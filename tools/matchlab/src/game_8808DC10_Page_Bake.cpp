// 0x8808DC10 (game module) — THE PAGE BAKE.
//
// Called from the per-quad sprite emitter (0x8808E298) with a PHASE derived from the quad's
// own packed texture id: 0 for ordinary art, 1..6 for the six 512x512 scroll-backdrop pages
// (texture ids 0x1D-0x1F and 0x3D-0x3F, two triplets = two rows).  Everything below runs only
// when the phase CHANGES, so the pages refresh incrementally as the scroll consumes them.
//
// Two halves:
//   1. BAKE   — resolve a 512-wide window of the live pane into each page's own texture
//               (plain Flags=0 resolves; src rect {x,0,x+512,512} clamped to the 640-wide pane).
//   2. PASTE  — bind each page texture and draw it back into the pane as a full-height strip
//               at x = 512*i, with the usual half-pixel bias.
//
// See decomp/game/NOTES_select_compose.md for the family write-up.
//
// NOTE ON THE GLOBALS BELOW.  The image addresses each cluster with ONE materialised base
// register plus literal displacements (e.g. `lwz r3,0x16C0(r31)` with r31 = 0x887ABF10).  Those
// displacements are NOT relocated, so the original compiler knew the distances at compile time:
// each cluster was either one object or a set of file-scope statics in one .bss section.  The
// field names come from the atlases (ATLAS_game_sprite_uv.md §5-6, ATLAS_select_compose.md) and
// every field carries its guest address so the layout stays auditable.
//
// ---------------------------------------------------------------------------------------
// MATCH STATUS (ppcmatch, XDK 9328 cl.exe; -O2 and "-O2 -Oc" give the identical 216 words):
// DIFF — 216/216 instructions, same frame
// (stwu r1,-0x1C0), same prologue/epilogue, same __savegprlr_19/__restgprlr_19 pair, same
// call order, same stack layout (rect@0x70, pageIds@0x80, verts@0xA0, resolve params@0x110).
// 146/216 words are positionally identical (48 → 130 → 146 over three legs).
//
// THE CEILING IS 190, NOT 216: 26 words carry a relocation, and our reloc fields are zero
// until link time, so those 26 can never be byte-equal under --check.  146/190 = 77%.
// ALL 44 remaining words are downstream of ONE unsolved fact — the nonvolatile priority of
// the float-pool base register (see (1) below).  There is no independent defect left.
//
// WHAT LANDED IN THE 2026-08-05 EVENING LEG (+16: 130 → 146)
//
//  (D) THE VERTEX INIT BLOCK RUNS BACKWARDS, verts[3] FIRST.  +12 words, free.
//      The image writes the z / colour / rhw fields in vertex order 3,2,1,0 (z at 0xFC, 0xE0,
//      0xC4, 0xA8, then the colour+rhw pairs at 0x104/0x100, 0xE8/0xE4, 0xCC/0xC8, 0xB0/0xAC).
//      Ours ran 0,1,2,3.  These stores are pure and independent, so the scheduler preserves
//      SOURCE order exactly — reversing the three statements flipped all twelve words in one
//      shot.  Note the u/v block that follows is FORWARD in both builds and already matched:
//      only the z/colour/rhw group is reversed.  Do not "tidy" it back into ascending order.
//
//  (E) THE BAKE CURSOR IS A STRENGTH-REDUCED IV, NOT A USER ACCUMULATOR.  +4 words.
//      Written as `bx = x; ... bx += PAGE_DIM;` MSVC emits the `mr` that seeds it BEFORE the
//      loop's zero-trip guard, and orders the three loop-latch increments i, bx, rec.  The
//      image seeds it AFTER the guard, in the preheader (insn 58 `mr r29,r30`), and increments
//      i, rec, bx.  Writing `u32 bx = i * PAGE_DIM;` inside the loop makes the compiler build
//      that induction variable itself: the seed moves into the preheader and the latch order
//      becomes the image's.  Same arithmetic (i*512 == the running sum), fewer source moving
//      parts.  `bx = x + i*PAGE_DIM` and a function-scope `bx` are byte-identical to this.
//
// WHAT LANDED IN THE EARLIER 2026-08-05 LEG:
//
//  (A) THE SPRITE-BATCH CLUSTER IS ANCHORED ON quadCount.  +35 words, the single biggest win.
//      The old note below claimed "no single object can produce that" because a struct always
//      anchors at offset 0 — true, but the anchor does not have to be the whole cluster.
//      Declaring SpriteBatchTail (just quadCount, at 0x887398CC) and overlaying the four older
//      caches BELOW it reproduces the image exactly: `lis`+`addi` to &quadCount, the quadCount
//      store folded into the lis form, and -0x2C/-0x28/-8/-4 for the rest.  It also fixes the
//      store ORDER (the image emits quadCount first; anchoring at offset 0 emitted it last)
//      and drops one dead `mr` that our old shape carried.
//
//  (B) THE PERENNIAL ZERO IS THE PASTE CURSOR — one live range, not two.  +14 words.
//      In the image r30 is `li r30,0` at insn 7 and is still the same range at insn 198's
//      `addi r30,r30,512`.  Writing the paste cursor as `left = i * PAGE_DIM` makes MSVC build
//      a fresh induction variable initialised by `mr` from the zero register, and that copy
//      never coalesces.  Giving the bake loop its own cursor (`bx`) and letting the perennial
//      zero `x` be the paste accumulator removes the copy.  `x = 0;` must be a STATEMENT after
//      the early return, not a declaration initialiser — as an initialiser it is worth 2 words
//      less (99 vs 97 at the time it was measured; still -2 today).
//      ⚠ REFINED BY (E): the bake loop's own cursor must be a FUNCTION OF i, not an accumulator.
//      And the "one live range, not two" half of (B) is no longer load-bearing — splitting the
//      setup zero from the paste cursor into two source locals is now byte-identical, because
//      MSVC coalesces them.  Only the "don't derive the PASTE cursor from i" half still bites.
//
//  (C) TWO halfPixel LOCALS DEFEAT THE fsubs CSE.  +31 words, and it is what restores the
//      216-instruction count so the whole tail realigns.  The image computes
//      `(float)left - halfPixel` FOUR times (insns 181/183/185/187, four identical encodings
//      ed0af828/eceaf828/ecc9f828/eca9f828 into f8/f7/f6/f5) while sharing the two int->float
//      conversions.  Binding verts[2]/verts[3] to a SECOND local that reads the same ROM float
//      reproduces it byte-for-byte: MSVC still merges the two loads into one `lfs` (3 lfs
//      total, as in the image) but keeps two value numbers for the subtract.  This also fixes
//      the FP allocation for free — halfPixel now carries 4 references and earns f31, with
//      f30 paneBottom and f29 paneTop, exactly the image.  The duplicate local is a modelling
//      device, not a behavioural change: same address, same value, same emitted load.
//
// WHAT STILL DIFFERS — ALL OF IT IS ONE FACT:
//
//  (1) THE FLOAT-POOL BASE IS ONE PRIORITY SLOT FROM THE TOP IN OUR BUILD AND SEVENTH IN THE
//      IMAGE.  Every remaining word follows from this.  Ten of thirteen nonvolatiles already
//      match (r31 gfx, r29 bakeX/pasteRec, r28 i, r24 firstPage, r23 fmt, r22 512, r21 page
//      table, r20 640, r19 phase); the rest rotate:
//          ours  priority [gfx, POOL, bakeX, zero, i,       bakeRec, pageCount, firstPage, …]
//          image priority [gfx, zero, bakeX, i,    bakeRec, pageCount, POOL,    firstPage, …]
//      MECHANISM (reproduces BOTH maps exactly, so trust it): the allocator sorts live RANGES
//      by priority and gives each the HIGHEST register free over its whole extent, so one
//      register can host several disjoint ranges (bakeX+pasteRec share r29 in both builds;
//      pool+pasteRec share r30 in ours).  Hand it either list above and the byte-level map
//      falls out.  Note (E) already moved `zero` up one slot, past `i`.
//
//      WHAT IS NOW KNOWN ABOUT THE POOL'S RANK (measured this leg, not theorised):
//        * It IS reference-count sensitive.  Strip the pool to two displacement-accesses and
//          the base falls from r30 to r25 — the image's own register.  Four accesses puts it
//          at r29.  Five (our count, and the image's) puts it at r30.
//        * An address-base reference therefore weighs roughly 3x an ordinary value reference:
//          6 base references outrank `zero`'s ~18 weighted ones, while 5 do not outrank 11.
//        * Reference count alone cannot be the whole story, because our access pattern and the
//          image's are IDENTICAL (same five loads, offsets 0, 4, 0x3C, 0x48, 0x4C, all at loop
//          depth 0) — the instruction multisets are equal by construction.  The difference is
//          in the IR the compiler was handed, not in any statistic of what it emitted.
//        * ✅ BLOCK FREQUENCY WAS THE RIGHT SUSPECT, AND IT IS NOW SETTLED — see the long note
//          on the paste loop below.  The loads belong INSIDE a source `if (pageCount != 0)`,
//          whose compare fuses into the `addic.` record form, so the guard costs NOTHING; the
//          earlier "+3 instructions" measurement came from pairing the `if` with an upcount
//          `for`, which MSVC then re-guards.  Paired with a COUNTDOWN do/while it is free.
//          Conditional placement demotes the pool r30 → r29 — one slot toward the image's r25 —
//          so frequency does discount rank, but placement alone is NOT sufficient and the rest
//          of the rank arithmetic still has no source lever.  LICM is ruled out three ways
//          (`extern const`, internal-linkage `static`, `__declspec(noalias)` on the callees):
//          nothing hoists a load into the preheader on this cl, which is precisely why the
//          loads must be source-placed.
//
//  (2) THE TWO SCHEDULING SCRAMBLES ARE PURE KNOCK-ON, CONFIRMED THIS LEG.  insns 28-49 (the
//      setup block) and 150-158 (the paste preheader).  The image materialises the four address
//      bases in exactly SOURCE order — batch, pool, blend-control, pageIds, page table — and
//      ours does not, because our `one` load lands at 53 instead of 44 and the scheduler puts
//      each base next to its first use.  Ten statement-order permutations of that block were
//      tried (see RULED OUT); every one was inert or worse.  It falls out with (1) or not at
//      all.  Same for 150-158: identical instructions, wrong side of the beq.
//
// RULED OUT — DO NOT RE-RUN (this leg, on top of everything the earlier legs ruled out):
//   * "Hoist g_c.zero into a local to starve the pool base" (the register-rule's EDIT 2): INERT.
//     The premise is false.  MSVC already CSEs all eight `g_c.zero` reads into ONE `lfs`, so
//     the pool base carries exactly 6 machine references — identical to the image's r25.  There
//     is no count defect to fix; measure the .cod, not the source text.
//   * fsubs duplication, 7 spellings before (C) worked: named conversion temps; `x`/`x+PAGE_DIM`
//     inline; the image's own store order (v0,v2,v1,v3); redundant casts; three inlined-helper
//     shapes (float param, int param, combined x+y setter); stores through a `PaneVertex*`;
//     four named float temps; all four y stores before all four x stores.
//   * `x = 0` placement: declaration initialiser first / last, statement after the early return,
//     statement after SpriteBatch_Flush (the two statement forms tie and win by 2).
//   * `float one = g_c.one;` placement: before/after the g_lastBlendControl poke (tie), before
//     the batch pokes (adds 2 instructions and scrambles everything), after pageCount, after
//     firstPage — all inert or worse.
//   * bake-loop init order: `bx = x;` then `for(i=0;...)`, `for (i = 0, bx = x; ...)`,
//     `i = 0; bx = x; for(;...)` — all identical.  `bx = 0;` instead of `bx = x;` — identical.
//   * Passing `x` for the Resolve's integer zero arguments (Flags/DestLevel/DestSliceOrFace):
//     inert; MSVC rematerialises `li rN,0` for call arguments in both builds anyway.
//   * Declaration order of `x` vs `bx`; declaring `one` up top and assigning later: inert.
//   * Loading paneBottom/paneTop/halfPixel up front or in the bake preheader instead of just
//     before the paste loop: CATASTROPHIC (4/216).  Their current position is load-bearing.
//   * Swapping the paneBottom/paneTop load order: -4 words.  Current order is correct.
//
// RULED OUT — 2026-08-05 EVENING LEG (46 measured variants; all numbers are `same=`/216
// against the 146 baseline, so anything at 146 is inert and anything below it is worse):
//   * THE FLOAT POOL IS NOT A COMPILER LITERAL POOL.  Spelling the five constants as literals
//     (1.0f / 0.0f / 0.5f / -0.5f / 511.5f) gives 47: this cl emits a SEPARATE `lis` + `lfs`
//     for every distinct float literal and never builds a shared pool base.  The image's one
//     base with displacements 0/4/0x3C/0x48/0x4C therefore has to be a named object (or a run
//     of file-scope statics), which is exactly what GfxConstants models.  Whole class closed.
//   * Pool spelling: `const GfxConstants*` local (142/146, inert), non-const g_c (inert),
//     `static const` definition with initialisers (3 — MSVC folds the values and deletes the
//     loads), non-const `static` (inert), file-scope reference (18), flat `extern const float
//     g_cf[]` with constant indices (inert).
//   * Promoting `zero`: four inline `x`/`x+PAGE_DIM` references instead of left/right (inert),
//     `right = left + PAGE_DIM` (inert), passing `x` for the SetVertexDeclaration /
//     SetBlendState / AlphaTestEnable zero arguments (inert — all rematerialised), splitting
//     the setup zero from the paste cursor into two locals (inert; finding (B) is now moot,
//     MSVC coalesces them either way), `x = right` instead of `x += PAGE_DIM` (19).
//   * Declaration order: all six permutations of `i`/`bx`/`x`, scalars before the aggregates,
//     `x` declared first of all — every one byte-identical.  Global-regime, as ALLOCATOR.md
//     predicts; stop tuning declarations in this function.
//   * Loop shape: `i != pageCount` (145), explicit `if (…) { … do … while }` in MSVC's own
//     rotated form (218/217 — the redundant guard always costs at least one instruction),
//     guardless `do/while` (52), countdown paste loop over firstPage (90), bake record walked
//     as a `PageRecord*` instead of an index (20), `bx = i << 9` instead of `i * PAGE_DIM` (50).
//   * Setup-block statement order: blend-control poke moved last (inert) or first (143),
//     pageIds built by seven assignments instead of an initialiser (132), quadCount store moved
//     to the end of the poke run (21 — re-confirms finding (A)'s anchor), `one` loaded between
//     the batch pokes (23), `one` after firstPage (inert), a `lastPhase` local feeding both
//     pageCount and firstPage (inert), firstPage computed before pageCount (inert), separate
//     locals for the paste half's pageCount/firstPage (inert), `x`/`i` typed `int` (inert).
//   * Splitting g_c so a field gets its own symbol always costs instructions: `one` alone (89),
//     `zero` alone (53), the three paste floats alone (20), all five alone (29).
// ---------------------------------------------------------------------------------------

