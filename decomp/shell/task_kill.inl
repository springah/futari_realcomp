// task_kill.inl — 0x820619F0, the self-kill action: *(task + 8) = 2.
//
// ONE BODY, TWO COMPILATIONS. This file is the single source of truth for the function:
//
//   * matchlab/src/shell_820619F0_TaskKill.cpp includes it and is compiled by the ORIGINAL
//     XDK 9328 PowerPC compiler, where ppcmatch proves it is byte-identical to the guest
//     bytes at 0x820619F0.
//   * decomp/shell/task_kill.cpp includes it and is compiled by the host toolchain into the
//     port, wrapped in a PPC_FUNC adapter that displaces the recompiled body.
//
// So the code that RUNS in the port is provably the same program the original was. That is
// the whole point of the ASM-EXACT rung; nothing else in decomp/ has this property yet.
//
// Guest-memory fields use be<T> (decomp/include/guest_be.h): the identity on big-endian PPC —
// verified, the emitted instructions are unchanged — and byte-swapping on the host, matching
// PPC_LOAD_*/PPC_STORE_* in out_reco/ppc_context.h.
//
// Role: 70 references, all address-taken — this is registered as a delegate and invoked
// through the indirect-call path, never called directly (plan §8.1 rank 1 / §9.1 #3).

#ifndef DECOMP_SHELL_TASK_KILL_INL
#define DECOMP_SHELL_TASK_KILL_INL

#include "../include/guest_be.h"

struct Task
{
    be<unsigned int> pad00[2];   // 0x00, 0x04
    be<unsigned int> state;      // 0x08
};

// State 2 is the "dead / reap me" value the task scheduler looks for.
inline void Task_Kill(Task* t)
{
    t->state = 2;
}

#endif
