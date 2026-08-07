// rt_audio.cpp — host audio sink for the guest's XAudio render-driver frames.
//
// EVIDENCE / MODEL (2026-07-13): the shell registers ONE XAudio render-driver client
// ([xaudio] register cb=82139888 ctx=00368B90, stubs.cpp XAudioRegisterRenderDriverClient)
// and the RT_AUDIOPUMP tick (shell/gen/rt.cpp vblank thread) drives that guest callback.
// On HW the callback runs every 256 samples (~5.33ms @48kHz = 187.5Hz); each invocation the
// guest-side XAudio mixer produces one fully-mixed frame and hands it to the kernel via
// XAudioSubmitRenderDriverFrame(r3=driver_handle, r4=samples_ptr). The frame layout — per the
// SDK oracle (rexglue-sdk sdl_audio_driver.h + conversion.h, Xenia lineage) — is
//   256 samples x 6 channels, float32 BIG-ENDIAN, CHANNEL-MAJOR (256 floats fl, 256 fr,
//   256 fc, 256 lfe, 256 bl, 256 br), 48000 Hz.
// Until now the submit stub discarded the frame (the port was silent by construction).
//
// This module is the sink. Two independent, default-OFF levers (repo discipline: byte-identical
// runtime behavior without them):
//   RT_AUDIODUMP=<path.wav>  append every submitted frame, downmixed to stereo float32 LE,
//                            to a WAV file (header re-patched ~1x/sec so a hard taskkill still
//                            leaves a readable file). Proves the guest MIXES real audio
//                            offline, before any live-backend debugging.
//   RT_AUDIO=1               live playback: lock-free-ish ring of downmixed stereo frames
//                            feeding a WASAPI shared-mode render thread (Windows only; no new
//                            deps beyond ole32). rt_audio_can_accept() gates the RT_AUDIOPUMP
//                            callback fire so the guest mixes at consumption rate (~187.5Hz),
//                            mirroring the SDK's queued_frames_=8 semaphore pacing.
//
// Downmix formula = the SDK's sequential_6_BE_to_interleaved_2_LE (conversion.h): center at
// half onto both sides, LFE discarded, x 1/2.5. NOTE the SDK's scalar path swaps br/bl
// (input[4]->right's back, input[5]->left's back) vs its own SSE path; we follow the SSE path
// (bl=input[4], br=input[5]) which matches the XAudio2 channel order fl,fr,fc,lfe,bl,br.
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdint>
#include <cmath>
#include <atomic>
#include <mutex>
#include <map>
#include <string>
#include <condition_variable>
#include <thread>
#include <chrono>
#include <vector>
#ifdef _WIN32
#include <windows.h>   // SetThreadPriority (worker elevation) + the legacy WASAPI section below
#endif

static inline float rt_audio_beflt(const uint8_t* p){
  uint32_t u = ((uint32_t)p[0]<<24)|((uint32_t)p[1]<<16)|((uint32_t)p[2]<<8)|(uint32_t)p[3];
  float f; std::memcpy(&f,&u,4); return f;
}

static const int kChanSamples = 256;             // samples per channel per frame
static const int kStereoFloats = kChanSamples*2; // downmixed floats per frame
static const int kRateHz = 48000;

// ---- ring buffer of downmixed stereo frames (submit thread -> WASAPI thread) ----
static const int kRingFrames = 64;               // ~340ms absolute cap; pacing keeps it ~8
static const int kTargetDepth = 8;               // mirror SDK queued_frames_=8 (~42ms)
static float g_ring[kRingFrames][kStereoFloats];
static std::atomic<uint32_t> g_ring_wr{0}, g_ring_rd{0};   // frame indices, wr>=rd
static std::atomic<long> g_submits{0}, g_dropped{0};

static bool rt_audio_live_on(){ static bool on = getenv("RT_AUDIO")!=nullptr; return on; }
static const char* rt_audio_dump_path(){ static const char* p = getenv("RT_AUDIODUMP"); return p; }

// Pacing gate for the RT_AUDIOPUMP tick (rt.cpp). Without RT_AUDIO the pump behavior is
// unchanged (always fire); with it, hold the callback while the ring is at depth — the guest
// then mixes exactly as fast as WASAPI drains, like the SDK semaphore model.
// ---- STARVATION INSTRUMENT (RT_AUDIOSTARVE, 2026-07-31) ----------------------------------------
// The 07-31 live gate failed on a defect no gate could see: ring depth drifting to zero. Depth was
// only ever printed at frames #1/#188/#1880, so a slow drain was invisible. This tracks, per second:
// min/max ring depth actually observed at consumption, and UNDERRUNS (device had room, ring empty).
// PASS for the starvation gate = underruns 0 and min depth >= a floor, sustained.
// RT_AUDIOSTALLTEST=<ms> is its POSITIVE CONTROL: it stalls the producer periodically so a run that
// *should* starve does, proving the counter is not simply stuck at zero.
static std::atomic<long> g_sv_under{0}, g_sv_total_under{0};
static std::atomic<uint32_t> g_sv_min{0xFFFFFFFFu}, g_sv_max{0};
static std::atomic<long> g_sv_samples{0};
static bool rt_starve_on(){ static bool on=getenv("RT_AUDIOSTARVE")!=nullptr; return on; }

static void rt_starve_note_depth(uint32_t depth){
  if(!rt_starve_on()) return;
  uint32_t m=g_sv_min.load(std::memory_order_relaxed);
  while(depth<m && !g_sv_min.compare_exchange_weak(m,depth)) {}
  uint32_t M=g_sv_max.load(std::memory_order_relaxed);
  while(depth>M && !g_sv_max.compare_exchange_weak(M,depth)) {}
  if(g_sv_samples.fetch_add(1)+1 >= 188){       // ~1 s of consumed frames
    long u=g_sv_under.exchange(0);
    std::fprintf(stderr,"[starve] 1s window: ring depth min=%u max=%u underruns=%ld (total=%ld)\n",
                 g_sv_min.exchange(0xFFFFFFFFu), g_sv_max.exchange(0), u,
                 g_sv_total_under.load());
    g_sv_samples.store(0);
  }
}
static void rt_starve_note_underrun(){
  if(!rt_starve_on()) return;
  g_sv_under.fetch_add(1); g_sv_total_under.fetch_add(1);
}
// Positive control: stall the PRODUCER on a schedule so starvation is provoked on demand.
static void rt_starve_stall_test(){
  static int ms = [](){ const char* e=getenv("RT_AUDIOSTALLTEST"); int v=e?atoi(e):0;
                        return (v>0&&v<=2000)?v:0; }();
  if(!ms) return;
  static long n=0;
  if((n++ % 375)==0 && n>375){                  // once per ~2 s of frames, after warm-up
    std::fprintf(stderr,"[starve] POSITIVE CONTROL: stalling the producer %d ms\n",ms);
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
  }
}

// Live-backend health, so the pacing gate can never wedge the guest's audio clock (2026-07-31):
// 0 = starting, 1 = running, 2 = failed/absent. Before this, a machine with no usable render
// endpoint would fail WASAPI init, never drain the ring, and rt_audio_can_accept() would return 0
// FOREVER — which stops the RT_AUDIOPUMP tick, and with it every guest clock derived from mix
// progress (XACT cue position, music-synced screen timers). Fine while live audio was an opt-in
// diagnostic; not acceptable now that the beta launcher asks for it on every machine.
static std::atomic<int> g_live_state{0};

extern "C" int rt_audio_can_accept(void){
  if(!rt_audio_live_on()) return 1;
  if(g_live_state.load(std::memory_order_relaxed)==2) return 1;   // no device -> never gate
  uint32_t wr=g_ring_wr.load(std::memory_order_relaxed), rd=g_ring_rd.load(std::memory_order_relaxed);
  if((wr-rd) < (uint32_t)kTargetDepth) return 1;
  // Ring at depth: normally the device drains it within ~5 ms. If it has not moved for a while the
  // backend is wedged (device removed, endpoint stolen, thread stuck) — keep the guest mixing and
  // let the submit path drop frames instead of freezing its clock.
  static std::atomic<uint32_t> lastrd{0};
  static std::atomic<long long> lastms{0};
  auto nowms = std::chrono::duration_cast<std::chrono::milliseconds>(
                 std::chrono::steady_clock::now().time_since_epoch()).count();
  if(lastrd.exchange(rd)!=rd || lastms.load()==0){ lastms.store(nowms); return 0; }
  if(nowms - lastms.load() > 250){
    static bool warned=false;
    if(!warned){ warned=true;
      std::fprintf(stderr,"[audio] live sink stalled >250ms — ungating the pump (frames will drop)\n"); }
    lastms.store(nowms);
    return 1;
  }
  return 0;
}

// ===================================================================================
// RT_AUDIOWORKER — pump-clock parity (2026-07-25 differential-trace verdict).
// The verdict: BGM is an ordinary in-memory looping wave in BOTH runtimes; the ONLY
// divergence is the CLOCK that drives the guest render-driver callback (g_xaudio_cb).
// rexglue (audio_system.cpp) runs it on a dedicated "Audio Worker" XHostThread paced by
// the audio DEVICE (SDLAudioDriver releases the client semaphore per consumed buffer,
// primed with queued_frames_); the port instead bursts it from the 59.94Hz VBLANK thread
// (RT_AUDIOPUMP accumulator, gated by the fake rt_audio_can_accept()), so the guest's
// looping-refill starves and BGM goes silent while one-shot SE survives.
//
// This is the host-transport half: a counting semaphore (produce-tokens) plus the
// CONSUMPTION clock. rt.cpp owns the worker THREAD (it needs the guest-callback
// machinery). Two pacing sources, matching rexglue's shape:
//   - live  (RT_AUDIO):     the WASAPI render thread releases ONE token per consumed
//                           256-sample frame  => device-paced, like the SDL client sem.
//   - dump  (RT_AUDIODUMP): a pacer thread releases tokens at 48000/256 = 187.5 Hz, an
//                           actual-audio-rate clock derived from 48kHz (NOT the vblank).
// Priming: the semaphore starts with queued_frames_ tokens (rexglue default 8, clamp
// 4-64) so the worker produces N frames AHEAD before any consumption, exactly mirroring
// audio_system.cpp RegisterClient's client_semaphore->Release(queued_frames_).
static std::condition_variable g_wk_cv;
static std::mutex              g_wk_m;
static int   g_wk_count    = 0;     // available produce-tokens (>=0, <= g_wk_max)
static int   g_wk_max      = 8;     // == queued_frames_ ; bounds the ahead-of-consume depth
static bool  g_wk_shutdown = false;
static bool  g_wk_inited   = false;

// 2026-07-31 (live-gate FAIL: "crunchy, then slowdown"): the worker is now the DEFAULT whenever a
// live sink is open. ROOT CAUSE of that FAIL — the legacy vblank pump and the audio device are two
// FREE-RUNNING clocks with a ONE-SIDED brake: rt_audio_can_accept() can only throttle production
// DOWN when the ring is full, and nothing ever lets the producer CATCH UP. The device consumes at
// exactly 48000/256 = 187.5 frames/s; the pump produces 187.5 * (achieved_vblank / assumed_vblank),
// so any sustained render-loop deficit is permanent and cumulative. Measured in the user's log:
// ring depth 7 (frame #1) -> 1 (#188) -> 0 (#1880) — a ~0.4% deficit draining the whole 8-frame
// buffer in ~10 s, after which every device period with an empty ring is a dropout. That is the
// crunch, and the sustained under-production is the "slowdown".
// The worker inverts the dependency: ONE produce per CONSUMED frame, primed N deep, so production
// is demand-driven and self-correcting by construction (rexglue AudioSystem parity). RT_AUDIOWORKER=0
// forces the legacy vblank pump back for A/B.
extern "C" int rt_audio_worker_on(void){
  static int on = [](){
    const char* e = getenv("RT_AUDIOWORKER");
    if(e) return (e[0]=='0' && !e[1]) ? 0 : 1;     // explicit wins, either way
    return rt_audio_live_on() ? 1 : 0;             // live sink -> demand-driven by default
  }();
  return on;
}
extern "C" int rt_audio_worker_prime_count(void){
  static int q=[](){ const char* e=getenv("RT_AUDIOWORKER_QFRAMES"); int v=e?atoi(e):8;
                     return (v>=4&&v<=64)?v:8; }();
  return q;
}
// Release n produce-tokens (consumer / priming / pacer side); clamped at g_wk_max so the
// worker can never run more than queued_frames_ ahead of real consumption.
static void rt_wk_release(int n){
  std::lock_guard<std::mutex> l(g_wk_m);
  g_wk_count += n; if(g_wk_count>g_wk_max) g_wk_count=g_wk_max;
  g_wk_cv.notify_one();
}
// Dump-only pacer: a 48kHz-derived 187.5 Hz token clock (absolute deadline, drift-free).
static void rt_audio_dump_pacer(){
  using namespace std::chrono;
  const auto period = nanoseconds((long long)(1e9*(double)kChanSamples/(double)kRateHz)); // 5.333ms
  auto next = steady_clock::now()+period;
  std::fprintf(stderr,"[audioworker] dump pacer up: %.1f Hz (48000/256, actual-audio-rate, NOT vblank)\n",
               (double)kRateHz/(double)kChanSamples);
  while(!g_wk_shutdown){
    std::this_thread::sleep_until(next);
    next += period;
    auto now=steady_clock::now(); if(next < now - 8*period) next = now+period; // forgive big stalls
    rt_wk_release(1);
  }
}
// Called once by the rt.cpp worker thread before its produce loop: prime the tokens and,
// in dump-only mode, start the 48kHz pacer (live mode is paced by the WASAPI consumer).
extern "C" void rt_audio_env_banner(void);   // defined below, after all the lever accessors
extern "C" void rt_audio_worker_init(void){
  rt_audio_env_banner();
#ifdef _WIN32
  // ★ 2026-08-02: this runs ON the worker thread (rt_audio_worker_main calls it first). The
  // worker produces one 5.33ms real-time frame per token — it IS the guest audio clock. At
  // default priority it loses scheduling races against the render worker and game threads
  // exactly when firing gets heavy (measured: ring depth 0 for consecutive seconds during
  // SFX-dense play with thousands of catch-up grants unable to refill). SDK parity: rexglue
  // runs its Audio Worker elevated (Xenia lineage), and SDL's own device thread is already
  // high-priority. RT_WORKERPRIO=0 reverts.
  { static bool off = [](){ const char* e=getenv("RT_WORKERPRIO"); return e && e[0]=='0' && !e[1]; }();
    if(!off && SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_TIME_CRITICAL))
      std::fprintf(stderr,"  [audioworker] priority TIME_CRITICAL (RT_WORKERPRIO=0 reverts)\n"); }