typedef unsigned int   u32;
typedef unsigned long  DWORD;
typedef unsigned char  u8;

struct D3DDevice;
struct D3DBaseTexture;
struct D3DVertexShader;
struct D3DPixelShader;
struct D3DVertexDeclaration;
struct D3DVECTOR4;

struct D3DRECT  { long x1, y1, x2, y2; };
struct D3DPOINT { long x, y; };

struct D3DRESOLVE_PARAMETERS
{
    u32 ColorFormat;    // 0x00 — packed Xenos texture format for the resolve destination
    int ColorExpBias;   // 0x04
    u32 DepthFormat;    // 0x08 (not written here — this is a colour-only resolve)
};

// ---------------------------------------------------------------------------------------
// Guest globals
// ---------------------------------------------------------------------------------------

// Page-record table, 0x887518D0, 0x200 records of 0x14 bytes.  0x8808D838 keeps `tex` alive,
// 0x8808DF70 streams the initial art in through `srcBuf`.
struct PageRecord
{
    D3DBaseTexture* tex;        // 0x00
    u32             sizeState;  // 0x04  — 1 or 2; the texture is (sizeState << 8) square
    u32             srcBuf;     // 0x08  — CPU staging buffer for the streamed art
    u32             state;      // 0x0C
    u32             spare;      // 0x10
};
extern PageRecord g_pageRecords[0x200];             // 0x887518D0

