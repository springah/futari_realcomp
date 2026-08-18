#pragma once
// Checked indirect-call shim (hand-authored, survives regen via keep_reco + build_reco.sh -include).
// Replaces ppc_context.h's raw PPC_CALL_INDIRECT_FUNC: logs + skips calls to unmapped/oob
// guest addresses instead of jumping through a null host pointer (SIGSEGV at nil).
//
// IMPORTANT (cross-module / futari_merged build): this file is force-included via
// `-include out_reco/rt_indirect.h` on BOTH game and shell translation units. It must
// NOT `#include "ppc_recomp_shared.h"` here: that is a quote-include, and quote-includes
// resolve relative to the CURRENT file's own directory before the `-I` search path is
// consulted -- so from out_reco/rt_indirect.h it would always pull in
// out_reco/ppc_recomp_shared.h (the GAME's header), even when force-included ahead of a
// shell/gen/*.cpp TU compiled with -I shell/gen. That previously let the shell tree's own
// ppc_recomp_shared.h (which independently hardcodes its own legacy
// `#define PPC_CALL_INDIRECT_FUNC(x) rt_indirect(...)` shim) win when the TU's real
// `#include "ppc_recomp_shared.h"` ran later and re-clobbered our macro. Fix: don't
// include anything here -- just forward-declare PPCContext (fine for a reference/pointer
// parameter in an extern "C" decl) and define the macro. This file is included before
// ppc_context.h defines PPCFunc/PPCContext, and after our define, the TU's OWN
// `#include "ppc_recomp_shared.h"` runs -- which for game TUs re-`#undef`s nothing (game's
// header has no such macro) and for shell TUs DOES re-`#define` PPC_CALL_INDIRECT_FUNC to
// its legacy `rt_indirect(...)` shim. We handle that case by also providing a same-signature
// `rt_indirect()` forwarding function (see rt.cpp) so shell TUs link cleanly either way.
#include <cstdint>
struct PPCContext;
#undef PPC_CALL_INDIRECT_FUNC
extern "C" void rt_indirect_call(PPCContext& ctx, uint8_t* base, uint32_t target);
#define PPC_CALL_INDIRECT_FUNC(x) rt_indirect_call(ctx, base, (uint32_t)(x))

