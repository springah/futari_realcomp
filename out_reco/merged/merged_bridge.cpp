// merged_bridge.cpp — the module-agnostic Xex bridge: XexLoadImage / XexGetProcedureAddress /
// XexGetModuleHandle + rt_load_game_data_sections + the RT_REATTACH lever
// Split out of out_reco/merged/merged_xex.cpp (verbatim) by L2 of
// _tmpscripts/dll_packaging_plan.md §2.3/§2.4.  Original: merged_xex.cpp.bak_l2split.
// Shared scaffolding lives in merged_common.h.
#include "merged_common.h"
#ifdef FUTARI_COMBINED
#include "../../host/module_registry.h"   // L5: the combined exe's module lifecycle
#endif

// ---- L4/E6: THE TWO CROSS-MODULE-LINE GLOBALS NOW LIVE HERE (host side) -------------------
// Both were defined in merged_game.cpp, which becomes DLL-resident at E6.  Both are WRITTEN by
// the game half and READ by host code (render/vk_render.cpp, shell/gen/rt.cpp,
// merged_shell.cpp), so a per-DLL copy would have split them SILENTLY — vk_render.cpp carries
// a `__attribute__((weak))` definition of g_rt_romactive, so the split would have LINKED and
// left rt_rom_render()'s routing gate and the pillarbox decision permanently false.
// Inside a module DLL these names are macros over the bound host pointers (merged_common.h);
// the game half's write sites are unchanged text either way.
//   g_rt_romactive  1 once the arcade ROM main (sub_88168D48) is running — gates the legacy
//                   PM4 spine routing for attract AND field (shell/gen/rt.cpp:389-392) and the
//                   TATE pillarbox (vk_render.cpp:7822).  Cleared by XexUnloadImage.
//   g_rt_realstage  1 once the arcade-select FSM has submitted to a REAL stage — gates the
//                   one-shot RVK_ARENADUMP capture (vk_render.cpp:8806).
extern "C" { volatile int g_rt_romactive = 0; }
extern "C" { volatile int g_rt_realstage = 0; }
// ---- L3: the four module constants this TU used to own now come from the descriptor -------
// Retired -D flags. A stale one in a build script must be a COMPILE ERROR, not a silently
// ignored macro that leaves the desc's value in force behind its back.
#ifdef GAME_ENTRY_ORD1_VAL
#error "GAME_ENTRY_ORD1_VAL retired at L3 -> FutariModuleDesc::entry_ord1. Pass -DFUTARI_MODULE=<0|1>."
#endif
#ifdef GAME_MODULE_BASENAME_STR
#error "GAME_MODULE_BASENAME_STR retired at L3 -> FutariModuleDesc::module_basename. Pass -DFUTARI_MODULE=<0|1>."
#endif
// GAME_HMODULE  -> futari_desc()->image_base   (x360 convention: handle == image base)
// GAME_ENTRY_ORD1 -> ->entry_ord1              (export ordinal 1 = GameEntry)
// GAME_XSTART   -> ->xstart                    (module entry, DllMain-style PROCESS_ATTACH)
// GAME_MODULE_BASENAME -> ->module_basename
// Each consumer takes a function-LOCAL reference (`const FutariModuleDesc& d = *futari_desc();`)
// rather than a file-scope alias, because at L4 futari_desc() becomes a relaxed atomic load of
// the currently-bound module and a file-scope alias would freeze the first one (plan §3.6).
static const uint32_t RECO_LOADER     = 0x821C8A80u;  // reco_normal loader clone (no longer called directly; see sub_821C3B90)

// Set by __imp__XexUnloadImage (shell/gen/stubs.cpp) when the guest unloads the game module;
// consumed by the RT_REATTACH lever below (mode-switch de-risk, 2026-07-30).
extern "C" volatile int g_game_unloaded = 0;

