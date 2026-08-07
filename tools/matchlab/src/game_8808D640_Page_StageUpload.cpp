// 0x8808D640 (game module) — scroll-cache PAGE STAGING UPLOAD.
//
// The CPU-side half of the select-screen page engine described in
// decomp/game/NOTES_select_compose.md. Callers hand this function a freshly decoded
// page image (the decode buffer + 0x10 header) and it parks a private copy in the
// page record's staging buffer. 0x8808DF70 later walks the whole record table, sees
// state == 0 with a non-null srcBuf, and LockRect-copies that staging buffer into the
// page's D3D texture, then frees it.
//
// Page record table 0x887518D0: 0x200 records of 5 dwords (0x14 bytes).
//   [0] tex        D3D texture handle (0x8808D838 owns this one)
//   [1] texSize    size-state the texture was created at
//   [2] srcBuf     staging buffer allocated here, freed after upload
//   [3] state      0 = an upload is pending
//   [4] stageSize  size-state the staging buffer was sized for
//
// A page is (sizeState << 8) texels square at 2 bytes/texel, so the staging buffer is
// dim * dim * 2 bytes; sizeState 2 => 512x512 => 512KB.

typedef unsigned int u32;

const u32 PAGE_COUNT  = 0x200;   // records in the table
const u32 PAGE_STRIDE = 5;       // dwords per record
const u32 PAGE_SRCBUF = 2;       // record dword indices
const u32 PAGE_STATE  = 3;
const u32 PAGE_STAGESIZE = 4;

const u32 PAGE_BYTES_PER_TEXEL = 2;

// 0x887518D0 — the page record table, addressed as a flat dword array.
extern u32 g_pageTable[PAGE_COUNT * PAGE_STRIDE];
// 0x887AD5D0 — the D3D device; nothing may touch the page table before it exists.
extern u32 g_device;
// 0x887398A8 — the lock the whole page family serialises on.
extern u32 g_pageLock;

// 0x8824EAD0 / 0x8824EAE0 — page-table lock enter/leave (retail bodies are nop;nop;nop;blr).
extern "C" void PageLock_Enter(u32* lock);
extern "C" void PageLock_Leave(u32* lock);

// 0x88083758 — free a heap block.
extern "C" void Mem_Free(u32 block);
// 0x880836D0 — allocate (size, heap = -1 meaning default, alignment, tag).
extern "C" u32 Mem_Alloc(u32 size, int heap, u32 align, u32 tag);

extern "C" void* memcpy(void* dst, const void* src, unsigned int n);

bool Page_StageUpload(u32 pageId, const void* src, u32 sizeState)
{
    u32 dim = sizeState << 8;
    u32 bytes = dim * dim * PAGE_BYTES_PER_TEXEL;
    bool staged = false;

    if (pageId >= PAGE_COUNT)
        return false;
    if (g_device == 0)
        return false;

    PageLock_Enter(&g_pageLock);

    u32 rec = pageId * PAGE_STRIDE;

    // A size change invalidates whatever is already parked here.
    if (g_pageTable[rec + PAGE_SRCBUF] != 0 &&
        g_pageTable[rec + PAGE_STAGESIZE] != sizeState)
    {
        Mem_Free(g_pageTable[rec + PAGE_SRCBUF]);
        g_pageTable[rec + PAGE_SRCBUF] = 0;
    }

    if (g_pageTable[rec + PAGE_SRCBUF] == 0)
        g_pageTable[rec + PAGE_SRCBUF] = Mem_Alloc(bytes, -1, 0x10, 4);

    if (g_pageTable[rec + PAGE_SRCBUF] != 0)
    {
        g_pageTable[rec + PAGE_STAGESIZE] = sizeState;
        g_pageTable[rec + PAGE_STATE] = 0;              // arm the pending-upload flag
        memcpy((void*)g_pageTable[rec + PAGE_SRCBUF], src, bytes);
        staged = true;
    }

    PageLock_Leave(&g_pageLock);
    return staged;
}
