// decomp/game/asset_pump.cpp — the ASSET-PIPELINE KEYSTONE: submit / per-frame pump / completion.
//
// This is the consolidation half of the asset pipeline (registry / ATLAS AP§2). The archive half
// (decomp/game/archive.cpp) turns an id into raw bytes; the decode half (decomp/game/asset_decode.cpp)
// turns a compressed record into pixels; THIS file is the machine that ties them together — the
// 16-slot job ring, the per-frame state machine that walks it, the mode dispatch into the four
// decoders, and the async completion callback that closes the loop. It is the pipeline's engine room.
//
// ════════════════════════════════════════════════════════════════════════════════════════════════
// THE PIPELINE, END TO END  (archive-open → id→bytes → job-ring → decode → upload)
// ════════════════════════════════════════════════════════════════════════════════════════════════
//
//   [1] ARCHIVE OPEN  (archive.cpp) — sub_88092ED8 opens the one archive file (handle 0x88252E1C),
//       parses the 16-byte header + expands the raw 12-byte TOC records into the in-memory 0x14-byte
//       TOC at 0x887AD1A8 (count 0x887AD19C), and spawns the streaming worker thread. Front door.
//
//   [2] SCENE SUBMIT  (archive.cpp sub_8813A460 → THIS FILE sub_8813A4D0) — a scene descriptor
//       id-chain (records at 0x88290CD0[id], id field at +2, -1 sentinel) is walked; each id is
//       pushed. sub_8813A4D0 ARMS one free slot of the 16-entry job-slot table at 0x884D20E8
//       (56 bytes/slot): it copies the id + a user callback into the slot, stamps a sequence number,
//       reads the resource's descriptor (halfword fields at 0x88290CD0[id]) into the slot, marks the
//       slot busy(=1) and advances the submit cursor (mod 16). Returns the sequence number (0 = ring
//       full). This is the PRODUCER onto the ring.
//
//   [3] PER-FRAME PUMP  (THIS FILE sub_8813A738) — THE KEYSTONE. Called once per game-main-loop
//       iteration (merged_game pins the loop tid off it). It walks the armed slots between the
//       dispatch cursor [0x887ACDFC] and the submit cursor [0x887ACE00], and advances each slot
//       through a small state machine held in slot+8 (0=idle/needs-read, 1=read-done/needs-decode,
//       2=..., 5=decoded/needs-consume). Per slot, per state:
//         · state 0 → sizes + allocates the decode-output buffer (sub_8808CE90), then reads the raw
//                     bytes for the resource straight in via archive.cpp's sub_88092B20(id,dst,slot)
//                     — which on success runs the completion callback sub_8813A6A0 (see [5]).
//         · state 1 → allocates the final image buffer (sub_8808CE90), then DISPATCHES the compressed
//                     record to the mode decoder by the mode byte (slot+... → r30):
//                        mode 1 → sub_8813A248   mode 2 → sub_8813A118
//                        mode 3 → sub_88139D90   mode 4 → sub_88139A88   (all in asset_decode.cpp)
//         · state 5 → hands the decoded image to the host/consume path: sub_88090E58 / sub_88090D50 /
//                     sub_88090CB8 build the upload descriptor and sub_8808D640 performs the TEXTURE
//                     UPLOAD (the GPU hand-off; sub_8808D640/sub_8808DF70 are ASM-EXACT in matchlab).
//       When a slot finishes it fires the per-slot user callback (bctrl on slot+... function pointer),
//       frees the scratch buffers (sub_8808CF58), reloads the next descriptor for the slot, and rings
//       the dispatch cursor forward (mod 16). The group-state block at 0x884947F8 + group*7204 tracks
//       per-descriptor-group cell state (a second ring, cell result at +4, counter at +7200).
//
//   [4] DECODE  (asset_decode.cpp) — modes 1..4 decompress the record into the slot's image buffer.
//
//   [5] COMPLETION  (THIS FILE sub_8813A6A0) — the post-read hook. Given a slot, it sets the slot
//       state to 2 (loaded), then — if the resource's TOC entry (0x887AD1A8 + id*0x14) has a nonzero
//       "needs-further-processing" byte at entry+2 — overrides the state to 1 (needs-decode), routing
//       the slot back into the pump's decode arm. This is the edge that turns a raw read into a decode
//       job; completing it closes the archive→decode loop. (Its +8 twin sub_8813A6A8 lives in the abn
//       symbol map — now covered — and shares the same slot-state contract.)
//
// ════════════════════════════════════════════════════════════════════════════════════════════════
// GUEST STATE BLOCK (addresses cited from the recomp lis/addi decimals)
// ════════════════════════════════════════════════════════════════════════════════════════════════
//   0x884D20E8  JOB_SLOT_TABLE     16 × 56-byte job slots (sub_8813A5F0 memsets 896 = 16*56 bytes)
//                                    slot+0  busy flag (0=free, 1=armed)
//                                    slot+4  sequence number (submit generation; wraps 0→1)
//                                    slot+8  state machine (0/1/2/5)
//                                    slot+12 user callback function pointer (bctrl target)
//                                    slot+16 user callback argument (the id passed to submit)
//                                    slot+20 group cell index / secondary index
//                                    slot+24 resource id (from descriptor[+2], signed halfword)
//                                    slot+28 descriptor field0        slot+32 group id
//                                    slot+36 descriptor field8        slot+40 descriptor field10
//                                    slot+44 descriptor pointer       slot+48 raw-read buffer
//                                    slot+52 decoded-image buffer
//   0x88290CD0  DESCRIPTOR_TABLE   PTR_DAT_88290cd0 — per-id descriptor-pointer array (id*4)
//   0x887AD1A8  ARC_TOC_PTR        in-memory TOC base (0x14 bytes/entry; entry+2 = the completion
//                                    routing byte read by sub_8813A6A0)             [-30597<<16 -11864]
//   0x887AD19C  ARC_TOC_COUNT      entry count (bound for every id)                 [-30597<<16 -11876]
//   0x887ACDFC  RING_DISPATCH_CUR  pump's dispatch cursor (slot index being serviced) [r29-940]
//   0x887ACE00  RING_SUBMIT_CUR    submit cursor (next free slot index)               [r29-936 / r8-4]
//   0x887ACE04  RING_SEQ           submit sequence counter (never 0 after wrap)       [r8]
//   0x884947F8  GROUP_STATE_BASE   per-descriptor-group state, +group*7204 (cell result @+4,
//                                    live-cell counter @+7200)                       [-30647<<16 +18424]
//   0x884D2468/0x884D3468/0x884D6530  decoder scratch dictionaries (asset_decode.cpp)
//
// ════════════════════════════════════════════════════════════════════════════════════════════════
// SEAM (PILOT_NOTES §2). Chosen per-function by whether merged_game.cpp strong-hooks it:
//   * sub_8813A738  HOOKED — merged_game.cpp:1352 defines strong PPC_FUNC(sub_8813A738) (the [boot]/
//                   [gmstage] main-loop-tid instrument, tail-calls __imp__sub_8813A738). → take the
//                   __imp__ seam so that instrument stays alive and this body displaces the GENERATED
//                   __imp__ underneath it.
//   * sub_8813A4D0  HOOKED — merged_game.cpp:1347 TB_WRAP(sub_8813A4D0) (strong PPC_FUNC + [boot]).
//                   → __imp__ seam.
//   * sub_8813A6A0  UNHOOKED — no strong hook in merged_game. → plain PPC_FUNC(sub_8813A6A0); the
//                   strong body beats the generated weak alias (same as archive.cpp sub_88092AA8).
// decomp/game/*.cpp is auto-globbed and linked FIRST (build_win.sh:49), so these win; the generated
// bodies stay as dead rollback bytes. ROLLBACK = drop obj_win/decomp_asset_pump.o. No build-line edit.
//
// CALLEE STATUS at the bl/bctrl boundaries:
//   TRANSLATED (this leg): sub_88092B20 (archive.cpp, [wjob] ENQUEUE — the raw read + completion hook);
//     sub_8813A248 / sub_8813A118 / sub_88139D90 / sub_88139A88 (asset_decode.cpp, the mode decoders).
//   TRANSLATED (round 5, decomp/game/asset_upload.cpp): sub_8808D640 (the state-5 TEXTURE UPLOAD —
//     page staging copy; its render-side consumer twin sub_8808DF70 came with it).
//   STILL GENERATED (called through their plain sub_* symbols so their instrument wrappers keep
//     firing): sub_8808CE90 (buffer alloc), sub_8808CF58 (free), sub_88090E58 / sub_88090D50 /
//     sub_88090CB8 (upload-descriptor build),
//     sub_880924E8 (cache-line variant read), the per-slot user callback (bctrl on slot+12).
//
// ════════════════════════════════════════════════════════════════════════════════════════════════
// TRANSLATION FORM — READABLE NATURAL C (refactored 2026-08-14; the round-5 debt paid)
// ════════════════════════════════════════════════════════════════════════════════════════════════
// The pump + submit began as faithful transcriptions (generated ops verbatim) because proving a
// readable rewrite equivalent requires the live end-to-end differential — which did not exist when
// the leg landed. It does now (_local/_tmpscripts/decdiff_arcade.sh: control-vs-pilot RT_DECLOG
// stream equality + RT_DECDUMP byte-compare + the RT_UPCANARY execution proof), and the
// transcriptions passed it 398/398 on 08-13. This file now carries the NATURAL-C rewrite of both,
// re-proven on the same gate (ledger 08-14). C1 discipline: the exact ARG registers + ctx.lr are
// presented at every bl/bctrl (the proven asset_decode/asset_upload pattern; the still-generated
// callees are register-exact ABI code that reads args only); the guest stack frame is emulated
// (back-chain stored, r1 lowered across the calls). Ground truth stays out_reco/ppc_recomp.18.cpp
// (:10979 submit, :11355 pump) — diff against it when in doubt; git holds the retired
// transcriptions (commit f79a8f1 and earlier).
//
// Two shipped behaviors preserved deliberately (they look odd; they are the game):
//   * SUBMIT reads the descriptor with NO bound check on id (the chain-walker guards upstream),
//     and its store ORDER is kept (busy=1 lands before the descriptor fields; the streaming
//     worker observes these slots concurrently).
//   * A record whose output cell is still unconsumed at ARM time parks the slot in state 2 —
//     on resume the pump PRODUCES from whatever buffers the slot has (never-read ⇒ zero bufs).
//     That is the generated control flow, reproduced 1:1.
#include "ppc_recomp_shared.h"   // ppc_config.h (base 0x88000000) + ppc_context.h + all callee decls
namespace {
constexpr uint32_t ARC_TOC_COUNT   = 0x887AD19C;  // entry count            [-30597<<16 -11876]
constexpr uint32_t ARC_TOC_PTR     = 0x887AD1A8;  // in-memory TOC base      [-30597<<16 -11864]
constexpr uint32_t TOC_STRIDE      = 0x14;        // 20 bytes / TOC entry
constexpr uint32_t RING_DISPATCH_CUR = 0x887ACDFC;  // pump's slot cursor
constexpr uint32_t RING_SUBMIT_CUR   = 0x887ACE00;  // next free slot index
constexpr uint32_t RING_SEQ          = 0x887ACE04;  // submit sequence counter (never 0 after wrap)
constexpr uint32_t JOB_SLOT_TABLE  = 0x884D20E8;  constexpr uint32_t SLOT_STRIDE = 56;
constexpr uint32_t DESC_TABLE      = 0x88290CD0;  constexpr uint32_t DESC_REC_STRIDE = 12;
constexpr uint32_t GROUP_BASE      = 0x884947F8;  constexpr uint32_t GROUP_STRIDE = 7204;
constexpr uint32_t GROUP_COUNTER   = 7200;        // live-cell counter inside a group block
constexpr uint32_t CELL_STRIDE     = 12;          // group cell: {ready flag @0, result @+4}
constexpr uint32_t DBG_LAST_ID     = 0x884947F0;  // last serviced resource id (debug global)
constexpr uint32_t DBG_LAST_SIZE   = 0x884947F4;  // last raw alloc size      (debug global)
constexpr uint32_t ARC_HANDLE      = 0x88252E1C;  // archive file handle; -1 = not open
// job-slot field offsets (56-byte record; layout doc in the header above)
enum : uint32_t { SLOT_BUSY = 0, SLOT_SEQ = 4, SLOT_STATE = 8, SLOT_CB = 12, SLOT_CBARG = 16,
                  SLOT_RECIDX = 20, SLOT_RESID = 24, SLOT_FIELD0 = 28, SLOT_CELLIDX = 32,
                  SLOT_FIELD8 = 36, SLOT_FIELD10 = 40, SLOT_DESC = 44, SLOT_RAWBUF = 48,
                  SLOT_IMGBUF = 52 };
// The `id < count ? TOC[id].field : fallback` guard the pump inlines at a dozen sites.
// Every load is FRESH — the generated body reloads count/base after each call boundary.
inline bool     toc_in   (uint8_t* base, uint32_t id){ return id < PPC_LOAD_U32(ARC_TOC_COUNT); }
inline uint32_t toc_entry(uint8_t* base, uint32_t id){ return PPC_LOAD_U32(ARC_TOC_PTR) + id * TOC_STRIDE; }
inline uint32_t toc_route(uint8_t* base, uint32_t id){ return toc_in(base,id) ? PPC_LOAD_U8 (toc_entry(base,id) + 2u) : 0u; }
inline uint32_t toc_fmt  (uint8_t* base, uint32_t id){ return toc_in(base,id) ? PPC_LOAD_U8 (toc_entry(base,id) + 3u) : 0u; }
inline uint32_t toc_len  (uint8_t* base, uint32_t id){ return toc_in(base,id) ? PPC_LOAD_U32(toc_entry(base,id) + 8u) : 0x20000u; }
} // namespace

