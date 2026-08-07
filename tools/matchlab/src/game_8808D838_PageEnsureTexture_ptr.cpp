// 0x8808D838 (game) — Page_EnsureTexture, SAME-EXPRESSION / POINTER VARIANT.
//
// Sibling of game_8808D838_PageEnsureTexture.cpp, which stays canonical. Read the numbers before
// judging which is better, because the tracked metric inverts them:
//
//                       insn   same=   mismatched words vs the guest
//   canonical            50     35            9
//   this file            49     19            3
//
// `same=` is POSITIONAL, so being one instruction short misaligns everything after it and the
// score collapses. Measured properly, this body is the closer of the two by a factor of three.
//
// TWO EDITS GOT IT THERE, both directed rather than swept:
//   1. The release argument uses the SAME EXPRESSION as its guard —
//      `Gpu_ReleaseTexture(g_pageTable[... + PAGE_TEX])`, not `*tex`. The guard and the argument
//      then share one load, which the compiler puts straight in r3, and the canonical body's
//      extra `mr r3,r11` at +24 disappears. **Instructions 0-25 are now byte-identical.**
//   2. The slot pointer is BORN AFTER the release block, matching where the image forms it.
//
// ⏭ WHAT IS LEFT IS THREE WORDS, AND THEY ARE ONE DECISION: the image collapses base+index into
// an address (`add r30,r31,r30` at +26) and then uses OFFSET form (`lwz r11,0(r30)` at +27,
// `stw r3,0(r30)` at +40); we keep INDEXED form (`lwzx`/`stwx`) and never emit the add. Every
// other word from +26 to the end matches under a single insertion.
//
// ⚠ The image's form is one instruction WORSE — `lwzx` needs no add — so this is not something
// the optimiser can be argued into by making the code better. RULED OUT, do not re-run: the
// eight pointer spellings listed in the canonical file; pointer used exactly twice (load+store)
// with the success test on the returned value rather than a reload; the create-and-store block
// extracted into a helper taking `u32* slot`, as `static __forceinline`, `static inline` and
// plain `static` (all three fold the pointer straight back to indexed); flag matrix
// -O2 -Oc == -Ox -Oc == -Ou == -Ob0 == -Op == -Oy- (all 49/19).
//
// ⇒ Same class as Driver_SendStageRecord's store slot: a back-end addressing choice source shape
// does not reach. The difference is that the residue here is now exactly three words and named,
// so if the addressing decision is ever cracked this function goes straight to EXACT.

typedef unsigned int u32;

// 0x887518D0 — 0x200 records x 5 words.
extern u32 g_pageTable[];

enum {
    PAGE_TEX        = 0,
    PAGE_SIZESTATE  = 1,
    PAGE_STRIDE     = 5,
    PAGE_COUNT      = 0x200,
    PAGE_FORMAT     = 0x18280143
};

// 0x8807F8C8 — release a texture object.
extern "C" void Gpu_ReleaseTexture(u32 tex);

// 0x88079970 — CreateTexture(width, height, levels, ?, ?, packedFormat, ?, pool).
extern "C" u32 Gpu_CreateTexture(u32 w, u32 h, u32 levels, u32 a4, u32 a5,
                                 u32 packedFormat, u32 a7, u32 pool);

u32 Page_EnsureTexture(u32 pageId, u32 sizeState)
{
    u32 result = 0;
    u32 dim = (sizeState & 0xFFFFFF) << 8;

    if (pageId < PAGE_COUNT && sizeState != 0 && sizeState <= 2)
    {
        if (g_pageTable[pageId * PAGE_STRIDE + PAGE_SIZESTATE] != sizeState &&
            g_pageTable[pageId * PAGE_STRIDE + PAGE_TEX] != 0)
        {
            Gpu_ReleaseTexture(g_pageTable[pageId * PAGE_STRIDE + PAGE_TEX]);
            g_pageTable[pageId * PAGE_STRIDE + PAGE_TEX] = result;
        }

        u32* tex = &g_pageTable[pageId * PAGE_STRIDE + PAGE_TEX];
        if (*tex == 0)
            *tex = Gpu_CreateTexture(dim, dim, 1, 1, 0, PAGE_FORMAT, 0, 3);

        if (*tex != 0)
        {
            g_pageTable[pageId * PAGE_STRIDE + PAGE_SIZESTATE] = sizeState;
            result = 1;
        }
    }
    return result;
}
