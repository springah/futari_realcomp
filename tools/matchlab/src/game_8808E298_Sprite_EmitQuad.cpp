// 0x8808E298 (game module, base 0x88000000) — Sprite_EmitQuad — 116 instructions.
//
// The per-quad emitter of the 2D sprite engine, AND the bake-on-demand trigger described in
// decomp/game/NOTES_select_compose.md.  For every quad it:
//   1. decodes the packed source-atlas and destination coordinates,
//   2. derives the PAGE ID of the destination and, when that page is one of the six baked
//      512x512 backdrop pages, converts it to a bake PHASE (1..6) and calls the bake
//      (0x8808DC10) so the page is current before the quad is drawn — everything else
//      passes phase 0,
//   3. flushes / re-binds the batch when the quad's texture page, blend or attribute
//      flags differ from what the batch is bound to (or when the batch is full), and
//   4. appends three vertices (a rect list: top-left, top-right, bottom-left) to the ring.
//
// Caller: 0x8808E468 walks a 5-dword command list at 0x886998A0 and passes rec[0..4]
// straight through, under the critical section at 0x887398A8 (= this batch's `lock`).
//
// PARAMETERS (all five arrive in r3..r7 as 32-bit words):
//   attr    packed sprite attributes.  bits 0..25 = the batch "flags" word handed to
//           Sprite_SetBatchState; bits 26..27 = the mirror selector (bit26 flips V,
//           bit27 flips U); bits 28..31 unused here.
//   srcUV   source atlas coordinate: u in bits 16..28 (13 bits), v in bits 0..11.
//   dstXY   destination coordinate as two SIGNED shorts: x in the high half, y in the low.
//   extent  size minus one: (width-1) in the high half, (height-1) in the low half.
//   blend   blend mode; part of the batch key and passed on to Sprite_SetBatchState.
//
// ---------------------------------------------------------------------------------------
// MATCH STATUS  (ppcmatch --check, cl 15.00.8327, -O2):  DIFF 63/116 words identical.
// Every instruction is present, in the image's order, with the image's operands.  The ONLY
// residue is the permutation of the 11 nonvolatiles and, downstream of it, the schedule of
// the seven-instruction address/count prologue at idx 95..101.
//
//   image  r31 base   r30 flags  r29 w    r28 h     r27 texPage  r26 blend  r25 attr
//          r24 srcV   r23 srcU   r22 x0   r21 y0
//   ours   r31 flags  r30 w      r29 h    r28 base  r27 texPage  r26 x0     r25 y0
//          r24 attr   r23 blend  r22 srcV r21 srcU
//   -> three elementary moves: base to the top, x0/y0 to the bottom, blend above attr.
//
// The two builds agree on EVERY input the allocator can see: 116 instructions, the same 11
// nonvolatile definitions at the same instruction indices (3,4,8,14,19,20,21,29,31,40,41),
// the same live-range starts/ends/lengths, and the same per-value reference counts
// (base 8, w 6, h 6, x0 5, y0 5, and 3 each for flags, texPage, blend, attr, srcV, srcU).
// The image's order is NOT reference-count ordered (x0/y0 carry 5 refs yet sit at the bottom,
// below six values carrying 3), so no reference-count edit can produce it.
//
// LANDED THIS LEG (58 -> 63 words):
//   * The four switch bodies assign the PLAIN COPY of each axis before the +span one --
//     case 0/2 write vTop before vBottom, case 1/3 write vBottom before vTop, and case 2/3
//     write uRight before uLeft.  That fixes the emission order inside all four case blocks
//     (idx 72..88) AND the order of the four garbage loads in the switch's default block
//     (idx 90..93).  Independently checkable: the default-block load order is the reverse of
//     the compiler's stack-slot listing and tracks case 0's assignment order exactly.
//
// RULED OUT -- verified INERT (output byte-identical) on this build:
//   1. w/h, srcU/srcV, uLeft/uRight/vTop/vBottom declaration order (any permutation).
//   2. Declaration position decoupled from assignment ("u32 flags;" at the top, assigned in
//      place) -- declaration order is inert; only the emitted DEFINITION position matters.
//   3. Commutative operand order: w+u / h+v / w+x0 / h+y0 all canonicalise to the same
//      encoding.  The image's "add r5,w,x0" operand order is a CONSEQUENCE of its register
//      map, not a source property (ours emits ascending register order, the image descending).
//   4. First-block statement order: w/h first, dstX/dstY first, srcV before srcU, dstPage
//      before texPage.
//   5. Tail shape: no "q" temp (worse -- 124 insns), SpriteQuad& reference, g_spriteQuads + n,
//      a SpriteVertex* cursor, explicit "x1 = x0 + w" / "y1 = y0 + h" locals, and every
//      ordering of {q, count store, x1/y1} -- the tail schedule is a fixed point.
//   6. Types: int vs u32 params (int breaks the shifts), x0/y0 and w/h as u32, const locals,
//      "int n", volatile on the header fields.
//   7. Inline helpers (a PageOf(x,y) used for both page ids; a PutVert() for the stores).
//   8. Explicit base-pointer variables (SpriteQuad* ring = g_spriteQuads at the image's
//      definition point or before flags; a SpriteBatchHeader* anchor -- the last is much
//      worse, 24 words).
//   9. Redundant copies meant to perturb the allocator's worklist (copies of texPage, blend,
//      attr, x0/y0) -- all coalesced away with no effect on the map.
//  10. File-level context: extra externs, extra structs, one or two preceding dummy functions,
//      extern declaration order.  The map does not depend on anything outside the function.
//  11. Compiler knobs: -Ox, -Og, -O2 -Oy-, -O2 -Ob1, -O2 -Op all give the identical map
//      (-O1/-Oxs give 109 insns, -Ot gives 247).  The second XDK compiler on this box,
//      cl 15.00.8153 (xdk9328_ship), emits a BYTE-IDENTICAL function -- so the residue is not
//      a compiler-version artefact between those two.
//
// PROVEN LEVERS (the allocator is not blind, it is saturated here):
//   * Intra-pair rank follows the emitted definition order (earlier def -> higher register):
//     swapping the x0/y0 assignments inside BOTH branches swaps r26/r25.  That is the only
//     handle on the map found in ~50 source shapes, and it cannot move a value between groups.
//   * Moving a definition's emitted position DOES reorder the whole map (computing flags in
//     the first block sends it from r31 to r23 and drops x0/y0 to r22/r21) -- but that costs
//     the instruction schedule, so it is not usable here.
//
// NEXT: the residue is a group-level permutation with no source-reachable handle found.  It is
// semantically irrelevant (same instructions, same live ranges, same counts).  If it must be
// closed, the remaining unexplored input is the exact XDK compiler build the game shipped
// with -- neither 15.00.8327 nor 15.00.8153 produces it -- not the C++ source.
// ---------------------------------------------------------------------------------------

