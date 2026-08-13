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
// TRANSLATION FORM — WHY THE PUMP + SUBMIT ARE FAITHFUL TRANSCRIPTIONS, NOT NATURAL C
// ════════════════════════════════════════════════════════════════════════════════════════════════
// sub_8813A738 is a ~650-instruction nested state machine whose slot/group indexing is dense, self-
// referential (repeated `id<count ? TOC[id].byte : sentinel` guards inlined at a dozen sites) and
// ring-modular; sub_8813A4D0's ring-index wrap is the signed-modulo-by-16 idiom. Their exact behavior
// IS the spec (the pump feeds byte-exact slot fields that the decoders and the upload path read back),
// and proving a from-scratch readable rewrite equivalent requires the live end-to-end differential
// (the [winit]/[wjob]/[gwork] archive instruments + RT_DECLOG/RT_DECDUMP on a card/select-screen boot)
// — which a background/non-interactive session cannot reliably bank. So, exactly as the round-4
// decoders sub_88139D90 / sub_88139A88 did for their bit-readers, these two bodies are the generated
// __imp__ operations VERBATIM (behavior-identical by construction), carrying the derived pipeline
// writeup above; round 5 refactors them to readable natural C once the gate can prove equivalence.
// Because the ops are unchanged, C1 register-file discipline (PILOT_NOTES §2) is automatic at every
// bl/bctrl: the exact register file + ctx.lr the generated body presents to each callee are preserved.
// The one tractable leaf — the completion sub_8813A6A0 (no bl/bctrl) — is written as human-readable
// natural C, the readable-translation demonstrator, and closes the loop archive.cpp's sub_88092B20
// depends on.

#include "ppc_recomp_shared.h"   // ppc_config.h (base 0x88000000) + ppc_context.h + all callee decls