// The renderer block.  Base 0x887ABF10.
struct GameGfx
{
    u32 lastBlendConstant;                          // 0x0000 = 0x887ABF10
    u8  _gap0[0x16C0 - 0x0004];
    D3DDevice* pDevice;                             // 0x16C0 = 0x887AD5D0
    u8  _gap1[0x16D0 - 0x16C4];
    D3DPixelShader*  psBackdrop;                    // 0x16D0 = 0x887AD5E0
    D3DVertexShader* vsBackdrop;                    // 0x16D4 = 0x887AD5E4
    u8  _gap2[0x16E0 - 0x16D8];
    u32 lastBakePhase;                              // 0x16E0 = 0x887AD5F0 — the bake gate
    u8  _gap3[0x16E8 - 0x16E4];
    D3DPixelShader*  psSprite;                      // 0x16E8 = 0x887AD5F8 — the sprite pair
    D3DVertexShader* vsSprite;                      // 0x16EC = 0x887AD5FC   restored on the way out
};
extern GameGfx g_gfx;                               // 0x887ABF10

// The sprite batcher's redundancy caches, 0x887398A0..0x887398CC (0x88070000 gates every
// per-draw state write on these).  Poisoning them to -1 is what forces 0x88070000 to reprogram
// everything after the bake has trampled the pipeline.
//
// ANCHORED THE WAY THE IMAGE ANCHORS IT — see note (A) in the match status.  The image
// materialises ONE base for this cluster and that base is the LAST field, 0x887398CC quadCount;
// the four older caches are reached at negative displacements (-0x2C, -0x28, -8, -4).  A plain
// struct always anchors at offset 0, so the anchor is declared on its own and the older caches
// are overlaid below it.  Same addresses as the flat struct this replaced; the only difference
// is which end the compiler puts the base register on.
struct SpriteBatchTail
{
    u32 quadCount;                                  //  0x00 = 0x887398CC — the anchor
};
extern SpriteBatchTail g_batchTail;                 // 0x887398CC