#endif
  {
    std::lock_guard<std::mutex> l(g_wk_m);
    if(g_wk_inited) return;
    g_wk_inited=true;
    g_wk_max   = rt_audio_worker_prime_count();
    g_wk_count = g_wk_max;                 // PRIME: N frames ahead (rexglue queued_frames_)
  }
  std::atexit([](){ g_wk_shutdown=true; g_wk_cv.notify_all(); });
  std::fprintf(stderr,"[audioworker] init: primed %d frames (queued_frames_ parity); pacing=%s\n",
               g_wk_max, rt_audio_live_on()?"WASAPI-consumption":"48kHz-clock");
  if(!rt_audio_live_on()) std::thread(rt_audio_dump_pacer).detach();
}
// Worker blocks here for one produce-token; returns 1 => produce a frame, 0 => shut down.
// BOUNDED (2026-07-31): a dead or suspended sink releases no tokens, and an unbounded wait would
// park the guest render-driver callback forever — freezing every guest clock derived from mix
// progress (XACT cue position, music-synced timers), the same hazard rt_audio_can_accept() got a
// watchdog for. On timeout we grant a token anyway: production limps at ~4 Hz instead of stopping.
extern "C" int rt_audio_worker_wait_token(void){
  // ★ 2026-08-01 CATCH-UP GRANT (user: "a couple of cut-outs"). The strict one-produce-per-
  // consumed-frame model CANNOT refill: rt_wk_release() caps tokens at g_wk_max and DISCARDS the
  // excess, so any stall longer than the cap permanently destroys that much ring depth. With the
  // engine wait now able to block up to RT_FRAMEPAIR_WAITMS (250ms ~ 47 frames), each such wait
  // burned far more than the 8-token cap. Measured over one gameplay session: depth 6 -> 5 -> 2
  // -> 0, monotonic, never recovering -> the ring runs dry and the device gets silence.
  // Fix, mirroring the UnleashedRecomp/SDL driver's "keep the queue topped up" model: while the
  // ring is below the low-water mark, produce immediately without waiting for (or consuming) a
  // token. Self-limiting - once depth reaches the mark we fall back to consumption pacing, so the
  // producer can never free-run ahead of the device. RT_AUDIOCATCHUP=0 restores the strict model.
  {
    static bool cu = [](){ const char* e=getenv("RT_AUDIOCATCHUP"); return !(e && e[0]=='0' && !e[1]); }();
    // ⚠ LIVE ONLY. The ring is written exclusively on the WASAPI path; in dump-only mode it stays
    // empty forever, so an ungated catch-up grants on every call and the guest callback free-runs
    // (measured on the bench: 673k submits in 150s vs the correct 187.5/s). Dump mode is paced by
    // rt_audio_dump_pacer's own 187.5Hz token clock and needs no catch-up.
    if(cu && g_live_state.load(std::memory_order_relaxed)==1){
      uint32_t depth = g_ring_wr.load(std::memory_order_acquire) - g_ring_rd.load(std::memory_order_acquire);
      int low = g_wk_max/2; if(low<2) low=2;
      if(depth < (uint32_t)low){
        static std::atomic<long> cn{0}; long n=cn.fetch_add(1)+1;
        if(n==1||(n%2000)==0)
          std::fprintf(stderr,"[audioworker] catch-up grant #%ld (ring depth %u < %d) — refilling\n",n,depth,low);
        return 1;
      }
    }
  }
  std::unique_lock<std::mutex> l(g_wk_m);
  if(!g_wk_cv.wait_for(l,std::chrono::milliseconds(250),
                       [&]{ return g_wk_count>0 || g_wk_shutdown; })){
    static std::atomic<long> to{0}; long n=to.fetch_add(1)+1;
    if(n==1||(n%400)==0)
      std::fprintf(stderr,"[audioworker] no consumption token for 250ms (#%ld) — granting one so the "
                          "guest audio clock keeps advancing\n",n);
    return 1;                                   // do NOT decrement: there was no token
  }
  if(g_wk_shutdown) return 0;
  g_wk_count--; return 1;
}

// ---- WAV dump (stereo float32 LE, 48kHz) ----
static FILE* g_wav = nullptr;
static long  g_wav_frames = 0;
static void rt_audio_wav_patch(){ // sizes at RIFF+4 and data+4; keep file valid mid-run
  if(!g_wav) return;
  long data_bytes = g_wav_frames*(long)kStereoFloats*4;
  uint32_t riff = 36u+(uint32_t)data_bytes, dsz = (uint32_t)data_bytes;
  std::fflush(g_wav);
  std::fseek(g_wav,4,SEEK_SET);  std::fwrite(&riff,4,1,g_wav);
  std::fseek(g_wav,40,SEEK_SET); std::fwrite(&dsz,4,1,g_wav);
  std::fseek(g_wav,0,SEEK_END);  std::fflush(g_wav);
}
static void rt_audio_wav_open(const char* path){
  g_wav = std::fopen(path,"wb");
  if(!g_wav){ std::fprintf(stderr,"[audio] RT_AUDIODUMP: cannot open %s\n",path); return; }
  // 44-byte header, format 3 = IEEE float, 2ch 48kHz 32-bit; sizes patched as we go
  uint8_t h[44]; std::memset(h,0,sizeof h);
  std::memcpy(h,"RIFF",4); std::memcpy(h+8,"WAVEfmt ",8);
  uint32_t fmtsz=16; std::memcpy(h+16,&fmtsz,4);
  uint16_t fmt=3, ch=2, bits=32; uint32_t rate=kRateHz;
  uint32_t brate=rate*ch*(bits/8); uint16_t align=ch*(bits/8);
  std::memcpy(h+20,&fmt,2); std::memcpy(h+22,&ch,2); std::memcpy(h+24,&rate,4);
  std::memcpy(h+28,&brate,4); std::memcpy(h+32,&align,2); std::memcpy(h+34,&bits,2);
  std::memcpy(h+36,"data",4);
  std::fwrite(h,1,44,g_wav);
  std::atexit(rt_audio_wav_patch);   // clean exits get exact sizes; hard kills lose <=1s
  std::fprintf(stderr,"[audio] RT_AUDIODUMP -> %s (stereo f32 48kHz)\n",path);
}

// ---- SDL3 backend (DEFAULT SINK, 2026-08-02) ----------------------------------------------------
// USER DIRECTIVE 08-02: retire the hand-rolled WASAPI machinery. This is the SAME sink the
// reference SDK build uses (rexglue-sdk src/audio/sdl/sdl_audio_driver.cpp, Xenia lineage, also
// UnleashedRecomp's) — adopting it makes our host sink the same code path as the reference, so
// A/Bs against it compare guest output, not sink implementations. What it deletes from our side:
// the WASAPI render thread, the IMMNotificationClient default-device follower, and the device-lost
// re-open loop — SDL3's audio thread owns device follow/migration internally.
// Differences vs the SDK driver, deliberate:
//   - the SDK queues raw BE 6ch guest frames and folds in the callback; we fold at submit (same
//     arithmetic, conversion.h formula, proven byte-identical) and queue folded stereo. The ring
//     and its depth semantics are unchanged so every instrument ([starve], depth logs, catch-up
//     grant, can_accept gate) keeps meaning what it meant.
//   - the SDK releases its client semaphore per consumed frame; we release one worker
//     produce-token per consumed frame — the same pacing contract, same place.
// Revert arm: RT_SINKWASAPI=1 selects the legacy WASAPI path (kept compiled, byte-identical).
#include <SDL3/SDL.h>
static std::atomic<long> g_rendered{0};   // frames actually handed to the device sink
static bool rt_sink_wasapi(){
  static bool on = [](){ const char* e=getenv("RT_SINKWASAPI"); return e && e[0]=='1' && !e[1]; }();
  return on;
}

static void SDLCALL rt_audio_sdl_cb(void*, SDL_AudioStream* stream, int additional_amount, int){
  // Mirror of SDLAudioDriver::SDLCallback: serve whole 256-sample frames; explicit silence when
  // the ring is dry (the device timeline stays continuous and the underrun is COUNTED, not
  // implied). Tokens/depth notes fire only on real frames, exactly like the SDK's semaphore.
  const int len = (int)(kStereoFloats*sizeof(float));
  while(additional_amount > 0){
    uint32_t rd = g_ring_rd.load(std::memory_order_acquire);
    if(rd == g_ring_wr.load(std::memory_order_acquire)){
      static const float silence[kStereoFloats] = {};
      rt_starve_note_underrun();
      if(!SDL_PutAudioStreamData(stream, silence, len)) break;
      additional_amount -= len;
      continue;
    }
    if(!SDL_PutAudioStreamData(stream, g_ring[rd % kRingFrames], len)) break;
    g_ring_rd.store(rd+1, std::memory_order_release);
    rt_starve_note_depth(g_ring_wr.load(std::memory_order_relaxed)-(rd+1));
    // one consumed device frame -> one produce-token (SDK client-sem release-per-buffer parity)
    if(rt_audio_worker_on()) rt_wk_release(1);
    additional_amount -= len;
    long r = g_rendered.fetch_add(1)+1;
    if(r==1||r==188||r==1880)
      std::fprintf(stderr,"[audio] SDL rendered frame #%ld (ring depth %u)\n",
                   r, g_ring_wr.load()-g_ring_rd.load());
  }
}

static void rt_audio_sdl_start(){
  // Same three environment hints the SDK driver sets (timer-resolution one prevents FPS drops).
  SDL_SetHintWithPriority(SDL_HINT_TIMER_RESOLUTION, "0", SDL_HINT_OVERRIDE);
  SDL_SetHint(SDL_HINT_AUDIO_CATEGORY, "playback");
  SDL_SetAppMetadataProperty(SDL_PROP_APP_METADATA_NAME_STRING, "futariRealcomp");
  if(!SDL_InitSubSystem(SDL_INIT_AUDIO)){
    std::fprintf(stderr,"[audio] SDL3 init FAILED: %s (no live audio; pump ungated)\n", SDL_GetError());
    g_live_state.store(2); return;
  }
  SDL_AudioSpec spec{};
  spec.format   = SDL_AUDIO_F32LE;
  spec.channels = 2;
  spec.freq     = kRateHz;
  SDL_AudioStream* s = SDL_OpenAudioDeviceStream(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &spec,
                                                 rt_audio_sdl_cb, nullptr);
  if(!s){
    std::fprintf(stderr,"[audio] SDL_OpenAudioDeviceStream FAILED: %s (no live audio; pump ungated)\n",
                 SDL_GetError());
    g_live_state.store(2); return;
  }
  if(!SDL_ResumeAudioDevice(SDL_GetAudioStreamDevice(s))){
    std::fprintf(stderr,"[audio] SDL_ResumeAudioDevice FAILED: %s (no live audio; pump ungated)\n",
                 SDL_GetError());
    g_live_state.store(2); return;
  }
  g_live_state.store(1);
  std::fprintf(stderr,"[audio] SDL3 sink up: 48kHz stereo f32, default device "
                      "(device follow is SDL-managed; RT_SINKWASAPI=1 reverts to legacy WASAPI)\n");
}

