#include "ppc_recomp_shared.h"
#include <cstdio>
#include <map>
#include <set>
#include <cstring>
#include <atomic>
#include <cstdint>
#include <cstdlib>   // std::getenv/std::atoll — RT_INDCENSUS reads env above the later include
#include <mutex>
#include <condition_variable>
#include <unordered_map>
#include <chrono>
#include "win_compat.h"
#include <string>
#ifdef _WIN32
#include <io.h>   // _commit/_fileno (E18 atomic-save flush)
#endif
// L3/E5 (dll_packaging_plan §3.6): the GAME code range and its host function-pointer table
// window are MODULE properties, not properties of whichever tree this TU was compiled from.
// They now come from the descriptor; the SHELL range stays hardcoded forever (the shell is
// the host and is never swapped).  Relative path: no build script needs a new -I.
#include "../host/futari_module_desc.h"
extern std::atomic<long> g_import_calls;
extern "C" uint32_t rt_alloc(uint32_t size, uint32_t align);   // bump allocator (in harness)
extern "C" void rt_recommit(uint32_t addr, uint32_t size);     // NtVA DECOMMIT/recommit (in harness)
#define LOGN(n) do{static bool o=false;if(!o){o=true;std::fprintf(stderr,"  [import] " n "\n");}g_import_calls++;}while(0)
static bool crt_trace(){ static bool on=getenv("RT_CRTTRACE")!=nullptr; return on; }

// --- event/wait machinery (game kernel) -----------------------------------
// Minimal RtEvent registry mirroring shell/gen/rt.cpp's design, scoped to the
// game module's own handle space so NtCreateEvent/NtSetEvent/NtWaitForSingleObjectEx
// interoperate here even when the game kernel wins the shared import in the
// merged binary. Handles allocated starting at 0x50000000 to stay clear of the
// 0xE000/0xF100 thread/file handle ranges used elsewhere in this TU.
struct RtObj{ virtual ~RtObj(){} };
struct RtEvent:RtObj{ std::mutex m; std::condition_variable cv; bool sig=false, manual=false; long count=0; bool counting=false; };
// RtSemaphore (2026-07-25 audio-kernel-parity leg): a real counting semaphore, EXACT rexglue
// parity with xboxkrnl_threading.cpp NtCreateSemaphore/NtReleaseSemaphore + rex::thread::Semaphore.
// Lives in the SAME game-side handle registry (g_rteht, 0x50000000 space) as RtEvent so the
// game-winning NtWaitForSingleObjectEx / NtWaitForMultipleObjectsEx resolve it (handle-based
// semaphore waits route through Nt*, and game links first -> wins globally for both modules).
// Motivated by stub_audit_2026-07-22.md line 107 + the SDK-referee verdict (NOTE_audio_4point_plan):
// the guest audio streaming producer->consumer (BGM disk-read -> decode -> buffer-queue) syncs on
// this; the old shell/gen/stubs.cpp no-op made every create/release/wait a silent success -> lost
// signals -> the streamed-PCM BGM buffer never refilled. Gated by RT_AUDIOSEM (default-OFF) so the
// no-env regression path is byte-identical to the historical no-op stub.
struct RtSemaphore:RtObj{ std::mutex m; std::condition_variable cv; long count=0; long maxcount=0x7FFFFFFF; };
static bool realsem(){ static bool on=getenv("RT_AUDIOSEM")!=nullptr; return on; }
static std::mutex g_rtevm; static std::unordered_map<uint32_t,RtObj*> g_rteht; static uint32_t g_rtenh=0x50000000;
static uint32_t rt_add(RtObj*o){ std::lock_guard<std::mutex> l(g_rtevm); uint32_t h=g_rtenh; g_rtenh+=4; g_rteht[h]=o; return h; }
static RtObj* rt_get(uint32_t k){ std::lock_guard<std::mutex> l(g_rtevm); auto it=g_rteht.find(k); return it==g_rteht.end()?nullptr:it->second; }
// CODE_REVIEW_0804 MED-7: lookup + insert under ONE lock. The old two-lock shape let two
// threads racing an unseen key both construct; the loser's insert overwrote the winner's
// object, orphaning a just-signalled event (lost wakeup) — and an unconditional overwrite
// could silently evict a semaphore under the same key.
static RtEvent* rt_ev(uint32_t k,bool create){
  std::lock_guard<std::mutex> l(g_rtevm);
  auto it=g_rteht.find(k);
  if(it!=g_rteht.end()){ if(auto*e=dynamic_cast<RtEvent*>(it->second))return e; return nullptr; }  // never evict a non-event
  if(!create)return nullptr;
  RtEvent*e=new RtEvent(); g_rteht[k]=e; return e; }
static RtSemaphore* rt_sem(uint32_t k){ return dynamic_cast<RtSemaphore*>(rt_get(k)); }
static void rt_mw_wake();   // fwd: defined with the realwait cluster below
static void rt_setev(uint32_t k){ if(auto*e=rt_ev(k,true)){ { std::lock_guard<std::mutex> l(e->m); e->sig=true; e->cv.notify_all(); } rt_mw_wake(); } }
static void rt_rstev(uint32_t k){ if(auto*e=rt_ev(k,true)){ std::lock_guard<std::mutex> l(e->m); e->sig=false;
  e->count=0; } }   // review wf_ea22499a #2: NtClearEvent must drain the counting backlog too, else stale counts hot-spin post-clear waits
// RT_EVCOUNT (LEG-25 fix): async read-completion events (signalled by NtReadFile) are made
// COUNTING. merged's reads are SYNCHRONOUS, so many reads signal the shared auto-reset
// completion event (0x50000018) back-to-back before the LZX streaming service thread waits;
// on a plain auto-reset event those signals COALESCE (one latched), the service thread wakes
// ~twice, feeds 2 reqs to the done-list then parks forever -> LZX assets never commit -> scene
// FSM stuck at state 5. Counting makes N completions deliver N wakes (matching real staggered
// async I/O), so no completion is lost. Scoped to events NtReadFile actually signals.
// ★ DEFAULT ON since 2026-07-28 (flicker-truth workflow wf_e3c67137 fix #1): completion
// coalescing on the shared auto-reset event was the only unbounded, boot-variable stall left in
// the async-IO chain — the shell's accessing/connecting indicator is visible for exactly the
// lifetime of its async task, so a coalesced under-wake stretched sub-frame tasks across
// presents = the "sometimes" NOW-LOADING flicker at M2. RT_EVCOUNT=0 restores coalescing.
static bool evcount(){ static bool on=[](){const char*e=getenv("RT_EVCOUNT");return e?atoi(e)!=0:true;}(); return on; }
// ★ Real multi-wait wake (flicker-truth fix #2): one global cv notified by EVERY event/semaphore
// signal so NtWaitForMultipleObjectsEx wakes in microseconds instead of its 1ms usleep poll (each
// producer->worker->consumer hop cost up to 1ms; the whole hardware lifetime of the indicator's
// task is smaller than one hop). Bounded 1ms fallback keeps missed-notify races harmless.
// RT_REALWAIT=0 restores the pure poll.
static std::condition_variable g_mwCv; static std::mutex g_mwM;
static bool realwait(){ static bool on=[](){const char*e=getenv("RT_REALWAIT");return e?atoi(e)!=0:true;}(); return on; }
static void rt_mw_wake(){ g_mwCv.notify_all(); }
static void rt_setev_completion(uint32_t k){ if(auto*e=rt_ev(k,true)){ { std::lock_guard<std::mutex> l(e->m); e->counting=true; e->count++; e->sig=true; e->cv.notify_all(); } rt_mw_wake(); } }
// auto-reset consume with counting support (caller holds e->m).
static void rt_consume(RtEvent* e){
  if(e->manual) return;                    // manual/notification event: stays signalled
  if(e->counting && e->count>0){ e->count--; e->sig=(e->count>0); return; }
  e->sig=false;
}
// --- video ---
// VdQueryVideoMode(XVIDEO_MODE* out, r3). A/B-tested 2026-07-22 (char-card hunt): filling the
// register-true 1280x720 HD struct here (same layout XGetVideoMode uses) makes the guest
// reconfigure its render targets in a way the panel compose path does not handle yet — the
// entire center panel goes black at menus/select — AND the asset loader STILL decodes the
// 256x256 variants (0x20014), so HD-mode brings no benefit today. Default therefore stays the
// legacy zero-fill (= all-zero mode struct, matching the historical no-op stub / ship-observed
// behavior). RT_HDMODE=1 opts in to the HD fill for the future HD-render leg.
PPC_FUNC_IMPL(__imp__VdQueryVideoMode){ LOGN("VdQueryVideoMode");
  static const bool hd = std::getenv("RT_HDMODE")!=nullptr;
  uint32_t p=ctx.r3.u32;
  if(p){ uint8_t* v=base+p; for(int i=0;i<0x50;i++) v[i]=0;
    if(hd){
      auto W=[&](uint32_t o,uint32_t val){ *(uint32_t*)(v+o)=__builtin_bswap32(val); };
      W(0,1280);W(4,720);W(8,0);W(0xC,1);W(0x10,1);W(0x14,0x42700000);W(0x18,1);
    } }
  ctx.r3.u32=0;
}
// --- memory ---
// HW-true (2026-08-04 decomp verdict): physical allocations are NOT kernel-zeroed — the guest
// wrappers memset themselves when flag 0x40000000 asks (shell FUN_82089ed8 / game FUN_880836d0
// callers, identical XAPI code). rt_alloc_raw reuses without zeroing (rt_phys.cpp, law 1).
extern "C" uint32_t rt_alloc_raw(uint32_t size,uint32_t align);
PPC_FUNC_IMPL(__imp__MmAllocatePhysicalMemoryEx){ LOGN("MmAllocatePhysicalMemoryEx"); uint32_t sz=ctx.r4.u32; ctx.r3.u32=rt_alloc_raw(sz?sz:0x1000,0x1000);
  // Big-alloc census (2026-07-20 soak leak hunt): log every phys alloc >= 256KB with size + lr
  // so the per-attract-cycle leak class (frees are no-op stubs) can be attributed to a caller.
  if(sz>=0x40000){ static long bn=0; if(bn++<200)
    std::fprintf(stderr,"[bigalloc] Mm size=%.1fMB lr=0x%llX -> 0x%X\n",sz/(1024.0*1024.0),(unsigned long long)ctx.lr,ctx.r3.u32); }
  { static std::map<uint64_t,std::pair<long,double>> msum; static long mn=0;
    auto& s=msum[(uint64_t)ctx.lr]; s.first++; s.second+=(sz?sz:0x1000)/(1024.0*1024.0);
    if((++mn%500)==0){ std::fprintf(stderr,"[allocsum] Mm after %ld allocs:",mn);
      for(auto& kv:msum) if(kv.second.second>=1.0) std::fprintf(stderr," lr=0x%llX n=%ld %.0fMB",(unsigned long long)kv.first,kv.second.first,kv.second.second);
      std::fprintf(stderr,"\n"); } }
  (void)base; }
PPC_FUNC_IMPL(__imp__NtAllocateVirtualMemory){ LOGN("NtAllocateVirtualMemory");
  // x360 ABI (rexglue xboxkrnl_memory.cpp): r3=&BaseAddress(in/out), r4=&RegionSize(in/out),
  // r5=alloc_type, r6=protect, r7=debug_memory. Flat 4GB mmap = every address is backed:
  // honor a requested base as-is; bump-alloc only when base==0.
  uint32_t baseptr=ctx.r3.u32, sizeptr=ctx.r4.u32;
  if(!baseptr||!sizeptr){ ctx.r3.u32=0xC000000D; return; }
  uint32_t reqbase=__builtin_bswap32(*(uint32_t*)(base+baseptr));
  uint32_t reqsize=__builtin_bswap32(*(uint32_t*)(base+sizeptr));
  if(!reqsize){ ctx.r3.u32=0xC000000D; return; }
  uint32_t sz=(reqsize+0xFFFu)&~0xFFFu;
  uint32_t addr=reqbase? (reqbase&~0xFFFu) : rt_alloc(sz,0x10000);
  // reqbase = COMMIT into an existing reservation (the guest allocator re-committing a
  // previously DECOMMITted arena segment): re-commit the host pages + cancel any pending
  // decommit quarantine covering the range (harness rt_recommit; no-op if never decommitted).
  if(reqbase) rt_recommit(addr,sz);
  if(sz>=0x40000 && !reqbase){ static long bn=0; if(bn++<200)
    std::fprintf(stderr,"[bigalloc] NtVA size=%.1fMB lr=0x%llX -> 0x%X\n",sz/(1024.0*1024.0),(unsigned long long)ctx.lr,addr); }
  // [allocsum] uncapped per-LR aggregation (2026-07-20 heap-leak attribution v2): the capped
  // per-line census exhausts on boot-era calls, leaving LATE-soak growth unattributed. Every
  // 200 base=0 allocs, print the running {lr: count, MB} table — the eternal grower names
  // itself in one soak.
  if(!reqbase){ static std::map<uint64_t,std::pair<long,double>> asum; static long an=0;
    auto& s=asum[(uint64_t)ctx.lr]; s.first++; s.second+=sz/(1024.0*1024.0);
    if((++an%200)==0){ std::fprintf(stderr,"[allocsum] NtVA after %ld allocs:",an);
      for(auto& kv:asum) std::fprintf(stderr," lr=0x%llX n=%ld %.0fMB",(unsigned long long)kv.first,kv.second.first,kv.second.second);
      std::fprintf(stderr,"\n"); } }
  *(uint32_t*)(base+baseptr)=__builtin_bswap32(addr);
  *(uint32_t*)(base+sizeptr)=__builtin_bswap32(sz);
  if(crt_trace()) std::fprintf(stderr,"  [NtAllocVM] req base=0x%X size=0x%X type=0x%X prot=0x%X -> addr=0x%X size=0x%X\n",reqbase,reqsize,ctx.r5.u32,ctx.r6.u32,addr,sz);
  ctx.r3.u32=0; /* STATUS_SUCCESS */ }
