// decomp/shell/driver_msgs.inl — the TWELVE shapes of the GameDriverTask command surface.
//
// This file is the whole point of the D1 leg: HUMAN_READABLE_DECOMP_PLAN §4 rank 5 says the
// shell driver's "8 near-identical clones collapse into one template + msg-id table — the
// largest LOC reduction per effort in the project". They do, and it is now MEASURED rather
// than asserted: extracting every generated body from shell/gen/ppc_recomp.*.cpp and comparing
// them with address literals normalised away gives exactly EIGHT byte-identical clones of each
// shape below, no more and no less (the check is reproducible — see driver_msgs.cpp's table,
// every listed clone was produced by that scan, not by hand).
//
// Each shape is written ONCE here, register-faithful, and instantiated per clone in
// driver_msgs.cpp. The only thing that differs between clones is the guest address, which is
// why every shape takes its entry address and derives the return addresses it must publish
// from a FIXED offset — verified identical across all 8 clones of every shape.
//
// Ground truth: shell/gen/ppc_recomp.34.cpp / .35.cpp (register-exact recomp) cross-checked
// against reference/ghidra_futari_decomp/asm_msgwrap_0727.txt (raw disassembly),
// force_fnf11_wrappers.txt, orch2.txt, allgap.txt (Ghidra pseudo-C) and the vtable dump
// vt_gdtask_0727.txt. Recomp and Ghidra agree everywhere; no dropped-instruction suspects.
//
// REGISTER-FILE DISCIPLINE (the C1 gate lesson): every shape that reaches GameEntry mirrors the
// generated instruction stream verbatim at the call boundary — guest-stack frame (back-chain
// store, SP move, staging stores at their exact offsets), r3/r4/r5, the scratch the loads leave
// behind (r9/r10/r11/r12/r30/r31), ctr, and ctx.lr (exact generated return address before a
// bctrl; UNTOUCHED before a bctr, where the callee returns straight to OUR caller). The two
// predicates are leaves — no call boundary — so they are natural C and their volatile leftovers
// are deliberately not reproduced (the decomp/shell/task_kill.cpp precedent, same reasoning).

// ---- GameDriverTask field offsets (ATLAS_shell_menus §3, ctor FUN_821C57B8) -----------------
constexpr uint32_t kDrvLaunchState = 120;  // +0x78 launch state (0 / 1 / 2 / 3 / 4 / 5)
constexpr uint32_t kDrvStageWord   = 124;  // +0x7C zeroed alongside launchState by shape K
constexpr uint32_t kDrvSlotA       = 76;   // +0x4C value the init driver hands out via msg 6
constexpr uint32_t kDrvSlotB       = 80;   // +0x50 value the init driver hands out via msg 7
constexpr uint32_t kDrvExParam1    = 140;  // +0x8C mode-arm EXTENDED param (shape I, from r5)
constexpr uint32_t kDrvExParam2    = 144;  // +0x90 mode-arm EXTENDED param (shape I, from r6)
constexpr uint32_t kDrvRankLevel   = 148;  // +0x94 rank / level
constexpr uint32_t kDrvModeArg     = 152;  // +0x98 mode arg
constexpr uint32_t kDrvBootArg     = 164;  // +0xA4 the word the init driver sends as msg 2 (BOOT)
constexpr uint32_t kDrvModeIndex   = 168;  // +0xA8 per-mode index (× 720 = config-table stride)
constexpr uint32_t kDrvStateBlock  = 180;  // +0xB4 → game-side status block (msg 8 gave 0x887AD544)
constexpr uint32_t kDrvCfgWord     = 192;  // +0xC0 second word the msg-20 descriptor carries
constexpr uint32_t kDrvGameEntry   = 252;  // +0xFC → GameEntry proc ptr (XexGetProcAddr ord 1)
constexpr uint32_t kDrvToggle      = 116;  // +0x74 index/toggle shape K uses to pick array slots
constexpr uint32_t kDrvField88     = 136;  // +0x88 cleared by shape K before the rank/level call

// ---- The game-side status block bytes the predicates test (offsets INTO driver+0xB4) --------
constexpr uint32_t kStPhase = 4;  // 0x887AD548 — both predicates require == 5
constexpr uint32_t kStSub   = 6;  // 0x887AD54A — sub-state: 4 or 1
constexpr uint32_t kStGate  = 3;  // 0x887AD547 — the byte msg 14 CREDIT-ARM uses as its guard

// ---- Messages sent from here (ids proven in decomp/game/game_entry_msgs.cpp) -----------------
enum GameMsg : uint32_t {
    MSG_CONFIG_IN      =  1,  // GameEntry case  0: CONFIG-IN (the init driver's big config struct)
    MSG_BOOT           =  2,  // GameEntry case  1: BOOT (driver+0xA4 passed straight through)
    MSG_GET_PTR_D5D4   =  6,  // GameEntry case  5: *arg = &0x887AD5D4 (init back-links driver+0x4C)
    MSG_GET_PTR_D5DC   =  7,  // GameEntry case  6: *arg = &0x887AD5DC (init back-links driver+0x50)
    MSG_STATE_BLOCK    =  8,  // GameEntry case  7: *arg = &0x887AD544 (fills driver+0xB4, guarded)
    MSG_REGISTER_CBS   =  9,  // GameEntry case  8: register 4 (fn,ctx) callback pairs
    MSG_MODE_ARM       = 10,  // GameEntry case  9: 0x887AD534 = arg[0], 0x887AD538 = 0
    MSG_RANK_LEVEL     = 11,  // GameEntry case 10: 0x88252DD8 = arg[0]
    MSG_MODE64_ARM     = 12,  // GameEntry case 11: 0x88252D58=-1, mode64=3, 0x887AD59C=0x8000
    MSG_RETURN_TO_MENU = 13,  // GameEntry case 12: reload mailbox 0x887AD58C = 1
    MSG_CONFIG_BLOCK   = 15,  // GameEntry case 14: sub_8808F1E8(arg) with r4 = arg[16]
    MSG_COLOR_DEFAULTS = 16,  // GameEntry case 15: sub_8808F150(arg[0])
    MSG_MAGIC_VALIDATE = 17,  // GameEntry case 16: sub_8808F098(arg[0], arg[1])
    MSG_BLOCK2C_IN     = 18,  // GameEntry case 17: sub_8808EFA8(arg)
    MSG_MODE_SELECT    = 19,  // GameEntry case 18: 0x88252D58 = arg[0] (range-checked)
    MSG_DESCRIPTOR_IN  = 20,  // GameEntry case 19: DESCRIPTOR-IN (per-mode config pointer + word)
};

