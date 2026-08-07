// GameDriverTask -> game module message wrappers (shell, 0x82).
//
// Every one of these calls the game's exported GameEntry(msg, arg) through the function
// pointer the loader stored at driver+0xFC (ATLAS_shell_menus "Shell->game protocol").
// The pattern is always: stage whatever state the message needs into the driver object,
// put the argument somewhere addressable, then call GameEntry(msg, &arg).
//
// Msg ids are the same ones GameEntry_Dispatch decodes on the game side
// (decomp/game/game_entry_msgs.cpp).
//
//   0x821C2B38  msg 13  return-to-menu       (tail call, no argument)
//   0x821C2B50  msg 12  mode64 arm           (tail call, no argument)
//   0x821C2B90  msg 19  single-param setter  == clone 0x821C8F38 (byte-identical)
//   0x821C2C20  msg 16  single-param setter  == clone 0x821C8FC8 (byte-identical)
//   0x821C2CB0  msg 10  mode arm, simple
//   0x821C2D00  msg 10  mode arm, extended (two extra params)
//   0x821C8E20  msg 11  rank/level setter

typedef unsigned int u32;

// The game module's entry point: r3 = message id, r4 = argument pointer.
typedef int (*GameEntryFn)(int msg, void* arg);

struct GameDriverTask
{
    const void* vtbl;               // 0x000
    u32         pad004[(0x5C - 0x04) / 4];
    u32         startValue;         // 0x05C  staged from g_driverStartValue before msg 5
    u32         pad060[(0x78 - 0x60) / 4];
    u32         armState;           // 0x078  0 / 1 / 5 depending on the arm flavour
    u32         pad07C[(0x8C - 0x7C) / 4];
    u32         extraA;             // 0x08C
    u32         extraB;             // 0x090
    u32         level;              // 0x094
    u32         arg;                // 0x098
    u32         pad09C[(0xA8 - 0x9C) / 4];
    u32         modeIndex;          // 0x0A8  which of the 8 driver instances / modes
    u32         pad0AC[(0xC0 - 0xAC) / 4];
    u32         aux;                // 0x0C0
    u32         pad0C4[(0xF8 - 0xC4) / 4];
    void*       hmodule;            // 0x0F8  XexLoadImage handle
    GameEntryFn GameEntry;          // 0x0FC
};

// 0x821C2B38 — msg 13, return to menu. Tail call: nothing to stage, no argument.
int Driver_SendReturnToMenu(GameDriverTask* d)
{
    return d->GameEntry(13, 0);
}

// 0x821C2B50 — msg 12, arm mode64. Same shape as msg 13.
int Driver_SendArmMode64(GameDriverTask* d)
{
    return d->GameEntry(12, 0);
}

// 0x821C2B90 (and its byte-identical clone 0x821C8F38) — msg 19.
// The callee takes a pointer, so the parameter is spilled to its own home slot
// (r1+0x7C) and that address is passed -- NOT a copy in a fresh local (r1+0x50).
void Driver_SetConfig19(GameDriverTask* d, u32 value)
{
    d->GameEntry(19, &value);
}

// 0x821C2C20 (and its byte-identical clone 0x821C8FC8) — msg 16.
void Driver_SetConfig16(GameDriverTask* d, u32 value)
{
    d->GameEntry(16, &value);
}

// 0x821C2CB0 — msg 10, simple arm. armState is 5 when a mode is supplied, else 0.
// `mode` is SIGNED: the original compares with cmpwi, not cmplwi.
void Driver_ArmMode(GameDriverTask* d, int mode)
{
    d->armState = 0;
    if (mode != 0)
        d->armState = 5;
    d->arg = (u32)mode;
    d->GameEntry(10, &mode);
}

// 0x821C2D00 — msg 10, extended arm: carries two extra params, and clears them when
// no mode is supplied.
void Driver_ArmModeEx(GameDriverTask* d, int mode, u32 a8c, u32 a90)
{
    d->armState = 0;
    if (mode != 0)
    {
        d->extraA = a8c;
        d->extraB = a90;
        d->armState = 1;
    }
    else
    {
        d->extraA = 0;
        d->extraB = 0;
    }
    d->arg = (u32)mode;
    d->GameEntry(10, &mode);
}

