// decomp/shell/driver_msgs.cpp — D1 CLUSTER: the shell's GameDriverTask command surface.
//
// WHAT THIS REPLACES.  The shell talks to the loaded game module through a GameDriverTask
// object whose vtable carries one small wrapper per protocol message (ATLAS_shell_menus §2
// "Shell→game protocol: driver + config-setter wrappers", §3 GameDriverTask table). There are
// EIGHT copies of that driver in default.img.bin — one per launchable mode — and the copies are
// byte-identical apart from their addresses. HUMAN_READABLE_DECOMP_PLAN §4 rank 5 predicted
// exactly this and called collapsing them "the largest LOC reduction per effort in the project".
//
// This file makes that concrete: TWELVE shapes, written once in driver_msgs.inl, instantiated
// 96 times below (12 shapes × 8 clones). Every listed address came from a mechanical scan that
// normalised address literals out of every generated body in shell/gen/ppc_recomp.*.cpp and
// grouped the results — each shape found exactly 8 members, so the table is complete by
// construction rather than by transcription. ~1500 lines of generated PPC become ~300 lines of
// commented C plus a table you can read top to bottom.
//
// The clone → vtable mapping is in reference/ghidra_futari_decomp/vt_gdtask_0727.txt
// (vt 0x8204FFA8 = the 0x821C2xxx clone, vt 0x8204FC38 = the 0x821C8xxx clone; the other six
// follow the same slot layout at 0x821C40xx/0x821C49xx/0x821C75xx/0x821C7Dxx/0x821C8Exx/
// 0x821C96xx). Slot numbers below are that dump's offsets.
//
// ── SEAM (plan §3, PILOT_NOTES §2) ────────────────────────────────────────────────────────
// None of the 96 addresses is hooked in out_reco/merged/* (checked mechanically), so the plain
// PPC_FUNC(sub_82XXXXXX) form is correct: strong beats the generated PPC_WEAK_FUNC alias, and
// decomp objects link FIRST in every build entry point (build_win.sh, build_win_abn.sh,
// build_win_dll.sh all glob decomp/shell/*.cpp), so these bodies win and the generated ones stay
// in the image as dead weight. ROLLBACK = delete this file, or drop obj_win/decomp_driver_msgs.o
// from the link line; the generated bodies take over again instantly.
//
// ── FINDING for the atlas conflict ledger (log only; do not edit atlases from this task) ──
// The predicate operand `driver+0xB4` is the block the GAME hands back in msg 8: GameEntry
// case 7 stores 0x887AD544 into *arg (decomp/game/game_entry_msgs.cpp). So the two predicate
// shapes read GAME-module globals live from the shell —
//     stateBlock[3] = 0x887AD547  ← the very byte msg 14 CREDIT-ARM uses as its guard
//     stateBlock[4] = 0x887AD548      stateBlock[6] = 0x887AD54A
// ATLAS_shell_menus §3 records +0xB4 only as "persistent state block → msg 8 arg"; naming the
// concrete guest addresses (and the overlap with the msg-14 credit gate) is new here.
//
// Registry status: see decomp/registry.toml (per-address rows) and PILOT_NOTES-style gate notes
// in docs/NOTE_campaign_decomp.md. NOT ASM-EXACT and cannot be: these are PPC_FUNC ctx-shaped
// bodies manipulating ctx.rNN and the guest stack, so there is no natural C++ for the XDK 9328
// compiler to compare against (plan §10, two-axis table in decomp/README.md).

#include "ppc_recomp_shared.h"   // -I shell/gen: shell ppc_config.h (base 0x82000000) + context

// The 16-byte block copier both msg-15 shapes call. Declared at global scope so the call routes
// through the same strong-over-weak seam the generated bodies use (any instrument wrapper on it
// keeps firing exactly as before).
PPC_EXTERN_FUNC(sub_8207DAC0);

namespace drv {
#include "driver_msgs.inl"
}  // namespace drv