// ---- WASAPI backend (LEGACY, revert arm RT_SINKWASAPI=1) ----
#ifdef _WIN32
#include <windows.h>
#include <mmdeviceapi.h>
#include <audioclient.h>
// ★ 2026-08-01 round-8 ("sound cut out toward the end", telemetry CLEAN to the last line): a
// Windows DEFAULT-DEVICE CHANGE does not invalidate the old endpoint — the stream keeps
// rendering into the orphaned device and the user hears silence while every meter reads
// healthy. Follow the default: an IMMNotificationClient flags the change and the render loop
// breaks into the existing device-lost recovery (which re-opens the CURRENT default).
static std::atomic<bool> g_dev_changed{false};
struct RtMMNotify final : IMMNotificationClient {
  ULONG STDMETHODCALLTYPE AddRef()  override { return 2; }
  ULONG STDMETHODCALLTYPE Release() override { return 1; }
  HRESULT STDMETHODCALLTYPE QueryInterface(REFIID iid, void** out) override {
    if(iid==__uuidof(IUnknown) || iid==__uuidof(IMMNotificationClient)){ *out=this; return S_OK; }
    *out=nullptr; return E_NOINTERFACE;
  }
  HRESULT STDMETHODCALLTYPE OnDefaultDeviceChanged(EDataFlow flow, ERole role, LPCWSTR) override {
    if(flow==eRender && role==eConsole){
      g_dev_changed.store(true);
      std::fprintf(stderr,"[audio] default render device CHANGED — will follow\n");
    }
    return S_OK;
  }
  HRESULT STDMETHODCALLTYPE OnDeviceStateChanged(LPCWSTR, DWORD) override { return S_OK; }
  HRESULT STDMETHODCALLTYPE OnDeviceAdded(LPCWSTR) override { return S_OK; }
  HRESULT STDMETHODCALLTYPE OnDeviceRemoved(LPCWSTR) override { return S_OK; }
  HRESULT STDMETHODCALLTYPE OnPropertyValueChanged(LPCWSTR, const PROPERTYKEY) override { return S_OK; }
};
static RtMMNotify g_mm_notify;
static void rt_audio_wasapi_thread(){
  // Shared-mode with AUTOCONVERTPCM: we ask for OUR format (48kHz stereo f32) and let the
  // audio engine convert/resample to whatever the device mix format is — no negotiation code.
  // ★ 2026-08-01 DEVICE-LOST RECOVERY (user round-2: "no sound at all" — GetCurrentPadding
  // failed ~10s in, the thread exited, the game played on in total silence). Device
  // invalidation (default-device switch, driver reset, sleep/wake) is a session event, not a
  // fatal one: tear down and re-open the CURRENT default endpoint, forever, with loud logs.
  if(FAILED(CoInitializeEx(nullptr,COINIT_MULTITHREADED))){
    std::fprintf(stderr,"[audio] WASAPI: CoInitializeEx failed\n"); return; }
  long session=0;
  for(;;){
    IMMDeviceEnumerator* en=nullptr; IMMDevice* dev=nullptr; IAudioClient* ac=nullptr;
    IAudioRenderClient* rc=nullptr;
    HRESULT hr = CoCreateInstance(__uuidof(MMDeviceEnumerator),nullptr,CLSCTX_ALL,
                                  __uuidof(IMMDeviceEnumerator),(void**)&en);
    if(SUCCEEDED(hr)){
      // Register the default-device watcher ONCE, on its own enumerator that outlives every
      // session (the per-session `en` below is Released on device loss, which would silently
      // unregister the callback with it).
      static bool registered = [](){
        IMMDeviceEnumerator* ne=nullptr;
        if(FAILED(CoCreateInstance(__uuidof(MMDeviceEnumerator),nullptr,CLSCTX_ALL,
                                   __uuidof(IMMDeviceEnumerator),(void**)&ne))) return false;
        return SUCCEEDED(ne->RegisterEndpointNotificationCallback(&g_mm_notify)); // ne kept alive
      }();
      (void)registered;
      g_dev_changed.store(false);
      hr = en->GetDefaultAudioEndpoint(eRender,eConsole,&dev);
    }
    if(SUCCEEDED(hr)) hr = dev->Activate(__uuidof(IAudioClient),CLSCTX_ALL,nullptr,(void**)&ac);
    WAVEFORMATEX wf{}; wf.wFormatTag=WAVE_FORMAT_IEEE_FLOAT; wf.nChannels=2;
    wf.nSamplesPerSec=kRateHz; wf.wBitsPerSample=32;
    wf.nBlockAlign=(WORD)(wf.nChannels*wf.wBitsPerSample/8);
    wf.nAvgBytesPerSec=wf.nSamplesPerSec*wf.nBlockAlign;
    if(SUCCEEDED(hr)) hr = ac->Initialize(AUDCLNT_SHAREMODE_SHARED,
        AUDCLNT_STREAMFLAGS_AUTOCONVERTPCM|AUDCLNT_STREAMFLAGS_SRC_DEFAULT_QUALITY,
        400000 /*40ms hns*/,0,&wf,nullptr);
    UINT32 bufsz=0;
    if(SUCCEEDED(hr)) hr = ac->GetBufferSize(&bufsz);
    if(SUCCEEDED(hr)) hr = ac->GetService(__uuidof(IAudioRenderClient),(void**)&rc);
    if(SUCCEEDED(hr)) hr = ac->Start();
    if(FAILED(hr)){
      if(rc)rc->Release(); if(ac)ac->Release(); if(dev)dev->Release(); if(en)en->Release();
      g_live_state.store(2);    // no device: rt_audio_can_accept() must stop gating the pump
      if(session==0){           // boot-time no-device: the old terminal behaviour
        std::fprintf(stderr,"[audio] WASAPI init FAILED hr=0x%08lX (no live audio; pump ungated)\n",(long)hr);
        CoUninitialize(); return;
      }
      static std::atomic<long> w{0};
      if(w.fetch_add(1)<8) std::fprintf(stderr,"[audio] WASAPI re-init failed hr=0x%08lX — retrying in 1s\n",(long)hr);
      Sleep(1000); continue;
    }
    g_live_state.store(1);
    std::fprintf(stderr,"[audio] WASAPI up: shared 48kHz stereo f32, buffer=%u frames (session %ld)\n",
                 bufsz,session);
    ++session;
    for(;;){
      if(g_dev_changed.load()) break;      // default endpoint moved: re-open on the new one
      UINT32 pad=0;
      if(FAILED(ac->GetCurrentPadding(&pad))) break;
      UINT32 room = bufsz - pad;
      // move whole 256-sample frames from the ring into the device buffer
      while(room >= (UINT32)kChanSamples &&
            g_ring_rd.load(std::memory_order_acquire) != g_ring_wr.load(std::memory_order_acquire)){
        BYTE* out=nullptr;
        if(FAILED(rc->GetBuffer(kChanSamples,&out)) || !out) { room=0; break; }
        uint32_t rd = g_ring_rd.load(std::memory_order_relaxed);
        std::memcpy(out, g_ring[rd % kRingFrames], kStereoFloats*sizeof(float));
        rc->ReleaseBuffer(kChanSamples,0);
        g_ring_rd.store(rd+1, std::memory_order_release);
        rt_starve_note_depth(g_ring_wr.load(std::memory_order_relaxed)-(rd+1));
        // RT_AUDIOWORKER live pacing: one consumed device frame -> one produce-token, so the
        // worker refills at the device's real consumption rate (the SDLAudioDriver client-sem
        // release-per-consumed-buffer parity). No-op unless RT_AUDIOWORKER is set.
        if(rt_audio_worker_on()) rt_wk_release(1);
        room -= kChanSamples;
        long r = g_rendered.fetch_add(1)+1;
        if(r==1||r==188||r==1880) std::fprintf(stderr,"[audio] WASAPI rendered frame #%ld (ring depth %u)\n",
          r, g_ring_wr.load()-g_ring_rd.load());
      }
      // Ring empty while the device still had room = a genuine UNDERRUN: the engine plays whatever
      // is left in its buffer and the listener hears a crunch. This is the signal the 07-31 live
      // gate needed and did not have.
      if(room >= (UINT32)kChanSamples &&
         g_ring_rd.load(std::memory_order_acquire)==g_ring_wr.load(std::memory_order_acquire))
        rt_starve_note_underrun();
      Sleep(2);
    }
    g_live_state.store(2);      // ungate the pump while the device is gone
    std::fprintf(stderr,"[audio] WASAPI DEVICE LOST (session %ld) — reopening default endpoint\n",session-1);
    ac->Stop(); rc->Release(); ac->Release(); dev->Release(); en->Release();
    Sleep(250);                 // let the endpoint change settle before regrabbing
  }
}
#endif

// ---- RT_AUDIOBRIDGE (DIAGNOSTIC PROOF, default-OFF; NOT the ship path) --------------------------
// The register-true XACT3->XAudio2 source-voice path is broken (no IXAudio2SourceVoice ever reaches
// the ticked submix -> the guest mixes digital silence). This lever BYPASSES that path: at the cue-
// commit crux (merged_xex.cpp sub_88090588) we already know cueId->(bankType,waveIdx). For a
// committed PCM BGM cue (bankType 0 == BGM.xwb, PCM 48k stereo in a driven field) we slice the
// resident .xwb PlayRegion straight from disk host-side and mix it into the stereo frame that
// rt_audio_submit emits. This proves rt_audio->WASAPI/dump->speaker works with REAL BGM (the prior
// fill-tests never confirmed the output path end-to-end) and yields the first audible PCM sound.
// Byte-swap is applied EXACTLY ONCE (on-disk BE PCM16 -> host int16); a double-swap gives noise.
// Needs a sink to be audible/measurable: pair with RT_AUDIODUMP=<wav> or RT_AUDIO=1.
static bool rt_bridge_on(){ static bool on = getenv("RT_AUDIOBRIDGE")!=nullptr; return on; }
extern "C" int rt_audio_bridge_enabled(void){ return rt_bridge_on()?1:0; }
extern "C" void rt_audio_bridge_play_cue(const char* sbName, int cueIndex);   // defined below
// RT_CUEBRIDGE=0 reverts to the pre-07-31 dispatch site (the game-side crux only, no shell banks).
// Default ON: the shell-side SoundBank::Prepare funnel is a strict superset — it sees the same game
// cues PLUS SYS_SE / SYS_BGM. Consumed by merged_shell.cpp (dispatch) and merged_game.cpp (suppress
// the crux dispatch so a game cue is not played twice).
extern "C" int rt_audio_cuebridge_enabled(void){
  static int on = [](){ const char* e=getenv("RT_CUEBRIDGE"); return (e && e[0]=='0' && !e[1])?0:1; }();
  return on;
}

// ---- RT_AUDIOXWMA: xWMA (WMAudio2) COMPRESSED banks through the bridge --------------------------
// Until this leg the bridge served PCM only ("bankType!=0 -> return"), so the 67 xWMA SE + 134 VOICE
// entries — including the user's repro (the menu confirm SE) — had no path to a speaker at all: the
// port has no software decoder and the hardware XMA context stubs are never called. rt_xwma.cpp now
// decodes those entries host-side (Windows in-box WMAudio2 decoder, packets straight out of the
// .xwb PlayRegion, format from the WAVEBANKMINIWAVEFORMAT index pair). Decoded PCM is cached per
// (bank,waveIdx) and played as an overlapping ONE-SHOT voice, linearly resampled from the bank's
// native rate (44100 for SE/VOICE) to the 48kHz frame ABI — host-side only, so it cannot collide
// with the guest's own per-voice resamplers.
// Lever: RT_AUDIOXWMA=0 reverts to the previous PCM-only bridge behaviour exactly.
extern "C" int rt_xwma_decode_xwb_entry(const char* path,int waveIdx,int16_t** outPcm,size_t* outFrames,int* outChans,int* outRate);
extern "C" int rt_xwb_entry_count(const char* path);
extern "C" int rt_xwb_entry_tag(const char* path,int waveIdx);
extern "C" int rt_xwb_pcm_info(const char* path,int waveIdx,unsigned* absOff,unsigned* len,
                               int* chans,int* rate,int* tag,unsigned* loopStart,unsigned* loopTotal);
// .xsb SoundBank map (rt_xwma.cpp, 2026-07-31): cue index -> wave index. See the big comment
// there — cue index != wave index for BGM (11/13 cues) and SYS_SE (6/7), so every dispatch that
// arrives with a CUE index must come through here.
// NOTE: this declaration is a hand-kept mirror of the one in rt_xwma.cpp — keep the two in step
// (adding a field to one and not the other is a silent ABI mismatch, not a compile error, unless
// the new field is actually referenced here).
typedef struct RtXsbCue { int waveIndex; int waveBankIndex; int fromXsb; const char* name; int category; int loopInfinite;
                          float volume; /* ★ 08-01 authored per-sound linear gain (FAudio curve) */ } RtXsbCue;