struct SpriteBatchCaches
{
    u32 lastTexSlot;                                // -0x2C = 0x887398A0
    u32 lastColour;                                 // -0x28 = 0x887398A4
    u8  lock[0x1C];                                 // -0x24 = 0x887398A8 — critical section
    u32 lastAlphaState;                             // -0x08 = 0x887398C4
    u32 lastRenderState;                            // -0x04 = 0x887398C8
};
#define g_batch (*(SpriteBatchCaches*)((u8*)&g_batchTail - 0x2C))

extern u32 g_lastBlendControl;                      // 0x8869989C — cached RB_BLENDCONTROL

// The ROM float pool.  Base 0x88063370; every value below was read straight out of the image.
// paneTop/paneBottom/halfPixel give the paste-back strip the usual half-pixel bias: the quad
// spans x = [512*i - 0.5, 512*i + 511.5] and y = [-0.5, 511.5], i.e. exactly 512x512 texels.
struct GfxConstants
{
    float one;                                      // 0x00 = 0x88063370   1.0f
    float zero;                                     // 0x04 = 0x88063374   0.0f
    float _unused0[13];                             // 0x08 .. 0x38
    float halfPixel;                                // 0x3C = 0x880633AC   0.5f
    float _unused1[2];                              // 0x40, 0x44
    float paneTop;                                  // 0x48 = 0x880633B8  -0.5f
    float paneBottom;                               // 0x4C = 0x880633BC   511.5f
};
extern const GfxConstants g_c;                      // 0x88063370