// The ONE module this build statically recompiled. Any other game:\media\Module\*.xex
// request must fail LOUDLY (0xC0000135) instead of silently serving reco_normal's code
// under another mode's name — see NOTE_other_modes.md §5/§7 (silent-substitution hazard:
// every Module path used to match here via the "Module" substring).
#ifndef _WIN32
#include <strings.h>
#define _strnicmp strncasecmp   // MSVC CRT spelling; same alias as host/module_registry.cpp
#endif
static bool str_icontains(const char* hay, const char* needle){
  const size_t nl = std::strlen(needle);
  for(const char* p = hay; *p; ++p)
    if(_strnicmp(p, needle, nl) == 0) return true;
  return false;
}

// ---- L5: "which module does this guest path name?" ---------------------------------------
// PER-MODULE EXE: exactly one answer is possible — the module we statically host — so this is
// the old substring test, unchanged.
// COMBINED EXE: the question genuinely has N answers and the REGISTRY owns it.  Note what this
// does NOT do: it never invents or rewrites a path.  Each of the shell's eight per-mode loader
// ctors builds its OWN "game:\media\Module\<name>.xex" string (FUN_821C8A80 = reco_normal,
// its siblings = the rest), so the guest names the module it wants and we only recognise it.
// That is why the combined exe needs no name plumbing anywhere: [modestub] L2 simply stops
// vetoing modeIdx 1, and the request that arrives here already says "reco_abnormal".
static const FutariModuleDesc* module_for_path(const uint8_t* base, uint32_t p){
  if(!p) return nullptr;
  const char* s = (const char*)(base + p);
#ifdef FUTARI_COMBINED
  return futari_registry_resolve_path(s);
#else
  return str_icontains(s, futari_desc()->module_basename) ? futari_desc() : nullptr;
#endif
}

static bool path_is_game(const uint8_t* base, uint32_t p){
  return module_for_path(base, p) != nullptr;
}

// What this build can serve, for the one log line that has to say it.
static const char* futari_hosted_modules_str(){
#ifdef FUTARI_COMBINED
  return futari_registry_summary();
#else
  static char b[64]; std::snprintf(b,sizeof b,"%s.xex only",futari_desc()->module_basename); return b;
#endif
}

// Set by the swap arm of XexLoadImage, consumed by its attach block a few lines later.  A plain
// file static, not an atomic: both writer and reader are the same guest thread inside the same
// call, and the `swapping` CAS above already excludes a concurrent second loader.
static int g_swap_forces_attach = 0;

// A game-module-shaped request (Module dir or .xex) that is NOT the module we host.
static bool path_is_foreign_module(const uint8_t* base, uint32_t p){
  if(!p || path_is_game(base,p)) return false;
  const char* s = (const char*)(base + p);
  return str_icontains(s,"module") || str_icontains(s,".xex");
}

