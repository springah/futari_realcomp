// decomp/game/archive.cpp — the game module's ARCHIVE / TOC / FILE-READ cluster.
//
// This is the ASSET-PIPELINE archive half (registry / ATLAS AP§2): archive-open → id→bytes →
// (job-ring) → decode → upload. It owns the low-level file read, the archive header/TOC parse,
// the id→raw-bytes recipe, the per-id cache, the synchronous read path, and teardown. The DECODE
// half (mode 1..4 decompressors) lives in decomp/game/asset_decode.cpp (parallel agent); the job
// pump sub_8813A738 that ties archive+decode together is the main session's consolidation target.
//
// GROUND TRUTH: out_reco/ppc_recomp.5.cpp (register-exact recomp) — the archive cluster is at
// :6145-7834; the descriptor id-chain walker sub_8813A460 is at out_reco/ppc_recomp.18.cpp:10906.
// Every constant/offset below is cited to a guest address computed from that recomp's lis/addi
// pairs. (reco_normal_decomp_all.txt was not seeded into this worktree; the register-exact recomp
// is authoritative and self-consistent — the two agree per plan §3.5 wherever both are present.)
//
// ════════════════════════════════════════════════════════════════════════════════════════════════
// ARCHIVE FORMAT (derived byte-for-byte from sub_88092ED8's parse + validation)
// ════════════════════════════════════════════════════════════════════════════════════════════════
// The main archive is one file (opened by sub_880928D8, still generated). Its handle is cached at
// guest 0x88252E1C. Everything is BIG-ENDIAN on disk.
//
//   ── 16-byte FILE HEADER (read at file offset 0) ──────────────────────────────────────────────
//     hdr[0..3]   magic / version — READ into the stack buffer but NOT parsed (ignored).
//     hdr[4..7]   totalSize   → cached at 0x887AD1A0. Validated: must equal the real file size
//                               (sub_88082B88). Used as the bound for every TOC entry.
//     hdr[8..11]  dataStart   → cached at 0x887AD1A4. Validated: must equal 16 + entryCount*12
//                               (i.e. the byte just past the header + the raw 12-byte TOC records).
//     hdr[12..15] entryCount  → cached at 0x887AD19C. Number of resources in the archive.
//
//   ── RAW TOC: entryCount × 12-byte records, at file offset 16 ──────────────────────────────────
//   Read verbatim into a scratch buffer, then EXPANDED into the in-memory 0x14-byte TOC (below).
//   Each 12-byte record (big-endian fields):
//     rec[0..1]   u16 kind/type   → entry+0
//     rec[2]      u8              → entry+2
//     rec[3]      u8              → entry+3
//     rec[4..7]   u32 length      → entry+8   (bytes to read for this resource)
//     rec[8..11]  u32 fileOffset  → entry+4   (absolute byte offset in the archive file)
//   Per-record validation during expansion (stops the parse on the first bad record):
//     fileOffset < totalSize   AND   fileOffset + length <= totalSize.
//
//   ── IN-MEMORY TOC: entryCount × 0x14 (20) bytes, heap-allocated, zero-filled, at 0x887AD1A8 ────
//     entry+0   u16 kind          (from rec[0..1])
//     entry+2   u8                (from rec[2])
//     entry+3   u8                (from rec[3])
//     entry+4   u32 fileOffset    (from rec[8..11])   ← read arg to sub_880927A8
//     entry+8   u32 length        (from rec[4..7])    ← read arg to sub_880927A8
//     entry+12  u32 cachePtr      (0; lazily filled by sub_88092B80 with a heap buffer)
//     entry+16  u32 cacheState    (0; the streaming worker sub_88092C28 sets 1=pending / 2=loaded)
//
//   sub_88092AA8 turns an id into bytes: bound-check id<entryCount, entry = TOC + id*0x14, then
//   read entry->length bytes at entry->fileOffset into the caller's buffer.
//
// ════════════════════════════════════════════════════════════════════════════════════════════════
// GUEST STATE BLOCK (all addresses cited from the recomp lis/addi decimals)
// ════════════════════════════════════════════════════════════════════════════════════════════════
//   0x88252E1C  ARC_FILE_HANDLE   main archive file handle (-1 = closed)         [-30683<<16 +11804]
//   0x887AD19C  ARC_TOC_COUNT     entryCount                                     [-30597<<16 -11876]
//   0x887AD1A0  ARC_TOC_SIZE      totalSize (== file size)                       [-30597<<16 -11872]
//   0x887AD1A4  ARC_TOC_DATASTART dataStart (== 16 + count*12)                   [-30597<<16 -11868]
//   0x887AD1A8  ARC_TOC_PTR       in-memory TOC base (0x14 bytes/entry)          [-30597<<16 -11864]
//   0x887AD4B0  ARC_WORKER_EVENT  streaming-worker wake event (auto-reset)       [-30597<<16 -11088]
//   0x887AD4B4  ARC_WORKER_THREAD streaming-worker thread handle (0 = none)      [-30597<<16 -11084]
//   0x887AD4C4  ARC_HDR_BUFFER    persistent 3184-byte companion buffer (0=none) [-30597<<16 -11068]
//   0x885C3280  ARC_CS            worker critical section                        [-30628<<16 +12928]
//   0x885C1A80  ARC_RING          6144-byte worker job ring                      [-30628<<16 +6784]
//   0x885C32D0  ARC_RING_CTRL     256-byte ring control block                    [-30628<<16 +13008]
//   0x88092C28  ARC_WORKER_FN     streaming-worker thread entry (still generated)
//   0x887AD2B0  ARC_NAME_PREFIX / 0x887AD3B0 ARC_NAME_SUFFIX — companion filename strings (668)
//
// ════════════════════════════════════════════════════════════════════════════════════════════════
// SEAM (PILOT_NOTES §2). Two forms, chosen per-function by whether merged_game.cpp strong-hooks it:
//   * HOOKED (strong PPC_FUNC(sub_XXXX) instrument already in merged_game.o) → take __imp__sub_XXXX
//     so the instrument stays alive and this body displaces the GENERATED __imp__ underneath it:
//       sub_880927A8 (E8_WRAP), sub_880929C8 ([gwork]), sub_88092B20 ([wjob] ENQUEUE),
//       sub_88092B80 ([wjob] DISPATCH), sub_88092ED8 ([winit] manager).
//   * UNHOOKED → plain PPC_FUNC(sub_XXXX); the strong body beats the generated weak alias:
//       sub_88092668, sub_88092AA8, sub_8813A460.
// decomp/game/*.cpp links FIRST (build_win.sh glob), so these win; the generated bodies stay as
// dead rollback bytes. ROLLBACK = delete this file / drop obj_win/decomp_archive.o. No build-line
// edit is needed — archive.cpp is auto-globbed into the GAME/decomp tree like mem_util.cpp.
//
// C1 REGISTER-FILE DISCIPLINE (PILOT_NOTES C1 GATE LESSON). These are NON-LEAF functions. At every
// bl a still-generated callee can observe, the register file + guest stack are mirrored verbatim:
//   - the stwu back-chain frame is reproduced so stack buffers (OVERLAPPED, filename, header) land
//     at their generated guest addresses (the file/thread callees read them there);
//   - r3..r10 args and ctx.lr are set to the generated values before each call;
//   - nonvolatiles r27..r31 are never touched (C locals hold the data) → strictly more conservative
//     than the generated body, which clobbers-then-restores them (PILOT_NOTES §6). The __savegprlr
//     register-save scratch is NOT written (host-register state, no guest meaning; nothing walks the
//     back chain per the rt.cpp LR-band note).
// CALLEE STATUS: the shared memcpy sub_88072260 is already translated (decomp/game/mem_util.cpp,
// __imp__ form). Every other callee here (sub_880836D0 alloc, sub_88073BD0 memset, sub_88083758
// free, sub_88082xxx file/event, sub_88083xxx handle, sub_880928D8 open, sub_88092310 ring-push,
// sub_8813A6A0 post-read, RtlEnter/Leave/InitializeCriticalSection) is still GENERATED and is
// called through its normal symbol so its own instrument wrapper keeps firing.
//
// GATE: mechanical this session (parallel agent may be running the game — NO boot). Build links
// green + build/futari_merged.map shows each body winning (see per-function notes / registry).
// Behavioral live-fire is PENDING-GATE — drive: archive-open + a resource read; a boot to a
// select/card screen loads art through this path (sub_88092ED8 init → sub_88092B20/B80 → decode).