// The block copier the msg-15 shapes and the init driver call is sub_8207DAC0(dst, src, len),
// and the init driver also calls the pre-init helper sub_821C64E8(); both are declared at global
// scope in driver_msgs.cpp (a PPC_EXTERN_FUNC inside this namespace would declare a
// namespace-local symbol and never link to the generated body).

// ═════════════════════════════════════════════════════════════════════════════════════════════
// SHAPE A — vt+0x44 / vt+0x38: the two game-state predicates. Leaves, 13 / 10 instructions.
//   return st[4] == 5 && st[6] == wantSub && (!wantGateClear || st[3] == 0);
// ═════════════════════════════════════════════════════════════════════════════════════════════
inline void Driver_IsPhase5Sub(PPCContext& ctx, uint8_t* base, uint32_t wantSub, bool wantGateClear)
{
    const uint32_t st = PPC_LOAD_U32(ctx.r3.u32 + kDrvStateBlock);   // lwz r11,180(r3)
    bool yes = PPC_LOAD_U8(st + kStPhase) == 5 &&                    // lbz/cmplwi 5/bne
               PPC_LOAD_U8(st + kStSub)   == wantSub;                // lbz/cmplwi 4|1/bne
    if (yes && wantGateClear)
        yes = PPC_LOAD_U8(st + kStGate) == 0;                        // lbz/cmplwi 0/beqlr
    ctx.r3.s64 = yes ? 1 : 0;                                        // li r3,1 / li r3,0
}

// ═════════════════════════════════════════════════════════════════════════════════════════════
// SHAPE B — vt+0x40 / vt+0x3C / vt+0x2C: TAIL sends. 5 or 4 instructions, no frame at all.
// `bctr` (not bctrl): GameEntry returns straight to our caller, so ctx.lr must stay untouched.
// zeroArg=true clears r4 (msgs 12/13 take no argument); msg 18 passes the caller's r4 through.
// ═════════════════════════════════════════════════════════════════════════════════════════════
inline void Driver_SendTail(PPCContext& ctx, uint8_t* base, uint32_t msg, bool zeroArg)
{
    ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + kDrvGameEntry);  // lwz r11,252(r3)  (boundary-visible)
    if (zeroArg) ctx.r4.s64 = 0;                             // li r4,0
    ctx.r3.s64  = msg;                                       // li r3,<msg>
    ctx.ctr.u64 = ctx.r11.u64;                               // mtctr r11
    PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);                     // bctr — lr deliberately untouched
}

// ═════════════════════════════════════════════════════════════════════════════════════════════
// SHAPE C — vt+0x24 (msg 16) / vt+0x4C (msg 19): send ONE word by pointer. 13 instructions.
// The caller passes the value in r4; GameEntry reads arg[0], so the word is staged on the guest
// stack and its address is passed. Frame -96; the staging slot at new r1+124 == old r1+28 (the
// caller's outgoing-parameter area) and the LR save at old r1-8 are both callee-visible memory,
// so both stores are reproduced exactly. Published return address = entry + 0x24.
// ═════════════════════════════════════════════════════════════════════════════════════════════
inline void Driver_SendWord(PPCContext& ctx, uint8_t* base, uint32_t msg, uint32_t entry)
{
    ctx.r12.u64 = ctx.lr;                                    // mflr r12
    PPC_STORE_U32(ctx.r1.u32 - 8, ctx.r12.u32);              // stw r12,-8(r1)
    const uint32_t frame = ctx.r1.u32 - 96;                  // stwu r1,-96(r1)
    PPC_STORE_U32(frame, ctx.r1.u32);
    ctx.r1.u32 = frame;
    PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);             // stw r4,124(r1) — stage the value
    ctx.r4.s64  = ctx.r1.s64 + 124;                          // addi r4,r1,124 — arg = &value
    ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + kDrvGameEntry);  // lwz r11,252(r3)
    ctx.r3.s64  = msg;                                       // li r3,<msg>
    ctx.ctr.u64 = ctx.r11.u64;                               // mtctr r11
    ctx.lr = entry + 0x24;                                   // bctrl
    PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
    ctx.r1.s64  = ctx.r1.s64 + 96;                           // addi r1,r1,96
    ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 - 8);              // lwz r12,-8(r1)
    ctx.lr      = ctx.r12.u64;                               // mtlr r12
}

// ═════════════════════════════════════════════════════════════════════════════════════════════
// SHAPE D — vt+0x28 (msg 17 MAGIC-VALIDATE): a QUERY. 18 instructions.
// Stages a two-word argument block {value, &out} plus a zeroed out-slot, sends, and returns the
// word the game wrote through the out-pointer (GameEntry case 16 → sub_8808F098(arg[0],arg[1])).
// Frame -112:  out-slot @ r1+80 (= old r1 - 32), arg block @ r1+88 (= old r1 - 24).
// Published return address = entry + 0x34.
// ═════════════════════════════════════════════════════════════════════════════════════════════
inline void Driver_QueryWord(PPCContext& ctx, uint8_t* base, uint32_t msg, uint32_t entry)
{
    ctx.r12.u64 = ctx.lr;                                    // mflr r12
    PPC_STORE_U32(ctx.r1.u32 - 8, ctx.r12.u32);              // stw r12,-8(r1)
    const uint32_t frame = ctx.r1.u32 - 112;                 // stwu r1,-112(r1)
    PPC_STORE_U32(frame, ctx.r1.u32);
    ctx.r1.u32 = frame;
    ctx.r11.s64 = 0;                                         // li r11,0
    PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);              // stw r4,88(r1)  — arg[0] = value
    ctx.r10.s64 = ctx.r1.s64 + 80;                           // addi r10,r1,80 — &out-slot
    ctx.r9.u64  = PPC_LOAD_U32(ctx.r3.u32 + kDrvGameEntry);  // lwz r9,252(r3)
    PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);             // stw r11,80(r1) — out-slot = 0
    ctx.r4.s64  = ctx.r1.s64 + 88;                           // addi r4,r1,88  — arg = &block
    PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);             // stw r10,92(r1) — arg[1] = &out
    ctx.r3.s64  = msg;                                       // li r3,17
    ctx.ctr.u64 = ctx.r9.u64;                                // mtctr r9
    ctx.lr = entry + 0x34;                                   // bctrl
    PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
    ctx.r3.u64  = PPC_LOAD_U32(ctx.r1.u32 + 80);             // lwz r3,80(r1)  — the answer
    ctx.r1.s64  = ctx.r1.s64 + 112;                          // addi r1,r1,112
    ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 - 8);              // lwz r12,-8(r1)
    ctx.lr      = ctx.r12.u64;                               // mtlr r12
}