namespace {
constexpr uint32_t ARC_TOC_COUNT = 0x887AD19C;   // entry count            [-30597<<16 -11876]
constexpr uint32_t ARC_TOC_PTR   = 0x887AD1A8;   // in-memory TOC base      [-30597<<16 -11864]
constexpr uint32_t TOC_STRIDE    = 0x14;         // 20 bytes / TOC entry
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
// Ground truth: out_reco/ppc_recomp.18.cpp:10979-11097 (register-exact recomp, entry → blr). Reads the
// submit cursor [0x887ACE00], indexes the 56-byte slot at 0x884D20E8 + cursor*56; if it is busy
// returns 0. Otherwise bumps the sequence counter [0x887ACE04] (wrapping 0→1), stores id/callback/seq
// into the slot, marks it busy, loads the resource's descriptor (0x88290CD0 + id*4) and copies its
// signed-halfword fields (+2→slot+24 id, +0→slot+28, +8→slot+36, +10→slot+40), zeroes the slot's
// working fields, and advances the submit cursor (mod 16). FAITHFUL TRANSCRIPTION (see the form note
// in the header): the ring-index wrap is the signed-modulo-by-16 idiom and the slot layout is read
// back byte-exact by the pump, so the generated ops are reproduced verbatim. LEAF-shaped (no bl) but
// transcribed to keep the wrap + field stores bit-exact.
// ════════════════════════════════════════════════════════════════════════════════════════════════
PPC_FUNC_IMPL(__imp__sub_8813A4D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// addi r8,r11,-12796
	ctx.r8.s64 = ctx.r11.s64 + -12796;
	// addi r11,r10,8424
	ctx.r11.s64 = ctx.r10.s64 + 8424;
	// lwz r10,-4(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4);
	// mulli r9,r10,56
	ctx.r9.s64 = ctx.r10.s64 * 56;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8813a504
	if (ctx.cr6.eq) goto loc_8813A504;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr
	return;
loc_8813A504:
	// lwz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// addic. r9,r9,1
	ctx.xer.ca = ctx.r9.u32 > 4294967294;
	ctx.r9.s64 = ctx.r9.s64 + 1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r9,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
	// bne 0x8813a51c
	if (!ctx.cr0.eq) goto loc_8813A51C;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r9,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
loc_8813A51C:
	// lis r7,-30679
	ctx.r7.s64 = -2010578944;
	// stw r3,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r3.u32);
	// rlwinm r5,r3,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r4,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r4.u32);
	// addi r3,r7,3280
	ctx.r3.s64 = ctx.r7.s64 + 3280;
	// stw r9,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r7,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwzx r5,r5,r3
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r3.u32);
	// subfc r31,r7,r10
	ctx.xer.ca = ctx.r10.u32 >= ctx.r7.u32;
	ctx.r31.s64 = ctx.r10.s64 - ctx.r7.s64;
	// rlwinm r4,r10,1,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// stw r6,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r6.u32);
	// rlwinm r7,r7,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0x1;
	// stw r6,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r6.u32);
	// stw r6,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r6.u32);
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// subfe r6,r4,r7
	temp.u8 = (~ctx.r4.u32 + ctx.r7.u32 < ~ctx.r4.u32) | (~ctx.r4.u32 + ctx.r7.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ~ctx.r4.u64 + ctx.r7.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r5,44(r11)
	PPC_STORE_U32(ctx.r11.u32 + 44, ctx.r5.u32);
	// lhz r4,2(r5)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r5.u32 + 2);
	// extsh r9,r4
	ctx.r9.s64 = ctx.r4.s16;
	// stw r9,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r9.u32);
	// and r10,r6,r10
	ctx.r10.u64 = ctx.r6.u64 & ctx.r10.u64;
	// lhz r7,0(r5)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r5.u32 + 0);
	// extsh r6,r7
	ctx.r6.s64 = ctx.r7.s16;
	// stw r6,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r6.u32);
	// lhz r4,8(r5)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r5.u32 + 8);
	// stw r4,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r4.u32);
	// lhz r9,10(r5)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r5.u32 + 10);
	// stw r10,-4(r8)
	PPC_STORE_U32(ctx.r8.u32 + -4, ctx.r10.u32);
	// stw r9,40(r11)
	PPC_STORE_U32(ctx.r11.u32 + 40, ctx.r9.u32);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr
	return;
}

// ════════════════════════════════════════════════════════════════════════════════════════════════
// sub_8813A738 — THE PER-FRAME ASSET JOB PUMP. THE KEYSTONE. HOOKED (PPC_FUNC(sub_8813A738) in
//               merged_game.cpp:1352, the [boot]/[gmstage] main-loop instrument) → __imp__ seam.
//
//   sub_8813A738()   [drains the ready slots of the 16-entry job ring one frame's worth]
//
// Ground truth: out_reco/ppc_recomp.18.cpp:11355-12419 (register-exact recomp, entry → __restgprlr_20
// tail). Walks the armed slots between the dispatch cursor [0x887ACDFC] and the submit cursor
// [0x887ACE00]; per slot advances slot+8 through the read → decode → upload state machine described in
// the header (state 0 read via archive.cpp sub_88092B20; state 1 mode-dispatch into the four
// asset_decode.cpp decoders; state 5 build-descriptor + TEXTURE UPLOAD via sub_8808D640), fires the
// per-slot user callback (bctrl on slot+12), frees scratch (sub_8808CF58), reloads the next descriptor,
// rings the dispatch cursor (mod 16). FAITHFUL TRANSCRIPTION (header form note): the generated __imp__
// operations verbatim — behavior-identical by construction; C1 discipline is automatic (the exact
// register file + ctx.lr are preserved at every bl/bctrl into the still-generated alloc/upload callees
// and the translated read/decode callees). Round 5 refactors to readable natural C once the live
// [winit]/[wjob]/[gwork] + RT_DECLOG/RT_DECDUMP differential can prove equivalence.
// ════════════════════════════════════════════════════════════════════════════════════════════════
PPC_FUNC_IMPL(__imp__sub_8813A738) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071138
	ctx.lr = 0x8813A740;
	__savegprlr_20(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// addi r29,r11,-11864
	ctx.r29.s64 = ctx.r11.s64 + -11864;
	// li r26,1
	ctx.r26.s64 = 1;
	// addi r10,r10,8424
	ctx.r10.s64 = ctx.r10.s64 + 8424;
	// mr r24,r26
	ctx.r24.u64 = ctx.r26.u64;
	// lwz r9,-940(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + -940);
	// lwz r11,-936(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -936);
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// mulli r9,r9,56
	ctx.r9.s64 = ctx.r9.s64 * 56;
	// add r31,r9,r10
	ctx.r31.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmpw cr6,r8,r11
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x8813aebc
	if (ctx.cr6.eq) goto loc_8813AEBC;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8813aebc
	if (ctx.cr6.eq) goto loc_8813AEBC;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lis r9,-30647
	ctx.r9.s64 = -2008481792;
	// lwz r7,-12(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + -12);
	// lis r20,-30683
	ctx.r20.s64 = -2010841088;
	// mulli r10,r10,7204
	ctx.r10.s64 = ctx.r10.s64 * 7204;
	// addi r11,r9,18424
	ctx.r11.s64 = ctx.r9.s64 + 18424;
	// li r21,4
	ctx.r21.s64 = 4;
	// add r28,r10,r11
	ctx.r28.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// li r27,0
	ctx.r27.s64 = 0;
	// lis r25,-30647
	ctx.r25.s64 = -2008481792;
	// li r23,5
	ctx.r23.s64 = 5;
	// lis r22,-30647
	ctx.r22.s64 = -2008481792;
loc_8813A7B8:
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bgt cr6,0x8813ae88
	if (ctx.cr6.gt) goto loc_8813AE88;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x8813a8ac
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8813A8AC;
	// bdzf 4*cr6+eq,0x8813a9e4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8813A9E4;
	// bdzf 4*cr6+eq,0x8813ad38
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8813AD38;
	// bdzf 4*cr6+eq,0x8813aebc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8813AEBC;
	// bne cr6,0x8813aebc
	if (!ctx.cr6.eq) goto loc_8813AEBC;
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r28
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r28.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x8813ae98
	if (!ctx.cr6.eq) goto loc_8813AE98;
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// stw r11,18416(r22)
	PPC_STORE_U32(ctx.r22.u32 + 18416, ctx.r11.u32);
	// bge cr6,0x8813a824
	if (!ctx.cr6.lt) goto loc_8813A824;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r11,8(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// b 0x8813a828
	goto loc_8813A828;
loc_8813A824:
	// lis r11,2
	ctx.r11.s64 = 131072;
loc_8813A828:
	// addi r3,r11,256
	ctx.r3.s64 = ctx.r11.s64 + 256;
	// li r4,256
	ctx.r4.s64 = 256;
	// stw r3,18420(r25)
	PPC_STORE_U32(ctx.r25.u32 + 18420, ctx.r3.u32);
	// bl 0x8808ce90
	ctx.lr = 0x8813A838;
	sub_8808CE90(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// stw r21,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r21.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r11,11804(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 11804);
	// stw r3,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r3.u32);
	// bne cr6,0x8813aea8
	if (!ctx.cr6.eq) goto loc_8813AEA8;
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8813a868
	if (ctx.cr6.eq) goto loc_8813A868;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88092b20
	ctx.lr = 0x8813A868;
	sub_88092B20(ctx, base);
loc_8813A868:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r7,-12(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + -12);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x8813a894
	if (!ctx.cr6.lt) goto loc_8813A894;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lbz r11,2(r9)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 2);
	// b 0x8813a898
	goto loc_8813A898;
loc_8813A894:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_8813A898:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8813a8ac
	if (ctx.cr6.eq) goto loc_8813A8AC;
	// stw r26,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r26.u32);
	// b 0x8813a8b8
	goto loc_8813A8B8;
loc_8813A8AC:
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x8813a9e4
	if (!ctx.cr6.eq) goto loc_8813A9E4;
loc_8813A8B8:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x8813a8dc
	if (!ctx.cr6.lt) goto loc_8813A8DC;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lbz r9,2(r8)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r8.u32 + 2);
	// b 0x8813a8e0
	goto loc_8813A8E0;
loc_8813A8DC:
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
loc_8813A8E0:
	// clrlwi r30,r9,24
	ctx.r30.u64 = ctx.r9.u32 & 0xFF;
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x8813a908
	if (!ctx.cr6.lt) goto loc_8813A908;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lbz r11,3(r10)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 3);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813a90c
	if (!ctx.cr6.eq) goto loc_8813A90C;
loc_8813A908:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_8813A90C:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// li r4,256
	ctx.r4.s64 = 256;
	// mullw r10,r11,r11
	ctx.r10.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r11.s32);
	// rlwinm r11,r10,17,0,14
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 17) & 0xFFFE0000;
	// addi r3,r11,128
	ctx.r3.s64 = ctx.r11.s64 + 128;
	// bl 0x8808ce90
	ctx.lr = 0x8813A924;
	sub_8808CE90(ctx, base);
	// cmpwi cr6,r30,1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 1, ctx.xer);
	// stw r3,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r3.u32);
	// bne cr6,0x8813a93c
	if (!ctx.cr6.eq) goto loc_8813A93C;
	// lwz r4,48(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// bl 0x8813a248
	ctx.lr = 0x8813A938;
	sub_8813A248(ctx, base);
	// b 0x8813a9dc
	goto loc_8813A9DC;