// ═════════════════════════════════════════════════════════════════════════════════════════════
// THE CLONE TABLE — 12 shapes × 8 clones. One line per guest function; the address is passed to
// the shapes that must publish generated return addresses (each derives them at a fixed offset
// from the entry, verified identical across all 8 clones of that shape).
// ═════════════════════════════════════════════════════════════════════════════════════════════

#define DRV_PRED_SUB4(sym)              PPC_FUNC(sym) { PPC_FUNC_PROLOGUE(); drv::Driver_IsPhase5Sub(ctx, base, 4, true); }
#define DRV_PRED_SUB1(sym)              PPC_FUNC(sym) { PPC_FUNC_PROLOGUE(); drv::Driver_IsPhase5Sub(ctx, base, 1, false); }
#define DRV_SEND_RETURN_TO_MENU(sym)    PPC_FUNC(sym) { PPC_FUNC_PROLOGUE(); drv::Driver_SendTail(ctx, base, drv::MSG_RETURN_TO_MENU, true); }
#define DRV_SEND_MODE64_ARM(sym)        PPC_FUNC(sym) { PPC_FUNC_PROLOGUE(); drv::Driver_SendTail(ctx, base, drv::MSG_MODE64_ARM, true); }
#define DRV_SEND_BLOCK2C(sym)           PPC_FUNC(sym) { PPC_FUNC_PROLOGUE(); drv::Driver_SendTail(ctx, base, drv::MSG_BLOCK2C_IN, false); }
#define DRV_SET_COLOR_DEFAULTS(sym, ea) PPC_FUNC(sym) { PPC_FUNC_PROLOGUE(); drv::Driver_SendWord(ctx, base, drv::MSG_COLOR_DEFAULTS, (ea)); }
#define DRV_SET_MODE_SELECT(sym, ea)    PPC_FUNC(sym) { PPC_FUNC_PROLOGUE(); drv::Driver_SendWord(ctx, base, drv::MSG_MODE_SELECT, (ea)); }
#define DRV_QUERY_MAGIC(sym, ea)        PPC_FUNC(sym) { PPC_FUNC_PROLOGUE(); drv::Driver_QueryWord(ctx, base, drv::MSG_MAGIC_VALIDATE, (ea)); }
#define DRV_ARM_MODE(sym, ea)           PPC_FUNC(sym) { PPC_FUNC_PROLOGUE(); drv::Driver_ArmMode(ctx, base, (ea)); }
#define DRV_SET_RANK_LEVEL(sym, ea)     PPC_FUNC(sym) { PPC_FUNC_PROLOGUE(); drv::Driver_SetRankLevel(ctx, base, (ea)); }
#define DRV_CFG_BLOCK_ARG(sym, ea)      PPC_FUNC(sym) { PPC_FUNC_PROLOGUE(); drv::Driver_SendConfigBlockFromArg(ctx, base, (ea)); }
#define DRV_CFG_BLOCK_REGION(sym, ea)   PPC_FUNC(sym) { PPC_FUNC_PROLOGUE(); drv::Driver_SendConfigBlockFromRegion(ctx, base, (ea)); }

// ---- vtable slot +0x1C : msg 10 MODE-ARM (simple)          — SHAPE E  Driver_ArmMode
DRV_ARM_MODE(sub_821C2CB0, 0x821C2CB0)
DRV_ARM_MODE(sub_821C4248, 0x821C4248)
DRV_ARM_MODE(sub_821C4AC8, 0x821C4AC8)
DRV_ARM_MODE(sub_821C76D8, 0x821C76D8)
DRV_ARM_MODE(sub_821C7F58, 0x821C7F58)
DRV_ARM_MODE(sub_821C87D8, 0x821C87D8)
DRV_ARM_MODE(sub_821C9058, 0x821C9058)
DRV_ARM_MODE(sub_821C98D8, 0x821C98D8)