// ═════════════════════════════════════════════════════════════════════════════════════════════
// SHAPE E — vt+0x1C (msg 10 MODE-ARM, simple). 20 instructions.
// Records the launch on the driver object and then sends the arg by pointer:
//     driver->launchState = (arg == 0) ? 0 : 5;   driver->modeArg = arg;   GameEntry(10, &arg);
// The unconditional `stw r11,120(r3)` of 0 followed by the conditional `stw r11,120(r3)` of 5
// is kept as TWO stores — that is the memory trace the original produces.
// Published return address = entry + 0x40.
// ═════════════════════════════════════════════════════════════════════════════════════════════
inline void Driver_ArmMode(PPCContext& ctx, uint8_t* base, uint32_t entry)
{
    ctx.r12.u64 = ctx.lr;                                    // mflr r12
    PPC_STORE_U32(ctx.r1.u32 - 8, ctx.r12.u32);              // stw r12,-8(r1)
    const uint32_t frame = ctx.r1.u32 - 96;                  // stwu r1,-96(r1)
    PPC_STORE_U32(frame, ctx.r1.u32);
    ctx.r1.u32 = frame;
    ctx.r11.s64 = 0;                                         // li r11,0
    PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);             // stw r4,124(r1) — stage the arg
    const bool argIsZero = (ctx.r4.s32 == 0);                // cmpwi cr6,r4,0 (SIGNED)
    PPC_STORE_U32(ctx.r3.u32 + kDrvLaunchState, ctx.r11.u32);// stw r11,120(r3) — state = 0
    if (!argIsZero) {
        ctx.r11.s64 = 5;                                     // li r11,5
        PPC_STORE_U32(ctx.r3.u32 + kDrvLaunchState, ctx.r11.u32); // stw r11,120(r3) — state = 5
    }
    PPC_STORE_U32(ctx.r3.u32 + kDrvModeArg, ctx.r4.u32);     // stw r4,152(r3)  — driver->modeArg
    ctx.r4.s64  = ctx.r1.s64 + 124;                          // addi r4,r1,124  — arg = &staged
    ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + kDrvGameEntry);  // lwz r11,252(r3)
    ctx.r3.s64  = MSG_MODE_ARM;                              // li r3,10
    ctx.ctr.u64 = ctx.r11.u64;                               // mtctr r11
    ctx.lr = entry + 0x40;                                   // bctrl
    PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
    ctx.r1.s64  = ctx.r1.s64 + 96;                           // addi r1,r1,96
    ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 - 8);              // lwz r12,-8(r1)
    ctx.lr      = ctx.r12.u64;                               // mtlr r12
}

// ═════════════════════════════════════════════════════════════════════════════════════════════
// SHAPE F — vt+0x50 (msg 11 RANK/LEVEL). 27 instructions.
// Clamp the level to 0..8 (anything outside becomes the neutral 4), record it on the driver,
// then send the SIGNED RANK MASK the game wants: level < 4 → -1 << (4-level),
// level >= 4 → 1 << (level-4). ATLAS_shell_menus calls this "param 0..8 → signed mask (-4..+4)".
// The shift is reproduced through the recomp's exact slw expression (PPC masks the shift count
// and yields 0 when bit 0x20 is set) rather than a C `<<`, which would be UB-shaped here.
// Published return address = entry + 0x5C.
// ═════════════════════════════════════════════════════════════════════════════════════════════
inline void Driver_SetRankLevel(PPCContext& ctx, uint8_t* base, uint32_t entry)
{
    ctx.r12.u64 = ctx.lr;                                    // mflr r12
    PPC_STORE_U32(ctx.r1.u32 - 8, ctx.r12.u32);              // stw r12,-8(r1)
    const uint32_t frame = ctx.r1.u32 - 96;                  // stwu r1,-96(r1)
    PPC_STORE_U32(frame, ctx.r1.u32);
    ctx.r1.u32 = frame;
    if (ctx.r4.s32 < 0 || ctx.r4.s32 > 8)                    // cmpwi 0/blt + cmpwi 8/ble
        ctx.r4.s64 = 4;                                      // li r4,4 — out of range → neutral
    PPC_STORE_U32(ctx.r3.u32 + kDrvRankLevel, ctx.r4.u32);   // stw r4,148(r3)
    if (ctx.r4.s32 < 4) {                                    // cmpwi cr6,r4,4 / bge
        ctx.xer.ca  = ctx.r4.u32 <= 4;                       // subfic r11,r4,4 (carry out mirrored)
        ctx.r11.s64 = 4 - ctx.r4.s64;                        //   shift  = 4 - level
        ctx.r10.s64 = -1;                                    // li r10,-1  — negative rank
    } else {
        ctx.r11.s64 = ctx.r4.s64 + -4;                       // addi r11,r4,-4 — shift = level - 4
        ctx.r10.s64 = 1;                                     // li r10,1   — positive rank
    }
    ctx.r9.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r11.u8 & 0x3F));  // slw r9,r10,r11
    ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + kDrvGameEntry);  // lwz r11,252(r3)
    PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);              // stw r9,80(r1) — stage the mask
    ctx.r4.s64  = ctx.r1.s64 + 80;                           // addi r4,r1,80
    ctx.r3.s64  = MSG_RANK_LEVEL;                            // li r3,11
    ctx.ctr.u64 = ctx.r11.u64;                               // mtctr r11
    ctx.lr = entry + 0x5C;                                   // bctrl
    PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
    ctx.r1.s64  = ctx.r1.s64 + 96;                           // addi r1,r1,96
    ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 - 8);              // lwz r12,-8(r1)
    ctx.lr      = ctx.r12.u64;                               // mtlr r12
}

