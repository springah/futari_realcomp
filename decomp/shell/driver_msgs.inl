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
constexpr uint32_t kDrvLaunchState = 120;  // +0x78 launch state (0 / 5)
constexpr uint32_t kDrvRankLevel   = 148;  // +0x94 rank / level
constexpr uint32_t kDrvModeArg     = 152;  // +0x98 mode arg
constexpr uint32_t kDrvStateBlock  = 180;  // +0xB4 → game-side status block (msg 8 gave 0x887AD544)
constexpr uint32_t kDrvGameEntry   = 252;  // +0xFC → GameEntry proc ptr (XexGetProcAddr ord 1)

// ---- The game-side status block bytes the predicates test (offsets INTO driver+0xB4) --------
constexpr uint32_t kStPhase = 4;  // 0x887AD548 — both predicates require == 5
constexpr uint32_t kStSub   = 6;  // 0x887AD54A — sub-state: 4 or 1
constexpr uint32_t kStGate  = 3;  // 0x887AD547 — the byte msg 14 CREDIT-ARM uses as its guard

// ---- Messages sent from here (ids proven in decomp/game/game_entry_msgs.cpp) -----------------
enum GameMsg : uint32_t {
    MSG_MODE_ARM       = 10,  // GameEntry case  9: 0x887AD534 = arg[0], 0x887AD538 = 0
    MSG_RANK_LEVEL     = 11,  // GameEntry case 10: 0x88252DD8 = arg[0]
    MSG_MODE64_ARM     = 12,  // GameEntry case 11: 0x88252D58=-1, mode64=3, 0x887AD59C=0x8000
    MSG_RETURN_TO_MENU = 13,  // GameEntry case 12: reload mailbox 0x887AD58C = 1
    MSG_CONFIG_BLOCK   = 15,  // GameEntry case 14: sub_8808F1E8(arg) with r4 = arg[16]
    MSG_COLOR_DEFAULTS = 16,  // GameEntry case 15: sub_8808F150(arg[0])
    MSG_MAGIC_VALIDATE = 17,  // GameEntry case 16: sub_8808F098(arg[0], arg[1])
    MSG_BLOCK2C_IN     = 18,  // GameEntry case 17: sub_8808EFA8(arg)
    MSG_MODE_SELECT    = 19,  // GameEntry case 18: 0x88252D58 = arg[0] (range-checked)
};

// The 16-byte block copier the two msg-15 shapes call is sub_8207DAC0(dst, src, len); it is
// declared at global scope in driver_msgs.cpp (a PPC_EXTERN_FUNC inside this namespace would
// declare a namespace-local symbol and never link to the generated body).

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
