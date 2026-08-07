// 0x821C30B8 (shell) — GameDriverTask INIT: the message burst that brings a driver instance up.
//
// EIGHT CLONES (0x821C30B8, 0x821C4650, 0x821C4ED0, 0x821C7AE0, 0x821C8360, 0x821C8BE0,
// 0x821C9460, ...) => 113 x 8 = 904 instructions, the single most valuable unmatched entry in
// decomp/registry.toml. Registry role: "Init driver (8 clones): msg 6,7,1,2,8,9 burst".
//
// The burst, in order:
//   base init  -> 0x821C64E8
//   msg 6      -> hands the game a slot it writes a pointer back into; we then store f4C there
//   msg 7      -> same shape for f50
//   msg 1      -> an eight-word descriptor built on the stack (see Msg1Desc)
//   msg 2      -> this->fA4
//   msg 8      -> &this->fB4
//   msg 9      -> four {callback, this} pairs
//   finally    -> a virtual call through vtable slot 0x34
//
// EXTENT IS 112, NOT THE 113 THE BOUNDARY TABLE IMPLIES. The word at +112 is `b 0x821C69F0`,
// sitting AFTER this function's `blr` — a .pdata-less leaf starting there, the same over-run
// class as Menu_Cancel. At 113 our body is one instruction short by construction; at 112 the
// lengths agree exactly and the epilogue is byte-identical.
//
// NOTE ON THE THREE RELOADS OF `g_env->f98` (image insns 30/33/36): the image loads the same
// field three times rather than caching it. That is not a source-level repetition to "fix" —
// the stack descriptor's address escapes into GameEntry, so the stores between those reads may
// alias, and this compiler reloads. Writing it as three reads reproduces it; caching it in a
// local does not.
//
// STATUS: 66/112, 13 structural mismatches, written from scratch 2026-08-05.
//
// WHAT ALREADY MATCHES EXACTLY: the prologue, the whole msg 6 / msg 7 burst (insns 6-19), the
// descriptor's first three fields including the three f98 reloads and the memcpy (30-41), and
// the entire epilogue. The msg 9 callback table (80-100) is STRUCTURALLY PERFECT — every
// opcode correct, all four `stw r31` instance stores in place — and differs only in register
// numbering and which stack slot each callback address lands in.
//
// WHAT IS LEFT, and it is one class: the two config ternaries at 43-61. The image computes the
// value into a register (taking the false arm from the perennial zero in r30 via `mr r10,r30`)
// and stores it ONCE after the merge; we store in both arms. That is 8 of the 13 structural
// mismatches. RULED OUT — do not re-run: hoisting either ternary into a local (39/112, and the
// function shrinks to 111), both into locals declared up front (38/112, 108 insn), `if/else`
// instead of `?:`, a shared `nul` variable feeding the two slot initialisers AND both false
// arms, typing `cfgBody` as `u32*`, and moving `desc.cfg` before `desc.handler` to match the
// image's store order. ALL FIVE ARE BYTE-IDENTICAL AT 66/112 — the sweep is flat, so this is
// allocator/scheduling residue, not spelling. Attack it with ALLOCATOR.md, not more syntax.
//
// THE ONE THING THAT DID MOVE IT (61 -> 66, S 17 -> 13): reading `g_env` into a local BEFORE the
// two slot stores rather than after. The image materialises that 0x8220xxxx base at insn 20,
// ahead of `lwz r8,0x4c(r31)`, and schedules the stores around the load.

typedef unsigned int u32;

struct GameDriverTask;

// The game module's entry point: r3 = message id, r4 = argument pointer.
typedef int (*GameEntryFn)(int msg, void* arg);
typedef void (*DriverCallback)(GameDriverTask* d);

struct GameDriverTask
{
    const void* vtbl;                       // 0x000
    u32         pad004[(0x4C - 0x04) / 4];
    u32         f4C;                        // 0x04C  published through the msg 6 slot
    u32         f50;                        // 0x050  published through the msg 7 slot
    u32         pad054[(0xA4 - 0x54) / 4];
    u32         fA4;                        // 0x0A4  msg 2 argument
    u32         pad0A8[(0xB4 - 0xA8) / 4];
    u32         fB4;                        // 0x0B4  msg 8 points at this
    u32         pad0B8[(0xFC - 0xB8) / 4];
    GameEntryFn GameEntry;                  // 0x0FC
};

