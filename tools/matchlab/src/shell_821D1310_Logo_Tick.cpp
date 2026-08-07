// 0x821D1310 (shell) — the boot-logo task's STATE RUNNER (SPEC_shell_compose_1to1.md §20.2).
//
// The logo task (0x6C bytes, vptr 0x8204FA5C) puts this function in vtable slot +0x0C.  The
// dual tick FUN_82173B98 calls that slot once per frame, but only while the task's SERIAL A
// child list (task+0x20) is empty — that emptiness test is the FSM's whole wait primitive.
//
// All this runner does is (a) latch "the player wants to skip the logos" and (b) tail-dispatch
// whichever of the eight state functions currently sits in task+0x48.  The skip latch is only
// ever set here; the individual states decide what to do with it (the fade-INs consume it, the
// holds honour it without clearing it — that asymmetry is what makes one press skip the rest of
// the sequence).  See src/shell_821D1500_Logo_Hold.cpp for the consuming side.
//
// Original (14 insn):
//   lis r11,0x8220 / lwz r11,-0x7A78(r11)      ; r11 = g_shellConfig  (the DAT_821F8588 global)
//   lwz r10,0x4C(r11) / lwz r9,0x50(r10) / lwz r8,0x254(r9)
//   rlwinm r7,r8,0,28,31 / rlwinm r7,r7,0,31,28 ; = r8 & 9, as two contiguous masks
//   cmplwi cr6,r7,0 / beq cr6,+0xC / li r11,1 / stb r11,0x68(r3)
//   lwz r11,0x48(r3) / mtctr r11 / bctr          ; TAIL dispatch, not a call

typedef unsigned int u32;

// One entry of the pad manager's 5-slot record table (indices 0..4; the bounds test inlined
// into FUN_82190A90 / FUN_82190AE0 is "i < 0 || i > 4", which is how the count is known).
// Three separate button-mask words live in every record; the shell reads all three.
struct PadRecord                                // 0x84 bytes
{
    u32 buttonsRaw;                             // 0x00  wide mask (0x4000..0x800000 bits tested)
    u32 unk04;                                  // 0x04
    u32 buttonsPressed;                         // 0x08  the mask FUN_82190A90 scans with 9
    u32 buttonsRepeat;                          // 0x0C
    u32 rest[(0x84 - 0x10) / 4];                // 0x10  per-pad analogue/history state
};

// Bits of PadRecord::buttonsPressed used by the shell front-end.
const u32 kBtnA     = 0x1;
const u32 kBtnStart = 0x8;

// [[g_shellConfig+0x4C]+0x50] — the pad manager.  FUN_82190A90 takes exactly this pointer.
struct PadManager
{
    u32       pad000[0x3C / 4];                 // 0x000  latches (+0x14/+0x18), found-pad index (+0x24/+0x28)
    PadRecord pads[5];                          // 0x03C  pads[4].buttonsPressed == +0x254
};

// [g_shellConfig+0x4C] — the services object that owns the pad manager, the sound system
// (+0x54) and the mode-record table.
struct ShellServices
{
    u32         pad000[0x50 / 4];               // 0x00
    PadManager* pads;                           // 0x50
};

// DAT_821F8588 — THE global config/services object (0x80 bytes, built by FUN_8218A358 and
// stored by the shell root ctor FUN_821CE528).
struct ShellConfig
{
    u32            pad000[0x4C / 4];            // 0x00
    ShellServices* services;                    // 0x4C
};

extern ShellConfig* g_shellConfig;              // 0x821F8588

struct LogoTask;
typedef void (*LogoStateFn)(LogoTask* task);

struct LogoTask                                 // 0x6C bytes, vptr 0x8204FA5C
{
    u32           pad000[0x48 / 4];             // 0x000  vptr, child lists, node handles
    LogoStateFn   state;                        // 0x048  current FSM state (tail-dispatched)
    u32           pad04C[(0x68 - 0x4C) / 4];    // 0x04C  bank handle, built scene nodes, cnt
    unsigned char skip;                         // 0x068  A/START seen — latched here, only here
};

void Logo_Tick(LogoTask* task)
{
    if (g_shellConfig->services->pads->pads[4].buttonsPressed & (kBtnA | kBtnStart))
        task->skip = 1;

    task->state(task);
}
