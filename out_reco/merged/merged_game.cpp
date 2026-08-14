// merged_game.cpp — the GAME-MODULE half: every sub_88 hook. Moves into the per-module DLL at E6,
// so this TU is the one that carries -include abn_symbol_map.h and -DGA_DSHIFT
// Split out of out_reco/merged/merged_xex.cpp (verbatim) by L2 of
// _tmpscripts/dll_packaging_plan.md §2.3/§2.4.  Original: merged_xex.cpp.bak_l2split.
// Shared scaffolding lives in merged_common.h.
#include "merged_common.h"

// ---- DEBUG wrappers (RT_DBGSPAWN=1): trace the game msg-2 boot routine + thread-spawn
// trampoline to see whether the game-main ExCreateThread(ctx=0x88168D48) is reached. ----
extern "C" void __imp__sub_8808FDF8(PPCContext& __restrict, uint8_t*);
extern "C" void __imp__sub_88083200(PPCContext& __restrict, uint8_t*);
extern "C" void __imp__sub_8807C0A8(PPCContext& __restrict, uint8_t*);
extern "C" void __imp__sub_8808DA28(PPCContext& __restrict, uint8_t*);
extern "C" void __imp__sub_880901B8(PPCContext& __restrict, uint8_t*);
static bool dbgspawn(){ static bool on=std::getenv("RT_DBGSPAWN")!=nullptr; return on; }

// sub_8807C0A8: suspected grind loop; iteration count comes from *(u32*)(r5+28).
// Log the first 20 calls in full, then every 1,000,000th call; track total calls + max count seen.
// Logging is now UNGATED (always on, no RT_DBGSPAWN check). A corruption FIREWALL guards the
// call to the original: garbage args (r3==0, r5==0, r5 in kernel/negative range, or an absurd
// iteration count) drive ~65k scattered atomic writes across low guest memory in the original's
// internal loop, corrupting the main thread's guest stack. When guarded, skip the original
// entirely and return with ctx.r3.u64=0 instead.
static std::atomic<long long> g_c0a8_calls{0};
static std::atomic<uint32_t> g_c0a8_max_count{0};
PPC_FUNC(sub_8807C0A8){
  long long n = g_c0a8_calls.fetch_add(1)+1;
  if(n<=4) rt_heapdump(base, "c0a8-call");
  if(n<=4){ std::fprintf(stderr, "[r26] c0a8-call r26=%08X\n", (uint32_t)ctx.r26.u32); std::fflush(stderr); }
  uint32_t r3=ctx.r3.u32;
  uint32_t r5=ctx.r5.u32;
  uint32_t cnt = r5 ? PPC_LOAD_U32(r5+28) : 0;
  uint32_t prev = g_c0a8_max_count.load();
  while(cnt>prev && !g_c0a8_max_count.compare_exchange_weak(prev,cnt)) {}
  if(n<=20 || (n%1000000)==0){
    std::fprintf(stderr,"[c0a8] sub_8807C0A8 call#%lld r3=0x%X r4=0x%X r5=0x%X *(r5+28)=%u\n",
      n,r3,ctx.r4.u32,r5,cnt);
  }
  // RANK-8 FIREWALL RETIRED (2026-07-19): the corruption firewall was a symptom-patch for the
  // era when the game's .data was never loaded into guest memory (FILE_INFO vtable @0x88252560 == 0
  // => garbage args here). rt_load_game_data_sections() (XexLoadImage above) now populates .data, so
  // every observed call arrives with valid args (r3/r5 in heap range, *(r5+28) small) and the
  // original runs cleanly with r26 preserved. Verified: 0 GUARDED-SKIPs across boot AND a full
  // menu->field run. Keep the guard predicate as a DIAGNOSTIC only (log-and-continue); do NOT skip.
  bool would_guard = (r3==0 || r5==0 || r5>=0x80000000u || cnt>4096);
  if(would_guard){
    static std::atomic<long long> g{0}; long long gi=g.fetch_add(1)+1;
    if(gi<=8 || (gi%100000)==0)
      std::fprintf(stderr,"[c0a8] WOULD-GUARD (firewall retired; calling original) r3=%x r5=%x cnt=%u\n",r3,r5,cnt);
  }
  __imp__sub_8807C0A8(ctx,base);
}

// sub_8808DA28: cheap ENTER/EXIT trace, first 20 calls only.
static std::atomic<long long> g_da28_calls{0};
PPC_FUNC(sub_8808DA28){
  bool d=dbgspawn();
  long long n = g_da28_calls.fetch_add(1)+1;
  bool log = d && n<=20;
  rt_heapdump(base, "DA28-enter");
  if(n<=4){ std::fprintf(stderr, "[r26] DA28-enter r26=%08X\n", (uint32_t)ctx.r26.u32); std::fflush(stderr); }
  if(log) std::fprintf(stderr,"[dbg] sub_8808DA28 ENTER call#%lld r3=0x%X r4=0x%X r5=0x%X\n",n,ctx.r3.u32,ctx.r4.u32,ctx.r5.u32);
  uint32_t save26=ctx.r26.u32, save27=ctx.r27.u32, save28=ctx.r28.u32;
  __imp__sub_8808DA28(ctx,base);
  if(save26==0x88168D48u && ctx.r26.u32!=save26) std::fprintf(stderr,"[clob] sub_8808DA28 clobbered r26 0x88168D48 -> 0x%X\n",ctx.r26.u32);
  // FIX (RT_FIXCLOB): sub_8808DA28's recompiled body writes callee-saved r26 (and possibly
  // r27/r28) but its prologue only __savegprlr_29 (saves r29-r31), so those are never restored
  // -> corrupts the caller's r26 (game-main fn ptr) and every other saved-reg-dependent value.
  // Enforce the ABI contract the buggy recomp violates by restoring r26/r27/r28 to entry. This
  // is the true fix (vs the lr-keyed RT_FIXSPAWN stopgap) and repairs ALL clobbered spawns.
  if(std::getenv("RT_FIXCLOB")){ ctx.r26.u32=save26; ctx.r27.u32=save27; ctx.r28.u32=save28; }
  rt_heapdump(base, "DA28-exit");
  if(n<=4){ std::fprintf(stderr, "[r26] DA28-exit r26=%08X\n", (uint32_t)ctx.r26.u32); std::fflush(stderr); }
  if(log) std::fprintf(stderr,"[dbg] sub_8808DA28 EXIT call#%lld r3=0x%X\n",n,ctx.r3.u32);
}

static std::atomic<long long> g_fdf8_calls{0};
PPC_FUNC(sub_8808FDF8){
  bool d=dbgspawn();
  long long n = g_fdf8_calls.fetch_add(1)+1;
  rt_heapdump(base, "FDF8-enter");
  if(n<=4){
    uint32_t guard568 = PPC_LOAD_U32(0x887AD568u);
    uint32_t guard56C = PPC_LOAD_U32(0x887AD56Cu);
    std::fprintf(stderr, "[r26] FDF8-enter r26=%08X guard={%08X,%08X}\n", (uint32_t)ctx.r26.u32, guard568, guard56C);
    std::fflush(stderr);
  }
  if(d){
    uint32_t guard568 = PPC_LOAD_U32(0x887AD568u);
    uint32_t guard56C = PPC_LOAD_U32(0x887AD56Cu);
    std::fprintf(stderr,"[dbg] sub_8808FDF8 ENTER r3=0x%X r4=0x%X (imports=%ld) guard[0x887AD568]=0x%X guard[0x887AD56C]=0x%X\n",
      ctx.r3.u32,ctx.r4.u32,g_import_calls.load(),guard568,guard56C);
  }
  __imp__sub_8808FDF8(ctx,base);
  rt_heapdump(base, "FDF8-exit");
  if(n<=4){ std::fprintf(stderr, "[r26] FDF8-exit r26=%08X\n", (uint32_t)ctx.r26.u32); std::fflush(stderr); }
  if(d) std::fprintf(stderr,"[dbg] sub_8808FDF8 EXIT r3=0x%X (imports=%ld) c0a8_calls=%lld c0a8_max(r5+28)=%u\n",
    ctx.r3.u32,g_import_calls.load(),g_c0a8_calls.load(),g_c0a8_max_count.load());
}
PPC_FUNC(sub_88083200){
  // STOPGAP (RT_FIXSPAWN): sub_8808FDF8 sets the game-main fn ptr r26=0x88168D48 (literal @
  // ppc_recomp.4.cpp:14936) and passes r6=r26 to this trampoline (:15038), but a callee clobbers
  // the non-volatile r26 to a heap addr on the real-.data path, so the runner sub_8808F798
  // (mtctr r3;bctrl) calls garbage and the game main never runs. Force the correct fn ptr at THIS
  // exact spawn site (return addr lr=0x8808FF20) so sub_88168D48 runs. (Real fix = find the
  // clobbering callee; this proves the theory + unblocks downstream testing.)
  if(std::getenv("RT_FIXSPAWN") && (uint32_t)ctx.lr==0x8808FF20u && ctx.r6.u32!=0x88168D48u){
    std::fprintf(stderr,"[fixspawn] forcing game-main ctx r6 0x%X -> 0x88168D48\n",ctx.r6.u32);
    ctx.r6.u32=0x88168D48u;
  }
  if(dbgspawn()) std::fprintf(stderr,"[dbg] sub_88083200 SPAWN-trampoline ctx(r6)=0x%X start(r7)=0x%X lr=0x%X\n",ctx.r6.u32,ctx.r7.u32,(uint32_t)ctx.lr);
  __imp__sub_88083200(ctx,base);
}

// ---- RT_PUMPFIX: the streaming/decompress WORKER (sub_88092C28) waits on an event whose
// handle lives at guest 0x887ACD30 (companion "system live" handle at 0x887ACD34 — the
// queue-push signaler sub_880929C8 gates on it being non-null, then NtSetEvents *0xD30).
// In our harness nothing ever creates that pair -> worker's first wait fails -> the worker
// RETURNS immediately -> no decompress/commit completions ever run (root cause of the
// starved asset-commit flag 0x887AC973 that RT_LOADDONE papers over). Create the pair with
// REAL kernel events at worker entry if absent. This is missing-init HLE, not a state lie. ----
extern "C" void __imp__sub_88092C28(PPCContext& __restrict, uint8_t*);
extern "C" void __imp__NtCreateEvent(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88092C28){
  if(std::getenv("RT_PUMPFIX") && PPC_LOAD_U32(0x887ACD30u)==0){
    uint32_t scratch = ctx.r1.u32 - 64;   // transient guest scratch below the worker's SP
    uint32_t h[2]={0,0};
    for(int k=0;k<2;++k){
      PPCContext ic=ctx; ic.r3.u32=scratch; ic.r4.u32=0; ic.r5.u32=1/*SynchronizationEvent*/; ic.r6.u32=0;
      __imp__NtCreateEvent(ic,base);
      h[k]=PPC_LOAD_U32(scratch);
    }
    PPC_STORE_U32(0x887ACD30u,h[0]);
    PPC_STORE_U32(0x887ACD34u,h[1]);
    std::fprintf(stderr,"[pumpfix] worker event pair created: *(0x887ACD30)=0x%X *(0x887ACD34)=0x%X\n",h[0],h[1]);
  }
  std::fprintf(stderr,"[pumpfix] worker sub_88092C28 ENTER (wait handle=0x%X)\n",PPC_LOAD_U32(0x887ACD30u));
  __imp__sub_88092C28(ctx,base);
  std::fprintf(stderr,"[pumpfix] worker sub_88092C28 RETURNED r3=0x%X\n",ctx.r3.u32);
}
// [scene] game-side commit tier: sub_8808E780 = scene-graph PUBLISHER (writes *(0x88699894));
// sub_8808E740 = sibling flag getter. If the publisher never fires, the game's title sprites
// never register -> title never "done". Log every call + the value published.
extern "C" void __imp__sub_8808E780(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_8808E780){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  __imp__sub_8808E780(ctx,base);
  if(i<=4||(i%2000)==0)   // CODE_REVIEW_0804 E21: was uncapped (its sibling 8808E740 was already throttled)
    std::fprintf(stderr,"[scene] PUBLISH sub_8808E780 #%ld -> *(0x88699894)=0x%X (r3=0x%X r4=0x%X)\n",
      i, PPC_LOAD_U32(0x88699894u), ctx.r3.u32, ctx.r4.u32);
}
extern "C" void __imp__sub_8808E740(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_8808E740){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  __imp__sub_8808E740(ctx,base);
  if(i<=4||i%2000==0) std::fprintf(stderr,"[scene] getter sub_8808E740 #%ld -> r3=0x%X\n",i,ctx.r3.u32);
}
// [gwork] game asset-commit worker queue push (sub_880929C8 — gates on 0x887ACD34 non-null
// then NtSetEvents *0xD30). Log to see if the game ever ENQUEUES a decompress/commit job.
extern "C" void __imp__sub_880929C8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_880929C8){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  if(i<=8||i%500==0) std::fprintf(stderr,"[gwork] enqueue sub_880929C8 #%ld r3=0x%X r4=0x%X (D34=0x%X)\n",
    i,ctx.r3.u32,ctx.r4.u32,PPC_LOAD_U32(0x887ACD34u));
  __imp__sub_880929C8(ctx,base);
}

// ---- LEG-19 (Arch, 2026-07-07): WORKER-SUBSYSTEM INIT GATE diagnostic.
// CORRECTION to LEG-18: the real worker control block is at 0x887AD4B0 (event handle) /
// 0x887AD4B4 (thread handle) — NOT 0x887ACD30 (that address was off by 0x780; the old
// RT_PUMPFIX wrote a dead address). The manager sub_88092ED8 creates the event+thread and
// the id46/47 enqueue is only un-suppressed when sub_880928D8 (gameplay-scene archive open)
// returns != -1; that result is stored at 0x88252E1C. If it returns -1, the manager
// early-outs (loc_880931CC) BEFORE NtCreateEvent/ExCreateThread => worker dead + no enqueue.
// These wrappers pin the bail: does sub_880928D8 return -1, and does the manager wire the pair?
extern "C" void __imp__sub_880928D8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_880928D8){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  __imp__sub_880928D8(ctx,base);
  if(i<=6) std::fprintf(stderr,"[winit] sub_880928D8 #%ld -> r3=0x%X  (archive-open; -1=FAIL => manager bails)\n",i,ctx.r3.u32);
}
extern "C" void __imp__sub_88092ED8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88092ED8){
  static std::atomic<int> once{0}; bool f=(once.fetch_add(1)==0);
  if(f) std::fprintf(stderr,"[winit] manager sub_88092ED8 ENTER\n");
  __imp__sub_88092ED8(ctx,base);
  if(f) std::fprintf(stderr,"[winit] manager EXIT r28ok=0x%X | CD30(event 0x887AD4B0)=0x%X CD34(thread 0x887AD4B4)=0x%X upflag(0x88252E1C)=0x%X\n",
    ctx.r3.u32, PPC_LOAD_U32(0x887AD4B0u), PPC_LOAD_U32(0x887AD4B4u), PPC_LOAD_U32(0x88252E1Cu));
}
// [wjob] the REAL per-job enqueue (sub_88092B20: push {r3=resource id, r4=callback, r5=ctx}
// onto the worker ring + NtSetEvent the worker event) and the worker's job DISPATCH
// (sub_88092B80). If B20 fires for id 46/47 and B80 dispatches, the worker IS building the
// gameplay scene; if B20 never fires post-submit, nothing asks the worker to build it.
extern "C" void __imp__sub_88092B20(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88092B20){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  if(i<=50||i%500==0) std::fprintf(stderr,"[wjob] ENQUEUE#%ld sub_88092B20 id=0x%X r4=0x%X r5=0x%X\n",i,ctx.r3.u32,ctx.r4.u32,ctx.r5.u32);
  __imp__sub_88092B20(ctx,base);
}
extern "C" void __imp__sub_88092B80(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88092B80){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  if(i<=40||i%200==0) std::fprintf(stderr,"[wjob] DISPATCH#%ld sub_88092B80 r3=0x%X\n",i,ctx.r3.u32);
  __imp__sub_88092B80(ctx,base);
}

// [gpcb] LEG-21 DETECTOR: sub_88163CF0 is the #1 gameplay-object callback (x920 in SDK gameplay
// data). Now that it's recompiled (part A), it gets CALLED iff merged ENTERS real gameplay. This
// wrapper = a "did we reach gameplay" tripwire. Same for sub_881602F0 (another gameplay callback).
extern "C" void __imp__sub_88163CF0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88163CF0){
  static std::atomic<long long> n{0}; long long i=n.fetch_add(1)+1;
  if(i==1||i%2000==0) std::fprintf(stderr,"[gpcb] *** GAMEPLAY CALLBACK sub_88163CF0 CALLED #%lld — GAMEPLAY ENTERED ***\n",i);
  __imp__sub_88163CF0(ctx,base);
}
extern "C" void __imp__sub_881602F0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_881602F0){
  static std::atomic<long long> n{0}; long long i=n.fetch_add(1)+1;
  if(i==1||i%2000==0) std::fprintf(stderr,"[gpcb] gameplay callback sub_881602F0 called #%lld\n",i);
  __imp__sub_881602F0(ctx,base);
}
// [gpfac] the GAMEPLAY-SCENE factories: sub_88227220 (id46, this=registry entry r3, r4=arg;
// arg5 in the REQ was 0x884D6740=FSM obj) and sub_880FBB08 (id47). These are dispatched by the
// resource pump when the id46/47 REQ completes and should CONSTRUCT the gameplay scene object +
// install its per-frame drawer. If they NEVER fire at scene=5/d76=8, the scene object is never
// built => near-black. If they DO fire, the gap is downstream (drawer not registered/ticked).
extern "C" void __imp__sub_88227220(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88227220){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  // WORKFLOW FINDING: the id46 factory registers the scene into the PRIORITY DRAW LIST (0x885A5C20,
  // the real per-frame drawer tick) via sub_880E3888 — but that EARLY-RETURNS if +312 (0x884D6878)!=0.
  // If +312 is stuck (the LEG-14/17 menu timer flag), the gameplay scene is never in the per-frame
  // draw list -> drawer sub_88226EB0 ticked only ~12x by the pump then dropped -> near-black.
  // RT_CLEAR312: zero +312 across the id46 factory so sub_880E3888 registers the scene.
  uint32_t p312_pre=PPC_LOAD_U32(0x884D6878u);
  static int clr = std::getenv("RT_CLEAR312")?atoi(std::getenv("RT_CLEAR312")):0;
  if(clr) PPC_STORE_U32(0x884D6878u,0);
  std::fprintf(stderr,"[gpfac] id46 factory CALL#%ld r3=0x%X r4=0x%X | +312(0x884D6878)=0x%X%s\n",
    i,ctx.r3.u32,ctx.r4.u32,p312_pre, clr?" (CLEARED)":"");
  __imp__sub_88227220(ctx,base);
  std::fprintf(stderr,"[gpfac] id46 factory RET#%ld r3=0x%X\n",i,ctx.r3.u32);
}
// [prio] sub_880E3888 registers the id46 scene into the priority draw list 0x885A5C20 (per-frame
// drawer tick) — gated on +312==0. Log whether it runs to completion (=scene registered).
extern "C" void __imp__sub_880E3888(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_880E3888){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  if(i<=8) std::fprintf(stderr,"[prio] sub_880E3888 #%ld r3=0x%X +312(0x884D6878)=0x%X\n",i,ctx.r3.u32,PPC_LOAD_U32(0x884D6878u));
  __imp__sub_880E3888(ctx,base);
}
// RT_FORCEPLAYER (LEG-20): the id47 factory installs the gameplay drawer only if object+17!=0,
// which needs sub_88133DB0(slot) to report an AVAILABLE player slot. In merged no player joined
// (RT_SLOT2FIX skipped 1P-SIDE-START) so it returns 0. When RT_FORCEPLAYER, force sub_88133DB0
// to return nonzero WHILE the id47 factory runs -> sub_880FA670 marks a slot live -> obj17++ ->
// gameplay update sub_880FA720 installs. Gated to the id47-factory window via g_in_id47.
std::atomic<int> g_in_id47{0};
extern "C" void __imp__sub_88133DB0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88133DB0){
  uint32_t jl_p1 = ctx.r3.u32;   // capture param_1 (player-record) BEFORE the scan overwrites r3
  // RT_JOINMARK (2026-07-22 EXPERIMENT, default OFF): the id47 obj17-gate needs the ranking/hi-score
  // table (systemobj+0x14c/+0x190) to carry a -1 (1P) / -2 (2P) "current-player" slot marker so the
  // arm sub_880FA670 finds a slot, copies its data into the player, and increments obj17. The natural
  // 1P join fully succeeds (side-record 0x884D6CE8 b0=1, 3 credits, rec+6=3 lives) but never writes
  // that ranking marker, so obj17 stays 0. Unlike RT_FORCEPLAYER (which fabricates the scan RESULT),
  // this writes the marker the join is supposed to write, then lets the game's OWN scan+arm run — so
  // the player is armed with the ranking slot's real data (its +158 field). Slot0 of the joining
  // side's row. Test-only: reveals whether the natural arm yields real lives.
  if(std::getenv("RT_JOINMARK") && g_in_id47.load()>0 && jl_p1>=0x82000000u && jl_p1<0x8B000000u){
    uint32_t side=PPC_LOAD_U8(jl_p1+1u), idx=PPC_LOAD_U8(jl_p1+8u), B=PPC_LOAD_U32(jl_p1+0x80u);
    if(side==0 && B>=0x82000000u && B<0x8B000000u){
      uint32_t F54=PPC_LOAD_U32(B+0x54u);
      uint32_t mk0=((idx*3u+F54)*0xB4u)+B+0x190u;          // slot0 marker for this side's row
      static int jm=0;
      if(PPC_LOAD_U8(mk0)!=0xFFu){ PPC_STORE_U8(mk0,0xFFu); // -1 = 1P current-player marker
        if(jm++<8) std::fprintf(stderr,"[joinmark] wrote -1 marker @0x%X (side=%u idx=%u F54=%u) so natural scan arms 1P\n",mk0,side,idx,F54); }
    }
  }
  __imp__sub_88133DB0(ctx,base);
  // RT_FORCEPLAYER (LEG-20 revival, 2026-07-22): the id47 gameplay factory (sub_880FBB08) installs
  // the real gameplay per-frame update (FUN_880fa720) + sets field_active ONLY if obj17 (0x884D95F1)
  // != 0. obj17 is incremented by sub_880FA670 (decomp line 87135, param+0x11) ONLY when THIS
  // function reports a free player slot (return = slot_index+1). In merged no player ever joined the
  // slot table (1P-SIDE-START join never armed the -1/-2 free markers) so the scan returns 0 => obj17
  // stays 0 => factory early-returns (decomp 87861) => no gameplay drawer => the credited reach falls
  // back to the ATTRACT loop (ranking + DEMONSTRATION demo), never live gameplay. When RT_FORCEPLAYER
  // is set, during the id47-factory window (g_in_id47>0) force a 1P slot (return 1 => sub_880FA670
  // stores slot index 0, side 0) so obj17 increments and the factory installs the gameplay drawer.
  // Gated to the factory window + env presence; default OFF => byte-identical.
  // Force ONLY the 1P slot: the id47 factory inits 2 player slots and calls sub_880FA670 (which
  // calls us) once per slot. Gate the force on obj17 (0x884D95F1) still reading 0 so only the FIRST
  // slot is forced live (obj17 0->1); the second slot sees obj17==1, is NOT forced, returns 0, and no
  // phantom 2P joins. A forced 2P slot (obj17=2) starts a 2-player credited game whose empty 2P side
  // triggers an immediate GAME OVER. RT_FORCEPLAYER2=1 keeps the old both-slots behavior for A/B.
  static bool on = std::getenv("RT_FORCEPLAYER")!=nullptr;
  static bool both = std::getenv("RT_FORCEPLAYER2")!=nullptr;
  // RT_JOINLOG (2026-07-22 survivable-join leg): decompose WHY the scan returns 0 during the id47
  // gameplay-factory window. sub_88133DB0(param_1=r3 player-record) scans the systemobj slot table
  // for a slot whose marker byte == -1 (1P side, record+1==0) / -2 (2P side). It reads:
  //   B    = *(param_1+0x80)                      (the systemobj; expect 0x884D6740)
  //   F54  = *(B+0x54)                            (mode/row selector = DAT_884d6794)
  //   idx  = *(byte*)(param_1+8)                  (slot-block index)
  //   base = ((idx*3 + F54)*0xB4 + B + 0x190)     then 5 markers at stride 0x24
  // If B is wrong (0 / not 0x884D6740) the scan reads a bogus table => never matches => returns 0
  // even though the real slot table (embedded in 0x884D6740) may be correctly armed. This log tells
  // us the exact param_1, B, and the 5 markers the scan actually inspected. Gated to the id47 window.
  static bool jl = std::getenv("RT_JOINLOG")!=nullptr;
  if(jl && g_in_id47.load()>0){
    uint32_t ret=ctx.r3.u32;                    // scan result (0 = no slot found)
    static int n=0; if(n++<24){
      uint32_t p1=jl_p1;                          // the player-record the scan inspected
      uint32_t side = (p1>=0x80000000u&&p1<0x8B000000u)? PPC_LOAD_U8(p1+1u):0xFF;
      uint32_t idx  = (p1>=0x80000000u&&p1<0x8B000000u)? PPC_LOAD_U8(p1+8u):0xFF;
      uint32_t Bp   = (p1>=0x80000000u&&p1<0x8B000000u)? PPC_LOAD_U32(p1+0x80u):0;
      char mk[96]; mk[0]=0; uint32_t F54=0xFFFFFFFFu;
      if(Bp>=0x82000000u && Bp<0x8B000000u){
        F54=PPC_LOAD_U32(Bp+0x54u);
        uint32_t bbase=((idx*3u + F54)*0xB4u) + Bp + 0x190u; int off=0;
        for(int k=0;k<5;k++) off += std::snprintf(mk+off,sizeof(mk)-off,"%02X ",PPC_LOAD_U8(bbase+(uint32_t)k*0x24u));
      } else std::snprintf(mk,sizeof(mk),"(B out of range)");
      // Also dump the canonical systemobj 0x884D6740's own slot table (row F54 of B) for reference.
      uint32_t B0=0x884D6740u,F0=PPC_LOAD_U32(B0+0x54u); char mk0[96]; int o0=0;
      for(uint32_t ix=0;ix<2;ix++){ uint32_t bb=((ix*3u+F0)*0xB4u)+B0+0x190u;
        o0+=std::snprintf(mk0+o0,sizeof(mk0)-o0,"ix%u[",ix);
        for(int k=0;k<5;k++)o0+=std::snprintf(mk0+o0,sizeof(mk0)-o0,"%02X ",PPC_LOAD_U8(bb+(uint32_t)k*0x24u));
        o0+=std::snprintf(mk0+o0,sizeof(mk0)-o0,"]"); }
      std::fprintf(stderr,"[joinlog] scan#%d ret=%u | p1=0x%X side=%u idx=%u B=0x%X F54=%u scanned[%s] | sysobj0740 F=%u %s | obj17=%u rec0.b0=%u rec0.cr=%u rec1.b0=%u\n",
        n,ret,p1,side,idx,Bp,F54,mk,F0,mk0,PPC_LOAD_U8(0x884D95F1u),
        PPC_LOAD_U8(0x884D6CE8u),PPC_LOAD_U16(0x884D6CEAu),PPC_LOAD_U8(0x884D6DACu));
      // Deep dump (once): all F54 rows for idx 0/1, the parallel lives/data table (B+0x14c), and the
      // systemobj TEMPLATE (0x884D6ED8, the memcpy source) — to find where -1 lives / where 4B comes from.
      static int deep=0; if(deep++<2){
        for(uint32_t F=0;F<4;F++) for(uint32_t ix=0;ix<2;ix++){
          uint32_t bb=((ix*3u+F)*0xB4u)+B0+0x190u; char row[64];int ro=0;
          for(int k=0;k<5;k++)ro+=std::snprintf(row+ro,sizeof(row)-ro,"%02X ",PPC_LOAD_U8(bb+(uint32_t)k*0x24u));
          std::fprintf(stderr,"[joindeep] mk F=%u ix=%u @0x%X [%s]\n",F,ix,bb,row);
        }
        // parallel lives/data table: accessor sub_88134910 reads ((idx*3+F)*5 + slotidx)*0x24 + B + 0x14c
        for(uint32_t slotidx=1;slotidx<=5;slotidx++){
          uint32_t a=(((0u*3u+F0)*5u)+slotidx)*0x24u + B0 + 0x14Cu;
          std::fprintf(stderr,"[joindeep] lives ix0 slot%u @0x%X +14c=0x%X +158=0x%X +15c=0x%X +160=0x%X\n",
            slotidx,a,PPC_LOAD_U32(a),PPC_LOAD_U32(a+0xCu),PPC_LOAD_U32(a+0x10u),PPC_LOAD_U32(a+0x14u));
        }
        // template @0x884D6ED8 slot markers (row F54=0, idx0)
        uint32_t tb=0x884D6ED8u+0x190u; char tr[64];int to=0;
        for(int k=0;k<5;k++)to+=std::snprintf(tr+to,sizeof(tr)-to,"%02X ",PPC_LOAD_U8(tb+(uint32_t)k*0x24u));
        std::fprintf(stderr,"[joindeep] TEMPLATE(6ED8) mk ix0 @0x%X [%s]\n",tb,tr);
      }
    }
  }
  if(on && g_in_id47.load()>0 && ctx.r3.u64==0 && (both || PPC_LOAD_U8(0x884D95F1u)==0)){
    ctx.r3.u64=1;
    static int fp=0; if(fp++<8) std::fprintf(stderr,"[forceplayer] id47 slot-scan returned 0 -> forced slot live (r3 0->1, obj17_pre=%u)\n",PPC_LOAD_U8(0x884D95F1u));
  }
}
extern "C" void __imp__sub_880FBB08(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_880FBB08){
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  g_in_id47.fetch_add(1);
  // GATE (workflow finding): id47 installs the gameplay update/draw ONLY if object+17 (0x884D95F1,
  // = count of LIVE player slots) != 0. In merged it's suspected 0 (RT_SLOT2FIX skipped player-join)
  // => early-return, no gameplay drawer => near-black. Log it before/after + the parent player state.
  uint32_t parent=ctx.r4.u32;                       // r4=arg = the FSM/parent block (0x884D6740)
  uint8_t o17_pre=PPC_LOAD_U8(0x884D95F1u);
  uint8_t slot0=PPC_LOAD_U8(parent+1448u), slot1=PPC_LOAD_U8(parent+1449u);
  uint32_t p128=PPC_LOAD_U32(parent+128u);
  std::fprintf(stderr,"[gpfac] id47 sub_880FBB08 CALL#%ld r3=0x%X parent=0x%X | obj17(0x884D95F1)=%u slot@+1448=%u/%u p128=0x%X\n",
    i,ctx.r3.u32,parent,o17_pre,slot0,slot1,p128);
  __imp__sub_880FBB08(ctx,base);
  g_in_id47.fetch_sub(1);
  std::fprintf(stderr,"[gpfac] id47 RET#%ld obj17_post=%u (0=EARLY-RETURN no drawer; !=0=drawer installed)\n",i,PPC_LOAD_U8(0x884D95F1u));
}
// [gpdraw] the id46 gameplay DRAWER sub_88226EB0 (installed at registry-node+12; emits ~81 draws
// via sub_881538C0). WORKFLOW FINDING: it early-returns (skips the draw loop) if any of bits
// 0x10/0x20/0x40/0x8000 is set in *(FLAG+4)|*(FLAG+92) where FLAG=0x885C33D0 (lis -30628 +13264).
// Bit 0x8000=START — our input injection (RT_PAD/RT_STARTFSM/RT_NATPLAY writes 0x885C33D8/3430)
// may set the pause bit -> drawer pauses -> near-black. Log call-rate + the gate words + verdict.
extern "C" void __imp__sub_88226EB0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88226EB0){
  static std::atomic<long long> n{0}; long long i=n.fetch_add(1)+1;
  uint32_t f4c=PPC_LOAD_U32(0x885C33D4u), f92c=PPC_LOAD_U32(0x885C342Cu);   // 0x885C33D0 +4/+92
  uint32_t f4a=PPC_LOAD_U32(0x885A33D4u), f92a=PPC_LOAD_U32(0x885A342Cu);   // 0x885A33D0 +4/+92 (alt)
  uint32_t maskc=(f4c|f92c)&0x8070u, maska=(f4a|f92a)&0x8070u;
  if(i<=12||i%600==0) std::fprintf(stderr,"[gpdraw] sub_88226EB0 tick#%lld this(r3)=0x%X arg(r4)=0x%X CALLER_lr=0x%X | pausebits 33D0=0x%X 5A=0x%X %s\n",
    i,ctx.r3.u32,ctx.r4.u32,(uint32_t)ctx.lr,maskc,maska, (maskc||maska)?"<==WOULD PAUSE":"draws");
  __imp__sub_88226EB0(ctx,base);
}
// [gpupd] the GAMEPLAY per-frame UPDATE installed at registry-node+12 by the id47 factory
// (sub_880FA720). If it ticks each frame, game logic runs -> sprites/draws emitted. If it never
// fires, the per-frame walker of the registry list *(0x88449D4C) isn't reaching the gameplay node.
extern "C" void __imp__sub_880FA720(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_880FA720){
  static std::atomic<long long> n{0}; long long i=n.fetch_add(1)+1;
  if(i<=5||i%600==0) std::fprintf(stderr,"[gpupd] gameplay-update sub_880FA720 tick#%lld r3=0x%X\n",i,ctx.r3.u32);
  __imp__sub_880FA720(ctx,base);
}
// [reg] the drawer-REGISTER fns (sub_880938F0/sub_880939F0 push a per-frame callback into the
// sub_88093950-ticked deferred list). Log caller lr — a registration with lr inside the id46/47
// factory (0x88227xxx / 0x880FBxxx) or right after them = the gameplay drawer being installed.
// RT_REG-gated (fires a lot). Also flag registrations whose caller is in the gameplay-factory range.
extern "C" void __imp__sub_880938F0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_880938F0){
  static bool on=std::getenv("RT_REG")!=nullptr;
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  uint32_t lr=(uint32_t)ctx.lr; bool gp=(lr>=0x88227000&&lr<0x88228000)||(lr>=0x880FB000&&lr<0x880FC000);
  if(on && (i<=15 || gp || i%1000==0))
    std::fprintf(stderr,"[reg] sub_880938F0 #%ld lr=0x%X r3=0x%X r4=0x%X r5=0x%X%s\n",i,lr,ctx.r3.u32,ctx.r4.u32,ctx.r5.u32, gp?"  <==FROM GAMEPLAY FACTORY":"");
  __imp__sub_880938F0(ctx,base);
}
extern "C" void __imp__sub_880939F0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_880939F0){
  static bool on=std::getenv("RT_REG")!=nullptr;
  static std::atomic<long> n{0}; long i=n.fetch_add(1)+1;
  uint32_t lr=(uint32_t)ctx.lr; bool gp=(lr>=0x88227000&&lr<0x88228000)||(lr>=0x880FB000&&lr<0x880FC000);
  if(on && (i<=15 || gp || i%1000==0))
    std::fprintf(stderr,"[reg] sub_880939F0 #%ld lr=0x%X r3=0x%X r4=0x%X r5=0x%X%s\n",i,lr,ctx.r3.u32,ctx.r4.u32,ctx.r5.u32, gp?"  <==FROM GAMEPLAY FACTORY":"");
  __imp__sub_880939F0(ctx,base);
}

// RT_JOINP scene-sequencer probe: sub_880EA968 = the ROM scene FSM that gates 67cc-clear (case 0xC)
// on the mode-select/char-select scene chain (case2 waits 0f4, case4 waits 0f0, case6 waits 0f8=
// char-select state7). Log its per-object state + the three anim flags so we can see WHERE it stalls
// after the join. Object state = piVar10[1] via the 0x88449d4c list keyed by FUN_88071158().
extern "C" void __imp__sub_880EA968(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_880EA968){
  if(std::getenv("RT_JOINP")){
    // replicate the object lookup: iVar3=FUN_88071158() return is r3 after call; instead read via the
    // list head 0x88449d4c, entry+8==key. We can't cheaply call FUN_88071158 here, so just log flags +
    // the char-select FSM state; the state itself is dumped by scanning the list for any node.
    uint32_t f4=PPC_LOAD_U32(0x887AD0F4u), f0=PPC_LOAD_U32(0x887AD0F0u), f8=PPC_LOAD_U32(0x887AD0F8u);
    uint32_t cs=PPC_LOAD_U32(0x884EA3DCu), g67cc=PPC_LOAD_U32(0x884D67CCu), d76=PPC_LOAD_U16(0x884D678Cu);
    // Installer FUN_880eaf58 pins ctx = 0x884EA1A0 (record[7]); state u16 @+4, countdown u16 @+6.
    // The old list-walk grabbed the FIRST plausible node (wrong scene) — read the pinned ctx instead.
    uint32_t st=PPC_LOAD_U16(0x884EA1A4u), cdn=PPC_LOAD_U16(0x884EA1A6u);
    uint32_t hseq=PPC_LOAD_U32(0x884D6748u); // sequencer scene handle (created @125334 with d76:=2)
    static std::atomic<uint32_t> ticks{0}; uint32_t tk=ticks.fetch_add(1)+1;
    static uint64_t lk=~0ull; uint64_t key=((uint64_t)(st&0xFF))|((uint64_t)(f4!=0)<<8)|((uint64_t)(f0!=0)<<9)
      |((uint64_t)(f8!=0)<<10)|((uint64_t)(cs&0xF)<<11)|((uint64_t)(g67cc!=0)<<15)|((uint64_t)(d76&0xF)<<16)
      |((uint64_t)(hseq!=0)<<20);
    if(key!=lk || tk%300==0){ lk=key;
      std::fprintf(stderr,"[seq] 880EA968 tick#%u ctxstate=%u cdn=%u hseq=%08X | 0f4=%u 0f0=%u 0f8=%u | csfsm=%u 67cc=%u d76=%u\n",
        tk,st,cdn,hseq,f4,f0,f8,cs,g67cc,d76); }
  }
  __imp__sub_880EA968(ctx,base);
}
// [csa] RT_JOINP companion (2026-07-23 sequencer leg, Fable-5): sub_880EE880 = the char-select
// intro scene tick (installed by init sub_880F09F8 @82370; created by the sequencer's case 1 as
// scene id 0x31). Its FSM DAT_884E7D5C must reach case 10 to set 0f4=1 (the flag the sequencer's
// case 2 waits on). Log state transitions + a call heartbeat so we can tell "never ticked" from
// "ticking but stuck in an early case".
extern "C" void __imp__sub_880EE880(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_880EE880){
  if(std::getenv("RT_JOINP")){
    static std::atomic<uint32_t> n{0}; uint32_t k=n.fetch_add(1)+1;
    uint32_t st=PPC_LOAD_U32(0x884E7D5Cu), cd=PPC_LOAD_U32(0x884E7D60u), sub=PPC_LOAD_U32(0x884E7D7Cu);
    static uint32_t lastSt=0xFFFFFFFF;
    if(st!=lastSt || k%300==0){ lastSt=st;
      std::fprintf(stderr,"[csa] 880EE880 call#%u 7d5c=%u 7d60=%u 7d7c=%u 0f4=%u\n",
        k,st,cd,sub,PPC_LOAD_U32(0x887AD0F4u)); }
  }
  __imp__sub_880EE880(ctx,base);
}
// ══ RT_NOPAUSE spin-breaker (2026-07-23 sequencer leg, Fable-5) ═════════════════════════════════
// ROOT CAUSE of the post-join freeze (full chain, runtime-proven): GameEntry msg 10 (case 9,
// reco:305096) = the shell's PAUSE control -> 887AD534=arg, 887AD538=0. fb90's outer
// `while(534!=0 && 538==0)` then spins INSIDE one call: the game main keeps servicing the
// frame handshake (fa68 sets / WaitMulti consumes evt 0x...34 at 60Hz -> looks alive) but never
// reaches fb90's tail -> (*887AD524)()=sub_88168C80 never runs -> gate 887AC958 never clears ->
// outer FSM/scene pump/sequencer all starve (67cc never clears, d76 parked). The ONLY game-side
// resume is msg 10 arg=0, which this flow never sends. RT_NOPAUSE's entry-clear can't help once
// the thread is trapped inside the spin — but the spin body calls cb3 = shell FUN_821c5618 every
// iteration ON THE SPINNING THREAD, so clearing 534 here is exactly the resume the shell would
// deliver. Same lever (RT_NOPAUSE), new reach.
// (Implementation lives in the existing sub_821C5618 wrapper below — [cb2gate] — which already
// owns this override; the clear is merged there.)
// ══ RT_STARTWIRE (2026-07-23 JOIN leg, Fable-5) — register-true 1P-START host wiring ═══════════
// ROOT CAUSE (runtime + reco confirmed): the char-select JOIN needs game bit 0x8000 (arcade
// 1P-START) in the P1 input edge 0x885C33D8. That bit = host EXCH byte 0x88699894 bit 0x08 via the
// encoder FUN_8808e7d8. The shell input object's remapper (cb3 FUN_821c5618 -> vtable[0x6c]) only
// emits the joystick/dpad host bits (0x10..0x80); NOTHING emits host-0x08, so no gamepad button
// ever reaches the 1P-START/JOIN line. The arcade cabinet wired a physical START button to that
// line — so completing that wiring host-side IS register-true (per the leg brief). This hook runs
// at the per-frame input compose FUN_8808f2c0 (which reads EXCH 0x88699894 via the encoder and
// writes P1 LEVEL 0x887AD5B0): when the port's START button is held (g_rt_startline), OR host-bit
// 0x08 into the P1 EXCH byte so the encoder produces game 0x8000. The player must still press START;
// this only supplies the input line the port's shell encoder was missing (NOT an FSM force).
#ifndef FUTARI_IN_MODULE_DLL
extern std::atomic<int> g_rt_startline;   // stubs.cpp — START (wButton 0x10) LEVEL for P1
#endif                                    // (in a DLL it is a macro over the bound host pointer)
extern "C" void __imp__sub_8808F2C0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_8808F2C0){
  static bool on = std::getenv("RT_STARTWIRE")!=nullptr;
  if(on && g_rt_startline.load(std::memory_order_relaxed)){
    uint32_t ex=PPC_LOAD_U32(0x88699894u);
    if((ex & 0x08u)==0){ PPC_STORE_U32(0x88699894u, ex | 0x08u);
      static std::atomic<int> z{0}; int q=z.fetch_add(1);
      if(q<8) std::fprintf(stderr,"[startwire] OR host-0x08 into EXCH 0x88699894 (was 0x%08X) -> game 0x8000 (1P-START)\n",ex); }
  }
  __imp__sub_8808F2C0(ctx,base);
}
// ══ RT_JOINP (2026-07-23 JOIN leg, Fable-5) — char-select JOIN gate probe ══════════════════════
// The join is a TWO-TIER gate (both tiers share an outer scene-busy check):
//   FUN_88103048 @92888 outer: gs_busy(674c)==0 && DAT_884d6870==0 ; @92904 inner: (33d8&0x8000)
//     && widget+0x744!=2 && a13==0  -> calls FUN_881366d0(slot)
//   FUN_881366d0 @124387 executor: gs_busy(674c)==0 && 6870==0 && 6878==0 ; per-slot guard
//     *(0x884D6740+slot*4+0x3c)==0 -> sets join flag *(0x884D6740+slot*0xC4+0x5A8) & drives 880920e0
// gs_busy() faithfully replicates FUN_88152b00 (reco 142484): registry at 0x88449A20, stride 20,
// count 0x88449D40, match tag at +4 => busy if +12!=0; else scan list head 0x88449D4C (next=[0],
// tag=[8]). This measures the exact operand the RT_DECIDE negative never cleared (the outer gate).
static int rt_gs_busy(uint8_t* base, uint32_t tag){
  if(tag==0) return 0;
  uint32_t cnt=PPC_LOAD_U32(0x88449D40u), p=0x88449A20u;
  for(uint32_t i=0;i<cnt;i++){ if(PPC_LOAD_U32(p+4)==tag){ if(PPC_LOAD_U32(p+12)!=0) return 1; break; } p+=20; }
  for(uint32_t node=PPC_LOAD_U32(0x88449D4Cu); node; node=PPC_LOAD_U32(node)){ if(PPC_LOAD_U32(node+8)==tag) return 1; }
  return 0;
}
// ══ RT_DECIDE (2026-07-23 FREE-PLAY INPUT leg, Fable-5) — DIAGNOSTIC ═══════════════════════════
// The select confirm FUN_88103048 (reco 92904) fires the join ONLY if (33d8 & 0x8000) &&
// widget+0x744 != 2 && DAT_88449a13 == 0. Runtime shows a13=1 at char-select (blocks it) AND the
// scripted FIFO never delivers game-bit 0x8000. This lever isolates the confirm LOGIC from both:
// at the confirm's own entry it (a) forces a13=0 and (b) injects a clean, spaced 0x8000 edge into
// the per-player 33d8 word. If the character then confirms (widget+0x744 climbs 0->1->2, +352 sets,
// d76 leaves 2), the confirm path is intact and the true blockers are exactly {a13, 0x8000 delivery}.
// Default-off, diagnostic only (NOT a ship fix — a real decide edge must come from the pad).
extern "C" void __imp__sub_88103048(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88103048){
  static const bool rtJoinP = std::getenv("RT_JOINP")!=nullptr;
  if(rtJoinP){
    uint32_t out=PPC_LOAD_U32(0x884D66A8u);
    if(out==5u){
      uint32_t W=PPC_LOAD_U32(ctx.r4.u32+0x2cu);
      uint32_t v744=(W>=0x82000000u&&W<0x8B000000u)?PPC_LOAD_U32(W+0x744u):0xFFFFFFFFu;
      uint32_t t674c=PPC_LOAD_U32(0x884D674Cu); int busy=rt_gs_busy(base,t674c);
      uint32_t g6870=PPC_LOAD_U32(0x884D6870u);
      uint32_t a13=PPC_LOAD_U8(0x88449A13u), g598=PPC_LOAD_U32(0x887AD598u), g6828=PPC_LOAD_U32(0x885C6828u);
      uint32_t d8=PPC_LOAD_U32(0x885C33D8u), d4=PPC_LOAD_U32(0x885C33D4u), exch=PPC_LOAD_U32(0x88699894u);
      bool outer=(busy==0 && g6870==0);
      bool inner=((d8&0x8000)!=0 && v744!=2 && a13==0);
      static uint64_t lk=~0ull; static int lc=-1000; static std::atomic<int> nn{0}; int n=nn.fetch_add(1);
      uint64_t key=((uint64_t)(busy!=0))|((uint64_t)(g6870!=0)<<1)|((uint64_t)(a13!=0)<<2)|((uint64_t)(g598!=0)<<3)
        |((uint64_t)((d8&0x8000)!=0)<<4)|((uint64_t)(v744&3)<<5)|((uint64_t)(d4&0xFFFF)<<7)|((uint64_t)((exch&0xFF))<<23);
      static int cbp=0; if(!cbp){ cbp=1; std::fprintf(stderr,"[joinp] cb3(887ad5a8)=0x%08X cb3ctx(5ac)=0x%08X cb4(4d8)=0x%08X\n",
        PPC_LOAD_U32(0x887AD5A8u),PPC_LOAD_U32(0x887AD5ACu),PPC_LOAD_U32(0x887AD4D8u)); }
      if(key!=lk || n-lc>=90){ lk=key; lc=n;
        std::fprintf(stderr,"[joinp] 88103048 674c=0x%X busy=%d 6870=%u | a13=%u 598=%u 6828=0x%X | 33d8=0x%08X 33d4=0x%08X EXCH94=0x%08X W+744=%d | OUTER=%s INNER=%s\n",
          t674c,busy,g6870,a13,g598,g6828,d8,d4,exch,(int)v744,outer?"OPEN":"BLOCK",inner?"ready":"no");
      }
    }
  }
  static const bool rtDecide = std::getenv("RT_DECIDE")!=nullptr;
  if(rtDecide){
    static std::atomic<long long> n{0}; long long i=n.fetch_add(1)+1;
    uint32_t sess=PPC_LOAD_U16(0x884D678Cu), out=PPC_LOAD_U32(0x884D66A8u);
    if(out==5u && sess<=4u){
      PPC_STORE_U8(0x88449A13u, 0);                 // clear the a13 confirm-gate
      // player index = *(char*)(FUN_8807113c()+1); P1 word = 0x885C33D8. Pulse a single-frame
      // 0x8000 edge every ~110 confirm-calls (release between so the edge is clean).
      long long ph = i % 110;
      if(ph==0){ PPC_STORE_U32(0x885C33D8u, PPC_LOAD_U32(0x885C33D8u)|0x8000u);
        static std::atomic<int> p{0}; int q=p.fetch_add(1);
        if(q<12) std::fprintf(stderr,"[decide] pulse#%d inject 33d8|=0x8000 @sess=%u (a13 forced 0)\n",q,sess);
      }
    }
  }
  // ══ RT_744P (2026-07-24 +744-WRITER leg, Fable-5) — object-identity + before/after on the confirm ══
  // The confirm-widget commit gate (FSM sub_8814f558 case 8) needs *(DAT_8844a3a8+0x744)==2, but the
  // per-tap confirm here reads/writes *(r4+0x2c)+0x744. If Wc(=*(r4+0x2c)) != Wf(=DAT_8844a3a8) the two
  // are DIFFERENT objects -> confirms land on an object the FSM never reads (the folded-base/object-
  // identity miss). Also captures +744 and the per-page confirm counters +0x73c..0x740 before AND after
  // the real body: does the confirm CALL TREE (FUN_881366d0/881332e8) touch +744 at all? Default-off.
  bool p744on = std::getenv("RT_744P")!=nullptr;
  uint32_t P_Wc=0,P_pre744=0xFFFFFFFFu,P_pre73c=0; bool P_valid=false; uint32_t P_edge=0;
  if(p744on){
    P_Wc=PPC_LOAD_U32(ctx.r4.u32+0x2cu);
    P_valid=(P_Wc>=0x82000000u&&P_Wc<0x8B000000u);
    P_edge=PPC_LOAD_U32(0x885C33D8u)&0x8000u;
    if(P_valid){ P_pre744=PPC_LOAD_U32(P_Wc+0x744u); P_pre73c=PPC_LOAD_U32(P_Wc+0x73cu); }
  }
  __imp__sub_88103048(ctx,base);
  if(p744on && P_valid){
    uint32_t post744=PPC_LOAD_U32(P_Wc+0x744u), post73c=PPC_LOAD_U32(P_Wc+0x73cu);
    uint32_t Wf=PPC_LOAD_U32(0x8844A3A8u);
    bool changed=(post744!=P_pre744)||(post73c!=P_pre73c);
    static std::atomic<int> once{0};
    if(changed || P_edge || once.fetch_add(1)<40)
      std::fprintf(stderr,"[744p] 88103048 Wc=%08X Wf(a3a8)=%08X %s edge8000=%u | +744 %u->%u  +73ccnt %08X->%08X\n",
        P_Wc,Wf,(P_Wc==Wf)?"SAME-OBJ":"DIFF-OBJ",P_edge?1:0,P_pre744,post744,P_pre73c,post73c);
  }
}
// ══ RT_744P wrappers (2026-07-24 +744-WRITER leg, Fable-5) ═════════════════════════════════════
// (1) sub_881332E8 = per-page confirm-counter bump: iVar1=*(r3+0x80); *((iVar1+*(iVar1+0x58))+0x73c)++.
//     The init sub_8814fdf8 reads Wf+0x73c/+0x73e/+0x740 (page 0/2/4 counters) — so the counter base
//     (iVar1) MUST equal Wf(=DAT_8844a3a8) for the confirm to register on the object the FSM reads.
extern "C" void __imp__sub_881332E8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_881332E8){
  bool on=std::getenv("RT_744P")!=nullptr;
  uint32_t b80=0,cntobj=0,pre=0; bool valid=false;
  if(on){
    uint32_t r3=ctx.r3.u32;
    if(r3>=0x1000u&&r3<0xFFFF0000u) b80=PPC_LOAD_U32(r3+0x80u);
    if(b80>=0x82000000u&&b80<0x8B000000u){
      cntobj=b80+PPC_LOAD_U32(b80+0x58u);
      valid=(cntobj>=0x82000000u&&cntobj<0x8B000000u);
      if(valid) pre=PPC_LOAD_U8(cntobj+0x73cu);
    }
  }
  __imp__sub_881332E8(ctx,base);
  if(on && valid){
    uint32_t Wf=PPC_LOAD_U32(0x8844A3A8u);
    uint32_t post=PPC_LOAD_U8(cntobj+0x73cu);
    uint32_t w744=(Wf>=0x82000000u&&Wf<0x8B000000u)?PPC_LOAD_U32(Wf+0x744u):0xFFFFFFFFu;
    static std::atomic<int> c{0};
    if(c.fetch_add(1)<60 || post!=pre)
      std::fprintf(stderr,"[744p] 881332E8 b80=%08X cntobj=%08X Wf(a3a8)=%08X b80==Wf?%s | +73c %u->%u  Wf+744=%u\n",
        b80,cntobj,Wf,(b80==Wf)?"YES":"NO",pre,post,w744);
  }
}
// (2) sub_8814F558 = the confirm-widget FSM. POISON-WATCH *(Wf+0x744): log the exact frame/state it
//     changes (if ever). Plus the case-8 decision operands (a3cc/a3c8/d0) and the two disjuncts, so we
//     see WHY it takes back-out (case 10) vs credited (case 0xC): is it +744!=2, or a3cc!=5, etc.
extern "C" void __imp__sub_8814F558(PPCContext& __restrict, uint8_t*);
// [hb] RT_CR328 leg 3 (2026-07-25, Fable-5): liveness counters. Leg-2 verdict: on NORMAL PLAY the
// whole side-panel subsystem (88137498 tail dispatch -> [ff0], 8814D400 tick -> [b378] processor)
// STOPS BEING CALLED ~27 frames after the 2nd decide (job-2 ramp dies at rec64=10; no heartbeats
// for the rest of the run), while the game keeps running. These counters + the [hb] emitter in
// sub_88104230 (coin-display tick pr32, alive to run end) name the layer that dies and when.
// Counters always increment (cheap atomics); output RT_S5-gated.
static std::atomic<uint32_t> g_hb_708{0}, g_hb_498{0}, g_hb_ff0{0}, g_hb_b378{0}, g_hb_d400{0}, g_hb_f558{0};
PPC_FUNC(sub_8814F558){
  g_hb_f558.fetch_add(1);
  bool on=std::getenv("RT_744P")!=nullptr;
  uint32_t Wf=0,lvl=0xFFFFFFFFu; bool valid=false;
  if(on){
    Wf=PPC_LOAD_U32(0x8844A3A8u); valid=(Wf>=0x82000000u&&Wf<0x8B000000u);
    if(valid) lvl=PPC_LOAD_U32(Wf+0x744u);
    // page-advance trigger DAT_88353036: set 1 by the char-card confirm-complete FSM (241254 et al.),
    // consumed @25553 -> FUN_88136bc8(page+1). If it never flips to 1, the widget page never advances.
    static uint8_t lastAdv=0xEE; uint8_t adv=PPC_LOAD_U8(0x88353036u);
    if(adv!=lastAdv){ std::fprintf(stderr,"[744p] ### DAT_88353036(page-adv trigger) %u -> %u  csfsm=%u d76=%u\n",
      lastAdv,adv,PPC_LOAD_U32(0x884EA3DCu),PPC_LOAD_U16(0x884D678Cu)); lastAdv=adv; }
    static uint32_t lastLvl=0xEEEEEEEEu;
    if(valid && lvl!=lastLvl){
      std::fprintf(stderr,"[744p] *** Wf+744 CHANGED %u -> %u  fsm=0x%X csfsm=%u d76=%u +352=%u ***\n",
        lastLvl,lvl,PPC_LOAD_U32(0x8844A3B8u),PPC_LOAD_U32(0x884EA3DCu),PPC_LOAD_U16(0x884D678Cu),PPC_LOAD_U32(0x884D68A0u));
      lastLvl=lvl;
    }
    uint32_t fsm=PPC_LOAD_U32(0x8844A3B8u);
    static uint32_t lastFsm=0xEEEEEEEEu;
    if(fsm!=lastFsm || fsm==8){
      uint32_t a3cc=PPC_LOAD_U32(0x8844A3CCu), a3c8=PPC_LOAD_U32(0x8844A3C8u), d0=PPC_LOAD_U32(0x8844A3D0u);
      uint32_t shot=valid?PPC_LOAD_U32(Wf+0x760u):0;
      bool disj1=(a3cc==5), disj2=(a3cc!=a3c8 && lvl==2);
      static std::atomic<int> c8{0};
      if(fsm!=lastFsm || (fsm==8 && d0==0 && c8.fetch_add(1)<30))
        std::fprintf(stderr,"[744p] 8814F558 fsm=0x%X Wf=%08X a3cc=%u a3c8=%u d0=%u | +744=%u +760=0x%X | disj1(cc==5)=%d disj2(cc!=c8&744==2)=%d -> %s\n",
          fsm,Wf,a3cc,a3c8,d0,lvl,shot,disj1,disj2,(disj1||disj2)?"ADVANCE(0xC/0xD)":"BACKOUT(case10)");
      lastFsm=fsm;
    }
  }
  __imp__sub_8814F558(ctx,base);
}
// (2b) sub_88136BC8 = the PAGE-ADVANCE creator: sets W+0x5c(curpg)=param_2(page), re-creates the confirm
//     widget (scene id 0x2c). Called from the ROM sequencer case 0xC (page=seq[0x1c]) AND from the child-
//     tick loop @25553 when DAT_88353036!=0 (page=W+0x58+1). If the port only ever calls it with page 0
//     (never advancing), a3cc/a3c8 stay equal and the FSM backs out. Log page + W+0x58/+0x5c each call.
extern "C" void __imp__sub_88136BC8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88136BC8){
  if(std::getenv("RT_744P")){
    uint32_t page=ctx.r4.u32, W=ctx.r3.u32; bool v=(W>=0x82000000u&&W<0x8B000000u);
    std::fprintf(stderr,"[744p] 88136BC8 CREATE page=%u W=%08X pre[+58tgt=%u +5ccur=%u] adv353036=%u csfsm=%u d76=%u\n",
      page,W, v?PPC_LOAD_U32(W+0x58u):0, v?PPC_LOAD_U32(W+0x5cu):0,
      PPC_LOAD_U8(0x88353036u), PPC_LOAD_U32(0x884EA3DCu), PPC_LOAD_U16(0x884D678Cu));
  }
  __imp__sub_88136BC8(ctx,base);
}
// (3) sub_8814FDF8 = confirm-widget install (sets DAT_8844a3a8=param_2, captures pages from W+0x58/+0x5c).
//     Log every (re)install with the widget ptr + its page/mode fields so we can tell WHICH screen's
//     widget is live at shot-select and whether its a3cc/a3c8 pages set up the +744==2 path at all.
extern "C" void __imp__sub_8814FDF8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_8814FDF8){
  if(std::getenv("RT_744P")){
    uint32_t W=ctx.r4.u32; bool v=(W>=0x82000000u&&W<0x8B000000u);
    std::fprintf(stderr,"[744p] 8814FDF8 INSTALL W=%08X | +54(mode)=%u +58(tgtpg)=%u +5c(curpg)=%u +60=%u +744=%u csfsm=%u d76=%u\n",
      W, v?PPC_LOAD_U32(W+0x54u):0, v?PPC_LOAD_U32(W+0x58u):0, v?PPC_LOAD_U32(W+0x5cu):0,
      v?PPC_LOAD_U32(W+0x60u):0, v?PPC_LOAD_U32(W+0x744u):0,
      PPC_LOAD_U32(0x884EA3DCu), PPC_LOAD_U16(0x884D678Cu));
  }
  __imp__sub_8814FDF8(ctx,base);
}
// ══ RT_CARDFSM (2026-07-25 NORMAL-PLAY commit-gate leg, Fable-5) — the card-confirm-complete chain that
//    ARMS DAT_88353036 (the page-advance one-shot sub_88095950 consumes -> FUN_88136bc8(page+1)). Static
//    chain (reco_normal_decomp_all.txt): the char/shot CARD scene's confirm handler FUN_880a4b20
//    (collision/confirm trigger; scene root = *(param_2+0x900); reads selected-slot +0x9aa*4, lock
//    +0x9a9*4, countdown +0x99b*4) -> FUN_880a3ca8(case 1/2/3) [or poll FUN_880a3f98] ->
//    FUN_880969a8(root[6], 0x881f1968) spawns card-FSM entry sub_881f1968 -> registers 881ef798/881f0bc8
//    -> ticks to case 0x28 -> DAT_88353036=1. RT_744P proved the FSMs are ABSENT from the shot-select
//    drawlist; this probe finds WHERE the chain breaks (reached-vs-gated). Default-off, byte-inert.
static inline bool rt_cardfsm(){ static int v=std::getenv("RT_CARDFSM")?1:0; return v; }
extern "C" void __imp__sub_880A4B20(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_880A4B20){
  if(rt_cardfsm()){
    uint32_t ev=ctx.r3.u32, sc=ctx.r4.u32;
    uint32_t root=(sc>=0x1000u&&sc<0xFFFF0000u)?PPC_LOAD_U32(sc+0x900u):0;
    bool rv=(root>=0x1000u&&root<0xFFFF0000u);
    uint32_t sel=rv?PPC_LOAD_U32(root+0x9aa*4u):0xFFFFFFFFu;
    uint32_t lock=rv?PPC_LOAD_U32(root+0x9a9*4u):0xFFFFFFFFu;
    int32_t  cd=rv?(int32_t)PPC_LOAD_U32(root+0x99b*4u):-1;
    int32_t  thr=rv?(int32_t)PPC_LOAD_U32(root+0x9b5*4u):0;
    int32_t  dec=(ev>=0x1000u&&ev<0xFFFF0000u)?(int32_t)PPC_LOAD_U32(ev+4u):0;
    static uint64_t lk=~0ull; static std::atomic<int> c{0};
    uint64_t k=((uint64_t)(sel&0xFF))|((uint64_t)(lock!=0)<<8)|((uint64_t)((cd>>4)&0xFFFF)<<9);
    if(k!=lk || c.fetch_add(1)<25){ lk=k;
      std::fprintf(stderr,"[cardfsm] 880A4B20 TRIGGER root=%08X sel(9aa)=%u lock(9a9)=%u cd(99b)=%d thr(9b5)=%d evdec=%d csfsm=%u d76=%u\n",
        root,sel,lock,cd,thr,dec,PPC_LOAD_U32(0x884EA3DCu),PPC_LOAD_U16(0x884D678Cu));
    }
  }
  __imp__sub_880A4B20(ctx,base);
}
extern "C" void __imp__sub_880A3CA8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_880A3CA8){
  if(rt_cardfsm()){
    static std::atomic<int> c{0}; if(c.fetch_add(1)<40)
      std::fprintf(stderr,"[cardfsm] *** 880A3CA8 SPAWN-DISPATCH r3(case)=%u r4=%08X csfsm=%u d76=%u adv353036=%u\n",
        ctx.r3.u32,ctx.r4.u32,PPC_LOAD_U32(0x884EA3DCu),PPC_LOAD_U16(0x884D678Cu),PPC_LOAD_U8(0x88353036u));
  }
  __imp__sub_880A3CA8(ctx,base);
}
extern "C" void __imp__sub_880A3F98(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_880A3F98){
  if(rt_cardfsm()){
    static std::atomic<int> c{0};
    uint32_t root=PPC_LOAD_U32(0x887AD130u); bool rv=(root>=0x1000u&&root<0xFFFF0000u);
    if(c.fetch_add(1)<15)
      std::fprintf(stderr,"[cardfsm] 880A3F98 POLL root=%08X 66a0=%u sel(9aa)=%u cds[9bb=%d 9bc=%d 9bd=%d] locks[9aa=%u 9be=%d 9bf=%d 9c0=%d]\n",
        root,PPC_LOAD_U32(0x884D66A0u), rv?PPC_LOAD_U32(root+0x9aa*4u):0,
        rv?(int)PPC_LOAD_U32(root+0x9bb*4u):0, rv?(int)PPC_LOAD_U32(root+0x9bc*4u):0, rv?(int)PPC_LOAD_U32(root+0x9bd*4u):0,
        rv?PPC_LOAD_U32(root+0x9aa*4u):0, rv?(int)PPC_LOAD_U32(root+0x9be*4u):0, rv?(int)PPC_LOAD_U32(root+0x9bf*4u):0, rv?(int)PPC_LOAD_U32(root+0x9c0*4u):0);
  }
  __imp__sub_880A3F98(ctx,base);
}
extern "C" void __imp__sub_881F1968(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_881F1968){
  if(rt_cardfsm()){
    static std::atomic<int> c{0}; if(c.fetch_add(1)<20)
      std::fprintf(stderr,"[cardfsm] ***** 881F1968 CARD-FSM-CREATE (spawns 881ef798/881f0bc8) csfsm=%u d76=%u adv353036=%u\n",
        PPC_LOAD_U32(0x884EA3DCu),PPC_LOAD_U16(0x884D678Cu),PPC_LOAD_U8(0x88353036u));
  }
  __imp__sub_881F1968(ctx,base);
}
// (installer) sub_880A4628 sets obj+0x40=880a4190 tick + thresholds keyed on MODE(*(DAT_887ad130+0x54));
// records DAT_887ad120=card-mgr object. If this never fires the card-manager scene is never created.
extern "C" void __imp__sub_880A4628(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_880A4628){
  if(rt_cardfsm()){
    static std::atomic<int> c{0};
    uint32_t g130=PPC_LOAD_U32(0x887AD130u);
    std::fprintf(stderr,"[cardfsm] ##### 880A4628 CARD-MANAGER-INSTALL #%d mode(887ad130+54)=%u csfsm=%u d76=%u out=%u\n",
      c.fetch_add(1), (g130>=0x1000u&&g130<0xFFFF0000u)?PPC_LOAD_U32(g130+0x54u):0xFFFFFFFFu,
      PPC_LOAD_U32(0x884EA3DCu),PPC_LOAD_U16(0x884D678Cu),PPC_LOAD_U32(0x884D66A8u));
  }
  __imp__sub_880A4628(ctx,base);
}
// (tick) sub_880A4190 card-manager per-frame. Reads root=*(DAT_887ad120+0x900). Gate to spawn card FSM:
// [0x9ac](confirm-hold)!=0 && [0x9a9](lock)==0 && [0x99b](countdown)>0 && countdown<=[0x9b5](thr).
// [0x9ac]==0 => whole spawn path skipped. This probe reveals whether the card-mgr is LIVE and its gate.
extern "C" void __imp__sub_880A4190(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_880A4190){
  if(rt_cardfsm()){
    uint32_t obj=PPC_LOAD_U32(0x887AD120u);
    uint32_t root=(obj>=0x1000u&&obj<0xFFFF0000u)?PPC_LOAD_U32(obj+0x900u):0;
    bool rv=(root>=0x1000u&&root<0xFFFF0000u);
    uint32_t hold=rv?PPC_LOAD_U32(root+0x9ac*4u):0xEEEE;
    int32_t  cd =rv?(int32_t)PPC_LOAD_U32(root+0x99b*4u):-1;
    uint32_t slot=rv?PPC_LOAD_U32(root+0x9aa*4u):0xEE;
    uint32_t lock=rv?PPC_LOAD_U32(root+0x9a9*4u):0xEE;
    uint32_t done=rv?PPC_LOAD_U32(root+0x9a8*4u):0xEE;
    uint32_t hl =rv?PPC_LOAD_U32(root+0x982*4u):0;
    int32_t  thr=rv?(int32_t)PPC_LOAD_U32(root+0x9b5*4u):0;
    static uint64_t lk=~0ull; static std::atomic<int> c{0};
    uint64_t k=((uint64_t)(slot&0xFF))|((uint64_t)(lock!=0)<<8)|((uint64_t)(done!=0)<<9)|((uint64_t)(hold!=0)<<10)|((uint64_t)(((uint32_t)cd>>8)&0xFFFF)<<11);
    if(k!=lk || c.fetch_add(1)<10){ lk=k;
      std::fprintf(stderr,"[cardfsm] 880A4190 CARD-MGR-TICK obj=%08X root=%08X hold(9ac)=%u cd(99b)=%d thr(9b5)=%d slot(9aa)=%u lock(9a9)=%u done(9a8)=%u hitlist(982)=%08X csfsm=%u\n",
        obj,root,hold,cd,thr,slot,lock,done,hl,PPC_LOAD_U32(0x884EA3DCu));
    }
  }
  __imp__sub_880A4190(ctx,base);
}
extern "C" void __imp__sub_881EF798(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_881EF798){ if(rt_cardfsm()){ static std::atomic<int> c{0}; int q=c.fetch_add(1); if(q<8) std::fprintf(stderr,"[cardfsm] 881EF798 card-FSM TICK #%d adv353036=%u\n",q,PPC_LOAD_U8(0x88353036u)); } __imp__sub_881EF798(ctx,base); }
extern "C" void __imp__sub_881F0BC8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_881F0BC8){ if(rt_cardfsm()){ static std::atomic<int> c{0}; int q=c.fetch_add(1); if(q<8) std::fprintf(stderr,"[cardfsm] 881F0BC8 card-FSM TICK #%d adv353036=%u\n",q,PPC_LOAD_U8(0x88353036u)); } __imp__sub_881F0BC8(ctx,base); }
extern "C" void __imp__sub_881EB1F0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_881EB1F0){ if(rt_cardfsm()){ static std::atomic<int> c{0}; int q=c.fetch_add(1); if(q<8) std::fprintf(stderr,"[cardfsm] 881EB1F0 card-FSM TICK #%d adv353036=%u\n",q,PPC_LOAD_U8(0x88353036u)); } __imp__sub_881EB1F0(ctx,base); }
// [gmstage] (2026-07-23 sequencer leg): poor-man's stack sampler for the game-main freeze.
// Main-loop wrappers stamp g_gm_stage on ENTER/EXIT (odd=inside, even=returned); the tid is
// pinned by the sub_8813A738 wrapper (called once per main-loop iteration, main-loop only).
// The service-cb thread (sub_88090480, alive across the freeze) prints the stamp — whatever
// odd stage it shows post-freeze names the exact blocking callee.
// Stages: 1/2=8813A738  3/4=88091448  5/6=88138F00  7/8=88093950  9/10=88093418  11/12=8808FB90
std::atomic<int>  g_gm_stage{0};
std::atomic<long> g_gm_loop_tid{0};
std::atomic<long long> g_gm_frame_returns{0};   // 93418 EXITs on the main-loop tid (frame-wait returns)
std::atomic<long long> g_fa68_calls{0};         // frame-release (msg5 case-4) invocations
// [fa68] frame-release counter — the msg-5 side of the frame-lock ping-pong.
extern "C" void __imp__sub_8808FA68(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_8808FA68){
  g_fa68_calls.fetch_add(1);
  __imp__sub_8808FA68(ctx,base);
}
// [fb90] the frame-complete branch in sub_8808FB90 (ppc_recomp.4.cpp:14759 loc_8808FD08):
// gate-clear sub_88168C80 (via fn-ptr 0x887AD564) is SKIPPED when A=*(0x887AD534)!=0 && B=*(0x887AD538)==0.
// At frame ~7462 the branch flips to skip => gate 0x887AC958 never clears => game main spins.
// Log A/B/fnptr (throttled + on-change) to see WHICH flips at submit. RT_FB90-gated.
extern "C" void __imp__sub_8808FB90(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_8808FB90){
  static bool on=std::getenv("RT_FB90")!=nullptr;
  static std::atomic<long long> n{0}; long long i=n.fetch_add(1)+1;
  static uint32_t lA=0xDEAD,lB=0xDEAD;
  uint32_t A=PPC_LOAD_U32(0x887AD534u), B=PPC_LOAD_U32(0x887AD538u), fp=PPC_LOAD_U32(0x887AD564u);
  bool ch=(A!=lA||B!=lB); lA=A; lB=B;
  bool willskip = (A!=0 && B==0);
  if(on && (i<=20 || (i%4000)==0 || ch))
    std::fprintf(stderr,"[fb90] #%lld A(0x887AD534)=0x%X B(0x887AD538)=0x%X fnptr(0x887AD524)=0x%X gate=0x%X %s%s\n",
      i,A,B,PPC_LOAD_U32(0x887AD524u),PPC_LOAD_U32(GA_GM_FRAME_GATE), willskip?"WILL-SKIP-GATECLEAR":"do-clear", ch?"  <==CHANGED":"");
  // RT_NOPAUSE: the "frame-advance paused / transition-in-progress" flag A=*(0x887AD534) flips
  // 0->1 at submit and never clears in merged, so sub_8808FB90 skips the gate-clear -> game main
  // spins. Force it back to 0 so the game keeps advancing frames through the transition.
  static int nopause = std::getenv("RT_NOPAUSE")?atoi(std::getenv("RT_NOPAUSE")):0;
  if(nopause && PPC_LOAD_U32(0x887AD534u)!=0){ PPC_STORE_U32(0x887AD534u,0);
    static std::atomic<long long> z{0}; long long zz=z.fetch_add(1)+1;
    if(zz<=3||zz%2000==0) std::fprintf(stderr,"[nopause] cleared A(0x887AD534) #%lld\n",zz); }
  __imp__sub_8808FB90(ctx,base);
}

// ---- UNGATED game-chain trace (always on, no RT_DBGSPAWN check): sub_88087F88 (xapi entry)
// -> sub_8808F798 (pure trampoline: mtctr r3; bctrl) -> sub_88168D48 (real game main). All
// three are PPC_WEAK_FUNC aliases in the generated recomp .cpp (see ppc_recomp.3/.4.cpp);
// these thin PPC_FUNC(sub_X) overrides here win the weak-alias resolution at link time,
// same mechanism sub_821706E8 relies on below (C++ linkage, NOT extern "C" on the wrapper
// itself — only the __imp__ forward decl is extern "C"). Prefix `[gm]`. ----
extern "C" void __imp__sub_88087F88(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88087F88){
  std::fprintf(stderr,"[gm] sub_88087F88 ENTER r3=0x%X r4=0x%X\n",ctx.r3.u32,ctx.r4.u32);
  __imp__sub_88087F88(ctx,base);
  std::fprintf(stderr,"[gm] sub_88087F88 EXIT r3=0x%X\n",ctx.r3.u32);
}

extern "C" void __imp__sub_8808F798(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_8808F798){
  std::fprintf(stderr,"[gm] sub_8808F798 ENTER r3=0x%X\n",ctx.r3.u32);
  __imp__sub_8808F798(ctx,base);
  std::fprintf(stderr,"[gm] sub_8808F798 EXIT r3=0x%X\n",ctx.r3.u32);
}

// sub_88168D48: the real game main (ctx passed to the thread runner sub_8808F798). Ungated
// ENTER/EXIT trace (always fires; was RT_DBGSPAWN-gated before — that gating never observed
// an ENTER despite the chain above running to ExTerminateThread, hence making it unconditional).
extern "C" void __imp__sub_88168D48(PPCContext& __restrict, uint8_t*);
static std::atomic<long long> g_168d48_calls{0};
// RT_ROMRENDER (2026-07-15, attract-render): 1 once the arcade ROM main (sub_88168D48) is running, so
// rt.cpp can route the ROM's PM4 render (attract AND field) to the legacy spine — not just on the guest
// field_active flag (0x885C1A20), which the legal/ranking ATTRACT screens never set. Distinct from
// g_rt_realstage (that gates the one-shot RVK_ARENADUMP to the REAL stage; this gates LIVE routing).
// False during the shell front-end menus (ROM main not entered yet) so those keep the hook render.
// L4/E6: the DEFINITION moved to merged_bridge.cpp (host side).  This TU becomes DLL-resident,
// and vk_render.cpp / shell/gen/rt.cpp / merged_shell.cpp all read this flag — a per-DLL copy
// would link cleanly (vk_render has a weak fallback definition) and be permanently 0 on the host
// side.  Inside a DLL the name is a macro over the bound host pointer (merged_common.h); in the
// two per-module exes nothing changes except which .cpp owns the storage.
// (declaration comes from merged_common.h in an exe build, or the macro in a DLL build)
// js_state_name() MOVED to merged_shell.cpp at L3 stage 1 together with the [jankstate] /
// [janksum] emitters — see merged_common.h's rt_jankstate_* declarations.
PPC_FUNC(sub_88168D48){
  long long n = g_168d48_calls.fetch_add(1)+1;
  g_rt_romactive = 1;                    // ROM main entered -> ROM scene live (attract onward)
  rt_heapdump(base, "gm-enter");
  std::fprintf(stderr,"[gm] sub_88168D48 ENTER call#%lld r3=0x%X r4=0x%X\n",n,ctx.r3.u32,ctx.r4.u32);
  __imp__sub_88168D48(ctx,base);
  std::fprintf(stderr,"[gm] sub_88168D48 EXIT call#%lld r3=0x%X\n",n,ctx.r3.u32);
}

// sub_88168C80: the ONLY clearer of the game main's per-frame gate flag 0x887AC958 (the game
// main busy-spins in loc_88168F80 until this runs). It has zero bl-callers in the game tree —
// reached only via an indirect per-frame/vblank callback that the shell/kernel is expected to
// invoke. This wrapper traces whether our per-frame sub_821C3278 tick actually reaches it. If
// [gate] never fires while [gametick] does, the shell tick is NOT the gate-clear path and we
// must find/force the real one. Always-on trace, first 10 + every 600th.
extern "C" void __imp__sub_88168C80(PPCContext& __restrict, uint8_t*);
static std::atomic<long long> g_gate_clears{0};
PPC_FUNC(sub_88168C80){
  long long n=g_gate_clears.fetch_add(1)+1;
  static std::atomic<uint32_t> lastlr{0};
  uint32_t lr=(uint32_t)ctx.lr; uint32_t prev=lastlr.exchange(lr);
  bool caller_changed = (lr!=prev);
  // log first 10, every 600th, and whenever the caller LR changes (names the invoker).
  // (LEG-34: the n>=7000 flood window is retired — the "~7200 stop" is SOLVED: it was
  // sub_8808FB90 skipping the gate-clear when pause flag A=0x887AD534 flips to 1 and never
  // clears in merged; RT_NOPAUSE clears A and C80 then fires indefinitely.)
  if(n<=10 || (n%600)==0 || caller_changed)
    std::fprintf(stderr,"[gate] sub_88168C80 call#%lld  caller_lr=0x%X gate=0x%X%s\n",
      n,lr,PPC_LOAD_U32(GA_GM_FRAME_GATE), caller_changed?"  <==NEW CALLER":"");
  __imp__sub_88168C80(ctx,base);
  // [p1word] (2026-07-23 rapid-fire A/B): C80 derives the per-player input words; log the P1
  // HELD word 0x885C33D4 on CHANGE so a FIFO-injected RT (bit 0x40 = R.SHOT after the shell
  // binding resolver) or A (bit 0x10 = SHOT) is provable from the log. Change-only = quiet.
  {
    static std::atomic<uint32_t> lastw{0};
    uint32_t w=PPC_LOAD_U32(0x885C33D4u), pw=lastw.exchange(w);
    if(w!=pw) std::fprintf(stderr,"[p1word] held 0x%X -> 0x%X (rshot=%d shot=%d)\n",
      pw,w,(w>>6)&1,(w>>4)&1);
  }
  // [fade] (2026-07-24 menu-glitch leg): the outer FSM tail draws ~80 blend quads per frame
  // while fade byte DAT_884d66cc != 0. The now-completing EEPROM boot chain arms it (state 4:
  // 66cc=0xff); if the glyph/fade scene never finishes, it sticks/strobes over the ROM/menu
  // layer. Change-only sample of 66cc/66d0 = bounded by real fade activity.
  {
    static std::atomic<uint64_t> lastf{~0ull};
    uint64_t f=((uint64_t)PPC_LOAD_U32(0x884D66CCu)<<32)|PPC_LOAD_U32(0x884D66D0u);
    uint64_t pf=lastf.exchange(f);
    if(f!=pf) std::fprintf(stderr,"[fade] 66cc=0x%X 66d0=0x%X 66d4=0x%X\n",
      PPC_LOAD_U32(0x884D66CCu),PPC_LOAD_U32(0x884D66D0u),PPC_LOAD_U32(0x884D66D4u));
  }
  // [jank] (2026-07-24 menu-glitch oracle): C80 ticks once per guest frame, so host time between
  // consecutive calls = the real frame cadence. A deviant frame (delta outside [12ms,21ms] once
  // warmed up) is measurable judder we can catch headless instead of by eye. Per-deviant one-liner
  // (with the fade byte, to correlate jank with fade-armed windows) + a 5s rolling summary.
  static const bool rtMenuJank = std::getenv("RT_MENUJANK")!=nullptr;   // per-frame hook: cache the lever
  if(rtMenuJank){
    using clk=std::chrono::steady_clock;
    static bool inited=false;
    static clk::time_point last, wstart;
    static long long fcount=0, wslow=0; static long long wmaxd=0; static long long wsumd=0, wframes=0;
    clk::time_point now=clk::now();
    // [jankstate] change-only join line: whenever the menu model's state fn OR the live
    // confirm-task / kind-2-dialog count changes, emit it WITH the instantaneous frame delta so
    // the exact frame a transition lands is timestamped against fps. (Q1 discriminator.)
    // L3 stage 1: the three g_js_* counters are SHELL-side state (written by shell hooks) and
    // this read was the only thing keeping them alive across the module line (l2_split_notes
    // §6.1). The sample + change-latch + both fprintf's now live in merged_shell.cpp; this half
    // only supplies its own frame cadence.  Output is byte-identical: rt_jankstate_tick()
    // samples once and caches the triple for the summary line, exactly as the old single
    // in-line sample did.
    if(!inited){ inited=true; last=now; wstart=now; fcount=1; }
    else{
      long long d=std::chrono::duration_cast<std::chrono::microseconds>(now-last).count();
      last=now; ++fcount; ++wframes; wsumd+=d; if(d>wmaxd) wmaxd=d;
      rt_jankstate_tick(fcount,d);
      if(fcount>3 && (d>21000 || d<12000)){
        ++wslow;
        std::fprintf(stderr,"[jank] d=%lldus n=%lld fade66cc=0x%X\n",
          d,fcount,PPC_LOAD_U32(0x884D66CCu));
      }
      // 1s summary window (was 5s) for temporal resolution: carries the state snapshot so fps is
      // plotted directly against menu state + alive counts, and a task-death->fps-recovery shows.
      long long we=std::chrono::duration_cast<std::chrono::milliseconds>(now-wstart).count();
      if(we>=1000){
        long long meand = wframes? (wsumd/wframes) : 0;
        rt_jankstate_summary(wframes, wslow, wmaxd, meand);
        wstart=now; wslow=0; wmaxd=0; wsumd=0; wframes=0;
      }
    }
  }
}
// [rfmask] (2026-07-24 RT-rapid leg): sub_88134048 = the SHIP's per-object input-decode
// primitive (the only 33d4-family consumer the stage-segment scene bodies call). Its FIRST
// act is `if (DAT_88449a19 == 0) word &= ~0x40` — i.e. with the rapid-enable byte zero the
// R.SHOT bit is stripped before the ship ever sees it, which exactly matches the live
// symptom (p1word held 0x40 asserts, ship never fires). Probe: log pre/post words whenever
// the rapid bit is present on entry (change-only), plus the a19 byte. RT_RAPIDEN=1 is the
// DIAGNOSTIC A/B lever: force a19=1 before the original runs (not a ship fix — the
// register-true initializer of a19 is still unlocated; see the session note).
extern "C" void __imp__sub_88134048(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88134048){
  static int rapiden = std::getenv("RT_RAPIDEN") ? 1 : 0;
  if(rapiden) base[0x88449a19u] = 1;
  uint32_t p2=ctx.r4.u32, p3=ctx.r5.u32;
  uint32_t pre2=p2?PPC_LOAD_U32(p2):0, pre3=p3?PPC_LOAD_U32(p3):0;
  __imp__sub_88134048(ctx,base);
  uint32_t post2=p2?PPC_LOAD_U32(p2):0, post3=p3?PPC_LOAD_U32(p3):0;
  // RT_EEPROMLOG-gated: pre-words are caller stack garbage, so the change-only sig fired every
  // frame in menus (browse handlers call this per tick) — unbounded stderr flood. Default OFF.
  static const bool rtEepromLog = std::getenv("RT_EEPROMLOG")!=nullptr;   // per-tick input decode: cache the lever
  if(rtEepromLog){
    static std::atomic<long long> calls{0};
    long long n=calls.fetch_add(1)+1;
    static std::atomic<uint64_t> lastsig{~0ull};
    uint64_t sig=((uint64_t)pre2<<32)|post2;
    if(n<=3 || (((pre2|pre3)&0x40) && lastsig.exchange(sig)!=sig))
      std::fprintf(stderr,"[rfmask] call#%lld a19=%d held 0x%X->0x%X edge 0x%X->0x%X\n",
        n, base[0x88449a19u], pre2, post2, pre3, post3);
  }
}
// [eeprom] (2026-07-24 RT-rapid leg): the game's arcade-EEPROM/settings bring-up chain.
// sub_88100588 = storage state machine (state@ctx+0 walks 0->1->2->3->4->5); state 2 reads the
// save into the SHADOW block 0x887ac758 (0x200B), state 3 = sub_88100280 VALIDATOR (magic
// DAT_88062d50[0..3] + size word 0x1c at 887ac75c/5e; bad -> sub_88153DF8 FACTORY DEFAULTS,
// which is the ONLY boot-path writer of rapid-enable DAT_88449a19=1). sub_88153D18 = shadow->
// cluster RESTORE (save-backed a19). In the port the cluster stays all-zero at play (leg A),
// so this chain never completes — these wrappers name the dying stage.
#define RT_EEPROM_TRACE(fn) \
  extern "C" void __imp__##fn(PPCContext& __restrict, uint8_t*); \
  PPC_FUNC(fn){ \
    static std::atomic<long long> n{0}; long long c=n.fetch_add(1)+1; \
    if(c<=5 || (c%600)==0) std::fprintf(stderr,"[eeprom] " #fn " call#%lld a19=%d\n", c, base[0x88449a19u]); \
    __imp__##fn(ctx,base); }
// validator gets its own richer probe: log its context's flag(+0xc) and copy-counter(+0x34)
extern "C" void __imp__sub_88100280(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88100280){
  static std::atomic<long long> n{0}; long long c=n.fetch_add(1)+1;
  uint32_t cx=ctx.r3.u32;
  uint32_t f0=cx?PPC_LOAD_U32(cx+0xc):0, t0=cx?PPC_LOAD_U32(cx+0x34):0;
  __imp__sub_88100280(ctx,base);
  if(c<=40 || (c%600)==0)
    std::fprintf(stderr,"[eeprom] 280#%lld cx=0x%X flag %u->%u ctr %u->%u ret=%u a19=%d\n",
      c, cx, f0, cx?PPC_LOAD_U32(cx+0xc):0, t0, cx?PPC_LOAD_U32(cx+0x34):0,
      (uint32_t)ctx.r3.u32, base[0x88449a19u]);
}
RT_EEPROM_TRACE(sub_88153D18)
RT_EEPROM_TRACE(sub_88153DF8)
RT_EEPROM_TRACE(sub_88153BB0)
// [drawalloc] (2026-07-24 menu-glitch leg, RT_DRAWALLOC-gated): sub_88091DE8 = the ROM's
// draw-record allocator (everything on the ROM layer allocates sprites through it; returns 0
// on pool exhaustion). The now-completing boot chain draws the fullscreen FADE (~80 records/
// frame while 66cc!=0, outer-FSM tail) — if that exhausts the pool during menu transitions,
// OTHER menu elements fail to alloc and flicker = "menus glitching". Counts calls + NULLs,
// one line per ~2s + one line on every NULL-count change.
extern "C" void __imp__sub_88091DE8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88091DE8){
  static bool on = std::getenv("RT_DRAWALLOC")!=nullptr;
  if(!on){ __imp__sub_88091DE8(ctx,base); return; }
  static std::atomic<long long> calls{0}, nulls{0};
  static std::atomic<long> lastlog{0};
  __imp__sub_88091DE8(ctx,base);
  long long c=calls.fetch_add(1)+1;
  long long nl=nulls.load(std::memory_order_relaxed);
  if(ctx.r3.u32==0) nl=nulls.fetch_add(1)+1;
  long now=(long)std::chrono::duration_cast<std::chrono::seconds>(
             std::chrono::steady_clock::now().time_since_epoch()).count();
  long prev=lastlog.load(std::memory_order_relaxed);
  if((ctx.r3.u32==0) || (now-prev>=2 && lastlog.compare_exchange_strong(prev,now)))
    std::fprintf(stderr,"[drawalloc] calls=%lld nulls=%lld fade66cc=0x%X\n",
      c, nl, PPC_LOAD_U32(0x884D66CCu));
}

// RT_GATEADV: drive the game's per-frame vsync gate FROM THE GAME THREAD ITSELF. The game main
// (sub_88168D48 loc_88168F80) busy-spins on gate 0x887AC958 (set to 1 after each frame's work in
// loc_88168F60) until sub_88168C80 clears it. On real HW sub_88168C80 is the game's per-vblank
// interrupt callback — invoked externally, never wired in our harness — so the game spins
// forever after its first frame. sub_88093418 is the ONE function called on every spin iteration
// of the poll loop, so it runs on the GAME thread: hooking it lets us invoke sub_88168C80 with no
// cross-thread race against the game's own frame state. Fire only when the gate is set (matches
// sub_88168C80's own guard); this releases the game to run its next frame. Effectively unthrottled
// (advances as fast as the game spins), which is what we want to force it past loading → content.
extern "C" void __imp__sub_88093418(PPCContext& __restrict, uint8_t*);
static bool gateadv(){ static bool on=std::getenv("RT_GATEADV")!=nullptr; return on; }
static std::atomic<long long> g_gateadv{0};
std::atomic<long> g_gmain_tid{0};   // game-main thread id (recorded here; used by the gmwait probe)
PPC_FUNC(sub_88093418){
  g_gmain_tid.store(xr_gettid(), std::memory_order_relaxed);
  // [spin] (2026-07-23 sequencer leg): heartbeat with tid — tells whether the game main is alive
  // and spinning on the gate (this fn runs every spin iteration) when the FSM/pump cadence dies.
  if(std::getenv("RT_JOINP")){ static std::atomic<long long> sp{0}; long long s=sp.fetch_add(1)+1;
    if(s%1200==0) std::fprintf(stderr,"[spin] 88093418 #%lld tid=%ld gate=%u\n",
      s,(long)xr_gettid(),PPC_LOAD_U32(GA_GM_FRAME_GATE)); }
  bool gm93=(xr_gettid()==g_gm_loop_tid.load(std::memory_order_relaxed));
  if(gm93) g_gm_stage.store(9,std::memory_order_relaxed);
  __imp__sub_88093418(ctx,base);
  if(gm93){ g_gm_stage.store(10,std::memory_order_relaxed); g_gm_frame_returns.fetch_add(1); }
  if(gateadv() && PPC_LOAD_U32(GA_GM_FRAME_GATE)!=0){
    long long n=g_gateadv.fetch_add(1)+1;
    if(n<=5 || (n%600)==0)
      std::fprintf(stderr,"[gateadv] advancing game frame #%lld via sub_88168C80\n",n);
    PPCContext ic=ctx; __imp__sub_88168C80(ic,base);
  }
}
// [gmwait2] capture the GAME-MAIN thread's frame-wait handle set (sub_880832C8, cnt/r3, array/r5,
// waitAll/r6, alertable/r7). Filtered to the game-main tid recorded above => no cross-thread noise.
// The blocking call at the submit freeze logs ENTER with NO matching EXIT => its handles are the
// answer. RT_GMWAIT-gated. Reads up to 4 handles from the guest array.
extern "C" void __imp__sub_880832C8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_880832C8){
  static bool on=std::getenv("RT_GMWAIT")!=nullptr;
  bool gm = on && (xr_gettid()==g_gmain_tid.load(std::memory_order_relaxed));
  static std::atomic<long long> n{0}; long long i = gm ? n.fetch_add(1)+1 : 0;
  static uint32_t last0=0xDEADBEEF,last1=0;
  uint32_t cnt=ctx.r3.u32, arr=ctx.r5.u32;
  uint32_t h[4]={0,0,0,0};
  for(uint32_t k=0;k<cnt&&k<4&&arr;k++) h[k]=PPC_LOAD_U32(arr+4*k);
  bool changed=(h[0]!=last0||h[1]!=last1); last0=h[0]; last1=h[1];
  bool f = gm && (i<=30 || (i%8000)==0 || changed);
  if(f) std::fprintf(stderr,"[gmwait2] #%lld ENTER cnt=%u arr=0x%X waitAll=0x%X alert=0x%X h={%08X %08X %08X %08X}%s\n",
    i,cnt,arr,ctx.r6.u32,ctx.r7.u32,h[0],h[1],h[2],h[3], changed?"  <==CHANGED":"");
  __imp__sub_880832C8(ctx,base);
  if(f) std::fprintf(stderr,"[gmwait2] #%lld EXIT r3=0x%X\n",i,ctx.r3.u32);
}
// (Draw sub_8209D800 / Present sub_820A5408 are ALREADY hooked by shell/gen rt.cpp's RT_D3D9
// layer — defining them here is a duplicate-symbol link error. Use RT_D3D9=1 for those.)

// RT_LOADDONE: the faithful fix for the "stuck on the copyright/loading screen" gate. The boot
// scene FSM (sub_88138F00 on *(0x884D66A8)) advances 5->6 (and 3->6) only through sub_88138E38,
// which gates on bit 0x02 of guest byte 0x887AC973 (the "assets fully committed" flag) being set
// for >120 consecutive calls. In the harness that flag's async decompress/stream-completion
// setter never fires, so the gate is starved. Rather than blanket-poke the byte every frame from
// the shell present hook (RT_POKE — proven to stall the FSM at state 3 by disturbing earlier
// states), OR the bit in call-scoped, on the game thread, at the exact instant sub_88138E38 reads
// it. This lets the gate's own counter climb and take its real transition path (request title pack
// via sub_881526C0 id29 @0x88097370 into HandleA, set 0x887AC964=1, store 6 into 0x884D66A8)
// unmodified. NOTE: reaching state 6 loads the title PACK but does not by itself instantiate the
// title-screen sprites (that is a deeper scene-manager/asset-commit layer the harness still does
// not drive), so the visible screen may remain the copyright/replay boot screen. Verified fix per
// the session-7 workflow (7 agents, cross-checked vs SDK ground truth).
extern "C" void __imp__sub_88138E38(PPCContext& __restrict, uint8_t*);
static bool loaddone(){ static bool on=std::getenv("RT_LOADDONE")!=nullptr; return on; }
PPC_FUNC(sub_88138E38){
  if(loaddone()) *(uint8_t*)(base+GA_ASSET_COMMIT) |= 0x02u;
  __imp__sub_88138E38(ctx,base);
}

// RT_SNDDRAINED (2026-07-17 attract-pacing): sub_88092228 is the ROM's "async/sound command
// queue drained" poll (returns DAT_887AD4BC == DAT_887AD4B8 under a mutex). The attract task
// chain (legal-notice typewriter sub_88100588 state 2, and siblings across the attract
// choreography) gates on it between steps. In merged the ROM's sound consumer never runs
// (see RT_SNDQFREE below: "sound commands go nowhere — no game audio consumer"), so the queue
// indices can stall unequal and every gated step waits for its fallback path instead of
// advancing immediately — the measured ~6-10x-slow attract cadence. This shim forces the poll
// to report DRAINED. Value-checked: RT_SNDDRAINED=0 disables.
extern "C" void __imp__sub_88092228(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88092228){
  __imp__sub_88092228(ctx,base);
  static int snddrained = std::getenv("RT_SNDDRAINED") ? atoi(std::getenv("RT_SNDDRAINED")) : 0;
  if(snddrained && ctx.r3.u32 == 0){
    static std::atomic<long long> c{0}; long long i=c.fetch_add(1)+1;
    if(i<=5 || (i%500)==0) std::fprintf(stderr,"[snddrained] forced drained (#%lld, 4BC=0x%X 4B8=0x%X)\n",
      i, PPC_LOAD_U32(0x887AD4BCu), PPC_LOAD_U32(0x887AD4B8u));
    ctx.r3.u64 = 1;
  }
}
// RT_TICKRATE=1 (2026-07-17): rate counters on the attract task family — the legal-notice task
// step (sub_88100588) and the glyph fly-in step (sub_880FFCE8). Prints calls/sec vs wall time so
// the "task pump under-driven ~10x" hypothesis is measurable against the ~60Hz present rate.
static bool tickrate(){ static bool on=std::getenv("RT_TICKRATE")!=nullptr; return on; }
extern "C" void __imp__sub_88100588(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88100588){
  // [eeprom] (2026-07-24): this "legal-notice task" is ALSO the arcade-EEPROM/settings bring-up
  // machine (the legal screen shows while the EEPROM check runs). State walk 0->1->2->3->4->5;
  // state 2 gates on the sub_88092228 sound-drain poll. Log state transitions.
  // RT_EEPROMLOG-gated: once the machine parks at state 5 this fired EVERY call = a per-frame
  // stderr flood for the rest of the session (COMPDBG-throttle class -> menu jank). Default OFF.
  static const bool rtEepromLogSM = std::getenv("RT_EEPROMLOG")!=nullptr;
  if(rtEepromLogSM){
    static std::atomic<long long> n{0}; long long c=n.fetch_add(1)+1;
    {
      // replicate the fn's own context lookup: walk draw list @0x88449D4C, key node[+8]==r3,
      // ctx=node[+28], machine state=ctx[0]. NULL ctx => the guest will read address 0.
      uint32_t node=PPC_LOAD_U32(0x88449D4Cu), cx=0; int hops=0;
      while(node && hops<32){ if(PPC_LOAD_U32(node+8)==ctx.r3.u32){ cx=PPC_LOAD_U32(node+28); break; }
        node=PPC_LOAD_U32(node); ++hops; }
      uint32_t st=cx?PPC_LOAD_U32(cx):0xdead;
      // log: first 10, then EVERY call whose state != 1 (the long asset wait is the only spam)
      if(c<=10 || st!=1 || (c%200)==0)
        std::fprintf(stderr,"[eeprom] 588#%lld r3=0x%X ctx=0x%X st=%u inner=0x%X err67=%u,%u pend4=%u a19=%d\n",
          c, ctx.r3.u32, cx, st,
          cx?PPC_LOAD_U32(cx+8):0, cx?PPC_LOAD_U32(cx+24):0, cx?PPC_LOAD_U32(cx+28):0,
          cx?PPC_LOAD_U32(cx+16):0, base[0x88449a19u]);
    }
  }
  if(tickrate()){
    static std::atomic<long long> n{0}; long long i=n.fetch_add(1)+1;
    static const auto t0=std::chrono::steady_clock::now();
    if(i<=3 || (i%120)==0){ double s=std::chrono::duration<double>(std::chrono::steady_clock::now()-t0).count();
      std::fprintf(stderr,"[tickrate] legaltask#%lld t=%.1fs avg=%.1f/s state=%u\n", i, s, s>0? i/s:0.0,
        PPC_LOAD_U32(ctx.r3.u32)); }
  }
  __imp__sub_88100588(ctx,base);
}
extern "C" void __imp__sub_880FFCE8(PPCContext& __restrict, uint8_t*);
// RT_TICKTRACE=1: resolve the HOST return-address chain of a glyph-step invocation back to guest
// sub_ names via PPCFuncMappings (nearest-host-pointer heuristic) — identifies the ROM's task
// DISPATCHER chain empirically, no decomp guessing. A handful of one-shot dumps.
#ifdef _WIN32
extern "C" unsigned short RtlCaptureStackBackTrace(unsigned long, unsigned long, void**, unsigned long*);
#endif
static void rt_ticktrace_dump(const char* tag){
#ifdef _WIN32
  void* frames[24]; unsigned short nf = RtlCaptureStackBackTrace(1, 24, frames, nullptr);
  static std::vector<std::pair<void*,uint32_t>> sorted;
  if(sorted.empty()){
    for(PPCFuncMapping* m=PPCFuncMappings; m->guest; ++m) if(m->host) sorted.push_back({(void*)m->host,(uint32_t)m->guest});
    std::sort(sorted.begin(), sorted.end());
  }
  char line[640]; int o=std::snprintf(line,sizeof line,"[ticktrace] %s:",tag);
  for(unsigned short f=0; f<nf && o<560; ++f){
    auto it = std::upper_bound(sorted.begin(), sorted.end(), std::make_pair(frames[f],~0u));
    if(it==sorted.begin()) continue;
    --it;
    // only report frames within ~2MB of a mapped function start (recomp fns are contiguous-ish)
    if((char*)frames[f]-(char*)it->first < (1<<21))
      o+=std::snprintf(line+o,sizeof(line)-o," %08X",(unsigned)it->second);
  }
  std::fprintf(stderr,"%s\n",line);
#else
  (void)tag;
#endif
}
PPC_FUNC(sub_880FFCE8){
  if(tickrate()){
    static std::atomic<long long> n{0}; long long i=n.fetch_add(1)+1;
    static const auto t0=std::chrono::steady_clock::now();
    if(i<=3 || (i%120)==0){ double s=std::chrono::duration<double>(std::chrono::steady_clock::now()-t0).count();
      std::fprintf(stderr,"[tickrate] glyphstep#%lld t=%.1fs avg=%.1f/s\n", i, s, s>0? i/s:0.0); }
    static std::atomic<int> traced{0};
    if(std::getenv("RT_TICKTRACE") && traced.fetch_add(1) < 4) rt_ticktrace_dump("glyphstep");
  }
  __imp__sub_880FFCE8(ctx,base);
}

// RT_SLOWPROBE / RT_SLOWCLAMP (2026-07-17 attract-pacing ROOT CAUSE): sub_88168F98 is the ROM's
// AUTHENTIC ARCADE-SLOWDOWN ESTIMATOR — per logic frame, sub_8808FB90 asks it how many 60Hz
// vblank handshakes this frame should span (emulating PCB slowdown from sprite/load statistics
// gathered by sub_8808F908's command-buffer cost walk; state bytes 0x887AD548.. select the
// scene formula; on the attract path it should early-exit and return 1). In the port its stat
// inputs are wrong (the cost walk parses OUR sprite stream; accumulators like 0x887AD188 feed
// straight into the wait count), so it returns ~8-10 EVERY frame -> game logic runs at
// 67/8..67/10 = 6.7-8.4Hz while rendering at 67Hz = the whole ~6-10x-slow attract (legal 87s vs
// the oracle's ~10s; measured [tickrate] glyphstep 6.5/s vs gamekick 67/s).
// RT_SLOWPROBE=1 logs the estimator's return + inputs. RT_SLOWCLAMP=<n> clamps the return to n
// (=1 disables slowdown emulation entirely — faithful for the attract where the true value is 1;
// gameplay wants the real fix = correct stats, or a state-gated clamp).
extern "C" void __imp__sub_88168F98(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88168F98){
  __imp__sub_88168F98(ctx,base);
  static int slowprobe = std::getenv("RT_SLOWPROBE") ? 1 : 0;
  static int slowclamp = std::getenv("RT_SLOWCLAMP") ? atoi(std::getenv("RT_SLOWCLAMP")) : 0;
  if(slowprobe){
    static std::atomic<long long> n{0}; long long i=n.fetch_add(1)+1;
    if(i<=10 || (i%300)==0)
      std::fprintf(stderr,"[slowprobe] est#%lld ret=%u st548=%u,%u,%u,%u d140=%u d188=%u\n",
        i,(unsigned)ctx.r3.u32,
        *(uint8_t*)(base+0x887AD548u),*(uint8_t*)(base+0x887AD549u),
        *(uint8_t*)(base+0x887AD54Au),*(uint8_t*)(base+0x887AD54Bu),
        (unsigned)PPC_LOAD_U32(0x887AD140u),(unsigned)PPC_LOAD_U32(0x887AD188u));
  }
  if(slowclamp > 0 && ctx.r3.u32 > (uint32_t)slowclamp){
    static std::atomic<long long> c{0}; long long i=c.fetch_add(1)+1;
    if(i<=5 || (i%600)==0) std::fprintf(stderr,"[slowclamp] %u -> %d (#%lld)\n",(unsigned)ctx.r3.u32,slowclamp,i);
    ctx.r3.u64 = (uint32_t)slowclamp;
  }
}

// sub_88090480 = the game's service-pump callback (registered at CB248-singleton+572 via
// sub_821CA5B8 during the driver msg sequence). The shell service thread bctrl's it every ~1ms.
// If it never fires, the game main's frame events (0x885C651C array) never get signaled and
// sub_88093418 waits forever. Always-on counter: first 5 + every 1000th.
extern "C" void __imp__sub_88090480(PPCContext& __restrict, uint8_t*);
static std::atomic<long long> g_pump480{0};
// RT_SNDQFREE (LEG-34): self-heal the game's sound-command-queue lock. The queue at 0x884EB398
// (busy flag 0x884EB394, index 0x884EA0BC, cap 128, doorbell pulse 0x884EB61C) is produced by
// sub_880E31B0/sub_880E3080/sub_880E3240/... which BUSY-SPIN while *(0x884EB394)!=0. The flag is
// a consumer-side "draining" latch, but the game module NEVER registers its own XAudio render
// client in merged (only the shell's cb 0x82139888 exists), so once something sets the latch it
// never clears -> game main spins forever inside the FSM tick (frame ~7600 freeze; proven by
// gdb: thread in sub_880E31B0 loc_880E31D8, live-clearing the flag un-froze the game). Zeroing
// here runs on the shell service thread every ~1ms, so a stuck producer self-heals within ~1ms.
// Sound commands go nowhere anyway (no game audio consumer). Log each nonzero clear (cadence of
// the mystery setter = future RE breadcrumb).
PPC_FUNC(sub_88090480){
  long long n=g_pump480.fetch_add(1)+1;
  if(n<=5 || (n%1000)==0)
    std::fprintf(stderr,"[pump] sub_88090480 (game service cb) call#%lld\n",n);
  // [gmstage] sampler print (this cb thread survives the game-main freeze): odd stage = the
  // main is INSIDE that callee. 1/2=A738 3/4=91448 5/6=138F00 7/8=93950 9/10=93418.
  if(std::getenv("RT_JOINP") && (n%2000)==0)
    std::fprintf(stderr,"[gmstage] stage=%d (pump#%lld) frameRets=%lld fa68=%lld gate=%u evt6528=%08X period=%d\n",
      g_gm_stage.load(std::memory_order_relaxed),n,
      g_gm_frame_returns.load(),g_fa68_calls.load(),PPC_LOAD_U32(GA_GM_FRAME_GATE),
      PPC_LOAD_U32(0x885C6528u),(int)PPC_LOAD_U32(0x88252DD8u));
  // RT_AUDIOGATE probe: DAT_887ad50c is the game's audio-driver object (null => the sound-command
  // consumer 0x880E4CD0 gated OFF at 0x88090480; game BGM/SE never drained -> silent). DAT_887ad510
  // is the installed consumer fn ptr. Log the transition so we see if/when audio init lands.
  if(std::getenv("RT_AUDIOGATE")){
    static uint32_t last50c=0xDEADBEEF; uint32_t v=PPC_LOAD_U32(0x887AD50Cu);
    if(v!=last50c){ last50c=v;
      std::fprintf(stderr,"[audiogate] DAT_887ad50c=0x%08X DAT_887ad510(consumer)=0x%08X DAT_887ad50c!=0 -> consumer %s (pump#%lld)\n",
        v, PPC_LOAD_U32(0x887AD510u), v?"ENABLED":"GATED-OFF", n); }
    // Sound-command queue: producer index 0x884EA0BC (bumped by game sub_880E31B0 when it emits a
    // sound), consumer index 0x884EA3D4 (bumped by sub_880E4CD0 as it drains). If the producer
    // never advances, the GAME is not triggering any sound (BGM/SE) in this state.
    static uint32_t lastprod=0xDEADBEEF; uint32_t prod=PPC_LOAD_U32(0x884EA0BCu), cons=PPC_LOAD_U32(0x884EA3D4u);
    if(prod!=lastprod){ lastprod=prod; static std::atomic<long> pe{0}; long e=pe.fetch_add(1)+1;
      if(e<=40 || (e%50)==0) std::fprintf(stderr,"[sndq] producer idx -> %u (consumer %u) pump#%lld\n",prod,cons,n); }
  }
  static bool sndqfree = std::getenv("RT_SNDQFREE")!=nullptr;
  if(sndqfree && PPC_LOAD_U32(0x884EB394u)!=0){
    PPC_STORE_U32(0x884EB394u, 0);
    static std::atomic<long long> c{0}; long long i=c.fetch_add(1)+1;
    if(i<=8 || (i%200)==0)
      std::fprintf(stderr,"[sndqfree] cleared stuck sound-queue latch 0x884EB394 (#%lld, pump#%lld, qidx=0x%X)\n",
        i, n, PPC_LOAD_U32(0x884EA0BCu));
  }
  // RT_AUDIOFILL (DIAGNOSTIC PROOF, default-OFF, AUDIO-ONLY side effect): the crux binds voices to
  // valid but EMPTY PCM sample buffers (wave-desc entry+12); the wave-data delivery never fills them
  // so the mixer sums zeros. This lever fills each wave-table buffer with a 375Hz square test tone
  // (BE PCM16 stereo, written via PPC_STORE_U16 so the guest reads it natively). If the submitted
  // mix then goes NON-ZERO, it proves the voice reaches the mixer and the empty buffer is the whole
  // defect -> first audible sound. It writes ONLY into the audio sample buffers, gated on the env.
  static bool audiofill = std::getenv("RT_AUDIOFILL")!=nullptr;
  if(audiofill){
    uint32_t wt=PPC_LOAD_U32(0x887AD504u), wcnt=PPC_LOAD_U32(0x887AD508u);
    if(wt && wt<0xF0000000u && wcnt && wcnt<=64){
      const uint32_t FILLB=0x8000;            // 32KB window == observed inter-entry stride
      const int amp=6000, half=64;            // 48000/(2*64)=375Hz
      for(uint32_t e=0;e<wcnt;++e){
        uint32_t sp=PPC_LOAD_U32(wt+e*16+12);
        if(!sp || sp>=0xF0000000u) continue;
        for(uint32_t b=0;b<FILLB;b+=4){        // stereo frame = 4 bytes (L16,R16)
          uint32_t fr=b>>2; int v=((fr/half)&1)?amp:-amp;
          PPC_STORE_U16(sp+b,   (uint16_t)(int16_t)v);
          PPC_STORE_U16(sp+b+2, (uint16_t)(int16_t)v);
        }
      }
      static std::atomic<long long> fc{0}; long long i=fc.fetch_add(1)+1;
      if(i==1||i%1000==0) std::fprintf(stderr,"[audiofill] filled %u wave buffers (0x%X..) with 375Hz tone (#%lld)\n",wcnt,wt,i);
    }
  }
  __imp__sub_88090480(ctx,base);
}

// ---- RT_TRACEBOOT: first-call ENTER/EXIT trace on the game-main init+loop functions, to
// pinpoint WHERE the game main (sub_88168D48) parks. The last fn that ENTERs without an EXIT is
// the blocker. Order in sub_88168D48: ...sub_88092ED8 (worker spawn) ... sub_880918B0,
// sub_88090A00, sub_88091210, sub_88138D68, sub_88093418(init), sub_8813A4D0, sub_8813A738,
// then loc_88168F60 loop: sub_8813A738, sub_88091448, sub_88138F00 (state machine),
// sub_88093950 (job drain), set gate, poll. ----
static bool traceboot(){ static bool on=std::getenv("RT_TRACEBOOT")!=nullptr; return on; }
#define TB_WRAP(FN) \
  extern "C" void __imp__##FN(PPCContext& __restrict, uint8_t*); \
  static std::atomic<int> g_tb_##FN{0}; \
  PPC_FUNC(FN){ \
    bool f = traceboot() && g_tb_##FN.fetch_add(1)==0; \
    if(f) std::fprintf(stderr,"[boot] " #FN " ENTER r3=0x%X r4=0x%X (imports=%ld)\n",ctx.r3.u32,ctx.r4.u32,g_import_calls.load()); \
    __imp__##FN(ctx,base); \
    if(f) std::fprintf(stderr,"[boot] " #FN " EXIT r3=0x%X (imports=%ld)\n",ctx.r3.u32,g_import_calls.load()); \
  }
TB_WRAP(sub_880918B0)
TB_WRAP(sub_88090A00)
TB_WRAP(sub_88091210)
TB_WRAP(sub_88138D68)
TB_WRAP(sub_8813A4D0)
// sub_8813A738 + sub_88093950: TB_WRAP semantics preserved, plus [gmstage] stamps (a738 pins the
// main-loop tid — it is called only from the game-main loop, once per iteration).
extern "C" void __imp__sub_8813A738(PPCContext& __restrict, uint8_t*);
static std::atomic<int> g_tb_sub_8813A738{0};
PPC_FUNC(sub_8813A738){
  bool f = traceboot() && g_tb_sub_8813A738.fetch_add(1)==0;
  if(f) std::fprintf(stderr,"[boot] sub_8813A738 ENTER r3=0x%X r4=0x%X (imports=%ld)\n",ctx.r3.u32,ctx.r4.u32,g_import_calls.load());
  g_gm_loop_tid.store(xr_gettid(),std::memory_order_relaxed);
  g_gm_stage.store(1,std::memory_order_relaxed);
  __imp__sub_8813A738(ctx,base);
  g_gm_stage.store(2,std::memory_order_relaxed);
  if(f) std::fprintf(stderr,"[boot] sub_8813A738 EXIT r3=0x%X (imports=%ld)\n",ctx.r3.u32,g_import_calls.load());
}
// sub_88091448 (input edge derive, main-loop stage 3/4) — not previously wrapped.
extern "C" void __imp__sub_88091448(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88091448){
  bool gm = xr_gettid()==g_gm_loop_tid.load(std::memory_order_relaxed);
  if(gm) g_gm_stage.store(3,std::memory_order_relaxed);
  __imp__sub_88091448(ctx,base);
  if(gm) g_gm_stage.store(4,std::memory_order_relaxed);
}
extern "C" void __imp__sub_88093950(PPCContext& __restrict, uint8_t*);
static std::atomic<int> g_tb_sub_88093950{0};
PPC_FUNC(sub_88093950){
  bool f = traceboot() && g_tb_sub_88093950.fetch_add(1)==0;
  if(f) std::fprintf(stderr,"[boot] sub_88093950 ENTER r3=0x%X r4=0x%X (imports=%ld)\n",ctx.r3.u32,ctx.r4.u32,g_import_calls.load());
  bool gm = xr_gettid()==g_gm_loop_tid.load(std::memory_order_relaxed);
  if(gm) g_gm_stage.store(7,std::memory_order_relaxed);
  __imp__sub_88093950(ctx,base);
  if(gm) g_gm_stage.store(8,std::memory_order_relaxed);
  if(f) std::fprintf(stderr,"[boot] sub_88093950 EXIT r3=0x%X (imports=%ld)\n",ctx.r3.u32,g_import_calls.load());
}

// ---- RT_TRACESM: trace the scene/mode state-machine sub_88138F00's per-state callees to find
// where the first tick stalls. Logs ENTER#n/EXIT#n for the first few calls of each; the fn whose
// ENTER#k has no matching EXIT#k is the stall (works for the sub_8813A3C0 x33 loop too). ----
#define SM_WRAP(FN) \
  extern "C" void __imp__##FN(PPCContext& __restrict, uint8_t*); \
  static std::atomic<int> g_sm_##FN{0}; \
  PPC_FUNC(FN){ \
    int n=g_sm_##FN.fetch_add(1); bool t=std::getenv("RT_TRACESM")&&(n<3); \
    if(t) std::fprintf(stderr,"[sm] " #FN " ENTER#%d\n",n); \
    __imp__##FN(ctx,base); \
    if(t) std::fprintf(stderr,"[sm] " #FN " EXIT#%d\n",n); \
  }
SM_WRAP(sub_881383A0)
SM_WRAP(sub_880F1448)
SM_WRAP(sub_88138BA8)
SM_WRAP(sub_88138CE0)
SM_WRAP(sub_88136460)
// pump wrapper + periodic descriptor-list dump: every 600th tick walk the node list at
// *(0x88449D4C) and print each node's raw words (layout: +8 handle, +12 fn, +24 id, +32 flag)
// — shows which phase stuck nodes sit in.
extern "C" void __imp__sub_88152CF0(PPCContext& __restrict, uint8_t*);
extern "C" void __imp__sub_88226EB0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88152CF0){
  static std::atomic<int> n{0}; int i=n.fetch_add(1);
  // [pumpcnt] (2026-07-23 sequencer leg): if [seq]/[csa] stop while this keeps counting, their
  // records were destroyed; if this stops too, the pump's caller (shell msg-5 drive) halted.
  if(std::getenv("RT_JOINP") && i>0 && i%60==0){
    uint32_t cnt=0, ids[12]={0};
    for(uint32_t nd=PPC_LOAD_U32(0x88449D4Cu); nd && cnt<64; nd=PPC_LOAD_U32(nd)){
      if(cnt<12) ids[cnt]=PPC_LOAD_U32(nd+8); cnt++; }
    std::fprintf(stderr,"[pumpcnt] #%d lr=%08X len=%u ids=[%X %X %X %X %X %X %X %X] d76=%u 67cc=%u\n",
      i,(uint32_t)ctx.lr,cnt,ids[0],ids[1],ids[2],ids[3],ids[4],ids[5],ids[6],ids[7],
      (uint32_t)PPC_LOAD_U16(0x884D678Cu),PPC_LOAD_U32(0x884D67CCu));
  }
  __imp__sub_88152CF0(ctx,base);
  // RT_TICKGP (LEG-20 first-pixels test): the id46 gameplay drawer sub_88226EB0 is ticked by the
  // pump only ~12x (node dropped from the list post-construct), never persistently. Re-tick it here
  // each pump frame with the pump's own args (r3=0x23 id46 handle, r4=0x884D6740 FSM block) — same
  // thread/frame-point the pump used. If it draws ~81, that's first gameplay pixels.
  static int tickgp = std::getenv("RT_TICKGP")?atoi(std::getenv("RT_TICKGP")):0;
  if(tickgp){
    static uint32_t h=(std::getenv("RT_TICKGP_H")?(uint32_t)strtoul(std::getenv("RT_TICKGP_H"),0,16):0x23u);
    PPCContext ic=ctx; ic.r3.u32=h; ic.r4.u32=0x884D6740u;
    __imp__sub_88226EB0(ic,base);
  }
  if(std::getenv("RT_TRACERES") && i>0 && (i%600)==0){
    uint32_t nd=PPC_LOAD_U32(0x88449D4Cu); int k=0;
    std::fprintf(stderr,"[rr] pump#%d list:",i);
    while(nd>=0x1000 && nd<0xFFFF0000u && k<24){
      std::fprintf(stderr," {h=%X fn=%08X id=%u f32=%u w4=%08X w5=%08X}",
        PPC_LOAD_U32(nd+8),PPC_LOAD_U32(nd+12),PPC_LOAD_U32(nd+24),PPC_LOAD_U32(nd+32),
        PPC_LOAD_U32(nd+16),PPC_LOAD_U32(nd+20));
      nd=PPC_LOAD_U32(nd); ++k;
    }
    std::fprintf(stderr," (%d)\n",k);
    // scene/FSM object + attract-state globals hexdump — diff vs the SDK's bright title
    std::fprintf(stderr,"[scn] pump#%d A:",i);
    for(uint32_t a=0x884D66A0u;a<0x884D6740u;a+=4) std::fprintf(stderr," %08X",PPC_LOAD_U32(a));
    std::fprintf(stderr,"\n[scn] pump#%d B:",i);
    for(uint32_t a=0x884EB380u;a<0x884EB3C0u;a+=4) std::fprintf(stderr," %08X",PPC_LOAD_U32(a));
    std::fprintf(stderr," | 61C=%08X 620=%08X\n",PPC_LOAD_U32(0x884EB61Cu),PPC_LOAD_U32(0x884EB620u));
  }
}
SM_WRAP(sub_8813AEC8)
SM_WRAP(sub_8813A3C0)
// ★ FNF-11 (2026-07-27, decomp-grounded — ghidra_futari_decomp/NOTE_fnf11_handback_decomp.md):
// sub_8813A5F0 = the state-2 teardown's job-ring + asset-table zero, running exactly once per
// RETURN-TO-TOP-MENU handback AFTER FUN_8813a3c0 destroy-marked every cached guest GPU texture.
// Signal the renderer to drop its host texture caches (rvk_handback_invalidate -> consumed on
// the render worker in getTexIndexReal) so post-teardown draws re-decode fresh guest RAM instead
// of serving pre-teardown images (the stuck green-panel compose). Also fires on any other guest
// path through this fn (e.g. credited post-game reset) — over-firing is safe (invalidate =
// re-decode). Keeps the RT_TRACESM behavior SM_WRAP provided. RVK_NOHBINV=1 (renderer side)
// ignores the signal for A/B.
extern "C" void rvk_handback_invalidate(void);
extern "C" void __imp__sub_8813A5F0(PPCContext& __restrict, uint8_t*);
static std::atomic<int> g_sm_sub_8813A5F0{0};
PPC_FUNC(sub_8813A5F0){
  int n=g_sm_sub_8813A5F0.fetch_add(1); bool t=std::getenv("RT_TRACESM")&&(n<3);
  if(t) std::fprintf(stderr,"[sm] sub_8813A5F0 ENTER#%d\n",n);
  rvk_handback_invalidate();
  __imp__sub_8813A5F0(ctx,base);
  if(t) std::fprintf(stderr,"[sm] sub_8813A5F0 EXIT#%d\n",n);
}
// sub_88152738 = FULL resource-system reset (bulk "release all": zeroes descriptor list head
// 0x88449D4C, writeSeq 0x88449D40, live-count 0x88449D44, pool). The FSM's scene transitions
// call it via 88138CE0/88138E38. RT_TRACERES logs every call + lr + pre-counts.
extern "C" void __imp__sub_88152738(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88152738){
  static std::atomic<int> n{0}; int i=n.fetch_add(1);
  if(std::getenv("RT_TRACERES") && i<400)
    std::fprintf(stderr,"[rr] RESET-52738#%d lr=0x%X live=%u seq=%u a074=%u\n",
      i,(uint32_t)ctx.lr,PPC_LOAD_U32(0x88449D44u),PPC_LOAD_U32(0x88449D40u),PPC_LOAD_U32(0x8844A074u));
  __imp__sub_88152738(ctx,base);
}
// state-5 menu HOST scene (tracked handle in 0x884D66B4 during state 5). Log call rate +
// whether it early-returns before its draw code. RT_S5 gated.
extern "C" void __imp__sub_881025D0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_881025D0){
  static std::atomic<long> n{0}; long i=n.fetch_add(1);
  if(std::getenv("RT_S5") && (i<5 || (i%2000)==0))
    std::fprintf(stderr,"[s5host] 881025D0 call#%ld r3=0x%X\n",i,ctx.r3.u32);
  __imp__sub_881025D0(ctx,base);
}
// LEG-14: sub_881366D0 = "confirm side r3 on the highlighted menu item" (mark-side-selected +
// highlight + SFX; ppc_recomp.18.cpp:1483). If this fires, the menu IS consuming a confirm; if
// it never fires despite injected START/confirm, the wall is upstream of the confirm read.
// Also dump the widget-select flags at base 0x884D6740 +308/+312/+328/+352 before/after.
extern "C" void __imp__sub_881366D0(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_881366D0){
  uint32_t side=ctx.r3.u32;
  int logit=0;
  if(std::getenv("RT_JOINP")){
    uint32_t t674c=PPC_LOAD_U32(0x884D674Cu); int busy=rt_gs_busy(base,t674c);
    uint32_t g6870=PPC_LOAD_U32(0x884D6870u), g6878=PPC_LOAD_U32(0x884D6878u);
    uint32_t guard=PPC_LOAD_U32(0x884D6740u+side*4+0x3c);
    uint32_t jflag=PPC_LOAD_U8(0x884D6CE8u+side*196u);
    static std::atomic<int> c{0}; int q=c.fetch_add(1);
    if(q<80) std::fprintf(stderr,"[joinp] *** 881366D0 ENTER slot=%u 674c=0x%X busy=%d 6870=%u 6878=%u guard+3c=%u jflag5a8=0x%X %s ***\n",
      side,t674c,busy,g6870,g6878,guard,jflag,(busy==0&&g6870==0&&g6878==0&&guard==0)?"WILL-JOIN":"EXECUTOR-BLOCKED");
  }
  if(std::getenv("RT_S5")){
    static std::atomic<int> n366{0}; int i=n366.fetch_add(1);
    if(i<40){ logit=1;
      std::fprintf(stderr,"[confirm366] call#%d side=%u sel308=0x%X f312=0x%X f328=0x%X f352=0x%X | gates +304=0x%X +60[s]=0x%X busy12h=0x%X\n",
        i,side,PPC_LOAD_U32(0x884D6740u+308u),PPC_LOAD_U32(0x884D6740u+312u),
        PPC_LOAD_U32(0x884D6740u+328u),PPC_LOAD_U32(0x884D6740u+352u),
        PPC_LOAD_U32(0x884D6740u+304u),PPC_LOAD_U32(0x884D6740u+60u+side*4u),PPC_LOAD_U32(0x884D6740u+12u)); }
  }
  __imp__sub_881366D0(ctx,base);
  if(logit)  // LEG-41: did the NATURAL join commit? (joined => +60[side]==1 & slot active)
    std::fprintf(stderr,"[confirm366]   post: +308=0x%X +60[s]=0x%X slot%u active=%u credit=%u\n",
      PPC_LOAD_U32(0x884D6740u+308u),PPC_LOAD_U32(0x884D6740u+60u+side*4u),
      side,PPC_LOAD_U8(0x884D6CE8u+side*196u),PPC_LOAD_U32(0x887AD4C8u));
}
// LEG-15 REVIEW (RT_S5): sub_88137C28 = the CONFIRM HANDLER (menu dispatch body #1, d76==1). It
// reads raw START (0x8000 in 0x885C33D8/3430), then branches on mode64 (0x887AD584): 0/2 auto-
// select via sub_881366D0, 1 reads confirm byte 0x885C6837. Decisive probe: log EVERY entry's
// inputs (d76/d78/START-bits/mode64/confirm-byte) + whether START is asserted when it runs. If
// START is NEVER set on entry, the pad-injection (RT_MENUCONFIRM) isn't reaching this read →
// wrong address/timing. If START IS set but [confirm366] still never fires, the branch logic
// early-outs (phase +78!=0 or the mode64 path needs more).
extern "C" void __imp__sub_88137C28(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88137C28){
  if(std::getenv("RT_S5")){
    uint32_t p1=PPC_LOAD_U32(0x885C33D8u), p2=PPC_LOAD_U32(0x885C3430u);
    uint32_t start=(p1|p2)&0x8000u;
    static std::atomic<int> nc{0}; int i=nc.fetch_add(1);
    // log first 20, every 4000th, AND every entry where START is asserted (the interesting ones)
    if(i<20 || (i%4000)==0 || start)
      std::fprintf(stderr,"[c28] call#%d d76=%u d78=%u START=0x%X mode64=0x%X cb837=0x%X\n",
        i,PPC_LOAD_U16(0x884D678Cu),PPC_LOAD_U16(0x884D678Eu),start,
        PPC_LOAD_U32(GA_MB_MODE64),PPC_LOAD_U8(0x885C6837u));
  }
  __imp__sub_88137C28(ctx,base);
}
// LEG-15 REVIEW step 2 (RT_S5): the d76=4 wall is +328(=menu-base 0x884D6888) stuck at 0x1.
// sub_88137498 ZEROES +328 (called by sub_88137708); sub_88135D20 INCREMENTS *(r4+328) (a
// registration counter, dispatched INDIRECTLY — no static callers). Capture sub_88135D20's runtime
// caller (lr), its r4 (is it the menu base?), and +328 before/after, to see who re-arms +328 and
// how often — distinguishes "menu widget re-registers every frame" from "stalled async load".
extern "C" void __imp__sub_88135D20(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88135D20){
  if(std::getenv("RT_S5")){
    static std::atomic<int> nd{0}; int i=nd.fetch_add(1);
    uint32_t r4=ctx.r4.u32, lr=(uint32_t)ctx.lr;
    bool menubase=(r4==0x884D6740u);
    if(i<30 || (i%8000)==0)
      std::fprintf(stderr,"[reg135D20] call#%d lr=0x%X r4=0x%X%s +328(of r4)=0x%X menubase328=0x%X\n",
        i,lr,r4,menubase?"(MENU-BASE)":"",
        (r4>=0x1000&&r4<0xFFFF0000u)?PPC_LOAD_U32(r4+328u):0xDEAD,PPC_LOAD_U32(0x884D6740u+328u));
  }
  __imp__sub_88135D20(ctx,base);
}
// LEG-14: sub_88137ED8 = the MENU TICK (dispatches on *(0x884D678C) 0..8). Decisive: is it
// driven per-frame at all? [case4] never firing means either this isn't ticking or it
// dispatches elsewhere. Log call rate + the dispatch value it reads each call.
extern "C" void __imp__sub_88137ED8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88137ED8){
  // [hb2] RT_CR328 leg 4: session-master-tick heartbeat. Leg-3 showed coin-[hb], [ff0] and the
  // sub-screen ticks all stop ~500-650 frames after d76-entry on NORMAL PLAY while d76 stays 4 in
  // memory. If [hb2] keeps printing past that point the session tick is alive (partial teardown
  // below it); if [hb2] stops too, the walker above died. Every 300 calls under RT_S5.
  if(std::getenv("RT_S5")){
    static std::atomic<uint32_t> ed8c{0}; uint32_t ei=ed8c.fetch_add(1);
    if((ei%300)==0)
      std::fprintf(stderr,"[hb2] #%u c708=%u c498=%u cff0=%u cb378=%u cd400=%u cf558=%u | d76=%u d78=%u OUTER=%u t6790=%u +328=%u slot0=0x%X slot2=%u conf=%u m8c=%u 67bc=%u 67b8=0x%X\n",
        ei,g_hb_708.load(),g_hb_498.load(),g_hb_ff0.load(),g_hb_b378.load(),g_hb_d400.load(),g_hb_f558.load(),
        (uint32_t)PPC_LOAD_U16(0x884D678Cu),(uint32_t)PPC_LOAD_U16(0x884D678Eu),
        PPC_LOAD_U32(0x884D66A8u),PPC_LOAD_U32(0x884D6790u),PPC_LOAD_U32(0x884D6888u),
        (uint32_t)PPC_LOAD_U8(0x884D6CE8u),(uint32_t)PPC_LOAD_U16(0x884D6CEAu),
        (uint32_t)PPC_LOAD_U32(0x884D6D0Cu),(uint32_t)PPC_LOAD_U32(0x884D6D74u),
        PPC_LOAD_U32(0x884D67BCu),PPC_LOAD_U32(0x884D67B8u));
  }
  if(std::getenv("RT_S5")){
    static std::atomic<int> nt{0}; int i=nt.fetch_add(1);
    uint32_t disp=PPC_LOAD_U16(0x884D678Cu);
    if(i<10 || (i%4000)==0)
      std::fprintf(stderr,"[menutick] call#%d disp(*884D678C)=%u\n",i,disp);
  }
  // RT_BOUNCEDBG (Round-15): the char-select->mode-select bounce lives INSIDE d76==2 (navreal
  // proves d76 never leaves 2). SDK referee (2026-07-15) proved authentic timeout = FORWARD
  // auto-confirm (char->shot->game), NEVER a backward revert, and the "time" countdown TICKS
  // (49->0) whereas ours is FROZEN at 59. The timer-decrement (sub_88137498) only runs at
  // d76>=3, so a d76-stuck-at-2 explains the freeze. This panel logs, per menu-tick on-change,
  // a WIDE set of candidate sub-screen/confirm/cancel/timer words so the exact word that flips
  // char->mode can be caught by cross-referencing the RVK_COMPDBG 640x512->512x512 atlas edge.
  if(std::getenv("RT_BOUNCEDBG")){
    static std::atomic<int> bn{0}; int i=bn.fetch_add(1);
    auto L16=[&](uint32_t a){return (uint32_t)PPC_LOAD_U16(a);};
    auto L32=[&](uint32_t a){return PPC_LOAD_U32(a);};
    uint32_t d76=L16(0x884D678Cu), d78=L16(0x884D678Eu);
    uint32_t b67cc=L32(0x884D67CCu), b6878=L32(0x884D6878u), b6874=L32(0x884D6874u);
    uint32_t idx6794=L32(0x884D6794u), idx6798=L32(0x884D6798u), idx679c=L32(0x884D679Cu);
    uint32_t t6790=L32(0x884D6790u), t66a4=L32(0x884D66A4u), t66a0=L32(0x884D66A0u), t67e4=L32(0x884D67E4u);
    uint32_t g6728=L32(0x884D6728u), g66f8=L32(0x884D66F8u), m6e84=L32(0x884D6E84u);
    uint32_t sc66a8=L32(0x884D66A8u), c66ec=L32(0x884D66ECu), mb58c=L32(GA_MB_RELOAD), md584=L32(GA_MB_MODE64);
    uint32_t w6748=L32(0x884D6748u), w674c=L32(0x884D674Cu), w6750=L32(0x884D6750u), w675c=L32(0x884D675Cu);
    // composite change-key over the words most likely to encode the sub-screen identity + phase
    uint64_t key=((uint64_t)(d76&7)<<0)|((uint64_t)(d78&7)<<3)|((uint64_t)(b67cc!=0)<<6)
      |((uint64_t)(b6878!=0)<<7)|((uint64_t)(b6874&0xF)<<8)|((uint64_t)(idx6794&0xF)<<12)
      |((uint64_t)(idx6798&0xF)<<16)|((uint64_t)(idx679c&0xF)<<20)|((uint64_t)(m6e84&0xF)<<24)
      |((uint64_t)(sc66a8&0xF)<<28)|((uint64_t)(c66ec!=0)<<32)|((uint64_t)(w6748)<<33)
      |((uint64_t)(w6750!=0)<<49)|((uint64_t)(t66a0&1)<<50);
    static uint64_t lk=~0ull; static std::atomic<int> np{0};
    if(i<20 || key!=lk){ lk=key; int p=np.fetch_add(1);
      if(p<4000) std::fprintf(stderr,
        "[bnc] f#%d d76=%u d78=%u 67cc=%u 6878=%u 6874=0x%X | idx 6794=%u 6798=%u 679c=%u | "
        "tmr 6790=%u 66a4=%u 66a0=%u 67e4=%u | gate 6728=%u 66f8=%u m6e84=%u | "
        "sc66a8=%u -84=%u mb58c=%u md584=%u | w 6748=0x%X 674c=0x%X 6750=0x%X 675c=0x%X\n",
        i,d76,d78,b67cc,b6878,b6874,idx6794,idx6798,idx679c,
        t6790,t66a4,t66a0,t67e4,g6728,g66f8,m6e84,
        sc66a8,c66ec,mb58c,md584,w6748,w674c,w6750,w675c);
    }
  }
  // RT_CHARSELHOLD (Round-15 FIX candidate): ROOT CAUSE of the frozen "59" timer + wedged
  // select menu = DAT_884d67cc stuck at 1. Decomp (reco_normal sub_88137168 @124875): d76==2 is a
  // transient SETUP that advances to d76=3 (the BROWSE state, where sub_88137498 decrements the
  // countdown + reads nav/confirm) ONLY when DAT_884d67cc==0. 67cc is set to 1 by the menu reset
  // (sub_88136178) and cleared to 0 by the select-screen intro-animation widget when it reaches
  // its phase 0xc (reco_normal @78840, whose clear-condition IS satisfied here since
  // DAT_884d66f8==0). In merged that widget never reaches phase 0xc, so 67cc stays 1, d76 wedges
  // at 2 (RT_BOUNCEDBG proved d76 parks at 2 with 67cc=1 forever, all idx/timer globals =0), the
  // browse state never runs -> timer FROZEN + no nav/confirm -> the screen is stuck on MODE SELECT
  // and any transient char-select "bounces" straight back. Force-clear 67cc at d76==2 once the
  // screen widgets exist (6748!=0) so sub_88137168 takes its advance-to-3 branch. This is a REAL
  // unwedge (matches the decomp's intended flow), not a cosmetic clamp. Env-gated; default off.
  if(std::getenv("RT_CHARSELHOLD")){
    if(PPC_LOAD_U16(0x884D678Cu)==2 && PPC_LOAD_U32(0x884D67CCu)!=0 && PPC_LOAD_U32(0x884D6748u)!=0){
      PPC_STORE_U32(0x884D67CCu,0);
      static int lg=0; if(lg++<8) std::fprintf(stderr,"[charselhold] d76==2 & widgets ready: force 67cc 1->0 (unwedge -> browse d76=3)\n");
    }
  }
  // RT_CSHOLD (Round-16): HOLD the d76==3 select browse indefinitely for capture/A-B. The browse
  // timer 0x884D6790 loads 0x40 (d78==1->2) then decrements ~1/frame (sub_881378A0 @125202); at
  // underflow it forces d76=4 (@125205) -> the +328 commit wall. On the SDK the same timer ticks
  // ~1-3/s so a browse screen holds ~20-25s (referee); ours expires in ~1s (60/frame). Re-arming
  // the timer whenever it dips low keeps d76 at 3 so the CURRENT select sub-screen (mode/char/shot,
  // whichever the per-slot machine sub_88136FF0 is showing) stays on screen. This is the "re-arm
  // the browse timer" hold the round brief calls for. Env-gated; default off (byte-identical).
  // RT_CSHOLD_FLOOR (opt) sets the low-water mark (default 8); RT_CSHOLD_ARM the re-armed value
  // (default 0x40). Does NOT block sub-screen advance: slot+2 confirms still cycle mode->char->shot
  // DURING the held browse (sub_88137498 tail runs every tick at d76==3).
  if(std::getenv("RT_CSHOLD")){
    if(PPC_LOAD_U16(0x884D678Cu)==3){
      int floor = std::getenv("RT_CSHOLD_FLOOR") ? atoi(std::getenv("RT_CSHOLD_FLOOR")) : 8;
      int arm   = std::getenv("RT_CSHOLD_ARM")   ? atoi(std::getenv("RT_CSHOLD_ARM"))   : 0x40;
      uint32_t t = PPC_LOAD_U32(0x884D6790u);
      if((int32_t)t <= floor){
        PPC_STORE_U32(0x884D6790u,(uint32_t)arm);
        static int hl=0; if(hl++<6) std::fprintf(stderr,"[cshold] d76==3: re-arm browse timer 6790 %u->0x%X (hold char/mode-select browse)\n",t,arm);
      }
    }
    // RT_SLOTHOLD (2026-07-21, char-card painting hunt): CSHOLD holds the OUTER browse, but the
    // PER-SLOT machine (FUN_88136ff0 via the sub_88137498 tail) still timeout-advances the
    // sub-screen: 0x884D688C = input-activity flag, 0x884D6890 = 8-tick grace it resets; when
    // both reach 0, 0x884D66A0=1 fires the per-slot timeout path (FUN_88133e30) every tick —
    // on our port that advanced the card in ~10-25s with NO input (before the visible 60s timer
    // emptied; the round-16 too-fast-tick class in the slot machine). Pinning the grace at 8 is
    // ARCADE-TRUE: identical to a player continuously wiggling the stick (input activity resets
    // the same grace on hardware, holding the screen). Confirms (slot+2 latch) still step
    // screens normally. Env-gated; default off (byte-identical).
    if(std::getenv("RT_SLOTHOLD") && PPC_LOAD_U16(0x884D678Cu)==3){
      if(PPC_LOAD_U32(0x884D6890u) < 8u){
        PPC_STORE_U32(0x884D6890u, 8u);
        static int sh=0; if(sh++<4) std::fprintf(stderr,"[slothold] d76==3: pin input-grace 6890=8 (freeze per-slot timeout advance)\n");
      }
    }
    // Observe the current select SUB-SCREEN id (887ad54e = (byte)884d6738 = table[8828cb90+
    // (6798*4+6794)*16]) so mode vs char vs shot can be told apart while held. Logs on change.
    static uint32_t lastsub=0xFFFFFFFFu;
    uint32_t sub=PPC_LOAD_U8(0x887AD54Eu), i6794=PPC_LOAD_U32(0x884D6794u), i6798=PPC_LOAD_U32(0x884D6798u);
    uint32_t key=(sub<<16)|((i6798&0xFF)<<8)|(i6794&0xFF);
    if(key!=lastsub && PPC_LOAD_U16(0x884D678Cu)==3){ lastsub=key;
      std::fprintf(stderr,"[cshold] SUBSCREEN 887ad54e=%u (6794=%u 6798=%u) at d76=3\n",sub,i6794,i6798); }
  }
  // ══ RT_LIVEPLAY step (2): at session state 5 (post-fade wait, sub_88136890), set +352=1 so
  // when the id46 fade dies sub_88136890 takes its ELSE branch -> state 8 -> outer 5->2->3 LIVE
  // STAGES (instead of the +352==0 && 6e84==0 -> state6 NAME-ENTRY branch). Paired with the
  // step-(1) +328 clear in the sub_88137498 wrapper above. Env-gated; default off.
  if(std::getenv("RT_LIVEPLAY") && PPC_LOAD_U16(0x884D678Cu)==5){
    if(PPC_LOAD_U32(0x884D68A0u)==0){
      PPC_STORE_U32(0x884D68A0u,1);   // +352 = 1 -> state5 fade-death routes to state8 STAGES
      // RT_LIVEPLAY>=2 (2026-07-23): ALSO replicate the confirm-widget case-0xC credited-ARM
      // side effects that the forced fade-path skipped (sub_8814F558 @140686-140689 / FUN_88137320
      // @124952-124955): the 4-entry (stride 0xD4) credited-slot flags 0x884D77C8/789C/7970/7A44=1.
      // These are the natural "player side armed for credited play" markers; the forced FSM route
      // reached state 8 without them, landing in the ATTRACT DEMO. Test whether setting them turns
      // credited play on (DEMONSTRATION off, player-controllable ship).
      if(atoi(std::getenv("RT_LIVEPLAY"))>=2){
        PPC_STORE_U32(0x884D77C8u,1); PPC_STORE_U32(0x884D789Cu,1);
        PPC_STORE_U32(0x884D7970u,1); PPC_STORE_U32(0x884D7A44u,1);
      }
      static std::atomic<int> l5{0}; int q=l5.fetch_add(1);
      if(q<8||(q%2000)==0) std::fprintf(stderr,"[liveplay] state5: set +352(68a0)=1%s (fade-death -> state8 -> outer3); 6e84=0x%X 77c8=%u\n",
        atoi(std::getenv("RT_LIVEPLAY"))>=2?" +4arm-flags":"",PPC_LOAD_U32(0x884D6E84u),PPC_LOAD_U32(0x884D77C8u));
    }
  }
  __imp__sub_88137ED8(ctx,base);
}
// LEG-14: sub_88137708 = menu dispatch value 4 = THE WALL (jump table is off-by-one: disp 4 ->
// sub_88137708, disp 5 -> sub_88136890). It advances +76 (requesting id 46/48) ONLY if its gate
// chain passes: +1876==0, +312==0, then +352==0 -> (if +328==0) request id46/+76=5, else exit
// at loc_88137884 with no advance. Log all gates to see which one is stuck nonzero.
extern "C" void __imp__sub_88137708(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88137708){
  g_hb_708.fetch_add(1);
  if(std::getenv("RT_S5")){
    static std::atomic<int> nc{0}; int i=nc.fetch_add(1);
    if(i<8 || (i%4000)==0)
      std::fprintf(stderr,"[wall4] call#%d +1876=0x%X +312=0x%X +352=0x%X +328=0x%X +324=0x%X +308=0x%X +76=%u\n",
        i,PPC_LOAD_U32(0x884D6740u+1876u),PPC_LOAD_U32(0x884D6740u+312u),
        PPC_LOAD_U32(0x884D6740u+352u),PPC_LOAD_U32(0x884D6740u+328u),
        PPC_LOAD_U32(0x884D6740u+324u),PPC_LOAD_U32(0x884D6740u+308u),PPC_LOAD_U16(0x884D678Cu));
  }
  // RT_MENUADV=1: clear the +312 gate. NEGATIVE RESULT: this HANGS the game inside sub_88137708's
  // post-+312 path (submenu/id-46 build). RT_MENUADV=2 additionally breadcrumbs the body via the
  // sub_88137498 wrapper + [wall4x] EXIT log to localize the hang (498 vs post-498/id-46 request).
  static int menuadv = std::getenv("RT_MENUADV") ? atoi(std::getenv("RT_MENUADV")) : 0;
  bool cleared=false;
  if(menuadv && PPC_LOAD_U16(0x884D678Cu)==4){
    // Clear BOTH transition gates sub_88137708 checks: +312 (checked before) and +328 (checked
    // at loc_881377DC — sub_88137498 fails to zero it in merged). With both 0 + +352==0 it should
    // request id 46 and advance +76->5. menuadv>=3 also clears +324.
    // +312 is cleared HERE (sub_88137498 doesn't touch it); +328 is cleared in the sub_88137498
    // wrapper AFTER that call, because sub_88137708 calls sub_88137498 (which re-sets +328=1)
    // BEFORE its own loc_881377DC +328 check.
    if(PPC_LOAD_U32(0x884D6740u+312u)!=0){ PPC_STORE_U32(0x884D6740u+312u,0); cleared=true; }
    static int lg=0; if(cleared && lg++<3) std::fprintf(stderr,"[menuadv] cleared +312 at +76=4 (+328 cleared post-498)\n");
  }
  if(menuadv>=2 && cleared){ static int a=0; if(a++<4) std::fprintf(stderr,"[wall4x] ENTER sub_88137708 (cleared, +328=0x%X)\n",PPC_LOAD_U32(0x884D6740u+328u)); }
  // [cmtgate] RT_CARDFSM (2026-07-25 commit-gate leg): d76==4 decision point. Commit d76 4->5 (stage
  // scene 0x2e @88227220) needs 6e94==0 && 6878==0 && +328==0; +352!=0 gives d76=7/8. Names which gate
  // differs between training (reaches d76=5) and normal-play (stalls at 4). Read-only, default-off.
  if(rt_cardfsm()){
    uint32_t d76=PPC_LOAD_U16(0x884D678Cu), e94=PPC_LOAD_U32(0x884D6E94u), g6878=PPC_LOAD_U32(0x884D6878u);
    uint32_t c328=PPC_LOAD_U32(0x884D6888u), c352=PPC_LOAD_U32(0x884D68A0u), e84=PPC_LOAD_U32(0x884D6E84u);
    uint32_t ga=PPC_LOAD_U32(0x884D66A0u), a0f=PPC_LOAD_U8(0x88449A0Fu), d674c=PPC_LOAD_U32(0x884D674Cu);
    static uint64_t lk=~0ull; static std::atomic<int> c{0};
    uint64_t k=((uint64_t)(d76&0xF))|((uint64_t)(e94!=0)<<4)|((uint64_t)(g6878!=0)<<5)|((uint64_t)(c328!=0)<<6)|((uint64_t)(c352!=0)<<7)|((uint64_t)(e84!=0)<<8)|((uint64_t)(ga!=0)<<9)|((uint64_t)(a0f!=0)<<10);
    if(k!=lk || c.fetch_add(1)<24){ lk=k;
      std::fprintf(stderr,"[cmtgate] 88137708 d76=%u | 6e94=%u 6878=%u | +328=%u +352=%u 6e84=%u | GATE_A(66a0)=%u a0f=%u 674c=%08X -> %s\n",
        d76,e94,g6878,c328,c352,e84,ga,a0f,d674c,
        (e94==0&&g6878==0)?((c352!=0)?"d76=7/8(+352)":((c328==0)?"COMMIT d76=5":"STALL(+328!=0)")):"SKIPPED(6e94/6878)");
    }
  }
  // [xscan] leg 26 (2026-07-25): differential memory scan to find a REGISTER-TRUE ship-X anchor.
  // RT_SHIPX (0x884D80B0) is a proven-dead instrument (always 0 while the ship visibly pins to
  // both walls), so every "is it playing / where is the ship" question lacks ground truth. The
  // drive holds LEFT/RIGHT/LEFT across the three dump points; a word that tracks the held
  // direction (low..high..low) IS the ship X. Dumps 0x88400000..0x88800000 (4MB) per phase.
  // v2: PHASE-ALIGNED dumps. Watch the live pad word; when the held horizontal direction changes,
  // restart a phase counter and dump 2s (120 frames) into each phase. Drive holds L,R,L,R so the
  // ship X must satisfy dump0≈dump2 (both left) and dump1≈dump3 (both right) — a far stronger
  // constraint than "between". Slots: 0..3.
  if(std::getenv("RT_XSCAN")){
    static int lastDir=-1, phaseN=0, slot=0;
    uint32_t pad=PPC_LOAD_U32(0x885C33D4u);
    int dir = (pad&0x04u)?1 : ((pad&0x08u)?2 : 0);
    if(dir!=lastDir){ lastDir=dir; phaseN=0; }
    phaseN++;
    if(dir!=0 && phaseN==120 && slot<4){
      char path[160]; std::snprintf(path,sizeof(path),"C:/tmp/xscan_%d.bin",slot);
      FILE* f=std::fopen(path,"wb");
      if(f){ std::fwrite(base+0x88400000u,1,0x400000u,f); std::fclose(f); }
      std::fprintf(stderr,"[xscan] dump%d dir=%s pad=0x%08X d76=%u\n",
        slot,dir==1?"LEFT":"RIGHT",pad,(unsigned)PPC_LOAD_U16(0x884D678Cu));
      slot++;
    }
  }
  uint32_t d76pre=PPC_LOAD_U16(0x884D678Cu);
  // [fielddiff] leg 22 (2026-07-25, post-retraction): d76=4 is PLAY-RUNNING (corrected ladder).
  // Training reaches a REAL stage here; normal play leaves the ROM in ATTRACT. Sample the field/
  // handoff state periodically during state 4 on BOTH paths — the diff names the handoff.
  if(std::getenv("RT_S5")){
    static std::atomic<int> fc{0}; int fi=fc.fetch_add(1);
    if((fi%180)==0 && fi<3600)
      std::fprintf(stderr,"[fielddiff] #%d d76=%u | field(885C1A20)=%u 574(INMODE)=%u 6e84=%u 6878=%u 6e94=%u 66a8=%u | 6738(stage)=%u 6794=%u 6798=%u 679c=%u 67b4=%u | 6870=%u 67c0=%u 67cc=%u 66a0=%u | +328=%u +352=%u slot0=0x%X\n",
        fi,(unsigned)PPC_LOAD_U16(0x884D678Cu),PPC_LOAD_U32(GA_FIELD_ACTIVE),PPC_LOAD_U32(0x887AD574u),
        PPC_LOAD_U32(0x884D6E84u),PPC_LOAD_U32(0x884D6878u),PPC_LOAD_U32(0x884D6E94u),
        PPC_LOAD_U32(0x884D66A8u),PPC_LOAD_U32(0x884D6738u),PPC_LOAD_U32(0x884D6794u),
        PPC_LOAD_U32(0x884D6798u),PPC_LOAD_U32(0x884D679Cu),PPC_LOAD_U32(0x884D67B4u),
        PPC_LOAD_U32(0x884D6870u),PPC_LOAD_U32(0x884D67C0u),PPC_LOAD_U32(0x884D67CCu),
        PPC_LOAD_U32(0x884D66A0u),PPC_LOAD_U32(0x884D6888u),PPC_LOAD_U32(0x884D68A0u),
        (unsigned)PPC_LOAD_U8(0x884D6CE8u));
  }
  __imp__sub_88137708(ctx,base);
  // [slotdiff] leg 20 (2026-07-25): at the d76 4->5 stage-entry edge, dump the FULL player-slot
  // record (0x884D6CE8, 0xC4 bytes) + the registration/mode globals. Run on BOTH training (plays)
  // and normal play (playerless) — the diff names the field the gameplay needs. Read-only.
  if(std::getenv("RT_S5") && d76pre==4 && PPC_LOAD_U16(0x884D678Cu)==5){
    static std::atomic<int> once{0};
    if(once.fetch_add(1)==0){
      char b[900]; int o=0;
      for(int w=0;w<0x31;w++) o+=std::snprintf(b+o,sizeof(b)-o,"%08X ",PPC_LOAD_U32(0x884D6CE8u+w*4u));
      std::fprintf(stderr,"[slotdiff] SLOT0(884D6CE8,0xC4): %s\n",b);
      o=0; for(int w=0;w<0x31;w++) o+=std::snprintf(b+o,sizeof(b)-o,"%08X ",PPC_LOAD_U32(0x884D6DACu+w*4u));
      std::fprintf(stderr,"[slotdiff] SLOT1(884D6DAC,0xC4): %s\n",b);
      std::fprintf(stderr,"[slotdiff] GLOBALS 6e84(mode)=%u 584=%u 6794=%u 6798=%u 679c=%u | 6cf0=%u 6cf1=%u 6cf2=%u 6cef=%u | 6738=%u 67b4=%u | a0e=%u a0f=%u a13=%u a1b=%u | 6ea0(shot)=0x%X 66c8=%u 66c4=%u\n",
        PPC_LOAD_U32(0x884D6E84u),PPC_LOAD_U32(GA_MB_MODE64),PPC_LOAD_U32(0x884D6794u),
        PPC_LOAD_U32(0x884D6798u),PPC_LOAD_U32(0x884D679Cu),
        (unsigned)PPC_LOAD_U8(0x884D6CF0u),(unsigned)PPC_LOAD_U8(0x884D6CF1u),
        (unsigned)PPC_LOAD_U8(0x884D6CF2u),(unsigned)PPC_LOAD_U8(0x884D6CEFu),
        PPC_LOAD_U32(0x884D6738u),PPC_LOAD_U32(0x884D67B4u),
        (unsigned)PPC_LOAD_U8(0x88449A0Eu),(unsigned)PPC_LOAD_U8(0x88449A0Fu),
        (unsigned)PPC_LOAD_U8(0x88449A13u),(unsigned)PPC_LOAD_U8(0x88449A1Bu),
        PPC_LOAD_U32(0x884D6EA0u),PPC_LOAD_U32(0x884D66C8u),PPC_LOAD_U32(0x884D66C4u));
    }
  }
  if(menuadv>=2 && cleared){ static int b=0; if(b++<4) std::fprintf(stderr,"[wall4x] EXIT sub_88137708 -> +76=%u (if this prints, hang is elsewhere)\n",PPC_LOAD_U16(0x884D678Cu)); }
}
// [ff0] LEG-17 probe (2026-07-07, agent RE): sub_88136FF0 = THE d76=4 side-slot
// ADVANCE/DEACTIVATE callback (invoked per active slot from sub_88137498's tail via
// sub_88135BA8(MB, 0x88136FF0, MB)). Its decoded gates (ppc_recomp.18.cpp:2861-3073):
//   gate = *(MB+52+side*4); if sub_88152B00(gate)!=0 -> not-ready, skip frame
//   MB+144 != 0 -> GLOBAL_BUSY path (needs b0F && GATE_A to deactivate)
//   slot+2 (u16) != 0 -> ADVANCE to next sub-screen (sub_88134520 magic re-init)
//   else DEACTIVATE-CHECK: byte 0x88449A0F, then GATE_A word 0x884D66A0 (one-shot
//   debounce pulse armed when MB+332==0 && MB+336==0) -> slot[0]=0 (deactivate,
//   +328 drops, id-46 branch opens). NO input read anywhere in the chain.
// This logs every gate to name the stuck branch. If NO [ff0] lines appear in state 5,
// sub_88137498 early-outs before its tail (instrument 498 next). RT_S5-gated.
extern "C" void __imp__sub_88136FF0(PPCContext& __restrict, uint8_t*);
extern "C" void __imp__sub_88152B00(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88136FF0){
  g_hb_ff0.fetch_add(1);
  if(std::getenv("RT_S5")){
    static std::atomic<int> cnt{0}; static uint64_t lastkey=~0ull;
    uint32_t slot=ctx.r3.u32, MB=ctx.r4.u32;
    int side=(int8_t)PPC_LOAD_U8(slot+1);
    uint32_t gate=(side>=0&&side<2)?PPC_LOAD_U32(MB+52+side*4):0;
    uint32_t busy=PPC_LOAD_U32(MB+144);
    uint32_t s2=PPC_LOAD_U16(slot+2);
    uint32_t b0F=PPC_LOAD_U8(0x88449A0Fu);
    uint32_t gA=PPC_LOAD_U32(0x884D66A0u);
    uint32_t c332=PPC_LOAD_U32(MB+332), c336=PPC_LOAD_U32(MB+336);
    uint32_t m1860=PPC_LOAD_U32(MB+1860);
    // CODE_REVIEW_0804: probe call on a CONTEXT COPY — the old save/restore covered only r3/r4;
    // r5-r12/cr/ctr stayed clobbered, i.e. the RT_S5 instrument was not read-only.
    uint32_t pend; { PPCContext ic=ctx; ic.r3.u32=gate; __imp__sub_88152B00(ic,base); pend=ic.r3.u32; }
    int i=cnt.fetch_add(1);
    uint32_t m8c=PPC_LOAD_U32(slot+0x8Cu);   // RT_CR328 leg 07-25: entry-confirmed flag — the
    // a0f!=0 (credit-mode) fork of sub_88136FF0 sets it 1 and keeps the slot ACTIVE (+328 stays
    // nonzero); counted by sub_88135D98. Decides which branch the port takes at slot2==0.
    uint64_t key=((uint64_t)(side&3)<<56)|((uint64_t)(pend&1)<<48)|((uint64_t)(busy!=0)<<40)
                |((uint64_t)(s2&0xFFFF)<<24)|((uint64_t)(b0F&0xFF)<<16)|((uint64_t)(gA!=0)<<8)|(m1860!=0?1:0)
                |((uint64_t)(PPC_LOAD_U32(0x884D67C0u)&1)<<33)|((uint64_t)(PPC_LOAD_U32(0x884D67C8u)!=0)<<34)
                |((uint64_t)(PPC_LOAD_U32(0x884D7664u)&7)<<35)|((uint64_t)(PPC_LOAD_U8(slot+7u)&0xF)<<38)
                |((uint64_t)(m8c!=0)<<42);
    if(i<8 || key!=lastkey || (i%600)==0)
      std::fprintf(stderr,"[ff0] #%d slot=0x%X side=%d gate=0x%X pend=%u busy144=0x%X slot2=%u b0F=0x%X gateA=0x%X c332=%u c336=%u m1860=0x%X inEn=%u demo=%u lock=%u fadeSt=%u fadeCt=%u edge33D4=0x%X scr=%u conf=%u m738=%u m8c=%u\n",
        i,slot,side,gate,pend,busy,s2,b0F,gA,c332,c336,m1860,
        PPC_LOAD_U32(0x884D67C0u),PPC_LOAD_U32(0x884D67C4u),PPC_LOAD_U32(0x884D67C8u),
        PPC_LOAD_U32(0x884D7664u),PPC_LOAD_U32(0x884D766Cu),PPC_LOAD_U32(0x885C33D4u),
        PPC_LOAD_U8(slot+7u),PPC_LOAD_U32(slot+0x24u),PPC_LOAD_U32(MB+0x738u),m8c);
    lastkey=key;
    // RT_SLOT2FIX (np7 finding): slot+2 = the confirm-animation countdown. A real A-press ARMS
    // it positive; sub_881339C8 counts it down to 0 and fires the 0x887AD4D8 confirm callback.
    // In merged it's never armed and the unconditional decrement UNDERFLOWS it to 0xFFFF (-1);
    // sub_88136FF0's advance test is `slot+2 != 0`, so -1 reads as "confirm in progress" ->
    // infinite ADVANCE churn (gate handle climbs 2/cycle), the MB+332/336 debounce keeps
    // resetting, GATE_A never pulses, the slot never deactivates, +328 stays 1 forever.
    // Clamp the underflow back to the healthy idle value 0 each call: churn stops, debounce
    // runs out, GATE_A pulses, slot[0]=0 -> +328=0 -> sub_88137708 REQ id=46 -> d76=5.
  }
  __imp__sub_88136FF0(ctx,base);
}
// [b930]/[b378] RT_CR328 leg 2 (2026-07-25, Fable-5): the sub-screen decide->scene-death chain.
// Register-true (reco_normal decomp): decide -> sub_8814B930 (arms per-side job record
// 0x8844A898+side*0xA0: +0x60(8F8)=1 step-armed, +0x64(8FC)=0, +0x68(900)=obj, +0x6C(904)=cont
// 0x8814B928; also slot+0x88=1, conf(slot+0x24)++, slot2-- via 881339C8, obj+0x54=3) ->
// sub_8814B378 (per-frame processor: 16 steps of +0x48/+0x4C cadence, then CALLS the continuation
// *(rec+0x6C) [mid-function target 0x8814B928 — indirect-dispatch landmine class] and CLEARS
// +0x60) -> sub_8814BFB0 state 4 waits for 8F8==0 -> state 5 -> 29 frames -> FUN_88152c60 scene
// kill -> [ff0] creates next sub-screen. Normal-play stalls with sub-screen 2 alive forever;
// training completes all 3. These probes name the stuck stage. Read-only, RT_S5-gated.
extern "C" void __imp__sub_8814B930(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_8814B930){
  if(std::getenv("RT_S5")){
    uint32_t s2a=PPC_LOAD_U16(0x884D6CEAu), cfa=PPC_LOAD_U32(0x884D6D0Cu);
    uint32_t r60a=PPC_LOAD_U32(0x8844A8F8u), r64a=PPC_LOAD_U32(0x8844A8FCu);
    __imp__sub_8814B930(ctx,base);
    static std::atomic<int> c{0}; int i=c.fetch_add(1);
    if(i<24) std::fprintf(stderr,"[b930] #%d DECIDE-COMMIT slot2 %u->%u conf %u->%u rec60 %u->%u rec64 %u->%u cont904=0x%X obj900=0x%X d76=%u\n",
      i,s2a,(uint32_t)PPC_LOAD_U16(0x884D6CEAu),cfa,(uint32_t)PPC_LOAD_U32(0x884D6D0Cu),
      r60a,(uint32_t)PPC_LOAD_U32(0x8844A8F8u),r64a,(uint32_t)PPC_LOAD_U32(0x8844A8FCu),
      (uint32_t)PPC_LOAD_U32(0x8844A904u),(uint32_t)PPC_LOAD_U32(0x8844A900u),(uint32_t)PPC_LOAD_U16(0x884D678Cu));
    return;
  }
  __imp__sub_8814B930(ctx,base);
}
extern "C" void __imp__sub_8814B378(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_8814B378){
  g_hb_b378.fetch_add(1);
  if(std::getenv("RT_S5") && ctx.r3.u32==0x8844A898u){
    uint32_t rec=ctx.r3.u32;
    uint32_t p60=PPC_LOAD_U32(rec+0x60u), p64=PPC_LOAD_U32(rec+0x64u);
    uint32_t obj=PPC_LOAD_U32(rec+0x68u);
    uint32_t pst=(obj>=0x82000000u&&obj<0x8A000000u)?PPC_LOAD_U8(obj+0x54u):0xEEu;
    __imp__sub_8814B378(ctx,base);
    uint32_t q60=PPC_LOAD_U32(rec+0x60u), q64=PPC_LOAD_U32(rec+0x64u);
    uint32_t qst=(obj>=0x82000000u&&obj<0x8A000000u)?PPC_LOAD_U8(obj+0x54u):0xEEu;
    uint32_t qb9=(obj>=0x82000000u&&obj<0x8A000000u)?PPC_LOAD_U8(obj+0xB9u):0xEEu;
    static uint64_t lk=~0ull; static std::atomic<int> c{0};
    uint64_t k=((uint64_t)(p60&1)<<40)|((uint64_t)(q60&1)<<36)|((uint64_t)(q64&0x1F)<<28)
              |((uint64_t)(pst&0xFF)<<16)|((uint64_t)(qst&0xFF)<<8)|((uint64_t)(obj!=0));
    int i=c.fetch_add(1);
    if(k!=lk || (q60&&(i%600)==0)){ lk=k;
      std::fprintf(stderr,"[b378] #%d rec60 %u->%u rec64 %u->%u obj=0x%X st54 %u->%u b9=%u gate8F8=%u e8=%u\n",
        i,p60,q60,p64,q64,obj,pst,qst,qb9,(uint32_t)PPC_LOAD_U32(0x8844A8F8u),(uint32_t)PPC_LOAD_U32(0x8844A8E8u)); }
    return;
  }
  __imp__sub_8814B378(ctx,base);
}
// [set] RT_CR328 leg 16 (2026-07-25): the SETTINGS APPLIERS — the a0f fork's writers.
// a0f(88449A0F) <- 885C6827 <- these four msg-dispatched appliers (game msg case N = protocol
// msg N+1): case 0xE/msg15 = sub_8808F1E8(blockPtr, x) NORMAL launch apply — param==0 -> FULL
// arcade defaults (880099CC byte3=1 -> 6827=1 -> a0f=1 -> the 15s credit-wait); param!=0 ->
// copies the SHELL'S 16-byte block raw (6827 = block byte7; SDK passes byte7=0 -> instant
// free-play consume, the 3s commit). case 0x11/msg18 = training efa8 (masked, a0f=0); 0xF/msg16
// = f150 (replay); 0x10/msg17 = f098 (score-attack, magic-gated). These wrappers log every call
// with params + the block bytes + 885C6820..2F after. RT_S5-gated, read-only.
static void xr_dump_setblk(const char* tag, PPCContext& ctx, uint8_t* base, uint32_t p1){
  char b[200]; int o=0;
  // D2 guard fix (Opus review): shell blocks live in LOW guest RAM (e.g. 0x340610) — the old
  // 0x82000000+ guard mislabeled them "(null/oob)". Accept any plausible guest address.
  if(p1>=0x1000u&&p1<0x8A000000u){ for(int w=0;w<16;w++) o+=std::snprintf(b+o,sizeof(b)-o,"%02X ",(unsigned)PPC_LOAD_U8(p1+(uint32_t)w)); }
  else std::snprintf(b,sizeof(b),"(null/oob)");
  char a[200]; int q=0;
  for(int w=0;w<16;w++) q+=std::snprintf(a+q,sizeof(a)-q,"%02X ",(unsigned)PPC_LOAD_U8(0x885C6820u+(uint32_t)w));
  std::fprintf(stderr,"[set] %s p1=0x%X blk[%s] post-6820[%s] a0f=%u d76=%u\n",
    tag,p1,b,a,(unsigned)PPC_LOAD_U8(0x88449A0Fu),(unsigned)PPC_LOAD_U16(0x884D678Cu));
}
extern "C" void __imp__sub_8808F1E8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_8808F1E8){
  uint32_t p1=ctx.r3.u32, p2=ctx.r4.u32; bool on=!!std::getenv("RT_S5");
  __imp__sub_8808F1E8(ctx,base);
  if(on){ std::fprintf(stderr,"[set] msg15/F1E8 p2=0x%X:\n",p2); xr_dump_setblk("msg15/F1E8",ctx,base,p1); }
}
extern "C" void __imp__sub_8808EFA8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_8808EFA8){
  uint32_t p1=ctx.r3.u32; bool on=!!std::getenv("RT_S5");
  __imp__sub_8808EFA8(ctx,base);
  if(on) xr_dump_setblk("msg18/EFA8(train)",ctx,base,p1);
}
extern "C" void __imp__sub_8808F150(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_8808F150){
  uint32_t p1=ctx.r3.u32; bool on=!!std::getenv("RT_S5");
  __imp__sub_8808F150(ctx,base);
  if(on) xr_dump_setblk("msg16/F150(replay)",ctx,base,p1);
}
extern "C" void __imp__sub_8808F098(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_8808F098){
  uint32_t p1=ctx.r3.u32; bool on=!!std::getenv("RT_S5");
  __imp__sub_8808F098(ctx,base);
  if(on) xr_dump_setblk("msg17/F098(scoreatk)",ctx,base,p1);
}
// leg-13 shared state: after a [25c8] timeline-init, force-log the next N sub_88131C30 calls
// (the change-key hides same-script calls) — proves whether the new 0x2b scene ticks at all.
static std::atomic<int> g_trk_force{0};
// [c60] leg 13: sub_88152C60 = scene DESTROY-enqueue (by handle/key; the 27b8 processor then
// REPLACES node[3] with the dtor proc — which would silently stop [trk] counting). Log first 48
// destroys with lr to catch who kills the 0x2b timeline scene (key logged by [25c8]).
extern "C" void __imp__sub_88152C60(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88152C60){
  if(std::getenv("RT_S5")){
    static std::atomic<int> c{0}; int i=c.fetch_add(1);
    if(i<48) std::fprintf(stderr,"[c60] #%d DESTROY handle=0x%X lr=0x%X d76=%u\n",
      i,ctx.r3.u32,(uint32_t)ctx.lr,(uint32_t)PPC_LOAD_U16(0x884D678Cu));
  }
  __imp__sub_88152C60(ctx,base);
}
// [a58]/[25c8] RT_CR328 leg 11 (2026-07-25): the timeline RESUME path. Case-8 else-branch
// (@140652) calls sub_88136A58 = kill W+0x10 scene, sync W+0x58=W+0x5c, CREATE page-timeline
// scene 0x2b (installer sub_881325C8: full timeline re-init from W+0x58 page cfg + registers
// sub_88131C30 tick on the scene node). Leg-10: the tick FROZE at menu-summon and never resumed
// — so either A58 never runs, or the 0x2b scene's tick never dispatches. These wrappers decide.
extern "C" void __imp__sub_88136A58(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88136A58){
  if(std::getenv("RT_S5")){
    static std::atomic<int> c{0}; int i=c.fetch_add(1);
    std::fprintf(stderr,"[a58] #%d CALLED r3=0x%X | W+10=0x%X pg58=%u pg5c=%u d76=%u fsm=0x%X\n",
      i,ctx.r3.u32,PPC_LOAD_U32(0x884D6750u),PPC_LOAD_U32(0x884D6798u),PPC_LOAD_U32(0x884D679Cu),
      (uint32_t)PPC_LOAD_U16(0x884D678Cu),PPC_LOAD_U32(0x8844A3B8u));
  }
  __imp__sub_88136A58(ctx,base);
}
extern "C" void __imp__sub_881325C8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_881325C8){
  if(std::getenv("RT_S5")){
    static std::atomic<int> c{0}; int i=c.fetch_add(1);
    uint32_t p2=ctx.r4.u32, key=ctx.r3.u32;
    std::fprintf(stderr,"[25c8] #%d TIMELINE-INIT r3=0x%X r4(W)=0x%X W+58(page)=%u W+5c=%u d76=%u\n",
      i,key,p2,(p2>=0x82000000u&&p2<0x8A000000u)?PPC_LOAD_U32(p2+0x58u):0xEEEEu,
      (p2>=0x82000000u&&p2<0x8A000000u)?PPC_LOAD_U32(p2+0x5Cu):0xEEEEu,(uint32_t)PPC_LOAD_U16(0x884D678Cu));
    __imp__sub_881325C8(ctx,base);
    // leg-12 audit: did the tail's tick-registration walk (node[2]==r3-at-entry → node[3]:=
    // 0x88131C30, silent return on miss) actually land? Dump the 88449D4C node list.
    uint32_t n=PPC_LOAD_U32(0x88449D4Cu); int k=0; int hit=-1;
    while(n>=0x82000000u&&n<0x8A000000u&&k<24){
      uint32_t nk=PPC_LOAD_U32(n+8u), tk=PPC_LOAD_U32(n+12u);
      std::fprintf(stderr,"[25c8]   node%d @0x%X key=0x%X tick=0x%X%s\n",k,n,nk,tk,
        (nk==key)?"  <== KEY MATCH":"");
      if(nk==key) hit=k;
      n=PPC_LOAD_U32(n); k++;
    }
    std::fprintf(stderr,"[25c8] WALK-AUDIT key=0x%X nodes=%d %s\n",key,k,
      hit>=0?"HIT (tick should be 0x88131C30 above)":"**MISS — tick NEVER registered**");
    g_trk_force.store(12);
    return;
  }
  __imp__sub_881325C8(ctx,base);
}
// [trk] RT_CR328 leg 10 (2026-07-25): sub_88131C30 = the pr43 timeline tick. Leg-9 found the ONE
// card-manager spawn in the whole image: track-command opcode 0x16 [frame=0x6B6=1718, type=0xD9]
// in PAGE-4 track-1's command stream (0x8805D19C; interpreter FUN_8822b520, opcode 0x16 gated
// *(track+0x390)==0). Port symptom: timeline parked at page-0 frame ~158, script never switches.
// This logs, every 300 ticks + on page/script change: script ptr, W+58(tgt page)/W+5c(cur page),
// active track 76F8, scan idx 76FC, and ALL FOUR track frames (884D7710+t*0xD4). RT_S5-gated.
extern "C" void __imp__sub_88131C30(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88131C30){
  if(std::getenv("RT_S5")){
    static std::atomic<int> c{0}; int i=c.fetch_add(1);
    static std::atomic<uint64_t> lk{~0ull};
    uint32_t scr=PPC_LOAD_U32(0x884D7700u), p58=PPC_LOAD_U32(0x884D6798u), p5c=PPC_LOAD_U32(0x884D679Cu);
    uint64_t k=((uint64_t)scr<<8)|((p58&0xF)<<4)|(p5c&0xF);
    int fv=g_trk_force.load(); if(fv>0) g_trk_force.fetch_add(-1);
    // leg-14 one-shot: full runtime dump of the timeline header + all 4 track records at the
    // plateau (call #1500), for the VM-decode agent to correlate against FUN_8822b520 fields.
    if(i==1500){
      char b[640]; int o=0;
      o=0; for(int w=0;w<18;w++) o+=std::snprintf(b+o,sizeof(b)-o,"%08X ",PPC_LOAD_U32(0x884D76C8u+w*4u));
      std::fprintf(stderr,"[trkdump] HDR 884D76C8: %s\n",b);
      for(int t=0;t<4;t++){
        uint32_t ba=0x884D7710u+t*0xD4u;
        for(int half=0;half<4;half++){
          o=0; int w0=half*14, w1=(half==3)?53:(half+1)*14;
          for(int w=w0;w<w1;w++) o+=std::snprintf(b+o,sizeof(b)-o,"%08X ",PPC_LOAD_U32(ba+w*4u));
          std::fprintf(stderr,"[trkdump] T%d+%03X: %s\n",t,w0*4,b);
        }
      }
    }
    if(k!=lk.exchange(k) || (i%300)==0 || fv>0)
      std::fprintf(stderr,"[trk] #%d%s scr=0x%X pg58=%u pg5c=%u trk=%u idx=%u f0=%u f1=%u f2=%u f3=%u 7a58=%u\n",
        i,(fv>0)?" POST-INIT":"",
        scr,p58,p5c,PPC_LOAD_U32(0x884D76F8u),PPC_LOAD_U32(0x884D76FCu),
        PPC_LOAD_U32(0x884D7710u),PPC_LOAD_U32(0x884D7710u+0xD4u),
        PPC_LOAD_U32(0x884D7710u+0x1A8u),PPC_LOAD_U32(0x884D7710u+0x27Cu),
        PPC_LOAD_U32(0x884D7A58u));
  }
  __imp__sub_88131C30(ctx,base);
}
// [tsp] RT_CR328 leg 9 (2026-07-25): sub_880957A8 = the ROM-TIMELINE child spawner
// (FUN_880957a8(type, frame, ...) from sub_88131C30's script walker; script ptr DAT_884D7700,
// u16 records [frame,type,idx,flags,x,y]; card-confirm managers = types 0xD8/0xD9 via type table
// 0x88252fe8). Logs every spawn's type+frame (first 48 + all types>=0xC0 + every 300th) with the
// spawn gates (7a58 fast-forward flag, W+744 mode, W+760 shot). On first call, one-shot scans the
// live script for 0xD8/0xD9 records and prints their frames + current track frame/scan index.
// Answers: does the timeline ever reach a card spawn on the port? RT_S5-gated, read-only.
extern "C" void __imp__sub_880957A8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_880957A8){
  if(std::getenv("RT_S5")){
    uint32_t ty=ctx.r3.u32, fr=ctx.r4.u32;
    static std::atomic<int> c{0}; int i=c.fetch_add(1);
    static std::atomic<uint32_t> lastScr{0xFFFFFFFFu}; static std::atomic<int> ndump{0};
    uint32_t scrNow=PPC_LOAD_U32(0x884D7700u);
    if(scrNow!=lastScr.exchange(scrNow) && ndump.fetch_add(1)<6){
      uint32_t scr=scrNow;
      uint32_t trk=PPC_LOAD_U32(0x884D76F8u);
      uint32_t trkfr=(trk<8)?PPC_LOAD_U32(0x884D7710u+trk*0xD4u):0xEEEEu;
      std::fprintf(stderr,"[tsp] SCRIPT dump: ptr(884D7700)=0x%X track=%u trackframe=%u scanidx=%u tracks(76E4)=%u\n",
        scr,trk,trkfr,PPC_LOAD_U32(0x884D76FCu),PPC_LOAD_U32(0x884D76E4u));
      if(scr>=0x88000000u&&scr<0x8A000000u){
        int shown=0;
        for(uint32_t r=0;r<2000;r++){
          uint32_t a=scr+r*12u;
          uint32_t f=PPC_LOAD_U16(a), t=PPC_LOAD_U16(a+2u);
          if(f==0xFFFFu){ std::fprintf(stderr,"[tsp] SCRIPT end at rec %u (frame 0xFFFF)\n",r); break; }
          if(t==0xD8u||t==0xD9u||t==0x30u||t==0xE5u){
            std::fprintf(stderr,"[tsp] SCRIPT rec%u frame=%u type=0x%X idx=%u fl=0x%X x=%u y=%u\n",
              r,f,t,(uint32_t)PPC_LOAD_U16(a+4u),(uint32_t)PPC_LOAD_U16(a+6u),
              (uint32_t)PPC_LOAD_U16(a+8u),(uint32_t)PPC_LOAD_U16(a+10u));
            if(++shown>=24) { std::fprintf(stderr,"[tsp] SCRIPT (24+ hits, truncated)\n"); break; }
          }
        }
      }
    }
    if(ty==0xD8u||ty==0xD9u||ty>=0xC0u||i<48||(i%300)==0)
      std::fprintf(stderr,"[tsp] #%d SPAWN type=0x%X frame=%u | 7a58=%u W744=%u W760=0x%X trkfr=%u %s\n",
        i,ty,fr,PPC_LOAD_U32(0x884D7A58u),PPC_LOAD_U32(0x884D6E84u),PPC_LOAD_U32(0x884D6EA0u),
        (PPC_LOAD_U32(0x884D76F8u)<8)?PPC_LOAD_U32(0x884D7710u+PPC_LOAD_U32(0x884D76F8u)*0xD4u):0xEEEEu,
        (ty==0xD8u||ty==0xD9u)?"<<<< CARD-MANAGER SPAWN":"");
  }
  __imp__sub_880957A8(ctx,base);
}
// [bf10] RT_CR328 leg 5: sub_8814BF10 = the sub-screen INPUT CALLBACK (registered via
// FUN_881556a0(1, side+2) at scene install). Register-true decide gate (decomp 138496-138502):
// fires sub_8814B930 iff !(edge&0x40) && obj+0x54==0 && (W+0x78[67B8] + slot+0x70[6D58])==0 &&
// (edge&0xC18)!=0. ED8's tail pegs 67B8=0x7FFFFFFF every frame while 67BC!=0 (12553x). Leg-4:
// decides 1-2 committed, sub-screen 3 (scene 0x15) alive but decides 3-5 rejected. This logs the
// edge word + every gate operand to name the reject. RT_S5-gated, logs nonzero edges + heartbeat.
extern "C" void __imp__sub_8814BF10(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_8814BF10){
  if(std::getenv("RT_S5")){
    uint32_t p1=ctx.r3.u32, obj=ctx.r5.u32;
    uint32_t e0=p1?PPC_LOAD_U32(p1):0xDEADu, e1=p1?PPC_LOAD_U32(p1+4):0xDEADu;
    uint32_t st=(obj>=0x82000000u&&obj<0x8A000000u)?PPC_LOAD_U8(obj+0x54u):0xEEu;
    uint32_t ty=(obj>=0x82000000u&&obj<0x8A000000u)?PPC_LOAD_U8(obj+0x9Eu):0xEEu;
    uint32_t g78=PPC_LOAD_U32(0x884D67B8u), g70=PPC_LOAD_U32(0x884D6D58u), gbc=PPC_LOAD_U32(0x884D67BCu);
    static std::atomic<int> c{0}; int i=c.fetch_add(1);
    if(e0!=0 || (i%600)==0)
      std::fprintf(stderr,"[bf10] #%d edge=0x%X e1=0x%X obj=0x%X st54=%u ty9e=%u | 67B8=0x%X 6D58=0x%X 67BC=%u -> %s\n",
        i,e0,e1,obj,st,ty,g78,g70,gbc,
        ((e0&0x40u)==0 && st==0 && (g78+g70)==0 && (e0&0xC18u)!=0)?"DECIDE":"no");
  }
  __imp__sub_8814BF10(ctx,base);
}
// [hb] leg-3 wrappers: sub_8814D400 tick counter; sub_88104230 (coin display, pr32, provably alive
// to run end) emits the heartbeat line every 300 calls under RT_S5. gate34 = W+0x34 (0x884D6774,
// side-0 select-scene handle), pend via sub_88152B00 like the [ff0] probe.
extern "C" void __imp__sub_8814D400(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_8814D400){
  g_hb_d400.fetch_add(1);
  __imp__sub_8814D400(ctx,base);
}
extern "C" void __imp__sub_88104230(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88104230){
  static std::atomic<uint32_t> c{0};
  uint32_t i=c.fetch_add(1);
  static const bool rtS5 = std::getenv("RT_S5")!=nullptr;
  if(rtS5 && (i%300)==0){
    uint32_t gate=PPC_LOAD_U32(0x884D6774u);
    // CODE_REVIEW_0804: probe on a context copy (see the twin note above)
    uint32_t pend; { PPCContext ic=ctx; ic.r3.u32=gate; __imp__sub_88152B00(ic,base); pend=ic.r3.u32; }
    std::fprintf(stderr,"[hb] #%u c708=%u c498=%u cff0=%u cb378=%u cd400=%u cf558=%u | d76=%u +328=%u slot0=0x%X slot2=%u conf=%u gate34=0x%X pend=%u\n",
      i,g_hb_708.load(),g_hb_498.load(),g_hb_ff0.load(),g_hb_b378.load(),g_hb_d400.load(),g_hb_f558.load(),
      (uint32_t)PPC_LOAD_U16(0x884D678Cu),(uint32_t)PPC_LOAD_U32(0x884D6888u),
      (uint32_t)PPC_LOAD_U8(0x884D6CE8u),(uint32_t)PPC_LOAD_U16(0x884D6CEAu),
      (uint32_t)PPC_LOAD_U32(0x884D6D0Cu),gate,pend);
  }
  __imp__sub_88104230(ctx,base);
}
// [d98] RT_CR328 leg (2026-07-25, Fable-5): sub_88135D98 = count slots that are ACTIVE (bit0) AND
// entry-confirmed (+0x8c!=0) — the credit-mode "ready" census. In credit mode (0x88449A0F!=0) the
// slot never self-deactivates in sub_88136FF0; something must poll this count and drive the
// confirm-widget page flow (-> case 0xC -> 881362D0 sweep = the credit-consume). Logging lr names
// the poller (or its absence) on normal-play vs training. Read-only, RT_S5-gated, change-keyed.
extern "C" void __imp__sub_88135D98(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88135D98){
  if(std::getenv("RT_S5")){
    uint32_t lr=(uint32_t)ctx.lr, p1=ctx.r3.u32, p2=ctx.r4.u32;
    __imp__sub_88135D98(ctx,base);
    uint32_t ret=ctx.r3.u32;
    uint32_t f1=p1?PPC_LOAD_U32(p1):0xEEu, f2=p2?PPC_LOAD_U32(p2):0xEEu;
    static std::atomic<int> c{0}; static uint64_t lk=~0ull;
    uint64_t k=((uint64_t)lr<<8)|((ret&0xF)<<4)|((f1!=0&&f1!=0xEEu)?2:0)|((f2!=0&&f2!=0xEEu)?1:0);
    int i=c.fetch_add(1);
    if(i<8 || k!=lk || (i%600)==0)
      std::fprintf(stderr,"[d98] #%d lr=0x%X ret=%u p1flag=0x%X p2flag=0x%X\n",i,lr,ret,f1,f2);
    lk=k;
    return;
  }
  __imp__sub_88135D98(ctx,base);
}
// [cd] (2026-07-13, gate-wall RE): sub_881339C8 = the slot+2 confirm/phase countdown
// (reco_normal decomp 122646): decrements ONLY while *(MB+0x758)==0; when slot+2 < 1 it fires
// the commit through the FUNCTION POINTER at 0x887AD4D8 (args: 0x887AD4DC ctx word, side!=0, 0)
// and returns 0. The d76=4 stall loop shows slot2 cycling 3->2->1->3 with no visible 0 — either
// the 0-edge happens between [ff0] samples and the callback ptr is NULL in merged (commit no-op,
// caller re-inits the next phase at 3), or MB+0x758 throttles the decrement. This wrapper logs
// pre/post, the hold word, and the callback ptr on every call under RT_S5.
extern "C" void __imp__sub_881339C8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_881339C8){
  if(std::getenv("RT_S5")){
    uint32_t slot=ctx.r3.u32;
    uint16_t pre=(uint16_t)PPC_LOAD_U16(slot+2u);
    uint32_t mb=PPC_LOAD_U32(slot+128u);
    uint32_t hold758=mb?PPC_LOAD_U32(mb+0x758u):0xDEADBEEFu;
    uint32_t cb=PPC_LOAD_U32(0x887AD4D8u);
    __imp__sub_881339C8(ctx,base);
    uint16_t post=(uint16_t)PPC_LOAD_U16(slot+2u);
    static int cnt=0; static uint64_t lk=~0ull;
    uint64_t k=((uint64_t)pre<<32)|((uint64_t)post<<16)|((uint64_t)(hold758!=0)<<1)|(uint64_t)(cb!=0);
    int i=cnt++;
    if(i<12 || k!=lk || (pre<=1))
      std::fprintf(stderr,"[cd] #%d slot=0x%X s2 %u->%u hold758=0x%X cb4D8=0x%X ret=%u\n",
        i,slot,pre,post,hold758,cb,(uint32_t)ctx.r3.u32);
    lk=k;
    return;
  }
  __imp__sub_881339C8(ctx,base);
}
// LEG-14: breadcrumb sub_88137498 (called first inside sub_88137708 post-+312) to split the hang:
// if ENTER prints but not EXIT under RT_MENUADV=2, the hang is inside 88137498's 6 sub-calls;
// if both print, the hang is AFTER it (the id-46 sub_881526C0 request path).
extern "C" void __imp__sub_88137498(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88137498){
  g_hb_498.fetch_add(1);
  int menuadv = std::getenv("RT_MENUADV") ? atoi(std::getenv("RT_MENUADV")) : 0;
  static std::atomic<int> e{0};
  bool log = menuadv>=2 && e.load()<4;
  if(log){ e++; std::fprintf(stderr,"[498] ENTER\n"); }
  __imp__sub_88137498(ctx,base);
  // LEG-15 REVIEW: log the ACTUAL post-reset gate values sub_88137708 will check at loc_881377DC
  // (+1876/+312/+352/+328 — advance to +76=5 needs ALL of +312,+352,+328 == 0). This is BEFORE the
  // RT_MENUADV clear below, so it shows the NATURAL blocker. RT_S5-gated, first 20 + on-change.
  if(std::getenv("RT_S5")){
    uint32_t g1876=PPC_LOAD_U32(0x884D6740u+1876u), g312=PPC_LOAD_U32(0x884D6740u+312u);
    uint32_t g352=PPC_LOAD_U32(0x884D6740u+352u), g328=PPC_LOAD_U32(0x884D6740u+328u);
    static uint32_t last=0xFFFFFFFFu; uint32_t key=(g1876?8:0)|(g312?4:0)|(g352?2:0)|(g328?1:0);
    static std::atomic<int> ne{0}; int i=ne.fetch_add(1);
    if(i<20 || key!=last){ last=key;
      std::fprintf(stderr,"[498gate] call#%d POST-498 +1876=0x%X +312=0x%X +352=0x%X +328=0x%X +76=%u %s\n",
        i,g1876,g312,g352,g328,PPC_LOAD_U16(0x884D678Cu),
        (g312==0&&g352==0&&g328==0)?"<-- WOULD ADVANCE to 5":"<-- BLOCKED"); }
  }
  // RT_MENUADV: sub_88137498 leaves +328=1 in merged (native zeroing at loc_88137518 doesn't
  // stick), which then makes sub_88137708 exit at loc_881377DC. Clear it here (post-call) at
  // +76==4 so the id-46/+76->5 advance can proceed. +324 too under menuadv>=3.
  if(menuadv && PPC_LOAD_U16(0x884D678Cu)==4){
    PPC_STORE_U32(0x884D6740u+328u,0);
    if(menuadv>=3) PPC_STORE_U32(0x884D6740u+324u,0);
  }
  // LEG-15 CONTINUATION — RT_START352: the sub_88137708 advance to gameplay needs +312==0 AND
  // (+352!=0 -> id=48/+76=7  OR  +328==0 -> id=46/+76=5). sub_88136660 is the native +352=1 setter
  // (dispatched indirectly; the "start" menu action, never reached in merged). Post-498 at d76==4,
  // set +352=1 (route to the id=48 gameplay branch) + clear +312 (the pre-gate). Leave +328 alone.
  // If +1860!=0 the branch diverts (loc_881377B4) — clear it too so id=48 fires. Success = +76->7,
  // [res] REQ id=48, scene leaves the menu, a stage/gameplay asset loads.
  if(std::getenv("RT_START352") && PPC_LOAD_U16(0x884D678Cu)==4){
    PPC_STORE_U32(0x884D6740u+352u,1);   // +352 = 1  (take the id=48 branch)
    PPC_STORE_U32(0x884D6740u+312u,0);   // +312 = 0  (pass the pre-gate)
    if(atoi(std::getenv("RT_START352"))>=2) PPC_STORE_U32(0x884D6740u+1860u,0); // force id=48 (not loc_881377B4)
    static std::atomic<int> s3{0}; int q=s3.fetch_add(1);
    if(q<5||(q%2000)==0) std::fprintf(stderr,"[start352] set +352=1 +312=0 at d76=4 #%d (+1860=0x%X)\n",q,PPC_LOAD_U32(0x884D6740u+1860u));
  }
  if(log) std::fprintf(stderr,"[498] EXIT +328=0x%X (post-clear)\n",PPC_LOAD_U32(0x884D6740u+328u));
  // ══ RT_LIVEPLAY (2026-07-23, FIRST-LIVE-GAMEPLAY leg, Fable-5 RE) ═══════════════════════════
  // NOVEL PATH to the live credited stage loop, decomp-grounded (reco_normal sub_88137708 @125051,
  // sub_88136890 @124488, sub_88136978 @124521). The register-true credited-start decision tree:
  //   sub_88137708 (session state 4): runs only if +312(0x884D6878)==0 && 6e94==0. Then
  //     +352(0x884D68A0)!=0 -> (6e84==0 ? state7/id48 -> state6 NAME-ENTRY : state8 STAGES)   [checked FIRST]
  //     else +328(0x884D6888)==0 -> spawn id46 FADE (0x88227220) -> state5.
  //   sub_88136890 (state 5, when the id46 fade dies): (+352==0 && 6e84==0) -> state6 NAME-ENTRY;
  //     ELSE -> ★ state8 -> session returns 0 -> OUTER FSM 5->2->3 = LIVE STAGE LOOP ★.
  // So: setting +352 AT STATE 4 routes to NAME-ENTRY (prior RT_START352/RT_STARTACT dead end,
  // because 6e84==DAT_887ad584==0 for NORMAL PLAY). The WINNING sequence is:
  //   (1) at state 4, clear ONLY +328 (leave +312/+352) -> take the FADE branch -> state 5;
  //   (2) at state 5 (below, in the sub_88137ED8 wrapper) set +352=1 -> when the fade dies,
  //       sub_88136890's ELSE branch fires -> state 8 -> outer state 3 LIVE STAGES.
  // This is the step-(1) half. Env-gated; default off (byte-identical). Verify with RT_SCENELOG.
  if(std::getenv("RT_LIVEPLAY") && PPC_LOAD_U16(0x884D678Cu)==4){
    uint32_t p352=PPC_LOAD_U32(0x884D68A0u), p328=PPC_LOAD_U32(0x884D6888u), p312=PPC_LOAD_U32(0x884D6878u);
    if(p352==0 && p328!=0){
      PPC_STORE_U32(0x884D6888u,0);   // +328 = 0  -> sub_88137708 takes the id46-FADE branch -> state 5
      static std::atomic<int> lc{0}; int q=lc.fetch_add(1);
      if(q<8||(q%2000)==0) std::fprintf(stderr,"[liveplay] state4: cleared +328(6888) 0x%X->0 (+312/6878=0x%X +352=0x%X) -> fade->state5\n",p328,p312,p352);
    }
  }
}
SM_WRAP(sub_88133B68)
SM_WRAP(sub_88138C30)
// [cred320] observe the credited-start sub_88137320: its guard (sub_88152b00(884d674c)==0) + whether
// it ran to completion (DAT_884d6e94 set 1 at the tail). Always cheap (fires once). RT_ARMCRED leg.
extern "C" void __imp__sub_88137320(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88137320){
  uint32_t s674c=PPC_LOAD_U32(0x884D674Cu), e94b=PPC_LOAD_U32(0x884D6E94u);
  __imp__sub_88137320(ctx,base);
  uint32_t e94a=PPC_LOAD_U32(0x884D6E94u), inmode=PPC_LOAD_U32(0x887AD574u);
  static std::atomic<int> n{0}; int i=n.fetch_add(1);
  if(i<8) std::fprintf(stderr,"[cred320] sub_88137320 #%d: 674c=0x%X e94 %u->%u (1=RAN credited-start) inmode574=%u lives[77c8=%u 789c=%u]\n",
    i,s674c,e94b,e94a,inmode,PPC_LOAD_U32(0x884D77C8u),PPC_LOAD_U32(0x884D789Cu));
}
extern "C" void __imp__sub_8808D1B8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_8808D1B8){
  if(std::getenv("RT_HUB")){ static std::atomic<int> n{0}; int i=n++;
    if(i<20) std::fprintf(stderr,"[hub] D1B8 bit-notify#%d r3=%u slot610={fn=0x%X arg=0x%X}\n",
      i,ctx.r3.u32,PPC_LOAD_U32(0x887AD610u),PPC_LOAD_U32(0x887AD614u)); }
  __imp__sub_8808D1B8(ctx,base);
}

// LEG-15 (RT_QDIAG=1): the state-2 teardown quiesce handshake. sub_88092460 sets quiesce flag
// *(0x887AD1AC)=1 then spin-waits (1ms sleeps) for the game worker sub_88092C28 to clear it.
// Wrap ENTER/EXIT: an ENTER with NO matching EXIT = the spin hangs (worker never ACKs). ENTER..EXIT
// pairs = it self-heals. Also logs the existence guard *(0x8829AE1C) (== -1 => handshake skipped).
extern "C" void __imp__sub_88092460(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88092460){
  bool lg = std::getenv("RT_QDIAG")!=nullptr;
  static std::atomic<int> seq{0}; int i=lg?seq++:0;
  if(lg && (i<12||(i%200)==0))
    std::fprintf(stderr,"[q] 92460 ENTER#%d guard(8829AE1C)=0x%X flag(887AD1AC)=0x%X\n",
      i,PPC_LOAD_U32(0x8829AE1Cu),PPC_LOAD_U32(0x887AD1ACu));
  __imp__sub_88092460(ctx,base);
  if(lg && (i<12||(i%200)==0))
    std::fprintf(stderr,"[q] 92460 EXIT#%d flag(887AD1AC)=0x%X\n",i,PPC_LOAD_U32(0x887AD1ACu));
}

// sub_88138F00 scene machine with STATE logging: dispatches on state *(0x884D66A8) (0..6). Log
// the state each tick (first 60 + on every change) to see whether it ADVANCES past the loading
// state or is pinned. Also count total ticks. (Replaces its former TB_WRAP.)
extern "C" void __imp__sub_88138F00(PPCContext& __restrict, uint8_t*);
extern "C" void __imp__sub_88136660(PPCContext& __restrict, uint8_t*);  // native "start" action (RT_STARTACT)
extern "C" void __imp__sub_88133E30(PPCContext& __restrict, uint8_t*);  // ranking-insert (RT_PJOIN live-run mark)
extern "C" void __imp__sub_88133DB0(PPCContext& __restrict, uint8_t*);  // live-player rank check (RT_PJOIN verify)
extern "C" void __imp__sub_88134658(PPCContext& __restrict, uint8_t*);  // slot ACTIVATOR (1P SIDE START: slot+0=1, credits, score=0) — LEG-40f
extern "C" void __imp__sub_88136BC8(PPCContext& __restrict, uint8_t*);  // STAGE-SIM creator: creates REQ id-44 (factory sub_8814FDF8 -> per-frame stage tick sub_8814F558) — RT_STAGERUN (Fable-5 RE)
// Cross-module capture gate (2026-07-14): set to 1 by the RT_NAVREAL observer once the arcade-select
// FSM has SUBMITTED to gameplay (maxD76>=8 = real stage entered). vk_render.cpp's RVK_ARENADUMP
// reads this so the one-shot PM4 kick-arena capture fires on the REAL held stage-1 field, not the
// attract-under-menu field (which is also field_active!=0) or a config-menu frame.
// L4/E6: DEFINITION moved to merged_bridge.cpp (host side) — same class as g_rt_romactive above:
// this TU is DLL-resident and vk_render.cpp reads the flag.
extern std::atomic<long> g_spriteAllocs;  // defined at the sub_881538C0 wrapper below
extern std::atomic<int> g_syn_quiet;      // shell/gen/stubs.cpp — silences the synthetic pad
static std::atomic<int> g_smf{0};
static std::atomic<uint32_t> g_smf_last{0xFFFFFFFFu};
PPC_FUNC(sub_88138F00){
  uint32_t st=PPC_LOAD_U32(0x884D66A8u);
  int n=g_smf.fetch_add(1);
  uint32_t prev=g_smf_last.exchange(st);
  // RT_TICKRATE (2026-07-27, FNF-5 severity — Fable panel ordered-plan item 1): guest LOGIC
  // tick rate vs WALL CLOCK, ticks not frames. This pump (outer scene FSM) runs once per guest
  // logic frame, so its rate IS the simulation rate; hardware runs it at 60/s unconditionally.
  // If the port's guest logic is welded to the present path, this rate becomes a function of
  // host render throughput — the correctness-class defect the panel named. Logs a 5s-window
  // rate + the gameplay-field flag (0x885C1A20) + outer state, so one drive yields per-phase
  // rates (menu vs in-stage). Default-off, read-only, byte-inert.
  if(std::getenv("RT_TICKRATE")){
    static std::chrono::steady_clock::time_point tr0 = std::chrono::steady_clock::now();
    static int trn0 = n; static long trwin = 0;
    double dt = std::chrono::duration<double>(std::chrono::steady_clock::now() - tr0).count();
    if(dt >= 5.0){
      uint32_t fa=PPC_LOAD_U32(GA_FIELD_ACTIVE);
      std::fprintf(stderr,"[tickrate] win%ld ticks=%d dt=%.3fs rate=%.3f/s field=%u outer=%u\n",
                   trwin++, n-trn0, dt, (double)(n-trn0)/dt, fa, st);
      tr0 = std::chrono::steady_clock::now(); trn0 = n;
    }
  }
  // [credlog] RT_CREDLOG (2026-07-22, ATTRACT->CREDITED leg, Fable-5 RE) — telemetry for the
  // credited-play INPUT chain, decomp-grounded (reco):
  //   * DAT_887ad574 = INPUT MODE selector: 0=LIVE, 2=RECORD, 4=REPLAY(attract demo). Only ==4
  //     ignores the live pad (FUN_8808f2c0 @21326: !=4 reads the exchange buffer via FUN_8808e7d8
  //     and writes DAT_887ad5b0; ==4 reads canned replay bytes). FUN_88137320 sets it 0 (@124956),
  //     FUN_88137168 sets it 2 when credits 6e84==0 (@124889-90) or 4 when 6e84==1 (@124893).
  //   * exchange buffer 0x88699894/98 = the SHELL-provided live pad (worker FUN_8808fb90 @21694
  //     calls cb3 DAT_887ad5a8 to fill it). If this carries button bits when keys are pressed, the
  //     shell input provider works and the only lock is 887ad574.
  //   * DAT_887ad5b0 = P1 field-input buffer -> DAT_885c33d4 = 887ad5b0&0xb0ff (reco:156522) ->
  //     ship control. DAT_885c33d8 = 33d4 & ~33d0 = the EDGE (used for title START advance).
  //   * cb4 DAT_887ad4d8 / cb3 DAT_887ad5a8 = shell callbacks installed by GameEntry msg9 (case8,
  //     reco:305083-90). Non-null => the shell driver ran its init burst.
  //   * DAT_887ad58c = credited/pause mailbox: ==2 (GameEntry msg14/case0xd, guarded 887ad547==0)
  //     is the ONLY trigger for the credited-arm FUN_88137320 (outer state5, iVar8==2). Read HERE
  //     before __imp__ clears it (@126020).  ==1 (msg13) => outer state5->2 reset.
  //   * 763c/7640 = per-player join gates (NO game-side writer). credited flags 77c8/789c/7970/7a44.
  // Logs on change of the decisive subset + >=1/2s. Default-off, byte-inert (read-only).
  if(std::getenv("RT_CREDLOG")){
    uint32_t inmode=PPC_LOAD_U32(0x887AD574u), pause=PPC_LOAD_U32(GA_MB_RELOAD),
             vstart=PPC_LOAD_U32(0x887AD59Cu), p1buf=PPC_LOAD_U16(0x887AD5B0u),
             fld=PPC_LOAD_U16(0x885C33D4u), fldedge=PPC_LOAD_U16(0x885C33D8u),
             cb4=PPC_LOAD_U32(0x887AD4D8u), cb3=PPC_LOAD_U32(0x887AD5A8u),
             ex0=PPC_LOAD_U32(0x88699894u), ex1=PPC_LOAD_U32(0x88699898u),
             j0=PPC_LOAD_U32(0x884D763Cu), j1=PPC_LOAD_U32(0x884D7640u),
             cf0=PPC_LOAD_U32(0x884D77C8u), cred=PPC_LOAD_U32(0x884D6E84u),
             mode=PPC_LOAD_U32(GA_MB_MODE64), sess=PPC_LOAD_U16(0x884D678Cu),
             fa=PPC_LOAD_U32(GA_FIELD_ACTIVE);
    int32_t sx=(int32_t)PPC_LOAD_U32(0x884D80B0u);   // authoritative ship-X (gameplay-core atlas)
    static uint64_t lastk=~0ull; static int lastlog=-1000;
    uint64_t k=((uint64_t)(inmode&7)<<0)|((uint64_t)(pause&3)<<3)|((uint64_t)(cb4!=0)<<5)
             |((uint64_t)(cb3!=0)<<6)|((uint64_t)(ex0!=0)<<7)|((uint64_t)(fld!=0)<<8)
             |((uint64_t)(j0!=0)<<9)|((uint64_t)(j1!=0)<<10)|((uint64_t)(cf0!=0)<<11)
             |((uint64_t)(st&7)<<12)|((uint64_t)(sess&0xF)<<15)|((uint64_t)(cred&0xF)<<19)
             |((uint64_t)(mode&7)<<23)|((uint64_t)(vstart!=0)<<26)|((uint64_t)(p1buf!=0)<<27);
    if(k!=lastk || n-lastlog>=120){ lastk=k; lastlog=n;
      std::fprintf(stderr,"[credlog] f%d out=%u sess=%u fa=%u | INMODE574=%u pause58c=%u vstart59c=0x%X | EXCH[%08X %08X] p1buf5b0=0x%04X fld33d4=0x%04X | cb4=%s cb3=%s | j0=%u j1=%u credflags=%u cred6e84=%u mode584=%u | shipX=%d\n",
        n,st,sess,fa,inmode,pause,vstart,ex0,ex1,p1buf,fld,cb4?"Y":"n",cb3?"Y":"n",j0,j1,cf0,cred,mode,sx);
    }
  }
  // ══ RT_INTAP (2026-07-23 FREE-PLAY INPUT leg, Fable-5) ════════════════════════════════════════
  // CORRECT-ENDIANNESS input tracer. The [credlog]/[shipx] probes read 0x885C33D4 with
  // PPC_LOAD_U16 — but sub_88168C80 STORES it with `stw` (PPC_STORE_U32, recomp ppc_recomp.21
  // line ~29691): the payload lands in the LOW halfword of the word, so a U16 read at 0x885C33D4
  // returns the HIGH half = 0x0000 always. That telemetry artifact is the entire basis of the
  // "33d4 stays 0 in RECORD" premise. Read the WORDS as U32 here to see the real values:
  //   5b0 (0x887AD5B0) = P1 pad LEVEL — genuine 16-bit store (sub_8808f2c0 `sth`), read U16.
  //   33d4 (0x885C33D4) = 5b0 & 0xB0FF, WORD store -> read U32. 33d0 = prev 33d4 (WORD).
  //   33d8 (0x885C33D8) = 33d4 & ~33d0 = the rising EDGE (WORD). 342c = P2 mirror (WORD).
  //   confirm FSM DAT_8844a3b8; widget DAT_8844a3a8 (+0x744=confirm level, +0x760=shot id);
  //   commit +328(0x884D6888)/+352(0x884D68A0); session d76 (0x884D678C U16); INMODE 574.
  // Default-off, byte-inert (read-only). Logs on change of the decisive subset + >=1/2s.
  if(std::getenv("RT_INTAP")){
    uint32_t p1=PPC_LOAD_U16(0x887AD5B0u),
             d4=PPC_LOAD_U32(0x885C33D4u), d0=PPC_LOAD_U32(0x885C33D0u),
             d8=PPC_LOAD_U32(0x885C33D8u), p2=PPC_LOAD_U32(0x885C342Cu),
             inm=PPC_LOAD_U32(0x887AD574u), sess=PPC_LOAD_U16(0x884D678Cu),
             fsm=PPC_LOAD_U32(0x8844A3B8u), wid=PPC_LOAD_U32(0x8844A3A8u),
             c328=PPC_LOAD_U32(0x884D6888u), c352=PPC_LOAD_U32(0x884D68A0u),
             a13=PPC_LOAD_U8(0x88449A13u),
             // ROM boot/title FSM sub_880EA968 gate: session state-2 (FUN_88137168) advances 2->3
             // only when 67cc(0x884D67CC)==0; 67cc is set 1 by the session-reset FUN_88136178 and
             // cleared 0 ONLY by 880EA968 case 0xC. That FSM steps on child-anim flags
             // 0f4/0f0/0f8 (0x887AD0F4/F0/F8). If it stalls, 67cc latches 1 and d76 stalls at 2.
             g67cc=PPC_LOAD_U32(0x884D67CCu), f0f4=PPC_LOAD_U32(0x887AD0F4u),
             f0f0=PPC_LOAD_U32(0x887AD0F0u), f0f8=PPC_LOAD_U32(0x887AD0F8u);
    uint32_t lvl=0,shot=0; if(wid>=0x82000000u&&wid<0x8B000000u){ lvl=PPC_LOAD_U32(wid+0x744u); shot=PPC_LOAD_U32(wid+0x760u); }
    static uint64_t lk=~0ull; static int ll=-1000;
    uint64_t k=((uint64_t)(p1&0xFFFF))|((uint64_t)(d4&0xFFFF)<<16)|((uint64_t)(d8!=0)<<32)
             |((uint64_t)(sess&0xF)<<33)|((uint64_t)(fsm&0x1F)<<37)|((uint64_t)(inm&7)<<42)
             |((uint64_t)(lvl&3)<<45)|((uint64_t)(c328!=0)<<47)|((uint64_t)(c352!=0)<<48)|((uint64_t)(a13!=0)<<49)
             |((uint64_t)(g67cc!=0)<<50)|((uint64_t)(f0f4!=0)<<51)|((uint64_t)(f0f0!=0)<<52)|((uint64_t)(f0f8!=0)<<53);
    uint32_t csfsm=PPC_LOAD_U32(0x884EA3DCu), j0=PPC_LOAD_U8(0x884D6CE8u), j1=PPC_LOAD_U8(0x884D6CE8u+196u);
    if(k!=lk || n-ll>=30){ lk=k; ll=n;
      std::fprintf(stderr,"[intap] f%d out=%u d76=%u INMODE=%u | 5b0=0x%04X 33d4=0x%08X 33d8edge=0x%08X | csfsm(ea3dc)=%u join[P1=%u P2=%u] | fsm=0x%X widlvl744=%u shot760=0x%X | +328=%u +352=%u a13=%u | 67cc=%u\n",
        n,st,sess,inm,p1,d4,d8,csfsm,j0,j1,fsm,lvl,shot,c328,c352,a13,g67cc);
    }
  }
  // RT_SHIPX: dense per-frame ship-X (884d80b0) + P1 field-input (885c33d4) tracker. When a field
  // is active (885c1a20!=0) it accumulates min/max/first/last of both and prints a window summary
  // every 60 frames -> monotone shipX drift under a held LEFT/RIGHT = commanded control; flat = the
  // stage scene isn't consuming the pad (attract demo). Cheaper/stronger than PrintWindow. Default-off.
  // ★ 2026-07-25 REBASED (the old probe was DEAD — see NOTE_ship_anchor.md). Corrections:
  //  (a) player X/Y are NOT at 0x884D80B0 (that address has FOUR loads and ZERO stores module-wide
  //      — it is the enemy-aim mirror). The live ship position is written EVERY FRAME by the ship
  //      controller sub_8814D400 to fixed globals: 1P X=0x887AD550 Y=0x887AD558, 2P X=+4 Y=+4,
  //      16.16 fixed, clamped to X[8..232] Y[26..280] (240x320 TATE). 0xFFFFFFFF = player absent.
  //  (b) 0x885C33D4 is written by `stw`, so the old PPC_LOAD_U16 read the always-zero HIGH half.
  //      Now a 32-bit load (same bug still lurks at the other 33D4 U16 reads in this file).
  // VALIDATED against the leg-27 xscan dumps: held LEFT -> X=8.00 (exact left clamp), held RIGHT
  // -> X=232.00 (exact right clamp), Y constant 49.00 under pure horizontal input, 2P=0xFFFFFFFF.
  if(std::getenv("RT_SHIPX")){
    static int32_t sxmin=0x7fffffff,sxmax=-0x7fffffff,sxfirst=0,sxlast=0; static uint32_t fmin=0xFFFFFFFFu,fmax=0;
    static int32_t symin=0x7fffffff,symax=-0x7fffffff;
    static int have=0, cnt=0;
    if(PPC_LOAD_U32(GA_FIELD_ACTIVE)!=0){
      int32_t sx=(int32_t)PPC_LOAD_U32(0x887AD550u), sy=(int32_t)PPC_LOAD_U32(0x887AD558u);
      uint32_t fw=PPC_LOAD_U32(0x885C33D4u);
      if(!have){ sxfirst=sx; sxmin=sxmax=sx; symin=symax=sy; fmin=fmax=fw; have=1; }
      if(sx<sxmin)sxmin=sx; if(sx>sxmax)sxmax=sx; sxlast=sx;
      if(sy<symin)symin=sy; if(sy>symax)symax=sy;
      if(fw<fmin)fmin=fw; if(fw>fmax)fmax=fw;
      if(++cnt>=60){
        auto px=[](int32_t v){ return (double)v/65536.0; };
        std::fprintf(stderr,"[shipx] win60: X %.2f->%.2f [%.2f..%.2f] dX=%.2f | Y [%.2f..%.2f] | pad33D4 %08X..%08X | out=%u%s\n",
          px(sxfirst),px(sxlast),px(sxmin),px(sxmax),px(sxmax-sxmin),px(symin),px(symax),fmin,fmax,st,
          ((uint32_t)sxlast==0xFFFFFFFFu)?"  (no player)":"");
        cnt=0; sxfirst=sxlast; sxmin=sxmax=sxlast; symin=symax=sy; fmin=fmax=fw; }
    } else { have=0; cnt=0; }
  }
  // RT_INMODE=<v>: diagnostic — force DAT_887ad574 to <v> (0=live,2=record) whenever it reads 4
  // (attract replay) while a field is active. Tests whether the live pad reaches the ship once the
  // replay-mode lock is removed (register-true target is FUN_88137320 firing; this isolates the
  // input-mode gate). Default-off.
  if(const char* im=std::getenv("RT_INMODE")){
    if(PPC_LOAD_U32(0x887AD574u)==4u){
      PPC_STORE_U32(0x887AD574u,(uint32_t)atoi(im));
      static int lg=0; if(lg++<6) std::fprintf(stderr,"[inmode] forced 887ad574 4->%d (was attract replay)\n",atoi(im));
    }
  }
  // ══ RT_FORCELIVE (2026-07-22 CREDITED-SEQUENCE leg, Fable-5) ═══════════════════════════════════
  // The chicken-and-egg breaker. RE (reco): during the game-module select (outer state 5), the input
  // mode DAT_887ad574 is set to 2 (RECORD) by FUN_88137168 (credits 6e84==0 @124889). Empirically
  // (mapsweep 2026-07-22) the select input word DAT_885c33d4 (= 887ad5b0&0xb0ff, the EDGE source for
  // the confirm at FUN_88103048 bit 0x8000) stays 0 in RECORD even though the live pad DOES reach
  // 887ad5b0 — so the select never consumes the pad and d76 stalls at 4 (+328 never drops). LIVE mode
  // (574==0) normally arrives ONLY from the credited-start FUN_88137320, which also sets 6e94=1 and
  // deadlocks the state-4 pump. This lever forces 574 RECORD(2)->LIVE(0) during the select WITHOUT
  // the deadlocking side effects, so the natural select can consume the pad and drive the confirm
  // widget to case 0xC (=> +352/credited flags set NATURALLY). Gate: outer state 5 (st==5), 574==2,
  // and the select is live (session d76 in 1..4). Default off => byte-identical. Verify via RT_SELEDGE
  // (33d4 should start tracking the pad) + RT_CREDLOG (INMODE574 should read 0).
  if(std::getenv("RT_FORCELIVE") && st==5){
    uint32_t d76fl=PPC_LOAD_U16(0x884D678Cu);
    if(PPC_LOAD_U32(0x887AD574u)==2u && d76fl>=1u && d76fl<=4u){
      PPC_STORE_U32(0x887AD574u,0u);
      static std::atomic<int> fl{0}; int q=fl.fetch_add(1);
      if(q<6||(q%2000)==0) std::fprintf(stderr,"[forcelive] forced 887ad574 2->0 (LIVE) at out=5 d76=%u so select consumes the pad\n",d76fl);
    }
  }
  // [scenelog] RT_SCENELOG (2026-07-23 SCENE-SYSTEM ATLAS leg) — the REAL scene-lifecycle tracer,
  // grounded in ghidra_futari_decomp/ATLAS_scene_system.md. CORRECTS the [gpfac]/[gpdraw]/[prio]
  // premise: sub_880E3888 = SOUND voice allocator (0x884D6878 = menu-transition/sfx-suppress flag,
  // NOT a draw gate); id46 (sub_88227220->sub_88226EB0) = a ~48-frame FADE/WIPE that self-destructs
  // by design. Real priority DRAW LIST = sorted linked list at head *(0x88449D4C) (node+0xC=drawer fn,
  // +8=handle, +0x18=priority), pumped by sub_88152CF0 inside THIS outer FSM (state 0x884D66A8: outer
  // 0->1->3 = LIVE STAGE loop cycling id-0x1d scenes from table 0x8828CB40[1..4]; outer 5 delegates to
  // the session FSM sub_88137ED8 = state 0x884D678C). Credited play reaches stages ONLY via session
  // state 8 (returns 0 -> outer 5->2->3), gated by the select-CONFIRM COMMIT +352(0x884D68A0) /
  // +328(0x884D6888) and credits 0x884D6E84. Logs both FSM states + gates + id46/stage handles + the
  // full draw-list membership (priority:fn per node) on change and >=1/s. Default-off, byte-inert.
  if(std::getenv("RT_SCENELOG")){
    // Read widths per proven prior-hook accesses: session state d76 @0x884D678C = U16 ([m5s]);
    // commit gates +352(0x884D68A0)/+328(0x884D6888) = U32 (RT_STARTACT). OUTER `st` already U32 above.
    uint32_t s67=PPC_LOAD_U16(0x884D678Cu);
    static uint32_t ps66=0xFFFFu, ps67=0xFFFFu; static int lastlog=-1000;
    if(st!=ps66 || s67!=ps67 || n-lastlog>=60){
      lastlog=n; ps66=st; ps67=s67;
      uint32_t g_68a0=PPC_LOAD_U32(0x884D68A0u), g_6888=PPC_LOAD_U32(0x884D6888u),
               g_6e84=PPC_LOAD_U32(0x884D6E84u), g_6878=PPC_LOAD_U32(0x884D6878u),
               h6768=PPC_LOAD_U32(0x884D6768u), h66b4=PPC_LOAD_U32(0x884D66B4u),
               h66b8=PPC_LOAD_U32(0x884D66B8u), sub=PPC_LOAD_U8(0x887AD54Eu),
               b0=PPC_LOAD_U8(0x884D66B0u),
               // STAGE-DISPATCH leg (2026-07-22, Fable-5): +76ec = the loop-back-to-menu decider.
               // reco 125445 (session FSM d76=8 fallthrough) sets DAT_884d66ec=1 iff 6e84!=0&&!=3;
               // then session returns 0 -> outer 5->2 (reco 126189), and outer state 2 (reco 126076)
               // branches: 66ec==0 -> spawn root scene 0x1d + outer:=3 (STAGE LOOP); 66ec!=0 ->
               // sub_88136178(0) + outer:=5 (BACK TO MENU). arm674c = the credited-start scene
               // handle (0x2c/88132cc0 created by sub_88137320). mbox58c/g547 = the GameEntry
               // credited mailbox (msg 0xd -> 58c=2 -> sub_88137320 fires at outer state 5).
               g_66ec=PPC_LOAD_U32(0x884D66ECu), arm674c=PPC_LOAD_U32(0x884D674Cu),
               mbox58c=PPC_LOAD_U32(GA_MB_RELOAD), g547=PPC_LOAD_U8(GA_MB_CREDITED);
      char dl[512]; int o=0; int cnt=0;
      for(uint32_t p=PPC_LOAD_U32(0x88449D4Cu); p>=0x82000000u && p<0x8B000000u && cnt<24; p=PPC_LOAD_U32(p)){
        uint32_t fn=PPC_LOAD_U32(p+0xCu), pr=PPC_LOAD_U32(p+0x18u);
        if(o<(int)sizeof(dl)-32) o+=std::snprintf(dl+o,sizeof(dl)-(size_t)o,"pr%u:%X ",pr,fn);
        cnt++;
      }
      dl[o]=0;
      std::fprintf(stderr,"[scenelog] f%d OUTER66a8=%u SESS678c=%u sub54e=%u | commit68a0=%u 6888=%u 6e84=%u 66ec=%u trans6878=0x%X | id46h=0x%X stage66b4=0x%X 66b8=0x%X arm674c=0x%X mbox58c=%u g547=%u b0=%u | DRAWLIST(%d){%s}\n",
        n,st,s67,sub,g_68a0,g_6888,g_6e84,g_66ec,g_6878,h6768,h66b4,h66b8,arm674c,mbox58c,g547,b0,cnt,dl);
    }
  }
  // RT_CONFIRMPATH (LEG-17 agent RE): scene-FSM state 2 (loc_88139034) branches on the
  // menu-return flag *(0x884D66EC) (=r31-84): !=0 -> back to menu (state 5) via sub_88136178(0);
  // ==0 -> CONFIRM/load-forward (REQ id=29 factory 0x8819DE88, state:=3). The flag is set to 1
  // by a Cancel (widget msg 12 -> mailbox 0x887AD58C=1 -> state-5 sets -84=1) and left 0 by a
  // Confirm (msg 13). Merged's menu-loop = the submit is landing as a CANCEL. Force the confirm
  // path: zero -84 at state-2 entry so the FSM takes the load-forward branch (no shell reboot).
  // =2 also zeroes the mailbox 0x887AD58C so state-5 can't re-arm -84 the next cycle.
  // [s5] state-5 residency + per-state tick histogram + tracked handle. Prints the state
  // histogram every 4000 ticks so we can see whether state 5 HOLDS or oscillates 5<->3, and
  // what its tracked handle is (to cross-ref [res] POLL completion).
  if(std::getenv("RT_S5")){
    static long hist[8]={0}; if(st<8) hist[st]++;
    static long m=0; if((m++%4000)==0)
      std::fprintf(stderr,"[s5] hist s0=%ld s1=%ld s3=%ld s5=%ld s6=%ld | cur=%u h=0x%X\n",
        hist[0],hist[1],hist[3],hist[5],hist[6],st,PPC_LOAD_U32(0x884D66B4u));
  }
  if(std::getenv("RT_TRACESM") && (n<60 || st!=prev))
    std::fprintf(stderr,"[smf] tick#%d state=%u (prev=%d)\n",n,st,(int)prev);
  // [fsm] cycle-2 rate diagnosis (RT_TRACERES): first 5 + every 1000th call, with tracked
  // handle, lifecycle slot 0x88252D58 (read+set-to--1 per call), head latches, pump count.
  if(std::getenv("RT_TRACERES") && (n<5 || n%1000==0))
    std::fprintf(stderr,"[fsm] F00#%d state=%u h66B4=0x%X slot2D58=%d latch8=0x%X latch16=0x%X latch20=0x%X\n",
      n,st,PPC_LOAD_U32(0x884D66B4u),(int32_t)PPC_LOAD_U32(0x88252D58u),
      PPC_LOAD_U32(GA_MB_RELOAD),PPC_LOAD_U32(0x887AD594u),PPC_LOAD_U32(0x887AD598u));
  // [q] RT_QDIAG: state + reload-flag *(0x887AD58C) + mode64 *(0x887AD584) on EVERY change of any of
  // the three — exposes a state-6<->state-2 oscillation (reload flag stuck at 1) that the 1000-tick
  // [fsm] sampler misses. This is the "does the FSM re-teardown forever" test.
  if(std::getenv("RT_QDIAG")){
    static uint32_t ls=0xFFFFFFFFu, lr=0xFFFFFFFFu, lm=0xFFFFFFFFu;
    uint32_t rl=PPC_LOAD_U32(GA_MB_RELOAD), md=PPC_LOAD_U32(GA_MB_MODE64);
    if(st!=ls||rl!=lr||md!=lm){ ls=st; lr=rl; lm=md;
      static int qp=0; if(qp++<400)
        std::fprintf(stderr,"[qfsm] F00#%d state=%u reload(58C)=0x%X mode64(584)=0x%X\n",n,st,rl,md); }
  }
  // [g14] LEG-13: the state-3 START gate (loc_881392B8) only examines the raw pad word when
  // byte *(0x88449A0E) == 18 (r29=0x88449A00 from the prologue lis/addi; pad words r27/r26 =
  // *(0x885C33D8)/*(0x885C3430), tested vs bit 0x8000). Log byte transitions + pad words to
  // learn merged's value across the attract rotation (does 18 ever appear? at which slot?).
  if(std::getenv("RT_G14")){
    static uint32_t lastb=0xFFFFu; static long k=0; static int prints=0;
    uint32_t b=PPC_LOAD_U8(0x88449A0Eu); bool chg=(b!=lastb); lastb=b;
    if((chg || (k%4000)==0) && prints<400)
      { prints++; std::fprintf(stderr,"[g14] tick#%d state=%u b14=%u%s pad1=0x%08X pad2=0x%08X\n",
        n,st,b,chg?" CHG":"",PPC_LOAD_U32(0x885C33D8u),PPC_LOAD_U32(0x885C3430u)); }
    k++;
  }
  // RT_STARTFSM=<startTick>[:holdTicks]: race-free START — OR 0x8000 into the raw pad word
  // 0x885C33D8 HERE, immediately before the FSM tick reads it (kills the shell input-staging
  // clobber race the VdSwap-hook RT_STARTBIT had). Level-triggered gate, so holding across the
  // window spans the attract rotation until the title slot (gate byte 18) comes around.
  // RT_FORCE14=1 additionally forces the gate byte to 18 during the window (diagnostic lever).
  // RT_NATPLAY: replay the SDK-oracle GROUND-TRUTH menu script (2026-07-07, oracle_menu.log,
  // natural gameplay reached on real futari.exe). Facts it encodes — REFUTING LEG-15's model:
  //   * mode64 stays 0 the ENTIRE way (RT_MODE64=1 was the poison; do NOT combine).
  //   * raw-pad bits (word 0x885C33D8): START=0x8000, A=0x0020 (NOT 0x1000), Down=0x0008.
  //   * d76=1 --START--> COMMIT-366D0(side=0) --> d76=2 --A(cb837=1)--> 3 --> 4.
  //   * d76=4 is HEALTHY with +328==1: the registered side runs mode/char/shot sub-screens,
  //     each stepped by an A EDGE; the last confirm drops +328 to 0 -> sub_88137708 takes the
  //     +352==0/+328==0 branch -> REQ id=46 (NOT id=48!) -> d76=5 -> 6 -> 8 -> stage load.
  // Implementation: state-driven at FSM-tick entry (race-free spot). A is pulsed 4 ticks on /
  // 90 off so each sub-screen sees a fresh edge.
  // LEG-14 (workflow futari-confirm-gate, high-conf RE): the in-game menu ITEM-CONFIRM is NOT
  // the raw pad word 0x885C33D8 (that only carries START/join, bit 0x8000). The confirm gate is
  // the BYTE *(0x885C6837) (=global 0x885C6818+31): bit 0x1=side0, bit 0x2=side1, read in
  // sub_88137C28 @ ppc_recomp.18.cpp:4775 — but ONLY on a tick where raw-START (0x8000) is
  // asserted AND mode64 *(0x887AD584)==1 AND sub_88137C28's phase +78==0. mode64==0 (merged's
  // observed value) takes the auto-select-both path instead; mode64==3 skips confirm entirely.
  // RT_CONFIRMFSM=<startTick>[:holdTicks] level-forces the confirm byte, overlap RT_STARTFSM.
  // RT_MODE64=<v>[:startTick] diagnostic: force mode64 *(0x887AD584)=v. mode64 selects the
  // confirm branch (1=read confirm byte; 0/2=auto-select; 3=skip). If the SDK has mode64==1 at
  // this menu and merged has 0, forcing 1 should route START through the confirm-byte path.
  if(const char* mf=std::getenv("RT_MODE64")){
    int v=atoi(mf); const char* c=std::strchr(mf,':'); int at=c?atoi(c+1):0;
    if(n>=at){ PPC_STORE_U32(GA_MB_MODE64,(uint32_t)v);
      static int lg=0; if(lg++<2) std::fprintf(stderr,"[mode64] tick#%d forced mode64=%d\n",n,v); }
  }
  // [m5s] menu substate (halfword @0x884D6774 = FSM obj +228, dispatched 0..8 by sub_88137ED8)
  // — log on change so menu reactions to injected buttons are visible. Substate 0 calls
  // sub_88137C28 whose OWN gate halfwords live at 0x884D678C(+76)/0x884D678E(+78): the pad
  // read (loc_88137CEC) only runs when +78 == 0. Now also logs the confirm byte 0x885C6837 and
  // the full raw pad word 0x885C33D8 so we see exactly what the menu tick sees.
  if(std::getenv("RT_S5")){
    static uint64_t lastKey=0xFFFFFFFFFFFFFFFFull;
    uint32_t sub=PPC_LOAD_U16(0x884D6774u);
    uint32_t c76=PPC_LOAD_U16(0x884D678Cu), c78=PPC_LOAD_U16(0x884D678Eu);
    uint32_t mode=PPC_LOAD_U32(GA_MB_MODE64);
    uint32_t cbyte=PPC_LOAD_U8(0x885C6837u), pad1=PPC_LOAD_U32(0x885C33D8u);
    uint64_t key=((uint64_t)sub<<48)|((uint64_t)c76<<40)|((uint64_t)c78<<32)|((uint64_t)(mode&0xFF)<<24)|((cbyte&0xFF)<<16)|((pad1>>16)&0xFFFF);
    if(key!=lastKey){ lastKey=key;
      std::fprintf(stderr,"[m5s] tick#%d menu-substate=%u c28sub76=%u c28sub78=%u mode64=0x%X confirm837=0x%X pad1hi=0x%04X (state=%u)\n",
        n,sub,c76,c78,mode,cbyte,(pad1>>16)&0xFFFF,st); }
  }
  // RT_FSMRESET=2: wedge WATCHDOG — the stale-handle wedge (state 1, unchanged handle, no
  // progress) recurs on NATIVE transitions (e.g. START press), not just the scripted modecmd.
  // Detect: state==1 with the same tracked handle for 500 consecutive ticks -> zero it.
  if(const char* fr=std::getenv("RT_FSMRESET"); fr && atoi(fr)>=2){
    static int thresh=[&]{ const char* t=std::getenv("RT_WDTICKS"); return t?atoi(t):120; }();
    static uint32_t lastH=0xFFFFFFFFu; static int stuck=0; static int resets=0;
    uint32_t h=PPC_LOAD_U32(0x884D66B4u);
    if(st==1 && h!=0 && h==lastH){ if(++stuck>=thresh){
      PPC_STORE_U32(0x884D66B4u,0); stuck=0;
      if(resets++<20) std::fprintf(stderr,"[fsmreset2] state-1 wedge on h=0x%X -> handle cleared (reset#%d)\n",h,resets);
    } } else stuck=0;
    lastH=h;
  }
  // LEG-15 RT_MENUCONFIRM: the confirm handler sub_88137C28 runs ONLY as menu dispatch body #1
  // (d76 *(0x884D678C)==1) and gates on raw START (0x8000 in 0x885C33D8/3430) with phase +78==0.
  // The forced runs cycle d76 through 2..8 so a periodic START pulse rarely coincides. Assert START
  // PRECISELY when d76==1 && +78==0 && state==5, right before the dispatch reads it, so the confirm
  // lands every time. With mode64==0 the auto-path takes START as select+confirm (sub_881366D0);
  // with mode64==1 also set the confirm byte 0x885C6837|=1 (RT_MENUCONFIRM>=2). Edge-safe: only
  // fires on d76==1 windows, and we clear on the NEXT tick where d76!=1 so each window = one edge.
  // LEG-15 CONTINUATION — RT_STARTACT (trace workflow wf_954b9f8e): the native "start" action is
  // sub_88136660 (sets MB+352=1 + its MB+1860==0 cleanup) — the confirm-callback for the 1P-SIDE-
  // START widget, normally fired via the deferred-callback singleton 0x887AD4D8 when that widget's
  // confirm animation lands. In merged the 2nd confirm never arms it. CALL IT NATIVELY (better than
  // RT_START352's raw poke — runs the cleanup, sticks). Gate to fire ONCE at the RIGHT time:
  // side 0 committed (MB+308 bit0) AND MB+352==0 AND MB+1860==0 AND in the menu (state 5, d76 in
  // {1,4}). Firing before side0 is committed would reference an uninitialized side record.
  if(const char* sa=std::getenv("RT_STARTACT")){
    int lvl=atoi(sa);
    static bool fired=false;
    uint32_t d76=PPC_LOAD_U16(0x884D678Cu);
    uint32_t p308=PPC_LOAD_U32(0x884D6740u+308u), p352=PPC_LOAD_U32(0x884D6740u+352u);
    uint32_t p1860=PPC_LOAD_U32(0x884D6740u+1860u), p304=PPC_LOAD_U32(0x884D6740u+304u);
    bool side0 = (p308&1u)!=0;
    // Diagnostic: why isn't the gate met? Log the components while parked at d76 in {1,4}.
    if(st==5 && (d76==1||d76==4)){
      static uint32_t lk=0xFFFFFFFFu; uint32_t k=(p308&0xF)|((p352&1)<<4)|((p1860&0xF)<<5)|((p304&1)<<9)|(d76<<12);
      static std::atomic<int> nq{0}; int qi=nq.fetch_add(1);
      if(qi<20 || k!=lk){ lk=k;
        std::fprintf(stderr,"[startact?] d76=%u +308=0x%X(side0=%d) +352=0x%X +1860=0x%X +304=0x%X\n",d76,p308,side0,p352,p1860,p304); }
    }
    // Fire once: side 0 committed + not-yet-started. lvl>=2 drops the side0 requirement (test).
    bool gate = st==5 && (d76==1||d76==4) && p352==0 && (side0 || lvl>=2);
    if(!fired && gate){
      __imp__sub_88136660(ctx,base);   // the real start action (sets +352=1 + MB+1860==0 cleanup)
      fired=true;
      std::fprintf(stderr,"[startact] CALLED sub_88136660 at d76=%u side0=%d -> +352=0x%X\n",
        d76,side0,PPC_LOAD_U32(0x884D6740u+352u));
    }
  }
  // ══ RT_SELEDGE (2026-07-22 TRAINING-MODE DRIVE leg, Fable-5) — the coordinator's confirm-chain
  // discriminator (NOTE_confirm_chain_edges.md). Per-frame during select: the decide-edge words
  // {5b0,33d4,33d8}&0x8000, the confirm-widget FSM {a3b8 state, a3d0 slide timer, a3cc/a3c8 pages},
  // the confirm-level widget+0x744 / shot-id widget+0x760 (widget=DAT_8844a3a8), and the settings
  // gate 88449a13 (nonzero => FUN_88103048 skips the ENTIRE confirm block => +0x744 never reaches 2
  // => case-8 wall). Log on change of any key field (+ first 40 frames). RT_SELEDGE>=2 also FORCES
  // 88449a13=0 (grounded: the game itself zeroes it at reco 124100/124155) to test that gate.
  if(std::getenv("RT_SELEDGE")){
    uint32_t wdg=PPC_LOAD_U32(0x8844A3A8u);
    uint32_t w744=wdg?PPC_LOAD_U32(wdg+0x744u):0xFFFFFFFF, w760=wdg?PPC_LOAD_U32(wdg+0x760u):0;
    uint32_t a3b8=PPC_LOAD_U32(0x8844A3B8u), a3d0=PPC_LOAD_U32(0x8844A3D0u);
    uint32_t a3cc=PPC_LOAD_U32(0x8844A3CCu), a3c8=PPC_LOAD_U32(0x8844A3C8u);
    uint32_t e5b0=PPC_LOAD_U32(0x887AD5B0u)&0x8000u, e33d4=PPC_LOAD_U32(0x885C33D4u)&0x8000u, e33d8=PPC_LOAD_U32(0x885C33D8u)&0x8000u;
    uint8_t a13=PPC_LOAD_U8(0x88449A13u);
    if(std::atoi(std::getenv("RT_SELEDGE"))>=2 && a13){ PPC_STORE_U8(0x88449A13u,0);
      static std::atomic<int> f{0}; if(f.fetch_add(1)<3) std::fprintf(stderr,"[seledge] FORCED 88449a13 %u->0 (confirm-gate)\n",a13); }
    static std::atomic<int> sn{0}; int si=sn.fetch_add(1);
    static uint64_t lk=~0ull;
    uint64_t k=((uint64_t)(a3b8&0xFF))|((uint64_t)(a3cc&7)<<8)|((uint64_t)(a3c8&7)<<11)
             |((uint64_t)((w744&3))<<14)|((uint64_t)((w760!=0))<<16)|((uint64_t)((e33d8!=0))<<17)
             |((uint64_t)(a13&0xFF)<<18)|((uint64_t)(st&7)<<26);
    if(si<40 || k!=lk){ lk=k;
      std::fprintf(stderr,"[seledge] f%d out=%u | edge 5b0=%u 33d4=%u 33d8=%u(0x8000) | fsm a3b8=%u d0=%u a3cc=%u a3c8=%u | wdg=0x%X +744=%d +760=0x%X | a13=%u\n",
        si,st,e5b0?1:0,e33d4?1:0,e33d8?1:0,a3b8,a3d0,a3cc,a3c8,wdg,(int)w744,w760,a13);
    }
  }
  // ══ RT_ARMCRED (2026-07-22 TRAINING-MODE DRIVE leg, Fable-5) ═══════════════════════════════
  // The mission's msg-14 hypothesis, tested by REPLICATING the shell game-start message the port's
  // RT_DEFERDRIVER harness bypasses. Decomp (reco): GameEntry msg 14 (case 0xd) sets DAT_887ad58c=2
  // iff DAT_887ad547==0; the OUTER-FSM tick sub_88138F00 (this fn), at outer state 5, latches 58c
  // and if ==2 calls sub_88137320 = the REAL credited-start (sets input-mode 574=0=LIVE, arms lives
  // 884d77c8/789c/7970/7a44=1, zeroes the player/ship struct 884d8008[0x94] incl shipX 884d80b0,
  // launches gameplay scene 0x88132cc0). Guard inside 137320: sub_88152b00(884d674c)==0 (scene slot
  // idle). We set 58c=2 RIGHT BEFORE the original tick latches it, at outer state 5, one-shot, after
  // the select menu has settled. RT_ARMCRED>=2 also frees the menu-scene slot 674c so the 137320
  // guard passes even mid-menu. Default off (byte-identical). Verify via [cred320] + RT_SHIPX.
  // RT_ARMCRED>=3 (2026-07-22 CREDITED-SEQUENCE leg): POST-SELECT gating. Firing sub_88137320 mid-
  // select (d76<5) deadlocks — it sets 6e94=1 which short-circuits the state-4 pump (sub_88137708
  // needs 6e94==0), so the select never completes. Instead, let the NATURAL select complete first
  // (FORCELIVE + confirm edges drive d76 4->5->6->8), THEN arm: gate on the session FSM having
  // reached the post-select region (d76>=5) at least once (latched), and fire at outer state 5. At
  // that point the outer handler calls sub_88137320 (creates gameplay scene 0x88132cc0 + LIVE +
  // lives) then sub_88137ed8 -> outer 3 runs the REAL credited scene.
  static std::atomic<int> g_armcred_post{0};
  static const bool g_armcred_on = std::getenv("RT_ARMCRED")!=nullptr;
  if(g_armcred_on){ uint32_t d76w=PPC_LOAD_U16(0x884D678Cu); if(d76w>=5u && d76w<=8u) g_armcred_post.store(1); }
  if(g_armcred_on && st==5){
    static std::atomic<int> settle{0}; static std::atomic<int> armed{0};
    uint32_t d76=PPC_LOAD_U16(0x884D678Cu);
    int lvl=std::atoi(std::getenv("RT_ARMCRED"));
    // lvl>=3: require the select to have COMPLETED (d76 reached >=5 once) before arming.
    bool postGate = (lvl<3) || (g_armcred_post.load()!=0);
    // wait until the game-module select menu exists (session d76>=2) then settle ~90 ticks
    if(d76>=2 && postGate){
      int s=settle.fetch_add(1)+1;
      int thr = (lvl>=3) ? 2 : 90;   // post-select: fire fast (select already done)
      if(s>=thr && armed.fetch_add(1)==0){
        uint32_t s674c=PPC_LOAD_U32(0x884D674Cu);
        if(lvl>=2){ PPC_STORE_U32(0x884D674Cu,0); }   // free scene slot so 137320 guard passes
        PPC_STORE_U8(GA_MB_CREDITED,0);                  // guard for msg-14 (case 0xd)
        PPC_STORE_U32(GA_MB_RELOAD,2);                 // == GameEntry(msg=14) result: arm credited
        std::fprintf(stderr,"[armcred] outer=5 d76=%u settle=%d: forced 547=0, 58c=2 (msg14-equiv), 674c was 0x%X%s -> next tick calls sub_88137320\n",
          d76,s,s674c,lvl>=2?" (freed)":"");
      }
    }
  }
  // [fsmio] (2026-07-23 sequencer leg): unmatched-ENTER detector. The scene pump (88152CF0, tail
  // of this fn) stops at ~#480 post-join while waits keep pairing — so either this fn stops being
  // CALLED (main loop stuck upstream) or hangs INSIDE one call. Print ENTER/EXIT with a shared
  // counter every 120 + the last ENTER# on any stall is visible as an ENTER with no EXIT.
  {
    static std::atomic<int> eio{0};
    bool gmf=(xr_gettid()==g_gm_loop_tid.load(std::memory_order_relaxed));
    if(gmf) g_gm_stage.store(5,std::memory_order_relaxed);
    if(std::getenv("RT_JOINP")){ int e=eio.fetch_add(1)+1;
      if(e%120==0) std::fprintf(stderr,"[fsmio] 88138F00 ENTER#%d st=%u\n",e,st);
      __imp__sub_88138F00(ctx,base);
      if(e%120==0) std::fprintf(stderr,"[fsmio] 88138F00 EXIT#%d\n",e);
    } else {
      __imp__sub_88138F00(ctx,base);
    }
    if(gmf) g_gm_stage.store(6,std::memory_order_relaxed);
  }
  // RT_NAVREAL (2026-07-14): OBSERVER + real-vs-attract discriminator for the DETERMINISTIC
  // REAL-CREDITED stage-1 reach. The reach itself is driven entirely through the RT_PAD_FIFO
  // host-input channel (run_realplay.sh writes button words to /tmp/futari_pad; stubs.cpp
  // OR-merges them into XamInputGetState exactly like a human keyboard) — the SAME channel the
  // proven manual recipe uses (Enter=START, Z=A, arrows). This lever does NOT poke game state; it
  // only (1) LOGS the scene-FSM (0x884D66A8) + arcade-select FSM (d76 @0x884D678C) transitions so
  // the driver script can pace presses on real game feedback instead of wall-clock, and (2) emits
  // a one-shot "REAL-FIELD CONFIRMED" marker that distinguishes a genuine credited stage — field
  // live (0x885C1A20!=0) AFTER menu navigation advanced the select-FSM (d76>=2) WITH slot0 ACTIVE
  // (0x884D6CE8!=0, set by the game's OWN join when A confirms 1P SIDE START) — from the attract/
  // title demo (which latches field_active BEFORE any nav, slot inactive, no credit). When
  // RT_NAVREAL>=2 it additionally SUSTAINS the confirmed real field (clamp teardown flag
  // 0x884D6878=0 + re-arm slot0 credits 0x884D6CEA), gated on the real-field signal so it never
  // holds the attract demo. Default OFF => byte-identical.
  if(std::getenv("RT_NAVREAL")){
    static uint32_t lst=0xFFFFFFFFu, ld76=0xFFFFFFFFu;
    uint32_t d76nr=PPC_LOAD_U16(0x884D678Cu);
    uint32_t goflag=PPC_LOAD_U32(0x884D6878u);   // game-over/teardown flag (death chain)
    uint32_t field =PPC_LOAD_U32(GA_FIELD_ACTIVE);   // gameplay-field-active
    uint16_t cred  =PPC_LOAD_U16(0x884D6CEAu);   // slot0 credit-countdown
    static uint32_t maxD76=0; if(d76nr<0x100u && d76nr>maxD76) maxD76=d76nr;
    if(st!=lst){ std::fprintf(stderr,"[navreal] st %d->%u (d76=%u field=%u go=%u cred=%u)\n",(int)lst,st,d76nr,field,goflag,cred); lst=st; }
    if(d76nr!=ld76){
      std::fprintf(stderr,"[navreal] d76 %d->%u (st=%u field=%u go=%u cred=%u maxD76=%u)\n",(int)ld76,d76nr,st,field,goflag,cred,maxD76);
      // LOOP/DEATH diagnostic (coordinator ground-truth: credited run dies -> replay-save loop):
      // the select-FSM fell from the gameplay-submit value (>=8) back toward the menu (<5). Dump
      // the death-chain state so we can see WHICH teardown flag/scene the real path uses (attract
      // used 0x884D6878). Extra candidate words logged for RE.
      if(maxD76>=8u && ld76<0x100u && ld76>=8u && d76nr<5u)
        std::fprintf(stderr,"[navreal] *** LOOP/DEATH d76 %u->%u st=%u go(884D6878)=%u cred(884D6CEA)=%u field(885C1A20)=%u | 884D66EC=%u 887AD58C=%u 884D6740+312=%u 884D6CE8=%u ***\n",
          ld76,d76nr,st,goflag,cred,field,PPC_LOAD_U32(0x884D66ECu),PPC_LOAD_U32(GA_MB_RELOAD),
          PPC_LOAD_U32(0x884D6740u+312u),PPC_LOAD_U8(0x884D6CE8u));
      ld76=d76nr;
    }
    // HOLD (coordinator ground-truth): the credited run DIED near-instantly -> replay-save prompt.
    // Diagnosis from the cred/slot timeline: the credit-countdown 0x884D6CEA drops 3->0 exactly at
    // the d76 4->5 confirm (the game "spends" the credit to start), and slot0 0x884D6CE8 reads
    // INACTIVE at the field -> with no live player + 0 credits the game runs the field as a REPLAY
    // ("リプレイをセーブ" prompt) and immediately offers to save it. To hold GENUINE play we must
    // keep the player slot LIVE + credits non-zero FROM the submit (maxD76>=5), BEFORE they drain,
    // and block the scene teardown. Arm at maxD76>=5 (not >=8) so the re-arm beats the drain.
    static bool held=false, fieldSeen=false;
    if(maxD76>=8u && !g_rt_realstage){ g_rt_realstage=1;
      std::fprintf(stderr,"[navreal] real-stage gate OPEN (maxD76>=8) -- RVK_ARENADUMP may now fire\n"); }
    if(!held && maxD76>=5u){ held=true;
      std::fprintf(stderr,"[navreal] SUBMIT (maxD76>=5) -- HOLD armed: keep slot0 live + credits, block teardown\n"); }
    if(held && !fieldSeen && field!=0u){ fieldSeen=true;
      std::fprintf(stderr,"[navreal] REAL-FIELD CONFIRMED: field_active=%u d76=%u maxD76=%u slot0-active=%u cred=%u -- credited stage-1\n",
        field,d76nr,maxD76,PPC_LOAD_U8(0x884D6CE8u),cred); }
    if(held && atoi(std::getenv("RT_NAVREAL"))>=2){
      // (a) keep the player slot LIVE + credits floored so no game-over/replay-save is ever reached.
      if(PPC_LOAD_U8(0x884D6CE8u)==0u){ PPC_STORE_U8(0x884D6CE8u,1u);
        static int sl=0; if(sl++<8) std::fprintf(stderr,"[navreal] re-activated player slot0 (0x884D6CE8 0->1)\n"); }
      if(cred<3u) PPC_STORE_U16(0x884D6CEAu,9u);
      if(goflag!=0u){ PPC_STORE_U32(0x884D6878u,0u);
        static int cl=0; if(cl++<16) std::fprintf(stderr,"[navreal] cleared game-over/teardown flag 0x884D6878 (was %u)\n",goflag); }
      // (b) block the real-path teardown: the run ends by the SCENE FSM (0x884D66A8) 5->2
      // (state-2 teardown/menu-return) with 0x884D6878 staying 0. Restore 5 so the id46/47
      // gameplay scene keeps ticking and the field keeps rendering.
      uint32_t scene=PPC_LOAD_U32(0x884D66A8u);
      if(scene==2u){ PPC_STORE_U32(0x884D66A8u,5u);
        static int sb=0; if(sb++<16) std::fprintf(stderr,"[navreal] blocked scene 5->2 teardown -> held at gameplay state 5 (field=%u)\n",field); }
    }
  }
  // RT_JOINLOG side-select-window tracer (2026-07-22): dump the systemobj (0x884D6740) slot-marker
  // table + the two side-records on every d76 change through the side-select -> commit window, so we
  // can see (a) whether the 1P join ever writes a -1 marker into a slot (the thing the id47 scan
  // looks for) and (b) the side-record join bit/credit-countdown timeline. If NO -1 marker ever
  // appears anywhere, the natural join-assign step is missing (the smoking gun). Byte-inert unset.
  if(std::getenv("RT_JOINLOG")){
    static uint32_t ljd=0xFFFFFFFFu;
    uint32_t d76=PPC_LOAD_U16(0x884D678Cu);
    if(d76!=ljd){ ljd=d76;
      uint32_t B=0x884D6740u,F=PPC_LOAD_U32(B+0x54u);
      char mk[160]; int o=0;
      for(uint32_t ix=0;ix<2;ix++){ uint32_t bb=((ix*3u+F)*0xB4u)+B+0x190u;
        o+=std::snprintf(mk+o,sizeof(mk)-o,"ix%u[",ix);
        for(int k=0;k<5;k++)o+=std::snprintf(mk+o,sizeof(mk)-o,"%02X ",PPC_LOAD_U8(bb+(uint32_t)k*0x24u));
        o+=std::snprintf(mk+o,sizeof(mk)-o,"] "); }
      std::fprintf(stderr,"[joinlog] d76=%u st=%u F54=%u slots %s| rec0(6CE8) b0=%u cr=%u +88=%u +8c=%u | rec1(6DAC) b0=%u cr=%u | entry0(6774)=0x%X entry1(6778)=0x%X | obj17=%u\n",
        d76,st,F,mk,
        PPC_LOAD_U8(0x884D6CE8u),PPC_LOAD_U16(0x884D6CEAu),PPC_LOAD_U32(0x884D6CE8u+0x88u),PPC_LOAD_U32(0x884D6CE8u+0x8Cu),
        PPC_LOAD_U8(0x884D6DACu),PPC_LOAD_U16(0x884D6DAEu),
        PPC_LOAD_U32(0x884D6774u),PPC_LOAD_U32(0x884D6778u),PPC_LOAD_U8(0x884D95F1u));
      // config/options block DAT_885c6820 -> DAT_88449a1b(default lives) / a0f(auto-branch) etc + the
      // side-record's own lives field (rec+6 = DAT_88449a1b). If lives==0 the join/settings are starved.
      std::fprintf(stderr,"[joincfg] d76=%u | opt(885C6820)=%08X%08X%08X | a15=%u a16=%u a17=%u a18=%u a1a=%u a1b(lives)=%u a0f(auto)=%u a13=%u | rec0+6(lives)=%u rec1+6=%u\n",
        d76,PPC_LOAD_U32(0x885C6820u),PPC_LOAD_U32(0x885C6824u),PPC_LOAD_U32(0x885C6828u),
        PPC_LOAD_U8(0x88449A15u),PPC_LOAD_U8(0x88449A16u),PPC_LOAD_U8(0x88449A17u),PPC_LOAD_U8(0x88449A18u),
        PPC_LOAD_U8(0x88449A1Au),PPC_LOAD_U8(0x88449A1Bu),PPC_LOAD_U8(0x88449A0Fu),PPC_LOAD_U8(0x88449A13u),
        PPC_LOAD_U8(0x884D6CE8u+6u),PPC_LOAD_U8(0x884D6DACu+6u));
    }
  }
  // RT_STAY5 (LEG-18, SDK-oracle ground truth): the healthy SDK enters GAMEPLAY with the scene
  // FSM STAYING at state 5 the whole time — it NEVER goes to state 2 (oracle_res.log: all REQs
  // incl. the gameplay-branch id=46/47 fire at fsm=5; oracle_menu.log: scene=5 at d76=8/gameplay).
  // The id=46/47 factories build the gameplay scene + install its per-frame drawer AS the active
  // state-5 scene, exactly like the menu was. Merged instead transitions 5->2 after the submit
  // (state-2 teardown -> frame-handshake freeze). Block that: if this tick moved 5->2 after the
  // menu had submitted (d76>=5 was reached), restore state 5 so the pump can build+run the
  // id-46/47 gameplay scene natively. Gated: only after POST-WALL (menu submitted at least once).
  // RT_FIELDHOLD (2026-07-14): DETERMINISTIC SUSTAINED-GAMEPLAY REACH for on-window render A/B.
  // The autopilot reaches the stage-1 field (field_active 0x885C1A20 != 0) but the game then drains
  // slot0 credits -> game-over -> sub_88136030 sets the teardown flag 0x884D6878=1 -> the stage tick
  // tears the id-44 node down -> the shell drops to the replay-save/attract screen. That made every
  // field render A/B a coin flip (see run_window.sh field drops). Fix: once field_active is first
  // latched, every tick (1) CLAMP the game-over/teardown flag 0x884D6878 to 0 -- this blocks the
  // teardown regardless of CAUSE (credit drain OR player death both route through this same flag),
  // and (2) re-arm slot0 credits 0x884D6CEA to a floor as belt-and-suspenders. Combine with
  // RT_STAY5 (keeps the scene FSM at gameplay state 5) so the field renders indefinitely. This is a
  // TEST HARNESS lever (hold the field so renderer fixes can be captured), NOT shipped play.
  // Default OFF (env unset) => byte-identical. Runs on the MAIN-thread FSM tick, same thread as the
  // teardown, so the clamp pre-empts the flag before the teardown acts on it.
  if(std::getenv("RT_FIELDHOLD")){
    static bool held=false;
    if(!held && PPC_LOAD_U32(GA_FIELD_ACTIVE)!=0u){ held=true;
      std::fprintf(stderr,"[fieldhold] field_active latched (0x885C1A20=%u) -- holding stage-1 field\n",
        PPC_LOAD_U32(GA_FIELD_ACTIVE)); }
    if(held){
      if(PPC_LOAD_U32(0x884D6878u)!=0u){ PPC_STORE_U32(0x884D6878u,0u);
        static int gl=0; if(gl++<8) std::fprintf(stderr,"[fieldhold] cleared game-over/teardown flag 0x884D6878\n"); }
      if(PPC_LOAD_U16(0x884D6CEAu)<2u){ PPC_STORE_U16(0x884D6CEAu,9u); }
    }
  }
}

// RT_TRACERES: trace the resource-load request (sub_881526C0 = queue-add, returns handle) and
// poll (sub_88152B00 = "loaded?" 0/1) to see why loads never complete. The load queue is drained
// by a separate worker/streaming thread; if it never marks the resource loaded, sub_88152B00
// returns 0 forever and the scene machine (state 3) stalls.
extern "C" void __imp__sub_881526C0(PPCContext& __restrict, uint8_t*);
extern "C" void __imp__sub_88152B00(PPCContext& __restrict, uint8_t*);
static std::atomic<int> g_req{0}, g_poll{0};
PPC_FUNC(sub_881526C0){
  uint32_t id=ctx.r4.u32&0xFFFF, a3=ctx.r3.u32, a5=ctx.r5.u32;
  // [desc] descriptor-registry dump at first REQ: walk *(0x88449D4C) printing {id@+8,
  // factory@+12}. SDK oracle proved this list is populated BEFORE the first REQ; if it's
  // empty here, the init-time populator (suspect: msg-2 DA28 -> sub_880750A0 builds,
  // the session-5 count=0 debt) is the last-mile defect.
  { static std::atomic<int> once{0};
    if(std::getenv("RT_TRACERES") && once.fetch_add(1)==0){
      uint32_t head=PPC_LOAD_U32(0x88449D4Cu);
      std::fprintf(stderr,"[desc] at first REQ: list head *(0x88449D4C)=0x%X nodes:",head);
      uint32_t node=head; int k=0;
      while(node && node>=0x1000u && node<0xFFFF0000u && k<40){
        std::fprintf(stderr," {id=%u f=0x%X}",PPC_LOAD_U32(node+8),PPC_LOAD_U32(node+12));
        node=PPC_LOAD_U32(node); ++k;
      }
      std::fprintf(stderr," (%d)\n",k);
      std::fprintf(stderr,"[desc] static desc ARRAY e0 @0x8844A080: %08X %08X %08X %08X %08X %08X\n",
        PPC_LOAD_U32(0x8844A080u),PPC_LOAD_U32(0x8844A084u),PPC_LOAD_U32(0x8844A088u),
        PPC_LOAD_U32(0x8844A08Cu),PPC_LOAD_U32(0x8844A090u),PPC_LOAD_U32(0x8844A094u));
    } }
  __imp__sub_881526C0(ctx,base);
  // [desc] ring/pump counters after each REQ: entryCount *(0x88449A1C), writeSeq *(0x88449D20),
  // pumpPending *(0x8844A054) — mismatch between enqueue side and pump side = the defect.
  if(std::getenv("RT_TRACERES")){
    static std::atomic<int> rq{0}; int q=rq.fetch_add(1);
    if(q<12) std::fprintf(stderr,"[desc] postREQ#%d cnt=%u seq=%u pumpPend=%u\n",q,
      PPC_LOAD_U32(0x88449A1Cu),PPC_LOAD_U32(0x88449D20u),PPC_LOAD_U32(0x8844A054u));
  }
  int n=g_req.fetch_add(1);
  if(std::getenv("RT_TRACERES") && n<2000)
    std::fprintf(stderr,"[res] REQ#%d id=%u arg3=0x%X arg5=0x%X -> handle=0x%X\n",n,id,a3,a5,ctx.r3.u32);
}
// [kick] LEG-27/40 ring-window: sub_88080298 = the GAME d3d9 primary-ring writer + kick
// (copies IB/packet dwords into the primary ring at dev+15104 with dword-index mask
// dev+15108, advances the WPTR index dev+10956 and stores it to GPU MMIO 0x7FC80714).
// Under RVK_RINGPROBE log each kick: dev+0x30 cursor before/after, WPTR index range, and
// the primary-ring dwords written (the INDIRECT_BUFFER packets = the submitted segments).
extern "C" void __imp__sub_88080298(PPCContext& __restrict, uint8_t*);
extern "C" void rt_kick_capture(uint8_t*,uint32_t,uint32_t,uint32_t) __attribute__((weak));  // (base,dev,segAddr,lenDwords)  // shell-kernel LEG-27/40 segment capture
PPC_FUNC(sub_88080298){
  static int probe = std::getenv("RVK_RINGPROBE")?atoi(std::getenv("RVK_RINGPROBE")):0;
  // RT_TICKRATE: kicks/sec = the ROM render loop's true iteration rate (the attract task family
  // measured 6-10/s vs ~60Hz presents — is the whole ROM loop throttled, or just the task slice?)
  if(std::getenv("RT_TICKRATE")){
    static std::atomic<long long> kn{0}; long long ki=kn.fetch_add(1)+1;
    static const auto kt0=std::chrono::steady_clock::now();
    if(ki<=3 || (ki%120)==0){ double s=std::chrono::duration<double>(std::chrono::steady_clock::now()-kt0).count();
      std::fprintf(stderr,"[tickrate] gamekick#%lld t=%.1fs avg=%.1f/s\n", ki, s, s>0? ki/s:0.0); }
  }
  uint32_t dev=ctx.r3.u32;
  // r4/r6 volatile -> read before; r4[1] (segment addr) dereferenced after (relocation).
  uint32_t ks_obj=ctx.r4.u32, ks_len=ctx.r6.u32;
  if(!probe){ __imp__sub_88080298(ctx,base);
    if(rt_kick_capture) rt_kick_capture(base,dev, ks_obj?PPC_LOAD_U32(ks_obj+4u):0u, ks_len); return; }
  uint32_t pre30=PPC_LOAD_U32(dev+0x30), preIdx=PPC_LOAD_U32(dev+10956);
  uint32_t ring=PPC_LOAD_U32(dev+15104), mask=PPC_LOAD_U32(dev+15108);
  __imp__sub_88080298(ctx,base);
  if(rt_kick_capture) rt_kick_capture(base,dev, ks_obj?PPC_LOAD_U32(ks_obj+4u):0u, ks_len);
  uint32_t post30=PPC_LOAD_U32(dev+0x30), postIdx=PPC_LOAD_U32(dev+10956);
  static std::atomic<long> n{0}; long k=n.fetch_add(1);
  if(k<400 || (k%97)==0){
    char buf[560]; int o=0; int guard=0;
    for(uint32_t i=preIdx; i!=postIdx && o<480 && guard<40; i=(i+1)&mask, ++guard)
      o+=std::snprintf(buf+o,sizeof(buf)-o," %08X",PPC_LOAD_U32(ring+4*(i&mask)));
    buf[o]=0;
    std::fprintf(stderr,"[kick] G#%ld dev=0x%X 30:0x%X->0x%X idx:%u->%u ring=0x%X mask=0x%X |%s\n",
      k,dev,pre30,post30,preIdx,postIdx,ring,mask,buf);
    if(k<4 || (k%485)==0){
      std::fprintf(stderr,"[kick] G#%ld devfields 28=0x%X 2C=0x%X 30=0x%X 34=0x%X 38=0x%X 3C=0x%X 40=0x%X\n",
        k,PPC_LOAD_U32(dev+0x28),PPC_LOAD_U32(dev+0x2C),PPC_LOAD_U32(dev+0x30),
        PPC_LOAD_U32(dev+0x34),PPC_LOAD_U32(dev+0x38),PPC_LOAD_U32(dev+0x3C),PPC_LOAD_U32(dev+0x40));
    }
  }
}
// [vs] sub_881538C0 = THE 2D vertex-slot allocator (every quad writer allocs here then writes
// color into the slot). Log lr (identifies the writer fn) + read back the PREVIOUS slot's
// color words (+0, +48) — the caller has written them by then. Two 40-call windows post-boot.
extern "C" void __imp__sub_881538C0(PPCContext& __restrict, uint8_t*);
std::atomic<long> g_spriteAllocs{0};  // LEG-39 [semit]: total 2D vertex-slot allocs (emission-rate probe)
PPC_FUNC(sub_881538C0){
  static std::atomic<long>& n=g_spriteAllocs; long i=n.fetch_add(1);
  uint32_t sz=ctx.r3.u32;
  __imp__sub_881538C0(ctx,base);
  if(std::getenv("RT_TRACERES")){
    bool win=(i>=500000&&i<500040)||(i>=1500000&&i<1500040);
    if(win){
      static uint32_t prev=0;
      uint32_t slot=ctx.r3.u32, pc0=0, pc48=0;
      if(prev>=0x1000&&prev<0xFFFF0000u){ pc0=PPC_LOAD_U32(prev); pc48=PPC_LOAD_U32(prev+48); }
      std::fprintf(stderr,"[vs] alloc#%ld sz=%u lr=0x%X -> 0x%X | prev+0=%08X prev+48=%08X\n",
        i,sz,(uint32_t)ctx.lr,slot,pc0,pc48);
      prev=slot;
    }
  }
}
// [fade] sub_8822BE60 = suspected transition/fade FSM (state block 0x884EBC44: state, cnt1,
// cnt2, flag). Content draws have vertex alpha 0 + fullscreen dark overlay — if this stepper
// is frozen/never called, the fade-in never runs. Log call rate + state.
extern "C" void __imp__sub_8822BE60(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_8822BE60){
  static std::atomic<int> n{0}; int i=n.fetch_add(1);
  __imp__sub_8822BE60(ctx,base);
  if(std::getenv("RT_TRACERES") && (i<10 || (i%600)==0))
    std::fprintf(stderr,"[fade] BE60#%d st=%u c1=%u c2=%u fl=%u\n",i,
      PPC_LOAD_U32(0x884EBC44u),PPC_LOAD_U32(0x884EBC48u),PPC_LOAD_U32(0x884EBC4Cu),PPC_LOAD_U32(0x884EBC50u));
}
// [tt] TEXT-TASK system (title/press-start blink lives here). sub_88091288 = spawn named text
// task into 100x52B table at *(0x887AD4F8) (DE58 spawns "PRESS START BUTTON" @0x8800F52C).
// sub_88091068 / sub_88090F38 = per-slot executors (draw + free slot), called INDIRECTLY —
// log lr to find the executor's driver; log spawn + occupancy to catch table exhaustion.
extern "C" void __imp__sub_88091288(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88091288){
  static std::atomic<int> n{0}; int i=n.fetch_add(1);
  uint32_t r3=ctx.r3.u32,r4=ctx.r4.u32,r5=ctx.r5.u32,r6=ctx.r6.u32;
  __imp__sub_88091288(ctx,base);
  if(std::getenv("RT_TRACERES") && (i<40 || (i%500)==0)){
    char nm[25]; nm[0]=0;
    if(r6>=0x1000&&r6<0xFFFF0000u){ for(int k=0;k<24;++k){ char c=(char)*(base+r6+k); nm[k]=(c>=32&&c<127)?c:0; if(!c) break; } nm[24]=0; }
    uint32_t tbl=PPC_LOAD_U32(0x887AD4F8u); int occ=0;
    if(tbl>=0x1000&&tbl<0xFFFF0000u) for(int s=0;s<100;++s) if(PPC_LOAD_U32(tbl+s*52)) ++occ;
    std::fprintf(stderr,"[tt] SPAWN#%d (%u,%u,%u) '%s' lr=0x%X occ=%d/100\n",i,r3,r4,r5,nm,(uint32_t)ctx.lr,occ);
  }
}
extern "C" void __imp__sub_88091068(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88091068){
  static std::atomic<int> n{0}; int i=n.fetch_add(1);
  if(std::getenv("RT_TRACERES") && (i<20 || (i%5000)==0))
    std::fprintf(stderr,"[tt] EXEC-1068#%d r3=0x%X lr=0x%X\n",i,ctx.r3.u32,(uint32_t)ctx.lr);
  __imp__sub_88091068(ctx,base);
}
extern "C" void __imp__sub_88090F38(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88090F38){
  static std::atomic<int> n{0}; int i=n.fetch_add(1);
  if(std::getenv("RT_TRACERES") && (i<20 || (i%5000)==0))
    std::fprintf(stderr,"[tt] EXEC-F38#%d r3=0x%X lr=0x%X\n",i,ctx.r3.u32,(uint32_t)ctx.lr);
  __imp__sub_88090F38(ctx,base);
}
// [rr] sub_88152900 = persistent-descriptor REGISTER (slots 0-19 path). HARD CAP: bails with 0
// when live-count *(0x88449D44) >= 20 — silently DROPS the request. Log drops + occupancy.
extern "C" void __imp__sub_88152900(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88152900){
  uint32_t e=ctx.r3.u32, h=0,id=0;
  if(e>=0x1000&&e<0xFFFF0000u){ h=PPC_LOAD_U32(e+4); id=PPC_LOAD_U32(e+8); }
  uint32_t live=PPC_LOAD_U32(0x88449D44u);
  __imp__sub_88152900(ctx,base);
  if(std::getenv("RT_TRACERES")){
    static std::atomic<int> n{0}; int i=n.fetch_add(1);
    if(ctx.r3.u32==0){
      static std::atomic<int> d{0}; int j=d.fetch_add(1);
      if(j<200) std::fprintf(stderr,"[rr] 52900-DROP#%d h=0x%X id=%u live=%u (pool full)\n",j,h,id,live);
    } else if(i<200)
      std::fprintf(stderr,"[rr] 52900-reg#%d h=0x%X id=%u live=%u->%u\n",i,h,id,live,PPC_LOAD_U32(0x88449D44u));
  }
}
// [desc] pump per-entry step: sub_881527B8(r3=pending-entry) — matches/builds/registers.
// Log entry words + return for the first calls (RT_TRACERES).
extern "C" void __imp__sub_881527B8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_881527B8){
  static std::atomic<int> n{0}; int i=n.fetch_add(1);
  uint32_t e=ctx.r3.u32;
  uint32_t w[5]={0,0,0,0,0};
  if(e>=0x1000&&e<0xFFFF0000u) for(int k=0;k<5;++k) w[k]=PPC_LOAD_U32(e+k*4);
  __imp__sub_881527B8(ctx,base);
  if(std::getenv("RT_TRACERES") && i<2000)
    std::fprintf(stderr,"[desc] 27B8#%d e=0x%X {%08X %08X %08X %08X %08X} -> 0x%X\n",
      i,e,w[0],w[1],w[2],w[3],w[4],ctx.r3.u32);
}
PPC_FUNC(sub_88152B00){
  uint32_t h=ctx.r3.u32;
  __imp__sub_88152B00(ctx,base);
  int n=g_poll.fetch_add(1);
  if(std::getenv("RT_TRACERES") && n<12)
    std::fprintf(stderr,"[res] POLL#%d handle=0x%X -> loaded=%d\n",n,h,ctx.r3.u32);
  // The interesting signal is the STUCK resource: log the first few loaded=0 per distinct
  // handle, plus a periodic summary of every handle still returning 0. (A hot state-3 wait
  // loop polls the full set each frame — millions of loaded=1 lines are noise.)
  if(std::getenv("RT_TRACERES")){
    static std::mutex m; static std::unordered_map<uint32_t,std::pair<int,uint32_t>> hs; // handle -> {zero_logs, last}
    std::lock_guard<std::mutex> l(m);
    auto& e=hs[h]; e.second=ctx.r3.u32;
    if(ctx.r3.u32==0 && e.first<3){ e.first++; std::fprintf(stderr,"[res] POLL handle=0x%X loaded=0 (lr=0x%X)\n",h,(uint32_t)ctx.lr);
      if(e.first==1){ // first stuck poll: scan the request ring for this handle — still pending (never pumped) vs consumed
        bool found=false;
        for(int s=0;s<40;++s){ uint32_t ea=0x88449A20u+s*20;
          if(PPC_LOAD_U32(ea+4)==h){ found=true;
            std::fprintf(stderr,"[res]   ring slot%d for h=0x%X: {st=%u id=%u fn=%08X arg=%08X}\n",
              s,h,PPC_LOAD_U32(ea),PPC_LOAD_U32(ea+8),PPC_LOAD_U32(ea+12),PPC_LOAD_U32(ea+16)); break; } }
        if(!found) std::fprintf(stderr,"[res]   ring: h=0x%X NOT in ring (consumed) — registry obj still null\n",h);
      }
    }
    if((n%500000)==499999){
      std::fprintf(stderr,"[res] POLL summary @%d: still-zero handles:",n+1);
      int c=0; for(auto&kv:hs) if(kv.second.second==0){ std::fprintf(stderr," 0x%X",kv.first); if(++c>=32) break; }
      if(!c) std::fprintf(stderr," (none)");
      std::fprintf(stderr,"\n");
    }
  }
}
// sub_88090360 = resource-KIND registration: iterates 157 entries, each dispatched to one of 3
// kind-handler objects at 0x885C5BB4/+0x20/+0x40, calling handler.vtable[0](); returns 1 if all
// 157 registered. [f8] showed handler this=0 (null). These 3 handlers are populated by GameEntry
// msg-1 (ppc_recomp.32.cpp:21658). Log them to confirm they're null + why (RT_TRACERES).
extern "C" void __imp__sub_88090360(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_88090360){
  if(std::getenv("RT_TRACERES")){
    uint32_t h0=PPC_LOAD_U32(0x885C5BB4u),h1=PPC_LOAD_U32(0x885C5BD4u),h2=PPC_LOAD_U32(0x885C5BF4u);
    std::fprintf(stderr,"[reg] sub_88090360 ENTER handlers h0=0x%X(vt=0x%X) h1=0x%X(vt=0x%X) h2=0x%X(vt=0x%X)\n",
      h0, h0?PPC_LOAD_U32(h0):0, h1, h1?PPC_LOAD_U32(h1):0, h2, h2?PPC_LOAD_U32(h2):0);
  }
  __imp__sub_88090360(ctx,base);
  if(std::getenv("RT_TRACERES")) std::fprintf(stderr,"[reg] sub_88090360 EXIT r3=%d (1=all 157 registered)\n",ctx.r3.u32);
  // RT_AUDIOCRUX: after registration, report handler slots, loaded-flags, and how many of the 256
  // cue-table entries got a real waveIndex (!=0xFFFF). This tells us whether the empty-table defect
  // is upstream (null handlers / no cue names resolved) — read-only, default-OFF.
  if(std::getenv("RT_AUDIOCRUX")){
    uint32_t h0=PPC_LOAD_U32(0x885C5BB4u),h1=PPC_LOAD_U32(0x885C5BD4u),h2=PPC_LOAD_U32(0x885C5BF4u);
    uint32_t l0=PPC_LOAD_U32(0x885C5BCCu),l1=PPC_LOAD_U32(0x885C5BECu),l2=PPC_LOAD_U32(0x885C5C0Cu);
    int filled=0, firstc=-1, firstbt=-1, firstwi=-1;
    for(uint32_t c=0;c<256;++c){ uint32_t wi=PPC_LOAD_U32(0x885C5D14u+c*8);
      if(wi!=0xFFFF){ ++filled; if(firstc<0){ firstc=(int)c; firstbt=(int)PPC_LOAD_U32(0x885C5D10u+c*8); firstwi=(int)wi; } } }
    std::fprintf(stderr,"[crux] post-reg: handlers h0=0x%X h1=0x%X h2=0x%X | loaded-flags l0=0x%X l1=0x%X l2=0x%X | cues_filled=%d/256 (first cueId=%d bankType=%d waveIdx=%d)\n",
      h0,h1,h2,l0,l1,l2,filled,firstc,firstbt,firstwi);
    // Driver-submit resolution: the crux fires driver->vtable[+56] (=vt[14]) as the sample-producing
    // edge. Dump the driver vtable so we can trace the SUBMIT fn statically (it should create/link a
    // shell voice into the submix the mixer walks).
    uint32_t drv=PPC_LOAD_U32(0x887AD50Cu), dvt=drv?PPC_LOAD_U32(drv):0;
    std::fprintf(stderr,"[crux] driver=0x%X vtable=0x%X SUBMIT(vt+56)=0x%X  vt[0..15]=",drv,dvt,dvt?PPC_LOAD_U32(dvt+56):0);
    for(int i=0;i<16&&dvt;i++) std::fprintf(stderr," %08X",PPC_LOAD_U32(dvt+i*4));
    std::fprintf(stderr,"\n");
  }
}

// RT_AUDIOCRUX: read-only gate-ladder probe on the voice-bind crux sub_88090588 (out_reco/
// ppc_recomp.5.cpp:923). NOT editing its register-true logic — this wrapper only reads the gate
// inputs, calls the real impl, and reports which gate a cue dies at. Gates (per the disassembly):
//   A driver *(0x887AD50C)==0 ; B cueId>=256 ; C bankType *(0x885C5D10+cueId*8)>=3 ;
//   D waveIndex *(0x885C5D14+cueId*8)==0xFFFF ; E loaded *(0x885C5BCC+bankType*32)==0 ;
//   then PREPARE handler->vtable[+16] must return 0, else silence. Args: r3=slot r4=cueId r5 r6.
extern "C" void __imp__sub_88090588(PPCContext& __restrict, uint8_t*);
extern "C" void rt_audio_bridge_play(int bankType, int waveIdx);   // rt_audio.cpp (RT_AUDIOBRIDGE)
extern "C" int  rt_audio_bridge_enabled(void);                     // rt_audio.cpp
extern "C" void rt_audio_stage_play_volume(int vol64);             // rt_audio.cpp (64 = unity)
extern "C" int  rt_audio_cuebridge_enabled(void);                  // rt_audio.cpp (RT_CUEBRIDGE)
// 2026-07-31: the dispatch moved to the shell-side SoundBank::Prepare funnel (merged_shell.cpp
// sub_820EEE00), which sees these same game cues PLUS the shell's SYS_SE/SYS_BGM banks and resolves
// the cue index through the .xsb. Dispatching from BOTH sites would play every game cue twice, so
// the crux dispatch below is suppressed while the cue bridge is on. RT_CUEBRIDGE=0 restores it.
static bool rt_crux_dispatch_on(){ return rt_audio_cuebridge_enabled()==0; }
PPC_FUNC(sub_88090588){
  bool crux   = std::getenv("RT_AUDIOCRUX")!=nullptr;
  bool bridge = rt_audio_bridge_enabled()!=0;
  bool bgmf   = std::getenv("RT_BGMFUNNEL")!=nullptr;
  if(!crux && !bridge && !bgmf){ __imp__sub_88090588(ctx,base); return; }

  // Resolve the gate inputs read-only (same ladder as the disassembly; see gate map above).
  // param4 (r6) = the BGM/SE discriminator the funnels set (BGM funnel li r6,1 / SE funnel li r6,0).
  // REGISTER-TRUE FACT (ppc_recomp.5.cpp:923): the crux stores r6 to active-voice+8 ONCE and NEVER
  // branches on it — SE and BGM take the IDENTICAL gate/PREPARE/RegisterNotification path here.
  uint32_t slot=ctx.r3.u32, cueId=ctx.r4.u32, p3=ctx.r5.u32, p4=ctx.r6.u32;
  uint32_t drv=PPC_LOAD_U32(0x887AD50Cu);
  const char* gate="PASS(all A-E)"; int bt=-1,wi=-1,ld=-1; uint32_t hnd=0;
  if(!drv) gate="A(driver null)";
  else if(cueId>=256) gate="B(cueId>=256)";
  else {
    bt=(int)PPC_LOAD_U32(0x885C5D10u+cueId*8);
    wi=(int)PPC_LOAD_U32(0x885C5D14u+cueId*8);
    if(bt>=3) gate="C(bankType>=3)";
    else if((uint32_t)wi==0xFFFF) gate="D(waveIndex==0xFFFF)";
    else { ld=(int)PPC_LOAD_U32(0x885C5BCCu+(uint32_t)bt*32);
           hnd=PPC_LOAD_U32(0x885C5BB4u+(uint32_t)bt*32);
           if(ld==0) gate="E(loaded-flag==0)"; }
  }
  bool pass=(gate[0]=='P');

  // ★ RT_VOLTRACE (2026-08-02) — IS THE GAME'S PER-PLAY VOLUME ACTUALLY BEING APPLIED?
  // USER GROUND TRUTH: "we can hear our bullet shots, SDK you can barely hear them" — a LEVEL gap
  // on the shot specifically, not timbre. The guest's own applier is FUN_88090110
  // (reco_normal_decomp_all.txt:21829):
  //     DAT_885c5c10 = (float)param_2 * DAT_88063378;          // r5 (this hook's p3) scaled, vol/64
  //     DAT_885c5c1c = DAT_885c5c10;
  //     sound->vtable[+0x10](sound, 2, DAT_887ad51c, &DAT_885c5c10);
  // ⚠ RETRACTED 2026-08-02: the note that stood here guessed the THIRD argument (DAT_887AD51C) was
  // left ZERO by an unwritten out-param — the "returns SUCCESS, writes nothing" shape that muted
  // every music track — so the volume applied to zero channels. IT IS 6, measured, every run: it is
  // the renderer's FINAL-MIX CHANNEL COUNT from the engine format query (FUN_880906D8 :22099), not
  // a wave count. That hypothesis is DEAD.
  // ⚠ AND THIS TRACE'S OWN "appliedVol" COLUMN WAS A LIE: it read 0x885C5C10 BEFORE the crux ran,
  // so it reported the PREVIOUS play's number — visible in the logs themselves (#2 appliedVol=1.4844
  // is #1's 95/64). It only ever proved the game WROTE a value, never that the value REACHED a
  // voice. Read AFTER the crux now, and paired with RT_MTXTRACE (merged_shell.cpp sub_820ECE08),
  // which reports whether SetMatrixCoefficients actually accepted it and whether a live voice
  // existed to accept it. p3 is the per-play volume (64 = unity).
  // Detail for the first 24 calls, then an UNCAPPED tally — the old flat cap of 24 is exactly how
  // the se01a baseline error survived (a capped log read as if it were a census).

  if(crux||bgmf){
    static std::atomic<long> cn{0}; long n=cn.fetch_add(1)+1;
    static std::atomic<int> firstpass{0};
    // param4=1 => arrived via BGM funnel sub_88093760; param4=0 => SE funnel sub_880937C8.
    if(n<=40 || (pass && firstpass.fetch_add(1)==0) || (bgmf && p4!=0))
      std::fprintf(stderr,"[crux] sub_88090588 #%ld slot=%u cueId=%u p3=%u param4=0x%X(%s) drv=0x%X bankType=%d waveIdx=%d loaded=0x%X handler=0x%X -> GATE %s%s\n",
        n,slot,cueId,p3,p4,(p4!=0?"BGM/loop":"SE/oneshot"),drv,bt,wi,(uint32_t)ld,hnd,gate, pass?"  <<< REACHES PREPARE/SUBMIT":"");
  }

  // Run the real crux ONCE (PREPARE + SUBMIT). Everything below is read-only post-state / the
  // host-bridge dispatch — the register-true logic is untouched.
  // ★ 2026-08-01: p3 (r5) IS the game's per-play VOLUME (64 = unity; sub_88090110 applies vol/64
  // via SetMatrixCoefficients — the game's ONLY volume interface, no 0x88 XACT twins exist).
  // Stage it for the host bridge: the shell Prepare funnel dispatch fires NESTED inside the
  // original call on this thread, and the legacy crux dispatch below runs before the clear.
  if(bridge) rt_audio_stage_play_volume((int)p3);
  __imp__sub_88090588(ctx,base);

  // getenv CACHED — this runs on every cue dispatch (4608 in one session); a per-call getenv is a
  // linear scan of the environment and has no business in the audio path.
  static const bool voltrace = (std::getenv("RT_VOLTRACE") != nullptr);
  if(voltrace){
    static std::atomic<long> vn{0}; long vi=vn.fetch_add(1)+1;
    uint32_t cnt = PPC_LOAD_U32(0x887AD51Cu);
    uint32_t v0  = PPC_LOAD_U32(0x885C5C10u), v3 = PPC_LOAD_U32(0x885C5C1Cu);
    float f0,f3; std::memcpy(&f0,&v0,4); std::memcpy(&f3,&v3,4);
    // PER-CUE budget, not a flat cap. A flat first-24 fills entirely with menu SYS_SE before the
    // stage even starts, so the shot cue never appears — the same crowding-out that hid the real
    // shot behind se01a. Give every distinct cue its own small budget plus an uncapped census.
    static std::atomic<int> perCue[512];
    const uint32_t ci = (cueId<512)?cueId:511;
    const int seen = perCue[ci].fetch_add(1);
    if(seen<6)
      std::fprintf(stderr,"[voltrace] #%ld cue=%u (play %d of this cue) perPlayVol=%u (64=unity) "
                   "chanCount@887AD51C=%u matrix[0]=%.5f matrix[3]=%.5f (POST-crux) gate=%s\n",
                   vi,cueId,seen+1,p3,cnt,(double)f0,(double)f3,gate);
    if((vi%512)==0){
      std::fprintf(stderr,"[voltally] %ld plays (uncapped) — per-cue census:",vi);
      for(int c=0;c<512;c++){ int k=perCue[c].load(); if(k) std::fprintf(stderr," cue%d=%d",c,k); }
      std::fprintf(stderr,"\n");
    }
  }

  if(pass && bt==0){
    uint32_t vs=0x885C5C50u+slot*24;
    bool prepared=(PPC_LOAD_U32(vs+4)==1);   // crux set +4=1 iff PREPARE returned 0 and SUBMIT fired
    // Downstream capture for PCM passing cues — read-only, first few PCM cues only.
    if(crux){
      static std::atomic<int> pcmdump{0};
      if(pcmdump.fetch_add(1)<6){
        uint32_t wt=PPC_LOAD_U32(0x887AD504u), wcnt=PPC_LOAD_U32(0x887AD508u);
        uint32_t we=wt?wt+(uint32_t)wi*16:0;
        std::fprintf(stderr,"[crux-pcm] cueId=%u waveIdx=%d voice@0x%X[+0..20]=%08X %08X %08X %08X %08X %08X (active+4=%s)\n",
          cueId,wi,vs,PPC_LOAD_U32(vs),PPC_LOAD_U32(vs+4),PPC_LOAD_U32(vs+8),PPC_LOAD_U32(vs+12),PPC_LOAD_U32(vs+16),PPC_LOAD_U32(vs+20),
          prepared?"YES(PREPARE ok+SUBMIT fired)":"NO(PREPARE bailed)");
        std::fprintf(stderr,"[crux-pcm]   wave-desc: table=0x%X count=%u entry@0x%X[+0..12]=%08X %08X %08X %08X sampleptr(+12)=0x%X\n",
          wt,wcnt,we, we?PPC_LOAD_U32(we):0, we?PPC_LOAD_U32(we+4):0, we?PPC_LOAD_U32(we+8):0, we?PPC_LOAD_U32(we+12):0, we?PPC_LOAD_U32(we+12):0);
        uint32_t sp = we?PPC_LOAD_U32(we+12):0;
        if(sp && sp<0xF0000000u){
          int nz=0; const int scan=16384;
          for(int b=0;b<scan;b+=4){ if(PPC_LOAD_U32(sp+(uint32_t)b)) nz++; }
          std::fprintf(stderr,"[crux-pcm]   SAMPLE-DATA @0x%X first16KB nonzero-words=%d/%d\n",sp,nz,scan/4);
        } else std::fprintf(stderr,"[crux-pcm]   SAMPLE-DATA ptr invalid (0x%X)\n",sp);
        // B1-plus dead-end trace: identify PREPARE = handler->vtable[+0x10] (is it Prepare-only or
        // Play?) and dump the returned wave object's fields, looking for a source-voice pointer / a
        // state word that DoWork keys on. wave obj = voice+0 (local_70[0]).
        uint32_t hvt=hnd?PPC_LOAD_U32(hnd):0, prep=hvt?PPC_LOAD_U32(hvt+0x10):0;
        uint32_t wav=PPC_LOAD_U32(vs);
        std::fprintf(stderr,"[crux-pcm]   handler=0x%X vtable=0x%X PREPARE(vt+0x10)=0x%X  wave-obj=0x%X\n",hnd,hvt,prep,wav);
        if(wav && wav<0xF0000000u){
          std::fprintf(stderr,"[crux-pcm]   wave-obj[+0..0x40]:");
          for(uint32_t o=0;o<=0x40;o+=4) std::fprintf(stderr," +%u=%08X",o,PPC_LOAD_U32(wav+o));
          std::fprintf(stderr,"\n[crux-pcm]   wave-obj[0x44..0x80]:");
          for(uint32_t o=0x44;o<=0x80;o+=4) std::fprintf(stderr," +%u=%08X",o,PPC_LOAD_U32(wav+o));
          std::fprintf(stderr," (wave-obj-vtable=0x%X)\n",PPC_LOAD_U32(wav));
        }
      }
    }
    // RT_AUDIOBRIDGE: feed the resident BGM.xwb PCM for this committed cue into the host frame.
    if(bridge && prepared && rt_crux_dispatch_on()) rt_audio_bridge_play(bt, wi);
    // (compressed banks are dispatched below — this whole block is bt==0 only)

    // RT_AUDIOROUTE (Phase-3c fork a/b probe, default-OFF): the source-voice->submix ATTACH is
    // FUN_821000A0, reached only via the wave send-list (wave+0x160 gate / +0x168 head / +0x164
    // sentinel). Read: renderer=*(engine+0x24), its source-voice list *(renderer+0x10); the ticked
    // submixes' child lists (master 0x36A090+0x22c, category 0x372F10+0x22c); and the live wave's
    // send-list. (a) send-list empty + renderer list empty => attach never called. (b) send-list
    // non-empty / renderer list has entry but submix child empty => create/attach fails a gate.
    if(std::getenv("RT_AUDIOROUTE") && prepared){
      static std::atomic<int> rn{0};
      if(rn.fetch_add(1)<8){
        uint32_t eng=drv, rend=eng?PPC_LOAD_U32(eng+0x24):0;
        uint32_t svhead=rend?PPC_LOAD_U32(rend+0x10):0;
        int svc=0; uint32_t nd=svhead; while(nd&&nd<0xF0000000u&&svc<128){ nd=PPC_LOAD_U32(nd+4); ++svc; }
        uint32_t wav=PPC_LOAD_U32(vs);
        uint32_t sgate=wav?PPC_LOAD_U32(wav+0x160):0, shead=wav?PPC_LOAD_U32(wav+0x168):0, ssent=wav?(wav+0x164):0;
        bool sendEmpty=(shead==ssent);
        uint32_t mch=PPC_LOAD_U32(0x36A090u+0x22c); int mc=0; nd=mch; while(nd&&nd<0xF0000000u&&mc<128){ nd=PPC_LOAD_U32(nd+4); ++mc; }
        uint32_t cch=PPC_LOAD_U32(0x372F10u+0x22c); int cc=0; nd=cch; while(nd&&nd<0xF0000000u&&cc<128){ nd=PPC_LOAD_U32(nd+4); ++cc; }
        std::fprintf(stderr,"[route] cue=%u wave=0x%X | renderer=0x%X srcVoiceList head=0x%X count=%d | wave.send[+0x160]gate=0x%X head=0x%X sentinel=0x%X %s | master0x36A090.children=%d category0x372F10.children=%d\n",
          cueId,wav,rend,svhead,svc,sgate,shead,ssent,sendEmpty?"EMPTY":"NON-EMPTY",mc,cc);
      }
    }
  }

  // ===== COMPRESSED-BANK DISPATCH (2026-07-29 xWMA decoder leg) ==============================
  // Everything above is bt==0 (PCM/BGM) only — which is why the compressed banks never reached
  // rt_audio_bridge_play and every xWMA cue was silent end-to-end. bankType 1/2 are the game's
  // other two registered resource kinds (SE / VOICE, both xWMA per the .xwb census). Same
  // read-only PREPARE test as the PCM path (crux writes active-voice+4=1 on PREPARE success).
  // Gated on RT_AUDIOBRIDGE (the host player) and, inside rt_audio.cpp, on RT_AUDIOXWMA.
  if(pass && bt>0 && bt<3 && bridge){
    uint32_t vs=0x885C5C50u+slot*24;
    bool prep=(PPC_LOAD_U32(vs+4)==1);
    static std::atomic<long> cn{0}; long k=cn.fetch_add(1)+1;
    if(k<=16) std::fprintf(stderr,"[crux-xwma] cueId=%u bankType=%d cueIdx=%d prepared=%d -> %s\n",
                           cueId,bt,wi,prep?1:0,
                           !rt_crux_dispatch_on()?"(cue bridge owns dispatch)":
                           (prep?"bridge dispatch":"SKIP(PREPARE bailed)"));
    if(prep && rt_crux_dispatch_on()) rt_audio_bridge_play(bt, wi);
  }
  if(bridge) rt_audio_stage_play_volume(-1);   // clear the per-play volume staging
}

// ===== RT_BGMFUNNEL (default-OFF): game-module (0x88) BGM/SE cue-dispatch FUNNEL MATRIX =====
// The precise NEXT-PROBE from NOTE_audio_4point_plan.md VOICE-START leg. Answers, in ONE driven
// field: (a) does the BGM funnel sub_88093760 (crux param4=1) ever fire, with what cueId; (b) does a
// type-3 (BGM) sound-command ever reach dispatch sub_880E4948; correlated against the SE reference
// (type-2 dispatch sub_880E49D8 / SE funnel sub_880937C8). Register-true architecture (verified in
// out_reco/ppc_recomp.12.cpp:2957 sub_880E4CD0 = sound-cmd queue CONSUMER): the consumer dispatches
// on the command TYPE byte *(cmd+1): type 2 -> sub_880E49D8 -> SE funnel; type 3 -> sub_880E4948 ->
// (gate sub_880E3598) -> BGM funnel sub_88093760. All funnels converge on crux sub_88090588, which is
// param4-AGNOSTIC (see the crux hook above). So SE-vs-BGM MUST diverge at cue-PRODUCTION (which type
// commands are enqueued) or DOWNSTREAM shell-side (loop byte), NOT inside the crux. Pure pass-through
// when RT_BGMFUNNEL unset. Read-only.
extern "C" void __imp__sub_88093760(PPCContext& __restrict, uint8_t*);  // BGM funnel  (crux param4=1)
extern "C" void __imp__sub_880937C8(PPCContext& __restrict, uint8_t*);  // SE funnel   (crux param4=0)
extern "C" void __imp__sub_88093830(PPCContext& __restrict, uint8_t*);  // BGM-engine funnel
extern "C" void __imp__sub_880E4948(PPCContext& __restrict, uint8_t*);  // BGM dispatch (cmd type==3)
extern "C" void __imp__sub_880E49D8(PPCContext& __restrict, uint8_t*);  // SE  dispatch (cmd type==2) ref
PPC_FUNC(sub_88093760){
  if(std::getenv("RT_BGMFUNNEL")){
    static std::atomic<long> n{0}; long c=n.fetch_add(1)+1;
    std::fprintf(stderr,"[funnel] *** BGM sub_88093760 #%ld slot=%u cueId=%u p3=%u p4(orig r6)=0x%X -> crux(param4=1)\n",
      c, ctx.r3.u32&0x7, ctx.r4.u32&0xFF, ctx.r5.u32&0xFF, ctx.r6.u32);
  }
  __imp__sub_88093760(ctx,base);
}
PPC_FUNC(sub_880937C8){
  if(std::getenv("RT_BGMFUNNEL")){
    static std::atomic<long> n{0}; long c=n.fetch_add(1)+1;
    if(c<=8||(c%50)==0)
      std::fprintf(stderr,"[funnel] SE  sub_880937C8 #%ld slot=%u cueId=%u p3=%u -> crux(param4=0)\n",
        c, ctx.r3.u32&0x7, ctx.r4.u32&0xFF, ctx.r5.u32&0xFF);
  }
  __imp__sub_880937C8(ctx,base);
}
PPC_FUNC(sub_88093830){
  if(std::getenv("RT_BGMFUNNEL")){
    static std::atomic<long> n{0}; long c=n.fetch_add(1)+1;
    std::fprintf(stderr,"[funnel] *** ENGINE sub_88093830 #%ld cmdptr=0x%X hword0=%d -> crux\n",
      c, ctx.r3.u32, (int)(int16_t)PPC_LOAD_U16(ctx.r3.u32));
  }
  __imp__sub_88093830(ctx,base);
}
PPC_FUNC(sub_880E4948){
  if(std::getenv("RT_BGMFUNNEL")){
    static std::atomic<long> n{0}; long c=n.fetch_add(1)+1;
    std::fprintf(stderr,"[bgmdisp] *** sub_880E4948 #%ld ENTER (a type-3 BGM sound-command was consumed) r3=%u r4=%u r5=%u r6=%u\n",
      c, ctx.r3.u32&0xFF, ctx.r4.u32&0xFF, ctx.r5.u32&0xFF, ctx.r6.u32&0xFF);
  }
  __imp__sub_880E4948(ctx,base);
}
PPC_FUNC(sub_880E49D8){
  if(std::getenv("RT_BGMFUNNEL")){
    static std::atomic<long> n{0}; long c=n.fetch_add(1)+1;
    if(c<=8||(c%50)==0)
      std::fprintf(stderr,"[sedisp] sub_880E49D8 #%ld ENTER (type-2 SE sound-command consumed) [reference]\n", c);
  }
  __imp__sub_880E49D8(ctx,base);
}
// PRODUCER layer: the game FSM enqueues typed sound-commands into queue 0x884EB398 (stride 5,
// type byte at +1). sub_880E3128 hardcodes type=3 (BGM enqueue); sub_880E31B0 hardcodes type=2 (SE).
// If sub_880E3128 fires 0× in-field, the game FSM NEVER asks for BGM through this queue → the whole
// funnel/crux/voice-create chain is starved at the source. lr identifies which FSM site issued it.
extern "C" void __imp__sub_880E3128(PPCContext& __restrict, uint8_t*);  // BGM producer (type==3)
extern "C" void __imp__sub_880E31B0(PPCContext& __restrict, uint8_t*);  // SE  producer (type==2) ref
PPC_FUNC(sub_880E3128){
  if(std::getenv("RT_BGMFUNNEL")){
    static std::atomic<long> n{0}; long c=n.fetch_add(1)+1;
    std::fprintf(stderr,"[prod] *** BGM-ENQUEUE sub_880E3128 #%ld (type=3) p1=%u p2=%u p3=%u p4=%u caller-lr=0x%X\n",
      c, ctx.r3.u32&0xFF, ctx.r4.u32&0xFF, ctx.r5.u32&0xFF, ctx.r6.u32&0xFF, (uint32_t)ctx.lr);
  }
  __imp__sub_880E3128(ctx,base);
}
PPC_FUNC(sub_880E31B0){
  if(std::getenv("RT_BGMFUNNEL")){
    static std::atomic<long> n{0}; long c=n.fetch_add(1)+1;
    if(c<=6||(c%100)==0)
      std::fprintf(stderr,"[prod] SE-ENQUEUE sub_880E31B0 #%ld (type=2) caller-lr=0x%X [reference]\n", c, (uint32_t)ctx.lr);
  }
  __imp__sub_880E31B0(ctx,base);
}

// ---- RT_TRACEBOOT fine-grained trace of sub_88092ED8's internal callees (ppc_recomp.5.cpp
// :7403-7822). sub_88092ED8 ENTERs but never EXITs; find which of its own bl-callees parks.
// Call order in the tail of the fn: sub_88073BD0 -> sub_880836D0 -> [parse loop] ->
// sub_880927A8 -> sub_88092668 -> sub_88082CA8 -> sub_88083200(spawn,:7767) -> sub_88083030 ->
// sub_8808F6C0 -> sub_88082F98(wait) -> sub_880831C0. Prefix `[e8]`. ----
#define E8_WRAP(FN) \
  extern "C" void __imp__##FN(PPCContext& __restrict, uint8_t*); \
  static std::atomic<int> g_e8_##FN{0}; \
  PPC_FUNC(FN){ \
    bool f = traceboot() && g_e8_##FN.fetch_add(1)==0; \
    if(f) std::fprintf(stderr,"[e8] " #FN " ENTER r3=0x%X r4=0x%X r5=0x%X r6=0x%X\n",ctx.r3.u32,ctx.r4.u32,ctx.r5.u32,ctx.r6.u32); \
    __imp__##FN(ctx,base); \
    if(f) std::fprintf(stderr,"[e8] " #FN " EXIT r3=0x%X\n",ctx.r3.u32); \
  }
E8_WRAP(sub_88073BD0)
E8_WRAP(sub_880836D0)
E8_WRAP(sub_880927A8)
E8_WRAP(sub_88083030)
E8_WRAP(sub_8808F6C0)
E8_WRAP(sub_88082F98)
E8_WRAP(sub_880831C0)
E8_WRAP(sub_88082D48)
E8_WRAP(sub_88083170)

// sub_88082C38: the wait-poll loop inside sub_880927A8 (calls NtWaitForSingleObjectEx on
// handle r3 in a loop while r28(alertable-ish)!=0 and wait returns 257). Trace EVERY call
// (not just first) since it's meant to loop a bounded number of times; if it loops forever
// that's the hang. Cap logging to first 40 to avoid flooding.
extern "C" void __imp__sub_88082C38(PPCContext& __restrict, uint8_t*);
static std::atomic<long long> g_c38_calls{0};
PPC_FUNC(sub_88082C38){
  long long n = g_c38_calls.fetch_add(1)+1;
  bool f = traceboot() && n<=40;
  uint32_t r3=ctx.r3.u32, r4=ctx.r4.u32;
  if(f) std::fprintf(stderr,"[e8] sub_88082C38 ENTER call#%lld handle(r3)=0x%X alertable(r4)=0x%X\n",n,r3,r4);
  __imp__sub_88082C38(ctx,base);
  if(f) std::fprintf(stderr,"[e8] sub_88082C38 EXIT call#%lld r3=0x%X\n",n,ctx.r3.u32);
}

// ---- r26-clobber hunt: the game-main fn ptr 0x88168D48 lives in the non-volatile r26 across
// sub_8808FDF8's callees (ppc_recomp.4.cpp:14936..15038). One callee returns without restoring
// r26 -> the spawn gets garbage. Each wrapper checks: entered with r26==0x88168D48, returned
// with it changed => that callee is the culprit. Always on (no env gate). ----
#define CLOB_WRAP(FN) \
  extern "C" void __imp__##FN(PPCContext& __restrict, uint8_t*); \
  PPC_FUNC(FN){ \
    uint32_t pre=ctx.r26.u32; \
    __imp__##FN(ctx,base); \
    if(pre==0x88168D48u && ctx.r26.u32!=pre) \
      std::fprintf(stderr,"[clob] " #FN " did NOT restore r26: 0x88168D48 -> 0x%X\n",ctx.r26.u32); \
  }
CLOB_WRAP(sub_8808F548)
CLOB_WRAP(sub_88082CA8)
CLOB_WRAP(sub_880906D8)
CLOB_WRAP(sub_88082BF8)
CLOB_WRAP(sub_88082BF0)

// ---- SESSION 6c: split-chunk suspect + bracket-callee wrappers (r26-trample hunt) ----
// sub_88084F18 (ppc_recomp.3.cpp:10019) is a prologue-less "function" — really a duplicated
// mid-body chunk of a parent heap function. It writes r20-r28 unsaved and ends with
// __restgprlr_20 (reloads r20-r31 from a frame it doesn't own). It has NO direct bl-callers in
// the game tree, so the only way it can run is via indirect dispatch (mtctr/bctr). If it fires
// at all, that is the smoking gun for the r26 trample; the lr tells us the dispatch site.
// sub_88074328 / sub_88074354 are two more candidates of the same shape. These should NEVER
// legitimately execute as function *entries* — log loudly, unconditionally.
#define SPLIT_WRAP(FN)   extern "C" void __imp__##FN(PPCContext& __restrict, uint8_t*);   static std::atomic<long> g_split_##FN{0};   PPC_FUNC(FN){     long sn_=g_split_##FN.fetch_add(1)+1;     bool lg_=(sn_<=64)||(sn_%500)==0; /* CODE_REVIEW_0804 E21: tripwire kept, flood capped */     if(lg_){ std::fprintf(stderr,"[SPLIT-CHUNK] " #FN " ENTER #%ld lr=%08X r1=%08X r31=%08X r26=%08X\n",       sn_,(uint32_t)ctx.lr,ctx.r1.u32,ctx.r31.u32,ctx.r26.u32);     std::fflush(stderr); }     __imp__##FN(ctx,base);     if(lg_){ std::fprintf(stderr,"[SPLIT-CHUNK] " #FN " EXIT r26=%08X\n",ctx.r26.u32);     std::fflush(stderr); }   }
SPLIT_WRAP(sub_88084F18)
SPLIT_WRAP(sub_88074328)
SPLIT_WRAP(sub_88074354)

// Bracket callees: sub_8808DA28's tail calls (all in the game module). Guard each with a
// per-function static counter so only the first 6 calls log (these may be hot in the steady
// state once the game main is running). Prefix `[r26]` to match the pre-existing FDF8/DA28/c0a8
// brackets so a single grep for "[r26]" gives the full ordered picture.
#define R26_BRACKET_WRAP(FN)   extern "C" void __imp__##FN(PPCContext& __restrict, uint8_t*);   static std::atomic<long long> g_r26b_##FN{0};   PPC_FUNC(FN){     long long n = g_r26b_##FN.fetch_add(1)+1;     bool lg = n<=6;     if(lg){ std::fprintf(stderr,"[r26] " #FN " enter r26=%08X\n",ctx.r26.u32); std::fflush(stderr); }     __imp__##FN(ctx,base);     if(lg){ std::fprintf(stderr,"[r26] " #FN " exit r26=%08X\n",ctx.r26.u32); std::fflush(stderr); }   }
R26_BRACKET_WRAP(sub_88075EB8)
R26_BRACKET_WRAP(sub_88075BA8)
R26_BRACKET_WRAP(sub_88075C08)
R26_BRACKET_WRAP(sub_88074F98)
R26_BRACKET_WRAP(sub_880781C8)
// ★ CODE_REVIEW_0804 C10: sub_8807D4F8 (game Clear) and sub_8807DD88 (game Resolve) wraps
// DELETED — both symbols are ALSO defined in decomp/game/nvk_game_hooks.cpp (the live nvk
// renderer taps). decomp_*.o links first so these wraps were dead — but one glob reorder in
// build_win.sh away from silently replacing the renderer's Resolve/Clear hooks with debug
// brackets that record nothing. Same for the two SLOT_WATCH wraps below.

// ---- SESSION 6d: stack-slot-watch wrappers (sub_8807CD20 saved-r26 corruption hunt) ----
// CD20 saves callee-saved regs via __savegprlr_19 then stwu r1,-256(r1). The saved r26
// doubleword slot lives at guest address entry_r1-56 (== new_r1+200). std stores 8 bytes
// big-endian, so the live 32-bit value is in the HIGH-address half: slot+4.
static volatile uint32_t g_cd20_slot = 0;
static std::atomic<long long> g_cd20_calls{0};

extern "C" void __imp__sub_8807CD20(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_8807CD20){
  long long n = g_cd20_calls.fetch_add(1)+1;
  bool lg = n<=8;
  uint32_t entry_r1 = ctx.r1.u32;
  uint32_t slotAddr = entry_r1 - 56;
  g_cd20_slot = slotAddr;
  if(lg){
    std::fprintf(stderr,"[slot] CD20 enter#%lld r1=%08X slotAddr=%08X r26=%08X\n",
      n, entry_r1, slotAddr, ctx.r26.u32);
    std::fflush(stderr);
  }
  __imp__sub_8807CD20(ctx,base);
  if(lg){
    uint32_t sv_lo = PPC_LOAD_U32(g_cd20_slot);
    uint32_t sv_hi = PPC_LOAD_U32(g_cd20_slot+4);
    std::fprintf(stderr,"[slot] CD20 exit#%lld slotVal=%08X:%08X r26=%08X r1exit=%08X\n",
      n, sv_lo, sv_hi, ctx.r26.u32, ctx.r1.u32);
    static const char* names[13] = {"r19","r20","r21","r22","r23","r24","r25","r26","r27","r28","r29","r30","r31"};
    std::fprintf(stderr,"[slot] CD20 exit#%lld savedblock f31=%08X",
      n, PPC_LOAD_U32(entry_r1-120));
    for(int i=0;i<13;++i){
      uint32_t addr = (entry_r1-112) + (uint32_t)i*8 + 4;
      std::fprintf(stderr," %s=%08X", names[i], PPC_LOAD_U32(addr));
    }
    std::fprintf(stderr,"\n");
    std::fflush(stderr);
  }
  g_cd20_slot = 0;
}

#define SLOT_WATCH_WRAP(FN)                                                              \
  extern "C" void __imp__##FN(PPCContext& __restrict, uint8_t*);                         \
  static std::atomic<long long> g_slotw_##FN{0};                                         \
  PPC_FUNC(FN){                                                                           \
    long long n = g_slotw_##FN.fetch_add(1)+1;                                           \
    bool lg = (g_cd20_slot != 0) && (n<=16);                                             \
    if(lg){                                                                              \
      std::fprintf(stderr,"[slot] " #FN " enter val=%08X r1=%08X\n", PPC_LOAD_U32(g_cd20_slot+4), ctx.r1.u32); \
      std::fflush(stderr);                                                               \
    }                                                                                     \
    __imp__##FN(ctx,base);                                                               \
    if(lg){                                                                              \
      std::fprintf(stderr,"[slot] " #FN " exit val=%08X r1=%08X\n", PPC_LOAD_U32(g_cd20_slot+4), ctx.r1.u32);  \
      std::fflush(stderr);                                                               \
    }                                                                                     \
  }
// (sub_8807A1E0 / sub_8807A578 SLOT_WATCH wraps deleted — see the C10 note above; live
//  definitions are the NVK_GHOOK taps in decomp/game/nvk_game_hooks.cpp.)
SLOT_WATCH_WRAP(sub_88080A00)
SLOT_WATCH_WRAP(sub_8807C7A8)

// sub_88072260 = the guest memcpy(dst=r3,src=r4,len=r5). Specialized wrap: same slot-watch
// behavior as the macro, plus RT_MEMCPYLOG=<hexlo>[-<hexhi>] — log any copy whose dst OR src
// overlaps the guest range (default hi = lo+0x20000), with the caller lr. Used to find the
// SOURCE staging buffer of the char-card page fill (0x12634000): the final page fill is a
// linear full-page copy, so the width-160 defect lives in whoever composed its source.
extern "C" void __imp__sub_88072260(PPCContext& __restrict, uint8_t*);
static std::atomic<long long> g_slotw_sub_88072260{0};
PPC_FUNC(sub_88072260){
  long long n = g_slotw_sub_88072260.fetch_add(1)+1;
  bool lg = (g_cd20_slot != 0) && (n<=16);
  if(lg){
    std::fprintf(stderr,"[slot] sub_88072260 enter val=%08X r1=%08X\n", PPC_LOAD_U32(g_cd20_slot+4), ctx.r1.u32);
    std::fflush(stderr);
  }
  static const char* mclEnv = std::getenv("RT_MEMCPYLOG");
  static uint32_t mclLo = 0, mclHi = 0;
  if(mclEnv && !mclHi){
    mclLo = (uint32_t)strtoul(mclEnv,nullptr,16);
    const char* d = strchr(mclEnv,'-');
    mclHi = d ? (uint32_t)strtoul(d+1,nullptr,16) : mclLo+0x20000u;
  }
  if(mclEnv){
    uint32_t dst=ctx.r3.u32, src=ctx.r4.u32, len=ctx.r5.u32;
    bool dHit = dst<mclHi && dst+len>mclLo;
    bool sHit = src<mclHi && src+len>mclLo;
    if(dHit||sHit){
      std::fprintf(stderr,"[mcpy] dst=%08X src=%08X len=%08X lr=%08X %s%s\n",
        dst,src,len,(uint32_t)ctx.lr, dHit?"D":"", sHit?"S":"");
      std::fflush(stderr);
    }
  }
  __imp__sub_88072260(ctx,base);
  if(lg){
    std::fprintf(stderr,"[slot] sub_88072260 exit val=%08X r1=%08X\n", PPC_LOAD_U32(g_cd20_slot+4), ctx.r1.u32);
    std::fflush(stderr);
  }
}
SLOT_WATCH_WRAP(sub_880753F8)

// RT_DECLOG=1 (char-card hunt): log every asset-decoder invocation. The four decoders are
// dispatched by the FUN_8813a738 job pump (mode byte 1..4 -> A248/A118/9D90/9A88); the card
// art buffer is composed by CPU stores that guard-watch/readlog/memcpylog all failed to
// attribute, so log r3..r6 at entry + r3 at exit for each decode and correlate offline with
// the buffer address the staging fill later reads (e.g. 0x125C9010).
#define DECODER_LOG_WRAP(FN)                                                             \
  extern "C" void __imp__##FN(PPCContext& __restrict, uint8_t*);                         \
  PPC_FUNC(FN){                                                                          \
    static const bool lg = std::getenv("RT_DECLOG")!=nullptr;                            \
    uint32_t a=ctx.r3.u32,b=ctx.r4.u32,c=ctx.r5.u32,d=ctx.r6.u32,l=(uint32_t)ctx.lr;     \
    __imp__##FN(ctx,base);                                                               \
    if(lg){                                                                              \
      std::fprintf(stderr,"[declog] " #FN " r3=%08X r4=%08X r5=%08X r6=%08X lr=%08X -> r3=%08X\n", \
        a,b,c,d,l,ctx.r3.u32);                                                           \
      std::fflush(stderr);                                                               \
    }                                                                                     \
    /* RT_DECDUMP=<hex dst>: snapshot compressed input + decode output AT DECODE TIME     \
       (buffers recycle within a boot -- post-hoc dumps read a later asset). */          \
    static const char* ddEnv = std::getenv("RT_DECDUMP");                                \
    static uint32_t ddTgt = ddEnv ? (uint32_t)strtoul(ddEnv,nullptr,16) : 0u;            \
    if(ddTgt && a==ddTgt){                                                               \
      static int ddN=0;                                                                  \
      char p[128]; uint32_t outlen=ctx.r3.u32; if(outlen>0x40000u) outlen=0x40000u;      \
      std::snprintf(p,sizeof p,"C:/tmp/decdump_%08X_%d_out.bin",a,ddN);                  \
      if(FILE* f=std::fopen(p,"wb")){ std::fwrite(base+a,1,outlen,f); std::fclose(f); }  \
      std::snprintf(p,sizeof p,"C:/tmp/decdump_%08X_%d_comp.bin",a,ddN);                 \
      if(FILE* f=std::fopen(p,"wb")){ std::fwrite(base+b,1,0x10000,f); std::fclose(f); } \
      std::fprintf(stderr,"[decdump] " #FN " #%d dst=%08X src=%08X outlen=%08X\n",       \
        ddN,a,b,ctx.r3.u32); std::fflush(stderr); ddN++;                                 \
    }                                                                                     \
  }
DECODER_LOG_WRAP(sub_88139A88)
DECODER_LOG_WRAP(sub_88139D90)
DECODER_LOG_WRAP(sub_8813A248)
DECODER_LOG_WRAP(sub_8813A118)

// RT_UPLOG=1 (pump-refactor retry prerequisite; ledger 08-14 revert block): the produce arm's
// upload-descriptor ARGUMENTS are invisible to RT_DECLOG — the a15bdbc refactor shipped a
// user-visible playfield regression THROUGH a 398/398 STRICT decode-stream pass. Cover the
// descriptor-build trio (sub_88090E58/D50/CB8), the async cache-line read variant
// (sub_880924E8 — its r4 dest arg is the "leftover register IS an argument" precedent), and
// the upload pair (sub_8808D640/DF70) the way declog covers the decoders. r3..r8 at entry
// (capture MORE than the known arity — leftovers can BE arguments), lr, r3 at exit.
//
// LINK-ORDER CONTRACT (the shadowed-hook seam, ledger 08-13): merged_game.o precedes gen_*.o,
// so these wrappers win over GENERATED bodies — they fire on the control DLLs (asset decomp
// excluded) and on the abn ship arm (same exclusion). On the PILOT normal arm,
// decomp_asset_upload.o precedes merged_game.o, so the D640/DF70 wrappers are DEAD there BY
// DESIGN — decomp/game/asset_upload.cpp carries identical-format in-body logs instead.
// POSITIVE CONTROL: a differential run must show >0 [uplog] lines per covered fn per arm
// (updiff_compare.py enforces this) — "wrapper printed nothing" NEVER means "path not taken".
#define UPLOAD_LOG_WRAP(FN)                                                              \
  extern "C" void __imp__##FN(PPCContext& __restrict, uint8_t*);                         \
  PPC_FUNC(FN){                                                                          \
    static const bool lg = std::getenv("RT_UPLOG")!=nullptr;                             \
    uint32_t a=ctx.r3.u32,b=ctx.r4.u32,c=ctx.r5.u32,d=ctx.r6.u32,e=ctx.r7.u32,           \
             f=ctx.r8.u32,l=(uint32_t)ctx.lr;                                            \
    __imp__##FN(ctx,base);                                                               \
    if(lg){                                                                              \
      std::fprintf(stderr,"[uplog] " #FN " r3=%08X r4=%08X r5=%08X r6=%08X r7=%08X r8=%08X lr=%08X -> r3=%08X\n", \
        a,b,c,d,e,f,l,ctx.r3.u32);                                                       \
      std::fflush(stderr);                                                               \
    }                                                                                     \
  }
UPLOAD_LOG_WRAP(sub_88090E58)
UPLOAD_LOG_WRAP(sub_88090D50)
UPLOAD_LOG_WRAP(sub_88090CB8)
UPLOAD_LOG_WRAP(sub_880924E8)
UPLOAD_LOG_WRAP(sub_8808D640)
UPLOAD_LOG_WRAP(sub_8808DF70)

// ---- SESSION 6e: tripwires for unresolved-jump-table functions. sub_8807D838 and
// sub_8808B330 contain byte-lookup jump tables that were never resolved during
// recompilation. If either fires inside the CD20 call window, it's a prime suspect
// for leaking/shifting r1. Log every invocation (no hit-counter cap).
extern "C" void __imp__sub_8807D838(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_8807D838){
  static std::atomic<long> jn{0}; long j=jn.fetch_add(1)+1;
  bool lg=(j<=64)||(j%500)==0;   // CODE_REVIEW_0804 E21: tripwire kept, flood capped
  if(lg){ std::fprintf(stderr,"[JT-UNRESOLVED] sub_8807D838 ENTER #%ld lr=%08X r1=%08X\n", j, (uint32_t)ctx.lr, ctx.r1.u32); std::fflush(stderr); }
  __imp__sub_8807D838(ctx,base);
  if(lg){ std::fprintf(stderr,"[JT-UNRESOLVED] sub_8807D838 EXIT r1=%08X\n", ctx.r1.u32); std::fflush(stderr); }
}

extern "C" void __imp__sub_8808B330(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_8808B330){
  static std::atomic<long> jn{0}; long j=jn.fetch_add(1)+1;
  bool lg=(j<=64)||(j%500)==0;   // CODE_REVIEW_0804 E21: tripwire kept, flood capped
  if(lg){ std::fprintf(stderr,"[JT-UNRESOLVED] sub_8808B330 ENTER #%ld lr=%08X r1=%08X\n", j, (uint32_t)ctx.lr, ctx.r1.u32); std::fflush(stderr); }
  __imp__sub_8808B330(ctx,base);
  if(lg){ std::fprintf(stderr,"[JT-UNRESOLVED] sub_8808B330 EXIT r1=%08X\n", ctx.r1.u32); std::fflush(stderr); }
}

// ---- [gemsg] GameEntry message counter: log every distinct msg's first 3 calls + running
// totals. Tells us exactly which msgs the native tick path sends vs our driver's 6/7/1/2/8/9. ----
// RT_MSGLOG (2026-07-22 TRAINING-MODE DRIVE leg, Fable-5): default-off VERBOSE extension — for the
// credited-flow-critical rare messages (9/10/12/13/14/15/16/19) dump the arg pointer's first words
// AND the credited mailboxes 887ad58c / 887ad547 BEFORE and AFTER the call, on the first several
// occurrences. This is the "did the shell's game-start flow send msg 14 (case0xd -> 887ad58c=2)"
// probe. Presence-gated; when RT_MSGLOG is unset the behaviour is exactly the prior cheap logger.
extern "C" void __imp__sub_8824E698(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_8824E698){
  static std::atomic<long> cnt[24];
  uint32_t m=ctx.r3.u32;
  long n = (m<24)? cnt[m].fetch_add(1)+1 : -1;
  if(n>0 && (n<=3 || n%600==0)) std::fprintf(stderr,"[gemsg] GameEntry(msg=%u, r4=0x%X) call#%ld\n",m,ctx.r4.u32,n);
  const bool verbose = std::getenv("RT_MSGLOG")!=nullptr;
  // The rare, credited-flow-relevant messages: arm/config setters + the msg-14 credited trigger.
  const bool crit = (m==9||m==10||m==11||m==12||m==13||m==14||m==15||m==16||m==17||m==18||m==19||m==20);
  if(verbose && crit && n>0 && n<=6){
    uint32_t r4=ctx.r4.u32; uint32_t w0=0,w1=0,w2=0,w3=0;
    if(r4){ w0=PPC_LOAD_U32(r4); w1=PPC_LOAD_U32(r4+4); w2=PPC_LOAD_U32(r4+8); w3=PPC_LOAD_U32(r4+12); }
    std::fprintf(stderr,"[msglog] PRE  msg=%u#%ld lr=0x%X r4=0x%X arg[0..3]=%08X %08X %08X %08X | 58c=%u 547=%u 584=%u\n",
      m,n,(unsigned)ctx.lr,r4,w0,w1,w2,w3,(unsigned)PPC_LOAD_U32(GA_MB_RELOAD),(unsigned)PPC_LOAD_U8(GA_MB_CREDITED),(unsigned)PPC_LOAD_U32(GA_MB_MODE64));
  }
  __imp__sub_8824E698(ctx,base);
  if(n>0 && n<=3) std::fprintf(stderr,"[gemsg] GameEntry(msg=%u) -> r3=0x%X\n",m,ctx.r3.u32);
  if(verbose && crit && n>0 && n<=6){
    std::fprintf(stderr,"[msglog] POST msg=%u#%ld -> r3=0x%X | 58c=%u 547=%u  (msg14 arms credited when 58c->2)\n",
      m,n,ctx.r3.u32,(unsigned)PPC_LOAD_U32(GA_MB_RELOAD),(unsigned)PPC_LOAD_U8(GA_MB_CREDITED));
  }
}
// SIGFPE GUARD (2026-07-12, RT_SAVE options-menu recipe): sub_882272E8 is an in-game-menu
// layout/selection helper (reached via the OPTION item, cursor84=4, d76 2->3). Deep inside it
// (ppc_recomp.30.cpp ~line 24746) it does `divwu r8,r11,r10` with r10 loaded fresh from a
// guest global divisor at 0x887ACE14 (`lis r10,-30597; lwz r10,-12780(r10)`). The real ucode
// guards this divide with a trap (twllei) that XenonRecomp drops -> a raw host `divl` faults
// (EXCEPTION_INT_DIVIDE_BY_ZERO, symbolicated via a /MAP relink + llvm-objdump at the exact
// fault RVA) when 0x887ACE14 is still 0 -- observed on every RT_NATPLAY_CURSOR=4 (OPTION) run
// in the headless recomp; the value is presumably populated by some options-data/config-table
// init we haven't traced. Repair-not-crash, same convention as sub_82114628 above: if the
// divisor is ever seen at 0, set it to 1 (matches "denominator floor" style guards elsewhere)
// so the layout math degenerates harmlessly instead of faulting, then call through.
extern "C" void __imp__sub_882272E8(PPCContext& __restrict, uint8_t*);
PPC_FUNC(sub_882272E8){
  // CODE_REVIEW_0804: this WRITES guest state (unlike the skip-only sub_82114628 sibling) and
  // had no off-switch — RT_DIVGUARD=0 now reverts, per the every-behaviour-change-gets-a-lever rule.
  static const bool divGuard = [](){ const char* e=std::getenv("RT_DIVGUARD"); return !(e&&e[0]=='0'&&!e[1]); }();
  if(divGuard && PPC_LOAD_U32(0x887ACE14u)==0){
    PPC_STORE_U32(0x887ACE14u, 1u);
    static int lg=0; if(lg++<8)
      std::fprintf(stderr,"[sfpe] sub_882272E8 divisor@0x887ACE14 was 0 -> repaired to 1\n");
  }
  __imp__sub_882272E8(ctx,base);
}

// ★ 2026-08-02 GHOST-VOICE FORK INSTRUMENT (shot-level hunt). sub_880901B8 = the game's
// STOP-SLOT (decomp reco_normal:21850-21878): zeroes the 0x18-byte active-voice slot, queues a
// type-3 message to the engine (vtable+0x3C) and calls voice vtable+0xC (destroy). The digital
// A/B put the shot demo at x6 IN THE GUEST MIX while the slot census matches the SDK — so
// either stops are never REQUESTED (this wrapper's rate ~0 vs the [cuetally] play rate) or
// they are requested and the DESTROY never lands (rate matches plays; hunt moves to the engine
// message pump / voice vtable+0xC path). Tally-only, gated on RT_VOICECENSUS, passthrough.
static std::atomic<long> g_stopslot_calls{0};
PPC_FUNC(sub_880901B8){
  static bool on = [](){ const char* e=std::getenv("RT_VOICECENSUS"); return e && e[0]=='1' && !e[1]; }();
  if(on){
    long n=g_stopslot_calls.fetch_add(1)+1;
    if(n<=8 || (n%64)==0)
      std::fprintf(stderr,"[stopslot] #%ld slot=%u lr=0x%X\n",n,(unsigned)ctx.r3.u32,(uint32_t)ctx.lr);
  }
  __imp__sub_880901B8(ctx,base);
}
