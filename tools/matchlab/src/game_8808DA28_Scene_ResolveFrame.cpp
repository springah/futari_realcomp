// 0x8808DA28 (game module) - Scene_ResolveFrame            EXACT, 122/122 instructions
//
// The scene's render-target bring-up. It rebuilds the two shader sets the whole 2D
// pipeline draws with, clears the 640x512 pane to opaque black, and resolves it into the
// pane texture every later frame samples.
//
// Corroboration for the naming below (all of it pre-existing project evidence):
//   * ATLAS_game_sprite_uv.md section 5 lists this function's render-state programming
//     verbatim ("one-time / device-reset", only caller = boot init 0x8808FDF8).
//   * NOTE_legal_streaks.md: the Clear here is the ONLY Clear call site in all 3960
//     game-module functions.
//   * NOTES_select_compose.md: the page-record table wiped below is the scroll cache
//     0x887518D0 (0x200 records x 0x14 bytes = 0x2800), and 0x887AD5F0 is the bake-phase
//     gate 0x8808DC10 reads.
//
// Shape:
//     Stub_8824EAF0(&g_traceRecord)                retail-disabled instrumentation
//     memset(g_pageRecords, 0, 0x2800)             wipe the 0x200 scroll-cache pages
//     params = *g_pane.pParams                     0x130-byte copy onto the stack
//     if (ready && device && width >= 256 && height >= 256) {
//         create VS/PS/decl for the sprite set (stride 16) and the compose set (stride 28)
//         bind each vertex shader to its declaration, then drop the declarations
//         Z off, Z-write off, alpha ref 0, alpha func GREATER, vertex declaration NULL
//         SetRenderTarget(0, pane surface)
//         Clear(flags 0xF, 0xFF000000)             colour targets only, opaque black
//         Resolve(Flags = 0, pSrcRect = NULL, dest = pane texture)
//     }
//
// ---------------------------------------------------------------------------------------
// COMPILER-SHAPE NOTES - why the globals are carved up the way they are.
//
// MSVC 9328 addresses a translation unit's OWN statics through a single anchor register
// (lis/addi once, then plain displacements), because it knows their relative section
// offsets. Three separate facts about that anchor were needed to reproduce this function,
// and each is a reusable tell:
//
//  1. WHEN THE POOL IS SMALL the anchor is the pool base, so every displacement is
//     positive. The original reaches two globals at -8 and -4 and the shader blobs at
//     -0x4C8..0, so BOTH pools must be larger than the 16-bit displacement window. The two
//     `...PoolPadding` objects below only exist to reproduce that distance - the real
//     translation unit obviously holds far more .rdata (other shaders) and .bss than the
//     ten words this function touches.
//
//  2. .rdata KEEPS DECLARATION ORDER, .bss DOES NOT. Initialised const data is emitted in
//     source order; .bss statics are emitted in an order that depends on the *identifier*
//     (MSVC walks an internal hash), independent of declaration order, size or use order.
//     The .bss names here are the ones that land as [padding][paneReady][pDevice]
//     [pPaneTexture][pane] - i.e. the original's 0x887AD5CC / 0x887AD5D0 / 0x887AD5D4 /
//     0x887AD5D8 order.
//
//  3. THE ANCHOR IS AN OBJECT BASE, NOT AN ADDRESS. With a far pool base MSVC picks one
//     whole object and reaches everything else from it. That is why the resolve
//     destination texture has to be its OWN global rather than the first member of the
//     block: as a member, the anchor landed on the object holding the device pointer and
//     every displacement came out 4 bytes low (102/122 words). Split out as a scalar, the
//     anchor is `g_pPaneTexture` = 0x887AD5D4 and the two gate words fall at -8 / -4
//     exactly as the original has them.
// ---------------------------------------------------------------------------------------

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

// ---------------------------------------------------------------------------
// XDK d3d9 declarations. The title links d3d9.lib statically, so every callee below is a
// plain function inside the game module; the guest address on each line is the bl target
// ppcmatch resolves, and all of them agree with the Ghidra listing.
// ---------------------------------------------------------------------------
struct D3DDevice;
struct D3DResource;
struct D3DSurface;
struct D3DBaseTexture;
struct D3DVertexShader;
struct D3DPixelShader;
struct D3DVertexDeclaration;
struct D3DRECT;
struct D3DPOINT;
struct D3DVECTOR4;
struct D3DRESOLVE_PARAMETERS;

