#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_8207D940"))) PPC_WEAK_FUNC(sub_8207D940);
PPC_FUNC_IMPL(__imp__sub_8207D940) {
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
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-23104(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -23104);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8207d968
	if (ctx.cr0.eq) goto loc_8207D968;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8207D964;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x8207d974
	goto loc_8207D974;
loc_8207D968:
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x820826a8
	ctx.lr = 0x8207D970;
	sub_820826A8(ctx, base);
	// twi 31,r0,22
loc_8207D974:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8207D984"))) PPC_WEAK_FUNC(sub_8207D984);
PPC_FUNC_IMPL(__imp__sub_8207D984) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8207D988"))) PPC_WEAK_FUNC(sub_8207D988);
PPC_FUNC_IMPL(__imp__sub_8207D988) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-2816(r1)
	ea = -2816 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r5,76
	ctx.r5.s64 = 76;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// addi r3,r1,100
	ctx.r3.s64 = ctx.r1.s64 + 100;
	// bl 0x8207da20
	ctx.lr = 0x8207D9AC;
	sub_8207DA20(ctx, base);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// li r5,2624
	ctx.r5.s64 = 2624;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x8207da20
	ctx.lr = 0x8207D9CC;
	sub_8207DA20(ctx, base);
	// lwz r9,2808(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2808);
	// lis r11,-16384
	ctx.r11.s64 = -1073741824;
	// li r10,1
	ctx.r10.s64 = 1;
	// ori r11,r11,1047
	ctx.r11.u64 = ctx.r11.u64 | 1047;
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// stw r9,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r9.u32);
	// bl 0x82088af0
	ctx.lr = 0x8207D9F0;
	sub_82088AF0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82088bb8
	ctx.lr = 0x8207D9F8;
	sub_82088BB8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8207da08
	if (!ctx.cr0.eq) goto loc_8207DA08;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x820826a8
	ctx.lr = 0x8207DA08;
	sub_820826A8(ctx, base);
loc_8207DA08:
	// li r3,30
	ctx.r3.s64 = 30;
	// bl 0x821d53c4
	ctx.lr = 0x8207DA10;
	__imp__KeBugCheck(ctx, base);
}

__attribute__((alias("__imp__sub_8207DA10"))) PPC_WEAK_FUNC(sub_8207DA10);
PPC_FUNC_IMPL(__imp__sub_8207DA10) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// stw r3,-11880(r11)
	PPC_STORE_U32(ctx.r11.u32 + -11880, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8207DA1C"))) PPC_WEAK_FUNC(sub_8207DA1C);
PPC_FUNC_IMPL(__imp__sub_8207DA1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8207DA20"))) PPC_WEAK_FUNC(sub_8207DA20);
PPC_FUNC_IMPL(__imp__sub_8207DA20) {
	PPC_FUNC_PROLOGUE();
	// addi r0,r5,1
	ctx.r0.s64 = ctx.r5.s64 + 1;
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// ori r6,r3,0
	ctx.r6.u64 = ctx.r3.u64 | 0;
	// b 0x8207da3c
	goto loc_8207DA3C;
loc_8207DA30:
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
	// stb r4,0(r6)
	PPC_STORE_U8(ctx.r6.u32 + 0, ctx.r4.u8);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
loc_8207DA3C:
	// andi. r0,r6,3
	ctx.r0.u64 = ctx.r6.u64 & 3;
	ctx.cr0.compare<int32_t>(ctx.r0.s32, 0, ctx.xer);
	// bdnzf eq,0x8207da30
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0 && !ctx.cr0.eq) goto loc_8207DA30;
	// rlwimi r4,r4,8,16,23
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r4.u32, 8) & 0xFF00) | (ctx.r4.u64 & 0xFFFFFFFFFFFF00FF);
	// rlwinm. r0,r5,28,4,31
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 28) & 0xFFFFFFF;
	ctx.cr0.compare<int32_t>(ctx.r0.s32, 0, ctx.xer);
	// rlwimi r4,r4,16,0,15
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r4.u32, 16) & 0xFFFF0000) | (ctx.r4.u64 & 0xFFFFFFFF0000FFFF);
	// beq+ 0x8207da70
	if (ctx.cr0.eq) goto loc_8207DA70;
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
loc_8207DA58:
	// stw r4,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r4.u32);
	// stw r4,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r4.u32);
	// stw r4,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r4.u32);
	// stw r4,12(r6)
	PPC_STORE_U32(ctx.r6.u32 + 12, ctx.r4.u32);
	// addi r6,r6,16
	ctx.r6.s64 = ctx.r6.s64 + 16;
	// bdnz+ 0x8207da58
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8207DA58;
loc_8207DA70:
	// rlwinm. r0,r5,30,30,31
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x3;
	ctx.cr0.compare<int32_t>(ctx.r0.s32, 0, ctx.xer);
	// beq- 0x8207da9c
	if (ctx.cr0.eq) goto loc_8207DA9C;
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// stw r4,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r4.u32);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// bdz- 0x8207da9c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_8207DA9C;
	// stw r4,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r4.u32);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// bdz- 0x8207da9c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_8207DA9C;
	// stw r4,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r4.u32);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
loc_8207DA9C:
	// andi. r0,r5,3
	ctx.r0.u64 = ctx.r5.u64 & 3;
	ctx.cr0.compare<int32_t>(ctx.r0.s32, 0, ctx.xer);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// beqlr+ 
	if (ctx.cr0.eq) return;
	// stb r4,0(r6)
	PPC_STORE_U8(ctx.r6.u32 + 0, ctx.r4.u8);
	// bdzlr- 
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) return;
}

__attribute__((alias("__imp__sub_8207DAB0"))) PPC_WEAK_FUNC(sub_8207DAB0);
PPC_FUNC_IMPL(__imp__sub_8207DAB0) {
	PPC_FUNC_PROLOGUE();
	// stb r4,1(r6)
	PPC_STORE_U8(ctx.r6.u32 + 1, ctx.r4.u8);
	// bdzlr- 
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) return;
}

__attribute__((alias("__imp__sub_8207DAB8"))) PPC_WEAK_FUNC(sub_8207DAB8);
PPC_FUNC_IMPL(__imp__sub_8207DAB8) {
	PPC_FUNC_PROLOGUE();
	// stb r4,2(r6)
	PPC_STORE_U8(ctx.r6.u32 + 2, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8207DAC0"))) PPC_WEAK_FUNC(sub_8207DAC0);
PPC_FUNC_IMPL(__imp__sub_8207DAC0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r3,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r3.u64);
	// clrlwi r6,r3,29
	ctx.r6.u64 = ctx.r3.u32 & 0x7;
	// dcbt r0,r4
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// subfic r6,r6,8
	ctx.xer.ca = ctx.r6.u32 <= 8;
	ctx.r6.s64 = 8 - ctx.r6.s64;
	// beq 0x8207db24
	if (ctx.cr0.eq) goto loc_8207DB24;
	// cmplw r5,r6
	ctx.cr0.compare<uint32_t>(ctx.r5.u32, ctx.r6.u32, ctx.xer);
	// ble 0x8207db40
	if (!ctx.cr0.gt) goto loc_8207DB40;
	// cmplwi r6,4
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 4, ctx.xer);
	// beq 0x8207db10
	if (ctx.cr0.eq) goto loc_8207DB10;
	// addi r3,r3,-1
	ctx.r3.s64 = ctx.r3.s64 + -1;
	// addi r4,r4,-1
	ctx.r4.s64 = ctx.r4.s64 + -1;
	// subf r5,r6,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r6.s64;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
loc_8207DAF8:
	// lbzu r6,1(r4)
	ea = 1 + ctx.r4.u32;
	ctx.r6.u64 = PPC_LOAD_U8(ea);
	ctx.r4.u32 = ea;
	// stbu r6,1(r3)
	ea = 1 + ctx.r3.u32;
	PPC_STORE_U8(ea, ctx.r6.u8);
	ctx.r3.u32 = ea;
	// bdnz 0x8207daf8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8207DAF8;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// b 0x8207db24
	goto loc_8207DB24;
loc_8207DB10:
	// subf r5,r6,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r6.s64;
	// lwz r6,0(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
loc_8207DB24:
	// clrlwi r6,r4,29
	ctx.r6.u64 = ctx.r4.u32 & 0x7;
	// cmplwi cr6,r6,4
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 4, ctx.xer);
	// cmplwi cr1,r6,0
	ctx.cr1.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// cmplwi cr7,r5,128
	ctx.cr7.compare<uint32_t>(ctx.r5.u32, 128, ctx.xer);
	// beq cr6,0x8207dd08
	if (ctx.cr6.eq) goto loc_8207DD08;
	// bne cr1,0x8207de38
	if (!ctx.cr1.eq) goto loc_8207DE38;
	// bge cr7,0x8207dbdc
	if (!ctx.cr7.lt) goto loc_8207DBDC;
loc_8207DB40:
	// dcbtst r0,r3
	// addi r4,r4,-8
	ctx.r4.s64 = ctx.r4.s64 + -8;
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
loc_8207DB4C:
	// rlwinm r7,r5,29,28,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 29) & 0xF;
	// clrlwi r6,r5,29
	ctx.r6.u64 = ctx.r5.u32 & 0x7;
	// cmplwi cr1,r7,0
	ctx.cr1.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr1,0x8207db70
	if (ctx.cr1.eq) goto loc_8207DB70;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_8207DB64:
	// ldu r7,8(r4)
	ea = 8 + ctx.r4.u32;
	ctx.r7.u64 = PPC_LOAD_U64(ea);
	ctx.r4.u32 = ea;
	// stdu r7,8(r3)
	ea = 8 + ctx.r3.u32;
	PPC_STORE_U64(ea, ctx.r7.u64);
	ctx.r3.u32 = ea;
	// bdnz 0x8207db64
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8207DB64;
loc_8207DB70:
	// cmplwi cr1,r6,4
	ctx.cr1.compare<uint32_t>(ctx.r6.u32, 4, ctx.xer);
	// beq cr6,0x8207db94
	if (ctx.cr6.eq) goto loc_8207DB94;
	// beq cr1,0x8207db9c
	if (ctx.cr1.eq) goto loc_8207DB9C;
	// addi r3,r3,7
	ctx.r3.s64 = ctx.r3.s64 + 7;
	// addi r4,r4,7
	ctx.r4.s64 = ctx.r4.s64 + 7;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
loc_8207DB88:
	// lbzu r7,1(r4)
	ea = 1 + ctx.r4.u32;
	ctx.r7.u64 = PPC_LOAD_U8(ea);
	ctx.r4.u32 = ea;
	// stbu r7,1(r3)
	ea = 1 + ctx.r3.u32;
	PPC_STORE_U8(ea, ctx.r7.u8);
	ctx.r3.u32 = ea;
	// bdnz 0x8207db88
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8207DB88;
loc_8207DB94:
	// ld r3,-8(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_8207DB9C:
	// clrlwi r6,r3,30
	ctx.r6.u64 = ctx.r3.u32 & 0x3;
	// lwz r5,8(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne 0x8207dbb8
	if (!ctx.cr0.eq) goto loc_8207DBB8;
	// stw r5,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r5.u32);
	// ld r3,-8(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_8207DBB8:
	// lbz r8,8(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 8);
	// lbz r7,9(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 9);
	// lbz r6,10(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 10);
	// stb r8,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, ctx.r8.u8);
	// stb r7,9(r3)
	PPC_STORE_U8(ctx.r3.u32 + 9, ctx.r7.u8);
	// stb r6,10(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10, ctx.r6.u8);
	// stb r5,11(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11, ctx.r5.u8);
	// ld r3,-8(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_8207DBDC:
	// clrlwi r6,r3,25
	ctx.r6.u64 = ctx.r3.u32 & 0x7F;
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
	// addi r4,r4,-8
	ctx.r4.s64 = ctx.r4.s64 + -8;
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// subfic r6,r6,128
	ctx.xer.ca = ctx.r6.u32 <= 128;
	ctx.r6.s64 = 128 - ctx.r6.s64;
	// beq 0x8207dc0c
	if (ctx.cr0.eq) goto loc_8207DC0C;
	// rlwinm r7,r6,29,3,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 29) & 0x1FFFFFFF;
	// subf r5,r6,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r6.s64;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_8207DC00:
	// ldu r7,8(r4)
	ea = 8 + ctx.r4.u32;
	ctx.r7.u64 = PPC_LOAD_U64(ea);
	ctx.r4.u32 = ea;
	// stdu r7,8(r3)
	ea = 8 + ctx.r3.u32;
	PPC_STORE_U64(ea, ctx.r7.u64);
	ctx.r3.u32 = ea;
	// bdnz 0x8207dc00
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8207DC00;
loc_8207DC0C:
	// rlwinm r6,r5,25,7,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 25) & 0x1FFFFFF;
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq 0x8207db4c
	if (ctx.cr0.eq) goto loc_8207DB4C;
	// addi r10,r5,127
	ctx.r10.s64 = ctx.r5.s64 + 127;
	// clrlwi r8,r5,25
	ctx.r8.u64 = ctx.r5.u32 & 0x7F;
	// rlwinm r10,r10,25,7,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1FFFFFF;
	// cmplwi cr1,r8,0
	ctx.cr1.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// clrlwi r10,r10,29
	ctx.r10.u64 = ctx.r10.u32 & 0x7;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// li r9,8
	ctx.r9.s64 = 8;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8207DC3C:
	// dcbt r9,r4
	// addi r9,r9,128
	ctx.r9.s64 = ctx.r9.s64 + 128;
	// bdnz 0x8207dc3c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8207DC3C;
	// add r12,r4,r5
	ctx.r12.u64 = ctx.r4.u64 + ctx.r5.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// subf r11,r9,r12
	ctx.r11.s64 = ctx.r12.s64 - ctx.r9.s64;
	// add r12,r3,r5
	ctx.r12.u64 = ctx.r3.u64 + ctx.r5.u64;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
loc_8207DC5C:
	// ld r6,8(r4)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r4.u32 + 8);
	// ld r7,16(r4)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r4.u32 + 16);
	// ld r8,24(r4)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r4.u32 + 24);
	// std r6,8(r3)
	PPC_STORE_U64(ctx.r3.u32 + 8, ctx.r6.u64);
	// ld r6,32(r4)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r4.u32 + 32);
	// std r7,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r7.u64);
	// ld r7,40(r4)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r4.u32 + 40);
	// std r8,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, ctx.r8.u64);
	// ld r8,48(r4)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r4.u32 + 48);
	// std r6,32(r3)
	PPC_STORE_U64(ctx.r3.u32 + 32, ctx.r6.u64);
	// ld r6,56(r4)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r4.u32 + 56);
	// std r7,40(r3)
	PPC_STORE_U64(ctx.r3.u32 + 40, ctx.r7.u64);
	// ld r7,64(r4)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r4.u32 + 64);
	// std r8,48(r3)
	PPC_STORE_U64(ctx.r3.u32 + 48, ctx.r8.u64);
	// ld r8,72(r4)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r4.u32 + 72);
	// std r6,56(r3)
	PPC_STORE_U64(ctx.r3.u32 + 56, ctx.r6.u64);
	// ld r6,80(r4)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r4.u32 + 80);
	// std r7,64(r3)
	PPC_STORE_U64(ctx.r3.u32 + 64, ctx.r7.u64);
	// ld r7,88(r4)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r4.u32 + 88);
	// std r8,72(r3)
	PPC_STORE_U64(ctx.r3.u32 + 72, ctx.r8.u64);
	// ld r8,96(r4)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r4.u32 + 96);
	// std r6,80(r3)
	PPC_STORE_U64(ctx.r3.u32 + 80, ctx.r6.u64);
	// ld r6,104(r4)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r4.u32 + 104);
	// std r7,88(r3)
	PPC_STORE_U64(ctx.r3.u32 + 88, ctx.r7.u64);
	// ld r7,112(r4)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r4.u32 + 112);
	// std r8,96(r3)
	PPC_STORE_U64(ctx.r3.u32 + 96, ctx.r8.u64);
	// ld r8,120(r4)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r4.u32 + 120);
	// std r6,104(r3)
	PPC_STORE_U64(ctx.r3.u32 + 104, ctx.r6.u64);
	// ldu r6,128(r4)
	ea = 128 + ctx.r4.u32;
	ctx.r6.u64 = PPC_LOAD_U64(ea);
	ctx.r4.u32 = ea;
	// std r7,112(r3)
	PPC_STORE_U64(ctx.r3.u32 + 112, ctx.r7.u64);
	// std r8,120(r3)
	PPC_STORE_U64(ctx.r3.u32 + 120, ctx.r8.u64);
	// stdu r6,128(r3)
	ea = 128 + ctx.r3.u32;
	PPC_STORE_U64(ea, ctx.r6.u64);
	ctx.r3.u32 = ea;
	// cmplw r4,r11
	ctx.cr0.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// bge 0x8207dcf0
	if (!ctx.cr0.lt) goto loc_8207DCF0;
	// dcbt r9,r4
	// bdnz 0x8207dc5c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8207DC5C;
	// b 0x8207db4c
	goto loc_8207DB4C;
loc_8207DCF0:
	// beq cr1,0x8207dd00
	if (ctx.cr1.eq) goto loc_8207DD00;
	// li r8,-1
	ctx.r8.s64 = -1;
	// dcbtst r8,r12
	// cmplwi cr1,r8,0
	ctx.cr1.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
loc_8207DD00:
	// bdnz 0x8207dc5c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8207DC5C;
	// b 0x8207db4c
	goto loc_8207DB4C;
loc_8207DD08:
	// addi r4,r4,-4
	ctx.r4.s64 = ctx.r4.s64 + -4;
	// bge cr7,0x8207dd60
	if (!ctx.cr7.lt) goto loc_8207DD60;
	// dcbtst r0,r3
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
loc_8207DD18:
	// rlwinm r7,r5,30,27,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x1F;
	// clrlwi r6,r5,30
	ctx.r6.u64 = ctx.r5.u32 & 0x3;
	// cmplwi cr1,r7,0
	ctx.cr1.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr1,0x8207dd3c
	if (ctx.cr1.eq) goto loc_8207DD3C;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_8207DD30:
	// lwzu r7,4(r4)
	ea = 4 + ctx.r4.u32;
	ctx.r7.u64 = PPC_LOAD_U32(ea);
	ctx.r4.u32 = ea;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// bdnz 0x8207dd30
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8207DD30;
loc_8207DD3C:
	// beq cr6,0x8207dd58
	if (ctx.cr6.eq) goto loc_8207DD58;
	// addi r3,r3,3
	ctx.r3.s64 = ctx.r3.s64 + 3;
	// addi r4,r4,3
	ctx.r4.s64 = ctx.r4.s64 + 3;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
loc_8207DD4C:
	// lbzu r7,1(r4)
	ea = 1 + ctx.r4.u32;
	ctx.r7.u64 = PPC_LOAD_U8(ea);
	ctx.r4.u32 = ea;
	// stbu r7,1(r3)
	ea = 1 + ctx.r3.u32;
	PPC_STORE_U8(ea, ctx.r7.u8);
	ctx.r3.u32 = ea;
	// bdnz 0x8207dd4c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8207DD4C;
loc_8207DD58:
	// ld r3,-8(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_8207DD60:
	// clrlwi r6,r3,25
	ctx.r6.u64 = ctx.r3.u32 & 0x7F;
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// subfic r6,r6,128
	ctx.xer.ca = ctx.r6.u32 <= 128;
	ctx.r6.s64 = 128 - ctx.r6.s64;
	// beq 0x8207dd8c
	if (ctx.cr0.eq) goto loc_8207DD8C;
	// rlwinm r7,r6,30,2,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 30) & 0x3FFFFFFF;
	// subf r5,r6,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r6.s64;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_8207DD80:
	// lwzu r7,4(r4)
	ea = 4 + ctx.r4.u32;
	ctx.r7.u64 = PPC_LOAD_U32(ea);
	ctx.r4.u32 = ea;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// bdnz 0x8207dd80
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8207DD80;
loc_8207DD8C:
	// rlwinm r6,r5,25,7,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 25) & 0x1FFFFFF;
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq 0x8207dd18
	if (ctx.cr0.eq) goto loc_8207DD18;
	// addi r10,r5,127
	ctx.r10.s64 = ctx.r5.s64 + 127;
	// clrlwi r8,r5,25
	ctx.r8.u64 = ctx.r5.u32 & 0x7F;
	// rlwinm r10,r10,25,7,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1FFFFFF;
	// cmplwi cr1,r8,0
	ctx.cr1.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// clrlwi r10,r10,29
	ctx.r10.u64 = ctx.r10.u32 & 0x7;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// li r9,4
	ctx.r9.s64 = 4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8207DDBC:
	// dcbt r9,r4
	// addi r9,r9,128
	ctx.r9.s64 = ctx.r9.s64 + 128;
	// bdnz 0x8207ddbc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8207DDBC;
	// add r12,r4,r5
	ctx.r12.u64 = ctx.r4.u64 + ctx.r5.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// subf r11,r9,r12
	ctx.r11.s64 = ctx.r12.s64 - ctx.r9.s64;
	// add r12,r3,r5
	ctx.r12.u64 = ctx.r3.u64 + ctx.r5.u64;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
loc_8207DDDC:
	// li r6,8
	ctx.r6.s64 = 8;
loc_8207DDE0:
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// lwz r0,4(r4)
	ctx.r0.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r7,8(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r8,12(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// stw r0,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r0.u32);
	// lwzu r0,16(r4)
	ea = 16 + ctx.r4.u32;
	ctx.r0.u64 = PPC_LOAD_U32(ea);
	ctx.r4.u32 = ea;
	// stw r7,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r7.u32);
	// stw r8,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r8.u32);
	// stwu r0,16(r3)
	ea = 16 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r0.u32);
	ctx.r3.u32 = ea;
	// bne 0x8207dde0
	if (!ctx.cr0.eq) goto loc_8207DDE0;
	// cmplw r4,r11
	ctx.cr0.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// bge 0x8207de20
	if (!ctx.cr0.lt) goto loc_8207DE20;
	// dcbt r9,r4
	// bdnz 0x8207dddc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8207DDDC;
	// b 0x8207dd18
	goto loc_8207DD18;
loc_8207DE20:
	// beq cr1,0x8207de30
	if (ctx.cr1.eq) goto loc_8207DE30;
	// li r8,-1
	ctx.r8.s64 = -1;
	// dcbtst r8,r12
	// cmplwi cr1,r8,0
	ctx.cr1.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
loc_8207DE30:
	// bdnz 0x8207dddc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8207DDDC;
	// b 0x8207dd18
	goto loc_8207DD18;
loc_8207DE38:
	// addi r4,r4,-1
	ctx.r4.s64 = ctx.r4.s64 + -1;
	// bge cr7,0x8207de6c
	if (!ctx.cr7.lt) goto loc_8207DE6C;
	// dcbtst r0,r3
	// addi r3,r3,-1
	ctx.r3.s64 = ctx.r3.s64 + -1;
loc_8207DE48:
	// clrlwi r6,r5,25
	ctx.r6.u64 = ctx.r5.u32 & 0x7F;
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// beq 0x8207de64
	if (ctx.cr0.eq) goto loc_8207DE64;
loc_8207DE58:
	// lbzu r6,1(r4)
	ea = 1 + ctx.r4.u32;
	ctx.r6.u64 = PPC_LOAD_U8(ea);
	ctx.r4.u32 = ea;
	// stbu r6,1(r3)
	ea = 1 + ctx.r3.u32;
	PPC_STORE_U8(ea, ctx.r6.u8);
	ctx.r3.u32 = ea;
	// bdnz 0x8207de58
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8207DE58;
loc_8207DE64:
	// ld r3,-8(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_8207DE6C:
	// clrlwi r6,r3,25
	ctx.r6.u64 = ctx.r3.u32 & 0x7F;
	// addi r3,r3,-1
	ctx.r3.s64 = ctx.r3.s64 + -1;
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// subfic r6,r6,128
	ctx.xer.ca = ctx.r6.u32 <= 128;
	ctx.r6.s64 = 128 - ctx.r6.s64;
	// beq 0x8207de94
	if (ctx.cr0.eq) goto loc_8207DE94;
	// subf r5,r6,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r6.s64;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
loc_8207DE88:
	// lbzu r6,1(r4)
	ea = 1 + ctx.r4.u32;
	ctx.r6.u64 = PPC_LOAD_U8(ea);
	ctx.r4.u32 = ea;
	// stbu r6,1(r3)
	ea = 1 + ctx.r3.u32;
	PPC_STORE_U8(ea, ctx.r6.u8);
	ctx.r3.u32 = ea;
	// bdnz 0x8207de88
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8207DE88;
loc_8207DE94:
	// rlwinm r6,r5,25,7,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 25) & 0x1FFFFFF;
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq 0x8207de48
	if (ctx.cr0.eq) goto loc_8207DE48;
	// addi r10,r5,127
	ctx.r10.s64 = ctx.r5.s64 + 127;
	// clrlwi r8,r5,25
	ctx.r8.u64 = ctx.r5.u32 & 0x7F;
	// rlwinm r10,r10,25,7,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1FFFFFF;
	// cmplwi cr1,r8,0
	ctx.cr1.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// clrlwi r10,r10,29
	ctx.r10.u64 = ctx.r10.u32 & 0x7;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// li r9,1
	ctx.r9.s64 = 1;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8207DEC4:
	// dcbt r9,r4
	// addi r9,r9,128
	ctx.r9.s64 = ctx.r9.s64 + 128;
	// bdnz 0x8207dec4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8207DEC4;
	// add r12,r4,r5
	ctx.r12.u64 = ctx.r4.u64 + ctx.r5.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// subf r11,r9,r12
	ctx.r11.s64 = ctx.r12.s64 - ctx.r9.s64;
	// add r12,r3,r5
	ctx.r12.u64 = ctx.r3.u64 + ctx.r5.u64;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
loc_8207DEE4:
	// li r6,32
	ctx.r6.s64 = 32;
loc_8207DEE8:
	// lbz r7,4(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 4);
	// lbz r8,3(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 3);
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// rlwimi r7,r8,8,16,23
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r7.u64 & 0xFFFFFFFFFFFF00FF);
	// lbz r9,2(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 2);
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// rlwimi r7,r9,16,8,15
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r9.u32, 16) & 0xFF0000) | (ctx.r7.u64 & 0xFFFFFFFFFF00FFFF);
	// lbz r10,1(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// rlwimi r7,r10,24,0,7
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r10.u32, 24) & 0xFF000000) | (ctx.r7.u64 & 0xFFFFFFFF00FFFFFF);
	// stw r7,1(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1, ctx.r7.u32);
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// bne 0x8207dee8
	if (!ctx.cr0.eq) goto loc_8207DEE8;
	// cmplw r4,r11
	ctx.cr0.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// bge 0x8207df30
	if (!ctx.cr0.lt) goto loc_8207DF30;
	// dcbt r9,r4
	// bdnz 0x8207dee4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8207DEE4;
	// b 0x8207de48
	goto loc_8207DE48;
loc_8207DF30:
	// beq cr1,0x8207df40
	if (ctx.cr1.eq) goto loc_8207DF40;
	// li r8,-1
	ctx.r8.s64 = -1;
	// dcbtst r8,r12
	// cmplwi cr1,r8,0
	ctx.cr1.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
loc_8207DF40:
	// bdnz 0x8207dee4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8207DEE4;
	// b 0x8207de48
	goto loc_8207DE48;
}

__attribute__((alias("__imp__sub_8207DF48"))) PPC_WEAK_FUNC(sub_8207DF48);
PPC_FUNC_IMPL(__imp__sub_8207DF48) {
	PPC_FUNC_PROLOGUE();
	// addi r0,r5,1
	ctx.r0.s64 = ctx.r5.s64 + 1;
	// ori r6,r3,0
	ctx.r6.u64 = ctx.r3.u64 | 0;
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// b 0x8207df6c
	goto loc_8207DF6C;
loc_8207DF58:
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
	// lbz r0,0(r4)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// stb r0,0(r6)
	PPC_STORE_U8(ctx.r6.u32 + 0, ctx.r0.u8);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
loc_8207DF6C:
	// andi. r0,r6,3
	ctx.r0.u64 = ctx.r6.u64 & 3;
	ctx.cr0.compare<int32_t>(ctx.r0.s32, 0, ctx.xer);
	// bdnzf eq,0x8207df58
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0 && !ctx.cr0.eq) goto loc_8207DF58;
	// rlwinm. r0,r5,30,2,31
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x3FFFFFFF;
	ctx.cr0.compare<int32_t>(ctx.r0.s32, 0, ctx.xer);
	// beq- 0x8207df9c
	if (ctx.cr0.eq) goto loc_8207DF9C;
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// andi. r0,r4,3
	ctx.r0.u64 = ctx.r4.u64 & 3;
	ctx.cr0.compare<int32_t>(ctx.r0.s32, 0, ctx.xer);
	// bne- 0x8207dfc0
	if (!ctx.cr0.eq) goto loc_8207DFC0;
loc_8207DF88:
	// lwz r7,0(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// stw r7,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r7.u32);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// bdnz+ 0x8207df88
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8207DF88;
loc_8207DF9C:
	// andi. r0,r5,3
	ctx.r0.u64 = ctx.r5.u64 & 3;
	ctx.cr0.compare<int32_t>(ctx.r0.s32, 0, ctx.xer);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// beqlr+ 
	if (ctx.cr0.eq) return;
loc_8207DFA8:
	// lbz r0,0(r4)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// stb r0,0(r6)
	PPC_STORE_U8(ctx.r6.u32 + 0, ctx.r0.u8);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// bdnz+ 0x8207dfa8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8207DFA8;
	// blr 
	return;
loc_8207DFC0:
	// lbz r7,3(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 3);
	// lbz r8,2(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 2);
	// rlwimi r7,r8,8,16,23
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r7.u64 & 0xFFFFFFFFFFFF00FF);
	// lbz r9,1(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// rlwimi r7,r9,16,8,15
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r9.u32, 16) & 0xFF0000) | (ctx.r7.u64 & 0xFFFFFFFFFF00FFFF);
	// lbz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// rlwimi r7,r10,24,0,7
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r10.u32, 24) & 0xFF000000) | (ctx.r7.u64 & 0xFFFFFFFF00FFFFFF);
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// stw r7,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r7.u32);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// bdnz 0x8207dfc0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8207DFC0;
	// b 0x8207df9c
	goto loc_8207DF9C;
}

__attribute__((alias("__imp__sub_8207DFF0"))) PPC_WEAK_FUNC(sub_8207DFF0);
PPC_FUNC_IMPL(__imp__sub_8207DFF0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x8207DFF8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8207e018
	if (!ctx.cr6.eq) goto loc_8207E018;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x8207a400
	ctx.lr = 0x8207E014;
	sub_8207A400(ctx, base);
	// b 0x8207e0a4
	goto loc_8207E0A4;
loc_8207E018:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8207e02c
	if (!ctx.cr6.eq) goto loc_8207E02C;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8207c068
	ctx.lr = 0x8207E028;
	sub_8207C068(ctx, base);
	// b 0x8207e0a0
	goto loc_8207E0A0;
loc_8207E02C:
	// li r29,-4096
	ctx.r29.s64 = -4096;
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// bgt cr6,0x8207e088
	if (ctx.cr6.gt) goto loc_8207E088;
	// lis r27,-32225
	ctx.r27.s64 = -2111897600;
loc_8207E03C:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8207e048
	if (!ctx.cr6.eq) goto loc_8207E048;
	// li r31,1
	ctx.r31.s64 = 1;
loc_8207E048:
	// bl 0x8208d8f8
	ctx.lr = 0x8207E04C;
	sub_8208D8F8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// bl 0x8208d018
	ctx.lr = 0x8207E05C;
	sub_8208D018(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x8207e0d8
	if (!ctx.cr0.eq) goto loc_8207E0D8;
	// lwz r11,-12276(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + -12276);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8207e0c4
	if (ctx.cr6.eq) goto loc_8207E0C4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207a4d8
	ctx.lr = 0x8207E078;
	sub_8207A4D8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8207e0ac
	if (ctx.cr0.eq) goto loc_8207E0AC;
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// ble cr6,0x8207e03c
	if (!ctx.cr6.gt) goto loc_8207E03C;
loc_8207E088:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207a4d8
	ctx.lr = 0x8207E090;
	sub_8207A4D8(ctx, base);
	// bl 0x8207d4d8
	ctx.lr = 0x8207E094;
	sub_8207D4D8(ctx, base);
	// li r10,12
	ctx.r10.s64 = 12;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_8207E0A0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8207E0A4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_8207E0AC:
	// bl 0x8207d4d8
	ctx.lr = 0x8207E0B0;
	sub_8207D4D8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82089a10
	ctx.lr = 0x8207E0B8;
	sub_82089A10(ctx, base);
	// bl 0x8207d468
	ctx.lr = 0x8207E0BC;
	sub_8207D468(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// b 0x8207e0a0
	goto loc_8207E0A0;
loc_8207E0C4:
	// bl 0x8207d4d8
	ctx.lr = 0x8207E0C8;
	sub_8207D4D8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82089a10
	ctx.lr = 0x8207E0D0;
	sub_82089A10(ctx, base);
	// bl 0x8207d468
	ctx.lr = 0x8207E0D4;
	sub_8207D468(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
loc_8207E0D8:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// b 0x8207e0a4
	goto loc_8207E0A4;
}

__attribute__((alias("__imp__sub_8207E0E0"))) PPC_WEAK_FUNC(sub_8207E0E0);
PPC_FUNC_IMPL(__imp__sub_8207E0E0) {
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
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8207e128
	if (!ctx.cr6.eq) goto loc_8207E128;
	// bl 0x8207d4d8
	ctx.lr = 0x8207E100;
	sub_8207D4D8(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d940
	ctx.lr = 0x8207E120;
	sub_8207D940(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x8207e138
	goto loc_8207E138;
loc_8207E128:
	// bl 0x8208d8f8
	ctx.lr = 0x8207E12C;
	sub_8208D8F8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// bl 0x8208b6d0
	ctx.lr = 0x8207E138;
	sub_8208B6D0(ctx, base);
loc_8207E138:
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

__attribute__((alias("__imp__sub_8207E14C"))) PPC_WEAK_FUNC(sub_8207E14C);
PPC_FUNC_IMPL(__imp__sub_8207E14C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8207E150"))) PPC_WEAK_FUNC(sub_8207E150);
PPC_FUNC_IMPL(__imp__sub_8207E150) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x820826b8
	ctx.lr = 0x8207E170;
	sub_820826B8(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x8207e19c
	if (!ctx.cr0.eq) goto loc_8207E19C;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8207e19c
	if (ctx.cr6.eq) goto loc_8207E19C;
	// bl 0x8207d4d8
	ctx.lr = 0x8207E188;
	sub_8207D4D8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8207e19c
	if (ctx.cr0.eq) goto loc_8207E19C;
	// bl 0x8207d4d8
	ctx.lr = 0x8207E194;
	sub_8207D4D8(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
loc_8207E19C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8207E1B4"))) PPC_WEAK_FUNC(sub_8207E1B4);
PPC_FUNC_IMPL(__imp__sub_8207E1B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8207E1B8"))) PPC_WEAK_FUNC(sub_8207E1B8);
PPC_FUNC_IMPL(__imp__sub_8207E1B8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8207E1C0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r3,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r3.u32);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// bl 0x820809e8
	ctx.lr = 0x8207E1D4;
	sub_820809E8(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// andi. r10,r11,130
	ctx.r10.u64 = ctx.r11.u64 & 130;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// cmpwi r10,0
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8207e20c
	if (!ctx.cr0.eq) goto loc_8207E20C;
	// bl 0x8207d4d8
	ctx.lr = 0x8207E1EC;
	sub_8207D4D8(ctx, base);
	// li r10,9
	ctx.r10.s64 = 9;
loc_8207E1F0:
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_8207E1F8:
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
loc_8207E1FC:
	// ori r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 | 32;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// b 0x8207e384
	goto loc_8207E384;
loc_8207E20C:
	// rlwinm. r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8207e220
	if (ctx.cr0.eq) goto loc_8207E220;
	// bl 0x8207d4d8
	ctx.lr = 0x8207E218;
	sub_8207D4D8(ctx, base);
	// li r10,34
	ctx.r10.s64 = 34;
	// b 0x8207e1f0
	goto loc_8207E1F0;
loc_8207E220:
	// clrlwi. r9,r11,31
	ctx.r9.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// li r10,0
	ctx.r10.s64 = 0;
	// beq 0x8207e248
	if (ctx.cr0.eq) goto loc_8207E248;
	// rlwinm. r9,r11,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// beq 0x8207e1fc
	if (ctx.cr0.eq) goto loc_8207E1FC;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// rlwinm r11,r11,0,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
loc_8207E248:
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// mr r28,r10
	ctx.r28.u64 = ctx.r10.u64;
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// rlwinm r11,r11,0,28,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// ori r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 2;
	// andi. r10,r11,268
	ctx.r10.u64 = ctx.r11.u64 & 268;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// cmpwi r10,0
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8207e2a4
	if (!ctx.cr0.eq) goto loc_8207E2A4;
	// bl 0x8207c2b8
	ctx.lr = 0x8207E270;
	sub_8207C2B8(ctx, base);
	// addi r11,r3,32
	ctx.r11.s64 = ctx.r3.s64 + 32;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8207e28c
	if (ctx.cr6.eq) goto loc_8207E28C;
	// bl 0x8207c2b8
	ctx.lr = 0x8207E280;
	sub_8207C2B8(ctx, base);
	// addi r11,r3,64
	ctx.r11.s64 = ctx.r3.s64 + 64;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8207e29c
	if (!ctx.cr6.eq) goto loc_8207E29C;
loc_8207E28C:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820d9438
	ctx.lr = 0x8207E294;
	sub_820D9438(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8207e2a4
	if (!ctx.cr0.eq) goto loc_8207E2A4;
loc_8207E29C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820829f8
	ctx.lr = 0x8207E2A4;
	sub_820829F8(ctx, base);
loc_8207E2A4:
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// andi. r11,r11,264
	ctx.r11.u64 = ctx.r11.u64 & 264;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8207e35c
	if (ctx.cr0.eq) goto loc_8207E35C;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// subf. r30,r4,r10
	ctx.r30.s64 = ctx.r10.s64 - ctx.r4.s64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r10,r4,1
	ctx.r10.s64 = ctx.r4.s64 + 1;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// ble 0x8207e2ec
	if (!ctx.cr0.gt) goto loc_8207E2EC;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82080d90
	ctx.lr = 0x8207E2E4;
	sub_82080D90(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// b 0x8207e34c
	goto loc_8207E34C;
loc_8207E2EC:
	// cmpwi cr6,r29,-1
	ctx.cr6.compare<int32_t>(ctx.r29.s32, -1, ctx.xer);
	// beq cr6,0x8207e320
	if (ctx.cr6.eq) goto loc_8207E320;
	// cmpwi cr6,r29,-2
	ctx.cr6.compare<int32_t>(ctx.r29.s32, -2, ctx.xer);
	// beq cr6,0x8207e320
	if (ctx.cr6.eq) goto loc_8207E320;
	// srawi r11,r29,5
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r29.s32 >> 5;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,-23360
	ctx.r10.s64 = ctx.r10.s64 + -23360;
	// clrlwi r11,r29,27
	ctx.r11.u64 = ctx.r29.u32 & 0x1F;
	// mulli r11,r11,72
	ctx.r11.s64 = ctx.r11.s64 * 72;
	// lwzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// b 0x8207e328
	goto loc_8207E328;
loc_8207E320:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,2456
	ctx.r11.s64 = ctx.r11.s64 + 2456;
loc_8207E328:
	// lbz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// rlwinm. r11,r11,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8207e34c
	if (ctx.cr0.eq) goto loc_8207E34C;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82082860
	ctx.lr = 0x8207E344;
	sub_82082860(ctx, base);
	// cmpdi cr6,r3,-1
	ctx.cr6.compare<int64_t>(ctx.r3.s64, -1, ctx.xer);
	// beq cr6,0x8207e1f8
	if (ctx.cr6.eq) goto loc_8207E1F8;
loc_8207E34C:
	// lwz r11,148(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r11.u8);
	// b 0x8207e374
	goto loc_8207E374;
loc_8207E35C:
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,148
	ctx.r4.s64 = ctx.r1.s64 + 148;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r30,1
	ctx.r30.s64 = 1;
	// bl 0x82080d90
	ctx.lr = 0x8207E370;
	sub_82080D90(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
loc_8207E374:
	// cmpw cr6,r28,r30
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r30.s32, ctx.xer);
	// bne cr6,0x8207e1f8
	if (!ctx.cr6.eq) goto loc_8207E1F8;
	// lwz r11,148(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
loc_8207E384:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8207E38C"))) PPC_WEAK_FUNC(sub_8207E38C);
PPC_FUNC_IMPL(__imp__sub_8207E38C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8207E390"))) PPC_WEAK_FUNC(sub_8207E390);
PPC_FUNC_IMPL(__imp__sub_8207E390) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8207E398;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,12(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r31,r6
	ctx.r31.u64 = ctx.r6.u64;
	// rlwinm. r11,r11,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8207e3d0
	if (ctx.cr0.eq) goto loc_8207E3D0;
	// lwz r11,8(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8207e3d0
	if (!ctx.cr6.eq) goto loc_8207E3D0;
	// lwz r11,0(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// stw r11,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r11.u32);
	// b 0x8207e424
	goto loc_8207E424;
loc_8207E3D0:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// ble cr6,0x8207e424
	if (!ctx.cr6.gt) goto loc_8207E424;
	// addi r28,r3,-1
	ctx.r28.s64 = ctx.r3.s64 + -1;
loc_8207E3DC:
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// lbzu r3,1(r28)
	ea = 1 + ctx.r28.u32;
	ctx.r3.u64 = PPC_LOAD_U8(ea);
	ctx.r28.u32 = ea;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r30,r30,-1
	ctx.r30.s64 = ctx.r30.s64 + -1;
	// bl 0x8207ef78
	ctx.lr = 0x8207E3F0;
	sub_8207EF78(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x8207e41c
	if (!ctx.cr6.eq) goto loc_8207E41C;
	// bl 0x8207d4d8
	ctx.lr = 0x8207E400;
	sub_8207D4D8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,42
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 42, ctx.xer);
	// bne cr6,0x8207e424
	if (!ctx.cr6.eq) goto loc_8207E424;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,63
	ctx.r3.s64 = 63;
	// bl 0x8207ef78
	ctx.lr = 0x8207E41C;
	sub_8207EF78(ctx, base);
loc_8207E41C:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bgt cr6,0x8207e3dc
	if (ctx.cr6.gt) goto loc_8207E3DC;
loc_8207E424:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8207E42C"))) PPC_WEAK_FUNC(sub_8207E42C);
PPC_FUNC_IMPL(__imp__sub_8207E42C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8207E430"))) PPC_WEAK_FUNC(sub_8207E430);
PPC_FUNC_IMPL(__imp__sub_8207E430) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c950
	ctx.lr = 0x8207E438;
	__savegprlr_14(ctx, base);
	// stwu r1,-1328(r1)
	ea = -1328 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r18,r3
	ctx.r18.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// stw r30,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r30.u32);
	// mr r26,r6
	ctx.r26.u64 = ctx.r6.u64;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r30.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// mr r27,r30
	ctx.r27.u64 = ctx.r30.u64;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// mr r25,r30
	ctx.r25.u64 = ctx.r30.u64;
	// mr r16,r30
	ctx.r16.u64 = ctx.r30.u64;
	// bne cr6,0x8207e49c
	if (!ctx.cr6.eq) goto loc_8207E49C;
loc_8207E470:
	// bl 0x8207d4d8
	ctx.lr = 0x8207E474;
	sub_8207D4D8(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d940
	ctx.lr = 0x8207E494;
	sub_8207D940(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x8207ef6c
	goto loc_8207EF6C;
loc_8207E49C:
	// lwz r11,12(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	// rlwinm. r11,r11,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8207e538
	if (!ctx.cr0.eq) goto loc_8207E538;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// bl 0x820809e8
	ctx.lr = 0x8207E4B0;
	sub_820809E8(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// addi r11,r11,-23360
	ctx.r11.s64 = ctx.r11.s64 + -23360;
	// addi r8,r10,2456
	ctx.r8.s64 = ctx.r10.s64 + 2456;
	// beq cr6,0x8207e4ec
	if (ctx.cr6.eq) goto loc_8207E4EC;
	// cmpwi cr6,r3,-2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -2, ctx.xer);
	// beq cr6,0x8207e4ec
	if (ctx.cr6.eq) goto loc_8207E4EC;
	// srawi r10,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 5;
	// clrlwi r9,r3,27
	ctx.r9.u64 = ctx.r3.u32 & 0x1F;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mulli r10,r9,72
	ctx.r10.s64 = ctx.r9.s64 * 72;
	// lwzx r9,r7,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r11.u32);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// b 0x8207e4f0
	goto loc_8207E4F0;
loc_8207E4EC:
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
loc_8207E4F0:
	// lbz r10,40(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 40);
	// rlwinm. r10,r10,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8207e470
	if (!ctx.cr0.eq) goto loc_8207E470;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8207e528
	if (ctx.cr6.eq) goto loc_8207E528;
	// cmpwi cr6,r3,-2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -2, ctx.xer);
	// beq cr6,0x8207e528
	if (ctx.cr6.eq) goto loc_8207E528;
	// srawi r10,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 5;
	// clrlwi r9,r3,27
	ctx.r9.u64 = ctx.r3.u32 & 0x1F;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mulli r10,r9,72
	ctx.r10.s64 = ctx.r9.s64 * 72;
	// lwzx r11,r8,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x8207e52c
	goto loc_8207E52C;
loc_8207E528:
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
loc_8207E52C:
	// lbz r11,40(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 40);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8207e470
	if (!ctx.cr0.eq) goto loc_8207E470;
loc_8207E538:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8207e470
	if (ctx.cr6.eq) goto loc_8207E470;
	// bl 0x8207c2b8
	ctx.lr = 0x8207E544;
	sub_8207C2B8(ctx, base);
	// addi r11,r3,32
	ctx.r11.s64 = ctx.r3.s64 + 32;
	// cmplw cr6,r18,r11
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8207ef38
	if (ctx.cr6.eq) goto loc_8207EF38;
	// bl 0x8207c2b8
	ctx.lr = 0x8207E554;
	sub_8207C2B8(ctx, base);
	// addi r11,r3,64
	ctx.r11.s64 = ctx.r3.s64 + 64;
	// cmplw cr6,r18,r11
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8207ef38
	if (ctx.cr6.eq) goto loc_8207EF38;
	// lbz r29,0(r31)
	ctx.r29.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// mr r24,r30
	ctx.r24.u64 = ctx.r30.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// extsb. r8,r29
	ctx.r8.s64 = ctx.r29.s8;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// mr r14,r30
	ctx.r14.u64 = ctx.r30.u64;
	// beq 0x8207ef30
	if (ctx.cr0.eq) goto loc_8207EF30;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lwz r21,112(r1)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lwz r28,112(r1)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r19,r31,-1
	ctx.r19.s64 = ctx.r31.s64 + -1;
	// lis r15,-32256
	ctx.r15.s64 = -2113929216;
	// lis r20,-32256
	ctx.r20.s64 = -2113929216;
	// addi r23,r11,2792
	ctx.r23.s64 = ctx.r11.s64 + 2792;
	// addi r22,r10,2800
	ctx.r22.s64 = ctx.r10.s64 + 2800;
	// addi r17,r9,3960
	ctx.r17.s64 = ctx.r9.s64 + 3960;
loc_8207E5B0:
	// addi r19,r19,1
	ctx.r19.s64 = ctx.r19.s64 + 1;
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// blt cr6,0x8207ef30
	if (ctx.cr6.lt) goto loc_8207EF30;
	// cmpwi cr6,r8,32
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 32, ctx.xer);
	// blt cr6,0x8207e5dc
	if (ctx.cr6.lt) goto loc_8207E5DC;
	// cmpwi cr6,r8,120
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 120, ctx.xer);
	// bgt cr6,0x8207e5dc
	if (ctx.cr6.gt) goto loc_8207E5DC;
	// add r11,r8,r17
	ctx.r11.u64 = ctx.r8.u64 + ctx.r17.u64;
	// lbz r11,-32(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + -32);
	// clrlwi r11,r11,28
	ctx.r11.u64 = ctx.r11.u32 & 0xF;
	// b 0x8207e5e0
	goto loc_8207E5E0;
loc_8207E5DC:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8207E5E0:
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// lbzx r11,r11,r17
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r17.u32);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// srawi r11,r11,4
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 4;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r11.u32);
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// bgt cr6,0x8207ef14
	if (ctx.cr6.gt) goto loc_8207EF14;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8207e7f8
	if (ctx.cr6.eq) goto loc_8207E7F8;
	// bdz 0x8207e62c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_8207E62C;
	// bdz 0x8207e64c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_8207E64C;
	// bdz 0x8207e69c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_8207E69C;
	// bdz 0x8207e6e8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_8207E6E8;
	// bdz 0x8207e6f0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_8207E6F0;
	// bdz 0x8207e728
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_8207E728;
	// b 0x8207e844
	goto loc_8207E844;
loc_8207E62C:
	// li r27,0
	ctx.r27.s64 = 0;
	// li r25,-1
	ctx.r25.s64 = -1;
	// mr r21,r27
	ctx.r21.u64 = ctx.r27.u64;
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r27.u32);
	// stw r27,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r27.u32);
	// mr r16,r27
	ctx.r16.u64 = ctx.r27.u64;
	// stw r27,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r27.u32);
	// b 0x8207ef14
	goto loc_8207EF14;
loc_8207E64C:
	// cmpwi cr6,r8,32
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 32, ctx.xer);
	// beq cr6,0x8207e694
	if (ctx.cr6.eq) goto loc_8207E694;
	// cmpwi cr6,r8,35
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 35, ctx.xer);
	// beq cr6,0x8207e68c
	if (ctx.cr6.eq) goto loc_8207E68C;
	// cmpwi cr6,r8,43
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 43, ctx.xer);
	// beq cr6,0x8207e684
	if (ctx.cr6.eq) goto loc_8207E684;
	// cmpwi cr6,r8,45
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 45, ctx.xer);
	// beq cr6,0x8207e67c
	if (ctx.cr6.eq) goto loc_8207E67C;
	// cmpwi cr6,r8,48
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 48, ctx.xer);
	// bne cr6,0x8207ef14
	if (!ctx.cr6.eq) goto loc_8207EF14;
	// ori r27,r27,8
	ctx.r27.u64 = ctx.r27.u64 | 8;
	// b 0x8207ef14
	goto loc_8207EF14;
loc_8207E67C:
	// ori r27,r27,4
	ctx.r27.u64 = ctx.r27.u64 | 4;
	// b 0x8207ef14
	goto loc_8207EF14;
loc_8207E684:
	// ori r27,r27,1
	ctx.r27.u64 = ctx.r27.u64 | 1;
	// b 0x8207ef14
	goto loc_8207EF14;
loc_8207E68C:
	// ori r27,r27,128
	ctx.r27.u64 = ctx.r27.u64 | 128;
	// b 0x8207ef14
	goto loc_8207EF14;
loc_8207E694:
	// ori r27,r27,2
	ctx.r27.u64 = ctx.r27.u64 | 2;
	// b 0x8207ef14
	goto loc_8207EF14;
loc_8207E69C:
	// cmpwi cr6,r8,42
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 42, ctx.xer);
	// bne cr6,0x8207e6d0
	if (!ctx.cr6.eq) goto loc_8207E6D0;
	// addi r11,r26,7
	ctx.r11.s64 = ctx.r26.s64 + 7;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r26,r11,8
	ctx.r26.s64 = ctx.r11.s64 + 8;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// bge cr6,0x8207ef14
	if (!ctx.cr6.lt) goto loc_8207EF14;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// ori r27,r27,4
	ctx.r27.u64 = ctx.r27.u64 | 4;
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
	// b 0x8207e6e0
	goto loc_8207E6E0;
loc_8207E6D0:
	// lwz r11,96(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// mulli r11,r11,10
	ctx.r11.s64 = ctx.r11.s64 * 10;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// addi r11,r11,-48
	ctx.r11.s64 = ctx.r11.s64 + -48;
loc_8207E6E0:
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// b 0x8207ef14
	goto loc_8207EF14;
loc_8207E6E8:
	// li r25,0
	ctx.r25.s64 = 0;
	// b 0x8207ef14
	goto loc_8207EF14;
loc_8207E6F0:
	// cmpwi cr6,r8,42
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 42, ctx.xer);
	// bne cr6,0x8207e718
	if (!ctx.cr6.eq) goto loc_8207E718;
	// addi r11,r26,7
	ctx.r11.s64 = ctx.r26.s64 + 7;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r26,r11,8
	ctx.r26.s64 = ctx.r11.s64 + 8;
	// lwz r25,4(r11)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// bge cr6,0x8207ef14
	if (!ctx.cr6.lt) goto loc_8207EF14;
	// li r25,-1
	ctx.r25.s64 = -1;
	// b 0x8207ef14
	goto loc_8207EF14;
loc_8207E718:
	// mulli r11,r25,10
	ctx.r11.s64 = ctx.r25.s64 * 10;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// addi r25,r11,-48
	ctx.r25.s64 = ctx.r11.s64 + -48;
	// b 0x8207ef14
	goto loc_8207EF14;
loc_8207E728:
	// cmpwi cr6,r8,73
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 73, ctx.xer);
	// beq cr6,0x8207e778
	if (ctx.cr6.eq) goto loc_8207E778;
	// cmpwi cr6,r8,104
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 104, ctx.xer);
	// beq cr6,0x8207e770
	if (ctx.cr6.eq) goto loc_8207E770;
	// cmpwi cr6,r8,108
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 108, ctx.xer);
	// beq cr6,0x8207e750
	if (ctx.cr6.eq) goto loc_8207E750;
	// cmpwi cr6,r8,119
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 119, ctx.xer);
	// bne cr6,0x8207ef14
	if (!ctx.cr6.eq) goto loc_8207EF14;
	// ori r27,r27,2048
	ctx.r27.u64 = ctx.r27.u64 | 2048;
	// b 0x8207ef14
	goto loc_8207EF14;
loc_8207E750:
	// lbz r11,1(r19)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r19.u32 + 1);
	// cmplwi cr6,r11,108
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 108, ctx.xer);
	// bne cr6,0x8207e768
	if (!ctx.cr6.eq) goto loc_8207E768;
	// addi r19,r19,1
	ctx.r19.s64 = ctx.r19.s64 + 1;
	// ori r27,r27,4096
	ctx.r27.u64 = ctx.r27.u64 | 4096;
	// b 0x8207ef14
	goto loc_8207EF14;
loc_8207E768:
	// ori r27,r27,16
	ctx.r27.u64 = ctx.r27.u64 | 16;
	// b 0x8207ef14
	goto loc_8207EF14;
loc_8207E770:
	// ori r27,r27,32
	ctx.r27.u64 = ctx.r27.u64 | 32;
	// b 0x8207ef14
	goto loc_8207EF14;
loc_8207E778:
	// lbz r11,1(r19)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r19.u32 + 1);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// cmpwi cr6,r11,54
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 54, ctx.xer);
	// bne cr6,0x8207e7a0
	if (!ctx.cr6.eq) goto loc_8207E7A0;
	// lbz r10,2(r19)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r19.u32 + 2);
	// cmplwi cr6,r10,52
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 52, ctx.xer);
	// bne cr6,0x8207e7a0
	if (!ctx.cr6.eq) goto loc_8207E7A0;
	// addi r19,r19,2
	ctx.r19.s64 = ctx.r19.s64 + 2;
	// ori r27,r27,32768
	ctx.r27.u64 = ctx.r27.u64 | 32768;
	// b 0x8207ef14
	goto loc_8207EF14;
loc_8207E7A0:
	// cmpwi cr6,r11,51
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 51, ctx.xer);
	// bne cr6,0x8207e7c0
	if (!ctx.cr6.eq) goto loc_8207E7C0;
	// lbz r10,2(r19)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r19.u32 + 2);
	// cmplwi cr6,r10,50
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 50, ctx.xer);
	// bne cr6,0x8207e7c0
	if (!ctx.cr6.eq) goto loc_8207E7C0;
	// addi r19,r19,2
	ctx.r19.s64 = ctx.r19.s64 + 2;
	// rlwinm r27,r27,0,17,15
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0xFFFFFFFFFFFF7FFF;
	// b 0x8207ef14
	goto loc_8207EF14;
loc_8207E7C0:
	// cmpwi cr6,r11,100
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 100, ctx.xer);
	// beq cr6,0x8207ef14
	if (ctx.cr6.eq) goto loc_8207EF14;
	// cmpwi cr6,r11,105
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 105, ctx.xer);
	// beq cr6,0x8207ef14
	if (ctx.cr6.eq) goto loc_8207EF14;
	// cmpwi cr6,r11,111
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 111, ctx.xer);
	// beq cr6,0x8207ef14
	if (ctx.cr6.eq) goto loc_8207EF14;
	// cmpwi cr6,r11,117
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 117, ctx.xer);
	// beq cr6,0x8207ef14
	if (ctx.cr6.eq) goto loc_8207EF14;
	// cmpwi cr6,r11,120
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 120, ctx.xer);
	// beq cr6,0x8207ef14
	if (ctx.cr6.eq) goto loc_8207EF14;
	// cmpwi cr6,r11,88
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 88, ctx.xer);
	// beq cr6,0x8207ef14
	if (ctx.cr6.eq) goto loc_8207EF14;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r11.u32);
loc_8207E7F8:
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// clrlwi r3,r29,24
	ctx.r3.u64 = ctx.r29.u32 & 0xFF;
	// li r16,0
	ctx.r16.s64 = 0;
	// bl 0x82082ca8
	ctx.lr = 0x8207E808;
	sub_82082CA8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8207e82c
	if (ctx.cr0.eq) goto loc_8207E82C;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8207ef78
	ctx.lr = 0x8207E820;
	sub_8207EF78(ctx, base);
	// lbzu r29,1(r19)
	ea = 1 + ctx.r19.u32;
	ctx.r29.u64 = PPC_LOAD_U8(ea);
	ctx.r19.u32 = ea;
	// cmplwi r29,0
	ctx.cr0.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq 0x8207e470
	if (ctx.cr0.eq) goto loc_8207E470;
loc_8207E82C:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8207ef78
	ctx.lr = 0x8207E83C;
	sub_8207EF78(ctx, base);
	// lwz r24,80(r1)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// b 0x8207ef14
	goto loc_8207EF14;
loc_8207E844:
	// addi r11,r8,-65
	ctx.r11.s64 = ctx.r8.s64 + -65;
	// cmplwi cr6,r11,55
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 55, ctx.xer);
	// bgt cr6,0x8207ed44
	if (ctx.cr6.gt) goto loc_8207ED44;
	// lis r12,-32256
	ctx.r12.s64 = -2113929216;
	// rlwinm r0,r11,1,0,30
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r12,r12,4056
	ctx.r12.s64 = ctx.r12.s64 + 4056;
	// lhzx r0,r12,r0
	ctx.r0.u64 = PPC_LOAD_U16(ctx.r12.u32 + ctx.r0.u32);
	// lis r12,-32248
	ctx.r12.s64 = -2113404928;
	// addi r12,r12,-6024
	ctx.r12.s64 = ctx.r12.s64 + -6024;
	// nop 
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// bctr 
	switch (ctx.r11.u64) {
	case 0:
		goto loc_8207EA54;
	case 1:
		goto loc_8207ED44;
	case 2:
		goto loc_8207E878;
	case 3:
		goto loc_8207ED44;
	case 4:
		goto loc_8207EA54;
	case 5:
		goto loc_8207ED44;
	case 6:
		goto loc_8207EA54;
	case 7:
		goto loc_8207ED44;
	case 8:
		goto loc_8207ED44;
	case 9:
		goto loc_8207ED44;
	case 10:
		goto loc_8207ED44;
	case 11:
		goto loc_8207ED44;
	case 12:
		goto loc_8207ED44;
	case 13:
		goto loc_8207ED44;
	case 14:
		goto loc_8207ED44;
	case 15:
		goto loc_8207ED44;
	case 16:
		goto loc_8207ED44;
	case 17:
		goto loc_8207ED44;
	case 18:
		goto loc_8207E960;
	case 19:
		goto loc_8207ED44;
	case 20:
		goto loc_8207ED44;
	case 21:
		goto loc_8207ED44;
	case 22:
		goto loc_8207ED44;
	case 23:
		goto loc_8207EB94;
	case 24:
		goto loc_8207ED44;
	case 25:
		goto loc_8207E8E4;
	case 26:
		goto loc_8207ED44;
	case 27:
		goto loc_8207ED44;
	case 28:
		goto loc_8207ED44;
	case 29:
		goto loc_8207ED44;
	case 30:
		goto loc_8207ED44;
	case 31:
		goto loc_8207ED44;
	case 32:
		goto loc_8207EA60;
	case 33:
		goto loc_8207ED44;
	case 34:
		goto loc_8207E888;
	case 35:
		goto loc_8207EB84;
	case 36:
		goto loc_8207EA60;
	case 37:
		goto loc_8207EA60;
	case 38:
		goto loc_8207EA60;
	case 39:
		goto loc_8207ED44;
	case 40:
		goto loc_8207EB84;
	case 41:
		goto loc_8207ED44;
	case 42:
		goto loc_8207ED44;
	case 43:
		goto loc_8207ED44;
	case 44:
		goto loc_8207ED44;
	case 45:
		goto loc_8207EA18;
	case 46:
		goto loc_8207EBCC;
	case 47:
		goto loc_8207EB90;
	case 48:
		goto loc_8207ED44;
	case 49:
		goto loc_8207ED44;
	case 50:
		goto loc_8207E970;
	case 51:
		goto loc_8207ED44;
	case 52:
		goto loc_8207EB88;
	case 53:
		goto loc_8207ED44;
	case 54:
		goto loc_8207ED44;
	case 55:
		goto loc_8207EB9C;
	default:
		__builtin_unreachable();
	}
loc_8207E878:
	// andi. r11,r27,2096
	ctx.r11.u64 = ctx.r27.u64 & 2096;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8207e888
	if (!ctx.cr0.eq) goto loc_8207E888;
	// ori r27,r27,2048
	ctx.r27.u64 = ctx.r27.u64 | 2048;
loc_8207E888:
	// andi. r11,r27,2064
	ctx.r11.u64 = ctx.r27.u64 & 2064;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r11,r26,7
	ctx.r11.s64 = ctx.r26.s64 + 7;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r26,r11,8
	ctx.r26.s64 = ctx.r11.s64 + 8;
	// beq 0x8207e8c8
	if (ctx.cr0.eq) goto loc_8207E8C8;
	// li r5,512
	ctx.r5.s64 = 512;
	// lhz r6,6(r11)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r11.u32 + 6);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x82082ca0
	ctx.lr = 0x8207E8B4;
	sub_82082CA0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8207e8d8
	if (ctx.cr0.eq) goto loc_8207E8D8;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// b 0x8207e8d8
	goto loc_8207E8D8;
loc_8207E8C8:
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stb r11,144(r1)
	PPC_STORE_U8(ctx.r1.u32 + 144, ctx.r11.u8);
loc_8207E8D8:
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r28,r1,144
	ctx.r28.s64 = ctx.r1.s64 + 144;
	// b 0x8207ed44
	goto loc_8207ED44;
loc_8207E8E4:
	// addi r11,r26,7
	ctx.r11.s64 = ctx.r26.s64 + 7;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r26,r11,8
	ctx.r26.s64 = ctx.r11.s64 + 8;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8207e934
	if (ctx.cr6.eq) goto loc_8207E934;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8207e934
	if (ctx.cr6.eq) goto loc_8207E934;
	// rlwinm. r9,r27,0,20,20
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x800;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// mr r28,r10
	ctx.r28.u64 = ctx.r10.u64;
	// beq 0x8207e928
	if (ctx.cr0.eq) goto loc_8207E928;
	// lha r11,0(r11)
	ctx.r11.s64 = int16_t(PPC_LOAD_U16(ctx.r11.u32 + 0));
	// li r16,1
	ctx.r16.s64 = 1;
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// addze r6,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r6.s64 = temp.s64;
	// b 0x8207ed40
	goto loc_8207ED40;
loc_8207E928:
	// lha r6,0(r11)
	ctx.r6.s64 = int16_t(PPC_LOAD_U16(ctx.r11.u32 + 0));
	// li r16,0
	ctx.r16.s64 = 0;
	// b 0x8207ed40
	goto loc_8207ED40;
loc_8207E934:
	// lwz r28,3948(r20)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r20.u32 + 3948);
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
loc_8207E940:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8207e940
	if (!ctx.cr6.eq) goto loc_8207E940;
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
loc_8207E954:
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rotlwi r6,r11,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// b 0x8207ed40
	goto loc_8207ED40;
loc_8207E960:
	// andi. r11,r27,2096
	ctx.r11.u64 = ctx.r27.u64 & 2096;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8207e970
	if (!ctx.cr0.eq) goto loc_8207E970;
	// ori r27,r27,2048
	ctx.r27.u64 = ctx.r27.u64 | 2048;
loc_8207E970:
	// cmpwi cr6,r25,-1
	ctx.cr6.compare<int32_t>(ctx.r25.s32, -1, ctx.xer);
	// bne cr6,0x8207e984
	if (!ctx.cr6.eq) goto loc_8207E984;
	// lis r10,32767
	ctx.r10.s64 = 2147418112;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
	// b 0x8207e988
	goto loc_8207E988;
loc_8207E984:
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
loc_8207E988:
	// addi r11,r26,7
	ctx.r11.s64 = ctx.r26.s64 + 7;
	// andi. r9,r27,2064
	ctx.r9.u64 = ctx.r27.u64 & 2064;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// addi r26,r11,8
	ctx.r26.s64 = ctx.r11.s64 + 8;
	// lwz r28,4(r11)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq 0x8207e9e4
	if (ctx.cr0.eq) goto loc_8207E9E4;
	// bne cr6,0x8207e9b0
	if (!ctx.cr6.eq) goto loc_8207E9B0;
	// lwz r28,3952(r15)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r15.u32 + 3952);
loc_8207E9B0:
	// li r16,1
	ctx.r16.s64 = 1;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// b 0x8207e9d0
	goto loc_8207E9D0;
loc_8207E9BC:
	// lhz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq 0x8207e9d8
	if (ctx.cr0.eq) goto loc_8207E9D8;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
loc_8207E9D0:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8207e9bc
	if (!ctx.cr6.eq) goto loc_8207E9BC;
loc_8207E9D8:
	// subf r11,r28,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r28.s64;
	// srawi r6,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r11.s32 >> 1;
	// b 0x8207ed40
	goto loc_8207ED40;
loc_8207E9E4:
	// bne cr6,0x8207e9ec
	if (!ctx.cr6.eq) goto loc_8207E9EC;
	// lwz r28,3948(r20)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r20.u32 + 3948);
loc_8207E9EC:
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// b 0x8207ea08
	goto loc_8207EA08;
loc_8207E9F4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq 0x8207ea10
	if (ctx.cr0.eq) goto loc_8207EA10;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_8207EA08:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8207e9f4
	if (!ctx.cr6.eq) goto loc_8207E9F4;
loc_8207EA10:
	// subf r6,r28,r11
	ctx.r6.s64 = ctx.r11.s64 - ctx.r28.s64;
	// b 0x8207ed40
	goto loc_8207ED40;
loc_8207EA18:
	// addi r11,r26,7
	ctx.r11.s64 = ctx.r26.s64 + 7;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r26,r11,8
	ctx.r26.s64 = ctx.r11.s64 + 8;
	// lwz r31,4(r11)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8207bda0
	ctx.lr = 0x8207EA2C;
	sub_8207BDA0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8207e470
	if (ctx.cr0.eq) goto loc_8207E470;
	// rlwinm. r11,r27,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8207ea44
	if (ctx.cr0.eq) goto loc_8207EA44;
	// sth r24,0(r31)
	PPC_STORE_U16(ctx.r31.u32 + 0, ctx.r24.u16);
	// b 0x8207ea48
	goto loc_8207EA48;
loc_8207EA44:
	// stw r24,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r24.u32);
loc_8207EA48:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// b 0x8207ef00
	goto loc_8207EF00;
loc_8207EA54:
	// addi r11,r8,32
	ctx.r11.s64 = ctx.r8.s64 + 32;
	// li r21,1
	ctx.r21.s64 = 1;
	// extsb r29,r11
	ctx.r29.s64 = ctx.r11.s8;
loc_8207EA60:
	// ori r27,r27,64
	ctx.r27.u64 = ctx.r27.u64 | 64;
	// addi r28,r1,144
	ctx.r28.s64 = ctx.r1.s64 + 144;
	// li r30,512
	ctx.r30.s64 = 512;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// bge cr6,0x8207ea7c
	if (!ctx.cr6.lt) goto loc_8207EA7C;
	// li r25,6
	ctx.r25.s64 = 6;
	// b 0x8207eacc
	goto loc_8207EACC;
loc_8207EA7C:
	// bne cr6,0x8207ea94
	if (!ctx.cr6.eq) goto loc_8207EA94;
	// extsb r11,r29
	ctx.r11.s64 = ctx.r29.s8;
	// cmpwi cr6,r11,103
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 103, ctx.xer);
	// bne cr6,0x8207eacc
	if (!ctx.cr6.eq) goto loc_8207EACC;
	// li r25,1
	ctx.r25.s64 = 1;
	// b 0x8207eacc
	goto loc_8207EACC;
loc_8207EA94:
	// cmpwi cr6,r25,512
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 512, ctx.xer);
	// ble cr6,0x8207eaa0
	if (!ctx.cr6.gt) goto loc_8207EAA0;
	// li r25,512
	ctx.r25.s64 = 512;
loc_8207EAA0:
	// cmpwi cr6,r25,163
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 163, ctx.xer);
	// ble cr6,0x8207eacc
	if (!ctx.cr6.gt) goto loc_8207EACC;
	// addi r31,r25,349
	ctx.r31.s64 = ctx.r25.s64 + 349;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207a400
	ctx.lr = 0x8207EAB4;
	sub_8207A400(ctx, base);
	// mr. r14,r3
	ctx.r14.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r14.s32, 0, ctx.xer);
	// beq 0x8207eac8
	if (ctx.cr0.eq) goto loc_8207EAC8;
	// mr r28,r14
	ctx.r28.u64 = ctx.r14.u64;
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
	// b 0x8207eacc
	goto loc_8207EACC;
loc_8207EAC8:
	// li r25,163
	ctx.r25.s64 = 163;
loc_8207EACC:
	// addi r11,r26,7
	ctx.r11.s64 = ctx.r26.s64 + 7;
	// lwz r10,24(r22)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r22.u32 + 24);
	// extsb r31,r29
	ctx.r31.s64 = ctx.r29.s8;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// mr r9,r23
	ctx.r9.u64 = ctx.r23.u64;
	// mr r8,r21
	ctx.r8.u64 = ctx.r21.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// mr r7,r25
	ctx.r7.u64 = ctx.r25.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// ld r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r11.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r26,r11,8
	ctx.r26.s64 = ctx.r11.s64 + 8;
	// std r10,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r10.u64);
	// bctrl 
	ctx.lr = 0x8207EB0C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// rlwinm. r30,r27,0,24,24
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x8207eb30
	if (ctx.cr0.eq) goto loc_8207EB30;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// bne cr6,0x8207eb30
	if (!ctx.cr6.eq) goto loc_8207EB30;
	// lwz r11,36(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 36);
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8207EB30;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8207EB30:
	// cmpwi cr6,r31,103
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 103, ctx.xer);
	// bne cr6,0x8207eb54
	if (!ctx.cr6.eq) goto loc_8207EB54;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x8207eb54
	if (!ctx.cr6.eq) goto loc_8207EB54;
	// lwz r11,32(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 32);
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8207EB54;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8207EB54:
	// lbz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,45
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 45, ctx.xer);
	// bne cr6,0x8207eb68
	if (!ctx.cr6.eq) goto loc_8207EB68;
	// ori r27,r27,256
	ctx.r27.u64 = ctx.r27.u64 | 256;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
loc_8207EB68:
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
loc_8207EB6C:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8207eb6c
	if (!ctx.cr6.eq) goto loc_8207EB6C;
	// subf r11,r28,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r28.s64;
	// b 0x8207e954
	goto loc_8207E954;
loc_8207EB84:
	// ori r27,r27,64
	ctx.r27.u64 = ctx.r27.u64 | 64;
loc_8207EB88:
	// li r8,10
	ctx.r8.s64 = 10;
	// b 0x8207ebdc
	goto loc_8207EBDC;
loc_8207EB90:
	// li r25,8
	ctx.r25.s64 = 8;
loc_8207EB94:
	// li r11,7
	ctx.r11.s64 = 7;
	// b 0x8207eba0
	goto loc_8207EBA0;
loc_8207EB9C:
	// li r11,39
	ctx.r11.s64 = 39;
loc_8207EBA0:
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
	// rlwinm. r10,r27,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// li r8,16
	ctx.r8.s64 = 16;
	// beq 0x8207ebdc
	if (ctx.cr0.eq) goto loc_8207EBDC;
	// addi r11,r11,81
	ctx.r11.s64 = ctx.r11.s64 + 81;
	// li r10,48
	ctx.r10.s64 = 48;
	// li r9,2
	ctx.r9.s64 = 2;
	// stb r11,89(r1)
	PPC_STORE_U8(ctx.r1.u32 + 89, ctx.r11.u8);
	// stb r10,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, ctx.r10.u8);
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// b 0x8207ebdc
	goto loc_8207EBDC;
loc_8207EBCC:
	// rlwinm. r11,r27,0,24,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r8,8
	ctx.r8.s64 = 8;
	// beq 0x8207ebdc
	if (ctx.cr0.eq) goto loc_8207EBDC;
	// ori r27,r27,512
	ctx.r27.u64 = ctx.r27.u64 | 512;
loc_8207EBDC:
	// rlwinm. r11,r27,0,16,16
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x8000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8207ebec
	if (!ctx.cr0.eq) goto loc_8207EBEC;
	// rlwinm. r11,r27,0,19,19
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x1000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8207ec00
	if (ctx.cr0.eq) goto loc_8207EC00;
loc_8207EBEC:
	// addi r11,r26,7
	ctx.r11.s64 = ctx.r26.s64 + 7;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r26,r11,8
	ctx.r26.s64 = ctx.r11.s64 + 8;
	// ld r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r11.u32 + 0);
	// b 0x8207ec50
	goto loc_8207EC50;
loc_8207EC00:
	// rlwinm. r11,r27,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8207ec30
	if (ctx.cr0.eq) goto loc_8207EC30;
	// rlwinm. r11,r27,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r11,r26,7
	ctx.r11.s64 = ctx.r26.s64 + 7;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r26,r11,8
	ctx.r26.s64 = ctx.r11.s64 + 8;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// beq 0x8207ec28
	if (ctx.cr0.eq) goto loc_8207EC28;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// b 0x8207ec50
	goto loc_8207EC50;
loc_8207EC28:
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// b 0x8207ec50
	goto loc_8207EC50;
loc_8207EC30:
	// rlwinm. r11,r27,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r11,r26,7
	ctx.r11.s64 = ctx.r26.s64 + 7;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r26,r11,8
	ctx.r26.s64 = ctx.r11.s64 + 8;
	// beq 0x8207ec4c
	if (ctx.cr0.eq) goto loc_8207EC4C;
	// lwa r11,4(r11)
	ctx.r11.s64 = int32_t(PPC_LOAD_U32(ctx.r11.u32 + 4));
	// b 0x8207ec50
	goto loc_8207EC50;
loc_8207EC4C:
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
loc_8207EC50:
	// rlwinm. r10,r27,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8207ec68
	if (ctx.cr0.eq) goto loc_8207EC68;
	// cmpdi cr6,r11,0
	ctx.cr6.compare<int64_t>(ctx.r11.s64, 0, ctx.xer);
	// bge cr6,0x8207ec68
	if (!ctx.cr6.lt) goto loc_8207EC68;
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
	// ori r27,r27,256
	ctx.r27.u64 = ctx.r27.u64 | 256;
loc_8207EC68:
	// rlwinm. r10,r27,0,16,16
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x8000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8207ec7c
	if (!ctx.cr0.eq) goto loc_8207EC7C;
	// rlwinm. r10,r27,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x1000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8207ec7c
	if (!ctx.cr0.eq) goto loc_8207EC7C;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
loc_8207EC7C:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// bge cr6,0x8207ec8c
	if (!ctx.cr6.lt) goto loc_8207EC8C;
	// li r25,1
	ctx.r25.s64 = 1;
	// b 0x8207ec9c
	goto loc_8207EC9C;
loc_8207EC8C:
	// rlwinm r27,r27,0,29,27
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
	// cmpwi cr6,r25,512
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 512, ctx.xer);
	// ble cr6,0x8207ec9c
	if (!ctx.cr6.gt) goto loc_8207EC9C;
	// li r25,512
	ctx.r25.s64 = 512;
loc_8207EC9C:
	// cmpldi cr6,r11,0
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, 0, ctx.xer);
	// bne cr6,0x8207ecac
	if (!ctx.cr6.eq) goto loc_8207ECAC;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
loc_8207ECAC:
	// addi r9,r1,655
	ctx.r9.s64 = ctx.r1.s64 + 655;
loc_8207ECB0:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// addi r25,r25,-1
	ctx.r25.s64 = ctx.r25.s64 + -1;
	// bgt cr6,0x8207ecc4
	if (ctx.cr6.gt) goto loc_8207ECC4;
	// cmpldi cr6,r11,0
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, 0, ctx.xer);
	// beq cr6,0x8207ed08
	if (ctx.cr6.eq) goto loc_8207ED08;
loc_8207ECC4:
	// extsw r10,r8
	ctx.r10.s64 = ctx.r8.s32;
	// divdu r7,r11,r10
	ctx.r7.u64 = ppc_divdu(ctx.r11.u64, ctx.r10.u64);
	// tdllei r10,0
	// mulld r7,r7,r10
	ctx.r7.s64 = ctx.r7.s64 * ctx.r10.s64;
	// subf r7,r7,r11
	ctx.r7.s64 = ctx.r11.s64 - ctx.r7.s64;
	// divdu r11,r11,r10
	ctx.r11.u64 = ppc_divdu(ctx.r11.u64, ctx.r10.u64);
	// tdllei r10,0
	// rotlwi r10,r7,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// cmpwi cr6,r10,57
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 57, ctx.xer);
	// ble cr6,0x8207ecf8
	if (!ctx.cr6.gt) goto loc_8207ECF8;
	// lwz r7,104(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
loc_8207ECF8:
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// stb r10,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r10.u8);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// b 0x8207ecb0
	goto loc_8207ECB0;
loc_8207ED08:
	// addi r11,r1,655
	ctx.r11.s64 = ctx.r1.s64 + 655;
	// rlwinm. r10,r27,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x200;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// subf r6,r9,r11
	ctx.r6.s64 = ctx.r11.s64 - ctx.r9.s64;
	// addi r28,r9,1
	ctx.r28.s64 = ctx.r9.s64 + 1;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// beq 0x8207ed44
	if (ctx.cr0.eq) goto loc_8207ED44;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq cr6,0x8207ed34
	if (ctx.cr6.eq) goto loc_8207ED34;
	// lbz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,48
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 48, ctx.xer);
	// beq cr6,0x8207ed44
	if (ctx.cr6.eq) goto loc_8207ED44;
loc_8207ED34:
	// li r11,48
	ctx.r11.s64 = 48;
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// stbu r11,-1(r28)
	ea = -1 + ctx.r28.u32;
	PPC_STORE_U8(ea, ctx.r11.u8);
	ctx.r28.u32 = ea;
loc_8207ED40:
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
loc_8207ED44:
	// lwz r11,100(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8207ef00
	if (!ctx.cr6.eq) goto loc_8207EF00;
	// rlwinm. r11,r27,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8207ed94
	if (ctx.cr0.eq) goto loc_8207ED94;
	// rlwinm. r11,r27,0,23,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x100;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8207ed68
	if (ctx.cr0.eq) goto loc_8207ED68;
	// li r11,45
	ctx.r11.s64 = 45;
	// b 0x8207ed74
	goto loc_8207ED74;
loc_8207ED68:
	// clrlwi. r11,r27,31
	ctx.r11.u64 = ctx.r27.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8207ed84
	if (ctx.cr0.eq) goto loc_8207ED84;
	// li r11,43
	ctx.r11.s64 = 43;
loc_8207ED74:
	// li r30,1
	ctx.r30.s64 = 1;
	// stb r11,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, ctx.r11.u8);
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// b 0x8207ed98
	goto loc_8207ED98;
loc_8207ED84:
	// rlwinm. r11,r27,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8207ed94
	if (ctx.cr0.eq) goto loc_8207ED94;
	// li r11,32
	ctx.r11.s64 = 32;
	// b 0x8207ed74
	goto loc_8207ED74;
loc_8207ED94:
	// lwz r30,92(r1)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
loc_8207ED98:
	// lwz r11,96(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// rlwinm. r10,r27,0,28,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0xC;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// subf r11,r6,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r6.s64;
	// subf r29,r30,r11
	ctx.r29.s64 = ctx.r11.s64 - ctx.r30.s64;
	// bne 0x8207ede0
	if (!ctx.cr0.eq) goto loc_8207EDE0;
	// mr r31,r29
	ctx.r31.u64 = ctx.r29.u64;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// ble cr6,0x8207ede0
	if (!ctx.cr6.gt) goto loc_8207EDE0;
loc_8207EDB8:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// li r3,32
	ctx.r3.s64 = 32;
	// addi r31,r31,-1
	ctx.r31.s64 = ctx.r31.s64 + -1;
	// bl 0x8207ef78
	ctx.lr = 0x8207EDCC;
	sub_8207EF78(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8207ede0
	if (ctx.cr6.eq) goto loc_8207EDE0;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bgt cr6,0x8207edb8
	if (ctx.cr6.gt) goto loc_8207EDB8;
loc_8207EDE0:
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r18
	ctx.r5.u64 = ctx.r18.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8207e390
	ctx.lr = 0x8207EDF4;
	sub_8207E390(ctx, base);
	// rlwinm. r11,r27,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8207ee38
	if (ctx.cr0.eq) goto loc_8207EE38;
	// rlwinm. r11,r27,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8207ee38
	if (!ctx.cr0.eq) goto loc_8207EE38;
	// mr r31,r29
	ctx.r31.u64 = ctx.r29.u64;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// ble cr6,0x8207ee38
	if (!ctx.cr6.gt) goto loc_8207EE38;
loc_8207EE10:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// li r3,48
	ctx.r3.s64 = 48;
	// addi r31,r31,-1
	ctx.r31.s64 = ctx.r31.s64 + -1;
	// bl 0x8207ef78
	ctx.lr = 0x8207EE24;
	sub_8207EF78(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8207ee38
	if (ctx.cr6.eq) goto loc_8207EE38;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bgt cr6,0x8207ee10
	if (ctx.cr6.gt) goto loc_8207EE10;
loc_8207EE38:
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r16,0
	ctx.cr6.compare<int32_t>(ctx.r16.s32, 0, ctx.xer);
	// beq cr6,0x8207eea8
	if (ctx.cr6.eq) goto loc_8207EEA8;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// ble cr6,0x8207eea8
	if (!ctx.cr6.gt) goto loc_8207EEA8;
	// addi r30,r28,-2
	ctx.r30.s64 = ctx.r28.s64 + -2;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
loc_8207EE54:
	// li r5,6
	ctx.r5.s64 = 6;
	// lhzu r6,2(r30)
	ea = 2 + ctx.r30.u32;
	ctx.r6.u64 = PPC_LOAD_U16(ea);
	ctx.r30.u32 = ea;
	// addi r4,r1,116
	ctx.r4.s64 = ctx.r1.s64 + 116;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r31,r31,-1
	ctx.r31.s64 = ctx.r31.s64 + -1;
	// bl 0x82082ca0
	ctx.lr = 0x8207EE6C;
	sub_82082CA0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8207ee9c
	if (!ctx.cr0.eq) goto loc_8207EE9C;
	// lwz r4,112(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x8207ee9c
	if (ctx.cr6.eq) goto loc_8207EE9C;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r18
	ctx.r5.u64 = ctx.r18.u64;
	// addi r3,r1,116
	ctx.r3.s64 = ctx.r1.s64 + 116;
	// bl 0x8207e390
	ctx.lr = 0x8207EE90;
	sub_8207E390(ctx, base);
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne cr6,0x8207ee54
	if (!ctx.cr6.eq) goto loc_8207EE54;
	// b 0x8207eeb8
	goto loc_8207EEB8;
loc_8207EE9C:
	// li r24,-1
	ctx.r24.s64 = -1;
	// stw r24,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r24.u32);
	// b 0x8207eebc
	goto loc_8207EEBC;
loc_8207EEA8:
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r18
	ctx.r5.u64 = ctx.r18.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8207e390
	ctx.lr = 0x8207EEB8;
	sub_8207E390(ctx, base);
loc_8207EEB8:
	// lwz r24,80(r1)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_8207EEBC:
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// blt cr6,0x8207ef00
	if (ctx.cr6.lt) goto loc_8207EF00;
	// rlwinm. r11,r27,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8207ef00
	if (ctx.cr0.eq) goto loc_8207EF00;
	// mr r31,r29
	ctx.r31.u64 = ctx.r29.u64;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// ble cr6,0x8207ef00
	if (!ctx.cr6.gt) goto loc_8207EF00;
loc_8207EED8:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// li r3,32
	ctx.r3.s64 = 32;
	// addi r31,r31,-1
	ctx.r31.s64 = ctx.r31.s64 + -1;
	// bl 0x8207ef78
	ctx.lr = 0x8207EEEC;
	sub_8207EF78(ctx, base);
	// lwz r24,80(r1)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r24,-1
	ctx.cr6.compare<int32_t>(ctx.r24.s32, -1, ctx.xer);
	// beq cr6,0x8207ef00
	if (ctx.cr6.eq) goto loc_8207EF00;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bgt cr6,0x8207eed8
	if (ctx.cr6.gt) goto loc_8207EED8;
loc_8207EF00:
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x8207ef14
	if (ctx.cr6.eq) goto loc_8207EF14;
	// mr r3,r14
	ctx.r3.u64 = ctx.r14.u64;
	// bl 0x8207c068
	ctx.lr = 0x8207EF10;
	sub_8207C068(ctx, base);
	// li r14,0
	ctx.r14.s64 = 0;
loc_8207EF14:
	// lbz r29,1(r19)
	ctx.r29.u64 = PPC_LOAD_U8(ctx.r19.u32 + 1);
	// extsb. r8,r29
	ctx.r8.s64 = ctx.r29.s8;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x8207ef30
	if (ctx.cr0.eq) goto loc_8207EF30;
	// lwz r7,108(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// b 0x8207e5b0
	goto loc_8207E5B0;
loc_8207EF30:
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// b 0x8207ef6c
	goto loc_8207EF6C;
loc_8207EF38:
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// li r4,512
	ctx.r4.s64 = 512;
	// addi r3,r1,656
	ctx.r3.s64 = ctx.r1.s64 + 656;
	// bl 0x82082b70
	ctx.lr = 0x8207EF4C;
	sub_82082B70(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x8207ef60
	if (!ctx.cr6.eq) goto loc_8207EF60;
	// li r31,511
	ctx.r31.s64 = 511;
	// stb r30,1167(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1167, ctx.r30.u8);
loc_8207EF60:
	// addi r3,r1,656
	ctx.r3.s64 = ctx.r1.s64 + 656;
	// bl 0x8208d988
	ctx.lr = 0x8207EF68;
	sub_8208D988(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8207EF6C:
	// addi r1,r1,1328
	ctx.r1.s64 = ctx.r1.s64 + 1328;
	// b 0x8207c9a0
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8207EF74"))) PPC_WEAK_FUNC(sub_8207EF74);
PPC_FUNC_IMPL(__imp__sub_8207EF74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8207EF78"))) PPC_WEAK_FUNC(sub_8207EF78);
PPC_FUNC_IMPL(__imp__sub_8207EF78) {
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
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// rlwinm. r10,r10,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8207efa8
	if (ctx.cr0.eq) goto loc_8207EFA8;
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8207efec
	if (ctx.cr6.eq) goto loc_8207EFEC;
loc_8207EFA8:
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r10.u32);
	// blt 0x8207efd4
	if (ctx.cr0.lt) goto loc_8207EFD4;
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r11.u8);
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// b 0x8207efdc
	goto loc_8207EFDC;
loc_8207EFD4:
	// extsb r3,r11
	ctx.r3.s64 = ctx.r11.s8;
	// bl 0x8207e1b8
	ctx.lr = 0x8207EFDC;
	sub_8207E1B8(ctx, base);
loc_8207EFDC:
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x8207efec
	if (!ctx.cr6.eq) goto loc_8207EFEC;
	// li r11,-1
	ctx.r11.s64 = -1;
	// b 0x8207eff4
	goto loc_8207EFF4;
loc_8207EFEC:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_8207EFF4:
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_8207F00C"))) PPC_WEAK_FUNC(sub_8207F00C);
PPC_FUNC_IMPL(__imp__sub_8207F00C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8207F010"))) PPC_WEAK_FUNC(sub_8207F010);
PPC_FUNC_IMPL(__imp__sub_8207F010) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c950
	ctx.lr = 0x8207F018;
	__savegprlr_14(ctx, base);
	// stwu r1,-1328(r1)
	ea = -1328 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r18,r3
	ctx.r18.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// stw r30,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r30.u32);
	// mr r26,r6
	ctx.r26.u64 = ctx.r6.u64;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r30.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// mr r27,r30
	ctx.r27.u64 = ctx.r30.u64;
	// stw r30,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r30.u32);
	// mr r25,r30
	ctx.r25.u64 = ctx.r30.u64;
	// mr r16,r30
	ctx.r16.u64 = ctx.r30.u64;
	// bne cr6,0x8207f07c
	if (!ctx.cr6.eq) goto loc_8207F07C;
loc_8207F050:
	// bl 0x8207d4d8
	ctx.lr = 0x8207F054;
	sub_8207D4D8(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d940
	ctx.lr = 0x8207F074;
	sub_8207D940(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x8207fb64
	goto loc_8207FB64;
loc_8207F07C:
	// lwz r11,12(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	// rlwinm. r11,r11,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8207f118
	if (!ctx.cr0.eq) goto loc_8207F118;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// bl 0x820809e8
	ctx.lr = 0x8207F090;
	sub_820809E8(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// addi r11,r11,-23360
	ctx.r11.s64 = ctx.r11.s64 + -23360;
	// addi r8,r10,2456
	ctx.r8.s64 = ctx.r10.s64 + 2456;
	// beq cr6,0x8207f0cc
	if (ctx.cr6.eq) goto loc_8207F0CC;
	// cmpwi cr6,r3,-2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -2, ctx.xer);
	// beq cr6,0x8207f0cc
	if (ctx.cr6.eq) goto loc_8207F0CC;
	// srawi r10,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 5;
	// clrlwi r9,r3,27
	ctx.r9.u64 = ctx.r3.u32 & 0x1F;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mulli r10,r9,72
	ctx.r10.s64 = ctx.r9.s64 * 72;
	// lwzx r9,r7,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r11.u32);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// b 0x8207f0d0
	goto loc_8207F0D0;
loc_8207F0CC:
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
loc_8207F0D0:
	// lbz r10,40(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 40);
	// rlwinm. r10,r10,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8207f050
	if (!ctx.cr0.eq) goto loc_8207F050;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8207f108
	if (ctx.cr6.eq) goto loc_8207F108;
	// cmpwi cr6,r3,-2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -2, ctx.xer);
	// beq cr6,0x8207f108
	if (ctx.cr6.eq) goto loc_8207F108;
	// srawi r10,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 5;
	// clrlwi r9,r3,27
	ctx.r9.u64 = ctx.r3.u32 & 0x1F;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mulli r10,r9,72
	ctx.r10.s64 = ctx.r9.s64 * 72;
	// lwzx r11,r8,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x8207f10c
	goto loc_8207F10C;
loc_8207F108:
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
loc_8207F10C:
	// lbz r11,40(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 40);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8207f050
	if (!ctx.cr0.eq) goto loc_8207F050;
loc_8207F118:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8207f050
	if (ctx.cr6.eq) goto loc_8207F050;
	// bl 0x8207c2b8
	ctx.lr = 0x8207F124;
	sub_8207C2B8(ctx, base);
	// addi r11,r3,32
	ctx.r11.s64 = ctx.r3.s64 + 32;
	// cmplw cr6,r18,r11
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8207fb30
	if (ctx.cr6.eq) goto loc_8207FB30;
	// bl 0x8207c2b8
	ctx.lr = 0x8207F134;
	sub_8207C2B8(ctx, base);
	// addi r11,r3,64
	ctx.r11.s64 = ctx.r3.s64 + 64;
	// cmplw cr6,r18,r11
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8207fb30
	if (ctx.cr6.eq) goto loc_8207FB30;
	// lbz r29,0(r31)
	ctx.r29.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// mr r24,r30
	ctx.r24.u64 = ctx.r30.u64;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// extsb. r8,r29
	ctx.r8.s64 = ctx.r29.s8;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// mr r14,r30
	ctx.r14.u64 = ctx.r30.u64;
	// beq 0x8207fb28
	if (ctx.cr0.eq) goto loc_8207FB28;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lwz r21,112(r1)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lwz r28,112(r1)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r19,r31,-1
	ctx.r19.s64 = ctx.r31.s64 + -1;
	// lis r15,-32256
	ctx.r15.s64 = -2113929216;
	// lis r20,-32256
	ctx.r20.s64 = -2113929216;
	// addi r23,r11,2792
	ctx.r23.s64 = ctx.r11.s64 + 2792;
	// addi r22,r10,2800
	ctx.r22.s64 = ctx.r10.s64 + 2800;
	// addi r17,r9,4168
	ctx.r17.s64 = ctx.r9.s64 + 4168;
loc_8207F190:
	// addi r19,r19,1
	ctx.r19.s64 = ctx.r19.s64 + 1;
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// blt cr6,0x8207fb14
	if (ctx.cr6.lt) goto loc_8207FB14;
	// cmpwi cr6,r8,32
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 32, ctx.xer);
	// blt cr6,0x8207f1bc
	if (ctx.cr6.lt) goto loc_8207F1BC;
	// cmpwi cr6,r8,120
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 120, ctx.xer);
	// bgt cr6,0x8207f1bc
	if (ctx.cr6.gt) goto loc_8207F1BC;
	// add r11,r8,r17
	ctx.r11.u64 = ctx.r8.u64 + ctx.r17.u64;
	// lbz r11,-32(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + -32);
	// clrlwi r11,r11,28
	ctx.r11.u64 = ctx.r11.u32 & 0xF;
	// b 0x8207f1c0
	goto loc_8207F1C0;
loc_8207F1BC:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8207F1C0:
	// lwz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// mulli r11,r11,9
	ctx.r11.s64 = ctx.r11.s64 * 9;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lbzx r11,r11,r17
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r17.u32);
	// rlwinm r11,r11,28,4,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0xFFFFFFF;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// beq cr6,0x8207f050
	if (ctx.cr6.eq) goto loc_8207F050;
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// bgt cr6,0x8207fafc
	if (ctx.cr6.gt) goto loc_8207FAFC;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8207f3e0
	if (ctx.cr6.eq) goto loc_8207F3E0;
	// bdz 0x8207f214
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_8207F214;
	// bdz 0x8207f234
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_8207F234;
	// bdz 0x8207f284
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_8207F284;
	// bdz 0x8207f2d0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_8207F2D0;
	// bdz 0x8207f2d8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_8207F2D8;
	// bdz 0x8207f310
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_8207F310;
	// b 0x8207f42c
	goto loc_8207F42C;
loc_8207F214:
	// li r27,0
	ctx.r27.s64 = 0;
	// li r25,-1
	ctx.r25.s64 = -1;
	// mr r21,r27
	ctx.r21.u64 = ctx.r27.u64;
	// stw r27,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r27.u32);
	// stw r27,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r27.u32);
	// mr r16,r27
	ctx.r16.u64 = ctx.r27.u64;
	// stw r27,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r27.u32);
	// b 0x8207fafc
	goto loc_8207FAFC;
loc_8207F234:
	// cmpwi cr6,r8,32
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 32, ctx.xer);
	// beq cr6,0x8207f27c
	if (ctx.cr6.eq) goto loc_8207F27C;
	// cmpwi cr6,r8,35
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 35, ctx.xer);
	// beq cr6,0x8207f274
	if (ctx.cr6.eq) goto loc_8207F274;
	// cmpwi cr6,r8,43
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 43, ctx.xer);
	// beq cr6,0x8207f26c
	if (ctx.cr6.eq) goto loc_8207F26C;
	// cmpwi cr6,r8,45
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 45, ctx.xer);
	// beq cr6,0x8207f264
	if (ctx.cr6.eq) goto loc_8207F264;
	// cmpwi cr6,r8,48
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 48, ctx.xer);
	// bne cr6,0x8207fafc
	if (!ctx.cr6.eq) goto loc_8207FAFC;
	// ori r27,r27,8
	ctx.r27.u64 = ctx.r27.u64 | 8;
	// b 0x8207fafc
	goto loc_8207FAFC;
loc_8207F264:
	// ori r27,r27,4
	ctx.r27.u64 = ctx.r27.u64 | 4;
	// b 0x8207fafc
	goto loc_8207FAFC;
loc_8207F26C:
	// ori r27,r27,1
	ctx.r27.u64 = ctx.r27.u64 | 1;
	// b 0x8207fafc
	goto loc_8207FAFC;
loc_8207F274:
	// ori r27,r27,128
	ctx.r27.u64 = ctx.r27.u64 | 128;
	// b 0x8207fafc
	goto loc_8207FAFC;
loc_8207F27C:
	// ori r27,r27,2
	ctx.r27.u64 = ctx.r27.u64 | 2;
	// b 0x8207fafc
	goto loc_8207FAFC;
loc_8207F284:
	// cmpwi cr6,r8,42
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 42, ctx.xer);
	// bne cr6,0x8207f2b8
	if (!ctx.cr6.eq) goto loc_8207F2B8;
	// addi r11,r26,7
	ctx.r11.s64 = ctx.r26.s64 + 7;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r26,r11,8
	ctx.r26.s64 = ctx.r11.s64 + 8;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// bge cr6,0x8207fafc
	if (!ctx.cr6.lt) goto loc_8207FAFC;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// ori r27,r27,4
	ctx.r27.u64 = ctx.r27.u64 | 4;
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
	// b 0x8207f2c8
	goto loc_8207F2C8;
loc_8207F2B8:
	// lwz r11,96(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// mulli r11,r11,10
	ctx.r11.s64 = ctx.r11.s64 * 10;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// addi r11,r11,-48
	ctx.r11.s64 = ctx.r11.s64 + -48;
loc_8207F2C8:
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// b 0x8207fafc
	goto loc_8207FAFC;
loc_8207F2D0:
	// li r25,0
	ctx.r25.s64 = 0;
	// b 0x8207fafc
	goto loc_8207FAFC;
loc_8207F2D8:
	// cmpwi cr6,r8,42
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 42, ctx.xer);
	// bne cr6,0x8207f300
	if (!ctx.cr6.eq) goto loc_8207F300;
	// addi r11,r26,7
	ctx.r11.s64 = ctx.r26.s64 + 7;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r26,r11,8
	ctx.r26.s64 = ctx.r11.s64 + 8;
	// lwz r25,4(r11)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// bge cr6,0x8207fafc
	if (!ctx.cr6.lt) goto loc_8207FAFC;
	// li r25,-1
	ctx.r25.s64 = -1;
	// b 0x8207fafc
	goto loc_8207FAFC;
loc_8207F300:
	// mulli r11,r25,10
	ctx.r11.s64 = ctx.r25.s64 * 10;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// addi r25,r11,-48
	ctx.r25.s64 = ctx.r11.s64 + -48;
	// b 0x8207fafc
	goto loc_8207FAFC;
loc_8207F310:
	// cmpwi cr6,r8,73
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 73, ctx.xer);
	// beq cr6,0x8207f360
	if (ctx.cr6.eq) goto loc_8207F360;
	// cmpwi cr6,r8,104
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 104, ctx.xer);
	// beq cr6,0x8207f358
	if (ctx.cr6.eq) goto loc_8207F358;
	// cmpwi cr6,r8,108
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 108, ctx.xer);
	// beq cr6,0x8207f338
	if (ctx.cr6.eq) goto loc_8207F338;
	// cmpwi cr6,r8,119
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 119, ctx.xer);
	// bne cr6,0x8207fafc
	if (!ctx.cr6.eq) goto loc_8207FAFC;
	// ori r27,r27,2048
	ctx.r27.u64 = ctx.r27.u64 | 2048;
	// b 0x8207fafc
	goto loc_8207FAFC;
loc_8207F338:
	// lbz r11,1(r19)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r19.u32 + 1);
	// cmplwi cr6,r11,108
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 108, ctx.xer);
	// bne cr6,0x8207f350
	if (!ctx.cr6.eq) goto loc_8207F350;
	// addi r19,r19,1
	ctx.r19.s64 = ctx.r19.s64 + 1;
	// ori r27,r27,4096
	ctx.r27.u64 = ctx.r27.u64 | 4096;
	// b 0x8207fafc
	goto loc_8207FAFC;
loc_8207F350:
	// ori r27,r27,16
	ctx.r27.u64 = ctx.r27.u64 | 16;
	// b 0x8207fafc
	goto loc_8207FAFC;
loc_8207F358:
	// ori r27,r27,32
	ctx.r27.u64 = ctx.r27.u64 | 32;
	// b 0x8207fafc
	goto loc_8207FAFC;
loc_8207F360:
	// lbz r11,1(r19)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r19.u32 + 1);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// cmpwi cr6,r11,54
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 54, ctx.xer);
	// bne cr6,0x8207f388
	if (!ctx.cr6.eq) goto loc_8207F388;
	// lbz r10,2(r19)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r19.u32 + 2);
	// cmplwi cr6,r10,52
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 52, ctx.xer);
	// bne cr6,0x8207f388
	if (!ctx.cr6.eq) goto loc_8207F388;
	// addi r19,r19,2
	ctx.r19.s64 = ctx.r19.s64 + 2;
	// ori r27,r27,32768
	ctx.r27.u64 = ctx.r27.u64 | 32768;
	// b 0x8207fafc
	goto loc_8207FAFC;
loc_8207F388:
	// cmpwi cr6,r11,51
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 51, ctx.xer);
	// bne cr6,0x8207f3a8
	if (!ctx.cr6.eq) goto loc_8207F3A8;
	// lbz r10,2(r19)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r19.u32 + 2);
	// cmplwi cr6,r10,50
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 50, ctx.xer);
	// bne cr6,0x8207f3a8
	if (!ctx.cr6.eq) goto loc_8207F3A8;
	// addi r19,r19,2
	ctx.r19.s64 = ctx.r19.s64 + 2;
	// rlwinm r27,r27,0,17,15
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0xFFFFFFFFFFFF7FFF;
	// b 0x8207fafc
	goto loc_8207FAFC;
loc_8207F3A8:
	// cmpwi cr6,r11,100
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 100, ctx.xer);
	// beq cr6,0x8207fafc
	if (ctx.cr6.eq) goto loc_8207FAFC;
	// cmpwi cr6,r11,105
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 105, ctx.xer);
	// beq cr6,0x8207fafc
	if (ctx.cr6.eq) goto loc_8207FAFC;
	// cmpwi cr6,r11,111
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 111, ctx.xer);
	// beq cr6,0x8207fafc
	if (ctx.cr6.eq) goto loc_8207FAFC;
	// cmpwi cr6,r11,117
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 117, ctx.xer);
	// beq cr6,0x8207fafc
	if (ctx.cr6.eq) goto loc_8207FAFC;
	// cmpwi cr6,r11,120
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 120, ctx.xer);
	// beq cr6,0x8207fafc
	if (ctx.cr6.eq) goto loc_8207FAFC;
	// cmpwi cr6,r11,88
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 88, ctx.xer);
	// beq cr6,0x8207fafc
	if (ctx.cr6.eq) goto loc_8207FAFC;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
loc_8207F3E0:
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// clrlwi r3,r29,24
	ctx.r3.u64 = ctx.r29.u32 & 0xFF;
	// li r16,0
	ctx.r16.s64 = 0;
	// bl 0x82082ca8
	ctx.lr = 0x8207F3F0;
	sub_82082CA8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8207f414
	if (ctx.cr0.eq) goto loc_8207F414;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8207ef78
	ctx.lr = 0x8207F408;
	sub_8207EF78(ctx, base);
	// lbzu r29,1(r19)
	ea = 1 + ctx.r19.u32;
	ctx.r29.u64 = PPC_LOAD_U8(ea);
	ctx.r19.u32 = ea;
	// cmplwi r29,0
	ctx.cr0.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq 0x8207f050
	if (ctx.cr0.eq) goto loc_8207F050;
loc_8207F414:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8207ef78
	ctx.lr = 0x8207F424;
	sub_8207EF78(ctx, base);
	// lwz r24,80(r1)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// b 0x8207fafc
	goto loc_8207FAFC;
loc_8207F42C:
	// addi r11,r8,-65
	ctx.r11.s64 = ctx.r8.s64 + -65;
	// cmplwi cr6,r11,55
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 55, ctx.xer);
	// bgt cr6,0x8207f92c
	if (ctx.cr6.gt) goto loc_8207F92C;
	// lis r12,-32256
	ctx.r12.s64 = -2113929216;
	// rlwinm r0,r11,1,0,30
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r12,r12,4264
	ctx.r12.s64 = ctx.r12.s64 + 4264;
	// lhzx r0,r12,r0
	ctx.r0.u64 = PPC_LOAD_U16(ctx.r12.u32 + ctx.r0.u32);
	// lis r12,-32248
	ctx.r12.s64 = -2113404928;
	// addi r12,r12,-2976
	ctx.r12.s64 = ctx.r12.s64 + -2976;
	// nop 
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// bctr 
	switch (ctx.r11.u64) {
	case 0:
		goto loc_8207F63C;
	case 1:
		goto loc_8207F92C;
	case 2:
		goto loc_8207F460;
	case 3:
		goto loc_8207F92C;
	case 4:
		goto loc_8207F63C;
	case 5:
		goto loc_8207F92C;
	case 6:
		goto loc_8207F63C;
	case 7:
		goto loc_8207F92C;
	case 8:
		goto loc_8207F92C;
	case 9:
		goto loc_8207F92C;
	case 10:
		goto loc_8207F92C;
	case 11:
		goto loc_8207F92C;
	case 12:
		goto loc_8207F92C;
	case 13:
		goto loc_8207F92C;
	case 14:
		goto loc_8207F92C;
	case 15:
		goto loc_8207F92C;
	case 16:
		goto loc_8207F92C;
	case 17:
		goto loc_8207F92C;
	case 18:
		goto loc_8207F548;
	case 19:
		goto loc_8207F92C;
	case 20:
		goto loc_8207F92C;
	case 21:
		goto loc_8207F92C;
	case 22:
		goto loc_8207F92C;
	case 23:
		goto loc_8207F77C;
	case 24:
		goto loc_8207F92C;
	case 25:
		goto loc_8207F4CC;
	case 26:
		goto loc_8207F92C;
	case 27:
		goto loc_8207F92C;
	case 28:
		goto loc_8207F92C;
	case 29:
		goto loc_8207F92C;
	case 30:
		goto loc_8207F92C;
	case 31:
		goto loc_8207F92C;
	case 32:
		goto loc_8207F648;
	case 33:
		goto loc_8207F92C;
	case 34:
		goto loc_8207F470;
	case 35:
		goto loc_8207F76C;
	case 36:
		goto loc_8207F648;
	case 37:
		goto loc_8207F648;
	case 38:
		goto loc_8207F648;
	case 39:
		goto loc_8207F92C;
	case 40:
		goto loc_8207F76C;
	case 41:
		goto loc_8207F92C;
	case 42:
		goto loc_8207F92C;
	case 43:
		goto loc_8207F92C;
	case 44:
		goto loc_8207F92C;
	case 45:
		goto loc_8207F600;
	case 46:
		goto loc_8207F7B4;
	case 47:
		goto loc_8207F778;
	case 48:
		goto loc_8207F92C;
	case 49:
		goto loc_8207F92C;
	case 50:
		goto loc_8207F558;
	case 51:
		goto loc_8207F92C;
	case 52:
		goto loc_8207F770;
	case 53:
		goto loc_8207F92C;
	case 54:
		goto loc_8207F92C;
	case 55:
		goto loc_8207F784;
	default:
		__builtin_unreachable();
	}
loc_8207F460:
	// andi. r11,r27,2096
	ctx.r11.u64 = ctx.r27.u64 & 2096;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8207f470
	if (!ctx.cr0.eq) goto loc_8207F470;
	// ori r27,r27,2048
	ctx.r27.u64 = ctx.r27.u64 | 2048;
loc_8207F470:
	// andi. r11,r27,2064
	ctx.r11.u64 = ctx.r27.u64 & 2064;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r11,r26,7
	ctx.r11.s64 = ctx.r26.s64 + 7;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r26,r11,8
	ctx.r26.s64 = ctx.r11.s64 + 8;
	// beq 0x8207f4b0
	if (ctx.cr0.eq) goto loc_8207F4B0;
	// li r5,512
	ctx.r5.s64 = 512;
	// lhz r6,6(r11)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r11.u32 + 6);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x82082ca0
	ctx.lr = 0x8207F49C;
	sub_82082CA0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8207f4c0
	if (ctx.cr0.eq) goto loc_8207F4C0;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
	// b 0x8207f4c0
	goto loc_8207F4C0;
loc_8207F4B0:
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stb r11,144(r1)
	PPC_STORE_U8(ctx.r1.u32 + 144, ctx.r11.u8);
loc_8207F4C0:
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r28,r1,144
	ctx.r28.s64 = ctx.r1.s64 + 144;
	// b 0x8207f92c
	goto loc_8207F92C;
loc_8207F4CC:
	// addi r11,r26,7
	ctx.r11.s64 = ctx.r26.s64 + 7;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r26,r11,8
	ctx.r26.s64 = ctx.r11.s64 + 8;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8207f51c
	if (ctx.cr6.eq) goto loc_8207F51C;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8207f51c
	if (ctx.cr6.eq) goto loc_8207F51C;
	// rlwinm. r9,r27,0,20,20
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x800;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// mr r28,r10
	ctx.r28.u64 = ctx.r10.u64;
	// beq 0x8207f510
	if (ctx.cr0.eq) goto loc_8207F510;
	// lha r11,0(r11)
	ctx.r11.s64 = int16_t(PPC_LOAD_U16(ctx.r11.u32 + 0));
	// li r16,1
	ctx.r16.s64 = 1;
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// addze r7,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r7.s64 = temp.s64;
	// b 0x8207f928
	goto loc_8207F928;
loc_8207F510:
	// lha r7,0(r11)
	ctx.r7.s64 = int16_t(PPC_LOAD_U16(ctx.r11.u32 + 0));
	// li r16,0
	ctx.r16.s64 = 0;
	// b 0x8207f928
	goto loc_8207F928;
loc_8207F51C:
	// lwz r28,3948(r20)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r20.u32 + 3948);
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
loc_8207F528:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8207f528
	if (!ctx.cr6.eq) goto loc_8207F528;
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
loc_8207F53C:
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rotlwi r7,r11,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// b 0x8207f928
	goto loc_8207F928;
loc_8207F548:
	// andi. r11,r27,2096
	ctx.r11.u64 = ctx.r27.u64 & 2096;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8207f558
	if (!ctx.cr0.eq) goto loc_8207F558;
	// ori r27,r27,2048
	ctx.r27.u64 = ctx.r27.u64 | 2048;
loc_8207F558:
	// cmpwi cr6,r25,-1
	ctx.cr6.compare<int32_t>(ctx.r25.s32, -1, ctx.xer);
	// bne cr6,0x8207f56c
	if (!ctx.cr6.eq) goto loc_8207F56C;
	// lis r10,32767
	ctx.r10.s64 = 2147418112;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
	// b 0x8207f570
	goto loc_8207F570;
loc_8207F56C:
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
loc_8207F570:
	// addi r11,r26,7
	ctx.r11.s64 = ctx.r26.s64 + 7;
	// andi. r9,r27,2064
	ctx.r9.u64 = ctx.r27.u64 & 2064;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// addi r26,r11,8
	ctx.r26.s64 = ctx.r11.s64 + 8;
	// lwz r28,4(r11)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq 0x8207f5cc
	if (ctx.cr0.eq) goto loc_8207F5CC;
	// bne cr6,0x8207f598
	if (!ctx.cr6.eq) goto loc_8207F598;
	// lwz r28,3952(r15)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r15.u32 + 3952);
loc_8207F598:
	// li r16,1
	ctx.r16.s64 = 1;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// b 0x8207f5b8
	goto loc_8207F5B8;
loc_8207F5A4:
	// lhz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq 0x8207f5c0
	if (ctx.cr0.eq) goto loc_8207F5C0;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
loc_8207F5B8:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8207f5a4
	if (!ctx.cr6.eq) goto loc_8207F5A4;
loc_8207F5C0:
	// subf r11,r28,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r28.s64;
	// srawi r7,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r7.s64 = ctx.r11.s32 >> 1;
	// b 0x8207f928
	goto loc_8207F928;
loc_8207F5CC:
	// bne cr6,0x8207f5d4
	if (!ctx.cr6.eq) goto loc_8207F5D4;
	// lwz r28,3948(r20)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r20.u32 + 3948);
loc_8207F5D4:
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// b 0x8207f5f0
	goto loc_8207F5F0;
loc_8207F5DC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq 0x8207f5f8
	if (ctx.cr0.eq) goto loc_8207F5F8;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_8207F5F0:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8207f5dc
	if (!ctx.cr6.eq) goto loc_8207F5DC;
loc_8207F5F8:
	// subf r7,r28,r11
	ctx.r7.s64 = ctx.r11.s64 - ctx.r28.s64;
	// b 0x8207f928
	goto loc_8207F928;
loc_8207F600:
	// addi r11,r26,7
	ctx.r11.s64 = ctx.r26.s64 + 7;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r26,r11,8
	ctx.r26.s64 = ctx.r11.s64 + 8;
	// lwz r31,4(r11)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8207bda0
	ctx.lr = 0x8207F614;
	sub_8207BDA0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8207f050
	if (ctx.cr0.eq) goto loc_8207F050;
	// rlwinm. r11,r27,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8207f62c
	if (ctx.cr0.eq) goto loc_8207F62C;
	// sth r24,0(r31)
	PPC_STORE_U16(ctx.r31.u32 + 0, ctx.r24.u16);
	// b 0x8207f630
	goto loc_8207F630;
loc_8207F62C:
	// stw r24,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r24.u32);
loc_8207F630:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
	// b 0x8207fae8
	goto loc_8207FAE8;
loc_8207F63C:
	// addi r11,r8,32
	ctx.r11.s64 = ctx.r8.s64 + 32;
	// li r21,1
	ctx.r21.s64 = 1;
	// extsb r29,r11
	ctx.r29.s64 = ctx.r11.s8;
loc_8207F648:
	// ori r27,r27,64
	ctx.r27.u64 = ctx.r27.u64 | 64;
	// addi r28,r1,144
	ctx.r28.s64 = ctx.r1.s64 + 144;
	// li r30,512
	ctx.r30.s64 = 512;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// bge cr6,0x8207f664
	if (!ctx.cr6.lt) goto loc_8207F664;
	// li r25,6
	ctx.r25.s64 = 6;
	// b 0x8207f6b4
	goto loc_8207F6B4;
loc_8207F664:
	// bne cr6,0x8207f67c
	if (!ctx.cr6.eq) goto loc_8207F67C;
	// extsb r11,r29
	ctx.r11.s64 = ctx.r29.s8;
	// cmpwi cr6,r11,103
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 103, ctx.xer);
	// bne cr6,0x8207f6b4
	if (!ctx.cr6.eq) goto loc_8207F6B4;
	// li r25,1
	ctx.r25.s64 = 1;
	// b 0x8207f6b4
	goto loc_8207F6B4;
loc_8207F67C:
	// cmpwi cr6,r25,512
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 512, ctx.xer);
	// ble cr6,0x8207f688
	if (!ctx.cr6.gt) goto loc_8207F688;
	// li r25,512
	ctx.r25.s64 = 512;
loc_8207F688:
	// cmpwi cr6,r25,163
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 163, ctx.xer);
	// ble cr6,0x8207f6b4
	if (!ctx.cr6.gt) goto loc_8207F6B4;
	// addi r31,r25,349
	ctx.r31.s64 = ctx.r25.s64 + 349;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207a400
	ctx.lr = 0x8207F69C;
	sub_8207A400(ctx, base);
	// mr. r14,r3
	ctx.r14.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r14.s32, 0, ctx.xer);
	// beq 0x8207f6b0
	if (ctx.cr0.eq) goto loc_8207F6B0;
	// mr r28,r14
	ctx.r28.u64 = ctx.r14.u64;
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
	// b 0x8207f6b4
	goto loc_8207F6B4;
loc_8207F6B0:
	// li r25,163
	ctx.r25.s64 = 163;
loc_8207F6B4:
	// addi r11,r26,7
	ctx.r11.s64 = ctx.r26.s64 + 7;
	// lwz r10,24(r22)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r22.u32 + 24);
	// extsb r31,r29
	ctx.r31.s64 = ctx.r29.s8;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// mr r9,r23
	ctx.r9.u64 = ctx.r23.u64;
	// mr r8,r21
	ctx.r8.u64 = ctx.r21.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// mr r7,r25
	ctx.r7.u64 = ctx.r25.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// ld r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r11.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r26,r11,8
	ctx.r26.s64 = ctx.r11.s64 + 8;
	// std r10,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r10.u64);
	// bctrl 
	ctx.lr = 0x8207F6F4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// rlwinm. r30,r27,0,24,24
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x8207f718
	if (ctx.cr0.eq) goto loc_8207F718;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// bne cr6,0x8207f718
	if (!ctx.cr6.eq) goto loc_8207F718;
	// lwz r11,36(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 36);
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8207F718;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8207F718:
	// cmpwi cr6,r31,103
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 103, ctx.xer);
	// bne cr6,0x8207f73c
	if (!ctx.cr6.eq) goto loc_8207F73C;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x8207f73c
	if (!ctx.cr6.eq) goto loc_8207F73C;
	// lwz r11,32(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 32);
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8207F73C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8207F73C:
	// lbz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,45
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 45, ctx.xer);
	// bne cr6,0x8207f750
	if (!ctx.cr6.eq) goto loc_8207F750;
	// ori r27,r27,256
	ctx.r27.u64 = ctx.r27.u64 | 256;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
loc_8207F750:
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
loc_8207F754:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8207f754
	if (!ctx.cr6.eq) goto loc_8207F754;
	// subf r11,r28,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r28.s64;
	// b 0x8207f53c
	goto loc_8207F53C;
loc_8207F76C:
	// ori r27,r27,64
	ctx.r27.u64 = ctx.r27.u64 | 64;
loc_8207F770:
	// li r8,10
	ctx.r8.s64 = 10;
	// b 0x8207f7c4
	goto loc_8207F7C4;
loc_8207F778:
	// li r25,8
	ctx.r25.s64 = 8;
loc_8207F77C:
	// li r11,7
	ctx.r11.s64 = 7;
	// b 0x8207f788
	goto loc_8207F788;
loc_8207F784:
	// li r11,39
	ctx.r11.s64 = 39;
loc_8207F788:
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r11.u32);
	// rlwinm. r10,r27,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// li r8,16
	ctx.r8.s64 = 16;
	// beq 0x8207f7c4
	if (ctx.cr0.eq) goto loc_8207F7C4;
	// addi r11,r11,81
	ctx.r11.s64 = ctx.r11.s64 + 81;
	// li r10,48
	ctx.r10.s64 = 48;
	// li r9,2
	ctx.r9.s64 = 2;
	// stb r11,89(r1)
	PPC_STORE_U8(ctx.r1.u32 + 89, ctx.r11.u8);
	// stb r10,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, ctx.r10.u8);
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// b 0x8207f7c4
	goto loc_8207F7C4;
loc_8207F7B4:
	// rlwinm. r11,r27,0,24,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r8,8
	ctx.r8.s64 = 8;
	// beq 0x8207f7c4
	if (ctx.cr0.eq) goto loc_8207F7C4;
	// ori r27,r27,512
	ctx.r27.u64 = ctx.r27.u64 | 512;
loc_8207F7C4:
	// rlwinm. r11,r27,0,16,16
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x8000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8207f7d4
	if (!ctx.cr0.eq) goto loc_8207F7D4;
	// rlwinm. r11,r27,0,19,19
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x1000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8207f7e8
	if (ctx.cr0.eq) goto loc_8207F7E8;
loc_8207F7D4:
	// addi r11,r26,7
	ctx.r11.s64 = ctx.r26.s64 + 7;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r26,r11,8
	ctx.r26.s64 = ctx.r11.s64 + 8;
	// ld r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r11.u32 + 0);
	// b 0x8207f838
	goto loc_8207F838;
loc_8207F7E8:
	// rlwinm. r11,r27,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8207f818
	if (ctx.cr0.eq) goto loc_8207F818;
	// rlwinm. r11,r27,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r11,r26,7
	ctx.r11.s64 = ctx.r26.s64 + 7;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r26,r11,8
	ctx.r26.s64 = ctx.r11.s64 + 8;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// beq 0x8207f810
	if (ctx.cr0.eq) goto loc_8207F810;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// b 0x8207f838
	goto loc_8207F838;
loc_8207F810:
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// b 0x8207f838
	goto loc_8207F838;
loc_8207F818:
	// rlwinm. r11,r27,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r11,r26,7
	ctx.r11.s64 = ctx.r26.s64 + 7;
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r26,r11,8
	ctx.r26.s64 = ctx.r11.s64 + 8;
	// beq 0x8207f834
	if (ctx.cr0.eq) goto loc_8207F834;
	// lwa r11,4(r11)
	ctx.r11.s64 = int32_t(PPC_LOAD_U32(ctx.r11.u32 + 4));
	// b 0x8207f838
	goto loc_8207F838;
loc_8207F834:
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
loc_8207F838:
	// rlwinm. r10,r27,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8207f850
	if (ctx.cr0.eq) goto loc_8207F850;
	// cmpdi cr6,r11,0
	ctx.cr6.compare<int64_t>(ctx.r11.s64, 0, ctx.xer);
	// bge cr6,0x8207f850
	if (!ctx.cr6.lt) goto loc_8207F850;
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
	// ori r27,r27,256
	ctx.r27.u64 = ctx.r27.u64 | 256;
loc_8207F850:
	// rlwinm. r10,r27,0,16,16
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x8000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8207f864
	if (!ctx.cr0.eq) goto loc_8207F864;
	// rlwinm. r10,r27,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x1000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8207f864
	if (!ctx.cr0.eq) goto loc_8207F864;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
loc_8207F864:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// bge cr6,0x8207f874
	if (!ctx.cr6.lt) goto loc_8207F874;
	// li r25,1
	ctx.r25.s64 = 1;
	// b 0x8207f884
	goto loc_8207F884;
loc_8207F874:
	// rlwinm r27,r27,0,29,27
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
	// cmpwi cr6,r25,512
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 512, ctx.xer);
	// ble cr6,0x8207f884
	if (!ctx.cr6.gt) goto loc_8207F884;
	// li r25,512
	ctx.r25.s64 = 512;
loc_8207F884:
	// cmpldi cr6,r11,0
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, 0, ctx.xer);
	// bne cr6,0x8207f894
	if (!ctx.cr6.eq) goto loc_8207F894;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
loc_8207F894:
	// addi r9,r1,655
	ctx.r9.s64 = ctx.r1.s64 + 655;
loc_8207F898:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// addi r25,r25,-1
	ctx.r25.s64 = ctx.r25.s64 + -1;
	// bgt cr6,0x8207f8ac
	if (ctx.cr6.gt) goto loc_8207F8AC;
	// cmpldi cr6,r11,0
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, 0, ctx.xer);
	// beq cr6,0x8207f8f0
	if (ctx.cr6.eq) goto loc_8207F8F0;
loc_8207F8AC:
	// extsw r10,r8
	ctx.r10.s64 = ctx.r8.s32;
	// divdu r7,r11,r10
	ctx.r7.u64 = ppc_divdu(ctx.r11.u64, ctx.r10.u64);
	// tdllei r10,0
	// mulld r7,r7,r10
	ctx.r7.s64 = ctx.r7.s64 * ctx.r10.s64;
	// subf r7,r7,r11
	ctx.r7.s64 = ctx.r11.s64 - ctx.r7.s64;
	// divdu r11,r11,r10
	ctx.r11.u64 = ppc_divdu(ctx.r11.u64, ctx.r10.u64);
	// tdllei r10,0
	// rotlwi r10,r7,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// cmpwi cr6,r10,57
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 57, ctx.xer);
	// ble cr6,0x8207f8e0
	if (!ctx.cr6.gt) goto loc_8207F8E0;
	// lwz r7,108(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
loc_8207F8E0:
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// stb r10,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r10.u8);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// b 0x8207f898
	goto loc_8207F898;
loc_8207F8F0:
	// addi r11,r1,655
	ctx.r11.s64 = ctx.r1.s64 + 655;
	// rlwinm. r10,r27,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x200;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// subf r7,r9,r11
	ctx.r7.s64 = ctx.r11.s64 - ctx.r9.s64;
	// addi r28,r9,1
	ctx.r28.s64 = ctx.r9.s64 + 1;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// beq 0x8207f92c
	if (ctx.cr0.eq) goto loc_8207F92C;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x8207f91c
	if (ctx.cr6.eq) goto loc_8207F91C;
	// lbz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,48
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 48, ctx.xer);
	// beq cr6,0x8207f92c
	if (ctx.cr6.eq) goto loc_8207F92C;
loc_8207F91C:
	// li r11,48
	ctx.r11.s64 = 48;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// stbu r11,-1(r28)
	ea = -1 + ctx.r28.u32;
	PPC_STORE_U8(ea, ctx.r11.u8);
	ctx.r28.u32 = ea;
loc_8207F928:
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
loc_8207F92C:
	// lwz r11,104(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8207fae8
	if (!ctx.cr6.eq) goto loc_8207FAE8;
	// rlwinm. r11,r27,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8207f97c
	if (ctx.cr0.eq) goto loc_8207F97C;
	// rlwinm. r11,r27,0,23,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x100;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8207f950
	if (ctx.cr0.eq) goto loc_8207F950;
	// li r11,45
	ctx.r11.s64 = 45;
	// b 0x8207f95c
	goto loc_8207F95C;
loc_8207F950:
	// clrlwi. r11,r27,31
	ctx.r11.u64 = ctx.r27.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8207f96c
	if (ctx.cr0.eq) goto loc_8207F96C;
	// li r11,43
	ctx.r11.s64 = 43;
loc_8207F95C:
	// li r30,1
	ctx.r30.s64 = 1;
	// stb r11,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, ctx.r11.u8);
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// b 0x8207f980
	goto loc_8207F980;
loc_8207F96C:
	// rlwinm. r11,r27,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8207f97c
	if (ctx.cr0.eq) goto loc_8207F97C;
	// li r11,32
	ctx.r11.s64 = 32;
	// b 0x8207f95c
	goto loc_8207F95C;
loc_8207F97C:
	// lwz r30,92(r1)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
loc_8207F980:
	// lwz r11,96(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// rlwinm. r10,r27,0,28,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0xC;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// subf r11,r7,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r7.s64;
	// subf r29,r30,r11
	ctx.r29.s64 = ctx.r11.s64 - ctx.r30.s64;
	// bne 0x8207f9c8
	if (!ctx.cr0.eq) goto loc_8207F9C8;
	// mr r31,r29
	ctx.r31.u64 = ctx.r29.u64;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// ble cr6,0x8207f9c8
	if (!ctx.cr6.gt) goto loc_8207F9C8;
loc_8207F9A0:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// li r3,32
	ctx.r3.s64 = 32;
	// addi r31,r31,-1
	ctx.r31.s64 = ctx.r31.s64 + -1;
	// bl 0x8207ef78
	ctx.lr = 0x8207F9B4;
	sub_8207EF78(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8207f9c8
	if (ctx.cr6.eq) goto loc_8207F9C8;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bgt cr6,0x8207f9a0
	if (ctx.cr6.gt) goto loc_8207F9A0;
loc_8207F9C8:
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r18
	ctx.r5.u64 = ctx.r18.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8207e390
	ctx.lr = 0x8207F9DC;
	sub_8207E390(ctx, base);
	// rlwinm. r11,r27,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8207fa20
	if (ctx.cr0.eq) goto loc_8207FA20;
	// rlwinm. r11,r27,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8207fa20
	if (!ctx.cr0.eq) goto loc_8207FA20;
	// mr r31,r29
	ctx.r31.u64 = ctx.r29.u64;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// ble cr6,0x8207fa20
	if (!ctx.cr6.gt) goto loc_8207FA20;
loc_8207F9F8:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// li r3,48
	ctx.r3.s64 = 48;
	// addi r31,r31,-1
	ctx.r31.s64 = ctx.r31.s64 + -1;
	// bl 0x8207ef78
	ctx.lr = 0x8207FA0C;
	sub_8207EF78(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8207fa20
	if (ctx.cr6.eq) goto loc_8207FA20;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bgt cr6,0x8207f9f8
	if (ctx.cr6.gt) goto loc_8207F9F8;
loc_8207FA20:
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r16,0
	ctx.cr6.compare<int32_t>(ctx.r16.s32, 0, ctx.xer);
	// beq cr6,0x8207fa90
	if (ctx.cr6.eq) goto loc_8207FA90;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// ble cr6,0x8207fa90
	if (!ctx.cr6.gt) goto loc_8207FA90;
	// addi r30,r28,-2
	ctx.r30.s64 = ctx.r28.s64 + -2;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
loc_8207FA3C:
	// li r5,6
	ctx.r5.s64 = 6;
	// lhzu r6,2(r30)
	ea = 2 + ctx.r30.u32;
	ctx.r6.u64 = PPC_LOAD_U16(ea);
	ctx.r30.u32 = ea;
	// addi r4,r1,116
	ctx.r4.s64 = ctx.r1.s64 + 116;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r31,r31,-1
	ctx.r31.s64 = ctx.r31.s64 + -1;
	// bl 0x82082ca0
	ctx.lr = 0x8207FA54;
	sub_82082CA0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8207fa84
	if (!ctx.cr0.eq) goto loc_8207FA84;
	// lwz r4,112(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x8207fa84
	if (ctx.cr6.eq) goto loc_8207FA84;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r18
	ctx.r5.u64 = ctx.r18.u64;
	// addi r3,r1,116
	ctx.r3.s64 = ctx.r1.s64 + 116;
	// bl 0x8207e390
	ctx.lr = 0x8207FA78;
	sub_8207E390(ctx, base);
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne cr6,0x8207fa3c
	if (!ctx.cr6.eq) goto loc_8207FA3C;
	// b 0x8207faa0
	goto loc_8207FAA0;
loc_8207FA84:
	// li r24,-1
	ctx.r24.s64 = -1;
	// stw r24,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r24.u32);
	// b 0x8207faa4
	goto loc_8207FAA4;
loc_8207FA90:
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r18
	ctx.r5.u64 = ctx.r18.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8207e390
	ctx.lr = 0x8207FAA0;
	sub_8207E390(ctx, base);
loc_8207FAA0:
	// lwz r24,80(r1)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_8207FAA4:
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// blt cr6,0x8207fae8
	if (ctx.cr6.lt) goto loc_8207FAE8;
	// rlwinm. r11,r27,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8207fae8
	if (ctx.cr0.eq) goto loc_8207FAE8;
	// mr r31,r29
	ctx.r31.u64 = ctx.r29.u64;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// ble cr6,0x8207fae8
	if (!ctx.cr6.gt) goto loc_8207FAE8;
loc_8207FAC0:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// li r3,32
	ctx.r3.s64 = 32;
	// addi r31,r31,-1
	ctx.r31.s64 = ctx.r31.s64 + -1;
	// bl 0x8207ef78
	ctx.lr = 0x8207FAD4;
	sub_8207EF78(ctx, base);
	// lwz r24,80(r1)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r24,-1
	ctx.cr6.compare<int32_t>(ctx.r24.s32, -1, ctx.xer);
	// beq cr6,0x8207fae8
	if (ctx.cr6.eq) goto loc_8207FAE8;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bgt cr6,0x8207fac0
	if (ctx.cr6.gt) goto loc_8207FAC0;
loc_8207FAE8:
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x8207fafc
	if (ctx.cr6.eq) goto loc_8207FAFC;
	// mr r3,r14
	ctx.r3.u64 = ctx.r14.u64;
	// bl 0x8207c068
	ctx.lr = 0x8207FAF8;
	sub_8207C068(ctx, base);
	// li r14,0
	ctx.r14.s64 = 0;
loc_8207FAFC:
	// lbz r29,1(r19)
	ctx.r29.u64 = PPC_LOAD_U8(ctx.r19.u32 + 1);
	// extsb. r8,r29
	ctx.r8.s64 = ctx.r29.s8;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x8207fb14
	if (ctx.cr0.eq) goto loc_8207FB14;
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r30,0
	ctx.r30.s64 = 0;
	// b 0x8207f190
	goto loc_8207F190;
loc_8207FB14:
	// lwz r11,100(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8207fb28
	if (ctx.cr6.eq) goto loc_8207FB28;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bne cr6,0x8207f050
	if (!ctx.cr6.eq) goto loc_8207F050;
loc_8207FB28:
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// b 0x8207fb64
	goto loc_8207FB64;
loc_8207FB30:
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// li r4,512
	ctx.r4.s64 = 512;
	// addi r3,r1,656
	ctx.r3.s64 = ctx.r1.s64 + 656;
	// bl 0x82082b70
	ctx.lr = 0x8207FB44;
	sub_82082B70(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x8207fb58
	if (!ctx.cr6.eq) goto loc_8207FB58;
	// li r31,511
	ctx.r31.s64 = 511;
	// stb r30,1167(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1167, ctx.r30.u8);
loc_8207FB58:
	// addi r3,r1,656
	ctx.r3.s64 = ctx.r1.s64 + 656;
	// bl 0x8208d988
	ctx.lr = 0x8207FB60;
	sub_8208D988(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8207FB64:
	// addi r1,r1,1328
	ctx.r1.s64 = ctx.r1.s64 + 1328;
	// b 0x8207c9a0
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8207FB6C"))) PPC_WEAK_FUNC(sub_8207FB6C);
PPC_FUNC_IMPL(__imp__sub_8207FB6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8207FB70"))) PPC_WEAK_FUNC(sub_8207FB70);
PPC_FUNC_IMPL(__imp__sub_8207FB70) {
	PPC_FUNC_PROLOGUE();
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// lis r11,-32248
	ctx.r11.s64 = -2113404928;
	// addi r30,r8,2800
	ctx.r30.s64 = ctx.r8.s64 + 2800;
	// addi r11,r11,15744
	ctx.r11.s64 = ctx.r11.s64 + 15744;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// stw r11,2800(r8)
	PPC_STORE_U32(ctx.r8.u32 + 2800, ctx.r11.u32);
	// lis r31,-32248
	ctx.r31.s64 = -2113404928;
	// addi r10,r10,12696
	ctx.r10.s64 = ctx.r10.s64 + 12696;
	// addi r9,r9,12680
	ctx.r9.s64 = ctx.r9.s64 + 12680;
	// addi r11,r31,12688
	ctx.r11.s64 = ctx.r31.s64 + 12688;
	// stw r10,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r10.u32);
	// lis r3,-32248
	ctx.r3.s64 = -2113404928;
	// stw r9,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r9.u32);
	// lis r4,-32248
	ctx.r4.s64 = -2113404928;
	// stw r11,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r11.u32);
	// lis r5,-32248
	ctx.r5.s64 = -2113404928;
	// addi r10,r3,12552
	ctx.r10.s64 = ctx.r3.s64 + 12552;
	// addi r9,r4,15744
	ctx.r9.s64 = ctx.r4.s64 + 15744;
	// addi r11,r5,15664
	ctx.r11.s64 = ctx.r5.s64 + 15664;
	// stw r10,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r10.u32);
	// lis r6,-32248
	ctx.r6.s64 = -2113404928;
	// stw r9,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r9.u32);
	// lis r7,-32248
	ctx.r7.s64 = -2113404928;
	// stw r11,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r11.u32);
	// lis r8,-32248
	ctx.r8.s64 = -2113404928;
	// addi r10,r6,12584
	ctx.r10.s64 = ctx.r6.s64 + 12584;
	// addi r9,r7,12384
	ctx.r9.s64 = ctx.r7.s64 + 12384;
	// addi r11,r8,12232
	ctx.r11.s64 = ctx.r8.s64 + 12232;
	// stw r10,28(r30)
	PPC_STORE_U32(ctx.r30.u32 + 28, ctx.r10.u32);
	// stw r9,32(r30)
	PPC_STORE_U32(ctx.r30.u32 + 32, ctx.r9.u32);
	// stw r11,36(r30)
	PPC_STORE_U32(ctx.r30.u32 + 36, ctx.r11.u32);
	// ld r30,-16(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8207FC04"))) PPC_WEAK_FUNC(sub_8207FC04);
PPC_FUNC_IMPL(__imp__sub_8207FC04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8207FC08"))) PPC_WEAK_FUNC(sub_8207FC08);
PPC_FUNC_IMPL(__imp__sub_8207FC08) {
	PPC_FUNC_PROLOGUE();
	// b 0x8207fb70
	sub_8207FB70(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8207FC0C"))) PPC_WEAK_FUNC(sub_8207FC0C);
PPC_FUNC_IMPL(__imp__sub_8207FC0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8207FC10"))) PPC_WEAK_FUNC(sub_8207FC10);
PPC_FUNC_IMPL(__imp__sub_8207FC10) {
	PPC_FUNC_PROLOGUE();
	// stfd f1,16(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + 16, ctx.f1.u64);
	// lhz r11,16(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 16);
	// stfd f1,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f1.u64);
	// addi r10,r4,1022
	ctx.r10.s64 = ctx.r4.s64 + 1022;
	// andi. r11,r11,32783
	ctx.r11.u64 = ctx.r11.u64 & 32783;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// sth r11,-16(r1)
	PPC_STORE_U16(ctx.r1.u32 + -16, ctx.r11.u16);
	// lfd f1,-16(r1)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8207FC38"))) PPC_WEAK_FUNC(sub_8207FC38);
PPC_FUNC_IMPL(__imp__sub_8207FC38) {
	PPC_FUNC_PROLOGUE();
	// stfd f1,16(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + 16, ctx.f1.u64);
	// lhz r11,16(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 16);
	// rlwinm r11,r11,28,21,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0x7FF;
	// addi r11,r11,-1022
	ctx.r11.s64 = ctx.r11.s64 + -1022;
	// extsh r3,r11
	ctx.r3.s64 = ctx.r11.s16;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8207FC50"))) PPC_WEAK_FUNC(sub_8207FC50);
PPC_FUNC_IMPL(__imp__sub_8207FC50) {
	PPC_FUNC_PROLOGUE();
	// lis r11,32752
	ctx.r11.s64 = 2146435072;
	// stfd f1,16(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + 16, ctx.f1.u64);
	// lwz r10,16(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 16);
	// lwz r9,20(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 20);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8207fc78
	if (!ctx.cr6.eq) goto loc_8207FC78;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8207fc94
	if (!ctx.cr6.eq) goto loc_8207FC94;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8207FC78:
	// lis r11,-16
	ctx.r11.s64 = -1048576;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8207fc94
	if (!ctx.cr6.eq) goto loc_8207FC94;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8207fc94
	if (!ctx.cr6.eq) goto loc_8207FC94;
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
loc_8207FC94:
	// lhz r11,16(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 16);
	// rlwinm r11,r11,0,17,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x7FF8;
	// cmplwi cr6,r11,32760
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32760, ctx.xer);
	// bne cr6,0x8207fcac
	if (!ctx.cr6.eq) goto loc_8207FCAC;
	// li r3,3
	ctx.r3.s64 = 3;
	// blr 
	return;
loc_8207FCAC:
	// cmplwi cr6,r11,32752
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32752, ctx.xer);
	// bne cr6,0x8207fccc
	if (!ctx.cr6.eq) goto loc_8207FCCC;
	// clrlwi. r11,r10,13
	ctx.r11.u64 = ctx.r10.u32 & 0x7FFFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8207fcc4
	if (!ctx.cr0.eq) goto loc_8207FCC4;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8207fccc
	if (ctx.cr6.eq) goto loc_8207FCCC;
loc_8207FCC4:
	// li r3,4
	ctx.r3.s64 = 4;
	// blr 
	return;
loc_8207FCCC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8207FCD4"))) PPC_WEAK_FUNC(sub_8207FCD4);
PPC_FUNC_IMPL(__imp__sub_8207FCD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8207FCD8"))) PPC_WEAK_FUNC(sub_8207FCD8);
PPC_FUNC_IMPL(__imp__sub_8207FCD8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// stfd f1,16(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + 16, ctx.f1.u64);
	// lfd f0,2432(r11)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r11.u32 + 2432);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// bne cr6,0x8207fcf4
	if (!ctx.cr6.eq) goto loc_8207FCF4;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x8207fdc4
	goto loc_8207FDC4;
loc_8207FCF4:
	// lhz r11,16(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 16);
	// rlwinm. r9,r11,0,17,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x7FF0;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x8207fd9c
	if (!ctx.cr0.eq) goto loc_8207FD9C;
	// lwz r8,16(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 16);
	// lwz r10,20(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 20);
	// clrlwi. r7,r8,12
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFFF;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne 0x8207fd18
	if (!ctx.cr0.eq) goto loc_8207FD18;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8207fd9c
	if (ctx.cr6.eq) goto loc_8207FD9C;
loc_8207FD18:
	// li r9,-1021
	ctx.r9.s64 = -1021;
	// fcmpu cr6,f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// li r7,1
	ctx.r7.s64 = 1;
	// blt cr6,0x8207fd2c
	if (ctx.cr6.lt) goto loc_8207FD2C;
	// li r7,0
	ctx.r7.s64 = 0;
loc_8207FD2C:
	// rlwinm. r6,r11,0,27,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne 0x8207fd64
	if (!ctx.cr0.eq) goto loc_8207FD64;
loc_8207FD34:
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm. r11,r10,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r8,16(r1)
	PPC_STORE_U32(ctx.r1.u32 + 16, ctx.r8.u32);
	// beq 0x8207fd4c
	if (ctx.cr0.eq) goto loc_8207FD4C;
	// ori r8,r8,1
	ctx.r8.u64 = ctx.r8.u64 | 1;
	// stw r8,16(r1)
	PPC_STORE_U32(ctx.r1.u32 + 16, ctx.r8.u32);
loc_8207FD4C:
	// lhz r11,16(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 16);
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// rlwinm. r6,r11,0,27,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq 0x8207fd34
	if (ctx.cr0.eq) goto loc_8207FD34;
	// stw r10,20(r1)
	PPC_STORE_U32(ctx.r1.u32 + 20, ctx.r10.u32);
loc_8207FD64:
	// andi. r11,r11,65519
	ctx.r11.u64 = ctx.r11.u64 & 65519;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// sth r11,16(r1)
	PPC_STORE_U16(ctx.r1.u32 + 16, ctx.r11.u16);
	// beq cr6,0x8207fd7c
	if (ctx.cr6.eq) goto loc_8207FD7C;
	// ori r11,r11,32768
	ctx.r11.u64 = ctx.r11.u64 | 32768;
	// sth r11,16(r1)
	PPC_STORE_U16(ctx.r1.u32 + 16, ctx.r11.u16);
loc_8207FD7C:
	// lfd f0,16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 16);
	// stfd f0,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f0.u64);
	// lhz r11,-16(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + -16);
	// andi. r11,r11,32783
	ctx.r11.u64 = ctx.r11.u64 & 32783;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stfd f0,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f0.u64);
	// ori r11,r11,16352
	ctx.r11.u64 = ctx.r11.u64 | 16352;
	// sth r11,-16(r1)
	PPC_STORE_U16(ctx.r1.u32 + -16, ctx.r11.u16);
	// b 0x8207fdc0
	goto loc_8207FDC0;
loc_8207FD9C:
	// stfd f1,-16(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f1.u64);
	// lhz r11,-16(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + -16);
	// andi. r11,r11,32783
	ctx.r11.u64 = ctx.r11.u64 & 32783;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stfd f1,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f1.u64);
	// ori r11,r11,16352
	ctx.r11.u64 = ctx.r11.u64 | 16352;
	// rlwinm r10,r9,28,20,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 28) & 0xFFF;
	// sth r11,-16(r1)
	PPC_STORE_U16(ctx.r1.u32 + -16, ctx.r11.u16);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// addi r9,r10,-1022
	ctx.r9.s64 = ctx.r10.s64 + -1022;
loc_8207FDC0:
	// lfd f1,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
loc_8207FDC4:
	// stw r9,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8207FDCC"))) PPC_WEAK_FUNC(sub_8207FDCC);
PPC_FUNC_IMPL(__imp__sub_8207FDCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8207FDD0"))) PPC_WEAK_FUNC(sub_8207FDD0);
PPC_FUNC_IMPL(__imp__sub_8207FDD0) {
	PPC_FUNC_PROLOGUE();
	// lis r12,-32256
	ctx.r12.s64 = -2113929216;
	// lfd f4,4512(r12)
	ctx.fpscr.disableFlushMode();
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r12.u32 + 4512);
	// lis r12,-32256
	ctx.r12.s64 = -2113929216;
	// lfd f5,4520(r12)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r12.u32 + 4520);
	// fcmpu cr0,f1,f4
	ctx.cr0.compare(ctx.f1.f64, ctx.f4.f64);
	// beq- 0x8207fe10
	if (ctx.cr0.eq) goto loc_8207FE10;
	// fabs f6,f1
	ctx.f6.u64 = ctx.f1.u64 & ~0x8000000000000000;
	// fcmpu cr0,f6,f5
	ctx.cr0.compare(ctx.f6.f64, ctx.f5.f64);
	// bge- 0x8207fe10
	if (!ctx.cr0.lt) goto loc_8207FE10;
	// fcmpu cr0,f1,f4
	ctx.cr0.compare(ctx.f1.f64, ctx.f4.f64);
	// blt 0x8207fe08
	if (ctx.cr0.lt) goto loc_8207FE08;
	// fadd f4,f1,f5
	ctx.f4.f64 = ctx.f1.f64 + ctx.f5.f64;
	// fsub f1,f4,f5
	ctx.f1.f64 = ctx.f4.f64 - ctx.f5.f64;
	// b 0x8207fe10
	goto loc_8207FE10;
loc_8207FE08:
	// fsub f4,f1,f5
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = ctx.f1.f64 - ctx.f5.f64;
	// fadd f1,f4,f5
	ctx.f1.f64 = ctx.f4.f64 + ctx.f5.f64;
loc_8207FE10:
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8207FE14"))) PPC_WEAK_FUNC(sub_8207FE14);
PPC_FUNC_IMPL(__imp__sub_8207FE14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8207FE18"))) PPC_WEAK_FUNC(sub_8207FE18);
PPC_FUNC_IMPL(__imp__sub_8207FE18) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lwz r3,-11864(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11864);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8207FE24"))) PPC_WEAK_FUNC(sub_8207FE24);
PPC_FUNC_IMPL(__imp__sub_8207FE24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8207FE28"))) PPC_WEAK_FUNC(sub_8207FE28);
PPC_FUNC_IMPL(__imp__sub_8207FE28) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lwz r16,21428(r29)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r29.u32 + 21428);
	// lwz r16,6752(r5)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r5.u32 + 6752);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x8207FE38;
	__savegprlr_26(ctx, base);
	// addi r31,r1,-160
	ctx.r31.s64 = ctx.r1.s64 + -160;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// stw r3,180(r31)
	PPC_STORE_U32(ctx.r31.u32 + 180, ctx.r3.u32);
	// li r26,0
	ctx.r26.s64 = 0;
	// cmpwi cr6,r3,11
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 11, ctx.xer);
	// mr r28,r26
	ctx.r28.u64 = ctx.r26.u64;
	// mr r27,r26
	ctx.r27.u64 = ctx.r26.u64;
	// stw r26,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r26.u32);
	// stw r26,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r26.u32);
	// bgt cr6,0x8207ff0c
	if (ctx.cr6.gt) goto loc_8207FF0C;
	// beq cr6,0x8207fe88
	if (ctx.cr6.eq) goto loc_8207FE88;
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x8207fea0
	if (ctx.cr6.eq) goto loc_8207FEA0;
	// cmpwi cr6,r3,4
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 4, ctx.xer);
	// beq cr6,0x8207fe88
	if (ctx.cr6.eq) goto loc_8207FE88;
	// cmpwi cr6,r3,6
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 6, ctx.xer);
	// beq cr6,0x8207ff4c
	if (ctx.cr6.eq) goto loc_8207FF4C;
	// cmpwi cr6,r3,8
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 8, ctx.xer);
	// bne cr6,0x8207ff24
	if (!ctx.cr6.eq) goto loc_8207FF24;
loc_8207FE88:
	// bl 0x820810f8
	ctx.lr = 0x8207FE8C;
	sub_820810F8(ctx, base);
	// mr. r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// stw r27,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r27.u32);
	// bne 0x8207feb0
	if (!ctx.cr0.eq) goto loc_8207FEB0;
loc_8207FE98:
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x820800c4
	goto loc_820800C4;
loc_8207FEA0:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r30,r11,-11872
	ctx.r30.s64 = ctx.r11.s64 + -11872;
	// lwz r11,-11872(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11872);
	// b 0x8207ff84
	goto loc_8207FF84;
loc_8207FEB0:
	// lwz r10,92(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 92);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// lwz r8,2552(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2552);
loc_8207FEC0:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmpw cr6,r9,r29
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r29.s32, ctx.xer);
	// beq cr6,0x8207fee0
	if (ctx.cr6.eq) goto loc_8207FEE0;
	// mulli r9,r8,12
	ctx.r9.s64 = ctx.r8.s64 * 12;
	// addi r11,r11,12
	ctx.r11.s64 = ctx.r11.s64 + 12;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x8207fec0
	if (ctx.cr6.lt) goto loc_8207FEC0;
loc_8207FEE0:
	// mulli r9,r8,12
	ctx.r9.s64 = ctx.r8.s64 * 12;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8207fefc
	if (!ctx.cr6.lt) goto loc_8207FEFC;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmpw cr6,r10,r29
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r29.s32, ctx.xer);
	// beq cr6,0x8207ff00
	if (ctx.cr6.eq) goto loc_8207FF00;
loc_8207FEFC:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_8207FF00:
	// addi r30,r11,8
	ctx.r30.s64 = ctx.r11.s64 + 8;
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x8207ff8c
	goto loc_8207FF8C;
loc_8207FF0C:
	// cmpwi cr6,r29,15
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 15, ctx.xer);
	// beq cr6,0x8207ff74
	if (ctx.cr6.eq) goto loc_8207FF74;
	// cmpwi cr6,r29,21
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 21, ctx.xer);
	// beq cr6,0x8207ff60
	if (ctx.cr6.eq) goto loc_8207FF60;
	// cmpwi cr6,r29,22
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 22, ctx.xer);
	// beq cr6,0x8207ff4c
	if (ctx.cr6.eq) goto loc_8207FF4C;
loc_8207FF24:
	// bl 0x8207d4d8
	ctx.lr = 0x8207FF28;
	sub_8207D4D8(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d940
	ctx.lr = 0x8207FF48;
	sub_8207D940(ctx, base);
	// b 0x8207fe98
	goto loc_8207FE98;
loc_8207FF4C:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r11,r11,-11872
	ctx.r11.s64 = ctx.r11.s64 + -11872;
	// addi r30,r11,8
	ctx.r30.s64 = ctx.r11.s64 + 8;
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x8207ff84
	goto loc_8207FF84;
loc_8207FF60:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r11,r11,-11872
	ctx.r11.s64 = ctx.r11.s64 + -11872;
	// addi r30,r11,4
	ctx.r30.s64 = ctx.r11.s64 + 4;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x8207ff84
	goto loc_8207FF84;
loc_8207FF74:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r11,r11,-11872
	ctx.r11.s64 = ctx.r11.s64 + -11872;
	// addi r30,r11,12
	ctx.r30.s64 = ctx.r11.s64 + 12;
	// lwz r11,12(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
loc_8207FF84:
	// li r28,1
	ctx.r28.s64 = 1;
	// stw r28,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r28.u32);
loc_8207FF8C:
	// stw r11,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x820800c0
	if (ctx.cr6.eq) goto loc_820800C0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8207ffa8
	if (!ctx.cr6.eq) goto loc_8207FFA8;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x8207d370
	ctx.lr = 0x8207FFA8;
	sub_8207D370(ctx, base);
loc_8207FFA8:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq cr6,0x8207ffb8
	if (ctx.cr6.eq) goto loc_8207FFB8;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d808
	ctx.lr = 0x8207FFB8;
	sub_8207D808(ctx, base);
loc_8207FFB8:
	// nop 
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// cmpwi cr6,r29,8
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 8, ctx.xer);
	// beq cr6,0x8207ffd8
	if (ctx.cr6.eq) goto loc_8207FFD8;
	// cmpwi cr6,r29,11
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 11, ctx.xer);
	// beq cr6,0x8207ffd8
	if (ctx.cr6.eq) goto loc_8207FFD8;
	// cmpwi cr6,r29,4
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 4, ctx.xer);
	// bne cr6,0x8207fffc
	if (!ctx.cr6.eq) goto loc_8207FFFC;
loc_8207FFD8:
	// lwz r11,96(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 96);
	// cmpwi cr6,r29,8
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 8, ctx.xer);
	// stw r11,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
	// stw r26,96(r27)
	PPC_STORE_U32(ctx.r27.u32 + 96, ctx.r26.u32);
	// bne cr6,0x8208004c
	if (!ctx.cr6.eq) goto loc_8208004C;
	// lwz r11,100(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 100);
	// li r10,140
	ctx.r10.s64 = 140;
	// stw r11,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
	// stw r10,100(r27)
	PPC_STORE_U32(ctx.r27.u32 + 100, ctx.r10.u32);
loc_8207FFFC:
	// cmpwi cr6,r29,8
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 8, ctx.xer);
	// bne cr6,0x8208004c
	if (!ctx.cr6.eq) goto loc_8208004C;
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// lis r7,-32226
	ctx.r7.s64 = -2111963136;
	// lwz r10,2540(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2540);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// stw r10,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r10.u32);
loc_82080018:
	// lwz r9,2544(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2544);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x82080050
	if (!ctx.cr6.lt) goto loc_82080050;
	// lwz r9,92(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 92);
	// mulli r10,r11,12
	ctx.r10.s64 = ctx.r11.s64 * 12;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r26,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r26.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// lwz r10,2540(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2540);
	// b 0x82080018
	goto loc_82080018;
loc_8208004C:
	// stw r26,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r26.u32);
loc_82080050:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,160
	ctx.r12.s64 = ctx.r31.s64 + 160;
	// bl 0x820800ec
	ctx.lr = 0x8208005C;
	sub_820800EC(ctx, base);
	// lwz r30,180(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 180);
	// cmpwi cr6,r30,8
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 8, ctx.xer);
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bne cr6,0x82080084
	if (!ctx.cr6.eq) goto loc_82080084;
	// li r3,8
	ctx.r3.s64 = 8;
	// lwz r29,88(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// lwz r4,100(r29)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r29.u32 + 100);
	// bctrl 
	ctx.lr = 0x82080080;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82080090
	goto loc_82080090;
loc_82080084:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bctrl 
	ctx.lr = 0x8208008C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r29,88(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
loc_82080090:
	// cmpwi cr6,r30,8
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 8, ctx.xer);
	// beq cr6,0x820800a8
	if (ctx.cr6.eq) goto loc_820800A8;
	// cmpwi cr6,r30,11
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 11, ctx.xer);
	// beq cr6,0x820800a8
	if (ctx.cr6.eq) goto loc_820800A8;
	// cmpwi cr6,r30,4
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 4, ctx.xer);
	// bne cr6,0x820800c0
	if (!ctx.cr6.eq) goto loc_820800C0;
loc_820800A8:
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// cmpwi cr6,r30,8
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 8, ctx.xer);
	// stw r11,96(r29)
	PPC_STORE_U32(ctx.r29.u32 + 96, ctx.r11.u32);
	// bne cr6,0x820800c0
	if (!ctx.cr6.eq) goto loc_820800C0;
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// stw r11,100(r29)
	PPC_STORE_U32(ctx.r29.u32 + 100, ctx.r11.u32);
loc_820800C0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_820800C4:
	// addi r1,r31,160
	ctx.r1.s64 = ctx.r31.s64 + 160;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8207FE30"))) PPC_WEAK_FUNC(sub_8207FE30);
PPC_FUNC_IMPL(__imp__sub_8207FE30) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x8207FE38;
	__savegprlr_26(ctx, base);
	// addi r31,r1,-160
	ctx.r31.s64 = ctx.r1.s64 + -160;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// stw r3,180(r31)
	PPC_STORE_U32(ctx.r31.u32 + 180, ctx.r3.u32);
	// li r26,0
	ctx.r26.s64 = 0;
	// cmpwi cr6,r3,11
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 11, ctx.xer);
	// mr r28,r26
	ctx.r28.u64 = ctx.r26.u64;
	// mr r27,r26
	ctx.r27.u64 = ctx.r26.u64;
	// stw r26,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r26.u32);
	// stw r26,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r26.u32);
	// bgt cr6,0x8207ff0c
	if (ctx.cr6.gt) goto loc_8207FF0C;
	// beq cr6,0x8207fe88
	if (ctx.cr6.eq) goto loc_8207FE88;
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x8207fea0
	if (ctx.cr6.eq) goto loc_8207FEA0;
	// cmpwi cr6,r3,4
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 4, ctx.xer);
	// beq cr6,0x8207fe88
	if (ctx.cr6.eq) goto loc_8207FE88;
	// cmpwi cr6,r3,6
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 6, ctx.xer);
	// beq cr6,0x8207ff4c
	if (ctx.cr6.eq) goto loc_8207FF4C;
	// cmpwi cr6,r3,8
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 8, ctx.xer);
	// bne cr6,0x8207ff24
	if (!ctx.cr6.eq) goto loc_8207FF24;
loc_8207FE88:
	// bl 0x820810f8
	ctx.lr = 0x8207FE8C;
	sub_820810F8(ctx, base);
	// mr. r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// stw r27,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r27.u32);
	// bne 0x8207feb0
	if (!ctx.cr0.eq) goto loc_8207FEB0;
loc_8207FE98:
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x820800c4
	goto loc_820800C4;
loc_8207FEA0:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r30,r11,-11872
	ctx.r30.s64 = ctx.r11.s64 + -11872;
	// lwz r11,-11872(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11872);
	// b 0x8207ff84
	goto loc_8207FF84;
loc_8207FEB0:
	// lwz r10,92(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 92);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// lwz r8,2552(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2552);
loc_8207FEC0:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmpw cr6,r9,r29
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r29.s32, ctx.xer);
	// beq cr6,0x8207fee0
	if (ctx.cr6.eq) goto loc_8207FEE0;
	// mulli r9,r8,12
	ctx.r9.s64 = ctx.r8.s64 * 12;
	// addi r11,r11,12
	ctx.r11.s64 = ctx.r11.s64 + 12;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x8207fec0
	if (ctx.cr6.lt) goto loc_8207FEC0;
loc_8207FEE0:
	// mulli r9,r8,12
	ctx.r9.s64 = ctx.r8.s64 * 12;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8207fefc
	if (!ctx.cr6.lt) goto loc_8207FEFC;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmpw cr6,r10,r29
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r29.s32, ctx.xer);
	// beq cr6,0x8207ff00
	if (ctx.cr6.eq) goto loc_8207FF00;
loc_8207FEFC:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_8207FF00:
	// addi r30,r11,8
	ctx.r30.s64 = ctx.r11.s64 + 8;
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x8207ff8c
	goto loc_8207FF8C;
loc_8207FF0C:
	// cmpwi cr6,r29,15
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 15, ctx.xer);
	// beq cr6,0x8207ff74
	if (ctx.cr6.eq) goto loc_8207FF74;
	// cmpwi cr6,r29,21
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 21, ctx.xer);
	// beq cr6,0x8207ff60
	if (ctx.cr6.eq) goto loc_8207FF60;
	// cmpwi cr6,r29,22
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 22, ctx.xer);
	// beq cr6,0x8207ff4c
	if (ctx.cr6.eq) goto loc_8207FF4C;
loc_8207FF24:
	// bl 0x8207d4d8
	ctx.lr = 0x8207FF28;
	sub_8207D4D8(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d940
	ctx.lr = 0x8207FF48;
	sub_8207D940(ctx, base);
	// b 0x8207fe98
	goto loc_8207FE98;
loc_8207FF4C:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r11,r11,-11872
	ctx.r11.s64 = ctx.r11.s64 + -11872;
	// addi r30,r11,8
	ctx.r30.s64 = ctx.r11.s64 + 8;
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x8207ff84
	goto loc_8207FF84;
loc_8207FF60:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r11,r11,-11872
	ctx.r11.s64 = ctx.r11.s64 + -11872;
	// addi r30,r11,4
	ctx.r30.s64 = ctx.r11.s64 + 4;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x8207ff84
	goto loc_8207FF84;
loc_8207FF74:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r11,r11,-11872
	ctx.r11.s64 = ctx.r11.s64 + -11872;
	// addi r30,r11,12
	ctx.r30.s64 = ctx.r11.s64 + 12;
	// lwz r11,12(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
loc_8207FF84:
	// li r28,1
	ctx.r28.s64 = 1;
	// stw r28,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r28.u32);
loc_8207FF8C:
	// stw r11,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x820800c0
	if (ctx.cr6.eq) goto loc_820800C0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8207ffa8
	if (!ctx.cr6.eq) goto loc_8207FFA8;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x8207d370
	ctx.lr = 0x8207FFA8;
	sub_8207D370(ctx, base);
loc_8207FFA8:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq cr6,0x8207ffb8
	if (ctx.cr6.eq) goto loc_8207FFB8;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d808
	ctx.lr = 0x8207FFB8;
	sub_8207D808(ctx, base);
loc_8207FFB8:
	// nop 
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// cmpwi cr6,r29,8
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 8, ctx.xer);
	// beq cr6,0x8207ffd8
	if (ctx.cr6.eq) goto loc_8207FFD8;
	// cmpwi cr6,r29,11
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 11, ctx.xer);
	// beq cr6,0x8207ffd8
	if (ctx.cr6.eq) goto loc_8207FFD8;
	// cmpwi cr6,r29,4
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 4, ctx.xer);
	// bne cr6,0x8207fffc
	if (!ctx.cr6.eq) goto loc_8207FFFC;
loc_8207FFD8:
	// lwz r11,96(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 96);
	// cmpwi cr6,r29,8
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 8, ctx.xer);
	// stw r11,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
	// stw r26,96(r27)
	PPC_STORE_U32(ctx.r27.u32 + 96, ctx.r26.u32);
	// bne cr6,0x8208004c
	if (!ctx.cr6.eq) goto loc_8208004C;
	// lwz r11,100(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 100);
	// li r10,140
	ctx.r10.s64 = 140;
	// stw r11,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
	// stw r10,100(r27)
	PPC_STORE_U32(ctx.r27.u32 + 100, ctx.r10.u32);
loc_8207FFFC:
	// cmpwi cr6,r29,8
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 8, ctx.xer);
	// bne cr6,0x8208004c
	if (!ctx.cr6.eq) goto loc_8208004C;
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// lis r7,-32226
	ctx.r7.s64 = -2111963136;
	// lwz r10,2540(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2540);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// stw r10,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r10.u32);
loc_82080018:
	// lwz r9,2544(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2544);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x82080050
	if (!ctx.cr6.lt) goto loc_82080050;
	// lwz r9,92(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 92);
	// mulli r10,r11,12
	ctx.r10.s64 = ctx.r11.s64 * 12;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r26,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r26.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// lwz r10,2540(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2540);
	// b 0x82080018
	goto loc_82080018;
loc_8208004C:
	// stw r26,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r26.u32);
loc_82080050:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,160
	ctx.r12.s64 = ctx.r31.s64 + 160;
	// bl 0x820800ec
	ctx.lr = 0x8208005C;
	sub_820800EC(ctx, base);
	// lwz r30,180(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 180);
	// cmpwi cr6,r30,8
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 8, ctx.xer);
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bne cr6,0x82080084
	if (!ctx.cr6.eq) goto loc_82080084;
	// li r3,8
	ctx.r3.s64 = 8;
	// lwz r29,88(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// lwz r4,100(r29)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r29.u32 + 100);
	// bctrl 
	ctx.lr = 0x82080080;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82080090
	goto loc_82080090;
loc_82080084:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bctrl 
	ctx.lr = 0x8208008C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r29,88(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
loc_82080090:
	// cmpwi cr6,r30,8
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 8, ctx.xer);
	// beq cr6,0x820800a8
	if (ctx.cr6.eq) goto loc_820800A8;
	// cmpwi cr6,r30,11
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 11, ctx.xer);
	// beq cr6,0x820800a8
	if (ctx.cr6.eq) goto loc_820800A8;
	// cmpwi cr6,r30,4
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 4, ctx.xer);
	// bne cr6,0x820800c0
	if (!ctx.cr6.eq) goto loc_820800C0;
loc_820800A8:
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// cmpwi cr6,r30,8
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 8, ctx.xer);
	// stw r11,96(r29)
	PPC_STORE_U32(ctx.r29.u32 + 96, ctx.r11.u32);
	// bne cr6,0x820800c0
	if (!ctx.cr6.eq) goto loc_820800C0;
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// stw r11,100(r29)
	PPC_STORE_U32(ctx.r29.u32 + 100, ctx.r11.u32);
loc_820800C0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_820800C4:
	// addi r1,r31,160
	ctx.r1.s64 = ctx.r31.s64 + 160;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820800CC"))) PPC_WEAK_FUNC(sub_820800CC);
PPC_FUNC_IMPL(__imp__sub_820800CC) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r31,r12,-160
	ctx.r31.s64 = ctx.r12.s64 + -160;
	// std r28,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r28.u64);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r28,84(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// b 0x82080104
	goto loc_82080104;
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r31,r12,-160
	ctx.r31.s64 = ctx.r12.s64 + -160;
	// std r28,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r28.u64);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
loc_82080104:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq cr6,0x82080114
	if (ctx.cr6.eq) goto loc_82080114;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d6a8
	ctx.lr = 0x82080114;
	sub_8207D6A8(ctx, base);
loc_82080114:
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r28,-16(r1)
	ctx.r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-24(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820800EC"))) PPC_WEAK_FUNC(sub_820800EC);
PPC_FUNC_IMPL(__imp__sub_820800EC) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r31,r12,-160
	ctx.r31.s64 = ctx.r12.s64 + -160;
	// std r28,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r28.u64);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq cr6,0x82080114
	if (ctx.cr6.eq) goto loc_82080114;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d6a8
	ctx.lr = 0x82080114;
	sub_8207D6A8(ctx, base);
loc_82080114:
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r28,-16(r1)
	ctx.r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-24(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8208012C"))) PPC_WEAK_FUNC(sub_8208012C);
PPC_FUNC_IMPL(__imp__sub_8208012C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82080130"))) PPC_WEAK_FUNC(sub_82080130);
PPC_FUNC_IMPL(__imp__sub_82080130) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// stfd f1,16(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + 16, ctx.f1.u64);
	// lfd f6,2064(r11)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r11.u32 + 2064);
	// fcmpu cr6,f1,f6
	ctx.cr6.compare(ctx.f1.f64, ctx.f6.f64);
	// bne cr6,0x82080150
	if (!ctx.cr6.eq) goto loc_82080150;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfd f1,2432(r11)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r11.u32 + 2432);
	// blr 
	return;
loc_82080150:
	// lhz r10,16(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 16);
	// rlwinm r11,r10,0,17,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x7FF0;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// cmplwi cr6,r11,32752
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32752, ctx.xer);
	// bne cr6,0x82080184
	if (!ctx.cr6.eq) goto loc_82080184;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfd f0,4664(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r11.u32 + 4664);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// bgtlr cr6
	if (ctx.cr6.gt) return;
loc_82080174:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfd f0,2400(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r11.u32 + 2400);
loc_8208017C:
	// fneg f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// blr 
	return;
loc_82080184:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfd f0,2432(r10)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r10.u32 + 2432);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// bgt cr6,0x820801a8
	if (ctx.cr6.gt) goto loc_820801A8;
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// bne cr6,0x82080174
	if (!ctx.cr6.eq) goto loc_82080174;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfd f0,2392(r11)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r11.u32 + 2392);
	// b 0x8208017c
	goto loc_8208017C;
loc_820801A8:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfd f0,4656(r10)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r10.u32 + 4656);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// bge cr6,0x820801e0
	if (!ctx.cr6.lt) goto loc_820801E0;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfd f0,4648(r11)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r11.u32 + 4648);
	// fmul f1,f1,f0
	ctx.f1.f64 = ctx.f1.f64 * ctx.f0.f64;
	// stfd f1,16(r1)
	PPC_STORE_U64(ctx.r1.u32 + 16, ctx.f1.u64);
	// lhz r11,16(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 16);
	// rlwinm r10,r11,28,21,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0x7FF;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// addi r10,r10,-1075
	ctx.r10.s64 = ctx.r10.s64 + -1075;
	// b 0x820801e8
	goto loc_820801E8;
loc_820801E0:
	// rlwinm r11,r11,28,20,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0xFFF;
	// addi r10,r11,-1022
	ctx.r10.s64 = ctx.r11.s64 + -1022;
loc_820801E8:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// stfd f1,-16(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f1.u64);
	// andi. r9,r9,32783
	ctx.r9.u64 = ctx.r9.u64 & 32783;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// addi r11,r11,4528
	ctx.r11.s64 = ctx.r11.s64 + 4528;
	// ori r9,r9,16352
	ctx.r9.u64 = ctx.r9.u64 | 16352;
	// sth r9,-16(r1)
	PPC_STORE_U16(ctx.r1.u32 + -16, ctx.r9.u16);
	// lfd f13,-16(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfd f0,0(r11)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r11.u32 + 0);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x8208022c
	if (!ctx.cr6.gt) goto loc_8208022C;
	// lfd f0,2072(r9)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r9.u32 + 2072);
	// fadd f12,f13,f6
	ctx.f12.f64 = ctx.f13.f64 + ctx.f6.f64;
	// fsub f11,f13,f0
	ctx.f11.f64 = ctx.f13.f64 - ctx.f0.f64;
	// fmul f13,f12,f0
	ctx.f13.f64 = ctx.f12.f64 * ctx.f0.f64;
	// fsub f0,f11,f0
	ctx.f0.f64 = ctx.f11.f64 - ctx.f0.f64;
	// b 0x82080240
	goto loc_82080240;
loc_8208022C:
	// lfd f12,2072(r9)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r9.u32 + 2072);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// fsub f0,f13,f12
	ctx.f0.f64 = ctx.f13.f64 - ctx.f12.f64;
	// fadd f13,f0,f6
	ctx.f13.f64 = ctx.f0.f64 + ctx.f6.f64;
	// fmul f13,f13,f12
	ctx.f13.f64 = ctx.f13.f64 * ctx.f12.f64;
loc_82080240:
	// fdiv f5,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f5.f64 = ctx.f0.f64 / ctx.f13.f64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfd f12,40(r11)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r11.u32 + 40);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfd f9,64(r11)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r11.u32 + 64);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfd f7,8(r11)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r11.u32 + 8);
	// extsw r11,r10
	ctx.r11.s64 = ctx.r10.s32;
	// lfd f13,4640(r9)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r9.u32 + 4640);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfd f11,4632(r8)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r8.u32 + 4632);
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r11.u64);
	// lfd f10,4624(r7)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r7.u32 + 4624);
	// lfd f8,4616(r6)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r6.u32 + 4616);
	// lfd f0,-16(r1)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f4,f0
	ctx.f4.f64 = double(ctx.f0.s64);
	// fmul f3,f5,f5
	ctx.f3.f64 = ctx.f5.f64 * ctx.f5.f64;
	// lfd f0,4608(r10)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r10.u32 + 4608);
	// fmul f0,f4,f0
	ctx.f0.f64 = ctx.f4.f64 * ctx.f0.f64;
	// fnmsub f13,f3,f13,f12
	ctx.f13.f64 = -(ctx.f3.f64 * ctx.f13.f64 - ctx.f12.f64);
	// fsub f12,f3,f11
	ctx.f12.f64 = ctx.f3.f64 - ctx.f11.f64;
	// fmsub f13,f13,f3,f10
	ctx.f13.f64 = ctx.f13.f64 * ctx.f3.f64 - ctx.f10.f64;
	// fmadd f12,f12,f3,f9
	ctx.f12.f64 = ctx.f12.f64 * ctx.f3.f64 + ctx.f9.f64;
	// fmul f13,f13,f3
	ctx.f13.f64 = ctx.f13.f64 * ctx.f3.f64;
	// fmsub f12,f12,f3,f8
	ctx.f12.f64 = ctx.f12.f64 * ctx.f3.f64 - ctx.f8.f64;
	// fdiv f13,f13,f12
	ctx.f13.f64 = ctx.f13.f64 / ctx.f12.f64;
	// fadd f13,f13,f6
	ctx.f13.f64 = ctx.f13.f64 + ctx.f6.f64;
	// fmsub f0,f13,f5,f0
	ctx.f0.f64 = ctx.f13.f64 * ctx.f5.f64 - ctx.f0.f64;
	// fmadd f1,f4,f7,f0
	ctx.f1.f64 = ctx.f4.f64 * ctx.f7.f64 + ctx.f0.f64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820802BC"))) PPC_WEAK_FUNC(sub_820802BC);
PPC_FUNC_IMPL(__imp__sub_820802BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820802C0"))) PPC_WEAK_FUNC(sub_820802C0);
PPC_FUNC_IMPL(__imp__sub_820802C0) {
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
	// bl 0x82080130
	ctx.lr = 0x820802D0;
	sub_82080130(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfd f0,4552(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r11.u32 + 4552);
	// fmul f1,f1,f0
	ctx.f1.f64 = ctx.f1.f64 * ctx.f0.f64;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820802EC"))) PPC_WEAK_FUNC(sub_820802EC);
PPC_FUNC_IMPL(__imp__sub_820802EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820802F0"))) PPC_WEAK_FUNC(sub_820802F0);
PPC_FUNC_IMPL(__imp__sub_820802F0) {
	PPC_FUNC_PROLOGUE();
	// stfd f2,24(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + 24, ctx.f2.u64);
	// lwz r11,24(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 24);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stfd f1,16(r1)
	PPC_STORE_U64(ctx.r1.u32 + 16, ctx.f1.u64);
	// lwz r9,16(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 16);
	// lwz r8,20(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 20);
	// lfd f0,2432(r10)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r10.u32 + 2432);
	// stfd f0,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f0.u64);
	// stw r8,-12(r1)
	PPC_STORE_U32(ctx.r1.u32 + -12, ctx.r8.u32);
	// rlwimi r11,r9,0,1,31
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r9.u32, 0) & 0x7FFFFFFF) | (ctx.r11.u64 & 0xFFFFFFFF80000000);
	// stw r11,-16(r1)
	PPC_STORE_U32(ctx.r1.u32 + -16, ctx.r11.u32);
	// lfd f1,-16(r1)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82080324"))) PPC_WEAK_FUNC(sub_82080324);
PPC_FUNC_IMPL(__imp__sub_82080324) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82080328"))) PPC_WEAK_FUNC(sub_82080328);
PPC_FUNC_IMPL(__imp__sub_82080328) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8208032C"))) PPC_WEAK_FUNC(sub_8208032C);
PPC_FUNC_IMPL(__imp__sub_8208032C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp____savefpr_14"))) PPC_WEAK_FUNC(__savefpr_14);
PPC_FUNC_IMPL(__imp____savefpr_14) {
	PPC_FUNC_PROLOGUE();
	// stfd f14,-144(r12)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r12.u32 + -144, ctx.f14.u64);
	// stfd f15,-136(r12)
	PPC_STORE_U64(ctx.r12.u32 + -136, ctx.f15.u64);
	// stfd f16,-128(r12)
	PPC_STORE_U64(ctx.r12.u32 + -128, ctx.f16.u64);
	// stfd f17,-120(r12)
	PPC_STORE_U64(ctx.r12.u32 + -120, ctx.f17.u64);
	// stfd f18,-112(r12)
	PPC_STORE_U64(ctx.r12.u32 + -112, ctx.f18.u64);
	// stfd f19,-104(r12)
	PPC_STORE_U64(ctx.r12.u32 + -104, ctx.f19.u64);
	// stfd f20,-96(r12)
	PPC_STORE_U64(ctx.r12.u32 + -96, ctx.f20.u64);
	// stfd f21,-88(r12)
	PPC_STORE_U64(ctx.r12.u32 + -88, ctx.f21.u64);
	// stfd f22,-80(r12)
	PPC_STORE_U64(ctx.r12.u32 + -80, ctx.f22.u64);
	// stfd f23,-72(r12)
	PPC_STORE_U64(ctx.r12.u32 + -72, ctx.f23.u64);
	// stfd f24,-64(r12)
	PPC_STORE_U64(ctx.r12.u32 + -64, ctx.f24.u64);
	// stfd f25,-56(r12)
	PPC_STORE_U64(ctx.r12.u32 + -56, ctx.f25.u64);
	// stfd f26,-48(r12)
	PPC_STORE_U64(ctx.r12.u32 + -48, ctx.f26.u64);
	// stfd f27,-40(r12)
	PPC_STORE_U64(ctx.r12.u32 + -40, ctx.f27.u64);
	// stfd f28,-32(r12)
	PPC_STORE_U64(ctx.r12.u32 + -32, ctx.f28.u64);
	// stfd f29,-24(r12)
	PPC_STORE_U64(ctx.r12.u32 + -24, ctx.f29.u64);
	// stfd f30,-16(r12)
	PPC_STORE_U64(ctx.r12.u32 + -16, ctx.f30.u64);
	// stfd f31,-8(r12)
	PPC_STORE_U64(ctx.r12.u32 + -8, ctx.f31.u64);
	// blr 
	return;
}

__attribute__((alias("__imp____savefpr_15"))) PPC_WEAK_FUNC(__savefpr_15);
PPC_FUNC_IMPL(__imp____savefpr_15) {
	PPC_FUNC_PROLOGUE();
	// stfd f15,-136(r12)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r12.u32 + -136, ctx.f15.u64);
	// stfd f16,-128(r12)
	PPC_STORE_U64(ctx.r12.u32 + -128, ctx.f16.u64);
	// stfd f17,-120(r12)
	PPC_STORE_U64(ctx.r12.u32 + -120, ctx.f17.u64);
	// stfd f18,-112(r12)
	PPC_STORE_U64(ctx.r12.u32 + -112, ctx.f18.u64);
	// stfd f19,-104(r12)
	PPC_STORE_U64(ctx.r12.u32 + -104, ctx.f19.u64);
	// stfd f20,-96(r12)
	PPC_STORE_U64(ctx.r12.u32 + -96, ctx.f20.u64);
	// stfd f21,-88(r12)
	PPC_STORE_U64(ctx.r12.u32 + -88, ctx.f21.u64);
	// stfd f22,-80(r12)
	PPC_STORE_U64(ctx.r12.u32 + -80, ctx.f22.u64);
	// stfd f23,-72(r12)
	PPC_STORE_U64(ctx.r12.u32 + -72, ctx.f23.u64);
	// stfd f24,-64(r12)
	PPC_STORE_U64(ctx.r12.u32 + -64, ctx.f24.u64);
	// stfd f25,-56(r12)
	PPC_STORE_U64(ctx.r12.u32 + -56, ctx.f25.u64);
	// stfd f26,-48(r12)
	PPC_STORE_U64(ctx.r12.u32 + -48, ctx.f26.u64);
	// stfd f27,-40(r12)
	PPC_STORE_U64(ctx.r12.u32 + -40, ctx.f27.u64);
	// stfd f28,-32(r12)
	PPC_STORE_U64(ctx.r12.u32 + -32, ctx.f28.u64);
	// stfd f29,-24(r12)
	PPC_STORE_U64(ctx.r12.u32 + -24, ctx.f29.u64);
	// stfd f30,-16(r12)
	PPC_STORE_U64(ctx.r12.u32 + -16, ctx.f30.u64);
	// stfd f31,-8(r12)
	PPC_STORE_U64(ctx.r12.u32 + -8, ctx.f31.u64);
	// blr 
	return;
}

__attribute__((alias("__imp____savefpr_16"))) PPC_WEAK_FUNC(__savefpr_16);
PPC_FUNC_IMPL(__imp____savefpr_16) {
	PPC_FUNC_PROLOGUE();
	// stfd f16,-128(r12)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r12.u32 + -128, ctx.f16.u64);
	// stfd f17,-120(r12)
	PPC_STORE_U64(ctx.r12.u32 + -120, ctx.f17.u64);
	// stfd f18,-112(r12)
	PPC_STORE_U64(ctx.r12.u32 + -112, ctx.f18.u64);
	// stfd f19,-104(r12)
	PPC_STORE_U64(ctx.r12.u32 + -104, ctx.f19.u64);
	// stfd f20,-96(r12)
	PPC_STORE_U64(ctx.r12.u32 + -96, ctx.f20.u64);
	// stfd f21,-88(r12)
	PPC_STORE_U64(ctx.r12.u32 + -88, ctx.f21.u64);
	// stfd f22,-80(r12)
	PPC_STORE_U64(ctx.r12.u32 + -80, ctx.f22.u64);
	// stfd f23,-72(r12)
	PPC_STORE_U64(ctx.r12.u32 + -72, ctx.f23.u64);
	// stfd f24,-64(r12)
	PPC_STORE_U64(ctx.r12.u32 + -64, ctx.f24.u64);
	// stfd f25,-56(r12)
	PPC_STORE_U64(ctx.r12.u32 + -56, ctx.f25.u64);
	// stfd f26,-48(r12)
	PPC_STORE_U64(ctx.r12.u32 + -48, ctx.f26.u64);
	// stfd f27,-40(r12)
	PPC_STORE_U64(ctx.r12.u32 + -40, ctx.f27.u64);
	// stfd f28,-32(r12)
	PPC_STORE_U64(ctx.r12.u32 + -32, ctx.f28.u64);
	// stfd f29,-24(r12)
	PPC_STORE_U64(ctx.r12.u32 + -24, ctx.f29.u64);
	// stfd f30,-16(r12)
	PPC_STORE_U64(ctx.r12.u32 + -16, ctx.f30.u64);
	// stfd f31,-8(r12)
	PPC_STORE_U64(ctx.r12.u32 + -8, ctx.f31.u64);
	// blr 
	return;
}

__attribute__((alias("__imp____savefpr_17"))) PPC_WEAK_FUNC(__savefpr_17);
PPC_FUNC_IMPL(__imp____savefpr_17) {
	PPC_FUNC_PROLOGUE();
	// stfd f17,-120(r12)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r12.u32 + -120, ctx.f17.u64);
	// stfd f18,-112(r12)
	PPC_STORE_U64(ctx.r12.u32 + -112, ctx.f18.u64);
	// stfd f19,-104(r12)
	PPC_STORE_U64(ctx.r12.u32 + -104, ctx.f19.u64);
	// stfd f20,-96(r12)
	PPC_STORE_U64(ctx.r12.u32 + -96, ctx.f20.u64);
	// stfd f21,-88(r12)
	PPC_STORE_U64(ctx.r12.u32 + -88, ctx.f21.u64);
	// stfd f22,-80(r12)
	PPC_STORE_U64(ctx.r12.u32 + -80, ctx.f22.u64);
	// stfd f23,-72(r12)
	PPC_STORE_U64(ctx.r12.u32 + -72, ctx.f23.u64);
	// stfd f24,-64(r12)
	PPC_STORE_U64(ctx.r12.u32 + -64, ctx.f24.u64);
	// stfd f25,-56(r12)
	PPC_STORE_U64(ctx.r12.u32 + -56, ctx.f25.u64);
	// stfd f26,-48(r12)
	PPC_STORE_U64(ctx.r12.u32 + -48, ctx.f26.u64);
	// stfd f27,-40(r12)
	PPC_STORE_U64(ctx.r12.u32 + -40, ctx.f27.u64);
	// stfd f28,-32(r12)
	PPC_STORE_U64(ctx.r12.u32 + -32, ctx.f28.u64);
	// stfd f29,-24(r12)
	PPC_STORE_U64(ctx.r12.u32 + -24, ctx.f29.u64);
	// stfd f30,-16(r12)
	PPC_STORE_U64(ctx.r12.u32 + -16, ctx.f30.u64);
	// stfd f31,-8(r12)
	PPC_STORE_U64(ctx.r12.u32 + -8, ctx.f31.u64);
	// blr 
	return;
}

__attribute__((alias("__imp____savefpr_18"))) PPC_WEAK_FUNC(__savefpr_18);
PPC_FUNC_IMPL(__imp____savefpr_18) {
	PPC_FUNC_PROLOGUE();
	// stfd f18,-112(r12)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r12.u32 + -112, ctx.f18.u64);
	// stfd f19,-104(r12)
	PPC_STORE_U64(ctx.r12.u32 + -104, ctx.f19.u64);
	// stfd f20,-96(r12)
	PPC_STORE_U64(ctx.r12.u32 + -96, ctx.f20.u64);
	// stfd f21,-88(r12)
	PPC_STORE_U64(ctx.r12.u32 + -88, ctx.f21.u64);
	// stfd f22,-80(r12)
	PPC_STORE_U64(ctx.r12.u32 + -80, ctx.f22.u64);
	// stfd f23,-72(r12)
	PPC_STORE_U64(ctx.r12.u32 + -72, ctx.f23.u64);
	// stfd f24,-64(r12)
	PPC_STORE_U64(ctx.r12.u32 + -64, ctx.f24.u64);
	// stfd f25,-56(r12)
	PPC_STORE_U64(ctx.r12.u32 + -56, ctx.f25.u64);
	// stfd f26,-48(r12)
	PPC_STORE_U64(ctx.r12.u32 + -48, ctx.f26.u64);
	// stfd f27,-40(r12)
	PPC_STORE_U64(ctx.r12.u32 + -40, ctx.f27.u64);
	// stfd f28,-32(r12)
	PPC_STORE_U64(ctx.r12.u32 + -32, ctx.f28.u64);
	// stfd f29,-24(r12)
	PPC_STORE_U64(ctx.r12.u32 + -24, ctx.f29.u64);
	// stfd f30,-16(r12)
	PPC_STORE_U64(ctx.r12.u32 + -16, ctx.f30.u64);
	// stfd f31,-8(r12)
	PPC_STORE_U64(ctx.r12.u32 + -8, ctx.f31.u64);
	// blr 
	return;
}

__attribute__((alias("__imp____savefpr_19"))) PPC_WEAK_FUNC(__savefpr_19);
PPC_FUNC_IMPL(__imp____savefpr_19) {
	PPC_FUNC_PROLOGUE();
	// stfd f19,-104(r12)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r12.u32 + -104, ctx.f19.u64);
	// stfd f20,-96(r12)
	PPC_STORE_U64(ctx.r12.u32 + -96, ctx.f20.u64);
	// stfd f21,-88(r12)
	PPC_STORE_U64(ctx.r12.u32 + -88, ctx.f21.u64);
	// stfd f22,-80(r12)
	PPC_STORE_U64(ctx.r12.u32 + -80, ctx.f22.u64);
	// stfd f23,-72(r12)
	PPC_STORE_U64(ctx.r12.u32 + -72, ctx.f23.u64);
	// stfd f24,-64(r12)
	PPC_STORE_U64(ctx.r12.u32 + -64, ctx.f24.u64);
	// stfd f25,-56(r12)
	PPC_STORE_U64(ctx.r12.u32 + -56, ctx.f25.u64);
	// stfd f26,-48(r12)
	PPC_STORE_U64(ctx.r12.u32 + -48, ctx.f26.u64);
	// stfd f27,-40(r12)
	PPC_STORE_U64(ctx.r12.u32 + -40, ctx.f27.u64);
	// stfd f28,-32(r12)
	PPC_STORE_U64(ctx.r12.u32 + -32, ctx.f28.u64);
	// stfd f29,-24(r12)
	PPC_STORE_U64(ctx.r12.u32 + -24, ctx.f29.u64);
	// stfd f30,-16(r12)
	PPC_STORE_U64(ctx.r12.u32 + -16, ctx.f30.u64);
	// stfd f31,-8(r12)
	PPC_STORE_U64(ctx.r12.u32 + -8, ctx.f31.u64);
	// blr 
	return;
}

__attribute__((alias("__imp____savefpr_20"))) PPC_WEAK_FUNC(__savefpr_20);
PPC_FUNC_IMPL(__imp____savefpr_20) {
	PPC_FUNC_PROLOGUE();
	// stfd f20,-96(r12)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r12.u32 + -96, ctx.f20.u64);
	// stfd f21,-88(r12)
	PPC_STORE_U64(ctx.r12.u32 + -88, ctx.f21.u64);
	// stfd f22,-80(r12)
	PPC_STORE_U64(ctx.r12.u32 + -80, ctx.f22.u64);
	// stfd f23,-72(r12)
	PPC_STORE_U64(ctx.r12.u32 + -72, ctx.f23.u64);
	// stfd f24,-64(r12)
	PPC_STORE_U64(ctx.r12.u32 + -64, ctx.f24.u64);
	// stfd f25,-56(r12)
	PPC_STORE_U64(ctx.r12.u32 + -56, ctx.f25.u64);
	// stfd f26,-48(r12)
	PPC_STORE_U64(ctx.r12.u32 + -48, ctx.f26.u64);
	// stfd f27,-40(r12)
	PPC_STORE_U64(ctx.r12.u32 + -40, ctx.f27.u64);
	// stfd f28,-32(r12)
	PPC_STORE_U64(ctx.r12.u32 + -32, ctx.f28.u64);
	// stfd f29,-24(r12)
	PPC_STORE_U64(ctx.r12.u32 + -24, ctx.f29.u64);
	// stfd f30,-16(r12)
	PPC_STORE_U64(ctx.r12.u32 + -16, ctx.f30.u64);
	// stfd f31,-8(r12)
	PPC_STORE_U64(ctx.r12.u32 + -8, ctx.f31.u64);
	// blr 
	return;
}

__attribute__((alias("__imp____savefpr_21"))) PPC_WEAK_FUNC(__savefpr_21);
PPC_FUNC_IMPL(__imp____savefpr_21) {
	PPC_FUNC_PROLOGUE();
	// stfd f21,-88(r12)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r12.u32 + -88, ctx.f21.u64);
	// stfd f22,-80(r12)
	PPC_STORE_U64(ctx.r12.u32 + -80, ctx.f22.u64);
	// stfd f23,-72(r12)
	PPC_STORE_U64(ctx.r12.u32 + -72, ctx.f23.u64);
	// stfd f24,-64(r12)
	PPC_STORE_U64(ctx.r12.u32 + -64, ctx.f24.u64);
	// stfd f25,-56(r12)
	PPC_STORE_U64(ctx.r12.u32 + -56, ctx.f25.u64);
	// stfd f26,-48(r12)
	PPC_STORE_U64(ctx.r12.u32 + -48, ctx.f26.u64);
	// stfd f27,-40(r12)
	PPC_STORE_U64(ctx.r12.u32 + -40, ctx.f27.u64);
	// stfd f28,-32(r12)
	PPC_STORE_U64(ctx.r12.u32 + -32, ctx.f28.u64);
	// stfd f29,-24(r12)
	PPC_STORE_U64(ctx.r12.u32 + -24, ctx.f29.u64);
	// stfd f30,-16(r12)
	PPC_STORE_U64(ctx.r12.u32 + -16, ctx.f30.u64);
	// stfd f31,-8(r12)
	PPC_STORE_U64(ctx.r12.u32 + -8, ctx.f31.u64);
	// blr 
	return;
}

__attribute__((alias("__imp____savefpr_22"))) PPC_WEAK_FUNC(__savefpr_22);
PPC_FUNC_IMPL(__imp____savefpr_22) {
	PPC_FUNC_PROLOGUE();
	// stfd f22,-80(r12)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r12.u32 + -80, ctx.f22.u64);
	// stfd f23,-72(r12)
	PPC_STORE_U64(ctx.r12.u32 + -72, ctx.f23.u64);
	// stfd f24,-64(r12)
	PPC_STORE_U64(ctx.r12.u32 + -64, ctx.f24.u64);
	// stfd f25,-56(r12)
	PPC_STORE_U64(ctx.r12.u32 + -56, ctx.f25.u64);
	// stfd f26,-48(r12)
	PPC_STORE_U64(ctx.r12.u32 + -48, ctx.f26.u64);
	// stfd f27,-40(r12)
	PPC_STORE_U64(ctx.r12.u32 + -40, ctx.f27.u64);
	// stfd f28,-32(r12)
	PPC_STORE_U64(ctx.r12.u32 + -32, ctx.f28.u64);
	// stfd f29,-24(r12)
	PPC_STORE_U64(ctx.r12.u32 + -24, ctx.f29.u64);
	// stfd f30,-16(r12)
	PPC_STORE_U64(ctx.r12.u32 + -16, ctx.f30.u64);
	// stfd f31,-8(r12)
	PPC_STORE_U64(ctx.r12.u32 + -8, ctx.f31.u64);
	// blr 
	return;
}

__attribute__((alias("__imp____savefpr_23"))) PPC_WEAK_FUNC(__savefpr_23);
PPC_FUNC_IMPL(__imp____savefpr_23) {
	PPC_FUNC_PROLOGUE();
	// stfd f23,-72(r12)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r12.u32 + -72, ctx.f23.u64);
	// stfd f24,-64(r12)
	PPC_STORE_U64(ctx.r12.u32 + -64, ctx.f24.u64);
	// stfd f25,-56(r12)
	PPC_STORE_U64(ctx.r12.u32 + -56, ctx.f25.u64);
	// stfd f26,-48(r12)
	PPC_STORE_U64(ctx.r12.u32 + -48, ctx.f26.u64);
	// stfd f27,-40(r12)
	PPC_STORE_U64(ctx.r12.u32 + -40, ctx.f27.u64);
	// stfd f28,-32(r12)
	PPC_STORE_U64(ctx.r12.u32 + -32, ctx.f28.u64);
	// stfd f29,-24(r12)
	PPC_STORE_U64(ctx.r12.u32 + -24, ctx.f29.u64);
	// stfd f30,-16(r12)
	PPC_STORE_U64(ctx.r12.u32 + -16, ctx.f30.u64);
	// stfd f31,-8(r12)
	PPC_STORE_U64(ctx.r12.u32 + -8, ctx.f31.u64);
	// blr 
	return;
}

__attribute__((alias("__imp____savefpr_24"))) PPC_WEAK_FUNC(__savefpr_24);
PPC_FUNC_IMPL(__imp____savefpr_24) {
	PPC_FUNC_PROLOGUE();
	// stfd f24,-64(r12)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r12.u32 + -64, ctx.f24.u64);
	// stfd f25,-56(r12)
	PPC_STORE_U64(ctx.r12.u32 + -56, ctx.f25.u64);
	// stfd f26,-48(r12)
	PPC_STORE_U64(ctx.r12.u32 + -48, ctx.f26.u64);
	// stfd f27,-40(r12)
	PPC_STORE_U64(ctx.r12.u32 + -40, ctx.f27.u64);
	// stfd f28,-32(r12)
	PPC_STORE_U64(ctx.r12.u32 + -32, ctx.f28.u64);
	// stfd f29,-24(r12)
	PPC_STORE_U64(ctx.r12.u32 + -24, ctx.f29.u64);
	// stfd f30,-16(r12)
	PPC_STORE_U64(ctx.r12.u32 + -16, ctx.f30.u64);
	// stfd f31,-8(r12)
	PPC_STORE_U64(ctx.r12.u32 + -8, ctx.f31.u64);
	// blr 
	return;
}

__attribute__((alias("__imp____savefpr_25"))) PPC_WEAK_FUNC(__savefpr_25);
PPC_FUNC_IMPL(__imp____savefpr_25) {
	PPC_FUNC_PROLOGUE();
	// stfd f25,-56(r12)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r12.u32 + -56, ctx.f25.u64);
	// stfd f26,-48(r12)
	PPC_STORE_U64(ctx.r12.u32 + -48, ctx.f26.u64);
	// stfd f27,-40(r12)
	PPC_STORE_U64(ctx.r12.u32 + -40, ctx.f27.u64);
	// stfd f28,-32(r12)
	PPC_STORE_U64(ctx.r12.u32 + -32, ctx.f28.u64);
	// stfd f29,-24(r12)
	PPC_STORE_U64(ctx.r12.u32 + -24, ctx.f29.u64);
	// stfd f30,-16(r12)
	PPC_STORE_U64(ctx.r12.u32 + -16, ctx.f30.u64);
	// stfd f31,-8(r12)
	PPC_STORE_U64(ctx.r12.u32 + -8, ctx.f31.u64);
	// blr 
	return;
}

__attribute__((alias("__imp____savefpr_26"))) PPC_WEAK_FUNC(__savefpr_26);
PPC_FUNC_IMPL(__imp____savefpr_26) {
	PPC_FUNC_PROLOGUE();
	// stfd f26,-48(r12)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r12.u32 + -48, ctx.f26.u64);
	// stfd f27,-40(r12)
	PPC_STORE_U64(ctx.r12.u32 + -40, ctx.f27.u64);
	// stfd f28,-32(r12)
	PPC_STORE_U64(ctx.r12.u32 + -32, ctx.f28.u64);
	// stfd f29,-24(r12)
	PPC_STORE_U64(ctx.r12.u32 + -24, ctx.f29.u64);
	// stfd f30,-16(r12)
	PPC_STORE_U64(ctx.r12.u32 + -16, ctx.f30.u64);
	// stfd f31,-8(r12)
	PPC_STORE_U64(ctx.r12.u32 + -8, ctx.f31.u64);
	// blr 
	return;
}

__attribute__((alias("__imp____savefpr_27"))) PPC_WEAK_FUNC(__savefpr_27);
PPC_FUNC_IMPL(__imp____savefpr_27) {
	PPC_FUNC_PROLOGUE();
	// stfd f27,-40(r12)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r12.u32 + -40, ctx.f27.u64);
	// stfd f28,-32(r12)
	PPC_STORE_U64(ctx.r12.u32 + -32, ctx.f28.u64);
	// stfd f29,-24(r12)
	PPC_STORE_U64(ctx.r12.u32 + -24, ctx.f29.u64);
	// stfd f30,-16(r12)
	PPC_STORE_U64(ctx.r12.u32 + -16, ctx.f30.u64);
	// stfd f31,-8(r12)
	PPC_STORE_U64(ctx.r12.u32 + -8, ctx.f31.u64);
	// blr 
	return;
}

__attribute__((alias("__imp____savefpr_28"))) PPC_WEAK_FUNC(__savefpr_28);
PPC_FUNC_IMPL(__imp____savefpr_28) {
	PPC_FUNC_PROLOGUE();
	// stfd f28,-32(r12)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r12.u32 + -32, ctx.f28.u64);
	// stfd f29,-24(r12)
	PPC_STORE_U64(ctx.r12.u32 + -24, ctx.f29.u64);
	// stfd f30,-16(r12)
	PPC_STORE_U64(ctx.r12.u32 + -16, ctx.f30.u64);
	// stfd f31,-8(r12)
	PPC_STORE_U64(ctx.r12.u32 + -8, ctx.f31.u64);
	// blr 
	return;
}

__attribute__((alias("__imp____savefpr_29"))) PPC_WEAK_FUNC(__savefpr_29);
PPC_FUNC_IMPL(__imp____savefpr_29) {
	PPC_FUNC_PROLOGUE();
	// stfd f29,-24(r12)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r12.u32 + -24, ctx.f29.u64);
	// stfd f30,-16(r12)
	PPC_STORE_U64(ctx.r12.u32 + -16, ctx.f30.u64);
	// stfd f31,-8(r12)
	PPC_STORE_U64(ctx.r12.u32 + -8, ctx.f31.u64);
	// blr 
	return;
}

__attribute__((alias("__imp____savefpr_30"))) PPC_WEAK_FUNC(__savefpr_30);
PPC_FUNC_IMPL(__imp____savefpr_30) {
	PPC_FUNC_PROLOGUE();
	// stfd f30,-16(r12)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r12.u32 + -16, ctx.f30.u64);
	// stfd f31,-8(r12)
	PPC_STORE_U64(ctx.r12.u32 + -8, ctx.f31.u64);
	// blr 
	return;
}

__attribute__((alias("__imp____savefpr_31"))) PPC_WEAK_FUNC(__savefpr_31);
PPC_FUNC_IMPL(__imp____savefpr_31) {
	PPC_FUNC_PROLOGUE();
	// stfd f31,-8(r12)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r12.u32 + -8, ctx.f31.u64);
	// blr 
	return;
}

__attribute__((alias("__imp____restfpr_14"))) PPC_WEAK_FUNC(__restfpr_14);
PPC_FUNC_IMPL(__imp____restfpr_14) {
	PPC_FUNC_PROLOGUE();
	// lfd f14,-144(r12)
	ctx.fpscr.disableFlushMode();
	ctx.f14.u64 = PPC_LOAD_U64(ctx.r12.u32 + -144);
	// lfd f15,-136(r12)
	ctx.f15.u64 = PPC_LOAD_U64(ctx.r12.u32 + -136);
	// lfd f16,-128(r12)
	ctx.f16.u64 = PPC_LOAD_U64(ctx.r12.u32 + -128);
	// lfd f17,-120(r12)
	ctx.f17.u64 = PPC_LOAD_U64(ctx.r12.u32 + -120);
	// lfd f18,-112(r12)
	ctx.f18.u64 = PPC_LOAD_U64(ctx.r12.u32 + -112);
	// lfd f19,-104(r12)
	ctx.f19.u64 = PPC_LOAD_U64(ctx.r12.u32 + -104);
	// lfd f20,-96(r12)
	ctx.f20.u64 = PPC_LOAD_U64(ctx.r12.u32 + -96);
	// lfd f21,-88(r12)
	ctx.f21.u64 = PPC_LOAD_U64(ctx.r12.u32 + -88);
	// lfd f22,-80(r12)
	ctx.f22.u64 = PPC_LOAD_U64(ctx.r12.u32 + -80);
	// lfd f23,-72(r12)
	ctx.f23.u64 = PPC_LOAD_U64(ctx.r12.u32 + -72);
	// lfd f24,-64(r12)
	ctx.f24.u64 = PPC_LOAD_U64(ctx.r12.u32 + -64);
	// lfd f25,-56(r12)
	ctx.f25.u64 = PPC_LOAD_U64(ctx.r12.u32 + -56);
	// lfd f26,-48(r12)
	ctx.f26.u64 = PPC_LOAD_U64(ctx.r12.u32 + -48);
	// lfd f27,-40(r12)
	ctx.f27.u64 = PPC_LOAD_U64(ctx.r12.u32 + -40);
	// lfd f28,-32(r12)
	ctx.f28.u64 = PPC_LOAD_U64(ctx.r12.u32 + -32);
	// lfd f29,-24(r12)
	ctx.f29.u64 = PPC_LOAD_U64(ctx.r12.u32 + -24);
	// lfd f30,-16(r12)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r12.u32 + -16);
	// lfd f31,-8(r12)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r12.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp____restfpr_15"))) PPC_WEAK_FUNC(__restfpr_15);
PPC_FUNC_IMPL(__imp____restfpr_15) {
	PPC_FUNC_PROLOGUE();
	// lfd f15,-136(r12)
	ctx.fpscr.disableFlushMode();
	ctx.f15.u64 = PPC_LOAD_U64(ctx.r12.u32 + -136);
	// lfd f16,-128(r12)
	ctx.f16.u64 = PPC_LOAD_U64(ctx.r12.u32 + -128);
	// lfd f17,-120(r12)
	ctx.f17.u64 = PPC_LOAD_U64(ctx.r12.u32 + -120);
	// lfd f18,-112(r12)
	ctx.f18.u64 = PPC_LOAD_U64(ctx.r12.u32 + -112);
	// lfd f19,-104(r12)
	ctx.f19.u64 = PPC_LOAD_U64(ctx.r12.u32 + -104);
	// lfd f20,-96(r12)
	ctx.f20.u64 = PPC_LOAD_U64(ctx.r12.u32 + -96);
	// lfd f21,-88(r12)
	ctx.f21.u64 = PPC_LOAD_U64(ctx.r12.u32 + -88);
	// lfd f22,-80(r12)
	ctx.f22.u64 = PPC_LOAD_U64(ctx.r12.u32 + -80);
	// lfd f23,-72(r12)
	ctx.f23.u64 = PPC_LOAD_U64(ctx.r12.u32 + -72);
	// lfd f24,-64(r12)
	ctx.f24.u64 = PPC_LOAD_U64(ctx.r12.u32 + -64);
	// lfd f25,-56(r12)
	ctx.f25.u64 = PPC_LOAD_U64(ctx.r12.u32 + -56);
	// lfd f26,-48(r12)
	ctx.f26.u64 = PPC_LOAD_U64(ctx.r12.u32 + -48);
	// lfd f27,-40(r12)
	ctx.f27.u64 = PPC_LOAD_U64(ctx.r12.u32 + -40);
	// lfd f28,-32(r12)
	ctx.f28.u64 = PPC_LOAD_U64(ctx.r12.u32 + -32);
	// lfd f29,-24(r12)
	ctx.f29.u64 = PPC_LOAD_U64(ctx.r12.u32 + -24);
	// lfd f30,-16(r12)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r12.u32 + -16);
	// lfd f31,-8(r12)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r12.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp____restfpr_16"))) PPC_WEAK_FUNC(__restfpr_16);
PPC_FUNC_IMPL(__imp____restfpr_16) {
	PPC_FUNC_PROLOGUE();
	// lfd f16,-128(r12)
	ctx.fpscr.disableFlushMode();
	ctx.f16.u64 = PPC_LOAD_U64(ctx.r12.u32 + -128);
	// lfd f17,-120(r12)
	ctx.f17.u64 = PPC_LOAD_U64(ctx.r12.u32 + -120);
	// lfd f18,-112(r12)
	ctx.f18.u64 = PPC_LOAD_U64(ctx.r12.u32 + -112);
	// lfd f19,-104(r12)
	ctx.f19.u64 = PPC_LOAD_U64(ctx.r12.u32 + -104);
	// lfd f20,-96(r12)
	ctx.f20.u64 = PPC_LOAD_U64(ctx.r12.u32 + -96);
	// lfd f21,-88(r12)
	ctx.f21.u64 = PPC_LOAD_U64(ctx.r12.u32 + -88);
	// lfd f22,-80(r12)
	ctx.f22.u64 = PPC_LOAD_U64(ctx.r12.u32 + -80);
	// lfd f23,-72(r12)
	ctx.f23.u64 = PPC_LOAD_U64(ctx.r12.u32 + -72);
	// lfd f24,-64(r12)
	ctx.f24.u64 = PPC_LOAD_U64(ctx.r12.u32 + -64);
	// lfd f25,-56(r12)
	ctx.f25.u64 = PPC_LOAD_U64(ctx.r12.u32 + -56);
	// lfd f26,-48(r12)
	ctx.f26.u64 = PPC_LOAD_U64(ctx.r12.u32 + -48);
	// lfd f27,-40(r12)
	ctx.f27.u64 = PPC_LOAD_U64(ctx.r12.u32 + -40);
	// lfd f28,-32(r12)
	ctx.f28.u64 = PPC_LOAD_U64(ctx.r12.u32 + -32);
	// lfd f29,-24(r12)
	ctx.f29.u64 = PPC_LOAD_U64(ctx.r12.u32 + -24);
	// lfd f30,-16(r12)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r12.u32 + -16);
	// lfd f31,-8(r12)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r12.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp____restfpr_17"))) PPC_WEAK_FUNC(__restfpr_17);
PPC_FUNC_IMPL(__imp____restfpr_17) {
	PPC_FUNC_PROLOGUE();
	// lfd f17,-120(r12)
	ctx.fpscr.disableFlushMode();
	ctx.f17.u64 = PPC_LOAD_U64(ctx.r12.u32 + -120);
	// lfd f18,-112(r12)
	ctx.f18.u64 = PPC_LOAD_U64(ctx.r12.u32 + -112);
	// lfd f19,-104(r12)
	ctx.f19.u64 = PPC_LOAD_U64(ctx.r12.u32 + -104);
	// lfd f20,-96(r12)
	ctx.f20.u64 = PPC_LOAD_U64(ctx.r12.u32 + -96);
	// lfd f21,-88(r12)
	ctx.f21.u64 = PPC_LOAD_U64(ctx.r12.u32 + -88);
	// lfd f22,-80(r12)
	ctx.f22.u64 = PPC_LOAD_U64(ctx.r12.u32 + -80);
	// lfd f23,-72(r12)
	ctx.f23.u64 = PPC_LOAD_U64(ctx.r12.u32 + -72);
	// lfd f24,-64(r12)
	ctx.f24.u64 = PPC_LOAD_U64(ctx.r12.u32 + -64);
	// lfd f25,-56(r12)
	ctx.f25.u64 = PPC_LOAD_U64(ctx.r12.u32 + -56);
	// lfd f26,-48(r12)
	ctx.f26.u64 = PPC_LOAD_U64(ctx.r12.u32 + -48);
	// lfd f27,-40(r12)
	ctx.f27.u64 = PPC_LOAD_U64(ctx.r12.u32 + -40);
	// lfd f28,-32(r12)
	ctx.f28.u64 = PPC_LOAD_U64(ctx.r12.u32 + -32);
	// lfd f29,-24(r12)
	ctx.f29.u64 = PPC_LOAD_U64(ctx.r12.u32 + -24);
	// lfd f30,-16(r12)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r12.u32 + -16);
	// lfd f31,-8(r12)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r12.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp____restfpr_18"))) PPC_WEAK_FUNC(__restfpr_18);
PPC_FUNC_IMPL(__imp____restfpr_18) {
	PPC_FUNC_PROLOGUE();
	// lfd f18,-112(r12)
	ctx.fpscr.disableFlushMode();
	ctx.f18.u64 = PPC_LOAD_U64(ctx.r12.u32 + -112);
	// lfd f19,-104(r12)
	ctx.f19.u64 = PPC_LOAD_U64(ctx.r12.u32 + -104);
	// lfd f20,-96(r12)
	ctx.f20.u64 = PPC_LOAD_U64(ctx.r12.u32 + -96);
	// lfd f21,-88(r12)
	ctx.f21.u64 = PPC_LOAD_U64(ctx.r12.u32 + -88);
	// lfd f22,-80(r12)
	ctx.f22.u64 = PPC_LOAD_U64(ctx.r12.u32 + -80);
	// lfd f23,-72(r12)
	ctx.f23.u64 = PPC_LOAD_U64(ctx.r12.u32 + -72);
	// lfd f24,-64(r12)
	ctx.f24.u64 = PPC_LOAD_U64(ctx.r12.u32 + -64);
	// lfd f25,-56(r12)
	ctx.f25.u64 = PPC_LOAD_U64(ctx.r12.u32 + -56);
	// lfd f26,-48(r12)
	ctx.f26.u64 = PPC_LOAD_U64(ctx.r12.u32 + -48);
	// lfd f27,-40(r12)
	ctx.f27.u64 = PPC_LOAD_U64(ctx.r12.u32 + -40);
	// lfd f28,-32(r12)
	ctx.f28.u64 = PPC_LOAD_U64(ctx.r12.u32 + -32);
	// lfd f29,-24(r12)
	ctx.f29.u64 = PPC_LOAD_U64(ctx.r12.u32 + -24);
	// lfd f30,-16(r12)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r12.u32 + -16);
	// lfd f31,-8(r12)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r12.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp____restfpr_19"))) PPC_WEAK_FUNC(__restfpr_19);
PPC_FUNC_IMPL(__imp____restfpr_19) {
	PPC_FUNC_PROLOGUE();
	// lfd f19,-104(r12)
	ctx.fpscr.disableFlushMode();
	ctx.f19.u64 = PPC_LOAD_U64(ctx.r12.u32 + -104);
	// lfd f20,-96(r12)
	ctx.f20.u64 = PPC_LOAD_U64(ctx.r12.u32 + -96);
	// lfd f21,-88(r12)
	ctx.f21.u64 = PPC_LOAD_U64(ctx.r12.u32 + -88);
	// lfd f22,-80(r12)
	ctx.f22.u64 = PPC_LOAD_U64(ctx.r12.u32 + -80);
	// lfd f23,-72(r12)
	ctx.f23.u64 = PPC_LOAD_U64(ctx.r12.u32 + -72);
	// lfd f24,-64(r12)
	ctx.f24.u64 = PPC_LOAD_U64(ctx.r12.u32 + -64);
	// lfd f25,-56(r12)
	ctx.f25.u64 = PPC_LOAD_U64(ctx.r12.u32 + -56);
	// lfd f26,-48(r12)
	ctx.f26.u64 = PPC_LOAD_U64(ctx.r12.u32 + -48);
	// lfd f27,-40(r12)
	ctx.f27.u64 = PPC_LOAD_U64(ctx.r12.u32 + -40);
	// lfd f28,-32(r12)
	ctx.f28.u64 = PPC_LOAD_U64(ctx.r12.u32 + -32);
	// lfd f29,-24(r12)
	ctx.f29.u64 = PPC_LOAD_U64(ctx.r12.u32 + -24);
	// lfd f30,-16(r12)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r12.u32 + -16);
	// lfd f31,-8(r12)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r12.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp____restfpr_20"))) PPC_WEAK_FUNC(__restfpr_20);
PPC_FUNC_IMPL(__imp____restfpr_20) {
	PPC_FUNC_PROLOGUE();
	// lfd f20,-96(r12)
	ctx.fpscr.disableFlushMode();
	ctx.f20.u64 = PPC_LOAD_U64(ctx.r12.u32 + -96);
	// lfd f21,-88(r12)
	ctx.f21.u64 = PPC_LOAD_U64(ctx.r12.u32 + -88);
	// lfd f22,-80(r12)
	ctx.f22.u64 = PPC_LOAD_U64(ctx.r12.u32 + -80);
	// lfd f23,-72(r12)
	ctx.f23.u64 = PPC_LOAD_U64(ctx.r12.u32 + -72);
	// lfd f24,-64(r12)
	ctx.f24.u64 = PPC_LOAD_U64(ctx.r12.u32 + -64);
	// lfd f25,-56(r12)
	ctx.f25.u64 = PPC_LOAD_U64(ctx.r12.u32 + -56);
	// lfd f26,-48(r12)
	ctx.f26.u64 = PPC_LOAD_U64(ctx.r12.u32 + -48);
	// lfd f27,-40(r12)
	ctx.f27.u64 = PPC_LOAD_U64(ctx.r12.u32 + -40);
	// lfd f28,-32(r12)
	ctx.f28.u64 = PPC_LOAD_U64(ctx.r12.u32 + -32);
	// lfd f29,-24(r12)
	ctx.f29.u64 = PPC_LOAD_U64(ctx.r12.u32 + -24);
	// lfd f30,-16(r12)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r12.u32 + -16);
	// lfd f31,-8(r12)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r12.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp____restfpr_21"))) PPC_WEAK_FUNC(__restfpr_21);
PPC_FUNC_IMPL(__imp____restfpr_21) {
	PPC_FUNC_PROLOGUE();
	// lfd f21,-88(r12)
	ctx.fpscr.disableFlushMode();
	ctx.f21.u64 = PPC_LOAD_U64(ctx.r12.u32 + -88);
	// lfd f22,-80(r12)
	ctx.f22.u64 = PPC_LOAD_U64(ctx.r12.u32 + -80);
	// lfd f23,-72(r12)
	ctx.f23.u64 = PPC_LOAD_U64(ctx.r12.u32 + -72);
	// lfd f24,-64(r12)
	ctx.f24.u64 = PPC_LOAD_U64(ctx.r12.u32 + -64);
	// lfd f25,-56(r12)
	ctx.f25.u64 = PPC_LOAD_U64(ctx.r12.u32 + -56);
	// lfd f26,-48(r12)
	ctx.f26.u64 = PPC_LOAD_U64(ctx.r12.u32 + -48);
	// lfd f27,-40(r12)
	ctx.f27.u64 = PPC_LOAD_U64(ctx.r12.u32 + -40);
	// lfd f28,-32(r12)
	ctx.f28.u64 = PPC_LOAD_U64(ctx.r12.u32 + -32);
	// lfd f29,-24(r12)
	ctx.f29.u64 = PPC_LOAD_U64(ctx.r12.u32 + -24);
	// lfd f30,-16(r12)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r12.u32 + -16);
	// lfd f31,-8(r12)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r12.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp____restfpr_22"))) PPC_WEAK_FUNC(__restfpr_22);
PPC_FUNC_IMPL(__imp____restfpr_22) {
	PPC_FUNC_PROLOGUE();
	// lfd f22,-80(r12)
	ctx.fpscr.disableFlushMode();
	ctx.f22.u64 = PPC_LOAD_U64(ctx.r12.u32 + -80);
	// lfd f23,-72(r12)
	ctx.f23.u64 = PPC_LOAD_U64(ctx.r12.u32 + -72);
	// lfd f24,-64(r12)
	ctx.f24.u64 = PPC_LOAD_U64(ctx.r12.u32 + -64);
	// lfd f25,-56(r12)
	ctx.f25.u64 = PPC_LOAD_U64(ctx.r12.u32 + -56);
	// lfd f26,-48(r12)
	ctx.f26.u64 = PPC_LOAD_U64(ctx.r12.u32 + -48);
	// lfd f27,-40(r12)
	ctx.f27.u64 = PPC_LOAD_U64(ctx.r12.u32 + -40);
	// lfd f28,-32(r12)
	ctx.f28.u64 = PPC_LOAD_U64(ctx.r12.u32 + -32);
	// lfd f29,-24(r12)
	ctx.f29.u64 = PPC_LOAD_U64(ctx.r12.u32 + -24);
	// lfd f30,-16(r12)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r12.u32 + -16);
	// lfd f31,-8(r12)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r12.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp____restfpr_23"))) PPC_WEAK_FUNC(__restfpr_23);
PPC_FUNC_IMPL(__imp____restfpr_23) {
	PPC_FUNC_PROLOGUE();
	// lfd f23,-72(r12)
	ctx.fpscr.disableFlushMode();
	ctx.f23.u64 = PPC_LOAD_U64(ctx.r12.u32 + -72);
	// lfd f24,-64(r12)
	ctx.f24.u64 = PPC_LOAD_U64(ctx.r12.u32 + -64);
	// lfd f25,-56(r12)
	ctx.f25.u64 = PPC_LOAD_U64(ctx.r12.u32 + -56);
	// lfd f26,-48(r12)
	ctx.f26.u64 = PPC_LOAD_U64(ctx.r12.u32 + -48);
	// lfd f27,-40(r12)
	ctx.f27.u64 = PPC_LOAD_U64(ctx.r12.u32 + -40);
	// lfd f28,-32(r12)
	ctx.f28.u64 = PPC_LOAD_U64(ctx.r12.u32 + -32);
	// lfd f29,-24(r12)
	ctx.f29.u64 = PPC_LOAD_U64(ctx.r12.u32 + -24);
	// lfd f30,-16(r12)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r12.u32 + -16);
	// lfd f31,-8(r12)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r12.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp____restfpr_24"))) PPC_WEAK_FUNC(__restfpr_24);
PPC_FUNC_IMPL(__imp____restfpr_24) {
	PPC_FUNC_PROLOGUE();
	// lfd f24,-64(r12)
	ctx.fpscr.disableFlushMode();
	ctx.f24.u64 = PPC_LOAD_U64(ctx.r12.u32 + -64);
	// lfd f25,-56(r12)
	ctx.f25.u64 = PPC_LOAD_U64(ctx.r12.u32 + -56);
	// lfd f26,-48(r12)
	ctx.f26.u64 = PPC_LOAD_U64(ctx.r12.u32 + -48);
	// lfd f27,-40(r12)
	ctx.f27.u64 = PPC_LOAD_U64(ctx.r12.u32 + -40);
	// lfd f28,-32(r12)
	ctx.f28.u64 = PPC_LOAD_U64(ctx.r12.u32 + -32);
	// lfd f29,-24(r12)
	ctx.f29.u64 = PPC_LOAD_U64(ctx.r12.u32 + -24);
	// lfd f30,-16(r12)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r12.u32 + -16);
	// lfd f31,-8(r12)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r12.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp____restfpr_25"))) PPC_WEAK_FUNC(__restfpr_25);
PPC_FUNC_IMPL(__imp____restfpr_25) {
	PPC_FUNC_PROLOGUE();
	// lfd f25,-56(r12)
	ctx.fpscr.disableFlushMode();
	ctx.f25.u64 = PPC_LOAD_U64(ctx.r12.u32 + -56);
	// lfd f26,-48(r12)
	ctx.f26.u64 = PPC_LOAD_U64(ctx.r12.u32 + -48);
	// lfd f27,-40(r12)
	ctx.f27.u64 = PPC_LOAD_U64(ctx.r12.u32 + -40);
	// lfd f28,-32(r12)
	ctx.f28.u64 = PPC_LOAD_U64(ctx.r12.u32 + -32);
	// lfd f29,-24(r12)
	ctx.f29.u64 = PPC_LOAD_U64(ctx.r12.u32 + -24);
	// lfd f30,-16(r12)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r12.u32 + -16);
	// lfd f31,-8(r12)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r12.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp____restfpr_26"))) PPC_WEAK_FUNC(__restfpr_26);
PPC_FUNC_IMPL(__imp____restfpr_26) {
	PPC_FUNC_PROLOGUE();
	// lfd f26,-48(r12)
	ctx.fpscr.disableFlushMode();
	ctx.f26.u64 = PPC_LOAD_U64(ctx.r12.u32 + -48);
	// lfd f27,-40(r12)
	ctx.f27.u64 = PPC_LOAD_U64(ctx.r12.u32 + -40);
	// lfd f28,-32(r12)
	ctx.f28.u64 = PPC_LOAD_U64(ctx.r12.u32 + -32);
	// lfd f29,-24(r12)
	ctx.f29.u64 = PPC_LOAD_U64(ctx.r12.u32 + -24);
	// lfd f30,-16(r12)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r12.u32 + -16);
	// lfd f31,-8(r12)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r12.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp____restfpr_27"))) PPC_WEAK_FUNC(__restfpr_27);
PPC_FUNC_IMPL(__imp____restfpr_27) {
	PPC_FUNC_PROLOGUE();
	// lfd f27,-40(r12)
	ctx.fpscr.disableFlushMode();
	ctx.f27.u64 = PPC_LOAD_U64(ctx.r12.u32 + -40);
	// lfd f28,-32(r12)
	ctx.f28.u64 = PPC_LOAD_U64(ctx.r12.u32 + -32);
	// lfd f29,-24(r12)
	ctx.f29.u64 = PPC_LOAD_U64(ctx.r12.u32 + -24);
	// lfd f30,-16(r12)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r12.u32 + -16);
	// lfd f31,-8(r12)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r12.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp____restfpr_28"))) PPC_WEAK_FUNC(__restfpr_28);
PPC_FUNC_IMPL(__imp____restfpr_28) {
	PPC_FUNC_PROLOGUE();
	// lfd f28,-32(r12)
	ctx.fpscr.disableFlushMode();
	ctx.f28.u64 = PPC_LOAD_U64(ctx.r12.u32 + -32);
	// lfd f29,-24(r12)
	ctx.f29.u64 = PPC_LOAD_U64(ctx.r12.u32 + -24);
	// lfd f30,-16(r12)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r12.u32 + -16);
	// lfd f31,-8(r12)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r12.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp____restfpr_29"))) PPC_WEAK_FUNC(__restfpr_29);
PPC_FUNC_IMPL(__imp____restfpr_29) {
	PPC_FUNC_PROLOGUE();
	// lfd f29,-24(r12)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = PPC_LOAD_U64(ctx.r12.u32 + -24);
	// lfd f30,-16(r12)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r12.u32 + -16);
	// lfd f31,-8(r12)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r12.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp____restfpr_30"))) PPC_WEAK_FUNC(__restfpr_30);
PPC_FUNC_IMPL(__imp____restfpr_30) {
	PPC_FUNC_PROLOGUE();
	// lfd f30,-16(r12)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r12.u32 + -16);
	// lfd f31,-8(r12)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r12.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp____restfpr_31"))) PPC_WEAK_FUNC(__restfpr_31);
PPC_FUNC_IMPL(__imp____restfpr_31) {
	PPC_FUNC_PROLOGUE();
	// lfd f31,-8(r12)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r12.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820803C8"))) PPC_WEAK_FUNC(sub_820803C8);
PPC_FUNC_IMPL(__imp__sub_820803C8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820803D0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x820809e8
	ctx.lr = 0x820803DC;
	sub_820809E8(ctx, base);
	// bl 0x820d9438
	ctx.lr = 0x820803E0;
	sub_820D9438(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82080494
	if (ctx.cr0.eq) goto loc_82080494;
	// bl 0x8207c2b8
	ctx.lr = 0x820803EC;
	sub_8207C2B8(ctx, base);
	// addi r11,r3,32
	ctx.r11.s64 = ctx.r3.s64 + 32;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82080400
	if (!ctx.cr6.eq) goto loc_82080400;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x82080414
	goto loc_82080414;
loc_82080400:
	// bl 0x8207c2b8
	ctx.lr = 0x82080404;
	sub_8207C2B8(ctx, base);
	// addi r11,r3,64
	ctx.r11.s64 = ctx.r3.s64 + 64;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82080494
	if (!ctx.cr6.eq) goto loc_82080494;
	// li r10,1
	ctx.r10.s64 = 1;
loc_82080414:
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// lwz r11,-12296(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12296);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-12296(r9)
	PPC_STORE_U32(ctx.r9.u32 + -12296, ctx.r11.u32);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// andi. r11,r11,268
	ctx.r11.u64 = ctx.r11.u64 & 268;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82080494
	if (!ctx.cr0.eq) goto loc_82080494;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// rlwinm r29,r10,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r30,r11,-11856
	ctx.r30.s64 = ctx.r11.s64 + -11856;
	// lwzx r11,r29,r30
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r30.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8208046c
	if (!ctx.cr6.eq) goto loc_8208046C;
	// li r3,4096
	ctx.r3.s64 = 4096;
	// bl 0x8207a400
	ctx.lr = 0x82080454;
	sub_8207A400(ctx, base);
	// mr. r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stwx r11,r29,r30
	PPC_STORE_U32(ctx.r29.u32 + ctx.r30.u32, ctx.r11.u32);
	// bne 0x8208046c
	if (!ctx.cr0.eq) goto loc_8208046C;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r11,r31,20
	ctx.r11.s64 = ctx.r31.s64 + 20;
	// b 0x82080470
	goto loc_82080470;
loc_8208046C:
	// li r10,4096
	ctx.r10.s64 = 4096;
loc_82080470:
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// ori r11,r11,4354
	ctx.r11.u64 = ctx.r11.u64 | 4354;
	// stw r10,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// b 0x82080498
	goto loc_82080498;
loc_82080494:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82080498:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820804A0"))) PPC_WEAK_FUNC(sub_820804A0);
PPC_FUNC_IMPL(__imp__sub_820804A0) {
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
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820804f0
	if (ctx.cr6.eq) goto loc_820804F0;
	// lwz r11,12(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// rlwinm. r11,r11,0,19,19
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x1000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820804f0
	if (ctx.cr0.eq) goto loc_820804F0;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x8207c558
	ctx.lr = 0x820804D0;
	sub_8207C558(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// rlwinm r11,r11,0,24,22
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFEFF;
	// rlwinm r11,r11,0,20,18
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFEFFF;
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_820804F0:
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

__attribute__((alias("__imp__sub_82080504"))) PPC_WEAK_FUNC(sub_82080504);
PPC_FUNC_IMPL(__imp__sub_82080504) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82080508"))) PPC_WEAK_FUNC(sub_82080508);
PPC_FUNC_IMPL(__imp__sub_82080508) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8208050C"))) PPC_WEAK_FUNC(sub_8208050C);
PPC_FUNC_IMPL(__imp__sub_8208050C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82080510"))) PPC_WEAK_FUNC(sub_82080510);
PPC_FUNC_IMPL(__imp__sub_82080510) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r31,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.r31.u64);
	// mflr r31
	ctx.r31.u64 = ctx.lr;
	// stwu r1,-80(r1)
	ea = -80 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821d53d4
	ctx.lr = 0x82080528;
	__imp__RtlUnwind(ctx, base);
	// mtlr r31
	ctx.lr = ctx.r31.u64;
	// ld r31,8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + 8);
	// addi r1,r1,80
	ctx.r1.s64 = ctx.r1.s64 + 80;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82080538"))) PPC_WEAK_FUNC(sub_82080538);
PPC_FUNC_IMPL(__imp__sub_82080538) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x82080540;
	__savegprlr_24(ctx, base);
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// mr r24,r5
	ctx.r24.u64 = ctx.r5.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82080590
	if (ctx.cr6.eq) goto loc_82080590;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82080590
	if (ctx.cr6.eq) goto loc_82080590;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne cr6,0x8208059c
	if (!ctx.cr6.eq) goto loc_8208059C;
loc_8208056C:
	// bl 0x8207d4d8
	ctx.lr = 0x82080570;
	sub_8207D4D8(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d940
	ctx.lr = 0x82080590;
	sub_8207D940(ctx, base);
loc_82080590:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82080594:
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
loc_8208059C:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8208056c
	if (ctx.cr6.eq) goto loc_8208056C;
	// li r11,-1
	ctx.r11.s64 = -1;
	// twllei r25,0
	// divwu r11,r11,r25
	ctx.r11.u32 = ppc_divwu(ctx.r11.u32, ctx.r25.u32);
	// cmplw cr6,r24,r11
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8208056c
	if (ctx.cr6.gt) goto loc_8208056C;
	// mullw r27,r25,r24
	ctx.r27.s64 = int64_t(ctx.r25.s32) * int64_t(ctx.r24.s32);
	// mr r31,r27
	ctx.r31.u64 = ctx.r27.u64;
	// bl 0x8207c2b8
	ctx.lr = 0x820805C4;
	sub_8207C2B8(ctx, base);
	// addi r11,r3,32
	ctx.r11.s64 = ctx.r3.s64 + 32;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82080764
	if (ctx.cr6.eq) goto loc_82080764;
	// bl 0x8207c2b8
	ctx.lr = 0x820805D4;
	sub_8207C2B8(ctx, base);
	// addi r11,r3,64
	ctx.r11.s64 = ctx.r3.s64 + 64;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82080764
	if (ctx.cr6.eq) goto loc_82080764;
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// andi. r11,r11,268
	ctx.r11.u64 = ctx.r11.u64 & 268;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820805f8
	if (ctx.cr0.eq) goto loc_820805F8;
	// lwz r26,24(r30)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// b 0x820805fc
	goto loc_820805FC;
loc_820805F8:
	// li r26,4096
	ctx.r26.s64 = 4096;
loc_820805FC:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x820807a8
	if (ctx.cr6.eq) goto loc_820807A8;
loc_82080604:
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// andi. r10,r11,264
	ctx.r10.u64 = ctx.r11.u64 & 264;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// cmpwi r10,0
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82080664
	if (ctx.cr0.eq) goto loc_82080664;
	// lwz r29,4(r30)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x82080664
	if (ctx.cr6.eq) goto loc_82080664;
	// blt cr6,0x82080740
	if (ctx.cr6.lt) goto loc_82080740;
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// bge cr6,0x82080630
	if (!ctx.cr6.lt) goto loc_82080630;
	// mr r29,r31
	ctx.r29.u64 = ctx.r31.u64;
loc_82080630:
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x8207dac0
	ctx.lr = 0x82080640;
	sub_8207DAC0(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// subf r31,r29,r31
	ctx.r31.s64 = ctx.r31.s64 - ctx.r29.s64;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// add r28,r29,r28
	ctx.r28.u64 = ctx.r29.u64 + ctx.r28.u64;
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// subf r11,r29,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r29.s64;
	// stw r11,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// b 0x82080734
	goto loc_82080734;
loc_82080664:
	// cmplw cr6,r31,r26
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r26.u32, ctx.xer);
	// blt cr6,0x82080700
	if (ctx.cr6.lt) goto loc_82080700;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82080684
	if (ctx.cr6.eq) goto loc_82080684;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207c558
	ctx.lr = 0x8208067C;
	sub_8207C558(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x82080758
	if (!ctx.cr0.eq) goto loc_82080758;
loc_82080684:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x820806a4
	if (ctx.cr6.eq) goto loc_820806A4;
	// divwu r11,r31,r26
	ctx.r11.u32 = ppc_divwu(ctx.r31.u32, ctx.r26.u32);
	// twllei r26,0
	// mullw r11,r11,r26
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r26.s32);
	// subf r11,r11,r31
	ctx.r11.s64 = ctx.r31.s64 - ctx.r11.s64;
	// subf r29,r11,r31
	ctx.r29.s64 = ctx.r31.s64 - ctx.r11.s64;
	// b 0x820806a8
	goto loc_820806A8;
loc_820806A4:
	// mr r29,r31
	ctx.r29.u64 = ctx.r31.u64;
loc_820806A8:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820809e8
	ctx.lr = 0x820806B0;
	sub_820809E8(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x82080d90
	ctx.lr = 0x820806BC;
	sub_82080D90(ctx, base);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x820806e4
	if (ctx.cr6.eq) goto loc_820806E4;
	// cmplw cr6,r3,r29
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r29.u32, ctx.xer);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// bgt cr6,0x820806d4
	if (ctx.cr6.gt) goto loc_820806D4;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_820806D4:
	// subf r31,r11,r31
	ctx.r31.s64 = ctx.r31.s64 - ctx.r11.s64;
	// add r28,r11,r28
	ctx.r28.u64 = ctx.r11.u64 + ctx.r28.u64;
	// cmplw cr6,r3,r29
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r29.u32, ctx.xer);
	// bge cr6,0x82080734
	if (!ctx.cr6.lt) goto loc_82080734;
loc_820806E4:
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// subf r10,r31,r27
	ctx.r10.s64 = ctx.r27.s64 - ctx.r31.s64;
	// twllei r25,0
	// ori r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 | 32;
	// divwu r3,r10,r25
	ctx.r3.u32 = ppc_divwu(ctx.r10.u32, ctx.r25.u32);
	// stw r11,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r11.u32);
	// b 0x82080594
	goto loc_82080594;
loc_82080700:
	// lbz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// extsb r3,r11
	ctx.r3.s64 = ctx.r11.s8;
	// bl 0x8207e1b8
	ctx.lr = 0x82080710;
	sub_8207E1B8(ctx, base);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x82080758
	if (ctx.cr6.eq) goto loc_82080758;
	// lwz r11,24(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r31,r31,-1
	ctx.r31.s64 = ctx.r31.s64 + -1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// mr r26,r11
	ctx.r26.u64 = ctx.r11.u64;
	// bgt cr6,0x82080734
	if (ctx.cr6.gt) goto loc_82080734;
	// li r26,1
	ctx.r26.s64 = 1;
loc_82080734:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82080604
	if (!ctx.cr6.eq) goto loc_82080604;
	// b 0x820807a8
	goto loc_820807A8;
loc_82080740:
	// ori r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 | 32;
	// subf r10,r31,r27
	ctx.r10.s64 = ctx.r27.s64 - ctx.r31.s64;
	// stw r11,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r11.u32);
	// divwu r3,r10,r25
	ctx.r3.u32 = ppc_divwu(ctx.r10.u32, ctx.r25.u32);
loc_82080750:
	// twllei r25,0
	// b 0x82080594
	goto loc_82080594;
loc_82080758:
	// subf r11,r31,r27
	ctx.r11.s64 = ctx.r27.s64 - ctx.r31.s64;
	// divwu r3,r11,r25
	ctx.r3.u32 = ppc_divwu(ctx.r11.u32, ctx.r25.u32);
	// b 0x82080750
	goto loc_82080750;
loc_82080764:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x820807a8
	if (ctx.cr6.eq) goto loc_820807A8;
loc_8208076C:
	// cmplwi cr6,r31,255
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 255, ctx.xer);
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
	// blt cr6,0x8208077c
	if (ctx.cr6.lt) goto loc_8208077C;
	// li r30,255
	ctx.r30.s64 = 255;
loc_8208077C:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8207dac0
	ctx.lr = 0x8208078C;
	sub_8207DAC0(ctx, base);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stbx r10,r30,r11
	PPC_STORE_U8(ctx.r30.u32 + ctx.r11.u32, ctx.r10.u8);
	// bl 0x8208d988
	ctx.lr = 0x820807A0;
	sub_8208D988(ctx, base);
	// subf. r31,r30,r31
	ctx.r31.s64 = ctx.r31.s64 - ctx.r30.s64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x8208076c
	if (!ctx.cr0.eq) goto loc_8208076C;
loc_820807A8:
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// b 0x82080594
	goto loc_82080594;
}

__attribute__((alias("__imp__sub_820807B0"))) PPC_WEAK_FUNC(sub_820807B0);
PPC_FUNC_IMPL(__imp__sub_820807B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lwz r16,21428(r29)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r29.u32 + 21428);
	// lwz r16,6776(r5)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r5.u32 + 6776);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x820807C0;
	__savegprlr_27(ctx, base);
	// addi r31,r1,-144
	ctx.r31.s64 = ctx.r1.s64 + -144;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// stw r6,188(r31)
	PPC_STORE_U32(ctx.r31.u32 + 188, ctx.r6.u32);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8208081c
	if (ctx.cr6.eq) goto loc_8208081C;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x8208081c
	if (ctx.cr6.eq) goto loc_8208081C;
	// addic r11,r6,-1
	ctx.xer.ca = ctx.r6.u32 > 0;
	ctx.r11.s64 = ctx.r6.s64 + -1;
	// subfe. r11,r11,r6
	temp.u8 = (~ctx.r11.u32 + ctx.r6.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r6.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r6.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82080828
	if (!ctx.cr0.eq) goto loc_82080828;
	// bl 0x8207d4d8
	ctx.lr = 0x820807FC;
	sub_8207D4D8(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d940
	ctx.lr = 0x8208081C;
	sub_8207D940(ctx, base);
loc_8208081C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82080820:
	// addi r1,r31,144
	ctx.r1.s64 = ctx.r31.s64 + 144;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_82080828:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207c430
	ctx.lr = 0x82080830;
	sub_8207C430(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82080538
	ctx.lr = 0x82080848;
	sub_82080538(ctx, base);
	// stw r3,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r3.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,144
	ctx.r12.s64 = ctx.r31.s64 + 144;
	// bl 0x82080880
	ctx.lr = 0x82080858;
	sub_82080880(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// b 0x82080820
	goto loc_82080820;
}

__attribute__((alias("__imp__sub_820807B8"))) PPC_WEAK_FUNC(sub_820807B8);
PPC_FUNC_IMPL(__imp__sub_820807B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x820807C0;
	__savegprlr_27(ctx, base);
	// addi r31,r1,-144
	ctx.r31.s64 = ctx.r1.s64 + -144;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// stw r6,188(r31)
	PPC_STORE_U32(ctx.r31.u32 + 188, ctx.r6.u32);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8208081c
	if (ctx.cr6.eq) goto loc_8208081C;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x8208081c
	if (ctx.cr6.eq) goto loc_8208081C;
	// addic r11,r6,-1
	ctx.xer.ca = ctx.r6.u32 > 0;
	ctx.r11.s64 = ctx.r6.s64 + -1;
	// subfe. r11,r11,r6
	temp.u8 = (~ctx.r11.u32 + ctx.r6.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r6.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r6.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82080828
	if (!ctx.cr0.eq) goto loc_82080828;
	// bl 0x8207d4d8
	ctx.lr = 0x820807FC;
	sub_8207D4D8(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d940
	ctx.lr = 0x8208081C;
	sub_8207D940(ctx, base);
loc_8208081C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82080820:
	// addi r1,r31,144
	ctx.r1.s64 = ctx.r31.s64 + 144;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_82080828:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207c430
	ctx.lr = 0x82080830;
	sub_8207C430(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82080538
	ctx.lr = 0x82080848;
	sub_82080538(ctx, base);
	// stw r3,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r3.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,144
	ctx.r12.s64 = ctx.r31.s64 + 144;
	// bl 0x82080880
	ctx.lr = 0x82080858;
	sub_82080880(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// b 0x82080820
	goto loc_82080820;
}

__attribute__((alias("__imp__sub_82080860"))) PPC_WEAK_FUNC(sub_82080860);
PPC_FUNC_IMPL(__imp__sub_82080860) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r31,r12,-144
	ctx.r31.s64 = ctx.r12.s64 + -144;
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r30,188(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 188);
	// b 0x82080898
	goto loc_82080898;
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r31,r12,-144
	ctx.r31.s64 = ctx.r12.s64 + -144;
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
loc_82080898:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207c4f0
	ctx.lr = 0x820808A0;
	sub_8207C4F0(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r30,-16(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-24(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82080880"))) PPC_WEAK_FUNC(sub_82080880);
PPC_FUNC_IMPL(__imp__sub_82080880) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r31,r12,-144
	ctx.r31.s64 = ctx.r12.s64 + -144;
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207c4f0
	ctx.lr = 0x820808A0;
	sub_8207C4F0(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r30,-16(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-24(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820808B8"))) PPC_WEAK_FUNC(sub_820808B8);
PPC_FUNC_IMPL(__imp__sub_820808B8) {
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
	// li r4,72
	ctx.r4.s64 = 72;
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x8207e150
	ctx.lr = 0x820808D0;
	sub_8207E150(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x820808e0
	if (!ctx.cr0.eq) goto loc_820808E0;
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x82080978
	goto loc_82080978;
loc_820808E0:
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// addi r6,r3,2304
	ctx.r6.s64 = ctx.r3.s64 + 2304;
	// li r9,32
	ctx.r9.s64 = 32;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r3,-23360(r8)
	PPC_STORE_U32(ctx.r8.u32 + -23360, ctx.r3.u32);
	// cmplw cr6,r3,r6
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r6.u32, ctx.xer);
	// stw r9,-23372(r7)
	PPC_STORE_U32(ctx.r7.u32 + -23372, ctx.r9.u32);
	// bge cr6,0x82080948
	if (!ctx.cr6.lt) goto loc_82080948;
	// li r9,10
	ctx.r9.s64 = 10;
loc_8208090C:
	// li r10,-1
	ctx.r10.s64 = -1;
	// stb r11,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r11.u8);
	// stb r9,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, ctx.r9.u8);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, ctx.r11.u8);
	// stb r9,41(r3)
	PPC_STORE_U8(ctx.r3.u32 + 41, ctx.r9.u8);
	// stb r9,42(r3)
	PPC_STORE_U8(ctx.r3.u32 + 42, ctx.r9.u8);
	// stw r11,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r11.u32);
	// stb r11,60(r3)
	PPC_STORE_U8(ctx.r3.u32 + 60, ctx.r11.u8);
	// addi r3,r3,72
	ctx.r3.s64 = ctx.r3.s64 + 72;
	// lwz r10,-23360(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + -23360);
	// addi r7,r10,2304
	ctx.r7.s64 = ctx.r10.s64 + 2304;
	// cmplw cr6,r3,r7
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r7.u32, ctx.xer);
	// blt cr6,0x8208090c
	if (ctx.cr6.lt) goto loc_8208090C;
loc_82080948:
	// li r9,3
	ctx.r9.s64 = 3;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// b 0x82080958
	goto loc_82080958;
loc_82080954:
	// lwz r10,-23360(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + -23360);
loc_82080958:
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// li r9,-63
	ctx.r9.s64 = -63;
	// li r7,-2
	ctx.r7.s64 = -2;
	// addi r11,r11,72
	ctx.r11.s64 = ctx.r11.s64 + 72;
	// stb r9,4(r10)
	PPC_STORE_U8(ctx.r10.u32 + 4, ctx.r9.u8);
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// bdnz 0x82080954
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82080954;
	// li r3,0
	ctx.r3.s64 = 0;
loc_82080978:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82080988"))) PPC_WEAK_FUNC(sub_82080988);
PPC_FUNC_IMPL(__imp__sub_82080988) {
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
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r30,r11,-23360
	ctx.r30.s64 = ctx.r11.s64 + -23360;
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
loc_820809A8:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820809c0
	if (ctx.cr6.eq) goto loc_820809C0;
	// bl 0x8207c068
	ctx.lr = 0x820809B8;
	sub_8207C068(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_820809C0:
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// addi r11,r30,256
	ctx.r11.s64 = ctx.r30.s64 + 256;
	// cmpw cr6,r31,r11
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x820809a8
	if (ctx.cr6.lt) goto loc_820809A8;
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

__attribute__((alias("__imp__sub_820809E8"))) PPC_WEAK_FUNC(sub_820809E8);
PPC_FUNC_IMPL(__imp__sub_820809E8) {
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
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82080a28
	if (!ctx.cr6.eq) goto loc_82080A28;
	// bl 0x8207d4d8
	ctx.lr = 0x82080A00;
	sub_8207D4D8(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d940
	ctx.lr = 0x82080A20;
	sub_8207D940(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x82080a2c
	goto loc_82080A2C;
loc_82080A28:
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
loc_82080A2C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82080A3C"))) PPC_WEAK_FUNC(sub_82080A3C);
PPC_FUNC_IMPL(__imp__sub_82080A3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82080A40"))) PPC_WEAK_FUNC(sub_82080A40);
PPC_FUNC_IMPL(__imp__sub_82080A40) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lwz r16,21428(r29)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r29.u32 + 21428);
	// lwz r16,6800(r5)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r5.u32 + 6800);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x82080A50;
	__savegprlr_26(ctx, base);
	// addi r31,r1,-144
	ctx.r31.s64 = ctx.r1.s64 + -144;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r26,0
	ctx.r26.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r26,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r26.u32);
	// bl 0x8207d808
	ctx.lr = 0x82080A68;
	sub_8207D808(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// li r28,3
	ctx.r28.s64 = 3;
	// lis r29,-32224
	ctx.r29.s64 = -2111832064;
	// lis r27,-32224
	ctx.r27.s64 = -2111832064;
loc_82080A78:
	// stw r28,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r28.u32);
	// lwz r11,-23084(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + -23084);
	// cmpw cr6,r28,r11
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x82080af0
	if (!ctx.cr6.lt) goto loc_82080AF0;
	// lwz r11,-23088(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -23088);
	// rlwinm r30,r28,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r30,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82080ae4
	if (ctx.cr6.eq) goto loc_82080AE4;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// andi. r11,r11,131
	ctx.r11.u64 = ctx.r11.u64 & 131;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82080ac4
	if (ctx.cr0.eq) goto loc_82080AC4;
	// bl 0x82084a80
	ctx.lr = 0x82080AB4;
	sub_82084A80(ctx, base);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x82080ac4
	if (ctx.cr6.eq) goto loc_82080AC4;
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// stw r26,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r26.u32);
loc_82080AC4:
	// cmpwi cr6,r28,20
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 20, ctx.xer);
	// blt cr6,0x82080ae4
	if (ctx.cr6.lt) goto loc_82080AE4;
	// lwz r11,-23088(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -23088);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// bl 0x8207c068
	ctx.lr = 0x82080AD8;
	sub_8207C068(ctx, base);
	// lwz r11,-23088(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -23088);
	// li r10,0
	ctx.r10.s64 = 0;
	// stwx r10,r30,r11
	PPC_STORE_U32(ctx.r30.u32 + ctx.r11.u32, ctx.r10.u32);
loc_82080AE4:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// b 0x82080a78
	goto loc_82080A78;
loc_82080AF0:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,144
	ctx.r12.s64 = ctx.r31.s64 + 144;
	// bl 0x82080b08
	ctx.lr = 0x82080AFC;
	sub_82080B08(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// addi r1,r31,144
	ctx.r1.s64 = ctx.r31.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82080A48"))) PPC_WEAK_FUNC(sub_82080A48);
PPC_FUNC_IMPL(__imp__sub_82080A48) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x82080A50;
	__savegprlr_26(ctx, base);
	// addi r31,r1,-144
	ctx.r31.s64 = ctx.r1.s64 + -144;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r26,0
	ctx.r26.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r26,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r26.u32);
	// bl 0x8207d808
	ctx.lr = 0x82080A68;
	sub_8207D808(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// li r28,3
	ctx.r28.s64 = 3;
	// lis r29,-32224
	ctx.r29.s64 = -2111832064;
	// lis r27,-32224
	ctx.r27.s64 = -2111832064;
loc_82080A78:
	// stw r28,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r28.u32);
	// lwz r11,-23084(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + -23084);
	// cmpw cr6,r28,r11
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x82080af0
	if (!ctx.cr6.lt) goto loc_82080AF0;
	// lwz r11,-23088(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -23088);
	// rlwinm r30,r28,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r30,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82080ae4
	if (ctx.cr6.eq) goto loc_82080AE4;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// andi. r11,r11,131
	ctx.r11.u64 = ctx.r11.u64 & 131;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82080ac4
	if (ctx.cr0.eq) goto loc_82080AC4;
	// bl 0x82084a80
	ctx.lr = 0x82080AB4;
	sub_82084A80(ctx, base);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x82080ac4
	if (ctx.cr6.eq) goto loc_82080AC4;
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// stw r26,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r26.u32);
loc_82080AC4:
	// cmpwi cr6,r28,20
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 20, ctx.xer);
	// blt cr6,0x82080ae4
	if (ctx.cr6.lt) goto loc_82080AE4;
	// lwz r11,-23088(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -23088);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// bl 0x8207c068
	ctx.lr = 0x82080AD8;
	sub_8207C068(ctx, base);
	// lwz r11,-23088(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -23088);
	// li r10,0
	ctx.r10.s64 = 0;
	// stwx r10,r30,r11
	PPC_STORE_U32(ctx.r30.u32 + ctx.r11.u32, ctx.r10.u32);
loc_82080AE4:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// b 0x82080a78
	goto loc_82080A78;
loc_82080AF0:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,144
	ctx.r12.s64 = ctx.r31.s64 + 144;
	// bl 0x82080b08
	ctx.lr = 0x82080AFC;
	sub_82080B08(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// addi r1,r31,144
	ctx.r1.s64 = ctx.r31.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82080B08"))) PPC_WEAK_FUNC(sub_82080B08);
PPC_FUNC_IMPL(__imp__sub_82080B08) {
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
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8207d6a8
	ctx.lr = 0x82080B1C;
	sub_8207D6A8(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82080B2C"))) PPC_WEAK_FUNC(sub_82080B2C);
PPC_FUNC_IMPL(__imp__sub_82080B2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82080B30"))) PPC_WEAK_FUNC(sub_82080B30);
PPC_FUNC_IMPL(__imp__sub_82080B30) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c96c
	ctx.lr = 0x82080B38;
	__savegprlr_21(ctx, base);
	// ld r12,-4096(r1)
	ctx.r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -4096);
	// stwu r1,-5312(r1)
	ea = -5312 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r21,0
	ctx.r21.s64 = 0;
	// mr r24,r4
	ctx.r24.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// mr r23,r21
	ctx.r23.u64 = ctx.r21.u64;
	// mr r22,r21
	ctx.r22.u64 = ctx.r21.u64;
	// bne cr6,0x82080b64
	if (!ctx.cr6.eq) goto loc_82080B64;
loc_82080B5C:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82080d7c
	goto loc_82080D7C;
loc_82080B64:
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// bne cr6,0x82080ba0
	if (!ctx.cr6.eq) goto loc_82080BA0;
loc_82080B6C:
	// bl 0x8207d510
	ctx.lr = 0x82080B70;
	sub_8207D510(ctx, base);
	// stw r21,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r21.u32);
	// bl 0x8207d4d8
	ctx.lr = 0x82080B78;
	sub_8207D4D8(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d940
	ctx.lr = 0x82080B98;
	sub_8207D940(ctx, base);
loc_82080B98:
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x82080d7c
	goto loc_82080D7C;
loc_82080BA0:
	// srawi r11,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 5;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// rlwinm r26,r11,2,0,29
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r27,r10,-23360
	ctx.r27.s64 = ctx.r10.s64 + -23360;
	// clrlwi r11,r3,27
	ctx.r11.u64 = ctx.r3.u32 & 0x1F;
	// mulli r28,r11,72
	ctx.r28.s64 = ctx.r11.s64 * 72;
	// lwzx r11,r26,r27
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + ctx.r27.u32);
	// add r10,r11,r28
	ctx.r10.u64 = ctx.r11.u64 + ctx.r28.u64;
	// lbz r11,40(r10)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 40);
	// rotlwi r11,r11,24
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 24);
	// srawi r11,r11,25
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1FFFFFF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 25;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x82080be0
	if (ctx.cr6.eq) goto loc_82080BE0;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82080bec
	if (!ctx.cr6.eq) goto loc_82080BEC;
loc_82080BE0:
	// not r11,r29
	ctx.r11.u64 = ~ctx.r29.u64;
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82080b6c
	if (ctx.cr0.eq) goto loc_82080B6C;
loc_82080BEC:
	// lbz r11,4(r10)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 4);
	// rlwinm. r11,r11,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82080c04
	if (ctx.cr0.eq) goto loc_82080C04;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82082790
	ctx.lr = 0x82080C04;
	sub_82082790(ctx, base);
loc_82080C04:
	// lwzx r11,r26,r27
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + ctx.r27.u32);
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// rlwinm. r10,r10,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82080cc4
	if (ctx.cr0.eq) goto loc_82080CC4;
	// mr r25,r21
	ctx.r25.u64 = ctx.r21.u64;
	// mr r30,r24
	ctx.r30.u64 = ctx.r24.u64;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82080d38
	if (ctx.cr6.eq) goto loc_82080D38;
loc_82080C28:
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// mr r10,r21
	ctx.r10.u64 = ctx.r21.u64;
	// subf r9,r24,r30
	ctx.r9.s64 = ctx.r30.s64 - ctx.r24.s64;
loc_82080C34:
	// cmplw cr6,r9,r29
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r29.u32, ctx.xer);
	// bge cr6,0x82080c78
	if (!ctx.cr6.lt) goto loc_82080C78;
	// lbz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r30.u32 + 0);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmplwi cr6,r8,10
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 10, ctx.xer);
	// bne cr6,0x82080c64
	if (!ctx.cr6.eq) goto loc_82080C64;
	// li r7,13
	ctx.r7.s64 = 13;
	// addi r22,r22,1
	ctx.r22.s64 = ctx.r22.s64 + 1;
	// stb r7,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r7.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_82080C64:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r8,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r8.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,5119
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 5119, ctx.xer);
	// blt cr6,0x82080c34
	if (ctx.cr6.lt) goto loc_82080C34;
loc_82080C78:
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lwzx r9,r26,r27
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r26.u32 + ctx.r27.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// subf r31,r10,r11
	ctx.r31.s64 = ctx.r11.s64 - ctx.r10.s64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwzx r3,r9,r28
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r28.u32);
	// bl 0x82089768
	ctx.lr = 0x82080C9C;
	sub_82089768(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82080cf0
	if (ctx.cr0.eq) goto loc_82080CF0;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r23,r11,r23
	ctx.r23.u64 = ctx.r11.u64 + ctx.r23.u64;
	// cmpw cr6,r11,r31
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r31.s32, ctx.xer);
	// blt cr6,0x82080cf8
	if (ctx.cr6.lt) goto loc_82080CF8;
	// subf r11,r24,r30
	ctx.r11.s64 = ctx.r30.s64 - ctx.r24.s64;
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// blt cr6,0x82080c28
	if (ctx.cr6.lt) goto loc_82080C28;
	// b 0x82080cf8
	goto loc_82080CF8;
loc_82080CC4:
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x82089768
	ctx.lr = 0x82080CDC;
	sub_82089768(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82080cf0
	if (ctx.cr0.eq) goto loc_82080CF0;
	// lwz r23,80(r1)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r25,r21
	ctx.r25.u64 = ctx.r21.u64;
	// b 0x82080cf8
	goto loc_82080CF8;
loc_82080CF0:
	// bl 0x82089a10
	ctx.lr = 0x82080CF4;
	sub_82089A10(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
loc_82080CF8:
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// bne cr6,0x82080d78
	if (!ctx.cr6.eq) goto loc_82080D78;
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x82080d38
	if (ctx.cr6.eq) goto loc_82080D38;
	// cmplwi cr6,r25,5
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 5, ctx.xer);
	// bne cr6,0x82080d2c
	if (!ctx.cr6.eq) goto loc_82080D2C;
	// bl 0x8207d4d8
	ctx.lr = 0x82080D14;
	sub_8207D4D8(ctx, base);
	// li r11,9
	ctx.r11.s64 = 9;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d510
	ctx.lr = 0x82080D20;
	sub_8207D510(ctx, base);
	// li r11,5
	ctx.r11.s64 = 5;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// b 0x82080b98
	goto loc_82080B98;
loc_82080D2C:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x8207d548
	ctx.lr = 0x82080D34;
	sub_8207D548(ctx, base);
	// b 0x82080b98
	goto loc_82080B98;
loc_82080D38:
	// lwzx r11,r26,r27
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + ctx.r27.u32);
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// lbz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// rlwinm. r11,r11,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82080d58
	if (ctx.cr0.eq) goto loc_82080D58;
	// lbz r11,0(r24)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r24.u32 + 0);
	// cmplwi cr6,r11,26
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 26, ctx.xer);
	// beq cr6,0x82080b5c
	if (ctx.cr6.eq) goto loc_82080B5C;
loc_82080D58:
	// bl 0x8207d4d8
	ctx.lr = 0x82080D5C;
	sub_8207D4D8(ctx, base);
	// li r11,28
	ctx.r11.s64 = 28;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d510
	ctx.lr = 0x82080D68;
	sub_8207D510(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r21,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r21.u32);
	// b 0x82080d7c
	goto loc_82080D7C;
loc_82080D78:
	// subf r3,r22,r23
	ctx.r3.s64 = ctx.r23.s64 - ctx.r22.s64;
loc_82080D7C:
	// addi r1,r1,5312
	ctx.r1.s64 = ctx.r1.s64 + 5312;
	// b 0x8207c9bc
	__restgprlr_21(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82080D84"))) PPC_WEAK_FUNC(sub_82080D84);
PPC_FUNC_IMPL(__imp__sub_82080D84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82080D88"))) PPC_WEAK_FUNC(sub_82080D88);
PPC_FUNC_IMPL(__imp__sub_82080D88) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lwz r16,21428(r29)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r29.u32 + 21428);
	// lwz r16,6824(r5)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r5.u32 + 6824);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x82080D98;
	__savegprlr_25(ctx, base);
	// addi r31,r1,-160
	ctx.r31.s64 = ctx.r1.s64 + -160;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r3,180(r31)
	PPC_STORE_U32(ctx.r31.u32 + 180, ctx.r3.u32);
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// cmpwi cr6,r3,-2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -2, ctx.xer);
	// bne cr6,0x82080ddc
	if (!ctx.cr6.eq) goto loc_82080DDC;
	// bl 0x8207d510
	ctx.lr = 0x82080DBC;
	sub_8207D510(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d4d8
	ctx.lr = 0x82080DC8;
	sub_8207D4D8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,9
	ctx.r10.s64 = 9;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// b 0x82080ec0
	goto loc_82080EC0;
loc_82080DDC:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x82080df4
	if (ctx.cr6.lt) goto loc_82080DF4;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-23372(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -23372);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82080e2c
	if (ctx.cr6.lt) goto loc_82080E2C;
loc_82080DF4:
	// bl 0x8207d510
	ctx.lr = 0x82080DF8;
	sub_8207D510(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d4d8
	ctx.lr = 0x82080E04;
	sub_8207D4D8(ctx, base);
	// li r11,9
	ctx.r11.s64 = 9;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d940
	ctx.lr = 0x82080E24;
	sub_8207D940(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x82080ec0
	goto loc_82080EC0;
loc_82080E2C:
	// srawi r11,r30,5
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r30.s32 >> 5;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// rlwinm r27,r11,2,0,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r28,r10,-23360
	ctx.r28.s64 = ctx.r10.s64 + -23360;
	// clrlwi r11,r30,27
	ctx.r11.u64 = ctx.r30.u32 & 0x1F;
	// mulli r29,r11,72
	ctx.r29.s64 = ctx.r11.s64 * 72;
	// lwzx r11,r27,r28
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r28.u32);
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// lbz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82080df4
	if (ctx.cr0.eq) goto loc_82080DF4;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82084d80
	ctx.lr = 0x82080E60;
	sub_82084D80(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwzx r11,r27,r28
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r28.u32);
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// lbz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82080e90
	if (ctx.cr0.eq) goto loc_82080E90;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82080b30
	ctx.lr = 0x82080E88;
	sub_82080B30(ctx, base);
	// stw r3,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r3.u32);
	// b 0x82080eb0
	goto loc_82080EB0;
loc_82080E90:
	// bl 0x8207d4d8
	ctx.lr = 0x82080E94;
	sub_8207D4D8(ctx, base);
	// li r11,9
	ctx.r11.s64 = 9;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d510
	ctx.lr = 0x82080EA0;
	sub_8207D510(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r10.u32);
loc_82080EB0:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,160
	ctx.r12.s64 = ctx.r31.s64 + 160;
	// bl 0x82080ee8
	ctx.lr = 0x82080EBC;
	sub_82080EE8(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
loc_82080EC0:
	// addi r1,r31,160
	ctx.r1.s64 = ctx.r31.s64 + 160;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82080D90"))) PPC_WEAK_FUNC(sub_82080D90);
PPC_FUNC_IMPL(__imp__sub_82080D90) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x82080D98;
	__savegprlr_25(ctx, base);
	// addi r31,r1,-160
	ctx.r31.s64 = ctx.r1.s64 + -160;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r3,180(r31)
	PPC_STORE_U32(ctx.r31.u32 + 180, ctx.r3.u32);
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// cmpwi cr6,r3,-2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -2, ctx.xer);
	// bne cr6,0x82080ddc
	if (!ctx.cr6.eq) goto loc_82080DDC;
	// bl 0x8207d510
	ctx.lr = 0x82080DBC;
	sub_8207D510(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d4d8
	ctx.lr = 0x82080DC8;
	sub_8207D4D8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,9
	ctx.r10.s64 = 9;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// b 0x82080ec0
	goto loc_82080EC0;
loc_82080DDC:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x82080df4
	if (ctx.cr6.lt) goto loc_82080DF4;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-23372(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -23372);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82080e2c
	if (ctx.cr6.lt) goto loc_82080E2C;
loc_82080DF4:
	// bl 0x8207d510
	ctx.lr = 0x82080DF8;
	sub_8207D510(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d4d8
	ctx.lr = 0x82080E04;
	sub_8207D4D8(ctx, base);
	// li r11,9
	ctx.r11.s64 = 9;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d940
	ctx.lr = 0x82080E24;
	sub_8207D940(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x82080ec0
	goto loc_82080EC0;
loc_82080E2C:
	// srawi r11,r30,5
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r30.s32 >> 5;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// rlwinm r27,r11,2,0,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r28,r10,-23360
	ctx.r28.s64 = ctx.r10.s64 + -23360;
	// clrlwi r11,r30,27
	ctx.r11.u64 = ctx.r30.u32 & 0x1F;
	// mulli r29,r11,72
	ctx.r29.s64 = ctx.r11.s64 * 72;
	// lwzx r11,r27,r28
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r28.u32);
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// lbz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82080df4
	if (ctx.cr0.eq) goto loc_82080DF4;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82084d80
	ctx.lr = 0x82080E60;
	sub_82084D80(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwzx r11,r27,r28
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r28.u32);
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// lbz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82080e90
	if (ctx.cr0.eq) goto loc_82080E90;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82080b30
	ctx.lr = 0x82080E88;
	sub_82080B30(ctx, base);
	// stw r3,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r3.u32);
	// b 0x82080eb0
	goto loc_82080EB0;
loc_82080E90:
	// bl 0x8207d4d8
	ctx.lr = 0x82080E94;
	sub_8207D4D8(ctx, base);
	// li r11,9
	ctx.r11.s64 = 9;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d510
	ctx.lr = 0x82080EA0;
	sub_8207D510(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r10.u32);
loc_82080EB0:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,160
	ctx.r12.s64 = ctx.r31.s64 + 160;
	// bl 0x82080ee8
	ctx.lr = 0x82080EBC;
	sub_82080EE8(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
loc_82080EC0:
	// addi r1,r31,160
	ctx.r1.s64 = ctx.r31.s64 + 160;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82080EC8"))) PPC_WEAK_FUNC(sub_82080EC8);
PPC_FUNC_IMPL(__imp__sub_82080EC8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r31,r12,-160
	ctx.r31.s64 = ctx.r12.s64 + -160;
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r30,180(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 180);
	// b 0x82080f00
	goto loc_82080F00;
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r31,r12,-160
	ctx.r31.s64 = ctx.r12.s64 + -160;
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
loc_82080F00:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82084e80
	ctx.lr = 0x82080F08;
	sub_82084E80(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r30,-16(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-24(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82080EE8"))) PPC_WEAK_FUNC(sub_82080EE8);
PPC_FUNC_IMPL(__imp__sub_82080EE8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r31,r12,-160
	ctx.r31.s64 = ctx.r12.s64 + -160;
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82084e80
	ctx.lr = 0x82080F08;
	sub_82084E80(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r30,-16(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-24(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82080F20"))) PPC_WEAK_FUNC(sub_82080F20);
PPC_FUNC_IMPL(__imp__sub_82080F20) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lwz r16,21428(r29)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r29.u32 + 21428);
	// lwz r16,6848(r5)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r5.u32 + 6848);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82080F30;
	__savegprlr_27(ctx, base);
	// addi r31,r1,-144
	ctx.r31.s64 = ctx.r1.s64 + -144;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// stw r3,164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 164, ctx.r3.u32);
	// cmpwi cr6,r3,-2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -2, ctx.xer);
	// bne cr6,0x82080f60
	if (!ctx.cr6.eq) goto loc_82080F60;
	// bl 0x8207d4d8
	ctx.lr = 0x82080F4C;
	sub_8207D4D8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,9
	ctx.r10.s64 = 9;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// b 0x8208104c
	goto loc_8208104C;
loc_82080F60:
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// blt cr6,0x82080f78
	if (ctx.cr6.lt) goto loc_82080F78;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-23372(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -23372);
	// cmplw cr6,r27,r11
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82080fa4
	if (ctx.cr6.lt) goto loc_82080FA4;
loc_82080F78:
	// bl 0x8207d4d8
	ctx.lr = 0x82080F7C;
	sub_8207D4D8(ctx, base);
	// li r11,9
	ctx.r11.s64 = 9;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d940
	ctx.lr = 0x82080F9C;
	sub_8207D940(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x8208104c
	goto loc_8208104C;
loc_82080FA4:
	// srawi r11,r27,5
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r27.s32 >> 5;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// rlwinm r28,r11,2,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r29,r10,-23360
	ctx.r29.s64 = ctx.r10.s64 + -23360;
	// clrlwi r11,r27,27
	ctx.r11.u64 = ctx.r27.u32 & 0x1F;
	// mulli r30,r11,72
	ctx.r30.s64 = ctx.r11.s64 * 72;
	// lwzx r11,r28,r29
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + ctx.r29.u32);
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// lbz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82080f78
	if (ctx.cr0.eq) goto loc_82080F78;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82084d80
	ctx.lr = 0x82080FD8;
	sub_82084D80(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwzx r11,r28,r29
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + ctx.r29.u32);
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// lbz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82081028
	if (ctx.cr0.eq) goto loc_82081028;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82084cb0
	ctx.lr = 0x82080FF8;
	sub_82084CB0(ctx, base);
	// bl 0x8208d9c8
	ctx.lr = 0x82080FFC;
	sub_8208D9C8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x82081010
	if (!ctx.cr0.eq) goto loc_82081010;
	// bl 0x82089a10
	ctx.lr = 0x82081008;
	sub_82089A10(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x82081014
	goto loc_82081014;
loc_82081010:
	// li r30,0
	ctx.r30.s64 = 0;
loc_82081014:
	// stw r30,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r30.u32);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x8208103c
	if (ctx.cr6.eq) goto loc_8208103C;
	// bl 0x8207d510
	ctx.lr = 0x82081024;
	sub_8207D510(ctx, base);
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
loc_82081028:
	// bl 0x8207d4d8
	ctx.lr = 0x8208102C;
	sub_8207D4D8(ctx, base);
	// li r11,9
	ctx.r11.s64 = 9;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r10.u32);
loc_8208103C:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,144
	ctx.r12.s64 = ctx.r31.s64 + 144;
	// bl 0x82081074
	ctx.lr = 0x82081048;
	sub_82081074(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
loc_8208104C:
	// addi r1,r31,144
	ctx.r1.s64 = ctx.r31.s64 + 144;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82080F28"))) PPC_WEAK_FUNC(sub_82080F28);
PPC_FUNC_IMPL(__imp__sub_82080F28) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82080F30;
	__savegprlr_27(ctx, base);
	// addi r31,r1,-144
	ctx.r31.s64 = ctx.r1.s64 + -144;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// stw r3,164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 164, ctx.r3.u32);
	// cmpwi cr6,r3,-2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -2, ctx.xer);
	// bne cr6,0x82080f60
	if (!ctx.cr6.eq) goto loc_82080F60;
	// bl 0x8207d4d8
	ctx.lr = 0x82080F4C;
	sub_8207D4D8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,9
	ctx.r10.s64 = 9;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// b 0x8208104c
	goto loc_8208104C;
loc_82080F60:
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// blt cr6,0x82080f78
	if (ctx.cr6.lt) goto loc_82080F78;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-23372(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -23372);
	// cmplw cr6,r27,r11
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82080fa4
	if (ctx.cr6.lt) goto loc_82080FA4;
loc_82080F78:
	// bl 0x8207d4d8
	ctx.lr = 0x82080F7C;
	sub_8207D4D8(ctx, base);
	// li r11,9
	ctx.r11.s64 = 9;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d940
	ctx.lr = 0x82080F9C;
	sub_8207D940(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x8208104c
	goto loc_8208104C;
loc_82080FA4:
	// srawi r11,r27,5
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r27.s32 >> 5;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// rlwinm r28,r11,2,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r29,r10,-23360
	ctx.r29.s64 = ctx.r10.s64 + -23360;
	// clrlwi r11,r27,27
	ctx.r11.u64 = ctx.r27.u32 & 0x1F;
	// mulli r30,r11,72
	ctx.r30.s64 = ctx.r11.s64 * 72;
	// lwzx r11,r28,r29
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + ctx.r29.u32);
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// lbz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82080f78
	if (ctx.cr0.eq) goto loc_82080F78;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82084d80
	ctx.lr = 0x82080FD8;
	sub_82084D80(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwzx r11,r28,r29
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + ctx.r29.u32);
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// lbz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82081028
	if (ctx.cr0.eq) goto loc_82081028;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82084cb0
	ctx.lr = 0x82080FF8;
	sub_82084CB0(ctx, base);
	// bl 0x8208d9c8
	ctx.lr = 0x82080FFC;
	sub_8208D9C8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x82081010
	if (!ctx.cr0.eq) goto loc_82081010;
	// bl 0x82089a10
	ctx.lr = 0x82081008;
	sub_82089A10(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x82081014
	goto loc_82081014;
loc_82081010:
	// li r30,0
	ctx.r30.s64 = 0;
loc_82081014:
	// stw r30,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r30.u32);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x8208103c
	if (ctx.cr6.eq) goto loc_8208103C;
	// bl 0x8207d510
	ctx.lr = 0x82081024;
	sub_8207D510(ctx, base);
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
loc_82081028:
	// bl 0x8207d4d8
	ctx.lr = 0x8208102C;
	sub_8207D4D8(ctx, base);
	// li r11,9
	ctx.r11.s64 = 9;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r10.u32);
loc_8208103C:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,144
	ctx.r12.s64 = ctx.r31.s64 + 144;
	// bl 0x82081074
	ctx.lr = 0x82081048;
	sub_82081074(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
loc_8208104C:
	// addi r1,r31,144
	ctx.r1.s64 = ctx.r31.s64 + 144;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82081054"))) PPC_WEAK_FUNC(sub_82081054);
PPC_FUNC_IMPL(__imp__sub_82081054) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r31,r12,-144
	ctx.r31.s64 = ctx.r12.s64 + -144;
	// std r27,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r27.u64);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r27,164(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 164);
	// b 0x8208108c
	goto loc_8208108C;
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r31,r12,-144
	ctx.r31.s64 = ctx.r12.s64 + -144;
	// std r27,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r27.u64);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
loc_8208108C:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82084e80
	ctx.lr = 0x82081094;
	sub_82084E80(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r27,-16(r1)
	ctx.r27.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-24(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82081074"))) PPC_WEAK_FUNC(sub_82081074);
PPC_FUNC_IMPL(__imp__sub_82081074) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r31,r12,-144
	ctx.r31.s64 = ctx.r12.s64 + -144;
	// std r27,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r27.u64);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82084e80
	ctx.lr = 0x82081094;
	sub_82084E80(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r27,-16(r1)
	ctx.r27.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-24(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820810AC"))) PPC_WEAK_FUNC(sub_820810AC);
PPC_FUNC_IMPL(__imp__sub_820810AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820810B0"))) PPC_WEAK_FUNC(sub_820810B0);
PPC_FUNC_IMPL(__imp__sub_820810B0) {
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
	// lis r31,-32226
	ctx.r31.s64 = -2111963136;
	// lwz r3,2528(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2528);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x820810dc
	if (ctx.cr6.eq) goto loc_820810DC;
	// bl 0x821d5414
	ctx.lr = 0x820810D4;
	__imp__KeTlsFree(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,2528(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2528, ctx.r11.u32);
loc_820810DC:
	// bl 0x8207d638
	ctx.lr = 0x820810E0;
	sub_8207D638(ctx, base);
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

__attribute__((alias("__imp__sub_820810F4"))) PPC_WEAK_FUNC(sub_820810F4);
PPC_FUNC_IMPL(__imp__sub_820810F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820810F8"))) PPC_WEAK_FUNC(sub_820810F8);
PPC_FUNC_IMPL(__imp__sub_820810F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82081100;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82089a10
	ctx.lr = 0x82081108;
	sub_82089A10(ctx, base);
	// lis r30,-32226
	ctx.r30.s64 = -2111963136;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r3,2528(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2528);
	// bl 0x821d53f4
	ctx.lr = 0x82081118;
	__imp__KeTlsGetValue(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x820811a0
	if (!ctx.cr0.eq) goto loc_820811A0;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,2528(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2528);
	// bl 0x821d5404
	ctx.lr = 0x8208112C;
	__imp__KeTlsSetValue(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x820811b0
	if (ctx.cr0.eq) goto loc_820811B0;
	// li r4,196
	ctx.r4.s64 = 196;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8207e150
	ctx.lr = 0x82081140;
	sub_8207E150(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// lwz r3,2528(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2528);
	// beq 0x82081194
	if (ctx.cr0.eq) goto loc_82081194;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x821d5404
	ctx.lr = 0x82081154;
	__imp__KeTlsSetValue(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82081184
	if (ctx.cr0.eq) goto loc_82081184;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r11,r11,6568
	ctx.r11.s64 = ctx.r11.s64 + 6568;
	// stw r10,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// stw r11,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// bl 0x8208da10
	ctx.lr = 0x82081174;
	sub_8208DA10(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r3,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// b 0x820811b0
	goto loc_820811B0;
loc_82081184:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207c068
	ctx.lr = 0x8208118C;
	sub_8207C068(ctx, base);
	// li r31,0
	ctx.r31.s64 = 0;
	// b 0x820811b0
	goto loc_820811B0;
loc_82081194:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821d5404
	ctx.lr = 0x8208119C;
	__imp__KeTlsSetValue(ctx, base);
	// b 0x820811b0
	goto loc_820811B0;
loc_820811A0:
	// addi r11,r31,-1
	ctx.r11.s64 = ctx.r31.s64 + -1;
	// subfic r11,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r11.s64 = 0 - ctx.r11.s64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r31,r11,r31
	ctx.r31.u64 = ctx.r11.u64 & ctx.r31.u64;
loc_820811B0:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8208da08
	ctx.lr = 0x820811B8;
	sub_8208DA08(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820811C4"))) PPC_WEAK_FUNC(sub_820811C4);
PPC_FUNC_IMPL(__imp__sub_820811C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820811C8"))) PPC_WEAK_FUNC(sub_820811C8);
PPC_FUNC_IMPL(__imp__sub_820811C8) {
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
	// bl 0x820810f8
	ctx.lr = 0x820811DC;
	sub_820810F8(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x820811ec
	if (!ctx.cr0.eq) goto loc_820811EC;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x8207d0f0
	ctx.lr = 0x820811EC;
	sub_8207D0F0(ctx, base);
loc_820811EC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
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

__attribute__((alias("__imp__sub_82081204"))) PPC_WEAK_FUNC(sub_82081204);
PPC_FUNC_IMPL(__imp__sub_82081204) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82081208"))) PPC_WEAK_FUNC(sub_82081208);
PPC_FUNC_IMPL(__imp__sub_82081208) {
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
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820812b4
	if (ctx.cr6.eq) goto loc_820812B4;
	// lwz r3,36(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82081234
	if (ctx.cr6.eq) goto loc_82081234;
	// bl 0x8207c068
	ctx.lr = 0x82081234;
	sub_8207C068(ctx, base);
loc_82081234:
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82081244
	if (ctx.cr6.eq) goto loc_82081244;
	// bl 0x8207c068
	ctx.lr = 0x82081244;
	sub_8207C068(ctx, base);
loc_82081244:
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82081254
	if (ctx.cr6.eq) goto loc_82081254;
	// bl 0x8207c068
	ctx.lr = 0x82081254;
	sub_8207C068(ctx, base);
loc_82081254:
	// lwz r3,60(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82081264
	if (ctx.cr6.eq) goto loc_82081264;
	// bl 0x8207c068
	ctx.lr = 0x82081264;
	sub_8207C068(ctx, base);
loc_82081264:
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82081274
	if (ctx.cr6.eq) goto loc_82081274;
	// bl 0x8207c068
	ctx.lr = 0x82081274;
	sub_8207C068(ctx, base);
loc_82081274:
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82081284
	if (ctx.cr6.eq) goto loc_82081284;
	// bl 0x8207c068
	ctx.lr = 0x82081284;
	sub_8207C068(ctx, base);
loc_82081284:
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82081294
	if (ctx.cr6.eq) goto loc_82081294;
	// bl 0x8207c068
	ctx.lr = 0x82081294;
	sub_8207C068(ctx, base);
loc_82081294:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// addi r11,r11,6568
	ctx.r11.s64 = ctx.r11.s64 + 6568;
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820812ac
	if (ctx.cr6.eq) goto loc_820812AC;
	// bl 0x8207c068
	ctx.lr = 0x820812AC;
	sub_8207C068(ctx, base);
loc_820812AC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207c068
	ctx.lr = 0x820812B4;
	sub_8207C068(ctx, base);
loc_820812B4:
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

__attribute__((alias("__imp__sub_820812C8"))) PPC_WEAK_FUNC(sub_820812C8);
PPC_FUNC_IMPL(__imp__sub_820812C8) {
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
	// lis r30,-32226
	ctx.r30.s64 = -2111963136;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,2528(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2528);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8208131c
	if (ctx.cr6.eq) goto loc_8208131C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82081308
	if (!ctx.cr6.eq) goto loc_82081308;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x821d53f4
	ctx.lr = 0x82081300;
	__imp__KeTlsGetValue(ctx, base);
	// lwz r11,2528(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2528);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_82081308:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x821d5404
	ctx.lr = 0x82081314;
	__imp__KeTlsSetValue(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82081208
	ctx.lr = 0x8208131C;
	sub_82081208(ctx, base);
loc_8208131C:
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

__attribute__((alias("__imp__sub_82081334"))) PPC_WEAK_FUNC(sub_82081334);
PPC_FUNC_IMPL(__imp__sub_82081334) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82081338"))) PPC_WEAK_FUNC(sub_82081338);
PPC_FUNC_IMPL(__imp__sub_82081338) {
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
	// bl 0x8207d390
	ctx.lr = 0x82081350;
	sub_8207D390(ctx, base);
	// bl 0x8207d5b8
	ctx.lr = 0x82081354;
	sub_8207D5B8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x820813e4
	if (ctx.cr0.eq) goto loc_820813E4;
	// bl 0x821d53e4
	ctx.lr = 0x82081360;
	__imp__KeTlsAlloc(ctx, base);
	// lis r30,-32226
	ctx.r30.s64 = -2111963136;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// stw r3,2528(r30)
	PPC_STORE_U32(ctx.r30.u32 + 2528, ctx.r3.u32);
	// beq cr6,0x820813e4
	if (ctx.cr6.eq) goto loc_820813E4;
	// li r4,196
	ctx.r4.s64 = 196;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8207e150
	ctx.lr = 0x8208137C;
	sub_8207E150(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x820813e4
	if (ctx.cr0.eq) goto loc_820813E4;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r3,2528(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2528);
	// bl 0x821d5404
	ctx.lr = 0x82081390;
	__imp__KeTlsSetValue(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x820813e4
	if (ctx.cr0.eq) goto loc_820813E4;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r11,r11,6568
	ctx.r11.s64 = ctx.r11.s64 + 6568;
	// stw r10,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// stw r11,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// bl 0x8208da10
	ctx.lr = 0x820813B0;
	sub_8208DA10(ctx, base);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lis r11,-32248
	ctx.r11.s64 = -2113404928;
	// stw r3,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// addi r10,r10,-11788
	ctx.r10.s64 = ctx.r10.s64 + -11788;
	// li r9,-1
	ctx.r9.s64 = -1;
	// addi r11,r11,20776
	ctx.r11.s64 = ctx.r11.s64 + 20776;
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r11.u32);
	// bl 0x8208da88
	ctx.lr = 0x820813DC;
	sub_8208DA88(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x820813ec
	goto loc_820813EC;
loc_820813E4:
	// bl 0x820810b0
	ctx.lr = 0x820813E8;
	sub_820810B0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_820813EC:
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

__attribute__((alias("__imp__sub_82081404"))) PPC_WEAK_FUNC(sub_82081404);
PPC_FUNC_IMPL(__imp__sub_82081404) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82081408"))) PPC_WEAK_FUNC(sub_82081408);
PPC_FUNC_IMPL(__imp__sub_82081408) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82081410;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82081428
	if (!ctx.cr6.eq) goto loc_82081428;
	// bl 0x82082590
	ctx.lr = 0x82081428;
	sub_82082590(ctx, base);
loc_82081428:
	// lwz r31,20(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82081438
	if (!ctx.cr6.eq) goto loc_82081438;
	// bl 0x82082590
	ctx.lr = 0x82081438;
	sub_82082590(ctx, base);
loc_82081438:
	// lwz r11,24(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82081448
	if (!ctx.cr6.eq) goto loc_82081448;
	// bl 0x82082590
	ctx.lr = 0x82081448;
	sub_82082590(ctx, base);
loc_82081448:
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8208147c
	if (ctx.cr6.eq) goto loc_8208147C;
	// lwz r8,24(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
loc_8208145C:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r29,r9
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82081494
	if (ctx.cr6.eq) goto loc_82081494;
	// blt cr6,0x820814a4
	if (ctx.cr6.lt) goto loc_820814A4;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// blt cr6,0x8208145c
	if (ctx.cr6.lt) goto loc_8208145C;
loc_8208147C:
	// lwz r10,24(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// rlwinm r11,r31,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
loc_82081488:
	// lwz r3,-4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -4);
loc_8208148C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_82081494:
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x8208148c
	goto loc_8208148C;
loc_820814A4:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820814b4
	if (!ctx.cr6.eq) goto loc_820814B4;
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x8208148c
	goto loc_8208148C;
loc_820814B4:
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// b 0x82081488
	goto loc_82081488;
}

__attribute__((alias("__imp__sub_820814C0"))) PPC_WEAK_FUNC(sub_820814C0);
PPC_FUNC_IMPL(__imp__sub_820814C0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,12(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820814f0
	if (ctx.cr6.eq) goto loc_820814F0;
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820814f0
	if (ctx.cr6.eq) goto loc_820814F0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r11,-2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -2, ctx.xer);
	// beq cr6,0x820814f0
	if (ctx.cr6.eq) goto loc_820814F0;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// blr 
	return;
loc_820814F0:
	// lwz r4,0(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// b 0x82081408
	sub_82081408(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820814FC"))) PPC_WEAK_FUNC(sub_820814FC);
PPC_FUNC_IMPL(__imp__sub_820814FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82081500"))) PPC_WEAK_FUNC(sub_82081500);
PPC_FUNC_IMPL(__imp__sub_82081500) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,12(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r6,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82081520"))) PPC_WEAK_FUNC(sub_82081520);
PPC_FUNC_IMPL(__imp__sub_82081520) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820815c4
	if (ctx.cr6.eq) goto loc_820815C4;
	// lbz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 8);
	// addi r11,r10,8
	ctx.r11.s64 = ctx.r10.s64 + 8;
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq 0x820815c4
	if (ctx.cr0.eq) goto loc_820815C4;
	// lwz r9,4(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82081580
	if (ctx.cr6.eq) goto loc_82081580;
	// addi r10,r9,8
	ctx.r10.s64 = ctx.r9.s64 + 8;
loc_8208154C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq 0x82081570
	if (ctx.cr0.eq) goto loc_82081570;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8208154c
	if (ctx.cr6.eq) goto loc_8208154C;
loc_82081570:
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x82081580
	if (ctx.cr0.eq) goto loc_82081580;
loc_82081578:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82081580:
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// rlwinm. r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82081598
	if (ctx.cr0.eq) goto loc_82081598;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm. r11,r11,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82081578
	if (ctx.cr0.eq) goto loc_82081578;
loc_82081598:
	// lwz r11,0(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// clrlwi. r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x820815b0
	if (ctx.cr0.eq) goto loc_820815B0;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi. r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82081578
	if (ctx.cr0.eq) goto loc_82081578;
loc_820815B0:
	// rlwinm. r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820815c4
	if (ctx.cr0.eq) goto loc_820815C4;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm. r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82081578
	if (ctx.cr0.eq) goto loc_82081578;
loc_820815C4:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820815CC"))) PPC_WEAK_FUNC(sub_820815CC);
PPC_FUNC_IMPL(__imp__sub_820815CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820815D0"))) PPC_WEAK_FUNC(sub_820815D0);
PPC_FUNC_IMPL(__imp__sub_820815D0) {
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
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-8125
	ctx.r10.s64 = -532480000;
	// ori r10,r10,20301
	ctx.r10.u64 = ctx.r10.u64 | 20301;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x82081614
	if (ctx.cr6.eq) goto loc_82081614;
	// lis r10,-8083
	ctx.r10.s64 = -529727488;
	// ori r10,r10,29539
	ctx.r10.u64 = ctx.r10.u64 | 29539;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82081638
	if (!ctx.cr6.eq) goto loc_82081638;
	// bl 0x820811c8
	ctx.lr = 0x82081608;
	sub_820811C8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,132(r3)
	PPC_STORE_U32(ctx.r3.u32 + 132, ctx.r11.u32);
	// bl 0x82082530
	ctx.lr = 0x82081614;
	sub_82082530(ctx, base);
loc_82081614:
	// bl 0x820811c8
	ctx.lr = 0x82081618;
	sub_820811C8(ctx, base);
	// lwz r11,132(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82081638
	if (!ctx.cr6.gt) goto loc_82081638;
	// bl 0x820811c8
	ctx.lr = 0x82081628;
	sub_820811C8(ctx, base);
	// addi r10,r3,132
	ctx.r10.s64 = ctx.r3.s64 + 132;
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
loc_82081638:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8208164C"))) PPC_WEAK_FUNC(sub_8208164C);
PPC_FUNC_IMPL(__imp__sub_8208164C) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// .long 0x0
	// lwz r16,21428(r29)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r29.u32 + 21428);
	// lwz r16,6872(r5)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r5.u32 + 6872);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x82081660;
	__savegprlr_25(ctx, base);
	// addi r31,r1,-160
	ctx.r31.s64 = ctx.r1.s64 + -160;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// stw r3,180(r31)
	PPC_STORE_U32(ctx.r31.u32 + 180, ctx.r3.u32);
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// stw r4,188(r31)
	PPC_STORE_U32(ctx.r31.u32 + 188, ctx.r4.u32);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// stw r5,196(r31)
	PPC_STORE_U32(ctx.r31.u32 + 196, ctx.r5.u32);
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// stw r6,204(r31)
	PPC_STORE_U32(ctx.r31.u32 + 204, ctx.r6.u32);
	// bl 0x820814c0
	ctx.lr = 0x8208168C;
	sub_820814C0(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// stw r27,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r27.u32);
	// cmpwi cr6,r27,-1
	ctx.cr6.compare<int32_t>(ctx.r27.s32, -1, ctx.xer);
	// stw r3,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r3.u32);
	// beq cr6,0x820816c8
	if (ctx.cr6.eq) goto loc_820816C8;
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
loc_820816A4:
	// rlwinm r11,r27,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x820816c8
	if (!ctx.cr6.eq) goto loc_820816C8;
	// lwz r27,0(r11)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r27,-1
	ctx.cr6.compare<int32_t>(ctx.r27.s32, -1, ctx.xer);
	// stw r27,204(r31)
	PPC_STORE_U32(ctx.r31.u32 + 204, ctx.r27.u32);
	// bne cr6,0x820816a4
	if (!ctx.cr6.eq) goto loc_820816A4;
loc_820816C8:
	// cmpwi cr6,r28,-1
	ctx.cr6.compare<int32_t>(ctx.r28.s32, -1, ctx.xer);
	// bne cr6,0x820816d8
	if (!ctx.cr6.eq) goto loc_820816D8;
	// cmpwi cr6,r27,-1
	ctx.cr6.compare<int32_t>(ctx.r27.s32, -1, ctx.xer);
	// beq cr6,0x820817c8
	if (ctx.cr6.eq) goto loc_820817C8;
loc_820816D8:
	// bl 0x820811c8
	ctx.lr = 0x820816DC;
	sub_820811C8(ctx, base);
	// addi r10,r3,132
	ctx.r10.s64 = ctx.r3.s64 + 132;
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
loc_820816EC:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// cmpw cr6,r28,r27
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r27.s32, ctx.xer);
	// beq cr6,0x82081794
	if (ctx.cr6.eq) goto loc_82081794;
	// cmpwi cr6,r28,-1
	ctx.cr6.compare<int32_t>(ctx.r28.s32, -1, ctx.xer);
	// ble cr6,0x8208170c
	if (!ctx.cr6.gt) goto loc_8208170C;
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// cmpw cr6,r28,r11
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x82081710
	if (ctx.cr6.lt) goto loc_82081710;
loc_8208170C:
	// bl 0x82082590
	ctx.lr = 0x82081710;
	sub_82082590(ctx, base);
loc_82081710:
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// rlwinm r29,r28,3,0,28
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// lwz r28,0(r11)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r28,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r28.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82081768
	if (ctx.cr6.eq) goto loc_82081768;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82081500
	ctx.lr = 0x8208174C;
	sub_82081500(ctx, base);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// li r6,0
	ctx.r6.s64 = 0;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// li r5,259
	ctx.r5.s64 = 259;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x82085190
	ctx.lr = 0x82081768;
	sub_82085190(ctx, base);
loc_82081768:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x8208178c
	goto loc_8208178C;
	// lwz r27,204(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 204);
	// lwz r30,196(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 196);
	// lwz r25,188(r31)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r31.u32 + 188);
	// lwz r26,180(r31)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r31.u32 + 180);
	// lwz r28,84(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
loc_8208178C:
	// stw r28,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r28.u32);
	// b 0x820816ec
	goto loc_820816EC;
loc_82081794:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,160
	ctx.r12.s64 = ctx.r31.s64 + 160;
	// bl 0x820817d0
	ctx.lr = 0x820817A0;
	sub_820817D0(ctx, base);
	// lwz r11,204(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 204);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x820817b4
	if (ctx.cr6.eq) goto loc_820817B4;
	// bl 0x82082590
	ctx.lr = 0x820817B4;
	sub_82082590(ctx, base);
loc_820817B4:
	// lwz r6,88(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// lwz r5,196(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 196);
	// lwz r4,188(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 188);
	// lwz r3,180(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 180);
	// bl 0x82081500
	ctx.lr = 0x820817C8;
	sub_82081500(ctx, base);
loc_820817C8:
	// addi r1,r31,160
	ctx.r1.s64 = ctx.r31.s64 + 160;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82081658"))) PPC_WEAK_FUNC(sub_82081658);
PPC_FUNC_IMPL(__imp__sub_82081658) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x82081660;
	__savegprlr_25(ctx, base);
	// addi r31,r1,-160
	ctx.r31.s64 = ctx.r1.s64 + -160;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// stw r3,180(r31)
	PPC_STORE_U32(ctx.r31.u32 + 180, ctx.r3.u32);
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// stw r4,188(r31)
	PPC_STORE_U32(ctx.r31.u32 + 188, ctx.r4.u32);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// stw r5,196(r31)
	PPC_STORE_U32(ctx.r31.u32 + 196, ctx.r5.u32);
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// stw r6,204(r31)
	PPC_STORE_U32(ctx.r31.u32 + 204, ctx.r6.u32);
	// bl 0x820814c0
	ctx.lr = 0x8208168C;
	sub_820814C0(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// stw r27,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r27.u32);
	// cmpwi cr6,r27,-1
	ctx.cr6.compare<int32_t>(ctx.r27.s32, -1, ctx.xer);
	// stw r3,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r3.u32);
	// beq cr6,0x820816c8
	if (ctx.cr6.eq) goto loc_820816C8;
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
loc_820816A4:
	// rlwinm r11,r27,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x820816c8
	if (!ctx.cr6.eq) goto loc_820816C8;
	// lwz r27,0(r11)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r27,-1
	ctx.cr6.compare<int32_t>(ctx.r27.s32, -1, ctx.xer);
	// stw r27,204(r31)
	PPC_STORE_U32(ctx.r31.u32 + 204, ctx.r27.u32);
	// bne cr6,0x820816a4
	if (!ctx.cr6.eq) goto loc_820816A4;
loc_820816C8:
	// cmpwi cr6,r28,-1
	ctx.cr6.compare<int32_t>(ctx.r28.s32, -1, ctx.xer);
	// bne cr6,0x820816d8
	if (!ctx.cr6.eq) goto loc_820816D8;
	// cmpwi cr6,r27,-1
	ctx.cr6.compare<int32_t>(ctx.r27.s32, -1, ctx.xer);
	// beq cr6,0x820817c8
	if (ctx.cr6.eq) goto loc_820817C8;
loc_820816D8:
	// bl 0x820811c8
	ctx.lr = 0x820816DC;
	sub_820811C8(ctx, base);
	// addi r10,r3,132
	ctx.r10.s64 = ctx.r3.s64 + 132;
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
loc_820816EC:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// cmpw cr6,r28,r27
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r27.s32, ctx.xer);
	// beq cr6,0x82081794
	if (ctx.cr6.eq) goto loc_82081794;
	// cmpwi cr6,r28,-1
	ctx.cr6.compare<int32_t>(ctx.r28.s32, -1, ctx.xer);
	// ble cr6,0x8208170c
	if (!ctx.cr6.gt) goto loc_8208170C;
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// cmpw cr6,r28,r11
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x82081710
	if (ctx.cr6.lt) goto loc_82081710;
loc_8208170C:
	// bl 0x82082590
	ctx.lr = 0x82081710;
	sub_82082590(ctx, base);
loc_82081710:
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// rlwinm r29,r28,3,0,28
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// lwz r28,0(r11)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r28,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r28.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82081768
	if (ctx.cr6.eq) goto loc_82081768;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82081500
	ctx.lr = 0x8208174C;
	sub_82081500(ctx, base);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// li r6,0
	ctx.r6.s64 = 0;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// li r5,259
	ctx.r5.s64 = 259;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x82085190
	ctx.lr = 0x82081768;
	sub_82085190(ctx, base);
loc_82081768:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x8208178c
	goto loc_8208178C;
	// lwz r27,204(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 204);
	// lwz r30,196(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 196);
	// lwz r25,188(r31)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r31.u32 + 188);
	// lwz r26,180(r31)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r31.u32 + 180);
	// lwz r28,84(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
loc_8208178C:
	// stw r28,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r28.u32);
	// b 0x820816ec
	goto loc_820816EC;
loc_82081794:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,160
	ctx.r12.s64 = ctx.r31.s64 + 160;
	// bl 0x820817d0
	ctx.lr = 0x820817A0;
	sub_820817D0(ctx, base);
	// lwz r11,204(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 204);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x820817b4
	if (ctx.cr6.eq) goto loc_820817B4;
	// bl 0x82082590
	ctx.lr = 0x820817B4;
	sub_82082590(ctx, base);
loc_820817B4:
	// lwz r6,88(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// lwz r5,196(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 196);
	// lwz r4,188(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 188);
	// lwz r3,180(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 180);
	// bl 0x82081500
	ctx.lr = 0x820817C8;
	sub_82081500(ctx, base);
loc_820817C8:
	// addi r1,r31,160
	ctx.r1.s64 = ctx.r31.s64 + 160;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820817D0"))) PPC_WEAK_FUNC(sub_820817D0);
PPC_FUNC_IMPL(__imp__sub_820817D0) {
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
	// bl 0x820811c8
	ctx.lr = 0x820817E0;
	sub_820811C8(ctx, base);
	// lwz r11,132(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82081800
	if (!ctx.cr6.gt) goto loc_82081800;
	// bl 0x820811c8
	ctx.lr = 0x820817F0;
	sub_820811C8(ctx, base);
	// addi r10,r3,132
	ctx.r10.s64 = ctx.r3.s64 + 132;
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
loc_82081800:
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82081810"))) PPC_WEAK_FUNC(sub_82081810);
PPC_FUNC_IMPL(__imp__sub_82081810) {
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
	// bl 0x820815d0
	ctx.lr = 0x82081820;
	sub_820815D0(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82081834"))) PPC_WEAK_FUNC(sub_82081834);
PPC_FUNC_IMPL(__imp__sub_82081834) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82081838"))) PPC_WEAK_FUNC(sub_82081838);
PPC_FUNC_IMPL(__imp__sub_82081838) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// andi. r11,r11,102
	ctx.r11.u64 = ctx.r11.u64 & 102;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82081850
	if (!ctx.cr0.eq) goto loc_82081850;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_82081850:
	// stw r5,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, ctx.r5.u32);
	// li r3,3
	ctx.r3.s64 = 3;
	// ld r11,48(r5)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r5.u32 + 48);
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// ld r11,56(r5)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r5.u32 + 56);
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r11.u32);
	// ld r11,64(r5)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r5.u32 + 64);
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82081874"))) PPC_WEAK_FUNC(sub_82081874);
PPC_FUNC_IMPL(__imp__sub_82081874) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// .long 0x0
	// lwz r16,21428(r29)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r29.u32 + 21428);
	// lwz r16,6912(r5)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r5.u32 + 6912);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// addi r31,r1,-96
	ctx.r31.s64 = ctx.r1.s64 + -96;
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stb r4,127(r31)
	PPC_STORE_U8(ctx.r31.u32 + 127, ctx.r4.u8);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820818f4
	if (ctx.cr6.eq) goto loc_820818F4;
	// lis r11,-8083
	ctx.r11.s64 = -529727488;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// ori r11,r11,29539
	ctx.r11.u64 = ctx.r11.u64 | 29539;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x820818f4
	if (!ctx.cr6.eq) goto loc_820818F4;
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820818f4
	if (ctx.cr6.eq) goto loc_820818F4;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820818f4
	if (ctx.cr6.eq) goto loc_820818F4;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r3,24(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820818E0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x820818f4
	goto loc_820818F4;
	// bl 0x82082530
	ctx.lr = 0x820818F4;
	sub_82082530(ctx, base);
loc_820818F4:
	// addi r1,r31,96
	ctx.r1.s64 = ctx.r31.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82081880"))) PPC_WEAK_FUNC(sub_82081880);
PPC_FUNC_IMPL(__imp__sub_82081880) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// addi r31,r1,-96
	ctx.r31.s64 = ctx.r1.s64 + -96;
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stb r4,127(r31)
	PPC_STORE_U8(ctx.r31.u32 + 127, ctx.r4.u8);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820818f4
	if (ctx.cr6.eq) goto loc_820818F4;
	// lis r11,-8083
	ctx.r11.s64 = -529727488;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// ori r11,r11,29539
	ctx.r11.u64 = ctx.r11.u64 | 29539;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x820818f4
	if (!ctx.cr6.eq) goto loc_820818F4;
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820818f4
	if (ctx.cr6.eq) goto loc_820818F4;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820818f4
	if (ctx.cr6.eq) goto loc_820818F4;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r3,24(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820818E0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x820818f4
	goto loc_820818F4;
	// bl 0x82082530
	ctx.lr = 0x820818F4;
	sub_82082530(ctx, base);
loc_820818F4:
	// addi r1,r31,96
	ctx.r1.s64 = ctx.r31.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82081908"))) PPC_WEAK_FUNC(sub_82081908);
PPC_FUNC_IMPL(__imp__sub_82081908) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r31,r12,-96
	ctx.r31.s64 = ctx.r12.s64 + -96;
	// lbz r11,127(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 127);
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r3,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82081928"))) PPC_WEAK_FUNC(sub_82081928);
PPC_FUNC_IMPL(__imp__sub_82081928) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x82081930;
	__savegprlr_24(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// mr r26,r8
	ctx.r26.u64 = ctx.r8.u64;
	// mr r31,r9
	ctx.r31.u64 = ctx.r9.u64;
	// bl 0x820811c8
	ctx.lr = 0x82081950;
	sub_820811C8(ctx, base);
	// lwz r25,124(r3)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// bl 0x820811c8
	ctx.lr = 0x82081958;
	sub_820811C8(ctx, base);
	// lwz r24,128(r3)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// bl 0x820811c8
	ctx.lr = 0x82081960;
	sub_820811C8(ctx, base);
	// stw r30,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r30.u32);
	// bl 0x820811c8
	ctx.lr = 0x82081968;
	sub_820811C8(ctx, base);
	// li r11,-2
	ctx.r11.s64 = -2;
	// stw r28,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, ctx.r28.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// li r5,256
	ctx.r5.s64 = 256;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r31.u32);
	// bl 0x82085190
	ctx.lr = 0x82081998;
	sub_82085190(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207d040
	ctx.lr = 0x820819A4;
	sub_8207D040(ctx, base);
	// bl 0x820811c8
	ctx.lr = 0x820819A8;
	sub_820811C8(ctx, base);
	// stw r25,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r25.u32);
	// bl 0x820811c8
	ctx.lr = 0x820819B0;
	sub_820811C8(ctx, base);
	// stw r24,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, ctx.r24.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820819e0
	if (ctx.cr6.eq) goto loc_820819E0;
	// bl 0x8207cfe8
	ctx.lr = 0x820819C4;
	sub_8207CFE8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x820819e0
	if (ctx.cr0.eq) goto loc_820819E0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82081880
	ctx.lr = 0x820819D8;
	sub_82081880(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_820819E0:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820819EC"))) PPC_WEAK_FUNC(sub_820819EC);
PPC_FUNC_IMPL(__imp__sub_820819EC) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// .long 0x0
	// lwz r16,21428(r29)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r29.u32 + 21428);
	// lwz r16,6936(r5)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r5.u32 + 6936);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82081A00;
	__savegprlr_28(ctx, base);
	// addi r31,r1,-144
	ctx.r31.s64 = ctx.r1.s64 + -144;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// lwz r11,4(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82081c68
	if (ctx.cr6.eq) goto loc_82081C68;
	// lbz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 8);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82081c68
	if (ctx.cr0.eq) goto loc_82081C68;
	// lwz r11,8(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82081a48
	if (!ctx.cr6.eq) goto loc_82081A48;
	// lwz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// rlwinm. r10,r10,0,0,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82081c68
	if (ctx.cr0.eq) goto loc_82081C68;
loc_82081A48:
	// lwz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// rlwinm. r9,r10,0,0,0
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// bne 0x82081a5c
	if (!ctx.cr0.eq) goto loc_82081A5C;
	// add r28,r11,r4
	ctx.r28.u64 = ctx.r11.u64 + ctx.r4.u64;
loc_82081A5C:
	// nop 
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// rlwinm. r11,r10,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// beq 0x82081ae4
	if (ctx.cr0.eq) goto loc_82081AE4;
	// bl 0x820852b0
	ctx.lr = 0x82081A7C;
	sub_820852B0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82081c48
	if (ctx.cr0.eq) goto loc_82081C48;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820852b0
	ctx.lr = 0x82081A90;
	sub_820852B0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82081c48
	if (ctx.cr0.eq) goto loc_82081C48;
	// lwz r10,24(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// addi r11,r30,8
	ctx.r11.s64 = ctx.r30.s64 + 8;
	// stw r10,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r10.u32);
	// lwz r8,12(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stw r9,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r9.u32);
	// blt cr6,0x82081adc
	if (ctx.cr6.lt) goto loc_82081ADC;
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwzx r10,r8,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// lwzx r11,r10,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r9,r8,r11
	ctx.r9.u64 = ctx.r8.u64 + ctx.r11.u64;
	// stw r11,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
	// stw r9,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r9.u32);
loc_82081ADC:
	// stw r9,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r9.u32);
	// b 0x82081c4c
	goto loc_82081C4C;
loc_82081AE4:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82081b7c
	if (ctx.cr0.eq) goto loc_82081B7C;
	// bl 0x820852b0
	ctx.lr = 0x82081AF4;
	sub_820852B0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82081c48
	if (ctx.cr0.eq) goto loc_82081C48;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820852b0
	ctx.lr = 0x82081B08;
	sub_820852B0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82081c48
	if (ctx.cr0.eq) goto loc_82081C48;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r5,20(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// lwz r4,24(r29)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// bl 0x8207d870
	ctx.lr = 0x82081B20;
	sub_8207D870(ctx, base);
	// lwz r11,20(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bne cr6,0x82081c4c
	if (!ctx.cr6.eq) goto loc_82081C4C;
	// lwz r8,0(r28)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82081c4c
	if (ctx.cr6.eq) goto loc_82081C4C;
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// addi r11,r30,8
	ctx.r11.s64 = ctx.r30.s64 + 8;
	// lwz r9,12(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r10,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r10.u32);
	// blt cr6,0x82081b74
	if (ctx.cr6.lt) goto loc_82081B74;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwzx r8,r9,r8
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// lwzx r11,r8,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r10,r9,r11
	ctx.r10.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// stw r10,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r10.u32);
loc_82081B74:
	// stw r10,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r10.u32);
	// b 0x82081c4c
	goto loc_82081C4C;
loc_82081B7C:
	// lwz r11,24(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82081bf8
	if (!ctx.cr6.eq) goto loc_82081BF8;
	// bl 0x820852b0
	ctx.lr = 0x82081B8C;
	sub_820852B0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82081c48
	if (ctx.cr0.eq) goto loc_82081C48;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820852b0
	ctx.lr = 0x82081BA0;
	sub_820852B0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82081c48
	if (ctx.cr0.eq) goto loc_82081C48;
	// lwz r10,24(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// addi r11,r30,8
	ctx.r11.s64 = ctx.r30.s64 + 8;
	// lwz r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r8,12(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// add r4,r9,r10
	ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stw r4,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r4.u32);
	// blt cr6,0x82081be8
	if (ctx.cr6.lt) goto loc_82081BE8;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwzx r11,r10,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// add r4,r9,r11
	ctx.r4.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stw r11,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r11.u32);
	// stw r4,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r4.u32);
loc_82081BE8:
	// lwz r5,20(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8207d870
	ctx.lr = 0x82081BF4;
	sub_8207D870(ctx, base);
	// b 0x82081c4c
	goto loc_82081C4C;
loc_82081BF8:
	// bl 0x820852b0
	ctx.lr = 0x82081BFC;
	sub_820852B0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82081c48
	if (ctx.cr0.eq) goto loc_82081C48;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820852b0
	ctx.lr = 0x82081C10;
	sub_820852B0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82081c48
	if (ctx.cr0.eq) goto loc_82081C48;
	// lwz r3,24(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// bl 0x820852b0
	ctx.lr = 0x82081C20;
	sub_820852B0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82081c48
	if (ctx.cr0.eq) goto loc_82081C48;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// rlwinm r11,r11,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// xori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 ^ 1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// b 0x82081c4c
	goto loc_82081C4C;
loc_82081C48:
	// bl 0x82082590
	ctx.lr = 0x82081C4C;
	sub_82082590(ctx, base);
loc_82081C4C:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x82081c60
	goto loc_82081C60;
	// bl 0x82082530
	ctx.lr = 0x82081C60;
	sub_82082530(ctx, base);
loc_82081C60:
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// b 0x82081c6c
	goto loc_82081C6C;
loc_82081C68:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82081C6C:
	// addi r1,r31,144
	ctx.r1.s64 = ctx.r31.s64 + 144;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820819F8"))) PPC_WEAK_FUNC(sub_820819F8);
PPC_FUNC_IMPL(__imp__sub_820819F8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82081A00;
	__savegprlr_28(ctx, base);
	// addi r31,r1,-144
	ctx.r31.s64 = ctx.r1.s64 + -144;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// lwz r11,4(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82081c68
	if (ctx.cr6.eq) goto loc_82081C68;
	// lbz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 8);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82081c68
	if (ctx.cr0.eq) goto loc_82081C68;
	// lwz r11,8(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82081a48
	if (!ctx.cr6.eq) goto loc_82081A48;
	// lwz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// rlwinm. r10,r10,0,0,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82081c68
	if (ctx.cr0.eq) goto loc_82081C68;
loc_82081A48:
	// lwz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// rlwinm. r9,r10,0,0,0
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// bne 0x82081a5c
	if (!ctx.cr0.eq) goto loc_82081A5C;
	// add r28,r11,r4
	ctx.r28.u64 = ctx.r11.u64 + ctx.r4.u64;
loc_82081A5C:
	// nop 
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// rlwinm. r11,r10,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// beq 0x82081ae4
	if (ctx.cr0.eq) goto loc_82081AE4;
	// bl 0x820852b0
	ctx.lr = 0x82081A7C;
	sub_820852B0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82081c48
	if (ctx.cr0.eq) goto loc_82081C48;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820852b0
	ctx.lr = 0x82081A90;
	sub_820852B0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82081c48
	if (ctx.cr0.eq) goto loc_82081C48;
	// lwz r10,24(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// addi r11,r30,8
	ctx.r11.s64 = ctx.r30.s64 + 8;
	// stw r10,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r10.u32);
	// lwz r8,12(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stw r9,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r9.u32);
	// blt cr6,0x82081adc
	if (ctx.cr6.lt) goto loc_82081ADC;
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwzx r10,r8,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// lwzx r11,r10,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r9,r8,r11
	ctx.r9.u64 = ctx.r8.u64 + ctx.r11.u64;
	// stw r11,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
	// stw r9,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r9.u32);
loc_82081ADC:
	// stw r9,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r9.u32);
	// b 0x82081c4c
	goto loc_82081C4C;
loc_82081AE4:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82081b7c
	if (ctx.cr0.eq) goto loc_82081B7C;
	// bl 0x820852b0
	ctx.lr = 0x82081AF4;
	sub_820852B0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82081c48
	if (ctx.cr0.eq) goto loc_82081C48;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820852b0
	ctx.lr = 0x82081B08;
	sub_820852B0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82081c48
	if (ctx.cr0.eq) goto loc_82081C48;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r5,20(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// lwz r4,24(r29)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// bl 0x8207d870
	ctx.lr = 0x82081B20;
	sub_8207D870(ctx, base);
	// lwz r11,20(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bne cr6,0x82081c4c
	if (!ctx.cr6.eq) goto loc_82081C4C;
	// lwz r8,0(r28)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82081c4c
	if (ctx.cr6.eq) goto loc_82081C4C;
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// addi r11,r30,8
	ctx.r11.s64 = ctx.r30.s64 + 8;
	// lwz r9,12(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r10,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r10.u32);
	// blt cr6,0x82081b74
	if (ctx.cr6.lt) goto loc_82081B74;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwzx r8,r9,r8
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// lwzx r11,r8,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r10,r9,r11
	ctx.r10.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// stw r10,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r10.u32);
loc_82081B74:
	// stw r10,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r10.u32);
	// b 0x82081c4c
	goto loc_82081C4C;
loc_82081B7C:
	// lwz r11,24(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82081bf8
	if (!ctx.cr6.eq) goto loc_82081BF8;
	// bl 0x820852b0
	ctx.lr = 0x82081B8C;
	sub_820852B0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82081c48
	if (ctx.cr0.eq) goto loc_82081C48;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820852b0
	ctx.lr = 0x82081BA0;
	sub_820852B0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82081c48
	if (ctx.cr0.eq) goto loc_82081C48;
	// lwz r10,24(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// addi r11,r30,8
	ctx.r11.s64 = ctx.r30.s64 + 8;
	// lwz r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r8,12(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// add r4,r9,r10
	ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stw r4,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r4.u32);
	// blt cr6,0x82081be8
	if (ctx.cr6.lt) goto loc_82081BE8;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwzx r11,r10,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// add r4,r9,r11
	ctx.r4.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stw r11,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r11.u32);
	// stw r4,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r4.u32);
loc_82081BE8:
	// lwz r5,20(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8207d870
	ctx.lr = 0x82081BF4;
	sub_8207D870(ctx, base);
	// b 0x82081c4c
	goto loc_82081C4C;
loc_82081BF8:
	// bl 0x820852b0
	ctx.lr = 0x82081BFC;
	sub_820852B0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82081c48
	if (ctx.cr0.eq) goto loc_82081C48;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820852b0
	ctx.lr = 0x82081C10;
	sub_820852B0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82081c48
	if (ctx.cr0.eq) goto loc_82081C48;
	// lwz r3,24(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// bl 0x820852b0
	ctx.lr = 0x82081C20;
	sub_820852B0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82081c48
	if (ctx.cr0.eq) goto loc_82081C48;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// rlwinm r11,r11,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// xori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 ^ 1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// b 0x82081c4c
	goto loc_82081C4C;
loc_82081C48:
	// bl 0x82082590
	ctx.lr = 0x82081C4C;
	sub_82082590(ctx, base);
loc_82081C4C:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x82081c60
	goto loc_82081C60;
	// bl 0x82082530
	ctx.lr = 0x82081C60;
	sub_82082530(ctx, base);
loc_82081C60:
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// b 0x82081c6c
	goto loc_82081C6C;
loc_82081C68:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82081C6C:
	// addi r1,r31,144
	ctx.r1.s64 = ctx.r31.s64 + 144;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82081C74"))) PPC_WEAK_FUNC(sub_82081C74);
PPC_FUNC_IMPL(__imp__sub_82081C74) {
	PPC_FUNC_PROLOGUE();
	// li r3,1
	ctx.r3.s64 = 1;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82081C80"))) PPC_WEAK_FUNC(sub_82081C80);
PPC_FUNC_IMPL(__imp__sub_82081C80) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lwz r16,21428(r29)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r29.u32 + 21428);
	// lwz r16,6960(r5)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r5.u32 + 6960);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82081C90;
	__savegprlr_28(ctx, base);
	// addi r31,r1,-128
	ctx.r31.s64 = ctx.r1.s64 + -128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// lwz r11,0(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// rlwinm. r11,r11,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82081cb4
	if (ctx.cr0.eq) goto loc_82081CB4;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// b 0x82081cbc
	goto loc_82081CBC;
loc_82081CB4:
	// lwz r11,8(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// add r28,r11,r4
	ctx.r28.u64 = ctx.r11.u64 + ctx.r4.u64;
loc_82081CBC:
	// nop 
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820819f8
	ctx.lr = 0x82081CD4;
	sub_820819F8(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// beq cr6,0x82081d3c
	if (ctx.cr6.eq) goto loc_82081D3C;
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// bne cr6,0x82081d8c
	if (!ctx.cr6.eq) goto loc_82081D8C;
	// lwz r10,24(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// addi r11,r29,8
	ctx.r11.s64 = ctx.r29.s64 + 8;
	// lwz r9,8(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// lwz r8,12(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// add r4,r9,r10
	ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stw r4,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r4.u32);
	// blt cr6,0x82081d24
	if (ctx.cr6.lt) goto loc_82081D24;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwzx r11,r10,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// add r4,r9,r11
	ctx.r4.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stw r11,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
	// stw r4,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r4.u32);
loc_82081D24:
	// lwz r11,24(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82081D38;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82081d8c
	goto loc_82081D8C;
loc_82081D3C:
	// lwz r10,24(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// addi r11,r29,8
	ctx.r11.s64 = ctx.r29.s64 + 8;
	// lwz r9,8(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// lwz r8,12(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// add r4,r9,r10
	ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stw r4,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r4.u32);
	// blt cr6,0x82081d7c
	if (ctx.cr6.lt) goto loc_82081D7C;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwzx r11,r10,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// add r4,r9,r11
	ctx.r4.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// stw r4,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r4.u32);
loc_82081D7C:
	// lwz r11,24(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82081D8C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82081D8C:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x82081da0
	goto loc_82081DA0;
	// bl 0x82082530
	ctx.lr = 0x82081DA0;
	sub_82082530(ctx, base);
loc_82081DA0:
	// addi r1,r31,128
	ctx.r1.s64 = ctx.r31.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82081C88"))) PPC_WEAK_FUNC(sub_82081C88);
PPC_FUNC_IMPL(__imp__sub_82081C88) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82081C90;
	__savegprlr_28(ctx, base);
	// addi r31,r1,-128
	ctx.r31.s64 = ctx.r1.s64 + -128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// lwz r11,0(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// rlwinm. r11,r11,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82081cb4
	if (ctx.cr0.eq) goto loc_82081CB4;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// b 0x82081cbc
	goto loc_82081CBC;
loc_82081CB4:
	// lwz r11,8(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// add r28,r11,r4
	ctx.r28.u64 = ctx.r11.u64 + ctx.r4.u64;
loc_82081CBC:
	// nop 
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820819f8
	ctx.lr = 0x82081CD4;
	sub_820819F8(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// beq cr6,0x82081d3c
	if (ctx.cr6.eq) goto loc_82081D3C;
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// bne cr6,0x82081d8c
	if (!ctx.cr6.eq) goto loc_82081D8C;
	// lwz r10,24(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// addi r11,r29,8
	ctx.r11.s64 = ctx.r29.s64 + 8;
	// lwz r9,8(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// lwz r8,12(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// add r4,r9,r10
	ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stw r4,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r4.u32);
	// blt cr6,0x82081d24
	if (ctx.cr6.lt) goto loc_82081D24;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwzx r11,r10,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// add r4,r9,r11
	ctx.r4.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stw r11,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
	// stw r4,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r4.u32);
loc_82081D24:
	// lwz r11,24(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82081D38;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82081d8c
	goto loc_82081D8C;
loc_82081D3C:
	// lwz r10,24(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// addi r11,r29,8
	ctx.r11.s64 = ctx.r29.s64 + 8;
	// lwz r9,8(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// lwz r8,12(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// add r4,r9,r10
	ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stw r4,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r4.u32);
	// blt cr6,0x82081d7c
	if (ctx.cr6.lt) goto loc_82081D7C;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwzx r11,r10,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// add r4,r9,r11
	ctx.r4.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// stw r4,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r4.u32);
loc_82081D7C:
	// lwz r11,24(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82081D8C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82081D8C:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x82081da0
	goto loc_82081DA0;
	// bl 0x82082530
	ctx.lr = 0x82081DA0;
	sub_82082530(ctx, base);
loc_82081DA0:
	// addi r1,r31,128
	ctx.r1.s64 = ctx.r31.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82081DA8"))) PPC_WEAK_FUNC(sub_82081DA8);
PPC_FUNC_IMPL(__imp__sub_82081DA8) {
	PPC_FUNC_PROLOGUE();
	// li r3,1
	ctx.r3.s64 = 1;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82081DB4"))) PPC_WEAK_FUNC(sub_82081DB4);
PPC_FUNC_IMPL(__imp__sub_82081DB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82081DB8"))) PPC_WEAK_FUNC(sub_82081DB8);
PPC_FUNC_IMPL(__imp__sub_82081DB8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c96c
	ctx.lr = 0x82081DC0;
	__savegprlr_21(ctx, base);
	// stwu r1,-2832(r1)
	ea = -2832 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// mr r31,r7
	ctx.r31.u64 = ctx.r7.u64;
	// mr r24,r8
	ctx.r24.u64 = ctx.r8.u64;
	// mr r23,r9
	ctx.r23.u64 = ctx.r9.u64;
	// mr r25,r10
	ctx.r25.u64 = ctx.r10.u64;
	// bl 0x8207cae0
	ctx.lr = 0x82081DF0;
	sub_8207CAE0(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8207cb08
	ctx.lr = 0x82081E00;
	sub_8207CB08(ctx, base);
	// mr. r22,r3
	ctx.r22.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// li r21,0
	ctx.r21.s64 = 0;
	// bne 0x82081e28
	if (!ctx.cr0.eq) goto loc_82081E28;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// li r10,-2
	ctx.r10.s64 = -2;
	// stw r21,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r21.u32);
	// stw r11,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stw r21,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r21.u32);
loc_82081E28:
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x82081e44
	if (ctx.cr6.eq) goto loc_82081E44;
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82081c88
	ctx.lr = 0x82081E44;
	sub_82081C88(ctx, base);
loc_82081E44:
	// bl 0x820811c8
	ctx.lr = 0x82081E48;
	sub_820811C8(ctx, base);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// stw r11,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r11.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8207cf30
	ctx.lr = 0x82081E5C;
	sub_8207CF30(ctx, base);
	// lwz r11,2916(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2916);
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bne cr6,0x82081e74
	if (!ctx.cr6.eq) goto loc_82081E74;
	// lwz r3,8(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
loc_82081E74:
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x820852d0
	ctx.lr = 0x82081E80;
	sub_820852D0(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r6,0(r25)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82081658
	ctx.lr = 0x82081E94;
	sub_82081658(ctx, base);
	// lwz r11,4(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 4);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r6,r11,1
	ctx.r6.s64 = ctx.r11.s64 + 1;
	// bl 0x82081500
	ctx.lr = 0x82081EAC;
	sub_82081500(ctx, base);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// bl 0x820811c8
	ctx.lr = 0x82081EB4;
	sub_820811C8(ctx, base);
	// lwz r10,140(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// mr r9,r23
	ctx.r9.u64 = ctx.r23.u64;
	// lwz r7,12(r24)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r24.u32 + 12);
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8208537c
	ctx.lr = 0x82081ED8;
	sub_8208537C(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82081ef4
	if (ctx.cr0.eq) goto loc_82081EF4;
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// bne cr6,0x82081eec
	if (!ctx.cr6.eq) goto loc_82081EEC;
	// stw r21,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r21.u32);
loc_82081EEC:
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// bl 0x820851ec
	ctx.lr = 0x82081EF4;
	sub_820851EC(ctx, base);
loc_82081EF4:
	// addi r1,r1,2832
	ctx.r1.s64 = ctx.r1.s64 + 2832;
	// b 0x8207c9bc
	__restgprlr_21(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82081EFC"))) PPC_WEAK_FUNC(sub_82081EFC);
PPC_FUNC_IMPL(__imp__sub_82081EFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82081F00"))) PPC_WEAK_FUNC(sub_82081F00);
PPC_FUNC_IMPL(__imp__sub_82081F00) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x82081F08;
	__savegprlr_24(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32768
	ctx.r11.s64 = -2147483648;
	// mr r25,r10
	ctx.r25.u64 = ctx.r10.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// ori r11,r11,3
	ctx.r11.u64 = ctx.r11.u64 | 3;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// mr r24,r8
	ctx.r24.u64 = ctx.r8.u64;
	// mr r31,r9
	ctx.r31.u64 = ctx.r9.u64;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82082058
	if (ctx.cr6.eq) goto loc_82082058;
	// bl 0x820811c8
	ctx.lr = 0x82081F44;
	sub_820811C8(ctx, base);
	// lwz r11,116(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82081f9c
	if (ctx.cr6.eq) goto loc_82081F9C;
	// bl 0x820811c8
	ctx.lr = 0x82081F54;
	sub_820811C8(ctx, base);
	// lwz r11,116(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82081f9c
	if (ctx.cr6.eq) goto loc_82081F9C;
	// lis r11,-8125
	ctx.r11.s64 = -532480000;
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// ori r11,r11,20301
	ctx.r11.u64 = ctx.r11.u64 | 20301;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82081f9c
	if (ctx.cr6.eq) goto loc_82081F9C;
	// mr r9,r25
	ctx.r9.u64 = ctx.r25.u64;
	// mr r8,r31
	ctx.r8.u64 = ctx.r31.u64;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8207cd18
	ctx.lr = 0x82081F94;
	sub_8207CD18(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x82082058
	if (!ctx.cr0.eq) goto loc_82082058;
loc_82081F9C:
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82081fac
	if (!ctx.cr6.eq) goto loc_82081FAC;
	// bl 0x82082590
	ctx.lr = 0x82081FAC;
	sub_82082590(ctx, base);
loc_82081FAC:
	// mr r8,r28
	ctx.r8.u64 = ctx.r28.u64;
	// addi r7,r1,100
	ctx.r7.s64 = ctx.r1.s64 + 100;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8207cdd8
	ctx.lr = 0x82081FC8;
	sub_8207CDD8(ctx, base);
	// lwz r9,96(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x8208204c
	goto loc_8208204C;
loc_82081FD4:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpw cr6,r24,r11
	ctx.cr6.compare<int32_t>(ctx.r24.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x82082040
	if (ctx.cr6.lt) goto loc_82082040;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpw cr6,r24,r11
	ctx.cr6.compare<int32_t>(ctx.r24.s32, ctx.r11.s32, ctx.xer);
	// bgt cr6,0x82082040
	if (ctx.cr6.gt) goto loc_82082040;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,-12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -12);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82082014
	if (ctx.cr6.eq) goto loc_82082014;
	// lbz r10,8(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 8);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x82082040
	if (!ctx.cr0.eq) goto loc_82082040;
loc_82082014:
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// stw r25,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r25.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r11,-16
	ctx.r8.s64 = ctx.r11.s64 + -16;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82081db8
	ctx.lr = 0x8208203C;
	sub_82081DB8(ctx, base);
	// lwz r9,96(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
loc_82082040:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r31,r31,20
	ctx.r31.s64 = ctx.r31.s64 + 20;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
loc_8208204C:
	// lwz r11,100(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82081fd4
	if (ctx.cr6.lt) goto loc_82081FD4;
loc_82082058:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82082060"))) PPC_WEAK_FUNC(sub_82082060);
PPC_FUNC_IMPL(__imp__sub_82082060) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c964
	ctx.lr = 0x82082068;
	__savegprlr_19(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r4
	ctx.r23.u64 = ctx.r4.u64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r20,r5
	ctx.r20.u64 = ctx.r5.u64;
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// mr r22,r6
	ctx.r22.u64 = ctx.r6.u64;
	// mr r24,r7
	ctx.r24.u64 = ctx.r7.u64;
	// mr r25,r8
	ctx.r25.u64 = ctx.r8.u64;
	// mr r26,r9
	ctx.r26.u64 = ctx.r9.u64;
	// mr r19,r10
	ctx.r19.u64 = ctx.r10.u64;
	// bl 0x820814c0
	ctx.lr = 0x8208209C;
	sub_820814C0(ctx, base);
	// mr r21,r3
	ctx.r21.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// blt cr6,0x820820b4
	if (ctx.cr6.lt) goto loc_820820B4;
	// lwz r11,4(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 4);
	// cmpw cr6,r3,r11
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x820820b8
	if (ctx.cr6.lt) goto loc_820820B8;
loc_820820B4:
	// bl 0x82082590
	ctx.lr = 0x820820B8;
	sub_82082590(ctx, base);
loc_820820B8:
	// lis r11,-8083
	ctx.r11.s64 = -529727488;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// ori r28,r11,29539
	ctx.r28.u64 = ctx.r11.u64 | 29539;
	// cmplw cr6,r10,r28
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r28.u32, ctx.xer);
	// bne cr6,0x820822c4
	if (!ctx.cr6.eq) goto loc_820822C4;
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// lis r10,6547
	ctx.r10.s64 = 429064192;
	// lis r9,6547
	ctx.r9.s64 = 429064192;
	// lis r8,6547
	ctx.r8.s64 = 429064192;
	// ori r31,r10,1312
	ctx.r31.u64 = ctx.r10.u64 | 1312;
	// ori r29,r9,1313
	ctx.r29.u64 = ctx.r9.u64 | 1313;
	// ori r27,r8,1314
	ctx.r27.u64 = ctx.r8.u64 | 1314;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x82082194
	if (!ctx.cr6.eq) goto loc_82082194;
	// lwz r11,20(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x8208210c
	if (ctx.cr6.eq) goto loc_8208210C;
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x8208210c
	if (ctx.cr6.eq) goto loc_8208210C;
	// cmplw cr6,r11,r27
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r27.u32, ctx.xer);
	// bne cr6,0x82082194
	if (!ctx.cr6.eq) goto loc_82082194;
loc_8208210C:
	// lwz r11,28(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82082194
	if (!ctx.cr6.eq) goto loc_82082194;
	// bl 0x820811c8
	ctx.lr = 0x8208211C;
	sub_820811C8(ctx, base);
	// lwz r11,124(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820822bc
	if (ctx.cr6.eq) goto loc_820822BC;
	// bl 0x820811c8
	ctx.lr = 0x8208212C;
	sub_820811C8(ctx, base);
	// lwz r30,124(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// bl 0x820811c8
	ctx.lr = 0x82082134;
	sub_820811C8(ctx, base);
	// lwz r20,128(r3)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820852b0
	ctx.lr = 0x82082144;
	sub_820852B0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x82082150
	if (!ctx.cr0.eq) goto loc_82082150;
	// bl 0x82082590
	ctx.lr = 0x82082150;
	sub_82082590(ctx, base);
loc_82082150:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// bne cr6,0x820822c4
	if (!ctx.cr6.eq) goto loc_820822C4;
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x82082194
	if (!ctx.cr6.eq) goto loc_82082194;
	// lwz r11,20(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x82082184
	if (ctx.cr6.eq) goto loc_82082184;
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x82082184
	if (ctx.cr6.eq) goto loc_82082184;
	// cmplw cr6,r11,r27
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r27.u32, ctx.xer);
	// bne cr6,0x82082194
	if (!ctx.cr6.eq) goto loc_82082194;
loc_82082184:
	// lwz r11,28(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82082194
	if (!ctx.cr6.eq) goto loc_82082194;
	// bl 0x82082590
	ctx.lr = 0x82082194;
	sub_82082590(ctx, base);
loc_82082194:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// bne cr6,0x820822c4
	if (!ctx.cr6.eq) goto loc_820822C4;
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x820822c4
	if (!ctx.cr6.eq) goto loc_820822C4;
	// lwz r11,20(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x820821c8
	if (ctx.cr6.eq) goto loc_820821C8;
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x820821c8
	if (ctx.cr6.eq) goto loc_820821C8;
	// cmplw cr6,r11,r27
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r27.u32, ctx.xer);
	// bne cr6,0x820822c4
	if (!ctx.cr6.eq) goto loc_820822C4;
loc_820821C8:
	// lwz r11,12(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x820822bc
	if (!ctx.cr6.gt) goto loc_820822BC;
	// mr r8,r22
	ctx.r8.u64 = ctx.r22.u64;
	// addi r7,r1,100
	ctx.r7.s64 = ctx.r1.s64 + 100;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r5,r21
	ctx.r5.u64 = ctx.r21.u64;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x8207cdd8
	ctx.lr = 0x820821F0;
	sub_8207CDD8(ctx, base);
	// lwz r25,96(r1)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x820822b0
	goto loc_820822B0;
loc_820821FC:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpw cr6,r11,r21
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r21.s32, ctx.xer);
	// bgt cr6,0x820822a4
	if (ctx.cr6.gt) goto loc_820822A4;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpw cr6,r21,r11
	ctx.cr6.compare<int32_t>(ctx.r21.s32, ctx.r11.s32, ctx.xer);
	// bgt cr6,0x820822a4
	if (ctx.cr6.gt) goto loc_820822A4;
	// lwz r26,12(r31)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r7,16(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// ble cr6,0x820822a4
	if (!ctx.cr6.gt) goto loc_820822A4;
	// lwz r11,28(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	// lwz r11,12(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r27,r11,4
	ctx.r27.s64 = ctx.r11.s64 + 4;
	// lwz r28,0(r11)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
loc_82082234:
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// cmpwi r28,0
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// ble 0x82082268
	if (!ctx.cr0.gt) goto loc_82082268;
	// lwz r5,28(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 28);
loc_82082248:
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// lwz r4,0(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// bl 0x82081520
	ctx.lr = 0x82082254;
	sub_82081520(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x82082278
	if (!ctx.cr0.eq) goto loc_82082278;
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// bgt 0x82082248
	if (ctx.cr0.gt) goto loc_82082248;
loc_82082268:
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// addi r7,r7,16
	ctx.r7.s64 = ctx.r7.s64 + 16;
	// bgt 0x82082234
	if (ctx.cr0.gt) goto loc_82082234;
	// b 0x820822a4
	goto loc_820822A4;
loc_82082278:
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// stw r19,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r19.u32);
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
	// mr r6,r22
	ctx.r6.u64 = ctx.r22.u64;
	// mr r5,r20
	ctx.r5.u64 = ctx.r20.u64;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82081db8
	ctx.lr = 0x820822A0;
	sub_82081DB8(ctx, base);
	// lwz r25,96(r1)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
loc_820822A4:
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// addi r31,r31,20
	ctx.r31.s64 = ctx.r31.s64 + 20;
	// stw r25,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r25.u32);
loc_820822B0:
	// lwz r11,100(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmplw cr6,r25,r11
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x820821fc
	if (ctx.cr6.lt) goto loc_820821FC;
loc_820822BC:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9b4
	__restgprlr_19(ctx, base);
	return;
loc_820822C4:
	// lwz r11,12(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x820822bc
	if (!ctx.cr6.gt) goto loc_820822BC;
	// clrlwi. r11,r25,24
	ctx.r11.u64 = ctx.r25.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82082300
	if (!ctx.cr0.eq) goto loc_82082300;
	// mr r10,r19
	ctx.r10.u64 = ctx.r19.u64;
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
	// mr r8,r21
	ctx.r8.u64 = ctx.r21.u64;
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
	// mr r6,r22
	ctx.r6.u64 = ctx.r22.u64;
	// mr r5,r20
	ctx.r5.u64 = ctx.r20.u64;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82081f00
	ctx.lr = 0x820822FC;
	sub_82081F00(ctx, base);
	// b 0x820822bc
	goto loc_820822BC;
loc_82082300:
	// bl 0x82082530
	ctx.lr = 0x82082304;
	sub_82082530(ctx, base);
}

__attribute__((alias("__imp__sub_82082304"))) PPC_WEAK_FUNC(sub_82082304);
PPC_FUNC_IMPL(__imp__sub_82082304) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// .long 0x0
	// lwz r16,21428(r29)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r29.u32 + 21428);
	// lwz r16,6984(r5)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r5.u32 + 6984);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82082318;
	__savegprlr_27(ctx, base);
	// addi r31,r1,-144
	ctx.r31.s64 = ctx.r1.s64 + -144;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// andi. r7,r10,102
	ctx.r7.u64 = ctx.r10.u64 & 102;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// cmplwi r7,0
	ctx.cr0.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq 0x8208247c
	if (ctx.cr0.eq) goto loc_8208247C;
	// lwz r11,4(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8208250c
	if (ctx.cr6.eq) goto loc_8208250C;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x8208250c
	if (!ctx.cr6.eq) goto loc_8208250C;
	// rlwinm. r11,r10,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820823d4
	if (ctx.cr0.eq) goto loc_820823D4;
	// bl 0x8207cab8
	ctx.lr = 0x82082364;
	sub_8207CAB8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x820823d4
	if (ctx.cr0.eq) goto loc_820823D4;
	// bl 0x820811c8
	ctx.lr = 0x82082370;
	sub_820811C8(ctx, base);
	// lwz r11,140(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82082380
	if (!ctx.cr6.eq) goto loc_82082380;
	// bl 0x82082590
	ctx.lr = 0x82082380;
	sub_82082590(ctx, base);
loc_82082380:
	// bl 0x820811c8
	ctx.lr = 0x82082384;
	sub_820811C8(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r3,140(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// bl 0x8207cb00
	ctx.lr = 0x82082390;
	sub_8207CB00(ctx, base);
	// lwz r29,0(r30)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x820811c8
	ctx.lr = 0x82082398;
	sub_820811C8(ctx, base);
	// lwz r11,140(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// std r29,48(r11)
	PPC_STORE_U64(ctx.r11.u32 + 48, ctx.r29.u64);
	// lwz r29,4(r30)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x820811c8
	ctx.lr = 0x820823A8;
	sub_820811C8(ctx, base);
	// lwz r11,140(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// std r29,56(r11)
	PPC_STORE_U64(ctx.r11.u32 + 56, ctx.r29.u64);
	// lwz r30,8(r30)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// bl 0x820811c8
	ctx.lr = 0x820823B8;
	sub_820811C8(ctx, base);
	// lwz r11,140(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// std r30,64(r11)
	PPC_STORE_U64(ctx.r11.u32 + 64, ctx.r30.u64);
	// bl 0x8207cab8
	ctx.lr = 0x820823C4;
	sub_8207CAB8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8207cb00
	ctx.lr = 0x820823D0;
	sub_8207CB00(ctx, base);
	// b 0x8208250c
	goto loc_8208250C;
loc_820823D4:
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8207cb98
	ctx.lr = 0x820823E4;
	sub_8207CB98(ctx, base);
	// lwz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8208250c
	if (ctx.cr6.eq) goto loc_8208250C;
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r29,4(r11)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// stw r29,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r29.u32);
	// beq cr6,0x8208250c
	if (ctx.cr6.eq) goto loc_8208250C;
	// lwz r30,8(r29)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8208250c
	if (ctx.cr6.eq) goto loc_8208250C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r30,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r30.u32);
	// bl 0x8207d040
	ctx.lr = 0x8208241C;
	sub_8207D040(ctx, base);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x8207cfe8
	ctx.lr = 0x82082424;
	sub_8207CFE8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82082470
	if (ctx.cr0.eq) goto loc_82082470;
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82082470
	if (ctx.cr6.eq) goto loc_82082470;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8208244C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x82082468
	goto loc_82082468;
	// bl 0x82082530
	ctx.lr = 0x82082460;
	sub_82082530(ctx, base);
	// lwz r29,80(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r30,84(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
loc_82082468:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
loc_82082470:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,8(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8, ctx.r11.u32);
	// b 0x8208250c
	goto loc_8208250C;
loc_8208247C:
	// lwz r10,12(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8208250c
	if (ctx.cr6.eq) goto loc_8208250C;
	// lis r10,-8083
	ctx.r10.s64 = -529727488;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// ori r10,r10,29539
	ctx.r10.u64 = ctx.r10.u64 | 29539;
	// cmplw cr6,r7,r10
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x820824ec
	if (!ctx.cr6.eq) goto loc_820824EC;
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// blt cr6,0x820824ec
	if (ctx.cr6.lt) goto loc_820824EC;
	// lis r10,6547
	ctx.r10.s64 = 429064192;
	// lwz r7,20(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// ori r10,r10,1314
	ctx.r10.u64 = ctx.r10.u64 | 1314;
	// cmplw cr6,r7,r10
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x820824ec
	if (!ctx.cr6.gt) goto loc_820824EC;
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r7,8(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x820824ec
	if (ctx.cr6.eq) goto loc_820824EC;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// clrlwi r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bctrl 
	ctx.lr = 0x820824E8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82082510
	goto loc_82082510;
loc_820824EC:
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82082060
	ctx.lr = 0x8208250C;
	sub_82082060(ctx, base);
loc_8208250C:
	// li r3,1
	ctx.r3.s64 = 1;
loc_82082510:
	// addi r1,r31,144
	ctx.r1.s64 = ctx.r31.s64 + 144;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82082310"))) PPC_WEAK_FUNC(sub_82082310);
PPC_FUNC_IMPL(__imp__sub_82082310) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82082318;
	__savegprlr_27(ctx, base);
	// addi r31,r1,-144
	ctx.r31.s64 = ctx.r1.s64 + -144;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// andi. r7,r10,102
	ctx.r7.u64 = ctx.r10.u64 & 102;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// cmplwi r7,0
	ctx.cr0.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq 0x8208247c
	if (ctx.cr0.eq) goto loc_8208247C;
	// lwz r11,4(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8208250c
	if (ctx.cr6.eq) goto loc_8208250C;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x8208250c
	if (!ctx.cr6.eq) goto loc_8208250C;
	// rlwinm. r11,r10,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820823d4
	if (ctx.cr0.eq) goto loc_820823D4;
	// bl 0x8207cab8
	ctx.lr = 0x82082364;
	sub_8207CAB8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x820823d4
	if (ctx.cr0.eq) goto loc_820823D4;
	// bl 0x820811c8
	ctx.lr = 0x82082370;
	sub_820811C8(ctx, base);
	// lwz r11,140(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82082380
	if (!ctx.cr6.eq) goto loc_82082380;
	// bl 0x82082590
	ctx.lr = 0x82082380;
	sub_82082590(ctx, base);
loc_82082380:
	// bl 0x820811c8
	ctx.lr = 0x82082384;
	sub_820811C8(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r3,140(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// bl 0x8207cb00
	ctx.lr = 0x82082390;
	sub_8207CB00(ctx, base);
	// lwz r29,0(r30)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x820811c8
	ctx.lr = 0x82082398;
	sub_820811C8(ctx, base);
	// lwz r11,140(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// std r29,48(r11)
	PPC_STORE_U64(ctx.r11.u32 + 48, ctx.r29.u64);
	// lwz r29,4(r30)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x820811c8
	ctx.lr = 0x820823A8;
	sub_820811C8(ctx, base);
	// lwz r11,140(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// std r29,56(r11)
	PPC_STORE_U64(ctx.r11.u32 + 56, ctx.r29.u64);
	// lwz r30,8(r30)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// bl 0x820811c8
	ctx.lr = 0x820823B8;
	sub_820811C8(ctx, base);
	// lwz r11,140(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// std r30,64(r11)
	PPC_STORE_U64(ctx.r11.u32 + 64, ctx.r30.u64);
	// bl 0x8207cab8
	ctx.lr = 0x820823C4;
	sub_8207CAB8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8207cb00
	ctx.lr = 0x820823D0;
	sub_8207CB00(ctx, base);
	// b 0x8208250c
	goto loc_8208250C;
loc_820823D4:
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8207cb98
	ctx.lr = 0x820823E4;
	sub_8207CB98(ctx, base);
	// lwz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8208250c
	if (ctx.cr6.eq) goto loc_8208250C;
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r29,4(r11)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// stw r29,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r29.u32);
	// beq cr6,0x8208250c
	if (ctx.cr6.eq) goto loc_8208250C;
	// lwz r30,8(r29)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8208250c
	if (ctx.cr6.eq) goto loc_8208250C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r30,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r30.u32);
	// bl 0x8207d040
	ctx.lr = 0x8208241C;
	sub_8207D040(ctx, base);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x8207cfe8
	ctx.lr = 0x82082424;
	sub_8207CFE8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82082470
	if (ctx.cr0.eq) goto loc_82082470;
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82082470
	if (ctx.cr6.eq) goto loc_82082470;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8208244C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x82082468
	goto loc_82082468;
	// bl 0x82082530
	ctx.lr = 0x82082460;
	sub_82082530(ctx, base);
	// lwz r29,80(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r30,84(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
loc_82082468:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
loc_82082470:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,8(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8, ctx.r11.u32);
	// b 0x8208250c
	goto loc_8208250C;
loc_8208247C:
	// lwz r10,12(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8208250c
	if (ctx.cr6.eq) goto loc_8208250C;
	// lis r10,-8083
	ctx.r10.s64 = -529727488;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// ori r10,r10,29539
	ctx.r10.u64 = ctx.r10.u64 | 29539;
	// cmplw cr6,r7,r10
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x820824ec
	if (!ctx.cr6.eq) goto loc_820824EC;
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// blt cr6,0x820824ec
	if (ctx.cr6.lt) goto loc_820824EC;
	// lis r10,6547
	ctx.r10.s64 = 429064192;
	// lwz r7,20(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// ori r10,r10,1314
	ctx.r10.u64 = ctx.r10.u64 | 1314;
	// cmplw cr6,r7,r10
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x820824ec
	if (!ctx.cr6.gt) goto loc_820824EC;
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r7,8(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x820824ec
	if (ctx.cr6.eq) goto loc_820824EC;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// clrlwi r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bctrl 
	ctx.lr = 0x820824E8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82082510
	goto loc_82082510;
loc_820824EC:
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82082060
	ctx.lr = 0x8208250C;
	sub_82082060(ctx, base);
loc_8208250C:
	// li r3,1
	ctx.r3.s64 = 1;
loc_82082510:
	// addi r1,r31,144
	ctx.r1.s64 = ctx.r31.s64 + 144;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82082518"))) PPC_WEAK_FUNC(sub_82082518);
PPC_FUNC_IMPL(__imp__sub_82082518) {
	PPC_FUNC_PROLOGUE();
	// li r3,1
	ctx.r3.s64 = 1;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82082524"))) PPC_WEAK_FUNC(sub_82082524);
PPC_FUNC_IMPL(__imp__sub_82082524) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82082528"))) PPC_WEAK_FUNC(sub_82082528);
PPC_FUNC_IMPL(__imp__sub_82082528) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lwz r16,21428(r29)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r29.u32 + 21428);
	// lwz r16,7008(r5)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r5.u32 + 7008);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// addi r31,r1,-96
	ctx.r31.s64 = ctx.r1.s64 + -96;
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x820811c8
	ctx.lr = 0x82082548;
	sub_820811C8(ctx, base);
	// lwz r11,108(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 108);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82082570
	if (ctx.cr6.eq) goto loc_82082570;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82082564;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
loc_82082570:
	// lis r3,-16384
	ctx.r3.s64 = -1073741824;
	// ori r3,r3,324
	ctx.r3.u64 = ctx.r3.u64 | 324;
	// bl 0x821d53c4
	ctx.lr = 0x8208257C;
	__imp__KeBugCheck(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82082530"))) PPC_WEAK_FUNC(sub_82082530);
PPC_FUNC_IMPL(__imp__sub_82082530) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// addi r31,r1,-96
	ctx.r31.s64 = ctx.r1.s64 + -96;
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x820811c8
	ctx.lr = 0x82082548;
	sub_820811C8(ctx, base);
	// lwz r11,108(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 108);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82082570
	if (ctx.cr6.eq) goto loc_82082570;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82082564;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
loc_82082570:
	// lis r3,-16384
	ctx.r3.s64 = -1073741824;
	// ori r3,r3,324
	ctx.r3.u64 = ctx.r3.u64 | 324;
	// bl 0x821d53c4
	ctx.lr = 0x8208257C;
	__imp__KeBugCheck(ctx, base);
}

__attribute__((alias("__imp__sub_8208257C"))) PPC_WEAK_FUNC(sub_8208257C);
PPC_FUNC_IMPL(__imp__sub_8208257C) {
	PPC_FUNC_PROLOGUE();
	// li r3,1
	ctx.r3.s64 = 1;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82082588"))) PPC_WEAK_FUNC(sub_82082588);
PPC_FUNC_IMPL(__imp__sub_82082588) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lwz r16,21428(r29)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r29.u32 + 21428);
	// lwz r16,7032(r5)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r5.u32 + 7032);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// addi r31,r1,-96
	ctx.r31.s64 = ctx.r1.s64 + -96;
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lwz r11,-11776(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11776);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x820825d0
	if (ctx.cr0.eq) goto loc_820825D0;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820825C4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
loc_820825D0:
	// bl 0x82082530
	ctx.lr = 0x820825D4;
	sub_82082530(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82082590"))) PPC_WEAK_FUNC(sub_82082590);
PPC_FUNC_IMPL(__imp__sub_82082590) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// addi r31,r1,-96
	ctx.r31.s64 = ctx.r1.s64 + -96;
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lwz r11,-11776(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11776);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x820825d0
	if (ctx.cr0.eq) goto loc_820825D0;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820825C4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
loc_820825D0:
	// bl 0x82082530
	ctx.lr = 0x820825D4;
	sub_82082530(ctx, base);
}

__attribute__((alias("__imp__sub_820825D4"))) PPC_WEAK_FUNC(sub_820825D4);
PPC_FUNC_IMPL(__imp__sub_820825D4) {
	PPC_FUNC_PROLOGUE();
	// li r3,1
	ctx.r3.s64 = 1;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820825E0"))) PPC_WEAK_FUNC(sub_820825E0);
PPC_FUNC_IMPL(__imp__sub_820825E0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32248
	ctx.r11.s64 = -2113404928;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// addi r11,r11,9520
	ctx.r11.s64 = ctx.r11.s64 + 9520;
	// stw r11,-11776(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11776, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820825F4"))) PPC_WEAK_FUNC(sub_820825F4);
PPC_FUNC_IMPL(__imp__sub_820825F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820825F8"))) PPC_WEAK_FUNC(sub_820825F8);
PPC_FUNC_IMPL(__imp__sub_820825F8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// stw r3,-11772(r11)
	PPC_STORE_U32(ctx.r11.u32 + -11772, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82082604"))) PPC_WEAK_FUNC(sub_82082604);
PPC_FUNC_IMPL(__imp__sub_82082604) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// .long 0x0
	// lwz r16,21428(r29)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r29.u32 + 21428);
	// lwz r16,7056(r5)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r5.u32 + 7056);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// addi r31,r1,-112
	ctx.r31.s64 = ctx.r1.s64 + -112;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// nop 
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// bl 0x821d5424
	ctx.lr = 0x82082634;
	__imp__RtlInitializeCriticalSectionAndSpinCount(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r3,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r3.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x8208266c
	goto loc_8208266C;
	// lis r11,-16384
	ctx.r11.s64 = -1073741824;
	// ori r11,r11,23
	ctx.r11.u64 = ctx.r11.u64 | 23;
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82082664
	if (!ctx.cr6.eq) goto loc_82082664;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x8208da08
	ctx.lr = 0x82082664;
	sub_8208DA08(ctx, base);
loc_82082664:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r3,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r3.u32);
loc_8208266C:
	// addi r1,r31,112
	ctx.r1.s64 = ctx.r31.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82082610"))) PPC_WEAK_FUNC(sub_82082610);
PPC_FUNC_IMPL(__imp__sub_82082610) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// addi r31,r1,-112
	ctx.r31.s64 = ctx.r1.s64 + -112;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// nop 
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// bl 0x821d5424
	ctx.lr = 0x82082634;
	__imp__RtlInitializeCriticalSectionAndSpinCount(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r3,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r3.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x8208266c
	goto loc_8208266C;
	// lis r11,-16384
	ctx.r11.s64 = -1073741824;
	// ori r11,r11,23
	ctx.r11.u64 = ctx.r11.u64 | 23;
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82082664
	if (!ctx.cr6.eq) goto loc_82082664;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x8208da08
	ctx.lr = 0x82082664;
	sub_8208DA08(ctx, base);
loc_82082664:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r3,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r3.u32);
loc_8208266C:
	// addi r1,r31,112
	ctx.r1.s64 = ctx.r31.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82082680"))) PPC_WEAK_FUNC(sub_82082680);
PPC_FUNC_IMPL(__imp__sub_82082680) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-16384
	ctx.r11.s64 = -1073741824;
	// ori r11,r11,23
	ctx.r11.u64 = ctx.r11.u64 | 23;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820826A4"))) PPC_WEAK_FUNC(sub_820826A4);
PPC_FUNC_IMPL(__imp__sub_820826A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820826A8"))) PPC_WEAK_FUNC(sub_820826A8);
PPC_FUNC_IMPL(__imp__sub_820826A8) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,-23376(r10)
	PPC_STORE_U32(ctx.r10.u32 + -23376, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820826B8"))) PPC_WEAK_FUNC(sub_820826B8);
PPC_FUNC_IMPL(__imp__sub_820826B8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x820826C0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r30,-4096
	ctx.r30.s64 = -4096;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82082710
	if (ctx.cr6.eq) goto loc_82082710;
	// divwu r11,r30,r3
	ctx.r11.u32 = ppc_divwu(ctx.r30.u32, ctx.r3.u32);
	// twllei r3,0
	// cmplw cr6,r11,r4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r4.u32, ctx.xer);
	// bge cr6,0x82082710
	if (!ctx.cr6.lt) goto loc_82082710;
	// bl 0x8207d4d8
	ctx.lr = 0x820826E8;
	sub_8207D4D8(ctx, base);
	// li r11,12
	ctx.r11.s64 = 12;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d940
	ctx.lr = 0x82082708;
	sub_8207D940(ctx, base);
loc_82082708:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82082784
	goto loc_82082784;
loc_82082710:
	// mullw. r31,r3,r4
	ctx.r31.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r4.s32);
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x8208271c
	if (!ctx.cr0.eq) goto loc_8208271C;
	// li r31,1
	ctx.r31.s64 = 1;
loc_8208271C:
	// lis r29,-32225
	ctx.r29.s64 = -2111897600;
loc_82082720:
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bgt cr6,0x82082744
	if (ctx.cr6.gt) goto loc_82082744;
	// bl 0x8208d8f8
	ctx.lr = 0x82082730;
	sub_8208D8F8(ctx, base);
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// bl 0x8208c458
	ctx.lr = 0x8208273C;
	sub_8208C458(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x82082784
	if (!ctx.cr0.eq) goto loc_82082784;
loc_82082744:
	// lwz r11,-12276(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -12276);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82082774
	if (ctx.cr6.eq) goto loc_82082774;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207a4d8
	ctx.lr = 0x82082758;
	sub_8207A4D8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x82082720
	if (!ctx.cr0.eq) goto loc_82082720;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x82082708
	if (ctx.cr6.eq) goto loc_82082708;
	// li r11,12
	ctx.r11.s64 = 12;
	// stw r11,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
	// b 0x82082708
	goto loc_82082708;
loc_82082774:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x82082784
	if (ctx.cr6.eq) goto loc_82082784;
	// li r11,12
	ctx.r11.s64 = 12;
	// stw r11,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
loc_82082784:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8208278C"))) PPC_WEAK_FUNC(sub_8208278C);
PPC_FUNC_IMPL(__imp__sub_8208278C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82082790"))) PPC_WEAK_FUNC(sub_82082790);
PPC_FUNC_IMPL(__imp__sub_82082790) {
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
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// bl 0x82084cb0
	ctx.lr = 0x820827B4;
	sub_82084CB0(ctx, base);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x820827d4
	if (!ctx.cr6.eq) goto loc_820827D4;
	// bl 0x8207d4d8
	ctx.lr = 0x820827C0;
	sub_8207D4D8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,9
	ctx.r10.s64 = 9;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// b 0x82082840
	goto loc_82082840;
loc_820827D4:
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x82089528
	ctx.lr = 0x820827E4;
	sub_82089528(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x82082808
	if (!ctx.cr6.eq) goto loc_82082808;
	// bl 0x82089a10
	ctx.lr = 0x820827F4;
	sub_82089A10(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82082808
	if (ctx.cr0.eq) goto loc_82082808;
	// bl 0x8207d548
	ctx.lr = 0x82082800;
	sub_8207D548(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x82082840
	goto loc_82082840;
loc_82082808:
	// srawi r11,r31,5
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r31.s32 >> 5;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,-23360
	ctx.r10.s64 = ctx.r10.s64 + -23360;
	// clrlwi r11,r31,27
	ctx.r11.u64 = ctx.r31.u32 & 0x1F;
	// mulli r11,r11,72
	ctx.r11.s64 = ctx.r11.s64 * 72;
	// lwzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// rlwinm r10,r10,0,31,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// stb r10,4(r11)
	PPC_STORE_U8(ctx.r11.u32 + 4, ctx.r10.u8);
	// ld r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
loc_82082840:
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

__attribute__((alias("__imp__sub_82082858"))) PPC_WEAK_FUNC(sub_82082858);
PPC_FUNC_IMPL(__imp__sub_82082858) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lwz r16,21428(r29)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r29.u32 + 21428);
	// lwz r16,7080(r5)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r5.u32 + 7080);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x82082868;
	__savegprlr_24(ctx, base);
	// addi r31,r1,-160
	ctx.r31.s64 = ctx.r1.s64 + -160;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r3,180(r31)
	PPC_STORE_U32(ctx.r31.u32 + 180, ctx.r3.u32);
	// li r24,-1
	ctx.r24.s64 = -1;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// std r24,80(r31)
	PPC_STORE_U64(ctx.r31.u32 + 80, ctx.r24.u64);
	// cmpwi cr6,r3,-2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -2, ctx.xer);
	// bne cr6,0x820828b4
	if (!ctx.cr6.eq) goto loc_820828B4;
	// bl 0x8207d510
	ctx.lr = 0x82082894;
	sub_8207D510(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d4d8
	ctx.lr = 0x820828A0;
	sub_8207D4D8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,9
	ctx.r10.s64 = 9;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// b 0x82082994
	goto loc_82082994;
loc_820828B4:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x820828cc
	if (ctx.cr6.lt) goto loc_820828CC;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-23372(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -23372);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82082904
	if (ctx.cr6.lt) goto loc_82082904;
loc_820828CC:
	// bl 0x8207d510
	ctx.lr = 0x820828D0;
	sub_8207D510(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d4d8
	ctx.lr = 0x820828DC;
	sub_8207D4D8(ctx, base);
	// li r11,9
	ctx.r11.s64 = 9;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d940
	ctx.lr = 0x820828FC;
	sub_8207D940(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x82082994
	goto loc_82082994;
loc_82082904:
	// srawi r11,r30,5
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r30.s32 >> 5;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// rlwinm r27,r11,2,0,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r28,r10,-23360
	ctx.r28.s64 = ctx.r10.s64 + -23360;
	// clrlwi r11,r30,27
	ctx.r11.u64 = ctx.r30.u32 & 0x1F;
	// mulli r29,r11,72
	ctx.r29.s64 = ctx.r11.s64 * 72;
	// lwzx r11,r27,r28
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r28.u32);
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// lbz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820828cc
	if (ctx.cr0.eq) goto loc_820828CC;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82084d80
	ctx.lr = 0x82082938;
	sub_82084D80(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwzx r11,r27,r28
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r28.u32);
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// lbz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82082968
	if (ctx.cr0.eq) goto loc_82082968;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82082790
	ctx.lr = 0x82082960;
	sub_82082790(ctx, base);
	// std r3,80(r31)
	PPC_STORE_U64(ctx.r31.u32 + 80, ctx.r3.u64);
	// b 0x82082984
	goto loc_82082984;
loc_82082968:
	// bl 0x8207d4d8
	ctx.lr = 0x8208296C;
	sub_8207D4D8(ctx, base);
	// li r11,9
	ctx.r11.s64 = 9;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d510
	ctx.lr = 0x82082978;
	sub_8207D510(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// std r24,80(r31)
	PPC_STORE_U64(ctx.r31.u32 + 80, ctx.r24.u64);
loc_82082984:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,160
	ctx.r12.s64 = ctx.r31.s64 + 160;
	// bl 0x820829bc
	ctx.lr = 0x82082990;
	sub_820829BC(ctx, base);
	// ld r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r31.u32 + 80);
loc_82082994:
	// addi r1,r31,160
	ctx.r1.s64 = ctx.r31.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82082860"))) PPC_WEAK_FUNC(sub_82082860);
PPC_FUNC_IMPL(__imp__sub_82082860) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x82082868;
	__savegprlr_24(ctx, base);
	// addi r31,r1,-160
	ctx.r31.s64 = ctx.r1.s64 + -160;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r3,180(r31)
	PPC_STORE_U32(ctx.r31.u32 + 180, ctx.r3.u32);
	// li r24,-1
	ctx.r24.s64 = -1;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// std r24,80(r31)
	PPC_STORE_U64(ctx.r31.u32 + 80, ctx.r24.u64);
	// cmpwi cr6,r3,-2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -2, ctx.xer);
	// bne cr6,0x820828b4
	if (!ctx.cr6.eq) goto loc_820828B4;
	// bl 0x8207d510
	ctx.lr = 0x82082894;
	sub_8207D510(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d4d8
	ctx.lr = 0x820828A0;
	sub_8207D4D8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,9
	ctx.r10.s64 = 9;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// b 0x82082994
	goto loc_82082994;
loc_820828B4:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x820828cc
	if (ctx.cr6.lt) goto loc_820828CC;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-23372(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -23372);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82082904
	if (ctx.cr6.lt) goto loc_82082904;
loc_820828CC:
	// bl 0x8207d510
	ctx.lr = 0x820828D0;
	sub_8207D510(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d4d8
	ctx.lr = 0x820828DC;
	sub_8207D4D8(ctx, base);
	// li r11,9
	ctx.r11.s64 = 9;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d940
	ctx.lr = 0x820828FC;
	sub_8207D940(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x82082994
	goto loc_82082994;
loc_82082904:
	// srawi r11,r30,5
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r30.s32 >> 5;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// rlwinm r27,r11,2,0,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r28,r10,-23360
	ctx.r28.s64 = ctx.r10.s64 + -23360;
	// clrlwi r11,r30,27
	ctx.r11.u64 = ctx.r30.u32 & 0x1F;
	// mulli r29,r11,72
	ctx.r29.s64 = ctx.r11.s64 * 72;
	// lwzx r11,r27,r28
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r28.u32);
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// lbz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820828cc
	if (ctx.cr0.eq) goto loc_820828CC;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82084d80
	ctx.lr = 0x82082938;
	sub_82084D80(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwzx r11,r27,r28
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r28.u32);
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// lbz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82082968
	if (ctx.cr0.eq) goto loc_82082968;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82082790
	ctx.lr = 0x82082960;
	sub_82082790(ctx, base);
	// std r3,80(r31)
	PPC_STORE_U64(ctx.r31.u32 + 80, ctx.r3.u64);
	// b 0x82082984
	goto loc_82082984;
loc_82082968:
	// bl 0x8207d4d8
	ctx.lr = 0x8208296C;
	sub_8207D4D8(ctx, base);
	// li r11,9
	ctx.r11.s64 = 9;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d510
	ctx.lr = 0x82082978;
	sub_8207D510(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// std r24,80(r31)
	PPC_STORE_U64(ctx.r31.u32 + 80, ctx.r24.u64);
loc_82082984:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,160
	ctx.r12.s64 = ctx.r31.s64 + 160;
	// bl 0x820829bc
	ctx.lr = 0x82082990;
	sub_820829BC(ctx, base);
	// ld r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r31.u32 + 80);
loc_82082994:
	// addi r1,r31,160
	ctx.r1.s64 = ctx.r31.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8208299C"))) PPC_WEAK_FUNC(sub_8208299C);
PPC_FUNC_IMPL(__imp__sub_8208299C) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r31,r12,-160
	ctx.r31.s64 = ctx.r12.s64 + -160;
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r30,180(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 180);
	// b 0x820829d4
	goto loc_820829D4;
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r31,r12,-160
	ctx.r31.s64 = ctx.r12.s64 + -160;
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
loc_820829D4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82084e80
	ctx.lr = 0x820829DC;
	sub_82084E80(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r30,-16(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-24(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820829BC"))) PPC_WEAK_FUNC(sub_820829BC);
PPC_FUNC_IMPL(__imp__sub_820829BC) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r31,r12,-160
	ctx.r31.s64 = ctx.r12.s64 + -160;
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82084e80
	ctx.lr = 0x820829DC;
	sub_82084E80(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r30,-16(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-24(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820829F4"))) PPC_WEAK_FUNC(sub_820829F4);
PPC_FUNC_IMPL(__imp__sub_820829F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820829F8"))) PPC_WEAK_FUNC(sub_820829F8);
PPC_FUNC_IMPL(__imp__sub_820829F8) {
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
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r3,4096
	ctx.r3.s64 = 4096;
	// lwz r11,-12296(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12296);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-12296(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12296, ctx.r11.u32);
	// bl 0x8207a400
	ctx.lr = 0x82082A24;
	sub_8207A400(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// beq 0x82082a44
	if (ctx.cr0.eq) goto loc_82082A44;
	// li r10,4096
	ctx.r10.s64 = 4096;
	// ori r11,r11,8
	ctx.r11.u64 = ctx.r11.u64 | 8;
	// stw r10,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// b 0x82082a58
	goto loc_82082A58;
loc_82082A44:
	// addi r10,r31,20
	ctx.r10.s64 = ctx.r31.s64 + 20;
	// li r9,2
	ctx.r9.s64 = 2;
	// ori r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 4;
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// stw r9,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r9.u32);
loc_82082A58:
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_82082A80"))) PPC_WEAK_FUNC(sub_82082A80);
PPC_FUNC_IMPL(__imp__sub_82082A80) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82082ad4
	if (!ctx.cr6.eq) goto loc_82082AD4;
loc_82082AA8:
	// bl 0x8207d4d8
	ctx.lr = 0x82082AAC;
	sub_8207D4D8(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d940
	ctx.lr = 0x82082ACC;
	sub_8207D940(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x82082b58
	goto loc_82082B58;
loc_82082AD4:
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82082ae4
	if (ctx.cr6.eq) goto loc_82082AE4;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82082aa8
	if (ctx.cr6.eq) goto loc_82082AA8;
loc_82082AE4:
	// lis r10,32767
	ctx.r10.s64 = 2147418112;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
	// cmplw cr6,r4,r10
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, ctx.xer);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bgt cr6,0x82082afc
	if (ctx.cr6.gt) goto loc_82082AFC;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
loc_82082AFC:
	// li r10,66
	ctx.r10.s64 = 66;
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r31.u32);
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8207e430
	ctx.lr = 0x82082B1C;
	sub_8207E430(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82082b54
	if (ctx.cr6.eq) goto loc_82082B54;
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// blt 0x82082b48
	if (ctx.cr0.lt) goto loc_82082B48;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// b 0x82082b54
	goto loc_82082B54;
loc_82082B48:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207e1b8
	ctx.lr = 0x82082B54;
	sub_8207E1B8(ctx, base);
loc_82082B54:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_82082B58:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
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

__attribute__((alias("__imp__sub_82082B70"))) PPC_WEAK_FUNC(sub_82082B70);
PPC_FUNC_IMPL(__imp__sub_82082B70) {
	PPC_FUNC_PROLOGUE();
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// b 0x82082a80
	sub_82082A80(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82082B7C"))) PPC_WEAK_FUNC(sub_82082B7C);
PPC_FUNC_IMPL(__imp__sub_82082B7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82082B80"))) PPC_WEAK_FUNC(sub_82082B80);
PPC_FUNC_IMPL(__imp__sub_82082B80) {
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
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x82082bac
	if (!ctx.cr6.eq) goto loc_82082BAC;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82082bac
	if (ctx.cr6.eq) goto loc_82082BAC;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82082c88
	if (ctx.cr6.eq) goto loc_82082C88;
	// b 0x82082c84
	goto loc_82082C84;
loc_82082BAC:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82082bbc
	if (ctx.cr6.eq) goto loc_82082BBC;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_82082BBC:
	// lis r10,32767
	ctx.r10.s64 = 2147418112;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
	// cmplw cr6,r5,r10
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x82082bf8
	if (!ctx.cr6.gt) goto loc_82082BF8;
	// bl 0x8207d4d8
	ctx.lr = 0x82082BD0;
	sub_8207D4D8(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d940
	ctx.lr = 0x82082BF0;
	sub_8207D940(ctx, base);
	// li r3,22
	ctx.r3.s64 = 22;
	// b 0x82082c8c
	goto loc_82082C8C;
loc_82082BF8:
	// clrlwi r10,r6,16
	ctx.r10.u64 = ctx.r6.u32 & 0xFFFF;
	// cmplwi cr6,r10,255
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 255, ctx.xer);
	// ble cr6,0x82082c38
	if (!ctx.cr6.gt) goto loc_82082C38;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82082c20
	if (ctx.cr6.eq) goto loc_82082C20;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82082c20
	if (ctx.cr6.eq) goto loc_82082C20;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x8207da20
	ctx.lr = 0x82082C20;
	sub_8207DA20(ctx, base);
loc_82082C20:
	// bl 0x8207d4d8
	ctx.lr = 0x82082C24;
	sub_8207D4D8(ctx, base);
	// li r11,42
	ctx.r11.s64 = 42;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d4d8
	ctx.lr = 0x82082C30;
	sub_8207D4D8(ctx, base);
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x82082c8c
	goto loc_82082C8C;
loc_82082C38:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82082c78
	if (ctx.cr6.eq) goto loc_82082C78;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bne cr6,0x82082c74
	if (!ctx.cr6.eq) goto loc_82082C74;
	// bl 0x8207d4d8
	ctx.lr = 0x82082C4C;
	sub_8207D4D8(ctx, base);
	// li r11,34
	ctx.r11.s64 = 34;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d940
	ctx.lr = 0x82082C6C;
	sub_8207D940(ctx, base);
	// li r3,34
	ctx.r3.s64 = 34;
	// b 0x82082c8c
	goto loc_82082C8C;
loc_82082C74:
	// stb r6,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r6.u8);
loc_82082C78:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82082c88
	if (ctx.cr6.eq) goto loc_82082C88;
	// li r11,1
	ctx.r11.s64 = 1;
loc_82082C84:
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
loc_82082C88:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82082C8C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82082C9C"))) PPC_WEAK_FUNC(sub_82082C9C);
PPC_FUNC_IMPL(__imp__sub_82082C9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82082CA0"))) PPC_WEAK_FUNC(sub_82082CA0);
PPC_FUNC_IMPL(__imp__sub_82082CA0) {
	PPC_FUNC_PROLOGUE();
	// li r7,0
	ctx.r7.s64 = 0;
	// b 0x82082b80
	sub_82082B80(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82082CA8"))) PPC_WEAK_FUNC(sub_82082CA8);
PPC_FUNC_IMPL(__imp__sub_82082CA8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// rlwinm r10,r3,1,23,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0x1FE;
	// lwz r11,2792(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2792);
	// lwz r11,200(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 200);
	// lhzx r11,r10,r11
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r11.u32);
	// rlwinm r3,r11,0,0,16
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFF8000;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82082CC4"))) PPC_WEAK_FUNC(sub_82082CC4);
PPC_FUNC_IMPL(__imp__sub_82082CC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82082CC8"))) PPC_WEAK_FUNC(sub_82082CC8);
PPC_FUNC_IMPL(__imp__sub_82082CC8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c974
	ctx.lr = 0x82082CD0;
	__savegprlr_23(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// mr r23,r4
	ctx.r23.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r24,r6
	ctx.r24.u64 = ctx.r6.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82082cf0
	if (ctx.cr6.eq) goto loc_82082CF0;
	// stw r3,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r3.u32);
loc_82082CF0:
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// bne cr6,0x82082d20
	if (!ctx.cr6.eq) goto loc_82082D20;
loc_82082CF8:
	// bl 0x8207d4d8
	ctx.lr = 0x82082CFC;
	sub_8207D4D8(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d940
	ctx.lr = 0x82082D1C;
	sub_8207D940(ctx, base);
	// b 0x82082fa8
	goto loc_82082FA8;
loc_82082D20:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq cr6,0x82082d38
	if (ctx.cr6.eq) goto loc_82082D38;
	// cmpwi cr6,r28,2
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 2, ctx.xer);
	// blt cr6,0x82082cf8
	if (ctx.cr6.lt) goto loc_82082CF8;
	// cmpwi cr6,r28,36
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 36, ctx.xer);
	// bgt cr6,0x82082cf8
	if (ctx.cr6.gt) goto loc_82082CF8;
loc_82082D38:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lbz r31,0(r25)
	ctx.r31.u64 = PPC_LOAD_U8(ctx.r25.u32 + 0);
	// li r26,0
	ctx.r26.s64 = 0;
	// addi r29,r25,1
	ctx.r29.s64 = ctx.r25.s64 + 1;
	// addi r30,r11,2792
	ctx.r30.s64 = ctx.r11.s64 + 2792;
	// lwz r10,2792(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2792);
loc_82082D50:
	// lwz r11,172(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 172);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// ble cr6,0x82082d74
	if (!ctx.cr6.gt) goto loc_82082D74;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r4,8
	ctx.r4.s64 = 8;
	// clrlwi r3,r31,24
	ctx.r3.u64 = ctx.r31.u32 & 0xFF;
	// bl 0x82085400
	ctx.lr = 0x82082D6C;
	sub_82085400(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// b 0x82082d84
	goto loc_82082D84;
loc_82082D74:
	// lwz r11,200(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 200);
	// rlwinm r9,r31,1,23,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0x1FE;
	// lhzx r11,r9,r11
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r11.u32);
	// rlwinm r3,r11,0,28,28
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
loc_82082D84:
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x82082d98
	if (ctx.cr6.eq) goto loc_82082D98;
	// lbz r31,0(r29)
	ctx.r31.u64 = PPC_LOAD_U8(ctx.r29.u32 + 0);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// b 0x82082d50
	goto loc_82082D50;
loc_82082D98:
	// extsb r11,r31
	ctx.r11.s64 = ctx.r31.s8;
	// cmpwi cr6,r11,45
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 45, ctx.xer);
	// bne cr6,0x82082dac
	if (!ctx.cr6.eq) goto loc_82082DAC;
	// ori r24,r24,2
	ctx.r24.u64 = ctx.r24.u64 | 2;
	// b 0x82082db4
	goto loc_82082DB4;
loc_82082DAC:
	// cmpwi cr6,r11,43
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 43, ctx.xer);
	// bne cr6,0x82082dbc
	if (!ctx.cr6.eq) goto loc_82082DBC;
loc_82082DB4:
	// lbz r31,0(r29)
	ctx.r31.u64 = PPC_LOAD_U8(ctx.r29.u32 + 0);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
loc_82082DBC:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// blt cr6,0x82082f9c
	if (ctx.cr6.lt) goto loc_82082F9C;
	// cmpwi cr6,r28,1
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 1, ctx.xer);
	// beq cr6,0x82082f9c
	if (ctx.cr6.eq) goto loc_82082F9C;
	// cmpwi cr6,r28,36
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 36, ctx.xer);
	// bgt cr6,0x82082f9c
	if (ctx.cr6.gt) goto loc_82082F9C;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bne cr6,0x82082e18
	if (!ctx.cr6.eq) goto loc_82082E18;
	// extsb r11,r31
	ctx.r11.s64 = ctx.r31.s8;
	// cmpwi cr6,r11,48
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 48, ctx.xer);
	// beq cr6,0x82082df0
	if (ctx.cr6.eq) goto loc_82082DF0;
	// li r28,10
	ctx.r28.s64 = 10;
	// b 0x82082e4c
	goto loc_82082E4C;
loc_82082DF0:
	// lbz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r29.u32 + 0);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// cmpwi cr6,r11,120
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 120, ctx.xer);
	// beq cr6,0x82082e10
	if (ctx.cr6.eq) goto loc_82082E10;
	// cmpwi cr6,r11,88
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 88, ctx.xer);
	// beq cr6,0x82082e10
	if (ctx.cr6.eq) goto loc_82082E10;
	// li r28,8
	ctx.r28.s64 = 8;
	// b 0x82082e4c
	goto loc_82082E4C;
loc_82082E10:
	// li r28,16
	ctx.r28.s64 = 16;
	// b 0x82082e20
	goto loc_82082E20;
loc_82082E18:
	// cmpwi cr6,r28,16
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 16, ctx.xer);
	// bne cr6,0x82082e4c
	if (!ctx.cr6.eq) goto loc_82082E4C;
loc_82082E20:
	// extsb r11,r31
	ctx.r11.s64 = ctx.r31.s8;
	// cmpwi cr6,r11,48
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 48, ctx.xer);
	// bne cr6,0x82082e4c
	if (!ctx.cr6.eq) goto loc_82082E4C;
	// lbz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r29.u32 + 0);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// cmpwi cr6,r11,120
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 120, ctx.xer);
	// beq cr6,0x82082e44
	if (ctx.cr6.eq) goto loc_82082E44;
	// cmpwi cr6,r11,88
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 88, ctx.xer);
	// bne cr6,0x82082e4c
	if (!ctx.cr6.eq) goto loc_82082E4C;
loc_82082E44:
	// lbzu r31,1(r29)
	ea = 1 + ctx.r29.u32;
	ctx.r31.u64 = PPC_LOAD_U8(ea);
	ctx.r29.u32 = ea;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
loc_82082E4C:
	// li r27,-1
	ctx.r27.s64 = -1;
	// lwz r8,200(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 200);
	// twllei r28,0
	// divwu r9,r27,r28
	ctx.r9.u32 = ppc_divwu(ctx.r27.u32, ctx.r28.u32);
loc_82082E5C:
	// rlwinm r11,r31,1,23,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0x1FE;
	// lhzx r11,r11,r8
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r8.u32);
	// rlwinm. r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82082e78
	if (ctx.cr0.eq) goto loc_82082E78;
	// extsb r11,r31
	ctx.r11.s64 = ctx.r31.s8;
	// addi r11,r11,-48
	ctx.r11.s64 = ctx.r11.s64 + -48;
	// b 0x82082ea0
	goto loc_82082EA0;
loc_82082E78:
	// andi. r11,r11,259
	ctx.r11.u64 = ctx.r11.u64 & 259;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82082ee0
	if (ctx.cr0.eq) goto loc_82082EE0;
	// extsb r11,r31
	ctx.r11.s64 = ctx.r31.s8;
	// cmpwi cr6,r11,97
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 97, ctx.xer);
	// blt cr6,0x82082e9c
	if (ctx.cr6.lt) goto loc_82082E9C;
	// cmpwi cr6,r11,122
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 122, ctx.xer);
	// bgt cr6,0x82082e9c
	if (ctx.cr6.gt) goto loc_82082E9C;
	// addi r11,r11,-32
	ctx.r11.s64 = ctx.r11.s64 + -32;
loc_82082E9C:
	// addi r11,r11,-55
	ctx.r11.s64 = ctx.r11.s64 + -55;
loc_82082EA0:
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// bge cr6,0x82082ee0
	if (!ctx.cr6.lt) goto loc_82082EE0;
	// ori r24,r24,8
	ctx.r24.u64 = ctx.r24.u64 | 8;
	// cmplw cr6,r26,r9
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x82082f00
	if (ctx.cr6.lt) goto loc_82082F00;
	// bne cr6,0x82082ed4
	if (!ctx.cr6.eq) goto loc_82082ED4;
	// divwu r7,r27,r28
	ctx.r7.u32 = ppc_divwu(ctx.r27.u32, ctx.r28.u32);
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// mullw r7,r7,r28
	ctx.r7.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r28.s32);
	// subf r10,r7,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r7.s64;
	// twllei r28,0
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x82082f00
	if (!ctx.cr6.gt) goto loc_82082F00;
loc_82082ED4:
	// ori r24,r24,4
	ctx.r24.u64 = ctx.r24.u64 | 4;
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// bne cr6,0x82082f08
	if (!ctx.cr6.eq) goto loc_82082F08;
loc_82082EE0:
	// rlwinm. r11,r24,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r30,r29,-1
	ctx.r30.s64 = ctx.r29.s64 + -1;
	// bne 0x82082f14
	if (!ctx.cr0.eq) goto loc_82082F14;
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x82082ef8
	if (ctx.cr6.eq) goto loc_82082EF8;
	// mr r30,r25
	ctx.r30.u64 = ctx.r25.u64;
loc_82082EF8:
	// li r26,0
	ctx.r26.s64 = 0;
	// b 0x82082f7c
	goto loc_82082F7C;
loc_82082F00:
	// mullw r10,r26,r28
	ctx.r10.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r28.s32);
	// add r26,r10,r11
	ctx.r26.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_82082F08:
	// lbz r31,0(r29)
	ctx.r31.u64 = PPC_LOAD_U8(ctx.r29.u32 + 0);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// b 0x82082e5c
	goto loc_82082E5C;
loc_82082F14:
	// lis r10,32767
	ctx.r10.s64 = 2147418112;
	// rlwinm. r11,r24,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ori r31,r10,65535
	ctx.r31.u64 = ctx.r10.u64 | 65535;
	// bne 0x82082f50
	if (!ctx.cr0.eq) goto loc_82082F50;
	// clrlwi. r11,r24,31
	ctx.r11.u64 = ctx.r24.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82082f7c
	if (!ctx.cr0.eq) goto loc_82082F7C;
	// rlwinm. r11,r24,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82082f40
	if (ctx.cr0.eq) goto loc_82082F40;
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// cmplw cr6,r26,r10
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x82082f50
	if (ctx.cr6.gt) goto loc_82082F50;
loc_82082F40:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82082f7c
	if (!ctx.cr6.eq) goto loc_82082F7C;
	// cmplw cr6,r26,r31
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r31.u32, ctx.xer);
	// ble cr6,0x82082f7c
	if (!ctx.cr6.gt) goto loc_82082F7C;
loc_82082F50:
	// bl 0x8207d4d8
	ctx.lr = 0x82082F54;
	sub_8207D4D8(ctx, base);
	// li r11,34
	ctx.r11.s64 = 34;
	// clrlwi. r10,r24,31
	ctx.r10.u64 = ctx.r24.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// beq 0x82082f6c
	if (ctx.cr0.eq) goto loc_82082F6C;
	// mr r26,r27
	ctx.r26.u64 = ctx.r27.u64;
	// b 0x82082f7c
	goto loc_82082F7C;
loc_82082F6C:
	// rlwinm. r11,r24,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lis r26,-32768
	ctx.r26.s64 = -2147483648;
	// bne 0x82082f7c
	if (!ctx.cr0.eq) goto loc_82082F7C;
	// mr r26,r31
	ctx.r26.u64 = ctx.r31.u64;
loc_82082F7C:
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x82082f88
	if (ctx.cr6.eq) goto loc_82082F88;
	// stw r30,0(r23)
	PPC_STORE_U32(ctx.r23.u32 + 0, ctx.r30.u32);
loc_82082F88:
	// rlwinm. r11,r24,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82082f94
	if (ctx.cr0.eq) goto loc_82082F94;
	// neg r26,r26
	ctx.r26.s64 = -ctx.r26.s64;
loc_82082F94:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// b 0x82082fac
	goto loc_82082FAC;
loc_82082F9C:
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x82082fa8
	if (ctx.cr6.eq) goto loc_82082FA8;
	// stw r25,0(r23)
	PPC_STORE_U32(ctx.r23.u32 + 0, ctx.r25.u32);
loc_82082FA8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82082FAC:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82082FB4"))) PPC_WEAK_FUNC(sub_82082FB4);
PPC_FUNC_IMPL(__imp__sub_82082FB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82082FB8"))) PPC_WEAK_FUNC(sub_82082FB8);
PPC_FUNC_IMPL(__imp__sub_82082FB8) {
	PPC_FUNC_PROLOGUE();
	// li r6,0
	ctx.r6.s64 = 0;
	// b 0x82082cc8
	sub_82082CC8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82082FC0"))) PPC_WEAK_FUNC(sub_82082FC0);
PPC_FUNC_IMPL(__imp__sub_82082FC0) {
	PPC_FUNC_PROLOGUE();
	// li r6,1
	ctx.r6.s64 = 1;
	// b 0x82082cc8
	sub_82082CC8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82082FC8"))) PPC_WEAK_FUNC(sub_82082FC8);
PPC_FUNC_IMPL(__imp__sub_82082FC8) {
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
	// lbz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// extsb r3,r11
	ctx.r3.s64 = ctx.r11.s8;
	// bl 0x820854f8
	ctx.lr = 0x82082FE8;
	sub_820854F8(ctx, base);
	// cmpwi cr6,r3,101
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 101, ctx.xer);
	// beq cr6,0x82083000
	if (ctx.cr6.eq) goto loc_82083000;
loc_82082FF0:
	// lbzu r3,1(r31)
	ea = 1 + ctx.r31.u32;
	ctx.r3.u64 = PPC_LOAD_U8(ea);
	ctx.r31.u32 = ea;
	// bl 0x82085498
	ctx.lr = 0x82082FF8;
	sub_82085498(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x82082ff0
	if (!ctx.cr0.eq) goto loc_82082FF0;
loc_82083000:
	// lbz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// extsb r3,r11
	ctx.r3.s64 = ctx.r11.s8;
	// bl 0x820854f8
	ctx.lr = 0x8208300C;
	sub_820854F8(ctx, base);
	// cmpwi cr6,r3,120
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 120, ctx.xer);
	// bne cr6,0x82083018
	if (!ctx.cr6.eq) goto loc_82083018;
	// addi r31,r31,2
	ctx.r31.s64 = ctx.r31.s64 + 2;
loc_82083018:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// lwz r11,3848(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 3848);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// lbz r9,0(r9)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// stb r9,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r9.u8);
loc_82083034:
	// lbz r9,1(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// stb r10,1(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1, ctx.r10.u8);
	// lbzu r8,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// cmplwi r8,0
	ctx.cr0.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne 0x82083034
	if (!ctx.cr0.eq) goto loc_82083034;
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

__attribute__((alias("__imp__sub_82083060"))) PPC_WEAK_FUNC(sub_82083060);
PPC_FUNC_IMPL(__imp__sub_82083060) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lbz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// extsb. r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r8,3848(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 3848);
	// beq 0x82083094
	if (ctx.cr0.eq) goto loc_82083094;
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lbz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
loc_82083080:
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x82083094
	if (ctx.cr6.eq) goto loc_82083094;
	// lbzu r11,1(r3)
	ea = 1 + ctx.r3.u32;
	ctx.r11.u64 = PPC_LOAD_U8(ea);
	ctx.r3.u32 = ea;
	// extsb. r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82083080
	if (!ctx.cr0.eq) goto loc_82083080;
loc_82083094:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 1;
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// b 0x820830bc
	goto loc_820830BC;
loc_820830A8:
	// cmpwi cr6,r10,101
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 101, ctx.xer);
	// beq cr6,0x820830c4
	if (ctx.cr6.eq) goto loc_820830C4;
	// cmpwi cr6,r10,69
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 69, ctx.xer);
	// beq cr6,0x820830c4
	if (ctx.cr6.eq) goto loc_820830C4;
	// lbzu r10,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r10.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
loc_820830BC:
	// extsb. r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x820830a8
	if (!ctx.cr0.eq) goto loc_820830A8;
loc_820830C4:
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
loc_820830C8:
	// lbzu r10,-1(r11)
	ea = -1 + ctx.r11.u32;
	ctx.r10.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// cmpwi cr6,r10,48
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 48, ctx.xer);
	// beq cr6,0x820830c8
	if (ctx.cr6.eq) goto loc_820830C8;
	// lwz r8,0(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lbz r8,0(r8)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// extsb r8,r8
	ctx.r8.s64 = ctx.r8.s8;
	// cmpw cr6,r10,r8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, ctx.xer);
	// bne cr6,0x820830f0
	if (!ctx.cr6.eq) goto loc_820830F0;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_820830F0:
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
loc_820830F4:
	// lbzu r10,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r10.u64 = PPC_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stbu r10,1(r11)
	ea = 1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r10.u8);
	ctx.r11.u32 = ea;
	// bne 0x820830f4
	if (!ctx.cr0.eq) goto loc_820830F4;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82083108"))) PPC_WEAK_FUNC(sub_82083108);
PPC_FUNC_IMPL(__imp__sub_82083108) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfd f13,0(r3)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// li r3,1
	ctx.r3.s64 = 1;
	// lfd f0,2432(r11)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r11.u32 + 2432);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82083128"))) PPC_WEAK_FUNC(sub_82083128);
PPC_FUNC_IMPL(__imp__sub_82083128) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x82083160
	if (ctx.cr6.eq) goto loc_82083160;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82085510
	ctx.lr = 0x82083154;
	sub_82085510(ctx, base);
	// ld r11,88(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// std r11,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
	// b 0x82083170
	goto loc_82083170;
loc_82083160:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820855b8
	ctx.lr = 0x82083168;
	sub_820855B8(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_82083170:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82083184"))) PPC_WEAK_FUNC(sub_82083184);
PPC_FUNC_IMPL(__imp__sub_82083184) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82083188"))) PPC_WEAK_FUNC(sub_82083188);
PPC_FUNC_IMPL(__imp__sub_82083188) {
	PPC_FUNC_PROLOGUE();
	// li r6,0
	ctx.r6.s64 = 0;
	// b 0x82083128
	sub_82083128(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82083190"))) PPC_WEAK_FUNC(sub_82083190);
PPC_FUNC_IMPL(__imp__sub_82083190) {
	PPC_FUNC_PROLOGUE();
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x82082fc8
	sub_82082FC8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82083198"))) PPC_WEAK_FUNC(sub_82083198);
PPC_FUNC_IMPL(__imp__sub_82083198) {
	PPC_FUNC_PROLOGUE();
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x82083060
	sub_82083060(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820831A0"))) PPC_WEAK_FUNC(sub_820831A0);
PPC_FUNC_IMPL(__imp__sub_820831A0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x820831A8;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// mr r25,r6
	ctx.r25.u64 = ctx.r6.u64;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820831f4
	if (!ctx.cr6.eq) goto loc_820831F4;
	// bl 0x8207d4d8
	ctx.lr = 0x820831CC;
	sub_8207D4D8(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d940
	ctx.lr = 0x820831EC;
	sub_8207D940(ctx, base);
	// li r3,22
	ctx.r3.s64 = 22;
	// b 0x8208340c
	goto loc_8208340C;
loc_820831F4:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x82083228
	if (!ctx.cr6.eq) goto loc_82083228;
	// bl 0x8207d4d8
	ctx.lr = 0x82083200;
	sub_8207D4D8(ctx, base);
	// li r31,22
	ctx.r31.s64 = 22;
loc_82083204:
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r31.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d940
	ctx.lr = 0x82083220;
	sub_8207D940(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x8208340c
	goto loc_8208340C;
loc_82083228:
	// subfic r11,r31,0
	ctx.xer.ca = ctx.r31.u32 <= 0;
	ctx.r11.s64 = 0 - ctx.r31.s64;
	// rlwinm r11,r31,1,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0x1;
	// addme r11,r11
	{ uint8_t _ca = (ctx.r11.u32 + 0xFFFFFFFF < ctx.r11.u32) | (ctx.r11.u32 + 0xFFFFFFFF + ctx.xer.ca < ctx.xer.ca); // FIX 2026-07-24: insn was silently dropped by the recompiler
	ctx.r11.u64 = ctx.r11.u64 + 0xFFFFFFFFFFFFFFFFull + ctx.xer.ca;
	ctx.xer.ca = _ca; }
	// and r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 & ctx.r31.u64;
	// addi r11,r11,9
	ctx.r11.s64 = ctx.r11.s64 + 9;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x82083250
	if (ctx.cr6.gt) goto loc_82083250;
	// bl 0x8207d4d8
	ctx.lr = 0x82083248;
	sub_8207D4D8(ctx, base);
	// li r31,34
	ctx.r31.s64 = 34;
	// b 0x82083204
	goto loc_82083204;
loc_82083250:
	// extsb. r28,r8
	ctx.r28.s64 = ctx.r8.s8;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq 0x820832a0
	if (ctx.cr0.eq) goto loc_820832A0;
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// addi r11,r11,-45
	ctx.r11.s64 = ctx.r11.s64 + -45;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// add r4,r11,r30
	ctx.r4.u64 = ctx.r11.u64 + ctx.r30.u64;
	// ble cr6,0x820832a0
	if (!ctx.cr6.gt) goto loc_820832A0;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
loc_82083278:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82083278
	if (!ctx.cr6.eq) goto loc_82083278;
	// subf r11,r4,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r4.s64;
	// addi r3,r4,1
	ctx.r3.s64 = ctx.r4.s64 + 1;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// bl 0x8207d870
	ctx.lr = 0x820832A0;
	sub_8207D870(ctx, base);
loc_820832A0:
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// li r26,45
	ctx.r26.s64 = 45;
	// cmpwi cr6,r10,45
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 45, ctx.xer);
	// bne cr6,0x820832bc
	if (!ctx.cr6.eq) goto loc_820832BC;
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// stb r26,0(r30)
	PPC_STORE_U8(ctx.r30.u32 + 0, ctx.r26.u8);
loc_820832BC:
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// ble cr6,0x820832e8
	if (!ctx.cr6.gt) goto loc_820832E8;
	// lbz r9,1(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// stb r9,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r9.u8);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// lwz r9,3848(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 3848);
	// lwz r9,0(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lbz r9,0(r9)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
loc_820832E8:
	// cntlzw r10,r28
	ctx.r10.u64 = ctx.r28.u32 == 0 ? 32 : __builtin_clz(ctx.r28.u32);
	// cmpwi cr6,r29,-1
	ctx.cr6.compare<int32_t>(ctx.r29.s32, -1, ctx.xer);
	// rlwinm r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r31,r11,r31
	ctx.r31.u64 = ctx.r11.u64 + ctx.r31.u64;
	// bne cr6,0x82083308
	if (!ctx.cr6.eq) goto loc_82083308;
	// li r4,-1
	ctx.r4.s64 = -1;
	// b 0x82083310
	goto loc_82083310;
loc_82083308:
	// subf r11,r31,r30
	ctx.r11.s64 = ctx.r30.s64 - ctx.r31.s64;
	// add r4,r11,r29
	ctx.r4.u64 = ctx.r11.u64 + ctx.r29.u64;
loc_82083310:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r5,r11,6688
	ctx.r5.s64 = ctx.r11.s64 + 6688;
	// bl 0x8207abf0
	ctx.lr = 0x82083320;
	sub_8207ABF0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82083340
	if (ctx.cr0.eq) goto loc_82083340;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d988
	ctx.lr = 0x82083340;
	sub_8207D988(ctx, base);
loc_82083340:
	// addi r3,r31,2
	ctx.r3.s64 = ctx.r31.s64 + 2;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq cr6,0x82083354
	if (ctx.cr6.eq) goto loc_82083354;
	// li r11,69
	ctx.r11.s64 = 69;
	// stb r11,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r11.u8);
loc_82083354:
	// lwz r11,12(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// addi r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 1;
	// lbz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,48
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 48, ctx.xer);
	// beq cr6,0x820833e0
	if (ctx.cr6.eq) goto loc_820833E0;
	// lwz r11,4(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge 0x8208337c
	if (!ctx.cr0.lt) goto loc_8208337C;
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
	// stb r26,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r26.u8);
loc_8208337C:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r11,100
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 100, ctx.xer);
	// blt cr6,0x820833a8
	if (ctx.cr6.lt) goto loc_820833A8;
	// li r7,100
	ctx.r7.s64 = 100;
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// divw r9,r11,r7
	ctx.r9.s32 = ppc_divw(ctx.r11.s32, ctx.r7.s32);
	// divw r7,r11,r7
	ctx.r7.s32 = ppc_divw(ctx.r11.s32, ctx.r7.s32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// mulli r8,r7,100
	ctx.r8.s64 = ctx.r7.s64 * 100;
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// subf r11,r8,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r8.s64;
loc_820833A8:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// blt cr6,0x820833d4
	if (ctx.cr6.lt) goto loc_820833D4;
	// li r7,10
	ctx.r7.s64 = 10;
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// divw r9,r11,r7
	ctx.r9.s32 = ppc_divw(ctx.r11.s32, ctx.r7.s32);
	// divw r7,r11,r7
	ctx.r7.s32 = ppc_divw(ctx.r11.s32, ctx.r7.s32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// mulli r8,r7,10
	ctx.r8.s64 = ctx.r7.s64 * 10;
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// subf r11,r8,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r8.s64;
loc_820833D4:
	// lbzu r9,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r9.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r11.u8);
loc_820833E0:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lwz r11,-11704(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11704);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82083408
	if (ctx.cr0.eq) goto loc_82083408;
	// lbz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,48
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 48, ctx.xer);
	// bne cr6,0x82083408
	if (!ctx.cr6.eq) goto loc_82083408;
	// addi r4,r3,1
	ctx.r4.s64 = ctx.r3.s64 + 1;
	// li r5,3
	ctx.r5.s64 = 3;
	// bl 0x8207d870
	ctx.lr = 0x82083408;
	sub_8207D870(ctx, base);
loc_82083408:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8208340C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82083414"))) PPC_WEAK_FUNC(sub_82083414);
PPC_FUNC_IMPL(__imp__sub_82083414) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82083418"))) PPC_WEAK_FUNC(sub_82083418);
PPC_FUNC_IMPL(__imp__sub_82083418) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82083420;
	__savegprlr_28(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// ld r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r31,r6
	ctx.r31.u64 = ctx.r6.u64;
	// li r6,22
	ctx.r6.s64 = 22;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// bl 0x820858c8
	ctx.lr = 0x82083448;
	sub_820858C8(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x8208347c
	if (!ctx.cr6.eq) goto loc_8208347C;
loc_82083450:
	// bl 0x8207d4d8
	ctx.lr = 0x82083454;
	sub_8207D4D8(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d940
	ctx.lr = 0x82083474;
	sub_8207D940(ctx, base);
	// li r3,22
	ctx.r3.s64 = 22;
	// b 0x82083514
	goto loc_82083514;
loc_8208347C:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82083450
	if (ctx.cr6.eq) goto loc_82083450;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r29,-1
	ctx.cr6.compare<int32_t>(ctx.r29.s32, -1, ctx.xer);
	// bne cr6,0x82083498
	if (!ctx.cr6.eq) goto loc_82083498;
	// li r4,-1
	ctx.r4.s64 = -1;
	// b 0x820834b8
	goto loc_820834B8;
loc_82083498:
	// addi r10,r11,-45
	ctx.r10.s64 = ctx.r11.s64 + -45;
	// neg r9,r31
	ctx.r9.s64 = -ctx.r31.s64;
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// andc r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 & ~ctx.r31.u64;
	// rlwinm r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// rlwinm r9,r9,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1;
	// subf r10,r10,r29
	ctx.r10.s64 = ctx.r29.s64 - ctx.r10.s64;
	// subf r4,r9,r10
	ctx.r4.s64 = ctx.r10.s64 - ctx.r9.s64;
loc_820834B8:
	// addi r11,r11,-45
	ctx.r11.s64 = ctx.r11.s64 + -45;
	// neg r10,r31
	ctx.r10.s64 = -ctx.r31.s64;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// andc r9,r10,r31
	ctx.r9.u64 = ctx.r10.u64 & ~ctx.r31.u64;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// rlwinm r11,r9,1,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r5,r31,1
	ctx.r5.s64 = ctx.r31.s64 + 1;
	// add r3,r11,r30
	ctx.r3.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x82085660
	ctx.lr = 0x820834E4;
	sub_82085660(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x820834f8
	if (ctx.cr0.eq) goto loc_820834F8;
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,0(r30)
	PPC_STORE_U8(ctx.r30.u32 + 0, ctx.r11.u8);
	// b 0x82083514
	goto loc_82083514;
loc_820834F8:
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820831a0
	ctx.lr = 0x82083514;
	sub_820831A0(ctx, base);
loc_82083514:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8208351C"))) PPC_WEAK_FUNC(sub_8208351C);
PPC_FUNC_IMPL(__imp__sub_8208351C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82083520"))) PPC_WEAK_FUNC(sub_82083520);
PPC_FUNC_IMPL(__imp__sub_82083520) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x82083528;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// rlwinm r11,r6,1,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0x1;
	// li r28,48
	ctx.r28.s64 = 48;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// li r30,1023
	ctx.r30.s64 = 1023;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// and r6,r11,r6
	ctx.r6.u64 = ctx.r11.u64 & ctx.r6.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x82083580
	if (!ctx.cr6.eq) goto loc_82083580;
	// bl 0x8207d4d8
	ctx.lr = 0x82083558;
	sub_8207D4D8(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d940
	ctx.lr = 0x82083578;
	sub_8207D940(ctx, base);
	// li r3,22
	ctx.r3.s64 = 22;
	// b 0x82083938
	goto loc_82083938;
loc_82083580:
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bne cr6,0x820835b4
	if (!ctx.cr6.eq) goto loc_820835B4;
	// bl 0x8207d4d8
	ctx.lr = 0x8208358C;
	sub_8207D4D8(ctx, base);
	// li r31,22
	ctx.r31.s64 = 22;
loc_82083590:
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r31.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d940
	ctx.lr = 0x820835AC;
	sub_8207D940(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x82083938
	goto loc_82083938;
loc_820835B4:
	// li r26,0
	ctx.r26.s64 = 0;
	// addi r11,r6,11
	ctx.r11.s64 = ctx.r6.s64 + 11;
	// stb r26,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r26.u8);
	// cmplw cr6,r5,r11
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x820835d4
	if (ctx.cr6.gt) goto loc_820835D4;
	// bl 0x8207d4d8
	ctx.lr = 0x820835CC;
	sub_8207D4D8(ctx, base);
	// li r31,34
	ctx.r31.s64 = 34;
	// b 0x82083590
	goto loc_82083590;
loc_820835D4:
	// ld r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// rlwinm r10,r11,0,20,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFE;
	// cmpldi cr6,r10,4094
	ctx.cr6.compare<uint64_t>(ctx.r10.u64, 4094, ctx.xer);
	// bne cr6,0x82083678
	if (!ctx.cr6.eq) goto loc_82083678;
	// cmpwi cr6,r5,-1
	ctx.cr6.compare<int32_t>(ctx.r5.s32, -1, ctx.xer);
	// bne cr6,0x820835f4
	if (!ctx.cr6.eq) goto loc_820835F4;
	// li r5,-1
	ctx.r5.s64 = -1;
	// b 0x820835f8
	goto loc_820835F8;
loc_820835F4:
	// addi r5,r5,-2
	ctx.r5.s64 = ctx.r5.s64 + -2;
loc_820835F8:
	// addi r30,r31,2
	ctx.r30.s64 = ctx.r31.s64 + 2;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82083418
	ctx.lr = 0x8208360C;
	sub_82083418(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8208361c
	if (ctx.cr0.eq) goto loc_8208361C;
	// stb r26,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r26.u8);
	// b 0x82083938
	goto loc_82083938;
loc_8208361C:
	// lbz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,45
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 45, ctx.xer);
	// bne cr6,0x82083630
	if (!ctx.cr6.eq) goto loc_82083630;
	// stb r11,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r11.u8);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
loc_82083630:
	// subfic r11,r29,0
	ctx.xer.ca = ctx.r29.u32 <= 0;
	ctx.r11.s64 = 0 - ctx.r29.s64;
	// stb r28,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r28.u8);
	// li r4,101
	ctx.r4.s64 = 101;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwinm r11,r11,0,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFE0;
	// addi r11,r11,120
	ctx.r11.s64 = ctx.r11.s64 + 120;
	// stbu r11,1(r31)
	ea = 1 + ctx.r31.u32;
	PPC_STORE_U8(ea, ctx.r11.u8);
	ctx.r31.u32 = ea;
	// addi r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 1;
	// bl 0x82085440
	ctx.lr = 0x82083654;
	sub_82085440(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82083934
	if (ctx.cr0.eq) goto loc_82083934;
	// subfic r11,r29,0
	ctx.xer.ca = ctx.r29.u32 <= 0;
	ctx.r11.s64 = 0 - ctx.r29.s64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwinm r11,r11,0,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFE0;
	// addi r11,r11,112
	ctx.r11.s64 = ctx.r11.s64 + 112;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r11.u8);
	// stb r26,3(r3)
	PPC_STORE_U8(ctx.r3.u32 + 3, ctx.r26.u8);
	// b 0x82083934
	goto loc_82083934;
loc_82083678:
	// clrldi r11,r11,63
	ctx.r11.u64 = ctx.r11.u64 & 0x1;
	// li r27,45
	ctx.r27.s64 = 45;
	// cmpldi cr6,r11,0
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, 0, ctx.xer);
	// beq cr6,0x82083690
	if (ctx.cr6.eq) goto loc_82083690;
	// stb r27,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r27.u8);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
loc_82083690:
	// subfic r11,r29,0
	ctx.xer.ca = ctx.r29.u32 <= 0;
	ctx.r11.s64 = 0 - ctx.r29.s64;
	// stb r28,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r28.u8);
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// subfic r10,r29,0
	ctx.xer.ca = ctx.r29.u32 <= 0;
	ctx.r10.s64 = 0 - ctx.r29.s64;
	// rlwinm r11,r11,0,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFE0;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// addi r11,r11,120
	ctx.r11.s64 = ctx.r11.s64 + 120;
	// rlwinm r10,r10,0,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFE0;
	// stbu r11,1(r31)
	ea = 1 + ctx.r31.u32;
	PPC_STORE_U8(ea, ctx.r11.u8);
	ctx.r31.u32 = ea;
	// ld r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// rlwinm r9,r11,0,20,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFE;
	// addi r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 1;
	// addi r5,r10,39
	ctx.r5.s64 = ctx.r10.s64 + 39;
	// cmpldi cr6,r9,0
	ctx.cr6.compare<uint64_t>(ctx.r9.u64, 0, ctx.xer);
	// bne cr6,0x820836f4
	if (!ctx.cr6.eq) goto loc_820836F4;
	// stb r28,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r28.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// ld r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// rldicr r10,r10,0,51
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 0) & 0xFFFFFFFFFFFFF000;
	// cmpldi cr6,r10,0
	ctx.cr6.compare<uint64_t>(ctx.r10.u64, 0, ctx.xer);
	// bne cr6,0x820836ec
	if (!ctx.cr6.eq) goto loc_820836EC;
	// mr r30,r26
	ctx.r30.u64 = ctx.r26.u64;
	// b 0x82083700
	goto loc_82083700;
loc_820836EC:
	// li r30,1022
	ctx.r30.s64 = 1022;
	// b 0x82083700
	goto loc_82083700;
loc_820836F4:
	// li r10,49
	ctx.r10.s64 = 49;
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_82083700:
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne cr6,0x82083718
	if (!ctx.cr6.eq) goto loc_82083718;
	// stb r26,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r26.u8);
	// b 0x8208372c
	goto loc_8208372C;
loc_82083718:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lwz r11,3848(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 3848);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// stb r11,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, ctx.r11.u8);
loc_8208372C:
	// ld r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// rldicr r11,r11,0,51
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 0) & 0xFFFFFFFFFFFFF000;
	// cmpldi cr6,r11,0
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, 0, ctx.xer);
	// ble cr6,0x82083810
	if (!ctx.cr6.gt) goto loc_82083810;
	// li r10,15
	ctx.r10.s64 = 15;
	// rldicr r10,r10,48,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 48) & 0xFFFF000000000000;
loc_82083744:
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// ble cr6,0x8208379c
	if (!ctx.cr6.gt) goto loc_8208379C;
	// ld r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// extsh r9,r7
	ctx.r9.s64 = ctx.r7.s16;
	// rldicl r11,r11,52,12
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 52) & 0xFFFFFFFFFFFFF;
	// and r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 & ctx.r10.u64;
	// srd r11,r11,r9
	ctx.r11.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r11.u64 >> (ctx.r9.u8 & 0x7F));
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// addi r11,r11,48
	ctx.r11.s64 = ctx.r11.s64 + 48;
	// clrlwi r9,r11,16
	ctx.r9.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplwi cr6,r9,57
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 57, ctx.xer);
	// ble cr6,0x82083780
	if (!ctx.cr6.gt) goto loc_82083780;
	// clrlwi r11,r5,16
	ctx.r11.u64 = ctx.r5.u32 & 0xFFFF;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
loc_82083780:
	// addi r9,r7,-4
	ctx.r9.s64 = ctx.r7.s64 + -4;
	// stb r11,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r11.u8);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// extsh. r7,r9
	ctx.r7.s64 = ctx.r9.s16;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// rldicl r10,r10,60,4
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 60) & 0xFFFFFFFFFFFFFFF;
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// bge 0x82083744
	if (!ctx.cr0.lt) goto loc_82083744;
loc_8208379C:
	// extsh. r11,r7
	ctx.r11.s64 = ctx.r7.s16;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt 0x82083810
	if (ctx.cr0.lt) goto loc_82083810;
	// ld r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// extsh r9,r7
	ctx.r9.s64 = ctx.r7.s16;
	// rldicl r11,r11,52,12
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 52) & 0xFFFFFFFFFFFFF;
	// and r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 & ctx.r10.u64;
	// srd r11,r11,r9
	ctx.r11.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r11.u64 >> (ctx.r9.u8 & 0x7F));
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// ble cr6,0x82083810
	if (!ctx.cr6.gt) goto loc_82083810;
	// addi r11,r8,-1
	ctx.r11.s64 = ctx.r8.s64 + -1;
loc_820837C8:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// cmpwi cr6,r10,102
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 102, ctx.xer);
	// beq cr6,0x820837e0
	if (ctx.cr6.eq) goto loc_820837E0;
	// cmpwi cr6,r10,70
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 70, ctx.xer);
	// bne cr6,0x820837ec
	if (!ctx.cr6.eq) goto loc_820837EC;
loc_820837E0:
	// stb r28,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r28.u8);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// b 0x820837c8
	goto loc_820837C8;
loc_820837EC:
	// cmplw cr6,r11,r4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x82083804
	if (ctx.cr6.eq) goto loc_82083804;
	// cmpwi cr6,r10,57
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 57, ctx.xer);
	// bne cr6,0x82083808
	if (!ctx.cr6.eq) goto loc_82083808;
	// addi r10,r5,58
	ctx.r10.s64 = ctx.r5.s64 + 58;
	// b 0x8208380c
	goto loc_8208380C;
loc_82083804:
	// lbzu r10,-1(r11)
	ea = -1 + ctx.r11.u32;
	ctx.r10.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
loc_82083808:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_8208380C:
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
loc_82083810:
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// ble cr6,0x82083838
	if (!ctx.cr6.gt) goto loc_82083838;
	// addi r11,r8,-1
	ctx.r11.s64 = ctx.r8.s64 + -1;
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq 0x82083834
	if (ctx.cr0.eq) goto loc_82083834;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
loc_8208382C:
	// stbu r10,1(r11)
	ea = 1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r10.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x8208382c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8208382C;
loc_82083834:
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
loc_82083838:
	// lbz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82083848
	if (!ctx.cr0.eq) goto loc_82083848;
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
loc_82083848:
	// subfic r11,r29,0
	ctx.xer.ca = ctx.r29.u32 <= 0;
	ctx.r11.s64 = 0 - ctx.r29.s64;
	// addi r10,r8,1
	ctx.r10.s64 = ctx.r8.s64 + 1;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwinm r11,r11,0,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFE0;
	// addi r11,r11,112
	ctx.r11.s64 = ctx.r11.s64 + 112;
	// stb r11,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r11.u8);
	// ld r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// rldicl r11,r11,63,53
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 63) & 0x7FF;
	// subf r11,r30,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r30.s64;
	// cmpdi cr6,r11,0
	ctx.cr6.compare<int64_t>(ctx.r11.s64, 0, ctx.xer);
	// blt cr6,0x82083880
	if (ctx.cr6.lt) goto loc_82083880;
	// li r9,43
	ctx.r9.s64 = 43;
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// b 0x82083888
	goto loc_82083888;
loc_82083880:
	// stb r27,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r27.u8);
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
loc_82083888:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpdi cr6,r11,1000
	ctx.cr6.compare<int64_t>(ctx.r11.s64, 1000, ctx.xer);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// stb r28,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r28.u8);
	// blt cr6,0x820838c8
	if (ctx.cr6.lt) goto loc_820838C8;
	// li r9,1000
	ctx.r9.s64 = 1000;
	// divd r7,r11,r9
	ctx.r7.s64 = ppc_divd(ctx.r11.s64, ctx.r9.s64);
	// divd r6,r11,r9
	ctx.r6.s64 = ppc_divd(ctx.r11.s64, ctx.r9.s64);
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// mulli r7,r6,1000
	ctx.r7.s64 = ctx.r6.s64 * 1000;
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// subf r11,r7,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r7.s64;
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x820838d0
	if (!ctx.cr6.eq) goto loc_820838D0;
loc_820838C8:
	// cmpdi cr6,r11,100
	ctx.cr6.compare<int64_t>(ctx.r11.s64, 100, ctx.xer);
	// blt cr6,0x820838f4
	if (ctx.cr6.lt) goto loc_820838F4;
loc_820838D0:
	// li r9,100
	ctx.r9.s64 = 100;
	// divd r7,r11,r9
	ctx.r7.s64 = ppc_divd(ctx.r11.s64, ctx.r9.s64);
	// divd r6,r11,r9
	ctx.r6.s64 = ppc_divd(ctx.r11.s64, ctx.r9.s64);
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// mulli r7,r6,100
	ctx.r7.s64 = ctx.r6.s64 * 100;
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// subf r11,r7,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r7.s64;
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_820838F4:
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x82083904
	if (!ctx.cr6.eq) goto loc_82083904;
	// cmpdi cr6,r11,10
	ctx.cr6.compare<int64_t>(ctx.r11.s64, 10, ctx.xer);
	// blt cr6,0x82083928
	if (ctx.cr6.lt) goto loc_82083928;
loc_82083904:
	// li r9,10
	ctx.r9.s64 = 10;
	// divd r8,r11,r9
	ctx.r8.s64 = ppc_divd(ctx.r11.s64, ctx.r9.s64);
	// divd r7,r11,r9
	ctx.r7.s64 = ppc_divd(ctx.r11.s64, ctx.r9.s64);
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// mulli r8,r7,10
	ctx.r8.s64 = ctx.r7.s64 * 10;
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// subf r11,r8,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r8.s64;
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_82083928:
	// addi r11,r11,48
	ctx.r11.s64 = ctx.r11.s64 + 48;
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r11.u8);
	// stb r26,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, ctx.r26.u8);
loc_82083934:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82083938:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82083940"))) PPC_WEAK_FUNC(sub_82083940);
PPC_FUNC_IMPL(__imp__sub_82083940) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x82083948;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// bne cr6,0x82083990
	if (!ctx.cr6.eq) goto loc_82083990;
loc_82083964:
	// bl 0x8207d4d8
	ctx.lr = 0x82083968;
	sub_8207D4D8(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d940
	ctx.lr = 0x82083988;
	sub_8207D940(ctx, base);
	// li r3,22
	ctx.r3.s64 = 22;
	// b 0x82083afc
	goto loc_82083AFC;
loc_82083990:
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82083964
	if (ctx.cr6.eq) goto loc_82083964;
	// extsb. r26,r7
	ctx.r26.s64 = ctx.r7.s8;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// li r28,48
	ctx.r28.s64 = 48;
	// beq 0x820839d0
	if (ctx.cr0.eq) goto loc_820839D0;
	// cmpw cr6,r10,r27
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r27.s32, ctx.xer);
	// bne cr6,0x820839d0
	if (!ctx.cr6.eq) goto loc_820839D0;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r11,-45
	ctx.r11.s64 = ctx.r11.s64 + -45;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// stb r28,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r28.u8);
	// stb r9,1(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1, ctx.r9.u8);
loc_820839D0:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,45
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 45, ctx.xer);
	// bne cr6,0x820839e8
	if (!ctx.cr6.eq) goto loc_820839E8;
	// addi r30,r3,1
	ctx.r30.s64 = ctx.r3.s64 + 1;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r11.u8);
loc_820839E8:
	// lwz r11,4(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt cr6,0x82083a30
	if (ctx.cr6.gt) goto loc_82083A30;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_820839F8:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820839f8
	if (!ctx.cr6.eq) goto loc_820839F8;
	// subf r11,r30,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r30.s64;
	// addi r31,r30,1
	ctx.r31.s64 = ctx.r30.s64 + 1;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// bl 0x8207d870
	ctx.lr = 0x82083A28;
	sub_8207D870(ctx, base);
	// stb r28,0(r30)
	PPC_STORE_U8(ctx.r30.u32 + 0, ctx.r28.u8);
	// b 0x82083a34
	goto loc_82083A34;
loc_82083A30:
	// add r31,r11,r30
	ctx.r31.u64 = ctx.r11.u64 + ctx.r30.u64;
loc_82083A34:
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// ble cr6,0x82083af8
	if (!ctx.cr6.gt) goto loc_82083AF8;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
loc_82083A40:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82083a40
	if (!ctx.cr6.eq) goto loc_82083A40;
	// subf r11,r31,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r31.s64;
	// addi r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 1;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// bl 0x8207d870
	ctx.lr = 0x82083A70;
	sub_8207D870(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lwz r11,3848(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 3848);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// stb r11,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r11.u8);
	// lwz r11,4(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x82083af8
	if (!ctx.cr6.lt) goto loc_82083AF8;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq cr6,0x82083aa0
	if (ctx.cr6.eq) goto loc_82083AA0;
	// neg r27,r11
	ctx.r27.s64 = -ctx.r11.s64;
	// b 0x82083ab0
	goto loc_82083AB0;
loc_82083AA0:
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
	// cmpw cr6,r27,r11
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x82083ab0
	if (ctx.cr6.lt) goto loc_82083AB0;
	// mr r27,r11
	ctx.r27.u64 = ctx.r11.u64;
loc_82083AB0:
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq cr6,0x82083ae8
	if (ctx.cr6.eq) goto loc_82083AE8;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_82083ABC:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82083abc
	if (!ctx.cr6.eq) goto loc_82083ABC;
	// subf r11,r30,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r30.s64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// add r3,r30,r27
	ctx.r3.u64 = ctx.r30.u64 + ctx.r27.u64;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// bl 0x8207d870
	ctx.lr = 0x82083AE8;
	sub_8207D870(ctx, base);
loc_82083AE8:
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// li r4,48
	ctx.r4.s64 = 48;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207da20
	ctx.lr = 0x82083AF8;
	sub_8207DA20(ctx, base);
loc_82083AF8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82083AFC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82083B04"))) PPC_WEAK_FUNC(sub_82083B04);
PPC_FUNC_IMPL(__imp__sub_82083B04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82083B08"))) PPC_WEAK_FUNC(sub_82083B08);
PPC_FUNC_IMPL(__imp__sub_82083B08) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82083B10;
	__savegprlr_29(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// ld r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// li r6,22
	ctx.r6.s64 = 22;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x820858c8
	ctx.lr = 0x82083B34;
	sub_820858C8(ctx, base);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82083b68
	if (!ctx.cr6.eq) goto loc_82083B68;
loc_82083B3C:
	// bl 0x8207d4d8
	ctx.lr = 0x82083B40;
	sub_8207D4D8(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d940
	ctx.lr = 0x82083B60;
	sub_8207D940(ctx, base);
	// li r3,22
	ctx.r3.s64 = 22;
	// b 0x82083be0
	goto loc_82083BE0;
loc_82083B68:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82083b3c
	if (ctx.cr6.eq) goto loc_82083B3C;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r29,-1
	ctx.cr6.compare<int32_t>(ctx.r29.s32, -1, ctx.xer);
	// bne cr6,0x82083b84
	if (!ctx.cr6.eq) goto loc_82083B84;
	// li r4,-1
	ctx.r4.s64 = -1;
	// b 0x82083b94
	goto loc_82083B94;
loc_82083B84:
	// addi r10,r11,-45
	ctx.r10.s64 = ctx.r11.s64 + -45;
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// subf r4,r10,r29
	ctx.r4.s64 = ctx.r29.s64 - ctx.r10.s64;
loc_82083B94:
	// addi r10,r11,-45
	ctx.r10.s64 = ctx.r11.s64 + -45;
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// add r5,r11,r30
	ctx.r5.u64 = ctx.r11.u64 + ctx.r30.u64;
	// rlwinm r11,r10,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// add r3,r11,r31
	ctx.r3.u64 = ctx.r11.u64 + ctx.r31.u64;
	// bl 0x82085660
	ctx.lr = 0x82083BB4;
	sub_82085660(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82083bc8
	if (ctx.cr0.eq) goto loc_82083BC8;
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r11.u8);
	// b 0x82083be0
	goto loc_82083BE0;
loc_82083BC8:
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82083940
	ctx.lr = 0x82083BE0;
	sub_82083940(ctx, base);
loc_82083BE0:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82083BE8"))) PPC_WEAK_FUNC(sub_82083BE8);
PPC_FUNC_IMPL(__imp__sub_82083BE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x82083BF0;
	__savegprlr_26(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// ld r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// li r6,22
	ctx.r6.s64 = 22;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r26,r7
	ctx.r26.u64 = ctx.r7.u64;
	// bl 0x820858c8
	ctx.lr = 0x82083C18;
	sub_820858C8(ctx, base);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x82083c4c
	if (!ctx.cr6.eq) goto loc_82083C4C;
loc_82083C20:
	// bl 0x8207d4d8
	ctx.lr = 0x82083C24;
	sub_8207D4D8(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d940
	ctx.lr = 0x82083C44;
	sub_8207D940(ctx, base);
	// li r3,22
	ctx.r3.s64 = 22;
	// b 0x82083d24
	goto loc_82083D24;
loc_82083C4C:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82083c20
	if (ctx.cr6.eq) goto loc_82083C20;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r31,-1
	ctx.cr6.compare<int32_t>(ctx.r31.s32, -1, ctx.xer);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r4,-1
	ctx.r4.s64 = -1;
	// addi r11,r11,-45
	ctx.r11.s64 = ctx.r11.s64 + -45;
	// addi r30,r10,-1
	ctx.r30.s64 = ctx.r10.s64 + -1;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// add r28,r11,r29
	ctx.r28.u64 = ctx.r11.u64 + ctx.r29.u64;
	// beq cr6,0x82083c80
	if (ctx.cr6.eq) goto loc_82083C80;
	// subf r4,r11,r31
	ctx.r4.s64 = ctx.r31.s64 - ctx.r11.s64;
loc_82083C80:
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82085660
	ctx.lr = 0x82083C90;
	sub_82085660(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82083ca4
	if (ctx.cr0.eq) goto loc_82083CA4;
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,0(r29)
	PPC_STORE_U8(ctx.r29.u32 + 0, ctx.r11.u8);
	// b 0x82083d24
	goto loc_82083D24;
loc_82083CA4:
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// subfc r10,r11,r30
	ctx.xer.ca = ctx.r30.u32 >= ctx.r11.u32;
	ctx.r10.s64 = ctx.r30.s64 - ctx.r11.s64;
	// eqv r9,r11,r30
	ctx.r9.u64 = ~(ctx.r11.u64 ^ ctx.r30.u64); // FIX 2026-07-24: eqv was silently dropped by the recompiler
	// cmpwi cr6,r11,-4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -4, ctx.xer);
	// rlwinm r10,r9,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1;
	// addze r10,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r10.s64 = temp.s64;
	// clrlwi r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	// blt cr6,0x82083d08
	if (ctx.cr6.lt) goto loc_82083D08;
	// cmpw cr6,r11,r27
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r27.s32, ctx.xer);
	// bge cr6,0x82083d08
	if (!ctx.cr6.lt) goto loc_82083D08;
	// extsb. r11,r10
	ctx.r11.s64 = ctx.r10.s8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82083cec
	if (ctx.cr0.eq) goto loc_82083CEC;
loc_82083CD8:
	// lbz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82083cd8
	if (!ctx.cr0.eq) goto loc_82083CD8;
	// stb r11,-2(r28)
	PPC_STORE_U8(ctx.r28.u32 + -2, ctx.r11.u8);
loc_82083CEC:
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82083940
	ctx.lr = 0x82083D04;
	sub_82083940(ctx, base);
	// b 0x82083d24
	goto loc_82083D24;
loc_82083D08:
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820831a0
	ctx.lr = 0x82083D24;
	sub_820831A0(ctx, base);
loc_82083D24:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82083D2C"))) PPC_WEAK_FUNC(sub_82083D2C);
PPC_FUNC_IMPL(__imp__sub_82083D2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82083D30"))) PPC_WEAK_FUNC(sub_82083D30);
PPC_FUNC_IMPL(__imp__sub_82083D30) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// cmpwi cr6,r11,101
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 101, ctx.xer);
	// beq cr6,0x82083d78
	if (ctx.cr6.eq) goto loc_82083D78;
	// cmpwi cr6,r11,69
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 69, ctx.xer);
	// beq cr6,0x82083d78
	if (ctx.cr6.eq) goto loc_82083D78;
	// cmpwi cr6,r11,102
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 102, ctx.xer);
	// bne cr6,0x82083d60
	if (!ctx.cr6.eq) goto loc_82083D60;
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// b 0x82083b08
	sub_82083B08(ctx, base);
	return;
loc_82083D60:
	// cmpwi cr6,r11,97
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 97, ctx.xer);
	// beq cr6,0x82083d74
	if (ctx.cr6.eq) goto loc_82083D74;
	// cmpwi cr6,r11,65
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 65, ctx.xer);
	// beq cr6,0x82083d74
	if (ctx.cr6.eq) goto loc_82083D74;
	// b 0x82083be8
	sub_82083BE8(ctx, base);
	return;
loc_82083D74:
	// b 0x82083520
	sub_82083520(ctx, base);
	return;
loc_82083D78:
	// b 0x82083418
	sub_82083418(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82083D7C"))) PPC_WEAK_FUNC(sub_82083D7C);
PPC_FUNC_IMPL(__imp__sub_82083D7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82083D80"))) PPC_WEAK_FUNC(sub_82083D80);
PPC_FUNC_IMPL(__imp__sub_82083D80) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// cmpwi cr6,r11,101
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 101, ctx.xer);
	// beq cr6,0x82083dcc
	if (ctx.cr6.eq) goto loc_82083DCC;
	// cmpwi cr6,r11,69
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 69, ctx.xer);
	// beq cr6,0x82083dcc
	if (ctx.cr6.eq) goto loc_82083DCC;
	// cmpwi cr6,r11,102
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 102, ctx.xer);
	// bne cr6,0x82083dac
	if (!ctx.cr6.eq) goto loc_82083DAC;
	// li r7,0
	ctx.r7.s64 = 0;
	// b 0x82083b08
	sub_82083B08(ctx, base);
	return;
loc_82083DAC:
	// cmpwi cr6,r11,97
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 97, ctx.xer);
	// beq cr6,0x82083dc4
	if (ctx.cr6.eq) goto loc_82083DC4;
	// cmpwi cr6,r11,65
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 65, ctx.xer);
	// beq cr6,0x82083dc4
	if (ctx.cr6.eq) goto loc_82083DC4;
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x82083be8
	sub_82083BE8(ctx, base);
	return;
loc_82083DC4:
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x82083520
	sub_82083520(ctx, base);
	return;
loc_82083DCC:
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x82083418
	sub_82083418(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82083DD4"))) PPC_WEAK_FUNC(sub_82083DD4);
PPC_FUNC_IMPL(__imp__sub_82083DD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82083DD8"))) PPC_WEAK_FUNC(sub_82083DD8);
PPC_FUNC_IMPL(__imp__sub_82083DD8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82083DE0;
	__savegprlr_29(ctx, base);
	// stfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.f30.u64);
	// stfd f31,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-16377
	ctx.r11.s64 = -1073283072;
	// stfd f1,160(r1)
	PPC_STORE_U64(ctx.r1.u32 + 160, ctx.f1.u64);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// ori r29,r11,65279
	ctx.r29.u64 = ctx.r11.u64 | 65279;
	// li r3,248
	ctx.r3.s64 = 248;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82084910
	ctx.lr = 0x82083E0C;
	sub_82084910(ctx, base);
	// lhz r11,160(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 160);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// rlwinm r11,r11,0,17,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x7FF0;
	// cmplwi cr6,r11,32752
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32752, ctx.xer);
	// bne cr6,0x82083e98
	if (!ctx.cr6.eq) goto loc_82083E98;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8207fc50
	ctx.lr = 0x82083E28;
	sub_8207FC50(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble 0x82083e64
	if (!ctx.cr0.gt) goto loc_82083E64;
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// ble cr6,0x82083f8c
	if (!ctx.cr6.gt) goto loc_82083F8C;
	// cmpwi cr6,r3,3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 3, ctx.xer);
	// bne cr6,0x82083e64
	if (!ctx.cr6.eq) goto loc_82083E64;
	// extsw r11,r31
	ctx.r11.s64 = ctx.r31.s32;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// li r3,25
	ctx.r3.s64 = 25;
	// lfd f0,88(r1)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f2,f0
	ctx.f2.f64 = double(ctx.f0.s64);
	// bl 0x820847a8
	ctx.lr = 0x82083E60;
	sub_820847A8(ctx, base);
	// b 0x82083f9c
	goto loc_82083F9C;
loc_82083E64:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// extsw r10,r31
	ctx.r10.s64 = ctx.r31.s32;
	// li r3,8
	ctx.r3.s64 = 8;
	// std r10,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lfd f13,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f2,f13
	ctx.f2.f64 = double(ctx.f13.s64);
	// lfd f0,2064(r11)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r11.u32 + 2064);
	// fadd f3,f31,f0
	ctx.f3.f64 = ctx.f31.f64 + ctx.f0.f64;
loc_82083E84:
	// li r4,25
	ctx.r4.s64 = 25;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// bl 0x82084828
	ctx.lr = 0x82083E94;
	sub_82084828(ctx, base);
	// b 0x82083f9c
	goto loc_82083F9C;
loc_82083E98:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfd f30,2432(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r11.u32 + 2432);
	// fcmpu cr6,f31,f30
	ctx.cr6.compare(ctx.f31.f64, ctx.f30.f64);
	// beq cr6,0x82083f8c
	if (ctx.cr6.eq) goto loc_82083F8C;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8207fcd8
	ctx.lr = 0x82083EB4;
	sub_8207FCD8(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bge cr6,0x82083ed4
	if (!ctx.cr6.lt) goto loc_82083ED4;
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// subf r10,r31,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r31.s64;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x82083f48
	if (ctx.cr6.lt) goto loc_82083F48;
	// b 0x82083ee8
	goto loc_82083EE8;
loc_82083ED4:
	// lis r10,32767
	ctx.r10.s64 = 2147418112;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
	// subf r10,r31,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r31.s64;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bgt cr6,0x82083ef4
	if (ctx.cr6.gt) goto loc_82083EF4;
loc_82083EE8:
	// add r4,r11,r31
	ctx.r4.u64 = ctx.r11.u64 + ctx.r31.u64;
	// cmpwi cr6,r4,2560
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 2560, ctx.xer);
	// ble cr6,0x82083f20
	if (!ctx.cr6.gt) goto loc_82083F20;
loc_82083EF4:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// fmr f2,f1
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f1.f64;
	// lfd f1,2392(r11)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r11.u32 + 2392);
	// bl 0x820802f0
	ctx.lr = 0x82083F04;
	sub_820802F0(ctx, base);
	// extsw r11,r31
	ctx.r11.s64 = ctx.r31.s32;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
loc_82083F10:
	// li r3,17
	ctx.r3.s64 = 17;
loc_82083F14:
	// fmr f3,f1
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = ctx.f1.f64;
loc_82083F18:
	// fcfid f2,f0
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = double(ctx.f0.s64);
	// b 0x82083e84
	goto loc_82083E84;
loc_82083F20:
	// cmpwi cr6,r4,1024
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 1024, ctx.xer);
	// ble cr6,0x82083f40
	if (!ctx.cr6.gt) goto loc_82083F40;
	// addi r4,r4,-1536
	ctx.r4.s64 = ctx.r4.s64 + -1536;
	// bl 0x8207fc10
	ctx.lr = 0x82083F30;
	sub_8207FC10(ctx, base);
	// extsw r11,r31
	ctx.r11.s64 = ctx.r31.s32;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// b 0x82083f10
	goto loc_82083F10;
loc_82083F40:
	// cmpwi cr6,r4,-2557
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -2557, ctx.xer);
	// bge cr6,0x82083f60
	if (!ctx.cr6.lt) goto loc_82083F60;
loc_82083F48:
	// extsw r11,r31
	ctx.r11.s64 = ctx.r31.s32;
	// fmul f3,f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = ctx.f1.f64 * ctx.f30.f64;
	// li r3,18
	ctx.r3.s64 = 18;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f0,88(r1)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// b 0x82083f18
	goto loc_82083F18;
loc_82083F60:
	// cmpwi cr6,r4,-1021
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1021, ctx.xer);
	// bge cr6,0x82083f84
	if (!ctx.cr6.lt) goto loc_82083F84;
	// addi r4,r4,1536
	ctx.r4.s64 = ctx.r4.s64 + 1536;
	// bl 0x8207fc10
	ctx.lr = 0x82083F70;
	sub_8207FC10(ctx, base);
	// extsw r11,r31
	ctx.r11.s64 = ctx.r31.s32;
	// li r3,18
	ctx.r3.s64 = 18;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// b 0x82083f14
	goto loc_82083F14;
loc_82083F84:
	// bl 0x8207fc10
	ctx.lr = 0x82083F88;
	sub_8207FC10(ctx, base);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
loc_82083F8C:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82084910
	ctx.lr = 0x82083F98;
	sub_82084910(ctx, base);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
loc_82083F9C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82083FAC"))) PPC_WEAK_FUNC(sub_82083FAC);
PPC_FUNC_IMPL(__imp__sub_82083FAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82083FB0"))) PPC_WEAK_FUNC(sub_82083FB0);
PPC_FUNC_IMPL(__imp__sub_82083FB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x82083FB8;
	__savegprlr_25(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r3,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r3.u32);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// rlwinm. r4,r5,0,27,27
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// mr r26,r8
	ctx.r26.u64 = ctx.r8.u64;
	// mr r25,r9
	ctx.r25.u64 = ctx.r9.u64;
	// lwz r10,180(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r11.u32);
	// lwz r10,180(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// stw r11,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r11.u32);
	// beq 0x82084010
	if (ctx.cr0.eq) goto loc_82084010;
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lis r27,-16384
	ctx.r27.s64 = -1073741824;
	// ori r27,r27,143
	ctx.r27.u64 = ctx.r27.u64 | 143;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// oris r10,r10,32768
	ctx.r10.u64 = ctx.r10.u64 | 2147483648;
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// b 0x82084014
	goto loc_82084014;
loc_82084010:
	// lwz r27,80(r1)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_82084014:
	// rlwinm. r11,r5,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82084034
	if (ctx.cr0.eq) goto loc_82084034;
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lis r27,-16384
	ctx.r27.s64 = -1073741824;
	// ori r27,r27,147
	ctx.r27.u64 = ctx.r27.u64 | 147;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// oris r10,r10,16384
	ctx.r10.u64 = ctx.r10.u64 | 1073741824;
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
loc_82084034:
	// clrlwi. r11,r5,31
	ctx.r11.u64 = ctx.r5.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82084054
	if (ctx.cr0.eq) goto loc_82084054;
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lis r27,-16384
	ctx.r27.s64 = -1073741824;
	// ori r27,r27,145
	ctx.r27.u64 = ctx.r27.u64 | 145;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// oris r10,r10,8192
	ctx.r10.u64 = ctx.r10.u64 | 536870912;
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
loc_82084054:
	// rlwinm. r11,r5,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82084074
	if (ctx.cr0.eq) goto loc_82084074;
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lis r27,-16384
	ctx.r27.s64 = -1073741824;
	// ori r27,r27,142
	ctx.r27.u64 = ctx.r27.u64 | 142;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// oris r10,r10,4096
	ctx.r10.u64 = ctx.r10.u64 | 268435456;
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
loc_82084074:
	// rlwinm. r11,r5,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82084094
	if (ctx.cr0.eq) goto loc_82084094;
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lis r27,-16384
	ctx.r27.s64 = -1073741824;
	// ori r27,r27,144
	ctx.r27.u64 = ctx.r27.u64 | 144;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// oris r10,r10,2048
	ctx.r10.u64 = ctx.r10.u64 | 134217728;
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
loc_82084094:
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// not r10,r10
	ctx.r10.u64 = ~ctx.r10.u64;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// rlwimi r9,r10,20,4,4
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 20) & 0x8000000) | (ctx.r9.u64 & 0xFFFFFFFFF7FFFFFF);
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// not r10,r10
	ctx.r10.u64 = ~ctx.r10.u64;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// rlwimi r9,r10,24,3,3
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 24) & 0x10000000) | (ctx.r9.u64 & 0xFFFFFFFFEFFFFFFF);
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// not r10,r10
	ctx.r10.u64 = ~ctx.r10.u64;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// rlwimi r9,r10,23,2,2
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 23) & 0x20000000) | (ctx.r9.u64 & 0xFFFFFFFFDFFFFFFF);
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// not r10,r10
	ctx.r10.u64 = ~ctx.r10.u64;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// rlwimi r9,r10,25,1,1
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 25) & 0x40000000) | (ctx.r9.u64 & 0xFFFFFFFFBFFFFFFF);
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// not r10,r10
	ctx.r10.u64 = ~ctx.r10.u64;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// rlwimi r9,r10,28,0,0
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 28) & 0x80000000) | (ctx.r9.u64 & 0xFFFFFFFF7FFFFFFF);
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// bl 0x82084940
	ctx.lr = 0x82084110;
	sub_82084940(ctx, base);
	// rlwinm. r11,r3,0,2,2
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x20000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82084128
	if (ctx.cr0.eq) goto loc_82084128;
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// oris r10,r10,2048
	ctx.r10.u64 = ctx.r10.u64 | 134217728;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
loc_82084128:
	// rlwinm. r11,r3,0,5,5
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x4000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82084140
	if (ctx.cr0.eq) goto loc_82084140;
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// oris r10,r10,4096
	ctx.r10.u64 = ctx.r10.u64 | 268435456;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
loc_82084140:
	// rlwinm. r11,r3,0,3,3
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x10000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82084158
	if (ctx.cr0.eq) goto loc_82084158;
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// oris r10,r10,8192
	ctx.r10.u64 = ctx.r10.u64 | 536870912;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
loc_82084158:
	// rlwinm. r11,r3,0,4,4
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82084170
	if (ctx.cr0.eq) goto loc_82084170;
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// oris r10,r10,16384
	ctx.r10.u64 = ctx.r10.u64 | 1073741824;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
loc_82084170:
	// rlwinm. r11,r3,0,6,6
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x2000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82084188
	if (ctx.cr0.eq) goto loc_82084188;
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// oris r10,r10,32768
	ctx.r10.u64 = ctx.r10.u64 | 2147483648;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
loc_82084188:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r30,1
	ctx.r30.s64 = 1;
	// clrlwi r11,r11,30
	ctx.r11.u64 = ctx.r11.u32 & 0x3;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x820841dc
	if (ctx.cr6.lt) goto loc_820841DC;
	// beq cr6,0x820841cc
	if (ctx.cr6.eq) goto loc_820841CC;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x820841bc
	if (ctx.cr6.lt) goto loc_820841BC;
	// bne cr6,0x820841ec
	if (!ctx.cr6.eq) goto loc_820841EC;
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// rlwimi r10,r30,30,0,1
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r30.u32, 30) & 0xC0000000) | (ctx.r10.u64 & 0xFFFFFFFF3FFFFFFF);
	// b 0x820841e8
	goto loc_820841E8;
loc_820841BC:
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// rlwimi r10,r30,31,0,1
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r30.u32, 31) & 0xC0000000) | (ctx.r10.u64 & 0xFFFFFFFF3FFFFFFF);
	// b 0x820841e8
	goto loc_820841E8;
loc_820841CC:
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// oris r10,r10,49152
	ctx.r10.u64 = ctx.r10.u64 | 3221225472;
	// b 0x820841e8
	goto loc_820841E8;
loc_820841DC:
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// clrlwi r10,r10,2
	ctx.r10.u64 = ctx.r10.u32 & 0x3FFFFFFF;
loc_820841E8:
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_820841EC:
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// rlwimi r10,r30,27,2,4
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r30.u32, 27) & 0x38000000) | (ctx.r10.u64 & 0xFFFFFFFFC7FFFFFF);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// rlwimi r10,r28,15,5,16
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r28.u32, 15) & 0x7FF8000) | (ctx.r10.u64 & 0xFFFFFFFFF8007FFF);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// oris r10,r10,32768
	ctx.r10.u64 = ctx.r10.u64 | 2147483648;
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// beq cr6,0x82084270
	if (ctx.cr6.eq) goto loc_82084270;
	// rlwinm r10,r10,0,5,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFF87FFFFFF;
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// stfs f0,16(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 16, temp.u32);
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 96);
	// oris r10,r10,32768
	ctx.r10.u64 = ctx.r10.u64 | 2147483648;
	// stw r10,96(r11)
	PPC_STORE_U32(ctx.r11.u32 + 96, ctx.r10.u32);
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 96);
	// rlwinm r10,r10,0,5,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFF87FFFFFF;
	// stw r10,96(r11)
	PPC_STORE_U32(ctx.r11.u32 + 96, ctx.r10.u32);
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lfs f0,0(r26)
	temp.u32 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 80, temp.u32);
	// b 0x820842b0
	goto loc_820842B0;
loc_82084270:
	// rlwimi r10,r30,27,1,4
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r30.u32, 27) & 0x78000000) | (ctx.r10.u64 & 0xFFFFFFFF87FFFFFF);
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lfd f0,0(r29)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r29.u32 + 0);
	// stfd f0,16(r11)
	PPC_STORE_U64(ctx.r11.u32 + 16, ctx.f0.u64);
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 96);
	// oris r10,r10,32768
	ctx.r10.u64 = ctx.r10.u64 | 2147483648;
	// stw r10,96(r11)
	PPC_STORE_U32(ctx.r11.u32 + 96, ctx.r10.u32);
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 96);
	// rlwimi r10,r30,27,1,4
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r30.u32, 27) & 0x78000000) | (ctx.r10.u64 & 0xFFFFFFFF87FFFFFF);
	// stw r10,96(r11)
	PPC_STORE_U32(ctx.r11.u32 + 96, ctx.r10.u32);
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lfd f0,0(r26)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r26.u32 + 0);
	// stfd f0,80(r11)
	PPC_STORE_U64(ctx.r11.u32 + 80, ctx.f0.u64);
loc_820842B0:
	// bl 0x820859e8
	ctx.lr = 0x820842B4;
	sub_820859E8(ctx, base);
	// addi r6,r1,180
	ctx.r6.s64 = ctx.r1.s64 + 180;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8208d908
	ctx.lr = 0x820842C8;
	sub_8208D908(ctx, base);
	// lwz r10,180(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r11,8(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// rlwinm. r11,r11,0,4,4
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820842e4
	if (ctx.cr0.eq) goto loc_820842E4;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r11,r11,0,25,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFF7F;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_820842E4:
	// lwz r11,8(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// rlwinm. r11,r11,0,3,3
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820842fc
	if (ctx.cr0.eq) goto loc_820842FC;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r11,r11,0,28,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_820842FC:
	// lwz r11,8(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// rlwinm. r11,r11,0,2,2
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82084314
	if (ctx.cr0.eq) goto loc_82084314;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r11,r11,0,26,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_82084314:
	// lwz r11,8(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// rlwinm. r11,r11,0,1,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8208432c
	if (ctx.cr0.eq) goto loc_8208432C;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r11,r11,0,27,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_8208432C:
	// lwz r11,8(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// rlwinm. r11,r11,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82084344
	if (ctx.cr0.eq) goto loc_82084344;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r11,r11,0,29,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_82084344:
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rlwinm r11,r11,2,30,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x3;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82084388
	if (ctx.cr6.lt) goto loc_82084388;
	// beq cr6,0x8208437c
	if (ctx.cr6.eq) goto loc_8208437C;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x82084370
	if (ctx.cr6.lt) goto loc_82084370;
	// bne cr6,0x82084394
	if (!ctx.cr6.eq) goto loc_82084394;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// rlwimi r11,r30,0,30,31
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r30.u32, 0) & 0x3) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFFFC);
	// b 0x82084390
	goto loc_82084390;
loc_82084370:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// rlwimi r11,r30,1,30,31
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r30.u32, 1) & 0x3) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFFFC);
	// b 0x82084390
	goto loc_82084390;
loc_8208437C:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// ori r11,r11,3
	ctx.r11.u64 = ctx.r11.u64 | 3;
	// b 0x82084390
	goto loc_82084390;
loc_82084388:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r11,r11,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFC;
loc_82084390:
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_82084394:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq cr6,0x820843a8
	if (ctx.cr6.eq) goto loc_820843A8;
	// lfs f0,80(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r26)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r26.u32 + 0, temp.u32);
	// b 0x820843b0
	goto loc_820843B0;
loc_820843A8:
	// lfd f0,80(r10)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r10.u32 + 80);
	// stfd f0,0(r26)
	PPC_STORE_U64(ctx.r26.u32 + 0, ctx.f0.u64);
loc_820843B0:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820843B8"))) PPC_WEAK_FUNC(sub_820843B8);
PPC_FUNC_IMPL(__imp__sub_820843B8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x820843C0;
	__savegprlr_27(ctx, base);
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// rlwinm. r11,r3,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// clrlwi r28,r3,27
	ctx.r28.u64 = ctx.r3.u32 & 0x1F;
	// beq 0x820843f8
	if (ctx.cr0.eq) goto loc_820843F8;
	// rlwinm. r11,r5,0,24,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820843f8
	if (ctx.cr0.eq) goto loc_820843F8;
	// lis r3,8192
	ctx.r3.s64 = 536870912;
	// bl 0x82084974
	ctx.lr = 0x820843F0;
	sub_82084974(ctx, base);
	// rlwinm r28,r28,0,29,27
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
	// b 0x820845dc
	goto loc_820845DC;
loc_820843F8:
	// rlwinm. r11,r29,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82084418
	if (ctx.cr0.eq) goto loc_82084418;
	// rlwinm. r11,r27,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82084418
	if (ctx.cr0.eq) goto loc_82084418;
	// lis r3,1024
	ctx.r3.s64 = 67108864;
	// bl 0x82084974
	ctx.lr = 0x82084410;
	sub_82084974(ctx, base);
	// rlwinm r28,r28,0,30,28
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// b 0x820845dc
	goto loc_820845DC;
loc_82084418:
	// clrlwi. r11,r29,31
	ctx.r11.u64 = ctx.r29.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820844e4
	if (ctx.cr0.eq) goto loc_820844E4;
	// rlwinm. r11,r27,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820844e4
	if (ctx.cr0.eq) goto loc_820844E4;
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// bl 0x82084974
	ctx.lr = 0x82084430;
	sub_82084974(ctx, base);
	// clrlwi r11,r27,30
	ctx.r11.u64 = ctx.r27.u32 & 0x3;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x820844ac
	if (ctx.cr6.lt) goto loc_820844AC;
	// beq cr6,0x8208448c
	if (ctx.cr6.eq) goto loc_8208448C;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x8208446c
	if (ctx.cr6.lt) goto loc_8208446C;
	// bne cr6,0x820844dc
	if (!ctx.cr6.eq) goto loc_820844DC;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfd f13,0(r30)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r30.u32 + 0);
	// lfd f0,2432(r11)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r11.u32 + 2432);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x820844cc
	if (!ctx.cr6.gt) goto loc_820844CC;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfd f0,2408(r11)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r11.u32 + 2408);
	// b 0x820844d8
	goto loc_820844D8;
loc_8208446C:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfd f13,0(r30)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r30.u32 + 0);
	// lfd f0,2432(r11)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r11.u32 + 2432);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bgt cr6,0x820844c0
	if (ctx.cr6.gt) goto loc_820844C0;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfd f0,2408(r11)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r11.u32 + 2408);
	// b 0x820844d4
	goto loc_820844D4;
loc_8208448C:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfd f13,0(r30)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r30.u32 + 0);
	// lfd f0,2432(r11)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r11.u32 + 2432);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// lfd f0,2408(r11)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r11.u32 + 2408);
	// bgt cr6,0x820844d8
	if (ctx.cr6.gt) goto loc_820844D8;
	// b 0x820844d4
	goto loc_820844D4;
loc_820844AC:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfd f13,0(r30)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r30.u32 + 0);
	// lfd f0,2432(r11)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r11.u32 + 2432);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x820844cc
	if (!ctx.cr6.gt) goto loc_820844CC;
loc_820844C0:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfd f0,2392(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r11.u32 + 2392);
	// b 0x820844d8
	goto loc_820844D8;
loc_820844CC:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfd f0,2392(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r11.u32 + 2392);
loc_820844D4:
	// fneg f0,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
loc_820844D8:
	// stfd f0,0(r30)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r30.u32 + 0, ctx.f0.u64);
loc_820844DC:
	// rlwinm r28,r28,0,0,30
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0xFFFFFFFE;
	// b 0x820845dc
	goto loc_820845DC;
loc_820844E4:
	// rlwinm. r11,r29,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820845dc
	if (ctx.cr0.eq) goto loc_820845DC;
	// rlwinm. r11,r27,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820845dc
	if (ctx.cr0.eq) goto loc_820845DC;
	// rlwinm. r11,r29,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r31,0
	ctx.r31.s64 = 0;
	// beq 0x82084504
	if (ctx.cr0.eq) goto loc_82084504;
	// li r31,1
	ctx.r31.s64 = 1;
loc_82084504:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfd f1,0(r30)
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r30.u32 + 0);
	// lfd f31,2432(r11)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r11.u32 + 2432);
	// fcmpu cr6,f1,f31
	ctx.cr6.compare(ctx.f1.f64, ctx.f31.f64);
	// beq cr6,0x820845c4
	if (ctx.cr6.eq) goto loc_820845C4;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8207fcd8
	ctx.lr = 0x82084520;
	sub_8207FCD8(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stfd f1,80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f1.u64);
	// addi r11,r11,-1536
	ctx.r11.s64 = ctx.r11.s64 + -1536;
	// cmpwi cr6,r11,-1074
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1074, ctx.xer);
	// bge cr6,0x82084540
	if (!ctx.cr6.lt) goto loc_82084540;
	// fmul f0,f1,f31
	ctx.f0.f64 = ctx.f1.f64 * ctx.f31.f64;
	// li r31,1
	ctx.r31.s64 = 1;
	// b 0x820845bc
	goto loc_820845BC;
loc_82084540:
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f1.f64, ctx.f31.f64);
	// li r9,1
	ctx.r9.s64 = 1;
	// blt cr6,0x82084550
	if (ctx.cr6.lt) goto loc_82084550;
	// li r9,0
	ctx.r9.s64 = 0;
loc_82084550:
	// lhz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,-1021
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1021, ctx.xer);
	// clrlwi r10,r10,28
	ctx.r10.u64 = ctx.r10.u32 & 0xF;
	// ori r10,r10,16
	ctx.r10.u64 = ctx.r10.u64 | 16;
	// sth r10,80(r1)
	PPC_STORE_U16(ctx.r1.u32 + 80, ctx.r10.u16);
	// bge cr6,0x820845ac
	if (!ctx.cr6.lt) goto loc_820845AC;
	// subfic r11,r11,-1021
	ctx.xer.ca = ctx.r11.u32 <= 4294966275;
	ctx.r11.s64 = -1021 - ctx.r11.s64;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_82084578:
	// clrlwi. r8,r11,31
	ctx.r8.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x8208458c
	if (ctx.cr0.eq) goto loc_8208458C;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne cr6,0x8208458c
	if (!ctx.cr6.eq) goto loc_8208458C;
	// li r31,1
	ctx.r31.s64 = 1;
loc_8208458C:
	// clrlwi. r8,r10,31
	ctx.r8.u64 = ctx.r10.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// rlwinm r11,r11,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// beq 0x8208459c
	if (ctx.cr0.eq) goto loc_8208459C;
	// oris r11,r11,32768
	ctx.r11.u64 = ctx.r11.u64 | 2147483648;
loc_8208459C:
	// rlwinm r10,r10,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// bdnz 0x82084578
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82084578;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
loc_820845AC:
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x820845bc
	if (ctx.cr6.eq) goto loc_820845BC;
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
loc_820845BC:
	// stfd f0,0(r30)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r30.u32 + 0, ctx.f0.u64);
	// b 0x820845c8
	goto loc_820845C8;
loc_820845C4:
	// li r31,1
	ctx.r31.s64 = 1;
loc_820845C8:
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq cr6,0x820845d8
	if (ctx.cr6.eq) goto loc_820845D8;
	// lis r3,2048
	ctx.r3.s64 = 134217728;
	// bl 0x82084974
	ctx.lr = 0x820845D8;
	sub_82084974(ctx, base);
loc_820845D8:
	// rlwinm r28,r28,0,31,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
loc_820845DC:
	// rlwinm. r11,r29,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820845f8
	if (ctx.cr0.eq) goto loc_820845F8;
	// rlwinm. r11,r27,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820845f8
	if (ctx.cr0.eq) goto loc_820845F8;
	// lis r3,512
	ctx.r3.s64 = 33554432;
	// bl 0x82084974
	ctx.lr = 0x820845F4;
	sub_82084974(ctx, base);
	// rlwinm r28,r28,0,28,26
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
loc_820845F8:
	// cntlzw r11,r28
	ctx.r11.u64 = ctx.r28.u32 == 0 ? 32 : __builtin_clz(ctx.r28.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8208460C"))) PPC_WEAK_FUNC(sub_8208460C);
PPC_FUNC_IMPL(__imp__sub_8208460C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82084610"))) PPC_WEAK_FUNC(sub_82084610);
PPC_FUNC_IMPL(__imp__sub_82084610) {
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
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// beq cr6,0x8208463c
	if (ctx.cr6.eq) goto loc_8208463C;
	// ble cr6,0x82084648
	if (!ctx.cr6.gt) goto loc_82084648;
	// cmpwi cr6,r3,3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 3, ctx.xer);
	// bgt cr6,0x82084648
	if (ctx.cr6.gt) goto loc_82084648;
	// bl 0x8207d4d8
	ctx.lr = 0x82084634;
	sub_8207D4D8(ctx, base);
	// li r11,34
	ctx.r11.s64 = 34;
	// b 0x82084644
	goto loc_82084644;
loc_8208463C:
	// bl 0x8207d4d8
	ctx.lr = 0x82084640;
	sub_8207D4D8(ctx, base);
	// li r11,33
	ctx.r11.s64 = 33;
loc_82084644:
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
loc_82084648:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82084658"))) PPC_WEAK_FUNC(sub_82084658);
PPC_FUNC_IMPL(__imp__sub_82084658) {
	PPC_FUNC_PROLOGUE();
	// rlwinm. r11,r3,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82084668
	if (ctx.cr0.eq) goto loc_82084668;
	// li r3,5
	ctx.r3.s64 = 5;
	// blr 
	return;
loc_82084668:
	// rlwinm. r11,r3,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82084678
	if (ctx.cr0.eq) goto loc_82084678;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_82084678:
	// rlwinm. r11,r3,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82084688
	if (ctx.cr0.eq) goto loc_82084688;
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
loc_82084688:
	// clrlwi. r11,r3,31
	ctx.r11.u64 = ctx.r3.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82084698
	if (ctx.cr0.eq) goto loc_82084698;
	// li r3,3
	ctx.r3.s64 = 3;
	// blr 
	return;
loc_82084698:
	// rlwinm r3,r3,1,29,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0x4;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820846A0"))) PPC_WEAK_FUNC(sub_820846A0);
PPC_FUNC_IMPL(__imp__sub_820846A0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stfd f31,-24(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// stfd f1,176(r1)
	PPC_STORE_U64(ctx.r1.u32 + 176, ctx.f1.u64);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stfd f2,184(r1)
	PPC_STORE_U64(ctx.r1.u32 + 184, ctx.f2.u64);
	// addi r11,r11,2840
	ctx.r11.s64 = ctx.r11.s64 + 2840;
	// stfd f3,192(r1)
	PPC_STORE_U64(ctx.r1.u32 + 192, ctx.f3.u64);
	// fmr f31,f3
	ctx.f31.f64 = ctx.f3.f64;
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_820846DC:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r8,r4
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x8208476c
	if (ctx.cr6.eq) goto loc_8208476C;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// addi r8,r11,232
	ctx.r8.s64 = ctx.r11.s64 + 232;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpw cr6,r10,r8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x820846dc
	if (ctx.cr6.lt) goto loc_820846DC;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82084700:
	// lis r4,-16377
	ctx.r4.s64 = -1073283072;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ori r4,r4,65279
	ctx.r4.u64 = ctx.r4.u64 | 65279;
	// beq cr6,0x8208477c
	if (ctx.cr6.eq) goto loc_8208477C;
	// lwz r11,176(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	// lwz r10,180(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r9,184(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	// lwz r8,188(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 188);
	// lwz r7,192(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	// lwz r6,196(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// stw r8,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r8.u32);
	// stw r7,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r7.u32);
	// stw r6,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r6.u32);
	// bl 0x82084910
	ctx.lr = 0x8208474C;
	sub_82084910(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820d9438
	ctx.lr = 0x82084754;
	sub_820D9438(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x82084764
	if (!ctx.cr0.eq) goto loc_82084764;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82084610
	ctx.lr = 0x82084764;
	sub_82084610(ctx, base);
loc_82084764:
	// lfd f1,104(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// b 0x8208478c
	goto loc_8208478C;
loc_8208476C:
	// rlwinm r10,r9,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// lwzx r11,r10,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// b 0x82084700
	goto loc_82084700;
loc_8208477C:
	// bl 0x82084910
	ctx.lr = 0x82084780;
	sub_82084910(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82084610
	ctx.lr = 0x82084788;
	sub_82084610(ctx, base);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
loc_8208478C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f31,-24(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820847A4"))) PPC_WEAK_FUNC(sub_820847A4);
PPC_FUNC_IMPL(__imp__sub_820847A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820847A8"))) PPC_WEAK_FUNC(sub_820847A8);
PPC_FUNC_IMPL(__imp__sub_820847A8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stfd f31,-24(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// fadd f31,f1,f2
	ctx.f31.f64 = ctx.f1.f64 + ctx.f2.f64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r31,r6
	ctx.r31.u64 = ctx.r6.u64;
	// lwz r11,3856(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 3856);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820847ec
	if (!ctx.cr6.eq) goto loc_820847EC;
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
	// fmr f3,f31
	ctx.f3.f64 = ctx.f31.f64;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x820846a0
	ctx.lr = 0x820847E8;
	sub_820846A0(ctx, base);
	// b 0x82084810
	goto loc_82084810;
loc_820847EC:
	// bl 0x8207d4d8
	ctx.lr = 0x820847F0;
	sub_8207D4D8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,33
	ctx.r10.s64 = 33;
	// lis r4,-16377
	ctx.r4.s64 = -1073283072;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// ori r4,r4,65279
	ctx.r4.u64 = ctx.r4.u64 | 65279;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// bl 0x82084910
	ctx.lr = 0x8208480C;
	sub_82084910(ctx, base);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
loc_82084810:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f31,-24(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82084828"))) PPC_WEAK_FUNC(sub_82084828);
PPC_FUNC_IMPL(__imp__sub_82084828) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82084830;
	__savegprlr_29(ctx, base);
	// stfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.f30.u64);
	// stfd f31,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stfd f3,288(r1)
	PPC_STORE_U64(ctx.r1.u32 + 288, ctx.f3.u64);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// addi r4,r1,288
	ctx.r4.s64 = ctx.r1.s64 + 288;
	// stfd f1,272(r1)
	PPC_STORE_U64(ctx.r1.u32 + 272, ctx.f1.u64);
	// mr r5,r8
	ctx.r5.u64 = ctx.r8.u64;
	// fmr f30,f1
	ctx.f30.f64 = ctx.f1.f64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r8,300(r1)
	PPC_STORE_U32(ctx.r1.u32 + 300, ctx.r8.u32);
	// mr r30,r8
	ctx.r30.u64 = ctx.r8.u64;
	// fmr f31,f2
	ctx.f31.f64 = ctx.f2.f64;
	// bl 0x820843b8
	ctx.lr = 0x82084868;
	sub_820843B8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x820848a8
	if (!ctx.cr0.eq) goto loc_820848A8;
	// lwz r11,144(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// stfd f31,128(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.f31.u64);
	// li r9,0
	ctx.r9.s64 = 0;
	// clrlwi r11,r11,5
	ctx.r11.u64 = ctx.r11.u32 & 0x7FFFFFF;
	// addi r8,r1,288
	ctx.r8.s64 = ctx.r1.s64 + 288;
	// oris r11,r11,34816
	ctx.r11.u64 = ctx.r11.u64 | 2281701376;
	// addi r7,r1,272
	ctx.r7.s64 = ctx.r1.s64 + 272;
	// stw r11,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r11.u32);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r4,r1,300
	ctx.r4.s64 = ctx.r1.s64 + 300;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82083fb0
	ctx.lr = 0x820848A4;
	sub_82083FB0(ctx, base);
	// lwz r30,300(r1)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 300);
loc_820848A8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82084658
	ctx.lr = 0x820848B0;
	sub_82084658(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lwz r11,3856(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 3856);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820848e4
	if (!ctx.cr6.eq) goto loc_820848E4;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820848e4
	if (ctx.cr6.eq) goto loc_820848E4;
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// lfd f3,288(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 288);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x820846a0
	ctx.lr = 0x820848E0;
	sub_820846A0(ctx, base);
	// b 0x820848fc
	goto loc_820848FC;
loc_820848E4:
	// bl 0x82084610
	ctx.lr = 0x820848E8;
	sub_82084610(ctx, base);
	// lis r4,-16377
	ctx.r4.s64 = -1073283072;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// ori r4,r4,65279
	ctx.r4.u64 = ctx.r4.u64 | 65279;
	// bl 0x82084910
	ctx.lr = 0x820848F8;
	sub_82084910(ctx, base);
	// lfd f1,288(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + 288);
loc_820848FC:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8208490C"))) PPC_WEAK_FUNC(sub_8208490C);
PPC_FUNC_IMPL(__imp__sub_8208490C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82084910"))) PPC_WEAK_FUNC(sub_82084910);
PPC_FUNC_IMPL(__imp__sub_82084910) {
	PPC_FUNC_PROLOGUE();
	// mffs f0
	ctx.f0.u64 = ctx.fpscr.loadFromHost();
	// stfd f0,-8(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.f0.u64);
	// xori r5,r3,248
	ctx.r5.u64 = ctx.r3.u64 ^ 248;
	// lwz r3,-4(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -4);
	// and r5,r5,r4
	ctx.r5.u64 = ctx.r5.u64 & ctx.r4.u64;
	// andc r6,r3,r4
	ctx.r6.u64 = ctx.r3.u64 & ~ctx.r4.u64;
	// or r6,r5,r6
	ctx.r6.u64 = ctx.r5.u64 | ctx.r6.u64;
	// stw r6,-4(r1)
	PPC_STORE_U32(ctx.r1.u32 + -4, ctx.r6.u32);
	// lfd f0,-8(r1)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// xori r3,r3,248
	ctx.r3.u64 = ctx.r3.u64 ^ 248;
	// mtfsf 255,f0
	ctx.fpscr.storeFromGuest(ctx.f0.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82084940"))) PPC_WEAK_FUNC(sub_82084940);
PPC_FUNC_IMPL(__imp__sub_82084940) {
	PPC_FUNC_PROLOGUE();
	// mffs f0
	ctx.f0.u64 = ctx.fpscr.loadFromHost();
	// stfd f0,-8(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.f0.u64);
	// lwz r3,-4(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -4);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82084950"))) PPC_WEAK_FUNC(sub_82084950);
PPC_FUNC_IMPL(__imp__sub_82084950) {
	PPC_FUNC_PROLOGUE();
	// mffs f0
	ctx.f0.u64 = ctx.fpscr.loadFromHost();
	// li r3,4
	ctx.r3.s64 = 4;
	// stfd f0,-8(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.f0.u64);
	// lwz r5,-4(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + -4);
	// and r5,r3,r5
	ctx.r5.u64 = ctx.r3.u64 & ctx.r5.u64;
	// stw r5,-4(r1)
	PPC_STORE_U32(ctx.r1.u32 + -4, ctx.r5.u32);
	// lfd f1,-8(r1)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// mtfsf 255,f1
	ctx.fpscr.storeFromGuest(ctx.f1.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82084974"))) PPC_WEAK_FUNC(sub_82084974);
PPC_FUNC_IMPL(__imp__sub_82084974) {
	PPC_FUNC_PROLOGUE();
	// mffs f0
	ctx.f0.u64 = ctx.fpscr.loadFromHost();
	// stfd f0,-8(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.f0.u64);
	// lwz r5,-4(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + -4);
	// or r5,r3,r5
	ctx.r5.u64 = ctx.r3.u64 | ctx.r5.u64;
	// stw r5,-4(r1)
	PPC_STORE_U32(ctx.r1.u32 + -4, ctx.r5.u32);
	// lfd f1,-8(r1)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// mtfsf 255,f1
	ctx.fpscr.storeFromGuest(ctx.f1.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82084994"))) PPC_WEAK_FUNC(sub_82084994);
PPC_FUNC_IMPL(__imp__sub_82084994) {
	PPC_FUNC_PROLOGUE();
	// stw r3,-4(r1)
	PPC_STORE_U32(ctx.r1.u32 + -4, ctx.r3.u32);
	// lfd f1,-8(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// mtfsf 255,f1
	ctx.fpscr.storeFromGuest(ctx.f1.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820849A4"))) PPC_WEAK_FUNC(sub_820849A4);
PPC_FUNC_IMPL(__imp__sub_820849A4) {
	PPC_FUNC_PROLOGUE();
	// mffs f0
	ctx.f0.u64 = ctx.fpscr.loadFromHost();
	// stfd f0,-8(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.f0.u64);
	// lwz r3,-4(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -4);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820849B4"))) PPC_WEAK_FUNC(sub_820849B4);
PPC_FUNC_IMPL(__imp__sub_820849B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820849B8"))) PPC_WEAK_FUNC(sub_820849B8);
PPC_FUNC_IMPL(__imp__sub_820849B8) {
	PPC_FUNC_PROLOGUE();
	// li r5,10
	ctx.r5.s64 = 10;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x82082fb8
	sub_82082FB8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820849C4"))) PPC_WEAK_FUNC(sub_820849C4);
PPC_FUNC_IMPL(__imp__sub_820849C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820849C8"))) PPC_WEAK_FUNC(sub_820849C8);
PPC_FUNC_IMPL(__imp__sub_820849C8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820849D0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r30,-1
	ctx.r30.s64 = -1;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82084a10
	if (!ctx.cr6.eq) goto loc_82084A10;
	// bl 0x8207d4d8
	ctx.lr = 0x820849E8;
	sub_8207D4D8(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d940
	ctx.lr = 0x82084A08;
	sub_8207D940(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x82084a70
	goto loc_82084A70;
loc_82084A10:
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r29,0
	ctx.r29.s64 = 0;
	// andi. r11,r11,131
	ctx.r11.u64 = ctx.r11.u64 & 131;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82084a68
	if (ctx.cr0.eq) goto loc_82084A68;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207c558
	ctx.lr = 0x82084A2C;
	sub_8207C558(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82085c78
	ctx.lr = 0x82084A38;
	sub_82085C78(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820809e8
	ctx.lr = 0x82084A40;
	sub_820809E8(ctx, base);
	// bl 0x82085b00
	ctx.lr = 0x82084A44;
	sub_82085B00(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x82084a54
	if (!ctx.cr0.lt) goto loc_82084A54;
	// li r30,-1
	ctx.r30.s64 = -1;
	// b 0x82084a68
	goto loc_82084A68;
loc_82084A54:
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82084a68
	if (ctx.cr6.eq) goto loc_82084A68;
	// bl 0x8207c068
	ctx.lr = 0x82084A64;
	sub_8207C068(ctx, base);
	// stw r29,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r29.u32);
loc_82084A68:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r29,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r29.u32);
loc_82084A70:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82084A78"))) PPC_WEAK_FUNC(sub_82084A78);
PPC_FUNC_IMPL(__imp__sub_82084A78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lwz r16,21428(r29)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r29.u32 + 21428);
	// lwz r16,7104(r5)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r5.u32 + 7104);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// addi r31,r1,-112
	ctx.r31.s64 = ctx.r1.s64 + -112;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r3,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r3.u32);
	// addic r11,r3,-1
	ctx.xer.ca = ctx.r3.u32 > 0;
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// li r10,-1
	ctx.r10.s64 = -1;
	// subfe. r11,r11,r3
	temp.u8 = (~ctx.r11.u32 + ctx.r3.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r3.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r3.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r10,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r10.u32);
	// bne 0x82084ae0
	if (!ctx.cr0.eq) goto loc_82084AE0;
	// bl 0x8207d4d8
	ctx.lr = 0x82084AB8;
	sub_8207D4D8(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d940
	ctx.lr = 0x82084AD8;
	sub_8207D940(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x82084b20
	goto loc_82084B20;
loc_82084AE0:
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// rlwinm. r11,r11,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82084af8
	if (ctx.cr0.eq) goto loc_82084AF8;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r11.u32);
	// b 0x82084b1c
	goto loc_82084B1C;
loc_82084AF8:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207c430
	ctx.lr = 0x82084B00;
	sub_8207C430(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820849c8
	ctx.lr = 0x82084B0C;
	sub_820849C8(ctx, base);
	// stw r3,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r3.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,112
	ctx.r12.s64 = ctx.r31.s64 + 112;
	// bl 0x82084b58
	ctx.lr = 0x82084B1C;
	sub_82084B58(ctx, base);
loc_82084B1C:
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
loc_82084B20:
	// addi r1,r31,112
	ctx.r1.s64 = ctx.r31.s64 + 112;
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

__attribute__((alias("__imp__sub_82084A80"))) PPC_WEAK_FUNC(sub_82084A80);
PPC_FUNC_IMPL(__imp__sub_82084A80) {
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
	// addi r31,r1,-112
	ctx.r31.s64 = ctx.r1.s64 + -112;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r3,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r3.u32);
	// addic r11,r3,-1
	ctx.xer.ca = ctx.r3.u32 > 0;
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// li r10,-1
	ctx.r10.s64 = -1;
	// subfe. r11,r11,r3
	temp.u8 = (~ctx.r11.u32 + ctx.r3.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r3.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r3.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r10,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r10.u32);
	// bne 0x82084ae0
	if (!ctx.cr0.eq) goto loc_82084AE0;
	// bl 0x8207d4d8
	ctx.lr = 0x82084AB8;
	sub_8207D4D8(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d940
	ctx.lr = 0x82084AD8;
	sub_8207D940(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x82084b20
	goto loc_82084B20;
loc_82084AE0:
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// rlwinm. r11,r11,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82084af8
	if (ctx.cr0.eq) goto loc_82084AF8;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r11.u32);
	// b 0x82084b1c
	goto loc_82084B1C;
loc_82084AF8:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207c430
	ctx.lr = 0x82084B00;
	sub_8207C430(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820849c8
	ctx.lr = 0x82084B0C;
	sub_820849C8(ctx, base);
	// stw r3,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r3.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,112
	ctx.r12.s64 = ctx.r31.s64 + 112;
	// bl 0x82084b58
	ctx.lr = 0x82084B1C;
	sub_82084B58(ctx, base);
loc_82084B1C:
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
loc_82084B20:
	// addi r1,r31,112
	ctx.r1.s64 = ctx.r31.s64 + 112;
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

__attribute__((alias("__imp__sub_82084B38"))) PPC_WEAK_FUNC(sub_82084B38);
PPC_FUNC_IMPL(__imp__sub_82084B38) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r31,r12,-112
	ctx.r31.s64 = ctx.r12.s64 + -112;
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r30,132(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// b 0x82084b70
	goto loc_82084B70;
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r31,r12,-112
	ctx.r31.s64 = ctx.r12.s64 + -112;
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
loc_82084B70:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207c4f0
	ctx.lr = 0x82084B78;
	sub_8207C4F0(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r30,-16(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-24(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82084B58"))) PPC_WEAK_FUNC(sub_82084B58);
PPC_FUNC_IMPL(__imp__sub_82084B58) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r31,r12,-112
	ctx.r31.s64 = ctx.r12.s64 + -112;
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207c4f0
	ctx.lr = 0x82084B78;
	sub_8207C4F0(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r30,-16(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-24(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82084B90"))) PPC_WEAK_FUNC(sub_82084B90);
PPC_FUNC_IMPL(__imp__sub_82084B90) {
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
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82084be8
	if (ctx.cr6.lt) goto loc_82084BE8;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-23372(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -23372);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x82084be8
	if (!ctx.cr6.lt) goto loc_82084BE8;
	// srawi r11,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 5;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,-23360
	ctx.r10.s64 = ctx.r10.s64 + -23360;
	// clrlwi r11,r3,27
	ctx.r11.u64 = ctx.r3.u32 & 0x1F;
	// mulli r11,r11,72
	ctx.r11.s64 = ctx.r11.s64 * 72;
	// lwzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// cmpwi cr6,r9,-1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, -1, ctx.xer);
	// bne cr6,0x82084be8
	if (!ctx.cr6.eq) goto loc_82084BE8;
	// stwx r4,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + ctx.r11.u32, ctx.r4.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82084c08
	goto loc_82084C08;
loc_82084BE8:
	// bl 0x8207d4d8
	ctx.lr = 0x82084BEC;
	sub_8207D4D8(ctx, base);
	// li r11,9
	ctx.r11.s64 = 9;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d510
	ctx.lr = 0x82084BF8;
	sub_8207D510(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_82084C08:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82084C18"))) PPC_WEAK_FUNC(sub_82084C18);
PPC_FUNC_IMPL(__imp__sub_82084C18) {
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
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82084c80
	if (ctx.cr6.lt) goto loc_82084C80;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-23372(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -23372);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x82084c80
	if (!ctx.cr6.lt) goto loc_82084C80;
	// srawi r11,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 5;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,-23360
	ctx.r10.s64 = ctx.r10.s64 + -23360;
	// clrlwi r11,r3,27
	ctx.r11.u64 = ctx.r3.u32 & 0x1F;
	// mulli r11,r11,72
	ctx.r11.s64 = ctx.r11.s64 * 72;
	// lwzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// clrlwi. r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82084c80
	if (ctx.cr0.eq) goto loc_82084C80;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// beq cr6,0x82084c80
	if (ctx.cr6.eq) goto loc_82084C80;
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82084c9c
	goto loc_82084C9C;
loc_82084C80:
	// bl 0x8207d4d8
	ctx.lr = 0x82084C84;
	sub_8207D4D8(ctx, base);
	// li r11,9
	ctx.r11.s64 = 9;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d510
	ctx.lr = 0x82084C90;
	sub_8207D510(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,-1
	ctx.r3.s64 = -1;
loc_82084C9C:
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82084CB0"))) PPC_WEAK_FUNC(sub_82084CB0);
PPC_FUNC_IMPL(__imp__sub_82084CB0) {
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
	// cmpwi cr6,r3,-2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -2, ctx.xer);
	// bne cr6,0x82084ce8
	if (!ctx.cr6.eq) goto loc_82084CE8;
	// bl 0x8207d510
	ctx.lr = 0x82084CC8;
	sub_8207D510(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d4d8
	ctx.lr = 0x82084CD4;
	sub_8207D4D8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,9
	ctx.r10.s64 = 9;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// b 0x82084d68
	goto loc_82084D68;
loc_82084CE8:
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82084d00
	if (ctx.cr6.lt) goto loc_82084D00;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-23372(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -23372);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82084d38
	if (ctx.cr6.lt) goto loc_82084D38;
loc_82084D00:
	// bl 0x8207d510
	ctx.lr = 0x82084D04;
	sub_8207D510(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d4d8
	ctx.lr = 0x82084D10;
	sub_8207D4D8(ctx, base);
	// li r11,9
	ctx.r11.s64 = 9;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207d940
	ctx.lr = 0x82084D30;
	sub_8207D940(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x82084d68
	goto loc_82084D68;
loc_82084D38:
	// srawi r11,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 5;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,-23360
	ctx.r10.s64 = ctx.r10.s64 + -23360;
	// clrlwi r11,r3,27
	ctx.r11.u64 = ctx.r3.u32 & 0x1F;
	// mulli r11,r11,72
	ctx.r11.s64 = ctx.r11.s64 * 72;
	// lwzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// clrlwi. r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82084d00
	if (ctx.cr0.eq) goto loc_82084D00;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
loc_82084D68:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82084D78"))) PPC_WEAK_FUNC(sub_82084D78);
PPC_FUNC_IMPL(__imp__sub_82084D78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lwz r16,21428(r29)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r29.u32 + 21428);
	// lwz r16,7128(r5)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r5.u32 + 7128);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82084D88;
	__savegprlr_29(ctx, base);
	// addi r31,r1,-128
	ctx.r31.s64 = ctx.r1.s64 + -128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r3,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r3.u32);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// srawi r10,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 5;
	// addi r11,r11,-23360
	ctx.r11.s64 = ctx.r11.s64 + -23360;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r9,r3,27
	ctx.r9.u64 = ctx.r3.u32 & 0x1F;
	// li r29,1
	ctx.r29.s64 = 1;
	// mulli r9,r9,72
	ctx.r9.s64 = ctx.r9.s64 * 72;
	// stw r29,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r29.u32);
	// lwzx r10,r10,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// add r30,r10,r9
	ctx.r30.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x82084e14
	if (!ctx.cr6.eq) goto loc_82084E14;
	// li r3,10
	ctx.r3.s64 = 10;
	// bl 0x8207d808
	ctx.lr = 0x82084DD0;
	sub_8207D808(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82084e08
	if (!ctx.cr6.eq) goto loc_82084E08;
	// li r4,4000
	ctx.r4.s64 = 4000;
	// addi r3,r30,12
	ctx.r3.s64 = ctx.r30.s64 + 12;
	// bl 0x82082610
	ctx.lr = 0x82084DEC;
	sub_82082610(ctx, base);
	// subfic r11,r3,0
	ctx.xer.ca = ctx.r3.u32 <= 0;
	ctx.r11.s64 = 0 - ctx.r3.s64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 & ctx.r29.u64;
	// stw r11,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
loc_82084E08:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,128
	ctx.r12.s64 = ctx.r31.s64 + 128;
	// bl 0x82084e48
	ctx.lr = 0x82084E14;
	sub_82084E48(ctx, base);
loc_82084E14:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x82084e3c
	if (ctx.cr6.eq) goto loc_82084E3C;
	// srawi r10,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 5;
	// clrlwi r9,r3,27
	ctx.r9.u64 = ctx.r3.u32 & 0x1F;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mulli r10,r9,72
	ctx.r10.s64 = ctx.r9.s64 * 72;
	// lwzx r11,r8,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r3,r11,12
	ctx.r3.s64 = ctx.r11.s64 + 12;
	// bl 0x821d5384
	ctx.lr = 0x82084E3C;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_82084E3C:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r31,128
	ctx.r1.s64 = ctx.r31.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82084D80"))) PPC_WEAK_FUNC(sub_82084D80);
PPC_FUNC_IMPL(__imp__sub_82084D80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82084D88;
	__savegprlr_29(ctx, base);
	// addi r31,r1,-128
	ctx.r31.s64 = ctx.r1.s64 + -128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r3,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r3.u32);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// srawi r10,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 5;
	// addi r11,r11,-23360
	ctx.r11.s64 = ctx.r11.s64 + -23360;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r9,r3,27
	ctx.r9.u64 = ctx.r3.u32 & 0x1F;
	// li r29,1
	ctx.r29.s64 = 1;
	// mulli r9,r9,72
	ctx.r9.s64 = ctx.r9.s64 * 72;
	// stw r29,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r29.u32);
	// lwzx r10,r10,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// add r30,r10,r9
	ctx.r30.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x82084e14
	if (!ctx.cr6.eq) goto loc_82084E14;
	// li r3,10
	ctx.r3.s64 = 10;
	// bl 0x8207d808
	ctx.lr = 0x82084DD0;
	sub_8207D808(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82084e08
	if (!ctx.cr6.eq) goto loc_82084E08;
	// li r4,4000
	ctx.r4.s64 = 4000;
	// addi r3,r30,12
	ctx.r3.s64 = ctx.r30.s64 + 12;
	// bl 0x82082610
	ctx.lr = 0x82084DEC;
	sub_82082610(ctx, base);
	// subfic r11,r3,0
	ctx.xer.ca = ctx.r3.u32 <= 0;
	ctx.r11.s64 = 0 - ctx.r3.s64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 & ctx.r29.u64;
	// stw r11,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
loc_82084E08:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,128
	ctx.r12.s64 = ctx.r31.s64 + 128;
	// bl 0x82084e48
	ctx.lr = 0x82084E14;
	sub_82084E48(ctx, base);
loc_82084E14:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x82084e3c
	if (ctx.cr6.eq) goto loc_82084E3C;
	// srawi r10,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 5;
	// clrlwi r9,r3,27
	ctx.r9.u64 = ctx.r3.u32 & 0x1F;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mulli r10,r9,72
	ctx.r10.s64 = ctx.r9.s64 * 72;
	// lwzx r11,r8,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r3,r11,12
	ctx.r3.s64 = ctx.r11.s64 + 12;
	// bl 0x821d5384
	ctx.lr = 0x82084E3C;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_82084E3C:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r31,128
	ctx.r1.s64 = ctx.r31.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82084E48"))) PPC_WEAK_FUNC(sub_82084E48);
PPC_FUNC_IMPL(__imp__sub_82084E48) {
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
	// li r3,10
	ctx.r3.s64 = 10;
	// bl 0x8207d6a8
	ctx.lr = 0x82084E5C;
	sub_8207D6A8(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r3,148(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// lwz r29,80(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// addi r11,r11,-23360
	ctx.r11.s64 = ctx.r11.s64 + -23360;
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82084E7C"))) PPC_WEAK_FUNC(sub_82084E7C);
PPC_FUNC_IMPL(__imp__sub_82084E7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82084E80"))) PPC_WEAK_FUNC(sub_82084E80);
PPC_FUNC_IMPL(__imp__sub_82084E80) {
	PPC_FUNC_PROLOGUE();
	// srawi r11,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 5;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,-23360
	ctx.r10.s64 = ctx.r10.s64 + -23360;
	// clrlwi r11,r3,27
	ctx.r11.u64 = ctx.r3.u32 & 0x1F;
	// mulli r11,r11,72
	ctx.r11.s64 = ctx.r11.s64 * 72;
	// lwzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r3,r11,12
	ctx.r3.s64 = ctx.r11.s64 + 12;
	// b 0x821d5394
	__imp__RtlLeaveCriticalSection(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82084EA8"))) PPC_WEAK_FUNC(sub_82084EA8);
PPC_FUNC_IMPL(__imp__sub_82084EA8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lwz r16,21428(r29)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r29.u32 + 21428);
	// lwz r16,7152(r5)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r5.u32 + 7152);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x82084EB8;
	__savegprlr_24(ctx, base);
	// addi r31,r1,-176
	ctx.r31.s64 = ctx.r1.s64 + -176;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r24,-1
	ctx.r24.s64 = -1;
	// li r25,0
	ctx.r25.s64 = 0;
	// li r3,11
	ctx.r3.s64 = 11;
	// stw r24,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r24.u32);
	// stw r25,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r25.u32);
	// bl 0x8207d6c8
	ctx.lr = 0x82084ED8;
	sub_8207D6C8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x82084ee8
	if (!ctx.cr0.eq) goto loc_82084EE8;
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x820850bc
	goto loc_820850BC;
loc_82084EE8:
	// li r3,11
	ctx.r3.s64 = 11;
	// bl 0x8207d808
	ctx.lr = 0x82084EF0;
	sub_8207D808(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r28,0
	ctx.r28.s64 = 0;
	// li r26,1
	ctx.r26.s64 = 1;
	// addi r29,r11,-23360
	ctx.r29.s64 = ctx.r11.s64 + -23360;
loc_82084F04:
	// stw r28,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r28.u32);
	// cmpwi cr6,r28,64
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 64, ctx.xer);
	// bge cr6,0x820850ac
	if (!ctx.cr6.lt) goto loc_820850AC;
	// rlwinm r27,r28,2,0,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r30,r27,r29
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r29.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8208501c
	if (ctx.cr6.eq) goto loc_8208501C;
loc_82084F20:
	// stw r30,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r30.u32);
	// rlwinm r11,r28,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r29
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// addi r11,r11,2304
	ctx.r11.s64 = ctx.r11.s64 + 2304;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x82085004
	if (!ctx.cr6.lt) goto loc_82085004;
	// lbz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + 4);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82084fd0
	if (!ctx.cr0.eq) goto loc_82084FD0;
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82084f9c
	if (!ctx.cr6.eq) goto loc_82084F9C;
	// li r3,10
	ctx.r3.s64 = 10;
	// bl 0x8207d808
	ctx.lr = 0x82084F58;
	sub_8207D808(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82084f90
	if (!ctx.cr6.eq) goto loc_82084F90;
	// li r4,4000
	ctx.r4.s64 = 4000;
	// addi r3,r30,12
	ctx.r3.s64 = ctx.r30.s64 + 12;
	// bl 0x82082610
	ctx.lr = 0x82084F74;
	sub_82082610(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x82084f84
	if (!ctx.cr0.eq) goto loc_82084F84;
	// stw r26,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r26.u32);
	// b 0x82084f90
	goto loc_82084F90;
loc_82084F84:
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
loc_82084F90:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,176
	ctx.r12.s64 = ctx.r31.s64 + 176;
	// bl 0x820850e8
	ctx.lr = 0x82084F9C;
	sub_820850E8(ctx, base);
loc_82084F9C:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// bne cr6,0x82084fd0
	if (!ctx.cr6.eq) goto loc_82084FD0;
	// addi r27,r30,12
	ctx.r27.s64 = ctx.r30.s64 + 12;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x821d5384
	ctx.lr = 0x82084FB0;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lbz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + 4);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82084fc8
	if (ctx.cr0.eq) goto loc_82084FC8;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x821d5394
	ctx.lr = 0x82084FC4;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// b 0x82084fd0
	goto loc_82084FD0;
loc_82084FC8:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq cr6,0x82084fdc
	if (ctx.cr6.eq) goto loc_82084FDC;
loc_82084FD0:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r30,r30,72
	ctx.r30.s64 = ctx.r30.s64 + 72;
	// b 0x82084f20
	goto loc_82084F20;
loc_82084FDC:
	// rlwinm r11,r28,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// stb r26,4(r30)
	PPC_STORE_U8(ctx.r30.u32 + 4, ctx.r26.u8);
	// stw r24,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r24.u32);
	// li r9,72
	ctx.r9.s64 = 72;
	// rlwinm r10,r28,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 5) & 0xFFFFFFE0;
	// lwzx r11,r11,r29
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// subf r11,r11,r30
	ctx.r11.s64 = ctx.r30.s64 - ctx.r11.s64;
	// divw r11,r11,r9
	ctx.r11.s32 = ppc_divw(ctx.r11.s32, ctx.r9.s32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r11,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
loc_82085004:
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x820850ac
	if (!ctx.cr6.eq) goto loc_820850AC;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// b 0x82084f04
	goto loc_82084F04;
loc_8208501C:
	// li r4,72
	ctx.r4.s64 = 72;
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x8207e150
	ctx.lr = 0x82085028;
	sub_8207E150(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x820850ac
	if (ctx.cr0.eq) goto loc_820850AC;
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// stwx r3,r27,r29
	PPC_STORE_U32(ctx.r27.u32 + ctx.r29.u32, ctx.r3.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,-23372(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23372);
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// stw r11,-23372(r9)
	PPC_STORE_U32(ctx.r9.u32 + -23372, ctx.r11.u32);
loc_82085048:
	// lwzx r11,r27,r29
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r29.u32);
	// addi r11,r11,2304
	ctx.r11.s64 = ctx.r11.s64 + 2304;
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x82085078
	if (!ctx.cr6.lt) goto loc_82085078;
	// li r11,10
	ctx.r11.s64 = 10;
	// stb r10,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r10.u8);
	// stw r24,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r24.u32);
	// stb r11,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, ctx.r11.u8);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r3,r3,72
	ctx.r3.s64 = ctx.r3.s64 + 72;
	// b 0x82085048
	goto loc_82085048;
loc_82085078:
	// rlwinm r3,r28,5,0,26
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 5) & 0xFFFFFFE0;
	// li r11,0
	ctx.r11.s64 = 0;
	// srawi r9,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r9.s64 = ctx.r3.s32 >> 5;
	// stw r3,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r3.u32);
	// mulli r10,r11,72
	ctx.r10.s64 = ctx.r11.s64 * 72;
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r29
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stb r26,4(r11)
	PPC_STORE_U8(ctx.r11.u32 + 4, ctx.r26.u8);
	// bl 0x82084d80
	ctx.lr = 0x820850A0;
	sub_82084D80(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x820850ac
	if (!ctx.cr0.eq) goto loc_820850AC;
	// stw r24,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r24.u32);
loc_820850AC:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,176
	ctx.r12.s64 = ctx.r31.s64 + 176;
	// bl 0x820850c4
	ctx.lr = 0x820850B8;
	sub_820850C4(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
loc_820850BC:
	// addi r1,r31,176
	ctx.r1.s64 = ctx.r31.s64 + 176;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82084EB0"))) PPC_WEAK_FUNC(sub_82084EB0);
PPC_FUNC_IMPL(__imp__sub_82084EB0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x82084EB8;
	__savegprlr_24(ctx, base);
	// addi r31,r1,-176
	ctx.r31.s64 = ctx.r1.s64 + -176;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r24,-1
	ctx.r24.s64 = -1;
	// li r25,0
	ctx.r25.s64 = 0;
	// li r3,11
	ctx.r3.s64 = 11;
	// stw r24,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r24.u32);
	// stw r25,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r25.u32);
	// bl 0x8207d6c8
	ctx.lr = 0x82084ED8;
	sub_8207D6C8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x82084ee8
	if (!ctx.cr0.eq) goto loc_82084EE8;
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x820850bc
	goto loc_820850BC;
loc_82084EE8:
	// li r3,11
	ctx.r3.s64 = 11;
	// bl 0x8207d808
	ctx.lr = 0x82084EF0;
	sub_8207D808(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r28,0
	ctx.r28.s64 = 0;
	// li r26,1
	ctx.r26.s64 = 1;
	// addi r29,r11,-23360
	ctx.r29.s64 = ctx.r11.s64 + -23360;
loc_82084F04:
	// stw r28,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r28.u32);
	// cmpwi cr6,r28,64
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 64, ctx.xer);
	// bge cr6,0x820850ac
	if (!ctx.cr6.lt) goto loc_820850AC;
	// rlwinm r27,r28,2,0,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r30,r27,r29
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r29.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8208501c
	if (ctx.cr6.eq) goto loc_8208501C;
loc_82084F20:
	// stw r30,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r30.u32);
	// rlwinm r11,r28,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r29
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// addi r11,r11,2304
	ctx.r11.s64 = ctx.r11.s64 + 2304;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x82085004
	if (!ctx.cr6.lt) goto loc_82085004;
	// lbz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + 4);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82084fd0
	if (!ctx.cr0.eq) goto loc_82084FD0;
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82084f9c
	if (!ctx.cr6.eq) goto loc_82084F9C;
	// li r3,10
	ctx.r3.s64 = 10;
	// bl 0x8207d808
	ctx.lr = 0x82084F58;
	sub_8207D808(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82084f90
	if (!ctx.cr6.eq) goto loc_82084F90;
	// li r4,4000
	ctx.r4.s64 = 4000;
	// addi r3,r30,12
	ctx.r3.s64 = ctx.r30.s64 + 12;
	// bl 0x82082610
	ctx.lr = 0x82084F74;
	sub_82082610(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x82084f84
	if (!ctx.cr0.eq) goto loc_82084F84;
	// stw r26,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r26.u32);
	// b 0x82084f90
	goto loc_82084F90;
loc_82084F84:
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
loc_82084F90:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,176
	ctx.r12.s64 = ctx.r31.s64 + 176;
	// bl 0x820850e8
	ctx.lr = 0x82084F9C;
	sub_820850E8(ctx, base);
loc_82084F9C:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// bne cr6,0x82084fd0
	if (!ctx.cr6.eq) goto loc_82084FD0;
	// addi r27,r30,12
	ctx.r27.s64 = ctx.r30.s64 + 12;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x821d5384
	ctx.lr = 0x82084FB0;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lbz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + 4);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82084fc8
	if (ctx.cr0.eq) goto loc_82084FC8;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x821d5394
	ctx.lr = 0x82084FC4;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// b 0x82084fd0
	goto loc_82084FD0;
loc_82084FC8:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq cr6,0x82084fdc
	if (ctx.cr6.eq) goto loc_82084FDC;
loc_82084FD0:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r30,r30,72
	ctx.r30.s64 = ctx.r30.s64 + 72;
	// b 0x82084f20
	goto loc_82084F20;
loc_82084FDC:
	// rlwinm r11,r28,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// stb r26,4(r30)
	PPC_STORE_U8(ctx.r30.u32 + 4, ctx.r26.u8);
	// stw r24,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r24.u32);
	// li r9,72
	ctx.r9.s64 = 72;
	// rlwinm r10,r28,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 5) & 0xFFFFFFE0;
	// lwzx r11,r11,r29
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// subf r11,r11,r30
	ctx.r11.s64 = ctx.r30.s64 - ctx.r11.s64;
	// divw r11,r11,r9
	ctx.r11.s32 = ppc_divw(ctx.r11.s32, ctx.r9.s32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r11,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
loc_82085004:
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x820850ac
	if (!ctx.cr6.eq) goto loc_820850AC;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// b 0x82084f04
	goto loc_82084F04;
loc_8208501C:
	// li r4,72
	ctx.r4.s64 = 72;
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x8207e150
	ctx.lr = 0x82085028;
	sub_8207E150(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x820850ac
	if (ctx.cr0.eq) goto loc_820850AC;
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// stwx r3,r27,r29
	PPC_STORE_U32(ctx.r27.u32 + ctx.r29.u32, ctx.r3.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,-23372(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23372);
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// stw r11,-23372(r9)
	PPC_STORE_U32(ctx.r9.u32 + -23372, ctx.r11.u32);
loc_82085048:
	// lwzx r11,r27,r29
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r29.u32);
	// addi r11,r11,2304
	ctx.r11.s64 = ctx.r11.s64 + 2304;
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x82085078
	if (!ctx.cr6.lt) goto loc_82085078;
	// li r11,10
	ctx.r11.s64 = 10;
	// stb r10,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r10.u8);
	// stw r24,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r24.u32);
	// stb r11,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, ctx.r11.u8);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r3,r3,72
	ctx.r3.s64 = ctx.r3.s64 + 72;
	// b 0x82085048
	goto loc_82085048;
loc_82085078:
	// rlwinm r3,r28,5,0,26
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 5) & 0xFFFFFFE0;
	// li r11,0
	ctx.r11.s64 = 0;
	// srawi r9,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r9.s64 = ctx.r3.s32 >> 5;
	// stw r3,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r3.u32);
	// mulli r10,r11,72
	ctx.r10.s64 = ctx.r11.s64 * 72;
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r29
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stb r26,4(r11)
	PPC_STORE_U8(ctx.r11.u32 + 4, ctx.r26.u8);
	// bl 0x82084d80
	ctx.lr = 0x820850A0;
	sub_82084D80(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x820850ac
	if (!ctx.cr0.eq) goto loc_820850AC;
	// stw r24,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r24.u32);
loc_820850AC:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,176
	ctx.r12.s64 = ctx.r31.s64 + 176;
	// bl 0x820850c4
	ctx.lr = 0x820850B8;
	sub_820850C4(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
loc_820850BC:
	// addi r1,r31,176
	ctx.r1.s64 = ctx.r31.s64 + 176;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820850C4"))) PPC_WEAK_FUNC(sub_820850C4);
PPC_FUNC_IMPL(__imp__sub_820850C4) {
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
	// li r3,11
	ctx.r3.s64 = 11;
	// bl 0x8207d6a8
	ctx.lr = 0x820850D8;
	sub_8207D6A8(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820850E8"))) PPC_WEAK_FUNC(sub_820850E8);
PPC_FUNC_IMPL(__imp__sub_820850E8) {
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
	// li r3,10
	ctx.r3.s64 = 10;
	// bl 0x8207d6a8
	ctx.lr = 0x820850FC;
	sub_8207D6A8(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r25,84(r31)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r28,92(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// li r24,-1
	ctx.r24.s64 = -1;
	// lwz r30,88(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// addi r29,r11,-23360
	ctx.r29.s64 = ctx.r11.s64 + -23360;
	// li r26,1
	ctx.r26.s64 = 1;
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