// ════════════════════════════════════════════════════════════════════════════════════════════════
// sub_8813A6A0 — ASYNC JOB COMPLETION CALLBACK. UNHOOKED → plain PPC_FUNC. LEAF (no bl/bctrl).
//
//   sub_8813A6A0(slot = r3)   [returns nothing meaningful; r3 left = slot]
//
// Ground truth: out_reco/ppc_recomp.18.cpp:11257-11305 (register-exact recomp, entry → blr). Sets the
// slot's state (slot+8) to 2 (loaded); then, if the resource id (slot+24) is in range and its TOC
// entry's routing byte (0x887AD1A8 + id*0x14 + 2) is nonzero, overrides the state to 1 (needs-decode),
// re-routing the slot into the pump's decode arm. Called by archive.cpp's sub_88092B20 after a raw
// read; completing it closes the archive→decode loop. Natural C: the generated body touches only
// r9/r10/r11/cr6 and never writes r3, so leaving ctx.r3 = slot is register-faithful; no call boundary
// so the C1 rule has nothing to mirror (same leaf discipline as mem_util.cpp).
// ════════════════════════════════════════════════════════════════════════════════════════════════
PPC_FUNC(sub_8813A6A0)
{
    PPC_FUNC_PROLOGUE();
    const uint32_t slot = ctx.r3.u32;
    const uint32_t id   = PPC_LOAD_U32(slot + 24);       // slot.id

    PPC_STORE_U32(slot + 8, 2);                          // slot.state = 2 (loaded)

    uint32_t routeByte = 0;
    if (id < PPC_LOAD_U32(ARC_TOC_COUNT))                // bound-check id < count
    {
        const uint32_t entry = PPC_LOAD_U32(ARC_TOC_PTR) + id * TOC_STRIDE;
        routeByte = PPC_LOAD_U8(entry + 2);              // TOC entry's completion-routing byte
    }
    if (routeByte != 0)
        PPC_STORE_U32(slot + 8, 1);                      // needs-decode → slot.state = 1
    // r3 left = slot (untouched), matching the generated body's exit register file.
}