struct D3DVERTEXELEMENT9   // 12 bytes on Xbox 360 (d3d9types.h)
{
    u16 Stream;      // 0x00
    u16 Offset;      // 0x02
    u32 Type;        // 0x04
    u8  Method;      // 0x08
    u8  Usage;       // 0x09
    u8  UsageIndex;  // 0x0A
};

// D3DCLEAR_TARGET0..3 - colour only, no Z, no stencil.
static const u32 CLEAR_ALL_COLOUR_TARGETS = 0x0000000F;
static const u32 CLEAR_OPAQUE_BLACK       = 0xFF000000;
static const u32 D3DCMP_GREATER           = 4;

extern "C" void* memcpy(void* dst, const void* src, unsigned int count);   // 0x88072260
extern "C" void* memset(void* dst, int value, unsigned int count);         // 0x88073BD0

extern "C" D3DVertexShader*      D3DDevice_CreateVertexShader(const u32* pFunction);        // 0x88075308
extern "C" D3DPixelShader*       D3DDevice_CreatePixelShader(const u32* pFunction);         // 0x88075120
extern "C" D3DVertexDeclaration* D3DDevice_CreateVertexDeclaration(
                                     const D3DVERTEXELEMENT9* pVertexElements);             // 0x880750A0
// Bakes a vertex shader's input mapping from a declaration plus one stride per stream.
extern "C" void  D3DVertexShader_Bind(D3DVertexShader* pThis, u32 Flags,
                                      D3DVertexDeclaration* pVertexDeclaration,
                                      const u32* pStreamStrides,
                                      D3DPixelShader* pPixelShader);                        // 0x8807C0A8
extern "C" unsigned long D3DResource_Release(D3DResource* pThis);                           // 0x8807F8C8

extern "C" void D3DDevice_SetRenderState_ZEnable(D3DDevice* pDevice, u32 Value);            // 0x88075E10
extern "C" void D3DDevice_SetRenderState_ZWriteEnable(D3DDevice* pDevice, u32 Value);       // 0x88075EB8
extern "C" void D3DDevice_SetRenderState_AlphaRef(D3DDevice* pDevice, u32 Value);           // 0x88075BA8
extern "C" void D3DDevice_SetRenderState_AlphaFunc(D3DDevice* pDevice, u32 Value);          // 0x88075C08
extern "C" void D3DDevice_SetVertexDeclaration(D3DDevice* pDevice,
                                               D3DVertexDeclaration* pDecl);                // 0x88074F98
extern "C" void D3DDevice_SetRenderTarget(D3DDevice* pDevice, u32 RenderTargetIndex,
                                          D3DSurface* pRenderTarget);                       // 0x880781C8
// Note the trailing BOOL EDRAMClear: it is what puts the last `li r10,0` in the Clear setup.
extern "C" void D3DDevice_Clear(D3DDevice* pDevice, u32 Count, const D3DRECT* pRects,
                                u32 Flags, u32 Color, float Z, u32 Stencil,
                                int EDRAMClear);                                            // 0x8807D4F8
// 11 parameters: ClearStencil and pParameters spill to the outgoing area at r1+0x5C/+0x64.
extern "C" void D3DDevice_Resolve(D3DDevice* pDevice, u32 Flags, const D3DRECT* pSourceRect,
                                  D3DBaseTexture* pDestTexture, const D3DPOINT* pDestPoint,
                                  u32 DestLevel, u32 DestSliceOrFace,
                                  const D3DVECTOR4* pClearColor, float ClearZ,
                                  u32 ClearStencil,
                                  const D3DRESOLVE_PARAMETERS* pParameters);                // 0x8807DD88

// 0x8824EAF0 - a blr-only stub in the shipped image (one of a run of empty functions at the
// top of the module: instrumentation compiled out for retail). Its argument is a zero-filled
// record at 0x887398A8.
extern "C" void Stub_8824EAF0(void* pRecord);
extern u32 g_traceRecord;                    // 0x887398A8