#include "ppc_recomp_shared.h"   // ppc_config.h (base 0x88000000) + ppc_context.h + all callee decls

namespace {
// Guest state block — see the table above; each cited to the recomp's lis/addi decimals.
constexpr uint32_t ARC_FILE_HANDLE   = 0x88252E1C;
constexpr uint32_t ARC_TOC_COUNT     = 0x887AD19C;
constexpr uint32_t ARC_TOC_SIZE      = 0x887AD1A0;
constexpr uint32_t ARC_TOC_DATASTART = 0x887AD1A4;
constexpr uint32_t ARC_TOC_PTR       = 0x887AD1A8;
constexpr uint32_t ARC_WORKER_EVENT  = 0x887AD4B0;
constexpr uint32_t ARC_WORKER_THREAD = 0x887AD4B4;
constexpr uint32_t ARC_HDR_BUFFER    = 0x887AD4C4;
constexpr uint32_t ARC_CS            = 0x885C3280;
constexpr uint32_t ARC_RING          = 0x885C1A80;
constexpr uint32_t ARC_RING_CTRL     = 0x885C32D0;
constexpr uint32_t ARC_WORKER_FN     = 0x88092C28;
constexpr uint32_t ARC_NAME_PREFIX   = 0x887AD2B0;
constexpr uint32_t ARC_NAME_SUFFIX   = 0x887AD3B0;
constexpr uint32_t TOC_STRIDE        = 0x14;   // 20 bytes per in-memory TOC entry

// Big-endian loads from the guest file buffers (the recomp assembles these byte-by-byte with
// lbz+rlwimi; a single lwz would be wrong for these unaligned on-disk fields).
inline uint32_t be16(uint8_t* base, uint32_t a) {
    return ((uint32_t)PPC_LOAD_U8(a) << 8) | PPC_LOAD_U8(a + 1);
}
inline uint32_t be32(uint8_t* base, uint32_t a) {
    return ((uint32_t)PPC_LOAD_U8(a) << 24) | ((uint32_t)PPC_LOAD_U8(a + 1) << 16)
         | ((uint32_t)PPC_LOAD_U8(a + 2) << 8) | PPC_LOAD_U8(a + 3);
}
} // namespace