typedef unsigned int u32;

struct SpriteVertex          // 0x10 bytes
{
    u32 x;                   // 0x00
    u32 y;                   // 0x04
    u32 u;                   // 0x08
    u32 v;                   // 0x0C
};

struct SpriteQuad            // 0x30 bytes — rect list: top-left, top-right, bottom-left
{
    SpriteVertex v[3];
};

// The batch header sits immediately BEFORE the quad ring in memory.  The original code
// addresses the whole block from the ring's base with negative displacements
// (lis/addi -> r31 = 0x887398D0, then lwz -0x30/-0x2C/-8/-4(r31)), so the ring is the
// anchor symbol and the header is reached as element [-1] in front of it.
struct SpriteBatchHeader     // 0x30 bytes, at 0x887398A0
{
    u32 texPage;             // 0x00 = 0x887398A0  atlas page id the batch is bound to
    u32 blend;               // 0x04 = 0x887398A4  blend mode the batch is bound to
    u32 lock[8];             // 0x08 = 0x887398A8  critical section (0x8824EAD0 / 0x8824EAE0)
    u32 flags;               // 0x28 = 0x887398C8  attribute bits the batch is bound to
    u32 count;               // 0x2C = 0x887398CC  quads queued
};

extern SpriteQuad g_spriteQuads[0x800];                          // 0x887398D0
#define g_spriteBatch (((SpriteBatchHeader*)g_spriteQuads)[-1])

extern "C" void Sprite_FlushBatch(void);                                 // 0x880702B0
extern "C" void Sprite_SetBatchState(u32 texPage, u32 flags, u32 blend); // 0x88070000
extern "C" void Page_BakePhase(int phase);                               // 0x8808DC10

// The virtual canvas is a grid of 256x256 cells, 32 columns wide, so
//     page id = (y >> 8) * 32 + (x >> 8)   ==   ((y >> 3) & ~0x1F) | (x >> 8).
// The six baked backdrop pages occupy columns 0x1D..0x1F of rows 0 and 1, i.e. page ids
// 0x1D,0x1E,0x1F,0x3D,0x3E,0x3F — exactly the phase table in 0x8808DC10 — which map to
// phases 1..6 via row*3 + column - 0x1C.  Everything outside that window is phase 0 and
// is drawn at a -32,-32 bias instead of page-local coordinates.
#define PAGE_COL_SHIFT  8
#define PAGE_COL_MASK   0x1F
#define FIRST_BAKED_COL 0x1C
#define PAGES_PER_ROW   3
#define BAKED_PAGE_END  0x40
#define CANVAS_BIAS     0x20
#define MAX_BATCH_QUADS 0x800

