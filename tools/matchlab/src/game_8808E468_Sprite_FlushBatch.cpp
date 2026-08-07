// 0x8808E468 (game module) — Sprite_FlushBatch: the whole-frame sprite compose.
//
// Called once per frame from the shell's msg-5 thread. It is the only place the game composes
// a frame, and it does four things in order:
//
//   1. Page_CpuFill()    — drain the streamed CPU page buffers into their textures
//                          (0x8808DF70; see NOTES_select_compose.md "FUN_8808DF70").
//   2. Background pass   — bind the background shader pair, point the device at the 640x512
//                          ROM render target, and paste LAST frame's resolve texture back over
//                          it as one screen-space quad.
//   3. Sprite pass       — swap to the sprite shader pair and walk the frame's sprite queue,
//                          emitting one quad per 5-dword record.
//   4. Resolve           — resolve the 640x480 live region of the ROM target back into the same
//                          texture the background pass samples next frame.  Flags = 0.
//
// Notes for the reader (all of this is visible in the instruction stream):
//
//  * The nine renderer variables at 0x887AD5D0..0x887AD5FC are file-scope statics that the
//    original compiler pooled into ONE .bss block and addressed from a single base register
//    anchored on the pool symbol at 0x887AD5EC (the sprite-queue length).  Everything below
//    that address is therefore reached at a NEGATIVE displacement.  That is modelled here as
//    `g_rend[]` plus the signed RG_* slot ids; the comments give the absolute guest addresses.
//    A plain `struct` at 0x887AD5D0 does not reproduce it: MSVC always anchors a struct base
//    at offset 0, which puts every displacement 0x1C too high.
//
//  * The float constants come from one shared .rdata table at 0x88063370 — the code loads them
//    from memory through a single base, it does not materialise literals (a literal would get
//    its own `__real@` COMDAT and its own `lis`), so they are modelled as `g_fc[]` slots.
//
//  * The three vertex fields that are identical on all four corners (colour, rhw, z) are
//    written with chained assignments; those evaluate right-to-left, which is why the store
//    order runs corner 3 -> 0 for them and 0 -> 3 for the fields that vary.
//
//  * The two device-shadow writes between SetRenderTarget and the sampler setters are an
//    inlined XDK-style setter: it clears a 2-bit field in the GPU constant at device+0x48C and
//    then raises the matching dirty tag in m_Pending (device+0x18).  The tag write goes through
//    a pointer (D3DTagCollection_Set) exactly as d3d9.h does it, and that pointer store is what
//    stops the compiler from interleaving the two read-modify-writes.
//
// Match status against XDK 9328 cl.exe 15.00.8327 at -O2 is recorded at the bottom of the file.

typedef unsigned int        u32;
typedef unsigned long long  u64;
typedef unsigned int        DWORD;
typedef unsigned int        UINT;
typedef unsigned long long  UINT64;

struct D3DSurface;
struct D3DBaseTexture;
struct D3DVertexShader;
struct D3DPixelShader;
struct D3DVertexDeclaration;
struct D3DVECTOR4;
struct D3DPOINT;
struct D3DRESOLVE_PARAMETERS;

struct D3DRECT { int x1, y1, x2, y2; };

// Only the two fields this function pokes directly are named; the rest is padding that places
// them at their real offsets inside the XDK's D3DDevice.
struct D3DDevice
{
    u32 head[6];                        // 0x000
    u64 Pending;                        // 0x018  m_Pending.m_Mask[0] — dirty-state tag word
    u32 mid[(0x48C - 0x20) / 4];        // 0x020
    u32 TextureFetchWord;               // 0x48C  GPU constant shadow; bits 23:24 are the field
};                                      //        this function clears

// --------------------------------------------------------------------------------------
// The renderer's pooled statics.  `g_rend` names the pool symbol at 0x887AD5EC; the slot ids
// below are signed dword indices from it.
// --------------------------------------------------------------------------------------
union RendererSlot
{
    u32               count;
    D3DDevice*        dev;
    D3DBaseTexture*   tex;
    D3DSurface*       surf;
    D3DPixelShader*   ps;
    D3DVertexShader*  vs;
};

