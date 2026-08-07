// _tmpscripts/game_entry_msgs_abn_DRAFT.cpp — DRAFT, DELIBERATELY OUTSIDE THE BUILD TREE.
// ============================================================================================
// C1-class MATCHED re-earn of GameEntry for reco_abnormal (modeIdx 1 / Ver 1.5 "XBOX-360 MODE"
// / MODULE_154_3_HI) at guest 0x8824E6A0.  Derived from decomp/game/game_entry_msgs.cpp (the
// MATCHED reco_normal translation of 0x8824E698, gate-passed 2026-07-28) by applying a
// per-address map that was DECODED DIRECTLY FROM THE reco_abnormal IMAGE — not inferred from
// the census laws.  Every substituted literal below was read out of an abn instruction word.
//
// PROVENANCE (this file's evidence base, all reproducible):
//   * abn flat image: xexdump.exe assets/media/Module/reco_abnormal.xex  (base 0x88000000)
//   * body diff: 270 words of GameEntry compared nor[0x8824E698+i] vs abn[0x8824E6A0+i]
//       200 byte-identical | 36 branch words whose ABSOLUTE target is unchanged
//       22 immediates +0x8 | 11 immediates +0x60 | 1 immediate -0x28
//       ZERO structural differences.  VERDICT: IDENTICAL MODULO SHIFT.
//   * generated cross-check: out_reco_abn/ppc_recomp.32.cpp:25606-26270 (register-exact,
//     with the disassembly as comments) vs out_reco/ppc_recomp.32.cpp:25606-26270.
//   * report: _tmpscripts/abn_gameentry_matched_prep.md
//
// ★ WHAT CHANGED VS THE reco_normal TRANSLATION — exhaustive, four classes and nothing else:
//   1. The seam symbol:  __imp__sub_8824E698 -> __imp__sub_8824E6A0        (+8, export-RVA proven)
//   2. ctx.lr return addresses at every call site: +8                       (16 sites)
//   3. Guest .data globals: +0x60                                           (33 distinct addrs)
//      EXCEPT 0x88252D58 and 0x88252DD8 which stay put (delta 0 — verified two ways, below).
//   4. ONE genuinely-different content reference: the msg-2 ROM-name string.  See ★ROM below.
//   NOT changed: every callee symbol (all 14 + millicode are BELOW the census split at
//   0x880DEF88, so their addresses are identical in reco_abnormal — verified by decoding all
//   15 bl words in both images: absolute target delta 0 on every one), every structure offset,
//   every loop count, every constant, and the code pointer 0x880083C0 (also below the split).
//
// ★ROM — THE ONE REAL CONTENT DIVERGENCE INSIDE GameEntry (headline finding):
//   msg 2's strcpy source is 0x88063284 in reco_normal and 0x8806325C in reco_abnormal
//   (delta -0x28).  These are NOT the same bytes relocated — they are DIFFERENT STRINGS:
//       nor 0x88063284 = "Rom\cg_v154.bin"    (15 bytes incl. NUL)
//       abn 0x8806325C = "Rom\cg_v154hi.bin"  (17 bytes incl. NUL)
//   This is the ARCADE-vs-HI content selector, and it is why the first-light log shows
//   [file] open "game:\media\Rom\cg_v154hi.bin".  The loop is NUL-terminated so no count
//   changes, but the destination window at 0x887AD210 receives 17 bytes instead of 15.
//   Do NOT treat -0x28 as a general ".rdata shifted" law: the wider .rdata window does NOT
//   match at -0x28 (verified), the section is genuinely re-laid-out AND re-contented.
//
// ★ REGISTER-FILE RULE (the C1 gate failed TWICE on this — NOTE_campaign_decomp.md
//   "C1 GATE PASS" item 1).  Callees CONSUME the incidental register file at call boundaries.
//   The mirroring below is copied VERBATIM from the MATCHED body: r30=0 and r11=msg at entry,
//   callee-saved r30/r31 saved+restored, and the msg-2 case is a literal stream mirror.
//   DO NOT "clean up" any of it.
//
// ★ 8 SHIFT-COLLISION ADDRESSES — the reason a half-applied +0x60 would look plausible:
//   0x887AD4D8+0x60=0x887AD538, 0x50C->0x56C, 0x544->0x5A4, 0x56C->0x5CC, 0x5A0->0x600,
//   0x5A4->0x604, 0x5A8->0x608, 0x5AC->0x60C — each RESULT is itself a live global in the
//   reco_normal address space and is also referenced by this very function.  A partial edit
//   therefore writes to a real-looking mailbox instead of faulting.  Review every line.
//
// STATUS: DRAFT.  Not compiled, not linked, not gated.  See the report's gate plan.
// ============================================================================================