// ════════════════════════════════════════════════════════════════════════════════════════════════
// sub_880927A8 — file-offset READ (NtReadFile-equivalent). Zero-fills the buffer on short/failed
//               read. HOOKED (E8_WRAP(sub_880927A8) in merged_game.cpp) → __imp__ seam.
//
//   sub_880927A8(dst = r3, length = r4, fileOffset = r5) -> r3 = completion status
//
// Ground truth: out_reco/ppc_recomp.5.cpp:6326-6469. Issues an async read on the archive handle via
// a Win32-shaped OVERLAPPED (Offset at +8, hEvent at +16) built on the guest stack, waits for the
// event, then GetOverlappedResult-checks that the full `length` arrived; anything else zero-fills.
// The OVERLAPPED and the two out-params live on the guest stack and are read by the (generated)
// file callees, so the stwu frame + those bytes are reproduced exactly.
// ════════════════════════════════════════════════════════════════════════════════════════════════
PPC_FUNC_IMPL(__imp__sub_880927A8)
{
    PPC_FUNC_PROLOGUE();
    const uint32_t dst    = ctx.r3.u32;   // caller's destination buffer (r27)
    const uint32_t length = ctx.r4.u32;   // bytes requested (r28)
    const uint32_t offset = ctx.r5.u32;   // absolute file offset (arg2)

    // stwu r1,-176(r1): guest frame. OVERLAPPED at sp+96, out-params at sp+80/84.
    const uint32_t sp = ctx.r1.u32 - 176;
    PPC_STORE_U32(sp, ctx.r1.u32);
    ctx.r1.u32 = sp;

    const uint32_t ov = sp + 96;                 // Win32 OVERLAPPED
    PPC_STORE_U64(ov + 0, 0);                    // Internal / InternalHigh = 0
    PPC_STORE_U64(ov + 8, 0);                    // Offset / OffsetHigh = 0
    PPC_STORE_U32(ov + 16, 0);                   // hEvent = 0 (set below)
    PPC_STORE_U32(ov + 8, offset);               // OVERLAPPED.Offset = fileOffset

    const uint32_t fileHandle = PPC_LOAD_U32(ARC_FILE_HANDLE);

    // event = sub_88082CA8(0,0,0,0) — create the completion event.
    ctx.r3.u64 = 0; ctx.r4.u64 = 0; ctx.r5.u64 = 0; ctx.r6.u64 = 0;
    ctx.lr = 0x880927F4; sub_88082CA8(ctx, base);
    PPC_STORE_U32(ov + 16, ctx.r3.u32);          // OVERLAPPED.hEvent

    // status = sub_88082D48(fileHandle, dst, length, &bytesRead@sp+84, &overlapped@sp+96)
    ctx.r3.u32 = fileHandle; ctx.r4.u32 = dst; ctx.r5.u32 = length;
    ctx.r6.u32 = sp + 84; ctx.r7.u32 = ov;
    ctx.lr = 0x88092810; sub_88082D48(ctx, base);
    int32_t status = ctx.r3.s32;

    // lastErr = sub_88083170()
    ctx.lr = 0x88092818; sub_88083170(ctx, base);
    const uint32_t lastErr = ctx.r3.u32;

    // WAIT unless the read neither pended nor reported ERROR_IO_PENDING(997) — that case is a
    // synchronous non-completion and falls straight through to the zero-fill.
    if (status != 0 || lastErr == 997)
    {
        PPC_STORE_U32(sp + 80, 0);               // bytesTransferred = 0
        status = -1;
        // Wait for the completion event: sub_88082C38(hEvent, status, 1) until it returns 0.
        do {
            ctx.r3.u32 = PPC_LOAD_U32(ov + 16); ctx.r4.s64 = status; ctx.r5.u64 = 1;
            ctx.lr = 0x88092840; sub_88082C38(ctx, base);
        } while (ctx.r3.u32 != 0);
        // sub_88082EC8(fileHandle, &overlapped, &bytesTransferred@sp+80, 0) — GetOverlappedResult.
        ctx.r3.u32 = fileHandle; ctx.r4.u32 = ov; ctx.r5.u32 = sp + 80; ctx.r6.u64 = 0;
        ctx.lr = 0x8809285C; sub_88082EC8(ctx, base);
        status = ctx.r3.s32;
        const uint32_t got = PPC_LOAD_U32(sp + 80);
        if (got == length) {
            if (status != 0) goto close;         // full read + success (BOOL!=0) → keep the bytes
            // full read but status==0 → falls through to zero-fill (matches the generated branch)
        } else {
            status = 0;                          // short read → force the zero-fill path
        }
    }

    // Zero-fill dst on failure / short read: sub_88073BD0(dst, 0, length) (guest memset).
    ctx.r3.u32 = dst; ctx.r4.u64 = 0; ctx.r5.u32 = length;
    ctx.lr = 0x8809288C; sub_88073BD0(ctx, base);

close:
    // Close the completion event handle.
    ctx.r3.u32 = PPC_LOAD_U32(ov + 16);
    ctx.lr = 0x88092894; sub_88083178(ctx, base);

    ctx.r1.u32 = sp + 176;
    ctx.r3.s64 = status;                          // return completion status (r31)
}

