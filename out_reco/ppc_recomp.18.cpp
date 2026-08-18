#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_88135C58"))) PPC_WEAK_FUNC(sub_88135C58);
PPC_FUNC_IMPL(__imp__sub_88135C58) {
	PPC_FUNC_PROLOGUE();
	// mulli r11,r4,196
	ctx.r11.s64 = ctx.r4.s64 * 196;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// addi r3,r11,1448
	ctx.r3.s64 = ctx.r11.s64 + 1448;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135C68"))) PPC_WEAK_FUNC(sub_88135C68);
PPC_FUNC_IMPL(__imp__sub_88135C68) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r11,r3,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// add r9,r3,r11
	ctx.r9.u64 = ctx.r3.u64 + ctx.r11.u64;
	// addi r11,r10,9480
	ctx.r11.s64 = ctx.r10.s64 + 9480;
	// rlwinm r8,r9,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r7,r11,20
	ctx.r7.s64 = ctx.r11.s64 + 20;
	// lwzx r3,r8,r7
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135C88"))) PPC_WEAK_FUNC(sub_88135C88);
PPC_FUNC_IMPL(__imp__sub_88135C88) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r11,r3,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// add r9,r3,r11
	ctx.r9.u64 = ctx.r3.u64 + ctx.r11.u64;
	// addi r11,r10,9480
	ctx.r11.s64 = ctx.r10.s64 + 9480;
	// rlwinm r8,r9,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r7,r11,16
	ctx.r7.s64 = ctx.r11.s64 + 16;
	// lwzx r3,r8,r7
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135CA8"))) PPC_WEAK_FUNC(sub_88135CA8);
PPC_FUNC_IMPL(__imp__sub_88135CA8) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r11,r3,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// add r9,r3,r11
	ctx.r9.u64 = ctx.r3.u64 + ctx.r11.u64;
	// addi r11,r10,9480
	ctx.r11.s64 = ctx.r10.s64 + 9480;
	// rlwinm r8,r9,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r7,r11,4
	ctx.r7.s64 = ctx.r11.s64 + 4;
	// lwzx r3,r8,r7
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135CC8"))) PPC_WEAK_FUNC(sub_88135CC8);
PPC_FUNC_IMPL(__imp__sub_88135CC8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,84(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135CD0"))) PPC_WEAK_FUNC(sub_88135CD0);
PPC_FUNC_IMPL(__imp__sub_88135CD0) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// stw r4,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, ctx.r4.u32);
	// addi r9,r10,-10940
	ctx.r9.s64 = ctx.r10.s64 + -10940;
	// stb r4,9(r9)
	PPC_STORE_U8(ctx.r9.u32 + 9, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135CE4"))) PPC_WEAK_FUNC(sub_88135CE4);
PPC_FUNC_IMPL(__imp__sub_88135CE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88135CE8"))) PPC_WEAK_FUNC(sub_88135CE8);
PPC_FUNC_IMPL(__imp__sub_88135CE8) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r8,r10,26432
	ctx.r8.s64 = ctx.r10.s64 + 26432;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r11,367(r8)
	PPC_STORE_U8(ctx.r8.u32 + 367, ctx.r11.u8);
	// stw r10,140(r8)
	PPC_STORE_U32(ctx.r8.u32 + 140, ctx.r10.u32);
	// stw r9,316(r8)
	PPC_STORE_U32(ctx.r8.u32 + 316, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135D0C"))) PPC_WEAK_FUNC(sub_88135D0C);
PPC_FUNC_IMPL(__imp__sub_88135D0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88135D10"))) PPC_WEAK_FUNC(sub_88135D10);
PPC_FUNC_IMPL(__imp__sub_88135D10) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,332(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 332);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,332(r4)
	PPC_STORE_U32(ctx.r4.u32 + 332, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135D20"))) PPC_WEAK_FUNC(sub_88135D20);
PPC_FUNC_IMPL(__imp__sub_88135D20) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,328(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 328);
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,28368
	ctx.r10.s64 = ctx.r10.s64 + 28368;
	// stw r11,328(r4)
	PPC_STORE_U32(ctx.r4.u32 + 328, ctx.r11.u32);
	// lbz r8,1(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// extsb r11,r8
	ctx.r11.s64 = ctx.r8.s8;
	// beq cr6,0x88135d58
	if (ctx.cr6.eq) goto loc_88135D58;
	// addi r9,r10,-8
	ctx.r9.s64 = ctx.r10.s64 + -8;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r7,1
	ctx.r7.s64 = 1;
	// stwx r7,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r7.u32);
loc_88135D58:
	// lwz r9,164(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r9,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135D68"))) PPC_WEAK_FUNC(sub_88135D68);
PPC_FUNC_IMPL(__imp__sub_88135D68) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,324(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 324);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,324(r4)
	PPC_STORE_U32(ctx.r4.u32 + 324, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135D78"))) PPC_WEAK_FUNC(sub_88135D78);
PPC_FUNC_IMPL(__imp__sub_88135D78) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,26432
	ctx.r11.s64 = ctx.r11.s64 + 26432;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r8,r11,60
	ctx.r8.s64 = ctx.r11.s64 + 60;
	// stwx r9,r10,r8
	PPC_STORE_U32(ctx.r10.u32 + ctx.r8.u32, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135D94"))) PPC_WEAK_FUNC(sub_88135D94);
PPC_FUNC_IMPL(__imp__sub_88135D94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88135D98"))) PPC_WEAK_FUNC(sub_88135D98);
PPC_FUNC_IMPL(__imp__sub_88135D98) {
	PPC_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// beq cr6,0x88135db0
	if (ctx.cr6.eq) goto loc_88135DB0;
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
loc_88135DB0:
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x88135dbc
	if (ctx.cr6.eq) goto loc_88135DBC;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
loc_88135DBC:
	// lis r9,-30643
	ctx.r9.s64 = -2008219648;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// addi r11,r9,26432
	ctx.r11.s64 = ctx.r9.s64 + 26432;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r11,r11,1448
	ctx.r11.s64 = ctx.r11.s64 + 1448;
loc_88135DD0:
	// lbz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq cr6,0x88135e1c
	if (ctx.cr6.eq) goto loc_88135E1C;
	// lwz r7,140(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 140);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x88135e1c
	if (ctx.cr6.eq) goto loc_88135E1C;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x88135e04
	if (!ctx.cr6.eq) goto loc_88135E04;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x88135e18
	if (ctx.cr6.eq) goto loc_88135E18;
	// stw r9,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
	// b 0x88135e18
	goto loc_88135E18;
loc_88135E04:
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x88135e18
	if (!ctx.cr6.eq) goto loc_88135E18;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x88135e18
	if (ctx.cr6.eq) goto loc_88135E18;
	// stw r9,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r9.u32);
loc_88135E18:
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
loc_88135E1C:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,196
	ctx.r11.s64 = ctx.r11.s64 + 196;
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// blt cr6,0x88135dd0
	if (ctx.cr6.lt) goto loc_88135DD0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135E30"))) PPC_WEAK_FUNC(sub_88135E30);
PPC_FUNC_IMPL(__imp__sub_88135E30) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lis r10,-30701
	ctx.r10.s64 = -2012020736;
	// addi r30,r11,26432
	ctx.r30.s64 = ctx.r11.s64 + 26432;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r4,r10,22816
	ctx.r4.s64 = ctx.r10.s64 + 22816;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88135ba8
	ctx.lr = 0x88135E64;
	sub_88135BA8(ctx, base);
	// stw r31,132(r30)
	PPC_STORE_U32(ctx.r30.u32 + 132, ctx.r31.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135E80"))) PPC_WEAK_FUNC(sub_88135E80);
PPC_FUNC_IMPL(__imp__sub_88135E80) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,128(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r11.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// stw r11,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, ctx.r11.u32);
	// stw r11,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r11.u32);
	// stw r11,148(r3)
	PPC_STORE_U32(ctx.r3.u32 + 148, ctx.r11.u32);
	// stw r11,152(r3)
	PPC_STORE_U32(ctx.r3.u32 + 152, ctx.r11.u32);
	// stw r11,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r11.u32);
	// stw r11,160(r3)
	PPC_STORE_U32(ctx.r3.u32 + 160, ctx.r11.u32);
	// stw r11,176(r3)
	PPC_STORE_U32(ctx.r3.u32 + 176, ctx.r11.u32);
	// lwz r9,84(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x88135ec0
	if (!ctx.cr6.eq) goto loc_88135EC0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,160(r3)
	PPC_STORE_U32(ctx.r3.u32 + 160, ctx.r10.u32);
loc_88135EC0:
	// stw r11,180(r3)
	PPC_STORE_U32(ctx.r3.u32 + 180, ctx.r11.u32);
	// stw r11,168(r3)
	PPC_STORE_U32(ctx.r3.u32 + 168, ctx.r11.u32);
	// lwz r10,1860(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 1860);
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// bne cr6,0x88135ef8
	if (!ctx.cr6.eq) goto loc_88135EF8;
	// lis r10,-30614
	ctx.r10.s64 = -2006319104;
	// lwz r9,84(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 84);
	// addi r10,r10,-26520
	ctx.r10.s64 = ctx.r10.s64 + -26520;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r10,16
	ctx.r7.s64 = ctx.r10.s64 + 16;
	// lwz r10,36(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// stw r10,112(r4)
	PPC_STORE_U32(ctx.r4.u32 + 112, ctx.r10.u32);
	// lwzx r6,r8,r7
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// stw r6,160(r3)
	PPC_STORE_U32(ctx.r3.u32 + 160, ctx.r6.u32);
loc_88135EF8:
	// lwz r10,92(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 92);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lwz r10,84(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 84);
	// lis r9,-30714
	ctx.r9.s64 = -2012872704;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r9,r9,9480
	ctx.r9.s64 = ctx.r9.s64 + 9480;
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// addi r7,r9,20
	ctx.r7.s64 = ctx.r9.s64 + 20;
	// rlwinm r6,r8,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r5,r6,r7
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r7.u32);
	// cmpwi cr6,r5,6
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 6, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// stb r11,7(r3)
	PPC_STORE_U8(ctx.r3.u32 + 7, ctx.r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135F34"))) PPC_WEAK_FUNC(sub_88135F34);
PPC_FUNC_IMPL(__imp__sub_88135F34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88135F38"))) PPC_WEAK_FUNC(sub_88135F38);
PPC_FUNC_IMPL(__imp__sub_88135F38) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071128
	ctx.lr = 0x88135F40;
	__savegprlr_16(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// li r5,1928
	ctx.r5.s64 = 1928;
	// addi r31,r11,28376
	ctx.r31.s64 = ctx.r11.s64 + 28376;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r31,-1944
	ctx.r3.s64 = ctx.r31.s64 + -1944;
	// lwz r30,-1944(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + -1944);
	// lwz r29,-1940(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + -1940);
	// lwz r28,-1936(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + -1936);
	// lwz r27,-1932(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + -1932);
	// lwz r26,-1928(r31)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r31.u32 + -1928);
	// lwz r25,-1924(r31)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r31.u32 + -1924);
	// lwz r24,-1920(r31)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r31.u32 + -1920);
	// lwz r23,-1916(r31)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r31.u32 + -1916);
	// lwz r22,-1912(r31)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r31.u32 + -1912);
	// lwz r21,-1908(r31)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r31.u32 + -1908);
	// lwz r20,-1904(r31)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r31.u32 + -1904);
	// lwz r19,-1900(r31)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r31.u32 + -1900);
	// lwz r18,-1896(r31)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r31.u32 + -1896);
	// lwz r17,-1892(r31)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r31.u32 + -1892);
	// lwz r16,-1888(r31)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r31.u32 + -1888);
	// bl 0x88072260
	ctx.lr = 0x88135F98;
	sub_88072260(ctx, base);
	// addi r11,r31,-1944
	ctx.r11.s64 = ctx.r31.s64 + -1944;
	// lwz r9,-28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + -28);
	// addi r10,r31,-1944
	ctx.r10.s64 = ctx.r31.s64 + -1944;
	// stw r30,-1944(r31)
	PPC_STORE_U32(ctx.r31.u32 + -1944, ctx.r30.u32);
	// stw r11,-368(r31)
	PPC_STORE_U32(ctx.r31.u32 + -368, ctx.r11.u32);
	// lis r8,-30671
	ctx.r8.s64 = -2010054656;
	// stw r10,-172(r31)
	PPC_STORE_U32(ctx.r31.u32 + -172, ctx.r10.u32);
	// lis r7,-30643
	ctx.r7.s64 = -2008219648;
	// lis r6,-30643
	ctx.r6.s64 = -2008219648;
	// stw r29,-1940(r31)
	PPC_STORE_U32(ctx.r31.u32 + -1940, ctx.r29.u32);
	// lis r5,-30643
	ctx.r5.s64 = -2008219648;
	// stw r28,-1936(r31)
	PPC_STORE_U32(ctx.r31.u32 + -1936, ctx.r28.u32);
	// lis r4,-30643
	ctx.r4.s64 = -2008219648;
	// stw r27,-1932(r31)
	PPC_STORE_U32(ctx.r31.u32 + -1932, ctx.r27.u32);
	// stw r26,-1928(r31)
	PPC_STORE_U32(ctx.r31.u32 + -1928, ctx.r26.u32);
	// stw r25,-1924(r31)
	PPC_STORE_U32(ctx.r31.u32 + -1924, ctx.r25.u32);
	// stw r9,26424(r6)
	PPC_STORE_U32(ctx.r6.u32 + 26424, ctx.r9.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r24,-1920(r31)
	PPC_STORE_U32(ctx.r31.u32 + -1920, ctx.r24.u32);
	// stw r23,-1916(r31)
	PPC_STORE_U32(ctx.r31.u32 + -1916, ctx.r23.u32);
	// stw r22,-1912(r31)
	PPC_STORE_U32(ctx.r31.u32 + -1912, ctx.r22.u32);
	// stw r21,-1908(r31)
	PPC_STORE_U32(ctx.r31.u32 + -1908, ctx.r21.u32);
	// stw r20,-1904(r31)
	PPC_STORE_U32(ctx.r31.u32 + -1904, ctx.r20.u32);
	// stw r19,-1900(r31)
	PPC_STORE_U32(ctx.r31.u32 + -1900, ctx.r19.u32);
	// stw r18,-1896(r31)
	PPC_STORE_U32(ctx.r31.u32 + -1896, ctx.r18.u32);
	// stw r17,-1892(r31)
	PPC_STORE_U32(ctx.r31.u32 + -1892, ctx.r17.u32);
	// stw r16,-1888(r31)
	PPC_STORE_U32(ctx.r31.u32 + -1888, ctx.r16.u32);
	// lwz r11,-36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -36);
	// lwz r10,-32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -32);
	// stw r9,-68(r31)
	PPC_STORE_U32(ctx.r31.u32 + -68, ctx.r9.u32);
	// stw r11,4200(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4200, ctx.r11.u32);
	// stw r10,26428(r7)
	PPC_STORE_U32(ctx.r7.u32 + 26428, ctx.r10.u32);
	// lwz r11,-24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -24);
	// lwz r10,-20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -20);
	// stw r11,26272(r5)
	PPC_STORE_U32(ctx.r5.u32 + 26272, ctx.r11.u32);
	// stw r10,26276(r4)
	PPC_STORE_U32(ctx.r4.u32 + 26276, ctx.r10.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071178
	__restgprlr_16(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88136030"))) PPC_WEAK_FUNC(sub_88136030);
PPC_FUNC_IMPL(__imp__sub_88136030) {
	PPC_FUNC_PROLOGUE();
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,26280
	ctx.r11.s64 = ctx.r11.s64 + 26280;
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r9,r11,152
	ctx.r9.s64 = ctx.r11.s64 + 152;
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// lis r7,-30651
	ctx.r7.s64 = -2008743936;
	// stw r8,464(r11)
	PPC_STORE_U32(ctx.r11.u32 + 464, ctx.r8.u32);
	// addi r9,r9,-10888
	ctx.r9.s64 = ctx.r9.s64 + -10888;
	// stw r3,244(r11)
	PPC_STORE_U32(ctx.r11.u32 + 244, ctx.r3.u32);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// stw r10,220(r11)
	PPC_STORE_U32(ctx.r11.u32 + 220, ctx.r10.u32);
	// addi r8,r11,152
	ctx.r8.s64 = ctx.r11.s64 + 152;
	// stw r10,280(r11)
	PPC_STORE_U32(ctx.r11.u32 + 280, ctx.r10.u32);
	// addi r31,r7,-26112
	ctx.r31.s64 = ctx.r7.s64 + -26112;
	// stw r10,288(r11)
	PPC_STORE_U32(ctx.r11.u32 + 288, ctx.r10.u32);
	// li r8,-1
	ctx.r8.s64 = -1;
	// stw r10,460(r11)
	PPC_STORE_U32(ctx.r11.u32 + 460, ctx.r10.u32);
	// mr r6,r10
	ctx.r6.u64 = ctx.r10.u64;
	// sth r10,228(r11)
	PPC_STORE_U16(ctx.r11.u32 + 228, ctx.r10.u16);
	// addi r7,r11,152
	ctx.r7.s64 = ctx.r11.s64 + 152;
	// stb r10,519(r11)
	PPC_STORE_U8(ctx.r11.u32 + 519, ctx.r10.u8);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stw r10,256(r11)
	PPC_STORE_U32(ctx.r11.u32 + 256, ctx.r10.u32);
	// li r7,-1
	ctx.r7.s64 = -1;
	// stw r10,2012(r11)
	PPC_STORE_U32(ctx.r11.u32 + 2012, ctx.r10.u32);
	// li r5,-1
	ctx.r5.s64 = -1;
	// stw r10,1996(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1996, ctx.r10.u32);
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// stw r10,2000(r11)
	PPC_STORE_U32(ctx.r11.u32 + 2000, ctx.r10.u32);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// stw r10,2028(r11)
	PPC_STORE_U32(ctx.r11.u32 + 2028, ctx.r10.u32);
	// stw r10,2032(r11)
	PPC_STORE_U32(ctx.r11.u32 + 2032, ctx.r10.u32);
	// stw r10,2036(r11)
	PPC_STORE_U32(ctx.r11.u32 + 2036, ctx.r10.u32);
	// stw r10,2040(r11)
	PPC_STORE_U32(ctx.r11.u32 + 2040, ctx.r10.u32);
	// stb r10,2052(r11)
	PPC_STORE_U8(ctx.r11.u32 + 2052, ctx.r10.u8);
	// stb r10,2053(r11)
	PPC_STORE_U8(ctx.r11.u32 + 2053, ctx.r10.u8);
	// stb r10,2054(r11)
	PPC_STORE_U8(ctx.r11.u32 + 2054, ctx.r10.u8);
	// stb r10,2055(r11)
	PPC_STORE_U8(ctx.r11.u32 + 2055, ctx.r10.u8);
	// stb r10,2056(r11)
	PPC_STORE_U8(ctx.r11.u32 + 2056, ctx.r10.u8);
	// stb r10,2057(r11)
	PPC_STORE_U8(ctx.r11.u32 + 2057, ctx.r10.u8);
	// stb r10,2058(r11)
	PPC_STORE_U8(ctx.r11.u32 + 2058, ctx.r10.u8);
	// stb r10,2059(r11)
	PPC_STORE_U8(ctx.r11.u32 + 2059, ctx.r10.u8);
	// stb r10,2004(r11)
	PPC_STORE_U8(ctx.r11.u32 + 2004, ctx.r10.u8);
	// stb r10,2005(r11)
	PPC_STORE_U8(ctx.r11.u32 + 2005, ctx.r10.u8);
	// stb r10,2006(r11)
	PPC_STORE_U8(ctx.r11.u32 + 2006, ctx.r10.u8);
	// stb r10,2007(r11)
	PPC_STORE_U8(ctx.r11.u32 + 2007, ctx.r10.u8);
	// stb r10,2008(r11)
	PPC_STORE_U8(ctx.r11.u32 + 2008, ctx.r10.u8);
	// stw r8,-32(r9)
	PPC_STORE_U32(ctx.r9.u32 + -32, ctx.r8.u32);
	// lwz r8,32(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// stw r6,-36(r9)
	PPC_STORE_U32(ctx.r9.u32 + -36, ctx.r6.u32);
	// mr r6,r10
	ctx.r6.u64 = ctx.r10.u64;
	// stw r7,-40(r9)
	PPC_STORE_U32(ctx.r9.u32 + -40, ctx.r7.u32);
	// stw r5,-28(r9)
	PPC_STORE_U32(ctx.r9.u32 + -28, ctx.r5.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// stb r10,-44(r9)
	PPC_STORE_U8(ctx.r9.u32 + -44, ctx.r10.u8);
	// stw r10,-20(r9)
	PPC_STORE_U32(ctx.r9.u32 + -20, ctx.r10.u32);
	// stb r10,19(r31)
	PPC_STORE_U8(ctx.r31.u32 + 19, ctx.r10.u8);
	// stw r8,236(r11)
	PPC_STORE_U32(ctx.r11.u32 + 236, ctx.r8.u32);
	// stb r5,-49(r9)
	PPC_STORE_U8(ctx.r9.u32 + -49, ctx.r5.u8);
	// stb r8,-43(r9)
	PPC_STORE_U8(ctx.r9.u32 + -43, ctx.r8.u8);
	// lwz r7,244(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 244);
	// rlwinm r10,r7,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplwi cr6,r10,32
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 32, ctx.xer);
	// stb r7,-45(r9)
	PPC_STORE_U8(ctx.r9.u32 + -45, ctx.r7.u8);
	// bge cr6,0x8813616c
	if (!ctx.cr6.lt) goto loc_8813616C;
	// lwz r11,-4(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -4);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x8813616c
	if (!ctx.cr6.eq) goto loc_8813616C;
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r11,r11,26648
	ctx.r11.s64 = ctx.r11.s64 + 26648;
	// addi r7,r11,76
	ctx.r7.s64 = ctx.r11.s64 + 76;
	// addi r6,r11,80
	ctx.r6.s64 = ctx.r11.s64 + 80;
	// stwx r9,r10,r7
	PPC_STORE_U32(ctx.r10.u32 + ctx.r7.u32, ctx.r9.u32);
	// sthx r8,r10,r6
	PPC_STORE_U16(ctx.r10.u32 + ctx.r6.u32, ctx.r8.u16);
loc_8813616C:
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88136174"))) PPC_WEAK_FUNC(sub_88136174);
PPC_FUNC_IMPL(__imp__sub_88136174) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88136178"))) PPC_WEAK_FUNC(sub_88136178);
PPC_FUNC_IMPL(__imp__sub_88136178) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lis r11,-30651
	ctx.r11.s64 = -2008743936;
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// addi r4,r11,-26112
	ctx.r4.s64 = ctx.r11.s64 + -26112;
	// addi r11,r10,26432
	ctx.r11.s64 = ctx.r10.s64 + 26432;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// lbz r9,14(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 14);
	// mr r6,r10
	ctx.r6.u64 = ctx.r10.u64;
	// stw r7,140(r11)
	PPC_STORE_U32(ctx.r11.u32 + 140, ctx.r7.u32);
	// lis r31,-30597
	ctx.r31.s64 = -2005204992;
	// addi r9,r9,-18
	ctx.r9.s64 = ctx.r9.s64 + -18;
	// stw r10,312(r11)
	PPC_STORE_U32(ctx.r11.u32 + 312, ctx.r10.u32);
	// stw r10,136(r11)
	PPC_STORE_U32(ctx.r11.u32 + 136, ctx.r10.u32);
	// mr r5,r10
	ctx.r5.u64 = ctx.r10.u64;
	// addic r8,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r8.s64 = ctx.r9.s64 + -1;
	// stw r10,308(r11)
	PPC_STORE_U32(ctx.r11.u32 + 308, ctx.r10.u32);
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// stw r10,128(r11)
	PPC_STORE_U32(ctx.r11.u32 + 128, ctx.r10.u32);
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stb r10,367(r11)
	PPC_STORE_U8(ctx.r11.u32 + 367, ctx.r10.u8);
	// stw r10,104(r11)
	PPC_STORE_U32(ctx.r11.u32 + 104, ctx.r10.u32);
	// addi r5,r31,-10908
	ctx.r5.s64 = ctx.r31.s64 + -10908;
	// and r9,r6,r3
	ctx.r9.u64 = ctx.r6.u64 & ctx.r3.u64;
	// stw r10,1860(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1860, ctx.r10.u32);
	// stw r10,1844(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1844, ctx.r10.u32);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// stw r9,68(r11)
	PPC_STORE_U32(ctx.r11.u32 + 68, ctx.r9.u32);
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// stw r10,1848(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1848, ctx.r10.u32);
	// addi r9,r11,1900
	ctx.r9.s64 = ctx.r11.s64 + 1900;
	// stw r10,1876(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1876, ctx.r10.u32);
	// addi r9,r11,1904
	ctx.r9.s64 = ctx.r11.s64 + 1904;
	// stw r10,1880(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1880, ctx.r10.u32);
	// addi r9,r11,1852
	ctx.r9.s64 = ctx.r11.s64 + 1852;
	// stw r10,1884(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1884, ctx.r10.u32);
	// li r9,-1
	ctx.r9.s64 = -1;
	// stw r10,1888(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1888, ctx.r10.u32);
	// li r8,-1
	ctx.r8.s64 = -1;
	// stb r10,1900(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1900, ctx.r10.u8);
	// li r7,-1
	ctx.r7.s64 = -1;
	// stb r10,1901(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1901, ctx.r10.u8);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// stb r10,1902(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1902, ctx.r10.u8);
	// mr r6,r10
	ctx.r6.u64 = ctx.r10.u64;
	// stb r10,1903(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1903, ctx.r10.u8);
	// stb r10,1904(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1904, ctx.r10.u8);
	// stb r10,1905(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1905, ctx.r10.u8);
	// stb r10,1906(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1906, ctx.r10.u8);
	// stb r10,1907(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1907, ctx.r10.u8);
	// stb r10,1852(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1852, ctx.r10.u8);
	// stb r10,1853(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1853, ctx.r10.u8);
	// stb r10,1854(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1854, ctx.r10.u8);
	// stw r9,-12(r5)
	PPC_STORE_U32(ctx.r5.u32 + -12, ctx.r9.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// stb r10,1855(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1855, ctx.r10.u8);
	// stb r10,1856(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1856, ctx.r10.u8);
	// stw r8,-20(r5)
	PPC_STORE_U32(ctx.r5.u32 + -20, ctx.r8.u32);
	// stw r8,-16(r5)
	PPC_STORE_U32(ctx.r5.u32 + -16, ctx.r8.u32);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// stb r10,-24(r5)
	PPC_STORE_U8(ctx.r5.u32 + -24, ctx.r10.u8);
	// stw r7,-8(r5)
	PPC_STORE_U32(ctx.r5.u32 + -8, ctx.r7.u32);
	// stw r10,-10908(r31)
	PPC_STORE_U32(ctx.r31.u32 + -10908, ctx.r10.u32);
	// stb r9,-29(r5)
	PPC_STORE_U8(ctx.r5.u32 + -29, ctx.r9.u8);
	// stb r10,19(r4)
	PPC_STORE_U8(ctx.r4.u32 + 19, ctx.r10.u8);
	// sth r10,76(r11)
	PPC_STORE_U16(ctx.r11.u32 + 76, ctx.r10.u16);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813628C"))) PPC_WEAK_FUNC(sub_8813628C);
PPC_FUNC_IMPL(__imp__sub_8813628C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88136290"))) PPC_WEAK_FUNC(sub_88136290);
PPC_FUNC_IMPL(__imp__sub_88136290) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// li r5,1928
	ctx.r5.s64 = 1928;
	// addi r3,r11,26432
	ctx.r3.s64 = ctx.r11.s64 + 26432;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x88073bd0
	ctx.lr = 0x881362B0;
	sub_88073BD0(ctx, base);
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,-12784(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12784, ctx.r11.u32);
	// bl 0x88133b68
	ctx.lr = 0x881362C0;
	sub_88133B68(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881362D0"))) PPC_WEAK_FUNC(sub_881362D0);
PPC_FUNC_IMPL(__imp__sub_881362D0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// bl 0x88133e30
	ctx.lr = 0x881362F0;
	sub_88133E30(ctx, base);
	// lbz r9,1(r30)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r30.u32 + 1);
	// li r10,0
	ctx.r10.s64 = 0;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// mulli r11,r8,196
	ctx.r11.s64 = ctx.r8.s64 * 196;
	// add r7,r11,r31
	ctx.r7.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stb r10,1448(r7)
	PPC_STORE_U8(ctx.r7.u32 + 1448, ctx.r10.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88136320"))) PPC_WEAK_FUNC(sub_88136320);
PPC_FUNC_IMPL(__imp__sub_88136320) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r10,r11,26432
	ctx.r10.s64 = ctx.r11.s64 + 26432;
	// lwz r3,12(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// b 0x88152b00
	sub_88152B00(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88136330"))) PPC_WEAK_FUNC(sub_88136330);
PPC_FUNC_IMPL(__imp__sub_88136330) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// bl 0x88152c60
	ctx.lr = 0x8813634C;
	sub_88152C60(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88136368"))) PPC_WEAK_FUNC(sub_88136368);
PPC_FUNC_IMPL(__imp__sub_88136368) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x88136370;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r31,r3,1448
	ctx.r31.s64 = ctx.r3.s64 + 1448;
	// addi r29,r3,52
	ctx.r29.s64 = ctx.r3.s64 + 52;
	// li r30,2
	ctx.r30.s64 = 2;
loc_8813638C:
	// lbz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x881363c0
	if (ctx.cr6.eq) goto loc_881363C0;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x88152b00
	ctx.lr = 0x881363A4;
	sub_88152B00(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x881363c0
	if (ctx.cr6.eq) goto loc_881363C0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mtctr r28
	ctx.ctr.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bctrl 
	ctx.lr = 0x881363BC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r6,1
	ctx.r6.s64 = 1;
loc_881363C0:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r31,r31,196
	ctx.r31.s64 = ctx.r31.s64 + 196;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// bne 0x8813638c
	if (!ctx.cr0.eq) goto loc_8813638C;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_881363DC"))) PPC_WEAK_FUNC(sub_881363DC);
PPC_FUNC_IMPL(__imp__sub_881363DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881363E0"))) PPC_WEAK_FUNC(sub_881363E0);
PPC_FUNC_IMPL(__imp__sub_881363E0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x881363E8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r31,r3,1448
	ctx.r31.s64 = ctx.r3.s64 + 1448;
	// addi r29,r3,52
	ctx.r29.s64 = ctx.r3.s64 + 52;
	// li r30,2
	ctx.r30.s64 = 2;
loc_88136404:
	// lbz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88136444
	if (ctx.cr6.eq) goto loc_88136444;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x88152b00
	ctx.lr = 0x8813641C;
	sub_88152B00(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x88136444
	if (ctx.cr6.eq) goto loc_88136444;
	// lwz r11,136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 136);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88136444
	if (!ctx.cr6.eq) goto loc_88136444;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mtctr r28
	ctx.ctr.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bctrl 
	ctx.lr = 0x88136440;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r6,1
	ctx.r6.s64 = 1;
loc_88136444:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r31,r31,196
	ctx.r31.s64 = ctx.r31.s64 + 196;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// bne 0x88136404
	if (!ctx.cr0.eq) goto loc_88136404;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88136460"))) PPC_WEAK_FUNC(sub_88136460);
PPC_FUNC_IMPL(__imp__sub_88136460) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-30643
	ctx.r31.s64 = -2008219648;
	// addi r30,r31,26432
	ctx.r30.s64 = ctx.r31.s64 + 26432;
	// lwz r3,26432(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 26432);
	// bl 0x88152c60
	ctx.lr = 0x88136484;
	sub_88152C60(ctx, base);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x88152c60
	ctx.lr = 0x8813648C;
	sub_88152C60(ctx, base);
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// bl 0x88152c60
	ctx.lr = 0x88136494;
	sub_88152C60(ctx, base);
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// bl 0x88152c60
	ctx.lr = 0x8813649C;
	sub_88152C60(ctx, base);
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// bl 0x88152c60
	ctx.lr = 0x881364A4;
	sub_88152C60(ctx, base);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// bl 0x88152c60
	ctx.lr = 0x881364AC;
	sub_88152C60(ctx, base);
	// lwz r3,24(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// bl 0x88152c60
	ctx.lr = 0x881364B4;
	sub_88152C60(ctx, base);
	// lwz r3,28(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	// bl 0x88152c60
	ctx.lr = 0x881364BC;
	sub_88152C60(ctx, base);
	// lwz r3,32(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// bl 0x88152c60
	ctx.lr = 0x881364C4;
	sub_88152C60(ctx, base);
	// lwz r3,36(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// bl 0x88152c60
	ctx.lr = 0x881364CC;
	sub_88152C60(ctx, base);
	// lwz r3,40(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 40);
	// bl 0x88152c60
	ctx.lr = 0x881364D4;
	sub_88152C60(ctx, base);
	// lwz r3,48(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 48);
	// bl 0x88152c60
	ctx.lr = 0x881364DC;
	sub_88152C60(ctx, base);
	// lwz r3,52(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 52);
	// bl 0x88152c60
	ctx.lr = 0x881364E4;
	sub_88152C60(ctx, base);
	// lwz r3,56(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 56);
	// bl 0x88152c60
	ctx.lr = 0x881364EC;
	sub_88152C60(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,26432(r31)
	PPC_STORE_U32(ctx.r31.u32 + 26432, ctx.r11.u32);
	// stw r10,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r10.u32);
	// stw r9,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r9.u32);
	// stw r11,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r11.u32);
	// stw r10,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r10.u32);
	// stw r9,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r9.u32);
	// stw r11,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r11.u32);
	// stw r10,28(r30)
	PPC_STORE_U32(ctx.r30.u32 + 28, ctx.r10.u32);
	// stw r9,32(r30)
	PPC_STORE_U32(ctx.r30.u32 + 32, ctx.r9.u32);
	// stw r11,36(r30)
	PPC_STORE_U32(ctx.r30.u32 + 36, ctx.r11.u32);
	// stw r10,40(r30)
	PPC_STORE_U32(ctx.r30.u32 + 40, ctx.r10.u32);
	// stw r9,48(r30)
	PPC_STORE_U32(ctx.r30.u32 + 48, ctx.r9.u32);
	// stw r11,52(r30)
	PPC_STORE_U32(ctx.r30.u32 + 52, ctx.r11.u32);
	// stw r10,56(r30)
	PPC_STORE_U32(ctx.r30.u32 + 56, ctx.r10.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88136548"))) PPC_WEAK_FUNC(sub_88136548);
PPC_FUNC_IMPL(__imp__sub_88136548) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r31,r11,26432
	ctx.r31.s64 = ctx.r11.s64 + 26432;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// bl 0x88152c60
	ctx.lr = 0x88136568;
	sub_88152C60(ctx, base);
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// bl 0x88152c60
	ctx.lr = 0x88136570;
	sub_88152C60(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// stw r10,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r10.u32);
	// bl 0x88152c60
	ctx.lr = 0x88136588;
	sub_88152C60(ctx, base);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// bl 0x88152c60
	ctx.lr = 0x88136590;
	sub_88152C60(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88152c60
	ctx.lr = 0x88136598;
	sub_88152C60(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// stw r9,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r9.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881365C4"))) PPC_WEAK_FUNC(sub_881365C4);
PPC_FUNC_IMPL(__imp__sub_881365C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881365C8"))) PPC_WEAK_FUNC(sub_881365C8);
PPC_FUNC_IMPL(__imp__sub_881365C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x881365D0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r6,r11,28376
	ctx.r6.s64 = ctx.r11.s64 + 28376;
	// lwz r3,-1892(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -1892);
	// bl 0x88152b00
	ctx.lr = 0x881365E4;
	sub_88152B00(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-1888(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -1888);
	// addic r9,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// subfe r11,r9,r10
	temp.u8 = (~ctx.r9.u32 + ctx.r10.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r9.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r11,-52(r6)
	PPC_STORE_U32(ctx.r6.u32 + -52, ctx.r11.u32);
	// bl 0x88152b00
	ctx.lr = 0x881365FC;
	sub_88152B00(ctx, base);
	// lis r8,-30671
	ctx.r8.s64 = -2010054656;
	// lis r7,-30643
	ctx.r7.s64 = -2008219648;
	// lis r5,-30643
	ctx.r5.s64 = -2008219648;
	// lis r31,-30643
	ctx.r31.s64 = -2008219648;
	// lis r30,-30643
	ctx.r30.s64 = -2008219648;
	// lwz r11,4200(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4200);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r10,26428(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 26428);
	// addi r4,r6,-1944
	ctx.r4.s64 = ctx.r6.s64 + -1944;
	// lwz r9,26424(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 26424);
	// addic r5,r3,-1
	ctx.xer.ca = ctx.r3.u32 > 0;
	ctx.r5.s64 = ctx.r3.s64 + -1;
	// lwz r8,26272(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 26272);
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// lwz r7,26276(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 26276);
	// subfe r5,r5,r29
	temp.u8 = (~ctx.r5.u32 + ctx.r29.u32 < ~ctx.r5.u32) | (~ctx.r5.u32 + ctx.r29.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r5.u64 = ~ctx.r5.u64 + ctx.r29.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r11,-36(r6)
	PPC_STORE_U32(ctx.r6.u32 + -36, ctx.r11.u32);
	// stw r5,-48(r6)
	PPC_STORE_U32(ctx.r6.u32 + -48, ctx.r5.u32);
	// li r5,1928
	ctx.r5.s64 = 1928;
	// stw r10,-32(r6)
	PPC_STORE_U32(ctx.r6.u32 + -32, ctx.r10.u32);
	// stw r9,-28(r6)
	PPC_STORE_U32(ctx.r6.u32 + -28, ctx.r9.u32);
	// stw r8,-24(r6)
	PPC_STORE_U32(ctx.r6.u32 + -24, ctx.r8.u32);
	// stw r7,-20(r6)
	PPC_STORE_U32(ctx.r6.u32 + -20, ctx.r7.u32);
	// bl 0x88072260
	ctx.lr = 0x88136658;
	sub_88072260(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88136660"))) PPC_WEAK_FUNC(sub_88136660);
PPC_FUNC_IMPL(__imp__sub_88136660) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// li r11,1
	ctx.r11.s64 = 1;
	// addi r5,r10,26432
	ctx.r5.s64 = ctx.r10.s64 + 26432;
	// lwz r10,1860(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 1860);
	// stw r11,352(r5)
	PPC_STORE_U32(ctx.r5.u32 + 352, ctx.r11.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lis r11,-30701
	ctx.r11.s64 = -2012020736;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// addi r4,r11,25296
	ctx.r4.s64 = ctx.r11.s64 + 25296;
	// b 0x88135ba8
	sub_88135BA8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8813668C"))) PPC_WEAK_FUNC(sub_8813668C);
PPC_FUNC_IMPL(__imp__sub_8813668C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88136690"))) PPC_WEAK_FUNC(sub_88136690);
PPC_FUNC_IMPL(__imp__sub_88136690) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r6,r11,26432
	ctx.r6.s64 = ctx.r11.s64 + 26432;
	// lwz r3,12(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// bl 0x88152b00
	ctx.lr = 0x881366AC;
	sub_88152B00(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// bne cr6,0x881366bc
	if (!ctx.cr6.eq) goto loc_881366BC;
	// lwz r3,304(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 304);
loc_881366BC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881366CC"))) PPC_WEAK_FUNC(sub_881366CC);
PPC_FUNC_IMPL(__imp__sub_881366CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881366D0"))) PPC_WEAK_FUNC(sub_881366D0);
PPC_FUNC_IMPL(__imp__sub_881366D0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r6,r11,26432
	ctx.r6.s64 = ctx.r11.s64 + 26432;
	// lwz r3,12(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// bl 0x88152b00
	ctx.lr = 0x881366F4;
	sub_88152B00(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88136764
	if (!ctx.cr6.eq) goto loc_88136764;
	// lwz r11,304(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 304);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88136764
	if (!ctx.cr6.eq) goto loc_88136764;
	// lwz r11,312(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 312);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88136764
	if (!ctx.cr6.eq) goto loc_88136764;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r6,60
	ctx.r9.s64 = ctx.r6.s64 + 60;
	// lwzx r11,r10,r9
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88136764
	if (!ctx.cr6.eq) goto loc_88136764;
	// lwz r11,308(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 308);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8813673c
	if (ctx.cr6.eq) goto loc_8813673C;
	// ori r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 2;
	// b 0x88136740
	goto loc_88136740;
loc_8813673C:
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
loc_88136740:
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r11,308(r6)
	PPC_STORE_U32(ctx.r6.u32 + 308, ctx.r11.u32);
	// mulli r11,r31,196
	ctx.r11.s64 = ctx.r31.s64 * 196;
	// stwx r8,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r8.u32);
	// addi r10,r6,1448
	ctx.r10.s64 = ctx.r6.s64 + 1448;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x88134658
	ctx.lr = 0x8813675C;
	sub_88134658(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880920e0
	ctx.lr = 0x88136764;
	sub_880920E0(ctx, base);
loc_88136764:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88136778"))) PPC_WEAK_FUNC(sub_88136778);
PPC_FUNC_IMPL(__imp__sub_88136778) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x88136780;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r5,r11,26432
	ctx.r5.s64 = ctx.r11.s64 + 26432;
	// lwz r3,44(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 44);
	// bl 0x88152b00
	ctx.lr = 0x88136794;
	sub_88152B00(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88136884
	if (!ctx.cr6.eq) goto loc_88136884;
	// lis r11,-30642
	ctx.r11.s64 = -2008154112;
	// addi r10,r5,376
	ctx.r10.s64 = ctx.r5.s64 + 376;
	// addi r8,r11,31024
	ctx.r8.s64 = ctx.r11.s64 + 31024;
	// addi r11,r8,4
	ctx.r11.s64 = ctx.r8.s64 + 4;
loc_881367AC:
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_881367B4:
	// lwz r7,8(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r6,-8(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8);
	// rlwimi r9,r7,4,0,27
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r7.u32, 4) & 0xFFFFFFF0) | (ctx.r9.u64 & 0xFFFFFFFF0000000F);
	// lwz r4,-4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r7,12(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r31,16(r10)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r30,20(r10)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// lbz r29,24(r10)
	ctx.r29.u64 = PPC_LOAD_U8(ctx.r10.u32 + 24);
	// lbz r28,25(r10)
	ctx.r28.u64 = PPC_LOAD_U8(ctx.r10.u32 + 25);
	// lbz r27,26(r10)
	ctx.r27.u64 = PPC_LOAD_U8(ctx.r10.u32 + 26);
	// lbz r26,27(r10)
	ctx.r26.u64 = PPC_LOAD_U8(ctx.r10.u32 + 27);
	// addi r10,r10,36
	ctx.r10.s64 = ctx.r10.s64 + 36;
	// stw r6,-4(r11)
	PPC_STORE_U32(ctx.r11.u32 + -4, ctx.r6.u32);
	// stb r4,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r4.u8);
	// stb r3,1(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1, ctx.r3.u8);
	// stb r9,2(r11)
	PPC_STORE_U8(ctx.r11.u32 + 2, ctx.r9.u8);
	// stb r7,3(r11)
	PPC_STORE_U8(ctx.r11.u32 + 3, ctx.r7.u8);
	// stb r31,4(r11)
	PPC_STORE_U8(ctx.r11.u32 + 4, ctx.r31.u8);
	// stb r30,5(r11)
	PPC_STORE_U8(ctx.r11.u32 + 5, ctx.r30.u8);
	// stb r29,6(r11)
	PPC_STORE_U8(ctx.r11.u32 + 6, ctx.r29.u8);
	// stb r28,7(r11)
	PPC_STORE_U8(ctx.r11.u32 + 7, ctx.r28.u8);
	// stb r27,8(r11)
	PPC_STORE_U8(ctx.r11.u32 + 8, ctx.r27.u8);
	// stb r26,9(r11)
	PPC_STORE_U8(ctx.r11.u32 + 9, ctx.r26.u8);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// bdnz 0x881367b4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_881367B4;
	// addi r9,r8,484
	ctx.r9.s64 = ctx.r8.s64 + 484;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x881367ac
	if (ctx.cr6.lt) goto loc_881367AC;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r11,352(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 352);
	// addi r9,r10,-10940
	ctx.r9.s64 = ctx.r10.s64 + -10940;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// sth r10,78(r5)
	PPC_STORE_U16(ctx.r5.u32 + 78, ctx.r10.u16);
	// beq cr6,0x88136878
	if (ctx.cr6.eq) goto loc_88136878;
	// li r11,5
	ctx.r11.s64 = 5;
	// lis r8,-30686
	ctx.r8.s64 = -2011037696;
	// sth r11,76(r5)
	PPC_STORE_U16(ctx.r5.u32 + 76, ctx.r11.u16);
	// li r4,46
	ctx.r4.s64 = 46;
	// stb r11,6(r9)
	PPC_STORE_U8(ctx.r9.u32 + 6, ctx.r11.u8);
	// addi r3,r8,29024
	ctx.r3.s64 = ctx.r8.s64 + 29024;
	// bl 0x881526c0
	ctx.lr = 0x88136864;
	sub_881526C0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r3,40(r5)
	PPC_STORE_U32(ctx.r5.u32 + 40, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_88136878:
	// li r11,8
	ctx.r11.s64 = 8;
	// sth r11,76(r5)
	PPC_STORE_U16(ctx.r5.u32 + 76, ctx.r11.u16);
	// stb r11,6(r9)
	PPC_STORE_U8(ctx.r9.u32 + 6, ctx.r11.u8);
loc_88136884:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88136890"))) PPC_WEAK_FUNC(sub_88136890);
PPC_FUNC_IMPL(__imp__sub_88136890) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r31,r11,26432
	ctx.r31.s64 = ctx.r11.s64 + 26432;
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// bl 0x88152b00
	ctx.lr = 0x881368B0;
	sub_88152B00(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8813695c
	if (!ctx.cr6.eq) goto loc_8813695C;
	// lwz r11,352(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 352);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88136938
	if (!ctx.cr6.eq) goto loc_88136938;
	// lwz r11,1860(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1860);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88136938
	if (!ctx.cr6.eq) goto loc_88136938;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// bl 0x88152c60
	ctx.lr = 0x881368D8;
	sub_88152C60(ctx, base);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// bl 0x88152c60
	ctx.lr = 0x881368E0;
	sub_88152C60(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88152c60
	ctx.lr = 0x881368E8;
	sub_88152C60(ctx, base);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x88152c60
	ctx.lr = 0x881368F0;
	sub_88152C60(ctx, base);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x88152c60
	ctx.lr = 0x881368F8;
	sub_88152C60(ctx, base);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// bl 0x88152c60
	ctx.lr = 0x88136900;
	sub_88152C60(ctx, base);
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// li r11,6
	ctx.r11.s64 = 6;
	// addi r9,r10,-10940
	ctx.r9.s64 = ctx.r10.s64 + -10940;
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r11,76(r31)
	PPC_STORE_U16(ctx.r31.u32 + 76, ctx.r11.u16);
	// lis r8,-30704
	ctx.r8.s64 = -2012217344;
	// sth r10,78(r31)
	PPC_STORE_U16(ctx.r31.u32 + 78, ctx.r10.u16);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// li r4,47
	ctx.r4.s64 = 47;
	// stb r11,6(r9)
	PPC_STORE_U8(ctx.r9.u32 + 6, ctx.r11.u8);
	// addi r3,r8,-17656
	ctx.r3.s64 = ctx.r8.s64 + -17656;
	// bl 0x881526c0
	ctx.lr = 0x88136930;
	sub_881526C0(ctx, base);
	// stw r3,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r3.u32);
	// b 0x88136954
	goto loc_88136954;
loc_88136938:
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// li r11,8
	ctx.r11.s64 = 8;
	// addi r9,r10,-10940
	ctx.r9.s64 = ctx.r10.s64 + -10940;
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r11,76(r31)
	PPC_STORE_U16(ctx.r31.u32 + 76, ctx.r11.u16);
	// sth r10,78(r31)
	PPC_STORE_U16(ctx.r31.u32 + 78, ctx.r10.u16);
	// stb r11,6(r9)
	PPC_STORE_U8(ctx.r9.u32 + 6, ctx.r11.u8);
loc_88136954:
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x8808d268
	ctx.lr = 0x8813695C;
	sub_8808D268(ctx, base);
loc_8813695C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88136974"))) PPC_WEAK_FUNC(sub_88136974);
PPC_FUNC_IMPL(__imp__sub_88136974) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88136978"))) PPC_WEAK_FUNC(sub_88136978);
PPC_FUNC_IMPL(__imp__sub_88136978) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r31,r11,26432
	ctx.r31.s64 = ctx.r11.s64 + 26432;
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// bl 0x88152b00
	ctx.lr = 0x88136998;
	sub_88152B00(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88136a3c
	if (!ctx.cr6.eq) goto loc_88136A3C;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// bl 0x88152c60
	ctx.lr = 0x881369A8;
	sub_88152C60(ctx, base);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// bl 0x88152c60
	ctx.lr = 0x881369B0;
	sub_88152C60(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88152c60
	ctx.lr = 0x881369B8;
	sub_88152C60(ctx, base);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x88152c60
	ctx.lr = 0x881369C0;
	sub_88152C60(ctx, base);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x88152c60
	ctx.lr = 0x881369C8;
	sub_88152C60(ctx, base);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// bl 0x88152c60
	ctx.lr = 0x881369D0;
	sub_88152C60(ctx, base);
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r11,1860(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1860);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r9,r10,-10940
	ctx.r9.s64 = ctx.r10.s64 + -10940;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// sth r10,78(r31)
	PPC_STORE_U16(ctx.r31.u32 + 78, ctx.r10.u16);
	// bne cr6,0x88136a18
	if (!ctx.cr6.eq) goto loc_88136A18;
	// li r11,6
	ctx.r11.s64 = 6;
	// lis r8,-30704
	ctx.r8.s64 = -2012217344;
	// sth r11,76(r31)
	PPC_STORE_U16(ctx.r31.u32 + 76, ctx.r11.u16);
	// li r4,47
	ctx.r4.s64 = 47;
	// stb r11,6(r9)
	PPC_STORE_U8(ctx.r9.u32 + 6, ctx.r11.u8);
	// addi r3,r8,-17656
	ctx.r3.s64 = ctx.r8.s64 + -17656;
	// bl 0x881526c0
	ctx.lr = 0x88136A0C;
	sub_881526C0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r3,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r3.u32);
	// b 0x88136a3c
	goto loc_88136A3C;
loc_88136A18:
	// li r11,5
	ctx.r11.s64 = 5;
	// lis r8,-30686
	ctx.r8.s64 = -2011037696;
	// sth r11,76(r31)
	PPC_STORE_U16(ctx.r31.u32 + 76, ctx.r11.u16);
	// li r4,46
	ctx.r4.s64 = 46;
	// stb r11,6(r9)
	PPC_STORE_U8(ctx.r9.u32 + 6, ctx.r11.u8);
	// addi r3,r8,29024
	ctx.r3.s64 = ctx.r8.s64 + 29024;
	// bl 0x881526c0
	ctx.lr = 0x88136A34;
	sub_881526C0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r3,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r3.u32);
loc_88136A3C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88136A54"))) PPC_WEAK_FUNC(sub_88136A54);
PPC_FUNC_IMPL(__imp__sub_88136A54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88136A58"))) PPC_WEAK_FUNC(sub_88136A58);
PPC_FUNC_IMPL(__imp__sub_88136A58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88136A60;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30701
	ctx.r11.s64 = -2012020736;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r11,24192
	ctx.r4.s64 = ctx.r11.s64 + 24192;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x88135ba8
	ctx.lr = 0x88136A78;
	sub_88135BA8(ctx, base);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// bl 0x88152c60
	ctx.lr = 0x88136A80;
	sub_88152C60(ctx, base);
	// lwz r9,100(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r8,92(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// lis r10,-30701
	ctx.r10.s64 = -2012020736;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// li r4,43
	ctx.r4.s64 = 43;
	// addi r3,r10,9672
	ctx.r3.s64 = ctx.r10.s64 + 9672;
	// stw r9,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r9.u32);
	// stw r8,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r8.u32);
	// bl 0x881526c0
	ctx.lr = 0x88136AA4;
	sub_881526C0(ctx, base);
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r3,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r3.u32);
	// addi r29,r11,-10888
	ctx.r29.s64 = ctx.r11.s64 + -10888;
	// stw r30,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r30.u32);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// lis r7,-30679
	ctx.r7.s64 = -2010578944;
	// lis r6,-30643
	ctx.r6.s64 = -2008219648;
	// addi r5,r7,-13424
	ctx.r5.s64 = ctx.r7.s64 + -13424;
	// stb r30,-44(r29)
	PPC_STORE_U8(ctx.r29.u32 + -44, ctx.r30.u8);
	// stw r30,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r30.u32);
	// stw r30,172(r31)
	PPC_STORE_U32(ctx.r31.u32 + 172, ctx.r30.u32);
	// stw r30,176(r31)
	PPC_STORE_U32(ctx.r31.u32 + 176, ctx.r30.u32);
	// stw r30,180(r31)
	PPC_STORE_U32(ctx.r31.u32 + 180, ctx.r30.u32);
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r4,88(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r11,r3,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwzx r11,r11,r5
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r5.u32);
	// stw r11,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r11.u32);
	// stb r11,-42(r29)
	PPC_STORE_U8(ctx.r29.u32 + -42, ctx.r11.u8);
	// stw r11,26424(r6)
	PPC_STORE_U32(ctx.r6.u32 + 26424, ctx.r11.u32);
	// bl 0x88132858
	ctx.lr = 0x88136B08;
	sub_88132858(ctx, base);
	// lis r7,-30643
	ctx.r7.s64 = -2008219648;
	// lis r6,-30642
	ctx.r6.s64 = -2008154112;
	// li r11,128
	ctx.r11.s64 = 128;
	// addi r5,r7,32244
	ctx.r5.s64 = ctx.r7.s64 + 32244;
	// addi r8,r6,-21272
	ctx.r8.s64 = ctx.r6.s64 + -21272;
	// li r9,1
	ctx.r9.s64 = 1;
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// addi r8,r8,-40
	ctx.r8.s64 = ctx.r8.s64 + -40;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stw r30,-5508(r5)
	PPC_STORE_U32(ctx.r5.u32 + -5508, ctx.r30.u32);
	// stw r9,32244(r7)
	PPC_STORE_U32(ctx.r7.u32 + 32244, ctx.r9.u32);
loc_88136B34:
	// stbu r30,40(r8)
	ea = 40 + ctx.r8.u32;
	PPC_STORE_U8(ea, ctx.r30.u8);
	ctx.r8.u32 = ea;
	// bdnz 0x88136b34
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88136B34;
	// lis r10,-30642
	ctx.r10.s64 = -2008154112;
	// lis r9,-30642
	ctx.r9.s64 = -2008154112;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,-16152(r10)
	PPC_STORE_U32(ctx.r10.u32 + -16152, ctx.r30.u32);
	// stw r30,-21276(r9)
	PPC_STORE_U32(ctx.r9.u32 + -21276, ctx.r30.u32);
	// bl 0x8815caf0
	ctx.lr = 0x88136B54;
	sub_8815CAF0(ctx, base);
	// lis r8,-30643
	ctx.r8.s64 = -2008219648;
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// lis r7,-30671
	ctx.r7.s64 = -2010054656;
	// lwz r11,26268(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 26268);
	// lwz r10,4200(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4200);
	// addic r6,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r6.s64 = ctx.r11.s64 + -1;
	// stb r3,-45(r29)
	PPC_STORE_U8(ctx.r29.u32 + -45, ctx.r3.u8);
	// subfe r4,r5,r5
	temp.u8 = (~ctx.r5.u32 + ctx.r5.u32 < ~ctx.r5.u32) | (~ctx.r5.u32 + ctx.r5.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r4.u64 = ~ctx.r5.u64 + ctx.r5.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r4,r10
	ctx.r11.u64 = ctx.r4.u64 & ctx.r10.u64;
	// stw r11,4200(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4200, ctx.r11.u32);
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplwi cr6,r11,32
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32, ctx.xer);
	// bge cr6,0x88136bbc
	if (!ctx.cr6.lt) goto loc_88136BBC;
	// lwz r10,-4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + -4);
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// bne cr6,0x88136bbc
	if (!ctx.cr6.eq) goto loc_88136BBC;
	// lis r8,-30628
	ctx.r8.s64 = -2007236608;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// rlwinm r7,r11,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r9,4(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// addi r11,r8,26648
	ctx.r11.s64 = ctx.r8.s64 + 26648;
	// addi r5,r11,76
	ctx.r5.s64 = ctx.r11.s64 + 76;
	// addi r4,r11,80
	ctx.r4.s64 = ctx.r11.s64 + 80;
	// stwx r9,r7,r5
	PPC_STORE_U32(ctx.r7.u32 + ctx.r5.u32, ctx.r9.u32);
	// sthx r10,r7,r4
	PPC_STORE_U16(ctx.r7.u32 + ctx.r4.u32, ctx.r10.u16);
loc_88136BBC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88136BC4"))) PPC_WEAK_FUNC(sub_88136BC4);
PPC_FUNC_IMPL(__imp__sub_88136BC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88136BC8"))) PPC_WEAK_FUNC(sub_88136BC8);
PPC_FUNC_IMPL(__imp__sub_88136BC8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88136BD0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// cmplwi cr6,r4,5
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 5, ctx.xer);
	// bgt cr6,0x88136c50
	if (ctx.cr6.gt) goto loc_88136C50;
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,32244(r10)
	PPC_STORE_U32(ctx.r10.u32 + 32244, ctx.r11.u32);
	// bl 0x88095120
	ctx.lr = 0x88136BF4;
	sub_88095120(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x88152b00
	ctx.lr = 0x88136BFC;
	sub_88152B00(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88136c50
	if (!ctx.cr6.eq) goto loc_88136C50;
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// cmplwi cr6,r29,5
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 5, ctx.xer);
	// addi r30,r11,-10908
	ctx.r30.s64 = ctx.r11.s64 + -10908;
	// bge cr6,0x88136c24
	if (!ctx.cr6.lt) goto loc_88136C24;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r10,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r10.u32);
	// stb r11,-24(r30)
	PPC_STORE_U8(ctx.r30.u32 + -24, ctx.r11.u8);
loc_88136C24:
	// stw r29,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r29.u32);
	// lis r11,-30699
	ctx.r11.s64 = -2011889664;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// li r4,44
	ctx.r4.s64 = 44;
	// addi r3,r11,-520
	ctx.r3.s64 = ctx.r11.s64 + -520;
	// bl 0x881526c0
	ctx.lr = 0x88136C3C;
	sub_881526C0(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// stb r10,-29(r30)
	PPC_STORE_U8(ctx.r30.u32 + -29, ctx.r10.u8);
loc_88136C50:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88136C58"))) PPC_WEAK_FUNC(sub_88136C58);
PPC_FUNC_IMPL(__imp__sub_88136C58) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x88155298
	ctx.lr = 0x88136C6C;
	sub_88155298(ctx, base);
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lis r10,-30690
	ctx.r10.s64 = -2011299840;
	// addi r31,r11,26432
	ctx.r31.s64 = ctx.r11.s64 + 26432;
	// li r4,34
	ctx.r4.s64 = 34;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r3,r10,11352
	ctx.r3.s64 = ctx.r10.s64 + 11352;
	// bl 0x881526c0
	ctx.lr = 0x88136C88;
	sub_881526C0(ctx, base);
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// lis r9,-30690
	ctx.r9.s64 = -2011299840;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,38
	ctx.r4.s64 = 38;
	// addi r3,r9,28720
	ctx.r3.s64 = ctx.r9.s64 + 28720;
	// bl 0x881526c0
	ctx.lr = 0x88136CA0;
	sub_881526C0(ctx, base);
	// stw r3,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r3.u32);
	// lis r8,-30698
	ctx.r8.s64 = -2011824128;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// li r4,35
	ctx.r4.s64 = 35;
	// addi r3,r8,9744
	ctx.r3.s64 = ctx.r8.s64 + 9744;
	// bl 0x881526c0
	ctx.lr = 0x88136CB8;
	sub_881526C0(ctx, base);
	// stw r3,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88136CD0"))) PPC_WEAK_FUNC(sub_88136CD0);
PPC_FUNC_IMPL(__imp__sub_88136CD0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x88135f38
	ctx.lr = 0x88136CE4;
	sub_88135F38(ctx, base);
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r31,r11,28376
	ctx.r31.s64 = ctx.r11.s64 + 28376;
	// lwz r11,1892(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1892);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88136d14
	if (ctx.cr6.eq) goto loc_88136D14;
	// addi r11,r31,-1944
	ctx.r11.s64 = ctx.r31.s64 + -1944;
	// lis r10,-30699
	ctx.r10.s64 = -2011889664;
	// li r4,40
	ctx.r4.s64 = 40;
	// addi r5,r11,1448
	ctx.r5.s64 = ctx.r11.s64 + 1448;
	// addi r3,r10,-8760
	ctx.r3.s64 = ctx.r10.s64 + -8760;
	// bl 0x881526c0
	ctx.lr = 0x88136D10;
	sub_881526C0(ctx, base);
	// stw r3,-1892(r31)
	PPC_STORE_U32(ctx.r31.u32 + -1892, ctx.r3.u32);
loc_88136D14:
	// lwz r11,1896(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1896);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88136d3c
	if (ctx.cr6.eq) goto loc_88136D3C;
	// addi r11,r31,-1944
	ctx.r11.s64 = ctx.r31.s64 + -1944;
	// lis r10,-30699
	ctx.r10.s64 = -2011889664;
	// li r4,39
	ctx.r4.s64 = 39;
	// addi r5,r11,1644
	ctx.r5.s64 = ctx.r11.s64 + 1644;
	// addi r3,r10,-8760
	ctx.r3.s64 = ctx.r10.s64 + -8760;
	// bl 0x881526c0
	ctx.lr = 0x88136D38;
	sub_881526C0(ctx, base);
	// stw r3,-1888(r31)
	PPC_STORE_U32(ctx.r31.u32 + -1888, ctx.r3.u32);
loc_88136D3C:
	// li r10,1
	ctx.r10.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r10,-1820(r31)
	PPC_STORE_U32(ctx.r31.u32 + -1820, ctx.r10.u32);
	// stw r11,-1816(r31)
	PPC_STORE_U32(ctx.r31.u32 + -1816, ctx.r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88136D60"))) PPC_WEAK_FUNC(sub_88136D60);
PPC_FUNC_IMPL(__imp__sub_88136D60) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88136D68;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r4,15
	ctx.r11.s64 = ctx.r4.s64 + 15;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// rlwinm r29,r11,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r29,r3
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r3.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88136de8
	if (ctx.cr6.eq) goto loc_88136DE8;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// mulli r30,r4,196
	ctx.r30.s64 = ctx.r4.s64 * 196;
	// addi r11,r11,26432
	ctx.r11.s64 = ctx.r11.s64 + 26432;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// addi r11,r11,1448
	ctx.r11.s64 = ctx.r11.s64 + 1448;
	// add r5,r30,r11
	ctx.r5.u64 = ctx.r30.u64 + ctx.r11.u64;
	// lis r11,-30699
	ctx.r11.s64 = -2011889664;
	// addi r3,r11,-8760
	ctx.r3.s64 = ctx.r11.s64 + -8760;
	// bne cr6,0x88136db8
	if (!ctx.cr6.eq) goto loc_88136DB8;
	// li r4,40
	ctx.r4.s64 = 40;
	// bl 0x881526c0
	ctx.lr = 0x88136DB0;
	sub_881526C0(ctx, base);
	// stw r3,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r3.u32);
	// b 0x88136dc4
	goto loc_88136DC4;
loc_88136DB8:
	// li r4,39
	ctx.r4.s64 = 39;
	// bl 0x881526c0
	ctx.lr = 0x88136DC0;
	sub_881526C0(ctx, base);
	// stw r3,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r3.u32);
loc_88136DC4:
	// add r11,r30,r31
	ctx.r11.u64 = ctx.r30.u64 + ctx.r31.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r10,r11,1448
	ctx.r10.s64 = ctx.r11.s64 + 1448;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// lbz r8,1458(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1458);
	// stb r8,1457(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1457, ctx.r8.u8);
	// stwx r9,r29,r31
	PPC_STORE_U32(ctx.r29.u32 + ctx.r31.u32, ctx.r9.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_88136DE8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88136DF4"))) PPC_WEAK_FUNC(sub_88136DF4);
PPC_FUNC_IMPL(__imp__sub_88136DF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88136DF8"))) PPC_WEAK_FUNC(sub_88136DF8);
PPC_FUNC_IMPL(__imp__sub_88136DF8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x88155298
	ctx.lr = 0x88136E0C;
	sub_88155298(ctx, base);
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lis r10,-30690
	ctx.r10.s64 = -2011299840;
	// addi r31,r11,26432
	ctx.r31.s64 = ctx.r11.s64 + 26432;
	// li r4,34
	ctx.r4.s64 = 34;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r3,r10,11352
	ctx.r3.s64 = ctx.r10.s64 + 11352;
	// bl 0x881526c0
	ctx.lr = 0x88136E28;
	sub_881526C0(ctx, base);
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// lis r9,-30711
	ctx.r9.s64 = -2012676096;
	// li r4,36
	ctx.r4.s64 = 36;
	// addi r3,r9,23504
	ctx.r3.s64 = ctx.r9.s64 + 23504;
	// bl 0x881526c0
	ctx.lr = 0x88136E3C;
	sub_881526C0(ctx, base);
	// stw r3,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r3.u32);
	// lis r8,-30690
	ctx.r8.s64 = -2011299840;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,38
	ctx.r4.s64 = 38;
	// addi r3,r8,28720
	ctx.r3.s64 = ctx.r8.s64 + 28720;
	// bl 0x881526c0
	ctx.lr = 0x88136E54;
	sub_881526C0(ctx, base);
	// stw r3,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r3.u32);
	// lis r7,-30698
	ctx.r7.s64 = -2011824128;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// li r4,35
	ctx.r4.s64 = 35;
	// addi r3,r7,9744
	ctx.r3.s64 = ctx.r7.s64 + 9744;
	// bl 0x881526c0
	ctx.lr = 0x88136E6C;
	sub_881526C0(ctx, base);
	// stw r3,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88136E84"))) PPC_WEAK_FUNC(sub_88136E84);
PPC_FUNC_IMPL(__imp__sub_88136E84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88136E88"))) PPC_WEAK_FUNC(sub_88136E88);
PPC_FUNC_IMPL(__imp__sub_88136E88) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88136E90;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r31,r11,26432
	ctx.r31.s64 = ctx.r11.s64 + 26432;
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88136ed8
	if (ctx.cr6.eq) goto loc_88136ED8;
	// lis r11,-30699
	ctx.r11.s64 = -2011889664;
	// li r4,40
	ctx.r4.s64 = 40;
	// addi r5,r31,1448
	ctx.r5.s64 = ctx.r31.s64 + 1448;
	// addi r3,r11,-8760
	ctx.r3.s64 = ctx.r11.s64 + -8760;
	// bl 0x881526c0
	ctx.lr = 0x88136EBC;
	sub_881526C0(ctx, base);
	// lbz r11,1458(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1458);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r3,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r3.u32);
	// addi r30,r31,1448
	ctx.r30.s64 = ctx.r31.s64 + 1448;
	// stw r10,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r10.u32);
	// stb r11,1457(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1457, ctx.r11.u8);
	// b 0x88136edc
	goto loc_88136EDC;
loc_88136ED8:
	// li r30,0
	ctx.r30.s64 = 0;
loc_88136EDC:
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88136f18
	if (ctx.cr6.eq) goto loc_88136F18;
	// lis r11,-30699
	ctx.r11.s64 = -2011889664;
	// li r4,39
	ctx.r4.s64 = 39;
	// addi r5,r31,1644
	ctx.r5.s64 = ctx.r31.s64 + 1644;
	// addi r3,r11,-8760
	ctx.r3.s64 = ctx.r11.s64 + -8760;
	// bl 0x881526c0
	ctx.lr = 0x88136EFC;
	sub_881526C0(ctx, base);
	// lbz r11,1654(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1654);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r3,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r3.u32);
	// addi r29,r31,1644
	ctx.r29.s64 = ctx.r31.s64 + 1644;
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// stb r11,1653(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1653, ctx.r11.u8);
	// b 0x88136f1c
	goto loc_88136F1C;
loc_88136F18:
	// li r29,0
	ctx.r29.s64 = 0;
loc_88136F1C:
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r10,-30701
	ctx.r10.s64 = -2012020736;
	// stw r11,324(r31)
	PPC_STORE_U32(ctx.r31.u32 + 324, ctx.r11.u32);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r10,23912
	ctx.r4.s64 = ctx.r10.s64 + 23912;
	// bl 0x881363e0
	ctx.lr = 0x88136F38;
	sub_881363E0(ctx, base);
	// lwz r11,324(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 324);
	// lis r5,50
	ctx.r5.s64 = 3276800;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x88136f94
	if (!ctx.cr6.eq) goto loc_88136F94;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x88136f74
	if (ctx.cr6.eq) goto loc_88136F74;
	// addi r3,r31,1448
	ctx.r3.s64 = ctx.r31.s64 + 1448;
	// bl 0x88133bb8
	ctx.lr = 0x88136F58;
	sub_88133BB8(ctx, base);
	// lis r11,60
	ctx.r11.s64 = 3932160;
	// stw r5,68(r30)
	PPC_STORE_U32(ctx.r30.u32 + 68, ctx.r5.u32);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// stw r11,64(r30)
	PPC_STORE_U32(ctx.r30.u32 + 64, ctx.r11.u32);
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// stw r11,1504(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1504, ctx.r11.u32);
	// stw r5,1508(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1508, ctx.r5.u32);
loc_88136F74:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x88136fe8
	if (ctx.cr6.eq) goto loc_88136FE8;
	// addi r3,r31,1644
	ctx.r3.s64 = ctx.r31.s64 + 1644;
	// bl 0x88133bb8
	ctx.lr = 0x88136F84;
	sub_88133BB8(ctx, base);
	// lis r11,180
	ctx.r11.s64 = 11796480;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// stw r11,64(r29)
	PPC_STORE_U32(ctx.r29.u32 + 64, ctx.r11.u32);
	// b 0x88136fd8
	goto loc_88136FD8;
loc_88136F94:
	// lis r4,120
	ctx.r4.s64 = 7864320;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x88136fc0
	if (ctx.cr6.eq) goto loc_88136FC0;
	// addi r3,r31,1448
	ctx.r3.s64 = ctx.r31.s64 + 1448;
	// bl 0x88133bb8
	ctx.lr = 0x88136FA8;
	sub_88133BB8(ctx, base);
	// stw r4,64(r30)
	PPC_STORE_U32(ctx.r30.u32 + 64, ctx.r4.u32);
	// stw r5,68(r30)
	PPC_STORE_U32(ctx.r30.u32 + 68, ctx.r5.u32);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// stw r4,1504(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1504, ctx.r4.u32);
	// stw r5,1508(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1508, ctx.r5.u32);
loc_88136FC0:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x88136fe8
	if (ctx.cr6.eq) goto loc_88136FE8;
	// addi r3,r31,1644
	ctx.r3.s64 = ctx.r31.s64 + 1644;
	// bl 0x88133bb8
	ctx.lr = 0x88136FD0;
	sub_88133BB8(ctx, base);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// stw r4,64(r29)
	PPC_STORE_U32(ctx.r29.u32 + 64, ctx.r4.u32);
loc_88136FD8:
	// stw r5,68(r29)
	PPC_STORE_U32(ctx.r29.u32 + 68, ctx.r5.u32);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// stw r5,1704(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1704, ctx.r5.u32);
	// stw r11,1700(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1700, ctx.r11.u32);
loc_88136FE8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88136FF0"))) PPC_WEAK_FUNC(sub_88136FF0);
PPC_FUNC_IMPL(__imp__sub_88136FF0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88136FF8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,1(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// extsb r30,r11
	ctx.r30.s64 = ctx.r11.s8;
	// addi r10,r30,13
	ctx.r10.s64 = ctx.r30.s64 + 13;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r4
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r4.u32);
	// bl 0x88152b00
	ctx.lr = 0x8813701C;
	sub_88152B00(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88137158
	if (!ctx.cr6.eq) goto loc_88137158;
	// lwz r11,144(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 144);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8813712c
	if (!ctx.cr6.eq) goto loc_8813712C;
	// lhz r11,2(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 2);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88137098
	if (ctx.cr6.eq) goto loc_88137098;
	// lwz r11,328(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 328);
	// lis r4,120
	ctx.r4.s64 = 7864320;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// blt cr6,0x8813705c
	if (ctx.cr6.lt) goto loc_8813705C;
	// lis r4,60
	ctx.r4.s64 = 3932160;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8813705c
	if (ctx.cr6.eq) goto loc_8813705C;
	// lis r4,180
	ctx.r4.s64 = 11796480;
loc_8813705C:
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,26432
	ctx.r11.s64 = ctx.r11.s64 + 26432;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r8,r11,60
	ctx.r8.s64 = ctx.r11.s64 + 60;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r9,r10,r8
	PPC_STORE_U32(ctx.r10.u32 + ctx.r8.u32, ctx.r9.u32);
	// bl 0x88134520
	ctx.lr = 0x8813707C;
	sub_88134520(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88136d60
	ctx.lr = 0x88137088;
	sub_88136D60(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88134b28
	ctx.lr = 0x88137090;
	sub_88134B28(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_88137098:
	// lis r11,-30651
	ctx.r11.s64 = -2008743936;
	// addi r10,r11,-26112
	ctx.r10.s64 = ctx.r11.s64 + -26112;
	// lbz r9,15(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 15);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x88137104
	if (ctx.cr6.eq) goto loc_88137104;
	// lwz r11,140(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88137158
	if (!ctx.cr6.eq) goto loc_88137158;
	// lwz r11,1860(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 1860);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x881370cc
	if (!ctx.cr6.eq) goto loc_881370CC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88133e30
	ctx.lr = 0x881370CC;
	sub_88133E30(ctx, base);
loc_881370CC:
	// lwz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,90
	ctx.r11.s64 = 90;
	// stw r9,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r9.u32);
	// li r8,9
	ctx.r8.s64 = 9;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r11,365(r10)
	PPC_STORE_U8(ctx.r10.u32 + 365, ctx.r11.u8);
	// lwz r7,128(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// stb r11,366(r7)
	PPC_STORE_U8(ctx.r7.u32 + 366, ctx.r11.u8);
	// lwz r6,128(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// stb r8,364(r6)
	PPC_STORE_U8(ctx.r6.u32 + 364, ctx.r8.u8);
	// bl 0x88134b28
	ctx.lr = 0x881370FC;
	sub_88134B28(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_88137104:
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26272(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26272);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88137158
	if (ctx.cr6.eq) goto loc_88137158;
	// lwz r11,1860(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 1860);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88137150
	if (!ctx.cr6.eq) goto loc_88137150;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88133e30
	ctx.lr = 0x88137128;
	sub_88133E30(ctx, base);
	// b 0x88137150
	goto loc_88137150;
loc_8813712C:
	// lis r11,-30651
	ctx.r11.s64 = -2008743936;
	// addi r10,r11,-26112
	ctx.r10.s64 = ctx.r11.s64 + -26112;
	// lbz r9,15(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 15);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x88137158
	if (!ctx.cr6.eq) goto loc_88137158;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26272(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26272);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88137158
	if (ctx.cr6.eq) goto loc_88137158;
loc_88137150:
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r11.u8);
loc_88137158:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88134b28
	ctx.lr = 0x88137160;
	sub_88134B28(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88137168"))) PPC_WEAK_FUNC(sub_88137168);
PPC_FUNC_IMPL(__imp__sub_88137168) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x88137170;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r31,r10,26264
	ctx.r31.s64 = ctx.r10.s64 + 26264;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r9,308(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 308);
	// stw r11,1728(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1728, ctx.r11.u32);
	// stw r10,1924(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1924, ctx.r10.u32);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x88137314
	if (!ctx.cr6.eq) goto loc_88137314;
	// lwz r11,2028(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2028);
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r30,r10,-10940
	ctx.r30.s64 = ctx.r10.s64 + -10940;
	// bne cr6,0x88137228
	if (!ctx.cr6.eq) goto loc_88137228;
	// lis r6,-30671
	ctx.r6.s64 = -2010054656;
	// lbz r8,1624(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1624);
	// lis r5,-30643
	ctx.r5.s64 = -2008219648;
	// lbz r7,1626(r31)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1626);
	// lbz r9,1820(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1820);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r29,252(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r28,476(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 476);
	// lwz r11,4200(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4200);
	// lwz r10,26428(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 26428);
	// lbz r6,1822(r31)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1822);
	// lwz r5,256(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 256);
	// lwz r27,236(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 236);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// stb r29,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r29.u8);
	// stb r28,87(r1)
	PPC_STORE_U8(ctx.r1.u32 + 87, ctx.r28.u8);
	// stb r27,86(r1)
	PPC_STORE_U8(ctx.r1.u32 + 86, ctx.r27.u8);
	// stb r8,82(r1)
	PPC_STORE_U8(ctx.r1.u32 + 82, ctx.r8.u8);
	// stb r7,83(r1)
	PPC_STORE_U8(ctx.r1.u32 + 83, ctx.r7.u8);
	// stb r9,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r9.u8);
	// stb r6,85(r1)
	PPC_STORE_U8(ctx.r1.u32 + 85, ctx.r6.u8);
	// stb r5,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, ctx.r5.u8);
	// std r4,2032(r31)
	PPC_STORE_U64(ctx.r31.u32 + 2032, ctx.r4.u64);
	// stw r3,2040(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2040, ctx.r3.u32);
	// bl 0x8808eda8
	ctx.lr = 0x88137218;
	sub_8808EDA8(ctx, base);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8808ec08
	ctx.lr = 0x88137224;
	sub_8808EC08(ctx, base);
	// b 0x8813729c
	goto loc_8813729C;
loc_88137228:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8813729c
	if (!ctx.cr6.eq) goto loc_8813729C;
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// lis r10,9
	ctx.r10.s64 = 589824;
	// addi r4,r11,26648
	ctx.r4.s64 = ctx.r11.s64 + 26648;
	// ori r3,r10,58508
	ctx.r3.u64 = ctx.r10.u64 | 58508;
	// lis r29,-30671
	ctx.r29.s64 = -2010054656;
	// lis r28,-30643
	ctx.r28.s64 = -2008219648;
	// li r9,4
	ctx.r9.s64 = 4;
	// lwz r11,32(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 32);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r10,36(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 36);
	// li r7,0
	ctx.r7.s64 = 0;
	// lbzx r5,r4,r3
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r3.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r4,72(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 72);
	// stw r9,48(r30)
	PPC_STORE_U32(ctx.r30.u32 + 48, ctx.r9.u32);
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// stw r11,4200(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4200, ctx.r11.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r10,26428(r28)
	PPC_STORE_U32(ctx.r28.u32 + 26428, ctx.r10.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// sth r8,112(r30)
	PPC_STORE_U16(ctx.r30.u32 + 112, ctx.r8.u16);
	// sth r7,108(r30)
	PPC_STORE_U16(ctx.r30.u32 + 108, ctx.r7.u16);
	// sth r6,128(r30)
	PPC_STORE_U16(ctx.r30.u32 + 128, ctx.r6.u16);
	// sth r11,124(r30)
	PPC_STORE_U16(ctx.r30.u32 + 124, ctx.r11.u16);
	// stw r10,56(r30)
	PPC_STORE_U32(ctx.r30.u32 + 56, ctx.r10.u32);
	// stw r5,52(r30)
	PPC_STORE_U32(ctx.r30.u32 + 52, ctx.r5.u32);
	// stw r4,60(r30)
	PPC_STORE_U32(ctx.r30.u32 + 60, ctx.r4.u32);
loc_8813729C:
	// bl 0x881e2b48
	ctx.lr = 0x881372A0;
	sub_881E2B48(ctx, base);
	// bl 0x881e6f78
	ctx.lr = 0x881372A4;
	sub_881E6F78(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,-17844(r31)
	PPC_STORE_U32(ctx.r31.u32 + -17844, ctx.r11.u32);
	// lis r11,-30679
	ctx.r11.s64 = -2010578944;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// lis r8,-30643
	ctx.r8.s64 = -2008219648;
	// addi r7,r11,-13424
	ctx.r7.s64 = ctx.r11.s64 + -13424;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,280(r31)
	PPC_STORE_U32(ctx.r31.u32 + 280, ctx.r9.u32);
	// lwz r11,256(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 256);
	// lwz r10,252(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r5,r6,4,0,27
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// lwzx r11,r5,r7
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r7.u32);
	// stb r11,10(r30)
	PPC_STORE_U8(ctx.r30.u32 + 10, ctx.r11.u8);
	// stw r11,26424(r8)
	PPC_STORE_U32(ctx.r8.u32 + 26424, ctx.r11.u32);
	// stw r11,284(r31)
	PPC_STORE_U32(ctx.r31.u32 + 284, ctx.r11.u32);
	// bl 0x8815caf0
	ctx.lr = 0x881372F0;
	sub_8815CAF0(ctx, base);
	// bl 0x88160780
	ctx.lr = 0x881372F4;
	sub_88160780(ctx, base);
	// bl 0x881609e8
	ctx.lr = 0x881372F8;
	sub_881609E8(ctx, base);
	// bl 0x88136e88
	ctx.lr = 0x881372FC;
	sub_88136E88(ctx, base);
	// li r11,3
	ctx.r11.s64 = 3;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,3
	ctx.r9.s64 = 3;
	// sth r11,244(r31)
	PPC_STORE_U16(ctx.r31.u32 + 244, ctx.r11.u16);
	// sth r10,246(r31)
	PPC_STORE_U16(ctx.r31.u32 + 246, ctx.r10.u16);
	// stb r9,6(r30)
	PPC_STORE_U8(ctx.r30.u32 + 6, ctx.r9.u8);
loc_88137314:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88137320"))) PPC_WEAK_FUNC(sub_88137320);
PPC_FUNC_IMPL(__imp__sub_88137320) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r31,r11,32388
	ctx.r31.s64 = ctx.r11.s64 + 32388;
	// lwz r3,-5944(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -5944);
	// bl 0x88152b00
	ctx.lr = 0x88137344;
	sub_88152B00(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88137480
	if (!ctx.cr6.eq) goto loc_88137480;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r9,-2120(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + -2120);
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r30,r10,-11048
	ctx.r30.s64 = ctx.r10.s64 + -11048;
	// li r10,1
	ctx.r10.s64 = 1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r11,140(r30)
	PPC_STORE_U32(ctx.r30.u32 + 140, ctx.r11.u32);
	// stb r10,111(r30)
	PPC_STORE_U8(ctx.r30.u32 + 111, ctx.r10.u8);
	// bne cr6,0x88137394
	if (!ctx.cr6.eq) goto loc_88137394;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88137394
	if (ctx.cr6.eq) goto loc_88137394;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x88137394;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_88137394:
	// lwz r11,-2116(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -2116);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x881373c4
	if (!ctx.cr6.eq) goto loc_881373C4;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x881373c4
	if (ctx.cr6.eq) goto loc_881373C4;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x881373C4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_881373C4:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,-144(r31)
	PPC_STORE_U32(ctx.r31.u32 + -144, ctx.r11.u32);
	// bl 0x88095120
	ctx.lr = 0x881373D0;
	sub_88095120(ctx, base);
	// addi r3,r31,388
	ctx.r3.s64 = ctx.r31.s64 + 388;
	// li r5,148
	ctx.r5.s64 = 148;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x88073bd0
	ctx.lr = 0x881373E0;
	sub_88073BD0(ctx, base);
	// li r11,241
	ctx.r11.s64 = 241;
	// li r10,2
	ctx.r10.s64 = 2;
	// lis r8,-30643
	ctx.r8.s64 = -2008219648;
	// stw r11,404(r31)
	PPC_STORE_U32(ctx.r31.u32 + 404, ctx.r11.u32);
	// stw r10,420(r31)
	PPC_STORE_U32(ctx.r31.u32 + 420, ctx.r10.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,396(r31)
	PPC_STORE_U32(ctx.r31.u32 + 396, ctx.r11.u32);
	// addi r7,r8,30408
	ctx.r7.s64 = ctx.r8.s64 + 30408;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// stw r10,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,-5828(r31)
	PPC_STORE_U32(ctx.r31.u32 + -5828, ctx.r11.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r9,-5832(r31)
	PPC_STORE_U32(ctx.r31.u32 + -5832, ctx.r9.u32);
	// li r3,16
	ctx.r3.s64 = 16;
	// stw r10,256(r7)
	PPC_STORE_U32(ctx.r7.u32 + 256, ctx.r10.u32);
	// stw r11,468(r7)
	PPC_STORE_U32(ctx.r7.u32 + 468, ctx.r11.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r9,680(r7)
	PPC_STORE_U32(ctx.r7.u32 + 680, ctx.r9.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,892(r7)
	PPC_STORE_U32(ctx.r7.u32 + 892, ctx.r10.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,156(r30)
	PPC_STORE_U32(ctx.r30.u32 + 156, ctx.r11.u32);
	// stw r9,160(r30)
	PPC_STORE_U32(ctx.r30.u32 + 160, ctx.r9.u32);
	// stw r10,164(r30)
	PPC_STORE_U32(ctx.r30.u32 + 164, ctx.r10.u32);
	// stw r11,172(r30)
	PPC_STORE_U32(ctx.r30.u32 + 172, ctx.r11.u32);
	// stw r9,184(r30)
	PPC_STORE_U32(ctx.r30.u32 + 184, ctx.r9.u32);
	// stw r10,308(r30)
	PPC_STORE_U32(ctx.r30.u32 + 308, ctx.r10.u32);
	// bl 0x880900a0
	ctx.lr = 0x88137460;
	sub_880900A0(ctx, base);
	// lis r6,-30701
	ctx.r6.s64 = -2012020736;
	// addi r5,r31,-5956
	ctx.r5.s64 = ctx.r31.s64 + -5956;
	// li r4,44
	ctx.r4.s64 = 44;
	// addi r3,r6,11456
	ctx.r3.s64 = ctx.r6.s64 + 11456;
	// bl 0x881526c0
	ctx.lr = 0x88137474;
	sub_881526C0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r3,-5944(r31)
	PPC_STORE_U32(ctx.r31.u32 + -5944, ctx.r3.u32);
	// stw r11,-4080(r31)
	PPC_STORE_U32(ctx.r31.u32 + -4080, ctx.r11.u32);
loc_88137480:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88137498"))) PPC_WEAK_FUNC(sub_88137498);
PPC_FUNC_IMPL(__imp__sub_88137498) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x88136e88
	ctx.lr = 0x881374B0;
	sub_88136E88(ctx, base);
	// bl 0x881395c8
	ctx.lr = 0x881374B4;
	sub_881395C8(ctx, base);
	// bl 0x881328f8
	ctx.lr = 0x881374B8;
	sub_881328F8(ctx, base);
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r31,r11,26432
	ctx.r31.s64 = ctx.r11.s64 + 26432;
	// lwz r11,164(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 164);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x881374e4
	if (ctx.cr6.eq) goto loc_881374E4;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// subfic r10,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r10.s64 = 0 - ctx.r11.s64;
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addme r8,r9
	{ uint8_t _ca = (ctx.r9.u32 + 0xFFFFFFFF < ctx.r9.u32) | (ctx.r9.u32 + 0xFFFFFFFF + ctx.xer.ca < ctx.xer.ca); // FIX 2026-07-24: insn was silently dropped by the recompiler
	ctx.r8.u64 = ctx.r9.u64 + 0xFFFFFFFFFFFFFFFFull + ctx.xer.ca;
	ctx.xer.ca = _ca; }
	// and r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 & ctx.r11.u64;
	// stw r11,164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 164, ctx.r11.u32);
loc_881374E4:
	// lwz r11,120(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// lis r30,-30643
	ctx.r30.s64 = -2008219648;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88137518
	if (!ctx.cr6.eq) goto loc_88137518;
	// lwz r11,26272(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 26272);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88137518
	if (!ctx.cr6.eq) goto loc_88137518;
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// lwz r11,26276(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26276);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88137518
	if (ctx.cr6.eq) goto loc_88137518;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,26276(r10)
	PPC_STORE_U32(ctx.r10.u32 + 26276, ctx.r11.u32);
loc_88137518:
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,324(r31)
	PPC_STORE_U32(ctx.r31.u32 + 324, ctx.r11.u32);
	// stw r10,328(r31)
	PPC_STORE_U32(ctx.r31.u32 + 328, ctx.r10.u32);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// stw r10,1932(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1932, ctx.r10.u32);
	// lis r10,-30701
	ctx.r10.s64 = -2012020736;
	// stw r9,332(r31)
	PPC_STORE_U32(ctx.r31.u32 + 332, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,1928(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1928, ctx.r11.u32);
	// addi r4,r10,23912
	ctx.r4.s64 = ctx.r10.s64 + 23912;
	// stw r9,1936(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1936, ctx.r9.u32);
	// stw r11,1940(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1940, ctx.r11.u32);
	// bl 0x881363e0
	ctx.lr = 0x88137554;
	sub_881363E0(ctx, base);
	// lis r9,-30701
	ctx.r9.s64 = -2012020736;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r9,23840
	ctx.r4.s64 = ctx.r9.s64 + 23840;
	// bl 0x88135ba8
	ctx.lr = 0x88137568;
	sub_88135BA8(ctx, base);
	// lis r8,-30701
	ctx.r8.s64 = -2012020736;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r8,23824
	ctx.r4.s64 = ctx.r8.s64 + 23824;
	// bl 0x88136368
	ctx.lr = 0x8813757C;
	sub_88136368(ctx, base);
	// lwz r11,1928(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1928);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88137598
	if (!ctx.cr6.eq) goto loc_88137598;
	// lwz r11,1932(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1932);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r11,0
	ctx.r11.s64 = 0;
	// beq cr6,0x8813759c
	if (ctx.cr6.eq) goto loc_8813759C;
loc_88137598:
	// li r11,1
	ctx.r11.s64 = 1;
loc_8813759C:
	// stw r11,316(r31)
	PPC_STORE_U32(ctx.r31.u32 + 316, ctx.r11.u32);
	// lbz r11,367(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 367);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x881375cc
	if (ctx.cr6.eq) goto loc_881375CC;
	// lwz r11,1460(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1460);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x881375c4
	if (!ctx.cr6.eq) goto loc_881375C4;
	// lwz r11,1656(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1656);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x881375cc
	if (ctx.cr6.eq) goto loc_881375CC;
loc_881375C4:
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,367(r31)
	PPC_STORE_U8(ctx.r31.u32 + 367, ctx.r11.u8);
loc_881375CC:
	// lwz r11,1936(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1936);
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r8,1
	ctx.r8.s64 = 65536;
	// lwz r9,1940(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1940);
	// stw r10,360(r31)
	PPC_STORE_U32(ctx.r31.u32 + 360, ctx.r10.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ori r8,r8,4464
	ctx.r8.u64 = ctx.r8.u64 | 4464;
	// bne cr6,0x881375f8
	if (!ctx.cr6.eq) goto loc_881375F8;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x88137618
	if (ctx.cr6.eq) goto loc_88137618;
	// b 0x88137608
	goto loc_88137608;
loc_881375F8:
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x88137608
	if (ctx.cr6.lt) goto loc_88137608;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,360(r31)
	PPC_STORE_U32(ctx.r31.u32 + 360, ctx.r11.u32);
loc_88137608:
	// cmpw cr6,r9,r8
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x88137618
	if (ctx.cr6.lt) goto loc_88137618;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,360(r31)
	PPC_STORE_U32(ctx.r31.u32 + 360, ctx.r11.u32);
loc_88137618:
	// lwz r10,332(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 332);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,26272(r30)
	PPC_STORE_U32(ctx.r30.u32 + 26272, ctx.r11.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8813764c
	if (!ctx.cr6.eq) goto loc_8813764C;
	// lwz r11,336(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 336);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88137640
	if (ctx.cr6.eq) goto loc_88137640;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// b 0x88137650
	goto loc_88137650;
loc_88137640:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,26272(r30)
	PPC_STORE_U32(ctx.r30.u32 + 26272, ctx.r11.u32);
	// b 0x88137654
	goto loc_88137654;
loc_8813764C:
	// li r11,8
	ctx.r11.s64 = 8;
loc_88137650:
	// stw r11,336(r31)
	PPC_STORE_U32(ctx.r31.u32 + 336, ctx.r11.u32);
loc_88137654:
	// lis r11,-30701
	ctx.r11.s64 = -2012020736;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,28656
	ctx.r4.s64 = ctx.r11.s64 + 28656;
	// bl 0x88135ba8
	ctx.lr = 0x88137668;
	sub_88135BA8(ctx, base);
	// lwz r11,1588(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1588);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88137680
	if (!ctx.cr6.eq) goto loc_88137680;
	// lwz r11,1784(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1784);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x881376f0
	if (ctx.cr6.eq) goto loc_881376F0;
loc_88137680:
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x88152b00
	ctx.lr = 0x88137688;
	sub_88152B00(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x881376e8
	if (!ctx.cr6.eq) goto loc_881376E8;
	// lwz r11,304(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 304);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x881376e8
	if (!ctx.cr6.eq) goto loc_881376E8;
	// lbz r11,365(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 365);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stb r10,367(r31)
	PPC_STORE_U8(ctx.r31.u32 + 367, ctx.r10.u8);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// stb r11,365(r31)
	PPC_STORE_U8(ctx.r31.u32 + 365, ctx.r11.u8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x881376f0
	if (!ctx.cr6.lt) goto loc_881376F0;
	// lbz r11,364(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 364);
	// li r6,80
	ctx.r6.s64 = 80;
	// lbz r10,366(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 366);
	// li r5,45
	ctx.r5.s64 = 45;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// li r4,129
	ctx.r4.s64 = 129;
	// li r3,6
	ctx.r3.s64 = 6;
	// stb r11,364(r31)
	PPC_STORE_U8(ctx.r31.u32 + 364, ctx.r11.u8);
	// stb r10,365(r31)
	PPC_STORE_U8(ctx.r31.u32 + 365, ctx.r10.u8);
	// bl 0x880e3240
	ctx.lr = 0x881376E4;
	sub_880E3240(ctx, base);
	// b 0x881376f0
	goto loc_881376F0;
loc_881376E8:
	// lbz r11,366(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 366);
	// stb r11,365(r31)
	PPC_STORE_U8(ctx.r31.u32 + 365, ctx.r11.u8);
loc_881376F0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88137708"))) PPC_WEAK_FUNC(sub_88137708);
PPC_FUNC_IMPL(__imp__sub_88137708) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r31,r11,26432
	ctx.r31.s64 = ctx.r11.s64 + 26432;
	// lwz r11,1876(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1876);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88137884
	if (!ctx.cr6.eq) goto loc_88137884;
	// bl 0x88137498
	ctx.lr = 0x88137734;
	sub_88137498(ctx, base);
	// lwz r11,312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 312);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88137884
	if (!ctx.cr6.eq) goto loc_88137884;
	// lwz r11,324(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 324);
	// lis r8,-30597
	ctx.r8.s64 = -2005204992;
	// lwz r9,1848(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1848);
	// addic r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// lwz r11,1588(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1588);
	// lwz r10,1784(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1784);
	// addi r30,r8,-10908
	ctx.r30.s64 = ctx.r8.s64 + -10908;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// lwz r8,352(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 352);
	// and r9,r6,r9
	ctx.r9.u64 = ctx.r6.u64 & ctx.r9.u64;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stb r11,-31(r30)
	PPC_STORE_U8(ctx.r30.u32 + -31, ctx.r11.u8);
	// stb r10,-30(r30)
	PPC_STORE_U8(ctx.r30.u32 + -30, ctx.r10.u8);
	// stw r9,1848(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1848, ctx.r9.u32);
	// beq cr6,0x881377dc
	if (ctx.cr6.eq) goto loc_881377DC;
	// lwz r10,1860(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1860);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,304(r31)
	PPC_STORE_U32(ctx.r31.u32 + 304, ctx.r11.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x881377b4
	if (!ctx.cr6.eq) goto loc_881377B4;
	// lis r11,-30697
	ctx.r11.s64 = -2011758592;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// li r4,48
	ctx.r4.s64 = 48;
	// addi r3,r11,-31184
	ctx.r3.s64 = ctx.r11.s64 + -31184;
	// bl 0x881526c0
	ctx.lr = 0x881377A4;
	sub_881526C0(ctx, base);
	// li r11,7
	ctx.r11.s64 = 7;
	// stw r3,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r3.u32);
	// li r9,7
	ctx.r9.s64 = 7;
	// b 0x881377c4
	goto loc_881377C4;
loc_881377B4:
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x880900a0
	ctx.lr = 0x881377BC;
	sub_880900A0(ctx, base);
	// li r11,8
	ctx.r11.s64 = 8;
	// li r9,8
	ctx.r9.s64 = 8;
loc_881377C4:
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r9,-26(r30)
	PPC_STORE_U8(ctx.r30.u32 + -26, ctx.r9.u8);
	// sth r11,76(r31)
	PPC_STORE_U16(ctx.r31.u32 + 76, ctx.r11.u16);
	// li r3,0
	ctx.r3.s64 = 0;
	// sth r10,78(r31)
	PPC_STORE_U16(ctx.r31.u32 + 78, ctx.r10.u16);
	// b 0x88137888
	goto loc_88137888;
loc_881377DC:
	// lwz r11,328(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 328);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88137884
	if (!ctx.cr6.eq) goto loc_88137884;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,5
	ctx.r10.s64 = 5;
	// stw r11,304(r31)
	PPC_STORE_U32(ctx.r31.u32 + 304, ctx.r11.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r11,5
	ctx.r11.s64 = 5;
	// sth r10,76(r31)
	PPC_STORE_U16(ctx.r31.u32 + 76, ctx.r10.u16);
	// sth r9,78(r31)
	PPC_STORE_U16(ctx.r31.u32 + 78, ctx.r9.u16);
	// lis r10,-30686
	ctx.r10.s64 = -2011037696;
	// stb r11,-26(r30)
	PPC_STORE_U8(ctx.r30.u32 + -26, ctx.r11.u8);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// li r4,46
	ctx.r4.s64 = 46;
	// addi r3,r10,29216
	ctx.r3.s64 = ctx.r10.s64 + 29216;
	// bl 0x881526c0
	ctx.lr = 0x8813781C;
	sub_881526C0(ctx, base);
	// lwz r11,1844(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1844);
	// stw r3,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r3.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88137874
	if (ctx.cr6.eq) goto loc_88137874;
	// lwz r11,168(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 168);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88137864
	if (ctx.cr6.eq) goto loc_88137864;
	// lwz r11,160(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 160);
	// cmplwi cr6,r11,43
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 43, ctx.xer);
	// ble cr6,0x88137864
	if (!ctx.cr6.gt) goto loc_88137864;
	// lwz r11,-5364(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -5364);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813785c
	if (!ctx.cr6.eq) goto loc_8813785C;
	// li r3,43
	ctx.r3.s64 = 43;
	// bl 0x8808d1b8
	ctx.lr = 0x88137858;
	sub_8808D1B8(ctx, base);
	// b 0x88137864
	goto loc_88137864;
loc_8813785C:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,-5360(r30)
	PPC_STORE_U32(ctx.r30.u32 + -5360, ctx.r11.u32);
loc_88137864:
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,1848(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1848, ctx.r11.u32);
	// stw r10,1844(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1844, ctx.r10.u32);
loc_88137874:
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// stb r10,-29(r30)
	PPC_STORE_U8(ctx.r30.u32 + -29, ctx.r10.u8);
loc_88137884:
	// li r3,1
	ctx.r3.s64 = 1;
loc_88137888:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881378A0"))) PPC_WEAK_FUNC(sub_881378A0);
PPC_FUNC_IMPL(__imp__sub_881378A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x881378A8;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r31,r11,32388
	ctx.r31.s64 = ctx.r11.s64 + 32388;
	// lhz r11,-5878(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + -5878);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x88137a1c
	if (ctx.cr6.lt) goto loc_88137A1C;
	// beq cr6,0x881379d8
	if (ctx.cr6.eq) goto loc_881379D8;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x88137c14
	if (!ctx.cr6.lt) goto loc_88137C14;
	// lwz r11,-5876(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -5876);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,-5876(r31)
	PPC_STORE_U32(ctx.r31.u32 + -5876, ctx.r11.u32);
	// bge 0x88137c14
	if (!ctx.cr0.lt) goto loc_88137C14;
	// lis r9,-30643
	ctx.r9.s64 = -2008219648;
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lis r6,-30671
	ctx.r6.s64 = -2010054656;
	// addi r30,r11,-16616
	ctx.r30.s64 = ctx.r11.s64 + -16616;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r11,26268(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 26268);
	// li r9,4
	ctx.r9.s64 = 4;
	// stw r10,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// addic r5,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r5.s64 = ctx.r11.s64 + -1;
	// lwz r8,4200(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4200);
	// lwz r3,5876(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5876);
	// li r10,4
	ctx.r10.s64 = 4;
	// subfe r11,r4,r4
	temp.u8 = (~ctx.r4.u32 + ctx.r4.u32 < ~ctx.r4.u32) | (~ctx.r4.u32 + ctx.r4.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r4.u64 + ctx.r4.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// sth r9,-5880(r31)
	PPC_STORE_U16(ctx.r31.u32 + -5880, ctx.r9.u16);
	// sth r7,-5878(r31)
	PPC_STORE_U16(ctx.r31.u32 + -5878, ctx.r7.u16);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// and r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 & ctx.r8.u64;
	// stb r10,5682(r30)
	PPC_STORE_U8(ctx.r30.u32 + 5682, ctx.r10.u8);
	// stw r11,4200(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4200, ctx.r11.u32);
	// beq cr6,0x8813795c
	if (ctx.cr6.eq) goto loc_8813795C;
	// lwz r11,5868(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5868);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8813795c
	if (ctx.cr6.eq) goto loc_8813795C;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88137954
	if (!ctx.cr6.eq) goto loc_88137954;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8808d1b8
	ctx.lr = 0x88137950;
	sub_8808D1B8(ctx, base);
	// b 0x8813795c
	goto loc_8813795C;
loc_88137954:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
loc_8813795C:
	// addi r11,r31,-5956
	ctx.r11.s64 = ctx.r31.s64 + -5956;
	// li r29,2
	ctx.r29.s64 = 2;
	// addi r31,r11,1448
	ctx.r31.s64 = ctx.r11.s64 + 1448;
loc_88137968:
	// lbz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x881379bc
	if (ctx.cr6.eq) goto loc_881379BC;
	// lbz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 8);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x881379bc
	if (!ctx.cr6.eq) goto loc_881379BC;
	// lwz r11,5876(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5876);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x881379bc
	if (ctx.cr6.eq) goto loc_881379BC;
	// lwz r11,5868(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5868);
	// cmplwi cr6,r11,49
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 49, ctx.xer);
	// ble cr6,0x881379bc
	if (!ctx.cr6.gt) goto loc_881379BC;
	// lwz r11,392(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 392);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x881379b4
	if (!ctx.cr6.eq) goto loc_881379B4;
	// li r3,49
	ctx.r3.s64 = 49;
	// bl 0x8808d1b8
	ctx.lr = 0x881379B0;
	sub_8808D1B8(ctx, base);
	// b 0x881379bc
	goto loc_881379BC;
loc_881379B4:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,396(r30)
	PPC_STORE_U32(ctx.r30.u32 + 396, ctx.r11.u32);
loc_881379BC:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r31,r31,196
	ctx.r31.s64 = ctx.r31.s64 + 196;
	// bne 0x88137968
	if (!ctx.cr0.eq) goto loc_88137968;
	// bl 0x88137498
	ctx.lr = 0x881379CC;
	sub_88137498(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_881379D8:
	// lwz r11,-5816(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -5816);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88137c18
	if (!ctx.cr6.eq) goto loc_88137C18;
	// li r11,64
	ctx.r11.s64 = 64;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,-5876(r31)
	PPC_STORE_U32(ctx.r31.u32 + -5876, ctx.r11.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,-5656(r31)
	PPC_STORE_U32(ctx.r31.u32 + -5656, ctx.r10.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r9,-5808(r31)
	PPC_STORE_U32(ctx.r31.u32 + -5808, ctx.r9.u32);
	// stw r11,-5804(r31)
	PPC_STORE_U32(ctx.r31.u32 + -5804, ctx.r11.u32);
	// sth r10,-5878(r31)
	PPC_STORE_U16(ctx.r31.u32 + -5878, ctx.r10.u16);
	// bl 0x88137498
	ctx.lr = 0x88137A10;
	sub_88137498(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_88137A1C:
	// lwz r5,-5644(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + -5644);
	// li r7,1
	ctx.r7.s64 = 1;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne cr6,0x88137a38
	if (!ctx.cr6.eq) goto loc_88137A38;
	// lwz r11,-4096(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -4096);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88137a3c
	if (ctx.cr6.eq) goto loc_88137A3C;
loc_88137A38:
	// li r7,0
	ctx.r7.s64 = 0;
loc_88137A3C:
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// lis r9,-30651
	ctx.r9.s64 = -2008743936;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r10,11616
	ctx.r10.s64 = ctx.r10.s64 + 11616;
	// addi r9,r9,-26112
	ctx.r9.s64 = ctx.r9.s64 + -26112;
loc_88137A50:
	// addi r8,r9,20
	ctx.r8.s64 = ctx.r9.s64 + 20;
	// lbzx r6,r11,r10
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r10.u32);
	// lbzx r4,r11,r8
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r8.u32);
	// cmplw cr6,r4,r6
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r6.u32, ctx.xer);
	// bne cr6,0x88137a74
	if (!ctx.cr6.eq) goto loc_88137A74;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// blt cr6,0x88137a50
	if (ctx.cr6.lt) goto loc_88137A50;
	// b 0x88137a78
	goto loc_88137A78;
loc_88137A74:
	// li r7,0
	ctx.r7.s64 = 0;
loc_88137A78:
	// lwz r11,-5648(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -5648);
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r8,-5872(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + -5872);
	// clrlwi r11,r11,30
	ctx.r11.u64 = ctx.r11.u32 & 0x3;
	// addi r30,r9,-16616
	ctx.r30.s64 = ctx.r9.s64 + -16616;
	// sth r10,-5878(r31)
	PPC_STORE_U16(ctx.r31.u32 + -5878, ctx.r10.u16);
	// addi r11,r11,-3
	ctx.r11.s64 = ctx.r11.s64 + -3;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// subfic r11,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r11.s64 = 0 - ctx.r11.s64;
	// lwz r11,5868(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5868);
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// subfic r6,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r6.s64 = 0 - ctx.r11.s64;
	// and r3,r9,r7
	ctx.r3.u64 = ctx.r9.u64 & ctx.r7.u64;
	// subfe r11,r4,r4
	temp.u8 = (~ctx.r4.u32 + ctx.r4.u32 < ~ctx.r4.u32) | (~ctx.r4.u32 + ctx.r4.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r4.u64 + ctx.r4.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 & ctx.r3.u64;
	// stw r11,5876(r30)
	PPC_STORE_U32(ctx.r30.u32 + 5876, ctx.r11.u32);
	// bne cr6,0x88137ac8
	if (!ctx.cr6.eq) goto loc_88137AC8;
	// li r11,500
	ctx.r11.s64 = 500;
	// b 0x88137ad4
	goto loc_88137AD4;
loc_88137AC8:
	// cmpwi cr6,r8,2
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 2, ctx.xer);
	// bne cr6,0x88137adc
	if (!ctx.cr6.eq) goto loc_88137ADC;
	// li r11,2000
	ctx.r11.s64 = 2000;
loc_88137AD4:
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// stw r11,-12780(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12780, ctx.r11.u32);
loc_88137ADC:
	// li r11,2
	ctx.r11.s64 = 2;
	// addi r10,r31,-5956
	ctx.r10.s64 = ctx.r31.s64 + -5956;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r9,r10,1448
	ctx.r9.s64 = ctx.r10.s64 + 1448;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lis r11,-30642
	ctx.r11.s64 = -2008154112;
	// addi r6,r11,31504
	ctx.r6.s64 = ctx.r11.s64 + 31504;
loc_88137AF8:
	// lbz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// clrlwi r4,r11,31
	ctx.r4.u64 = ctx.r11.u32 & 0x1;
	// stw r10,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r10.u32);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x88137b38
	if (ctx.cr6.eq) goto loc_88137B38;
	// lbz r11,8(r9)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 8);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// rotlwi r11,r11,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r4,r10,4,0,27
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// lwzx r3,r4,r6
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r6.u32);
	// stw r3,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r3.u32);
loc_88137B38:
	// addi r9,r9,196
	ctx.r9.s64 = ctx.r9.s64 + 196;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// bdnz 0x88137af8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88137AF8;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x88137b5c
	if (!ctx.cr6.gt) goto loc_88137B5C;
	// stw r11,-5616(r31)
	PPC_STORE_U32(ctx.r31.u32 + -5616, ctx.r11.u32);
	// b 0x88137b60
	goto loc_88137B60;
loc_88137B5C:
	// stw r10,-5616(r31)
	PPC_STORE_U32(ctx.r31.u32 + -5616, ctx.r10.u32);
loc_88137B60:
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq cr6,0x88137c0c
	if (ctx.cr6.eq) goto loc_88137C0C;
	// lwz r11,-5864(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -5864);
	// lis r7,-30679
	ctx.r7.s64 = -2010578944;
	// li r10,1
	ctx.r10.s64 = 1;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r7,-13424
	ctx.r6.s64 = ctx.r7.s64 + -13424;
	// stw r10,-5656(r31)
	PPC_STORE_U32(ctx.r31.u32 + -5656, ctx.r10.u32);
	// add r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 + ctx.r8.u64;
	// stw r11,-5868(r31)
	PPC_STORE_U32(ctx.r31.u32 + -5868, ctx.r11.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// rlwinm r4,r5,4,0,27
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,-5808(r31)
	PPC_STORE_U32(ctx.r31.u32 + -5808, ctx.r10.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r10,-5844(r31)
	PPC_STORE_U32(ctx.r31.u32 + -5844, ctx.r10.u32);
	// stw r9,-5804(r31)
	PPC_STORE_U32(ctx.r31.u32 + -5804, ctx.r9.u32);
	// lis r7,-30643
	ctx.r7.s64 = -2008219648;
	// stw r9,-23968(r31)
	PPC_STORE_U32(ctx.r31.u32 + -23968, ctx.r9.u32);
	// addi r5,r31,-5956
	ctx.r5.s64 = ctx.r31.s64 + -5956;
	// lwzx r11,r4,r6
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r6.u32);
	// lis r6,-30701
	ctx.r6.s64 = -2012020736;
	// stw r8,-6124(r31)
	PPC_STORE_U32(ctx.r31.u32 + -6124, ctx.r8.u32);
	// li r4,43
	ctx.r4.s64 = 43;
	// addi r3,r6,9672
	ctx.r3.s64 = ctx.r6.s64 + 9672;
	// stb r11,5686(r30)
	PPC_STORE_U8(ctx.r30.u32 + 5686, ctx.r11.u8);
	// stw r11,-5840(r31)
	PPC_STORE_U32(ctx.r31.u32 + -5840, ctx.r11.u32);
	// stw r11,26424(r7)
	PPC_STORE_U32(ctx.r7.u32 + 26424, ctx.r11.u32);
	// bl 0x881526c0
	ctx.lr = 0x88137BD4;
	sub_881526C0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r3,-5940(r31)
	PPC_STORE_U32(ctx.r31.u32 + -5940, ctx.r3.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,-5828(r31)
	PPC_STORE_U32(ctx.r31.u32 + -5828, ctx.r11.u32);
	// stw r10,-5824(r31)
	PPC_STORE_U32(ctx.r31.u32 + -5824, ctx.r10.u32);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r9,-144(r31)
	PPC_STORE_U32(ctx.r31.u32 + -144, ctx.r9.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// li r11,4
	ctx.r11.s64 = 4;
	// sth r10,-5880(r31)
	PPC_STORE_U16(ctx.r31.u32 + -5880, ctx.r10.u16);
	// sth r9,-5878(r31)
	PPC_STORE_U16(ctx.r31.u32 + -5878, ctx.r9.u16);
	// stb r11,5682(r30)
	PPC_STORE_U8(ctx.r30.u32 + 5682, ctx.r11.u8);
loc_88137C0C:
	// addi r3,r31,-5956
	ctx.r3.s64 = ctx.r31.s64 + -5956;
	// bl 0x88132858
	ctx.lr = 0x88137C14;
	sub_88132858(ctx, base);
loc_88137C14:
	// bl 0x88137498
	ctx.lr = 0x88137C18;
	sub_88137498(ctx, base);
loc_88137C18:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88137C24"))) PPC_WEAK_FUNC(sub_88137C24);
PPC_FUNC_IMPL(__imp__sub_88137C24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88137C28"))) PPC_WEAK_FUNC(sub_88137C28);
PPC_FUNC_IMPL(__imp__sub_88137C28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r31,r11,26432
	ctx.r31.s64 = ctx.r11.s64 + 26432;
	// lhz r11,78(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 78);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x88137cec
	if (ctx.cr6.lt) goto loc_88137CEC;
	// beq cr6,0x88137c8c
	if (ctx.cr6.eq) goto loc_88137C8C;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x88137eb8
	if (!ctx.cr6.lt) goto loc_88137EB8;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x88152c60
	ctx.lr = 0x88137C64;
	sub_88152C60(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x88152c60
	ctx.lr = 0x88137C6C;
	sub_88152C60(ctx, base);
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// li r11,8
	ctx.r11.s64 = 8;
	// addi r9,r10,-10940
	ctx.r9.s64 = ctx.r10.s64 + -10940;
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r11,76(r31)
	PPC_STORE_U16(ctx.r31.u32 + 76, ctx.r11.u16);
	// sth r10,78(r31)
	PPC_STORE_U16(ctx.r31.u32 + 78, ctx.r10.u16);
	// stb r11,6(r9)
	PPC_STORE_U8(ctx.r9.u32 + 6, ctx.r11.u8);
	// b 0x88137eb8
	goto loc_88137EB8;
loc_88137C8C:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x88152c60
	ctx.lr = 0x88137C94;
	sub_88152C60(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x88152c60
	ctx.lr = 0x88137C9C;
	sub_88152C60(ctx, base);
	// lis r11,-30705
	ctx.r11.s64 = -2012282880;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// li r4,31
	ctx.r4.s64 = 31;
	// addi r3,r11,-20648
	ctx.r3.s64 = ctx.r11.s64 + -20648;
	// bl 0x881526c0
	ctx.lr = 0x88137CB0;
	sub_881526C0(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// lis r10,-30704
	ctx.r10.s64 = -2012217344;
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r10,18992
	ctx.r3.s64 = ctx.r10.s64 + 18992;
	// bl 0x881526c0
	ctx.lr = 0x88137CC4;
	sub_881526C0(ctx, base);
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r3,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r3.u32);
	// addi r8,r9,-10940
	ctx.r8.s64 = ctx.r9.s64 + -10940;
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r11,76(r31)
	PPC_STORE_U16(ctx.r31.u32 + 76, ctx.r11.u16);
	// li r9,2
	ctx.r9.s64 = 2;
	// sth r10,78(r31)
	PPC_STORE_U16(ctx.r31.u32 + 78, ctx.r10.u16);
	// stb r9,6(r8)
	PPC_STORE_U8(ctx.r8.u32 + 6, ctx.r9.u8);
	// b 0x88137eb8
	goto loc_88137EB8;
loc_88137CEC:
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// addi r9,r11,26648
	ctx.r9.s64 = ctx.r11.s64 + 26648;
	// lwz r11,-13376(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -13376);
	// rlwinm r8,r11,0,16,16
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x88137d14
	if (!ctx.cr6.eq) goto loc_88137D14;
	// lwz r11,-13288(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -13288);
	// rlwinm r11,r11,0,16,16
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88137eb8
	if (ctx.cr6.eq) goto loc_88137EB8;
loc_88137D14:
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addi r30,r11,-10940
	ctx.r30.s64 = ctx.r11.s64 + -10940;
	// lwz r11,64(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 64);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// stw r11,1860(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1860, ctx.r11.u32);
	// bne cr6,0x88137d34
	if (!ctx.cr6.eq) goto loc_88137D34;
	// li r11,2
	ctx.r11.s64 = 2;
	// b 0x88137eb4
	goto loc_88137EB4;
loc_88137D34:
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r10,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r10.u32);
	// beq cr6,0x88137dc4
	if (ctx.cr6.eq) goto loc_88137DC4;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x88137dc4
	if (ctx.cr6.eq) goto loc_88137DC4;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x88137eb0
	if (!ctx.cr6.eq) goto loc_88137EB0;
	// lbz r11,31(r9)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 31);
	// ld r10,24(r9)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r9.u32 + 24);
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// beq cr6,0x88137d74
	if (ctx.cr6.eq) goto loc_88137D74;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x881366d0
	ctx.lr = 0x88137D74;
	sub_881366D0(ctx, base);
loc_88137D74:
	// lbz r11,87(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x88137d8c
	if (ctx.cr6.eq) goto loc_88137D8C;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x881366d0
	ctx.lr = 0x88137D8C;
	sub_881366D0(ctx, base);
loc_88137D8C:
	// lbz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lbz r10,86(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 86);
	// lbz r9,82(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// lbz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 84);
	// lbz r7,83(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 83);
	// lbz r6,85(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 85);
	// stw r10,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r10.u32);
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// stb r11,9(r30)
	PPC_STORE_U8(ctx.r30.u32 + 9, ctx.r11.u8);
	// stb r9,1456(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1456, ctx.r9.u8);
	// stb r8,1652(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1652, ctx.r8.u8);
	// stb r7,1458(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1458, ctx.r7.u8);
	// stb r6,1654(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1654, ctx.r6.u8);
	// b 0x88137eb0
	goto loc_88137EB0;
loc_88137DC4:
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x88137ddc
	if (ctx.cr6.eq) goto loc_88137DDC;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x881366d0
	ctx.lr = 0x88137DD4;
	sub_881366D0(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x88137de8
	goto loc_88137DE8;
loc_88137DDC:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x881366d0
	ctx.lr = 0x88137DE4;
	sub_881366D0(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
loc_88137DE8:
	// lwz r11,1860(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1860);
	// stw r10,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r10.u32);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x88137eb0
	if (!ctx.cr6.eq) goto loc_88137EB0;
	// lis r11,-30614
	ctx.r11.s64 = -2006319104;
	// mulli r9,r10,196
	ctx.r9.s64 = ctx.r10.s64 * 196;
	// addi r11,r11,-26520
	ctx.r11.s64 = ctx.r11.s64 + -26520;
	// addi r8,r31,1448
	ctx.r8.s64 = ctx.r31.s64 + 1448;
	// xori r7,r10,1
	ctx.r7.u64 = ctx.r10.u64 ^ 1;
	// add r10,r9,r8
	ctx.r10.u64 = ctx.r9.u64 + ctx.r8.u64;
	// mulli r6,r7,196
	ctx.r6.s64 = ctx.r7.s64 * 196;
	// lbz r8,2(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r7,3(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 3);
	// stw r8,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r8.u32);
	// stb r8,9(r30)
	PPC_STORE_U8(ctx.r30.u32 + 9, ctx.r8.u8);
	// addi r9,r31,1448
	ctx.r9.s64 = ctx.r31.s64 + 1448;
	// stb r7,8(r10)
	PPC_STORE_U8(ctx.r10.u32 + 8, ctx.r7.u8);
	// add r9,r6,r9
	ctx.r9.u64 = ctx.r6.u64 + ctx.r9.u64;
	// lbz r6,3(r11)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r11.u32 + 3);
	// xori r5,r6,1
	ctx.r5.u64 = ctx.r6.u64 ^ 1;
	// stb r5,8(r9)
	PPC_STORE_U8(ctx.r9.u32 + 8, ctx.r5.u8);
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// stb r8,10(r10)
	PPC_STORE_U8(ctx.r10.u32 + 10, ctx.r8.u8);
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// stb r8,10(r9)
	PPC_STORE_U8(ctx.r9.u32 + 10, ctx.r8.u8);
	// lbz r8,5(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 5);
	// stb r8,7(r10)
	PPC_STORE_U8(ctx.r10.u32 + 7, ctx.r8.u8);
	// lbz r8,5(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 5);
	// stb r8,7(r9)
	PPC_STORE_U8(ctx.r9.u32 + 7, ctx.r8.u8);
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// stw r8,164(r10)
	PPC_STORE_U32(ctx.r10.u32 + 164, ctx.r8.u32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// stw r10,164(r9)
	PPC_STORE_U32(ctx.r9.u32 + 164, ctx.r10.u32);
	// lbz r4,7(r11)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r11.u32 + 7);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// stw r10,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r10.u32);
	// stw r10,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r10.u32);
	// cmplwi cr6,r4,255
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 255, ctx.xer);
	// bne cr6,0x88137e8c
	if (!ctx.cr6.eq) goto loc_88137E8C;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,1880(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1880, ctx.r10.u32);
loc_88137E8C:
	// lbz r10,6(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 6);
	// cmplwi cr6,r10,255
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 255, ctx.xer);
	// bne cr6,0x88137ea0
	if (!ctx.cr6.eq) goto loc_88137EA0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,1884(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1884, ctx.r10.u32);
loc_88137EA0:
	// lbz r11,1(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r11,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r11,1888(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1888, ctx.r11.u32);
loc_88137EB0:
	// li r11,1
	ctx.r11.s64 = 1;
loc_88137EB4:
	// sth r11,78(r31)
	PPC_STORE_U16(ctx.r31.u32 + 78, ctx.r11.u16);
loc_88137EB8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88137ED4"))) PPC_WEAK_FUNC(sub_88137ED4);
PPC_FUNC_IMPL(__imp__sub_88137ED4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88137ED8"))) PPC_WEAK_FUNC(sub_88137ED8);
PPC_FUNC_IMPL(__imp__sub_88137ED8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x88137EE0;
	__savegprlr_25(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r31,r11,26280
	ctx.r31.s64 = ctx.r11.s64 + 26280;
	// lhz r11,228(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 228);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bgt cr6,0x881380e4
	if (ctx.cr6.gt) goto loc_881380E4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x88138140
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_88138140;
	// bdzf 4*cr6+eq,0x88138148
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_88138148;
	// bdzf 4*cr6+eq,0x88138150
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_88138150;
	// bdzf 4*cr6+eq,0x88138158
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_88138158;
	// bdzf 4*cr6+eq,0x88138160
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_88138160;
	// bdzf 4*cr6+eq,0x88138168
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_88138168;
	// bdzf 4*cr6+eq,0x88138170
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_88138170;
	// bne cr6,0x88138178
	if (!ctx.cr6.eq) goto loc_88138178;
	// addi r3,r31,152
	ctx.r3.s64 = ctx.r31.s64 + 152;
	// bl 0x88132858
	ctx.lr = 0x88137F28;
	sub_88132858(ctx, base);
	// lis r11,-30642
	ctx.r11.s64 = -2008154112;
	// addi r10,r31,152
	ctx.r10.s64 = ctx.r31.s64 + 152;
	// addi r8,r11,31024
	ctx.r8.s64 = ctx.r11.s64 + 31024;
	// addi r10,r10,376
	ctx.r10.s64 = ctx.r10.s64 + 376;
	// addi r11,r8,12
	ctx.r11.s64 = ctx.r8.s64 + 12;
loc_88137F3C:
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_88137F44:
	// lbz r9,-6(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + -6);
	// lwz r7,-12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + -12);
	// clrlwi r5,r9,28
	ctx.r5.u64 = ctx.r9.u32 & 0xF;
	// lbz r6,-8(r11)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r11.u32 + -8);
	// rlwinm r3,r9,28,4,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 28) & 0xFFFFFFF;
	// lbz r4,-7(r11)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r11.u32 + -7);
	// lbz r9,-5(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + -5);
	// lbz r30,-4(r11)
	ctx.r30.u64 = PPC_LOAD_U8(ctx.r11.u32 + -4);
	// lbz r29,-3(r11)
	ctx.r29.u64 = PPC_LOAD_U8(ctx.r11.u32 + -3);
	// lbz r28,-2(r11)
	ctx.r28.u64 = PPC_LOAD_U8(ctx.r11.u32 + -2);
	// lbz r27,-1(r11)
	ctx.r27.u64 = PPC_LOAD_U8(ctx.r11.u32 + -1);
	// lbz r26,0(r11)
	ctx.r26.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r25,1(r11)
	ctx.r25.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// stw r7,-8(r10)
	PPC_STORE_U32(ctx.r10.u32 + -8, ctx.r7.u32);
	// stw r6,-4(r10)
	PPC_STORE_U32(ctx.r10.u32 + -4, ctx.r6.u32);
	// stw r4,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
	// stw r5,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r5.u32);
	// stw r3,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r3.u32);
	// stw r9,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r9.u32);
	// stw r30,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r30.u32);
	// stw r29,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r29.u32);
	// stb r28,24(r10)
	PPC_STORE_U8(ctx.r10.u32 + 24, ctx.r28.u8);
	// stb r27,25(r10)
	PPC_STORE_U8(ctx.r10.u32 + 25, ctx.r27.u8);
	// stb r26,26(r10)
	PPC_STORE_U8(ctx.r10.u32 + 26, ctx.r26.u8);
	// stb r25,27(r10)
	PPC_STORE_U8(ctx.r10.u32 + 27, ctx.r25.u8);
	// addi r10,r10,36
	ctx.r10.s64 = ctx.r10.s64 + 36;
	// bdnz 0x88137f44
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88137F44;
	// addi r9,r8,492
	ctx.r9.s64 = ctx.r8.s64 + 492;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x88137f3c
	if (ctx.cr6.lt) goto loc_88137F3C;
	// bl 0x88136df8
	ctx.lr = 0x88137FC4;
	sub_88136DF8(ctx, base);
	// lwz r11,464(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 464);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88138078
	if (ctx.cr6.eq) goto loc_88138078;
	// bl 0x881398e0
	ctx.lr = 0x88137FD4;
	sub_881398E0(ctx, base);
	// lis r11,-30704
	ctx.r11.s64 = -2012217344;
	// addi r5,r31,152
	ctx.r5.s64 = ctx.r31.s64 + 152;
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r11,18992
	ctx.r3.s64 = ctx.r11.s64 + 18992;
	// bl 0x881526c0
	ctx.lr = 0x88137FE8;
	sub_881526C0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r3,180(r31)
	PPC_STORE_U32(ctx.r31.u32 + 180, ctx.r3.u32);
	// addi r10,r31,152
	ctx.r10.s64 = ctx.r31.s64 + 152;
	// stw r11,212(r31)
	PPC_STORE_U32(ctx.r31.u32 + 212, ctx.r11.u32);
	// addi r3,r10,1448
	ctx.r3.s64 = ctx.r10.s64 + 1448;
	// bl 0x88134658
	ctx.lr = 0x88138000;
	sub_88134658(ctx, base);
	// lwz r11,244(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 244);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88138018
	if (!ctx.cr6.eq) goto loc_88138018;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x88138048
	goto loc_88138048;
loc_88138018:
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x88138034
	if (!ctx.cr6.eq) goto loc_88138034;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,1609(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1609, ctx.r11.u8);
	// li r9,2
	ctx.r9.s64 = 2;
	// b 0x88138050
	goto loc_88138050;
loc_88138034:
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x8813805c
	if (!ctx.cr6.eq) goto loc_8813805C;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,4
	ctx.r9.s64 = 4;
loc_88138048:
	// stb r11,1609(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1609, ctx.r11.u8);
	// li r11,1
	ctx.r11.s64 = 1;
loc_88138050:
	// stb r10,1610(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1610, ctx.r10.u8);
	// stb r9,1607(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1607, ctx.r9.u8);
	// stb r11,1608(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1608, ctx.r11.u8);
loc_8813805C:
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// li r11,3
	ctx.r11.s64 = 3;
	// addi r9,r10,-10940
	ctx.r9.s64 = ctx.r10.s64 + -10940;
	// sth r11,228(r31)
	PPC_STORE_U16(ctx.r31.u32 + 228, ctx.r11.u16);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,6(r9)
	PPC_STORE_U8(ctx.r9.u32 + 6, ctx.r11.u8);
	// b 0x881380e0
	goto loc_881380E0;
loc_88138078:
	// lis r11,-30651
	ctx.r11.s64 = -2008743936;
	// addi r10,r11,-26112
	ctx.r10.s64 = ctx.r11.s64 + -26112;
	// lbz r9,14(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 14);
	// cmplwi cr6,r9,18
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 18, ctx.xer);
	// bne cr6,0x88138110
	if (!ctx.cr6.eq) goto loc_88138110;
	// lwz r3,220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 220);
	// bl 0x881366d0
	ctx.lr = 0x88138094;
	sub_881366D0(ctx, base);
	// lis r11,-30705
	ctx.r11.s64 = -2012282880;
	// addi r5,r31,152
	ctx.r5.s64 = ctx.r31.s64 + 152;
	// li r4,31
	ctx.r4.s64 = 31;
	// addi r3,r11,-20648
	ctx.r3.s64 = ctx.r11.s64 + -20648;
	// bl 0x881526c0
	ctx.lr = 0x881380A8;
	sub_881526C0(ctx, base);
	// stw r3,160(r31)
	PPC_STORE_U32(ctx.r31.u32 + 160, ctx.r3.u32);
	// lis r10,-30704
	ctx.r10.s64 = -2012217344;
	// addi r5,r31,152
	ctx.r5.s64 = ctx.r31.s64 + 152;
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r10,18992
	ctx.r3.s64 = ctx.r10.s64 + 18992;
	// bl 0x881526c0
	ctx.lr = 0x881380C0;
	sub_881526C0(ctx, base);
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r3,180(r31)
	PPC_STORE_U32(ctx.r31.u32 + 180, ctx.r3.u32);
	// addi r8,r9,-10940
	ctx.r8.s64 = ctx.r9.s64 + -10940;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,2
	ctx.r9.s64 = 2;
loc_881380D8:
	// sth r11,228(r31)
	PPC_STORE_U16(ctx.r31.u32 + 228, ctx.r11.u16);
	// stb r9,6(r8)
	PPC_STORE_U8(ctx.r8.u32 + 6, ctx.r9.u8);
loc_881380E0:
	// sth r10,230(r31)
	PPC_STORE_U16(ctx.r31.u32 + 230, ctx.r10.u16);
loc_881380E4:
	// lwz r11,276(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 276);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88138274
	if (!ctx.cr6.eq) goto loc_88138274;
	// lwz r11,272(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 272);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88138280
	if (ctx.cr6.eq) goto loc_88138280;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,272(r31)
	PPC_STORE_U32(ctx.r31.u32 + 272, ctx.r11.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_88138110:
	// lis r11,-30694
	ctx.r11.s64 = -2011561984;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,30
	ctx.r4.s64 = 30;
	// addi r3,r11,-8992
	ctx.r3.s64 = ctx.r11.s64 + -8992;
	// bl 0x881526c0
	ctx.lr = 0x88138124;
	sub_881526C0(ctx, base);
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r3,152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 152, ctx.r3.u32);
	// addi r8,r10,-10940
	ctx.r8.s64 = ctx.r10.s64 + -10940;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,1
	ctx.r9.s64 = 1;
	// b 0x881380d8
	goto loc_881380D8;
loc_88138140:
	// bl 0x88137c28
	ctx.lr = 0x88138144;
	sub_88137C28(ctx, base);
	// b 0x881380e4
	goto loc_881380E4;
loc_88138148:
	// bl 0x88137168
	ctx.lr = 0x8813814C;
	sub_88137168(ctx, base);
	// b 0x881380e4
	goto loc_881380E4;
loc_88138150:
	// bl 0x881378a0
	ctx.lr = 0x88138154;
	sub_881378A0(ctx, base);
	// b 0x881380e4
	goto loc_881380E4;
loc_88138158:
	// bl 0x88137708
	ctx.lr = 0x8813815C;
	sub_88137708(ctx, base);
	// b 0x881380e4
	goto loc_881380E4;
loc_88138160:
	// bl 0x88136890
	ctx.lr = 0x88138164;
	sub_88136890(ctx, base);
	// b 0x881380e4
	goto loc_881380E4;
loc_88138168:
	// bl 0x88136778
	ctx.lr = 0x8813816C;
	sub_88136778(ctx, base);
	// b 0x881380e4
	goto loc_881380E4;
loc_88138170:
	// bl 0x88136978
	ctx.lr = 0x88138174;
	sub_88136978(ctx, base);
	// b 0x881380e4
	goto loc_881380E4;
loc_88138178:
	// lwz r11,2012(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2012);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88138230
	if (!ctx.cr6.eq) goto loc_88138230;
	// lwz r11,1628(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1628);
	// lwz r10,1824(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1824);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 9, ctx.xer);
	// ble cr6,0x881381a0
	if (!ctx.cr6.gt) goto loc_881381A0;
	// li r11,9
	ctx.r11.s64 = 9;
loc_881381A0:
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
	// ld r10,2016(r31)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r31.u32 + 2016);
	// lwz r11,2024(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2024);
	// lwz r9,504(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 504);
	// stb r8,97(r1)
	PPC_STORE_U8(ctx.r1.u32 + 97, ctx.r8.u8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// stb r11,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, ctx.r11.u8);
	// beq cr6,0x881381d8
	if (ctx.cr6.eq) goto loc_881381D8;
	// lwz r11,256(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 256);
	// li r10,5
	ctx.r10.s64 = 5;
	// stb r10,98(r1)
	PPC_STORE_U8(ctx.r1.u32 + 98, ctx.r10.u8);
	// stb r11,99(r1)
	PPC_STORE_U8(ctx.r1.u32 + 99, ctx.r11.u8);
	// b 0x881381e8
	goto loc_881381E8;
loc_881381D8:
	// lwz r11,240(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 240);
	// lwz r10,256(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 256);
	// stb r11,98(r1)
	PPC_STORE_U8(ctx.r1.u32 + 98, ctx.r11.u8);
	// stb r10,99(r1)
	PPC_STORE_U8(ctx.r1.u32 + 99, ctx.r10.u8);
loc_881381E8:
	// lbz r11,2052(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 2052);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lbz r10,2056(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 2056);
	// lbz r9,2053(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 2053);
	// lbz r8,2057(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 2057);
	// lbz r7,2054(r31)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r31.u32 + 2054);
	// lbz r6,2058(r31)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r31.u32 + 2058);
	// lbz r5,2055(r31)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r31.u32 + 2055);
	// lbz r4,2059(r31)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r31.u32 + 2059);
	// stb r11,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, ctx.r11.u8);
	// stb r10,92(r1)
	PPC_STORE_U8(ctx.r1.u32 + 92, ctx.r10.u8);
	// stb r9,89(r1)
	PPC_STORE_U8(ctx.r1.u32 + 89, ctx.r9.u8);
	// stb r8,93(r1)
	PPC_STORE_U8(ctx.r1.u32 + 93, ctx.r8.u8);
	// stb r7,90(r1)
	PPC_STORE_U8(ctx.r1.u32 + 90, ctx.r7.u8);
	// stb r6,94(r1)
	PPC_STORE_U8(ctx.r1.u32 + 94, ctx.r6.u8);
	// stb r5,91(r1)
	PPC_STORE_U8(ctx.r1.u32 + 91, ctx.r5.u8);
	// stb r4,95(r1)
	PPC_STORE_U8(ctx.r1.u32 + 95, ctx.r4.u8);
	// b 0x88138240
	goto loc_88138240;
loc_88138230:
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x88138240
	if (ctx.cr6.eq) goto loc_88138240;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
loc_88138240:
	// bl 0x8808eb10
	ctx.lr = 0x88138244;
	sub_8808EB10(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,2012(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2012, ctx.r11.u32);
	// lwz r11,236(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 236);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// bne cr6,0x88138260
	if (!ctx.cr6.eq) goto loc_88138260;
	// li r11,1
	ctx.r11.s64 = 1;
loc_88138260:
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// bl 0x88136460
	ctx.lr = 0x88138268;
	sub_88136460(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_88138274:
	// lis r11,32767
	ctx.r11.s64 = 2147418112;
	// ori r11,r11,65535
	ctx.r11.u64 = ctx.r11.u64 | 65535;
	// stw r11,272(r31)
	PPC_STORE_U32(ctx.r31.u32 + 272, ctx.r11.u32);
loc_88138280:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8813828C"))) PPC_WEAK_FUNC(sub_8813828C);
PPC_FUNC_IMPL(__imp__sub_8813828C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88138290"))) PPC_WEAK_FUNC(sub_88138290);
PPC_FUNC_IMPL(__imp__sub_88138290) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r11,r11,26280
	ctx.r11.s64 = ctx.r11.s64 + 26280;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881382AC"))) PPC_WEAK_FUNC(sub_881382AC);
PPC_FUNC_IMPL(__imp__sub_881382AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881382B0"))) PPC_WEAK_FUNC(sub_881382B0);
PPC_FUNC_IMPL(__imp__sub_881382B0) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// li r11,1
	ctx.r11.s64 = 1;
	// addi r9,r10,26280
	ctx.r9.s64 = ctx.r10.s64 + 26280;
	// stw r11,68(r9)
	PPC_STORE_U32(ctx.r9.u32 + 68, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881382C4"))) PPC_WEAK_FUNC(sub_881382C4);
PPC_FUNC_IMPL(__imp__sub_881382C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881382C8"))) PPC_WEAK_FUNC(sub_881382C8);
PPC_FUNC_IMPL(__imp__sub_881382C8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r11,r11,26280
	ctx.r11.s64 = ctx.r11.s64 + 26280;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x881382e4
	if (ctx.cr6.eq) goto loc_881382E4;
	// lwz r3,128(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 128);
	// blr 
	return;
loc_881382E4:
	// lis r3,1
	ctx.r3.s64 = 65536;
	// ori r3,r3,34463
	ctx.r3.u64 = ctx.r3.u64 | 34463;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881382F0"))) PPC_WEAK_FUNC(sub_881382F0);
PPC_FUNC_IMPL(__imp__sub_881382F0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r10,r11,26280
	ctx.r10.s64 = ctx.r11.s64 + 26280;
	// stw r3,36(r10)
	PPC_STORE_U32(ctx.r10.u32 + 36, ctx.r3.u32);
	// stw r4,40(r10)
	PPC_STORE_U32(ctx.r10.u32 + 40, ctx.r4.u32);
	// stw r5,44(r10)
	PPC_STORE_U32(ctx.r10.u32 + 44, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88138308"))) PPC_WEAK_FUNC(sub_88138308);
PPC_FUNC_IMPL(__imp__sub_88138308) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r10,r11,26280
	ctx.r10.s64 = ctx.r11.s64 + 26280;
	// stw r3,140(r10)
	PPC_STORE_U32(ctx.r10.u32 + 140, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88138318"))) PPC_WEAK_FUNC(sub_88138318);
PPC_FUNC_IMPL(__imp__sub_88138318) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r10,r11,26280
	ctx.r10.s64 = ctx.r11.s64 + 26280;
	// lwz r3,140(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 140);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88138328"))) PPC_WEAK_FUNC(sub_88138328);
PPC_FUNC_IMPL(__imp__sub_88138328) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r10,r11,26280
	ctx.r10.s64 = ctx.r11.s64 + 26280;
	// stw r3,28(r10)
	PPC_STORE_U32(ctx.r10.u32 + 28, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88138338"))) PPC_WEAK_FUNC(sub_88138338);
PPC_FUNC_IMPL(__imp__sub_88138338) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r10,r11,26280
	ctx.r10.s64 = ctx.r11.s64 + 26280;
	// lwz r3,28(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88138348"))) PPC_WEAK_FUNC(sub_88138348);
PPC_FUNC_IMPL(__imp__sub_88138348) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// addi r11,r11,26280
	ctx.r11.s64 = ctx.r11.s64 + 26280;
	// stw r3,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r3.u32);
	// bne cr6,0x88138368
	if (!ctx.cr6.eq) goto loc_88138368;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// blr 
	return;
loc_88138368:
	// stw r3,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88138370"))) PPC_WEAK_FUNC(sub_88138370);
PPC_FUNC_IMPL(__imp__sub_88138370) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r10,r11,26280
	ctx.r10.s64 = ctx.r11.s64 + 26280;
	// lwz r3,32(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88138380"))) PPC_WEAK_FUNC(sub_88138380);
PPC_FUNC_IMPL(__imp__sub_88138380) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// li r11,1
	ctx.r11.s64 = 1;
	// addi r9,r10,26280
	ctx.r9.s64 = ctx.r10.s64 + 26280;
	// stw r11,60(r9)
	PPC_STORE_U32(ctx.r9.u32 + 60, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88138394"))) PPC_WEAK_FUNC(sub_88138394);
PPC_FUNC_IMPL(__imp__sub_88138394) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88138398"))) PPC_WEAK_FUNC(sub_88138398);
PPC_FUNC_IMPL(__imp__sub_88138398) {
	PPC_FUNC_PROLOGUE();
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881383A0"))) PPC_WEAK_FUNC(sub_881383A0);
PPC_FUNC_IMPL(__imp__sub_881383A0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r11,26280
	ctx.r30.s64 = ctx.r11.s64 + 26280;
	// lwz r11,72(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 72);
	// cmpw cr6,r11,r3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r3.s32, ctx.xer);
	// beq cr6,0x88138618
	if (ctx.cr6.eq) goto loc_88138618;
	// bl 0x88092288
	ctx.lr = 0x881383D0;
	sub_88092288(ctx, base);
	// cmplwi cr6,r31,14
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 14, ctx.xer);
	// bgt cr6,0x881385f0
	if (ctx.cr6.gt) goto loc_881385F0;
	// lis r12,-30700
	ctx.r12.s64 = -2011955200;
	// rlwinm r0,r31,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,-31760
	ctx.r12.s64 = ctx.r12.s64 + -31760;
	// lwzx r0,r12,r0
	ctx.r0.u64 = PPC_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r31.u64) {
	case 0:
		goto loc_8813842C;
	case 1:
		goto loc_88138454;
	case 2:
		goto loc_88138494;
	case 3:
		goto loc_881384D4;
	case 4:
		goto loc_88138508;
	case 5:
		goto loc_8813853C;
	case 6:
		goto loc_881385F0;
	case 7:
		goto loc_881385F0;
	case 8:
		goto loc_881385F0;
	case 9:
		goto loc_881385F0;
	case 10:
		goto loc_88138564;
	case 11:
		goto loc_88138580;
	case 12:
		goto loc_8813859C;
	case 13:
		goto loc_881385B8;
	case 14:
		goto loc_881385D4;
	default:
		__builtin_unreachable();
	}
	// lbz r0,-31700(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -31700);
	// lbz r0,-31660(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -31660);
	// lbz r0,-31596(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -31596);
	// lbz r0,-31532(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -31532);
	// lbz r0,-31480(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -31480);
	// lbz r0,-31428(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -31428);
	// lbz r0,-31248(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -31248);
	// lbz r0,-31248(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -31248);
	// lbz r0,-31248(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -31248);
	// lbz r0,-31248(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -31248);
	// lbz r0,-31388(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -31388);
	// lbz r0,-31360(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -31360);
	// lbz r0,-31332(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -31332);
	// lbz r0,-31304(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -31304);
	// lbz r0,-31276(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -31276);
loc_8813842C:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,7
	ctx.r3.s64 = 7;
	// bl 0x8813a460
	ctx.lr = 0x88138438;
	sub_8813A460(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,18
	ctx.r3.s64 = 18;
	// bl 0x8813a460
	ctx.lr = 0x88138444;
	sub_8813A460(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x8813a460
	ctx.lr = 0x88138450;
	sub_8813A460(ctx, base);
	// b 0x88138614
	goto loc_88138614;
loc_88138454:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,25
	ctx.r3.s64 = 25;
	// bl 0x8813a460
	ctx.lr = 0x88138460;
	sub_8813A460(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,22
	ctx.r3.s64 = 22;
	// bl 0x8813a460
	ctx.lr = 0x8813846C;
	sub_8813A460(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x8813a460
	ctx.lr = 0x88138478;
	sub_8813A460(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,19
	ctx.r3.s64 = 19;
	// bl 0x8813a460
	ctx.lr = 0x88138484;
	sub_8813A460(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,13
	ctx.r3.s64 = 13;
	// bl 0x8813a460
	ctx.lr = 0x88138490;
	sub_8813A460(ctx, base);
	// b 0x88138614
	goto loc_88138614;
loc_88138494:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,26
	ctx.r3.s64 = 26;
	// bl 0x8813a460
	ctx.lr = 0x881384A0;
	sub_8813A460(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,23
	ctx.r3.s64 = 23;
	// bl 0x8813a460
	ctx.lr = 0x881384AC;
	sub_8813A460(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,9
	ctx.r3.s64 = 9;
	// bl 0x8813a460
	ctx.lr = 0x881384B8;
	sub_8813A460(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x8813a460
	ctx.lr = 0x881384C4;
	sub_8813A460(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,14
	ctx.r3.s64 = 14;
	// bl 0x8813a460
	ctx.lr = 0x881384D0;
	sub_8813A460(ctx, base);
	// b 0x88138614
	goto loc_88138614;
loc_881384D4:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,27
	ctx.r3.s64 = 27;
	// bl 0x8813a460
	ctx.lr = 0x881384E0;
	sub_8813A460(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,10
	ctx.r3.s64 = 10;
	// bl 0x8813a460
	ctx.lr = 0x881384EC;
	sub_8813A460(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,21
	ctx.r3.s64 = 21;
	// bl 0x8813a460
	ctx.lr = 0x881384F8;
	sub_8813A460(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,15
	ctx.r3.s64 = 15;
	// bl 0x8813a460
	ctx.lr = 0x88138504;
	sub_8813A460(ctx, base);
	// b 0x88138614
	goto loc_88138614;
loc_88138508:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x8813a460
	ctx.lr = 0x88138514;
	sub_8813A460(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x8813a460
	ctx.lr = 0x88138520;
	sub_8813A460(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,11
	ctx.r3.s64 = 11;
	// bl 0x8813a460
	ctx.lr = 0x8813852C;
	sub_8813A460(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x8813a460
	ctx.lr = 0x88138538;
	sub_8813A460(ctx, base);
	// b 0x88138614
	goto loc_88138614;
loc_8813853C:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,29
	ctx.r3.s64 = 29;
	// bl 0x8813a460
	ctx.lr = 0x88138548;
	sub_8813A460(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x8813a460
	ctx.lr = 0x88138554;
	sub_8813A460(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x8813a460
	ctx.lr = 0x88138560;
	sub_8813A460(ctx, base);
	// b 0x88138610
	goto loc_88138610;
loc_88138564:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,30
	ctx.r3.s64 = 30;
	// bl 0x8813a460
	ctx.lr = 0x88138570;
	sub_8813A460(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x8813a460
	ctx.lr = 0x8813857C;
	sub_8813A460(ctx, base);
	// b 0x88138614
	goto loc_88138614;
loc_88138580:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,31
	ctx.r3.s64 = 31;
	// bl 0x8813a460
	ctx.lr = 0x8813858C;
	sub_8813A460(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,13
	ctx.r3.s64 = 13;
	// bl 0x8813a460
	ctx.lr = 0x88138598;
	sub_8813A460(ctx, base);
	// b 0x88138614
	goto loc_88138614;
loc_8813859C:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x8813a460
	ctx.lr = 0x881385A8;
	sub_8813A460(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,14
	ctx.r3.s64 = 14;
	// bl 0x8813a460
	ctx.lr = 0x881385B4;
	sub_8813A460(ctx, base);
	// b 0x88138614
	goto loc_88138614;
loc_881385B8:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,33
	ctx.r3.s64 = 33;
	// bl 0x8813a460
	ctx.lr = 0x881385C4;
	sub_8813A460(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,15
	ctx.r3.s64 = 15;
	// bl 0x8813a460
	ctx.lr = 0x881385D0;
	sub_8813A460(ctx, base);
	// b 0x88138614
	goto loc_88138614;
loc_881385D4:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,34
	ctx.r3.s64 = 34;
	// bl 0x8813a460
	ctx.lr = 0x881385E0;
	sub_8813A460(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x8813a460
	ctx.lr = 0x881385EC;
	sub_8813A460(ctx, base);
	// b 0x88138614
	goto loc_88138614;
loc_881385F0:
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt cr6,0x88138600
	if (ctx.cr6.lt) goto loc_88138600;
	// cmpwi cr6,r31,5
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 5, ctx.xer);
	// blt cr6,0x88138614
	if (ctx.cr6.lt) goto loc_88138614;
loc_88138600:
	// cmpwi cr6,r31,10
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 10, ctx.xer);
	// blt cr6,0x88138610
	if (ctx.cr6.lt) goto loc_88138610;
	// cmpwi cr6,r31,15
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 15, ctx.xer);
	// blt cr6,0x88138614
	if (ctx.cr6.lt) goto loc_88138614;
loc_88138610:
	// li r31,-1
	ctx.r31.s64 = -1;
loc_88138614:
	// stw r31,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r31.u32);
loc_88138618:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88138630"))) PPC_WEAK_FUNC(sub_88138630);
PPC_FUNC_IMPL(__imp__sub_88138630) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88138638;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// li r11,10
	ctx.r11.s64 = 10;
	// addi r31,r10,26280
	ctx.r31.s64 = ctx.r10.s64 + 26280;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// addi r10,r31,84
	ctx.r10.s64 = ctx.r31.s64 + 84;
loc_88138660:
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x88138660
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88138660;
	// cmplwi cr6,r30,14
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 14, ctx.xer);
	// bgt cr6,0x88138868
	if (ctx.cr6.gt) goto loc_88138868;
	// lis r12,-30700
	ctx.r12.s64 = -2011955200;
	// rlwinm r0,r30,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,-31096
	ctx.r12.s64 = ctx.r12.s64 + -31096;
	// lwzx r0,r12,r0
	ctx.r0.u64 = PPC_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r30.u64) {
	case 0:
		goto loc_881386C4;
	case 1:
		goto loc_881386F8;
	case 2:
		goto loc_8813873C;
	case 3:
		goto loc_88138780;
	case 4:
		goto loc_881387B4;
	case 5:
		goto loc_88138868;
	case 6:
		goto loc_88138868;
	case 7:
		goto loc_88138868;
	case 8:
		goto loc_88138868;
	case 9:
		goto loc_88138868;
	case 10:
		goto loc_881387E8;
	case 11:
		goto loc_88138800;
	case 12:
		goto loc_88138818;
	case 13:
		goto loc_88138830;
	case 14:
		goto loc_88138848;
	default:
		__builtin_unreachable();
	}
	// lbz r0,-31036(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -31036);
	// lbz r0,-30984(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -30984);
	// lbz r0,-30916(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -30916);
	// lbz r0,-30848(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -30848);
	// lbz r0,-30796(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -30796);
	// lbz r0,-30616(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -30616);
	// lbz r0,-30616(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -30616);
	// lbz r0,-30616(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -30616);
	// lbz r0,-30616(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -30616);
	// lbz r0,-30616(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -30616);
	// lbz r0,-30744(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -30744);
	// lbz r0,-30720(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -30720);
	// lbz r0,-30696(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -30696);
	// lbz r0,-30672(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -30672);
	// lbz r0,-30648(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -30648);
loc_881386C4:
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,7
	ctx.r3.s64 = 7;
	// bl 0x8813a4d0
	ctx.lr = 0x881386D0;
	sub_8813A4D0(ctx, base);
	// stw r3,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r3.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,18
	ctx.r3.s64 = 18;
	// bl 0x8813a4d0
	ctx.lr = 0x881386E0;
	sub_8813A4D0(ctx, base);
	// stw r3,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r3.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x8813a4d0
	ctx.lr = 0x881386F0;
	sub_8813A4D0(ctx, base);
	// stw r3,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r3.u32);
	// b 0x88138868
	goto loc_88138868;
loc_881386F8:
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,22
	ctx.r3.s64 = 22;
	// bl 0x8813a4d0
	ctx.lr = 0x88138704;
	sub_8813A4D0(ctx, base);
	// stw r3,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r3.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x8813a4d0
	ctx.lr = 0x88138714;
	sub_8813A4D0(ctx, base);
	// stw r3,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r3.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,19
	ctx.r3.s64 = 19;
	// bl 0x8813a4d0
	ctx.lr = 0x88138724;
	sub_8813A4D0(ctx, base);
	// stw r3,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r3.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,13
	ctx.r3.s64 = 13;
	// bl 0x8813a4d0
	ctx.lr = 0x88138734;
	sub_8813A4D0(ctx, base);
	// stw r3,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r3.u32);
	// b 0x88138868
	goto loc_88138868;
loc_8813873C:
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,23
	ctx.r3.s64 = 23;
	// bl 0x8813a4d0
	ctx.lr = 0x88138748;
	sub_8813A4D0(ctx, base);
	// stw r3,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r3.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,9
	ctx.r3.s64 = 9;
	// bl 0x8813a4d0
	ctx.lr = 0x88138758;
	sub_8813A4D0(ctx, base);
	// stw r3,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r3.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x8813a4d0
	ctx.lr = 0x88138768;
	sub_8813A4D0(ctx, base);
	// stw r3,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r3.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,14
	ctx.r3.s64 = 14;
	// bl 0x8813a4d0
	ctx.lr = 0x88138778;
	sub_8813A4D0(ctx, base);
	// stw r3,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r3.u32);
	// b 0x88138868
	goto loc_88138868;
loc_88138780:
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,10
	ctx.r3.s64 = 10;
	// bl 0x8813a4d0
	ctx.lr = 0x8813878C;
	sub_8813A4D0(ctx, base);
	// stw r3,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r3.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,21
	ctx.r3.s64 = 21;
	// bl 0x8813a4d0
	ctx.lr = 0x8813879C;
	sub_8813A4D0(ctx, base);
	// stw r3,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r3.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,15
	ctx.r3.s64 = 15;
	// bl 0x8813a4d0
	ctx.lr = 0x881387AC;
	sub_8813A4D0(ctx, base);
	// stw r3,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r3.u32);
	// b 0x88138868
	goto loc_88138868;
loc_881387B4:
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x8813a4d0
	ctx.lr = 0x881387C0;
	sub_8813A4D0(ctx, base);
	// stw r3,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r3.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,11
	ctx.r3.s64 = 11;
	// bl 0x8813a4d0
	ctx.lr = 0x881387D0;
	sub_8813A4D0(ctx, base);
	// stw r3,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r3.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x8813a4d0
	ctx.lr = 0x881387E0;
	sub_8813A4D0(ctx, base);
	// stw r3,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r3.u32);
	// b 0x88138868
	goto loc_88138868;
loc_881387E8:
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,30
	ctx.r3.s64 = 30;
	// bl 0x8813a4d0
	ctx.lr = 0x881387F4;
	sub_8813A4D0(ctx, base);
	// stw r3,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r3.u32);
	// li r3,12
	ctx.r3.s64 = 12;
	// b 0x8813885c
	goto loc_8813885C;
loc_88138800:
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,31
	ctx.r3.s64 = 31;
	// bl 0x8813a4d0
	ctx.lr = 0x8813880C;
	sub_8813A4D0(ctx, base);
	// stw r3,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r3.u32);
	// li r3,13
	ctx.r3.s64 = 13;
	// b 0x8813885c
	goto loc_8813885C;
loc_88138818:
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x8813a4d0
	ctx.lr = 0x88138824;
	sub_8813A4D0(ctx, base);
	// stw r3,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r3.u32);
	// li r3,14
	ctx.r3.s64 = 14;
	// b 0x8813885c
	goto loc_8813885C;
loc_88138830:
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,33
	ctx.r3.s64 = 33;
	// bl 0x8813a4d0
	ctx.lr = 0x8813883C;
	sub_8813A4D0(ctx, base);
	// stw r3,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r3.u32);
	// li r3,15
	ctx.r3.s64 = 15;
	// b 0x8813885c
	goto loc_8813885C;
loc_88138848:
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,34
	ctx.r3.s64 = 34;
	// bl 0x8813a4d0
	ctx.lr = 0x88138854;
	sub_8813A4D0(ctx, base);
	// stw r3,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r3.u32);
	// li r3,16
	ctx.r3.s64 = 16;
loc_8813885C:
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8813a4d0
	ctx.lr = 0x88138864;
	sub_8813A4D0(ctx, base);
	// stw r3,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r3.u32);
loc_88138868:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r30,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r30.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// stw r10,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r10.u32);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// stw r9,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r9.u32);
	// beq cr6,0x88138890
	if (ctx.cr6.eq) goto loc_88138890;
	// stw r29,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r29.u32);
loc_88138890:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8813889c
	if (ctx.cr6.eq) goto loc_8813889C;
	// stw r28,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r28.u32);
loc_8813889C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_881388A4"))) PPC_WEAK_FUNC(sub_881388A4);
PPC_FUNC_IMPL(__imp__sub_881388A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881388A8"))) PPC_WEAK_FUNC(sub_881388A8);
PPC_FUNC_IMPL(__imp__sub_881388A8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r31,r11,26280
	ctx.r31.s64 = ctx.r11.s64 + 26280;
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmplwi cr6,r11,14
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 14, ctx.xer);
	// bgt cr6,0x881389f0
	if (ctx.cr6.gt) goto loc_881389F0;
	// lis r12,-30700
	ctx.r12.s64 = -2011955200;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,-30492
	ctx.r12.s64 = ctx.r12.s64 + -30492;
	// lwzx r0,r12,r0
	ctx.r0.u64 = PPC_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u64) {
	case 0:
		goto loc_88138920;
	case 1:
		goto loc_88138938;
	case 2:
		goto loc_88138958;
	case 3:
		goto loc_88138978;
	case 4:
		goto loc_88138990;
	case 5:
		goto loc_881389F0;
	case 6:
		goto loc_881389F0;
	case 7:
		goto loc_881389F0;
	case 8:
		goto loc_881389F0;
	case 9:
		goto loc_881389F0;
	case 10:
		goto loc_881389A0;
	case 11:
		goto loc_881389B0;
	case 12:
		goto loc_881389C0;
	case 13:
		goto loc_881389D0;
	case 14:
		goto loc_881389E0;
	default:
		__builtin_unreachable();
	}
	// lbz r0,-30432(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -30432);
	// lbz r0,-30408(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -30408);
	// lbz r0,-30376(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -30376);
	// lbz r0,-30344(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -30344);
	// lbz r0,-30320(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -30320);
	// lbz r0,-30224(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -30224);
	// lbz r0,-30224(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -30224);
	// lbz r0,-30224(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -30224);
	// lbz r0,-30224(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -30224);
	// lbz r0,-30224(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -30224);
	// lbz r0,-30304(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -30304);
	// lbz r0,-30288(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -30288);
	// lbz r0,-30272(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -30272);
	// lbz r0,-30256(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -30256);
	// lbz r0,-30240(r19)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r19.u32 + -30240);
loc_88138920:
	// li r3,7
	ctx.r3.s64 = 7;
	// bl 0x8813a3c0
	ctx.lr = 0x88138928;
	sub_8813A3C0(ctx, base);
	// li r3,18
	ctx.r3.s64 = 18;
	// bl 0x8813a3c0
	ctx.lr = 0x88138930;
	sub_8813A3C0(ctx, base);
	// li r3,12
	ctx.r3.s64 = 12;
	// b 0x881389ec
	goto loc_881389EC;
loc_88138938:
	// li r3,22
	ctx.r3.s64 = 22;
	// bl 0x8813a3c0
	ctx.lr = 0x88138940;
	sub_8813A3C0(ctx, base);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x8813a3c0
	ctx.lr = 0x88138948;
	sub_8813A3C0(ctx, base);
	// li r3,19
	ctx.r3.s64 = 19;
	// bl 0x8813a3c0
	ctx.lr = 0x88138950;
	sub_8813A3C0(ctx, base);
	// li r3,13
	ctx.r3.s64 = 13;
	// b 0x881389ec
	goto loc_881389EC;
loc_88138958:
	// li r3,23
	ctx.r3.s64 = 23;
	// bl 0x8813a3c0
	ctx.lr = 0x88138960;
	sub_8813A3C0(ctx, base);
	// li r3,9
	ctx.r3.s64 = 9;
	// bl 0x8813a3c0
	ctx.lr = 0x88138968;
	sub_8813A3C0(ctx, base);
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x8813a3c0
	ctx.lr = 0x88138970;
	sub_8813A3C0(ctx, base);
	// li r3,14
	ctx.r3.s64 = 14;
	// b 0x881389ec
	goto loc_881389EC;
loc_88138978:
	// li r3,10
	ctx.r3.s64 = 10;
	// bl 0x8813a3c0
	ctx.lr = 0x88138980;
	sub_8813A3C0(ctx, base);
	// li r3,21
	ctx.r3.s64 = 21;
	// bl 0x8813a3c0
	ctx.lr = 0x88138988;
	sub_8813A3C0(ctx, base);
	// li r3,15
	ctx.r3.s64 = 15;
	// b 0x881389ec
	goto loc_881389EC;
loc_88138990:
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x8813a3c0
	ctx.lr = 0x88138998;
	sub_8813A3C0(ctx, base);
	// li r3,11
	ctx.r3.s64 = 11;
	// b 0x881389e4
	goto loc_881389E4;
loc_881389A0:
	// li r3,30
	ctx.r3.s64 = 30;
	// bl 0x8813a3c0
	ctx.lr = 0x881389A8;
	sub_8813A3C0(ctx, base);
	// li r3,12
	ctx.r3.s64 = 12;
	// b 0x881389ec
	goto loc_881389EC;
loc_881389B0:
	// li r3,31
	ctx.r3.s64 = 31;
	// bl 0x8813a3c0
	ctx.lr = 0x881389B8;
	sub_8813A3C0(ctx, base);
	// li r3,13
	ctx.r3.s64 = 13;
	// b 0x881389ec
	goto loc_881389EC;
loc_881389C0:
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x8813a3c0
	ctx.lr = 0x881389C8;
	sub_8813A3C0(ctx, base);
	// li r3,14
	ctx.r3.s64 = 14;
	// b 0x881389ec
	goto loc_881389EC;
loc_881389D0:
	// li r3,33
	ctx.r3.s64 = 33;
	// bl 0x8813a3c0
	ctx.lr = 0x881389D8;
	sub_8813A3C0(ctx, base);
	// li r3,15
	ctx.r3.s64 = 15;
	// b 0x881389ec
	goto loc_881389EC;
loc_881389E0:
	// li r3,34
	ctx.r3.s64 = 34;
loc_881389E4:
	// bl 0x8813a3c0
	ctx.lr = 0x881389E8;
	sub_8813A3C0(ctx, base);
	// li r3,16
	ctx.r3.s64 = 16;
loc_881389EC:
	// bl 0x8813a3c0
	ctx.lr = 0x881389F0;
	sub_8813A3C0(ctx, base);
loc_881389F0:
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// stw r10,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88138A14"))) PPC_WEAK_FUNC(sub_88138A14);
PPC_FUNC_IMPL(__imp__sub_88138A14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88138A18"))) PPC_WEAK_FUNC(sub_88138A18);
PPC_FUNC_IMPL(__imp__sub_88138A18) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30651
	ctx.r11.s64 = -2008743936;
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// addi r9,r11,-26112
	ctx.r9.s64 = ctx.r11.s64 + -26112;
	// addi r8,r10,26280
	ctx.r8.s64 = ctx.r10.s64 + 26280;
	// lbz r11,12(r9)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 12);
	// stw r11,56(r8)
	PPC_STORE_U32(ctx.r8.u32 + 56, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88138A34"))) PPC_WEAK_FUNC(sub_88138A34);
PPC_FUNC_IMPL(__imp__sub_88138A34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88138A38"))) PPC_WEAK_FUNC(sub_88138A38);
PPC_FUNC_IMPL(__imp__sub_88138A38) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r31,r11,8424
	ctx.r31.s64 = ctx.r11.s64 + 8424;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r11,17932(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 17932);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88138b90
	if (ctx.cr6.eq) goto loc_88138B90;
	// lwz r11,17936(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 17936);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88138b90
	if (ctx.cr6.eq) goto loc_88138B90;
	// addi r11,r31,17856
	ctx.r11.s64 = ctx.r31.s64 + 17856;
	// addi r8,r11,88
	ctx.r8.s64 = ctx.r11.s64 + 88;
loc_88138A78:
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// li r10,0
	ctx.r10.s64 = 0;
loc_88138A80:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x88138a9c
	if (ctx.cr6.eq) goto loc_88138A9C;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r5,0(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmpw cr6,r9,r5
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r5.s32, ctx.xer);
	// beq cr6,0x88138ab0
	if (ctx.cr6.eq) goto loc_88138AB0;
loc_88138A9C:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,56
	ctx.r11.s64 = ctx.r11.s64 + 56;
	// cmpwi cr6,r10,16
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 16, ctx.xer);
	// blt cr6,0x88138a80
	if (ctx.cr6.lt) goto loc_88138A80;
	// b 0x88138ab4
	goto loc_88138AB4;
loc_88138AB0:
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
loc_88138AB4:
	// lwz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// li r10,0
	ctx.r10.s64 = 0;
loc_88138AC0:
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmpw cr6,r5,r9
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r9.s32, ctx.xer);
	// beq cr6,0x88138b88
	if (ctx.cr6.eq) goto loc_88138B88;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,56
	ctx.r11.s64 = ctx.r11.s64 + 56;
	// cmpwi cr6,r10,16
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 16, ctx.xer);
	// blt cr6,0x88138ac0
	if (ctx.cr6.lt) goto loc_88138AC0;
	// li r10,0
	ctx.r10.s64 = 0;
loc_88138AE0:
	// addi r11,r31,17856
	ctx.r11.s64 = ctx.r31.s64 + 17856;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// cmpw cr6,r8,r11
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x88138a78
	if (ctx.cr6.lt) goto loc_88138A78;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne cr6,0x88138b90
	if (!ctx.cr6.eq) goto loc_88138B90;
	// lwz r11,17992(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 17992);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88138b1c
	if (ctx.cr6.eq) goto loc_88138B1C;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r3,17988(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 17988);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x88138B1C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_88138B1C:
	// lis r9,26214
	ctx.r9.s64 = 1717960704;
	// lwz r11,17940(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 17940);
	// li r10,0
	ctx.r10.s64 = 0;
	// ori r8,r9,26215
	ctx.r8.u64 = ctx.r9.u64 | 26215;
	// stw r10,17992(r31)
	PPC_STORE_U32(ctx.r31.u32 + 17992, ctx.r10.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// mulhw r7,r11,r8
	ctx.r7.s64 = (int64_t(ctx.r11.s32) * int64_t(ctx.r8.s32)) >> 32;
	// stw r9,17936(r31)
	PPC_STORE_U32(ctx.r31.u32 + 17936, ctx.r9.u32);
	// srawi r10,r7,2
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r7.s32 >> 2;
	// li r8,0
	ctx.r8.s64 = 0;
	// rlwinm r9,r10,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// stw r8,17932(r31)
	PPC_STORE_U32(ctx.r31.u32 + 17932, ctx.r8.u32);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r5,r6,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r11,r5,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r5.s64;
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// bl 0x881383a0
	ctx.lr = 0x88138B68;
	sub_881383A0(ctx, base);
	// lis r11,1
	ctx.r11.s64 = 65536;
	// ori r11,r11,34463
	ctx.r11.u64 = ctx.r11.u64 | 34463;
	// stw r11,17984(r31)
	PPC_STORE_U32(ctx.r31.u32 + 17984, ctx.r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_88138B88:
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// b 0x88138ae0
	goto loc_88138AE0;
loc_88138B90:
	// stw r7,17984(r31)
	PPC_STORE_U32(ctx.r31.u32 + 17984, ctx.r7.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88138BA8"))) PPC_WEAK_FUNC(sub_88138BA8);
PPC_FUNC_IMPL(__imp__sub_88138BA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
loc_88138BC4:
	// srawi r11,r31,3
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0x7) != 0);
	ctx.r11.s64 = ctx.r31.s32 >> 3;
	// li r6,0
	ctx.r6.s64 = 0;
	// addze r10,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r10.s64 = temp.s64;
	// srawi r9,r31,3
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0x7) != 0);
	ctx.r9.s64 = ctx.r31.s32 >> 3;
	// rlwinm r5,r10,21,0,10
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 21) & 0xFFE00000;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// li r3,368
	ctx.r3.s64 = 368;
	// rlwinm r7,r8,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r4,r7,r31
	ctx.r4.s64 = ctx.r31.s64 - ctx.r7.s64;
	// rlwinm r4,r4,21,0,10
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 21) & 0xFFE00000;
	// bl 0x881538c0
	ctx.lr = 0x88138BF0;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88138c0c
	if (ctx.cr6.eq) goto loc_88138C0C;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r30,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r30.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
loc_88138C0C:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmpwi cr6,r31,80
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 80, ctx.xer);
	// blt cr6,0x88138bc4
	if (ctx.cr6.lt) goto loc_88138BC4;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88138C30"))) PPC_WEAK_FUNC(sub_88138C30);
PPC_FUNC_IMPL(__imp__sub_88138C30) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// li r5,80
	ctx.r5.s64 = 80;
	// addi r31,r11,26432
	ctx.r31.s64 = ctx.r11.s64 + 26432;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,-248
	ctx.r3.s64 = ctx.r31.s64 + -248;
	// bl 0x88073bd0
	ctx.lr = 0x88138C5C;
	sub_88073BD0(ctx, base);
	// bl 0x8813aec8
	ctx.lr = 0x88138C60;
	sub_8813AEC8(ctx, base);
	// bl 0x881388a8
	ctx.lr = 0x88138C64;
	sub_881388A8(ctx, base);
	// bl 0x88136460
	ctx.lr = 0x88138C68;
	sub_88136460(ctx, base);
	// li r30,10
	ctx.r30.s64 = 10;
loc_88138C6C:
	// bl 0x88152cf0
	ctx.lr = 0x88138C70;
	sub_88152CF0(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x88138c6c
	if (!ctx.cr0.eq) goto loc_88138C6C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,1928
	ctx.r5.s64 = 1928;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x88073bd0
	ctx.lr = 0x88138C88;
	sub_88073BD0(ctx, base);
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,-12784(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12784, ctx.r11.u32);
	// bl 0x88133b68
	ctx.lr = 0x88138C98;
	sub_88133B68(ctx, base);
	// lis r9,-30643
	ctx.r9.s64 = -2008219648;
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r8,-30643
	ctx.r8.s64 = -2008219648;
	// lis r7,-30643
	ctx.r7.s64 = -2008219648;
	// lis r6,-30643
	ctx.r6.s64 = -2008219648;
	// stw r11,26428(r9)
	PPC_STORE_U32(ctx.r9.u32 + 26428, ctx.r11.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,26272(r8)
	PPC_STORE_U32(ctx.r8.u32 + 26272, ctx.r10.u32);
	// stw r9,26276(r7)
	PPC_STORE_U32(ctx.r7.u32 + 26276, ctx.r9.u32);
	// stw r11,26424(r6)
	PPC_STORE_U32(ctx.r6.u32 + 26424, ctx.r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88138CDC"))) PPC_WEAK_FUNC(sub_88138CDC);
PPC_FUNC_IMPL(__imp__sub_88138CDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88138CE0"))) PPC_WEAK_FUNC(sub_88138CE0);
PPC_FUNC_IMPL(__imp__sub_88138CE0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x88152738
	ctx.lr = 0x88138CF4;
	sub_88152738(ctx, base);
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r31,r10,26432
	ctx.r31.s64 = ctx.r10.s64 + 26432;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,-1
	ctx.r8.s64 = -1;
	// addi r3,r31,-248
	ctx.r3.s64 = ctx.r31.s64 + -248;
	// li r5,80
	ctx.r5.s64 = 80;
	// stw r11,-116(r31)
	PPC_STORE_U32(ctx.r31.u32 + -116, ctx.r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r10,-88(r31)
	PPC_STORE_U32(ctx.r31.u32 + -88, ctx.r10.u32);
	// stw r9,-84(r31)
	PPC_STORE_U32(ctx.r31.u32 + -84, ctx.r9.u32);
	// stw r8,-80(r31)
	PPC_STORE_U32(ctx.r31.u32 + -80, ctx.r8.u32);
	// bl 0x88073bd0
	ctx.lr = 0x88138D2C;
	sub_88073BD0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,1928
	ctx.r5.s64 = 1928;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x88073bd0
	ctx.lr = 0x88138D3C;
	sub_88073BD0(ctx, base);
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,-12784(r9)
	PPC_STORE_U32(ctx.r9.u32 + -12784, ctx.r11.u32);
	// bl 0x88133b68
	ctx.lr = 0x88138D4C;
	sub_88133B68(ctx, base);
	// bl 0x88138c30
	ctx.lr = 0x88138D50;
	sub_88138C30(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88138D64"))) PPC_WEAK_FUNC(sub_88138D64);
PPC_FUNC_IMPL(__imp__sub_88138D64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88138D68"))) PPC_WEAK_FUNC(sub_88138D68);
PPC_FUNC_IMPL(__imp__sub_88138D68) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// li r5,144
	ctx.r5.s64 = 144;
	// addi r3,r11,26280
	ctx.r3.s64 = ctx.r11.s64 + 26280;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x88073bd0
	ctx.lr = 0x88138D8C;
	sub_88073BD0(ctx, base);
	// bl 0x88138ce0
	ctx.lr = 0x88138D90;
	sub_88138CE0(ctx, base);
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x88093308
	ctx.lr = 0x88138D98;
	sub_88093308(ctx, base);
	// lis r6,-30628
	ctx.r6.s64 = -2007236608;
	// lis r31,-30643
	ctx.r31.s64 = -2008219648;
	// addi r6,r6,13264
	ctx.r6.s64 = ctx.r6.s64 + 13264;
	// lis r10,-30671
	ctx.r10.s64 = -2010054656;
	// addis r4,r3,12547
	ctx.r4.s64 = ctx.r3.s64 + 822280192;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r4,r4,32765
	ctx.r4.s64 = ctx.r4.s64 + 32765;
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// stw r11,26268(r31)
	PPC_STORE_U32(ctx.r31.u32 + 26268, ctx.r11.u32);
	// rlwinm r9,r5,0,25,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x40;
	// stw r4,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r4.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x88138de4
	if (ctx.cr6.eq) goto loc_88138DE4;
	// lwz r10,92(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 92);
	// rlwinm r10,r10,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x88138de4
	if (ctx.cr6.eq) goto loc_88138DE4;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,26268(r31)
	PPC_STORE_U32(ctx.r31.u32 + 26268, ctx.r10.u32);
loc_88138DE4:
	// lis r6,-30641
	ctx.r6.s64 = -2008088576;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// addi r5,r6,-18916
	ctx.r5.s64 = ctx.r6.s64 + -18916;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
	// mr r7,r11
	ctx.r7.u64 = ctx.r11.u64;
	// stw r11,-648(r5)
	PPC_STORE_U32(ctx.r5.u32 + -648, ctx.r11.u32);
	// stw r11,-652(r5)
	PPC_STORE_U32(ctx.r5.u32 + -652, ctx.r11.u32);
	// stw r11,-5248(r5)
	PPC_STORE_U32(ctx.r5.u32 + -5248, ctx.r11.u32);
	// stw r11,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r11.u32);
	// stw r11,-18916(r6)
	PPC_STORE_U32(ctx.r6.u32 + -18916, ctx.r11.u32);
	// stw r11,-4(r5)
	PPC_STORE_U32(ctx.r5.u32 + -4, ctx.r11.u32);
	// stw r11,-656(r5)
	PPC_STORE_U32(ctx.r5.u32 + -656, ctx.r11.u32);
	// stw r11,-660(r5)
	PPC_STORE_U32(ctx.r5.u32 + -660, ctx.r11.u32);
	// stw r11,-4680(r5)
	PPC_STORE_U32(ctx.r5.u32 + -4680, ctx.r11.u32);
	// stw r11,-5472(r5)
	PPC_STORE_U32(ctx.r5.u32 + -5472, ctx.r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88138E38"))) PPC_WEAK_FUNC(sub_88138E38);
PPC_FUNC_IMPL(__imp__sub_88138E38) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88138E40;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x88138eec
	if (ctx.cr6.eq) goto loc_88138EEC;
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addi r31,r11,-10940
	ctx.r31.s64 = ctx.r11.s64 + -10940;
	// lbz r11,-3025(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + -3025);
	// rlwinm r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88138eec
	if (ctx.cr6.eq) goto loc_88138EEC;
	// lwz r11,20(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r11,120
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 120, ctx.xer);
	// ble cr6,0x88138ef4
	if (!ctx.cr6.gt) goto loc_88138EF4;
	// bl 0x880938f0
	ctx.lr = 0x88138E84;
	sub_880938F0(ctx, base);
	// lis r29,-30643
	ctx.r29.s64 = -2008219648;
	// lis r7,-30597
	ctx.r7.s64 = -2005204992;
	// addi r6,r29,26280
	ctx.r6.s64 = ctx.r29.s64 + 26280;
	// li r11,255
	ctx.r11.s64 = 255;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r11,36(r6)
	PPC_STORE_U32(ctx.r6.u32 + 36, ctx.r11.u32);
	// stw r10,40(r6)
	PPC_STORE_U32(ctx.r6.u32 + 40, ctx.r10.u32);
	// stw r9,44(r6)
	PPC_STORE_U32(ctx.r6.u32 + 44, ctx.r9.u32);
	// stw r8,-13980(r7)
	PPC_STORE_U32(ctx.r7.u32 + -13980, ctx.r8.u32);
	// bl 0x88152738
	ctx.lr = 0x88138EB4;
	sub_88152738(ctx, base);
	// lis r3,-30711
	ctx.r3.s64 = -2012676096;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,29
	ctx.r4.s64 = 29;
	// addi r3,r3,29552
	ctx.r3.s64 = ctx.r3.s64 + 29552;
	// bl 0x881526c0
	ctx.lr = 0x88138EC8;
	sub_881526C0(ctx, base);
	// li r11,6
	ctx.r11.s64 = 6;
	// li r10,6
	ctx.r10.s64 = 6;
	// stw r3,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r3.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,26280(r29)
	PPC_STORE_U32(ctx.r29.u32 + 26280, ctx.r11.u32);
	// stb r10,4(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4, ctx.r10.u8);
	// stb r9,5(r31)
	PPC_STORE_U8(ctx.r31.u32 + 5, ctx.r9.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_88138EEC:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r11.u32);
loc_88138EF4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88138EFC"))) PPC_WEAK_FUNC(sub_88138EFC);
PPC_FUNC_IMPL(__imp__sub_88138EFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88138F00"))) PPC_WEAK_FUNC(sub_88138F00);
PPC_FUNC_IMPL(__imp__sub_88138F00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x88138F08;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lis r9,-30683
	ctx.r9.s64 = -2010841088;
	// addi r30,r11,-10876
	ctx.r30.s64 = ctx.r11.s64 + -10876;
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// li r25,0
	ctx.r25.s64 = 0;
	// addi r31,r11,26648
	ctx.r31.s64 = ctx.r11.s64 + 26648;
	// lwz r3,11608(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11608);
	// li r10,-1
	ctx.r10.s64 = -1;
	// lwz r28,8(r30)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// stw r10,11608(r9)
	PPC_STORE_U32(ctx.r9.u32 + 11608, ctx.r10.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// stw r25,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r25.u32);
	// lwz r27,-13376(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + -13376);
	// lwz r26,-13288(r31)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r31.u32 + -13288);
	// blt cr6,0x88138f50
	if (ctx.cr6.lt) goto loc_88138F50;
	// bl 0x881383a0
	ctx.lr = 0x88138F50;
	sub_881383A0(ctx, base);
loc_88138F50:
	// lwz r9,20(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// lis r10,-30651
	ctx.r10.s64 = -2008743936;
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// stw r25,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r25.u32);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// addi r29,r10,-26112
	ctx.r29.s64 = ctx.r10.s64 + -26112;
	// beq cr6,0x88138fb0
	if (ctx.cr6.eq) goto loc_88138FB0;
	// lbz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 12);
	// lbz r10,9(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 9);
	// lbz r11,10(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lbz r9,11(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lbz r7,13(r31)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r31.u32 + 13);
	// lbz r6,14(r31)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r31.u32 + 14);
	// lbz r5,15(r31)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r31.u32 + 15);
	// lbz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r31.u32 + 16);
	// stb r10,21(r29)
	PPC_STORE_U8(ctx.r29.u32 + 21, ctx.r10.u8);
	// stb r11,22(r29)
	PPC_STORE_U8(ctx.r29.u32 + 22, ctx.r11.u8);
	// stb r9,23(r29)
	PPC_STORE_U8(ctx.r29.u32 + 23, ctx.r9.u8);
	// stb r8,24(r29)
	PPC_STORE_U8(ctx.r29.u32 + 24, ctx.r8.u8);
	// stb r7,26(r29)
	PPC_STORE_U8(ctx.r29.u32 + 26, ctx.r7.u8);
	// stb r6,27(r29)
	PPC_STORE_U8(ctx.r29.u32 + 27, ctx.r6.u8);
	// stb r5,15(r29)
	PPC_STORE_U8(ctx.r29.u32 + 15, ctx.r5.u8);
	// stb r4,19(r29)
	PPC_STORE_U8(ctx.r29.u32 + 19, ctx.r4.u8);
loc_88138FB0:
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// stw r25,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r25.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88138fc8
	if (ctx.cr6.eq) goto loc_88138FC8;
	// bl 0x880f1448
	ctx.lr = 0x88138FC8;
	sub_880F1448(ctx, base);
loc_88138FC8:
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r31,r11,26432
	ctx.r31.s64 = ctx.r11.s64 + 26432;
	// lwz r11,-152(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -152);
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// bgt cr6,0x88139480
	if (ctx.cr6.gt) goto loc_88139480;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x88139128
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_88139128;
	// bdzf 4*cr6+eq,0x88139034
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_88139034;
	// bdzf 4*cr6+eq,0x88139188
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_88139188;
	// bdzf 4*cr6+eq,0x88139480
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_88139480;
	// bdzf 4*cr6+eq,0x881393d4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_881393D4;
	// bne cr6,0x88139460
	if (!ctx.cr6.eq) goto loc_88139460;
	// bl 0x88138ba8
	ctx.lr = 0x88139000;
	sub_88138BA8(ctx, base);
	// bl 0x88138ce0
	ctx.lr = 0x88139004;
	sub_88138CE0(ctx, base);
	// lis r11,-30704
	ctx.r11.s64 = -2012217344;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,29
	ctx.r4.s64 = 29;
	// addi r3,r11,2048
	ctx.r3.s64 = ctx.r11.s64 + 2048;
	// bl 0x881526c0
	ctx.lr = 0x88139018;
	sub_881526C0(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r3,-140(r31)
	PPC_STORE_U32(ctx.r31.u32 + -140, ctx.r3.u32);
	// mr r9,r25
	ctx.r9.u64 = ctx.r25.u64;
	// stb r10,-60(r30)
	PPC_STORE_U8(ctx.r30.u32 + -60, ctx.r10.u8);
	// stb r25,-59(r30)
	PPC_STORE_U8(ctx.r30.u32 + -59, ctx.r25.u8);
	// b 0x8813947c
	goto loc_8813947C;
loc_88139034:
	// bl 0x88136460
	ctx.lr = 0x88139038;
	sub_88136460(ctx, base);
	// bl 0x88152cf0
	ctx.lr = 0x8813903C;
	sub_88152CF0(ctx, base);
	// bl 0x8813aec8
	ctx.lr = 0x88139040;
	sub_8813AEC8(ctx, base);
	// li r28,2
	ctx.r28.s64 = 2;
loc_88139044:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8813a3c0
	ctx.lr = 0x8813904C;
	sub_8813A3C0(ctx, base);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// cmpwi cr6,r28,35
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 35, ctx.xer);
	// blt cr6,0x88139044
	if (ctx.cr6.lt) goto loc_88139044;
	// bl 0x8813a5f0
	ctx.lr = 0x8813905C;
	sub_8813A5F0(ctx, base);
	// bl 0x88152738
	ctx.lr = 0x88139060;
	sub_88152738(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,1928
	ctx.r5.s64 = 1928;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x88073bd0
	ctx.lr = 0x88139070;
	sub_88073BD0(ctx, base);
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// stw r25,-1908(r30)
	PPC_STORE_U32(ctx.r30.u32 + -1908, ctx.r25.u32);
	// bl 0x88133b68
	ctx.lr = 0x8813907C;
	sub_88133B68(ctx, base);
	// bl 0x88138c30
	ctx.lr = 0x88139080;
	sub_88138C30(ctx, base);
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// lis r9,-30704
	ctx.r9.s64 = -2012217344;
	// stw r25,-144(r31)
	PPC_STORE_U32(ctx.r31.u32 + -144, ctx.r25.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r8,r9,1200
	ctx.r8.s64 = ctx.r9.s64 + 1200;
	// stw r10,-92(r31)
	PPC_STORE_U32(ctx.r31.u32 + -92, ctx.r10.u32);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lbz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r29.u32 + 12);
	// stw r11,-96(r31)
	PPC_STORE_U32(ctx.r31.u32 + -96, ctx.r11.u32);
	// beq cr6,0x881390b4
	if (ctx.cr6.eq) goto loc_881390B4;
	// lis r11,-30704
	ctx.r11.s64 = -2012217344;
	// addi r11,r11,1200
	ctx.r11.s64 = ctx.r11.s64 + 1200;
	// b 0x881390bc
	goto loc_881390BC;
loc_881390B4:
	// lis r11,-30711
	ctx.r11.s64 = -2012676096;
	// addi r11,r11,8608
	ctx.r11.s64 = ctx.r11.s64 + 8608;
loc_881390BC:
	// stw r11,-176(r30)
	PPC_STORE_U32(ctx.r30.u32 + -176, ctx.r11.u32);
	// lwz r11,-84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -84);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x881390f8
	if (ctx.cr6.eq) goto loc_881390F8;
	// stw r25,-84(r31)
	PPC_STORE_U32(ctx.r31.u32 + -84, ctx.r25.u32);
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// bl 0x88138c30
	ctx.lr = 0x881390D8;
	sub_88138C30(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x88136178
	ctx.lr = 0x881390E0;
	sub_88136178(ctx, base);
	// li r10,5
	ctx.r10.s64 = 5;
	// li r11,5
	ctx.r11.s64 = 5;
	// stb r25,-59(r30)
	PPC_STORE_U8(ctx.r30.u32 + -59, ctx.r25.u8);
	// mr r9,r25
	ctx.r9.u64 = ctx.r25.u64;
	// stb r10,-60(r30)
	PPC_STORE_U8(ctx.r30.u32 + -60, ctx.r10.u8);
	// b 0x8813947c
	goto loc_8813947C;
loc_881390F8:
	// lis r11,-30694
	ctx.r11.s64 = -2011561984;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,29
	ctx.r4.s64 = 29;
	// addi r3,r11,-8568
	ctx.r3.s64 = ctx.r11.s64 + -8568;
	// bl 0x881526c0
	ctx.lr = 0x8813910C;
	sub_881526C0(ctx, base);
	// li r10,3
	ctx.r10.s64 = 3;
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r3,-136(r31)
	PPC_STORE_U32(ctx.r31.u32 + -136, ctx.r3.u32);
	// mr r9,r25
	ctx.r9.u64 = ctx.r25.u64;
	// stb r10,-60(r30)
	PPC_STORE_U8(ctx.r30.u32 + -60, ctx.r10.u8);
	// stb r25,-59(r30)
	PPC_STORE_U8(ctx.r30.u32 + -59, ctx.r25.u8);
	// b 0x8813947c
	goto loc_8813947C;
loc_88139128:
	// bl 0x88138ba8
	ctx.lr = 0x8813912C;
	sub_88138BA8(ctx, base);
	// lwz r3,-140(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -140);
	// bl 0x88152b00
	ctx.lr = 0x88139134;
	sub_88152B00(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x88139148
	if (ctx.cr6.eq) goto loc_88139148;
	// addi r3,r31,-152
	ctx.r3.s64 = ctx.r31.s64 + -152;
	// bl 0x88138e38
	ctx.lr = 0x88139144;
	sub_88138E38(ctx, base);
	// b 0x88139480
	goto loc_88139480;
loc_88139148:
	// lbz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r29.u32 + 12);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,-30694
	ctx.r9.s64 = -2011561984;
	// stw r10,-92(r31)
	PPC_STORE_U32(ctx.r31.u32 + -92, ctx.r10.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,29
	ctx.r4.s64 = 29;
	// addi r3,r9,-8568
	ctx.r3.s64 = ctx.r9.s64 + -8568;
	// stw r11,-96(r31)
	PPC_STORE_U32(ctx.r31.u32 + -96, ctx.r11.u32);
	// bl 0x881526c0
	ctx.lr = 0x8813916C;
	sub_881526C0(ctx, base);
	// li r10,3
	ctx.r10.s64 = 3;
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r3,-136(r31)
	PPC_STORE_U32(ctx.r31.u32 + -136, ctx.r3.u32);
	// mr r9,r25
	ctx.r9.u64 = ctx.r25.u64;
	// stb r10,-60(r30)
	PPC_STORE_U8(ctx.r30.u32 + -60, ctx.r10.u8);
	// stb r25,-59(r30)
	PPC_STORE_U8(ctx.r30.u32 + -59, ctx.r25.u8);
	// b 0x8813947c
	goto loc_8813947C;
loc_88139188:
	// lwz r3,-140(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -140);
	// bl 0x88152b00
	ctx.lr = 0x88139190;
	sub_88152B00(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x881392b8
	if (!ctx.cr6.eq) goto loc_881392B8;
	// lwz r11,-144(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -144);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bne cr6,0x88139238
	if (!ctx.cr6.eq) goto loc_88139238;
	// lwz r11,-128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -128);
	// lis r10,21845
	ctx.r10.s64 = 1431633920;
	// ori r9,r10,21846
	ctx.r9.u64 = ctx.r10.u64 | 21846;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// mulhw r10,r11,r9
	ctx.r10.s64 = (int64_t(ctx.r11.s32) * int64_t(ctx.r9.s32)) >> 32;
	// rlwinm r9,r10,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 + ctx.r9.u64;
	// subf r11,r8,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r8.s64;
	// stw r11,-128(r31)
	PPC_STORE_U32(ctx.r31.u32 + -128, ctx.r11.u32);
	// bl 0x88138c30
	ctx.lr = 0x881391D4;
	sub_88138C30(ctx, base);
	// lis r6,-30641
	ctx.r6.s64 = -2008088576;
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// addi r5,r6,-18916
	ctx.r5.s64 = ctx.r6.s64 + -18916;
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
	// mr r9,r25
	ctx.r9.u64 = ctx.r25.u64;
	// mr r8,r25
	ctx.r8.u64 = ctx.r25.u64;
	// mr r7,r25
	ctx.r7.u64 = ctx.r25.u64;
	// stw r25,-648(r5)
	PPC_STORE_U32(ctx.r5.u32 + -648, ctx.r25.u32);
	// stw r25,-652(r5)
	PPC_STORE_U32(ctx.r5.u32 + -652, ctx.r25.u32);
	// stw r25,-5248(r5)
	PPC_STORE_U32(ctx.r5.u32 + -5248, ctx.r25.u32);
	// stw r25,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r25.u32);
	// stw r25,-18916(r6)
	PPC_STORE_U32(ctx.r6.u32 + -18916, ctx.r25.u32);
	// stw r25,-4(r5)
	PPC_STORE_U32(ctx.r5.u32 + -4, ctx.r25.u32);
	// stw r25,-656(r5)
	PPC_STORE_U32(ctx.r5.u32 + -656, ctx.r25.u32);
	// stw r25,-660(r5)
	PPC_STORE_U32(ctx.r5.u32 + -660, ctx.r25.u32);
	// stw r25,-4680(r5)
	PPC_STORE_U32(ctx.r5.u32 + -4680, ctx.r25.u32);
	// stw r25,-5472(r5)
	PPC_STORE_U32(ctx.r5.u32 + -5472, ctx.r25.u32);
	// bl 0x880e4860
	ctx.lr = 0x8813921C;
	sub_880E4860(ctx, base);
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
	// stw r25,-124(r31)
	PPC_STORE_U32(ctx.r31.u32 + -124, ctx.r25.u32);
	// mr r9,r25
	ctx.r9.u64 = ctx.r25.u64;
	// stw r25,-120(r31)
	PPC_STORE_U32(ctx.r31.u32 + -120, ctx.r25.u32);
	// stw r25,-12(r31)
	PPC_STORE_U32(ctx.r31.u32 + -12, ctx.r25.u32);
	// lwz r11,-144(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -144);
loc_88139238:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-144(r31)
	PPC_STORE_U32(ctx.r31.u32 + -144, ctx.r11.u32);
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// blt cr6,0x88139250
	if (ctx.cr6.lt) goto loc_88139250;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,-144(r31)
	PPC_STORE_U32(ctx.r31.u32 + -144, ctx.r11.u32);
loc_88139250:
	// lis r10,-30679
	ctx.r10.s64 = -2010578944;
	// lwz r5,-128(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + -128);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r29,r10,-13104
	ctx.r29.s64 = ctx.r10.s64 + -13104;
	// li r4,29
	ctx.r4.s64 = 29;
	// addi r10,r29,-400
	ctx.r10.s64 = ctx.r29.s64 + -400;
	// lwzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// bl 0x881526c0
	ctx.lr = 0x88139270;
	sub_881526C0(ctx, base);
	// lwz r11,-144(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -144);
	// lwz r10,-152(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -152);
	// stw r3,-140(r31)
	PPC_STORE_U32(ctx.r31.u32 + -140, ctx.r3.u32);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// stb r11,-59(r30)
	PPC_STORE_U8(ctx.r30.u32 + -59, ctx.r11.u8);
	// stb r10,-60(r30)
	PPC_STORE_U8(ctx.r30.u32 + -60, ctx.r10.u8);
	// bne cr6,0x88139480
	if (!ctx.cr6.eq) goto loc_88139480;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -128);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x88138630
	ctx.lr = 0x8813929C;
	sub_88138630(ctx, base);
	// lis r9,-30647
	ctx.r9.s64 = -2008481792;
	// lwz r11,48(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 48);
	// lwz r10,52(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 52);
	// addi r8,r9,18412
	ctx.r8.s64 = ctx.r9.s64 + 18412;
	// stw r11,-4(r8)
	PPC_STORE_U32(ctx.r8.u32 + -4, ctx.r11.u32);
	// stw r10,18412(r9)
	PPC_STORE_U32(ctx.r9.u32 + 18412, ctx.r10.u32);
	// b 0x88139480
	goto loc_88139480;
loc_881392B8:
	// lbz r11,14(r29)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r29.u32 + 14);
	// cmplwi cr6,r11,18
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 18, ctx.xer);
	// rlwinm r11,r27,0,16,16
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x8000;
	// bne cr6,0x8813936c
	if (!ctx.cr6.eq) goto loc_8813936C;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88139318
	if (ctx.cr6.eq) goto loc_88139318;
	// stw r25,-116(r31)
	PPC_STORE_U32(ctx.r31.u32 + -116, ctx.r25.u32);
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// lwz r3,-140(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -140);
	// bl 0x88152c60
	ctx.lr = 0x881392E0;
	sub_88152C60(ctx, base);
	// lwz r3,-136(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -136);
	// bl 0x88152c60
	ctx.lr = 0x881392E8;
	sub_88152C60(ctx, base);
	// bl 0x88138c30
	ctx.lr = 0x881392EC;
	sub_88138C30(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x88136178
	ctx.lr = 0x881392F4;
	sub_88136178(ctx, base);
	// li r11,5
	ctx.r11.s64 = 5;
	// li r10,5
	ctx.r10.s64 = 5;
	// stb r25,-59(r30)
	PPC_STORE_U8(ctx.r30.u32 + -59, ctx.r25.u8);
	// stw r11,-152(r31)
	PPC_STORE_U32(ctx.r31.u32 + -152, ctx.r11.u32);
	// addi r3,r31,-152
	ctx.r3.s64 = ctx.r31.s64 + -152;
	// stb r10,-60(r30)
	PPC_STORE_U8(ctx.r30.u32 + -60, ctx.r10.u8);
	// mr r9,r25
	ctx.r9.u64 = ctx.r25.u64;
	// bl 0x88138e38
	ctx.lr = 0x88139314;
	sub_88138E38(ctx, base);
	// b 0x88139480
	goto loc_88139480;
loc_88139318:
	// rlwinm r11,r26,0,16,16
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x8000;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x881393c8
	if (ctx.cr6.eq) goto loc_881393C8;
	// stw r25,-116(r31)
	PPC_STORE_U32(ctx.r31.u32 + -116, ctx.r25.u32);
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// lwz r3,-140(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -140);
	// bl 0x88152c60
	ctx.lr = 0x88139334;
	sub_88152C60(ctx, base);
	// lwz r3,-136(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -136);
	// bl 0x88152c60
	ctx.lr = 0x8813933C;
	sub_88152C60(ctx, base);
	// bl 0x88138c30
	ctx.lr = 0x88139340;
	sub_88138C30(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x88136178
	ctx.lr = 0x88139348;
	sub_88136178(ctx, base);
	// li r11,5
	ctx.r11.s64 = 5;
	// li r10,5
	ctx.r10.s64 = 5;
	// stb r25,-59(r30)
	PPC_STORE_U8(ctx.r30.u32 + -59, ctx.r25.u8);
	// stw r11,-152(r31)
	PPC_STORE_U32(ctx.r31.u32 + -152, ctx.r11.u32);
	// addi r3,r31,-152
	ctx.r3.s64 = ctx.r31.s64 + -152;
	// stb r10,-60(r30)
	PPC_STORE_U8(ctx.r30.u32 + -60, ctx.r10.u8);
	// mr r9,r25
	ctx.r9.u64 = ctx.r25.u64;
	// bl 0x88138e38
	ctx.lr = 0x88139368;
	sub_88138E38(ctx, base);
	// b 0x88139480
	goto loc_88139480;
loc_8813936C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813938c
	if (!ctx.cr6.eq) goto loc_8813938C;
	// rlwinm r11,r26,0,16,16
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x8000;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813938c
	if (!ctx.cr6.eq) goto loc_8813938C;
	// lwz r11,-88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -88);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x881393c8
	if (ctx.cr6.eq) goto loc_881393C8;
loc_8813938C:
	// lwz r3,-140(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -140);
	// bl 0x88152c60
	ctx.lr = 0x88139394;
	sub_88152C60(ctx, base);
	// lwz r3,-136(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -136);
	// bl 0x88152c60
	ctx.lr = 0x8813939C;
	sub_88152C60(ctx, base);
	// bl 0x88138c30
	ctx.lr = 0x881393A0;
	sub_88138C30(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x88136178
	ctx.lr = 0x881393A8;
	sub_88136178(ctx, base);
	// bl 0x880e4c88
	ctx.lr = 0x881393AC;
	sub_880E4C88(ctx, base);
	// li r10,5
	ctx.r10.s64 = 5;
	// li r9,5
	ctx.r9.s64 = 5;
	// stw r25,-88(r31)
	PPC_STORE_U32(ctx.r31.u32 + -88, ctx.r25.u32);
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// stw r10,-152(r31)
	PPC_STORE_U32(ctx.r31.u32 + -152, ctx.r10.u32);
	// stb r9,-60(r30)
	PPC_STORE_U8(ctx.r30.u32 + -60, ctx.r9.u8);
	// stb r25,-59(r30)
	PPC_STORE_U8(ctx.r30.u32 + -59, ctx.r25.u8);
loc_881393C8:
	// addi r3,r31,-152
	ctx.r3.s64 = ctx.r31.s64 + -152;
	// bl 0x88138e38
	ctx.lr = 0x881393D0;
	sub_88138E38(ctx, base);
	// b 0x88139480
	goto loc_88139480;
loc_881393D4:
	// cmplwi cr6,r28,1
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 1, ctx.xer);
	// bne cr6,0x88139424
	if (!ctx.cr6.eq) goto loc_88139424;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r25,-16(r30)
	PPC_STORE_U32(ctx.r30.u32 + -16, ctx.r25.u32);
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
	// stw r25,-12(r30)
	PPC_STORE_U32(ctx.r30.u32 + -12, ctx.r25.u32);
	// stw r11,-84(r31)
	PPC_STORE_U32(ctx.r31.u32 + -84, ctx.r11.u32);
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// mr r9,r25
	ctx.r9.u64 = ctx.r25.u64;
	// stw r25,-8(r30)
	PPC_STORE_U32(ctx.r30.u32 + -8, ctx.r25.u32);
	// stw r25,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r25.u32);
	// stw r25,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r25.u32);
	// bl 0x88136460
	ctx.lr = 0x88139408;
	sub_88136460(ctx, base);
	// bl 0x88152cf0
	ctx.lr = 0x8813940C;
	sub_88152CF0(ctx, base);
	// li r10,2
	ctx.r10.s64 = 2;
	// li r11,2
	ctx.r11.s64 = 2;
	// stb r25,-59(r30)
	PPC_STORE_U8(ctx.r30.u32 + -59, ctx.r25.u8);
	// mr r9,r25
	ctx.r9.u64 = ctx.r25.u64;
	// stb r10,-60(r30)
	PPC_STORE_U8(ctx.r30.u32 + -60, ctx.r10.u8);
	// b 0x8813947c
	goto loc_8813947C;
loc_88139424:
	// cmplwi cr6,r28,2
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 2, ctx.xer);
	// bne cr6,0x88139430
	if (!ctx.cr6.eq) goto loc_88139430;
	// bl 0x88137320
	ctx.lr = 0x88139430;
	sub_88137320(ctx, base);
loc_88139430:
	// bl 0x88137ed8
	ctx.lr = 0x88139434;
	sub_88137ED8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88139454
	if (!ctx.cr6.eq) goto loc_88139454;
	// li r11,2
	ctx.r11.s64 = 2;
	// stb r25,-59(r30)
	PPC_STORE_U8(ctx.r30.u32 + -59, ctx.r25.u8);
	// li r10,2
	ctx.r10.s64 = 2;
	// mr r9,r25
	ctx.r9.u64 = ctx.r25.u64;
	// stw r11,-152(r31)
	PPC_STORE_U32(ctx.r31.u32 + -152, ctx.r11.u32);
	// stb r10,-60(r30)
	PPC_STORE_U8(ctx.r30.u32 + -60, ctx.r10.u8);
loc_88139454:
	// addi r3,r31,-152
	ctx.r3.s64 = ctx.r31.s64 + -152;
	// bl 0x88138e38
	ctx.lr = 0x8813945C;
	sub_88138E38(ctx, base);
	// b 0x88139480
	goto loc_88139480;
loc_88139460:
	// bl 0x88138ba8
	ctx.lr = 0x88139464;
	sub_88138BA8(ctx, base);
	// lwz r3,-140(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -140);
	// bl 0x88152b00
	ctx.lr = 0x8813946C;
	sub_88152B00(ctx, base);
	// subfic r11,r3,0
	ctx.xer.ca = ctx.r3.u32 <= 0;
	ctx.r11.s64 = 0 - ctx.r3.s64;
	// lwz r11,-152(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -152);
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 & ctx.r11.u64;
loc_8813947C:
	// stw r11,-152(r31)
	PPC_STORE_U32(ctx.r31.u32 + -152, ctx.r11.u32);
loc_88139480:
	// bl 0x88152cf0
	ctx.lr = 0x88139484;
	sub_88152CF0(ctx, base);
	// bl 0x88138a38
	ctx.lr = 0x88139488;
	sub_88138A38(ctx, base);
	// lwz r11,-116(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -116);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8813951c
	if (ctx.cr6.eq) goto loc_8813951C;
	// lis r28,-30597
	ctx.r28.s64 = -2005204992;
	// mr r29,r25
	ctx.r29.u64 = ctx.r25.u64;
	// lwz r30,-11932(r28)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r28.u32 + -11932);
loc_881394A0:
	// srawi r11,r29,3
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x7) != 0);
	ctx.r11.s64 = ctx.r29.s32 >> 3;
	// lwz r6,-108(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + -108);
	// li r3,368
	ctx.r3.s64 = 368;
	// addze r10,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r10.s64 = temp.s64;
	// srawi r9,r29,3
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x7) != 0);
	ctx.r9.s64 = ctx.r29.s32 >> 3;
	// rlwinm r5,r10,21,0,10
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 21) & 0xFFE00000;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// rlwinm r7,r8,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r4,r7,r29
	ctx.r4.s64 = ctx.r29.s64 - ctx.r7.s64;
	// rlwinm r4,r4,21,0,10
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 21) & 0xFFE00000;
	// bl 0x881538c0
	ctx.lr = 0x881394CC;
	sub_881538C0(ctx, base);
	// lwz r11,-116(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -116);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x88139510
	if (ctx.cr6.eq) goto loc_88139510;
	// lis r10,547
	ctx.r10.s64 = 35848192;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,12(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// lwz r7,16(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r30,-11932(r28)
	PPC_STORE_U32(ctx.r28.u32 + -11932, ctx.r30.u32);
	// or r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// lwz r11,-112(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -112);
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
	// stw r7,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r7.u32);
loc_88139510:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmpwi cr6,r29,80
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 80, ctx.xer);
	// blt cr6,0x881394a0
	if (ctx.cr6.lt) goto loc_881394A0;
loc_8813951C:
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// lwz r11,26428(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26428);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,26428(r10)
	PPC_STORE_U32(ctx.r10.u32 + 26428, ctx.r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88139534"))) PPC_WEAK_FUNC(sub_88139534);
PPC_FUNC_IMPL(__imp__sub_88139534) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88139538"))) PPC_WEAK_FUNC(sub_88139538);
PPC_FUNC_IMPL(__imp__sub_88139538) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lbz r9,1(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// addi r10,r11,26264
	ctx.r10.s64 = ctx.r11.s64 + 26264;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// addi r11,r10,-17844
	ctx.r11.s64 = ctx.r10.s64 + -17844;
	// beq cr6,0x88139554
	if (ctx.cr6.eq) goto loc_88139554;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_88139554:
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// lbz r9,7(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 7);
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// rlwinm r10,r8,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// lbz r7,6(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 6);
	// extsb r6,r7
	ctx.r6.s64 = ctx.r7.s8;
	// rlwinm r9,r6,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r5,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88139584"))) PPC_WEAK_FUNC(sub_88139584);
PPC_FUNC_IMPL(__imp__sub_88139584) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88139588"))) PPC_WEAK_FUNC(sub_88139588);
PPC_FUNC_IMPL(__imp__sub_88139588) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,88(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// lis r9,-30679
	ctx.r9.s64 = -2010578944;
	// lwz r11,84(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// lis r8,-30597
	ctx.r8.s64 = -2005204992;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r9,-13424
	ctx.r7.s64 = ctx.r9.s64 + -13424;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lis r5,-30643
	ctx.r5.s64 = -2008219648;
	// rlwinm r4,r6,4,0,27
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r9,r8,-10940
	ctx.r9.s64 = ctx.r8.s64 + -10940;
	// lwzx r11,r4,r7
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r7.u32);
	// stw r11,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r11.u32);
	// stw r11,26424(r5)
	PPC_STORE_U32(ctx.r5.u32 + 26424, ctx.r11.u32);
	// stb r11,10(r9)
	PPC_STORE_U8(ctx.r9.u32 + 10, ctx.r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881395C4"))) PPC_WEAK_FUNC(sub_881395C4);
PPC_FUNC_IMPL(__imp__sub_881395C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881395C8"))) PPC_WEAK_FUNC(sub_881395C8);
PPC_FUNC_IMPL(__imp__sub_881395C8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26272(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26272);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x881396c4
	if (!ctx.cr6.eq) goto loc_881396C4;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lis r10,-30700
	ctx.r10.s64 = -2011955200;
	// addi r31,r11,26432
	ctx.r31.s64 = ctx.r11.s64 + 26432;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-27336
	ctx.r4.s64 = ctx.r10.s64 + -27336;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,112(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r11.u32);
	// bl 0x88135ba8
	ctx.lr = 0x88139610;
	sub_88135BA8(ctx, base);
	// lwz r11,-18012(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -18012);
	// lwz r10,-168(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -168);
	// lis r7,-30643
	ctx.r7.s64 = -2008219648;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x88139628
	if (!ctx.cr6.lt) goto loc_88139628;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_88139628:
	// lwz r10,112(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// lwz r9,116(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// rlwinm r8,r10,23,9,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 23) & 0x7FFFFF;
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stw r11,26424(r7)
	PPC_STORE_U32(ctx.r7.u32 + 26424, ctx.r11.u32);
	// blt cr6,0x88139694
	if (ctx.cr6.lt) goto loc_88139694;
	// beq cr6,0x88139684
	if (ctx.cr6.eq) goto loc_88139684;
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// bge cr6,0x881396b8
	if (!ctx.cr6.lt) goto loc_881396B8;
	// lwz r10,88(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// bge cr6,0x88139674
	if (!ctx.cr6.lt) goto loc_88139674;
	// cmplwi cr6,r11,248
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 248, ctx.xer);
	// blt cr6,0x881396b8
	if (ctx.cr6.lt) goto loc_881396B8;
	// li r11,248
	ctx.r11.s64 = 248;
	// b 0x881396b4
	goto loc_881396B4;
loc_88139674:
	// cmplwi cr6,r11,255
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 255, ctx.xer);
	// blt cr6,0x881396b8
	if (ctx.cr6.lt) goto loc_881396B8;
	// li r11,255
	ctx.r11.s64 = 255;
	// b 0x881396b4
	goto loc_881396B4;
loc_88139684:
	// cmplwi cr6,r11,232
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 232, ctx.xer);
	// blt cr6,0x881396b8
	if (ctx.cr6.lt) goto loc_881396B8;
	// li r11,232
	ctx.r11.s64 = 232;
	// b 0x881396b4
	goto loc_881396B4;
loc_88139694:
	// lwz r10,360(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 360);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x881396a8
	if (ctx.cr6.eq) goto loc_881396A8;
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// stw r11,26424(r7)
	PPC_STORE_U32(ctx.r7.u32 + 26424, ctx.r11.u32);
loc_881396A8:
	// cmplwi cr6,r11,208
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 208, ctx.xer);
	// blt cr6,0x881396b8
	if (ctx.cr6.lt) goto loc_881396B8;
	// li r11,208
	ctx.r11.s64 = 208;
loc_881396B4:
	// stw r11,26424(r7)
	PPC_STORE_U32(ctx.r7.u32 + 26424, ctx.r11.u32);
loc_881396B8:
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// addi r9,r10,-10940
	ctx.r9.s64 = ctx.r10.s64 + -10940;
	// stb r11,10(r9)
	PPC_STORE_U8(ctx.r9.u32 + 10, ctx.r11.u8);
loc_881396C4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881396D8"))) PPC_WEAK_FUNC(sub_881396D8);
PPC_FUNC_IMPL(__imp__sub_881396D8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lis r10,-30679
	ctx.r10.s64 = -2010578944;
	// addi r6,r11,26432
	ctx.r6.s64 = ctx.r11.s64 + 26432;
	// addi r5,r10,-13424
	ctx.r5.s64 = ctx.r10.s64 + -13424;
	// li r9,0
	ctx.r9.s64 = 0;
	// lis r4,-30597
	ctx.r4.s64 = -2005204992;
	// lis r3,-30643
	ctx.r3.s64 = -2008219648;
	// lwz r11,88(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 88);
	// addi r4,r4,-10940
	ctx.r4.s64 = ctx.r4.s64 + -10940;
	// lwz r10,84(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 84);
	// li r8,0
	ctx.r8.s64 = 0;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r9,112(r6)
	PPC_STORE_U32(ctx.r6.u32 + 112, ctx.r9.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r8,-18012(r6)
	PPC_STORE_U32(ctx.r6.u32 + -18012, ctx.r8.u32);
	// add r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 + ctx.r10.u64;
	// stw r11,-168(r6)
	PPC_STORE_U32(ctx.r6.u32 + -168, ctx.r11.u32);
	// rlwinm r9,r10,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// lwzx r11,r9,r5
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r5.u32);
	// stb r11,10(r4)
	PPC_STORE_U8(ctx.r4.u32 + 10, ctx.r11.u8);
	// stw r11,26424(r3)
	PPC_STORE_U32(ctx.r3.u32 + 26424, ctx.r11.u32);
	// stw r11,116(r6)
	PPC_STORE_U32(ctx.r6.u32 + 116, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88139734"))) PPC_WEAK_FUNC(sub_88139734);
PPC_FUNC_IMPL(__imp__sub_88139734) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88139738"))) PPC_WEAK_FUNC(sub_88139738);
PPC_FUNC_IMPL(__imp__sub_88139738) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r10,r11,26184
	ctx.r10.s64 = ctx.r11.s64 + 26184;
	// addi r11,r10,8
	ctx.r11.s64 = ctx.r10.s64 + 8;
loc_88139744:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// beq cr6,0x88139768
	if (ctx.cr6.eq) goto loc_88139768;
	// addi r11,r11,40
	ctx.r11.s64 = ctx.r11.s64 + 40;
	// addi r9,r10,88
	ctx.r9.s64 = ctx.r10.s64 + 88;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x88139744
	if (ctx.cr6.lt) goto loc_88139744;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_88139768:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88139770"))) PPC_WEAK_FUNC(sub_88139770);
PPC_FUNC_IMPL(__imp__sub_88139770) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r8,32(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// lbz r5,1(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// rotlwi r4,r9,8
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// lbz r3,2(r10)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r10.u32 + 2);
	// lbz r9,3(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 3);
	// or r5,r4,r5
	ctx.r5.u64 = ctx.r4.u64 | ctx.r5.u64;
	// rlwinm r4,r5,8,0,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00;
	// or r3,r4,r3
	ctx.r3.u64 = ctx.r4.u64 | ctx.r3.u64;
	// rlwinm r5,r3,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 8) & 0xFFFFFF00;
	// or r4,r5,r9
	ctx.r4.u64 = ctx.r5.u64 | ctx.r9.u64;
	// cmplw cr6,r8,r4
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, ctx.xer);
	// bgt cr6,0x8813981c
	if (ctx.cr6.gt) goto loc_8813981C;
	// addi r9,r8,4
	ctx.r9.s64 = ctx.r8.s64 + 4;
	// lwz r5,20(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lbz r4,3(r9)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r9.u32 + 3);
	// lbz r3,2(r9)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + 2);
	// extsb r9,r4
	ctx.r9.s64 = ctx.r4.s8;
	// extsb r7,r3
	ctx.r7.s64 = ctx.r3.s8;
	// cmplw cr6,r5,r9
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x881397e4
	if (ctx.cr6.eq) goto loc_881397E4;
	// mr r6,r9
	ctx.r6.u64 = ctx.r9.u64;
	// stw r9,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r9.u32);
loc_881397E4:
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r9,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r9.u32);
	// bgt 0x8813981c
	if (ctx.cr0.gt) goto loc_8813981C;
	// addi r9,r8,1
	ctx.r9.s64 = ctx.r8.s64 + 1;
	// addi r8,r9,4
	ctx.r8.s64 = ctx.r9.s64 + 4;
	// stw r9,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r9.u32);
	// rlwinm r9,r8,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lbz r5,1(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// lbz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// rotlwi r3,r4,8
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r4.u32, 8);
	// or r10,r3,r5
	ctx.r10.u64 = ctx.r3.u64 | ctx.r5.u64;
	// stw r10,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r10.u32);
loc_8813981C:
	// stw r7,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r7.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r6,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813982C"))) PPC_WEAK_FUNC(sub_8813982C);
PPC_FUNC_IMPL(__imp__sub_8813982C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88139830"))) PPC_WEAK_FUNC(sub_88139830);
PPC_FUNC_IMPL(__imp__sub_88139830) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// li r5,80
	ctx.r5.s64 = 80;
	// addi r3,r11,26184
	ctx.r3.s64 = ctx.r11.s64 + 26184;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x88073bd0
	sub_88073BD0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88139844"))) PPC_WEAK_FUNC(sub_88139844);
PPC_FUNC_IMPL(__imp__sub_88139844) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88139848"))) PPC_WEAK_FUNC(sub_88139848);
PPC_FUNC_IMPL(__imp__sub_88139848) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88139850;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lbz r9,1(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r10,r11,26432
	ctx.r10.s64 = ctx.r11.s64 + 26432;
	// extsb r11,r9
	ctx.r11.s64 = ctx.r9.s8;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// lwz r9,312(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 312);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x881398ac
	if (ctx.cr6.eq) goto loc_881398AC;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,-248
	ctx.r10.s64 = ctx.r10.s64 + -248;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r31,r11,r10
	ctx.r31.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88139770
	ctx.lr = 0x88139894;
	sub_88139770(ctx, base);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// stw r10,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// stw r9,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r9.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_881398AC:
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// lis r9,-30628
	ctx.r9.s64 = -2007236608;
	// subfe r8,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// addi r11,r9,13264
	ctx.r11.s64 = ctx.r9.s64 + 13264;
	// mulli r7,r8,88
	ctx.r7.s64 = ctx.r8.s64 * 88;
	// addi r6,r11,4
	ctx.r6.s64 = ctx.r11.s64 + 4;
	// addi r5,r11,8
	ctx.r5.s64 = ctx.r11.s64 + 8;
	// lwzx r4,r7,r6
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// lwzx r3,r7,r5
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r5.u32);
	// stw r4,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r4.u32);
	// stw r3,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_881398E0"))) PPC_WEAK_FUNC(sub_881398E0);
PPC_FUNC_IMPL(__imp__sub_881398E0) {
	PPC_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071120
	ctx.lr = 0x881398E8;
	__savegprlr_14(ctx, base);
	// li r10,2
	ctx.r10.s64 = 2;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lis r5,-30668
	ctx.r5.s64 = -2009858048;
	// addi r31,r11,26280
	ctx.r31.s64 = ctx.r11.s64 + 26280;
	// lis r6,-30668
	ctx.r6.s64 = -2009858048;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// addi r11,r31,-96
	ctx.r11.s64 = ctx.r31.s64 + -96;
	// lis r7,-30667
	ctx.r7.s64 = -2009792512;
	// lis r8,-30667
	ctx.r8.s64 = -2009792512;
	// lis r9,-30667
	ctx.r9.s64 = -2009792512;
	// lwz r4,244(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 244);
	// lis r10,-30667
	ctx.r10.s64 = -2009792512;
	// addi r11,r11,36
	ctx.r11.s64 = ctx.r11.s64 + 36;
	// li r3,0
	ctx.r3.s64 = 0;
	// lis r28,-30671
	ctx.r28.s64 = -2010054656;
	// lis r29,-30643
	ctx.r29.s64 = -2008219648;
	// lis r30,-30643
	ctx.r30.s64 = -2008219648;
	// addi r5,r5,20616
	ctx.r5.s64 = ctx.r5.s64 + 20616;
	// addi r6,r6,28816
	ctx.r6.s64 = ctx.r6.s64 + 28816;
	// addi r7,r7,-28520
	ctx.r7.s64 = ctx.r7.s64 + -28520;
	// addi r27,r8,-20320
	ctx.r27.s64 = ctx.r8.s64 + -20320;
	// addi r26,r9,-12120
	ctx.r26.s64 = ctx.r9.s64 + -12120;
	// addi r25,r10,-3920
	ctx.r25.s64 = ctx.r10.s64 + -3920;
loc_88139944:
	// addi r10,r31,152
	ctx.r10.s64 = ctx.r31.s64 + 152;
	// stw r4,-32(r11)
	PPC_STORE_U32(ctx.r11.u32 + -32, ctx.r4.u32);
	// li r9,16
	ctx.r9.s64 = 16;
	// stw r3,-28(r11)
	PPC_STORE_U32(ctx.r11.u32 + -28, ctx.r3.u32);
	// stw r10,-36(r11)
	PPC_STORE_U32(ctx.r11.u32 + -36, ctx.r10.u32);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// stw r3,-24(r11)
	PPC_STORE_U32(ctx.r11.u32 + -24, ctx.r3.u32);
	// stw r3,-20(r11)
	PPC_STORE_U32(ctx.r11.u32 + -20, ctx.r3.u32);
	// stw r3,-16(r11)
	PPC_STORE_U32(ctx.r11.u32 + -16, ctx.r3.u32);
	// stw r9,-8(r11)
	PPC_STORE_U32(ctx.r11.u32 + -8, ctx.r9.u32);
	// bne cr6,0x88139978
	if (!ctx.cr6.eq) goto loc_88139978;
	// addi r10,r25,4
	ctx.r10.s64 = ctx.r25.s64 + 4;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_88139978:
	// cmplwi cr6,r4,1
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 1, ctx.xer);
	// bne cr6,0x88139988
	if (!ctx.cr6.eq) goto loc_88139988;
	// addi r10,r26,4
	ctx.r10.s64 = ctx.r26.s64 + 4;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_88139988:
	// cmplwi cr6,r4,2
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 2, ctx.xer);
	// bne cr6,0x88139998
	if (!ctx.cr6.eq) goto loc_88139998;
	// addi r10,r27,4
	ctx.r10.s64 = ctx.r27.s64 + 4;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_88139998:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// beq cr6,0x881399ac
	if (ctx.cr6.eq) goto loc_881399AC;
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// bne cr6,0x881399dc
	if (!ctx.cr6.eq) goto loc_881399DC;
loc_881399AC:
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x881399bc
	if (!ctx.cr6.eq) goto loc_881399BC;
	// addi r10,r7,4
	ctx.r10.s64 = ctx.r7.s64 + 4;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_881399BC:
	// cmplwi cr6,r4,1
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 1, ctx.xer);
	// bne cr6,0x881399cc
	if (!ctx.cr6.eq) goto loc_881399CC;
	// addi r10,r6,4
	ctx.r10.s64 = ctx.r6.s64 + 4;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_881399CC:
	// cmplwi cr6,r4,2
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 2, ctx.xer);
	// bne cr6,0x881399dc
	if (!ctx.cr6.eq) goto loc_881399DC;
	// addi r10,r5,4
	ctx.r10.s64 = ctx.r5.s64 + 4;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_881399DC:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r3,-4(r11)
	PPC_STORE_U32(ctx.r11.u32 + -4, ctx.r3.u32);
	// lbz r24,5(r10)
	ctx.r24.u64 = PPC_LOAD_U8(ctx.r10.u32 + 5);
	// lbz r23,9(r10)
	ctx.r23.u64 = PPC_LOAD_U8(ctx.r10.u32 + 9);
	// lbz r20,10(r10)
	ctx.r20.u64 = PPC_LOAD_U8(ctx.r10.u32 + 10);
	// lbz r18,16(r10)
	ctx.r18.u64 = PPC_LOAD_U8(ctx.r10.u32 + 16);
	// lbz r17,17(r10)
	ctx.r17.u64 = PPC_LOAD_U8(ctx.r10.u32 + 17);
	// lbz r15,11(r10)
	ctx.r15.u64 = PPC_LOAD_U8(ctx.r10.u32 + 11);
	// lbz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 4);
	// rotlwi r9,r9,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// lbz r8,8(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 8);
	// rotlwi r8,r8,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// lbz r21,6(r10)
	ctx.r21.u64 = PPC_LOAD_U8(ctx.r10.u32 + 6);
	// or r9,r9,r24
	ctx.r9.u64 = ctx.r9.u64 | ctx.r24.u64;
	// lbz r14,15(r10)
	ctx.r14.u64 = PPC_LOAD_U8(ctx.r10.u32 + 15);
	// or r8,r8,r23
	ctx.r8.u64 = ctx.r8.u64 | ctx.r23.u64;
	// lbz r22,13(r10)
	ctx.r22.u64 = PPC_LOAD_U8(ctx.r10.u32 + 13);
	// rlwinm r9,r9,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// lbz r19,14(r10)
	ctx.r19.u64 = PPC_LOAD_U8(ctx.r10.u32 + 14);
	// rlwinm r8,r8,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// lbz r16,7(r10)
	ctx.r16.u64 = PPC_LOAD_U8(ctx.r10.u32 + 7);
	// or r9,r9,r21
	ctx.r9.u64 = ctx.r9.u64 | ctx.r21.u64;
	// lbz r10,12(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 12);
	// rotlwi r10,r10,8
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// or r10,r10,r22
	ctx.r10.u64 = ctx.r10.u64 | ctx.r22.u64;
	// or r8,r8,r20
	ctx.r8.u64 = ctx.r8.u64 | ctx.r20.u64;
	// rlwinm r10,r10,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r9,r9,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// or r10,r10,r19
	ctx.r10.u64 = ctx.r10.u64 | ctx.r19.u64;
	// rlwinm r8,r8,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// rotlwi r24,r18,8
	ctx.r24.u64 = __builtin_rotateleft32(ctx.r18.u32, 8);
	// rlwinm r23,r10,8,0,23
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// or r10,r9,r16
	ctx.r10.u64 = ctx.r9.u64 | ctx.r16.u64;
	// or r9,r8,r15
	ctx.r9.u64 = ctx.r8.u64 | ctx.r15.u64;
	// or r24,r24,r17
	ctx.r24.u64 = ctx.r24.u64 | ctx.r17.u64;
	// stw r10,26428(r30)
	PPC_STORE_U32(ctx.r30.u32 + 26428, ctx.r10.u32);
	// or r8,r23,r14
	ctx.r8.u64 = ctx.r23.u64 | ctx.r14.u64;
	// stw r9,26424(r29)
	PPC_STORE_U32(ctx.r29.u32 + 26424, ctx.r9.u32);
	// stw r24,-12(r11)
	PPC_STORE_U32(ctx.r11.u32 + -12, ctx.r24.u32);
	// addi r11,r11,40
	ctx.r11.s64 = ctx.r11.s64 + 40;
	// stw r8,4200(r28)
	PPC_STORE_U32(ctx.r28.u32 + 4200, ctx.r8.u32);
	// bdnz 0x88139944
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88139944;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88139A88"))) PPC_WEAK_FUNC(sub_88139A88);
PPC_FUNC_IMPL(__imp__sub_88139A88) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071124
	ctx.lr = 0x88139A90;
	__savegprlr_15(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// mr r19,r3
	ctx.r19.u64 = ctx.r3.u64;
	// mr r16,r5
	ctx.r16.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,90
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 90, ctx.xer);
	// beq cr6,0x88139ab4
	if (ctx.cr6.eq) goto loc_88139AB4;
loc_88139AA8:
	// li r3,8
	ctx.r3.s64 = 8;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071174
	__restgprlr_15(ctx, base);
	return;
loc_88139AB4:
	// lbz r11,1(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// cmplwi cr6,r11,90
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 90, ctx.xer);
	// bne cr6,0x88139aa8
	if (!ctx.cr6.eq) goto loc_88139AA8;
	// lbz r9,4(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 4);
	// li r10,1
	ctx.r10.s64 = 1;
	// lbz r8,5(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 5);
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// rotlwi r7,r9,8
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// lbz r23,2(r4)
	ctx.r23.u64 = PPC_LOAD_U8(ctx.r4.u32 + 2);
	// lbz r21,3(r4)
	ctx.r21.u64 = PPC_LOAD_U8(ctx.r4.u32 + 3);
	// addi r22,r11,13416
	ctx.r22.s64 = ctx.r11.s64 + 13416;
	// or r6,r7,r8
	ctx.r6.u64 = ctx.r7.u64 | ctx.r8.u64;
	// lbz r5,6(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 6);
	// slw r24,r10,r23
	ctx.r24.u64 = ctx.r23.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r23.u8 & 0x3F));
	// lbz r3,7(r4)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r4.u32 + 7);
	// rlwinm r11,r6,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// slw r10,r10,r21
	ctx.r10.u64 = ctx.r21.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r21.u8 & 0x3F));
	// or r9,r11,r5
	ctx.r9.u64 = ctx.r11.u64 | ctx.r5.u64;
	// add r8,r10,r24
	ctx.r8.u64 = ctx.r10.u64 + ctx.r24.u64;
	// rlwinm r7,r9,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// addic. r11,r8,2
	ctx.xer.ca = ctx.r8.u32 > 4294967293;
	ctx.r11.s64 = ctx.r8.s64 + 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// mr r26,r22
	ctx.r26.u64 = ctx.r22.u64;
	// or r15,r7,r3
	ctx.r15.u64 = ctx.r7.u64 | ctx.r3.u64;
	// rlwinm r20,r11,1,0,30
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// ble 0x88139b34
	if (!ctx.cr0.gt) goto loc_88139B34;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r10,r22,-1
	ctx.r10.s64 = ctx.r22.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88139b34
	if (ctx.cr6.eq) goto loc_88139B34;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_88139B2C:
	// stbu r9,1(r10)
	ea = 1 + ctx.r10.u32;
	PPC_STORE_U8(ea, ctx.r9.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x88139b2c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88139B2C;
loc_88139B34:
	// subfic r11,r21,8
	ctx.xer.ca = ctx.r21.u32 <= 8;
	ctx.r11.s64 = 8 - ctx.r21.s64;
	// lbz r28,8(r4)
	ctx.r28.u64 = PPC_LOAD_U8(ctx.r4.u32 + 8);
	// addi r29,r4,8
	ctx.r29.s64 = ctx.r4.s64 + 8;
	// li r27,8
	ctx.r27.s64 = 8;
	// li r30,0
	ctx.r30.s64 = 0;
	// subf r18,r23,r11
	ctx.r18.s64 = ctx.r11.s64 - ctx.r23.s64;
	// addi r17,r16,-1
	ctx.r17.s64 = ctx.r16.s64 + -1;
	// li r25,0
	ctx.r25.s64 = 0;
	// cmpwi cr6,r16,8
	ctx.cr6.compare<int32_t>(ctx.r16.s32, 8, ctx.xer);
	// ble cr6,0x88139d80
	if (!ctx.cr6.gt) goto loc_88139D80;
loc_88139B5C:
	// cmpw cr6,r27,r17
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r17.s32, ctx.xer);
	// bne cr6,0x88139b6c
	if (!ctx.cr6.eq) goto loc_88139B6C;
	// cmpw cr6,r30,r18
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r18.s32, ctx.xer);
	// bgt cr6,0x88139d80
	if (ctx.cr6.gt) goto loc_88139D80;
loc_88139B6C:
	// rlwinm r10,r28,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0x80;
	// clrlwi r11,r28,24
	ctx.r11.u64 = ctx.r28.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x88139c00
	if (!ctx.cr6.eq) goto loc_88139C00;
	// addi r10,r30,1
	ctx.r10.s64 = ctx.r30.s64 + 1;
	// rlwinm r11,r11,1,24,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFE;
	// clrlwi r30,r10,29
	ctx.r30.u64 = ctx.r10.u32 & 0x7;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x88139ba0
	if (!ctx.cr6.eq) goto loc_88139BA0;
	// lbzu r31,1(r29)
	ea = 1 + ctx.r29.u32;
	ctx.r31.u64 = PPC_LOAD_U8(ea);
	ctx.r29.u32 = ea;
	// addi r27,r27,2
	ctx.r27.s64 = ctx.r27.s64 + 2;
	// lbzu r28,1(r29)
	ea = 1 + ctx.r29.u32;
	ctx.r28.u64 = PPC_LOAD_U8(ea);
	ctx.r29.u32 = ea;
	// b 0x88139bc8
	goto loc_88139BC8;
loc_88139BA0:
	// subfic r9,r30,8
	ctx.xer.ca = ctx.r30.u32 <= 8;
	ctx.r9.s64 = 8 - ctx.r30.s64;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// lbzu r11,1(r29)
	ea = 1 + ctx.r29.u32;
	ctx.r11.u64 = PPC_LOAD_U8(ea);
	ctx.r29.u32 = ea;
	// clrlwi r7,r9,24
	ctx.r7.u64 = ctx.r9.u32 & 0xFF;
	// clrlwi r5,r30,24
	ctx.r5.u64 = ctx.r30.u32 & 0xFF;
	// srw r4,r11,r7
	ctx.r4.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r11.u32 >> (ctx.r7.u8 & 0x3F));
	// slw r3,r11,r5
	ctx.r3.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r5.u8 & 0x3F));
	// or r31,r4,r10
	ctx.r31.u64 = ctx.r4.u64 | ctx.r10.u64;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// clrlwi r28,r3,24
	ctx.r28.u64 = ctx.r3.u32 & 0xFF;
loc_88139BC8:
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// stbx r31,r26,r24
	PPC_STORE_U8(ctx.r26.u32 + ctx.r24.u32, ctx.r31.u8);
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// cmpw cr6,r25,r20
	ctx.cr6.compare<int32_t>(ctx.r25.s32, ctx.r20.s32, ctx.xer);
	// ble cr6,0x88139bf4
	if (!ctx.cr6.gt) goto loc_88139BF4;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// li r25,0
	ctx.r25.s64 = 0;
	// bl 0x880707f0
	ctx.lr = 0x88139BF0;
	sub_880707F0(ctx, base);
	// mr r26,r22
	ctx.r26.u64 = ctx.r22.u64;
loc_88139BF4:
	// stb r31,0(r19)
	PPC_STORE_U8(ctx.r19.u32 + 0, ctx.r31.u8);
	// addi r19,r19,1
	ctx.r19.s64 = ctx.r19.s64 + 1;
	// b 0x88139d78
	goto loc_88139D78;
loc_88139C00:
	// addi r9,r30,1
	ctx.r9.s64 = ctx.r30.s64 + 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// clrlwi r30,r9,29
	ctx.r30.u64 = ctx.r9.u32 & 0x7;
	// rlwinm r28,r11,1,24,30
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFE;
	// mr r9,r23
	ctx.r9.u64 = ctx.r23.u64;
	// cmpwi cr6,r23,8
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 8, ctx.xer);
	// blt cr6,0x88139c68
	if (ctx.cr6.lt) goto loc_88139C68;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x88139c38
	if (!ctx.cr6.eq) goto loc_88139C38;
	// lbzu r10,1(r29)
	ea = 1 + ctx.r29.u32;
	ctx.r10.u64 = PPC_LOAD_U8(ea);
	ctx.r29.u32 = ea;
	// addi r27,r27,2
	ctx.r27.s64 = ctx.r27.s64 + 2;
	// addi r9,r23,-8
	ctx.r9.s64 = ctx.r23.s64 + -8;
	// lbzu r28,1(r29)
	ea = 1 + ctx.r29.u32;
	ctx.r28.u64 = PPC_LOAD_U8(ea);
	ctx.r29.u32 = ea;
	// b 0x88139c78
	goto loc_88139C78;
loc_88139C38:
	// subfic r10,r30,8
	ctx.xer.ca = ctx.r30.u32 <= 8;
	ctx.r10.s64 = 8 - ctx.r30.s64;
	// lbzu r8,1(r29)
	ea = 1 + ctx.r29.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r29.u32 = ea;
	// clrlwi r9,r30,24
	ctx.r9.u64 = ctx.r30.u32 & 0xFF;
	// clrlwi r7,r10,24
	ctx.r7.u64 = ctx.r10.u32 & 0xFF;
	// clrlwi r6,r28,24
	ctx.r6.u64 = ctx.r28.u32 & 0xFF;
	// slw r4,r8,r9
	ctx.r4.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r9.u8 & 0x3F));
	// srw r5,r8,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r7.u8 & 0x3F));
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// or r10,r5,r6
	ctx.r10.u64 = ctx.r5.u64 | ctx.r6.u64;
	// clrlwi r28,r4,24
	ctx.r28.u64 = ctx.r4.u32 & 0xFF;
	// addi r9,r23,-8
	ctx.r9.s64 = ctx.r23.s64 + -8;
	// b 0x88139c78
	goto loc_88139C78;
loc_88139C68:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x88139c78
	if (!ctx.cr6.eq) goto loc_88139C78;
	// lbzu r28,1(r29)
	ea = 1 + ctx.r29.u32;
	ctx.r28.u64 = PPC_LOAD_U8(ea);
	ctx.r29.u32 = ea;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
loc_88139C78:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x88139cc4
	if (!ctx.cr6.gt) goto loc_88139CC4;
	// lbz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r29.u32 + 0);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_88139C88:
	// subfic r9,r30,7
	ctx.xer.ca = ctx.r30.u32 <= 7;
	ctx.r9.s64 = 7 - ctx.r30.s64;
	// clrlwi r8,r11,24
	ctx.r8.u64 = ctx.r11.u32 & 0xFF;
	// clrlwi r7,r9,24
	ctx.r7.u64 = ctx.r9.u32 & 0xFF;
	// addi r6,r30,1
	ctx.r6.s64 = ctx.r30.s64 + 1;
	// srw r5,r8,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r7.u8 & 0x3F));
	// rlwimi r5,r10,1,0,30
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r10.u32, 1) & 0xFFFFFFFE) | (ctx.r5.u64 & 0xFFFFFFFF00000001);
	// clrlwi r30,r6,29
	ctx.r30.u64 = ctx.r6.u32 & 0x7;
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// rlwinm r28,r28,1,24,30
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 1) & 0xFE;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x88139cc0
	if (!ctx.cr6.eq) goto loc_88139CC0;
	// lbzu r11,1(r29)
	ea = 1 + ctx.r29.u32;
	ctx.r11.u64 = PPC_LOAD_U8(ea);
	ctx.r29.u32 = ea;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
loc_88139CC0:
	// bdnz 0x88139c88
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88139C88;
loc_88139CC4:
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r21,0
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// ble cr6,0x88139d14
	if (!ctx.cr6.gt) goto loc_88139D14;
	// lbz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r29.u32 + 0);
	// mtctr r21
	ctx.ctr.u64 = ctx.r21.u64;
loc_88139CD8:
	// subfic r8,r30,7
	ctx.xer.ca = ctx.r30.u32 <= 7;
	ctx.r8.s64 = 7 - ctx.r30.s64;
	// clrlwi r7,r11,24
	ctx.r7.u64 = ctx.r11.u32 & 0xFF;
	// clrlwi r6,r8,24
	ctx.r6.u64 = ctx.r8.u32 & 0xFF;
	// addi r5,r30,1
	ctx.r5.s64 = ctx.r30.s64 + 1;
	// srw r4,r7,r6
	ctx.r4.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r7.u32 >> (ctx.r6.u8 & 0x3F));
	// rlwimi r4,r9,1,0,30
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r9.u32, 1) & 0xFFFFFFFE) | (ctx.r4.u64 & 0xFFFFFFFF00000001);
	// clrlwi r30,r5,29
	ctx.r30.u64 = ctx.r5.u32 & 0x7;
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// rlwinm r28,r28,1,24,30
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 1) & 0xFE;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x88139d10
	if (!ctx.cr6.eq) goto loc_88139D10;
	// lbzu r11,1(r29)
	ea = 1 + ctx.r29.u32;
	ctx.r11.u64 = PPC_LOAD_U8(ea);
	ctx.r29.u32 = ea;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
loc_88139D10:
	// bdnz 0x88139cd8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88139CD8;
loc_88139D14:
	// addic. r31,r9,3
	ctx.xer.ca = ctx.r9.u32 > 4294967292;
	ctx.r31.s64 = ctx.r9.s64 + 3;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// add r4,r26,r24
	ctx.r4.u64 = ctx.r26.u64 + ctx.r24.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// ble 0x88139d40
	if (!ctx.cr0.gt) goto loc_88139D40;
	// subf r10,r10,r4
	ctx.r10.s64 = ctx.r4.s64 - ctx.r10.s64;
	// mtctr r31
	ctx.ctr.u64 = ctx.r31.u64;
	// addi r10,r10,-2
	ctx.r10.s64 = ctx.r10.s64 + -2;
loc_88139D30:
	// lbzu r9,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r9.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbx r9,r4,r11
	PPC_STORE_U8(ctx.r4.u32 + ctx.r11.u32, ctx.r9.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bdnz 0x88139d30
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88139D30;
loc_88139D40:
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// bl 0x88072260
	ctx.lr = 0x88139D4C;
	sub_88072260(ctx, base);
	// add r25,r31,r25
	ctx.r25.u64 = ctx.r31.u64 + ctx.r25.u64;
	// add r19,r31,r19
	ctx.r19.u64 = ctx.r31.u64 + ctx.r19.u64;
	// add r26,r31,r26
	ctx.r26.u64 = ctx.r31.u64 + ctx.r26.u64;
	// cmpw cr6,r25,r20
	ctx.cr6.compare<int32_t>(ctx.r25.s32, ctx.r20.s32, ctx.xer);
	// ble cr6,0x88139d78
	if (!ctx.cr6.gt) goto loc_88139D78;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// li r25,0
	ctx.r25.s64 = 0;
	// bl 0x880707f0
	ctx.lr = 0x88139D74;
	sub_880707F0(ctx, base);
	// mr r26,r22
	ctx.r26.u64 = ctx.r22.u64;
loc_88139D78:
	// cmpw cr6,r27,r16
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r16.s32, ctx.xer);
	// blt cr6,0x88139b5c
	if (ctx.cr6.lt) goto loc_88139B5C;
loc_88139D80:
	// mr r3,r15
	ctx.r3.u64 = ctx.r15.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071174
	__restgprlr_15(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88139D8C"))) PPC_WEAK_FUNC(sub_88139D8C);
PPC_FUNC_IMPL(__imp__sub_88139D8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88139D90"))) PPC_WEAK_FUNC(sub_88139D90);
PPC_FUNC_IMPL(__imp__sub_88139D90) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071130
	ctx.lr = 0x88139D98;
	__savegprlr_18(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r19,r5
	ctx.r19.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,90
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 90, ctx.xer);
	// beq cr6,0x88139dc0
	if (ctx.cr6.eq) goto loc_88139DC0;
loc_88139DB4:
	// li r3,8
	ctx.r3.s64 = 8;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x88071180
	__restgprlr_18(ctx, base);
	return;
loc_88139DC0:
	// lbz r11,1(r27)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r27.u32 + 1);
	// cmplwi cr6,r11,90
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 90, ctx.xer);
	// bne cr6,0x88139db4
	if (!ctx.cr6.eq) goto loc_88139DB4;
	// lbz r11,4(r27)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r27.u32 + 4);
	// li r10,1
	ctx.r10.s64 = 1;
	// lbz r9,5(r27)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r27.u32 + 5);
	// rotlwi r8,r11,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// lbz r21,3(r27)
	ctx.r21.u64 = PPC_LOAD_U8(ctx.r27.u32 + 3);
	// lbz r7,6(r27)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r27.u32 + 6);
	// or r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 | ctx.r9.u64;
	// lbz r20,2(r27)
	ctx.r20.u64 = PPC_LOAD_U8(ctx.r27.u32 + 2);
	// slw r11,r10,r21
	ctx.r11.u64 = ctx.r21.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r21.u8 & 0x3F));
	// lbz r5,7(r27)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r27.u32 + 7);
	// rlwinm r4,r6,8,0,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// slw r25,r10,r20
	ctx.r25.u64 = ctx.r20.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r20.u8 & 0x3F));
	// or r3,r4,r7
	ctx.r3.u64 = ctx.r4.u64 | ctx.r7.u64;
	// addi r24,r11,2
	ctx.r24.s64 = ctx.r11.s64 + 2;
	// rlwinm r9,r3,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 8) & 0xFFFFFF00;
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// add. r11,r24,r25
	ctx.r11.u64 = ctx.r24.u64 + ctx.r25.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// or r18,r9,r5
	ctx.r18.u64 = ctx.r9.u64 | ctx.r5.u64;
	// addi r26,r10,25904
	ctx.r26.s64 = ctx.r10.s64 + 25904;
	// ble 0x88139e38
	if (!ctx.cr0.gt) goto loc_88139E38;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r10,r26,-1
	ctx.r10.s64 = ctx.r26.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88139e38
	if (ctx.cr6.eq) goto loc_88139E38;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_88139E30:
	// stbu r9,1(r10)
	ea = 1 + ctx.r10.u32;
	PPC_STORE_U8(ea, ctx.r9.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x88139e30
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88139E30;
loc_88139E38:
	// cmpw cr6,r25,r18
	ctx.cr6.compare<int32_t>(ctx.r25.s32, ctx.r18.s32, ctx.xer);
	// ble cr6,0x88139e5c
	if (!ctx.cr6.gt) goto loc_88139E5C;
	// mr r5,r18
	ctx.r5.u64 = ctx.r18.u64;
	// addi r4,r27,8
	ctx.r4.s64 = ctx.r27.s64 + 8;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88072260
	ctx.lr = 0x88139E50;
	sub_88072260(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x88071180
	__restgprlr_18(ctx, base);
	return;
loc_88139E5C:
	// addi r31,r27,8
	ctx.r31.s64 = ctx.r27.s64 + 8;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// bl 0x88072260
	ctx.lr = 0x88139E70;
	sub_88072260(ctx, base);
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88072260
	ctx.lr = 0x88139E80;
	sub_88072260(ctx, base);
	// addi r30,r25,8
	ctx.r30.s64 = ctx.r25.s64 + 8;
	// add r11,r25,r29
	ctx.r11.u64 = ctx.r25.u64 + ctx.r29.u64;
	// li r31,0
	ctx.r31.s64 = 0;
	// cmpw cr6,r30,r19
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r19.s32, ctx.xer);
	// bge cr6,0x8813a108
	if (!ctx.cr6.lt) goto loc_8813A108;
	// addi r22,r19,-1
	ctx.r22.s64 = ctx.r19.s64 + -1;
	// addi r23,r11,-1
	ctx.r23.s64 = ctx.r11.s64 + -1;
loc_88139E9C:
	// cmpw cr6,r30,r22
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r22.s32, ctx.xer);
	// bne cr6,0x88139eb4
	if (!ctx.cr6.eq) goto loc_88139EB4;
	// subfic r11,r21,8
	ctx.xer.ca = ctx.r21.u32 <= 8;
	ctx.r11.s64 = 8 - ctx.r21.s64;
	// subf r10,r20,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r20.s64;
	// cmpw cr6,r31,r10
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r10.s32, ctx.xer);
	// bgt cr6,0x8813a108
	if (ctx.cr6.gt) goto loc_8813A108;
loc_88139EB4:
	// subfic r11,r31,7
	ctx.xer.ca = ctx.r31.u32 <= 7;
	ctx.r11.s64 = 7 - ctx.r31.s64;
	// lbzx r10,r30,r27
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r27.u32);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// clrlwi r9,r11,24
	ctx.r9.u64 = ctx.r11.u32 & 0xFF;
	// srw r8,r10,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r9.u8 & 0x3F));
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x88139ffc
	if (!ctx.cr6.eq) goto loc_88139FFC;
	// li r28,0
	ctx.r28.s64 = 0;
	// cmpwi cr6,r31,7
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 7, ctx.xer);
	// ble cr6,0x88139ee8
	if (!ctx.cr6.gt) goto loc_88139EE8;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
loc_88139EE8:
	// li r11,2
	ctx.r11.s64 = 2;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_88139EF0:
	// subfic r10,r31,7
	ctx.xer.ca = ctx.r31.u32 <= 7;
	ctx.r10.s64 = 7 - ctx.r31.s64;
	// lbzx r7,r30,r27
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r27.u32);
	// clrlwi r9,r28,24
	ctx.r9.u64 = ctx.r28.u32 & 0xFF;
	// clrlwi r8,r10,24
	ctx.r8.u64 = ctx.r10.u32 & 0xFF;
	// addi r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 1;
	// srw r6,r7,r8
	ctx.r6.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r7.u32 >> (ctx.r8.u8 & 0x3F));
	// rlwimi r6,r9,1,24,30
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r9.u32, 1) & 0xFE) | (ctx.r6.u64 & 0xFFFFFFFFFFFFFF01);
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// clrlwi r10,r6,24
	ctx.r10.u64 = ctx.r6.u32 & 0xFF;
	// ble cr6,0x88139f20
	if (!ctx.cr6.gt) goto loc_88139F20;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
loc_88139F20:
	// subfic r8,r11,7
	ctx.xer.ca = ctx.r11.u32 <= 7;
	ctx.r8.s64 = 7 - ctx.r11.s64;
	// lbzx r5,r30,r27
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r27.u32);
	// clrlwi r7,r10,24
	ctx.r7.u64 = ctx.r10.u32 & 0xFF;
	// clrlwi r6,r8,24
	ctx.r6.u64 = ctx.r8.u32 & 0xFF;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// srw r4,r5,r6
	ctx.r4.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r5.u32 >> (ctx.r6.u8 & 0x3F));
	// rlwimi r4,r7,1,24,30
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r7.u32, 1) & 0xFE) | (ctx.r4.u64 & 0xFFFFFFFFFFFFFF01);
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// clrlwi r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	// ble cr6,0x88139f50
	if (!ctx.cr6.gt) goto loc_88139F50;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
loc_88139F50:
	// subfic r8,r11,7
	ctx.xer.ca = ctx.r11.u32 <= 7;
	ctx.r8.s64 = 7 - ctx.r11.s64;
	// lbzx r5,r30,r27
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r27.u32);
	// clrlwi r7,r10,24
	ctx.r7.u64 = ctx.r10.u32 & 0xFF;
	// clrlwi r6,r8,24
	ctx.r6.u64 = ctx.r8.u32 & 0xFF;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// srw r4,r5,r6
	ctx.r4.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r5.u32 >> (ctx.r6.u8 & 0x3F));
	// rlwimi r4,r7,1,24,30
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r7.u32, 1) & 0xFE) | (ctx.r4.u64 & 0xFFFFFFFFFFFFFF01);
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// clrlwi r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	// ble cr6,0x88139f80
	if (!ctx.cr6.gt) goto loc_88139F80;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
loc_88139F80:
	// subfic r8,r11,7
	ctx.xer.ca = ctx.r11.u32 <= 7;
	ctx.r8.s64 = 7 - ctx.r11.s64;
	// lbzx r5,r30,r27
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r27.u32);
	// clrlwi r7,r10,24
	ctx.r7.u64 = ctx.r10.u32 & 0xFF;
	// clrlwi r6,r8,24
	ctx.r6.u64 = ctx.r8.u32 & 0xFF;
	// addi r31,r11,1
	ctx.r31.s64 = ctx.r11.s64 + 1;
	// srw r4,r5,r6
	ctx.r4.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r5.u32 >> (ctx.r6.u8 & 0x3F));
	// rlwimi r4,r7,1,24,30
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r7.u32, 1) & 0xFE) | (ctx.r4.u64 & 0xFFFFFFFFFFFFFF01);
	// cmpwi cr6,r31,7
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 7, ctx.xer);
	// clrlwi r28,r4,24
	ctx.r28.u64 = ctx.r4.u32 & 0xFF;
	// ble cr6,0x88139fb0
	if (!ctx.cr6.gt) goto loc_88139FB0;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
loc_88139FB0:
	// bdnz 0x88139ef0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88139EF0;
	// stbx r28,r25,r26
	PPC_STORE_U8(ctx.r25.u32 + ctx.r26.u32, ctx.r28.u8);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// addi r4,r26,1
	ctx.r4.s64 = ctx.r26.s64 + 1;
	// add r29,r25,r26
	ctx.r29.u64 = ctx.r25.u64 + ctx.r26.u64;
	// bl 0x880707f0
	ctx.lr = 0x88139FCC;
	sub_880707F0(ctx, base);
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// ble cr6,0x88139ff0
	if (!ctx.cr6.gt) goto loc_88139FF0;
	// addi r11,r29,-1
	ctx.r11.s64 = ctx.r29.s64 + -1;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x88139ff0
	if (ctx.cr6.eq) goto loc_88139FF0;
	// mtctr r24
	ctx.ctr.u64 = ctx.r24.u64;
loc_88139FE8:
	// stbu r10,1(r11)
	ea = 1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r10.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x88139fe8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88139FE8;
loc_88139FF0:
	// stb r28,1(r23)
	PPC_STORE_U8(ctx.r23.u32 + 1, ctx.r28.u8);
	// addi r23,r23,1
	ctx.r23.s64 = ctx.r23.s64 + 1;
	// b 0x8813a100
	goto loc_8813A100;
loc_88139FFC:
	// li r11,0
	ctx.r11.s64 = 0;
	// cmpwi cr6,r31,7
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 7, ctx.xer);
	// ble cr6,0x8813a010
	if (!ctx.cr6.gt) goto loc_8813A010;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
loc_8813A010:
	// lbz r10,2(r27)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r27.u32 + 2);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x8813a050
	if (!ctx.cr6.gt) goto loc_8813A050;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8813A020:
	// subfic r10,r31,7
	ctx.xer.ca = ctx.r31.u32 <= 7;
	ctx.r10.s64 = 7 - ctx.r31.s64;
	// lbzx r9,r30,r27
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r27.u32);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// clrlwi r8,r10,24
	ctx.r8.u64 = ctx.r10.u32 & 0xFF;
	// cmpwi cr6,r31,7
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 7, ctx.xer);
	// srw r7,r9,r8
	ctx.r7.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r8.u8 & 0x3F));
	// rlwimi r7,r11,1,0,30
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r11.u32, 1) & 0xFFFFFFFE) | (ctx.r7.u64 & 0xFFFFFFFF00000001);
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
	// ble cr6,0x8813a04c
	if (!ctx.cr6.gt) goto loc_8813A04C;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
loc_8813A04C:
	// bdnz 0x8813a020
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8813A020;
loc_8813A050:
	// lbz r9,3(r27)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r27.u32 + 3);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x8813a094
	if (!ctx.cr6.gt) goto loc_8813A094;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8813A064:
	// subfic r9,r31,7
	ctx.xer.ca = ctx.r31.u32 <= 7;
	ctx.r9.s64 = 7 - ctx.r31.s64;
	// lbzx r8,r30,r27
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r27.u32);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// clrlwi r7,r9,24
	ctx.r7.u64 = ctx.r9.u32 & 0xFF;
	// cmpwi cr6,r31,7
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 7, ctx.xer);
	// srw r6,r8,r7
	ctx.r6.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r7.u8 & 0x3F));
	// rlwimi r6,r10,1,0,30
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r10.u32, 1) & 0xFFFFFFFE) | (ctx.r6.u64 & 0xFFFFFFFF00000001);
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// ble cr6,0x8813a090
	if (!ctx.cr6.gt) goto loc_8813A090;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
loc_8813A090:
	// bdnz 0x8813a064
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8813A064;
loc_8813A094:
	// addi r8,r10,3
	ctx.r8.s64 = ctx.r10.s64 + 3;
	// add r10,r8,r11
	ctx.r10.u64 = ctx.r8.u64 + ctx.r11.u64;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x8813a0c8
	if (!ctx.cr6.lt) goto loc_8813A0C8;
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r11.s64;
	// subf r9,r11,r25
	ctx.r9.s64 = ctx.r25.s64 - ctx.r11.s64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8813A0B0:
	// add r10,r11,r26
	ctx.r10.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// stbx r7,r9,r10
	PPC_STORE_U8(ctx.r9.u32 + ctx.r10.u32, ctx.r7.u8);
	// stbu r7,1(r23)
	ea = 1 + ctx.r23.u32;
	PPC_STORE_U8(ea, ctx.r7.u8);
	ctx.r23.u32 = ea;
	// bdnz 0x8813a0b0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8813A0B0;
loc_8813A0C8:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// add r4,r8,r26
	ctx.r4.u64 = ctx.r8.u64 + ctx.r26.u64;
	// bl 0x880707f0
	ctx.lr = 0x8813A0D8;
	sub_880707F0(ctx, base);
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// ble cr6,0x8813a100
	if (!ctx.cr6.gt) goto loc_8813A100;
	// add r11,r25,r26
	ctx.r11.u64 = ctx.r25.u64 + ctx.r26.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// beq cr6,0x8813a100
	if (ctx.cr6.eq) goto loc_8813A100;
	// mtctr r24
	ctx.ctr.u64 = ctx.r24.u64;
loc_8813A0F8:
	// stbu r10,1(r11)
	ea = 1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r10.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x8813a0f8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8813A0F8;
loc_8813A100:
	// cmpw cr6,r30,r19
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r19.s32, ctx.xer);
	// blt cr6,0x88139e9c
	if (ctx.cr6.lt) goto loc_88139E9C;
loc_8813A108:
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x88071180
	__restgprlr_18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8813A114"))) PPC_WEAK_FUNC(sub_8813A114);
PPC_FUNC_IMPL(__imp__sub_8813A114) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8813A118"))) PPC_WEAK_FUNC(sub_8813A118);
PPC_FUNC_IMPL(__imp__sub_8813A118) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lbz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 4);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lbz r8,8(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 8);
	// addi r9,r4,12
	ctx.r9.s64 = ctx.r4.s64 + 12;
	// lbz r7,0(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// rotlwi r6,r10,8
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// lbz r5,5(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 5);
	// rotlwi r3,r8,8
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// lbz r10,9(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 9);
	// rotlwi r8,r7,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r7.u32, 8);
	// lbz r7,1(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// or r6,r6,r5
	ctx.r6.u64 = ctx.r6.u64 | ctx.r5.u64;
	// or r5,r3,r10
	ctx.r5.u64 = ctx.r3.u64 | ctx.r10.u64;
	// lbz r3,6(r4)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r4.u32 + 6);
	// or r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 | ctx.r7.u64;
	// lbz r10,10(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 10);
	// rlwinm r7,r6,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// lbz r6,2(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 2);
	// rlwinm r5,r5,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00;
	// lbz r31,7(r4)
	ctx.r31.u64 = PPC_LOAD_U8(ctx.r4.u32 + 7);
	// or r7,r7,r3
	ctx.r7.u64 = ctx.r7.u64 | ctx.r3.u64;
	// lbz r30,11(r4)
	ctx.r30.u64 = PPC_LOAD_U8(ctx.r4.u32 + 11);
	// or r10,r5,r10
	ctx.r10.u64 = ctx.r5.u64 | ctx.r10.u64;
	// lbz r3,3(r4)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r4.u32 + 3);
	// rlwinm r8,r8,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r7,r7,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// or r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 | ctx.r6.u64;
	// rlwinm r5,r10,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// or r6,r7,r31
	ctx.r6.u64 = ctx.r7.u64 | ctx.r31.u64;
	// rlwinm r8,r8,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// or r10,r5,r30
	ctx.r10.u64 = ctx.r5.u64 | ctx.r30.u64;
	// or r3,r8,r3
	ctx.r3.u64 = ctx.r8.u64 | ctx.r3.u64;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// ble cr6,0x8813a23c
	if (!ctx.cr6.gt) goto loc_8813A23C;
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// lbz r10,-32(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + -32);
	// addi r4,r9,-1
	ctx.r4.s64 = ctx.r9.s64 + -1;
loc_8813A1BC:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x8813a1cc
	if (!ctx.cr6.eq) goto loc_8813A1CC;
	// lbzu r10,1(r4)
	ea = 1 + ctx.r4.u32;
	ctx.r10.u64 = PPC_LOAD_U8(ea);
	ctx.r4.u32 = ea;
	// li r7,8
	ctx.r7.s64 = 8;
loc_8813A1CC:
	// rlwinm r9,r10,0,24,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80;
	// clrlwi r5,r10,24
	ctx.r5.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8813a220
	if (ctx.cr6.eq) goto loc_8813A220;
	// lbz r9,1(r8)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r8.u32 + 1);
	// lbz r10,2(r8)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r8.u32 + 2);
	// rlwimi r10,r9,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// clrlwi r9,r10,27
	ctx.r9.u64 = ctx.r10.u32 & 0x1F;
	// rlwinm r31,r10,27,5,31
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x7FFFFFF;
	// addic. r10,r9,3
	ctx.xer.ca = ctx.r9.u32 > 4294967292;
	ctx.r10.s64 = ctx.r9.s64 + 3;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// subf r9,r31,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r31.s64;
	// beq 0x8813a218
	if (ctx.cr0.eq) goto loc_8813A218;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// addi r10,r9,-1
	ctx.r10.s64 = ctx.r9.s64 + -1;
loc_8813A208:
	// lbzu r9,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r9.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stb r9,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bdnz 0x8813a208
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8813A208;
loc_8813A218:
	// addi r8,r8,2
	ctx.r8.s64 = ctx.r8.s64 + 2;
	// b 0x8813a22c
	goto loc_8813A22C;
loc_8813A220:
	// lbzu r10,1(r8)
	ea = 1 + ctx.r8.u32;
	ctx.r10.u64 = PPC_LOAD_U8(ea);
	ctx.r8.u32 = ea;
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_8813A22C:
	// addic. r6,r6,-1
	ctx.xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// rlwinm r10,r5,1,24,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFE;
	// bgt 0x8813a1bc
	if (ctx.cr0.gt) goto loc_8813A1BC;
loc_8813A23C:
	// ld r30,-16(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813A248"))) PPC_WEAK_FUNC(sub_8813A248);
PPC_FUNC_IMPL(__imp__sub_8813A248) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x8813A250;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r10,1(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lbz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lbz r8,2(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 2);
	// extsb r7,r10
	ctx.r7.s64 = ctx.r10.s8;
	// extsb r6,r9
	ctx.r6.s64 = ctx.r9.s8;
	// lbz r4,3(r4)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r4.u32 + 3);
	// extsb r10,r8
	ctx.r10.s64 = ctx.r8.s8;
	// rlwimi r7,r6,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r6.u32, 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// addi r30,r11,9320
	ctx.r30.s64 = ctx.r11.s64 + 9320;
	// extsb r27,r4
	ctx.r27.s64 = ctx.r4.s8;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// rlwimi r10,r7,8,0,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r7.u32, 8) & 0xFFFFFF00) | (ctx.r10.u64 & 0xFFFFFFFF000000FF);
	// li r5,4096
	ctx.r5.s64 = 4096;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// rlwimi r27,r10,8,0,23
	ctx.r27.u64 = (__builtin_rotateleft32(ctx.r10.u32, 8) & 0xFFFFFF00) | (ctx.r27.u64 & 0xFFFFFFFF000000FF);
	// li r29,4
	ctx.r29.s64 = 4;
	// bl 0x88073bd0
	ctx.lr = 0x8813A2A4;
	sub_88073BD0(ctx, base);
	// li r11,1024
	ctx.r11.s64 = 1024;
	// lis r5,-30597
	ctx.r5.s64 = -2005204992;
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r4,-30597
	ctx.r4.s64 = -2005204992;
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r10,-12792(r5)
	PPC_STORE_U32(ctx.r5.u32 + -12792, ctx.r10.u32);
	// subf r8,r30,r28
	ctx.r8.s64 = ctx.r28.s64 - ctx.r30.s64;
	// li r3,1024
	ctx.r3.s64 = 1024;
loc_8813A2CC:
	// lbzx r7,r29,r31
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r31.u32);
	// addi r6,r11,1
	ctx.r6.s64 = ctx.r11.s64 + 1;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// clrlwi r11,r6,20
	ctx.r11.u64 = ctx.r6.u32 & 0xFFF;
	// stb r7,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r7.u8);
	// clrlwi r7,r7,24
	ctx.r7.u64 = ctx.r7.u32 & 0xFF;
	// stbx r7,r8,r9
	PPC_STORE_U8(ctx.r8.u32 + ctx.r9.u32, ctx.r7.u8);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// bdnz 0x8813a2cc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8813A2CC;
	// stw r11,-12788(r4)
	PPC_STORE_U32(ctx.r4.u32 + -12788, ctx.r11.u32);
	// cmplwi cr6,r27,1024
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 1024, ctx.xer);
	// beq cr6,0x8813a3b4
	if (ctx.cr6.eq) goto loc_8813A3B4;
	// add r9,r29,r31
	ctx.r9.u64 = ctx.r29.u64 + ctx.r31.u64;
	// addi r8,r9,-1
	ctx.r8.s64 = ctx.r9.s64 + -1;
loc_8813A304:
	// lbz r9,1(r8)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r8.u32 + 1);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// rlwinm r7,r9,0,0,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x8813a340
	if (!ctx.cr6.eq) goto loc_8813A340;
	// lbz r9,1(r8)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r8.u32 + 1);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// addi r6,r11,1
	ctx.r6.s64 = ctx.r11.s64 + 1;
	// clrlwi r10,r7,20
	ctx.r10.u64 = ctx.r7.u32 & 0xFFF;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stbx r9,r11,r30
	PPC_STORE_U8(ctx.r11.u32 + ctx.r30.u32, ctx.r9.u8);
	// clrlwi r11,r6,20
	ctx.r11.u64 = ctx.r6.u32 & 0xFFF;
	// stbx r9,r3,r28
	PPC_STORE_U8(ctx.r3.u32 + ctx.r28.u32, ctx.r9.u8);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// b 0x8813a3a4
	goto loc_8813A3A4;
loc_8813A340:
	// lbzu r7,1(r8)
	ea = 1 + ctx.r8.u32;
	ctx.r7.u64 = PPC_LOAD_U8(ea);
	ctx.r8.u32 = ea;
	// extsb r6,r9
	ctx.r6.s64 = ctx.r9.s8;
	// li r9,0
	ctx.r9.s64 = 0;
	// rlwimi r7,r6,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r6.u32, 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// clrlwi r7,r7,17
	ctx.r7.u64 = ctx.r7.u32 & 0x7FFF;
	// extsh r31,r7
	ctx.r31.s64 = ctx.r7.s16;
	// clrlwi r6,r7,27
	ctx.r6.u64 = ctx.r7.u32 & 0x1F;
	// srawi r7,r31,5
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0x1F) != 0);
	ctx.r7.s64 = ctx.r31.s32 >> 5;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// add r7,r7,r10
	ctx.r7.u64 = ctx.r7.u64 + ctx.r10.u64;
	// blt cr6,0x8813a3ac
	if (ctx.cr6.lt) goto loc_8813A3AC;
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
loc_8813A374:
	// add r6,r7,r9
	ctx.r6.u64 = ctx.r7.u64 + ctx.r9.u64;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// clrlwi r6,r6,20
	ctx.r6.u64 = ctx.r6.u32 & 0xFFF;
	// addi r31,r11,1
	ctx.r31.s64 = ctx.r11.s64 + 1;
	// clrlwi r10,r10,20
	ctx.r10.u64 = ctx.r10.u32 & 0xFFF;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// lbzx r6,r6,r30
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r30.u32);
	// stbx r6,r11,r30
	PPC_STORE_U8(ctx.r11.u32 + ctx.r30.u32, ctx.r6.u8);
	// clrlwi r11,r31,20
	ctx.r11.u64 = ctx.r31.u32 & 0xFFF;
	// stbx r6,r3,r28
	PPC_STORE_U8(ctx.r3.u32 + ctx.r28.u32, ctx.r6.u8);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// bdnz 0x8813a374
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8813A374;
loc_8813A3A4:
	// stw r11,-12788(r4)
	PPC_STORE_U32(ctx.r4.u32 + -12788, ctx.r11.u32);
	// stw r10,-12792(r5)
	PPC_STORE_U32(ctx.r5.u32 + -12792, ctx.r10.u32);
loc_8813A3AC:
	// cmplw cr6,r3,r27
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r27.u32, ctx.xer);
	// bne cr6,0x8813a304
	if (!ctx.cr6.eq) goto loc_8813A304;
loc_8813A3B4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8813A3BC"))) PPC_WEAK_FUNC(sub_8813A3BC);
PPC_FUNC_IMPL(__imp__sub_8813A3BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8813A3C0"))) PPC_WEAK_FUNC(sub_8813A3C0);
PPC_FUNC_IMPL(__imp__sub_8813A3C0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x8813A3C8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30647
	ctx.r11.s64 = -2008481792;
	// mulli r10,r3,7204
	ctx.r10.s64 = ctx.r3.s64 * 7204;
	// addi r11,r11,18424
	ctx.r11.s64 = ctx.r11.s64 + 18424;
	// li r28,0
	ctx.r28.s64 = 0;
	// add r29,r10,r11
	ctx.r29.u64 = ctx.r10.u64 + ctx.r11.u64;
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
	// lwz r10,7200(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 7200);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x8813a41c
	if (!ctx.cr6.gt) goto loc_8813A41C;
	// addi r31,r29,-12
	ctx.r31.s64 = ctx.r29.s64 + -12;
loc_8813A3F4:
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813a404
	if (ctx.cr6.eq) goto loc_8813A404;
	// bl 0x88090b48
	ctx.lr = 0x8813A404;
	sub_88090B48(ctx, base);
loc_8813A404:
	// stw r28,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r28.u32);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// stwu r28,12(r31)
	ea = 12 + ctx.r31.u32;
	PPC_STORE_U32(ea, ctx.r28.u32);
	ctx.r31.u32 = ea;
	// lwz r11,7200(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 7200);
	// cmpw cr6,r30,r11
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8813a3f4
	if (ctx.cr6.lt) goto loc_8813A3F4;
loc_8813A41C:
	// stw r28,7200(r29)
	PPC_STORE_U32(ctx.r29.u32 + 7200, ctx.r28.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8813A428"))) PPC_WEAK_FUNC(sub_8813A428);
PPC_FUNC_IMPL(__imp__sub_8813A428) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,8424
	ctx.r11.s64 = ctx.r11.s64 + 8424;
loc_8813A434:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmpw cr6,r9,r3
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r3.s32, ctx.xer);
	// beq cr6,0x8813a458
	if (ctx.cr6.eq) goto loc_8813A458;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,56
	ctx.r11.s64 = ctx.r11.s64 + 56;
	// cmpwi cr6,r10,16
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 16, ctx.xer);
	// blt cr6,0x8813a434
	if (ctx.cr6.lt) goto loc_8813A434;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8813A458:
	// lwz r3,32(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813A460"))) PPC_WEAK_FUNC(sub_8813A460);
PPC_FUNC_IMPL(__imp__sub_8813A460) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30679
	ctx.r11.s64 = -2010578944;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,3280
	ctx.r9.s64 = ctx.r11.s64 + 3280;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwzx r11,r10,r9
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// addi r31,r11,2
	ctx.r31.s64 = ctx.r11.s64 + 2;
	// lhz r8,2(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 2);
	// extsh r3,r8
	ctx.r3.s64 = ctx.r8.s16;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8813a4b4
	if (ctx.cr6.lt) goto loc_8813A4B4;
loc_8813A49C:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x88092310
	ctx.lr = 0x8813A4A4;
	sub_88092310(ctx, base);
	// lhzu r11,12(r31)
	ea = 12 + ctx.r31.u32;
	ctx.r11.u64 = PPC_LOAD_U16(ea);
	ctx.r31.u32 = ea;
	// extsh r3,r11
	ctx.r3.s64 = ctx.r11.s16;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge cr6,0x8813a49c
	if (!ctx.cr6.lt) goto loc_8813A49C;
loc_8813A4B4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813A4CC"))) PPC_WEAK_FUNC(sub_8813A4CC);
PPC_FUNC_IMPL(__imp__sub_8813A4CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8813A4D0"))) PPC_WEAK_FUNC(sub_8813A4D0);
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

__attribute__((alias("__imp__sub_8813A5A8"))) PPC_WEAK_FUNC(sub_8813A5A8);
PPC_FUNC_IMPL(__imp__sub_8813A5A8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,8424
	ctx.r11.s64 = ctx.r11.s64 + 8424;
loc_8813A5B4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8813a5cc
	if (ctx.cr6.eq) goto loc_8813A5CC;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmpw cr6,r9,r3
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r3.s32, ctx.xer);
	// beq cr6,0x8813a5e4
	if (ctx.cr6.eq) goto loc_8813A5E4;
loc_8813A5CC:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,56
	ctx.r11.s64 = ctx.r11.s64 + 56;
	// cmpwi cr6,r10,16
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 16, ctx.xer);
	// blt cr6,0x8813a5b4
	if (ctx.cr6.lt) goto loc_8813A5B4;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8813A5E4:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813A5EC"))) PPC_WEAK_FUNC(sub_8813A5EC);
PPC_FUNC_IMPL(__imp__sub_8813A5EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8813A5F0"))) PPC_WEAK_FUNC(sub_8813A5F0);
PPC_FUNC_IMPL(__imp__sub_8813A5F0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// li r5,896
	ctx.r5.s64 = 896;
	// addi r3,r11,8424
	ctx.r3.s64 = ctx.r11.s64 + 8424;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x88073bd0
	ctx.lr = 0x8813A614;
	sub_88073BD0(ctx, base);
	// lis r10,-30647
	ctx.r10.s64 = -2008481792;
	// lis r5,3
	ctx.r5.s64 = 196608;
	// addi r3,r10,18424
	ctx.r3.s64 = ctx.r10.s64 + 18424;
	// ori r5,r5,55532
	ctx.r5.u64 = ctx.r5.u64 | 55532;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x88073bd0
	ctx.lr = 0x8813A62C;
	sub_88073BD0(ctx, base);
	// lis r7,-30647
	ctx.r7.s64 = -2008481792;
	// lis r6,-30597
	ctx.r6.s64 = -2005204992;
	// addi r5,r7,18412
	ctx.r5.s64 = ctx.r7.s64 + 18412;
	// li r11,16
	ctx.r11.s64 = 16;
	// addi r4,r6,-12796
	ctx.r4.s64 = ctx.r6.s64 + -12796;
	// li r10,7
	ctx.r10.s64 = 7;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,-4(r5)
	PPC_STORE_U32(ctx.r5.u32 + -4, ctx.r11.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r10,18412(r7)
	PPC_STORE_U32(ctx.r7.u32 + 18412, ctx.r10.u32);
	// stw r9,-8(r4)
	PPC_STORE_U32(ctx.r4.u32 + -8, ctx.r9.u32);
	// li r31,2
	ctx.r31.s64 = 2;
	// stw r8,-4(r4)
	PPC_STORE_U32(ctx.r4.u32 + -4, ctx.r8.u32);
	// stw r11,-12796(r6)
	PPC_STORE_U32(ctx.r6.u32 + -12796, ctx.r11.u32);
loc_8813A668:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8813a3c0
	ctx.lr = 0x8813A670;
	sub_8813A3C0(ctx, base);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmpwi cr6,r31,35
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 35, ctx.xer);
	// blt cr6,0x8813a668
	if (ctx.cr6.lt) goto loc_8813A668;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813A690"))) PPC_WEAK_FUNC(sub_8813A690);
PPC_FUNC_IMPL(__imp__sub_8813A690) {
	PPC_FUNC_PROLOGUE();
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813A69C"))) PPC_WEAK_FUNC(sub_8813A69C);
PPC_FUNC_IMPL(__imp__sub_8813A69C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8813A6A0"))) PPC_WEAK_FUNC(sub_8813A6A0);
PPC_FUNC_IMPL(__imp__sub_8813A6A0) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// li r9,2
	ctx.r9.s64 = 2;
	// addi r10,r10,-11864
	ctx.r10.s64 = ctx.r10.s64 + -11864;
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// lwz r9,-12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x8813a6dc
	if (!ctx.cr6.lt) goto loc_8813A6DC;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lbz r11,2(r10)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 2);
	// b 0x8813a6e0
	goto loc_8813A6E0;
loc_8813A6DC:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8813A6E0:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813A6F8"))) PPC_WEAK_FUNC(sub_8813A6F8);
PPC_FUNC_IMPL(__imp__sub_8813A6F8) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,7
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 7, ctx.xer);
	// blt cr6,0x8813a704
	if (ctx.cr6.lt) goto loc_8813A704;
	// li r3,7
	ctx.r3.s64 = 7;
loc_8813A704:
	// lis r11,-30679
	ctx.r11.s64 = -2010578944;
	// rlwinm r10,r3,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r11,r11,-13104
	ctx.r11.s64 = ctx.r11.s64 + -13104;
	// lis r9,-30647
	ctx.r9.s64 = -2008481792;
	// addi r8,r11,4
	ctx.r8.s64 = ctx.r11.s64 + 4;
	// addi r7,r9,18412
	ctx.r7.s64 = ctx.r9.s64 + 18412;
	// lwzx r11,r10,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// lwzx r10,r10,r8
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// stw r11,-4(r7)
	PPC_STORE_U32(ctx.r7.u32 + -4, ctx.r11.u32);
	// stw r10,18412(r9)
	PPC_STORE_U32(ctx.r9.u32 + 18412, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813A730"))) PPC_WEAK_FUNC(sub_8813A730);
PPC_FUNC_IMPL(__imp__sub_8813A730) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813A734"))) PPC_WEAK_FUNC(sub_8813A734);
PPC_FUNC_IMPL(__imp__sub_8813A734) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8813A738"))) PPC_WEAK_FUNC(sub_8813A738);
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

__attribute__((alias("__imp__sub_8813AEC4"))) PPC_WEAK_FUNC(sub_8813AEC4);
PPC_FUNC_IMPL(__imp__sub_8813AEC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8813AEC8"))) PPC_WEAK_FUNC(sub_8813AEC8);
PPC_FUNC_IMPL(__imp__sub_8813AEC8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x8813AED0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x88092460
	ctx.lr = 0x8813AED8;
	sub_88092460(ctx, base);
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// li r29,16
	ctx.r29.s64 = 16;
	// addi r28,r11,8424
	ctx.r28.s64 = ctx.r11.s64 + 8424;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r31,r28,52
	ctx.r31.s64 = ctx.r28.s64 + 52;
loc_8813AEEC:
	// lwz r11,-4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8813af0c
	if (ctx.cr6.eq) goto loc_8813AF0C;
	// addic. r11,r31,-4
	ctx.xer.ca = ctx.r31.u32 > 3;
	ctx.r11.s64 = ctx.r31.s64 + -4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8813af0c
	if (ctx.cr0.eq) goto loc_8813AF0C;
	// lwz r3,-4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -4);
	// bl 0x8808cf58
	ctx.lr = 0x8813AF08;
	sub_8808CF58(ctx, base);
	// stw r30,-4(r31)
	PPC_STORE_U32(ctx.r31.u32 + -4, ctx.r30.u32);
loc_8813AF0C:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8813af2c
	if (ctx.cr6.eq) goto loc_8813AF2C;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8813af2c
	if (ctx.cr6.eq) goto loc_8813AF2C;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x8808cf58
	ctx.lr = 0x8813AF28;
	sub_8808CF58(ctx, base);
	// stw r30,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
loc_8813AF2C:
	// stw r30,-52(r31)
	PPC_STORE_U32(ctx.r31.u32 + -52, ctx.r30.u32);
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r31,r31,56
	ctx.r31.s64 = ctx.r31.s64 + 56;
	// bne 0x8813aeec
	if (!ctx.cr0.eq) goto loc_8813AEEC;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r5,896
	ctx.r5.s64 = 896;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x88073bd0
	ctx.lr = 0x8813AF4C;
	sub_88073BD0(ctx, base);
	// lis r8,-30597
	ctx.r8.s64 = -2005204992;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// addi r7,r8,-12796
	ctx.r7.s64 = ctx.r8.s64 + -12796;
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// stw r30,-12796(r8)
	PPC_STORE_U32(ctx.r8.u32 + -12796, ctx.r30.u32);
	// stw r30,-8(r7)
	PPC_STORE_U32(ctx.r7.u32 + -8, ctx.r30.u32);
	// stw r30,-4(r7)
	PPC_STORE_U32(ctx.r7.u32 + -4, ctx.r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8813AF74"))) PPC_WEAK_FUNC(sub_8813AF74);
PPC_FUNC_IMPL(__imp__sub_8813AF74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8813AF78"))) PPC_WEAK_FUNC(sub_8813AF78);
PPC_FUNC_IMPL(__imp__sub_8813AF78) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x8813aec8
	ctx.lr = 0x8813AF8C;
	sub_8813AEC8(ctx, base);
	// li r31,2
	ctx.r31.s64 = 2;
loc_8813AF90:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8813a3c0
	ctx.lr = 0x8813AF98;
	sub_8813A3C0(ctx, base);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmpwi cr6,r31,35
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 35, ctx.xer);
	// blt cr6,0x8813af90
	if (ctx.cr6.lt) goto loc_8813AF90;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813AFB8"))) PPC_WEAK_FUNC(sub_8813AFB8);
PPC_FUNC_IMPL(__imp__sub_8813AFB8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813AFBC"))) PPC_WEAK_FUNC(sub_8813AFBC);
PPC_FUNC_IMPL(__imp__sub_8813AFBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8813AFC0"))) PPC_WEAK_FUNC(sub_8813AFC0);
PPC_FUNC_IMPL(__imp__sub_8813AFC0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813AFC4"))) PPC_WEAK_FUNC(sub_8813AFC4);
PPC_FUNC_IMPL(__imp__sub_8813AFC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8813AFC8"))) PPC_WEAK_FUNC(sub_8813AFC8);
PPC_FUNC_IMPL(__imp__sub_8813AFC8) {
	PPC_FUNC_PROLOGUE();
	// lwz r9,128(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r8,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r8.u8);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// addi r11,r11,576
	ctx.r11.s64 = ctx.r11.s64 + 576;
	// lwz r10,-104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -104);
	// cmpwi cr6,r10,3000
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3000, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r8.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,-104(r11)
	PPC_STORE_U32(ctx.r11.u32 + -104, ctx.r10.u32);
	// stwx r9,r7,r11
	PPC_STORE_U32(ctx.r7.u32 + ctx.r11.u32, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813B008"))) PPC_WEAK_FUNC(sub_8813B008);
PPC_FUNC_IMPL(__imp__sub_8813B008) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30647
	ctx.r11.s64 = -2008481792;
	// li r5,18464
	ctx.r5.s64 = 18464;
	// addi r31,r11,-5576
	ctx.r31.s64 = ctx.r11.s64 + -5576;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x8813B030;
	sub_88073BD0(ctx, base);
	// lis r7,-30671
	ctx.r7.s64 = -2010054656;
	// lis r10,-21846
	ctx.r10.s64 = -1431699456;
	// lis r11,16838
	ctx.r11.s64 = 1103495168;
	// ori r6,r10,43691
	ctx.r6.u64 = ctx.r10.u64 | 43691;
	// addi r4,r31,9204
	ctx.r4.s64 = ctx.r31.s64 + 9204;
	// lwz r10,4200(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4200);
	// ori r5,r11,20077
	ctx.r5.u64 = ctx.r11.u64 | 20077;
loc_8813B04C:
	// li r11,4
	ctx.r11.s64 = 4;
	// addi r9,r4,-4
	ctx.r9.s64 = ctx.r4.s64 + -4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8813B058:
	// mullw r11,r10,r5
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r5.s32);
	// addi r10,r11,12345
	ctx.r10.s64 = ctx.r11.s64 + 12345;
	// stw r10,4200(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4200, ctx.r10.u32);
	// lhz r3,4200(r7)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r7.u32 + 4200);
	// mulhwu r11,r3,r6
	ctx.r11.u64 = (uint64_t(ctx.r3.u32) * uint64_t(ctx.r6.u32)) >> 32;
	// rlwinm r11,r11,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// subf r3,r8,r3
	ctx.r3.s64 = ctx.r3.s64 - ctx.r8.s64;
	// extsh r8,r3
	ctx.r8.s64 = ctx.r3.s16;
	// stwu r8,4(r9)
	ea = 4 + ctx.r9.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x8813b058
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8813B058;
	// addi r4,r4,9232
	ctx.r4.s64 = ctx.r4.s64 + 9232;
	// addi r11,r31,27668
	ctx.r11.s64 = ctx.r31.s64 + 27668;
	// cmpw cr6,r4,r11
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8813b04c
	if (ctx.cr6.lt) goto loc_8813B04C;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813B0AC"))) PPC_WEAK_FUNC(sub_8813B0AC);
PPC_FUNC_IMPL(__imp__sub_8813B0AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8813B0B0"))) PPC_WEAK_FUNC(sub_8813B0B0);
PPC_FUNC_IMPL(__imp__sub_8813B0B0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x8813B0B8;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30647
	ctx.r11.s64 = -2008481792;
	// li r26,2
	ctx.r26.s64 = 2;
	// addi r30,r11,-5576
	ctx.r30.s64 = ctx.r11.s64 + -5576;
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r29,r11,576
	ctx.r29.s64 = ctx.r11.s64 + 576;
loc_8813B0D4:
	// lwz r11,9228(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 9228);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8813b168
	if (ctx.cr6.eq) goto loc_8813B168;
	// addi r31,r30,16
	ctx.r31.s64 = ctx.r30.s64 + 16;
	// li r27,56
	ctx.r27.s64 = 56;
loc_8813B0E8:
	// lbz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8813b15c
	if (ctx.cr6.eq) goto loc_8813B15C;
	// lwz r11,140(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8813B104;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8813b15c
	if (!ctx.cr6.eq) goto loc_8813B15C;
	// lwz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// stb r28,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r28.u8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8813b13c
	if (ctx.cr6.eq) goto loc_8813B13C;
	// lwz r11,-104(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -104);
	// cmpwi cr6,r11,3000
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3000, ctx.xer);
	// bge cr6,0x8813b13c
	if (!ctx.cr6.lt) goto loc_8813B13C;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r28,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r28.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-104(r29)
	PPC_STORE_U32(ctx.r29.u32 + -104, ctx.r11.u32);
	// stwx r10,r9,r29
	PPC_STORE_U32(ctx.r9.u32 + ctx.r29.u32, ctx.r10.u32);
loc_8813B13C:
	// lbz r11,3(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 3);
	// rotlwi r11,r11,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// lwzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r30.u32);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stwx r10,r11,r30
	PPC_STORE_U32(ctx.r11.u32 + ctx.r30.u32, ctx.r10.u32);
	// lwz r11,9228(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 9228);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// stw r9,9228(r30)
	PPC_STORE_U32(ctx.r30.u32 + 9228, ctx.r9.u32);
loc_8813B15C:
	// addi r31,r31,164
	ctx.r31.s64 = ctx.r31.s64 + 164;
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// bne 0x8813b0e8
	if (!ctx.cr0.eq) goto loc_8813B0E8;
loc_8813B168:
	// addi r30,r30,9232
	ctx.r30.s64 = ctx.r30.s64 + 9232;
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne 0x8813b0d4
	if (!ctx.cr0.eq) goto loc_8813B0D4;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8813B17C"))) PPC_WEAK_FUNC(sub_8813B17C);
PPC_FUNC_IMPL(__imp__sub_8813B17C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8813B180"))) PPC_WEAK_FUNC(sub_8813B180);
PPC_FUNC_IMPL(__imp__sub_8813B180) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x8813B188;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,76(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r27,0
	ctx.r27.s64 = 0;
	// cmpwi cr6,r11,256
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 256, ctx.xer);
	// blt cr6,0x8813b1a8
	if (ctx.cr6.lt) goto loc_8813B1A8;
	// subfic r11,r11,512
	ctx.xer.ca = ctx.r11.u32 <= 512;
	ctx.r11.s64 = 512 - ctx.r11.s64;
	// li r27,1
	ctx.r27.s64 = 1;
loc_8813B1A8:
	// srawi r11,r11,3
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 3;
	// lhz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 56);
	// lwz r29,32(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r6,151
	ctx.r6.s64 = 151;
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// lwz r28,36(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x8813B1D8;
	sub_881538C0(ctx, base);
	// lis r30,-30597
	ctx.r30.s64 = -2005204992;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813b218
	if (ctx.cr6.eq) goto loc_8813B218;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r27,26,0,5
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 26) & 0xFC000000;
	// lwz r11,-11932(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -11932);
	// lis r8,128
	ctx.r8.s64 = 8388608;
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// ori r6,r8,32896
	ctx.r6.u64 = ctx.r8.u64 | 32896;
	// oris r5,r7,531
	ctx.r5.u64 = ctx.r7.u64 | 34799616;
	// addi r27,r11,1
	ctx.r27.s64 = ctx.r11.s64 + 1;
	// stw r6,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r6.u32);
	// ori r5,r5,32768
	ctx.r5.u64 = ctx.r5.u64 | 32768;
	// stw r27,-11932(r30)
	PPC_STORE_U32(ctx.r30.u32 + -11932, ctx.r27.u32);
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// b 0x8813b21c
	goto loc_8813B21C;
loc_8813B218:
	// lwz r27,-11932(r30)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r30.u32 + -11932);
loc_8813B21C:
	// lbz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 4);
	// li r6,151
	ctx.r6.s64 = 151;
	// addis r5,r28,-2
	ctx.r5.s64 = ctx.r28.s64 + -131072;
	// rotlwi r11,r11,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r11,397
	ctx.r3.s64 = ctx.r11.s64 + 397;
	// bl 0x881538c0
	ctx.lr = 0x8813B238;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813b264
	if (ctx.cr6.eq) goto loc_8813B264;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,16
	ctx.r9.s64 = 1048576;
	// addi r11,r27,1
	ctx.r11.s64 = ctx.r27.s64 + 1;
	// oris r7,r10,545
	ctx.r7.u64 = ctx.r10.u64 | 35717120;
	// ori r8,r9,24704
	ctx.r8.u64 = ctx.r9.u64 | 24704;
	// stw r11,-11932(r30)
	PPC_STORE_U32(ctx.r30.u32 + -11932, ctx.r11.u32);
	// ori r7,r7,32768
	ctx.r7.u64 = ctx.r7.u64 | 32768;
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
loc_8813B264:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8813B26C"))) PPC_WEAK_FUNC(sub_8813B26C);
PPC_FUNC_IMPL(__imp__sub_8813B26C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8813B270"))) PPC_WEAK_FUNC(sub_8813B270);
PPC_FUNC_IMPL(__imp__sub_8813B270) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x8813B278;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,2(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813b4f4
	if (!ctx.cr6.eq) goto loc_8813B4F4;
	// lwz r9,128(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// lwz r9,28(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8813b2bc
	if (ctx.cr6.eq) goto loc_8813B2BC;
loc_8813B2A4:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8813b2bc
	if (ctx.cr6.eq) goto loc_8813B2BC;
	// lwz r9,0(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8813b2a4
	if (!ctx.cr6.eq) goto loc_8813B2A4;
loc_8813B2BC:
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// lis r27,-30671
	ctx.r27.s64 = -2010054656;
	// lis r11,16838
	ctx.r11.s64 = 1103495168;
	// lis r9,-13108
	ctx.r9.s64 = -859045888;
	// ori r30,r11,20077
	ctx.r30.u64 = ctx.r11.u64 | 20077;
	// ori r7,r9,52429
	ctx.r7.u64 = ctx.r9.u64 | 52429;
	// lwz r11,4200(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4200);
	// lis r6,14563
	ctx.r6.s64 = 954400768;
	// li r5,1
	ctx.r5.s64 = 1;
	// mullw r11,r11,r30
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// stb r5,2(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2, ctx.r5.u8);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// ori r29,r6,36409
	ctx.r29.u64 = ctx.r6.u64 | 36409;
	// stw r11,4200(r27)
	PPC_STORE_U32(ctx.r27.u32 + 4200, ctx.r11.u32);
	// mullw r11,r11,r30
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// lwz r4,68(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// lwz r5,76(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// lwz r6,12(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// srawi r3,r4,2
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x3) != 0);
	ctx.r3.s64 = ctx.r4.s32 >> 2;
	// lhz r4,4200(r27)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r27.u32 + 4200);
	// stw r11,4200(r27)
	PPC_STORE_U32(ctx.r27.u32 + 4200, ctx.r11.u32);
	// mullw r8,r11,r30
	ctx.r8.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// lhz r26,4200(r27)
	ctx.r26.u64 = PPC_LOAD_U16(ctx.r27.u32 + 4200);
	// addze r11,r3
	temp.s64 = ctx.r3.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r11.s64 = temp.s64;
	// mulhwu r3,r4,r7
	ctx.r3.u64 = (uint64_t(ctx.r4.u32) * uint64_t(ctx.r7.u32)) >> 32;
	// rlwinm r9,r3,29,3,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 29) & 0x1FFFFFFF;
	// stw r11,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// addi r28,r8,12345
	ctx.r28.s64 = ctx.r8.s64 + 12345;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// mulhwu r8,r26,r29
	ctx.r8.u64 = (uint64_t(ctx.r26.u32) * uint64_t(ctx.r29.u32)) >> 32;
	// stw r28,4200(r27)
	PPC_STORE_U32(ctx.r27.u32 + 4200, ctx.r28.u32);
	// lhz r25,4200(r27)
	ctx.r25.u64 = PPC_LOAD_U16(ctx.r27.u32 + 4200);
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// lis r3,-30714
	ctx.r3.s64 = -2012872704;
	// rlwinm r7,r9,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r9,r8,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// subf r4,r7,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r7.s64;
	// rlwinm r7,r9,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// extsh r8,r4
	ctx.r8.s64 = ctx.r4.s16;
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r8,r8,-4
	ctx.r8.s64 = ctx.r8.s64 + -4;
	// subf r26,r9,r26
	ctx.r26.s64 = ctx.r26.s64 - ctx.r9.s64;
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// mulhwu r4,r25,r29
	ctx.r4.u64 = (uint64_t(ctx.r25.u32) * uint64_t(ctx.r29.u32)) >> 32;
	// add r9,r8,r5
	ctx.r9.u64 = ctx.r8.u64 + ctx.r5.u64;
	// rlwinm r8,r4,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 31) & 0x7FFFFFFF;
	// clrlwi r9,r9,23
	ctx.r9.u64 = ctx.r9.u32 & 0x1FF;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// addi r26,r9,128
	ctx.r26.s64 = ctx.r9.s64 + 128;
	// rlwinm r24,r9,2,0,29
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r8,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r3,r3,9552
	ctx.r3.s64 = ctx.r3.s64 + 9552;
	// rlwinm r26,r26,2,21,29
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 2) & 0x7FC;
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// extsh r9,r4
	ctx.r9.s64 = ctx.r4.s16;
	// subf r4,r8,r25
	ctx.r4.s64 = ctx.r25.s64 - ctx.r8.s64;
	// lwzx r8,r24,r3
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r24.u32 + ctx.r3.u32);
	// addi r9,r9,-4
	ctx.r9.s64 = ctx.r9.s64 + -4;
	// lwzx r3,r26,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r26.u32 + ctx.r3.u32);
	// lis r26,-30667
	ctx.r26.s64 = -2009792512;
	// stb r10,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r10.u8);
	// mullw r8,r8,r11
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r11.s32);
	// stb r10,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r10.u8);
	// stb r10,113(r31)
	PPC_STORE_U8(ctx.r31.u32 + 113, ctx.r10.u8);
	// stw r8,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r8.u32);
	// rlwinm r10,r9,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// mullw r3,r3,r11
	ctx.r3.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r11.s32);
	// stw r3,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r3.u32);
	// add r11,r10,r7
	ctx.r11.u64 = ctx.r10.u64 + ctx.r7.u64;
	// li r10,3
	ctx.r10.s64 = 3;
	// rlwinm r9,r4,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// stw r11,12364(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12364, ctx.r11.u32);
	// lis r25,-30667
	ctx.r25.s64 = -2009792512;
	// stb r10,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r10.u8);
	// add r10,r9,r6
	ctx.r10.u64 = ctx.r9.u64 + ctx.r6.u64;
	// li r6,64
	ctx.r6.s64 = 64;
	// li r4,153
	ctx.r4.s64 = 153;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r10.u32);
	// bl 0x880f83f8
	ctx.lr = 0x8813B404;
	sub_880F83F8(ctx, base);
	// mullw r11,r28,r30
	ctx.r11.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r30.s32);
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// lis r7,-30667
	ctx.r7.s64 = -2009792512;
	// mullw r10,r11,r30
	ctx.r10.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// stw r11,4200(r27)
	PPC_STORE_U32(ctx.r27.u32 + 4200, ctx.r11.u32);
	// lhz r6,4200(r27)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r27.u32 + 4200);
	// lwz r5,76(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// addi r11,r10,12345
	ctx.r11.s64 = ctx.r10.s64 + 12345;
	// mulhwu r4,r6,r29
	ctx.r4.u64 = (uint64_t(ctx.r6.u32) * uint64_t(ctx.r29.u32)) >> 32;
	// stw r11,4200(r27)
	PPC_STORE_U32(ctx.r27.u32 + 4200, ctx.r11.u32);
	// rlwinm r11,r4,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 31) & 0x7FFFFFFF;
	// lhz r3,4200(r27)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r27.u32 + 4200);
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r5,12368(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12368, ctx.r5.u32);
	// mulhwu r7,r3,r29
	ctx.r7.u64 = (uint64_t(ctx.r3.u32) * uint64_t(ctx.r29.u32)) >> 32;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r7,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// subf r7,r4,r6
	ctx.r7.s64 = ctx.r6.s64 - ctx.r4.s64;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// li r6,64
	ctx.r6.s64 = 64;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// extsh r11,r7
	ctx.r11.s64 = ctx.r7.s16;
	// subf r3,r4,r3
	ctx.r3.s64 = ctx.r3.s64 - ctx.r4.s64;
	// addi r10,r11,-4
	ctx.r10.s64 = ctx.r11.s64 + -4;
	// rlwinm r11,r3,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// stw r11,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r11.u32);
	// lis r3,-30667
	ctx.r3.s64 = -2009792512;
	// stw r10,12364(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12364, ctx.r10.u32);
	// lis r8,-30667
	ctx.r8.s64 = -2009792512;
	// lis r7,-30667
	ctx.r7.s64 = -2009792512;
	// li r9,64
	ctx.r9.s64 = 64;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,153
	ctx.r10.s64 = 153;
	// stw r9,12384(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12384, ctx.r9.u32);
	// li r4,153
	ctx.r4.s64 = 153;
	// stw r11,12380(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12380, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,12376(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12376, ctx.r10.u32);
	// bl 0x880f83f8
	ctx.lr = 0x8813B4B4;
	sub_880F83F8(ctx, base);
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// addi r11,r11,-19568
	ctx.r11.s64 = ctx.r11.s64 + -19568;
	// lwz r10,-4596(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -4596);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8813b4f4
	if (!ctx.cr6.eq) goto loc_8813B4F4;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8813b4f4
	if (!ctx.cr6.eq) goto loc_8813B4F4;
	// lbz r9,1(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// li r10,3
	ctx.r10.s64 = 3;
	// li r6,17
	ctx.r6.s64 = 17;
	// li r5,25
	ctx.r5.s64 = 25;
	// stw r10,-4596(r11)
	PPC_STORE_U32(ctx.r11.u32 + -4596, ctx.r10.u32);
	// li r4,71
	ctx.r4.s64 = 71;
	// addi r3,r9,3
	ctx.r3.s64 = ctx.r9.s64 + 3;
	// bl 0x880e3240
	ctx.lr = 0x8813B4F4;
	sub_880E3240(ctx, base);
loc_8813B4F4:
	// lis r9,-30671
	ctx.r9.s64 = -2010054656;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// li r6,152
	ctx.r6.s64 = 152;
	// addi r7,r9,-24476
	ctx.r7.s64 = ctx.r9.s64 + -24476;
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// add r29,r11,r10
	ctx.r29.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r5,120(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// add r30,r9,r8
	ctx.r30.u64 = ctx.r9.u64 + ctx.r8.u64;
	// stw r29,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r29.u32);
	// rlwinm r3,r5,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// lbz r11,110(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 110);
	// stw r30,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lhzx r11,r3,r7
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + ctx.r7.u32);
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x8813B544;
	sub_881538C0(ctx, base);
	// lis r28,-30597
	ctx.r28.s64 = -2005204992;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813b57c
	if (ctx.cr6.eq) goto loc_8813B57C;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,128
	ctx.r9.s64 = 8388608;
	// lwz r11,-11932(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -11932);
	// oris r7,r10,531
	ctx.r7.u64 = ctx.r10.u64 | 34799616;
	// ori r8,r9,32896
	ctx.r8.u64 = ctx.r9.u64 | 32896;
	// ori r7,r7,32768
	ctx.r7.u64 = ctx.r7.u64 | 32768;
	// addi r27,r11,1
	ctx.r27.s64 = ctx.r11.s64 + 1;
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r27,-11932(r28)
	PPC_STORE_U32(ctx.r28.u32 + -11932, ctx.r27.u32);
	// b 0x8813b580
	goto loc_8813B580;
loc_8813B57C:
	// lwz r27,-11932(r28)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r28.u32 + -11932);
loc_8813B580:
	// lwz r11,120(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// li r6,152
	ctx.r6.s64 = 152;
	// addis r5,r29,-6
	ctx.r5.s64 = ctx.r29.s64 + -393216;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r11,401
	ctx.r3.s64 = ctx.r11.s64 + 401;
	// bl 0x881538c0
	ctx.lr = 0x8813B59C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813b5c8
	if (ctx.cr6.eq) goto loc_8813B5C8;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,32
	ctx.r9.s64 = 2097152;
	// addi r11,r27,1
	ctx.r11.s64 = ctx.r27.s64 + 1;
	// oris r7,r10,545
	ctx.r7.u64 = ctx.r10.u64 | 35717120;
	// ori r8,r9,16512
	ctx.r8.u64 = ctx.r9.u64 | 16512;
	// stw r11,-11932(r28)
	PPC_STORE_U32(ctx.r28.u32 + -11932, ctx.r11.u32);
	// ori r7,r7,32768
	ctx.r7.u64 = ctx.r7.u64 | 32768;
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
loc_8813B5C8:
	// lbz r11,112(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 112);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r9.u8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge cr6,0x8813b604
	if (!ctx.cr6.lt) goto loc_8813B604;
	// lbz r11,110(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 110);
	// li r3,0
	ctx.r3.s64 = 0;
	// lbz r10,113(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 113);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// stb r10,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r10.u8);
	// cmpwi cr6,r8,8
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 8, ctx.xer);
	// stb r8,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r8.u8);
	// bge cr6,0x8813b608
	if (!ctx.cr6.lt) goto loc_8813B608;
loc_8813B604:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8813B608:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8813B610"))) PPC_WEAK_FUNC(sub_8813B610);
PPC_FUNC_IMPL(__imp__sub_8813B610) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x8813B618;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,2(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r27,0
	ctx.r27.s64 = 0;
	// li r26,1
	ctx.r26.s64 = 1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813b71c
	if (!ctx.cr6.eq) goto loc_8813B71C;
	// lwz r9,128(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// lwz r11,28(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8813b660
	if (ctx.cr6.eq) goto loc_8813B660;
loc_8813B648:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8813b704
	if (ctx.cr6.eq) goto loc_8813B704;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813b648
	if (!ctx.cr6.eq) goto loc_8813B648;
loc_8813B660:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_8813B664:
	// addi r30,r31,8
	ctx.r30.s64 = ctx.r31.s64 + 8;
	// lis r10,-30671
	ctx.r10.s64 = -2010054656;
	// stw r30,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r30.u32);
	// lis r8,-30671
	ctx.r8.s64 = -2010054656;
	// lbz r7,3(r31)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r31.u32 + 3);
	// addi r6,r10,-23660
	ctx.r6.s64 = ctx.r10.s64 + -23660;
	// lbz r5,4(r31)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r31.u32 + 4);
	// rotlwi r4,r5,2
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// rotlwi r10,r7,3
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 3);
	// lwzx r9,r4,r6
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r6.u32);
	// addi r3,r8,-24468
	ctx.r3.s64 = ctx.r8.s64 + -24468;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// li r8,2
	ctx.r8.s64 = 2;
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r7,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r7.u32);
	// lwz r6,4(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r6,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r6.u32);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r5,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r5.u32);
	// lwz r4,92(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// stw r4,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r4.u32);
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// stw r26,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r26.u32);
	// lbz r10,114(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 114);
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r6,120(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// rlwinm r5,r6,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// extsb r11,r10
	ctx.r11.s64 = ctx.r10.s8;
	// stw r7,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r7.u32);
	// stw r9,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r9.u32);
	// lhzx r10,r5,r3
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r5.u32 + ctx.r3.u32);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stb r26,2(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2, ctx.r26.u8);
	// stb r8,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r8.u8);
	// stb r8,5(r31)
	PPC_STORE_U8(ctx.r31.u32 + 5, ctx.r8.u8);
	// sth r4,56(r31)
	PPC_STORE_U16(ctx.r31.u32 + 56, ctx.r4.u16);
	// b 0x8813b740
	goto loc_8813B740;
loc_8813B704:
	// lwz r10,24(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8813b714
	if (ctx.cr6.eq) goto loc_8813B714;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_8813B714:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x8813b664
	goto loc_8813B664;
loc_8813B71C:
	// lbz r10,1(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// lis r9,-30651
	ctx.r9.s64 = -2008743936;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r30,r31,8
	ctx.r30.s64 = ctx.r31.s64 + 8;
	// addi r8,r9,-8560
	ctx.r8.s64 = ctx.r9.s64 + -8560;
	// rotlwi r7,r10,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lwzx r10,r7,r8
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r6,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
loc_8813B740:
	// lbz r11,5(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 5);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8813b780
	if (ctx.cr6.eq) goto loc_8813B780;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x8813b76c
	if (ctx.cr6.eq) goto loc_8813B76C;
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r11,72(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 72);
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r10,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r10.u32);
loc_8813B76C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8813b180
	ctx.lr = 0x8813B774;
	sub_8813B180(ctx, base);
	// lbz r11,5(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 5);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// stb r10,5(r31)
	PPC_STORE_U8(ctx.r31.u32 + 5, ctx.r10.u8);
loc_8813B780:
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lis r7,360
	ctx.r7.s64 = 23592960;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// add r28,r9,r8
	ctx.r28.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r29,r11,r10
	ctx.r29.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r28,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r28.u32);
	// stw r29,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r29.u32);
	// cmpw cr6,r29,r7
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r7.s32, ctx.xer);
	// bge cr6,0x8813b8d4
	if (!ctx.cr6.lt) goto loc_8813B8D4;
	// lis r11,280
	ctx.r11.s64 = 18350080;
	// cmpw cr6,r28,r11
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x8813b8d4
	if (!ctx.cr6.lt) goto loc_8813B8D4;
	// lis r11,-40
	ctx.r11.s64 = -2621440;
	// cmpw cr6,r28,r11
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x8813b8d4
	if (!ctx.cr6.gt) goto loc_8813B8D4;
	// lbz r11,112(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 112);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r9.u8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge cr6,0x8813b800
	if (!ctx.cr6.lt) goto loc_8813B800;
	// lbz r11,110(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 110);
	// lbz r10,113(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 113);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// stb r10,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r10.u8);
	// cmpwi cr6,r8,3
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 3, ctx.xer);
	// stb r8,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r8.u8);
	// blt cr6,0x8813b800
	if (ctx.cr6.lt) goto loc_8813B800;
	// stb r27,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r27.u8);
loc_8813B800:
	// lwz r10,120(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// lis r9,-30671
	ctx.r9.s64 = -2010054656;
	// lbz r8,110(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 110);
	// addi r7,r9,-24460
	ctx.r7.s64 = ctx.r9.s64 + -24460;
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// rlwinm r6,r10,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// extsb r9,r8
	ctx.r9.s64 = ctx.r8.s8;
	// cmpwi cr6,r11,256
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 256, ctx.xer);
	// lhzx r10,r6,r7
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r6.u32 + ctx.r7.u32);
	// add r30,r10,r9
	ctx.r30.u64 = ctx.r10.u64 + ctx.r9.u64;
	// blt cr6,0x8813b834
	if (ctx.cr6.lt) goto loc_8813B834;
	// subfic r11,r11,512
	ctx.xer.ca = ctx.r11.u32 <= 512;
	ctx.r11.s64 = 512 - ctx.r11.s64;
	// mr r27,r26
	ctx.r27.u64 = ctx.r26.u64;
loc_8813B834:
	// srawi r11,r11,3
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 3;
	// li r6,150
	ctx.r6.s64 = 150;
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r3,r11,r30
	ctx.r3.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x881538c0
	ctx.lr = 0x8813B858;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813b870
	if (ctx.cr6.eq) goto loc_8813B870;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r27,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_8813B870:
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// li r6,150
	ctx.r6.s64 = 150;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// subf r5,r11,r29
	ctx.r5.s64 = ctx.r29.s64 - ctx.r11.s64;
	// subf r4,r10,r28
	ctx.r4.s64 = ctx.r28.s64 - ctx.r10.s64;
	// bl 0x881538c0
	ctx.lr = 0x8813B88C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813b8c8
	if (ctx.cr6.eq) goto loc_8813B8C8;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// rlwinm r8,r27,26,0,5
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 26) & 0xFC000000;
	// lis r7,128
	ctx.r7.s64 = 8388608;
	// or r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 | ctx.r9.u64;
	// ori r5,r7,32896
	ctx.r5.u64 = ctx.r7.u64 | 32896;
	// lwz r11,-11932(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11932);
	// oris r4,r6,531
	ctx.r4.u64 = ctx.r6.u64 | 34799616;
	// stw r5,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r5.u32);
	// ori r4,r4,32768
	ctx.r4.u64 = ctx.r4.u64 | 32768;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stw r11,-11932(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11932, ctx.r11.u32);
loc_8813B8C8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_8813B8D4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8813B8E0"))) PPC_WEAK_FUNC(sub_8813B8E0);
PPC_FUNC_IMPL(__imp__sub_8813B8E0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,0(r5)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x8813b96c
	if (!ctx.cr6.eq) goto loc_8813B96C;
	// lbz r5,4(r5)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r5.u32 + 4);
	// lwz r4,100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// bl 0x88147a30
	ctx.lr = 0x8813B914;
	sub_88147A30(ctx, base);
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// subf. r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r9,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r9.u32);
	// bgt 0x8813b96c
	if (ctx.cr0.gt) goto loc_8813B96C;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8813b958
	if (ctx.cr6.eq) goto loc_8813B958;
loc_8813B940:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8813b958
	if (ctx.cr6.eq) goto loc_8813B958;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813b940
	if (!ctx.cr6.eq) goto loc_8813B940;
loc_8813B958:
	// lis r10,-30700
	ctx.r10.s64 = -2011955200;
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// stb r9,2(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2, ctx.r9.u8);
	// addi r9,r10,-19856
	ctx.r9.s64 = ctx.r10.s64 + -19856;
	// stw r9,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r9.u32);
loc_8813B96C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813B988"))) PPC_WEAK_FUNC(sub_8813B988);
PPC_FUNC_IMPL(__imp__sub_8813B988) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071120
	ctx.lr = 0x8813B990;
	__savegprlr_14(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// lis r10,-30671
	ctx.r10.s64 = -2010054656;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r8,-30671
	ctx.r8.s64 = -2010054656;
	// extsh r6,r11
	ctx.r6.s64 = ctx.r11.s16;
	// addi r4,r10,-23604
	ctx.r4.s64 = ctx.r10.s64 + -23604;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// addi r3,r8,-23628
	ctx.r3.s64 = ctx.r8.s64 + -23628;
	// lis r7,-30671
	ctx.r7.s64 = -2010054656;
	// lbz r11,1(r9)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 1);
	// rlwinm r10,r6,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r5,-30643
	ctx.r5.s64 = -2008219648;
	// addi r9,r7,-23612
	ctx.r9.s64 = ctx.r7.s64 + -23612;
	// lbzx r7,r6,r4
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r4.u32);
	// addi r8,r5,26432
	ctx.r8.s64 = ctx.r5.s64 + 26432;
	// lis r5,-30647
	ctx.r5.s64 = -2008481792;
	// lhzx r4,r10,r3
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r3.u32);
	// extsb r14,r11
	ctx.r14.s64 = ctx.r11.s8;
	// addi r10,r5,-5576
	ctx.r10.s64 = ctx.r5.s64 + -5576;
	// lbzx r5,r6,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r9.u32);
	// mulli r9,r14,9232
	ctx.r9.s64 = ctx.r14.s64 * 9232;
	// lwz r11,324(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 324);
	// sth r4,80(r1)
	PPC_STORE_U16(ctx.r1.u32 + 80, ctx.r4.u16);
	// extsb r3,r7
	ctx.r3.s64 = ctx.r7.s8;
	// extsb r4,r5
	ctx.r4.s64 = ctx.r5.s8;
	// add r29,r9,r10
	ctx.r29.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x8813ba14
	if (!ctx.cr6.eq) goto loc_8813BA14;
	// cmpwi cr6,r4,7
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 7, ctx.xer);
	// blt cr6,0x8813ba14
	if (ctx.cr6.lt) goto loc_8813BA14;
	// li r4,7
	ctx.r4.s64 = 7;
loc_8813BA14:
	// li r19,0
	ctx.r19.s64 = 0;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// mr r8,r19
	ctx.r8.u64 = ctx.r19.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble cr6,0x8813ba44
	if (!ctx.cr6.gt) goto loc_8813BA44;
	// addi r11,r1,92
	ctx.r11.s64 = ctx.r1.s64 + 92;
	// li r10,-1
	ctx.r10.s64 = -1;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813ba44
	if (ctx.cr6.eq) goto loc_8813BA44;
	// mtctr r3
	ctx.ctr.u64 = ctx.r3.u64;
loc_8813BA3C:
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8813ba3c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8813BA3C;
loc_8813BA44:
	// mr r5,r19
	ctx.r5.u64 = ctx.r19.u64;
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
loc_8813BA4C:
	// lwz r11,9200(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 9200);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,9200(r29)
	PPC_STORE_U32(ctx.r29.u32 + 9200, ctx.r11.u32);
	// cmpwi cr6,r11,56
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 56, ctx.xer);
	// blt cr6,0x8813ba64
	if (ctx.cr6.lt) goto loc_8813BA64;
	// stw r19,9200(r29)
	PPC_STORE_U32(ctx.r29.u32 + 9200, ctx.r19.u32);
loc_8813BA64:
	// lwz r11,9200(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 9200);
	// mulli r10,r11,164
	ctx.r10.s64 = ctx.r11.s64 * 164;
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + ctx.r29.u64;
	// lbz r10,16(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8813baa0
	if (!ctx.cr6.eq) goto loc_8813BAA0;
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpw cr6,r10,r4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r4.s32, ctx.xer);
	// bge cr6,0x8813ba8c
	if (!ctx.cr6.lt) goto loc_8813BA8C;
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r11.u32);
loc_8813BA8C:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmpw cr6,r8,r3
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r3.s32, ctx.xer);
	// bge cr6,0x8813baac
	if (!ctx.cr6.lt) goto loc_8813BAAC;
loc_8813BAA0:
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// cmpwi cr6,r5,56
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 56, ctx.xer);
	// blt cr6,0x8813ba4c
	if (ctx.cr6.lt) goto loc_8813BA4C;
loc_8813BAAC:
	// lwz r11,9220(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 9220);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,9220(r29)
	PPC_STORE_U32(ctx.r29.u32 + 9220, ctx.r11.u32);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// blt cr6,0x8813bac4
	if (ctx.cr6.lt) goto loc_8813BAC4;
	// stw r19,9220(r29)
	PPC_STORE_U32(ctx.r29.u32 + 9220, ctx.r19.u32);
loc_8813BAC4:
	// lwz r11,9224(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 9224);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,9224(r29)
	PPC_STORE_U32(ctx.r29.u32 + 9224, ctx.r11.u32);
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// blt cr6,0x8813badc
	if (ctx.cr6.lt) goto loc_8813BADC;
	// stw r19,9224(r29)
	PPC_STORE_U32(ctx.r29.u32 + 9224, ctx.r19.u32);
loc_8813BADC:
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// lis r10,-30671
	ctx.r10.s64 = -2010054656;
	// lis r9,-30671
	ctx.r9.s64 = -2010054656;
	// rlwinm r8,r6,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r11,-24100
	ctx.r7.s64 = ctx.r11.s64 + -24100;
	// addi r6,r10,-23852
	ctx.r6.s64 = ctx.r10.s64 + -23852;
	// addi r5,r9,-24292
	ctx.r5.s64 = ctx.r9.s64 + -24292;
	// addi r16,r1,96
	ctx.r16.s64 = ctx.r1.s64 + 96;
	// mr r22,r19
	ctx.r22.u64 = ctx.r19.u64;
	// lwzx r28,r8,r7
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// lwzx r27,r8,r6
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r6.u32);
	// lwzx r25,r8,r5
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r5.u32);
	// ble cr6,0x8813bd3c
	if (!ctx.cr6.gt) goto loc_8813BD3C;
	// lis r10,-30641
	ctx.r10.s64 = -2008088576;
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// addi r17,r10,-19568
	ctx.r17.s64 = ctx.r10.s64 + -19568;
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// addi r30,r29,9204
	ctx.r30.s64 = ctx.r29.s64 + 9204;
	// li r20,2
	ctx.r20.s64 = 2;
	// li r24,1
	ctx.r24.s64 = 1;
	// lwz r9,0(r17)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r17.u32 + 0);
	// li r21,100
	ctx.r21.s64 = 100;
	// lwz r18,-4596(r17)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r17.u32 + -4596);
	// addi r23,r11,-23596
	ctx.r23.s64 = ctx.r11.s64 + -23596;
	// addi r15,r10,9552
	ctx.r15.s64 = ctx.r10.s64 + 9552;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
loc_8813BB48:
	// lwz r11,0(r16)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x8813bd1c
	if (ctx.cr6.lt) goto loc_8813BD1C;
	// mulli r11,r11,164
	ctx.r11.s64 = ctx.r11.s64 * 164;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// addi r31,r11,16
	ctx.r31.s64 = ctx.r11.s64 + 16;
	// stb r22,19(r11)
	PPC_STORE_U8(ctx.r11.u32 + 19, ctx.r22.u8);
	// lwz r11,-9204(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -9204);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-9204(r30)
	PPC_STORE_U32(ctx.r30.u32 + -9204, ctx.r11.u32);
	// lwz r11,9228(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 9228);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stw r9,9228(r29)
	PPC_STORE_U32(ctx.r29.u32 + 9228, ctx.r9.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// blt cr6,0x8813bb94
	if (ctx.cr6.lt) goto loc_8813BB94;
	// stw r19,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r19.u32);
loc_8813BB94:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// addic. r10,r31,20
	ctx.xer.ca = ctx.r31.u32 > 4294967275;
	ctx.r10.s64 = ctx.r31.s64 + 20;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r7,0(r26)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// addi r5,r31,16
	ctx.r5.s64 = ctx.r31.s64 + 16;
	// lwz r8,16(r26)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r26.u32 + 16);
	// lwz r6,20(r26)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r26.u32 + 20);
	// stb r11,114(r31)
	PPC_STORE_U8(ctx.r31.u32 + 114, ctx.r11.u8);
	// lwz r3,9220(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 9220);
	// stb r3,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r3.u8);
	// lwz r4,9224(r29)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r29.u32 + 9224);
	// rlwinm r3,r4,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r3,r23
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r23.u32);
	// lhz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// lhz r4,4(r26)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r26.u32 + 4);
	// stb r11,111(r31)
	PPC_STORE_U8(ctx.r31.u32 + 111, ctx.r11.u8);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// stb r19,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r19.u8);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// stb r20,113(r31)
	PPC_STORE_U8(ctx.r31.u32 + 113, ctx.r20.u8);
	// lwz r4,0(r25)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// stw r4,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r4.u32);
	// lwz r4,4(r25)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r25.u32 + 4);
	// stw r4,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r4.u32);
	// stb r14,1(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1, ctx.r14.u8);
	// stw r7,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r7.u32);
	// stb r24,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r24.u8);
	// lwz r7,4(r27)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// add r9,r6,r7
	ctx.r9.u64 = ctx.r6.u64 + ctx.r7.u64;
	// stw r8,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r8.u32);
	// stw r11,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// stw r9,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r9.u32);
	// stb r3,4(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4, ctx.r3.u8);
	// lwz r7,8(r27)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r27.u32 + 8);
	// clrlwi r6,r7,23
	ctx.r6.u64 = ctx.r7.u32 & 0x1FF;
	// stw r6,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r6.u32);
	// rotlwi r4,r6,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// mulli r9,r3,100
	ctx.r9.s64 = ctx.r3.s64 * 100;
	// divwu r8,r9,r21
	ctx.r8.u32 = ppc_divwu(ctx.r9.u32, ctx.r21.u32);
	// clrlwi r9,r4,23
	ctx.r9.u64 = ctx.r4.u32 & 0x1FF;
	// stw r8,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r8.u32);
	// lwz r7,0(r28)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// stw r7,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r7.u32);
	// lwz r6,4(r28)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// stw r6,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r6.u32);
	// beq 0x8813bc68
	if (ctx.cr0.eq) goto loc_8813BC68;
	// addi r8,r9,128
	ctx.r8.s64 = ctx.r9.s64 + 128;
	// rlwinm r7,r8,2,21,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x7FC;
	// lwzx r6,r7,r15
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r15.u32);
	// mullw r4,r6,r11
	ctx.r4.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r11.s32);
	// stw r4,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
loc_8813BC68:
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x8813bc80
	if (ctx.cr6.eq) goto loc_8813BC80;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r15
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r15.u32);
	// mullw r8,r9,r11
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// stw r8,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r8.u32);
loc_8813BC80:
	// lbz r11,1(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r4,r11,4
	ctx.r4.s64 = ctx.r11.s64 + 4;
	// bl 0x881556a0
	ctx.lr = 0x8813BC90;
	sub_881556A0(ctx, base);
	// stw r3,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r3.u32);
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// mr r10,r19
	ctx.r10.u64 = ctx.r19.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8813bcbc
	if (ctx.cr6.eq) goto loc_8813BCBC;
loc_8813BCA4:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8813bd48
	if (ctx.cr6.eq) goto loc_8813BD48;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813bca4
	if (!ctx.cr6.eq) goto loc_8813BCA4;
loc_8813BCBC:
	// mr r11,r19
	ctx.r11.u64 = ctx.r19.u64;
loc_8813BCC0:
	// lis r10,-30700
	ctx.r10.s64 = -2011955200;
	// stw r24,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r24.u32);
	// lis r9,-30700
	ctx.r9.s64 = -2011955200;
	// lwz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// addi r7,r10,-18208
	ctx.r7.s64 = ctx.r10.s64 + -18208;
	// stw r31,36(r8)
	PPC_STORE_U32(ctx.r8.u32 + 36, ctx.r31.u32);
	// addi r6,r9,-18928
	ctx.r6.s64 = ctx.r9.s64 + -18928;
	// stw r7,32(r8)
	PPC_STORE_U32(ctx.r8.u32 + 32, ctx.r7.u32);
	// cmpwi cr6,r18,0
	ctx.cr6.compare<int32_t>(ctx.r18.s32, 0, ctx.xer);
	// stb r19,2(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2, ctx.r19.u8);
	// stw r6,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r6.u32);
	// bne cr6,0x8813bd18
	if (!ctx.cr6.eq) goto loc_8813BD18;
	// lwz r11,88(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8813bd18
	if (!ctx.cr6.eq) goto loc_8813BD18;
	// li r18,3
	ctx.r18.s64 = 3;
	// li r6,16
	ctx.r6.s64 = 16;
	// li r5,30
	ctx.r5.s64 = 30;
	// stw r18,-4596(r17)
	PPC_STORE_U32(ctx.r17.u32 + -4596, ctx.r18.u32);
	// li r4,70
	ctx.r4.s64 = 70;
	// addi r3,r14,3
	ctx.r3.s64 = ctx.r14.s64 + 3;
	// bl 0x880e3240
	ctx.lr = 0x8813BD18;
	sub_880E3240(ctx, base);
loc_8813BD18:
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_8813BD1C:
	// addi r22,r22,1
	ctx.r22.s64 = ctx.r22.s64 + 1;
	// addi r28,r28,8
	ctx.r28.s64 = ctx.r28.s64 + 8;
	// addi r27,r27,12
	ctx.r27.s64 = ctx.r27.s64 + 12;
	// addi r25,r25,8
	ctx.r25.s64 = ctx.r25.s64 + 8;
	// addi r16,r16,4
	ctx.r16.s64 = ctx.r16.s64 + 4;
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// cmpw cr6,r22,r3
	ctx.cr6.compare<int32_t>(ctx.r22.s32, ctx.r3.s32, ctx.xer);
	// blt cr6,0x8813bb48
	if (ctx.cr6.lt) goto loc_8813BB48;
loc_8813BD3C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
loc_8813BD48:
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8813bd58
	if (ctx.cr6.eq) goto loc_8813BD58;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_8813BD58:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x8813bcc0
	goto loc_8813BCC0;
}

__attribute__((alias("__imp__sub_8813BD60"))) PPC_WEAK_FUNC(sub_8813BD60);
PPC_FUNC_IMPL(__imp__sub_8813BD60) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813BD64"))) PPC_WEAK_FUNC(sub_8813BD64);
PPC_FUNC_IMPL(__imp__sub_8813BD64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8813BD68"))) PPC_WEAK_FUNC(sub_8813BD68);
PPC_FUNC_IMPL(__imp__sub_8813BD68) {
	PPC_FUNC_PROLOGUE();
	// lwz r9,128(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r8,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r8.u8);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// addi r11,r11,576
	ctx.r11.s64 = ctx.r11.s64 + 576;
	// lwz r10,-104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -104);
	// cmpwi cr6,r10,3000
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3000, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r8.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,-104(r11)
	PPC_STORE_U32(ctx.r11.u32 + -104, ctx.r10.u32);
	// stwx r9,r7,r11
	PPC_STORE_U32(ctx.r7.u32 + ctx.r11.u32, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813BDA8"))) PPC_WEAK_FUNC(sub_8813BDA8);
PPC_FUNC_IMPL(__imp__sub_8813BDA8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30648
	ctx.r11.s64 = -2008547328;
	// li r5,21184
	ctx.r5.s64 = 21184;
	// addi r31,r11,13904
	ctx.r31.s64 = ctx.r11.s64 + 13904;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x8813BDD0;
	sub_88073BD0(ctx, base);
	// lis r8,-30671
	ctx.r8.s64 = -2010054656;
	// lis r10,16838
	ctx.r10.s64 = 1103495168;
	// lis r9,-21846
	ctx.r9.s64 = -1431699456;
	// ori r5,r10,20077
	ctx.r5.u64 = ctx.r10.u64 | 20077;
	// addi r11,r31,2632
	ctx.r11.s64 = ctx.r31.s64 + 2632;
	// lwz r10,4200(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4200);
	// ori r6,r9,43691
	ctx.r6.u64 = ctx.r9.u64 | 43691;
loc_8813BDEC:
	// mullw r10,r10,r5
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r5.s32);
	// addi r10,r10,12345
	ctx.r10.s64 = ctx.r10.s64 + 12345;
	// addi r4,r31,23816
	ctx.r4.s64 = ctx.r31.s64 + 23816;
	// stw r10,4200(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4200, ctx.r10.u32);
	// lhz r3,4200(r8)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4200);
	// mulhwu r9,r3,r6
	ctx.r9.u64 = (uint64_t(ctx.r3.u32) * uint64_t(ctx.r6.u32)) >> 32;
	// rlwinm r9,r9,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r7,r9,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r9,r7
	ctx.r7.u64 = ctx.r9.u64 + ctx.r7.u64;
	// subf r3,r7,r3
	ctx.r3.s64 = ctx.r3.s64 - ctx.r7.s64;
	// extsh r7,r3
	ctx.r7.s64 = ctx.r3.s16;
	// stw r7,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// addi r11,r11,2648
	ctx.r11.s64 = ctx.r11.s64 + 2648;
	// cmpw cr6,r11,r4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r4.s32, ctx.xer);
	// blt cr6,0x8813bdec
	if (ctx.cr6.lt) goto loc_8813BDEC;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813BE3C"))) PPC_WEAK_FUNC(sub_8813BE3C);
PPC_FUNC_IMPL(__imp__sub_8813BE3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8813BE40"))) PPC_WEAK_FUNC(sub_8813BE40);
PPC_FUNC_IMPL(__imp__sub_8813BE40) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x8813BE48;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30648
	ctx.r11.s64 = -2008547328;
	// li r26,8
	ctx.r26.s64 = 8;
	// addi r30,r11,13904
	ctx.r30.s64 = ctx.r11.s64 + 13904;
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r29,r11,576
	ctx.r29.s64 = ctx.r11.s64 + 576;
loc_8813BE64:
	// lwz r11,2644(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2644);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8813bf14
	if (ctx.cr6.eq) goto loc_8813BF14;
	// addi r31,r30,4
	ctx.r31.s64 = ctx.r30.s64 + 4;
	// li r27,16
	ctx.r27.s64 = 16;
loc_8813BE78:
	// lbz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8813bf08
	if (ctx.cr6.eq) goto loc_8813BF08;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bgt cr6,0x8813bea0
	if (ctx.cr6.gt) goto loc_8813BEA0;
	// lwz r11,140(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8813BEA0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8813BEA0:
	// lwz r11,140(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8813BEB0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8813bf08
	if (!ctx.cr6.eq) goto loc_8813BF08;
	// lwz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// stb r28,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r28.u8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8813bee8
	if (ctx.cr6.eq) goto loc_8813BEE8;
	// lwz r11,-104(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -104);
	// cmpwi cr6,r11,3000
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3000, ctx.xer);
	// bge cr6,0x8813bee8
	if (!ctx.cr6.lt) goto loc_8813BEE8;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r28,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r28.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-104(r29)
	PPC_STORE_U32(ctx.r29.u32 + -104, ctx.r11.u32);
	// stwx r10,r9,r29
	PPC_STORE_U32(ctx.r9.u32 + ctx.r29.u32, ctx.r10.u32);
loc_8813BEE8:
	// lbz r11,3(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 3);
	// rotlwi r11,r11,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// lwzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r30.u32);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stwx r10,r11,r30
	PPC_STORE_U32(ctx.r11.u32 + ctx.r30.u32, ctx.r10.u32);
	// lwz r11,2644(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2644);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// stw r9,2644(r30)
	PPC_STORE_U32(ctx.r30.u32 + 2644, ctx.r9.u32);
loc_8813BF08:
	// addi r31,r31,164
	ctx.r31.s64 = ctx.r31.s64 + 164;
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// bne 0x8813be78
	if (!ctx.cr0.eq) goto loc_8813BE78;
loc_8813BF14:
	// addi r30,r30,2648
	ctx.r30.s64 = ctx.r30.s64 + 2648;
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne 0x8813be64
	if (!ctx.cr0.eq) goto loc_8813BE64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8813BF28"))) PPC_WEAK_FUNC(sub_8813BF28);
PPC_FUNC_IMPL(__imp__sub_8813BF28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x8813BF30;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,76(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// lis r8,-30671
	ctx.r8.s64 = -2010054656;
	// lhz r9,56(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 56);
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// addi r7,r11,4
	ctx.r7.s64 = ctx.r11.s64 + 4;
	// lwz r29,32(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r28,36(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// addi r11,r8,3944
	ctx.r11.s64 = ctx.r8.s64 + 3944;
	// srawi r6,r7,3
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 3;
	// addi r31,r10,9552
	ctx.r31.s64 = ctx.r10.s64 + 9552;
	// rlwinm r4,r6,1,25,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0x7E;
	// addi r5,r11,2
	ctx.r5.s64 = ctx.r11.s64 + 2;
	// srawi r3,r4,1
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1) != 0);
	ctx.r3.s64 = ctx.r4.s32 >> 1;
	// rlwinm r10,r4,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// addze r8,r3
	temp.s64 = ctx.r3.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r8.s64 = temp.s64;
	// li r6,151
	ctx.r6.s64 = 151;
	// rlwinm r30,r8,3,23,28
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0x1F8;
	// addi r7,r30,128
	ctx.r7.s64 = ctx.r30.s64 + 128;
	// lhzx r11,r10,r11
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r11.u32);
	// rlwinm r4,r30,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lhzx r26,r10,r5
	ctx.r26.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r5.u32);
	// rlwinm r3,r7,2,21,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x7FC;
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwzx r10,r4,r31
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r31.u32);
	// lwzx r11,r3,r31
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r31.u32);
	// add r3,r8,r9
	ctx.r3.u64 = ctx.r8.u64 + ctx.r9.u64;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r10,6,0,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// rlwinm r10,r9,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0xFFFFFFC0;
	// add r4,r11,r29
	ctx.r4.u64 = ctx.r11.u64 + ctx.r29.u64;
	// add r5,r10,r28
	ctx.r5.u64 = ctx.r10.u64 + ctx.r28.u64;
	// bl 0x881538c0
	ctx.lr = 0x8813BFC4;
	sub_881538C0(ctx, base);
	// lis r8,545
	ctx.r8.s64 = 35717120;
	// lis r27,-30597
	ctx.r27.s64 = -2005204992;
	// ori r25,r8,32768
	ctx.r25.u64 = ctx.r8.u64 | 32768;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813bffc
	if (ctx.cr6.eq) goto loc_8813BFFC;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r26,26,0,5
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 26) & 0xFC000000;
	// lwz r11,-11932(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// addi r26,r11,1
	ctx.r26.s64 = ctx.r11.s64 + 1;
	// or r7,r8,r25
	ctx.r7.u64 = ctx.r8.u64 | ctx.r25.u64;
	// stw r26,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r26.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// b 0x8813c000
	goto loc_8813C000;
loc_8813BFFC:
	// lwz r26,-11932(r27)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
loc_8813C000:
	// addi r11,r30,128
	ctx.r11.s64 = ctx.r30.s64 + 128;
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r11,2,21,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x7FC;
	// li r6,151
	ctx.r6.s64 = 151;
	// li r3,402
	ctx.r3.s64 = 402;
	// lwzx r11,r10,r31
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// lwzx r10,r9,r31
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r11,r9
	ctx.r7.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r5,r10,r8
	ctx.r5.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r11,r7,6,0,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 6) & 0xFFFFFFC0;
	// rlwinm r10,r5,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 6) & 0xFFFFFFC0;
	// add r4,r11,r29
	ctx.r4.u64 = ctx.r11.u64 + ctx.r29.u64;
	// add r5,r10,r28
	ctx.r5.u64 = ctx.r10.u64 + ctx.r28.u64;
	// bl 0x881538c0
	ctx.lr = 0x8813C040;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813c068
	if (ctx.cr6.eq) goto loc_8813C068;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,48
	ctx.r9.s64 = 3145728;
	// addi r11,r26,1
	ctx.r11.s64 = ctx.r26.s64 + 1;
	// ori r8,r9,32800
	ctx.r8.u64 = ctx.r9.u64 | 32800;
	// or r7,r10,r25
	ctx.r7.u64 = ctx.r10.u64 | ctx.r25.u64;
	// stw r11,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r11.u32);
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
loc_8813C068:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8813C070"))) PPC_WEAK_FUNC(sub_8813C070);
PPC_FUNC_IMPL(__imp__sub_8813C070) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071144
	ctx.lr = 0x8813C078;
	__savegprlr_23(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r10,2(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r11,4200
	ctx.r30.s64 = ctx.r11.s64 + 4200;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8813c268
	if (!ctx.cr6.eq) goto loc_8813C268;
	// lwz r9,128(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// lwz r8,28(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8813c0c0
	if (ctx.cr6.eq) goto loc_8813C0C0;
loc_8813C0A8:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8813c0c0
	if (ctx.cr6.eq) goto loc_8813C0C0;
	// lwz r8,0(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8813c0a8
	if (!ctx.cr6.eq) goto loc_8813C0A8;
loc_8813C0C0:
	// lis r11,16838
	ctx.r11.s64 = 1103495168;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// lis r8,-13108
	ctx.r8.s64 = -859045888;
	// ori r11,r11,20077
	ctx.r11.u64 = ctx.r11.u64 | 20077;
	// ori r7,r8,52429
	ctx.r7.u64 = ctx.r8.u64 | 52429;
	// mullw r9,r9,r11
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// addi r9,r9,12345
	ctx.r9.s64 = ctx.r9.s64 + 12345;
	// lis r6,20971
	ctx.r6.s64 = 1374355456;
	// stw r9,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r9.u32);
	// mullw r9,r9,r11
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// lwz r8,68(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// lwz r5,76(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r9,r9,12345
	ctx.r9.s64 = ctx.r9.s64 + 12345;
	// srawi r29,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r29.s64 = ctx.r8.s32 >> 2;
	// mullw r8,r9,r11
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// lhz r28,0(r30)
	ctx.r28.u64 = PPC_LOAD_U16(ctx.r30.u32 + 0);
	// stw r9,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r9.u32);
	// mulhwu r7,r28,r7
	ctx.r7.u64 = (uint64_t(ctx.r28.u32) * uint64_t(ctx.r7.u32)) >> 32;
	// rlwinm r9,r7,29,3,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 29) & 0x1FFFFFFF;
	// addi r11,r8,12345
	ctx.r11.s64 = ctx.r8.s64 + 12345;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// li r27,1
	ctx.r27.s64 = 1;
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// lhz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r30.u32 + 0);
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// addze r11,r29
	temp.s64 = ctx.r29.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r29.u32;
	ctx.r11.s64 = temp.s64;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// stb r27,2(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2, ctx.r27.u8);
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// stw r11,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// ori r8,r6,34079
	ctx.r8.u64 = ctx.r6.u64 | 34079;
	// subf r6,r9,r28
	ctx.r6.s64 = ctx.r28.s64 - ctx.r9.s64;
	// mulhwu r29,r7,r8
	ctx.r29.u64 = (uint64_t(ctx.r7.u32) * uint64_t(ctx.r8.u32)) >> 32;
	// extsh r8,r6
	ctx.r8.s64 = ctx.r6.s16;
	// lhz r28,0(r30)
	ctx.r28.u64 = PPC_LOAD_U16(ctx.r30.u32 + 0);
	// lis r6,14563
	ctx.r6.s64 = 954400768;
	// addi r9,r8,-4
	ctx.r9.s64 = ctx.r8.s64 + -4;
	// rlwinm r8,r29,29,3,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 29) & 0x1FFFFFFF;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// ori r6,r6,36409
	ctx.r6.u64 = ctx.r6.u64 | 36409;
	// add r9,r9,r5
	ctx.r9.u64 = ctx.r9.u64 + ctx.r5.u64;
	// lis r29,-30667
	ctx.r29.s64 = -2009792512;
	// clrlwi r9,r9,23
	ctx.r9.u64 = ctx.r9.u32 & 0x1FF;
	// mulli r8,r8,25
	ctx.r8.s64 = ctx.r8.s64 * 25;
	// addi r25,r9,128
	ctx.r25.s64 = ctx.r9.s64 + 128;
	// rlwinm r24,r9,2,0,29
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// mulhwu r6,r28,r6
	ctx.r6.u64 = (uint64_t(ctx.r28.u32) * uint64_t(ctx.r6.u32)) >> 32;
	// lis r27,-30667
	ctx.r27.s64 = -2009792512;
	// li r9,1
	ctx.r9.s64 = 1;
	// lis r23,-30714
	ctx.r23.s64 = -2012872704;
	// subf r26,r8,r7
	ctx.r26.s64 = ctx.r7.s64 - ctx.r8.s64;
	// stw r9,12380(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12380, ctx.r9.u32);
	// rlwinm r8,r6,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 31) & 0x7FFFFFFF;
	// li r7,153
	ctx.r7.s64 = 153;
	// addi r6,r23,9552
	ctx.r6.s64 = ctx.r23.s64 + 9552;
	// rlwinm r29,r25,2,21,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 2) & 0x7FC;
	// stw r7,12376(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12376, ctx.r7.u32);
	// mr r7,r26
	ctx.r7.u64 = ctx.r26.u64;
	// lis r26,-30667
	ctx.r26.s64 = -2009792512;
	// rlwinm r9,r8,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r25,r24,r6
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r24.u32 + ctx.r6.u32);
	// extsh r7,r7
	ctx.r7.s64 = ctx.r7.s16;
	// lwzx r29,r29,r6
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r6.u32);
	// li r6,64
	ctx.r6.s64 = 64;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stb r10,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r10.u8);
	// lis r27,-30667
	ctx.r27.s64 = -2009792512;
	// stw r6,12384(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12384, ctx.r6.u32);
	// addi r8,r7,-12
	ctx.r8.s64 = ctx.r7.s64 + -12;
	// stb r10,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r10.u8);
	// li r7,3
	ctx.r7.s64 = 3;
	// stb r10,113(r31)
	PPC_STORE_U8(ctx.r31.u32 + 113, ctx.r10.u8);
	// subf r6,r9,r28
	ctx.r6.s64 = ctx.r28.s64 - ctx.r9.s64;
	// stb r7,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r7.u8);
	// rlwinm r9,r8,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// stw r5,12368(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12368, ctx.r5.u32);
	// rlwinm r8,r6,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// lis r7,-30667
	ctx.r7.s64 = -2009792512;
	// mullw r6,r25,r11
	ctx.r6.s64 = int64_t(ctx.r25.s32) * int64_t(ctx.r11.s32);
	// stw r6,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r6.u32);
	// mullw r11,r29,r11
	ctx.r11.s64 = int64_t(ctx.r29.s32) * int64_t(ctx.r11.s32);
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lis r28,-30667
	ctx.r28.s64 = -2009792512;
	// add r11,r9,r4
	ctx.r11.u64 = ctx.r9.u64 + ctx.r4.u64;
	// add r10,r8,r3
	ctx.r10.u64 = ctx.r8.u64 + ctx.r3.u64;
	// stw r11,12364(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12364, ctx.r11.u32);
	// li r6,64
	ctx.r6.s64 = 64;
	// li r4,153
	ctx.r4.s64 = 153;
	// stw r10,12372(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12372, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x880f83f8
	ctx.lr = 0x8813C238;
	sub_880F83F8(ctx, base);
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// lwz r10,-19568(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -19568);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8813c268
	if (!ctx.cr6.eq) goto loc_8813C268;
	// lbz r9,1(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// li r10,3
	ctx.r10.s64 = 3;
	// li r6,17
	ctx.r6.s64 = 17;
	// li r5,28
	ctx.r5.s64 = 28;
	// stw r10,-19568(r11)
	PPC_STORE_U32(ctx.r11.u32 + -19568, ctx.r10.u32);
	// li r4,78
	ctx.r4.s64 = 78;
	// addi r3,r9,3
	ctx.r3.s64 = ctx.r9.s64 + 3;
	// bl 0x880e3240
	ctx.lr = 0x8813C268;
	sub_880E3240(ctx, base);
loc_8813C268:
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r27,-30597
	ctx.r27.s64 = -2005204992;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// add r28,r11,r10
	ctx.r28.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lbz r7,5(r31)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r31.u32 + 5);
	// lwz r11,120(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// add r29,r8,r9
	ctx.r29.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// lbz r8,110(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 110);
	// stw r29,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r29.u32);
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r28,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r28.u32);
	// beq cr6,0x8813c2fc
	if (ctx.cr6.eq) goto loc_8813C2FC;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// addi r9,r30,-25096
	ctx.r9.s64 = ctx.r30.s64 + -25096;
	// ori r11,r10,43008
	ctx.r11.u64 = ctx.r10.u64 | 43008;
	// extsb r10,r8
	ctx.r10.s64 = ctx.r8.s8;
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// subf r5,r11,r28
	ctx.r5.s64 = ctx.r28.s64 - ctx.r11.s64;
	// lhzx r11,r7,r9
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + ctx.r9.u32);
	// li r6,152
	ctx.r6.s64 = 152;
	// add r4,r29,r4
	ctx.r4.u64 = ctx.r29.u64 + ctx.r4.u64;
	// add r30,r11,r10
	ctx.r30.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x881538c0
	ctx.lr = 0x8813C2D4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813c30c
	if (ctx.cr6.eq) goto loc_8813C30C;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-11932(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
	// oris r9,r10,545
	ctx.r9.u64 = ctx.r10.u64 | 35717120;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// ori r9,r9,24576
	ctx.r9.u64 = ctx.r9.u64 | 24576;
	// stw r8,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r8.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// b 0x8813c30c
	goto loc_8813C30C;
loc_8813C2FC:
	// addi r9,r30,-25104
	ctx.r9.s64 = ctx.r30.s64 + -25104;
	// extsb r10,r8
	ctx.r10.s64 = ctx.r8.s8;
	// lhzx r11,r7,r9
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + ctx.r9.u32);
	// add r30,r11,r10
	ctx.r30.u64 = ctx.r11.u64 + ctx.r10.u64;
loc_8813C30C:
	// li r6,152
	ctx.r6.s64 = 152;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x881538c0
	ctx.lr = 0x8813C320;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813c344
	if (ctx.cr6.eq) goto loc_8813C344;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-11932(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
	// oris r9,r10,545
	ctx.r9.u64 = ctx.r10.u64 | 35717120;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// ori r9,r9,32768
	ctx.r9.u64 = ctx.r9.u64 | 32768;
	// stw r11,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r11.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_8813C344:
	// lbz r11,112(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 112);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r9.u8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge cr6,0x8813c380
	if (!ctx.cr6.lt) goto loc_8813C380;
	// lbz r11,110(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 110);
	// li r3,0
	ctx.r3.s64 = 0;
	// lbz r10,113(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 113);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// stb r10,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r10.u8);
	// cmpwi cr6,r8,8
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 8, ctx.xer);
	// stb r8,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r8.u8);
	// bge cr6,0x8813c384
	if (!ctx.cr6.lt) goto loc_8813C384;
loc_8813C380:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8813C384:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8813C38C"))) PPC_WEAK_FUNC(sub_8813C38C);
PPC_FUNC_IMPL(__imp__sub_8813C38C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8813C390"))) PPC_WEAK_FUNC(sub_8813C390);
PPC_FUNC_IMPL(__imp__sub_8813C390) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x8813C398;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,2(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813c3c0
	if (!ctx.cr6.eq) goto loc_8813C3C0;
	// li r11,2
	ctx.r11.s64 = 2;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r11.u8);
	// stb r10,2(r3)
	PPC_STORE_U8(ctx.r3.u32 + 2, ctx.r10.u8);
	// stb r11,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, ctx.r11.u8);
loc_8813C3C0:
	// lbz r10,1(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// lis r9,-30651
	ctx.r9.s64 = -2008743936;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lis r7,-30671
	ctx.r7.s64 = -2010054656;
	// addi r6,r9,-8560
	ctx.r6.s64 = ctx.r9.s64 + -8560;
	// lwz r5,100(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// rotlwi r4,r10,2
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lwz r3,156(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 156);
	// addi r24,r7,-20872
	ctx.r24.s64 = ctx.r7.s64 + -20872;
	// lbz r29,5(r31)
	ctx.r29.u64 = PPC_LOAD_U8(ctx.r31.u32 + 5);
	// lis r8,-30651
	ctx.r8.s64 = -2008743936;
	// rlwinm r9,r3,7,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 7) & 0xFFFFFF80;
	// addi r8,r8,-16096
	ctx.r8.s64 = ctx.r8.s64 + -16096;
	// lwzx r10,r4,r6
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r6.u32);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// li r28,0
	ctx.r28.s64 = 0;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r30,r31,8
	ctx.r30.s64 = ctx.r31.s64 + 8;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// lbz r10,1(r5)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r5.u32 + 1);
	// extsb r7,r10
	ctx.r7.s64 = ctx.r10.s8;
	// mulli r11,r7,3768
	ctx.r11.s64 = ctx.r7.s64 * 3768;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lwz r29,16(r11)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// beq cr6,0x8813c4e8
	if (ctx.cr6.eq) goto loc_8813C4E8;
	// lwz r10,96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8813c448
	if (!ctx.cr6.eq) goto loc_8813C448;
	// stw r29,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r29.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// bl 0x8813bf28
	ctx.lr = 0x8813C448;
	sub_8813BF28(ctx, base);
loc_8813C448:
	// lbz r11,5(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 5);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,5(r31)
	PPC_STORE_U8(ctx.r31.u32 + 5, ctx.r9.u8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bgt cr6,0x8813c4e8
	if (ctx.cr6.gt) goto loc_8813C4E8;
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8813c6d0
	if (ctx.cr6.eq) goto loc_8813C6D0;
	// lwz r9,128(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// lwz r11,28(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8813c498
	if (ctx.cr6.eq) goto loc_8813C498;
loc_8813C480:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8813c6b8
	if (ctx.cr6.eq) goto loc_8813C6B8;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813c480
	if (!ctx.cr6.eq) goto loc_8813C480;
loc_8813C498:
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
loc_8813C49C:
	// lbz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 4);
	// addi r9,r24,280
	ctx.r9.s64 = ctx.r24.s64 + 280;
	// lbz r8,3(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 3);
	// rotlwi r7,r10,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// rotlwi r10,r8,3
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 3);
	// lwzx r9,r7,r9
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// stw r30,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r30.u32);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r6,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r6.u32);
	// lwz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r5,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r5.u32);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r4,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r4.u32);
	// lwz r3,4(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r3,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r3.u32);
	// lwz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// stw r10,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r10.u32);
	// stw r28,40(r11)
	PPC_STORE_U32(ctx.r11.u32 + 40, ctx.r28.u32);
loc_8813C4E8:
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8813c6ac
	if (ctx.cr6.eq) goto loc_8813C6AC;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r7,12(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// add r27,r9,r7
	ctx.r27.u64 = ctx.r9.u64 + ctx.r7.u64;
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r27,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r27.u32);
	// bne cr6,0x8813c534
	if (!ctx.cr6.eq) goto loc_8813C534;
	// subf r9,r11,r29
	ctx.r9.s64 = ctx.r29.s64 - ctx.r11.s64;
	// srawi r8,r9,3
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 3;
	// addze r9,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r9.s64 = temp.s64;
	// add r7,r9,r11
	ctx.r7.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stw r7,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r7.u32);
loc_8813C534:
	// lis r11,360
	ctx.r11.s64 = 23592960;
	// cmpw cr6,r27,r11
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x8813c6d0
	if (!ctx.cr6.lt) goto loc_8813C6D0;
	// lis r11,-40
	ctx.r11.s64 = -2621440;
	// cmpw cr6,r27,r11
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x8813c6d0
	if (!ctx.cr6.gt) goto loc_8813C6D0;
	// lwz r26,0(r30)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lis r9,280
	ctx.r9.s64 = 18350080;
	// cmpw cr6,r26,r9
	ctx.cr6.compare<int32_t>(ctx.r26.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x8813c6d0
	if (!ctx.cr6.lt) goto loc_8813C6D0;
	// cmpw cr6,r26,r11
	ctx.cr6.compare<int32_t>(ctx.r26.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x8813c6d0
	if (!ctx.cr6.gt) goto loc_8813C6D0;
	// lbz r11,112(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 112);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// stb r8,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r8.u8);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bge cr6,0x8813c5a0
	if (!ctx.cr6.lt) goto loc_8813C5A0;
	// lbz r11,110(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 110);
	// lbz r9,113(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 113);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// extsb r7,r8
	ctx.r7.s64 = ctx.r8.s8;
	// stb r9,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r9.u8);
	// cmpwi cr6,r7,3
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 3, ctx.xer);
	// stb r7,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r7.u8);
	// blt cr6,0x8813c5a0
	if (ctx.cr6.lt) goto loc_8813C5A0;
	// stb r28,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r28.u8);
loc_8813C5A0:
	// addi r11,r10,4
	ctx.r11.s64 = ctx.r10.s64 + 4;
	// lwz r10,120(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// lis r9,-30671
	ctx.r9.s64 = -2010054656;
	// lbz r8,110(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 110);
	// srawi r7,r11,3
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7) != 0);
	ctx.r7.s64 = ctx.r11.s32 >> 3;
	// addi r29,r9,3944
	ctx.r29.s64 = ctx.r9.s64 + 3944;
	// rlwinm r28,r7,1,25,30
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0x7E;
	// rlwinm r3,r10,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r30,r28,1,0,30
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r4,r24,-8
	ctx.r4.s64 = ctx.r24.s64 + -8;
	// extsb r10,r8
	ctx.r10.s64 = ctx.r8.s8;
	// addi r7,r29,2
	ctx.r7.s64 = ctx.r29.s64 + 2;
	// li r6,150
	ctx.r6.s64 = 150;
	// lhzx r11,r30,r29
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + ctx.r29.u32);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// lhzx r9,r3,r4
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + ctx.r4.u32);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// rotlwi r8,r11,1
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// lhzx r25,r30,r7
	ctx.r25.u64 = PPC_LOAD_U16(ctx.r30.u32 + ctx.r7.u32);
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x8813C5FC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813c614
	if (ctx.cr6.eq) goto loc_8813C614;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r25,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_8813C614:
	// srawi r11,r28,1
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r28.s32 >> 1;
	// lwz r10,120(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// lis r8,-30714
	ctx.r8.s64 = -2012872704;
	// lhzx r9,r30,r29
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r30.u32 + ctx.r29.u32);
	// addze r7,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r7.s64 = temp.s64;
	// rlwinm r5,r10,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r11,r7,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r4,r8,9552
	ctx.r4.s64 = ctx.r8.s64 + 9552;
	// addi r3,r11,-256
	ctx.r3.s64 = ctx.r11.s64 + -256;
	// li r6,150
	ctx.r6.s64 = 150;
	// clrlwi r11,r3,23
	ctx.r11.u64 = ctx.r3.u32 & 0x1FF;
	// lhzx r10,r5,r24
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r5.u32 + ctx.r24.u32);
	// addi r8,r11,128
	ctx.r8.s64 = ctx.r11.s64 + 128;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r5,r8,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x7FC;
	// add r3,r10,r9
	ctx.r3.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwzx r11,r7,r4
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r4.u32);
	// lwzx r9,r5,r4
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r4.u32);
	// rlwinm r10,r11,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r11,r9,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// add r4,r10,r26
	ctx.r4.u64 = ctx.r10.u64 + ctx.r26.u64;
	// add r5,r11,r27
	ctx.r5.u64 = ctx.r11.u64 + ctx.r27.u64;
	// bl 0x881538c0
	ctx.lr = 0x8813C670;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813c6ac
	if (ctx.cr6.eq) goto loc_8813C6AC;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// rlwinm r8,r25,26,0,5
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 26) & 0xFC000000;
	// lis r7,64
	ctx.r7.s64 = 4194304;
	// or r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 | ctx.r9.u64;
	// ori r5,r7,32864
	ctx.r5.u64 = ctx.r7.u64 | 32864;
	// lwz r11,-11932(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11932);
	// oris r4,r6,545
	ctx.r4.u64 = ctx.r6.u64 | 35717120;
	// stw r5,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r5.u32);
	// ori r4,r4,49152
	ctx.r4.u64 = ctx.r4.u64 | 49152;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stw r11,-11932(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11932, ctx.r11.u32);
loc_8813C6AC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
loc_8813C6B8:
	// lwz r10,24(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8813c6c8
	if (ctx.cr6.eq) goto loc_8813C6C8;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_8813C6C8:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x8813c49c
	goto loc_8813C49C;
loc_8813C6D0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8813C6DC"))) PPC_WEAK_FUNC(sub_8813C6DC);
PPC_FUNC_IMPL(__imp__sub_8813C6DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8813C6E0"))) PPC_WEAK_FUNC(sub_8813C6E0);
PPC_FUNC_IMPL(__imp__sub_8813C6E0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,40(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 40);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8813c71c
	if (!ctx.cr6.eq) goto loc_8813C71C;
	// lwz r11,136(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 136);
	// lwz r5,12(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r3,100(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// bl 0x88147d38
	ctx.lr = 0x8813C71C;
	sub_88147D38(ctx, base);
loc_8813C71C:
	// lbz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x8813c790
	if (!ctx.cr6.eq) goto loc_8813C790;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lbz r5,4(r31)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r31.u32 + 4);
	// lwz r4,100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// bl 0x88147a30
	ctx.lr = 0x8813C738;
	sub_88147A30(ctx, base);
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// subf. r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r9,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r9.u32);
	// bgt 0x8813c790
	if (ctx.cr0.gt) goto loc_8813C790;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8813c77c
	if (ctx.cr6.eq) goto loc_8813C77C;
loc_8813C764:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8813c77c
	if (ctx.cr6.eq) goto loc_8813C77C;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813c764
	if (!ctx.cr6.eq) goto loc_8813C764;
loc_8813C77C:
	// lis r10,-30700
	ctx.r10.s64 = -2011955200;
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// stb r9,2(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2, ctx.r9.u8);
	// addi r9,r10,-16272
	ctx.r9.s64 = ctx.r10.s64 + -16272;
	// stw r9,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r9.u32);
loc_8813C790:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813C7AC"))) PPC_WEAK_FUNC(sub_8813C7AC);
PPC_FUNC_IMPL(__imp__sub_8813C7AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8813C7B0"))) PPC_WEAK_FUNC(sub_8813C7B0);
PPC_FUNC_IMPL(__imp__sub_8813C7B0) {
	PPC_FUNC_PROLOGUE();
	// lwz r8,128(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r10,28(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8813c7e0
	if (ctx.cr6.eq) goto loc_8813C7E0;
loc_8813C7C8:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8813c868
	if (ctx.cr6.eq) goto loc_8813C868;
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8813c7c8
	if (!ctx.cr6.eq) goto loc_8813C7C8;
loc_8813C7E0:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8813C7E4:
	// li r9,25
	ctx.r9.s64 = 25;
	// addi r8,r11,32
	ctx.r8.s64 = ctx.r11.s64 + 32;
	// lis r6,-30671
	ctx.r6.s64 = -2010054656;
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r9,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r9.u32);
	// stw r9,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r9.u32);
	// addi r4,r6,-20888
	ctx.r4.s64 = ctx.r6.s64 + -20888;
	// stw r9,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r9.u32);
	// lis r5,-30700
	ctx.r5.s64 = -2011955200;
	// stw r8,36(r10)
	PPC_STORE_U32(ctx.r10.u32 + 36, ctx.r8.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r6,88(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// addi r8,r5,-15472
	ctx.r8.s64 = ctx.r5.s64 + -15472;
	// stw r6,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r6.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r7,40(r10)
	PPC_STORE_U32(ctx.r10.u32 + 40, ctx.r7.u32);
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 128);
	// stw r7,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r7.u32);
	// lbz r9,114(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 114);
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r10,120(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 120);
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// extsb r9,r9
	ctx.r9.s64 = ctx.r9.s8;
	// stb r5,2(r11)
	PPC_STORE_U8(ctx.r11.u32 + 2, ctx.r5.u8);
	// stw r8,140(r11)
	PPC_STORE_U32(ctx.r11.u32 + 140, ctx.r8.u32);
	// stw r6,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r6.u32);
	// stw r7,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r7.u32);
	// lhzx r10,r10,r4
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r4.u32);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// sth r9,56(r11)
	PPC_STORE_U16(ctx.r11.u32 + 56, ctx.r9.u16);
	// blr 
	return;
loc_8813C868:
	// lwz r9,24(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8813c878
	if (ctx.cr6.eq) goto loc_8813C878;
	// stw r9,64(r10)
	PPC_STORE_U32(ctx.r10.u32 + 64, ctx.r9.u32);
loc_8813C878:
	// addi r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 + 24;
	// b 0x8813c7e4
	goto loc_8813C7E4;
}

__attribute__((alias("__imp__sub_8813C880"))) PPC_WEAK_FUNC(sub_8813C880);
PPC_FUNC_IMPL(__imp__sub_8813C880) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071120
	ctx.lr = 0x8813C888;
	__savegprlr_14(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// lhz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lhz r7,8(r3)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// addi r16,r11,-20488
	ctx.r16.s64 = ctx.r11.s64 + -20488;
	// extsh r6,r9
	ctx.r6.s64 = ctx.r9.s16;
	// addi r4,r16,-8
	ctx.r4.s64 = ctx.r16.s64 + -8;
	// lbz r3,1(r10)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// extsh r14,r7
	ctx.r14.s64 = ctx.r7.s16;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// extsb r29,r3
	ctx.r29.s64 = ctx.r3.s8;
	// lis r8,-30648
	ctx.r8.s64 = -2008547328;
	// rlwinm r11,r29,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lbzx r7,r6,r4
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r4.u32);
	// addi r9,r16,-40
	ctx.r9.s64 = ctx.r16.s64 + -40;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// add r6,r11,r14
	ctx.r6.u64 = ctx.r11.u64 + ctx.r14.u64;
	// extsb r15,r7
	ctx.r15.s64 = ctx.r7.s8;
	// mulli r10,r6,2648
	ctx.r10.s64 = ctx.r6.s64 * 2648;
	// lwzx r31,r5,r9
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r9.u32);
	// li r19,0
	ctx.r19.s64 = 0;
	// addi r11,r8,13904
	ctx.r11.s64 = ctx.r8.s64 + 13904;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// add r28,r10,r11
	ctx.r28.u64 = ctx.r10.u64 + ctx.r11.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// cmpwi cr6,r15,0
	ctx.cr6.compare<int32_t>(ctx.r15.s32, 0, ctx.xer);
	// ble cr6,0x8813c918
	if (!ctx.cr6.gt) goto loc_8813C918;
	// addi r11,r1,76
	ctx.r11.s64 = ctx.r1.s64 + 76;
	// li r10,-1
	ctx.r10.s64 = -1;
	// cmplwi cr6,r15,0
	ctx.cr6.compare<uint32_t>(ctx.r15.u32, 0, ctx.xer);
	// beq cr6,0x8813c918
	if (ctx.cr6.eq) goto loc_8813C918;
	// mtctr r15
	ctx.ctr.u64 = ctx.r15.u64;
loc_8813C910:
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8813c910
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8813C910;
loc_8813C918:
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// addi r10,r11,26432
	ctx.r10.s64 = ctx.r11.s64 + 26432;
	// addi r9,r31,2
	ctx.r9.s64 = ctx.r31.s64 + 2;
	// mr r8,r28
	ctx.r8.u64 = ctx.r28.u64;
	// lwz r4,324(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 324);
loc_8813C930:
	// lwz r11,2628(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 2628);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,2628(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2628, ctx.r11.u32);
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// blt cr6,0x8813c948
	if (ctx.cr6.lt) goto loc_8813C948;
	// stw r19,2628(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2628, ctx.r19.u32);
loc_8813C948:
	// lwz r10,2628(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 2628);
	// mulli r11,r10,164
	ctx.r11.s64 = ctx.r10.s64 * 164;
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// lbz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813c9a4
	if (!ctx.cr6.eq) goto loc_8813C9A4;
	// lhz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 0);
	// cmpwi cr6,r4,2
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 2, ctx.xer);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// bne cr6,0x8813c97c
	if (!ctx.cr6.eq) goto loc_8813C97C;
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// blt cr6,0x8813c97c
	if (ctx.cr6.lt) goto loc_8813C97C;
	// li r11,8
	ctx.r11.s64 = 8;
loc_8813C97C:
	// lwz r27,0(r8)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmpw cr6,r27,r11
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x8813c98c
	if (!ctx.cr6.lt) goto loc_8813C98C;
	// stw r10,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r10.u32);
loc_8813C98C:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmpw cr6,r7,r15
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r15.s32, ctx.xer);
	// bge cr6,0x8813c9b0
	if (!ctx.cr6.lt) goto loc_8813C9B0;
loc_8813C9A4:
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// cmpwi cr6,r3,16
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 16, ctx.xer);
	// blt cr6,0x8813c930
	if (ctx.cr6.lt) goto loc_8813C930;
loc_8813C9B0:
	// lwz r11,2636(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 2636);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,2636(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2636, ctx.r11.u32);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// blt cr6,0x8813c9c8
	if (ctx.cr6.lt) goto loc_8813C9C8;
	// stw r19,2636(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2636, ctx.r19.u32);
loc_8813C9C8:
	// lwz r11,2640(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 2640);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,2640(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2640, ctx.r11.u32);
	// cmpwi cr6,r11,14
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 14, ctx.xer);
	// blt cr6,0x8813c9e0
	if (ctx.cr6.lt) goto loc_8813C9E0;
	// stw r19,2640(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2640, ctx.r19.u32);
loc_8813C9E0:
	// addi r11,r16,-256
	ctx.r11.s64 = ctx.r16.s64 + -256;
	// addi r10,r16,-200
	ctx.r10.s64 = ctx.r16.s64 + -200;
	// addi r9,r16,-352
	ctx.r9.s64 = ctx.r16.s64 + -352;
	// mr r22,r31
	ctx.r22.u64 = ctx.r31.u64;
	// addi r20,r1,80
	ctx.r20.s64 = ctx.r1.s64 + 80;
	// lwzx r24,r5,r11
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r11.u32);
	// mr r26,r19
	ctx.r26.u64 = ctx.r19.u64;
	// lwzx r27,r5,r10
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r10.u32);
	// cmpwi cr6,r15,0
	ctx.cr6.compare<int32_t>(ctx.r15.s32, 0, ctx.xer);
	// lwzx r23,r5,r9
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r9.u32);
	// ble cr6,0x8813cc98
	if (!ctx.cr6.gt) goto loc_8813CC98;
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// addi r29,r28,2632
	ctx.r29.s64 = ctx.r28.s64 + 2632;
	// li r17,2
	ctx.r17.s64 = 2;
	// li r21,1
	ctx.r21.s64 = 1;
	// li r18,5
	ctx.r18.s64 = 5;
	// addi r25,r11,9552
	ctx.r25.s64 = ctx.r11.s64 + 9552;
loc_8813CA24:
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x8813cc70
	if (ctx.cr6.lt) goto loc_8813CC70;
	// mulli r11,r11,164
	ctx.r11.s64 = ctx.r11.s64 * 164;
	// lwz r10,32(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// addi r31,r11,4
	ctx.r31.s64 = ctx.r11.s64 + 4;
	// stb r26,7(r11)
	PPC_STORE_U8(ctx.r11.u32 + 7, ctx.r26.u8);
	// stw r14,160(r11)
	PPC_STORE_U32(ctx.r11.u32 + 160, ctx.r14.u32);
	// stw r10,140(r11)
	PPC_STORE_U32(ctx.r11.u32 + 140, ctx.r10.u32);
	// lwz r11,-2632(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -2632);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-2632(r29)
	PPC_STORE_U32(ctx.r29.u32 + -2632, ctx.r11.u32);
	// lwz r11,2644(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 2644);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// stw r8,2644(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2644, ctx.r8.u32);
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// blt cr6,0x8813ca7c
	if (ctx.cr6.lt) goto loc_8813CA7C;
	// stw r19,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r19.u32);
loc_8813CA7C:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r6,28(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	// stb r11,114(r31)
	PPC_STORE_U8(ctx.r31.u32 + 114, ctx.r11.u8);
	// cmpwi cr6,r6,2
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 2, ctx.xer);
	// lwz r5,2636(r28)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r28.u32 + 2636);
	// stb r5,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r5.u8);
	// lwz r3,2640(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 2640);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r16
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r16.u32);
	// stb r17,113(r31)
	PPC_STORE_U8(ctx.r31.u32 + 113, ctx.r17.u8);
	// stb r9,111(r31)
	PPC_STORE_U8(ctx.r31.u32 + 111, ctx.r9.u8);
	// stb r19,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r19.u8);
	// lwz r5,0(r23)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r23.u32 + 0);
	// stw r5,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r5.u32);
	// lwz r4,4(r23)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r23.u32 + 4);
	// stb r21,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r21.u8);
	// stb r7,1(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1, ctx.r7.u8);
	// stw r10,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r10.u32);
	// stw r4,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r4.u32);
	// bne cr6,0x8813cae4
	if (!ctx.cr6.eq) goto loc_8813CAE4;
	// lwz r10,20(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// stw r10,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r10.u32);
	// b 0x8813cb6c
	goto loc_8813CB6C;
loc_8813CAE4:
	// lhz r11,6(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + 6);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// extsh r9,r11
	ctx.r9.s64 = ctx.r11.s16;
	// lwz r5,4(r27)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// srawi r4,r10,8
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xFF) != 0);
	ctx.r4.s64 = ctx.r10.s32 >> 8;
	// lwz r7,20(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// neg r3,r9
	ctx.r3.s64 = -ctx.r9.s64;
	// lwz r8,16(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// addze r11,r4
	temp.s64 = ctx.r4.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r11.s64 = temp.s64;
	// clrlwi r10,r3,23
	ctx.r10.u64 = ctx.r3.u32 & 0x1FF;
	// srawi r9,r5,8
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xFF) != 0);
	ctx.r9.s64 = ctx.r5.s32 >> 8;
	// addi r5,r10,128
	ctx.r5.s64 = ctx.r10.s64 + 128;
	// rlwinm r4,r10,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r3,r5,2,21,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x7FC;
	// addze r10,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r10.s64 = temp.s64;
	// lwzx r9,r4,r25
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r25.u32);
	// lwzx r5,r3,r25
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r25.u32);
	// rlwinm r4,r9,4,0,27
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r3,r5,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// mullw r5,r10,r4
	ctx.r5.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r4.s32);
	// mullw r9,r11,r3
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r3.s32);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// mullw r9,r11,r4
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r4.s32);
	// mullw r11,r10,r3
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r3.s32);
	// lwz r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// subf r5,r5,r4
	ctx.r5.s64 = ctx.r4.s64 - ctx.r5.s64;
	// add r3,r9,r11
	ctx.r3.u64 = ctx.r9.u64 + ctx.r11.u64;
	// srawi r4,r5,8
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xFF) != 0);
	ctx.r4.s64 = ctx.r5.s32 >> 8;
	// addze r11,r4
	temp.s64 = ctx.r4.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r11.s64 = temp.s64;
	// srawi r10,r3,8
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFF) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 8;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// addze r10,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r10.s64 = temp.s64;
	// add r9,r10,r7
	ctx.r9.u64 = ctx.r10.u64 + ctx.r7.u64;
	// stw r9,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r9.u32);
loc_8813CB6C:
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// cmpwi cr6,r6,1
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 1, ctx.xer);
	// lhz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4);
	// lhz r10,6(r30)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r30.u32 + 6);
	// clrlwi r11,r10,23
	ctx.r11.u64 = ctx.r10.u32 & 0x1FF;
	// stb r9,4(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4, ctx.r9.u8);
	// lhz r8,0(r22)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r22.u32 + 0);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// stw r11,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// stw r7,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r7.u32);
	// lwz r6,0(r24)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// divwu r5,r6,r18
	ctx.r5.u32 = ppc_divwu(ctx.r6.u32, ctx.r18.u32);
	// stw r5,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r5.u32);
	// lwz r4,0(r24)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// divwu r3,r4,r18
	ctx.r3.u32 = ppc_divwu(ctx.r4.u32, ctx.r18.u32);
	// stw r19,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r19.u32);
	// stw r3,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r3.u32);
	// bne cr6,0x8813cbc8
	if (!ctx.cr6.eq) goto loc_8813CBC8;
	// lwz r10,0(r24)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// stw r10,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r10.u32);
	// lwz r9,0(r24)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// stw r21,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r21.u32);
	// stw r9,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r9.u32);
loc_8813CBC8:
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// addic. r10,r31,20
	ctx.xer.ca = ctx.r31.u32 > 4294967275;
	ctx.r10.s64 = ctx.r31.s64 + 20;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r8,r31,16
	ctx.r8.s64 = ctx.r31.s64 + 16;
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// beq 0x8813cbf0
	if (ctx.cr0.eq) goto loc_8813CBF0;
	// addi r7,r11,128
	ctx.r7.s64 = ctx.r11.s64 + 128;
	// rlwinm r6,r7,2,21,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x7FC;
	// lwzx r5,r6,r25
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r25.u32);
	// mullw r4,r5,r9
	ctx.r4.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r9.s32);
	// stw r4,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
loc_8813CBF0:
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8813cc08
	if (ctx.cr6.eq) goto loc_8813CC08;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r25
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// mullw r9,r10,r9
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// stw r9,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
loc_8813CC08:
	// lbz r11,1(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r4,r11,4
	ctx.r4.s64 = ctx.r11.s64 + 4;
	// bl 0x881556a0
	ctx.lr = 0x8813CC18;
	sub_881556A0(ctx, base);
	// stw r3,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r3.u32);
	// mr r10,r19
	ctx.r10.u64 = ctx.r19.u64;
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8813cc44
	if (ctx.cr6.eq) goto loc_8813CC44;
loc_8813CC2C:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8813ccec
	if (ctx.cr6.eq) goto loc_8813CCEC;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813cc2c
	if (!ctx.cr6.eq) goto loc_8813CC2C;
loc_8813CC44:
	// mr r11,r19
	ctx.r11.u64 = ctx.r19.u64;
loc_8813CC48:
	// stw r21,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r21.u32);
	// lis r11,-30700
	ctx.r11.s64 = -2011955200;
	// lis r10,-30700
	ctx.r10.s64 = -2011955200;
	// lwz r7,128(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// addi r9,r11,-14624
	ctx.r9.s64 = ctx.r11.s64 + -14624;
	// stw r31,36(r7)
	PPC_STORE_U32(ctx.r7.u32 + 36, ctx.r31.u32);
	// addi r8,r10,-14416
	ctx.r8.s64 = ctx.r10.s64 + -14416;
	// stw r9,32(r7)
	PPC_STORE_U32(ctx.r7.u32 + 32, ctx.r9.u32);
	// stb r19,2(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2, ctx.r19.u8);
	// stw r8,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r8.u32);
loc_8813CC70:
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// addi r24,r24,8
	ctx.r24.s64 = ctx.r24.s64 + 8;
	// addi r27,r27,12
	ctx.r27.s64 = ctx.r27.s64 + 12;
	// addi r23,r23,8
	ctx.r23.s64 = ctx.r23.s64 + 8;
	// addi r22,r22,4
	ctx.r22.s64 = ctx.r22.s64 + 4;
	// addi r20,r20,4
	ctx.r20.s64 = ctx.r20.s64 + 4;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// cmpw cr6,r26,r15
	ctx.cr6.compare<int32_t>(ctx.r26.s32, ctx.r15.s32, ctx.xer);
	// blt cr6,0x8813ca24
	if (ctx.cr6.lt) goto loc_8813CA24;
	// lwz r29,84(r1)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_8813CC98:
	// lwz r11,28(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8813cce0
	if (!ctx.cr6.eq) goto loc_8813CCE0;
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// addi r11,r11,-19568
	ctx.r11.s64 = ctx.r11.s64 + -19568;
	// lwz r10,-4596(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -4596);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8813cce0
	if (!ctx.cr6.eq) goto loc_8813CCE0;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8813cce0
	if (!ctx.cr6.eq) goto loc_8813CCE0;
	// li r10,3
	ctx.r10.s64 = 3;
	// li r6,16
	ctx.r6.s64 = 16;
	// li r5,20
	ctx.r5.s64 = 20;
	// stw r10,-4596(r11)
	PPC_STORE_U32(ctx.r11.u32 + -4596, ctx.r10.u32);
	// li r4,77
	ctx.r4.s64 = 77;
	// addi r3,r29,3
	ctx.r3.s64 = ctx.r29.s64 + 3;
	// bl 0x880e3240
	ctx.lr = 0x8813CCE0;
	sub_880E3240(ctx, base);
loc_8813CCE0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
loc_8813CCEC:
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8813ccfc
	if (ctx.cr6.eq) goto loc_8813CCFC;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_8813CCFC:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x8813cc48
	goto loc_8813CC48;
}

__attribute__((alias("__imp__sub_8813CD04"))) PPC_WEAK_FUNC(sub_8813CD04);
PPC_FUNC_IMPL(__imp__sub_8813CD04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8813CD08"))) PPC_WEAK_FUNC(sub_8813CD08);
PPC_FUNC_IMPL(__imp__sub_8813CD08) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813CD0C"))) PPC_WEAK_FUNC(sub_8813CD0C);
PPC_FUNC_IMPL(__imp__sub_8813CD0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8813CD10"))) PPC_WEAK_FUNC(sub_8813CD10);
PPC_FUNC_IMPL(__imp__sub_8813CD10) {
	PPC_FUNC_PROLOGUE();
	// lwz r9,128(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r8,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r8.u8);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// addi r11,r11,576
	ctx.r11.s64 = ctx.r11.s64 + 576;
	// lwz r10,-104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -104);
	// cmpwi cr6,r10,3000
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3000, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r8.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,-104(r11)
	PPC_STORE_U32(ctx.r11.u32 + -104, ctx.r10.u32);
	// stwx r9,r7,r11
	PPC_STORE_U32(ctx.r7.u32 + ctx.r11.u32, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813CD50"))) PPC_WEAK_FUNC(sub_8813CD50);
PPC_FUNC_IMPL(__imp__sub_8813CD50) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30648
	ctx.r11.s64 = -2008547328;
	// li r5,19792
	ctx.r5.s64 = 19792;
	// addi r31,r11,-5888
	ctx.r31.s64 = ctx.r11.s64 + -5888;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x8813CD78;
	sub_88073BD0(ctx, base);
	// lis r7,-30671
	ctx.r7.s64 = -2010054656;
	// lis r10,-21846
	ctx.r10.s64 = -1431699456;
	// lis r11,16838
	ctx.r11.s64 = 1103495168;
	// ori r6,r10,43691
	ctx.r6.u64 = ctx.r10.u64 | 43691;
	// addi r4,r31,9864
	ctx.r4.s64 = ctx.r31.s64 + 9864;
	// lwz r10,4200(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4200);
	// ori r5,r11,20077
	ctx.r5.u64 = ctx.r11.u64 | 20077;
loc_8813CD94:
	// li r11,5
	ctx.r11.s64 = 5;
	// addi r9,r4,-4
	ctx.r9.s64 = ctx.r4.s64 + -4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8813CDA0:
	// mullw r11,r10,r5
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r5.s32);
	// addi r10,r11,12345
	ctx.r10.s64 = ctx.r11.s64 + 12345;
	// stw r10,4200(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4200, ctx.r10.u32);
	// lhz r3,4200(r7)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r7.u32 + 4200);
	// mulhwu r11,r3,r6
	ctx.r11.u64 = (uint64_t(ctx.r3.u32) * uint64_t(ctx.r6.u32)) >> 32;
	// rlwinm r11,r11,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// subf r3,r8,r3
	ctx.r3.s64 = ctx.r3.s64 - ctx.r8.s64;
	// extsh r8,r3
	ctx.r8.s64 = ctx.r3.s16;
	// stwu r8,4(r9)
	ea = 4 + ctx.r9.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x8813cda0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8813CDA0;
	// addi r4,r4,9896
	ctx.r4.s64 = ctx.r4.s64 + 9896;
	// addi r11,r31,29656
	ctx.r11.s64 = ctx.r31.s64 + 29656;
	// cmpw cr6,r4,r11
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8813cd94
	if (ctx.cr6.lt) goto loc_8813CD94;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813CDF4"))) PPC_WEAK_FUNC(sub_8813CDF4);
PPC_FUNC_IMPL(__imp__sub_8813CDF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8813CDF8"))) PPC_WEAK_FUNC(sub_8813CDF8);
PPC_FUNC_IMPL(__imp__sub_8813CDF8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x8813CE00;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30648
	ctx.r11.s64 = -2008547328;
	// li r26,2
	ctx.r26.s64 = 2;
	// addi r30,r11,-5888
	ctx.r30.s64 = ctx.r11.s64 + -5888;
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r29,r11,576
	ctx.r29.s64 = ctx.r11.s64 + 576;
loc_8813CE1C:
	// lwz r11,9892(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 9892);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8813cecc
	if (ctx.cr6.eq) goto loc_8813CECC;
	// addi r31,r30,20
	ctx.r31.s64 = ctx.r30.s64 + 20;
	// li r27,60
	ctx.r27.s64 = 60;
loc_8813CE30:
	// lbz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8813cec0
	if (ctx.cr6.eq) goto loc_8813CEC0;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bgt cr6,0x8813ce58
	if (ctx.cr6.gt) goto loc_8813CE58;
	// lwz r11,140(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8813CE58;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8813CE58:
	// lwz r11,140(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8813CE68;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8813cec0
	if (!ctx.cr6.eq) goto loc_8813CEC0;
	// lwz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// stb r28,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r28.u8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8813cea0
	if (ctx.cr6.eq) goto loc_8813CEA0;
	// lwz r11,-104(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -104);
	// cmpwi cr6,r11,3000
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3000, ctx.xer);
	// bge cr6,0x8813cea0
	if (!ctx.cr6.lt) goto loc_8813CEA0;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r28,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r28.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-104(r29)
	PPC_STORE_U32(ctx.r29.u32 + -104, ctx.r11.u32);
	// stwx r10,r9,r29
	PPC_STORE_U32(ctx.r9.u32 + ctx.r29.u32, ctx.r10.u32);
loc_8813CEA0:
	// lbz r11,3(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 3);
	// rotlwi r11,r11,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// lwzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r30.u32);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stwx r10,r11,r30
	PPC_STORE_U32(ctx.r11.u32 + ctx.r30.u32, ctx.r10.u32);
	// lwz r11,9892(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 9892);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// stw r9,9892(r30)
	PPC_STORE_U32(ctx.r30.u32 + 9892, ctx.r9.u32);
loc_8813CEC0:
	// addi r31,r31,164
	ctx.r31.s64 = ctx.r31.s64 + 164;
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// bne 0x8813ce30
	if (!ctx.cr0.eq) goto loc_8813CE30;
loc_8813CECC:
	// addi r30,r30,9896
	ctx.r30.s64 = ctx.r30.s64 + 9896;
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne 0x8813ce1c
	if (!ctx.cr0.eq) goto loc_8813CE1C;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8813CEE0"))) PPC_WEAK_FUNC(sub_8813CEE0);
PPC_FUNC_IMPL(__imp__sub_8813CEE0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x8813CEE8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,76(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmpwi cr6,r11,256
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 256, ctx.xer);
	// blt cr6,0x8813cf04
	if (ctx.cr6.lt) goto loc_8813CF04;
	// li r29,1
	ctx.r29.s64 = 1;
loc_8813CF04:
	// lwz r28,32(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r6,151
	ctx.r6.s64 = 151;
	// lwz r27,36(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lhz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r31.u32 + 56);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// bl 0x881538c0
	ctx.lr = 0x8813CF20;
	sub_881538C0(ctx, base);
	// lis r30,-30597
	ctx.r30.s64 = -2005204992;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813cf60
	if (ctx.cr6.eq) goto loc_8813CF60;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r29,26,0,5
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 26) & 0xFC000000;
	// lwz r11,-11932(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -11932);
	// lis r8,128
	ctx.r8.s64 = 8388608;
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// ori r6,r8,32896
	ctx.r6.u64 = ctx.r8.u64 | 32896;
	// oris r5,r7,531
	ctx.r5.u64 = ctx.r7.u64 | 34799616;
	// addi r29,r11,1
	ctx.r29.s64 = ctx.r11.s64 + 1;
	// stw r6,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r6.u32);
	// ori r5,r5,32768
	ctx.r5.u64 = ctx.r5.u64 | 32768;
	// stw r29,-11932(r30)
	PPC_STORE_U32(ctx.r30.u32 + -11932, ctx.r29.u32);
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// b 0x8813cf64
	goto loc_8813CF64;
loc_8813CF60:
	// lwz r29,-11932(r30)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r30.u32 + -11932);
loc_8813CF64:
	// lbz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 4);
	// li r6,151
	ctx.r6.s64 = 151;
	// addis r5,r27,-2
	ctx.r5.s64 = ctx.r27.s64 + -131072;
	// rotlwi r11,r11,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r11,397
	ctx.r3.s64 = ctx.r11.s64 + 397;
	// bl 0x881538c0
	ctx.lr = 0x8813CF80;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813cfac
	if (ctx.cr6.eq) goto loc_8813CFAC;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,16
	ctx.r9.s64 = 1048576;
	// addi r11,r29,1
	ctx.r11.s64 = ctx.r29.s64 + 1;
	// oris r7,r10,545
	ctx.r7.u64 = ctx.r10.u64 | 35717120;
	// ori r8,r9,24704
	ctx.r8.u64 = ctx.r9.u64 | 24704;
	// stw r11,-11932(r30)
	PPC_STORE_U32(ctx.r30.u32 + -11932, ctx.r11.u32);
	// ori r7,r7,32768
	ctx.r7.u64 = ctx.r7.u64 | 32768;
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
loc_8813CFAC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8813CFB4"))) PPC_WEAK_FUNC(sub_8813CFB4);
PPC_FUNC_IMPL(__imp__sub_8813CFB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8813CFB8"))) PPC_WEAK_FUNC(sub_8813CFB8);
PPC_FUNC_IMPL(__imp__sub_8813CFB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071144
	ctx.lr = 0x8813CFC0;
	__savegprlr_23(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r10,2(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r11,4200
	ctx.r30.s64 = ctx.r11.s64 + 4200;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8813d1b0
	if (!ctx.cr6.eq) goto loc_8813D1B0;
	// lwz r9,128(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// lwz r8,28(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8813d008
	if (ctx.cr6.eq) goto loc_8813D008;
loc_8813CFF0:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8813d008
	if (ctx.cr6.eq) goto loc_8813D008;
	// lwz r8,0(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8813cff0
	if (!ctx.cr6.eq) goto loc_8813CFF0;
loc_8813D008:
	// lis r11,16838
	ctx.r11.s64 = 1103495168;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// lis r8,-13108
	ctx.r8.s64 = -859045888;
	// ori r11,r11,20077
	ctx.r11.u64 = ctx.r11.u64 | 20077;
	// ori r7,r8,52429
	ctx.r7.u64 = ctx.r8.u64 | 52429;
	// mullw r9,r9,r11
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// addi r9,r9,12345
	ctx.r9.s64 = ctx.r9.s64 + 12345;
	// lis r6,20971
	ctx.r6.s64 = 1374355456;
	// stw r9,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r9.u32);
	// mullw r9,r9,r11
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// lwz r8,68(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// lwz r5,76(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r9,r9,12345
	ctx.r9.s64 = ctx.r9.s64 + 12345;
	// srawi r29,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r29.s64 = ctx.r8.s32 >> 1;
	// mullw r8,r9,r11
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// lhz r28,0(r30)
	ctx.r28.u64 = PPC_LOAD_U16(ctx.r30.u32 + 0);
	// stw r9,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r9.u32);
	// mulhwu r7,r28,r7
	ctx.r7.u64 = (uint64_t(ctx.r28.u32) * uint64_t(ctx.r7.u32)) >> 32;
	// rlwinm r9,r7,29,3,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 29) & 0x1FFFFFFF;
	// addi r11,r8,12345
	ctx.r11.s64 = ctx.r8.s64 + 12345;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// li r27,1
	ctx.r27.s64 = 1;
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// lhz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r30.u32 + 0);
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// addze r11,r29
	temp.s64 = ctx.r29.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r29.u32;
	ctx.r11.s64 = temp.s64;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// stb r27,2(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2, ctx.r27.u8);
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// stw r11,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// ori r8,r6,34079
	ctx.r8.u64 = ctx.r6.u64 | 34079;
	// subf r6,r9,r28
	ctx.r6.s64 = ctx.r28.s64 - ctx.r9.s64;
	// mulhwu r29,r7,r8
	ctx.r29.u64 = (uint64_t(ctx.r7.u32) * uint64_t(ctx.r8.u32)) >> 32;
	// extsh r8,r6
	ctx.r8.s64 = ctx.r6.s16;
	// lhz r28,0(r30)
	ctx.r28.u64 = PPC_LOAD_U16(ctx.r30.u32 + 0);
	// lis r6,14563
	ctx.r6.s64 = 954400768;
	// addi r9,r8,-4
	ctx.r9.s64 = ctx.r8.s64 + -4;
	// rlwinm r8,r29,29,3,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 29) & 0x1FFFFFFF;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// ori r6,r6,36409
	ctx.r6.u64 = ctx.r6.u64 | 36409;
	// add r9,r9,r5
	ctx.r9.u64 = ctx.r9.u64 + ctx.r5.u64;
	// lis r29,-30667
	ctx.r29.s64 = -2009792512;
	// clrlwi r9,r9,23
	ctx.r9.u64 = ctx.r9.u32 & 0x1FF;
	// mulli r8,r8,25
	ctx.r8.s64 = ctx.r8.s64 * 25;
	// addi r25,r9,128
	ctx.r25.s64 = ctx.r9.s64 + 128;
	// rlwinm r24,r9,2,0,29
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// mulhwu r6,r28,r6
	ctx.r6.u64 = (uint64_t(ctx.r28.u32) * uint64_t(ctx.r6.u32)) >> 32;
	// lis r27,-30667
	ctx.r27.s64 = -2009792512;
	// li r9,1
	ctx.r9.s64 = 1;
	// lis r23,-30714
	ctx.r23.s64 = -2012872704;
	// subf r26,r8,r7
	ctx.r26.s64 = ctx.r7.s64 - ctx.r8.s64;
	// stw r9,12380(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12380, ctx.r9.u32);
	// rlwinm r8,r6,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 31) & 0x7FFFFFFF;
	// li r7,153
	ctx.r7.s64 = 153;
	// addi r6,r23,9552
	ctx.r6.s64 = ctx.r23.s64 + 9552;
	// rlwinm r29,r25,2,21,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 2) & 0x7FC;
	// stw r7,12376(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12376, ctx.r7.u32);
	// mr r7,r26
	ctx.r7.u64 = ctx.r26.u64;
	// lis r26,-30667
	ctx.r26.s64 = -2009792512;
	// rlwinm r9,r8,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r25,r24,r6
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r24.u32 + ctx.r6.u32);
	// extsh r7,r7
	ctx.r7.s64 = ctx.r7.s16;
	// lwzx r29,r29,r6
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r6.u32);
	// li r6,64
	ctx.r6.s64 = 64;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stb r10,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r10.u8);
	// lis r27,-30667
	ctx.r27.s64 = -2009792512;
	// stw r6,12384(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12384, ctx.r6.u32);
	// addi r8,r7,-12
	ctx.r8.s64 = ctx.r7.s64 + -12;
	// stb r10,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r10.u8);
	// li r7,3
	ctx.r7.s64 = 3;
	// stb r10,113(r31)
	PPC_STORE_U8(ctx.r31.u32 + 113, ctx.r10.u8);
	// subf r6,r9,r28
	ctx.r6.s64 = ctx.r28.s64 - ctx.r9.s64;
	// stb r7,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r7.u8);
	// rlwinm r9,r8,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// stw r5,12368(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12368, ctx.r5.u32);
	// rlwinm r8,r6,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// lis r7,-30667
	ctx.r7.s64 = -2009792512;
	// mullw r6,r25,r11
	ctx.r6.s64 = int64_t(ctx.r25.s32) * int64_t(ctx.r11.s32);
	// stw r6,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r6.u32);
	// mullw r11,r29,r11
	ctx.r11.s64 = int64_t(ctx.r29.s32) * int64_t(ctx.r11.s32);
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lis r28,-30667
	ctx.r28.s64 = -2009792512;
	// add r11,r9,r4
	ctx.r11.u64 = ctx.r9.u64 + ctx.r4.u64;
	// add r10,r8,r3
	ctx.r10.u64 = ctx.r8.u64 + ctx.r3.u64;
	// stw r11,12364(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12364, ctx.r11.u32);
	// li r6,64
	ctx.r6.s64 = 64;
	// li r4,153
	ctx.r4.s64 = 153;
	// stw r10,12372(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12372, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x880f83f8
	ctx.lr = 0x8813D180;
	sub_880F83F8(ctx, base);
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// lwz r10,-19568(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -19568);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8813d1b0
	if (!ctx.cr6.eq) goto loc_8813D1B0;
	// lbz r9,1(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// li r10,3
	ctx.r10.s64 = 3;
	// li r6,17
	ctx.r6.s64 = 17;
	// li r5,23
	ctx.r5.s64 = 23;
	// stw r10,-19568(r11)
	PPC_STORE_U32(ctx.r11.u32 + -19568, ctx.r10.u32);
	// li r4,76
	ctx.r4.s64 = 76;
	// addi r3,r9,3
	ctx.r3.s64 = ctx.r9.s64 + 3;
	// bl 0x880e3240
	ctx.lr = 0x8813D1B0;
	sub_880E3240(ctx, base);
loc_8813D1B0:
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r7,r30,-24632
	ctx.r7.s64 = ctx.r30.s64 + -24632;
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r6,152
	ctx.r6.s64 = 152;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// add r29,r11,r10
	ctx.r29.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r5,120(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// add r30,r9,r8
	ctx.r30.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lbz r4,110(r31)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r31.u32 + 110);
	// stw r29,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r29.u32);
	// rlwinm r3,r5,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r30,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
	// extsb r10,r4
	ctx.r10.s64 = ctx.r4.s8;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lhzx r11,r3,r7
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + ctx.r7.u32);
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x8813D1FC;
	sub_881538C0(ctx, base);
	// lis r28,-30597
	ctx.r28.s64 = -2005204992;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813d234
	if (ctx.cr6.eq) goto loc_8813D234;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,128
	ctx.r9.s64 = 8388608;
	// lwz r11,-11932(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -11932);
	// oris r7,r10,531
	ctx.r7.u64 = ctx.r10.u64 | 34799616;
	// ori r8,r9,32896
	ctx.r8.u64 = ctx.r9.u64 | 32896;
	// ori r7,r7,32768
	ctx.r7.u64 = ctx.r7.u64 | 32768;
	// addi r27,r11,1
	ctx.r27.s64 = ctx.r11.s64 + 1;
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r27,-11932(r28)
	PPC_STORE_U32(ctx.r28.u32 + -11932, ctx.r27.u32);
	// b 0x8813d238
	goto loc_8813D238;
loc_8813D234:
	// lwz r27,-11932(r28)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r28.u32 + -11932);
loc_8813D238:
	// lwz r11,120(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// li r6,152
	ctx.r6.s64 = 152;
	// addis r5,r29,-6
	ctx.r5.s64 = ctx.r29.s64 + -393216;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r11,401
	ctx.r3.s64 = ctx.r11.s64 + 401;
	// bl 0x881538c0
	ctx.lr = 0x8813D254;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813d280
	if (ctx.cr6.eq) goto loc_8813D280;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,32
	ctx.r9.s64 = 2097152;
	// addi r11,r27,1
	ctx.r11.s64 = ctx.r27.s64 + 1;
	// oris r7,r10,545
	ctx.r7.u64 = ctx.r10.u64 | 35717120;
	// ori r8,r9,16512
	ctx.r8.u64 = ctx.r9.u64 | 16512;
	// stw r11,-11932(r28)
	PPC_STORE_U32(ctx.r28.u32 + -11932, ctx.r11.u32);
	// ori r7,r7,32768
	ctx.r7.u64 = ctx.r7.u64 | 32768;
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
loc_8813D280:
	// lbz r11,112(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 112);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r9.u8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge cr6,0x8813d2bc
	if (!ctx.cr6.lt) goto loc_8813D2BC;
	// lbz r11,110(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 110);
	// li r3,0
	ctx.r3.s64 = 0;
	// lbz r10,113(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 113);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// stb r10,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r10.u8);
	// cmpwi cr6,r8,8
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 8, ctx.xer);
	// stb r8,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r8.u8);
	// bge cr6,0x8813d2c0
	if (!ctx.cr6.lt) goto loc_8813D2C0;
loc_8813D2BC:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8813D2C0:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8813D2C8"))) PPC_WEAK_FUNC(sub_8813D2C8);
PPC_FUNC_IMPL(__imp__sub_8813D2C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x8813D2D0;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r10,2(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r27,0
	ctx.r27.s64 = 0;
	// li r26,1
	ctx.r26.s64 = 1;
	// addi r29,r11,-20416
	ctx.r29.s64 = ctx.r11.s64 + -20416;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8813d3c4
	if (!ctx.cr6.eq) goto loc_8813D3C4;
	// lwz r9,128(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// lwz r11,28(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8813d320
	if (ctx.cr6.eq) goto loc_8813D320;
loc_8813D308:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8813d3ac
	if (ctx.cr6.eq) goto loc_8813D3AC;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813d308
	if (!ctx.cr6.eq) goto loc_8813D308;
loc_8813D320:
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
loc_8813D324:
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8813d350
	if (ctx.cr6.eq) goto loc_8813D350;
loc_8813D338:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8813d350
	if (ctx.cr6.eq) goto loc_8813D350;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813d338
	if (!ctx.cr6.eq) goto loc_8813D338;
loc_8813D350:
	// stw r26,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r26.u32);
	// addi r9,r29,1112
	ctx.r9.s64 = ctx.r29.s64 + 1112;
	// lbz r7,3(r31)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r31.u32 + 3);
	// li r8,2
	ctx.r8.s64 = 2;
	// lbz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r31.u32 + 4);
	// rotlwi r5,r6,2
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r6.u32, 2);
	// rotlwi r11,r7,3
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 3);
	// lwzx r9,r5,r9
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r9.u32);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r4,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r4.u32);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r3,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r3.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r9.u32);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r7.u32);
	// lwz r6,92(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// stw r6,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r6.u32);
	// stb r26,2(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2, ctx.r26.u8);
	// stb r8,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r8.u8);
	// stb r8,5(r31)
	PPC_STORE_U8(ctx.r31.u32 + 5, ctx.r8.u8);
	// b 0x8813d3e4
	goto loc_8813D3E4;
loc_8813D3AC:
	// lwz r10,24(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8813d3bc
	if (ctx.cr6.eq) goto loc_8813D3BC;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_8813D3BC:
	// addi r10,r11,24
	ctx.r10.s64 = ctx.r11.s64 + 24;
	// b 0x8813d324
	goto loc_8813D324;
loc_8813D3C4:
	// lbz r11,1(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// lis r9,-30651
	ctx.r9.s64 = -2008743936;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r8,r9,-8560
	ctx.r8.s64 = ctx.r9.s64 + -8560;
	// rotlwi r7,r11,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// lwzx r11,r7,r8
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r6,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
loc_8813D3E4:
	// lbz r11,5(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 5);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8813d424
	if (ctx.cr6.eq) goto loc_8813D424;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x8813d410
	if (ctx.cr6.eq) goto loc_8813D410;
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r11,72(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 72);
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r10,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r10.u32);
loc_8813D410:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8813cee0
	ctx.lr = 0x8813D418;
	sub_8813CEE0(ctx, base);
	// lbz r11,5(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 5);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// stb r10,5(r31)
	PPC_STORE_U8(ctx.r31.u32 + 5, ctx.r10.u8);
loc_8813D424:
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r7,360
	ctx.r7.s64 = 23592960;
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r6,100(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r30,r10,r9
	ctx.r30.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmpw cr6,r30,r7
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r7.s32, ctx.xer);
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// subf r4,r11,r5
	ctx.r4.s64 = ctx.r5.s64 - ctx.r11.s64;
	// srawi r3,r4,4
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0xF) != 0);
	ctx.r3.s64 = ctx.r4.s32 >> 4;
	// addze r10,r3
	temp.s64 = ctx.r3.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r10.s64 = temp.s64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// bge cr6,0x8813d57c
	if (!ctx.cr6.lt) goto loc_8813D57C;
	// lis r10,280
	ctx.r10.s64 = 18350080;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x8813d57c
	if (!ctx.cr6.lt) goto loc_8813D57C;
	// lis r10,-40
	ctx.r10.s64 = -2621440;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x8813d57c
	if (!ctx.cr6.gt) goto loc_8813D57C;
	// lbz r11,112(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 112);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r9.u8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge cr6,0x8813d4c0
	if (!ctx.cr6.lt) goto loc_8813D4C0;
	// lbz r11,110(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 110);
	// lbz r10,113(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 113);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// stb r10,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r10.u8);
	// cmpwi cr6,r8,3
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 3, ctx.xer);
	// stb r8,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r8.u8);
	// blt cr6,0x8813d4c0
	if (ctx.cr6.lt) goto loc_8813D4C0;
	// stb r27,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r27.u8);
loc_8813D4C0:
	// lwz r11,120(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// lbz r10,110(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 110);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,76(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// cmpwi cr6,r8,256
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 256, ctx.xer);
	// lhzx r11,r9,r29
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r29.u32);
	// add r28,r11,r10
	ctx.r28.u64 = ctx.r11.u64 + ctx.r10.u64;
	// blt cr6,0x8813d4e8
	if (ctx.cr6.lt) goto loc_8813D4E8;
	// mr r27,r26
	ctx.r27.u64 = ctx.r26.u64;
loc_8813D4E8:
	// lwz r29,8(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r6,150
	ctx.r6.s64 = 150;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x881538c0
	ctx.lr = 0x8813D500;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813d518
	if (ctx.cr6.eq) goto loc_8813D518;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r27,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_8813D518:
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// li r6,150
	ctx.r6.s64 = 150;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// subf r5,r11,r30
	ctx.r5.s64 = ctx.r30.s64 - ctx.r11.s64;
	// subf r4,r10,r29
	ctx.r4.s64 = ctx.r29.s64 - ctx.r10.s64;
	// bl 0x881538c0
	ctx.lr = 0x8813D534;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813d570
	if (ctx.cr6.eq) goto loc_8813D570;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// rlwinm r8,r27,26,0,5
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 26) & 0xFC000000;
	// lis r7,128
	ctx.r7.s64 = 8388608;
	// or r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 | ctx.r9.u64;
	// ori r5,r7,32896
	ctx.r5.u64 = ctx.r7.u64 | 32896;
	// lwz r11,-11932(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11932);
	// oris r4,r6,531
	ctx.r4.u64 = ctx.r6.u64 | 34799616;
	// stw r5,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r5.u32);
	// ori r4,r4,32768
	ctx.r4.u64 = ctx.r4.u64 | 32768;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stw r11,-11932(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11932, ctx.r11.u32);
loc_8813D570:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_8813D57C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8813D588"))) PPC_WEAK_FUNC(sub_8813D588);
PPC_FUNC_IMPL(__imp__sub_8813D588) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,0(r5)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x8813d614
	if (!ctx.cr6.eq) goto loc_8813D614;
	// lbz r5,4(r5)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r5.u32 + 4);
	// lwz r4,100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// bl 0x88147a30
	ctx.lr = 0x8813D5BC;
	sub_88147A30(ctx, base);
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// subf. r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r9,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r9.u32);
	// bgt 0x8813d614
	if (ctx.cr0.gt) goto loc_8813D614;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8813d600
	if (ctx.cr6.eq) goto loc_8813D600;
loc_8813D5E8:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8813d600
	if (ctx.cr6.eq) goto loc_8813D600;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813d5e8
	if (!ctx.cr6.eq) goto loc_8813D5E8;
loc_8813D600:
	// lis r10,-30700
	ctx.r10.s64 = -2011955200;
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// stb r9,2(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2, ctx.r9.u8);
	// addi r9,r10,-12360
	ctx.r9.s64 = ctx.r10.s64 + -12360;
	// stw r9,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r9.u32);
loc_8813D614:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813D630"))) PPC_WEAK_FUNC(sub_8813D630);
PPC_FUNC_IMPL(__imp__sub_8813D630) {
	PPC_FUNC_PROLOGUE();
	// lwz r8,128(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r10,28(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8813d660
	if (ctx.cr6.eq) goto loc_8813D660;
loc_8813D648:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8813d6e4
	if (ctx.cr6.eq) goto loc_8813D6E4;
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8813d648
	if (!ctx.cr6.eq) goto loc_8813D648;
loc_8813D660:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8813D664:
	// li r9,32
	ctx.r9.s64 = 32;
	// addi r8,r11,8
	ctx.r8.s64 = ctx.r11.s64 + 8;
	// lis r6,-30671
	ctx.r6.s64 = -2010054656;
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// stw r9,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r9.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r9,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r9.u32);
	// addi r4,r6,-20424
	ctx.r4.s64 = ctx.r6.s64 + -20424;
	// stw r9,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r9.u32);
	// lis r5,-30700
	ctx.r5.s64 = -2011955200;
	// stw r8,36(r10)
	PPC_STORE_U32(ctx.r10.u32 + 36, ctx.r8.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r6,88(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// addi r8,r5,-11576
	ctx.r8.s64 = ctx.r5.s64 + -11576;
	// stw r6,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r6.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 128);
	// stw r7,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r7.u32);
	// lbz r9,114(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 114);
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r10,120(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 120);
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// extsb r9,r9
	ctx.r9.s64 = ctx.r9.s8;
	// stb r5,2(r11)
	PPC_STORE_U8(ctx.r11.u32 + 2, ctx.r5.u8);
	// stw r8,140(r11)
	PPC_STORE_U32(ctx.r11.u32 + 140, ctx.r8.u32);
	// stw r6,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r6.u32);
	// stw r7,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r7.u32);
	// lhzx r10,r10,r4
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r4.u32);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// sth r9,56(r11)
	PPC_STORE_U16(ctx.r11.u32 + 56, ctx.r9.u16);
	// blr 
	return;
loc_8813D6E4:
	// lwz r9,24(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8813d6f4
	if (ctx.cr6.eq) goto loc_8813D6F4;
	// stw r9,64(r10)
	PPC_STORE_U32(ctx.r10.u32 + 64, ctx.r9.u32);
loc_8813D6F4:
	// addi r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 + 24;
	// b 0x8813d664
	goto loc_8813D664;
}

__attribute__((alias("__imp__sub_8813D6FC"))) PPC_WEAK_FUNC(sub_8813D6FC);
PPC_FUNC_IMPL(__imp__sub_8813D6FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8813D700"))) PPC_WEAK_FUNC(sub_8813D700);
PPC_FUNC_IMPL(__imp__sub_8813D700) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071120
	ctx.lr = 0x8813D708;
	__savegprlr_14(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lhz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// addi r19,r11,-19120
	ctx.r19.s64 = ctx.r11.s64 + -19120;
	// extsh r7,r9
	ctx.r7.s64 = ctx.r9.s16;
	// addi r6,r19,-8
	ctx.r6.s64 = ctx.r19.s64 + -8;
	// lbz r4,1(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r8,-30648
	ctx.r8.s64 = -2008547328;
	// extsb r10,r4
	ctx.r10.s64 = ctx.r4.s8;
	// addi r3,r19,-40
	ctx.r3.s64 = ctx.r19.s64 + -40;
	// lbzx r9,r7,r6
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r6.u32);
	// li r18,0
	ctx.r18.s64 = 0;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r11,r8,-5888
	ctx.r11.s64 = ctx.r8.s64 + -5888;
	// extsb r31,r9
	ctx.r31.s64 = ctx.r9.s8;
	// mulli r10,r10,9896
	ctx.r10.s64 = ctx.r10.s64 * 9896;
	// lwzx r24,r5,r3
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r3.u32);
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// add r29,r10,r11
	ctx.r29.u64 = ctx.r10.u64 + ctx.r11.u64;
	// mr r7,r18
	ctx.r7.u64 = ctx.r18.u64;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// ble cr6,0x8813d78c
	if (!ctx.cr6.gt) goto loc_8813D78C;
	// addi r11,r1,92
	ctx.r11.s64 = ctx.r1.s64 + 92;
	// li r10,-1
	ctx.r10.s64 = -1;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8813d78c
	if (ctx.cr6.eq) goto loc_8813D78C;
	// mtctr r31
	ctx.ctr.u64 = ctx.r31.u64;
loc_8813D784:
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8813d784
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8813D784;
loc_8813D78C:
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// addi r10,r11,26432
	ctx.r10.s64 = ctx.r11.s64 + 26432;
	// addi r9,r24,2
	ctx.r9.s64 = ctx.r24.s64 + 2;
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// lwz r4,324(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 324);
loc_8813D7A4:
	// lwz r11,9860(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 9860);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,9860(r29)
	PPC_STORE_U32(ctx.r29.u32 + 9860, ctx.r11.u32);
	// cmpwi cr6,r11,60
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 60, ctx.xer);
	// blt cr6,0x8813d7bc
	if (ctx.cr6.lt) goto loc_8813D7BC;
	// stw r18,9860(r29)
	PPC_STORE_U32(ctx.r29.u32 + 9860, ctx.r18.u32);
loc_8813D7BC:
	// lwz r10,9860(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 9860);
	// mulli r11,r10,164
	ctx.r11.s64 = ctx.r10.s64 * 164;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// lbz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 20);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813d818
	if (!ctx.cr6.eq) goto loc_8813D818;
	// lhz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 0);
	// cmpwi cr6,r4,2
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 2, ctx.xer);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// bne cr6,0x8813d7f0
	if (!ctx.cr6.eq) goto loc_8813D7F0;
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// blt cr6,0x8813d7f0
	if (ctx.cr6.lt) goto loc_8813D7F0;
	// li r11,6
	ctx.r11.s64 = 6;
loc_8813D7F0:
	// lwz r30,0(r8)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmpw cr6,r30,r11
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x8813d800
	if (!ctx.cr6.lt) goto loc_8813D800;
	// stw r10,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r10.u32);
loc_8813D800:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmpw cr6,r7,r31
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r31.s32, ctx.xer);
	// bge cr6,0x8813d824
	if (!ctx.cr6.lt) goto loc_8813D824;
loc_8813D818:
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// cmpwi cr6,r3,60
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 60, ctx.xer);
	// blt cr6,0x8813d7a4
	if (ctx.cr6.lt) goto loc_8813D7A4;
loc_8813D824:
	// lwz r11,9884(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 9884);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,9884(r29)
	PPC_STORE_U32(ctx.r29.u32 + 9884, ctx.r11.u32);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// blt cr6,0x8813d83c
	if (ctx.cr6.lt) goto loc_8813D83C;
	// stw r18,9884(r29)
	PPC_STORE_U32(ctx.r29.u32 + 9884, ctx.r18.u32);
loc_8813D83C:
	// lwz r11,9888(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 9888);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,9888(r29)
	PPC_STORE_U32(ctx.r29.u32 + 9888, ctx.r11.u32);
	// cmpwi cr6,r11,14
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 14, ctx.xer);
	// blt cr6,0x8813d854
	if (ctx.cr6.lt) goto loc_8813D854;
	// stw r18,9888(r29)
	PPC_STORE_U32(ctx.r29.u32 + 9888, ctx.r18.u32);
loc_8813D854:
	// addi r11,r19,-808
	ctx.r11.s64 = ctx.r19.s64 + -808;
	// addi r10,r19,-440
	ctx.r10.s64 = ctx.r19.s64 + -440;
	// addi r9,r19,-1064
	ctx.r9.s64 = ctx.r19.s64 + -1064;
	// addi r17,r1,96
	ctx.r17.s64 = ctx.r1.s64 + 96;
	// mr r22,r18
	ctx.r22.u64 = ctx.r18.u64;
	// lwzx r28,r5,r11
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r11.u32);
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// lwzx r27,r5,r10
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r10.u32);
	// lwzx r26,r5,r9
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r9.u32);
	// ble cr6,0x8813daa8
	if (!ctx.cr6.gt) goto loc_8813DAA8;
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// addi r15,r11,-19568
	ctx.r15.s64 = ctx.r11.s64 + -19568;
	// addi r30,r29,9864
	ctx.r30.s64 = ctx.r29.s64 + 9864;
	// li r20,2
	ctx.r20.s64 = 2;
	// lwz r11,-19568(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -19568);
	// li r23,1
	ctx.r23.s64 = 1;
	// li r21,100
	ctx.r21.s64 = 100;
	// lwz r16,-4596(r15)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r15.u32 + -4596);
	// addi r14,r10,9552
	ctx.r14.s64 = ctx.r10.s64 + 9552;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
loc_8813D8A8:
	// lwz r11,0(r17)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r17.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x8813da84
	if (ctx.cr6.lt) goto loc_8813DA84;
	// mulli r11,r11,164
	ctx.r11.s64 = ctx.r11.s64 * 164;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// addi r31,r11,20
	ctx.r31.s64 = ctx.r11.s64 + 20;
	// stb r22,23(r11)
	PPC_STORE_U8(ctx.r11.u32 + 23, ctx.r22.u8);
	// lwz r11,-9864(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -9864);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-9864(r30)
	PPC_STORE_U32(ctx.r30.u32 + -9864, ctx.r11.u32);
	// lwz r11,9892(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 9892);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stw r9,9892(r29)
	PPC_STORE_U32(ctx.r29.u32 + 9892, ctx.r9.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// blt cr6,0x8813d8f4
	if (ctx.cr6.lt) goto loc_8813D8F4;
	// stw r18,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r18.u32);
loc_8813D8F4:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// addic. r11,r31,20
	ctx.xer.ca = ctx.r31.u32 > 4294967275;
	ctx.r11.s64 = ctx.r31.s64 + 20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r5,0(r25)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// addi r6,r31,16
	ctx.r6.s64 = ctx.r31.s64 + 16;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r9,16(r25)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r25.u32 + 16);
	// stb r10,114(r31)
	PPC_STORE_U8(ctx.r31.u32 + 114, ctx.r10.u8);
	// lwz r3,9884(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 9884);
	// stb r3,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r3.u8);
	// lwz r8,9888(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 9888);
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r7,r19
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r19.u32);
	// stb r3,111(r31)
	PPC_STORE_U8(ctx.r31.u32 + 111, ctx.r3.u8);
	// stb r18,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r18.u8);
	// stb r20,113(r31)
	PPC_STORE_U8(ctx.r31.u32 + 113, ctx.r20.u8);
	// lwz r7,20(r25)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r25.u32 + 20);
	// lhz r3,4(r25)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r25.u32 + 4);
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// stw r10,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r10.u32);
	// lwz r8,4(r26)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// stw r5,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r5.u32);
	// stb r4,1(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1, ctx.r4.u8);
	// stw r8,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r8.u32);
	// stb r23,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r23.u8);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// add r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r8,4(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// add r10,r7,r8
	ctx.r10.u64 = ctx.r7.u64 + ctx.r8.u64;
	// stw r5,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r5.u32);
	// stb r3,4(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4, ctx.r3.u8);
	// stw r10,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r10.u32);
	// lhz r4,0(r24)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r24.u32 + 0);
	// extsh r3,r4
	ctx.r3.s64 = ctx.r4.s16;
	// stw r3,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r3.u32);
	// lwz r10,8(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 8);
	// clrlwi r9,r10,23
	ctx.r9.u64 = ctx.r10.u32 & 0x1FF;
	// stw r9,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r9.u32);
	// rotlwi r10,r3,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// lwz r7,0(r28)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// mulli r5,r7,100
	ctx.r5.s64 = ctx.r7.s64 * 100;
	// divwu r4,r5,r21
	ctx.r4.u32 = ppc_divwu(ctx.r5.u32, ctx.r21.u32);
	// rotlwi r8,r9,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// stw r4,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r4.u32);
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// clrlwi r9,r8,23
	ctx.r9.u64 = ctx.r8.u32 & 0x1FF;
	// stw r3,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r3.u32);
	// lwz r8,4(r28)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// stw r8,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r8.u32);
	// beq 0x8813d9cc
	if (ctx.cr0.eq) goto loc_8813D9CC;
	// addi r8,r9,128
	ctx.r8.s64 = ctx.r9.s64 + 128;
	// rlwinm r7,r8,2,21,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x7FC;
	// lwzx r5,r7,r14
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r14.u32);
	// mullw r4,r5,r10
	ctx.r4.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r10.s32);
	// stw r4,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r4.u32);
loc_8813D9CC:
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x8813d9e4
	if (ctx.cr6.eq) goto loc_8813D9E4;
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r14
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r14.u32);
	// mullw r8,r9,r10
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// stw r8,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r8.u32);
loc_8813D9E4:
	// lbz r11,1(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r4,r11,4
	ctx.r4.s64 = ctx.r11.s64 + 4;
	// bl 0x881556a0
	ctx.lr = 0x8813D9F4;
	sub_881556A0(ctx, base);
	// stw r3,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r3.u32);
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// mr r10,r18
	ctx.r10.u64 = ctx.r18.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8813da20
	if (ctx.cr6.eq) goto loc_8813DA20;
loc_8813DA08:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8813dab4
	if (ctx.cr6.eq) goto loc_8813DAB4;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813da08
	if (!ctx.cr6.eq) goto loc_8813DA08;
loc_8813DA20:
	// mr r11,r18
	ctx.r11.u64 = ctx.r18.u64;
loc_8813DA24:
	// lis r10,-30700
	ctx.r10.s64 = -2011955200;
	// stw r23,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r23.u32);
	// lis r9,-30700
	ctx.r9.s64 = -2011955200;
	// lwz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// addi r7,r10,-10872
	ctx.r7.s64 = ctx.r10.s64 + -10872;
	// stw r31,36(r8)
	PPC_STORE_U32(ctx.r8.u32 + 36, ctx.r31.u32);
	// addi r6,r9,-10704
	ctx.r6.s64 = ctx.r9.s64 + -10704;
	// stw r7,32(r8)
	PPC_STORE_U32(ctx.r8.u32 + 32, ctx.r7.u32);
	// cmpwi cr6,r16,0
	ctx.cr6.compare<int32_t>(ctx.r16.s32, 0, ctx.xer);
	// stb r18,2(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2, ctx.r18.u8);
	// stw r6,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r6.u32);
	// bne cr6,0x8813da80
	if (!ctx.cr6.eq) goto loc_8813DA80;
	// lwz r11,88(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8813da80
	if (!ctx.cr6.eq) goto loc_8813DA80;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r16,3
	ctx.r16.s64 = 3;
	// li r6,16
	ctx.r6.s64 = 16;
	// li r5,24
	ctx.r5.s64 = 24;
	// stw r16,-4596(r15)
	PPC_STORE_U32(ctx.r15.u32 + -4596, ctx.r16.u32);
	// li r4,75
	ctx.r4.s64 = 75;
	// addi r3,r11,3
	ctx.r3.s64 = ctx.r11.s64 + 3;
	// bl 0x880e3240
	ctx.lr = 0x8813DA80;
	sub_880E3240(ctx, base);
loc_8813DA80:
	// lwz r31,84(r1)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_8813DA84:
	// addi r22,r22,1
	ctx.r22.s64 = ctx.r22.s64 + 1;
	// addi r28,r28,8
	ctx.r28.s64 = ctx.r28.s64 + 8;
	// addi r27,r27,12
	ctx.r27.s64 = ctx.r27.s64 + 12;
	// addi r26,r26,8
	ctx.r26.s64 = ctx.r26.s64 + 8;
	// addi r24,r24,4
	ctx.r24.s64 = ctx.r24.s64 + 4;
	// addi r17,r17,4
	ctx.r17.s64 = ctx.r17.s64 + 4;
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// cmpw cr6,r22,r31
	ctx.cr6.compare<int32_t>(ctx.r22.s32, ctx.r31.s32, ctx.xer);
	// blt cr6,0x8813d8a8
	if (ctx.cr6.lt) goto loc_8813D8A8;
loc_8813DAA8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
loc_8813DAB4:
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8813dac4
	if (ctx.cr6.eq) goto loc_8813DAC4;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_8813DAC4:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x8813da24
	goto loc_8813DA24;
}

__attribute__((alias("__imp__sub_8813DACC"))) PPC_WEAK_FUNC(sub_8813DACC);
PPC_FUNC_IMPL(__imp__sub_8813DACC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8813DAD0"))) PPC_WEAK_FUNC(sub_8813DAD0);
PPC_FUNC_IMPL(__imp__sub_8813DAD0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813DAD4"))) PPC_WEAK_FUNC(sub_8813DAD4);
PPC_FUNC_IMPL(__imp__sub_8813DAD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8813DAD8"))) PPC_WEAK_FUNC(sub_8813DAD8);
PPC_FUNC_IMPL(__imp__sub_8813DAD8) {
	PPC_FUNC_PROLOGUE();
	// lwz r9,128(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r8,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r8.u8);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// addi r11,r11,576
	ctx.r11.s64 = ctx.r11.s64 + 576;
	// lwz r10,-104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -104);
	// cmpwi cr6,r10,3000
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3000, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r8.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,-104(r11)
	PPC_STORE_U32(ctx.r11.u32 + -104, ctx.r10.u32);
	// stwx r9,r7,r11
	PPC_STORE_U32(ctx.r7.u32 + ctx.r11.u32, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813DB18"))) PPC_WEAK_FUNC(sub_8813DB18);
PPC_FUNC_IMPL(__imp__sub_8813DB18) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30648
	ctx.r11.s64 = -2008547328;
	// li r5,21184
	ctx.r5.s64 = 21184;
	// addi r31,r11,-27072
	ctx.r31.s64 = ctx.r11.s64 + -27072;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x8813DB40;
	sub_88073BD0(ctx, base);
	// lis r8,-30671
	ctx.r8.s64 = -2010054656;
	// lis r10,16838
	ctx.r10.s64 = 1103495168;
	// lis r9,-21846
	ctx.r9.s64 = -1431699456;
	// ori r5,r10,20077
	ctx.r5.u64 = ctx.r10.u64 | 20077;
	// addi r11,r31,2632
	ctx.r11.s64 = ctx.r31.s64 + 2632;
	// lwz r10,4200(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4200);
	// ori r6,r9,43691
	ctx.r6.u64 = ctx.r9.u64 | 43691;
loc_8813DB5C:
	// mullw r10,r10,r5
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r5.s32);
	// addi r10,r10,12345
	ctx.r10.s64 = ctx.r10.s64 + 12345;
	// addi r4,r31,23816
	ctx.r4.s64 = ctx.r31.s64 + 23816;
	// stw r10,4200(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4200, ctx.r10.u32);
	// lhz r3,4200(r8)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4200);
	// mulhwu r9,r3,r6
	ctx.r9.u64 = (uint64_t(ctx.r3.u32) * uint64_t(ctx.r6.u32)) >> 32;
	// rlwinm r9,r9,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r7,r9,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r9,r7
	ctx.r7.u64 = ctx.r9.u64 + ctx.r7.u64;
	// subf r3,r7,r3
	ctx.r3.s64 = ctx.r3.s64 - ctx.r7.s64;
	// extsh r7,r3
	ctx.r7.s64 = ctx.r3.s16;
	// stw r7,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// addi r11,r11,2648
	ctx.r11.s64 = ctx.r11.s64 + 2648;
	// cmpw cr6,r11,r4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r4.s32, ctx.xer);
	// blt cr6,0x8813db5c
	if (ctx.cr6.lt) goto loc_8813DB5C;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813DBAC"))) PPC_WEAK_FUNC(sub_8813DBAC);
PPC_FUNC_IMPL(__imp__sub_8813DBAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8813DBB0"))) PPC_WEAK_FUNC(sub_8813DBB0);
PPC_FUNC_IMPL(__imp__sub_8813DBB0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x8813DBB8;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30648
	ctx.r11.s64 = -2008547328;
	// li r26,8
	ctx.r26.s64 = 8;
	// addi r30,r11,-27072
	ctx.r30.s64 = ctx.r11.s64 + -27072;
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r29,r11,576
	ctx.r29.s64 = ctx.r11.s64 + 576;
loc_8813DBD4:
	// lwz r11,2644(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2644);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8813dc84
	if (ctx.cr6.eq) goto loc_8813DC84;
	// addi r31,r30,4
	ctx.r31.s64 = ctx.r30.s64 + 4;
	// li r27,16
	ctx.r27.s64 = 16;
loc_8813DBE8:
	// lbz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8813dc78
	if (ctx.cr6.eq) goto loc_8813DC78;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bgt cr6,0x8813dc10
	if (ctx.cr6.gt) goto loc_8813DC10;
	// lwz r11,140(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8813DC10;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8813DC10:
	// lwz r11,140(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8813DC20;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8813dc78
	if (!ctx.cr6.eq) goto loc_8813DC78;
	// lwz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// stb r28,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r28.u8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8813dc58
	if (ctx.cr6.eq) goto loc_8813DC58;
	// lwz r11,-104(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -104);
	// cmpwi cr6,r11,3000
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3000, ctx.xer);
	// bge cr6,0x8813dc58
	if (!ctx.cr6.lt) goto loc_8813DC58;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r28,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r28.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-104(r29)
	PPC_STORE_U32(ctx.r29.u32 + -104, ctx.r11.u32);
	// stwx r10,r9,r29
	PPC_STORE_U32(ctx.r9.u32 + ctx.r29.u32, ctx.r10.u32);
loc_8813DC58:
	// lbz r11,3(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 3);
	// rotlwi r11,r11,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// lwzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r30.u32);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stwx r10,r11,r30
	PPC_STORE_U32(ctx.r11.u32 + ctx.r30.u32, ctx.r10.u32);
	// lwz r11,2644(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2644);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// stw r9,2644(r30)
	PPC_STORE_U32(ctx.r30.u32 + 2644, ctx.r9.u32);
loc_8813DC78:
	// addi r31,r31,164
	ctx.r31.s64 = ctx.r31.s64 + 164;
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// bne 0x8813dbe8
	if (!ctx.cr0.eq) goto loc_8813DBE8;
loc_8813DC84:
	// addi r30,r30,2648
	ctx.r30.s64 = ctx.r30.s64 + 2648;
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne 0x8813dbd4
	if (!ctx.cr0.eq) goto loc_8813DBD4;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8813DC98"))) PPC_WEAK_FUNC(sub_8813DC98);
PPC_FUNC_IMPL(__imp__sub_8813DC98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x8813DCA0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,76(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// lis r10,-30671
	ctx.r10.s64 = -2010054656;
	// lbz r6,114(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 114);
	// lis r9,-30714
	ctx.r9.s64 = -2012872704;
	// addi r5,r11,4
	ctx.r5.s64 = ctx.r11.s64 + 4;
	// lwz r7,32(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// addi r10,r10,3944
	ctx.r10.s64 = ctx.r10.s64 + 3944;
	// lwz r8,36(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// srawi r4,r5,3
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7) != 0);
	ctx.r4.s64 = ctx.r5.s32 >> 3;
	// addi r3,r10,2
	ctx.r3.s64 = ctx.r10.s64 + 2;
	// rlwinm r11,r4,1,25,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0x7E;
	// addi r5,r9,9552
	ctx.r5.s64 = ctx.r9.s64 + 9552;
	// srawi r4,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r4.s64 = ctx.r11.s32 >> 1;
	// rlwinm r31,r11,1,0,30
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addze r11,r4
	temp.s64 = ctx.r4.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r11.s64 = temp.s64;
	// extsb r9,r6
	ctx.r9.s64 = ctx.r6.s8;
	// rlwinm r11,r11,3,23,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0x1F8;
	// li r6,151
	ctx.r6.s64 = 151;
	// addi r4,r11,128
	ctx.r4.s64 = ctx.r11.s64 + 128;
	// lhzx r10,r31,r10
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + ctx.r10.u32);
	// lhzx r29,r31,r3
	ctx.r29.u64 = PPC_LOAD_U16(ctx.r31.u32 + ctx.r3.u32);
	// rlwinm r30,r11,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r3,r4,2,21,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x7FC;
	// rotlwi r11,r10,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwzx r10,r30,r5
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r5.u32);
	// lwzx r5,r3,r5
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r5.u32);
	// add r4,r11,r9
	ctx.r4.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r10,r10,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r11,r5,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00;
	// addis r3,r4,1
	ctx.r3.s64 = ctx.r4.s64 + 65536;
	// add r30,r10,r7
	ctx.r30.u64 = ctx.r10.u64 + ctx.r7.u64;
	// add r31,r11,r8
	ctx.r31.u64 = ctx.r11.u64 + ctx.r8.u64;
	// addi r3,r3,-22215
	ctx.r3.s64 = ctx.r3.s64 + -22215;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x881538c0
	ctx.lr = 0x8813DD38;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813dd50
	if (ctx.cr6.eq) goto loc_8813DD50;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r29,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_8813DD50:
	// li r6,151
	ctx.r6.s64 = 151;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,402
	ctx.r3.s64 = 402;
	// bl 0x881538c0
	ctx.lr = 0x8813DD64;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813dd98
	if (ctx.cr6.eq) goto loc_8813DD98;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r8,48
	ctx.r8.s64 = 3145728;
	// oris r7,r9,545
	ctx.r7.u64 = ctx.r9.u64 | 35717120;
	// ori r6,r8,32800
	ctx.r6.u64 = ctx.r8.u64 | 32800;
	// ori r7,r7,32768
	ctx.r7.u64 = ctx.r7.u64 | 32768;
	// lwz r11,-11932(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11932);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r6,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r6.u32);
	// stw r11,-11932(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11932, ctx.r11.u32);
loc_8813DD98:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8813DDA0"))) PPC_WEAK_FUNC(sub_8813DDA0);
PPC_FUNC_IMPL(__imp__sub_8813DDA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x8813DDA8;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r10,2(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r11,4200
	ctx.r30.s64 = ctx.r11.s64 + 4200;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8813df94
	if (!ctx.cr6.eq) goto loc_8813DF94;
	// lwz r10,128(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// lwz r8,28(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8813ddf4
	if (ctx.cr6.eq) goto loc_8813DDF4;
loc_8813DDDC:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8813ddf4
	if (ctx.cr6.eq) goto loc_8813DDF4;
	// lwz r8,0(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8813dddc
	if (!ctx.cr6.eq) goto loc_8813DDDC;
loc_8813DDF4:
	// lis r11,16838
	ctx.r11.s64 = 1103495168;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// stw r9,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r9.u32);
	// lis r8,-13108
	ctx.r8.s64 = -859045888;
	// ori r11,r11,20077
	ctx.r11.u64 = ctx.r11.u64 | 20077;
	// ori r6,r8,52429
	ctx.r6.u64 = ctx.r8.u64 | 52429;
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// addi r10,r10,12345
	ctx.r10.s64 = ctx.r10.s64 + 12345;
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// stw r10,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// lwz r29,12(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r7,20(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r28,16(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r8,r10,12345
	ctx.r8.s64 = ctx.r10.s64 + 12345;
	// lwz r5,76(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// subf r7,r7,r29
	ctx.r7.s64 = ctx.r29.s64 - ctx.r7.s64;
	// srawi r3,r3,2
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x3) != 0);
	ctx.r3.s64 = ctx.r3.s32 >> 2;
	// stw r7,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r7.u32);
	// subf r11,r28,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r28.s64;
	// addze r10,r3
	temp.s64 = ctx.r3.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r10.s64 = temp.s64;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// stw r10,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r10.u32);
	// stb r3,2(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2, ctx.r3.u8);
	// lis r3,20971
	ctx.r3.s64 = 1374355456;
	// lis r26,14563
	ctx.r26.s64 = 954400768;
	// ori r3,r3,34079
	ctx.r3.u64 = ctx.r3.u64 | 34079;
	// lhz r29,0(r30)
	ctx.r29.u64 = PPC_LOAD_U16(ctx.r30.u32 + 0);
	// stw r8,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r8.u32);
	// mullw r8,r8,r4
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r4.s32);
	// mulhwu r7,r29,r6
	ctx.r7.u64 = (uint64_t(ctx.r29.u32) * uint64_t(ctx.r6.u32)) >> 32;
	// lhz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r30.u32 + 0);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// rlwinm r7,r7,29,3,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 29) & 0x1FFFFFFF;
	// stw r8,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r8.u32);
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
	// rlwinm r4,r7,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,8(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// mulhwu r3,r8,r3
	ctx.r3.u64 = (uint64_t(ctx.r8.u32) * uint64_t(ctx.r3.u32)) >> 32;
	// add r7,r7,r4
	ctx.r7.u64 = ctx.r7.u64 + ctx.r4.u64;
	// rlwinm r4,r3,29,3,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 29) & 0x1FFFFFFF;
	// rlwinm r3,r7,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// mulli r7,r4,25
	ctx.r7.s64 = ctx.r4.s64 * 25;
	// subf r4,r3,r29
	ctx.r4.s64 = ctx.r29.s64 - ctx.r3.s64;
	// addi r3,r11,9552
	ctx.r3.s64 = ctx.r11.s64 + 9552;
	// extsh r11,r4
	ctx.r11.s64 = ctx.r4.s16;
	// lis r4,-30667
	ctx.r4.s64 = -2009792512;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// subf r8,r7,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r7.s64;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// addi r8,r7,-12
	ctx.r8.s64 = ctx.r7.s64 + -12;
	// lwz r7,12(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// li r29,3
	ctx.r29.s64 = 3;
	// addi r28,r11,128
	ctx.r28.s64 = ctx.r11.s64 + 128;
	// rlwinm r27,r11,2,0,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r28,r28,2,21,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0x7FC;
	// li r11,1
	ctx.r11.s64 = 1;
	// rlwinm r8,r8,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// stw r11,12380(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12380, ctx.r11.u32);
	// ori r4,r26,36409
	ctx.r4.u64 = ctx.r26.u64 | 36409;
	// lhz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + 0);
	// lis r26,-30667
	ctx.r26.s64 = -2009792512;
	// lwzx r28,r28,r3
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r28.u32 + ctx.r3.u32);
	// lwzx r3,r27,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r3.u32);
	// mr r27,r11
	ctx.r27.u64 = ctx.r11.u64;
	// mullw r11,r28,r10
	ctx.r11.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r10.s32);
	// stb r9,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r9.u8);
	// stb r9,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r9.u8);
	// stb r9,113(r31)
	PPC_STORE_U8(ctx.r31.u32 + 113, ctx.r9.u8);
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stb r29,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r29.u8);
	// mulhwu r9,r27,r4
	ctx.r9.u64 = (uint64_t(ctx.r27.u32) * uint64_t(ctx.r4.u32)) >> 32;
	// rlwinm r11,r9,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// lis r4,-30667
	ctx.r4.s64 = -2009792512;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// mullw r3,r3,r10
	ctx.r3.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r10.s32);
	// stw r3,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r3.u32);
	// add r10,r11,r9
	ctx.r10.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r11,r8,r6
	ctx.r11.u64 = ctx.r8.u64 + ctx.r6.u64;
	// subf r9,r10,r27
	ctx.r9.s64 = ctx.r27.s64 - ctx.r10.s64;
	// stw r11,12364(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12364, ctx.r11.u32);
	// lis r3,-30667
	ctx.r3.s64 = -2009792512;
	// rlwinm r11,r9,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// lis r8,-30667
	ctx.r8.s64 = -2009792512;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// lis r9,-30667
	ctx.r9.s64 = -2009792512;
	// stw r11,12372(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12372, ctx.r11.u32);
	// li r11,153
	ctx.r11.s64 = 153;
	// li r10,64
	ctx.r10.s64 = 64;
	// stw r11,12376(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12376, ctx.r11.u32);
	// li r6,64
	ctx.r6.s64 = 64;
	// li r4,153
	ctx.r4.s64 = 153;
	// stw r5,12368(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12368, ctx.r5.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,12384(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12384, ctx.r10.u32);
	// bl 0x880f83f8
	ctx.lr = 0x8813DF90;
	sub_880F83F8(ctx, base);
	// b 0x8813dfb4
	goto loc_8813DFB4;
loc_8813DF94:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r9,r11,r8
	ctx.r9.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// stw r9,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r9.u32);
loc_8813DFB4:
	// lwz r11,120(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// addi r9,r30,-23264
	ctx.r9.s64 = ctx.r30.s64 + -23264;
	// lbz r8,110(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 110);
	// li r6,152
	ctx.r6.s64 = 152;
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r29,8(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// extsb r10,r8
	ctx.r10.s64 = ctx.r8.s8;
	// lwz r28,12(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// lhzx r11,r7,r9
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + ctx.r9.u32);
	// add r30,r11,r10
	ctx.r30.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x881538c0
	ctx.lr = 0x8813DFEC;
	sub_881538C0(ctx, base);
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// li r6,152
	ctx.r6.s64 = 152;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// add r5,r10,r28
	ctx.r5.u64 = ctx.r10.u64 + ctx.r28.u64;
	// add r4,r11,r29
	ctx.r4.u64 = ctx.r11.u64 + ctx.r29.u64;
	// bl 0x881538c0
	ctx.lr = 0x8813E008;
	sub_881538C0(ctx, base);
	// lis r30,-30597
	ctx.r30.s64 = -2005204992;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813e040
	if (ctx.cr6.eq) goto loc_8813E040;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,160
	ctx.r9.s64 = 10485760;
	// lwz r11,-11932(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -11932);
	// oris r7,r10,531
	ctx.r7.u64 = ctx.r10.u64 | 34799616;
	// ori r8,r9,45168
	ctx.r8.u64 = ctx.r9.u64 | 45168;
	// ori r7,r7,32768
	ctx.r7.u64 = ctx.r7.u64 | 32768;
	// addi r27,r11,1
	ctx.r27.s64 = ctx.r11.s64 + 1;
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r27,-11932(r30)
	PPC_STORE_U32(ctx.r30.u32 + -11932, ctx.r27.u32);
	// b 0x8813e044
	goto loc_8813E044;
loc_8813E040:
	// lwz r27,-11932(r30)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r30.u32 + -11932);
loc_8813E044:
	// li r6,152
	ctx.r6.s64 = 152;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,387
	ctx.r3.s64 = 387;
	// bl 0x881538c0
	ctx.lr = 0x8813E058;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813e084
	if (ctx.cr6.eq) goto loc_8813E084;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,32
	ctx.r9.s64 = 2097152;
	// addi r11,r27,1
	ctx.r11.s64 = ctx.r27.s64 + 1;
	// oris r7,r10,545
	ctx.r7.u64 = ctx.r10.u64 | 35717120;
	// ori r8,r9,32800
	ctx.r8.u64 = ctx.r9.u64 | 32800;
	// stw r11,-11932(r30)
	PPC_STORE_U32(ctx.r30.u32 + -11932, ctx.r11.u32);
	// ori r7,r7,32768
	ctx.r7.u64 = ctx.r7.u64 | 32768;
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
loc_8813E084:
	// lbz r11,112(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 112);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r9.u8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge cr6,0x8813e0c0
	if (!ctx.cr6.lt) goto loc_8813E0C0;
	// lbz r11,110(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 110);
	// li r3,0
	ctx.r3.s64 = 0;
	// lbz r10,113(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 113);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// stb r10,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r10.u8);
	// cmpwi cr6,r8,8
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 8, ctx.xer);
	// stb r8,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r8.u8);
	// bge cr6,0x8813e0c4
	if (!ctx.cr6.lt) goto loc_8813E0C4;
loc_8813E0C0:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8813E0C4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8813E0CC"))) PPC_WEAK_FUNC(sub_8813E0CC);
PPC_FUNC_IMPL(__imp__sub_8813E0CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8813E0D0"))) PPC_WEAK_FUNC(sub_8813E0D0);
PPC_FUNC_IMPL(__imp__sub_8813E0D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x8813E0D8;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,2(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813e100
	if (!ctx.cr6.eq) goto loc_8813E100;
	// li r11,2
	ctx.r11.s64 = 2;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r11.u8);
	// stb r10,2(r3)
	PPC_STORE_U8(ctx.r3.u32 + 2, ctx.r10.u8);
	// stb r11,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, ctx.r11.u8);
loc_8813E100:
	// lbz r11,5(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 5);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8813e158
	if (ctx.cr6.eq) goto loc_8813E158;
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lis r9,-30651
	ctx.r9.s64 = -2008743936;
	// lwz r8,156(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 156);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r9,r9,-16096
	ctx.r9.s64 = ctx.r9.s64 + -16096;
	// rlwinm r11,r8,7,0,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 7) & 0xFFFFFF80;
	// lbz r7,1(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// extsb r6,r7
	ctx.r6.s64 = ctx.r7.s8;
	// mulli r10,r6,3768
	ctx.r10.s64 = ctx.r6.s64 * 3768;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r5,16(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// stw r5,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r5.u32);
	// lwz r4,20(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// stw r4,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r4.u32);
	// bl 0x8813dc98
	ctx.lr = 0x8813E14C;
	sub_8813DC98(ctx, base);
	// lbz r3,5(r31)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r31.u32 + 5);
	// addi r11,r3,-1
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// stb r11,5(r31)
	PPC_STORE_U8(ctx.r31.u32 + 5, ctx.r11.u8);
loc_8813E158:
	// lbz r9,1(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// lis r8,-30651
	ctx.r8.s64 = -2008743936;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r7,360
	ctx.r7.s64 = 23592960;
	// rotlwi r5,r9,2
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addi r6,r8,-8560
	ctx.r6.s64 = ctx.r8.s64 + -8560;
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// add r27,r10,r11
	ctx.r27.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmpw cr6,r27,r7
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r7.s32, ctx.xer);
	// lwzx r11,r5,r6
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r6.u32);
	// stw r27,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r27.u32);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r4,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r4.u32);
	// bge cr6,0x8813e398
	if (!ctx.cr6.lt) goto loc_8813E398;
	// lis r10,-40
	ctx.r10.s64 = -2621440;
	// cmpw cr6,r27,r10
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x8813e398
	if (!ctx.cr6.gt) goto loc_8813E398;
	// rotlwi r11,r4,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 0);
	// lis r9,280
	ctx.r9.s64 = 18350080;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x8813e398
	if (!ctx.cr6.lt) goto loc_8813E398;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x8813e398
	if (!ctx.cr6.gt) goto loc_8813E398;
	// lbz r11,112(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 112);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r9.u8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge cr6,0x8813e200
	if (!ctx.cr6.lt) goto loc_8813E200;
	// lbz r11,110(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 110);
	// lbz r10,113(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 113);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// stb r10,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r10.u8);
	// cmpwi cr6,r8,3
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 3, ctx.xer);
	// stb r8,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r8.u8);
	// blt cr6,0x8813e200
	if (ctx.cr6.lt) goto loc_8813E200;
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r11.u8);
loc_8813E200:
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// lis r10,-30671
	ctx.r10.s64 = -2010054656;
	// lwz r9,120(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// li r6,150
	ctx.r6.s64 = 150;
	// addi r8,r11,4
	ctx.r8.s64 = ctx.r11.s64 + 4;
	// lbz r7,110(r31)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r31.u32 + 110);
	// addi r29,r10,3944
	ctx.r29.s64 = ctx.r10.s64 + 3944;
	// lwz r28,8(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// srawi r5,r8,3
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7) != 0);
	ctx.r5.s64 = ctx.r8.s32 >> 3;
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// rlwinm r25,r5,1,25,30
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0x7E;
	// addi r26,r11,-19032
	ctx.r26.s64 = ctx.r11.s64 + -19032;
	// rlwinm r30,r25,1,0,30
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r3,r26,-8
	ctx.r3.s64 = ctx.r26.s64 + -8;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// extsb r10,r7
	ctx.r10.s64 = ctx.r7.s8;
	// addi r7,r29,2
	ctx.r7.s64 = ctx.r29.s64 + 2;
	// lhzx r11,r30,r29
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + ctx.r29.u32);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// rotlwi r8,r11,1
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// lhzx r9,r9,r3
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r3.u32);
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lhzx r24,r30,r7
	ctx.r24.u64 = PPC_LOAD_U16(ctx.r30.u32 + ctx.r7.u32);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x8813E26C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813e290
	if (ctx.cr6.eq) goto loc_8813E290;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r24,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 26) & 0xFC000000;
	// lis r9,144
	ctx.r9.s64 = 9437184;
	// or r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 | ctx.r11.u64;
	// ori r7,r9,41088
	ctx.r7.u64 = ctx.r9.u64 | 41088;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stw r7,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r7.u32);
loc_8813E290:
	// srawi r11,r25,1
	ctx.xer.ca = (ctx.r25.s32 < 0) & ((ctx.r25.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r25.s32 >> 1;
	// lwz r10,120(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// lis r8,-30714
	ctx.r8.s64 = -2012872704;
	// lhzx r9,r30,r29
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r30.u32 + ctx.r29.u32);
	// addze r7,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r7.s64 = temp.s64;
	// rlwinm r4,r10,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r11,r7,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r5,r8,9552
	ctx.r5.s64 = ctx.r8.s64 + 9552;
	// addi r3,r11,-256
	ctx.r3.s64 = ctx.r11.s64 + -256;
	// li r6,150
	ctx.r6.s64 = 150;
	// clrlwi r11,r3,23
	ctx.r11.u64 = ctx.r3.u32 & 0x1FF;
	// lhzx r10,r4,r26
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r4.u32 + ctx.r26.u32);
	// addi r8,r11,128
	ctx.r8.s64 = ctx.r11.s64 + 128;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r4,r8,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x7FC;
	// add r29,r10,r9
	ctx.r29.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwzx r11,r7,r5
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r5.u32);
	// lwzx r10,r4,r5
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r5.u32);
	// rlwinm r31,r11,7,0,24
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 7) & 0xFFFFFF80;
	// rlwinm r30,r10,7,0,24
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 7) & 0xFFFFFF80;
	// add r4,r31,r28
	ctx.r4.u64 = ctx.r31.u64 + ctx.r28.u64;
	// add r5,r30,r27
	ctx.r5.u64 = ctx.r30.u64 + ctx.r27.u64;
	// bl 0x881538c0
	ctx.lr = 0x8813E2F0;
	sub_881538C0(ctx, base);
	// lis r26,-30597
	ctx.r26.s64 = -2005204992;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813e330
	if (ctx.cr6.eq) goto loc_8813E330;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r24,26,0,5
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 26) & 0xFC000000;
	// lwz r11,-11932(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + -11932);
	// lis r8,96
	ctx.r8.s64 = 6291456;
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// ori r6,r8,32816
	ctx.r6.u64 = ctx.r8.u64 | 32816;
	// oris r5,r7,545
	ctx.r5.u64 = ctx.r7.u64 | 35717120;
	// addi r25,r11,1
	ctx.r25.s64 = ctx.r11.s64 + 1;
	// stw r6,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r6.u32);
	// ori r5,r5,49152
	ctx.r5.u64 = ctx.r5.u64 | 49152;
	// stw r25,-11932(r26)
	PPC_STORE_U32(ctx.r26.u32 + -11932, ctx.r25.u32);
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// b 0x8813e334
	goto loc_8813E334;
loc_8813E330:
	// lwz r25,-11932(r26)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r26.u32 + -11932);
loc_8813E334:
	// rlwinm r10,r30,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r11,r31,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r30,r10
	ctx.r10.u64 = ctx.r30.u64 + ctx.r10.u64;
	// add r11,r31,r11
	ctx.r11.u64 = ctx.r31.u64 + ctx.r11.u64;
	// li r6,150
	ctx.r6.s64 = 150;
	// add r5,r10,r27
	ctx.r5.u64 = ctx.r10.u64 + ctx.r27.u64;
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x881538c0
	ctx.lr = 0x8813E358;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813e38c
	if (ctx.cr6.eq) goto loc_8813E38C;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r24,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 26) & 0xFC000000;
	// lis r9,96
	ctx.r9.s64 = 6291456;
	// or r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 | ctx.r11.u64;
	// ori r7,r9,32912
	ctx.r7.u64 = ctx.r9.u64 | 32912;
	// oris r6,r8,545
	ctx.r6.u64 = ctx.r8.u64 | 35717120;
	// addi r11,r25,1
	ctx.r11.s64 = ctx.r25.s64 + 1;
	// stw r7,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r7.u32);
	// ori r6,r6,32768
	ctx.r6.u64 = ctx.r6.u64 | 32768;
	// stw r11,-11932(r26)
	PPC_STORE_U32(ctx.r26.u32 + -11932, ctx.r11.u32);
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
loc_8813E38C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
loc_8813E398:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8813E3A4"))) PPC_WEAK_FUNC(sub_8813E3A4);
PPC_FUNC_IMPL(__imp__sub_8813E3A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8813E3A8"))) PPC_WEAK_FUNC(sub_8813E3A8);
PPC_FUNC_IMPL(__imp__sub_8813E3A8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,0(r5)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x8813e434
	if (!ctx.cr6.eq) goto loc_8813E434;
	// lbz r5,4(r5)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r5.u32 + 4);
	// lwz r4,100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// bl 0x88147a30
	ctx.lr = 0x8813E3DC;
	sub_88147A30(ctx, base);
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// subf. r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r9,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r9.u32);
	// bgt 0x8813e434
	if (ctx.cr0.gt) goto loc_8813E434;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8813e420
	if (ctx.cr6.eq) goto loc_8813E420;
loc_8813E408:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8813e420
	if (ctx.cr6.eq) goto loc_8813E420;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813e408
	if (!ctx.cr6.eq) goto loc_8813E408;
loc_8813E420:
	// lis r10,-30700
	ctx.r10.s64 = -2011955200;
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// stb r9,2(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2, ctx.r9.u8);
	// addi r9,r10,-8800
	ctx.r9.s64 = ctx.r10.s64 + -8800;
	// stw r9,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r9.u32);
loc_8813E434:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813E450"))) PPC_WEAK_FUNC(sub_8813E450);
PPC_FUNC_IMPL(__imp__sub_8813E450) {
	PPC_FUNC_PROLOGUE();
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lwz r8,128(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// lwz r10,28(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8813e48c
	if (ctx.cr6.eq) goto loc_8813E48C;
loc_8813E474:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8813e540
	if (ctx.cr6.eq) goto loc_8813E540;
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8813e474
	if (!ctx.cr6.eq) goto loc_8813E474;
loc_8813E48C:
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
loc_8813E490:
	// lis r8,-30671
	ctx.r8.s64 = -2010054656;
	// lbz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// lbz r6,3(r11)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r11.u32 + 3);
	// addi r9,r11,8
	ctx.r9.s64 = ctx.r11.s64 + 8;
	// addi r8,r8,-19048
	ctx.r8.s64 = ctx.r8.s64 + -19048;
	// rotlwi r4,r7,2
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// addi r7,r8,368
	ctx.r7.s64 = ctx.r8.s64 + 368;
	// rotlwi r6,r6,3
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r6.u32, 3);
	// lis r30,-30700
	ctx.r30.s64 = -2011955200;
	// li r31,1
	ctx.r31.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwzx r7,r4,r7
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r7.u32);
	// addi r4,r30,-7984
	ctx.r4.s64 = ctx.r30.s64 + -7984;
	// stw r9,36(r10)
	PPC_STORE_U32(ctx.r10.u32 + 36, ctx.r9.u32);
	// add r9,r7,r6
	ctx.r9.u64 = ctx.r7.u64 + ctx.r6.u64;
	// lwzx r30,r7,r6
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// stw r30,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r30.u32);
	// lwzx r7,r7,r6
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// stw r7,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r7.u32);
	// lwz r6,4(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r6,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r6.u32);
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r9,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r9.u32);
	// lwz r7,92(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 92);
	// stw r7,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r7.u32);
	// stw r5,40(r10)
	PPC_STORE_U32(ctx.r10.u32 + 40, ctx.r5.u32);
	// lwz r6,128(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 128);
	// stw r31,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r31.u32);
	// lwz r10,120(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 120);
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// stw r4,140(r11)
	PPC_STORE_U32(ctx.r11.u32 + 140, ctx.r4.u32);
	// stw r6,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r6.u32);
	// stw r7,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r7.u32);
	// rlwinm r4,r10,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lbz r10,114(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 114);
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r5,2(r11)
	PPC_STORE_U8(ctx.r11.u32 + 2, ctx.r5.u8);
	// lhzx r10,r4,r8
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r4.u32 + ctx.r8.u32);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// sth r9,56(r11)
	PPC_STORE_U16(ctx.r11.u32 + 56, ctx.r9.u16);
	// ld r30,-16(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_8813E540:
	// lwz r9,24(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8813e550
	if (ctx.cr6.eq) goto loc_8813E550;
	// stw r9,64(r10)
	PPC_STORE_U32(ctx.r10.u32 + 64, ctx.r9.u32);
loc_8813E550:
	// addi r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 + 24;
	// b 0x8813e490
	goto loc_8813E490;
}

__attribute__((alias("__imp__sub_8813E558"))) PPC_WEAK_FUNC(sub_8813E558);
PPC_FUNC_IMPL(__imp__sub_8813E558) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071120
	ctx.lr = 0x8813E560;
	__savegprlr_14(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// lhz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lhz r7,8(r3)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// addi r18,r11,-18576
	ctx.r18.s64 = ctx.r11.s64 + -18576;
	// extsh r6,r9
	ctx.r6.s64 = ctx.r9.s16;
	// addi r4,r18,-8
	ctx.r4.s64 = ctx.r18.s64 + -8;
	// lbz r3,1(r10)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// addi r10,r18,-40
	ctx.r10.s64 = ctx.r18.s64 + -40;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// extsb r15,r3
	ctx.r15.s64 = ctx.r3.s8;
	// extsh r14,r7
	ctx.r14.s64 = ctx.r7.s16;
	// rlwinm r11,r15,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 2) & 0xFFFFFFFC;
	// lbzx r9,r6,r4
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r4.u32);
	// lis r8,-30648
	ctx.r8.s64 = -2008547328;
	// stw r14,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r14.u32);
	// add r7,r11,r14
	ctx.r7.u64 = ctx.r11.u64 + ctx.r14.u64;
	// lwzx r23,r5,r10
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r10.u32);
	// extsb r31,r9
	ctx.r31.s64 = ctx.r9.s8;
	// mulli r10,r7,2648
	ctx.r10.s64 = ctx.r7.s64 * 2648;
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r31.u32);
	// li r17,0
	ctx.r17.s64 = 0;
	// addi r11,r8,-27072
	ctx.r11.s64 = ctx.r8.s64 + -27072;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// add r28,r10,r11
	ctx.r28.u64 = ctx.r10.u64 + ctx.r11.u64;
	// mr r7,r17
	ctx.r7.u64 = ctx.r17.u64;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// ble cr6,0x8813e5f4
	if (!ctx.cr6.gt) goto loc_8813E5F4;
	// addi r11,r1,76
	ctx.r11.s64 = ctx.r1.s64 + 76;
	// li r10,-1
	ctx.r10.s64 = -1;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8813e5f4
	if (ctx.cr6.eq) goto loc_8813E5F4;
	// mtctr r31
	ctx.ctr.u64 = ctx.r31.u64;
loc_8813E5EC:
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8813e5ec
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8813E5EC;
loc_8813E5F4:
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// addi r10,r11,26432
	ctx.r10.s64 = ctx.r11.s64 + 26432;
	// addi r9,r23,2
	ctx.r9.s64 = ctx.r23.s64 + 2;
	// mr r8,r28
	ctx.r8.u64 = ctx.r28.u64;
	// lwz r4,324(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 324);
loc_8813E60C:
	// lwz r11,2628(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 2628);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,2628(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2628, ctx.r11.u32);
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// blt cr6,0x8813e624
	if (ctx.cr6.lt) goto loc_8813E624;
	// stw r17,2628(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2628, ctx.r17.u32);
loc_8813E624:
	// lwz r10,2628(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 2628);
	// mulli r11,r10,164
	ctx.r11.s64 = ctx.r10.s64 * 164;
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// lbz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813e680
	if (!ctx.cr6.eq) goto loc_8813E680;
	// lhz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 0);
	// cmpwi cr6,r4,2
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 2, ctx.xer);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// bne cr6,0x8813e658
	if (!ctx.cr6.eq) goto loc_8813E658;
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// blt cr6,0x8813e658
	if (ctx.cr6.lt) goto loc_8813E658;
	// li r11,8
	ctx.r11.s64 = 8;
loc_8813E658:
	// lwz r29,0(r8)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmpw cr6,r29,r11
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x8813e668
	if (!ctx.cr6.lt) goto loc_8813E668;
	// stw r10,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r10.u32);
loc_8813E668:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmpw cr6,r7,r31
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r31.s32, ctx.xer);
	// bge cr6,0x8813e68c
	if (!ctx.cr6.lt) goto loc_8813E68C;
loc_8813E680:
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// cmpwi cr6,r3,16
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 16, ctx.xer);
	// blt cr6,0x8813e60c
	if (ctx.cr6.lt) goto loc_8813E60C;
loc_8813E68C:
	// lwz r11,2636(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 2636);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,2636(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2636, ctx.r11.u32);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// blt cr6,0x8813e6a4
	if (ctx.cr6.lt) goto loc_8813E6A4;
	// stw r17,2636(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2636, ctx.r17.u32);
loc_8813E6A4:
	// lwz r11,2640(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 2640);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,2640(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2640, ctx.r11.u32);
	// cmpwi cr6,r11,14
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 14, ctx.xer);
	// blt cr6,0x8813e6bc
	if (ctx.cr6.lt) goto loc_8813E6BC;
	// stw r17,2640(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2640, ctx.r17.u32);
loc_8813E6BC:
	// addi r11,r18,-328
	ctx.r11.s64 = ctx.r18.s64 + -328;
	// addi r10,r18,-200
	ctx.r10.s64 = ctx.r18.s64 + -200;
	// addi r9,r18,-424
	ctx.r9.s64 = ctx.r18.s64 + -424;
	// addi r16,r1,80
	ctx.r16.s64 = ctx.r1.s64 + 80;
	// mr r22,r17
	ctx.r22.u64 = ctx.r17.u64;
	// lwzx r27,r5,r11
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r11.u32);
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// lwzx r26,r5,r10
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r10.u32);
	// lwzx r25,r5,r9
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r9.u32);
	// ble cr6,0x8813e92c
	if (!ctx.cr6.gt) goto loc_8813E92C;
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// addi r29,r28,2632
	ctx.r29.s64 = ctx.r28.s64 + 2632;
	// li r19,2
	ctx.r19.s64 = 2;
	// li r20,1
	ctx.r20.s64 = 1;
	// li r21,100
	ctx.r21.s64 = 100;
	// addi r24,r11,9552
	ctx.r24.s64 = ctx.r11.s64 + 9552;
loc_8813E6FC:
	// lwz r11,0(r16)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x8813e908
	if (ctx.cr6.lt) goto loc_8813E908;
	// mulli r11,r11,164
	ctx.r11.s64 = ctx.r11.s64 * 164;
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// addi r31,r11,4
	ctx.r31.s64 = ctx.r11.s64 + 4;
	// stb r22,7(r11)
	PPC_STORE_U8(ctx.r11.u32 + 7, ctx.r22.u8);
	// stw r14,160(r11)
	PPC_STORE_U32(ctx.r11.u32 + 160, ctx.r14.u32);
	// lwz r11,-2632(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -2632);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-2632(r29)
	PPC_STORE_U32(ctx.r29.u32 + -2632, ctx.r11.u32);
	// lwz r11,2644(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 2644);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stw r9,2644(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2644, ctx.r9.u32);
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// blt cr6,0x8813e74c
	if (ctx.cr6.lt) goto loc_8813E74C;
	// stw r17,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r17.u32);
loc_8813E74C:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// addi r5,r31,16
	ctx.r5.s64 = ctx.r31.s64 + 16;
	// lhz r6,6(r30)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r30.u32 + 6);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// extsh r3,r6
	ctx.r3.s64 = ctx.r6.s16;
	// lhz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4);
	// stb r11,114(r31)
	PPC_STORE_U8(ctx.r31.u32 + 114, ctx.r11.u8);
	// neg r7,r3
	ctx.r7.s64 = -ctx.r3.s64;
	// lwz r11,2636(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 2636);
	// stb r11,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r11.u8);
	// lwz r6,2640(r28)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r28.u32 + 2640);
	// rlwinm r11,r6,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r18
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r18.u32);
	// clrlwi r11,r7,23
	ctx.r11.u64 = ctx.r7.u32 & 0x1FF;
	// stb r9,111(r31)
	PPC_STORE_U8(ctx.r31.u32 + 111, ctx.r9.u8);
	// clrlwi r9,r3,23
	ctx.r9.u64 = ctx.r3.u32 & 0x1FF;
	// stb r17,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r17.u8);
	// addi r6,r11,128
	ctx.r6.s64 = ctx.r11.s64 + 128;
	// stb r19,113(r31)
	PPC_STORE_U8(ctx.r31.u32 + 113, ctx.r19.u8);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,0(r25)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// rlwinm r14,r6,2,21,29
	ctx.r14.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// stw r3,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r3.u32);
	// lwz r3,4(r25)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r25.u32 + 4);
	// stw r8,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r8.u32);
	// stw r3,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r3.u32);
	// stb r15,1(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1, ctx.r15.u8);
	// stb r20,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r20.u8);
	// lwzx r8,r11,r24
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// srawi r11,r11,8
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 8;
	// lwz r10,4(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// lwzx r3,r14,r24
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r14.u32 + ctx.r24.u32);
	// srawi r10,r10,8
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xFF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 8;
	// stb r4,4(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4, ctx.r4.u8);
	// rlwinm r4,r3,4,0,27
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// addze r10,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r10.s64 = temp.s64;
	// lwz r7,16(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// rlwinm r3,r8,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r6,20(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// mullw r14,r11,r4
	ctx.r14.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r4.s32);
	// mullw r8,r10,r3
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r3.s32);
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// mullw r8,r11,r3
	ctx.r8.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r3.s32);
	// mullw r11,r10,r4
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r4.s32);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// subf r3,r3,r14
	ctx.r3.s64 = ctx.r14.s64 - ctx.r3.s64;
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + ctx.r11.u64;
	// srawi r10,r3,8
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFF) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 8;
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r11.s64 = temp.s64;
	// srawi r4,r8,8
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFF) != 0);
	ctx.r4.s64 = ctx.r8.s32 >> 8;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// addze r10,r4
	temp.s64 = ctx.r4.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r10.s64 = temp.s64;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// addic. r11,r31,20
	ctx.xer.ca = ctx.r31.u32 > 4294967275;
	ctx.r11.s64 = ctx.r31.s64 + 20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// add r3,r10,r6
	ctx.r3.u64 = ctx.r10.u64 + ctx.r6.u64;
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// lhz r10,0(r23)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r23.u32 + 0);
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// stw r8,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r8.u32);
	// rotlwi r10,r8,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// stw r9,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r9.u32);
	// lwz r7,0(r27)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// mulli r6,r7,100
	ctx.r6.s64 = ctx.r7.s64 * 100;
	// divwu r4,r6,r21
	ctx.r4.u32 = ppc_divwu(ctx.r6.u32, ctx.r21.u32);
	// stw r4,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r4.u32);
	// lwz r3,0(r27)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// stw r3,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r3.u32);
	// lwz r8,4(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// stw r8,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r8.u32);
	// beq 0x8813e880
	if (ctx.cr0.eq) goto loc_8813E880;
	// addi r8,r9,128
	ctx.r8.s64 = ctx.r9.s64 + 128;
	// rlwinm r7,r8,2,21,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x7FC;
	// lwzx r6,r7,r24
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r24.u32);
	// mullw r4,r6,r10
	ctx.r4.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r10.s32);
	// stw r4,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r4.u32);
loc_8813E880:
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x8813e898
	if (ctx.cr6.eq) goto loc_8813E898;
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r24
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// mullw r8,r9,r10
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// stw r8,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r8.u32);
loc_8813E898:
	// lbz r11,1(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r4,r11,4
	ctx.r4.s64 = ctx.r11.s64 + 4;
	// bl 0x881556a0
	ctx.lr = 0x8813E8A8;
	sub_881556A0(ctx, base);
	// stw r3,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r3.u32);
	// mr r10,r17
	ctx.r10.u64 = ctx.r17.u64;
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8813e8d4
	if (ctx.cr6.eq) goto loc_8813E8D4;
loc_8813E8BC:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8813e938
	if (ctx.cr6.eq) goto loc_8813E938;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813e8bc
	if (!ctx.cr6.eq) goto loc_8813E8BC;
loc_8813E8D4:
	// mr r11,r17
	ctx.r11.u64 = ctx.r17.u64;
loc_8813E8D8:
	// lis r10,-30700
	ctx.r10.s64 = -2011955200;
	// stw r17,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r17.u32);
	// lis r9,-30700
	ctx.r9.s64 = -2011955200;
	// lwz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// addi r7,r10,-7256
	ctx.r7.s64 = ctx.r10.s64 + -7256;
	// stw r31,36(r8)
	PPC_STORE_U32(ctx.r8.u32 + 36, ctx.r31.u32);
	// addi r6,r9,-7088
	ctx.r6.s64 = ctx.r9.s64 + -7088;
	// stw r7,32(r8)
	PPC_STORE_U32(ctx.r8.u32 + 32, ctx.r7.u32);
	// stb r17,2(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2, ctx.r17.u8);
	// stw r6,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r6.u32);
	// lwz r31,88(r1)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r14,92(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
loc_8813E908:
	// addi r22,r22,1
	ctx.r22.s64 = ctx.r22.s64 + 1;
	// addi r27,r27,8
	ctx.r27.s64 = ctx.r27.s64 + 8;
	// addi r26,r26,12
	ctx.r26.s64 = ctx.r26.s64 + 12;
	// addi r25,r25,8
	ctx.r25.s64 = ctx.r25.s64 + 8;
	// addi r23,r23,4
	ctx.r23.s64 = ctx.r23.s64 + 4;
	// addi r16,r16,4
	ctx.r16.s64 = ctx.r16.s64 + 4;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// cmpw cr6,r22,r31
	ctx.cr6.compare<int32_t>(ctx.r22.s32, ctx.r31.s32, ctx.xer);
	// blt cr6,0x8813e6fc
	if (ctx.cr6.lt) goto loc_8813E6FC;
loc_8813E92C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
loc_8813E938:
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8813e948
	if (ctx.cr6.eq) goto loc_8813E948;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_8813E948:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x8813e8d8
	goto loc_8813E8D8;
}

__attribute__((alias("__imp__sub_8813E950"))) PPC_WEAK_FUNC(sub_8813E950);
PPC_FUNC_IMPL(__imp__sub_8813E950) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813E954"))) PPC_WEAK_FUNC(sub_8813E954);
PPC_FUNC_IMPL(__imp__sub_8813E954) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8813E958"))) PPC_WEAK_FUNC(sub_8813E958);
PPC_FUNC_IMPL(__imp__sub_8813E958) {
	PPC_FUNC_PROLOGUE();
	// lwz r9,128(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r8,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r8.u8);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// addi r11,r11,576
	ctx.r11.s64 = ctx.r11.s64 + 576;
	// lwz r10,-104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -104);
	// cmpwi cr6,r10,3000
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3000, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r8.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,-104(r11)
	PPC_STORE_U32(ctx.r11.u32 + -104, ctx.r10.u32);
	// stwx r9,r7,r11
	PPC_STORE_U32(ctx.r7.u32 + ctx.r11.u32, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813E998"))) PPC_WEAK_FUNC(sub_8813E998);
PPC_FUNC_IMPL(__imp__sub_8813E998) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30649
	ctx.r11.s64 = -2008612864;
	// li r5,13880
	ctx.r5.s64 = 13880;
	// addi r31,r11,24584
	ctx.r31.s64 = ctx.r11.s64 + 24584;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x8813E9C0;
	sub_88073BD0(ctx, base);
	// lis r7,-30671
	ctx.r7.s64 = -2010054656;
	// lis r10,-21846
	ctx.r10.s64 = -1431699456;
	// lis r11,16838
	ctx.r11.s64 = 1103495168;
	// ori r6,r10,43691
	ctx.r6.u64 = ctx.r10.u64 | 43691;
	// addi r4,r31,180
	ctx.r4.s64 = ctx.r31.s64 + 180;
	// lwz r10,4200(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4200);
	// ori r5,r11,20077
	ctx.r5.u64 = ctx.r11.u64 | 20077;
loc_8813E9DC:
	// li r11,5
	ctx.r11.s64 = 5;
	// addi r9,r4,6720
	ctx.r9.s64 = ctx.r4.s64 + 6720;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8813E9E8:
	// mullw r11,r10,r5
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r5.s32);
	// addi r10,r11,12345
	ctx.r10.s64 = ctx.r11.s64 + 12345;
	// stw r10,4200(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4200, ctx.r10.u32);
	// lhz r3,4200(r7)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r7.u32 + 4200);
	// mulhwu r11,r3,r6
	ctx.r11.u64 = (uint64_t(ctx.r3.u32) * uint64_t(ctx.r6.u32)) >> 32;
	// rlwinm r11,r11,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// subf r3,r8,r3
	ctx.r3.s64 = ctx.r3.s64 - ctx.r8.s64;
	// extsh r8,r3
	ctx.r8.s64 = ctx.r3.s16;
	// stwu r8,4(r9)
	ea = 4 + ctx.r9.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x8813e9e8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8813E9E8;
	// li r8,40
	ctx.r8.s64 = 40;
	// addi r9,r4,-164
	ctx.r9.s64 = ctx.r4.s64 + -164;
	// addi r11,r4,6400
	ctx.r11.s64 = ctx.r4.s64 + 6400;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_8813EA28:
	// stwu r11,164(r9)
	ea = 164 + ctx.r9.u32;
	PPC_STORE_U32(ea, ctx.r11.u32);
	ctx.r9.u32 = ea;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// bdnz 0x8813ea28
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8813EA28;
	// addi r4,r4,6940
	ctx.r4.s64 = ctx.r4.s64 + 6940;
	// addi r11,r31,14060
	ctx.r11.s64 = ctx.r31.s64 + 14060;
	// cmpw cr6,r4,r11
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8813e9dc
	if (ctx.cr6.lt) goto loc_8813E9DC;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813EA58"))) PPC_WEAK_FUNC(sub_8813EA58);
PPC_FUNC_IMPL(__imp__sub_8813EA58) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x8813EA60;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30649
	ctx.r11.s64 = -2008612864;
	// li r26,2
	ctx.r26.s64 = 2;
	// addi r30,r11,24584
	ctx.r30.s64 = ctx.r11.s64 + 24584;
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r29,r11,576
	ctx.r29.s64 = ctx.r11.s64 + 576;
loc_8813EA7C:
	// lwz r11,6936(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6936);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8813eb2c
	if (ctx.cr6.eq) goto loc_8813EB2C;
	// addi r31,r30,20
	ctx.r31.s64 = ctx.r30.s64 + 20;
	// li r27,40
	ctx.r27.s64 = 40;
loc_8813EA90:
	// lbz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8813eb20
	if (ctx.cr6.eq) goto loc_8813EB20;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bgt cr6,0x8813eab8
	if (ctx.cr6.gt) goto loc_8813EAB8;
	// lwz r11,140(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8813EAB8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8813EAB8:
	// lwz r11,140(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8813EAC8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8813eb20
	if (!ctx.cr6.eq) goto loc_8813EB20;
	// lwz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// stb r28,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r28.u8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8813eb00
	if (ctx.cr6.eq) goto loc_8813EB00;
	// lwz r11,-104(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -104);
	// cmpwi cr6,r11,3000
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3000, ctx.xer);
	// bge cr6,0x8813eb00
	if (!ctx.cr6.lt) goto loc_8813EB00;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r28,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r28.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-104(r29)
	PPC_STORE_U32(ctx.r29.u32 + -104, ctx.r11.u32);
	// stwx r10,r9,r29
	PPC_STORE_U32(ctx.r9.u32 + ctx.r29.u32, ctx.r10.u32);
loc_8813EB00:
	// lbz r11,3(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 3);
	// rotlwi r11,r11,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// lwzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r30.u32);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stwx r10,r11,r30
	PPC_STORE_U32(ctx.r11.u32 + ctx.r30.u32, ctx.r10.u32);
	// lwz r11,6936(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6936);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// stw r9,6936(r30)
	PPC_STORE_U32(ctx.r30.u32 + 6936, ctx.r9.u32);
loc_8813EB20:
	// addi r31,r31,164
	ctx.r31.s64 = ctx.r31.s64 + 164;
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// bne 0x8813ea90
	if (!ctx.cr0.eq) goto loc_8813EA90;
loc_8813EB2C:
	// addi r30,r30,6940
	ctx.r30.s64 = ctx.r30.s64 + 6940;
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne 0x8813ea7c
	if (!ctx.cr0.eq) goto loc_8813EA7C;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8813EB40"))) PPC_WEAK_FUNC(sub_8813EB40);
PPC_FUNC_IMPL(__imp__sub_8813EB40) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x8813EB48;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,76(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmpwi cr6,r11,256
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 256, ctx.xer);
	// blt cr6,0x8813eb64
	if (ctx.cr6.lt) goto loc_8813EB64;
	// li r29,1
	ctx.r29.s64 = 1;
loc_8813EB64:
	// lwz r28,32(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r6,151
	ctx.r6.s64 = 151;
	// lwz r27,36(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lhz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r31.u32 + 56);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// bl 0x881538c0
	ctx.lr = 0x8813EB80;
	sub_881538C0(ctx, base);
	// lis r30,-30597
	ctx.r30.s64 = -2005204992;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813ebb4
	if (ctx.cr6.eq) goto loc_8813EBB4;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r29,26,0,5
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 26) & 0xFC000000;
	// lwz r11,-11932(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -11932);
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// addi r29,r11,1
	ctx.r29.s64 = ctx.r11.s64 + 1;
	// oris r7,r8,531
	ctx.r7.u64 = ctx.r8.u64 | 34799616;
	// stw r29,-11932(r30)
	PPC_STORE_U32(ctx.r30.u32 + -11932, ctx.r29.u32);
	// ori r7,r7,32768
	ctx.r7.u64 = ctx.r7.u64 | 32768;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// b 0x8813ebb8
	goto loc_8813EBB8;
loc_8813EBB4:
	// lwz r29,-11932(r30)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r30.u32 + -11932);
loc_8813EBB8:
	// lbz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 4);
	// li r6,151
	ctx.r6.s64 = 151;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r11,403
	ctx.r3.s64 = ctx.r11.s64 + 403;
	// bl 0x881538c0
	ctx.lr = 0x8813EBD0;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813ebfc
	if (ctx.cr6.eq) goto loc_8813EBFC;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,96
	ctx.r9.s64 = 6291456;
	// addi r11,r29,1
	ctx.r11.s64 = ctx.r29.s64 + 1;
	// oris r7,r10,545
	ctx.r7.u64 = ctx.r10.u64 | 35717120;
	// ori r8,r9,32800
	ctx.r8.u64 = ctx.r9.u64 | 32800;
	// stw r11,-11932(r30)
	PPC_STORE_U32(ctx.r30.u32 + -11932, ctx.r11.u32);
	// ori r7,r7,32768
	ctx.r7.u64 = ctx.r7.u64 | 32768;
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
loc_8813EBFC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8813EC04"))) PPC_WEAK_FUNC(sub_8813EC04);
PPC_FUNC_IMPL(__imp__sub_8813EC04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8813EC08"))) PPC_WEAK_FUNC(sub_8813EC08);
PPC_FUNC_IMPL(__imp__sub_8813EC08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071134
	ctx.lr = 0x8813EC10;
	__savegprlr_19(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r10,2(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r30,r11,4200
	ctx.r30.s64 = ctx.r11.s64 + 4200;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8813ee50
	if (!ctx.cr6.eq) goto loc_8813EE50;
	// lwz r11,128(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8813ec5c
	if (ctx.cr6.eq) goto loc_8813EC5C;
loc_8813EC44:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8813ec5c
	if (ctx.cr6.eq) goto loc_8813EC5C;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813ec44
	if (!ctx.cr6.eq) goto loc_8813EC44;
loc_8813EC5C:
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r29,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r29.u32);
	// lbz r9,5(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 5);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stb r10,2(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2, ctx.r10.u8);
	// beq cr6,0x8813ec88
	if (ctx.cr6.eq) goto loc_8813EC88;
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// srawi r10,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 1;
	// addze r9,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r9.s64 = temp.s64;
	// stw r9,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r9.u32);
	// b 0x8813ecc4
	goto loc_8813ECC4;
loc_8813EC88:
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// addi r7,r11,256
	ctx.r7.s64 = ctx.r11.s64 + 256;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// srawi r6,r10,3
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7) != 0);
	ctx.r6.s64 = ctx.r10.s32 >> 3;
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addze r5,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r5.s64 = temp.s64;
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r7,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r7.u32);
	// add r3,r8,r9
	ctx.r3.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stw r5,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r5.u32);
	// stw r4,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r4.u32);
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
loc_8813ECC4:
	// lis r11,16838
	ctx.r11.s64 = 1103495168;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lis r9,-13108
	ctx.r9.s64 = -859045888;
	// lwz r5,76(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// ori r11,r11,20077
	ctx.r11.u64 = ctx.r11.u64 | 20077;
	// lwz r26,68(r31)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// ori r8,r9,52429
	ctx.r8.u64 = ctx.r9.u64 | 52429;
	// lwz r28,8(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// lwz r27,12(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r10,12345
	ctx.r10.s64 = ctx.r10.s64 + 12345;
	// lis r7,20971
	ctx.r7.s64 = 1374355456;
	// stw r10,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// addi r10,r10,12345
	ctx.r10.s64 = ctx.r10.s64 + 12345;
	// lis r3,14563
	ctx.r3.s64 = 954400768;
	// mullw r9,r10,r11
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// lhz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r30.u32 + 0);
	// stw r10,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// mulhwu r11,r4,r8
	ctx.r11.u64 = (uint64_t(ctx.r4.u32) * uint64_t(ctx.r8.u32)) >> 32;
	// rlwinm r11,r11,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// addi r9,r9,12345
	ctx.r9.s64 = ctx.r9.s64 + 12345;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// ori r6,r7,34079
	ctx.r6.u64 = ctx.r7.u64 | 34079;
	// lhz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r30.u32 + 0);
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stw r9,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r9.u32);
	// ori r7,r3,36409
	ctx.r7.u64 = ctx.r3.u64 | 36409;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// mulhwu r10,r10,r6
	ctx.r10.u64 = (uint64_t(ctx.r10.u32) * uint64_t(ctx.r6.u32)) >> 32;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r10,29,3,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFFFFFF;
	// subf r10,r9,r4
	ctx.r10.s64 = ctx.r4.s64 - ctx.r9.s64;
	// mulli r9,r8,25
	ctx.r9.s64 = ctx.r8.s64 * 25;
	// lhz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r30.u32 + 0);
	// extsh r11,r10
	ctx.r11.s64 = ctx.r10.s16;
	// mulhwu r7,r6,r7
	ctx.r7.u64 = (uint64_t(ctx.r6.u32) * uint64_t(ctx.r7.u32)) >> 32;
	// addi r8,r11,-4
	ctx.r8.s64 = ctx.r11.s64 + -4;
	// lis r4,-30714
	ctx.r4.s64 = -2012872704;
	// rlwinm r11,r8,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r8,-30667
	ctx.r8.s64 = -2009792512;
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// subf r3,r9,r3
	ctx.r3.s64 = ctx.r3.s64 - ctx.r9.s64;
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// rlwinm r10,r7,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r25,r11,2,0,29
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,128
	ctx.r9.s64 = ctx.r11.s64 + 128;
	// addi r4,r4,9552
	ctx.r4.s64 = ctx.r4.s64 + 9552;
	// li r11,1
	ctx.r11.s64 = 1;
	// rlwinm r7,r10,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r9,r9,2,21,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x7FC;
	// stw r11,12380(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12380, ctx.r11.u32);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lwzx r25,r25,r4
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r25.u32 + ctx.r4.u32);
	// lis r3,-30667
	ctx.r3.s64 = -2009792512;
	// lis r10,-30667
	ctx.r10.s64 = -2009792512;
	// lis r24,-30667
	ctx.r24.s64 = -2009792512;
	// lwzx r23,r9,r4
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r4.u32);
	// addi r11,r11,-12
	ctx.r11.s64 = ctx.r11.s64 + -12;
	// stb r29,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r29.u8);
	// subf r7,r7,r6
	ctx.r7.s64 = ctx.r6.s64 - ctx.r7.s64;
	// stb r29,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r29.u8);
	// li r4,3
	ctx.r4.s64 = 3;
	// stw r5,12368(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12368, ctx.r5.u32);
	// li r9,153
	ctx.r9.s64 = 153;
	// stb r29,113(r31)
	PPC_STORE_U8(ctx.r31.u32 + 113, ctx.r29.u8);
	// li r8,64
	ctx.r8.s64 = 64;
	// stb r4,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r4.u8);
	// mullw r6,r25,r26
	ctx.r6.s64 = int64_t(ctx.r25.s32) * int64_t(ctx.r26.s32);
	// stw r9,12376(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12376, ctx.r9.u32);
	// stw r8,12384(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12384, ctx.r8.u32);
	// stw r6,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r6.u32);
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// li r6,64
	ctx.r6.s64 = 64;
	// li r4,153
	ctx.r4.s64 = 153;
	// li r3,1
	ctx.r3.s64 = 1;
	// rlwinm r10,r7,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// lis r9,-30667
	ctx.r9.s64 = -2009792512;
	// lis r8,-30667
	ctx.r8.s64 = -2009792512;
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// add r10,r10,r27
	ctx.r10.u64 = ctx.r10.u64 + ctx.r27.u64;
	// stw r11,12364(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12364, ctx.r11.u32);
	// mullw r7,r23,r26
	ctx.r7.s64 = int64_t(ctx.r23.s32) * int64_t(ctx.r26.s32);
	// stw r10,12372(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12372, ctx.r10.u32);
	// stw r7,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r7.u32);
	// bl 0x880f83f8
	ctx.lr = 0x8813EE20;
	sub_880F83F8(ctx, base);
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// lwz r10,-19568(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -19568);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8813ee50
	if (!ctx.cr6.eq) goto loc_8813EE50;
	// lbz r9,1(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// li r10,3
	ctx.r10.s64 = 3;
	// li r6,17
	ctx.r6.s64 = 17;
	// li r5,44
	ctx.r5.s64 = 44;
	// stw r10,-19568(r11)
	PPC_STORE_U32(ctx.r11.u32 + -19568, ctx.r10.u32);
	// li r4,74
	ctx.r4.s64 = 74;
	// addi r3,r9,3
	ctx.r3.s64 = ctx.r9.s64 + 3;
	// bl 0x880e3240
	ctx.lr = 0x8813EE50;
	sub_880E3240(ctx, base);
loc_8813EE50:
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r7,r30,-22720
	ctx.r7.s64 = ctx.r30.s64 + -22720;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r6,152
	ctx.r6.s64 = 152;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// add r27,r11,r10
	ctx.r27.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r5,120(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// add r28,r9,r8
	ctx.r28.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lbz r4,110(r31)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r31.u32 + 110);
	// stw r27,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r27.u32);
	// rlwinm r3,r5,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r28,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r28.u32);
	// extsb r10,r4
	ctx.r10.s64 = ctx.r4.s8;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lhzx r11,r3,r7
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + ctx.r7.u32);
	// add r25,r11,r10
	ctx.r25.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x881538c0
	ctx.lr = 0x8813EEA0;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813eeb4
	if (ctx.cr6.eq) goto loc_8813EEB4;
	// lis r11,160
	ctx.r11.s64 = 10485760;
	// ori r10,r11,33023
	ctx.r10.u64 = ctx.r11.u64 | 33023;
	// stw r10,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r10.u32);
loc_8813EEB4:
	// lbz r11,5(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 5);
	// lis r23,192
	ctx.r23.s64 = 12582912;
	// lis r20,128
	ctx.r20.s64 = 8388608;
	// li r26,128
	ctx.r26.s64 = 128;
	// li r22,24
	ctx.r22.s64 = 24;
	// lis r21,8
	ctx.r21.s64 = 524288;
	// ori r23,r23,32991
	ctx.r23.u64 = ctx.r23.u64 | 32991;
	// ori r20,r20,8192
	ctx.r20.u64 = ctx.r20.u64 | 8192;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813eef8
	if (!ctx.cr6.eq) goto loc_8813EEF8;
	// lis r23,8
	ctx.r23.s64 = 524288;
	// lis r20,32
	ctx.r20.s64 = 2097152;
	// li r26,8
	ctx.r26.s64 = 8;
	// mr r21,r29
	ctx.r21.u64 = ctx.r29.u64;
	// li r22,2
	ctx.r22.s64 = 2;
	// ori r23,r23,2056
	ctx.r23.u64 = ctx.r23.u64 | 2056;
	// ori r20,r20,32864
	ctx.r20.u64 = ctx.r20.u64 | 32864;
loc_8813EEF8:
	// lis r19,-30597
	ctx.r19.s64 = -2005204992;
	// li r30,1
	ctx.r30.s64 = 1;
	// lwz r24,-11932(r19)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r19.u32 + -11932);
loc_8813EF04:
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// li r6,152
	ctx.r6.s64 = 152;
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// mullw r10,r11,r30
	ctx.r10.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// mullw r11,r30,r9
	ctx.r11.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r9.s32);
	// add r5,r10,r27
	ctx.r5.u64 = ctx.r10.u64 + ctx.r27.u64;
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + ctx.r28.u64;
	// clrlwi r29,r30,31
	ctx.r29.u64 = ctx.r30.u32 & 0x1;
	// bl 0x881538c0
	ctx.lr = 0x8813EF2C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813ef5c
	if (ctx.cr6.eq) goto loc_8813EF5C;
	// rlwinm r11,r29,18,0,13
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 18) & 0xFFFC0000;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r26,24
	ctx.r9.u64 = ctx.r26.u32 & 0xFF;
	// stw r23,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r23.u32);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// or r8,r11,r9
	ctx.r8.u64 = ctx.r11.u64 | ctx.r9.u64;
	// rlwinm r7,r8,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// oris r6,r7,531
	ctx.r6.u64 = ctx.r7.u64 | 34799616;
	// or r5,r6,r10
	ctx.r5.u64 = ctx.r6.u64 | ctx.r10.u64;
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
loc_8813EF5C:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// subf r26,r22,r26
	ctx.r26.s64 = ctx.r26.s64 - ctx.r22.s64;
	// cmpwi cr6,r30,3
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 3, ctx.xer);
	// blt cr6,0x8813ef04
	if (ctx.cr6.lt) goto loc_8813EF04;
	// li r6,153
	ctx.r6.s64 = 153;
	// stw r24,-11932(r19)
	PPC_STORE_U32(ctx.r19.u32 + -11932, ctx.r24.u32);
	// add r5,r21,r27
	ctx.r5.u64 = ctx.r21.u64 + ctx.r27.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r3,407
	ctx.r3.s64 = 407;
	// bl 0x881538c0
	ctx.lr = 0x8813EF84;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813efa8
	if (ctx.cr6.eq) goto loc_8813EFA8;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r11,r24,1
	ctx.r11.s64 = ctx.r24.s64 + 1;
	// stw r20,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r20.u32);
	// oris r9,r10,545
	ctx.r9.u64 = ctx.r10.u64 | 35717120;
	// stw r11,-11932(r19)
	PPC_STORE_U32(ctx.r19.u32 + -11932, ctx.r11.u32);
	// ori r9,r9,32768
	ctx.r9.u64 = ctx.r9.u64 | 32768;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_8813EFA8:
	// lbz r11,112(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 112);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r9.u8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge cr6,0x8813efe4
	if (!ctx.cr6.lt) goto loc_8813EFE4;
	// lbz r11,110(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 110);
	// li r3,0
	ctx.r3.s64 = 0;
	// lbz r10,113(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 113);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// stb r10,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r10.u8);
	// cmpwi cr6,r8,8
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 8, ctx.xer);
	// stb r8,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r8.u8);
	// bge cr6,0x8813efe8
	if (!ctx.cr6.lt) goto loc_8813EFE8;
loc_8813EFE4:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8813EFE8:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x88071184
	__restgprlr_19(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8813EFF0"))) PPC_WEAK_FUNC(sub_8813EFF0);
PPC_FUNC_IMPL(__imp__sub_8813EFF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071130
	ctx.lr = 0x8813EFF8;
	__savegprlr_18(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r10,2(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// lwz r29,160(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r27,1
	ctx.r27.s64 = 1;
	// addi r28,r11,-17720
	ctx.r28.s64 = ctx.r11.s64 + -17720;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8813f0c8
	if (!ctx.cr6.eq) goto loc_8813F0C8;
	// lwz r9,128(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// lwz r11,28(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8813f044
	if (ctx.cr6.eq) goto loc_8813F044;
loc_8813F02C:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8813f0b0
	if (ctx.cr6.eq) goto loc_8813F0B0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813f02c
	if (!ctx.cr6.eq) goto loc_8813F02C;
loc_8813F044:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8813F048:
	// addi r30,r31,8
	ctx.r30.s64 = ctx.r31.s64 + 8;
	// addi r9,r28,848
	ctx.r9.s64 = ctx.r28.s64 + 848;
	// stw r30,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r30.u32);
	// li r8,2
	ctx.r8.s64 = 2;
	// lwz r7,128(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// stw r27,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r27.u32);
	// lbz r6,3(r31)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r31.u32 + 3);
	// lbz r5,4(r31)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r31.u32 + 4);
	// rotlwi r4,r5,2
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// rotlwi r10,r6,3
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r6.u32, 3);
	// lwzx r9,r4,r9
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r9.u32);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r3,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r3.u32);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r9.u32);
	// lwz r7,4(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r7,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r7.u32);
	// lwz r6,4(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r6,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r6.u32);
	// lwz r5,88(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// stw r5,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r5.u32);
	// stb r27,2(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2, ctx.r27.u8);
	// stb r8,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r8.u8);
	// stb r8,5(r31)
	PPC_STORE_U8(ctx.r31.u32 + 5, ctx.r8.u8);
	// b 0x8813f0ec
	goto loc_8813F0EC;
loc_8813F0B0:
	// lwz r10,24(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8813f0c0
	if (ctx.cr6.eq) goto loc_8813F0C0;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_8813F0C0:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x8813f048
	goto loc_8813F048;
loc_8813F0C8:
	// lbz r10,1(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// lis r9,-30651
	ctx.r9.s64 = -2008743936;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r30,r31,8
	ctx.r30.s64 = ctx.r31.s64 + 8;
	// addi r8,r9,-8560
	ctx.r8.s64 = ctx.r9.s64 + -8560;
	// rotlwi r7,r10,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lwzx r10,r7,r8
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r6,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
loc_8813F0EC:
	// lbz r11,5(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 5);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8813f170
	if (ctx.cr6.eq) goto loc_8813F170;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x8813f118
	if (ctx.cr6.eq) goto loc_8813F118;
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r10,72(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r9,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r9.u32);
loc_8813F118:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8813eb40
	ctx.lr = 0x8813F120;
	sub_8813EB40(ctx, base);
	// lbz r11,5(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 5);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,5(r31)
	PPC_STORE_U8(ctx.r31.u32 + 5, ctx.r9.u8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bgt cr6,0x8813f170
	if (ctx.cr6.gt) goto loc_8813F170;
	// lwz r9,128(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,28(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8813f164
	if (ctx.cr6.eq) goto loc_8813F164;
loc_8813F14C:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8813f3e4
	if (ctx.cr6.eq) goto loc_8813F3E4;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813f14c
	if (!ctx.cr6.eq) goto loc_8813F14C;
loc_8813F164:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8813F168:
	// lwz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// stw r10,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r10.u32);
loc_8813F170:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lis r7,360
	ctx.r7.s64 = 23592960;
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// add r25,r10,r11
	ctx.r25.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r26,r8,r9
	ctx.r26.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stw r25,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r25.u32);
	// stw r26,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r26.u32);
	// cmpw cr6,r26,r7
	ctx.cr6.compare<int32_t>(ctx.r26.s32, ctx.r7.s32, ctx.xer);
	// bge cr6,0x8813f5d4
	if (!ctx.cr6.lt) goto loc_8813F5D4;
	// lis r11,280
	ctx.r11.s64 = 18350080;
	// cmpw cr6,r25,r11
	ctx.cr6.compare<int32_t>(ctx.r25.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x8813f5d4
	if (!ctx.cr6.lt) goto loc_8813F5D4;
	// lis r11,-40
	ctx.r11.s64 = -2621440;
	// cmpw cr6,r25,r11
	ctx.cr6.compare<int32_t>(ctx.r25.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x8813f5d4
	if (!ctx.cr6.gt) goto loc_8813F5D4;
	// lbz r11,112(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 112);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r9.u8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge cr6,0x8813f1f4
	if (!ctx.cr6.lt) goto loc_8813F1F4;
	// lbz r11,110(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 110);
	// lbz r10,113(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 113);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// stb r10,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r10.u8);
	// cmpwi cr6,r8,3
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 3, ctx.xer);
	// stb r8,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r8.u8);
	// blt cr6,0x8813f1f4
	if (ctx.cr6.lt) goto loc_8813F1F4;
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r11.u8);
loc_8813F1F4:
	// lwz r11,120(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// addi r9,r28,-752
	ctx.r9.s64 = ctx.r28.s64 + -752;
	// lbz r8,110(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 110);
	// li r18,0
	ctx.r18.s64 = 0;
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r6,76(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// extsb r10,r8
	ctx.r10.s64 = ctx.r8.s8;
	// cmpwi cr6,r6,256
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 256, ctx.xer);
	// lhzx r11,r7,r9
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + ctx.r9.u32);
	// add r30,r11,r10
	ctx.r30.u64 = ctx.r11.u64 + ctx.r10.u64;
	// blt cr6,0x8813f224
	if (ctx.cr6.lt) goto loc_8813F224;
	// mr r18,r27
	ctx.r18.u64 = ctx.r27.u64;
loc_8813F224:
	// lhz r11,2(r29)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r29.u32 + 2);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8813f530
	if (!ctx.cr6.eq) goto loc_8813F530;
	// lhz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r29.u32 + 0);
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// cmpwi cr6,r10,128
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 128, ctx.xer);
	// bge cr6,0x8813f278
	if (!ctx.cr6.lt) goto loc_8813F278;
	// lbz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 4);
	// addi r11,r28,48
	ctx.r11.s64 = ctx.r28.s64 + 48;
	// lhz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r29.u32 + 0);
	// rotlwi r8,r10,3
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 3);
	// addi r7,r11,4
	ctx.r7.s64 = ctx.r11.s64 + 4;
	// lwzx r11,r8,r7
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// add r6,r11,r9
	ctx.r6.u64 = ctx.r11.u64 + ctx.r9.u64;
	// extsh r5,r6
	ctx.r5.s64 = ctx.r6.s16;
	// sth r5,0(r29)
	PPC_STORE_U16(ctx.r29.u32 + 0, ctx.r5.u16);
	// cmpwi cr6,r5,128
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 128, ctx.xer);
	// ble cr6,0x8813f278
	if (!ctx.cr6.gt) goto loc_8813F278;
	// li r11,128
	ctx.r11.s64 = 128;
	// sth r11,0(r29)
	PPC_STORE_U16(ctx.r29.u32 + 0, ctx.r11.u16);
loc_8813F278:
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// lhz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r29.u32 + 0);
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// extsh r7,r9
	ctx.r7.s64 = ctx.r9.s16;
	// addi r29,r11,9552
	ctx.r29.s64 = ctx.r11.s64 + 9552;
	// lwz r11,26428(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26428);
	// clrlwi r8,r11,31
	ctx.r8.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8813f340
	if (ctx.cr6.eq) goto loc_8813F340;
	// lwz r9,128(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,28(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8813f2c8
	if (ctx.cr6.eq) goto loc_8813F2C8;
loc_8813F2B0:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8813f3fc
	if (ctx.cr6.eq) goto loc_8813F3FC;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813f2b0
	if (!ctx.cr6.eq) goto loc_8813F2B0;
loc_8813F2C8:
	// li r9,0
	ctx.r9.s64 = 0;
loc_8813F2CC:
	// lwz r11,120(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// addi r8,r28,880
	ctx.r8.s64 = ctx.r28.s64 + 880;
	// lbz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r31.u32 + 4);
	// rlwinm r5,r7,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x7FC;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r3,3(r31)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r31.u32 + 3);
	// rotlwi r6,r6,2
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r6.u32, 2);
	// addi r11,r28,848
	ctx.r11.s64 = ctx.r28.s64 + 848;
	// rotlwi r10,r3,3
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r3.u32, 3);
	// lwzx r5,r5,r29
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r29.u32);
	// lwzx r4,r4,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r8.u32);
	// lwzx r11,r6,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r11.u32);
	// mullw r3,r5,r4
	ctx.r3.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r4.s32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r10,r3,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// srawi r6,r10,16
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xFFFF) != 0);
	ctx.r6.s64 = ctx.r10.s32 >> 16;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addze r10,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r10.s64 = temp.s64;
	// add r5,r8,r10
	ctx.r5.u64 = ctx.r8.u64 + ctx.r10.u64;
	// stw r5,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r5.u32);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// add r4,r8,r10
	ctx.r4.u64 = ctx.r8.u64 + ctx.r10.u64;
	// stw r4,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r4.u32);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// add r3,r8,r10
	ctx.r3.u64 = ctx.r8.u64 + ctx.r10.u64;
	// stw r3,16(r9)
	PPC_STORE_U32(ctx.r9.u32 + 16, ctx.r3.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r11,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r11.u32);
loc_8813F340:
	// lwz r10,120(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// addi r11,r28,-96
	ctx.r11.s64 = ctx.r28.s64 + -96;
	// addi r9,r28,-96
	ctx.r9.s64 = ctx.r28.s64 + -96;
	// lwz r8,76(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// rlwinm r6,r10,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r5,r11,4
	ctx.r5.s64 = ctx.r11.s64 + 4;
	// rlwinm r4,r10,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r8,256
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 256, ctx.xer);
	// lwzx r30,r6,r9
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// lwzx r11,r6,r5
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r5.u32);
	// lwzx r28,r4,r28
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r28.u32);
	// ble cr6,0x8813f374
	if (!ctx.cr6.gt) goto loc_8813F374;
	// subfic r28,r28,512
	ctx.xer.ca = ctx.r28.u32 <= 512;
	ctx.r28.s64 = 512 - ctx.r28.s64;
loc_8813F374:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8813f5c8
	if (!ctx.cr6.gt) goto loc_8813F5C8;
	// lis r19,-30597
	ctx.r19.s64 = -2005204992;
	// mr r20,r11
	ctx.r20.u64 = ctx.r11.u64;
	// lis r11,160
	ctx.r11.s64 = 10485760;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lis r9,64
	ctx.r9.s64 = 4194304;
	// lwz r27,-11932(r19)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r19.u32 + -11932);
	// rlwinm r21,r7,2,21,29
	ctx.r21.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x7FC;
	// ori r24,r11,33023
	ctx.r24.u64 = ctx.r11.u64 | 33023;
	// ori r22,r10,32768
	ctx.r22.u64 = ctx.r10.u64 | 32768;
	// ori r23,r9,16512
	ctx.r23.u64 = ctx.r9.u64 | 16512;
loc_8813F3A4:
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// lwzx r11,r21,r29
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r21.u32 + ctx.r29.u32);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// mullw r10,r9,r11
	ctx.r10.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// rlwinm r11,r10,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// ble cr6,0x8813f414
	if (!ctx.cr6.gt) goto loc_8813F414;
	// addi r10,r28,160
	ctx.r10.s64 = ctx.r28.s64 + 160;
	// rlwinm r8,r11,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// clrlwi r11,r10,23
	ctx.r11.u64 = ctx.r10.u32 & 0x1FF;
	// srawi r7,r8,16
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFF) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 16;
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r11,128
	ctx.r6.s64 = ctx.r11.s64 + 128;
	// addze r11,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r11.s64 = temp.s64;
	// lwzx r3,r5,r29
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r29.u32);
	// mullw r10,r3,r11
	ctx.r10.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r11.s32);
	// b 0x8813f43c
	goto loc_8813F43C;
loc_8813F3E4:
	// lwz r10,24(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8813f3f4
	if (ctx.cr6.eq) goto loc_8813F3F4;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_8813F3F4:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x8813f168
	goto loc_8813F168;
loc_8813F3FC:
	// lwz r10,24(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8813f40c
	if (ctx.cr6.eq) goto loc_8813F40C;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_8813F40C:
	// addi r9,r11,24
	ctx.r9.s64 = ctx.r11.s64 + 24;
	// b 0x8813f2cc
	goto loc_8813F2CC;
loc_8813F414:
	// addi r10,r28,-160
	ctx.r10.s64 = ctx.r28.s64 + -160;
	// neg r8,r11
	ctx.r8.s64 = -ctx.r11.s64;
	// clrlwi r11,r10,23
	ctx.r11.u64 = ctx.r10.u32 & 0x1FF;
	// rlwinm r7,r8,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// srawi r3,r7,16
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFFFF) != 0);
	ctx.r3.s64 = ctx.r7.s32 >> 16;
	// addi r6,r11,128
	ctx.r6.s64 = ctx.r11.s64 + 128;
	// addze r11,r3
	temp.s64 = ctx.r3.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r11.s64 = temp.s64;
	// lwzx r10,r5,r29
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r29.u32);
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
loc_8813F43C:
	// rlwinm r4,r6,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// li r6,150
	ctx.r6.s64 = 150;
	// lwzx r8,r4,r29
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r29.u32);
	// mullw r11,r8,r11
	ctx.r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r11.s32);
	// beq cr6,0x8813f490
	if (ctx.cr6.eq) goto loc_8813F490;
	// lbz r8,110(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 110);
	// add r5,r11,r26
	ctx.r5.u64 = ctx.r11.u64 + ctx.r26.u64;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// add r4,r10,r25
	ctx.r4.u64 = ctx.r10.u64 + ctx.r25.u64;
	// extsb r11,r8
	ctx.r11.s64 = ctx.r8.s8;
	// add r3,r11,r9
	ctx.r3.u64 = ctx.r11.u64 + ctx.r9.u64;
	// bl 0x881538c0
	ctx.lr = 0x8813F470;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813f514
	if (ctx.cr6.eq) goto loc_8813F514;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r18,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 26) & 0xFC000000;
	// stw r24,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r24.u32);
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// b 0x8813f514
	goto loc_8813F514;
loc_8813F490:
	// lbz r11,110(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 110);
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x8813F4AC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813f4c8
	if (ctx.cr6.eq) goto loc_8813F4C8;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r18,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 26) & 0xFC000000;
	// stw r24,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r24.u32);
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_8813F4C8:
	// lbz r11,110(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 110);
	// li r6,150
	ctx.r6.s64 = 150;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r5,r9,r26
	ctx.r5.s64 = ctx.r26.s64 - ctx.r9.s64;
	// subf r4,r8,r25
	ctx.r4.s64 = ctx.r25.s64 - ctx.r8.s64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x8813F4F0;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813f514
	if (ctx.cr6.eq) goto loc_8813F514;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r18,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 26) & 0xFC000000;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// stw r23,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r23.u32);
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// or r8,r9,r22
	ctx.r8.u64 = ctx.r9.u64 | ctx.r22.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_8813F514:
	// addic. r20,r20,-1
	ctx.xer.ca = ctx.r20.u32 > 0;
	ctx.r20.s64 = ctx.r20.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// bne 0x8813f3a4
	if (!ctx.cr0.eq) goto loc_8813F3A4;
	// stw r27,-11932(r19)
	PPC_STORE_U32(ctx.r19.u32 + -11932, ctx.r27.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x88071180
	__restgprlr_18(ctx, base);
	return;
loc_8813F530:
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// li r6,150
	ctx.r6.s64 = 150;
	// sth r11,2(r29)
	PPC_STORE_U16(ctx.r29.u32 + 2, ctx.r11.u16);
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x881538c0
	ctx.lr = 0x8813F54C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813f570
	if (ctx.cr6.eq) goto loc_8813F570;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r18,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 26) & 0xFC000000;
	// lis r9,160
	ctx.r9.s64 = 10485760;
	// or r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 | ctx.r11.u64;
	// ori r7,r9,33023
	ctx.r7.u64 = ctx.r9.u64 | 33023;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stw r7,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r7.u32);
loc_8813F570:
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// li r6,150
	ctx.r6.s64 = 150;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// subf r5,r11,r26
	ctx.r5.s64 = ctx.r26.s64 - ctx.r11.s64;
	// subf r4,r10,r25
	ctx.r4.s64 = ctx.r25.s64 - ctx.r10.s64;
	// bl 0x881538c0
	ctx.lr = 0x8813F58C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813f5c8
	if (ctx.cr6.eq) goto loc_8813F5C8;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// rlwinm r8,r18,26,0,5
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 26) & 0xFC000000;
	// lis r7,64
	ctx.r7.s64 = 4194304;
	// or r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 | ctx.r9.u64;
	// ori r5,r7,16512
	ctx.r5.u64 = ctx.r7.u64 | 16512;
	// lwz r11,-11932(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11932);
	// oris r4,r6,545
	ctx.r4.u64 = ctx.r6.u64 | 35717120;
	// stw r5,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r5.u32);
	// ori r4,r4,32768
	ctx.r4.u64 = ctx.r4.u64 | 32768;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stw r11,-11932(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11932, ctx.r11.u32);
loc_8813F5C8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x88071180
	__restgprlr_18(ctx, base);
	return;
loc_8813F5D4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x88071180
	__restgprlr_18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8813F5E0"))) PPC_WEAK_FUNC(sub_8813F5E0);
PPC_FUNC_IMPL(__imp__sub_8813F5E0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,0(r5)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x8813f66c
	if (!ctx.cr6.eq) goto loc_8813F66C;
	// lbz r5,4(r5)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r5.u32 + 4);
	// lwz r4,100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// bl 0x88147a30
	ctx.lr = 0x8813F614;
	sub_88147A30(ctx, base);
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// subf. r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r9,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r9.u32);
	// bgt 0x8813f66c
	if (ctx.cr0.gt) goto loc_8813F66C;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8813f658
	if (ctx.cr6.eq) goto loc_8813F658;
loc_8813F640:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8813f658
	if (ctx.cr6.eq) goto loc_8813F658;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813f640
	if (!ctx.cr6.eq) goto loc_8813F640;
loc_8813F658:
	// lis r10,-30700
	ctx.r10.s64 = -2011955200;
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// stb r9,2(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2, ctx.r9.u8);
	// addi r9,r10,-5112
	ctx.r9.s64 = ctx.r10.s64 + -5112;
	// stw r9,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r9.u32);
loc_8813F66C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813F688"))) PPC_WEAK_FUNC(sub_8813F688);
PPC_FUNC_IMPL(__imp__sub_8813F688) {
	PPC_FUNC_PROLOGUE();
	// lwz r8,120(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// lis r7,-30671
	ctx.r7.s64 = -2010054656;
	// lwz r4,12(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r6,8(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r5,-30700
	ctx.r5.s64 = -2011955200;
	// addi r10,r7,-18496
	ctx.r10.s64 = ctx.r7.s64 + -18496;
	// lbz r7,114(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 114);
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r5,r5,-4112
	ctx.r5.s64 = ctx.r5.s64 + -4112;
	// stw r4,36(r9)
	PPC_STORE_U32(ctx.r9.u32 + 36, ctx.r4.u32);
	// extsb r11,r7
	ctx.r11.s64 = ctx.r7.s8;
	// stb r3,2(r9)
	PPC_STORE_U8(ctx.r9.u32 + 2, ctx.r3.u8);
	// stw r5,140(r9)
	PPC_STORE_U32(ctx.r9.u32 + 140, ctx.r5.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r6,32(r9)
	PPC_STORE_U32(ctx.r9.u32 + 32, ctx.r6.u32);
	// lhzx r10,r8,r10
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r8.u32 + ctx.r10.u32);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// sth r4,56(r9)
	PPC_STORE_U16(ctx.r9.u32 + 56, ctx.r4.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813F6DC"))) PPC_WEAK_FUNC(sub_8813F6DC);
PPC_FUNC_IMPL(__imp__sub_8813F6DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8813F6E0"))) PPC_WEAK_FUNC(sub_8813F6E0);
PPC_FUNC_IMPL(__imp__sub_8813F6E0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071120
	ctx.lr = 0x8813F6E8;
	__savegprlr_14(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lhz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// addi r23,r11,-17672
	ctx.r23.s64 = ctx.r11.s64 + -17672;
	// extsh r16,r9
	ctx.r16.s64 = ctx.r9.s16;
	// addi r6,r23,1008
	ctx.r6.s64 = ctx.r23.s64 + 1008;
	// lbz r5,1(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// lis r8,-30649
	ctx.r8.s64 = -2008612864;
	// addi r4,r23,976
	ctx.r4.s64 = ctx.r23.s64 + 976;
	// extsb r14,r5
	ctx.r14.s64 = ctx.r5.s8;
	// rlwinm r7,r16,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// lbzx r3,r16,r6
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r16.u32 + ctx.r6.u32);
	// li r22,0
	ctx.r22.s64 = 0;
	// addi r11,r8,24584
	ctx.r11.s64 = ctx.r8.s64 + 24584;
	// extsb r31,r3
	ctx.r31.s64 = ctx.r3.s8;
	// mulli r10,r14,6940
	ctx.r10.s64 = ctx.r14.s64 * 6940;
	// lwzx r24,r7,r4
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r4.u32);
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// add r30,r10,r11
	ctx.r30.u64 = ctx.r10.u64 + ctx.r11.u64;
	// mr r6,r22
	ctx.r6.u64 = ctx.r22.u64;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// ble cr6,0x8813f768
	if (!ctx.cr6.gt) goto loc_8813F768;
	// addi r11,r1,92
	ctx.r11.s64 = ctx.r1.s64 + 92;
	// li r10,-1
	ctx.r10.s64 = -1;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8813f768
	if (ctx.cr6.eq) goto loc_8813F768;
	// mtctr r31
	ctx.ctr.u64 = ctx.r31.u64;
loc_8813F760:
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8813f760
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8813F760;
loc_8813F768:
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// addi r10,r11,26432
	ctx.r10.s64 = ctx.r11.s64 + 26432;
	// addi r9,r24,2
	ctx.r9.s64 = ctx.r24.s64 + 2;
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// lwz r4,324(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 324);
loc_8813F780:
	// lwz r11,6900(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6900);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,6900(r30)
	PPC_STORE_U32(ctx.r30.u32 + 6900, ctx.r11.u32);
	// cmpwi cr6,r11,40
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 40, ctx.xer);
	// blt cr6,0x8813f798
	if (ctx.cr6.lt) goto loc_8813F798;
	// stw r22,6900(r30)
	PPC_STORE_U32(ctx.r30.u32 + 6900, ctx.r22.u32);
loc_8813F798:
	// lwz r10,6900(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6900);
	// mulli r11,r10,164
	ctx.r11.s64 = ctx.r10.s64 * 164;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// lbz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 20);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813f7f4
	if (!ctx.cr6.eq) goto loc_8813F7F4;
	// lhz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 0);
	// cmpwi cr6,r4,2
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 2, ctx.xer);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// bne cr6,0x8813f7cc
	if (!ctx.cr6.eq) goto loc_8813F7CC;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// blt cr6,0x8813f7cc
	if (ctx.cr6.lt) goto loc_8813F7CC;
	// li r11,4
	ctx.r11.s64 = 4;
loc_8813F7CC:
	// lwz r29,0(r8)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmpw cr6,r29,r11
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x8813f7dc
	if (!ctx.cr6.lt) goto loc_8813F7DC;
	// stw r10,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r10.u32);
loc_8813F7DC:
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmpw cr6,r6,r31
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r31.s32, ctx.xer);
	// bge cr6,0x8813f800
	if (!ctx.cr6.lt) goto loc_8813F800;
loc_8813F7F4:
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// cmpwi cr6,r3,40
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 40, ctx.xer);
	// blt cr6,0x8813f780
	if (ctx.cr6.lt) goto loc_8813F780;
loc_8813F800:
	// lwz r11,6924(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6924);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,6924(r30)
	PPC_STORE_U32(ctx.r30.u32 + 6924, ctx.r11.u32);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// blt cr6,0x8813f818
	if (ctx.cr6.lt) goto loc_8813F818;
	// stw r22,6924(r30)
	PPC_STORE_U32(ctx.r30.u32 + 6924, ctx.r22.u32);
loc_8813F818:
	// lwz r11,6928(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6928);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,6928(r30)
	PPC_STORE_U32(ctx.r30.u32 + 6928, ctx.r11.u32);
	// cmpwi cr6,r11,14
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 14, ctx.xer);
	// blt cr6,0x8813f830
	if (ctx.cr6.lt) goto loc_8813F830;
	// stw r22,6928(r30)
	PPC_STORE_U32(ctx.r30.u32 + 6928, ctx.r22.u32);
loc_8813F830:
	// lwz r11,6932(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6932);
	// addi r10,r23,256
	ctx.r10.s64 = ctx.r23.s64 + 256;
	// addi r9,r23,576
	ctx.r9.s64 = ctx.r23.s64 + 576;
	// addi r8,r23,-592
	ctx.r8.s64 = ctx.r23.s64 + -592;
	// addi r6,r11,-1
	ctx.r6.s64 = ctx.r11.s64 + -1;
	// addi r17,r1,96
	ctx.r17.s64 = ctx.r1.s64 + 96;
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// lwzx r28,r7,r10
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// lwzx r27,r7,r9
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// mr r21,r22
	ctx.r21.u64 = ctx.r22.u64;
	// lwzx r26,r7,r8
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// stw r5,6932(r30)
	PPC_STORE_U32(ctx.r30.u32 + 6932, ctx.r5.u32);
	// ble cr6,0x8813fa70
	if (!ctx.cr6.gt) goto loc_8813FA70;
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// addi r29,r30,6904
	ctx.r29.s64 = ctx.r30.s64 + 6904;
	// li r18,2
	ctx.r18.s64 = 2;
	// li r19,1
	ctx.r19.s64 = 1;
	// li r20,100
	ctx.r20.s64 = 100;
	// addi r15,r11,9552
	ctx.r15.s64 = ctx.r11.s64 + 9552;
loc_8813F880:
	// lwz r11,0(r17)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r17.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x8813fa4c
	if (ctx.cr6.lt) goto loc_8813FA4C;
	// mulli r11,r11,164
	ctx.r11.s64 = ctx.r11.s64 * 164;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r31,r11,20
	ctx.r31.s64 = ctx.r11.s64 + 20;
	// stb r21,23(r11)
	PPC_STORE_U8(ctx.r11.u32 + 23, ctx.r21.u8);
	// lwz r11,-6904(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -6904);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-6904(r29)
	PPC_STORE_U32(ctx.r29.u32 + -6904, ctx.r11.u32);
	// lwz r11,6936(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6936);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stw r9,6936(r30)
	PPC_STORE_U32(ctx.r30.u32 + 6936, ctx.r9.u32);
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// blt cr6,0x8813f8cc
	if (ctx.cr6.lt) goto loc_8813F8CC;
	// stw r22,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r22.u32);
loc_8813F8CC:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// addi r10,r23,1016
	ctx.r10.s64 = ctx.r23.s64 + 1016;
	// rlwinm r8,r16,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r5,160(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 160);
	// lwz r3,0(r25)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// addi r6,r31,16
	ctx.r6.s64 = ctx.r31.s64 + 16;
	// lwz r9,16(r25)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r25.u32 + 16);
	// stb r14,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r14.u8);
	// stb r11,114(r31)
	PPC_STORE_U8(ctx.r31.u32 + 114, ctx.r11.u8);
	// addic. r11,r31,20
	ctx.xer.ca = ctx.r31.u32 > 4294967275;
	ctx.r11.s64 = ctx.r31.s64 + 20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r7,6924(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6924);
	// stb r7,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r7.u8);
	// lwz r4,6928(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6928);
	// rlwinm r7,r4,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r7,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// stb r4,111(r31)
	PPC_STORE_U8(ctx.r31.u32 + 111, ctx.r4.u8);
	// stb r22,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r22.u8);
	// stb r18,113(r31)
	PPC_STORE_U8(ctx.r31.u32 + 113, ctx.r18.u8);
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// stw r10,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r10.u32);
	// lwz r10,4(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// stw r10,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r10.u32);
	// lwzx r8,r8,r23
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r23.u32);
	// sth r8,2(r5)
	PPC_STORE_U16(ctx.r5.u32 + 2, ctx.r8.u16);
	// sth r22,0(r5)
	PPC_STORE_U16(ctx.r5.u32 + 0, ctx.r22.u16);
	// lwz r8,6932(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6932);
	// stw r8,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r8.u32);
	// clrlwi r5,r14,24
	ctx.r5.u64 = ctx.r14.u32 & 0xFF;
	// stw r3,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r3.u32);
	// stb r5,1(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1, ctx.r5.u8);
	// stb r19,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r19.u8);
	// lwz r7,20(r25)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r25.u32 + 20);
	// lhz r4,4(r25)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r25.u32 + 4);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// add r3,r9,r10
	ctx.r3.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r8,4(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// add r10,r7,r8
	ctx.r10.u64 = ctx.r7.u64 + ctx.r8.u64;
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// stw r10,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r10.u32);
	// stb r4,4(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4, ctx.r4.u8);
	// lhz r10,0(r24)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r24.u32 + 0);
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// stw r9,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r9.u32);
	// rotlwi r10,r9,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// lwz r8,8(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 8);
	// clrlwi r7,r8,23
	ctx.r7.u64 = ctx.r8.u32 & 0x1FF;
	// stw r7,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r7.u32);
	// rotlwi r5,r7,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// mulli r3,r4,300
	ctx.r3.s64 = ctx.r4.s64 * 300;
	// divwu r8,r3,r20
	ctx.r8.u32 = ppc_divwu(ctx.r3.u32, ctx.r20.u32);
	// clrlwi r9,r5,23
	ctx.r9.u64 = ctx.r5.u32 & 0x1FF;
	// stw r8,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r8.u32);
	// lwz r7,0(r28)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// stw r7,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r7.u32);
	// lwz r5,4(r28)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// stw r5,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r5.u32);
	// beq 0x8813f9c8
	if (ctx.cr0.eq) goto loc_8813F9C8;
	// addi r8,r9,128
	ctx.r8.s64 = ctx.r9.s64 + 128;
	// rlwinm r7,r8,2,21,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x7FC;
	// lwzx r5,r7,r15
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r15.u32);
	// mullw r4,r5,r10
	ctx.r4.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r10.s32);
	// stw r4,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r4.u32);
loc_8813F9C8:
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x8813f9e0
	if (ctx.cr6.eq) goto loc_8813F9E0;
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r15
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r15.u32);
	// mullw r8,r9,r10
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// stw r8,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r8.u32);
loc_8813F9E0:
	// lbz r11,1(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r4,r11,4
	ctx.r4.s64 = ctx.r11.s64 + 4;
	// bl 0x881556a0
	ctx.lr = 0x8813F9F0;
	sub_881556A0(ctx, base);
	// stw r3,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r3.u32);
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// mr r10,r22
	ctx.r10.u64 = ctx.r22.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8813fa1c
	if (ctx.cr6.eq) goto loc_8813FA1C;
loc_8813FA04:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8813fab8
	if (ctx.cr6.eq) goto loc_8813FAB8;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813fa04
	if (!ctx.cr6.eq) goto loc_8813FA04;
loc_8813FA1C:
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
loc_8813FA20:
	// lis r10,-30700
	ctx.r10.s64 = -2011955200;
	// stw r22,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r22.u32);
	// lis r9,-30700
	ctx.r9.s64 = -2011955200;
	// lwz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// addi r7,r10,-2592
	ctx.r7.s64 = ctx.r10.s64 + -2592;
	// stw r31,36(r8)
	PPC_STORE_U32(ctx.r8.u32 + 36, ctx.r31.u32);
	// addi r6,r9,-2424
	ctx.r6.s64 = ctx.r9.s64 + -2424;
	// stw r7,32(r8)
	PPC_STORE_U32(ctx.r8.u32 + 32, ctx.r7.u32);
	// stb r22,2(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2, ctx.r22.u8);
	// stw r6,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r6.u32);
	// lwz r31,84(r1)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_8813FA4C:
	// addi r21,r21,1
	ctx.r21.s64 = ctx.r21.s64 + 1;
	// addi r28,r28,8
	ctx.r28.s64 = ctx.r28.s64 + 8;
	// addi r27,r27,12
	ctx.r27.s64 = ctx.r27.s64 + 12;
	// addi r26,r26,8
	ctx.r26.s64 = ctx.r26.s64 + 8;
	// addi r24,r24,4
	ctx.r24.s64 = ctx.r24.s64 + 4;
	// addi r17,r17,4
	ctx.r17.s64 = ctx.r17.s64 + 4;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// cmpw cr6,r21,r31
	ctx.cr6.compare<int32_t>(ctx.r21.s32, ctx.r31.s32, ctx.xer);
	// blt cr6,0x8813f880
	if (ctx.cr6.lt) goto loc_8813F880;
loc_8813FA70:
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// addi r11,r11,-19568
	ctx.r11.s64 = ctx.r11.s64 + -19568;
	// lwz r10,-4596(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -4596);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8813faac
	if (!ctx.cr6.eq) goto loc_8813FAAC;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8813faac
	if (!ctx.cr6.eq) goto loc_8813FAAC;
	// li r10,3
	ctx.r10.s64 = 3;
	// li r6,16
	ctx.r6.s64 = 16;
	// li r5,10
	ctx.r5.s64 = 10;
	// stw r10,-4596(r11)
	PPC_STORE_U32(ctx.r11.u32 + -4596, ctx.r10.u32);
	// li r4,73
	ctx.r4.s64 = 73;
	// addi r3,r14,3
	ctx.r3.s64 = ctx.r14.s64 + 3;
	// bl 0x880e3240
	ctx.lr = 0x8813FAAC;
	sub_880E3240(ctx, base);
loc_8813FAAC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
loc_8813FAB8:
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8813fac8
	if (ctx.cr6.eq) goto loc_8813FAC8;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_8813FAC8:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x8813fa20
	goto loc_8813FA20;
}

__attribute__((alias("__imp__sub_8813FAD0"))) PPC_WEAK_FUNC(sub_8813FAD0);
PPC_FUNC_IMPL(__imp__sub_8813FAD0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813FAD4"))) PPC_WEAK_FUNC(sub_8813FAD4);
PPC_FUNC_IMPL(__imp__sub_8813FAD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8813FAD8"))) PPC_WEAK_FUNC(sub_8813FAD8);
PPC_FUNC_IMPL(__imp__sub_8813FAD8) {
	PPC_FUNC_PROLOGUE();
	// lwz r9,128(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r8,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r8.u8);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// addi r11,r11,576
	ctx.r11.s64 = ctx.r11.s64 + 576;
	// lwz r10,-104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -104);
	// cmpwi cr6,r10,3000
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3000, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r8.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,-104(r11)
	PPC_STORE_U32(ctx.r11.u32 + -104, ctx.r10.u32);
	// stwx r9,r7,r11
	PPC_STORE_U32(ctx.r7.u32 + ctx.r11.u32, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813FB18"))) PPC_WEAK_FUNC(sub_8813FB18);
PPC_FUNC_IMPL(__imp__sub_8813FB18) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30649
	ctx.r11.s64 = -2008612864;
	// li r5,21088
	ctx.r5.s64 = 21088;
	// addi r31,r11,-19032
	ctx.r31.s64 = ctx.r11.s64 + -19032;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x8813FB40;
	sub_88073BD0(ctx, base);
	// lis r8,-30671
	ctx.r8.s64 = -2010054656;
	// lis r11,16838
	ctx.r11.s64 = 1103495168;
	// addi r6,r31,10516
	ctx.r6.s64 = ctx.r31.s64 + 10516;
	// ori r7,r11,20077
	ctx.r7.u64 = ctx.r11.u64 | 20077;
	// lwz r11,4200(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4200);
loc_8813FB54:
	// li r9,4
	ctx.r9.s64 = 4;
	// addi r10,r6,-4
	ctx.r10.s64 = ctx.r6.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8813FB60:
	// mullw r11,r11,r7
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r7.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// stw r11,4200(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4200, ctx.r11.u32);
	// lhz r9,4200(r8)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4200);
	// clrlwi r9,r9,30
	ctx.r9.u64 = ctx.r9.u32 & 0x3;
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8813fb60
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8813FB60;
	// addi r6,r6,10544
	ctx.r6.s64 = ctx.r6.s64 + 10544;
	// addi r10,r31,31604
	ctx.r10.s64 = ctx.r31.s64 + 31604;
	// cmpw cr6,r6,r10
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x8813fb54
	if (ctx.cr6.lt) goto loc_8813FB54;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813FBA0"))) PPC_WEAK_FUNC(sub_8813FBA0);
PPC_FUNC_IMPL(__imp__sub_8813FBA0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x8813FBA8;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30649
	ctx.r11.s64 = -2008612864;
	// li r26,2
	ctx.r26.s64 = 2;
	// addi r30,r11,-19032
	ctx.r30.s64 = ctx.r11.s64 + -19032;
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r29,r11,576
	ctx.r29.s64 = ctx.r11.s64 + 576;
loc_8813FBC4:
	// lwz r11,10540(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 10540);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8813fc74
	if (ctx.cr6.eq) goto loc_8813FC74;
	// addi r31,r30,16
	ctx.r31.s64 = ctx.r30.s64 + 16;
	// li r27,64
	ctx.r27.s64 = 64;
loc_8813FBD8:
	// lbz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8813fc68
	if (ctx.cr6.eq) goto loc_8813FC68;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bgt cr6,0x8813fc00
	if (ctx.cr6.gt) goto loc_8813FC00;
	// lwz r11,140(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8813FC00;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8813FC00:
	// lwz r11,140(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8813FC10;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8813fc68
	if (!ctx.cr6.eq) goto loc_8813FC68;
	// lwz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// stb r28,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r28.u8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8813fc48
	if (ctx.cr6.eq) goto loc_8813FC48;
	// lwz r11,-104(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -104);
	// cmpwi cr6,r11,3000
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3000, ctx.xer);
	// bge cr6,0x8813fc48
	if (!ctx.cr6.lt) goto loc_8813FC48;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r28,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r28.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-104(r29)
	PPC_STORE_U32(ctx.r29.u32 + -104, ctx.r11.u32);
	// stwx r10,r9,r29
	PPC_STORE_U32(ctx.r9.u32 + ctx.r29.u32, ctx.r10.u32);
loc_8813FC48:
	// lbz r11,3(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 3);
	// rotlwi r11,r11,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// lwzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r30.u32);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stwx r10,r11,r30
	PPC_STORE_U32(ctx.r11.u32 + ctx.r30.u32, ctx.r10.u32);
	// lwz r11,10540(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 10540);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// stw r9,10540(r30)
	PPC_STORE_U32(ctx.r30.u32 + 10540, ctx.r9.u32);
loc_8813FC68:
	// addi r31,r31,164
	ctx.r31.s64 = ctx.r31.s64 + 164;
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// bne 0x8813fbd8
	if (!ctx.cr0.eq) goto loc_8813FBD8;
loc_8813FC74:
	// addi r30,r30,10544
	ctx.r30.s64 = ctx.r30.s64 + 10544;
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne 0x8813fbc4
	if (!ctx.cr0.eq) goto loc_8813FBC4;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8813FC88"))) PPC_WEAK_FUNC(sub_8813FC88);
PPC_FUNC_IMPL(__imp__sub_8813FC88) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,76(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r31,0
	ctx.r31.s64 = 0;
	// cmpwi cr6,r10,256
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 256, ctx.xer);
	// blt cr6,0x8813fcb0
	if (ctx.cr6.lt) goto loc_8813FCB0;
	// li r31,1
	ctx.r31.s64 = 1;
loc_8813FCB0:
	// li r6,151
	ctx.r6.s64 = 151;
	// lhz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r11.u32 + 56);
	// lwz r4,32(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// lwz r5,36(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// bl 0x881538c0
	ctx.lr = 0x8813FCC4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813fcdc
	if (ctx.cr6.eq) goto loc_8813FCDC;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r31,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_8813FCDC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813FCF0"))) PPC_WEAK_FUNC(sub_8813FCF0);
PPC_FUNC_IMPL(__imp__sub_8813FCF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x8813FCF8;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r10,2(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r11,4200
	ctx.r30.s64 = ctx.r11.s64 + 4200;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8813feb8
	if (!ctx.cr6.eq) goto loc_8813FEB8;
	// lwz r10,128(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// lwz r7,28(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x8813fd44
	if (ctx.cr6.eq) goto loc_8813FD44;
loc_8813FD2C:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8813fd44
	if (ctx.cr6.eq) goto loc_8813FD44;
	// lwz r7,0(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x8813fd2c
	if (!ctx.cr6.eq) goto loc_8813FD2C;
loc_8813FD44:
	// lis r11,16838
	ctx.r11.s64 = 1103495168;
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// stw r9,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r9.u32);
	// lis r10,-13108
	ctx.r10.s64 = -859045888;
	// ori r11,r11,20077
	ctx.r11.u64 = ctx.r11.u64 | 20077;
	// ori r6,r10,52429
	ctx.r6.u64 = ctx.r10.u64 | 52429;
	// mullw r8,r8,r11
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r11.s32);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// lis r10,14563
	ctx.r10.s64 = 954400768;
	// stw r8,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r8.u32);
	// mullw r8,r8,r11
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r11.s32);
	// lwz r7,68(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// lwz r5,76(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// srawi r29,r7,2
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3) != 0);
	ctx.r29.s64 = ctx.r7.s32 >> 2;
	// mullw r7,r8,r11
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r11.s32);
	// lhz r28,0(r30)
	ctx.r28.u64 = PPC_LOAD_U16(ctx.r30.u32 + 0);
	// stw r8,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r8.u32);
	// mulhwu r6,r28,r6
	ctx.r6.u64 = (uint64_t(ctx.r28.u32) * uint64_t(ctx.r6.u32)) >> 32;
	// rlwinm r8,r6,29,3,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 29) & 0x1FFFFFFF;
	// addi r11,r7,12345
	ctx.r11.s64 = ctx.r7.s64 + 12345;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// ori r10,r10,36409
	ctx.r10.u64 = ctx.r10.u64 | 36409;
	// lhz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r30.u32 + 0);
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// addze r11,r29
	temp.s64 = ctx.r29.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r29.u32;
	ctx.r11.s64 = temp.s64;
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r11,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// li r27,1
	ctx.r27.s64 = 1;
	// subf r6,r7,r28
	ctx.r6.s64 = ctx.r28.s64 - ctx.r7.s64;
	// mulhwu r8,r29,r10
	ctx.r8.u64 = (uint64_t(ctx.r29.u32) * uint64_t(ctx.r10.u32)) >> 32;
	// stb r27,2(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2, ctx.r27.u8);
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// lhz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r30.u32 + 0);
	// mr r28,r10
	ctx.r28.u64 = ctx.r10.u64;
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// addi r6,r6,-4
	ctx.r6.s64 = ctx.r6.s64 + -4;
	// addi r27,r10,9552
	ctx.r27.s64 = ctx.r10.s64 + 9552;
	// rlwinm r10,r6,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// add r10,r10,r5
	ctx.r10.u64 = ctx.r10.u64 + ctx.r5.u64;
	// rlwinm r8,r8,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// clrlwi r10,r10,23
	ctx.r10.u64 = ctx.r10.u32 & 0x1FF;
	// lis r25,-30667
	ctx.r25.s64 = -2009792512;
	// addi r26,r10,128
	ctx.r26.s64 = ctx.r10.s64 + 128;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r26,r26,2,21,29
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 2) & 0x7FC;
	// mulhwu r28,r6,r28
	ctx.r28.u64 = (uint64_t(ctx.r6.u32) * uint64_t(ctx.r28.u32)) >> 32;
	// stw r9,12380(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12380, ctx.r9.u32);
	// lwzx r24,r10,r27
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r27.u32);
	// lwzx r27,r26,r27
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r26.u32 + ctx.r27.u32);
	// stb r9,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r9.u8);
	// stb r9,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r9.u8);
	// stb r9,113(r31)
	PPC_STORE_U8(ctx.r31.u32 + 113, ctx.r9.u8);
	// rlwinm r7,r8,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r10,r28,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 31) & 0x7FFFFFFF;
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// rlwinm r9,r10,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r8,r8,r29
	ctx.r8.s64 = ctx.r29.s64 - ctx.r8.s64;
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// extsh r10,r8
	ctx.r10.s64 = ctx.r8.s16;
	// subf r7,r7,r6
	ctx.r7.s64 = ctx.r6.s64 - ctx.r7.s64;
	// lis r9,-30667
	ctx.r9.s64 = -2009792512;
	// addi r6,r10,-4
	ctx.r6.s64 = ctx.r10.s64 + -4;
	// lis r29,-30667
	ctx.r29.s64 = -2009792512;
	// li r8,153
	ctx.r8.s64 = 153;
	// rlwinm r10,r6,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// mullw r6,r24,r11
	ctx.r6.s64 = int64_t(ctx.r24.s32) * int64_t(ctx.r11.s32);
	// stw r5,12368(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12368, ctx.r5.u32);
	// stw r8,12376(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12376, ctx.r8.u32);
	// stw r6,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r6.u32);
	// li r28,3
	ctx.r28.s64 = 3;
	// rlwinm r9,r7,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// stb r28,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r28.u8);
	// lis r8,-30667
	ctx.r8.s64 = -2009792512;
	// lis r7,-30667
	ctx.r7.s64 = -2009792512;
	// mullw r11,r27,r11
	ctx.r11.s64 = int64_t(ctx.r27.s32) * int64_t(ctx.r11.s32);
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// add r11,r10,r4
	ctx.r11.u64 = ctx.r10.u64 + ctx.r4.u64;
	// add r10,r9,r3
	ctx.r10.u64 = ctx.r9.u64 + ctx.r3.u64;
	// stw r11,12364(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12364, ctx.r11.u32);
	// lis r9,-30667
	ctx.r9.s64 = -2009792512;
	// stw r10,12372(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12372, ctx.r10.u32);
	// li r11,64
	ctx.r11.s64 = 64;
	// li r6,64
	ctx.r6.s64 = 64;
	// li r4,153
	ctx.r4.s64 = 153;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,12384(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12384, ctx.r11.u32);
	// bl 0x880f83f8
	ctx.lr = 0x8813FEB8;
	sub_880F83F8(ctx, base);
loc_8813FEB8:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r7,r30,-20128
	ctx.r7.s64 = ctx.r30.s64 + -20128;
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r6,152
	ctx.r6.s64 = 152;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// add r5,r11,r8
	ctx.r5.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lwz r3,120(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// add r4,r9,r10
	ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lbz r11,110(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 110);
	// stw r5,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r5.u32);
	// rlwinm r9,r3,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r4,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r4.u32);
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// lhzx r11,r9,r7
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r7.u32);
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x8813FEFC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8813ff24
	if (ctx.cr6.eq) goto loc_8813FF24;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// oris r8,r9,545
	ctx.r8.u64 = ctx.r9.u64 | 35717120;
	// ori r8,r8,32768
	ctx.r8.u64 = ctx.r8.u64 | 32768;
	// lwz r11,-11932(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11932);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-11932(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11932, ctx.r11.u32);
loc_8813FF24:
	// lbz r11,112(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 112);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r9.u8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge cr6,0x8813ff60
	if (!ctx.cr6.lt) goto loc_8813FF60;
	// lbz r11,110(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 110);
	// li r3,0
	ctx.r3.s64 = 0;
	// lbz r10,113(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 113);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// stb r10,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r10.u8);
	// cmpwi cr6,r8,8
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 8, ctx.xer);
	// stb r8,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r8.u8);
	// bge cr6,0x8813ff64
	if (!ctx.cr6.lt) goto loc_8813FF64;
loc_8813FF60:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8813FF64:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8813FF6C"))) PPC_WEAK_FUNC(sub_8813FF6C);
PPC_FUNC_IMPL(__imp__sub_8813FF6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8813FF70"))) PPC_WEAK_FUNC(sub_8813FF70);
PPC_FUNC_IMPL(__imp__sub_8813FF70) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,0(r5)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x8813fffc
	if (!ctx.cr6.eq) goto loc_8813FFFC;
	// lbz r5,4(r5)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r5.u32 + 4);
	// lwz r4,100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// bl 0x88147a30
	ctx.lr = 0x8813FFA4;
	sub_88147A30(ctx, base);
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// subf. r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r9,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r9.u32);
	// bgt 0x8813fffc
	if (ctx.cr0.gt) goto loc_8813FFFC;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8813ffe8
	if (ctx.cr6.eq) goto loc_8813FFE8;
loc_8813FFD0:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8813ffe8
	if (ctx.cr6.eq) goto loc_8813FFE8;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813ffd0
	if (!ctx.cr6.eq) goto loc_8813FFD0;
loc_8813FFE8:
	// lis r10,-30700
	ctx.r10.s64 = -2011955200;
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// stb r9,2(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2, ctx.r9.u8);
	// addi r9,r10,-784
	ctx.r9.s64 = ctx.r10.s64 + -784;
	// stw r9,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r9.u32);
loc_8813FFFC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88140018"))) PPC_WEAK_FUNC(sub_88140018);
PPC_FUNC_IMPL(__imp__sub_88140018) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x88140020;
	__savegprlr_25(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,2(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r25,1
	ctx.r25.s64 = 1;
	// li r27,2
	ctx.r27.s64 = 2;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8814004c
	if (!ctx.cr6.eq) goto loc_8814004C;
	// stb r25,2(r3)
	PPC_STORE_U8(ctx.r3.u32 + 2, ctx.r25.u8);
	// stb r27,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r27.u8);
	// stb r25,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, ctx.r25.u8);
	// b 0x8814006c
	goto loc_8814006C;
loc_8814004C:
	// lbz r10,1(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// lis r9,-30651
	ctx.r9.s64 = -2008743936;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r8,r9,-8560
	ctx.r8.s64 = ctx.r9.s64 + -8560;
	// rotlwi r7,r10,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lwzx r10,r7,r8
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r6,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
loc_8814006C:
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// lbz r10,5(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 5);
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r26,r11,-15864
	ctx.r26.s64 = ctx.r11.s64 + -15864;
	// extsb r11,r10
	ctx.r11.s64 = ctx.r10.s8;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88140144
	if (ctx.cr6.eq) goto loc_88140144;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x881400a4
	if (ctx.cr6.eq) goto loc_881400A4;
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r10,72(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r9,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r9.u32);
loc_881400A4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8813fc88
	ctx.lr = 0x881400AC;
	sub_8813FC88(ctx, base);
	// lbz r11,5(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 5);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,5(r31)
	PPC_STORE_U8(ctx.r31.u32 + 5, ctx.r9.u8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bgt cr6,0x88140144
	if (ctx.cr6.gt) goto loc_88140144;
	// lwz r9,128(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// lwz r11,28(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x881400f0
	if (ctx.cr6.eq) goto loc_881400F0;
loc_881400D8:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88140228
	if (ctx.cr6.eq) goto loc_88140228;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x881400d8
	if (!ctx.cr6.eq) goto loc_881400D8;
loc_881400F0:
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
loc_881400F4:
	// lbz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 4);
	// addi r8,r26,916
	ctx.r8.s64 = ctx.r26.s64 + 916;
	// lbz r7,3(r31)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r31.u32 + 3);
	// addi r6,r31,8
	ctx.r6.s64 = ctx.r31.s64 + 8;
	// rotlwi r5,r10,2
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// rotlwi r9,r7,3
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r7.u32, 3);
	// lwzx r10,r5,r8
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r8.u32);
	// stw r6,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r6.u32);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r4,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r4.u32);
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r3,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r3.u32);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r9,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r9.u32);
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r8,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r8.u32);
	// lwz r7,92(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// stw r7,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r7.u32);
	// stw r28,40(r11)
	PPC_STORE_U32(ctx.r11.u32 + 40, ctx.r28.u32);
loc_88140144:
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r8,360
	ctx.r8.s64 = 23592960;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// add r30,r10,r9
	ctx.r30.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// add r29,r11,r10
	ctx.r29.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmpw cr6,r30,r8
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r8.s32, ctx.xer);
	// stw r29,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r29.u32);
	// bge cr6,0x881402d4
	if (!ctx.cr6.lt) goto loc_881402D4;
	// lis r11,280
	ctx.r11.s64 = 18350080;
	// cmpw cr6,r29,r11
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x881402d4
	if (!ctx.cr6.lt) goto loc_881402D4;
	// lis r11,-40
	ctx.r11.s64 = -2621440;
	// cmpw cr6,r29,r11
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x881402d4
	if (!ctx.cr6.gt) goto loc_881402D4;
	// lbz r11,112(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 112);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r9.u8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge cr6,0x881401c4
	if (!ctx.cr6.lt) goto loc_881401C4;
	// lbz r11,110(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 110);
	// lbz r10,113(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 113);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// stb r10,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r10.u8);
	// cmpwi cr6,r8,8
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 8, ctx.xer);
	// stb r8,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r8.u8);
	// blt cr6,0x881401c4
	if (ctx.cr6.lt) goto loc_881401C4;
	// stb r28,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r28.u8);
loc_881401C4:
	// lbz r11,111(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 111);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,111(r31)
	PPC_STORE_U8(ctx.r31.u32 + 111, ctx.r9.u8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge cr6,0x881402e0
	if (!ctx.cr6.lt) goto loc_881402E0;
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lbz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 4);
	// lbz r8,3(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 3);
	// lwz r7,76(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// stw r29,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r29.u32);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// cmpwi cr6,r7,256
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 256, ctx.xer);
	// lhz r11,104(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 104);
	// sth r9,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, ctx.r9.u16);
	// sth r8,88(r1)
	PPC_STORE_U16(ctx.r1.u32 + 88, ctx.r8.u16);
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// sth r28,90(r1)
	PPC_STORE_U16(ctx.r1.u32 + 90, ctx.r28.u16);
	// ble cr6,0x88140240
	if (!ctx.cr6.gt) goto loc_88140240;
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// sth r27,92(r1)
	PPC_STORE_U16(ctx.r1.u32 + 92, ctx.r27.u16);
	// neg r7,r10
	ctx.r7.s64 = -ctx.r10.s64;
	// extsh r10,r7
	ctx.r10.s64 = ctx.r7.s16;
	// b 0x88140248
	goto loc_88140248;
loc_88140228:
	// lwz r10,24(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88140238
	if (ctx.cr6.eq) goto loc_88140238;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_88140238:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x881400f4
	goto loc_881400F4;
loc_88140240:
	// sth r28,92(r1)
	PPC_STORE_U16(ctx.r1.u32 + 92, ctx.r28.u16);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_88140248:
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// sth r10,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r10.u16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x881402a8
	if (!ctx.cr6.gt) goto loc_881402A8;
	// addi r11,r26,1120
	ctx.r11.s64 = ctx.r26.s64 + 1120;
	// clrlwi r7,r9,24
	ctx.r7.u64 = ctx.r9.u32 & 0xFF;
	// lbzx r6,r7,r11
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r11.u32);
	// extsb r11,r6
	ctx.r11.s64 = ctx.r6.s8;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x88140284
	if (!ctx.cr6.eq) goto loc_88140284;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// srawi r7,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r7.s64 = ctx.r10.s32 >> 1;
	// addze r6,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r6.s64 = temp.s64;
	// extsh r10,r6
	ctx.r10.s64 = ctx.r6.s16;
	// sth r10,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r10.u16);
loc_88140284:
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x881402a8
	if (!ctx.cr6.eq) goto loc_881402A8;
	// extsh r11,r8
	ctx.r11.s64 = ctx.r8.s16;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// blt cr6,0x881402a8
	if (ctx.cr6.lt) goto loc_881402A8;
	// extsh r11,r10
	ctx.r11.s64 = ctx.r10.s16;
	// srawi r10,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 1;
	// addze r7,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r7.s64 = temp.s64;
	// sth r7,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r7.u16);
loc_881402A8:
	// addi r11,r26,1120
	ctx.r11.s64 = ctx.r26.s64 + 1120;
	// clrlwi r10,r9,24
	ctx.r10.u64 = ctx.r9.u32 & 0xFF;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r11.u32);
	// cmplwi cr6,r9,4
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 4, ctx.xer);
	// bne cr6,0x881402cc
	if (!ctx.cr6.eq) goto loc_881402CC;
	// extsh r11,r8
	ctx.r11.s64 = ctx.r8.s16;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bge cr6,0x881402cc
	if (!ctx.cr6.lt) goto loc_881402CC;
	// sth r25,90(r1)
	PPC_STORE_U16(ctx.r1.u32 + 90, ctx.r25.u16);
loc_881402CC:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x881e5ce0
	ctx.lr = 0x881402D4;
	sub_881E5CE0(ctx, base);
loc_881402D4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_881402E0:
	// lbz r11,110(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 110);
	// addi r10,r26,-28
	ctx.r10.s64 = ctx.r26.s64 + -28;
	// lwz r9,120(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// addi r8,r26,-40
	ctx.r8.s64 = ctx.r26.s64 + -40;
	// extsb r7,r11
	ctx.r7.s64 = ctx.r11.s8;
	// lbz r6,116(r31)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r31.u32 + 116);
	// rlwinm r28,r9,1,0,30
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r5,r7,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// extsb r4,r6
	ctx.r4.s64 = ctx.r6.s8;
	// addi r7,r26,-12
	ctx.r7.s64 = ctx.r26.s64 + -12;
	// rlwinm r27,r4,1,0,30
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r9,r28,r8
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r28.u32 + ctx.r8.u32);
	// li r6,149
	ctx.r6.s64 = 149;
	// lhzx r11,r5,r10
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r5.u32 + ctx.r10.u32);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// add r3,r11,r9
	ctx.r3.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lhzx r10,r28,r7
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r28.u32 + ctx.r7.u32);
	// lhzx r11,r27,r26
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r27.u32 + ctx.r26.u32);
	// add r28,r11,r10
	ctx.r28.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x88140334;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88140344
	if (ctx.cr6.eq) goto loc_88140344;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
loc_88140344:
	// li r6,149
	ctx.r6.s64 = 149;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x881538c0
	ctx.lr = 0x88140358;
	sub_881538C0(ctx, base);
	// lis r28,-30597
	ctx.r28.s64 = -2005204992;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8814038c
	if (ctx.cr6.eq) goto loc_8814038C;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r9,128
	ctx.r9.s64 = 128;
	// lwz r11,-11932(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -11932);
	// oris r8,r10,545
	ctx.r8.u64 = ctx.r10.u64 | 35717120;
	// stw r9,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r9.u32);
	// addi r27,r11,1
	ctx.r27.s64 = ctx.r11.s64 + 1;
	// ori r8,r8,32768
	ctx.r8.u64 = ctx.r8.u64 | 32768;
	// stw r27,-11932(r28)
	PPC_STORE_U32(ctx.r28.u32 + -11932, ctx.r27.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// b 0x88140390
	goto loc_88140390;
loc_8814038C:
	// lwz r27,-11932(r28)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r28.u32 + -11932);
loc_88140390:
	// lbz r11,116(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 116);
	// li r6,150
	ctx.r6.s64 = 150;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r11,r9,r26
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r26.u32);
	// addi r3,r11,377
	ctx.r3.s64 = ctx.r11.s64 + 377;
	// bl 0x881538c0
	ctx.lr = 0x881403B4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x881403e0
	if (ctx.cr6.eq) goto loc_881403E0;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,112
	ctx.r9.s64 = 7340032;
	// addi r11,r27,1
	ctx.r11.s64 = ctx.r27.s64 + 1;
	// oris r7,r10,545
	ctx.r7.u64 = ctx.r10.u64 | 35717120;
	// ori r8,r9,28800
	ctx.r8.u64 = ctx.r9.u64 | 28800;
	// stw r11,-11932(r28)
	PPC_STORE_U32(ctx.r28.u32 + -11932, ctx.r11.u32);
	// ori r7,r7,65280
	ctx.r7.u64 = ctx.r7.u64 | 65280;
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
loc_881403E0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_881403EC"))) PPC_WEAK_FUNC(sub_881403EC);
PPC_FUNC_IMPL(__imp__sub_881403EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881403F0"))) PPC_WEAK_FUNC(sub_881403F0);
PPC_FUNC_IMPL(__imp__sub_881403F0) {
	PPC_FUNC_PROLOGUE();
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lwz r8,128(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// lwz r10,28(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x88140428
	if (ctx.cr6.eq) goto loc_88140428;
loc_88140410:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x881404b4
	if (ctx.cr6.eq) goto loc_881404B4;
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x88140410
	if (!ctx.cr6.eq) goto loc_88140410;
loc_88140428:
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
loc_8814042C:
	// li r9,8
	ctx.r9.s64 = 8;
	// addi r8,r11,32
	ctx.r8.s64 = ctx.r11.s64 + 32;
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// stw r9,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r9.u32);
	// lis r5,-30671
	ctx.r5.s64 = -2010054656;
	// stw r9,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r9.u32);
	// lis r4,-30700
	ctx.r4.s64 = -2011955200;
	// stw r9,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r9.u32);
	// addi r5,r5,-15916
	ctx.r5.s64 = ctx.r5.s64 + -15916;
	// stw r8,36(r10)
	PPC_STORE_U32(ctx.r10.u32 + 36, ctx.r8.u32);
	// addi r4,r4,24
	ctx.r4.s64 = ctx.r4.s64 + 24;
	// lwz r9,88(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r9.u32);
	// stw r6,40(r10)
	PPC_STORE_U32(ctx.r10.u32 + 40, ctx.r6.u32);
	// lwz r8,128(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 128);
	// stw r7,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r7.u32);
	// lwz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lbz r10,114(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 114);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r9,120(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 120);
	// rlwinm r31,r9,1,0,30
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// addis r6,r6,-4
	ctx.r6.s64 = ctx.r6.s64 + -262144;
	// stb r7,2(r11)
	PPC_STORE_U8(ctx.r11.u32 + 2, ctx.r7.u8);
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stw r4,140(r11)
	PPC_STORE_U32(ctx.r11.u32 + 140, ctx.r4.u32);
	// stw r8,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r8.u32);
	// stw r6,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r6.u32);
	// lhzx r10,r31,r5
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + ctx.r5.u32);
	// add r5,r10,r9
	ctx.r5.u64 = ctx.r10.u64 + ctx.r9.u64;
	// sth r5,56(r11)
	PPC_STORE_U16(ctx.r11.u32 + 56, ctx.r5.u16);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_881404B4:
	// lwz r9,24(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x881404c4
	if (ctx.cr6.eq) goto loc_881404C4;
	// stw r9,64(r10)
	PPC_STORE_U32(ctx.r10.u32 + 64, ctx.r9.u32);
loc_881404C4:
	// addi r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 + 24;
	// b 0x8814042c
	goto loc_8814042C;
}

__attribute__((alias("__imp__sub_881404CC"))) PPC_WEAK_FUNC(sub_881404CC);
PPC_FUNC_IMPL(__imp__sub_881404CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881404D0"))) PPC_WEAK_FUNC(sub_881404D0);
PPC_FUNC_IMPL(__imp__sub_881404D0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071120
	ctx.lr = 0x881404D8;
	__savegprlr_14(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lhz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// addi r20,r11,-14736
	ctx.r20.s64 = ctx.r11.s64 + -14736;
	// lhz r7,8(r3)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// extsh r6,r9
	ctx.r6.s64 = ctx.r9.s16;
	// addi r4,r20,-8
	ctx.r4.s64 = ctx.r20.s64 + -8;
	// lbz r3,1(r10)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// extsh r11,r7
	ctx.r11.s64 = ctx.r7.s16;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// extsb r15,r3
	ctx.r15.s64 = ctx.r3.s8;
	// lis r8,-30649
	ctx.r8.s64 = -2008612864;
	// lbzx r7,r6,r4
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r4.u32);
	// add r6,r11,r15
	ctx.r6.u64 = ctx.r11.u64 + ctx.r15.u64;
	// addi r9,r20,-40
	ctx.r9.s64 = ctx.r20.s64 + -40;
	// mulli r10,r6,10544
	ctx.r10.s64 = ctx.r6.s64 * 10544;
	// lwzx r25,r5,r9
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r9.u32);
	// extsb r17,r7
	ctx.r17.s64 = ctx.r7.s8;
	// li r14,0
	ctx.r14.s64 = 0;
	// addi r11,r8,-19032
	ctx.r11.s64 = ctx.r8.s64 + -19032;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// add r29,r10,r11
	ctx.r29.u64 = ctx.r10.u64 + ctx.r11.u64;
	// mr r7,r14
	ctx.r7.u64 = ctx.r14.u64;
	// cmpwi cr6,r17,0
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 0, ctx.xer);
	// ble cr6,0x88140560
	if (!ctx.cr6.gt) goto loc_88140560;
	// addi r11,r1,76
	ctx.r11.s64 = ctx.r1.s64 + 76;
	// li r10,-1
	ctx.r10.s64 = -1;
	// cmplwi cr6,r17,0
	ctx.cr6.compare<uint32_t>(ctx.r17.u32, 0, ctx.xer);
	// beq cr6,0x88140560
	if (ctx.cr6.eq) goto loc_88140560;
	// mtctr r17
	ctx.ctr.u64 = ctx.r17.u64;
loc_88140558:
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x88140558
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88140558;
loc_88140560:
	// mr r4,r14
	ctx.r4.u64 = ctx.r14.u64;
	// addi r9,r25,2
	ctx.r9.s64 = ctx.r25.s64 + 2;
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
loc_8814056C:
	// lwz r11,10512(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 10512);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,10512(r29)
	PPC_STORE_U32(ctx.r29.u32 + 10512, ctx.r11.u32);
	// cmpwi cr6,r11,64
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 64, ctx.xer);
	// blt cr6,0x88140584
	if (ctx.cr6.lt) goto loc_88140584;
	// stw r14,10512(r29)
	PPC_STORE_U32(ctx.r29.u32 + 10512, ctx.r14.u32);
loc_88140584:
	// lwz r11,10512(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 10512);
	// mulli r10,r11,164
	ctx.r10.s64 = ctx.r11.s64 * 164;
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + ctx.r29.u64;
	// lbz r3,16(r10)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r10.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x881405cc
	if (!ctx.cr6.eq) goto loc_881405CC;
	// lhz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r9.u32 + 0);
	// lwz r3,0(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// cmpw cr6,r3,r10
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x881405b4
	if (!ctx.cr6.lt) goto loc_881405B4;
	// stw r11,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r11.u32);
loc_881405B4:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// addi r9,r9,6
	ctx.r9.s64 = ctx.r9.s64 + 6;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmpw cr6,r7,r17
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r17.s32, ctx.xer);
	// bge cr6,0x881405d8
	if (!ctx.cr6.lt) goto loc_881405D8;
loc_881405CC:
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// cmpwi cr6,r4,64
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 64, ctx.xer);
	// blt cr6,0x8814056c
	if (ctx.cr6.lt) goto loc_8814056C;
loc_881405D8:
	// lwz r11,10532(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 10532);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,10532(r29)
	PPC_STORE_U32(ctx.r29.u32 + 10532, ctx.r11.u32);
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// blt cr6,0x881405f0
	if (ctx.cr6.lt) goto loc_881405F0;
	// stw r14,10532(r29)
	PPC_STORE_U32(ctx.r29.u32 + 10532, ctx.r14.u32);
loc_881405F0:
	// lwz r11,10536(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 10536);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,10536(r29)
	PPC_STORE_U32(ctx.r29.u32 + 10536, ctx.r11.u32);
	// cmpwi cr6,r11,24
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 24, ctx.xer);
	// blt cr6,0x88140608
	if (ctx.cr6.lt) goto loc_88140608;
	// stw r14,10536(r29)
	PPC_STORE_U32(ctx.r29.u32 + 10536, ctx.r14.u32);
loc_88140608:
	// addi r11,r20,-736
	ctx.r11.s64 = ctx.r20.s64 + -736;
	// addi r10,r20,-428
	ctx.r10.s64 = ctx.r20.s64 + -428;
	// addi r9,r20,-952
	ctx.r9.s64 = ctx.r20.s64 + -952;
	// addi r19,r1,80
	ctx.r19.s64 = ctx.r1.s64 + 80;
	// mr r24,r14
	ctx.r24.u64 = ctx.r14.u64;
	// lwzx r23,r5,r11
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r11.u32);
	// cmpwi cr6,r17,0
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 0, ctx.xer);
	// lwzx r28,r5,r10
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r10.u32);
	// lwzx r26,r5,r9
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r9.u32);
	// ble cr6,0x88140848
	if (!ctx.cr6.gt) goto loc_88140848;
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// addi r30,r29,10516
	ctx.r30.s64 = ctx.r29.s64 + 10516;
	// li r22,16
	ctx.r22.s64 = 16;
	// li r21,1
	ctx.r21.s64 = 1;
	// li r16,100
	ctx.r16.s64 = 100;
	// addi r18,r11,9552
	ctx.r18.s64 = ctx.r11.s64 + 9552;
loc_88140648:
	// lwz r11,0(r19)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r19.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x88140824
	if (ctx.cr6.lt) goto loc_88140824;
	// mulli r11,r11,164
	ctx.r11.s64 = ctx.r11.s64 * 164;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// addi r31,r11,16
	ctx.r31.s64 = ctx.r11.s64 + 16;
	// stb r24,19(r11)
	PPC_STORE_U8(ctx.r11.u32 + 19, ctx.r24.u8);
	// lwz r11,-10516(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -10516);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-10516(r30)
	PPC_STORE_U32(ctx.r30.u32 + -10516, ctx.r11.u32);
	// lwz r11,10540(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 10540);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stw r9,10540(r29)
	PPC_STORE_U32(ctx.r29.u32 + 10540, ctx.r9.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// blt cr6,0x88140694
	if (ctx.cr6.lt) goto loc_88140694;
	// stw r14,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r14.u32);
loc_88140694:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r7,0(r27)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r10,16(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 16);
	// lwz r8,20(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 20);
	// stb r11,114(r31)
	PPC_STORE_U8(ctx.r31.u32 + 114, ctx.r11.u8);
	// lwz r5,10532(r29)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r29.u32 + 10532);
	// stb r5,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r5.u8);
	// lhz r3,4(r25)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r25.u32 + 4);
	// stb r22,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r22.u8);
	// stb r22,113(r31)
	PPC_STORE_U8(ctx.r31.u32 + 113, ctx.r22.u8);
	// stb r3,111(r31)
	PPC_STORE_U8(ctx.r31.u32 + 111, ctx.r3.u8);
	// lwz r6,0(r26)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// stw r6,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r6.u32);
	// lwz r5,4(r26)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// stw r5,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r5.u32);
	// lwz r4,10536(r29)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r29.u32 + 10536);
	// rlwinm r3,r4,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r3,r20
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r20.u32);
	// stb r11,116(r31)
	PPC_STORE_U8(ctx.r31.u32 + 116, ctx.r11.u8);
	// stw r7,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r7.u32);
	// lhz r5,4(r27)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r27.u32 + 4);
	// stb r21,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r21.u8);
	// stb r15,1(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1, ctx.r15.u8);
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r9,4(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// add r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stw r10,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r10.u32);
	// stw r4,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r4.u32);
	// stb r5,4(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4, ctx.r5.u8);
	// lhz r10,0(r25)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r25.u32 + 0);
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// stw r9,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r9.u32);
	// lwz r8,8(r28)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8);
	// clrlwi r7,r8,23
	ctx.r7.u64 = ctx.r8.u32 & 0x1FF;
	// lhz r11,6(r27)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r27.u32 + 6);
	// rotlwi r10,r7,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// stw r7,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r7.u32);
	// cmpwi cr6,r10,256
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 256, ctx.xer);
	// sth r11,104(r31)
	PPC_STORE_U16(ctx.r31.u32 + 104, ctx.r11.u16);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// ble cr6,0x88140748
	if (!ctx.cr6.gt) goto loc_88140748;
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r11.s64;
	// stw r10,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r10.u32);
	// b 0x88140750
	goto loc_88140750;
loc_88140748:
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r11,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
loc_88140750:
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// addic. r10,r31,20
	ctx.xer.ca = ctx.r31.u32 > 4294967275;
	ctx.r10.s64 = ctx.r31.s64 + 20;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// addi r8,r31,16
	ctx.r8.s64 = ctx.r31.s64 + 16;
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// stw r11,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// lwz r7,0(r23)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r23.u32 + 0);
	// mulli r6,r7,100
	ctx.r6.s64 = ctx.r7.s64 * 100;
	// divwu r5,r6,r16
	ctx.r5.u32 = ppc_divwu(ctx.r6.u32, ctx.r16.u32);
	// stw r5,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r5.u32);
	// lwz r4,0(r23)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r23.u32 + 0);
	// stw r4,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r4.u32);
	// lwz r3,4(r23)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r23.u32 + 4);
	// stw r3,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r3.u32);
	// beq 0x881407a0
	if (ctx.cr0.eq) goto loc_881407A0;
	// addi r7,r11,128
	ctx.r7.s64 = ctx.r11.s64 + 128;
	// rlwinm r6,r7,2,21,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x7FC;
	// lwzx r5,r6,r18
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r18.u32);
	// mullw r4,r5,r9
	ctx.r4.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r9.s32);
	// stw r4,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
loc_881407A0:
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x881407b8
	if (ctx.cr6.eq) goto loc_881407B8;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r18
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r18.u32);
	// mullw r9,r10,r9
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// stw r9,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
loc_881407B8:
	// lbz r11,1(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r4,r11,4
	ctx.r4.s64 = ctx.r11.s64 + 4;
	// bl 0x881556a0
	ctx.lr = 0x881407C8;
	sub_881556A0(ctx, base);
	// stw r3,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r3.u32);
	// mr r10,r14
	ctx.r10.u64 = ctx.r14.u64;
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x881407f4
	if (ctx.cr6.eq) goto loc_881407F4;
loc_881407DC:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88140854
	if (ctx.cr6.eq) goto loc_88140854;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x881407dc
	if (!ctx.cr6.eq) goto loc_881407DC;
loc_881407F4:
	// mr r11,r14
	ctx.r11.u64 = ctx.r14.u64;
loc_881407F8:
	// lis r10,-30700
	ctx.r10.s64 = -2011955200;
	// stw r21,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r21.u32);
	// lis r9,-30700
	ctx.r9.s64 = -2011955200;
	// lwz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// addi r7,r10,-144
	ctx.r7.s64 = ctx.r10.s64 + -144;
	// stw r31,36(r8)
	PPC_STORE_U32(ctx.r8.u32 + 36, ctx.r31.u32);
	// addi r6,r9,1008
	ctx.r6.s64 = ctx.r9.s64 + 1008;
	// stw r7,32(r8)
	PPC_STORE_U32(ctx.r8.u32 + 32, ctx.r7.u32);
	// stw r14,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r14.u32);
	// stb r14,2(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2, ctx.r14.u8);
	// stw r6,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r6.u32);
loc_88140824:
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// addi r23,r23,8
	ctx.r23.s64 = ctx.r23.s64 + 8;
	// addi r28,r28,12
	ctx.r28.s64 = ctx.r28.s64 + 12;
	// addi r26,r26,8
	ctx.r26.s64 = ctx.r26.s64 + 8;
	// addi r25,r25,6
	ctx.r25.s64 = ctx.r25.s64 + 6;
	// addi r19,r19,4
	ctx.r19.s64 = ctx.r19.s64 + 4;
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// cmpw cr6,r24,r17
	ctx.cr6.compare<int32_t>(ctx.r24.s32, ctx.r17.s32, ctx.xer);
	// blt cr6,0x88140648
	if (ctx.cr6.lt) goto loc_88140648;
loc_88140848:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
loc_88140854:
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88140864
	if (ctx.cr6.eq) goto loc_88140864;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_88140864:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x881407f8
	goto loc_881407F8;
}

__attribute__((alias("__imp__sub_8814086C"))) PPC_WEAK_FUNC(sub_8814086C);
PPC_FUNC_IMPL(__imp__sub_8814086C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88140870"))) PPC_WEAK_FUNC(sub_88140870);
PPC_FUNC_IMPL(__imp__sub_88140870) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + ctx.r11.u64;
	// lis r11,-30650
	ctx.r11.s64 = -2008678400;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// addi r11,r11,19600
	ctx.r11.s64 = ctx.r11.s64 + 19600;
	// mulli r9,r10,2648
	ctx.r9.s64 = ctx.r10.s64 * 2648;
	// addi r8,r11,2644
	ctx.r8.s64 = ctx.r11.s64 + 2644;
	// lwzx r3,r9,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88140894"))) PPC_WEAK_FUNC(sub_88140894);
PPC_FUNC_IMPL(__imp__sub_88140894) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88140898"))) PPC_WEAK_FUNC(sub_88140898);
PPC_FUNC_IMPL(__imp__sub_88140898) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8814089C"))) PPC_WEAK_FUNC(sub_8814089C);
PPC_FUNC_IMPL(__imp__sub_8814089C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881408A0"))) PPC_WEAK_FUNC(sub_881408A0);
PPC_FUNC_IMPL(__imp__sub_881408A0) {
	PPC_FUNC_PROLOGUE();
	// lwz r9,128(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r8,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r8.u8);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// addi r11,r11,576
	ctx.r11.s64 = ctx.r11.s64 + 576;
	// lwz r10,-104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -104);
	// cmpwi cr6,r10,3000
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3000, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r8.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,-104(r11)
	PPC_STORE_U32(ctx.r11.u32 + -104, ctx.r10.u32);
	// stwx r9,r7,r11
	PPC_STORE_U32(ctx.r7.u32 + ctx.r11.u32, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881408E0"))) PPC_WEAK_FUNC(sub_881408E0);
PPC_FUNC_IMPL(__imp__sub_881408E0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30650
	ctx.r11.s64 = -2008678400;
	// li r5,26480
	ctx.r5.s64 = 26480;
	// addi r31,r11,19600
	ctx.r31.s64 = ctx.r11.s64 + 19600;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x88140908;
	sub_88073BD0(ctx, base);
	// lis r9,-30671
	ctx.r9.s64 = -2010054656;
	// lis r10,16838
	ctx.r10.s64 = 1103495168;
	// addi r11,r31,2632
	ctx.r11.s64 = ctx.r31.s64 + 2632;
	// ori r7,r10,20077
	ctx.r7.u64 = ctx.r10.u64 | 20077;
	// lwz r10,4200(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4200);
loc_8814091C:
	// mullw r10,r10,r7
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32);
	// addi r10,r10,12345
	ctx.r10.s64 = ctx.r10.s64 + 12345;
	// addi r6,r31,29112
	ctx.r6.s64 = ctx.r31.s64 + 29112;
	// stw r10,4200(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4200, ctx.r10.u32);
	// lhz r8,4200(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4200);
	// clrlwi r5,r8,30
	ctx.r5.u64 = ctx.r8.u32 & 0x3;
	// stw r5,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r5.u32);
	// addi r11,r11,2648
	ctx.r11.s64 = ctx.r11.s64 + 2648;
	// cmpw cr6,r11,r6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r6.s32, ctx.xer);
	// blt cr6,0x8814091c
	if (ctx.cr6.lt) goto loc_8814091C;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88140958"))) PPC_WEAK_FUNC(sub_88140958);
PPC_FUNC_IMPL(__imp__sub_88140958) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x88140960;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30650
	ctx.r11.s64 = -2008678400;
	// li r26,10
	ctx.r26.s64 = 10;
	// addi r30,r11,19600
	ctx.r30.s64 = ctx.r11.s64 + 19600;
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r29,r11,576
	ctx.r29.s64 = ctx.r11.s64 + 576;
loc_8814097C:
	// lwz r11,2644(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2644);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88140a24
	if (ctx.cr6.eq) goto loc_88140A24;
	// addi r31,r30,4
	ctx.r31.s64 = ctx.r30.s64 + 4;
	// li r27,16
	ctx.r27.s64 = 16;
loc_88140990:
	// lbz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88140a18
	if (ctx.cr6.eq) goto loc_88140A18;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bgt cr6,0x881409b8
	if (ctx.cr6.gt) goto loc_881409B8;
	// lwz r11,140(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x881409B8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_881409B8:
	// lwz r11,140(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x881409C8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88140a18
	if (!ctx.cr6.eq) goto loc_88140A18;
	// lwz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// stb r28,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r28.u8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x88140a00
	if (ctx.cr6.eq) goto loc_88140A00;
	// lwz r11,-104(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -104);
	// cmpwi cr6,r11,3000
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3000, ctx.xer);
	// bge cr6,0x88140a00
	if (!ctx.cr6.lt) goto loc_88140A00;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r28,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r28.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-104(r29)
	PPC_STORE_U32(ctx.r29.u32 + -104, ctx.r11.u32);
	// stwx r10,r9,r29
	PPC_STORE_U32(ctx.r9.u32 + ctx.r29.u32, ctx.r10.u32);
loc_88140A00:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,2644(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2644);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// stw r10,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// stw r9,2644(r30)
	PPC_STORE_U32(ctx.r30.u32 + 2644, ctx.r9.u32);
loc_88140A18:
	// addi r31,r31,164
	ctx.r31.s64 = ctx.r31.s64 + 164;
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// bne 0x88140990
	if (!ctx.cr0.eq) goto loc_88140990;
loc_88140A24:
	// addi r30,r30,2648
	ctx.r30.s64 = ctx.r30.s64 + 2648;
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne 0x8814097c
	if (!ctx.cr0.eq) goto loc_8814097C;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88140A38"))) PPC_WEAK_FUNC(sub_88140A38);
PPC_FUNC_IMPL(__imp__sub_88140A38) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lhz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r3.u32 + 56);
	// li r6,151
	ctx.r6.s64 = 151;
	// lwz r4,32(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// lwz r5,36(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// bl 0x881538c0
	ctx.lr = 0x88140A5C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88140a84
	if (ctx.cr6.eq) goto loc_88140A84;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// oris r8,r9,2593
	ctx.r8.u64 = ctx.r9.u64 | 169934848;
	// ori r8,r8,32768
	ctx.r8.u64 = ctx.r8.u64 | 32768;
	// lwz r11,-11932(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11932);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-11932(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11932, ctx.r11.u32);
loc_88140A84:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88140A94"))) PPC_WEAK_FUNC(sub_88140A94);
PPC_FUNC_IMPL(__imp__sub_88140A94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88140A98"))) PPC_WEAK_FUNC(sub_88140A98);
PPC_FUNC_IMPL(__imp__sub_88140A98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071144
	ctx.lr = 0x88140AA0;
	__savegprlr_23(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r10,2(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r11,4200
	ctx.r30.s64 = ctx.r11.s64 + 4200;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x88140c64
	if (!ctx.cr6.eq) goto loc_88140C64;
	// lwz r9,128(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// lwz r8,28(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x88140ae8
	if (ctx.cr6.eq) goto loc_88140AE8;
loc_88140AD0:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88140ae8
	if (ctx.cr6.eq) goto loc_88140AE8;
	// lwz r8,0(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x88140ad0
	if (!ctx.cr6.eq) goto loc_88140AD0;
loc_88140AE8:
	// lis r11,16838
	ctx.r11.s64 = 1103495168;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// lis r8,-13108
	ctx.r8.s64 = -859045888;
	// ori r11,r11,20077
	ctx.r11.u64 = ctx.r11.u64 | 20077;
	// ori r7,r8,52429
	ctx.r7.u64 = ctx.r8.u64 | 52429;
	// mullw r9,r9,r11
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// addi r9,r9,12345
	ctx.r9.s64 = ctx.r9.s64 + 12345;
	// lis r6,20971
	ctx.r6.s64 = 1374355456;
	// stw r9,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r9.u32);
	// mullw r9,r9,r11
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// lwz r4,68(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// lwz r5,76(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r29,12(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r9,r9,12345
	ctx.r9.s64 = ctx.r9.s64 + 12345;
	// srawi r4,r4,3
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7) != 0);
	ctx.r4.s64 = ctx.r4.s32 >> 3;
	// mullw r8,r9,r11
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// lhz r28,0(r30)
	ctx.r28.u64 = PPC_LOAD_U16(ctx.r30.u32 + 0);
	// stw r9,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r9.u32);
	// mulhwu r9,r28,r7
	ctx.r9.u64 = (uint64_t(ctx.r28.u32) * uint64_t(ctx.r7.u32)) >> 32;
	// rlwinm r9,r9,29,3,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 29) & 0x1FFFFFFF;
	// addi r11,r8,12345
	ctx.r11.s64 = ctx.r8.s64 + 12345;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// li r27,1
	ctx.r27.s64 = 1;
	// lhz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r30.u32 + 0);
	// add r7,r9,r7
	ctx.r7.u64 = ctx.r9.u64 + ctx.r7.u64;
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// addze r11,r4
	temp.s64 = ctx.r4.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r11.s64 = temp.s64;
	// rlwinm r9,r7,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// stb r27,2(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2, ctx.r27.u8);
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// stw r11,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// ori r8,r6,34079
	ctx.r8.u64 = ctx.r6.u64 | 34079;
	// subf r7,r9,r28
	ctx.r7.s64 = ctx.r28.s64 - ctx.r9.s64;
	// mulhwu r6,r4,r8
	ctx.r6.u64 = (uint64_t(ctx.r4.u32) * uint64_t(ctx.r8.u32)) >> 32;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// lhz r28,0(r30)
	ctx.r28.u64 = PPC_LOAD_U16(ctx.r30.u32 + 0);
	// lis r7,14563
	ctx.r7.s64 = 954400768;
	// extsh r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	// rlwinm r6,r6,29,3,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 29) & 0x1FFFFFFF;
	// addi r9,r8,-4
	ctx.r9.s64 = ctx.r8.s64 + -4;
	// lis r27,-30667
	ctx.r27.s64 = -2009792512;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// ori r9,r7,36409
	ctx.r9.u64 = ctx.r7.u64 | 36409;
	// add r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 + ctx.r5.u64;
	// mulli r7,r6,25
	ctx.r7.s64 = ctx.r6.s64 * 25;
	// mulhwu r6,r28,r9
	ctx.r6.u64 = (uint64_t(ctx.r28.u32) * uint64_t(ctx.r9.u32)) >> 32;
	// clrlwi r9,r8,23
	ctx.r9.u64 = ctx.r8.u32 & 0x1FF;
	// rlwinm r8,r6,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r6,r9,128
	ctx.r6.s64 = ctx.r9.s64 + 128;
	// rlwinm r26,r9,2,0,29
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// li r9,1
	ctx.r9.s64 = 1;
	// subf r7,r7,r4
	ctx.r7.s64 = ctx.r4.s64 - ctx.r7.s64;
	// lis r25,-30714
	ctx.r25.s64 = -2012872704;
	// stw r9,12380(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12380, ctx.r9.u32);
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// addi r7,r25,9552
	ctx.r7.s64 = ctx.r25.s64 + 9552;
	// rlwinm r4,r8,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r6,r6,2,21,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// add r4,r8,r4
	ctx.r4.u64 = ctx.r8.u64 + ctx.r4.u64;
	// lis r8,-30667
	ctx.r8.s64 = -2009792512;
	// lwzx r26,r26,r7
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r26.u32 + ctx.r7.u32);
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// lis r27,-30667
	ctx.r27.s64 = -2009792512;
	// lwzx r24,r6,r7
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r7.u32);
	// li r7,153
	ctx.r7.s64 = 153;
	// lis r25,-30667
	ctx.r25.s64 = -2009792512;
	// stb r10,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r10.u8);
	// stw r7,12376(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12376, ctx.r7.u32);
	// addi r7,r9,-12
	ctx.r7.s64 = ctx.r9.s64 + -12;
	// li r6,64
	ctx.r6.s64 = 64;
	// stb r10,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r10.u8);
	// li r23,3
	ctx.r23.s64 = 3;
	// stw r5,12368(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12368, ctx.r5.u32);
	// subf r4,r4,r28
	ctx.r4.s64 = ctx.r28.s64 - ctx.r4.s64;
	// rlwinm r9,r7,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// stw r6,12384(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12384, ctx.r6.u32);
	// stb r23,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r23.u8);
	// rlwinm r8,r4,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// lis r7,-30667
	ctx.r7.s64 = -2009792512;
	// stb r10,113(r31)
	PPC_STORE_U8(ctx.r31.u32 + 113, ctx.r10.u8);
	// mullw r10,r26,r11
	ctx.r10.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r11.s32);
	// stw r10,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r10.u32);
	// lis r4,-30667
	ctx.r4.s64 = -2009792512;
	// mullw r6,r24,r11
	ctx.r6.s64 = int64_t(ctx.r24.s32) * int64_t(ctx.r11.s32);
	// stw r6,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r6.u32);
	// add r11,r9,r3
	ctx.r11.u64 = ctx.r9.u64 + ctx.r3.u64;
	// add r10,r8,r29
	ctx.r10.u64 = ctx.r8.u64 + ctx.r29.u64;
	// stw r11,12364(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12364, ctx.r11.u32);
	// li r6,64
	ctx.r6.s64 = 64;
	// stw r10,12372(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12372, ctx.r10.u32);
	// li r4,153
	ctx.r4.s64 = 153;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x880f83f8
	ctx.lr = 0x88140C64;
	sub_880F83F8(ctx, base);
loc_88140C64:
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r7,r30,-18184
	ctx.r7.s64 = ctx.r30.s64 + -18184;
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r6,152
	ctx.r6.s64 = 152;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r3,120(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// add r5,r8,r9
	ctx.r5.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lbz r11,110(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 110);
	// stw r4,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r4.u32);
	// rlwinm r9,r3,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r5,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r5.u32);
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// lhzx r11,r9,r7
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r7.u32);
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x88140CA8;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88140cd0
	if (ctx.cr6.eq) goto loc_88140CD0;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// oris r8,r9,545
	ctx.r8.u64 = ctx.r9.u64 | 35717120;
	// ori r8,r8,65280
	ctx.r8.u64 = ctx.r8.u64 | 65280;
	// lwz r11,-11932(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11932);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-11932(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11932, ctx.r11.u32);
loc_88140CD0:
	// lbz r11,112(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 112);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r9.u8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge cr6,0x88140d0c
	if (!ctx.cr6.lt) goto loc_88140D0C;
	// lbz r11,110(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 110);
	// li r3,0
	ctx.r3.s64 = 0;
	// lbz r10,113(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 113);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// stb r10,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r10.u8);
	// cmpwi cr6,r8,8
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 8, ctx.xer);
	// stb r8,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r8.u8);
	// bge cr6,0x88140d10
	if (!ctx.cr6.lt) goto loc_88140D10;
loc_88140D0C:
	// li r3,1
	ctx.r3.s64 = 1;
loc_88140D10:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88140D18"))) PPC_WEAK_FUNC(sub_88140D18);
PPC_FUNC_IMPL(__imp__sub_88140D18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x88140D20;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,2(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88140d4c
	if (!ctx.cr6.eq) goto loc_88140D4C;
	// li r11,2
	ctx.r11.s64 = 2;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r11.u8);
	// stb r10,2(r3)
	PPC_STORE_U8(ctx.r3.u32 + 2, ctx.r10.u8);
	// stb r11,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, ctx.r11.u8);
	// b 0x88140d6c
	goto loc_88140D6C;
loc_88140D4C:
	// lbz r10,1(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// lis r9,-30651
	ctx.r9.s64 = -2008743936;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r8,r9,-8560
	ctx.r8.s64 = ctx.r9.s64 + -8560;
	// rotlwi r7,r10,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lwzx r10,r7,r8
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r6,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
loc_88140D6C:
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// lbz r10,5(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 5);
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r26,r11,-13952
	ctx.r26.s64 = ctx.r11.s64 + -13952;
	// extsb r11,r10
	ctx.r11.s64 = ctx.r10.s8;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88140e3c
	if (ctx.cr6.eq) goto loc_88140E3C;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x88140da4
	if (ctx.cr6.eq) goto loc_88140DA4;
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r10,72(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r9,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r9.u32);
loc_88140DA4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88140a38
	ctx.lr = 0x88140DAC;
	sub_88140A38(ctx, base);
	// lbz r11,5(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 5);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,5(r31)
	PPC_STORE_U8(ctx.r31.u32 + 5, ctx.r9.u8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bgt cr6,0x88140e3c
	if (ctx.cr6.gt) goto loc_88140E3C;
	// lwz r9,128(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// lwz r11,28(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88140df0
	if (ctx.cr6.eq) goto loc_88140DF0;
loc_88140DD8:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88140fb8
	if (ctx.cr6.eq) goto loc_88140FB8;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88140dd8
	if (!ctx.cr6.eq) goto loc_88140DD8;
loc_88140DF0:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_88140DF4:
	// lbz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 4);
	// addi r9,r26,1000
	ctx.r9.s64 = ctx.r26.s64 + 1000;
	// lbz r8,3(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 3);
	// rotlwi r7,r10,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// rotlwi r10,r8,3
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 3);
	// lwzx r9,r7,r9
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r6,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r6.u32);
	// lwz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r5,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r5.u32);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r4,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r4.u32);
	// lwz r3,4(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r3,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r3.u32);
	// lwz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// stw r10,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r10.u32);
	// stw r29,40(r11)
	PPC_STORE_U32(ctx.r11.u32 + 40, ctx.r29.u32);
loc_88140E3C:
	// lwz r9,128(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// lwz r11,28(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88140e68
	if (ctx.cr6.eq) goto loc_88140E68;
loc_88140E50:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88140fd0
	if (ctx.cr6.eq) goto loc_88140FD0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88140e50
	if (!ctx.cr6.eq) goto loc_88140E50;
loc_88140E68:
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
loc_88140E6C:
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// lis r27,-30597
	ctx.r27.s64 = -2005204992;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88141098
	if (ctx.cr6.eq) goto loc_88141098;
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88140ea4
	if (ctx.cr6.eq) goto loc_88140EA4;
loc_88140E8C:
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// stw r29,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r29.u32);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88140e8c
	if (!ctx.cr6.eq) goto loc_88140E8C;
loc_88140EA4:
	// rlwinm r11,r10,0,20,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFF8;
	// rlwinm r11,r11,0,28,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFC0F;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88141098
	if (ctx.cr6.eq) goto loc_88141098;
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// addi r28,r31,20
	ctx.r28.s64 = ctx.r31.s64 + 20;
	// lwz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// lis r9,-30714
	ctx.r9.s64 = -2012872704;
	// srawi r7,r11,3
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7) != 0);
	ctx.r7.s64 = ctx.r11.s32 >> 3;
	// clrlwi r11,r10,23
	ctx.r11.u64 = ctx.r10.u32 & 0x1FF;
	// addi r30,r31,16
	ctx.r30.s64 = ctx.r31.s64 + 16;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// addze r10,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r10.s64 = temp.s64;
	// addi r9,r9,9552
	ctx.r9.s64 = ctx.r9.s64 + 9552;
	// beq cr6,0x88140ef4
	if (ctx.cr6.eq) goto loc_88140EF4;
	// addi r7,r11,128
	ctx.r7.s64 = ctx.r11.s64 + 128;
	// rlwinm r6,r7,2,21,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x7FC;
	// lwzx r5,r6,r9
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// mullw r4,r5,r10
	ctx.r4.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r10.s32);
	// stw r4,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r4.u32);
loc_88140EF4:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x88140f0c
	if (ctx.cr6.eq) goto loc_88140F0C;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r9
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r9.u32);
	// mullw r7,r9,r10
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// stw r7,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r7.u32);
loc_88140F0C:
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// li r10,5
	ctx.r10.s64 = 5;
	// divwu r9,r11,r10
	ctx.r9.u32 = ppc_divwu(ctx.r11.u32, ctx.r10.u32);
	// stw r9,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r9.u32);
	// lbz r11,115(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 115);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// extsb r6,r7
	ctx.r6.s64 = ctx.r7.s8;
	// clrlwi r5,r6,30
	ctx.r5.u64 = ctx.r6.u32 & 0x3;
	// stb r6,115(r31)
	PPC_STORE_U8(ctx.r31.u32 + 115, ctx.r6.u8);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne cr6,0x88140fe8
	if (!ctx.cr6.eq) goto loc_88140FE8;
	// lis r10,-30667
	ctx.r10.s64 = -2009792512;
	// li r3,24
	ctx.r3.s64 = 24;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// stw r29,12380(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12380, ctx.r29.u32);
	// bl 0x881534c8
	ctx.lr = 0x88140F4C;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lis r9,-30667
	ctx.r9.s64 = -2009792512;
	// addi r8,r11,-12
	ctx.r8.s64 = ctx.r11.s64 + -12;
	// li r3,8
	ctx.r3.s64 = 8;
	// rlwinm r11,r8,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r11,12364(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12364, ctx.r11.u32);
	// bl 0x881534c8
	ctx.lr = 0x88140F70;
	sub_881534C8(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// rlwinm r9,r3,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 16) & 0xFFFF0000;
	// lis r7,-30667
	ctx.r7.s64 = -2009792512;
	// lwz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lis r6,-30667
	ctx.r6.s64 = -2009792512;
	// lis r3,-30667
	ctx.r3.s64 = -2009792512;
	// lis r9,-30667
	ctx.r9.s64 = -2009792512;
	// stw r11,12372(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12372, ctx.r11.u32);
	// addi r5,r10,256
	ctx.r5.s64 = ctx.r10.s64 + 256;
	// li r11,153
	ctx.r11.s64 = 153;
	// li r10,64
	ctx.r10.s64 = 64;
	// stw r5,12368(r6)
	PPC_STORE_U32(ctx.r6.u32 + 12368, ctx.r5.u32);
	// stw r11,12376(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12376, ctx.r11.u32);
	// li r6,64
	ctx.r6.s64 = 64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,12384(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12384, ctx.r10.u32);
	// b 0x8814103c
	goto loc_8814103C;
loc_88140FB8:
	// lwz r10,24(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88140fc8
	if (ctx.cr6.eq) goto loc_88140FC8;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_88140FC8:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x88140df4
	goto loc_88140DF4;
loc_88140FD0:
	// lwz r10,24(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88140fe0
	if (ctx.cr6.eq) goto loc_88140FE0;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_88140FE0:
	// addi r8,r11,24
	ctx.r8.s64 = ctx.r11.s64 + 24;
	// b 0x88140e6c
	goto loc_88140E6C;
loc_88140FE8:
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lis r9,-30667
	ctx.r9.s64 = -2009792512;
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r7,-30667
	ctx.r7.s64 = -2009792512;
	// lwz r5,68(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// lis r6,-30667
	ctx.r6.s64 = -2009792512;
	// addis r10,r8,16
	ctx.r10.s64 = ctx.r8.s64 + 1048576;
	// lis r3,-30667
	ctx.r3.s64 = -2009792512;
	// lis r4,-30667
	ctx.r4.s64 = -2009792512;
	// stw r11,12364(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12364, ctx.r11.u32);
	// lis r8,-30667
	ctx.r8.s64 = -2009792512;
	// stw r10,12372(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12372, ctx.r10.u32);
	// li r11,153
	ctx.r11.s64 = 153;
	// stw r5,12368(r6)
	PPC_STORE_U32(ctx.r6.u32 + 12368, ctx.r5.u32);
	// li r10,8
	ctx.r10.s64 = 8;
	// stw r11,12376(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12376, ctx.r11.u32);
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
	// stw r10,12380(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12380, ctx.r10.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r29,12384(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12384, ctx.r29.u32);
	// li r3,8
	ctx.r3.s64 = 8;
loc_8814103C:
	// li r4,153
	ctx.r4.s64 = 153;
	// bl 0x880f83f8
	ctx.lr = 0x88141044;
	sub_880F83F8(ctx, base);
	// lwz r11,120(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// addi r10,r26,-24
	ctx.r10.s64 = ctx.r26.s64 + -24;
	// lbz r9,110(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 110);
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// extsb r11,r9
	ctx.r11.s64 = ctx.r9.s8;
	// li r6,152
	ctx.r6.s64 = 152;
	// lhzx r10,r8,r10
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r8.u32 + ctx.r10.u32);
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x881538c0
	ctx.lr = 0x88141070;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x881410f0
	if (ctx.cr6.eq) goto loc_881410F0;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-11932(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
	// oris r9,r10,545
	ctx.r9.u64 = ctx.r10.u64 | 35717120;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// ori r9,r9,65280
	ctx.r9.u64 = ctx.r9.u64 | 65280;
	// stw r8,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r8.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// b 0x881410f0
	goto loc_881410F0;
loc_88141098:
	// lwz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// addi r28,r31,20
	ctx.r28.s64 = ctx.r31.s64 + 20;
	// lis r9,-30714
	ctx.r9.s64 = -2012872704;
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// addi r30,r31,16
	ctx.r30.s64 = ctx.r31.s64 + 16;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// clrlwi r10,r10,23
	ctx.r10.u64 = ctx.r10.u32 & 0x1FF;
	// addi r9,r9,9552
	ctx.r9.s64 = ctx.r9.s64 + 9552;
	// beq cr6,0x881410d0
	if (ctx.cr6.eq) goto loc_881410D0;
	// addi r7,r10,128
	ctx.r7.s64 = ctx.r10.s64 + 128;
	// rlwinm r6,r7,2,21,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x7FC;
	// lwzx r5,r6,r9
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// mullw r4,r5,r11
	ctx.r4.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r11.s32);
	// stw r4,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r4.u32);
loc_881410D0:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x881410e8
	if (ctx.cr6.eq) goto loc_881410E8;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r9
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// mullw r7,r9,r11
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// stw r7,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r7.u32);
loc_881410E8:
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// stw r11,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r11.u32);
loc_881410F0:
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lis r7,344
	ctx.r7.s64 = 22544384;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// cmpw cr6,r11,r7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r7.s32, ctx.xer);
	// blt cr6,0x88141128
	if (ctx.cr6.lt) goto loc_88141128;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_88141128:
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88141180
	if (ctx.cr6.eq) goto loc_88141180;
	// lwz r8,68(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r7,80(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// addis r10,r10,6
	ctx.r10.s64 = ctx.r10.s64 + 393216;
	// addi r8,r8,3
	ctx.r8.s64 = ctx.r8.s64 + 3;
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// add r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 + ctx.r9.u64;
	// stw r10,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r10.u32);
	// stw r8,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r8.u32);
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// bne 0x88141180
	if (!ctx.cr0.eq) goto loc_88141180;
	// stw r29,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r29.u32);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x88141174
	if (ctx.cr6.eq) goto loc_88141174;
	// rlwinm r11,r8,12,0,19
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 12) & 0xFFFFF000;
	// stw r11,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
loc_88141174:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x88141180
	if (ctx.cr6.eq) goto loc_88141180;
	// stw r29,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r29.u32);
loc_88141180:
	// lbz r11,112(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 112);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r9.u8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge cr6,0x881411bc
	if (!ctx.cr6.lt) goto loc_881411BC;
	// lbz r11,110(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 110);
	// lbz r10,113(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 113);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// stb r10,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r10.u8);
	// cmpwi cr6,r8,3
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 3, ctx.xer);
	// stb r8,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r8.u8);
	// blt cr6,0x881411bc
	if (ctx.cr6.lt) goto loc_881411BC;
	// stb r29,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r29.u8);
loc_881411BC:
	// lwz r11,120(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// addi r9,r26,-8
	ctx.r9.s64 = ctx.r26.s64 + -8;
	// lbz r8,110(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 110);
	// li r6,150
	ctx.r6.s64 = 150;
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r30,8(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r29,12(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// extsb r10,r8
	ctx.r10.s64 = ctx.r8.s8;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lhzx r11,r7,r9
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + ctx.r9.u32);
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x881411F0;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88141200
	if (ctx.cr6.eq) goto loc_88141200;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
loc_88141200:
	// lwz r11,120(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// li r6,150
	ctx.r6.s64 = 150;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r5,r10,r29
	ctx.r5.s64 = ctx.r29.s64 - ctx.r10.s64;
	// lhzx r3,r9,r26
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r26.u32);
	// bl 0x881538c0
	ctx.lr = 0x88141220;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88141244
	if (ctx.cr6.eq) goto loc_88141244;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-11932(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
	// oris r9,r10,545
	ctx.r9.u64 = ctx.r10.u64 | 35717120;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// ori r9,r9,32768
	ctx.r9.u64 = ctx.r9.u64 | 32768;
	// stw r11,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r11.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_88141244:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88141250"))) PPC_WEAK_FUNC(sub_88141250);
PPC_FUNC_IMPL(__imp__sub_88141250) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,0(r5)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x881412c0
	if (!ctx.cr6.eq) goto loc_881412C0;
	// lbz r5,4(r5)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r5.u32 + 4);
	// lwz r4,100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// bl 0x88147a30
	ctx.lr = 0x8814127C;
	sub_88147A30(ctx, base);
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x881412ac
	if (ctx.cr6.eq) goto loc_881412AC;
loc_88141294:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x881412ac
	if (ctx.cr6.eq) goto loc_881412AC;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88141294
	if (!ctx.cr6.eq) goto loc_88141294;
loc_881412AC:
	// lis r10,-30700
	ctx.r10.s64 = -2011955200;
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// stb r9,2(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2, ctx.r9.u8);
	// addi r9,r10,2712
	ctx.r9.s64 = ctx.r10.s64 + 2712;
	// stw r9,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r9.u32);
loc_881412C0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881412D8"))) PPC_WEAK_FUNC(sub_881412D8);
PPC_FUNC_IMPL(__imp__sub_881412D8) {
	PPC_FUNC_PROLOGUE();
	// lwz r8,128(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r10,28(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x88141308
	if (ctx.cr6.eq) goto loc_88141308;
loc_881412F0:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x88141390
	if (ctx.cr6.eq) goto loc_88141390;
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x881412f0
	if (!ctx.cr6.eq) goto loc_881412F0;
loc_88141308:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8814130C:
	// li r9,16
	ctx.r9.s64 = 16;
	// addi r8,r11,8
	ctx.r8.s64 = ctx.r11.s64 + 8;
	// lis r6,-30671
	ctx.r6.s64 = -2010054656;
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r9,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r9.u32);
	// stw r9,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r9.u32);
	// addi r4,r6,-13968
	ctx.r4.s64 = ctx.r6.s64 + -13968;
	// stw r9,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r9.u32);
	// lis r5,-30700
	ctx.r5.s64 = -2011955200;
	// stw r8,36(r10)
	PPC_STORE_U32(ctx.r10.u32 + 36, ctx.r8.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r6,88(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// addi r8,r5,3352
	ctx.r8.s64 = ctx.r5.s64 + 3352;
	// stw r6,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r6.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r7,40(r10)
	PPC_STORE_U32(ctx.r10.u32 + 40, ctx.r7.u32);
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 128);
	// stw r7,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r7.u32);
	// lbz r9,114(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 114);
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r10,120(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 120);
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// extsb r9,r9
	ctx.r9.s64 = ctx.r9.s8;
	// stb r5,2(r11)
	PPC_STORE_U8(ctx.r11.u32 + 2, ctx.r5.u8);
	// stw r8,140(r11)
	PPC_STORE_U32(ctx.r11.u32 + 140, ctx.r8.u32);
	// stw r6,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r6.u32);
	// stw r7,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r7.u32);
	// lhzx r10,r10,r4
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r4.u32);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// sth r9,56(r11)
	PPC_STORE_U16(ctx.r11.u32 + 56, ctx.r9.u16);
	// blr 
	return;
loc_88141390:
	// lwz r9,24(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x881413a0
	if (ctx.cr6.eq) goto loc_881413A0;
	// stw r9,64(r10)
	PPC_STORE_U32(ctx.r10.u32 + 64, ctx.r9.u32);
loc_881413A0:
	// addi r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 + 24;
	// b 0x8814130c
	goto loc_8814130C;
}

__attribute__((alias("__imp__sub_881413A8"))) PPC_WEAK_FUNC(sub_881413A8);
PPC_FUNC_IMPL(__imp__sub_881413A8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071138
	ctx.lr = 0x881413B0;
	__savegprlr_20(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r27,0(r3)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// lhz r26,4(r3)
	ctx.r26.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// lis r5,-30650
	ctx.r5.s64 = -2008678400;
	// addi r7,r11,-12792
	ctx.r7.s64 = ctx.r11.s64 + -12792;
	// lhz r25,8(r3)
	ctx.r25.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// extsh r4,r26
	ctx.r4.s64 = ctx.r26.s16;
	// addi r10,r7,-32
	ctx.r10.s64 = ctx.r7.s64 + -32;
	// lbz r8,1(r27)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r27.u32 + 1);
	// rlwinm r6,r4,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// extsh r9,r25
	ctx.r9.s64 = ctx.r25.s16;
	// extsb r30,r8
	ctx.r30.s64 = ctx.r8.s8;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r30,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r6,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// rlwinm r4,r9,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// add r28,r8,r10
	ctx.r28.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r8,r11,r9
	ctx.r8.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addi r11,r5,19600
	ctx.r11.s64 = ctx.r5.s64 + 19600;
	// mulli r8,r8,2648
	ctx.r8.s64 = ctx.r8.s64 * 2648;
	// subf r5,r4,r28
	ctx.r5.s64 = ctx.r28.s64 - ctx.r4.s64;
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// subf r8,r10,r5
	ctx.r8.s64 = ctx.r5.s64 - ctx.r10.s64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r31,-1
	ctx.r31.s64 = -1;
	// add r4,r8,r10
	ctx.r4.u64 = ctx.r8.u64 + ctx.r10.u64;
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// li r22,0
	ctx.r22.s64 = 0;
	// addi r10,r10,26432
	ctx.r10.s64 = ctx.r10.s64 + 26432;
	// mr r5,r22
	ctx.r5.u64 = ctx.r22.u64;
	// mr r24,r22
	ctx.r24.u64 = ctx.r22.u64;
	// addi r8,r28,2
	ctx.r8.s64 = ctx.r28.s64 + 2;
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
	// lwz r23,324(r10)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r10.u32 + 324);
loc_88141444:
	// lwz r10,2628(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2628);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,2628(r11)
	PPC_STORE_U32(ctx.r11.u32 + 2628, ctx.r10.u32);
	// cmpwi cr6,r10,16
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 16, ctx.xer);
	// blt cr6,0x8814145c
	if (ctx.cr6.lt) goto loc_8814145C;
	// stw r22,2628(r11)
	PPC_STORE_U32(ctx.r11.u32 + 2628, ctx.r22.u32);
loc_8814145C:
	// lwz r29,2628(r11)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2628);
	// mulli r10,r29,164
	ctx.r10.s64 = ctx.r29.s64 * 164;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lbz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x881414b8
	if (!ctx.cr6.eq) goto loc_881414B8;
	// lhz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r8.u32 + 0);
	// cmpwi cr6,r23,2
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 2, ctx.xer);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// bne cr6,0x88141490
	if (!ctx.cr6.eq) goto loc_88141490;
	// cmpwi cr6,r10,8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 8, ctx.xer);
	// blt cr6,0x88141490
	if (ctx.cr6.lt) goto loc_88141490;
	// li r10,8
	ctx.r10.s64 = 8;
loc_88141490:
	// lwz r21,0(r31)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpw cr6,r21,r10
	ctx.cr6.compare<int32_t>(ctx.r21.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x881414a0
	if (!ctx.cr6.lt) goto loc_881414A0;
	// stw r29,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r29.u32);
loc_881414A0:
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// cmpwi cr6,r5,1
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 1, ctx.xer);
	// bge cr6,0x881414c4
	if (!ctx.cr6.lt) goto loc_881414C4;
loc_881414B8:
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// cmpwi cr6,r24,16
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 16, ctx.xer);
	// blt cr6,0x88141444
	if (ctx.cr6.lt) goto loc_88141444;
loc_881414C4:
	// lwz r10,2636(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2636);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,2636(r11)
	PPC_STORE_U32(ctx.r11.u32 + 2636, ctx.r10.u32);
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// blt cr6,0x881414dc
	if (ctx.cr6.lt) goto loc_881414DC;
	// stw r22,2636(r11)
	PPC_STORE_U32(ctx.r11.u32 + 2636, ctx.r22.u32);
loc_881414DC:
	// lwz r10,2640(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2640);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,2640(r11)
	PPC_STORE_U32(ctx.r11.u32 + 2640, ctx.r10.u32);
	// cmpwi cr6,r10,14
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 14, ctx.xer);
	// blt cr6,0x881414f4
	if (ctx.cr6.lt) goto loc_881414F4;
	// stw r22,2640(r11)
	PPC_STORE_U32(ctx.r11.u32 + 2640, ctx.r22.u32);
loc_881414F4:
	// addi r10,r7,-784
	ctx.r10.s64 = ctx.r7.s64 + -784;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r31,r7,-384
	ctx.r31.s64 = ctx.r7.s64 + -384;
	// addi r29,r7,-1008
	ctx.r29.s64 = ctx.r7.s64 + -1008;
	// rlwinm r8,r9,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r5,r9,4,0,27
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// lwzx r10,r6,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// lwzx r9,r6,r31
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r31.u32);
	// lwzx r6,r6,r29
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r29.u32);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r9,r9,r5
	ctx.r9.u64 = ctx.r9.u64 + ctx.r5.u64;
	// add r8,r6,r8
	ctx.r8.u64 = ctx.r6.u64 + ctx.r8.u64;
	// blt cr6,0x881416d8
	if (ctx.cr6.lt) goto loc_881416D8;
	// mulli r6,r4,164
	ctx.r6.s64 = ctx.r4.s64 * 164;
	// add r6,r6,r11
	ctx.r6.u64 = ctx.r6.u64 + ctx.r11.u64;
	// addi r31,r6,4
	ctx.r31.s64 = ctx.r6.s64 + 4;
	// stb r25,7(r6)
	PPC_STORE_U8(ctx.r6.u32 + 7, ctx.r25.u8);
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r4,r6,1
	ctx.r4.s64 = ctx.r6.s64 + 1;
	// stw r4,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r4.u32);
	// lwz r6,2644(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2644);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// stw r6,2644(r11)
	PPC_STORE_U32(ctx.r11.u32 + 2644, ctx.r6.u32);
	// lwz r6,2632(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2632);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// stw r6,2632(r11)
	PPC_STORE_U32(ctx.r11.u32 + 2632, ctx.r6.u32);
	// cmpwi cr6,r6,4
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 4, ctx.xer);
	// blt cr6,0x8814156c
	if (ctx.cr6.lt) goto loc_8814156C;
	// stw r22,2632(r11)
	PPC_STORE_U32(ctx.r11.u32 + 2632, ctx.r22.u32);
loc_8814156C:
	// lwz r4,2632(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2632);
	// mr r24,r30
	ctx.r24.u64 = ctx.r30.u64;
	// lhz r30,10(r3)
	ctx.r30.u64 = PPC_LOAD_U16(ctx.r3.u32 + 10);
	// li r25,2
	ctx.r25.s64 = 2;
	// li r23,1
	ctx.r23.s64 = 1;
	// lwz r6,20(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// extsh r21,r30
	ctx.r21.s64 = ctx.r30.s16;
	// lwz r5,16(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r3,28(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// addi r29,r31,16
	ctx.r29.s64 = ctx.r31.s64 + 16;
	// stb r4,114(r31)
	PPC_STORE_U8(ctx.r31.u32 + 114, ctx.r4.u8);
	// clrlwi r4,r21,23
	ctx.r4.u64 = ctx.r21.u32 & 0x1FF;
	// lwz r30,2636(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2636);
	// stb r30,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r30.u8);
	// lwz r11,2640(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2640);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r20,r11,r7
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r7.u32);
	// lis r7,-30714
	ctx.r7.s64 = -2012872704;
	// stb r22,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r22.u8);
	// addic. r11,r31,20
	ctx.xer.ca = ctx.r31.u32 > 4294967275;
	ctx.r11.s64 = ctx.r31.s64 + 20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stb r25,113(r31)
	PPC_STORE_U8(ctx.r31.u32 + 113, ctx.r25.u8);
	// addi r30,r7,9552
	ctx.r30.s64 = ctx.r7.s64 + 9552;
	// stb r20,111(r31)
	PPC_STORE_U8(ctx.r31.u32 + 111, ctx.r20.u8);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// stw r7,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r7.u32);
	// lwz r8,4(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// stw r8,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r8.u32);
	// stb r23,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r23.u8);
	// stb r24,1(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1, ctx.r24.u8);
	// stw r27,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r27.u32);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// add r7,r5,r7
	ctx.r7.u64 = ctx.r5.u64 + ctx.r7.u64;
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// stb r26,4(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4, ctx.r26.u8);
	// stw r7,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r7.u32);
	// stw r8,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r8.u32);
	// lhz r6,0(r28)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r28.u32 + 0);
	// extsh r5,r6
	ctx.r5.s64 = ctx.r6.s16;
	// stw r5,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r5.u32);
	// stw r21,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r21.u32);
	// stw r3,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r3.u32);
	// lwz r3,12(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// stw r3,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r3.u32);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r9.u32);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r8,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r8.u32);
	// lwz r7,4(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// rotlwi r10,r5,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r7,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r7.u32);
	// beq 0x88141650
	if (ctx.cr0.eq) goto loc_88141650;
	// addi r9,r4,128
	ctx.r9.s64 = ctx.r4.s64 + 128;
	// rlwinm r8,r9,2,21,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x7FC;
	// lwzx r7,r8,r30
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r30.u32);
	// mullw r6,r7,r10
	ctx.r6.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// stw r6,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r6.u32);
loc_88141650:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x88141668
	if (ctx.cr6.eq) goto loc_88141668;
	// rlwinm r11,r4,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r30
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r30.u32);
	// mullw r8,r9,r10
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// stw r8,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r8.u32);
loc_88141668:
	// stb r22,115(r31)
	PPC_STORE_U8(ctx.r31.u32 + 115, ctx.r22.u8);
	// li r3,1
	ctx.r3.s64 = 1;
	// lbz r11,1(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// addi r4,r11,4
	ctx.r4.s64 = ctx.r11.s64 + 4;
	// bl 0x881556a0
	ctx.lr = 0x8814167C;
	sub_881556A0(ctx, base);
	// stw r3,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r3.u32);
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// mr r10,r22
	ctx.r10.u64 = ctx.r22.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x881416a8
	if (ctx.cr6.eq) goto loc_881416A8;
loc_88141690:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x881416e4
	if (ctx.cr6.eq) goto loc_881416E4;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88141690
	if (!ctx.cr6.eq) goto loc_88141690;
loc_881416A8:
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
loc_881416AC:
	// lis r10,-30700
	ctx.r10.s64 = -2011955200;
	// stw r22,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r22.u32);
	// lis r9,-30700
	ctx.r9.s64 = -2011955200;
	// lwz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// addi r7,r10,4688
	ctx.r7.s64 = ctx.r10.s64 + 4688;
	// stw r31,36(r8)
	PPC_STORE_U32(ctx.r8.u32 + 36, ctx.r31.u32);
	// addi r6,r9,4824
	ctx.r6.s64 = ctx.r9.s64 + 4824;
	// stw r7,32(r8)
	PPC_STORE_U32(ctx.r8.u32 + 32, ctx.r7.u32);
	// stw r22,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r22.u32);
	// stb r22,2(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2, ctx.r22.u8);
	// stw r6,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r6.u32);
loc_881416D8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x88071188
	__restgprlr_20(ctx, base);
	return;
loc_881416E4:
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x881416f4
	if (ctx.cr6.eq) goto loc_881416F4;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_881416F4:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x881416ac
	goto loc_881416AC;
}

__attribute__((alias("__imp__sub_881416FC"))) PPC_WEAK_FUNC(sub_881416FC);
PPC_FUNC_IMPL(__imp__sub_881416FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88141700"))) PPC_WEAK_FUNC(sub_88141700);
PPC_FUNC_IMPL(__imp__sub_88141700) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88141704"))) PPC_WEAK_FUNC(sub_88141704);
PPC_FUNC_IMPL(__imp__sub_88141704) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88141708"))) PPC_WEAK_FUNC(sub_88141708);
PPC_FUNC_IMPL(__imp__sub_88141708) {
	PPC_FUNC_PROLOGUE();
	// lwz r9,128(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r8,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r8.u8);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// addi r11,r11,576
	ctx.r11.s64 = ctx.r11.s64 + 576;
	// lwz r10,-104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -104);
	// cmpwi cr6,r10,3000
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3000, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r8.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,-104(r11)
	PPC_STORE_U32(ctx.r11.u32 + -104, ctx.r10.u32);
	// stwx r9,r7,r11
	PPC_STORE_U32(ctx.r7.u32 + ctx.r11.u32, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88141748"))) PPC_WEAK_FUNC(sub_88141748);
PPC_FUNC_IMPL(__imp__sub_88141748) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30650
	ctx.r11.s64 = -2008678400;
	// li r5,16512
	ctx.r5.s64 = 16512;
	// addi r31,r11,3088
	ctx.r31.s64 = ctx.r11.s64 + 3088;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x88141770;
	sub_88073BD0(ctx, base);
	// lis r8,-30671
	ctx.r8.s64 = -2010054656;
	// lis r11,16838
	ctx.r11.s64 = 1103495168;
	// addi r6,r31,8224
	ctx.r6.s64 = ctx.r31.s64 + 8224;
	// ori r7,r11,20077
	ctx.r7.u64 = ctx.r11.u64 | 20077;
	// lwz r11,4200(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4200);
loc_88141784:
	// li r9,5
	ctx.r9.s64 = 5;
	// addi r10,r6,-4
	ctx.r10.s64 = ctx.r6.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_88141790:
	// mullw r11,r11,r7
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r7.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// stw r11,4200(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4200, ctx.r11.u32);
	// lhz r9,4200(r8)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4200);
	// clrlwi r9,r9,30
	ctx.r9.u64 = ctx.r9.u32 & 0x3;
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x88141790
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88141790;
	// addi r6,r6,8256
	ctx.r6.s64 = ctx.r6.s64 + 8256;
	// addi r10,r31,24736
	ctx.r10.s64 = ctx.r31.s64 + 24736;
	// cmpw cr6,r6,r10
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x88141784
	if (ctx.cr6.lt) goto loc_88141784;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881417D0"))) PPC_WEAK_FUNC(sub_881417D0);
PPC_FUNC_IMPL(__imp__sub_881417D0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x881417D8;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30650
	ctx.r11.s64 = -2008678400;
	// li r26,2
	ctx.r26.s64 = 2;
	// addi r30,r11,3088
	ctx.r30.s64 = ctx.r11.s64 + 3088;
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r29,r11,576
	ctx.r29.s64 = ctx.r11.s64 + 576;
loc_881417F4:
	// lwz r11,8252(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8252);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x881418a4
	if (ctx.cr6.eq) goto loc_881418A4;
	// addi r31,r30,20
	ctx.r31.s64 = ctx.r30.s64 + 20;
	// li r27,50
	ctx.r27.s64 = 50;
loc_88141808:
	// lbz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88141898
	if (ctx.cr6.eq) goto loc_88141898;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bgt cr6,0x88141830
	if (ctx.cr6.gt) goto loc_88141830;
	// lwz r11,140(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x88141830;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_88141830:
	// lwz r11,140(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x88141840;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88141898
	if (!ctx.cr6.eq) goto loc_88141898;
	// lwz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// stb r28,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r28.u8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x88141878
	if (ctx.cr6.eq) goto loc_88141878;
	// lwz r11,-104(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -104);
	// cmpwi cr6,r11,3000
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3000, ctx.xer);
	// bge cr6,0x88141878
	if (!ctx.cr6.lt) goto loc_88141878;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r28,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r28.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-104(r29)
	PPC_STORE_U32(ctx.r29.u32 + -104, ctx.r11.u32);
	// stwx r10,r9,r29
	PPC_STORE_U32(ctx.r9.u32 + ctx.r29.u32, ctx.r10.u32);
loc_88141878:
	// lbz r11,3(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 3);
	// rotlwi r11,r11,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// lwzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r30.u32);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stwx r10,r11,r30
	PPC_STORE_U32(ctx.r11.u32 + ctx.r30.u32, ctx.r10.u32);
	// lwz r11,8252(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8252);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// stw r9,8252(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8252, ctx.r9.u32);
loc_88141898:
	// addi r31,r31,164
	ctx.r31.s64 = ctx.r31.s64 + 164;
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// bne 0x88141808
	if (!ctx.cr0.eq) goto loc_88141808;
loc_881418A4:
	// addi r30,r30,8256
	ctx.r30.s64 = ctx.r30.s64 + 8256;
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne 0x881417f4
	if (!ctx.cr0.eq) goto loc_881417F4;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_881418B8"))) PPC_WEAK_FUNC(sub_881418B8);
PPC_FUNC_IMPL(__imp__sub_881418B8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,76(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r31,0
	ctx.r31.s64 = 0;
	// cmpwi cr6,r10,256
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 256, ctx.xer);
	// blt cr6,0x881418e0
	if (ctx.cr6.lt) goto loc_881418E0;
	// li r31,1
	ctx.r31.s64 = 1;
loc_881418E0:
	// li r6,151
	ctx.r6.s64 = 151;
	// lhz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r11.u32 + 56);
	// lwz r4,32(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// lwz r5,36(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// bl 0x881538c0
	ctx.lr = 0x881418F4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8814190c
	if (ctx.cr6.eq) goto loc_8814190C;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r31,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_8814190C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88141920"))) PPC_WEAK_FUNC(sub_88141920);
PPC_FUNC_IMPL(__imp__sub_88141920) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88141928;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r10,2(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r11,4200
	ctx.r30.s64 = ctx.r11.s64 + 4200;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x88141a54
	if (!ctx.cr6.eq) goto loc_88141A54;
	// lwz r9,128(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// lwz r9,28(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x88141970
	if (ctx.cr6.eq) goto loc_88141970;
loc_88141958:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88141970
	if (ctx.cr6.eq) goto loc_88141970;
	// lwz r9,0(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x88141958
	if (!ctx.cr6.eq) goto loc_88141958;
loc_88141970:
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// lis r8,16838
	ctx.r8.s64 = 1103495168;
	// lwz r6,76(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// lis r7,-13108
	ctx.r7.s64 = -859045888;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// ori r5,r8,20077
	ctx.r5.u64 = ctx.r8.u64 | 20077;
	// ori r4,r7,52429
	ctx.r4.u64 = ctx.r7.u64 | 52429;
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// mullw r11,r11,r5
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r5.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// lis r7,-30714
	ctx.r7.s64 = -2012872704;
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// srawi r5,r3,2
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x3) != 0);
	ctx.r5.s64 = ctx.r3.s32 >> 2;
	// lhz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + 0);
	// mulhwu r4,r11,r4
	ctx.r4.u64 = (uint64_t(ctx.r11.u32) * uint64_t(ctx.r4.u32)) >> 32;
	// addi r3,r7,9552
	ctx.r3.s64 = ctx.r7.s64 + 9552;
	// mr r7,r11
	ctx.r7.u64 = ctx.r11.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// rlwinm r11,r4,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 29) & 0x1FFFFFFF;
	// stb r9,2(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2, ctx.r9.u8);
	// lis r8,-30641
	ctx.r8.s64 = -2008088576;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r29,3
	ctx.r29.s64 = 3;
	// add r4,r11,r9
	ctx.r4.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addze r11,r5
	temp.s64 = ctx.r5.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r11.s64 = temp.s64;
	// rlwinm r5,r4,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,-19568(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + -19568);
	// stw r11,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// subf r4,r5,r7
	ctx.r4.s64 = ctx.r7.s64 - ctx.r5.s64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// extsh r7,r4
	ctx.r7.s64 = ctx.r4.s16;
	// addi r7,r7,-4
	ctx.r7.s64 = ctx.r7.s64 + -4;
	// rlwinm r9,r7,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r9,r6
	ctx.r6.u64 = ctx.r9.u64 + ctx.r6.u64;
	// clrlwi r9,r6,23
	ctx.r9.u64 = ctx.r6.u32 & 0x1FF;
	// addi r5,r9,128
	ctx.r5.s64 = ctx.r9.s64 + 128;
	// rlwinm r4,r9,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r5,2,21,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x7FC;
	// lwzx r7,r4,r3
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r3.u32);
	// mullw r6,r7,r11
	ctx.r6.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r11.s32);
	// lwzx r5,r9,r3
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r3.u32);
	// mullw r4,r5,r11
	ctx.r4.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r11.s32);
	// stw r6,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r6.u32);
	// stb r29,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r29.u8);
	// stb r10,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r10.u8);
	// stw r4,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r4.u32);
	// stb r10,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r10.u8);
	// stb r10,113(r31)
	PPC_STORE_U8(ctx.r31.u32 + 113, ctx.r10.u8);
	// bne cr6,0x88141a54
	if (!ctx.cr6.eq) goto loc_88141A54;
	// lbz r10,1(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// li r11,3
	ctx.r11.s64 = 3;
	// li r6,17
	ctx.r6.s64 = 17;
	// li r5,26
	ctx.r5.s64 = 26;
	// stw r11,-19568(r8)
	PPC_STORE_U32(ctx.r8.u32 + -19568, ctx.r11.u32);
	// li r4,81
	ctx.r4.s64 = 81;
	// addi r3,r10,3
	ctx.r3.s64 = ctx.r10.s64 + 3;
	// bl 0x880e3240
	ctx.lr = 0x88141A54;
	sub_880E3240(ctx, base);
loc_88141A54:
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r7,r30,-16936
	ctx.r7.s64 = ctx.r30.s64 + -16936;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// li r6,152
	ctx.r6.s64 = 152;
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r3,120(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// add r4,r9,r8
	ctx.r4.u64 = ctx.r9.u64 + ctx.r8.u64;
	// stw r5,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r5.u32);
	// rlwinm r11,r3,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// lbz r10,110(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 110);
	// stw r4,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r4.u32);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// lhzx r11,r11,r7
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r7.u32);
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x88141A98;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88141ac0
	if (ctx.cr6.eq) goto loc_88141AC0;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// oris r8,r9,545
	ctx.r8.u64 = ctx.r9.u64 | 35717120;
	// ori r8,r8,32768
	ctx.r8.u64 = ctx.r8.u64 | 32768;
	// lwz r11,-11932(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11932);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-11932(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11932, ctx.r11.u32);
loc_88141AC0:
	// lbz r11,112(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 112);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r9.u8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge cr6,0x88141afc
	if (!ctx.cr6.lt) goto loc_88141AFC;
	// lbz r11,110(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 110);
	// li r3,0
	ctx.r3.s64 = 0;
	// lbz r10,113(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 113);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// stb r10,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r10.u8);
	// cmpwi cr6,r8,8
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 8, ctx.xer);
	// stb r8,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r8.u8);
	// bge cr6,0x88141b00
	if (!ctx.cr6.lt) goto loc_88141B00;
loc_88141AFC:
	// li r3,1
	ctx.r3.s64 = 1;
loc_88141B00:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88141B08"))) PPC_WEAK_FUNC(sub_88141B08);
PPC_FUNC_IMPL(__imp__sub_88141B08) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,0(r5)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x88141b94
	if (!ctx.cr6.eq) goto loc_88141B94;
	// lbz r5,4(r5)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r5.u32 + 4);
	// lwz r4,100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// bl 0x88147a30
	ctx.lr = 0x88141B3C;
	sub_88147A30(ctx, base);
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// subf. r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r9,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r9.u32);
	// bgt 0x88141b94
	if (ctx.cr0.gt) goto loc_88141B94;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88141b80
	if (ctx.cr6.eq) goto loc_88141B80;
loc_88141B68:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88141b80
	if (ctx.cr6.eq) goto loc_88141B80;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88141b68
	if (!ctx.cr6.eq) goto loc_88141B68;
loc_88141B80:
	// lis r10,-30700
	ctx.r10.s64 = -2011955200;
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// stb r9,2(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2, ctx.r9.u8);
	// addi r9,r10,6432
	ctx.r9.s64 = ctx.r10.s64 + 6432;
	// stw r9,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r9.u32);
loc_88141B94:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88141BB0"))) PPC_WEAK_FUNC(sub_88141BB0);
PPC_FUNC_IMPL(__imp__sub_88141BB0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x88141BB8;
	__savegprlr_26(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,2(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r30,2
	ctx.r30.s64 = 2;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88141be8
	if (!ctx.cr6.eq) goto loc_88141BE8;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r30,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r30.u8);
	// li r10,3
	ctx.r10.s64 = 3;
	// stb r11,2(r3)
	PPC_STORE_U8(ctx.r3.u32 + 2, ctx.r11.u8);
	// stb r10,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, ctx.r10.u8);
	// b 0x88141c08
	goto loc_88141C08;
loc_88141BE8:
	// lbz r10,1(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// lis r9,-30651
	ctx.r9.s64 = -2008743936;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r8,r9,-8560
	ctx.r8.s64 = ctx.r9.s64 + -8560;
	// rotlwi r7,r10,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lwzx r10,r7,r8
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r6,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
loc_88141C08:
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// lbz r10,5(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 5);
	// li r27,0
	ctx.r27.s64 = 0;
	// addi r28,r11,-12720
	ctx.r28.s64 = ctx.r11.s64 + -12720;
	// extsb r11,r10
	ctx.r11.s64 = ctx.r10.s8;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88141ce0
	if (ctx.cr6.eq) goto loc_88141CE0;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x88141c40
	if (ctx.cr6.eq) goto loc_88141C40;
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r11,72(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 72);
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r10,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r10.u32);
loc_88141C40:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x881418b8
	ctx.lr = 0x88141C48;
	sub_881418B8(ctx, base);
	// lbz r11,5(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 5);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,5(r31)
	PPC_STORE_U8(ctx.r31.u32 + 5, ctx.r9.u8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bgt cr6,0x88141ce0
	if (ctx.cr6.gt) goto loc_88141CE0;
	// lwz r9,128(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// lwz r11,28(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88141c8c
	if (ctx.cr6.eq) goto loc_88141C8C;
loc_88141C74:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88141d24
	if (ctx.cr6.eq) goto loc_88141D24;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88141c74
	if (!ctx.cr6.eq) goto loc_88141C74;
loc_88141C8C:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_88141C90:
	// lbz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 4);
	// addi r8,r28,1064
	ctx.r8.s64 = ctx.r28.s64 + 1064;
	// lbz r7,3(r31)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r31.u32 + 3);
	// addi r6,r31,8
	ctx.r6.s64 = ctx.r31.s64 + 8;
	// rotlwi r5,r10,2
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// rotlwi r9,r7,3
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r7.u32, 3);
	// lwzx r10,r5,r8
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r8.u32);
	// stw r6,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r6.u32);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r4,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r4.u32);
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r3,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r3.u32);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r9,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r9.u32);
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r8,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r8.u32);
	// lwz r7,92(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// stw r7,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r7.u32);
	// stw r27,40(r11)
	PPC_STORE_U32(ctx.r11.u32 + 40, ctx.r27.u32);
loc_88141CE0:
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// bge 0x88141d94
	if (!ctx.cr0.lt) goto loc_88141D94;
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// stw r30,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r30.u32);
	// addic. r11,r11,-2
	ctx.xer.ca = ctx.r11.u32 > 1;
	ctx.r11.s64 = ctx.r11.s64 + -2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// bgt 0x88141d08
	if (ctx.cr0.gt) goto loc_88141D08;
	// stw r27,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r27.u32);
loc_88141D08:
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88141d48
	if (ctx.cr6.eq) goto loc_88141D48;
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// bge cr6,0x88141d3c
	if (!ctx.cr6.lt) goto loc_88141D3C;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// b 0x88141d40
	goto loc_88141D40;
loc_88141D24:
	// lwz r10,24(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88141d34
	if (ctx.cr6.eq) goto loc_88141D34;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_88141D34:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x88141c90
	goto loc_88141C90;
loc_88141D3C:
	// addi r11,r11,-8
	ctx.r11.s64 = ctx.r11.s64 + -8;
loc_88141D40:
	// clrlwi r10,r11,23
	ctx.r10.u64 = ctx.r11.u32 & 0x1FF;
	// stw r10,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r10.u32);
loc_88141D48:
	// lwz r9,76(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// lis r8,-30714
	ctx.r8.s64 = -2012872704;
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// addic. r11,r31,20
	ctx.xer.ca = ctx.r31.u32 > 4294967275;
	ctx.r11.s64 = ctx.r31.s64 + 20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r7,r31,16
	ctx.r7.s64 = ctx.r31.s64 + 16;
	// clrlwi r9,r9,23
	ctx.r9.u64 = ctx.r9.u32 & 0x1FF;
	// addi r8,r8,9552
	ctx.r8.s64 = ctx.r8.s64 + 9552;
	// beq 0x88141d7c
	if (ctx.cr0.eq) goto loc_88141D7C;
	// addi r6,r9,128
	ctx.r6.s64 = ctx.r9.s64 + 128;
	// rlwinm r5,r6,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// lwzx r4,r5,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r8.u32);
	// mullw r3,r4,r10
	ctx.r3.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r10.s32);
	// stw r3,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
loc_88141D7C:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x88141d94
	if (ctx.cr6.eq) goto loc_88141D94;
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r8
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r8.u32);
	// mullw r8,r9,r10
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// stw r8,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r8.u32);
loc_88141D94:
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r8,336
	ctx.r8.s64 = 22020096;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// add r30,r10,r9
	ctx.r30.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// add r29,r11,r10
	ctx.r29.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmpw cr6,r30,r8
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r8.s32, ctx.xer);
	// stw r29,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r29.u32);
	// bge cr6,0x88141e64
	if (!ctx.cr6.lt) goto loc_88141E64;
	// lis r11,280
	ctx.r11.s64 = 18350080;
	// cmpw cr6,r29,r11
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x88141e64
	if (!ctx.cr6.lt) goto loc_88141E64;
	// lis r11,-40
	ctx.r11.s64 = -2621440;
	// cmpw cr6,r29,r11
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x88141e64
	if (!ctx.cr6.gt) goto loc_88141E64;
	// lbz r11,112(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 112);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r9.u8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge cr6,0x88141e70
	if (!ctx.cr6.lt) goto loc_88141E70;
	// lbz r11,110(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 110);
	// lbz r10,113(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 113);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// stb r10,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r10.u8);
	// cmpwi cr6,r8,24
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 24, ctx.xer);
	// stb r8,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r8.u8);
	// blt cr6,0x88141e70
	if (ctx.cr6.lt) goto loc_88141E70;
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lbz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 4);
	// lbz r8,3(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 3);
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// stw r29,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r29.u32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// cmpwi cr6,r11,256
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 256, ctx.xer);
	// sth r9,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, ctx.r9.u16);
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// sth r8,88(r1)
	PPC_STORE_U16(ctx.r1.u32 + 88, ctx.r8.u16);
	// bne cr6,0x88141e44
	if (!ctx.cr6.eq) goto loc_88141E44;
	// sth r27,90(r1)
	PPC_STORE_U16(ctx.r1.u32 + 90, ctx.r27.u16);
	// b 0x88141e50
	goto loc_88141E50;
loc_88141E44:
	// subfic r11,r11,-256
	ctx.xer.ca = ctx.r11.u32 <= 4294967040;
	ctx.r11.s64 = -256 - ctx.r11.s64;
	// clrlwi r10,r11,23
	ctx.r10.u64 = ctx.r11.u32 & 0x1FF;
	// sth r10,90(r1)
	PPC_STORE_U16(ctx.r1.u32 + 90, ctx.r10.u16);
loc_88141E50:
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r11.u32);
	// bl 0x881413a8
	ctx.lr = 0x88141E60;
	sub_881413A8(ctx, base);
	// stb r27,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r27.u8);
loc_88141E64:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_88141E70:
	// lwz r11,120(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// li r6,149
	ctx.r6.s64 = 149;
	// lbz r10,110(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 110);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lhzx r11,r9,r28
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r28.u32);
	// add r27,r11,r10
	ctx.r27.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x881538c0
	ctx.lr = 0x88141E9C;
	sub_881538C0(ctx, base);
	// lis r28,-30597
	ctx.r28.s64 = -2005204992;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88141ed4
	if (ctx.cr6.eq) goto loc_88141ED4;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,128
	ctx.r9.s64 = 8388608;
	// lwz r11,-11932(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -11932);
	// oris r7,r10,531
	ctx.r7.u64 = ctx.r10.u64 | 34799616;
	// ori r8,r9,32896
	ctx.r8.u64 = ctx.r9.u64 | 32896;
	// ori r7,r7,32768
	ctx.r7.u64 = ctx.r7.u64 | 32768;
	// addi r26,r11,1
	ctx.r26.s64 = ctx.r11.s64 + 1;
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r26,-11932(r28)
	PPC_STORE_U32(ctx.r28.u32 + -11932, ctx.r26.u32);
	// b 0x88141ed8
	goto loc_88141ED8;
loc_88141ED4:
	// lwz r26,-11932(r28)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r28.u32 + -11932);
loc_88141ED8:
	// li r6,150
	ctx.r6.s64 = 150;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x881538c0
	ctx.lr = 0x88141EEC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88141f0c
	if (ctx.cr6.eq) goto loc_88141F0C;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// oris r10,r11,545
	ctx.r10.u64 = ctx.r11.u64 | 35717120;
	// stw r26,-11932(r28)
	PPC_STORE_U32(ctx.r28.u32 + -11932, ctx.r26.u32);
	// ori r10,r10,32768
	ctx.r10.u64 = ctx.r10.u64 | 32768;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_88141F0C:
	// lbz r11,110(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 110);
	// li r6,150
	ctx.r6.s64 = 150;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addis r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 65536;
	// addi r3,r3,-20370
	ctx.r3.s64 = ctx.r3.s64 + -20370;
	// bl 0x881538c0
	ctx.lr = 0x88141F2C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88141f58
	if (ctx.cr6.eq) goto loc_88141F58;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,0
	ctx.r9.s64 = 0;
	// addi r11,r26,1
	ctx.r11.s64 = ctx.r26.s64 + 1;
	// oris r7,r10,545
	ctx.r7.u64 = ctx.r10.u64 | 35717120;
	// ori r8,r9,32864
	ctx.r8.u64 = ctx.r9.u64 | 32864;
	// stw r11,-11932(r28)
	PPC_STORE_U32(ctx.r28.u32 + -11932, ctx.r11.u32);
	// ori r7,r7,36864
	ctx.r7.u64 = ctx.r7.u64 | 36864;
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
loc_88141F58:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88141F64"))) PPC_WEAK_FUNC(sub_88141F64);
PPC_FUNC_IMPL(__imp__sub_88141F64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88141F68"))) PPC_WEAK_FUNC(sub_88141F68);
PPC_FUNC_IMPL(__imp__sub_88141F68) {
	PPC_FUNC_PROLOGUE();
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lwz r8,128(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r10,28(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x88141f9c
	if (ctx.cr6.eq) goto loc_88141F9C;
loc_88141F84:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8814202c
	if (ctx.cr6.eq) goto loc_8814202C;
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x88141f84
	if (!ctx.cr6.eq) goto loc_88141F84;
loc_88141F9C:
	// li r10,0
	ctx.r10.s64 = 0;
loc_88141FA0:
	// li r9,8
	ctx.r9.s64 = 8;
	// addi r8,r11,32
	ctx.r8.s64 = ctx.r11.s64 + 32;
	// lis r6,-30671
	ctx.r6.s64 = -2010054656;
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r9,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r9.u32);
	// stw r9,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r9.u32);
	// addi r4,r6,-12728
	ctx.r4.s64 = ctx.r6.s64 + -12728;
	// stw r9,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r9.u32);
	// lis r5,-30700
	ctx.r5.s64 = -2011955200;
	// stw r8,36(r10)
	PPC_STORE_U32(ctx.r10.u32 + 36, ctx.r8.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r6,88(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// addi r8,r5,7088
	ctx.r8.s64 = ctx.r5.s64 + 7088;
	// stw r6,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r6.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r7,40(r10)
	PPC_STORE_U32(ctx.r10.u32 + 40, ctx.r7.u32);
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 128);
	// stw r7,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r7.u32);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lbz r7,114(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 114);
	// lwz r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r10,120(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 120);
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addis r31,r9,-4
	ctx.r31.s64 = ctx.r9.s64 + -262144;
	// stb r5,2(r11)
	PPC_STORE_U8(ctx.r11.u32 + 2, ctx.r5.u8);
	// extsb r9,r7
	ctx.r9.s64 = ctx.r7.s8;
	// stw r8,140(r11)
	PPC_STORE_U32(ctx.r11.u32 + 140, ctx.r8.u32);
	// stw r6,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r6.u32);
	// stw r31,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r31.u32);
	// lhzx r10,r10,r4
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r4.u32);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// sth r9,56(r11)
	PPC_STORE_U16(ctx.r11.u32 + 56, ctx.r9.u16);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_8814202C:
	// lwz r9,24(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8814203c
	if (ctx.cr6.eq) goto loc_8814203C;
	// stw r9,64(r10)
	PPC_STORE_U32(ctx.r10.u32 + 64, ctx.r9.u32);
loc_8814203C:
	// addi r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 + 24;
	// b 0x88141fa0
	goto loc_88141FA0;
}

__attribute__((alias("__imp__sub_88142044"))) PPC_WEAK_FUNC(sub_88142044);
PPC_FUNC_IMPL(__imp__sub_88142044) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88142048"))) PPC_WEAK_FUNC(sub_88142048);
PPC_FUNC_IMPL(__imp__sub_88142048) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071120
	ctx.lr = 0x88142050;
	__savegprlr_14(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// lhz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// addi r19,r11,-11488
	ctx.r19.s64 = ctx.r11.s64 + -11488;
	// lhz r7,8(r3)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// addi r5,r19,-8
	ctx.r5.s64 = ctx.r19.s64 + -8;
	// lbz r3,1(r9)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + 1);
	// extsh r11,r7
	ctx.r11.s64 = ctx.r7.s16;
	// lis r10,-30650
	ctx.r10.s64 = -2008678400;
	// extsb r18,r3
	ctx.r18.s64 = ctx.r3.s8;
	// addi r4,r10,19600
	ctx.r4.s64 = ctx.r10.s64 + 19600;
	// add r8,r11,r18
	ctx.r8.u64 = ctx.r11.u64 + ctx.r18.u64;
	// lbzx r7,r6,r5
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r5.u32);
	// addi r9,r19,-40
	ctx.r9.s64 = ctx.r19.s64 + -40;
	// rlwinm r31,r6,2,0,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r4,-16512
	ctx.r11.s64 = ctx.r4.s64 + -16512;
	// mulli r10,r8,8256
	ctx.r10.s64 = ctx.r8.s64 * 8256;
	// lwzx r27,r31,r9
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r9.u32);
	// li r17,0
	ctx.r17.s64 = 0;
	// extsb r14,r7
	ctx.r14.s64 = ctx.r7.s8;
	// add r28,r10,r11
	ctx.r28.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// mr r8,r17
	ctx.r8.u64 = ctx.r17.u64;
	// cmpwi cr6,r14,0
	ctx.cr6.compare<int32_t>(ctx.r14.s32, 0, ctx.xer);
	// ble cr6,0x881420dc
	if (!ctx.cr6.gt) goto loc_881420DC;
	// addi r10,r1,76
	ctx.r10.s64 = ctx.r1.s64 + 76;
	// li r9,-1
	ctx.r9.s64 = -1;
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x881420dc
	if (ctx.cr6.eq) goto loc_881420DC;
	// mtctr r14
	ctx.ctr.u64 = ctx.r14.u64;
loc_881420D4:
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x881420d4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_881420D4;
loc_881420DC:
	// addi r3,r11,-4
	ctx.r3.s64 = ctx.r11.s64 + -4;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// mr r30,r17
	ctx.r30.u64 = ctx.r17.u64;
	// addi r10,r11,26432
	ctx.r10.s64 = ctx.r11.s64 + 26432;
	// addi r6,r27,2
	ctx.r6.s64 = ctx.r27.s64 + 2;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// lwz r29,324(r10)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + 324);
loc_881420F8:
	// lwz r11,8220(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8220);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,8220(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8220, ctx.r11.u32);
	// cmpwi cr6,r11,50
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 50, ctx.xer);
	// blt cr6,0x88142110
	if (ctx.cr6.lt) goto loc_88142110;
	// stw r17,8220(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8220, ctx.r17.u32);
loc_88142110:
	// lwz r5,8220(r28)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8220);
	// mulli r11,r5,164
	ctx.r11.s64 = ctx.r5.s64 * 164;
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// lbz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 20);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x88142184
	if (!ctx.cr6.eq) goto loc_88142184;
	// lhz r11,0(r6)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r6.u32 + 0);
	// cmpwi cr6,r29,2
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 2, ctx.xer);
	// extsh r9,r11
	ctx.r9.s64 = ctx.r11.s16;
	// bne cr6,0x88142144
	if (!ctx.cr6.eq) goto loc_88142144;
	// cmpwi cr6,r9,5
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 5, ctx.xer);
	// blt cr6,0x88142144
	if (ctx.cr6.lt) goto loc_88142144;
	// li r9,5
	ctx.r9.s64 = 5;
loc_88142144:
	// rlwinm r11,r18,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// addi r25,r4,2644
	ctx.r25.s64 = ctx.r4.s64 + 2644;
	// add r11,r18,r11
	ctx.r11.u64 = ctx.r18.u64 + ctx.r11.u64;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// mulli r11,r11,2648
	ctx.r11.s64 = ctx.r11.s64 * 2648;
	// lwzx r11,r11,r25
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r25.u32);
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x88142190
	if (!ctx.cr6.lt) goto loc_88142190;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stwu r5,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r3.u32 = ea;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// cmpw cr6,r8,r14
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r14.s32, ctx.xer);
	// bge cr6,0x8814219c
	if (!ctx.cr6.lt) goto loc_8814219C;
loc_88142184:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmpwi cr6,r30,50
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 50, ctx.xer);
	// blt cr6,0x881420f8
	if (ctx.cr6.lt) goto loc_881420F8;
loc_88142190:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
loc_8814219C:
	// lwz r11,8244(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8244);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,8244(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8244, ctx.r11.u32);
	// cmpwi cr6,r11,24
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 24, ctx.xer);
	// blt cr6,0x881421b4
	if (ctx.cr6.lt) goto loc_881421B4;
	// stw r17,8244(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8244, ctx.r17.u32);
loc_881421B4:
	// lwz r11,8248(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8248);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,8248(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8248, ctx.r11.u32);
	// cmpwi cr6,r11,14
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 14, ctx.xer);
	// blt cr6,0x881421cc
	if (ctx.cr6.lt) goto loc_881421CC;
	// stw r17,8248(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8248, ctx.r17.u32);
loc_881421CC:
	// addi r11,r19,-808
	ctx.r11.s64 = ctx.r19.s64 + -808;
	// addi r10,r19,-392
	ctx.r10.s64 = ctx.r19.s64 + -392;
	// addi r9,r19,-1032
	ctx.r9.s64 = ctx.r19.s64 + -1032;
	// mr r25,r27
	ctx.r25.u64 = ctx.r27.u64;
	// addi r20,r1,80
	ctx.r20.s64 = ctx.r1.s64 + 80;
	// lwzx r23,r31,r11
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// mr r24,r17
	ctx.r24.u64 = ctx.r17.u64;
	// lwzx r29,r31,r10
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r10.u32);
	// cmpwi cr6,r14,0
	ctx.cr6.compare<int32_t>(ctx.r14.s32, 0, ctx.xer);
	// lwzx r27,r31,r9
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r9.u32);
	// ble cr6,0x88142410
	if (!ctx.cr6.gt) goto loc_88142410;
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// addi r30,r28,8224
	ctx.r30.s64 = ctx.r28.s64 + 8224;
	// li r21,10
	ctx.r21.s64 = 10;
	// li r22,1
	ctx.r22.s64 = 1;
	// li r15,2
	ctx.r15.s64 = 2;
	// addi r16,r11,9552
	ctx.r16.s64 = ctx.r11.s64 + 9552;
loc_88142210:
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x881423ec
	if (ctx.cr6.lt) goto loc_881423EC;
	// mulli r11,r11,164
	ctx.r11.s64 = ctx.r11.s64 * 164;
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// addi r31,r11,20
	ctx.r31.s64 = ctx.r11.s64 + 20;
	// stb r24,23(r11)
	PPC_STORE_U8(ctx.r11.u32 + 23, ctx.r24.u8);
	// lwz r11,-8224(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -8224);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-8224(r30)
	PPC_STORE_U32(ctx.r30.u32 + -8224, ctx.r11.u32);
	// lwz r11,8252(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8252);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stw r9,8252(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8252, ctx.r9.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// blt cr6,0x8814225c
	if (ctx.cr6.lt) goto loc_8814225C;
	// stw r17,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r17.u32);
loc_8814225C:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// stb r21,110(r31)
	PPC_STORE_U8(ctx.r31.u32 + 110, ctx.r21.u8);
	// lwz r7,0(r26)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// lwz r9,16(r26)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r26.u32 + 16);
	// stb r11,114(r31)
	PPC_STORE_U8(ctx.r31.u32 + 114, ctx.r11.u8);
	// lwz r6,8248(r28)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8248);
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r5,r19
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r19.u32);
	// stb r17,113(r31)
	PPC_STORE_U8(ctx.r31.u32 + 113, ctx.r17.u8);
	// stb r4,111(r31)
	PPC_STORE_U8(ctx.r31.u32 + 111, ctx.r4.u8);
	// stb r22,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r22.u8);
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// stw r11,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r11.u32);
	// lwz r8,4(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// stw r7,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r7.u32);
	// lwz r11,20(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 20);
	// lhz r7,4(r26)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r26.u32 + 4);
	// stb r18,1(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1, ctx.r18.u8);
	// stb r22,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r22.u8);
	// stw r8,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r8.u32);
	// lwz r8,4(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stw r6,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// stb r7,4(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4, ctx.r7.u8);
	// lhz r4,0(r25)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r25.u32 + 0);
	// extsh r3,r4
	ctx.r3.s64 = ctx.r4.s16;
	// stw r3,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r3.u32);
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// stw r11,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// cmpwi cr6,r11,256
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 256, ctx.xer);
	// beq cr6,0x88142318
	if (ctx.cr6.eq) goto loc_88142318;
	// lbz r10,111(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 111);
	// ble cr6,0x88142300
	if (!ctx.cr6.gt) goto loc_88142300;
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r9,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r9.u32);
	// b 0x8814230c
	goto loc_8814230C;
loc_88142300:
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// subf r8,r9,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r9.s64;
	// stw r8,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r8.u32);
loc_8814230C:
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// clrlwi r10,r11,23
	ctx.r10.u64 = ctx.r11.u32 & 0x1FF;
	// stw r10,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r10.u32);
loc_88142318:
	// lwz r7,12(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// addic. r11,r31,20
	ctx.xer.ca = ctx.r31.u32 > 4294967275;
	ctx.r11.s64 = ctx.r31.s64 + 20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r15,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r15.u32);
	// addi r8,r31,16
	ctx.r8.s64 = ctx.r31.s64 + 16;
	// lwz r6,76(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// clrlwi r9,r6,23
	ctx.r9.u64 = ctx.r6.u32 & 0x1FF;
	// stw r7,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r7.u32);
	// lwz r5,0(r23)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r23.u32 + 0);
	// stw r5,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r5.u32);
	// lwz r4,0(r23)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r23.u32 + 0);
	// stw r4,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r4.u32);
	// lwz r3,4(r23)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r23.u32 + 4);
	// stw r3,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r3.u32);
	// beq 0x88142368
	if (ctx.cr0.eq) goto loc_88142368;
	// addi r7,r9,128
	ctx.r7.s64 = ctx.r9.s64 + 128;
	// rlwinm r6,r7,2,21,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x7FC;
	// lwzx r5,r6,r16
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r16.u32);
	// mullw r4,r5,r10
	ctx.r4.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r10.s32);
	// stw r4,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r4.u32);
loc_88142368:
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x88142380
	if (ctx.cr6.eq) goto loc_88142380;
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r16
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r16.u32);
	// mullw r7,r9,r10
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// stw r7,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
loc_88142380:
	// lbz r11,1(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r4,r11,4
	ctx.r4.s64 = ctx.r11.s64 + 4;
	// bl 0x881556a0
	ctx.lr = 0x88142390;
	sub_881556A0(ctx, base);
	// stw r3,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r3.u32);
	// mr r10,r17
	ctx.r10.u64 = ctx.r17.u64;
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x881423bc
	if (ctx.cr6.eq) goto loc_881423BC;
loc_881423A4:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8814241c
	if (ctx.cr6.eq) goto loc_8814241C;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x881423a4
	if (!ctx.cr6.eq) goto loc_881423A4;
loc_881423BC:
	// mr r11,r17
	ctx.r11.u64 = ctx.r17.u64;
loc_881423C0:
	// lis r10,-30700
	ctx.r10.s64 = -2011955200;
	// stw r17,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r17.u32);
	// lis r9,-30700
	ctx.r9.s64 = -2011955200;
	// lwz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// addi r7,r10,6920
	ctx.r7.s64 = ctx.r10.s64 + 6920;
	// stw r31,36(r8)
	PPC_STORE_U32(ctx.r8.u32 + 36, ctx.r31.u32);
	// addi r6,r9,8040
	ctx.r6.s64 = ctx.r9.s64 + 8040;
	// stw r7,32(r8)
	PPC_STORE_U32(ctx.r8.u32 + 32, ctx.r7.u32);
	// stw r17,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r17.u32);
	// stb r17,2(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2, ctx.r17.u8);
	// stw r6,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r6.u32);
loc_881423EC:
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// addi r23,r23,8
	ctx.r23.s64 = ctx.r23.s64 + 8;
	// addi r29,r29,16
	ctx.r29.s64 = ctx.r29.s64 + 16;
	// addi r27,r27,8
	ctx.r27.s64 = ctx.r27.s64 + 8;
	// addi r25,r25,4
	ctx.r25.s64 = ctx.r25.s64 + 4;
	// addi r20,r20,4
	ctx.r20.s64 = ctx.r20.s64 + 4;
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// cmpw cr6,r24,r14
	ctx.cr6.compare<int32_t>(ctx.r24.s32, ctx.r14.s32, ctx.xer);
	// blt cr6,0x88142210
	if (ctx.cr6.lt) goto loc_88142210;
loc_88142410:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
loc_8814241C:
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8814242c
	if (ctx.cr6.eq) goto loc_8814242C;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_8814242C:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x881423c0
	goto loc_881423C0;
}

__attribute__((alias("__imp__sub_88142434"))) PPC_WEAK_FUNC(sub_88142434);
PPC_FUNC_IMPL(__imp__sub_88142434) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88142438"))) PPC_WEAK_FUNC(sub_88142438);
PPC_FUNC_IMPL(__imp__sub_88142438) {
	PPC_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r11.u8);
	// blr 
	return;
}