#include "ppc_recomp_shared.h"   // ppc_config.h + ppc_context.h + generated externs (-I out_reco_abn)

// Callees — IDENTICAL SYMBOLS to the reco_normal translation.  All 14 targets are below the
// census split (0x880DEF88) so reco_abnormal hosts them at the same guest addresses; all 14
// exist in out_reco_abn's generated set (checked: ppc_recomp.0/4/5.cpp, same files as normal).
// Plain sub_* so calls keep routing through the same strong-over-weak instrument seam.
// ⚠ BUILD NOTE: this TU must NOT be force-included with out_reco_abn/abn_symbol_map.h.  Nothing
//   here needs renaming, and the map contains `#define sub_8824E698 sub_8824E6A0`, which would
//   silently rewrite any future reference written with the reco_normal name.
PPC_EXTERN_FUNC(sub_880923D0);
PPC_EXTERN_FUNC(sub_88073BD0);
PPC_EXTERN_FUNC(sub_8808D0A8);
PPC_EXTERN_FUNC(sub_8808FDF8);
PPC_EXTERN_FUNC(sub_8808FAB8);
PPC_EXTERN_FUNC(sub_8808FF58);
PPC_EXTERN_FUNC(sub_8808D930);
PPC_EXTERN_FUNC(sub_8808FA68);
PPC_EXTERN_FUNC(sub_8808E468);
PPC_EXTERN_FUNC(sub_8808F1E8);
PPC_EXTERN_FUNC(sub_8808F150);
PPC_EXTERN_FUNC(sub_8808F098);
PPC_EXTERN_FUNC(sub_8808EFA8);
PPC_EXTERN_FUNC(sub_8808EEC8);

