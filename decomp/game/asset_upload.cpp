// decomp/game/asset_upload.cpp — the ASSET PIPELINE'S LAST MILE: the two PAGE-CACHE writers.
//
// asset_pump.cpp's state-5 arm ends by handing a decoded image to sub_8808D640; that call was the
// last still-GENERATED callee of the pump (see the "STILL GENERATED" list in asset_pump.cpp's
// header). This file folds it — and its consumer twin sub_8808DF70 — into the decomp, closing the
// chain archive → decode → pump → **upload** end to end in human-readable C.
//
// Both functions are ASM-EXACT in tools/matchlab (matchlab is the byte-level oracle: its C sources
// compile under XDK 9328 cl.exe 15.00.8327 to the ORIGINAL instruction bytes):
//   * 0x8808D640  tools/matchlab/src/game_8808D640_Page_StageUpload.cpp   63 insn
//                 sha1 d0122ee89e5df4258bc155879b034c184e734e6a
//   * 0x8808DF70  tools/matchlab/src/game_8808DF70_Page_FillFromCpu.cpp   81 insn
//                 sha1 26025ea09a3f961e76ca5408e6809cb76b055b40
// That is a stronger provenance than any other function this campaign has translated: the field
// names, the record layout, the argument order and the XG/D3D call signatures below are not
// inferred from the recomp — they are the shapes that PROVABLY rebuild the shipped bytes. Hence
// NATURAL READABLE C for both (no faithful-transcription fallback was needed): there is no
// residual uncertainty for the live differential to resolve, only execution to witness.
//
// ════════════════════════════════════════════════════════════════════════════════════════════════
// THE PAGE CACHE (the select-screen / backdrop scroll cache — docs: decomp/game/NOTES_select_compose.md)
// ════════════════════════════════════════════════════════════════════════════════════════════════
// A "page" is a square 16bpp texture (fixed format word 0x18280143) whose edge is sizeState<<8 —
// sizeState 1 → 256×256, sizeState 2 → 512×512. 0x200 (512) page records live in a flat table at
// 0x887518D0, 5 dwords (0x14 bytes) each:
//
//   rec+0x00  tex        D3D texture handle. OWNED BY sub_8808D838 (Page_EnsureTexture); 0 = none.
//   rec+0x04  sizeState  the size the texture currently IS (written by sub_8808D838).
//   rec+0x08  srcBuf     linear CPU staging image — ALLOCATED BY sub_8808D640, FREED BY sub_8808DF70.
//   rec+0x0C  state      SIGNED flag. 0 = "upload pending" (the normal armed state); non-zero =
//                        "release requested" (some other page API asks for the texture to be dropped).
//   rec+0x10  stageSize  the sizeState the staging image was written for (a mismatch invalidates it).
//
// The whole page family serialises on one lock at 0x887398A8 (RtlEnter/LeaveCriticalSection —
// the retail import bodies are nop;nop;nop;blr, so this is free, but the calls ARE reproduced:
// they are real bl boundaries the call-graph instruments and any future hook can observe).
//
// THE TWO WRITERS, AND WHY THERE ARE TWO
//   PRODUCER  sub_8808D640(pageId, src, sizeState) — runs ON THE ASSET-PUMP THREAD, at the end of
//     the pump's state-5 arm (asset_pump.cpp, ppc_recomp.18.cpp:11978), and from the upload-
//     descriptor family sub_88090C90/… (ppc_recomp.5.cpp:2050/2101/2152/2293/2431). It may NOT touch
//     the GPU: it only parks a private CPU copy of the freshly decoded image in rec.srcBuf, sized
//     dim*dim*2, arming rec.state = 0. Returns 1 if the copy was parked, 0 if it was refused
//     (pageId out of range / no device yet / the staging allocation failed).
//   CONSUMER  sub_8808DF70() — runs on the RENDER side (its only caller is sub_8808E468, the family
//     that also drives the sub_8808DC10 page bake). It sweeps ALL 512 records once under the lock and
//     per record either (a) honours a release request, or (b) drains a pending upload: ensure the
//     texture exists at stageSize (sub_8808D838), then TILE the linear staging image into the
//     texture's memory (XGTileSurface) and free the staging buffer.
//   The split is the classic decouple: the streaming/decode thread never calls D3D, and the render
//   thread never blocks on I/O. rec.srcBuf is the mailbox between them; the lock is the handshake.
//
// ⚠ THE COPY IS A TILE, NOT A MEMCPY. GPU texture memory on Xenos is tiled; the staged image is
// linear. sub_8808DF70 takes the destination extent from XGGetTextureDesc (RowPitch/BytesPerBlock,
// HeightInBlocks) rather than from the page size, so a padded row pitch is honoured — a plain
// memcpy of dim*dim*2 bytes into locked.pBits would be WRONG on any padded texture. Anyone porting
// this path to the native renderer must reproduce the untiled→tiled step, not just the byte count.
//
// ════════════════════════════════════════════════════════════════════════════════════════════════
// GUEST STATE (addresses derived from the recomp lis/addi decimals; all confirmed against matchlab)
// ════════════════════════════════════════════════════════════════════════════════════════════════
//   0x887518D0  PAGE_TABLE   512 × 0x14-byte page records          [lis -30603 (0x88750000) + 6352]
//   0x887398A8  PAGE_LOCK    the page-family critical section      [lis -30604 (0x88740000) - 26456]
//   0x887AD5D0  G_DEVICE     the D3D device; 0 = nothing may touch the page table
//                                                                  [lis -30597 (0x887B0000) - 10800]
//
// ════════════════════════════════════════════════════════════════════════════════════════════════
// SEAM (PILOT_NOTES §2): BOTH ARE UNHOOKED → plain PPC_FUNC for both.
//   Measured, not assumed: no strong PPC_FUNC(sub_8808D640) / PPC_FUNC(sub_8808DF70) exists in
//   out_reco/merged/*.cpp (or anywhere outside the generated tree) — grep for the addresses returns
//   only asset_pump.cpp's prose + the mapping tables. So the SHADOWED-HOOK (__imp__) form is NOT
//   needed here; a strong body beats the generated weak alias, exactly like asset_pump.cpp's
//   sub_8813A6A0 and archive.cpp's sub_88092AA8.
//   decomp/game/*.cpp is auto-globbed and linked FIRST (build_win.sh:49, build_win_dll.sh:192), so
//   these win; the generated __imp__ bodies stay linked as dead rollback bytes.
//   ROLLBACK = drop obj_win/decomp_asset_upload.o. No build-line edit.
//
// C1 REGISTER-FILE DISCIPLINE (PILOT_NOTES §2) — both bodies are NON-LEAVES:
//   At every bl boundary the exact argument registers the generated body presents are set, plus
//   ctx.lr = that call's generated return address, and the callee is invoked through its plain
//   sub_* symbol so its own instrument wrapper (if any) keeps firing. The guest frame IS emulated
//   (back-chain store + r1 move, restored on every exit path) so callee frames — and, in
//   sub_8808DF70, the D3D/XG out-parameter structs that live IN that frame — land at the generated
//   guest addresses. Deliberately-accepted residuals, same class as PILOT_NOTES §6: the
//   __savegprlr_24/__restgprlr_24 (D640) and __savegprlr_26/__restgprlr_26 (DF70) nonvolatile-save
//   scratch bytes are not written (host-register state with no guest meaning; nothing walks the
//   back chain), ctx nonvolatiles are never clobbered (strictly more conservative than the
//   generated save/restore pair), and callee-clobbered volatiles differ at exit — no caller of
//   either function reads anything but r3.
//
// CALLEE STATUS at the bl boundaries:
//   TRANSLATED: sub_88072260 (guest memcpy — decomp/game/mem_util.cpp).
//   STILL GENERATED (called via plain sub_* so their wrappers keep firing): sub_880836D0 (aligned
//     alloc), sub_88083758 (free), sub_8808D838 (page-texture ensure), sub_8807F8C8 (texture
//     release), sub_88082978→sub_88082548 (XGGetTextureDesc), sub_88083380 (SetRect),
//     sub_88079948 (D3DTexture_LockRect), sub_880822C0→sub_88081EF0 (XGTileSurface),
//     sub_88078308 (D3DTexture_UnlockRect), and the two Rtl*CriticalSection imports.
// ════════════════════════════════════════════════════════════════════════════════════════════════