loc_8813A93C:
	// cmpwi cr6,r30,2
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 2, ctx.xer);
	// bne cr6,0x8813a950
	if (!ctx.cr6.eq) goto loc_8813A950;
	// lwz r4,48(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// bl 0x8813a118
	ctx.lr = 0x8813A94C;
	sub_8813A118(ctx, base);
	// b 0x8813a9dc
	goto loc_8813A9DC;
loc_8813A950:
	// cmpwi cr6,r30,3
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 3, ctx.xer);
	// bne cr6,0x8813a99c
	if (!ctx.cr6.eq) goto loc_8813A99C;
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r10,-12(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + -12);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8813a98c
	if (!ctx.cr6.lt) goto loc_8813A98C;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r4,48(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r5,8(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x88139d90
	ctx.lr = 0x8813A988;
	sub_88139D90(ctx, base);
	// b 0x8813a9dc
	goto loc_8813A9DC;
loc_8813A98C:
	// lis r5,2
	ctx.r5.s64 = 131072;
	// lwz r4,48(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// bl 0x88139d90
	ctx.lr = 0x8813A998;
	sub_88139D90(ctx, base);
	// b 0x8813a9dc
	goto loc_8813A9DC;
loc_8813A99C:
	// cmpwi cr6,r30,4
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 4, ctx.xer);
	// bne cr6,0x8813a9dc
	if (!ctx.cr6.eq) goto loc_8813A9DC;
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r10,-12(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + -12);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8813a9d0
	if (!ctx.cr6.lt) goto loc_8813A9D0;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r5,8(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// b 0x8813a9d4
	goto loc_8813A9D4;
loc_8813A9D0:
	// lis r5,2
	ctx.r5.s64 = 131072;
loc_8813A9D4:
	// lwz r4,48(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// bl 0x88139a88
	ctx.lr = 0x8813A9DC;
	sub_88139A88(ctx, base);
loc_8813A9DC:
	// lwz r7,-12(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + -12);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
loc_8813A9E4:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// stw r23,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r23.u32);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r28
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r28.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x8813ad38
	if (!ctx.cr6.eq) goto loc_8813AD38;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8813abd4
	if (!ctx.cr6.eq) goto loc_8813ABD4;
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8813aae8
	if (!ctx.cr6.eq) goto loc_8813AAE8;
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplw cr6,r5,r7
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x8813aa44
	if (!ctx.cr6.lt) goto loc_8813AA44;
	// rlwinm r11,r5,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r5,r11
	ctx.r11.u64 = ctx.r5.u64 + ctx.r11.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lbz r11,2(r9)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 2);
	// b 0x8813aa48
	goto loc_8813AA48;
loc_8813AA44:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_8813AA48:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8813aa84
	if (ctx.cr6.eq) goto loc_8813AA84;
	// cmplw cr6,r5,r7
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x8813aa78
	if (!ctx.cr6.lt) goto loc_8813AA78;
	// rlwinm r11,r5,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r5,r11
	ctx.r11.u64 = ctx.r5.u64 + ctx.r11.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lbz r11,3(r10)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 3);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813aa7c
	if (!ctx.cr6.eq) goto loc_8813AA7C;