// ---- XACT CATEGORY VOLUME (2026-07-31) ---------------------------------------------------------
// MEASURED, not assumed. The shell calls IXACT3Engine::SetVolume(category, volume) (engine vtable
// slot 18 = 0x820E7628) exactly five times at audio setup and the calls DO take effect (the guest
// gates them on the category record's byte+9 bit 0x2, probed live: flags=0x02, APPLIED=1 for all):
//     cat 3 BGM     -> 0.000      cat 4 SE     -> 1.000
//     cat 6 SYS_BGM -> 0.000      cat 5 VOICE  -> 1.000
//                                 cat 7 SYS_SE -> 1.000
// The index space is sound.xgs's single category table — 0 Global, 1 Default, 2 Music, 3 BGM,
// 4 SE, 5 VOICE, 6 SYS_BGM, 7 SYS_SE — which matches the category field of all five .xsb banks
// 5/5. So the shell mutes MUSIC and keeps every SFX category: exactly the user's ground truth
// ("attract has no music, only SFX"). Our bridge ignored category volume entirely, which is the
// whole reason the menu stream was audible at all — and why it bled into attract.
//
// SCOPE (RT_CATVOL), deliberately conservative:
//   "shell" (default) honour categories 6/7 only — the shell's own SYS_* banks. This silences the
//           menu/attract music (both reported defects) and CANNOT touch the game's BGM, whose
//           audio the user has already accepted as good.
//   "all"   honour every category literally, including BGM(3). HW-literal, but it would also
//           silence in-game stage music, and nothing observed ever restores cat 3 to 1.0 — that
//           restore path is the open question banked for the next leg.
//   "0"     off entirely (pre-07-31 behaviour).
static float g_cat_vol[16];
static bool  g_cat_init=false;
static int rt_catvol_mode(){        // 0=off 1=shell-only 2=all
  // DEFAULT = "all" as of the referee correction: with the shell's own SetCategoryVolume(name,..)
  // now feeding the table, music categories carry the guest's real INTENT (1.0 in the menus), not
  // the stale engine copy — so honouring every category is both correct and safe for gameplay BGM.
  static int m = [](){ const char* e=getenv("RT_CATVOL");
                       if(!e) return 2;
                       if(e[0]=='0'&&!e[1]) return 0;
                       if(!strcmp(e,"all")) return 2;
                       return 1; }();
  return m;
}
// By NAME — the shell's own SetCategoryVolume(name, vol) (FUN_821caa60). This is the guest's real
// INTENT for music: for "BGM"/"SYS_BGM" the shell caches the value and deliberately does NOT push
// it to the engine, so the engine copy is stale and only this path tells the truth. Names come
// straight from sound.xgs's category table, so the mapping is exact.
static int rt_cat_index_by_name(const char* n){
  if(!n) return -1;
  if(!strcmp(n,"Global"))  return 0;   if(!strcmp(n,"Default")) return 1;
  if(!strcmp(n,"Music"))   return 2;   if(!strcmp(n,"BGM"))     return 3;
  if(!strcmp(n,"SE"))      return 4;   if(!strcmp(n,"VOICE"))   return 5;
  if(!strcmp(n,"SYS_BGM")) return 6;   if(!strcmp(n,"SYS_SE"))  return 7;
  return -1;
}
extern "C" void rt_audio_set_category_volume_named(const char* name, double vol){
  int c = rt_cat_index_by_name(name);
  if(c<0) return;
  if(!g_cat_init){ for(int i=0;i<16;i++) g_cat_vol[i]=1.0f; g_cat_init=true; }
  g_cat_vol[c] = (float)vol;
  // ★ 2026-08-01: log ON CHANGE, not "first 24 calls". The flat cap made the BGM SLIDER INVISIBLE:
  // BGM/SYS_BGM are cached by the shell and never pushed to the engine, so this named path is the
  // ONLY record of them, and the shell re-asserts the same values often enough to burn all 24
  // lines during boot. A 20:12 session where the user demonstrably moved the BGM slider showed
  // just 1.000/0.990/0.980 and then nothing — the movement happened, the log had gone quiet. Same
  // class of blind spot as the missing build id ([env] banner): a measurement that is silent when
  // it matters invites a wrong attribution. Per-category last-value so a slider drag prints its
  // whole trajectory while steady-state re-assertions stay quiet.
  static float lastLogged[16] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
  if(lastLogged[c] != (float)vol){
    lastLogged[c] = (float)vol;
    std::fprintf(stderr,"[catvol] (shell intent) %s (cat %d) -> %.3f\n",name,c,vol);
  }
}
extern "C" void rt_audio_set_category_volume(int cat, double vol){
  if(cat<0 || cat>=16) return;
  if(!g_cat_init){ for(int i=0;i<16;i++) g_cat_vol[i]=1.0f; g_cat_init=true; }
  g_cat_vol[cat] = (float)vol;
  std::fprintf(stderr,"[catvol] category %d -> %.3f%s\n", cat, vol,
               (rt_catvol_mode()==1 && cat!=6 && cat!=7) ? "  (recorded; outside RT_CATVOL=shell scope)" : "");
}
// ★ THE HANDOVER FADE (2026-07-31, user-reported "the cutoff is weird and abrupt").
// Referee measurement (Xenia, per-process meter @20 Hz): on hardware the menu music does NOT
// hard-stop at the mode handover — it FADES, -6.7 dBFS at t=26.14 sliding smoothly to -73 dBFS by
// t=28.06, then digital zero. Our build played at full level right up to the guest's cue teardown
// and cut dead there.
// The guest drives that fade on category 0 ("Global"), the XACT ROOT category that scales all
// others — measured, not assumed: sub_821CA078(idx=0, vol) is called 43x from the fade tick
// FUN_821cac08 (lr=0x821CAD14) with vol sliding 1.0000 -> 0.0001, and the cue teardown we were
// reacting to happens only AFTER the ramp completes. We tracked per-cue categories only and never
// read category 0 at all, so the entire ramp was invisible to the bridge.
// Both rt_cat_gain call sites are inside the per-buffer mix, so following it here ramps a
// STREAM ALREADY PLAYING rather than only affecting newly started cues.
// Lever: RT_FADEGAIN=0 ignores the master again (pre-07-31 behaviour).
// ★ 2026-08-01 SCOPE CORRECTION (user ground truth: "no background music at all, SFX lower, after
// entering arcade"). Following Global for EVERYTHING left the whole mix at ~0.002 through gameplay:
// the guest's handover fade (multiplicative decay, sub_821CAC08 tick) reaches perceptual zero in
// ~2 s but stays INTERNALLY armed for ~80+ s more (frames-remaining large), applying ~0.000x every
// tick until fade-END sub_821CA108 finally fires (clears the record + posts a notification msg;
// the restore lives in the msg RECEIVER — undecomp'd, THE open item). The referee measurement that
// validated the fade was of MENU music — shell-owned audio — and hardware gameplay audio plays at
// full level. So the master-follow is scoped to the shell categories (SYS_BGM 6 / SYS_SE 7).
//   RT_FADEGAIN: 1 (default) follow Global for shell categories only
//                2 old behaviour — follow Global for everything (the A/B arm)
//                0 ignore the master entirely (pre-07-31)
static int rt_fadegain_mode(){
  static int m = [](){ const char* e=getenv("RT_FADEGAIN"); return e?atoi(e):1; }();
  return m;
}
// The guest's live value for the root category.
static float rt_master_gain(){
  if(!rt_fadegain_mode() || !g_cat_init) return 1.0f;
  return g_cat_vol[0];
}
// The gain a cue of this category should play at, under the current scope.
static float rt_cat_gain(int cat){
  int m = rt_catvol_mode();
  const bool shellCat = (cat==6 || cat==7);
  const float master = (shellCat || rt_fadegain_mode()==2) ? rt_master_gain() : 1.0f;
  if(m==0 || cat<0 || cat>=16 || !g_cat_init) return master;
  if(m==1 && !shellCat) return master;           // shell-only scope
  return g_cat_vol[cat] * master;
}
// Written by the guest's fade tick via sub_821CA078. Kept separate from the engine-level setter so
// a 43-tick ramp does not spam a line per tick: logs the head of a ramp and its landing only.
extern "C" void rt_audio_set_category_fade(int cat, double vol){
  if(cat<0 || cat>=16) return;
  if(!g_cat_init){ for(int i=0;i<16;i++) g_cat_vol[i]=1.0f; g_cat_init=true; }
  float prev = g_cat_vol[cat];
  g_cat_vol[cat] = (float)vol;
  bool edge = (prev>0.002f) != (vol>0.002);      // ramp start / ramp landing
  static std::atomic<long> n{0};
  if(edge || n.fetch_add(1) < 6)
    std::fprintf(stderr,"[catfade] category %d %.4f -> %.4f%s\n", cat, (double)prev, vol,
                 (cat==0) ? "   (Global = master)" : "");
}
extern "C" int         rt_xsb_cue(const char* bankName,int cueIndex,RtXsbCue* out);
extern "C" const char* rt_xsb_wavebank(const char* bankName,int waveBankIndex);

static bool rt_xwma_on(){
  static bool on = [](){ const char* e=getenv("RT_AUDIOXWMA"); return !e || !(e[0]=='0'&&e[1]==0); }();
  return on;
}
// ★ RT_SEPCM (2026-08-01): how PCM entries in NON-music banks play. The cue dispatch used to route
// by wave FORMAT (tag 0 -> the singleton music streamer), so the three PCM waves in SE.xwb
// (8/18/24 = the L-named looping SEs, the shot-loop class) HIJACKED the music stream on every
// dispatch and killed it when their instance ended — 159 "SE cueN -> MUSIC STREAM STOPPED" lines
// in one user session (playtest_rdc_0801_0802.log) = the "music stops mid-gameplay, worse the
// more I shoot" defect. On hardware these are ordinary in-memory voices, not streams.
//   1 (default) -> PCM entries in SE-class banks play as decoded one-shots in the voice pool
//   0           -> pre-08-01 behaviour (tag routing; the hijack) — revert arm
//   2           -> suppress them entirely (if the guest's own voice path turns out to deliver
//                  them and mode 1 doubles; user's ears decide between 1 and 2)
static int rt_sepcm_mode(){
  static int m = [](){ const char* e=getenv("RT_SEPCM"); return e?atoi(e):1; }();
  return m;
}
// LEGACY bankType -> .xsb basename map (the game's 0x88 cue table stores one of THREE registered
// resource kinds; 0=BGM proven by the 07-18 bridge leg, 1=SE / 2=VOICE corroborated 07-29 by
// out-of-range waveIdx on bt2). Kept because the game-side crux dispatch still speaks bankType;
// the shell-side dispatch speaks bank NAMES and covers SYS_SE / SYS_BGM too.
static const char* rt_xw_bank_name(int bankType){
  switch(bankType){ case 0: return "BGM"; case 1: return "SE"; case 2: return "VOICE"; }
  return nullptr;
}
static void rt_xw_wb_path(const char* wbName, char* out, size_t n){
  if(!wbName || !*wbName){ out[0]=0; return; }
  const char* root = getenv("RT_GAME_ROOT");
  if(root) std::snprintf(out,n,"%s/media/Sound/%s.xwb",root,wbName);
  else     std::snprintf(out,n,"assets/media/Sound/%s.xwb",wbName);
}

// The SDK's 5.1->stereo fold gain — every guest-mixed sample's final scale before the speaker.
// Bridge content injects post-fold and must carry the same factor (see the kXaFold uses below).
static const float kXaFold = 1.0f/2.5f;

// ★ 2026-08-01 MUSIC/SFX BALANCE CALIBRATION (user: "sfx much louder than they should be vs the
// music"). Measured against the banked HARDWARE envelope (Xenia meter.csv, 60ms p90 peak — the
// only reference that carries menu-music and demo-SFX as SEPARATE segments):
//     hardware  menu music 0.472 : demo SFX 0.266  => SFX/music 0.56  (-5.0 dB)
//     ours      menu music 0.218 : SFX      0.638  => SFX/music 2.93  (+9.3 dB)
// i.e. a 14.3 dB error. It is structural, not a bug in either path: music comes from the host
// bridge (already stereo, so the 5.1 fold's 1/2.5 headroom divisor over-attenuates it) while SFX
// come through the guest's 5.1 field where multi-channel placement sums BEFORE that divisor.
// Guest SFX x0.42 (-7.6dB) -> p90 peak 0.256 on a real gameplay session, vs hardware 0.266.
// USER-ACCEPTED ("much better") — leave it alone.
// ⚠ MUSIC was first set to x2.16 to put our menu music on hardware's ABSOLUTE 0.472, and the user
// called it too loud. Two errors, both in the same direction: (1) absolute levels are NOT
// comparable across systems (Xenia's own master volume is unknown) — this file's own comment said
// so and the number was used anyway; (2) the ratio target itself compared OUR GAMEPLAY SFX with
// HARDWARE'S ATTRACT-DEMO SFX, and demo audio is quieter than real play, so the true gameplay
// ratio is higher than 0.56 and music should sit lower than that implied. Hardware's ratio is
// therefore a BOUND, not a target. Backed off x2.16 -> x1.45 -> x1.15 -> x1.0 on the user's ear.
// ★ x1.0 is now the default. As of the "remove all gains" directive the SFX trim is x1.0 too, so
// BOTH constants are identity and there is NO calibration anywhere in the chain — the mix is the
// guest's own, folded 5.1->stereo by the SDK constant and nothing else. Reference points if
// re-tuned: x1.15 / x1.45 (louder music), x2.16 = the too-loud hardware-absolute setting that
// started this sequence.
// ⚠ NOT A DEFECT, do not "fix": the audible level STEP entering a stage is AUTHORED — menu cue
// mushifuta_Menu02 carries volume 0.71 and the stage cues 1.00 (+3.0 dB authored, +1.7 dB as
// mastered). Categories are symmetric (cat 3 and cat 6 both land at 1.000) and the guest issues
// no fade-in after the handover, so nothing host-side is stepping on a ramp; hardware steps too.
// ⚠ These WERE calibration constants for a path that is not register-true (the guest's own music
// streaming stalls, which is why the bridge exists at all). Both are now 1.0, so the guest-path
// migration no longer has to unwind a trim — that debt is already paid.
// ★★ 2026-08-02 READ THIS BEFORE TOUCHING EITHER LEVER — THEIR NAMES ARE NOW LIES.
//  * RT_SFXGAIN is NOT an SFX gain. rt_sfx_cal() multiplies the ENTIRE guest 5.1->stereo fold, and
//    since the guest started rendering its own music (08890f6 / a8cdb79) that frame carries MUSIC
//    TOO. Setting RT_SFXGAIN=0.42 today ducks the user's confirmed-good music by 7.6 dB and moves
//    the music-vs-SFX balance by exactly ZERO. It is a MASTER TRIM. Treat it as one.
//  * RT_MUSICGAIN is INERT. rt_music_cal()'s only call site is the retired host music streamer,
//    which every bank now returns before reaching. It is kept solely so the [env] banner can keep
//    printing a stable field; changing it does nothing at all.
//  * There is therefore NO host lever that changes SFX relative to music, and adding one would be
//    the fudge factor this campaign exists to delete. The register-true control is the guest's own
//    SE category — the in-game OPTIONS > SOUND > SE slider (sub_82189158 -> sub_821CAA60, group 1
//    = {SE, SYS_SE}), measured working: SE 100->19 took guest rms 0.055 -> 0.0097.
// ⚠ AND THE BALANCE IS NOT BROKEN — measured 08-02 with the shot-held vs no-fire A/B
// (_tmpscripts/ab_instage_nofire.sh): the stage MUSIC BED alone peaks p50 0.3846, against a
// prediction of 0.3371 computed from the authored bytes with no free parameters
// (wave 1.0000 x sound 1.0008 x category 0.8421 x fold 0.4). SFX peak only 2.10x over that bed.
// The earlier "SFX are 4x the music" reading was a BASELINE ERROR: it compared gameplay against
// MENU music, which is authored 4.56 dB below stage music (SYS_BGM sound byte 151/cat 151 vs
// BGM 180/165). Do not re-open this as a level defect.
// Levers: RT_MUSICGAIN (inert) / RT_SFXGAIN (master trim; =1 is identity).
static float rt_music_cal(){
  static float v = [](){ const char* e=getenv("RT_MUSICGAIN"); float f=e?(float)atof(e):1.0f;
                         return (f>0.0f && f<=16.0f)?f:1.0f; }();
  return v;
}
// ★ 2026-08-01, USER DIRECTIVE "remove all gains too": the SFX trim is now 1.0 as well, so the
// ENTIRE calibration chain is gone and both halves of the mix run at the raw SDK fold. Tested by
// ear at musicgain=1.0 sfxgain=1.0 ([env] banner in playtest_0801_2012.log) — verdict "sounds ok
// for now". This is the register-true state and the one the guest-path migration wants; the 0.42
// hardware trim below is kept as a reference point, not a default.
// Reference points if re-tuned: RT_SFXGAIN=0.42 (the hardware-measured trim, -7.6 dB, which put
// our p90 gameplay peak at 0.256 vs hardware 0.266); RT_MUSICGAIN=1.15 / 1.45 (louder music).
static float rt_sfx_cal(){
  static float v = [](){ const char* e=getenv("RT_SFXGAIN"); float f=e?(float)atof(e):1.0f;
                         return (f>0.0f && f<=16.0f)?f:1.0f; }();
  return v;
}

// Serialises every bridge state change (music streamer + one-shot voice slots + clip cache)
// between the guest hook threads and the audio submit thread. Declared here because both the
// clip cache below and the test harness need it.
static std::mutex g_br_mtx;

// Decoded-PCM cache (host memory; a whole bank of SE is a few MB decoded). Keyed by wave-bank
// NAME (stable string owned by rt_xwma.cpp's bank cache or a literal) + wave index.
struct RtXwClip { const char* wb; int idx; int16_t* pcm; size_t frames; int chans; int rate; bool bad; };
static std::vector<RtXwClip> g_xw_clips;
static std::atomic<long> g_xw_decodes{0}, g_xw_plays{0}, g_xw_fails{0};

// ⚠ 2026-07-31 (live-gate FAIL, second defect): decoding used to run INSIDE g_br_mtx, the same
// mutex rt_bridge_mix() takes on EVERY submitted frame. A first-play decode is 4-12 ms (the user's
// log: SYS_SE[0] 11.9 ms) = up to 2+ device periods of 5.33 ms during which the producer cannot
// hand over a frame — an instant ring drain at exactly the moment a new sound starts. That is the
// "at first crunchy". The cache now has its OWN mutex and decoding happens with g_br_mtx NOT held;
// g_br_mtx is taken only to install the finished voice, which is a handful of pointer stores.
static std::mutex g_clip_mtx;

