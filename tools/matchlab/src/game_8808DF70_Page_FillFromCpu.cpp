// 0x8808DF70 (game module) — scroll-cache PAGE FILL FROM CPU.
//
// The "other page writer" of the select-screen compose engine (see
// decomp/game/NOTES_select_compose.md, "FUN_8808DF70 (:20666)"). It sweeps the whole
// 0x200-entry page record table once, under the page lock, and does one of two jobs per
// record:
//
//   state != 0                -> a release was requested: drop the texture, re-arm the record.
//   state == 0 && srcBuf != 0 -> an upload is pending: make sure the texture exists at the
//                                requested size, TILE the linear staging image that
//                                0x8808D640 parked in srcBuf into the texture's memory,
//                                then free the staging buffer.
//
// The copy is XGTileSurface, not a memcpy: the staging image is linear, GPU texture memory is
// tiled, and the destination extent comes from XGGetTextureDesc rather than from the page
// size, so a padded RowPitch is honoured. Together with the resolve bake in 0x8808DC10 this
// is the pair of writers that keep the six 512x512 backdrop pages current — this one supplies
// the INITIAL art from the asset stream, the bake keeps it fresh.
//
// Page record table 0x887518D0: 0x200 records of 5 dwords (0x14 bytes), addressed as a flat
// dword array (see PAGE_* indices below).
//   [0] 0x00 tex        D3D texture handle, owned by 0x8808D838 (0 = none)
//   [1] 0x04 sizeState  size the texture currently IS; 0x8808D838 writes it
//   [2] 0x08 srcBuf     linear CPU staging image, freed here once uploaded
//   [3] 0x0C state      0 = upload pending, non-zero = release requested (SIGNED)
//   [4] 0x10 stageSize  size the staging image was written for

typedef unsigned int u32;

// ---------------------------------------------------------------- Win32 / D3D / XG types
struct RECT  { int left; int top; int right; int bottom; };
struct POINT { int x; int y; };

struct D3DLOCKED_RECT
{
    u32   Pitch;            // 0x00  bytes between rows of the locked image
    void* pBits;            // 0x04
};

// XGTEXTURE_DESC, xgraphics.h — 15 dwords / 0x3C bytes.
struct XGTEXTURE_DESC
{
    u32 ResourceType;       // 0x00
    u32 Width;              // 0x04
    u32 Height;             // 0x08
    u32 Depth;              // 0x0C
    u32 Format;             // 0x10
    u32 RowPitch;           // 0x14
    u32 SlicePitch;         // 0x18
    u32 BitsPerPixel;       // 0x1C
    u32 WidthInBlocks;      // 0x20
    u32 HeightInBlocks;     // 0x24
    u32 DepthInBlocks;      // 0x28
    u32 BytesPerBlock;      // 0x2C
    int ExpBias;            // 0x30
    u32 Flags;              // 0x34
    u32 MultiSampleType;    // 0x38
};

// ---------------------------------------------------------------- page record table
const u32 PAGE_COUNT  = 0x200;      // records in the table
const u32 PAGE_STRIDE = 5;          // dwords per record

const u32 PAGE_TEX       = 0;       // record dword indices
const u32 PAGE_SIZESTATE = 1;
const u32 PAGE_SRCBUF    = 2;
const u32 PAGE_STATE     = 3;
const u32 PAGE_STAGESIZE = 4;

const u32 PAGE_BYTES_PER_TEXEL = 2; // pages are a 16bpp format (packed word 0x18280143)

// 0x887518D0 — the page record table, addressed as a flat dword array.
extern u32 g_pageTable[PAGE_COUNT * PAGE_STRIDE];
// 0x887398A8 — the lock the whole page family serialises on.
extern u32 g_pageLock;

// 0x8824EAD0 / 0x8824EAE0 — page-table lock enter/leave (retail bodies are nop;nop;nop;blr).
extern "C" void PageLock_Enter(u32* lock);
extern "C" void PageLock_Leave(u32* lock);