loc_8813AA78:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_8813AA7C:
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// b 0x8813aab0
	goto loc_8813AAB0;
loc_8813AA84:
	// cmplw cr6,r5,r7
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x8813aaa8
	if (!ctx.cr6.lt) goto loc_8813AAA8;
	// rlwinm r11,r5,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r5,r11
	ctx.r11.u64 = ctx.r5.u64 + ctx.r11.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lbz r11,3(r10)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 3);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813aaac
	if (!ctx.cr6.eq) goto loc_8813AAAC;
loc_8813AAA8:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_8813AAAC:
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
loc_8813AAB0:
	// clrlwi r4,r11,24
	ctx.r4.u64 = ctx.r11.u32 & 0xFF;
	// bl 0x88090e58
	ctx.lr = 0x8813AAB8;
	sub_88090E58(ctx, base);
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r7,-12(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + -12);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r28
	ctx.r9.u64 = ctx.r11.u64 + ctx.r28.u64;
	// stw r3,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r3.u32);
	// lwz r11,7200(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 7200);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,7200(r28)
	PPC_STORE_U32(ctx.r28.u32 + 7200, ctx.r11.u32);
	// b 0x8813ad38
	goto loc_8813AD38;
loc_8813AAE8:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x8813ab0c
	if (!ctx.cr6.lt) goto loc_8813AB0C;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lbz r9,2(r8)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r8.u32 + 2);
	// b 0x8813ab10
	goto loc_8813AB10;