// A resolved, decoded clip. Returned BY VALUE: g_xw_clips is a vector, so a pointer into it can be
// invalidated by a later push_back from another thread.
struct RtXwClipRef { const int16_t* pcm; size_t frames; int chans; int rate; };

static bool rt_xw_prepare(const char* wbName, int waveIdx, RtXwClipRef* out){   // NO g_br_mtx here
  {
    std::lock_guard<std::mutex> lk(g_clip_mtx);
    for(auto& c : g_xw_clips)
      if(c.idx==waveIdx && c.wb && wbName && std::strcmp(c.wb,wbName)==0){
        if(c.bad) return false;
        *out = { c.pcm, c.frames, c.chans, c.rate }; return true;
      }
  }
  char path[1024]; rt_xw_wb_path(wbName,path,sizeof path);
  if(!path[0]) return false;
  RtXwClip c{wbName,waveIdx,nullptr,0,0,0,false};
  auto publish=[&](void){ std::lock_guard<std::mutex> lk(g_clip_mtx); g_xw_clips.push_back(c); };
  int n = rt_xwb_entry_count(path);
  if(n>=0 && waveIdx>=n){
    std::fprintf(stderr,"[xwma] MISMATCH %s waveIdx=%d >= entryCount=%d — bank map may be wrong\n",
                 wbName,waveIdx,n);
    c.bad=true; publish(); return false;
  }
  int tag = rt_xwb_entry_tag(path,waveIdx);
  if(tag==0){
    // ★ 2026-08-01: PCM entries load straight into the clip cache (fread + BE16 swap, no DMO).
    // The old refusal here ("already reaches the speaker through the guest voice path") was
    // never positive-controlled, and the dispatch never reached it anyway — tag 0 was routed to
    // the MUSIC STREAMER first, which is the BGM-stop hijack (see rt_sepcm_mode above).
    unsigned absOff=0,len=0,loopStart=0,loopTotal=0; int chans=2,rate=48000,ptag=-1;
    if(rt_xwb_pcm_info(path,waveIdx,&absOff,&len,&chans,&rate,&ptag,&loopStart,&loopTotal)!=0
       || !len || chans<1 || chans>2){
      c.bad=true; publish();
      std::fprintf(stderr,"[sepcm] %s[%d]: cannot read PCM entry -> silent\n",wbName,waveIdx);
      return false;
    }
    size_t frames = (size_t)len/((size_t)chans*2);
    FILE* f = std::fopen(path,"rb");
    if(!f || !frames){ if(f) std::fclose(f); c.bad=true; publish(); return false; }
    uint8_t* raw = (uint8_t*)std::malloc(len);
    std::fseek(f,(long)absOff,SEEK_SET);
    size_t r = raw ? std::fread(raw,1,len,f) : 0;
    std::fclose(f);
    if(r!=len){ std::free(raw); c.bad=true; publish();
      std::fprintf(stderr,"[sepcm] %s[%d]: short read %zu/%u -> silent\n",wbName,waveIdx,r,len);
      return false; }
    int16_t* pcm = (int16_t*)std::malloc(frames*(size_t)chans*2);
    for(size_t i=0;i<frames*(size_t)chans;i++)              // XWB payload is big-endian PCM16
      pcm[i] = (int16_t)((raw[i*2]<<8)|raw[i*2+1]);
    std::free(raw);
    c.pcm=pcm; c.frames=frames; c.chans=chans; c.rate=rate;
    std::fprintf(stderr,"[sepcm] loaded %s[%d]: %zu frames %dch %dHz (%.3fs)\n",
                 wbName,waveIdx,frames,chans,rate,(double)frames/(double)(rate?rate:1));
    *out = { c.pcm, c.frames, c.chans, c.rate };
    publish();
    return true;
  }
  if(tag!=3){
    c.bad=true; publish();
    std::fprintf(stderr,"[xwma] %s[%d] tag=%d unsupported -> silent\n",wbName,waveIdx,tag);
    return false;
  }
  auto t0 = std::chrono::steady_clock::now();
  int rc = rt_xwma_decode_xwb_entry(path,waveIdx,&c.pcm,&c.frames,&c.chans,&c.rate);
  double ms = std::chrono::duration<double,std::milli>(std::chrono::steady_clock::now()-t0).count();
  if(rc!=0 || !c.pcm || !c.frames){
    c.bad=true; g_xw_fails.fetch_add(1);
    std::fprintf(stderr,"[xwma] decode rc=%d for %s[%d] — voice stays silent\n",rc,path,waveIdx);
    publish(); return false;
  }
  g_xw_decodes.fetch_add(1);
  std::fprintf(stderr,"[xwma] decoded %s[%d]: %zu frames %dch %dHz (%.3fs) in %.1f ms (off the mix lock)\n",
               wbName,waveIdx,c.frames,c.chans,c.rate,
               (double)c.frames/(double)(c.rate?c.rate:1),ms);
  *out = { c.pcm, c.frames, c.chans, c.rate };
  publish();
  return true;
}

// Overlapping one-shot voices (SE fire on top of each other; 8 is well past what a menu needs).
// ★ RT_SELOOP (2026-07-31, DEFAULT OFF — not yet validated by ear, see the gate rule below).
// Offline decode of the shipped .xsb sound records shows two record shapes, and the split is the
// LOOP distinction:
//   flags=0x00 size=12  -> one-shot        flags=0x01 size=36 -> event sound whose trailing
//                                          PlayWave carries XACT's 0xFF infinite-loop marker
// Evidence from the shipped data, not from the spec: `m05_govr` (game over) is the ONLY size-12
// cue in BGM.xsb — the one stage track that must not loop — while every looping stage track is
// size-36; and the SE cues NAMED with an L (se09La, se19Lb, se25Lb) are size-36 too.
// Our voice mixer has never looped anything: it just clears `active` at end of sample, so every
// looping SE plays once and stops. Wire the flag through, but leave it OFF until it is gated
// against real gameplay SFX with the user listening — shipping an audio change on a gate that
// did not cover gameplay SFX is exactly what regressed the build on 07-31.
static bool rt_seloop_on(){
  static bool on = std::getenv("RT_SELOOP") != nullptr;
  return on;
}
// sb/cue = the cue identity that started the voice (for the guest's stop-by-cue path; a LOOPING
// voice must be stoppable or RT_SELOOP=1 turns every shot-loop into an infinite drone).
// fade: declick ramp state — 1.0 = full; a stopping voice ramps to 0 over ~1.3ms then frees.
struct RtXwVoice { const int16_t* pcm; size_t frames; int chans; double pos, step; bool active; int cat; bool loop;
                   const char* sb; int cue; float vol; float fade; bool stopping; };
// ★ 2026-08-01: 8 -> 32 voices. Rapid fire alone is 6-7 concurrent 0.46s shot instances; at 8
// slots the pool overflowed constantly and every steal REPLACED A PLAYING VOICE MID-SAMPLE — a
// click per steal, i.e. a crunch stream exactly when sounds overlap (the user's report through
// rounds 5-7, invariant under every gain change because it never was gain). 360 hardware had
// dozens of voices. Steal policy when genuinely full: the voice closest to its natural end.
static const int kXwVoices = 32;
static RtXwVoice g_xw_v[kXwVoices];

// MUST be called with g_br_mtx NOT held: it decodes (multi-ms) before taking the lock, and only
// the voice-slot install runs locked. See the g_clip_mtx note above.
static void rt_xw_start(const char* wbName, int waveIdx, int cat, bool loop=false,
                        const char* sbName=nullptr, int cueIndex=-1, float vol=1.0f){
  RtXwClipRef c{};
  if(!rt_xw_prepare(wbName,waveIdx,&c)) return;               // decode happens HERE, unlocked
  int slot;
  {
    std::lock_guard<std::mutex> lk(g_br_mtx);
    slot=-1;
    for(int i=0;i<kXwVoices;i++) if(!g_xw_v[i].active){ slot=i; break; }
    if(slot<0){                                               // full: steal closest-to-end
      double bestLeft=1e18;
      slot=0;
      for(int i=0;i<kXwVoices;i++){
        double left = g_xw_v[i].loop ? 1e17 : (double)g_xw_v[i].frames - g_xw_v[i].pos;
        if(left<bestLeft){ bestLeft=left; slot=i; }
      }
    }
    g_xw_v[slot] = { c.pcm, c.frames, c.chans, 0.0,
                     (double)c.rate/(double)kRateHz, true, cat,
                     loop && rt_seloop_on(), sbName, cueIndex, vol, 1.0f, false };
  }
  long p = g_xw_plays.fetch_add(1)+1;
  if(p<=24) std::fprintf(stderr,"[xwma] PLAY %s[%d] slot=%d %dch %dHz step=%.5f (play#%ld)\n",
                         wbName,waveIdx,slot,c.chans,c.rate,
                         (double)c.rate/(double)kRateHz,p);
}

// RT_XWMATEST="bank:idx[,bank:idx...]" (default-OFF) — in-process acceptance harness. Fires the
// listed bank entries through the EXACT runtime path a committed cue takes (rt_xw_start -> decode
// -> voice slot -> rt_xw_mix -> the submitted 48k frame -> RT_AUDIODUMP/WASAPI), one every ~1.5 s,
// without needing a credited-field drive to produce the cues. Proves the wiring inside the real
// exe; it does NOT prove which cueIds the game fires (that still needs a field drive).
// RT_CUETEST="SoundBank:cueIndex,..." (2026-07-31) drives the SAME entry point the shell-side
// Prepare hook uses — cue index -> .xsb -> wave -> PCM stream or xWMA one-shot — so the beta
// dispatch can be gated in-process without a field drive. e.g. RT_CUETEST="SYS_SE:1,BGM:2".
struct RtXwTest { const char* wb; int idx; bool asCue; };
static std::vector<RtXwTest> g_xw_test;
static bool rt_xw_test_on(){
  static bool parsed=false, on=false;
  if(!parsed){
    parsed=true;
    // Accepts either the legacy numeric bankType (`1:25`) or a wave-bank NAME (`SYS_SE:5`) —
    // names are how the shell banks are reachable, and how the beta gate fires SE_OK01.
    // Stable storage for the parsed name strings (heap-owned: a vector<string> would dangle the
    // c_str() of earlier entries on reallocation).
    static std::vector<std::string*> names;
    auto parse=[&](const char* s, bool asCue){
      if(!s || !*s) return;
      on=true;
      const char* p=s;
      while(*p){
        const char* tokStart=p;
        while(*p && *p!=':' && *p!=',') p++;
        std::string tok(tokStart,(size_t)(p-tokStart));
        int idx=0;
        if(*p==':'){ p++; idx=(int)strtol(p,(char**)&p,10); }
        const char* nm=nullptr;
        if(!asCue && !tok.empty() && (tok[0]=='-' || (tok[0]>='0'&&tok[0]<='9')))
          nm = rt_xw_bank_name(atoi(tok.c_str()));       // legacy numeric bankType
        else if(!tok.empty()){ names.push_back(new std::string(tok)); nm = names.back()->c_str(); }
        if(nm) g_xw_test.push_back({nm,idx,asCue});
        while(*p && *p!=',') p++;
        if(*p==',') p++;
      }
    };
    parse(getenv("RT_XWMATEST"), false);
    parse(getenv("RT_CUETEST"),  true);
    if(on) std::fprintf(stderr,"[xwma] test harness armed: %zu entries (RT_XWMATEST/RT_CUETEST)\n",
                        g_xw_test.size());
  }
  return on;
}
// NOTE: called with g_br_mtx NOT held — the cue arm re-enters rt_audio_bridge_play_cue, which takes
// the mutex itself (holding it here would self-deadlock on a non-recursive std::mutex).
static void rt_xw_test_tick(){
  if(!rt_xw_test_on() || g_xw_test.empty()) return;
  static long n=0; static size_t next=0;
  const long period=280;                                     // ~1.5 s at 187.5 submits/s
  if((n++ % period)==0 && next<g_xw_test.size()){
    RtXwTest t=g_xw_test[next++];
    std::fprintf(stderr,"[xwma] TEST fire #%zu %s=%s idx=%d\n",next,
                 t.asCue?"soundbank":"wavebank",t.wb?t.wb:"(null)",t.idx);
    if(t.asCue) rt_audio_bridge_play_cue(t.wb,t.idx);
    else        rt_xw_start(t.wb,t.idx,-1);                  // both take g_br_mtx internally
  }
}

static void rt_xw_mix(float* st){                            // caller holds g_br_mtx
  for(int i=0;i<kXwVoices;i++){
    RtXwVoice& v=g_xw_v[i];
    if(!v.active) continue;
    // Gain = category x authored sound volume x kXaFold (the SDK's 5.1->stereo fold — bridge
    // content injects post-fold and must carry the same 1/2.5 the guest-mixed path gets).
    for(int s=0;s<kChanSamples;s++){
      size_t i0=(size_t)v.pos;
      if(i0+1>=v.frames){
        if(v.loop && v.frames>1){ v.pos -= (double)(v.frames-1); i0=(size_t)v.pos; }
        else { v.active=false; break; }
      }
      float g = rt_cat_gain(v.cat) * v.vol * kXaFold;
      if(v.stopping){                       // declick: ~1.3ms linear ramp-out, then free the slot
        v.fade -= (1.0f/64.0f);
        if(v.fade<=0.0f){ v.active=false; break; }
        g *= v.fade;
      }
      double fr = v.pos-(double)i0;
      if(v.chans>=2){
        float l0=v.pcm[i0*2], l1=v.pcm[(i0+1)*2];
        float r0=v.pcm[i0*2+1], r1=v.pcm[(i0+1)*2+1];
        st[s*2]   += (float)((l0+(l1-l0)*fr)*(1.0/32768.0))*g;
        st[s*2+1] += (float)((r0+(r1-r0)*fr)*(1.0/32768.0))*g;
      } else {
        float m0=v.pcm[i0], m1=v.pcm[i0+1];
        float m=(float)((m0+(m1-m0)*fr)*(1.0/32768.0))*0.7071f*g; // mono spread, equal-power
        st[s*2]+=m; st[s*2+1]+=m;
      }
      v.pos += v.step;
    }
  }
}