extern RendererSlot g_rend[];             // 0x887AD5EC

enum RendererSlotId
{
    RG_DEV             = -0x1C / 4,   // 0x887AD5D0  the D3D device
    RG_RESOLVE_TEX     = -0x18 / 4,   // 0x887AD5D4  640x512 pane texture: sampled by the
                                      //             background quad, written by the resolve
    RG_ROM_TARGET      = -0x10 / 4,   // 0x887AD5DC  the ROM render target surface
    RG_PS_BACKGROUND   = -0x0C / 4,   // 0x887AD5E0  background pixel shader
    RG_VS_BACKGROUND   = -0x04 / 4,   // 0x887AD5E8  background vertex shader
    RG_QUEUE_DWORDS    =  0x00 / 4,   // 0x887AD5EC  sprite queue length, in dwords
    RG_LAST_BAKE_PHASE =  0x04 / 4,   // 0x887AD5F0  page-bake phase latch (0x8808DC10's gate)
    RG_PS_SPRITE       =  0x0C / 4,   // 0x887AD5F8  sprite pixel shader
    RG_VS_SPRITE       =  0x10 / 4    // 0x887AD5FC  sprite vertex shader
};

// --------------------------------------------------------------------------------------
// 0x88063370 — the module's shared float constant table.
// --------------------------------------------------------------------------------------
extern const float g_fc[];

enum FloatSlotId
{
    FC_ONE      = 0x00 / 4,   // 0x88063370   1.0f
    FC_ZERO     = 0x04 / 4,   // 0x88063374   0.0f
    FC_NEG_HALF = 0x48 / 4,   // 0x880633B8  -0.5f     half-texel screen origin
    FC_X1       = 0x58 / 4,   // 0x880633C8   639.5f   640 - 0.5
    FC_Y1       = 0x5C / 4,   // 0x880633CC   479.5f   480 - 0.5
    FC_V1       = 0x60 / 4    // 0x880633D0   0.9375f  480/512 — the live rows of the ROM target
};

extern u32 g_spriteQueue[];   // 0x886998A0 — frame sprite queue, 5 dwords per record
extern u32 g_batchLock;       // 0x887398A8 — quad-batch lock object (a no-op thunk pair)

// Pre-transformed screen-space vertex, 0x1C bytes.
struct ScreenVertex { float x, y, z, rhw; u32 diffuse; float u, v; };

enum { SPRITE_CMD_DWORDS = 5 };            // one sprite queue record
enum { D3DPT_RECTLIST    = 6 };            // primitive type of the background quad
enum { BACKGROUND_TINT   = 0xFF808080u };  // 0x80 == 1.0 in the game's colour convention
enum { SCREEN_W = 640, SCREEN_H = 480 };   // live region of the 640x512 ROM target
enum { TEXTUREFETCH_FIELD_MASK = 0xFE7FFFFFu };   // clears bits 23:24 of device+0x48C

// The dirty tag this function raises, and the same bit as SetTexture's PendingMask3.  It has to
// be a 64-bit literal: an int-typed constant is materialised with lis+or instead of one oris.
static const UINT64 PENDING_TAG_BIT = 0x80000000ull;