// ════════════════════════════════════════════════════════════════════════════════════════════════
// sub_8813A4D0 — JOB SUBMIT: arms a free ring slot from the static descriptor table PTR_DAT_88290cd0.
//               HOOKED (TB_WRAP(sub_8813A4D0) in merged_game.cpp:1347) → __imp__ seam.
//
//   sub_8813A4D0(id = r3, userCallback = r4) -> r3 = sequence number (0 if the ring is full)
//
// Ground truth: out_reco/ppc_recomp.18.cpp:10979-11097. NATURAL C (2026-08-14 refactor; the
// transcription this replaces passed the live differential first). Store order preserved — the
// streaming worker reads these slots concurrently, so busy=1 landing before the descriptor
// fields is the shipped memory order, and the seq wrap really does store 0 then 1.
// ════════════════════════════════════════════════════════════════════════════════════════════════
PPC_FUNC_IMPL(__imp__sub_8813A4D0)
{
    PPC_FUNC_PROLOGUE();
    const uint32_t id = ctx.r3.u32;
    const uint32_t cb = ctx.r4.u32;

    const uint32_t cur  = PPC_LOAD_U32(RING_SUBMIT_CUR);
    const uint32_t slot = JOB_SLOT_TABLE + cur * SLOT_STRIDE;
    if (PPC_LOAD_U32(slot + SLOT_BUSY) != 0) { ctx.r3.u64 = 0; return; }   // ring full

    uint32_t seq = PPC_LOAD_U32(RING_SEQ) + 1;                             // wraps 0 -> 1
    PPC_STORE_U32(RING_SEQ, seq);
    if (seq == 0) { seq = 1; PPC_STORE_U32(RING_SEQ, seq); }

    PPC_STORE_U32(slot + SLOT_CBARG,   id);
    PPC_STORE_U32(slot + SLOT_CB,      cb);
    PPC_STORE_U32(slot + SLOT_SEQ,     seq);
    PPC_STORE_U32(slot + SLOT_BUSY,    1);
    PPC_STORE_U32(slot + SLOT_STATE,   0);
    PPC_STORE_U32(slot + SLOT_RECIDX,  0);
    PPC_STORE_U32(slot + SLOT_CELLIDX, 0);

    // First descriptor record (12 bytes: s16 field0, s16 resId, u32 recordCallback, u16 f8, u16 f10).
    // NO bound check on id — as shipped; the chain-walker (sub_8813A460) guards upstream.
    const uint32_t desc = PPC_LOAD_U32(DESC_TABLE + id * 4u);
    PPC_STORE_U32(slot + SLOT_DESC,    desc);
    PPC_STORE_U32(slot + SLOT_RESID,   (uint32_t)(int32_t)(int16_t)PPC_LOAD_U16(desc + 2u));
    PPC_STORE_U32(slot + SLOT_FIELD0,  (uint32_t)(int32_t)(int16_t)PPC_LOAD_U16(desc + 0u));
    PPC_STORE_U32(slot + SLOT_FIELD8,  PPC_LOAD_U16(desc + 8u));           // zero-extended, as generated
    const uint32_t next = cur + 1;
    PPC_STORE_U32(RING_SUBMIT_CUR, (next >= 16u) ? 0u : next);             // wrap at 16
    PPC_STORE_U32(slot + SLOT_FIELD10, PPC_LOAD_U16(desc + 10u));          // (cursor store interleaves here
                                                                           //  in the generated order)
    ctx.r3.u64 = seq;
}