loc_8813AB0C:
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
loc_8813AB10:
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8813ab4c
	if (ctx.cr6.eq) goto loc_8813AB4C;
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x8813ab40
	if (!ctx.cr6.lt) goto loc_8813AB40;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lbz r11,3(r9)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 3);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813ab44
	if (!ctx.cr6.eq) goto loc_8813AB44;
loc_8813AB40:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_8813AB44:
	// lwz r9,52(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// b 0x8813ab78
	goto loc_8813AB78;
loc_8813AB4C:
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x8813ab70
	if (!ctx.cr6.lt) goto loc_8813AB70;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lbz r11,3(r9)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 3);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813ab74
	if (!ctx.cr6.eq) goto loc_8813AB74;
loc_8813AB70:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_8813AB74:
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
loc_8813AB78:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8813abac
	if (ctx.cr6.eq) goto loc_8813ABAC;
	// lwz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// clrlwi r5,r11,24
	ctx.r5.u64 = ctx.r11.u32 & 0xFF;
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// addi r4,r9,16
	ctx.r4.s64 = ctx.r9.s64 + 16;
	// rlwinm r6,r8,27,5,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x7FFFFFF;
	// rlwinm r7,r10,0,29,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFF07;
	// or r3,r7,r6
	ctx.r3.u64 = ctx.r7.u64 | ctx.r6.u64;
	// rlwinm r3,r3,29,3,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 29) & 0x1FFFFFFF;
	// bl 0x8808d640
	ctx.lr = 0x8813ABA4;
	sub_8808D640(ctx, base);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r7,-12(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + -12);