// --------------------------------------------------------------------------------------
// Callees.  All of these relocate; the guest target is in the comment so the reloc list the
// matcher prints can be audited line by line.
// --------------------------------------------------------------------------------------
extern "C" {
void D3DDevice_SetPixelShader(D3DDevice*, D3DPixelShader*);                 // 0x88074DC8
void D3DDevice_SetVertexShader(D3DDevice*, D3DVertexShader*);               // 0x88074C08
void D3DDevice_SetVertexDeclaration(D3DDevice*, D3DVertexDeclaration*);     // 0x88074F98
void D3DDevice_SetRenderState_88076918(D3DDevice*, DWORD);                  // 0x88076918
              // writes device+0x294C = 0x400 and device+0x2944 bit16 (ATLAS_game_sprite_uv
              // §5); which D3DRS_* that is has not been pinned down, so it keeps its address.
void D3DDevice_SetRenderTarget(D3DDevice*, DWORD, D3DSurface*);             // 0x880781C8
void D3DDevice_SetSamplerState_AddressU(D3DDevice*, DWORD, DWORD);          // 0x88076F88
void D3DDevice_SetSamplerState_AddressV(D3DDevice*, DWORD, DWORD);          // 0x88077130
              // stage-0 address modes per ATLAS_game_sprite_uv §5; the U/V split is that
              // atlas's reading, not proven here.
void D3DDevice_SetRenderState_AlphaTestEnable(D3DDevice*, DWORD);           // 0x88075748
void D3DDevice_SetRenderState_AlphaBlendEnable(D3DDevice*, DWORD);          // 0x88075780
void D3DDevice_SetTexture(D3DDevice*, DWORD, D3DBaseTexture*, UINT64);      // 0x88079B70
void D3DDevice_DrawVerticesUP(D3DDevice*, DWORD, UINT, const void*, UINT);  // 0x8807F138
void D3DDevice_Resolve(D3DDevice*, DWORD Flags, const D3DRECT* pSourceRect, // 0x8807DD88
                       D3DBaseTexture* pDestTexture, const D3DPOINT* pDestPoint,
                       UINT DestLevel, UINT DestSliceOrFace,
                       const D3DVECTOR4* pClearColor, float ClearZ,
                       DWORD ClearStencil, const D3DRESOLVE_PARAMETERS* pParameters);

u32  Timing_MarkPhase(u32 phase);                            // 0x88093308
void Page_CpuFill();                                         // 0x8808DF70
void Sprite_ResetStateCache();                               // 0x8808D740
void Sprite_EmitQuad(u32, u32, u32, u32, u32);               // 0x8808E298
void Sprite_DrawPendingQuads();                              // 0x880702B0
void Lock_Acquire(u32* lock);                                // 0x8824EAD0
void Lock_Release(u32* lock);                                // 0x8824EAE0
}

// d3d9.h's tag helper, reproduced so the pending-mask write keeps its pointer form.
static void D3DTagCollection_Set(u64* pMask, UINT64 Mask) { *pMask |= Mask; }


