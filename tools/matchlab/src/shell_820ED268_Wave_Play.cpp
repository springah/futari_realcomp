// 0x820ED268 (shell) — WAVE PLAY: prepare the sink, then push every entry of this wave's send
// list into it, stopping at the first failure. Two copies => 56 instructions.
//
// registry.toml: "Wave PLAY: iterate send-list (no-op while gate wave+0x160 == 0)".
//
// The list is an intrusive doubly-linked ring: the head pointer lives at +0x168 and the SENTINEL
// is the node-shaped field pair at +0x164, so the walk ends when the cursor comes back to
// `&wave->listSentinel` rather than at a null. That is why the image computes `r30 + 0x164` into
// a register and compares against it instead of testing for zero.
//
// The return value is the LAST call's status: 0 when the gate is closed, Wave_Prepare's failure
// when it fails, otherwise whatever the final Wave_Send returned.

// STATUS: 19/28, length exact, only 2 structural mismatches. Was 2/28 at 32 instructions.
//
// TWO CONTROL-FLOW FACTS DID ALL OF IT, and both are reusable:
//   1. SINGLE EXIT. Every failure path in the image branches to one epilogue at 0x820ED2D0
//      instead of returning inline, so `rc` is a carried variable returned once. Early returns
//      make MSVC emit an inline `li r3,0` + epilogue and the function grows. Same shape that
//      unlocked Page_EnsureTexture; that makes two functions where it was the lever.
//   2. THE LOOP IS NOT ROTATED. The image's `n != end` test exists ONCE, at the top, with the
//      back-edge jumping straight to it. A plain `while` makes MSVC rotate it -- guard at the
//      top, duplicated test at the bottom -- costing 4 words. The explicit back-edge is what
//      keeps it unrotated.
//   Neither alone is enough: single-exit with a `while` gives 30 insn / 12, the unrotated loop
//   with early returns gives 30 / 2. Together, 28 / 19.
//
// ⚠ The rotation is NOT a flags question, and I checked before concluding: -O1 -Oc and -O2 -Os
//   reach 30 insn / 8 but still rotate, so a better score there is not evidence of library code
//   and was not adopted. Canonical stays -O2 -Oc.
//
// ⏭ THE REMAINING 5 WORDS ARE ONE ALLOCATION DECISION, all in insns 3-9. The image saves `sink`
//   into its nonvolatile FIRST (`mr r29,r4`) and then reads the gate into the now-free r4; we
//   read the gate into r11 and save `sink` later. Everything else follows: at +9 the image feeds
//   the call from r29 while we still have it in r4.

typedef unsigned int u32;

struct WaveNode
{
    WaveNode* prev;             // 0x00
    WaveNode* next;             // 0x04
    u32       pad08[(0x0C - 0x08) / 4];
    u32       a;                // 0x0C
    u32       b;                // 0x10
    u32       c;                // 0x14
    u32       d;                // 0x18
};

struct Wave
{
    u32       pad000[0x160 / 4];
    u32       gate;             // 0x160  play is a no-op while this is 0
    WaveNode  listSentinel;     // 0x164  the ring's sentinel; head is its `next` at 0x168
};

// 0x820F7138 / 0x820F7180 — the sink.
extern "C" int Wave_Prepare(void* sink);
extern "C" int Wave_Send(void* sink, u32 a, u32 b, u32 c, u32 d);

int Wave_Play(Wave* wave, void* sink)
{
    // SINGLE EXIT, and the loop is NOT rotated. Both are load-bearing, and together they took
    // this function from 32 instructions / 2 correct to 28 / 19:
    //   * every failure path in the image branches to ONE epilogue (0x820ED2D0) rather than
    //     returning inline, so `rc` is a carried variable returned once -- the same shape that
    //     unlocked Page_EnsureTexture. Written with early returns, MSVC emits an inline
    //     `li r3,0` + epilogue and the function grows.
    //   * the image's `n != end` test exists ONCE, at the top, with the back-edge jumping to it.
    //     A plain `while` makes MSVC rotate -- guard at the top, duplicated test at the bottom,
    //     +4 words. The explicit back-edge below is what keeps it unrotated; five other loop
    //     spellings all rotated (see the header).
    int rc = 0;
    if (wave->gate != 0)
    {
        rc = Wave_Prepare(sink);
        WaveNode* n = wave->listSentinel.next;
        if (rc >= 0)
        {
            WaveNode* end = &wave->listSentinel;
        loop:
            if (n != end)
            {
                rc = Wave_Send(sink, n->a, n->b, n->c, n->d);
                n = n->next;
                if (rc >= 0)
                    goto loop;
            }
        }
    }
    return rc;
}
