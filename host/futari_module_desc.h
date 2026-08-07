#pragma once
// futari_module_desc.h — the ONE place that knows anything module-specific.
//
// L3 / E4+E5 of _tmpscripts/dll_packaging_plan.md (§1.3 bind-struct shape, §3.4 the GA_DSHIFT
// surface, §3.6 rt_indirect_call's three constants, §5 the L3 row).
//
// WHAT THIS IS TODAY (L3): a pair of `constexpr` descriptors compiled into the exe, one per
// recompiled module, with the build picking one at compile time via -DFUTARI_MODULE.  Because
// they are constexpr, every consumer folds to exactly the immediate it used before the
// refactor — L3 is provably behaviour-neutral (the -S gate in _tmpscripts/l3_gate.sh).
//
// WHAT IT BECAME (L4/E6, 2026-07-31): exactly what the paragraph below predicted.  In a
// COMBINED build (-DFUTARI_COMBINED=1, build_win_dll.sh) `futari_desc()` is a volatile load of
// `g_futari_cur_desc`, the pointer the host got back from the live module DLL's
// FutariModuleBind() export; in the two per-module exes it is still the constexpr fold, and in
// a module DLL it is that DLL's OWN constexpr descriptor (correct by construction — the DLL's
// guest addresses cannot be another module's).  Every consumer in this repo already reads
// through this accessor, so it was a one-line change here and nothing else.
// The struct also grew `mappings` / `mapping_count` — only a DLL can fill them, because
// PPCFuncMappings is the DLL's symbol.
//
// ORIGINAL L3 TEXT (kept because it is the reason the accessor exists):
// WHAT IT BECOMES (L4/E6): `futari_desc()` stops returning &g_futari_desc_<mod> and starts
// returning the pointer the host got back from the DLL's FutariModuleBind() export (plan §1.3),
// i.e. `std::atomic<const FutariModuleDesc*> g_cur` loaded relaxed.  EVERY consumer in this
// repo already reads through this accessor, so that is a one-line change here and nothing else.
// The struct then also grows `mappings` / `mapping_count` / `mode_idx_mask` — deliberately
// NOT added at L3, because nothing in the exe can populate them yet and a dead field is a
// wrong-value trap.
//
// THE RULE THIS FILE EXISTS TO ENFORCE: no host file may name a guest address, a module
// basename, a module code range or a module entry point directly.  A module whose layout
// differs then produces a MISSING-DESC-FIELD COMPILE ERROR instead of a silent wrong write —
// plan §3.4 calls that "the single biggest correctness win of the refactor".
#include <stdint.h>

#define FUTARI_MODULE_ABI 1

// ---- module selection (compile-time at L3; runtime at L4) -------------------------------
//   0 = reco_normal     (build_win.sh          -> futari_merged.exe)
//   1 = reco_abnormal   (build_win_abn.sh      -> futari_merged_v154hi.exe, Ver 1.5 HI)
// DEFAULT IS 0, i.e. a TU that forgets the flag gets reco_normal — the SAME default-to-normal
// fragility GA_DSHIFT had.  It is mitigated the same way: both build scripts pass the flag to
// every TU that includes this header (see their headers), and the two arms' descriptors differ
// in enough places that a missed flag shows up loudly in the -S gate.
#ifndef FUTARI_MODULE
#define FUTARI_MODULE 0
#endif

// ---- guest .data layout law for reco_abnormal ------------------------------------------
// reco_abnormal (Ver 1.5 HI) has the SAME guest .data base but a 0x60-longer section: every
// global from 0x88351830 to the .data end sits at nor_addr + 0x60 (13756 code-side +0x60
// displacement deltas; _tmpscripts/abn_recomp_notes.md S2c).  This replaces the -DGA_DSHIFT=0x60u
// that used to be sprayed onto four TUs.  Addresses in the genuinely-differing .data region
// 0x88250767..0x88351830 (0x88252504/8, 0x88252560) must NEVER be shifted by rule — they are
// not in this struct and must not be added to it without a per-module measurement.
#define FUTARI_DSHIFT_RECO_NORMAL   0u
#define FUTARI_DSHIFT_RECO_ABNORMAL 0x60u