void Sprite_FlushBatch(void)
{
    Timing_MarkPhase(5);

    if (g_rend[RG_DEV].dev != 0 && g_rend[RG_RESOLVE_TEX].tex != 0)
    {
        // ---- CPU-side page fill, then the background pass -----------------------------
        Page_CpuFill();

        D3DDevice_SetPixelShader(g_rend[RG_DEV].dev, g_rend[RG_PS_BACKGROUND].ps);
        D3DDevice_SetRenderState_88076918(g_rend[RG_DEV].dev, 0);
        D3DDevice_SetVertexDeclaration(g_rend[RG_DEV].dev, 0);

        // The original reads the ROM target BEFORE it clears the bake-phase latch.  Modelling
        // the pool as one object makes the two a possible alias, so the read has to be written
        // out as its own binding or the compiler keeps the store first (see the DIFF notes).
        D3DSurface* const romTarget = g_rend[RG_ROM_TARGET].surf;

        // A fresh frame invalidates the page-bake phase latch that 0x8808DC10 gates on.
        g_rend[RG_LAST_BAKE_PHASE].count = 0;

        D3DDevice_SetRenderTarget(g_rend[RG_DEV].dev, 0, romTarget);

        {
            D3DDevice* const dev = g_rend[RG_DEV].dev;
            dev->TextureFetchWord &= TEXTUREFETCH_FIELD_MASK;
            D3DTagCollection_Set(&dev->Pending, PENDING_TAG_BIT);
            D3DDevice_SetSamplerState_AddressU(dev, 0, 0);
        }
        D3DDevice_SetSamplerState_AddressV(g_rend[RG_DEV].dev, 0, 0);

        // ---- the background quad ------------------------------------------------------
        // One screen-space rect covering 640x480 with a half-texel origin, sampling the top
        // 480 of the 512 rows of last frame's resolve (v runs 0 .. 480/512).
        const float one  = g_fc[FC_ONE];
        const float zero = g_fc[FC_ZERO];
        const float x0   = g_fc[FC_NEG_HALF];
        const float x1   = g_fc[FC_X1];
        const float y1   = g_fc[FC_Y1];
        const float v1   = g_fc[FC_V1];

        ScreenVertex bg[4];
        bg[0].diffuse = bg[1].diffuse = bg[2].diffuse = bg[3].diffuse = BACKGROUND_TINT;
        bg[0].rhw     = bg[1].rhw     = bg[2].rhw     = bg[3].rhw     = one;
        bg[0].z       = bg[1].z       = bg[2].z       = bg[3].z       = zero;

        bg[0].x = x0;  bg[0].y = x0;  bg[0].u = zero; bg[0].v = zero;
        bg[1].x = x1;  bg[1].y = x0;  bg[1].u = one;  bg[1].v = zero;
        bg[2].x = x0;  bg[2].y = y1;  bg[2].u = zero; bg[2].v = v1;
        bg[3].x = x1;  bg[3].y = y1;  bg[3].u = one;  bg[3].v = v1;

        D3DDevice_SetRenderState_AlphaTestEnable(g_rend[RG_DEV].dev, 0);
        D3DDevice_SetRenderState_AlphaBlendEnable(g_rend[RG_DEV].dev, 0);
        D3DDevice_SetVertexShader(g_rend[RG_DEV].dev, g_rend[RG_VS_BACKGROUND].vs);
        D3DDevice_SetTexture(g_rend[RG_DEV].dev, 0, g_rend[RG_RESOLVE_TEX].tex,
                             PENDING_TAG_BIT);
        D3DDevice_DrawVerticesUP(g_rend[RG_DEV].dev, D3DPT_RECTLIST, 4, bg,
                                 sizeof(ScreenVertex));

        // ---- the sprite pass ----------------------------------------------------------
        D3DDevice_SetRenderState_AlphaTestEnable(g_rend[RG_DEV].dev, 1);
        D3DDevice_SetRenderState_AlphaBlendEnable(g_rend[RG_DEV].dev, 1);

        Lock_Acquire(&g_batchLock);

        D3DDevice_SetPixelShader(g_rend[RG_DEV].dev, g_rend[RG_PS_SPRITE].ps);
        D3DDevice_SetVertexShader(g_rend[RG_DEV].dev, g_rend[RG_VS_SPRITE].vs);
        D3DDevice_SetVertexDeclaration(g_rend[RG_DEV].dev, 0);

        Sprite_ResetStateCache();

        // The bound is hoisted: the queue length is read once, before the loop, which is why
        // the compiler turns the walk into a divwu trip count instead of re-reading it.
        u32* const end = g_spriteQueue + g_rend[RG_QUEUE_DWORDS].count;
        for (u32* p = g_spriteQueue; p < end; p += SPRITE_CMD_DWORDS)
            Sprite_EmitQuad(p[0], p[1], p[2], p[3], p[4]);

        Sprite_DrawPendingQuads();

        Lock_Release(&g_batchLock);

        // ---- end-of-frame resolve -----------------------------------------------------
        // Flags = 0: a plain resolve, no clear-after.  The destination is the same texture the
        // background pass sampled at the top of this function.
        // Field order is load-bearing, not cosmetic: it is the tie-break the post-RA scheduler
        // uses for the four independent rect stores, and x2/x1/y2/y1 is the only one of the 24
        // orderings that reproduces the original's `li r5,480` scratch and its store order.
        D3DRECT src;
        src.x2 = SCREEN_W; src.x1 = 0; src.y2 = SCREEN_H; src.y1 = 0;
        D3DDevice_Resolve(g_rend[RG_DEV].dev, 0, &src, g_rend[RG_RESOLVE_TEX].tex,
                          0, 0, 0, 0, one, 0, 0);
    }
}

