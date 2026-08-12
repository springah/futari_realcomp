// decomp/game/game_entry_msgs.cpp — C1 PILOT (HUMAN_READABLE_DECOMP_PLAN §5)
// GameEntry_Dispatch — 0x8824E698, the game module's export-ordinal-1 message receiver
// ("GameEntry(msg,arg)", 20-way switch on msg-1; ATLAS_shell_menus §4 Anchor 3, ATLAS_INDEX
// row 8824e698). Pilot slice of interest = msgs 12/13/14 (cases 0xb/0xc/0xd); the WHOLE
// function is translated because the only non-shadowing link seam is __imp__sub_8824E698
// (merged_xex.cpp already owns the strong sub_8824E698 hook = the [gemsg]/RT_MSGLOG
// instrument, which the acceptance gate itself needs alive) and first-def-wins displacement
// of __imp__ discards the generated body, so per-case delegation is impossible.
// See PILOT_NOTES.md (same dir) for seam analysis, gate recipe, and rollback.
//
// Ground truth used for every line: out_reco/ppc_recomp.32.cpp:25606-26270 (register-exact
// recomp) cross-checked against ghidra_futari_decomp/reco_normal_decomp_all.txt:304974-305151.
// Framing note: Ghidra's "iVar3 = FUN_8807115c(); switch(iVar3-1)" is an artifact — 0x8807115C
// is __savegprlr_29 millicode; the switch operand is the INCOMING r3 (msg id), r4 = arg ptr.
//
// Registry status: MATCHED (registry.toml; c1_gate.sh drive 2026-07-28 — control-vs-pilot
// 42/42 canonical-identical, raw 41/42, determinism control PASS). Gate coverage =
// msgs {1,2,5,6,7,8,9,11,15,20}; the 12/13/14 pilot slice is still attended live-fire debt
// (quit-path playtest with RT_MSGLOG armed).
// NOT ASM-EXACT, and cannot be: this is a PPC_FUNC_IMPL ctx-shaped body manipulating ctx.rNN,
// so there is no natural C++ for the XDK 9328 compiler to compare against (plan §10, and the
// two-axis table in decomp/README.md).

#include "ppc_recomp_shared.h"   // ppc_config.h + ppc_context.h + generated externs (-I out_reco)

// Callees (declarations are benign if ppc_recomp_shared.h already provides them).
// Plain sub_* symbols so calls route through the same strong-over-weak hook seam the
// generated body uses (e.g. sub_8808FDF8 has a merged_xex instrument wrapper — kept).
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

// ★ 2026-08-12 tick/present decoupling seam — ARCADE side (RT_FRAMECLOCK_VBLANK; host ABI
// helpers via tools/gen_host_abi.py, shim module_shim_reco_normal.cpp). Mirror of the abn seam
// (game_entry_msgs_abn.cpp): lever OFF => skip() returns 0 => this translation stays
// behaviorally IDENTICAL to the matched body. Lever ON => the 59.94Hz frame-clock thread
// (shell/gen/rt.cpp) owns the msg-5 frame handshake and the present path skips it here —
// closes the "arcade still welded" ship debt (ledger 08-12). grantfn: this module hands the
// host its OWN &sub_8808FA68 (same static guest address as abn, different DLL — the shell's
// rt_lookup can't resolve it). Passed as void* so the generated host ABI carries no PPC types.
extern "C" int rt_frameclock_present_skip(void* grantfn);
extern "C" void rt_frameclock_disarm(const char* why);

