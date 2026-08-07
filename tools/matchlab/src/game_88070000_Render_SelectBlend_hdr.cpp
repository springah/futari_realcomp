// ===========================================================================
// game module @ 0x88070000 — Render_SelectBlend, REAL-HEADER VARIANT
//
// Same statement structure as game_88070000_Render_SelectBlend.cpp, but every D3D construct
// comes from the ORIGINAL XDK 9328 <d3d9.h> instead of a hand-reproduced inline.  This is the
// experiment the 08-05 park queued ("a hand-written approximation of a header inline is the
// leading suspect").  IT IS THE RIGHT LEVER, and it is NOT yet the better file — read both
// numbers before judging:
//
//                                   ours   same/171   S(all)   S(first 80)   r(first 80)
//   hand-rolled inlines (canonical)  171      56         49         12            17
//   real header (this file)          168      37         67          2            28
//
// The positional `same=` score is WORSE because this body is 3 instructions SHORT, which
// misaligns everything past the custom-blend arms.  Structurally it is far closer: over the
// first 80 instructions the structural mismatches fall from 12 to 2, and what is left there is
// almost entirely register NUMBERING.  That moves this function out of the "statement structure"
// class the park left it in and into the allocator class.
//
// ⚠⚠ `_XBOX` MUST BE DEFINED, OR THE WHOLE HEADER UNLOCK IS INERT.  d3d9.h gates
// D3DISINTCONST(x) on _XBOX; without it the macro is the literal FALSE (the x86 arm) and
// D3DDevice_SetPixelShaderConstantF NEVER folds to the F1 fast path — it emits a `bl
// SetPixelShaderConstantFN` and a 0x70 frame.  D3DRESTRICT is gated the same way.  The compiler
// does NOT predefine it; the XDK build system does.  Measured on a 2-line probe: without _XBOX
// 21 instructions and a call, with it 15 and a leaf.  Anyone reaching for the real headers on
// another function must define it or they will measure the wrong compiler.
//
// ★ WHAT THE HEADER PROVED ON ITS OWN: D3DBLENDSTATE is a BITFIELD STRUCT passed BY VALUE, not
// a DWORD, and MSVC lays bitfields out from the LEAST significant bit even on this big-endian
// target.  Its widths are SrcBlend:5 / BlendOp:3 / DestBlend:8 / SrcBlendAlpha:5 /
// BlendOpAlpha:3 / DestBlendAlpha:8 — so the `& 0x1F` and `& 0xFF` in the guest's blend-state
// expression ARE those field widths, not a hand-chosen mask.  The word form is kept below only
// because the cache compare against g_appliedBlendState is a word compare; writing the six
// fields as a real bitfield struct is the obvious next experiment and was NOT run here.
//
// ⏭ WHAT IS LEFT — measured 2026-08-07, both defects now have hard numbers and a dead end each.
//
// 1. TAIL MERGING, and it is EXACTLY TWO MISSING RMW SITES. Instruction-multiset diff against the
//    guest: ld -2, or -2, std -2, lfs +1, mr +1, stfs +1 = the 3-instruction shortfall. The guest
//    has FOUR pending-tag RMWs (custom arm A, custom arm B, default-alphaInX, and the colour
//    block); we have TWO (one shared by all three alpha arms, plus the colour block). MSVC is
//    tail-merging the common `[ld, or, std, b]` SUFFIX — suffixes, not whole blocks, which is why
//    arms with different lane-write ORDER still merge. The guest merges exactly one pair
//    (default-else into custom arm B, `beq cr6,0x8807015C` jumping across paths) and keeps the
//    other two apart; custom arm A survives because its leftover staging store is scheduled
//    BETWEEN the `or` and the `std`, breaking the suffix.
//    ⚠ ELEVEN SHAPES SWEPT, ALL 168 OR WORSE — DO NOT RE-RUN ANY OF THESE:
//      inert (byte-identical to this file): null-arm-first on the custom pair; z/w writes pushed
//      down into each default arm; the RMW spelled as a raw `m_Pending.m_Mask[1] |= …` instead of
//      D3DTagCollection_Set; dropping the `D3DVECTOR4* c` pointer local (38/171, +1, noise);
//      combinations of those.
//      WORSE: hoisting `g_consts.defaultAlpha` into a local above the branch — 165, i.e. it
//      merges one MORE RMW. (Note the guest DOES load it once above the branch, so the guest is
//      not simply "our base plus a hoist"; it CSEs the load while keeping the RMWs apart, which
//      no statement ordering here reproduces.) Declaring both staging arrays up front, naming
//      them distinctly, and calling SetPixelShaderConstantF1 directly: also inert or worse.
//      Flag matrix flat: -O2 -Oc == -Ox -Oc == -O2 -Oc -Ou == -O2 -Oc -Ot; -Os far worse.
//    ⇒ THIS IS NOT REACHABLE FROM STATEMENT STRUCTURE ON THIS BODY. The next move is the
//    synthetic route ALLOCATOR.md itself was built with: a small probe function with four arms
//    that each write a lane and then OR the tag, swept until MSVC keeps four RMWs. Settle the
//    mechanism on a body small enough to read, then apply it here.
//
// 2. REGISTER RANK — the residue is TWO DECISIONS, not a permutation (the Page_Bake §3 framing):
//      guest r31..r23: g_render, factor, g_batch, alpha, alphaInX, consts, mask,  color, pageId
//      ours  r31..r23: g_batch,  g_render, factor, alpha, alphaInX, consts, color, mask,  pageId
//    Delete `g_batch` from both and only mask/color still differ. So: g_batch is over-ranked by
//    two slots, and mask/color are transposed.
//    ★ DO NOT ATTACK THIS BEFORE DEFECT 1. `mask` is the RMW's operand — it has exactly 2 FEWER
//    machine references in our build BECAUSE we merged the RMWs. Fixing defect 1 raises its
//    count by 2 and may resolve the mask/color transposition for free.
//    ✅ AND THE g_batch ANOMALY IS EXPLAINED (2026-08-07, matchlab/rank.py). It does not follow
//    ALLOCATOR.md Step 1 — g_batch has 11 machine references to g_render's 9, both address bases
//    — but priority here is a DENSITY, not a total: normalised by live-range span, g_render
//    scores (3*8+1)/112 = 0.223 against g_batch's (3*10+1)/150 = 0.207, and the image prefers the
//    denser value. That candidate reproduces this function's whole 9-way register order at
//    tau 0.92 (plain count: 0.58). ⚠⚠ BUT THE CAUSAL READING IS REFUTED — matchlab/probe_rank.py
//    tested density directly the same day and the OPPOSITE holds under control: the long-range
//    value wins in all twelve configurations, at equal counts, in both declaration orders, and
//    even when the tight value has MORE references. The 0.92 is a fit on nine points, not a
//    mechanism. The anomaly is still real and unexplained; see ALLOCATOR.md for what died with
//    it (declaration-order tie-break and plain count, both refuted) and for the pressure probe
//    that is now the open question.
// ===========================================================================
#define _XBOX 1