// ════════════════════════════════════════════════════════════════════════════════════════════════
// sub_88092668 — opens the small companion header/check file (exactly 3184 = 0xC70 bytes) into the
//               persistent buffer at 0x887AD4C4. UNHOOKED → plain PPC_FUNC.
//
// Ground truth: out_reco/ppc_recomp.5.cpp:6145-6323. No-op unless the suffix string at 0x887AD3B0
// is non-empty. Builds "<prefix><suffix>" (prefix 0x887AD2B0, suffix 0x887AD3B0) on the guest
// stack, CreateFile(GENERIC_READ, share=1, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL), requires the
// file to be exactly 3184 bytes, allocates + synchronously reads it; frees + nulls on any failure.
// The filename + bytes-read out-param live on the guest stack → stwu frame reproduced.
// ════════════════════════════════════════════════════════════════════════════════════════════════
PPC_FUNC(sub_88092668)
{
    PPC_FUNC_PROLOGUE();
    if (PPC_LOAD_U8(ARC_NAME_SUFFIX) == 0)       // lbz [0x887AD3B0]; empty → do nothing
        return;

    // stwu r1,-384(r1): guest frame. Filename at sp+96, bytesRead out at sp+80.
    const uint32_t sp = ctx.r1.u32 - 384;
    PPC_STORE_U32(sp, ctx.r1.u32);
    ctx.r1.u32 = sp;

    // filename = strcpy(sp+96, prefix); strcat(., suffix)  (both NUL-terminated guest strings)
    const uint32_t name = sp + 96;
    uint32_t d = name, s = ARC_NAME_PREFIX;
    uint8_t c;
    do { c = PPC_LOAD_U8(s++); PPC_STORE_U8(d++, c); } while (c != 0);
    --d;                                          // back over the NUL
    s = ARC_NAME_SUFFIX;
    do { c = PPC_LOAD_U8(s++); PPC_STORE_U8(d++, c); } while (c != 0);

    // handle = sub_88082990(name, GENERIC_READ, share=1, 0, OPEN_EXISTING=3, ATTR_NORMAL=128, 0)
    ctx.r3.u32 = name; ctx.r4.u64 = 0x80000000; ctx.r5.u64 = 1; ctx.r6.u64 = 0;
    ctx.r7.u64 = 3; ctx.r8.u64 = 128; ctx.r9.u64 = 0;
    ctx.lr = 0x88092704; sub_88082990(ctx, base);
    const int32_t handle = ctx.r3.s32;
    if (handle == -1) goto free_buf;             // loc_88092768

    // filesize check: sub_88082B88(handle, 0) must be exactly 3184.
    ctx.r3.s64 = handle; ctx.r4.u64 = 0;
    ctx.lr = 0x88092718; sub_88082B88(ctx, base);
    if (ctx.r3.u32 != 3184) goto free_buf;       // loc_88092768

    {
        // buf = sub_880836D0(3184, -1, 16, 4); store at ARC_HDR_BUFFER.
        ctx.r3.u64 = 3184; ctx.r4.s64 = -1; ctx.r5.u64 = 16; ctx.r6.u64 = 4;
        ctx.lr = 0x88092730; sub_880836D0(ctx, base);
        const uint32_t buf = ctx.r3.u32;
        PPC_STORE_U32(ARC_HDR_BUFFER, buf);
        if (buf == 0) goto skip_close_check;     // loc_88092780

        // sub_88082D48(handle, buf, 3184, &bytesRead@sp+80, lpOverlapped=0) — sync read.
        ctx.r3.s64 = handle; ctx.r4.u32 = buf; ctx.r5.u64 = 3184;
        ctx.r6.u32 = sp + 80; ctx.r7.u64 = 0;
        ctx.lr = 0x88092754; sub_88082D48(ctx, base);
        if (ctx.r3.s32 == 0) goto free_buf;      // read failed
        if (PPC_LOAD_U32(sp + 80) == 3184) goto close_handle;  // full read → keep buf
        // fall through to free_buf
    }

free_buf:                                        // loc_88092768 — free + null buf if allocated
    if (PPC_LOAD_U32(ARC_HDR_BUFFER) != 0)
    {
        ctx.r3.u32 = PPC_LOAD_U32(ARC_HDR_BUFFER);
        ctx.lr = 0x88092778; sub_88083758(ctx, base);
        PPC_STORE_U32(ARC_HDR_BUFFER, 0);
    }
skip_close_check:                                // loc_88092780
    if (handle == -1) goto done;                 // cannot close an invalid handle
close_handle:                                    // loc_88092788
    ctx.r3.s64 = handle;
    ctx.lr = 0x88092790; sub_88083178(ctx, base);
done:                                            // loc_88092790
    ctx.r1.u32 = sp + 384;
}