// --- TLS ---
static uint32_t g_tls_next=1; static thread_local uint32_t g_tls[256];
PPC_FUNC_IMPL(__imp__KeTlsAlloc){ LOGN("KeTlsAlloc"); ctx.r3.u32=g_tls_next++; (void)base; }
PPC_FUNC_IMPL(__imp__KeTlsFree){ LOGN("KeTlsFree"); ctx.r3.u32=1; (void)base; }
PPC_FUNC_IMPL(__imp__KeTlsGetValue){ LOGN("KeTlsGetValue"); uint32_t i=ctx.r3.u32; ctx.r3.u32=(i<256)?g_tls[i]:0; (void)base; }
PPC_FUNC_IMPL(__imp__KeTlsSetValue){ LOGN("KeTlsSetValue"); uint32_t i=ctx.r3.u32; if(i<256)g_tls[i]=ctx.r4.u32; ctx.r3.u32=1; (void)base; }
// --- REAL lock primitives (stub-audit HIGH: sync primitives that silently succeeded) ---
// Before: RtlEnter/LeaveCriticalSection and the Kf*/Ke* spinlocks were bare no-ops in BOTH
// rt.cpp copies (this one wins the merged link) and in stubs.cpp — every guest lock acquire
// "succeeded" without ever excluding another thread. ATLAS_threading_kernel.md CONFIRMS a real
// cross-thread race under these no-op locks: the async job ring 0x885c3280 (main-pump producers
// vs worker FUN_88092c28). So this is not hygiene — real primitives close a real race.
//
// Design: a keyed table guest-lock-address -> host std::recursive_mutex, lazily created on first
// acquire, PROCESS-LIFETIME (never destroyed — guest "delete"/free paths under recomp are
// unreliable, and a freed-then-reused address just re-keys the same mutex). recursive_mutex has
// exactly Win32 CRITICAL_SECTION semantics: Xbox critical sections AND spinlocks are recursive on
// the owning processor, so a recursive host lock can never self-deadlock on re-entrant acquire
// while still enforcing mutual exclusion between DIFFERENT host (guest) threads. (SRWLOCK was
// rejected precisely because it is non-recursive.)
//
// RT_NOLOCKS (presence-gated OPT-OUT; default = real locks ON, ship-true) reverts every primitive
// below to a no-op — the escape hatch if real locks surface a latent guest lock-ordering deadlock
// the no-op stubs used to mask. Under RT_NOLOCKS, TryEnter reports "acquired" (uncontended, no
// real lock) rather than the old audit-flagged always-fail 0.
static bool rt_nolocks(){ static bool off=getenv("RT_NOLOCKS")!=nullptr; return off; }
static std::mutex g_locktab_m;
static std::unordered_map<uint32_t,std::recursive_mutex*> g_locktab;
static std::recursive_mutex* rt_lock_for(uint32_t key){
  std::lock_guard<std::mutex> l(g_locktab_m);
  auto it=g_locktab.find(key); if(it!=g_locktab.end()) return it->second;
  std::recursive_mutex* m=new std::recursive_mutex(); g_locktab[key]=m; return m;
}
// Init: the lock is created lazily on first acquire, so init stays a no-op (return SUCCESS).
PPC_FUNC_IMPL(__imp__RtlInitializeCriticalSection){ LOGN("RtlInitializeCriticalSection"); ctx.r3.u32=0; (void)base; }
PPC_FUNC_IMPL(__imp__RtlInitializeCriticalSectionAndSpinCount){ LOGN("RtlInitializeCriticalSectionAndSpinCount"); ctx.r3.u32=0; (void)base; }
PPC_FUNC_IMPL(__imp__RtlEnterCriticalSection){ LOGN("RtlEnterCriticalSection");
  if(!rt_nolocks() && ctx.r3.u32) rt_lock_for(ctx.r3.u32)->lock(); (void)base; }
PPC_FUNC_IMPL(__imp__RtlLeaveCriticalSection){ LOGN("RtlLeaveCriticalSection");
  if(!rt_nolocks() && ctx.r3.u32) rt_lock_for(ctx.r3.u32)->unlock(); (void)base; }
// RtlTryEnterCriticalSection(r3=&cs) -> 1 acquired / 0 contended.
PPC_FUNC_IMPL(__imp__RtlTryEnterCriticalSection){ LOGN("RtlTryEnterCriticalSection");
  uint32_t r=1;
  if(!rt_nolocks() && ctx.r3.u32) r = rt_lock_for(ctx.r3.u32)->try_lock() ? 1u : 0u;
  ctx.r3.u32=r; (void)base; }
// Guest spinlocks -> the SAME keyed recursive-mutex table. IRQL is unmodeled: KfAcquireSpinLock
// returns previous-IRQL 0 (as the old stub did); Kf release takes old-IRQL in r4 (ignored).
PPC_FUNC_IMPL(__imp__KfAcquireSpinLock){ LOGN("KfAcquireSpinLock");
  uint32_t lk=ctx.r3.u32;
  if(!rt_nolocks() && lk) rt_lock_for(lk)->lock();
  ctx.r3.u32=0; /* previous IRQL */ (void)base; }
PPC_FUNC_IMPL(__imp__KfReleaseSpinLock){ LOGN("KfReleaseSpinLock");
  if(!rt_nolocks() && ctx.r3.u32) rt_lock_for(ctx.r3.u32)->unlock();
  ctx.r3.u32=0; (void)base; }
PPC_FUNC_IMPL(__imp__KeAcquireSpinLockAtRaisedIrql){ LOGN("KeAcquireSpinLockAtRaisedIrql");
  if(!rt_nolocks() && ctx.r3.u32) rt_lock_for(ctx.r3.u32)->lock(); (void)base; }
PPC_FUNC_IMPL(__imp__KeReleaseSpinLockFromRaisedIrql){ LOGN("KeReleaseSpinLockFromRaisedIrql");
  if(!rt_nolocks() && ctx.r3.u32) rt_lock_for(ctx.r3.u32)->unlock(); (void)base; }
// --- memory protection query (stub-audit H5) ---
// MmQueryAddressProtect(r3=address) -> page-protect flags. The old stub returned 0 (=NOACCESS) for
// EVERY address, so a guest that gates a read/write on the queried protection would treat valid
// committed RW memory as inaccessible. The port maps the whole guest space flat and READ/WRITE, so
// the register-true answer for any committed guest address is PAGE_READWRITE(0x04); the high
// sentinel/handle range (>=0xF0000000, used as the not-a-guest-pointer guard throughout this TU)
// and null return 0. RT_NOMEMPROTECT (opt-out) restores the old all-zero behavior.
PPC_FUNC_IMPL(__imp__MmQueryAddressProtect){ LOGN("MmQueryAddressProtect");
  static const bool off = getenv("RT_NOMEMPROTECT")!=nullptr;
  uint32_t a=ctx.r3.u32;
  ctx.r3.u32 = (!off && a && a<0xF0000000u) ? 0x04u /* PAGE_READWRITE */ : 0u;
  (void)base; }
// x360 ExCreateThread(r3=&handle_out, r4=stack_size, r5=&tid_out, r6=xapi_startup,
// r7=start_addr, r8=start_ctx, r9=creation_flags). Log-only for now: report what thread
// the game wants, hand back a dummy handle, do NOT run it yet.
extern "C" uint32_t g_thread_xapi, g_thread_entry, g_thread_ctx;
// --- real thread model (RT_THREADS=1): pthread per ExCreateThread, per-thread guest
// stack/PCR/TLS block (same layout the harness builds for the main thread).
// Handles: 0xE000+idx. CREATE_SUSPENDED honored via a resume flag; NtResumeThread sets it.
#ifndef _WIN32
#include <pthread.h>
#endif
static bool rt_threads_on(){ static bool on=getenv("RT_THREADS")!=nullptr; return on; }
struct RtThread { std::atomic<int> resumed{0}; uint32_t xapi=0,entry=0,tctx=0; uint8_t* base=nullptr; bool used=false;
                  void* hth=nullptr; /* host thread HANDLE, kept for KeSetBasePriorityThread */ };