// ════════════════════════════════════════════════════════════════════════════════════════════════
// sub_8813A738 — THE PER-FRAME ASSET JOB PUMP. THE KEYSTONE. HOOKED (PPC_FUNC(sub_8813A738) in
//               merged_game.cpp:1352, the [boot]/[gmstage] main-loop instrument) → __imp__ seam.
//
//   sub_8813A738()   [services the slot under the dispatch cursor; drains its whole record chain]
//
// Ground truth: out_reco/ppc_recomp.18.cpp:11355-12419. NATURAL C (2026-08-14 refactor).
//
// SHAPE: one call services ONE slot — the one under the dispatch cursor. A slot carries a CHAIN
// of 12-byte descriptor records (slot.recIdx walks them; a negative resId is the sentinel); the
// pump drains record after record IN THE SAME CALL (the for(;;)), each through:
//
//     ARM(0)         size + allocate the raw buffer, kick the read.
//                    · submit-callback slots take the ASYNC read (sub_880924E8) and the pump
//                      returns; the completion callback re-routes the state when data lands.
//                    · plain slots read SYNCHRONOUSLY (sub_88092B20, which runs the completion
//                      sub_8813A6A0 inline on success) and keep going in-frame.
//     DECODE(1)      allocate the image buffer (fmt²·0x20000+128) and dispatch the compressed
//                    record by its TOC route byte: 1→A248 2→A118 3→9D90 4→9A88.
//     PRODUCE(2/5)   hand the result to the consumer side, one of three arms:
//                    · slot.cb set        → descriptor-build family (field0 ? CB8 : D50);
//                                           D50's return value is the cell result, CB8's is not.
//                    · slot.field0 set    → PAGE STAGING: pack the page id from f8/f10 and
//                                           sub_8808D640(page, buf+16, flag)  [asset_upload.cpp]
//                    · neither            → sub_88090E58(buf, flag) → result handle.
//                    The result lands in the slot's GROUP CELL (+4), the group live-counter
//                    increments, and FINISH marks the cell ready.
//     FINISH(3)      if the cell is still unmarked: fire the RECORD's callback (record+4, bctrl)
//                    and set cell.ready=1 (the consumer clears it). Then advance: cellIdx++,
//                    free both buffers, load the next record; sentinel (resId<0) frees the slot,
//                    rings the dispatch cursor (wrap 16) and ends the call.
//
// STALL: if a record's output cell is still unconsumed at ARM, the slot parks in state 2 and the
// pump returns; states 4 (read in flight) and 5 (produced) also just return. See the form note —
// the park-resume produces from the never-read buffers exactly like the generated body.
// ════════════════════════════════════════════════════════════════════════════════════════════════
PPC_FUNC_IMPL(__imp__sub_8813A738)
{
    PPC_FUNC_PROLOGUE();
    const uint32_t sp = ctx.r1.u32 - 192u;         // stwu back-chain; callees run below this frame
    PPC_STORE_U32(sp, ctx.r1.u32);
    ctx.r1.u32 = sp;
#define PUMP_RETURN() do { ctx.r1.u32 = sp + 192u; return; } while (0)

    const uint32_t dc   = PPC_LOAD_U32(RING_DISPATCH_CUR);
    const uint32_t slot = JOB_SLOT_TABLE + dc * SLOT_STRIDE;
    if (dc == PPC_LOAD_U32(RING_SUBMIT_CUR))      PUMP_RETURN();   // ring empty
    if (PPC_LOAD_U32(slot + SLOT_BUSY) == 0)      PUMP_RETURN();   // cursor slot not armed

    // Group block for this submit (slot.cbArg = the submit id = the group index).
    const uint32_t group = GROUP_BASE + PPC_LOAD_U32(slot + SLOT_CBARG) * GROUP_STRIDE;
    const auto cellAt = [&](uint32_t idx) -> uint32_t { return group + idx * CELL_STRIDE; };

    for (;;) {
        const uint32_t state = PPC_LOAD_U32(slot + SLOT_STATE);
        if (state > 5u) continue;                  // defensive in the generated body too (unreachable)

        if (state == 4u || state == 5u) PUMP_RETURN();   // read in flight / already produced
        if (state == 1u) goto decode;
        if (state == 2u) goto produce;
        if (state == 3u) goto finish;

        {   // ── ARM (state 0): size + allocate + kick the read ─────────────────────────────────
            if (PPC_LOAD_U32(cellAt(PPC_LOAD_U32(slot + SLOT_CELLIDX))) != 0u) {
                PPC_STORE_U32(slot + SLOT_STATE, 2u);   // output cell unconsumed: park, resume at PRODUCE
                PUMP_RETURN();
            }
            const uint32_t id = PPC_LOAD_U32(slot + SLOT_RESID);
            PPC_STORE_U32(DBG_LAST_ID, id);
            const uint32_t rawSize = toc_len(base, id) + 256u;
            PPC_STORE_U32(DBG_LAST_SIZE, rawSize);
            ctx.r3.u32 = rawSize; ctx.r4.u32 = 256u;
            ctx.lr = 0x8813A838; sub_8808CE90(ctx, base);            // raw-buffer alloc
            const uint32_t rawBuf = ctx.r3.u32;
            PPC_STORE_U32(slot + SLOT_STATE,  4u);                   // read-pending
            PPC_STORE_U32(slot + SLOT_RAWBUF, rawBuf);

            if (PPC_LOAD_U32(slot + SLOT_CB) != 0u) {
                // Submit-callback slots: ASYNC read via the streaming worker; completion re-routes.
                // ⚠ sub_880924E8 shares sub_88092B20's (id, dst, slot) shape — in the generated
                // body r4 still holds the fresh rawBuf from the alloc, and that IS the dest arg.
                // (The first refactor omitted it; the differential caught the empty buffer at
                // decode #47 — the first async-delivered record. STRICT gates earn their keep.)
                if ((int32_t)PPC_LOAD_U32(ARC_HANDLE) != -1) {
                    ctx.r3.u32 = PPC_LOAD_U32(slot + SLOT_RESID); ctx.r4.u32 = rawBuf; ctx.r5.u32 = slot;
                    ctx.lr = 0x8813AEBC; sub_880924E8(ctx, base);
                }
                PUMP_RETURN();
            }
            if ((int32_t)PPC_LOAD_U32(ARC_HANDLE) != -1) {
                // Sync read; on success sub_88092B20 runs the completion sub_8813A6A0 inline,
                // which may set the state to 1 (decode) or 2 (loaded as-is).
                ctx.r3.u32 = PPC_LOAD_U32(slot + SLOT_RESID); ctx.r4.u32 = rawBuf; ctx.r5.u32 = slot;
                ctx.lr = 0x8813A868; sub_88092B20(ctx, base);
            }
            if (toc_route(base, PPC_LOAD_U32(slot + SLOT_RESID)) != 0u) {
                PPC_STORE_U32(slot + SLOT_STATE, 1u);
                goto decode;
            }
            if (PPC_LOAD_U32(slot + SLOT_STATE) == 1u) goto decode;  // completion re-routed it
            goto produce;
        }

decode: {   // ── DECODE (state 1): image alloc + mode dispatch ──────────────────────────────────
            const uint32_t id   = PPC_LOAD_U32(slot + SLOT_RESID);
            const uint32_t mode = toc_route(base, id);
            const uint32_t fmtB = toc_fmt(base, id);
            const uint32_t dim  = fmtB ? fmtB : 1u;
            ctx.r3.u32 = dim * dim * 0x20000u + 128u;                // fmt² pages of 128KB, + header
            ctx.r4.u32 = 256u;
            ctx.lr = 0x8813A924; sub_8808CE90(ctx, base);            // image-buffer alloc
            const uint32_t imgBuf = ctx.r3.u32;
            PPC_STORE_U32(slot + SLOT_IMGBUF, imgBuf);
            ctx.r3.u32 = imgBuf;
            ctx.r4.u32 = PPC_LOAD_U32(slot + SLOT_RAWBUF);
            switch (mode) {
            case 1u: ctx.lr = 0x8813A938; sub_8813A248(ctx, base); break;
            case 2u: ctx.lr = 0x8813A94C; sub_8813A118(ctx, base); break;
            case 3u: ctx.r5.u32 = toc_len(base, id);
                     ctx.lr = (PPC_LOAD_U32(ARC_TOC_COUNT) > id) ? 0x8813A988 : 0x8813A998;
                     sub_88139D90(ctx, base); break;
            case 4u: ctx.r5.u32 = toc_len(base, id);
                     ctx.lr = 0x8813A9DC; sub_88139A88(ctx, base); break;
            default: break;                                          // modes 0 / 5+: no decoder
            }
            goto produce;
        }

produce: {  // ── PRODUCE (states 2/5): hand the result to the consumer side ─────────────────────
            PPC_STORE_U32(slot + SLOT_STATE, 5u);
            const uint32_t ci = PPC_LOAD_U32(slot + SLOT_CELLIDX);
            if (PPC_LOAD_U32(cellAt(ci)) != 0u) goto finish;         // cell busy: nothing to publish

            const uint32_t id    = PPC_LOAD_U32(slot + SLOT_RESID);
            const uint32_t route = toc_route(base, id);
            const uint32_t fmtB  = toc_fmt(base, id);
            const uint32_t flag  = fmtB ? fmtB : 1u;
            const uint32_t buf   = route ? PPC_LOAD_U32(slot + SLOT_IMGBUF)
                                         : PPC_LOAD_U32(slot + SLOT_RAWBUF);

            if (PPC_LOAD_U32(slot + SLOT_CB) != 0u) {
                // Descriptor-build family. D50's return value is the published result; CB8's is
                // NOT captured (the generated body publishes the stale 0) — preserved.
                uint32_t result = 0u;
                if (PPC_LOAD_U32(slot + SLOT_FIELD0) != 0u) {
                    ctx.r3.u32 = buf; ctx.r4.u32 = flag;
                    ctx.r5.u32 = PPC_LOAD_U32(slot + SLOT_FIELD8);
                    ctx.r6.u32 = PPC_LOAD_U32(slot + SLOT_FIELD10);
                    ctx.r7.u32 = slot;
                    ctx.lr = 0x8813AD0C; sub_88090CB8(ctx, base);
                } else {
                    ctx.r3.u32 = buf; ctx.r4.u32 = flag; ctx.r5.u32 = id; ctx.r6.u32 = slot;
                    ctx.lr = route ? 0x8813AC4C : 0x8813ACC4;
                    sub_88090D50(ctx, base);
                    result = ctx.r3.u32;
                }
                const uint32_t c = cellAt(PPC_LOAD_U32(slot + SLOT_CELLIDX));
                PPC_STORE_U32(c + 4u, result);
            } else if (PPC_LOAD_U32(slot + SLOT_FIELD0) != 0u) {
                // Page-cache record: stage the page (asset_upload.cpp consumes it render-side).
                if (buf != 0u) {
                    const uint32_t f8  = PPC_LOAD_U32(slot + SLOT_FIELD8);
                    const uint32_t f10 = PPC_LOAD_U32(slot + SLOT_FIELD10);
                    ctx.r3.u32 = ((f10 & 0xFFFFFF07u) | ((f8 >> 5) & 0x07FFFFFFu)) >> 3;
                    ctx.r4.u32 = buf + 16u;                          // past the 16-byte record header
                    ctx.r5.u32 = flag;
                    ctx.lr = 0x8813ABA4; sub_8808D640(ctx, base);
                }
                const uint32_t c = cellAt(PPC_LOAD_U32(slot + SLOT_CELLIDX));
                PPC_STORE_U32(c + 4u, 0u);                           // pages publish no handle
            } else {
                // Plain resource: build the upload descriptor; its handle is the result.
                ctx.r3.u32 = buf; ctx.r4.u32 = flag;
                ctx.lr = 0x8813AAB8; sub_88090E58(ctx, base);
                const uint32_t c = cellAt(PPC_LOAD_U32(slot + SLOT_CELLIDX));
                PPC_STORE_U32(c + 4u, ctx.r3.u32);
            }
            PPC_STORE_U32(group + GROUP_COUNTER, PPC_LOAD_U32(group + GROUP_COUNTER) + 1u);
            goto finish;
        }

finish: {   // ── FINISH (state 3): publish the cell, fire the record callback, step the chain ───
            const uint32_t ci = PPC_LOAD_U32(slot + SLOT_CELLIDX);
            if (PPC_LOAD_U32(cellAt(ci)) == 0u) {
                const uint32_t rec  = PPC_LOAD_U32(slot + SLOT_DESC)
                                    + PPC_LOAD_U32(slot + SLOT_RECIDX) * DESC_REC_STRIDE;
                const uint32_t cbfn = PPC_LOAD_U32(rec + 4u);
                if (cbfn != 0u) {
                    ctx.r3.u32 = PPC_LOAD_U32(slot + SLOT_CBARG);
                    ctx.ctr.u64 = cbfn;
                    ctx.lr = 0x8813AD84;
                    PPC_CALL_INDIRECT_FUNC(cbfn);
                }
                PPC_STORE_U32(cellAt(PPC_LOAD_U32(slot + SLOT_CELLIDX)), 1u);  // READY (consumer clears)
            }
            PPC_STORE_U32(slot + SLOT_CELLIDX, PPC_LOAD_U32(slot + SLOT_CELLIDX) + 1u);

            const uint32_t rawBuf = PPC_LOAD_U32(slot + SLOT_RAWBUF);
            if (rawBuf != 0u) {
                ctx.r3.u32 = rawBuf; ctx.lr = 0x8813ADCC; sub_8808CF58(ctx, base);
                PPC_STORE_U32(slot + SLOT_RAWBUF, 0u);
            }
            const uint32_t imgBuf = PPC_LOAD_U32(slot + SLOT_IMGBUF);
            if (imgBuf != 0u) {
                ctx.r3.u32 = imgBuf; ctx.lr = 0x8813ADF8; sub_8808CF58(ctx, base);
                PPC_STORE_U32(slot + SLOT_IMGBUF, 0u);
            }

            // Next record of the chain (12-byte records off the descriptor base).
            const uint32_t ri = PPC_LOAD_U32(slot + SLOT_RECIDX) + 1u;
            PPC_STORE_U32(slot + SLOT_RECIDX, ri);
            const uint32_t rec = PPC_LOAD_U32(slot + SLOT_DESC) + ri * DESC_REC_STRIDE;
            const int32_t  nid = (int32_t)(int16_t)PPC_LOAD_U16(rec + 2u);
            PPC_STORE_U32(slot + SLOT_RESID,   (uint32_t)nid);
            PPC_STORE_U32(slot + SLOT_FIELD0,  (uint32_t)(int32_t)(int16_t)PPC_LOAD_U16(rec + 0u));
            PPC_STORE_U32(slot + SLOT_FIELD8,  PPC_LOAD_U16(rec + 8u));
            PPC_STORE_U32(slot + SLOT_FIELD10, PPC_LOAD_U16(rec + 10u));

            if (nid < 0) {                                            // chain sentinel: slot is done
                PPC_STORE_U32(slot + SLOT_BUSY, 0u);
                const uint32_t next = PPC_LOAD_U32(RING_DISPATCH_CUR) + 1u;
                PPC_STORE_U32(RING_DISPATCH_CUR, (next >= 16u) ? 0u : next);
                PPC_STORE_U32(slot + SLOT_STATE, 0u);
                PUMP_RETURN();
            }
            PPC_STORE_U32(slot + SLOT_STATE, 0u);                     // same slot, next record, now
        }
    }
#undef PUMP_RETURN
}
