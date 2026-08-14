// decomp/game/page_bake.cpp — the select-compose CONSUME side: sub_8808DC10 (THE PAGE BAKE)
// and sub_8808E298 (SPRITE EMIT QUAD, the bake-on-demand trigger).
//
// Family write-up: decomp/game/NOTES_select_compose.md. Page-record table shared with
// decomp/game/asset_upload.cpp (PAGE_TABLE/PAGE_STRIDE/REC_TEX — re-declared here as this TU's
// own constants pointing at the SAME literals; no cross-TU helpers, per campaign rule).
//
// Ground truth: out_reco/ppc_recomp.4.cpp — sub_8808DC10 :9416-9921 (__savegprlr_19/-0x1C0
// frame), sub_8808E298 :10490-10750 (__savegprlr_21/-0xC0 frame). Both cross-checked
// field-for-field against the independent matchlab models (tools/matchlab/src/
// game_8808DC10_Page_Bake.cpp 146/190 non-reloc words positionally identical — residue is a
// documented register-allocation-rank tie, not a logic disagreement; game_8808E298_
// Sprite_EmitQuad.cpp likewise, residue a pure nonvolatile-rank permutation).
//
// SEAM (measured, decomp/README rule):
//   sub_8808DC10 — UNHOOKED → plain PPC_FUNC (strong beats the generated weak alias).
//   sub_8808E298 — HOOKED (decomp/game/nvk_game_hooks.cpp:186 NVK_GHOOK "G_SpriteEmit" owns the
//     strong sub_ symbol) → THIS file provides the __imp__ override form, exactly the
//     mem_util.cpp sub_88072260 precedent. The trace tap keeps firing around our body.
//   Callees stay plain sub_* so THEIR wrappers keep firing — incl. the hooked ones:
//   sub_88074F98 (R26_BRACKET_WRAP in merged_game.cpp), sub_88077AA8/88079B70/8807F138/
//   8807DD88/880702B0 (nvk hooks).
//
// ⚠ ABN: this TU joins the abn-EXCLUDED set — and NOT only for the uniform +0x60 law: the ROM
// float-constant pool (0x88063370, FPOOL_*) shifts by −48 in the abn image (measured:
// lis -30714 +13168 → +13120), a DIFFERENT segment with its own drift. A blanket +0x60 literal
// patch can NEVER port sub_8808DC10 to abn; the float pool needs its own audit first.
// (sub_8808E298 and sub_8808D838 touch no float-pool literals — uniform +0x60 class only.)
#include "ppc_recomp_shared.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace {

// -- shared with asset_upload.cpp: SAME literals, re-declared per the no-cross-TU rule --------
constexpr uint32_t PAGE_TABLE  = 0x887518D0;
constexpr uint32_t PAGE_STRIDE = 0x14;
constexpr uint32_t REC_TEX     = 0x00;

// -- the renderer block, base 0x887ABF10 (lis -30597) ----------------------------------------
constexpr uint32_t G_LASTBLENDCONST = 0x887ABF10;  // poisoned to -1 on every bake
constexpr uint32_t G_DEVICE         = 0x887AD5D0;  // == asset_upload.cpp's G_DEVICE
constexpr uint32_t G_PS_BACKDROP    = 0x887AD5E0;
constexpr uint32_t G_VS_BACKDROP    = 0x887AD5E4;
constexpr uint32_t G_LAST_PHASE     = 0x887AD5F0;  // the bake gate: last phase baked
constexpr uint32_t G_PS_SPRITE      = 0x887AD5F8;
constexpr uint32_t G_VS_SPRITE      = 0x887AD5FC;

// -- the sprite batcher's redundancy caches, 0x887398A0..0x887398CC (lis -30604). Poisoning
//    them to -1 is what forces sub_88070000 to reprogram texture/blend/flags on the NEXT quad
//    after a bake tramples the pipeline — load-bearing invalidation, not defensive code.
constexpr uint32_t BATCH_LASTTEXSLOT     = 0x887398A0;
constexpr uint32_t BATCH_LASTCOLOUR      = 0x887398A4;
constexpr uint32_t BATCH_LASTALPHASTATE  = 0x887398C4;  // consumer = sub_88070000 (unverified)
constexpr uint32_t BATCH_LASTRENDERSTATE = 0x887398C8;  // == sub_8808E298's "flags" cache
constexpr uint32_t BATCH_QUADCOUNT       = 0x887398CC;
constexpr uint32_t BATCH_RING            = 0x887398D0;  // SpriteQuad[0x800] right after the count