namespace {
// lis/addi address arithmetic sign-extends into the 64-bit register; mirror it exactly for
// every register value handed to a callee (callees address with .u32, but stay bit-true).
constexpr int64_t SX(uint32_t v) { return (int64_t)(int32_t)v; }

// Message ids (decomp-proven values; vocabulary from ATLAS_shell_menus §Anchor 3 and
// HUMAN_READABLE_DECOMP_PLAN §2 — 10/11 kept address-true, the atlas msg-10/11 rows are
// off-by-one vs the recomp, see PILOT_NOTES).
enum GameMsg : uint32_t {
    MSG_CONFIG_IN      = 1,   // arg[0..5]->DAT_887ad5cc cluster + 96-byte copy -> 0x885C5BB0
    MSG_BOOT           = 2,   // events @0x885C651C + game worker 0x88168F98 bring-up
    MSG_BOOT_SHUTDOWN  = 3,   // join + teardown
    /* 4 unimplemented -> -1 */
    MSG_FRAME_RENDER   = 5,   // handshake + per-frame draw-block build
    MSG_GETPTR_5D4     = 6,   // *arg = &0x887AD5D4
    MSG_GETPTR_5DC     = 7,   // *arg = &0x887AD5DC
    MSG_GETPTR_544     = 8,   // *arg = &0x887AD544 (guarded arg!=0)
    MSG_REGISTER_CBS   = 9,   // 4 {fn,ctx} callback pairs
    MSG_SET_887AD534   = 10,  // 0x887AD534=*arg, 0x887AD538=0
    MSG_SET_88252DD8   = 11,  // 0x88252DD8=*arg
    MSG_MODE64_ARM     = 12,  // PILOT: 0x88252D58=-1, mode64 0x887AD584=3, 0x887AD59C=0x8000
    MSG_RETURN_TO_MENU = 13,  // PILOT: reload mailbox 0x887AD58C=1
    MSG_CREDIT_ARM     = 14,  // PILOT: if 0x887AD547==0 -> 0x887AD58C=2
    MSG_COLOR_BLOCK_IN = 15, MSG_COLOR_DEFAULTS = 16, MSG_MAGIC_VALIDATE = 17,
    MSG_BLOCK2C_IN     = 18,
    MSG_MODE_SELECT    = 19,  // 0x88252D58=*arg range-checked (<5 | 10..14), else -1
    MSG_DESCRIPTOR_IN  = 20,
};

// Pilot-critical mailbox cluster (raw Ghidra aliases kept greppable, plan §2):
constexpr uint32_t g_reloadReq  = 0x887AD58Cu; // DAT_887ad58c — msg13->1 / msg14->2; consumed+
                                               //   cleared by outer FSM FUN_88138f00 (reco:126015/126020)
constexpr uint32_t g_creditGate = 0x887AD547u; // DAT_887ad547 — byte guard on msg 14
constexpr uint32_t g_mode64     = 0x887AD584u; // DAT_887ad584 — "mode64" ([q] RT_QDIAG name)
constexpr uint32_t g_msg12Aux   = 0x887AD59Cu; // DAT_887ad59c — msg-12 companion (0x8000)
constexpr uint32_t g_modeSlot   = 0x88252D58u; // DAT_88252d58 — shared config/mode slot; >=0 makes
                                               //   FUN_88138f00 call FUN_881383A0 (reco:126018-126022)
} // namespace