// ---------------------------------------------------------------------------------------
// Callees
// ---------------------------------------------------------------------------------------

extern "C" void SpriteBatch_Flush();                                        // 0x880702B0
extern "C" int  Page_EnsureTexture(u32 pageId, u32 sizeState);              // 0x8808D838

extern "C" void D3DDevice_SetRenderState_AlphaTestEnable(D3DDevice* pDevice, DWORD Value);
extern "C" void D3DDevice_SetVertexShader(D3DDevice* pDevice, D3DVertexShader* pShader);
extern "C" void D3DDevice_SetPixelShader(D3DDevice* pDevice, D3DPixelShader* pShader);
extern "C" void D3DDevice_SetVertexDeclaration(D3DDevice* pDevice, D3DVertexDeclaration* pDecl);
extern "C" void D3DDevice_SetBlendState(D3DDevice* pDevice, DWORD RenderTargetIndex,
                                        DWORD BlendState);
extern "C" void D3DDevice_SetTexture(D3DDevice* pDevice, DWORD Sampler,
                                     D3DBaseTexture* pTexture, unsigned __int64 PendingMask3);
extern "C" void D3DDevice_DrawVerticesUP(D3DDevice* pDevice, int PrimitiveType,
                                         unsigned VertexCount, const void* pVertexStreamZeroData,
                                         unsigned VertexStreamZeroStride);
