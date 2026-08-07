// ===========================================================================
// game module @ 0x88070000 — Render_SelectBlend        (171 instructions, 5 bl)
//
// The sprite batcher's render-state selector.  sub_8808E298 (the per-quad
// emitter) calls this whenever the quad it is about to emit carries a packed
// render-state word that differs from the one currently applied, passing
// `word & 0x03FFFFFF` plus the quad's texture page and modulation colour.
//
//   pageId     texture-page index; the page's texture pointer lives in
//              g_pageRecords[pageId * PAGE_RECORD_DWORDS]
//   stateWord  the packed render state (see the bit map below)
//   color      packed 0x00RRGGBB modulation colour
//
// stateWord bit map, as this function decodes it:
//   bits  0.. 7  D3DRS_BLENDFACTOR level, splatted to R,G,B
//   bits  8..15  alpha, 0..255
//   bits 16..19  index into g_blendFactorTable -> DEST blend factor code
//   bits 20..23  index into g_blendFactorTable -> SRC  blend factor code
//   bit  24      ALPHA_IN_X: which lane of pixel-shader constant c15 the
//                alpha goes in; the other lane gets 1.0
//   bit  25      CUSTOM_BLEND: 0 = the default OVER blend (0x07060706),
//                1 = build the D3DBLENDSTATE out of the factor table
//
// Everything here is a cache check.  Five "already applied" comparisons guard,
// in order: the whole state word, the blend state, the blend factor, the alpha
// constant, then the modulation colour, then the texture.  Nothing is pushed
// to D3D unless a cache misses.
//
// The shader-constant writes are the XDK's header-inline fast path (d3d9.h,
// build 9328), reproduced below because it is what the original compiled:
// SetPixelShaderConstantF with a literal count of 1 folds to four dword
// stores into the device's shadow copy plus one OR into the pending-tag mask.
// That is why this function pokes D3DDevice fields directly.
//
// How the guest bytes identify all of that, so none of it has to be taken on
// faith:
//   * the pending-tag OR is `|= 1<<60` at device+8.  D3DTagCollection_Set
//     writes m_Mask[D3DTag_Index(D3DTAG_PIXELSHADERCONSTANTS)] == m_Mask[1],
//     i.e. device+8, and D3DTag_ShaderConstantMask(reg,1) for reg 12..15 is
//     D3DTAG_MASKENCODE(3,3) == 1<<60.  Both halves agree.
//   * walking the 9328 D3DDevice layout puts m_Constants at +0x480 and
//     m_Constants.PixelShaderF[0] at +0x1780, so the two constant registers
//     the guest writes (+0x1860 and +0x1870) are exactly c14 and c15.
//   * the SetTexture call passes 0x80000000, which is D3DTag_SamplerMask(0)
//     == D3DTAG_MASKENCODE(32,32) — the constant D3DDevice_SetTexture_Inline
//     folds for a literal sampler.
//
// VERIFICATION (ppcmatch, XDK 9328 cl.exe, -O2): 171 instructions, same
// extent as the guest, same four pending-tag
// ⚠ CORRECTION 2026-08-05: this file used to claim "same 0xF0-class frame shape". THAT IS WRONG.
// The image opens `stwu r1,-0xf0(r1)`; we emit `-0xe0` — we are 0x10 SHORT, and that 0x10 is
// exactly two missing 16-byte conversion slots (see the colour-block note below). Verified by
// disassembly, not inferred.
// read-modify-writes and the same two surviving staging stores.  Not yet
// byte-exact: see the note above D3DDevice_SetPixelShaderConstantF.
// ===========================================================================

typedef unsigned char       u8;
typedef unsigned int        u32;
typedef unsigned long long  u64;

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

// --- the slice of the XDK D3DDevice this function reaches into -------------
//
// Offsets are the real ones for XDK build 9328 (d3d9.h / d3d9gpu.h):
//   0x0000  m_Pending.m_Mask[5]          pending GPU-state tag bits
//   0x0028  m_Predicated_PendingMask2 .. m_GetSamplerStateCall[]
//   0x0480  m_Constants                  (__declspec(align(128)))
//   0x0480    .Fetch[32]                 32 * 24 bytes
//   0x0780    .VertexShaderF[256]        256 * 16 bytes
//   0x1780    .PixelShaderF[256]         256 * 16 bytes  -> c14 = 0x1860,
//                                                           c15 = 0x1870
struct D3DVECTOR4
{
    float x, y, z, w;
};