// FIX (data-section bridge): reco_normal.xex's real .data/.bss image bytes are never copied
// into guest memory by this bridge (unlike out_reco/harness.cpp's own xexpath-gated loader,
// which this merged binary's invocation does not use). That leaves every static/global in
// the game's .data section — including the FILE_INFO class-34 vtable object at guest
// 0x88252560 that sub_880865F0 (out_reco/ppc_recomp.3.cpp:14910) reads through — all-zero,
// so its vtable-slot reads resolve to null and callers (e.g. sub_88092ED8's record-parse
// loop) spin on a garbage count. Root cause + verification: see the RE recipe. Minimal fix:
// load the game XEX's DATA-bearing sections (skip the CODE section, already covered by the
// recompiler's own PPCFuncMappings host-function table) into guest memory once, before the
// game's DllMain/_xstart runs, mirroring harness.cpp's memcpy loop.
// CODE_REVIEW_0804 A5: renderer lock across the ~6MB section re-image (same guard the registry
// switch holds over its memset window — a mid-flight frame walk must never see a half-copied
// arena). Weak: absent renderer, the guards are null and skipped. Guest code (DllMain) runs
// AFTER the guard is released — never hold g_mtx across guest execution.
extern "C" void rvk_swap_guard_begin(void) __attribute__((weak));
extern "C" void rvk_swap_guard_end(void) __attribute__((weak));
static void rt_load_game_data_sections(uint8_t* base){
  const FutariModuleDesc& d = *futari_desc();
  // ⚠ L3 BEHAVIOUR DELTA ON THE ABN ARM ONLY — read this before trusting a boot.
  // These two used to be the literals 0x88070000 / 0x1DEEB0, i.e. reco_NORMAL's code range,
  // in a TU compiled into BOTH exes. reco_abnormal's code section is 0x1DEEB8 (8 bytes
  // longer, out_reco_abn/ppc_config.h), so the `skip the CODE section` test below never
  // matched on the abn arm and the abn build has been memcpy'ing ~1.9 MB of guest CODE image
  // into the arena that the accepted normal build deliberately skips. Measured proof, from
  // banked logs: normal prints "loaded 4 game DATA sections (6060812 bytes)", abn prints
  // "loaded 5 game DATA sections (8022516 bytes)" — one extra section, code-sized.
  // Taking the size from the descriptor fixes it, which CHANGES the abn arm. RT_XEXCODESEC=1
  // restores the pre-L3 abn behaviour (copy the CODE section too) without a rebuild, so the
  // boot gate has a one-env A/B if the abn arm regresses. The normal arm is unaffected either
  // way: its literal and its descriptor value are the same number.
  const uint32_t CODE_BASE = d.code_base, CODE_SIZE = d.code_size;
  static bool keepcode = std::getenv("RT_XEXCODESEC") && atoi(std::getenv("RT_XEXCODESEC"))!=0;
  // Module-image resolution ladder (2026-07-30, Q7 closed): (1) XR_RECO_NORMAL env override;
  // (2) cwd-local "<basename>.xex" (the dev-tree root copy — the only path that existed
  // before); (3) RT_GAME_ROOT/media/Module/<basename>.xex — the layout the dist actually
  // ships. The shipped alpha-1 had NO root xex and NO env, so LoadFile returned empty and
  // ParseImage null-dereferenced = the 0xC0000005 at mode select in the alpha-1 boot-test
  // log. All-fail is now DIE-LOUD instead of a null deref.
  const char* env = std::getenv("XR_RECO_NORMAL");
  const char* groot = std::getenv("RT_GAME_ROOT");
  std::string name = std::string(d.module_basename) + ".xex";
  std::string cands[3]; int nc = 0;
  if(env) cands[nc++] = env;
  cands[nc++] = name;
  if(groot) cands[nc++] = std::string(groot) + "/media/Module/" + name;
  std::vector<uint8_t> f; std::string chosen;
  for(int ci = 0; ci < nc && f.empty(); ++ci){ f = LoadFile(cands[ci]); if(!f.empty()) chosen = cands[ci]; }
  if(f.empty()){
    std::fprintf(stderr, "\n[xex] FATAL: cannot find the game module image '%s' — tried:\n", name.c_str());
    for(int ci = 0; ci < nc; ++ci) std::fprintf(stderr, "  [xex]   %s\n", cands[ci].c_str());
    std::fflush(stderr);
    std::_Exit(7);
  }
  std::fprintf(stderr, "  [xex] game module image: %s (%zu bytes)\n", chosen.c_str(), f.size());
  Image img = Image::ParseImage(f.data(), f.size());
  long sc = 0; unsigned long long by = 0;
  if (rvk_swap_guard_begin) rvk_swap_guard_begin();   // CODE_REVIEW_0804 A5: no walk mid-copy
  for(const auto& sN : img.sections){
    uint64_t b=(uint64_t)sN.base, z=(uint64_t)sN.size;
    if(!sN.data || z==0) continue;
    if(b < (uint64_t)d.image_base || b+z > (uint64_t)d.image_base + d.image_size) continue;  // out of guest image bounds
    if(!keepcode && b == CODE_BASE && z == CODE_SIZE) continue;  // skip CODE: PPCFuncMappings already covers it
    std::memcpy(base+b, (const void*)sN.data, z);
    ++sc; by += z;
  }
  if (rvk_swap_guard_end) rvk_swap_guard_end();
  std::fprintf(stderr,"  [xex] loaded %ld game DATA sections (%llu bytes) from %s\n", sc, by, chosen.c_str());
  // [rapiden] (2026-07-24 RT-rapid leg): static image values of the game-settings cluster
  // 0x88449a14..1b and the factory-defaults table 0x88062d60..67. FUN_88134048 (ship input
  // decode) MASKS OUT the R.SHOT bit 0x40 when DAT_88449a19==0, and NOTHING in the decomp dump
  // ever writes a19 nonzero (the 8816a7xx config menu only round-trips it; the FUN_88138f00
  // options commit skips it) — so its load-time value decides whether rapid-fire can ever work.
  std::fprintf(stderr,"  [rapiden] static a14..1b = %02X %02X %02X %02X %02X %02X %02X %02X   defaults 62d60..67 = %02X %02X %02X %02X %02X %02X %02X %02X\n",
    base[0x88449a14u],base[0x88449a15u],base[0x88449a16u],base[0x88449a17u],
    base[0x88449a18u],base[0x88449a19u],base[0x88449a1au],base[0x88449a1bu],
    base[0x88062d60u],base[0x88062d61u],base[0x88062d62u],base[0x88062d63u],
    base[0x88062d64u],base[0x88062d65u],base[0x88062d66u],base[0x88062d67u]);
}

