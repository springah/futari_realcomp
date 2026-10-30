// merged_common.h — shared scaffolding for the merged_xex.cpp 3-way split.
//
// L2 of _tmpscripts/dll_packaging_plan.md (§2.2d target "merged_common.h", §2.4 layout).
// merged_xex.cpp was partitioned along the MODULE line into:
//     merged_game.cpp    166 sub_88 game-module hooks      -> the module DLL at E6
//     merged_shell.cpp   157 sub_82 shell hooks + injection -> stays in the host exe
//     merged_bridge.cpp  the 3 Xex fns + rt_load_game_data_sections -> host, desc-driven at E4
//     merged_common.h    (this file) everything both halves need
// The original is preserved verbatim at merged_xex.cpp.bak_l2split.
//
// ONLY three things in here are not a verbatim copy of the original text:
//   * rt_heapdump()      static -> static inline   (stateless; one copy per TU is identical)
//   * g_js_menuState / g_js_taskAlive / g_js_dlgAlive
//                        static -> inline variables.  RESOLVED AT L3 STAGE 1: they are
//                        shell-private file statics again (merged_shell.cpp) and the game
//                        half's diagnostic read became the two rt_jankstate_* calls declared
//                        below.  An inline variable is one instance per IMAGE, so carrying it
//                        into the E6 DLL would have silently split the state.
//   * g_rt_romactive / g_game_unloaded — extern "C" DEFINITIONS stayed in one .cpp each
//                        (merged_game.cpp / merged_bridge.cpp); only a declaration is here.
//
// Original banner follows.
// ---------------------------------------------------------------------------------------
#pragma once
// merged_xex.cpp — Gate 2: make the booted shell load+drive the reco_normal game module.
// Linked into futari_merged ONLY (out_reco/merged/, excluded from both default *.cpp globs).
// Compiled with GAME headers (-I out_reco). Two parts:
//   (1) Xex loader BRIDGE — the game module is already resident in the merged address space,
//       so the shell's own load path (loader sub_821C8A80 → XexLoadImage +
//       XexGetProcedureAddress(ordinal 1)) resolves to it instead of re-loading.
//   (2) INJECTION — override the shell idle/render loop sub_821706E8 so that, on first entry
//       (after full shell boot, before idling), we run the shell's mode-select dispatcher
//       sub_821C3B90 (one level above the loader) + driver, then fall through to the real
//       loop (which now renders with the game active). This is the code-path equivalent of
//       a menu "start game", bypassing the terminate-on-advance menu.
//
// Recipe (verified by RE agent against decompressed default.xex strings):
//   Entry point is now sub_821C3B90, the shell's mode-select dispatcher: it reads a mode
//   selector out of modectx+104 and, internally, runs the modectx ctor sub_821C57B8, the
//   reco_normal loader clone sub_821C8A80 (NOT sub_821C2F58 = palm_abnormal; builds
//   "game:\media\Module\reco_normal.xex", calls XexLoadImage →hmodule@modectx+248 +
//   XexGetProcedureAddress(ord 1) →GameEntry@modectx+252), AND the critical tail setup our
//   old direct-loader-call bypass used to skip (this is why we now enter one level higher).
//   Selector value 8 routes the dispatcher's default branch to reco_normal.
//   driver sub_821C30B8 then sends GameEntry msgs 6,7,1,2,8,9 + a finalize vtable call.
//   modectx = zeroed >=256 bytes (use 512 — dispatcher touches more fields than the bare
//   loader did); single r3=modectx arg to every function.
#include "ppc_recomp_shared.h"
#include <cstdio>
#include <cstring>
#include <cstdint>
#include <cstdlib>
#include <atomic>
#include <condition_variable>
#include <algorithm>
#include <chrono>
#include <mutex>
#include <unordered_map>
#include <vector>
#include "win_compat.h"
#include <file.h>
#include <image.h>
// L3 (dll_packaging_plan §5 L3 / §1.3 / §3.4 / §3.6): every module-specific constant this
// host layer used to spell out — the game module's basename, entry ordinal, image/code ranges,
// _xstart, and the six load-bearing guest .data addresses — now lives in ONE descriptor.
// Relative path on purpose: no build script has to gain an -I for it.
#include "../../host/futari_module_desc.h"
extern "C" void rt_indirect_call(PPCContext& ctx, uint8_t* base, uint32_t target);