// ---- host SHELL constants: NOT per-module, and never will be ---------------------------
// The shell (default.xex) is the host; it is never swapped.  rt_indirect_call's shell branch
// and rt_thread_main's shell entry-bounds check use these and stay hardcoded forever (plan
// §3.6 (iii)).  Named here only so no host file has to spell them out twice.
#define FUTARI_SHELL_CODE_BASE   0x82060000u
#define FUTARI_SHELL_CODE_SIZE   0x175BF4u
#define FUTARI_SHELL_TABLE_BASE  0x822B0000ull   // = shell image base 0x82000000 + image size 0x2B0000

// ---- the descriptor --------------------------------------------------------------------
// Forward declaration only: this header is included by TUs (render/vk_render.cpp) that have no
// business seeing ppc_context.h.  The definition, when it arrives, is compatible.
struct PPCFuncMapping;

struct FutariModuleAddrs {          // plan §1.3 FutariModuleAddrs, the six -D-parameterised ones
    uint32_t field_active;          // reco_normal 0x885C1A20  (was GA_FIELD_ACTIVE)
    uint32_t gm_frame_gate;         //             0x887AC958  (was GA_GM_FRAME_GATE)
    uint32_t asset_commit;          //             0x887AC973  (was GA_ASSET_COMMIT)
    uint32_t mb_reload;             //             0x887AD58C  (was GA_MB_RELOAD)
    uint32_t mb_credited;           //             0x887AD547  (was GA_MB_CREDITED)
    uint32_t mb_mode64;             //             0x887AD584  (was GA_MB_MODE64)
};

struct FutariModuleDesc {
    uint32_t abi_version;           // == FUTARI_MODULE_ABI
    uint32_t struct_size;           // sizeof(FutariModuleDesc)
    const char* module_basename;    // "reco_normal" — guest path match AND "<name>.xex" re-image
    uint32_t image_base;            // 0x88000000.  ALSO the hmodule handed back by XexLoadImage
    uint32_t image_size;            // 0x7B0000
    uint32_t code_base;             // 0x88070000    } rt_indirect_call's GAME branch and
    uint32_t code_size;             // 0x1DEEB0/B8   } rt_thread_main's entry-bounds check
    uint32_t table_base;            // 0x887B0000 = image_base + image_size (host func-ptr window)
    uint32_t xstart;                // 0x88070588 — module entry, the DllMain-style dispatcher
    uint32_t entry_ord1;            // export ordinal 1 = GameEntry
    // hosted_mode_idx — the SHELL-side game-select index this build can actually serve.
    // The shell folds the game-select into modeIdx = titleIdx*2 + sub (sub: the arcade_front
    // ARCADE/XBOX-360 answer) in FUN_821B7CC0 and hands it to FUN_821C3F38(mem, modeIdx);
    // FUN_821C3B90 then picks one of EIGHT per-module loaders from it.  Map (register-true,
    // _tmpscripts/modules_shift_census.md §1): 0 reco_normal / 1 reco_abnormal / 2 palm_normal /
    // 3 palm_abnormal / 4 kiniro_normal / 5 kiniro_abnormal / 6 hirow_normal / 7 hirow_abnormal.
    // This is the L4 `mode_idx_mask` slot promised in the header comment, landed early (and as a
    // plain index, not a mask) because beta1's mode STUBS need it: the host must know which
    // menu rows this exe can honour.  Consumer: out_reco/merged/merged_shell.cpp [modestub]
    // L1/L2 (design: _tmpscripts/mode_stub_design.md).
    uint32_t hosted_mode_idx;       // 0 = reco_normal (ARCADE), 1 = reco_abnormal (XBOX 360)
    uint32_t dshift;                // audit only; `addrs` below are already absolute
    FutariModuleAddrs addrs;
    // ---- L4/E6 additions.  NULL/0 in the constexpr copies compiled into any EXE; filled by
    // the DLL's FutariModuleBind() in its own mutable copy, because PPCFuncMappings is the
    // DLL's symbol and no exe can name it once the generated tree has left.
    const PPCFuncMapping* mappings; // sentinel-terminated {0,nullptr}
    uint32_t mapping_count;         // precomputed at bind (excludes the sentinel)
};

// The six addresses, written ONCE against the reco_normal reference layout and shifted by the
// module's own dshift — so a sibling module cannot acquire a typo'd address, only a wrong shift.
#define FUTARI_ADDRS_FROM_RECO_NORMAL(D) { \
    0x885C1A20u + (D),   /* field_active  */ \
    0x887AC958u + (D),   /* gm_frame_gate */ \
    0x887AC973u + (D),   /* asset_commit  */ \
    0x887AD58Cu + (D),   /* mb_reload     */ \
    0x887AD547u + (D),   /* mb_credited   */ \
    0x887AD584u + (D) }  /* mb_mode64     */