PPC_FUNC_IMPL(__imp__sub_8824E698) {
    PPC_FUNC_PROLOGUE();
    // @8824E698-E6A4: mflr + __savegprlr_29 + stwu r1,-128(r1). Frame emulated (back-chain
    // store + SP move) so callee frames/scratch land at the generated addresses; the
    // savegpr/lr scratch stores themselves are host-register state and not reproduced.
    // ★ C1 GATE LESSON (2026-07-28, first gate FAIL): callees CONSUME the incidental register
    // file at call boundaries (the first cut passed caller garbage in r30/r7-r11 and shifted a
    // guest allocation — 2-line sequence diff, heap pointer only). The body must mirror the
    // generated stream's register state wherever a bl can observe it: r30=0 + r11=msg at entry
    // (nonvolatiles saved/restored like __savegprlr_29/__restgprlr_29 do), and the msg2 case is
    // a VERBATIM stream mirror.
    const uint32_t entry_r1 = ctx.r1.u32;
    const uint64_t entry_r30 = ctx.r30.u64, entry_r31 = ctx.r31.u64;   // callee-saved
    PPC_STORE_U32(entry_r1 - 128, entry_r1);      // @8824E6A4 stwu back-chain
    ctx.r1.u32 = entry_r1 - 128;
    const uint32_t msg = ctx.r3.u32;              // @8824E6A8 mr r11,r3
    ctx.r11.u64 = ctx.r3.u64;                     //   (callees in call-cases see r11=msg)
    ctx.r3.u64 = ctx.r4.u64;                      // @8824E6AC mr r3,r4 — every case sees r3=arg
    const uint32_t arg = ctx.r3.u32;
    ctx.r30.u64 = 0;                              // @8824E6B4 li r30,0 (callee-visible!)
    int64_t ret = 0;

    switch (msg - 1u) {                           // @8824E6B8-E6D4 cmplwi 19 / jump table
    case 0: {                                     // ---- msg 1 CONFIG-IN @8824E724 ----
        if (arg == 0) break;                      // @8824E724 beq -> ret 0
        const uint32_t a0 = PPC_LOAD_U32(arg + 0);   // @8824E730..E754: load arg[0..4]+arg[20]
        const uint32_t a1 = PPC_LOAD_U32(arg + 4);
        const uint32_t a2 = PPC_LOAD_U32(arg + 8);
        const uint32_t a3 = PPC_LOAD_U32(arg + 12);
        const uint32_t a4 = PPC_LOAD_U32(arg + 16);
        const uint32_t src = PPC_LOAD_U32(arg + 20); // copy-source ptr (r29)
        PPC_STORE_U32(0x887AD5CCu, a0);           // @8824E75C DAT_887ad5cc (device/context, AP§1)
        PPC_STORE_U32(0x887AD5D0u, a1);           // @8824E764 DAT_887ad5d0
        PPC_STORE_U32(0x887AD5F4u, a2);           // @8824E768 DAT_887ad5f4
        PPC_STORE_U32(0x887AD50Cu, a3);           // @8824E76C DAT_887ad50c
        PPC_STORE_U32(0x887AD520u, a4);           // @8824E770 DAT_887ad520
        // @8824E774-E79C: 3 outer x 8-word inner copy loops == one contiguous ascending
        // 96-byte word copy src -> 0x885C5BB0 (DAT_885c5bb0); memory trace identical.
        for (uint32_t off = 0; off < 96; off += 4)
            PPC_STORE_U32(0x885C5BB0u + off, PPC_LOAD_U32(src + off));
        PPC_STORE_U32(0x887AD568u, PPC_LOAD_U32(arg + 24)); // @8824E7A0/B0 DAT_887ad568 (msg-1 hook fn)
        PPC_STORE_U32(0x887AD56Cu, PPC_LOAD_U32(arg + 28)); // @8824E7A4/B4 DAT_887ad56c (hook ctx)
        break; }
    case 1: {                                     // ---- msg 2 BOOT @8824E7BC ----
        // VERBATIM stream mirror (gate lesson: two bl's observe the full register file; the
        // readable-C form shifted a guest alloc). Semantics summary: sub_880923D0(arg); strcpy
        // 0x88063284->0x887AD1B0; memset(0x887AD3B0,0,256); mailbox block init (r31 anchor
        // 0x887AD58C: +116=0x880083C0 +120=60 +124/+132/+136=0 +128=1 -44=0x88168F98); zero
        // 8-byte staging @r1+80 -> byte-copy to 0x887AC718; sub_8808D0A8(); sub_8808FDF8().
        ctx.lr = 0x8824E7C0; sub_880923D0(ctx, base);       // @8824E7BC (r3=arg)
        ctx.r10.s64 = SX(0x88060000u);            // lis r10,-30714
        ctx.r9.s64  = SX(0x887B0000u);            // lis r9,-30597
        ctx.r11.u64 = ctx.r30.u64;                // mr r11,r30
        ctx.r10.s64 = ctx.r10.s64 + 12932;        // -> 0x88063284 (strcpy src)
        ctx.r31.s64 = ctx.r9.s64 + -10868;        // -> 0x887AD58C (anchor)
        do {                                      // @8824E7D4 strcpy loop (lbzx/stbx, incl. NUL)
            ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r10.u32);
            ctx.r8.s64 = ctx.r31.s64 + -988;      // -> 0x887AD1B0 (dest, re-formed each iter)
            PPC_STORE_U8(ctx.r11.u32 + ctx.r8.u32, ctx.r9.u8);
            ctx.r11.s64 = ctx.r11.s64 + 1;
        } while (ctx.r9.u32 != 0);
        ctx.r3.s64 = ctx.r31.s64 + -476;          // @8824E7F0 -> 0x887AD3B0
        ctx.r5.s64 = 256;                         // @8824E7F4
        ctx.r4.s64 = 0;                           // @8824E7F8
        ctx.lr = 0x8824E7FC; sub_88073BD0(ctx, base);       // memset
        ctx.r11.s64 = 8;                          // li r11,8
        ctx.r10.s64 = SX(0x88010000u);            // lis r10,-30719
        PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r30.u32);      // 0x887AD608 = 0
        ctx.r7.s64 = ctx.r1.s64 + 80;             // staging ptr (callee-visible)
        PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r30.u32);      // 0x887AD610 = 0
        ctx.r10.s64 = ctx.r10.s64 + -31808;       // -> 0x880083C0
        PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r30.u32);      // 0x887AD614 = 0
        ctx.r9.s64 = SX(0x88170000u);             // lis r9,-30697
        ctx.ctr.u64 = ctx.r11.u64;                // mtctr 8
        PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r10.u32);      // 0x887AD600 = 0x880083C0
        ctx.r11.s64 = ctx.r9.s64 + -28776;        // -> 0x88168F98
        ctx.r10.u64 = ctx.r30.u64;
        PPC_STORE_U64(ctx.r7.u32 + 0, ctx.r30.u64);         // std r30,80(r1) zero staging
        ctx.r10.s64 = 1;
        PPC_STORE_U32(ctx.r31.u32 + -44, ctx.r11.u32);      // 0x887AD560 = 0x88168F98
        ctx.r9.u64 = ctx.r30.u64;
        ctx.r8.s64 = ctx.r31.s64 + -3700;         // -> 0x887AC718
        PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r10.u32);      // 0x887AD60C = 1
        ctx.r7.s64 = ctx.r1.s64 + 80;
        ctx.r9.s64 = 60;
        ctx.r11.u64 = ctx.r30.u64;
        ctx.r10.s64 = ctx.r8.s64 + -1;
        PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r9.u32);       // 0x887AD604 = 60
        ctx.r11.s64 = ctx.r7.s64 + -1;
        do {                                      // @8824E85C lbzu/stbu byte copy, ctr=8
            ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1); ctx.r11.u32 += 1;
            PPC_STORE_U8(ctx.r10.u32 + 1, ctx.r9.u8); ctx.r10.u32 += 1;
            --ctx.ctr.u64;
        } while (ctx.ctr.u32 != 0);
        ctx.lr = 0x8824E86C; sub_8808D0A8(ctx, base);       // @8824E868
        ctx.lr = 0x8824E870; sub_8808FDF8(ctx, base);       // @8824E86C events + worker spawn
        break; }
    case 2:                                       // ---- msg 3 BOOT-SHUTDOWN @8824E87C ----
        rt_frameclock_disarm("msg3 teardown (arcade)"); // ★ 08-12: frame-clock thread must never
                                                  //   block on a dying module's ack (no-op off)
        ctx.lr = 0x8824E880; sub_8808FAB8(ctx, base);       // (r3=arg)
        ctx.lr = 0x8824E884; sub_8808FF58(ctx, base);
        ctx.lr = 0x8824E888; sub_8808D930(ctx, base);
        break;
    case 4:                                       // ---- msg 5 FRAME RENDER @8824E894 ----
        // ★ 08-12 decoupling seam (arcade): with RT_FRAMECLOCK_VBLANK armed, the 59.94Hz
        // frame-clock thread performs the handshake (shell/gen/rt.cpp) and the present path
        // skips it — the render build below stays HERE at present rate. Lever off => skip()
        // returns 0 => matched behavior, byte-identical flow.
        if (!rt_frameclock_present_skip((void*)&sub_8808FA68)) {
            ctx.lr = 0x8824E898; sub_8808FA68(ctx, base);   // handshake (FA68 ignores incoming r3)
        }
        ctx.lr = 0x8824E89C; sub_8808E468(ctx, base);       // per-frame draw/param block
        break;
    case 5:                                       // ---- msg 6 @8824E8A8: *arg = &DAT_887ad5d4 ----
        PPC_STORE_U32(arg + 0, 0x887AD5D4u);      // (unguarded, as in guest)
        break;
    case 6:                                       // ---- msg 7 @8824E8C4: *arg = &DAT_887ad5dc ----
        PPC_STORE_U32(arg + 0, 0x887AD5DCu);
        break;
    case 7:                                       // ---- msg 8 @8824E8E0: *arg = &DAT_887ad544 ----
        if (arg == 0) break;                      // guarded
        PPC_STORE_U32(arg + 0, 0x887AD544u);
        break;
    case 8: {                                     // ---- msg 9 REGISTER-CBS @8824E904 ----
        if (arg == 0) break;
        const uint32_t c0 = PPC_LOAD_U32(arg + 0);   // @8824E90C..E92C: load all 8 first
        const uint32_t c1 = PPC_LOAD_U32(arg + 4);
        const uint32_t c2 = PPC_LOAD_U32(arg + 8);
        const uint32_t c3 = PPC_LOAD_U32(arg + 12);
        const uint32_t c4 = PPC_LOAD_U32(arg + 16);
        const uint32_t c5 = PPC_LOAD_U32(arg + 20);
        const uint32_t c6 = PPC_LOAD_U32(arg + 24);
        const uint32_t c7 = PPC_LOAD_U32(arg + 28);
        PPC_STORE_U32(0x887AD5A0u, c0);           // cb1 fn   DAT_887ad5a0
        PPC_STORE_U32(0x887AD5A4u, c1);           // cb1 ctx  DAT_887ad5a4
        PPC_STORE_U32(0x887AD610u, c2);           // cb2 fn   DAT_887ad610
        PPC_STORE_U32(0x887AD614u, c3);           // cb2 ctx  DAT_887ad614
        PPC_STORE_U32(0x887AD5A8u, c4);           // cb3 fn   DAT_887ad5a8
        PPC_STORE_U32(0x887AD5ACu, c5);           // cb3 ctx  DAT_887ad5ac
        PPC_STORE_U32(0x887AD4D8u, c6);           // cb4 fn   DAT_887ad4d8
        PPC_STORE_U32(0x887AD4DCu, c7);           // cb4 ctx  DAT_887ad4dc
        break; }
    case 9:                                       // ---- msg 10 @8824E960 ----
        PPC_STORE_U32(0x887AD534u, PPC_LOAD_U32(arg + 0));  // DAT_887ad534 = *arg
        PPC_STORE_U32(0x887AD538u, 0);                      // DAT_887ad538 = 0
        break;
    case 10:                                      // ---- msg 11 @8824E980 ----
        PPC_STORE_U32(0x88252DD8u, PPC_LOAD_U32(arg + 0));  // DAT_88252dd8 = *arg
        break;
    case 11:                                      // ==== PILOT msg 12 MODE64-ARM @8824E99C ====
        PPC_STORE_U32(g_modeSlot, 0xFFFFFFFFu);   // @8824E9B4 DAT_88252d58 = -1
        PPC_STORE_U32(g_mode64,   3);             // @8824E9BC DAT_887ad584 = 3
        PPC_STORE_U32(g_msg12Aux, 0x8000u);       // @8824E9C0 DAT_887ad59c = 0x8000
        break;
    case 12:                                      // ==== PILOT msg 13 RETURN-TO-MENU @8824E9D0 ====
        PPC_STORE_U32(g_reloadReq, 1);            // @8824E9DC DAT_887ad58c = 1
        break;
    case 13:                                      // ==== PILOT msg 14 CREDIT-ARM @8824E9E8 ====
        if (PPC_LOAD_U8(g_creditGate) != 0)       // @8824E9F0 lbz DAT_887ad547; guard fails -> ret 0
            break;
        PPC_STORE_U32(g_reloadReq, 2);            // @8824EA04 DAT_887ad58c = 2
        break;
    case 14:                                      // ---- msg 15 @8824EA10 ----
        ctx.r4.u64 = PPC_LOAD_U32(arg + 16);      // lwz r4,16(r3)
        ctx.lr = 0x8824EA18; sub_8808F1E8(ctx, base);       // (r3=arg)
        break;
    case 15:                                      // ---- msg 16 @8824EA24 ----
        ctx.r3.u64 = PPC_LOAD_U32(arg + 0);       // lwz r3,0(r3)
        ctx.lr = 0x8824EA2C; sub_8808F150(ctx, base);
        break;
    case 16:                                      // ---- msg 17 MAGIC-VALIDATE @8824EA38 ----
        ctx.r4.u64 = PPC_LOAD_U32(arg + 4);
        ctx.r3.u64 = PPC_LOAD_U32(arg + 0);
        ctx.lr = 0x8824EA44; sub_8808F098(ctx, base);
        break;
    case 17:                                      // ---- msg 18 @8824EA50 ----
        ctx.lr = 0x8824EA54; sub_8808EFA8(ctx, base);       // (r3=arg)
        break;
    case 18: {                                    // ---- msg 19 MODE-SELECT @8824EA60 ----
        const uint32_t v = PPC_LOAD_U32(arg + 0);
        if (v < 5u || (v >= 10u && v < 15u))      // @8824EA68-EA78 range check
            PPC_STORE_U32(g_modeSlot, v);         // @8824EA84 DAT_88252d58 = v
        else
            PPC_STORE_U32(g_modeSlot, 0xFFFFFFFFu); // @8824EA98 DAT_88252d58 = -1
        break; }
    case 19:                                      // ---- msg 20 DESCRIPTOR-IN @8824EAA8 ----
        ctx.r4.u64 = PPC_LOAD_U32(arg + 4);
        ctx.r3.u64 = PPC_LOAD_U32(arg + 0);
        ctx.lr = 0x8824EAB4; sub_8808EEC8(ctx, base);
        break;
    default:                                      // ---- msg 0/4/>20 @8824EAC0: unimplemented ----
        ret = -1;                                 // li r30,-1 (64-bit -1, as r30/r3)
        break;
    }

    ctx.r3.s64 = ret;                             // @8824EAC4 mr r3,r30
    ctx.r1.u32 = entry_r1;                        // addi r1,r1,128
    ctx.r30.u64 = entry_r30;                      // __restgprlr_29: restore callee-saved regs
    ctx.r31.u64 = entry_r31;                      //   (r30 set at entry, r31 in msg2/msg9 paths)
}