// ★ CODE_REVIEW_0804 CRITICAL-2 (4th-swap hang, confirmed in futari_beta1_20260803_201252.log:
// 18 ExCreateThread vs 16 [thread] START — the last create failed silently). The table was 16
// slots NEVER recycled; 7 shell threads at boot + 2 game threads per module attach exhausted it
// at swap #4, and the failure path returned 0xC0000001 while writing NEITHER out-param — the
// guest read stack garbage as a thread handle (the XMsgInProcessCall stub class, on the thread
// path). Now: slots are freed when the guest thread exits (rt_thread_main return or
// ExTerminateThread), alloc/free are mutex-serialised, the failure path writes 0 to both
// out-params and screams, and the table is 32 for stale-handle-alias margin. Handle range
// 0xE000+idx and tid 0x30+idx follow RT_THR_MAX. RT_THREADRECYCLE=0 restores never-free.
static constexpr uint32_t RT_THR_MAX = 32;
static RtThread g_thr[RT_THR_MAX];
static std::mutex g_thr_slotmtx;
static bool rt_thr_recycle(){ static bool on=[](){ const char* e=std::getenv("RT_THREADRECYCLE"); return !(e&&e[0]=='0'&&!e[1]); }(); return on; }
static void rt_thr_free(RtThread* T, const char* who){
  if(!rt_thr_recycle()) return;
  std::lock_guard<std::mutex> l(g_thr_slotmtx);
  if(T->hth){
#ifdef _WIN32
    CloseHandle((HANDLE)T->hth);
#endif
    T->hth=nullptr;
  }
  T->xapi=T->entry=T->tctx=0; T->base=nullptr; T->resumed.store(0); T->used=false;
  (void)who;
}
static std::atomic<long> g_thr_live{0};
static thread_local RtThread* g_thr_self=nullptr;   // set at guest-thread start; ExTerminateThread keys on it
static void* rt_thread_main(void* p){
  RtThread* T=(RtThread*)p; uint8_t* base=T->base;
  g_thr_self=T;
  while(!T->resumed.load()) usleep(1000);
  const uint32_t PCR=0xAB0,TLS=0x100,TEB=0x2E0,STK=0x40000,TOT=PCR+TLS+TEB+STK;
  uint32_t tb=rt_alloc(TOT,0x1000); uint8_t* t=base+tb; std::memset(t,0,TOT);
  *(uint32_t*)t=__builtin_bswap32(tb+PCR); *(uint32_t*)(t+0x100)=__builtin_bswap32(tb+PCR+TLS); t[0x10C]=0;
  // ★ 2026-08-04 UNIQUE THREAD IDS (shot-SFX ghost root cause). KTHREAD+0x14C was hardcoded 1
  // for EVERY thread, so the guest's GetCurrentThreadId (reads PCR->0x100->0x14C, e.g. shell
  // FUN_8208DA10) returned 1 everywhere. XACT's apartment check (FUN_82137B50: currentTid ==
  // engineTid at state+0x14) therefore passed on ALL threads and every caller took the
  // mutate-engine-state-directly path concurrently — retail 360 XACT's thread safety IS that
  // identity check (its critsec helpers are compiled empty). Result: cross-thread use-after-
  // free stomps on wave descriptors mid-submit; a pool free node (owner,flink,blink) lands on
  // the loop triple, PrepareNextPacket sees loopCount=0x36B2xx and a 75ms one-shot grain loops
  // 3.5M times = the ringing ghost voices = the +16dB shot SFX. A real 360 kernel NEVER issues
  // duplicate thread ids; unique ids are register-true. Use 0x30+idx to MATCH the tid_out that
  // ExCreateThread already returns for this slot (guest may compare the two). Main thread
  // keeps id 1 (harness.cpp). RT_TIDUNIQ=0 reverts to the old all-threads-id-1 behaviour.
  static const bool tiduniq = [](){ const char* e=std::getenv("RT_TIDUNIQ"); return !(e&&e[0]=='0'&&!e[1]); }();
  uint32_t tid = tiduniq ? (0x30u + (uint32_t)(T - g_thr)) : 1u;
  *(uint32_t*)(t+PCR+0x10)=0xFFFFFFFF; *(uint32_t*)(t+PCR+TLS+0x14C)=__builtin_bswap32(tid);
  PPCContext c{}; c.r1.u64=tb+PCR+TLS+TEB+STK; c.r13.u64=tb; c.fpscr.loadFromHost();
  uint32_t start = T->xapi ? T->xapi : T->entry;
  if(T->xapi){ c.r3.u64=T->entry; c.r4.u64=T->tctx; } else { c.r3.u64=T->tctx; }
  std::fprintf(stderr,"  [thread] START start=0x%X entry=0x%X ctx=0x%X (host tid live=%ld)\n",start,T->entry,T->tctx,g_thr_live.fetch_add(1)+1);
  // Cross-module dispatch: start may be a GAME (0x88070000+) or SHELL (0x82060000+)
  // range address in the merged binary. rt_indirect_call() (declared in rt_indirect.h,
  // force-included ahead of this TU) range-dispatches both (shell table null-guarded so
  // standalone futari_mode still works); use it here instead of the game-only
  // PPC_CODE_BASE table lookup.
  // L3/E5: was three terms — PPC_CODE_BASE/SIZE (this TU's own module, i.e. whichever tree it
  // was compiled from), then a HARDCODED reco_normal game range 0x88070000+0x1DEEB0, then the
  // shell range.  The first two are the same range and the hardcoded one is the SHORTER of the
  // two on the abn arm (0x1DEEB0 < 0x1DEEB8), so it was already dead in both builds; merging
  // them into one descriptor-driven test is exactly behaviour-preserving today and is what
  // lets a SWAPPED-IN module's ExCreateThread entry point still be judged resolvable (plan
  // §3.6 (iv): this site is absent from both research reports and is on the boot path of every
  // module after the first — a wrong bound here means the module's game threads never start).
  const FutariModuleDesc& d = *futari_desc();
  bool resolved = (start>=d.code_base && start<d.code_base+d.code_size)
    || (start>=FUTARI_SHELL_CODE_BASE && start<FUTARI_SHELL_CODE_BASE+FUTARI_SHELL_CODE_SIZE);
  if(resolved){
    rt_indirect_call(c, base, start);
  } else {
    std::fprintf(stderr,"  [thread] START-UNRESOLVED start=0x%X\n",start);
  }
  g_thr_live.fetch_add(-1);
  std::fprintf(stderr,"  [thread] EXIT entry=0x%X r3=0x%llX\n",T->entry,(unsigned long long)c.r3.u64);
  rt_thr_free(T,"exit");   // CODE_REVIEW_0804: recycle the slot (was never freed -> swap-#4 exhaustion)
  return nullptr;
}
#ifdef _WIN32
static unsigned __stdcall rt_thread_trampoline(void* p){ rt_thread_main(p); return 0; }
#endif
PPC_FUNC_IMPL(__imp__ExCreateThread){ LOGN("ExCreateThread");
  std::fprintf(stderr,"  [thread] ExCreateThread stack=0x%X xapi=0x%X entry=0x%X ctx=0x%X flags=0x%X\n",
    ctx.r4.u32,ctx.r6.u32,ctx.r7.u32,ctx.r8.u32,ctx.r9.u32);
  g_thread_xapi=ctx.r6.u32; g_thread_entry=ctx.r7.u32; g_thread_ctx=ctx.r8.u32;
  if(!rt_threads_on()){
    if(ctx.r3.u32) *(uint32_t*)(base+ctx.r3.u32)=__builtin_bswap32(0x1234);
    if(ctx.r5.u32) *(uint32_t*)(base+ctx.r5.u32)=__builtin_bswap32(0x22);
    ctx.r3.u32=0; return;
  }
  int idx=-1;
  { std::lock_guard<std::mutex> l(g_thr_slotmtx);
    for(uint32_t i=0;i<RT_THR_MAX;i++) if(!g_thr[i].used){idx=(int)i;break;}
    if(idx>=0) g_thr[idx].used=true; }   // claim under the lock; fields filled below
  if(idx<0){
    // CODE_REVIEW_0804: die loud AND write the out-params — a status the guest may not check
    // plus stale stack out-params is how the 4th-swap hang stayed invisible.
    std::fprintf(stderr,"  [thread] ExCreateThread FAILED — table full (%u slots, live=%ld)\n",RT_THR_MAX,g_thr_live.load());
    if(ctx.r3.u32) *(uint32_t*)(base+ctx.r3.u32)=0;
    if(ctx.r5.u32) *(uint32_t*)(base+ctx.r5.u32)=0;
    ctx.r3.u32=0xC0000001u; return; }
  RtThread* T=&g_thr[idx]; T->xapi=ctx.r6.u32; T->entry=ctx.r7.u32; T->tctx=ctx.r8.u32; T->base=base;
  if(!(ctx.r9.u32&1)) T->resumed.store(1);   // not suspended -> run now
#ifdef _WIN32
  // Handle KEPT (was CloseHandle'd): KeSetBasePriorityThread below needs a live target. Closed
  // in rt_thr_free when the thread exits (slots recycle since CODE_REVIEW_0804).
  uintptr_t th=_beginthreadex(nullptr,0,rt_thread_trampoline,T,0,nullptr); T->hth=(void*)th;
#else
  pthread_t th; pthread_attr_t at; pthread_attr_init(&at); pthread_attr_setdetachstate(&at,PTHREAD_CREATE_DETACHED);
  pthread_create(&th,&at,rt_thread_main,T);
#endif
  if(ctx.r3.u32) *(uint32_t*)(base+ctx.r3.u32)=__builtin_bswap32(0xE000u+idx);
  if(ctx.r5.u32) *(uint32_t*)(base+ctx.r5.u32)=__builtin_bswap32(0x30+idx);
  ctx.r3.u32=0; }
PPC_FUNC_IMPL(__imp__NtResumeThread){ LOGN("NtResumeThread");
  uint32_t h=ctx.r3.u32;
  if(h>=0xE000u&&h<0xE000u+RT_THR_MAX){ g_thr[h-0xE000u].resumed.store(1); std::fprintf(stderr,"  [thread] resume h=0x%X\n",h); }
  if(ctx.r4.u32) *(uint32_t*)(base+ctx.r4.u32)=__builtin_bswap32(1);
  ctx.r3.u32=0; (void)base; }
// ★ 2026-08-02 REAL THREAD PRIORITIES (user: SFX still cause slowdown; SDL sink proved the
// device side clean — the ring drains PRODUCER-side under fire). On hardware the title raises
// its audio-critical threads through this call; it was a return-0 stub in BOTH modules — the
// same "return SUCCESS, do nothing" class as the XMsgInProcessCall music bug — so every guest
// thread ran at host-normal priority and the mixer lost scheduling races against the render
// worker exactly when firing got heavy. The reference SDK implements thread priorities in its
// kernel layer; parity here is register-true. This def shadows the stubs.cpp no-op by link
// order (game_rt.o < game_stubs.o, /FORCE:MULTIPLE first-def-wins — the ExCreateThread pattern).
// r3 = thread token: our 0xE000+idx handle resolves through g_thr; anything else (KTHREAD
// pointers are opaque to us — ObReferenceObjectByHandle writes nothing) is treated as the
// KeGetCurrentThread self-raise idiom and applied to the CALLING thread, logged. r4 = signed
// increment relative to base 8. Returns the previous base (constant 8). RT_NOPRIO=1 reverts.
#ifdef _WIN32
static int rt_prio_map(int inc){
  if(inc>=16) return THREAD_PRIORITY_TIME_CRITICAL;
  if(inc>=2)  return THREAD_PRIORITY_HIGHEST;
  if(inc==1)  return THREAD_PRIORITY_ABOVE_NORMAL;
  if(inc==0)  return THREAD_PRIORITY_NORMAL;
  if(inc==-1) return THREAD_PRIORITY_BELOW_NORMAL;
  return THREAD_PRIORITY_LOWEST;
}
#endif
PPC_FUNC_IMPL(__imp__KeSetBasePriorityThread){ LOGN("KeSetBasePriorityThread");
  static bool off = getenv("RT_NOPRIO")!=nullptr;
  uint32_t h=ctx.r3.u32; int inc=(int)(int32_t)ctx.r4.u32;
  ctx.r3.u64=8;
  if(off){ (void)base; return; }
#ifdef _WIN32
  HANDLE t=nullptr; const char* route="current-thread";
  if(h>=0xE000u && h<0xE000u+RT_THR_MAX && g_thr[h-0xE000u].hth){ t=(HANDLE)g_thr[h-0xE000u].hth; route="handle"; }
  BOOL ok=SetThreadPriority(t?t:GetCurrentThread(), rt_prio_map(inc));
  static std::atomic<long> pn{0}; long i=pn.fetch_add(1)+1;
  if(i<=8) std::fprintf(stderr,"  [prio] KeSetBasePriorityThread(0x%X, %+d) -> %s host=%d ok=%d (RT_NOPRIO=1 reverts)\n",
                        h,inc,route,rt_prio_map(inc),(int)ok);
#endif
  (void)base; }
// Real ExTerminateThread: actually end the calling host thread. The old return-0 stub let the
// guest's terminate call fall through -> the caller loops re-calling it forever (35k-call storm,
// px_runH). Guest threads (rt_thread_main) get g_thr_self; on those, log identity + pthread_exit.
// On a non-guest thread (harness main) just return 0 like before.
PPC_FUNC_IMPL(__imp__ExTerminateThread){ LOGN("ExTerminateThread");
  RtThread* T=g_thr_self;
  if(T){
    std::fprintf(stderr,"  [thread] TERMINATE entry=0x%X ctx=0x%X exitcode=0x%X (thread-exit)\n",T->entry,T->tctx,ctx.r3.u32);
    g_thr_live.fetch_add(-1);
    rt_thr_free(T,"terminate");   // CODE_REVIEW_0804: _endthreadex skips rt_thread_main's tail free
#ifdef _WIN32
    _endthreadex(0);
#else
    pthread_exit(nullptr);
#endif
  }
  std::fprintf(stderr,"  [thread] TERMINATE on non-guest thread r3=0x%X (ignored)\n",ctx.r3.u32);
  ctx.r3.u64=0; (void)base; }
PPC_FUNC_IMPL(__imp__KeDelayExecutionThread){ LOGN("KeDelayExecutionThread");
  // r5 = &interval (be64, negative = relative 100ns units)
  long long us=1000; bool haveIv=false;
  if(ctx.r5.u32){ long long v=(long long)__builtin_bswap64(*(uint64_t*)(base+ctx.r5.u32)); haveIv=true; if(v<0) us=(-v)/10; else if(v==0) us=0; }
  // flicker-truth fix #2b (wf_e3c67137): a ZERO interval is the guest's "yield" — historically it
  // fell into the 1000us DEFAULT sleep, turning tight producer/consumer handoffs into ms stalls.
  // Yield for 0. RT_REALWAIT=0 restores the historical 1000us for v==0 exactly (review wf_ea22499a
  // #3: the first cut's opt-out gave 100us — not the shipped behavior, useless for A/B truth).
  if(haveIv && us==0){ if(realwait()){ std::this_thread::yield(); ctx.r3.u32=0; return; } us=1000; }
  if(us<100) us=100; if(us>50000) us=50000;
  usleep((useconds_t)us);
  ctx.r3.u32=0; }
// --- misc ---
PPC_FUNC_IMPL(__imp__KeGetCurrentProcessType){ LOGN("KeGetCurrentProcessType"); ctx.r3.u32=1; (void)base; }
PPC_FUNC_IMPL(__imp__RtlInitAnsiString){ LOGN("RtlInitAnsiString");
  uint32_t dst=ctx.r3.u32, src=ctx.r4.u32; uint16_t len=0; if(src){const char*s=(const char*)(base+src); while(s[len]&&len<0xFFFE)++len;}
  if(dst){ *(uint16_t*)(base+dst)=__builtin_bswap16(len); *(uint16_t*)(base+dst+2)=__builtin_bswap16(src?len+1:0); *(uint32_t*)(base+dst+4)=__builtin_bswap32(src);} (void)base; }