namespace {
// lis/addi address arithmetic sign-extends into the 64-bit register; mirror it exactly for
// every register value handed to a callee (callees address with .u32, but stay bit-true).
constexpr int64_t SX(uint32_t v) { return (int64_t)(int32_t)v; }

// Message ids — UNCHANGED from the reco_normal translation.  The 20-way dispatch, the case
// order, the jump-table contents (all 20 entries +8, decoded from the abn image) and every
// case's semantics are identical.  Only the addresses the cases touch move.
enum GameMsg : uint32_t {
    MSG_CONFIG_IN      = 1,   // arg[0..5]->0x887AD62C cluster + 96-byte copy -> 0x885C5C10
    MSG_BOOT           = 2,   // ROM name strcpy + events @0x885C651C + worker 0x88168FA0 bring-up
    MSG_BOOT_SHUTDOWN  = 3,   // join + teardown
    /* 4 unimplemented -> -1 */
    MSG_FRAME_RENDER   = 5,   // handshake + per-frame draw-block build
    MSG_GETPTR_5D4     = 6,   // *arg = &0x887AD634   (was 0x887AD5D4)
    MSG_GETPTR_5DC     = 7,   // *arg = &0x887AD63C   (was 0x887AD5DC)
    MSG_GETPTR_544     = 8,   // *arg = &0x887AD5A4   (was 0x887AD544; guarded arg!=0)
    MSG_REGISTER_CBS   = 9,   // 4 {fn,ctx} callback pairs
    MSG_SET_887AD534   = 10,  // 0x887AD594=*arg, 0x887AD598=0
    MSG_SET_88252DD8   = 11,  // 0x88252DD8=*arg   (⚠ NOT shifted — see g_msg11Slot)
    MSG_MODE64_ARM     = 12,  // PILOT: 0x88252D58=-1, mode64 0x887AD5E4=3, 0x887AD5FC=0x8000
    MSG_RETURN_TO_MENU = 13,  // PILOT: reload mailbox 0x887AD5EC=1
    MSG_CREDIT_ARM     = 14,  // PILOT: if 0x887AD5A7==0 -> 0x887AD5EC=2
    MSG_COLOR_BLOCK_IN = 15, MSG_COLOR_DEFAULTS = 16, MSG_MAGIC_VALIDATE = 17,
    MSG_BLOCK2C_IN     = 18,
    MSG_MODE_SELECT    = 19,  // 0x88252D58=*arg range-checked (<5 | 10..14), else -1
    MSG_DESCRIPTOR_IN  = 20,
};

// ---- Pilot-critical mailbox cluster, reco_abnormal addresses ----------------------------
// Every value below was decoded from an abn instruction word (the resolved effective address
// of the store/load at the stated guest PC), not computed from a law.  The reco_normal value
// is given so the +0x60 (or delta-0) can be re-checked at review time.
// ⚠ CONTENT-EVIDENCE STRENGTH: 0x887ADxxx is BSS (all-zero in both images), so byte-comparing
//   the images at these addresses is VACUOUS and proves nothing either way.  The +0x60 rests
//   entirely on the code side: the 11 displacement deltas inside this function, plus the
//   13,756 image-wide (abn_recomp_notes.md §2b).  That is the right kind of evidence for a
//   translation — we must reference what the abn CODE references, which is what we decoded.
constexpr uint32_t g_reloadReq  = 0x887AD5ECu; // nor 0x887AD58C  @abn 0x8824E9E4 stw  — msg13->1 / msg14->2
constexpr uint32_t g_creditGate = 0x887AD5A7u; // nor 0x887AD547  @abn 0x8824E9F8 lbz  — byte guard on msg 14
constexpr uint32_t g_mode64     = 0x887AD5E4u; // nor 0x887AD584  @abn 0x8824E9C8 stw  — "mode64"
constexpr uint32_t g_msg12Aux   = 0x887AD5FCu; // nor 0x887AD59C  @abn 0x8824E9CC stw  — msg-12 companion (0x8000)

// ⚠⚠ THE TWO NON-SHIFTED GLOBALS.  Both live inside the .data region the census flagged as
// "genuinely differing" (0x88250767..~0x88351830), so no shift law applies and each needed
// individual verification.  BOTH VERIFIED delta 0, two independent ways:
//   (a) code side: the abn instructions at 0x8824E998 (msg11 stw), 0x8824E9C0 (msg12 stw),
//       0x8824EA8C and 0x8824EAA4 (msg19 stw) resolve to the SAME addresses as their
//       reco_normal twins (0x8824E990 / 0x8824E9B8 / 0x8824EA84 / 0x8824EA9C) — the
//       instruction words are byte-identical, which is why they never appeared in the
//       body diff at all;
//   (b) content side (NON-vacuous here — this data is initialized, not BSS):
//       nor[0x88252D58..+0x100] == abn[0x88252D58..+0x100]  EXACTLY, and does NOT match at
//       +0x60.  First bytes: ff ff ff ff 00 00 00 01 "Player1\0" — i.e. the mode slot's
//       static -1 initializer, present at the same address in both modules.
//       Same result for 0x88252DD8: identical at delta 0 (00 00 00 01 "gameMainThr."),
//       no match at +0x60.
// CONFIDENCE: HIGH.  This is the strongest-evidenced pair in the file.
constexpr uint32_t g_modeSlot   = 0x88252D58u; // nor 0x88252D58 — UNCHANGED
constexpr uint32_t g_msg11Slot  = 0x88252DD8u; // nor 0x88252DD8 — UNCHANGED
} // namespace