constexpr uint32_t G_LASTBLENDCONTROL = 0x8869989C;     // cached RB_BLENDCONTROL word

// -- ROM float constant pool, base 0x88063370 (lis -30714, +13168). ⚠ ABN SHIFT IS −48 HERE. --
constexpr uint32_t FPOOL_ONE     = 0x88063370 + 0x00;   // 1.0f
constexpr uint32_t FPOOL_ZERO    = 0x88063370 + 0x04;   // 0.0f
constexpr uint32_t FPOOL_HALFPX  = 0x88063370 + 0x3C;   // 0.5f
constexpr uint32_t FPOOL_PANETOP = 0x88063370 + 0x48;   // -0.5f
constexpr uint32_t FPOOL_PANEBOT = 0x88063370 + 0x4C;   // 511.5f

constexpr uint32_t PAGE_DIM           = 0x200;   // 512
constexpr uint32_t PAGE_SIZESTATE     = 2;       // sub_8808D838's sizeState for a 512x512 page
constexpr uint32_t PANE_WIDTH         = 0x280;   // 640 — the live pane; x-clamp target
constexpr uint32_t PAGE_FORMAT        = 0x18280143;
constexpr uint32_t QUAD_COLOUR        = 0xFF808080;
constexpr uint32_t BLEND_STATE        = 0x00010001;
constexpr uint32_t PRIM_TRIANGLESTRIP = 6;
constexpr uint32_t POISON             = 0xFFFFFFFFu;

inline uint32_t f32_bits(float f) { uint32_t u; __builtin_memcpy(&u, &f, 4); return u; }
inline float    load_f32(uint8_t* base, uint32_t ea) { uint32_t u = PPC_LOAD_U32(ea); float f; __builtin_memcpy(&f, &u, 4); return f; }
inline void     store_f32(uint8_t* base, uint32_t ea, float f) { PPC_STORE_U32(ea, f32_bits(f)); }

} // namespace