struct D3DDevice
{
    u64        m_PendingMask[5];        // 0x0000  m_Pending.m_Mask
    u8         reserved0[0x1780 - 0x28];// 0x0028
    D3DVECTOR4 PixelShaderF[256];       // 0x1780  m_Constants.PixelShaderF
};

// D3DTag_Index(D3DTAG_PIXELSHADERCONSTANTS) — pixel-shader constants live in
// word 1 of the pending mask.
static const u32 TAGINDEX_PIXELSHADERCONSTANTS = 1;

// D3DTag_ShaderConstantMask(reg, 1) for any reg in 12..15: the tag bits cover
// four constant registers each, counted from the MSB, so registers 12..15 all
// share bit 3 == 1<<60.
static const u64 TAGMASK_PSCONST_C12_C15 = 0x1000000000000000ull;

// The two pixel-shader constant registers this batcher owns.
static const u32 PSCONST_MODULATE_COLOR = 14;   // (r, g, b, 1)
static const u32 PSCONST_BLEND_ALPHA    = 15;   // (alpha, 1, 1, 1) or (1, alpha, 1, 1)

// D3DTag_SamplerMask(0): the texture-fetch tag group starts at bit 32, so
// sampler 0 is bit 32 counted from the MSB.  D3DDevice_SetTexture_Inline
// folds this to a constant when the sampler is a literal.
static const u64 TAGMASK_TEXTUREFETCH_SAMPLER0 = 0x0000000080000000ull;

// --- XDK d3d9.h inlines, reproduced --------------------------------------
static __forceinline void D3DVECTOR4_SetX(D3DVECTOR4* pVector, float Value)
{
    *(float*)pVector = Value;
}
static __forceinline void D3DVECTOR4_SetY(D3DVECTOR4* pVector, float Value)
{
    *((float*)pVector + 1) = Value;
}
static __forceinline void D3DVECTOR4_SetZ(D3DVECTOR4* pVector, float Value)
{
    *((float*)pVector + 2) = Value;
}
static __forceinline void D3DVECTOR4_SetW(D3DVECTOR4* pVector, float Value)
{
    *((float*)pVector + 3) = Value;
}

static __forceinline void D3DTagCollection_Set(u64* pMask, u32 Index, u64 Mask)
{
    pMask[Index] |= Mask;
}

// What SetPixelShaderConstantF(reg, data, 1) collapses to.  The XDK copies a
// dword at a time on purpose: it lets the optimizer forward the values
// straight out of the caller's staging array.
static __forceinline void D3DDevice_SetPixelShaderConstantF1(
    D3DDevice* __restrict pDevice, u32 StartRegister,
    const float* __restrict pConstantData)
{
    D3DVECTOR4_SetX(&pDevice->PixelShaderF[StartRegister], pConstantData[0]);
    D3DVECTOR4_SetY(&pDevice->PixelShaderF[StartRegister], pConstantData[1]);
    D3DVECTOR4_SetZ(&pDevice->PixelShaderF[StartRegister], pConstantData[2]);
    D3DVECTOR4_SetW(&pDevice->PixelShaderF[StartRegister], pConstantData[3]);

    D3DTagCollection_Set(pDevice->m_PendingMask, TAGINDEX_PIXELSHADERCONSTANTS,
                         TAGMASK_PSCONST_C12_C15);
}

// __IsIntConst: XDK compiler intrinsic, 1 when the argument is a literal.
extern "C" int __IsIntConst(int);

extern void D3DDevice_SetPixelShaderConstantFN(D3DDevice* pDevice, u32 StartRegister,
                                               const float* pConstantData,
                                               u32 Vector4fCount, u64 PendingMask1);