// ============================================================================================
// L4/E6 — THE FOUR GLOBALS THAT CROSS THE MODULE LINE, AND WHY EACH IS A POINTER IN THE DLL
// ============================================================================================
// A `static`/`extern` global compiled into BOTH images is TWO objects, silently.  The §1.3
// bind-struct ABI can only express functions and pointers, so every datum shared between the
// host exe and a module DLL has to be host-owned and reached through the bound FutariHostAbi.
// The macro trick below keeps every USE SITE in merged_game.cpp / the decomp tree byte-for-byte
// unchanged: inside a DLL the name expands to a deref of the bound pointer, everywhere else it
// is the plain global it always was.
//
// The pointers themselves are DEFINED in the generated <moddir>/module_shim.cpp and assigned
// inside FutariModuleBind(), which the host calls immediately after LoadLibrary and BEFORE any
// guest code, any table registration, or any DllMain(PROCESS_ATTACH) — so no DLL code can read
// a null one.  (The DLL's own C++ static initialisers run earlier, at LoadLibrary; none of them
// touch these four — audited, l4l5_combined_notes.md §5.)
//
//   g_import_calls   host: out_reco/stubs.cpp        DLL: reads/increments
//   g_rt_startline   host: shell/gen/stubs.cpp       DLL: reads (P1 START LEVEL, rapid-fire)
//   g_rt_romactive   ★ MOVED to merged_bridge.cpp at L4 (was merged_game.cpp) — the DLL WRITES
//                    it and vk_render.cpp / shell/gen/rt.cpp / merged_shell.cpp all READ it, so
//                    a per-DLL copy would have left rt_rom_render() and the pillarbox gate
//                    permanently false with no link error.  vk_render's __attribute__((weak))
//                    definition made that split LINK CLEANLY — the exact silent class this
//                    header exists to kill.
//   g_rt_realstage   ★ same move, same reason (DLL writes, vk_render reads).
// The declarations/macros themselves live in ONE place, shared with every other DLL-side TU
// (decomp/game/crt_hooks.cpp was the second and forced the extraction):
#include "../../host/futari_dll_globals.h"

static inline void rt_heapdump(uint8_t* base, const char* tag) {
    fprintf(stderr, "[heap] %-14s g887AD65C=%08X g887AD5D4=%08X root821F85A0=%08X\n",
        tag, PPC_LOAD_U32(0x887AD65C), PPC_LOAD_U32(0x887AD5D4), PPC_LOAD_U32(0x821F85A0));
    fflush(stderr);
}