static FILE*      g_br_file   = nullptr;   // the streaming (music) .xwb, kept open for the session
static const char* g_br_wb    = nullptr;   // which wave bank g_br_file holds
static long long  g_br_base   = 0;         // absolute file offset of the PlayRegion start
static long long  g_br_len    = 0;         // PlayRegion byte length
static long long  g_br_cursor = 0;         // bytes consumed within the region (loops)
static long long  g_br_loop   = 0;         // byte offset to jump back to at the end (loop start)
static int        g_br_chans  = 2;
static int        g_br_rate   = 48000;
static int        g_br_wave   = -1;        // currently loaded waveIdx (-1 = none)
static bool       g_br_active = false;
// WHICH CUE started the stream. The guest's own stop path is keyed by (soundBank, cueIndex), so we
// record the same identity at play time and only stop when the guest stops THAT cue (2026-07-31).
static const char* g_br_sb    = nullptr;
static int        g_br_cue    = -1;
static int        g_br_cat    = -1;   // XACT category of the cue driving the stream
// The GUEST cue object that started the stream, plus the identity it had then. The shell never
// calls any XACT Stop for the menu BGM (traced: SoundBank::Stop / the engine walker / cue Stop /
// the voice stop all fire 0x across a full mode-select) — it ends the music by DESTROYING the cue
// instance. So the truthful mirror is the guest's own IXACT3Cue::GetState (FUN_820ecac8):
//     inst = *(u32*)(cue+0x38);  inst==0            => STOPPED
//     st   = *(u32*)(inst+0x58); st outside 1..5    => STOPPED (the guest maps 6/other to 0x20)
// The identity words are re-checked too, so a recycled/freed object can never read as "still
// playing". Polled on the vblank thread in rt.cpp — guest data, guest timing, no host timer.
static uint32_t   g_br_cueobj = 0;
static uint32_t   g_br_bankptr= 0;
// STAGED, not committed: only rt_br_start_pcm() may adopt these, because a cue that turns out to be
// an SE one-shot must NOT overwrite the handle the music stream is watched by (that would make the
// mirror poll an SE instance and kill the music when that SE ended).
static thread_local unsigned t_pending_cueobj = 0, t_pending_bankptr = 0;
// ★ 2026-08-01 PER-PLAY VOLUME (opus research + decomp): the game passes volume as an ARGUMENT —
// sub_88090588(slot, cueId, r5=vol, bgmFlag) — and sub_88090110 applies coef = vol/64 (64=unity)
// via IXACT3Cue::SetMatrixCoefficients. There are NO 0x88 XACT twins; this argument is the game's
// entire per-instance volume interface. Field range observed: 25..95 (0.39x..1.48x). The crux hook
// (merged_game.cpp sub_88090588) stages it here around the original call; the shell Prepare funnel
// fires NESTED inside that call on the same thread, so the dispatch below picks it up. <0 = none.
static thread_local float t_pending_playvol = -1.0f;
extern "C" void rt_audio_stage_play_volume(int vol64){
  t_pending_playvol = (vol64>=0)? (float)vol64*(1.0f/64.0f) : -1.0f;
}

// Start (or switch) the host-side PCM music stream. wbName = wave-bank basename ("BGM"/"SYS_BGM").
// Ignores a re-request of the entry already playing, so the cursor is not reset every commit.
// MUST be called with g_br_mtx NOT held (2026-07-31): the header read and the fopen of a 182 MB
// bank are filesystem work, and doing them under the mix lock stalls the producer exactly like the
// decode did. Everything slow happens first; the lock is taken only to swap the stream state in.
static float      g_br_vol    = 1.0f;      // authored per-sound gain of the cue driving the stream
static void rt_br_start_pcm(const char* wbName, int waveIdx, const char* sbName, int cueIndex, int cat, float vol=1.0f){
  {
    std::lock_guard<std::mutex> lk(g_br_mtx);
    if(g_br_active && waveIdx==g_br_wave && g_br_wb && wbName && std::strcmp(g_br_wb,wbName)==0) return;
  }
  char path[1024]; rt_xw_wb_path(wbName,path,sizeof path);
  if(!path[0]) return;
  unsigned absOff=0,len=0,loopStart=0,loopTotal=0; int chans=2,rate=48000,tag=-1;
  if(rt_xwb_pcm_info(path,waveIdx,&absOff,&len,&chans,&rate,&tag,&loopStart,&loopTotal)!=0){
    std::fprintf(stderr,"[bridge] %s[%d]: cannot read entry\n",wbName,waveIdx); return; }
  if(tag!=0){ std::fprintf(stderr,"[bridge] %s[%d] tag=%d not PCM -> skip\n",wbName,waveIdx,tag); return; }
  // Open the new bank BEFORE taking the lock; swap it in under the lock.
  FILE* nf = nullptr;
  {
    std::lock_guard<std::mutex> lk(g_br_mtx);
    if(g_br_file && g_br_wb && std::strcmp(g_br_wb,wbName)==0) nf = g_br_file;   // reuse
  }
  bool opened=false;
  if(!nf){
    nf = std::fopen(path,"rb");
    if(!nf){ std::fprintf(stderr,"[bridge] cannot open %s\n",path); return; }
    opened=true;
  }
  std::lock_guard<std::mutex> lk(g_br_mtx);
  if(opened){
    if(g_br_file) std::fclose(g_br_file);
    g_br_file = nf; g_br_wb = wbName;
    std::fprintf(stderr,"[bridge] opened %s\n",path);
  }
  g_br_base   = (long long)absOff;
  g_br_len    = (long long)len;
  g_br_cursor = 0;
  g_br_chans  = chans;
  g_br_rate   = rate;
  g_br_wave   = waveIdx;
  g_br_active = true;
  g_br_sb     = sbName;
  g_br_cue    = cueIndex;
  g_br_cat    = cat;
  g_br_vol    = vol;
  // ★ 2026-08-01 (user: "menu music didn't come back"): the guest's handover fade parks our
  // mirrored Global at ~0 and the true restore lives in the undecomp'd fade-END msg receiver —
  // so a RETURNING menu stream played at master x0.0001. A new music cue starting is the guest
  // unambiguously intending audible music: reset the mirrored master. (The handover fade still
  // works — it ramps DURING a stream; this only clears the stale landing between streams.)
  if(g_cat_init && g_cat_vol[0] < 0.5f){
    std::fprintf(stderr,"[catfade] master %.4f -> 1.0 (new music stream %s[%d] resets stale fade landing)\n",
                 (double)g_cat_vol[0],wbName,waveIdx);
    g_cat_vol[0] = 1.0f;
  }
  g_br_cueobj = t_pending_cueobj;      // adopt the guest handle ONLY for a real music start
  g_br_bankptr= t_pending_bankptr;
  // WAVEBANKENTRY LoopRegion is in SAMPLES for PCM ({start, total}); BGM entry0 = {66053,1396363}
  // and 66053+1396363 == the entry's exact sample count, i.e. "intro once, then loop the body".
  // Looping the whole region (the pre-07-31 behaviour) replayed the intro every pass.
  long long loopBytes = (long long)loopStart * (long long)g_br_chans * 2;
  g_br_loop = (loopTotal && loopBytes>0 && loopBytes<g_br_len) ? loopBytes : 0;
  std::fprintf(stderr,"[bridge] PLAY %s[%d] base=0x%llX len=%lld %dch %dHz (~%.1fs) loop@%lld (%u,%u)%s\n",
    wbName,waveIdx,(unsigned long long)g_br_base,g_br_len,g_br_chans,g_br_rate,
    (double)g_br_len/(double)(g_br_rate*g_br_chans*2), g_br_loop, loopStart, loopTotal,
    g_br_rate!=kRateHz?"  [WARN rate!=48k, no resample]":"");
}

// LEGACY entry point: the game-side crux (merged_game.cpp sub_88090588) speaks bankType and passes
// the value straight out of the game cue table — which is a SOUNDBANK CUE INDEX, not a wave index.
// Kept for the RT_CUEBRIDGE=0 revert arm; the cue index is now resolved through the .xsb here too,
// so even the legacy arm plays the right track.
extern "C" void rt_audio_bridge_play(int bankType, int waveIdx){
  if(!rt_bridge_on()) return;
  const char* sb = rt_xw_bank_name(bankType);
  if(!sb) return;
  rt_audio_bridge_play_cue(sb, waveIdx);
}

// ---- THE DISPATCH (2026-07-31): a cue index in a NAMED SoundBank ---------------------------------
// Called from the shell-side SoundBank::Prepare hook (merged_shell.cpp sub_820EEE00), which is the
// ONE funnel every prepared cue passes through — game banks (BGM/SE/VOICE, reached via the game's
// crux -> handler vtable[+0x10]) AND the shell's own banks (SYS_SE menu SFX, SYS_BGM menu music),
// which have no bankType in the game cue table and therefore never had any path to a speaker.
// cueIndex -> (waveBank, waveIndex) is resolved from the .xsb; PCM entries stream, xWMA entries
// decode+play as one-shots.
// cueObj/bankPtr are the guest handles for the lifetime mirror (0 = harness / unknown).
extern "C" void rt_audio_bridge_play_cue_h(const char* sbName, int cueIndex,
                                           unsigned cueObj, unsigned bankPtr){
  t_pending_cueobj = cueObj; t_pending_bankptr = bankPtr;
  rt_audio_bridge_play_cue(sbName,cueIndex);
  t_pending_cueobj = 0; t_pending_bankptr = 0;
}
extern "C" void rt_audio_bridge_play_cue(const char* sbName, int cueIndex){
  if(!sbName) return;
  if(!rt_bridge_on() && !rt_xw_test_on()) return;   // harness may drive it without the bridge
  RtXsbCue q;
  int rc = rt_xsb_cue(sbName,cueIndex,&q);
  const char* wb = (rc==0) ? rt_xsb_wavebank(sbName,q.waveBankIndex) : sbName;
  int wave = (rc==0) ? q.waveIndex : cueIndex;      // no bank on disk -> identity, as before
  {
    // ★ 2026-08-02 PER-CUE TALLY. The 48-line detail cap below silently truncates a session, and
    // reading the truncated lines as counts nearly produced a false finding ("the shot cue fires
    // once per session, so it must be looping") — the cap had simply been reached. Detail stays
    // capped so the log does not flood; the TALLY is uncapped and prints every 512 dispatches, so
    // firing RATES are always answerable. Same lesson as the catvol log: a measurement that goes
    // quiet when it matters invites a wrong attribution.
    {
      static std::mutex tm; static std::map<std::string,long> tally; static long tn=0;
      char key[128]; std::snprintf(key,sizeof key,"%s cue%d",sbName,cueIndex);
      std::lock_guard<std::mutex> lg(tm);
      tally[key]++;
      if(++tn % 512 == 0){
        std::fprintf(stderr,"[cuetally] %ld dispatches:",tn);
        for(auto& kv : tally) std::fprintf(stderr," %s=%ld",kv.first.c_str(),kv.second);
        std::fprintf(stderr,"\n");
      }
    }
    static std::atomic<long> n{0}; long k=n.fetch_add(1)+1;
    if(k<=48) std::fprintf(stderr,"[cue] %s cue%d (%s) -> %s wave %d vol=%.2f%s\n",
      sbName,cueIndex,(rc==0&&q.name)?q.name:"?",wb,wave,(rc==0)?q.volume:1.0f,
      (rc==0&&!q.fromXsb)?" [identity-fallback]":"");
  }
  char path[1024]; rt_xw_wb_path(wb,path,sizeof path);
  if(!path[0]) return;
  int tag = rt_xwb_entry_tag(path,wave);
  // ★ 2026-08-01 ROUTE BY BANK ROLE, NOT WAVE FORMAT. Only the music banks may drive the singleton
  // PCM streamer; the three PCM waves in SE.xwb (the shot-loop class) used to land there via the
  // tag and hijack+kill the BGM stream on every dispatch. See rt_sepcm_mode for the evidence.
  // NOTE: neither branch may be called holding g_br_mtx — both do filesystem/decode work first and
  // take the lock only to install. Holding it here was the "crunchy" stall (see g_clip_mtx).
  bool musicBank = wb && (!std::strcmp(wb,"BGM") || !std::strcmp(wb,"SYS_BGM"));
  int cat   = (rc==0) ? q.category : -1;
  int loop  = (rc==0) && q.loopInfinite;
  float vol = (rc==0) ? q.volume : 1.0f;        // authored per-sound gain (FAudio curve)
  if(t_pending_playvol >= 0.0f) vol *= t_pending_playvol;  // game's per-play vol/64 (crux staged)
  // ★ 2026-08-01 round-10 DOUBLE-RENDER FIX ([gframe] probe: the guest's OWN frame carries rms
  // 0.08-0.21 of SFX during gameplay, zero in menus). The game's native XACT path renders the
  // in-memory SE/VOICE one-shots itself — the bridge was layering a latency-shifted SECOND copy
  // of every gameplay sound = comb-filter "crunch on overlaps", invariant under all gain fixes.
  // The bridge now plays ONLY what the guest cannot: the BGM/SYS_BGM streams (guest streaming
  // path stalls — ATLAS_audio 0x11891000 ring plateau) and menu SYS_SE. RT_BRIDGESE=1 restores
  // bridge dispatch of game SE/VOICE (the pre-round-10 doubling arm).
  static const bool bridgeSE = [](){ const char* e=getenv("RT_BRIDGESE"); return e && e[0]=='1'; }();
  // ★ 2026-08-01 SYS_SE ADDED (settings-audit follow-up). The round-10 de-doubling covered game
  // SE/VOICE but left the shell's own menu bank bridged — and the guest renders those too, so
  // every menu click has been playing TWICE (the same comb-filter class round 10 fixed for
  // gameplay). MEASURED on the cv_on capture, button presses at 21.8s/27.8s/30.3s: the guest tap
  // shows the click onsets decaying 0.022 -> 0.000 over ~1.5s, while the bridge simultaneously
  // carries its own copy on top of the menu music. RT_BRIDGESE=1 restores the old doubling for A/B.
  // ⚠ 2026-08-02 THE TAIL OF THIS COMMENT WAS STALE AND IS DELETED. It read "SYS_BGM menu MUSIC
  // stays bridged, because the guest renders no music at all (the guest's streaming path is the
  // open post-beta item)". That stopped being true when the XMP status stub was implemented
  // (08890f6): the guest renders ALL music now and the host streamer is retired (a8cdb79). A
  // comment that describes a retired architecture is the same wrong-attribution trap the [env]
  // banner was added to kill — every music bank is the guest's, and nothing here bridges music.
  bool guestRendersBank = sbName && (!std::strcmp(sbName,"SE") || !std::strcmp(sbName,"VOICE")
                                     || !std::strcmp(sbName,"SYS_SE"));
  if(guestRendersBank && !bridgeSE){
    static std::atomic<long> sn{0}; long sk=sn.fetch_add(1)+1;
    if(sk<=12) std::fprintf(stderr,"[cue] %s cue%d -> native (guest renders SE/VOICE/SYS_SE; RT_BRIDGESE=1 reverts)\n",
                            sbName,cueIndex);
    return;
  }
  if(rt_sepcm_mode()==0) musicBank = (tag==0);                // revert arm: pre-08-01 tag routing
  // ★ 2026-08-01 THE BRIDGE STOPS PLAYING MUSIC. The XMP status stub was THE reason the guest
  // rendered none (stubs.cpp __imp__XMsgInProcessCall): the shell was muting its own BGM/SYS_BGM
  // categories because an unanswered custom-soundtrack query read as "a soundtrack is playing".
  // With that answered the guest renders its own music — measured on the guest-ONLY tap, p50
  // 0.000000 -> 0.058128 sustained. Keeping the host stream would now DOUBLE it, the same
  // latency-shifted comb-filter defect fixed for game SE (6f9284c) and menu SYS_SE (c368db8).
  // This is the bridge's music streamer being RETIRED by the guest, exactly as the migration plan
  // (§1.5) said it should be. Lever: RT_BRIDGEMUSIC=1 forces the host stream back on (pair it with
  // RT_XMP=0, or you get both); RT_BRIDGEMUSIC=0 is also the arm to use if a bank ever turns out to
  // be one the guest genuinely cannot render.
  static const int bridgeMusic = [](){ const char* e=std::getenv("RT_BRIDGEMUSIC"); return e?atoi(e):0; }();
  static const bool xmpOn = [](){ const char* e=std::getenv("RT_XMP"); return !(e && e[0]=='0' && !e[1]); }();
  if(musicBank && xmpOn && !bridgeMusic){
    static bool once=false;
    if(!once){ once=true; std::fprintf(stderr,"[cue] music banks -> GUEST (XMP answered; host stream retired). RT_BRIDGEMUSIC=1 reverts\n"); }
    return;
  }
  if(musicBank){
    if(tag==0)      rt_br_start_pcm(wb,wave,sbName,cueIndex,cat,vol);          // music stream
    else if(tag==3){ if(rt_xwma_on()) rt_xw_start(wb,wave,cat,loop,sbName,cueIndex,vol); }
    else std::fprintf(stderr,"[cue] %s[%d] tag=%d unsupported -> silent\n",wb,wave,tag);
  } else {
    if(tag==0 && rt_sepcm_mode()==2)
      std::fprintf(stderr,"[sepcm] %s[%d] PCM suppressed (RT_SEPCM=2)\n",wb,wave);
    else if(tag==0 || tag==3){ if(rt_xwma_on()) rt_xw_start(wb,wave,cat,loop,sbName,cueIndex,vol); } // one-shot
    else std::fprintf(stderr,"[cue] %s[%d] tag=%d unsupported -> silent\n",wb,wave,tag);
  }
}