// The public API.  Both FN arms below are dead for a literal count of 1, but
// the staging array's address escapes into them before they are folded away.
// The array is therefore materialised in a 16-byte-aligned stack slot, and one
// store into it — lane 0 — survives to the end even though nothing reads it.
//
// That leftover store is not cosmetic: it is visible in the guest bytes as
// `stfs fN,0x70(r1)` / `stfs fN,0x80(r1)` inside the two alpha arms, it is why
// ⏭⏭ 2026-08-07: THE HAND-WRITTEN-INLINE SUSPICION WAS CORRECT — see the sibling file
//   game_88070000_Render_SelectBlend_hdr.cpp, which builds the same body against the REAL XDK
//   9328 <d3d9.h>. It scores LOWER on `same=` (37 vs 56, because it is 3 instructions short and
//   everything past the custom arms misaligns) but its structural mismatches over the first 80
//   instructions fall from 12 to 2, leaving mostly register numbering. Defect 1 below is
//   restated there as a TAIL-MERGING problem with the guest's exact asymmetry identified.
//   This file stays canonical only because it is the honest 56/171; the header variant is where
//   the next leg starts. ⚠ That variant needs `_XBOX` defined — see matchlab/README.md.
//
// ⏭ THE BLOCKER HERE IS ABOVE ALLOCATION — do not run more allocator sweeps (Fable review,
//   2026-08-05, and the S=49 count says the same thing: structural, not rank). Two defects:
//   1. PER-ARM RMW. Our build CSE-hoists the pending-tag read-modify-write (`ld`/`or`/`std` of
//      device+8) above the alphaInX branch; the image keeps ONE RMW PER ARM, and its default-else
//      arm TAIL-MERGES into custom arm B (`beq cr6,0x8807015C` jumps across paths into the other
//      arm's store+RMW+exit). That merge is impossible while our RMW is hoisted, and this one
//      defect accounts for most of the midsection S. Removing both `__restrict` qualifiers is
//      INERT (56/171) — the compiler proves no-alias regardless, so restrict is not the lever.
//      Declaring the two arrays up front: 57/171 but S 49 -> 52, not recommended.
//   2. COLOUR BLOCK. The image runs the three int->float conversions through THREE distinct stack
//      slots (0x50/0x58/0x60, overlapping lifetimes, extraction order g,b,r); ours funnels all
//      three through ONE slot, which is why the frame is 0x10 short. Three named channel locals
//      and extraction-order permutations are inert — forwarding erases them.
//   ⇒ Re-open as a STATEMENT-STRUCTURE leg targeting the per-arm RMW shape.
// the frame carries two extra 16-byte slots, and reproducing it is the only
// shape found that makes the compiler emit the guest's per-arm pending-tag OR
// rather than hoisting a single OR above the branch.  Calling
// D3DDevice_SetPixelShaderConstantF1 directly instead loses all three.
//
// REMAINING DELTA: the compiler still hoists the pending-tag OR out of the
// *custom* path's two arms (the guest keeps one per arm) and reuses a single
// int-to-float conversion slot in the colour block where the guest uses three.
// Both are scheduling decisions; a wide sweep over staging type, restrict
// qualifiers, statement order, inline depth and the -O2/-Ox flag matrix left
// them unchanged.
static __forceinline void D3DDevice_SetPixelShaderConstantF(
    D3DDevice* pDevice, u32 StartRegister, const float* pConstantData,
    u32 Vector4fCount)
{
    if (__IsIntConst((int)Vector4fCount))
    {
        if (Vector4fCount == 1)
        {
            D3DDevice_SetPixelShaderConstantF1(pDevice, StartRegister, pConstantData);
        }
        else
        {
            D3DDevice_SetPixelShaderConstantFN(pDevice, StartRegister, pConstantData,
                                               Vector4fCount, TAGMASK_PSCONST_C12_C15);
        }
    }
    else
    {
        D3DDevice_SetPixelShaderConstantFN(pDevice, StartRegister, pConstantData,
                                           Vector4fCount, TAGMASK_PSCONST_C12_C15);
    }
}

// --- out-of-line D3D entry points ------------------------------------------
extern void D3DDevice_SetBlendState(D3DDevice* pDevice, u32 RenderTargetIndex,
                                    u32 BlendState);                  // 0x88077AA8
extern void D3DDevice_SetRenderState_BlendFactor(D3DDevice* pDevice,
                                                 u32 Value);          // 0x88075C38