// ---- vtable slot +0x20 : msg 15 CONFIG BLOCK from caller    — SHAPE G  Driver_SendConfigBlockFromArg
DRV_CFG_BLOCK_ARG(sub_821C2C58, 0x821C2C58)
DRV_CFG_BLOCK_ARG(sub_821C41F0, 0x821C41F0)
DRV_CFG_BLOCK_ARG(sub_821C4A70, 0x821C4A70)
DRV_CFG_BLOCK_ARG(sub_821C7680, 0x821C7680)
DRV_CFG_BLOCK_ARG(sub_821C7F00, 0x821C7F00)
DRV_CFG_BLOCK_ARG(sub_821C8780, 0x821C8780)
DRV_CFG_BLOCK_ARG(sub_821C9000, 0x821C9000)
DRV_CFG_BLOCK_ARG(sub_821C9880, 0x821C9880)

// ---- vtable slot +0x24 : msg 16 single-word setter          — SHAPE C  Driver_SendWord
DRV_SET_COLOR_DEFAULTS(sub_821C2C20, 0x821C2C20)
DRV_SET_COLOR_DEFAULTS(sub_821C41B8, 0x821C41B8)
DRV_SET_COLOR_DEFAULTS(sub_821C4A38, 0x821C4A38)
DRV_SET_COLOR_DEFAULTS(sub_821C7648, 0x821C7648)
DRV_SET_COLOR_DEFAULTS(sub_821C7EC8, 0x821C7EC8)
DRV_SET_COLOR_DEFAULTS(sub_821C8748, 0x821C8748)
DRV_SET_COLOR_DEFAULTS(sub_821C8FC8, 0x821C8FC8)
DRV_SET_COLOR_DEFAULTS(sub_821C9848, 0x821C9848)

// ---- vtable slot +0x28 : msg 17 MAGIC-VALIDATE query        — SHAPE D  Driver_QueryWord
DRV_QUERY_MAGIC(sub_821C2BD8, 0x821C2BD8)
DRV_QUERY_MAGIC(sub_821C4170, 0x821C4170)
DRV_QUERY_MAGIC(sub_821C49F0, 0x821C49F0)
DRV_QUERY_MAGIC(sub_821C7600, 0x821C7600)
DRV_QUERY_MAGIC(sub_821C7E80, 0x821C7E80)
DRV_QUERY_MAGIC(sub_821C8700, 0x821C8700)
DRV_QUERY_MAGIC(sub_821C8F80, 0x821C8F80)
DRV_QUERY_MAGIC(sub_821C9800, 0x821C9800)

// ---- vtable slot +0x2C : msg 18 BLOCK2C-IN (tail)           — SHAPE B  Driver_SendTail
DRV_SEND_BLOCK2C(sub_821C2BC8)
DRV_SEND_BLOCK2C(sub_821C4160)
DRV_SEND_BLOCK2C(sub_821C49E0)
DRV_SEND_BLOCK2C(sub_821C75F0)
DRV_SEND_BLOCK2C(sub_821C7E70)
DRV_SEND_BLOCK2C(sub_821C86F0)
DRV_SEND_BLOCK2C(sub_821C8F70)
DRV_SEND_BLOCK2C(sub_821C97F0)

// ---- vtable slot +0x30 : msg 15 CONFIG BLOCK from region    — SHAPE H  Driver_SendConfigBlockFromRegion
DRV_CFG_BLOCK_REGION(sub_821C2DC0, 0x821C2DC0)
DRV_CFG_BLOCK_REGION(sub_821C4358, 0x821C4358)
DRV_CFG_BLOCK_REGION(sub_821C4BD8, 0x821C4BD8)
DRV_CFG_BLOCK_REGION(sub_821C77E8, 0x821C77E8)
DRV_CFG_BLOCK_REGION(sub_821C8068, 0x821C8068)
DRV_CFG_BLOCK_REGION(sub_821C88E8, 0x821C88E8)
DRV_CFG_BLOCK_REGION(sub_821C9168, 0x821C9168)
DRV_CFG_BLOCK_REGION(sub_821C99E8, 0x821C99E8)