// ---------------------------------------------------------------------------
// Scroll-cache page table (see 0x8808D838 and NOTES_select_compose.md)
// ---------------------------------------------------------------------------
struct PageRecord
{
    u32 tex;         // 0x00  D3D texture handle
    u32 sizeState;   // 0x04  1 or 2; texture is (sizeState << 8) square
    u32 srcBuf;      // 0x08  streamed CPU staging buffer
    u32 state;       // 0x0C  fill state
    u32 spare;       // 0x10
};
extern PageRecord g_pageRecords[0x200];      // 0x887518D0, 0x2800 bytes

// 0x88063370 - the module's float-constant table. [0] = 1.0f (Resolve ClearZ),
// [1] = 0.0f (Clear Z).  One lis serves both, so they are one object, not two globals.
extern const float g_floatConstants[2];

// 0x88063440 / 0x88063444 - the pStreamStrides arrays D3DVertexShader_Bind walks (one DWORD
// per vertex stream). 16 bytes per sprite vertex, 28 per compose vertex - the same two
// strides the draw calls in 0x8808DC10 / 0x8808E298 use. Two separate lis/addi pairs in the
// original, so two separate symbols.
extern const u32 g_strideSprite[1];          // 0x88063440 = { 0x10 }
extern const u32 g_strideCompose[1];         // 0x88063444 = { 0x1C }

// ---------------------------------------------------------------------------
// The scene's parameter block - copied to the stack whole before it is inspected.
// ---------------------------------------------------------------------------
struct SceneParams                // 0x130 bytes
{
    u32 reserved00[0x16];         // 0x00
    u32 paneWidth;                // 0x58
    u32 paneHeight;               // 0x5C
    u32 reserved60[0x34];         // 0x60 .. 0x12F
};

// ---------------------------------------------------------------------------
// Translation-unit statics.  Declaration order here is NOT the .bss order - see note 2 in
// the header comment; the resulting addresses are given per line.
// ---------------------------------------------------------------------------

// .bss layout filler - see note 1 in the header comment.
static u32 s_bssPoolPadding[0x2800];

static u32 g_paneReady;                     // 0x887AD5CC  boot init sets this non-zero
static D3DDevice* g_pDevice;                // 0x887AD5D0

// 0x887AD5D8 - the rest of the pane block. Split from g_pPaneTexture on purpose (note 3).
struct PaneRenderer
{
    u32                   reserved00;        // 0x00 (0x887AD5D8)
    D3DSurface*           pPaneSurface;      // 0x04 (0x887AD5DC) the 640x512 render target
    D3DVertexShader*      pVsCompose;        // 0x08 (0x887AD5E0) page-compose set, stride 28
    D3DPixelShader*       pPsCompose;        // 0x0C (0x887AD5E4)
    D3DPixelShader*       pPsComposeCurrent; // 0x10 (0x887AD5E8) live compose PS slot
    u32                   reserved14;        // 0x14 (0x887AD5EC)
    u32                   bakePhase;         // 0x18 (0x887AD5F0) 0x8808DC10's last-phase gate
    const SceneParams*    pParams;           // 0x1C (0x887AD5F4)
    D3DVertexShader*      pVsSprite;         // 0x20 (0x887AD5F8) sprite/UI set, stride 16
    D3DPixelShader*       pPsSprite;         // 0x24 (0x887AD5FC)
};

// 0x887AD5D4 - the resolve destination; 0x8808E468 later binds it as a texture.
static D3DBaseTexture* g_pPaneTexture;
static PaneRenderer g_pane;

// .rdata layout filler - see note 1 in the header comment.
extern const u32 g_rdataPoolPadding[0x2800];
const u32 g_rdataPoolPadding[0x2800] = { 0 };