#include "ppc_recomp_shared.h"   // ppc_config.h (base 0x88000000) + ppc_context.h + all callee decls

namespace {

// ── the page record table ────────────────────────────────────────────────────────────────────────
constexpr uint32_t PAGE_TABLE  = 0x887518D0;   // 512 records                [lis -30603 + 6352]
constexpr uint32_t PAGE_LOCK   = 0x887398A8;   // the page-family lock       [lis -30604 - 26456]
constexpr uint32_t G_DEVICE    = 0x887AD5D0;   // D3D device (0 = not up)    [lis -30597 - 10800]

constexpr uint32_t PAGE_COUNT  = 0x200;        // records in the table (li r27,512 / cmplwi r3,512)
constexpr uint32_t PAGE_STRIDE = 0x14;         // 5 dwords per record

constexpr uint32_t REC_TEX       = 0x00;       // D3D texture handle (sub_8808D838 owns it)
constexpr uint32_t REC_SIZESTATE = 0x04;       // size the texture currently IS
constexpr uint32_t REC_SRCBUF    = 0x08;       // linear CPU staging image
constexpr uint32_t REC_STATE     = 0x0C;       // 0 = upload pending, non-zero = release requested
constexpr uint32_t REC_STAGESIZE = 0x10;       // size the staging image was written for

constexpr uint32_t BYTES_PER_TEXEL = 2;        // pages are 16bpp (packed format word 0x18280143)

// ── XGTEXTURE_DESC (xgraphics.h, 15 dwords / 0x3C bytes) — only two fields are consumed ─────────
constexpr uint32_t XGDESC_SIZE           = 0x3C;
constexpr uint32_t XGDESC_HEIGHTINBLOCKS = 0x24;
constexpr uint32_t XGDESC_BYTESPERBLOCK  = 0x2C;

} // namespace