// ── RT_INDCENSUS (default OFF): the INDIRECT-TARGET LIVENESS CENSUS ──────────────────────────
// rt_indirect.h routes EVERY PPC_CALL_INDIRECT_FUNC in BOTH trees through rt_indirect_call, and
// the module DLLs carry no copy of this TU (build_win_dll.sh links no game_rt — the DLL imports
// this one), so a single bitmap here sees every callback dispatch in the process: shell + game,
// host thread + workers.  That makes it the liveness oracle the decomp campaign has been missing.
// Instead of one placement canary per drafted TU — one body at a time, and exposed to the
// PPC_FUNC clone-bypass landmine — ONE drive answers "which of the 5,438 reco_normal / 9,149
// shell bodies actually executed indirectly", which is exactly the question the objAction leg's
// dormancy finding (NOTE_campaign_decomp, "10 OF THE 11 BODIES NEVER EXECUTE") left open.
//
// Two rules this instrument obeys, both learned the hard way:
//   * POSITIVE CONTROL IS STRUCTURAL — the census cannot print zero for families we have already
//     watched run, so every dump carries the live-family counts next to the region under test.
//     A dark-run zero is only evidence while the live counts are non-zero in the SAME dump.
//   * The file is REWRITTEN IN PLACE every RT_INDCENSUS_EVERY dispatches, because drives end in
//     Stop-Process -Force: an atexit dump would never fire and the artifact would always be
//     missing exactly when the drive did the most interesting thing.
// Cost when off: one relaxed load of a function-local static.  When on: a bit test per dispatch.
namespace {
constexpr uint32_t IC_GAME = 0x88000000u, IC_SHELL = 0x82000000u, IC_SPAN = 0x00300000u;
constexpr uint32_t IC_WORDS = IC_SPAN / 4 / 32;          // bits at 4-byte granularity, per image
constexpr uint32_t IC_DARK_LO = 0x88170000u, IC_DARK_HI = 0x88250000u;   // the objAction dark run

inline bool ic_on(){ static const bool on = std::getenv("RT_INDCENSUS") != nullptr; return on; }
inline std::atomic<uint32_t>* ic_bits(){
  static std::atomic<uint32_t>* b = new std::atomic<uint32_t>[IC_WORDS * 2]();
  return b;
}
inline void ic_note(uint32_t t){
  uint32_t idx;
  if(t>=IC_GAME && t<IC_GAME+IC_SPAN)        idx = (t-IC_GAME)>>2;
  else if(t>=IC_SHELL && t<IC_SHELL+IC_SPAN) idx = ((t-IC_SHELL)>>2) + IC_WORDS*32;
  else return;
  auto* b = ic_bits();
  const uint32_t w = idx>>5, m = 1u<<(idx&31);
  if(!(b[w].load(std::memory_order_relaxed) & m)) b[w].fetch_or(m, std::memory_order_relaxed);
}
void ic_dump(long long dispatches){
  auto* b = ic_bits();
  const char* p = std::getenv("RT_INDCENSUS_OUT");
  std::string path = p ? p : "C:/tmp/indcensus.txt";
  FILE* fp = std::fopen(path.c_str(), "w");
  unsigned nga=0, nsh=0, ndark=0;
  for(uint32_t i=0;i<IC_WORDS*2;i++){
    uint32_t v = b[i].load(std::memory_order_relaxed);
    if(!v) continue;
    for(int k=0;k<32;k++){
      if(!(v & (1u<<k))) continue;
      const uint32_t idx = i*32+k;
      const bool game = idx < IC_WORDS*32;
      const uint32_t a = game ? IC_GAME + (idx<<2) : IC_SHELL + ((idx - IC_WORDS*32)<<2);
      if(game){ nga++; if(a>=IC_DARK_LO && a<IC_DARK_HI) ndark++; } else nsh++;
      if(fp) std::fprintf(fp, "%s 0x%08X\n", game?"game":"shell", a);
    }
  }
  if(fp){ std::fprintf(fp, "# dispatches=%lld game=%u shell=%u dark=%u\n", dispatches, nga, nsh, ndark);
          std::fclose(fp); }
  // the verdict line, in the drive log itself: dark count next to its own positive control.
  // ⚠ SAY SO WHEN THE FILE DID NOT GET WRITTEN. An MSYS-style "/c/tmp/..." path (the drive
  // scripts run under Git Bash) is not a Windows path: fopen fails, and the first version of this
  // printed the same confident "-> <path>" line anyway, so a whole run looked banked and wasn't.
  std::fprintf(stderr, "[indcensus] dispatches=%lld distinct game=%u shell=%u  DARK(0x8817-0x8824)=%u  -> %s%s\n",
               dispatches, nga, nsh, ndark, path.c_str(),
               fp ? "" : "   ** NOT WRITTEN (fopen failed — Windows-style path required, e.g. C:/tmp/...)");
  std::fflush(stderr);
}

// ── RT_A3EMIT state (see the probe in rt_indirect_call for the full rationale) ───────────────
// Two spellings of ONE body (arcade 0x881A1428 / abn twin 0x881A1430) x four watched cells.
// Counters are per (spelling, cell) so the verdict cannot be assembled by hand from a log tail:
// the file below IS the verdict, and it is rewritten in place because drives end in
// Stop-Process -Force and an atexit dump would never fire (ic_dump's own lesson, w40).
struct A3EmitCell { const char* name; uint32_t addr; };
constexpr A3EmitCell A3E_CELLS[4] = {
  { "G_EMITS_ARC 0x887AD164", 0x887AD164u },   // the UNSHIFTED cell
  { "G_EMITS_ABN 0x887AD1C4", 0x887AD1C4u },   // the +0x60-SHIFTED cell
  { "SCENEPTR_ARC 0x887AD130", 0x887AD130u },  // sentinel: the exclusion doc's blast radius
  { "SCENEPTR_ABN 0x887AD190", 0x887AD190u },  // sentinel, abn spelling
};
inline bool a3e_on(){ static const bool on = std::getenv("RT_A3EMIT") != nullptr; return on; }
struct A3EmitStats {
  std::atomic<long long> dispatches{0};
  std::atomic<long long> changed[4]{};     // # dispatches on which this cell changed
  std::atomic<long long> delta[4]{};       // summed (post-pre) as signed
  std::atomic<uint32_t>  last[4]{};
};
inline A3EmitStats* a3e_stats(){ static A3EmitStats* s = new A3EmitStats[2](); return s; }  // [0]=arc [1]=abn
void a3e_dump(){
  auto* st = a3e_stats();
  const char* p = std::getenv("RT_A3EMIT_OUT");
  std::string path = p ? p : "C:/tmp/a3emit.txt";
  FILE* fp = std::fopen(path.c_str(), "w");
  if(fp){
    std::fprintf(fp, "# RT_A3EMIT r23-w43 -- the +0x60-shift falsifier probe (packet g1)\n");
    std::fprintf(fp, "# spelling  dispatches | per cell: changed_count  summed_delta  last_value\n");
    for(int s=0;s<2;s++){
      const char* sp = s? "ABN_0x881A1430" : "ARC_0x881A1428";
      std::fprintf(fp, "%s dispatches=%lld\n", sp, st[s].dispatches.load(std::memory_order_relaxed));
      for(int c=0;c<4;c++)
        std::fprintf(fp, "  %-24s changed=%lld delta=%lld last=0x%08X\n", A3E_CELLS[c].name,
                     st[s].changed[c].load(std::memory_order_relaxed),
                     st[s].delta[c].load(std::memory_order_relaxed),
                     st[s].last[c].load(std::memory_order_relaxed));
    }
    // The scoring lines, spelled so a grep cannot mis-read them.
    std::fprintf(fp, "A3EMIT_ARC disp=%lld nARC=%lld nABN=%lld nSCN_ARC=%lld nSCN_ABN=%lld\n",
      st[0].dispatches.load(), st[0].changed[0].load(), st[0].changed[1].load(),
      st[0].changed[2].load(), st[0].changed[3].load());
    std::fprintf(fp, "A3EMIT_ABN disp=%lld nARC=%lld nABN=%lld nSCN_ARC=%lld nSCN_ABN=%lld\n",
      st[1].dispatches.load(), st[1].changed[0].load(), st[1].changed[1].load(),
      st[1].changed[2].load(), st[1].changed[3].load());
    std::fclose(fp);
  }
  std::fprintf(stderr, "[a3emit] arc disp=%lld nARC=%lld nABN=%lld | abn disp=%lld nARC=%lld nABN=%lld -> %s%s\n",
    st[0].dispatches.load(), st[0].changed[0].load(), st[0].changed[1].load(),
    st[1].dispatches.load(), st[1].changed[0].load(), st[1].changed[1].load(),
    path.c_str(), fp ? "" : "   ** NOT WRITTEN (fopen failed -- Windows-style path required)");
  std::fflush(stderr);
}
void a3e_note(uint32_t target, uint32_t A0,uint32_t A1, uint32_t B0,uint32_t B1,
              uint32_t C0,uint32_t C1, uint32_t D0,uint32_t D1){
  const int s = (target==0x881A1430u) ? 1 : 0;
  auto* st = a3e_stats();
  const long long n = st[s].dispatches.fetch_add(1, std::memory_order_relaxed) + 1;
  const uint32_t pre[4]={A0,B0,C0,D0}, post[4]={A1,B1,C1,D1};
  bool any=false;
  for(int c=0;c<4;c++){
    st[s].last[c].store(post[c], std::memory_order_relaxed);
    if(pre[c]!=post[c]){
      any=true;
      st[s].changed[c].fetch_add(1, std::memory_order_relaxed);
      st[s].delta[c].fetch_add((long long)(int32_t)(post[c]-pre[c]), std::memory_order_relaxed);
    }
  }
  // First 5 dispatches per spelling verbatim, then every 500th: a rare arm cannot be crowded
  // out by a common one (the w35 per-pose-counter lesson, applied to spellings).
  // A SENTINEL change (cells 2/3 = the scene pointer) is ALWAYS printed -- it is the corruption
  // signature and must never be sampled away.
  const bool sentinel = (C0!=C1) || (D0!=D1);
  if(n<=5 || (n%500)==0 || sentinel){
    std::fprintf(stderr,
      "[a3emit] #%lld tgt=0x%08X(%s) ARC 0x%08X->0x%08X%s  ABN 0x%08X->0x%08X%s"
      "  SCN_ARC 0x%08X->0x%08X%s  SCN_ABN 0x%08X->0x%08X%s%s\n",
      n, target, s? "ABN-twin":"ARC",
      A0,A1, (A0!=A1)?" *CHANGED*":"", B0,B1, (B0!=B1)?" *CHANGED*":"",
      C0,C1, (C0!=C1)?" **SENTINEL**":"", D0,D1, (D0!=D1)?" **SENTINEL**":"",
      any?"":"  (no watched cell moved)");
    std::fflush(stderr);
  }
  // ⚠ DUMP ON THE FIRST FEW TOO, not only every 200th.  A leg on which the family dispatches
  // only a handful of times is exactly the interesting one, and an every-200th dump would
  // leave it with NO FILE — the failure mode ic_dump's own comment warns about, one level up.
  if(n<=5 || (n%200)==0 || sentinel) a3e_dump();
}
}  // namespace