extern "C" {

// ---- (1) Xex bridge (strong; build_merged.sh weakens the shell-kernel return-0 stubs) ----
PPC_FUNC(__imp__XexLoadImage){
  g_import_calls++;
  uint32_t path=ctx.r3.u32, hout=ctx.r6.u32;
  const char* s = path ? (const char*)(base+path) : "(null)";
  const FutariModuleDesc* want = module_for_path(base, path);
  if(want){
    // ---- L5: THE MODULE SWAP ----------------------------------------------------------------
    // The whole runtime-mode-switch feature is these eight lines plus module_registry.cpp.
    // Placement is load-bearing: we are on the GUEST thread, inside XexLoadImage, BEFORE the
    // hmodule is handed back — the one instant at which the guest has torn the old module down
    // (msg13 -> msg3 -> both game threads TERMINATE -> XexUnloadImage) and has not yet touched
    // the new one.  That is what makes the swap atomic with respect to the guest, and it is the
    // exact window the 2026-07-29 RT_REATTACH probe drove twice (A,B,A) without a VK error.
    // A swap FORCES the attach block below: fresh .data/.bss image + a fresh
    // DllMain(PROCESS_ATTACH) are not optional across modules, so `attached` is bypassed.
#ifdef FUTARI_COMBINED
    static std::atomic<bool> swapping{false};
    if(want != futari_desc()){
      bool sexp=false;
      if(!swapping.compare_exchange_strong(sexp,true)){
        std::fprintf(stderr,"  [xex] REENTRANT module swap request for \"%s\" — refusing\n",s);
        if(hout) *(uint32_t*)(base+hout)=0;
        ctx.r3.u32=0xC0000135u; return;
      }
      int ok = futari_registry_switch(want, base);
      swapping.store(false);
      if(!ok){
        std::fprintf(stderr,"  [xex] XexLoadImage(\"%s\") FAILED: module swap refused — the "
                            "[modestub] L3 safety net will bounce the player to the top menu\n",s);
        if(hout) *(uint32_t*)(base+hout)=0;
        ctx.r3.u32=0xC0000135u; return;
      }
      g_swap_forces_attach = 1;   // consumed once, below
    }
#endif
    const FutariModuleDesc& d = *futari_desc();   // AFTER the swap: this is the incoming module
    // One-time DllMain(PROCESS_ATTACH) call into the resident game module's real entry
    // (_xstart @ d.xstart), BEFORE we hand back the hmodule — matches real XexLoadImage
    // semantics (module entry runs synchronously on the calling thread before the loader
    // returns). Without this the game's CRT heap is never initialized and its first
    // mallocs corrupt memory. Save the bridge's own in/out regs across the call since the
    // attach call clobbers volatiles (r3-r10 etc per rt_indirect_call/PPCContext copy).
    static std::atomic<bool> attached{false};
    // RT_REATTACH=1 (mode-switch de-risk, 2026-07-30): after a genuine XexUnloadImage, re-run
    // this whole attach block on the next load — fresh .data/.bss re-image + a second
    // DllMain(PROCESS_ATTACH) — instead of reusing the first boot's dirty module state (the
    // default one-shot behavior). This is exactly the lifecycle a runtime module SWAP needs;
    // the lever proves it on the resident module alone. Known debt if this ever ships: the
    // first attach's CRT heap arenas leak in the guest heap (the re-imaged .data drops the
    // pointers), acceptable for a de-risk probe.
    // L5: on the combined exe RT_REATTACH is DEFAULT-ON, because a mode swap IS a reattach and
    // the same-module re-select (A -> menu -> A) must behave identically to the cross-module
    // one — one lifecycle, one code path, one thing to gate.  RT_REATTACH=0 still turns it off
    // for A/B.  On the two per-module exes the default is unchanged (off): that is the shape
    // their gates passed with.
#ifdef FUTARI_COMBINED
    static bool reattach = std::getenv("RT_REATTACH") ? atoi(std::getenv("RT_REATTACH"))!=0 : true;
#else
    static bool reattach = std::getenv("RT_REATTACH") && atoi(std::getenv("RT_REATTACH"))!=0;
#endif
    bool exp=false;
    bool doAttach = attached.compare_exchange_strong(exp,true);
    if(!doAttach && reattach && g_game_unloaded){
      g_game_unloaded = 0;
      doAttach = true;
      std::fprintf(stderr,"  [xex] RT_REATTACH: unload seen -> re-imaging game data + DllMain(PROCESS_ATTACH) again\n");
    }
    // A module SWAP always re-attaches, whatever the lever says: the incoming module has never
    // had its .data imaged in this process and its CRT has never run.  Skipping it would run
    // module B's code against module A's static image — the loudest possible corruption class.
    if(g_swap_forces_attach){
      g_swap_forces_attach = 0;
      g_game_unloaded = 0;
      if(!doAttach) std::fprintf(stderr,"  [xex] module swap -> forcing re-image + DllMain(PROCESS_ATTACH)\n");
      doAttach = true;
    }
    if(doAttach){
      // Load the game's real .data/.bss image bytes into guest memory BEFORE DllMain/_xstart
      // runs, so _initterm_e's static-ctor table and every other .data global (including the
      // 0x88252560 FILE_INFO vtable object) are populated instead of reading back as zero.
      rt_load_game_data_sections(base);
      PPCContext ic=ctx;
      ic.r3.u32=d.image_base;  // hmodule
      ic.r4.u32=1;             // DLL_PROCESS_ATTACH
      ic.r5.u32=0;             // reserved
      rt_indirect_call(ic,base,d.xstart);
      std::fprintf(stderr,"  [xex] DllMain(PROCESS_ATTACH) -> r3=0x%X\n",ic.r3.u32);
      if(ic.r3.u32!=1){
        std::fprintf(stderr,"  [xex] WARNING: DllMain(PROCESS_ATTACH) returned r3=0x%X (expected 1) — continuing anyway\n",ic.r3.u32);
      }
      // ctx (the bridge's own r3/r6/etc) is untouched — we called through the copy `ic`.

      // Thread notify-list sentinel (sub_88083A10 walks this LIST_ENTRY at guest
      // 0x88252504/0x88252508 on every new game thread's xapi startup). Nothing in the
      // game ever inserts into this list, so a real xapi init would leave it self-pointing
      // (empty list). Our harness leaves it zeroed, so the walk chases garbage at guest
      // address 0 forever and the game thread never reaches main. Initialize it once here,
      // right after DllMain(PROCESS_ATTACH), matching what real xapi startup would do.
      PPC_STORE_U32(0x88252504u, 0x88252504u);  // notify-list sentinel Flink -> self (empty)
      PPC_STORE_U32(0x88252508u, 0x88252504u);  // Blink -> self
      std::fprintf(stderr,"  [xex] notify-list sentinel initialized\n");
      rt_heapdump(base, "post-attach");
    }
    if(hout) *(uint32_t*)(base+hout)=__builtin_bswap32(d.image_base);
    std::fprintf(stderr,"  [xex] XexLoadImage(\"%s\") -> resident hmodule=0x%08X\n",s,d.image_base);
    ctx.r3.u32=0;
  } else {
    // The mode-substitution guard.  Since the [modestub] layers landed (2026-07-31) this is
    // DEAD CODE ON THE MENU PATH — L1/L2 decline before a loader ctor is ever constructed — and
    // a REFUSED line on a gate run therefore means a stub layer MISSED.  It stays as the last
    // line of defence and as [modestub] L3's trigger (it is what leaves modectx+0xF8 == 0).
    if(path_is_foreign_module(base,path))
      std::fprintf(stderr,"  [xex] XexLoadImage(\"%s\") REFUSED: this build hosts %s (mode-substitution guard)\n",
                   s, futari_hosted_modules_str());
    else
      std::fprintf(stderr,"  [xex] XexLoadImage(\"%s\") -> not the game module\n",s);
    if(hout) *(uint32_t*)(base+hout)=0;
    ctx.r3.u32=0xC0000135u;
  }
}
PPC_FUNC(__imp__XexGetProcedureAddress){
  const FutariModuleDesc& d = *futari_desc();
  g_import_calls++;
  uint32_t hmod=ctx.r3.u32, ordinal=ctx.r4.u32, fout=ctx.r5.u32;
  if(hmod==d.image_base && ordinal==1){
    if(fout) *(uint32_t*)(base+fout)=__builtin_bswap32(d.entry_ord1);
    std::fprintf(stderr,"  [xex] XexGetProcedureAddress(0x%08X, ord=%u) -> 0x%08X\n",hmod,ordinal,d.entry_ord1);
    ctx.r3.u32=0;
  } else {
    std::fprintf(stderr,"  [xex] XexGetProcedureAddress(0x%08X, ord=%u) -> not found\n",hmod,ordinal);
    if(fout) *(uint32_t*)(base+fout)=0;
    ctx.r3.u32=0xC0000225u;
  }
}
PPC_FUNC(__imp__XexGetModuleHandle){
  // ★ CODE_REVIEW_0804 D13: guest contract (call site shell/gen/ppc_recomp.23.cpp:24561+):
  // r4 = &handleOut, NTSTATUS in r3 (blt on negative), handle read back from *r4. The old body
  // returned the HANDLE in r3 (0 = STATUS_SUCCESS even on miss) and never wrote *r4 — the
  // guest read uninitialised stack as the module handle. Same shape as XexGetProcedureAddress
  // directly above, which was always correct.
  const FutariModuleDesc& d = *futari_desc();
  g_import_calls++;
  uint32_t name=ctx.r3.u32, hout=ctx.r4.u32;
  if(path_is_game(base,name)){
    if(hout) *(uint32_t*)(base+hout)=__builtin_bswap32(d.image_base);
    ctx.r3.u32=0;
  } else {
    if(hout) *(uint32_t*)(base+hout)=0;
    ctx.r3.u32=0xC0000225u;   // STATUS_NOT_FOUND — negative, the caller's blt takes the failure leg
  }
}

} // extern "C"