// ══════════════════════════════════════════════════════════════════════════════════════════════
// ★★★ r23-w11 DRIVER LANE — [wwatch]: THE PROGRAM-WIDE STORE WATCH ON ONE GUEST WORD.
//
// WHY THIS EXISTS, AND WHY IT IS A NEW AXIS RATHER THAN A SIXTH SWEEP.
//   C2 (= PlayerSlot[0]+28 = W+1476 = guest 0x884D6D04) climbs 0 -> 9 on every drive and NOBODY
//   HAS NAMED THE INCREMENTER.  Five static sweeps (EA / displacement / indexed / add-form /
//   over-approximating taint) and w10's 15-body [wwrite] differencing watch all failed, for two
//   MEASURED reasons:
//     (1) the writer reaches the cell through a pointer CACHED IN ANOTHER OBJECT, so no static
//         base-chain resolves to the record;  and
//     (2) w10's own refinement of the differencing law -- "a differencing watch is blind to a
//         write of the value that was already there" -- means a body-scoped watch can tick and
//         report nothing.
//   Both failures are failures of ADDRESSING and of ROSTER.  This instrument has neither: it does
//   not care how the effective address was formed, and it puts NO roster on the stand at all.  It
//   intercepts the store macro itself, so EVERY store executed by EVERY body in the game module
//   is tested against the one word.  The writer cannot hide from it by being unlisted.
//
// HOW THE WRITER IS NAMED.  The watch function is __attribute__((noinline)), so
// __builtin_return_address(0) inside it is a HOST address lying inside whichever generated body
// executed the store.  That host address is reported as an offset from a reference symbol in the
// same DLL, and futari_game_normal.map turns the offset back into a symbol.  No guest lr is used
// and `ctx` is deliberately NOT referenced, so the macro is safe in every expansion context.
//
// ★ POSITIVE CONTROL, BUILT INTO THE SAME DRIVE AND INDEPENDENT OF THE HYPOTHESIS (LAWS: an
//   instrument lies until positive-controlled; a positive control must not co-vary with the
//   thing under test).  sub_88133B68 PlayerSlots_Reset memsets the record through the library
//   helper sub_88073BD0, whose body was READ (ppc_recomp.0.cpp:11690) and stores via
//   PPC_STORE_U8 + unrolled PPC_STORE_U32 -- NO dcbz anywhere in the tree.  So at session start
//   this watch MUST fire and MUST symbolize to the memset helper, writing 0 over the 0x5A5A5A5A
//   poison that every banked [wgate] board records as C2's first value.  That control is about
//   the ZEROER; the hypothesis is about the INCREMENTER.  If the control does not fire, the
//   instrument is broken and NOTHING on the drive may be read -- including a zero.
//
// ⚠ COVERAGE LIMITS, STATED IN ADVANCE SO A ZERO CANNOT BE OVER-READ:
//     * only the GAME module is rebuilt with this flag; a store executed by the shell binary
//       (futari_combined.exe, not rebuilt) is INVISIBLE;
//     * a store through a host-side memcpy/DMA path that bypasses the PPC store macros is
//       INVISIBLE (grep confirmed no dcbz in the generated tree, which was the main such risk);
//     * "no writer seen" therefore means "no writer among game-module PPC stores", never
//       "no writer".
//
// DEFAULT-OFF AT COMPILE TIME.  Without -DFUTARI_W11_WWATCH not one token below is emitted and
// the build is byte-identical to the normal one, so this file stays safe for every other lane.
// PURELY ADDITIVE: nothing above this line was changed.
// ══════════════════════════════════════════════════════════════════════════════════════════════
#ifdef FUTARI_W11_WWATCH
extern "C" void rt_w11_wwatch(uint32_t ea, uint32_t width, uint32_t val, const void* ra);
// the watched word: PlayerSlot[0]+28 == W+1476 == C2.  Half-open [LO,HI).
#define FUTARI_W11_WLO 0x884D6D04u
#define FUTARI_W11_WHI 0x884D6D08u
// overlap test: any store of `sz` bytes at `e` that touches the word
#define FUTARI_W11_HIT(e, sz) ((e) < FUTARI_W11_WHI && (e) + (sz) > FUTARI_W11_WLO)
#define FUTARI_W11_FIRE(e, sz, v) \
    rt_w11_wwatch((e), (sz), (uint32_t)(v), __builtin_return_address(0))

#undef PPC_STORE_U8
#define PPC_STORE_U8(x, y) do { \
        uint32_t _w_e = (uint32_t)(x); uint8_t _w_v = (uint8_t)(y); \
        if (__builtin_expect(FUTARI_W11_HIT(_w_e, 1u), 0)) FUTARI_W11_FIRE(_w_e, 1u, _w_v); \
        *(volatile uint8_t*)(base + _w_e) = _w_v; } while (0)

#undef PPC_STORE_U16
#define PPC_STORE_U16(x, y) do { \
        uint32_t _w_e = (uint32_t)(x); uint16_t _w_v = (uint16_t)(y); \
        if (__builtin_expect(FUTARI_W11_HIT(_w_e, 2u), 0)) FUTARI_W11_FIRE(_w_e, 2u, _w_v); \
        *(volatile uint16_t*)(base + _w_e) = __builtin_bswap16(_w_v); } while (0)

#undef PPC_STORE_U32
#define PPC_STORE_U32(x, y) do { \
        uint32_t _w_e = (uint32_t)(x); uint32_t _w_v = (uint32_t)(y); \
        if (__builtin_expect(FUTARI_W11_HIT(_w_e, 4u), 0)) FUTARI_W11_FIRE(_w_e, 4u, _w_v); \
        *(volatile uint32_t*)(base + _w_e) = __builtin_bswap32(_w_v); } while (0)

#undef PPC_STORE_U64
#define PPC_STORE_U64(x, y) do { \
        uint32_t _w_e = (uint32_t)(x); uint64_t _w_v = (uint64_t)(y); \
        if (__builtin_expect(FUTARI_W11_HIT(_w_e, 8u), 0)) FUTARI_W11_FIRE(_w_e, 8u, (uint32_t)(_w_v >> 32)); \
        *(volatile uint64_t*)(base + _w_e) = __builtin_bswap64(_w_v); } while (0)
#endif  // FUTARI_W11_WWATCH
