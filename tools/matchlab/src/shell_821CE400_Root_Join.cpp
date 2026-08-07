// 0x821CE400 (shell) — Root_Join: the shell ROOT task's "wait for my children" state.
//
// The root task drives the whole front-end as a phase FSM through task+0x48 (see
// ghidra_futari_decomp/ATLAS_scene_system.md §8.4).  Root_PhaseDispatch (0x821CE098) runs one
// phase — ensure the veil, spawn the logo, spawn the top menu, spawn the game-driver task — and
// then parks the root in THIS state.  Root_Join is ticked once per frame and deliberately does
// nothing while the children it spawned are still alive; when the last one dies AND the phase
// word has actually moved on, it hands control back to the dispatcher.
//
// That "return early while [root+0x5C]+0x10 != 0" is the engine-wide invariant which makes every
// "spawn a child, then set the wait state" sequence in this shell work.
//
// Two global escapes are tested first, and each replaces the whole join with a different state:
//   * cfg->resetRequest (0x821F8588 +0x68) -> Root_Reset (0x821CDF30), which zeroes the phase
//     record ([cfg+0x4C]+0x54) and rebuilds the front end from scratch.
//   * Root_GuestSignedOut() (0x82189740)   -> Root_SignoutModal (0x821CDE00), the error modal.
//
// On the way out it publishes the "the shell front-end owns the screen" predicate
// g_appConfig->frontEndActive (+0x64) = (4 <= phase <= 6): phase 4 is veil-release, 5 is the top menu and
// 6 spawns the game driver, i.e. exactly the window in which the shell composes its own screen.
// The port reads that word as a register-true compose-routing signal (ATLAS §8.3 item 5).
//
// Original (46 insn), the shape this file is trying to reproduce:
//   mflr r12 / stw r12,-8(r1) / std r30,-0x18(r1) / std r31,-0x10(r1) / stwu r1,-0x70(r1)
//   lis r30,0x8220 / mr r31,r3 / lwz r11,-0x7A78(r30) / lwz r11,0x68(r11) / cmpwi cr6,r11,0
//   beq +0x10 / lis r11,0x821D / addi r11,r11,-0x20D0 / b STORE
//   bl 0x82189740 / clrlwi r11,r3,24 / cmplwi cr6,r11,0 / beq +0x10
//   lis r11,0x821D / addi r11,r11,-0x2200 / b STORE
//   lwz r11,0x5C(r31) / lwz r10,0x10(r11) / cmplwi cr6,r10,0 / bne EXIT
//   lwz r11,0x50(r31) / lwz r10,0x4C(r31) / cmpw cr6,r10,r11 / beq EXIT
//   cmpwi cr6,r11,4 / blt +0x10 / cmpwi cr6,r11,6 / li r10,1 / ble +8 / li r10,0
//   lwz r11,-0x7A78(r30) / stw r10,0x64(r11) / lis r11,0x821D / addi r11,r11,-0x1F68
//   STORE: stw r11,0x48(r31) / EXIT: epilogue
//
// STATUS: DIFF — 46/46 instructions, 28 positionally identical.  What is left is one
// register-allocation decision and its fallout; see the note at the bottom of this file.

struct RootTask;
typedef void (*RootStateFn)(RootTask* root);

// The root's child container (the scene system's task list).  Only the live-child count matters
// here: while it is non-zero the root must not advance.  Compared with cmplwi -> unsigned.
struct TaskList
{
    unsigned int pad000[4];          // 0x00  vptr, list links
    unsigned int liveCount;          // 0x10  children still alive
};

struct RootTask
{
    unsigned int pad000[0x48 / 4];   // 0x00  vptr, node handles, child lists (+0x24, +0x40)
    RootStateFn  state;              // 0x48  current FSM state, dispatched once per frame
    int          lastPhase;          // 0x4C  the phase the dispatcher last ran
    int          phase;              // 0x50  the phase requested (the top menu writes it)
    int          modeIndex;          // 0x54  game mode chosen in the top menu
    unsigned int pad058;             // 0x58
    TaskList*    children;           // 0x5C  the tasks this root spawned
};

// The global config/services object; the pointer to it lives at 0x821F8588.
struct AppConfig
{
    unsigned int pad000[0x64 / 4];   // 0x00  services; +0x4C state object, +0x54, +0x74 profiles
    int          frontEndActive;     // 0x64  1 while the shell front-end owns the screen
    int          resetRequest;       // 0x68  non-zero: tear the front end down and rebuild it
};

extern AppConfig* g_appConfig;

// 0x82189740 — true when a signed-in guest went away and the error modal has to come up.
// It returns 0/1 in r3 and the caller masks it with clrlwi, i.e. a `bool` return.
extern bool Root_GuestSignedOut();