// ═════════════════════════════════════════════════════════════════════════════════════════════
// SHAPE G — vt+0x20 (msg 15 CONFIG BLOCK from the caller). 22 instructions.
// Builds the 20-byte msg-15 argument on the guest stack: 16 bytes copied from the caller's
// pointer (r4) via sub_8207DAC0, then the caller's r5 appended as the fifth word — which is
// exactly the word GameEntry case 14 re-reads as arg[16] before calling sub_8808F1E8.
// r30/r31 are saved to the frame and used across the copy call, mirroring the original.
// Published return addresses = entry + 0x28 (the copy) and entry + 0x40 (the send).
// ═════════════════════════════════════════════════════════════════════════════════════════════
inline void Driver_SendConfigBlockFromArg(PPCContext& ctx, uint8_t* base, uint32_t entry)
{
    ctx.r12.u64 = ctx.lr;                                    // mflr r12
    PPC_STORE_U32(ctx.r1.u32 - 8,  ctx.r12.u32);             // stw r12,-8(r1)
    PPC_STORE_U64(ctx.r1.u32 - 24, ctx.r30.u64);             // std r30,-24(r1)
    PPC_STORE_U64(ctx.r1.u32 - 16, ctx.r31.u64);             // std r31,-16(r1)
    const uint32_t frame = ctx.r1.u32 - 128;                 // stwu r1,-128(r1)
    PPC_STORE_U32(frame, ctx.r1.u32);
    ctx.r1.u32 = frame;
    ctx.r31.u64 = ctx.r3.u64;                                // mr r31,r3 — keep the driver
    ctx.r30.u64 = ctx.r5.u64;                                // mr r30,r5 — keep the 5th word
    ctx.r3.s64  = ctx.r1.s64 + 80;                           // addi r3,r1,80 — dst
    ctx.r5.s64  = 16;                                        // li r5,16      — len (src = r4)
    ctx.lr = entry + 0x28; sub_8207DAC0(ctx, base);          // bl 0x8207dac0 — copy 16 bytes
    PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r30.u32);             // stw r30,96(r1) — block[16] = r5
    ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + kDrvGameEntry); // lwz r11,252(r31)
    ctx.r4.s64  = ctx.r1.s64 + 80;                           // addi r4,r1,80 — arg = &block
    ctx.r3.s64  = MSG_CONFIG_BLOCK;                          // li r3,15
    ctx.ctr.u64 = ctx.r11.u64;                               // mtctr r11
    ctx.lr = entry + 0x40;                                   // bctrl
    PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
    ctx.r1.s64  = ctx.r1.s64 + 128;                          // addi r1,r1,128
    ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 - 8);              // lwz r12,-8(r1)
    ctx.lr      = ctx.r12.u64;                               // mtlr r12
    ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 - 24);             // ld r30,-24(r1)
    ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 - 16);             // ld r31,-16(r1)
}

// ═════════════════════════════════════════════════════════════════════════════════════════════
// SHAPE H — vt+0x30 (msg 15 CONFIG BLOCK from the per-mode config). 23 instructions.
// Same 20-byte msg-15 block as shape G, but the 16 bytes come from the per-mode config root
// (**DAT_821F858C → [0]) and the fifth word is the literal -1 instead of a caller parameter.
// ATLAS_shell_menus calls this "region/config 0x10-byte block from *DAT_821f858c".
// Published return addresses = entry + 0x2C (the copy) and entry + 0x48 (the send).
// ═════════════════════════════════════════════════════════════════════════════════════════════
inline void Driver_SendConfigBlockFromRegion(PPCContext& ctx, uint8_t* base, uint32_t entry)
{
    ctx.r12.u64 = ctx.lr;                                    // mflr r12
    PPC_STORE_U32(ctx.r1.u32 - 8,  ctx.r12.u32);             // stw r12,-8(r1)
    PPC_STORE_U64(ctx.r1.u32 - 16, ctx.r31.u64);             // std r31,-16(r1)
    const uint32_t frame = ctx.r1.u32 - 128;                 // stwu r1,-128(r1)
    PPC_STORE_U32(frame, ctx.r1.u32);
    ctx.r1.u32 = frame;
    ctx.r11.s64 = (int64_t)(int32_t)0x82200000;              // lis r11,-32224
    ctx.r31.u64 = ctx.r3.u64;                                // mr r31,r3 — keep the driver
    ctx.r3.s64  = ctx.r1.s64 + 80;                           // addi r3,r1,80 — dst
    ctx.r5.s64  = 16;                                        // li r5,16      — len
    ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 - 31348);         // lwz r11,-31348(r11) → [0x821F858C]
    ctx.r4.u64  = PPC_LOAD_U32(ctx.r11.u32 + 0);             // lwz r4,0(r11)       — src
    ctx.lr = entry + 0x2C; sub_8207DAC0(ctx, base);          // bl 0x8207dac0 — copy 16 bytes
    ctx.r10.s64 = -1;                                        // li r10,-1
    ctx.r9.u64  = PPC_LOAD_U32(ctx.r31.u32 + kDrvGameEntry); // lwz r9,252(r31)
    ctx.r4.s64  = ctx.r1.s64 + 80;                           // addi r4,r1,80 — arg = &block
    PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);             // stw r10,96(r1) — block[16] = -1
    ctx.r3.s64  = MSG_CONFIG_BLOCK;                          // li r3,15
    ctx.ctr.u64 = ctx.r9.u64;                                // mtctr r9
    ctx.lr = entry + 0x48;                                   // bctrl
    PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
    ctx.r1.s64  = ctx.r1.s64 + 128;                          // addi r1,r1,128
    ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 - 8);              // lwz r12,-8(r1)
    ctx.lr      = ctx.r12.u64;                               // mtlr r12
    ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 - 16);             // ld r31,-16(r1)
}