// Stop the host PCM music stream (cue stop / bank unload). Idempotent.
extern "C" void rt_audio_bridge_stop_music(void){
  std::lock_guard<std::mutex> lk(g_br_mtx);
  if(!g_br_active) return;
  g_br_active=false; g_br_wave=-1; g_br_sb=nullptr; g_br_cue=-1; g_br_cueobj=0; g_br_bankptr=0;
  std::fprintf(stderr,"[bridge] STOP music\n");
}

// ---- THE CUE-STOP DISPATCH (2026-07-31) --------------------------------------------------------
// Called from the guest's OWN stop funnel (merged_shell.cpp sub_820EC958 = IXACT3Cue::Stop, the
// method the engine's stop-by-cue walker FUN_820e8b98 itself invokes as wave->vtable[+0x04]).
// So this fires at the guest's site, on the guest's schedule, with the guest's own (bank,cue)
// identity — no host-side timer, no synthetic fade. If the stopped cue is the one that started the
// host music stream, the stream stops with it; anything else is logged and left alone.
//
// SCOPE (documented, deliberate): only the PCM MUSIC stream responds. The decoded xWMA one-shots
// (SE/VOICE/SYS_SE) are left to run to their natural end — the guest recycles those cue instances
// routinely, and honouring every such Stop would truncate short SFX that have already been handed
// to the mixer. Both user-reported defects are music, so this is the guest-truthful minimum.
// Lever: RT_CUESTOP=0 disables the dispatch entirely (the pre-07-31 "never stops" behaviour).
extern "C" int rt_audio_cuestop_enabled(void){
  static int on = [](){ const char* e=getenv("RT_CUESTOP"); return (e && e[0]=='0' && !e[1])?0:1; }();
  return on;
}
// ---- THE LIFETIME MIRROR (2026-07-31) ----------------------------------------------------------
// rt.cpp's vblank thread hands us the guest's own liveness verdict for the cue object that started
// the music (computed there because only that side has guest memory). alive==0 => the guest's
// GetState would say STOPPED, so the stream ends exactly when the guest's cue instance does.
// Levers: RT_CUESTOP=0 disables it (pre-07-31 "never stops"). Returns the cue object to poll, or 0.
extern "C" unsigned rt_audio_bridge_music_cueobj(unsigned* bankPtrOut, int* cueOut){
  if(!rt_bridge_on() || !rt_audio_cuestop_enabled()) return 0;
  std::lock_guard<std::mutex> lk(g_br_mtx);
  if(!g_br_active || !g_br_cueobj) return 0;
  if(bankPtrOut) *bankPtrOut = g_br_bankptr;
  if(cueOut)     *cueOut     = g_br_cue;
  return g_br_cueobj;
}
extern "C" void rt_audio_bridge_music_liveness(unsigned cueObj, int alive){
  // ★ DEBOUNCE (2026-08-01): the mirror polls guest words from the vblank thread — a sample rate
  // and thread the guest's own GetState never runs at — so a single mid-write tear can read as
  // "dead" once and silence the music forever. Require 3 CONSECUTIVE dead reads (~50ms): a
  // genuinely destroyed instance stays dead, so the stop still fires on the guest's schedule,
  // while a transient blip self-heals. The absorb line firing without a stop is direct evidence
  // of the transient class in the wild.
  static unsigned deadObj=0; static int deadRuns=0;
  if(alive){ if(deadObj==cueObj && deadRuns>0)
               std::fprintf(stderr,"[cue-stop] transient dead read absorbed (obj=0x%X, %d run%s)\n",
                            cueObj,deadRuns,deadRuns==1?"":"s");
             deadObj=0; deadRuns=0; return; }
  if(deadObj!=cueObj){ deadObj=cueObj; deadRuns=0; }
  if(++deadRuns<3) return;
  deadObj=0; deadRuns=0;
  const char* sb; int cue;
  {
    std::lock_guard<std::mutex> lk(g_br_mtx);
    if(!g_br_active || g_br_cueobj!=cueObj) return;      // already stopped / a different cue took over
    sb=g_br_sb; cue=g_br_cue;
    g_br_active=false; g_br_wave=-1; g_br_sb=nullptr; g_br_cue=-1; g_br_cueobj=0; g_br_bankptr=0;
  }
  std::fprintf(stderr,"[cue-stop] guest cue instance ended (%s cue%d, obj=0x%X) -> MUSIC STREAM STOPPED\n",
               sb?sb:"?",cue,cueObj);
}

extern "C" void rt_audio_bridge_stop_cue(const char* sbName, int cueIndex, int immediate){
  if(!rt_bridge_on() || !rt_audio_cuestop_enabled() || !sbName) return;
  bool hit=false; int loopstops=0;
  {
    std::lock_guard<std::mutex> lk(g_br_mtx);
    hit = g_br_active && g_br_sb && std::strcmp(g_br_sb,sbName)==0 && g_br_cue==cueIndex;
    if(hit){ g_br_active=false; g_br_wave=-1; g_br_sb=nullptr; g_br_cue=-1; }
    // ★ 2026-08-01: LOOPING voices honour the guest's stop (scope note above still holds for
    // plain one-shots — they run to their natural end). Without this, RT_SELOOP=1 turns every
    // shot-loop (se09La class) into an infinite drone the guest has already stopped.
    for(int i=0;i<kXwVoices;i++){
      RtXwVoice& v=g_xw_v[i];
      if(v.active && !v.stopping && v.loop && v.sb && std::strcmp(v.sb,sbName)==0 && v.cue==cueIndex){
        v.stopping=true; ++loopstops;        // declick ramp-out in the mixer, not a hard cut
      }
    }
  }
  if(loopstops){
    static std::atomic<long> ls{0};
    if(ls.fetch_add(1)<24)
      std::fprintf(stderr,"[cue-stop] %s cue%d -> %d looping voice(s) stopped\n",sbName,cueIndex,loopstops);
  }
  static std::atomic<long> n{0}; long k=n.fetch_add(1)+1;
  if(k<=64 || hit)
    std::fprintf(stderr,"[cue-stop] %s cue%d immediate=%d -> %s\n",
                 sbName,cueIndex,immediate, hit?"MUSIC STREAM STOPPED":"not the music cue (ignored)");
}

// Mix the active bridge PCM into the outgoing stereo float frame (256 stereo samples). Consuming 256
// samples per submit at ~187.5 submits/s == 48000 samples/s, so no resampling for a 48k bank.
static void rt_bridge_mix(float* st){
  // xWMA one-shots run for RT_AUDIOBRIDGE (cue-driven) or RT_XWMATEST (harness); both need only
  // a sink (RT_AUDIODUMP / RT_AUDIO). RT_AUDIOXWMA=0 disables the whole block.
  if(rt_xwma_on() && (rt_bridge_on() || rt_xw_test_on())){
    rt_xw_test_tick();                       // unlocked: the cue arm re-enters the bridge
    std::lock_guard<std::mutex> lk(g_br_mtx);
    rt_xw_mix(st);
  }
  if(!rt_bridge_on() && !rt_xw_test_on()) return;
  std::lock_guard<std::mutex> lk(g_br_mtx);
  if(!g_br_active || !g_br_file) return;          // BGM PCM streamer below
  const int frames = kChanSamples;                 // 256
  const int bpf    = g_br_chans*2;                 // bytes per source frame (BE PCM16)
  const int need   = frames*bpf;                   // <= 256*2*2 = 1024
  uint8_t buf[kChanSamples*2*2];
  int got=0;
  while(got<need){
    if(g_br_cursor>=g_br_len) g_br_cursor=g_br_loop; // loop point (intro not repeated); 0 if none
    long long avail = g_br_len - g_br_cursor;
    int chunk = (int)((need-got)<avail ? (need-got) : avail);
    std::fseek(g_br_file,(long)(g_br_base+g_br_cursor),SEEK_SET);
    int r = (int)std::fread(buf+got,1,chunk,g_br_file);
    if(r<=0){ std::memset(buf+got,0,need-got); break; }
    got += r; g_br_cursor += r;
  }
  // category x authored x SDK fold x hardware-calibrated music trim (see rt_music_cal)
  const float mg = rt_cat_gain(g_br_cat) * g_br_vol * kXaFold * rt_music_cal();
  for(int s=0;s<frames;s++){
    const uint8_t* p = buf + s*bpf;
    int16_t l = (int16_t)(((uint16_t)p[0]<<8)|(uint16_t)p[1]);           // one BE->host swap
    int16_t r = (g_br_chans>=2)?(int16_t)(((uint16_t)p[2]<<8)|(uint16_t)p[3]):l;
    st[s*2]   += (float)l*(1.0f/32768.0f)*mg;
    st[s*2+1] += (float)r*(1.0f/32768.0f)*mg;
  }
}

