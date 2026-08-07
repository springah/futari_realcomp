// 0x821D1500 (shell) — logo FSM state 6: the PURE HOLD on the "M2" logo.
//
// The boot logo task (0x6C bytes, vptr 0x8204FA5C) drives an eight-state FSM through
// task+0x48 (SPEC_shell_compose_1to1.md §20.3).  The dual tick FUN_82173B98 tail-dispatches
// that pointer every frame, so a state function is just "one frame of this phase".
//
// State 5 (FUN_821D1540) performed the CAVE->M2 swap and faded M2 in; this state simply
// holds M2 fully opaque for 121 ticks (cnt = 0..0x78 inclusive — the limit test uses the
// pre-increment value, hence N+1 semantics), then hands off to state 7 (FUN_821D1408),
// the M2 fade-OUT.  It writes no colour and no hide bit — nothing but the counter.
//
// The skip latch (task+0x68) is set by the tick 0x821D1310 when A or START is held.  A hold
// state *honours* it by jumping the counter straight to the limit — so this frame is also
// the last one — but deliberately does NOT clear it; only the fade-IN states consume it.
// That asymmetry is what makes one button press skip the whole remaining logo sequence.
//
// Original (16 insn):
//   lbz r11,0x68(r3) / cmplwi cr6,r11,0 / beq cr6,+0xC / li r11,0x78 / stw r11,0x64(r3)
//   lwz r11,0x64(r3) / addi r10,r11,1 / cmpwi cr6,r11,0x78 / stw r10,0x64(r3) / bltlr cr6
//   lis r11,0x821D / li r10,0 / addi r9,r11,0x1408 / stw r10,0x64(r3) / stw r9,0x48(r3) / blr
//
// (0x821D1740, the CAVE hold, is the same shape with a different successor.)

typedef unsigned int u32;

struct LogoTask;
typedef void (*LogoStateFn)(LogoTask* task);

struct LogoTask
{
    u32           pad000[0x48 / 4];             // 0x000  vptr, child lists, node handles
    LogoStateFn   state;                        // 0x048  current FSM state (tail-dispatched)
    u32           pad04C[(0x64 - 0x4C) / 4];    // 0x04C  bank handle + built scene nodes
    int           cnt;                          // 0x064  ticks elapsed in the current state
    unsigned char skip;                         // 0x068  A/START seen — latched by the tick
};

// State 7 @ 0x821D1408 — fades the M2 logo back out over 61 ticks.
extern void Logo_FadeOutM2(LogoTask* task);

// Number of the last tick this state runs on; the hold therefore lasts kHoldLimit + 1 frames.
const int kHoldLimit = 0x78;

void Logo_Hold(LogoTask* task)
{
    if (task->skip)
        task->cnt = kHoldLimit;

    if (task->cnt++ < kHoldLimit)
        return;

    task->cnt = 0;
    task->state = Logo_FadeOutM2;
}
