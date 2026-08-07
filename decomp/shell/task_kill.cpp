// decomp/shell/task_kill.cpp — port-side adapter for 0x820619F0 (Task_Kill).
//
// THE SEAM: shell/gen/ppc_recomp.0.cpp:4184 defines PPC_FUNC_IMPL(__imp__sub_820619F0) with
// a WEAK alias PPC_WEAK_FUNC(sub_820619F0). This strong PPC_FUNC(sub_820619F0) beats the weak
// alias, and obj_win/decomp_*.o is linked FIRST (build_win.sh), so this body wins and the
// generated one becomes dead weight. ROLLBACK = delete this file (the .inl stays; matchlab
// keeps verifying it) or drop obj_win/decomp_task_kill.o from the link line.
//
// Nothing is hooked at this address in out_reco/merged/merged_shell.cpp, so the plain
// PPC_FUNC seam is correct here — the __imp__ shadowed-hook form (PILOT_NOTES §2) is only
// needed when an instrument already owns the strong symbol.
//
// Behaviour vs the generated body: identical memory effect. The generated body additionally
// leaves ctx.r11 = 2 (a callee-clobbered volatile); this does not, which is strictly more
// conservative. Safe here because the function is a LEAF — it makes no calls, so the C1
// register-file rule (callee-visible registers at call sites are part of the contract) has
// no call boundary to apply to, and no correct caller reads a callee-clobbered volatile.

#include "ppc_recomp_shared.h"
#include "task_kill.inl"


PPC_FUNC(sub_820619F0)
{
    PPC_FUNC_PROLOGUE();
    Task_Kill(reinterpret_cast<Task*>(base + ctx.r3.u32));
}