#include <xtl.h>
#include <d3d9.h>

typedef unsigned int u32;

// --- state-word bits -------------------------------------------------------
static const u32 STATE_ALPHA_IN_X   = 0x01000000;
static const u32 STATE_CUSTOM_BLEND = 0x02000000;

// D3DBLENDSTATE (RB_BLENDCONTROL) for the default OVER blend: SRC=6, DEST=7
// in the colour half and again in the alpha half.
static const u32 BLEND_STATE_OVER = 0x07060706;

// Blend factor codes 4 and 5 are the SRC_ALPHA / INV_SRC_ALPHA pair: with
// those a zero alpha would draw nothing, so the alpha is floored at 1.
static const u32 FACTOR_SRC_ALPHA     = 4;
static const u32 FACTOR_INV_SRC_ALPHA = 5;

// Page records are 5 dwords wide; dword 0 is the texture pointer.
static const u32 PAGE_RECORD_DWORDS = 5;

// See the file header: D3DBLENDSTATE is a bitfield struct passed by value.  The word form is
// kept because the cache compare is a word compare.
static __forceinline D3DBLENDSTATE AsBlendState(u32 v)
{
    return *(const D3DBLENDSTATE*)&v;
}

// The two pixel-shader constant registers this batcher owns.
static const u32 PSCONST_MODULATE_COLOR = 14;   // (r, g, b, 1)
static const u32 PSCONST_BLEND_ALPHA    = 15;   // (alpha, 1, 1, 1) or (1, alpha, 1, 1)

// --- game globals ----------------------------------------------------------

// The batcher's "currently applied" cache, 0x887398A0.
struct SpriteBatchState
{
    u32 appliedPage;            // 0x00  last texture page bound
    u32 appliedColor;           // 0x04  last modulation colour
    u32 reserved0[7];           // 0x08
    u32 appliedAlphaKey;        // 0x24  last (alpha | ALPHA_IN_X)
    u32 appliedStateWord;       // 0x28  last whole state word
};

// The renderer globals block, 0x887ABF10.
struct RenderGlobals
{
    u32        appliedBlendFactor;  // 0x0000  last D3DRS_BLENDFACTOR level
    unsigned char reserved0[0x16BC];// 0x0004
    D3DDevice* device;              // 0x16C0
};

// Float constants the renderer keeps in one block, 0x88063370.
struct RenderConsts
{
    float defaultAlpha;         // 0x00  the non-custom path's alpha (== 1.0)
    float one;                  // 0x04
    float reserved0[18];        // 0x08
    float alphaScale;           // 0x50  1/255 for the alpha byte
    float colorScale;           // 0x54  1/255 for the colour bytes
};

extern SpriteBatchState   g_batch;                // 0x887398A0
extern RenderGlobals      g_render;               // 0x887ABF10
extern const RenderConsts g_consts;               // 0x88063370
extern const u32          g_blendFactorTable[16]; // 0x88063418
extern u32                g_appliedBlendState;    // 0x8869989C
extern void*              g_pageRecords[];        // 0x887518D0

// ---------------------------------------------------------------------------