PPC_FUNC_IMPL(__imp__sub_8824E6A0) {
    PPC_FUNC_PROLOGUE();
    // @8824E6A0-E6A8: mflr r12 (7D8802A6) + __savegprlr_29 (bl 0x8807115C — SAME address, below
    // the split; the bl WORD differs only because the caller moved: 4BE22AC1 -> 4BE22AB9, LI -8)
    // + stwu r1,-128(r1) (9421FF80).  Frame emulated (back-chain store + SP move) so callee frames and
    // the msg-2 zero-staging land at the generated addresses; the savegpr/lr scratch stores
    // themselves are host-register state and are not reproduced (accepted residual, identical
    // to the MATCHED reco_normal body — PILOT_NOTES.md §6).
    // ★ REGISTER-FILE MIRROR — VERBATIM from the MATCHED body.  Do not simplify.
    const uint32_t entry_r1 = ctx.r1.u32;
    const uint64_t entry_r30 = ctx.r30.u64, entry_r31 = ctx.r31.u64;   // callee-saved
    PPC_STORE_U32(entry_r1 - 128, entry_r1);      // @8824E6A8 stwu back-chain
    ctx.r1.u32 = entry_r1 - 128;
    const uint32_t msg = ctx.r3.u32;              // @8824E6AC mr r11,r3
    ctx.r11.u64 = ctx.r3.u64;                     //   (callees in call-cases see r11=msg)
    ctx.r3.u64 = ctx.r4.u64;                      // @8824E6B0 mr r3,r4 — every case sees r3=arg
    const uint32_t arg = ctx.r3.u32;
    ctx.r30.u64 = 0;                              // @8824E6B8 li r30,0 (callee-visible!)
    int64_t ret = 0;
    // NOTE (cosmetic): decomp/game/game_entry_msgs.cpp's prologue PC comments are 4 bytes high
    // (it labels the stwu @8824E6A4; the image has it at 0x8824E6A0).  Addresses here are
    // re-derived from the images, not carried over.

    // @8824E6BC-E6D8 cmplwi 19 / lwzx from the inline jump table at 0x8824E6DC (nor 0x8824E6D4,
    // +0x8).  All 20 table dwords decoded from the abn image and each is exactly its
    // reco_normal value +8 — the case ORDER is unchanged, so the switch below is unchanged.
    // (The generated body performs a real lwzx read of .text here; the C does not.  Same
    // accepted residual as the MATCHED body.)
    switch (msg - 1u) {
    case 0: {                                     // ---- msg 1 CONFIG-IN @8824E72C ----
        if (arg == 0) break;                      // @8824E72C beq -> ret 0
        const uint32_t a0 = PPC_LOAD_U32(arg + 0);   // @8824E738..E75C: load arg[0..4]+arg[20]
        const uint32_t a1 = PPC_LOAD_U32(arg + 4);
        const uint32_t a2 = PPC_LOAD_U32(arg + 8);
        const uint32_t a3 = PPC_LOAD_U32(arg + 12);
        const uint32_t a4 = PPC_LOAD_U32(arg + 16);
        const uint32_t src = PPC_LOAD_U32(arg + 20); // copy-source ptr (r29)
        PPC_STORE_U32(0x887AD62Cu, a0);           // @8824E764  nor 0x887AD5CC (device/context)
        PPC_STORE_U32(0x887AD630u, a1);           // @8824E76C  nor 0x887AD5D0
        PPC_STORE_U32(0x887AD654u, a2);           // @8824E770  nor 0x887AD5F4
        PPC_STORE_U32(0x887AD56Cu, a3);           // @8824E774  nor 0x887AD50C  ⚠ COLLISION-CLASS
        PPC_STORE_U32(0x887AD580u, a4);           // @8824E778  nor 0x887AD520
        // @8824E77C-E7A4: 3 outer x 8-word inner copy loops == one contiguous ascending
        // 96-byte word copy src -> 0x885C5C10.  Loop words are byte-identical to reco_normal;
        // only the base immediate moved (addi r4,r10,23472 -> 23568 = +0x60).  Count still 96.
        for (uint32_t off = 0; off < 96; off += 4)
            PPC_STORE_U32(0x885C5C10u + off, PPC_LOAD_U32(src + off));   // nor 0x885C5BB0
        PPC_STORE_U32(0x887AD5C8u, PPC_LOAD_U32(arg + 24)); // @8824E7A8/B4  nor 0x887AD568 (hook fn)
        PPC_STORE_U32(0x887AD5CCu, PPC_LOAD_U32(arg + 28)); // @8824E7AC/B8  nor 0x887AD56C (hook ctx)
        break; }                                            //   ⚠ COLLISION-CLASS (0x56C+0x60)
    case 1: {                                     // ---- msg 2 BOOT @8824E7C4 ----
        // ★ VERBATIM STREAM MIRROR (gate lesson: two bl's observe the full register file).
        // Transcribed from out_reco_abn/ppc_recomp.32.cpp.  EXACTLY THREE immediates differ
        // from the reco_normal mirror; every other line is character-identical:
        //     addi r10,r10,12932 -> 12892     (.rdata ROM-name string, ★ROM above)
        //     addi r31,r9,-10868 -> -10772    (.data anchor, +0x60)
        //     addi r11,r9,-28776 -> -28768    (code ptr 0x88168F98 -> 0x88168FA0, +8)
        // Every r31-relative OFFSET (-988/-476/-44/-3700/+116..+136) is UNCHANGED — only the
        // anchor moved, which is why the whole block re-points with one edit.
        ctx.lr = 0x8824E7C8; sub_880923D0(ctx, base);       // @8824E7C4 (r3=arg)
        ctx.r10.s64 = SX(0x88060000u);            // lis r10,-30714
        ctx.r9.s64  = SX(0x887B0000u);            // lis r9,-30597
        ctx.r11.u64 = ctx.r30.u64;                // mr r11,r30
        ctx.r10.s64 = ctx.r10.s64 + 12892;        // -> 0x8806325C = "Rom\cg_v154hi.bin"
                                                  //    (nor: +12932 -> 0x88063284 "Rom\cg_v154.bin")
        ctx.r31.s64 = ctx.r9.s64 + -10772;        // -> 0x887AD5EC (anchor; nor 0x887AD58C)
        do {                                      // @8824E7DC strcpy loop (lbzx/stbx, incl. NUL)
            ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r10.u32);
            ctx.r8.s64 = ctx.r31.s64 + -988;      // -> 0x887AD210 (dest; re-formed each iter)
            PPC_STORE_U8(ctx.r11.u32 + ctx.r8.u32, ctx.r9.u8);
            ctx.r11.s64 = ctx.r11.s64 + 1;
        } while (ctx.r9.u32 != 0);                //   NOTE: 17 iterations here vs 15 in normal
        ctx.r3.s64 = ctx.r31.s64 + -476;          // @8824E7F8 -> 0x887AD410
        ctx.r5.s64 = 256;                         // @8824E7FC
        ctx.r4.s64 = 0;                           // @8824E800
        ctx.lr = 0x8824E804; sub_88073BD0(ctx, base);       // memset
        ctx.r11.s64 = 8;                          // li r11,8
        ctx.r10.s64 = SX(0x88010000u);            // lis r10,-30719
        PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r30.u32);      // 0x887AD668 = 0
        ctx.r7.s64 = ctx.r1.s64 + 80;             // staging ptr (callee-visible)
        PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r30.u32);      // 0x887AD670 = 0
        ctx.r10.s64 = ctx.r10.s64 + -31808;       // -> 0x880083C0 (UNCHANGED: below the split)
        PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r30.u32);      // 0x887AD674 = 0
        ctx.r9.s64 = SX(0x88170000u);             // lis r9,-30697
        ctx.ctr.u64 = ctx.r11.u64;                // mtctr 8
        PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r10.u32);      // 0x887AD660 = 0x880083C0
        ctx.r11.s64 = ctx.r9.s64 + -28768;        // -> 0x88168FA0 (nor 0x88168F98, +8; the
                                                  //    game worker fn — confirmed a .pdata
                                                  //    function start in reco_abnormal and a
                                                  //    generated body in out_reco_abn/
                                                  //    ppc_recomp.21.cpp)
        ctx.r10.u64 = ctx.r30.u64;
        PPC_STORE_U64(ctx.r7.u32 + 0, ctx.r30.u64);         // std r30,80(r1) zero staging
        ctx.r10.s64 = 1;
        PPC_STORE_U32(ctx.r31.u32 + -44, ctx.r11.u32);      // 0x887AD5C0 = 0x88168FA0
        ctx.r9.u64 = ctx.r30.u64;
        ctx.r8.s64 = ctx.r31.s64 + -3700;         // -> 0x887AC778 (nor 0x887AC718)
        PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r10.u32);      // 0x887AD66C = 1
        ctx.r7.s64 = ctx.r1.s64 + 80;
        ctx.r9.s64 = 60;
        ctx.r11.u64 = ctx.r30.u64;
        ctx.r10.s64 = ctx.r8.s64 + -1;
        PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r9.u32);       // 0x887AD664 = 60
        ctx.r11.s64 = ctx.r7.s64 + -1;
        do {                                      // @8824E864 lbzu/stbu byte copy, ctr=8
            ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1); ctx.r11.u32 += 1;
            PPC_STORE_U8(ctx.r10.u32 + 1, ctx.r9.u8); ctx.r10.u32 += 1;
            --ctx.ctr.u64;
        } while (ctx.ctr.u32 != 0);               // net effect: zero 0x887AC778..7F
        ctx.lr = 0x8824E874; sub_8808D0A8(ctx, base);       // @8824E870
        ctx.lr = 0x8824E878; sub_8808FDF8(ctx, base);       // @8824E874 events + worker spawn
        break; }
    case 2:                                       // ---- msg 3 BOOT-SHUTDOWN @8824E884 ----
        ctx.lr = 0x8824E888; sub_8808FAB8(ctx, base);       // (r3=arg)
        ctx.lr = 0x8824E88C; sub_8808FF58(ctx, base);
        ctx.lr = 0x8824E890; sub_8808D930(ctx, base);
        break;
    case 4:                                       // ---- msg 5 FRAME RENDER @8824E89C ----
        ctx.lr = 0x8824E8A0; sub_8808FA68(ctx, base);       // handshake (r3=arg)
        ctx.lr = 0x8824E8A4; sub_8808E468(ctx, base);       // per-frame draw/param block
        break;
    case 5:                                       // ---- msg 6 @8824E8B0: *arg = &0x887AD634 ----
        PPC_STORE_U32(arg + 0, 0x887AD634u);      // nor 0x887AD5D4 (unguarded, as in guest)
        break;
    case 6:                                       // ---- msg 7 @8824E8CC: *arg = &0x887AD63C ----
        PPC_STORE_U32(arg + 0, 0x887AD63Cu);      // nor 0x887AD5DC
        break;
    case 7:                                       // ---- msg 8 @8824E8E8: *arg = &0x887AD5A4 ----
        if (arg == 0) break;                      // guarded
        PPC_STORE_U32(arg + 0, 0x887AD5A4u);      // nor 0x887AD544  ⚠ COLLISION-CLASS
        break;
    case 8: {                                     // ---- msg 9 REGISTER-CBS @8824E90C ----
        if (arg == 0) break;
        const uint32_t c0 = PPC_LOAD_U32(arg + 0);   // @8824E914..E938: load all 8 first
        const uint32_t c1 = PPC_LOAD_U32(arg + 4);
        const uint32_t c2 = PPC_LOAD_U32(arg + 8);
        const uint32_t c3 = PPC_LOAD_U32(arg + 12);
        const uint32_t c4 = PPC_LOAD_U32(arg + 16);
        const uint32_t c5 = PPC_LOAD_U32(arg + 20);
        const uint32_t c6 = PPC_LOAD_U32(arg + 24);
        const uint32_t c7 = PPC_LOAD_U32(arg + 28);
        PPC_STORE_U32(0x887AD600u, c0);           // @8824E940 cb1 fn   nor 0x887AD5A0 ⚠COLLISION
        PPC_STORE_U32(0x887AD604u, c1);           // @8824E944 cb1 ctx  nor 0x887AD5A4 ⚠COLLISION
        PPC_STORE_U32(0x887AD670u, c2);           // @8824E948 cb2 fn   nor 0x887AD610
        PPC_STORE_U32(0x887AD674u, c3);           // @8824E94C cb2 ctx  nor 0x887AD614
        PPC_STORE_U32(0x887AD608u, c4);           // @8824E950 cb3 fn   nor 0x887AD5A8 ⚠COLLISION
        PPC_STORE_U32(0x887AD60Cu, c5);           // @8824E954 cb3 ctx  nor 0x887AD5AC ⚠COLLISION
        PPC_STORE_U32(0x887AD538u, c6);           // @8824E958 cb4 fn   nor 0x887AD4D8 ⚠COLLISION
        PPC_STORE_U32(0x887AD53Cu, c7);           // @8824E95C cb4 ctx  nor 0x887AD4DC
        break; }
    case 9:                                       // ---- msg 10 @8824E968 ----
        PPC_STORE_U32(0x887AD594u, PPC_LOAD_U32(arg + 0));  // nor 0x887AD534 = *arg
        PPC_STORE_U32(0x887AD598u, 0);                      // nor 0x887AD538 = 0
        break;
    case 10:                                      // ---- msg 11 @8824E988 ----
        PPC_STORE_U32(g_msg11Slot, PPC_LOAD_U32(arg + 0));  // 0x88252DD8 = *arg (NOT shifted)
        break;
    case 11:                                      // ==== PILOT msg 12 MODE64-ARM @8824E9A4 ====
        PPC_STORE_U32(g_modeSlot, 0xFFFFFFFFu);   // @8824E9C0 0x88252D58 = -1 (NOT shifted)
        PPC_STORE_U32(g_mode64,   3);             // @8824E9C8 0x887AD5E4 = 3
        PPC_STORE_U32(g_msg12Aux, 0x8000u);       // @8824E9CC 0x887AD5FC = 0x8000
        break;
    case 12:                                      // ==== PILOT msg 13 RETURN-TO-MENU @8824E9D8 ====
        PPC_STORE_U32(g_reloadReq, 1);            // @8824E9E4 0x887AD5EC = 1
        break;
    case 13:                                      // ==== PILOT msg 14 CREDIT-ARM @8824E9F0 ====
        if (PPC_LOAD_U8(g_creditGate) != 0)       // @8824E9F8 lbz 0x887AD5A7; guard fails -> ret 0
            break;
        PPC_STORE_U32(g_reloadReq, 2);            // @8824EA0C 0x887AD5EC = 2
        break;
    case 14:                                      // ---- msg 15 @8824EA18 ----
        ctx.r4.u64 = PPC_LOAD_U32(arg + 16);      // lwz r4,16(r3)
        ctx.lr = 0x8824EA20; sub_8808F1E8(ctx, base);       // (r3=arg)
        break;
    case 15:                                      // ---- msg 16 @8824EA2C ----
        ctx.r3.u64 = PPC_LOAD_U32(arg + 0);       // lwz r3,0(r3)
        ctx.lr = 0x8824EA34; sub_8808F150(ctx, base);
        break;
    case 16:                                      // ---- msg 17 MAGIC-VALIDATE @8824EA40 ----
        ctx.r4.u64 = PPC_LOAD_U32(arg + 4);
        ctx.r3.u64 = PPC_LOAD_U32(arg + 0);
        ctx.lr = 0x8824EA4C; sub_8808F098(ctx, base);
        break;
    case 17:                                      // ---- msg 18 @8824EA58 ----
        ctx.lr = 0x8824EA5C; sub_8808EFA8(ctx, base);       // (r3=arg)
        break;
    case 18: {                                    // ---- msg 19 MODE-SELECT @8824EA68 ----
        const uint32_t v = PPC_LOAD_U32(arg + 0);
        if (v < 5u || (v >= 10u && v < 15u))      // @8824EA70-EA80 range check (UNCHANGED)
            PPC_STORE_U32(g_modeSlot, v);         // @8824EA8C 0x88252D58 = v
        else
            PPC_STORE_U32(g_modeSlot, 0xFFFFFFFFu); // @8824EAA4 0x88252D58 = -1
        break; }
    case 19:                                      // ---- msg 20 DESCRIPTOR-IN @8824EAB0 ----
        ctx.r4.u64 = PPC_LOAD_U32(arg + 4);
        ctx.r3.u64 = PPC_LOAD_U32(arg + 0);
        ctx.lr = 0x8824EABC; sub_8808EEC8(ctx, base);
        break;
    default:                                      // ---- msg 0/4/>20 @8824EAC8: unimplemented ----
        ret = -1;                                 // li r30,-1 (64-bit -1, as r30/r3)
        break;
    }

    ctx.r3.s64 = ret;                             // @8824EACC mr r3,r30
    ctx.r1.u32 = entry_r1;                        // addi r1,r1,128
    ctx.r30.u64 = entry_r30;                      // __restgprlr_29: restore callee-saved regs
    ctx.r31.u64 = entry_r31;                      //   (r30 set at entry, r31 in msg2/msg9 paths)
}