// Checked indirect call (see rt_indirect.h): log + skip unmapped targets, r3=0.
// Cross-module dispatch (futari_merged / RT_SHELL probe): the flat guest lookup-table
// region normally reserved for one module's own code range is, in the merged binary,
// ALSO populated (by harness.cpp under RT_SHELL) for the shell module's code range at a
// second, disjoint host offset. These bounds are HARDCODED (not the PPC_CODE_BASE/SIZE
// macros, which resolve per-TU to whichever module that TU was compiled as) so this one
// function is module-agnostic and works whether compiled into the game or shell object.
extern "C" void rt_indirect_call(PPCContext& ctx, uint8_t* base, uint32_t target){
  PPCFunc* f=nullptr;
  // RT_STUBREG experiment (task 11): the game's resource-kind registration loop
  // (sub_88090360) dispatches handler->vtable[0](r3=handler, r4=descriptor) -> 16-bit id at
  // lr=0x880903F8. The 3 handlers are null (the shell resource-kind managers at CB248
  // singleton S+12 are never installed by our bypass), so ids come back garbage and nothing
  // renders. This stub hands out valid unique ids to TEST whether valid-ids-alone lets the
  // game proceed to draw (via its msg-9 shell callbacks) or whether real shell resource
  // storage is required for pixels -- and logs the first descriptors being registered (RE).
  if((uint32_t)ctx.lr==0x880903F8u && getenv("RT_STUBREG")){
    static std::atomic<unsigned> g_stubid{0};
    static std::atomic<long> g_stublog{0};
    unsigned myid = (g_stubid.fetch_add(1)+1) & 0x7FFF;  // valid 16-bit id, != 0xFFFF
    long ln = g_stublog.fetch_add(1);
    if(ln<24){
      uint32_t d=ctx.r4.u32;
      auto rd=[&](uint32_t a){ return (a && a<0xF0000000u)? __builtin_bswap32(*(uint32_t*)(base+a)) : 0u; };
      std::fprintf(stderr,"[stubreg] #%ld this=0x%X desc=0x%X [%08x %08x %08x %08x] -> id=%u\n",
        ln, ctx.r3.u32, d, rd(d), rd(d+4), rd(d+8), rd(d+12), myid);
    }
    ctx.r3.u32 = myid;
    return;
  }
  if(target==0x8204FDB8u){  // recurring UNMAPPED game->shell vtable[0] call; dump this/vtable to diagnose
    static long f8=0;
    if(f8++<3){
      uint32_t o=ctx.r3.u32;
      uint32_t vt=(o && o<0xF0000000u)? __builtin_bswap32(*(uint32_t*)(base+o)) : 0;
      uint32_t s0=(vt && vt<0xF0000000u)? __builtin_bswap32(*(uint32_t*)(base+vt)) : 0;
      std::fprintf(stderr,"[f8] call 0x8204FDB8 this=0x%X vtable=0x%X vt[0]=0x%X lr=0x%X\n",o,vt,s0,(uint32_t)ctx.lr);
    }
  }
  // L3/E5 (plan §3.6): the two GAME branches this used to have — one on the compiled TU's own
  // PPC_CODE_* macros, one on hardcoded reco_normal literals — were the same range (and the
  // hardcoded one was the shorter of the two on the abn arm, hence dead in both builds).  One
  // descriptor-driven branch replaces both.  At L4 futari_desc() becomes a relaxed atomic load
  // of the bound module and this function needs no further edit; the read is hoisted into a
  // local exactly as §3.6 requires (the function already does an lr compare and env-cached
  // checks on this path, so one load is noise).
  const FutariModuleDesc& d = *futari_desc();
  if(target>=d.code_base && target<d.code_base+d.code_size){
    // GAME table region: base + image_base + image_size + (t - code_base)*2
    f=*(PPCFunc**)(base+(uint64_t)d.table_base+(uint64_t)(target-d.code_base)*2);
  } else if(target>=FUTARI_SHELL_CODE_BASE && target<FUTARI_SHELL_CODE_BASE+FUTARI_SHELL_CODE_SIZE){
    // SHELL table region: base + 0x82000000 + 0x2B0000 + (t-0x82060000)*2.  Never per-module.
    f=*(PPCFunc**)(base+FUTARI_SHELL_TABLE_BASE+(uint64_t)(target-FUTARI_SHELL_CODE_BASE)*2);
    static long shellhits=0;
    if(f && shellhits++<10) std::fprintf(stderr,"[indirect] SHELL target=0x%08X -> dispatched\n",target);
  }
  if(f){
    if(ic_on()){                       // RT_INDCENSUS: note the target that is about to run
      ic_note(target);
      static std::atomic<long long> n{0};
      const long long c = n.fetch_add(1, std::memory_order_relaxed) + 1;
      static const long long every = [] {
        const char* e = std::getenv("RT_INDCENSUS_EVERY");
        long long v = e ? std::atoll(e) : 0; return v > 0 ? v : 500000LL;
      }();
      if((c % every) == 0) ic_dump(c);
    }
    // r26-clobber hunt: the indirect call at ppc_recomp.4.cpp:15012 (sub_8808FDF8, ret
    // lr=0x8808FEE4) is the prime suspect for clobbering non-volatile r26 (game-main fn ptr
    // 0x88168D48) on the real-.data path. Name its target + report if r26 isn't preserved.
    if((uint32_t)ctx.lr==0x8808FEE4u){
      uint32_t pre=ctx.r26.u32; f(ctx,base);
      std::fprintf(stderr,"[clob] indirect@15012 target=0x%08X r26 0x%X -> 0x%X%s\n",
        target,pre,ctx.r26.u32,(pre==0x88168D48u&&ctx.r26.u32!=pre)?"  <<< CLOBBER":"");
      return;
    }
    // ── RT_A3EMIT (default OFF): THE A3POSE +0x60-SHIFT FALSIFIER PROBE ───────────────────────
    // r23-w43.  Aims packet falsifier g1, open since w35 and UNEXERCISED in w39/w40/w41:
    //   "the abn arm reads the +0x60-shifted tables correctly."
    // Actor3Pose_Draw (0x881A1428) WRITES the module global G_EMITS at 11 of its 38 emit sites.
    // On reco_normal that cell is 0x887AD164; under reco_abnormal every module datum shifts
    // +0x60, so the body running there must write 0x887AD1C4 instead.  0x887AD1C4 is inside the
    // live 0x887A neighbourhood (scene ptr 0x887AD130, slowdown accumulator 0x887AD168), so a
    // wrong shift is CORRUPTION, not a wrong read (ABN_EXCLUSION_881A1428_w34.txt).
    //
    // ★ WHY THE PROBE IS HERE AND NOT IN THE TU.  decomp/game/actor3pose_draw.cpp is EXCLUDED
    //   from the abn DLL (build_win_dll.sh:334), so its [a3pose] tap is silent on the abn arm BY
    //   CONSTRUCTION and cannot observe this at all.  rt.cpp is HOST-EXE code that both module
    //   DLLs import, and w42 established statically that this family has ZERO direct bl/b sites
    //   (addrsite_scan, 5 built-in controls + region-local non-vacuity) — so EVERY invocation on
    //   EITHER arm passes through here.  One code path, both arms, no arm-specific branch.
    //   It also touches no decomp TU, so no STANDARD §5.5 re-certification is engaged.
    //
    // ★ TWIN SPELLINGS.  out_reco_abn/abn_symbol_map.h renames +8 (the abn image is 8 bytes
    //   longer), so the SAME body is guest 0x881A1428 on arcade and 0x881A1430 on abn.  w40 and
    //   w41 both grepped only the arcade spelling in an abn census and read the resulting zero
    //   as a two-window negative; w42 withdrew it.  BOTH spellings are matched here, and BOTH
    //   candidate data cells are sampled on BOTH arms, so the reading cannot depend on knowing
    //   which arm is live.
    //
    // THE OBSERVABLE is WHICH CELL CHANGES across one dispatch — not the sign or size of the
    // delta.  G_EMITS is seeded-and-stored, not read-modify-written per site, so a delta may
    // legitimately be 0 when nothing emitted.  Values and deltas are logged too, so the record
    // survives a wrong guess about the arithmetic.
    //   n_ARC > 0 on an abn arm  => the UNSHIFTED write => falsifier FAILS (a real defect).
    //   n_ABN > 0 with n_ARC == 0 on an abn arm => shifted correctly => falsifier DISCHARGED.
    //   scene-pointer sentinels changing across this body at all => corruption, reported loudly.
    // Cost when off: one relaxed load of a function-local static, on the dispatch path only.
    if(a3e_on() && (target==0x881A1428u || target==0x881A1430u)){
      auto rd=[&](uint32_t a){ return __builtin_bswap32(*(uint32_t*)(base+a)); };
      const uint32_t A0=rd(0x887AD164u), B0=rd(0x887AD1C4u), C0=rd(0x887AD130u), D0=rd(0x887AD190u);
      f(ctx,base);
      const uint32_t A1=rd(0x887AD164u), B1=rd(0x887AD1C4u), C1=rd(0x887AD130u), D1=rd(0x887AD190u);
      a3e_note(target, A0,A1, B0,B1, C0,C1, D0,D1);
      return;
    }
    // RT_WATCHS: software watchpoint on the CB248 singleton (S=*(0x821F857C)) fields S+0
    // (engine-root install), S+16/S+0x30/S+0x50 (the 3 render-kind-handler ptr slots). Polls
    // after each indirect call; logs the just-called target+lr the moment a slot first flips
    // 0->nonzero. S+0 DOES flip in our bypass (dispatcher builds the engine root) so this
    // locates the resource/engine subsystem; S+16/+30/+50 do NOT flip yet (the factory that
    // fills them never runs) -- if driving more mode-enter makes them flip, this names the fn.
    if(getenv("RT_WATCHS")){
      static uint32_t s0s=0,s16s=0,s30s=0,s50s=0;
      uint32_t S = __builtin_bswap32(*(uint32_t*)(base+0x821F857Cu));
      f(ctx,base);
      if(S && S<0xF0000000u){
        auto g=[&](uint32_t o){ return __builtin_bswap32(*(uint32_t*)(base+S+o)); };
        uint32_t v0=g(0),v16=g(16),v30=g(0x30),v50=g(0x50);
        if(v0&&!s0s){s0s=v0;std::fprintf(stderr,"[watchS] S+0   =0x%X  after tgt=0x%08X lr=0x%08X\n",v0,target,(uint32_t)ctx.lr);}
        if(v16&&!s16s){s16s=v16;std::fprintf(stderr,"[watchS] S+16  =0x%X  after tgt=0x%08X lr=0x%08X\n",v16,target,(uint32_t)ctx.lr);}
        if(v30&&!s30s){s30s=v30;std::fprintf(stderr,"[watchS] S+0x30=0x%X  after tgt=0x%08X lr=0x%08X\n",v30,target,(uint32_t)ctx.lr);}
        if(v50&&!s50s){s50s=v50;std::fprintf(stderr,"[watchS] S+0x50=0x%X  after tgt=0x%08X lr=0x%08X\n",v50,target,(uint32_t)ctx.lr);}
      }
      return;
    }
    f(ctx,base); return;
  }
  static long miss=0;
  if(miss++<40) std::fprintf(stderr,"[indirect] UNMAPPED guest target=0x%08X (lr=0x%08X) -> skipped, r3=0\n",target,(uint32_t)ctx.lr);
  ctx.r3.u64=0;
}

// futari_merged only: the shell/gen tree's OWN generated ppc_recomp_shared.h independently
// hardcodes a legacy indirect-call shim (`#define PPC_CALL_INDIRECT_FUNC(x) rt_indirect((x),
// ctx, base)`, predating this task) which wins over rt_indirect.h's #define once a shell TU's
// own `#include "ppc_recomp_shared.h"` runs (see rt_indirect.h for why). Rather than hand-edit
// the generated shell header, satisfy that legacy call convention directly: same dispatch,
// different argument order/signature.
extern "C" void rt_indirect(uint32_t target, PPCContext& ctx, uint8_t* base){
  rt_indirect_call(ctx, base, target);
}

// --- CRT_INIT diagnostics MOVED (DLL plan L1/E2, 2026-07-30): the 5 [crt] game hooks
// (sub_88083920/88070E30/88083848/88083768/88070318, incl. the boot-critical _initterm_e
// replacement) now live in decomp/game/crt_hooks.cpp — game-module-side code, linked FIRST. ---

// ================= file I/O backend: serve game assets from host FS =================
// ABI ground truth: rexglue src/kernel/xboxkrnl/xboxkrnl_io.cpp (+xio.h structs).
// RT_GAME_ROOT overrides the asset root. Handles are 0xF100+idx into g_files.
#include <cstdlib>
#include <cstring>
#ifndef _WIN32
#include <strings.h>
#endif
#include <filesystem>
#include <map>
#include <string>
#include <cctype>

// [evt14] GATE (2026-08-02). This trace was UNGATED: a synchronous fprintf to stderr on every
// set/consume of the file-manager WORK event, left behind from "post-boot starvation forensics".
// Measured 2026-08-02: 22004 of 28154 stderr lines in one short playtest = 78% of all output (and
// it was still the dominant line-type in a 404k-line session). A debug trace that floods stderr
// from a hot kernel-event path is itself a plausible starvation source — i.e. the instrument is a
// candidate cause of the very symptom it was added to diagnose. Suspected in the OPEN in-game
// "audio slows down and distorts while firing" regression; see memory [[futari-shot-level-hunt]].
// Default OFF. RT_EVT14TRACE=1 restores the old behaviour.
static const bool rt_evt14_trace = (std::getenv("RT_EVT14TRACE") != nullptr);