// reco_normal — out_reco/, ppc_config.h PPC_CODE_SIZE 0x1DEEB0
constexpr FutariModuleDesc g_futari_desc_reco_normal = {
    FUTARI_MODULE_ABI, (uint32_t)sizeof(FutariModuleDesc),
    "reco_normal",
    0x88000000u, 0x7B0000u,
    0x88070000u, 0x1DEEB0u,
    0x887B0000u,
    0x88070588u,
    0x8824E698u,
    0u,                             // hosted_mode_idx: title 0 (Ver 1.5) / sub 0 (ARCADE)
    FUTARI_DSHIFT_RECO_NORMAL,
    FUTARI_ADDRS_FROM_RECO_NORMAL(FUTARI_DSHIFT_RECO_NORMAL),
    nullptr, 0u                     // mappings/mapping_count: DLL-only (see the field comment)
};

// reco_abnormal — out_reco_abn/, ppc_config.h PPC_CODE_SIZE 0x1DEEB8 (8 bytes LONGER than
// reco_normal: the pre-L3 hardcoded 0x1DEEB0 bound in rt_indirect_call under-covered the abn
// code range by 8 bytes and was only saved by the duplicate PPC_CODE_* branch ahead of it).
constexpr FutariModuleDesc g_futari_desc_reco_abnormal = {
    FUTARI_MODULE_ABI, (uint32_t)sizeof(FutariModuleDesc),
    "reco_abnormal",
    0x88000000u, 0x7B0000u,
    0x88070000u, 0x1DEEB8u,
    0x887B0000u,
    0x88070588u,
    0x8824E6A0u,
    1u,                             // hosted_mode_idx: title 0 (Ver 1.5) / sub 1 (XBOX 360 MODE)
    FUTARI_DSHIFT_RECO_ABNORMAL,
    FUTARI_ADDRS_FROM_RECO_NORMAL(FUTARI_DSHIFT_RECO_ABNORMAL),
    nullptr, 0u                     // mappings/mapping_count: DLL-only (see the field comment)
};

// The +0x60 law, asserted rather than trusted.
static_assert(g_futari_desc_reco_abnormal.addrs.field_active  == g_futari_desc_reco_normal.addrs.field_active  + 0x60u, "abn dshift");
static_assert(g_futari_desc_reco_abnormal.addrs.gm_frame_gate == g_futari_desc_reco_normal.addrs.gm_frame_gate + 0x60u, "abn dshift");
static_assert(g_futari_desc_reco_abnormal.addrs.asset_commit  == g_futari_desc_reco_normal.addrs.asset_commit  + 0x60u, "abn dshift");
static_assert(g_futari_desc_reco_abnormal.addrs.mb_reload     == g_futari_desc_reco_normal.addrs.mb_reload     + 0x60u, "abn dshift");
static_assert(g_futari_desc_reco_abnormal.addrs.mb_credited   == g_futari_desc_reco_normal.addrs.mb_credited   + 0x60u, "abn dshift");
static_assert(g_futari_desc_reco_abnormal.addrs.mb_mode64     == g_futari_desc_reco_normal.addrs.mb_mode64     + 0x60u, "abn dshift");
// The table window is where the recompiler's host-function pointers live (ppc_context.h:113:
// base + PPC_IMAGE_BASE + PPC_IMAGE_SIZE + (guest - PPC_CODE_BASE)*2), so it must sit exactly
// at the end of the guest image for both modules.
static_assert(g_futari_desc_reco_normal.table_base   == g_futari_desc_reco_normal.image_base   + g_futari_desc_reco_normal.image_size,   "table window");
static_assert(g_futari_desc_reco_abnormal.table_base == g_futari_desc_reco_abnormal.image_base + g_futari_desc_reco_abnormal.image_size, "table window");
// The two exes must host DIFFERENT modes (that is the whole point of shipping two), and both are
// the Ver 1.5 title (row 0) — an ARCADE/XBOX-360 pair, i.e. the SAME titleIdx and different sub.
// If a third module is ever added, the second assert is the one that has to be relaxed, and the
// [modestub] L1 loop in merged_shell.cpp is the code that has to learn about it.
static_assert(g_futari_desc_reco_normal.hosted_mode_idx != g_futari_desc_reco_abnormal.hosted_mode_idx, "hosted mode collision");
static_assert(g_futari_desc_reco_normal.hosted_mode_idx / 2u == g_futari_desc_reco_abnormal.hosted_mode_idx / 2u, "both arms are title 0 (Ver 1.5)");
static_assert(g_futari_desc_reco_normal.hosted_mode_idx < 8u && g_futari_desc_reco_abnormal.hosted_mode_idx < 8u, "modeIdx is 0..7");