// 0x8808D838 — ensure page `pageId` has a live texture at `sizeState`; returns 0 on failure.
extern "C" int Page_EnsureTexture(u32 pageId, u32 sizeState);
// 0x8807F8C8 — release a texture object.
extern "C" void Gpu_ReleaseTexture(u32 tex);
// 0x88083758 — free a heap block.
extern "C" void Mem_Free(u32 block);

// 0x88083380 — SetRect(lprc, xLeft, yTop, xRight, yBottom).
extern "C" int SetRect(RECT* lprc, int xLeft, int yTop, int xRight, int yBottom);
// 0x88082978 -> 0x88082548 — XGGetTextureDesc(pTexture, Level, pDesc).
extern "C" void XGGetTextureDesc(u32 tex, u32 level, XGTEXTURE_DESC* desc);
// 0x88079948 — D3DTexture_LockRect(tex, level, pLockedRect, pRect, flags).
extern "C" u32 D3DTexture_LockRect(u32 tex, u32 level, D3DLOCKED_RECT* locked,
                                   const RECT* rect, u32 flags);
// 0x88078308 — D3DTexture_UnlockRect(tex, level).
extern "C" void D3DTexture_UnlockRect(u32 tex, u32 level);
// 0x880822C0 -> 0x88081EF0 — XGTileSurface(pDestination, Width, Height, pPoint,
//                                          pSource, RowPitch, pRect, TexelPitch).
extern "C" void XGTileSurface(void* dest, u32 width, u32 height, const POINT* point,
                              const void* source, u32 rowPitch, const RECT* rect,
                              u32 texelPitch);

// The real CRT signature: MSVC expands this inline as a counted stdu/bdnz zero-fill.
// (`XGTEXTURE_DESC desc = {0};` instead emits a CALL to memset — not what the game does.)
extern "C" void* memset(void* dst, int c, unsigned int n);

void Page_FillFromCpu(void)
{
    PageLock_Enter(&g_pageLock);

    u32 rec = 0;            // dword index of the current record
    u32 pageId = 0;

    for (int n = PAGE_COUNT; n != 0; n--)
    {
        // The state slot is a signed flag, so this is a signed test.
        if ((int)g_pageTable[rec + PAGE_STATE] != 0)
        {
            // Release requested: drop the texture and re-arm the record.
            if (g_pageTable[rec + PAGE_TEX] != 0)
            {
                Gpu_ReleaseTexture(g_pageTable[rec + PAGE_TEX]);
                g_pageTable[rec + PAGE_TEX] = 0;
            }
            g_pageTable[rec + PAGE_STATE] = 0;
        }
        else if (g_pageTable[rec + PAGE_SRCBUF] != 0)
        {
            if (Page_EnsureTexture(pageId, g_pageTable[rec + PAGE_STAGESIZE]) != 0)
            {
                // sizeState is only trustworthy after the ensure above rewrote it.
                u32 dim = g_pageTable[rec + PAGE_SIZESTATE] << 8;

                POINT destPoint;
                destPoint.x = 0;
                destPoint.y = 0;

                D3DLOCKED_RECT locked;
                RECT srcRect;
                XGTEXTURE_DESC desc;
                memset(&desc, 0, sizeof(desc));

                XGGetTextureDesc(g_pageTable[rec + PAGE_TEX], 0, &desc);
                SetRect(&srcRect, 0, 0, dim, dim);
                D3DTexture_LockRect(g_pageTable[rec + PAGE_TEX], 0, &locked, &srcRect, 0);
                XGTileSurface(locked.pBits,
                              locked.Pitch / desc.BytesPerBlock,     // dest width in blocks
                              desc.HeightInBlocks,
                              &destPoint,
                              (const void*)g_pageTable[rec + PAGE_SRCBUF],
                              dim * PAGE_BYTES_PER_TEXEL,            // linear source row pitch
                              &srcRect,
                              desc.BytesPerBlock);
                D3DTexture_UnlockRect(g_pageTable[rec + PAGE_TEX], 0);
            }

            Mem_Free(g_pageTable[rec + PAGE_SRCBUF]);
            g_pageTable[rec + PAGE_SRCBUF] = 0;
        }

        pageId++;
        rec += PAGE_STRIDE;
    }

    PageLock_Leave(&g_pageLock);
}