static struct { FILE* f; unsigned long long pos; bool sync; } g_files[64];
static char g_fname[64][48];   // [RT_AUDIOCRUX] basename per handle, to trace .xwb read destinations
// ★ CODE_REVIEW_0804 E18 atomic saves: truncating content-path opens ("w+b" class) used to
// truncate the REAL file at open — a kill mid-save (which a hang invites) destroyed
// systemdata.bin. Truncating saves now write "<path>.tmp"; NtClose flushes, closes, and
// renames over the final path (filesystem::rename = MoveFileEx REPLACE semantics), so the old
// save survives any crash before the rename. Non-truncating ("r+b") opens are untouched — the
// guest expects the existing bytes readable there. RT_SAVEATOMIC=0 reverts.
static std::string g_fatomic_tmp[64], g_fatomic_fin[64];
static bool rt_saveatomic(){ static bool on=[](){ const char* e=getenv("RT_SAVEATOMIC"); return !(e&&e[0]=='0'&&!e[1]); }(); return on; }
// Last wall/wpNN.bin index the guest successfully opened (0 = none yet). Strong def here;
// vk_render reads it via a weak extern for the live-wallpaper border blit (wp-index tracking).
extern "C" { volatile int g_rt_wpindex = 0; }
static const char* rt_game_root(){ const char* e=getenv("RT_GAME_ROOT"); return e?e:"assets"; }
static uint32_t rt_h2i(uint32_t h){ return (h>=0xF100u&&h<0xF140u)?h-0xF100u:0xFFFFFFFFu; }
static void rt_guest_path(uint8_t* base, uint32_t oa, char* out, size_t cap){
  out[0]=0; if(!oa) return;
  uint32_t np=__builtin_bswap32(*(uint32_t*)(base+oa+4)); if(!np) return;
  uint16_t len=__builtin_bswap16(*(uint16_t*)(base+np));
  uint32_t sp=__builtin_bswap32(*(uint32_t*)(base+np+4));
  if(!sp||len+1>=cap) return;
  std::memcpy(out, base+sp, len); out[len]=0;
}
static FILE* rt_open_host(const char* gp, char* hp, size_t cap){
  const char* p=gp;
  if(!strncasecmp(p,"\\??\\",4)) p+=4;
  if(!strncasecmp(p,"game:",5)) p+=5;
  else if(!strncasecmp(p,"d:",2)) p+=2;
  else if(!strncasecmp(p,"\\Device\\Cdrom0",14)) p+=14;
  std::snprintf(hp,cap,"%s%s%s",rt_game_root(),(*p=='\\'||*p=='/')?"":"/",p);
  for(char* c=hp;*c;++c) if(*c=='\\') *c='/';
  return fopen(hp,"rb");
}
// ---- RT_SAVE content-root mounts: registered by the shell's XamContentCreateEx(type=1/SAVE)
// (shell/gen/stubs.cpp) via rt_content_register_root(), keyed by the guest "root_name" mount
// alias (e.g. the string passed as XamContentCreateEx's szRootName). NT file paths of the form
// "<ROOT_NAME>:\...\file" resolve here FIRST, ahead of the default RT_GAME_ROOT convention below
// — read-only asset paths are completely unaffected (this map is empty unless something actually
// registered a root, which only happens when RT_SAVE is set and a save mount succeeded).
static std::mutex g_croot_m;
static std::map<std::string,std::string> g_croots; // key: UPPERCASED "NAME:" -> host dir (no trailing slash)
extern "C" void rt_content_register_root(const char* root_name, const char* host_dir){
  if(!root_name||!*root_name||!host_dir) return;
  std::string key(root_name); for(auto& c:key) c=(char)std::toupper((unsigned char)c); key+=":";
  std::lock_guard<std::mutex> l(g_croot_m);
  g_croots[key]=host_dir;
  std::fprintf(stderr,"  [content] mount '%s' -> host '%s'\n",key.c_str(),host_dir);
}
extern "C" void rt_content_unregister_root(const char* root_name){
  if(!root_name) return;
  std::string key(root_name); for(auto& c:key) c=(char)std::toupper((unsigned char)c); key+=":";
  std::lock_guard<std::mutex> l(g_croot_m);
  if(g_croots.erase(key)) std::fprintf(stderr,"  [content] unmount '%s'\n",key.c_str());
}
// Resolve a guest path to a host path under a registered content-root mount. Returns false
// (leaving hp untouched) if gp isn't under any registered root -- callers fall through to the
// old rt_open_host()/RT_GAME_ROOT convention unchanged.
static bool rt_content_path(const char* gp, char* hp, size_t cap){
  const char* p=gp; if(!strncasecmp(p,"\\??\\",4)) p+=4;
  std::lock_guard<std::mutex> l(g_croot_m);
  for(auto& kv: g_croots){
    size_t n=kv.first.size();
    if(!strncasecmp(p,kv.first.c_str(),n)){
      std::string rel(p+n);
      for(auto& c: rel) if(c=='\\') c='/';
      if(!rel.empty() && rel[0]=='/') rel.erase(0,1);
      std::snprintf(hp,cap,"%s/%s",kv.second.c_str(),rel.c_str());
      return true;
    }
  }
  return false;
}
static void rt_w32(uint8_t* base,uint32_t a,uint32_t v){ if(a)*(uint32_t*)(base+a)=__builtin_bswap32(v); }
static void rt_w64(uint8_t* base,uint32_t a,unsigned long long v){ if(a)*(uint64_t*)(base+a)=__builtin_bswap64(v); }
static void rt_iosb(uint8_t* base,uint32_t io,uint32_t st,uint32_t info){ rt_w32(base,io,st); if(io) rt_w32(base,io+4,info); }
static unsigned long long rt_fsize(FILE* f){ long long c=ftello(f); fseeko(f,0,SEEK_END); long long s=ftello(f); fseeko(f,c,SEEK_SET); return (unsigned long long)s; }
static void rt_create_common(PPCContext& ctx, uint8_t* base, uint32_t iosb_reg, uint32_t options, uint32_t disposition, bool allow_create){
  char gp[512],hp[1024];
  rt_guest_path(base,ctx.r5.u32,gp,sizeof gp);
  int idx=-1; for(int i=0;i<64;i++) if(!g_files[i].f){idx=i;break;}
  FILE* f=nullptr; bool is_content=false, created=false;
  if(idx>=0 && gp[0]){
    is_content = rt_content_path(gp,hp,sizeof hp);
    if(is_content){
      // RT_SAVE mount: real read/write, create-on-demand per NT disposition semantics.
      std::error_code mkec; std::filesystem::create_directories(std::filesystem::path(hp).parent_path(), mkec);
      bool exists = std::filesystem::exists(hp);
      const char* mode=nullptr;
      if(allow_create){
        switch(disposition & 0xFu){
          case 1: mode = exists? "r+b" : nullptr; break;         // FILE_OPEN (must exist)
          case 2: case 0: case 4: case 5: mode = "w+b"; break;   // CREATE/SUPERSEDE/OVERWRITE[_IF]
          default: mode = exists? "r+b" : "w+b"; break;          // FILE_OPEN_IF(3) and unknown
        }
      } else {
        mode = exists? "r+b" : nullptr;                          // NtOpenFile never creates
      }
      if(mode){
        bool trunc = mode[0]=='w';
        if(trunc && rt_saveatomic()){
          char tp[1100]; std::snprintf(tp,sizeof tp,"%s.tmp",hp);
          f=fopen(tp,mode);
          if(f && idx>=0){ g_fatomic_tmp[idx]=tp; g_fatomic_fin[idx]=hp; }
        } else {
          f=fopen(hp,mode);
          if(f && idx>=0){ g_fatomic_tmp[idx].clear(); g_fatomic_fin[idx].clear(); }
        }
        created=!exists && trunc;
      }
    } else {
      f=rt_open_host(gp,hp,sizeof hp);
      if(f && idx>=0){ g_fatomic_tmp[idx].clear(); g_fatomic_fin[idx].clear(); }
    }
  }
  // rexglue parity (xboxkrnl_io.cpp NtCreateFile): a handle is SYNCHRONOUS iff create_options
  // has FILE_SYNCHRONOUS_IO_ALERT(0x10)|FILE_SYNCHRONOUS_IO_NONALERT(0x20). Non-sync handles
  // get STATUS_PENDING from NtReadFile (see there) — the shell's async streaming engine keys
  // its completion flow off that.
  bool sync = (options & 0x30u) != 0;
  static long n=0; if(n++<64) std::fprintf(stderr,"  [file] open \"%s\" opts=0x%X disp=%u content=%d sync=%d -> %s\n",gp,options,disposition,(int)is_content,(int)sync,f?hp:"MISS");
  // wp-index tracking (2026-07-20): the shell picks one of 13 border wallpapers per screen
  // (media\wall\wpNN.bin) — record the last SUCCESSFULLY opened index so the renderer's
  // pillarbox border blit (RVK_WALLBG=4) follows the guest's live selection instead of a
  // hardcoded wp01. Read by vk_render as a weak extern (g_rt_wpindex).
  if(f){
    const char* w=std::strstr(gp,"wall");
    if(w && (w[4]=='\\'||w[4]=='/') && w[5]=='w' && w[6]=='p'
         && w[7]>='0'&&w[7]<='9' && w[8]>='0'&&w[8]<='9'){
      int wi=(w[7]-'0')*10+(w[8]-'0');
      if(wi>=1&&wi<=99&&g_rt_wpindex!=wi){ g_rt_wpindex=wi; std::fprintf(stderr,"  [wpidx] wallpaper -> wp%02d\n",wi); }
    }
  }
  if(f){ g_files[idx].f=f; g_files[idx].pos=0; g_files[idx].sync=sync; std::strncpy(g_fname[idx],gp,47); g_fname[idx][47]=0; rt_w32(base,ctx.r3.u32,0xF100u+idx); rt_iosb(base,iosb_reg,0,created?2u:1u); ctx.r3.u32=0; }
  else { rt_w32(base,ctx.r3.u32,0xFFFFFFFFu); rt_iosb(base,iosb_reg,0xC0000034u,0); ctx.r3.u32=0xC0000034u; }
}
// NtCreateFile(out r3, access r4, attrs r5, iosb r6, allocsz r7, fileattrs r8, share r9,
//              disposition r10, create_options = 9th arg = stack r1+0x54 (64-bit slots, BE u32)).
PPC_FUNC_IMPL(__imp__NtCreateFile){ LOGN("NtCreateFile"); rt_create_common(ctx,base,ctx.r6.u32,PPC_LOAD_U32(ctx.r1.u32+0x54),ctx.r10.u32,true); }
// NtOpenFile(out r3, access r4, attrs r5, iosb r6, open_options r7). NtOpenFile never creates.
PPC_FUNC_IMPL(__imp__NtOpenFile){ LOGN("NtOpenFile"); rt_create_common(ctx,base,ctx.r6.u32,ctx.r7.u32,1u,false); }
PPC_FUNC_IMPL(__imp__NtReadFile){ LOGN("NtReadFile");
  uint32_t h=ctx.r3.u32, io=ctx.r7.u32, buf=ctx.r8.u32, len=ctx.r9.u32, offp=ctx.r10.u32;
  uint32_t i=rt_h2i(h);
  if(i==0xFFFFFFFFu||!g_files[i].f){ rt_iosb(base,io,0xC0000008u,0); ctx.r3.u32=0xC0000008u; return; }
  unsigned long long off = offp? __builtin_bswap64(*(uint64_t*)(base+offp)) : g_files[i].pos;
  fseeko(g_files[i].f,(long long)off,SEEK_SET);
  size_t rd=fread(base+buf,1,len,g_files[i].f);
  g_files[i].pos=off+rd;
  // x360 NtReadFile ABI: r4=Event, r5=ApcRoutine. Our read is fully synchronous, so signal the
  // async-completion Event here — the game issues an overlapped read (status=STATUS_PENDING) then
  // blocks in NtWaitForSingleObjectEx on this event (e.g. sub_88092ED8 waiting on 0x5000003C);
  // without the signal it waits forever. Only touch real event handles (>=0x50000000).
  uint32_t ev=ctx.r4.u32;
  static long n=0; if(n++<16) std::fprintf(stderr,"  [file] read h=0x%X len=0x%X off=0x%llX -> %zu evt=0x%X apc=0x%X\n",h,len,off,rd,ev,ctx.r5.u32);
  // RT_READLOG=<hexlo>[-<hexhi>] (char-card hunt): log any read landing in the guest range —
  // file reads bypass guard-page watches (kernel/host write strips PAGE_GUARD silently), so
  // this is how a watched art buffer's true filler is identified. Default hi = lo+0x20000.
  {
    static const char* rlEnv=std::getenv("RT_READLOG");
    static uint32_t rlLo=0, rlHi=0;
    if(rlEnv && !rlHi){ rlLo=(uint32_t)strtoul(rlEnv,nullptr,16);
      const char* d=std::strchr(rlEnv,'-'); rlHi=d?(uint32_t)strtoul(d+1,nullptr,16):rlLo+0x20000u; }
    if(rlEnv && buf<rlHi && buf+len>rlLo)
      std::fprintf(stderr,"[readlog] \"%s\" buf=0x%08X len=0x%X off=0x%llX rd=%zu\n",
        (i<64)?g_fname[i]:"?",buf,(unsigned)len,off,rd);
  }
  // [RT_AUDIOCRUX] .xwb read-destination trace: XACT in-memory wave-bank model has the source voice
  // point INTO the loaded .xwb at PlayRegion offset. Log WHERE the .xwb bytes land (buf) vs what the
  // wave descriptor entry+12 later computes — a base/offset mismatch => the "buffer is zeros" defect.
  if(i<64 && std::getenv("RT_AUDIOCRUX")){
    const char* nm=g_fname[i];
    if(std::strstr(nm,"xwb")||std::strstr(nm,".xw")||std::strstr(nm,"Sound")){
      // nonzero-word count of the just-read destination: proves the .xwb PCM actually landed in
      // guest memory (so the "voice ring is zeros" defect is a routing/copy gap, not a failed load).
      int nz=0; uint32_t scan=(len<0x8000u)?len:0x8000u;
      for(uint32_t b=0;b+4<=scan;b+=4){ if(*(uint32_t*)(base+buf+b)) nz++; }
      std::fprintf(stderr,"[xwbread] \"%s\" h=0x%X buf=0x%X len=0x%X off=0x%llX rd=%zu | first%uKB nonzero-words=%d\n",
        nm,h,buf,(unsigned)len,off,rd,scan/1024,nz);
    }
  }
  // RT_ASYNCIO v2 — EXACT rexglue parity (xboxkrnl_io.cpp NtReadFile, the working oracle):
  // the read is ALWAYS synchronous; the IOSB gets the FINAL status/info immediately; the
  // event is signaled immediately; and the RETURN VALUE alone is converted to STATUS_PENDING
  // — but only when the handle was opened NON-synchronous (no FILE_SYNCHRONOUS_IO_* in
  // create_options) and the read didn't hit EOF. No deferral thread (the old 1ms-deferred
  // variant raced the guest's slot setup -> half-initialized parse slots -> CRT fatal).
  static const bool asyncio = std::getenv("RT_ASYNCIO")!=nullptr;
  rt_iosb(base,io,rd?0:0xC0000011u,(uint32_t)rd);
  if(ev>=0x50000000u){ if(evcount()) rt_setev_completion(ev); else rt_setev(ev); }
  if(asyncio && !g_files[i].sync && rd){
    static long an=0; if(an++<12) std::fprintf(stderr,"  [file] read -> STATUS_PENDING (iosb+event already final) h=0x%X\n",h);
    ctx.r3.u32=0x103; return;
  }
  ctx.r3.u32=rd?0:0xC0000011u;
}
// Real host writes (RT_SAVE). Mirrors NtReadFile's structure/ABI exactly: x360 ABI is
// NtWriteFile(handle r3, Event r4, ApcRoutine r5, ApcContext r6, IoStatusBlock r7, Buffer r8,
// Length r9, ByteOffset r10) — identical shape to NtReadFile. Previously a bare no-op stub in
// out_reco/stubs.cpp; writing has never been exercised in this codebase until RT_SAVE.
PPC_FUNC_IMPL(__imp__NtWriteFile){ LOGN("NtWriteFile");
  uint32_t h=ctx.r3.u32, io=ctx.r7.u32, buf=ctx.r8.u32, len=ctx.r9.u32, offp=ctx.r10.u32;
  uint32_t i=rt_h2i(h);
  if(i==0xFFFFFFFFu||!g_files[i].f){ rt_iosb(base,io,0xC0000008u,0); ctx.r3.u32=0xC0000008u; return; }
  unsigned long long off = offp? __builtin_bswap64(*(uint64_t*)(base+offp)) : g_files[i].pos;
  fseeko(g_files[i].f,(long long)off,SEEK_SET);
  size_t wr=fwrite(base+buf,1,len,g_files[i].f);
  fflush(g_files[i].f);
  g_files[i].pos=off+wr;
  uint32_t ev=ctx.r4.u32;
  static long n=0; if(n++<32) std::fprintf(stderr,"  [file] write h=0x%X len=0x%X off=0x%llX -> %zu evt=0x%X\n",h,len,off,wr,ev);
  static const bool asyncio = std::getenv("RT_ASYNCIO")!=nullptr;
  rt_iosb(base,io,wr==len?0:0xC0000008u,(uint32_t)wr);
  if(ev>=0x50000000u){ if(evcount()) rt_setev_completion(ev); else rt_setev(ev); }
  if(asyncio && !g_files[i].sync && wr){
    static long an=0; if(an++<12) std::fprintf(stderr,"  [file] write -> STATUS_PENDING (iosb+event already final) h=0x%X\n",h);
    ctx.r3.u32=0x103; return;   // STATUS_PENDING, mirrors NtReadFile's RT_ASYNCIO v2
  }
  ctx.r3.u32=(wr==len)?0:0xC0000008u;
}
// x360 ABI: NtFlushBuffersFile(handle r3, IoStatusBlock r4). Previously a bare no-op stub.
PPC_FUNC_IMPL(__imp__NtFlushBuffersFile){ LOGN("NtFlushBuffersFile");
  uint32_t h=ctx.r3.u32, io=ctx.r4.u32;
  uint32_t i=rt_h2i(h);
  if(i==0xFFFFFFFFu||!g_files[i].f){ rt_iosb(base,io,0xC0000008u,0); ctx.r3.u32=0xC0000008u; return; }
  fflush(g_files[i].f);
  rt_iosb(base,io,0,0);
  ctx.r3.u32=0;
}
PPC_FUNC_IMPL(__imp__NtQueryInformationFile){ LOGN("NtQueryInformationFile");
  uint32_t h=ctx.r3.u32, io=ctx.r4.u32, info=ctx.r5.u32, len=ctx.r6.u32, cls=ctx.r7.u32;
  uint32_t i=rt_h2i(h);
  static long n=0; if(n++<16) std::fprintf(stderr,"  [file] queryinfo h=0x%X class=%u len=%u\n",h,cls,len);
  if(i==0xFFFFFFFFu||!g_files[i].f){ rt_iosb(base,io,0xC0000008u,0); ctx.r3.u32=0xC0000008u; return; }
  if(info&&len) std::memset(base+info,0,len);
  unsigned long long sz=rt_fsize(g_files[i].f);
  if(cls==5&&len>=24){ rt_w64(base,info,sz); rt_w64(base,info+8,sz); rt_w32(base,info+16,1); }       // standard: alloc,eof,links
  else if(cls==14&&len>=8){ rt_w64(base,info,g_files[i].pos); }                                      // position
  else if(cls==34&&len>=56){ rt_w64(base,info+32,sz); rt_w64(base,info+40,sz); rt_w32(base,info+48,0x80); } // network-open
  rt_iosb(base,io,0,len);
  ctx.r3.u32=0;
}
PPC_FUNC_IMPL(__imp__NtSetInformationFile){ LOGN("NtSetInformationFile");
  uint32_t h=ctx.r3.u32, io=ctx.r4.u32, info=ctx.r5.u32, len=ctx.r6.u32, cls=ctx.r7.u32;
  uint32_t i=rt_h2i(h);
  static long n=0; if(n++<16) std::fprintf(stderr,"  [file] setinfo h=0x%X class=%u len=%u\n",h,cls,len);
  if(i!=0xFFFFFFFFu&&g_files[i].f&&cls==14&&len>=8&&info)
    g_files[i].pos=__builtin_bswap64(*(uint64_t*)(base+info));
  rt_iosb(base,io,0,0);
  ctx.r3.u32=0;
}
// x360 ABI: NtQueryVolumeInformationFile(r3=handle, r4=&iosb, r5=&buffer, r6=length, r7=class).
// Was a success-with-unwritten-out stub -> guest streaming math read bytes_per_sector=0 and
// SIGFPE'd (divw) in the shell's async-read path (sub_82178778) once RT_ASYNCIO engaged it.
// Values = rexglue ground truth (xboxkrnl_io_info.cpp: bps 0x200 asserted, spau 0x80).
PPC_FUNC_IMPL(__imp__NtQueryVolumeInformationFile){ LOGN("NtQueryVolumeInformationFile");
  uint32_t io=ctx.r4.u32, info=ctx.r5.u32, len=ctx.r6.u32, cls=ctx.r7.u32;
  static long n=0; if(n++<8) std::fprintf(stderr,"  [file] queryvol h=0x%X class=%u len=%u\n",ctx.r3.u32,cls,len);
  if(info&&len) std::memset(base+info,0,len);
  uint32_t out=len;
  if(cls==3&&len>=24){ // FileFsSizeInformation
    rt_w64(base,info,0x100000ull);        // total_allocation_units
    rt_w64(base,info+8,0x80000ull);       // available_allocation_units
    rt_w32(base,info+16,0x80);            // sectors_per_allocation_unit
    rt_w32(base,info+20,0x200);           // bytes_per_sector
    out=24;
  } else if(cls==1&&len>=18){ out=18; }   // FileFsVolumeInformation: zeros, label_length=0
  rt_iosb(base,io,0,out);
  ctx.r3.u32=0;
}
PPC_FUNC_IMPL(__imp__NtQueryFullAttributesFile){ LOGN("NtQueryFullAttributesFile");
  char gp[512],hp[1024];
  rt_guest_path(base,ctx.r3.u32,gp,sizeof gp);
  FILE* f=nullptr;
  if(gp[0]){
    if(rt_content_path(gp,hp,sizeof hp)) f=fopen(hp,"rb");   // RT_SAVE mount: check real host state
    else f=rt_open_host(gp,hp,sizeof hp);
  }
  static long n=0; if(n++<24) std::fprintf(stderr,"  [file] attrs \"%s\" -> %s\n",gp,f?hp:"MISS");
  uint32_t info=ctx.r4.u32;
  if(info) std::memset(base+info,0,56);
  if(f){ unsigned long long sz=rt_fsize(f); rt_w64(base,info+32,sz); rt_w64(base,info+40,sz); rt_w32(base,info+48,0x80); fclose(f); ctx.r3.u32=0; }
  else ctx.r3.u32=0xC0000034u;
}
PPC_FUNC_IMPL(__imp__NtClose){ LOGN("NtClose");
  uint32_t i=rt_h2i(ctx.r3.u32);
  if(i!=0xFFFFFFFFu&&g_files[i].f){
    FILE* f=g_files[i].f;
    if(!g_fatomic_tmp[i].empty()){
      // atomic-save publish (E18): flush CRT + OS buffers, then rename over the final path.
      std::fflush(f);
#ifdef _WIN32
      _commit(_fileno(f));
#endif
      fclose(f);
      std::error_code rec;
      std::filesystem::rename(g_fatomic_tmp[i], g_fatomic_fin[i], rec);
      if(rec) std::fprintf(stderr,"  [file] ATOMIC-SAVE RENAME FAILED %s -> %s (%s) — data kept in .tmp\n",
                           g_fatomic_tmp[i].c_str(), g_fatomic_fin[i].c_str(), rec.message().c_str());
      else { static long an=0; if(an++<8) std::fprintf(stderr,"  [file] atomic save published -> %s\n", g_fatomic_fin[i].c_str()); }
      g_fatomic_tmp[i].clear(); g_fatomic_fin[i].clear();
    } else {
      fclose(f);
    }
    g_files[i].f=nullptr; g_files[i].pos=0;
  }
  ctx.r3.u32=0;
}