void Sprite_EmitQuad(u32 attr, u32 srcUV, u32 dstXY, u32 extent, u32 blend)
{
    int srcU = (int)((srcUV >> 16) & 0x1FFF);
    int srcV = (int)(srcUV & 0xFFF);
    int dstX = (short)(dstXY >> 16);
    int dstY = (short)dstXY;

    int w = (int)(extent >> 16) + 1;
    int h = (int)(extent & 0xFFFF) + 1;

    u32 texPage = (u32)(((srcV >> 3) & ~PAGE_COL_MASK) | (srcU >> PAGE_COL_SHIFT));
    u32 dstPage = (u32)(((dstY >> 3) & ~PAGE_COL_MASK) | (dstX >> PAGE_COL_SHIFT));

    int phase;
    int x0, y0;
    if (dstPage < BAKED_PAGE_END && (dstPage & PAGE_COL_MASK) > FIRST_BAKED_COL)
    {
        // Destination is inside one of the six baked pages: the coordinates are
        // page-local and that page's bake phase has to be made current first.
        x0 = dstX & 0xFF;
        y0 = dstY & 0xFF;
        phase = (int)((dstPage >> 5) * PAGES_PER_ROW + (dstPage & PAGE_COL_MASK))
                - FIRST_BAKED_COL;
    }
    else
    {
        phase = 0;
        x0 = dstX - CANVAS_BIAS;
        y0 = dstY - CANVAS_BIAS;
    }
    Page_BakePhase(phase);

    // A quad can only join the batch if it wants the same texture page, blend and
    // attribute flags.  Sprite_FlushBatch() empties the ring, so `count` is re-read
    // after every call that can flush.
    u32 flags = attr & 0x3FFFFFF;
    u32 n;
    if (g_spriteBatch.texPage == texPage && g_spriteBatch.blend == blend &&
        g_spriteBatch.flags == flags)
    {
        n = g_spriteBatch.count;
        if (n >= MAX_BATCH_QUADS)
        {
            Sprite_FlushBatch();
            n = g_spriteBatch.count;
        }
    }
    else
    {
        Sprite_FlushBatch();
        Sprite_SetBatchState(texPage, flags, blend);
        n = g_spriteBatch.count;
    }

    // Mirror selector: attr bit 26 flips the V span, bit 27 flips the U span.
    // Each case assigns the plain copy of an axis before the +span one; that order is what
    // the image's per-case emission order and default-block load order encode.
    u32 u = (u32)(srcU & 0xFF);
    u32 v = (u32)(srcV & 0xFF);
    u32 uLeft, uRight, vTop, vBottom;
    switch ((attr >> 26) & 3)
    {
    case 0:     // no mirror
        uLeft = u; uRight = u + w; vTop = v; vBottom = v + h;
        break;
    case 1:     // mirror V
        uLeft = u; uRight = u + w; vBottom = v; vTop = v + h;
        break;
    case 2:     // mirror U
        uRight = u; uLeft = u + w; vTop = v; vBottom = v + h;
        break;
    case 3:     // mirror both
        uRight = u; uLeft = u + w; vBottom = v; vTop = v + h;
        break;
    }

    SpriteQuad* q = &g_spriteQuads[n];
    g_spriteBatch.count = n + 1;

    // The three corners as tables plus a COUNTABLE loop. MSVC unrolls this fully back to the
    // same twelve stores and the same 116 instructions -- the loop is not in the output at all --
    // but the loop-frequency weight is assigned while it still exists, and that shifts the
    // register map two words closer (63 -> 65, total mismatches 45 -> 43).
    //   `k < 3` is MANDATORY: `k != 3` defeats the unroller (132 insn, 36/116, measured).
    //                        top-left   top-right     bottom-left
    const int xs[3] = { x0,        x0 + w,       x0        };
    const int ys[3] = { y0,        y0,           y0 + h    };
    const u32 us[3] = { uLeft,     uRight,       uLeft     };
    const u32 vs[3] = { vTop,      vTop,         vBottom   };
    for (u32 k = 0; k < 3; ++k)
    {
        q->v[k].x = xs[k];
        q->v[k].y = ys[k];
        q->v[k].u = us[k];
        q->v[k].v = vs[k];
    }
}