extern void Root_SignoutModal(RootTask* root);    // 0x821CDE00
extern void Root_Reset(RootTask* root);           // 0x821CDF30
extern void Root_PhaseDispatch(RootTask* root);   // 0x821CE098

// Phases 4..6: veil release, top menu, game-driver spawn.
const int kFrontEndFirstPhase = 4;
const int kFrontEndLastPhase  = 6;

void Root_Join(RootTask* root)
{
    RootStateFn next;

    if (g_appConfig->resetRequest != 0)
    {
        next = Root_Reset;
    }
    else if (Root_GuestSignedOut())
    {
        next = Root_SignoutModal;
    }
    else
    {
        // Still waiting: children alive, or the dispatcher has already run this phase.
        if (root->children->liveCount != 0)
            return;

        if (root->lastPhase == root->phase)
            return;

        g_appConfig->frontEndActive =
            (root->phase >= kFrontEndFirstPhase && root->phase <= kFrontEndLastPhase);

        next = Root_PhaseDispatch;
    }

    root->state = next;
}

// ---------------------------------------------------------------------------------------------
// What still differs, and what was ruled out (2026-08-04)
//
// The instruction stream is the right length, with the right opcodes in the right order except
// for two adjacent words in the tail.  The whole delta is one register-allocation choice:
//
//     original      lis r30,<&g_appConfig>   mr r31,r3      (base -> r30, parameter -> r31)
//     9328 here     lis r31,<&g_appConfig>   mr r30,r3      (base -> r31, parameter -> r30)
//
// That swap renames r30/r31 in the six instructions that touch them, and it cascades: with `next`
// pinned to r11 by the merge, the original reuses r11 for the reloaded config pointer (so its
// `lis r11` cannot be hoisted above `stw r10,0x64(r11)`), while 9328 here parks the config
// pointer in r10, leaves r11 free, and lets the scheduler hoist the `lis/addi` above the flag
// store — two words swapped, and the flag constant lands in r9 instead of r10.
//
// Ruled out by sweep (~50 builds, every one of which produced these same 46 instructions and the
// same 28 matches):
//   * expression shape — early return vs `else`, goto, do/while(0)+break, `&&` guard vs two ifs,
//     nested vs chained ifs, inverted branch polarity, ternary vs `&&` for the range test,
//     comparison operand order.  Flat, exactly as matchlab tell #7 predicts.
//   * locals — none / `next` alone / plus `AppConfig* cfg` / plus `int active`, in all six
//     declaration orders, reading the config through the local or the global (tell #6 axis).
//   * types — `void*` and `unsigned int` for `next`, `RootTask&` parameter, global declared as
//     `AppConfig&` and as `AppConfig**`, const parameter, unused second parameter, and
//     `RootTask::Root_Join()` as a member function.
//   * flags — -O2, -Ox, -Og, -Ogt, -O2 with -Ob0/-Ob1/-Ob2, -GS-, -Gy, -Oy-, -Oi-, -Ou/-Ou-,
//     -Gd/-Gz/-Gr, -Zp1, -EHsc.  (-Os/-Ot/-Oit/-Oxs restructure the function and are wrong.)
//   * declaration order of the externs themselves.
//
// Diagnostics that DO flip the allocation the right way, and why they are not the answer: writing
// `root->state` directly in the deep path (with or without a `next` local for the two escapes)
// puts the parameter in r31 — but it also emits a second store, so those builds are 47 or 48
// instructions, and 9328 never tail-merges the stores back together.  Adding extra references to
// `root` does NOT flip it, so this is not a simple use-count ordering either.
//
// A census of the shell image shows the original compiler emits BOTH assignments (12 functions
// with parameter->r31/base->r30 against 8 the other way, counting the first twelve instructions),
// so the original toolchain is capable of what we want and this is not a systematic difference —
// something about this source still reads differently to it.
//
// ❌ THE c2.dll LEAD IS DEAD (2026-08-05).  This note used to end by proposing "re-run under a
// QFE'd c2.dll" as the next experiment.  Do not.  Both compiler back-ends that XDK 9328 ships
// were already extracted on this machine, and they were compared directly:
//     xdk9328/raw + TechPreview/Mar09Compiler  cl 15.00.8327  c2.dll 7f0cdb62  <- matchlab's CL
//     XDK/bin/win32 + xdk9328_ship             cl 15.00.8153  c2.dll 01db8e0e
// ALL 97 ASM-EXACT TARGETS STAY EXACT UNDER BOTH, with zero DIFFs, and every stuck function
// scores identically under both.  Codegen for this corpus is invariant across every compiler in
// the 9328 tree, so the back-end is not the variable here and no QFE extraction is needed.
// (`MATCHLAB_CL` overrides the compiler path if this ever has to be re-tested.)