// ================= events + NtWaitForSingleObjectEx (game kernel) =================
// x360 ABI (xboxkrnl): NtCreateEvent(r3=&handle_out, r4=obj_attrs, r5=EVENT_TYPE
// (0=NotificationEvent/manual, 1=SynchronizationEvent/auto), r6=InitialState).
// NtSetEvent(r3=handle). NtClearEvent/NtResetEvent(r3=handle).
PPC_FUNC_IMPL(__imp__NtCreateEvent){ LOGN("NtCreateEvent");
  uint32_t hp=ctx.r3.u32, type=ctx.r5.u32, state=ctx.r6.u32;
  RtEvent*e=new RtEvent(); e->manual=(type==0); e->sig=(state!=0);
  uint32_t h=rt_add(e);
  if(hp) *(uint32_t*)(base+hp)=__builtin_bswap32(h);
  { static std::atomic<int> cn{0}; int ci=cn.fetch_add(1)+1;
    if(ci<=24) std::fprintf(stderr,"[cre] #%d h=0x%X type=%u init=%u lr=0x%X tid=%ld\n",
      ci,h,type,state,(uint32_t)ctx.lr,xr_gettid()); }
  ctx.r3.u32=0; }
PPC_FUNC_IMPL(__imp__NtSetEvent){ LOGN("NtSetEvent");
  { static std::mutex m; static std::unordered_map<uint32_t,int> seen;
    bool log=false; { std::lock_guard<std::mutex> l(m); if(seen[ctx.r3.u32]++<2) log=true; }
    if(log) std::fprintf(stderr,"[setev] h=0x%X lr=0x%X\n",ctx.r3.u32,(uint32_t)ctx.lr); }
  // [evt14] trace the file-manager WORK event end-to-end (post-boot starvation forensics)
  if(rt_evt14_trace && ctx.r3.u32==0x50000014u) std::fprintf(stderr,"[evt14] SET lr=0x%X\n",(uint32_t)ctx.lr);
  // [evt34] frame-lock forensics (2026-07-23 sequencer leg): count sets on the game frame event.
  // 08-12 tick/present lane: wall-ms stamps so consecutive prints give a windowed grant rate
  // (delta-ms/600 = ms per frame) — the welded-vs-decoupled discriminator when paired with
  // RT_PRESENT_THROTTLE_MS. NOTE this out_reco copy is the /FORCE:MULTIPLE link WINNER in the
  // combined build (build_win_dll.sh:88) — the out_reco_abn twin carries the same stamp.
  if(ctx.r3.u32==0x50000034u){ extern std::atomic<long long> g_evt34_sets; long long s=g_evt34_sets.fetch_add(1)+1;
    if(s<=3||s%600==0){
      static const auto t0=std::chrono::steady_clock::now();
      long long ms=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-t0).count();
      std::fprintf(stderr,"[evt34] SET #%lld lr=0x%X tid=%ld ms=%lld\n",s,(uint32_t)ctx.lr,xr_gettid(),ms); } }
  rt_setev(ctx.r3.u32); ctx.r3.u32=0; (void)base; }
std::atomic<long long> g_evt34_sets{0};
std::atomic<long long> g_evt34_consumes{0};
PPC_FUNC_IMPL(__imp__NtClearEvent){ LOGN("NtClearEvent"); rt_rstev(ctx.r3.u32); ctx.r3.u32=0; (void)base; }

// ===== counting semaphores (audio producer-consumer) — EXACT rexglue parity =====
// x360 ABI (xboxkrnl):
//   NtCreateSemaphore(r3=&handle_out, r4=obj_attributes, r5=InitialCount, r6=MaximumCount)
//   NtReleaseSemaphore(r3=handle, r4=ReleaseCount, r5=&PreviousCount) -> returns X_STATUS.
// Mirrors rexglue xboxkrnl_threading.cpp NtCreateSemaphore_entry (587-655) /
// NtReleaseSemaphore_entry (657-675) + xsemaphore.cpp semantics: create with initial/max,
// release increments and returns the PREVIOUS count, wait (below) decrements. Handle-based, so
// only NtWaitForSingleObjectEx / NtWaitForMultipleObjectsEx decrement (extended below).
// RT_AUDIOSEM-gated: OFF => historical no-op stub semantics (r3=0, no handle), so the no-env
// regression path is unchanged; ON => real primitive.
PPC_FUNC_IMPL(__imp__NtCreateSemaphore){ LOGN("NtCreateSemaphore");
  if(!realsem()){ ctx.r3.u64=0; (void)base; return; }   // legacy no-op parity (default)
  uint32_t hp=ctx.r3.u32, initial=ctx.r5.u32, maxc=ctx.r6.u32;
  RtSemaphore* s=new RtSemaphore();
  s->count=(long)(int32_t)initial;
  s->maxcount=(maxc? (long)(int32_t)maxc : 0x7FFFFFFF);
  uint32_t h=rt_add(s);
  if(hp) *(uint32_t*)(base+hp)=__builtin_bswap32(h);
  { static std::atomic<int> cn{0}; int ci=cn.fetch_add(1)+1;
    if(ci<=16) std::fprintf(stderr,"[sem] CREATE #%d h=0x%X init=%d max=%d lr=0x%X tid=%ld\n",
      ci,h,(int)s->count,(int)s->maxcount,(uint32_t)ctx.lr,xr_gettid()); }
  ctx.r3.u32=0; }