loc_8813ABAC:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r28
	ctx.r9.u64 = ctx.r11.u64 + ctx.r28.u64;
	// stw r27,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r27.u32);
	// lwz r11,7200(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 7200);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,7200(r28)
	PPC_STORE_U32(ctx.r28.u32 + 7200, ctx.r11.u32);
	// b 0x8813ad38
	goto loc_8813AD38;
loc_8813ABD4:
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplw cr6,r5,r7
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x8813abf8
	if (!ctx.cr6.lt) goto loc_8813ABF8;
	// rlwinm r11,r5,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r5,r11
	ctx.r11.u64 = ctx.r5.u64 + ctx.r11.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lbz r11,2(r9)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 2);
	// b 0x8813abfc
	goto loc_8813ABFC;
loc_8813ABF8:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_8813ABFC:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// beq cr6,0x8813ac84
	if (ctx.cr6.eq) goto loc_8813AC84;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8813ac54
	if (!ctx.cr6.eq) goto loc_8813AC54;
	// cmplw cr6,r5,r7
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x8813ac38
	if (!ctx.cr6.lt) goto loc_8813AC38;
	// rlwinm r11,r5,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r5,r11
	ctx.r11.u64 = ctx.r5.u64 + ctx.r11.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lbz r11,3(r10)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 3);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813ac3c
	if (!ctx.cr6.eq) goto loc_8813AC3C;
loc_8813AC38:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_8813AC3C:
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// clrlwi r4,r11,24
	ctx.r4.u64 = ctx.r11.u32 & 0xFF;
	// bl 0x88090d50
	ctx.lr = 0x8813AC4C;
	sub_88090D50(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x8813ad0c
	goto loc_8813AD0C;
loc_8813AC54:
	// cmplw cr6,r5,r7
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x8813ac78
	if (!ctx.cr6.lt) goto loc_8813AC78;
	// rlwinm r11,r5,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r5,r11
	ctx.r11.u64 = ctx.r5.u64 + ctx.r11.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lbz r11,3(r10)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 3);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813ac7c
	if (!ctx.cr6.eq) goto loc_8813AC7C;
loc_8813AC78:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_8813AC7C:
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// b 0x8813acf8
	goto loc_8813ACF8;
loc_8813AC84:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8813accc
	if (!ctx.cr6.eq) goto loc_8813ACCC;
	// cmplw cr6,r5,r7
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x8813acb0
	if (!ctx.cr6.lt) goto loc_8813ACB0;
	// rlwinm r11,r5,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r5,r11
	ctx.r11.u64 = ctx.r5.u64 + ctx.r11.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lbz r11,3(r10)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 3);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813acb4
	if (!ctx.cr6.eq) goto loc_8813ACB4;
loc_8813ACB0:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_8813ACB4:
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// clrlwi r4,r11,24
	ctx.r4.u64 = ctx.r11.u32 & 0xFF;
	// bl 0x88090d50
	ctx.lr = 0x8813ACC4;
	sub_88090D50(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x8813ad0c
	goto loc_8813AD0C;
loc_8813ACCC:
	// cmplw cr6,r5,r7
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x8813acf0
	if (!ctx.cr6.lt) goto loc_8813ACF0;
	// rlwinm r11,r5,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r5,r11
	ctx.r11.u64 = ctx.r5.u64 + ctx.r11.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lbz r11,3(r10)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 3);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813acf4
	if (!ctx.cr6.eq) goto loc_8813ACF4;
loc_8813ACF0:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_8813ACF4:
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
loc_8813ACF8:
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// clrlwi r4,r11,24
	ctx.r4.u64 = ctx.r11.u32 & 0xFF;
	// lwz r5,36(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// bl 0x88090cb8
	ctx.lr = 0x8813AD0C;
	sub_88090CB8(ctx, base);