// ════════════════════════════════════════════════════════════════════════════════════════════════
// sub_8808D640 — PAGE STAGING UPLOAD (the PRODUCER half). UNHOOKED → plain PPC_FUNC. NON-LEAF.
//
//   sub_8808D640(pageId = r3, src = r4, sizeState = r5) -> r3 = 1 if staged, 0 if refused
//
// Ground truth: out_reco/ppc_recomp.4.cpp:8442-8587 (register-exact recomp, entry → __restgprlr_24
// tail). Matchlab twin: Page_StageUpload, ASM-EXACT (63 insn).
//
// Parks a private copy of a freshly decoded page image in the record's staging buffer:
//   dim   = sizeState << 8            (rlwinm r11,r5,8,0,23 — masked to 24 bits, so it is a
//                                      *256 of the low 24 bits of sizeState, not a full <<8)
//   bytes = dim * dim * 2             (mullw + rlwinm ...,1,0,30 — 32-bit wrapping, as generated)
// A size change invalidates whatever is already parked (free + re-alloc at the new size); the
// staging buffer is otherwise REUSED across uploads of the same page — that reuse is why the
// stageSize field exists at all. Sets state = 0 (upload pending) before the copy, so a consumer
// sweep that races in with the lock held sees a fully-armed record or nothing.
//
// C1 boundaries (4): RtlEnterCriticalSection lr=0x8808D69C r3=lock · sub_88083758(free) lr=0x8808D6D4
// r3=srcBuf · sub_880836D0(alloc) lr=0x8808D6F8 r3=bytes r4=-1 r5=16(align) r6=4(tag) ·
// sub_88072260(memcpy) lr=0x8808D724 r3=dst r4=src r5=bytes · RtlLeaveCriticalSection lr=0x8808D730.
// Exit r3 is written AFTER the leave call (mr r3,r25), matching the generated order.
// ════════════════════════════════════════════════════════════════════════════════════════════════
PPC_FUNC(sub_8808D640)
{
    PPC_FUNC_PROLOGUE();
    const uint32_t pageId    = ctx.r3.u32;
    const uint32_t src       = ctx.r4.u32;
    const uint32_t sizeState = ctx.r5.u32;

    const uint32_t sp = ctx.r1.u32 - 160;             // stwu r1,-160(r1)
    PPC_STORE_U32(sp, ctx.r1.u32);
    ctx.r1.u32 = sp;

    const uint32_t dim   = (sizeState << 8) & 0xFFFFFF00u;   // page edge in texels
    const uint32_t bytes = (dim * dim) << 1;                 // dim*dim*BYTES_PER_TEXEL, 32-bit wrap
    static_assert(BYTES_PER_TEXEL == 2, "the <<1 above IS the *BYTES_PER_TEXEL");

    // Refuse out-of-range pages, and refuse everything before the device exists — nothing may
    // touch the page table until then (the texture handles it holds would be meaningless).
    if (pageId >= PAGE_COUNT || PPC_LOAD_U32(G_DEVICE) == 0)
    {
        ctx.r1.u32 = sp + 160;
        ctx.r3.s64 = 0;
        return;
    }

    ctx.r3.u32 = PAGE_LOCK; ctx.lr = 0x8808D69C; __imp__RtlEnterCriticalSection(ctx, base);

    const uint32_t rec = PAGE_TABLE + pageId * PAGE_STRIDE;   // rlwinm/add/rlwinm = pageId*5*4

    // A size change invalidates whatever is already parked here.
    if (PPC_LOAD_U32(rec + REC_SRCBUF) != 0 &&
        PPC_LOAD_U32(rec + REC_STAGESIZE) != sizeState)
    {
        ctx.r3.u32 = PPC_LOAD_U32(rec + REC_SRCBUF);
        ctx.lr = 0x8808D6D4; sub_88083758(ctx, base);         // Mem_Free(srcBuf)
        PPC_STORE_U32(rec + REC_SRCBUF, 0);
    }

    if (PPC_LOAD_U32(rec + REC_SRCBUF) == 0)
    {
        ctx.r3.u32 = bytes; ctx.r4.s64 = -1; ctx.r5.u64 = 16; ctx.r6.u64 = 4;
        ctx.lr = 0x8808D6F8; sub_880836D0(ctx, base);         // Mem_Alloc(bytes, heap -1, align 16, tag 4)
        PPC_STORE_U32(rec + REC_SRCBUF, ctx.r3.u32);
    }

    uint32_t staged = 0;
    const uint32_t srcBuf = PPC_LOAD_U32(rec + REC_SRCBUF);
    if (srcBuf != 0)
    {
        PPC_STORE_U32(rec + REC_STAGESIZE, sizeState);        // the buffer is now sized for this state
        PPC_STORE_U32(rec + REC_STATE, 0);                    // arm the pending-upload flag
        ctx.r3.u32 = srcBuf; ctx.r4.u32 = src; ctx.r5.u32 = bytes;
        ctx.lr = 0x8808D724; sub_88072260(ctx, base);         // memcpy(srcBuf, src, bytes)
        staged = 1;
    }

    ctx.r3.u32 = PAGE_LOCK; ctx.lr = 0x8808D730; __imp__RtlLeaveCriticalSection(ctx, base);

    ctx.r1.u32 = sp + 160;
    ctx.r3.u64 = staged;   // r3 set after the leave call, as generated (mr r3,r25)
}

