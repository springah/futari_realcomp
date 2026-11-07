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
