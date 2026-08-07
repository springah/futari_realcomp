#pragma once
// module_registry.h — the combined exe's module lifecycle: load / bind / activate / swap.
//
// L4+L5 of _tmpscripts/dll_packaging_plan.md.  Notes: _tmpscripts/l4l5_combined_notes.md.
// COMPILED ONLY INTO THE COMBINED EXE (-DFUTARI_COMBINED=1, build_win_dll.sh).  The two
// per-module exes (build_win.sh / _tmpscripts/build_win_abn.sh) never see this file — they are
// the beta1 fallback and must stay bit-for-bit the shape that passed their gates.
#include <stdint.h>
struct FutariModuleDesc;

extern "C" {

// The live module.  DEFINED here; READ by host/futari_module_desc.h's futari_desc() in a
// combined build.  Written exactly once per swap, on the guest thread inside XexLoadImage,
// after a release fence that publishes the function-table slots (plan §3.6 publication order).
extern const FutariModuleDesc* volatile g_futari_cur_desc;

// Bit N set => modeIdx N is servable by this process.  OR of every module DLL that BOUND
// successfully at boot — so a missing DLL greys its mode instead of wedging.  Consumed by the
// [modestub] L1/L2 layers through futari_mode_hosted()/futari_title_hosted().
extern uint32_t g_futari_hosted_mask;

// Load + bind every module DLL, then activate the boot module.  Called once from
// out_reco/harness.cpp main() where the eager PPCFuncMappings loop used to be — i.e. BEFORE the
// shell boots, so the guest table is populated at exactly the same point in the boot as in the
// per-module exes.  Boot module = RT_STARTMODULE (basename or modeIdx), default reco_normal.
// Returns 0 on success; nonzero means nothing can run and the caller must die loud.
int futari_registry_boot(uint8_t* base);

// Guest module path (e.g. "game:\media\Module\reco_abnormal.xex") -> the desc that serves it,
// or nullptr if this build does not host it (=> XexLoadImage keeps refusing with 0xC0000135).
const FutariModuleDesc* futari_registry_resolve_path(const char* guestPath);

// THE SWAP.  Returns 1 if `d` is now live, 0 on failure (caller must refuse the load).
// Idempotent: switching to the module that is already live is a no-op that returns 1.
// Preconditions the caller is responsible for: every guest GAME thread joined, called from the
// guest thread inside XexLoadImage before the hmodule is handed back.
int futari_registry_switch(const FutariModuleDesc* d, uint8_t* base);

// One line for the boot log / gate parsing: which modules bound, which is live.
const char* futari_registry_summary(void);

} // extern "C"