// Called from the XAudioSubmitRenderDriverFrame stub with the guest frame pointer.
// ★ [env] BOOT BANNER (2026-08-01, settings audit B4). Prints the RESOLVED post-default values of
// every audio lever, plus the build id, ONCE. Acceptance scripts must assert on THIS line and
// NEVER on launcher (.bat/.cmd) contents: the audit found a whole class of wrong attributions
// from doing the latter — an audio defect was blamed on a launcher pin when the deployed exe
// simply did not contain the hook at all. Host diagnostics only; changes no behaviour.
#ifndef FUTARI_BUILD_ID
#define FUTARI_BUILD_ID "unknown"
#endif
extern "C" void rt_audio_env_banner(void){
  static std::atomic<bool> done{false};
  if(done.exchange(true)) return;
  const int cvm = rt_catvol_mode();
  const char* cv = (cvm==0)?"off":(cvm==1)?"shell":"all";
  const char* ge = getenv("RT_AUDIOGAIN");
  float gain = ge?(float)atof(ge):1.0f; if(!(gain>0.0f && gain<=4.0f)) gain=1.0f;
  const char* le = getenv("RT_AUDIOLIMIT");
  const char* ce = getenv("RT_AUDIOCATCHUP");
  std::fprintf(stderr,
    "[env] build=%s audio=%d sink=%s bridge=%d xwma=%d cuebridge=%d worker=%d catvol=%s fadegain=%d "
    "sepcm=%d seloop=%d cuestop=%d musicgain=%.3f sfxgain=%.3f gain=%.2f limiter=%d catchup=%d\n",
    FUTARI_BUILD_ID, (int)rt_audio_live_on(), rt_sink_wasapi()?"wasapi(legacy)":"sdl3",
    (int)rt_bridge_on(), (int)rt_xwma_on(),
    (int)rt_audio_cuebridge_enabled(), (int)rt_audio_worker_on(),
    cv, rt_fadegain_mode(), rt_sepcm_mode(), (int)rt_seloop_on(), rt_audio_cuestop_enabled(),
    (double)rt_music_cal(), (double)rt_sfx_cal(), (double)gain,
    (int)(le && le[0]=='1' && !le[1]), (int)!(ce && ce[0]=='0' && !ce[1]));
}
extern "C" void rt_audio_submit(uint8_t* base, uint32_t samples_ptr){
  rt_audio_env_banner();          // first submit = the earliest point every lever is resolvable
  long n = g_submits.fetch_add(1)+1;
  rt_starve_stall_test();          // no-op unless RT_AUDIOSTALLTEST (positive control)
  static const char* dumpp = rt_audio_dump_path();
  static bool live = rt_audio_live_on();
  if(n==1) std::fprintf(stderr,"[audio] first submit: samples=%08X dump=%s live=%d\n",
                        samples_ptr, dumpp?dumpp:"(off)", live?1:0);
  if(!dumpp && !live) return;                       // levers off: count only
  if(!samples_ptr) return;
  const uint8_t* in = base + samples_ptr;

  // RT_AUDIOPROBE: diagnostic — dump raw guest frame bytes BEFORE downmix, to tell
  // "guest mixes zero" from "we mangle a nonzero frame". Scans the WHOLE 6ch frame for any
  // nonzero byte; logs the first N raw BE floats of ch0 + a per-channel nonzero-byte count.
  {
    static const char* probe = getenv("RT_AUDIOPROBE");
    if(probe){
      static long pn=0; long p=++pn;
      const int frame_bytes = 6*kChanSamples*4;
      int nz=0; for(int i=0;i<frame_bytes;i++) if(in[i]) nz++;
      // Onset transition: first nonzero frame after a run of zeros = a voice just started (e.g. a
      // menu SFX firing on a button press). This is the key isolation signal.
      static bool waszero=true;
      if(nz && waszero){ waszero=false;
        std::fprintf(stderr,"[audioprobe] ONSET at submit#%ld: %d/%d nonzero bytes, ch0[0..7]:",p,nz,frame_bytes);
        for(int s=0;s<8;s++) std::fprintf(stderr," %.5f", rt_audio_beflt(in+(0*kChanSamples+s)*4));
        std::fprintf(stderr," | nz/ch:");
        for(int c=0;c<6;c++){ int cnz=0; for(int b=0;b<kChanSamples*4;b++) if(in[(c*kChanSamples*4)+b]) cnz++; std::fprintf(stderr," %d",cnz); }
        std::fprintf(stderr,"\n");
      } else if(!nz) waszero=true;
      // Per-~1s heartbeat: max nonzero-byte-count seen in the window (0 => guest submitted only
      // silence this second). Proves whether ANY frame ever carried audio.
      static int maxnz=0; static long cnt=0;
      if(nz>maxnz) maxnz=nz;
      if(++cnt>=187){ std::fprintf(stderr,"[audioprobe] 1s window: maxnzbytes=%d (submit#%ld)\n",maxnz,p); maxnz=0; cnt=0; }
      if(p<=2) std::fprintf(stderr,"[audioprobe] #%ld ptr=%08X nzbytes=%d/%d\n",p,samples_ptr,nz,frame_bytes);
    }
  }

  // downmix 6ch sequential BE -> stereo interleaved LE (SDK conversion.h formula)
  float st[kStereoFloats];
  for(int s=0;s<kChanSamples;s++){
    float fl = rt_audio_beflt(in+(0*kChanSamples+s)*4);
    float fr = rt_audio_beflt(in+(1*kChanSamples+s)*4);
    float fc = rt_audio_beflt(in+(2*kChanSamples+s)*4);
    float bl = rt_audio_beflt(in+(4*kChanSamples+s)*4);
    float br = rt_audio_beflt(in+(5*kChanSamples+s)*4);
    float ch = fc*0.5f;
    // Fold constant is the SDK's; rt_sfx_cal() is the hardware-calibrated SFX trim (see above).
    const float gs = (1.0f/2.5f) * rt_sfx_cal();
    st[s*2]   = (fl+bl+ch)*gs;
    st[s*2+1] = (fr+br+ch)*gs;
  }

  // ★ [gframe]/[gqc] (2026-08-01): guest-frame quality metrics, BEFORE the bridge adds anything.
  // [gframe] rms proved the double-render (round 9). [gqc] hunts the round-10 residual: crunch
  // that survives with SE fully native must be IN the guest render itself — count (a) REPEATED
  // non-silent frames (stale delivery: the engine handshake missed and the callback re-served
  // the last mix) and (b) boundary DISCONTINUITIES (|first sample - previous frame's last| big
  // on non-silent audio = a click per occurrence). Both print 1/sec; correlate with fire.
  {
    static long gn=0; static double acc=0.0;
    static long rep=0, jmp=0; static float lastL=0.0f; static uint32_t lastHash=0; static bool lastLive=false;
    double facc=0.0;
    for(int i=0;i<kStereoFloats;i++) facc += (double)st[i]*(double)st[i];
    acc += facc;
    double frms = std::sqrt(facc/(double)kStereoFloats);
    bool live = frms > 0.005;
    uint32_t h = 2166136261u;
    for(int i=0;i<kStereoFloats;i++){ uint32_t w; std::memcpy(&w,&st[i],4); h=(h^w)*16777619u; }
    if(live && lastLive && h==lastHash) ++rep;
    if(live && lastLive && std::fabs(st[0]-lastL) > 0.35f) ++jmp;
    lastHash=h; lastL=st[kStereoFloats-1]; lastLive=live;
    if((++gn % 187)==0){
      double rms = std::sqrt(acc/(187.0*kStereoFloats)); acc=0.0;
      static long pn=0;
      if(pn++<600) std::fprintf(stderr,"[gqc] guest rms=%.4f repeats=%ld jumps=%ld (cumulative)\n",rms,rep,jmp);
    }
  }
  // ★ RT_AUDIODUMP2 (2026-08-01): dump the GUEST-ONLY stream (post-fold, pre-bridge) to a second
  // WAV for offline artifact classification — tearing is 256-sample-grid clicks, voice leak is a
  // rising noise floor, recompiler VMX damage has saturation/alias signatures. Same header/patch
  // discipline as the main dump.
  {
    static FILE* w2 = [](){
      const char* p = getenv("RT_AUDIODUMP2");
      if(!p) return (FILE*)nullptr;
      FILE* f = std::fopen(p,"wb");
      if(!f){ std::fprintf(stderr,"[audio] RT_AUDIODUMP2: cannot open %s\n",p); return (FILE*)nullptr; }
      uint8_t h[44]; std::memset(h,0,sizeof h);
      std::memcpy(h,"RIFF",4); std::memcpy(h+8,"WAVEfmt ",8);
      uint32_t fmtsz=16; std::memcpy(h+16,&fmtsz,4);
      uint16_t fmt=3, ch=2, bits=32; uint32_t rate=kRateHz;
      uint32_t brate=rate*ch*4; uint16_t align=ch*4;
      std::memcpy(h+20,&fmt,2); std::memcpy(h+22,&ch,2); std::memcpy(h+24,&rate,4);
      std::memcpy(h+28,&brate,4); std::memcpy(h+32,&align,2); std::memcpy(h+34,&bits,2);
      std::memcpy(h+36,"data",4);
      std::fwrite(h,1,44,f);
      std::fprintf(stderr,"[audio] RT_AUDIODUMP2 -> %s (guest-only stereo f32 48kHz)\n",p);
      return f;
    }();
    static long w2f = 0;
    if(w2){
      std::fwrite(st,4,kStereoFloats,w2);
      if((++w2f % 750)==0){                       // patch sizes ~every 4s so kills keep a valid file
        long data = w2f*(long)kStereoFloats*4;
        uint32_t riff=36u+(uint32_t)data, dsz=(uint32_t)data;
        std::fflush(w2); std::fseek(w2,4,SEEK_SET); std::fwrite(&riff,4,1,w2);
        std::fseek(w2,40,SEEK_SET); std::fwrite(&dsz,4,1,w2);
        std::fseek(w2,0,SEEK_END);
      }
    }
  }
  // RT_AUDIOBRIDGE: mix resident .xwb PCM for a committed cue into the frame (default-OFF, no-op
  // without the env). This is what makes the dump/live sink go NON-SILENT with real BGM.
  rt_bridge_mix(st);

  // ---- OUTPUT STAGE ----------------------------------------------------------------------------
  // ★ 2026-08-01 REVISED TO SDK TRUTH (opus research): the reference SDK port has NO output
  // limiter, NO gain trim, NO waveshaper — SubmitFrame is a memcpy, and clipping is prevented
  // UPSTREAM by per-voice gains (the game's per-play vol/64 argument, now honoured). The 07-31
  // tanh soft-knee was a per-sample waveshaper with no attack/release — i.e. a distortion
  // generator, and the user's "crunchy" (194k shaped samples/session). New defaults: gain 1.0,
  // limiter OFF (hard safety clamp at +/-1 only, which the device range requires). Revert arm:
  // RT_AUDIOLIMIT=1 re-enables the shaper, RT_AUDIOGAIN=<float> trims.
  // ★ 2026-08-02 THE NON-FINITE GUARD MUST NOT BE BRIDGE-GATED. Everything below used to sit
  // behind rt_bridge_on(), including the insanity check that is the ONLY finite test between the
  // guest frame and WASAPI. That was survivable while the bridge was always on, but the bridge is
  // being dismantled (music retired a8cdb79) and the day RT_AUDIOBRIDGE goes away by default the
  // guard would vanish silently with it — a NaN reaching the device is a full-scale screech, not a
  // glitch. Run the guard unconditionally; keep the gain/limiter apparatus bridge-gated as before
  // so this change is otherwise byte-identical.
  if(!(rt_bridge_on() || rt_xw_test_on())){
    for(int i=0;i<kStereoFloats;i++){
      float v = st[i];
      if(!(v>-8.0f && v<8.0f)) st[i] = (v>0.0f)? 8.0f : (v<0.0f? -8.0f : 0.0f);
    }
  }
  if(rt_bridge_on() || rt_xw_test_on()){
    static float gain = [](){ const char* e=getenv("RT_AUDIOGAIN"); float v=e?(float)atof(e):1.0f;
                              return (v>0.0f && v<=4.0f)?v:1.0f; }();
    static bool  lim  = [](){ const char* e=getenv("RT_AUDIOLIMIT"); return e && e[0]=='1' && !e[1]; }();
    static const float kKnee = 0.75f;
    static std::atomic<long> clipped{0};
    for(int i=0;i<kStereoFloats;i++){
      float v = st[i]*gain;
      float a = std::fabs(v);
      if(lim && a>kKnee){
        clipped.fetch_add(1,std::memory_order_relaxed);
        float over = (a-kKnee)/(1.0f-kKnee);
        a = kKnee + (1.0f-kKnee)*std::tanh(over);
        v = (v<0.0f)? -a : a;
      } else if(!lim){
        // ★ 2026-08-01 round-6 (user: overlaps still crunch): the hard +/-1 clamp WAS the
        // remaining clip. Shared-mode WASAPI float carries >1.0 samples to the OS mix engine,
        // whose built-in lookahead limiter (CAudioLimiter — the same stage XAudio2 rides)
        // handles overshoot gracefully; the SDK ships unclamped floats the same way. Keep only
        // an insanity guard against non-finite/runaway samples.
        if(!(v>-8.0f && v<8.0f)) v = (v>0.0f)? 8.0f : (v<0.0f? -8.0f : 0.0f);
      }
      st[i]=v;
    }
    static long ln=0;
    if((++ln % 1870)==0 && clipped.load())
      std::fprintf(stderr,"[audio] limiter: %ld samples over knee so far (gain=%.2f limit=%d)\n",
                   clipped.load(),gain,lim?1:0);
  }

  // 1x/sec evidence line: non-silence is visible in the log without opening the WAV
  {
    static float acc=0.f, peak=0.f; static long cnt=0;
    for(int i=0;i<kStereoFloats;i++){ float v=st[i]; acc+=v*v; float a=std::fabs(v); if(a>peak)peak=a; }
    if(++cnt>=187){
      // ring depth is on this line as of 2026-07-31: the live gate failed on a slow drain to zero
      // that was invisible because depth only ever printed at frames #1/#188/#1880.
      std::fprintf(stderr,"[audio] submits=%ld rms=%.4f peak=%.4f dropped=%ld depth=%u under=%ld%s\n",
                   n, std::sqrt(acc/((float)cnt*kStereoFloats)), peak, g_dropped.load(),
                   g_ring_wr.load()-g_ring_rd.load(), g_sv_total_under.load(),
                   rt_audio_worker_on()?" [worker]":" [vblank-pump]");
      acc=0.f; peak=0.f; cnt=0;
    }
  }

  if(dumpp){
    static bool opened=false;
    if(!opened){ opened=true; rt_audio_wav_open(dumpp); }
    if(g_wav){
      std::fwrite(st,sizeof(float),kStereoFloats,g_wav);
      if((++g_wav_frames % 187)==0) rt_audio_wav_patch();
    }
  }

  if(live){
#ifdef _WIN32
    static std::once_flag once;
    std::call_once(once,[](){
      if(rt_sink_wasapi()) std::thread(rt_audio_wasapi_thread).detach();  // legacy revert arm
      else                 rt_audio_sdl_start();                          // default: SDK-parity SDL3
    });
    uint32_t wr = g_ring_wr.load(std::memory_order_relaxed);
    if(wr - g_ring_rd.load(std::memory_order_acquire) >= (uint32_t)kRingFrames){
      g_dropped.fetch_add(1);                       // shouldn't happen with the pump gate
    } else {
      std::memcpy(g_ring[wr % kRingFrames], st, sizeof st);
      g_ring_wr.store(wr+1, std::memory_order_release);
    }
#else
    static bool warned=false;
    if(!warned){ warned=true; std::fprintf(stderr,"[audio] RT_AUDIO: no live backend on this platform yet (dump still works)\n"); }
#endif
  }
}

// The banner must print in EVERY run so any finding can be scoped to a build+config, including
// runs with audio levers off (where rt_audio_submit is never reached). A file-scope initializer
// is the only placement that guarantees that; it only reads getenv and function-local statics,
// so it is safe at static-init time.
namespace { struct RtEnvBannerInit { RtEnvBannerInit(){ rt_audio_env_banner(); } }; RtEnvBannerInit g_rt_env_banner_init; }