// ════════════════════════════════════════════════════════════════════════════════════════════════
// sub_8808DC10 — THE PAGE BAKE. UNHOOKED → plain PPC_FUNC. NON-LEAF.
//
//   sub_8808DC10(phase = r3)   [no meaningful return]
//
// Runs only when the incoming phase differs from the last one baked (G_LAST_PHASE). Two halves:
//   BAKE  — resolve a 512-wide window of the live pane into the OLD phase's page(s)
//           (plain Flags=0 resolve; src rect {x,0,x+512,512} clamped to the 640-wide pane).
//   PASTE — after G_LAST_PHASE is overwritten with the NEW phase, draw the NEW phase's page(s)
//           back into the pane as full-height strips at x = 512*i.
// ⚠ BAKE AND PASTE READ DIFFERENT PHASES. The phase store sits BETWEEN the halves and the paste
// re-derives pageCount/firstPage from the now-updated global — paste is NOT "draw what bake just
// resolved"; the page ids generally differ. Do not "simplify" this.
// Phase 0 bakes/pastes TWO pages (ids 0 and 1); every other phase ONE (pageIds[phase]).
// The blr-identity sub_88071134 of old notes is __savegprlr_19 millicode, not a call.
// ════════════════════════════════════════════════════════════════════════════════════════════════
PPC_FUNC(sub_8808DC10)
{
    PPC_FUNC_PROLOGUE();
    const uint32_t phase = ctx.r3.u32;

    if (PPC_LOAD_U32(G_LAST_PHASE) == phase)
        return;                                        // no-op: already on this phase

    // RT_UPCANARY=1: execution proof (unhooked body). Default-off.
    if (std::getenv("RT_UPCANARY")) {
        static int n = 0;
        if (n < 6 || (n % 100) == 0)
            std::fprintf(stderr, "[upcanary] Page_Bake #%d phase=%u last=%u\n",
                         n, phase, PPC_LOAD_U32(G_LAST_PHASE));
        ++n;
    }

    const uint32_t sp = ctx.r1.u32 - 448;               // stwu r1,-448(r1)
    PPC_STORE_U32(sp, ctx.r1.u32);
    ctx.r1.u32 = sp;

    // Frame layout at the generated offsets (out-structs must land at guest addresses — the
    // callees are still-generated PPC bodies).
    const uint32_t pageIds = sp + 128;   // u32[7]: {0, 0x1D,0x1E,0x1F, 0x3D,0x3E,0x3F}
    const uint32_t rect    = sp + 112;   // D3DRECT {x1,y1,x2,y2}
    const uint32_t verts   = sp + 160;   // PaneVertex[4], 0x1C stride: x,y,z,rhw,colour,u,v
    const uint32_t rp      = sp + 272;   // D3DRESOLVE_PARAMETERS {ColorFormat, ColorExpBias, ...}
    constexpr uint32_t VSTRIDE = 0x1C;

    static const uint32_t kPageIds[7] = { 0, 0x1D, 0x1E, 0x1F, 0x3D, 0x3E, 0x3F };
    for (int k = 0; k < 7; ++k) PPC_STORE_U32(pageIds + k * 4, kPageIds[k]);

    // Drain the sprite batcher before trampling the pipeline. ⚠ LEFTOVER-ARG SITE: the generated
    // body sets NO registers before this bl — r3 rides in as the phase argument, unread by the
    // void(void) callee. Do NOT set registers here; that would diverge the observable leftover
    // state from the generated body for zero behavioral gain.
    ctx.lr = 0x8808DC7C; sub_880702B0(ctx, base);       // Sprite_FlushBatch()

    // Poison the batch's redundancy caches (load-bearing — forces full reprogram on next quad).
    PPC_STORE_U32(G_LASTBLENDCONST,      POISON);
    PPC_STORE_U32(BATCH_QUADCOUNT,       0);
    PPC_STORE_U32(BATCH_LASTCOLOUR,      POISON);
    PPC_STORE_U32(BATCH_LASTTEXSLOT,     POISON);
    PPC_STORE_U32(BATCH_LASTRENDERSTATE, POISON);
    PPC_STORE_U32(BATCH_LASTALPHASTATE,  POISON);

    const float one = load_f32(base, FPOOL_ONE);
    PPC_STORE_U32(G_LASTBLENDCONTROL, 0x01010101);

    // ---- 1. BAKE: the OLD phase's page(s) ----------------------------------------------------
    uint32_t lastPhase = PPC_LOAD_U32(G_LAST_PHASE);
    uint32_t pageCount = (lastPhase == 0) ? 2u : 1u;
    uint32_t firstPage = PPC_LOAD_U32(pageIds + lastPhase * 4);

    for (uint32_t i = 0; i < pageCount; ++i)
    {
        const uint32_t bx     = i * PAGE_DIM;
        const uint32_t pageId = firstPage + i;

        ctx.r3.u32 = pageId; ctx.r4.u32 = PAGE_SIZESTATE;
        ctx.lr = 0x8808DD24; sub_8808D838(ctx, base);   // Page_EnsureTexture(pageId, 2)

        if (ctx.r3.s32 != 0)
        {
            PPC_STORE_U32(rp + 0, PAGE_FORMAT);          // rp.ColorFormat
            PPC_STORE_U32(rp + 4, 0);                    // rp.ColorExpBias

            uint32_t x1 = bx, x2 = bx + PAGE_DIM;
            if (x1 > PANE_WIDTH) x1 = PANE_WIDTH;        // x-clamp only; y is always 0..512
            if (x2 > PANE_WIDTH) x2 = PANE_WIDTH;
            PPC_STORE_U32(rect + 0,  x1);
            PPC_STORE_U32(rect + 4,  0);
            PPC_STORE_U32(rect + 8,  x2);
            PPC_STORE_U32(rect + 12, PAGE_DIM);

            const uint32_t tex = PPC_LOAD_U32(PAGE_TABLE + pageId * PAGE_STRIDE + REC_TEX);

            ctx.r3.u32  = PPC_LOAD_U32(G_DEVICE);
            ctx.r4.u64  = 0;                   // Flags (plain resolve — never 0x100 here)
            ctx.r5.u32  = rect;                // pSourceRect (r5 — the register the r5-fix saga was about)
            ctx.r6.u32  = tex;                 // pDestTexture
            ctx.r7.u64  = 0;                   // pDestPoint
            ctx.r8.u64  = 0;                   // DestLevel
            ctx.r9.u64  = 0;                   // DestSliceOrFace
            ctx.r10.u64 = 0;                   // pClearColor
            ctx.f1.f64  = double(one);         // ClearZ
            PPC_STORE_U32(sp + 92,  0);        // stack arg: ClearStencil
            PPC_STORE_U32(sp + 100, rp);       // stack arg: pParameters
            ctx.lr = 0x8808DD94; sub_8807DD88(ctx, base);   // D3DDevice_Resolve
        }
    }

    // ---- vertex template (z/colour/rhw/uv shared by every strip) -----------------------------
    // ⚠ Store order 3,2,1,0 for z/colour/rhw matches the generated schedule — do not "tidy".
    for (int k = 3; k >= 0; --k) store_f32(base, verts + (uint32_t)k * VSTRIDE + 0x08, load_f32(base, FPOOL_ZERO));
    PPC_STORE_U32(verts + 3 * VSTRIDE + 0x10, QUAD_COLOUR);
    PPC_STORE_U32(verts + 2 * VSTRIDE + 0x10, QUAD_COLOUR);
    PPC_STORE_U32(verts + 1 * VSTRIDE + 0x10, QUAD_COLOUR);
    PPC_STORE_U32(verts + 0 * VSTRIDE + 0x10, QUAD_COLOUR);
    for (int k = 3; k >= 0; --k) store_f32(base, verts + (uint32_t)k * VSTRIDE + 0x0C, one);
    store_f32(base, verts + 0 * VSTRIDE + 0x14, load_f32(base, FPOOL_ZERO)); store_f32(base, verts + 0 * VSTRIDE + 0x18, load_f32(base, FPOOL_ZERO));
    store_f32(base, verts + 1 * VSTRIDE + 0x14, one);                        store_f32(base, verts + 1 * VSTRIDE + 0x18, load_f32(base, FPOOL_ZERO));
    store_f32(base, verts + 2 * VSTRIDE + 0x14, load_f32(base, FPOOL_ZERO)); store_f32(base, verts + 2 * VSTRIDE + 0x18, one);
    store_f32(base, verts + 3 * VSTRIDE + 0x14, one);                        store_f32(base, verts + 3 * VSTRIDE + 0x18, one);

    PPC_STORE_U32(G_LAST_PHASE, phase);                  // ★ commit the NEW phase — paste reads it

    const uint32_t dev = PPC_LOAD_U32(G_DEVICE);
    ctx.r3.u32 = dev; ctx.r4.u64 = 0;
    ctx.lr = 0x8808DE14; sub_88075748(ctx, base);        // AlphaTestEnable(dev, 0)
    ctx.r3.u32 = dev; ctx.r4.u32 = PPC_LOAD_U32(G_VS_BACKDROP);
    ctx.lr = 0x8808DE20; sub_88074C08(ctx, base);        // SetVertexShader(dev, vsBackdrop)
    ctx.r3.u32 = dev; ctx.r4.u32 = PPC_LOAD_U32(G_PS_BACKDROP);
    ctx.lr = 0x8808DE2C; sub_88074DC8(ctx, base);        // SetPixelShader(dev, psBackdrop)
    ctx.r3.u32 = dev; ctx.r4.u64 = 0;
    ctx.lr = 0x8808DE38; sub_88074F98(ctx, base);        // SetVertexDeclaration(dev, NULL) [hooked: bracket wrap]
    ctx.r3.u32 = dev; ctx.r4.u64 = 0; ctx.r5.u32 = BLEND_STATE;
    ctx.lr = 0x8808DE4C; sub_88077AA8(ctx, base);        // SetBlendState(dev, 0, 0x10001)

    // ---- 2. PASTE: the NEW phase's page(s) — re-derived from the just-updated global ---------
    lastPhase = PPC_LOAD_U32(G_LAST_PHASE);
    pageCount = (lastPhase == 0) ? 2u : 1u;
    firstPage = PPC_LOAD_U32(pageIds + lastPhase * 4);

    const float paneBottom = load_f32(base, FPOOL_PANEBOT);
    const float paneTop    = load_f32(base, FPOOL_PANETOP);
    const float halfPixel  = load_f32(base, FPOOL_HALFPX);
    const float halfPixel2 = load_f32(base, FPOOL_HALFPX);   // second load: the image does it too

    uint32_t left = 0;
    for (uint32_t i = 0; i < pageCount; ++i, left += PAGE_DIM)
    {
        const uint32_t pageId = firstPage + i;
        const uint32_t tex = PPC_LOAD_U32(PAGE_TABLE + pageId * PAGE_STRIDE + REC_TEX);
        if (tex == 0) continue;

        const uint32_t right = left + PAGE_DIM;
        store_f32(base, verts + 0 * VSTRIDE + 0x00, float(left)  - halfPixel);  store_f32(base, verts + 0 * VSTRIDE + 0x04, paneTop);
        store_f32(base, verts + 1 * VSTRIDE + 0x00, float(right) - halfPixel);  store_f32(base, verts + 1 * VSTRIDE + 0x04, paneTop);
        store_f32(base, verts + 2 * VSTRIDE + 0x00, float(left)  - halfPixel2); store_f32(base, verts + 2 * VSTRIDE + 0x04, paneBottom);
        store_f32(base, verts + 3 * VSTRIDE + 0x00, float(right) - halfPixel2); store_f32(base, verts + 3 * VSTRIDE + 0x04, paneBottom);

        ctx.r3.u32 = dev; ctx.r4.u64 = 0; ctx.r5.u32 = tex; ctx.r6.u64 = 0x80000000;
        ctx.lr = 0x8808DF08; sub_88079B70(ctx, base);    // SetTexture(dev, 0, tex, PS-pending)
        ctx.r3.u32 = dev; ctx.r4.u32 = PRIM_TRIANGLESTRIP; ctx.r5.u64 = 4; ctx.r6.u32 = verts; ctx.r7.u64 = VSTRIDE;
        ctx.lr = 0x8808DF20; sub_8807F138(ctx, base);    // DrawVerticesUP(dev, strip, 4, verts, 0x1C)
    }

    // Hand the pipeline back to the sprite batcher.
    ctx.r3.u32 = dev; ctx.r4.u32 = (PPC_LOAD_U32(G_LAST_PHASE) == 0) ? 1u : 0u;
    ctx.lr = 0x8808DF44; sub_88075748(ctx, base);        // AlphaTestEnable(dev, lastPhase==0)
    ctx.r3.u32 = dev; ctx.r4.u32 = PPC_LOAD_U32(G_PS_SPRITE);
    ctx.lr = 0x8808DF50; sub_88074DC8(ctx, base);        // SetPixelShader(dev, psSprite)
    ctx.r3.u32 = dev; ctx.r4.u32 = PPC_LOAD_U32(G_VS_SPRITE);
    ctx.lr = 0x8808DF5C; sub_88074C08(ctx, base);        // SetVertexShader(dev, vsSprite)

    ctx.r1.u32 = sp + 448;
    // r3 left = the last call's leftover, matching the generated exit (no mr r3 before blr).
}

