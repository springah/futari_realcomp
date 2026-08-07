// 0x8808D930 (game module) — PAGE TEARDOWN for the select-screen compose engine.
//
// Shuts the engine down: unbinds sampler 0, releases the pane colour texture and both
// depth/stencil pairs, then walks all 0x200 scroll-cache page records releasing every page
// texture and freeing every CPU staging buffer that was streamed in but never consumed.
//
// See decomp/game/NOTES_select_compose.md — "FUN_8808D930 (:20393) — teardown: releases all
// page textures + frees pending src buffers". Companions: 0x8808D838 Page_EnsureTexture,
// 0x8808DC10 the page bake, 0x8808DF70 the CPU-side page fill (the writer of srcBuf).
//
// ---------------------------------------------------------------------------------------
// ADDRESSING NOTE (this is why the state block is declared in two pieces below)
//
// The original addresses the whole compose-state block off ONE base register anchored at
// 0x887AD5D8, and reaches the two words BELOW that anchor with negative displacements:
//
//     lis   r11, 0x887B
//     addi  r31, r11, -0x2A28      ; r31 = 0x887AD5D8   <- the anchor
//     lwz   r3,  -8(r31)           ; 0x887AD5D0 = the D3D device handle
//     lwz   r3,  0xC(r31)          ; 0x887AD5E4 ... etc
//
// The sibling 0x8808DA28 does the same thing with its own anchor at 0x887AD5D4 and reads
// -8/-4 off it, so this is how the original TU's state block is laid out and addressed, not
// a quirk of one function. Modelling the block as a single struct based at 0x887AD5D0 gives
// the identical instruction sequence with every displacement 8 too high, so the anchor
// object has to be the one at 0x887AD5D8 with the head words addressed beneath it.
// ---------------------------------------------------------------------------------------

typedef unsigned int u32;

// The anchor object: the render targets the compose engine owns.   base = 0x887AD5D8
struct ComposeTargets
{
    u32 paneTex;      // 0x00  0x887AD5D8  pane colour texture (the resolve source)
    u32 paneSurface;  // 0x04  0x887AD5DC  pane render-target surface
    u32 depthB;       // 0x08  0x887AD5E0  depth/stencil pair B — the double-buffered pair
    u32 stencilB;     // 0x0C  0x887AD5E4     that 0x8807C0A8 swaps against pair A
    u32 boundDepth;   // 0x10  0x887AD5E8  depth surface currently bound (borrowed, not owned)
    u32 _pad14;       // 0x14  0x887AD5EC
    u32 lastPhase;    // 0x18  0x887AD5F0  bake phase gate read by 0x8808DC10
    u32 _pad1C;       // 0x1C  0x887AD5F4
    u32 depthA;       // 0x20  0x887AD5F8  depth/stencil pair A
    u32 stencilA;     // 0x24  0x887AD5FC
};

// The two words that sit immediately below the anchor.               base = 0x887AD5D0
struct ComposeHead
{
    u32 device;       // 0x887AD5D0  D3DDevice*
    u32 resolveDest;  // 0x887AD5D4  pane resolve destination texture
};

extern ComposeTargets g_composeTargets;                                    // 0x887AD5D8
#define g_composeHead  (((ComposeHead*)&g_composeTargets)[-1])             // 0x887AD5D0

// ---------------------------------------------------------------- page record table
struct PageRecord
{
    u32 tex;          // 0x00  D3D texture handle (0 = none)
    u32 sizeState;    // 0x04  1 or 2; the texture is (sizeState << 8) square
    u32 srcBuf;       // 0x08  CPU staging buffer the streamed art arrives in
    u32 state;        // 0x0C  fill state flag
    u32 spare;        // 0x10
};

extern PageRecord g_pageRecords[0x200];                                    // 0x887518D0

// 0x88079B70 — D3DDevice_SetTexture(device, sampler, texture, dirtyMask).
//              The mask is 64-bit: the callers build 0x80000000 as a zero-extended
//              doubleword (li/oris), which a 32-bit argument would not do.
extern "C" void Gpu_SetTexture(u32 device, unsigned __int64 sampler,
                               unsigned __int64 texture, unsigned __int64 dirtyMask);
// 0x8807F8C8 — release a texture/surface object.
extern "C" void Gpu_ReleaseTexture(u32 tex);
// 0x88083758 — free a heap block.
extern "C" void Mem_Free(u32 block);

#define PAGE_COUNT       0x200
#define SETTEX_ALLDIRTY  0x80000000

void Page_Teardown(void)
{
    // Drop whatever is bound to sampler 0 before any of it is released.
    Gpu_SetTexture(g_composeHead.device, 0, 0, SETTEX_ALLDIRTY);

    if (g_composeTargets.stencilB != 0)
    {
        Gpu_ReleaseTexture(g_composeTargets.stencilB);
        g_composeTargets.stencilB = 0;
    }
    g_composeTargets.boundDepth = 0;    // borrowed surface: forget it, never released here

    if (g_composeTargets.depthB != 0)
    {
        Gpu_ReleaseTexture(g_composeTargets.depthB);
        g_composeTargets.depthB = 0;
    }

    if (g_composeTargets.depthA != 0)
    {
        Gpu_ReleaseTexture(g_composeTargets.depthA);
        g_composeTargets.depthA = 0;
    }

    if (g_composeTargets.stencilA != 0)
    {
        Gpu_ReleaseTexture(g_composeTargets.stencilA);
        g_composeTargets.stencilA = 0;
    }

    if (g_composeTargets.paneTex != 0)
    {
        Gpu_ReleaseTexture(g_composeTargets.paneTex);
        g_composeTargets.paneTex = 0;
    }

    // Every page: release its texture and free any staging buffer 0x8808DF70 never got to.
    PageRecord* rec = g_pageRecords;
    for (int i = PAGE_COUNT; i != 0; i--)
    {
        if (rec->tex != 0)
        {
            Gpu_ReleaseTexture(rec->tex);
            rec->tex = 0;
        }
        if (rec->srcBuf != 0)
            Mem_Free(rec->srcBuf);
        rec->srcBuf = 0;
        rec++;
    }
}
