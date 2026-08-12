// decomp/game/mem_util.cpp — the game module's shared byte-copy primitive.
//
// WHAT THIS REPLACES.  0x88072260 is the guest memcpy(dst=r3, src=r4, len=r5) — a hand-tuned,
// alignment-cased PPC copy (8-byte bulk loop + byte head/tail, with dcbt/dcbtst prefetch). It is
// the single most-referenced leaf in the module: 224 call sites (registry role "Shared memcpy
// utility (224 refs)", ATLAS_INDEX §1 SC§2[RT]/AP§2[RT]). ~200 lines of ctx-shaped goo collapse
// into the four lines below — the "largest LOC reduction per effort" the plan (§4) prizes, applied
// to a leaf instead of a clone family.
//
// Ground truth: out_reco/ppc_recomp.0.cpp:6858-70xx (register-exact recomp, entry 0x88072260 →
// blr). The routine reads r3=dst, r4=src, r5=len, copies FORWARD (pointers advance low→high with
// ldu/stdu/lbzu/stbu), and returns the ORIGINAL dst in r3 (std r3,-8(r1) at entry; ld r3,-8(r1)
// before every blr). Standard memcpy contract: byte-for-byte copy of len bytes, return dst.
//
// ── SEAM (PILOT_NOTES §2 — SHADOWED-HOOK form) ─────────────────────────────────────────────────
// out_reco/merged/merged_game.cpp:3531 already defines a STRONG PPC_FUNC(sub_88072260): the
// [slot]/[mcpy] RT_MEMCPYLOG watch instrument, which tail-calls __imp__sub_88072260. A second
// strong sub_88072260 would collide with it (first-def-wins kills one of the two). So this body
// takes the __imp__sub_88072260 symbol instead: the instrument keeps its strong definition and
// this translation displaces the GENERATED __imp__ body underneath it. Chain after link:
//   caller → rt_indirect → sub_88072260 (merged_game watch) → __imp__sub_88072260 = THIS BODY.
// decomp objects link FIRST (build_win.sh globs decomp/game/*.cpp), so this wins over the
// generated __imp__ in game_ppc_recomp.0.o (which stays as dead bytes = the rollback path).
// ROLLBACK = delete this file, or drop obj_win/decomp_mem_util.o from the link line.
//
// ── Deliberately-accepted residual (all invisible to every correct caller) ─────────────────────
// This is a LEAF (no bl / bctrl), so the C1 register-file rule has no call boundary to honour:
// the generated body's volatile leftovers (r4/r5/r6-r8/ctr/cr scratch) are not reproduced, exactly
// as decomp/shell/task_kill.cpp accepts. r3 is left = dst (the return value), which the [slot]
// watch does not read at exit but real callers do. The forward byte copy is bit-identical to the
// generated forward copy for every NON-overlapping call (the memcpy contract) and for the
// memmove-safe dst<src overlap direction; it does not bit-reproduce the generated body's 8-byte
// chunk ordering for the forbidden dst>src self-overlap case (undefined for a forward memcpy in
// both bodies) — same residual class as task_kill's volatile leftovers.

#include "ppc_recomp_shared.h"   // ppc_config.h (base 0x88000000) + ppc_context.h (-I out_reco)

// 0x88072260 — guest memcpy(dst=r3, src=r4, len=r5) -> r3=dst. Leaf.
PPC_FUNC_IMPL(__imp__sub_88072260)
{
    PPC_FUNC_PROLOGUE();
    const uint32_t dst = ctx.r3.u32;   // also the return value, left in r3 untouched
    const uint32_t src = ctx.r4.u32;
    const uint32_t len = ctx.r5.u32;

    for (uint32_t i = 0; i < len; ++i)
        PPC_STORE_U8(dst + i, PPC_LOAD_U8(src + i));
}