// ════════════════════════════════════════════════════════════════════════════════════════════════
// sub_8808E298 — SPRITE EMIT QUAD. HOOKED (NVK_GHOOK "G_SpriteEmit" owns the strong sub_ symbol)
// → __imp__ override form, the mem_util.cpp precedent. NON-LEAF.
//
//   sub_8808E298(attr=r3, srcUV=r4, dstXY=r5, extent=r6, blend=r7)   [void]
//
// Per quad: decode src atlas coords (u:13/v:12 bit split) + SIGNED dest shorts + (w-1,h-1)
// extent; derive texPage/dstPage via page = ((y>>3)&~0x1F)|(x>>8); when dstPage is one of the
// six baked pages (id<0x40 && (id&0x1F)>0x1C) convert to bake phase 1..6 with PAGE-LOCAL x/y
// (&0xFF), else phase 0 with the -32,-32 canvas bias; call sub_8808DC10(phase) UNCONDITIONALLY
// (the only-on-change gate lives inside the bake — do NOT "optimize" phase 0 away); flush/rebind
// when texPage/blend/flags differ from the bound state or the ring is full (0x800); append
// 3 vertices (rect-as-strip: TL, TR, BL) with a 4-way UV mirror from attr bits 26-27.
//
// ⚠ LEFTOVER-ARG SITES: both Sprite_FlushBatch calls run with NO register setup — r3 at those
// sites is sub_8808DC10's exit leftover. Harmless (void(void) callee, generated body reads no
// incoming register) but observable — do not "tidy" registers there.
// ════════════════════════════════════════════════════════════════════════════════════════════════
PPC_FUNC_IMPL(__imp__sub_8808E298)
{
    PPC_FUNC_PROLOGUE();
    const uint32_t attrArg  = ctx.r3.u32;
    const uint32_t srcUV    = ctx.r4.u32;
    const uint32_t dstXY    = ctx.r5.u32;
    const uint32_t extent   = ctx.r6.u32;
    const uint32_t blendArg = ctx.r7.u32;

    const uint32_t sp = ctx.r1.u32 - 192;              // stwu r1,-192(r1)
    PPC_STORE_U32(sp, ctx.r1.u32);
    ctx.r1.u32 = sp;

    const int32_t srcU = int32_t((srcUV >> 16) & 0x1FFF);
    const int32_t srcV = int32_t(srcUV & 0xFFF);
    const int32_t dstX = int16_t(dstXY >> 16);
    const int32_t dstY = int16_t(dstXY);

    const uint32_t w = uint32_t((extent >> 16) + 1);
    const uint32_t h = uint32_t((extent & 0xFFFF) + 1);

    const uint32_t texPage = uint32_t(((srcV >> 3) & ~0x1F) | (srcU >> 8));
    const uint32_t dstPage = uint32_t(((dstY >> 3) & ~0x1F) | (dstX >> 8));

    int32_t phase, x0, y0;
    if (dstPage < 0x40 && (dstPage & 0x1F) > 0x1C)
    {
        x0 = dstX & 0xFF;
        y0 = dstY & 0xFF;
        phase = int32_t((dstPage >> 5) * 3 + (dstPage & 0x1F)) - 0x1C;
    }
    else
    {
        phase = 0;
        x0 = dstX - 0x20;
        y0 = dstY - 0x20;
    }

    ctx.r3.s32 = phase;
    ctx.lr = 0x8808E334; sub_8808DC10(ctx, base);      // Page_Bake(phase) — bake-on-demand

    const uint32_t flags = attrArg & 0x3FFFFFFu;

    uint32_t n;
    if (PPC_LOAD_U32(BATCH_LASTTEXSLOT)     == texPage &&
        PPC_LOAD_U32(BATCH_LASTCOLOUR)      == blendArg &&
        PPC_LOAD_U32(BATCH_LASTRENDERSTATE) == flags)
    {
        n = PPC_LOAD_U32(BATCH_QUADCOUNT);
        if (n >= 0x800)
        {
            // ⚠ leftover r3 — see header note; do not set registers here.
            ctx.lr = 0x8808E374; sub_880702B0(ctx, base);      // Sprite_FlushBatch()
            n = PPC_LOAD_U32(BATCH_QUADCOUNT);
        }
    }
    else
    {
        // ⚠ same leftover-r3 note.
        ctx.lr = 0x8808E37C; sub_880702B0(ctx, base);          // Sprite_FlushBatch()
        ctx.r3.u32 = texPage; ctx.r4.u32 = flags; ctx.r5.u32 = blendArg;
        ctx.lr = 0x8808E38C; sub_88070000(ctx, base);          // Sprite_SetBatchState(...)
        n = PPC_LOAD_U32(BATCH_QUADCOUNT);
    }

    const uint32_t u = uint32_t(srcU) & 0xFF;
    const uint32_t v = uint32_t(srcV) & 0xFF;
    uint32_t uLeft, uRight, vTop, vBottom;
    switch ((attrArg >> 26) & 3)                       // case names per matchlab's labeling
    {
    default:
    case 0: uLeft = u;     uRight = u + w; vTop = v;     vBottom = v + h; break;  // no mirror
    case 1: uLeft = u;     uRight = u + w; vBottom = v;  vTop = v + h;    break;  // mirror V
    case 2: uRight = u;    uLeft = u + w;  vTop = v;     vBottom = v + h; break;  // mirror U
    case 3: uRight = u;    uLeft = u + w;  vBottom = v;  vTop = v + h;    break;  // mirror both
    }

    constexpr uint32_t QUAD_STRIDE = 0x30;             // 3 x SpriteVertex{x,y,u,v}, 0x10 each
    const uint32_t q = BATCH_RING + n * QUAD_STRIDE;
    PPC_STORE_U32(BATCH_QUADCOUNT, n + 1);

    PPC_STORE_U32(q + 0x00, uint32_t(x0));      PPC_STORE_U32(q + 0x04, uint32_t(y0));
    PPC_STORE_U32(q + 0x08, uLeft);             PPC_STORE_U32(q + 0x0C, vTop);
    PPC_STORE_U32(q + 0x10, uint32_t(x0) + w);  PPC_STORE_U32(q + 0x14, uint32_t(y0));
    PPC_STORE_U32(q + 0x18, uRight);            PPC_STORE_U32(q + 0x1C, vTop);
    PPC_STORE_U32(q + 0x20, uint32_t(x0));      PPC_STORE_U32(q + 0x24, uint32_t(y0) + h);
    PPC_STORE_U32(q + 0x28, uLeft);             PPC_STORE_U32(q + 0x2C, vBottom);

    ctx.r1.u32 = sp + 192;
    // no r3 write at exit — void, matching the generated body.
}