// The six blobs sit back to back at 0x880094D0..0x880099C7 as two complete shader sets
// {pixel shader, vertex shader, vertex declaration}. Only their SIZES reach the code, so
// the microcode bodies are left zero here; the leading word is the real Xenos shader magic
// (0x102A1100 = pixel, 0x102A1101 = vertex - confirmed by which creator each blob is fed to).
static const u32 kPsSprite[0x168 / 4] = { 0x102A1100 };            // 0x880094D0
static const u32 kVsSprite[0x164 / 4] = { 0x102A1101 };            // 0x88009638
static const D3DVERTEXELEMENT9 kDeclSprite[3] =                    // 0x8800979C, stride 16
{
    { 0,  0, 0x002C23A2, 0, 0, 0 },   // POSITION
    { 0,  8, 0x002C23A2, 0, 5, 0 },   // TEXCOORD0
    { 0xFF, 0, 0xFFFFFFFF, 0, 0, 0 }, // D3DDECL_END()
};
static const u32 kPsCompose[0xE8 / 4] = { 0x102A1100 };            // 0x880097C0
static const u32 kVsCompose[0xF0 / 4] = { 0x102A1101 };            // 0x880098A8
static const D3DVERTEXELEMENT9 kDeclCompose[4] =                   // 0x88009998, stride 28
{
    { 0,    0, 0x001A23A6, 0,  0, 0 },  // POSITION
    { 0, 0x10, 0x00182886, 0, 10, 0 },  // COLOR
    { 0, 0x14, 0x002C23A5, 0,  5, 0 },  // TEXCOORD0
    { 0xFF, 0, 0xFFFFFFFF, 0,  0, 0 },  // D3DDECL_END()
};

// ---------------------------------------------------------------------------
// Keep-alive for the two layout fillers. 0x8808DA28 is not the first function in its
// translation unit; this stands in for the neighbours (0x8808D838, 0x8808D930, ...) that
// keep those objects referenced. It contributes nothing to Scene_ResolveFrame's own code.
// ---------------------------------------------------------------------------
void Scene_TuBssLayoutModel()
{
    s_bssPoolPadding[0] = 0;
    g_paneReady = 0;
    g_pDevice = 0;
    g_pane.bakePhase = 0;
}

// ---------------------------------------------------------------------------

void Scene_ResolveFrame()
{
    SceneParams params;

    Stub_8824EAF0(&g_traceRecord);
    memset(g_pageRecords, 0, sizeof(g_pageRecords));
    memcpy(&params, g_pane.pParams, sizeof(params));

    // cmplwi in the original: all four tests are unsigned.
    if (g_paneReady != 0 && g_pDevice != 0 &&
        params.paneWidth >= 256 && params.paneHeight >= 256)
    {
        g_pane.pVsSprite  = D3DDevice_CreateVertexShader(kVsSprite);
        g_pane.pPsSprite  = D3DDevice_CreatePixelShader(kPsSprite);
        g_pane.pVsCompose = D3DDevice_CreateVertexShader(kVsCompose);
        g_pane.pPsCompose = D3DDevice_CreatePixelShader(kPsCompose);
        g_pane.pPsComposeCurrent = g_pane.pPsCompose;

        D3DVertexDeclaration* pDeclSprite  = D3DDevice_CreateVertexDeclaration(kDeclSprite);
        D3DVertexDeclaration* pDeclCompose = D3DDevice_CreateVertexDeclaration(kDeclCompose);

        // The declarations are only needed to bake each vertex shader's input mapping.
        D3DVertexShader_Bind(g_pane.pVsSprite,  0, pDeclSprite,  g_strideSprite,  0);
        D3DVertexShader_Bind(g_pane.pVsCompose, 0, pDeclCompose, g_strideCompose, 0);

        if (pDeclSprite != 0)
            D3DResource_Release((D3DResource*)pDeclSprite);
        if (pDeclCompose != 0)
            D3DResource_Release((D3DResource*)pDeclCompose);

        D3DDevice_SetRenderState_ZEnable(g_pDevice, 0);
        D3DDevice_SetRenderState_ZWriteEnable(g_pDevice, 0);
        D3DDevice_SetRenderState_AlphaRef(g_pDevice, 0);
        D3DDevice_SetRenderState_AlphaFunc(g_pDevice, D3DCMP_GREATER);
        D3DDevice_SetVertexDeclaration(g_pDevice, 0);
        D3DDevice_SetRenderTarget(g_pDevice, 0, g_pane.pPaneSurface);

        D3DDevice_Clear(g_pDevice, 0, 0, CLEAR_ALL_COLOUR_TARGETS, CLEAR_OPAQUE_BLACK,
                        g_floatConstants[1], 0, 0);
        D3DDevice_Resolve(g_pDevice, 0, 0, g_pPaneTexture, 0, 0, 0, 0,
                          g_floatConstants[0], 0, 0);
    }
}