// --------------------------------------------------------------------------------------
// DIFF status (XDK 9328 cl.exe 15.00.8327, -O2): 169/169 instructions, 87 word-identical
// (was 80; 35 of the remaining 82 words are relocated and can only ever be compared modulo
// their patched field, so the ceiling this metric can reach is 134).
//
// Everything structural agrees — prologue/epilogue (__savegprlr_27 plus the manual f31 save),
// frame size 0x130, all 25 bl targets in order, every stack offset (rect at r1+0x70, the four
// 0x1C-byte vertices at r1+0x80..0xEF, the two outgoing Resolve stack slots at r1+0x5C/0x64),
// the whole loop including the divwu trip count and the lwzu walk, and every global
// displacement.  What still differs is instruction SCHEDULING / register naming only.
//
// FIXED 2026-08-05 (both are statement-order effects on the post-RA scheduler):
//   * the romTarget binding above the bake-phase store — closed +26..28 AND, as a side
//     effect, +89/90 (the background SetVertexShader now loads r4 before r3 like the image).
//   * the rect field order x2,x1,y2,y1 — closed +148 and +151 (the 480 constant now lands in
//     r5, as the original's scratch does) and +158/160.  All 24 orderings were measured; this
//     one is the unique best, and the metric ranges 82..87 across them, so the order is a real
//     compiler input, not noise.
//
// STILL DIFFERENT:
//   * +51..72 (21 words): the original issues `lfs f31, pool(r7)` (the 1.0f) FIRST in the quad
//     block and its first rhw store third; ours sinks that one load to +68 and the whole rhw
//     group with it.  Every other load, store and register in the block matches.
//   * +112..146 (15 words): the lock pointer gets r30 in the original and r28 here, with the
//     loop walker and trip counter rotated down to match (image r30/r29/r28 = lock/walker/
//     counter; ours r28/r30/r29).  Same five nonvolatile values, same defs, same instructions.
//   * +15/16, +32..34, +92..96, +156/162: single-slot scheduling swaps inside four blocks.
//
// SWEPT FLAT this leg — do not repeat (each rebuilt and re-diffed; "flat" = byte-identical):
//   * quad fill: all six chain permutations, split/unsplit rhw, per-vertex loop form, aggregate
//     initialiser, all 24 per-corner field orders (x,y,u,v is already optimal), reversed corner
//     order (strictly worse), four separate vertex locals behind a cursor.
//   * the six float locals: declaration order, const-ness, `one` removed entirely (drops to 167
//     — the f31 save/restore pair disappears, which CONFIRMS `one` is the cross-call value),
//     `*g_fc` vs `g_fc[0]`, an explicit pool pointer, ClearZ named through a second local.
//   * the lock: named local at three scopes, taken by reference, `g_batchLock` as an array,
//     re-assigned before release, and as a literal guest address (much worse — 63).
//   * the loop: while form, do/while on a count, index form, record-struct walk with ++p,
//     bound hoisted above Lock_Acquire, walker declared before the acquire, body words pulled
//     into five named locals.  None moves the lock/walker/counter rotation.
//   * pool model: plain u32 array with casts instead of the union — identical, so the union is
//     not what defeats the bake-phase/romTarget alias analysis.
//   * callee prototypes: void callees redeclared as returning u32 (tests whether a live r3 at
//     the block head reorders the next two-argument setter) — all inert.
//   * flags: -Ou- (prescheduling off), -Ot, -Os, -Og -Ot -Ou, -Oi-, -fp:fast, -fp:precise,
//     -GF, -Gy, -Ob2, -Ox -Ob2, -Ox -Ou-.  Only -Os moves the number, and downward.
//
// ONE UNEXPLORED LEAD, deliberately not taken: compiled as nine separate file-scope statics
// (rather than one pooled object) this compiler merges them into a single unnamed .bss block,
// anchors ONE named symbol per function, uses signed displacements off it — and, measurably,
// both breaks the false bake-phase alias and emits r4 before r3 for two-argument calls, i.e.
// it is the shape the original was written in.  It is not taken here because the .bss layout
// order is a name hash, not declaration order, so hitting the twelve required slot positions
// would mean brute-forcing identifier spellings; the result would be unreadable and would
// throw away this file's documented guest addresses for at most a handful of words.
// --------------------------------------------------------------------------------------