// 0x8207DAC0 is LIBCMT's memcpy. It must be declared AS memcpy, not as a look-alike helper:
// the compiler knows this name and sets up r3 before r5, while an ordinary 3-argument
// function gets the reverse order. That one detail is the whole difference between
// matching and not.
extern "C" void* memcpy(void* dst, const void* src, unsigned n);

// 0x821F858C — holds a pointer to the active region-configuration record.
extern const void** g_regionConfig;

// 0x821C2DC0 — msg 15: hand the game a 16-byte copy of the region config, with a -1
// terminator word appended after it.
void Driver_SendRegionConfig(GameDriverTask* d)
{
    u32 block[5];
    memcpy(block, *g_regionConfig, 0x10);
    block[4] = 0xFFFFFFFF;
    d->GameEntry(15, block);
}

// 0x821C2C58 (8 identical instances) — msg 15 again, but PARAMETERISED. Where
// Driver_SendRegionConfig reads the active region config and appends a -1 terminator, this one
// takes the source block and the terminator word from its caller: r4 is passed straight through
// to memcpy untouched (nothing sets it before the call), and the third argument is staged in a
// nonvolatile across the memcpy and then stored as block[4].
void Driver_SendConfigBlock(GameDriverTask* d, const void* src, u32 tail)
{
    u32 block[5];
    memcpy(block, src, 0x10);
    block[4] = tail;
    d->GameEntry(15, block);
}

// 0x821C8E20 — msg 11, rank/level. Out-of-range levels fall back to 4, and the level is
// sent as a signed bit mask: below centre it is a negative run, above it a single bit.
void Driver_SetRankLevel(GameDriverTask* d, int level)
{
    if (level < 0 || level > 8)
        level = 4;
    d->level = (u32)level;

    int mask;
    if (level < 4)
        mask = -1 << (4 - level);
    else
        mask = 1 << (level - 4);

    d->GameEntry(11, &mask);
}

// 0x821C3280 (7 identical instances) — msg 5, START. Two globals gate a once-only first-start
// hook: the first is a "may start at all" flag, the second a latch this function sets itself so
// the hook runs exactly once across all seven driver instances. Note the image re-materialises
// the 0x8220xxxx base with its own `lis` for each of the three globals rather than sharing one —
// the same "a separate lis per distinct symbol" behaviour seen throughout this compiler.
extern u32 g_driverStartGate;       // 0x82208574
extern u32 g_driverStartedOnce;     // 0x82208578
extern u32 g_driverStartValue;      // 0x822085B8

extern "C" void Driver_FirstStart(GameDriverTask* d);   // 0x82184CC8
extern "C" void Driver_AfterStart(int result);          // 0x821C54F8

void Driver_Start(GameDriverTask* d)
{
    if (g_driverStartGate != 0 && g_driverStartedOnce == 0)
    {
        g_driverStartedOnce = 1;
        Driver_FirstStart(d);
    }
    d->startValue = g_driverStartValue;
    Driver_AfterStart(d->GameEntry(5, 0));
}

// ---------------------------------------------------------------- lifecycle

// 0x8204FFA8 — the GameDriverTask vtable the destructor re-seats before tearing down.
extern const void* const g_GameDriverTaskVtbl;

extern "C" void Xex_UnloadImage(void* hmodule);      // 0x82088D98
extern "C" void Task_Destroy(GameDriverTask* t);     // 0x821C5738 (base-class teardown)

// 0x821C2EF0 — GameDriverTask destructor: tell the game to shut down (msg 3), unload the
// module if one is still loaded, then run the base teardown.
void Driver_Destroy(GameDriverTask* d)
{
    d->vtbl = &g_GameDriverTaskVtbl;
    d->GameEntry(3, 0);
    if (d->hmodule != 0)
    {
        Xex_UnloadImage(d->hmodule);
        d->hmodule = 0;
    }
    Task_Destroy(d);
}

// ---------------------------------------------------------------- query + stage record