// ═════════════════════════════════════════════════════════════════════════════════════════════
// SHAPE I — vt+0x14 (msg 10 MODE-ARM, EXTENDED). 25 instructions.
// The extended sibling of shape E: it takes TWO extra caller parameters (r5, r6) and records them
// on the driver, and the armed launchState is 1 rather than 5 (this is the training-stage / boss
// candidate arm — ATLAS census row for 0x821C2D00). Layout:
//     driver->exParam1 = (arg?r5:0);  driver->exParam2 = (arg?r6:0);
//     driver->launchState = (arg==0)?0:1;  driver->modeArg = arg;  GameEntry(10, &arg);
// The unconditional stw of 0 to launchState followed by the conditional stw of 1 is kept as TWO
// stores — the memory trace the original produces. Published return address = entry + 0x54.
// ═════════════════════════════════════════════════════════════════════════════════════════════
inline void Driver_ArmModeExt(PPCContext& ctx, uint8_t* base, uint32_t entry)
{
    ctx.r12.u64 = ctx.lr;                                    // mflr r12
    PPC_STORE_U32(ctx.r1.u32 - 8, ctx.r12.u32);              // stw r12,-8(r1)
    const uint32_t frame = ctx.r1.u32 - 96;                  // stwu r1,-96(r1)
    PPC_STORE_U32(frame, ctx.r1.u32);
    ctx.r1.u32 = frame;
    ctx.r11.s64 = 0;                                         // li r11,0
    PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);             // stw r4,124(r1) — stage the arg
    const bool argIsZero = (ctx.r4.s32 == 0);                // cmpwi cr6,r4,0 (SIGNED)
    PPC_STORE_U32(ctx.r3.u32 + kDrvLaunchState, ctx.r11.u32);// stw r11,120(r3) — state = 0
    if (!argIsZero) {
        ctx.r11.s64 = 1;                                     // li r11,1
        PPC_STORE_U32(ctx.r3.u32 + kDrvExParam1, ctx.r5.u32);// stw r5,140(r3) — exParam1 = r5
        PPC_STORE_U32(ctx.r3.u32 + kDrvExParam2, ctx.r6.u32);// stw r6,144(r3) — exParam2 = r6
        PPC_STORE_U32(ctx.r3.u32 + kDrvLaunchState, ctx.r11.u32); // stw r11,120(r3) — state = 1
    } else {
        PPC_STORE_U32(ctx.r3.u32 + kDrvExParam1, ctx.r11.u32);   // stw r11,140(r3) — exParam1 = 0
        PPC_STORE_U32(ctx.r3.u32 + kDrvExParam2, ctx.r11.u32);   // stw r11,144(r3) — exParam2 = 0
    }
    PPC_STORE_U32(ctx.r3.u32 + kDrvModeArg, ctx.r4.u32);     // stw r4,152(r3)  — driver->modeArg
    ctx.r4.s64  = ctx.r1.s64 + 124;                          // addi r4,r1,124  — arg = &staged
    ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + kDrvGameEntry);  // lwz r11,252(r3)
    ctx.r3.s64  = MSG_MODE_ARM;                              // li r3,10
    ctx.ctr.u64 = ctx.r11.u64;                               // mtctr r11
    ctx.lr = entry + 0x54;                                   // bctrl
    PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
    ctx.r1.s64  = ctx.r1.s64 + 96;                           // addi r1,r1,96
    ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 - 8);              // lwz r12,-8(r1)
    ctx.lr      = ctx.r12.u64;                               // mtlr r12
}

// ═════════════════════════════════════════════════════════════════════════════════════════════
// SHAPE J — vt+0x34 (msg 20 DESCRIPTOR-IN). 22 instructions.
// Sends a two-word descriptor built from the per-mode config table: word[0] points 16 bytes into
// the mode's 720-byte config record (**DAT_821F858C[0] + modeIndex*720 + 16 — same config root
// shape H copies from), word[1] is the driver's +0xC0 word. GameEntry case 19 receives it.
// Published return address = entry + 0x48.
// ═════════════════════════════════════════════════════════════════════════════════════════════
inline void Driver_SendDescriptor(PPCContext& ctx, uint8_t* base, uint32_t entry)
{
    ctx.r12.u64 = ctx.lr;                                    // mflr r12
    PPC_STORE_U32(ctx.r1.u32 - 8, ctx.r12.u32);              // stw r12,-8(r1)
    const uint32_t frame = ctx.r1.u32 - 96;                  // stwu r1,-96(r1)
    PPC_STORE_U32(frame, ctx.r1.u32);
    ctx.r1.u32 = frame;
    ctx.r11.s64 = (int64_t)(int32_t)0x82200000;              // lis r11,-32224
    ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + kDrvModeIndex);  // lwz r10,168(r3) — mode index
    ctx.r9.u64  = PPC_LOAD_U32(ctx.r3.u32 + kDrvCfgWord);    // lwz r9,192(r3)  — descriptor word[1]
    ctx.r4.s64  = ctx.r1.s64 + 80;                           // addi r4,r1,80 — arg = &descriptor
    ctx.r10.s64 = ctx.r10.s64 * 720;                         // mulli r10,r10,720 — index × stride
    ctx.r8.u64  = PPC_LOAD_U32(ctx.r3.u32 + kDrvGameEntry);  // lwz r8,252(r3)
    ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 - 31348);         // lwz r11,-31348(r11) → [0x821F858C]
    PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);              // stw r9,84(r1) — word[1] = driver+0xC0
    ctx.ctr.u64 = ctx.r8.u64;                                // mtctr r8
    ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);             // lwz r11,0(r11) — config root
    ctx.r3.s64  = MSG_DESCRIPTOR_IN;                         // li r3,20
    ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;                 // add r11,r10,r11 — &record
    ctx.r7.s64  = ctx.r11.s64 + 16;                          // addi r7,r11,16  — skip 16-byte header
    PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);             // stw r7,80(r1) — word[0] = record+16
    ctx.lr = entry + 0x48;                                   // bctrl
    PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
    ctx.r1.s64  = ctx.r1.s64 + 96;                           // addi r1,r1,96
    ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 - 8);              // lwz r12,-8(r1)
    ctx.lr      = ctx.r12.u64;                               // mtlr r12
}