// 0x822085B0 — the environment record the descriptor is built from.
struct Env
{
    u32  pad00[0x98 / 4];
    u32* f98;                               // 0x098  -> {., f04, f08, ... , f98 = 0x130 bytes }
};
extern Env* g_env;

// 0x8220857C — optional config record; both descriptor fields below degrade to null without it.
struct DriverConfig
{
    u32* f00;                               // 0x00
    u32  pad04[2];
    u32  f0C;                               // 0x0C
};
extern DriverConfig* g_driverConfig;

// The two fixed addresses the descriptor always carries.
//   0x82208210 is the ENGINE CRITICAL SECTION, not a table — 0x821CA5B8 passes this same address
//   to the 0x821D5384/0x821D5394 lock pair, which is how it was identified. It was written here
//   as `g_driverDescTable` on first drafting; corrected once its other user was decompiled.
//   0x821CA5B8 is Driver_PublishDesc (src/shell_821CA5B8_Driver_PublishDesc.cpp, ASM-EXACT) —
//   the callback the game module invokes during msg 1 / msg 2.
extern u32 g_engineLock;                        // 0x82208210
extern "C" void Driver_PublishDesc(void* rec, u32 value);   // 0x821CA5B8

// The four callbacks msg 9 registers, each paired with the driver instance.
extern "C" void Driver_Cb52E8(GameDriverTask* d);   // 0x821C52E8
extern "C" void Driver_Cb6208(GameDriverTask* d);   // 0x821C6208
extern "C" void Driver_Cb5618(GameDriverTask* d);   // 0x821C5618
extern "C" void Driver_Cb5230(GameDriverTask* d);   // 0x821C5230

extern "C" void* memcpy(void* dst, const void* src, unsigned n);
extern "C" void Driver_BaseInit(GameDriverTask* d);  // 0x821C64E8

// msg 1's argument: eight words assembled on the caller's stack.
struct Msg1Desc
{
    u32         a;          // 0x00  g_env->f98[1]
    u32         b;          // 0x04  g_env->f98[2]
    void*       buf;        // 0x08  -> the 0x130-byte copy below
    u32*        cfgHead;    // 0x0C  g_driverConfig ? g_driverConfig->f00 : 0
    const void* lock;       // 0x10  &g_engineLock
    void*       cfgBody;    // 0x14  (cfg && cfg->f00) ? &cfg->f0C : 0
    const void* handler;    // 0x18  &Driver_PublishDesc
    void*       cfg;        // 0x1C  g_driverConfig
};

// msg 9's argument: four {callback, instance} pairs.
struct Msg9Entry
{
    DriverCallback  fn;
    GameDriverTask* self;
};

void Driver_Init(GameDriverTask* d)
{
    Driver_BaseInit(d);

    u32* slot6 = 0;
    u32* slot7 = 0;
    d->GameEntry(6, &slot6);
    d->GameEntry(7, &slot7);

    // The environment pointer is read BEFORE the two slot stores: the image materialises its
    // 0x8220xxxx base at insn 20, ahead of `lwz r8,0x4c(r31)`, and takes the load itself at 25
    // with the stores scheduled around it.  Reading it after the stores costs 5 words (61 vs 66)
    // and 4 structural mismatches.
    Env* env = g_env;

    *slot6 = d->f4C;
    *slot7 = d->f50;

    Msg1Desc desc;
    unsigned char envCopy[0x130];

    desc.a = env->f98[1];
    desc.b = env->f98[2];
    memcpy(envCopy, (const unsigned char*)env->f98 + 0x98, 0x130);
    desc.buf = envCopy;

    DriverConfig* cfg = g_driverConfig;
    desc.cfgHead = cfg ? cfg->f00 : 0;
    desc.lock    = &g_engineLock;
    desc.cfgBody = (cfg && cfg->f00) ? &cfg->f0C : 0;
    desc.handler = (const void*)&Driver_PublishDesc;
    desc.cfg     = cfg;

    d->GameEntry(1, &desc);
    d->GameEntry(2, (void*)d->fA4);
    d->GameEntry(8, &d->fB4);

    Msg9Entry cbs[4];
    cbs[0].fn = &Driver_Cb52E8;  cbs[0].self = d;
    cbs[1].fn = &Driver_Cb6208;  cbs[1].self = d;
    cbs[2].fn = &Driver_Cb5618;  cbs[2].self = d;
    cbs[3].fn = &Driver_Cb5230;  cbs[3].self = d;
    d->GameEntry(9, cbs);

    (*(void (**)(GameDriverTask*))((const char*)d->vtbl + 0x34))(d);
}