// ---- vtable slot +0x38 : state predicate, sub-state 1       — SHAPE A  Driver_IsPhase5Sub
DRV_PRED_SUB1(sub_821C2B68)
DRV_PRED_SUB1(sub_821C4100)
DRV_PRED_SUB1(sub_821C4980)
DRV_PRED_SUB1(sub_821C7590)
DRV_PRED_SUB1(sub_821C7E10)
DRV_PRED_SUB1(sub_821C8690)
DRV_PRED_SUB1(sub_821C8F10)
DRV_PRED_SUB1(sub_821C9790)

// ---- vtable slot +0x3C : msg 12 MODE64-ARM (tail)           — SHAPE B  Driver_SendTail
DRV_SEND_MODE64_ARM(sub_821C2B50)
DRV_SEND_MODE64_ARM(sub_821C40E8)
DRV_SEND_MODE64_ARM(sub_821C4968)
DRV_SEND_MODE64_ARM(sub_821C7578)
DRV_SEND_MODE64_ARM(sub_821C7DF8)
DRV_SEND_MODE64_ARM(sub_821C8678)
DRV_SEND_MODE64_ARM(sub_821C8EF8)
DRV_SEND_MODE64_ARM(sub_821C9778)

// ---- vtable slot +0x40 : msg 13 RETURN-TO-MENU (tail)       — SHAPE B  Driver_SendTail
DRV_SEND_RETURN_TO_MENU(sub_821C2B38)
DRV_SEND_RETURN_TO_MENU(sub_821C40D0)
DRV_SEND_RETURN_TO_MENU(sub_821C4950)
DRV_SEND_RETURN_TO_MENU(sub_821C7560)
DRV_SEND_RETURN_TO_MENU(sub_821C7DE0)
DRV_SEND_RETURN_TO_MENU(sub_821C8660)
DRV_SEND_RETURN_TO_MENU(sub_821C8EE0)
DRV_SEND_RETURN_TO_MENU(sub_821C9760)

// ---- vtable slot +0x44 : state predicate, sub-state 4+gate  — SHAPE A  Driver_IsPhase5Sub
DRV_PRED_SUB4(sub_821C2B00)
DRV_PRED_SUB4(sub_821C4098)
DRV_PRED_SUB4(sub_821C4918)
DRV_PRED_SUB4(sub_821C7528)
DRV_PRED_SUB4(sub_821C7DA8)
DRV_PRED_SUB4(sub_821C8628)
DRV_PRED_SUB4(sub_821C8EA8)
DRV_PRED_SUB4(sub_821C9728)

// ---- vtable slot +0x4C : msg 19 MODE-SELECT setter          — SHAPE C  Driver_SendWord
DRV_SET_MODE_SELECT(sub_821C2B90, 0x821C2B90)
DRV_SET_MODE_SELECT(sub_821C4128, 0x821C4128)
DRV_SET_MODE_SELECT(sub_821C49A8, 0x821C49A8)
DRV_SET_MODE_SELECT(sub_821C75B8, 0x821C75B8)
DRV_SET_MODE_SELECT(sub_821C7E38, 0x821C7E38)
DRV_SET_MODE_SELECT(sub_821C86B8, 0x821C86B8)
DRV_SET_MODE_SELECT(sub_821C8F38, 0x821C8F38)
DRV_SET_MODE_SELECT(sub_821C97B8, 0x821C97B8)

// ---- vtable slot +0x50 : msg 11 RANK/LEVEL setter           — SHAPE F  Driver_SetRankLevel
DRV_SET_RANK_LEVEL(sub_821C2A78, 0x821C2A78)
DRV_SET_RANK_LEVEL(sub_821C4010, 0x821C4010)
DRV_SET_RANK_LEVEL(sub_821C4890, 0x821C4890)
DRV_SET_RANK_LEVEL(sub_821C74A0, 0x821C74A0)
DRV_SET_RANK_LEVEL(sub_821C7D20, 0x821C7D20)
DRV_SET_RANK_LEVEL(sub_821C85A0, 0x821C85A0)
DRV_SET_RANK_LEVEL(sub_821C8E20, 0x821C8E20)
DRV_SET_RANK_LEVEL(sub_821C96A0, 0x821C96A0)