// ════════════════════════════════════════════════════════════════════════════════════════════════
// sub_88092AA8 — id → raw bytes recipe. UNHOOKED → plain PPC_FUNC.
//
//   sub_88092AA8(id = r3, dst = r4) -> r3 = 1 on success, 0 if id out of range or dst == 0
//
// Ground truth: out_reco/ppc_recomp.5.cpp:6792-6860. Bound-check id < ARC_TOC_COUNT and dst != 0,
// entry = ARC_TOC_PTR + id*0x14, then sub_880927A8(dst, entry->length@+8, entry->fileOffset@+4).
// ════════════════════════════════════════════════════════════════════════════════════════════════
PPC_FUNC(sub_88092AA8)
{
    PPC_FUNC_PROLOGUE();
    const uint32_t id  = ctx.r3.u32;
    const uint32_t dst = ctx.r4.u32;
    const uint32_t sp = ctx.r1.u32 - 96;         // stwu r1,-96(r1)
    PPC_STORE_U32(sp, ctx.r1.u32);
    ctx.r1.u32 = sp;

    uint32_t result = 0;
    if (id < PPC_LOAD_U32(ARC_TOC_COUNT) && dst != 0)
    {
        const uint32_t entry = PPC_LOAD_U32(ARC_TOC_PTR) + id * TOC_STRIDE;
        ctx.r3.u32 = dst;
        ctx.r4.u32 = PPC_LOAD_U32(entry + 8);    // length
        ctx.r5.u32 = PPC_LOAD_U32(entry + 4);    // fileOffset
        ctx.lr = 0x88092B0C; sub_880927A8(ctx, base);
        result = 1;
    }

    ctx.r1.u32 = sp + 96;
    ctx.r3.u64 = result;
}