// The resident game module: handle = image base (x360 convention), GameEntry = export ord 1.
// L3: GAME_ENTRY_ORD1_VAL / GAME_MODULE_BASENAME_STR are RETIRED; the values are descriptor
// fields (entry_ord1 / module_basename) and merged_bridge.cpp #error's if either -D comes back.
// ---- GUEST .data ADDRESS PARAMETERIZATION (sibling-module builds) ----
// ★ L3/E4: ALL SIX macros below are now descriptor reads. GA_DSHIFT no longer reaches this
// header — build_win_abn.sh passes -DGA_DSHIFT only to render/vk_render.cpp, the single
// remaining un-descriptorised consumer. PROVEN by recompiling this TU without the flag and
// diffing -S (_tmpscripts/l3_baseline/s4f_nodshift_probe). The #ifndef block survives ONLY
// because _tmpscripts/abn_apply_data_macros.py anchors its insertion on it; it is inert.
// Historical note, still true of the LAYOUT: reco_abnormal (Ver 1.5 HI) has the SAME guest
// .data base but a 0x60-longer section — every global from 0x88351830 to the .data end sits at
// nor_addr + 0x60 (13756 code-side deltas; _tmpscripts/abn_recomp_notes.md S2c). That law now
// lives in host/futari_module_desc.h and is static_assert'ed there. Only the load-bearing
// addresses below are parameterized; the select-FSM 0x884D67xx / scene-FSM 0x884D66xx clusters
// are NOT (whole-cluster sweep still pending — _tmpscripts/abn_hooks_revive_notes.md).
// Addresses in the genuinely-differing .data region 0x88250767..0x88351830 (0x88252504/8,
// 0x88252560) must NEVER be shifted by rule, which is why they are not descriptor fields.
#ifndef GA_DSHIFT
#define GA_DSHIFT 0u   /* inert since L3 — see above */
#endif
// GA_FIELD_ACTIVE  gameplay-field-active flag: present routing / pillarbox / compose + clear gating (vk_render), romactive clear (stubs.cpp XexUnloadImage). No sibling field is referenced anywhere.
#define GA_FIELD_ACTIVE  (futari_desc()->addrs.field_active)   // L3: was (0x885C1A20u + GA_DSHIFT)
// GA_GM_FRAME_GATE game-main per-frame gate flag; the ONLY clearer is the sub_88168C80 hook (abn twin sub_88168C88) and RT_GATEADV reads it.
#define GA_GM_FRAME_GATE (futari_desc()->addrs.gm_frame_gate)   // L3: was (0x887AC958u + GA_DSHIFT)
// GA_ASSET_COMMIT  asset-commit flag byte; RT_LOADDONE WRITES bit 0x02 here — a wrong-address write is the most dangerous class.
#define GA_ASSET_COMMIT  (futari_desc()->addrs.asset_commit)   // L3: was (0x887AC973u + GA_DSHIFT)
// GA_MB_RELOAD     RETURN-TO-MENU / reload mailbox; parsed out of [msglog] and rt.cpp handback logs by the boot gates.
#define GA_MB_RELOAD     (futari_desc()->addrs.mb_reload)   // L3: was (0x887AD58Cu + GA_DSHIFT)
// GA_MB_CREDITED   credited-flow byte; parsed out of [msglog] (the "58c->2 arms credited" probe).
#define GA_MB_CREDITED   (futari_desc()->addrs.mb_credited)   // L3: was (0x887AD547u + GA_DSHIFT)
// GA_MB_MODE64     mode64 mailbox; msg-12 arm target, read by [msglog] and rt.cpp.
#define GA_MB_MODE64     (futari_desc()->addrs.mb_mode64)   // L3: was (0x887AD584u + GA_DSHIFT)
// ---- end guest .data parameterization ----
// ---- RECO-LAYOUT GUARD for the sub_88 hooks (Black Label step 3, 2026-10-31) ----
// FUTARI_RECO_DATA is 1 when this module's .data is laid out like reco_normal's (reco_normal itself and its
// +0x60 twin reco_abnormal, where every literal is dshift-correct) and 0 for a DIFFERENT GAME BUILD
// (kiniro_normal, modeIdx 4). merged_game.cpp carries ~460 reco_normal .data literals. Under the flat 4 GB
// guest arena a READ of a wrong address is harmless (an instrument logs garbage), but a WRITE corrupts the
// live module's own .data. The step-3 audit (docs/PLAN_kiniro_bringup.md "Step 3") found every literal
// STORE and literal-driven register/call override inside a hook that kiniro_symbol_map.h INSTALLS sits
// behind one of eight RT_ levers; each of those is now also gated on rt_kgate("<lever>"), which is a
// constant `true` on the reco pair (byte-identical codegen) and on module 4 refuses once per lever with a
// [kgate] line so the harvest log shows what was withheld. Hooks the map DROPS (sub_X_KDROP) are never
// installed, so their literal stores cannot run. The RT_STARTWIRE store goes through futari_desc()->dshift
// (the descriptor's candidate), not a literal, and stays live on purpose.
#define FUTARI_RECO_DATA (FUTARI_MODULE == 0 || FUTARI_MODULE == 1)
static inline bool rt_kgate(const char* lever){
#if FUTARI_RECO_DATA
  (void)lever; return true;
#else
  static std::atomic<int> shown{0};
  if(shown.fetch_add(1) < 64)
    std::fprintf(stderr,"[kgate] %s REFUSED on %s (modeIdx %u): it writes through reco_normal .data literals\n",
                 lever, futari_desc()->module_basename, (unsigned)futari_desc()->hosted_mode_idx);
  return false;
#endif
}
// ---- [jankstate] / [janksum]: module -> host diagnostic calls (L3 stage 1) ----
// The three g_js_* counters that L2 had to make `inline` variables are shell-PRIVATE statics
// again (merged_shell.cpp).  The game half's per-frame [jank] block calls these two instead of
// reading them, so nothing crosses the module line but a function call — the one shape the
// §1.3 FutariHostAbi can express.  See l2_split_notes §6.1.
extern "C" void rt_jankstate_tick(long long n, long long d_us);
extern "C" void rt_jankstate_summary(long long frames, long long slow, long long maxd, long long meand);

// ---- cross-TU declarations for definitions that stayed behind in one .cpp ----
// g_rt_romactive / g_rt_realstage are declared by host/futari_dll_globals.h (included above) —
// plain externs in an exe build, macros over the bound host pointers in a DLL build.
extern "C" volatile int g_game_unloaded;     // DEFINED in merged_bridge.cpp (read by XexLoadImage)