// ════════════════════════════════════════════════════════════════════════════════════════════════
// sub_8808DF70 — PAGE FILL FROM CPU (the CONSUMER half). UNHOOKED → plain PPC_FUNC. NON-LEAF.
//
//   sub_8808DF70(void)   [no arguments, no meaningful return]
//
// Ground truth: out_reco/ppc_recomp.4.cpp:9924-10115 (register-exact recomp, entry → __restgprlr_26
// tail). Matchlab twin: Page_FillFromCpu, ASM-EXACT (81 insn). Only caller: sub_8808E468
// (ppc_recomp.4.cpp:10792) — the render-side family that also drives the sub_8808DC10 page bake.
//
// One sweep of all 512 records under the page lock. Per record, exactly one of:
//   state != 0  (SIGNED test) → a release was requested: drop the texture, re-arm state = 0.
//   state == 0 && srcBuf != 0 → an upload is pending: ensure the texture exists at stageSize, tile
//                               the staged linear image into it, and free the staging buffer.
// The free happens even when the ensure FAILS — a page that cannot get a texture must not keep its
// staging buffer alive forever (that is the leak this ordering prevents; note the generated body
// falls through to the free at loc_8808E088 on both arms).
//
// THE TILE, argument by argument (sub_880822C0 → sub_88081EF0 = XGTileSurface):
//   dest        = locked.pBits                       (r3, from the LockRect out-struct)
//   width       = locked.Pitch / desc.BytesPerBlock  (r4, DESTINATION width in BLOCKS — this is why
//                                                     the padded row pitch is honoured; divwu, so a
//                                                     zero BytesPerBlock yields 0, not a trap)
//   height      = desc.HeightInBlocks                (r5)
//   pPoint      = &destPoint {0,0}                   (r6)
//   source      = rec.srcBuf                         (r7, the linear staged image)
//   rowPitch    = dim * 2                            (r8, the SOURCE row pitch — linear, unpadded)
//   pRect       = &srcRect {0,0,dim,dim}             (r9)
//   texelPitch  = desc.BytesPerBlock                 (r10)
// ⚠ dim comes from rec.sizeState (the size the texture IS), read AFTER the ensure call rewrote it —
// NOT from the stageSize that was passed to the ensure. Reading it before would be wrong on the
// first upload of a page whose texture had to be created.
//
// GUEST FRAME (stwu r1,-240): the D3D/XG out-parameters live in it, so it must be emulated —
//   sp+80  destPoint  POINT{x,y}, zeroed per record
//   sp+88  locked     D3DLOCKED_RECT{Pitch@+0, pBits@+4}
//   sp+96  srcRect    RECT{left,top,right,bottom}
//   sp+112 desc       XGTEXTURE_DESC, 0x3C bytes, zeroed per record (the generated body's inlined
//                     7×stdu + 1×stw zero-fill = the CRT memset MSVC expanded inline; reproduced
//                     as the same 60 bytes)
//
// C1 boundaries (8): RtlEnter lr=0x8808DF8C · sub_8807F8C8(release) lr=0x8808DFBC ·
// sub_8808D838(ensure) lr=0x8808DFE0 · sub_88082978(XGGetTextureDesc) lr=0x8808E024 ·
// sub_88083380(SetRect) lr=0x8808E03C · sub_88079948(LockRect) lr=0x8808E054 ·
// sub_880822C0(XGTileSurface) lr=0x8808E07C · sub_88078308(UnlockRect) lr=0x8808E088 ·
// sub_88083758(free) lr=0x8808E090 · RtlLeave lr=0x8808E0AC. Exit r3 is left as the leave call's
// leftover — the generated body does not write r3 after it, and no caller reads one.
// ════════════════════════════════════════════════════════════════════════════════════════════════
PPC_FUNC(sub_8808DF70)
{
    PPC_FUNC_PROLOGUE();

    const uint32_t sp = ctx.r1.u32 - 240;             // stwu r1,-240(r1)
    PPC_STORE_U32(sp, ctx.r1.u32);
    ctx.r1.u32 = sp;

    const uint32_t destPoint = sp + 80;               // POINT   {x, y}
    const uint32_t locked    = sp + 88;               // D3DLOCKED_RECT {Pitch, pBits}
    const uint32_t srcRect   = sp + 96;               // RECT    {left, top, right, bottom}
    const uint32_t desc      = sp + 112;              // XGTEXTURE_DESC (0x3C bytes)

    ctx.r3.u32 = PAGE_LOCK; ctx.lr = 0x8808DF8C; __imp__RtlEnterCriticalSection(ctx, base);

    uint32_t rec = PAGE_TABLE;
    for (uint32_t pageId = 0; pageId < PAGE_COUNT; ++pageId, rec += PAGE_STRIDE)
    {
        // The state slot is a signed flag (cmpwi), so this is a signed test.
        if (PPC_LOAD_U32(rec + REC_STATE) != 0)
        {
            // Release requested: drop the texture and re-arm the record.
            if (PPC_LOAD_U32(rec + REC_TEX) != 0)
            {
                ctx.r3.u32 = PPC_LOAD_U32(rec + REC_TEX);
                ctx.lr = 0x8808DFBC; sub_8807F8C8(ctx, base);      // Gpu_ReleaseTexture(tex)
                PPC_STORE_U32(rec + REC_TEX, 0);
            }
            PPC_STORE_U32(rec + REC_STATE, 0);
            continue;
        }

        if (PPC_LOAD_U32(rec + REC_SRCBUF) == 0)
            continue;                                             // nothing pending on this page

        // Make sure the page has a live texture at the size the staged image was written for.
        ctx.r3.u32 = pageId; ctx.r4.u32 = PPC_LOAD_U32(rec + REC_STAGESIZE);
        ctx.lr = 0x8808DFE0; sub_8808D838(ctx, base);              // Page_EnsureTexture(pageId, stageSize)
        if (ctx.r3.s32 != 0)
        {
            // sizeState is only trustworthy after the ensure above rewrote it.
            const uint32_t dim = (PPC_LOAD_U32(rec + REC_SIZESTATE) << 8) & 0xFFFFFF00u;

            PPC_STORE_U32(destPoint + 0, 0);                       // destPoint = {0, 0}
            PPC_STORE_U32(destPoint + 4, 0);
            for (uint32_t off = 0; off + 8 <= XGDESC_SIZE; off += 8)   // memset(&desc, 0, 0x3C):
                PPC_STORE_U64(desc + off, 0);                          //   7 × stdu (56 bytes) …
            PPC_STORE_U32(desc + (XGDESC_SIZE - 4), 0);                //   … + 1 × stw (the tail dword)

            // rec.tex is RE-LOADED at each of the three call sites, as the generated body does
            // (lwz r3,0(r31) before each) — not hoisted into a local. Nothing in this call chain
            // rewrites it today, but the reload is free and keeps the memory trace identical.
            ctx.r3.u32 = PPC_LOAD_U32(rec + REC_TEX); ctx.r4.u64 = 0; ctx.r5.u32 = desc;
            ctx.lr = 0x8808E024; sub_88082978(ctx, base);          // XGGetTextureDesc(tex, 0, &desc)

            ctx.r3.u32 = srcRect; ctx.r4.u64 = 0; ctx.r5.u64 = 0; ctx.r6.u32 = dim; ctx.r7.u32 = dim;
            ctx.lr = 0x8808E03C; sub_88083380(ctx, base);          // SetRect(&srcRect, 0, 0, dim, dim)

            ctx.r3.u32 = PPC_LOAD_U32(rec + REC_TEX);
            ctx.r4.u64 = 0; ctx.r5.u32 = locked; ctx.r6.u32 = srcRect; ctx.r7.u64 = 0;
            ctx.lr = 0x8808E054; sub_88079948(ctx, base);          // D3DTexture_LockRect(tex,0,&locked,&srcRect,0)

            const uint32_t bytesPerBlock = PPC_LOAD_U32(desc + XGDESC_BYTESPERBLOCK);
            ctx.r3.u32  = PPC_LOAD_U32(locked + 4);                        // locked.pBits
            ctx.r4.u32  = ppc_divwu(PPC_LOAD_U32(locked + 0), bytesPerBlock);   // pitch / bytesPerBlock
            ctx.r5.u32  = PPC_LOAD_U32(desc + XGDESC_HEIGHTINBLOCKS);
            ctx.r6.u32  = destPoint;
            ctx.r7.u32  = PPC_LOAD_U32(rec + REC_SRCBUF);
            ctx.r8.u32  = dim * BYTES_PER_TEXEL;                            // linear source row pitch
            ctx.r9.u32  = srcRect;
            ctx.r10.u32 = bytesPerBlock;
            ctx.lr = 0x8808E07C; sub_880822C0(ctx, base);          // XGTileSurface(...)

            ctx.r3.u32 = PPC_LOAD_U32(rec + REC_TEX); ctx.r4.u64 = 0;
            ctx.lr = 0x8808E088; sub_88078308(ctx, base);          // D3DTexture_UnlockRect(tex, 0)
        }

        // Reached on BOTH arms — a page that could not get a texture must not keep the staging
        // buffer alive (the generated body falls through to loc_8808E088 either way).
        ctx.r3.u32 = PPC_LOAD_U32(rec + REC_SRCBUF);
        ctx.lr = 0x8808E090; sub_88083758(ctx, base);              // Mem_Free(srcBuf)
        PPC_STORE_U32(rec + REC_SRCBUF, 0);
    }

    ctx.r3.u32 = PAGE_LOCK; ctx.lr = 0x8808E0AC; __imp__RtlLeaveCriticalSection(ctx, base);

    ctx.r1.u32 = sp + 240;
    // r3 left = the leave call's leftover, matching the generated exit (no mr r3 after it).
}