// ════════════════════════════════════════════════════════════════════════════════════════════════
// sub_88092B80 — allocate a persistent per-id cache buffer and fill it. HOOKED ([wjob] DISPATCH in
//               merged_game.cpp) → __imp__ seam.
//
//   sub_88092B80(id = r3)  [returns nothing meaningful]
//
// Ground truth: out_reco/ppc_recomp.5.cpp:6923-7019. Allocates a buffer sized to the entry's
// length (or 0x20000 default if id is out of range), stores it at TOC[id]+0xc, then fills it via
// sub_88092AA8 — LEAVING the worker critical section around the (blocking) fill and re-entering
// after, so the streaming worker can make progress while the read is in flight.
// ════════════════════════════════════════════════════════════════════════════════════════════════
PPC_FUNC_IMPL(__imp__sub_88092B80)
{
    PPC_FUNC_PROLOGUE();
    const uint32_t id = ctx.r3.u32;
    const uint32_t sp = ctx.r1.u32 - 128;        // stwu r1,-128(r1)
    PPC_STORE_U32(sp, ctx.r1.u32);
    ctx.r1.u32 = sp;

    uint32_t size;
    if (id < PPC_LOAD_U32(ARC_TOC_COUNT))
        size = PPC_LOAD_U32(PPC_LOAD_U32(ARC_TOC_PTR) + id * TOC_STRIDE + 8);   // entry->length
    else
        size = 0x20000;                          // lis r3,2 — default cache size

    // buf = sub_880836D0(size, -1, 16, 4)
    ctx.r3.u32 = size; ctx.r4.s64 = -1; ctx.r5.u64 = 16; ctx.r6.u64 = 4;
    ctx.lr = 0x88092BD4; sub_880836D0(ctx, base);
    const uint32_t buf = ctx.r3.u32;

    const uint32_t entry = PPC_LOAD_U32(ARC_TOC_PTR) + id * TOC_STRIDE;
    PPC_STORE_U32(entry + 12, buf);              // TOC[id].cachePtr = buf

    // RtlLeaveCriticalSection(&ARC_CS); fill; RtlEnterCriticalSection(&ARC_CS)
    ctx.r3.u32 = ARC_CS; ctx.lr = 0x88092C00; __imp__RtlLeaveCriticalSection(ctx, base);
    ctx.r3.u32 = id; ctx.r4.u32 = PPC_LOAD_U32(entry + 12);
    ctx.lr = 0x88092C14; sub_88092AA8(ctx, base);
    ctx.r3.u32 = ARC_CS; ctx.lr = 0x88092C1C; __imp__RtlEnterCriticalSection(ctx, base);

    ctx.r1.u32 = sp + 128;   // r3 left = RtlEnter leftover (no meaningful return; matches generated)
}

// ════════════════════════════════════════════════════════════════════════════════════════════════
// sub_88092B20 — synchronous immediate resource-read path (no ring hop). HOOKED ([wjob] ENQUEUE in
//               merged_game.cpp) → __imp__ seam.
//
//   sub_88092B20(id = r3, dst = r4, cbArg = r5) -> r3 = 1 on success, 0 on failure
//
// Ground truth: out_reco/ppc_recomp.5.cpp:6862-6921. Reads the resource straight into dst via
// sub_88092AA8; on success runs the post-read hook sub_8813A6A0(cbArg). The generated body loads
// &sub_8813A6A0 into a register and null-checks it — a compile-time constant, so always taken.
// ════════════════════════════════════════════════════════════════════════════════════════════════
PPC_FUNC_IMPL(__imp__sub_88092B20)
{
    PPC_FUNC_PROLOGUE();
    const uint32_t id    = ctx.r3.u32;
    const uint32_t dst   = ctx.r4.u32;
    const uint32_t cbArg = ctx.r5.u32;
    const uint32_t sp = ctx.r1.u32 - 112;        // stwu r1,-112(r1)
    PPC_STORE_U32(sp, ctx.r1.u32);
    ctx.r1.u32 = sp;

    uint32_t result;
    ctx.r3.u32 = id; ctx.r4.u32 = dst;
    ctx.lr = 0x88092B44; sub_88092AA8(ctx, base);
    if (ctx.r3.s32 != 0)
    {
        ctx.r3.u32 = cbArg;
        ctx.lr = 0x88092B5C; sub_8813A6A0(ctx, base);
        result = 1;
    }
    else
    {
        result = 0;
    }

    ctx.r1.u32 = sp + 112;
    ctx.r3.u64 = result;
}