extern void D3DDevice_SetTexture(D3DDevice* pDevice, u32 Sampler,
                                 void* pTexture, u64 PendingMask3);   // 0x88079B70

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
    u8         reserved0[0x16BC];   // 0x0004
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
    // Read once and held in a callee-saved FPR for the whole function: every
    // constant lane written below gets 1.0 on at least one path.
    float one = g_consts.one;

    if (g_batch.appliedStateWord != stateWord)
    {
        g_batch.appliedStateWord = stateWord;

        // Which lane of c15 the alpha goes in. Needed by both arms, so it is
        // decoded before the split.
        u32 alphaInX = stateWord & STATE_ALPHA_IN_X;

        if (stateWord & STATE_CUSTOM_BLEND)
        {
            u32 factor = stateWord & 0xFF;
            u32 alpha  = (stateWord >> 8) & 0xFF;

            u32 destFactor = g_blendFactorTable[(stateWord >> 16) & 0xF];
            u32 srcFactor  = g_blendFactorTable[(stateWord >> 20) & 0xF];

            // A fully transparent quad drawn with a SRC_ALPHA-family blend
            // would be a no-op; the batcher floors the alpha at 1 instead.
            if ((destFactor == FACTOR_SRC_ALPHA || destFactor == FACTOR_INV_SRC_ALPHA) &&
                alpha == 0)
            {
                alpha = 1;
            }

            // D3DBLENDSTATE: the colour half and the alpha half get the same
            // pair, i.e. dest:src:dest:src packed one byte apart.
            u32 blendState =
                (((destFactor << 8 | (srcFactor & 0x1F)) << 8 | (destFactor & 0xFF)) << 8) |
                (srcFactor & 0x1F);

            if (g_appliedBlendState != blendState)
            {
                g_appliedBlendState = blendState;
                D3DDevice_SetBlendState(g_render.device, 0, blendState);
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
                D3DDevice_SetBlendState(g_render.device, 0, BLEND_STATE_OVER);
            }

            // The default path is fixed at full alpha, so its cache key is
            // 0xFF and the constant it writes is the pre-scaled 1.0.
            if (g_batch.appliedAlphaKey != (alphaInX | 0xFF))
            {
                g_batch.appliedAlphaKey = alphaInX | 0xFF;

                D3DDevice* dev = g_render.device;

                D3DVECTOR4* c = &dev->PixelShaderF[PSCONST_BLEND_ALPHA];
                D3DVECTOR4_SetW(c, one);
                D3DVECTOR4_SetZ(c, one);
                if (alphaInX)
                {
                    D3DVECTOR4_SetY(c, one);
                    D3DVECTOR4_SetX(c, g_consts.defaultAlpha);
                    D3DTagCollection_Set(dev->m_PendingMask, TAGINDEX_PIXELSHADERCONSTANTS,
                                         TAGMASK_PSCONST_C12_C15);
                }
                else
                {
                    D3DVECTOR4_SetX(c, one);
                    D3DVECTOR4_SetY(c, g_consts.defaultAlpha);
                    D3DTagCollection_Set(dev->m_PendingMask, TAGINDEX_PIXELSHADERCONSTANTS,
                                         TAGMASK_PSCONST_C12_C15);
                }
            }
        }
    }

    D3DDevice* dev = g_render.device;

    if (g_batch.appliedColor != color)
    {
        float scale = g_consts.colorScale;

        D3DVECTOR4_SetW(&dev->PixelShaderF[PSCONST_MODULATE_COLOR], one);
        g_batch.appliedColor = color;
        D3DVECTOR4_SetX(&dev->PixelShaderF[PSCONST_MODULATE_COLOR],
                        (float)((color >> 16) & 0xFF) * scale);
        D3DVECTOR4_SetY(&dev->PixelShaderF[PSCONST_MODULATE_COLOR],
                        (float)((color >>  8) & 0xFF) * scale);
        D3DVECTOR4_SetZ(&dev->PixelShaderF[PSCONST_MODULATE_COLOR],
                        (float)( color        & 0xFF) * scale);
        D3DTagCollection_Set(dev->m_PendingMask, TAGINDEX_PIXELSHADERCONSTANTS,
                             TAGMASK_PSCONST_C12_C15);
    }

    if (g_batch.appliedPage != pageId)
    {
        g_batch.appliedPage = pageId;
        void* texture = g_pageRecords[pageId * PAGE_RECORD_DWORDS];
        if (texture != 0)
            D3DDevice_SetTexture(dev, 0, texture, TAGMASK_TEXTUREFETCH_SAMPLER0);
    }
}