loc_8813AD0C:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r7,-12(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + -12);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r28
	ctx.r9.u64 = ctx.r11.u64 + ctx.r28.u64;
	// stw r30,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r30.u32);
	// lwz r11,7200(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 7200);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// stw r8,7200(r28)
	PPC_STORE_U32(ctx.r28.u32 + 7200, ctx.r8.u32);
loc_8813AD38:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r28
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r28.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x8813ada0
	if (!ctx.cr6.eq) goto loc_8813ADA0;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r9,44(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r11,4(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8813ad8c
	if (ctx.cr6.eq) goto loc_8813AD8C;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl
	ctx.lr = 0x8813AD84;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r7,-12(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + -12);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
loc_8813AD8C:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r26,r9,r28
	PPC_STORE_U32(ctx.r9.u32 + ctx.r28.u32, ctx.r26.u32);
loc_8813ADA0:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r30,r31,48
	ctx.r30.s64 = ctx.r31.s64 + 48;
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stw r8,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r8.u32);
	// beq cr6,0x8813add8
	if (ctx.cr6.eq) goto loc_8813ADD8;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8813add8
	if (ctx.cr6.eq) goto loc_8813ADD8;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x8808cf58
	ctx.lr = 0x8813ADCC;
	sub_8808CF58(ctx, base);
	// lwz r7,-12(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + -12);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// stw r27,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r27.u32);
loc_8813ADD8:
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addi r30,r31,52
	ctx.r30.s64 = ctx.r31.s64 + 52;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8813ae04
	if (ctx.cr6.eq) goto loc_8813AE04;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8813ae04
	if (ctx.cr6.eq) goto loc_8813AE04;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x8808cf58
	ctx.lr = 0x8813ADF8;
	sub_8808CF58(ctx, base);
	// lwz r7,-12(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + -12);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// stw r27,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r27.u32);
loc_8813AE04:
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r9,44(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lhz r9,2(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 2);
	// extsh r8,r9
	ctx.r8.s64 = ctx.r9.s16;
	// stw r8,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r8.u32);
	// rotlwi r6,r8,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// lhz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r11.u32 + 0);
	// extsh r4,r5
	ctx.r4.s64 = ctx.r5.s16;
	// stw r4,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r4.u32);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// lhz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r11.u32 + 8);
	// stw r3,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r3.u32);
	// lhz r11,10(r11)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r11.u32 + 10);
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// bge cr6,0x8813ae84
	if (!ctx.cr6.lt) goto loc_8813AE84;
	// lwz r11,-940(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -940);
	// li r9,16
	ctx.r9.s64 = 16;
	// stw r27,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r27.u32);
	// mr r24,r27
	ctx.r24.u64 = ctx.r27.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r8,r9,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1;
	// subfc r6,r9,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r9.u32;
	ctx.r6.s64 = ctx.r11.s64 - ctx.r9.s64;
	// rlwinm r5,r11,1,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// subfe r4,r5,r8
	temp.u8 = (~ctx.r5.u32 + ctx.r8.u32 < ~ctx.r5.u32) | (~ctx.r5.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r4.u64 = ~ctx.r5.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r3,r4,r11
	ctx.r3.u64 = ctx.r4.u64 & ctx.r11.u64;
	// stw r3,-940(r29)
	PPC_STORE_U32(ctx.r29.u32 + -940, ctx.r3.u32);
loc_8813AE84:
	// stw r27,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r27.u32);
loc_8813AE88:
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// bne cr6,0x8813a7b8
	if (!ctx.cr6.eq) goto loc_8813A7B8;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x88071188
	__restgprlr_20(ctx, base);
	return;
loc_8813AE98:
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x88071188
	__restgprlr_20(ctx, base);
	return;
loc_8813AEA8:
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8813aebc
	if (ctx.cr6.eq) goto loc_8813AEBC;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x880924e8
	ctx.lr = 0x8813AEBC;
	sub_880924E8(ctx, base);
loc_8813AEBC:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x88071188
	__restgprlr_20(ctx, base);
	return;
}
