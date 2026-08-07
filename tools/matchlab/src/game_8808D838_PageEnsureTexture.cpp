// 0x8808D838 (game module) — scroll-cache PAGE TEXTURE ENSURE.
//
// NOTES_select_compose.md: the thing the 08-03/08-04 hunt kept calling "the page state machine"
// is just this function. It guarantees page `pageId` has a live texture of the requested size,
// recreating it when the size changed.
//
// The page table is a FLAT u32 array of 0x200 records, 5 words each, at 0x887518D0:
//     [id*5 + 0] tex        D3D texture handle (0 = none)
//     [id*5 + 1] sizeState  1 or 2; the texture is (sizeState << 8) square, so 2 => 512x512
//     [id*5 + 2] srcBuf     CPU staging buffer the streamed art arrives in (0x8808DF70 uses it)
//     [id*5 + 3] state      fill state flag
//     [id*5 + 4] spare
// It is written as an ARRAY, not as `Record* r = &tbl[id]`: the original computes the element
// index (id*5, then <<2) and uses indexed loads off hoisted bases, which is what tell #13
// predicts for flat-array access and what a struct-pointer form does NOT produce.
//
// EXTENT: 50 instructions. The boundary table says 53 because a 3-instruction leaf follows at
// 0x8808D900 with no .pdata record; ppcmatch accepts 50 because nothing in this body can branch
// into that tail (split-UNREACHABLE proof).
//
// The six 512x512 select-screen backdrop pages are sizeState 2 here, and the packed format word
// 0x18280143 is the same one the bake pass stores.

// PARKED at 35/50 (was 3/50; 41/50 once relocated words are masked).  The length is now right and both ends match exactly:
// instructions 0-25 and 42-49 are byte-identical, including the prologue's __savegprlr_26,
// the -0x90 frame, and the shared-zero epilogue.
//
// (A) THE SHARED ZERO IS A SINGLE-EXIT RESULT VARIABLE, not a hoisted constant.  +25 words.
//     The image's extra word is `li r26,0` at +4, a zero in a NONVOLATILE reused by both
//     `tbl[tex] = 0` and the `return 0` exit (`mr r3,r26` at +47).  Declaring a `u32 zero = 0`
//     local and using it in those places does NOT produce it -- MSVC constant-propagates and
//     rematerialises, and the function stays 49 instructions, whatever the declaration order
//     (8 spellings measured, all 3/50).  What DOES produce it is restructuring the function
//     around a single `result` variable initialised to 0, returned once at the end, with the
//     range checks inverted into one positive `if`.  Then the zero is a real value with a live
//     range spanning every branch, it earns r26, and the frame grows to 0x90 to save it.
//     This is the same pattern as Page_Bake's perennial zero, and it is worth restating as a
//     rule: A ZERO ONLY EARNS A NONVOLATILE WHEN IT IS A VARIABLE THE FUNCTION CARRIES, NOT
//     WHEN IT IS A CONSTANT THE FUNCTION SPELLS REPEATEDLY.
//
// (B) WHAT IS LEFT IS ONE ADDRESSING DECISION — and 2026-08-07 pinned it to THREE WORDS.
//     The image collapses base+index into a single register after the release block
//     (`add r30,r31,r30` at +26) and then uses offset form (`lwz r11,0(r30)` at +27,
//     `stw r3,0(r30)` at +40).  We keep indexed form (`lwzx`/`stwx`) and never emit the add.
//
//     ⚠ MEASUREMENT NOTE, because the tracked number misleads here: `same=` is POSITIONAL and
//     is NOT reloc-masked.  This body is 50 instructions and scores 35/50, but 41 of its 50
//     words are actually right once the six relocated words are masked.  A body that is one
//     instruction SHORT scores far worse than that gap deserves, because everything after the
//     short point shifts.  Judge these two by mismatched-word count, not by `same=`.
//
//     ★ SEE THE SIBLING game_8808D838_PageEnsureTexture_ptr.cpp: 49 instructions, `same=` only
//     19, but **three mismatched words against this file's nine**, and instructions 0-25 are
//     byte-identical.  Two directed edits got it there — the release argument written as the
//     SAME EXPRESSION as its guard (which kills this file's extra `mr r3,r11` at +24), and the
//     slot pointer born after the release block.  That file carries the residue and the full
//     ruled-out list; this one stays canonical only because 35 is the honest positional score
//     and the gate must not over-report.
//
//     RULED OUT for producing the add — do not re-run: eight pointer spellings (&arr[i+TEX],
//     arr+i+TEX, arr+i with tex[TEX], &arr[i] with tex[0], an idx local, `u32* const`, a byte
//     cast), all byte-identical; a PageRecord* over the u32 array; the table redeclared as
//     `extern PageRecord g_pageRecs[]`; early-return forms of the create block; the pointer used
//     exactly twice with the success test on the RETURNED value; and the create block extracted
//     into a helper taking `u32* slot` as `static __forceinline`, `static inline` and plain
//     `static` — all three fold the pointer straight back to indexed.  Flags are not the lever
//     on either shape.
//     ⚠ And note the image's form is one instruction WORSE (`lwzx` needs no add), so this cannot
//     be reached by making the code better; it is a back-end addressing choice.
//     => Same class as Driver_SendStageRecord's store slot.  Attack it with a model, not syntax.

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
    // `result` is the shared zero of finding (A): one variable, one exit, so it earns r26.
    u32 result = 0;
    u32 dim = (sizeState & 0xFFFFFF) << 8;

    if (pageId < PAGE_COUNT && sizeState != 0 && sizeState <= 2)
    {
        u32* tex = &g_pageTable[pageId * PAGE_STRIDE + PAGE_TEX];

        // A size change invalidates the existing texture.
        if (g_pageTable[pageId * PAGE_STRIDE + PAGE_SIZESTATE] != sizeState &&
            g_pageTable[pageId * PAGE_STRIDE + PAGE_TEX] != 0)
        {
            Gpu_ReleaseTexture(*tex);
            g_pageTable[pageId * PAGE_STRIDE + PAGE_TEX] = result;
        }

        tex = &g_pageTable[pageId * PAGE_STRIDE + PAGE_TEX];
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