// ═════════════════════════════════════════════════════════════════════════════════════════════
// SHAPE K — vt+0x18 (mode-arm STAGED). 51 instructions — the widest of the family.
// Arms a mode WITHOUT sending a GameEntry message directly; instead it primes two array slots on
// the driver (indexed by the +0x74 toggle) and then calls its OWN vtable slot +0x50 (the msg-11
// rank/level wrapper, shape F) with a neutral level of 4. The launchState it records depends on a
// second parameter r5: 2 by default, 3 when r5==3, 4 when r5==4 (the last two also clear +0x7C).
//   - array slot (toggle+32)*4 ← a value pulled from the global chain [0x821F8588]→[+76]→[+80]→[+36]
//   - array slot ((toggle^1)+32)*4 ← -1
// When arg==0 it only records modeArg and returns. Published return address = entry + 0xB0.
// The two rlwinm word-offset computations are reproduced through the recomp's exact rotate/mask
// expression, and +0x88 is cleared just before the inner call — all boundary-visible for the
// vt+0x50 bctrl. r30/r31 are the nonvolatile working copies of arg/driver.
// ═════════════════════════════════════════════════════════════════════════════════════════════
inline void Driver_ArmModeStaged(PPCContext& ctx, uint8_t* base, uint32_t entry)
{
    ctx.r12.u64 = ctx.lr;                                    // mflr r12
    PPC_STORE_U32(ctx.r1.u32 - 8,  ctx.r12.u32);             // stw r12,-8(r1)
    PPC_STORE_U64(ctx.r1.u32 - 24, ctx.r30.u64);             // std r30,-24(r1)
    PPC_STORE_U64(ctx.r1.u32 - 16, ctx.r31.u64);             // std r31,-16(r1)
    const uint32_t frame = ctx.r1.u32 - 112;                 // stwu r1,-112(r1)
    PPC_STORE_U32(frame, ctx.r1.u32);
    ctx.r1.u32 = frame;
    ctx.r10.s64 = 0;                                         // li r10,0
    ctx.r31.u64 = ctx.r3.u64;                                // mr r31,r3
    ctx.r30.u64 = ctx.r4.u64;                                // mr r30,r4
    PPC_STORE_U32(ctx.r3.u32 + kDrvLaunchState, ctx.r10.u32);// stw r10,120(r3) — launchState = 0
    if (ctx.r4.s32 != 0) {                                   // cmpwi cr6,r4,0 / beq cr6 -> loc_ED0
        ctx.r11.s64 = 2;                                     // li r11,2
        PPC_STORE_U32(ctx.r3.u32 + kDrvLaunchState, ctx.r11.u32); // stw r11,120(r3) — state = 2
        if (ctx.r5.u32 == 3) {                               // cmplwi cr6,r5,3 / beq cr6
            ctx.r11.s64 = 3;                                 // li r11,3
            PPC_STORE_U32(ctx.r31.u32 + kDrvLaunchState, ctx.r11.u32); // stw r11,120(r31) — state = 3
            PPC_STORE_U32(ctx.r31.u32 + kDrvStageWord,   ctx.r10.u32); // stw r10,124(r31) — +0x7C = 0
        } else if (ctx.r5.u32 == 4) {                        // cmplwi cr6,r5,4 / bne cr6 -> loc_E78
            ctx.r11.s64 = 4;                                 // li r11,4
            PPC_STORE_U32(ctx.r31.u32 + kDrvLaunchState, ctx.r11.u32); // stw r11,120(r31) — state = 4
            PPC_STORE_U32(ctx.r31.u32 + kDrvStageWord,   ctx.r10.u32); // stw r10,124(r31) — +0x7C = 0
        }
        // loc_E78 — reached for every non-zero arg (all three r5 branches fall through to here)
        ctx.r9.s64  = (int64_t)(int32_t)0x82200000;          // lis r9,-32224
        ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + kDrvToggle);// lwz r11,116(r31) — the +0x74 toggle
        ctx.r8.s64  = -1;                                    // li r8,-1
        ctx.r7.s64  = ctx.r11.s64 + 32;                      // addi r7,r11,32
        ctx.r4.s64  = 4;                                     // li r4,4 — neutral rank level for +0x50
        ctx.r6.u64  = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC; // rlwinm r6,r7,2,0,29
        ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 - 31352);      // lwz r11,-31352(r9) → [0x821F8588]
        ctx.r3.u64  = ctx.r31.u64;                           // mr r3,r31
        ctx.r5.u64  = PPC_LOAD_U32(ctx.r11.u32 + 76);        // lwz r5,76(r11)
        ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 80);         // lwz r11,80(r5)
        ctx.r9.u64  = PPC_LOAD_U32(ctx.r11.u32 + 36);        // lwz r9,36(r11)
        PPC_STORE_U32(ctx.r6.u32 + ctx.r31.u32, ctx.r9.u32); // stwx r9,r6,r31 — slot (toggle+32) = r9
        ctx.r7.u64  = PPC_LOAD_U32(ctx.r31.u32 + kDrvToggle); // lwz r7,116(r31) — reload toggle
        ctx.r11.u64 = ctx.r7.u64 ^ 1;                        // xori r11,r7,1
        ctx.r6.s64  = ctx.r11.s64 + 32;                      // addi r6,r11,32
        ctx.r5.u64  = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC; // rlwinm r5,r6,2,0,29
        PPC_STORE_U32(ctx.r5.u32 + ctx.r31.u32, ctx.r8.u32); // stwx r8,r5,r31 — slot (toggle^1+32) = -1
        ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);         // lwz r11,0(r31) — driver vtable
        PPC_STORE_U32(ctx.r31.u32 + kDrvField88, ctx.r10.u32); // stw r10,136(r31) — +0x88 = 0
        ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);        // lwz r10,80(r11) — vtable slot +0x50
        ctx.ctr.u64 = ctx.r10.u64;                           // mtctr r10
        ctx.lr = entry + 0xB0;                               // bctrl — call +0x50 (rank/level) with r4=4
        PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
    }
    // loc_ED0
    PPC_STORE_U32(ctx.r31.u32 + kDrvModeArg, ctx.r30.u32);   // stw r30,152(r31) — driver->modeArg = arg
    ctx.r1.s64  = ctx.r1.s64 + 112;                          // addi r1,r1,112
    ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 - 8);              // lwz r12,-8(r1)
    ctx.lr      = ctx.r12.u64;                               // mtlr r12
    ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 - 24);             // ld r30,-24(r1)
    ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 - 16);             // ld r31,-16(r1)
}