// 0x821C2BD8 (8 identical instances) — msg 17 is a QUERY: the request block carries the
// value being asked about plus a pointer the game writes its answer through.
struct Msg17Request
{
    u32  value;     // 0x00
    u32* out;       // 0x04
};

u32 Driver_Query17(GameDriverTask* d, u32 value)
{
    u32 result = 0;
    Msg17Request req;
    req.value = value;
    req.out = &result;
    d->GameEntry(17, &req);
    return result;
}

// 0x821C2D68 (8 identical instances) — msg 20 hands over this driver's stage record: the
// 720-byte (0x2D0) entry for its mode index, offset 0x10 into the record, plus one aux word.
// 0x2D0 matches ATLAS_shell_menus msg 20 ("stage 0x2d0-byte block").
//
// PARKED at 16/22 — and the whole residue is ONE INSTRUCTION IN THE WRONG SLOT.
// The register allocation below is ALREADY the image's (modeIndex r10, aux r9, GameEntry r8),
// every instruction is present with the right operands, and the two halves agree everywhere
// except that our `stw r9,0x54(r1)` — the `req.aux` store — is scheduled at slot 13 and the
// image's at slot 10.  mtctr / the deref / `li r3,0x14` just shift up one to fill:
//     image  9 lwz r11,cfg | 10 stw r9 | 11 mtctr r8 | 12 lwz r11,0(r11) | 13 li r3,0x14
//     ours   9 lwz r11,cfg | 10 mtctr  | 11 lwz r11,0(r11) | 12 li r3,0x14 | 13 stw r9
//
// 37 SOURCE VARIANTS MEASURED (2026-08-05) AND THE FUNCTION IS BINARY: every shape scores
// either 16 (aux stored after the record assignment) or 10 (aux stored before it).  Nothing
// lands in between, and nothing reaches 17.  Storing aux first DOES move the store to the
// right slot — the whole 10..13 window then matches the image exactly — but it also flips the
// two leading loads (aux lands in r9 and modeIndex in r8 instead of r10), and that reallocation
// costs more than the store gains.  Ruled out, do not re-run: statement order both ways;
// idx/aux/off/fn/cfg locals in every combination; splitting the record EXPRESSION from its
// STORE; splitting `*g_regionConfig` into its two loads with the aux store between them;
// aggregate init; a `Msg20Request*` alias; `((u32*)&req)[1] = d->aux`; two bare locals instead
// of the struct (6); __forceinline helper for the record, for both fields, and a constructor
// with the members in both orders.  Flags are not the lever either: -O2, -Ox, -O2 -Ob1,
// -O2 -Oy-, -O2 -GS-, -O2 -Op all give 16; -O1 gives 14; -Os/-Ot give 26 instructions.
//
// So the remaining defect is NOT source ordering — it is whatever makes the image's scheduler
// prefer a ready store over a ready `mtctr` at that cycle.  Worth solving: this body has EIGHT
// byte-identical instances, so it is 198 instructions, the single biggest lever on the board.
//
// ⚖ 17/22 IS REACHABLE WITH `volatile`, AND IS DELIBERATELY NOT TAKEN.  Reading the two fields as
//    `*(volatile u32*)&d->modeIndex` / `&d->aux` pins the load order, defeats the reassociation
//    that sinks the aux store, and scores 17/22 with the prefix running 0-12 (structural 4 -> 2).
//    The semantics are identical — they are plain `u32` field reads either way — and the rest of
//    the TU re-verified EXACT with the change in place.  It is still REFUSED: a `volatile` cast is
//    a scheduling device, not something the original source plausibly contained, and this campaign
//    matches without fudge factors.  A body that scores higher by telling the compiler something
//    the original never said is not a better decompilation, it is a better-scoring wrong answer.
//    ⇒ **16/22 is the volatile-free ceiling**, and that is the number this file stands on.
struct Msg20Request
{
    const void* record;     // 0x00
    u32         aux;        // 0x04
};

void Driver_SendStageRecord(GameDriverTask* d)
{
    Msg20Request req;
    req.record = (const unsigned char*)(*g_regionConfig) + d->modeIndex * 0x2D0 + 0x10;
    req.aux = d->aux;
    d->GameEntry(20, &req);
}