extern "C" void D3DDevice_Resolve(D3DDevice* pDevice, DWORD Flags, const D3DRECT* pSourceRect,
                                  D3DBaseTexture* pDestTexture, const D3DPOINT* pDestPoint,
                                  unsigned DestLevel, unsigned DestSliceOrFace,
                                  const D3DVECTOR4* pClearColor, float ClearZ,
                                  DWORD ClearStencil,
                                  const D3DRESOLVE_PARAMETERS* pParameters);

// ---------------------------------------------------------------------------------------

// The paste-back quad's vertex — the same 0x1C-byte layout the per-frame backdrop quad uses.
struct PaneVertex
{
    float x;        // 0x00
    float y;        // 0x04
    float z;        // 0x08
    float rhw;      // 0x0C
    u32   colour;   // 0x10
    float u;        // 0x14
    float v;        // 0x18
};

enum
{
    PAGE_DIM        = 0x200,        // pages are 512x512
    PAGE_SIZE_STATE = 2,            // 0x8808D838 encodes the dimension as sizeState << 8
    PANE_WIDTH      = 0x280,        // the live pane is 640 wide; the second page runs off it
    PAGE_FORMAT     = 0x18280143,   // packed Xenos format the pages are created with
    QUAD_COLOUR     = 0xFF808080,   // 0x80 = 1.0 under the game's 2/255 colour convention
    BLEND_STATE     = 0x00010001,   // RB_BLENDCONTROL: straight copy, no blending
    PRIM_TRIANGLESTRIP = 6,         // D3DPT_TRIANGLESTRIP — the 360 enum swaps FAN/STRIP vs PC
                                    // (d3d9types.h:465).  NOTES_select_compose.md calls this
                                    // "6=rectlist"; RECTLIST is 8.  The UVs (0,0)(1,0)(0,1)(1,1)
                                    // confirm a strip, not a fan and not a rect list.
    PAGE_ID_POISON  = 0xFFFFFFFF
};

// Texture is bound for the pixel shader only (PendingMask3 bit 31).
#define TEX_PENDING_MASK 0x80000000

// THE PASTE HALF IS AN INLINED HELPER, NOT OPEN CODE.  References inside a LOOP-BEARING inlinee
// are rank-discounted by the allocator: this is what finally lifts the perennial zero to r30 (the
// image's rank 2) and bakeX to r29, and demotes the pool base.  Straight-line inlinees get NO
// discount (measured), and this cl REFUSES to auto-inline a looping callee (the call stays
// outlined, 166 insn), so __forceinline is mandatory rather than cosmetic.
// The latch order `++i` THEN `x += PAGE_DIM` is load-bearing: the scheduler keeps source order for
// the two latch addis, and the image increments the record cursor before the paste cursor.
static __forceinline void Page_PasteStrips(u32 x, u32 firstPage, u32 n, PaneVertex* verts)
{
    float paneBottom = g_c.paneBottom;
    float paneTop    = g_c.paneTop;
    float halfPixel  = g_c.halfPixel;
    float halfPixel2 = g_c.halfPixel;
    u32 i = 0;
    do
    {
        D3DBaseTexture* tex = g_pageRecords[firstPage + i].tex;
        if (tex != 0)
        {
            u32 left  = x;
            u32 right = x + PAGE_DIM;

            verts[0].x = (float)left  - halfPixel;   verts[0].y = paneTop;
            verts[1].x = (float)right - halfPixel;   verts[1].y = paneTop;
            verts[2].x = (float)left  - halfPixel2;  verts[2].y = paneBottom;
            verts[3].x = (float)right - halfPixel2;  verts[3].y = paneBottom;

            D3DDevice_SetTexture(g_gfx.pDevice, 0, tex, TEX_PENDING_MASK);
            D3DDevice_DrawVerticesUP(g_gfx.pDevice, PRIM_TRIANGLESTRIP, 4, verts,
                                     sizeof(PaneVertex));
        }
        ++i;
        x += PAGE_DIM;
    } while (--n != 0);
}