// ═════════════════════════════════════════════════════════════════════════════════════════════
// SHAPE L — vt+0x70 (the INIT DRIVER). ~130 instructions, frame -496. FUN_821C30B8 in Ghidra.
// This is the boot-path bring-up of a GameDriverTask: it runs a fixed message burst against the
// freshly loaded game module, so translating it live-fires nearly the whole protocol surface on
// the ordinary boot→attract drive. Sequence (each GameEntry call publishes an entry-relative
// return address, verified equal across all 8 clones):
//   entry+0x1C  sub_821C64E8()            pre-init helper (stays generated)
//   entry+0x3C  GameEntry(6, &slotA)      game writes &0x887AD5D4; init back-links driver+0x4C
//   entry+0x50  GameEntry(7, &slotB)      game writes &0x887AD5DC; init back-links driver+0x50
//   entry+0x9C  sub_8207DAC0(dst,src,304) copy the mode's 304-byte config block onto the stack
//   entry+0x118 GameEntry(1, &configIn)   CONFIG-IN: {cfg[+4], cfg[+8], &copied, opt, tbl, opt, 0}
//   entry+0x12C GameEntry(2, driver+0xA4) BOOT
//   entry+0x140 GameEntry(8, driver+0xB4) STATE-BLOCK: game fills driver+0xB4 = 0x887AD544
//   entry+0x194 GameEntry(9, &cbTable)    REGISTER-CBS: 4 (fn,driver) callback pairs
//   entry+0x1A8 vtable+0x34 (this driver) DESCRIPTOR-IN via shape J (msg 20)
// The three opaque global-table loads keep the recomp's exact literals; resolved guest addresses
// are annotated. Nonvolatiles r30 (=0 constant) / r31 (=driver) mirror the generated body.
// ═════════════════════════════════════════════════════════════════════════════════════════════
inline void Driver_Init(PPCContext& ctx, uint8_t* base, uint32_t entry)
{
    ctx.r12.u64 = ctx.lr;                                    // mflr r12
    PPC_STORE_U32(ctx.r1.u32 - 8,  ctx.r12.u32);             // stw r12,-8(r1)
    PPC_STORE_U64(ctx.r1.u32 - 24, ctx.r30.u64);             // std r30,-24(r1)
    PPC_STORE_U64(ctx.r1.u32 - 16, ctx.r31.u64);             // std r31,-16(r1)
    const uint32_t frame = ctx.r1.u32 - 496;                 // stwu r1,-496(r1)
    PPC_STORE_U32(frame, ctx.r1.u32);
    ctx.r1.u32 = frame;
    ctx.r31.u64 = ctx.r3.u64;                                // mr r31,r3 — keep the driver
    ctx.lr = entry + 0x1C; sub_821C64E8(ctx, base);          // bl 0x821c64e8 — pre-init helper
    ctx.r30.s64 = 0;                                         // li r30,0 — the constant-zero nonvolatile
    // ---- GameEntry(6, &slotA@r1+80): game returns &0x887AD5D4 -----------------------------------
    ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + kDrvGameEntry); // lwz r11,252(r31)
    ctx.r4.s64  = ctx.r1.s64 + 80;                           // addi r4,r1,80
    PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);             // stw r30,80(r1) — slotA = 0
    ctx.r3.s64  = MSG_GET_PTR_D5D4;                          // li r3,6
    PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);             // stw r30,84(r1) — slotB = 0
    ctx.ctr.u64 = ctx.r11.u64;                               // mtctr r11
    ctx.lr = entry + 0x3C;                                   // bctrl
    PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
    // ---- GameEntry(7, &slotB@r1+84): game returns &0x887AD5DC ------------------------------------
    ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + kDrvGameEntry); // lwz r10,252(r31)
    ctx.r4.s64  = ctx.r1.s64 + 84;                           // addi r4,r1,84
    ctx.r3.s64  = MSG_GET_PTR_D5DC;                          // li r3,7
    ctx.ctr.u64 = ctx.r10.u64;                               // mtctr r10
    ctx.lr = entry + 0x50;                                   // bctrl
    PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
    // ---- back-link the two returned pointers, then build the CONFIG-IN struct @r1+96 ------------
    ctx.r9.s64  = (int64_t)(int32_t)0x82200000;              // lis r9,-32224
    ctx.r8.u64  = PPC_LOAD_U32(ctx.r31.u32 + kDrvSlotA);     // lwz r8,76(r31)  — driver+0x4C
    ctx.r7.u64  = PPC_LOAD_U32(ctx.r1.u32 + 80);             // lwz r7,80(r1)   — &0x887AD5D4
    ctx.r3.s64  = ctx.r1.s64 + 160;                          // addi r3,r1,160  — dst for the copy
    ctx.r5.s64  = 304;                                       // li r5,304       — copy length
    ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 - 31312);          // lwz r11,-31312(r9) → [0x821F85B0] cfg ptr
    PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r8.u32);               // stw r8,0(r7)   — *0x887AD5D4 = driver+0x4C
    ctx.r6.u64  = PPC_LOAD_U32(ctx.r31.u32 + kDrvSlotB);     // lwz r6,80(r31) — driver+0x50
    ctx.r4.u64  = PPC_LOAD_U32(ctx.r1.u32 + 84);             // lwz r4,84(r1)  — &0x887AD5DC
    PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);               // stw r6,0(r4)   — *0x887AD5DC = driver+0x50
    ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);           // lwz r10,152(r11)
    ctx.r9.u64  = PPC_LOAD_U32(ctx.r10.u32 + 4);             // lwz r9,4(r10)
    PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);              // stw r9,96(r1)  — configIn[0]
    ctx.r8.u64  = PPC_LOAD_U32(ctx.r11.u32 + 152);           // lwz r8,152(r11)
    ctx.r7.u64  = PPC_LOAD_U32(ctx.r8.u32 + 8);              // lwz r7,8(r8)
    PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r7.u32);             // stw r7,100(r1) — configIn[1]
    ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);           // lwz r11,152(r11)
    ctx.r4.s64  = ctx.r11.s64 + 152;                         // addi r4,r11,152 — src for the copy
    ctx.lr = entry + 0x9C; sub_8207DAC0(ctx, base);          // bl 0x8207dac0 — copy 304 bytes to r1+160
    ctx.r6.s64  = (int64_t)(int32_t)0x82200000;              // lis r6,-32224
    ctx.r5.s64  = ctx.r1.s64 + 160;                          // addi r5,r1,160
    PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r5.u32);             // stw r5,104(r1) — configIn[2] = &copied
    ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 - 31364);          // lwz r11,-31364(r6) → [0x821F857C]
    if (ctx.r11.u32 != 0) {                                  // cmplwi cr6,r11,0 / beq -> loc_3178
        ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);         // lwz r10,0(r11)
        if (ctx.r10.u32 == 0)                                // cmplwi cr6,r10,0 / bne -> loc_317C
            ctx.r10.u64 = ctx.r30.u64;                       // (fallthrough loc_3178) mr r10,r30
    } else {
        ctx.r10.u64 = ctx.r30.u64;                           // loc_3178: mr r10,r30
    }
    ctx.r9.s64  = (int64_t)(int32_t)0x82200000;              // lis r9,-32224
    PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);            // stw r10,108(r1) — configIn[3]
    ctx.r8.s64  = ctx.r9.s64 + -32240;                       // addi r8,r9,-32240 → 0x821F8210
    PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);             // stw r8,112(r1) — configIn[4] = &0x821F8210
    if (ctx.r11.u32 != 0) {                                  // cmplwi cr6,r11,0 / beq -> loc_31A4
        ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);         // lwz r10,0(r11)
        const bool nz = (ctx.r10.u32 != 0);                  // cmplwi cr6,r10,0
        ctx.r10.s64 = ctx.r11.s64 + 12;                      // addi r10,r11,12
        if (!nz) ctx.r10.u64 = ctx.r30.u64;                  // bne -> loc_31A8 else loc_31A4 mr r10,r30
    } else {
        ctx.r10.u64 = ctx.r30.u64;                           // loc_31A4: mr r10,r30
    }
    ctx.r9.s64  = (int64_t)(int32_t)0x821D0000;              // lis r9,-32227
    PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r10.u32);            // stw r10,116(r1) — configIn[5]
    PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r11.u32);            // stw r11,124(r1) — configIn[7] = [0x821F857C]
    ctx.r4.s64  = ctx.r1.s64 + 96;                           // addi r4,r1,96 — arg = &configIn
    ctx.r8.s64  = ctx.r9.s64 + -23112;                       // addi r8,r9,-23112 → 0x821CA5B8
    ctx.r7.u64  = PPC_LOAD_U32(ctx.r31.u32 + kDrvGameEntry); // lwz r7,252(r31)
    ctx.r3.s64  = MSG_CONFIG_IN;                             // li r3,1
    PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r8.u32);             // stw r8,120(r1) — configIn[6] = &0x821CA5B8
    ctx.ctr.u64 = ctx.r7.u64;                                // mtctr r7
    ctx.lr = entry + 0x118;                                  // bctrl
    PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
    // ---- GameEntry(2, driver+0xA4): BOOT --------------------------------------------------------
    ctx.r6.u64  = PPC_LOAD_U32(ctx.r31.u32 + kDrvGameEntry); // lwz r6,252(r31)
    ctx.r3.s64  = MSG_BOOT;                                  // li r3,2
    ctx.r4.u64  = PPC_LOAD_U32(ctx.r31.u32 + kDrvBootArg);   // lwz r4,164(r31) — driver+0xA4
    ctx.ctr.u64 = ctx.r6.u64;                                // mtctr r6
    ctx.lr = entry + 0x12C;                                  // bctrl
    PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
    // ---- GameEntry(8, &driver+0xB4): STATE-BLOCK (game writes 0x887AD544 into driver+0xB4) ------
    ctx.r5.u64  = PPC_LOAD_U32(ctx.r31.u32 + kDrvGameEntry); // lwz r5,252(r31)
    ctx.r4.s64  = ctx.r31.s64 + kDrvStateBlock;              // addi r4,r31,180
    ctx.r3.s64  = MSG_STATE_BLOCK;                           // li r3,8
    ctx.ctr.u64 = ctx.r5.u64;                                // mtctr r5
    ctx.lr = entry + 0x140;                                  // bctrl
    PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
    // ---- GameEntry(9, &cbTable@r1+128): REGISTER-CBS — 4 (fn,driver) pairs ----------------------
    ctx.r4.s64  = (int64_t)(int32_t)0x821C0000;              // lis r4,-32228
    PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r31.u32);            // stw r31,132(r1) — pair0.ctx = driver
    ctx.r3.s64  = (int64_t)(int32_t)0x821C0000;              // lis r3,-32228
    PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r31.u32);            // stw r31,140(r1) — pair1.ctx = driver
    ctx.r11.s64 = (int64_t)(int32_t)0x821C0000;              // lis r11,-32228
    PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r31.u32);            // stw r31,148(r1) — pair2.ctx = driver
    ctx.r10.s64 = (int64_t)(int32_t)0x821C0000;              // lis r10,-32228
    PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r31.u32);            // stw r31,156(r1) — pair3.ctx = driver
    ctx.r9.s64  = ctx.r4.s64 + 21224;                        // addi r9,r4,21224  → 0x821C52E8 (cb fn0)
    ctx.r5.u64  = PPC_LOAD_U32(ctx.r31.u32 + kDrvGameEntry); // lwz r5,252(r31)
    ctx.r8.s64  = ctx.r3.s64 + 25096;                        // addi r8,r3,25096  → 0x821C6208 (cb fn1)
    ctx.r7.s64  = ctx.r11.s64 + 22040;                       // addi r7,r11,22040 → 0x821C5618 (cb fn2, sub_821C5618)
    PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r9.u32);             // stw r9,128(r1)  — pair0.fn
    ctx.r6.s64  = ctx.r10.s64 + 21040;                       // addi r6,r10,21040 → 0x821C5230 (cb fn3, sub_821C5230)
    PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r8.u32);             // stw r8,136(r1)  — pair1.fn
    PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r7.u32);             // stw r7,144(r1)  — pair2.fn
    ctx.r4.s64  = ctx.r1.s64 + 128;                          // addi r4,r1,128 — arg = &cbTable
    PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r6.u32);             // stw r6,152(r1)  — pair3.fn
    ctx.r3.s64  = MSG_REGISTER_CBS;                          // li r3,9
    ctx.ctr.u64 = ctx.r5.u64;                                // mtctr r5
    ctx.lr = entry + 0x194;                                  // bctrl
    PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
    // ---- finally, kick DESCRIPTOR-IN through this driver's own vtable slot +0x34 (shape J) ------
    ctx.r4.u64  = PPC_LOAD_U32(ctx.r31.u32 + 0);             // lwz r4,0(r31) — driver vtable
    ctx.r3.u64  = ctx.r31.u64;                               // mr r3,r31
    ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 52);             // lwz r11,52(r4) — vtable slot +0x34
    ctx.ctr.u64 = ctx.r11.u64;                               // mtctr r11
    ctx.lr = entry + 0x1A8;                                  // bctrl
    PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
    ctx.r1.s64  = ctx.r1.s64 + 496;                          // addi r1,r1,496
    ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 - 8);              // lwz r12,-8(r1)
    ctx.lr      = ctx.r12.u64;                               // mtlr r12
    ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 - 24);             // ld r30,-24(r1)
    ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 - 16);             // ld r31,-16(r1)
}
