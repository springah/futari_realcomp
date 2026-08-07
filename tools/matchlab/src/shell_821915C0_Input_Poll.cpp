// 0x821915C0 (shell) — PER-USER INPUT POLL: latch the device, read this user's pad, and repack.
// registry.toml: "Per-user input entry (user<4); latch + mask-convert + repack".
//
// The per-user records start 0xB0 into the base and are 0x84 bytes each, which is why the image
// computes `user * 0x84 + base` and then `+ 0xB0` with an `addic.` that doubles as the null test.
//
// The repack is two masks: `clrlwi r3,r3,8` keeps the low 24 bits, then
// `rlwinm r3,r3,0,0x14,0x11` is a WRAPPED mask (MB=20 > ME=17) that clears exactly bits 12-13.

// STATUS: 25/31, length exact, ZERO STRUCTURAL MISMATCHES — every opcode and every operand shape
// is the image's. The entire residue is FOUR words from one nonvolatile swap: the image holds
// `base` in r30 and `user` in r31; we do the reverse, and insns 12/13 follow from it.
//
// ⚠ THIS IS THE SAME ANOMALY AS Root_Join (0x821CE400), and the tie is closer than it looks. Both
// values are compared on their INCOMING argument registers (image insns 7/9 use r4, not r31), so
// after the saves each nonvolatile carries exactly ONE use — `mulli r11,r31,0x84` for user,
// `add r11,r11,r30` for base. A genuine tie, broken by definition order: the image saves `base`
// FIRST and gives it the LOWER register, ours saves `base` first and gives it the HIGHER one.
// Whatever picks the direction is not visible in the emitted code, which is exactly what
// ALLOCATOR.md's "further ordering term" section is about. Do not sweep syntax for it.
//
// ★ WHAT GOT IT TO S=0: the NULL arm must be written FIRST (`if (rec == 0) raw = 0; else ...`).
//   Both `rec ? Read(rec) : 0` and `if (rec != 0) ... else ...` make MSVC lay the READ path out as
//   the fall-through and branch to the null path; the image branches to the read (`bne`). Two
//   further spellings that collapse the mask into each arm's return are much worse (10/31 at 27
//   instructions) — the masked repack must happen ONCE after the join.

typedef unsigned int u32;

struct PadRecord
{
    u32 w[0x84 / 4];
};

struct InputBase
{
    u32       pad000[0xB0 / 4];
    PadRecord users[4];             // 0x0B0, stride 0x84
};

extern "C" void Input_Latch(InputBase* base);   // 0x821905A0
extern "C" u32  Input_Read(PadRecord* rec);     // 0x82190B38

enum { INPUT_USERS = 4, KEEP_LOW24 = 0x00FFFFFFu, DROP_BITS_12_13 = ~0x00003000u };

u32 Input_Poll(InputBase* base, int user)
{
    if (user < 0 || user >= INPUT_USERS)
        return 0;

    Input_Latch(base);

    // The NULL arm must come FIRST. Written as `rec ? Read(rec) : 0`, or as
    // `if (rec != 0) ... else ...`, MSVC lays the read path out as the fall-through and branches
    // to the null path; the image does the opposite (`bne` to the read). Testing `== 0` first
    // flips the polarity and takes the function to ZERO structural mismatches -- every opcode
    // correct, only register numbering left.
    PadRecord* rec = &base->users[user];
    u32 raw;
    if (rec == 0)
        raw = 0;
    else
        raw = Input_Read(rec);
    return (raw & KEEP_LOW24) & DROP_BITS_12_13;
}