void Page_Bake(u32 phase)
{
    D3DRECT rect;
    u32 pageIds[7] = { 0, 0x1D, 0x1E, 0x1F, 0x3D, 0x3E, 0x3F };
    PaneVertex verts[4];
    D3DRESOLVE_PARAMETERS rp;
    u32 i;
    u32 x;

    if (g_gfx.lastBakePhase == phase)
        return;

    x = 0;

    // Drain whatever the sprite batcher has queued: the bake reprograms the pipeline.
    SpriteBatch_Flush();

    g_gfx.lastBlendConstant  = PAGE_ID_POISON;
    g_batchTail.quadCount    = 0;
    g_batch.lastColour       = PAGE_ID_POISON;
    g_batch.lastTexSlot      = PAGE_ID_POISON;
    g_batch.lastRenderState  = PAGE_ID_POISON;
    g_batch.lastAlphaState   = PAGE_ID_POISON;

    // 1.0f serves twice: as the resolve's ClearZ and as the paste-back quad's rhw / far UVs.
    // The image materialises the float-pool base and takes this load BEFORE the blend-control
    // poke, which is what fixes the order the four address bases come up in.
    float one = g_c.one;

    g_lastBlendControl       = 0x01010101;

    // Phase 0 owns page id 0 AND the first backdrop page, so it bakes two; every other phase
    // owns exactly one.
    u32 pageCount = (g_gfx.lastBakePhase == 0) + 1;
    u32 firstPage = pageIds[g_gfx.lastBakePhase];

    // --- 1. BAKE: resolve the pane window that belongs to each page into that page ---------
    // `bx` must be written as a function of `i`, not as an accumulator seeded before the loop:
    // that is what makes MSVC build the induction variable itself and seed it in the PREHEADER,
    // the way the image does.  See finding (E).
    for (i = 0; i < pageCount; ++i)
    {
        u32 bx = i * PAGE_DIM;
        if (Page_EnsureTexture(firstPage + i, PAGE_SIZE_STATE))
        {
            rp.ColorFormat  = PAGE_FORMAT;
            rp.ColorExpBias = x;

            rect.x1 = bx;
            rect.y1 = x;
            rect.x2 = bx + PAGE_DIM;
            rect.y2 = PAGE_DIM;
            if (rect.x1 > PANE_WIDTH) rect.x1 = PANE_WIDTH;
            if (rect.x2 > PANE_WIDTH) rect.x2 = PANE_WIDTH;

            D3DDevice_Resolve(g_gfx.pDevice, 0, &rect, g_pageRecords[firstPage + i].tex,
                              0, 0, 0, 0, one, x, &rp);
        }
    }

    // --- 2. PASTE: draw the pages back into the pane ---------------------------------------
    // BACKWARDS ON PURPOSE, verts[3] FIRST — the image's store order, and these stores are
    // independent so the scheduler keeps source order verbatim.  Finding (D); reversing this
    // group back to 0,1,2,3 costs twelve words.  The u/v group below is FORWARD in the image.
    verts[3].z = g_c.zero;  verts[2].z = g_c.zero;  verts[1].z = g_c.zero;  verts[0].z = g_c.zero;
    verts[3].colour = QUAD_COLOUR;  verts[2].colour = QUAD_COLOUR;
    verts[1].colour = QUAD_COLOUR;  verts[0].colour = QUAD_COLOUR;
    verts[3].rhw = one;  verts[2].rhw = one;  verts[1].rhw = one;  verts[0].rhw = one;
    verts[0].u = g_c.zero;  verts[0].v = g_c.zero;
    verts[1].u = one;       verts[1].v = g_c.zero;
    verts[2].u = g_c.zero;  verts[2].v = one;
    verts[3].u = one;       verts[3].v = one;

    g_gfx.lastBakePhase = phase;

    D3DDevice_SetRenderState_AlphaTestEnable(g_gfx.pDevice, 0);
    D3DDevice_SetVertexShader(g_gfx.pDevice, g_gfx.vsBackdrop);
    D3DDevice_SetPixelShader(g_gfx.pDevice, g_gfx.psBackdrop);
    D3DDevice_SetVertexDeclaration(g_gfx.pDevice, 0);
    D3DDevice_SetBlendState(g_gfx.pDevice, 0, BLEND_STATE);

    pageCount = (g_gfx.lastBakePhase == 0) + 1;
    firstPage = pageIds[g_gfx.lastBakePhase];

    if (pageCount != 0)
        Page_PasteStrips(x, firstPage, pageCount, verts);

    // Hand the pipeline back to the sprite batcher.
    D3DDevice_SetRenderState_AlphaTestEnable(g_gfx.pDevice, g_gfx.lastBakePhase == 0);
    D3DDevice_SetPixelShader(g_gfx.pDevice, g_gfx.psSprite);
    D3DDevice_SetVertexShader(g_gfx.pDevice, g_gfx.vsSprite);
}