// ════════════════════════════════════════════════════════════════════════════════════════════════
// sub_880929C8 — archive TEARDOWN. HOOKED ([gwork] in merged_game.cpp) → __imp__ seam.
//
// Ground truth: out_reco/ppc_recomp.5.cpp:6654-6789. Four steps, each guarded so teardown is safe
// on a partially-initialised archive: (1) shut the streaming worker down — signal its wake event,
// wait for the thread, close both handles; (2) free every per-entry cache buffer then the TOC
// array; (3) close the archive file; (4) free the companion buffer. (d2 RESOLVED 07-23.)
// ════════════════════════════════════════════════════════════════════════════════════════════════
PPC_FUNC_IMPL(__imp__sub_880929C8)
{
    PPC_FUNC_PROLOGUE();
    const uint32_t sp = ctx.r1.u32 - 112;        // stwu r1,-112(r1)
    PPC_STORE_U32(sp, ctx.r1.u32);
    ctx.r1.u32 = sp;

    // 1) worker shutdown — only if a worker thread was ever created.
    if (PPC_LOAD_U32(ARC_WORKER_THREAD) != 0)
    {
        ctx.r3.u32 = PPC_LOAD_U32(ARC_WORKER_EVENT);          // signal wake event
        ctx.lr = 0x880929F0; sub_88082BF8(ctx, base);
        ctx.r3.u32 = PPC_LOAD_U32(ARC_WORKER_THREAD); ctx.r4.s64 = -1;   // wait (infinite)
        ctx.lr = 0x880929FC; sub_88082BF0(ctx, base);
        ctx.r3.u32 = PPC_LOAD_U32(ARC_WORKER_THREAD);         // close thread
        ctx.lr = 0x88092A04; sub_88083178(ctx, base);
        ctx.r3.u32 = PPC_LOAD_U32(ARC_WORKER_EVENT);          // close event
        ctx.lr = 0x88092A0C; sub_88083178(ctx, base);
    }

    // 2) free the per-entry caches (entry+12) then the TOC array itself.
    if (PPC_LOAD_U32(ARC_TOC_PTR) != 0)
    {
        uint32_t count = PPC_LOAD_U32(ARC_TOC_COUNT);
        for (uint32_t i = 0; i < count; ++i)
        {
            const uint32_t entry = PPC_LOAD_U32(ARC_TOC_PTR) + i * TOC_STRIDE;
            if (PPC_LOAD_U32(entry + 12) != 0)
            {
                ctx.r3.u32 = PPC_LOAD_U32(entry + 12);
                ctx.lr = 0x88092A40; sub_88083758(ctx, base);
                count = PPC_LOAD_U32(ARC_TOC_COUNT);          // generated reloads after each free
            }
        }
        ctx.r3.u32 = PPC_LOAD_U32(ARC_TOC_PTR);
        ctx.lr = 0x88092A64; sub_88083758(ctx, base);
        PPC_STORE_U32(ARC_TOC_PTR, 0);
    }

    // 3) close the archive file.
    if ((int32_t)PPC_LOAD_U32(ARC_FILE_HANDLE) != -1)
    {
        ctx.r3.u32 = PPC_LOAD_U32(ARC_FILE_HANDLE);
        ctx.lr = 0x88092A80; sub_88083178(ctx, base);
        PPC_STORE_U32(ARC_FILE_HANDLE, 0xFFFFFFFF);
    }

    // 4) free the companion/header buffer.
    if (PPC_LOAD_U32(ARC_HDR_BUFFER) != 0)
    {
        ctx.r3.u32 = PPC_LOAD_U32(ARC_HDR_BUFFER);
        ctx.lr = 0x88092A98; sub_88083758(ctx, base);
        PPC_STORE_U32(ARC_HDR_BUFFER, 0);
    }

    ctx.r1.u32 = sp + 112;
}