PPC_FUNC_IMPL(__imp__NtReleaseSemaphore){ LOGN("NtReleaseSemaphore");
  if(!realsem()){ ctx.r3.u64=0; (void)base; return; }   // legacy no-op parity (default)
  uint32_t h=ctx.r3.u32, rel=ctx.r4.u32, prevp=ctx.r5.u32;
  RtSemaphore* s=rt_sem(h);
  if(!s){ if(prevp)*(uint32_t*)(base+prevp)=0; ctx.r3.u32=0xC0000008u; /*INVALID_HANDLE*/ return; }
  long prev; bool over=false;
  { std::lock_guard<std::mutex> l(s->m);
    prev=s->count;
    if(s->count + (long)(int32_t)rel > s->maxcount){ over=true; }
    else { s->count += (long)(int32_t)rel; s->cv.notify_all(); }
  }
  if(!over) rt_mw_wake();   // flicker-truth fix #2: multi-waiters with semaphore members wake now
  if(prevp)*(uint32_t*)(base+prevp)=__builtin_bswap32((uint32_t)prev);
  { static std::atomic<int> rn{0}; int ri=rn.fetch_add(1)+1;
    if(ri<=24) std::fprintf(stderr,"[sem] RELEASE #%d h=0x%X rel=%u prev=%d%s lr=0x%X tid=%ld\n",
      ri,h,rel,(int)prev,over?" OVER":"",(uint32_t)ctx.lr,xr_gettid()); }
  ctx.r3.u32=over?0xC0000047u/*SEMAPHORE_LIMIT_EXCEEDED*/:0; (void)base; }

// x360 ABI: NtWaitForSingleObjectEx(r3=handle, r4=WaitMode, r5=Alertable, r6=&Timeout
// (LARGE_INTEGER*, NULL/0 = infinite; negative = relative 100ns units)). Returns
// STATUS_SUCCESS(0) on signal, STATUS_TIMEOUT(0x102) on timeout. If the handle can't be
// resolved to a known RtEvent (e.g. a service-thread event we haven't modeled, or a
// handle from a code path we don't yet track), do NOT fail the wait -- that previously
// caused callers to treat a negative/error return as a shutdown signal and self-terminate
// after one iteration. Instead: log once, back off briefly, and return SUCCESS so the
// caller's loop keeps spinning until something (e.g. the shell's per-frame kick) signals
// the real event out from under us on a later pass.
PPC_FUNC_IMPL(__imp__NtWaitForSingleObjectEx){ LOGN("NtWaitForSingleObjectEx");
  uint32_t h=ctx.r3.u32, timeoutp=ctx.r6.u32;
  // Semaphore handle (RT_AUDIOSEM): wait for count>0, then decrement (rex::thread::Semaphore /
  // Wait semantics). Infinite-block matches rexglue; on a dedicated guest audio thread this parks
  // exactly like HW until the producer's NtReleaseSemaphore signals.
  if(realsem()){ if(RtSemaphore* s=rt_sem(h)){
    bool infinite=(timeoutp==0); long long rel100ns=0;
    if(!infinite) rel100ns=(long long)__builtin_bswap64(*(uint64_t*)(base+timeoutp));
    std::unique_lock<std::mutex> l(s->m);
    bool signaled;
    if(infinite){ s->cv.wait(l,[&]{return s->count>0;}); signaled=true; }
    else if(rel100ns<0){ long long us=(-rel100ns)/10; if(us<0)us=0;
      signaled=s->cv.wait_for(l,std::chrono::microseconds(us),[&]{return s->count>0;}); }
    else signaled=(s->count>0);   // absolute/positive timeout -> poll once (event-path parity)
    if(signaled){ s->count--; ctx.r3.u32=0; } else ctx.r3.u32=0x102;
    { static std::atomic<int> wn{0}; int wi=wn.fetch_add(1)+1;
      if(wi<=24) std::fprintf(stderr,"[sem] WAIT #%d h=0x%X -> %s count=%d lr=0x%X tid=%ld\n",
        wi,h,signaled?"SIG":"TMO",(int)s->count,(uint32_t)ctx.lr,xr_gettid()); }
    return;
  } }
  RtEvent* e=rt_ev(h,false);
  if(h>=0x50000040u && h<=0x5000005Cu){ static std::atomic<int> wn{0}; int wi=wn.fetch_add(1)+1;
    if(wi<=12) std::fprintf(stderr,"[wait48] h=0x%X timeoutp=0x%X e=%p sig=%d lr=0x%X tid=%ld\n",
      h,timeoutp,(void*)e,e?(int)e->sig:-1,(uint32_t)ctx.lr,xr_gettid()); }
  if(!e){
    // CODE_REVIEW_0804 MED-8: warn PER-HANDLE (the old one-shot global latch meant a NEW bad
    // handle appearing later — e.g. a garbage handle from a failed create — was silent).
    static std::set<uint32_t> warnedH; static std::mutex warnedM;
    bool firstH=false; { std::lock_guard<std::mutex> wl(warnedM); firstH=warnedH.insert(h).second && warnedH.size()<=64; }
    if(firstH){ std::fprintf(stderr,"[wait] NtWaitForSingleObjectEx unresolved h=0x%X lr=0x%X\n",h,(uint32_t)ctx.lr); }
    usleep(1000);
    ctx.r3.u32=0;
    return;
  }
  bool infinite = (timeoutp==0);
  long long rel100ns=0;
  if(!infinite){
    rel100ns=(long long)__builtin_bswap64(*(uint64_t*)(base+timeoutp));
  }
  std::unique_lock<std::mutex> l(e->m);
  bool signaled;
  if(infinite){
    e->cv.wait(l,[&]{return e->sig;});
    signaled=true;
  } else if(rel100ns<0){
    long long us=(-rel100ns)/10; if(us<0) us=0;
    signaled=e->cv.wait_for(l,std::chrono::microseconds(us),[&]{return e->sig;});
  } else {
    // Absolute timeout: treat conservatively as "already due" -> poll once.
    signaled=e->sig;
  }
  if(signaled){
    rt_consume(e);
    if(rt_evt14_trace && h==0x50000014u) std::fprintf(stderr,"[evt14] CONSUMED-single lr=0x%X\n",(uint32_t)ctx.lr);
    if(h==0x50000034u){ long long c=g_evt34_consumes.fetch_add(1)+1;
      if(c<=3||c%600==0) std::fprintf(stderr,"[evt34] CONSUME-single #%lld lr=0x%X tid=%ld\n",c,(uint32_t)ctx.lr,xr_gettid()); }
    ctx.r3.u32=0; /* STATUS_SUCCESS */
  } else {
    ctx.r3.u32=0x102; /* STATUS_TIMEOUT */
  }
  (void)base;
}

// x360 ABI: NtWaitForMultipleObjectsEx(r3=Count, r4=&Handles[] (big-endian u32 array),
// r5=WaitType (1=wait-any, 0=wait-all), r6=WaitMode, r7=Alertable, r8=&Timeout (LARGE_INTEGER*,
// NULL/0 = infinite; negative = relative 100ns units; positive/absolute = treated as infinite,
// logged once). Currently only wait-any is implemented (wait-all logs once and is treated as
// wait-any); real multi-object AND-wait is not needed by any caller we've observed yet.
// Poll loop (~1ms) over the handle set, reusing the same RtEvent registry/semantics as
// NtWaitForSingleObjectEx above (auto-reset events are consumed on signal). Unknown/unresolved
// handles (e.g. thread handles 0xE000+) are treated as never-signaled and logged once per
// unique handle. This is called from a HOT shell sound-thread loop -- keep the 1ms usleep so
// polling doesn't burn CPU.
PPC_FUNC_IMPL(__imp__NtWaitForMultipleObjectsEx){ LOGN("NtWaitForMultipleObjectsEx");
  uint32_t count=ctx.r3.u32, handlesp=ctx.r4.u32, waittype=ctx.r5.u32, timeoutp=ctx.r8.u32;
  if(waittype==0){
    static bool warned=false;
    if(!warned){ warned=true; std::fprintf(stderr,"[waitmulti] WaitType=0 (wait-all) not implemented; treating as wait-any\n"); }
  }
  if(count==0||count>64) count=(count>64)?64:count;
  uint32_t handles[64];
  for(uint32_t i=0;i<count;++i) handles[i]= handlesp? __builtin_bswap32(*(uint32_t*)(base+handlesp+4*i)) : 0;
  { // diag: log the first few DISTINCT wait-sets (key = first handle ^ count) with caller lr
    static std::mutex m; static std::unordered_map<uint64_t,int> seen;
    uint64_t key=((uint64_t)count<<32)|handles[0];
    bool log=false;
    { std::lock_guard<std::mutex> l(m); if(seen[key]++<2) log=true; }
    if(log){
      char buf[512]; int p=0;
      for(uint32_t i=0;i<count&&p<(int)sizeof(buf)-16;++i) p+=std::snprintf(buf+p,sizeof(buf)-p," 0x%X",handles[i]);
      std::fprintf(stderr,"[waitmulti] lr=0x%X count=%u type=%u timeout=%s handles:%s\n",
        (uint32_t)ctx.lr,count,waittype,timeoutp?"timed":"inf",buf);
    }
  }

  bool infinite=(timeoutp==0);
  long long rel100ns=0;
  if(!infinite){
    rel100ns=(long long)__builtin_bswap64(*(uint64_t*)(base+timeoutp));
    if(rel100ns>=0){
      static bool warnedabs=false;
      if(!warnedabs){ warnedabs=true; std::fprintf(stderr,"[waitmulti] absolute/positive timeout not supported; treating as infinite\n"); }
      infinite=true;
    }
  }
  long long timeout_ms = infinite? -1 : ((-rel100ns)/10000);
  if(!infinite && timeout_ms<0) timeout_ms=0;

  long long elapsed_ms=0;
  const auto wm_t0 = std::chrono::steady_clock::now();   // real-wait path: clock-based timeout
  static std::mutex g_wm_warned_m; static std::unordered_map<uint32_t,bool> g_wm_warned;
  for(;;){
    for(uint32_t i=0;i<count;++i){
      uint32_t h=handles[i];
      // Semaphore member of the wait-set (RT_AUDIOSEM): if available, decrement + return index.
      if(realsem()){ if(RtSemaphore* s=rt_sem(h)){
        std::lock_guard<std::mutex> l(s->m);
        if(s->count>0){ s->count--; ctx.r3.u32=i; return; }
        continue;
      } }
      RtEvent* e=rt_ev(h,false);
      if(!e){
        bool first=false;
        { std::lock_guard<std::mutex> l(g_wm_warned_m); if(!g_wm_warned[h]){ g_wm_warned[h]=true; first=true; } }
        if(first) std::fprintf(stderr,"[waitmulti] unresolved h=0x%X (skipped)\n",h);
        continue;
      }
      std::lock_guard<std::mutex> l(e->m);
      if(e->sig){
        rt_consume(e);
        if(rt_evt14_trace && h==0x50000014u) std::fprintf(stderr,"[evt14] CONSUMED-multi idx=%u\n",i);
        if(h==0x50000034u){ long long c=g_evt34_consumes.fetch_add(1)+1;
          if(c<=3||c%600==0) std::fprintf(stderr,"[evt34] CONSUME-multi #%lld lr=0x%X tid=%ld\n",c,(uint32_t)ctx.lr,xr_gettid()); }
        ctx.r3.u32=i; /* index of the signaled object, STATUS_WAIT_0 + i */
        return;
      }
    }
    if(!infinite){
      if(elapsed_ms>=timeout_ms){ ctx.r3.u32=0x102; /* STATUS_TIMEOUT */ return; }
    }
    // [evt34] poll-alive heartbeat: proves the game main's frame-wait loop is RUNNING (vs blocked
    // elsewhere) and shows the observed sig state when the wait-set includes the frame event.
    { static std::atomic<long long> pl{0};
      bool has34=false; for(uint32_t i=0;i<count;++i) if(handles[i]==0x50000034u){ has34=true; break; }
      if(has34){ long long p=pl.fetch_add(1)+1;
        if(p%4000==0){ RtEvent* e34=rt_ev(0x50000034u,false);
          extern std::atomic<long long> g_evt34_sets;
          std::fprintf(stderr,"[evt34] POLL-alive #%lld tid=%ld sig=%d sets=%lld consumes=%lld\n",
            p,xr_gettid(),e34?(int)e34->sig:-1,g_evt34_sets.load(),g_evt34_consumes.load()); } } }
    if(realwait()){
      // Block on the global wake cv: any event/semaphore signal wakes ALL multi-waiters
      // immediately (they re-scan their handle sets above). 1ms bounded fallback keeps a
      // missed notify (signal between scan and wait) no worse than the old poll.
      std::unique_lock<std::mutex> ml(g_mwM);
      g_mwCv.wait_for(ml, std::chrono::milliseconds(1));
      ml.unlock();
      elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                     std::chrono::steady_clock::now() - wm_t0).count();
    } else {
      usleep(1000);
      elapsed_ms+=1;
    }
  }
}