// ---- THE ACCESSOR.  Every module-specific value in the host goes through this. -----------
// THREE BUILD SHAPES, ONE SIGNATURE:
//
//   (a) per-module exe  (build_win.sh / build_win_abn.sh — the beta1 FALLBACK, unchanged)
//       constexpr fold of the -DFUTARI_MODULE arm.  Byte-identical codegen to L3; the l3_gate
//       -S digests still apply.
//   (b) module DLL      (-DFUTARI_IN_MODULE_DLL=1)
//       ALSO the constexpr fold, and that is not a compromise — a DLL contains exactly one
//       module's recompiled tree, so its guest addresses can never be another module's.  It is
//       the strongest possible form of the "no host file may name a guest address" rule.
//   (c) combined-exe HOST (-DFUTARI_COMBINED=1, build_win_dll.sh)
//       a volatile load of the pointer the live DLL's FutariModuleBind() returned.  This is the
//       ONLY shape where the value can change at runtime, and it changes exactly once per
//       mode swap, inside XexLoadImage, with every guest game thread already joined.
//
// Why `volatile` and not std::atomic: this header is included by TUs that have no <atomic>
// (and by C-ish generated code), the datum is a single pointer (naturally atomic on x86-64 and
// on aarch64), and the ONE ordering requirement — table slots visible before the publish — is
// met by an explicit release fence in module_registry.cpp, not by the load.
#if defined(FUTARI_COMBINED) && !defined(FUTARI_IN_MODULE_DLL)
extern "C" { extern const FutariModuleDesc* volatile g_futari_cur_desc; }   // module_registry.cpp
inline const FutariModuleDesc* futari_desc() { return g_futari_cur_desc; }
#else
constexpr const FutariModuleDesc* futari_desc() {
#if FUTARI_MODULE == 1
    return &g_futari_desc_reco_abnormal;
#else
    return &g_futari_desc_reco_normal;
#endif
}
#endif

// ---- WHICH GAME-SELECT COORDINATES THIS BUILD CAN SERVE (beta1 mode stubs) ----------------
// L4 promoted this from a single index to the MASK the header always planned (plan §1.3
// `mode_idx_mask`), because the combined exe hosts a SET {0,1} and the stub layers must grey
// only true foreigners.  Bit N set => this BUILD can honour modeIdx N.
//
//   per-module exe / DLL : 1u << hosted_mode_idx      (0b0000_0001 or 0b0000_0010)
//   combined exe         : the OR over every module DLL that bound successfully at boot,
//                          published by module_registry.cpp.  If one DLL is missing from the
//                          install, its bit is CLEAR and that mode greys out — the stub layers
//                          degrade to exactly the per-module-exe behaviour instead of wedging.
//
// A TITLE row is servable if EITHER of its two modeIdx (row*2 + {0,1}) is servable, because L1
// greys whole rows and L2 handles the ARCADE/XBOX-360 sub-choice inside a row.
#if defined(FUTARI_COMBINED) && !defined(FUTARI_IN_MODULE_DLL)
extern "C" { extern uint32_t g_futari_hosted_mask; }                        // module_registry.cpp
inline uint32_t futari_hosted_mask() { return g_futari_hosted_mask; }
#else
inline uint32_t futari_hosted_mask() { return 1u << futari_desc()->hosted_mode_idx; }
#endif
inline bool futari_mode_hosted(uint32_t modeIdx) {
    return modeIdx < 8u && (futari_hosted_mask() & (1u << modeIdx)) != 0u;
}
inline bool futari_title_hosted(uint32_t titleIdx) {
    return titleIdx < 4u && (futari_hosted_mask() & (3u << (titleIdx * 2u))) != 0u;
}

// Legacy spellings, kept so a stale call site is a value, not a compile error.  They mean "the
// module that is live RIGHT NOW", which is what every log line wants; the STUB LAYERS must use
// futari_mode_hosted()/futari_title_hosted() instead — on the combined exe a single index is
// the wrong question.
#define FUTARI_MODE_HOSTED   (futari_desc()->hosted_mode_idx)
#define FUTARI_TITLE_HOSTED  (futari_desc()->hosted_mode_idx >> 1)
