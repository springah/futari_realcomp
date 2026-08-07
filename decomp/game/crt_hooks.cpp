// decomp/game/crt_hooks.cpp — the 5 game-module CRT hooks, extracted from out_reco/rt.cpp
// (DLL plan L1/E2, 2026-07-30: these are game-module-side hooks and belong in the tree that
// moves into the module DLL; the decomp tree also links FIRST, so the strong defs win over the
// generated weak aliases by symbol strength AND order instead of order alone).
//
// Contents are verbatim from out_reco/rt.cpp (the [crt] trace family, RT_CRTTRACE=1):
//   sub_88083920 / sub_88070E30 / sub_88083768  — traced pass-throughs
//   sub_88070318                                — _CRT_INIT (DllMain attach gate)
//   sub_88083848                                — _initterm_e FULL REPLACEMENT (boot-critical):
//     bounds HARD-CODED 0x88250000..0x88250008 (2 entries; the ctor pointers are read from
//     guest memory at runtime, so a re-imaged/swapped module supplies its own values), and the
//     only host-side PPC_LOOKUP_FUNC on the game table — the DLL plan moves it into the module
//     link unit by construction.
// In the abn build this TU compiles WITH abn_symbol_map.h like the rest of decomp/game/*.cpp;
// all five addresses are BELOW the 0x880DEF88 split (same address in every reco-law module),
// so the map correctly leaves them untouched.
#include "ppc_recomp_shared.h"
#include <cstdio>
#include <cstdlib>
#include <atomic>

// L4/E6: this TU is DLL-resident, and g_import_calls is a HOST global.  The shared header maps
// the name onto the bound host pointer inside a DLL and leaves it a plain extern everywhere
// else, so the two use sites below are unchanged text in both build shapes.
// (Its own `extern` here is what made this TU the first casualty of the DLL split — see the
// header's banner.)
#include "../../host/futari_dll_globals.h"

static bool crt_trace(){ static bool on = std::getenv("RT_CRTTRACE") != nullptr; return on; }

// --- CRT_INIT diagnostics: trace the 4 sub-calls whose return values gate a
// successful DllMain attach (sub_88070318). RT_CRTTRACE=1 to enable. ---
PPC_FUNC_IMPL(__imp__sub_88083920);
PPC_FUNC(sub_88083920){ __imp__sub_88083920(ctx,base); if(crt_trace()) std::fprintf(stderr,"[crt] sub_88083920 -> r3=0x%X\n",ctx.r3.u32); }
PPC_FUNC_IMPL(__imp__sub_88070E30);
PPC_FUNC(sub_88070E30){ __imp__sub_88070E30(ctx,base); if(crt_trace()) std::fprintf(stderr,"[crt] sub_88070E30 -> r3=0x%X\n",ctx.r3.u32); }
PPC_FUNC_IMPL(__imp__sub_88083848);
// _initterm_e: bounds are HARD-CODED in the body: lis -30683 = 0x88250000..0x88250008
// (2 entries; earlier notes said 0x88510000 -- wrong). Replicate the walk with per-entry tracing.
PPC_FUNC(sub_88083848){
  bool tr=crt_trace();
  ctx.r3.s64=0;
  for(uint32_t ea=0x88250000; ea<0x88250008 && ctx.r3.u32==0; ea+=4){
    uint32_t fp=__builtin_bswap32(*(uint32_t*)(base+ea));
    if(tr) std::fprintf(stderr,"[crt] _initterm_e entry @0x%08X = 0x%08X%s\n",ea,fp,fp?"":" (null, skip)");
    if(!fp) continue;
    PPCFunc* f=PPC_LOOKUP_FUNC(base,fp);
    if(!f){ if(tr) std::fprintf(stderr,"[crt]   !! no host func for 0x%08X\n",fp); continue; }
    long ic0=g_import_calls.load();
    f(ctx,base);
    if(tr) std::fprintf(stderr,"[crt]   init 0x%08X -> r3=0x%X (%ld import calls)\n",fp,ctx.r3.u32,g_import_calls.load()-ic0);
  }
  if(tr) std::fprintf(stderr,"[crt] sub_88083848 (_initterm_e) -> r3=0x%X\n",ctx.r3.u32);
}
PPC_FUNC_IMPL(__imp__sub_88083768);
PPC_FUNC(sub_88083768){ __imp__sub_88083768(ctx,base); if(crt_trace()) std::fprintf(stderr,"[crt] sub_88083768 -> r3=0x%X\n",ctx.r3.u32); }
PPC_FUNC_IMPL(__imp__sub_88070318);
PPC_FUNC(sub_88070318){ __imp__sub_88070318(ctx,base); if(crt_trace()) std::fprintf(stderr,"[crt] sub_88070318 (_CRT_INIT) -> r3=0x%X\n",ctx.r3.u32); }