void Render_SelectBlend(u32 pageId, u32 stateWord, u32 color)
{
    float one = g_consts.one;

    if (g_batch.appliedStateWord != stateWord)
    {
        g_batch.appliedStateWord = stateWord;

        u32 alphaInX = stateWord & STATE_ALPHA_IN_X;

        if (stateWord & STATE_CUSTOM_BLEND)
        {
            u32 factor = stateWord & 0xFF;
            u32 alpha  = (stateWord >> 8) & 0xFF;

            u32 destFactor = g_blendFactorTable[(stateWord >> 16) & 0xF];
            u32 srcFactor  = g_blendFactorTable[(stateWord >> 20) & 0xF];

            if ((destFactor == FACTOR_SRC_ALPHA || destFactor == FACTOR_INV_SRC_ALPHA) &&
                alpha == 0)
            {
                alpha = 1;
            }

            u32 blendState =
                (((destFactor << 8 | (srcFactor & 0x1F)) << 8 | (destFactor & 0xFF)) << 8) |
                (srcFactor & 0x1F);

            if (g_appliedBlendState != blendState)
            {
                g_appliedBlendState = blendState;
                D3DDevice_SetBlendState(g_render.device, 0, AsBlendState(blendState));
            }

            if (g_render.appliedBlendFactor != factor)
            {
                g_render.appliedBlendFactor = factor;
                D3DDevice_SetRenderState_BlendFactor(
                    g_render.device, ((factor << 8 | factor) << 8) | factor);
            }

            if (g_batch.appliedAlphaKey != (alpha | alphaInX))
            {
                g_batch.appliedAlphaKey = alpha | alphaInX;

                D3DDevice* dev = g_render.device;
                float a = (float)alpha * g_consts.alphaScale;

                if (alphaInX)
                {
                    float v[4] = { a, one, one, one };
                    D3DDevice_SetPixelShaderConstantF(dev, PSCONST_BLEND_ALPHA, v, 1);
                }
                else
                {
                    float v[4] = { one, a, one, one };
                    D3DDevice_SetPixelShaderConstantF(dev, PSCONST_BLEND_ALPHA, v, 1);
                }
            }
        }
        else
        {
            if (g_appliedBlendState != BLEND_STATE_OVER)
            {
                g_appliedBlendState = BLEND_STATE_OVER;
                D3DDevice_SetBlendState(g_render.device, 0, AsBlendState(BLEND_STATE_OVER));
            }

            if (g_batch.appliedAlphaKey != (alphaInX | 0xFF))
            {
                g_batch.appliedAlphaKey = alphaInX | 0xFF;

                D3DDevice* dev = g_render.device;

                D3DVECTOR4* c = &dev->m_Constants.PixelShaderF[PSCONST_BLEND_ALPHA];
                D3DVECTOR4_SetW(c, one);
                D3DVECTOR4_SetZ(c, one);
                if (alphaInX)
                {
                    D3DVECTOR4_SetY(c, one);
                    D3DVECTOR4_SetX(c, g_consts.defaultAlpha);
                    D3DTagCollection_Set(&dev->m_Pending,
                                         D3DTag_Index(D3DTAG_PIXELSHADERCONSTANTS),
                                         D3DTag_ShaderConstantMask(PSCONST_BLEND_ALPHA, 1));
                }
                else
                {
                    D3DVECTOR4_SetX(c, one);
                    D3DVECTOR4_SetY(c, g_consts.defaultAlpha);
                    D3DTagCollection_Set(&dev->m_Pending,
                                         D3DTag_Index(D3DTAG_PIXELSHADERCONSTANTS),
                                         D3DTag_ShaderConstantMask(PSCONST_BLEND_ALPHA, 1));
                }
            }
        }
    }

    D3DDevice* dev = g_render.device;

    if (g_batch.appliedColor != color)
    {
        float scale = g_consts.colorScale;

        D3DVECTOR4_SetW(&dev->m_Constants.PixelShaderF[PSCONST_MODULATE_COLOR], one);
        g_batch.appliedColor = color;
        D3DVECTOR4_SetX(&dev->m_Constants.PixelShaderF[PSCONST_MODULATE_COLOR],
                        (float)((color >> 16) & 0xFF) * scale);
        D3DVECTOR4_SetY(&dev->m_Constants.PixelShaderF[PSCONST_MODULATE_COLOR],
                        (float)((color >>  8) & 0xFF) * scale);
        D3DVECTOR4_SetZ(&dev->m_Constants.PixelShaderF[PSCONST_MODULATE_COLOR],
                        (float)( color        & 0xFF) * scale);
        D3DTagCollection_Set(&dev->m_Pending, D3DTag_Index(D3DTAG_PIXELSHADERCONSTANTS),
                             D3DTag_ShaderConstantMask(PSCONST_MODULATE_COLOR, 1));
    }

    if (g_batch.appliedPage != pageId)
    {
        g_batch.appliedPage = pageId;
        void* texture = g_pageRecords[pageId * PAGE_RECORD_DWORDS];
        if (texture != 0)
            D3DDevice_SetTexture(dev, 0, (D3DBaseTexture*)texture, D3DTag_SamplerMask(0));
    }
}
