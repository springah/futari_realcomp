// merged_shell.cpp — the SHELL half (host-exe-forever): every sub_82 hook, the idle/render-loop
// injection sub_821706E8, RT_LOADGAME, the menu/task instruments
// Split out of out_reco/merged/merged_xex.cpp (verbatim) by L2 of
// _tmpscripts/dll_packaging_plan.md §2.3/§2.4.  Original: merged_xex.cpp.bak_l2split.
// Shared scaffolding lives in merged_common.h.
#include "merged_common.h"
extern "C" uint32_t rt_alloc(uint32_t size, uint32_t align);
extern "C" void __imp__sub_821706E8(PPCContext& __restrict ctx, uint8_t* base);  // real idle/render loop
// GATE 3: the per-frame game-mode tick target. Defined in shell/gen/rt.cpp; the VdSwap hook
// there calls sub_821C3278(r3=g_game_tick_modectx) once per present when RT_GAMETICK is set.
// We set it to the INNER modectx after the GameEntry init driver completes, so the shell begins
// servicing the game's per-frame update (which the free-running game main thread is waiting on
// via its gate flag 0x887AC958 — see sub_88168C80 wrapper below).
extern "C" uint32_t g_game_tick_modectx;
static const uint32_t GAME_DRIVER     = 0x821C30B8u;  // GameEntry message driver
static const uint32_t MODE_DISPATCH   = 0x821C3B90u;  // shell mode-select dispatcher (ctor+loader+tail setup)
static const uint32_t SINGLETON_ADDR  = 0x821F8588u;  // shell singleton watched pre/post dispatch
static const uint32_t CB248_INIT      = 0x821CB248u;  // shell service-singleton ctor: RtlInitializeCriticalSection(0x821F8210) + pool-alloc + ExCreateThread(service thread), stores singleton -> 0x821F857C
static const uint32_t CB248_SINGLETON = 0x821F857Cu;  // singleton pointer written by CB248_INIT; GameEntry msg-1 struct+28 reads *(this)
// g_rt_menu_heartbeat (2026-07-23 SYSTEM-MENU pillarbox compose): pulsed every guest tick a
// SHELL MENU MODEL is on-screen ticking a visible state. Covered models (vt-scoped):
//   0x820503B0 menu_game_title (7-item SYSTEM MENU) + 0x820504D0 menu_scoreattack — both run
//   the SHARED state chain vt+0x2C=821BB298 / +0x30=821BA4D8 / +0x34=821BB1D8 (img vtable dump);
//   0x82050F00 training-config model (built by 821966D0 on DECIDE(2)) — OWN chain
//   vt+0x2C=82196660 / +0x30=821BE500 (dialog-family, shared!) / +0x34=82195AB0.
// The renderer's in-session pillarbox compose gates its shell-overlay pass on this advancing so it
// composes the menu ONLY when it is up — NOT during ROM attract, whose ranking UI is already in the
// panel (compositing it too = double-draw). A monotonic counter (not a bool) so the renderer detects
// "advanced since last present" without writing guest memory; freezes on close -> overlay stops.
extern "C" { volatile unsigned int g_rt_menu_heartbeat = 0; }
// [jankstate] JOIN-PROBE globals (2026-07-24 menu-jank Q1 discriminator): sampled once per guest
// frame inside the sub_88168C80 [jank] block, written by the shell menu walker (sub_82173B98) and
// the cancel-life ctor/dtor hooks further down. Lets the SAME stream carry frame-cadence AND the
// menu model's state fn (+0x48) AND the live confirm-task / kind-2-dialog counts, so fps can be
// correlated against (a) menu leaving idle, (b) a confirm-task's birth, (c) its continued life.
static std::atomic<uint32_t> g_js_menuModel{0};
// L3 stage 1 (dll_packaging_plan §5 L3 / l2_split_notes §6.1): these three were briefly
// C++17 `inline` variables in merged_common.h because the game half read them.  An inline
// variable yields ONE instance per IMAGE, so the moment merged_game.cpp becomes a DLL (E6/L4)
// the shell's writes would silently stop reaching the game's read.  The read was a pure
// diagnostic, so it moved HERE instead — and these are file statics again, invisible outside
// this TU, i.e. the entanglement is gone rather than carried.  The game half now supplies only
// its own frame cadence through the two rt_jankstate_* entry points below (module -> host
// calls, which the §1.3 FutariHostAbi covers; a shared variable is not expressible in it).
static std::atomic<uint32_t> g_js_menuState{0};   // menu_game_title (vt 820503b0) +0x48 state fn
static std::atomic<int> g_js_taskAlive{0};        // confirm task  (ctor 821bd8b8, vt 82050254) alive
static std::atomic<int> g_js_dlgAlive{0};         // kind-2 dialog (ctor 821bd670, vt 82050200) alive
// The per-tick sample, cached so [janksum] reports the SAME triple [jankstate] latched on this
// frame — preserving the old code's single-sample-per-frame semantics exactly.
static std::atomic<uint32_t> g_js_lastMst{0};
static std::atomic<int> g_js_lastTa{0}, g_js_lastDa{0};
static const char* js_state_name(uint32_t s){
  switch(s){ case 0x82061D50u:return "idle"; case 0x82061D70u:return "confirm";
    case 0x82063A58u:return "commit"; case 0x82065A78u:return "leave"; case 0x82065A88u:return "close";
    case 0x821BD7E8u:return "task-init"; default:return "?"; } }
// Called once per guest frame from the game half's sub_88168C80 [jank] block (RT_MENUJANK).
// n = that block's frame counter, d_us = the instantaneous frame delta.
extern "C" void rt_jankstate_tick(long long n, long long d_us){
  static std::atomic<uint64_t> lastjs{~0ull};
  uint32_t mst=g_js_menuState.load(); int ta=g_js_taskAlive.load(), da=g_js_dlgAlive.load();
  g_js_lastMst.store(mst); g_js_lastTa.store(ta); g_js_lastDa.store(da);
  uint64_t js=((uint64_t)mst<<24)^((uint64_t)(ta&0xFFF)<<12)^(uint64_t)(da&0xFFF);
  if(lastjs.exchange(js)!=js && n>3)
    std::fprintf(stderr,"[jankstate] n=%lld d=%lldus menu=0x%X[%s] taskAlive=%d dlgAlive=%d\n",
      n,d_us,mst,js_state_name(mst),ta,da);
}
// The 1s window summary, emitted from the same block right after its own counters are read.
extern "C" void rt_jankstate_summary(long long frames, long long slow, long long maxd, long long meand){
  uint32_t mst=g_js_lastMst.load(); int ta=g_js_lastTa.load(), da=g_js_lastDa.load();
  std::fprintf(stderr,"[janksum] frames=%lld slow=%lld maxd=%lldus meand=%lldus | menu=0x%X[%s] taskAlive=%d dlgAlive=%d\n",
    frames, slow, maxd, meand, mst, js_state_name(mst), ta, da);
}
// [rbind] (2026-07-23 rapid-fire A/B): sub_821C5390 = the shell's per-frame BINDING RESOLVER
// (bindings ptr = u32[4] @ *(u32@(*(u32@0x821F858C) + (player+1)*4)); factory {1,2,8,3} =
// SHOT->A, BOMB->B, R.SHOT->R_TRIGGER, PlayerChange->X). The rapid-fire trace ranked "settings
// load zeroes the binding array" as the #1 residual risk — log P1's four binding words on
// first call + any change.
extern "C" void __imp__sub_821C5390(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821C5390){
  uint32_t player=ctx.r4.u32;
  if(player==0){
    uint32_t basev=PPC_LOAD_U32(0x821F858Cu);
    uint32_t p=basev?PPC_LOAD_U32(basev+4):0;
    uint32_t b0=p?PPC_LOAD_U32(p):0, b1=p?PPC_LOAD_U32(p+4):0,
             b2=p?PPC_LOAD_U32(p+8):0, b3=p?PPC_LOAD_U32(p+12):0;
    static std::atomic<uint64_t> lastb{~0ull};
    uint64_t sig=((uint64_t)b0<<48)|((uint64_t)b1<<32)|((uint64_t)b2<<16)|b3;
    if(lastb.exchange(sig)!=sig)
      std::fprintf(stderr,"[rbind] P1 bindings SHOT=%u BOMB=%u R.SHOT=%u PCHG=%u (ptr=0x%X; factory=1,2,8,3)\n",
        b0,b1,b2,b3,p);
  }
  __imp__sub_821C5390(ctx,base);
}

// sub_82182008 = the game-panel DROP-SHADOW ring (4 edge strips + 4 corner fans; FUN_82183C68
// calls it right before the panel quad). Discriminator for the border-shadow leg: confirm it
// fires 1x/frame during ROM attract (=> the 8 ovN batches the present path drops ARE the ring)
// and log the guest gate dwords (SS+0x580 -> +0x14 DropShadow!=Off, +0x18 SimplifyDraw==Off).
extern "C" void __imp__sub_82182008(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_82182008){
  static std::atomic<long long> n{0}; long long i=n.fetch_add(1)+1;
  if(i<=4 || (i%600)==0){
    uint32_t ss=PPC_LOAD_U32(0x821F8264u);
    uint32_t g14=ss?PPC_LOAD_U32(ss+0x14):0, g18=ss?PPC_LOAD_U32(ss+0x18):0;
    std::fprintf(stderr,"[shadowring] call#%lld gate14=%u gate18=%u (draws iff 14!=0 && 18!=0)\n",
      i,g14,g18);
  }
  __imp__sub_82182008(ctx,base);
}

// Render-handoff visibility: the driver's msg-9 registers 4 REAL shell callbacks with the game
// (cb2=sub_821C5618 = the per-frame render/state poll). If the game main runs frames, these
// should fire; if the shell then authors draws, sub_8209D800 (immediate DRAW_INDX emitter) and
// sub_820A5408 (Present) fire. Always-on counters: first 5 + every 2000th.
#define CBCOUNT_WRAP(FN,TAG) \
  extern "C" void __imp__##FN(PPCContext& __restrict, uint8_t*); \
  static std::atomic<long long> g_cbc_##FN{0}; \
  PPC_FUNC(FN){ \
    long long n=g_cbc_##FN.fetch_add(1)+1; \
    if(n<=5 || (n%2000)==0) std::fprintf(stderr,"[cb] " TAG " (" #FN ") call#%lld r3=0x%X r4=0x%X\n",n,ctx.r3.u32,ctx.r4.u32); \
    __imp__##FN(ctx,base); \
  }
CBCOUNT_WRAP(sub_821C52E8,"svc0")
CBCOUNT_WRAP(sub_821C6208,"svc1")
CBCOUNT_WRAP(sub_821C5230,"svc3")
// cb2 = the per-frame input/render callback the game invokes. It reads user *(this+128)'s
// processed input but DISPATCHES it only if *(this+152)==0; nonzero => input IGNORED (the
// "can't advance while titles play" gate). Log the gate state to see if it ever clears.
extern "C" void __imp__sub_821C5618(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821C5618){
  // [nopause-spin] (2026-07-23 sequencer leg): cb3 runs EVERY iteration of fb90's pause spin on
  // the spinning game-main thread — clearing 534 here is the resume (msg 10 arg=0) the shell never
  // sends in this flow. See the RT_NOPAUSE spin-breaker comment block above RT_STARTWIRE.
  { static int np = std::getenv("RT_NOPAUSE")?1:0;
    if(np && PPC_LOAD_U32(0x887AD534u)!=0){
      PPC_STORE_U32(0x887AD534u,0);
      static std::atomic<int> z{0}; int q=z.fetch_add(1)+1;
      if(q<=5||q%600==0) std::fprintf(stderr,"[nopause-spin] cleared 534 inside fb90 pause spin (#%d)\n",q);
    } }
  uint32_t t=ctx.r3.u32;
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  static uint32_t lastgate=0xDEAD; uint32_t gate=t?PPC_LOAD_U32(t+152):0, usr=t?PPC_LOAD_U32(t+128):0;
  if(i<=5 || gate!=lastgate){ lastgate=gate;
    std::fprintf(stderr,"[cb2gate] call#%ld this=0x%X user(+128)=%u gate(+152)=0x%X %s\n",
      i,t,usr,gate,gate?"INPUT-IGNORED":"INPUT-LIVE"); }
  // RT_INPUTFORCE: override the input-disable gate (modectx+152 stuck at 1 during titles).
  // Diagnostic: if forcing input-live lets our synthetic START drive the title->press-start
  // transition, the gate IS the lever and the real fix is the natural title-done clear.
  static const bool rtInputForce = std::getenv("RT_INPUTFORCE")!=nullptr;   // hot path: this hook runs every pause-spin iteration
  if(t && rtInputForce && PPC_LOAD_U32(t+152)!=0){
    PPC_STORE_U32(t+152,0);
    static std::atomic<int> once{0}; if(once.fetch_add(1)<3) std::fprintf(stderr,"[cb2gate] RT_INPUTFORCE cleared gate +152 -> 0\n");
  }
  __imp__sub_821C5618(ctx,base);
  // RT_CB2RET=<hex>: force cb2's return value to the game. Standalone (futari_mode) needed
  // RT_CB2_RET=1 to unblock the game past its per-loop poll into asset loading. Test whether
  // the merged game's commit tier gates on cb2's return the same way.
  static const char* rtCb2Ret = std::getenv("RT_CB2RET");   // cached: same hot path as above
  if(const char* v=rtCb2Ret){
    uint32_t fv=(uint32_t)strtoul(v,nullptr,16);
    static std::atomic<int> once{0}; if(once.fetch_add(1)<2) std::fprintf(stderr,"[cb2gate] RT_CB2RET forcing r3 0x%X -> 0x%X\n",ctx.r3.u32,fv);
    ctx.r3.u32=fv;
  }
}

// ---- RT_RESCACHE (LEG-37): np-wall probe. sub_8206E500 (shell/gen/ppc_recomp.1.cpp:20343)
// is the SHELL's string-keyed sorted-list find/insert (its node-insert helper sub_8206F988
// allocs 44-byte nodes; container r4: +24=sentinel, +28=count). The np13-class freeze = the
// shell main thread never returning from this walk (RSS flat -> cyclic/corrupt chain OR
// pathological growth), starving the GameEntry msg-5 pump. On ENTER: bounded host-side walk
// of BOTH candidate link chains (+0 and +4) from the sentinel; log count evolution, flag a
// cycle (cap hit) or huge growth. Log-only — mitigation decided after the evidence.
extern "C" void __imp__sub_8206E500(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_8206E500){
  static bool on = std::getenv("RT_RESCACHE")!=nullptr;
  long long i=0; bool shouldLog=false;
  if(on){
    static std::atomic<long long> n{0}; i=n.fetch_add(1)+1;
    uint32_t cont=ctx.r4.u32;
    uint32_t sent=cont?PPC_LOAD_U32(cont+24):0, cnt=cont?PPC_LOAD_U32(cont+28):0;
    uint32_t cap = (cnt<400000u?cnt:400000u)+16;
    uint32_t hops0=0,hops4=0; bool cyc0=false,cyc4=false;
    if(sent){
      for(uint32_t nd=PPC_LOAD_U32(sent+0); nd && nd!=sent; nd=PPC_LOAD_U32(nd+0))
        if(++hops0>cap){ cyc0=true; break; }
      for(uint32_t nd=PPC_LOAD_U32(sent+4); nd && nd!=sent; nd=PPC_LOAD_U32(nd+4))
        if(++hops4>cap){ cyc4=true; break; }
    }
    static std::atomic<int> oddLogs{0};
    bool odd = cyc0||cyc4||cnt>20000u;
    shouldLog = (i<=6 || (i%2000)==0 || (odd && oddLogs.fetch_add(1)<40));
    if(shouldLog)
      std::fprintf(stderr,"[rescache] #%lld ENTER lr=0x%X cont=0x%X sent=0x%X count=%u hops0=%u%s hops4=%u%s tid=%ld\n",
        i,(uint32_t)ctx.lr,cont,sent,cnt,hops0,cyc0?"(CYCLE!)":"",hops4,cyc4?"(CYCLE!)":"",
        xr_gettid());
  }
  __imp__sub_8206E500(ctx,base);
  // 2026-07-12 RT_RESCACHE EXIT probe: pairs with the ENTER log above. If a call's ENTER
  // prints but its EXIT never does, __imp__sub_8206E500 itself is hung inside the real
  // (recompiled) list walk/insert -- proving the freeze is IN this function, not merely
  // that its caller stopped invoking it.
  if(on && shouldLog)
    std::fprintf(stderr,"[rescache] #%lld EXIT tid=%ld\n", i, xr_gettid());
}

// ---- RT_HEAPLOCK (LEG-37): serialize the SHELL HEAP with a host mutex. The np13-class
// nondeterministic freeze = SHELL HEAP CORRUPTION: the heap entry fns (sub_8208C450/C458
// alloc, sub_8208CD18/CD20 free, + siblings) take their guest critical section (heap+1408)
// only when the HEAP_NO_SERIALIZE bit (heap+24 bit0 | caller flags bit0) is CLEAR — and this
// heap runs NO_SERIALIZE (single-threaded on real HW). In merged, the shell PUMP thread
// builds/destroys transition-item screens (np's rec+68|=0x2 walks statefns into 0x8206xxxx
// string/list code) while the MAIN thread ticks screens — two threads in a lockless heap →
// free-list cycle → a later alloc (gdb: spin in sub_8208C458 walk / sub_8206E500 insert) or
// free (spin in sub_8208CD20) walks forever, RSS flat, msg-5 pump starves. Freezes observed
// at 3 different PCs across runs = classic corruption nondeterminism. One host recursive
// mutex over every entry point (recursive: the entries nest via weak-alias dispatch).
static std::recursive_mutex g_shellheap_m;
static bool heaplock(){ static bool on=std::getenv("RT_HEAPLOCK")!=nullptr; return on; }
#define HEAPLOCK_WRAP(FN) \
  extern "C" void __imp__##FN(PPCContext& __restrict, uint8_t*); \
  PPC_FUNC(FN){ \
    if(heaplock()){ std::lock_guard<std::recursive_mutex> l(g_shellheap_m); __imp__##FN(ctx,base); } \
    else __imp__##FN(ctx,base); \
  }
HEAPLOCK_WRAP(sub_8208C450)
HEAPLOCK_WRAP(sub_8208C458)
HEAPLOCK_WRAP(sub_8208CCA4)
HEAPLOCK_WRAP(sub_8208CCCC)
HEAPLOCK_WRAP(sub_8208CD18)
HEAPLOCK_WRAP(sub_8208CD20)
HEAPLOCK_WRAP(sub_8208CF9C)
HEAPLOCK_WRAP(sub_8208CFC4)
HEAPLOCK_WRAP(sub_8208D00C)
HEAPLOCK_WRAP(sub_8208D018)
HEAPLOCK_WRAP(sub_8208D860)
HEAPLOCK_WRAP(sub_8208D880)

// LEG-15 (RT_HUB=1): shell message-hub probes. RE found the UNMAPPED-at-0x820E9004 loop is the
// hub manager (264B obj, ctor sub_820E7E10 via sub_820E5FA8 <- sub_821CA5F0 <- sub_821CB108)
// being ticked with an unconstructed/garbage `this`. Probe: does the ctor chain ever run, and
// what `this`/vtable does the tick sub_820E8F88 see? Also the game->shell bit-notify bridge
// sub_8808D1B8 (bit 43 = id-46 completion) through slot pair 0x887AD610/614.
extern "C" void __imp__sub_820E8F88(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820E8F88){
  if(std::getenv("RT_HUB")){
    static std::atomic<int> n{0}; int i=n++;
    if(i<8 || (i%2000)==0){
      uint32_t t=ctx.r3.u32, vt=0, nx=0;
      if(t>=0x1000 && t<0xFFFF0000u){ vt=PPC_LOAD_U32(t); nx=PPC_LOAD_U32(t+176); }
      std::fprintf(stderr,"[hub] tick#%d this=0x%X vt0=0x%X next176=0x%X (healthy vt0=0x82013F48)\n",i,t,vt,nx);
    }
  }
  __imp__sub_820E8F88(ctx,base);
}
extern "C" void __imp__sub_821CA5F0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821CA5F0){
  if(std::getenv("RT_HUB")){ static std::atomic<int> n{0}; int i=n++;
    if(i<6) std::fprintf(stderr,"[hub] CA5F0 (hub-creator) ENTER#%d this=0x%X\n",i,ctx.r3.u32); }
  __imp__sub_821CA5F0(ctx,base);
}

// ---- RT_MIXTRACE globals (declared before the attach hook that references them) ----
static std::mutex g_mt_mtx;
struct MtVoice { uint64_t first=0, last=0, count=0; uint32_t vt=0, render=0;
                 uint64_t renders=0, nzRenders=0; float peak=0;
                 uint64_t inRenders=0, inNz=0; float inPeak=0; float rawPeak=0; };
// census 256 f32 at guest addr `out`. Computes BOTH the BE (bswapped) peak and the raw host-endian
// peak — whichever lands in sane audio range tells us the true storage order of the mix buffers.
static inline int rt_mt_census_buf(uint8_t* base, uint32_t out, float& peak, float* rawpeak=nullptr){
  peak=0.0f; if(rawpeak)*rawpeak=0.0f; if(!out||out>=0xF0000000u) return -1; int nz=0;
  for(int s=0;s<256;s++){
    uint32_t be=PPC_LOAD_U32(out+(uint32_t)s*4); float f; std::memcpy(&f,&be,4);
    float a=f<0?-f:f; if(f!=0.0f && a<1e12f){ ++nz; if(a>peak)peak=a; }
    if(rawpeak){ uint32_t raw=*(volatile uint32_t*)(base+out+(uint32_t)s*4); float g; std::memcpy(&g,&raw,4);
      float ag=g<0?-g:g; if(g!=0.0f && ag<1e12f && ag>*rawpeak)*rawpeak=ag; }
  }
  return nz;
}
static std::unordered_map<uint32_t,MtVoice> g_mt_v;   // XAudio2 source-voice addr -> lifetime
// per-voice OUTPUT census: after a voice renders, its contribution lands at *(voice+120)+56 (the
// same block the summer reads back). Count nonzero frames + peak. Long-lived voice with 0 nonzero
// => in-graph but STARVED (prime hypothesis: loop/refill stall). r3=voice.
static void rt_mt_census(uint8_t* base, uint32_t voice, uint32_t render){
  if(!voice || voice>=0xF0000000u) return;
  // resolve the TRUE output buffer per render type (decomp-grounded):
  //  8214E5C0: process outbuf = *(*(voice+0x7c))  (FUN_8214e5c0: **(param_1+0x7c))
  //  82150338: final outbuf   = *(*(voice+0x50)) + 0x38  (iVar6+0x38, iVar6=*(voice[0x14]))
  uint32_t out=0, in=0;
  if(render==0x8214E5C0u){
    // FUN_8214e5c0: DSP process(this, 1, INbuf=*(*(voice+0x78)), 1, OUTbuf=*(*(voice+0x7c)), n=*(voice+0x60))
    uint32_t p7c=PPC_LOAD_U32(voice+0x7c); if(p7c&&p7c<0xF0000000u) out=PPC_LOAD_U32(p7c);
    uint32_t p78=PPC_LOAD_U32(voice+0x78); if(p78&&p78<0xF0000000u) in =PPC_LOAD_U32(p78);
  } else if(render==0x82150338u){
    uint32_t p=PPC_LOAD_U32(voice+0x50); if(p&&p<0xF0000000u){ uint32_t iv=PPC_LOAD_U32(p); if(iv&&iv<0xF0000000u) out=iv+0x38; }
  } else { // submix 8214E3E0: *(voice+120)+56
    uint32_t ob=PPC_LOAD_U32(voice+120); if(ob&&ob<0xF0000000u) out=ob+56;
  }
  float peak=0.0f, ipeak=0.0f, rawpk=0.0f;
  int nz  = rt_mt_census_buf(base,out,peak,&rawpk);
  int inz = in? rt_mt_census_buf(base,in,ipeak) : -1;
  std::lock_guard<std::mutex> lk(g_mt_mtx);
  auto& mv = g_mt_v[voice];
  if(mv.render==0) mv.render=render;
  if(nz>=0){ mv.renders++; if(nz>0){ mv.nzRenders++; if(peak>mv.peak)mv.peak=peak; if(rawpk>mv.rawPeak)mv.rawPeak=rawpk; } }
  if(inz>=0){ mv.inRenders++; if(inz>0){ mv.inNz++; if(ipeak>mv.inPeak)mv.inPeak=ipeak; } }
}
static std::atomic<uint64_t> g_mt_call{0};            // summer-call index (our "clock")
static std::atomic<uint32_t> g_mt_attach_loop{0x77};  // last attach param_3 (loop byte), for align
static std::atomic<long> g_mt_attach_n{0};
// dump a source-voice's raw words so the true (piVar3 / vtable 0x82015760) layout is readable at
// runtime — we do NOT assume XACT wave-voice offsets here.
static void rt_mt_dump(uint8_t* base, const char* why, uint32_t v, uint32_t vt, uint32_t render, uint64_t call){
  std::fprintf(stderr,"[mixtrace] %s v=0x%X vt=0x%X render=0x%X @call=%llu\n",
    why,v,vt,render,(unsigned long long)call);
  for(int o=0;o<=0x9c;o+=4){ if(o%32==0) std::fprintf(stderr,"%s[mixtrace]   +%3d:",o?"\n":"",o);
    std::fprintf(stderr," %08X",PPC_LOAD_U32(v+o)); }
  std::fprintf(stderr,"\n");
}

// RT_AUDIOROUTE: hook the source-voice ATTACH FUN_821000A0 (source-voice obj vtable 0x82015760
// method +0x90) — calls renderer CreateSourceVoice + buffer-submit + sets the playing flag. If this
// is NEVER entered in a driven field with a playing (ring-filling) BGM wave, the send/route was never
// built (fork a). If entered, log its HRESULT return (fork b = create/submit fails a gate). Read-only.
extern "C" void __imp__sub_821000A0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821000A0){
  static bool mt = std::getenv("RT_MIXTRACE")!=nullptr;
  bool route = std::getenv("RT_AUDIOROUTE")!=nullptr;
  if(mt || route){
    uint32_t p1=ctx.r3.u32, p2=ctx.r4.u32; uint8_t loop=ctx.r5.u8; int p3=(int)(int8_t)loop;
    uint32_t rl0 = mt?PPC_LOAD_U32(0x360CF0u+0x10):0;
    __imp__sub_821000A0(ctx,base);
    uint32_t ret=ctx.r3.u32;
    if(mt){
      long an=g_mt_attach_n.fetch_add(1)+1; g_mt_attach_loop.store(loop);
      uint32_t rl1 = PPC_LOAD_U32(0x360CF0u+0x10);
      std::fprintf(stderr,"[mixtrace] ATTACH #%ld loop=0x%02X ret=0x%X (%s) rendererListHead %08X->%08X\n",
        an,loop,ret,(int32_t)ret>=0?"OK":"FAIL",rl0,rl1);
    }
    if(route){
      static std::atomic<long> an2{0}; long n=an2.fetch_add(1)+1;
      if(n<=16||(n%500)==0)
        std::fprintf(stderr,"[route] ATTACH FUN_821000A0 #%ld param1=0x%X param2=0x%X param3=%d -> ret=0x%X (%s)\n",
          n,p1,p2,p3,ret,(int32_t)ret>=0?"OK-voice-created":"FAIL");
    }
    return;
  }
  __imp__sub_821000A0(ctx,base);
}
// RT_AUDIOROUTE2 (Phase-3d caller trace, default-OFF): the two IXACT3Wave routing setters that build
// the send-list BGM lacks. SetOutputVoices (0x820EE2C8, wave vtable+0x28) sets the gate wave+0x160;
// SetOutputMatrix (0x820ED3C0, wave vtable+0x2c) inserts a send node (target=param_2) into the
// wave+0x164 list. The decomp found NO static callers (pure-virtual dispatch) — so capture the guest
// LR (ctx.lr) at entry to learn WHO issues routing, plus the send TARGET, then decompile that caller.
extern "C" void __imp__sub_820EE2C8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820EE2C8){
  if(std::getenv("RT_AUDIOROUTE2")){
    static std::atomic<long> sn{0}; long n=sn.fetch_add(1)+1;
    uint32_t self=ctx.r3.u32, lr=(uint32_t)ctx.lr, pv=ctx.r4.u32;
    uint32_t cnt=pv?PPC_LOAD_U32(pv):0, arr=pv?PPC_LOAD_U32(pv+4):0, tgt0=arr?PPC_LOAD_U32(arr):0;
    if(n<=24||(n%200)==0)
      std::fprintf(stderr,"[route2] SetOutputVoices #%ld this=0x%X CALLER-LR=0x%08X | count=%u voiceArr=0x%X target0=0x%X\n",
        n,self,lr,cnt,arr,tgt0);
  }
  __imp__sub_820EE2C8(ctx,base);
}
extern "C" void __imp__sub_820ED3C0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820ED3C0){
  if(std::getenv("RT_AUDIOROUTE2")){
    static std::atomic<long> sn{0}; long n=sn.fetch_add(1)+1;
    uint32_t self=ctx.r3.u32, lr=(uint32_t)ctx.lr, tgtIdx=ctx.r4.u32;
    if(n<=24||(n%200)==0)
      std::fprintf(stderr,"[route2] SetOutputMatrix #%ld this=0x%X CALLER-LR=0x%08X | targetIdx=%u srcCh=%u dstCh=%u\n",
        n,self,lr,tgtIdx,ctx.r5.u32,ctx.r6.u32);
  }
  __imp__sub_820ED3C0(ctx,base);
}
// RT_MTXTRACE — REMOVED 2026-08-02 (it lived here as PPC_FUNC(sub_820ECE08), a NEW wrapper on
// IXACT3Cue::SetMatrixCoefficients, cue vtable PTR_FUN_82014688 +0x10).
// IT HAD ALREADY DELIVERED ITS ANSWER, so it does not need to ship in a hot audio path:
//   [mtx] GAME src=2 dst=6 mat=0x885C5C10 m0=0.37500 m3=0.37500 voice[+38]=0x27931F0
//         lr=0x880901AC -> hr=0x00000000 APPLIED-to-live-voice
//   [mtxtally] 512 calls: GAME=390 shell=122 | rejected=0 cached-only=0 applied=512
// i.e. the guest's per-play volume IS delivered and applied to a live voice every time, and
// m0 == perPlayVol/64 exactly. That killed the matrix-dropped, cached-only, channel-count and
// polyphony theories outright. Full detail: memory [[futari-shot-level-hunt]].
// Removed as the bisect step for the OPEN in-game pitch-down-while-firing regression: this was the
// only NEW per-call wrapper today's work put in the audio path. (The per-call std::getenv it
// originally did was already hoisted to a static and that did NOT fix the pitch-down, so the
// getenv-contention theory is REFUTED — do not resurrect it.)
// Restore from git history if the trace is needed again; keep the getenv cached if you do.
// RT_AUDIOROUTE2: the DEFERRED-ATTACH RETRIGGER chain. sub_820ECBA0 (per-instance update, driven by
// DoWork's engine+0x58 list via vtable[+0x4c]) calls sub_820F8168, which — when a cue's sub-voices
// all reach state 3 — sets the wave state 3, clears the pending flag 0x40, and RE-calls FUN_820f7f88
// (the attach). If these are ~0 in-field the retrigger isn't driven (fix = drive it, SMALL). If they
// run often yet BGM still never attaches, the streaming-readiness gate (sub-voice state!=3) is the
// deeper blocker. Read-only entry counters.
extern "C" void __imp__sub_820ECBA0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820ECBA0){
  if(std::getenv("RT_AUDIOROUTE2")){ static std::atomic<long> c{0}; long n=c.fetch_add(1)+1;
    if(n<=4||(n%4000)==0) std::fprintf(stderr,"[route2] per-instance-update sub_820ECBA0 #%ld this=0x%X\n",n,ctx.r3.u32); }
  __imp__sub_820ECBA0(ctx,base);
}
extern "C" void __imp__sub_820F8168(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820F8168){
  if(std::getenv("RT_AUDIOROUTE2")){ static std::atomic<long> c{0}; long n=c.fetch_add(1)+1;
    if(n<=8||(n%4000)==0) std::fprintf(stderr,"[route2] RETRIGGER sub_820F8168 #%ld\n",n); }
  __imp__sub_820F8168(ctx,base);
}
extern "C" void __imp__sub_820F7F88(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820F7F88){
  if(std::getenv("RT_AUDIOROUTE2")){ static std::atomic<long> c{0}; long n=c.fetch_add(1)+1;
    if(n<=16||(n%1000)==0) std::fprintf(stderr,"[route2] START sub_820F7F88 #%ld (attaches iff inst-state==3)\n",n); }
  __imp__sub_820F7F88(ctx,base);
}
// RT_AUDIOROUTE: hook wave-play FUN_820ED268(param1=wave, param2=*(wave+0x38)) — iterates the wave
// send-list (wave+0x160 gate, +0x168 head, +0x164 sentinel). Confirms play runs and whether the
// send-list is empty at play time (the source of fork a). Read-only.
extern "C" void __imp__sub_820ED268(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820ED268){
  if(std::getenv("RT_AUDIOROUTE")){
    static std::atomic<long> pn{0}; long n=pn.fetch_add(1)+1;
    uint32_t wav=ctx.r3.u32;
    uint32_t sgate=wav?PPC_LOAD_U32(wav+0x160):0, shead=wav?PPC_LOAD_U32(wav+0x168):0, ssent=wav?(wav+0x164):0;
    if(n<=16||(n%500)==0)
      std::fprintf(stderr,"[route] PLAY FUN_820ED268 #%ld wave=0x%X send[+0x160]gate=0x%X head=0x%X sentinel=0x%X %s\n",
        n,wav,sgate,shead,ssent,(shead==ssent)?"EMPTY(->attach SKIPPED)":"NON-EMPTY(->attach runs)");
  }
  __imp__sub_820ED268(ctx,base);
}

// RT_ENROLL (Phase-3e ENROLL fork a/b determination, default-OFF): the deferred-attach streaming
// state machine (DoWork -> engine+0x58 walk -> vtable[+0x4c] -> FUN_820F8168 -> attach) ONLY runs for
// waves ENROLLED in the engine active-instance list at engine+0x58 (sentinel@engine+0x58; node.next
// @+4; first-node ptr @engine+0x5c; tail @engine+0x60). ENROLL = sub_820E8AC8(engine,wave) — called
// UNCONDITIONALLY inside CreateWave sub_820EEC10 right after wave Initialize (wave vtable+0x50)
// returns >=0 (verified: loc_820EEDB8 calls vt+0x50; if ret<0 -> loc_820EED84 skips enroll; else
// stores wave to *out and bl 0x820e8ac8). Hook both to pin the fork for the streaming BGM wave
// (vtable 0x82015690):
//   (a) CreateWave NEVER runs for a 0x82015690 wave => BGM create bypasses the real Prepare/CreateWave
//       enroll path (analogous to the dropped-DoWork gap; fix = drive the real create).
//   (b) CreateWave runs but Initialize <0 (enroll skipped) => a stubbed dependency inside streaming
//       wave Initialize; fix = restore that dependency so the real enroll proceeds.
// Read-only. List-count walks engine+0x5c..sentinel forward via node+4.
static int rt_enroll_listcount(uint8_t* base, uint32_t eng){
  if(!eng || eng>=0xF0000000u) return -1;
  uint32_t sent=eng+0x58u, nd=PPC_LOAD_U32(eng+0x5cu); int c=0;
  while(nd && nd!=sent && nd<0xF0000000u && c<256){ ++c; nd=PPC_LOAD_U32(nd+4u); }
  return c;
}
// 2026-07-31 (cue-lifetime mirror): CreateWave runs INSIDE SoundBank::Prepare and is the only place
// the created cue object is visible when Prepare was called Play-style (out-pointer NULL, which is
// how the shell starts its menu music). Stash it per-thread so the Prepare hook below can hand the
// guest handle to the bridge; Prepare -> CreateWave is synchronous on one thread, so a thread_local
// is exact. Always captured (two stores) — the cost is nil and it must not depend on RT_ENROLL.
static thread_local uint32_t t_last_created_wave = 0;

extern "C" void __imp__sub_820EEC10(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820EEC10){
  static bool en_on = std::getenv("RT_ENROLL")!=nullptr;
  if(!en_on){                                   // ship path: run once, capture the created cue
    uint32_t outslot = ctx.r7.u32;
    __imp__sub_820EEC10(ctx,base);
    t_last_created_wave = (outslot && outslot<0xF0000000u) ? PPC_LOAD_U32(outslot) : 0;
    return;
  }
  if(en_on){
    static std::atomic<long> cn{0}; long n=cn.fetch_add(1)+1;
    uint32_t bank=ctx.r3.u32, widx=ctx.r4.u32 & 0xFFFF, outslot=ctx.r7.u32;
    uint32_t eng=(bank&&bank<0xF0000000u)?PPC_LOAD_U32(bank+24u):0;
    int before=rt_enroll_listcount(base,eng);
    __imp__sub_820EEC10(ctx,base);
    uint32_t ret=ctx.r3.u32;
    uint32_t wave=(outslot&&outslot<0xF0000000u)?PPC_LOAD_U32(outslot):0;
    t_last_created_wave = wave;                 // same capture as the ship path above
    uint32_t vt=(wave&&wave<0xF0000000u)?PPC_LOAD_U32(wave):0;
    int after=rt_enroll_listcount(base,eng);
    bool streaming=(vt==0x82015690u);
    // One-shot vtable dump per distinct wave class: slots 0x28 (SetOutputVoices), 0x2c
    // (SetOutputMatrix), 0x30 (START/play), 0x4c (per-instance update DoWork calls), 0x50 (Initialize).
    if(vt && vt>=0x82000000u && vt<0x82400000u){
      static std::atomic<uint32_t> lastvt{0};
      if(lastvt.exchange(vt)!=vt){
        std::fprintf(stderr,"[enroll] VTABLE 0x%X FULL[0x00..0x60]:",vt);
        for(uint32_t o=0;o<=0x60u;o+=4){ uint32_t s=PPC_LOAD_U32(vt+o); std::fprintf(stderr," +0x%X=%08X",o,s); }
        std::fprintf(stderr,"\n");
      }
    }
    // Phase-3g class-root: dump the BANK's vtable[+0x50] (the format-source CreateWave reads byte0 bit
    // 0x2 from to pick streaming class) + bank object fields (looking for the WAVEBANKDATA dwFlags
    // streaming bit 0x1 that SHOULD propagate). BGM bank should be streaming; wave is base 0x82014688.
    if(bank && bank<0xF0000000u){
      static std::atomic<uint32_t> lastbank{0};
      if(lastbank.exchange(bank)!=bank){
        uint32_t bvt=PPC_LOAD_U32(bank);
        std::fprintf(stderr,"[enroll] BANK 0x%X vtable=0x%X [+0x10 Prep]=0x%08X [+0x48 hdrAcc]=0x%08X [+0x50 fmtSrc]=0x%08X\n",
          bank,bvt,(bvt&&bvt<0xF0000000u)?PPC_LOAD_U32(bvt+0x10u):0,(bvt&&bvt<0xF0000000u)?PPC_LOAD_U32(bvt+0x48u):0,(bvt&&bvt<0xF0000000u)?PPC_LOAD_U32(bvt+0x50u):0);
        // Follow SoundBank pointer fields (+0..0x120) hunting the referenced WaveBank: header magic
        // 'DNBW'(0x444E4257)/'WBND'(0x57424E44) with a nearby WAVEBANKDATA dwFlags 0x0008000x
        // (streaming bit0: BGM/SYS_BGM=0x00080001, SE=0x00080000). Report the field + where the flag is.
        std::fprintf(stderr,"[enroll]   WB-hunt:");
        for(uint32_t o=0;o<0x120u;o+=4){ uint32_t p=PPC_LOAD_U32(bank+o);
          if(p>=0x10000u && p<0xF0000000u){ uint32_t m=PPC_LOAD_U32(p);
            if(m==0x444E4257u||m==0x57424E44u){ std::fprintf(stderr," [bank+0x%X]->0x%X magic=0x%08X flags@+0x%X..:",o,p,m,0x8u);
              for(uint32_t k=0;k<0x40u;k+=4){ uint32_t w=PPC_LOAD_U32(p+k); if((w>>16)==0x0008u) std::fprintf(stderr," +0x%X=0x%08X",k,w); } }
            // also: does this pointer's region hold a 0x0008000x dwFlags directly?
            for(uint32_t k=0;k<0x30u;k+=4){ uint32_t w=PPC_LOAD_U32(p+k); if((w>>16)==0x0008u){ std::fprintf(stderr," [bank+0x%X]->0x%X +0x%X=0x%08X",o,p,k,w); break; } } } }
        std::fprintf(stderr,"\n");
      }
    }
    if(n<=400 || streaming || (n%500)==0)
      std::fprintf(stderr,"[enroll] CreateWave sub_820EEC10 #%ld bank=0x%X engine=0x%X waveIdx=%u -> ret=0x%X wave=0x%X vtable=0x%X%s | engine+0x58 list %d->%d\n",
        n,bank,eng,widx,ret,wave,vt,streaming?" <<STREAMING-BGM>>":"",before,after);
    return;
  }
  __imp__sub_820EEC10(ctx,base);
}
extern "C" void __imp__sub_820E8AC8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820E8AC8){
  static bool en_on = std::getenv("RT_ENROLL")!=nullptr;
  if(en_on){
    static std::atomic<long> en{0}; long n=en.fetch_add(1)+1;
    uint32_t eng=ctx.r3.u32, wave=ctx.r4.u32;
    uint32_t vt=(wave&&wave<0xF0000000u)?PPC_LOAD_U32(wave):0;
    int before=rt_enroll_listcount(base,eng);
    __imp__sub_820E8AC8(ctx,base);
    int after=rt_enroll_listcount(base,eng);
    bool streaming=(vt==0x82015690u);
    if(n<=400 || streaming || (n%500)==0)
      std::fprintf(stderr,"[enroll] ENROLL sub_820E8AC8 #%ld engine=0x%X wave=0x%X vtable=0x%X%s | engine+0x58 list %d->%d\n",
        n,eng,wave,vt,streaming?" <<STREAMING-BGM>>":"",before,after);
    return;
  }
  __imp__sub_820E8AC8(ctx,base);
}
// RT_ENROLL: hook the ACTUAL per-instance update = wave vtable[+0x4c] = sub_820ECC18 (the fn DoWork's
// engine+0x58 walk invokes on each enrolled wave; the prior report hooked sub_820ECBA0 which is a
// DIFFERENT class' slot -> measured 0 spuriously). r3=wave; inst=*(wave+0x38); the START gate reads
// state at inst+0x58 (==3 attaches, <4 defers). Count calls + watch inst+0x58 for advance. If this
// fires for the BGM wave (0x21560F0) but state never reaches 3, the streaming-readiness gate inside
// sub_820ECC18 (sub_820F7430/sub_820EF6C8 buffer-ready checks) is the stall.
extern "C" void __imp__sub_820ECC18(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820ECC18){
  static bool en_on = std::getenv("RT_ENROLL")!=nullptr;
  if(en_on){
    static std::atomic<long> u{0}; long n=u.fetch_add(1)+1;
    uint32_t wave=ctx.r3.u32;
    uint32_t inst=(wave&&wave<0xF0000000u)?PPC_LOAD_U32(wave+0x38u):0;
    uint32_t st=(inst&&inst<0xF0000000u)?PPC_LOAD_U32(inst+0x58u):0xFFFFFFFFu;
    __imp__sub_820ECC18(ctx,base);
    uint32_t st2=(inst&&inst<0xF0000000u)?PPC_LOAD_U32(inst+0x58u):0xFFFFFFFFu;
    if(n<=32 || (n%8000)==0 || st!=st2)
      std::fprintf(stderr,"[enroll] perInstUpd sub_820ECC18 #%ld wave=0x%X inst=0x%X state(inst+0x58) %u->%u\n",n,wave,inst,st,st2);
    return;
  }
  __imp__sub_820ECC18(ctx,base);
}

// RT_STREAMRDY (Phase-3g streaming-readiness LIVE-CONFIRM, default-OFF, read-only): the state 2->3
// gate is the PCM decoder ready-poll sub_82101670 (ready iff decode-queue count *(X+0x54)>1). The
// queue fills via submit sub_82101A40, which fetches the streaming source bank via
// sub_820EF3B0 -> sub_820E7858 (walks the engine+0x74 bank list; returns a bank ONLY if its ready
// flag *(bank+0x100)!=0 = loaded/ready). submit returns 0x8AC70013 (source not found) or 0x8AC70016
// (source's *(+0x100)==0) on failure, else calls source->vtable[+0x50] to pull staging->ring. Hook
// all three to prove WHERE BGM stalls: is submit erroring, is the bank list absent/unready
// (*(bank+0x100)==0), does the poll ever flip to 1? (byte offsets: decomp's [0x40] is an int* index
// = byte 0x100, confirmed in recomp `*(r+256)`.)
extern "C" void __imp__sub_82101A40(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_82101A40){
  static bool sr_on = std::getenv("RT_STREAMRDY")!=nullptr;
  if(sr_on){
    static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    uint32_t ch=ctx.r3.u32, idx=ctx.r4.u32;
    __imp__sub_82101A40(ctx,base);
    uint32_t ret=ctx.r3.u32;
    const char* tag = (ret==0x8AC70013u)?"ERR-source-not-found(0x8AC70013)":
                      (ret==0x8AC70016u)?"ERR-source-NOT-READY(0x8AC70016)":
                      ((int32_t)ret>=0)?"OK(pulled staging->ring)":"ERR-other";
    static std::atomic<long> e13{0},e16{0},ok{0};
    if(ret==0x8AC70013u) e13.fetch_add(1); else if(ret==0x8AC70016u) e16.fetch_add(1); else if((int32_t)ret>=0) ok.fetch_add(1);
    if(i<=40 || (i%4000)==0)
      std::fprintf(stderr,"[streamrdy] submit sub_82101A40 #%ld ch=0x%X idx=%u -> ret=0x%08X %s | totals: notfound=%ld notready=%ld ok=%ld\n",
        i,ch,idx,ret,tag,e13.load(),e16.load(),ok.load());
    return;
  }
  __imp__sub_82101A40(ctx,base);
}
extern "C" void __imp__sub_820E7858(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820E7858){
  static bool sr_on = std::getenv("RT_STREAMRDY")!=nullptr;
  if(sr_on){
    static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    uint32_t owner=ctx.r3.u32;
    char buf[512]; int p=0; buf[0]=0;
    if(owner && owner<0xF0000000u){
      uint32_t sent=owner+0x74u, nd=PPC_LOAD_U32(owner+0x78u); int c=0;
      while(nd && nd!=sent && nd<0xF0000000u && c<32){
        uint32_t bank=nd-8u; uint32_t rdy=(bank<0xF0000000u)?PPC_LOAD_U32(bank+0x100u):0xFFFFFFFFu;
        if(p<(int)sizeof(buf)-40) p+=std::snprintf(buf+p,sizeof(buf)-p,"[bank=0x%X rdy(+0x100)=%u]",bank,rdy);
        nd=PPC_LOAD_U32(nd+4u); ++c;
      }
      if(c==0) std::snprintf(buf,sizeof(buf),"(engine+0x74 list EMPTY)");
    }
    __imp__sub_820E7858(ctx,base);
    uint32_t ret=ctx.r3.u32;
    if(i<=40 || (i%4000)==0)
      std::fprintf(stderr,"[streamrdy] bankLookup sub_820E7858 #%ld owner=0x%X -> ret=0x%X (%s) | banks: %s\n",
        i,owner,ret,ret?"FOUND":"NOT-FOUND",buf);
    return;
  }
  __imp__sub_820E7858(ctx,base);
}
extern "C" void __imp__sub_82101670(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_82101670){
  static bool sr_on = std::getenv("RT_STREAMRDY")!=nullptr;
  if(sr_on){
    static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    __imp__sub_82101670(ctx,base);
    uint32_t ret=ctx.r3.u32;
    static std::atomic<long> ready{0}; if(ret) ready.fetch_add(1);
    if(i<=8 || (i%16000)==0)
      std::fprintf(stderr,"[streamrdy] readyPoll sub_82101670 #%ld -> %u %s (cumulative-ready=%ld)\n",
        i,ret,ret?"<<READY: queue>1>>":"not-ready(queue<=1)",ready.load());
    return;
  }
  __imp__sub_82101670(ctx,base);
}
// RT_STREAMRDY: the authoritative state-advance sub_820F6990 (decomp FUN_820f6990): if
// waveinst+0x28==2 AND subvoice(+0x24)->vtable[+0x18]() (the ready-poll) !=0 -> state=3; then if
// flag(+0x20)&0x40 && state==3 -> clear 0x40 + call FUN_820f6328 (the deferred-attach retrigger).
// Hook it to see PER waveinst whether state advances 2->3 (offsets confirmed in recomp: +40/+36/+32).
extern "C" void __imp__sub_820F6990(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820F6990){
  static bool sr_on = std::getenv("RT_STREAMRDY")!=nullptr;
  static bool bp_on = std::getenv("RT_BGMPROBE")!=nullptr;   // PATCH (c)/(d) probe, read-only
  if(sr_on || bp_on){
    static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    uint32_t inst=ctx.r3.u32;
    bool ok=inst && inst<0xF0000000u;
    uint32_t st0=ok?PPC_LOAD_U32(inst+0x28u):0xFFFFFFFFu, sub=ok?PPC_LOAD_U32(inst+0x24u):0, fl0=ok?PPC_LOAD_U32(inst+0x20u):0;
    __imp__sub_820F6990(ctx,base);
    uint32_t st1=ok?PPC_LOAD_U32(inst+0x28u):0xFFFFFFFFu, fl1=ok?PPC_LOAD_U32(inst+0x20u):0;
    static std::atomic<long> adv{0}; if(st0==2&&st1==3) adv.fetch_add(1);
    if(sr_on && (i<=48 || st0!=st1 || fl0!=fl1 || (i%8000)==0))
      std::fprintf(stderr,"[streamrdy] stateAdv sub_820F6990 #%ld inst=0x%X subvoice=0x%X state(+0x28) %u->%u flag(+0x20) 0x%X->0x%X (cum 2->3=%ld)\n",
        i,inst,sub,st0,st1,fl0,fl1,adv.load());
    if(bp_on && (st0!=st1 || i<=64 || (i%2000)==0))
      std::fprintf(stderr,"[bgmprobe.cd] FUN_820f6990 #%ld sv=0x%X state %u->%u flag0=0x%02X (advance=%d)\n",
        i,inst,st0,st1,(unsigned)(fl0&0xFFu),(int)(st0!=st1));
    return;
  }
  __imp__sub_820F6990(ctx,base);
}
extern "C" void __imp__sub_820F6328(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820F6328){
  static bool sr_on = std::getenv("RT_STREAMRDY")!=nullptr;
  static bool bp_on = std::getenv("RT_BGMPROBE")!=nullptr;   // PATCH (c)/(d) probe, read-only
  if(sr_on || bp_on){
    static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    uint32_t sv=ctx.r3.u32; bool ok=sv&&sv<0xF0000000u;
    uint32_t st  = ok?PPC_LOAD_U32(sv+0x28u):0;
    uint8_t  fl  = ok?PPC_LOAD_U8 (sv+0x20u):0;
    uint8_t  cnt = ok?PPC_LOAD_U8 (sv+0x18u):0;   // send/source-buffer count (5th dep)
    if(sr_on && (i<=32 || (i%2000)==0)) std::fprintf(stderr,"[streamrdy] attachRetrigger sub_820F6328 #%ld inst=0x%X\n",i,sv);
    if(bp_on && (i<=64||(i%2000)==0))
      std::fprintf(stderr,"[bgmprobe.cd] FUN_820f6328 #%ld sv=0x%X state(+0x28)=%u flag(+0x20)=0x%02X sendCount(+0x18)=%u %s\n",
        i,sv,st,fl,cnt, (st==3)?((cnt!=0)?"=>CREATE":"=>state3-but-EMPTY-sendlist(5th-dep-FAIL)"):"=>arm0x40(defer)");
    __imp__sub_820F6328(ctx,base);
    return;
  }
  __imp__sub_820F6328(ctx,base);
}
// RT_STREAMRDY: the CUE-INSTANCE update sub_820FC8B8 (decomp FUN_820fc8b8) — THE driver of the
// deferred attach: at its tail it calls FUN_820ecba0 + FUN_820f8168 for each active sub-wave
// (cue+0x1AC/0x1B0/0x1B4) -> sub_820FB148 -> sub_820F6990 (state 2->3 + attach). It has NO static
// caller (indirect vtable dispatch on a cue-instance). If this count is 0 in-field, the cue-instance
// pump the port needs is undriven (the drivable gap). state at cue+0x1C0 (int idx 0x70).
extern "C" void __imp__sub_820FC8B8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820FC8B8){
  static bool sr_on = std::getenv("RT_STREAMRDY")!=nullptr;
  if(sr_on){
    static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    uint32_t cue=ctx.r3.u32; bool ok=cue&&cue<0xF0000000u;
    uint32_t st=ok?PPC_LOAD_U32(cue+0x1C0u):0;
    uint32_t w6b=ok?PPC_LOAD_U32(cue+0x1ACu):0, w6c=ok?PPC_LOAD_U32(cue+0x1B0u):0, we=ok?PPC_LOAD_U32(cue+0x38u):0;
    if(i<=32||(i%4000)==0)
      std::fprintf(stderr,"[streamrdy] cueUpd sub_820FC8B8 #%ld cue=0x%X state(+0x1C0)=%u subwaves[+0x1AC]=0x%X[+0x1B0]=0x%X[+0x38]=0x%X\n",i,cue,st,w6b,w6c,we);
    __imp__sub_820FC8B8(ctx,base);
    return;
  }
  __imp__sub_820FC8B8(ctx,base);
}

// RT_STREAMCLASS (Phase-3i EXPERIMENTAL causal-chain confirm, default-OFF, AUDIO-ONLY): the BGM
// SoundBank (bt=0 = *(0x885C5BB4)) is a STREAMING bank (BGM.xwb WAVEBANKDATA dwFlags bit0=1), but the
// port builds its waves as the IN-MEMORY base class 0x82014688 because the per-wave descriptor byte0
// streaming bit (0x2) is CLEAR — so CreateWave's class-select (byte0 & 0x2) misses the streaming class
// 0x82015690 whose tick self-drives the deferred attach. FORCE it: hook the bank's format-source
// sub_820F14A8 (vtable[+0x50], returns the descriptor CreateWave reads byte0 from) and set byte0 bit
// 0x2 for the BGM bank. This makes CreateWave build 0x82015690 for BGM waves. Proves class->deferred-
// attach->sound before the clean loader-side fix (which should set this bit from the WaveBank dwFlags
// at SoundBank load). Read-mostly (only ORs one bit on the BGM bank's own descriptor).
// RT_STREAMCLASS diag: the streaming class 0x82015690 DoWork tick (vtable+0x4c=sub_820FD530) and its
// START (vtable+0x30=sub_820FBF00). Confirm the forced streaming object is well-formed (sub-waves at
// +0x1AC/+0x1B0/+0x1B4) and actually ticked/played — to pin whether the "no sound" is a half-init
// streaming object vs the still-missing cue-instance scheduler (sub_820FC8B8).
// PATCH (b) DRIVE THE STREAMING CUE-INSTANCE TICK (RT_BGMFIX ship path). DoWork FUN_820e8f88 walks
// engine+0x58 and calls each streaming object's vtable[+0x4c]=sub_820FD530 (pump) but NEVER its
// vtable[+0x48]=sub_820FC8B8 (the cue tick that drives sub_820f8168->sub_820f6990 state 2->3 + the
// deferred attach). Register-true observable-equivalent drive: after the real pump, invoke the same
// object's own +0x48 cue tick. Inert until (a) makes BGM the streaming class 0x82015690.
extern "C" void __imp__sub_820FD530(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820FD530){
  static bool fix  = std::getenv("RT_BGMFIX")!=nullptr;
  static bool diag = std::getenv("RT_STREAMCLASS")!=nullptr;
  static bool cued = std::getenv("RT_CUEDRIVE")!=nullptr; // legacy manual A/B
  static bool bp   = std::getenv("RT_BGMPROBE")!=nullptr;
  uint32_t o=ctx.r3.u32; bool ok=o&&o<0xF0000000u;
  if(diag||bp){ static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    if(i<=24||(i%8000)==0) std::fprintf(stderr,
      "[streamclass] tick sub_820FD530 #%ld obj=0x%X st(+0x174)=%u pumpArm(+0x188)=%u (+0x178)=%u (+0x1b8s)=0x%04X sub[+0x1AC]=0x%X[+0x1B0]=0x%X[+0x1B4]=0x%X (+0x1C0)=%u (+0x44)=%u\n",
      i,o,ok?PPC_LOAD_U32(o+0x174u):0,ok?PPC_LOAD_U32(o+0x188u):0,ok?PPC_LOAD_U32(o+0x178u):0,ok?PPC_LOAD_U16(o+0x1b8u):0,
      ok?PPC_LOAD_U32(o+0x1ACu):0,ok?PPC_LOAD_U32(o+0x1B0u):0,
      ok?PPC_LOAD_U32(o+0x1B4u):0,ok?PPC_LOAD_U32(o+0x1C0u):0,ok?PPC_LOAD_U32(o+0x44u):0);
  }
  __imp__sub_820FD530(ctx,base);
  // CODE_REVIEW_0804: reentrant call on a CONTEXT COPY — the old form ran sub_820FC8B8 on the
  // live ctx and replaced sub_820FD530's own r3 return value with the pump's (every other
  // reentrant call in these files already uses the ic-copy pattern).
  if((fix || cued || diag) && ok){ PPCContext ic=ctx; ic.r3.u64=o; __imp__sub_820FC8B8(ic,base); }
}
extern "C" void __imp__sub_820FBF00(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820FBF00){
  static bool on = std::getenv("RT_STREAMCLASS")!=nullptr || std::getenv("RT_BGMPROBE")!=nullptr;
  if(on){ static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    uint32_t o=ctx.r3.u32; uint32_t arg=ctx.r4.u32; bool ok=o&&o<0xF0000000u;
    if(i<=24) std::fprintf(stderr,"[bgmprobe.start] +0x30 sub_820FBF00 #%ld obj=0x%X arg=%u st(+0x174)=%u vt=0x%X\n",
      i,o,arg,ok?PPC_LOAD_U32(o+0x174u):0,ok?PPC_LOAD_U32(o):0);
    __imp__sub_820FBF00(ctx,base); return; }
  __imp__sub_820FBF00(ctx,base);
}
// RT_BGMPROBE (START-lifecycle leg): the STREAMING PLAY = streaming class 0x82015690 vtable[+0x00] =
// sub_820FD700 (decomp FUN_820fd700): gate st(+0x174)==4 && +0x178==0, then FUN_820FD480 arms the pump
// (+0x188=1), st(+0x174)->8, calls vt+0x84. This is the 4->8 (Prepared->Playing) transition the prior
// leg found MISSING (cue stuck; pump never allocates sub-waves). Is it EVER called for the BGM obj? If
// never -> PLAY is a dropped dispatch (same family as DoWork/cue-tick). If called-but-bails -> which gate.
extern "C" void __imp__sub_820FD700(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820FD700){
  static bool bp = std::getenv("RT_BGMPROBE")!=nullptr;
  if(bp){ static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    uint32_t o=ctx.r3.u32; bool ok=o&&o<0xF0000000u;
    uint32_t st0=ok?PPC_LOAD_U32(o+0x174u):0, s178=ok?PPC_LOAD_U32(o+0x178u):0;
    __imp__sub_820FD700(ctx,base);
    uint32_t st1=ok?PPC_LOAD_U32(o+0x174u):0, arm=ok?PPC_LOAD_U32(o+0x188u):0;
    if(i<=24) std::fprintf(stderr,"[bgmprobe.play] PLAY +0x00 sub_820FD700 #%ld obj=0x%X st(+0x174) %u->%u (+0x178)=%u pumpArm(+0x188)=%u ret=0x%X\n",
      i,o,st0,st1,s178,arm,ctx.r3.u32);
    return; }
  __imp__sub_820FD700(ctx,base);
}
// RT_BGMPROBE: STREAMING Prepare = 0x82015690 vtable[+0x50] = sub_820FCD18 (FUN_820fcd18): st 1->2->4,
// alloc decoders, FUN_820FC6D8 stream-source. Confirms the BGM obj reaches Prepared(4). +0x1b8 = stream
// index (ctor sets 0xffff; FUN_820fd160 needs it != -1 to alloc a sub-wave).
extern "C" void __imp__sub_820FCD18(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820FCD18){
  static bool bp = std::getenv("RT_BGMPROBE")!=nullptr;
  if(bp){ static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    uint32_t o=ctx.r3.u32; bool ok=o&&o<0xF0000000u;
    __imp__sub_820FCD18(ctx,base);
    if(i<=24) std::fprintf(stderr,"[bgmprobe.prep] Prepare +0x50 sub_820FCD18 #%ld obj=0x%X st(+0x174)=%u (+0x1b8short)=0x%04X (+0x180)=0x%X ret=0x%X\n",
      i,o,ok?PPC_LOAD_U32(o+0x174u):0,ok?(PPC_LOAD_U16(o+0x1b8u)):0,ok?PPC_LOAD_U32(o+0x180u):0,ctx.r3.u32);
    return; }
  __imp__sub_820FCD18(ctx,base);
}
// RT_BGMPROBE: bank/SoundBank PREPARE = sub_820EEE00 (FUN_820eee00, bank vtable[+0x10]): the crux's
// PREPARE. Per ATLAS it does engine.vt+0xc CreateWave (=sub_820EEC10: build class + wave+0x50 Init +
// ENROLL) then wave+0x30 START (arg=(outPtr==0)). If this runs for BGM, the created wave's +0x30 fires
// -> streaming PLAY. Report entry + created-wave vtable to decide if the START leg is reached at all.
// ===== BETA AUDIO 2026-07-31 — THE SHELL-SIDE CUE DISPATCH (T2: SYS_SE / SYS_BGM) ===============
// sub_820EEE00 is IXACT3SoundBank::Prepare(cueIndex,...) — proven, not assumed: its own bounds
// check reads numSimpleCues at hdr+0x13 / numComplexCues at hdr+0x15 of the object returned by the
// bank's vtable[+0x48], and the sibling accessors FUN_820f0d18/FUN_820f0d78 add hdr+0x22 / hdr+0x26
// to it — the exact .xsb SoundBank header layout (see rt_xwma.cpp's parser comment). Every prepared
// cue funnels through here:
//   * the GAME's three banks (BGM/SE/VOICE) arrive via the crux sub_88090588 -> handler vtable+0x10;
//   * the SHELL's own banks (SYS_SE menu SFX, SYS_BGM menu music) arrive here and NOWHERE else —
//     they carry no bankType in the game cue table, which is exactly why nothing has ever routed
//     them to a speaker (NOTE_audio_xwma_decoder.md "what is NOT done" item 3).
// So this one site is a strict superset of the old crux dispatch AND it has the cue index in hand,
// which the .xsb turns into the RIGHT wave (identity is wrong for 11/13 BGM cues and 6/7 SYS_SE).
// Lever: RT_CUEBRIDGE=0 -> inert here, crux keeps dispatching (pre-07-31 behaviour). Read-only
// w.r.t. guest state; the real Prepare runs exactly once either way.
extern "C" void        rt_audio_bridge_play_cue(const char* sbName, int cueIndex);
extern "C" void        rt_audio_bridge_play_cue_h(const char* sbName, int cueIndex,
                                                  unsigned cueObj, unsigned bankPtr);
extern "C" int         rt_audio_bridge_enabled(void);
extern "C" int         rt_audio_cuebridge_enabled(void);
extern "C" const char* rt_xsb_identify(const unsigned char* hdr, int len);

// bank object -> .xsb basename. The SoundBank keeps the mapped .xsb image in one of its pointer
// fields; find it by its 'KBDS' magic and identify the file by an exact byte-prefix match against
// the five shipped banks (rt_xsb_identify falls back to the unique cue-count pair). Resolved once
// per object; a bank that cannot be identified is cached as "unknown" and never re-scanned.
static const char* rt_sb_name(uint8_t* base, uint32_t bank){
  if(!bank || bank>=0xF0000000u) return nullptr;
  struct Ent { uint32_t obj; const char* name; };
  static std::mutex m;
  static std::vector<Ent> cache;
  {
    std::lock_guard<std::mutex> l(m);
    for(auto& e : cache) if(e.obj==bank) return e.name;
  }
  const char* found=nullptr; uint32_t at=0;
  for(uint32_t o=0;o<0x140u;o+=4){
    uint32_t p=PPC_LOAD_U32(bank+o);
    if(p<0x10000u || p>=0xF0000000u) continue;
    if(PPC_LOAD_U32(p)!=0x4B424453u) continue;        // 'KBDS' = the .xsb image, mapped verbatim
    at=p; found = rt_xsb_identify(base+p, 64);
    if(found) break;
  }
  {
    std::lock_guard<std::mutex> l(m);
    cache.push_back({bank,found});
  }
  std::fprintf(stderr,"[cue] SoundBank 0x%X -> %s (xsb image @0x%X)\n",
               bank, found?found:"UNIDENTIFIED", at);
  return found;
}

// ===== BETA AUDIO 2026-07-31 — THE CUE-STOP DISPATCH (user defects: menu music bleeds into the
// ===== ROM after mode select, and into attract) ==================================================
// GUEST-TRUTHFUL SITE, established from the decomp — no host timer, no synthetic fade:
//   * IXACT3SoundBank::Stop = FUN_820ef018 (the function-table entry immediately after Prepare's
//     0x820EEE00) -> FUN_820e8b98(engine, bank, cueIndex, immediate, wait).
//   * FUN_820e8b98 walks the engine's active-instance list (piVar3+0x16/0x17 == engine+0x58/+0x5c,
//     the same list DoWork walks), matches the node on bank and cueIndex, and stops each match with
//         (**(code **)(*piVar8 + 4))(piVar8, immediate)
//     i.e. **wave vtable[+0x04]**, which for the in-memory cue class 0x82014688 (vtables.txt) is
//     **sub_820EC958** — confirmed by decompile: takes the engine lock, checks state via
//     vtable[+0x34], sets this[0x11] to 0 (release) or 2 (immediate), then FUN_820f80b0 stops the
//     voices. Every stop funnels through it, whether it came from SoundBank::Stop or from a cue
//     handle the shell kept out of Prepare — exactly as sub_820EEE00 is the single PREPARE funnel.
// IDENTITY comes from the guest's own fields, read the way its own walker reads them: relative to
// the wave object (= link - 12, since the intrusive link lives at wave+0xC),
//     bank   = *(u32*)(wave + 0x134)     (walker: piVar5[0x4a])
//     cueIdx = *(u16*)(wave + 0x13C)     (walker: *(ushort*)(piVar5 + 0x4c))
// SELF-VALIDATING: the bank pointer is only accepted if it resolves through rt_sb_name() — i.e. it
// must point at a resident image whose bytes prefix-match a shipped .xsb. If these offsets were
// ever wrong the lookup simply fails and we do nothing (today's behaviour), rather than stopping
// the wrong sound. Lever: RT_CUESTOP=0.
extern "C" void rt_audio_bridge_stop_cue(const char* sbName, int cueIndex, int immediate);
extern "C" int  rt_audio_cuestop_enabled(void);
extern "C" void rt_audio_set_category_volume(int cat, double vol);

// RT_STOPTRACE (diagnostic, default-OFF): the 07-31 stop gate showed the menu BGM playing straight
// through a ROM load with sub_820EC958 never firing, so trace ALL THREE layers of the stop
// machinery at once and let the log say which one the shell actually uses:
//   sub_820EF018 = IXACT3SoundBank::Stop(cueIndex, flags)   [the public API]
//   sub_820E8B98 = the engine stop-by-(bank,cue) walker      [what Stop calls]
//   sub_820EC958 = wave/cue vtable[+0x04] Stop               [what the walker calls per instance]
// Also traces sub_820F80B0 (the voice-level stop the cue Stop delegates to) — if THAT fires while
// the three above do not, the shell is stopping voices by a path that bypasses the cue object.
extern "C" void __imp__sub_820EF018(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820EF018){
  if(std::getenv("RT_STOPTRACE")){
    static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    if(i<=40) std::fprintf(stderr,"[stoptrace] SoundBank::Stop sub_820EF018 #%ld bank=0x%X cueIdx=%u flags=0x%X lr=0x%X\n",
                           i,ctx.r3.u32,ctx.r4.u32&0xFFFFu,ctx.r5.u32,(uint32_t)ctx.lr);
  }
  __imp__sub_820EF018(ctx,base);
}
extern "C" void __imp__sub_820E8B98(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820E8B98){
  if(std::getenv("RT_STOPTRACE")){
    static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    if(i<=40) std::fprintf(stderr,"[stoptrace] engine stop-walker sub_820E8B98 #%ld eng=0x%X bank=0x%X cueIdx=%u imm=%u wait=%u lr=0x%X\n",
                           i,ctx.r3.u32,ctx.r4.u32,ctx.r5.u32&0xFFFFu,ctx.r6.u32,ctx.r7.u32,(uint32_t)ctx.lr);
  }
  __imp__sub_820E8B98(ctx,base);
}
// ★ 2026-08-02 DESTROY-CHAIN TALLY (ghost-voice hunt, gated on RT_VOICECENSUS). The stop-slot
// tally proved the game issues stops 1:1 with plays yet stolen voices keep ringing (digital A/B:
// x6 in the guest mix vs the SDK). Tallies every hop of the decomp'd chain
// (ghidra_futari_decomp/destroy_chain.txt): cueDestroy 0x820EC8F8 / cueStop 0x820EC958 ->
// waveStop 0x820F80B0 -> instStop 0x820FA218 -> mixStop 0x820F66C8 -> mixKill 0x820F5E80.
// The FIRST hop whose rate drops below the stop-slot rate is the fork; its guard names the
// culprit field. Wrapper bodies further down; two hops tally inside pre-existing hooks.
static std::atomic<long> g_dchain[6];
static bool rt_dchain_on(){
  static bool on = [](){ const char* e=std::getenv("RT_VOICECENSUS"); return e && e[0]=='1' && !e[1]; }();
  return on;
}
static void rt_dchain_tally(int i, const char* nm, PPCContext& ctx){
  if(!rt_dchain_on()) return;
  long n=g_dchain[i].fetch_add(1)+1;
  if(n<=4 || (n%256)==0)
    std::fprintf(stderr,"[dchain] %s #%ld r3=0x%X r4=0x%X lr=0x%X\n",
                 nm,n,(unsigned)ctx.r3.u32,(unsigned)ctx.r4.u32,(uint32_t)ctx.lr);
}
extern "C" void __imp__sub_820F80B0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820F80B0){
  rt_dchain_tally(2,"waveStop",ctx);
  if(std::getenv("RT_STOPTRACE")){
    static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    if(i<=40) std::fprintf(stderr,"[stoptrace] voice-stop sub_820F80B0 #%ld inst=0x%X imm=%u lr=0x%X\n",
                           i,ctx.r3.u32,ctx.r4.u32,(uint32_t)ctx.lr);
  }
  __imp__sub_820F80B0(ctx,base);
}

// ---- THE SHELL'S OWN VOLUME LAYER (2026-07-31, referee correction) -----------------------------
// The user's referee (real HW + Xenia + the SDK build) says TOP MENU MUSIC IS AUDIBLE, so the
// cat3/cat6=0.0 snapshot my slot-18 trace caught is NOT the steady state. The decomp says why:
//   FUN_821caa60 = SetCategoryVolume(const char* categoryName, double volume) — matches the name
//     against the category table at DAT_821f857c[0x91..0x95] (stride 0x1c), caches the value at
//     [0x97]+idx, then calls engine vtable +0x40 GetCategory(name) and +0x48 SetVolume(cat, vol).
//   FUN_821cac08 = a PER-FRAME FADE TICK over the same 0x1c-stride table: +0x120 = fade duration,
//     +0x124 = frames remaining (decremented each tick), +0x118 = the ramp source; when a fade
//     completes it snaps to DAT_8204f828, otherwise it feeds (src * remaining / duration).
// So category volume here is DYNAMIC and FADE-DRIVEN, which is exactly why neither static lever
// setting reproduces the real behaviour. (sound.xgs settles the other hypothesis: numRPCs = 0 and
// all 7 variables are XACT built-ins, so there is no RPC/global-variable curve in this project.)
// This trace logs the NAME-level truth: which category, what volume, from where.
// ★ THE DIVERGENCE, measured: SetCategoryVolume("SE"/"SYS_SE"/"VOICE", 1.0) each produce an engine
// SetVolume; **"BGM" and "SYS_BGM" produce NONE**. The decomp says why — on a name match the
// function caches the value at [0x97]+idx and then `if (DAT_821f857c[0x9d] != 0) return;` BEFORE
// the engine GetCategory/SetVolume tail. So the shell owns music volume in its OWN table and the
// engine copy stays at whatever the fade tick last pushed (0.0, from boot). The shell's cached
// value is therefore the guest's real INTENT for music, and it is what the bridge must follow.
// Hooked by NAME, so there is no category-index ambiguity at all.
extern "C" void rt_audio_set_category_volume_named(const char* name, double vol);
extern "C" void rt_audio_set_category_fade(int cat, double vol);
extern "C" void __imp__sub_821CAA60(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821CAA60){
  uint32_t p=ctx.r3.u32;
  const char* nm = (p && p<0xF0000000u) ? (const char*)(base+p) : nullptr;
  // ★ 2026-08-02 SE LEVEL MATCH vs the reference build (user A/B: "we can hear our bullet shots,
  // SDK you can barely hear them"; user then chose the reference's level as the target).
  //
  // MEASURED GAP (attract-demo A/B, _tmpscripts/shotlevel_attract*.{ps1,sh} + attract_segments.py):
  // the attract demo plays continuous shot SFX with NO music and runs identically on both builds,
  // and its silent/active segment DURATIONS matched in lockstep (47.1s / 4.1s / 5.7s / 23.1s), so
  // the two captures are directly comparable. Per-segment p50 peak, port vs reference:
  //     0.50930/0.05808  0.49038/0.08612  0.51185/0.05576  0.48762/0.06828
  //   mean port 0.49979, mean reference 0.06706  =>  k = 0.1342  (-17.4 dB)
  // Our peak hit 0.957 (-0.38 dBFS, essentially clipping) against the reference's 0.196.
  // This supersedes the 0.42 from the 08-01 leg (rt_audio.cpp:645-657): that figure was taken with
  // a different instrument in the era when music came from the host bridge, and today's direct
  // same-instrument A/B does not reproduce it. Cross-era numbers are not comparable.
  //
  // WHY HERE, and not a host trim: sub_821CAA60 is XACT SetCategoryVolume(const char* name, double
  // vol) -- decomp default_decomp_all.txt:221831-221908, name matched against the category table,
  // cached at [0x97]+idx, then engine vtable+0x40 GetCategory / +0x48 SetVolume(vol). It is a
  // per-category gain INSIDE the guest's XACT engine, upstream of the mix, so scaling "SE"/"SYS_SE"
  // by NAME cannot touch BGM/SYS_BGM -- whereas a host-side scalar (rt_sfx_cal at rt_audio.cpp:1404)
  // is now a MASTER trim, because since the XMP fix the guest renders music into the same frame,
  // and would duck the music the user has already approved. It is also the exact lever the in-game
  // OPTIONS->SOUND->SE slider drives (FUN_82189158(1,value) -> FUN_821caa60), so the slider keeps
  // working proportionally.
  // ⚠ Music safety rests on the NAME TEST ALONE. The comment above about BGM producing no engine
  // call is a PRE-XMP-FIX observation: the early return there is `if (DAT_821f857c[0x9d] != 0)`,
  // the very mute latch the XMP stub fix cleared, so it can no longer be relied on.
  // Scaled BEFORE the bridge notification below so the host bridge and the guest engine agree if
  // the bridge is ever armed for SE (RT_BRIDGESE=1).
  //
  // ★★ 2026-08-02 USER RULING — DEFAULT IS 1.0, i.e. NO TRIM. "All levels should be cleared up
  // and mirror the decomp/truth." A 0.1342 constant is a fudge factor, and the matching-decomp
  // doctrine forbids shipping it: the reference build runs the SAME recompiled guest code with a
  // memcpy host, so if our shots render +17 dB over it the cause is MECHANICAL (something host-
  // side feeds the guest different inputs) and must be found, not calibrated away. The measured
  // gap and the A/B method above stay valid as EVIDENCE; RT_SEGAIN=<float> stays as the
  // DIAGNOSTIC lever (e.g. RT_SEGAIN=0.1342 reproduces the reference level for ear comparison).
  static const float segain = [](){ const char* e=std::getenv("RT_SEGAIN");
                                    float f = e ? (float)std::atof(e) : 1.0f;
                                    return (f>0.0f && f<=4.0f) ? f : 1.0f; }();
  if(nm && segain!=1.0f && (!std::strcmp(nm,"SE") || !std::strcmp(nm,"SYS_SE"))){
    const double before = (double)ctx.f1.f64;
    ctx.f1.f64 = before * (double)segain;
    static std::atomic<long> sg{0}; long si=sg.fetch_add(1)+1;
    if(si<=8) std::fprintf(stderr,"[segain] SetCategoryVolume(\"%s\") %.4f x%.4f -> %.4f  (RT_SEGAIN=1 reverts)\n",
                           nm,before,(double)segain,(double)ctx.f1.f64);
  }
  if(std::getenv("RT_STOPTRACE")){
    static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    if(i<=80) std::fprintf(stderr,"[volt] SetCategoryVolume(\"%s\", %.3f) lr=0x%X\n",
                           nm?nm:"(null)",(double)ctx.f1.f64,(uint32_t)ctx.lr);
  }
  if(nm && rt_audio_bridge_enabled() && rt_audio_cuebridge_enabled())
    rt_audio_set_category_volume_named(nm,(double)ctx.f1.f64);
  __imp__sub_821CAA60(ctx,base);
}
// ★ RT_FADETRACE=1 (2026-07-31) — THE FADE TICK ITSELF, which was never hooked.
// Referee measurement: on hardware the menu music does NOT hard-stop at the mode handover, it
// FADES over ~1.9 s (Xenia, per-process meter at 20 Hz: -6.7 dBFS at t=26.14 ramping smoothly to
// -73 dBFS at t=28.06, then digital zero). Our build cuts dead on the guest's cue teardown, which
// is what the user hears as "weird and abrupt".
// We are structurally BLIND to such a fade: the by-name hook (sub_821CAA60) only fires when the
// shell explicitly CALLS SetCategoryVolume, and the engine path is gated for BGM/SYS_BGM by
// DAT_821f857c[0x9d] — so a ramp written straight into the shell's own table by this per-frame
// tick reaches neither hook. This dumps the raw 0x1c-stride category entries so the ramp can be
// SEEN rather than inferred. Default off => byte-identical.
extern "C" void __imp__sub_821CAC08(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821CAC08){
  static const bool ft = std::getenv("RT_FADETRACE") != nullptr;
  // ★ RT_MUTETRACE (2026-08-01) — see the block comment above sub_821CA1B8's neighbours: the tail
  // of THIS tick is a mute/unmute latch keyed on an app-state word, and [stoptrace] showed cats
  // 3/6 pushed to 0.000 once from lr=0x821CAE0C and never restored. Print that word and the latch
  // once a second so "is the shell muting because it thinks we are inactive?" is a measurement.
  if(std::getenv("RT_MUTETRACE")){
    static std::atomic<long> mn{0}; long mi=mn.fetch_add(1)+1;
    if((mi % 60) == 1 && mi <= 60*180){
      uint32_t root = PPC_LOAD_U32(0x821F8588u);
      uint32_t st   = (root && root<0xF0000000u) ? PPC_LOAD_U32(root+0x4Cu) : 0;
      uint32_t o48  = (st   && st  <0xF0000000u) ? PPC_LOAD_U32(st  +0x48u) : 0;
      uint32_t flag = (o48  && o48 <0xF0000000u) ? PPC_LOAD_U32(o48 +0x2Cu) : 0xFFFFFFFFu;
      uint32_t tbl  = PPC_LOAD_U32(0x821F857Cu);
      uint32_t latch= (tbl  && tbl <0xF0000000u) ? PPC_LOAD_U32(tbl + 0x9Du*4u) : 0xFFFFFFFFu;
      std::fprintf(stderr,"[mutetrace] tick#%ld appstate=0x%X (root=0x%X st=0x%X o48=0x%X) mutelatch=%u\n",
                   mi,flag,root,st,o48,latch);
      // IDENTIFY the object that owns the gate word: dword 0 is its vtable, which maps to a name in
      // ghidra_futari_decomp/asm_vtables.txt. Knowing the class is what turns "who writes +0x2c"
      // from a text search into a lookup. Printed once.
      if(mi==1 && o48 && o48<0xF0000000u){
        std::fprintf(stderr,"[mutetrace] o48 obj dump vt=0x%X |",PPC_LOAD_U32(o48));
        for(int k=1;k<16;k++) std::fprintf(stderr," +%02X=%08X",k*4,PPC_LOAD_U32(o48+(uint32_t)k*4u));
        std::fprintf(stderr,"\n");
      }
    }
  }
  if(ft){
    // ASSUMPTION-FREE: an earlier guess at the entry layout (r3+0x10c, stride 0x1c) produced
    // pointer-looking words, so instead of trusting any offset we DIFF the candidate regions
    // per tick and report which dwords move. A volume ramp shows up as a dword whose float
    // reading slides monotonically between 1.0 and 0.0 across consecutive ticks.
    static std::atomic<long> nn{0}; long call=nn.fetch_add(1)+1;
    static long printed = 0;
    struct Region { uint32_t addr; const char* tag; };
    uint32_t glob = PPC_LOAD_U32(0x821F857Cu);          // DAT_821f857c, likely a manager pointer
    Region regs[3] = { { 0x821F857Cu, "glob" },
                       { (glob && glob < 0xF0000000u) ? glob : 0u, "mgr" },
                       { ctx.r3.u32 < 0xF0000000u ? ctx.r3.u32 : 0u, "r3" } };
    static uint32_t prev[3][192]; static bool primed = false;
    for(int r=0;r<3;r++){
      if(!regs[r].addr) continue;
      for(int k=0;k<192;k++){
        uint32_t w = PPC_LOAD_U32(regs[r].addr + (uint32_t)k*4u);
        if(primed && w != prev[r][k] && printed < 3000 && call > 400){
          float fn, fo; std::memcpy(&fn,&w,4); std::memcpy(&fo,&prev[r][k],4);
          // A volume ramp is a dword where BOTH readings are floats in [0,1] and at least one is
          // strictly fractional. That excludes pointers, counters, and the 0<->1 integer churn
          // (0x00000000 also reads as 0.0f, which swamped the first attempt).
          // ...and DENORMALS must be excluded too: a monotonically climbing counter like
          // 0x00003018 reads as ~1.7e-41, which is technically in (0,1) and swamped attempt two.
          auto ok   = [](float v){ return v==0.f || (v>=1e-4f && v<=1.0f); };
          bool inR  = ok(fn) && ok(fo);
          bool frac = (fn>1e-4f && fn<0.9999f) || (fo>1e-4f && fo<0.9999f);
          if(inR && frac){
            std::fprintf(stderr,"[fade] call%ld %s+0x%03X %08X->%08X  %.4f -> %.4f\n",
                         call, regs[r].tag, k*4, prev[r][k], w, (double)fo, (double)fn);
            ++printed;
          }
        }
        prev[r][k] = w;
      }
    }
    primed = true;
  }
  __imp__sub_821CAC08(ctx,base);
}
// The two fade-tick outcomes: FUN_821ca078 applies a ramped/target volume, FUN_821ca108 is the
// other branch. Tracing both shows whether a fade is actually running and where it lands.
extern "C" void __imp__sub_821CA078(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821CA078){
  if(std::getenv("RT_STOPTRACE")){
    static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    if(i<=80) std::fprintf(stderr,"[volt] fade-apply sub_821CA078 idx=%u vol=%.3f lr=0x%X\n",
                           ctx.r5.u32,(double)ctx.f1.f64,(uint32_t)ctx.lr);
  }
  // Under RT_FADETRACE log only the FRACTIONAL applications — i.e. an actual ramp in flight —
  // so the handover fade is visible without the boot-time 0.0/1.0 churn burying it.
  if(std::getenv("RT_FADETRACE")){
    double v = (double)ctx.f1.f64;
    if(v > 0.0001 && v < 0.9999){
      static std::atomic<long> n2{0}; long j=n2.fetch_add(1)+1;
      if(j<=120) std::fprintf(stderr,"[fadeapply] sub_821CA078 idx=%u vol=%.4f r3=0x%X r4=0x%X lr=0x%X\n",
                              ctx.r5.u32,v,ctx.r3.u32,ctx.r4.u32,(uint32_t)ctx.lr);
    }
  }
  // ★ FOLLOW THE FADE. This is the guest's own per-tick volume application (idx = category,
  // f1 = the ramped value). Routing it into the bridge is what makes the handover fade audible
  // instead of a hard cut; see the RT_FADEGAIN block in rt_audio.cpp for the measurement.
  if(rt_audio_bridge_enabled() && rt_audio_cuebridge_enabled())
    rt_audio_set_category_fade((int)ctx.r5.u32,(double)ctx.f1.f64);
  __imp__sub_821CA078(ctx,base);
}
extern "C" void __imp__sub_821CA108(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821CA108){
  if(std::getenv("RT_STOPTRACE")){
    static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    if(i<=80) std::fprintf(stderr,"[volt] fade-off sub_821CA108 idx=%u lr=0x%X\n",
                           ctx.r3.u32,(uint32_t)ctx.lr);
  }
  __imp__sub_821CA108(ctx,base);
}
// ★ 2026-08-01 FADE-ARM TRACE. sub_821CA008(idx, frames) writes the fade table's duration(+0x120)
// and frames-remaining(+0x124) — THE armer of every category fade (decomp: ppc_recomp.35 5644..).
// sub_821CA1B8 rewrites the same pair (cancel/reset shape). The open question both defects hang on
// (Global stuck at 0.000 through gameplay; attract music-out never armed): WHO arms/releases, and
// does the armer RE-ARM per frame while a scene state holds? lr names the caller.
extern "C" void __imp__sub_821CA008(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821CA008){
  if(std::getenv("RT_STOPTRACE")){
    static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    if(i<=400) std::fprintf(stderr,"[fadearm] sub_821CA008 idx=%u frames=%u lr=0x%X\n",
                            ctx.r3.u32,ctx.r4.u32,(uint32_t)ctx.lr);
  }
  __imp__sub_821CA008(ctx,base);
}
extern "C" void __imp__sub_821CA1B8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821CA1B8){
  if(std::getenv("RT_STOPTRACE")){
    static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    if(i<=400) std::fprintf(stderr,"[fadecancel] sub_821CA1B8 idx=%u r4=0x%X lr=0x%X\n",
                            ctx.r3.u32,ctx.r4.u32,(uint32_t)ctx.lr);
  }
  __imp__sub_821CA1B8(ctx,base);
}


// Engine-level CATEGORY controls (vtable slots 17/18, resolved live: 0x820E91E0 / 0x820E7628).
// FUN_820e91e0(this, category, flags) is IXACT3Engine::Stop — it resolves the category through the
// category manager at engine+0xb8. This is the standard XACT way to silence "music" without
// touching the cue objects, which is exactly the shape the attract evidence points at.
extern "C" void __imp__sub_820E91E0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820E91E0){
  if(std::getenv("RT_STOPTRACE")){
    static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    if(i<=40) std::fprintf(stderr,"[stoptrace] engine::Stop(category) sub_820E91E0 #%ld cat=%u flags=0x%X lr=0x%X\n",
                           i,ctx.r4.u32,ctx.r5.u32,(uint32_t)ctx.lr);
  }
  __imp__sub_820E91E0(ctx,base);
}
extern "C" void __imp__sub_820E7628(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820E7628){
  if(std::getenv("RT_STOPTRACE")){
    static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    // ⚠ THE GATE (disassembly @0x820e7684): after looking the category up through the category
    // manager at engine+0xb8 (vtable[+4]), the guest reads the record's byte at +9 and applies the
    // volume ONLY if (byte & 2). If that bit is clear the whole call is a NO-OP. So "SetVolume(cat3,
    // 0.0) was called" does NOT mean music was muted — replicate the guest's own lookup and report
    // whether it actually took effect, before drawing any conclusion from these calls.
    uint32_t eng=ctx.r3.u32;
    uint32_t mgr=(eng&&eng<0xF0000000u)?PPC_LOAD_U32(eng+0xB8u):0;
    uint32_t mvt=(mgr&&mgr<0xF0000000u)?PPC_LOAD_U32(mgr):0;
    uint32_t fn =(mvt&&mvt<0xF0000000u)?PPC_LOAD_U32(mvt+4u):0;
    int applied=-1; uint32_t rec=0, flags=0;
    if(fn){
      PPCContext ic=ctx; ic.r3.u32=mgr; ic.r4.u32=ctx.r4.u32;
      rt_indirect_call(ic,base,fn);                 // the same lookup the guest is about to do
      rec=ic.r3.u32;
      if(rec && rec<0xF0000000u){ flags=PPC_LOAD_U8(rec+9u); applied=(flags&2u)?1:0; }
    }
    if(i<=40) std::fprintf(stderr,"[stoptrace] engine::SetVolume(category) sub_820E7628 #%ld cat=%u f1=%.3f rec=0x%X flags=0x%02X APPLIED=%d lr=0x%X\n",
                           i,ctx.r4.u32,(double)ctx.f1.f64,rec,flags,applied,(uint32_t)ctx.lr);
  }
  // Mirror the guest's category volume into the bridge, so host-played cues obey the same mute the
  // guest applies to its own voices. Only forwarded when the bridge is live; scope/no-op policy is
  // rt_audio.cpp's (RT_CATVOL).
  if(rt_audio_bridge_enabled() && rt_audio_cuebridge_enabled())
    rt_audio_set_category_volume((int)ctx.r4.u32,(double)ctx.f1.f64);
  __imp__sub_820E7628(ctx,base);
}

extern "C" void __imp__sub_820EC958(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820EC958){
  rt_dchain_tally(1,"cueStop",ctx);
  const bool on = rt_audio_bridge_enabled()!=0 && rt_audio_cuebridge_enabled()!=0
                  && rt_audio_cuestop_enabled()!=0;
  if(std::getenv("RT_STOPTRACE")){
    static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    uint32_t o=ctx.r3.u32;
    if(i<=40) std::fprintf(stderr,"[stoptrace] cue::Stop sub_820EC958 #%ld obj=0x%X imm=%u bankField(+0x134)=0x%X cueField(+0x13C)=%u lr=0x%X\n",
                           i,o,ctx.r4.u32&1u,
                           (o&&o<0xF0000000u)?PPC_LOAD_U32(o+0x134u):0,
                           (o&&o<0xF0000000u)?PPC_LOAD_U16(o+0x13Cu):0xFFFFu,(uint32_t)ctx.lr);
  }
  if(!on){ __imp__sub_820EC958(ctx,base); return; }
  uint32_t cueObj = ctx.r3.u32, immediate = ctx.r4.u32 & 1u;
  uint32_t bank=0, cueIdx=0xFFFFu;
  if(cueObj && cueObj<0xF0000000u){
    bank   = PPC_LOAD_U32(cueObj+0x134u);
    cueIdx = PPC_LOAD_U16(cueObj+0x13Cu);
  }
  __imp__sub_820EC958(ctx,base);            // the guest's real Stop runs first, untouched
  if(bank && bank<0xF0000000u && cueIdx!=0xFFFFu){
    const char* sb = rt_sb_name(base,bank);
    if(sb) rt_audio_bridge_stop_cue(sb,(int)cueIdx,(int)immediate);
  }
}

extern "C" void __imp__sub_820EEE00(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820EEE00){
  static bool bp = std::getenv("RT_BGMPROBE")!=nullptr;
  const bool cue = rt_audio_bridge_enabled()!=0 && rt_audio_cuebridge_enabled()!=0;
  if(!bp && !cue){ __imp__sub_820EEE00(ctx,base); return; }
  uint32_t bank=ctx.r3.u32, cueIdx=ctx.r4.u32 & 0xFFFFu, outPtr=ctx.r7.u32;
  __imp__sub_820EEE00(ctx,base);
  const int32_t ret=(int32_t)ctx.r3.u32;
  // RT_STOPTRACE one-shot: the ENGINE vtable. The attract gate showed the menu cue staying alive
  // (state 1..5) with no XACT Stop anywhere, so the shell must silence music by another route —
  // in XACT that is engine-level category volume. IXACT3Engine's layout here is the stock one
  // shifted +2 (DoWork lands on index 7 = 0x820E8F88, CreateSoundBank on 8 = 0x820E80C0 and
  // RegisterNotification on 14 = 0x820E8400, all three already confirmed), which puts
  // GetCategory at 16 (+0x40), Stop at 17 (+0x44) and SetVolume at 18 (+0x48). Dump them.
  if(std::getenv("RT_STOPTRACE")){
    static std::atomic<int> vonce{0};
    if(vonce.fetch_add(1)==0 && bank && bank<0xF0000000u){
      uint32_t eng=PPC_LOAD_U32(bank+24u);
      uint32_t evt=(eng&&eng<0xF0000000u)?PPC_LOAD_U32(eng):0;
      std::fprintf(stderr,"[stoptrace] engine=0x%X vtable=0x%X slots[0..24]:",eng,evt);
      for(int s=0;s<=24&&evt&&evt<0xF0000000u;s++)
        std::fprintf(stderr," %d:%08X",s,PPC_LOAD_U32(evt+(uint32_t)s*4));
      std::fprintf(stderr,"\n");
    }
  }
  if(bp){ static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    uint32_t wave=(outPtr&&outPtr<0xF0000000u)?PPC_LOAD_U32(outPtr):0;
    uint32_t wvt=(wave&&wave<0xF0000000u)?PPC_LOAD_U32(wave):0;
    if(i<=24) std::fprintf(stderr,"[bgmprobe.bankprep] PREPARE sub_820EEE00 #%ld bank=0x%X cueIdx=%u outPtr=0x%X -> wave=0x%X vt=0x%X %s ret=0x%X\n",
      i,bank,cueIdx,outPtr,wave,wvt,(wvt==0x82015690u)?"<<STREAMING>>":"",ctx.r3.u32);
  }
  // Dispatch only what the guest itself accepted (ret>=0 == the wave was created and STARTed).
  if(cue && ret>=0 && cueIdx!=0xFFFFu){
    const char* sb = rt_sb_name(base,bank);
    // Hand over the guest cue object created inside this Prepare (t_last_created_wave, captured in
    // the sub_820EEC10 hook) so the bridge can mirror its lifetime instead of looping forever.
    if(sb) rt_audio_bridge_play_cue_h(sb,(int)cueIdx,t_last_created_wave,bank);
  }
  t_last_created_wave = 0;
}
// RT_BGMPROBE (START-lifecycle leg, DOWNSTREAM sub-fork): sub-wave allocator = sub_820FD160
// (FUN_820fd160). Called by the pump sub_820FD530 when armed (+0x188!=0). Materializes the first
// streaming sub-wave into +0x1AC — but ONLY if the region index +0x1b8 != -1. When +0x1b8==-1 it first
// calls sub_82102E80 (region-SELECT by playback-time +0x184) to pick a region; if none is selected
// +0x1b8 stays 0xFFFF and NO sub-wave is created. Pump call passes obj in r3 (double time in f1).
extern "C" void __imp__sub_820FD160(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820FD160){
  static bool bp  = std::getenv("RT_BGMPROBE")!=nullptr;
  static bool fix = std::getenv("RT_BGMFIX")!=nullptr;
  if(!bp && !fix){ __imp__sub_820FD160(ctx,base); return; }  // inert when unset
  uint32_t o=ctx.r3.u32; bool ok=o&&o<0xF0000000u;
  uint16_t seg_pre = ok?PPC_LOAD_U16(o+0x1b8u):0;   // cold-start iff 0xFFFF
  uint32_t param3  = ctx.r5.u32;                    // r5 = &created (pump stack local)
  // --- probe pre-reads (read-only) ---
  uint16_t seg0=seg_pre; uint32_t t=ok?PPC_LOAD_U32(o+0x184u):0;
  uint32_t dec=ok?PPC_LOAD_U32(o+0x138u):0, src=ok?PPC_LOAD_U32(o+0x180u):0;

  // ============ TYPE-0 SIMPLE-LOOP DETECTION (guest's OWN has-transitions signal) ============
  // The decoder-2 ctor FUN_821035c0 (dec2 at obj+0x138) builds region/transition descriptors ONLY
  // when the region-block word0 encodes an interactive-audio type: (word0>>16)&7 ∈ {2,3} AND
  // (word0&0x380000)!=0x180000 AND (word0&0xffff)!=0; otherwise it early-returns with
  // jaggedTotal(dec2+0xc)==0 (NO transition descriptors). BGM's 13 cues are SIMPLE looping PCM waves
  // (numSimpleCues=13, no complex cues on disk): word0=0x010003B4 -> (>>16)&7=0 -> type-0, empty dec2.
  // For a type-0 wave there is exactly ONE implicit region (the whole wave); it must play as a simple
  // loop honoring the .xwb loop points, NOT through the multi-region crossfade FSM. Detect it with the
  // EXACT same predicate the guest uses so we never mis-gate an interactive (type 2/3) cue.
  bool type0=false;
  if(ok && dec && dec<0xF0000000u){
    uint32_t rblk=PPC_LOAD_U32(dec+8u);            // dec2+8 = region block (puVar6)
    uint32_t jt  =PPC_LOAD_U32(dec+0xcu);          // dec2+0xc = jaggedTotal (transition-descr count)
    if(rblk && rblk<0xF0000000u){
      uint32_t w0=PPC_LOAD_U32(rblk); uint32_t ty=(w0>>16)&7u;
      bool hasTrans = (ty==2u||ty==3u) && ((w0&0x380000u)!=0x180000u) && ((w0&0xffffu)!=0u);
      type0 = !hasTrans && (jt==0u);
    }
  }

  // ===== TYPE-0 STEADY-STATE SIMPLE-LOOP GATE (RT_BGMFIX) ==================================
  // fd160's job in steady-state (region unchanged) is to BAIL (asm 0x820fd220: if curRegionIdx
  // (+0x1b8)==selectedRegionIdx -> return, created=0). For a type-0 wave the current region NEVER
  // changes (one implicit region), so HW keeps bailing here every pump tick and the pump's own
  // FUN_820f7430 refill loops the current wave via its .xwb loop points. The port diverges ONLY
  // because the region/transition pointers resolve to garbage for a simple cue (region block = the
  // .xsb Sound entry; transition base = an OOB +64MB offset -> a zero-filled table): FUN_82102fb8
  // reads a garbage time-window and reports "region invalid", so fd160 re-selects a garbage region
  // and does a transition lookup on the empty table, which fails and TEARS DOWN the sub-wave -> stall.
  // Register-true fix: once past cold-start (+0x1b8!=0xFFFF), force a type-0 wave down fd160's OWN
  // bail path — do nothing, keep the current wave. NO synthesized data, no poke of region/wave state;
  // this only PREVENTS the FSM from acting on the garbage region/transition data. Cold-start
  // (+0x1b8==0xFFFF) still runs the real body + SEED fix below to build the first wave.
  if(fix && ok && seg_pre!=0xFFFFu && type0){
    if(param3 && param3<0xF0000000u) PPC_STORE_U32(param3, 0u);   // created = 0 (fd160 entry default)
    ctx.r3.u64 = 0;                                               // ret = S_OK (bail, no rebuild)
    static std::atomic<long> lf{0}; long li=lf.fetch_add(1)+1;
    if(li<=8) std::fprintf(stderr,"[bgmloop.fix] TYPE-0 steady-state fd160 obj=0x%X curRegion(+0x1b8)=0x%04X => BAIL (region unchanged; pump FUN_820f7430 loops the wave). No re-select, no transition lookup.\n", o,seg_pre);
    return;   // skip fd160 body: register-true equivalent of the "region unchanged" bail
  }

  __imp__sub_820FD160(ctx,base);

  int32_t ret=(int32_t)ctx.r3.s32;
  uint16_t seg1=ok?PPC_LOAD_U16(o+0x1b8u):0;
  uint16_t nxt =ok?PPC_LOAD_U16(o+0x1bau):0;
  uint32_t w1ac=ok?PPC_LOAD_U32(o+0x1ACu):0;
  uint32_t w1b0=ok?PPC_LOAD_U32(o+0x1B0u):0;

  // ================= SEED FIX (RT_BGMFIX) — COLD-START current-region bootstrap ==============
  // At a true cold start there is NO "from" region to cross-fade out of, so on HW the cold-start
  // transition descriptor's from-waveindex is -1 (skip the from-wave build). The port's transition
  // table lookup for source=+0x1b8==0xFFFF, with the region count (948) and the u16-truncated row
  // index sub_82103940 computes, lands on an unpopulated/aliased row whose [0]==0 (not -1) — so
  // fd160 calls a DOOMED edac8(waveIdx=0) (ret 0x8AC7xxxx) and reports created=0. Consequently the
  // pump (sub_820FD530) never sets +0x1c0=1, so the cue-tick (sub_820FC8B8) never promotes
  // +0x1ba(next)->+0x1b8(current), and the first region never plays.
  // fd160 DID successfully build the transition-IN sub-wave (+0x1b0) and seed +0x1ba — that IS the
  // first region's wave. Emulate HW's from-waveindex==-1 by reporting the cold-start success:
  // set *created=1 and ret>=0. The GUEST's OWN pump then sets +0x1c0=1, and the GUEST's OWN
  // cue-tick promotes +0x1b0 -> current wave (+0x38) and +0x1ba -> +0x1b8. No poke of
  // +0x1b8/+0x1c0/+0x1bc — only fd160's success report is corrected for the from-region-less case.
  bool seeded=false;
  if(fix && ok && seg_pre==0xFFFF && ret<0 && nxt!=0xFFFF && w1b0!=0 && w1ac==0){
    if(param3 && param3<0xF0000000u) PPC_STORE_U32(param3, 1u);  // created = 1
    ctx.r3.u64 = 0;                                              // ret = S_OK
    ret = 0; seeded=true;
    static std::atomic<long> sf{0};
    if(sf.fetch_add(1)<8) std::fprintf(stderr,"[bgmseed.fix] COLD-START fd160 obj=0x%X from(+0x1b8)=0xFFFF next(+0x1ba)=0x%04X transIn(+0x1b0)=0x%X => report created=1 ret=S_OK (guest pump will set +0x1c0=1; cue-tick promotes)\n", o,nxt,w1b0);
  }

  if(bp){ static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    uint32_t tbl=ok?PPC_LOAD_U32(o+0x1a4u):0;
    uint16_t cnt=(tbl&&tbl<0xF0000000u)?PPC_LOAD_U16(tbl+8u):0;
    uint32_t td=ok?PPC_LOAD_U32(o+0x1bcu):0;
    uint32_t td0=(td&&td<0xF0000000u)?PPC_LOAD_U32(td):0xBAD;
    uint16_t tdf=(td&&td<0xF0000000u)?PPC_LOAD_U16(td+0x18u):0;
    uint32_t tblbase=(tbl&&tbl<0xF0000000u)?PPC_LOAD_U32(tbl+4u):0;
    long row=(td&&tblbase)?((long)td-(long)tblbase-4)/26:-1;
    unsigned long cnt2c=(unsigned long)cnt*((unsigned long)cnt+1);
    unsigned char rb[26]; for(int q=0;q<26;q++) rb[q]=(td&&td<0xF0000000u)?PPC_LOAD_U8(td+q):0;
    char hx[80]; for(int q=0;q<26;q++) std::snprintf(hx+q*3,4,"%02X ",rb[q]);
    if(i<=40) std::fprintf(stderr,"[bgmprobe.alloc] sub_820FD160 #%ld obj=0x%X seg(+0x1b8) 0x%04X->0x%04X nxt(+0x1ba)=0x%04X tbl=0x%X cnt=%u td=0x%X *td=0x%X tflags=0x%04X time=0x%08X dec=0x%X src=0x%X => [+0x1AC]=0x%X [+0x1B0]=0x%X | ret=0x%X row=%ld cnt2c=%lu seeded=%d rowbytes=[%s]\n",
      i,o,seg0,seg1,nxt,tbl,cnt,td,td0,tdf,t,dec,src,w1ac,w1b0,(uint32_t)ret,row,cnt2c,seeded?1:0,hx);
    // ===== H1/H2 DISCRIMINATOR (one-shot deep dump of the transition-matrix source) =====
    static std::atomic<int> deep{0};
    if(deep.fetch_add(1)==0 && ok){
      uint32_t decp = PPC_LOAD_U32(o+0x134u);              // decoder (piVar5[0x4d])
      uint32_t decvt= (decp&&decp<0xF0000000u)?PPC_LOAD_U32(decp):0;
      uint32_t dec2 = PPC_LOAD_U32(o+0x138u);              // decoder-2 (piVar5[0x4e], FUN_821035c0)
      uint32_t rblk = (dec2&&dec2<0xF0000000u)?PPC_LOAD_U32(dec2+8u):0;  // region block (puVar6)
      uint32_t rbw0 = (rblk&&rblk<0xF0000000u)?PPC_LOAD_U32(rblk):0;     // region-block word0 (low16 = count)
      uint32_t d2tot= (dec2&&dec2<0xF0000000u)?PPC_LOAD_U32(dec2+0xcu):0;// FUN_821035c0 param_1[3] jagged total
      std::fprintf(stderr,"[bgmprobe.deep] decoder=0x%X decVT=0x%X dec2=0x%X regionBlk=0x%X rbWord0=0x%08X (low16=%u) jaggedTotal(dec2+0xc)=%u tblBase=0x%X cnt=%u\n",
        decp,decvt,dec2,rblk,rbw0,rbw0&0xFFFF,d2tot,tblbase,cnt);
      // transition table content: first 8 rows (26 bytes each) at tblBase — populated vs all-zero
      if(tblbase&&tblbase<0xF0000000u){
        for(int r=0;r<8;r++){ char hh[90]; for(int q=0;q<26;q++) std::snprintf(hh+q*3,4,"%02X ",PPC_LOAD_U8(tblbase+r*26u+q));
          std::fprintf(stderr,"[bgmprobe.trow] row%d @0x%X: %s\n",r,tblbase+r*26u,hh); }
        // scan first 64KB of table for ANY non-zero byte (is it populated anywhere?)
        long nz=0,lastnz=-1; for(long b=0;b<65536;b++){ if(PPC_LOAD_U8(tblbase+b)){nz++; lastnz=b;} }
        std::fprintf(stderr,"[bgmprobe.tscan] tblBase[0..64K): nonZeroBytes=%ld lastNZoff=%ld\n",nz,lastnz);
      }
      // region block first 48 bytes (region entries are 16 bytes each after word0..+8 header)
      if(rblk&&rblk<0xF0000000u){ char hh[160]; for(int q=0;q<48;q++) std::snprintf(hh+q*3,4,"%02X ",PPC_LOAD_U8(rblk+q));
        std::fprintf(stderr,"[bgmprobe.rblk] regionBlk[0..48]: %s\n",hh); }
    }
  }
}
// RT_BGMPROBE: streaming region-SELECT = sub_82102E80 (FUN_82102e80): walks a region table, picks a
// region whose time-window [+0xc,+0x10] contains the playback time (f1), returns idx via *param3(r5).
// If it selects nothing, +0x1b8 stays 0xFFFF. Report region-count and the selected idx to distinguish
// (empty-table) vs (time-out-of-window) vs (not-reached).
extern "C" void __imp__sub_82102E80(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_82102E80){
  static bool bp = std::getenv("RT_BGMPROBE")!=nullptr;
  if(bp){ static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    uint32_t r4=ctx.r4.u32, r5=ctx.r5.u32; // r5 = &segIdx out
    __imp__sub_82102E80(ctx,base);
    uint16_t segOut=(r5&&r5<0xF0000000u)?PPC_LOAD_U16(r5):0xDEAD;
    if(i<=40) std::fprintf(stderr,"[bgmprobe.rgnsel] sub_82102E80 #%ld r4(dec?)=0x%X segOutPtr=0x%X selectedSeg=0x%04X ret=0x%X\n",
      i,r4,r5,segOut,ctx.r3.u32);
    return; }
  __imp__sub_82102E80(ctx,base);
}
// PATCH (a) VARIANT A1 (RT_BGMFIX ship path; RT_STREAMCLASS kept as alias). Propagate the bank's
// STREAMING type into the per-wave class-selector byte0 that CreateWave (FUN_820eec10) reads. On disk
// the per-entry dwFlags nibble is 0 for all banks; the streaming discriminator is bank-global
// WAVEBANKDATA.dwFlags bit0 (BGM 0x00080001 vs SE 0x00080000), which HW's bank-load synthesis stamps
// into byte0 bit0x2 and the port drops. Keyed on the BGM SoundBank handler *(0x885C5BB4) (bt=0).
extern "C" void __imp__sub_820F14A8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820F14A8){
  static bool on = std::getenv("RT_BGMFIX")!=nullptr || std::getenv("RT_STREAMCLASS")!=nullptr;
  if(on){
    uint32_t bank=ctx.r3.u32;
    uint32_t bgm = PPC_LOAD_U32(0x885C5BB4u);       // bt=0 SoundBank handler = BGM (streaming)
    __imp__sub_820F14A8(ctx,base);
    uint32_t desc=ctx.r3.u32;
    if(bgm && bank==bgm && desc && desc<0xF0000000u){
      uint8_t b0=PPC_LOAD_U8(desc);
      if(!(b0&0x2u)){
        PPC_STORE_U8(desc,(uint8_t)(b0|0x2u));
        static std::atomic<int> f{0}; long k=f.fetch_add(1);
        if(k<12) std::fprintf(stderr,"[bgmfix.a] BGM desc 0x%X byte0 0x%02X->0x%02X (bank=0x%X) => streaming class 0x82015690\n",
                              desc,b0,(unsigned)(b0|0x2u),bank);
      }
    }
    return;
  }
  __imp__sub_820F14A8(ctx,base);
}

// RT_AUDIOCRUX: XACT engine instrumentation. sub_820E8400 = the driver-SUBMIT (vtable[+56]) the
// crux fires — it queues a wave-instance node into the engine's list at engine+0xA0 and returns 0
// on success / an HRESULT-style error otherwise (the crux ignores the return). sub_820E8970 = the
// engine COMMIT/DoWork that walks engine+0xA0/+0xA4 and invokes *(engine+0x4c) to actually create/
// start the XAudio2 source voices. If SUBMIT succeeds but COMMIT never runs (or vice-versa), that
// is the game->XAudio2 voice-creation gap. Read-only counters.
static std::atomic<long> g_xsubmit{0}, g_xsubmit_ok{0}, g_xsubmit_err{0}, g_xcommit{0};
extern "C" void __imp__sub_820E8400(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820E8400){
  if(std::getenv("RT_AUDIOCRUX")){
    long n=g_xsubmit.fetch_add(1)+1;
    uint32_t engine=ctx.r3.u32;
    __imp__sub_820E8400(ctx,base);
    uint32_t ret=ctx.r3.u32; bool ok=(int32_t)ret>=0;
    if(ok) g_xsubmit_ok.fetch_add(1); else g_xsubmit_err.fetch_add(1);
    if(n<=12) std::fprintf(stderr,"[xact] SUBMIT#%ld engine=0x%X ret=0x%X (%s) engineQueueTail(+0xA8)=0x%X\n",
      n,engine,ret,ok?"OK-queued":"ERR",engine?PPC_LOAD_U32(engine+0xA8):0);
    return;
  }
  __imp__sub_820E8400(ctx,base);
}
extern "C" void __imp__sub_820E8970(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820E8970){
  static bool bp = std::getenv("RT_BGMPROBE")!=nullptr;
  if(std::getenv("RT_AUDIOCRUX") || bp){
    long n=g_xcommit.fetch_add(1)+1;
    uint32_t eng=ctx.r3.u32;
    uint32_t reg=(eng&&eng<0xF0000000u)?PPC_LOAD_U32(eng+0x4c):0;
    uint32_t head=(eng&&eng<0xF0000000u)?PPC_LOAD_U32(eng+0xa4):0;   // +0xa0 list head
    if(n<=12) std::fprintf(stderr,"[bgmprobe.commit] COMMIT/DoWork(820E8970)#%ld engine=0x%X *(engine+0x4c)=0x%X list(+0xa4)=0x%X GUARD=%s\n",
      n,eng,reg,head,reg?"PASS(callback registered)":"FAIL(engine+0x4c==0 -> no-op)");
  }
  __imp__sub_820E8970(ctx,base);
}
// RT_BGMPROBE (engine+0x4c GUARD leg): engine Initialize = sub_820E6A98 (FUN_820e6a98). Writes
// engine+0x4c = param_2[7] (int index 7 of the runtime-params struct = XACT fnNotificationCallback).
// Captures whether the port ever registers a notification callback at all. r3=engine, r4=params.
extern "C" void __imp__sub_820E6A98(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820E6A98){
  static bool bp = std::getenv("RT_BGMPROBE")!=nullptr;
  uint32_t engine=ctx.r3.u32, params=ctx.r4.u32;
  uint32_t cb= bp && params&&params<0xF0000000u ? PPC_LOAD_U32(params+0x1c):0; // param_2[7]
  __imp__sub_820E6A98(ctx,base);
  if(bp){
    uint32_t reg=(engine&&engine<0xF0000000u)?PPC_LOAD_U32(engine+0x4c):0;
    std::fprintf(stderr,"[bgmprobe.init] Initialize sub_820E6A98 engine=0x%X params=0x%X param2[7](notifCb)=0x%X => engine+0x4c=0x%X ret=0x%X\n",
      engine,params,cb,reg,ctx.r3.u32);
  }
}
// RT_BGMPROBE (engine+0x4c GUARD leg): sub_820EC880 (FUN_820ec880) = the "fire a notification"
// call the streaming wave makes at Prepare(type=1) and PLAY(type=2). Builds a 0x1c-byte notification
// command from decoder(+0x134)/region(+0x13c) and calls the engine COMMIT sub_820E8970. If engine+0x4c
// is 0 the whole thing no-ops (harmless). r3=this(streaming wave), r4=notif type. Read-only.
extern "C" void __imp__sub_820EC880(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820EC880){
  static bool bp = std::getenv("RT_BGMPROBE")!=nullptr;
  if(bp){
    uint32_t self=ctx.r3.u32; uint32_t typ=ctx.r4.u32 & 0xFF;
    uint32_t dec=(self&&self<0xF0000000u)?PPC_LOAD_U32(self+0x134):0;
    uint32_t rgn=(self&&self<0xF0000000u)?PPC_LOAD_U16(self+0x13c):0;
    uint32_t eng=(self&&self<0xF0000000u)?PPC_LOAD_U32(self+0x3c):0;
    uint32_t reg=(eng&&eng<0xF0000000u)?PPC_LOAD_U32(eng+0x4c):0;
    static std::atomic<long> nn{0}; long k=nn.fetch_add(1);
    if(k<24) std::fprintf(stderr,"[bgmprobe.notify] sub_820EC880 #%ld self=0x%X notifType=%u dec(+0x134)=0x%X rgn(+0x13c)=0x%04X engine(+0x3c)=0x%X engine+0x4c=0x%X\n",
      k,self,typ,dec,rgn,eng,reg);
  }
  __imp__sub_820EC880(ctx,base);
}
// ============================================================================================
// RT_MIXTRACE (mixer/refill leg, layer 22, default-OFF, all hooks HERE in merged_xex.cpp so they
// WIN the /FORCE:MULTIPLE link — never in rt.cpp where they'd be shadowed). DOWNSTREAM-OF-ATTACH
// probe: the port creates the loop=0xFF BGM source voice at parity (DIFFERENTIAL-TRACE #2), yet
// BGM is silent — the divergence is host-runtime pump/mixer/refill. This enumerates the XAudio2
// submix graph the summer sub_82137218 walks, tracks each source-voice's LIFETIME (BGM loop
// voices are long-lived / persistent; SE are transient one-shots — this tags BGM vs SE WITHOUT
// fragile offset RE), and dumps struct layout so the read-cursor/buffer/loop offsets can be read
// empirically. The summer is called once per submix per tick: master 0x36A090 render == sub_82137218,
// which walks children (+0x22c/556) and calls each child render; child submixes recurse (render ==
// 0x82137218), source voices have a different render. Union of source-voice children across all
// summer calls = the whole voice graph.
static void rt_mixtrace_summer(uint8_t* base, uint32_t submix){
  if(!submix || submix>=0xF0000000u) return;
  uint64_t call = g_mt_call.fetch_add(1)+1;
  std::lock_guard<std::mutex> lk(g_mt_mtx);
  uint32_t node = PPC_LOAD_U32(submix+556);
  int guard=0, nSrc=0, nSub=0;
  while(node && node<0xF0000000u && guard<256){
    uint32_t v = PPC_LOAD_U32(node+0);
    node = PPC_LOAD_U32(node+4); ++guard;
    if(!v || v>=0xF0000000u) continue;
    uint32_t vt = PPC_LOAD_U32(v);
    uint32_t render = (vt&&vt<0xF0000000u)?PPC_LOAD_U32(vt):0;
    if(render==0x82137218u){ ++nSub; continue; }   // nested submix, seen on its own call
    ++nSrc;
    auto it = g_mt_v.find(v);
    if(it==g_mt_v.end()){
      g_mt_v[v] = MtVoice{call,call,1,vt,render};
      std::fprintf(stderr,"[mixtrace] NEW-SRCVOICE 0x%X parentSubmix=0x%X render=0x%X call=%llu lastAttachLoop=0x%X\n",
        v,submix,render,(unsigned long long)call,g_mt_attach_loop.load());
      rt_mt_dump(base,"NEW", v, vt, render, call);
    } else {
      if(call - it->second.last > 300){
        std::fprintf(stderr,"[mixtrace] REAPPEAR 0x%X gap=%llu (transient/SE-like) call=%llu\n",
          v,(unsigned long long)(call-it->second.last),(unsigned long long)call);
      }
      it->second.last=call; it->second.count++;
    }
  }
  // periodic persistence + cursor report — reveals which voices are LONG-LIVED (BGM loop) and
  // re-dumps their struct so a monotonically-advancing word = the read cursor (refill evidence).
  if((call%1500)==0){
    size_t alive=0, longlived=0;
    std::fprintf(stderr,"[mixtrace] === call=%llu everSeenSrcVoices=%zu (thisSubmix src=%d sub=%d) ===\n",
      (unsigned long long)call,g_mt_v.size(),nSrc,nSub);
    for(auto& kv:g_mt_v){
      uint32_t v=kv.first; MtVoice& mv=kv.second;
      bool a=(call-mv.last)<80; uint64_t span=mv.last-mv.first;
      if(a) ++alive;
      if(a && span>200){ ++longlived;
        double onzf = mv.renders? (double)mv.nzRenders/(double)mv.renders : 0.0;
        double inzf = mv.inRenders? (double)mv.inNz/(double)mv.inRenders : 0.0;
        const char* verdict="";
        if(mv.render==0x8214E5C0u && mv.inRenders>50){
          if(mv.inNz==0 && mv.nzRenders==0) verdict="<<STARVED(in=0,out=0: no PCM feeding)";
          else if(mv.inNz>0 && mv.nzRenders==0) verdict="<<GAIN-ZEROED(in>0,out=0: volume/send mutes it)";
          else if(mv.inNz>0 && mv.nzRenders>0) verdict="<<PRODUCING(in>0,out>0)";
        }
        std::fprintf(stderr,"[mixtrace] LONGLIVED 0x%X span=%llu render=0x%X | IN nz=%llu/%llu(%.2f) ipk=%.4g | OUT nz=%llu/%llu(%.2f) BEpk=%.4g RAWpk=%.4g %s\n",
          v,(unsigned long long)span,mv.render,
          (unsigned long long)mv.inNz,(unsigned long long)mv.inRenders,inzf,mv.inPeak,
          (unsigned long long)mv.nzRenders,(unsigned long long)mv.renders,onzf,mv.peak,mv.rawPeak,verdict);
      }
    }
    std::fprintf(stderr,"[mixtrace] --- alive=%zu longlived(BGM-candidate)=%zu ---\n",alive,longlived);
  }
}
// ============================================================================================
// RT_BGMCOLLECT (collect leg, layer 25, default-OFF) — MAP the collected pass + find the missing link.
// ============================================================================================
// Layer-24 proved H-ORPHAN: the transpose sub_821396C0 submits *(client+0x18)=0x36FA90 which carries
// SE but NEVER the BGM. RT_AUDIOFILL earlier proved master 0x36A090's summer child is category submix
// 0x372F10, and filling *(0x372F10+0x78)+0x38 reaches the transport frame 0x36FA90. BGM stage voices
// (sub_8214E5C0) write **(voice+0x7c)=0x36C678. This probe enumerates the FULL submix tree the summer
// sub_82137218 walks (register-true, per the recomp: submix=r3, device/output obj=*(r3+0x6c) with
// vt[0]=begin/vt[+4]=end, child-list head=*(r3+556=0x22c), node+0=voice node+4=next, child render =
// child->vtable[0]()). For each child it reads the true outbuf per render class: source
// (sub_8214E5C0/sub_82150338) = **(child+0x7c); leaf submix (sub_8214E3E0) = *(child+0x78)+0x38;
// recursive submix (sub_82137218) = its own device *(child+0x6c). Flags any node touching 0x36C678
// (BGM accum) or 0x36FA90 (transport). => reveals WHICH submix owns the BGM stage voices, where its
// output routes (its device obj), and whether that submix is a summed child of master/0x372F10
// (present-but-zero-send) or entirely absent from the collected list (orphan). This is the register-
// true collected-pass map the fix needs.
static const uint32_t COL_BGMACC = 0x36C678u;
static const uint32_t COL_XPORT  = 0x36FA90u;
static std::mutex g_col_mtx;
static uint32_t g_col_seen[64]={0}; static int g_col_seen_n=0;
static std::atomic<uint64_t> g_col_epoch{0};
static void rt_bgmcollect_tree(uint8_t* base, uint32_t submix){
  if(!submix||submix>=0xF0000000u) return;
  uint64_t T=g_col_epoch.fetch_add(1)+1;
  std::lock_guard<std::mutex> lk(g_col_mtx);
  bool seen=false; for(int i=0;i<g_col_seen_n;i++) if(g_col_seen[i]==submix) seen=true;
  bool periodic = (T%6000)==0;
  if(seen && !periodic) return;
  if(!seen && g_col_seen_n<64) g_col_seen[g_col_seen_n++]=submix;
  uint32_t devO=PPC_LOAD_U32(submix+0x6c);
  uint32_t devVt=(devO&&devO<0xF0000000u)?PPC_LOAD_U32(devO):0;
  uint32_t devBuf=(devO&&devO<0xF0000000u)?PPC_LOAD_U32(devO+0x18):0;      // render-driver-style accum
  uint32_t s78=PPC_LOAD_U32(submix+0x78); uint32_t sAcc=(s78&&s78<0xF0000000u)?s78+0x38:0;
  std::fprintf(stderr,"[collect] T=%llu SUBMIX=0x%X dev(+0x6c)=0x%X devVt=0x%X devBuf(+0x18)=0x%X ownAcc(*(+0x78)+0x38)=0x%X%s%s\n",
    (unsigned long long)T,submix,devO,devVt,devBuf,sAcc,
    (devBuf==COL_XPORT||sAcc==COL_XPORT?" <TRANSPORT0x36FA90>":""),
    (devBuf==COL_BGMACC||sAcc==COL_BGMACC?" <BGMACC0x36C678>":""));
  uint32_t node=PPC_LOAD_U32(submix+556); int guard=0, nkids=0;
  while(node&&node<0xF0000000u&&guard<256){
    uint32_t v=PPC_LOAD_U32(node+0); node=PPC_LOAD_U32(node+4); ++guard;
    if(!v||v>=0xF0000000u) continue; ++nkids;
    uint32_t vt=PPC_LOAD_U32(v); uint32_t render=(vt&&vt<0xF0000000u)?PPC_LOAD_U32(vt):0;
    uint32_t ob=0;   // source outbuf **(v+0x7c)
    if(render==0x8214E5C0u||render==0x82150338u){ uint32_t o=PPC_LOAD_U32(v+0x7c); ob=(o&&o<0xF0000000u)?PPC_LOAD_U32(o):0; }
    uint32_t cAcc=0, cdev=0, cdevBuf=0;
    if(render==0x8214E3E0u){ uint32_t c78=PPC_LOAD_U32(v+0x78); cAcc=(c78&&c78<0xF0000000u)?c78+0x38:0; }
    if(render==0x82137218u){ cdev=PPC_LOAD_U32(v+0x6c); cdevBuf=(cdev&&cdev<0xF0000000u)?PPC_LOAD_U32(cdev+0x18):0; }
    const char* tag = (ob==COL_BGMACC)?" <<BGM stage voice outbuf=0x36C678":
                      (ob==COL_XPORT )?" <<source writes transport 0x36FA90":
                      (cAcc==COL_BGMACC||cdevBuf==COL_BGMACC)?" <<submix touches 0x36C678":
                      (cAcc==COL_XPORT||cdevBuf==COL_XPORT)?" <<submix touches 0x36FA90":"";
    std::fprintf(stderr,"[collect]   child v=0x%X render=0x%X srcOutbuf=0x%X leafAcc=0x%X recDev=0x%X recDevBuf=0x%X%s\n",
      v,render,ob,cAcc,cdev,cdevBuf,tag);
  }
  std::fprintf(stderr,"[collect]   -> SUBMIX 0x%X nkids=%d\n",submix,nkids);
}
// RT_AUDIOCRUX: read-only probe on the SHELL XACT submix mixer sub_82137218 (ppc_recomp.21.cpp:
// 24912). It walks its context object's active-voice list at r3+556 (node+0=voice, node+4=next)
// and sums each voice. If that list is EMPTY, the game-submitted voices never reach the mixer's
// summation graph => zero frame regardless of wave-data (a game->shell voice-routing gap). Logs
// the list length + first voices for the first calls and periodically. Read-only.
extern "C" void __imp__sub_82137218(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_82137218){
  static bool mt = std::getenv("RT_MIXTRACE")!=nullptr;
  static bool col = std::getenv("RT_BGMCOLLECT")!=nullptr;
  if(mt) rt_mixtrace_summer(base, ctx.r3.u32);
  if(col) rt_bgmcollect_tree(base, ctx.r3.u32);
  if(std::getenv("RT_AUDIOCRUX")){
    static std::atomic<long> mc{0}; long n=mc.fetch_add(1)+1;
    if(n<=8 || (n%2000)==0){
      uint32_t mo=ctx.r3.u32;
      uint32_t head=mo?PPC_LOAD_U32(mo+556):0;
      int cnt=0; uint32_t node=head; uint32_t v0=0,v1=0;
      while(node && node<0xF0000000u && cnt<64){
        uint32_t v=PPC_LOAD_U32(node+0); if(cnt==0)v0=v; else if(cnt==1)v1=v;
        node=PPC_LOAD_U32(node+4); ++cnt;
      }
      std::fprintf(stderr,"[mix] sub_82137218 #%ld mixerObj=0x%X active-voice-list(+556)=0x%X count=%d firstVoices=0x%X 0x%X\n",
        n,mo,head,cnt,v0,v1);
      std::fprintf(stderr,"[xact] SUBMIT(820E8400) calls=%ld ok=%ld err=%ld | COMMIT/DoWork(820E8970) calls=%ld\n",
        g_xsubmit.load(),g_xsubmit_ok.load(),g_xsubmit_err.load(),g_xcommit.load());
      // One-shot deep dump: what is the single voice the mixer reads? mixer calls voice->vtable[0]
      // (ppc_recomp.21.cpp:25013 `lwz r11,0(r3); lwz r11,0(r11); bctrl`). If it's a SUBMIX it will
      // itself have a +556 child list (where game source voices should hang); if a SOURCE voice it
      // holds a PCM buffer ptr. Dump vtable[0] (render fn, to trace statically), structure, +556.
      static std::atomic<int> once{0};
      if(v0 && v0<0xF0000000u && once.fetch_add(1)==0){
        uint32_t vt=PPC_LOAD_U32(v0), render=vt?PPC_LOAD_U32(vt):0;
        uint32_t child=PPC_LOAD_U32(v0+556);
        int ccnt=0; uint32_t cn2=child; while(cn2&&cn2<0xF0000000u&&ccnt<64){ cn2=PPC_LOAD_U32(cn2+4); ++ccnt; }
        std::fprintf(stderr,"[mix] HEAD-VOICE 0x%X vtable=0x%X render(vt[0])=0x%X  own+556(childList)=0x%X childCount=%d\n",v0,vt,render,child,ccnt);
        std::fprintf(stderr,"[mix]   voice[+0..60]:");
        for(int o=0;o<=60;o+=4) std::fprintf(stderr," +%d=%08X",o,PPC_LOAD_U32(v0+o));
        std::fprintf(stderr,"\n[mix]   voice[+104..120]:");
        for(int o=104;o<=120;o+=4) std::fprintf(stderr," +%d=%08X",o,PPC_LOAD_U32(v0+o));
        std::fprintf(stderr,"\n");
      }
    }
  }
  __imp__sub_82137218(ctx,base);
}

// RT_AUDIOFILL audibility proof (default-OFF, audio-only): the ticked master mixer sub_82137218
// (0x36A090) sums exactly ONE child voice 0x372F10 whose per-voice render is sub_8214E3E0. That
// render writes the voice's contribution into *(voice+120)+56. There are NO source voices in the
// graph (routing gap), so the coordinator's "fill the source-voice buffer" has no target; instead
// we fill THIS submix render output with a 375Hz f32 tone right after it renders. If the transport
// frame (RT_AUDIODUMP / RT_AUDIOPROBE) then goes NON-ZERO, the submix->master->transport path is
// proven end-to-end and the whole defect is pinned to "create+route a source voice + fill its ring".
static int rt_sv_census512(uint8_t* base, uint32_t buf, float& pk);  // fwd (defined below)
// ============================================================================================
// RT_FRAMEPAIR (frame-pairing leg, layer 26, default-OFF) — host 1:1 produce/consume rendezvous.
// ============================================================================================
// Layer-26 RT_PAIRTRACE proved: the render-driver client's producer/consumer events (consumed
// 0x36A748=client+0x28, ready 0x36A76C=client+0x2c, shutdown 0x372AE0=client+0x30) live in ONE
// address-keyed registry (no Nt/Ke mismatch), and the transpose sub_821396C0 wait on {shutdown,
// ready} DOES block (clamped 3ms) and returns ready. The break is PACING: the summer's category-
// submix DSP (sub_8214E3E0, voice=category submix 0x372F10) writes the transport buffer 0x36FA90
// on the XAudio2 process thread at ~245-263Hz, while the transpose reads+submits 0x36FA90 on the
// pump/worker thread at 187.5Hz. Producer > consumer over one SINGLE buffer => the transpose reads
// a frame the next summer pass already overwrote (and the DSP zeroes its output when its input
// isn't lock-stepped) => sustained BGM never survives; loud SE transients occasionally do.
//
// FIX = rexglue AudioSystem's produce-per-consumed contract, collapsed to a host rendezvous on the
// single transport buffer: the producer may not overwrite 0x36FA90 until the consumer has read the
// previous frame (at most `depth` unconsumed frames outstanding; depth=1 = strict lockstep, the
// transpose always reads the freshest complete mix). NO buffer copy, NO host mixing — pure pacing:
// the guest DSP still does all the audio, we only stop it running ahead of consumption so the
// resampler advances once per consumed frame and the DSP input-ready handshake lands every pass.
//
// SAFETY: ONLY the XAudio2 producer thread (tid=2) ever blocks here (bounded by a generous
// watchdog => a stalled/absent consumer degrades to today's free-run, never a hard wedge). The
// consumer release is a non-blocking notify, so the vblank/render thread is NEVER blocked by this
// rendezvous => 60fps is unaffected. Env: RT_FRAMEPAIR (on), RT_FRAMEPAIR_DEPTH (default 1),
// RT_FRAMEPAIR_WAITMS (producer watchdog, default 250).
struct RtFramePair {
  std::mutex m; std::condition_variable cv;
  int outstanding=0; int depth=1; long wd_us=250000; bool on=false; bool inited=false;
  std::atomic<uint64_t> prod{0}, cons{0}, blocked{0}, wdfire{0};
};
static RtFramePair g_fp;
static void rt_fp_init(){
  static std::once_flag o;
  std::call_once(o,[](){
    g_fp.on = std::getenv("RT_FRAMEPAIR")!=nullptr;
    const char* d=std::getenv("RT_FRAMEPAIR_DEPTH"); g_fp.depth = d?std::atoi(d):1; if(g_fp.depth<1)g_fp.depth=1; if(g_fp.depth>16)g_fp.depth=16;
    const char* w=std::getenv("RT_FRAMEPAIR_WAITMS"); long ms=w?std::atol(w):250; if(ms<1)ms=1; if(ms>2000)ms=2000; g_fp.wd_us=ms*1000;
    g_fp.inited=true;
    if(g_fp.on) std::fprintf(stderr,"  [framepair] ON depth=%d watchdog=%ldms (producer=category-submix 0x372F10 -> 0x36FA90, consumer=transpose sub_821396C0)\n",g_fp.depth,g_fp.wd_us/1000);
  });
}
// Producer, BEFORE it overwrites 0x36FA90: block (bounded) until the previous frame was consumed
// (outstanding < depth). Then let the DSP write. Returns after the guard so the caller marks the
// produce with rt_fp_after_produce() once the write is done.
static void rt_fp_before_produce(){
  if(!g_fp.on) return;
  std::unique_lock<std::mutex> l(g_fp.m);
  if(g_fp.outstanding >= g_fp.depth){
    g_fp.blocked.fetch_add(1);
    if(!g_fp.cv.wait_for(l,std::chrono::microseconds(g_fp.wd_us),[&]{return g_fp.outstanding < g_fp.depth;})){
      g_fp.wdfire.fetch_add(1);          // consumer stalled -> proceed (free-run fallback), reset slot
      g_fp.outstanding = 0;
    }
  }
}
static void rt_fp_after_produce(){
  if(!g_fp.on) return;
  std::lock_guard<std::mutex> l(g_fp.m);
  g_fp.outstanding++; g_fp.prod.fetch_add(1);
}
// Consumer (transpose), AFTER it read+submitted 0x36FA90: free exactly one produced frame.
// Non-blocking: never stalls the pump/vblank thread.
static void rt_fp_after_consume(){
  if(!g_fp.on) return;
  { std::lock_guard<std::mutex> l(g_fp.m); if(g_fp.outstanding>0) g_fp.outstanding--; g_fp.cons.fetch_add(1); }
  g_fp.cv.notify_one();
  static std::atomic<uint64_t> c{0}; uint64_t q=c.fetch_add(1)+1;
  if(q<=3 || (q%4000)==0)
    std::fprintf(stderr,"[framepair] consumed #%llu | prod=%llu cons=%llu blocked=%llu wdfire=%llu outstanding=%d\n",
      (unsigned long long)q,(unsigned long long)g_fp.prod.load(),(unsigned long long)g_fp.cons.load(),
      (unsigned long long)g_fp.blocked.load(),(unsigned long long)g_fp.wdfire.load(),g_fp.outstanding);
}

extern "C" void __imp__sub_8214E3E0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_8214E3E0){
  static bool mt = std::getenv("RT_MIXTRACE")!=nullptr;
  static bool col = std::getenv("RT_BGMCOLLECT")!=nullptr;
  uint32_t voice=ctx.r3.u32;
  // RT_FRAMEPAIR producer gate: the category submix 0x372F10 is the node that writes the transport
  // buffer 0x36FA90. Hold the XAudio2 thread here until the transpose consumed the previous frame,
  // so this DSP write cannot overwrite an unread frame. Guarded to the transport-writing submix only.
  rt_fp_init();
  bool fp_producer = g_fp.on && (voice==0x372F10u);
  if(fp_producer) rt_fp_before_produce();
  // RT_BGMCOLLECT (layer 25): the category submix render. Its DSP call (recomp ppc_recomp.23:1672)
  // reads INPUT accum r5=*(v+0x78)+0x38 and writes to OUTPUT target r7=&*(v+0x88). *(v+0x88) is only
  // RESOLVED when the gate *(v+0x94)!=0 (then r3'=*(v+0x84), r4=*(v+0x80), *(v+0x88)=r3'->vt+0x14()).
  // Capture the routing fields + census input vs the transport buffer 0x36FA80(run-relative) to see
  // whether the submix output is delivered or dropped (gate==0 => output never resolved => orphan).
  uint32_t c_in=0,c_out=0,c94=0,c84=0,c80=0,c8c=0; int c_innz=0; float c_inpk=0;
  if(col && voice && voice<0xF0000000u){
    uint32_t p78=PPC_LOAD_U32(voice+0x78); c_in=(p78&&p78<0xF0000000u)?p78+0x38:0;
    c94=PPC_LOAD_U32(voice+0x94); c84=PPC_LOAD_U32(voice+0x84); c80=PPC_LOAD_U32(voice+0x80);
    c_innz=rt_sv_census512(base,c_in,c_inpk);
  }
  // ---- RT_COLFORCE (layer-25 causal A/B): the DSP sub_82115180 gates output on param_3[1]=*(inAcc+4)
  // (=inDesc+0x3c). When 0 it takes the no-input branch and ZEROES the output → BGM silence. The REAL
  // input PCM is param_3[0]=*(inAcc) (=0x36C800-class), NOT the struct region 0x36C678. If that PCM
  // carries audio and the ready-flag is 0, force it to param_3[2] (frame count) so the DSP processes
  // the real PCM into the transport. If BGM then flows CLEAN (not garbled like the RT_ACCSPLICE struct
  // copy), the mute is PROVEN to be the un-set input-ready handshake flag inDesc+0x3c, and the fix is
  // to make the guest producer set it. Diagnostic only (like RT_ACCSPLICE); NOT the register-true fix.
  static bool force = std::getenv("RT_COLFORCE")!=nullptr;
  if(force && voice && voice<0xF0000000u){
    uint32_t p78=PPC_LOAD_U32(voice+0x78); uint32_t inAcc=(p78&&p78<0xF0000000u)?p78+0x38:0;
    if(inAcc && inAcc<0xF0000000u){
      uint32_t ready=PPC_LOAD_U32(inAcc+4);         // param_3[1]
      uint32_t frames=PPC_LOAD_U32(inAcc+8);        // param_3[2] (frame count, =0x100)
      uint32_t pcm=PPC_LOAD_U32(inAcc+0);           // param_3[0] = real PCM buffer (0x36C800-class)
      if(ready==0 && frames!=0 && pcm && pcm<0xF0000000u){
        // only force when the real PCM buffer actually has audio-range content
        float ppk=0; int pnz=rt_sv_census512(base,pcm,ppk);
        if(pnz>0 && ppk<=4.0f){
          PPC_STORE_U32(inAcc+4, frames);           // arm the ready flag with the frame count
          static std::atomic<long> ff{0}; long i=ff.fetch_add(1)+1;
          if(i==1||i%4000==0) std::fprintf(stderr,"[colforce] #%ld armed inAcc=0x%X ready:0->%u pcm=0x%X pcmNz=%d/512 pk=%.4f\n",i,inAcc,frames,pcm,pnz,ppk);
        }
      }
    }
  }
  // RT_INFLAG (frame-pairing leg, layer 26): decide whether the DSP ready-flag (inAcc+4) is a
  // FALSE-negative (under-set while real PCM present => a fixable handshake) or GENUINE (flag matches
  // real PCM availability => resampler/source gap, a new fork). Read the TRUE per-voice PCM buffer
  // *(inAcc+0) (offset-free) and correlate flag x pcmPresent x outLanded. Snapshot flag BEFORE __imp__
  // (the DSP may clear it). Default-OFF.
  static bool inflag = std::getenv("RT_INFLAG")!=nullptr;
  uint32_t if_flag=0, if_pcm=0; int if_pcmnz=0; float if_pcmpk=0;
  if(inflag && voice==0x372F10u){
    uint32_t p78=PPC_LOAD_U32(voice+0x78); uint32_t inAcc=(p78&&p78<0xF0000000u)?p78+0x38:0;
    if(inAcc&&inAcc<0xF0000000u){ if_flag=PPC_LOAD_U32(inAcc+4); if_pcm=PPC_LOAD_U32(inAcc+0);
      if(if_pcm&&if_pcm<0xF0000000u) if_pcmnz=rt_sv_census512(base,if_pcm,if_pcmpk); }
  }
  __imp__sub_8214E3E0(ctx,base);
  if(fp_producer) rt_fp_after_produce();   // frame written to 0x36FA90; mark it unconsumed
  if(inflag && voice==0x372F10u){
    uint32_t c_out2=PPC_LOAD_U32(voice+0x88); int onz=0; float opk=0;
    if(c_out2&&c_out2<0xF0000000u){ for(int s=0;s<1536;s++){ uint32_t be=PPC_LOAD_U32(c_out2+(uint32_t)s*4); float f; std::memcpy(&f,&be,4);
      float a=f<0?-f:f; if(f!=0.0f&&a<=4.0f){ ++onz; if(a>opk)opk=a; } } }
    bool flagSet=(if_flag>=1), pcmPresent=(if_pcmnz>0 && if_pcmpk<=4.0f), outLanded=(onz>0);
    static std::atomic<uint64_t> nFire{0}, nFlag{0}, nPcm{0}, nOut{0}, nPcmNoFlag{0}, nFlagNoPcm{0}, nPcmNoOut{0};
    nFire.fetch_add(1);
    if(flagSet)nFlag.fetch_add(1); if(pcmPresent)nPcm.fetch_add(1); if(outLanded)nOut.fetch_add(1);
    if(pcmPresent&&!flagSet)nPcmNoFlag.fetch_add(1);      // FALSE-negative flag (fixable)
    if(flagSet&&!pcmPresent)nFlagNoPcm.fetch_add(1);
    if(pcmPresent&&!outLanded)nPcmNoOut.fetch_add(1);
    uint64_t q=nFire.load();
    if(q<=3 || (q%4000)==0)
      std::fprintf(stderr,"[inflag] fires=%llu | flagSet=%llu pcmPresent=%llu outLanded=%llu | PCM&&!flag(FALSE-neg)=%llu flag&&!PCM=%llu PCM&&!out=%llu | (FALSE-neg>0 => flag under-set = fixable handshake; ~0 => flag genuine = resampler/source gap)\n",
        (unsigned long long)q,(unsigned long long)nFlag.load(),(unsigned long long)nPcm.load(),(unsigned long long)nOut.load(),
        (unsigned long long)nPcmNoFlag.load(),(unsigned long long)nFlagNoPcm.load(),(unsigned long long)nPcmNoOut.load());
  }
  if(col && voice && voice<0xF0000000u){
    c_out=PPC_LOAD_U32(voice+0x88); c8c=PPC_LOAD_U32(voice+0x8c);
    // census FULL 6ch interleaved out (1536 f32) right after the DSP write
    int conz=0; float copk=0;
    if(c_out && c_out<0xF0000000u){
      for(int s=0;s<1536;s++){ uint32_t be=PPC_LOAD_U32(c_out+(uint32_t)s*4); float f; std::memcpy(&f,&be,4);
        float a=f<0?-f:f; if(f!=0.0f && a<=4.0f){ ++conz; if(a>copk)copk=a; } }
    }
    // correlation tallies: when input carries BGM (pk>1.0), does output land?
    static std::atomic<uint64_t> nFire{0}, nInBgm{0}, nOutWhenInBgm{0}, nOutZeroWhenInBgm{0};
    nFire.fetch_add(1);
    bool inBgm = (c_innz>0 && c_inpk>1.0f);
    if(inBgm){ nInBgm.fetch_add(1); if(conz>0) nOutWhenInBgm.fetch_add(1); else nOutZeroWhenInBgm.fetch_add(1); }
    static std::mutex m; static uint32_t seenv[16]={0}; static int seenn=0; static std::atomic<uint64_t> ce{0};
    uint64_t e=ce.fetch_add(1)+1;
    std::lock_guard<std::mutex> lk(m);
    bool sv=false; for(int i=0;i<seenn;i++) if(seenv[i]==voice) sv=true;
    if((!sv&&seenn<16) || (e%4000)==0){
      if(!sv&&seenn<16) seenv[seenn++]=voice;
      std::fprintf(stderr,"[collect3e0] submix=0x%X gate(+0x94)=0x%X outMtx(+0x84)=0x%X arg(+0x80)=0x%X | inAcc=0x%X inNz=%d/512 pk=%.4f | outTarget(+0x88)=0x%X outNz=%d/1536 pk=%.4f | +0x8c=0x%X\n",
        voice,c94,c84,c80,c_in,c_innz,c_inpk,c_out,conz,copk,c8c);
      std::fprintf(stderr,"[collect3e0]   TALLY fires=%llu inBGM(pk>1)=%llu -> outLanded=%llu outZERO=%llu (outZERO/inBGM = the drop rate)\n",
        (unsigned long long)nFire.load(),(unsigned long long)nInBgm.load(),
        (unsigned long long)nOutWhenInBgm.load(),(unsigned long long)nOutZeroWhenInBgm.load());
      // DSP identity: r3=*(v+8), fn=*(*(r3))+0x28. Plus input descriptor *(v+0x78) and its head fields.
      uint32_t dsp=PPC_LOAD_U32(voice+8);
      uint32_t dvt=(dsp&&dsp<0xF0000000u)?PPC_LOAD_U32(dsp):0;
      uint32_t dfn=(dvt&&dvt<0xF0000000u)?PPC_LOAD_U32(dvt+0x28):0;
      uint32_t p78=PPC_LOAD_U32(voice+0x78);
      std::fprintf(stderr,"[collect3e0]   DSP obj=0x%X vt=0x%X procFn(vt+0x28)=0x%X | inDesc(*(v+0x78))=0x%X inDesc[+0..+0x40]:",dsp,dvt,dfn,p78);
      if(p78&&p78<0xF0000000u) for(int o=0;o<=0x40;o+=4) std::fprintf(stderr," +%d=%08X",o,PPC_LOAD_U32(p78+o));
      std::fprintf(stderr," | outMtxObj[+0..+0x20]:");
      if(c84&&c84<0xF0000000u) for(int o=0;o<=0x20;o+=4) std::fprintf(stderr," +%d=%08X",o,PPC_LOAD_U32(c84+o));
      std::fprintf(stderr,"\n");
    }
  }
  if(mt) rt_mt_census(base, voice, 0x8214E3E0u);
  if(std::getenv("RT_AUDIOFILL") && voice && voice<0xF0000000u){
    uint32_t ob=PPC_LOAD_U32(voice+120);
    if(ob && ob<0xF0000000u){
      uint32_t out=ob+56;
      static std::atomic<long> fc{0}; long i=fc.fetch_add(1)+1;
      for(int s=0;s<256;s++){ float f=((s/64)&1)?0.35f:-0.35f; uint32_t bits; std::memcpy(&bits,&f,4); PPC_STORE_U32(out+(uint32_t)s*4,bits); }
      if(i==1||i%4000==0) std::fprintf(stderr,"[fillmix] voice=0x%X output=0x%X filled 256 f32 tone (#%ld)\n",voice,out,i);
    }
  }
}
// RT_MIXTRACE: the two SOURCE-voice renders (0x82150338 = resampling source, vtable 0x820349A4;
// 0x8214E5C0 = paired voice, vtable 0x82034970). Census each voice's OUTPUT contribution right
// after it renders. This answers (b): do the long-lived BGM voices produce nonzero samples or are
// they STARVED (in-graph but silent)? r3=voice.
//
// ============================================================================================
// RT_STARVED (layer 23, default-OFF) — the offset-free STARVED(A) vs MUTED(B) discriminator.
// ============================================================================================
// The layer-22 per-voice f32 output census was UNRELIABLE (the "outbuf" struct slots resolve to
// control/descriptor words → garbage 1e10-1e11 in both endiannesses). This probe avoids float
// buffers entirely and reads only INTEGERS + FUNCTION-FIRE counts, all grounded in the resampler
// decomp (default_decomp_all.txt sub_82150338 @149877):
//   piVar2 = r3 (voice; FUN_8207c984 = __savegprlr_27, r3 preserved — verified ppc_recomp.23:6538).
//   iVar6  = *(int*)piVar2[0x14]           = *( *(voice+0x50) )         [the SOURCE object]
//   cursor = *(uint*)(iVar6+0x34)          [integer sample position; /channels @149902]
//   fmt    = *(int*)(iVar6+0x2c) ; channels= *(ushort*)(fmt+0xc)       [@149901]
//   @149917: iVar3 = vt+8(this)  ["source active?"]
//   @149918: if (iVar3==0 || piVar2[0x1f]!=0 || (piVar2[0x2e]==0 && piVar2[0x2c]==0))
//                 local_50 = 0 ;                        // <-- SILENCE branch (no source read)
//            else local_50 = FUN_82150148(piVar2, channels*frames) ; // <-- reads REAL source PCM
//   FUN_82150148 (sole caller = this line 149923) is the ONLY source-PCM read.
// Class discriminator: channels==2 → STEREO = BGM ; channels==1 → MONO = SE (task-confirmed).
// Verdict logic (combine with the AUTHORITATIVE master 6ch frame from RT_AUDIOPROBE):
//   (A) STARVED  = BGM(stereo) voice ticks every frame but readTicks≈0 / cursor stuck  AND master=0.
//   (B) MUTED    = BGM voice reads real PCM every tick (readTicks≈ticks) + cursor advances, yet
//                  master 6ch output stays 0 → a downstream per-voice gain/send zeroes it.
static thread_local uint64_t g_sv_readc = 0;      // FUN_82150148 entries (source reads), per thread
struct SvVoice { uint16_t ch=0; uint32_t src=0,iVar6=0,fmt=0; uint32_t firstCur=0, lastCur=0, minCur=0xFFFFFFFFu, maxCur=0;
                 uint64_t ticks=0, readTicks=0, advTicks=0, outNzTicks=0, outSampNz=0, outSampTot=0; float outPeak=0;
                 bool haveCur=false, dumped=false; };
static std::mutex g_sv_mtx;
static std::unordered_map<uint32_t,SvVoice> g_sv;
extern "C" void __imp__sub_82150148(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_82150148){
  static bool sv = std::getenv("RT_STARVED")!=nullptr;
  if(sv) ++g_sv_readc;                              // this tick took the source-read (non-silence) branch
  __imp__sub_82150148(ctx,base);
}
extern "C" void __imp__sub_82150338(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_82150338){
  static bool mt = std::getenv("RT_MIXTRACE")!=nullptr;
  static bool sv = std::getenv("RT_STARVED")!=nullptr;
  uint32_t voice=ctx.r3.u32;
  uint16_t ch=0; uint32_t cur=0, src=0, iVar6=0, fmt=0;
  if(sv && voice && voice<0xF0000000u){
    src=PPC_LOAD_U32(voice+0x50);
    if(src && src<0xF0000000u){
      iVar6=PPC_LOAD_U32(src);
      if(iVar6 && iVar6<0xF0000000u){
        cur=PPC_LOAD_U32(iVar6+0x34);
        fmt=PPC_LOAD_U32(iVar6+0x2c);
        if(fmt && fmt<0xF0000000u) ch=(uint16_t)PPC_LOAD_U16(fmt+0xc);
      }
    }
  }
  uint64_t r0 = sv ? g_sv_readc : 0;
  __imp__sub_82150338(ctx,base);
  if(sv && voice && voice<0xF0000000u){
    uint64_t rd = g_sv_readc - r0;                  // >0 => source-read branch fired this tick
    std::lock_guard<std::mutex> lk(g_sv_mtx);
    auto& e=g_sv[voice];
    if(e.ticks==0){ e.firstCur=cur; e.src=src; e.iVar6=iVar6; e.fmt=fmt; }
    if(ch) e.ch=ch;
    if(e.haveCur && cur!=e.lastCur) e.advTicks++;
    e.lastCur=cur; e.haveCur=true; if(cur<e.minCur)e.minCur=cur; if(cur>e.maxCur)e.maxCur=cur;
    e.ticks++; if(rd>0) e.readTicks++;
    // AUDIO-RANGE output census (post-render): the resampler's final stage writes the mixed f32 into
    // the buffer at (iVar6+0x38) [decomp @149944, outbuf arg = (iVar6+0x38); blockAlign 8 => 256
    // stereo frames = 512 f32 = 2048 bytes]. Read BE-f32, count samples with 0<|x|<=4 (real PCM lives
    // in [-1,1]); pointer/control garbage lands far outside → excluded. Nonzero here + read every tick
    // = REAL PCM FLOWING (=> MUTED downstream). All-zero here = source produced silence (=> STARVED).
    if(iVar6 && iVar6<0xF0000000u){
      uint32_t ob=iVar6+0x38; int snz=0; float pk=0.0f;
      for(int s=0;s<512;s++){ uint32_t be=PPC_LOAD_U32(ob+(uint32_t)s*4); float f; std::memcpy(&f,&be,4);
        float a=f<0?-f:f; if(f!=0.0f && a<=4.0f){ ++snz; if(a>pk)pk=a; } }
      e.outSampTot+=512; e.outSampNz+=snz; if(snz>0)e.outNzTicks++; if(pk>e.outPeak)e.outPeak=pk;
    }
    // one-shot raw-chain dump per NEW voice (locate the true channel / cursor fields; iVar6 window)
    if(!e.dumped && iVar6 && iVar6<0xF0000000u){
      e.dumped=true;
      std::fprintf(stderr,"[starved] NEWVOICE 0x%X src=0x%X iVar6=0x%X fmt=0x%X ch(fmt+0xc)=%u cur(iVar6+0x34)=%u\n",
        voice,src,iVar6,fmt,ch,cur);
      std::fprintf(stderr,"[starved]   iVar6[+0x28..+0x40]:");
      for(uint32_t o=0x28;o<=0x40;o+=4) std::fprintf(stderr," +%X=%08X",o,PPC_LOAD_U32(iVar6+o));
      if(fmt && fmt<0xF0000000u){ std::fprintf(stderr,"  | fmt[+0..+0x10]:");
        for(uint32_t o=0;o<=0x10;o+=4) std::fprintf(stderr," +%X=%08X",o,PPC_LOAD_U32(fmt+o)); }
      std::fprintf(stderr,"\n");
    }
    static std::atomic<uint64_t> pc{0}; uint64_t p=pc.fetch_add(1)+1;
    if((p%4000)==0){
      int nP=0; std::fprintf(stderr,"[starved] #%llu report (persistent resampler voices, ticks>200):\n",(unsigned long long)p);
      for(auto&kv:g_sv){ auto&s=kv.second; if(s.ticks>200){ nP++;
        std::fprintf(stderr,"[starved]   voice 0x%X ticks=%llu READ=%llu(%.3f) | OUTPUT nzTicks=%llu(%.3f) sampNz=%llu/%llu(%.3f) pk=%.4f\n",
          kv.first,(unsigned long long)s.ticks,(unsigned long long)s.readTicks,
          s.ticks?(double)s.readTicks/(double)s.ticks:0.0,
          (unsigned long long)s.outNzTicks, s.ticks?(double)s.outNzTicks/(double)s.ticks:0.0,
          (unsigned long long)s.outSampNz,(unsigned long long)s.outSampTot,
          s.outSampTot?(double)s.outSampNz/(double)s.outSampTot:0.0, s.outPeak); } }
      std::fprintf(stderr,"[starved]   persistentVoices=%d totalDistinct=%zu  (readTicks~0 & curSpan~0 => STARVED(A); readTicks~ticks & curSpan large => MUTED(B))\n",nP,g_sv.size());
    }
  }
  if(mt) rt_mt_census(base, voice, 0x82150338u);
}
// RT_STARVED stage-voice probe: the paired stage sub_8214E5C0 (@148616) reads its input
// (**(p1+0x78) = the resampler output) and writes output (**(p1+0x7c)) via the vt+0x28 process on
// *(p1+8) — this is the OUTPUT-MATRIX/gain stage that feeds the master. Census IN vs OUT in audio
// range: IN nonzero (resampler output present) + OUT ZERO => the MUTE is THIS stage's matrix/gain
// (the precise (B) fix site). IN & OUT both nonzero => mute is further downstream (send/master).
struct StVoice { uint32_t inO=0,inP=0,outO=0,outP=0,n=0; uint64_t ticks=0, inNzTicks=0, outNzTicks=0;
                 uint64_t inSampNz=0,inTot=0,outSampNz=0,outTot=0; float inPk=0,outPk=0; bool dumped=false; };
static std::unordered_map<uint32_t,StVoice> g_st;
static int rt_sv_census512(uint8_t* base, uint32_t buf, float& pk){
  pk=0.0f; if(!buf||buf>=0xF0000000u) return -1; int nz=0;
  for(int s=0;s<512;s++){ uint32_t be=PPC_LOAD_U32(buf+(uint32_t)s*4); float f; std::memcpy(&f,&be,4);
    float a=f<0?-f:f; if(f!=0.0f && a<=4.0f){ ++nz; if(a>pk)pk=a; } }
  return nz;
}
// ============================================================================================
// RT_ACCLIFE (accumulator-lifecycle leg, layer 24, default-OFF) — H-ORPHAN vs H-WIPE.
// ============================================================================================
// Layer-23 proved BGM PCM reaches the shared mix accumulator 0x36C678 (stage OUT nonzero pk~1.95)
// yet the submitted 6ch master frame is ZERO while mono SE reaches it. The transpose/submit
// sub_821396C0 (register-true, shell/gen/ppc_recomp.21.cpp:30926) reads its SOURCE buffer from
// *(this+0x18) (r31=this=render-driver client; `lwz r10,24(r31)`), transposes 6ch-interleaved ->
// channel-major into a stack frame, and submits via XAudioSubmitRenderDriverFrame(r3=*(this+0x20)).
// The captured render-driver callback sub_82139888 does `r3=*(r3+0)` then `b sub_821396C0`, i.e.
// the port's RT_AUDIOPUMP path ONLY runs the transpose; the summer FUN_82137390/sub_82137218 runs
// on the XAudio2 process-thread table separately. => the ONE decisive question:
//   is the transpose source *(this+0x18) == 0x36C678 (the BGM accumulator)?
//     src == 0x36C678  => the BGM accumulator IS what gets submitted => WIPE (something clears/
//                         overwrites 0x36C678 after BGM writes, before the transpose reads it)
//     src != 0x36C678  => the submitted buffer differs from the BGM accumulator => ORPHAN
//                         (0x36C678 is a submix never collected into the submitted master frame)
// Cross-census 0x36C678 AND src at transpose time; track what the stage voices leave in 0x36C678
// between transposes; capture the stage-render caller lr (summer-walk 0x821372xx vs DoWork).
static const uint32_t ACC_BGM = 0x36C678u;
static std::atomic<uint64_t> g_al_epoch{0};
static std::atomic<uint32_t> g_al_stage_out{0};       // last stage voice outBuf addr
static std::atomic<int>      g_al_stage_bgm_nz{0};     // sum stage-out census nz since last transpose
static std::atomic<uint64_t> g_al_stage_writes{0};    // stage renders since last transpose
static std::atomic<uint32_t> g_al_last_src{0};
static uint32_t g_al_stage_lr[16]={0}; static int g_al_stage_lr_n=0;  // caller-lr dedup (g_sv_mtx)
extern "C" void __imp__sub_8214E5C0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_8214E5C0){
  static bool mt = std::getenv("RT_MIXTRACE")!=nullptr;
  static bool sv = std::getenv("RT_STARVED")!=nullptr;
  static bool al = std::getenv("RT_ACCLIFE")!=nullptr;
  uint32_t voice=ctx.r3.u32;
  uint32_t inO=0,inP=0,outO=0,outP=0,n=0;
  uint32_t st_lr=(uint32_t)ctx.lr;                     // capture caller lr before impl clobbers it
  if((sv||al) && voice && voice<0xF0000000u){
    inO=PPC_LOAD_U32(voice+0x78);  if(inO&&inO<0xF0000000u)  inP=PPC_LOAD_U32(inO);
    outO=PPC_LOAD_U32(voice+0x7c); if(outO&&outO<0xF0000000u) outP=PPC_LOAD_U32(outO);
    n=PPC_LOAD_U32(voice+0x60);
  }
  __imp__sub_8214E5C0(ctx,base);
  if(al && voice && voice<0xF0000000u){
    float opk=0; int onz=rt_sv_census512(base,outP,opk);
    if(outP){ g_al_stage_out.store(outP); if(onz>0) g_al_stage_bgm_nz.fetch_add(onz); g_al_stage_writes.fetch_add(1); }
    std::lock_guard<std::mutex> lk(g_sv_mtx);
    bool seen=false; for(int i=0;i<g_al_stage_lr_n;i++) if(g_al_stage_lr[i]==st_lr) seen=true;
    if(!seen && g_al_stage_lr_n<16){ g_al_stage_lr[g_al_stage_lr_n++]=st_lr;
      std::fprintf(stderr,"[acclife] stage voice 0x%X outBuf=0x%X n=%u caller_lr=0x%08X %s\n",
        voice,outP,n,st_lr,(outP==ACC_BGM?"(outBuf==ACC_BGM 0x36C678)":"")); }
  }
  if(sv && voice && voice<0xF0000000u){
    float ipk=0,opk=0; int inz=rt_sv_census512(base,inP,ipk); int onz=rt_sv_census512(base,outP,opk);
    std::lock_guard<std::mutex> lk(g_sv_mtx);
    auto& e=g_st[voice];
    if(!e.dumped){ e.dumped=true; e.inO=inO;e.inP=inP;e.outO=outO;e.outP=outP;e.n=n;
      std::fprintf(stderr,"[stage] NEWVOICE 0x%X inObj=0x%X inBuf=0x%X outObj=0x%X outBuf=0x%X n=%u\n",voice,inO,inP,outO,outP,n); }
    e.ticks++;
    if(inz>0){ e.inNzTicks++; e.inSampNz+=inz; if(ipk>e.inPk)e.inPk=ipk; } if(inz>=0)e.inTot+=512;
    if(onz>0){ e.outNzTicks++; e.outSampNz+=onz; if(opk>e.outPk)e.outPk=opk; } if(onz>=0)e.outTot+=512;
    static std::atomic<uint64_t> sp{0}; uint64_t q=sp.fetch_add(1)+1;
    if((q%4000)==0){
      std::fprintf(stderr,"[stage] #%llu report (paired output-matrix voices, ticks>200):\n",(unsigned long long)q);
      for(auto&kv:g_st){ auto&s=kv.second; if(s.ticks>200)
        std::fprintf(stderr,"[stage]   voice 0x%X ticks=%llu | IN nzTicks=%llu(%.3f) sampNz=%llu/%llu(%.3f) pk=%.4f | OUT nzTicks=%llu(%.3f) sampNz=%llu/%llu(%.3f) pk=%.4f\n",
          kv.first,(unsigned long long)s.ticks,
          (unsigned long long)s.inNzTicks, s.ticks?(double)s.inNzTicks/(double)s.ticks:0.0,
          (unsigned long long)s.inSampNz,(unsigned long long)s.inTot, s.inTot?(double)s.inSampNz/(double)s.inTot:0.0, s.inPk,
          (unsigned long long)s.outNzTicks, s.ticks?(double)s.outNzTicks/(double)s.ticks:0.0,
          (unsigned long long)s.outSampNz,(unsigned long long)s.outTot, s.outTot?(double)s.outSampNz/(double)s.outTot:0.0, s.outPk); }
      std::fprintf(stderr,"[stage]   (IN>0 & OUT=0 => MUTE is this stage's output matrix/gain; IN>0 & OUT>0 => mute further downstream)\n");
    }
  }
  if(mt) rt_mt_census(base, voice, 0x8214E5C0u);
}

// RT_ACCLIFE: the transpose/submit sub_821396C0 — the AUTHORITATIVE downstream hop. Read the source
// buffer it actually submits (*(this+0x18)), census it, and cross-census the BGM accumulator
// 0x36C678 at the SAME instant; report what the stage voices wrote to 0x36C678 since the previous
// transpose. This single hook decides H-ORPHAN vs H-WIPE (see block above).
extern "C" void __imp__sub_821396C0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821396C0){
  static bool al = std::getenv("RT_ACCLIFE")!=nullptr;
  static bool splice = std::getenv("RT_ACCSPLICE")!=nullptr;
  uint32_t self=ctx.r3.u32;
  uint32_t src=(self&&self<0xF0000000u)?PPC_LOAD_U32(self+0x18):0;
  // ---- RT_ACCSPLICE (layer-24 H-ORPHAN causal A/B): the register-true HW step that is MISSING is
  // the collection of the BGM submix accumulator 0x36C678 into the render-driver submit buffer
  // *(this+0x18)=0x36FA90 (the summer sums SE there but never the orphaned BGM submix). Restore
  // that collect step host-side, env-gated, as the decisive causal test: if BGM becomes audible +
  // sustained, H-ORPHAN is proven and the frontier = fix the guest submix->master send natively.
  // 0x36C678 = 256 stereo frames (512 f32). Default mapping PLANAR (L0..255,R0..255 — XAudio2
  // internal deinterleaved submix layout); RT_ACCSPLICE_ILV=1 tries interleaved LRLR. Accumulate
  // L->ch0, R->ch1 of the 6ch interleaved src frame (SE already there survives).
  if(splice && src && src<0xF0000000u){
    static bool ilv = std::getenv("RT_ACCSPLICE_ILV")!=nullptr;
    static std::atomic<int> dd{0};
    if(dd.fetch_add(1)==0){
      std::fprintf(stderr,"[accsplice] mapping=%s ACC0x36C678[0..7]:",ilv?"ILV":"PLANAR");
      for(int s=0;s<8;s++){uint32_t be=PPC_LOAD_U32(ACC_BGM+(uint32_t)s*4);float f;std::memcpy(&f,&be,4);std::fprintf(stderr," %.3f",f);}
      std::fprintf(stderr," | [256..263]:");
      for(int s=256;s<264;s++){uint32_t be=PPC_LOAD_U32(ACC_BGM+(uint32_t)s*4);float f;std::memcpy(&f,&be,4);std::fprintf(stderr," %.3f",f);}
      std::fprintf(stderr,"\n");
    }
    for(int f=0;f<256;f++){
      float L,R; uint32_t bl,br;
      if(ilv){ bl=PPC_LOAD_U32(ACC_BGM+(uint32_t)(2*f)*4);   br=PPC_LOAD_U32(ACC_BGM+(uint32_t)(2*f+1)*4); }
      else   { bl=PPC_LOAD_U32(ACC_BGM+(uint32_t)f*4);       br=PPC_LOAD_U32(ACC_BGM+(uint32_t)(256+f)*4); }
      std::memcpy(&L,&bl,4); std::memcpy(&R,&br,4);
      uint32_t a0=src+(uint32_t)(6*f+0)*4, a1=src+(uint32_t)(6*f+1)*4;
      uint32_t be0=PPC_LOAD_U32(a0), be1=PPC_LOAD_U32(a1); float c0,c1;
      std::memcpy(&c0,&be0,4); std::memcpy(&c1,&be1,4);
      c0+=L; c1+=R; uint32_t o0,o1; std::memcpy(&o0,&c0,4); std::memcpy(&o1,&c1,4);
      PPC_STORE_U32(a0,o0); PPC_STORE_U32(a1,o1);
    }
  }
  if(al && self && self<0xF0000000u){
    uint64_t T=g_al_epoch.fetch_add(1)+1;
    uint32_t handle=PPC_LOAD_U32(self+0x20);
    // census the SUBMITTED source (6ch interleaved, 1536 f32) BEFORE the impl transposes it away
    int srcNz=0; float srcPk=0;
    if(src && src<0xF0000000u){
      for(int s=0;s<1536;s++){ uint32_t be=PPC_LOAD_U32(src+(uint32_t)s*4); float f; std::memcpy(&f,&be,4);
        float a=f<0?-f:f; if(f!=0.0f && a<=4.0f){ ++srcNz; if(a>srcPk)srcPk=a; } }
    }
    // cross-census the BGM accumulator 0x36C678 at the SAME instant (512 f32, as layer-23)
    int accNz=0; float accPk=0;
    for(int s=0;s<512;s++){ uint32_t be=PPC_LOAD_U32(ACC_BGM+(uint32_t)s*4); float f; std::memcpy(&f,&be,4);
      float a=f<0?-f:f; if(f!=0.0f && a<=4.0f){ ++accNz; if(a>accPk)accPk=a; } }
    uint64_t stW=g_al_stage_writes.exchange(0);
    int stNz=g_al_stage_bgm_nz.exchange(0);
    uint32_t stOut=g_al_stage_out.load();
    g_al_last_src.store(src);
    bool same=(src==ACC_BGM);
    if(T<=8 || (T%800)==0){
      std::fprintf(stderr,"[acclife] T=%llu TRANSPOSE self=0x%X src(this+0x18)=0x%X %s handle=0x%X | srcCensus nz=%d/1536 pk=%.4f | ACC0x36C678 nz=%d/512 pk=%.4f | stageWrites=%llu stageAccNz=%d stageOut=0x%X\n",
        (unsigned long long)T,self,src,(same?"[src==ACC_BGM]":"[src!=ACC_BGM]"),handle,srcNz,srcPk,accNz,accPk,
        (unsigned long long)stW,stNz,stOut);
    }
  }
  // RT_BGMCOLLECT (layer 25): census src AFTER __imp__. The transpose reads src=*(self+0x18) only
  // INSIDE __imp__ AFTER its KeWaitForMultipleObjects returns 1 (ppc_recomp.21:31004) — so reading
  // src BEFORE __imp__ (RT_ACCLIFE above) is a pre-wait ARTIFACT. Post-__imp__ src holds what the
  // transpose actually transposed+submitted (it doesn't clear src). If post-src is ALSO zero while
  // the summer's category submix wrote nonzero (collect3e0) => PRODUCER/CONSUMER DESYNC: the summer's
  // 0x36FA90 write and the transpose's synchronized read are not paired to the same frame.
  static bool col2 = std::getenv("RT_BGMCOLLECT")!=nullptr;
  __imp__sub_821396C0(ctx,base);
  // RT_FRAMEPAIR consumer release: the transpose has now read+submitted 0x36FA90. Free the producer
  // to make exactly the next frame (non-blocking; never stalls the pump/vblank thread).
  rt_fp_after_consume();
  if(col2 && self && self<0xF0000000u){
    uint32_t s2=PPC_LOAD_U32(self+0x18);
    int nz=0; float pk=0;
    if(s2 && s2<0xF0000000u){ for(int s=0;s<1536;s++){ uint32_t be=PPC_LOAD_U32(s2+(uint32_t)s*4); float f; std::memcpy(&f,&be,4);
      float a=f<0?-f:f; if(f!=0.0f && a<=4.0f){ ++nz; if(a>pk)pk=a; } } }
    static std::atomic<uint64_t> te{0}; uint64_t T=te.fetch_add(1)+1;
    if(T<=6 || (T%1500)==0)
      std::fprintf(stderr,"[collectX] T=%llu POST-transpose src=0x%X nz=%d/1536 pk=%.4f (what the transpose actually read+submitted)\n",
        (unsigned long long)T,s2,nz,pk);
  }
}

// RT_TRACEREG: trace the render-kind register method sub_820EF0C0 (=handler vtable[0], called by
// the game's sub_88090360 as handler->vtable[0](handler, descriptor)->16-bit id; 0xFFFF=fail). Shows
// what id each of the 157 registrations returns with our constructed handlers.
extern "C" void __imp__sub_820EF0C0(PPCContext& __restrict, uint8_t*);
static std::atomic<int> g_regcalls{0};
PPC_FUNC(sub_820EF0C0){
  int n=g_regcalls.fetch_add(1);
  uint32_t handler=ctx.r3.u32, desc=ctx.r4.u32;
  uint32_t c24 = (handler&&handler<0xF0000000u)?PPC_LOAD_U32(handler+24):0;
  __imp__sub_820EF0C0(ctx,base);
  if(std::getenv("RT_TRACEREG") && n<12)
    std::fprintf(stderr,"[reg2] sub_820EF0C0#%d handler=0x%X (+24=0x%X) desc=0x%X -> id=0x%X\n",n,handler,c24,desc,ctx.r3.u32&0xFFFF);
}

// ---- RT_MODETICK: empirical diagnostics for the shell-side mode-enter. The dispatcher registers
// the mode-wrapper r28 (from sub_8216AC18, vtable 0x821D1764, holds inner@+16) into the engine-root
// per-frame scheduler (*(0x821F85B0)+156). The frame coordinator sub_8216EA68 -> sub_8216B148 ticks
// that scheduler each main-loop frame. Q: does that tick run + advance the mode-enter (which should
// eventually run the resource-kind factory populating S+16/+0x30/+0x50)? Count ticks + watch the
// handler slots + r28 state, to tell "not ticking" from "ticking but stuck" from "too slow". ----
extern "C" void __imp__sub_8216AC18(PPCContext& __restrict, uint8_t*);
extern "C" void __imp__sub_8216EA68(PPCContext& __restrict, uint8_t*);
extern "C" void __imp__sub_8216B148(PPCContext& __restrict, uint8_t*);
static std::atomic<uint32_t> g_r28{0};
static std::atomic<long> g_ea68{0}, g_b148{0};
// RT_DEFERDRIVER: hold the GameEntry driver until the shell's native mode-enter state machine
// (r28 ticked by the frame loop, kick-started via RT_FORCESTATE) has populated the CB248
// singleton's 3 resource-kind handler slots (S+0x10/0x30/0x50). msg-1 copies those descriptors
// into the game ONCE — firing the driver before the flip hands the game NULL handlers (every
// registration fake-succeeds with id=0) or, worse, inactive ones (first reg fails 0xFFFF).
// Proven empirically: slots flip at ~b148 tick #100 (px_runE 2026-07-05).
static std::atomic<uint32_t> g_defer_inner{0};
static std::atomic<uint32_t> g_s16seen{0};
static void modetick_dump(uint8_t* base, const char* who, long n){
  uint32_t S=PPC_LOAD_U32(0x821F857Cu);
  uint32_t s16=S?PPC_LOAD_U32(S+16):0, s30=S?PPC_LOAD_U32(S+0x30):0, s50=S?PPC_LOAD_U32(S+0x50):0;
  uint32_t r28=g_r28.load();
  std::fprintf(stderr,"[modetick] %s#%ld S=0x%X S+16=0x%X S+0x30=0x%X S+0x50=0x%X r28=0x%X r28.state(+8)=0x%X\n",
    who,n,S,s16,s30,s50,r28,r28?PPC_LOAD_U32(r28+8):0);
  if(s16 && !g_s16seen.exchange(s16))
    std::fprintf(stderr,"[modetick] *** S+16 FLIPPED to 0x%X (handler installed!) at %s#%ld ***\n",s16,who,n);
}
static void dump_vt(uint8_t* base, const char* nm, uint32_t vt){
  if(!vt || vt>=0xF0000000u){ std::fprintf(stderr,"[vt] %s vt=0x%X (unmapped)\n",nm,vt); return; }
  std::fprintf(stderr,"[vt] %s @0x%X:",nm,vt);
  for(int i=0;i<24;++i) std::fprintf(stderr," [%d]=%X",i,PPC_LOAD_U32(vt+i*4));
  std::fprintf(stderr,"\n");
}
PPC_FUNC(sub_8216AC18){
  __imp__sub_8216AC18(ctx,base);
  g_r28 = ctx.r3.u32;   // return = the initialized 96B mode-wrapper (r28)
  static const bool rtModeTickAC18 = std::getenv("RT_MODETICK")!=nullptr;
  if(rtModeTickAC18){
    uint32_t r28=ctx.r3.u32;
    std::fprintf(stderr,"[modetick] sub_8216AC18 -> r28=0x%X vtable=0x%X inner(+16)=0x%X\n",
      r28, r28?PPC_LOAD_U32(r28):0, r28?PPC_LOAD_U32(r28+16):0);
    // Dump the vtables grep can't see (they live in .xex data). One of these methods is the
    // mode update/enter, and one on the engine-root/scheduler is the resource-kind factory.
    dump_vt(base,"r28(0x82051764)",0x82051764u);
    uint32_t inner=r28?PPC_LOAD_U32(r28+16):0;
    dump_vt(base,"inner",inner?PPC_LOAD_U32(inner):0);
    uint32_t S=PPC_LOAD_U32(0x821F857Cu);
    uint32_t sS=S?PPC_LOAD_U32(S):0;
    std::fprintf(stderr,"[vt] engine-root *S=0x%X\n",sS);
    dump_vt(base,"engineroot(*S)",sS?PPC_LOAD_U32(sS):0);
    uint32_t G=PPC_LOAD_U32(0x821F85B0u);
    uint32_t g156=G?PPC_LOAD_U32(G+156):0;
    std::fprintf(stderr,"[vt] G=0x%X *(G+156)=0x%X\n",G,g156);
    dump_vt(base,"scheduler(*(G+156))",g156?PPC_LOAD_U32(g156):0);
  }
}
// RT_POKE: generic per-frame guest-memory poke, for testing "force this flag/state" hypotheses
// without a rebuild each time. Format: comma-separated "addr/val/size" (all hex except size which is
// 1 or 4 decimal). e.g. RT_POKE=887AC973/2/1,884D66A8/6/4 sets bit-value 2 into the loading-done
// byte and forces scene state 6 every frame. Applied on every sub_8216EA68 tick (a per-frame hook),
// so it wins even if the game continually rewrites the location.
static void rt_apply_pokes(uint8_t* base){
  const char* p=std::getenv("RT_POKE");
  if(!p) return;
  static std::atomic<int> logged{0};
  bool first = logged.fetch_add(1)==0;
  char buf[512]; std::strncpy(buf,p,sizeof buf-1); buf[sizeof buf-1]=0;
  for(char* tok=std::strtok(buf,","); tok; tok=std::strtok(nullptr,",")){
    uint32_t addr=0,val=0; int sz=4;
    char* s1=std::strchr(tok,'/'); if(!s1) continue; *s1=0;
    char* s2=std::strchr(s1+1,'/');
    addr=(uint32_t)std::strtoul(tok,nullptr,16);
    val=(uint32_t)std::strtoul(s1+1,nullptr,16);
    if(s2){ *s2=0; sz=std::atoi(s2+1); }
    if(sz==1) *(uint8_t*)(base+addr)=(uint8_t)val;
    else PPC_STORE_U32(addr,val);
    if(first) std::fprintf(stderr,"[poke] *(0x%08X) <- 0x%X (size %d) each frame\n",addr,val,sz);
  }
}
PPC_FUNC(sub_8216EA68){
  long n=g_ea68.fetch_add(1)+1;
  rt_apply_pokes(base);
  // RT_FORCESTATE: force the mode-runner r28's state field (+8) off 0 once, to test whether the
  // resource-kind factory is gated purely on the state value (would flip S+16 on a later tick).
  { const char* fs=std::getenv("RT_FORCESTATE");
    if(fs && g_r28.load()){ uint32_t r28=g_r28.load();
      static std::atomic<int> forced{0};
      if(PPC_LOAD_U32(r28+8)==0 && forced.fetch_add(1)<8){
        PPC_STORE_U32(r28+8,(uint32_t)std::atoi(fs));
        std::fprintf(stderr,"[force] r28+8 0->%d at ea68#%ld\n",std::atoi(fs),n);
      } } }
  __imp__sub_8216EA68(ctx,base);
  { static const bool rtModeTickEA68 = std::getenv("RT_MODETICK")!=nullptr;
    if(rtModeTickEA68 && (n<=10 || n%100==0)) modetick_dump(base,"ea68",n); }
  // RT_DEFERDRIVER: fire the held GameEntry driver once the native factory has populated all 3
  // handler slots — msg-1 then copies REAL handlers into the game (0x885C5BB4/+0x20/+0x40).
  { uint32_t di=g_defer_inner.load();
    if(di){
      uint32_t S=PPC_LOAD_U32(0x821F857Cu);
      if(S && PPC_LOAD_U32(S+0x10) && PPC_LOAD_U32(S+0x30) && PPC_LOAD_U32(S+0x50)){
        if(g_defer_inner.exchange(0)==di){
          std::fprintf(stderr,"[defer] handler slots live (S+0x10=0x%X +0x30=0x%X +0x50=0x%X) at ea68#%ld — driving GameEntry\n",
            PPC_LOAD_U32(S+0x10),PPC_LOAD_U32(S+0x30),PPC_LOAD_U32(S+0x50),n);
          PPCContext ic=ctx; ic.r3.u32=di; rt_indirect_call(ic,base,GAME_DRIVER);
          uint32_t h0=PPC_LOAD_U32(0x885C5BB4u),h1=PPC_LOAD_U32(0x885C5BD4u),h2=PPC_LOAD_U32(0x885C5BF4u);
          std::fprintf(stderr,"[defer] driver complete. GAME handlers h0=0x%X h1=0x%X h2=0x%X (want non-null); arming gametick\n",h0,h1,h2);
          // RT_NATIVETICK: the shell's per-frame tick sub_821C69F0(modectx) only dispatches the
          // game's per-frame GameEntry msg (-> sub_8808FA68 -> NtSetEvent(frame event), the thing
          // RT_SIGEV fakes) when modectx+124==4 && modectx+120==0 && modectx+244!=0. The native
          // mode-select FSM sets +124=4 on load-complete; our injection bypasses it. Set it here,
          // at the same lifecycle point ("driver init done") the native path would.
          { uint32_t f116=PPC_LOAD_U32(di+116),f120=PPC_LOAD_U32(di+120),f124=PPC_LOAD_U32(di+124),f244=PPC_LOAD_U32(di+244);
            std::fprintf(stderr,"[ntick] inner+116=0x%X +120=0x%X +124=0x%X +244=0x%X\n",f116,f120,f124,f244);
            if(std::getenv("RT_NATIVETICK")){
              if(f124!=4){ PPC_STORE_U32(di+124,4); std::fprintf(stderr,"[ntick] set inner+124=4 (was 0x%X)\n",f124); }
              if(f120!=0){ PPC_STORE_U32(di+120,0); std::fprintf(stderr,"[ntick] set inner+120=0 (was 0x%X)\n",f120); }
            }
            // RT_ARMREC: arm mode-record[0] (+68 state, "2" per the shell's own writer at
            // sub_821D11C0) so sub_821C6860's flags check (& 0x00FFCFF3) passes and the tick's
            // modectx dispatch — the native carrier of frame-event/commit/sprites — engages.
            // Record table: *(*(*(0x821F8588)+76)+80), 132-byte records, tick uses index
            // *(modectx+128) (=0 here). Experiment knob to validate the downstream chain.
            if(std::getenv("RT_ARMREC")){
              uint32_t G=PPC_LOAD_U32(0x821F8588u), m=G?PPC_LOAD_U32(G+76):0, T=m?PPC_LOAD_U32(m+80):0;
              if(T){ uint32_t rec=T+0*132, old=PPC_LOAD_U32(rec+68);
                PPC_STORE_U32(rec+68, 2);
                std::fprintf(stderr,"[armrec] G=0x%X mgr=0x%X table=0x%X rec0=0x%X +68: 0x%X -> 2 (recs1-4 +68: 0x%X 0x%X 0x%X 0x%X)\n",
                  G,m,T,rec,old,PPC_LOAD_U32(T+132+68),PPC_LOAD_U32(T+264+68),PPC_LOAD_U32(T+396+68),PPC_LOAD_U32(T+528+68));
              } else std::fprintf(stderr,"[armrec] chain null (G=0x%X)\n",G);
            } }
          g_game_tick_modectx = di;
        }
      }
    } }
}
// ---- [ntick2] instrument the mode-tick dispatch chain (sub_821C69F0's second gate):
// sub_821C6860(r3=*(modectx+244), r4=mode-index, r5=&modectx+148) — nonzero result lets the
// tick run the modectx dispatch (*(modectx+0))[+80], the path that natively carries the
// frame-event signal / commit pump / sprite instantiation. Log first calls + result. ----
// ---- [r28] find the guest-r28 clobberer inside sub_82178778's loop (44/0 SIGFPE):
// wrap each loop callee, report when r28 differs across the call (nonvolatile must be preserved). ----
#define R28_TRAP(FN) \
  extern "C" void __imp__##FN(PPCContext& __restrict, uint8_t*); \
  PPC_FUNC(FN){ uint64_t in=ctx.r28.u64; __imp__##FN(ctx,base); \
    if(ctx.r28.u64!=in){ static std::atomic<int> n{0}; if(n.fetch_add(1)<6) \
      std::fprintf(stderr,"[r28] " #FN " CLOBBERED r28 0x%llX -> 0x%llX (lr=0x%X)\n", \
        (unsigned long long)in,(unsigned long long)ctx.r28.u64,(uint32_t)ctx.lr); } }
// [svc] service-thread diagnostics: sub_821CB108 = the shell service loop (wait *(this+564),
// call cb *(this+572), loop while sub_82088438(*(this+568),1)!=0). It exits IMMEDIATELY in our
// harness ("pre-registration" — session-5). Log the object fields + each 88438 poll result.
extern "C" void __imp__sub_821CB108(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821CB108){
  uint32_t o=ctx.r3.u32;
  std::fprintf(stderr,"[svc] loop ENTER this=0x%X ev564=0x%X ev568=0x%X cb572=0x%X\n",
    o,PPC_LOAD_U32(o+564),PPC_LOAD_U32(o+568),PPC_LOAD_U32(o+572));
  __imp__sub_821CB108(ctx,base);
  std::fprintf(stderr,"[svc] loop EXIT r3=0x%X (this=0x%X ev568=0x%X cb572=0x%X)\n",
    ctx.r3.u32,o,PPC_LOAD_U32(o+568),PPC_LOAD_U32(o+572));
}
extern "C" void __imp__sub_82088438(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_82088438){
  uint32_t h=ctx.r3.u32, a=ctx.r4.u32;
  __imp__sub_82088438(ctx,base);
  static std::atomic<int> n{0}; int i=n.fetch_add(1)+1;
  if(i<=6) std::fprintf(stderr,"[svc] 88438 poll h=0x%X arg=%u -> r3=0x%X\n",h,a,ctx.r3.u32);
}

// ===================================================================================
// [l1gate] LEG-1 WHOLE-SHELL GATE CENSUS  (2026-08-15, P1 leg 1 A/B referee apparatus)
// ADDITIVE AND DEFAULT-OFF: everything below is inert unless RT_L1GATE=<dir> is set.
// It exists because the four instruments the gate needs are all capped or deduped:
//   * [res] (sub_82079FD8) logs only the FIRST call per distinct size -> no size SEQUENCE;
//   * rt_menu_vt_census keeps 8 slots, first-seen-only, and is gated on g_rt_romactive;
//   * [decide] caps at 12 calls; [mstate] prints i<=4 || i%120.
// Records written (one line each, to <dir>/l1seq.txt, append-only, flushed by a 250 ms
// writer thread so a taskkill loses at most a quarter second of a quiescent tail):
//   R <bytes> <lr>          every operator-new (sub_82079FD8) call, uncapped
//   S <vt> <from> <to>      a menu/panel state-machine TRANSITION (thunk-observed)
//   K <modelvt> <item>      a DECIDE commit (sub_821D0CB0), uncapped
// Plus a census snapshot rewritten every ~1 s to <dir>/l1cen.txt:
//   T <slotthunk> <vt> <ticks>   raw per-(state-thunk, vtable) tick counts
// ⚠ WHY TRANSITIONS AND NOT TICKS CARRY THE VERDICT: tick counts are frame counts, and a
// FIFO-pad drive is wall-clock timed, so they carry dwell noise. The TRANSITION sequence and
// the ALLOCATION sequence are event-ordered and therefore comparable A vs B. The tick census
// is supporting evidence (the vtable SET is the part of it that is timing-independent).
// ⚠ SEAM SAFETY: every function wrapped here (82079FD8, 82061D50/D70, 82065AB8/5A78/5A88,
// 82063A58, 821D0CB0) is either __imp__-seamed by the leg-1 decomp TUs or untouched by them,
// so the wrapper fires IDENTICALLY in the pilot and the control link. Never wrap a symbol a
// decomp TU owns with a plain PPC_FUNC — under /FORCE:MULTIPLE the instrument would be dead
// in one arm and live in the other, i.e. the A/B would be measuring the instrument.
#include <thread>
#include <cstdarg>
#include <string>
static const char* rt_l1_dir(){ static const char* d=std::getenv("RT_L1GATE"); return d; }
static bool rt_l1_on(){ static bool on=rt_l1_dir()!=nullptr; return on; }
static std::mutex g_l1_mu;
static std::string g_l1_buf;
static std::atomic<long> g_l1_recs{0};
struct L1Key { uint32_t slot, vt; bool operator==(const L1Key&o)const{return slot==o.slot&&vt==o.vt;} };
struct L1KeyHash { size_t operator()(const L1Key&k)const{ return (size_t)k.slot*1000003u ^ (size_t)k.vt; } };
static std::unordered_map<L1Key,long,L1KeyHash> g_l1_ticks;
static void rt_l1_writer();
static void rt_l1_start(){
  static std::once_flag f;
  std::call_once(f,[]{ g_l1_buf.reserve(1<<20); std::thread(rt_l1_writer).detach(); });
}
static void rt_l1_emit(const char* fmt, ...){
  if(!rt_l1_on()) return;
  rt_l1_start();
  char line[128]; va_list ap; va_start(ap,fmt);
  int n=std::vsnprintf(line,sizeof(line),fmt,ap); va_end(ap);
  if(n<=0) return;
  std::lock_guard<std::mutex> l(g_l1_mu); g_l1_buf.append(line,(size_t)n); g_l1_recs.fetch_add(1);
}
static void rt_l1_tick(uint32_t slot, uint32_t vt){
  if(!rt_l1_on()||!vt) return;
  std::lock_guard<std::mutex> l(g_l1_mu); g_l1_ticks[L1Key{slot,vt}]++;
}
static void rt_l1_writer(){
  const char* d=rt_l1_dir();
  std::string seqp=std::string(d)+"/l1seq.txt", cenp=std::string(d)+"/l1cen.txt";
  FILE* seq=std::fopen(seqp.c_str(),"wb");
  if(!seq){ std::fprintf(stderr,"[l1gate] CANNOT OPEN %s — census DISABLED\n",seqp.c_str()); return; }
  std::fprintf(stderr,"[l1gate] ARMED -> %s (+ %s)\n",seqp.c_str(),cenp.c_str());
  int round=0;
  for(;;){
    std::string out; std::vector<std::pair<L1Key,long>> cen;
    { std::lock_guard<std::mutex> l(g_l1_mu);
      out.swap(g_l1_buf); g_l1_buf.reserve(1<<20);
      if((round%4)==0){ cen.reserve(g_l1_ticks.size()); for(auto&kv:g_l1_ticks) cen.push_back(kv); } }
    if(!out.empty()){ std::fwrite(out.data(),1,out.size(),seq); std::fflush(seq); }
    if(!cen.empty()){
      std::sort(cen.begin(),cen.end(),[](const std::pair<L1Key,long>&a,const std::pair<L1Key,long>&b){
        return a.first.slot!=b.first.slot ? a.first.slot<b.first.slot : a.first.vt<b.first.vt; });
      FILE* c=std::fopen(cenp.c_str(),"wb");
      if(c){ for(auto&kv:cen) std::fprintf(c,"T %X %X %ld\n",kv.first.slot,kv.first.vt,kv.second); std::fclose(c); }
    }
    ++round;
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
  }
}
// ---- [l1cur] CURSOR ORACLE (2026-08-15, round 3) -------------------------------------------
// The whole-shell walk cannot be scripted assert-per-press without knowing where the cursor is,
// and the shipped [mcur] instrument is scoped to ONE vtable (menu_game_title 0x820503B0), so
// the OPTIONS page and every OPTIONS panel are invisible to it. Two cursor fields exist:
//   * menu-family classes  — cursor at +0x9C   (the BA4D8/BB1D8/BB298 chain)
//   * OptionsPanelBase     — cursor at +336    (P_CURSOR, options_panel_base.cpp:178)
// ⚠ The panel read is ALLOWLISTED by vtable on purpose. Reading +336 off a menu-family object
// would be reading past its allocation, and heap garbage differs between runs — which would
// inject fake divergence into the very A/B this instrument exists to serve.
static bool rt_l1_panel_vt(uint32_t vt){
  switch(vt){
    case 0x820506D0u: case 0x820509E0u: case 0x82050A40u: case 0x82050AA0u:
    case 0x82050B00u: case 0x82050BC0u: case 0x82050C20u: case 0x82050F00u:
    case 0x82050730u: case 0x82050868u: case 0x820508C8u: case 0x82050CE8u:
    case 0x82050D48u: case 0x82050DB0u: return true;
    // ⚠ 2026-08-16 (gate round 10): these two were MISSING and the omission was invisible —
    // a panel absent from this list has NO [l1cur] line, so a referee drive reads the cursor of
    // whatever was in front BEFORE it and concludes the panel never opened. That is exactly what
    // happened to Extra Setting: its ctor ran (364 @ lr 0x821A7CD4, Options_ScreenExtra_Build +
    // _OnDecide + _Dtor canaries all fired) while the walk recorded "NOT ENTERED" and skipped
    // every edit in it. 0x82050B60 = Extra Setting, 0x820505B0 = OptionsPanelBase itself.
    case 0x82050B60u: case 0x820505B0u: return true;
    default: return false;
  }
}
// ---- [gstap] SOURCE-STRING TAP on sub_821D3A20 (2026-08-16, gate round 10 residue) ----------
// sub_821D3A20(dst, src) = gstring -> render-string; it allocates 2*len(src) at lr 0x821D3AB4.
// Round 10's deep A/B found the COUNT of those allocations identical per phase but the SIZE MIX
// trading 1:1 -- the pilot reaches this copy with length-1 sources where the control has the true
// 4..14-char caption. This tap answers the one question that splits the two possible causes:
// is the SOURCE already length-1 when it arrives (defect upstream, in whoever builds it), or does
// the copy truncate it (defect in 821B6D20)?
//
// ⚠ IT LIVES HERE, NOT IN THE DECOMP TU, ON PURPOSE. merged_shell.o links into BOTH gate arms,
// so this prints identically on control and pilot and the two streams are directly diffable. An
// instrument inside the decomp C body would only exist on the pilot and could prove nothing.
// ⚠ LANDMINE (memory: PPC_FUNC wrapper CLONE BYPASS): "printed nothing" is NOT proof the body was
// not taken. Read the positive-control count before drawing any conclusion from silence.
extern "C" void __imp__sub_821D3A20(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821D3A20){
  static const bool on = std::getenv("RT_GSTAP")!=nullptr;
  if(on){
    const uint32_t src = ctx.r4.u32;
    if(src){
      const uint32_t size = PPC_LOAD_U32(src + 20);      // gstring::size
      const uint32_t cap  = PPC_LOAD_U32(src + 24);      // >=16 => heap, else inline SSO buffer
      const uint32_t buf  = (cap >= 16u) ? PPC_LOAD_U32(src + 4) : (src + 4);
      char txt[24]; unsigned k = 0;
      for(; k < 20u && k < size; ++k){
        uint8_t c = PPC_LOAD_U8(buf + k);
        txt[k] = (c >= 0x20 && c < 0x7F) ? (char)c : '.';
      }
      txt[k] = '\0';
      std::fprintf(stderr,"[gstap] lr=0x%08X size=%u cap=%u \"%s\"\n", (unsigned)ctx.lr, size, cap, txt);
    } else {
      std::fprintf(stderr,"[gstap] lr=0x%08X src=NULL\n", (unsigned)ctx.lr);
    }
  }
  __imp__sub_821D3A20(ctx,base);
}

// ---- [evtrace] VALUE TRACE on sub_8217D1D8 = PsbMovie_EvaluateAtTime (2026-08-16, round 14) --
// The registry holds 0x8217D1D8 at DRAFT for one reason: "three inlined PSB element reads still
// never probe-isolated". Those reads are INSIDE the body, so no wrapper can see them directly —
// but every one of them terminates in an OBSERVABLE STORE on the movie object, and the three
// stores are disjoint. Dumping them after the call therefore isolates all three:
//     read A -> cursor +320, times +324/+328        (track +312)
//     read B -> cursor +272, times +276/+280, and the WHOLE 8-byte content PsbRef at +284
//     read C -> per layer (stride 524, from index 1): xformA +132, xformB +280, flags +140,
//               dirty +428, result +432
// ⚠ IT LIVES HERE, NOT IN psb_core.cpp, FOR THE SAME REASON [gstap] does: merged_shell.o links
// into EVERY gate arm. The pilot/ctrl arms EXCLUDE the three PSB TUs, so there the __imp__ is the
// GENERATED body; the ship arm links psb_core.o, so there it is the DRAFT. One printf, two arms,
// directly diffable. psb_core.cpp's seam was changed to PPC_FUNC_IMPL(__imp__sub_8217D1D8) in the
// same commit — without that, /FORCE:MULTIPLE keeps the FIRST definition on the link line (the
// decomp object) and this tap vanishes from the ship arm with no diagnostic.
// ⚠ NO RAW POINTERS ARE PRINTED. Heap addresses differ between arms for reasons that have nothing
// to do with this body, and printing them would manufacture divergence in the very diff this tap
// exists to serve. Call ordinal + layer index only.
extern "C" void __imp__sub_8217D1D8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_8217D1D8){
  static const bool on = std::getenv("RT_EVTRACE")!=nullptr;
  if(!on){ __imp__sub_8217D1D8(ctx,base); return; }
  const uint32_t self = ctx.r3.u32;
  static std::atomic<long> n{0}; long i = n.fetch_add(1)+1;
  const uint32_t now  = self?PPC_LOAD_U32(self+184):0;          // raw bits, not %f
  const uint32_t trA  = self?PPC_LOAD_U32(self+312):0;
  const uint32_t trB  = self?PPC_LOAD_U32(self+292):0;
  const uint32_t lb0  = self?PPC_LOAD_U32(self+252):0, le0 = self?PPC_LOAD_U32(self+256):0;
  const int nlay = (self && le0>lb0 && ((le0-lb0)%524u)==0) ? (int)((le0-lb0)/524u) : -1;
  std::fprintf(stderr,"[evtrace] IN  #%ld now=%08X trackA=%s trackB=%s layers=%d\n",
    i,now,trA?"y":"n",trB?"y":"n",nlay);
  __imp__sub_8217D1D8(ctx,base);
  if(!self) return;
  std::fprintf(stderr,"[evtrace] A   #%ld cur=%u t0=%08X t1=%08X\n",
    i,PPC_LOAD_U32(self+320),PPC_LOAD_U32(self+324),PPC_LOAD_U32(self+328));
  std::fprintf(stderr,"[evtrace] B   #%ld cur=%u t0=%08X t1=%08X content=%08X%08X\n",
    i,PPC_LOAD_U32(self+272),PPC_LOAD_U32(self+276),PPC_LOAD_U32(self+280),
    PPC_LOAD_U32(self+284),PPC_LOAD_U32(self+288));
  const uint32_t lb = PPC_LOAD_U32(self+252), le = PPC_LOAD_U32(self+256);
  if(le>lb && ((le-lb)%524u)==0){
    int cnt=(int)((le-lb)/524u);
    for(int k=1;k<cnt && k<64;k++){
      uint32_t L=lb+(uint32_t)k*524u;
      std::fprintf(stderr,"[evtrace] L%02d #%ld xA=%08X %08X %08X %08X xB=%08X %08X %08X %08X fl=%08X d=%u r=%08X\n",
        k,i,PPC_LOAD_U32(L+132),PPC_LOAD_U32(L+136),PPC_LOAD_U32(L+144),PPC_LOAD_U32(L+148),
        PPC_LOAD_U32(L+280),PPC_LOAD_U32(L+284),PPC_LOAD_U32(L+288),PPC_LOAD_U32(L+292),
        PPC_LOAD_U32(L+140),(unsigned)PPC_LOAD_U8(L+428),PPC_LOAD_U32(L+432));
    }
  }
}
// ---- [psbfmt] PLATFORM / FORMAT TOKEN TAP inside the PSB image loader (round 14, job 4) ------
// 0x820787E0 Win_ExpandCI4's ONLY caller is sub_821680D0 (0x821680D0..0x82168E48) at lr
// 0x82168D44, inside the `win` arm of a FIVE-WAY PLATFORM DISPATCH on root["spec"], behind a
// second "CI4" token test. Reachability is therefore a DATA question, and the shell's PSBs are
// LZX-packed on disk — so ask the loader instead of the container. Both compare helpers are
// tapped (the loader deliberately uses two: sub_820654F8(str,len,lit,litlen) int 0==equal for
// revo/psp/ps3/win and win's RGBA8; sub_820659A0(str,cstr) bool for win's CI8/CI4 and BOTH x360
// tests — DO-NOT-FIX 4). lr-filtered to the loader's extent so the other ~12 call sites of
// 820654F8 elsewhere in the shell cost nothing.
static inline void psbfmt_lit(uint8_t* base, uint32_t p, char* out, int cap){
  int k=0; for(; k<cap-1 && p; ++k){ uint8_t c=PPC_LOAD_U8(p+(uint32_t)k); if(!c) break;
    out[k]=(c>=0x20&&c<0x7F)?(char)c:'.'; } out[k]='\0'; }
static inline bool psbfmt_in_loader(uint32_t lr){ return lr>=0x82168000u && lr<0x82169000u; }
extern "C" void __imp__sub_820654F8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820654F8){
  static const bool on = std::getenv("RT_PSBFMT")!=nullptr;
  uint32_t lr=(uint32_t)ctx.lr, lit=ctx.r5.u32, n=ctx.r6.u32;
  bool want = on && psbfmt_in_loader(lr);
  __imp__sub_820654F8(ctx,base);
  if(want){ char t[24]; psbfmt_lit(base,lit,t,sizeof t);
    std::fprintf(stderr,"[psbfmt] cmpN lr=0x%08X lit=\"%s\" n=%u -> %d%s\n",
      lr,t,n,(int)ctx.r3.u32,(int)ctx.r3.u32==0?"  MATCH":""); }
}
extern "C" void __imp__sub_820659A0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820659A0){
  static const bool on = std::getenv("RT_PSBFMT")!=nullptr;
  uint32_t lr=(uint32_t)ctx.lr, lit=ctx.r4.u32;
  bool want = on && psbfmt_in_loader(lr);
  __imp__sub_820659A0(ctx,base);
  if(want){ char t[24]; psbfmt_lit(base,lit,t,sizeof t);
    std::fprintf(stderr,"[psbfmt] cmpZ lr=0x%08X lit=\"%s\" -> %d%s\n",
      lr,t,(int)ctx.r3.u32,(int)ctx.r3.u32!=0?"  MATCH":""); }
}
// The CI4 decoder itself: a canary with the loader tap above as its positive control. Silence
// here alone would prove nothing (PPC_FUNC wrapper CLONE BYPASS); silence PLUS a loader that
// demonstrably ran its platform tests N times is the terminal evidence.
extern "C" void __imp__sub_820787E0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820787E0){
  static std::atomic<long> n{0};
  std::fprintf(stderr,"[psbfmt] ★ Win_ExpandCI4 0x820787E0 CALLED #%ld lr=0x%08X\n",
    n.fetch_add(1)+1,(uint32_t)ctx.lr);
  __imp__sub_820787E0(ctx,base);
}

static void rt_l1_cursor(uint8_t* base, uint32_t obj, uint32_t vt){
  if(!rt_l1_on() || !obj || !vt) return;
  bool panel = rt_l1_panel_vt(vt);
  // ⚠ 2026-08-16 (round 11): the menu list had the SAME gap the panel list had — three of the
  // seven classes in the 821BB670/821BA4D8 family were missing, so any drive through them read a
  // stale cursor and concluded "never opened" (round 10's Extra lesson, second instance).
  // 0x820503F8 = the NORMAL PLAY page (FUN_821CFD30) — the parent of the Config panel, whose
  // vt+0x1C item-action dispatcher 0x821D03A8 builds it on item id 2. Without it the Config
  // route cannot be driven at all. 0x820502E0 and 0x82050488 are the other two of the seven.
  bool menu  = (vt==0x820503B0u||vt==0x820504D0u||vt==0x82050518u||vt==0x82050440u||vt==0x82050574u
                ||vt==0x820503F8u||vt==0x820502E0u||vt==0x82050488u);
  if(!panel && !menu) return;
  uint32_t cur = PPC_LOAD_U32(obj + (panel ? 336u : 0x9Cu));
  static std::mutex m; static std::unordered_map<uint32_t,uint32_t> last;
  uint32_t prev; bool first;
  { std::lock_guard<std::mutex> l(m); auto it=last.find(obj); first=(it==last.end());
    prev = first?0u:it->second; last[obj]=cur; }
  if(first || prev==cur) return;
  rt_l1_emit("C %X %u %u\n", vt, prev, cur);
  std::fprintf(stderr,"[l1cur] vt=0x%X obj=0x%X cursor %u->%u%s\n", vt, obj, prev, cur,
              panel ? " (panel+336)" : " (menu+9C)");
}

// The six state thunks of the shared menu/panel state ring (NOTE_options_base.md §0.B.5).
// Each is a 4-instruction dispatch of ONE vtable slot; the object's current state pointer
// lives at +0x48 (== this+72). Observing +0x48 across the call yields the transition edge.
#define L1_STATE_THUNK(ADDR)                                                             \
  extern "C" void __imp__sub_##ADDR(PPCContext& __restrict, uint8_t*);                   \
  PPC_FUNC(sub_##ADDR){                                                                  \
    uint32_t o=ctx.r3.u32, vt=o?PPC_LOAD_U32(o):0, s0=o?PPC_LOAD_U32(o+0x48):0;          \
    rt_l1_tick(0x##ADDR##u, vt);                                                         \
    __imp__sub_##ADDR(ctx,base);                                                         \
    uint32_t s1=o?PPC_LOAD_U32(o+0x48):0;                                                \
    if(s1!=s0) rt_l1_emit("S %X %X %X\n",vt,s0,s1);                                      \
  }
L1_STATE_THUNK(82065AB8)   // decide-commit  (dispatches vt+0x38)
L1_STATE_THUNK(82065A78)   // cancel-commit  (dispatches vt+0x3C)
L1_STATE_THUNK(82065A88)   // slide-out      (dispatches vt+0x40)
L1_STATE_THUNK(82063A58)   // terminal       (dispatches vt+0x44)

// [res] sub_82079FD8(id) = shell resource-registry getter (the long-suspected session-4
// "config/feature getter"). Census: log each distinct id's first result + totals.
// ⚠ CORRECTED 2026-08-15 (NOTE_menu_containers.md §3.4 / NOTE_options_idiom.md §0.B B9):
// this is operator new and r3 is a BYTE COUNT, not an id. Every historical "[res] id=NNN"
// line is an allocation SIZE.
extern "C" void __imp__sub_82079FD8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_82079FD8){
  uint32_t id=ctx.r3.u32;
  rt_l1_emit("R %u %X\n",id,(uint32_t)ctx.lr);   // [l1gate] uncapped allocation-size sequence
  __imp__sub_82079FD8(ctx,base);
  static std::mutex m; static std::unordered_map<uint32_t,std::pair<long,uint32_t>> seen;
  bool log=false; uint32_t r=ctx.r3.u32;
  { std::lock_guard<std::mutex> l(m); auto&e=seen[id]; e.first++; if(e.first==1||(e.second==0)!=(r==0)){ log=true; e.second=r; } }
  if(log) std::fprintf(stderr,"[res] id=%u -> 0x%X (lr=0x%X)\n",id,r,(uint32_t)ctx.lr);
  // [wpgate] targeted: the SECOND alloc inside sub_821CB4F8 (lr=0x821CB5C4, id=60)
  // is the one whose result becomes DAT_821F8574. Log it unconditionally (bypass dedup).
  if((uint32_t)ctx.lr==0x821CB5C4u) std::fprintf(stderr,"[wpgate] CB4F8-alloc60 -> r3=0x%X\n",r);
}

// [doc] sub_8217B6A8(r3, r4=UI document object): log caller + doc per call — trace where the
// (currently NULL) document should come from.
extern "C" void __imp__sub_8217B6A8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_8217B6A8){
  static std::atomic<int> n{0}; int i=n.fetch_add(1)+1;
  // (menu-layout leg) r4 = the LAYER object bound into the movie loader; calls from
  // BB3A8 (model build) always log so the in-session menu bind is visible past the cap.
  bool fromBB3A8=((uint32_t)ctx.lr>=0x821BB3A8u&&(uint32_t)ctx.lr<0x821BB670u);
  if(i<=60||fromBB3A8) std::fprintf(stderr,"[doc] #%d lr=0x%X r3=0x%X doc(r4)=0x%X doc+44=0x%X\n",
    i,(uint32_t)ctx.lr,ctx.r3.u32,ctx.r4.u32,ctx.r4.u32?PPC_LOAD_U32(ctx.r4.u32+44):0);
  static const bool contain = std::getenv("RT_EHCONTAIN")!=nullptr;
  if(contain){
    PPCContext save = ctx; __imp__sub_8217B6A8(ctx,base); uint64_t r3=ctx.r3.u64;
    if(ctx.r1.u64 != save.r1.u64){ static std::atomic<int> c{0}; if(c.fetch_add(1)<8)
      std::fprintf(stderr,"[ehcontain] sub_8217B6A8 leaked -> contained, r3=0x%llX\n",(unsigned long long)r3); }
    ctx = save; ctx.r3.u64 = r3;
  } else {
    __imp__sub_8217B6A8(ctx,base);
  }
  if(i<=60) std::fprintf(stderr,"[doc] #%d -> r3=0x%X\n",i,ctx.r3.u32);
}

// [lookup2] sub_821753C8(outer, name, out): log caller + outer + *(outer)=inner per call.
extern "C" void __imp__sub_821753C8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821753C8){
  static std::atomic<int> n{0}; int i=n.fetch_add(1)+1;
  if(i<=6){
    uint32_t o=ctx.r3.u32, inner=o?PPC_LOAD_U32(o):0, name=ctx.r4.u32;
    char nm[32]={0}; for(int k=0;k<31&&name;k++){ char c=(char)PPC_LOAD_U8(name+k); if(!c)break; nm[k]=c; }
    std::fprintf(stderr,"[lookup2] #%d lr=0x%X outer=0x%X inner=0x%X inner+12=0x%X name=\"%s\"\n",
      i,(uint32_t)ctx.lr,o,inner,inner?PPC_LOAD_U32(inner+12):0,nm);
  }
  // RT_EHCONTAIN: the lookup-fail path inside is an MSVC throw whose unwind we don't
  // implement — the stubbed terminal import RETURNS and leaks a 0xB00 stack frame +
  // clobbers nonvolatiles (the SIGFPE cascade). By PPC ABI the caller only owns r3 +
  // memory effects, so snapshotting the ENTIRE context and restoring all-but-r3 after
  // the call is semantics-preserving for successful calls AND converts the fatal into
  // a clean "lookup failed" (r3=0) — which every caller already handles.
  static const bool contain = std::getenv("RT_EHCONTAIN")!=nullptr;
  if(contain){
    PPCContext save = ctx;
    __imp__sub_821753C8(ctx,base);
    uint64_t r3 = ctx.r3.u64;
    bool leaked = (ctx.r1.u64 != save.r1.u64);
    ctx = save; ctx.r3.u64 = r3;
    if(leaked){ static std::atomic<int> c{0}; if(c.fetch_add(1)<12)
      std::fprintf(stderr,"[ehcontain] sub_821753C8 leaked (fatal path) -> contained, r3=0x%llX\n",(unsigned long long)r3); }
    return;
  }
  uint64_t in=ctx.r28.u64; __imp__sub_821753C8(ctx,base);
  if(ctx.r28.u64!=in){ static std::atomic<int> c{0}; if(c.fetch_add(1)<4)
    std::fprintf(stderr,"[r28] sub_821753C8 CLOBBERED r28\n"); }
}
R28_TRAP(sub_8207BC98)
R28_TRAP(sub_8207B288)
R28_TRAP(sub_82175AE8)
// ===== RT_CONTLIFE (2026-07-24 menu-cancel movie-container leak census) =====
// Decomp of the B-cancel path (ForceFunc-corrected FUN_821d0cb0): DECIDE item=-1 -> LAB_821d10f8
// spawns the confirm task via sub_821BD8B8 (vt 0x82050254), pushes it on menu+0x24, sets
// menu+0x9c=6 and menu state +0x48=0x82063a58. The confirm task's deleting dtor is vt[0]=
// sub_82063AB8 -> base-dtor sub_821BD2C0, which destroys its two child lists (+0x10,+0x2c) via
// sub_82173A18 -> so a properly-destructed task frees its child movie containers. The movie
// CONTAINER is ctor sub_8217AA80 (vt 0x82051494), dtor sub_8206D530 (frees via 82179930 +
// operator delete when flag&1). This probe times each confirm task's lifetime IN GUEST FRAMES
// (heartbeat-clocked) and the state fn it dies from, and counts container born vs freed, to
// discriminate the SDK-referee double-fire hypothesis (instant same-press "No" self-close that
// orphans the container) from a stuck/never-freed task.
// g_rt_menu_heartbeat (defined ~line 815) = per-guest-frame clock while a menu ticks; used here as the lifetime clock.
static bool rt_contlife(){ static bool v=std::getenv("RT_CONTLIFE")!=nullptr; return v; }
static std::atomic<long> g_ctl_c_born{0}, g_ctl_c_freed{0};   // movie container born/freed
static std::atomic<long> g_ctl_t_born{0}, g_ctl_t_freed{0};   // confirm task born/freed
static std::atomic<long> g_ctl_release{0};                    // sub_82173A18 child-list-destroy invocations
// tiny lock-guarded birth-frame table for confirm tasks (few live at once) -> lifetime in frames
static std::mutex g_ctl_mtx; static uint32_t g_ctl_taskAddr[64]; static unsigned int g_ctl_taskHb[64];
static void ctl_task_birth(uint32_t a){ if(!a)return; std::lock_guard<std::mutex> lk(g_ctl_mtx);
  for(int i=0;i<64;i++){ if(g_ctl_taskAddr[i]==0){ g_ctl_taskAddr[i]=a; g_ctl_taskHb[i]=g_rt_menu_heartbeat; return; } }
}
static unsigned int ctl_task_life(uint32_t a){ if(!a)return 0xFFFFFFFFu; std::lock_guard<std::mutex> lk(g_ctl_mtx);
  for(int i=0;i<64;i++){ if(g_ctl_taskAddr[i]==a){ unsigned int b=g_ctl_taskHb[i]; g_ctl_taskAddr[i]=0;
    return (unsigned int)(g_rt_menu_heartbeat - b); } } return 0xFFFFFFFFu; }
static const char* ctl_state_name(uint32_t s){
  switch(s){ case 0x82061D50u:return "idle"; case 0x82061D70u:return "confirm"; case 0x82065A88u:return "close";
    case 0x821BD7E8u:return "init(bd7e8)"; case 0x82063A58u:return "menu-commit(3a58)"; case 0x82065A78u:return "leave(5a78)";
    default:return "?"; } }
static void rt_contlife_born_container(uint8_t* base,uint32_t c,uint32_t lr){
  if(!rt_contlife()||!c) return;
  long b=g_ctl_c_born.fetch_add(1)+1; long fr=g_ctl_c_freed.load();
  std::fprintf(stderr,"[contlife] CONT-BORN cont=0x%X vt=0x%X hb=%u lr=0x%X | cborn=%ld cfreed=%ld calive=%ld\n",
    c,PPC_LOAD_U32(c),(unsigned)g_rt_menu_heartbeat,lr,b,fr,b-fr);
}
// level 2: callees of sub_821753C8 — also watch r1 (stack-shift = the session-6 r1-leak signature).
// With RT_EHCONTAIN these become full ABI-containment wrappers (see sub_821753C8 above): the
// fatal/throw path inside leaks a 0xB00 frame; restoring everything-but-r3 is semantics-
// preserving per PPC ABI and stops the poison from propagating to callers like the stream
// parser sub_82178778 (whose divw on garbage r28 was the SIGFPE).
#define R1_TRAP(FN) \
  extern "C" void __imp__##FN(PPCContext& __restrict, uint8_t*); \
  PPC_FUNC(FN){ \
    static const bool contain = std::getenv("RT_EHCONTAIN")!=nullptr; \
    if(contain){ \
      PPCContext save = ctx; __imp__##FN(ctx,base); uint64_t r3=ctx.r3.u64; \
      bool leaked = (ctx.r1.u64 != save.r1.u64); \
      ctx = save; ctx.r3.u64 = r3; \
      if(leaked){ static std::atomic<int> n{0}; if(n.fetch_add(1)<8) \
        std::fprintf(stderr,"[ehcontain] " #FN " leaked -> contained, r3=0x%llX\n",(unsigned long long)r3); } \
      return; } \
    uint64_t in28=ctx.r28.u64, in1=ctx.r1.u64; __imp__##FN(ctx,base); \
    if(ctx.r28.u64!=in28 || ctx.r1.u64!=in1){ static std::atomic<int> n{0}; if(n.fetch_add(1)<6) \
      std::fprintf(stderr,"[r1] " #FN " r28 0x%llX->0x%llX r1 0x%llX->0x%llX\n", \
        (unsigned long long)in28,(unsigned long long)ctx.r28.u64,(unsigned long long)in1,(unsigned long long)ctx.r1.u64); } }
// [lookup] sub_821751C8(obj r3, name r4, out r5) = binary-search a name in the loaded
// archive index (obj+16=index buffer, obj+20=string-table offset). Log the requested name,
// the object state, and the buffer head to see why lookups fail under RT_ASYNCIO.
extern "C" void __imp__sub_821751C8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821751C8){
  uint32_t obj=ctx.r3.u32, name=ctx.r4.u32;
  static std::atomic<int> n{0}; int i=n.fetch_add(1)+1;
  if(i<=6){
    uint32_t st=PPC_LOAD_U32(obj+12), buf=PPC_LOAD_U32(obj+16), stroff=PPC_LOAD_U32(obj+20);
    char nm[40]={0}; for(int k=0;k<39&&name;k++){ char c=(char)PPC_LOAD_U8(name+k); if(!c)break; nm[k]=c; }
    std::fprintf(stderr,"[lookup] #%d lr=0x%X obj=0x%X st=%u buf=0x%X stroff=0x%X name=\"%s\" bufhead=",i,(uint32_t)ctx.lr,obj,st,buf,stroff,nm);
    for(int k=0;k<16;k++) std::fprintf(stderr,"%02x",buf?PPC_LOAD_U8(buf+k):0);
    std::fprintf(stderr,"\n");
  }
  static const bool contain = std::getenv("RT_EHCONTAIN")!=nullptr;
  if(contain){
    PPCContext save = ctx; __imp__sub_821751C8(ctx,base); uint64_t r3=ctx.r3.u64;
    bool leaked = (ctx.r1.u64 != save.r1.u64);
    ctx = save; ctx.r3.u64 = r3;
    if(leaked){ static std::atomic<int> c{0}; if(c.fetch_add(1)<8)
      std::fprintf(stderr,"[ehcontain] sub_821751C8 leaked -> contained, r3=0x%llX\n",(unsigned long long)r3); }
  } else {
    __imp__sub_821751C8(ctx,base);
  }
  if(i<=6) std::fprintf(stderr,"[lookup] #%d -> r3=0x%X\n",i,ctx.r3.u32);
}
R1_TRAP(sub_82173F78)
R1_TRAP(sub_82174818)
R1_TRAP(sub_82174A60)
R1_TRAP(sub_82174AF8)
// direct callees of the doc-build sub_821CD4B0 that can hit the fatal internally and
// clobber nonvolatiles (observed: ctx.r30 -> 0 across a callee => divw 524/0 SIGFPE
// inside CD4B0 itself once the r1-leak cascade was contained one level down):
// sub_8217C468 gets a custom contain+log wrapper: log args + caller before the call.
// (menu-layout leg) g_menuMovieCtx = the menu_game_title PSB movie ctx, stashed by the
// class-gated BB298/BA4D8 wrappers below; [mplay]/[namefind]/[itempos] focus on it.
static std::atomic<uint32_t> g_menuMovieCtx{0};
static std::atomic<uint32_t> g_menuLoader{0};
extern "C" void __imp__sub_8217C468(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_8217C468){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  if(i<=12) std::fprintf(stderr,"[parse] C468#%ld lr=0x%X r3=0x%X r4=0x%X r5=0x%X\n",
    i,(uint32_t)ctx.lr,ctx.r3.u32,ctx.r4.u32,ctx.r5.u32);
  // [mplay] (menu-layout leg): C468 = play-labeled-movie-section (r4 = label c-string,
  // e.g. 'open'/'stand' for menu_game_title). RT_MENULOG logs the label unthrottled-ish.
  { static bool mlog=std::getenv("RT_MENULOG")!=nullptr;
    static std::atomic<long> mp{0}, mpm{0};
    bool isMenu=(ctx.r3.u32==g_menuMovieCtx.load());
    if(mlog && (mp.fetch_add(1)<60 || (isMenu&&mpm.fetch_add(1)<40)))
      std::fprintf(stderr,"[mplay] ctx=0x%X%s label=%.24s r5=%u lr=0x%X\n",
        ctx.r3.u32,isMenu?"(MENU)":"",ctx.r4.u32?(const char*)(base+ctx.r4.u32):"(null)",ctx.r5.u32,(uint32_t)ctx.lr); }
  static const bool contain = std::getenv("RT_EHCONTAIN")!=nullptr;
  if(contain){
    PPCContext save = ctx; __imp__sub_8217C468(ctx,base); uint64_t r3=ctx.r3.u64;
    bool leaked = (ctx.r1.u64 != save.r1.u64);
    ctx = save; ctx.r3.u64 = r3;
    if(leaked){ static std::atomic<int> c{0}; if(c.fetch_add(1)<8)
      std::fprintf(stderr,"[ehcontain] sub_8217C468 leaked -> contained, r3=0x%llX\n",(unsigned long long)r3); }
  } else {
    __imp__sub_8217C468(ctx,base);
  }
  if(i<=12) std::fprintf(stderr,"[parse] C468#%ld -> r3=0x%X\n",i,ctx.r3.u32);
}
// sub_8217AA80 = the MOVIE CONTAINER ctor (installs vt 0x82051494; vt+0x08=0x82179e68 emit,
// vt[0]=dtor 0x8206d530). Keeps the R1_TRAP r1/r28 stack-leak guard AND, under RT_CONTLIFE,
// records each container BIRTH (return r3 = the new container) for the menu-cancel leak census.
extern "C" void __imp__sub_8217AA80(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_8217AA80){
  static const bool contain = std::getenv("RT_EHCONTAIN")!=nullptr;
  uint32_t lr=(uint32_t)ctx.lr;
  if(contain){
    PPCContext save = ctx; __imp__sub_8217AA80(ctx,base); uint64_t r3=ctx.r3.u64;
    bool leaked = (ctx.r1.u64 != save.r1.u64);
    ctx = save; ctx.r3.u64 = r3;
    if(leaked){ static std::atomic<int> n{0}; if(n.fetch_add(1)<8)
      std::fprintf(stderr,"[ehcontain] sub_8217AA80 leaked -> contained, r3=0x%llX\n",(unsigned long long)r3); }
    rt_contlife_born_container(base,ctx.r3.u32,lr);
    return; }
  uint64_t in28=ctx.r28.u64, in1=ctx.r1.u64; __imp__sub_8217AA80(ctx,base);
  if(ctx.r28.u64!=in28 || ctx.r1.u64!=in1){ static std::atomic<int> n{0}; if(n.fetch_add(1)<6)
    std::fprintf(stderr,"[r1] sub_8217AA80 r28 0x%llX->0x%llX r1 0x%llX->0x%llX\n",
      (unsigned long long)in28,(unsigned long long)ctx.r28.u64,(unsigned long long)in1,(unsigned long long)ctx.r1.u64); }
  rt_contlife_born_container(base,ctx.r3.u32,lr);
}
// (sub_821751C8 has the dedicated [lookup] wrapper above)
// [wpgate] ROOT CAUSE (live-traced, 2026-07-13, superseding the sub_820BE150/null-vtable
// theory -- that indirect-dispatch chain is never even reached: 0 "[indirect] UNMAPPED" hits
// occurred anywhere in an entire traced run, and the real recompiled machine code
// (ppc_recomp.29.cpp / ppc_recomp.28.cpp) shows sub_82181EC8 calling ONLY sub_82181C60, which
// never reaches sub_820BE150 at all). The real bug: sub_82181EC8 sets r31=this (its own working
// copy of the param), calls sub_82181C60, then LATER does `mr r3,r31` to return `this` -- so r31
// must survive the call to sub_82181C60 unclobbered (PPC ABI: r31 is non-volatile, callee-saved).
// An r1-snapshot/restore probe (the same idiom as R1_TRAP used elsewhere in this file) showed
// r1 is NOT disturbed by the call -- so this is a narrower bug than the other leaked-stack-frame
// sites: r31 itself gets clobbered to 0 somewhere inside sub_82181C60's call tree (most likely
// via sub_8217FAA8, called unconditionally on first-run init) without the stack pointer itself
// moving, i.e. its own __savegprlr_29/__restgprlr_29 non-volatile save/restore isn't holding
// for r31 on that path. This matches the same clobbered-non-volatile-register bug class already
// tracked for r26 (out_reco/rt.cpp "[clob] indirect@15012 ... CLOBBER") and r28 (R1_TRAP's r28
// watch) elsewhere in this port. Fix: explicitly save/restore r31 around the call (independent
// of whatever sub_82181C60 itself does/fails to do for its OWN frame), gated on RT_WALLPAPER
// (default off) so it's isolated/verifiable separately from the blanket RT_EHCONTAIN sites.
extern "C" void __imp__sub_82181C60(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_82181C60){
  static const bool wp = std::getenv("RT_WALLPAPER")!=nullptr;
  if(wp){
    uint64_t r31_in = ctx.r31.u64;
    __imp__sub_82181C60(ctx,base);
    if(ctx.r31.u64 != r31_in){
      static std::atomic<int> c{0}; if(c.fetch_add(1)<8)
        std::fprintf(stderr,"[wpgate] sub_82181C60 CLOBBERED r31 0x%llX -> 0x%llX -- restoring (non-volatile per ABI)\n",
          (unsigned long long)r31_in,(unsigned long long)ctx.r31.u64);
      ctx.r31.u64 = r31_in;
    }
    return;
  }
  __imp__sub_82181C60(ctx,base);
}
extern "C" void __imp__sub_821C6860(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821C6860){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  uint32_t r3=ctx.r3.u32, r4=ctx.r4.u32, r5=ctx.r5.u32;
  __imp__sub_821C6860(ctx,base);
  if(i<=8 || (i%600==0)) std::fprintf(stderr,"[ntick2] 6860#%ld obj=0x%X mode=%d slot148=0x%X -> r3=0x%X\n",
    i, r3, (int)r4, r5?PPC_LOAD_U32(r5):0, ctx.r3.u32);
}
extern "C" void rt_watch_arm_dyn(uint32_t guestAddr, uint32_t len);   // harness.cpp guard-page watch
// [lstate] (2026-07-23 +124-writer leg): entry counters for the launch-task +0x48 states —
// 33e0 (post-menu teardown), 35e0 (launch dispatcher by flavor +0x6c: 0->+7c=1, 1->+7c=2,
// 3->create loader + state 3530), 39a8 (mode dispatcher). Which ones run names where the
// chain parks. First 3 + every 600 each.
#define LSTATE_WRAP(FN) \
  extern "C" void __imp__##FN(PPCContext& __restrict, uint8_t*); \
  PPC_FUNC(FN){ \
    static std::atomic<long> n{0}; long i=n.fetch_add(1)+1; \
    if(i<=3||i%600==0){ uint32_t t=ctx.r3.u32; \
      std::fprintf(stderr,"[lstate] " #FN "#%ld task=0x%X flavor6c=0x%X\n",i,t,t?PPC_LOAD_U32(t+0x6c):0); } \
    __imp__##FN(ctx,base); \
  }
LSTATE_WRAP(sub_821C33E0)
LSTATE_WRAP(sub_821C35E0)
LSTATE_WRAP(sub_821C32F8)
// [ptask] (2026-07-23 draw-gate leg): page-menu task census — ctor FUN_821d05e8, page
// dispatchers FUN_821d0cb0/FUN_821d11c0 (param_2 = page id; training built at page-2 branch
// via FUN_821966d0). Which run + with what page ids => where the draw chain stops.
#define PTASK_WRAP(FN) \
  extern "C" void __imp__##FN(PPCContext& __restrict, uint8_t*); \
  PPC_FUNC(FN){ \
    static std::atomic<long> n{0}; long i=n.fetch_add(1)+1; \
    if(i<=6||i%600==0) std::fprintf(stderr,"[ptask] " #FN "#%ld r3=0x%X r4=0x%X lr=0x%X\n", \
      i,ctx.r3.u32,ctx.r4.u32,(uint32_t)ctx.lr); \
    __imp__##FN(ctx,base); \
  }
// ===== RT_CANCELLIFE (2026-07-24 menu-cancel leak leg) =====
// B (cancel / DECIDE item=-1) on the summoned SYSTEM MENU spawns a kind-2 modal "dialog"
// (vt 0x82050200; +0xf4=kind, +0xfc=indicator-kind, +0x100=timeout ctr, +0x48=state fn)
// via sub_821BD670, plus a movie doc + 3 FCF0 sound objs. Intended teardown (decomp): the
// state fn +0x48 walks idle(82061d50) -> confirm(82061d70) -> slide-out(sub_821BEED8),
// gated by the timeout poll sub_821BD1B8, then the DESTRUCTOR sub_821BD5B8 runs (hides the
// CRscIndicator via 821ccaf8/821cc9a8(ind,0), frees the name, base-dtor 821be788 detaches
// child nodes). This probe counts births vs destructs and watches whether a kind-2 dialog
// EVER advances / enters slide-out. If freed<born and no kind-2 reaches BEED8/821BD5B8, the
// teardown never runs and the accumulating containers ARE the permanent 48fps regime.
static bool rt_cancellife(){ static bool v=std::getenv("RT_CANCELLIFE")!=nullptr; return v; }
static std::atomic<long> g_cl_born{0}, g_cl_freed{0}, g_cl_slideout{0};

// ===== D1 field-gfx probes (RT_D1PROBE) — P1 (loading-box dismiss discriminator) + P2 (strip compose parity) =====
// Grounded in NOTE_field_gfx_defects.md (D1 root-cause verdict, wf_5d738027-bc5).
//  P1 (D1-A): reads the boot-gated dismiss preconditions the guest hide-chain waits on —
//   crsc=*(0x821F856C); 0x1ec (all 8 CRsc banks Prepared); sound-mgr ready
//   *(*(*(0x821F8588)+0x54)+0x5c); indicator ind=*(crsc+0x1f0) +0x70/+0x71/+0x78; plus hit
//   counters on the dismiss-gate state (ce4b8), the bank-wait state (cd270) and the indicator
//   pump (cd120, per-frame anchor while the box is alive). Discriminator table (note §D1-A):
//     i-a: 0x1ec==0 (a bank load never completes -> log waitIdx);
//     i-b: 0x1ec==1 & snd_ready==0 (sound FSM parked -> log snd_state +0x48);
//     ii : both==1 & ind+0x71==1 & ce4b8 hits frozen (dismiss state never ticked);
//     iii: ind+0x71==0 & ind+0x78 frozen >0 (pump/walker starved, fade never completes).
//  P2 (D1-B): for the parked dialog_flame container (grow/slide pair (container+0x2c/+0x30)
//   at (0,0)) read the ACTUAL pushed emit-entry XY/scale via the record-walk 82179e68 -> emit
//   push 82178d78. (0,0)+full-size emit => layer/compose-gate fix; scaled/zeroed emit =>
//   vk_render field-consumption fix. Container reached from BE500 asm as *(engine+0x50); pair
//   written at cont+0x2c/+0x30; movieCtx=cont+0x10; records at movieCtx+0xfc..+0x100 stride 0x20c.
static bool rt_d1probe(){ static bool v=std::getenv("RT_D1PROBE")!=nullptr; return v; }
static std::atomic<long> g_p1_ce4b8{0}, g_p1_cd270{0}, g_p1_cd120{0};
static std::atomic<int>  g_inFlameWalk{0};
static std::atomic<uint32_t> g_flameContainer{0};
// dialog_flame movie ctxs, registered by the name resolver (sub_8217B2A0) on a 'dialog_flame'
// name-hit. These are the ×1 replay-speed strip movies (11 recs, label 'stand'). container=ctx-0x10.
static std::atomic<uint32_t> g_flameCtx[8]={};
static bool rt_isFlameCtx(uint32_t ctx){ if(!ctx) return false; for(int k=0;k<8;k++){ uint32_t v=g_flameCtx[k].load(); if(!v) break; if(v==ctx) return true; } return false; }
static void rt_regFlameCtx(uint32_t ctx){ if(!ctx) return; for(int k=0;k<8;k++){ uint32_t v=g_flameCtx[k].load(); if(v==ctx) return; if(!v){ uint32_t exp=0; if(g_flameCtx[k].compare_exchange_strong(exp,ctx)) return; } } }
static inline float rt_f32(uint8_t* base,uint32_t a){ (void)base; uint32_t v=PPC_LOAD_U32(a); float f; std::memcpy(&f,&v,4); return f; }
static inline void rt_stf32(uint8_t* base,uint32_t a,float f){ (void)base; uint32_t v; std::memcpy(&v,&f,4); PPC_STORE_U32(a,v); }
// D1-B experimental lever (DEFAULT OFF — opt in with RT_STRIPFIX=1; other values are diagnostics
// xy/big/menu). PROBE P2 proved the dialog_flame replay-speed strip emits FULL-SIZE records
// (r04 @ (0,33), tf 24.5x, alpha 255) while its container grow/slide pair (cont+0x2c/+0x30) is
// parked at (0,0) — the guest's invisibility carrier consumed at layer compose on hardware.
// HOWEVER: scaling/hiding/offscreening these shell CPU emit entries has ZERO effect on the
// port's VISIBLE strip (verified 3 ways: zero, offscreen, x30). The port's vk_render composes
// the visible overlay from a DIFFERENT source, so the guest-faithful D1-B fix must live in
// vk_render's pillarbox overlay pass (as NOTE_field_gfx_defects.md originally scoped), NOT here.
// Kept default-off so the shipped exe is behaviorally unchanged; retained for the vk_render leg.
static bool rt_stripfix(){ static bool v=(std::getenv("RT_STRIPFIX")!=nullptr)&&(std::strcmp(std::getenv("RT_STRIPFIX"),"0")!=0); return v; }
// gate the flame detection/registration hot path: active only when probing or the lever is on,
// so a normal shipped run (neither env set) skips it entirely = zero behavior/overhead change.
static bool rt_d1active(){ static bool v=rt_d1probe()||rt_stripfix(); return v; }
static void p1_snapshot(uint8_t* base, const char* where){
  if(!rt_d1probe()) return;
  uint32_t crsc = PPC_LOAD_U32(0x821F856Cu);
  if(!crsc) return;
  uint32_t flag_1ec = PPC_LOAD_U8(crsc+0x1ECu);
  uint32_t snd_base = PPC_LOAD_U32(0x821F8588u);
  uint32_t snd_obj  = snd_base?PPC_LOAD_U32(snd_base+0x54u):0;
  uint32_t snd_ready= snd_obj?PPC_LOAD_U32(snd_obj+0x5Cu):0;
  uint32_t snd_state= snd_obj?PPC_LOAD_U32(snd_obj+0x48u):0;
  uint32_t ind = PPC_LOAD_U32(crsc+0x1F0u);
  uint32_t ind70 = ind?PPC_LOAD_U8(ind+0x70u):0xEE;
  uint32_t ind71 = ind?PPC_LOAD_U8(ind+0x71u):0xEE;
  uint32_t a78raw = ind?PPC_LOAD_U32(ind+0x78u):0; float a78; std::memcpy(&a78,&a78raw,4);
  int wait_idx=-1; for(int k=0;k<8;k++){ if(PPC_LOAD_U8(crsc+0x70u+(uint32_t)k*0x34u)==0){ wait_idx=k; break; } }
  static std::atomic<uint64_t> prev{~0ull};
  uint64_t key = (uint64_t)flag_1ec | ((uint64_t)(snd_ready!=0)<<8) | ((uint64_t)ind70<<16)
               | ((uint64_t)ind71<<24) | ((uint64_t)(uint32_t)(int)(a78*32.0f+0.5f)<<32)
               | ((uint64_t)(uint32_t)(wait_idx&0xff)<<52);
  if(prev.exchange(key)==key) return;
  std::fprintf(stderr,"[d1a] @%-6s 0x1ec=%u snd_ready=%u snd_state=0x%X ind=0x%X +70=%u +71=%u +78=%.3f waitIdx=%d | hits ce4b8=%ld cd270=%ld cd120=%ld\n",
    where,flag_1ec,snd_ready,snd_state,ind,ind70,ind71,a78,wait_idx,
    g_p1_ce4b8.load(),g_p1_cd270.load(),g_p1_cd120.load());
}
// ---- RT_CONTLIFE standalone lifecycle wrappers (infra + container ctor defined ~line 3832) ----
// sub_821BD8B8 = the B-CANCEL confirm-task CTOR (vt 0x82050254). Return r3 = new task -> record
// birth frame + log initial state fn (+0x48).
extern "C" void __imp__sub_821BD8B8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821BD8B8){
  uint32_t lr=(uint32_t)ctx.lr;
  __imp__sub_821BD8B8(ctx,base);
  g_js_taskAlive.fetch_add(1);   // [jankstate] confirm-task alive++
  if(rt_contlife()){
    uint32_t t=ctx.r3.u32; ctl_task_birth(t);
    long b=g_ctl_t_born.fetch_add(1)+1; long fr=g_ctl_t_freed.load();
    uint32_t st=t?PPC_LOAD_U32(t+0x48):0;
    std::fprintf(stderr,"[contlife] TASK-BORN task=0x%X vt=0x%X state(+48)=0x%X[%s] hb=%u lr=0x%X | tborn=%ld tfreed=%ld talive=%ld\n",
      t,t?PPC_LOAD_U32(t):0,st,ctl_state_name(st),(unsigned)g_rt_menu_heartbeat,lr,b,fr,b-fr);
  }
}
// sub_82063AB8 = the confirm-task DELETING dtor (vt[0] of 0x82050254). Entry r3=task, r4=flag&1.
// Measure lifetime in frames + the state fn it dies FROM. Only census vt-0x82050254 objects.
extern "C" void __imp__sub_82063AB8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_82063AB8){
  { uint32_t t=ctx.r3.u32; if(t&&PPC_LOAD_U32(t)==0x82050254u) g_js_taskAlive.fetch_sub(1); }  // [jankstate] confirm-task alive--
  if(rt_contlife()){
    uint32_t t=ctx.r3.u32; uint32_t vt=t?PPC_LOAD_U32(t):0; uint32_t st=t?PPC_LOAD_U32(t+0x48):0;
    if(vt==0x82050254u){
      unsigned int life=ctl_task_life(t);
      long fdel=g_ctl_t_freed.fetch_add(1)+1; long b=g_ctl_t_born.load();
      std::fprintf(stderr,"[contlife] TASK-DTOR task=0x%X vt=0x%X flag=%u dies-from state(+48)=0x%X[%s] life=%u frames | tborn=%ld tfreed=%ld talive=%ld\n",
        t,vt,(unsigned)(ctx.r4.u32&1),st,ctl_state_name(st),life,b,fdel,b-fdel);
    }
  }
  __imp__sub_82063AB8(ctx,base);
}
// sub_821BD2C0 = confirm-task BASE dtor: the actual child-list release site (runs sub_82173A18
// twice on +0x2c and +0x10). If this runs for the cancel task, its child movie containers SHOULD
// be freed here. Log entry state.
extern "C" void __imp__sub_821BD2C0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821BD2C0){
  if(rt_contlife()){
    uint32_t t=ctx.r3.u32; uint32_t st=t?PPC_LOAD_U32(t+0x48):0;
    static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    std::fprintf(stderr,"[contlife] TASK-BASEDTOR#%ld task=0x%X state(+48)=0x%X[%s] hb=%u | (child-list release x2 follows)\n",
      i,t,st,ctl_state_name(st),(unsigned)g_rt_menu_heartbeat);
  }
  __imp__sub_821BD2C0(ctx,base);
}
// sub_82173A18 = intrusive CHILD-LIST destroy-all (the container release mechanism). Count runs
// + caller lr (throttled) to see whether the release walk ever fires around a cancel.
extern "C" void __imp__sub_82173A18(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_82173A18){
  if(rt_contlife()){
    long r=g_ctl_release.fetch_add(1)+1; uint32_t lr=(uint32_t)ctx.lr;
    if(r<=40||r%400==0) std::fprintf(stderr,"[contlife] RELEASE#%ld sub_82173A18 list=0x%X lr=0x%X hb=%u\n",
      r,ctx.r3.u32,lr,(unsigned)g_rt_menu_heartbeat);
  }
  __imp__sub_82173A18(ctx,base);
}
// sub_8206D530 = movie-container DTOR (vt[0] of 0x82051494). Entry r3=cont, r4=flag&1.
extern "C" void __imp__sub_8206D530(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_8206D530){
  if(rt_contlife()){
    uint32_t c=ctx.r3.u32; long fdel=g_ctl_c_freed.fetch_add(1)+1; long b=g_ctl_c_born.load();
    std::fprintf(stderr,"[contlife] CONT-DTOR cont=0x%X flag=%u hb=%u | cborn=%ld cfreed=%ld calive=%ld\n",
      c,(unsigned)(ctx.r4.u32&1),(unsigned)g_rt_menu_heartbeat,b,fdel,b-fdel);
  }
  __imp__sub_8206D530(ctx,base);
}
PTASK_WRAP(sub_821966D0)
// Panel ctors of 0cb0's page-0 SYSTEM MENU build (2026-07-23 menu-content gap): the branch
// creates [conditional 0x108 dialog 821BD670(kind 2)] + [0x6c list obj 821BAE98(buf,
// engine+0x7c pagestore, name) = the item-panel builder suspect] + [0xbc 821D1E98]. If these
// never enter on the natural/forced page-0 build, the create is being skipped upstream.
// sub_821BD670 = the modal-dialog CTOR (see RT_CANCELLIFE block above). Custom wrapper keeps
// the [ptask] census AND, under RT_CANCELLIFE, records each birth (return value r3 = new obj).
extern "C" void __imp__sub_821BD670(PPCContext& __restrict, uint8_t*);
// ★ RT_LOADPROBE2 task lane (2026-07-28, flicker-truth wf_e3c67137; REVIEW FIX wf_ea22499a):
// first landed as PPC_FUNC(sub_821BD670/BD5B8) in shell/gen/rt.cpp — SILENTLY DEAD, shadowed by
// THESE strong wrappers (merged_xex.o links first, /FORCE:MULTIPLE keeps the first definition;
// the audio-arc shadowed-hook landmine, all 3 review lenses caught it). The dialog ctor SHOWS
// the CRscIndicator and the dtor HIDES it (see dtor comment below) — so ctor->dtor lifetime IS
// the indicator's visibility window = the M2 flicker duration. Default OFF.
static bool lp2_on(){ static bool on=std::getenv("RT_LOADPROBE2")&&atoi(std::getenv("RT_LOADPROBE2"))!=0; return on; }
static double lp2_ms(){ static auto t0=std::chrono::steady_clock::now();
  return std::chrono::duration<double,std::milli>(std::chrono::steady_clock::now()-t0).count(); }
static std::mutex g_lp2m; static std::unordered_map<uint32_t,double> g_lp2Born;
PPC_FUNC(sub_821BD670){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  uint32_t e_r3=ctx.r3.u32, e_r4=ctx.r4.u32, e_r5=ctx.r5.u32, e_r8=ctx.r8.u32, lr=(uint32_t)ctx.lr;
  if(i<=6||i%600==0) std::fprintf(stderr,"[ptask] sub_821BD670#%ld r3=0x%X r4=0x%X lr=0x%X\n",i,e_r3,e_r4,lr);
  __imp__sub_821BD670(ctx,base);
  { uint32_t o=ctx.r3.u32; if(o&&PPC_LOAD_U32(o+0xf4)==2) g_js_dlgAlive.fetch_add(1); }  // [jankstate] kind-2 dialog alive++
  if(lp2_on()){ uint32_t o=ctx.r3.u32;
    if(o){ double t=lp2_ms();
      { std::lock_guard<std::mutex> l(g_lp2m); g_lp2Born[o]=t; }
      uint32_t namep=PPC_LOAD_U32(o+0xD4); char nm[33]={0};
      if(namep&&namep<0x20000000u){ for(int ci=0;ci<32;ci++){ char c=(char)PPC_LOAD_U8(namep+ci); if(!c)break; nm[ci]=c; } }
      std::fprintf(stderr,"[lp2] t=%.1fms TASK-CTOR dlg=0x%X kind(+f4)=%u ind(+fc)=%u/r8=%u name='%s' lr=0x%08X\n",
        t,o,PPC_LOAD_U32(o+0xf4),PPC_LOAD_U32(o+0xfc),e_r8,nm,lr); } }
  if(rt_cancellife()){
    uint32_t o=ctx.r3.u32;   // return value = the freshly-built dialog task object
    long b=g_cl_born.fetch_add(1)+1; long fr=g_cl_freed.load();
    // [modalpoll] dialog+0x104 = the PLAYER INDEX that FUN_821bd348 (vt+0x34) polls for A/B.
    // If it is NOT in [0,4] the modal input poll is SKIPPED -> dialog only ages its +0x100
    // timeout = the long PARK. Seeded here (821bd670: puVar1[0x41]=input_record+0x24). Log the
    // raw value + validity so park-vs-responsive is decided from the seed.
    uint32_t inrec=PPC_LOAD_U32(PPC_LOAD_U32(PPC_LOAD_U32(0x821F8588u)+0x4C)+0x50);
    uint32_t pidx=o?PPC_LOAD_U32(o+0x104):0; uint32_t irec24=inrec?PPC_LOAD_U32(inrec+0x24):0xDEAD;
    std::fprintf(stderr,"[cancellife] BORN dlg=0x%X vt=0x%X kind(+f4)=%u/r5=%u ind(+fc)=%u/r8=%u doc(r4)=0x%X lr=0x%X | born=%ld freed=%ld alive=%ld | pidx(+104)=%u %s inrec=0x%X +0x24=0x%X\n",
      o,o?PPC_LOAD_U32(o):0,o?PPC_LOAD_U32(o+0xf4):0,e_r5,o?PPC_LOAD_U32(o+0xfc):0,e_r8,e_r4,lr,
      b,fr,b-fr, pidx,(pidx<=4)?"VALID-poll":"INVALID-SKIP->PARK",inrec,irec24);
  }
}
PTASK_WRAP(sub_821BAE98)
PTASK_WRAP(sub_821D1E98)
// sub_821D11C0 custom: RT_PAGE2 — the natural START-at-title summon delivers page 2 to THIS
// slot (vt+0x28), whose map has no page-2 build; the LIST build for page 2 lives in sibling
// FUN_821d0cb0 (vt+0x1c, the real page factory). Diagnostic: forward the request to the
// sibling on the same thread/task right after this handler no-builds.
extern "C" void __imp__sub_821D11C0(PPCContext& __restrict, uint8_t*);
extern "C" void __imp__sub_821D0CB0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821D11C0){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  uint32_t t=ctx.r3.u32;
  uint32_t shared=t?PPC_LOAD_U32(t+0xbc):0;
  uint32_t page=shared?PPC_LOAD_U32(shared+0x44):0xDEAD;
  if(i<=6||i%600==0) std::fprintf(stderr,"[ptask] sub_821D11C0#%ld r3=0x%X page(+0x44)=%u lr=0x%X\n",
    i,t,page,(uint32_t)ctx.lr);
  __imp__sub_821D11C0(ctx,base);
  const char* p2=std::getenv("RT_PAGE2");
  if(p2 && page!=3 && page!=4){
    static std::atomic<int> did{0};
    if(!did.exchange(1)){
      // RT_PAGE2=1 forwards the natural page; RT_PAGE2=<N> forces page N. Rationale: 11c0's
      // no-build branch RESETS sharedctx+0x44 to 2, so the natural "page 2" at summon time is
      // likely the idle value — the hardware summon should build page 0 = the SYSTEM MENU LIST
      // (0cb0's page-0 branch: 0x108 FUN_821bd670 + 0x6c FUN_821bae98 + 0xbc objs).
      uint32_t fwd=(std::strcmp(p2,"1")==0)?page:(uint32_t)std::atoi(p2);
      std::fprintf(stderr,"[page2] forwarding page %u (natural=%u) to sibling 821D0CB0 (vt+0x1c factory)\n",fwd,page);
      PPCContext ic=ctx; ic.r3.u32=t; ic.r4.u64=(uint64_t)fwd;
      __imp__sub_821D0CB0(ic,base);
    }
  }
}
// ===== 2026-07-23 menu-layout + hold leg (4-lane workflow ground truth) =====
// CORRECTED MODEL: the 7-item SYSTEM MENU = "menu_game_title" MODEL object, ctor
// sub_821D05E8 (items at +0x90 stride 0x24: SSO name/+0x1C id/+0x20 disabled; cursor
// +0x9C). sub_821D0CB0 is its vt+0x1C DECIDE handler (r4 = picked item id 0..6), NOT a
// page factory — RT_PAGE2 has been programmatically PICKING items (0=scoreattack build,
// 2=training relaunch); retire it. Per-item Y is DATA: the PSB movie "menu_game_title"
// coordinate/frameList tracks -> 0x20C-stride entity records (+0x1B8/+0x1BC composed XY),
// evaluated by sub_82179168, composed per frame by sub_8217F318, entities resolved BY
// NAME (item_scoreattack..) via sub_8217B2A0. State chain: 821B92E8 bind PSB ->
// 821BB298 wait-load then play 'open'/'stand' section -> ACTIVE 821BA4D8 (interactive)
// -> on confirm 82061D70-thunk -> 821BB1D8 waits anims then FIRES DECIDE(cursor).
// NO auto-hide exists anywhere (shipped menu waits forever); the observed ~1-2s
// dismissal must be a DECIDE commit (phantom confirm / forced RT_PAGE2) or model close.
// Levers: RT_MENUHOLD=1 blocks DECIDE + the commit-wait state (+ kind-2 dialog closes)
// so the menu persists; =2 additionally freezes ACTIVE-state transitions.
// RT_MENULOG=1: name-lookup + section-play logs. RT_ITEMPOS=1: per-record XY dumps for
// the menu movie ctx (=2: all small ctxs). g_menuMovieCtx defined above the C468 wrapper.
extern "C" void __imp__sub_821D05E8(PPCContext& __restrict, uint8_t*);
extern "C" volatile int g_lb_armed;   // defined in shell/gen/rt.cpp (RT_LRBAND_ARM)
PPC_FUNC(sub_821D05E8){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  uint32_t m=ctx.r3.u32;
  __imp__sub_821D05E8(ctx,base);
  g_lb_armed=1;                       // RT_LRBAND_ARM: menu is up -> start logging
  if(i<=2 && m){
    uint32_t b=PPC_LOAD_U32(m+0x90), e=PPC_LOAD_U32(m+0x94);
    int cnt=(e>b)?(int)((e-b)/0x24):0;
    std::fprintf(stderr,"[p0build] menu_game_title#%ld model=0x%X items=%d cursor=%u\n",
      i,m,cnt,PPC_LOAD_U32(m+0x9c));
    for(int k=0;k<cnt&&k<12;k++){
      uint32_t rec=b+(uint32_t)k*0x24;
      uint32_t sp=(PPC_LOAD_U32(rec+0x18)<0x10)?(rec+4):PPC_LOAD_U32(rec+4);
      std::fprintf(stderr,"[p0build]   item[%d] id=%u dis=%u name=%.28s\n",
        k,PPC_LOAD_U32(rec+0x1c),PPC_LOAD_U32(rec+0x20),(const char*)(base+sp));
    }
  }
}
PPC_FUNC(sub_821D0CB0){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  static bool hold=std::getenv("RT_MENUHOLD")!=nullptr;
  uint32_t m=ctx.r3.u32; bool isMenu=(m&&PPC_LOAD_U32(m)==0x820503B0u);
  rt_l1_emit("K %X %d\n",m?PPC_LOAD_U32(m):0,(int)ctx.r4.u32);   // [l1gate] uncapped decide stream
  if(i<=12) std::fprintf(stderr,"[decide] 821D0CB0#%ld model=0x%X item=%d lr=0x%X%s\n",
    i,m,(int)ctx.r4.u32,(uint32_t)ctx.lr,(hold&&isMenu)?" BLOCKED":"");
  if(hold&&isMenu) return;
  // [contlife] item=-1 (B-cancel) branch: capture the menu model's state fn (+0x48), menu-phase
  // (+0x9c) and pending-queue head (+0x24) BEFORE and AFTER, to prove the cancel writes
  // +0x48=0x82063a58 / +0x9c=6 (LAB_821d10f8) and see if the port immediately reverts it.
  bool ctlDecide = rt_contlife() && isMenu && ((int)ctx.r4.u32==-1);
  uint32_t s0=0,p0=0,q0=0;
  if(ctlDecide){ s0=PPC_LOAD_U32(m+0x48); p0=PPC_LOAD_U32(m+0x9c); q0=PPC_LOAD_U32(m+0x24); }
  __imp__sub_821D0CB0(ctx,base);
  if(ctlDecide){ uint32_t s1=PPC_LOAD_U32(m+0x48),p1=PPC_LOAD_U32(m+0x9c),q1=PPC_LOAD_U32(m+0x24);
    std::fprintf(stderr,"[contlife] DECIDE(-1) menu=0x%X +48:0x%X[%s]->0x%X[%s] +9c:%u->%u +24queue:0x%X->0x%X hb=%u\n",
      m,s0,ctl_state_name(s0),s1,ctl_state_name(s1),p0,p1,q0,q1,(unsigned)g_rt_menu_heartbeat); }
}
// ===== 2026-07-23 sub-menu heartbeat leg =====
// The pillarbox-compose heartbeat is scoped to a MENU-MODEL FAMILY of vtables, not just
// menu_game_title: menu_scoreattack (vt 0x820504D0, ctor 821D1E98, same base ctor 821BA6F0)
// shares the exact BB298/BA4D8/BB1D8 state impls (verified in the shell image vtable dump),
// so the shared-state wrappers cover it with a wider vt check. RT_MENUHOLD stays scoped to
// menu_game_title ONLY (holding sub-pages is never wanted).
static inline bool rt_menu_family_vt(uint32_t vt){
  return vt==0x820503B0u    // menu_game_title (7-item SYSTEM MENU)
      || vt==0x820504D0u    // menu_scoreattack sub-page (same shared state chain)
      || vt==0x82050F00u;   // training-config model (own state chain, see wrappers below)
}
// [mvt] census: while the ROM is live, log each DISTINCT non-family vtable that ticks a
// shared menu state — this is how future sub-menu models (option/replay/... panels) get
// identified for the heartbeat without re-deriving their class layout.
static void rt_menu_vt_census(const char* st, uint32_t vt){
  if(!g_rt_romactive || !vt || rt_menu_family_vt(vt)) return;
  static std::atomic<uint32_t> seen[8];
  for(int k=0;k<8;k++){
    uint32_t v=seen[k].load();
    if(v==vt) return;
    if(v==0){ uint32_t exp=0;
      if(seen[k].compare_exchange_strong(exp,vt)){
        std::fprintf(stderr,"[mvt] NEW vt 0x%X ticking %s while ROM live (not in heartbeat family)\n",vt,st);
        return; }
      if(seen[k].load()==vt) return; }
  }
}
// NOTE (showmenu4 run 1): these state fns are SHARED base-class states — the shell
// boot menus (title/top menu, e.g. model 0x37E500) run the same BB298/BA4D8/BB1D8
// chain. An unscoped hold wedges the BOOT flow. All holds are therefore gated on the
// object's vtable: 0x820503B0 = menu_game_title only.
extern "C" void __imp__sub_821BB1D8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821BB1D8){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  static bool hold=std::getenv("RT_MENUHOLD")!=nullptr;
  uint32_t m=ctx.r3.u32; uint32_t vt=m?PPC_LOAD_U32(m):0;
  bool isMenu=(vt==0x820503B0u);
  if(rt_menu_family_vt(vt)) g_rt_menu_heartbeat++;  // menu on-screen (commit-wait / RT_MENUHOLD)
  rt_menu_vt_census("BB1D8",vt);
  if(i<=4||i%120==0||(isMenu&&i%120<4)) std::fprintf(stderr,"[mstate] BB1D8(commit-wait)#%ld model=0x%X vt=0x%X cursor=%u%s\n",
    i,m,vt,m?PPC_LOAD_U32(m+0x9c):0,(hold&&isMenu)?" HELD":"");
  if(hold&&isMenu) return;               // never advances -> never fires DECIDE(cursor)
  __imp__sub_821BB1D8(ctx,base);
}
extern "C" void __imp__sub_821BB298(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821BB298){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  uint32_t m=ctx.r3.u32; uint32_t st0=m?PPC_LOAD_U32(m+0x48):0;
  uint32_t vt=m?PPC_LOAD_U32(m):0;
  __imp__sub_821BB298(ctx,base);
  uint32_t st1=m?PPC_LOAD_U32(m+0x48):0;
  uint32_t cont=m?PPC_LOAD_U32(m+0x7c):0;
  if(rt_menu_family_vt(vt)){ if(cont) g_menuMovieCtx.store(cont+0x10); g_rt_menu_heartbeat++; }  // menu on-screen (load/slide-in)
  rt_menu_vt_census("BB298",vt);
  if(i<=3||st0!=st1) std::fprintf(stderr,"[mstate] BB298(load-wait)#%ld model=0x%X vt=0x%X cont=0x%X state 0x%X->0x%X\n",
    i,m,vt,cont,st0,st1);
}
extern "C" void __imp__sub_821BA4D8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821BA4D8){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  static int hold=std::getenv("RT_MENUHOLD")?atoi(std::getenv("RT_MENUHOLD")):0;
  uint32_t m=ctx.r3.u32; uint32_t st0=m?PPC_LOAD_U32(m+0x48):0;
  uint32_t vt=m?PPC_LOAD_U32(m):0; bool isMenu=(vt==0x820503B0u);
  __imp__sub_821BA4D8(ctx,base);
  uint32_t st1=m?PPC_LOAD_U32(m+0x48):0;
  if(rt_menu_family_vt(vt)){ uint32_t cont=PPC_LOAD_U32(m+0x7c); if(cont) g_menuMovieCtx.store(cont+0x10); g_rt_menu_heartbeat++; }  // menu on-screen (interactive)
  rt_menu_vt_census("BA4D8",vt);
  // [mcur] cursor-change log (pad-drive leg): one line per cursor move so the FIFO dpad
  // step size is observable (keystroke+level double-fire discrimination).
  if(isMenu){
    static std::atomic<uint32_t> lastCur{0xFFFFFFFFu};
    uint32_t cur=PPC_LOAD_U32(m+0x9c), prev=lastCur.exchange(cur);
    if(prev!=cur && prev!=0xFFFFFFFFu)
      std::fprintf(stderr,"[mcur] model=0x%X cursor %u->%u\n",m,prev,cur);
  }
  // RT_MENUPICK=<item id 0..6> (diag): fire the model's DECIDE(item) once after
  // RT_MENUPICKAT ACTIVE ticks (default 300 ~= 5s) — programmatic item pick to reach the
  // sub-menu models (0=SCORE ATTACK page, 2=TRAINING config) without pad input. Calls the
  // __imp__ impl directly so an RT_MENUHOLD DECIDE-block can't eat it. Same mechanism the
  // retired RT_PAGE2 lever exercised by accident (proven to build sub-pages).
  if(isMenu){
    static int pick=std::getenv("RT_MENUPICK")?atoi(std::getenv("RT_MENUPICK")):-1;
    static long pickAt=std::getenv("RT_MENUPICKAT")?atol(std::getenv("RT_MENUPICKAT")):300;
    static std::atomic<long> mticks{0}; static std::atomic<bool> picked{false};
    if(pick>=0 && !picked.load()){
      long t=mticks.fetch_add(1)+1;
      if(t>=pickAt && !picked.exchange(true)){
        std::fprintf(stderr,"[mpick] firing DECIDE(%d) on model=0x%X after %ld ACTIVE ticks\n",pick,m,t);
        PPCContext ic=ctx; ic.r3.u32=m; ic.r4.u64=(uint64_t)pick;
        __imp__sub_821D0CB0(ic,base);
      }
    }
  }
  if(i<=3||i%300==0||st0!=st1) std::fprintf(stderr,"[mstate] BA4D8(ACTIVE)#%ld model=0x%X vt=0x%X cont=0x%X cursor=%u state 0x%X->0x%X\n",
    i,m,vt,m?PPC_LOAD_U32(m+0x7c):0,m?PPC_LOAD_U32(m+0x9c):0,st0,st1);
  // [mflags] node/visibility dump: task hide bytes +0x1C (nodeA) / +0x38 (nodeB), node
  // heads +0x10/+0x2C, loader/container hidden bytes +0xC and their link words. Dumped
  // for the menu model (and periodically) to compare against a rendering sibling.
  if(isMenu){ uint32_t ldr=PPC_LOAD_U32(m+0x78); if(ldr) g_menuLoader.store(ldr); }
  if(isMenu && (i%300==0||i==3)){
    uint32_t ld=PPC_LOAD_U32(m+0x78), co=PPC_LOAD_U32(m+0x7c);
    std::fprintf(stderr,"[mflags] model=0x%X hideA(+1C)=%u hideB(+38)=%u nodeA=0x%X nodeB=0x%X layer(+74)=0x%X\n",
      m,(unsigned)PPC_LOAD_U8(m+0x1c),(unsigned)PPC_LOAD_U8(m+0x38),PPC_LOAD_U32(m+0x10),PPC_LOAD_U32(m+0x2c),PPC_LOAD_U32(m+0x74));
    if(ld) std::fprintf(stderr,"[mflags]   loader=0x%X vt=0x%X next=0x%X hid(+C)=%u w4=0x%X\n",
      ld,PPC_LOAD_U32(ld),PPC_LOAD_U32(ld+4),(unsigned)PPC_LOAD_U8(ld+0xc),PPC_LOAD_U32(ld+0x10));
    if(co) std::fprintf(stderr,"[mflags]   cont=0x%X vt=0x%X next=0x%X hid(+C)=%u w4=0x%X\n",
      co,PPC_LOAD_U32(co),PPC_LOAD_U32(co+4),(unsigned)PPC_LOAD_U8(co+0xc),PPC_LOAD_U32(co+0x10));
  }
  if(hold>=2 && isMenu && st0!=st1){     // freeze interactive: revert any transition
    std::fprintf(stderr,"[mstate]   HELD=2: reverting state to 0x%X\n",st0);
    PPC_STORE_U32(m+0x48,st0);
  }
}
// ══════════════════════════════════════════════════════════════════════════════════════════════
// ★★★ r23-w17 MISSION C1(d) — THE DARKBD JOIN INSTRUMENT   (RT_BDJOIN=1)
//
// THE QUESTION IT EXISTS TO ANSWER, pre-registered in bank/r23/w17/PREREG_w17.txt §6 BEFORE the
// leg that reads it: when the stage-5 WASH predicate fires on a frame, does the 5998-show /
// backdrop path EXECUTE IN THAT SAME FRAME?
//   POSITIVE -> the wash is a NAMED QUAD.  sub_821C5998's backdrop-colour formula (below) is the
//               only construct anybody has found in this tree that provably saturates to
//               0xFFFFFFFF — opaque white — and it does so at cursor==4, which is the value every
//               [modegate] line of every w17 D1 leg reports.  A white full-width quad under a
//               correctly-drawn HUD and correctly-drawn sprites is exactly the film045 geometry.
//   NEGATIVE -> the join dies cleanly and the menu-layer lead comes OFF the suspect list.  That is
//               worth as much: it is the leading in-tree candidate, and leaving it un-eliminated
//               taxes every later window.
//
// WHY THE DRAW AND NOT ONLY THE FORMULA.  Running the formula writes bd+8; it does not put a quad
// on the screen.  The quad reaches the screen only if the engine's ACTIVE/drawer virtual
// (vt+0x30 = sub_821BE500) runs for an object that owns that backdrop.  So the tap is planted in
// BOTH places and the two are reported under DIFFERENT tags, never conflated:
//     [bdjoin] = the formula fired (a WRITE, in sub_821C5998)
//     [bddraw] = the drawer ran with a live backdrop (a DRAW, in sub_821BE500)
//     [closer] = the hide path spawned the never-ticked fade closer (a SECOND documented
//                white-quad producer — see RT_NOCLOSER's own comment further down this file)
//
// ⚠ THE CLONE-BYPASS LANDMINE APPLIES AND IS NOT WISHED AWAY.  These are PPC_FUNC wrappers, and a
//   cloned call site can reach the callee body without passing through the wrapper, so
//   "[bddraw] printed nothing" is NOT "the drawer did not run".  A NEGATIVE join is therefore only
//   readable against this instrument's OWN positive control, which is present in every leg by
//   construction: the boot dialogs drive BE500 (vt 0x82050200) dozens of times before any stage
//   loads, so a leg in which [bddraw] never appears AT ALL is a silent instrument, not a negative.
extern "C" long rvk_cur_frame(void) __attribute__((weak));   // defined in render/vk_render.cpp
static inline long rt_bdj_frame(){ return rvk_cur_frame ? rvk_cur_frame() : -1; }
static inline bool rt_bdjoin(){ static const bool on = std::getenv("RT_BDJOIN")!=nullptr; return on; }

// ===== TRAINING CONFIG model heartbeat (sub-menu leg) =====
// The training config panel (0x19c obj built by 821966D0 from DECIDE(2)) is vt 0x82050F00,
// base ctor 821B6748 (family vt 0x820505B0) — NOT a menu_game_title sibling. Its state chain
// (shell-image vtable dump at 0x50F00): vt+0x2C=82196660 (load/build), vt+0x30=821BE500
// (dialog-family ACTIVE — SHARED with the dialog class 0x82050200 and the 505B0 base, so the
// heartbeat pulse is vt-scoped: boot dialogs must not pulse, and dialogs ticking during ROM
// attract must not re-trigger the ranking double-draw), vt+0x34=82195AB0 (commit).
extern "C" void __imp__sub_82196660(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_82196660){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  uint32_t m=ctx.r3.u32; uint32_t vt=m?PPC_LOAD_U32(m):0;
  if(vt==0x82050F00u) g_rt_menu_heartbeat++;   // training panel on-screen (load/build)
  if(i<=4) std::fprintf(stderr,"[tstate] 96660(load)#%ld model=0x%X vt=0x%X\n",i,m,vt);
  __imp__sub_82196660(ctx,base);
}
extern "C" void __imp__sub_821BE500(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821BE500){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  uint32_t m=ctx.r3.u32; uint32_t vt=m?PPC_LOAD_U32(m):0;
  if(vt==0x82050F00u){
    g_rt_menu_heartbeat++;                     // training panel on-screen (interactive)
    if(i<=4||i%300==0) std::fprintf(stderr,"[tstate] BE500(ACTIVE)#%ld model=0x%X vt=0x%X\n",i,m,vt);
  }
  rt_menu_vt_census("BE500",vt);               // which dialog-family vts tick while ROM live
  // [cancellife] per-frame liveness heartbeat for the kind-2 cancel dialogs: BE500 is the
  // dialog-class ACTIVE tick (vt 0x82050200), so it runs once/frame per LIVE dialog. If the
  // state fn +0x48 stays at idle 0x82061D50 (never -> confirm 0x82061D70 -> close 0x82065A88)
  // the dialog never advances to teardown -> the leak. Throttled; scales with alive count.
  if(rt_cancellife() && vt==0x82050200u && PPC_LOAD_U32(m+0xf4)==2){
    static std::atomic<long> cn{0}; long c=cn.fetch_add(1)+1;
    if(c<=10||c%300==0){ long bn=g_cl_born.load(), fr=g_cl_freed.load();
      std::fprintf(stderr,"[cancellife] TICK#%ld dlg=0x%X state(+48)=0x%X tmr(+100)=%u +94=%u | born=%ld freed=%ld alive=%ld slideout=%ld\n",
        c,m,PPC_LOAD_U32(m+0x48),PPC_LOAD_U32(m+0x100),PPC_LOAD_U32(m+0x94),
        bn,fr,bn-fr,g_cl_slideout.load()); }
  }
  // [d1b] P2 engine-side: BE500 (dialog-family ACTIVE tick) is the dialog_flame strip engine's
  // per-frame state fn; container=*(m+0x50), grow/slide pair at cont+0x2c/+0x30, 12-step ctr m+0x94.
  // Log the parked strip (pair ~ (0,0)) with its records' composed XY + transform matrix (rec+0x40..
  // 0x4c) + size ints (rec+0x6c..0x78) = exactly the fields FUN_82178e78 copies into the emit entry.
  if(rt_d1probe() && m){
    uint32_t cont=PPC_LOAD_U32(m+0x50u);
    if(cont){
      float grow=rt_f32(base,cont+0x2Cu), slide=rt_f32(base,cont+0x30u);
      uint32_t prog=PPC_LOAD_U32(m+0x94u);
      uint32_t mvc=cont+0x10u;
      uint32_t rb=PPC_LOAD_U32(mvc+0xFCu), re=PPC_LOAD_U32(mvc+0x100u);
      int nrec=(re>rb && ((re-rb)%0x20Cu)==0)?(int)((re-rb)/0x20Cu):-1;
      bool parked=(grow>-0.02f&&grow<0.02f&&slide>-0.02f&&slide<0.02f);
      if(parked && nrec>=1 && nrec<=48){
        g_flameContainer.store(cont);
        static std::atomic<uint32_t> last{0}; static std::atomic<long> nn{0};
        long i=nn.fetch_add(1)+1;
        if(last.exchange(cont)!=cont || i%600==1){
          std::fprintf(stderr,"[d1b] BE500 engine=0x%X vt=0x%X cont=0x%X pair=(%.4f,%.4f) prog=%u nrec=%d mvc=0x%X\n",
            m,vt,cont,grow,slide,prog,nrec,mvc);
          int lim=nrec<12?nrec:12;
          for(int k=0;k<lim;k++){ uint32_t r=rb+(uint32_t)k*0x20Cu;
            std::fprintf(stderr,"[d1b]   r%02d vis=%u/%u XY=(%.1f,%.1f) sz6c=(%.0f,%.0f,%.0f,%.0f) tf40=(%.3f,%.3f,%.3f,%.3f) a=%u\n",
              k,(unsigned)PPC_LOAD_U8(r+0x1B4u),(unsigned)PPC_LOAD_U8(r+0x1B5u),
              rt_f32(base,r+0x1B8u),rt_f32(base,r+0x1BCu),
              (float)(int)PPC_LOAD_U32(r+0x6Cu),(float)(int)PPC_LOAD_U32(r+0x70u),
              (float)(int)PPC_LOAD_U32(r+0x74u),(float)(int)PPC_LOAD_U32(r+0x78u),
              rt_f32(base,r+0x40u),rt_f32(base,r+0x44u),rt_f32(base,r+0x48u),rt_f32(base,r+0x4Cu),
              (unsigned)PPC_LOAD_U32(r+0x1D8u));
          }
        }
      }
    }
  }
  // ★ r23-w17 C1(d) [bddraw] — THE DRAW HALF OF THE JOIN.  Every ACTIVE-virtual tick that carries
  //   a live backdrop object (obj+0xd8), with the colour actually sitting in bd+8 at that instant
  //   and the renderer frame it happened on.  Change-triggered on (vt,bdcol) with a slow
  //   heartbeat, so a stage-long run costs a handful of lines instead of one per frame per object.
  if(rt_bdjoin() && m){
    uint32_t bd=PPC_LOAD_U32(m+0xd8u);
    // ★ r23-w17 leg c1a taught this: ten change-triggered records, ALL in the first 54 calls, and
    //   nothing for the next ten minutes.  "No record" then means two different things that must
    //   not be conflated -- BE500 stopped being called at all, or it is still called but with no
    //   backdrop object.  So both denominators are counted and a periodic census prints them.
    { static std::atomic<long> allN{0}, bdN{0};
      long a=allN.fetch_add(1)+1; if(bd) bdN.fetch_add(1);
      if(a%1800==1) std::fprintf(stderr,"[bdcensus] f%ld BE500 calls=%ld with-backdrop=%ld\n",
                                 rt_bdj_frame(),a,bdN.load()); }
    if(bd){
      uint32_t col=PPC_LOAD_U32(bd+8u);
      static std::atomic<uint64_t> lastk{~0ull};
      static std::atomic<long> bn{0}; long b=bn.fetch_add(1)+1;
      uint64_t k=((uint64_t)vt<<32)|col;
      if(lastk.exchange(k)!=k || b%600==1)
        std::fprintf(stderr,"[bddraw] f%ld BE500#%ld obj=0x%X vt=0x%X bd=0x%X bdcol=0x%08X cur=%u st48=0x%X shown8c=%u\n",
          rt_bdj_frame(),i,m,vt,bd,col,PPC_LOAD_U32(m+0x138u),PPC_LOAD_U32(m+0x48u),
          (unsigned)PPC_LOAD_U8(m+0x8cu));
    }
  }
  __imp__sub_821BE500(ctx,base);
}
extern "C" void __imp__sub_82195AB0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_82195AB0){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  uint32_t m=ctx.r3.u32; uint32_t vt=m?PPC_LOAD_U32(m):0;
  if(vt==0x82050F00u) g_rt_menu_heartbeat++;   // training panel on-screen (commit)
  if(i<=4) std::fprintf(stderr,"[tstate] 95AB0(commit)#%ld model=0x%X vt=0x%X\n",i,m,vt);
  __imp__sub_82195AB0(ctx,base);
}
// ===== TICK-WALKER heartbeat (sub-menu leg, run-1 correction) =====
// showmenu5 run 1 (RT_MENUPICK=0): DECIDE(0) builds the scoreattack page (821D1E98 fired),
// but the page runs on DIALOG tasks + a new movie container while the PARENT game_title
// model PARKS — none of the state-scoped pulses fire and the compose starves (hb froze at
// 312, ovN=20+ sub-page sprites emitted with do=0). The state-level pulse is the wrong
// altitude for sub-pages. sub_82173B98 = the scheduler's per-element tick entry (vt+0x04 of
// every task/model class): it runs EVERY frame for every REGISTERED element regardless of
// which state impl the class uses (it is what ticks the parent's modal children). Pulsing
// here keys the compose gate to the menu model's LIFETIME in the task tree — the parked
// parent anchors the whole sub-page session, so any sub-page composes without knowing its
// class. No family model exists during ROM attract (created at summon, unlinked on close),
// so the double-draw gate holds. The state-scoped pulses above stay (harmless, redundant).
extern "C" void __imp__sub_82173B98(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_82173B98){
  uint32_t m=ctx.r3.u32; uint32_t vt=m?PPC_LOAD_U32(m):0;
  if(rt_menu_family_vt(vt)){
    g_rt_menu_heartbeat++;
    static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    if(i<=6||i%600==0) std::fprintf(stderr,"[mtick] walker elem=0x%X vt=0x%X #%ld\n",m,vt,i);
  }
  // [jankstate] the walker ticks every registered element every frame, so it is the one place
  // the menu_game_title model is guaranteed valid-and-live: stash its +0x48 state for the jank
  // block to sample. Freezes on close (walker stops seeing it) — acceptable, dwell is what matters.
  if(vt==0x820503B0u){ g_js_menuModel.store(m); g_js_menuState.store(PPC_LOAD_U32(m+0x48)); }
  __imp__sub_82173B98(ctx,base);
}
// [layer] sub_821B9FC0 = the model LAYER-RESOLVE state: scan 8-entry table at
// [0x821F856C]+104 stride 52 (key@+0, layerobj@+12) for key==model+0x54; result ->
// model+0x74; ON MISS stores NULL and advances anyway (silent). menu_game_title key=5
// (ctor 821D05E8 [0x15]=5); dialogs use 7. BB3A8 then binds the layer into the movie
// loader via FUN_8217b6a8(loader, model+0x74) — NULL bind = alive+composed+ZERO DRAWS.
extern "C" void __imp__sub_821B9FC0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821B9FC0){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  uint32_t m=ctx.r3.u32; uint32_t vt=m?PPC_LOAD_U32(m):0;
  uint32_t key=m?PPC_LOAD_U32(m+0x54):0;
  __imp__sub_821B9FC0(ctx,base);
  if(i<=10||vt==0x820503B0u){
    uint32_t tab=PPC_LOAD_U32(0x821F856Cu);
    std::fprintf(stderr,"[layer] B9FC0#%ld model=0x%X vt=0x%X key=%u -> layer=0x%X\n",
      i,m,vt,key,m?PPC_LOAD_U32(m+0x74):0);
    for(int k=0;k<8&&tab;k++){
      uint32_t e=tab+104+(uint32_t)k*52;
      uint32_t lo=PPC_LOAD_U32(e+12);
      std::fprintf(stderr,"[layer]   key=%u obj=0x%X vt=0x%X w1=0x%X w2=0x%X w3=0x%X w4=0x%X w5=0x%X\n",
        PPC_LOAD_U32(e),lo,lo?PPC_LOAD_U32(lo):0,lo?PPC_LOAD_U32(lo+4):0,lo?PPC_LOAD_U32(lo+8):0,
        lo?PPC_LOAD_U32(lo+12):0,lo?PPC_LOAD_U32(lo+16):0,lo?PPC_LOAD_U32(lo+20):0);
    }
  }
}
// (layer-bind logging lives in the existing [doc] sub_8217B6A8 wrapper above.)
// [rvisit] sub_82179E68 = container render trampoline (ctx=r3+0x10 -> 82178E78 walk).
// Logs each DISTINCT container the render pass visits (RT_MENULOG): if the menu's
// container never appears, its layer's render list is not being walked.
static std::atomic<int> g_inMenuWalk{0};
// [flush] sub_82168E58 = the loader's queue flush (sort + draw + reset). If the menu
// loader's flush never runs (or runs with a full queue that stays full), that's the gap.
extern "C" void __imp__sub_82168E58(PPCContext& __restrict, uint8_t*);
// RECON TASK B (2026-07-26): 0x82168E58 is ALSO slot +0x08 ("draw") of the PICTURE-node vtable
// 0x82051478 (verified against default.img.bin). rt.cpp owns the RT_PICNODE probe body; it is
// called from here because this file already owns the PPC_FUNC and a duplicate in rt.cpp would be
// silently shadowed by link order. Default OFF (getenv inside), read-only.
extern "C" void rt_picnode_report(uint32_t n, uint8_t* base);
// RT_EXPECTCENSUS drain half (2026-08-14): rt.cpp owns the counters + the emit hook; the drain
// is reported from HERE because this file already owns this PPC_FUNC (same shadowing rule as
// rt_picnode_report above). Queue = P+0x4C(begin)/+0x50(end), entries are Q* (stride 4).
extern "C" void rt_expcensus_drain(uint32_t P, int qdepth);
PPC_FUNC(sub_82168E58){
  static bool logon=std::getenv("RT_MENULOG")!=nullptr;
  static bool censOn=std::getenv("RT_EXPECTCENSUS")!=nullptr;
  uint32_t l=ctx.r3.u32;
  rt_picnode_report(l, base);
  if(censOn&&l) rt_expcensus_drain(l,(int)((PPC_LOAD_U32(l+0x50)-PPC_LOAD_U32(l+0x4c))>>2));
  bool menu=(l && l==g_menuLoader.load());
  int q0=0;
  if(logon&&l) q0=(int)((PPC_LOAD_U32(l+0x50)-PPC_LOAD_U32(l+0x4c))>>2);
  __imp__sub_82168E58(ctx,base);
  if(logon){
    static std::atomic<long> nm{0}, no{0};
    int q1=l?(int)((PPC_LOAD_U32(l+0x50)-PPC_LOAD_U32(l+0x4c))>>2):0;
    if(menu){ long i=nm.fetch_add(1)+1;
      if(i<=20||i%120==0) std::fprintf(stderr,"[flush] MENU loader=0x%X q=%d->%d call#%ld\n",l,q0,q1,i);
    } else { long i=no.fetch_add(1)+1;
      if(i<=6||i%3000==0) std::fprintf(stderr,"[flush] other#%ld loader=0x%X q=%d->%d\n",i,l,q0,q1);
    }
  }
}
// [d1b] sub_82178E78 = the per-ctx record walk (called top-level from 82179e68 AND RECURSED for
// type-4 child records inside itself). r3 = the ctx being walked (records at r3+0xfc). The visible
// dialog_flame strip is emitted as a CHILD during the parent menu's walk, so the top-level 82179e68
// flag misses it — scoping the flame flag HERE catches the strip whether walked standalone or nested.
// Container = ctx-0x10 (mvc=container+0x10). Save/restore g_inFlameWalk for nesting.
extern "C" void __imp__sub_82178E78(PPCContext& __restrict, uint8_t*);
// RT_EXPECTCENSUS emit half (2026-08-14): reported from HERE because this file owns this
// PPC_FUNC (a duplicate in rt.cpp was silently link-shadowed — the map file named this object
// as the winner; same rule as rt_picnode_report). Counter bodies live in shell/gen/rt.cpp.
extern "C" void rt_expcensus_emit(uint32_t c, uint8_t* base);
PPC_FUNC(sub_82178E78){
  { static const bool censOn = std::getenv("RT_EXPECTCENSUS") != nullptr;
    if(censOn) rt_expcensus_emit(ctx.r3.u32, base); }
  if(!rt_d1active()){ __imp__sub_82178E78(ctx,base); return; }   // zero-overhead in normal runs
  uint32_t r3=ctx.r3.u32;
  uint32_t mvc=0;
  if(rt_isFlameCtx(r3)) mvc=r3;
  else if(rt_isFlameCtx(r3+0x10u)) mvc=r3+0x10u;   // in case r3 is the container, not the mvc
  int prev=g_inFlameWalk.load();
  if(mvc){
    g_inFlameWalk.store(1); g_flameContainer.store(mvc-0x10u);
    if(rt_d1probe()){ static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
      if(i<=8||i%600==1) std::fprintf(stderr,"[d1b] E78 walk r3=0x%X mvc=0x%X cont=0x%X f=%.3f\n",
        r3,mvc,mvc-0x10u,rt_f32(base,(mvc-0x10u)+0x2Cu)); }
  }
  __imp__sub_82178E78(ctx,base);
  if(mvc) g_inFlameWalk.store(prev);
}
extern "C" void __imp__sub_82179E68(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_82179E68){
  static bool logon=std::getenv("RT_MENULOG")!=nullptr;
  uint32_t c=ctx.r3.u32;
  bool menu=(c+0x10==g_menuMovieCtx.load());
  if(logon){
    static std::atomic<uint32_t> seen[48]; static std::atomic<long> ns{0};
    bool isnew=true;
    long cnt=ns.load();
    for(long k=0;k<cnt&&k<48;k++) if(seen[k].load()==c){ isnew=false; break; }
    if(isnew){ long slot=ns.fetch_add(1); if(slot<48){ seen[slot].store(c);
      std::fprintf(stderr,"[rvisit] container=0x%X movieCtx=0x%X lr=0x%X%s\n",c,c+0x10,(uint32_t)ctx.lr,
        menu?" (MENU)":""); } }
  }
  if(menu) g_inMenuWalk.store(1);
  // [d1b] P2 emit-side: 82179e68 is the movie record-walk (vt+0x08) for container c; the emit
  // pushes (82178d78) happen within its dynamic extent. Flag the walk when c is the parked
  // dialog_flame container so the emit wrapper logs the ACTUAL pushed geometry.
  bool flameW=false;
  if(rt_d1active()){
    uint32_t mvc=c+0x10u;
    // Only the NAME-confirmed dialog_flame strip movies (registered by sub_8217B2A0). Flag the
    // walk (the D1-B lever in the emit wrapper reads it); logging stays RT_D1PROBE-gated.
    if(rt_isFlameCtx(mvc)){
      flameW=true; g_inFlameWalk.store(1); g_flameContainer.store(c);
    }
    if(rt_d1probe() && flameW){
      float grow=rt_f32(base,c+0x2Cu), slide=rt_f32(base,c+0x30u);
      uint32_t rb=PPC_LOAD_U32(mvc+0xFCu), re=PPC_LOAD_U32(mvc+0x100u);
      int nrec=(re>rb&&((re-rb)%0x20Cu)==0)?(int)((re-rb)/0x20Cu):-1;
      static std::atomic<uint32_t> fseen[16]; static std::atomic<long> fns{0};
      long cnt=fns.load(); bool isnew=true;
      for(long k=0;k<cnt&&k<16;k++) if(fseen[k].load()==c){isnew=false;break;}
      // dump per-record geometry ONCE per distinct container (composed XY, transform matrix rec+0x40..
      // 0x4c, size ints rec+0x6c..0x78, alpha rec+0x1d8, vis rec+0x1b4/1b5). This is the decisive
      // read: full-size records with pair (0,0) => layer/compose-gate fix; zeroed => field-consumption.
      if(isnew){ long sl=fns.fetch_add(1); if(sl<16){ fseen[sl].store(c);
        std::fprintf(stderr,"[d1b] STRIP container=0x%X mvc=0x%X pair=(%.4f,%.4f) nrec=%d lr=0x%X\n",
          c,mvc,grow,slide,nrec,(uint32_t)ctx.lr);
        int lim=(nrec>0&&nrec<24)?nrec:0;
        for(int k=0;k<lim;k++){ uint32_t r=rb+(uint32_t)k*0x20Cu;
          std::fprintf(stderr,"[d1b]   r%02d vis=%u/%u XY=(%.1f,%.1f) tf40=(%.3f,%.3f,%.3f,%.3f) sz6c=(%.0f,%.0f,%.0f,%.0f) a=%u ext=(%.1f,%.1f)\n",
            k,(unsigned)PPC_LOAD_U8(r+0x1B4u),(unsigned)PPC_LOAD_U8(r+0x1B5u),
            rt_f32(base,r+0x1B8u),rt_f32(base,r+0x1BCu),
            rt_f32(base,r+0x40u),rt_f32(base,r+0x44u),rt_f32(base,r+0x48u),rt_f32(base,r+0x4Cu),
            (float)(int)PPC_LOAD_U32(r+0x6Cu),(float)(int)PPC_LOAD_U32(r+0x70u),
            (float)(int)PPC_LOAD_U32(r+0x74u),(float)(int)PPC_LOAD_U32(r+0x78u),
            (unsigned)PPC_LOAD_U32(r+0x1D8u),rt_f32(base,r+0x1E0u),rt_f32(base,r+0x1E4u));
        }
      } }
    }
  }
  __imp__sub_82179E68(ctx,base);
  if(flameW) g_inFlameWalk.store(0);
  if(menu) g_inMenuWalk.store(0);
}
// [emit] sub_82178D78(drawer, slot): per-sprite queue push. During the menu walk, log
// drawer + slot pos/color; sample other walks for a working-drawer comparison.
extern "C" void __imp__sub_82178D78(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_82178D78){
  static bool logon=std::getenv("RT_MENULOG")!=nullptr;
  if(logon){
    uint32_t d=ctx.r3.u32, s=ctx.r4.u32;
    auto F=[&](uint32_t a){ uint32_t v=PPC_LOAD_U32(a); float f; std::memcpy(&f,&v,4); return f; };
    static std::atomic<long> nm{0}, no{0};
    if(g_inMenuWalk.load()){ long i=nm.fetch_add(1)+1;
      if(i<=40) std::fprintf(stderr,"[emit] MENU drawer=0x%X slot=0x%X key=0x%X XY=(%.1f,%.1f) col=0x%X fill=%d/%d\n",
        d,s,PPC_LOAD_U32(s),F(s+0x10),F(s+0x14),PPC_LOAD_U32(s+0x48),
        (int)((PPC_LOAD_U32(d+0x50)-PPC_LOAD_U32(d+0x4c))>>2),(int)((PPC_LOAD_U32(d+0x54)-PPC_LOAD_U32(d+0x4c))>>2));
    } else { long i=no.fetch_add(1)+1;
      if(i<=6||i%2000==0) std::fprintf(stderr,"[emit] other#%ld drawer=0x%X XY=(%.1f,%.1f)\n",i,d,F(s+0x10),F(s+0x14));
    }
  }
  // [d1b] P2: the literal pushed emit-entry for the dialog_flame strip. Entry layout (FUN_82178e78):
  // [4]/[5]=+0x10/+0x14 composed XY; [8..b]=+0x20..+0x2c size ints; [e..11]=+0x38..+0x44 rec+0x40..
  // 0x4c transform matrix. If these are full-size while the container pair is (0,0) => the (0,0)
  // invisibility is a downstream layer/compose gate the port skips (layer-gate fix); if zeroed/
  // scaled and the port still draws full-size => vk_render drops the transform (field-consumption).
  if(g_inFlameWalk.load()){
    uint32_t s=ctx.r4.u32;                // s = the 100-byte emit entry (puVar15)
    uint32_t cont=g_flameContainer.load();
    float f = cont?rt_f32(base,cont+0x2Cu):1.0f;   // grow/slide factor 0(parked)..1(shown)
    if(rt_d1probe()){
      static std::atomic<long> nf{0}; long i=nf.fetch_add(1)+1;
      if(i<=80) std::fprintf(stderr,"[d1b] EMIT#%ld drawer=0x%X entry=0x%X f=%.3f XY=(%.1f,%.1f) sz(8..b)=(%.0f,%.0f,%.0f,%.0f) tf(e..11)=(%.3f,%.3f,%.3f,%.3f) key=0x%X\n",
        i,ctx.r3.u32,s,f,rt_f32(base,s+0x10u),rt_f32(base,s+0x14u),
        rt_f32(base,s+0x20u),rt_f32(base,s+0x24u),rt_f32(base,s+0x28u),rt_f32(base,s+0x2Cu),
        rt_f32(base,s+0x38u),rt_f32(base,s+0x3Cu),rt_f32(base,s+0x40u),rt_f32(base,s+0x44u),
        PPC_LOAD_U32(s));
    }
    // --- D1-B FIX: consume the container grow/slide factor the port drops. Scale the entry's
    // transform matrix (rec+0x40..0x4c = entry+0x38..0x44) by f. f<1 shrinks; f==0 => zero-area
    // quad => invisible (matches hardware's parked strip). Guest-faithful: the guest's own
    // per-container factor applied to the guest's own emit geometry. RT_STRIPFIX=0 disables (A/B).
    // RT_STRIPFIX=xy is a DIAGNOSTIC that moves the flagged entries off-screen to confirm which
    // draw fields the consumer honors.
    if(rt_stripfix() && f<0.999f){
      static const char* mode=std::getenv("RT_STRIPFIX");
      bool diagXY = mode && std::strcmp(mode,"xy")==0;
      bool diagBIG = mode && std::strcmp(mode,"big")==0;
      if(diagBIG){        // positive control: balloon the flame records to prove the edit reaches the draw
        rt_stf32(base,s+0x38u, rt_f32(base,s+0x38u)*30.0f);
        rt_stf32(base,s+0x3Cu, rt_f32(base,s+0x3Cu)*30.0f);
        rt_stf32(base,s+0x40u, rt_f32(base,s+0x40u)*30.0f);
        rt_stf32(base,s+0x44u, rt_f32(base,s+0x44u)*30.0f);
      } else if(diagXY){
        rt_stf32(base,s+0x10u, -99999.0f); rt_stf32(base,s+0x14u, -99999.0f);
      } else {
        rt_stf32(base,s+0x38u, rt_f32(base,s+0x38u)*f);
        rt_stf32(base,s+0x3Cu, rt_f32(base,s+0x3Cu)*f);
        rt_stf32(base,s+0x40u, rt_f32(base,s+0x40u)*f);
        rt_stf32(base,s+0x44u, rt_f32(base,s+0x44u)*f);
      }
    }
  }
  // DIAGNOSTIC RT_STRIPFIX=menu: offscreen ALL menu-walk emits — tests whether the shell CPU
  // emit entries (82178d78) drive the port's visible pixels at all, or whether vk_render composes
  // from a different source (in which case the D1-B fix must live in vk_render, not here).
  { static const char* md=std::getenv("RT_STRIPFIX");
    if(md && std::strcmp(md,"menu")==0 && g_inMenuWalk.load()){
      uint32_t s=ctx.r4.u32; rt_stf32(base,s+0x10u,-99999.0f); rt_stf32(base,s+0x14u,-99999.0f);
    } }
  __imp__sub_82178D78(ctx,base);
}
// PSB bind observer (log only — the menu ctx stash lives in the class-gated BB298/BA4D8
// wrappers; menu_game_title does NOT run 92E8, showmenu4 run-2 evidence).
extern "C" void __imp__sub_821B92E8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821B92E8){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  uint32_t m=ctx.r3.u32;
  __imp__sub_821B92E8(ctx,base);
  uint32_t cont=m?PPC_LOAD_U32(m+0x7c):0;
  { static std::atomic<uint32_t> last{0};
    if(cont && last.exchange(cont)!=cont)
      std::fprintf(stderr,"[mstate] 92E8 bind#%ld model=0x%X vt=0x%X container=0x%X\n",i,m,PPC_LOAD_U32(m),cont); }
}
extern "C" void __imp__sub_8217B2A0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_8217B2A0){
  uint32_t mvc=ctx.r3.u32, nameP=ctx.r4.u32, outP=ctx.r5.u32;
  __imp__sub_8217B2A0(ctx,base);
  if(rt_d1active() && ctx.r3.u32!=0 && nameP){   // register only when probing/lever active
    const char* nm=(const char*)(base+nameP);
    if(std::strcmp(nm,"dialog_flame")==0) rt_regFlameCtx(mvc);
  }
  static bool logon=std::getenv("RT_MENULOG")!=nullptr;
  if(!logon) return;
  static std::atomic<long> nh{0}, nm{0}, nmenu{0};
  bool hit=ctx.r3.u32!=0;
  bool isMenu=(mvc==g_menuMovieCtx.load());
  long i=(hit?nh:nm).fetch_add(1)+1;
  bool show=(hit&&i<=120)||(!hit&&i<=200);
  if(isMenu&&!show) show=(nmenu.fetch_add(1)+1<=200);   // menu-ctx lookups bypass the caps
  if(show)
    std::fprintf(stderr,"[namefind] ctx=0x%X%s %.40s -> %s idx=%u\n",
      mvc,isMenu?"(MENU)":"",nameP?(const char*)(base+nameP):"(null)",hit?"HIT":"MISS",(hit&&outP)?PPC_LOAD_U32(outP):0);
}
// ([mplay] logging lives in the existing sub_8217C468 contain wrapper above.)
// Per-frame transform composer: after it runs, records hold final composed XY (+0x1B8/BC).
// keyXY (bank coord) vs final XY discriminates: all-keyY==0 => coord parse loss;
// keyY varies over frames => stacked-start intro anim; keyY per-item distinct but final
// Y identical => compose/parent-chain defect.
extern "C" void __imp__sub_8217F318(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_8217F318){
  uint32_t mctx=ctx.r3.u32;
  __imp__sub_8217F318(ctx,base);
  static int on=std::getenv("RT_ITEMPOS")?atoi(std::getenv("RT_ITEMPOS")):0;
  if(!on||!mctx) return;
  bool isMenu=(mctx==g_menuMovieCtx.load());
  if(!isMenu&&on<2) return;
  uint32_t rb=PPC_LOAD_U32(mctx+0xfc), re=PPC_LOAD_U32(mctx+0x100);
  if(re<=rb) return;
  int nrec=(int)((re-rb)/0x20c);
  if(nrec<1||nrec>64) return;
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  if(i>4&&(i%(isMenu?10:60))!=0) return;
  auto F=[&](uint32_t a){ uint32_t v=PPC_LOAD_U32(a); float f; std::memcpy(&f,&v,4); return f; };
  std::fprintf(stderr,"[itempos] ctx=0x%X%s recs=%d frame=%.1f end=%d call#%ld\n",
    mctx,isMenu?" (MENU)":"",nrec,F(mctx+0xb4),(int)PPC_LOAD_U32(mctx+0x10c),i);
  for(int k=0;k<nrec;k++){
    uint32_t r=rb+(uint32_t)k*0x20c;
    uint32_t bank=PPC_LOAD_U32(r+0x1b0); if(bank>1) bank=0;
    std::fprintf(stderr,"[itempos]   r%02d par=%d vis=%u XY=(%.1f,%.1f) a=%u key=(%.1f,%.1f) bankT=%.1f ext=(%.1f,%.1f)\n",
      k,(int)PPC_LOAD_U32(r+0xc),(unsigned)PPC_LOAD_U8(r+0x1b4),F(r+0x1b8),F(r+0x1bc),
      (unsigned)PPC_LOAD_U32(r+0x1d8),F(r+bank*0x94u+0xbc),F(r+bank*0x94u+0xc0),F(r+bank*0x94u+0x88),
      F(r+0x1e0),F(r+0x1e4));
  }
}
// sub_821BD5B8 = the modal-dialog DESTRUCTOR (decomp 0x821BD5B8): sets vt, hides the
// CRscIndicator (821ccaf8/821cc9a8(ind,0) mirroring the ctor's show), frees the name, then
// base-dtor 821be788. If this NEVER runs for a kind-2 dialog while births accumulate, the
// teardown is dead and the containers leak. (kind read BEFORE impl — dtor rewrites vt.)
extern "C" void __imp__sub_821BD5B8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821BD5B8){
  uint32_t d=ctx.r3.u32; uint32_t vt=d?PPC_LOAD_U32(d):0; uint32_t kind=d?PPC_LOAD_U32(d+0xf4):0;
  if(kind==2) g_js_dlgAlive.fetch_sub(1);   // [jankstate] kind-2 dialog alive--
  if(lp2_on()&&d){ double t=lp2_ms(), born=-1;   // RT_LOADPROBE2 task lane (see ctor)
    { std::lock_guard<std::mutex> l(g_lp2m); auto it=g_lp2Born.find(d);
      if(it!=g_lp2Born.end()){ born=it->second; g_lp2Born.erase(it); } }
    std::fprintf(stderr,"[lp2] t=%.1fms TASK-DTOR dlg=0x%X kind=%u LIFETIME=%.1fms lr=0x%08X\n",
      t,d,kind,born>=0?t-born:-1.0,(uint32_t)ctx.lr); }
  if(rt_cancellife()){
    long f=g_cl_freed.fetch_add(1)+1; long b=g_cl_born.load();
    std::fprintf(stderr,"[cancellife] DESTRUCT dlg=0x%X vt=0x%X kind(+f4)=%u lr=0x%X | born=%ld freed=%ld alive=%ld\n",
      d,vt,kind,(uint32_t)ctx.lr,b,f,b-f);
  }
  __imp__sub_821BD5B8(ctx,base);
}
// Dialog dismissal funnel (kind-2 gated so save/msg dialogs are untouched): every close
// path converges on slide-out state sub_821BEED8; sub_821BD1B8 is the external timeout
// poll. Under RT_MENUHOLD these are safety nets — DECIDE is blocked upstream anyway.
extern "C" void __imp__sub_821BEED8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821BEED8){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  static bool hold=std::getenv("RT_MENUHOLD")!=nullptr;
  uint32_t d=ctx.r3.u32; uint32_t vt=d?PPC_LOAD_U32(d):0;
  uint32_t kind=d?PPC_LOAD_U32(d+0xf4):0;
  bool isDlg2=(vt==0x82050200u&&kind==2);   // BEED8 is shared too — models enter it on close
  if(i<=8) std::fprintf(stderr,"[dclose] slide-out#%ld obj=0x%X vt=0x%X kind=%u ticks=%u lr=0x%X%s\n",
    i,d,vt,kind,d?PPC_LOAD_U32(d+0x100):0,(uint32_t)ctx.lr,(hold&&isDlg2)?" HELD":"");
  if(rt_cancellife()&&isDlg2){ long s=g_cl_slideout.fetch_add(1)+1;
    if(s<=8||s%120==0) std::fprintf(stderr,"[cancellife] SLIDE-OUT#%ld dlg=0x%X ticks(+100)=%u state(+48)=0x%X\n",
      s,d,PPC_LOAD_U32(d+0x100),PPC_LOAD_U32(d+0x48)); }
  if(hold&&isDlg2) return;
  __imp__sub_821BEED8(ctx,base);
}
extern "C" void __imp__sub_821BD1B8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821BD1B8){
  static bool hold=std::getenv("RT_MENUHOLD")!=nullptr;
  uint32_t d=ctx.r3.u32;
  if(hold&&d&&PPC_LOAD_U32(d)==0x82050200u&&PPC_LOAD_U32(d+0xf4)==2){
    static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    if(i<=6) std::fprintf(stderr,"[dclose] bd1b8 timeout-poll dlg=0x%X thr=%u lr=0x%X -> held(0)\n",
      d,ctx.r4.u32,(uint32_t)ctx.lr);
    ctx.r3.u64=0; return;
  }
  // [cancellife] gate observability: does the timeout poll ever RUN for a kind-2 dialog, and
  // does it advance the state fn +0x48 (idle 82061d50 -> confirm 82061d70 -> close 82065a88)?
  bool clDlg2 = rt_cancellife() && d && PPC_LOAD_U32(d)==0x82050200u && PPC_LOAD_U32(d+0xf4)==2;
  uint32_t st0 = clDlg2 ? PPC_LOAD_U32(d+0x48) : 0;
  uint32_t thr = ctx.r4.u32;   // capture before impl clobbers r4
  __imp__sub_821BD1B8(ctx,base);
  if(clDlg2){
    static std::atomic<long> g{0}; long gi=g.fetch_add(1)+1;
    uint32_t st1=PPC_LOAD_U32(d+0x48);
    if(gi<=8||gi%300==0||st0!=st1)
      std::fprintf(stderr,"[cancellife] GATE#%ld dlg=0x%X r4/thr=%u tmr(+100)=%u state 0x%X->0x%X ret=0x%X\n",
        gi,d,thr,PPC_LOAD_U32(d+0x100),st0,st1,ctx.r3.u32);
  }
}
// ============================================================================================
// [modestub] — GRACEFUL STUBS FOR THE MODES THIS EXE DOES NOT HOST  (beta1, 2026-07-31)
// Design + full refusal-path trace: _tmpscripts/mode_stub_design.md.  User ruling
// (NOTE_campaign_decomp.md 2026-07-31 "BETA1 CUT RATIFIED" (1)): beta1 ships 1.5 ARCADE +
// XBOX 360 only; every other mode-select entry must DECLINE CLEANLY and never hang.
//
// WHY THIS IS NEEDED — the banked failure, measured twice:
//   futari_merged.exe hosts reco_normal (modeIdx 0), futari_merged_v154hi.exe hosts
//   reco_abnormal (modeIdx 1).  Picking any other mode reaches the mode-substitution guard in
//   merged_bridge.cpp, which refuses XexLoadImage.  The GUEST HAS NO ERROR HANDLING for that:
//   FUN_82088E10 collapses the status to 0 and its only "assert" is FUN_8210E878, which is
//   literally `void FUN_8210e878(void){ return; }` (retail-stripped).  So the loader ctor
//   (FUN_821C8A80 + 7 siblings) leaves modectx+0xF8 (hmodule) = 0 and modectx+0xFC (GameEntry)
//   = 0, the driver task goes live anyway, and FUN_821C39A8 spins forever: its build branch
//   needs modectx+0x78 in 1..5 (it is 0) and its kill branch needs modectx+0x68 != 0 (it is 0).
//   The shell root FSM's join FUN_821CE400 stays blocked on that live child => PERMANENT SOFT
//   WEDGE at full frame rate.  Evidence: /c/tmp/modeprobe/carve_hi/boot.log:1356+ and
//   /c/tmp/modeprobe/mp_refuse/boot.log:1282+ — both end on `[bootsm] CE400 … cur76=6 want80=5`
//   with `[modegate] … mode78=0 gate=CLOSED` and `[lstate] sub_821C39A8#…` still counting.
//   ⚠ Returning a different NTSTATUS from XexLoadImage is NOT a fix — the guest discards it.
//
// THREE LAYERS, ALL GUEST-NATIVE (we reach the game's OWN decline flows, we invent nothing):
//   L1  sub_821B80D0 (game-select ctor) — call the guest's own per-item disable setter
//       FUN_821BA280(menu, titleIdx, 1) for every title row this build cannot serve.  The ACTIVE
//       state FUN_821BA4D8 then SWALLOWS the A press on a row whose record +0x20 has bit 0 set
//       (`(*(uint*)(rec+0x20) & 1) != 0` short-circuits the confirm and falls through to the
//       B-only branch).  This is exactly what the game already does to grey the un-entitled
//       Black Label row — the ctor itself calls FUN_821ba280(this,2,1) when
//       *(DAT_821F858C+0x38F0) & 1 == 0.  Presentation AND veto in one guest call.
//   L2  sub_821B7CC0 (the modeIdx fold) — L1 cannot express the ARCADE/XBOX-360 sub-choice
//       (one title row = two modeIdx, and the arcade_front panel FUN_821D2628 is a different
//       class).  So if the folded modeIdx is not ours, take the function's OWN out-of-range
//       branch LAB_821B7DA8 verbatim: `*(this+0x48) = 0x82061D50` (= vt+0x30 = FUN_821BA4D8 =
//       ACTIVE) and nothing else — phase (+0xA4) and modeIdx (+0xBC) stay untouched, so the root
//       FSM never leaves phase 5.
//   L3  sub_821C39A8 (safety net) — if a modectx ever reaches the driver with hmodule == 0, set
//       modectx+0x68 = 1.  That is the guest's own abort flag: the tail of FUN_821C39A8 appends
//       delegate 0x820619F0 (`*(task+8) = 2`, the engine's universal kill), the driver task dies,
//       FUN_821CE400's child-count guard clears and FUN_821CE098 re-dispatches with root+0x50
//       already pre-set to 5 by phase 6 => a fresh TOP MENU.  Same sequence
//       NOTE_fnf11_handback_decomp.md PART 2 measured for the in-ROM "return to top menu" quit.
//       Proof of the field (shell/gen/ppc_recomp.34.cpp, __imp__sub_821C39A8 tail):
//           lwz r11,184(r31)   ; task+0xB8 = modectx
//           lwz r10,104(r11)   ; modectx+0x68     <-- DOUBLE deref
//           cmpwi cr6,r10,0 / beq ... / bl 0x820735c8 with r4 = 0x820619F0
//       ⚠MIS ATLAS_scene_system.md §8.6 reads this as `driverObj+0x68` (= modeIdx).  It is not:
//       the asm double-loads, so it is modectx+0x68 on the LOADER object.  §8.6's "driverObj+0x68
//       double-duty unresolved" gap is closed by that asm.
//
// ⚠ TRAP DELIBERATELY NOT USED: FUN_821B7CC0's Black-Label entitlement arm sets
//   *(this+0xB8) = LAB_820662C8 and returns WITHOUT advancing +0x48.  The [gsel] block further
//   down (2026-07-12) banked what that does here: caller FUN_821BA090 re-invokes vt+0x20 every
//   tick => infinite per-tick retry, the `cur76=5 want80=-1` "Now Loading" hang.  Never copy it.
//
// LEVER: RT_MODESTUB=0 reverts ALL THREE layers to the pre-stub behaviour (i.e. back to the
// wedge) for A/B without a rebuild.  DEFAULT IS ON — this is shipping behaviour, not a probe.
// Every veto / grey / safety fire prints a [modestub] line: positive-control requirement, so a
// gate log can prove the layer RAN rather than inferring it from an absence.
static bool rt_modestub(){
  static bool on = [](){ const char* e = std::getenv("RT_MODESTUB"); return e ? atoi(e)!=0 : true; }();
  return on;
}
// ============================================================================================
// sub_821C39A8 gets a custom wrapper: RT_MODEPICK pokes the mode selection into THIS task's own
// modectx (+0xb8 → +0x78) after it has been parked ~120 ticks — right object, right time
// (the earlier 69F0-side poke hit a different modectx instance).
// [modestub] L3 (safety net) also lives here — see the block above.
extern "C" void __imp__sub_821C39A8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821C39A8){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  uint32_t t=ctx.r3.u32;
  if(i<=3||i%600==0)
    std::fprintf(stderr,"[lstate] sub_821C39A8#%ld task=0x%X flavor6c=0x%X\n",i,t,t?PPC_LOAD_U32(t+0x6c):0);
  { static int mp = std::getenv("RT_MODEPICK")?atoi(std::getenv("RT_MODEPICK")):0;
    if(mp && t && i>=120){ uint32_t mc2=PPC_LOAD_U32(t+0xb8);
      if(mc2 && PPC_LOAD_U32(mc2+0x78)==0){ static std::atomic<int> did{0};
        if(!did.exchange(1)){ PPC_STORE_U32(mc2+0x78,(uint32_t)mp);
          std::fprintf(stderr,"[modepick] 39A8#%ld poked ITS modectx=0x%X +0x78=%d\n",i,mc2,mp); } } } }
  // ---- [modestub] L3: SAFETY NET -----------------------------------------------------------
  // L1+L2 close the two routes a player can drive.  L3 exists so the wedge is unreachable BY
  // CONSTRUCTION for everything else: a stale/absent assets/media/Module/*.xex, a bad
  // XR_RECO_NORMAL override, or any other caller of FUN_821C3F38 (e.g. the replay page
  // FUN_821D0CB0 id 3, which reads the mode back through driverVt+0x10).
  // Predicate is register-true and module-agnostic: modectx+0xF8 is the hmodule slot written by
  // ALL EIGHT loader ctors (puVar3[0x3e] — verified identical in FUN_821C8A80/821C8200/821C7980/
  // 821C2F58/821C4D70/821C44F0/821C9B80/821C9300), so 0 there means "XexLoadImage returned 0",
  // i.e. refused or genuinely missing.  Fires once per modectx (the +0x68 test self-latches).
  if(rt_modestub() && t){
    uint32_t mc3 = PPC_LOAD_U32(t+0xb8);
    if(mc3 && PPC_LOAD_U32(mc3+0xF8)==0 && PPC_LOAD_U32(mc3+0x68)==0){
      PPC_STORE_U32(mc3+0x68, 1u);
      std::fprintf(stderr,"[modestub] L3 SAFETY task=0x%X modectx=0x%X hmodule(+0xF8)=0 "
                          "(module load refused/failed) -> +0x68=1: driver task self-kills, "
                          "root FSM join unblocks -> phase 5 = fresh TOP MENU\n", t, mc3);
    }
  }
  __imp__sub_821C39A8(ctx,base);
}
// [ldst] (2026-07-23 +124-writer leg): sub_821C3530 = THE load-complete stamper — task state fn:
// flavor *(task+0x6c)==1 -> poll vt[0x38] ("still loading?"); on 0 -> *(modectx+0x7c)=4 (the
// latch [modegate] proved missing) -> next state 821c39a8 (mode pages). else-flavor -> direct
// vt[0x18](mc,1,4) jump (no menu — likely the Arcade card). Log entry/flavor/predicate result.
extern "C" void __imp__sub_821C3530(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821C3530){
  uint32_t task=ctx.r3.u32;
  uint32_t f6c=task?PPC_LOAD_U32(task+0x6c):0xDEAD;
  uint32_t mc=task?PPC_LOAD_U32(task+0xb8):0;
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  uint32_t pre124 = mc?PPC_LOAD_U32(mc+0x7c):0xDEAD;
  __imp__sub_821C3530(ctx,base);
  uint32_t post124 = mc?PPC_LOAD_U32(mc+0x7c):0xDEAD;
  if(i<=20 || pre124!=post124 || i%600==0)
    std::fprintf(stderr,"[ldst] 3530#%ld task=0x%X flavor6c=%d mc=0x%X +124 %u->%u%s\n",
      i,task,(int)f6c,mc,pre124,post124,(pre124!=post124)?"  <== STAMPED":"");
}
extern "C" void __imp__sub_821C69F0(PPCContext& __restrict, uint8_t*);
extern "C" void __imp__sub_821C5998(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821C69F0){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  uint32_t mc=ctx.r3.u32;
  // RT_TICKGATE: force this ACTUAL ticked modectx's transition-stepper gate open
  // (modectx+124==4 && +120==0), so sub_821C6860 runs and drives screen transitions.
  // Earlier RT_NATIVETICK wrote g_defer_inner, which is a DIFFERENT object than the one
  // ticked here (0x36CEE0) — that's why it was "necessary but not sufficient".
  { static int tg = std::getenv("RT_TICKGATE")?std::atoi(std::getenv("RT_TICKGATE")):0;
    if(mc && tg){
    // tg==1: force from boot (legacy — EATS the natural summon, keep only for pre-summon
    // experiments). tg==2: DEFERRED — arm only after the natural summon (mode78!=0 seen once),
    // emulating the hardware post-load state (loader stamped +124=4, pick consumed +120=0) so
    // the 69F0 dispatch runs 6860 and input edges drive show/6560 naturally.
    static std::atomic<int> once{0}; static std::atomic<int> armed2{0};
    uint32_t f124=PPC_LOAD_U32(mc+124), f120=PPC_LOAD_U32(mc+120);
    if(tg==2 && !armed2.load()){
      if(f120!=0 && f120!=0xffffffffu){ armed2.store(1);
        std::fprintf(stderr,"[tickgate] deferred arm: summon seen (+120=0x%X) -> forcing gate open from now\n",f120); }
    }
    if(tg==1 || armed2.load()){
      if(f124!=4){ PPC_STORE_U32(mc+124,4); if(once.fetch_add(1)<2) std::fprintf(stderr,"[tickgate] modectx=0x%X +124 0x%X->4\n",mc,f124); }
      if(f120!=0){ PPC_STORE_U32(mc+120,0); }
    }
  } }
  // [modegate] (2026-07-23 mode-menu leg): periodic + on-change log of the dispatch-gate fields
  // (+124==4 && +120==0 && +244!=0) plus mode index +0x78 and mode-record[0..4]+68 — the skip
  // condition hunt for the missing Normal Play/Score Attack menu (user-oracle: unconditional on HW).
  if(mc){
    uint32_t f120=PPC_LOAD_U32(mc+120), f124=PPC_LOAD_U32(mc+124), f244=PPC_LOAD_U32(mc+244), f78=PPC_LOAD_U32(mc+0x78);
    uint32_t G=PPC_LOAD_U32(0x821F8588u), m2=G?PPC_LOAD_U32(G+76):0, T=m2?PPC_LOAD_U32(m2+80):0;
    // [watchrec] RT_WATCHREC: once the mode-record table resolves, guard-page-watch the whole
    // 5-record block (5*0x84) to catch the flags(+0x44) writers by host RIP (symbolicate via
    // futari_merged.map). Dynamic arm — table is heap-allocated.
    if(T && std::getenv("RT_WATCHREC")){
      static std::atomic<int> armed{0};
      if(!armed.exchange(1)) rt_watch_arm_dyn(T, 5*0x84);
    }
    // [edgetest] RT_EDGETEST: inject the 0x8000 EDGE (shell-logical = R-trigger per input atlas)
    // into user-0's edge word (rec0+0x44) once/sec — the bit FUN_821C6860 steps its counter on.
    // Diagnostic for the mode-menu chain: with RT_TICKGATE, counter should move -> 6860 true ->
    // 69F0 modectx dispatch runs -> menu/page UI. (Writer proven: sub_82191340 edge derive.)
    if(T && std::getenv("RT_EDGETEST")){
      static std::atomic<int> et{0}; int e=et.fetch_add(1)+1;
      // alternate 0x8000 (cursor++) / 0x4000 (cursor--) so the cursor keeps moving and 6560
      // keeps re-rendering the page strip (a saturated cursor stops the pageChanged path).
      if(e%60==0){ uint32_t bit=((e/60)&1)?0x8000u:0x4000u;
        PPC_STORE_U32(T+0x44, PPC_LOAD_U32(T+0x44)|bit);
        if(e<=1200) std::fprintf(stderr,"[edgetest] injected 0x%X edge into rec0+0x44 (tick %d)\n",bit,e); }
    }
    // [modepick] RT_MODEPICK=<n>: one-shot poke of the mode selection modectx+0x78 while the
    // launch task is parked in 39a8 — 39a8 should then create the page-menu task (FUN_821d05e8;
    // TRAINING = page 2 for modes 2/3/4) and advance to the 35e0 launch dispatcher.
    { static int mp = std::getenv("RT_MODEPICK")?atoi(std::getenv("RT_MODEPICK")):0;
      if(mp && i>=300){ static std::atomic<int> did{0};
        if(!did.exchange(1)){ PPC_STORE_U32(mc+0x78,(uint32_t)mp);
          std::fprintf(stderr,"[modepick] poked modectx+0x78=%d at tick#%ld\n",mp,i); } } }
    uint32_t r0=T?PPC_LOAD_U32(T+68):0, r1=T?PPC_LOAD_U32(T+132+68):0, r2=T?PPC_LOAD_U32(T+264+68):0;
    static uint64_t lk=~0ull;
    uint64_t key=((uint64_t)(f124&0xFF))|((uint64_t)(f120&0xFF)<<8)|((uint64_t)(f244!=0)<<16)
      |((uint64_t)(f78&0xFF)<<17)|((uint64_t)(r0&0xFF)<<25)|((uint64_t)(r1&0xFF)<<33)|((uint64_t)(r2&0xFF)<<41);
    if(key!=lk || i%600==0){ lk=key;
      // engine health: +0x48 state fn (d50=active drawer, d70=parked — show only flips d70->d50),
      // +0x8c shown flag, +0x134 auto-hide countdown, +0x138 cursor.
      uint32_t e48=f244?PPC_LOAD_U32(f244+0x48):0, e8c=f244?PPC_LOAD_U8(f244+0x8c):0,
               e134=f244?PPC_LOAD_U32(f244+0x134):0, e138=f244?PPC_LOAD_U32(f244+0x138):0;
      std::fprintf(stderr,"[modegate] 69F0#%ld mc=0x%X +120=0x%X +124=0x%X +244=0x%X mode78=%u | rec+68: r0=0x%X r1=0x%X r2=0x%X | gate=%s | eng48=0x%X 8c=%u t134=%u cur=%u\n",
        i,mc,f120,f124,f244,f78,r0,r1,r2,(f124==4&&f120==0&&f244!=0)?"OPEN":"CLOSED",e48,e8c,e134,e138); }
    // [showpage] RT_SHOWPAGE: display-enable hypothesis for the invisible built page. 6860's edge
    // path calls FUN_821c5998(engine,1) (enable); 39a8 calls it with 0 (disable) before creating
    // the page task. After the natural summon (mode78!=0) settle ~60 ticks, then enable once.
    { static int sp = std::getenv("RT_SHOWPAGE")?std::atoi(std::getenv("RT_SHOWPAGE")):0;
      if(sp){
      static std::atomic<int> did{0}; static std::atomic<int> settle{0};
      if(f78!=0 && f78!=0xffffffffu){
        int s=settle.fetch_add(1)+1;
        if(s>=60 && !did.exchange(1)){
          uint32_t eng=PPC_LOAD_U32(mc+0xf4);
          std::fprintf(stderr,"[showpage] mode78=%u engine(mc+0xf4)=0x%X -> calling 821C5998(engine,1)\n",f78,eng);
          if(eng){ PPCContext ic=ctx; ic.r3.u32=eng; ic.r4.u64=1; __imp__sub_821C5998(ic,base); }
        }
        // lvl>=2: keep the auto-hide countdown (engine+0x134, decremented by the engine tick at
        // 0x821C5F30; hide fires at 0) topped up — on hardware every input edge re-arms it via
        // 6860 -> 5998(engine,1). Emulates "user is interacting".
        if(sp>=2 && did.load()){
          uint32_t eng=PPC_LOAD_U32(mc+0xf4);
          if(eng && PPC_LOAD_U32(eng+0x134)<0x10u) PPC_STORE_U32(eng+0x134,0x78u);
        }
      }
    } }
  }
  __imp__sub_821C69F0(ctx,base);
  // [engpump] RT_ENGPUMP: the menu engine's +0x48 state fn is never pumped by the port (root
  // gap, d528701 — sibling 0x37E530 gets pumped, engine doesn't). Diagnostic: tick it ourselves
  // once per 69F0 tick. r3=engine; the d50/d70 thunks dispatch engine->vt[0x30]/[0x34]; r4=0.
  if(mc && std::getenv("RT_ENGPUMP")){
    uint32_t eng=PPC_LOAD_U32(mc+0xf4);
    // Hardware pump = sub_82173B98 per object: if (*(obj+0x20)==0) call obj->vt[0xC] (the TICK
    // virtual — which for this family reads/steps +0x48 AND services children like the +0x40
    // closer list). Call the real tick virtual, not +0x48 directly.
    if(eng && PPC_LOAD_U32(eng+0x20)==0){
      uint32_t vt=PPC_LOAD_U32(eng), tick=vt?PPC_LOAD_U32(vt+0xC):0;
      uint32_t st=PPC_LOAD_U32(eng+0x48);
      if(tick>=0x82000000u && tick<0x82200000u){
        static std::atomic<long> pn{0}; long p=pn.fetch_add(1)+1;
        static uint32_t lastst=0;
        if(p==1) std::fprintf(stderr,"[engpump] engine vt=0x%X: vt30(drawer)=0x%X vt34(parked)=0x%X vtC(tick)=0x%X\n",
          vt,PPC_LOAD_U32(vt+0x30),PPC_LOAD_U32(vt+0x34),tick);
        if(p<=3||p%600==0||st!=lastst){ lastst=st;
          std::fprintf(stderr,"[engpump] tick#%ld engine=0x%X vt=0x%X vtC=0x%X state48=0x%X\n",p,eng,vt,tick,st); }
        PPCContext ic=ctx; ic.r3.u32=eng; ic.r4.u64=0;
        { PPCContext& ctx=ic; PPC_CALL_INDIRECT_FUNC(tick); }
        // RT_DARKBD: at cursor==4 the 5998-show backdrop color formula yields 0xFFFFFFFF —
        // opaque white — and the quad covers the screen. If the menu text draws white too,
        // the whole overlay is white-on-white. Force a dark backdrop to reveal it.
        if(std::getenv("RT_DARKBD")){
          uint32_t bd=PPC_LOAD_U32(eng+0xd8);
          if(bd) PPC_STORE_U32(bd+8,0x202040FFu);
        }
      }
    }
  }
}
// [engst] engine state THUNKS: sub_82061D50 (active — dispatches engine->vt[0x30]) and
// sub_82061D70 (parked — vt[0x34]). Show flips the +0x48 slot d70->d50; counting entries tells
// whether the active state ever runs and what virtual it lands in.
extern "C" void __imp__sub_82061D50(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_82061D50){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  uint32_t l1o=ctx.r3.u32, l1vt=l1o?PPC_LOAD_U32(l1o):0, l1s0=l1o?PPC_LOAD_U32(l1o+0x48):0;
  rt_l1_tick(0x82061D50u,l1vt);
  if(i<=10||i%600==0){
    uint32_t o=ctx.r3.u32, vt=o?PPC_LOAD_U32(o):0, tgt=vt?PPC_LOAD_U32(vt+48):0;
    std::fprintf(stderr,"[engst] D50-ACTIVE#%ld obj=0x%X vt=0x%X -> fn30=0x%X lr=0x%X\n",i,o,vt,tgt,(uint32_t)ctx.lr);
  }
  __imp__sub_82061D50(ctx,base);
  rt_l1_cursor(base,l1o,l1vt);                    // [l1cur] cursor oracle (menu +0x9C / panel +336)
  { uint32_t l1s1=l1o?PPC_LOAD_U32(l1o+0x48):0; if(l1s1!=l1s0) rt_l1_emit("S %X %X %X\n",l1vt,l1s0,l1s1); }
}
extern "C" void __imp__sub_82061D70(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_82061D70){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  uint32_t l1o=ctx.r3.u32, l1vt=l1o?PPC_LOAD_U32(l1o):0, l1s0=l1o?PPC_LOAD_U32(l1o+0x48):0;
  rt_l1_tick(0x82061D70u,l1vt);
  if(i<=5||i%1800==0){
    uint32_t o=ctx.r3.u32, vt=o?PPC_LOAD_U32(o):0, tgt=vt?PPC_LOAD_U32(vt+52):0;
    std::fprintf(stderr,"[engst] D70-PARKED#%ld obj=0x%X vt=0x%X -> fn34=0x%X\n",i,o,vt,tgt);
  }
  __imp__sub_82061D70(ctx,base);
  rt_l1_cursor(base,l1o,l1vt);                    // [l1cur] cursor oracle (menu +0x9C / panel +336)
  { uint32_t l1s1=l1o?PPC_LOAD_U32(l1o+0x48):0; if(l1s1!=l1s0) rt_l1_emit("S %X %X %X\n",l1vt,l1s0,l1s1); }
}
// [pgr] page renderer FUN_821c6560(engine,page,changed) — the natural content pump (6860's
// change path). 6860 itself is already wrapped as [ntick2] above.
extern "C" void __imp__sub_821C6560(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821C6560){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  std::fprintf(stderr,"[pgr] 6560#%ld engine=0x%X page=%u changed=%u lr=0x%X\n",
    i,ctx.r3.u32,(uint32_t)ctx.r4.u32,(uint32_t)(ctx.r5.u32&0xFF),(uint32_t)ctx.lr);
  __imp__sub_821C6560(ctx,base);
}
// [disp] RT_DISPLOG: log every call of the display-enable/disable fn FUN_821c5998 (engine,val)
// with caller lr — who suppresses/enables the shell page layer around the summon.
PPC_FUNC(sub_821C5998){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  uint32_t val=(uint32_t)ctx.r4.u32;
  uint32_t bdjEng=ctx.r3.u32, bdjLr=(uint32_t)ctx.lr;   // captured BEFORE the body: r3/lr are scratch after it
  if(std::getenv("RT_DISPLOG")){
    if(i<=40||i%600==0||val==1) std::fprintf(stderr,"[disp] 821C5998#%ld engine=0x%X val=%u lr=0x%X\n",
      i,ctx.r3.u32,val,(uint32_t)ctx.lr);
  }
  // RT_NOCLOSER: the hide path spawns the closer fade (FUN_821be9d0) whenever 8c was 1 — in our
  // port nothing ticks it, so it wedges a fullscreen WHITE quad. Zero 8c pre-hide: the closer
  // branch is skipped (8c already 0), the rest of hide (timer clear) proceeds unchanged.
  if(val==0 && std::getenv("RT_NOCLOSER") && ctx.r3.u32) PPC_STORE_U8(ctx.r3.u32+0x8c,0);
  __imp__sub_821C5998(ctx,base);
  // ★ r23-w17 C1(d) [bdjoin] — THE FORMULA HALF.  Read AFTER the real body, so bdcol is the value
  //   the guest ACTUALLY WROTE rather than a re-derivation of its arithmetic here: re-deriving it
  //   would put a second implementation of the thing under test inside the instrument, and the two
  //   could agree while both being wrong about what reached memory.
  if(rt_bdjoin() && bdjEng){
    uint32_t bd=PPC_LOAD_U32(bdjEng+0xd8u);
    std::fprintf(stderr,"[bdjoin] f%ld 5998#%ld val=%u cur=%u bd=0x%X bdcol=0x%08X st48=0x%X shown8c=%u closer=0x%X lr=0x%X\n",
      rt_bdj_frame(),i,val,PPC_LOAD_U32(bdjEng+0x138u),bd,bd?PPC_LOAD_U32(bd+8u):0u,
      PPC_LOAD_U32(bdjEng+0x48u),(unsigned)PPC_LOAD_U8(bdjEng+0x8cu),PPC_LOAD_U32(bdjEng+0x90u),bdjLr);
  }
}
// ★ r23-w17 C1(d) [closer] — sub_821BE9D0 is the CLOSER FADE constructor that sub_821C5998's HIDE
//   arm spawns whenever +0x8c was 1.  THIS FILE'S OWN RT_NOCLOSER COMMENT (a few lines up) names
//   it as wedging "a fullscreen WHITE quad" because nothing in the port ticks it — i.e. it is a
//   SECOND documented opaque-white producer inside the same subsystem, and no wash leg has ever
//   asked whether it is live while a stage is on screen.  Free to arm alongside the backdrop tap;
//   its zero is subject to the same clone-bypass caveat as [bddraw]'s.
extern "C" void __imp__sub_821BE9D0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821BE9D0){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  uint32_t obj=ctx.r3.u32, owner=(uint32_t)ctx.r4.u32, lr=(uint32_t)ctx.lr;
  __imp__sub_821BE9D0(ctx,base);
  if(rt_bdjoin())
    std::fprintf(stderr,"[closer] f%ld 821BE9D0#%ld obj=0x%X owner=0x%X lr=0x%X\n",
      rt_bdj_frame(),i,obj,owner,lr);
}
PPC_FUNC(sub_8216B148){
  long n=g_b148.fetch_add(1)+1;
  __imp__sub_8216B148(ctx,base);
  { static const bool rtModeTickB148 = std::getenv("RT_MODETICK")!=nullptr;
    if(rtModeTickB148 && (n<=10 || n%100==0)) modetick_dump(base,"b148",n); }
}

// ---- [bootsm] the shell's BOOT-ASSET state machine (2026-07-06 milestone leg) ----
// sub_821CDD30 = init: this+76=2, +80=3, this+72 := sub_821CE400 (initial state fn)
// sub_821CDD50 = PUMP: one-line tail-call through *(this+72)  [subscriber vtable 0x8204FA9C]
// state chain: CE400 -> ... -> CDBE8 -> CD490 (gate poll: byte *(*(this+496)+112) != 0)
//   -> CD378 = THE MANIFEST WALKER (8 records @0x821ECB78+32, stride 52; issues loads
//      via sub_82194DF8 on *(*(0x821F8688)+80); menu/font/logo/StringTable set)
// manifest table built by sub_821D3D10 (no static caller — static-ctor/indirect).
extern "C" void __imp__sub_821CDD30(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821CDD30){
  std::fprintf(stderr,"[bootsm] INIT CDD30 this=0x%X\n",ctx.r3.u32);
  __imp__sub_821CDD30(ctx,base);
}
extern "C" void __imp__sub_821CDD50(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821CDD50){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  static std::atomic<uint32_t> last{0};
  uint32_t t=ctx.r3.u32, st=PPC_LOAD_U32(t+72);
  if(i<=4 || st!=last.exchange(st) || i%600==0)
    std::fprintf(stderr,"[bootsm] PUMP#%ld this=0x%X statefn=0x%X\n",i,t,st);
  __imp__sub_821CDD50(ctx,base);
}
// [pidx] sub_821915C0(array r3, user r4) = get-processed-input-for-user. Confirms WHICH
// user the game's cb2 reads during attract (demo record vs our user0) + the returned mask.
extern "C" void __imp__sub_821915C0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821915C0){
  uint32_t arr=ctx.r3.u32, user=ctx.r4.u32;
  uint16_t rawbtn = (arr && user<4) ? PPC_LOAD_U16(arr+user*132+176) : 0;
  __imp__sub_821915C0(ctx,base);
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  static uint32_t lastmask=0xDEAD;
  if(i<=8 || ctx.r3.u32!=lastmask){ lastmask=ctx.r3.u32;
    std::fprintf(stderr,"[pidx] arr=0x%X user=%u rawbtn=0x%04X -> mask=0x%X\n",arr,user,rawbtn,ctx.r3.u32); }
}
static void tprobe_tick(const char* state, uint32_t t, uint8_t* base);   // RVK_TITLEPROBE, defined below
// [cbf58] the title item's 30-frame-timer state. Counts this+124 to 30 then advances to
// CBEF8. It stalls at CBF58 forever — is it pumped (called) at all after arming? Log calls.
extern "C" void __imp__sub_821CBF58(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821CBF58){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  uint32_t t=ctx.r3.u32, c=PPC_LOAD_U32(t+124), per=PPC_LOAD_U32(t+128);
  // at timer expiry (cnt hits 30) the advance gate reads obj+20 where obj=*(*(G+76)+84);
  // obj+20==1 => SKIP (no advance to CBEF8) => title stalls. Log obj+20 around the boundary.
  uint32_t G=PPC_LOAD_U32(0x821F8588u), m=G?PPC_LOAD_U32(G+76):0, obj=m?PPC_LOAD_U32(m+84):0;
  uint32_t o20=obj?PPC_LOAD_U32(obj+20):0xEE;
  if(i<=40 || i%200==0 || c>=28) std::fprintf(stderr,"[cbf58] call#%ld this=0x%X cnt=%u per=%u | obj=0x%X obj+20=%u\n",i,t,c,per,obj,o20);
  uint32_t sf_before=PPC_LOAD_U32(t+72);
  __imp__sub_821CBF58(ctx,base);
  uint32_t sf_after=PPC_LOAD_U32(t+72);
  if(sf_before!=sf_after) std::fprintf(stderr,"[cbf58] ADVANCED statefn 0x%X -> 0x%X (obj+20 was %u)\n",sf_before,sf_after,o20);
  tprobe_tick("CBF58", ctx.r3.u32, base);
}
// ★★ RVK_TITLEPROBE (2026-07-31, alpha2 1:1 campaign — TITLE BLINK CADENCE PROBE). DEFAULT OFF.
//
// WHY. The compose census (d280de9) caught the PRESS START element vanishing 2-frames-on /
// 2-off x7 over 0.47s and could not say whether that was the guest or the port. The guest law
// is known exactly (ghidra_futari_decomp/SPEC_shell_compose_1to1.md §13 row 1; decomp
// FUN_821cbff0 @0x821CBFF0):
//
//     D   = task[+0x80]                                  (blink divisor)
//     ctr = ++task[+0x7C]
//     if (ctr % D != 0)  hide( *(task+0x58) + 0x0C ) = (ctr / D) & 1     // hide-byte square wave
//     cmd = FUN_82190A90(pad); task[+0x6C] = cmd
//     if (cmd < 4) { task[+0x7C] = 0; task[+0x80] = 2; task[+0x48] = 0x821CBF58; }   // ACCEPT
//
// so the element's on/off RUN LENGTH in ticks is exactly D, and the post-accept state
// (sub_821CBF58, same square wave, D=2, exits at ctr>=30) is an AUTHORED 30-tick 2/2 strobe.
// The oracle (SDK + Xbox 360, banked 07-21) says the pre-accept cadence is 20-on/20-off, i.e.
// the ctor's initial D must read 0x14 — and SPEC §13's synthesis delta flags exactly that as
// still open: "Initial-D ctor still [GAP] (needs a runtime read)". Nobody had ever hooked
// FUN_821CBFF0, only its post-accept successor. This probe closes that gap and, in the same
// pass, measures the tick-vs-present cadence that a welded-clock class would show up in.
//
// WHAT IT LOGS (per tick of either title-item state, both halves stamped with g_rt_presentN):
//   [tprobe] <state> tick=<n> pres=<P> dPres=<k> ctr=<c> D=<d> hide=<h> elem=0x<e>
// on every HIDE-BYTE TRANSITION, plus the first 3 ticks (the ctor's initial D, printed before
// the guest has had a chance to change it), plus a 120-tick heartbeat, plus a RUN summary line
// naming the completed run length in TICKS and in PRESENTS. dPres = presents elapsed since the
// previous tick: a steady 1 is the welded 1:1 clock; anything else is the pacing class.
//   RVK_TITLEPROBE=1  transitions + runs + heartbeat        (what the gates use)
//   RVK_TITLEPROBE=2  + EVERY tick (dense cadence dump; ~60 lines/s while the title holds)
// Pass-through is byte-identical when unset: the hook reads guest memory and prints, and
// touches nothing. Renderer-side companion = the [tprobe] run-length tracker in
// render/vk_render.cpp (observed presence per PRESENT), so guest-truth and glass-truth can be
// diffed without trusting either alone.
extern "C" { extern long g_rt_presentN; }
static int tprobe_lvl(){ static int v = std::getenv("RVK_TITLEPROBE") ? atoi(std::getenv("RVK_TITLEPROBE")) : 0; return v; }
static void tprobe_tick(const char* state, uint32_t t, uint8_t* base){
  int lvl = tprobe_lvl(); if(!lvl || !t) return;
  static long tick = 0; static long lastPres = 0;
  static uint8_t lastHide = 0xEE; static long runTicks = 0, runStartPres = 0;
  long P = g_rt_presentN, dP = P - lastPres; lastPres = P;
  ++tick;
  uint32_t ctr = PPC_LOAD_U32(t + 0x7C), D = PPC_LOAD_U32(t + 0x80), elem = PPC_LOAD_U32(t + 0x58);
  uint8_t hide = (elem && elem < 0x20000000u) ? *(base + elem + 0xC) : 0xEE;
  ++runTicks;
  bool trans = (hide != lastHide);
  if(trans && lastHide != 0xEE)
    std::fprintf(stderr,"[tprobe] RUN %s hide=%u lasted ticks=%ld presents=%ld (expect D=%u) -> hide=%u\n",
                 state, lastHide, runTicks - 1, P - runStartPres, D, hide);
  if(trans){ lastHide = hide; runTicks = 1; runStartPres = P; }
  if(lvl >= 2 || trans || tick <= 3 || (tick % 120) == 0)
    std::fprintf(stderr,"[tprobe] %s tick=%ld pres=%ld dPres=%ld ctr=%u D=%u hide=%u elem=0x%X\n",
                 state, tick, P, dP, ctr, D, hide, elem);
}
// The PRE-ACCEPT title-item state (the one the oracle's 20-on/20-off applies to). Ticked once
// per shell frame while the title holds; hands off to sub_821CBF58 on accept.
extern "C" void __imp__sub_821CBFF0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821CBFF0){
  if(!tprobe_lvl()){ __imp__sub_821CBFF0(ctx,base); return; }
  uint32_t t = ctx.r3.u32;
  uint32_t sf_before = t ? PPC_LOAD_U32(t + 72) : 0;
  __imp__sub_821CBFF0(ctx,base);
  tprobe_tick("CBFF0", t, base);
  uint32_t sf_after = t ? PPC_LOAD_U32(t + 72) : 0;
  if(sf_before != sf_after)
    std::fprintf(stderr,"[tprobe] ACCEPT (cmd<4): statefn 0x%X -> 0x%X, ctr reset to %u, D := %u @pres=%ld\n",
                 sf_before, sf_after, t ? PPC_LOAD_U32(t + 0x7C) : 0, t ? PPC_LOAD_U32(t + 0x80) : 0, g_rt_presentN);
}
// [input] confirm synthetic buttons reach the latch + produce a nonzero processed mask.
// sub_821905A0(r3=input-array, r4=user): calls XamInputGetState, caches gamepad into
// record+120 (buttons first halfword). Log the latched buttons for user 0.
extern "C" void __imp__sub_821905A0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821905A0){
  uint32_t arr=ctx.r3.u32, user=ctx.r4.u32;
  __imp__sub_821905A0(ctx,base);
  if(user==0){
    uint32_t rec=arr+user*132; uint16_t btn=PPC_LOAD_U16(rec+176); // gamepad snapshot lands at +176
    static uint16_t last=0xFFFF;
    if(btn!=last){ last=btn; std::fprintf(stderr,"[input] latch user0 buttons=0x%04X (rec=0x%X+176)\n",btn,rec); }
  }
}
// sub_82190B38(r3=record+176): processes latched input into the button mask the menu reads.
extern "C" void __imp__sub_82190B38(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_82190B38){
  __imp__sub_82190B38(ctx,base);
  static std::atomic<uint32_t> last{0xDEAD}; uint32_t r=ctx.r3.u32;
  if(r!=0 && r!=last.exchange(r)) std::fprintf(stderr,"[input] processed mask -> 0x%X\n",r);
}
// SIGFPE GUARD (np4 2026-07-07): sub_82114628 = shell pool-FREE; computes slot index as
// (obj - poolbase) / stride with stride = *(pooldesc+4), pooldesc = *((obj - *(obj-4)) - 8).
// The original ucode guards the divide with `twllei r8,0` (trap) which XenonRecomp DROPS ->
// raw host divide -> SIGFPE on the shell service thread (kills the game service pump) when a
// sound object with a zero/garbage pool header is freed (merged's XACT banks are empty; hit
// when the in-game menu confirm SE fires — np4 backtrace: rt_thread_main -> sub_821CB108 ->
// sub_88090480 pump -> game SE emit sub_880E4CD0/4A78 -> shell snd chain -> FAULT here).
// Skip the free (leak one object) instead of faulting. Always on; logs first hits.
extern "C" void __imp__sub_82114628(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_82114628){
  uint32_t r3=ctx.r3.u32;
  uint32_t hdr = (r3>=0x1000 && r3<0xFFFF0000) ? PPC_LOAD_U32(r3-4) : 0xFFFFFFFFu;
  uint32_t obj = r3-hdr;
  uint32_t pd  = (hdr!=0xFFFFFFFFu && obj>=0x1008 && obj<0xFFFF0000) ? PPC_LOAD_U32(obj-8) : 0;
  uint32_t stride = (pd>=0x1000 && pd<0xFFFF0000) ? PPC_LOAD_U32(pd+4) : 0;
  if(stride==0){
    static int lg=0; if(lg++<8)
      std::fprintf(stderr,"[sfpe] sub_82114628 SKIP free obj=0x%X hdr=0x%X pooldesc=0x%X stride=0\n",r3,hdr,pd);
    return;
  }
  __imp__sub_82114628(ctx,base);
}
extern "C" void __imp__sub_821CE400(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821CE400){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  // RT_MODECMD="idx:val" — post a real mode command (rec[idx]+68 |= val) once the
  // phase-3 park is established. A90's scan masks rec+68 & 0x9 (low bits 1/8), so the
  // session-9 ARMREC value 2 was masked out by design. Validates the entire consumer
  // chain: A90 index -> CBFF0 gate pass -> CBF58 (bit writer) -> 6860 stepper -> screens.
  // RT_MODECMD="idx:val[:period]" — post rec[idx]+68|=val once at frame 900, or (with
  // period) every `period` frames after 900, to drive SUCCESSIVE screen transitions.
  { static const char* mc = std::getenv("RT_MODECMD");
    // extended syntax: idx:val[:period[:start]] — start defaults to 900
    unsigned idx=0; unsigned val=1; unsigned period=0; unsigned start=900;
    if(mc) std::sscanf(mc,"%u:%x:%u:%u",&idx,&val,&period,&start);
    if(mc && i>=(long)start){
      bool fire = (i==(long)start) || (period && ((i-start)%period)==0);
      if(fire){
        uint32_t G2=PPC_LOAD_U32(0x821F8588u), m=G2?PPC_LOAD_U32(G2+76):0, T=m?PPC_LOAD_U32(m+80):0;
        if(T && idx<5){ uint32_t rec=T+idx*132; uint32_t old=PPC_LOAD_U32(rec+68);
          PPC_STORE_U32(rec+68, old|val);
          std::fprintf(stderr,"[modecmd] POST rec[%u]+68 0x%X -> 0x%X (@CE400#%ld)\n",idx,old,old|val,i);
          // RT_FSMRESET: the native transition releases the scene-FSM's resources; our command-post
          // path skips that, leaving the tracked handle *(0x884D66B4) STALE (cycle-1's still-registered
          // entry polls loaded=1 -> state-1 takes the already-loaded branch -> E38 can't advance from 1
          // -> permanent wedge). Clear the tracked handle so state-1 re-requests fresh (what a real
          // release would leave behind).
          if(std::getenv("RT_FSMRESET")){
            uint32_t oldh=PPC_LOAD_U32(0x884D66B4u);
            PPC_STORE_U32(0x884D66B4u, 0);
            std::fprintf(stderr,"[modecmd] RT_FSMRESET: cleared FSM tracked handle 0x884D66B4 (was 0x%X)\n",oldh);
          } }
      }
    } }
  // RT_SUBMITCMD (LEG-17 np8/hang finding): after the in-game menu submit (d76 walks to 8) the
  // scene FSM enters state 2 (mode-reload) and the GAME MAIN FREEZES in the frame-handshake wait
  // while msg=5 keeps flowing — the msg-5 handler early-outs because the submit tore down the
  // session; the game waits for the SHELL to re-drive the GameEntry mode init (msgs 6,7,1,2,8,9,
  // 20 — the "init ran again" the old RT_MODECMD flow produced). In merged the menu submit never
  // reaches the shell's transition item (parked at CBFF0 wanting a command). Post the shell
  // advance command rec[0]+68|=0x2 ONCE per state-2 entry (CE400 runs on the shell pump thread,
  // which keeps ticking after the game-main freeze — the natplay-block version never fired).
  { static const char* sc = std::getenv("RT_SUBMITCMD");
    if(sc){
      static int armed=0, posted=0, totalPosted=0; static long lastPost=-999999;
      uint32_t fsm=PPC_LOAD_U32(0x884D66A8u); uint32_t d=PPC_LOAD_U16(0x884D678Cu);
      if(fsm==5 && d>=1){ armed=1; posted=0; }  // arm + fresh post budget per menu cycle
      else if(fsm==2 && d>=5 && armed && posted<60 && i-lastPost>=100){
        // np10 lesson: a single post is NOT consumed — the shell item is parked at statefn
        // 0x821CBBD0 (post-CBFF0), which np3 showed advances only after ~3 repeated pulses.
        // Post every 100 CE400 ticks while the game sits in fsm=2 (cap 60).
        uint32_t G2=PPC_LOAD_U32(0x821F8588u), m=G2?PPC_LOAD_U32(G2+76):0, T=m?PPC_LOAD_U32(m+80):0;
        if(T){ uint32_t old=PPC_LOAD_U32(T+68);
          PPC_STORE_U32(T+68, old|0x2u); lastPost=i; ++posted;
          std::fprintf(stderr,"[submitcmd] CE400#%ld fsm=2 d76=%u post-submit: rec[0]+68 0x%X->0x%X (post #%d/total %d)\n",
            i,d,old,old|0x2u,posted,++totalPosted);
          if(posted==1 && std::getenv("RT_FSMRESET")){
            uint32_t oldh=PPC_LOAD_U32(0x884D66B4u);
            PPC_STORE_U32(0x884D66B4u, 0);
            std::fprintf(stderr,"[submitcmd] cleared FSM tracked handle (was 0x%X)\n",oldh); } }
      }
    } }
  // [cmdedge] catch the NATIVE title-advance command poster: edge-log any rec[0..4]+68
  // becoming nonzero (the timed title auto-advance). Cheap per-frame poll.
  { uint32_t G3=PPC_LOAD_U32(0x821F8588u), m3=G3?PPC_LOAD_U32(G3+76):0, T3=m3?PPC_LOAD_U32(m3+80):0;
    if(T3){ static uint32_t prev[5]={0,0,0,0,0};
      for(int k=0;k<5;k++){ uint32_t v=PPC_LOAD_U32(T3+k*132+68);
        if(v!=prev[k]){ std::fprintf(stderr,"[cmdedge] rec[%d]+68 0x%X -> 0x%X @CE400#%ld\n",k,prev[k],v,i); prev[k]=v; } } } }
  // [itemsm] track the pending title item's state fn (o92+16 -> +72) — progresses or loops?
  // 2026-07-12: ALSO log when the item POINTER itself changes (even if its statefn happens
  // to read the same value at the instant we sample) -- the original guard only compared
  // statefn, so a new pending item whose first-observed statefn matched the previous item's
  // last statefn would be silently missed (suspected @cur76=5, item 0x44B930 -> 0x20CBDE0).
  // On a pointer change, dump the first 12 words so we can identify what asset the stuck
  // item corresponds to (cross-ref against [ldreq]/[nres] resource names near the same tick).
  { uint32_t o92=PPC_LOAD_U32(ctx.r3.u32+92), item=o92?PPC_LOAD_U32(o92+16):0;
    static uint32_t last=0, lastItem=0xFFFFFFFFu; uint32_t sf=item?PPC_LOAD_U32(item+72):0;
    if(sf!=last){ std::fprintf(stderr,"[itemsm] item=0x%X statefn 0x%X -> 0x%X @CE400#%ld\n",item,last,sf,i); last=sf; }
    if(item!=lastItem){
      std::fprintf(stderr,"[itemsm] ITEM-PTR CHANGE 0x%X -> 0x%X @CE400#%ld\n",lastItem,item,i);
      if(item>=0x1000 && item<0xFFFF0000u){
        std::fprintf(stderr,"[itemsm]   dump @0x%X:",item);
        for(int k=0;k<12;k++) std::fprintf(stderr," %08X",PPC_LOAD_U32(item+4*k));
        std::fprintf(stderr," | +72(statefn)=%08X +76=%08X +80=%08X\n",
          PPC_LOAD_U32(item+72),PPC_LOAD_U32(item+76),PPC_LOAD_U32(item+80));
      }
      lastItem=item;
    }
  }
  if(i<=5||i%600==0){
    // decision inputs: G=*(0x821F8688): *(G+104)!=0 -> goto CDF30 (command-bit writer!);
    // else sub_82189740()!=0 -> CDE00; else *(*(this+92)+16)!=0 -> stay;
    // else +76!=+80 -> CE098 (build next phase); else stay.
    // G = *(0x821F8588) (mode-mgr root; earlier 0x821F8688 reads were a wrong-address bug)
    uint32_t t=ctx.r3.u32, G=PPC_LOAD_U32(0x821F8588u);
    uint32_t g104=G?PPC_LOAD_U32(G+104):0xEE, g100=G?PPC_LOAD_U32(G+100):0xEE;
    uint32_t mgr=G?PPC_LOAD_U32(G+76):0, tab=mgr?PPC_LOAD_U32(mgr+80):0;
    uint32_t o92=PPC_LOAD_U32(t+92), o92_16=o92?PPC_LOAD_U32(o92+16):0xEE;
    std::fprintf(stderr,"[bootsm] CE400#%ld this=0x%X G=0x%X G+104=0x%X G+100=0x%X mgr=0x%X tab=0x%X rec0+68=0x%X rec1+68=0x%X o92+16=0x%X cur76=%d want80=%d\n",
      i,t,G,g104,g100,mgr,tab,tab?PPC_LOAD_U32(tab+68):0,tab?PPC_LOAD_U32(tab+132+68):0,
      o92_16,(int)PPC_LOAD_U32(t+76),(int)PPC_LOAD_U32(t+80));
    if(o92_16 && o92_16!=0xEE && i==600){
      std::fprintf(stderr,"[bootsm] pending-node dump @0x%X:",o92_16);
      for(int k=0;k<12;k++) std::fprintf(stderr," %08X",PPC_LOAD_U32(o92_16+4*k));
      std::fprintf(stderr," | +72(statefn)=%08X +76=%08X +80=%08X\n",
        PPC_LOAD_U32(o92_16+72),PPC_LOAD_U32(o92_16+76),PPC_LOAD_U32(o92_16+80));
    }
  }
  __imp__sub_821CE400(ctx,base);
}
extern "C" void __imp__sub_821CDBE8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821CDBE8){
  std::fprintf(stderr,"[bootsm] CDBE8 this=0x%X\n",ctx.r3.u32);
  __imp__sub_821CDBE8(ctx,base);
}
extern "C" void __imp__sub_821CD490(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821CD490){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  uint32_t t=ctx.r3.u32, o=PPC_LOAD_U32(t+496);
  uint32_t g=o?PPC_LOAD_U8(o+112):0xEE;
  if(i<=6||i%600==0) std::fprintf(stderr,"[bootsm] GATE CD490#%ld this=0x%X obj496=0x%X gatebyte=0x%X\n",i,t,o,g);
  __imp__sub_821CD490(ctx,base);
}
extern "C" void __imp__sub_821CD378(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821CD378){
  std::fprintf(stderr,"[bootsm] *** MANIFEST WALKER CD378 ENTER this=0x%X\n",ctx.r3.u32);
  __imp__sub_821CD378(ctx,base);
  std::fprintf(stderr,"[bootsm] *** MANIFEST WALKER CD378 EXIT\n");
}
// ---- [gsel] 2026-07-12: game-select confirm PARK (the Windows "Now Loading" hang at
// cur76=5 want80=-1). Fable-5 static RE of the parked chain:
//   * pending boot item (vtable 0x82050518) statefn +72 parks at thunk 0x82063A58 ->
//     vtable+68 = sub_821BA090 (per-tick) -> vtable+32 = sub_821B7CC0(item, cmd=elem+28,
//     r5=*(item+168)); cmd==2 maps r11=4/5 -> loc_821B7DB8 = the MODE-CHANGE branch.
//   * 7DB8 gate: if storage-session obj=*(G+116) (G=*(0x821F8588)) exists AND obj+188==1,
//     it polls sub_821897C0 -> sub_82191A28(obj): that latches obj+180:=1 ONLY when
//     XamContentGetDeviceData(*(*(obj+100))) returns NONZERO (real XAM: a stale/closed
//     device id fails with 0x48F). Our stub ALWAYS returns 0 (success for any id) ->
//     the latch can never fire -> sub_821B7CC0 sets item+184:=0x820662C8 and returns
//     WITHOUT advancing the statefn -> infinite per-tick retry, want80 never posted.
//   * healthy runs (boot_win.log/boot_vk.log) advanced because obj+188 != 1 at confirm
//     time (gate bypassed) -> flaky timing, not a working setter.
// Probes (RT_TRACERES): call-rate + gate fields at 7CC0; +188 writers via sub_82191AA8.
// Unblock lever RT_DEVFREE=1: force sub_821897C0 -> 1, ONLY for the 7CC0 call site
// (lr==0x821B7DF0), reporting the storage-session release as complete.
extern "C" void __imp__sub_821B7CC0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821B7CC0){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  if(std::getenv("RT_TRACERES") && (i<=20 || i%600==0)){
    uint32_t G=PPC_LOAD_U32(0x821F8588u), o=G?PPC_LOAD_U32(G+116):0;
    uint32_t f172=o?PPC_LOAD_U32(o+172):0xEE, f176=o?PPC_LOAD_U32(o+176):0xEE;
    uint32_t f180=o?PPC_LOAD_U8(o+180):0xEE, f188=o?PPC_LOAD_U32(o+188):0xEE, f192=o?PPC_LOAD_U32(o+192):0xEE;
    uint32_t h100=o?PPC_LOAD_U32(o+100):0, dev=h100?PPC_LOAD_U32(h100):0xEE;
    std::fprintf(stderr,"[gsel] 7CC0#%ld item=0x%X cmd=%u r5=%u | G+116=0x%X +172=0x%X +176=0x%X +180=%u +188=0x%X +192=0x%X dev=0x%X\n",
      i,ctx.r3.u32,ctx.r4.u32,ctx.r5.u32,o,f172,f176,f180,f188,f192,dev);
  }
  // ---- [modestub] L2: VETO THE FOLD FOR A MODE THIS BUILD DOES NOT HOST --------------------
  // This IS the modeIdx fold (ATLAS_scene_system §8.6): r3 = the game-select task, r4 = titleIdx
  // (0..3, the item id the caller read out of elem+0x1C), r5 = sub (0 = ARCADE, 1 = XBOX 360,
  // the arcade_front panel's answer parked at this+0xA8).  The impl computes
  // modeIdx = titleIdx*2 + sub and, on the accept path, writes this+0xC4 = modeIdx,
  // *(this+0xBC) = modeIdx (= root+0x54), *(this+0xA4) = 6 (= root+0x50, phase 6 => the
  // GameDriverTask + XexLoadImage) and this+0x48 = LAB_82065A78 (CLOSING).
  // We refuse BEFORE any of that by reproducing the impl's own out-of-range branch
  // LAB_821B7DA8 byte-for-byte: it writes `*(this+0x48) = &LAB_82061D50` and NOTHING else.
  // 0x82061D50 is the vtable thunk `lwz r12,0(r3); lwz r11,0x30(r12); bctr` (asm_states_0727.txt)
  // = vt(0x82050518)+0x30 = FUN_821BA4D8 = the ACTIVE state, so the menu simply keeps taking
  // input.  Phase and modeIdx are left untouched => the root FSM never leaves phase 5.
  // NOTE this only bites the ARCADE/XBOX-360 sub-choice in practice: L1 has already made the
  // three foreign TITLE rows unconfirmable, so the fold is normally only reached for our own
  // title with the wrong `sub`.  It is still the catch-all if L1's item ids ever miss.
  if(rt_modestub()){
    uint32_t self = ctx.r3.u32, title = ctx.r4.u32, sub = ctx.r5.u32;
    if(self && title < 4u && sub < 2u){
      uint32_t mi = title*2u + sub;
      // L4/L5: the test is the MASK, not a single index.  On the two per-module exes the mask
      // has exactly one bit and this is byte-for-byte the old `mi != FUTARI_MODE_HOSTED`.  On
      // the COMBINED exe the mask is {0,1}, so modeIdx 0 AND 1 fall through to the impl — and
      // that fall-through IS the mode-swap trigger: the impl advances to phase 6, the guest's
      // own per-mode loader ctor builds "game:\media\Module\<its own name>.xex", and
      // merged_bridge.cpp's XexLoadImage resolves that name against the module registry and
      // swaps.  We never name the module here; the guest does.  (l4l5_combined_notes.md §3)
      if(!futari_mode_hosted(mi)){
        PPC_STORE_U32(self + 0x48, 0x82061D50u);   // == LAB_821B7DA8, verbatim
        static std::atomic<long> v{0}; long vn=v.fetch_add(1)+1;
        std::fprintf(stderr,"[modestub] L2 VETO#%ld 7CC0 menu=0x%X title=%u sub=%u -> modeIdx=%u; "
                            "this build hosts mask=0x%02X (live %s.xex) -> +0x48=0x82061D50 "
                            "(menu ACTIVE), no phase 6, no module load\n",
          vn,self,title,sub,mi,(unsigned)futari_hosted_mask(),futari_desc()->module_basename);
        return;                                    // do NOT run the impl
      }
    }
  }
  __imp__sub_821B7CC0(ctx,base);
}
// ---- [modestub] L1: GREY + VETO THE FOREIGN TITLE ROWS -------------------------------------
// FUN_821B80D0 = the game-select task ctor (vt 0x82050518, movie `menu_title_menu`, ctor args
// (mem, &root+0x50 /*phase*/, &root+0x54 /*modeIdx*/)), spawned by root FSM phase 5.  It builds
// the item vector (menu+0x84 data / +0x90 begin / +0x94 end, stride 0x24, key +0x1C = titleIdx,
// flag +0x20) and — when the DLC bit *(DAT_821F858C+0x38F0) & 1 is clear — greys the Black Label
// row itself with FUN_821ba280(this, 2, 1).  We reuse that exact call for every row this exe
// cannot serve.
// The payoff is entirely guest-side, in the ACTIVE state FUN_821BA4D8:
//     if ((FUN_821b9ec0(this,1) == 0) ||                                  // A not pressed …
//         ((*(uint*)(FUN_820652a8(this+0x84,cursor) + 0x20) & 1) != 0))   // …OR row DISABLED
//            { if (FUN_821b9ec0(this,2)) { …B/cancel… } }                 // only B still works
//     else   { (*vt+0x18)(this,cursor); this+0x48 = 0x82061D70; }         // A on an ENABLED row
// i.e. A on a disabled row is SWALLOWED — the cursor still moves, B still exits, and the fold
// FUN_821B7CC0 is never reached.  That is the whole beta1 requirement, implemented by the game.
// r3 in == the object (the recompiled prologue does `mr r28,r3` then `stw r31,188(r28)` =
// menu+0xBC = the modeIdx out-ptr), so we capture r3 BEFORE the impl and use it after.
// Item id == titleIdx (0 Ver 1.5 / 1 Arrange / 2 Black Label / 3 Ver 1.01) — corroborated three
// ways: the guest's own FUN_821ba280(this,2,1) for Black Label, FUN_821B7E78's `rec+0x1C == 2`
// test, and FUN_821B7CC0's r4 domain 0..3.  The 5th row (item_05) has a different id and is left
// alone.  FUN_821BA280 returns 1 on hit / 0 if the id is absent, which we log: under the
// `menu_title_menu_del1.01` layout (*(DAT_821F858C+0x38F0) & 2 == 0) the Ver 1.01 row does not
// exist at all and title 3 legitimately returns 0.
extern "C" void __imp__sub_821B80D0(PPCContext& __restrict, uint8_t*);
extern "C" void __imp__sub_821BA280(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821B80D0){
  uint32_t menu = ctx.r3.u32;              // capture before the impl clobbers volatiles
  __imp__sub_821B80D0(ctx,base);           // let the ctor build the item vector first
  if(!rt_modestub() || !menu) return;
  static std::atomic<long> b{0}; long bn=b.fetch_add(1)+1;
  for(uint32_t t=0; t<4u; ++t){
    // L4/L5: mask predicate.  Per-module exe -> identical to the old `t == FUTARI_TITLE_HOSTED`
    // (a one-bit mask makes exactly title 0 servable).  Combined exe -> also exactly title 0,
    // because both its bits live in row 0; rows 1..3 still grey.  The generalisation only
    // matters the day a sibling TITLE ships (palm/kiniro/hirow), and then it is already right.
    if(futari_title_hosted(t)) continue;
    PPCContext ic = ctx; ic.r3.u32 = menu; ic.r4.u64 = t; ic.r5.u64 = 1;
    __imp__sub_821BA280(ic, base);                     // item t: +0x20 = 1 (DISABLED)
    std::fprintf(stderr,"[modestub] L1 GREY#%ld menu=0x%X title row %u -> DISABLED (hit=%u) "
                        "[this build hosts modeIdx mask 0x%02X; live module = %s.xex]\n",
      bn,menu,t,ic.r3.u32,(unsigned)futari_hosted_mask(),
      futari_desc()->module_basename);
  }
}
extern "C" void __imp__sub_82191AA8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_82191AA8){
  if(std::getenv("RT_TRACERES")){
    static std::atomic<int> n{0}; int i=n.fetch_add(1)+1;
    if(i<=40) std::fprintf(stderr,"[gsel] AA8#%d obj=0x%X +188:=%u lr=0x%X\n",i,ctx.r3.u32,ctx.r4.u32,(uint32_t)ctx.lr);
  }
  __imp__sub_82191AA8(ctx,base);
}
extern "C" void __imp__sub_821897C0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821897C0){
  uint32_t from=(uint32_t)ctx.lr;
  __imp__sub_821897C0(ctx,base);
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  if(std::getenv("RT_TRACERES") && (i<=8 || i%600==0))
    std::fprintf(stderr,"[gsel] 897C0#%ld lr=0x%X -> %u\n",i,from,ctx.r3.u32);
  if(ctx.r3.u32==0 && from==0x821B7DF0u && std::getenv("RT_DEVFREE")){
    static std::atomic<int> f{0}; int k=f.fetch_add(1)+1;
    if(k<=6) std::fprintf(stderr,"[gsel] RT_DEVFREE: forcing 897C0 -> 1 at game-select confirm (#%d)\n",k);
    ctx.r3.u64=1;
  }
}
// [parse] sub_8217C238 = request-node resolve: doc=*(this+4), name str @this+8 (SSO),
// calls sub_82178778(doc, name, ...) whose fallback iterates doc's 44B records @doc+28/+32
// — each record+8 MUST hold a parsed node ("object" child assert = the contained fatal).
extern "C" void __imp__sub_8217C238(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_8217C238){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  if(i<=10){
    uint32_t t=ctx.r3.u32, doc=PPC_LOAD_U32(t+4);
    uint32_t cap=PPC_LOAD_U32(t+8+24), np=(cap>=16)?PPC_LOAD_U32(t+8+4):(t+8+4);
    uint32_t lo=doc?PPC_LOAD_U32(doc+28):0, hi=doc?PPC_LOAD_U32(doc+32):0;
    std::fprintf(stderr,"[parse] C238#%ld this=0x%X doc=0x%X name='%s' recs=[0x%X..0x%X]=%d",
      i,t,doc,(const char*)(base+np),lo,hi,(int)((hi-lo)/44));
    for(uint32_t r=lo;r<hi&&r<lo+4*44;r+=44) std::fprintf(stderr," n8=0x%X",PPC_LOAD_U32(r+8));
    std::fprintf(stderr,"\n");
  }
  __imp__sub_8217C238(ctx,base);
  if(i<=10) std::fprintf(stderr,"[parse] C238#%ld -> r3=0x%X\n",i,ctx.r3.u32);
}
// [lzxsm] the stream-request state machine that leads to LZX validation:
// sub_821C17D0 (alloc 136 + ctor sub_821933B0(node, src=*(this+112)+104, this+208/212/216))
// sub_821933B0 arms sub_82192570 (magic validator) into node+72; sub_82193508 arms 27C8.
// sub_82193938 = request pump/step (calls 82193508). Which of these ever run?
#define ENTRY_LOG(FN,TAG) \
  extern "C" void __imp__##FN(PPCContext& __restrict, uint8_t*); \
  PPC_FUNC(FN){ static std::atomic<long> n{0}; long i=n.fetch_add(1)+1; \
    if(i<=8||i%2000==0) std::fprintf(stderr,"[lzxsm] " TAG "#%ld lr=0x%X r3=0x%X r4=0x%X\n", \
      i,(uint32_t)ctx.lr,ctx.r3.u32,ctx.r4.u32); \
    __imp__##FN(ctx,base); }
ENTRY_LOG(sub_821C17D0,"C17D0")
ENTRY_LOG(sub_821933B0,"33B0")
ENTRY_LOG(sub_82193508,"3508")
// sub_82193938 = mgr state "pump done-list": bails unless *(this+144)!=0 AND head
// req *(node+8) has +12 (completion status) != 0; then closes handle (+0 via
// sub_82088D00), and if byte +68 (needs-parse, walker r7) starts parse sub_82193508.
extern "C" void __imp__sub_82193938(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_82193938){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  if(i<=6||i%600==0){
    uint32_t t=ctx.r3.u32, f140=PPC_LOAD_U32(t+140), f144=PPC_LOAD_U32(t+144);
    uint32_t node=f140?PPC_LOAD_U32(f140):0, req=node?PPC_LOAD_U32(node+8):0;
    std::fprintf(stderr,"[lzxsm] 3938#%ld mgr=0x%X +140=0x%X +144=0x%X req=0x%X",i,t,f140,f144,req);
    if(req) std::fprintf(stderr," h=0x%X st12=0x%X f68=%u st16=%u",
      PPC_LOAD_U32(req),PPC_LOAD_U32(req+12),PPC_LOAD_U8(req+68),PPC_LOAD_U32(req+16));
    std::fprintf(stderr,"\n");
  }
  __imp__sub_82193938(ctx,base);
}
// [iosvc] shell I/O service layer (0x82089xxx; singleton *(0x821E13B0); 0x50000018 evt)
ENTRY_LOG(sub_820891F8,"iosvc1F8")
ENTRY_LOG(sub_82089528,"iosvc528")
ENTRY_LOG(sub_82089890,"iosvc890")
// [dfout] DF8 early-out forensics: sub_820893F0(handle,0) -> node+8 (async read ctx) and
// sub_8207A030 -> node+4 (stream buffer alloc). Either returning 0 makes sub_82194DF8 bail
// (cleanup+close+free, return 1) between its OPEN and its QUERYINFO — the post-boot
// "requests never serviced" signature. Log entry+RETURN, unthrottled for 3F0 and for A030
// calls from the DF8 site (lr=0x82194F00).
extern "C" void __imp__sub_820893F0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820893F0){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  uint32_t r3=ctx.r3.u32,r4=ctx.r4.u32,lr=(uint32_t)ctx.lr;
  __imp__sub_820893F0(ctx,base);
  if(i<=60||i%500==0) std::fprintf(stderr,"[dfout] 3F0#%ld lr=0x%X h=0x%X r4=0x%X -> 0x%X\n",i,lr,r3,r4,ctx.r3.u32);
}
extern "C" void __imp__sub_8207A030(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_8207A030){
  uint32_t r3=ctx.r3.u32,r4=ctx.r4.u32,lr=(uint32_t)ctx.lr;
  bool df = (lr==0x82194F00u);
  __imp__sub_8207A030(ctx,base);
  if(df){ static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    if(i<=60) std::fprintf(stderr,"[dfout] A030#%ld(DF8) r3=0x%X r4=0x%X -> 0x%X\n",i,r3,r4,ctx.r3.u32); }
}
// [dfout] file worker per-wake step sub_82192218 — if its count freezes post-boot, the worker
// never wakes for game-phase requests (work-event 0x50000014 signal lost or queue mismatch).
// (DF8 returns already logged by the existing [ldreq] wrapper.)
extern "C" void __imp__sub_82192218(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_82192218){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  if(i<=20||i%200==0) std::fprintf(stderr,"[dfout] worker-2218 wake#%ld r3=0x%X\n",i,ctx.r3.u32);
  __imp__sub_82192218(ctx,base);
}
// (state-1 busy-poll tracing uses the existing RT_TRACERES wrappers on sub_881526C0/52B00.)
// [lzx] the two shell fns that validate the .lzx container magic 0x0FF512EE
// (sub_82192570 / sub_821927C8, ppc_recomp.31) — do they run, on what, result?
extern "C" void __imp__sub_82192570(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_82192570){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  uint32_t r3=ctx.r3.u32,r4=ctx.r4.u32,r5=ctx.r5.u32;
  __imp__sub_82192570(ctx,base);
  if(i<=100) std::fprintf(stderr,"[lzx] 2570#%ld r3=0x%X r4=0x%X r5=0x%X -> 0x%X\n",i,r3,r4,r5,ctx.r3.u32);
}
extern "C" void __imp__sub_821927C8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821927C8){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  uint32_t r3=ctx.r3.u32,r4=ctx.r4.u32,r5=ctx.r5.u32;
  __imp__sub_821927C8(ctx,base);
  if(i<=100) std::fprintf(stderr,"[lzx] 27C8#%ld r3=0x%X r4=0x%X r5=0x%X -> 0x%X\n",i,r3,r4,r5,ctx.r3.u32);
}
// [modecmd] sub_821902B0 = the mode-command POST API (tail: rec+68 := r4). If it never
// fires, nothing requests the logo->menu transition. [modeq] sub_82190A90 = command query
// (scan 5 records' +68, return index or -1) — CBFF0's park gate.
extern "C" void __imp__sub_821902B0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821902B0){
  std::fprintf(stderr,"[modecmd] 902B0 lr=0x%X r3=0x%X r4(cmd)=0x%X r5=0x%X\n",
    (uint32_t)ctx.lr,ctx.r3.u32,ctx.r4.u32,ctx.r5.u32);
  __imp__sub_821902B0(ctx,base);
}
extern "C" void __imp__sub_82190A90(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_82190A90){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  __imp__sub_82190A90(ctx,base);
  static std::atomic<uint32_t> last{0xDEAD};
  uint32_t r=ctx.r3.u32;
  if(i<=3 || r!=last.exchange(r)) std::fprintf(stderr,"[modeq] A90#%ld -> %d (lr=0x%X)\n",i,(int)r,(uint32_t)ctx.lr);
}
// [snd] sub_8216FCF0 = state-3 slot processor (sound-player ctor, vtable 0x82051698,
// 92B alloc). Log the constructed object to correlate with the o92+16 pending item
// that parks the boot-phase sequencer at phase 3->4.
extern "C" void __imp__sub_8216FCF0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_8216FCF0){
  uint32_t t=ctx.r3.u32, doc=ctx.r4.u32;
  __imp__sub_8216FCF0(ctx,base);
  std::fprintf(stderr,"[snd] FCF0 ctor this=0x%X doc=0x%X -> r3=0x%X\n",t,doc,ctx.r3.u32);
}
// [slots] sub_821CD270 = post-walker slot processor: 8 slots at this+120+52*i,
// fields (from disasm): state=*(base-12), ready=byte *(base-8), data=*(base-4).
extern "C" void __imp__sub_821CD270(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821CD270){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  if(i<=6 || i%600==0){
    uint32_t t=ctx.r3.u32;
    std::fprintf(stderr,"[slots] CD270#%ld this=0x%X:",i,t);
    for(int k=0;k<8;k++){ uint32_t b=t+120+52*k;
      std::fprintf(stderr," [%d st=%u rdy=%u d=0x%X]",k,PPC_LOAD_U32(b-12),PPC_LOAD_U8(b-8),PPC_LOAD_U32(b-4)); }
    std::fprintf(stderr,"\n");
  }
  if(rt_d1probe()){ g_p1_cd270.fetch_add(1); p1_snapshot(base,"cd270"); }
  __imp__sub_821CD270(ctx,base);
}
// [d1a] P1 wrappers: dismiss-gate state ce4b8 (waits 0x1ec & sound-ready, then fires
// FUN_821ccc48(ind,0)) and the CRscIndicator visual pump cd120 (r3=ind; per-frame anchor
// while the loading box is alive). See RT_D1PROBE block above for the discriminator table.
extern "C" void __imp__sub_821CE4B8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821CE4B8){
  if(rt_d1probe()){ g_p1_ce4b8.fetch_add(1); p1_snapshot(base,"ce4b8"); }
  __imp__sub_821CE4B8(ctx,base);
  if(rt_d1probe()) p1_snapshot(base,"ce4b8+");
}
extern "C" void __imp__sub_821CD120(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821CD120){
  if(rt_d1probe()){
    long c=g_p1_cd120.fetch_add(1)+1;
    static std::atomic<int> once{0};
    if(!once.exchange(1)){
      uint32_t ind=ctx.r3.u32; uint32_t h=ind?PPC_LOAD_U32(ind+0x5Cu):0; uint32_t hctx=h?PPC_LOAD_U32(h+0x10u):0;
      std::fprintf(stderr,"[d1a] IDENTITY cd120 ind=0x%X handle(+5c)=0x%X handle+0x10=0x%X (expect loading-movie ctx ~0x375250)\n",ind,h,hctx);
    }
    p1_snapshot(base,"cd120");
    if(c<=5 || c%180==0){
      uint32_t crsc=PPC_LOAD_U32(0x821F856Cu);
      uint32_t f=crsc?PPC_LOAD_U8(crsc+0x1ECu):0xEE;
      uint32_t sb=PPC_LOAD_U32(0x821F8588u); uint32_t so=sb?PPC_LOAD_U32(sb+0x54u):0;
      uint32_t sr=so?PPC_LOAD_U32(so+0x5Cu):0;
      uint32_t ind=ctx.r3.u32; uint32_t i71=ind?PPC_LOAD_U8(ind+0x71u):0xEE;
      uint32_t a78r=ind?PPC_LOAD_U32(ind+0x78u):0; float a78; std::memcpy(&a78,&a78r,4);
      std::fprintf(stderr,"[d1a] HB cd120#%ld 0x1ec=%u snd_ready=%u ind+71=%u ind+78=%.3f | hits ce4b8=%ld cd270=%ld cd120=%ld\n",
        c,f,sr,i71,a78,g_p1_ce4b8.load(),g_p1_cd270.load(),c);
    }
  }
  __imp__sub_821CD120(ctx,base);
}
// [ldreq] resource-load request (walker calls this 8x). r4 = guest std::string
// {buf/inline @+4, size @+20?, cap @+24: cap>=16 -> heap ptr at +4}. Resolve step
// inside = sub_821936E8(name,3) -> -1 = FAIL (distinct bail path via sub_8210E878).
static const char* rt_gstr(uint8_t* base, uint32_t s){
  if(!s) return "(null)";
  uint32_t cap=PPC_LOAD_U32(s+24);
  uint32_t p=(cap>=16)?PPC_LOAD_U32(s+4):(s+4);
  return (const char*)(base+p);
}
extern "C" void __imp__sub_82194DF8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_82194DF8){
  uint32_t mgr=ctx.r3.u32, s=ctx.r4.u32;
  std::fprintf(stderr,"[ldreq] DF8 mgr=0x%X name='%s' r5=0x%X r7=%u r9=0x%X\n",
    mgr, rt_gstr(base,s), ctx.r5.u32, ctx.r7.u32, ctx.r9.u32);
  __imp__sub_82194DF8(ctx,base);
  std::fprintf(stderr,"[ldreq] DF8 -> r3=0x%X\n",ctx.r3.u32);
}
// [wpgate] candidate top-menu wallpaper-manager object (DAT_821f8574 family):
// ctor sub_821CB4F8, per-frame driver sub_821CB8E0 (checks DAT_821f8574!=0),
// pump sub_82182BD0 (installs loaded texture via SetTexture 0x384080 once
// field+0x28/[10] is nonzero), loader sub_82182960 (formats name from a
// number @ param_2 and issues the DF8 load — the wp01.bin request).
extern "C" void __imp__sub_821CB4F8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821CB4F8){
  std::fprintf(stderr,"[wpgate] CTOR sub_821CB4F8 called (wallpaper-mgr object being constructed)\n");
  __imp__sub_821CB4F8(ctx,base);
  uint32_t g8574=PPC_LOAD_U32(0x821F8574u);
  std::fprintf(stderr,"[wpgate] CTOR -> r3=0x%X (this ptr) DAT_821F8574=0x%X (post-ctor)\n",ctx.r3.u32,g8574);
}
// [wpgate] sub_82181EC8: per the real recompiled machine code (ppc_recomp.29.cpp) this
// unconditionally calls sub_82181C60 then returns its own r3 param unchanged -- there is
// NO call to sub_820BE150 anywhere in this function. Confirm live: r3 in should equal r3 out.
extern "C" void __imp__sub_82181EC8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_82181EC8){
  uint32_t in=ctx.r3.u32;
  std::fprintf(stderr,"[wpgate] sub_82181EC8 IN this=0x%X\n",in);
  __imp__sub_82181EC8(ctx,base);
  std::fprintf(stderr,"[wpgate] sub_82181EC8 OUT r3=0x%X%s\n",ctx.r3.u32,(ctx.r3.u32!=in)?"  <<< CHANGED":"");
}
extern "C" void __imp__sub_821CB8E0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821CB8E0){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  uint32_t g8574=PPC_LOAD_U32(0x821F8574u), g8578=PPC_LOAD_U32(0x821F8578u);
  if(i<=20||i%300==0) std::fprintf(stderr,"[wpgate] CB8E0#%ld DAT_821f8574=0x%X DAT_821f8578=0x%X\n",i,g8574,g8578);
  __imp__sub_821CB8E0(ctx,base);
}
extern "C" void __imp__sub_82182BD0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_82182BD0){
  uint32_t p=ctx.r3.u32;
  uint32_t f9=p?PPC_LOAD_U32(p+0x24):0, f10=p?PPC_LOAD_U32(p+0x28):0;
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  if(f9||f10||i<=5) std::fprintf(stderr,"[wpgate] BD0#%ld this=0x%X [9]=0x%X [10]=0x%X\n",i,p,f9,f10);
  __imp__sub_82182BD0(ctx,base);
}
extern "C" void __imp__sub_82182960(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_82182960){
  std::fprintf(stderr,"[wpgate] LOAD sub_82182960 this=0x%X number(param_2)=0x%X (%d)\n",
    ctx.r3.u32, ctx.r4.u32, (int)ctx.r4.u32);
  __imp__sub_82182960(ctx,base);
}
extern "C" void __imp__sub_821936E8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821936E8){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  uint32_t s=ctx.r3.u32, m=ctx.r4.u32;
  char nm[64]; std::snprintf(nm,sizeof nm,"%s",rt_gstr(base,s));
  __imp__sub_821936E8(ctx,base);
  if(i<=40||i%500==0) std::fprintf(stderr,"[nres] 36E8#%ld name='%s' mode=%u -> 0x%X\n",i,nm,m,ctx.r3.u32);
}

// ---- (2) idle-loop injection: load+drive reco_normal once, then run the real loop.
// NOTE: this MUST have C++ linkage (NOT extern "C") to override the recompiler's weak
// `sub_821706E8` (which the func-mapping table references by its C++-mangled name).
// Only __imp__sub_821706E8 is extern "C"; sub_X (the weak alias) is C++-mangled. ----
PPC_FUNC(sub_821706E8){
  static std::atomic<int> once{0};
  int exp=0;
  if(std::getenv("RT_LOADGAME") && once.compare_exchange_strong(exp,1)){
    uint32_t modectx = rt_alloc(512,16);
    std::memset(base+modectx,0,512);
    std::fprintf(stderr,"\n[loadgame] shell booted; injecting via mode-select dispatcher sub_821C3B90. modectx=0x%08X\n",modectx);
    // Mode selector: value 8 routes the dispatcher's default branch to reco_normal.
    // RT_MODEIDX overrides (modeIdx -> module map in NOTE_other_modes.md §2); a non-default
    // value now fails loudly at XexLoadImage unless that module is actually hosted.
    uint32_t modeidx = 8;
    if(const char* mi = std::getenv("RT_MODEIDX")) modeidx = (uint32_t)std::atoi(mi);
    std::fprintf(stderr,"[loadgame] modeIdx=%u%s\n",modeidx,
      std::getenv("RT_MODEIDX") ? " (RT_MODEIDX override)" : " (default -> reco_normal)");
    PPC_STORE_U32(modectx+104, modeidx);
    uint32_t singleton_pre = PPC_LOAD_U32(SINGLETON_ADDR);
    std::fprintf(stderr,"[loadgame] singleton *(0x%08X)=%x\n",SINGLETON_ADDR,singleton_pre);
    // Shell global at 0x821F857C is still 0 unless the shell's service-singleton ctor
    // sub_821CB248 has run: with (r3=0,r4=0) it RtlInitializeCriticalSections(0x821F8210),
    // pool-allocs+constructs a 632-byte singleton, stores it here, and spawns the service
    // thread (ExCreateThread) that pumps a game-registered callback. The driver later reads
    // *(0x821F857C) into GameEntry msg-1 struct+28 — run this BEFORE the mode dispatcher.
    uint32_t cb248_pre = PPC_LOAD_U32(CB248_SINGLETON);
    std::fprintf(stderr,"[loadgame] pre-CB248 *(0x%08X)=%x\n",CB248_SINGLETON,cb248_pre);
    rt_heapdump(base, "pre-CB248");
    { PPCContext ic=ctx; ic.r3.u32=0; ic.r4.u32=0; rt_indirect_call(ic,base,CB248_INIT); }
    rt_heapdump(base, "post-CB248");
    uint32_t cb248_post = PPC_LOAD_U32(CB248_SINGLETON);
    std::fprintf(stderr,"[loadgame] post-CB248 *(0x%08X)=%x\n",CB248_SINGLETON,cb248_post);
    if(!cb248_post){
      std::fprintf(stderr,"[loadgame] WARNING: post-CB248 singleton *(0x%08X) is still 0 — continuing anyway\n",CB248_SINGLETON);
    }
    rt_heapdump(base, "pre-3B90");
    { PPCContext ic=ctx; ic.r3.u32=modectx; rt_indirect_call(ic,base,MODE_DISPATCH); }
    rt_heapdump(base, "post-3B90");
    uint32_t p104=PPC_LOAD_U32(modectx+104);
    uint32_t p184=PPC_LOAD_U32(modectx+184);
    uint32_t p248=PPC_LOAD_U32(modectx+248);
    uint32_t p252=PPC_LOAD_U32(modectx+252);
    uint32_t p76 =PPC_LOAD_U32(modectx+76);
    uint32_t p80 =PPC_LOAD_U32(modectx+80);
    std::fprintf(stderr,"[loadgame] post-3B90 modectx: +104=%x +184=%x +248=%x +252=%x +76=%x +80=%x\n",
      p104,p184,p248,p252,p76,p80);
    // The parent (mode-select) object only holds a pointer to the dispatcher's internally
    // pool-allocated REAL modectx (256B) at +184. GameEntry/hmodule live in THAT inner
    // object at +248/+252, not in the parent.
    uint32_t inner = PPC_LOAD_U32(modectx+184);
    std::fprintf(stderr,"[loadgame] inner modectx=0x%08X\n",inner);
    uint32_t inner_entry=0;
    if(inner){
      uint32_t i0   = PPC_LOAD_U32(inner+0);
      uint32_t i104 = PPC_LOAD_U32(inner+104);
      uint32_t i164 = PPC_LOAD_U32(inner+164);
      uint32_t i180 = PPC_LOAD_U32(inner+180);
      uint32_t i248 = PPC_LOAD_U32(inner+248);
      uint32_t i252 = PPC_LOAD_U32(inner+252);
      std::fprintf(stderr,"[loadgame] inner: +0=%x +104=%x +164=%x +180=%x +248=%x +252=%x\n",
        i0,i104,i164,i180,i248,i252);
      inner_entry=i252;
    }
    if(std::getenv("RT_HUNT")){
      // Brute-force factory hunt: call candidate vtable method N with the right `this`, watch
      // S+16/+0x30/+0x50. RT_HUNT="E<n>" -> engine-root *S vtable slot n (this=*S);
      // "I<n>" -> inner modectx vtable slot n (this=inner); "S<n>" -> singleton S vtable slot n.
      const char* h=std::getenv("RT_HUNT"); char kind=h[0]; int slot=std::atoi(h+1);
      uint32_t S=PPC_LOAD_U32(0x821F857Cu);
      uint32_t sS=S?PPC_LOAD_U32(S):0;               // engine root (*S)
      uint32_t thisobj = (kind=='E')? sS : (kind=='S')? S : inner;
      uint32_t vt = thisobj?PPC_LOAD_U32(thisobj):0;
      uint32_t method = vt?PPC_LOAD_U32(vt+slot*4):0;
      uint32_t pre16=S?PPC_LOAD_U32(S+16):0, pre30=S?PPC_LOAD_U32(S+0x30):0, pre50=S?PPC_LOAD_U32(S+0x50):0;
      std::fprintf(stderr,"[hunt] %s slot=%d this=0x%X vt=0x%X method=0x%X pre(S+16/30/50)=%X/%X/%X\n",
        h,slot,thisobj,vt,method,pre16,pre30,pre50);
      if(method>=0x82000000u && method<0x88000000u){
        PPCContext ic=ctx; ic.r3.u32=thisobj; ic.r4.u32=0; ic.r5.u32=0; ic.r6.u32=0; ic.r7.u32=0;
        rt_indirect_call(ic,base,method);
        uint32_t s16=S?PPC_LOAD_U32(S+16):0, s30=S?PPC_LOAD_U32(S+0x30):0, s50=S?PPC_LOAD_U32(S+0x50):0;
        bool flipped=(s16&&!pre16)||(s30&&!pre30)||(s50&&!pre50);
        std::fprintf(stderr,"[hunt] AFTER %s: S+16/30/50=%X/%X/%X %s\n",h,s16,s30,s50,
          flipped?"*** FACTORY-CANDIDATE: A HANDLER SLOT FLIPPED ***":"(no change)");
      } else std::fprintf(stderr,"[hunt] method 0x%X out of shell range — skip\n",method);
    } else if(inner && inner_entry){
      // [sing] TASK-11 disambiguation: the game's per-frame render (sub_88090360) dispatches
      // 157 resource registrations through 3 render-kind-handler objects at the GAME addrs
      // 0x885C5BB4/+0x20/+0x40, which are all NULL. GameEntry msg-1 (driver, below) copies
      // them from arg+20 = (S && *S) ? S+12 : 0, S=*(0x821F857C)=the CB248 singleton. Dump the
      // singleton region NOW (before the driver runs msg-1) to disambiguate: is *S zero (so
      // arg+20 resolves to 0 = driver builds it wrong) OR is S+12 non-null but pointing at
      // zeros (singleton's handler region never populated by any shell resource-init)?
      {
        uint32_t S = PPC_LOAD_U32(CB248_SINGLETON);
        std::fprintf(stderr,"[sing] pre-driver S=*(0x821F857C)=0x%X\n",S);
        if(S){
          uint32_t s0=PPC_LOAD_U32(S);
          std::fprintf(stderr,"[sing]   *S=0x%X ; arg+20 = (S&&*S)?S+12:0 = 0x%X\n", s0, s0? S+12 : 0);
          for(int row=0;row<4;++row){
            std::fprintf(stderr,"[sing]   S[+0x%02x]:",row*16);
            for(int col=0;col<4;++col) std::fprintf(stderr," %08x",PPC_LOAD_U32(S+row*16+col*4));
            std::fprintf(stderr,"\n");
          }
          // Also dump the *S sub-object (0x35A660) in case the real driver computes
          // arg+20 = *S+12 (inside the sub-object) rather than S+12.
          if(s0 && s0<0x80000000u){
            for(int row=0;row<4;++row){
              std::fprintf(stderr,"[sing]   *S[+0x%02x]:",row*16);
              for(int col=0;col<4;++col) std::fprintf(stderr," %08x",PPC_LOAD_U32(s0+row*16+col*4));
              std::fprintf(stderr,"\n");
            }
          }
          uint32_t h = s0? S+12 : 0;   // the region msg-1 copies 3 handler ptrs from
          if(h){
            std::fprintf(stderr,"[sing]   arg+20 target words:");
            for(int i=0;i<6;++i) std::fprintf(stderr," %08x",PPC_LOAD_U32(h+i*4));
            std::fprintf(stderr,"\n");
          }
        }
      }
      // ★ RT_MKHANDLERS (SDK-oracle fix): construct the 3 real render-kind handlers and install
      // them at the CB248 singleton S+0x10/0x30/0x50 (= the +4 field of the 3x 32B resource-kind
      // descriptors at S+0x0C that GameEntry msg-1 copies into the game). SDK ground truth: all 3
      // handlers are 272-byte objects whose ctor sub_820F0C20 sets 4 interface vtables
      // (+0=0x820148F0/+4=0x820147DC/+8=0x820148E8/+12=0x8201494C). The game's registration loop
      // sub_88090360 reads *(block+4)=handler and calls handler->vtable[0](handler,name)->id, using
      // ONLY block+4 — so installing real handlers here makes registration hit the REAL shell
      // resource-kind managers instead of null. Independent: uses xr-work's own shell ctor.
      if(std::getenv("RT_MKREAL")){
        // ★ Call the REAL create-handler = engine-root vtable[8] = sub_820E80C0(ctx=*S, a1,a2,flag,a4,
        // r8=&out). It does the full chain (crit-section + sub_820E6A10 container-slot + alloc 272B +
        // ctor sub_820F0C20 + init sub_820F10A0 + list-link) and stores the created handler into *(r8).
        // Retrieve via the out-pointer + install at S+0x10/0x30/0x50. Empirical: args=0 first.
        uint32_t S=PPC_LOAD_U32(CB248_SINGLETON);
        uint32_t eng=S?PPC_LOAD_U32(S):0;   // *S = the resource-kind-manager (its vtable[8]=sub_820E80C0)
        std::fprintf(stderr,"[mkreal] S=0x%X mgr(*S)=0x%X mgr.vtable=0x%X\n",S,eng,(eng&&eng<0xF0000000u)?PPC_LOAD_U32(eng):0);
        if(eng){
          for(int k=0;k<3;++k){
            uint32_t outp=rt_alloc(8,8); PPC_STORE_U32(outp,0);
            PPCContext ic=ctx; ic.r3.u32=eng; ic.r4.u32=0; ic.r5.u32=0; ic.r6.u32=0; ic.r7.u32=0; ic.r8.u32=outp;
            rt_indirect_call(ic,base,0x820E80C0u);
            uint32_t h=PPC_LOAD_U32(outp);
            std::fprintf(stderr,"[mkreal] create-handler#%d ret=0x%X -> h=0x%X (vt=0x%X)\n",k,ic.r3.u32,h,(h&&h<0xF0000000u)?PPC_LOAD_U32(h):0);
            if(h) PPC_STORE_U32(S+0x10+k*0x20, h);
          }
        }
      } else if(std::getenv("RT_MKHANDLERS")){
        uint32_t S=PPC_LOAD_U32(CB248_SINGLETON);
        if(S){
          uint32_t hs[3];
          for(int k=0;k<3;++k){
            uint32_t h=rt_alloc(272,16); std::memset(base+h,0,272);
            { PPCContext ic=ctx; ic.r3.u32=h; rt_indirect_call(ic,base,0x820F0C20u); }  // sets the 4 vtables
            // ACTIVATE — exactly what the real create-handler sub_820E80C0 does after the ctor:
            // (h+12)-as-interface -> vtable[0](h+12, 1). This initializes the handler's internal
            // state (the sub-objects vtable[18]/[19] of the register method sub_820EF0C0 read).
            // ⚠ HANGS on a bare handler (activate method busy-spins — needs the sub_820E6A10
            // container-slot state the real create-handler sub_820E80C0 sets up first). Gated OFF.
            if(std::getenv("RT_MKACT")){ uint32_t vt12=PPC_LOAD_U32(h+12); uint32_t m12=(vt12&&vt12<0xF0000000u)?PPC_LOAD_U32(vt12):0;
              if(m12){ PPCContext ic=ctx; ic.r3.u32=h+12; ic.r4.u32=1; rt_indirect_call(ic,base,m12);
                std::fprintf(stderr,"[mkh] activate handler%d: (h+12)->vt[0]=0x%X(h+12,1)\n",k,m12); } }
            hs[k]=h;
          }
          uint32_t sS=PPC_LOAD_U32(S);  // *(S) = the singleton's root sub-object (SDK: handler0+24)
          std::fprintf(stderr,"[mkh] register-method vtable[0]=*(0x820148F0)=0x%X ; *(S)=0x%X\n",PPC_LOAD_U32(0x820148F0u),sS);
          // RT_MKWIRE: replicate the SDK handler wiring — +24=parent chain (h0->*(S), h1->h0+0xC,
          // h2->h1+0xC), +16=next-sibling+0xC, +28=self+0xDC, +32=self+0x24 (an intrusive
          // tree/list the register method sub_820148F0[0] walks to insert resource kinds).
          if(std::getenv("RT_MKWIRE")){
            for(int k=0;k<3;++k){
              uint32_t h=hs[k];
              PPC_STORE_U32(h+16, (k<2)? (hs[k+1]+0x0C) : 0);
              PPC_STORE_U32(h+24, sS);   // container = *(S) = engine root (register method reads handler+24 as the resource container)
              PPC_STORE_U32(h+28, h+0xDC);
              PPC_STORE_U32(h+32, h+0x24);
            }
          }
          for(int k=0;k<3;++k){
            PPC_STORE_U32(S+0x10+k*0x20, hs[k]);
            std::fprintf(stderr,"[mkh] handler%d=0x%X vtable=0x%X -> S+0x%X\n",k,hs[k],PPC_LOAD_U32(hs[k]),0x10+k*0x20);
          }
        } else std::fprintf(stderr,"[mkh] S is null — cannot install handlers\n");
      }
      if(std::getenv("RT_DEFERDRIVER")){
        g_defer_inner = inner;
        std::fprintf(stderr,"[defer] driver HELD; will fire from the frame loop once S+0x10/0x30/0x50 populate (inner=0x%08X)\n",inner);
      } else {
      rt_heapdump(base, "pre-driver");
      { PPCContext ic=ctx; ic.r3.u32=inner; rt_indirect_call(ic,base,GAME_DRIVER); }
      rt_heapdump(base, "post-driver");
      std::fprintf(stderr,"[loadgame] after driver sub_821C30B8 (r3=inner): GameEntry init sequence sent. imports=%ld\n",g_import_calls.load());
      {
        uint32_t h0=PPC_LOAD_U32(0x885C5BB4u),h1=PPC_LOAD_U32(0x885C5BD4u),h2=PPC_LOAD_U32(0x885C5BF4u);
        std::fprintf(stderr,"[sing] post-driver GAME handlers h0=0x%X h1=0x%X h2=0x%X (want non-null)\n",h0,h1,h2);
      }
      // GATE 3: hand the fully-initialized inner modectx to the shell's per-frame tick path.
      // The VdSwap hook (shell/gen/rt.cpp) will now call sub_821C3278(inner) each present when
      // RT_GAMETICK is set, driving the game's per-frame update + unblocking the game main.
      g_game_tick_modectx = inner;
      std::fprintf(stderr,"[loadgame] g_game_tick_modectx=0x%08X (per-frame sub_821C3278 tick armed; enable with RT_GAMETICK=1)\n",inner);
      }
    } else if(inner){
      std::fprintf(stderr,"[loadgame] inner modectx+252 (GameEntry) is 0 — aborting drive. Dumping inner[+0..+0x3F] words:\n");
      for(int row=0; row<4; ++row){
        std::fprintf(stderr,"[loadgame] inner[+0x%02x]:",row*16*4);
        for(int col=0; col<16; ++col){
          int idx = row*16+col;
          uint32_t w = PPC_LOAD_U32(inner + idx*4);
          std::fprintf(stderr," %08x",w);
        }
        std::fprintf(stderr,"\n");
      }
    } else {
      std::fprintf(stderr,"[loadgame] dispatcher did NOT resolve inner modectx (parent+184==0) — aborting drive\n");
    }
    std::fprintf(stderr,"[loadgame] entering real shell idle/render loop with game active\n\n");
    // RT_MODEACTIVE: the mode-enter state machine (which runs the resource-kind factory) only
    // advances when the MODE is the actively-ticked loopobj. Our bypass leaves the idle menu
    // active (frame loop ticks it 10k+ times; r28.state stays 0, S+16 never flips). Swap the
    // loopobj passed to the real sub_821706E8 to the mode object so the frame loop ticks the
    // MODE, advancing its state machine -> resource factory -> S+12 handlers -> game draws.
    // =1 -> r28 (sub_8216AC18 mode-runner, vtable 0x82051764); =2 -> inner modectx (vtable 0x8204fc38).
    { const char* ma=std::getenv("RT_MODEACTIVE");
      if(ma && (g_r28.load()||inner)){
        uint32_t tgt = (std::atoi(ma)==2)? inner : g_r28.load();
        if(tgt){
          std::fprintf(stderr,"[loadgame] RT_MODEACTIVE=%s: swap active loopobj r3 0x%X -> 0x%X (its vtable=0x%X, +8=0x%X)\n",
            ma, ctx.r3.u32, tgt, PPC_LOAD_U32(tgt), PPC_LOAD_U32(tgt+8));
          ctx.r3.u32 = tgt;
        }
      }
    }
  }
  __imp__sub_821706E8(ctx,base);
}


// ============================================================================================
// ★ 2026-08-02 DESTROY-CHAIN TALLY (ghost-voice hunt, gated on RT_VOICECENSUS, default silent).
// The stop-slot tally proved the game issues stops 1:1 with plays (lr=0x880905D8 steal) yet
// stolen voices keep ringing (digital A/B: x6 in the guest mix vs the SDK). This instruments
// every hop of the decomp'd chain (ghidra_futari_decomp/destroy_chain.txt):
//   cue Destroy 0x820EC8F8 / cue Stop 0x820EC958 (vtable 0x82014688 +0xC/+0x4)
//   -> wave stop 0x820F80B0 (state 5, walks instance list +0x2C)
//   -> instance stop 0x820FA218 (mixer voice @+0x18)
//   -> mixer-voice stop 0x820F66C8 (state@+0x28, immediate kill via 0x820F5E80)
// The FIRST hop whose rate drops below the stop-slot rate is the fork; its guard names the
// culprit field. Wrappers are tally+passthrough only — byte-identical without the lever.
// (cue Stop 0x820EC958 and wave stop 0x820F80B0 already have hooks above — tallies merged there.)
extern "C" void __imp__sub_820EC8F8(PPCContext& __restrict, uint8_t*);
extern "C" void __imp__sub_820FA218(PPCContext& __restrict, uint8_t*);
extern "C" void __imp__sub_820F66C8(PPCContext& __restrict, uint8_t*);
extern "C" void __imp__sub_820F5E80(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820EC8F8){
  rt_dchain_tally(0,"cueDestroy",ctx);
  // One-shot identity walk (this-adjust thunks 0x8207C98x are pure identity, so decomp offsets
  // hold): cue+0x38=wave, wave+0x38=the sync/deferred-predicate object, vtable+0x90=the predicate
  // that gates synchronous vs queued stop processing. Name the class + the predicate fn.
  if(rt_dchain_on()){
    static std::atomic<long> once{0};
    uint32_t cue=ctx.r3.u32;
    if(once.load()<4 && cue && cue<0xF0000000u){
      uint32_t wave=PPC_LOAD_U32(cue+0x38u);
      uint32_t obj = (wave&&wave<0xF0000000u)?PPC_LOAD_U32(wave+0x38u):0;
      uint32_t vt  = (obj&&obj<0xF0000000u)?PPC_LOAD_U32(obj):0;
      uint32_t p90 = (vt&&vt<0xF0000000u)?PPC_LOAD_U32(vt+0x90u):0;
      uint32_t wstate=(wave&&wave<0xF0000000u)?PPC_LOAD_U32(wave+0x58u):0xDEAD;
      once.fetch_add(1);
      std::fprintf(stderr,"[dchain] ANATOMY cue=0x%X wave=0x%X state=%u obj38=0x%X vt=0x%X pred90=0x%X\n",
                   cue,wave,wstate,obj,vt,p90);
    }
  }
  __imp__sub_820EC8F8(ctx,base);
}
PPC_FUNC(sub_820FA218){ rt_dchain_tally(3,"instStop",ctx);   __imp__sub_820FA218(ctx,base); }
PPC_FUNC(sub_820F66C8){ rt_dchain_tally(4,"mixStop",ctx);    __imp__sub_820F66C8(ctx,base); }
PPC_FUNC(sub_820F5E80){ rt_dchain_tally(5,"mixKill",ctx);    __imp__sub_820F5E80(ctx,base); }

// ★ 2026-08-02 DESTROY-CHAIN round 2 (see the tally block above). Round-1 verdict: cueDestroy
// and the mixKill SWEEPER both fire at play-rate, but the sweeper reaps nothing because the
// whole Stop chain (cueStop/waveStop/instStop/mixStop) never runs. The stop is DEFERRED as an
// async command object (vtables 0x820158F8/0x82015F30/0x82015FD8, Execute at +8 =
// 0x82105760/0x82105E70) pushed via the engine container-slot claim sub_820E6A10. These three
// wrappers decide the remaining fork: enqueue refused (820E6A10 returns 0x8AC70012) vs enqueued
// but never executed (executors tally 0) vs executed against the wrong object.
extern "C" void __imp__sub_820E6A10(PPCContext& __restrict, uint8_t*);
extern "C" void __imp__sub_82105E70(PPCContext& __restrict, uint8_t*);
extern "C" void __imp__sub_82105760(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820E6A10){
  uint32_t r3in=ctx.r3.u32;
  __imp__sub_820E6A10(ctx,base);
  if(rt_dchain_on()){
    static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    if(i<=6 || (i%256)==0)
      std::fprintf(stderr,"[dchain] slotClaim #%ld this=0x%X -> ret=0x%X lr=0x%X\n",
                   i,r3in,(unsigned)ctx.r3.u32,(uint32_t)ctx.lr);
  }
}
PPC_FUNC(sub_82105E70){ rt_dchain_tally(3,"cmdExecE70",ctx); __imp__sub_82105E70(ctx,base); }
PPC_FUNC(sub_82105760){ rt_dchain_tally(1,"cmdExec760",ctx); __imp__sub_82105760(ctx,base); }

// ★ Destroy-chain round 3: sub_820F2990 = the per-tick walker over the active-wave list
// (+0xF4/+0xF8) that calls the async-stop consumer 0x820F9AD8 per node. Round 2 showed the
// consumer ran 4 times ALL SESSION vs 1536 queued stops. Fork: walker never called vs called
// with an empty list (= waves never REGISTER into this list in our port). Tally + depth.
extern "C" void __imp__sub_820F2990(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820F2990){
  if(rt_dchain_on()){
    static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    uint32_t self=ctx.r3.u32; int depth=0;
    if(self && self<0xF0000000u){
      uint32_t head=PPC_LOAD_U32(self+0xF8u), sent=self+0xF4u;
      while(head && head!=sent && depth<32){ depth++; head=PPC_LOAD_U32(head+4u); }
    }
    static std::atomic<long> nz{0};
    if(depth>0) nz.fetch_add(1);
    if(i<=4 || (i%2048)==0 || (depth>0 && nz.load()<=8))
      std::fprintf(stderr,"[dchain] walker #%ld this=0x%X depth=%d lr=0x%X\n",
                   i,self,depth,(uint32_t)ctx.lr);
    // Success-side anatomy: identify the registered node class (its vtable) so the ctor->insert
    // chain can be found from a class that DOES register (boot waves do; shot waves do not).
    if(depth>0 && nz.load()<=8){
      uint32_t node=PPC_LOAD_U32(self+0xF8u);
      uint32_t nvt =(node&&node<0xF0000000u)?PPC_LOAD_U32(node):0;
      std::fprintf(stderr,"[dchain] NODE 0x%X vt=0x%X vt0=0x%X\n",
                   node,nvt,(nvt&&nvt<0xF0000000u)?PPC_LOAD_U32(nvt):0);
    }
  }
  __imp__sub_820F2990(ctx,base);
}

// ★ Destroy-chain round 4: sub_82088C48 = the XACT POOL ALLOCATOR (real body per the 07-18
// audit; thunk_FUN_82088c48 in decomp). The wave service node (0x8C bytes, tag 0x2084801E,
// creator 0x820F4A40) registers a wave into its soundbank's per-tick update list — the list
// that is EMPTY for shot waves. If this allocator FAILS the creator returns E_OUTOFMEMORY and
// the wave plays WITHOUT a service node = audible but unstoppable = the ghost. Boot got 4-7
// nodes then none — exhausted-or-tiny-pool signature. Log failures + the node-tag allocs.
extern "C" void __imp__sub_82088C48(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_82088C48){
  uint32_t sz=ctx.r3.u32, tag=ctx.r4.u32;
  __imp__sub_82088C48(ctx,base);
  // ★ 2026-08-03 ROUND 9 — ZERO-FRESH-MEMORY HYPOTHESIS (the fix-candidate probe). Authored
  // data is correct in guest memory (round 8) and the mixer never ends one-shot voices; the
  // remaining divergence class is UNINITIALIZED STRUCT FIELDS: the SDK lineage serves
  // effectively-zeroed fresh memory while our pool slices are dirty, so any field XACT's ctors
  // do not explicitly set (e.g. a loop count in the play/submit params) reads zero there and
  // garbage here — and a garbage loop count loops a one-shot forever. RT_XALLOCZERO=0 reverts.
  {
    static bool zon = [](){ const char* e=std::getenv("RT_XALLOCZERO"); return e && e[0]==(char)49 && !e[1]; }();  // default OFF: A/B showed no change (refutation 9)
    uint32_t r=ctx.r3.u32;
    if(zon && r && r<0xF0000000u && sz && sz<0x100000u) std::memset(base+r,0,sz);
  }
  if(rt_dchain_on()){
    uint32_t ret=ctx.r3.u32;
    static std::atomic<long> n{0}, fails{0}, nodetag{0};
    long i=n.fetch_add(1)+1;
    bool fail = (ret==0);
    bool isnode = (tag==0x2084801Eu);
    if(fail) fails.fetch_add(1);
    if(isnode) nodetag.fetch_add(1);
    if(i<=8 || fail || (isnode && nodetag.load()<=12) || (i%4096)==0)
      std::fprintf(stderr,"[xalloc] #%ld size=0x%X tag=0x%X -> 0x%X%s (fails=%ld) lr=0x%X\n",
                   i,sz,tag,ret,fail?" FAIL":"",fails.load(),(uint32_t)ctx.lr);
  }
}

// Round-7 latency pairing helpers (used by the round-5 wrappers below; defined here so they
// precede first use). Node ptr -> create timestamp; take() returns ms delta or -1 if unpaired.
#include <unordered_map>
static std::mutex g_nlat_m;
static std::unordered_map<uint32_t,long long> g_nlat;
static long long rt_dchain_ms(){
  return std::chrono::duration_cast<std::chrono::milliseconds>(
           std::chrono::steady_clock::now().time_since_epoch()).count();
}
static void rt_dchain_note_create(uint32_t node){
  std::lock_guard<std::mutex> l(g_nlat_m);
  if(g_nlat.size()<4096) g_nlat[node]=rt_dchain_ms();
}
static long long rt_dchain_take_create(uint32_t node){
  std::lock_guard<std::mutex> l(g_nlat_m);
  auto it=g_nlat.find(node);
  if(it==g_nlat.end()) return -1;
  long long dt=rt_dchain_ms()-it->second; g_nlat.erase(it); return dt;
}

// ★ Destroy-chain round 5: node CREATE (0x820F4A40) vs suspected list REMOVE (0x820F9DB0).
// Allocator healthy (round 4: 73k allocs, node allocs succeed all demo) yet walker lists sit
// empty — so either nodes never INSERT, or they insert and get REMOVED within a tick
// (premature completion abandoning a still-playing voice). Rates + lr decide.
extern "C" void __imp__sub_820F4A40(PPCContext& __restrict, uint8_t*);
extern "C" void __imp__sub_820F9DB0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820F4A40){
  __imp__sub_820F4A40(ctx,base);
  if(rt_dchain_on()){
    // round 7b: r3 here is the HRESULT (post-call), NOT the node — the round-7 pairing keyed on
    // garbage (every remove dtms=-1). The stamp now lives in the nodeInit wrapper whose r3 IS
    // the node this-pointer.
    static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    if(i<=6 || (i%64)==0)
      std::fprintf(stderr,"[dchain] nodeCreate #%ld ret=0x%X lr=0x%X\n",
                   i,(unsigned)ctx.r3.u32,(uint32_t)ctx.lr);
  }
}
PPC_FUNC(sub_820F9DB0){
  if(rt_dchain_on()){
    long long dt = rt_dchain_take_create(ctx.r3.u32);   // -1 if unpaired
    static std::atomic<long> n{0}, lo{0}, hi{0}; long i=n.fetch_add(1)+1;
    if(dt>=0){ (dt<5 ? lo : hi).fetch_add(1); }
    if(i<=6 || (i%64)==0)
      std::fprintf(stderr,"[dchain] nodeRemove #%ld this=0x%X dtms=%lld (lo<5ms=%ld hi>=5ms=%ld) lr=0x%X\n",
                   i,(unsigned)ctx.r3.u32,dt,lo.load(),hi.load(),(uint32_t)ctx.lr);
  }
  __imp__sub_820F9DB0(ctx,base);
}

// ★ Destroy-chain round 6 — the node-init ARGUMENTS. FUN_821009e0(this, flags, LOOPCOUNT(byte,
// 0xFF=infinite), p4, p5, p6) steers its end-of-stream logic by the loop count: a shot grain
// arriving with loop=0 makes the service node complete after one iteration and self-remove
// (round 5: create==remove==1728, all via the completion path) while the mixer voice loops on
// = the ghost. Log the args per init; the shot class should show loop=0xFF if authored truth
// reaches the node, 0 if it is lost en route.
extern "C" void __imp__sub_821009E0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821009E0){
  if(rt_dchain_on()){
    rt_dchain_note_create(ctx.r3.u32);   // round 7b: node latency stamp (r3 = node this)
    static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    if(i<=10 || (i%64)==0)
      std::fprintf(stderr,"[dchain] nodeInit #%ld this=0x%X flags=0x%X loop=0x%X r6=0x%X r7=0x%X lr=0x%X\n",
                   i,(unsigned)ctx.r3.u32,(unsigned)ctx.r4.u32,(unsigned)ctx.r5.u32,
                   (unsigned)ctx.r6.u32,(unsigned)ctx.r7.u32,(uint32_t)ctx.lr);
  }
  __imp__sub_821009E0(ctx,base);
}

// ★ Destroy-chain round 7 (two discriminators, one drive):
// (1) NODE-REMOVAL LATENCY — rounds 5/6 proved create==remove with authored loop=0, but not
//     WHEN. Pair create/remove by node ptr with ms timestamps: ~75ms = grain-end (lifecycle
//     CORRECT, ghost is elsewhere); <5ms = premature completion stands.
// (2) THE SOFTWARE-MIXER POOL LANE (untouched until now): sub_820EBE38 = the pool voice-steal
//     (engine+0x58, priority steal — ATLAS_audio); sub_820F6A20 = the per-entry kill the
//     sweeper 0x820F5E80 invokes. If the ringing copies live in this pool, steal-rate vs
//     kill-rate exposes the leak directly.
extern "C" void __imp__sub_820EBE38(PPCContext& __restrict, uint8_t*);
extern "C" void __imp__sub_820F6A20(PPCContext& __restrict, uint8_t*);
// ★ Round 10 — WATCH A RINGING VOICE DIRECTLY. Capture one pool voice mid-demo (steal call
// #200+ = deep in the shot barrage) and hexdump its first 0x60 bytes once per second from the
// census. Field motion identifies the cursor/state offsets; a cursor that wraps past duration
// names the stuck branch; a cursor that never moves names a different one. Exported watch
// slot consumed by rt_voice_census (shell/gen/rt.cpp).
extern "C" uint32_t g_rt_watch_voice = 0;
PPC_FUNC(sub_820EBE38){
  if(rt_dchain_on()){
    static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    if(i<=6 || (i%64)==0)
      std::fprintf(stderr,"[dchain] poolSteal #%ld r3=0x%X r4=0x%X lr=0x%X\n",
                   i,(unsigned)ctx.r3.u32,(unsigned)ctx.r4.u32,(uint32_t)ctx.lr);
    __imp__sub_820EBE38(ctx,base);
    if(!g_rt_watch_voice && i>200 && ctx.r3.u32 && ctx.r3.u32<0xF0000000u){
      g_rt_watch_voice = ctx.r3.u32;
      std::fprintf(stderr,"[dchain] WATCH voice=0x%X (captured at steal #%ld)\n",g_rt_watch_voice,i);
    }
    return;
  }
  __imp__sub_820EBE38(ctx,base);
}
PPC_FUNC(sub_820F6A20){
  if(rt_dchain_on()){
    static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    if(i<=6 || (i%64)==0)
      std::fprintf(stderr,"[dchain] poolKill #%ld r3=0x%X lr=0x%X\n",
                   i,(unsigned)ctx.r3.u32,(uint32_t)ctx.lr);
  }
  __imp__sub_820F6A20(ctx,base);
}

// ★ Round 14 — THE ONE-SHOT/LOOPED DISCRIMINATOR. FUN_82150148 decompiled as a structural twin
// of the PDB-named CSWVoice::ProcessQueue (leap_swvoice_named.txt): packet@+0xB8, loopCount@
// +0xC0, Prepare=0x8214F818, ProcessOneShot=0x8214F8C0, ProcessLooped=0x8214FA68. The authored
// shot grains are one-shots (loop 0,0) — if the demo's packets run ProcessLooped, the packet
// loop fields are garbage and the packet BUILDER is the ghost's root. Tally both + dump the
// live packet (this+0xB8) fields on the looped path.
extern "C" void __imp__sub_8214F8C0(PPCContext& __restrict, uint8_t*);
extern "C" void __imp__sub_8214FA68(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_8214F8C0){
  if(rt_dchain_on()){
    static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    if(i<=4||(i%4096)==0) std::fprintf(stderr,"[psel] oneShot #%ld this=0x%X\n",i,(unsigned)ctx.r3.u32);
  }
  __imp__sub_8214F8C0(ctx,base);
}
static void rt_pktwatch_arm(uint32_t pkt);   // round 17, defined at file end
PPC_FUNC(sub_8214FA68){
  if(rt_dchain_on()){
    static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    uint32_t v0=ctx.r3.u32;
    if(v0 && v0<0xF0000000u) rt_pktwatch_arm(PPC_LOAD_U32(v0+0xB8));  // no-op unless RT_PKTWATCH=1
    if(i<=8||(i%4096)==0){
      uint32_t v=ctx.r3.u32;
      uint32_t pkt=(v&&v<0xF0000000u)?PPC_LOAD_U32(v+0xB8):0;
      uint32_t lc =(v&&v<0xF0000000u)?PPC_LOAD_U32(v+0xC0):0;
      char pb[220]; int off=0;
      if(pkt&&pkt<0xF0000000u)
        for(int k=0;k<10;k++) off+=std::snprintf(pb+off,sizeof pb-off,"%08X ",PPC_LOAD_U32(pkt+k*4));
      std::fprintf(stderr,"[psel] LOOPED #%ld this=0x%X loopCnt=%u pkt=0x%X [%s]\n",
                   i,v,lc,pkt,pb);
    }
  }
  __imp__sub_8214FA68(ctx,base);
}

// ★ Round 15 — WHERE THE GARBAGE PACKET COMES FROM. Round 14 proved the ghost: the shot voice
// takes the LOOPED path because packet[6]+packet[7] (0x0087D010 + 0xFF7879F4) overflows past
// packet[0]+packet[4], so PrepareNextPacket (0x8214F818) sets loopCount=packet[8]=0x36B260
// (a POINTER, not a count) => infinite re-serve. Authored SE grains are one-shots (loop 0,0),
// so these are UNINITIALISED/STALE packet fields. This wraps the packet dequeue
// (RemoveHead, 0x8214F1B0) to log each dequeued packet's 10 dwords + its address: packets whose
// loop fields are garbage AT DEQUEUE were built wrong (hunt the builder/AddTail caller);
// packets clean at dequeue but garbage later mean someone stomps them in place.
extern "C" void __imp__sub_8214F1B0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_8214F1B0){
  __imp__sub_8214F1B0(ctx,base);
  if(rt_dchain_on()){
    static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    uint32_t pkt=ctx.r3.u32;
    // ★ Round 19: TARGETED ARM + DIRTY-AT-DEQUEUE TEST. Round 18 armed the first heap packet
    // (0x270890C) but the ghost was 0x276E804 — the address moves every run while the CONTENT
    // signature is stable across all three: d[3]==d[5]==0x4A04 (the authored play length of SE
    // wave 18) and d[8]==the pool object ptr (0x36B250/0x36B260). So select by signature, not
    // by ordinal. Two outcomes, both decisive:
    //   DIRTY-AT-DEQUEUE  -> the triple is written before the packet is handed out; a watch
    //                        here is too late and the arm must move to enqueue/creation.
    //   CLEAN-AT-DEQUEUE  -> arm right now on the RIGHT packet; the next write to the triple
    //                        is the culprit's RIP.
    if(pkt && pkt<0xF0000000u){
      uint32_t d3=PPC_LOAD_U32(pkt+0x0C), d6=PPC_LOAD_U32(pkt+0x18),
               d7=PPC_LOAD_U32(pkt+0x1C), d8=PPC_LOAD_U32(pkt+0x20);
      bool dirty = (d6|d7|d8)!=0;
      if(d3==0x4A04u || dirty){
        static std::atomic<long> sn{0}; long s=sn.fetch_add(1)+1;
        if(s<=24)
          std::fprintf(stderr,"[pktsig] #%ld pkt=0x%X d3=%08X triple=%08X %08X %08X -> %s\n",
                       s,pkt,d3,d6,d7,d8,dirty?"DIRTY-AT-DEQUEUE":"clean");
        // ★ Round 20: ARM ON THE DIRTY PACKET ANYWAY — REFUTED BY RUN (pktcatch): the SE queue
        // sees ~15 dequeues per whole attract, so the armed packet is rarely recycled inside the
        // remaining window (5 page writes, none on the triple). Guard-at-DEQUEUE is the wrong
        // tool for this low-traffic object. DISABLED so the one-shot arm is free for the
        // enqueue-side probe (round 21 below), which arms inside the exact window that matters.
        // rt_pktwatch_arm(pkt);
      }
    }
    if(pkt && pkt<0xF0000000u && (i<=12 || (i%2048)==0)){
      uint32_t d[10]; for(int k=0;k<10;k++) d[k]=PPC_LOAD_U32(pkt+k*4);
      bool bad = (d[6]+d[7]+d[0]) > (d[0]+d[4]);   // the LOOPED predicate
      std::fprintf(stderr,"[pkt] #%ld pkt=0x%X %s [%08X %08X %08X %08X %08X %08X %08X %08X %08X %08X] lr=0x%X\n",
        i,pkt,bad?"LOOPY":"oneshot",d[0],d[1],d[2],d[3],d[4],d[5],d[6],d[7],d[8],d[9],(uint32_t)ctx.lr);
    }
  }
}

// ★ Round 21 — THE ENQUEUE PROBE (the decisive side). Static walk (enqueue_addtail.txt):
// dequeue 0x8214F1B0's enqueue sibling is AddTail = FUN_8214FC18 (node[0]=pkt, tail-link at
// list+0x24/+0x28/+0x2C), sole caller = SubmitPacket = FUN_821500D0(voice, pkt) ->
// AddTail(voice+0x84, pkt), whose callers are the async command dispatcher ops 5/6
// (FUN_82137C20/FUN_82137D60, pkt = *(cmd+0x10)). Round 19 proved DIRTY-AT-DEQUEUE; this
// decides WHERE it went dirty:
//   DIRTY-AT-ENQUEUE -> the producer (command-builder, client thread) wrote the triple; walk
//                       up from the dispatcher op-5/6 command builder.
//   CLEAN-AT-ENQUEUE -> it is stomped WHILE QUEUED; arm the guard page HERE (packet is inside
//                       the exact window where it goes bad — kills the round-20 low-traffic
//                       objection) and the next write's RIP names the culprit.
extern "C" void __imp__sub_821500D0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_821500D0){
  if(rt_dchain_on()){
    static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    uint32_t voice=ctx.r3.u32, pkt=ctx.r4.u32;
    if(pkt && pkt<0xF0000000u){
      uint32_t d[10]; for(int k=0;k<10;k++) d[k]=PPC_LOAD_U32(pkt+k*4);
      bool dirty=(d[6]|d[7]|d[8])!=0;
      bool sig  =(d[3]==0x4A04u);
      if(i<=32 || sig || dirty)
        std::fprintf(stderr,"[pktenq] #%ld voice=0x%X pkt=0x%X %s [%08X %08X %08X %08X %08X %08X %08X %08X %08X %08X] lr=0x%X\n",
          i,voice,pkt,dirty?"DIRTY-AT-ENQUEUE":"clean",
          d[0],d[1],d[2],d[3],d[4],d[5],d[6],d[7],d[8],d[9],(uint32_t)ctx.lr);
      // Arm only on a CLEAN signature packet: catch the in-queue stomp red-handed.
      if(sig && !dirty) rt_pktwatch_arm(pkt);
    }
  }
  __imp__sub_821500D0(ctx,base);
}

// ★ Round 22 — THE SOURCE BUFFER. Round 21 run (pktenq): DIRTY-AT-ENQUEUE, and the guard page
// caught the packet fill red-handed: sub_8207DAC0 (= memcpy; its neighbour 0x8207DA20 is the
// ctor's memset) writing all 10 dwords of packet 0x2763514, triple included. That memcpy is
// FUN_82137D60 = the client-side SubmitSourceBuffer (fresh-map symbolication, /MAP relink):
// slot A this+0x1C (busy +0x40) / slot B this+0x58 (busy +0x7C) / heap 0x28, then
// memcpy(slot, r4, 0x28) and queue op-5/6. The copy is verbatim ⇒ the CALLER's XAUDIO2_BUFFER
// already carries the garbage loop triple. This logs r4 (the source buffer) + its dwords +
// ctx.lr at entry: the lr on a dirty/signature buffer IS the producer.
extern "C" void __imp__sub_82137D60(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_82137D60){
  if(rt_dchain_on()){
    static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    uint32_t src=ctx.r4.u32;
    if(src && src<0xF0000000u){
      uint32_t d[10]; for(int k=0;k<10;k++) d[k]=PPC_LOAD_U32(src+k*4);
      bool dirty=(d[6]|d[7]|d[8])!=0;
      bool sig  =(d[3]==0x4A04u);
      if(i<=24 || sig || dirty)
        std::fprintf(stderr,"[srcbuf] #%ld this=0x%X src=0x%X %s [%08X %08X %08X %08X %08X %08X %08X %08X %08X %08X] lr=0x%X r5=0x%X\n",
          i,(unsigned)ctx.r3.u32,src,dirty?"DIRTY-SRC":"clean",
          d[0],d[1],d[2],d[3],d[4],d[5],d[6],d[7],d[8],d[9],(uint32_t)ctx.lr,(unsigned)ctx.r5.u32);
    }
  }
  __imp__sub_82137D60(ctx,base);
}

// Round 25 shared state: per-thread snapshot of the wave descriptor at sub_820FE7D8 entry
// (filled by the round-24 wrapper below, consumed by the round-23 wrapper on a dirty packet).
struct RtWdescSnap { uint32_t desc; uint32_t d[10]; uint32_t thisv; };
static thread_local RtWdescSnap g_wdesc_snap{0,{0},0};

// ★ Round 23 — THE XACT VOICE PACKET. Round 22 run (srcbuf): every dirty submit comes from
// lr=0x8210D9F4 inside FUN_8210D8A8 = CXAudio2SourceVoice::SubmitPacket (PC XACT PDB name),
// XAUDIO2_BUFFER is a stack local (0x18FE200), memset-zeroed 0x24 THEN loop triple written
// ONLY IF the incoming XACTVoicePacket's loopCount (r4[7]) != 0 — and its d7 fallback is
// PlayLength-LoopBegin, which IS the measured d6+d7==len invariant. So the garbage arrives in
// the XACTVoicePacket: r4[5]=loopBegin r4[6]=loopLength r4[7]=loopCount=0x36B260 (pool obj).
// This logs r4 + its 10 dwords + lr at entry: the lr names who BUILT the packet, the address
// names where it lives (stack / pool slice / wave instance).
extern "C" void __imp__sub_8210D8A8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_8210D8A8){
  if(rt_dchain_on()){
    static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    uint32_t vp=ctx.r4.u32;
    if(vp && vp<0xF0000000u){
      uint32_t d[10]; for(int k=0;k<10;k++) d[k]=PPC_LOAD_U32(vp+k*4);
      bool dirty=(d[5]|d[6]|d[7])!=0;
      if(i<=24 || dirty)
        std::fprintf(stderr,"[xvpkt] #%ld this=0x%X vp=0x%X %s [%08X %08X %08X %08X %08X %08X %08X %08X %08X %08X] lr=0x%X\n",
          i,(unsigned)ctx.r3.u32,vp,dirty?"DIRTY-VP":"clean",
          d[0],d[1],d[2],d[3],d[4],d[5],d[6],d[7],d[8],d[9],(uint32_t)ctx.lr);
      // Round 25: on a dirty packet, print the same-thread entry snapshot of the descriptor
      // plus a FRESH re-read — if entry was clean and the re-read shows the pool-node shape,
      // the mid-call cross-thread stomp is proven and the victim's address class is named.
      if(dirty && g_wdesc_snap.desc){
        uint32_t ds=g_wdesc_snap.desc, rd[10];
        for(int k=0;k<10;k++) rd[k]=PPC_LOAD_U32(ds+k*4);
        std::fprintf(stderr,"[race] desc=0x%X this=0x%X ENTRY [%08X %08X %08X %08X %08X %08X %08X %08X %08X %08X] NOW [%08X %08X %08X %08X %08X %08X %08X %08X %08X %08X]\n",
          ds,g_wdesc_snap.thisv,
          g_wdesc_snap.d[0],g_wdesc_snap.d[1],g_wdesc_snap.d[2],g_wdesc_snap.d[3],g_wdesc_snap.d[4],
          g_wdesc_snap.d[5],g_wdesc_snap.d[6],g_wdesc_snap.d[7],g_wdesc_snap.d[8],g_wdesc_snap.d[9],
          rd[0],rd[1],rd[2],rd[3],rd[4],rd[5],rd[6],rd[7],rd[8],rd[9]);
      }
    }
  }
  __imp__sub_8210D8A8(ctx,base);
}

// ★ Round 24 — THE WAVE DESCRIPTOR. Round 23 run (xvpkt): every dirty XACTVoicePacket is
// built at lr=0x820FE8C4 in FUN_820FE7D8, whose FUN_820FE490 fill is FULLY DETERMINISTIC
// (no uninitialised fields): pkt.loopCount = desc[2], pkt.loopBegin = desc[5],
// pkt.loopLength = desc[6]-desc[5]. The observed garbage (loopCount=0x36B250 the pool obj,
// loopBegin = fresh heap ptrs per call) therefore lives in the SOURCE DESCRIPTOR desc = r4 of
// FUN_820FE7D8 — passed straight through from ITS caller (asm: r4 untouched before the bl).
// Virtual (vtable 0x8201576C region), so name the caller at runtime: log r4 + dwords + lr.
// Round 25 upgrade: the round-24 run showed the dirty calls' descriptors are CLEAN AT ENTRY
// (no [wdesc] DIRTY line ever carries the 0x36B250 ctor-state shape) yet garbage by the time
// FUN_820FE490 reads them ~30 insns later — a cross-thread stomp whose shape is a POOL FREE
// NODE (owner=0x36B250, flink==blink) = use-after-free race with the steal/destroy path.
// Prove it airtight: snapshot desc at entry per-thread; on DIRTY-VP at SubmitPacket, print
// the snapshot + desc addr + a fresh re-read.
extern "C" void __imp__sub_820FE7D8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820FE7D8){
  if(rt_dchain_on()){
    static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    uint32_t ds=ctx.r4.u32;
    if(ds && ds<0xF0000000u){
      uint32_t d[10]; for(int k=0;k<10;k++) d[k]=PPC_LOAD_U32(ds+k*4);
      g_wdesc_snap.desc=ds; g_wdesc_snap.thisv=ctx.r3.u32;
      for(int k=0;k<10;k++) g_wdesc_snap.d[k]=d[k];
      bool dirty=(d[2]|d[5]|d[6])!=0;   // loopCount / loopStart / loopEnd authored zero for SE
      if(i<=24 || dirty)
        std::fprintf(stderr,"[wdesc] #%ld this=0x%X desc=0x%X %s [%08X %08X %08X %08X %08X %08X %08X %08X %08X %08X] lr=0x%X r5=0x%X r6=0x%X r7=0x%X\n",
          i,(unsigned)ctx.r3.u32,ds,dirty?"DIRTY-DESC":"clean",
          d[0],d[1],d[2],d[3],d[4],d[5],d[6],d[7],d[8],d[9],
          (uint32_t)ctx.lr,(unsigned)ctx.r5.u32,(unsigned)ctx.r6.u32,(unsigned)ctx.r7.u32);
    }
  }
  __imp__sub_820FE7D8(ctx,base);
}

// ★ Round 16 — THE PACKET WRITER. Round 15: streaming packets dequeue CLEAN (loop fields 0),
// but the ghost's packet (embedded at wave+0x170, per SubmitPacket 0x820FD480) carries garbage
// in the loop triple: d[6]=0x0087D010 d[7]=0xFF7879F4 d[8]=0x0036B260 (a POINTER used as the
// loop count). Authored SE waves are one-shots, so those fields must be zero — they are STALE.
// This wraps SubmitPacket to dump the embedded packet at submit time: garbage already present
// here means the wave object was recycled without clearing (our allocator/recommit parity gap);
// clean here means a later writer stomps it.
extern "C" void __imp__sub_820FD480(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_820FD480){
  if(rt_dchain_on()){
    static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
    uint32_t w=ctx.r3.u32;
    if(w && w<0xF0000000u && (i<=10 || (i%1024)==0)){
      uint32_t p=w+0x170, d[10];
      for(int k=0;k<10;k++) d[k]=PPC_LOAD_U32(p+k*4);
      bool loopy = (uint32_t)(d[6]+d[7]+d[0]) > (uint32_t)(d[4]+d[0]);
      std::fprintf(stderr,"[submit] #%ld wave=0x%X pkt=0x%X %s [%08X %08X %08X %08X %08X %08X %08X %08X %08X %08X]\n",
        i,w,p,loopy?"LOOPY-AT-SUBMIT":"clean",d[0],d[1],d[2],d[3],d[4],d[5],d[6],d[7],d[8],d[9]);
    }
  }
  __imp__sub_820FD480(ctx,base);
}

// ★ Round 17 — WRITE-WATCH THE GHOST PACKET (the named next move). The loop triple is written
// as a STRUCTURED (endPtr, -startPtr, poolObj+0x10) descriptor — reproduced across two runs,
// d[6]+d[7] == 0x4A04 == the authored play length of SE wave 18 — so a specific writer stomps
// the packet through the wrong struct view. This arms the harness guard-page watcher
// (rt_watch_arm_dyn, the RT_WATCHTEX machinery: PAGE_GUARD + single-step re-arm, already
// positive-controlled) on the packet's page the FIRST time the looped path is taken, so the
// NEXT write to that page prints the faulting host RIP + backtrace => the writer, symbolicated
// against exe+0x. Gated: needs BOTH RT_VOICECENSUS=1 and RT_PKTWATCH=1 (arming a guard page is
// intrusive; keep it out of ordinary census runs). One-shot: only the first ghost is armed.
extern "C" void rt_watch_arm_dyn(uint32_t guestAddr, uint32_t len);
static void rt_pktwatch_arm(uint32_t pkt){
  static bool on = [](){ const char* e=std::getenv("RT_PKTWATCH"); return e && e[0]=='1' && !e[1]; }();
  if(!on || !pkt || pkt>=0xF0000000u) return;
  static std::atomic<int> armed{0};
  if(armed.fetch_add(1)!=0) return;
  std::fprintf(stderr,"[pktwatch] arming guard page for ghost packet 0x%X (loop triple at +0x18..+0x20)\n",pkt);
  rt_watch_arm_dyn(pkt, 0x28);
}
