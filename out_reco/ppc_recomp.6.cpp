#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_88094208"))) PPC_WEAK_FUNC(sub_88094208);
PPC_FUNC_IMPL(__imp__sub_88094208) {
	PPC_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r4,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r4.u32);
	// stw r11,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094218"))) PPC_WEAK_FUNC(sub_88094218);
PPC_FUNC_IMPL(__imp__sub_88094218) {
	PPC_FUNC_PROLOGUE();
	// stw r4,96(r3)
	PPC_STORE_U32(ctx.r3.u32 + 96, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094220"))) PPC_WEAK_FUNC(sub_88094220);
PPC_FUNC_IMPL(__imp__sub_88094220) {
	PPC_FUNC_PROLOGUE();
	// lis r7,-30633
	ctx.r7.s64 = -2007564288;
	// lwz r11,-29748(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -29748);
	// cmpwi cr6,r11,128
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 128, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// li r8,1
	ctx.r8.s64 = 1;
	// lis r10,-30640
	ctx.r10.s64 = -2008023040;
	// stw r8,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r8.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r8,r10,31712
	ctx.r8.s64 = ctx.r10.s64 + 31712;
	// ble cr6,0x8809426c
	if (!ctx.cr6.gt) goto loc_8809426C;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
loc_88094250:
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r6,r3
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r3.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x88094250
	if (ctx.cr6.lt) goto loc_88094250;
loc_8809426C:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-29748(r7)
	PPC_STORE_U32(ctx.r7.u32 + -29748, ctx.r11.u32);
	// stwx r3,r10,r8
	PPC_STORE_U32(ctx.r10.u32 + ctx.r8.u32, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094280"))) PPC_WEAK_FUNC(sub_88094280);
PPC_FUNC_IMPL(__imp__sub_88094280) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,2304(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094288"))) PPC_WEAK_FUNC(sub_88094288);
PPC_FUNC_IMPL(__imp__sub_88094288) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,2304(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094290"))) PPC_WEAK_FUNC(sub_88094290);
PPC_FUNC_IMPL(__imp__sub_88094290) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lis r10,-30639
	ctx.r10.s64 = -2007957504;
	// rlwinm r11,r4,26,6,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 26) & 0x3FFFFFF;
	// addi r9,r10,-31640
	ctx.r9.s64 = ctx.r10.s64 + -31640;
	// addi r6,r11,1
	ctx.r6.s64 = ctx.r11.s64 + 1;
	// addi r7,r9,-1664
	ctx.r7.s64 = ctx.r9.s64 + -1664;
	// addi r31,r9,-1664
	ctx.r31.s64 = ctx.r9.s64 + -1664;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
loc_880942BC:
	// lbz r30,0(r7)
	ctx.r30.u64 = PPC_LOAD_U8(ctx.r7.u32 + 0);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x88094328
	if (!ctx.cr6.eq) goto loc_88094328;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplw cr6,r11,r6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r6.u32, ctx.xer);
	// bne cr6,0x88094334
	if (!ctx.cr6.eq) goto loc_88094334;
	// rlwinm r11,r10,6,0,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// stw r10,2308(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2308, ctx.r10.u32);
	// stw r6,2312(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2312, ctx.r6.u32);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stw r4,2316(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2316, ctx.r4.u32);
	// stw r5,2320(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2320, ctx.r5.u32);
	// stw r11,2304(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2304, ctx.r11.u32);
	// ble cr6,0x88094318
	if (!ctx.cr6.gt) goto loc_88094318;
	// addi r11,r31,-1
	ctx.r11.s64 = ctx.r31.s64 + -1;
	// li r10,1
	ctx.r10.s64 = 1;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x88094318
	if (ctx.cr6.eq) goto loc_88094318;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
loc_88094310:
	// stbu r10,1(r11)
	ea = 1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r10.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x88094310
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88094310;
loc_88094318:
	// li r3,1
	ctx.r3.s64 = 1;
	// ld r30,-16(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_88094328:
	// addi r10,r8,1
	ctx.r10.s64 = ctx.r8.s64 + 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r31,r7
	ctx.r31.u64 = ctx.r7.u64;
loc_88094334:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmpwi cr6,r8,1500
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 1500, ctx.xer);
	// blt cr6,0x880942bc
	if (ctx.cr6.lt) goto loc_880942BC;
	// li r3,0
	ctx.r3.s64 = 0;
	// ld r30,-16(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094350"))) PPC_WEAK_FUNC(sub_88094350);
PPC_FUNC_IMPL(__imp__sub_88094350) {
	PPC_FUNC_PROLOGUE();
	// lis r5,-292
	ctx.r5.s64 = -19136512;
	// ori r5,r5,47768
	ctx.r5.u64 = ctx.r5.u64 | 47768;
	// b 0x88094290
	sub_88094290(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809435C"))) PPC_WEAK_FUNC(sub_8809435C);
PPC_FUNC_IMPL(__imp__sub_8809435C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88094360"))) PPC_WEAK_FUNC(sub_88094360);
PPC_FUNC_IMPL(__imp__sub_88094360) {
	PPC_FUNC_PROLOGUE();
	// stw r4,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094368"))) PPC_WEAK_FUNC(sub_88094368);
PPC_FUNC_IMPL(__imp__sub_88094368) {
	PPC_FUNC_PROLOGUE();
	// stw r4,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094370"))) PPC_WEAK_FUNC(sub_88094370);
PPC_FUNC_IMPL(__imp__sub_88094370) {
	PPC_FUNC_PROLOGUE();
	// stw r4,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094378"))) PPC_WEAK_FUNC(sub_88094378);
PPC_FUNC_IMPL(__imp__sub_88094378) {
	PPC_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,164(r3)
	PPC_STORE_U32(ctx.r3.u32 + 164, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094384"))) PPC_WEAK_FUNC(sub_88094384);
PPC_FUNC_IMPL(__imp__sub_88094384) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88094388"))) PPC_WEAK_FUNC(sub_88094388);
PPC_FUNC_IMPL(__imp__sub_88094388) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,164(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094390"))) PPC_WEAK_FUNC(sub_88094390);
PPC_FUNC_IMPL(__imp__sub_88094390) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,120
	ctx.r3.s64 = ctx.r3.s64 + 120;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094398"))) PPC_WEAK_FUNC(sub_88094398);
PPC_FUNC_IMPL(__imp__sub_88094398) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880943A0;
	__savegprlr_29(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// mr r29,r10
	ctx.r29.u64 = ctx.r10.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// sth r10,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r10.u16);
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// mr r30,r9
	ctx.r30.u64 = ctx.r9.u64;
	// bl 0x8815c948
	ctx.lr = 0x880943D8;
	sub_8815C948(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809440c
	if (ctx.cr6.eq) goto loc_8809440C;
	// li r11,2
	ctx.r11.s64 = 2;
	// sth r30,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, ctx.r30.u16);
	// li r8,1
	ctx.r8.s64 = 1;
	// sth r29,28(r3)
	PPC_STORE_U16(ctx.r3.u32 + 28, ctx.r29.u16);
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r11.u8);
	// li r5,72
	ctx.r5.s64 = 72;
	// stw r8,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r8.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r3,36
	ctx.r3.s64 = ctx.r3.s64 + 36;
	// bl 0x88072260
	ctx.lr = 0x8809440C;
	sub_88072260(ctx, base);
loc_8809440C:
	// lwz r11,276(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 276);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88094424
	if (ctx.cr6.eq) goto loc_88094424;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x88094424
	if (ctx.cr6.eq) goto loc_88094424;
	// sth r11,16(r31)
	PPC_STORE_U16(ctx.r31.u32 + 16, ctx.r11.u16);
loc_88094424:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809442C"))) PPC_WEAK_FUNC(sub_8809442C);
PPC_FUNC_IMPL(__imp__sub_8809442C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88094430"))) PPC_WEAK_FUNC(sub_88094430);
PPC_FUNC_IMPL(__imp__sub_88094430) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88094438;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// lwz r11,26276(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
	// mr r29,r9
	ctx.r29.u64 = ctx.r9.u64;
	// mr r28,r10
	ctx.r28.u64 = ctx.r10.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880944a0
	if (!ctx.cr6.eq) goto loc_880944A0;
	// lwz r30,212(r1)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// stw r3,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r3.u32);
	// clrlwi r3,r31,24
	ctx.r3.u64 = ctx.r31.u32 & 0xFF;
	// sth r11,6(r30)
	PPC_STORE_U16(ctx.r30.u32 + 6, ctx.r11.u16);
	// bl 0x8815c948
	ctx.lr = 0x88094480;
	sub_8815C948(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88094498
	if (ctx.cr6.eq) goto loc_88094498;
	// li r11,2
	ctx.r11.s64 = 2;
	// sth r29,18(r3)
	PPC_STORE_U16(ctx.r3.u32 + 18, ctx.r29.u16);
	// sth r28,20(r3)
	PPC_STORE_U16(ctx.r3.u32 + 20, ctx.r28.u16);
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r11.u8);
loc_88094498:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8815c860
	ctx.lr = 0x880944A0;
	sub_8815C860(ctx, base);
loc_880944A0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880944A8"))) PPC_WEAK_FUNC(sub_880944A8);
PPC_FUNC_IMPL(__imp__sub_880944A8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880944B0;
	__savegprlr_29(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// lwz r11,26276(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
	// mr r30,r9
	ctx.r30.u64 = ctx.r9.u64;
	// mr r29,r10
	ctx.r29.u64 = ctx.r10.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88094544
	if (!ctx.cr6.eq) goto loc_88094544;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// sth r11,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r11.u16);
	// clrlwi r3,r31,24
	ctx.r3.u64 = ctx.r31.u32 & 0xFF;
	// bl 0x8815c948
	ctx.lr = 0x880944F4;
	sub_8815C948(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88094520
	if (ctx.cr6.eq) goto loc_88094520;
	// lwz r11,276(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 276);
	// li r7,2
	ctx.r7.s64 = 2;
	// lwz r9,284(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 284);
	// sth r30,18(r3)
	PPC_STORE_U16(ctx.r3.u32 + 18, ctx.r30.u16);
	// sth r29,20(r3)
	PPC_STORE_U16(ctx.r3.u32 + 20, ctx.r29.u16);
	// stb r7,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r7.u8);
	// sth r11,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, ctx.r11.u16);
	// sth r9,28(r3)
	PPC_STORE_U16(ctx.r3.u32 + 28, ctx.r9.u16);
loc_88094520:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8815c860
	ctx.lr = 0x8809452C;
	sub_8815C860(ctx, base);
	// lwz r11,292(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 292);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88094544
	if (ctx.cr6.eq) goto loc_88094544;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x88094544
	if (ctx.cr6.eq) goto loc_88094544;
	// sth r11,16(r31)
	PPC_STORE_U16(ctx.r31.u32 + 16, ctx.r11.u16);
loc_88094544:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809454C"))) PPC_WEAK_FUNC(sub_8809454C);
PPC_FUNC_IMPL(__imp__sub_8809454C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88094550"))) PPC_WEAK_FUNC(sub_88094550);
PPC_FUNC_IMPL(__imp__sub_88094550) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88094558;
	__savegprlr_29(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// lwz r11,26276(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
	// mr r30,r9
	ctx.r30.u64 = ctx.r9.u64;
	// mr r29,r10
	ctx.r29.u64 = ctx.r10.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880945ec
	if (!ctx.cr6.eq) goto loc_880945EC;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// sth r11,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r11.u16);
	// clrlwi r3,r31,24
	ctx.r3.u64 = ctx.r31.u32 & 0xFF;
	// bl 0x8815c948
	ctx.lr = 0x8809459C;
	sub_8815C948(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880945c8
	if (ctx.cr6.eq) goto loc_880945C8;
	// lwz r11,276(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 276);
	// li r10,2
	ctx.r10.s64 = 2;
	// lwz r9,284(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 284);
	// stb r10,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r10.u8);
	// sth r30,22(r3)
	PPC_STORE_U16(ctx.r3.u32 + 22, ctx.r30.u16);
	// sth r29,24(r3)
	PPC_STORE_U16(ctx.r3.u32 + 24, ctx.r29.u16);
	// sth r11,18(r3)
	PPC_STORE_U16(ctx.r3.u32 + 18, ctx.r11.u16);
	// sth r9,20(r3)
	PPC_STORE_U16(ctx.r3.u32 + 20, ctx.r9.u16);
loc_880945C8:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8815c860
	ctx.lr = 0x880945D4;
	sub_8815C860(ctx, base);
	// lwz r11,292(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 292);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880945ec
	if (ctx.cr6.eq) goto loc_880945EC;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x880945ec
	if (ctx.cr6.eq) goto loc_880945EC;
	// sth r11,16(r31)
	PPC_STORE_U16(ctx.r31.u32 + 16, ctx.r11.u16);
loc_880945EC:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880945F4"))) PPC_WEAK_FUNC(sub_880945F4);
PPC_FUNC_IMPL(__imp__sub_880945F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880945F8"))) PPC_WEAK_FUNC(sub_880945F8);
PPC_FUNC_IMPL(__imp__sub_880945F8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x88094600;
	__savegprlr_27(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// lwz r11,26276(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
	// mr r30,r9
	ctx.r30.u64 = ctx.r9.u64;
	// mr r29,r10
	ctx.r29.u64 = ctx.r10.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88094688
	if (!ctx.cr6.eq) goto loc_88094688;
	// lwz r11,292(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 292);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,300(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 300);
	// li r28,-1
	ctx.r28.s64 = -1;
	// lwz r27,308(r1)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// clrlwi r3,r31,24
	ctx.r3.u64 = ctx.r31.u32 & 0xFF;
	// sth r10,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r10.u16);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r27,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r27.u32);
	// stw r28,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r28.u32);
	// bl 0x8815c948
	ctx.lr = 0x88094668;
	sub_8815C948(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88094680
	if (ctx.cr6.eq) goto loc_88094680;
	// li r11,2
	ctx.r11.s64 = 2;
	// sth r30,18(r3)
	PPC_STORE_U16(ctx.r3.u32 + 18, ctx.r30.u16);
	// sth r29,20(r3)
	PPC_STORE_U16(ctx.r3.u32 + 20, ctx.r29.u16);
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r11.u8);
loc_88094680:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x88094688;
	sub_8815C860(ctx, base);
loc_88094688:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88094690"))) PPC_WEAK_FUNC(sub_88094690);
PPC_FUNC_IMPL(__imp__sub_88094690) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88094698;
	__savegprlr_29(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// lwz r11,26276(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
	// mr r30,r9
	ctx.r30.u64 = ctx.r9.u64;
	// mr r29,r10
	ctx.r29.u64 = ctx.r10.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8809471c
	if (!ctx.cr6.eq) goto loc_8809471C;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// sth r11,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r11.u16);
	// clrlwi r3,r31,24
	ctx.r3.u64 = ctx.r31.u32 & 0xFF;
	// bl 0x8815c948
	ctx.lr = 0x880946DC;
	sub_8815C948(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880946f8
	if (ctx.cr6.eq) goto loc_880946F8;
	// li r11,2
	ctx.r11.s64 = 2;
	// sth r30,18(r3)
	PPC_STORE_U16(ctx.r3.u32 + 18, ctx.r30.u16);
	// sth r29,20(r3)
	PPC_STORE_U16(ctx.r3.u32 + 20, ctx.r29.u16);
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r11.u8);
loc_880946F8:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8815c860
	ctx.lr = 0x88094704;
	sub_8815C860(ctx, base);
	// lwz r11,276(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 276);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8809471c
	if (ctx.cr6.eq) goto loc_8809471C;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8809471c
	if (ctx.cr6.eq) goto loc_8809471C;
	// sth r11,16(r31)
	PPC_STORE_U16(ctx.r31.u32 + 16, ctx.r11.u16);
loc_8809471C:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88094724"))) PPC_WEAK_FUNC(sub_88094724);
PPC_FUNC_IMPL(__imp__sub_88094724) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88094728"))) PPC_WEAK_FUNC(sub_88094728);
PPC_FUNC_IMPL(__imp__sub_88094728) {
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
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// lwz r11,26276(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880947b0
	if (!ctx.cr6.eq) goto loc_880947B0;
	// lwz r30,260(r1)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 260);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// sth r11,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r11.u16);
	// clrlwi r3,r31,24
	ctx.r3.u64 = ctx.r31.u32 & 0xFF;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r30.u32);
	// stw r9,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// bl 0x8815c948
	ctx.lr = 0x8809478C;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8815c860
	ctx.lr = 0x88094798;
	sub_8815C860(ctx, base);
	// lwz r11,268(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 268);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880947b0
	if (ctx.cr6.eq) goto loc_880947B0;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x880947b0
	if (ctx.cr6.eq) goto loc_880947B0;
	// sth r11,16(r31)
	PPC_STORE_U16(ctx.r31.u32 + 16, ctx.r11.u16);
loc_880947B0:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
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

__attribute__((alias("__imp__sub_880947C8"))) PPC_WEAK_FUNC(sub_880947C8);
PPC_FUNC_IMPL(__imp__sub_880947C8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880947D0;
	__savegprlr_29(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// lis r7,-30643
	ctx.r7.s64 = -2008219648;
	// lwz r7,26276(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + 26276);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x8809484c
	if (!ctx.cr6.eq) goto loc_8809484C;
	// lwz r31,276(r1)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 276);
	// li r30,1
	ctx.r30.s64 = 1;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// li r29,-1
	ctx.r29.s64 = -1;
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// sth r30,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r30.u16);
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// stw r31,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r31.u32);
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r29.u32);
	// bl 0x8815c948
	ctx.lr = 0x88094828;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8815c860
	ctx.lr = 0x88094834;
	sub_8815C860(ctx, base);
	// lwz r11,284(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 284);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8809484c
	if (ctx.cr6.eq) goto loc_8809484C;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8809484c
	if (ctx.cr6.eq) goto loc_8809484C;
	// sth r11,16(r31)
	PPC_STORE_U16(ctx.r31.u32 + 16, ctx.r11.u16);
loc_8809484C:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88094854"))) PPC_WEAK_FUNC(sub_88094854);
PPC_FUNC_IMPL(__imp__sub_88094854) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88094858"))) PPC_WEAK_FUNC(sub_88094858);
PPC_FUNC_IMPL(__imp__sub_88094858) {
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
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// lwz r11,26276(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
	// mr r31,r9
	ctx.r31.u64 = ctx.r9.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880948ac
	if (!ctx.cr6.eq) goto loc_880948AC;
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// sth r11,6(r9)
	PPC_STORE_U16(ctx.r9.u32 + 6, ctx.r11.u16);
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// clrlwi r3,r10,24
	ctx.r3.u64 = ctx.r10.u32 & 0xFF;
	// bl 0x8815c948
	ctx.lr = 0x880948A4;
	sub_8815C948(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x8815c860
	ctx.lr = 0x880948AC;
	sub_8815C860(ctx, base);
loc_880948AC:
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

__attribute__((alias("__imp__sub_880948C0"))) PPC_WEAK_FUNC(sub_880948C0);
PPC_FUNC_IMPL(__imp__sub_880948C0) {
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
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r9
	ctx.r30.u64 = ctx.r9.u64;
	// lis r9,-30643
	ctx.r9.s64 = -2008219648;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// lwz r9,26276(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 26276);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x88094930
	if (!ctx.cr6.eq) goto loc_88094930;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// extsh r6,r10
	ctx.r6.s64 = ctx.r10.s16;
	// sth r9,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r9.u16);
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// bl 0x8815c948
	ctx.lr = 0x88094910;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8815c860
	ctx.lr = 0x8809491C;
	sub_8815C860(ctx, base);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x88094930
	if (ctx.cr6.eq) goto loc_88094930;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x88094930
	if (ctx.cr6.eq) goto loc_88094930;
	// sth r30,16(r31)
	PPC_STORE_U16(ctx.r31.u32 + 16, ctx.r30.u16);
loc_88094930:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
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

__attribute__((alias("__imp__sub_88094948"))) PPC_WEAK_FUNC(sub_88094948);
PPC_FUNC_IMPL(__imp__sub_88094948) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r10,r11,26432
	ctx.r10.s64 = ctx.r11.s64 + 26432;
	// lwz r11,324(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 324);
	// cntlzw r9,r11
	ctx.r9.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r3,r9,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094960"))) PPC_WEAK_FUNC(sub_88094960);
PPC_FUNC_IMPL(__imp__sub_88094960) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lwz r11,-11984(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11984);
	// lwz r3,84(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094970"))) PPC_WEAK_FUNC(sub_88094970);
PPC_FUNC_IMPL(__imp__sub_88094970) {
	PPC_FUNC_PROLOGUE();
	RT_WITNESS_ENTRY(ctx.r3.u32, ctx.r4.u32, ctx.r5.u32, ctx.r6.u32, ctx.r7.u32, ctx.r8.u32); // r23-w62 RT_WITNESS: entry args before any transform
	// lwz r11,100(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// add. r10,r5,r7
	ctx.r10.u64 = ctx.r5.u64 + ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// and r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 & ctx.r11.u64;
	// ble 0x880949e4
	if (!ctx.cr0.gt) goto loc_880949E4;
	// rlwinm r9,r7,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r7,320
	ctx.r7.s64 = 20971520;
	// subf r5,r9,r10
	ctx.r5.s64 = ctx.r10.s64 - ctx.r9.s64;
	// cmpw cr6,r5,r7
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r7.s32, ctx.xer);
	RT_WITNESS_WINDOW("gate320", ctx.r5.u32, ctx.r7.u32, ctx.cr6.lt); // r23-w62 RT_WITNESS: common arm-independent gate
	// bge cr6,0x880949e4
	if (!ctx.cr6.lt) goto loc_880949E4;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x880949ec
	if (ctx.cr6.eq) goto loc_880949EC;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// addi r9,r11,55
	ctx.r9.s64 = ctx.r11.s64 + 55;
	// lis r8,-40
	ctx.r8.s64 = -2621440;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-11984(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11984);
	// lwzx r11,r7,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r11.u32);
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// add r11,r11,r6
	ctx.r11.u64 = ctx.r11.u64 + ctx.r6.u64;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	RT_WITNESS_WINDOW("lo40", ctx.r11.u32, ctx.r8.u32, ctx.cr6.gt); // r23-w62 RT_WITNESS: r8!=0 arm, lower bound -40.0
	// ble cr6,0x880949e4
	if (!ctx.cr6.gt) goto loc_880949E4;
	// rlwinm r10,r6,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r9,280
	ctx.r9.s64 = 18350080;
	// subf r8,r10,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r10.s64;
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	RT_WITNESS_WINDOW("hi280", ctx.r8.u32, ctx.r9.u32, ctx.cr6.lt); // r23-w62 RT_WITNESS: r8!=0 arm, upper bound 280.0 (success branch)
	// blt cr6,0x88094a0c
	if (ctx.cr6.lt) goto loc_88094A0C;
loc_880949E4:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_880949EC:
	// add. r11,r4,r6
	ctx.r11.u64 = ctx.r4.u64 + ctx.r6.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble 0x880949e4
	if (!ctx.cr0.gt) goto loc_880949E4;
	// rlwinm r10,r6,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r9,240
	ctx.r9.s64 = 15728640;
	// subf r8,r10,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r10.s64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	RT_WITNESS_WINDOW("lo240", ctx.r8.u32, ctx.r9.u32, ctx.cr6.lt); // r23-w62 RT_WITNESS: r8==0 arm, single threshold 240.0 (success branch)
	// bgelr cr6
	if (!ctx.cr6.lt) return;
loc_88094A0C:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094A14"))) PPC_WEAK_FUNC(sub_88094A14);
PPC_FUNC_IMPL(__imp__sub_88094A14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88094A18"))) PPC_WEAK_FUNC(sub_88094A18);
PPC_FUNC_IMPL(__imp__sub_88094A18) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,1(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// lis r10,-30633
	ctx.r10.s64 = -2007564288;
	// extsb r9,r11
	ctx.r9.s64 = ctx.r11.s8;
	// addi r8,r10,-29756
	ctx.r8.s64 = ctx.r10.s64 + -29756;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r3,r7,r8
	PPC_STORE_U32(ctx.r7.u32 + ctx.r8.u32, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094A34"))) PPC_WEAK_FUNC(sub_88094A34);
PPC_FUNC_IMPL(__imp__sub_88094A34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88094A38"))) PPC_WEAK_FUNC(sub_88094A38);
PPC_FUNC_IMPL(__imp__sub_88094A38) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addi r10,r3,55
	ctx.r10.s64 = ctx.r3.s64 + 55;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-11984(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11984);
	// lwzx r3,r9,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094A50"))) PPC_WEAK_FUNC(sub_88094A50);
PPC_FUNC_IMPL(__imp__sub_88094A50) {
	PPC_FUNC_PROLOGUE();
	// addi r11,r4,34
	ctx.r11.s64 = ctx.r4.s64 + 34;
	// lwz r10,2300(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2300);
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// neg r3,r8
	ctx.r3.s64 = -ctx.r8.s64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094A68"))) PPC_WEAK_FUNC(sub_88094A68);
PPC_FUNC_IMPL(__imp__sub_88094A68) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,2300(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2300);
	// rlwinm r11,r4,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,268(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 268);
	// neg r3,r10
	ctx.r3.s64 = -ctx.r10.s64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094A80"))) PPC_WEAK_FUNC(sub_88094A80);
PPC_FUNC_IMPL(__imp__sub_88094A80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,2300(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2300);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x88094aa8
	if (ctx.cr6.eq) goto loc_88094AA8;
	// lwz r10,156(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 156);
	// lwz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// srawi r8,r10,16
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xFFFF) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 16;
	// addze r7,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r7.s64 = temp.s64;
	// rlwinm r6,r7,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// subf r3,r6,r9
	ctx.r3.s64 = ctx.r9.s64 - ctx.r6.s64;
	// stw r3,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r3.u32);
loc_88094AA8:
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,160(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 160);
	// lwz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// srawi r9,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 16;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// rlwinm r7,r8,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// stw r6,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094AD0"))) PPC_WEAK_FUNC(sub_88094AD0);
PPC_FUNC_IMPL(__imp__sub_88094AD0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2300(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2300);
	// lwz r10,160(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 160);
	// neg r3,r10
	ctx.r3.s64 = -ctx.r10.s64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094AE0"))) PPC_WEAK_FUNC(sub_88094AE0);
PPC_FUNC_IMPL(__imp__sub_88094AE0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2300(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2300);
	// lwz r10,156(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 156);
	// neg r3,r10
	ctx.r3.s64 = -ctx.r10.s64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094AF0"))) PPC_WEAK_FUNC(sub_88094AF0);
PPC_FUNC_IMPL(__imp__sub_88094AF0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26272(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26272);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88094b08
	if (ctx.cr6.eq) goto loc_88094B08;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_88094B08:
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addi r10,r3,51
	ctx.r10.s64 = ctx.r3.s64 + 51;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-11984(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11984);
	// lwzx r3,r9,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094B20"))) PPC_WEAK_FUNC(sub_88094B20);
PPC_FUNC_IMPL(__imp__sub_88094B20) {
	PPC_FUNC_PROLOGUE();
	// b 0x88153458
	sub_88153458(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88094B24"))) PPC_WEAK_FUNC(sub_88094B24);
PPC_FUNC_IMPL(__imp__sub_88094B24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88094B28"))) PPC_WEAK_FUNC(sub_88094B28);
PPC_FUNC_IMPL(__imp__sub_88094B28) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lis r11,-30683
	ctx.r11.s64 = -2010841088;
	// addi r7,r11,12184
	ctx.r7.s64 = ctx.r11.s64 + 12184;
	// lwz r11,-11984(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11984);
	// addi r9,r7,-48
	ctx.r9.s64 = ctx.r7.s64 + -48;
	// lwz r8,88(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// lwz r11,84(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// rlwinm r10,r8,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// blt cr6,0x88094bd0
	if (ctx.cr6.lt) goto loc_88094BD0;
	// beq cr6,0x88094bac
	if (ctx.cr6.eq) goto loc_88094BAC;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x88094c08
	if (!ctx.cr6.lt) goto loc_88094C08;
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addis r9,r11,16
	ctx.r9.s64 = ctx.r11.s64 + 1048576;
	// cmpw cr6,r9,r4
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r4.s32, ctx.xer);
	// blt cr6,0x88094ba4
	if (ctx.cr6.lt) goto loc_88094BA4;
	// lwz r11,4(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// addis r10,r11,24
	ctx.r10.s64 = ctx.r11.s64 + 1572864;
	// cmpw cr6,r4,r10
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r10.s32, ctx.xer);
loc_88094B7C:
	// blt cr6,0x88094ba4
	if (ctx.cr6.lt) goto loc_88094BA4;
	// rlwinm r11,r8,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r7
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r7.u32);
	// addis r10,r11,-8
	ctx.r10.s64 = ctx.r11.s64 + -524288;
	// cmpw cr6,r3,r10
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x88094ba4
	if (ctx.cr6.lt) goto loc_88094BA4;
	// lis r10,248
	ctx.r10.s64 = 16252928;
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// cmpw cr6,r9,r3
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r3.s32, ctx.xer);
	// bge cr6,0x88094c08
	if (!ctx.cr6.lt) goto loc_88094C08;
loc_88094BA4:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_88094BAC:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lis r11,32
	ctx.r11.s64 = 2097152;
	// add r6,r9,r11
	ctx.r6.u64 = ctx.r9.u64 + ctx.r11.u64;
	// cmpw cr6,r6,r4
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r4.s32, ctx.xer);
	// blt cr6,0x88094ba4
	if (ctx.cr6.lt) goto loc_88094BA4;
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmpw cr6,r4,r9
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r9.s32, ctx.xer);
	// b 0x88094b7c
	goto loc_88094B7C;
loc_88094BD0:
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpw cr6,r11,r4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r4.s32, ctx.xer);
	// blt cr6,0x88094ba4
	if (ctx.cr6.lt) goto loc_88094BA4;
	// lwz r11,4(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmpw cr6,r4,r11
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x88094ba4
	if (ctx.cr6.lt) goto loc_88094BA4;
	// rlwinm r11,r8,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r7
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r7.u32);
	// cmpw cr6,r3,r11
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x88094ba4
	if (ctx.cr6.lt) goto loc_88094BA4;
	// lis r10,240
	ctx.r10.s64 = 15728640;
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// cmpw cr6,r9,r3
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r3.s32, ctx.xer);
	// blt cr6,0x88094ba4
	if (ctx.cr6.lt) goto loc_88094BA4;
loc_88094C08:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094C10"))) PPC_WEAK_FUNC(sub_88094C10);
PPC_FUNC_IMPL(__imp__sub_88094C10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lis r10,-30683
	ctx.r10.s64 = -2010841088;
	// addi r9,r10,12112
	ctx.r9.s64 = ctx.r10.s64 + 12112;
	// lwz r11,-11984(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11984);
	// lwz r8,88(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r7,r9
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// subfc r5,r3,r6
	ctx.xer.ca = ctx.r6.u32 >= ctx.r3.u32;
	ctx.r5.s64 = ctx.r6.s64 - ctx.r3.s64;
	// eqv r4,r3,r6
	ctx.r4.u64 = ~(ctx.r3.u64 ^ ctx.r6.u64); // FIX 2026-07-24: eqv was silently dropped by the recompiler
	// rlwinm r3,r4,1,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0x1;
	// addze r11,r3
	temp.s64 = ctx.r3.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r11.s64 = temp.s64;
	// clrlwi r3,r11,31
	ctx.r3.u64 = ctx.r11.u32 & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094C44"))) PPC_WEAK_FUNC(sub_88094C44);
PPC_FUNC_IMPL(__imp__sub_88094C44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88094C48"))) PPC_WEAK_FUNC(sub_88094C48);
PPC_FUNC_IMPL(__imp__sub_88094C48) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,1(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// extsb r9,r11
	ctx.r9.s64 = ctx.r11.s8;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x88094c60
	if (!ctx.cr6.eq) goto loc_88094C60;
	// stw r3,16(r4)
	PPC_STORE_U32(ctx.r4.u32 + 16, ctx.r3.u32);
loc_88094C60:
	// lwz r11,20(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,20(r4)
	PPC_STORE_U32(ctx.r4.u32 + 20, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094C70"))) PPC_WEAK_FUNC(sub_88094C70);
PPC_FUNC_IMPL(__imp__sub_88094C70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lwz r8,-11984(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11984);
	// addic. r11,r8,1448
	ctx.xer.ca = ctx.r8.u32 > 4294965847;
	ctx.r11.s64 = ctx.r8.s64 + 1448;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x88094cd8
	if (ctx.cr0.eq) goto loc_88094CD8;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// lwz r9,68(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// subf. r11,r3,r10
	ctx.r11.s64 = ctx.r10.s64 - ctx.r3.s64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// neg r10,r11
	ctx.r10.s64 = -ctx.r11.s64;
	// blt 0x88094c98
	if (ctx.cr0.lt) goto loc_88094C98;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_88094C98:
	// subf. r11,r4,r9
	ctx.r11.s64 = ctx.r9.s64 - ctx.r4.s64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge 0x88094ca4
	if (!ctx.cr0.lt) goto loc_88094CA4;
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
loc_88094CA4:
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x88094cbc
	if (!ctx.cr6.lt) goto loc_88094CBC;
	// srawi r10,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 1;
	// addze r10,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r10.s64 = temp.s64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// b 0x88094cc8
	goto loc_88094CC8;
loc_88094CBC:
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
loc_88094CC8:
	// cmpw cr6,r11,r5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r5.s32, ctx.xer);
	// bgt cr6,0x88094cd8
	if (ctx.cr6.gt) goto loc_88094CD8;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_88094CD8:
	// addic. r11,r8,1644
	ctx.xer.ca = ctx.r8.u32 > 4294965651;
	ctx.r11.s64 = ctx.r8.s64 + 1644;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x88094d34
	if (ctx.cr0.eq) goto loc_88094D34;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// lwz r9,68(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// subf. r11,r3,r10
	ctx.r11.s64 = ctx.r10.s64 - ctx.r3.s64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// neg r10,r11
	ctx.r10.s64 = -ctx.r11.s64;
	// blt 0x88094cf8
	if (ctx.cr0.lt) goto loc_88094CF8;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_88094CF8:
	// subf. r11,r4,r9
	ctx.r11.s64 = ctx.r9.s64 - ctx.r4.s64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge 0x88094d04
	if (!ctx.cr0.lt) goto loc_88094D04;
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
loc_88094D04:
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x88094d1c
	if (!ctx.cr6.lt) goto loc_88094D1C;
	// srawi r10,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 1;
	// addze r10,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r10.s64 = temp.s64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// b 0x88094d28
	goto loc_88094D28;
loc_88094D1C:
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
loc_88094D28:
	// cmpw cr6,r11,r5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r5.s32, ctx.xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// blelr cr6
	if (!ctx.cr6.gt) return;
loc_88094D34:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094D3C"))) PPC_WEAK_FUNC(sub_88094D3C);
PPC_FUNC_IMPL(__imp__sub_88094D3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88094D40"))) PPC_WEAK_FUNC(sub_88094D40);
PPC_FUNC_IMPL(__imp__sub_88094D40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lis r10,-30683
	ctx.r10.s64 = -2010841088;
	// addi r9,r10,12208
	ctx.r9.s64 = ctx.r10.s64 + 12208;
	// lwz r8,-11984(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11984);
	// lwz r7,88(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 88);
	// lwz r11,84(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 84);
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// lwzx r7,r6,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// beq cr6,0x88094d78
	if (ctx.cr6.eq) goto loc_88094D78;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x88094d7c
	if (!ctx.cr6.eq) goto loc_88094D7C;
	// addis r7,r7,-16
	ctx.r7.s64 = ctx.r7.s64 + -1048576;
	// b 0x88094d7c
	goto loc_88094D7C;
loc_88094D78:
	// addis r7,r7,-8
	ctx.r7.s64 = ctx.r7.s64 + -524288;
loc_88094D7C:
	// addic. r11,r8,1448
	ctx.xer.ca = ctx.r8.u32 > 4294965847;
	ctx.r11.s64 = ctx.r8.s64 + 1448;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x88094ddc
	if (ctx.cr0.eq) goto loc_88094DDC;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// lwz r9,68(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// subf. r11,r3,r10
	ctx.r11.s64 = ctx.r10.s64 - ctx.r3.s64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// neg r10,r11
	ctx.r10.s64 = -ctx.r11.s64;
	// blt 0x88094d9c
	if (ctx.cr0.lt) goto loc_88094D9C;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_88094D9C:
	// subf. r11,r4,r9
	ctx.r11.s64 = ctx.r9.s64 - ctx.r4.s64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge 0x88094da8
	if (!ctx.cr0.lt) goto loc_88094DA8;
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
loc_88094DA8:
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x88094dc0
	if (!ctx.cr6.lt) goto loc_88094DC0;
	// srawi r10,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 1;
	// addze r10,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r10.s64 = temp.s64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// b 0x88094dcc
	goto loc_88094DCC;
loc_88094DC0:
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
loc_88094DCC:
	// cmpw cr6,r11,r7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r7.s32, ctx.xer);
	// bgt cr6,0x88094ddc
	if (ctx.cr6.gt) goto loc_88094DDC;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_88094DDC:
	// addic. r11,r8,1644
	ctx.xer.ca = ctx.r8.u32 > 4294965651;
	ctx.r11.s64 = ctx.r8.s64 + 1644;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x88094e38
	if (ctx.cr0.eq) goto loc_88094E38;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// lwz r9,68(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// subf. r11,r3,r10
	ctx.r11.s64 = ctx.r10.s64 - ctx.r3.s64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// neg r10,r11
	ctx.r10.s64 = -ctx.r11.s64;
	// blt 0x88094dfc
	if (ctx.cr0.lt) goto loc_88094DFC;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_88094DFC:
	// subf. r11,r4,r9
	ctx.r11.s64 = ctx.r9.s64 - ctx.r4.s64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge 0x88094e08
	if (!ctx.cr0.lt) goto loc_88094E08;
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
loc_88094E08:
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x88094e20
	if (!ctx.cr6.lt) goto loc_88094E20;
	// srawi r10,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 1;
	// addze r10,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r10.s64 = temp.s64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// b 0x88094e2c
	goto loc_88094E2C;
loc_88094E20:
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
loc_88094E2C:
	// cmpw cr6,r11,r7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r7.s32, ctx.xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// blelr cr6
	if (!ctx.cr6.gt) return;
loc_88094E38:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094E40"))) PPC_WEAK_FUNC(sub_88094E40);
PPC_FUNC_IMPL(__imp__sub_88094E40) {
	PPC_FUNC_PROLOGUE();
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r4,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r4.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,96(r3)
	PPC_STORE_U32(ctx.r3.u32 + 96, ctx.r11.u32);
	// stw r10,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, ctx.r10.u32);
	// b 0x88169750
	sub_88169750(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88094E58"))) PPC_WEAK_FUNC(sub_88094E58);
PPC_FUNC_IMPL(__imp__sub_88094E58) {
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
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88094f20
	if (ctx.cr6.eq) goto loc_88094F20;
	// lwz r11,84(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// beq cr6,0x88094e98
	if (ctx.cr6.eq) goto loc_88094E98;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x88094E98;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_88094E98:
	// lwz r3,2296(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2296);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88094eac
	if (ctx.cr6.eq) goto loc_88094EAC;
	// bl 0x88097140
	ctx.lr = 0x88094EA8;
	sub_88097140(ctx, base);
	// stw r30,2296(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2296, ctx.r30.u32);
loc_88094EAC:
	// li r10,20
	ctx.r10.s64 = 20;
	// stw r30,1800(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1800, ctx.r30.u32);
	// addi r11,r31,120
	ctx.r11.s64 = ctx.r31.s64 + 120;
	// stw r30,2288(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2288, ctx.r30.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_88094EC0:
	// stwu r30,80(r11)
	ea = 80 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r30.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x88094ec0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88094EC0;
	// li r10,10
	ctx.r10.s64 = 10;
	// addi r11,r31,1760
	ctx.r11.s64 = ctx.r31.s64 + 1760;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_88094ED4:
	// stwu r30,48(r11)
	ea = 48 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r30.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x88094ed4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88094ED4;
	// lwz r8,2312(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2312);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x88094f20
	if (ctx.cr6.eq) goto loc_88094F20;
	// lis r9,-30640
	ctx.r9.s64 = -2008023040;
	// lwz r10,2308(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2308);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// addi r9,r9,32232
	ctx.r9.s64 = ctx.r9.s64 + 32232;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// ble cr6,0x88094f1c
	if (!ctx.cr6.gt) goto loc_88094F1C;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
loc_88094F08:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stbu r30,1(r10)
	ea = 1 + ctx.r10.u32;
	PPC_STORE_U8(ea, ctx.r30.u8);
	ctx.r10.u32 = ea;
	// lwz r9,2312(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2312);
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x88094f08
	if (ctx.cr6.lt) goto loc_88094F08;
loc_88094F1C:
	// stw r30,2312(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2312, ctx.r30.u32);
loc_88094F20:
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

__attribute__((alias("__imp__sub_88094F38"))) PPC_WEAK_FUNC(sub_88094F38);
PPC_FUNC_IMPL(__imp__sub_88094F38) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88094F40;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-30597
	ctx.r30.s64 = -2005204992;
	// lis r10,-30638
	ctx.r10.s64 = -2007891968;
	// addi r9,r30,-11988
	ctx.r9.s64 = ctx.r30.s64 + -11988;
	// lis r5,4
	ctx.r5.s64 = 262144;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r3,r10,-1168
	ctx.r3.s64 = ctx.r10.s64 + -1168;
	// ori r5,r5,36864
	ctx.r5.u64 = ctx.r5.u64 | 36864;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r11.u32);
	// bl 0x88073bd0
	ctx.lr = 0x88094F6C;
	sub_88073BD0(ctx, base);
	// lis r8,-30639
	ctx.r8.s64 = -2007957504;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// addi r3,r8,-31640
	ctx.r3.s64 = ctx.r8.s64 + -31640;
	// ori r5,r5,30464
	ctx.r5.u64 = ctx.r5.u64 | 30464;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x88073bd0
	ctx.lr = 0x88094F84;
	sub_88073BD0(ctx, base);
	// lis r7,-30639
	ctx.r7.s64 = -2007957504;
	// li r5,1500
	ctx.r5.s64 = 1500;
	// addi r31,r7,-31800
	ctx.r31.s64 = ctx.r7.s64 + -31800;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,-1504
	ctx.r3.s64 = ctx.r31.s64 + -1504;
	// bl 0x88073bd0
	ctx.lr = 0x88094F9C;
	sub_88073BD0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,160
	ctx.r5.s64 = 160;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x88073bd0
	ctx.lr = 0x88094FAC;
	sub_88073BD0(ctx, base);
	// lis r6,-30641
	ctx.r6.s64 = -2008088576;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// addi r3,r6,8752
	ctx.r3.s64 = ctx.r6.s64 + 8752;
	// ori r5,r5,22944
	ctx.r5.u64 = ctx.r5.u64 | 22944;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x88073bd0
	ctx.lr = 0x88094FC4;
	sub_88073BD0(ctx, base);
	// lis r4,-30641
	ctx.r4.s64 = -2008088576;
	// li r5,25600
	ctx.r5.s64 = 25600;
	// addi r31,r4,8352
	ctx.r31.s64 = ctx.r4.s64 + 8352;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,-25600
	ctx.r3.s64 = ctx.r31.s64 + -25600;
	// bl 0x88073bd0
	ctx.lr = 0x88094FDC;
	sub_88073BD0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,400
	ctx.r5.s64 = 400;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x88073bd0
	ctx.lr = 0x88094FEC;
	sub_88073BD0(ctx, base);
	// lis r8,-30671
	ctx.r8.s64 = -2010054656;
	// lis r7,16838
	ctx.r7.s64 = 1103495168;
	// lis r6,-30633
	ctx.r6.s64 = -2007564288;
	// ori r5,r7,20077
	ctx.r5.u64 = ctx.r7.u64 | 20077;
	// lis r4,-30633
	ctx.r4.s64 = -2007564288;
	// lwz r11,4200(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4200);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// mullw r11,r11,r5
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r5.s32);
	// stw r10,-29772(r6)
	PPC_STORE_U32(ctx.r6.u32 + -29772, ctx.r10.u32);
	// stw r9,-29808(r4)
	PPC_STORE_U32(ctx.r4.u32 + -29808, ctx.r9.u32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// lis r3,-30633
	ctx.r3.s64 = -2007564288;
	// lis r7,-30633
	ctx.r7.s64 = -2007564288;
	// stw r11,4200(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4200, ctx.r11.u32);
	// lis r6,-30641
	ctx.r6.s64 = -2008088576;
	// lhz r8,4200(r8)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4200);
	// lis r4,-30633
	ctx.r4.s64 = -2007564288;
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r5,-30633
	ctx.r5.s64 = -2007564288;
	// stw r11,-29804(r3)
	PPC_STORE_U32(ctx.r3.u32 + -29804, ctx.r11.u32);
	// lis r3,-30633
	ctx.r3.s64 = -2007564288;
	// stw r10,-29796(r7)
	PPC_STORE_U32(ctx.r7.u32 + -29796, ctx.r10.u32);
	// lis r7,-30638
	ctx.r7.s64 = -2007891968;
	// stw r9,-17252(r6)
	PPC_STORE_U32(ctx.r6.u32 + -17252, ctx.r9.u32);
	// lis r6,-30640
	ctx.r6.s64 = -2008023040;
	// stw r10,-29764(r4)
	PPC_STORE_U32(ctx.r4.u32 + -29764, ctx.r10.u32);
	// lis r29,-30643
	ctx.r29.s64 = -2008219648;
	// lis r4,-30633
	ctx.r4.s64 = -2007564288;
	// stw r11,-29768(r5)
	PPC_STORE_U32(ctx.r5.u32 + -29768, ctx.r11.u32);
	// addi r31,r29,32388
	ctx.r31.s64 = ctx.r29.s64 + 32388;
	// stw r9,-29744(r3)
	PPC_STORE_U32(ctx.r3.u32 + -29744, ctx.r9.u32);
	// stw r11,-1176(r7)
	PPC_STORE_U32(ctx.r7.u32 + -1176, ctx.r11.u32);
	// li r5,148
	ctx.r5.s64 = 148;
	// stw r10,32224(r6)
	PPC_STORE_U32(ctx.r6.u32 + 32224, ctx.r10.u32);
	// addi r3,r31,388
	ctx.r3.s64 = ctx.r31.s64 + 388;
	// lis r7,-30633
	ctx.r7.s64 = -2007564288;
	// lis r6,-30638
	ctx.r6.s64 = -2007891968;
	// stw r11,-29792(r4)
	PPC_STORE_U32(ctx.r4.u32 + -29792, ctx.r11.u32);
	// stw r10,-29788(r7)
	PPC_STORE_U32(ctx.r7.u32 + -29788, ctx.r10.u32);
	// lis r7,-30633
	ctx.r7.s64 = -2007564288;
	// stw r9,-1172(r6)
	PPC_STORE_U32(ctx.r6.u32 + -1172, ctx.r9.u32);
	// lis r6,-30633
	ctx.r6.s64 = -2007564288;
	// lis r4,-30633
	ctx.r4.s64 = -2007564288;
	// lis r28,-30633
	ctx.r28.s64 = -2007564288;
	// stw r10,-29736(r7)
	PPC_STORE_U32(ctx.r7.u32 + -29736, ctx.r10.u32);
	// lis r7,-30633
	ctx.r7.s64 = -2007564288;
	// stw r9,-29732(r6)
	PPC_STORE_U32(ctx.r6.u32 + -29732, ctx.r9.u32);
	// lis r6,-30639
	ctx.r6.s64 = -2007957504;
	// stw r11,-29760(r4)
	PPC_STORE_U32(ctx.r4.u32 + -29760, ctx.r11.u32);
	// lis r4,-30633
	ctx.r4.s64 = -2007564288;
	// sth r11,-29800(r28)
	PPC_STORE_U16(ctx.r28.u32 + -29800, ctx.r11.u16);
	// stw r10,-29784(r7)
	PPC_STORE_U32(ctx.r7.u32 + -29784, ctx.r10.u32);
	// lis r7,-30633
	ctx.r7.s64 = -2007564288;
	// stw r9,-31804(r6)
	PPC_STORE_U32(ctx.r6.u32 + -31804, ctx.r9.u32);
	// lis r6,-30640
	ctx.r6.s64 = -2008023040;
	// stw r11,-29740(r4)
	PPC_STORE_U32(ctx.r4.u32 + -29740, ctx.r11.u32);
	// lis r4,-30633
	ctx.r4.s64 = -2007564288;
	// stw r10,-29780(r7)
	PPC_STORE_U32(ctx.r7.u32 + -29780, ctx.r10.u32);
	// lis r7,-30667
	ctx.r7.s64 = -2009792512;
	// stw r9,32228(r6)
	PPC_STORE_U32(ctx.r6.u32 + 32228, ctx.r9.u32);
	// clrlwi r9,r8,31
	ctx.r9.u64 = ctx.r8.u32 & 0x1;
	// stw r11,-29776(r4)
	PPC_STORE_U32(ctx.r4.u32 + -29776, ctx.r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r9,-11988(r30)
	PPC_STORE_U32(ctx.r30.u32 + -11988, ctx.r9.u32);
	// stb r10,12342(r7)
	PPC_STORE_U8(ctx.r7.u32 + 12342, ctx.r10.u8);
	// bl 0x88073bd0
	ctx.lr = 0x880950F8;
	sub_88073BD0(ctx, base);
	// li r11,241
	ctx.r11.s64 = 241;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r11,404(r31)
	PPC_STORE_U32(ctx.r31.u32 + 404, ctx.r11.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r10,420(r31)
	PPC_STORE_U32(ctx.r31.u32 + 420, ctx.r10.u32);
	// stw r9,396(r31)
	PPC_STORE_U32(ctx.r31.u32 + 396, ctx.r9.u32);
	// stw r11,32388(r29)
	PPC_STORE_U32(ctx.r29.u32 + 32388, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88095120"))) PPC_WEAK_FUNC(sub_88095120);
PPC_FUNC_IMPL(__imp__sub_88095120) {
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
	// lis r11,-30638
	ctx.r11.s64 = -2007891968;
	// li r30,128
	ctx.r30.s64 = 128;
	// addi r31,r11,-1168
	ctx.r31.s64 = ctx.r11.s64 + -1168;
loc_88095140:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88095154
	if (ctx.cr6.eq) goto loc_88095154;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88094e58
	ctx.lr = 0x88095154;
	sub_88094E58(ctx, base);
loc_88095154:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r31,r31,2336
	ctx.r31.s64 = ctx.r31.s64 + 2336;
	// bne 0x88095140
	if (!ctx.cr0.eq) goto loc_88095140;
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

__attribute__((alias("__imp__sub_88095178"))) PPC_WEAK_FUNC(sub_88095178);
PPC_FUNC_IMPL(__imp__sub_88095178) {
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
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// rlwinm r10,r11,0,21,21
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x400;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880951ac
	if (ctx.cr6.eq) goto loc_880951AC;
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
loc_880951AC:
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lwz r11,-11984(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11984);
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x88095324
	if (!ctx.cr6.eq) goto loc_88095324;
	// lwz r11,8(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880951d8
	if (ctx.cr6.eq) goto loc_880951D8;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x880952dc
	if (!ctx.cr6.eq) goto loc_880952DC;
loc_880951D8:
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// li r7,48
	ctx.r7.s64 = 48;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// bne cr6,0x8809525c
	if (!ctx.cr6.eq) goto loc_8809525C;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88095224
	if (ctx.cr6.eq) goto loc_88095224;
	// lwz r9,128(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 128);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r4,88(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 88);
	// stw r8,184(r11)
	PPC_STORE_U32(ctx.r11.u32 + 184, ctx.r8.u32);
	// subfic r3,r4,4
	ctx.xer.ca = ctx.r4.u32 <= 4;
	ctx.r3.s64 = 4 - ctx.r4.s64;
	// rlwinm r9,r3,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 31) & 0x7FFFFFFF;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r10,3
	ctx.r10.s64 = ctx.r10.s64 + 3;
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r10,176(r11)
	PPC_STORE_U32(ctx.r11.u32 + 176, ctx.r10.u32);
	// cmpwi cr6,r9,48
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 48, ctx.xer);
	// b 0x8809524c
	goto loc_8809524C;
loc_88095224:
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 128);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r8,88(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 88);
	// stw r9,184(r11)
	PPC_STORE_U32(ctx.r11.u32 + 184, ctx.r9.u32);
	// subfic r4,r8,4
	ctx.xer.ca = ctx.r8.u32 <= 4;
	ctx.r4.s64 = 4 - ctx.r8.s64;
	// rlwinm r10,r4,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r3,r10,4
	ctx.r3.s64 = ctx.r10.s64 + 4;
	// rotlwi r10,r3,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// stw r3,176(r11)
	PPC_STORE_U32(ctx.r11.u32 + 176, ctx.r3.u32);
	// cmpwi cr6,r10,48
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 48, ctx.xer);
loc_8809524C:
	// blt cr6,0x88095314
	if (ctx.cr6.lt) goto loc_88095314;
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r7,176(r11)
	PPC_STORE_U32(ctx.r11.u32 + 176, ctx.r7.u32);
	// b 0x88095310
	goto loc_88095310;
loc_8809525C:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880952a0
	if (ctx.cr6.eq) goto loc_880952A0;
	// lwz r9,128(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 128);
	// li r8,3
	ctx.r8.s64 = 3;
	// lwz r4,88(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 88);
	// stw r8,184(r11)
	PPC_STORE_U32(ctx.r11.u32 + 184, ctx.r8.u32);
	// subfic r3,r4,4
	ctx.xer.ca = ctx.r4.u32 <= 4;
	ctx.r3.s64 = 4 - ctx.r4.s64;
	// rlwinm r9,r3,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 31) & 0x7FFFFFFF;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r10,10
	ctx.r10.s64 = ctx.r10.s64 + 10;
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r10,176(r11)
	PPC_STORE_U32(ctx.r11.u32 + 176, ctx.r10.u32);
	// cmpwi cr6,r9,48
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 48, ctx.xer);
	// blt cr6,0x88095314
	if (ctx.cr6.lt) goto loc_88095314;
	// stw r8,184(r11)
	PPC_STORE_U32(ctx.r11.u32 + 184, ctx.r8.u32);
	// stw r7,176(r11)
	PPC_STORE_U32(ctx.r11.u32 + 176, ctx.r7.u32);
	// b 0x88095314
	goto loc_88095314;
loc_880952A0:
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 128);
	// li r9,6
	ctx.r9.s64 = 6;
	// lwz r8,88(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 88);
	// stw r9,184(r11)
	PPC_STORE_U32(ctx.r11.u32 + 184, ctx.r9.u32);
	// subfic r4,r8,4
	ctx.xer.ca = ctx.r8.u32 <= 4;
	ctx.r4.s64 = 4 - ctx.r8.s64;
	// rlwinm r10,r4,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r3,r10,12
	ctx.r3.s64 = ctx.r10.s64 + 12;
	// rotlwi r10,r3,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// stw r3,176(r11)
	PPC_STORE_U32(ctx.r11.u32 + 176, ctx.r3.u32);
	// cmpwi cr6,r10,48
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 48, ctx.xer);
	// blt cr6,0x88095314
	if (ctx.cr6.lt) goto loc_88095314;
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r7,176(r11)
	PPC_STORE_U32(ctx.r11.u32 + 176, ctx.r7.u32);
	// stw r10,184(r11)
	PPC_STORE_U32(ctx.r11.u32 + 184, ctx.r10.u32);
	// b 0x88095314
	goto loc_88095314;
loc_880952DC:
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// li r7,48
	ctx.r7.s64 = 48;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// bne cr6,0x88095364
	if (!ctx.cr6.eq) goto loc_88095364;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8809535c
	if (ctx.cr6.eq) goto loc_8809535C;
	// li r9,3
	ctx.r9.s64 = 3;
	// cmpwi cr6,r10,48
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 48, ctx.xer);
	// stw r9,184(r11)
	PPC_STORE_U32(ctx.r11.u32 + 184, ctx.r9.u32);
	// blt cr6,0x88095314
	if (ctx.cr6.lt) goto loc_88095314;
	// stw r7,176(r11)
	PPC_STORE_U32(ctx.r11.u32 + 176, ctx.r7.u32);
loc_8809530C:
	// li r10,6
	ctx.r10.s64 = 6;
loc_88095310:
	// stw r10,184(r11)
	PPC_STORE_U32(ctx.r11.u32 + 184, ctx.r10.u32);
loc_88095314:
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// cmpwi cr6,r10,48
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 48, ctx.xer);
	// blt cr6,0x88095324
	if (ctx.cr6.lt) goto loc_88095324;
	// stw r7,176(r11)
	PPC_STORE_U32(ctx.r11.u32 + 176, ctx.r7.u32);
loc_88095324:
	// lwz r11,0(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8809533c
	if (ctx.cr6.eq) goto loc_8809533C;
	// li r11,10
	ctx.r11.s64 = 10;
	// divwu r5,r5,r11
	ctx.r5.u32 = ppc_divwu(ctx.r5.u32, ctx.r11.u32);
loc_8809533C:
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// lwz r3,8(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// bl 0x88134248
	ctx.lr = 0x88095348;
	sub_88134248(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_8809535C:
	// li r10,3
	ctx.r10.s64 = 3;
	// b 0x88095310
	goto loc_88095310;
loc_88095364:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8809530c
	if (ctx.cr6.eq) goto loc_8809530C;
	// li r9,6
	ctx.r9.s64 = 6;
	// cmpwi cr6,r10,48
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 48, ctx.xer);
	// stw r9,184(r11)
	PPC_STORE_U32(ctx.r11.u32 + 184, ctx.r9.u32);
	// blt cr6,0x88095314
	if (ctx.cr6.lt) goto loc_88095314;
	// stw r7,176(r11)
	PPC_STORE_U32(ctx.r11.u32 + 176, ctx.r7.u32);
	// stw r9,184(r11)
	PPC_STORE_U32(ctx.r11.u32 + 184, ctx.r9.u32);
	// b 0x88095314
	goto loc_88095314;
}

__attribute__((alias("__imp__sub_88095388"))) PPC_WEAK_FUNC(sub_88095388);
PPC_FUNC_IMPL(__imp__sub_88095388) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88095390;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-30633
	ctx.r10.s64 = -2007564288;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r31,r10,-29756
	ctx.r31.s64 = ctx.r10.s64 + -29756;
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// lis r8,-30711
	ctx.r8.s64 = -2012676096;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r8,18968
	ctx.r4.s64 = ctx.r8.s64 + 18968;
	// lwz r3,-11984(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -11984);
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// bl 0x881363e0
	ctx.lr = 0x880953D0;
	sub_881363E0(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880954c8
	if (ctx.cr6.eq) goto loc_880954C8;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x880954ac
	if (ctx.cr6.eq) goto loc_880954AC;
	// lwz r6,64(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r5,68(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// lwz r4,64(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// subf. r11,r6,r9
	ctx.r11.s64 = ctx.r9.s64 - ctx.r6.s64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r3,68(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// bge 0x88095408
	if (!ctx.cr0.lt) goto loc_88095408;
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
loc_88095408:
	// lwz r8,4(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// subf. r10,r5,r8
	ctx.r10.s64 = ctx.r8.s64 - ctx.r5.s64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bge 0x88095418
	if (!ctx.cr0.lt) goto loc_88095418;
	// neg r10,r10
	ctx.r10.s64 = -ctx.r10.s64;
loc_88095418:
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x88095430
	if (!ctx.cr6.lt) goto loc_88095430;
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x8809543c
	goto loc_8809543C;
loc_88095430:
	// srawi r10,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 1;
	// addze r10,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r10.s64 = temp.s64;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_8809543C:
	// subf. r11,r4,r9
	ctx.r11.s64 = ctx.r9.s64 - ctx.r4.s64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// neg r10,r11
	ctx.r10.s64 = -ctx.r11.s64;
	// blt 0x8809544c
	if (ctx.cr0.lt) goto loc_8809544C;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_8809544C:
	// subf. r11,r3,r8
	ctx.r11.s64 = ctx.r8.s64 - ctx.r3.s64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge 0x88095458
	if (!ctx.cr0.lt) goto loc_88095458;
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
loc_88095458:
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x88095470
	if (!ctx.cr6.lt) goto loc_88095470;
	// srawi r10,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 1;
	// addze r10,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r10.s64 = temp.s64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// b 0x8809547c
	goto loc_8809547C;
loc_88095470:
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
loc_8809547C:
	// cmpw cr6,r7,r11
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r11.s32, ctx.xer);
	// bgt cr6,0x88095498
	if (ctx.cr6.gt) goto loc_88095498;
	// stw r6,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r6.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r5,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r5.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_88095498:
	// stw r3,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r4,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r4.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_880954AC:
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r9,68(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// stw r10,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r10.u32);
	// stw r9,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_880954C8:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880954ac
	if (!ctx.cr6.eq) goto loc_880954AC;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880954E0"))) PPC_WEAK_FUNC(sub_880954E0);
PPC_FUNC_IMPL(__imp__sub_880954E0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x880954E8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r30,-30597
	ctx.r30.s64 = -2005204992;
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// lis r10,-30711
	ctx.r10.s64 = -2012676096;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r10,19528
	ctx.r4.s64 = ctx.r10.s64 + 19528;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,-11984(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + -11984);
	// bl 0x881363e0
	ctx.lr = 0x8809551C;
	sub_881363E0(ctx, base);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x88095540
	if (!ctx.cr6.eq) goto loc_88095540;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88095554
	if (!ctx.cr6.eq) goto loc_88095554;
	// lwz r11,-11984(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -11984);
	// addi r11,r11,1644
	ctx.r11.s64 = ctx.r11.s64 + 1644;
	// b 0x88095550
	goto loc_88095550;
loc_88095540:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88095554
	if (!ctx.cr6.eq) goto loc_88095554;
	// lwz r11,-11984(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -11984);
	// addi r11,r11,1448
	ctx.r11.s64 = ctx.r11.s64 + 1448;
loc_88095550:
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
loc_88095554:
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8809556c
	if (!ctx.cr6.eq) goto loc_8809556C;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8809556C:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// stw r10,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r10.u32);
	// lwz r9,68(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// stw r9,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809558C"))) PPC_WEAK_FUNC(sub_8809558C);
PPC_FUNC_IMPL(__imp__sub_8809558C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88095590"))) PPC_WEAK_FUNC(sub_88095590);
PPC_FUNC_IMPL(__imp__sub_88095590) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88095598;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r30,-30597
	ctx.r30.s64 = -2005204992;
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// lis r10,-30711
	ctx.r10.s64 = -2012676096;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r10,19528
	ctx.r4.s64 = ctx.r10.s64 + 19528;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,-11984(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + -11984);
	// bl 0x881363e0
	ctx.lr = 0x880955CC;
	sub_881363E0(ctx, base);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x880955f0
	if (!ctx.cr6.eq) goto loc_880955F0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88095604
	if (!ctx.cr6.eq) goto loc_88095604;
	// lwz r11,-11984(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -11984);
	// addi r11,r11,1644
	ctx.r11.s64 = ctx.r11.s64 + 1644;
	// b 0x88095600
	goto loc_88095600;
loc_880955F0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88095604
	if (!ctx.cr6.eq) goto loc_88095604;
	// lwz r11,-11984(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -11984);
	// addi r11,r11,1448
	ctx.r11.s64 = ctx.r11.s64 + 1448;
loc_88095600:
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
loc_88095604:
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8809561c
	if (!ctx.cr6.eq) goto loc_8809561C;
	// li r3,256
	ctx.r3.s64 = 256;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8809561C:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r4,68(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// lwz r3,64(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// bl 0x88153070
	ctx.lr = 0x88095634;
	sub_88153070(ctx, base);
	// clrlwi r3,r3,16
	ctx.r3.u64 = ctx.r3.u32 & 0xFFFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88095640"))) PPC_WEAK_FUNC(sub_88095640);
PPC_FUNC_IMPL(__imp__sub_88095640) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88095648;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r29,r11,-11984
	ctx.r29.s64 = ctx.r11.s64 + -11984;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r30,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r30.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r30,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r30.u32);
	// stw r30,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r30.u32);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// li r8,2
	ctx.r8.s64 = 2;
	// lwz r11,-4(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -4);
	// li r7,130
	ctx.r7.s64 = 130;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lis r6,-30711
	ctx.r6.s64 = -2012676096;
	// clrlwi r4,r11,31
	ctx.r4.u64 = ctx.r11.u32 & 0x1;
	// stw r9,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r9.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r30,2312(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2312, ctx.r30.u32);
	// stw r4,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r4.u32);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// stw r30,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r30.u32);
	// addi r4,r6,19528
	ctx.r4.s64 = ctx.r6.s64 + 19528;
	// stw r3,2300(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2300, ctx.r3.u32);
	// stw r30,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r30.u32);
	// stw r30,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r30.u32);
	// stw r30,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r30.u32);
	// stw r30,2328(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2328, ctx.r30.u32);
	// stw r30,2332(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2332, ctx.r30.u32);
	// stw r30,164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 164, ctx.r30.u32);
	// stw r30,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r30.u32);
	// stw r8,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r8.u32);
	// stw r30,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r30.u32);
	// stw r30,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r30.u32);
	// stw r30,1800(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1800, ctx.r30.u32);
	// stw r30,2288(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2288, ctx.r30.u32);
	// stw r30,2296(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2296, ctx.r30.u32);
	// stw r7,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r7.u32);
	// stw r10,172(r31)
	PPC_STORE_U32(ctx.r31.u32 + 172, ctx.r10.u32);
	// stw r10,176(r31)
	PPC_STORE_U32(ctx.r31.u32 + 176, ctx.r10.u32);
	// stw r10,180(r31)
	PPC_STORE_U32(ctx.r31.u32 + 180, ctx.r10.u32);
	// stw r30,184(r31)
	PPC_STORE_U32(ctx.r31.u32 + 184, ctx.r30.u32);
	// stw r30,188(r31)
	PPC_STORE_U32(ctx.r31.u32 + 188, ctx.r30.u32);
	// stw r30,192(r31)
	PPC_STORE_U32(ctx.r31.u32 + 192, ctx.r30.u32);
	// stw r11,-4(r29)
	PPC_STORE_U32(ctx.r29.u32 + -4, ctx.r11.u32);
	// stw r30,196(r31)
	PPC_STORE_U32(ctx.r31.u32 + 196, ctx.r30.u32);
	// stw r30,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r30.u32);
	// bl 0x881363e0
	ctx.lr = 0x8809570C;
	sub_881363E0(ctx, base);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x88095730
	if (!ctx.cr6.eq) goto loc_88095730;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88095744
	if (!ctx.cr6.eq) goto loc_88095744;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// addi r11,r11,1644
	ctx.r11.s64 = ctx.r11.s64 + 1644;
	// b 0x88095740
	goto loc_88095740;
loc_88095730:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88095744
	if (!ctx.cr6.eq) goto loc_88095744;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// addi r11,r11,1448
	ctx.r11.s64 = ctx.r11.s64 + 1448;
loc_88095740:
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
loc_88095744:
	// stw r31,2324(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2324, ctx.r31.u32);
	// stw r30,2316(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2316, ctx.r30.u32);
	// stw r30,2320(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2320, ctx.r30.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88095758"))) PPC_WEAK_FUNC(sub_88095758);
PPC_FUNC_IMPL(__imp__sub_88095758) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lwz r11,-11984(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11984);
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x88095770
	if (!ctx.cr6.eq) goto loc_88095770;
	// b 0x88095178
	sub_88095178(ctx, base);
	return;
loc_88095770:
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r11,88(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// lwz r9,160(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 160);
	// mulli r11,r9,100
	ctx.r11.s64 = ctx.r9.s64 * 100;
	// blt cr6,0x8809579c
	if (ctx.cr6.lt) goto loc_8809579C;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// li r11,0
	ctx.r11.s64 = 0;
	// beq cr6,0x88095798
	if (ctx.cr6.eq) goto loc_88095798;
	// lwz r11,164(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 164);
loc_88095798:
	// mulli r11,r11,100
	ctx.r11.s64 = ctx.r11.s64 * 100;
loc_8809579C:
	// add r5,r11,r5
	ctx.r5.u64 = ctx.r11.u64 + ctx.r5.u64;
	// b 0x88095178
	sub_88095178(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880957A4"))) PPC_WEAK_FUNC(sub_880957A4);
PPC_FUNC_IMPL(__imp__sub_880957A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880957A8"))) PPC_WEAK_FUNC(sub_880957A8);
PPC_FUNC_IMPL(__imp__sub_880957A8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x880957B0;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30638
	ctx.r11.s64 = -2007891968;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r26,r8
	ctx.r26.u64 = ctx.r8.u64;
	// mr r28,r9
	ctx.r28.u64 = ctx.r9.u64;
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// addi r31,r11,-1168
	ctx.r31.s64 = ctx.r11.s64 + -1168;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne cr6,0x880957dc
	if (!ctx.cr6.eq) goto loc_880957DC;
	// li r30,3
	ctx.r30.s64 = 3;
loc_880957DC:
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// addi r9,r30,54
	ctx.r9.s64 = ctx.r30.s64 + 54;
	// li r11,0
	ctx.r11.s64 = 0;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,-11984(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11984);
	// lwzx r9,r8,r10
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
loc_880957F4:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8809581c
	if (ctx.cr6.eq) goto loc_8809581C;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r31,r31,2336
	ctx.r31.s64 = ctx.r31.s64 + 2336;
	// cmpwi cr6,r11,128
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 128, ctx.xer);
	// blt cr6,0x880957f4
	if (ctx.cr6.lt) goto loc_880957F4;
loc_88095810:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
loc_8809581C:
	// lis r11,-30683
	ctx.r11.s64 = -2010841088;
	// rlwinm r10,r29,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r11,12264
	ctx.r8.s64 = ctx.r11.s64 + 12264;
	// lwzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// stw r7,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r7.u32);
	// beq cr6,0x88095810
	if (ctx.cr6.eq) goto loc_88095810;
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x88095810
	if (ctx.cr6.eq) goto loc_88095810;
	// clrlwi r10,r11,16
	ctx.r10.u64 = ctx.r11.u32 & 0xFFFF;
	// srawi r11,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 16;
	// add r10,r10,r5
	ctx.r10.u64 = ctx.r10.u64 + ctx.r5.u64;
	// add r11,r11,r6
	ctx.r11.u64 = ctx.r11.u64 + ctx.r6.u64;
	// addi r10,r10,-40
	ctx.r10.s64 = ctx.r10.s64 + -40;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rlwinm r8,r10,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r25,r11,16,0,15
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// subf r24,r9,r8
	ctx.r24.s64 = ctx.r8.s64 - ctx.r9.s64;
	// bl 0x88095640
	ctx.lr = 0x8809586C;
	sub_88095640(ctx, base);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r30,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r30.u32);
	// addi r6,r28,4
	ctx.r6.s64 = ctx.r28.s64 + 4;
	// stw r24,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r24.u32);
	// stw r7,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r25,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r25.u32);
	// stw r6,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r6.u32);
	// stw r29,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// stw r27,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r27.u32);
	// stw r26,164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 164, ctx.r26.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880958A0"))) PPC_WEAK_FUNC(sub_880958A0);
PPC_FUNC_IMPL(__imp__sub_880958A0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x880958A8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30638
	ctx.r11.s64 = -2007891968;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// cmplwi cr6,r3,256
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 256, ctx.xer);
	// addi r31,r11,-1168
	ctx.r31.s64 = ctx.r11.s64 + -1168;
	// bge cr6,0x880958ec
	if (!ctx.cr6.lt) goto loc_880958EC;
	// li r11,0
	ctx.r11.s64 = 0;
loc_880958D0:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x880958f8
	if (ctx.cr6.eq) goto loc_880958F8;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r31,r31,2336
	ctx.r31.s64 = ctx.r31.s64 + 2336;
	// cmpwi cr6,r11,128
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 128, ctx.xer);
	// blt cr6,0x880958d0
	if (ctx.cr6.lt) goto loc_880958D0;
loc_880958EC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_880958F8:
	// lis r11,-30683
	ctx.r11.s64 = -2010841088;
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,12264
	ctx.r9.s64 = ctx.r11.s64 + 12264;
	// lwzx r8,r10,r9
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// stw r8,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r8.u32);
	// beq cr6,0x880958ec
	if (ctx.cr6.eq) goto loc_880958EC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88095640
	ctx.lr = 0x8809591C;
	sub_88095640(ctx, base);
	// stw r28,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r28.u32);
	// stw r27,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r27.u32);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// stw r30,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// beq cr6,0x88095940
	if (ctx.cr6.eq) goto loc_88095940;
	// li r5,44
	ctx.r5.s64 = 44;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r31,120
	ctx.r3.s64 = ctx.r31.s64 + 120;
	// bl 0x88072260
	ctx.lr = 0x88095940;
	sub_88072260(ctx, base);
loc_88095940:
	// lwz r3,2324(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2324);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809594C"))) PPC_WEAK_FUNC(sub_8809594C);
PPC_FUNC_IMPL(__imp__sub_8809594C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88095950"))) PPC_WEAK_FUNC(sub_88095950);
PPC_FUNC_IMPL(__imp__sub_88095950) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071144
	ctx.lr = 0x88095958;
	__savegprlr_23(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30633
	ctx.r11.s64 = -2007564288;
	// li r23,0
	ctx.r23.s64 = 0;
	// addi r29,r11,-29800
	ctx.r29.s64 = ctx.r11.s64 + -29800;
	// lis r10,-30640
	ctx.r10.s64 = -2008023040;
	// mr r31,r23
	ctx.r31.u64 = ctx.r23.u64;
	// addi r28,r10,31696
	ctx.r28.s64 = ctx.r10.s64 + 31696;
	// lwz r11,52(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 52);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x880959a0
	if (!ctx.cr6.gt) goto loc_880959A0;
	// addi r11,r28,16
	ctx.r11.s64 = ctx.r28.s64 + 16;
	// addi r30,r11,-4
	ctx.r30.s64 = ctx.r11.s64 + -4;
loc_88095988:
	// lwzu r3,4(r30)
	ea = 4 + ctx.r30.u32;
	ctx.r3.u64 = PPC_LOAD_U32(ea);
	ctx.r30.u32 = ea;
	// bl 0x88094e58
	ctx.lr = 0x88095990;
	sub_88094E58(ctx, base);
	// lwz r11,52(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 52);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmpw cr6,r31,r11
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x88095988
	if (ctx.cr6.lt) goto loc_88095988;
loc_880959A0:
	// lis r27,-30597
	ctx.r27.s64 = -2005204992;
	// stw r23,52(r29)
	PPC_STORE_U32(ctx.r29.u32 + 52, ctx.r23.u32);
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
	// lis r10,-30638
	ctx.r10.s64 = -2007891968;
	// mr r26,r23
	ctx.r26.u64 = ctx.r23.u64;
	// addi r30,r10,-1168
	ctx.r30.s64 = ctx.r10.s64 + -1168;
	// lwz r31,-11984(r27)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11984);
	// li r25,128
	ctx.r25.s64 = 128;
	// lis r24,-30643
	ctx.r24.s64 = -2008219648;
	// lwz r11,204(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 204);
	// stw r11,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
	// lwz r11,268(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 268);
	// stw r11,-40(r29)
	PPC_STORE_U32(ctx.r29.u32 + -40, ctx.r11.u32);
	// lwz r11,272(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 272);
	// stw r11,-36(r29)
	PPC_STORE_U32(ctx.r29.u32 + -36, ctx.r11.u32);
	// lwz r11,208(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 208);
	// stw r11,4(r28)
	PPC_STORE_U32(ctx.r28.u32 + 4, ctx.r11.u32);
	// lwz r11,276(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 276);
	// stw r11,-32(r29)
	PPC_STORE_U32(ctx.r29.u32 + -32, ctx.r11.u32);
	// lwz r11,280(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 280);
	// stw r11,-28(r29)
	PPC_STORE_U32(ctx.r29.u32 + -28, ctx.r11.u32);
	// lwz r11,212(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 212);
	// stw r11,8(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8, ctx.r11.u32);
	// lwz r11,284(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 284);
	// stw r11,-24(r29)
	PPC_STORE_U32(ctx.r29.u32 + -24, ctx.r11.u32);
	// lwz r11,288(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 288);
	// stw r11,-20(r29)
	PPC_STORE_U32(ctx.r29.u32 + -20, ctx.r11.u32);
	// lwz r11,216(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 216);
	// stw r11,12(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12, ctx.r11.u32);
	// li r28,1
	ctx.r28.s64 = 1;
	// lwz r11,292(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 292);
	// stw r11,-16(r29)
	PPC_STORE_U32(ctx.r29.u32 + -16, ctx.r11.u32);
	// lwz r11,296(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 296);
	// stw r11,-12(r29)
	PPC_STORE_U32(ctx.r29.u32 + -12, ctx.r11.u32);
loc_88095A28:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88095b84
	if (ctx.cr6.eq) goto loc_88095B84;
	// stw r23,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r23.u32);
	// lis r11,-30711
	ctx.r11.s64 = -2012676096;
	// stw r23,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r23.u32);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r11,19528
	ctx.r4.s64 = ctx.r11.s64 + 19528;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x881363e0
	ctx.lr = 0x88095A50;
	sub_881363E0(ctx, base);
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwz r31,-11984(r27)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11984);
	// bne cr6,0x88095a74
	if (!ctx.cr6.eq) goto loc_88095A74;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88095a84
	if (!ctx.cr6.eq) goto loc_88095A84;
	// addi r11,r31,1644
	ctx.r11.s64 = ctx.r31.s64 + 1644;
	// b 0x88095a80
	goto loc_88095A80;
loc_88095A74:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88095a84
	if (!ctx.cr6.eq) goto loc_88095A84;
	// addi r11,r31,1448
	ctx.r11.s64 = ctx.r31.s64 + 1448;
loc_88095A80:
	// stw r11,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r11.u32);
loc_88095A84:
	// lwz r11,24(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88095aa8
	if (!ctx.cr6.eq) goto loc_88095AA8;
	// lwz r11,64(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 64);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x88095AA0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r28,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r28.u32);
	// b 0x88095b54
	goto loc_88095B54;
loc_88095AA8:
	// lwz r11,26272(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 26272);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88095ac8
	if (!ctx.cr6.eq) goto loc_88095AC8;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88169750
	ctx.lr = 0x88095ABC;
	sub_88169750(ctx, base);
	// lwz r31,-11984(r27)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11984);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x88095b84
	if (ctx.cr6.eq) goto loc_88095B84;
loc_88095AC8:
	// lwz r4,2296(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2296);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x88095ae0
	if (ctx.cr6.eq) goto loc_88095AE0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096048
	ctx.lr = 0x88095ADC;
	sub_88096048(ctx, base);
	// lwz r31,-11984(r27)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11984);
loc_88095AE0:
	// lwz r11,26272(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 26272);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88095b30
	if (!ctx.cr6.eq) goto loc_88095B30;
	// lwz r11,64(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 64);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88095b08
	if (ctx.cr6.eq) goto loc_88095B08;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x88095B04;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r31,-11984(r27)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11984);
loc_88095B08:
	// lwz r11,72(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 72);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88095b30
	if (ctx.cr6.eq) goto loc_88095B30;
	// lwz r10,112(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 112);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x88095b30
	if (!ctx.cr6.eq) goto loc_88095B30;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x88095B2C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r31,-11984(r27)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11984);
loc_88095B30:
	// lwz r11,68(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 68);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88095b58
	if (ctx.cr6.eq) goto loc_88095B58;
	// lwz r10,112(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 112);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x88095b58
	if (!ctx.cr6.eq) goto loc_88095B58;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x88095B54;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_88095B54:
	// lwz r31,-11984(r27)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11984);
loc_88095B58:
	// lwz r11,1800(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 1800);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88095b6c
	if (ctx.cr6.eq) goto loc_88095B6C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88093d10
	ctx.lr = 0x88095B6C;
	sub_88093D10(ctx, base);
loc_88095B6C:
	// lwz r11,2288(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2288);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88095b80
	if (ctx.cr6.eq) goto loc_88095B80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88095d80
	ctx.lr = 0x88095B80;
	sub_88095D80(ctx, base);
loc_88095B80:
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
loc_88095B84:
	// addi r30,r30,2336
	ctx.r30.s64 = ctx.r30.s64 + 2336;
	// addic. r25,r25,-1
	ctx.xer.ca = ctx.r25.u32 > 0;
	ctx.r25.s64 = ctx.r25.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// bne 0x88095a28
	if (!ctx.cr0.eq) goto loc_88095A28;
	// lis r11,-30667
	ctx.r11.s64 = -2009792512;
	// sth r26,0(r29)
	PPC_STORE_U16(ctx.r29.u32 + 0, ctx.r26.u16);
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// lbz r10,12342(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 12342);
	// stw r26,-11948(r9)
	PPC_STORE_U32(ctx.r9.u32 + -11948, ctx.r26.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x88095bc4
	if (ctx.cr6.eq) goto loc_88095BC4;
	// stb r23,12342(r11)
	PPC_STORE_U8(ctx.r11.u32 + 12342, ctx.r23.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r9,88(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// mr r10,r23
	ctx.r10.u64 = ctx.r23.u64;
	// addi r4,r9,1
	ctx.r4.s64 = ctx.r9.s64 + 1;
	// bl 0x88136bc8
	ctx.lr = 0x88095BC4;
	sub_88136BC8(ctx, base);
loc_88095BC4:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88095BCC"))) PPC_WEAK_FUNC(sub_88095BCC);
PPC_FUNC_IMPL(__imp__sub_88095BCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88095BD0"))) PPC_WEAK_FUNC(sub_88095BD0);
PPC_FUNC_IMPL(__imp__sub_88095BD0) {
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
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lis r9,-30633
	ctx.r9.s64 = -2007564288;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// stw r4,-11984(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11984, ctx.r4.u32);
	// stw r11,-29748(r9)
	PPC_STORE_U32(ctx.r9.u32 + -29748, ctx.r11.u32);
	// bl 0x88094f38
	ctx.lr = 0x88095C00;
	sub_88094F38(ctx, base);
	// lis r8,-30651
	ctx.r8.s64 = -2008743936;
	// lwz r11,-25268(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -25268);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88095c48
	if (ctx.cr6.eq) goto loc_88095C48;
loc_88095C10:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// cmplw cr6,r10,r31
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x88095c3c
	if (ctx.cr6.eq) goto loc_88095C3C;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88095c10
	if (!ctx.cr6.eq) goto loc_88095C10;
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
loc_88095C3C:
	// lis r10,-30711
	ctx.r10.s64 = -2012676096;
	// addi r9,r10,22864
	ctx.r9.s64 = ctx.r10.s64 + 22864;
	// stw r9,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r9.u32);
loc_88095C48:
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

__attribute__((alias("__imp__sub_88095C5C"))) PPC_WEAK_FUNC(sub_88095C5C);
PPC_FUNC_IMPL(__imp__sub_88095C5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88095C60"))) PPC_WEAK_FUNC(sub_88095C60);
PPC_FUNC_IMPL(__imp__sub_88095C60) {
	PPC_FUNC_PROLOGUE();
	// li r10,10
	ctx.r10.s64 = 10;
	// addi r11,r3,1808
	ctx.r11.s64 = ctx.r3.s64 + 1808;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// li r10,0
	ctx.r10.s64 = 0;
loc_88095C70:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x88095c8c
	if (ctx.cr6.eq) goto loc_88095C8C;
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r9,r4
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r4.u32, ctx.xer);
	// bne cr6,0x88095c8c
	if (!ctx.cr6.eq) goto loc_88095C8C;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_88095C8C:
	// addi r11,r11,48
	ctx.r11.s64 = ctx.r11.s64 + 48;
	// bdnz 0x88095c70
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88095C70;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88095C98"))) PPC_WEAK_FUNC(sub_88095C98);
PPC_FUNC_IMPL(__imp__sub_88095C98) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071144
	ctx.lr = 0x88095CA0;
	__savegprlr_23(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,2288(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2288);
	// li r27,1
	ctx.r27.s64 = 1;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// mr r28,r27
	ctx.r28.u64 = ctx.r27.u64;
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// bge cr6,0x88095d68
	if (!ctx.cr6.lt) goto loc_88095D68;
	// lwz r11,2292(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2292);
	// addi r31,r3,1808
	ctx.r31.s64 = ctx.r3.s64 + 1808;
	// addic. r11,r11,1
	ctx.xer.ca = ctx.r11.u32 > 4294967294;
	ctx.r11.s64 = ctx.r11.s64 + 1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,2292(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2292, ctx.r11.u32);
	// bne 0x88095cd8
	if (!ctx.cr0.eq) goto loc_88095CD8;
	// stw r27,2292(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2292, ctx.r27.u32);
loc_88095CD8:
	// lis r26,-30671
	ctx.r26.s64 = -2010054656;
	// lis r11,16838
	ctx.r11.s64 = 1103495168;
	// mr r24,r4
	ctx.r24.u64 = ctx.r4.u64;
	// li r23,0
	ctx.r23.s64 = 0;
	// ori r25,r11,20077
	ctx.r25.u64 = ctx.r11.u64 | 20077;
	// lwz r30,4200(r26)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4200);
loc_88095CF0:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88095d58
	if (!ctx.cr6.eq) goto loc_88095D58;
	// lwz r11,2288(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 2288);
	// cmpw cr6,r23,r11
	ctx.cr6.compare<int32_t>(ctx.r23.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x88095d10
	if (ctx.cr6.lt) goto loc_88095D10;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,2288(r29)
	PPC_STORE_U32(ctx.r29.u32 + 2288, ctx.r11.u32);
loc_88095D10:
	// mullw r11,r30,r25
	ctx.r11.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r25.s32);
	// stw r27,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r27.u32);
	// stw r27,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r27.u32);
	// stw r27,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r27.u32);
	// addi r30,r11,12345
	ctx.r30.s64 = ctx.r11.s64 + 12345;
	// li r5,28
	ctx.r5.s64 = 28;
	// stw r30,4200(r26)
	PPC_STORE_U32(ctx.r26.u32 + 4200, ctx.r30.u32);
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// lhz r11,4200(r26)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r26.u32 + 4200);
	// clrlwi r11,r11,28
	ctx.r11.u64 = ctx.r11.u32 & 0xF;
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// addi r3,r31,20
	ctx.r3.s64 = ctx.r31.s64 + 20;
	// lwz r10,2292(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 2292);
	// stw r10,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r10.u32);
	// bl 0x88072260
	ctx.lr = 0x88095D4C;
	sub_88072260(ctx, base);
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq 0x88095d74
	if (ctx.cr0.eq) goto loc_88095D74;
	// addi r24,r24,28
	ctx.r24.s64 = ctx.r24.s64 + 28;
loc_88095D58:
	// addi r23,r23,1
	ctx.r23.s64 = ctx.r23.s64 + 1;
	// addi r31,r31,48
	ctx.r31.s64 = ctx.r31.s64 + 48;
	// cmpwi cr6,r23,10
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 10, ctx.xer);
	// blt cr6,0x88095cf0
	if (ctx.cr6.lt) goto loc_88095CF0;
loc_88095D68:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
loc_88095D74:
	// lwz r3,2292(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 2292);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88095D80"))) PPC_WEAK_FUNC(sub_88095D80);
PPC_FUNC_IMPL(__imp__sub_88095D80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071140
	ctx.lr = 0x88095D88;
	__savegprlr_22(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,2288(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2288);
	// li r23,0
	ctx.r23.s64 = 0;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r27,r3,1808
	ctx.r27.s64 = ctx.r3.s64 + 1808;
	// mr r28,r23
	ctx.r28.u64 = ctx.r23.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x88095ecc
	if (!ctx.cr6.gt) goto loc_88095ECC;
	// lis r24,-30597
	ctx.r24.s64 = -2005204992;
	// lis r10,531
	ctx.r10.s64 = 34799616;
	// lis r11,-30683
	ctx.r11.s64 = -2010841088;
	// addi r31,r27,24
	ctx.r31.s64 = ctx.r27.s64 + 24;
	// ori r25,r10,8192
	ctx.r25.u64 = ctx.r10.u64 | 8192;
	// lwz r26,-11932(r24)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r24.u32 + -11932);
	// addi r30,r11,13336
	ctx.r30.s64 = ctx.r11.s64 + 13336;
loc_88095DC4:
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88095eb0
	if (ctx.cr6.eq) goto loc_88095EB0;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88095df4
	if (ctx.cr6.eq) goto loc_88095DF4;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x88095eb0
	if (ctx.cr6.gt) goto loc_88095EB0;
	// stw r23,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r23.u32);
	// b 0x88095eb0
	goto loc_88095EB0;
loc_88095DF4:
	// lwz r11,-4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -4);
	// addi r10,r30,64
	ctx.r10.s64 = ctx.r30.s64 + 64;
	// lwz r9,-20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + -20);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwzx r8,r8,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// stw r11,-20(r31)
	PPC_STORE_U32(ctx.r31.u32 + -20, ctx.r11.u32);
	// bge 0x88095e34
	if (!ctx.cr0.lt) goto loc_88095E34;
	// lwz r11,-12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -12);
	// lwz r10,-16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -16);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-12(r31)
	PPC_STORE_U32(ctx.r31.u32 + -12, ctx.r11.u32);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// stw r10,-20(r31)
	PPC_STORE_U32(ctx.r31.u32 + -20, ctx.r10.u32);
	// blt cr6,0x88095e34
	if (ctx.cr6.lt) goto loc_88095E34;
	// stw r23,-12(r31)
	PPC_STORE_U32(ctx.r31.u32 + -12, ctx.r23.u32);
loc_88095E34:
	// lwz r11,2324(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 2324);
	// lwz r10,-12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -12);
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// rlwinm r5,r10,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r22,2300(r11)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2300);
	// lwz r6,20(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwzx r11,r5,r30
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r30.u32);
	// lwz r7,4(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r5,156(r22)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r22.u32 + 156);
	// add r3,r11,r8
	ctx.r3.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lwz r11,160(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 160);
	// srawi r8,r5,16
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xFFFF) != 0);
	ctx.r8.s64 = ctx.r5.s32 >> 16;
	// addze r5,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r5.s64 = temp.s64;
	// srawi r11,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 16;
	// rlwinm r8,r5,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// addze r5,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r5.s64 = temp.s64;
	// subf r11,r8,r4
	ctx.r11.s64 = ctx.r4.s64 - ctx.r8.s64;
	// rlwinm r8,r5,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// subf r11,r8,r7
	ctx.r11.s64 = ctx.r7.s64 - ctx.r8.s64;
	// add r5,r11,r9
	ctx.r5.u64 = ctx.r11.u64 + ctx.r9.u64;
	// bl 0x881538c0
	ctx.lr = 0x88095E98;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88095eb0
	if (ctx.cr6.eq) goto loc_88095EB0;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// or r10,r11,r25
	ctx.r10.u64 = ctx.r11.u64 | ctx.r25.u64;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_88095EB0:
	// lwz r11,2288(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 2288);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r27,r27,48
	ctx.r27.s64 = ctx.r27.s64 + 48;
	// addi r31,r31,48
	ctx.r31.s64 = ctx.r31.s64 + 48;
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x88095dc4
	if (ctx.cr6.lt) goto loc_88095DC4;
	// stw r26,-11932(r24)
	PPC_STORE_U32(ctx.r24.u32 + -11932, ctx.r26.u32);
loc_88095ECC:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x88071190
	__restgprlr_22(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88095ED4"))) PPC_WEAK_FUNC(sub_88095ED4);
PPC_FUNC_IMPL(__imp__sub_88095ED4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88095ED8"))) PPC_WEAK_FUNC(sub_88095ED8);
PPC_FUNC_IMPL(__imp__sub_88095ED8) {
	PPC_FUNC_PROLOGUE();
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// sth r11,5836(r10)
	PPC_STORE_U16(ctx.r10.u32 + 5836, ctx.r11.u16);
	// stw r11,8840(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8840, ctx.r11.u32);
	// stw r11,8844(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8844, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88095EF4"))) PPC_WEAK_FUNC(sub_88095EF4);
PPC_FUNC_IMPL(__imp__sub_88095EF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88095EF8"))) PPC_WEAK_FUNC(sub_88095EF8);
PPC_FUNC_IMPL(__imp__sub_88095EF8) {
	PPC_FUNC_PROLOGUE();
	// lhz r11,5836(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 5836);
	// clrlwi r10,r4,16
	ctx.r10.u64 = ctx.r4.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88095f30
	if (ctx.cr6.eq) goto loc_88095F30;
	// lwz r11,8840(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8840);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88095f30
	if (ctx.cr6.eq) goto loc_88095F30;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
loc_88095F18:
	// lhz r9,92(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 92);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x88095f38
	if (ctx.cr6.eq) goto loc_88095F38;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88095f18
	if (!ctx.cr6.eq) goto loc_88095F18;
loc_88095F30:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_88095F38:
	// li r3,1
	ctx.r3.s64 = 1;
	// sth r5,96(r11)
	PPC_STORE_U16(ctx.r11.u32 + 96, ctx.r5.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88095F44"))) PPC_WEAK_FUNC(sub_88095F44);
PPC_FUNC_IMPL(__imp__sub_88095F44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88095F48"))) PPC_WEAK_FUNC(sub_88095F48);
PPC_FUNC_IMPL(__imp__sub_88095F48) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,5724(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 5724);
	// subf r10,r11,r4
	ctx.r10.s64 = ctx.r4.s64 - ctx.r11.s64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r3,r9,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88095F5C"))) PPC_WEAK_FUNC(sub_88095F5C);
PPC_FUNC_IMPL(__imp__sub_88095F5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88095F60"))) PPC_WEAK_FUNC(sub_88095F60);
PPC_FUNC_IMPL(__imp__sub_88095F60) {
	PPC_FUNC_PROLOGUE();
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88095F6C"))) PPC_WEAK_FUNC(sub_88095F6C);
PPC_FUNC_IMPL(__imp__sub_88095F6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88095F70"))) PPC_WEAK_FUNC(sub_88095F70);
PPC_FUNC_IMPL(__imp__sub_88095F70) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x88095fac
	if (ctx.cr6.eq) goto loc_88095FAC;
	// clrlwi r10,r4,16
	ctx.r10.u64 = ctx.r4.u32 & 0xFFFF;
	// li r11,0
	ctx.r11.s64 = 0;
loc_88095F80:
	// lhz r9,6(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 6);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x88095f9c
	if (ctx.cr6.eq) goto loc_88095F9C;
	// lhz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// clrlwi r8,r10,16
	ctx.r8.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
loc_88095F9C:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r3,r3,104
	ctx.r3.s64 = ctx.r3.s64 + 104;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// blt cr6,0x88095f80
	if (ctx.cr6.lt) goto loc_88095F80;
loc_88095FAC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88095FB4"))) PPC_WEAK_FUNC(sub_88095FB4);
PPC_FUNC_IMPL(__imp__sub_88095FB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88095FB8"))) PPC_WEAK_FUNC(sub_88095FB8);
PPC_FUNC_IMPL(__imp__sub_88095FB8) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,3640
	ctx.r3.s64 = ctx.r3.s64 + 3640;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x88095ff8
	if (ctx.cr6.eq) goto loc_88095FF8;
	// clrlwi r10,r4,16
	ctx.r10.u64 = ctx.r4.u32 & 0xFFFF;
	// li r11,0
	ctx.r11.s64 = 0;
loc_88095FCC:
	// lhz r9,6(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 6);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x88095fe8
	if (ctx.cr6.eq) goto loc_88095FE8;
	// lhz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// clrlwi r8,r10,16
	ctx.r8.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
loc_88095FE8:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r3,r3,104
	ctx.r3.s64 = ctx.r3.s64 + 104;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// blt cr6,0x88095fcc
	if (ctx.cr6.lt) goto loc_88095FCC;
loc_88095FF8:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88096000"))) PPC_WEAK_FUNC(sub_88096000);
PPC_FUNC_IMPL(__imp__sub_88096000) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,520
	ctx.r3.s64 = ctx.r3.s64 + 520;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x88096040
	if (ctx.cr6.eq) goto loc_88096040;
	// clrlwi r10,r4,16
	ctx.r10.u64 = ctx.r4.u32 & 0xFFFF;
	// li r11,0
	ctx.r11.s64 = 0;
loc_88096014:
	// lhz r9,6(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 6);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x88096030
	if (ctx.cr6.eq) goto loc_88096030;
	// lhz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// clrlwi r8,r10,16
	ctx.r8.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
loc_88096030:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r3,r3,104
	ctx.r3.s64 = ctx.r3.s64 + 104;
	// cmpwi cr6,r11,30
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 30, ctx.xer);
	// blt cr6,0x88096014
	if (ctx.cr6.lt) goto loc_88096014;
loc_88096040:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88096048"))) PPC_WEAK_FUNC(sub_88096048);
PPC_FUNC_IMPL(__imp__sub_88096048) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x88096050;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x880961f8
	if (ctx.cr6.eq) goto loc_880961F8;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26272(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26272);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8809619c
	if (!ctx.cr6.eq) goto loc_8809619C;
	// lwz r11,5824(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 5824);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809608c
	if (ctx.cr6.eq) goto loc_8809608C;
	// li r5,0
	ctx.r5.s64 = 0;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8809608C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8809608C:
	// lwz r11,5724(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5724);
	// addi r5,r31,5720
	ctx.r5.s64 = ctx.r31.s64 + 5720;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880960b0
	if (ctx.cr6.eq) goto loc_880960B0;
	// addi r6,r5,16
	ctx.r6.s64 = ctx.r5.s64 + 16;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bctrl 
	ctx.lr = 0x880960B0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_880960B0:
	// addi r30,r31,12
	ctx.r30.s64 = ctx.r31.s64 + 12;
	// li r27,5
	ctx.r27.s64 = 5;
	// lis r29,-30597
	ctx.r29.s64 = -2005204992;
loc_880960BC:
	// lhz r11,-6(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + -6);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880960f0
	if (ctx.cr6.eq) goto loc_880960F0;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// addi r6,r30,4
	ctx.r6.s64 = ctx.r30.s64 + 4;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lhz r5,-8(r30)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r30.u32 + -8);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x880960E4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,-11920(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -11920);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-11920(r29)
	PPC_STORE_U32(ctx.r29.u32 + -11920, ctx.r11.u32);
loc_880960F0:
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// addi r30,r30,104
	ctx.r30.s64 = ctx.r30.s64 + 104;
	// bne 0x880960bc
	if (!ctx.cr0.eq) goto loc_880960BC;
	// addi r11,r31,520
	ctx.r11.s64 = ctx.r31.s64 + 520;
	// li r27,30
	ctx.r27.s64 = 30;
	// addi r30,r11,12
	ctx.r30.s64 = ctx.r11.s64 + 12;
	// lis r29,-30597
	ctx.r29.s64 = -2005204992;
loc_8809610C:
	// lhz r11,-6(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + -6);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88096140
	if (ctx.cr6.eq) goto loc_88096140;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// addi r6,r30,4
	ctx.r6.s64 = ctx.r30.s64 + 4;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lhz r5,-8(r30)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r30.u32 + -8);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x88096134;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,-11916(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -11916);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-11916(r29)
	PPC_STORE_U32(ctx.r29.u32 + -11916, ctx.r11.u32);
loc_88096140:
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// addi r30,r30,104
	ctx.r30.s64 = ctx.r30.s64 + 104;
	// bne 0x8809610c
	if (!ctx.cr0.eq) goto loc_8809610C;
	// addi r11,r31,3640
	ctx.r11.s64 = ctx.r31.s64 + 3640;
	// li r27,20
	ctx.r27.s64 = 20;
	// addi r30,r11,12
	ctx.r30.s64 = ctx.r11.s64 + 12;
	// lis r29,-30597
	ctx.r29.s64 = -2005204992;
loc_8809615C:
	// lhz r11,-6(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + -6);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88096190
	if (ctx.cr6.eq) goto loc_88096190;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// addi r6,r30,4
	ctx.r6.s64 = ctx.r30.s64 + 4;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lhz r5,-8(r30)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r30.u32 + -8);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x88096184;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,-11912(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -11912);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-11912(r29)
	PPC_STORE_U32(ctx.r29.u32 + -11912, ctx.r11.u32);
loc_88096190:
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// addi r30,r30,104
	ctx.r30.s64 = ctx.r30.s64 + 104;
	// bne 0x8809615c
	if (!ctx.cr0.eq) goto loc_8809615C;
loc_8809619C:
	// lhz r11,5836(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 5836);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880961f8
	if (ctx.cr6.eq) goto loc_880961F8;
	// lwz r30,8840(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8840);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x880961f8
	if (ctx.cr6.eq) goto loc_880961F8;
	// lis r29,-30597
	ctx.r29.s64 = -2005204992;
loc_880961B8:
	// lhz r11,96(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + 96);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880961ec
	if (ctx.cr6.eq) goto loc_880961EC;
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// addi r6,r30,12
	ctx.r6.s64 = ctx.r30.s64 + 12;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lhz r5,92(r30)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r30.u32 + 92);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x880961E0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,-11908(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -11908);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-11908(r29)
	PPC_STORE_U32(ctx.r29.u32 + -11908, ctx.r11.u32);
loc_880961EC:
	// lwz r30,0(r30)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x880961b8
	if (!ctx.cr6.eq) goto loc_880961B8;
loc_880961F8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88096200"))) PPC_WEAK_FUNC(sub_88096200);
PPC_FUNC_IMPL(__imp__sub_88096200) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88096208;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-30641
	ctx.r10.s64 = -2008088576;
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r31,r10,8752
	ctx.r31.s64 = ctx.r10.s64 + 8752;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_88096220:
	// lhz r10,5828(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 5828);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x88096248
	if (ctx.cr6.eq) goto loc_88096248;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r31,r31,8848
	ctx.r31.s64 = ctx.r31.s64 + 8848;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// blt cr6,0x88096220
	if (ctx.cr6.lt) goto loc_88096220;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_88096248:
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// stw r4,5824(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5824, ctx.r4.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r5,520
	ctx.r5.s64 = 520;
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r10,5828(r31)
	PPC_STORE_U16(ctx.r31.u32 + 5828, ctx.r10.u16);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,-11984(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11984);
	// stw r11,5832(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5832, ctx.r11.u32);
	// bl 0x88073bd0
	ctx.lr = 0x88096270;
	sub_88073BD0(ctx, base);
	// li r5,3120
	ctx.r5.s64 = 3120;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,520
	ctx.r3.s64 = ctx.r31.s64 + 520;
	// bl 0x88073bd0
	ctx.lr = 0x88096280;
	sub_88073BD0(ctx, base);
	// li r5,2080
	ctx.r5.s64 = 2080;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,3640
	ctx.r3.s64 = ctx.r31.s64 + 3640;
	// bl 0x88073bd0
	ctx.lr = 0x88096290;
	sub_88073BD0(ctx, base);
	// li r5,104
	ctx.r5.s64 = 104;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,5720
	ctx.r3.s64 = ctx.r31.s64 + 5720;
	// bl 0x88073bd0
	ctx.lr = 0x880962A0;
	sub_88073BD0(ctx, base);
	// li r5,3000
	ctx.r5.s64 = 3000;
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r30,5836(r31)
	PPC_STORE_U16(ctx.r31.u32 + 5836, ctx.r30.u16);
	// addi r3,r31,5840
	ctx.r3.s64 = ctx.r31.s64 + 5840;
	// bl 0x88073bd0
	ctx.lr = 0x880962B4;
	sub_88073BD0(ctx, base);
	// stw r30,8840(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8840, ctx.r30.u32);
	// stw r30,8844(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8844, ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r31,2296(r29)
	PPC_STORE_U32(ctx.r29.u32 + 2296, ctx.r31.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880962CC"))) PPC_WEAK_FUNC(sub_880962CC);
PPC_FUNC_IMPL(__imp__sub_880962CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880962D0"))) PPC_WEAK_FUNC(sub_880962D0);
PPC_FUNC_IMPL(__imp__sub_880962D0) {
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
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// addi r3,r11,8752
	ctx.r3.s64 = ctx.r11.s64 + 8752;
	// ori r5,r5,22944
	ctx.r5.u64 = ctx.r5.u64 | 22944;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x88073bd0
	ctx.lr = 0x880962F8;
	sub_88073BD0(ctx, base);
	// lis r10,-30641
	ctx.r10.s64 = -2008088576;
	// li r5,25600
	ctx.r5.s64 = 25600;
	// addi r31,r10,8352
	ctx.r31.s64 = ctx.r10.s64 + 8352;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,-25600
	ctx.r3.s64 = ctx.r31.s64 + -25600;
	// bl 0x88073bd0
	ctx.lr = 0x88096310;
	sub_88073BD0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,400
	ctx.r5.s64 = 400;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x88073bd0
	ctx.lr = 0x88096320;
	sub_88073BD0(ctx, base);
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

__attribute__((alias("__imp__sub_88096334"))) PPC_WEAK_FUNC(sub_88096334);
PPC_FUNC_IMPL(__imp__sub_88096334) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88096338"))) PPC_WEAK_FUNC(sub_88096338);
PPC_FUNC_IMPL(__imp__sub_88096338) {
	PPC_FUNC_PROLOGUE();
	// lhz r11,5830(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 5830);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r10,r11,16
	ctx.r10.u64 = ctx.r11.u32 & 0xFFFF;
	// sth r10,5830(r3)
	PPC_STORE_U16(ctx.r3.u32 + 5830, ctx.r10.u16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// clrlwi r11,r10,16
	ctx.r11.u64 = ctx.r10.u32 & 0xFFFF;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// sth r11,5830(r3)
	PPC_STORE_U16(ctx.r3.u32 + 5830, ctx.r11.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88096360"))) PPC_WEAK_FUNC(sub_88096360);
PPC_FUNC_IMPL(__imp__sub_88096360) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lhz r8,6(r3)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r3.u32 + 6);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// lhz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r9,r11,8352
	ctx.r9.s64 = ctx.r11.s64 + 8352;
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// ble cr6,0x880963a4
	if (!ctx.cr6.gt) goto loc_880963A4;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
loc_88096390:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stbu r7,1(r10)
	ea = 1 + ctx.r10.u32;
	PPC_STORE_U8(ea, ctx.r7.u8);
	ctx.r10.u32 = ea;
	// lhz r9,6(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 6);
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x88096390
	if (ctx.cr6.lt) goto loc_88096390;
loc_880963A4:
	// sth r7,6(r3)
	PPC_STORE_U16(ctx.r3.u32 + 6, ctx.r7.u16);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880963B0"))) PPC_WEAK_FUNC(sub_880963B0);
PPC_FUNC_IMPL(__imp__sub_880963B0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lhz r11,6(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 6);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88096454
	if (!ctx.cr6.eq) goto loc_88096454;
	// lis r10,-30641
	ctx.r10.s64 = -2008088576;
	// rlwinm r11,r4,26,6,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 26) & 0x3FFFFFF;
	// addi r7,r10,-17248
	ctx.r7.s64 = ctx.r10.s64 + -17248;
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// addi r8,r7,25600
	ctx.r8.s64 = ctx.r7.s64 + 25600;
	// addi r6,r7,25600
	ctx.r6.s64 = ctx.r7.s64 + 25600;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
loc_880963E0:
	// lbz r4,0(r8)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x8809643c
	if (!ctx.cr6.eq) goto loc_8809643C;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplw cr6,r11,r5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r5.u32, ctx.xer);
	// bne cr6,0x88096448
	if (!ctx.cr6.eq) goto loc_88096448;
	// rlwinm r11,r10,6,0,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// sth r10,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, ctx.r10.u16);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// sth r5,6(r3)
	PPC_STORE_U16(ctx.r3.u32 + 6, ctx.r5.u16);
	// add r9,r11,r7
	ctx.r9.u64 = ctx.r11.u64 + ctx.r7.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// ble cr6,0x88096434
	if (!ctx.cr6.gt) goto loc_88096434;
	// addi r11,r6,-1
	ctx.r11.s64 = ctx.r6.s64 + -1;
	// li r10,1
	ctx.r10.s64 = 1;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x88096434
	if (ctx.cr6.eq) goto loc_88096434;
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
loc_8809642C:
	// stbu r10,1(r11)
	ea = 1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r10.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x8809642c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8809642C;
loc_88096434:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8809643C:
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
loc_88096448:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpwi cr6,r9,400
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 400, ctx.xer);
	// blt cr6,0x880963e0
	if (ctx.cr6.lt) goto loc_880963E0;
loc_88096454:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8809645C"))) PPC_WEAK_FUNC(sub_8809645C);
PPC_FUNC_IMPL(__imp__sub_8809645C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88096460"))) PPC_WEAK_FUNC(sub_88096460);
PPC_FUNC_IMPL(__imp__sub_88096460) {
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
	// lhz r11,5836(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 5836);
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// cmplwi cr6,r11,30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 30, ctx.xer);
	// blt cr6,0x88096494
	if (ctx.cr6.lt) goto loc_88096494;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8809660c
	goto loc_8809660C;
loc_88096494:
	// mulli r11,r11,100
	ctx.r11.s64 = ctx.r11.s64 * 100;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r31,r11,5840
	ctx.r31.s64 = ctx.r11.s64 + 5840;
	// sth r9,5936(r11)
	PPC_STORE_U16(ctx.r11.u32 + 5936, ctx.r9.u16);
	// lhz r11,5830(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + 5830);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// sth r7,5830(r30)
	PPC_STORE_U16(ctx.r30.u32 + 5830, ctx.r7.u16);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x880964cc
	if (!ctx.cr6.eq) goto loc_880964CC;
	// clrlwi r11,r7,16
	ctx.r11.u64 = ctx.r7.u32 & 0xFFFF;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// sth r11,5830(r30)
	PPC_STORE_U16(ctx.r30.u32 + 5830, ctx.r11.u16);
loc_880964CC:
	// lhz r11,5836(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + 5836);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8809650c
	if (!ctx.cr6.eq) goto loc_8809650C;
	// stw r5,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r5.u32);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// sth r10,94(r31)
	PPC_STORE_U16(ctx.r31.u32 + 94, ctx.r10.u16);
	// lhz r9,5830(r30)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r30.u32 + 5830);
	// sth r9,92(r31)
	PPC_STORE_U16(ctx.r31.u32 + 92, ctx.r9.u16);
	// beq cr6,0x88096504
	if (ctx.cr6.eq) goto loc_88096504;
	// li r5,80
	ctx.r5.s64 = 80;
	// addi r3,r31,12
	ctx.r3.s64 = ctx.r31.s64 + 12;
	// bl 0x88072260
	ctx.lr = 0x88096504;
	sub_88072260(ctx, base);
loc_88096504:
	// stw r31,8840(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8840, ctx.r31.u32);
	// b 0x880965f8
	goto loc_880965F8;
loc_8809650C:
	// lwz r11,8844(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8844);
	// lhz r9,94(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 94);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x880965bc
	if (!ctx.cr6.gt) goto loc_880965BC;
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x88096544
	if (!ctx.cr6.gt) goto loc_88096544;
loc_88096528:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x88096580
	if (ctx.cr6.eq) goto loc_88096580;
	// lhz r8,94(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 94);
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// cmplw cr6,r8,r10
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x88096528
	if (ctx.cr6.gt) goto loc_88096528;
loc_88096544:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// stw r31,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r31.u32);
	// stw r31,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r31.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// sth r10,94(r31)
	PPC_STORE_U16(ctx.r31.u32 + 94, ctx.r10.u16);
	// stw r5,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r5.u32);
	// lhz r7,5830(r30)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r30.u32 + 5830);
	// sth r7,92(r31)
	PPC_STORE_U16(ctx.r31.u32 + 92, ctx.r7.u16);
	// beq cr6,0x880965fc
	if (ctx.cr6.eq) goto loc_880965FC;
	// li r5,80
	ctx.r5.s64 = 80;
	// addi r3,r31,12
	ctx.r3.s64 = ctx.r31.s64 + 12;
	// bl 0x88072260
	ctx.lr = 0x8809657C;
	sub_88072260(ctx, base);
	// b 0x880965fc
	goto loc_880965FC;
loc_88096580:
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r31,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r31.u32);
	// sth r10,94(r31)
	PPC_STORE_U16(ctx.r31.u32 + 94, ctx.r10.u16);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// stw r5,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r5.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lhz r8,5830(r30)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r30.u32 + 5830);
	// sth r8,92(r31)
	PPC_STORE_U16(ctx.r31.u32 + 92, ctx.r8.u16);
	// beq cr6,0x880965b4
	if (ctx.cr6.eq) goto loc_880965B4;
	// li r5,80
	ctx.r5.s64 = 80;
	// addi r3,r31,12
	ctx.r3.s64 = ctx.r31.s64 + 12;
	// bl 0x88072260
	ctx.lr = 0x880965B4;
	sub_88072260(ctx, base);
loc_880965B4:
	// stw r31,8840(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8840, ctx.r31.u32);
	// b 0x880965fc
	goto loc_880965FC;
loc_880965BC:
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lwz r9,8844(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8844);
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// sth r10,94(r31)
	PPC_STORE_U16(ctx.r31.u32 + 94, ctx.r10.u16);
	// stw r5,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r5.u32);
	// lhz r8,5830(r30)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r30.u32 + 5830);
	// sth r8,92(r31)
	PPC_STORE_U16(ctx.r31.u32 + 92, ctx.r8.u16);
	// beq cr6,0x880965f0
	if (ctx.cr6.eq) goto loc_880965F0;
	// li r5,80
	ctx.r5.s64 = 80;
	// addi r3,r31,12
	ctx.r3.s64 = ctx.r31.s64 + 12;
	// bl 0x88072260
	ctx.lr = 0x880965F0;
	sub_88072260(ctx, base);
loc_880965F0:
	// lwz r11,8844(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8844);
	// stw r31,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r31.u32);
loc_880965F8:
	// stw r31,8844(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8844, ctx.r31.u32);
loc_880965FC:
	// lhz r11,5836(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + 5836);
	// lhz r3,5830(r30)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r30.u32 + 5830);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// sth r11,5836(r30)
	PPC_STORE_U16(ctx.r30.u32 + 5836, ctx.r11.u16);
loc_8809660C:
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

__attribute__((alias("__imp__sub_88096624"))) PPC_WEAK_FUNC(sub_88096624);
PPC_FUNC_IMPL(__imp__sub_88096624) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88096628"))) PPC_WEAK_FUNC(sub_88096628);
PPC_FUNC_IMPL(__imp__sub_88096628) {
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
	// lwz r9,5816(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 5816);
	// addi r10,r3,5720
	ctx.r10.s64 = ctx.r3.s64 + 5720;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r3,r10,96
	ctx.r3.s64 = ctx.r10.s64 + 96;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stw r8,5724(r11)
	PPC_STORE_U32(ctx.r11.u32 + 5724, ctx.r8.u32);
	// beq cr6,0x88096658
	if (ctx.cr6.eq) goto loc_88096658;
	// bl 0x88096360
	ctx.lr = 0x88096658;
	sub_88096360(ctx, base);
loc_88096658:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8809666C"))) PPC_WEAK_FUNC(sub_8809666C);
PPC_FUNC_IMPL(__imp__sub_8809666C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88096670"))) PPC_WEAK_FUNC(sub_88096670);
PPC_FUNC_IMPL(__imp__sub_88096670) {
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
	// addi r31,r3,96
	ctx.r31.s64 = ctx.r3.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880963b0
	ctx.lr = 0x8809668C;
	sub_880963B0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
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

__attribute__((alias("__imp__sub_880966A8"))) PPC_WEAK_FUNC(sub_880966A8);
PPC_FUNC_IMPL(__imp__sub_880966A8) {
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
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// stw r3,5720(r3)
	PPC_STORE_U32(ctx.r3.u32 + 5720, ctx.r3.u32);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// addi r31,r3,5720
	ctx.r31.s64 = ctx.r3.s64 + 5720;
	// stw r11,5724(r3)
	PPC_STORE_U32(ctx.r3.u32 + 5724, ctx.r11.u32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// stw r11,5728(r3)
	PPC_STORE_U32(ctx.r3.u32 + 5728, ctx.r11.u32);
	// beq cr6,0x880966e4
	if (ctx.cr6.eq) goto loc_880966E4;
	// li r5,80
	ctx.r5.s64 = 80;
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// bl 0x88072260
	ctx.lr = 0x880966E4;
	sub_88072260(ctx, base);
loc_880966E4:
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// addi r3,r31,96
	ctx.r3.s64 = ctx.r31.s64 + 96;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880966f8
	if (ctx.cr6.eq) goto loc_880966F8;
	// bl 0x88096360
	ctx.lr = 0x880966F8;
	sub_88096360(ctx, base);
loc_880966F8:
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

__attribute__((alias("__imp__sub_88096710"))) PPC_WEAK_FUNC(sub_88096710);
PPC_FUNC_IMPL(__imp__sub_88096710) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x88096750
	if (ctx.cr6.eq) goto loc_88096750;
	// clrlwi r9,r4,16
	ctx.r9.u64 = ctx.r4.u32 & 0xFFFF;
	// li r10,0
	ctx.r10.s64 = 0;
loc_88096724:
	// lhz r8,6(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 6);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x88096740
	if (ctx.cr6.eq) goto loc_88096740;
	// lhz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4);
	// clrlwi r7,r9,16
	ctx.r7.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x88096758
	if (ctx.cr6.eq) goto loc_88096758;
loc_88096740:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,104
	ctx.r11.s64 = ctx.r11.s64 + 104;
	// cmpwi cr6,r10,5
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 5, ctx.xer);
	// blt cr6,0x88096724
	if (ctx.cr6.lt) goto loc_88096724;
loc_88096750:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_88096758:
	// lhz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r11.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88096760"))) PPC_WEAK_FUNC(sub_88096760);
PPC_FUNC_IMPL(__imp__sub_88096760) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x880967a0
	if (ctx.cr6.eq) goto loc_880967A0;
	// clrlwi r9,r4,16
	ctx.r9.u64 = ctx.r4.u32 & 0xFFFF;
	// li r10,0
	ctx.r10.s64 = 0;
loc_88096774:
	// lhz r8,6(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 6);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x88096790
	if (ctx.cr6.eq) goto loc_88096790;
	// lhz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4);
	// clrlwi r7,r9,16
	ctx.r7.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x880967a8
	if (ctx.cr6.eq) goto loc_880967A8;
loc_88096790:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,104
	ctx.r11.s64 = ctx.r11.s64 + 104;
	// cmpwi cr6,r10,5
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 5, ctx.xer);
	// blt cr6,0x88096774
	if (ctx.cr6.lt) goto loc_88096774;
loc_880967A0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_880967A8:
	// li r10,1
	ctx.r10.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// sth r10,8(r11)
	PPC_STORE_U16(ctx.r11.u32 + 8, ctx.r10.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880967B8"))) PPC_WEAK_FUNC(sub_880967B8);
PPC_FUNC_IMPL(__imp__sub_880967B8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,5
	ctx.r11.s64 = 5;
	// addi r10,r3,102
	ctx.r10.s64 = ctx.r3.s64 + 102;
	// li r7,0
	ctx.r7.s64 = 0;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// addi r6,r11,8352
	ctx.r6.s64 = ctx.r11.s64 + 8352;
loc_880967D0:
	// lhz r11,-96(r10)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + -96);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88096820
	if (ctx.cr6.eq) goto loc_88096820;
	// sth r7,-96(r10)
	PPC_STORE_U16(ctx.r10.u32 + -96, ctx.r7.u16);
	// lhz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x88096820
	if (ctx.cr6.eq) goto loc_88096820;
	// lhz r9,-2(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + -2);
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// add r9,r9,r6
	ctx.r9.u64 = ctx.r9.u64 + ctx.r6.u64;
	// ble cr6,0x88096818
	if (!ctx.cr6.gt) goto loc_88096818;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
loc_88096804:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stbu r7,1(r9)
	ea = 1 + ctx.r9.u32;
	PPC_STORE_U8(ea, ctx.r7.u8);
	ctx.r9.u32 = ea;
	// lhz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x88096804
	if (ctx.cr6.lt) goto loc_88096804;
loc_88096818:
	// sth r7,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r7.u16);
	// stw r7,-6(r10)
	PPC_STORE_U32(ctx.r10.u32 + -6, ctx.r7.u32);
loc_88096820:
	// addi r10,r10,104
	ctx.r10.s64 = ctx.r10.s64 + 104;
	// bdnz 0x880967d0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_880967D0;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88096830"))) PPC_WEAK_FUNC(sub_88096830);
PPC_FUNC_IMPL(__imp__sub_88096830) {
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
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8809687c
	if (ctx.cr6.eq) goto loc_8809687C;
	// clrlwi r9,r4,16
	ctx.r9.u64 = ctx.r4.u32 & 0xFFFF;
	// li r10,0
	ctx.r10.s64 = 0;
loc_88096850:
	// lhz r8,6(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 6);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8809686c
	if (ctx.cr6.eq) goto loc_8809686C;
	// lhz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4);
	// clrlwi r7,r9,16
	ctx.r7.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x88096890
	if (ctx.cr6.eq) goto loc_88096890;
loc_8809686C:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,104
	ctx.r11.s64 = ctx.r11.s64 + 104;
	// cmpwi cr6,r10,5
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 5, ctx.xer);
	// blt cr6,0x88096850
	if (ctx.cr6.lt) goto loc_88096850;
loc_8809687C:
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
loc_88096890:
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r3,r11,96
	ctx.r3.s64 = ctx.r11.s64 + 96;
	// sth r10,6(r11)
	PPC_STORE_U16(ctx.r11.u32 + 6, ctx.r10.u16);
	// bl 0x88096360
	ctx.lr = 0x880968A0;
	sub_88096360(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880968B4"))) PPC_WEAK_FUNC(sub_880968B4);
PPC_FUNC_IMPL(__imp__sub_880968B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880968B8"))) PPC_WEAK_FUNC(sub_880968B8);
PPC_FUNC_IMPL(__imp__sub_880968B8) {
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
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8809690c
	if (ctx.cr6.eq) goto loc_8809690C;
	// clrlwi r9,r4,16
	ctx.r9.u64 = ctx.r4.u32 & 0xFFFF;
	// li r10,0
	ctx.r10.s64 = 0;
loc_880968E0:
	// lhz r8,6(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 6);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x880968fc
	if (ctx.cr6.eq) goto loc_880968FC;
	// lhz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4);
	// clrlwi r7,r9,16
	ctx.r7.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x88096924
	if (ctx.cr6.eq) goto loc_88096924;
loc_880968FC:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,104
	ctx.r11.s64 = ctx.r11.s64 + 104;
	// cmpwi cr6,r10,5
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 5, ctx.xer);
	// blt cr6,0x880968e0
	if (ctx.cr6.lt) goto loc_880968E0;
loc_8809690C:
	// li r3,0
	ctx.r3.s64 = 0;
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
loc_88096924:
	// addi r31,r11,96
	ctx.r31.s64 = ctx.r11.s64 + 96;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880963b0
	ctx.lr = 0x88096934;
	sub_880963B0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
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

__attribute__((alias("__imp__sub_88096950"))) PPC_WEAK_FUNC(sub_88096950);
PPC_FUNC_IMPL(__imp__sub_88096950) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x88096990
	if (ctx.cr6.eq) goto loc_88096990;
	// clrlwi r9,r4,16
	ctx.r9.u64 = ctx.r4.u32 & 0xFFFF;
	// li r10,0
	ctx.r10.s64 = 0;
loc_88096964:
	// lhz r8,6(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 6);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x88096980
	if (ctx.cr6.eq) goto loc_88096980;
	// lhz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4);
	// clrlwi r7,r9,16
	ctx.r7.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x88096998
	if (ctx.cr6.eq) goto loc_88096998;
loc_88096980:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,104
	ctx.r11.s64 = ctx.r11.s64 + 104;
	// cmpwi cr6,r10,5
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 5, ctx.xer);
	// blt cr6,0x88096964
	if (ctx.cr6.lt) goto loc_88096964;
loc_88096990:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_88096998:
	// stw r5,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r5.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880969A4"))) PPC_WEAK_FUNC(sub_880969A4);
PPC_FUNC_IMPL(__imp__sub_880969A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880969A8"))) PPC_WEAK_FUNC(sub_880969A8);
PPC_FUNC_IMPL(__imp__sub_880969A8) {
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
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
loc_880969C4:
	// lhz r9,6(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 6);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x880969f8
	if (ctx.cr6.eq) goto loc_880969F8;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r31,r31,104
	ctx.r31.s64 = ctx.r31.s64 + 104;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// blt cr6,0x880969c4
	if (ctx.cr6.lt) goto loc_880969C4;
	// li r3,0
	ctx.r3.s64 = 0;
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
loc_880969F8:
	// lhz r11,5830(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 5830);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r9,r11,16
	ctx.r9.u64 = ctx.r11.u32 & 0xFFFF;
	// sth r9,5830(r3)
	PPC_STORE_U16(ctx.r3.u32 + 5830, ctx.r9.u16);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x88096a1c
	if (!ctx.cr6.eq) goto loc_88096A1C;
	// clrlwi r11,r9,16
	ctx.r11.u64 = ctx.r9.u32 & 0xFFFF;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// sth r11,5830(r3)
	PPC_STORE_U16(ctx.r3.u32 + 5830, ctx.r11.u16);
loc_88096A1C:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r3,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// lhz r9,5830(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 5830);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r4,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r4.u32);
	// sth r11,6(r31)
	PPC_STORE_U16(ctx.r31.u32 + 6, ctx.r11.u16);
	// sth r9,4(r31)
	PPC_STORE_U16(ctx.r31.u32 + 4, ctx.r9.u16);
	// beq cr6,0x88096a4c
	if (ctx.cr6.eq) goto loc_88096A4C;
	// li r5,80
	ctx.r5.s64 = 80;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// bl 0x88072260
	ctx.lr = 0x88096A4C;
	sub_88072260(ctx, base);
loc_88096A4C:
	// lhz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4);
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

__attribute__((alias("__imp__sub_88096A64"))) PPC_WEAK_FUNC(sub_88096A64);
PPC_FUNC_IMPL(__imp__sub_88096A64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88096A68"))) PPC_WEAK_FUNC(sub_88096A68);
PPC_FUNC_IMPL(__imp__sub_88096A68) {
	PPC_FUNC_PROLOGUE();
	// addi r11,r3,3640
	ctx.r11.s64 = ctx.r3.s64 + 3640;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x88096aac
	if (ctx.cr6.eq) goto loc_88096AAC;
	// clrlwi r9,r4,16
	ctx.r9.u64 = ctx.r4.u32 & 0xFFFF;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
loc_88096A80:
	// lhz r7,2(r11)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r11.u32 + 2);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x88096a9c
	if (ctx.cr6.eq) goto loc_88096A9C;
	// lhz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r11.u32 + 0);
	// clrlwi r7,r9,16
	ctx.r7.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplw cr6,r6,r7
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x88096ab4
	if (ctx.cr6.eq) goto loc_88096AB4;
loc_88096A9C:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,104
	ctx.r11.s64 = ctx.r11.s64 + 104;
	// cmpwi cr6,r10,20
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 20, ctx.xer);
	// blt cr6,0x88096a80
	if (ctx.cr6.lt) goto loc_88096A80;
loc_88096AAC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_88096AB4:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88096ABC"))) PPC_WEAK_FUNC(sub_88096ABC);
PPC_FUNC_IMPL(__imp__sub_88096ABC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88096AC0"))) PPC_WEAK_FUNC(sub_88096AC0);
PPC_FUNC_IMPL(__imp__sub_88096AC0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,20
	ctx.r11.s64 = 20;
	// addi r10,r3,3640
	ctx.r10.s64 = ctx.r3.s64 + 3640;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r10,r10,102
	ctx.r10.s64 = ctx.r10.s64 + 102;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// addi r6,r11,8352
	ctx.r6.s64 = ctx.r11.s64 + 8352;
loc_88096ADC:
	// lhz r11,-96(r10)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + -96);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88096b2c
	if (ctx.cr6.eq) goto loc_88096B2C;
	// sth r7,-96(r10)
	PPC_STORE_U16(ctx.r10.u32 + -96, ctx.r7.u16);
	// lhz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x88096b2c
	if (ctx.cr6.eq) goto loc_88096B2C;
	// lhz r9,-2(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + -2);
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// add r9,r9,r6
	ctx.r9.u64 = ctx.r9.u64 + ctx.r6.u64;
	// ble cr6,0x88096b24
	if (!ctx.cr6.gt) goto loc_88096B24;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
loc_88096B10:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stbu r7,1(r9)
	ea = 1 + ctx.r9.u32;
	PPC_STORE_U8(ea, ctx.r7.u8);
	ctx.r9.u32 = ea;
	// lhz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x88096b10
	if (ctx.cr6.lt) goto loc_88096B10;
loc_88096B24:
	// sth r7,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r7.u16);
	// stw r7,-6(r10)
	PPC_STORE_U32(ctx.r10.u32 + -6, ctx.r7.u32);
loc_88096B2C:
	// addi r10,r10,104
	ctx.r10.s64 = ctx.r10.s64 + 104;
	// bdnz 0x88096adc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88096ADC;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88096B3C"))) PPC_WEAK_FUNC(sub_88096B3C);
PPC_FUNC_IMPL(__imp__sub_88096B3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88096B40"))) PPC_WEAK_FUNC(sub_88096B40);
PPC_FUNC_IMPL(__imp__sub_88096B40) {
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
	// addi r11,r3,3640
	ctx.r11.s64 = ctx.r3.s64 + 3640;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x88096b8c
	if (ctx.cr6.eq) goto loc_88096B8C;
	// clrlwi r9,r4,16
	ctx.r9.u64 = ctx.r4.u32 & 0xFFFF;
	// li r10,0
	ctx.r10.s64 = 0;
loc_88096B60:
	// lhz r8,6(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 6);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x88096b7c
	if (ctx.cr6.eq) goto loc_88096B7C;
	// lhz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4);
	// clrlwi r7,r9,16
	ctx.r7.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x88096ba0
	if (ctx.cr6.eq) goto loc_88096BA0;
loc_88096B7C:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,104
	ctx.r11.s64 = ctx.r11.s64 + 104;
	// cmpwi cr6,r10,20
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 20, ctx.xer);
	// blt cr6,0x88096b60
	if (ctx.cr6.lt) goto loc_88096B60;
loc_88096B8C:
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
loc_88096BA0:
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r3,r11,96
	ctx.r3.s64 = ctx.r11.s64 + 96;
	// sth r10,6(r11)
	PPC_STORE_U16(ctx.r11.u32 + 6, ctx.r10.u16);
	// bl 0x88096360
	ctx.lr = 0x88096BB0;
	sub_88096360(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88096BC4"))) PPC_WEAK_FUNC(sub_88096BC4);
PPC_FUNC_IMPL(__imp__sub_88096BC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88096BC8"))) PPC_WEAK_FUNC(sub_88096BC8);
PPC_FUNC_IMPL(__imp__sub_88096BC8) {
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
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// addi r11,r3,3640
	ctx.r11.s64 = ctx.r3.s64 + 3640;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x88096c1c
	if (ctx.cr6.eq) goto loc_88096C1C;
	// clrlwi r9,r4,16
	ctx.r9.u64 = ctx.r4.u32 & 0xFFFF;
	// li r10,0
	ctx.r10.s64 = 0;
loc_88096BF0:
	// lhz r8,6(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 6);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x88096c0c
	if (ctx.cr6.eq) goto loc_88096C0C;
	// lhz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4);
	// clrlwi r7,r9,16
	ctx.r7.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x88096c34
	if (ctx.cr6.eq) goto loc_88096C34;
loc_88096C0C:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,104
	ctx.r11.s64 = ctx.r11.s64 + 104;
	// cmpwi cr6,r10,20
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 20, ctx.xer);
	// blt cr6,0x88096bf0
	if (ctx.cr6.lt) goto loc_88096BF0;
loc_88096C1C:
	// li r3,0
	ctx.r3.s64 = 0;
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
loc_88096C34:
	// addi r31,r11,96
	ctx.r31.s64 = ctx.r11.s64 + 96;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880963b0
	ctx.lr = 0x88096C44;
	sub_880963B0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
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

__attribute__((alias("__imp__sub_88096C60"))) PPC_WEAK_FUNC(sub_88096C60);
PPC_FUNC_IMPL(__imp__sub_88096C60) {
	PPC_FUNC_PROLOGUE();
	// addi r11,r3,3640
	ctx.r11.s64 = ctx.r3.s64 + 3640;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x88096ca0
	if (ctx.cr6.eq) goto loc_88096CA0;
	// clrlwi r9,r4,16
	ctx.r9.u64 = ctx.r4.u32 & 0xFFFF;
	// li r10,0
	ctx.r10.s64 = 0;
loc_88096C74:
	// lhz r8,6(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 6);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x88096c90
	if (ctx.cr6.eq) goto loc_88096C90;
	// lhz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4);
	// clrlwi r7,r9,16
	ctx.r7.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x88096ca8
	if (ctx.cr6.eq) goto loc_88096CA8;
loc_88096C90:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,104
	ctx.r11.s64 = ctx.r11.s64 + 104;
	// cmpwi cr6,r10,20
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 20, ctx.xer);
	// blt cr6,0x88096c74
	if (ctx.cr6.lt) goto loc_88096C74;
loc_88096CA0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_88096CA8:
	// stw r5,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r5.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88096CB4"))) PPC_WEAK_FUNC(sub_88096CB4);
PPC_FUNC_IMPL(__imp__sub_88096CB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88096CB8"))) PPC_WEAK_FUNC(sub_88096CB8);
PPC_FUNC_IMPL(__imp__sub_88096CB8) {
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
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// addi r31,r3,3640
	ctx.r31.s64 = ctx.r3.s64 + 3640;
	// li r11,0
	ctx.r11.s64 = 0;
loc_88096CD4:
	// lhz r9,6(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 6);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x88096d08
	if (ctx.cr6.eq) goto loc_88096D08;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r31,r31,104
	ctx.r31.s64 = ctx.r31.s64 + 104;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// blt cr6,0x88096cd4
	if (ctx.cr6.lt) goto loc_88096CD4;
	// li r3,0
	ctx.r3.s64 = 0;
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
loc_88096D08:
	// lhz r11,5830(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 5830);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r9,r11,16
	ctx.r9.u64 = ctx.r11.u32 & 0xFFFF;
	// sth r9,5830(r3)
	PPC_STORE_U16(ctx.r3.u32 + 5830, ctx.r9.u16);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x88096d2c
	if (!ctx.cr6.eq) goto loc_88096D2C;
	// clrlwi r11,r9,16
	ctx.r11.u64 = ctx.r9.u32 & 0xFFFF;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// sth r11,5830(r3)
	PPC_STORE_U16(ctx.r3.u32 + 5830, ctx.r11.u16);
loc_88096D2C:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r3,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// lhz r8,5830(r3)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r3.u32 + 5830);
	// stw r4,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r4.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// sth r11,6(r31)
	PPC_STORE_U16(ctx.r31.u32 + 6, ctx.r11.u16);
	// sth r9,8(r31)
	PPC_STORE_U16(ctx.r31.u32 + 8, ctx.r9.u16);
	// sth r8,4(r31)
	PPC_STORE_U16(ctx.r31.u32 + 4, ctx.r8.u16);
	// beq cr6,0x88096d64
	if (ctx.cr6.eq) goto loc_88096D64;
	// li r5,80
	ctx.r5.s64 = 80;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// bl 0x88072260
	ctx.lr = 0x88096D64;
	sub_88072260(ctx, base);
loc_88096D64:
	// lhz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4);
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

__attribute__((alias("__imp__sub_88096D7C"))) PPC_WEAK_FUNC(sub_88096D7C);
PPC_FUNC_IMPL(__imp__sub_88096D7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88096D80"))) PPC_WEAK_FUNC(sub_88096D80);
PPC_FUNC_IMPL(__imp__sub_88096D80) {
	PPC_FUNC_PROLOGUE();
	// addi r11,r3,520
	ctx.r11.s64 = ctx.r3.s64 + 520;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x88096dc0
	if (ctx.cr6.eq) goto loc_88096DC0;
	// clrlwi r9,r4,16
	ctx.r9.u64 = ctx.r4.u32 & 0xFFFF;
	// li r10,0
	ctx.r10.s64 = 0;
loc_88096D94:
	// lhz r8,6(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 6);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x88096db0
	if (ctx.cr6.eq) goto loc_88096DB0;
	// lhz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4);
	// clrlwi r7,r9,16
	ctx.r7.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x88096dc8
	if (ctx.cr6.eq) goto loc_88096DC8;
loc_88096DB0:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,104
	ctx.r11.s64 = ctx.r11.s64 + 104;
	// cmpwi cr6,r10,30
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 30, ctx.xer);
	// blt cr6,0x88096d94
	if (ctx.cr6.lt) goto loc_88096D94;
loc_88096DC0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_88096DC8:
	// lhz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r11.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88096DD0"))) PPC_WEAK_FUNC(sub_88096DD0);
PPC_FUNC_IMPL(__imp__sub_88096DD0) {
	PPC_FUNC_PROLOGUE();
	// addi r11,r3,520
	ctx.r11.s64 = ctx.r3.s64 + 520;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x88096e10
	if (ctx.cr6.eq) goto loc_88096E10;
	// clrlwi r9,r4,16
	ctx.r9.u64 = ctx.r4.u32 & 0xFFFF;
	// li r10,0
	ctx.r10.s64 = 0;
loc_88096DE4:
	// lhz r8,6(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 6);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x88096e00
	if (ctx.cr6.eq) goto loc_88096E00;
	// lhz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4);
	// clrlwi r7,r9,16
	ctx.r7.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x88096e18
	if (ctx.cr6.eq) goto loc_88096E18;
loc_88096E00:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,104
	ctx.r11.s64 = ctx.r11.s64 + 104;
	// cmpwi cr6,r10,30
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 30, ctx.xer);
	// blt cr6,0x88096de4
	if (ctx.cr6.lt) goto loc_88096DE4;
loc_88096E10:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_88096E18:
	// li r10,1
	ctx.r10.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// sth r10,8(r11)
	PPC_STORE_U16(ctx.r11.u32 + 8, ctx.r10.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88096E28"))) PPC_WEAK_FUNC(sub_88096E28);
PPC_FUNC_IMPL(__imp__sub_88096E28) {
	PPC_FUNC_PROLOGUE();
	// addi r11,r3,520
	ctx.r11.s64 = ctx.r3.s64 + 520;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x88096e6c
	if (ctx.cr6.eq) goto loc_88096E6C;
	// clrlwi r9,r4,16
	ctx.r9.u64 = ctx.r4.u32 & 0xFFFF;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
loc_88096E40:
	// lhz r7,2(r11)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r11.u32 + 2);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x88096e5c
	if (ctx.cr6.eq) goto loc_88096E5C;
	// lhz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r11.u32 + 0);
	// clrlwi r7,r9,16
	ctx.r7.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplw cr6,r6,r7
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x88096e74
	if (ctx.cr6.eq) goto loc_88096E74;
loc_88096E5C:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,104
	ctx.r11.s64 = ctx.r11.s64 + 104;
	// cmpwi cr6,r10,30
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 30, ctx.xer);
	// blt cr6,0x88096e40
	if (ctx.cr6.lt) goto loc_88096E40;
loc_88096E6C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_88096E74:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88096E7C"))) PPC_WEAK_FUNC(sub_88096E7C);
PPC_FUNC_IMPL(__imp__sub_88096E7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88096E80"))) PPC_WEAK_FUNC(sub_88096E80);
PPC_FUNC_IMPL(__imp__sub_88096E80) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,30
	ctx.r11.s64 = 30;
	// addi r10,r3,520
	ctx.r10.s64 = ctx.r3.s64 + 520;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r10,r10,102
	ctx.r10.s64 = ctx.r10.s64 + 102;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// addi r6,r11,8352
	ctx.r6.s64 = ctx.r11.s64 + 8352;
loc_88096E9C:
	// lhz r11,-96(r10)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + -96);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88096eec
	if (ctx.cr6.eq) goto loc_88096EEC;
	// lhz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x88096ee8
	if (ctx.cr6.eq) goto loc_88096EE8;
	// lhz r9,-2(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + -2);
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// add r9,r9,r6
	ctx.r9.u64 = ctx.r9.u64 + ctx.r6.u64;
	// ble cr6,0x88096ee0
	if (!ctx.cr6.gt) goto loc_88096EE0;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
loc_88096ECC:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stbu r7,1(r9)
	ea = 1 + ctx.r9.u32;
	PPC_STORE_U8(ea, ctx.r7.u8);
	ctx.r9.u32 = ea;
	// lhz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x88096ecc
	if (ctx.cr6.lt) goto loc_88096ECC;
loc_88096EE0:
	// sth r7,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r7.u16);
	// stw r7,-6(r10)
	PPC_STORE_U32(ctx.r10.u32 + -6, ctx.r7.u32);
loc_88096EE8:
	// sth r7,-96(r10)
	PPC_STORE_U16(ctx.r10.u32 + -96, ctx.r7.u16);
loc_88096EEC:
	// addi r10,r10,104
	ctx.r10.s64 = ctx.r10.s64 + 104;
	// bdnz 0x88096e9c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88096E9C;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88096EFC"))) PPC_WEAK_FUNC(sub_88096EFC);
PPC_FUNC_IMPL(__imp__sub_88096EFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88096F00"))) PPC_WEAK_FUNC(sub_88096F00);
PPC_FUNC_IMPL(__imp__sub_88096F00) {
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
	// addi r6,r3,520
	ctx.r6.s64 = ctx.r3.s64 + 520;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x88096f4c
	if (ctx.cr6.eq) goto loc_88096F4C;
	// clrlwi r10,r4,16
	ctx.r10.u64 = ctx.r4.u32 & 0xFFFF;
	// li r11,0
	ctx.r11.s64 = 0;
loc_88096F20:
	// lhz r9,6(r6)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r6.u32 + 6);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x88096f3c
	if (ctx.cr6.eq) goto loc_88096F3C;
	// lhz r9,4(r6)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r6.u32 + 4);
	// clrlwi r8,r10,16
	ctx.r8.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x88096f60
	if (ctx.cr6.eq) goto loc_88096F60;
loc_88096F3C:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r6,r6,104
	ctx.r6.s64 = ctx.r6.s64 + 104;
	// cmpwi cr6,r11,30
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 30, ctx.xer);
	// blt cr6,0x88096f20
	if (ctx.cr6.lt) goto loc_88096F20;
loc_88096F4C:
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
loc_88096F60:
	// addi r3,r6,96
	ctx.r3.s64 = ctx.r6.s64 + 96;
	// bl 0x88096360
	ctx.lr = 0x88096F68;
	sub_88096360(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// sth r11,6(r6)
	PPC_STORE_U16(ctx.r6.u32 + 6, ctx.r11.u16);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88096F84"))) PPC_WEAK_FUNC(sub_88096F84);
PPC_FUNC_IMPL(__imp__sub_88096F84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88096F88"))) PPC_WEAK_FUNC(sub_88096F88);
PPC_FUNC_IMPL(__imp__sub_88096F88) {
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
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// addi r11,r3,520
	ctx.r11.s64 = ctx.r3.s64 + 520;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x88096fdc
	if (ctx.cr6.eq) goto loc_88096FDC;
	// clrlwi r9,r4,16
	ctx.r9.u64 = ctx.r4.u32 & 0xFFFF;
	// li r10,0
	ctx.r10.s64 = 0;
loc_88096FB0:
	// lhz r8,6(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 6);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x88096fcc
	if (ctx.cr6.eq) goto loc_88096FCC;
	// lhz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4);
	// clrlwi r7,r9,16
	ctx.r7.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x88096ff4
	if (ctx.cr6.eq) goto loc_88096FF4;
loc_88096FCC:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,104
	ctx.r11.s64 = ctx.r11.s64 + 104;
	// cmpwi cr6,r10,30
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 30, ctx.xer);
	// blt cr6,0x88096fb0
	if (ctx.cr6.lt) goto loc_88096FB0;
loc_88096FDC:
	// li r3,0
	ctx.r3.s64 = 0;
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
loc_88096FF4:
	// addi r31,r11,96
	ctx.r31.s64 = ctx.r11.s64 + 96;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880963b0
	ctx.lr = 0x88097004;
	sub_880963B0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
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

__attribute__((alias("__imp__sub_88097020"))) PPC_WEAK_FUNC(sub_88097020);
PPC_FUNC_IMPL(__imp__sub_88097020) {
	PPC_FUNC_PROLOGUE();
	// addi r11,r3,520
	ctx.r11.s64 = ctx.r3.s64 + 520;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x88097060
	if (ctx.cr6.eq) goto loc_88097060;
	// clrlwi r9,r4,16
	ctx.r9.u64 = ctx.r4.u32 & 0xFFFF;
	// li r10,0
	ctx.r10.s64 = 0;
loc_88097034:
	// lhz r8,6(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 6);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x88097050
	if (ctx.cr6.eq) goto loc_88097050;
	// lhz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4);
	// clrlwi r7,r9,16
	ctx.r7.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x88097068
	if (ctx.cr6.eq) goto loc_88097068;
loc_88097050:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,104
	ctx.r11.s64 = ctx.r11.s64 + 104;
	// cmpwi cr6,r10,30
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 30, ctx.xer);
	// blt cr6,0x88097034
	if (ctx.cr6.lt) goto loc_88097034;
loc_88097060:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_88097068:
	// stw r5,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r5.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88097074"))) PPC_WEAK_FUNC(sub_88097074);
PPC_FUNC_IMPL(__imp__sub_88097074) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88097078"))) PPC_WEAK_FUNC(sub_88097078);
PPC_FUNC_IMPL(__imp__sub_88097078) {
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
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// addi r31,r3,520
	ctx.r31.s64 = ctx.r3.s64 + 520;
	// li r11,0
	ctx.r11.s64 = 0;
loc_88097094:
	// lhz r9,6(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 6);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x880970c8
	if (ctx.cr6.eq) goto loc_880970C8;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r31,r31,104
	ctx.r31.s64 = ctx.r31.s64 + 104;
	// cmpwi cr6,r11,30
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 30, ctx.xer);
	// blt cr6,0x88097094
	if (ctx.cr6.lt) goto loc_88097094;
	// li r3,0
	ctx.r3.s64 = 0;
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
loc_880970C8:
	// lhz r11,5830(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 5830);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r9,r11,16
	ctx.r9.u64 = ctx.r11.u32 & 0xFFFF;
	// sth r9,5830(r3)
	PPC_STORE_U16(ctx.r3.u32 + 5830, ctx.r9.u16);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x880970ec
	if (!ctx.cr6.eq) goto loc_880970EC;
	// clrlwi r11,r9,16
	ctx.r11.u64 = ctx.r9.u32 & 0xFFFF;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// sth r11,5830(r3)
	PPC_STORE_U16(ctx.r3.u32 + 5830, ctx.r11.u16);
loc_880970EC:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r3,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// lhz r8,5830(r3)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r3.u32 + 5830);
	// stw r4,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r4.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// sth r11,6(r31)
	PPC_STORE_U16(ctx.r31.u32 + 6, ctx.r11.u16);
	// sth r9,8(r31)
	PPC_STORE_U16(ctx.r31.u32 + 8, ctx.r9.u16);
	// sth r8,4(r31)
	PPC_STORE_U16(ctx.r31.u32 + 4, ctx.r8.u16);
	// beq cr6,0x88097124
	if (ctx.cr6.eq) goto loc_88097124;
	// li r5,80
	ctx.r5.s64 = 80;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// bl 0x88072260
	ctx.lr = 0x88097124;
	sub_88072260(ctx, base);
loc_88097124:
	// lhz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4);
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

__attribute__((alias("__imp__sub_8809713C"))) PPC_WEAK_FUNC(sub_8809713C);
PPC_FUNC_IMPL(__imp__sub_8809713C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88097140"))) PPC_WEAK_FUNC(sub_88097140);
PPC_FUNC_IMPL(__imp__sub_88097140) {
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
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// bl 0x88096e80
	ctx.lr = 0x88097154;
	sub_88096E80(ctx, base);
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x88096ac0
	ctx.lr = 0x8809715C;
	sub_88096AC0(ctx, base);
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x880967b8
	ctx.lr = 0x88097164;
	sub_880967B8(ctx, base);
	// addi r11,r5,5720
	ctx.r11.s64 = ctx.r5.s64 + 5720;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,96
	ctx.r3.s64 = ctx.r11.s64 + 96;
	// stw r6,5724(r5)
	PPC_STORE_U32(ctx.r5.u32 + 5724, ctx.r6.u32);
	// lwz r11,5816(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 5816);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88097184
	if (ctx.cr6.eq) goto loc_88097184;
	// bl 0x88096360
	ctx.lr = 0x88097184;
	sub_88096360(ctx, base);
loc_88097184:
	// sth r6,5836(r5)
	PPC_STORE_U16(ctx.r5.u32 + 5836, ctx.r6.u16);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r6,8840(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8840, ctx.r6.u32);
	// stw r6,8844(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8844, ctx.r6.u32);
	// sth r6,5828(r5)
	PPC_STORE_U16(ctx.r5.u32 + 5828, ctx.r6.u16);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880971A8"))) PPC_WEAK_FUNC(sub_880971A8);
PPC_FUNC_IMPL(__imp__sub_880971A8) {
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
	// lis r10,-30642
	ctx.r10.s64 = -2008154112;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r30,r10,-31128
	ctx.r30.s64 = ctx.r10.s64 + -31128;
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,-1496(r30)
	PPC_STORE_U32(ctx.r30.u32 + -1496, ctx.r11.u32);
	// lwz r31,-11984(r9)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + -11984);
	// bl 0x88093880
	ctx.lr = 0x880971DC;
	sub_88093880(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,-7848(r30)
	PPC_STORE_U32(ctx.r30.u32 + -7848, ctx.r11.u32);
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// stw r9,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r9.u32);
	// lwz r11,3956(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 3956);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// beq cr6,0x88097218
	if (ctx.cr6.eq) goto loc_88097218;
loc_88097200:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x88097210
	if (ctx.cr6.eq) goto loc_88097210;
	// stw r9,136(r10)
	PPC_STORE_U32(ctx.r10.u32 + 136, ctx.r9.u32);
loc_88097210:
	// addi r10,r10,152
	ctx.r10.s64 = ctx.r10.s64 + 152;
	// bdnz 0x88097200
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88097200;
loc_88097218:
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

__attribute__((alias("__imp__sub_88097234"))) PPC_WEAK_FUNC(sub_88097234);
PPC_FUNC_IMPL(__imp__sub_88097234) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88097238"))) PPC_WEAK_FUNC(sub_88097238);
PPC_FUNC_IMPL(__imp__sub_88097238) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,5728(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 5728);
	// addi r11,r3,5720
	ctx.r11.s64 = ctx.r3.s64 + 5720;
	// cmpw cr6,r10,r4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r4.s32, ctx.xer);
	// bne cr6,0x88097250
	if (!ctx.cr6.eq) goto loc_88097250;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// blr 
	return;
loc_88097250:
	// b 0x880966a8
	sub_880966A8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88097254"))) PPC_WEAK_FUNC(sub_88097254);
PPC_FUNC_IMPL(__imp__sub_88097254) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88097258"))) PPC_WEAK_FUNC(sub_88097258);
PPC_FUNC_IMPL(__imp__sub_88097258) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// addi r10,r11,-17320
	ctx.r10.s64 = ctx.r11.s64 + -17320;
	// stw r3,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r3.u32);
	// stw r4,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8809726C"))) PPC_WEAK_FUNC(sub_8809726C);
PPC_FUNC_IMPL(__imp__sub_8809726C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88097270"))) PPC_WEAK_FUNC(sub_88097270);
PPC_FUNC_IMPL(__imp__sub_88097270) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// addi r8,r11,-17320
	ctx.r8.s64 = ctx.r11.s64 + -17320;
	// lis r7,-30683
	ctx.r7.s64 = -2010841088;
	// lbz r11,16(r8)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r8.u32 + 16);
	// lwz r10,12(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// oris r10,r10,32768
	ctx.r10.u64 = ctx.r10.u64 | 2147483648;
	// stw r11,-11012(r9)
	PPC_STORE_U32(ctx.r9.u32 + -11012, ctx.r11.u32);
	// stw r10,11776(r7)
	PPC_STORE_U32(ctx.r7.u32 + 11776, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88097298"))) PPC_WEAK_FUNC(sub_88097298);
PPC_FUNC_IMPL(__imp__sub_88097298) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x880972A0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-30597
	ctx.r30.s64 = -2005204992;
	// lis r29,-30683
	ctx.r29.s64 = -2010841088;
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r31,r11,-17320
	ctx.r31.s64 = ctx.r11.s64 + -17320;
	// lwz r11,-11012(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -11012);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r10,11776(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 11776);
	// stw r9,-11012(r30)
	PPC_STORE_U32(ctx.r30.u32 + -11012, ctx.r9.u32);
	// clrlwi r10,r10,1
	ctx.r10.u64 = ctx.r10.u32 & 0x7FFFFFFF;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// stb r11,16(r31)
	PPC_STORE_U8(ctx.r31.u32 + 16, ctx.r11.u8);
	// stw r10,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r10.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x880972E4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88097350
	if (!ctx.cr6.eq) goto loc_88097350;
	// lis r6,-30651
	ctx.r6.s64 = -2008743936;
	// lbz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 16);
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r5,-30711
	ctx.r5.s64 = -2012676096;
	// addi r11,r6,-24460
	ctx.r11.s64 = ctx.r6.s64 + -24460;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r7,r11,4
	ctx.r7.s64 = ctx.r11.s64 + 4;
	// lwz r11,-24460(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -24460);
	// addi r3,r5,29296
	ctx.r3.s64 = ctx.r5.s64 + 29296;
	// stw r10,-11012(r30)
	PPC_STORE_U32(ctx.r30.u32 + -11012, ctx.r10.u32);
	// oris r10,r9,32768
	ctx.r10.u64 = ctx.r9.u64 | 2147483648;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r10,11776(r29)
	PPC_STORE_U32(ctx.r29.u32 + 11776, ctx.r10.u32);
	// add r9,r11,r8
	ctx.r9.u64 = ctx.r11.u64 + ctx.r8.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,-24460(r6)
	PPC_STORE_U32(ctx.r6.u32 + -24460, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// add r11,r8,r7
	ctx.r11.u64 = ctx.r8.u64 + ctx.r7.u64;
	// stwx r4,r8,r7
	PPC_STORE_U32(ctx.r8.u32 + ctx.r7.u32, ctx.r4.u32);
	// stw r28,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r28.u32);
	// stw r6,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r6.u32);
	// stw r3,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r3.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_88097350:
	// lbz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 16);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// oris r10,r10,32768
	ctx.r10.u64 = ctx.r10.u64 | 2147483648;
	// stw r11,-11012(r30)
	PPC_STORE_U32(ctx.r30.u32 + -11012, ctx.r11.u32);
	// stw r10,11776(r29)
	PPC_STORE_U32(ctx.r29.u32 + 11776, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809736C"))) PPC_WEAK_FUNC(sub_8809736C);
PPC_FUNC_IMPL(__imp__sub_8809736C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88097370"))) PPC_WEAK_FUNC(sub_88097370);
PPC_FUNC_IMPL(__imp__sub_88097370) {
	PPC_FUNC_PROLOGUE();
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lis r5,-30597
	ctx.r5.s64 = -2005204992;
	// lis r4,-30651
	ctx.r4.s64 = -2008743936;
	// addi r6,r5,-11052
	ctx.r6.s64 = ctx.r5.s64 + -11052;
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r7,-30711
	ctx.r7.s64 = -2012676096;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r11,-25268(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + -25268);
	// lis r31,-30641
	ctx.r31.s64 = -2008088576;
	// stw r10,-12(r6)
	PPC_STORE_U32(ctx.r6.u32 + -12, ctx.r10.u32);
	// addi r10,r7,8608
	ctx.r10.s64 = ctx.r7.s64 + 8608;
	// stw r9,-8(r6)
	PPC_STORE_U32(ctx.r6.u32 + -8, ctx.r9.u32);
	// stw r8,-4(r6)
	PPC_STORE_U32(ctx.r6.u32 + -4, ctx.r8.u32);
	// addi r4,r31,-17320
	ctx.r4.s64 = ctx.r31.s64 + -17320;
	// lis r6,-30685
	ctx.r6.s64 = -2010972160;
	// stw r10,-11052(r5)
	PPC_STORE_U32(ctx.r5.u32 + -11052, ctx.r10.u32);
	// lis r7,-30683
	ctx.r7.s64 = -2010841088;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r8,r6,-15816
	ctx.r8.s64 = ctx.r6.s64 + -15816;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r8,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r8.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r9,11800(r7)
	PPC_STORE_U32(ctx.r7.u32 + 11800, ctx.r9.u32);
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// beq cr6,0x880973f0
	if (ctx.cr6.eq) goto loc_880973F0;
loc_880973D8:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// cmplw cr6,r10,r3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r3.u32, ctx.xer);
	// beq cr6,0x88097410
	if (ctx.cr6.eq) goto loc_88097410;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880973d8
	if (!ctx.cr6.eq) goto loc_880973D8;
loc_880973F0:
	// lis r8,-30641
	ctx.r8.s64 = -2008088576;
	// lis r9,-30641
	ctx.r9.s64 = -2008088576;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r10,-17328(r8)
	PPC_STORE_U32(ctx.r8.u32 + -17328, ctx.r10.u32);
	// stw r11,-17324(r9)
	PPC_STORE_U32(ctx.r9.u32 + -17324, ctx.r11.u32);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_88097410:
	// lis r9,-30711
	ctx.r9.s64 = -2012676096;
	// lis r8,-30641
	ctx.r8.s64 = -2008088576;
	// lis r7,-30641
	ctx.r7.s64 = -2008088576;
	// addi r6,r9,29336
	ctx.r6.s64 = ctx.r9.s64 + 29336;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r6,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r6.u32);
	// stw r10,-17324(r8)
	PPC_STORE_U32(ctx.r8.u32 + -17324, ctx.r10.u32);
	// stw r9,-17328(r7)
	PPC_STORE_U32(ctx.r7.u32 + -17328, ctx.r9.u32);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8809743C"))) PPC_WEAK_FUNC(sub_8809743C);
PPC_FUNC_IMPL(__imp__sub_8809743C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88097440"))) PPC_WEAK_FUNC(sub_88097440);
PPC_FUNC_IMPL(__imp__sub_88097440) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88097444"))) PPC_WEAK_FUNC(sub_88097444);
PPC_FUNC_IMPL(__imp__sub_88097444) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88097448"))) PPC_WEAK_FUNC(sub_88097448);
PPC_FUNC_IMPL(__imp__sub_88097448) {
	PPC_FUNC_PROLOGUE();
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lis r11,-30642
	ctx.r11.s64 = -2008154112;
	// li r8,46
	ctx.r8.s64 = 46;
	// addi r7,r11,31504
	ctx.r7.s64 = ctx.r11.s64 + 31504;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r11,r7,15304
	ctx.r11.s64 = ctx.r7.s64 + 15304;
	// addi r10,r7,11
	ctx.r10.s64 = ctx.r7.s64 + 11;
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
loc_8809746C:
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_88097474:
	// lbz r9,-5(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + -5);
	// lbz r5,-1(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + -1);
	// lwz r4,-11(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11);
	// clrlwi r9,r9,28
	ctx.r9.u64 = ctx.r9.u32 & 0xF;
	// lbz r3,-7(r10)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r10.u32 + -7);
	// cmplwi cr6,r5,45
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 45, ctx.xer);
	// lbz r30,-2(r10)
	ctx.r30.u64 = PPC_LOAD_U8(ctx.r10.u32 + -2);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stb r5,12(r11)
	PPC_STORE_U8(ctx.r11.u32 + 12, ctx.r5.u8);
	// stw r4,-4(r11)
	PPC_STORE_U32(ctx.r11.u32 + -4, ctx.r4.u32);
	// stw r3,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
	// stw r30,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r30.u32);
	// stw r9,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// bne cr6,0x880974b0
	if (!ctx.cr6.eq) goto loc_880974B0;
	// stb r8,12(r11)
	PPC_STORE_U8(ctx.r11.u32 + 12, ctx.r8.u8);
loc_880974B0:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,45
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 45, ctx.xer);
	// stb r9,13(r11)
	PPC_STORE_U8(ctx.r11.u32 + 13, ctx.r9.u8);
	// bne cr6,0x880974c4
	if (!ctx.cr6.eq) goto loc_880974C4;
	// stb r8,13(r11)
	PPC_STORE_U8(ctx.r11.u32 + 13, ctx.r8.u8);
loc_880974C4:
	// lbz r9,1(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// cmplwi cr6,r9,45
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 45, ctx.xer);
	// stb r9,14(r11)
	PPC_STORE_U8(ctx.r11.u32 + 14, ctx.r9.u8);
	// bne cr6,0x880974d8
	if (!ctx.cr6.eq) goto loc_880974D8;
	// stb r8,14(r11)
	PPC_STORE_U8(ctx.r11.u32 + 14, ctx.r8.u8);
loc_880974D8:
	// stb r6,15(r11)
	PPC_STORE_U8(ctx.r11.u32 + 15, ctx.r6.u8);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// addi r11,r11,20
	ctx.r11.s64 = ctx.r11.s64 + 20;
	// bdnz 0x88097474
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88097474;
	// addi r9,r7,491
	ctx.r9.s64 = ctx.r7.s64 + 491;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x8809746c
	if (ctx.cr6.lt) goto loc_8809746C;
	// ld r30,-16(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88097500"))) PPC_WEAK_FUNC(sub_88097500);
PPC_FUNC_IMPL(__imp__sub_88097500) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071144
	ctx.lr = 0x88097508;
	__savegprlr_23(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-30641
	ctx.r10.s64 = -2008088576;
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// lis r23,-30597
	ctx.r23.s64 = -2005204992;
	// addi r11,r11,13264
	ctx.r11.s64 = ctx.r11.s64 + 13264;
	// addi r31,r10,-18768
	ctx.r31.s64 = ctx.r10.s64 + -18768;
	// lwz r10,-18768(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -18768);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r25,128
	ctx.r25.s64 = 128;
	// stw r9,-11012(r23)
	PPC_STORE_U32(ctx.r23.u32 + -11012, ctx.r9.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bne cr6,0x880977a8
	if (!ctx.cr6.eq) goto loc_880977A8;
	// lwz r11,12(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x88097614
	if (ctx.cr6.eq) goto loc_88097614;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r11,r31,12
	ctx.r11.s64 = ctx.r31.s64 + 12;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stwx r9,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + ctx.r11.u32, ctx.r9.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88097588
	if (!ctx.cr6.eq) goto loc_88097588;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmpwi cr6,r10,99
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 99, ctx.xer);
	// ble cr6,0x880976ec
	if (!ctx.cr6.gt) goto loc_880976EC;
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r10,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r10.u32);
	// b 0x880976ec
	goto loc_880976EC;
loc_88097588:
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x880975a8
	if (!ctx.cr6.eq) goto loc_880975A8;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmpwi cr6,r10,12
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 12, ctx.xer);
	// ble cr6,0x880976ec
	if (!ctx.cr6.gt) goto loc_880976EC;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r10.u32);
	// b 0x880976ec
	goto loc_880976EC;
loc_880975A8:
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x880975c8
	if (!ctx.cr6.eq) goto loc_880975C8;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r10,31
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 31, ctx.xer);
	// ble cr6,0x880976ec
	if (!ctx.cr6.gt) goto loc_880976EC;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// b 0x880976ec
	goto loc_880976EC;
loc_880975C8:
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x880975e8
	if (!ctx.cr6.eq) goto loc_880975E8;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmpwi cr6,r10,23
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 23, ctx.xer);
	// ble cr6,0x880976ec
	if (!ctx.cr6.gt) goto loc_880976EC;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// b 0x880976ec
	goto loc_880976EC;
loc_880975E8:
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// beq cr6,0x880975f8
	if (ctx.cr6.eq) goto loc_880975F8;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bne cr6,0x880976ec
	if (!ctx.cr6.eq) goto loc_880976EC;
loc_880975F8:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r31,12
	ctx.r9.s64 = ctx.r31.s64 + 12;
	// lwzx r7,r10,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// cmpwi cr6,r7,59
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 59, ctx.xer);
	// ble cr6,0x880976ec
	if (!ctx.cr6.gt) goto loc_880976EC;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x880976e4
	goto loc_880976E4;
loc_88097614:
	// rlwinm r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880976e8
	if (ctx.cr6.eq) goto loc_880976E8;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r10,r31,12
	ctx.r10.s64 = ctx.r31.s64 + 12;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// stwx r9,r11,r10
	PPC_STORE_U32(ctx.r11.u32 + ctx.r10.u32, ctx.r9.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8809765c
	if (!ctx.cr6.eq) goto loc_8809765C;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmpwi cr6,r10,4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4, ctx.xer);
	// bge cr6,0x880976ec
	if (!ctx.cr6.lt) goto loc_880976EC;
	// li r10,99
	ctx.r10.s64 = 99;
	// stw r10,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r10.u32);
	// b 0x880976ec
	goto loc_880976EC;
loc_8809765C:
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x8809767c
	if (!ctx.cr6.eq) goto loc_8809767C;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bge cr6,0x880976ec
	if (!ctx.cr6.lt) goto loc_880976EC;
	// li r10,12
	ctx.r10.s64 = 12;
	// stw r10,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r10.u32);
	// b 0x880976ec
	goto loc_880976EC;
loc_8809767C:
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x8809769c
	if (!ctx.cr6.eq) goto loc_8809769C;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bge cr6,0x880976ec
	if (!ctx.cr6.lt) goto loc_880976EC;
	// li r10,31
	ctx.r10.s64 = 31;
	// stw r10,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// b 0x880976ec
	goto loc_880976EC;
loc_8809769C:
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x880976bc
	if (!ctx.cr6.eq) goto loc_880976BC;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bge cr6,0x880976ec
	if (!ctx.cr6.lt) goto loc_880976EC;
	// li r10,23
	ctx.r10.s64 = 23;
	// stw r10,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// b 0x880976ec
	goto loc_880976EC;
loc_880976BC:
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// beq cr6,0x880976cc
	if (ctx.cr6.eq) goto loc_880976CC;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bne cr6,0x880976ec
	if (!ctx.cr6.eq) goto loc_880976EC;
loc_880976CC:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r31,12
	ctx.r9.s64 = ctx.r31.s64 + 12;
	// lwzx r7,r10,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bge cr6,0x880976ec
	if (!ctx.cr6.lt) goto loc_880976EC;
	// li r11,59
	ctx.r11.s64 = 59;
loc_880976E4:
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r11.u32);
loc_880976E8:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
loc_880976EC:
	// rlwinm r10,r8,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x88097758
	if (!ctx.cr6.eq) goto loc_88097758;
	// rlwinm r10,r8,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x88097758
	if (!ctx.cr6.eq) goto loc_88097758;
	// rlwinm r10,r8,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x88097744
	if (!ctx.cr6.eq) goto loc_88097744;
	// rlwinm r10,r8,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x88097744
	if (!ctx.cr6.eq) goto loc_88097744;
	// rlwinm r10,r8,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x88097770
	if (ctx.cr6.eq) goto loc_88097770;
	// lis r9,-30641
	ctx.r9.s64 = -2008088576;
	// lis r10,-30710
	ctx.r10.s64 = -2012610560;
	// addi r8,r9,-17320
	ctx.r8.s64 = ctx.r9.s64 + -17320;
	// addi r10,r10,-31256
	ctx.r10.s64 = ctx.r10.s64 + -31256;
	// stw r3,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r3.u32);
	// stw r10,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r10.u32);
	// b 0x88097770
	goto loc_88097770;
loc_88097744:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88097770
	if (ctx.cr6.eq) goto loc_88097770;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// b 0x88097770
	goto loc_88097770;
loc_88097758:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// blt cr6,0x88097770
	if (ctx.cr6.lt) goto loc_88097770;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
loc_88097770:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lis r9,-30714
	ctx.r9.s64 = -2012872704;
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// addi r8,r9,9552
	ctx.r8.s64 = ctx.r9.s64 + 9552;
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// lbz r10,11(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// rotlwi r7,r10,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lwzx r6,r7,r8
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// srawi r5,r6,5
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1F) != 0);
	ctx.r5.s64 = ctx.r6.s32 >> 5;
	// addze r4,r5
	temp.s64 = ctx.r5.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r4.s64 = temp.s64;
	// srawi r3,r4,1
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1) != 0);
	ctx.r3.s64 = ctx.r4.s32 >> 1;
	// addze r10,r3
	temp.s64 = ctx.r3.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r10.s64 = temp.s64;
	// addi r25,r10,64
	ctx.r25.s64 = ctx.r10.s64 + 64;
	// b 0x88097804
	goto loc_88097804;
loc_880977A8:
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x88097800
	if (!ctx.cr6.eq) goto loc_88097800;
	// rlwinm r11,r8,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880977e8
	if (!ctx.cr6.eq) goto loc_880977E8;
	// rlwinm r11,r8,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880977dc
	if (ctx.cr6.eq) goto loc_880977DC;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// b 0x88097804
	goto loc_88097804;
loc_880977DC:
	// rlwinm r11,r8,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88097800
	if (ctx.cr6.eq) goto loc_88097800;
loc_880977E8:
	// lis r9,-30641
	ctx.r9.s64 = -2008088576;
	// lis r10,-30710
	ctx.r10.s64 = -2012610560;
	// addi r8,r9,-17320
	ctx.r8.s64 = ctx.r9.s64 + -17320;
	// addi r10,r10,-31256
	ctx.r10.s64 = ctx.r10.s64 + -31256;
	// stw r10,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r10.u32);
	// stw r3,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r3.u32);
loc_88097800:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
loc_88097804:
	// lis r9,-30683
	ctx.r9.s64 = -2010841088;
	// lis r10,-32640
	ctx.r10.s64 = -2139095040;
	// addi r30,r9,11780
	ctx.r30.s64 = ctx.r9.s64 + 11780;
	// ori r28,r10,32896
	ctx.r28.u64 = ctx.r10.u64 | 32896;
	// lis r9,-30719
	ctx.r9.s64 = -2013200384;
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// addi r24,r9,-7400
	ctx.r24.s64 = ctx.r9.s64 + -7400;
	// stw r28,-4(r30)
	PPC_STORE_U32(ctx.r30.u32 + -4, ctx.r28.u32);
	// bne cr6,0x88097858
	if (!ctx.cr6.eq) goto loc_88097858;
	// lis r11,-128
	ctx.r11.s64 = -8388608;
	// addi r6,r24,96
	ctx.r6.s64 = ctx.r24.s64 + 96;
	// rlwimi r11,r25,8,9,23
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r25.u32, 8) & 0x7FFF00) | (ctx.r11.u64 & 0xFFFFFFFFFF8000FF);
	// li r5,250
	ctx.r5.s64 = 250;
	// or r10,r11,r25
	ctx.r10.u64 = ctx.r11.u64 | ctx.r25.u64;
	// li r4,75
	ctx.r4.s64 = 75;
	// rlwinm r9,r10,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// li r3,40
	ctx.r3.s64 = 40;
	// or r11,r9,r25
	ctx.r11.u64 = ctx.r9.u64 | ctx.r25.u64;
	// stw r11,-4(r30)
	PPC_STORE_U32(ctx.r30.u32 + -4, ctx.r11.u32);
	// bl 0x88091288
	ctx.lr = 0x88097858;
	sub_88091288(ctx, base);
loc_88097858:
	// lis r11,26214
	ctx.r11.s64 = 1717960704;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r27,10
	ctx.r27.s64 = 10;
	// ori r29,r11,26215
	ctx.r29.u64 = ctx.r11.u64 | 26215;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// mulhw r6,r10,r29
	ctx.r6.s64 = (int64_t(ctx.r10.s32) * int64_t(ctx.r29.s32)) >> 32;
	// srawi r11,r6,2
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r6.s32 >> 2;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// divw r7,r10,r27
	ctx.r7.s32 = ppc_divw(ctx.r10.s32, ctx.r27.s32);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r10,r7,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// subf r11,r9,r8
	ctx.r11.s64 = ctx.r8.s64 - ctx.r9.s64;
	// add r26,r10,r11
	ctx.r26.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bl 0x88070590
	ctx.lr = 0x880978AC;
	sub_88070590(ctx, base);
	// ori r5,r26,8192
	ctx.r5.u64 = ctx.r26.u64 | 8192;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x88070590
	ctx.lr = 0x880978BC;
	sub_88070590(ctx, base);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// li r5,250
	ctx.r5.s64 = 250;
	// li r4,72
	ctx.r4.s64 = 72;
	// li r3,40
	ctx.r3.s64 = 40;
	// bl 0x88091288
	ctx.lr = 0x880978D0;
	sub_88091288(ctx, base);
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stw r28,-4(r30)
	PPC_STORE_U32(ctx.r30.u32 + -4, ctx.r28.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x88097910
	if (!ctx.cr6.eq) goto loc_88097910;
	// lis r11,-128
	ctx.r11.s64 = -8388608;
	// addi r6,r24,104
	ctx.r6.s64 = ctx.r24.s64 + 104;
	// rlwimi r11,r25,8,9,23
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r25.u32, 8) & 0x7FFF00) | (ctx.r11.u64 & 0xFFFFFFFFFF8000FF);
	// li r5,250
	ctx.r5.s64 = 250;
	// or r10,r11,r25
	ctx.r10.u64 = ctx.r11.u64 | ctx.r25.u64;
	// li r4,75
	ctx.r4.s64 = 75;
	// rlwinm r9,r10,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// li r3,80
	ctx.r3.s64 = 80;
	// or r11,r9,r25
	ctx.r11.u64 = ctx.r9.u64 | ctx.r25.u64;
	// stw r11,-4(r30)
	PPC_STORE_U32(ctx.r30.u32 + -4, ctx.r11.u32);
	// bl 0x88091288
	ctx.lr = 0x88097910;
	sub_88091288(ctx, base);
loc_88097910:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// mulhw r10,r11,r29
	ctx.r10.s64 = (int64_t(ctx.r11.s32) * int64_t(ctx.r29.s32)) >> 32;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	// divw r9,r11,r27
	ctx.r9.s32 = ppc_divw(ctx.r11.s32, ctx.r27.s32);
	// rlwinm r8,r10,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// rlwinm r9,r9,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r11,r7,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r7.s64;
	// add r26,r9,r11
	ctx.r26.u64 = ctx.r9.u64 + ctx.r11.u64;
	// bl 0x88070590
	ctx.lr = 0x88097950;
	sub_88070590(ctx, base);
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x88070590
	ctx.lr = 0x88097960;
	sub_88070590(ctx, base);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,250
	ctx.r5.s64 = 250;
	// li r4,72
	ctx.r4.s64 = 72;
	// li r3,80
	ctx.r3.s64 = 80;
	// bl 0x88091288
	ctx.lr = 0x88097974;
	sub_88091288(ctx, base);
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stw r28,-4(r30)
	PPC_STORE_U32(ctx.r30.u32 + -4, ctx.r28.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x880979b4
	if (!ctx.cr6.eq) goto loc_880979B4;
	// lis r11,-128
	ctx.r11.s64 = -8388608;
	// addi r6,r24,108
	ctx.r6.s64 = ctx.r24.s64 + 108;
	// rlwimi r11,r25,8,9,23
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r25.u32, 8) & 0x7FFF00) | (ctx.r11.u64 & 0xFFFFFFFFFF8000FF);
	// li r5,250
	ctx.r5.s64 = 250;
	// or r10,r11,r25
	ctx.r10.u64 = ctx.r11.u64 | ctx.r25.u64;
	// li r4,75
	ctx.r4.s64 = 75;
	// rlwinm r9,r10,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// li r3,104
	ctx.r3.s64 = 104;
	// or r11,r9,r25
	ctx.r11.u64 = ctx.r9.u64 | ctx.r25.u64;
	// stw r11,-4(r30)
	PPC_STORE_U32(ctx.r30.u32 + -4, ctx.r11.u32);
	// bl 0x88091288
	ctx.lr = 0x880979B4;
	sub_88091288(ctx, base);
loc_880979B4:
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// mulhw r10,r11,r29
	ctx.r10.s64 = (int64_t(ctx.r11.s32) * int64_t(ctx.r29.s32)) >> 32;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	// divw r9,r11,r27
	ctx.r9.s32 = ppc_divw(ctx.r11.s32, ctx.r27.s32);
	// rlwinm r8,r10,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// rlwinm r9,r9,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r11,r7,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r7.s64;
	// add r26,r9,r11
	ctx.r26.u64 = ctx.r9.u64 + ctx.r11.u64;
	// bl 0x88070590
	ctx.lr = 0x880979F4;
	sub_88070590(ctx, base);
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x88070590
	ctx.lr = 0x88097A04;
	sub_88070590(ctx, base);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,250
	ctx.r5.s64 = 250;
	// li r4,72
	ctx.r4.s64 = 72;
	// li r3,104
	ctx.r3.s64 = 104;
	// bl 0x88091288
	ctx.lr = 0x88097A18;
	sub_88091288(ctx, base);
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stw r28,-4(r30)
	PPC_STORE_U32(ctx.r30.u32 + -4, ctx.r28.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x88097a58
	if (!ctx.cr6.eq) goto loc_88097A58;
	// lis r11,-128
	ctx.r11.s64 = -8388608;
	// addi r6,r24,112
	ctx.r6.s64 = ctx.r24.s64 + 112;
	// rlwimi r11,r25,8,9,23
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r25.u32, 8) & 0x7FFF00) | (ctx.r11.u64 & 0xFFFFFFFFFF8000FF);
	// li r5,250
	ctx.r5.s64 = 250;
	// or r10,r11,r25
	ctx.r10.u64 = ctx.r11.u64 | ctx.r25.u64;
	// li r4,75
	ctx.r4.s64 = 75;
	// rlwinm r9,r10,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// li r3,128
	ctx.r3.s64 = 128;
	// or r11,r9,r25
	ctx.r11.u64 = ctx.r9.u64 | ctx.r25.u64;
	// stw r11,-4(r30)
	PPC_STORE_U32(ctx.r30.u32 + -4, ctx.r11.u32);
	// bl 0x88091288
	ctx.lr = 0x88097A58;
	sub_88091288(ctx, base);
loc_88097A58:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// mulhw r10,r11,r29
	ctx.r10.s64 = (int64_t(ctx.r11.s32) * int64_t(ctx.r29.s32)) >> 32;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	// divw r9,r11,r27
	ctx.r9.s32 = ppc_divw(ctx.r11.s32, ctx.r27.s32);
	// rlwinm r8,r10,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// rlwinm r9,r9,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r11,r7,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r7.s64;
	// add r26,r9,r11
	ctx.r26.u64 = ctx.r9.u64 + ctx.r11.u64;
	// bl 0x88070590
	ctx.lr = 0x88097A98;
	sub_88070590(ctx, base);
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x88070590
	ctx.lr = 0x88097AA8;
	sub_88070590(ctx, base);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,250
	ctx.r5.s64 = 250;
	// li r4,72
	ctx.r4.s64 = 72;
	// li r3,128
	ctx.r3.s64 = 128;
	// bl 0x88091288
	ctx.lr = 0x88097ABC;
	sub_88091288(ctx, base);
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stw r28,-4(r30)
	PPC_STORE_U32(ctx.r30.u32 + -4, ctx.r28.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bne cr6,0x88097afc
	if (!ctx.cr6.eq) goto loc_88097AFC;
	// lis r11,-128
	ctx.r11.s64 = -8388608;
	// addi r6,r24,116
	ctx.r6.s64 = ctx.r24.s64 + 116;
	// rlwimi r11,r25,8,9,23
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r25.u32, 8) & 0x7FFF00) | (ctx.r11.u64 & 0xFFFFFFFFFF8000FF);
	// li r5,250
	ctx.r5.s64 = 250;
	// or r10,r11,r25
	ctx.r10.u64 = ctx.r11.u64 | ctx.r25.u64;
	// li r4,75
	ctx.r4.s64 = 75;
	// rlwinm r9,r10,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// li r3,152
	ctx.r3.s64 = 152;
	// or r11,r9,r25
	ctx.r11.u64 = ctx.r9.u64 | ctx.r25.u64;
	// stw r11,-4(r30)
	PPC_STORE_U32(ctx.r30.u32 + -4, ctx.r11.u32);
	// bl 0x88091288
	ctx.lr = 0x88097AFC;
	sub_88091288(ctx, base);
loc_88097AFC:
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// mulhw r10,r11,r29
	ctx.r10.s64 = (int64_t(ctx.r11.s32) * int64_t(ctx.r29.s32)) >> 32;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	// divw r9,r11,r27
	ctx.r9.s32 = ppc_divw(ctx.r11.s32, ctx.r27.s32);
	// rlwinm r8,r10,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// rlwinm r9,r9,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r11,r7,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r7.s64;
	// add r26,r9,r11
	ctx.r26.u64 = ctx.r9.u64 + ctx.r11.u64;
	// bl 0x88070590
	ctx.lr = 0x88097B3C;
	sub_88070590(ctx, base);
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x88070590
	ctx.lr = 0x88097B4C;
	sub_88070590(ctx, base);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,250
	ctx.r5.s64 = 250;
	// li r4,72
	ctx.r4.s64 = 72;
	// li r3,152
	ctx.r3.s64 = 152;
	// bl 0x88091288
	ctx.lr = 0x88097B60;
	sub_88091288(ctx, base);
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stw r28,-4(r30)
	PPC_STORE_U32(ctx.r30.u32 + -4, ctx.r28.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bne cr6,0x88097ba0
	if (!ctx.cr6.eq) goto loc_88097BA0;
	// lis r11,-128
	ctx.r11.s64 = -8388608;
	// addi r6,r24,120
	ctx.r6.s64 = ctx.r24.s64 + 120;
	// rlwimi r11,r25,8,9,23
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r25.u32, 8) & 0x7FFF00) | (ctx.r11.u64 & 0xFFFFFFFFFF8000FF);
	// li r5,250
	ctx.r5.s64 = 250;
	// or r10,r11,r25
	ctx.r10.u64 = ctx.r11.u64 | ctx.r25.u64;
	// li r4,75
	ctx.r4.s64 = 75;
	// rlwinm r9,r10,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// li r3,176
	ctx.r3.s64 = 176;
	// or r11,r9,r25
	ctx.r11.u64 = ctx.r9.u64 | ctx.r25.u64;
	// stw r11,-4(r30)
	PPC_STORE_U32(ctx.r30.u32 + -4, ctx.r11.u32);
	// bl 0x88091288
	ctx.lr = 0x88097BA0;
	sub_88091288(ctx, base);
loc_88097BA0:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// mulhw r10,r11,r29
	ctx.r10.s64 = (int64_t(ctx.r11.s32) * int64_t(ctx.r29.s32)) >> 32;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	// divw r9,r11,r27
	ctx.r9.s32 = ppc_divw(ctx.r11.s32, ctx.r27.s32);
	// rlwinm r8,r10,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// rlwinm r9,r9,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r11,r7,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r7.s64;
	// add r29,r9,r11
	ctx.r29.u64 = ctx.r9.u64 + ctx.r11.u64;
	// bl 0x88070590
	ctx.lr = 0x88097BE0;
	sub_88070590(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x88070590
	ctx.lr = 0x88097BF0;
	sub_88070590(ctx, base);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,250
	ctx.r5.s64 = 250;
	// li r4,72
	ctx.r4.s64 = 72;
	// li r3,176
	ctx.r3.s64 = 176;
	// bl 0x88091288
	ctx.lr = 0x88097C04;
	sub_88091288(ctx, base);
	// stw r28,-4(r30)
	PPC_STORE_U32(ctx.r30.u32 + -4, ctx.r28.u32);
	// mr r29,r24
	ctx.r29.u64 = ctx.r24.u64;
	// li r30,2
	ctx.r30.s64 = 2;
loc_88097C10:
	// lwz r11,4(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// li r5,250
	ctx.r5.s64 = 250;
	// lwz r6,8(r29)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// addi r4,r11,24
	ctx.r4.s64 = ctx.r11.s64 + 24;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x88091288
	ctx.lr = 0x88097C28;
	sub_88091288(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r29,r29,12
	ctx.r29.s64 = ctx.r29.s64 + 12;
	// bne 0x88097c10
	if (!ctx.cr0.eq) goto loc_88097C10;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,-11012(r23)
	PPC_STORE_U32(ctx.r23.u32 + -11012, ctx.r11.u32);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x88097c4c
	if (!ctx.cr6.eq) goto loc_88097C4C;
	// addi r29,r29,36
	ctx.r29.s64 = ctx.r29.s64 + 36;
loc_88097C4C:
	// lwz r11,4(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// li r5,250
	ctx.r5.s64 = 250;
	// lwz r6,8(r29)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// addi r4,r11,24
	ctx.r4.s64 = ctx.r11.s64 + 24;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x88091288
	ctx.lr = 0x88097C64;
	sub_88091288(ctx, base);
	// lwz r11,16(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// li r5,250
	ctx.r5.s64 = 250;
	// lwz r6,20(r29)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// addi r4,r11,24
	ctx.r4.s64 = ctx.r11.s64 + 24;
	// lwz r3,12(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// addi r31,r29,12
	ctx.r31.s64 = ctx.r29.s64 + 12;
	// bl 0x88091288
	ctx.lr = 0x88097C80;
	sub_88091288(ctx, base);
	// lwz r11,28(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 28);
	// li r5,250
	ctx.r5.s64 = 250;
	// lwz r6,32(r29)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + 32);
	// addi r4,r11,24
	ctx.r4.s64 = ctx.r11.s64 + 24;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// bl 0x88091288
	ctx.lr = 0x88097C98;
	sub_88091288(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88097CA4"))) PPC_WEAK_FUNC(sub_88097CA4);
PPC_FUNC_IMPL(__imp__sub_88097CA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88097CA8"))) PPC_WEAK_FUNC(sub_88097CA8);
PPC_FUNC_IMPL(__imp__sub_88097CA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071134
	ctx.lr = 0x88097CB0;
	__savegprlr_19(ctx, base);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30651
	ctx.r11.s64 = -2008743936;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r10,r11,-26112
	ctx.r10.s64 = ctx.r11.s64 + -26112;
	// lbz r8,12(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 12);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x88097cd0
	if (ctx.cr6.eq) goto loc_88097CD0;
	// li r9,2
	ctx.r9.s64 = 2;
loc_88097CD0:
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// addi r27,r11,-18728
	ctx.r27.s64 = ctx.r11.s64 + -18728;
	// lwz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// bgt cr6,0x88097e88
	if (ctx.cr6.gt) goto loc_88097E88;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x88097df4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_88097DF4;
	// bdzf 4*cr6+eq,0x88097e3c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_88097E3C;
	// bne cr6,0x88097e68
	if (!ctx.cr6.eq) goto loc_88097E68;
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// addi r8,r11,13264
	ctx.r8.s64 = ctx.r11.s64 + 13264;
	// lwz r10,12(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// rlwinm r11,r10,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88097d28
	if (ctx.cr6.eq) goto loc_88097D28;
	// lwz r11,12(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,12(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12, ctx.r11.u32);
	// bge 0x88097d50
	if (!ctx.cr0.lt) goto loc_88097D50;
	// stw r9,12(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12, ctx.r9.u32);
	// b 0x88097d50
	goto loc_88097D50;
loc_88097D28:
	// clrlwi r11,r10,31
	ctx.r11.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88097d50
	if (ctx.cr6.eq) goto loc_88097D50;
	// lwz r11,12(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// subfc r9,r11,r9
	ctx.xer.ca = ctx.r9.u32 >= ctx.r11.u32;
	ctx.r9.s64 = ctx.r9.s64 - ctx.r11.s64;
	// addze r7,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r7.s64 = temp.s64;
	// subf r6,r7,r11
	ctx.r6.s64 = ctx.r11.s64 - ctx.r7.s64;
	// and r11,r6,r11
	ctx.r11.u64 = ctx.r6.u64 & ctx.r11.u64;
	// stw r11,12(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12, ctx.r11.u32);
loc_88097D50:
	// rlwinm r11,r10,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88097d74
	if (ctx.cr6.eq) goto loc_88097D74;
	// lwz r11,16(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 16);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,16(r27)
	PPC_STORE_U32(ctx.r27.u32 + 16, ctx.r11.u32);
	// bge 0x88097da4
	if (!ctx.cr0.lt) goto loc_88097DA4;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x88097da0
	goto loc_88097DA0;
loc_88097D74:
	// rlwinm r11,r10,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88097da4
	if (ctx.cr6.eq) goto loc_88097DA4;
	// lwz r11,16(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 16);
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// xoris r9,r11,32768
	ctx.r9.u64 = ctx.r11.u64 ^ 2147483648;
	// subf r7,r11,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r11.s64;
	// addc r6,r7,r9
	{ uint8_t _ca = ctx.r7.u32 + ctx.r9.u32 < ctx.r7.u32; // FIX 2026-07-24: insn was silently dropped by the recompiler
	ctx.r6.u64 = ctx.r7.u64 + ctx.r9.u64;
	ctx.xer.ca = _ca; }
	// subfe r4,r5,r5
	temp.u8 = (~ctx.r5.u32 + ctx.r5.u32 < ~ctx.r5.u32) | (~ctx.r5.u32 + ctx.r5.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r4.u64 = ~ctx.r5.u64 + ctx.r5.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 & ctx.r11.u64;
loc_88097DA0:
	// stw r11,16(r27)
	PPC_STORE_U32(ctx.r27.u32 + 16, ctx.r11.u32);
loc_88097DA4:
	// lwz r10,4(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// rlwinm r9,r10,0,16,16
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8000;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x88097e88
	if (ctx.cr6.eq) goto loc_88097E88;
	// rlwinm r11,r10,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88097dd8
	if (ctx.cr6.eq) goto loc_88097DD8;
	// lis r8,-30641
	ctx.r8.s64 = -2008088576;
	// lis r11,-30710
	ctx.r11.s64 = -2012610560;
	// addi r7,r8,-17320
	ctx.r7.s64 = ctx.r8.s64 + -17320;
	// addi r11,r11,-31256
	ctx.r11.s64 = ctx.r11.s64 + -31256;
	// stw r3,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r3.u32);
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r11.u32);
loc_88097DD8:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x88097e88
	if (ctx.cr6.eq) goto loc_88097E88;
	// rlwinm r11,r10,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88097e88
	if (ctx.cr6.eq) goto loc_88097E88;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x88097e84
	goto loc_88097E84;
loc_88097DF4:
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// addi r10,r11,13264
	ctx.r10.s64 = ctx.r11.s64 + 13264;
	// lwz r8,8(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// rlwinm r9,r8,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x88097e28
	if (ctx.cr6.eq) goto loc_88097E28;
	// lis r7,-30641
	ctx.r7.s64 = -2008088576;
	// li r11,2
	ctx.r11.s64 = 2;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,4(r27)
	PPC_STORE_U32(ctx.r27.u32 + 4, ctx.r11.u32);
	// stw r10,8(r27)
	PPC_STORE_U32(ctx.r27.u32 + 8, ctx.r10.u32);
	// stw r9,-17324(r7)
	PPC_STORE_U32(ctx.r7.u32 + -17324, ctx.r9.u32);
loc_88097E28:
	// rlwinm r11,r8,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88097e88
	if (ctx.cr6.eq) goto loc_88097E88;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x88097e84
	goto loc_88097E84;
loc_88097E3C:
	// lwz r11,8(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,8(r27)
	PPC_STORE_U32(ctx.r27.u32 + 8, ctx.r11.u32);
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// blt cr6,0x88097e88
	if (ctx.cr6.lt) goto loc_88097E88;
	// bl 0x880f14f8
	ctx.lr = 0x88097E54;
	sub_880F14F8(ctx, base);
	// bl 0x88097448
	ctx.lr = 0x88097E58;
	sub_88097448(ctx, base);
	// li r10,32
	ctx.r10.s64 = 32;
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r10,8(r27)
	PPC_STORE_U32(ctx.r27.u32 + 8, ctx.r10.u32);
	// b 0x88097e84
	goto loc_88097E84;
loc_88097E68:
	// lwz r11,8(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 8);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// subfic r9,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r9.s64 = 0 - ctx.r11.s64;
	// stw r11,8(r27)
	PPC_STORE_U32(ctx.r27.u32 + 8, ctx.r11.u32);
	// rlwinm r8,r11,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addme r7,r8
	{ uint8_t _ca = (ctx.r8.u32 + 0xFFFFFFFF < ctx.r8.u32) | (ctx.r8.u32 + 0xFFFFFFFF + ctx.xer.ca < ctx.xer.ca); // FIX 2026-07-24: insn was silently dropped by the recompiler
	ctx.r7.u64 = ctx.r8.u64 + 0xFFFFFFFFFFFFFFFFull + ctx.xer.ca;
	ctx.xer.ca = _ca; }
	// and r11,r7,r10
	ctx.r11.u64 = ctx.r7.u64 & ctx.r10.u64;
loc_88097E84:
	// stw r11,4(r27)
	PPC_STORE_U32(ctx.r27.u32 + 4, ctx.r11.u32);
loc_88097E88:
	// lis r11,-30719
	ctx.r11.s64 = -2013200384;
	// lis r10,-30683
	ctx.r10.s64 = -2010841088;
	// addi r20,r11,-7676
	ctx.r20.s64 = ctx.r11.s64 + -7676;
	// addi r25,r10,11780
	ctx.r25.s64 = ctx.r10.s64 + 11780;
	// lis r11,-32640
	ctx.r11.s64 = -2139095040;
	// li r22,10
	ctx.r22.s64 = 10;
	// addi r10,r20,-812
	ctx.r10.s64 = ctx.r20.s64 + -812;
	// ori r11,r11,32896
	ctx.r11.u64 = ctx.r11.u64 | 32896;
	// mr r30,r22
	ctx.r30.u64 = ctx.r22.u64;
	// addi r31,r10,-4
	ctx.r31.s64 = ctx.r10.s64 + -4;
	// stw r11,-4(r25)
	PPC_STORE_U32(ctx.r25.u32 + -4, ctx.r11.u32);
loc_88097EB4:
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r5,250
	ctx.r5.s64 = 250;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r4,r11,24
	ctx.r4.s64 = ctx.r11.s64 + 24;
	// lwzu r6,12(r31)
	ea = 12 + ctx.r31.u32;
	ctx.r6.u64 = PPC_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// bl 0x88091288
	ctx.lr = 0x88097ECC;
	sub_88091288(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x88097eb4
	if (!ctx.cr0.eq) goto loc_88097EB4;
	// lwz r11,16(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 16);
	// addi r8,r20,-500
	ctx.r8.s64 = ctx.r20.s64 + -500;
	// lwz r10,12(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// li r5,250
	ctx.r5.s64 = 250;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r31,r11,r10
	ctx.r31.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r31,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r31,r11
	ctx.r11.u64 = ctx.r31.u64 + ctx.r11.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// addi r4,r10,24
	ctx.r4.s64 = ctx.r10.s64 + 24;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x88091288
	ctx.lr = 0x88097F14;
	sub_88091288(ctx, base);
	// addi r11,r27,20
	ctx.r11.s64 = ctx.r27.s64 + 20;
	// mulli r10,r31,100
	ctx.r10.s64 = ctx.r31.s64 * 100;
	// add r24,r10,r11
	ctx.r24.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lis r11,-13108
	ctx.r11.s64 = -859045888;
	// li r23,64
	ctx.r23.s64 = 64;
	// li r21,5
	ctx.r21.s64 = 5;
	// ori r26,r11,52429
	ctx.r26.u64 = ctx.r11.u64 | 52429;
loc_88097F30:
	// lwz r31,0(r24)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x88097f50
	if (ctx.cr6.eq) goto loc_88097F50;
loc_88097F44:
	// divwu. r11,r11,r22
	ctx.r11.u32 = ppc_divwu(ctx.r11.u32, ctx.r22.u32);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// bne 0x88097f44
	if (!ctx.cr0.eq) goto loc_88097F44;
loc_88097F50:
	// li r29,128
	ctx.r29.s64 = 128;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x88097fbc
	if (ctx.cr6.eq) goto loc_88097FBC;
	// addi r28,r23,-8
	ctx.r28.s64 = ctx.r23.s64 + -8;
loc_88097F60:
	// mulhwu r11,r31,r26
	ctx.r11.u64 = (uint64_t(ctx.r31.u32) * uint64_t(ctx.r26.u32)) >> 32;
	// rlwinm r11,r11,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r5,1
	ctx.r5.s64 = 1;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r19,r9,r31
	ctx.r19.s64 = ctx.r31.s64 - ctx.r9.s64;
	// divwu r31,r31,r22
	ctx.r31.u32 = ppc_divwu(ctx.r31.u32, ctx.r22.u32);
	// bl 0x88070590
	ctx.lr = 0x88097F8C;
	sub_88070590(ctx, base);
	// mr r5,r19
	ctx.r5.u64 = ctx.r19.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x88070590
	ctx.lr = 0x88097F9C;
	sub_88070590(ctx, base);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// li r5,250
	ctx.r5.s64 = 250;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88091288
	ctx.lr = 0x88097FB0;
	sub_88091288(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r29,r29,-8
	ctx.r29.s64 = ctx.r29.s64 + -8;
	// bne 0x88097f60
	if (!ctx.cr0.eq) goto loc_88097F60;
loc_88097FBC:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// lwz r31,4(r24)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r24.u32 + 4);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x88070590
	ctx.lr = 0x88097FD0;
	sub_88070590(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x88070590
	ctx.lr = 0x88097FE0;
	sub_88070590(ctx, base);
	// addi r31,r23,-8
	ctx.r31.s64 = ctx.r23.s64 + -8;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r5,250
	ctx.r5.s64 = 250;
	// li r3,144
	ctx.r3.s64 = 144;
	// bl 0x88091288
	ctx.lr = 0x88097FF8;
	sub_88091288(ctx, base);
	// addi r6,r24,16
	ctx.r6.s64 = ctx.r24.s64 + 16;
	// li r5,250
	ctx.r5.s64 = 250;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,160
	ctx.r3.s64 = 160;
	// bl 0x88091288
	ctx.lr = 0x8809800C;
	sub_88091288(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lwz r31,12(r24)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r24.u32 + 12);
	// bl 0x88070590
	ctx.lr = 0x88098020;
	sub_88070590(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x88070590
	ctx.lr = 0x88098030;
	sub_88070590(ctx, base);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,250
	ctx.r5.s64 = 250;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// li r3,128
	ctx.r3.s64 = 128;
	// bl 0x88091288
	ctx.lr = 0x88098044;
	sub_88091288(ctx, base);
	// lwz r31,8(r24)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r24.u32 + 8);
	// cmplwi cr6,r31,6
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 6, ctx.xer);
	// blt cr6,0x88098058
	if (ctx.cr6.lt) goto loc_88098058;
	// addi r6,r20,12
	ctx.r6.s64 = ctx.r20.s64 + 12;
	// b 0x8809807c
	goto loc_8809807C;
loc_88098058:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x88070590
	ctx.lr = 0x88098068;
	sub_88070590(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x88070590
	ctx.lr = 0x88098078;
	sub_88070590(ctx, base);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
loc_8809807C:
	// li r5,250
	ctx.r5.s64 = 250;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// li r3,160
	ctx.r3.s64 = 160;
	// bl 0x88091288
	ctx.lr = 0x8809808C;
	sub_88091288(ctx, base);
	// addic. r21,r21,-1
	ctx.xer.ca = ctx.r21.u32 > 0;
	ctx.r21.s64 = ctx.r21.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// addi r23,r23,24
	ctx.r23.s64 = ctx.r23.s64 + 24;
	// addi r24,r24,20
	ctx.r24.s64 = ctx.r24.s64 + 20;
	// bne 0x88097f30
	if (!ctx.cr0.eq) goto loc_88097F30;
	// lwz r11,4(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x880980d8
	if (!ctx.cr6.eq) goto loc_880980D8;
	// addi r11,r20,-300
	ctx.r11.s64 = ctx.r20.s64 + -300;
	// li r30,4
	ctx.r30.s64 = 4;
	// addi r31,r11,-4
	ctx.r31.s64 = ctx.r11.s64 + -4;
loc_880980B4:
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r5,250
	ctx.r5.s64 = 250;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r4,r11,24
	ctx.r4.s64 = ctx.r11.s64 + 24;
	// lwzu r6,12(r31)
	ea = 12 + ctx.r31.u32;
	ctx.r6.u64 = PPC_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// bl 0x88091288
	ctx.lr = 0x880980CC;
	sub_88091288(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x880980b4
	if (!ctx.cr0.eq) goto loc_880980B4;
	// lwz r11,4(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
loc_880980D8:
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8809811c
	if (!ctx.cr6.eq) goto loc_8809811C;
	// lwz r11,8(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 8);
	// addi r10,r20,-92
	ctx.r10.s64 = ctx.r20.s64 + -92;
	// li r5,250
	ctx.r5.s64 = 250;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// addi r4,r10,24
	ctx.r4.s64 = ctx.r10.s64 + 24;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x88091288
	ctx.lr = 0x88098118;
	sub_88091288(ctx, base);
	// lwz r11,4(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
loc_8809811C:
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x88098138
	if (!ctx.cr6.eq) goto loc_88098138;
	// li r5,250
	ctx.r5.s64 = 250;
	// lwz r6,8(r20)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r20.u32 + 8);
	// li r4,184
	ctx.r4.s64 = 184;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x88091288
	ctx.lr = 0x88098138;
	sub_88091288(ctx, base);
loc_88098138:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x88071184
	__restgprlr_19(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88098144"))) PPC_WEAK_FUNC(sub_88098144);
PPC_FUNC_IMPL(__imp__sub_88098144) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88098148"))) PPC_WEAK_FUNC(sub_88098148);
PPC_FUNC_IMPL(__imp__sub_88098148) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807113c
	ctx.lr = 0x88098150;
	__savegprlr_21(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8808cbe8
	ctx.lr = 0x88098160;
	sub_8808CBE8(ctx, base);
	// lis r4,-30641
	ctx.r4.s64 = -2008088576;
	// lis r5,-30641
	ctx.r5.s64 = -2008088576;
	// lbz r8,82(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// addi r3,r4,-17320
	ctx.r3.s64 = ctx.r4.s64 + -17320;
	// lbz r7,81(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// addi r21,r5,-18768
	ctx.r21.s64 = ctx.r5.s64 + -18768;
	// lbz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r9,-30711
	ctx.r9.s64 = -2012676096;
	// stw r11,-18768(r5)
	PPC_STORE_U32(ctx.r5.u32 + -18768, ctx.r11.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r9,29952
	ctx.r9.s64 = ctx.r9.s64 + 29952;
	// stw r31,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r31.u32);
	// rlwinm r31,r7,28,4,31
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 28) & 0xFFFFFFF;
	// stw r10,4(r21)
	PPC_STORE_U32(ctx.r21.u32 + 4, ctx.r10.u32);
	// rlwinm r30,r7,30,2,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 30) & 0x3FFFFFFC;
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// rlwinm r29,r8,28,4,31
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 28) & 0xFFFFFFF;
	// rlwinm r22,r8,30,2,29
	ctx.r22.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0x3FFFFFFC;
	// rlwinm r5,r6,28,4,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 28) & 0xFFFFFFF;
	// rlwinm r4,r6,30,2,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 30) & 0x3FFFFFFC;
	// add r11,r29,r22
	ctx.r11.u64 = ctx.r29.u64 + ctx.r22.u64;
	// add r10,r31,r30
	ctx.r10.u64 = ctx.r31.u64 + ctx.r30.u64;
	// add r9,r5,r4
	ctx.r9.u64 = ctx.r5.u64 + ctx.r4.u64;
	// clrlwi r30,r8,28
	ctx.r30.u64 = ctx.r8.u32 & 0xF;
	// rlwinm r31,r11,1,0,30
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r5,r10,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lbz r11,86(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 86);
	// lbz r10,85(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 85);
	// clrlwi r4,r7,28
	ctx.r4.u64 = ctx.r7.u32 & 0xF;
	// lbz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 84);
	// rlwinm r27,r11,28,4,31
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0xFFFFFFF;
	// rlwinm r28,r11,30,2,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFC;
	// rlwinm r25,r10,28,4,31
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0xFFFFFFF;
	// rlwinm r26,r10,30,2,29
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFC;
	// rlwinm r23,r9,28,4,31
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 28) & 0xFFFFFFF;
	// rlwinm r24,r9,30,2,29
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFC;
	// add r7,r27,r28
	ctx.r7.u64 = ctx.r27.u64 + ctx.r28.u64;
	// add r3,r25,r26
	ctx.r3.u64 = ctx.r25.u64 + ctx.r26.u64;
	// add r29,r23,r24
	ctx.r29.u64 = ctx.r23.u64 + ctx.r24.u64;
	// clrlwi r11,r11,28
	ctx.r11.u64 = ctx.r11.u32 & 0xF;
	// clrlwi r10,r10,28
	ctx.r10.u64 = ctx.r10.u32 & 0xF;
	// clrlwi r9,r9,28
	ctx.r9.u64 = ctx.r9.u32 & 0xF;
	// rlwinm r27,r7,1,0,30
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r28,r3,1,0,30
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r29,r29,1,0,30
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r27,r11
	ctx.r11.u64 = ctx.r27.u64 + ctx.r11.u64;
	// add r10,r28,r10
	ctx.r10.u64 = ctx.r28.u64 + ctx.r10.u64;
	// add r9,r29,r9
	ctx.r9.u64 = ctx.r29.u64 + ctx.r9.u64;
	// stw r11,12(r21)
	PPC_STORE_U32(ctx.r21.u32 + 12, ctx.r11.u32);
	// clrlwi r7,r6,28
	ctx.r7.u64 = ctx.r6.u32 & 0xF;
	// stw r10,16(r21)
	PPC_STORE_U32(ctx.r21.u32 + 16, ctx.r10.u32);
	// stw r9,20(r21)
	PPC_STORE_U32(ctx.r21.u32 + 20, ctx.r9.u32);
	// add r11,r31,r30
	ctx.r11.u64 = ctx.r31.u64 + ctx.r30.u64;
	// add r10,r5,r4
	ctx.r10.u64 = ctx.r5.u64 + ctx.r4.u64;
	// add r9,r8,r7
	ctx.r9.u64 = ctx.r8.u64 + ctx.r7.u64;
	// stw r11,24(r21)
	PPC_STORE_U32(ctx.r21.u32 + 24, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,28(r21)
	PPC_STORE_U32(ctx.r21.u32 + 28, ctx.r10.u32);
	// stw r9,32(r21)
	PPC_STORE_U32(ctx.r21.u32 + 32, ctx.r9.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8807118c
	__restgprlr_21(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809825C"))) PPC_WEAK_FUNC(sub_8809825C);
PPC_FUNC_IMPL(__imp__sub_8809825C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88098260"))) PPC_WEAK_FUNC(sub_88098260);
PPC_FUNC_IMPL(__imp__sub_88098260) {
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
	// lis r7,-30641
	ctx.r7.s64 = -2008088576;
	// li r11,1
	ctx.r11.s64 = 1;
	// addi r6,r7,-18728
	ctx.r6.s64 = ctx.r7.s64 + -18728;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r11,-18728(r7)
	PPC_STORE_U32(ctx.r7.u32 + -18728, ctx.r11.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r10,12(r6)
	PPC_STORE_U32(ctx.r6.u32 + 12, ctx.r10.u32);
	// stw r9,16(r6)
	PPC_STORE_U32(ctx.r6.u32 + 16, ctx.r9.u32);
	// stw r8,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r8.u32);
	// bl 0x88097448
	ctx.lr = 0x880982A0;
	sub_88097448(ctx, base);
	// lis r5,-30641
	ctx.r5.s64 = -2008088576;
	// lis r11,-30711
	ctx.r11.s64 = -2012676096;
	// addi r4,r5,-17320
	ctx.r4.s64 = ctx.r5.s64 + -17320;
	// addi r11,r11,31912
	ctx.r11.s64 = ctx.r11.s64 + 31912;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r31,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r31.u32);
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_880982D0"))) PPC_WEAK_FUNC(sub_880982D0);
PPC_FUNC_IMPL(__imp__sub_880982D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x880982D8;
	__savegprlr_25(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r10,r11,13264
	ctx.r10.s64 = ctx.r11.s64 + 13264;
	// lwz r31,12(r10)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r30,8(r10)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x8808cbe8
	ctx.lr = 0x880982F4;
	sub_8808CBE8(ctx, base);
	// lis r10,-30641
	ctx.r10.s64 = -2008088576;
	// lis r9,-32640
	ctx.r9.s64 = -2139095040;
	// lis r11,-30683
	ctx.r11.s64 = -2010841088;
	// addi r27,r10,-18784
	ctx.r27.s64 = ctx.r10.s64 + -18784;
	// ori r26,r9,32896
	ctx.r26.u64 = ctx.r9.u64 | 32896;
	// addi r29,r11,11780
	ctx.r29.s64 = ctx.r11.s64 + 11780;
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// lis r8,-32640
	ctx.r8.s64 = -2139095040;
	// ori r25,r8,32768
	ctx.r25.u64 = ctx.r8.u64 | 32768;
	// stw r26,-4(r29)
	PPC_STORE_U32(ctx.r29.u32 + -4, ctx.r26.u32);
	// lwz r11,4(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88098330
	if (!ctx.cr6.eq) goto loc_88098330;
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// stw r25,-4(r29)
	PPC_STORE_U32(ctx.r29.u32 + -4, ctx.r25.u32);
loc_88098330:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x88070590
	ctx.lr = 0x88098340;
	sub_88070590(ctx, base);
	// lbz r5,86(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 86);
	// li r11,1
	ctx.r11.s64 = 1;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// rlwimi r5,r11,13,0,23
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r11.u32, 13) & 0xFFFFFF00) | (ctx.r5.u64 & 0xFFFFFFFF000000FF);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x88070590
	ctx.lr = 0x88098358;
	sub_88070590(ctx, base);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// li r5,250
	ctx.r5.s64 = 250;
	// li r4,80
	ctx.r4.s64 = 80;
	// li r3,40
	ctx.r3.s64 = 40;
	// bl 0x88091288
	ctx.lr = 0x8809836C;
	sub_88091288(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x88070590
	ctx.lr = 0x8809837C;
	sub_88070590(ctx, base);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lbz r5,85(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 85);
	// bl 0x88070590
	ctx.lr = 0x8809838C;
	sub_88070590(ctx, base);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// li r5,250
	ctx.r5.s64 = 250;
	// li r4,80
	ctx.r4.s64 = 80;
	// li r3,80
	ctx.r3.s64 = 80;
	// bl 0x88091288
	ctx.lr = 0x880983A0;
	sub_88091288(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x88070590
	ctx.lr = 0x880983B0;
	sub_88070590(ctx, base);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lbz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 84);
	// bl 0x88070590
	ctx.lr = 0x880983C0;
	sub_88070590(ctx, base);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// li r5,250
	ctx.r5.s64 = 250;
	// li r4,80
	ctx.r4.s64 = 80;
	// li r3,104
	ctx.r3.s64 = 104;
	// bl 0x88091288
	ctx.lr = 0x880983D4;
	sub_88091288(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x88070590
	ctx.lr = 0x880983E4;
	sub_88070590(ctx, base);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lbz r5,82(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// bl 0x88070590
	ctx.lr = 0x880983F4;
	sub_88070590(ctx, base);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// li r5,250
	ctx.r5.s64 = 250;
	// li r4,80
	ctx.r4.s64 = 80;
	// li r3,128
	ctx.r3.s64 = 128;
	// bl 0x88091288
	ctx.lr = 0x88098408;
	sub_88091288(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x88070590
	ctx.lr = 0x88098418;
	sub_88070590(ctx, base);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lbz r5,81(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// bl 0x88070590
	ctx.lr = 0x88098428;
	sub_88070590(ctx, base);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// li r5,250
	ctx.r5.s64 = 250;
	// li r4,80
	ctx.r4.s64 = 80;
	// li r3,152
	ctx.r3.s64 = 152;
	// bl 0x88091288
	ctx.lr = 0x8809843C;
	sub_88091288(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x88070590
	ctx.lr = 0x8809844C;
	sub_88070590(ctx, base);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lbz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// bl 0x88070590
	ctx.lr = 0x8809845C;
	sub_88070590(ctx, base);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// li r5,250
	ctx.r5.s64 = 250;
	// li r4,80
	ctx.r4.s64 = 80;
	// li r3,176
	ctx.r3.s64 = 176;
	// bl 0x88091288
	ctx.lr = 0x88098470;
	sub_88091288(ctx, base);
	// clrlwi r5,r31,31
	ctx.r5.u64 = ctx.r31.u32 & 0x1;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x880984a8
	if (ctx.cr6.eq) goto loc_880984A8;
	// lwz r11,4(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,4(r27)
	PPC_STORE_U32(ctx.r27.u32 + 4, ctx.r11.u32);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x88098498
	if (!ctx.cr6.eq) goto loc_88098498;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x880984dc
	goto loc_880984DC;
loc_88098498:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x880984e0
	if (!ctx.cr6.lt) goto loc_880984E0;
	// li r11,3
	ctx.r11.s64 = 3;
	// b 0x880984dc
	goto loc_880984DC;
loc_880984A8:
	// rlwinm r11,r31,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r11,4(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// beq cr6,0x880984e0
	if (ctx.cr6.eq) goto loc_880984E0;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x880984cc
	if (!ctx.cr6.eq) goto loc_880984CC;
	// li r11,2
	ctx.r11.s64 = 2;
	// b 0x880984dc
	goto loc_880984DC;
loc_880984CC:
	// li r10,4
	ctx.r10.s64 = 4;
	// subfc r9,r10,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r10.u32;
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// subfe r7,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r7.u64 = ~ctx.r8.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 & ctx.r11.u64;
loc_880984DC:
	// stw r11,4(r27)
	PPC_STORE_U32(ctx.r27.u32 + 4, ctx.r11.u32);
loc_880984E0:
	// rlwinm r10,r30,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x88098550
	if (ctx.cr6.eq) goto loc_88098550;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8809850c
	if (!ctx.cr6.eq) goto loc_8809850C;
	// lis r10,-30641
	ctx.r10.s64 = -2008088576;
	// lis r9,-30710
	ctx.r9.s64 = -2012610560;
	// addi r8,r10,-17320
	ctx.r8.s64 = ctx.r10.s64 + -17320;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r9,-32440
	ctx.r9.s64 = ctx.r9.s64 + -32440;
	// b 0x88098548
	goto loc_88098548;
loc_8809850C:
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8809852c
	if (!ctx.cr6.eq) goto loc_8809852C;
	// lis r10,-30641
	ctx.r10.s64 = -2008088576;
	// lis r9,-30710
	ctx.r9.s64 = -2012610560;
	// addi r8,r10,-17320
	ctx.r8.s64 = ctx.r10.s64 + -17320;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r9,r9,-32160
	ctx.r9.s64 = ctx.r9.s64 + -32160;
	// b 0x88098548
	goto loc_88098548;
loc_8809852C:
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x88098550
	if (!ctx.cr6.eq) goto loc_88098550;
	// lis r10,-30641
	ctx.r10.s64 = -2008088576;
	// lis r9,-30685
	ctx.r9.s64 = -2010972160;
	// addi r8,r10,-17320
	ctx.r8.s64 = ctx.r10.s64 + -17320;
	// li r10,8
	ctx.r10.s64 = 8;
	// addi r9,r9,-15816
	ctx.r9.s64 = ctx.r9.s64 + -15816;
loc_88098548:
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// stw r9,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r9.u32);
loc_88098550:
	// lis r10,-30719
	ctx.r10.s64 = -2013200384;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r28,r10,-7008
	ctx.r28.s64 = ctx.r10.s64 + -7008;
	// addi r10,r28,-72
	ctx.r10.s64 = ctx.r28.s64 + -72;
	// addi r30,r10,-4
	ctx.r30.s64 = ctx.r10.s64 + -4;
loc_88098564:
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// stw r26,-4(r29)
	PPC_STORE_U32(ctx.r29.u32 + -4, ctx.r26.u32);
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// cmpw cr6,r31,r10
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x88098580
	if (!ctx.cr6.eq) goto loc_88098580;
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// stw r25,-4(r29)
	PPC_STORE_U32(ctx.r29.u32 + -4, ctx.r25.u32);
loc_88098580:
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// li r5,250
	ctx.r5.s64 = 250;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// addi r4,r11,24
	ctx.r4.s64 = ctx.r11.s64 + 24;
	// lwzu r6,12(r30)
	ea = 12 + ctx.r30.u32;
	ctx.r6.u64 = PPC_LOAD_U32(ea);
	ctx.r30.u32 = ea;
	// bl 0x88091288
	ctx.lr = 0x88098598;
	sub_88091288(ctx, base);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// lwz r11,4(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// cmplwi cr6,r31,6
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 6, ctx.xer);
	// blt cr6,0x88098564
	if (ctx.cr6.lt) goto loc_88098564;
	// stw r25,-4(r29)
	PPC_STORE_U32(ctx.r29.u32 + -4, ctx.r25.u32);
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r9,r28,-72
	ctx.r9.s64 = ctx.r28.s64 + -72;
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// li r5,250
	ctx.r5.s64 = 250;
	// li r3,32
	ctx.r3.s64 = 32;
	// lwzx r11,r7,r9
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// addi r4,r11,24
	ctx.r4.s64 = ctx.r11.s64 + 24;
	// bl 0x88091288
	ctx.lr = 0x880985DC;
	sub_88091288(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880985E8"))) PPC_WEAK_FUNC(sub_880985E8);
PPC_FUNC_IMPL(__imp__sub_880985E8) {
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
	// lis r10,-30641
	ctx.r10.s64 = -2008088576;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r9,r10,-18784
	ctx.r9.s64 = ctx.r10.s64 + -18784;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,-18784(r10)
	PPC_STORE_U32(ctx.r10.u32 + -18784, ctx.r11.u32);
	// stw r31,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r31.u32);
	// bl 0x8808cbe8
	ctx.lr = 0x88098618;
	sub_8808CBE8(ctx, base);
	// lis r8,-30641
	ctx.r8.s64 = -2008088576;
	// lis r11,-30710
	ctx.r11.s64 = -2012610560;
	// addi r7,r8,-17320
	ctx.r7.s64 = ctx.r8.s64 + -17320;
	// addi r11,r11,-32048
	ctx.r11.s64 = ctx.r11.s64 + -32048;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r31,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r31.u32);
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_88098648"))) PPC_WEAK_FUNC(sub_88098648);
PPC_FUNC_IMPL(__imp__sub_88098648) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,160
	ctx.r10.s64 = 160;
	// srawi r9,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 16;
	// addze r11,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r11.s64 = temp.s64;
	// addi r8,r11,-160
	ctx.r8.s64 = ctx.r11.s64 + -160;
	// mulli r7,r8,240
	ctx.r7.s64 = ctx.r8.s64 * 240;
	// srawi r6,r7,1
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 1;
	// addze r5,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r5.s64 = temp.s64;
	// divw r11,r5,r10
	ctx.r11.s32 = ppc_divw(ctx.r5.s32, ctx.r10.s32);
	// addi r4,r11,160
	ctx.r4.s64 = ctx.r11.s64 + 160;
	// rlwinm r11,r4,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8809867C"))) PPC_WEAK_FUNC(sub_8809867C);
PPC_FUNC_IMPL(__imp__sub_8809867C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88098680"))) PPC_WEAK_FUNC(sub_88098680);
PPC_FUNC_IMPL(__imp__sub_88098680) {
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
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,15624(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15624);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880986c4
	if (ctx.cr6.eq) goto loc_880986C4;
	// lwz r11,12(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lis r10,800
	ctx.r10.s64 = 52428800;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x880986c4
	if (!ctx.cr6.gt) goto loc_880986C4;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x880991d8
	ctx.lr = 0x880986BC;
	sub_880991D8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88094220
	ctx.lr = 0x880986C4;
	sub_88094220(ctx, base);
loc_880986C4:
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

__attribute__((alias("__imp__sub_880986D8"))) PPC_WEAK_FUNC(sub_880986D8);
PPC_FUNC_IMPL(__imp__sub_880986D8) {
	PPC_FUNC_PROLOGUE();
	// lwz r7,2304(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r10,r11,576
	ctx.r10.s64 = ctx.r11.s64 + 576;
	// lwz r9,14584(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 14584);
	// lwz r11,-104(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -104);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x88098714
	if (ctx.cr6.eq) goto loc_88098714;
	// cmpwi cr6,r11,3000
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3000, ctx.xer);
	// bge cr6,0x88098714
	if (!ctx.cr6.lt) goto loc_88098714;
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r8.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-104(r10)
	PPC_STORE_U32(ctx.r10.u32 + -104, ctx.r11.u32);
	// stwx r9,r6,r10
	PPC_STORE_U32(ctx.r6.u32 + ctx.r10.u32, ctx.r9.u32);
loc_88098714:
	// lwz r9,14728(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 14728);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8809873c
	if (ctx.cr6.eq) goto loc_8809873C;
	// cmpwi cr6,r11,3000
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3000, ctx.xer);
	// bge cr6,0x8809873c
	if (!ctx.cr6.lt) goto loc_8809873C;
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r8.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-104(r10)
	PPC_STORE_U32(ctx.r10.u32 + -104, ctx.r11.u32);
	// stwx r9,r6,r10
	PPC_STORE_U32(ctx.r6.u32 + ctx.r10.u32, ctx.r9.u32);
loc_8809873C:
	// lwz r9,14872(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 14872);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x88098764
	if (ctx.cr6.eq) goto loc_88098764;
	// cmpwi cr6,r11,3000
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3000, ctx.xer);
	// bge cr6,0x88098764
	if (!ctx.cr6.lt) goto loc_88098764;
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r8.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-104(r10)
	PPC_STORE_U32(ctx.r10.u32 + -104, ctx.r11.u32);
	// stwx r9,r6,r10
	PPC_STORE_U32(ctx.r6.u32 + ctx.r10.u32, ctx.r9.u32);
loc_88098764:
	// lwz r9,15016(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 15016);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8809878c
	if (ctx.cr6.eq) goto loc_8809878C;
	// cmpwi cr6,r11,3000
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3000, ctx.xer);
	// bge cr6,0x8809878c
	if (!ctx.cr6.lt) goto loc_8809878C;
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r8.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-104(r10)
	PPC_STORE_U32(ctx.r10.u32 + -104, ctx.r11.u32);
	// stwx r9,r6,r10
	PPC_STORE_U32(ctx.r6.u32 + ctx.r10.u32, ctx.r9.u32);
loc_8809878C:
	// lwz r9,15160(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 15160);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x880987b4
	if (ctx.cr6.eq) goto loc_880987B4;
	// cmpwi cr6,r11,3000
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3000, ctx.xer);
	// bge cr6,0x880987b4
	if (!ctx.cr6.lt) goto loc_880987B4;
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r8.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-104(r10)
	PPC_STORE_U32(ctx.r10.u32 + -104, ctx.r11.u32);
	// stwx r9,r6,r10
	PPC_STORE_U32(ctx.r6.u32 + ctx.r10.u32, ctx.r9.u32);
loc_880987B4:
	// lwz r9,15304(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 15304);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x880987dc
	if (ctx.cr6.eq) goto loc_880987DC;
	// cmpwi cr6,r11,3000
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3000, ctx.xer);
	// bge cr6,0x880987dc
	if (!ctx.cr6.lt) goto loc_880987DC;
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r8.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-104(r10)
	PPC_STORE_U32(ctx.r10.u32 + -104, ctx.r11.u32);
	// stwx r9,r6,r10
	PPC_STORE_U32(ctx.r6.u32 + ctx.r10.u32, ctx.r9.u32);
loc_880987DC:
	// lwz r9,15448(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 15448);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// cmpwi cr6,r11,3000
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3000, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r8.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-104(r10)
	PPC_STORE_U32(ctx.r10.u32 + -104, ctx.r11.u32);
	// stwx r9,r7,r10
	PPC_STORE_U32(ctx.r7.u32 + ctx.r10.u32, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88098808"))) PPC_WEAK_FUNC(sub_88098808);
PPC_FUNC_IMPL(__imp__sub_88098808) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r5,4(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne cr6,0x88098864
	if (!ctx.cr6.eq) goto loc_88098864;
	// addi r10,r11,-11984
	ctx.r10.s64 = ctx.r11.s64 + -11984;
	// lwz r11,-1972(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -1972);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r10,4
	ctx.r10.s64 = 262144;
	// lis r9,4
	ctx.r9.s64 = 262144;
	// ori r8,r10,33876
	ctx.r8.u64 = ctx.r10.u64 | 33876;
	// ori r7,r9,33872
	ctx.r7.u64 = ctx.r9.u64 | 33872;
	// li r6,304
	ctx.r6.s64 = 304;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// stwx r6,r11,r8
	PPC_STORE_U32(ctx.r11.u32 + ctx.r8.u32, ctx.r6.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stwx r5,r11,r7
	PPC_STORE_U32(ctx.r11.u32 + ctx.r7.u32, ctx.r5.u32);
	// b 0x8815d040
	sub_8815D040(ctx, base);
	return;
loc_88098864:
	// addi r11,r11,-11984
	ctx.r11.s64 = ctx.r11.s64 + -11984;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r10,84(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x88098888
	if (!ctx.cr6.eq) goto loc_88098888;
	// lwz r6,16(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// li r3,304
	ctx.r3.s64 = 304;
	// lwz r4,8(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// b 0x8815d688
	sub_8815D688(ctx, base);
	return;
loc_88098888:
	// lwz r11,-1972(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -1972);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r10,4
	ctx.r10.s64 = 262144;
	// lis r9,4
	ctx.r9.s64 = 262144;
	// ori r8,r10,33876
	ctx.r8.u64 = ctx.r10.u64 | 33876;
	// ori r7,r9,33872
	ctx.r7.u64 = ctx.r9.u64 | 33872;
	// li r6,304
	ctx.r6.s64 = 304;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// stwx r6,r11,r8
	PPC_STORE_U32(ctx.r11.u32 + ctx.r8.u32, ctx.r6.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stwx r5,r11,r7
	PPC_STORE_U32(ctx.r11.u32 + ctx.r7.u32, ctx.r5.u32);
	// b 0x8815d040
	sub_8815D040(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880988C0"))) PPC_WEAK_FUNC(sub_880988C0);
PPC_FUNC_IMPL(__imp__sub_880988C0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880988C4"))) PPC_WEAK_FUNC(sub_880988C4);
PPC_FUNC_IMPL(__imp__sub_880988C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880988C8"))) PPC_WEAK_FUNC(sub_880988C8);
PPC_FUNC_IMPL(__imp__sub_880988C8) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// li r30,1
	ctx.r30.s64 = 1;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-30683
	ctx.r10.s64 = -2010841088;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r10,13848
	ctx.r8.s64 = ctx.r10.s64 + 13848;
	// stw r30,15604(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15604, ctx.r30.u32);
	// lwzx r5,r9,r8
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// bl 0x88095178
	ctx.lr = 0x88098904;
	sub_88095178(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r30,15600(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15600, ctx.r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,14684(r31)
	PPC_STORE_U32(ctx.r31.u32 + 14684, ctx.r7.u32);
	// stw r30,14700(r31)
	PPC_STORE_U32(ctx.r31.u32 + 14700, ctx.r30.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x880991d8
	ctx.lr = 0x88098920;
	sub_880991D8(ctx, base);
	// addi r3,r31,15632
	ctx.r3.s64 = ctx.r31.s64 + 15632;
	// bl 0x88098808
	ctx.lr = 0x88098928;
	sub_88098808(ctx, base);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x88096e80
	ctx.lr = 0x88098930;
	sub_88096E80(ctx, base);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x880967b8
	ctx.lr = 0x88098938;
	sub_880967B8(ctx, base);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x88096ac0
	ctx.lr = 0x88098940;
	sub_88096AC0(ctx, base);
	// lis r6,-30689
	ctx.r6.s64 = -2011234304;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// addi r4,r6,-27392
	ctx.r4.s64 = ctx.r6.s64 + -27392;
	// bl 0x880969a8
	ctx.lr = 0x88098954;
	sub_880969A8(ctx, base);
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addi r11,r11,-16616
	ctx.r11.s64 = ctx.r11.s64 + -16616;
	// lwz r10,5876(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 5876);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88098990
	if (ctx.cr6.eq) goto loc_88098990;
	// lwz r10,5868(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 5868);
	// cmplwi cr6,r10,6
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 6, ctx.xer);
	// ble cr6,0x88098990
	if (!ctx.cr6.gt) goto loc_88098990;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 48);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8809898c
	if (!ctx.cr6.eq) goto loc_8809898C;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x8808d1b8
	ctx.lr = 0x88098988;
	sub_8808D1B8(ctx, base);
	// b 0x88098990
	goto loc_88098990;
loc_8809898C:
	// stw r30,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r30.u32);
loc_88098990:
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

__attribute__((alias("__imp__sub_880989A8"))) PPC_WEAK_FUNC(sub_880989A8);
PPC_FUNC_IMPL(__imp__sub_880989A8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880989B0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r11,-30642
	ctx.r11.s64 = -2008154112;
	// addi r29,r11,-32760
	ctx.r29.s64 = ctx.r11.s64 + -32760;
	// lwz r11,15600(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 15600);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88098bd4
	if (!ctx.cr6.eq) goto loc_88098BD4;
	// lwz r11,15652(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 15652);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88098ae0
	if (ctx.cr6.eq) goto loc_88098AE0;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r11,r31,14584
	ctx.r11.s64 = ctx.r31.s64 + 14584;
	// stw r9,14696(r31)
	PPC_STORE_U32(ctx.r31.u32 + 14696, ctx.r9.u32);
	// lwz r10,15604(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 15604);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x88098ae0
	if (!ctx.cr6.eq) goto loc_88098AE0;
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 100);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x88098ae0
	if (!ctx.cr6.gt) goto loc_88098AE0;
	// lwz r8,15624(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 15624);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x88098a18
	if (!ctx.cr6.eq) goto loc_88098A18;
	// lwz r8,15652(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 15652);
	// subf r7,r8,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r7,100(r11)
	PPC_STORE_U32(ctx.r11.u32 + 100, ctx.r7.u32);
loc_88098A18:
	// lwz r10,15608(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 15608);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x88098ae0
	if (!ctx.cr6.eq) goto loc_88098AE0;
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 100);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bgt cr6,0x88098ae0
	if (ctx.cr6.gt) goto loc_88098AE0;
	// lwz r10,-6020(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + -6020);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x88098a48
	if (!ctx.cr6.eq) goto loc_88098A48;
	// li r10,512
	ctx.r10.s64 = 512;
	// stw r10,100(r11)
	PPC_STORE_U32(ctx.r11.u32 + 100, ctx.r10.u32);
	// b 0x88098ae0
	goto loc_88098AE0;
loc_88098A48:
	// stw r9,15632(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15632, ctx.r9.u32);
	// addi r4,r31,15656
	ctx.r4.s64 = ctx.r31.s64 + 15656;
	// lwz r11,15664(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 15664);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88098a64
	if (!ctx.cr6.eq) goto loc_88098A64;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// b 0x88098a68
	goto loc_88098A68;
loc_88098A64:
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
loc_88098A68:
	// stw r11,15636(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15636, ctx.r11.u32);
	// lwz r11,15664(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 15664);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r10,15640(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15640, ctx.r10.u32);
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// beq cr6,0x88098a8c
	if (ctx.cr6.eq) goto loc_88098A8C;
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// bne cr6,0x88098a94
	if (!ctx.cr6.eq) goto loc_88098A94;
loc_88098A8C:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// b 0x88098a98
	goto loc_88098A98;
loc_88098A94:
	// lwz r11,164(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_88098A98:
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r10,2332(r8)
	PPC_STORE_U32(ctx.r8.u32 + 2332, ctx.r10.u32);
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// stw r11,2328(r8)
	PPC_STORE_U32(ctx.r8.u32 + 2328, ctx.r11.u32);
	// lwz r11,15664(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 15664);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88098ab8
	if (ctx.cr6.eq) goto loc_88098AB8;
	// lwz r10,164(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_88098AB8:
	// stw r10,15644(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15644, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88098acc
	if (!ctx.cr6.eq) goto loc_88098ACC;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// b 0x88098ad0
	goto loc_88098AD0;
loc_88098ACC:
	// lwz r11,176(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
loc_88098AD0:
	// stw r11,15648(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15648, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,15612(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15612, ctx.r9.u32);
	// bl 0x880988c8
	ctx.lr = 0x88098AE0;
	sub_880988C8(ctx, base);
loc_88098AE0:
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// stw r30,15652(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15652, ctx.r30.u32);
	// lis r8,192
	ctx.r8.s64 = 12582912;
	// lis r10,128
	ctx.r10.s64 = 8388608;
	// lis r3,255
	ctx.r3.s64 = 16711680;
	// ori r5,r8,49152
	ctx.r5.u64 = ctx.r8.u64 | 49152;
	// lwz r4,26428(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26428);
	// addi r9,r31,14584
	ctx.r9.s64 = ctx.r31.s64 + 14584;
	// li r6,7
	ctx.r6.s64 = 7;
	// ori r7,r10,32896
	ctx.r7.u64 = ctx.r10.u64 | 32896;
	// ori r8,r3,4112
	ctx.r8.u64 = ctx.r3.u64 | 4112;
loc_88098B0C:
	// lwz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// stw r7,120(r9)
	PPC_STORE_U32(ctx.r9.u32 + 120, ctx.r7.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88098b44
	if (ctx.cr6.eq) goto loc_88098B44;
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88098b44
	if (ctx.cr6.eq) goto loc_88098B44;
loc_88098B2C:
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// stw r30,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r30.u32);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// or r10,r3,r10
	ctx.r10.u64 = ctx.r3.u64 | ctx.r10.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88098b2c
	if (!ctx.cr6.eq) goto loc_88098B2C;
loc_88098B44:
	// clrlwi r11,r10,20
	ctx.r11.u64 = ctx.r10.u32 & 0xFFF;
	// rlwinm r11,r11,0,26,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFC3F;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88098b78
	if (ctx.cr6.eq) goto loc_88098B78;
	// lwz r11,124(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 124);
	// stw r30,112(r9)
	PPC_STORE_U32(ctx.r9.u32 + 112, ctx.r30.u32);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,124(r9)
	PPC_STORE_U32(ctx.r9.u32 + 124, ctx.r11.u32);
	// beq cr6,0x88098bc8
	if (ctx.cr6.eq) goto loc_88098BC8;
	// stw r5,120(r9)
	PPC_STORE_U32(ctx.r9.u32 + 120, ctx.r5.u32);
	// b 0x88098bc8
	goto loc_88098BC8;
loc_88098B78:
	// lwz r11,100(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 100);
	// lwz r10,108(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 108);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x88098bc8
	if (!ctx.cr6.lt) goto loc_88098BC8;
	// rlwinm r11,r4,0,28,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xE;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88098bc8
	if (!ctx.cr6.eq) goto loc_88098BC8;
	// lwz r11,136(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 136);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88098bb8
	if (ctx.cr6.eq) goto loc_88098BB8;
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r31,14560
	ctx.r11.s64 = ctx.r31.s64 + 14560;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_88098BAC:
	// stwu r8,144(r11)
	ea = 144 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x88098bac
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88098BAC;
	// b 0x88098bc8
	goto loc_88098BC8;
loc_88098BB8:
	// lwz r11,116(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 116);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88098bc8
	if (!ctx.cr6.eq) goto loc_88098BC8;
	// stw r8,120(r9)
	PPC_STORE_U32(ctx.r9.u32 + 120, ctx.r8.u32);
loc_88098BC8:
	// addic. r6,r6,-1
	ctx.xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// addi r9,r9,144
	ctx.r9.s64 = ctx.r9.s64 + 144;
	// bne 0x88098b0c
	if (!ctx.cr0.eq) goto loc_88098B0C;
loc_88098BD4:
	// lwz r10,14684(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 14684);
	// lwz r11,15616(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 15616);
	// subfic r9,r10,0
	ctx.xer.ca = ctx.r10.u32 <= 0;
	ctx.r9.s64 = 0 - ctx.r10.s64;
	// rlwinm r8,r10,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// addme r7,r8
	{ uint8_t _ca = (ctx.r8.u32 + 0xFFFFFFFF < ctx.r8.u32) | (ctx.r8.u32 + 0xFFFFFFFF + ctx.xer.ca < ctx.xer.ca); // FIX 2026-07-24: insn was silently dropped by the recompiler
	ctx.r7.u64 = ctx.r8.u64 + 0xFFFFFFFFFFFFFFFFull + ctx.xer.ca;
	ctx.xer.ca = _ca; }
	// stw r11,40(r29)
	PPC_STORE_U32(ctx.r29.u32 + 40, ctx.r11.u32);
	// and r11,r7,r10
	ctx.r11.u64 = ctx.r7.u64 & ctx.r10.u64;
	// stw r11,72(r29)
	PPC_STORE_U32(ctx.r29.u32 + 72, ctx.r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88098BFC"))) PPC_WEAK_FUNC(sub_88098BFC);
PPC_FUNC_IMPL(__imp__sub_88098BFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88098C00"))) PPC_WEAK_FUNC(sub_88098C00);
PPC_FUNC_IMPL(__imp__sub_88098C00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x88098C08;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30710
	ctx.r11.s64 = -2012610560;
	// li r4,15768
	ctx.r4.s64 = 15768;
	// addi r5,r11,-29696
	ctx.r5.s64 = ctx.r11.s64 + -29696;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x88098C20;
	sub_88094290(ctx, base);
	// li r5,15768
	ctx.r5.s64 = 15768;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,2304(r27)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r27.u32 + 2304);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x88098C34;
	sub_88073BD0(ctx, base);
	// lis r9,-30641
	ctx.r9.s64 = -2008088576;
	// li r10,8
	ctx.r10.s64 = 8;
	// addi r11,r9,-18792
	ctx.r11.s64 = ctx.r9.s64 + -18792;
	// li r26,0
	ctx.r26.s64 = 0;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_88098C50:
	// stbu r9,1(r11)
	ea = 1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r9.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x88098c50
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88098C50;
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lis r10,-30710
	ctx.r10.s64 = -2012610560;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r4,r10,-31104
	ctx.r4.s64 = ctx.r10.s64 + -31104;
	// lwz r30,-11984(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11984);
	// lwz r9,84(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 84);
	// stw r9,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r9.u32);
	// bl 0x88096200
	ctx.lr = 0x88098C78;
	sub_88096200(ctx, base);
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r10,-30683
	ctx.r10.s64 = -2010841088;
	// stw r27,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r27.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r30,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// ori r11,r8,61248
	ctx.r11.u64 = ctx.r8.u64 | 61248;
	// stw r3,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r3.u32);
	// addi r9,r10,14872
	ctx.r9.s64 = ctx.r10.s64 + 14872;
	// stw r7,14720(r31)
	PPC_STORE_U32(ctx.r31.u32 + 14720, ctx.r7.u32);
	// lwz r7,32(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
	// addi r10,r9,-208
	ctx.r10.s64 = ctx.r9.s64 + -208;
	// cmplwi cr6,r7,1
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 1, ctx.xer);
	// blt cr6,0x88098cd8
	if (ctx.cr6.lt) goto loc_88098CD8;
	// beq cr6,0x88098cd0
	if (ctx.cr6.eq) goto loc_88098CD0;
	// cmplwi cr6,r7,3
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 3, ctx.xer);
	// bge cr6,0x88098ce0
	if (!ctx.cr6.lt) goto loc_88098CE0;
	// lis r11,1
	ctx.r11.s64 = 65536;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// ori r11,r11,6848
	ctx.r11.u64 = ctx.r11.u64 | 6848;
	// b 0x88098cdc
	goto loc_88098CDC;
loc_88098CD0:
	// addi r10,r9,-104
	ctx.r10.s64 = ctx.r9.s64 + -104;
	// b 0x88098cdc
	goto loc_88098CDC;
loc_88098CD8:
	// addi r10,r9,-208
	ctx.r10.s64 = ctx.r9.s64 + -208;
loc_88098CDC:
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
loc_88098CE0:
	// srawi r8,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 2;
	// li r9,5
	ctx.r9.s64 = 5;
	// addze r7,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r7.s64 = temp.s64;
	// mr r28,r10
	ctx.r28.u64 = ctx.r10.u64;
	// stw r7,14692(r31)
	PPC_STORE_U32(ctx.r31.u32 + 14692, ctx.r7.u32);
	// addi r10,r10,-16
	ctx.r10.s64 = ctx.r10.s64 + -16;
	// stw r11,15616(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15616, ctx.r11.u32);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_88098D00:
	// lwz r11,16(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lwzu r9,20(r10)
	ea = 20 + ctx.r10.u32;
	ctx.r9.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// rlwinm r8,r11,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// rotlwi r8,r9,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// srawi r7,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 2;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addze r6,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r6.s64 = temp.s64;
	// addi r11,r11,14584
	ctx.r11.s64 = ctx.r11.s64 + 14584;
	// stw r9,100(r11)
	PPC_STORE_U32(ctx.r11.u32 + 100, ctx.r9.u32);
	// stw r9,104(r11)
	PPC_STORE_U32(ctx.r11.u32 + 104, ctx.r9.u32);
	// stw r6,108(r11)
	PPC_STORE_U32(ctx.r11.u32 + 108, ctx.r6.u32);
	// bdnz 0x88098d00
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88098D00;
	// lis r11,-30689
	ctx.r11.s64 = -2011234304;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-26624
	ctx.r4.s64 = ctx.r11.s64 + -26624;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x880969a8
	ctx.lr = 0x88098D4C;
	sub_880969A8(ctx, base);
	// stw r26,15628(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15628, ctx.r26.u32);
	// stw r26,15624(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15624, ctx.r26.u32);
	// lis r10,-30689
	ctx.r10.s64 = -2011234304;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-30320
	ctx.r4.s64 = ctx.r10.s64 + -30320;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x880969a8
	ctx.lr = 0x88098D68;
	sub_880969A8(ctx, base);
	// li r10,462
	ctx.r10.s64 = 462;
	// li r9,130
	ctx.r9.s64 = 130;
	// stw r26,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r26.u32);
	// lis r8,120
	ctx.r8.s64 = 7864320;
	// stw r9,168(r27)
	PPC_STORE_U32(ctx.r27.u32 + 168, ctx.r9.u32);
	// lis r7,444
	ctx.r7.s64 = 29097984;
	// li r6,16
	ctx.r6.s64 = 16;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// addi r11,r31,10884
	ctx.r11.s64 = ctx.r31.s64 + 10884;
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r5,r10,55
	ctx.r5.s64 = ctx.r10.s64 + 55;
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r4,r30
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r30.u32);
	// subf r10,r3,r8
	ctx.r10.s64 = ctx.r8.s64 - ctx.r3.s64;
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// stw r7,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r7.u32);
	// stw r6,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r6.u32);
loc_88098DAC:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// stwu r9,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x88098dac
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88098DAC;
	// li r10,21
	ctx.r10.s64 = 21;
	// addi r11,r31,9612
	ctx.r11.s64 = ctx.r31.s64 + 9612;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_88098DCC:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// stw r10,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// stwu r9,20(r11)
	ea = 20 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x88098dcc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88098DCC;
	// li r10,300
	ctx.r10.s64 = 300;
	// li r9,344
	ctx.r9.s64 = 344;
	// li r8,388
	ctx.r8.s64 = 388;
	// stw r10,2744(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2744, ctx.r10.u32);
	// li r7,432
	ctx.r7.s64 = 432;
	// stw r9,3032(r31)
	PPC_STORE_U32(ctx.r31.u32 + 3032, ctx.r9.u32);
	// li r10,652
	ctx.r10.s64 = 652;
	// stw r8,3320(r31)
	PPC_STORE_U32(ctx.r31.u32 + 3320, ctx.r8.u32);
	// stw r7,3608(r31)
	PPC_STORE_U32(ctx.r31.u32 + 3608, ctx.r7.u32);
	// li r6,476
	ctx.r6.s64 = 476;
	// li r5,520
	ctx.r5.s64 = 520;
	// stw r10,6200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 6200, ctx.r10.u32);
	// li r4,564
	ctx.r4.s64 = 564;
	// stw r6,5048(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5048, ctx.r6.u32);
	// li r3,608
	ctx.r3.s64 = 608;
	// stw r5,5336(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5336, ctx.r5.u32);
	// li r9,696
	ctx.r9.s64 = 696;
	// stw r4,5624(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5624, ctx.r4.u32);
	// li r8,740
	ctx.r8.s64 = 740;
	// stw r3,5912(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5912, ctx.r3.u32);
	// li r7,784
	ctx.r7.s64 = 784;
	// stw r9,6488(r31)
	PPC_STORE_U32(ctx.r31.u32 + 6488, ctx.r9.u32);
	// li r10,1004
	ctx.r10.s64 = 1004;
	// stw r8,6776(r31)
	PPC_STORE_U32(ctx.r31.u32 + 6776, ctx.r8.u32);
	// stw r7,7064(r31)
	PPC_STORE_U32(ctx.r31.u32 + 7064, ctx.r7.u32);
	// li r11,256
	ctx.r11.s64 = 256;
	// li r6,828
	ctx.r6.s64 = 828;
	// stw r10,8504(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8504, ctx.r10.u32);
	// li r5,872
	ctx.r5.s64 = 872;
	// stw r11,2456(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2456, ctx.r11.u32);
	// li r4,916
	ctx.r4.s64 = 916;
	// stw r6,7352(r31)
	PPC_STORE_U32(ctx.r31.u32 + 7352, ctx.r6.u32);
	// li r3,960
	ctx.r3.s64 = 960;
	// stw r5,7640(r31)
	PPC_STORE_U32(ctx.r31.u32 + 7640, ctx.r5.u32);
	// li r7,1136
	ctx.r7.s64 = 1136;
	// stw r4,7928(r31)
	PPC_STORE_U32(ctx.r31.u32 + 7928, ctx.r4.u32);
	// li r9,1048
	ctx.r9.s64 = 1048;
	// stw r3,8216(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8216, ctx.r3.u32);
	// li r8,1092
	ctx.r8.s64 = 1092;
	// stw r7,9368(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9368, ctx.r7.u32);
	// li r10,275
	ctx.r10.s64 = 275;
	// stw r9,8792(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8792, ctx.r9.u32);
	// stw r8,9080(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9080, ctx.r8.u32);
	// mr r6,r11
	ctx.r6.u64 = ctx.r11.u64;
	// stw r11,252(r31)
	PPC_STORE_U32(ctx.r31.u32 + 252, ctx.r11.u32);
	// li r7,-1
	ctx.r7.s64 = -1;
	// stw r11,256(r31)
	PPC_STORE_U32(ctx.r31.u32 + 256, ctx.r11.u32);
	// addi r11,r31,184
	ctx.r11.s64 = ctx.r31.s64 + 184;
	// stw r10,1388(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1388, ctx.r10.u32);
	// lis r5,96
	ctx.r5.s64 = 6291456;
	// stw r10,1392(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1392, ctx.r10.u32);
	// li r30,272
	ctx.r30.s64 = 272;
	// li r3,240
	ctx.r3.s64 = 240;
	// li r4,4
	ctx.r4.s64 = 4;
loc_88098EB8:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// rlwinm r9,r7,20,0,11
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 20) & 0xFFF00000;
	// cmpwi cr6,r7,-1
	ctx.cr6.compare<int32_t>(ctx.r7.s32, -1, ctx.xer);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r10,-32(r11)
	PPC_STORE_U32(ctx.r11.u32 + -32, ctx.r10.u32);
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// subf r8,r5,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r5.s64;
	// stw r8,-28(r11)
	PPC_STORE_U32(ctx.r11.u32 + -28, ctx.r8.u32);
	// bne cr6,0x88098ee8
	if (!ctx.cr6.eq) goto loc_88098EE8;
	// stw r30,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r30.u32);
	// stw r26,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r26.u32);
	// b 0x88098ef0
	goto loc_88098EF0;
loc_88098EE8:
	// stw r3,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
	// stw r4,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r4.u32);
loc_88098EF0:
	// li r8,21
	ctx.r8.s64 = 21;
	// addi r9,r11,64
	ctx.r9.s64 = ctx.r11.s64 + 64;
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_88098F00:
	// stwu r10,48(r9)
	ea = 48 + ctx.r9.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r9.u32 = ea;
	// addi r10,r10,44
	ctx.r10.s64 = ctx.r10.s64 + 44;
	// bdnz 0x88098f00
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88098F00;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// neg r7,r7
	ctx.r7.s64 = -ctx.r7.s64;
	// addi r11,r11,1136
	ctx.r11.s64 = ctx.r11.s64 + 1136;
	// cmpwi cr6,r6,264
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 264, ctx.xer);
	// blt cr6,0x88098eb8
	if (ctx.cr6.lt) goto loc_88098EB8;
	// lis r11,-30710
	ctx.r11.s64 = -2012610560;
	// lis r10,-30710
	ctx.r10.s64 = -2012610560;
	// addi r9,r11,-30296
	ctx.r9.s64 = ctx.r11.s64 + -30296;
	// addi r8,r10,-31016
	ctx.r8.s64 = ctx.r10.s64 + -31016;
	// stw r9,64(r27)
	PPC_STORE_U32(ctx.r27.u32 + 64, ctx.r9.u32);
	// addi r30,r28,16
	ctx.r30.s64 = ctx.r28.s64 + 16;
	// stw r8,84(r27)
	PPC_STORE_U32(ctx.r27.u32 + 84, ctx.r8.u32);
	// li r29,5
	ctx.r29.s64 = 5;
loc_88098F40:
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x881556a0
	ctx.lr = 0x88098F4C;
	sub_881556A0(ctx, base);
	// lwz r11,-16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -16);
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r11,r31
	ctx.r10.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stw r3,14584(r10)
	PPC_STORE_U32(ctx.r10.u32 + 14584, ctx.r3.u32);
	// lwz r8,-8(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + -8);
	// lwz r11,-16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -16);
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r7,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// add r6,r11,r31
	ctx.r6.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lwz r5,14584(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 14584);
	// stw r8,32(r5)
	PPC_STORE_U32(ctx.r5.u32 + 32, ctx.r8.u32);
	// stw r27,36(r5)
	PPC_STORE_U32(ctx.r5.u32 + 36, ctx.r27.u32);
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// lwz r11,-4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -4);
	// ble cr6,0x8809906c
	if (!ctx.cr6.gt) goto loc_8809906C;
	// addi r10,r11,-4
	ctx.r10.s64 = ctx.r11.s64 + -4;
loc_88098FA0:
	// lwz r11,-16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -16);
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// rlwinm r7,r11,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r7,r11,r31
	ctx.r7.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lwz r7,14584(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + 14584);
	// lwz r11,28(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88098fe0
	if (ctx.cr6.eq) goto loc_88098FE0;
loc_88098FC8:
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x880990e8
	if (ctx.cr6.eq) goto loc_880990E8;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88098fc8
	if (!ctx.cr6.eq) goto loc_88098FC8;
loc_88098FE0:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_88098FE4:
	// lwz r8,12(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r8,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// lwz r6,8(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// rlwinm r7,r8,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// add r7,r8,r7
	ctx.r7.u64 = ctx.r8.u64 + ctx.r7.u64;
	// rlwinm r8,r7,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r8,r6
	ctx.r6.u64 = ctx.r8.u64 + ctx.r6.u64;
	// rlwinm r8,r6,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// add r8,r8,r31
	ctx.r8.u64 = ctx.r8.u64 + ctx.r31.u64;
	// addi r5,r8,14588
	ctx.r5.s64 = ctx.r8.s64 + 14588;
	// stw r5,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r5.u32);
	// lwz r4,16(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// stw r4,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r4.u32);
	// lwz r3,20(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// stw r3,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r3.u32);
	// lhz r8,24(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 24);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// stw r7,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r7.u32);
	// lhz r6,26(r10)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r10.u32 + 26);
	// extsh r5,r6
	ctx.r5.s64 = ctx.r6.s16;
	// stw r5,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r5.u32);
	// lhz r4,28(r10)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + 28);
	// extsh r3,r4
	ctx.r3.s64 = ctx.r4.s16;
	// stw r3,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r3.u32);
	// lhz r8,30(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 30);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// stw r7,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r7.u32);
	// lwzu r8,32(r10)
	ea = 32 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// stw r8,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r8.u32);
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmpw cr6,r9,r6
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r6.s32, ctx.xer);
	// blt cr6,0x88098fa0
	if (ctx.cr6.lt) goto loc_88098FA0;
loc_8809906C:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r30,r30,20
	ctx.r30.s64 = ctx.r30.s64 + 20;
	// bne 0x88098f40
	if (!ctx.cr0.eq) goto loc_88098F40;
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r31,14560
	ctx.r11.s64 = ctx.r31.s64 + 14560;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lis r10,128
	ctx.r10.s64 = 8388608;
	// ori r10,r10,32896
	ctx.r10.u64 = ctx.r10.u64 | 32896;
loc_8809908C:
	// stwu r10,144(r11)
	ea = 144 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8809908c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8809908C;
	// lis r11,-30642
	ctx.r11.s64 = -2008154112;
	// li r8,8
	ctx.r8.s64 = 8;
	// addi r9,r11,-32760
	ctx.r9.s64 = ctx.r11.s64 + -32760;
	// addi r10,r9,118
	ctx.r10.s64 = ctx.r9.s64 + 118;
	// addi r11,r9,68
	ctx.r11.s64 = ctx.r9.s64 + 68;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_880990AC:
	// stw r26,-28(r11)
	PPC_STORE_U32(ctx.r11.u32 + -28, ctx.r26.u32);
	// stwu r26,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r26.u32);
	ctx.r11.u32 = ea;
	// sth r26,-14(r10)
	PPC_STORE_U16(ctx.r10.u32 + -14, ctx.r26.u16);
	// sthu r26,2(r10)
	ea = 2 + ctx.r10.u32;
	PPC_STORE_U16(ea, ctx.r26.u16);
	ctx.r10.u32 = ea;
	// bdnz 0x880990ac
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_880990AC;
	// lis r8,-30633
	ctx.r8.s64 = -2007564288;
	// lis r7,-30633
	ctx.r7.s64 = -2007564288;
	// li r11,1
	ctx.r11.s64 = 1;
	// mr r10,r26
	ctx.r10.u64 = ctx.r26.u64;
	// stw r11,136(r9)
	PPC_STORE_U32(ctx.r9.u32 + 136, ctx.r11.u32);
	// stw r26,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r26.u32);
	// stw r26,-29732(r8)
	PPC_STORE_U32(ctx.r8.u32 + -29732, ctx.r26.u32);
	// stw r11,-29780(r7)
	PPC_STORE_U32(ctx.r7.u32 + -29780, ctx.r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_880990E8:
	// lwz r8,24(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x880990f8
	if (ctx.cr6.eq) goto loc_880990F8;
	// stw r8,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r8.u32);
loc_880990F8:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x88098fe4
	goto loc_88098FE4;
}

__attribute__((alias("__imp__sub_88099100"))) PPC_WEAK_FUNC(sub_88099100);
PPC_FUNC_IMPL(__imp__sub_88099100) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r11,r5,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,2304(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 2304);
	// li r9,1
	ctx.r9.s64 = 1;
	// add r11,r5,r11
	ctx.r11.u64 = ctx.r5.u64 + ctx.r11.u64;
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r11,r11,14584
	ctx.r11.s64 = ctx.r11.s64 + 14584;
	// stw r9,112(r11)
	PPC_STORE_U32(ctx.r11.u32 + 112, ctx.r9.u32);
	// lwz r10,15604(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 15604);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x88099170
	if (!ctx.cr6.eq) goto loc_88099170;
	// lwz r10,140(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 140);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x88099170
	if (!ctx.cr6.eq) goto loc_88099170;
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 100);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x88099170
	if (!ctx.cr6.gt) goto loc_88099170;
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// subf. r7,r8,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r8.s64;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stw r7,100(r11)
	PPC_STORE_U32(ctx.r11.u32 + 100, ctx.r7.u32);
	// bgt 0x88099170
	if (ctx.cr0.gt) goto loc_88099170;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r9,116(r11)
	PPC_STORE_U32(ctx.r11.u32 + 116, ctx.r9.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,100(r11)
	PPC_STORE_U32(ctx.r11.u32 + 100, ctx.r10.u32);
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// blr 
	return;
loc_88099170:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88099178"))) PPC_WEAK_FUNC(sub_88099178);
PPC_FUNC_IMPL(__imp__sub_88099178) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
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
	// lwz r10,2304(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 2304);
	// rlwinm r9,r11,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x880991a4
	if (ctx.cr6.eq) goto loc_880991A4;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
loc_880991A4:
	// lwz r9,15652(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 15652);
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// ble cr6,0x880991c4
	if (!ctx.cr6.gt) goto loc_880991C4;
	// stw r11,15652(r10)
	PPC_STORE_U32(ctx.r10.u32 + 15652, ctx.r11.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r3,r10,15656
	ctx.r3.s64 = ctx.r10.s64 + 15656;
	// bl 0x88072260
	ctx.lr = 0x880991C4;
	sub_88072260(ctx, base);
loc_880991C4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880991D8"))) PPC_WEAK_FUNC(sub_880991D8);
PPC_FUNC_IMPL(__imp__sub_880991D8) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,2304(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r11,14584(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 14584);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880991ec
	if (ctx.cr6.eq) goto loc_880991EC;
	// stw r4,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r4.u32);
loc_880991EC:
	// lwz r11,14728(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 14728);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880991fc
	if (ctx.cr6.eq) goto loc_880991FC;
	// stw r4,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r4.u32);
loc_880991FC:
	// lwz r11,14872(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 14872);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809920c
	if (ctx.cr6.eq) goto loc_8809920C;
	// stw r4,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r4.u32);
loc_8809920C:
	// lwz r11,15016(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 15016);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809921c
	if (ctx.cr6.eq) goto loc_8809921C;
	// stw r4,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r4.u32);
loc_8809921C:
	// lwz r11,15160(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 15160);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809922c
	if (ctx.cr6.eq) goto loc_8809922C;
	// stw r4,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r4.u32);
loc_8809922C:
	// lwz r11,15304(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 15304);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809923c
	if (ctx.cr6.eq) goto loc_8809923C;
	// stw r4,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r4.u32);
loc_8809923C:
	// lwz r11,15448(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 15448);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r4,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88099250"))) PPC_WEAK_FUNC(sub_88099250);
PPC_FUNC_IMPL(__imp__sub_88099250) {
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
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// li r5,6
	ctx.r5.s64 = 6;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// bl 0x88099100
	ctx.lr = 0x88099270;
	sub_88099100(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x880992f0
	if (!ctx.cr6.eq) goto loc_880992F0;
	// lwz r31,2304(r4)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r4.u32 + 2304);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,15748(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15748, ctx.r11.u32);
	// lwz r11,8(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88099294
	if (ctx.cr6.eq) goto loc_88099294;
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
loc_88099294:
	// stw r11,15752(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15752, ctx.r11.u32);
	// lwz r11,8(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// stw r11,15756(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15756, ctx.r11.u32);
	// lwz r11,8(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880992b0
	if (ctx.cr6.eq) goto loc_880992B0;
	// lwz r11,164(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_880992B0:
	// stw r11,15760(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15760, ctx.r11.u32);
	// lwz r11,8(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880992c4
	if (ctx.cr6.eq) goto loc_880992C4;
	// lwz r11,176(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
loc_880992C4:
	// stw r11,15764(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15764, ctx.r11.u32);
	// lis r5,2
	ctx.r5.s64 = 131072;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// ori r5,r5,18928
	ctx.r5.u64 = ctx.r5.u64 | 18928;
	// bl 0x88095178
	ctx.lr = 0x880992DC;
	sub_88095178(ctx, base);
	// lis r11,-30697
	ctx.r11.s64 = -2011758592;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// addi r4,r11,-9872
	ctx.r4.s64 = ctx.r11.s64 + -9872;
	// bl 0x88096cb8
	ctx.lr = 0x880992F0;
	sub_88096CB8(ctx, base);
loc_880992F0:
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

__attribute__((alias("__imp__sub_88099308"))) PPC_WEAK_FUNC(sub_88099308);
PPC_FUNC_IMPL(__imp__sub_88099308) {
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
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// li r5,5
	ctx.r5.s64 = 5;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// bl 0x88099100
	ctx.lr = 0x88099328;
	sub_88099100(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x880993a8
	if (!ctx.cr6.eq) goto loc_880993A8;
	// lwz r31,2304(r4)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r4.u32 + 2304);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,15728(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15728, ctx.r11.u32);
	// lwz r11,8(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809934c
	if (ctx.cr6.eq) goto loc_8809934C;
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
loc_8809934C:
	// stw r11,15732(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15732, ctx.r11.u32);
	// lwz r11,8(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// stw r11,15736(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15736, ctx.r11.u32);
	// lwz r11,8(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88099368
	if (ctx.cr6.eq) goto loc_88099368;
	// lwz r11,164(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_88099368:
	// stw r11,15740(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15740, ctx.r11.u32);
	// lwz r11,8(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809937c
	if (ctx.cr6.eq) goto loc_8809937C;
	// lwz r11,176(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
loc_8809937C:
	// stw r11,15744(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15744, ctx.r11.u32);
	// lis r5,2
	ctx.r5.s64 = 131072;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// ori r5,r5,18928
	ctx.r5.u64 = ctx.r5.u64 | 18928;
	// bl 0x88095178
	ctx.lr = 0x88099394;
	sub_88095178(ctx, base);
	// lis r11,-30697
	ctx.r11.s64 = -2011758592;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// addi r4,r11,-9728
	ctx.r4.s64 = ctx.r11.s64 + -9728;
	// bl 0x88096cb8
	ctx.lr = 0x880993A8;
	sub_88096CB8(ctx, base);
loc_880993A8:
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

__attribute__((alias("__imp__sub_880993C0"))) PPC_WEAK_FUNC(sub_880993C0);
PPC_FUNC_IMPL(__imp__sub_880993C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
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
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,2304(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 2304);
	// rlwinm r9,r11,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x880993f0
	if (ctx.cr6.eq) goto loc_880993F0;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
loc_880993F0:
	// lwz r9,15652(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 15652);
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// ble cr6,0x8809940c
	if (!ctx.cr6.gt) goto loc_8809940C;
	// stw r11,15652(r10)
	PPC_STORE_U32(ctx.r10.u32 + 15652, ctx.r11.u32);
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r3,r10,15656
	ctx.r3.s64 = ctx.r10.s64 + 15656;
	// bl 0x88072260
	ctx.lr = 0x8809940C;
	sub_88072260(ctx, base);
loc_8809940C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88099420"))) PPC_WEAK_FUNC(sub_88099420);
PPC_FUNC_IMPL(__imp__sub_88099420) {
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
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// bl 0x88099100
	ctx.lr = 0x88099440;
	sub_88099100(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x880994c0
	if (!ctx.cr6.eq) goto loc_880994C0;
	// lwz r31,2304(r4)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r4.u32 + 2304);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,15708(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15708, ctx.r11.u32);
	// lwz r11,8(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88099464
	if (ctx.cr6.eq) goto loc_88099464;
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
loc_88099464:
	// stw r11,15712(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15712, ctx.r11.u32);
	// lwz r11,8(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// stw r11,15716(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15716, ctx.r11.u32);
	// lwz r11,8(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88099480
	if (ctx.cr6.eq) goto loc_88099480;
	// lwz r11,164(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_88099480:
	// stw r11,15720(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15720, ctx.r11.u32);
	// lwz r11,8(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88099494
	if (ctx.cr6.eq) goto loc_88099494;
	// lwz r11,176(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
loc_88099494:
	// stw r11,15724(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15724, ctx.r11.u32);
	// lis r5,2
	ctx.r5.s64 = 131072;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// ori r5,r5,18928
	ctx.r5.u64 = ctx.r5.u64 | 18928;
	// bl 0x88095178
	ctx.lr = 0x880994AC;
	sub_88095178(ctx, base);
	// lis r11,-30697
	ctx.r11.s64 = -2011758592;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// addi r4,r11,-6152
	ctx.r4.s64 = ctx.r11.s64 + -6152;
	// bl 0x88096cb8
	ctx.lr = 0x880994C0;
	sub_88096CB8(ctx, base);
loc_880994C0:
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

__attribute__((alias("__imp__sub_880994D8"))) PPC_WEAK_FUNC(sub_880994D8);
PPC_FUNC_IMPL(__imp__sub_880994D8) {
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
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// li r5,3
	ctx.r5.s64 = 3;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// bl 0x88099100
	ctx.lr = 0x880994F8;
	sub_88099100(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88099578
	if (!ctx.cr6.eq) goto loc_88099578;
	// lwz r31,2304(r4)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r4.u32 + 2304);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,15688(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15688, ctx.r11.u32);
	// lwz r11,8(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809951c
	if (ctx.cr6.eq) goto loc_8809951C;
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
loc_8809951C:
	// stw r11,15692(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15692, ctx.r11.u32);
	// lwz r11,8(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// stw r11,15696(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15696, ctx.r11.u32);
	// lwz r11,8(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88099538
	if (ctx.cr6.eq) goto loc_88099538;
	// lwz r11,164(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_88099538:
	// stw r11,15700(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15700, ctx.r11.u32);
	// lwz r11,8(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809954c
	if (ctx.cr6.eq) goto loc_8809954C;
	// lwz r11,176(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
loc_8809954C:
	// stw r11,15704(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15704, ctx.r11.u32);
	// lis r5,2
	ctx.r5.s64 = 131072;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// ori r5,r5,18928
	ctx.r5.u64 = ctx.r5.u64 | 18928;
	// bl 0x88095178
	ctx.lr = 0x88099564;
	sub_88095178(ctx, base);
	// lis r11,-30697
	ctx.r11.s64 = -2011758592;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// addi r4,r11,-6008
	ctx.r4.s64 = ctx.r11.s64 + -6008;
	// bl 0x88096cb8
	ctx.lr = 0x88099578;
	sub_88096CB8(ctx, base);
loc_88099578:
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

__attribute__((alias("__imp__sub_88099590"))) PPC_WEAK_FUNC(sub_88099590);
PPC_FUNC_IMPL(__imp__sub_88099590) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// li r10,8
	ctx.r10.s64 = 8;
	// addi r11,r11,-18792
	ctx.r11.s64 = ctx.r11.s64 + -18792;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_880995A8:
	// stbu r9,1(r11)
	ea = 1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r9.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x880995a8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_880995A8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880995B4"))) PPC_WEAK_FUNC(sub_880995B4);
PPC_FUNC_IMPL(__imp__sub_880995B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880995B8"))) PPC_WEAK_FUNC(sub_880995B8);
PPC_FUNC_IMPL(__imp__sub_880995B8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// lhz r10,5836(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 5836);
	// addi r9,r11,-18792
	ctx.r9.s64 = ctx.r11.s64 + -18792;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwz r11,4(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// clrlwi r10,r11,16
	ctx.r10.u64 = ctx.r11.u32 & 0xFFFF;
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,8840(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8840);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
loc_880995E4:
	// lhz r9,92(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 92);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x88099600
	if (ctx.cr6.eq) goto loc_88099600;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880995e4
	if (!ctx.cr6.eq) goto loc_880995E4;
	// blr 
	return;
loc_88099600:
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r10,96(r11)
	PPC_STORE_U16(ctx.r11.u32 + 96, ctx.r10.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8809960C"))) PPC_WEAK_FUNC(sub_8809960C);
PPC_FUNC_IMPL(__imp__sub_8809960C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88099610"))) PPC_WEAK_FUNC(sub_88099610);
PPC_FUNC_IMPL(__imp__sub_88099610) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// lhz r10,5836(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 5836);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwz r11,-18792(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -18792);
	// clrlwi r10,r11,16
	ctx.r10.u64 = ctx.r11.u32 & 0xFFFF;
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,8840(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8840);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
loc_88099638:
	// lhz r9,92(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 92);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x88099654
	if (ctx.cr6.eq) goto loc_88099654;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88099638
	if (!ctx.cr6.eq) goto loc_88099638;
	// blr 
	return;
loc_88099654:
	// sth r4,96(r11)
	PPC_STORE_U16(ctx.r11.u32 + 96, ctx.r4.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8809965C"))) PPC_WEAK_FUNC(sub_8809965C);
PPC_FUNC_IMPL(__imp__sub_8809965C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88099660"))) PPC_WEAK_FUNC(sub_88099660);
PPC_FUNC_IMPL(__imp__sub_88099660) {
	PPC_FUNC_PROLOGUE();
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// li r9,1
	ctx.r9.s64 = 1;
	// srawi r10,r11,3
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 3;
	// clrlwi r11,r10,26
	ctx.r11.u64 = ctx.r10.u32 & 0x3F;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r11,32
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 32, ctx.xer);
	// ble cr6,0x88099688
	if (!ctx.cr6.gt) goto loc_88099688;
	// subfic r11,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r11.s64 = 64 - ctx.r11.s64;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,-1
	ctx.r9.s64 = -1;
loc_88099688:
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// stw r10,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r10.u32);
	// stw r9,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88099698"))) PPC_WEAK_FUNC(sub_88099698);
PPC_FUNC_IMPL(__imp__sub_88099698) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071144
	ctx.lr = 0x880996A0;
	__savegprlr_23(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,352
	ctx.r11.s64 = 23068672;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// mr r31,r7
	ctx.r31.u64 = ctx.r7.u64;
	// mr r24,r8
	ctx.r24.u64 = ctx.r8.u64;
	// cmpw cr6,r6,r11
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r11.s32, ctx.xer);
	// bgt cr6,0x880998f4
	if (ctx.cr6.gt) goto loc_880998F4;
	// lis r10,-32
	ctx.r10.s64 = -2097152;
	// cmpw cr6,r5,r10
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x880998f4
	if (ctx.cr6.lt) goto loc_880998F4;
	// cmpw cr6,r5,r11
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r11.s32, ctx.xer);
	// bgt cr6,0x880998f4
	if (ctx.cr6.gt) goto loc_880998F4;
	// lwz r28,2424(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2424);
	// cmpwi cr6,r4,3
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 3, ctx.xer);
	// addi r11,r28,1
	ctx.r11.s64 = ctx.r28.s64 + 1;
	// stw r11,2424(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2424, ctx.r11.u32);
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// bne cr6,0x8809979c
	if (!ctx.cr6.eq) goto loc_8809979C;
	// lwz r27,26428(r11)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26428);
	// clrlwi r10,r27,29
	ctx.r10.u64 = ctx.r27.u32 & 0x7;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x880998f4
	if (!ctx.cr6.eq) goto loc_880998F4;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x881534c8
	ctx.lr = 0x88099708;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lis r9,-30667
	ctx.r9.s64 = -2009792512;
	// li r8,7
	ctx.r8.s64 = 7;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// divwu r11,r27,r8
	ctx.r11.u32 = ppc_divwu(ctx.r27.u32, ctx.r8.u32);
	// lis r10,-30667
	ctx.r10.s64 = -2009792512;
	// add r5,r11,r28
	ctx.r5.u64 = ctx.r11.u64 + ctx.r28.u64;
	// stw r30,12372(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12372, ctx.r30.u32);
	// lis r9,-30667
	ctx.r9.s64 = -2009792512;
	// lis r11,-30667
	ctx.r11.s64 = -2009792512;
	// clrlwi r5,r5,28
	ctx.r5.u64 = ctx.r5.u32 & 0xF;
	// stw r29,12364(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12364, ctx.r29.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lis r10,-30667
	ctx.r10.s64 = -2009792512;
	// stw r31,12376(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12376, ctx.r31.u32);
	// stw r5,12384(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12384, ctx.r5.u32);
	// beq cr6,0x88099758
	if (ctx.cr6.eq) goto loc_88099758;
	// lis r7,-30667
	ctx.r7.s64 = -2009792512;
	// addi r6,r7,10020
	ctx.r6.s64 = ctx.r7.s64 + 10020;
	// b 0x88099760
	goto loc_88099760;
loc_88099758:
	// lis r7,-30667
	ctx.r7.s64 = -2009792512;
	// addi r6,r7,10036
	ctx.r6.s64 = ctx.r7.s64 + 10036;
loc_88099760:
	// lwz r3,12(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// stw r3,12380(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12380, ctx.r3.u32);
	// bl 0x880f25b8
	ctx.lr = 0x8809976C;
	sub_880F25B8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r3,95
	ctx.r3.s64 = 95;
	// bl 0x881534c8
	ctx.lr = 0x88099778;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r4,12
	ctx.r4.s64 = 12;
	// subf r11,r11,r24
	ctx.r11.s64 = ctx.r24.s64 - ctx.r11.s64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r10,r11,-208
	ctx.r10.s64 = ctx.r11.s64 + -208;
	// clrlwi r5,r10,23
	ctx.r5.u64 = ctx.r10.u32 & 0x1FF;
	// bl 0x880f26e0
	ctx.lr = 0x88099794;
	sub_880F26E0(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
loc_8809979C:
	// lwz r25,26428(r11)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26428);
	// clrlwi r10,r25,27
	ctx.r10.u64 = ctx.r25.u32 & 0x1F;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x88099844
	if (!ctx.cr6.eq) goto loc_88099844;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x881534c8
	ctx.lr = 0x880997B4;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lis r10,-30667
	ctx.r10.s64 = -2009792512;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lis r11,-30667
	ctx.r11.s64 = -2009792512;
	// li r8,7
	ctx.r8.s64 = 7;
	// rlwinm r6,r27,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r30,12372(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12372, ctx.r30.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lis r10,-30667
	ctx.r10.s64 = -2009792512;
	// stw r29,12364(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12364, ctx.r29.u32);
	// divwu r11,r25,r8
	ctx.r11.u32 = ppc_divwu(ctx.r25.u32, ctx.r8.u32);
	// lis r8,-30667
	ctx.r8.s64 = -2009792512;
	// beq cr6,0x880997f4
	if (ctx.cr6.eq) goto loc_880997F4;
	// lis r9,-30667
	ctx.r9.s64 = -2009792512;
	// addi r7,r9,10020
	ctx.r7.s64 = ctx.r9.s64 + 10020;
	// b 0x880997fc
	goto loc_880997FC;
loc_880997F4:
	// lis r9,-30667
	ctx.r9.s64 = -2009792512;
	// addi r7,r9,10036
	ctx.r7.s64 = ctx.r9.s64 + 10036;
loc_880997FC:
	// lwzx r3,r6,r7
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r7.u32);
	// add r9,r11,r28
	ctx.r9.u64 = ctx.r11.u64 + ctx.r28.u64;
	// lis r7,-30667
	ctx.r7.s64 = -2009792512;
	// clrlwi r5,r9,28
	ctx.r5.u64 = ctx.r9.u32 & 0xF;
	// stw r5,12384(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12384, ctx.r5.u32);
	// stw r3,12380(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12380, ctx.r3.u32);
	// stw r31,12376(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12376, ctx.r31.u32);
	// bl 0x880f25b8
	ctx.lr = 0x8809981C;
	sub_880F25B8(ctx, base);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// li r3,95
	ctx.r3.s64 = 95;
	// bl 0x881534c8
	ctx.lr = 0x88099828;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r4,12
	ctx.r4.s64 = 12;
	// subf r11,r11,r24
	ctx.r11.s64 = ctx.r24.s64 - ctx.r11.s64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// addi r10,r11,-208
	ctx.r10.s64 = ctx.r11.s64 + -208;
	// clrlwi r5,r10,23
	ctx.r5.u64 = ctx.r10.u32 & 0x1FF;
	// bl 0x880f26e0
	ctx.lr = 0x88099844;
	sub_880F26E0(ctx, base);
loc_88099844:
	// lis r11,-30667
	ctx.r11.s64 = -2009792512;
	// rlwinm r26,r27,3,0,28
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r27,r11,9988
	ctx.r27.s64 = ctx.r11.s64 + 9988;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// addi r11,r27,4
	ctx.r11.s64 = ctx.r27.s64 + 4;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwzx r3,r26,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r26.u32 + ctx.r11.u32);
	// bl 0x881538c0
	ctx.lr = 0x88099868;
	sub_881538C0(ctx, base);
	// lis r24,-30597
	ctx.r24.s64 = -2005204992;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880998a0
	if (ctx.cr6.eq) goto loc_880998A0;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,128
	ctx.r9.s64 = 8388608;
	// lwz r11,-11932(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + -11932);
	// oris r7,r10,545
	ctx.r7.u64 = ctx.r10.u64 | 35717120;
	// ori r8,r9,4112
	ctx.r8.u64 = ctx.r9.u64 | 4112;
	// ori r7,r7,32768
	ctx.r7.u64 = ctx.r7.u64 | 32768;
	// addi r23,r11,1
	ctx.r23.s64 = ctx.r11.s64 + 1;
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r23,-11932(r24)
	PPC_STORE_U32(ctx.r24.u32 + -11932, ctx.r23.u32);
	// b 0x880998a4
	goto loc_880998A4;
loc_880998A0:
	// lwz r23,-11932(r24)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r24.u32 + -11932);
loc_880998A4:
	// rlwinm r11,r25,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 31) & 0x7FFFFFFF;
	// lwzx r10,r26,r27
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + ctx.r27.u32);
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// clrlwi r11,r11,28
	ctx.r11.u64 = ctx.r11.u32 & 0xF;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x880998C8;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880998f4
	if (ctx.cr6.eq) goto loc_880998F4;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,80
	ctx.r9.s64 = 5242880;
	// addi r11,r23,1
	ctx.r11.s64 = ctx.r23.s64 + 1;
	// oris r7,r10,545
	ctx.r7.u64 = ctx.r10.u64 | 35717120;
	// ori r8,r9,20560
	ctx.r8.u64 = ctx.r9.u64 | 20560;
	// stw r11,-11932(r24)
	PPC_STORE_U32(ctx.r24.u32 + -11932, ctx.r11.u32);
	// ori r7,r7,49152
	ctx.r7.u64 = ctx.r7.u64 | 49152;
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
loc_880998F4:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880998FC"))) PPC_WEAK_FUNC(sub_880998FC);
PPC_FUNC_IMPL(__imp__sub_880998FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88099900"))) PPC_WEAK_FUNC(sub_88099900);
PPC_FUNC_IMPL(__imp__sub_88099900) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071124
	ctx.lr = 0x88099908;
	__savegprlr_15(ctx, base);
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mulli r11,r3,1136
	ctx.r11.s64 = ctx.r3.s64 * 1136;
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// mr r18,r5
	ctx.r18.u64 = ctx.r5.u64;
	// mr r19,r6
	ctx.r19.u64 = ctx.r6.u64;
	// mr r17,r7
	ctx.r17.u64 = ctx.r7.u64;
	// li r20,10
	ctx.r20.s64 = 10;
	// lwz r31,232(r11)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r11.u32 + 232);
	// addi r22,r11,144
	ctx.r22.s64 = ctx.r11.s64 + 144;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// ble cr6,0x88099a10
	if (!ctx.cr6.gt) goto loc_88099A10;
	// lwz r11,80(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 80);
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// lwz r9,72(r22)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r22.u32 + 72);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r30,r11,128
	ctx.r30.s64 = ctx.r11.s64 + 128;
	// lwz r8,64(r22)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r22.u32 + 64);
	// lwz r11,56(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 56);
	// addi r29,r9,128
	ctx.r29.s64 = ctx.r9.s64 + 128;
	// lwz r28,84(r22)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r22.u32 + 84);
	// addi r27,r8,128
	ctx.r27.s64 = ctx.r8.s64 + 128;
	// lwz r26,76(r22)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r22.u32 + 76);
	// addi r25,r11,128
	ctx.r25.s64 = ctx.r11.s64 + 128;
	// lwz r24,68(r22)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r22.u32 + 68);
	// addi r9,r7,-8
	ctx.r9.s64 = ctx.r7.s64 + -8;
	// lwz r23,60(r22)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r22.u32 + 60);
	// addi r6,r22,112
	ctx.r6.s64 = ctx.r22.s64 + 112;
	// mtctr r31
	ctx.ctr.u64 = ctx.r31.u64;
	// lis r21,128
	ctx.r21.s64 = 8388608;
loc_8809997C:
	// divw r16,r10,r31
	ctx.r16.s32 = ppc_divw(ctx.r10.s32, ctx.r31.s32);
	// lwzu r5,48(r6)
	ea = 48 + ctx.r6.u32;
	ctx.r5.u64 = PPC_LOAD_U32(ea);
	ctx.r6.u32 = ea;
	// addi r10,r10,127
	ctx.r10.s64 = ctx.r10.s64 + 127;
	// subfic r11,r16,128
	ctx.xer.ca = ctx.r16.u32 <= 128;
	ctx.r11.s64 = 128 - ctx.r16.s64;
	// mullw r15,r16,r16
	ctx.r15.s64 = int64_t(ctx.r16.s32) * int64_t(ctx.r16.s32);
	// mullw r3,r11,r11
	ctx.r3.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r11.s32);
	// mullw r8,r3,r16
	ctx.r8.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r16.s32);
	// mullw r7,r11,r16
	ctx.r7.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r16.s32);
	// rlwinm r4,r8,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// mullw r7,r7,r16
	ctx.r7.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r16.s32);
	// mullw r3,r3,r11
	ctx.r3.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r11.s32);
	// add r11,r8,r4
	ctx.r11.u64 = ctx.r8.u64 + ctx.r4.u64;
	// rlwinm r8,r7,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// mullw r4,r25,r3
	ctx.r4.s64 = int64_t(ctx.r25.s32) * int64_t(ctx.r3.s32);
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// mullw r7,r27,r11
	ctx.r7.s64 = int64_t(ctx.r27.s32) * int64_t(ctx.r11.s32);
	// mullw r11,r24,r11
	ctx.r11.s64 = int64_t(ctx.r24.s32) * int64_t(ctx.r11.s32);
	// mullw r3,r23,r3
	ctx.r3.s64 = int64_t(ctx.r23.s32) * int64_t(ctx.r3.s32);
	// add r4,r4,r7
	ctx.r4.u64 = ctx.r4.u64 + ctx.r7.u64;
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + ctx.r11.u64;
	// mullw r7,r29,r8
	ctx.r7.s64 = int64_t(ctx.r29.s32) * int64_t(ctx.r8.s32);
	// mullw r11,r26,r8
	ctx.r11.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r8.s32);
	// mullw r16,r15,r16
	ctx.r16.s64 = int64_t(ctx.r15.s32) * int64_t(ctx.r16.s32);
	// add r7,r4,r7
	ctx.r7.u64 = ctx.r4.u64 + ctx.r7.u64;
	// add r4,r3,r11
	ctx.r4.u64 = ctx.r3.u64 + ctx.r11.u64;
	// mullw r8,r30,r16
	ctx.r8.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r16.s32);
	// mullw r11,r28,r16
	ctx.r11.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r16.s32);
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// add r7,r4,r11
	ctx.r7.u64 = ctx.r4.u64 + ctx.r11.u64;
	// rlwinm r4,r8,27,5,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x7FFFFFF;
	// rlwinm r8,r7,27,5,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x7FFFFFF;
	// divw r11,r5,r20
	ctx.r11.s32 = ppc_divw(ctx.r5.s32, ctx.r20.s32);
	// subf r3,r21,r4
	ctx.r3.s64 = ctx.r4.s64 - ctx.r21.s64;
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// stw r3,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r3.u32);
	// stwu r11,8(r9)
	ea = 8 + ctx.r9.u32;
	PPC_STORE_U32(ea, ctx.r11.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x8809997c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8809997C;
loc_88099A10:
	// lis r21,-30597
	ctx.r21.s64 = -2005204992;
	// li r28,0
	ctx.r28.s64 = 0;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// lwz r23,-11932(r21)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r21.u32 + -11932);
	// ble cr6,0x88099b50
	if (!ctx.cr6.gt) goto loc_88099B50;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lwz r27,92(r1)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r26,88(r1)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// addi r29,r22,160
	ctx.r29.s64 = ctx.r22.s64 + 160;
	// lwz r25,84(r1)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r30,r11,-8
	ctx.r30.s64 = ctx.r11.s64 + -8;
	// lwz r24,80(r1)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_88099A40:
	// addic. r11,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r11.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge 0x88099a5c
	if (!ctx.cr0.lt) goto loc_88099A5C;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// b 0x88099a90
	goto loc_88099A90;
loc_88099A5C:
	// addi r11,r31,-1
	ctx.r11.s64 = ctx.r31.s64 + -1;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r6,4(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// cmpw cr6,r28,r11
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x88099a7c
	if (!ctx.cr6.lt) goto loc_88099A7C;
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// lwz r4,20(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// b 0x88099a90
	goto loc_88099A90;
loc_88099A7C:
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r11,12(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 12);
	// divw r10,r10,r20
	ctx.r10.s32 = ppc_divw(ctx.r10.s32, ctx.r20.s32);
	// lwz r3,8(r22)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r22.u32 + 8);
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
loc_88099A90:
	// bl 0x88153070
	ctx.lr = 0x88099A94;
	sub_88153070(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// lwz r5,12(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// srawi r10,r11,4
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xF) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 4;
	// clrlwi r11,r10,27
	ctx.r11.u64 = ctx.r10.u32 & 0x1F;
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// ble cr6,0x88099ac0
	if (!ctx.cr6.gt) goto loc_88099AC0;
	// subfic r11,r11,32
	ctx.xer.ca = ctx.r11.u32 <= 32;
	ctx.r11.s64 = 32 - ctx.r11.s64;
	// li r31,1
	ctx.r31.s64 = 1;
loc_88099AC0:
	// mr r6,r18
	ctx.r6.u64 = ctx.r18.u64;
	// addi r3,r11,20506
	ctx.r3.s64 = ctx.r11.s64 + 20506;
	// bl 0x881538c0
	ctx.lr = 0x88099ACC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r19,0
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, 0, ctx.xer);
	// beq cr6,0x88099b14
	if (ctx.cr6.eq) goto loc_88099B14;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88099ae4
	if (ctx.cr6.eq) goto loc_88099AE4;
	// lwz r11,0(r19)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r19.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_88099AE4:
	// cmplwi cr6,r17,0
	ctx.cr6.compare<uint32_t>(ctx.r17.u32, 0, ctx.xer);
	// beq cr6,0x88099b14
	if (ctx.cr6.eq) goto loc_88099B14;
	// lwz r11,0(r17)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r17.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x88099b14
	if (ctx.cr6.eq) goto loc_88099B14;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r23,r23,1
	ctx.r23.s64 = ctx.r23.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_88099B14:
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq cr6,0x88099b34
	if (ctx.cr6.eq) goto loc_88099B34;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88099b34
	if (ctx.cr6.eq) goto loc_88099B34;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r31,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_88099B34:
	// lwz r31,88(r22)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r22.u32 + 88);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r29,r29,48
	ctx.r29.s64 = ctx.r29.s64 + 48;
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// cmpw cr6,r28,r31
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r31.s32, ctx.xer);
	// blt cr6,0x88099a40
	if (ctx.cr6.lt) goto loc_88099A40;
	// stw r23,-11932(r21)
	PPC_STORE_U32(ctx.r21.u32 + -11932, ctx.r23.u32);
loc_88099B50:
	// lwz r29,8(r22)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r22.u32 + 8);
	// addic. r11,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r11.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r30,12(r22)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r22.u32 + 12);
	// blt 0x88099b7c
	if (ctx.cr0.lt) goto loc_88099B7C;
	// rlwinm r11,r31,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r31,r11
	ctx.r11.u64 = ctx.r31.u64 + ctx.r11.u64;
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r11,r22
	ctx.r10.u64 = ctx.r11.u64 + ctx.r22.u64;
	// lwz r9,112(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 112);
	// divw r11,r9,r20
	ctx.r11.s32 = ppc_divw(ctx.r9.s32, ctx.r20.s32);
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
loc_88099B7C:
	// li r11,256
	ctx.r11.s64 = 256;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq cr6,0x88099bb8
	if (ctx.cr6.eq) goto loc_88099BB8;
	// lwz r11,88(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 88);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r1,84
	ctx.r9.s64 = ctx.r1.s64 + 84;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r6,-8(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + -8);
	// lwz r5,-8(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + -8);
	// bl 0x88153070
	ctx.lr = 0x88099BB4;
	sub_88153070(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
loc_88099BB8:
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// li r31,0
	ctx.r31.s64 = 0;
	// srawi r10,r11,4
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xF) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 4;
	// li r9,1
	ctx.r9.s64 = 1;
	// clrlwi r11,r10,27
	ctx.r11.u64 = ctx.r10.u32 & 0x1F;
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// ble cr6,0x88099be0
	if (!ctx.cr6.gt) goto loc_88099BE0;
	// subfic r11,r11,32
	ctx.xer.ca = ctx.r11.u32 <= 32;
	ctx.r11.s64 = 32 - ctx.r11.s64;
	// li r31,1
	ctx.r31.s64 = 1;
	// li r9,-1
	ctx.r9.s64 = -1;
loc_88099BE0:
	// lis r10,-30683
	ctx.r10.s64 = -2010841088;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r10,13676
	ctx.r10.s64 = ctx.r10.s64 + 13676;
	// addi r3,r11,20489
	ctx.r3.s64 = ctx.r11.s64 + 20489;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// mr r6,r18
	ctx.r6.u64 = ctx.r18.u64;
	// lbzx r5,r8,r10
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r10.u32);
	// lbzx r4,r8,r7
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r7.u32);
	// extsb r10,r5
	ctx.r10.s64 = ctx.r5.s8;
	// extsb r11,r4
	ctx.r11.s64 = ctx.r4.s8;
	// mullw r9,r10,r9
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// addi r8,r11,-5
	ctx.r8.s64 = ctx.r11.s64 + -5;
	// rlwinm r10,r9,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r8,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r10,r29
	ctx.r4.u64 = ctx.r10.u64 + ctx.r29.u64;
	// add r5,r11,r30
	ctx.r5.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x881538c0
	ctx.lr = 0x88099C24;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r19,0
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, 0, ctx.xer);
	// beq cr6,0x88099c70
	if (ctx.cr6.eq) goto loc_88099C70;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88099c3c
	if (ctx.cr6.eq) goto loc_88099C3C;
	// lwz r11,0(r19)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r19.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_88099C3C:
	// cmplwi cr6,r17,0
	ctx.cr6.compare<uint32_t>(ctx.r17.u32, 0, ctx.xer);
	// beq cr6,0x88099c70
	if (ctx.cr6.eq) goto loc_88099C70;
	// lwz r11,0(r17)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r17.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x88099c70
	if (ctx.cr6.eq) goto loc_88099C70;
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r11,r23,1
	ctx.r11.s64 = ctx.r23.s64 + 1;
	// rlwimi r9,r10,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r11,-11932(r21)
	PPC_STORE_U32(ctx.r21.u32 + -11932, ctx.r11.u32);
	// or r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 | ctx.r8.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
loc_88099C70:
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq cr6,0x88099c90
	if (ctx.cr6.eq) goto loc_88099C90;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88099c90
	if (ctx.cr6.eq) goto loc_88099C90;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r31,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_88099C90:
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x88071174
	__restgprlr_15(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88099C98"))) PPC_WEAK_FUNC(sub_88099C98);
PPC_FUNC_IMPL(__imp__sub_88099C98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071120
	ctx.lr = 0x88099CA0;
	__savegprlr_14(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r22,4(r6)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// lis r14,-30597
	ctx.r14.s64 = -2005204992;
	// lwz r23,2304(r3)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// li r21,0
	ctx.r21.s64 = 0;
	// lwz r10,184(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// lis r9,128
	ctx.r9.s64 = 8388608;
	// lwz r11,168(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// li r19,160
	ctx.r19.s64 = 160;
	// lwz r15,0(r6)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lis r25,80
	ctx.r25.s64 = 5242880;
	// lwz r17,-11932(r14)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r14.u32 + -11932);
	// ori r20,r9,32896
	ctx.r20.u64 = ctx.r9.u64 | 32896;
	// stw r22,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r22.u32);
	// add r16,r10,r11
	ctx.r16.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r21,2424(r23)
	PPC_STORE_U32(ctx.r23.u32 + 2424, ctx.r21.u32);
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// bne cr6,0x88099d64
	if (!ctx.cr6.eq) goto loc_88099D64;
	// addi r31,r23,9628
	ctx.r31.s64 = ctx.r23.s64 + 9628;
	// li r30,21
	ctx.r30.s64 = 21;
loc_88099CF0:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88099d54
	if (!ctx.cr6.eq) goto loc_88099D54;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r6,r16,-20
	ctx.r6.s64 = ctx.r16.s64 + -20;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r3,15804
	ctx.r3.s64 = 15804;
	// srawi r9,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 16;
	// subf r5,r25,r10
	ctx.r5.s64 = ctx.r10.s64 - ctx.r25.s64;
	// addze r11,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r11.s64 = temp.s64;
	// addi r8,r11,-160
	ctx.r8.s64 = ctx.r11.s64 + -160;
	// mulli r7,r8,240
	ctx.r7.s64 = ctx.r8.s64 * 240;
	// srawi r4,r7,1
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r4.s64 = ctx.r7.s32 >> 1;
	// addze r11,r4
	temp.s64 = ctx.r4.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r11.s64 = temp.s64;
	// divw r11,r11,r19
	ctx.r11.s32 = ppc_divw(ctx.r11.s32, ctx.r19.s32);
	// addi r10,r11,160
	ctx.r10.s64 = ctx.r11.s64 + 160;
	// rlwinm r4,r10,16,0,15
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// bl 0x881538c0
	ctx.lr = 0x88099D38;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88099d54
	if (ctx.cr6.eq) goto loc_88099D54;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// stw r20,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r20.u32);
	// oris r10,r11,518
	ctx.r10.u64 = ctx.r11.u64 | 33947648;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_88099D54:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r31,r31,20
	ctx.r31.s64 = ctx.r31.s64 + 20;
	// bne 0x88099cf0
	if (!ctx.cr0.eq) goto loc_88099CF0;
	// stw r17,-11932(r14)
	PPC_STORE_U32(ctx.r14.u32 + -11932, ctx.r17.u32);
loc_88099D64:
	// lwz r11,10036(r23)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + 10036);
	// addi r30,r23,10028
	ctx.r30.s64 = ctx.r23.s64 + 10028;
	// lwz r9,10040(r23)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r23.u32 + 10040);
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r8,r11,4
	ctx.r8.s64 = ctx.r11.s64 + 4;
	// subf r9,r9,r16
	ctx.r9.s64 = ctx.r16.s64 - ctx.r9.s64;
	// srawi r7,r8,3
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 3;
	// mr r26,r21
	ctx.r26.u64 = ctx.r21.u64;
	// clrlwi r11,r7,26
	ctx.r11.u64 = ctx.r7.u32 & 0x3F;
	// addi r6,r9,2
	ctx.r6.s64 = ctx.r9.s64 + 2;
	// cmpwi cr6,r11,32
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 32, ctx.xer);
	// ble cr6,0x88099da0
	if (!ctx.cr6.gt) goto loc_88099DA0;
	// subfic r11,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r11.s64 = 64 - ctx.r11.s64;
	// li r26,1
	ctx.r26.s64 = 1;
	// li r10,-1
	ctx.r10.s64 = -1;
loc_88099DA0:
	// lis r9,-30683
	ctx.r9.s64 = -2010841088;
	// lwz r7,9376(r23)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r23.u32 + 9376);
	// rlwinm r4,r11,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// addi r31,r9,20056
	ctx.r31.s64 = ctx.r9.s64 + 20056;
	// lwz r5,4(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// li r18,10
	ctx.r18.s64 = 10;
	// addi r9,r31,360
	ctx.r9.s64 = ctx.r31.s64 + 360;
	// addi r3,r31,360
	ctx.r3.s64 = ctx.r31.s64 + 360;
	// addi r29,r9,1
	ctx.r29.s64 = ctx.r9.s64 + 1;
	// divw r9,r7,r18
	ctx.r9.s32 = ppc_divw(ctx.r7.s32, ctx.r18.s32);
	// lbzx r7,r4,r3
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r3.u32);
	// lbzx r4,r4,r29
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r29.u32);
	// extsb r3,r7
	ctx.r3.s64 = ctx.r7.s8;
	// extsb r7,r4
	ctx.r7.s64 = ctx.r4.s8;
	// mullw r4,r3,r10
	ctx.r4.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r10.s32);
	// rlwinm r10,r7,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r7,r4,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r29,r7,r8
	ctx.r29.u64 = ctx.r7.u64 + ctx.r8.u64;
	// add r28,r10,r5
	ctx.r28.u64 = ctx.r10.u64 + ctx.r5.u64;
	// stw r29,14876(r23)
	PPC_STORE_U32(ctx.r23.u32 + 14876, ctx.r29.u32);
	// stw r28,14880(r23)
	PPC_STORE_U32(ctx.r23.u32 + 14880, ctx.r28.u32);
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88099efc
	if (!ctx.cr6.eq) goto loc_88099EFC;
	// addi r27,r11,20589
	ctx.r27.s64 = ctx.r11.s64 + 20589;
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
	// mr r8,r22
	ctx.r8.u64 = ctx.r22.u64;
	// mr r7,r15
	ctx.r7.u64 = ctx.r15.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x880a51a0
	ctx.lr = 0x88099E28;
	sub_880A51A0(ctx, base);
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// bne cr6,0x88099ef8
	if (!ctx.cr6.eq) goto loc_88099EF8;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// lwz r8,8(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r7,r16,3
	ctx.r7.s64 = ctx.r16.s64 + 3;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x88099698
	ctx.lr = 0x88099E4C;
	sub_88099698(ctx, base);
	// srawi r11,r29,16
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0xFFFF) != 0);
	ctx.r11.s64 = ctx.r29.s32 >> 16;
	// subf r30,r25,r28
	ctx.r30.s64 = ctx.r28.s64 - ctx.r25.s64;
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// addi r29,r16,-20
	ctx.r29.s64 = ctx.r16.s64 + -20;
	// addi r10,r11,-160
	ctx.r10.s64 = ctx.r11.s64 + -160;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mulli r9,r10,240
	ctx.r9.s64 = ctx.r10.s64 * 240;
	// srawi r8,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 1;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addze r7,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r7.s64 = temp.s64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// divw r11,r7,r19
	ctx.r11.s32 = ppc_divw(ctx.r7.s32, ctx.r19.s32);
	// addi r4,r11,160
	ctx.r4.s64 = ctx.r11.s64 + 160;
	// rlwinm r28,r4,16,0,15
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x881538c0
	ctx.lr = 0x88099E8C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88099ec0
	if (ctx.cr6.eq) goto loc_88099EC0;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r26,26,0,5
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 26) & 0xFC000000;
	// lwz r11,-11932(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + -11932);
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r21,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r21.u32);
	// addi r17,r11,1
	ctx.r17.s64 = ctx.r11.s64 + 1;
	// oris r7,r8,547
	ctx.r7.u64 = ctx.r8.u64 | 35848192;
	// stw r17,-11932(r14)
	PPC_STORE_U32(ctx.r14.u32 + -11932, ctx.r17.u32);
	// ori r7,r7,4096
	ctx.r7.u64 = ctx.r7.u64 | 4096;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// b 0x88099ec4
	goto loc_88099EC4;
loc_88099EC0:
	// lwz r17,-11932(r14)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r14.u32 + -11932);
loc_88099EC4:
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r3,15802
	ctx.r3.s64 = 15802;
	// bl 0x881538c0
	ctx.lr = 0x88099ED8;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88099efc
	if (ctx.cr6.eq) goto loc_88099EFC;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// oris r10,r11,518
	ctx.r10.u64 = ctx.r11.u64 | 33947648;
	// stw r17,-11932(r14)
	PPC_STORE_U32(ctx.r14.u32 + -11932, ctx.r17.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x88099efc
	goto loc_88099EFC;
loc_88099EF8:
	// lwz r17,-11932(r14)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r14.u32 + -11932);
loc_88099EFC:
	// addi r30,r23,10008
	ctx.r30.s64 = ctx.r23.s64 + 10008;
	// li r24,6
	ctx.r24.s64 = 6;
	// addi r27,r23,14936
	ctx.r27.s64 = ctx.r23.s64 + 14936;
	// addi r25,r23,9088
	ctx.r25.s64 = ctx.r23.s64 + 9088;
loc_88099F0C:
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// mr r26,r21
	ctx.r26.u64 = ctx.r21.u64;
	// addi r8,r11,4
	ctx.r8.s64 = ctx.r11.s64 + 4;
	// subf r11,r10,r16
	ctx.r11.s64 = ctx.r16.s64 - ctx.r10.s64;
	// srawi r7,r8,3
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 3;
	// addi r6,r11,2
	ctx.r6.s64 = ctx.r11.s64 + 2;
	// clrlwi r11,r7,26
	ctx.r11.u64 = ctx.r7.u32 & 0x3F;
	// cmpwi cr6,r11,32
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 32, ctx.xer);
	// ble cr6,0x88099f44
	if (!ctx.cr6.gt) goto loc_88099F44;
	// subfic r11,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r11.s64 = 64 - ctx.r11.s64;
	// li r26,1
	ctx.r26.s64 = 1;
	// li r9,-1
	ctx.r9.s64 = -1;
loc_88099F44:
	// addi r10,r31,288
	ctx.r10.s64 = ctx.r31.s64 + 288;
	// lwz r7,0(r25)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// rlwinm r4,r11,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// addi r3,r31,288
	ctx.r3.s64 = ctx.r31.s64 + 288;
	// lwz r5,4(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// addi r29,r10,1
	ctx.r29.s64 = ctx.r10.s64 + 1;
	// divw r10,r7,r18
	ctx.r10.s32 = ppc_divw(ctx.r7.s32, ctx.r18.s32);
	// lbzx r7,r4,r3
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r3.u32);
	// lbzx r4,r4,r29
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r29.u32);
	// extsb r3,r7
	ctx.r3.s64 = ctx.r7.s8;
	// extsb r7,r4
	ctx.r7.s64 = ctx.r4.s8;
	// mullw r4,r3,r9
	ctx.r4.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r9.s32);
	// rlwinm r9,r7,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r7,r4,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r29,r7,r8
	ctx.r29.u64 = ctx.r7.u64 + ctx.r8.u64;
	// add r28,r10,r5
	ctx.r28.u64 = ctx.r10.u64 + ctx.r5.u64;
	// stw r29,-4(r27)
	PPC_STORE_U32(ctx.r27.u32 + -4, ctx.r29.u32);
	// stw r28,0(r27)
	PPC_STORE_U32(ctx.r27.u32 + 0, ctx.r28.u32);
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8809a044
	if (!ctx.cr6.eq) goto loc_8809A044;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r11,20556
	ctx.r3.s64 = ctx.r11.s64 + 20556;
	// bl 0x881538c0
	ctx.lr = 0x88099FB0;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r15,0
	ctx.cr6.compare<uint32_t>(ctx.r15.u32, 0, ctx.xer);
	// beq cr6,0x88099ffc
	if (ctx.cr6.eq) goto loc_88099FFC;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88099fc8
	if (ctx.cr6.eq) goto loc_88099FC8;
	// lwz r11,0(r15)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_88099FC8:
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x88099ffc
	if (ctx.cr6.eq) goto loc_88099FFC;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x88099ffc
	if (ctx.cr6.eq) goto loc_88099FFC;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r17,-11932(r14)
	PPC_STORE_U32(ctx.r14.u32 + -11932, ctx.r17.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_88099FFC:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq cr6,0x8809a01c
	if (ctx.cr6.eq) goto loc_8809A01C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809a01c
	if (ctx.cr6.eq) goto loc_8809A01C;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r26,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_8809A01C:
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// bne cr6,0x8809a044
	if (!ctx.cr6.eq) goto loc_8809A044;
	// addi r7,r16,3
	ctx.r7.s64 = ctx.r16.s64 + 3;
	// lwz r8,8(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x88099698
	ctx.lr = 0x8809A040;
	sub_88099698(ctx, base);
	// lwz r17,-11932(r14)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r14.u32 + -11932);
loc_8809A044:
	// addic. r24,r24,-1
	ctx.xer.ca = ctx.r24.u32 > 0;
	ctx.r24.s64 = ctx.r24.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// addi r30,r30,-20
	ctx.r30.s64 = ctx.r30.s64 + -20;
	// addi r25,r25,-288
	ctx.r25.s64 = ctx.r25.s64 + -288;
	// addi r27,r27,-8
	ctx.r27.s64 = ctx.r27.s64 + -8;
	// bge 0x88099f0c
	if (!ctx.cr0.lt) goto loc_88099F0C;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// addi r30,r23,9868
	ctx.r30.s64 = ctx.r23.s64 + 9868;
	// li r21,7
	ctx.r21.s64 = 7;
	// addi r26,r23,14800
	ctx.r26.s64 = ctx.r23.s64 + 14800;
	// addi r24,r23,7072
	ctx.r24.s64 = ctx.r23.s64 + 7072;
	// ori r22,r10,16384
	ctx.r22.u64 = ctx.r10.u64 | 16384;
	// addi r25,r11,9552
	ctx.r25.s64 = ctx.r11.s64 + 9552;
loc_8809A078:
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// li r27,0
	ctx.r27.s64 = 0;
	// addi r8,r11,4
	ctx.r8.s64 = ctx.r11.s64 + 4;
	// subf r10,r10,r16
	ctx.r10.s64 = ctx.r16.s64 - ctx.r10.s64;
	// srawi r7,r8,3
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 3;
	// addi r6,r10,2
	ctx.r6.s64 = ctx.r10.s64 + 2;
	// clrlwi r11,r7,26
	ctx.r11.u64 = ctx.r7.u32 & 0x3F;
	// cmpwi cr6,r11,32
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 32, ctx.xer);
	// ble cr6,0x8809a0b0
	if (!ctx.cr6.gt) goto loc_8809A0B0;
	// subfic r11,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r11.s64 = 64 - ctx.r11.s64;
	// li r27,1
	ctx.r27.s64 = 1;
	// li r9,-1
	ctx.r9.s64 = -1;
loc_8809A0B0:
	// addi r10,r31,216
	ctx.r10.s64 = ctx.r31.s64 + 216;
	// lwz r7,0(r24)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// rlwinm r4,r11,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// addi r3,r31,216
	ctx.r3.s64 = ctx.r31.s64 + 216;
	// lwz r5,4(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// addi r29,r10,1
	ctx.r29.s64 = ctx.r10.s64 + 1;
	// divw r10,r7,r18
	ctx.r10.s32 = ppc_divw(ctx.r7.s32, ctx.r18.s32);
	// lbzx r7,r4,r3
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r3.u32);
	// lbzx r4,r4,r29
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r29.u32);
	// extsb r3,r7
	ctx.r3.s64 = ctx.r7.s8;
	// extsb r7,r4
	ctx.r7.s64 = ctx.r4.s8;
	// mullw r4,r3,r9
	ctx.r4.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r9.s32);
	// rlwinm r9,r7,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r7,r4,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r29,r7,r8
	ctx.r29.u64 = ctx.r7.u64 + ctx.r8.u64;
	// add r28,r10,r5
	ctx.r28.u64 = ctx.r10.u64 + ctx.r5.u64;
	// stw r29,-4(r26)
	PPC_STORE_U32(ctx.r26.u32 + -4, ctx.r29.u32);
	// stw r28,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r28.u32);
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8809a248
	if (!ctx.cr6.eq) goto loc_8809A248;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r11,20523
	ctx.r3.s64 = ctx.r11.s64 + 20523;
	// bl 0x881538c0
	ctx.lr = 0x8809A11C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r15,0
	ctx.cr6.compare<uint32_t>(ctx.r15.u32, 0, ctx.xer);
	// beq cr6,0x8809a170
	if (ctx.cr6.eq) goto loc_8809A170;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809a134
	if (ctx.cr6.eq) goto loc_8809A134;
	// lwz r11,0(r15)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_8809A134:
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8809a174
	if (ctx.cr6.eq) goto loc_8809A174;
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x8809a174
	if (ctx.cr6.eq) goto loc_8809A174;
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r9,r11,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r17,-11932(r14)
	PPC_STORE_U32(ctx.r14.u32 + -11932, ctx.r17.u32);
	// or r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 | ctx.r8.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// b 0x8809a174
	goto loc_8809A174;
loc_8809A170:
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_8809A174:
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq cr6,0x8809a194
	if (ctx.cr6.eq) goto loc_8809A194;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809a194
	if (ctx.cr6.eq) goto loc_8809A194;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r27,26,0,5
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 26) & 0xFC000000;
	// or r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 | ctx.r11.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_8809A194:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8809a248
	if (!ctx.cr6.eq) goto loc_8809A248;
	// addi r7,r16,3
	ctx.r7.s64 = ctx.r16.s64 + 3;
	// lwz r8,8(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x88099698
	ctx.lr = 0x8809A1B8;
	sub_88099698(ctx, base);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// addi r6,r16,-20
	ctx.r6.s64 = ctx.r16.s64 + -20;
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// li r3,15804
	ctx.r3.s64 = 15804;
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,128
	ctx.r9.s64 = ctx.r11.s64 + 128;
	// rlwinm r8,r9,2,21,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x7FC;
	// lwzx r7,r10,r25
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r25.u32);
	// rlwinm r11,r7,6,0,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 6) & 0xFFFFFFC0;
	// lwzx r5,r8,r25
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r25.u32);
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// subf r4,r22,r5
	ctx.r4.s64 = ctx.r5.s64 - ctx.r22.s64;
	// srawi r9,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 16;
	// rlwinm r10,r4,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 6) & 0xFFFFFFC0;
	// addze r11,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r11.s64 = temp.s64;
	// add r5,r10,r28
	ctx.r5.u64 = ctx.r10.u64 + ctx.r28.u64;
	// addi r8,r11,-160
	ctx.r8.s64 = ctx.r11.s64 + -160;
	// mulli r7,r8,240
	ctx.r7.s64 = ctx.r8.s64 * 240;
	// srawi r4,r7,1
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r4.s64 = ctx.r7.s32 >> 1;
	// addze r11,r4
	temp.s64 = ctx.r4.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r11.s64 = temp.s64;
	// divw r11,r11,r19
	ctx.r11.s32 = ppc_divw(ctx.r11.s32, ctx.r19.s32);
	// addi r10,r11,160
	ctx.r10.s64 = ctx.r11.s64 + 160;
	// rlwinm r4,r10,16,0,15
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// bl 0x881538c0
	ctx.lr = 0x8809A21C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809a244
	if (ctx.cr6.eq) goto loc_8809A244;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-11932(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + -11932);
	// oris r9,r10,518
	ctx.r9.u64 = ctx.r10.u64 | 33947648;
	// stw r20,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r20.u32);
	// addi r17,r11,1
	ctx.r17.s64 = ctx.r11.s64 + 1;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r17,-11932(r14)
	PPC_STORE_U32(ctx.r14.u32 + -11932, ctx.r17.u32);
	// b 0x8809a248
	goto loc_8809A248;
loc_8809A244:
	// lwz r17,-11932(r14)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r14.u32 + -11932);
loc_8809A248:
	// addic. r21,r21,-1
	ctx.xer.ca = ctx.r21.u32 > 0;
	ctx.r21.s64 = ctx.r21.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// addi r30,r30,-20
	ctx.r30.s64 = ctx.r30.s64 + -20;
	// addi r24,r24,-288
	ctx.r24.s64 = ctx.r24.s64 + -288;
	// addi r26,r26,-8
	ctx.r26.s64 = ctx.r26.s64 + -8;
	// bge 0x8809a078
	if (!ctx.cr0.lt) goto loc_8809A078;
	// lwz r10,9716(r23)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r23.u32 + 9716);
	// addi r24,r23,9708
	ctx.r24.s64 = ctx.r23.s64 + 9708;
	// lwz r11,9720(r23)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + 9720);
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// subf r11,r11,r16
	ctx.r11.s64 = ctx.r16.s64 - ctx.r11.s64;
	// srawi r9,r10,3
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 3;
	// addi r21,r11,2
	ctx.r21.s64 = ctx.r11.s64 + 2;
	// clrlwi r11,r9,26
	ctx.r11.u64 = ctx.r9.u32 & 0x3F;
	// li r28,0
	ctx.r28.s64 = 0;
	// cmpwi cr6,r11,32
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 32, ctx.xer);
	// ble cr6,0x8809a298
	if (!ctx.cr6.gt) goto loc_8809A298;
	// subfic r11,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r11.s64 = 64 - ctx.r11.s64;
	// li r28,1
	ctx.r28.s64 = 1;
	// li r7,-1
	ctx.r7.s64 = -1;
loc_8809A298:
	// addi r8,r31,-216
	ctx.r8.s64 = ctx.r31.s64 + -216;
	// lwz r3,3616(r23)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r23.u32 + 3616);
	// rlwinm r5,r11,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,0(r24)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lwz r9,4(r24)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r24.u32 + 4);
	// addi r4,r31,-216
	ctx.r4.s64 = ctx.r31.s64 + -216;
	// divw r6,r3,r18
	ctx.r6.s32 = ppc_divw(ctx.r3.s32, ctx.r18.s32);
	// mr r27,r10
	ctx.r27.u64 = ctx.r10.u64;
	// mr r26,r9
	ctx.r26.u64 = ctx.r9.u64;
	// lbzx r8,r5,r8
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r8.u32);
	// lbzx r4,r5,r4
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r4.u32);
	// extsb r5,r8
	ctx.r5.s64 = ctx.r8.s8;
	// extsb r3,r4
	ctx.r3.s64 = ctx.r4.s8;
	// rlwinm r8,r5,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// mullw r7,r3,r7
	ctx.r7.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r7.s32);
	// rlwinm r7,r7,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// add r30,r7,r10
	ctx.r30.u64 = ctx.r7.u64 + ctx.r10.u64;
	// add r29,r8,r9
	ctx.r29.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stw r30,14732(r23)
	PPC_STORE_U32(ctx.r23.u32 + 14732, ctx.r30.u32);
	// stw r29,14736(r23)
	PPC_STORE_U32(ctx.r23.u32 + 14736, ctx.r29.u32);
	// lwz r4,16(r24)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r24.u32 + 16);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne cr6,0x8809a3b0
	if (!ctx.cr6.eq) goto loc_8809A3B0;
	// mr r6,r21
	ctx.r6.u64 = ctx.r21.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r11,20291
	ctx.r3.s64 = ctx.r11.s64 + 20291;
	// bl 0x881538c0
	ctx.lr = 0x8809A310;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r15,0
	ctx.cr6.compare<uint32_t>(ctx.r15.u32, 0, ctx.xer);
	// beq cr6,0x8809a364
	if (ctx.cr6.eq) goto loc_8809A364;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809a328
	if (ctx.cr6.eq) goto loc_8809A328;
	// lwz r11,0(r15)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_8809A328:
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8809a368
	if (ctx.cr6.eq) goto loc_8809A368;
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x8809a368
	if (ctx.cr6.eq) goto loc_8809A368;
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r9,r11,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r17,-11932(r14)
	PPC_STORE_U32(ctx.r14.u32 + -11932, ctx.r17.u32);
	// or r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 | ctx.r8.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// b 0x8809a368
	goto loc_8809A368;
loc_8809A364:
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_8809A368:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq cr6,0x8809a388
	if (ctx.cr6.eq) goto loc_8809A388;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809a388
	if (ctx.cr6.eq) goto loc_8809A388;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r28,26,0,5
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 26) & 0xFC000000;
	// or r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 | ctx.r11.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_8809A388:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8809a3b0
	if (!ctx.cr6.eq) goto loc_8809A3B0;
	// addi r7,r16,3
	ctx.r7.s64 = ctx.r16.s64 + 3;
	// lwz r8,8(r24)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r24.u32 + 8);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x88099698
	ctx.lr = 0x8809A3AC;
	sub_88099698(ctx, base);
	// lwz r17,-11932(r14)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r14.u32 + -11932);
loc_8809A3B0:
	// lwz r11,8(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 8);
	// li r30,1
	ctx.r30.s64 = 1;
	// li r25,0
	ctx.r25.s64 = 0;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// srawi r10,r11,3
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 3;
	// clrlwi r28,r10,26
	ctx.r28.u64 = ctx.r10.u32 & 0x3F;
	// cmpwi cr6,r28,32
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 32, ctx.xer);
	// ble cr6,0x8809a3dc
	if (!ctx.cr6.gt) goto loc_8809A3DC;
	// addi r28,r28,-32
	ctx.r28.s64 = ctx.r28.s64 + -32;
	// li r25,3
	ctx.r25.s64 = 3;
	// li r30,-1
	ctx.r30.s64 = -1;
loc_8809A3DC:
	// lwz r11,10368(r23)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + 10368);
	// rlwinm r29,r28,1,0,30
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r7,3664(r23)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r23.u32 + 3664);
	// lis r22,16
	ctx.r22.s64 = 1048576;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8809a470
	if (ctx.cr6.eq) goto loc_8809A470;
	// addi r9,r31,-288
	ctx.r9.s64 = ctx.r31.s64 + -288;
	// lwz r11,-404(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -404);
	// addi r6,r31,-288
	ctx.r6.s64 = ctx.r31.s64 + -288;
	// lwz r10,-408(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -408);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// lbzx r4,r29,r6
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r6.u32);
	// lbzx r5,r29,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r9.u32);
	// extsb r9,r4
	ctx.r9.s64 = ctx.r4.s8;
	// extsb r8,r5
	ctx.r8.s64 = ctx.r5.s8;
	// add r3,r8,r11
	ctx.r3.u64 = ctx.r8.u64 + ctx.r11.u64;
	// add r11,r9,r10
	ctx.r11.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r3,r30
	ctx.r10.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r30.s32);
	// mullw r8,r11,r30
	ctx.r8.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// divw r9,r7,r18
	ctx.r9.s32 = ppc_divw(ctx.r7.s32, ctx.r18.s32);
	// rlwinm r10,r8,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r4,r10,r27
	ctx.r4.u64 = ctx.r10.u64 + ctx.r27.u64;
	// add r5,r11,r26
	ctx.r5.u64 = ctx.r11.u64 + ctx.r26.u64;
	// bne cr6,0x8809a44c
	if (!ctx.cr6.eq) goto loc_8809A44C;
	// subf r5,r22,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r22.s64;
loc_8809A44C:
	// stw r4,15020(r23)
	PPC_STORE_U32(ctx.r23.u32 + 15020, ctx.r4.u32);
	// stw r5,15024(r23)
	PPC_STORE_U32(ctx.r23.u32 + 15024, ctx.r5.u32);
	// stw r4,10312(r23)
	PPC_STORE_U32(ctx.r23.u32 + 10312, ctx.r4.u32);
	// stw r5,10316(r23)
	PPC_STORE_U32(ctx.r23.u32 + 10316, ctx.r5.u32);
	// lwz r11,16(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8809a554
	if (!ctx.cr6.eq) goto loc_8809A554;
	// addi r3,r28,20225
	ctx.r3.s64 = ctx.r28.s64 + 20225;
	// b 0x8809a4dc
	goto loc_8809A4DC;
loc_8809A470:
	// addi r9,r31,-360
	ctx.r9.s64 = ctx.r31.s64 + -360;
	// lwz r11,-412(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -412);
	// addi r6,r31,-360
	ctx.r6.s64 = ctx.r31.s64 + -360;
	// lwz r10,-416(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -416);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// lbzx r4,r29,r6
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r6.u32);
	// lbzx r5,r29,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r9.u32);
	// extsb r9,r4
	ctx.r9.s64 = ctx.r4.s8;
	// extsb r8,r5
	ctx.r8.s64 = ctx.r5.s8;
	// add r3,r8,r11
	ctx.r3.u64 = ctx.r8.u64 + ctx.r11.u64;
	// add r11,r9,r10
	ctx.r11.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r3,r30
	ctx.r10.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r30.s32);
	// mullw r8,r11,r30
	ctx.r8.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// divw r9,r7,r18
	ctx.r9.s32 = ppc_divw(ctx.r7.s32, ctx.r18.s32);
	// rlwinm r10,r8,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r4,r10,r27
	ctx.r4.u64 = ctx.r10.u64 + ctx.r27.u64;
	// add r5,r11,r26
	ctx.r5.u64 = ctx.r11.u64 + ctx.r26.u64;
	// bne cr6,0x8809a4c8
	if (!ctx.cr6.eq) goto loc_8809A4C8;
	// subf r5,r22,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r22.s64;
loc_8809A4C8:
	// stw r5,15024(r23)
	PPC_STORE_U32(ctx.r23.u32 + 15024, ctx.r5.u32);
	// addi r3,r28,20258
	ctx.r3.s64 = ctx.r28.s64 + 20258;
	// stw r4,15020(r23)
	PPC_STORE_U32(ctx.r23.u32 + 15020, ctx.r4.u32);
	// stw r4,10312(r23)
	PPC_STORE_U32(ctx.r23.u32 + 10312, ctx.r4.u32);
	// stw r5,10316(r23)
	PPC_STORE_U32(ctx.r23.u32 + 10316, ctx.r5.u32);
loc_8809A4DC:
	// addi r6,r21,-2
	ctx.r6.s64 = ctx.r21.s64 + -2;
	// bl 0x881538c0
	ctx.lr = 0x8809A4E4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r15,0
	ctx.cr6.compare<uint32_t>(ctx.r15.u32, 0, ctx.xer);
	// beq cr6,0x8809a534
	if (ctx.cr6.eq) goto loc_8809A534;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809a4fc
	if (ctx.cr6.eq) goto loc_8809A4FC;
	// lwz r11,0(r15)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_8809A4FC:
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809a534
	if (ctx.cr6.eq) goto loc_8809A534;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x8809a534
	if (ctx.cr6.eq) goto loc_8809A534;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r17,-11932(r14)
	PPC_STORE_U32(ctx.r14.u32 + -11932, ctx.r17.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_8809A534:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq cr6,0x8809a554
	if (ctx.cr6.eq) goto loc_8809A554;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809a554
	if (ctx.cr6.eq) goto loc_8809A554;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r25,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_8809A554:
	// lwz r11,10536(r23)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + 10536);
	// lwz r6,3664(r23)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r23.u32 + 3664);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8809a658
	if (ctx.cr6.eq) goto loc_8809A658;
	// addi r9,r31,-72
	ctx.r9.s64 = ctx.r31.s64 + -72;
	// lwz r11,-392(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -392);
	// addi r8,r31,-72
	ctx.r8.s64 = ctx.r31.s64 + -72;
	// lwz r10,-388(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -388);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// divw r9,r6,r18
	ctx.r9.s32 = ppc_divw(ctx.r6.s32, ctx.r18.s32);
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// lbzx r5,r29,r8
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r8.u32);
	// lbzx r4,r29,r7
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r7.u32);
	// extsb r7,r5
	ctx.r7.s64 = ctx.r5.s8;
	// extsb r8,r4
	ctx.r8.s64 = ctx.r4.s8;
	// add r3,r7,r11
	ctx.r3.u64 = ctx.r7.u64 + ctx.r11.u64;
	// add r11,r8,r10
	ctx.r11.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r10,r3,r30
	ctx.r10.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r30.s32);
	// mullw r8,r11,r30
	ctx.r8.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// rlwinm r11,r8,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r4,r10,r27
	ctx.r4.u64 = ctx.r10.u64 + ctx.r27.u64;
	// add r5,r11,r26
	ctx.r5.u64 = ctx.r11.u64 + ctx.r26.u64;
	// bne cr6,0x8809a5bc
	if (!ctx.cr6.eq) goto loc_8809A5BC;
	// add r5,r5,r22
	ctx.r5.u64 = ctx.r5.u64 + ctx.r22.u64;
loc_8809A5BC:
	// stw r4,15308(r23)
	PPC_STORE_U32(ctx.r23.u32 + 15308, ctx.r4.u32);
	// stw r5,15312(r23)
	PPC_STORE_U32(ctx.r23.u32 + 15312, ctx.r5.u32);
	// stw r5,10484(r23)
	PPC_STORE_U32(ctx.r23.u32 + 10484, ctx.r5.u32);
	// stw r4,10480(r23)
	PPC_STORE_U32(ctx.r23.u32 + 10480, ctx.r4.u32);
	// lwz r11,16(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8809a7d0
	if (!ctx.cr6.eq) goto loc_8809A7D0;
	// addi r6,r21,2
	ctx.r6.s64 = ctx.r21.s64 + 2;
	// addi r3,r28,20324
	ctx.r3.s64 = ctx.r28.s64 + 20324;
	// bl 0x881538c0
	ctx.lr = 0x8809A5E4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r15,0
	ctx.cr6.compare<uint32_t>(ctx.r15.u32, 0, ctx.xer);
	// beq cr6,0x8809a634
	if (ctx.cr6.eq) goto loc_8809A634;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809a5fc
	if (ctx.cr6.eq) goto loc_8809A5FC;
	// lwz r11,0(r15)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_8809A5FC:
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809a634
	if (ctx.cr6.eq) goto loc_8809A634;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x8809a634
	if (ctx.cr6.eq) goto loc_8809A634;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r17,-11932(r14)
	PPC_STORE_U32(ctx.r14.u32 + -11932, ctx.r17.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_8809A634:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq cr6,0x8809a7d0
	if (ctx.cr6.eq) goto loc_8809A7D0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809a7d0
	if (ctx.cr6.eq) goto loc_8809A7D0;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r25,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// b 0x8809a7d0
	goto loc_8809A7D0;
loc_8809A658:
	// addi r9,r31,-144
	ctx.r9.s64 = ctx.r31.s64 + -144;
	// lwz r11,-400(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -400);
	// addi r8,r31,-144
	ctx.r8.s64 = ctx.r31.s64 + -144;
	// lwz r10,-396(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -396);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// divw r9,r6,r18
	ctx.r9.s32 = ppc_divw(ctx.r6.s32, ctx.r18.s32);
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// lbzx r5,r29,r8
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r8.u32);
	// lbzx r4,r29,r7
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r7.u32);
	// extsb r7,r5
	ctx.r7.s64 = ctx.r5.s8;
	// extsb r8,r4
	ctx.r8.s64 = ctx.r4.s8;
	// add r3,r7,r11
	ctx.r3.u64 = ctx.r7.u64 + ctx.r11.u64;
	// add r11,r8,r10
	ctx.r11.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r10,r3,r30
	ctx.r10.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r30.s32);
	// mullw r8,r11,r30
	ctx.r8.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// rlwinm r11,r8,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r29,r10,r27
	ctx.r29.u64 = ctx.r10.u64 + ctx.r27.u64;
	// add r30,r11,r26
	ctx.r30.u64 = ctx.r11.u64 + ctx.r26.u64;
	// bne cr6,0x8809a6b0
	if (!ctx.cr6.eq) goto loc_8809A6B0;
	// add r30,r30,r22
	ctx.r30.u64 = ctx.r30.u64 + ctx.r22.u64;
loc_8809A6B0:
	// stw r29,15308(r23)
	PPC_STORE_U32(ctx.r23.u32 + 15308, ctx.r29.u32);
	// addi r6,r21,2
	ctx.r6.s64 = ctx.r21.s64 + 2;
	// stw r30,15312(r23)
	PPC_STORE_U32(ctx.r23.u32 + 15312, ctx.r30.u32);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// stw r29,10480(r23)
	PPC_STORE_U32(ctx.r23.u32 + 10480, ctx.r29.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r30,10484(r23)
	PPC_STORE_U32(ctx.r23.u32 + 10484, ctx.r30.u32);
	// addi r3,r28,20357
	ctx.r3.s64 = ctx.r28.s64 + 20357;
	// bl 0x881538c0
	ctx.lr = 0x8809A6D4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r15,0
	ctx.cr6.compare<uint32_t>(ctx.r15.u32, 0, ctx.xer);
	// beq cr6,0x8809a728
	if (ctx.cr6.eq) goto loc_8809A728;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809a6ec
	if (ctx.cr6.eq) goto loc_8809A6EC;
	// lwz r11,0(r15)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_8809A6EC:
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8809a72c
	if (ctx.cr6.eq) goto loc_8809A72C;
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x8809a72c
	if (ctx.cr6.eq) goto loc_8809A72C;
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r9,r11,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r17,-11932(r14)
	PPC_STORE_U32(ctx.r14.u32 + -11932, ctx.r17.u32);
	// or r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 | ctx.r8.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// b 0x8809a72c
	goto loc_8809A72C;
loc_8809A728:
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_8809A72C:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq cr6,0x8809a74c
	if (ctx.cr6.eq) goto loc_8809A74C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809a74c
	if (ctx.cr6.eq) goto loc_8809A74C;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r25,26,0,5
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 26) & 0xFC000000;
	// or r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 | ctx.r11.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_8809A74C:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8809a7d0
	if (!ctx.cr6.eq) goto loc_8809A7D0;
	// addi r7,r16,3
	ctx.r7.s64 = ctx.r16.s64 + 3;
	// lwz r8,8(r24)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r24.u32 + 8);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x88099698
	ctx.lr = 0x8809A770;
	sub_88099698(ctx, base);
	// srawi r11,r29,16
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0xFFFF) != 0);
	ctx.r11.s64 = ctx.r29.s32 >> 16;
	// addi r6,r16,-20
	ctx.r6.s64 = ctx.r16.s64 + -20;
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// addis r5,r30,-80
	ctx.r5.s64 = ctx.r30.s64 + -5242880;
	// addi r10,r11,-160
	ctx.r10.s64 = ctx.r11.s64 + -160;
	// li r3,15802
	ctx.r3.s64 = 15802;
	// mulli r9,r10,240
	ctx.r9.s64 = ctx.r10.s64 * 240;
	// srawi r8,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 1;
	// addze r7,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r7.s64 = temp.s64;
	// divw r11,r7,r19
	ctx.r11.s32 = ppc_divw(ctx.r7.s32, ctx.r19.s32);
	// addi r4,r11,160
	ctx.r4.s64 = ctx.r11.s64 + 160;
	// rlwinm r4,r4,16,0,15
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// bl 0x881538c0
	ctx.lr = 0x8809A7A4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809a7cc
	if (ctx.cr6.eq) goto loc_8809A7CC;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-11932(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + -11932);
	// oris r9,r10,518
	ctx.r9.u64 = ctx.r10.u64 | 33947648;
	// stw r20,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r20.u32);
	// addi r17,r11,1
	ctx.r17.s64 = ctx.r11.s64 + 1;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r17,-11932(r14)
	PPC_STORE_U32(ctx.r14.u32 + -11932, ctx.r17.u32);
	// b 0x8809a7d0
	goto loc_8809A7D0;
loc_8809A7CC:
	// lwz r17,-11932(r14)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r14.u32 + -11932);
loc_8809A7D0:
	// lwz r11,8(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 8);
	// li r30,1
	ctx.r30.s64 = 1;
	// li r25,1
	ctx.r25.s64 = 1;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// srawi r10,r11,3
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 3;
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// clrlwi r28,r9,26
	ctx.r28.u64 = ctx.r9.u32 & 0x3F;
	// cmpwi cr6,r28,32
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 32, ctx.xer);
	// ble cr6,0x8809a800
	if (!ctx.cr6.gt) goto loc_8809A800;
	// addi r28,r28,-32
	ctx.r28.s64 = ctx.r28.s64 + -32;
	// li r25,2
	ctx.r25.s64 = 2;
	// li r30,-1
	ctx.r30.s64 = -1;
loc_8809A800:
	// lwz r11,10452(r23)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + 10452);
	// rlwinm r29,r28,1,0,30
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r7,3664(r23)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r23.u32 + 3664);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8809a890
	if (ctx.cr6.eq) goto loc_8809A890;
	// addi r9,r31,-288
	ctx.r9.s64 = ctx.r31.s64 + -288;
	// lwz r11,-404(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -404);
	// addi r6,r31,-288
	ctx.r6.s64 = ctx.r31.s64 + -288;
	// lwz r10,-408(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -408);
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// divw r9,r7,r18
	ctx.r9.s32 = ppc_divw(ctx.r7.s32, ctx.r18.s32);
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// lbzx r4,r29,r6
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r6.u32);
	// lbzx r5,r29,r8
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r8.u32);
	// extsb r8,r4
	ctx.r8.s64 = ctx.r4.s8;
	// extsb r7,r5
	ctx.r7.s64 = ctx.r5.s8;
	// add r3,r7,r11
	ctx.r3.u64 = ctx.r7.u64 + ctx.r11.u64;
	// add r11,r8,r10
	ctx.r11.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r10,r3,r30
	ctx.r10.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r30.s32);
	// mullw r8,r11,r30
	ctx.r8.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r7,r8,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// subf r4,r7,r27
	ctx.r4.s64 = ctx.r27.s64 - ctx.r7.s64;
	// add r5,r11,r26
	ctx.r5.u64 = ctx.r11.u64 + ctx.r26.u64;
	// bne cr6,0x8809a86c
	if (!ctx.cr6.eq) goto loc_8809A86C;
	// subf r5,r22,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r22.s64;
loc_8809A86C:
	// stw r4,15164(r23)
	PPC_STORE_U32(ctx.r23.u32 + 15164, ctx.r4.u32);
	// stw r5,15168(r23)
	PPC_STORE_U32(ctx.r23.u32 + 15168, ctx.r5.u32);
	// stw r5,10400(r23)
	PPC_STORE_U32(ctx.r23.u32 + 10400, ctx.r5.u32);
	// stw r4,10396(r23)
	PPC_STORE_U32(ctx.r23.u32 + 10396, ctx.r4.u32);
	// lwz r11,16(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8809a974
	if (!ctx.cr6.eq) goto loc_8809A974;
	// addi r3,r28,20225
	ctx.r3.s64 = ctx.r28.s64 + 20225;
	// b 0x8809a8fc
	goto loc_8809A8FC;
loc_8809A890:
	// addi r9,r31,-360
	ctx.r9.s64 = ctx.r31.s64 + -360;
	// lwz r11,-412(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -412);
	// addi r6,r31,-360
	ctx.r6.s64 = ctx.r31.s64 + -360;
	// lwz r10,-416(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -416);
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// divw r9,r7,r18
	ctx.r9.s32 = ppc_divw(ctx.r7.s32, ctx.r18.s32);
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// lbzx r4,r29,r6
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r6.u32);
	// lbzx r5,r29,r8
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r8.u32);
	// extsb r8,r4
	ctx.r8.s64 = ctx.r4.s8;
	// extsb r7,r5
	ctx.r7.s64 = ctx.r5.s8;
	// add r3,r7,r11
	ctx.r3.u64 = ctx.r7.u64 + ctx.r11.u64;
	// add r11,r8,r10
	ctx.r11.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r10,r3,r30
	ctx.r10.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r30.s32);
	// mullw r8,r11,r30
	ctx.r8.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r7,r8,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// subf r4,r7,r27
	ctx.r4.s64 = ctx.r27.s64 - ctx.r7.s64;
	// add r5,r11,r26
	ctx.r5.u64 = ctx.r11.u64 + ctx.r26.u64;
	// bne cr6,0x8809a8e8
	if (!ctx.cr6.eq) goto loc_8809A8E8;
	// subf r5,r22,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r22.s64;
loc_8809A8E8:
	// stw r5,15168(r23)
	PPC_STORE_U32(ctx.r23.u32 + 15168, ctx.r5.u32);
	// addi r3,r28,20258
	ctx.r3.s64 = ctx.r28.s64 + 20258;
	// stw r4,15164(r23)
	PPC_STORE_U32(ctx.r23.u32 + 15164, ctx.r4.u32);
	// stw r4,10396(r23)
	PPC_STORE_U32(ctx.r23.u32 + 10396, ctx.r4.u32);
	// stw r5,10400(r23)
	PPC_STORE_U32(ctx.r23.u32 + 10400, ctx.r5.u32);
loc_8809A8FC:
	// addi r6,r21,-2
	ctx.r6.s64 = ctx.r21.s64 + -2;
	// bl 0x881538c0
	ctx.lr = 0x8809A904;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r15,0
	ctx.cr6.compare<uint32_t>(ctx.r15.u32, 0, ctx.xer);
	// beq cr6,0x8809a954
	if (ctx.cr6.eq) goto loc_8809A954;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809a91c
	if (ctx.cr6.eq) goto loc_8809A91C;
	// lwz r11,0(r15)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_8809A91C:
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809a954
	if (ctx.cr6.eq) goto loc_8809A954;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x8809a954
	if (ctx.cr6.eq) goto loc_8809A954;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r17,-11932(r14)
	PPC_STORE_U32(ctx.r14.u32 + -11932, ctx.r17.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_8809A954:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq cr6,0x8809a974
	if (ctx.cr6.eq) goto loc_8809A974;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809a974
	if (ctx.cr6.eq) goto loc_8809A974;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r25,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_8809A974:
	// lwz r11,10620(r23)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + 10620);
	// lwz r6,3664(r23)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r23.u32 + 3664);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8809aa78
	if (ctx.cr6.eq) goto loc_8809AA78;
	// addi r9,r31,-72
	ctx.r9.s64 = ctx.r31.s64 + -72;
	// lwz r11,-392(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -392);
	// addi r8,r31,-72
	ctx.r8.s64 = ctx.r31.s64 + -72;
	// lwz r10,-388(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -388);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// divw r9,r6,r18
	ctx.r9.s32 = ppc_divw(ctx.r6.s32, ctx.r18.s32);
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// lbzx r5,r29,r8
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r8.u32);
	// lbzx r4,r29,r7
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r7.u32);
	// extsb r7,r5
	ctx.r7.s64 = ctx.r5.s8;
	// extsb r8,r4
	ctx.r8.s64 = ctx.r4.s8;
	// add r3,r7,r11
	ctx.r3.u64 = ctx.r7.u64 + ctx.r11.u64;
	// add r11,r8,r10
	ctx.r11.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r10,r3,r30
	ctx.r10.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r30.s32);
	// mullw r8,r11,r30
	ctx.r8.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// rlwinm r11,r8,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r7,r10,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// subf r4,r7,r27
	ctx.r4.s64 = ctx.r27.s64 - ctx.r7.s64;
	// add r5,r11,r26
	ctx.r5.u64 = ctx.r11.u64 + ctx.r26.u64;
	// bne cr6,0x8809a9dc
	if (!ctx.cr6.eq) goto loc_8809A9DC;
	// add r5,r5,r22
	ctx.r5.u64 = ctx.r5.u64 + ctx.r22.u64;
loc_8809A9DC:
	// stw r4,15452(r23)
	PPC_STORE_U32(ctx.r23.u32 + 15452, ctx.r4.u32);
	// stw r5,15456(r23)
	PPC_STORE_U32(ctx.r23.u32 + 15456, ctx.r5.u32);
	// stw r5,10568(r23)
	PPC_STORE_U32(ctx.r23.u32 + 10568, ctx.r5.u32);
	// stw r4,10564(r23)
	PPC_STORE_U32(ctx.r23.u32 + 10564, ctx.r4.u32);
	// lwz r11,16(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8809abf0
	if (!ctx.cr6.eq) goto loc_8809ABF0;
	// addi r6,r21,2
	ctx.r6.s64 = ctx.r21.s64 + 2;
	// addi r3,r28,20324
	ctx.r3.s64 = ctx.r28.s64 + 20324;
	// bl 0x881538c0
	ctx.lr = 0x8809AA04;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r15,0
	ctx.cr6.compare<uint32_t>(ctx.r15.u32, 0, ctx.xer);
	// beq cr6,0x8809aa54
	if (ctx.cr6.eq) goto loc_8809AA54;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809aa1c
	if (ctx.cr6.eq) goto loc_8809AA1C;
	// lwz r11,0(r15)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_8809AA1C:
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809aa54
	if (ctx.cr6.eq) goto loc_8809AA54;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x8809aa54
	if (ctx.cr6.eq) goto loc_8809AA54;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r17,-11932(r14)
	PPC_STORE_U32(ctx.r14.u32 + -11932, ctx.r17.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_8809AA54:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq cr6,0x8809abf0
	if (ctx.cr6.eq) goto loc_8809ABF0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809abf0
	if (ctx.cr6.eq) goto loc_8809ABF0;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r25,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// b 0x8809abf0
	goto loc_8809ABF0;
loc_8809AA78:
	// addi r9,r31,-144
	ctx.r9.s64 = ctx.r31.s64 + -144;
	// lwz r11,-400(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -400);
	// addi r8,r31,-144
	ctx.r8.s64 = ctx.r31.s64 + -144;
	// lwz r10,-396(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -396);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// divw r9,r6,r18
	ctx.r9.s32 = ppc_divw(ctx.r6.s32, ctx.r18.s32);
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// lbzx r5,r29,r8
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r8.u32);
	// lbzx r4,r29,r7
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r7.u32);
	// extsb r7,r5
	ctx.r7.s64 = ctx.r5.s8;
	// extsb r8,r4
	ctx.r8.s64 = ctx.r4.s8;
	// add r3,r7,r11
	ctx.r3.u64 = ctx.r7.u64 + ctx.r11.u64;
	// add r11,r8,r10
	ctx.r11.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r10,r3,r30
	ctx.r10.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r30.s32);
	// mullw r8,r11,r30
	ctx.r8.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// rlwinm r11,r8,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r7,r10,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// subf r29,r7,r27
	ctx.r29.s64 = ctx.r27.s64 - ctx.r7.s64;
	// add r30,r11,r26
	ctx.r30.u64 = ctx.r11.u64 + ctx.r26.u64;
	// bne cr6,0x8809aad0
	if (!ctx.cr6.eq) goto loc_8809AAD0;
	// add r30,r30,r22
	ctx.r30.u64 = ctx.r30.u64 + ctx.r22.u64;
loc_8809AAD0:
	// stw r29,15452(r23)
	PPC_STORE_U32(ctx.r23.u32 + 15452, ctx.r29.u32);
	// addi r6,r21,2
	ctx.r6.s64 = ctx.r21.s64 + 2;
	// stw r30,15456(r23)
	PPC_STORE_U32(ctx.r23.u32 + 15456, ctx.r30.u32);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// stw r29,10564(r23)
	PPC_STORE_U32(ctx.r23.u32 + 10564, ctx.r29.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r30,10568(r23)
	PPC_STORE_U32(ctx.r23.u32 + 10568, ctx.r30.u32);
	// addi r3,r28,20357
	ctx.r3.s64 = ctx.r28.s64 + 20357;
	// bl 0x881538c0
	ctx.lr = 0x8809AAF4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r15,0
	ctx.cr6.compare<uint32_t>(ctx.r15.u32, 0, ctx.xer);
	// beq cr6,0x8809ab48
	if (ctx.cr6.eq) goto loc_8809AB48;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809ab0c
	if (ctx.cr6.eq) goto loc_8809AB0C;
	// lwz r11,0(r15)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_8809AB0C:
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8809ab4c
	if (ctx.cr6.eq) goto loc_8809AB4C;
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x8809ab4c
	if (ctx.cr6.eq) goto loc_8809AB4C;
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r9,r11,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r17,-11932(r14)
	PPC_STORE_U32(ctx.r14.u32 + -11932, ctx.r17.u32);
	// or r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 | ctx.r8.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// b 0x8809ab4c
	goto loc_8809AB4C;
loc_8809AB48:
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_8809AB4C:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq cr6,0x8809ab6c
	if (ctx.cr6.eq) goto loc_8809AB6C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809ab6c
	if (ctx.cr6.eq) goto loc_8809AB6C;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r25,26,0,5
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 26) & 0xFC000000;
	// or r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 | ctx.r11.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_8809AB6C:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8809abf0
	if (!ctx.cr6.eq) goto loc_8809ABF0;
	// addi r7,r16,3
	ctx.r7.s64 = ctx.r16.s64 + 3;
	// lwz r8,8(r24)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r24.u32 + 8);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x88099698
	ctx.lr = 0x8809AB90;
	sub_88099698(ctx, base);
	// srawi r11,r29,16
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0xFFFF) != 0);
	ctx.r11.s64 = ctx.r29.s32 >> 16;
	// addi r6,r16,-20
	ctx.r6.s64 = ctx.r16.s64 + -20;
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// addis r5,r30,-80
	ctx.r5.s64 = ctx.r30.s64 + -5242880;
	// addi r10,r11,-160
	ctx.r10.s64 = ctx.r11.s64 + -160;
	// li r3,15802
	ctx.r3.s64 = 15802;
	// mulli r9,r10,240
	ctx.r9.s64 = ctx.r10.s64 * 240;
	// srawi r8,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 1;
	// addze r7,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r7.s64 = temp.s64;
	// divw r11,r7,r19
	ctx.r11.s32 = ppc_divw(ctx.r7.s32, ctx.r19.s32);
	// addi r4,r11,160
	ctx.r4.s64 = ctx.r11.s64 + 160;
	// rlwinm r4,r4,16,0,15
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// bl 0x881538c0
	ctx.lr = 0x8809ABC4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809abec
	if (ctx.cr6.eq) goto loc_8809ABEC;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-11932(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + -11932);
	// oris r9,r10,518
	ctx.r9.u64 = ctx.r10.u64 | 33947648;
	// stw r20,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r20.u32);
	// addi r17,r11,1
	ctx.r17.s64 = ctx.r11.s64 + 1;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r17,-11932(r14)
	PPC_STORE_U32(ctx.r14.u32 + -11932, ctx.r17.u32);
	// b 0x8809abf0
	goto loc_8809ABF0;
loc_8809ABEC:
	// lwz r17,-11932(r14)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r14.u32 + -11932);
loc_8809ABF0:
	// lwz r22,80(r1)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r30,r23,9688
	ctx.r30.s64 = ctx.r23.s64 + 9688;
	// li r24,2
	ctx.r24.s64 = 2;
	// addi r27,r23,14616
	ctx.r27.s64 = ctx.r23.s64 + 14616;
	// addi r25,r23,3328
	ctx.r25.s64 = ctx.r23.s64 + 3328;
loc_8809AC04:
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// li r26,0
	ctx.r26.s64 = 0;
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// subf r11,r10,r16
	ctx.r11.s64 = ctx.r16.s64 - ctx.r10.s64;
	// srawi r8,r9,3
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 3;
	// addi r6,r11,2
	ctx.r6.s64 = ctx.r11.s64 + 2;
	// clrlwi r11,r8,26
	ctx.r11.u64 = ctx.r8.u32 & 0x3F;
	// cmpwi cr6,r11,32
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 32, ctx.xer);
	// ble cr6,0x8809ac3c
	if (!ctx.cr6.gt) goto loc_8809AC3C;
	// subfic r11,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r11.s64 = 64 - ctx.r11.s64;
	// li r26,1
	ctx.r26.s64 = 1;
	// li r5,-1
	ctx.r5.s64 = -1;
loc_8809AC3C:
	// addi r10,r31,216
	ctx.r10.s64 = ctx.r31.s64 + 216;
	// lwz r7,0(r25)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// rlwinm r4,r11,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// addi r10,r31,216
	ctx.r10.s64 = ctx.r31.s64 + 216;
	// divw r7,r7,r18
	ctx.r7.s32 = ppc_divw(ctx.r7.s32, ctx.r18.s32);
	// lbzx r3,r4,r3
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r3.u32);
	// lbzx r10,r4,r10
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r10.u32);
	// extsb r4,r3
	ctx.r4.s64 = ctx.r3.s8;
	// extsb r3,r10
	ctx.r3.s64 = ctx.r10.s8;
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// mullw r5,r3,r5
	ctx.r5.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r5.s32);
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// add r28,r10,r9
	ctx.r28.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r10,r5,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// stw r28,0(r27)
	PPC_STORE_U32(ctx.r27.u32 + 0, ctx.r28.u32);
	// add r29,r10,r8
	ctx.r29.u64 = ctx.r10.u64 + ctx.r8.u64;
	// stw r29,-4(r27)
	PPC_STORE_U32(ctx.r27.u32 + -4, ctx.r29.u32);
	// lwz r4,16(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne cr6,0x8809ad3c
	if (!ctx.cr6.eq) goto loc_8809AD3C;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r11,20523
	ctx.r3.s64 = ctx.r11.s64 + 20523;
	// bl 0x881538c0
	ctx.lr = 0x8809ACA8;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r15,0
	ctx.cr6.compare<uint32_t>(ctx.r15.u32, 0, ctx.xer);
	// beq cr6,0x8809acf4
	if (ctx.cr6.eq) goto loc_8809ACF4;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809acc0
	if (ctx.cr6.eq) goto loc_8809ACC0;
	// lwz r11,0(r15)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_8809ACC0:
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x8809acf4
	if (ctx.cr6.eq) goto loc_8809ACF4;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x8809acf4
	if (ctx.cr6.eq) goto loc_8809ACF4;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r17,-11932(r14)
	PPC_STORE_U32(ctx.r14.u32 + -11932, ctx.r17.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_8809ACF4:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq cr6,0x8809ad14
	if (ctx.cr6.eq) goto loc_8809AD14;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809ad14
	if (ctx.cr6.eq) goto loc_8809AD14;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r26,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_8809AD14:
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// bne cr6,0x8809ad3c
	if (!ctx.cr6.eq) goto loc_8809AD3C;
	// addi r7,r16,3
	ctx.r7.s64 = ctx.r16.s64 + 3;
	// lwz r8,8(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x88099698
	ctx.lr = 0x8809AD38;
	sub_88099698(ctx, base);
	// lwz r17,-11932(r14)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r14.u32 + -11932);
loc_8809AD3C:
	// addic. r24,r24,-1
	ctx.xer.ca = ctx.r24.u32 > 0;
	ctx.r24.s64 = ctx.r24.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// addi r30,r30,-20
	ctx.r30.s64 = ctx.r30.s64 + -20;
	// addi r25,r25,-288
	ctx.r25.s64 = ctx.r25.s64 + -288;
	// addi r27,r27,-8
	ctx.r27.s64 = ctx.r27.s64 + -8;
	// bge 0x8809ac04
	if (!ctx.cr0.lt) goto loc_8809AC04;
	// lwz r10,9636(r23)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r23.u32 + 9636);
	// addi r27,r23,9628
	ctx.r27.s64 = ctx.r23.s64 + 9628;
	// lwz r11,9640(r23)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + 9640);
	// li r24,1
	ctx.r24.s64 = 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// subf r11,r11,r16
	ctx.r11.s64 = ctx.r16.s64 - ctx.r11.s64;
	// srawi r9,r10,3
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 3;
	// li r19,0
	ctx.r19.s64 = 0;
	// clrlwi r25,r9,26
	ctx.r25.u64 = ctx.r9.u32 & 0x3F;
	// addi r20,r11,2
	ctx.r20.s64 = ctx.r11.s64 + 2;
	// cmpwi cr6,r25,32
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 32, ctx.xer);
	// ble cr6,0x8809ad8c
	if (!ctx.cr6.gt) goto loc_8809AD8C;
	// subfic r25,r25,64
	ctx.xer.ca = ctx.r25.u32 <= 64;
	ctx.r25.s64 = 64 - ctx.r25.s64;
	// li r19,1
	ctx.r19.s64 = 1;
	// li r24,-1
	ctx.r24.s64 = -1;
loc_8809AD8C:
	// lwz r9,2464(r23)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r23.u32 + 2464);
	// rlwinm r30,r25,1,0,30
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r31,144
	ctx.r11.s64 = ctx.r31.s64 + 144;
	// lwz r6,4(r27)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// addi r5,r31,144
	ctx.r5.s64 = ctx.r31.s64 + 144;
	// lwz r10,-368(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -368);
	// divw r7,r9,r18
	ctx.r7.s32 = ppc_divw(ctx.r9.s32, ctx.r18.s32);
	// lwz r8,0(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// lwz r11,-364(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -364);
	// add r3,r7,r6
	ctx.r3.u64 = ctx.r7.u64 + ctx.r6.u64;
	// rlwinm r9,r24,18,0,13
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 18) & 0xFFFC0000;
	// lbzx r7,r30,r5
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r5.u32);
	// addis r22,r3,-4
	ctx.r22.s64 = ctx.r3.s64 + -262144;
	// add r21,r9,r8
	ctx.r21.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lbzx r6,r30,r4
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r4.u32);
	// extsb r7,r7
	ctx.r7.s64 = ctx.r7.s8;
	// add r5,r7,r10
	ctx.r5.u64 = ctx.r7.u64 + ctx.r10.u64;
	// extsb r6,r6
	ctx.r6.s64 = ctx.r6.s8;
	// mullw r3,r5,r24
	ctx.r3.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r24.s32);
	// add r4,r6,r11
	ctx.r4.u64 = ctx.r6.u64 + ctx.r11.u64;
	// rlwinm r11,r3,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// add r28,r11,r21
	ctx.r28.u64 = ctx.r11.u64 + ctx.r21.u64;
	// add r29,r10,r22
	ctx.r29.u64 = ctx.r10.u64 + ctx.r22.u64;
	// stw r28,14588(r23)
	PPC_STORE_U32(ctx.r23.u32 + 14588, ctx.r28.u32);
	// stw r29,14592(r23)
	PPC_STORE_U32(ctx.r23.u32 + 14592, ctx.r29.u32);
	// lwz r11,16(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8809b128
	if (!ctx.cr6.eq) goto loc_8809B128;
	// addi r26,r25,20456
	ctx.r26.s64 = ctx.r25.s64 + 20456;
	// mr r6,r20
	ctx.r6.u64 = ctx.r20.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x881538c0
	ctx.lr = 0x8809AE1C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r15,0
	ctx.cr6.compare<uint32_t>(ctx.r15.u32, 0, ctx.xer);
	// beq cr6,0x8809ae70
	if (ctx.cr6.eq) goto loc_8809AE70;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809ae34
	if (ctx.cr6.eq) goto loc_8809AE34;
	// lwz r11,0(r15)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_8809AE34:
	// lwz r18,80(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// beq cr6,0x8809ae74
	if (ctx.cr6.eq) goto loc_8809AE74;
	// lwz r11,0(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x8809ae74
	if (ctx.cr6.eq) goto loc_8809AE74;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r17,-11932(r14)
	PPC_STORE_U32(ctx.r14.u32 + -11932, ctx.r17.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// b 0x8809ae74
	goto loc_8809AE74;
loc_8809AE70:
	// lwz r18,80(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_8809AE74:
	// cmpwi cr6,r19,0
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 0, ctx.xer);
	// beq cr6,0x8809ae94
	if (ctx.cr6.eq) goto loc_8809AE94;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809ae94
	if (ctx.cr6.eq) goto loc_8809AE94;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r19,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_8809AE94:
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// bne cr6,0x8809af40
	if (!ctx.cr6.eq) goto loc_8809AF40;
	// srawi r11,r28,16
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0xFFFF) != 0);
	ctx.r11.s64 = ctx.r28.s32 >> 16;
	// li r10,160
	ctx.r10.s64 = 160;
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// addi r9,r11,-160
	ctx.r9.s64 = ctx.r11.s64 + -160;
	// addis r29,r29,-80
	ctx.r29.s64 = ctx.r29.s64 + -5242880;
	// mulli r8,r9,240
	ctx.r8.s64 = ctx.r9.s64 * 240;
	// srawi r7,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 1;
	// addi r28,r16,-20
	ctx.r28.s64 = ctx.r16.s64 + -20;
	// addze r5,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r5.s64 = temp.s64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// divw r11,r5,r10
	ctx.r11.s32 = ppc_divw(ctx.r5.s32, ctx.r10.s32);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r4,r11,160
	ctx.r4.s64 = ctx.r11.s64 + 160;
	// rlwinm r26,r4,16,0,15
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x881538c0
	ctx.lr = 0x8809AEE0;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809af10
	if (ctx.cr6.eq) goto loc_8809AF10;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r19,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 26) & 0xFC000000;
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r17,-11932(r14)
	PPC_STORE_U32(ctx.r14.u32 + -11932, ctx.r17.u32);
	// oris r7,r9,547
	ctx.r7.u64 = ctx.r9.u64 | 35848192;
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// ori r7,r7,4096
	ctx.r7.u64 = ctx.r7.u64 | 4096;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
loc_8809AF10:
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// li r3,15802
	ctx.r3.s64 = 15802;
	// bl 0x881538c0
	ctx.lr = 0x8809AF24;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809af40
	if (ctx.cr6.eq) goto loc_8809AF40;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r11,r17,1
	ctx.r11.s64 = ctx.r17.s64 + 1;
	// oris r9,r10,518
	ctx.r9.u64 = ctx.r10.u64 | 33947648;
	// stw r11,-11932(r14)
	PPC_STORE_U32(ctx.r14.u32 + -11932, ctx.r11.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_8809AF40:
	// lwz r11,8(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 8);
	// mr r7,r18
	ctx.r7.u64 = ctx.r18.u64;
	// mr r6,r15
	ctx.r6.u64 = ctx.r15.u64;
	// cmpwi cr6,r11,256
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 256, ctx.xer);
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bge cr6,0x8809af6c
	if (!ctx.cr6.lt) goto loc_8809AF6C;
	// addi r5,r20,1
	ctx.r5.s64 = ctx.r20.s64 + 1;
	// bl 0x88099900
	ctx.lr = 0x8809AF64;
	sub_88099900(ctx, base);
	// mr r5,r20
	ctx.r5.u64 = ctx.r20.u64;
	// b 0x8809af90
	goto loc_8809AF90;
loc_8809AF6C:
	// ble cr6,0x8809af80
	if (!ctx.cr6.gt) goto loc_8809AF80;
	// mr r5,r20
	ctx.r5.u64 = ctx.r20.u64;
	// bl 0x88099900
	ctx.lr = 0x8809AF78;
	sub_88099900(ctx, base);
	// addi r5,r20,1
	ctx.r5.s64 = ctx.r20.s64 + 1;
	// b 0x8809af90
	goto loc_8809AF90;
loc_8809AF80:
	// addi r29,r20,1
	ctx.r29.s64 = ctx.r20.s64 + 1;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x88099900
	ctx.lr = 0x8809AF8C;
	sub_88099900(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
loc_8809AF90:
	// mr r7,r18
	ctx.r7.u64 = ctx.r18.u64;
	// mr r6,r15
	ctx.r6.u64 = ctx.r15.u64;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x88099900
	ctx.lr = 0x8809AFA4;
	sub_88099900(ctx, base);
	// addi r9,r31,72
	ctx.r9.s64 = ctx.r31.s64 + 72;
	// addi r8,r31,72
	ctx.r8.s64 = ctx.r31.s64 + 72;
	// lwz r11,-376(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -376);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// lwz r10,-372(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -372);
	// mr r6,r20
	ctx.r6.u64 = ctx.r20.u64;
	// addi r3,r25,20423
	ctx.r3.s64 = ctx.r25.s64 + 20423;
	// lbzx r5,r30,r8
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r8.u32);
	// lbzx r4,r30,r7
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r7.u32);
	// extsb r8,r5
	ctx.r8.s64 = ctx.r5.s8;
	// extsb r9,r4
	ctx.r9.s64 = ctx.r4.s8;
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r9,r11,r24
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r24.s32);
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r9,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// add r5,r10,r22
	ctx.r5.u64 = ctx.r10.u64 + ctx.r22.u64;
	// add r4,r11,r21
	ctx.r4.u64 = ctx.r11.u64 + ctx.r21.u64;
	// bl 0x881538c0
	ctx.lr = 0x8809AFF0;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r15,0
	ctx.cr6.compare<uint32_t>(ctx.r15.u32, 0, ctx.xer);
	// beq cr6,0x8809b044
	if (ctx.cr6.eq) goto loc_8809B044;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809b008
	if (ctx.cr6.eq) goto loc_8809B008;
	// lwz r11,0(r15)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_8809B008:
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// beq cr6,0x8809b044
	if (ctx.cr6.eq) goto loc_8809B044;
	// lwz r11,0(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x8809b044
	if (ctx.cr6.eq) goto loc_8809B044;
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-11932(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + -11932);
	// rlwimi r9,r10,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// addi r29,r11,1
	ctx.r29.s64 = ctx.r11.s64 + 1;
	// or r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 | ctx.r8.u64;
	// stw r29,-11932(r14)
	PPC_STORE_U32(ctx.r14.u32 + -11932, ctx.r29.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// b 0x8809b048
	goto loc_8809B048;
loc_8809B044:
	// lwz r29,-11932(r14)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r14.u32 + -11932);
loc_8809B048:
	// cmpwi cr6,r19,0
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 0, ctx.xer);
	// beq cr6,0x8809b068
	if (ctx.cr6.eq) goto loc_8809B068;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809b068
	if (ctx.cr6.eq) goto loc_8809B068;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r19,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_8809B068:
	// lbzx r10,r30,r31
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r31.u32);
	// addi r8,r31,1
	ctx.r8.s64 = ctx.r31.s64 + 1;
	// lwz r11,-384(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -384);
	// addi r6,r20,2
	ctx.r6.s64 = ctx.r20.s64 + 2;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// lwz r10,-380(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -380);
	// addi r3,r25,20390
	ctx.r3.s64 = ctx.r25.s64 + 20390;
	// add r7,r9,r11
	ctx.r7.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lbzx r5,r30,r8
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r8.u32);
	// mullw r4,r7,r24
	ctx.r4.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r24.s32);
	// extsb r9,r5
	ctx.r9.s64 = ctx.r5.s8;
	// rlwinm r11,r4,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r4,r11,r21
	ctx.r4.u64 = ctx.r11.u64 + ctx.r21.u64;
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r5,r11,r22
	ctx.r5.u64 = ctx.r11.u64 + ctx.r22.u64;
	// bl 0x881538c0
	ctx.lr = 0x8809B0AC;
	sub_881538C0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r15,0
	ctx.cr6.compare<uint32_t>(ctx.r15.u32, 0, ctx.xer);
	// beq cr6,0x8809b0fc
	if (ctx.cr6.eq) goto loc_8809B0FC;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809b0c8
	if (ctx.cr6.eq) goto loc_8809B0C8;
	// lwz r10,0(r15)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	// stw r10,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r10.u32);
loc_8809B0C8:
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// beq cr6,0x8809b0fc
	if (ctx.cr6.eq) goto loc_8809B0FC;
	// lwz r10,0(r18)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// beq cr6,0x8809b0fc
	if (ctx.cr6.eq) goto loc_8809B0FC;
	// lis r8,545
	ctx.r8.s64 = 35717120;
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r29,1
	ctx.r10.s64 = ctx.r29.s64 + 1;
	// rlwimi r8,r9,8,16,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r9.u32, 8) & 0xFF00) | (ctx.r8.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r10,-11932(r14)
	PPC_STORE_U32(ctx.r14.u32 + -11932, ctx.r10.u32);
	// or r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 | ctx.r7.u64;
	// stw r6,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r6.u32);
loc_8809B0FC:
	// cmpwi cr6,r19,0
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 0, ctx.xer);
	// beq cr6,0x8809b128
	if (ctx.cr6.eq) goto loc_8809B128;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// beq cr6,0x8809b12c
	if (ctx.cr6.eq) goto loc_8809B12C;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm r9,r19,26,0,5
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 26) & 0xFC000000;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
loc_8809B128:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8809B12C:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809B134"))) PPC_WEAK_FUNC(sub_8809B134);
PPC_FUNC_IMPL(__imp__sub_8809B134) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8809B138"))) PPC_WEAK_FUNC(sub_8809B138);
PPC_FUNC_IMPL(__imp__sub_8809B138) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,255
	ctx.r10.s64 = 16711680;
	// addi r11,r4,15596
	ctx.r11.s64 = ctx.r4.s64 + 15596;
	// addi r9,r4,15592
	ctx.r9.s64 = ctx.r4.s64 + 15592;
	// ori r8,r10,65535
	ctx.r8.u64 = ctx.r10.u64 | 65535;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// lis r7,-30710
	ctx.r7.s64 = -2012610560;
	// stw r8,15596(r4)
	PPC_STORE_U32(ctx.r4.u32 + 15596, ctx.r8.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r7,-25448
	ctx.r5.s64 = ctx.r7.s64 + -25448;
	// li r4,30
	ctx.r4.s64 = 30;
	// bl 0x88096460
	ctx.lr = 0x8809B174;
	sub_88096460(ctx, base);
	// lis r6,-30641
	ctx.r6.s64 = -2008088576;
	// addi r5,r6,-18792
	ctx.r5.s64 = ctx.r6.s64 + -18792;
	// stw r3,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r3.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8809B190"))) PPC_WEAK_FUNC(sub_8809B190);
PPC_FUNC_IMPL(__imp__sub_8809B190) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r4,14848
	ctx.r11.s64 = ctx.r4.s64 + 14848;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lis r9,-30710
	ctx.r9.s64 = -2012610560;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r9,-25448
	ctx.r5.s64 = ctx.r9.s64 + -25448;
	// li r4,30
	ctx.r4.s64 = 30;
	// bl 0x88096460
	ctx.lr = 0x8809B1C0;
	sub_88096460(ctx, base);
	// lis r8,-30641
	ctx.r8.s64 = -2008088576;
	// stw r3,-18792(r8)
	PPC_STORE_U32(ctx.r8.u32 + -18792, ctx.r3.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8809B1D8"))) PPC_WEAK_FUNC(sub_8809B1D8);
PPC_FUNC_IMPL(__imp__sub_8809B1D8) {
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
	// lwz r11,0(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r3,r11,15656
	ctx.r3.s64 = ctx.r11.s64 + 15656;
	// lwz r10,15652(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15652);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r10,15652(r11)
	PPC_STORE_U32(ctx.r11.u32 + 15652, ctx.r10.u32);
	// bl 0x88072260
	ctx.lr = 0x8809B208;
	sub_88072260(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8809B21C"))) PPC_WEAK_FUNC(sub_8809B21C);
PPC_FUNC_IMPL(__imp__sub_8809B21C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8809B220"))) PPC_WEAK_FUNC(sub_8809B220);
PPC_FUNC_IMPL(__imp__sub_8809B220) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071140
	ctx.lr = 0x8809B228;
	__savegprlr_22(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// lwz r11,116(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8809b340
	if (ctx.cr6.eq) goto loc_8809B340;
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
	// bge 0x8809b340
	if (!ctx.cr0.lt) goto loc_8809B340;
	// lwz r10,112(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// li r26,0
	ctx.r26.s64 = 0;
	// lwz r30,128(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// li r3,49
	ctx.r3.s64 = 49;
	// lwz r9,132(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// lwz r29,8(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// subf r11,r9,r30
	ctx.r11.s64 = ctx.r30.s64 - ctx.r9.s64;
	// lwz r28,12(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// stw r10,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r10.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r8,184(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// addi r11,r11,192
	ctx.r11.s64 = ctx.r11.s64 + 192;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r27.u32);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// sth r26,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r26.u16);
	// clrlwi r7,r11,16
	ctx.r7.u64 = ctx.r11.u32 & 0xFFFF;
	// bl 0x8815c948
	ctx.lr = 0x8809B298;
	sub_8815C948(ctx, base);
	// li r22,2
	ctx.r22.s64 = 2;
	// li r23,8
	ctx.r23.s64 = 8;
	// li r24,-3
	ctx.r24.s64 = -3;
	// li r25,1
	ctx.r25.s64 = 1;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809b2d0
	if (ctx.cr6.eq) goto loc_8809B2D0;
	// stb r22,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r22.u8);
	// li r5,72
	ctx.r5.s64 = 72;
	// sth r23,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, ctx.r23.u16);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// sth r24,28(r3)
	PPC_STORE_U16(ctx.r3.u32 + 28, ctx.r24.u16);
	// stw r25,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r25.u32);
	// addi r3,r3,36
	ctx.r3.s64 = ctx.r3.s64 + 36;
	// bl 0x88072260
	ctx.lr = 0x8809B2D0;
	sub_88072260(ctx, base);
loc_8809B2D0:
	// lwz r11,132(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// lwz r10,184(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r27.u32);
	// extsh r6,r10
	ctx.r6.s64 = ctx.r10.s16;
	// sth r26,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r26.u16);
	// addi r11,r11,-192
	ctx.r11.s64 = ctx.r11.s64 + -192;
	// li r3,49
	ctx.r3.s64 = 49;
	// clrlwi r7,r11,16
	ctx.r7.u64 = ctx.r11.u32 & 0xFFFF;
	// bl 0x8815c948
	ctx.lr = 0x8809B300;
	sub_8815C948(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809b328
	if (ctx.cr6.eq) goto loc_8809B328;
	// stb r22,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r22.u8);
	// li r5,72
	ctx.r5.s64 = 72;
	// sth r23,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, ctx.r23.u16);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// sth r24,28(r3)
	PPC_STORE_U16(ctx.r3.u32 + 28, ctx.r24.u16);
	// stw r25,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r25.u32);
	// addi r3,r3,36
	ctx.r3.s64 = ctx.r3.s64 + 36;
	// bl 0x88072260
	ctx.lr = 0x8809B328;
	sub_88072260(ctx, base);
loc_8809B328:
	// lwz r10,132(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// lwz r11,116(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// stw r10,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r10.u32);
	// stw r9,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r9.u32);
loc_8809B340:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x88071190
	__restgprlr_22(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809B348"))) PPC_WEAK_FUNC(sub_8809B348);
PPC_FUNC_IMPL(__imp__sub_8809B348) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x8809B350;
	__savegprlr_25(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// lwz r11,116(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8809b430
	if (ctx.cr6.eq) goto loc_8809B430;
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
	// bge 0x8809b430
	if (!ctx.cr0.lt) goto loc_8809B430;
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// lwz r9,112(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// lwz r30,128(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// li r26,0
	ctx.r26.s64 = 0;
	// lwz r8,132(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// lwz r28,8(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// subf r11,r8,r30
	ctx.r11.s64 = ctx.r30.s64 - ctx.r8.s64;
	// lwz r27,12(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r29,26276(r10)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26276);
	// lwz r10,184(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// addi r11,r11,192
	ctx.r11.s64 = ctx.r11.s64 + 192;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// stw r9,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r9.u32);
	// bne cr6,0x8809b3d8
	if (!ctx.cr6.eq) goto loc_8809B3D8;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// clrlwi r7,r11,16
	ctx.r7.u64 = ctx.r11.u32 & 0xFFFF;
	// extsh r6,r10
	ctx.r6.s64 = ctx.r10.s16;
	// sth r26,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r26.u16);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r3,49
	ctx.r3.s64 = 49;
	// bl 0x8815c948
	ctx.lr = 0x8809B3D0;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x8809B3D8;
	sub_8815C860(ctx, base);
loc_8809B3D8:
	// lwz r11,132(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// lwz r10,184(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r11,r11,-192
	ctx.r11.s64 = ctx.r11.s64 + -192;
	// bne cr6,0x8809b418
	if (!ctx.cr6.eq) goto loc_8809B418;
	// clrlwi r7,r11,16
	ctx.r7.u64 = ctx.r11.u32 & 0xFFFF;
	// stw r25,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r25.u32);
	// extsh r6,r10
	ctx.r6.s64 = ctx.r10.s16;
	// sth r26,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r26.u16);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r3,49
	ctx.r3.s64 = 49;
	// bl 0x8815c948
	ctx.lr = 0x8809B410;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x8809B418;
	sub_8815C860(ctx, base);
loc_8809B418:
	// lwz r10,132(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// lwz r11,116(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// stw r10,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r10.u32);
	// stw r9,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r9.u32);
loc_8809B430:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809B438"))) PPC_WEAK_FUNC(sub_8809B438);
PPC_FUNC_IMPL(__imp__sub_8809B438) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r9,96(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 96);
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
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r7,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r7.u32);
	// stw r10,-104(r11)
	PPC_STORE_U32(ctx.r11.u32 + -104, ctx.r10.u32);
	// stwx r9,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + ctx.r11.u32, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8809B478"))) PPC_WEAK_FUNC(sub_8809B478);
PPC_FUNC_IMPL(__imp__sub_8809B478) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x8809B480;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r11,-30681
	ctx.r11.s64 = -2010710016;
	// li r6,214
	ctx.r6.s64 = 214;
	// addi r11,r11,16464
	ctx.r11.s64 = ctx.r11.s64 + 16464;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r29,r10,64
	ctx.r29.s64 = ctx.r10.s64 + 64;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// rlwinm r30,r29,1,0,30
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r3,r29,10750
	ctx.r3.s64 = ctx.r29.s64 + 10750;
	// lbzx r7,r30,r11
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r11.u32);
	// lbzx r5,r30,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r9.u32);
	// extsb r4,r7
	ctx.r4.s64 = ctx.r7.s8;
	// extsb r11,r5
	ctx.r11.s64 = ctx.r5.s8;
	// rlwinm r9,r4,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r9,r10
	ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r5,r11,r8
	ctx.r5.u64 = ctx.r11.u64 + ctx.r8.u64;
	// bl 0x881538c0
	ctx.lr = 0x8809B4D4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809b4e4
	if (ctx.cr6.eq) goto loc_8809B4E4;
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_8809B4E4:
	// lis r11,-30681
	ctx.r11.s64 = -2010710016;
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r6,214
	ctx.r6.s64 = 214;
	// addi r11,r11,16720
	ctx.r11.s64 = ctx.r11.s64 + 16720;
	// addi r3,r29,10878
	ctx.r3.s64 = ctx.r29.s64 + 10878;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// lbzx r7,r30,r11
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r11.u32);
	// lbzx r5,r30,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r9.u32);
	// extsb r4,r7
	ctx.r4.s64 = ctx.r7.s8;
	// extsb r11,r5
	ctx.r11.s64 = ctx.r5.s8;
	// rlwinm r9,r4,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r9,r8
	ctx.r4.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x8809B524;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809b554
	if (ctx.cr6.eq) goto loc_8809B554;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// oris r7,r8,545
	ctx.r7.u64 = ctx.r8.u64 | 35717120;
	// ori r7,r7,61440
	ctx.r7.u64 = ctx.r7.u64 | 61440;
	// lwz r11,-11932(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11932);
	// stw r9,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r9.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r11,-11932(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11932, ctx.r11.u32);
loc_8809B554:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809B55C"))) PPC_WEAK_FUNC(sub_8809B55C);
PPC_FUNC_IMPL(__imp__sub_8809B55C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8809B560"))) PPC_WEAK_FUNC(sub_8809B560);
PPC_FUNC_IMPL(__imp__sub_8809B560) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x8809B568;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,172(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 172);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// blt cr6,0x8809b58c
	if (ctx.cr6.lt) goto loc_8809B58C;
	// lwz r11,188(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 188);
	// add r25,r11,r10
	ctx.r25.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x8809b598
	goto loc_8809B598;
loc_8809B58C:
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 184);
	// lwz r11,168(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 168);
	// add r25,r10,r11
	ctx.r25.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_8809B598:
	// li r6,32
	ctx.r6.s64 = 32;
	// lwz r30,0(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r5,40
	ctx.r5.s64 = 40;
	// li r4,93
	ctx.r4.s64 = 93;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x880e32d0
	ctx.lr = 0x8809B5B0;
	sub_880E32D0(ctx, base);
	// lis r27,-30667
	ctx.r27.s64 = -2009792512;
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r28,-30667
	ctx.r28.s64 = -2009792512;
	// lis r29,-30667
	ctx.r29.s64 = -2009792512;
	// lis r26,-30667
	ctx.r26.s64 = -2009792512;
	// stw r11,12380(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12380, ctx.r11.u32);
	// addi r4,r25,2
	ctx.r4.s64 = ctx.r25.s64 + 2;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r10.u32);
	// stw r4,12376(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12376, ctx.r4.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// stw r11,12364(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12364, ctx.r11.u32);
	// bl 0x880f52c8
	ctx.lr = 0x8809B5E8;
	sub_880F52C8(ctx, base);
	// lwz r11,15632(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 15632);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8809b610
	if (!ctx.cr6.eq) goto loc_8809B610;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r8,15648(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 15648);
	// lwz r7,15644(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 15644);
	// lwz r6,15640(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 15640);
	// lwz r5,15636(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 15636);
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// bl 0x880f5438
	ctx.lr = 0x8809B610;
	sub_880F5438(ctx, base);
loc_8809B610:
	// lwz r11,15632(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 15632);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8809b658
	if (!ctx.cr6.eq) goto loc_8809B658;
	// lwz r11,15636(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 15636);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8809b658
	if (!ctx.cr6.eq) goto loc_8809B658;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r8,140
	ctx.r8.s64 = 140;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r9,12380(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12380, ctx.r9.u32);
	// li r4,140
	ctx.r4.s64 = 140;
	// stw r8,12376(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12376, ctx.r8.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,12364(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r10.u32);
	// bl 0x881607f8
	ctx.lr = 0x8809B658;
	sub_881607F8(ctx, base);
loc_8809B658:
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809B66C"))) PPC_WEAK_FUNC(sub_8809B66C);
PPC_FUNC_IMPL(__imp__sub_8809B66C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8809B670"))) PPC_WEAK_FUNC(sub_8809B670);
PPC_FUNC_IMPL(__imp__sub_8809B670) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,2304(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,15632(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15632);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8809b6ac
	if (ctx.cr6.eq) goto loc_8809B6AC;
	// bl 0x8809b560
	ctx.lr = 0x8809B6A0;
	sub_8809B560(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88094220
	ctx.lr = 0x8809B6A8;
	sub_88094220(ctx, base);
	// b 0x8809b854
	goto loc_8809B854;
loc_8809B6AC:
	// lwz r11,96(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809b6dc
	if (ctx.cr6.eq) goto loc_8809B6DC;
loc_8809B6C4:
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// stw r5,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r5.u32);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8809b6c4
	if (!ctx.cr6.eq) goto loc_8809B6C4;
loc_8809B6DC:
	// lis r11,128
	ctx.r11.s64 = 8388608;
	// clrlwi r10,r10,20
	ctx.r10.u64 = ctx.r10.u32 & 0xFFF;
	// ori r9,r11,32896
	ctx.r9.u64 = ctx.r11.u64 | 32896;
	// rlwinm r10,r10,0,26,21
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFC3F;
	// stw r9,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, ctx.r9.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8809b71c
	if (ctx.cr6.eq) goto loc_8809B71C;
	// lwz r11,84(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// stw r11,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, ctx.r11.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8809b71c
	if (ctx.cr6.eq) goto loc_8809B71C;
	// lis r11,192
	ctx.r11.s64 = 12582912;
	// ori r10,r11,49152
	ctx.r10.u64 = ctx.r11.u64 | 49152;
	// stw r10,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, ctx.r10.u32);
loc_8809B71C:
	// lwz r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// lis r6,-30643
	ctx.r6.s64 = -2008219648;
	// lwz r7,20(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// lwz r8,12(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r4,r10,9552
	ctx.r4.s64 = ctx.r10.s64 + 9552;
	// addi r10,r11,128
	ctx.r10.s64 = ctx.r11.s64 + 128;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r30,r10,2,21,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0x7FC;
	// lwz r10,26272(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 26272);
	// lis r6,-30597
	ctx.r6.s64 = -2005204992;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwzx r10,r9,r4
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r4.u32);
	// lwzx r4,r30,r4
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r4.u32);
	// mullw r9,r10,r7
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32);
	// lwz r6,-11984(r6)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + -11984);
	// mullw r7,r4,r7
	ctx.r7.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r7.s32);
	// add r10,r9,r11
	ctx.r10.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r11,r7,r8
	ctx.r11.u64 = ctx.r7.u64 + ctx.r8.u64;
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// beq cr6,0x8809b784
	if (ctx.cr6.eq) goto loc_8809B784;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// b 0x8809b794
	goto loc_8809B794;
loc_8809B784:
	// lwz r10,92(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// addi r10,r10,51
	ctx.r10.s64 = ctx.r10.s64 + 51;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r9,r6
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r6.u32);
loc_8809B794:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r7,64
	ctx.r7.s64 = 4194304;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add. r9,r11,r7
	ctx.r9.u64 = ctx.r11.u64 + ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r8,r11,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// and r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 & ctx.r11.u64;
	// ble 0x8809b804
	if (!ctx.cr0.gt) goto loc_8809B804;
	// lis r8,128
	ctx.r8.s64 = 8388608;
	// lis r4,320
	ctx.r4.s64 = 20971520;
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// cmpw cr6,r9,r4
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r4.s32, ctx.xer);
	// bge cr6,0x8809b804
	if (!ctx.cr6.lt) goto loc_8809B804;
	// addi r11,r11,55
	ctx.r11.s64 = ctx.r11.s64 + 55;
	// lis r9,-40
	ctx.r9.s64 = -2621440;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r4,r6
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r6.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// ble cr6,0x8809b804
	if (!ctx.cr6.gt) goto loc_8809B804;
	// lis r10,280
	ctx.r10.s64 = 18350080;
	// subf r9,r8,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r8.s64;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x8809b824
	if (ctx.cr6.lt) goto loc_8809B824;
loc_8809B804:
	// lwz r11,88(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8809b82c
	if (ctx.cr6.eq) goto loc_8809B82C;
	// lwz r11,96(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r5,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r5.u32);
	// bl 0x88094220
	ctx.lr = 0x8809B820;
	sub_88094220(ctx, base);
	// b 0x8809b854
	goto loc_8809B854;
loc_8809B824:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,88(r3)
	PPC_STORE_U32(ctx.r3.u32 + 88, ctx.r11.u32);
loc_8809B82C:
	// lwz r11,44(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r11.u32);
	// bge 0x8809b854
	if (!ctx.cr0.lt) goto loc_8809B854;
	// lwz r11,52(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// clrlwi r8,r9,29
	ctx.r8.u64 = ctx.r9.u32 & 0x7;
	// stw r10,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r10.u32);
	// stw r8,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r8.u32);
loc_8809B854:
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

__attribute__((alias("__imp__sub_8809B86C"))) PPC_WEAK_FUNC(sub_8809B86C);
PPC_FUNC_IMPL(__imp__sub_8809B86C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8809B870"))) PPC_WEAK_FUNC(sub_8809B870);
PPC_FUNC_IMPL(__imp__sub_8809B870) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x8809B878;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30710
	ctx.r11.s64 = -2012610560;
	// li r4,208
	ctx.r4.s64 = 208;
	// addi r5,r11,-18320
	ctx.r5.s64 = ctx.r11.s64 + -18320;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x8809B890;
	sub_88094290(ctx, base);
	// li r5,208
	ctx.r5.s64 = 208;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,2304(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2304);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x8809B8A4;
	sub_88073BD0(ctx, base);
	// stw r30,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// li r4,21
	ctx.r4.s64 = 21;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x881556a0
	ctx.lr = 0x8809B8B4;
	sub_881556A0(ctx, base);
	// lis r9,-30710
	ctx.r9.s64 = -2012610560;
	// stw r3,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r3.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r8,r9,-20008
	ctx.r8.s64 = ctx.r9.s64 + -20008;
	// stw r31,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r31.u32);
	// li r29,0
	ctx.r29.s64 = 0;
	// stw r8,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r8.u32);
	// lwz r7,96(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// lwz r8,96(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// lwz r11,28(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809b904
	if (ctx.cr6.eq) goto loc_8809B904;
loc_8809B8EC:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8809ba90
	if (ctx.cr6.eq) goto loc_8809BA90;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8809b8ec
	if (!ctx.cr6.eq) goto loc_8809B8EC;
loc_8809B904:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_8809B908:
	// li r9,10
	ctx.r9.s64 = 10;
	// addi r8,r31,8
	ctx.r8.s64 = ctx.r31.s64 + 8;
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// li r7,63
	ctx.r7.s64 = 63;
	// lis r6,2
	ctx.r6.s64 = 131072;
	// stw r9,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r9.u32);
	// stw r9,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r9.u32);
	// stw r9,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r9.u32);
	// stw r8,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r8.u32);
	// stw r7,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// stw r6,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r6.u32);
	// lwz r5,32(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// stw r5,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r5.u32);
	// lwz r4,36(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// stw r4,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r4.u32);
	// lwz r11,100(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 100);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r3,r9,-1
	ctx.r3.s64 = ctx.r9.s64 + -1;
	// and r11,r3,r11
	ctx.r11.u64 = ctx.r3.u64 & ctx.r11.u64;
	// stw r11,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// lwz r9,132(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 132);
	// lwz r8,2304(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2304);
	// stw r8,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// lwz r7,136(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 136);
	// stw r7,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r7.u32);
	// lwz r6,140(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 140);
	// stw r6,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r6.u32);
	// stw r10,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r10.u32);
	// lwz r5,144(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 144);
	// clrlwi r4,r5,31
	ctx.r4.u64 = ctx.r5.u32 & 0x1;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x8809b994
	if (ctx.cr6.eq) goto loc_8809B994;
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r11.u32);
loc_8809B994:
	// lis r11,16838
	ctx.r11.s64 = 1103495168;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lis r5,-30671
	ctx.r5.s64 = -2010054656;
	// stw r10,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r10.u32);
	// ori r11,r11,20077
	ctx.r11.u64 = ctx.r11.u64 | 20077;
	// stw r10,172(r31)
	PPC_STORE_U32(ctx.r31.u32 + 172, ctx.r10.u32);
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// li r6,2
	ctx.r6.s64 = 2;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// stw r29,164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 164, ctx.r29.u32);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// stw r6,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r6.u32);
	// lwz r11,4200(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4200);
	// li r7,8
	ctx.r7.s64 = 8;
	// li r8,16
	ctx.r8.s64 = 16;
	// stw r29,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r29.u32);
	// mullw r11,r11,r10
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// stw r4,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r4.u32);
	// stw r7,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r7.u32);
	// stw r8,160(r31)
	PPC_STORE_U32(ctx.r31.u32 + 160, ctx.r8.u32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// li r4,32
	ctx.r4.s64 = 32;
	// stw r11,4200(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4200, ctx.r11.u32);
	// mullw r11,r11,r10
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// stw r4,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r4.u32);
	// addi r10,r11,12345
	ctx.r10.s64 = ctx.r11.s64 + 12345;
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// lwz r9,-11984(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + -11984);
	// lhz r11,4200(r5)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r5.u32 + 4200);
	// stw r10,4200(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4200, ctx.r10.u32);
	// clrlwi r3,r11,29
	ctx.r3.u64 = ctx.r11.u32 & 0x7;
	// lhz r11,4200(r5)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r5.u32 + 4200);
	// clrlwi r11,r11,29
	ctx.r11.u64 = ctx.r11.u32 & 0x7;
	// stw r3,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r3.u32);
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// lwz r11,84(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 84);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x8809baa8
	if (ctx.cr6.eq) goto loc_8809BAA8;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8809bae4
	if (!ctx.cr6.eq) goto loc_8809BAE4;
	// li r11,20
	ctx.r11.s64 = 20;
	// stw r8,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r8.u32);
	// li r10,6
	ctx.r10.s64 = 6;
	// stw r7,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r7.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r6,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r6.u32);
	// stw r11,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r11.u32);
	// stw r29,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r29.u32);
	// stw r10,144(r31)
	PPC_STORE_U32(ctx.r31.u32 + 144, ctx.r10.u32);
	// bl 0x881534c8
	ctx.lr = 0x8809BA5C;
	sub_881534C8(ctx, base);
	// lis r9,-30710
	ctx.r9.s64 = -2012610560;
	// stw r29,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r29.u32);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stw r29,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r29.u32);
	// extsh r8,r3
	ctx.r8.s64 = ctx.r3.s16;
	// li r7,5120
	ctx.r7.s64 = 5120;
	// stw r11,188(r31)
	PPC_STORE_U32(ctx.r31.u32 + 188, ctx.r11.u32);
	// addi r6,r9,-19936
	ctx.r6.s64 = ctx.r9.s64 + -19936;
	// stw r8,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r8.u32);
	// stw r11,184(r31)
	PPC_STORE_U32(ctx.r31.u32 + 184, ctx.r11.u32);
	// stw r7,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r7.u32);
	// stw r6,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r6.u32);
	// b 0x8809bae4
	goto loc_8809BAE4;
loc_8809BA90:
	// lwz r9,24(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8809baa0
	if (ctx.cr6.eq) goto loc_8809BAA0;
	// stw r9,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r9.u32);
loc_8809BAA0:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x8809b908
	goto loc_8809B908;
loc_8809BAA8:
	// lis r10,-30710
	ctx.r10.s64 = -2012610560;
	// stw r8,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r8.u32);
	// li r11,-18
	ctx.r11.s64 = -18;
	// stw r7,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r7.u32);
	// li r9,17
	ctx.r9.s64 = 17;
	// stw r6,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r6.u32);
	// li r8,5120
	ctx.r8.s64 = 5120;
	// stw r29,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r29.u32);
	// addi r7,r10,-19640
	ctx.r7.s64 = ctx.r10.s64 + -19640;
	// stw r9,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r9.u32);
	// stw r29,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r29.u32);
	// stw r11,188(r31)
	PPC_STORE_U32(ctx.r31.u32 + 188, ctx.r11.u32);
	// stw r11,184(r31)
	PPC_STORE_U32(ctx.r31.u32 + 184, ctx.r11.u32);
	// stw r8,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r8.u32);
	// stw r7,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r7.u32);
loc_8809BAE4:
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// lis r10,-30710
	ctx.r10.s64 = -2012610560;
	// lis r9,-30710
	ctx.r9.s64 = -2012610560;
	// lis r8,-30710
	ctx.r8.s64 = -2012610560;
	// addi r7,r10,-18832
	ctx.r7.s64 = ctx.r10.s64 + -18832;
	// addi r6,r9,-19336
	ctx.r6.s64 = ctx.r9.s64 + -19336;
	// addi r5,r8,-19400
	ctx.r5.s64 = ctx.r8.s64 + -19400;
	// stw r11,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// stw r7,64(r30)
	PPC_STORE_U32(ctx.r30.u32 + 64, ctx.r7.u32);
	// stw r6,68(r30)
	PPC_STORE_U32(ctx.r30.u32 + 68, ctx.r6.u32);
	// stw r5,84(r30)
	PPC_STORE_U32(ctx.r30.u32 + 84, ctx.r5.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809BB18"))) PPC_WEAK_FUNC(sub_8809BB18);
PPC_FUNC_IMPL(__imp__sub_8809BB18) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r11,r4,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// divwu r10,r3,r11
	ctx.r10.u32 = ppc_divwu(ctx.r3.u32, ctx.r11.u32);
	// mullw r9,r10,r11
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// subf r3,r9,r3
	ctx.r3.s64 = ctx.r3.s64 - ctx.r9.s64;
	// cmplw cr6,r3,r4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, ctx.xer);
	// bltlr cr6
	if (ctx.cr6.lt) return;
	// subf r3,r3,r11
	ctx.r3.s64 = ctx.r11.s64 - ctx.r3.s64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8809BB38"))) PPC_WEAK_FUNC(sub_8809BB38);
PPC_FUNC_IMPL(__imp__sub_8809BB38) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,2304(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r11,1180(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1180);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809bb4c
	if (ctx.cr6.eq) goto loc_8809BB4C;
	// stw r4,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r4.u32);
loc_8809BB4C:
	// lwz r11,1324(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1324);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r4,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8809BB60"))) PPC_WEAK_FUNC(sub_8809BB60);
PPC_FUNC_IMPL(__imp__sub_8809BB60) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r9,1324(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1324);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8809BB74"))) PPC_WEAK_FUNC(sub_8809BB74);
PPC_FUNC_IMPL(__imp__sub_8809BB74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8809BB78"))) PPC_WEAK_FUNC(sub_8809BB78);
PPC_FUNC_IMPL(__imp__sub_8809BB78) {
	PPC_FUNC_PROLOGUE();
	// lwz r7,2304(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r10,r11,576
	ctx.r10.s64 = ctx.r11.s64 + 576;
	// lwz r9,1180(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 1180);
	// lwz r11,-104(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -104);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8809bbb4
	if (ctx.cr6.eq) goto loc_8809BBB4;
	// cmpwi cr6,r11,3000
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3000, ctx.xer);
	// bge cr6,0x8809bbb4
	if (!ctx.cr6.lt) goto loc_8809BBB4;
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r8.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-104(r10)
	PPC_STORE_U32(ctx.r10.u32 + -104, ctx.r11.u32);
	// stwx r9,r6,r10
	PPC_STORE_U32(ctx.r6.u32 + ctx.r10.u32, ctx.r9.u32);
loc_8809BBB4:
	// lwz r9,1324(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 1324);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8809bbe8
	if (ctx.cr6.eq) goto loc_8809BBE8;
	// cmpwi cr6,r11,3000
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3000, ctx.xer);
	// bge cr6,0x8809bbe8
	if (!ctx.cr6.lt) goto loc_8809BBE8;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r8.u32);
	// lis r6,-30597
	ctx.r6.s64 = -2005204992;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-104(r10)
	PPC_STORE_U32(ctx.r10.u32 + -104, ctx.r11.u32);
	// stwx r9,r7,r10
	PPC_STORE_U32(ctx.r7.u32 + ctx.r10.u32, ctx.r9.u32);
	// stw r8,-11992(r6)
	PPC_STORE_U32(ctx.r6.u32 + -11992, ctx.r8.u32);
	// blr 
	return;
loc_8809BBE8:
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// stw r8,-11992(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11992, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8809BBF8"))) PPC_WEAK_FUNC(sub_8809BBF8);
PPC_FUNC_IMPL(__imp__sub_8809BBF8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,1476(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1476);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8809bc18
	if (!ctx.cr6.eq) goto loc_8809BC18;
	// lwz r11,1672(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1672);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
loc_8809BC18:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8809BC20"))) PPC_WEAK_FUNC(sub_8809BC20);
PPC_FUNC_IMPL(__imp__sub_8809BC20) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,1460(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1460);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8809bc50
	if (!ctx.cr6.eq) goto loc_8809BC50;
	// lwz r11,1656(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1656);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8809bc50
	if (!ctx.cr6.eq) goto loc_8809BC50;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,26276(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
loc_8809BC50:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8809BC58"))) PPC_WEAK_FUNC(sub_8809BC58);
PPC_FUNC_IMPL(__imp__sub_8809BC58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-30667
	ctx.r11.s64 = -2009792512;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r11,r11,9964
	ctx.r11.s64 = ctx.r11.s64 + 9964;
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
loc_8809BC68:
	// lwz r6,1172(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1172);
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// lwz r5,-4(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + -4);
	// lwz r4,0(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mullw r5,r5,r6
	ctx.r5.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r6.s32);
	// lwz r8,1324(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1324);
	// lwz r11,28(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// srawi r5,r5,4
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xF) != 0);
	ctx.r5.s64 = ctx.r5.s32 >> 4;
	// mullw r4,r4,r6
	ctx.r4.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r6.s32);
	// addze r6,r5
	temp.s64 = ctx.r5.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r6.s64 = temp.s64;
	// srawi r5,r4,4
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0xF) != 0);
	ctx.r5.s64 = ctx.r4.s32 >> 4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// addze r5,r5
	temp.s64 = ctx.r5.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r5.s64 = temp.s64;
	// beq cr6,0x8809bcb8
	if (ctx.cr6.eq) goto loc_8809BCB8;
loc_8809BCA0:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8809bce0
	if (ctx.cr6.eq) goto loc_8809BCE0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8809bca0
	if (!ctx.cr6.eq) goto loc_8809BCA0;
loc_8809BCB8:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8809BCBC:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// stw r6,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r6.u32);
	// stw r6,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r6.u32);
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// stw r5,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r5.u32);
	// cmplwi cr6,r7,3
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 3, ctx.xer);
	// stw r5,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r5.u32);
	// blt cr6,0x8809bc68
	if (ctx.cr6.lt) goto loc_8809BC68;
	// blr 
	return;
loc_8809BCE0:
	// lwz r10,24(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8809bcf0
	if (ctx.cr6.eq) goto loc_8809BCF0;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_8809BCF0:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x8809bcbc
	goto loc_8809BCBC;
}

__attribute__((alias("__imp__sub_8809BCF8"))) PPC_WEAK_FUNC(sub_8809BCF8);
PPC_FUNC_IMPL(__imp__sub_8809BCF8) {
	PPC_FUNC_PROLOGUE();
	// li r10,128
	ctx.r10.s64 = 128;
	// lwz r9,2304(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r11,r9,1884
	ctx.r11.s64 = ctx.r9.s64 + 1884;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8809BD0C:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x8809bd1c
	if (!ctx.cr6.eq) goto loc_8809BD1C;
	// stw r8,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
loc_8809BD1C:
	// addi r11,r11,96
	ctx.r11.s64 = ctx.r11.s64 + 96;
	// bdnz 0x8809bd0c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8809BD0C;
	// stw r8,14176(r9)
	PPC_STORE_U32(ctx.r9.u32 + 14176, ctx.r8.u32);
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// bne cr6,0x8809bd74
	if (!ctx.cr6.eq) goto loc_8809BD74;
	// addi r10,r11,-11984
	ctx.r10.s64 = ctx.r11.s64 + -11984;
	// lwz r11,-1972(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -1972);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r10,4
	ctx.r10.s64 = 262144;
	// lis r9,4
	ctx.r9.s64 = 262144;
	// ori r8,r10,33876
	ctx.r8.u64 = ctx.r10.u64 | 33876;
	// ori r7,r9,33872
	ctx.r7.u64 = ctx.r9.u64 | 33872;
	// li r6,176
	ctx.r6.s64 = 176;
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,0
	ctx.r4.s64 = 0;
	// stwx r6,r11,r8
	PPC_STORE_U32(ctx.r11.u32 + ctx.r8.u32, ctx.r6.u32);
	// li r3,-1
	ctx.r3.s64 = -1;
	// stwx r5,r11,r7
	PPC_STORE_U32(ctx.r11.u32 + ctx.r7.u32, ctx.r5.u32);
	// b 0x8815d040
	sub_8815D040(ctx, base);
	return;
loc_8809BD74:
	// lwz r5,12(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne cr6,0x8809bdb8
	if (!ctx.cr6.eq) goto loc_8809BDB8;
	// addi r10,r11,-11984
	ctx.r10.s64 = ctx.r11.s64 + -11984;
	// lwz r11,-1972(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -1972);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r10,4
	ctx.r10.s64 = 262144;
	// lis r9,4
	ctx.r9.s64 = 262144;
	// ori r7,r10,33876
	ctx.r7.u64 = ctx.r10.u64 | 33876;
	// ori r6,r9,33872
	ctx.r6.u64 = ctx.r9.u64 | 33872;
	// li r5,176
	ctx.r5.s64 = 176;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stwx r5,r11,r7
	PPC_STORE_U32(ctx.r11.u32 + ctx.r7.u32, ctx.r5.u32);
	// stwx r8,r11,r6
	PPC_STORE_U32(ctx.r11.u32 + ctx.r6.u32, ctx.r8.u32);
	// b 0x8815d040
	sub_8815D040(ctx, base);
	return;
loc_8809BDB8:
	// addi r11,r11,-11984
	ctx.r11.s64 = ctx.r11.s64 + -11984;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r10,84(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x8809bddc
	if (!ctx.cr6.eq) goto loc_8809BDDC;
	// lwz r6,24(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// li r3,176
	ctx.r3.s64 = 176;
	// lwz r4,16(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// b 0x8815d688
	sub_8815D688(ctx, base);
	return;
loc_8809BDDC:
	// lwz r11,-1972(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -1972);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r10,4
	ctx.r10.s64 = 262144;
	// lis r9,4
	ctx.r9.s64 = 262144;
	// ori r7,r10,33876
	ctx.r7.u64 = ctx.r10.u64 | 33876;
	// ori r6,r9,33872
	ctx.r6.u64 = ctx.r9.u64 | 33872;
	// li r5,176
	ctx.r5.s64 = 176;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stwx r5,r11,r7
	PPC_STORE_U32(ctx.r11.u32 + ctx.r7.u32, ctx.r5.u32);
	// stwx r8,r11,r6
	PPC_STORE_U32(ctx.r11.u32 + ctx.r6.u32, ctx.r8.u32);
	// b 0x8815d040
	sub_8815D040(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809BE10"))) PPC_WEAK_FUNC(sub_8809BE10);
PPC_FUNC_IMPL(__imp__sub_8809BE10) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8809BE14"))) PPC_WEAK_FUNC(sub_8809BE14);
PPC_FUNC_IMPL(__imp__sub_8809BE14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8809BE18"))) PPC_WEAK_FUNC(sub_8809BE18);
PPC_FUNC_IMPL(__imp__sub_8809BE18) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x8809BE20;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// li r28,1
	ctx.r28.s64 = 1;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// stw r28,1488(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1488, ctx.r28.u32);
	// beq cr6,0x8809c15c
	if (ctx.cr6.eq) goto loc_8809C15C;
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x8809c05c
	if (ctx.cr6.eq) goto loc_8809C05C;
	// cmpwi cr6,r3,3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 3, ctx.xer);
	// bne cr6,0x8809c214
	if (!ctx.cr6.eq) goto loc_8809C214;
	// lwz r11,1484(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1484);
	// li r27,0
	ctx.r27.s64 = 0;
	// stw r28,1480(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1480, ctx.r28.u32);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// stw r28,1580(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1580, ctx.r28.u32);
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r29,r11,-16616
	ctx.r29.s64 = ctx.r11.s64 + -16616;
	// lwz r11,4632(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4632);
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// bne cr6,0x8809becc
	if (!ctx.cr6.eq) goto loc_8809BECC;
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x8809be90
	if (!ctx.cr6.eq) goto loc_8809BE90;
	// lis r11,-30683
	ctx.r11.s64 = -2010841088;
	// addi r10,r11,14972
	ctx.r10.s64 = ctx.r11.s64 + 14972;
	// lwz r5,-104(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + -104);
	// b 0x8809bf18
	goto loc_8809BF18;
loc_8809BE90:
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r11,88(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// lwz r9,160(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 160);
	// mulli r11,r9,100
	ctx.r11.s64 = ctx.r9.s64 * 100;
	// blt cr6,0x8809bebc
	if (ctx.cr6.lt) goto loc_8809BEBC;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// beq cr6,0x8809beb8
	if (ctx.cr6.eq) goto loc_8809BEB8;
	// lwz r11,164(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 164);
loc_8809BEB8:
	// mulli r11,r11,100
	ctx.r11.s64 = ctx.r11.s64 * 100;
loc_8809BEBC:
	// lis r10,-30683
	ctx.r10.s64 = -2010841088;
	// addi r9,r10,14972
	ctx.r9.s64 = ctx.r10.s64 + 14972;
	// lwz r10,-104(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -104);
	// b 0x8809bf14
	goto loc_8809BF14;
loc_8809BECC:
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x8809bee0
	if (!ctx.cr6.eq) goto loc_8809BEE0;
	// lis r11,-30683
	ctx.r11.s64 = -2010841088;
	// lwz r5,14972(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 14972);
	// b 0x8809bf18
	goto loc_8809BF18;
loc_8809BEE0:
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r11,88(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// lwz r9,160(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 160);
	// mulli r11,r9,100
	ctx.r11.s64 = ctx.r9.s64 * 100;
	// blt cr6,0x8809bf0c
	if (ctx.cr6.lt) goto loc_8809BF0C;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// beq cr6,0x8809bf08
	if (ctx.cr6.eq) goto loc_8809BF08;
	// lwz r11,164(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 164);
loc_8809BF08:
	// mulli r11,r11,100
	ctx.r11.s64 = ctx.r11.s64 * 100;
loc_8809BF0C:
	// lis r10,-30683
	ctx.r10.s64 = -2010841088;
	// lwz r10,14972(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 14972);
loc_8809BF14:
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
loc_8809BF18:
	// bl 0x88095178
	ctx.lr = 0x8809BF1C;
	sub_88095178(ctx, base);
	// stw r28,1476(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1476, ctx.r28.u32);
	// stw r27,1280(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1280, ctx.r27.u32);
	// stw r28,1296(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1296, ctx.r28.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,2304(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2304);
	// lwz r11,1180(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1180);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809bf40
	if (ctx.cr6.eq) goto loc_8809BF40;
	// stw r27,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r27.u32);
loc_8809BF40:
	// lwz r11,1324(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1324);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809bf50
	if (ctx.cr6.eq) goto loc_8809BF50;
	// stw r27,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r27.u32);
loc_8809BF50:
	// addi r4,r31,1640
	ctx.r4.s64 = ctx.r31.s64 + 1640;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8809bcf8
	ctx.lr = 0x8809BF5C;
	sub_8809BCF8(ctx, base);
	// bl 0x880971a8
	ctx.lr = 0x8809BF60;
	sub_880971A8(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096e80
	ctx.lr = 0x8809BF68;
	sub_88096E80(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x880967b8
	ctx.lr = 0x8809BF70;
	sub_880967B8(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096ac0
	ctx.lr = 0x8809BF78;
	sub_88096AC0(ctx, base);
	// lis r11,-30689
	ctx.r11.s64 = -2011234304;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r4,r11,-15608
	ctx.r4.s64 = ctx.r11.s64 + -15608;
	// bl 0x880969a8
	ctx.lr = 0x8809BF8C;
	sub_880969A8(ctx, base);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r9,1860(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1860);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x8809c214
	if (!ctx.cr6.eq) goto loc_8809C214;
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// lis r9,-30651
	ctx.r9.s64 = -2008743936;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// addi r31,r10,11616
	ctx.r31.s64 = ctx.r10.s64 + 11616;
	// addi r30,r9,-26112
	ctx.r30.s64 = ctx.r9.s64 + -26112;
loc_8809BFB0:
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x8809bfcc
	if (ctx.cr6.eq) goto loc_8809BFCC;
	// addi r10,r30,20
	ctx.r10.s64 = ctx.r30.s64 + 20;
	// lbzx r9,r11,r31
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r31.u32);
	// lbzx r8,r11,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r10.u32);
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x8809c214
	if (!ctx.cr6.eq) goto loc_8809C214;
loc_8809BFCC:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// blt cr6,0x8809bfb0
	if (ctx.cr6.lt) goto loc_8809BFB0;
	// lwz r10,5868(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 5868);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8809c00c
	if (ctx.cr6.eq) goto loc_8809C00C;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stw r28,5876(r29)
	PPC_STORE_U32(ctx.r29.u32 + 5876, ctx.r28.u32);
	// cmplwi cr6,r10,44
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 44, ctx.xer);
	// ble cr6,0x8809c020
	if (!ctx.cr6.gt) goto loc_8809C020;
	// lwz r11,352(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 352);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8809c018
	if (!ctx.cr6.eq) goto loc_8809C018;
	// li r3,44
	ctx.r3.s64 = 44;
	// bl 0x8808d1b8
	ctx.lr = 0x8809C008;
	sub_8808D1B8(ctx, base);
	// b 0x8809c020
	goto loc_8809C020;
loc_8809C00C:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// stw r27,5876(r29)
	PPC_STORE_U32(ctx.r29.u32 + 5876, ctx.r27.u32);
	// b 0x8809c020
	goto loc_8809C020;
loc_8809C018:
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stw r28,356(r29)
	PPC_STORE_U32(ctx.r29.u32 + 356, ctx.r28.u32);
loc_8809C020:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_8809C024:
	// addi r10,r30,20
	ctx.r10.s64 = ctx.r30.s64 + 20;
	// lbzx r9,r11,r31
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r31.u32);
	// lbzx r8,r11,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r10.u32);
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x8809c04c
	if (!ctx.cr6.eq) goto loc_8809C04C;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// blt cr6,0x8809c024
	if (ctx.cr6.lt) goto loc_8809C024;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_8809C04C:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// stw r27,5876(r29)
	PPC_STORE_U32(ctx.r29.u32 + 5876, ctx.r27.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_8809C05C:
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r28,1480(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1480, ctx.r28.u32);
	// stw r28,1576(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1576, ctx.r28.u32);
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// stw r11,1484(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1484, ctx.r11.u32);
	// li r27,0
	ctx.r27.s64 = 0;
	// addi r9,r10,-16616
	ctx.r9.s64 = ctx.r10.s64 + -16616;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,4632(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4632);
	// lwz r8,84(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// cmpwi cr6,r8,1
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 1, ctx.xer);
	// bne cr6,0x8809c09c
	if (!ctx.cr6.eq) goto loc_8809C09C;
	// lis r11,-30683
	ctx.r11.s64 = -2010841088;
	// addi r10,r11,14972
	ctx.r10.s64 = ctx.r11.s64 + 14972;
	// lwz r5,-104(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + -104);
	// b 0x8809c0d8
	goto loc_8809C0D8;
loc_8809C09C:
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r11,88(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// lwz r9,160(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 160);
	// mulli r11,r9,100
	ctx.r11.s64 = ctx.r9.s64 * 100;
	// blt cr6,0x8809c0c8
	if (ctx.cr6.lt) goto loc_8809C0C8;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// beq cr6,0x8809c0c4
	if (ctx.cr6.eq) goto loc_8809C0C4;
	// lwz r11,164(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 164);
loc_8809C0C4:
	// mulli r11,r11,100
	ctx.r11.s64 = ctx.r11.s64 * 100;
loc_8809C0C8:
	// lis r10,-30683
	ctx.r10.s64 = -2010841088;
	// addi r9,r10,14972
	ctx.r9.s64 = ctx.r10.s64 + 14972;
	// lwz r10,-104(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -104);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_8809C0D8:
	// bl 0x88095178
	ctx.lr = 0x8809C0DC;
	sub_88095178(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r8,-30642
	ctx.r8.s64 = -2008154112;
	// lis r10,2
	ctx.r10.s64 = 131072;
	// ori r9,r11,45472
	ctx.r9.u64 = ctx.r11.u64 | 45472;
	// addi r7,r8,-32760
	ctx.r7.s64 = ctx.r8.s64 + -32760;
	// ori r11,r10,50816
	ctx.r11.u64 = ctx.r10.u64 | 50816;
	// stw r9,1288(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1288, ctx.r9.u32);
	// stw r27,1528(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1528, ctx.r27.u32);
	// addi r4,r31,1612
	ctx.r4.s64 = ctx.r31.s64 + 1612;
	// stw r27,1532(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1532, ctx.r27.u32);
	// stw r11,1280(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1280, ctx.r11.u32);
	// stw r11,1536(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1536, ctx.r11.u32);
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// stw r27,1540(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1540, ctx.r27.u32);
	// stw r27,1544(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1544, ctx.r27.u32);
	// stw r28,1548(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1548, ctx.r28.u32);
	// stw r27,136(r7)
	PPC_STORE_U32(ctx.r7.u32 + 136, ctx.r27.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8809bcf8
	ctx.lr = 0x8809C128;
	sub_8809BCF8(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096e80
	ctx.lr = 0x8809C130;
	sub_88096E80(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x880967b8
	ctx.lr = 0x8809C138;
	sub_880967B8(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096ac0
	ctx.lr = 0x8809C140;
	sub_88096AC0(ctx, base);
	// lis r6,-30689
	ctx.r6.s64 = -2011234304;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r4,r6,-14176
	ctx.r4.s64 = ctx.r6.s64 + -14176;
	// bl 0x880969a8
	ctx.lr = 0x8809C154;
	sub_880969A8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_8809C15C:
	// stw r28,1480(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1480, ctx.r28.u32);
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// stw r28,1484(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1484, ctx.r28.u32);
	// addi r10,r11,-16616
	ctx.r10.s64 = ctx.r11.s64 + -16616;
	// stw r28,1572(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1572, ctx.r28.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,4632(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4632);
	// lwz r9,84(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x8809c194
	if (!ctx.cr6.eq) goto loc_8809C194;
	// lis r11,-30683
	ctx.r11.s64 = -2010841088;
	// addi r10,r11,14972
	ctx.r10.s64 = ctx.r11.s64 + 14972;
	// lwz r5,-208(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + -208);
	// b 0x8809c1d0
	goto loc_8809C1D0;
loc_8809C194:
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r11,88(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// lwz r9,160(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 160);
	// mulli r11,r9,100
	ctx.r11.s64 = ctx.r9.s64 * 100;
	// blt cr6,0x8809c1c0
	if (ctx.cr6.lt) goto loc_8809C1C0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// li r11,0
	ctx.r11.s64 = 0;
	// beq cr6,0x8809c1bc
	if (ctx.cr6.eq) goto loc_8809C1BC;
	// lwz r11,164(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 164);
loc_8809C1BC:
	// mulli r11,r11,100
	ctx.r11.s64 = ctx.r11.s64 * 100;
loc_8809C1C0:
	// lis r10,-30683
	ctx.r10.s64 = -2010841088;
	// addi r9,r10,14972
	ctx.r9.s64 = ctx.r10.s64 + 14972;
	// lwz r10,-208(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -208);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_8809C1D0:
	// bl 0x88095178
	ctx.lr = 0x8809C1D4;
	sub_88095178(ctx, base);
	// lwz r11,1528(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1528);
	// addi r4,r31,1584
	ctx.r4.s64 = ctx.r31.s64 + 1584;
	// stw r11,1280(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1280, ctx.r11.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8809bcf8
	ctx.lr = 0x8809C1E8;
	sub_8809BCF8(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096e80
	ctx.lr = 0x8809C1F0;
	sub_88096E80(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x880967b8
	ctx.lr = 0x8809C1F8;
	sub_880967B8(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096ac0
	ctx.lr = 0x8809C200;
	sub_88096AC0(ctx, base);
	// lis r10,-30689
	ctx.r10.s64 = -2011234304;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r4,r10,-12960
	ctx.r4.s64 = ctx.r10.s64 + -12960;
	// bl 0x880969a8
	ctx.lr = 0x8809C214;
	sub_880969A8(ctx, base);
loc_8809C214:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809C21C"))) PPC_WEAK_FUNC(sub_8809C21C);
PPC_FUNC_IMPL(__imp__sub_8809C21C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8809C220"))) PPC_WEAK_FUNC(sub_8809C220);
PPC_FUNC_IMPL(__imp__sub_8809C220) {
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
	// lwz r11,26272(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26272);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8809c3e4
	if (!ctx.cr6.eq) goto loc_8809C3E4;
	// lwz r10,1484(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1484);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8809c2c4
	if (!ctx.cr6.eq) goto loc_8809C2C4;
	// lwz r11,1572(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1572);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8809c2c4
	if (!ctx.cr6.eq) goto loc_8809C2C4;
	// lwz r11,1560(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1560);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,1560(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1560, ctx.r11.u32);
	// bge 0x8809c2c4
	if (!ctx.cr0.lt) goto loc_8809C2C4;
	// lwz r11,1528(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1528);
	// li r30,1
	ctx.r30.s64 = 1;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r30,1488(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1488, ctx.r30.u32);
	// addi r4,r3,1584
	ctx.r4.s64 = ctx.r3.s64 + 1584;
	// stw r30,1484(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1484, ctx.r30.u32);
	// stw r30,1480(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1480, ctx.r30.u32);
	// stw r30,1572(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1572, ctx.r30.u32);
	// stw r10,1592(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1592, ctx.r10.u32);
	// stw r11,1280(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1280, ctx.r11.u32);
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x8809bcf8
	ctx.lr = 0x8809C2A0;
	sub_8809BCF8(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096e80
	ctx.lr = 0x8809C2A8;
	sub_88096E80(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x880967b8
	ctx.lr = 0x8809C2B0;
	sub_880967B8(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096ac0
	ctx.lr = 0x8809C2B8;
	sub_88096AC0(ctx, base);
	// lis r9,-30689
	ctx.r9.s64 = -2011234304;
	// addi r4,r9,-12960
	ctx.r4.s64 = ctx.r9.s64 + -12960;
	// b 0x8809c3d8
	goto loc_8809C3D8;
loc_8809C2C4:
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x8809c314
	if (!ctx.cr6.eq) goto loc_8809C314;
	// lwz r11,1576(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1576);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8809c314
	if (!ctx.cr6.eq) goto loc_8809C314;
	// lwz r11,1564(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1564);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,1564(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1564, ctx.r11.u32);
	// bge 0x8809c314
	if (!ctx.cr0.lt) goto loc_8809C314;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r10,r11,26432
	ctx.r10.s64 = ctx.r11.s64 + 26432;
	// lwz r11,324(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 324);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8809c308
	if (!ctx.cr6.eq) goto loc_8809C308;
	// li r11,300
	ctx.r11.s64 = 300;
	// stw r11,1564(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1564, ctx.r11.u32);
	// b 0x8809c3e4
	goto loc_8809C3E4;
loc_8809C308:
	// li r30,1
	ctx.r30.s64 = 1;
	// stw r30,1576(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1576, ctx.r30.u32);
	// b 0x8809c35c
	goto loc_8809C35C;
loc_8809C314:
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// bne cr6,0x8809c3e4
	if (!ctx.cr6.eq) goto loc_8809C3E4;
	// lwz r11,1580(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1580);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8809c3e4
	if (!ctx.cr6.eq) goto loc_8809C3E4;
	// lwz r11,1568(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1568);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,1568(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1568, ctx.r11.u32);
	// bge 0x8809c3e4
	if (!ctx.cr0.lt) goto loc_8809C3E4;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r10,r11,26432
	ctx.r10.s64 = ctx.r11.s64 + 26432;
	// lwz r11,324(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 324);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8809c358
	if (!ctx.cr6.eq) goto loc_8809C358;
	// li r11,300
	ctx.r11.s64 = 300;
	// stw r11,1568(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1568, ctx.r11.u32);
	// b 0x8809c3e4
	goto loc_8809C3E4;
loc_8809C358:
	// li r30,1
	ctx.r30.s64 = 1;
loc_8809C35C:
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r30,1488(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1488, ctx.r30.u32);
	// stw r30,1480(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1480, ctx.r30.u32);
	// stw r30,1580(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1580, ctx.r30.u32);
	// stw r11,1648(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1648, ctx.r11.u32);
	// bl 0x880971a8
	ctx.lr = 0x8809C374;
	sub_880971A8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r30,1476(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1476, ctx.r30.u32);
	// stw r30,1296(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1296, ctx.r30.u32);
	// stw r11,1280(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1280, ctx.r11.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,2304(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2304);
	// lwz r10,1180(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 1180);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8809c39c
	if (ctx.cr6.eq) goto loc_8809C39C;
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r11.u32);
loc_8809C39C:
	// lwz r10,1324(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 1324);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8809c3ac
	if (ctx.cr6.eq) goto loc_8809C3AC;
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r11.u32);
loc_8809C3AC:
	// addi r4,r31,1640
	ctx.r4.s64 = ctx.r31.s64 + 1640;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8809bcf8
	ctx.lr = 0x8809C3B8;
	sub_8809BCF8(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096e80
	ctx.lr = 0x8809C3C0;
	sub_88096E80(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x880967b8
	ctx.lr = 0x8809C3C8;
	sub_880967B8(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096ac0
	ctx.lr = 0x8809C3D0;
	sub_88096AC0(ctx, base);
	// lis r11,-30689
	ctx.r11.s64 = -2011234304;
	// addi r4,r11,-15608
	ctx.r4.s64 = ctx.r11.s64 + -15608;
loc_8809C3D8:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x880969a8
	ctx.lr = 0x8809C3E4;
	sub_880969A8(ctx, base);
loc_8809C3E4:
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

__attribute__((alias("__imp__sub_8809C3FC"))) PPC_WEAK_FUNC(sub_8809C3FC);
PPC_FUNC_IMPL(__imp__sub_8809C3FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8809C400"))) PPC_WEAK_FUNC(sub_8809C400);
PPC_FUNC_IMPL(__imp__sub_8809C400) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x8809C408;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x880a05a0
	ctx.lr = 0x8809C418;
	sub_880A05A0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a0478
	ctx.lr = 0x8809C420;
	sub_880A0478(ctx, base);
	// lwz r11,1476(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1476);
	// li r29,0
	ctx.r29.s64 = 0;
	// li r28,1
	ctx.r28.s64 = 1;
	// li r30,48
	ctx.r30.s64 = 48;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8809c494
	if (!ctx.cr6.eq) goto loc_8809C494;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r10,1460(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1460);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8809c464
	if (!ctx.cr6.eq) goto loc_8809C464;
	// lwz r11,1656(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1656);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8809c464
	if (!ctx.cr6.eq) goto loc_8809C464;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26276(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809c494
	if (ctx.cr6.eq) goto loc_8809C494;
loc_8809C464:
	// lwz r11,1164(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1164);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8809c490
	if (!ctx.cr6.eq) goto loc_8809C490;
	// lwz r11,1324(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1324);
	// li r10,64
	ctx.r10.s64 = 64;
	// stw r29,1168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1168, ctx.r29.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,1172(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1172, ctx.r10.u32);
	// stw r29,1176(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1176, ctx.r29.u32);
	// stw r28,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r28.u32);
	// bl 0x8809bc58
	ctx.lr = 0x8809C490;
	sub_8809BC58(ctx, base);
loc_8809C490:
	// stw r30,1164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1164, ctx.r30.u32);
loc_8809C494:
	// lwz r11,1164(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1164);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8809c4fc
	if (ctx.cr6.eq) goto loc_8809C4FC;
	// lwz r11,1324(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1324);
	// stw r28,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r28.u32);
	// lwz r11,1164(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1164);
	// cmpwi cr6,r11,48
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 48, ctx.xer);
	// blt cr6,0x8809c4d4
	if (ctx.cr6.lt) goto loc_8809C4D4;
	// lwz r10,1168(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1168);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// stw r10,1168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1168, ctx.r10.u32);
	// cmpwi cr6,r10,255
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 255, ctx.xer);
	// ble cr6,0x8809c4e4
	if (!ctx.cr6.gt) goto loc_8809C4E4;
	// li r10,255
	ctx.r10.s64 = 255;
	// stw r10,1168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1168, ctx.r10.u32);
	// b 0x8809c4e4
	goto loc_8809C4E4;
loc_8809C4D4:
	// rlwinm r10,r11,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw r8,r9,r30
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r30.s32);
	// stw r8,1168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1168, ctx.r8.u32);
loc_8809C4E4:
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,1164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1164, ctx.r11.u32);
	// bgt 0x8809c500
	if (ctx.cr0.gt) goto loc_8809C500;
	// lwz r11,1324(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1324);
	// stw r29,1164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1164, ctx.r29.u32);
	// stw r29,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r29.u32);
loc_8809C4FC:
	// stw r29,1168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1168, ctx.r29.u32);
loc_8809C500:
	// lwz r10,1476(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1476);
	// lis r11,-30642
	ctx.r11.s64 = -2008154112;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r30,r11,-32760
	ctx.r30.s64 = ctx.r11.s64 + -32760;
	// bne cr6,0x8809c8e8
	if (!ctx.cr6.eq) goto loc_8809C8E8;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r3,r31,1180
	ctx.r3.s64 = ctx.r31.s64 + 1180;
	// lis r10,128
	ctx.r10.s64 = 8388608;
	// lis r8,255
	ctx.r8.s64 = 16711680;
	// lis r5,192
	ctx.r5.s64 = 12582912;
	// lwz r4,26428(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26428);
	// li r6,2
	ctx.r6.s64 = 2;
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// ori r7,r10,32896
	ctx.r7.u64 = ctx.r10.u64 | 32896;
	// ori r8,r8,4112
	ctx.r8.u64 = ctx.r8.u64 | 4112;
	// ori r5,r5,49152
	ctx.r5.u64 = ctx.r5.u64 | 49152;
loc_8809C540:
	// lwz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// stw r7,120(r9)
	PPC_STORE_U32(ctx.r9.u32 + 120, ctx.r7.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809c578
	if (ctx.cr6.eq) goto loc_8809C578;
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809c578
	if (ctx.cr6.eq) goto loc_8809C578;
loc_8809C560:
	// lwz r27,20(r11)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// stw r29,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r29.u32);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// or r10,r10,r27
	ctx.r10.u64 = ctx.r10.u64 | ctx.r27.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8809c560
	if (!ctx.cr6.eq) goto loc_8809C560;
loc_8809C578:
	// clrlwi r11,r10,20
	ctx.r11.u64 = ctx.r10.u32 & 0xFFF;
	// rlwinm r11,r11,0,26,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFC3F;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8809c5e8
	if (!ctx.cr6.eq) goto loc_8809C5E8;
	// lwz r11,1492(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1492);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8809c5e8
	if (!ctx.cr6.eq) goto loc_8809C5E8;
	// lwz r11,100(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 100);
	// lwz r10,108(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 108);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x8809c608
	if (!ctx.cr6.lt) goto loc_8809C608;
	// rlwinm r11,r4,0,28,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xE;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8809c608
	if (!ctx.cr6.eq) goto loc_8809C608;
	// lwz r11,136(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 136);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8809c5d4
	if (ctx.cr6.eq) goto loc_8809C5D4;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r11,r31,1156
	ctx.r11.s64 = ctx.r31.s64 + 1156;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8809C5C8:
	// stwu r8,144(r11)
	ea = 144 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8809c5c8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8809C5C8;
	// b 0x8809c608
	goto loc_8809C608;
loc_8809C5D4:
	// lwz r11,116(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 116);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8809c608
	if (!ctx.cr6.eq) goto loc_8809C608;
	// stw r8,120(r9)
	PPC_STORE_U32(ctx.r9.u32 + 120, ctx.r8.u32);
	// b 0x8809c608
	goto loc_8809C608;
loc_8809C5E8:
	// lwz r11,124(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 124);
	// stw r29,112(r9)
	PPC_STORE_U32(ctx.r9.u32 + 112, ctx.r29.u32);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,124(r9)
	PPC_STORE_U32(ctx.r9.u32 + 124, ctx.r11.u32);
	// beq cr6,0x8809c608
	if (ctx.cr6.eq) goto loc_8809C608;
	// stw r5,120(r9)
	PPC_STORE_U32(ctx.r9.u32 + 120, ctx.r5.u32);
loc_8809C608:
	// addic. r6,r6,-1
	ctx.xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// addi r9,r9,144
	ctx.r9.s64 = ctx.r9.s64 + 144;
	// bne 0x8809c540
	if (!ctx.cr0.eq) goto loc_8809C540;
	// lwz r10,1492(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1492);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8809c8e8
	if (ctx.cr6.eq) goto loc_8809C8E8;
	// lwz r11,1480(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1480);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8809c8e4
	if (!ctx.cr6.eq) goto loc_8809C8E4;
	// lwz r11,100(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8809c8e4
	if (!ctx.cr6.gt) goto loc_8809C8E4;
	// lwz r9,1164(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1164);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x8809c8e4
	if (!ctx.cr6.eq) goto loc_8809C8E4;
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// stw r11,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r11.u32);
	// lwz r10,1484(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1484);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8809c6f0
	if (!ctx.cr6.eq) goto loc_8809C6F0;
	// lwz r10,1528(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1528);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bgt cr6,0x8809c8e4
	if (ctx.cr6.gt) goto loc_8809C8E4;
	// lwz r11,1504(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1504);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// stw r28,1592(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1592, ctx.r28.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809c67c
	if (ctx.cr6.eq) goto loc_8809C67C;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
loc_8809C67C:
	// stw r10,1596(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1596, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r11,1600(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1600, ctx.r11.u32);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// beq cr6,0x8809c694
	if (ctx.cr6.eq) goto loc_8809C694;
	// lwz r10,164(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_8809C694:
	// stw r10,1584(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1584, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// beq cr6,0x8809c6a8
	if (ctx.cr6.eq) goto loc_8809C6A8;
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
loc_8809C6A8:
	// stw r10,1588(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1588, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// beq cr6,0x8809c6c0
	if (ctx.cr6.eq) goto loc_8809C6C0;
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// bne cr6,0x8809c6d8
	if (!ctx.cr6.eq) goto loc_8809C6D8;
loc_8809C6C0:
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r29,2328(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2328, ctx.r29.u32);
	// stw r10,2332(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2332, ctx.r10.u32);
	// b 0x8809c8d8
	goto loc_8809C8D8;
loc_8809C6D8:
	// lwz r11,164(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r11,2328(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2328, ctx.r11.u32);
	// stw r10,2332(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2332, ctx.r10.u32);
	// b 0x8809c8d8
	goto loc_8809C8D8;
loc_8809C6F0:
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x8809c828
	if (!ctx.cr6.eq) goto loc_8809C828;
	// lwz r10,1532(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1532);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bgt cr6,0x8809c8e4
	if (ctx.cr6.gt) goto loc_8809C8E4;
	// lwz r11,-6020(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -6020);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8809c71c
	if (!ctx.cr6.eq) goto loc_8809C71C;
	// li r11,512
	ctx.r11.s64 = 512;
	// stw r11,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r11.u32);
	// b 0x8809c8e4
	goto loc_8809C8E4;
loc_8809C71C:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r10,1476(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1476);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8809c7c4
	if (!ctx.cr6.eq) goto loc_8809C7C4;
	// lwz r11,1672(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1672);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8809c7c4
	if (!ctx.cr6.eq) goto loc_8809C7C4;
	// lwz r11,1504(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1504);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// stw r28,1620(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1620, ctx.r28.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809c750
	if (ctx.cr6.eq) goto loc_8809C750;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
loc_8809C750:
	// stw r10,1624(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1624, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r11,1628(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1628, ctx.r11.u32);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// beq cr6,0x8809c768
	if (ctx.cr6.eq) goto loc_8809C768;
	// lwz r10,164(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_8809C768:
	// stw r10,1612(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1612, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// beq cr6,0x8809c77c
	if (ctx.cr6.eq) goto loc_8809C77C;
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
loc_8809C77C:
	// stw r10,1616(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1616, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// beq cr6,0x8809c794
	if (ctx.cr6.eq) goto loc_8809C794;
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// bne cr6,0x8809c7ac
	if (!ctx.cr6.eq) goto loc_8809C7AC;
loc_8809C794:
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// li r3,2
	ctx.r3.s64 = 2;
	// stw r29,2328(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2328, ctx.r29.u32);
	// stw r10,2332(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2332, ctx.r10.u32);
	// b 0x8809c8d8
	goto loc_8809C8D8;
loc_8809C7AC:
	// lwz r11,164(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
	// li r3,2
	ctx.r3.s64 = 2;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r11,2328(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2328, ctx.r11.u32);
	// stw r10,2332(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2332, ctx.r10.u32);
	// b 0x8809c8d8
	goto loc_8809C8D8;
loc_8809C7C4:
	// lwz r11,1504(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1504);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// stw r28,1648(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1648, ctx.r28.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809c7dc
	if (ctx.cr6.eq) goto loc_8809C7DC;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
loc_8809C7DC:
	// stw r10,1652(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1652, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r11,1656(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1656, ctx.r11.u32);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// beq cr6,0x8809c7f4
	if (ctx.cr6.eq) goto loc_8809C7F4;
	// lwz r10,164(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_8809C7F4:
	// stw r10,1640(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1640, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// beq cr6,0x8809c808
	if (ctx.cr6.eq) goto loc_8809C808;
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
loc_8809C808:
	// stw r10,1644(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1644, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
	// beq cr6,0x8809c8ac
	if (ctx.cr6.eq) goto loc_8809C8AC;
	// lwz r9,176(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// bne cr6,0x8809c8b4
	if (!ctx.cr6.eq) goto loc_8809C8B4;
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// b 0x8809c8b8
	goto loc_8809C8B8;
loc_8809C828:
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// bne cr6,0x8809c8e4
	if (!ctx.cr6.eq) goto loc_8809C8E4;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt cr6,0x8809c8e4
	if (ctx.cr6.gt) goto loc_8809C8E4;
	// lwz r11,-6020(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -6020);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8809c850
	if (!ctx.cr6.eq) goto loc_8809C850;
	// li r11,512
	ctx.r11.s64 = 512;
	// stw r11,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r11.u32);
	// b 0x8809c8e4
	goto loc_8809C8E4;
loc_8809C850:
	// lwz r11,1504(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1504);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// stw r28,1648(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1648, ctx.r28.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809c868
	if (ctx.cr6.eq) goto loc_8809C868;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
loc_8809C868:
	// stw r10,1652(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1652, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r11,1656(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1656, ctx.r11.u32);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// beq cr6,0x8809c880
	if (ctx.cr6.eq) goto loc_8809C880;
	// lwz r10,164(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_8809C880:
	// stw r10,1640(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1640, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// beq cr6,0x8809c894
	if (ctx.cr6.eq) goto loc_8809C894;
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
loc_8809C894:
	// stw r10,1644(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1644, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
	// beq cr6,0x8809c8ac
	if (ctx.cr6.eq) goto loc_8809C8AC;
	// lwz r9,176(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// bne cr6,0x8809c8b4
	if (!ctx.cr6.eq) goto loc_8809C8B4;
loc_8809C8AC:
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// b 0x8809c8b8
	goto loc_8809C8B8;
loc_8809C8B4:
	// lwz r10,164(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_8809C8B8:
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lis r7,-30633
	ctx.r7.s64 = -2007564288;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stw r10,2328(r8)
	PPC_STORE_U32(ctx.r8.u32 + 2328, ctx.r10.u32);
	// stw r28,-29776(r7)
	PPC_STORE_U32(ctx.r7.u32 + -29776, ctx.r28.u32);
	// stw r9,2332(r8)
	PPC_STORE_U32(ctx.r8.u32 + 2332, ctx.r9.u32);
	// bl 0x880971a8
	ctx.lr = 0x8809C8D4;
	sub_880971A8(ctx, base);
	// li r3,3
	ctx.r3.s64 = 3;
loc_8809C8D8:
	// addi r5,r31,1496
	ctx.r5.s64 = ctx.r31.s64 + 1496;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x8809be18
	ctx.lr = 0x8809C8E4;
	sub_8809BE18(ctx, base);
loc_8809C8E4:
	// stw r29,1492(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1492, ctx.r29.u32);
loc_8809C8E8:
	// lwz r11,1548(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1548);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x8809c928
	if (ctx.cr6.eq) goto loc_8809C928;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x8809c938
	if (ctx.cr6.eq) goto loc_8809C938;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x8809c978
	if (!ctx.cr6.eq) goto loc_8809C978;
	// lwz r11,1552(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1552);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,1552(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1552, ctx.r11.u32);
	// bge 0x8809c978
	if (!ctx.cr0.lt) goto loc_8809C978;
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r28,136(r30)
	PPC_STORE_U32(ctx.r30.u32 + 136, ctx.r28.u32);
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stw r10,1548(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1548, ctx.r10.u32);
	// b 0x8809c978
	goto loc_8809C978;
loc_8809C928:
	// li r11,32
	ctx.r11.s64 = 32;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r11,1552(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1552, ctx.r11.u32);
	// stw r10,1548(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1548, ctx.r10.u32);
loc_8809C938:
	// lwz r11,1552(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1552);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,1552(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1552, ctx.r11.u32);
	// bge 0x8809c978
	if (!ctx.cr0.lt) goto loc_8809C978;
	// li r9,8
	ctx.r9.s64 = 8;
	// addi r10,r30,118
	ctx.r10.s64 = ctx.r30.s64 + 118;
	// addi r11,r30,68
	ctx.r11.s64 = ctx.r30.s64 + 68;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8809C958:
	// stw r29,-28(r11)
	PPC_STORE_U32(ctx.r11.u32 + -28, ctx.r29.u32);
	// stwu r29,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r29.u32);
	ctx.r11.u32 = ea;
	// sth r29,-14(r10)
	PPC_STORE_U16(ctx.r10.u32 + -14, ctx.r29.u16);
	// sthu r29,2(r10)
	ea = 2 + ctx.r10.u32;
	PPC_STORE_U16(ea, ctx.r29.u16);
	ctx.r10.u32 = ea;
	// bdnz 0x8809c958
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8809C958;
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r11,1552(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1552, ctx.r11.u32);
	// stw r11,1548(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1548, ctx.r11.u32);
loc_8809C978:
	// lwz r11,1528(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1528);
	// lwz r9,1280(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1280);
	// lwz r8,1544(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1544);
	// subf. r10,r11,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r11.s64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r11,1540(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1540);
	// bgt 0x8809c9a8
	if (ctx.cr0.gt) goto loc_8809C9A8;
	// lwz r11,1532(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1532);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// subf. r11,r11,r9
	ctx.r11.s64 = ctx.r9.s64 - ctx.r11.s64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt 0x8809c9a8
	if (ctx.cr0.gt) goto loc_8809C9A8;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
loc_8809C9A8:
	// lwz r9,1536(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1536);
	// stw r10,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r10.u32);
	// stw r9,40(r30)
	PPC_STORE_U32(ctx.r30.u32 + 40, ctx.r9.u32);
	// lwz r10,1540(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1540);
	// stw r10,44(r30)
	PPC_STORE_U32(ctx.r30.u32 + 44, ctx.r10.u32);
	// stw r11,76(r30)
	PPC_STORE_U32(ctx.r30.u32 + 76, ctx.r11.u32);
	// lwz r11,1544(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1544);
	// stw r8,80(r30)
	PPC_STORE_U32(ctx.r30.u32 + 80, ctx.r8.u32);
	// stw r11,48(r30)
	PPC_STORE_U32(ctx.r30.u32 + 48, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809C9D4"))) PPC_WEAK_FUNC(sub_8809C9D4);
PPC_FUNC_IMPL(__imp__sub_8809C9D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8809C9D8"))) PPC_WEAK_FUNC(sub_8809C9D8);
PPC_FUNC_IMPL(__imp__sub_8809C9D8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,2304(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// b 0x8809c220
	sub_8809C220(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809C9E0"))) PPC_WEAK_FUNC(sub_8809C9E0);
PPC_FUNC_IMPL(__imp__sub_8809C9E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x8809C9E8;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30710
	ctx.r11.s64 = -2012610560;
	// li r4,26500
	ctx.r4.s64 = 26500;
	// addi r5,r11,-13856
	ctx.r5.s64 = ctx.r11.s64 + -13856;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x8809CA00;
	sub_88094290(ctx, base);
	// li r5,26500
	ctx.r5.s64 = 26500;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,2304(r29)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r29.u32 + 2304);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x8809CA14;
	sub_88073BD0(ctx, base);
	// lis r10,-30641
	ctx.r10.s64 = -2008088576;
	// li r5,12
	ctx.r5.s64 = 12;
	// addi r3,r10,-18804
	ctx.r3.s64 = ctx.r10.s64 + -18804;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x88073bd0
	ctx.lr = 0x8809CA28;
	sub_88073BD0(ctx, base);
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// lis r8,-30710
	ctx.r8.s64 = -2012610560;
	// addi r7,r9,-11984
	ctx.r7.s64 = ctx.r9.s64 + -11984;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r4,r8,-13864
	ctx.r4.s64 = ctx.r8.s64 + -13864;
	// lwz r30,-11984(r9)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + -11984);
	// stw r29,-8(r7)
	PPC_STORE_U32(ctx.r7.u32 + -8, ctx.r29.u32);
	// lwz r6,84(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 84);
	// stw r6,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r6.u32);
	// bl 0x88096200
	ctx.lr = 0x8809CA50;
	sub_88096200(ctx, base);
	// lis r10,-30683
	ctx.r10.s64 = -2010841088;
	// lis r5,9
	ctx.r5.s64 = 589824;
	// stw r29,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// lis r4,2
	ctx.r4.s64 = 131072;
	// stw r30,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// lis r8,12
	ctx.r8.s64 = 786432;
	// ori r11,r5,7808
	ctx.r11.u64 = ctx.r5.u64 | 7808;
	// stw r9,1316(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1316, ctx.r9.u32);
	// addi r27,r10,15092
	ctx.r27.s64 = ctx.r10.s64 + 15092;
	// li r28,0
	ctx.r28.s64 = 0;
	// stw r11,1528(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1528, ctx.r11.u32);
	// ori r7,r4,18336
	ctx.r7.u64 = ctx.r4.u64 | 18336;
	// ori r6,r8,48768
	ctx.r6.u64 = ctx.r8.u64 | 48768;
	// stw r28,1532(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1532, ctx.r28.u32);
	// stw r7,1288(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1288, ctx.r7.u32);
	// stw r11,1540(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1540, ctx.r11.u32);
	// stw r6,1536(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1536, ctx.r6.u32);
	// stw r28,1544(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1544, ctx.r28.u32);
	// lwz r10,6704(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 6704);
	// lwz r11,6700(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 6700);
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r5,r11,r9
	ctx.r5.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r5,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addi r11,r11,1180
	ctx.r11.s64 = ctx.r11.s64 + 1180;
	// stw r10,100(r11)
	PPC_STORE_U32(ctx.r11.u32 + 100, ctx.r10.u32);
	// lwz r10,6704(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 6704);
	// lwz r4,136(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 136);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// stw r10,104(r11)
	PPC_STORE_U32(ctx.r11.u32 + 104, ctx.r10.u32);
	// bne cr6,0x8809cae4
	if (!ctx.cr6.eq) goto loc_8809CAE4;
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 100);
	// srawi r9,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 2;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// stw r8,108(r11)
	PPC_STORE_U32(ctx.r11.u32 + 108, ctx.r8.u32);
loc_8809CAE4:
	// lwz r11,6720(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 6720);
	// lwz r10,6724(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 6724);
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addi r11,r11,1180
	ctx.r11.s64 = ctx.r11.s64 + 1180;
	// stw r10,100(r11)
	PPC_STORE_U32(ctx.r11.u32 + 100, ctx.r10.u32);
	// lwz r10,6724(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 6724);
	// stw r10,104(r11)
	PPC_STORE_U32(ctx.r11.u32 + 104, ctx.r10.u32);
	// lwz r10,136(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 136);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8809cb28
	if (!ctx.cr6.eq) goto loc_8809CB28;
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 100);
	// srawi r9,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 2;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// stw r8,108(r11)
	PPC_STORE_U32(ctx.r11.u32 + 108, ctx.r8.u32);
loc_8809CB28:
	// lis r11,-30689
	ctx.r11.s64 = -2011234304;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-12280
	ctx.r4.s64 = ctx.r11.s64 + -12280;
	// bl 0x880969a8
	ctx.lr = 0x8809CB38;
	sub_880969A8(ctx, base);
	// li r10,113
	ctx.r10.s64 = 113;
	// stw r28,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r28.u32);
	// lis r9,32
	ctx.r9.s64 = 2097152;
	// stw r10,168(r29)
	PPC_STORE_U32(ctx.r29.u32 + 168, ctx.r10.u32);
	// lis r8,-96
	ctx.r8.s64 = -6291456;
	// stw r9,1156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1156, ctx.r9.u32);
	// li r10,72
	ctx.r10.s64 = 72;
	// stw r8,1160(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1160, ctx.r8.u32);
	// lis r7,120
	ctx.r7.s64 = 7864320;
	// lis r6,500
	ctx.r6.s64 = 32768000;
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r11,r31,576
	ctx.r11.s64 = ctx.r31.s64 + 576;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r4,r10,55
	ctx.r4.s64 = ctx.r10.s64 + 55;
	// rlwinm r3,r4,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r3,r30
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r30.u32);
	// subf r9,r10,r7
	ctx.r9.s64 = ctx.r7.s64 - ctx.r10.s64;
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// stw r6,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r6.u32);
	// stw r5,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r5.u32);
	// lwz r8,32(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 32);
	// stw r8,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r8.u32);
	// lwz r7,36(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 36);
	// stw r7,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r7.u32);
loc_8809CB9C:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// stwu r9,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8809cb9c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8809CB9C;
	// lis r10,-30710
	ctx.r10.s64 = -2012610560;
	// lis r9,-30710
	ctx.r9.s64 = -2012610560;
	// addi r11,r27,6700
	ctx.r11.s64 = ctx.r27.s64 + 6700;
	// addi r8,r10,-15360
	ctx.r8.s64 = ctx.r10.s64 + -15360;
	// addi r7,r9,-17544
	ctx.r7.s64 = ctx.r9.s64 + -17544;
	// stw r8,64(r29)
	PPC_STORE_U32(ctx.r29.u32 + 64, ctx.r8.u32);
	// li r26,2
	ctx.r26.s64 = 2;
	// stw r7,84(r29)
	PPC_STORE_U32(ctx.r29.u32 + 84, ctx.r7.u32);
	// addi r30,r11,16
	ctx.r30.s64 = ctx.r11.s64 + 16;
loc_8809CBD4:
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x881556a0
	ctx.lr = 0x8809CBE0;
	sub_881556A0(ctx, base);
	// lwz r11,-16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -16);
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r11,r31
	ctx.r10.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stw r3,1180(r10)
	PPC_STORE_U32(ctx.r10.u32 + 1180, ctx.r3.u32);
	// lwz r8,-8(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + -8);
	// lwz r11,-16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -16);
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r7,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// add r6,r11,r31
	ctx.r6.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lwz r5,1180(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 1180);
	// stw r29,36(r5)
	PPC_STORE_U32(ctx.r5.u32 + 36, ctx.r29.u32);
	// stw r8,32(r5)
	PPC_STORE_U32(ctx.r5.u32 + 32, ctx.r8.u32);
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// lwz r11,-4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -4);
	// ble cr6,0x8809cd00
	if (!ctx.cr6.gt) goto loc_8809CD00;
	// addi r10,r11,-4
	ctx.r10.s64 = ctx.r11.s64 + -4;
loc_8809CC34:
	// lwz r11,-16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -16);
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// rlwinm r7,r11,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r7,r11,r31
	ctx.r7.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lwz r7,1180(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + 1180);
	// lwz r11,28(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809cc74
	if (ctx.cr6.eq) goto loc_8809CC74;
loc_8809CC5C:
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x8809cdbc
	if (ctx.cr6.eq) goto loc_8809CDBC;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8809cc5c
	if (!ctx.cr6.eq) goto loc_8809CC5C;
loc_8809CC74:
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
loc_8809CC78:
	// lwz r8,12(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r8,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// rlwinm r7,r8,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// add r7,r8,r7
	ctx.r7.u64 = ctx.r8.u64 + ctx.r7.u64;
	// lwz r6,8(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// rlwinm r8,r7,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// addi r6,r8,148
	ctx.r6.s64 = ctx.r8.s64 + 148;
	// rlwinm r8,r6,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// add r5,r8,r31
	ctx.r5.u64 = ctx.r8.u64 + ctx.r31.u64;
	// stw r5,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r5.u32);
	// lwz r4,16(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// stw r4,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r4.u32);
	// lwz r3,20(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// stw r3,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r3.u32);
	// lhz r8,24(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 24);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// stw r7,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r7.u32);
	// lhz r6,26(r10)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r10.u32 + 26);
	// extsh r5,r6
	ctx.r5.s64 = ctx.r6.s16;
	// stw r5,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r5.u32);
	// lhz r4,28(r10)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + 28);
	// extsh r3,r4
	ctx.r3.s64 = ctx.r4.s16;
	// stw r3,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r3.u32);
	// lhz r8,30(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 30);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// stw r7,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r7.u32);
	// lwzu r8,32(r10)
	ea = 32 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// stw r8,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r8.u32);
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmpw cr6,r9,r6
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r6.s32, ctx.xer);
	// blt cr6,0x8809cc34
	if (ctx.cr6.lt) goto loc_8809CC34;
loc_8809CD00:
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// addi r30,r30,20
	ctx.r30.s64 = ctx.r30.s64 + 20;
	// bne 0x8809cbd4
	if (!ctx.cr0.eq) goto loc_8809CBD4;
	// lwz r9,2304(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 2304);
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r11,r31,1156
	ctx.r11.s64 = ctx.r31.s64 + 1156;
	// lwz r8,1324(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 1324);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lis r10,128
	ctx.r10.s64 = 8388608;
	// ori r10,r10,32896
	ctx.r10.u64 = ctx.r10.u64 | 32896;
	// stw r28,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r28.u32);
loc_8809CD2C:
	// stwu r10,144(r11)
	ea = 144 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8809cd2c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8809CD2C;
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lis r9,-30642
	ctx.r9.s64 = -2008154112;
	// li r10,8
	ctx.r10.s64 = 8;
	// li r8,128
	ctx.r8.s64 = 128;
	// stw r11,1560(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1560, ctx.r11.u32);
	// addi r11,r9,-32760
	ctx.r11.s64 = ctx.r9.s64 + -32760;
	// lwz r9,4(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// stw r9,1564(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1564, ctx.r9.u32);
	// addi r10,r11,118
	ctx.r10.s64 = ctx.r11.s64 + 118;
	// lwz r9,8(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 8);
	// addi r11,r11,68
	ctx.r11.s64 = ctx.r11.s64 + 68;
	// stw r9,1568(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1568, ctx.r9.u32);
	// stw r8,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r8.u32);
	// stw r28,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r28.u32);
	// stw r28,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r28.u32);
	// stw r28,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r28.u32);
loc_8809CD78:
	// stw r28,-28(r11)
	PPC_STORE_U32(ctx.r11.u32 + -28, ctx.r28.u32);
	// stwu r28,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r28.u32);
	ctx.r11.u32 = ea;
	// sth r28,-14(r10)
	PPC_STORE_U16(ctx.r10.u32 + -14, ctx.r28.u16);
	// sthu r28,2(r10)
	ea = 2 + ctx.r10.u32;
	PPC_STORE_U16(ea, ctx.r28.u16);
	ctx.r10.u32 = ea;
	// bdnz 0x8809cd78
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8809CD78;
	// lis r8,-30633
	ctx.r8.s64 = -2007564288;
	// stw r28,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r28.u32);
	// lis r7,-30633
	ctx.r7.s64 = -2007564288;
	// lis r6,-30633
	ctx.r6.s64 = -2007564288;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// stw r28,-29732(r8)
	PPC_STORE_U32(ctx.r8.u32 + -29732, ctx.r28.u32);
	// stw r28,-29736(r7)
	PPC_STORE_U32(ctx.r7.u32 + -29736, ctx.r28.u32);
	// stw r28,-29760(r6)
	PPC_STORE_U32(ctx.r6.u32 + -29760, ctx.r28.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_8809CDBC:
	// lwz r8,24(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x8809cdcc
	if (ctx.cr6.eq) goto loc_8809CDCC;
	// stw r8,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r8.u32);
loc_8809CDCC:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x8809cc78
	goto loc_8809CC78;
}

__attribute__((alias("__imp__sub_8809CDD4"))) PPC_WEAK_FUNC(sub_8809CDD4);
PPC_FUNC_IMPL(__imp__sub_8809CDD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8809CDD8"))) PPC_WEAK_FUNC(sub_8809CDD8);
PPC_FUNC_IMPL(__imp__sub_8809CDD8) {
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
	// lwz r3,2304(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 2304);
	// addi r31,r3,1324
	ctx.r31.s64 = ctx.r3.s64 + 1324;
	// lwz r11,1436(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1436);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8809ce24
	if (!ctx.cr6.eq) goto loc_8809CE24;
	// lwz r11,1172(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1172);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,1172(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1172, ctx.r11.u32);
	// cmpwi cr6,r11,160
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 160, ctx.xer);
	// blt cr6,0x8809ce18
	if (ctx.cr6.lt) goto loc_8809CE18;
	// li r11,160
	ctx.r11.s64 = 160;
	// stw r11,1172(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1172, ctx.r11.u32);
loc_8809CE18:
	// bl 0x8809bc58
	ctx.lr = 0x8809CE1C;
	sub_8809BC58(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r11.u32);
loc_8809CE24:
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

__attribute__((alias("__imp__sub_8809CE3C"))) PPC_WEAK_FUNC(sub_8809CE3C);
PPC_FUNC_IMPL(__imp__sub_8809CE3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8809CE40"))) PPC_WEAK_FUNC(sub_8809CE40);
PPC_FUNC_IMPL(__imp__sub_8809CE40) {
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
	// lwz r31,2304(r4)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r4.u32 + 2304);
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r10,r31,1180
	ctx.r10.s64 = ctx.r31.s64 + 1180;
	// stw r8,1292(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1292, ctx.r8.u32);
	// lwz r11,1480(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1480);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8809cf38
	if (!ctx.cr6.eq) goto loc_8809CF38;
	// lwz r11,1164(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1164);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8809cf38
	if (!ctx.cr6.eq) goto loc_8809CF38;
	// lwz r11,100(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 100);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8809cf38
	if (!ctx.cr6.gt) goto loc_8809CF38;
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// subf r11,r9,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r9.s64;
	// stw r11,100(r10)
	PPC_STORE_U32(ctx.r10.u32 + 100, ctx.r11.u32);
	// lwz r9,1484(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1484);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x8809cf54
	if (!ctx.cr6.eq) goto loc_8809CF54;
	// lwz r7,1528(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1528);
	// cmpw cr6,r11,r7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r7.s32, ctx.xer);
	// bgt cr6,0x8809cf54
	if (ctx.cr6.gt) goto loc_8809CF54;
	// stw r8,1592(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1592, ctx.r8.u32);
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809cec4
	if (ctx.cr6.eq) goto loc_8809CEC4;
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
loc_8809CEC4:
	// stw r11,1596(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1596, ctx.r11.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// stw r11,1600(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1600, ctx.r11.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809cee0
	if (ctx.cr6.eq) goto loc_8809CEE0;
	// lwz r11,164(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_8809CEE0:
	// stw r11,1584(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1584, ctx.r11.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809cef4
	if (ctx.cr6.eq) goto loc_8809CEF4;
	// lwz r11,176(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
loc_8809CEF4:
	// stw r11,1588(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1588, ctx.r11.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809cf10
	if (ctx.cr6.eq) goto loc_8809CF10;
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// bne cr6,0x8809cf18
	if (!ctx.cr6.eq) goto loc_8809CF18;
loc_8809CF10:
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x8809cf1c
	goto loc_8809CF1C;
loc_8809CF18:
	// lwz r11,164(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_8809CF1C:
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,1
	ctx.r3.s64 = 1;
loc_8809CF2C:
	// stw r11,2328(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2328, ctx.r11.u32);
	// stw r10,2332(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2332, ctx.r10.u32);
	// bl 0x8809be18
	ctx.lr = 0x8809CF38;
	sub_8809BE18(ctx, base);
loc_8809CF38:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8809CF3C:
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
loc_8809CF54:
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x8809d0c8
	if (!ctx.cr6.eq) goto loc_8809D0C8;
	// lwz r11,100(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 100);
	// lwz r7,1532(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1532);
	// cmpw cr6,r11,r7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r7.s32, ctx.xer);
	// bgt cr6,0x8809d0c8
	if (ctx.cr6.gt) goto loc_8809D0C8;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r9,r11,26432
	ctx.r9.s64 = ctx.r11.s64 + 26432;
	// lwz r11,324(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 324);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8809cf8c
	if (!ctx.cr6.eq) goto loc_8809CF8C;
loc_8809CF80:
	// li r11,512
	ctx.r11.s64 = 512;
	// stw r11,100(r10)
	PPC_STORE_U32(ctx.r10.u32 + 100, ctx.r11.u32);
	// b 0x8809cf38
	goto loc_8809CF38;
loc_8809CF8C:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r10,1476(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1476);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8809d0f0
	if (!ctx.cr6.eq) goto loc_8809D0F0;
	// lwz r11,1672(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1672);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8809d0f0
	if (!ctx.cr6.eq) goto loc_8809D0F0;
	// stw r8,1620(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1620, ctx.r8.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809cfbc
	if (ctx.cr6.eq) goto loc_8809CFBC;
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
loc_8809CFBC:
	// stw r11,1624(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1624, ctx.r11.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// stw r11,1628(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1628, ctx.r11.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809cfd8
	if (ctx.cr6.eq) goto loc_8809CFD8;
	// lwz r11,164(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_8809CFD8:
	// stw r11,1612(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1612, ctx.r11.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809cfec
	if (ctx.cr6.eq) goto loc_8809CFEC;
	// lwz r11,176(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
loc_8809CFEC:
	// stw r11,1616(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1616, ctx.r11.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809d008
	if (ctx.cr6.eq) goto loc_8809D008;
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// bne cr6,0x8809d020
	if (!ctx.cr6.eq) goto loc_8809D020;
loc_8809D008:
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,2
	ctx.r3.s64 = 2;
	// b 0x8809cf2c
	goto loc_8809CF2C;
loc_8809D020:
	// lwz r11,164(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,2
	ctx.r3.s64 = 2;
	// b 0x8809cf2c
	goto loc_8809CF2C;
loc_8809D038:
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
loc_8809D03C:
	// stw r11,1652(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1652, ctx.r11.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// stw r11,1656(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1656, ctx.r11.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809d058
	if (ctx.cr6.eq) goto loc_8809D058;
	// lwz r11,164(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_8809D058:
	// stw r11,1640(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1640, ctx.r11.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809d06c
	if (ctx.cr6.eq) goto loc_8809D06C;
	// lwz r11,176(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
loc_8809D06C:
	// stw r11,1644(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1644, ctx.r11.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809d088
	if (ctx.cr6.eq) goto loc_8809D088;
	// lwz r9,176(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// bne cr6,0x8809d090
	if (!ctx.cr6.eq) goto loc_8809D090;
loc_8809D088:
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x8809d094
	goto loc_8809D094;
loc_8809D090:
	// lwz r10,164(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_8809D094:
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lis r6,-30633
	ctx.r6.s64 = -2007564288;
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// stw r10,2328(r7)
	PPC_STORE_U32(ctx.r7.u32 + 2328, ctx.r10.u32);
	// stw r8,-29776(r6)
	PPC_STORE_U32(ctx.r6.u32 + -29776, ctx.r8.u32);
	// stw r9,2332(r7)
	PPC_STORE_U32(ctx.r7.u32 + 2332, ctx.r9.u32);
	// bl 0x880971a8
	ctx.lr = 0x8809D0B0;
	sub_880971A8(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x8809be18
	ctx.lr = 0x8809D0C0;
	sub_8809BE18(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8809cf3c
	goto loc_8809CF3C;
loc_8809D0C8:
	// cmpwi cr6,r9,2
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 2, ctx.xer);
	// bne cr6,0x8809cf38
	if (!ctx.cr6.eq) goto loc_8809CF38;
	// lwz r11,100(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 100);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt cr6,0x8809cf38
	if (ctx.cr6.gt) goto loc_8809CF38;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r9,r11,26432
	ctx.r9.s64 = ctx.r11.s64 + 26432;
	// lwz r11,324(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 324);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809cf80
	if (ctx.cr6.eq) goto loc_8809CF80;
loc_8809D0F0:
	// stw r8,1648(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1648, ctx.r8.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8809d038
	if (!ctx.cr6.eq) goto loc_8809D038;
	// b 0x8809d03c
	goto loc_8809D03C;
}

__attribute__((alias("__imp__sub_8809D104"))) PPC_WEAK_FUNC(sub_8809D104);
PPC_FUNC_IMPL(__imp__sub_8809D104) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8809D108"))) PPC_WEAK_FUNC(sub_8809D108);
PPC_FUNC_IMPL(__imp__sub_8809D108) {
	PPC_FUNC_PROLOGUE();
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// b 0x8809ce40
	sub_8809CE40(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809D110"))) PPC_WEAK_FUNC(sub_8809D110);
PPC_FUNC_IMPL(__imp__sub_8809D110) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8809D114"))) PPC_WEAK_FUNC(sub_8809D114);
PPC_FUNC_IMPL(__imp__sub_8809D114) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8809D118"))) PPC_WEAK_FUNC(sub_8809D118);
PPC_FUNC_IMPL(__imp__sub_8809D118) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x8809D120;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// li r6,214
	ctx.r6.s64 = 214;
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r28,r11,64
	ctx.r28.s64 = ctx.r11.s64 + 64;
	// lwz r5,16(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r25,r28,10750
	ctx.r25.s64 = ctx.r28.s64 + 10750;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x881538c0
	ctx.lr = 0x8809D148;
	sub_881538C0(ctx, base);
	// lis r27,-30597
	ctx.r27.s64 = -2005204992;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809d174
	if (ctx.cr6.eq) goto loc_8809D174;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-11932(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
	// oris r9,r10,547
	ctx.r9.u64 = ctx.r10.u64 | 35848192;
	// addi r30,r11,1
	ctx.r30.s64 = ctx.r11.s64 + 1;
	// ori r9,r9,49152
	ctx.r9.u64 = ctx.r9.u64 | 49152;
	// stw r30,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r30.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// b 0x8809d178
	goto loc_8809D178;
loc_8809D174:
	// lwz r30,-11932(r27)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
loc_8809D178:
	// addi r26,r28,10878
	ctx.r26.s64 = ctx.r28.s64 + 10878;
	// lwz r29,12(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r28,16(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// li r6,214
	ctx.r6.s64 = 214;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x881538c0
	ctx.lr = 0x8809D198;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809d1b8
	if (ctx.cr6.eq) goto loc_8809D1B8;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// oris r10,r11,545
	ctx.r10.u64 = ctx.r11.u64 | 35717120;
	// stw r30,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r30.u32);
	// ori r10,r10,65280
	ctx.r10.u64 = ctx.r10.u64 | 65280;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_8809D1B8:
	// li r6,218
	ctx.r6.s64 = 218;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x881538c0
	ctx.lr = 0x8809D1CC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809d1ec
	if (ctx.cr6.eq) goto loc_8809D1EC;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// oris r10,r11,547
	ctx.r10.u64 = ctx.r11.u64 | 35848192;
	// stw r30,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r30.u32);
	// ori r10,r10,32768
	ctx.r10.u64 = ctx.r10.u64 | 32768;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_8809D1EC:
	// li r6,218
	ctx.r6.s64 = 218;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x881538c0
	ctx.lr = 0x8809D200;
	sub_881538C0(ctx, base);
	// lis r11,545
	ctx.r11.s64 = 35717120;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// ori r31,r11,32768
	ctx.r31.u64 = ctx.r11.u64 | 32768;
	// beq cr6,0x8809d224
	if (ctx.cr6.eq) goto loc_8809D224;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// or r10,r11,r31
	ctx.r10.u64 = ctx.r11.u64 | ctx.r31.u64;
	// stw r30,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r30.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_8809D224:
	// lis r3,0
	ctx.r3.s64 = 0;
	// li r6,218
	ctx.r6.s64 = 218;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// ori r3,r3,45204
	ctx.r3.u64 = ctx.r3.u64 | 45204;
	// bl 0x881538c0
	ctx.lr = 0x8809D23C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809d264
	if (ctx.cr6.eq) goto loc_8809D264;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,128
	ctx.r9.s64 = 8388608;
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// ori r8,r9,8320
	ctx.r8.u64 = ctx.r9.u64 | 8320;
	// or r7,r10,r31
	ctx.r7.u64 = ctx.r10.u64 | ctx.r31.u64;
	// stw r11,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r11.u32);
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
loc_8809D264:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809D26C"))) PPC_WEAK_FUNC(sub_8809D26C);
PPC_FUNC_IMPL(__imp__sub_8809D26C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8809D270"))) PPC_WEAK_FUNC(sub_8809D270);
PPC_FUNC_IMPL(__imp__sub_8809D270) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x8809D278;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r10,172(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 172);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// blt cr6,0x8809d29c
	if (ctx.cr6.lt) goto loc_8809D29C;
	// lwz r11,188(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 188);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x8809d2a8
	goto loc_8809D2A8;
loc_8809D29C:
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 184);
	// lwz r11,168(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 168);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_8809D2A8:
	// lwz r29,12(r30)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lis r25,-30667
	ctx.r25.s64 = -2009792512;
	// lwz r28,16(r30)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// lis r26,-30667
	ctx.r26.s64 = -2009792512;
	// lis r24,-30667
	ctx.r24.s64 = -2009792512;
	// lwz r31,0(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lis r27,-30667
	ctx.r27.s64 = -2009792512;
	// addi r4,r11,2
	ctx.r4.s64 = ctx.r11.s64 + 2;
	// stw r29,12364(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12364, ctx.r29.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r28,12372(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12372, ctx.r28.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r4,12376(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12376, ctx.r4.u32);
	// stw r11,12380(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12380, ctx.r11.u32);
	// bl 0x880f52c8
	ctx.lr = 0x8809D2E4;
	sub_880F52C8(ctx, base);
	// lwz r11,1620(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1620);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8809d340
	if (!ctx.cr6.eq) goto loc_8809D340;
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r8,1616(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1616);
	// lwz r7,1612(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1612);
	// lwz r6,1628(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1628);
	// lwz r5,1624(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1624);
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// bl 0x880f5438
	ctx.lr = 0x8809D30C;
	sub_880F5438(ctx, base);
	// lwz r10,1624(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1624);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8809d340
	if (!ctx.cr6.eq) goto loc_8809D340;
	// stw r29,12364(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12364, ctx.r29.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r28,12372(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12372, ctx.r28.u32);
	// li r10,140
	ctx.r10.s64 = 140;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,12380(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12380, ctx.r11.u32);
	// li r4,140
	ctx.r4.s64 = 140;
	// stw r10,12376(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12376, ctx.r10.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x881607f8
	ctx.lr = 0x8809D340;
	sub_881607F8(ctx, base);
loc_8809D340:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809D348"))) PPC_WEAK_FUNC(sub_8809D348);
PPC_FUNC_IMPL(__imp__sub_8809D348) {
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,1620(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1620);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8809d42c
	if (!ctx.cr6.eq) goto loc_8809D42C;
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lis r5,-30643
	ctx.r5.s64 = -2008219648;
	// lis r9,-30714
	ctx.r9.s64 = -2012872704;
	// lwz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// clrlwi r10,r11,23
	ctx.r10.u64 = ctx.r11.u32 & 0x1FF;
	// lwz r7,16(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r4,r9,9552
	ctx.r4.s64 = ctx.r9.s64 + 9552;
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r3,r10,128
	ctx.r3.s64 = ctx.r10.s64 + 128;
	// rlwinm r8,r11,2,21,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x7FC;
	// lwz r10,26272(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 26272);
	// rlwinm r3,r3,2,21,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x7FC;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwzx r10,r8,r4
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r4.u32);
	// lwzx r5,r3,r4
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r4.u32);
	// mullw r8,r10,r6
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r6.s32);
	// mullw r6,r5,r6
	ctx.r6.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r6.s32);
	// add r4,r8,r9
	ctx.r4.u64 = ctx.r8.u64 + ctx.r9.u64;
	// add r5,r6,r7
	ctx.r5.u64 = ctx.r6.u64 + ctx.r7.u64;
	// stw r4,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r4.u32);
	// stw r5,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r5.u32);
	// beq cr6,0x8809d3d4
	if (ctx.cr6.eq) goto loc_8809D3D4;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x8809d3ec
	goto loc_8809D3EC;
loc_8809D3D4:
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// addi r8,r10,51
	ctx.r8.s64 = ctx.r10.s64 + 51;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,-11984(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -11984);
	// lwzx r10,r7,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
loc_8809D3EC:
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r8,32(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// add r4,r9,r10
	ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addic. r10,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r10.s64 = ctx.r8.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r4,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r4.u32);
	// stw r10,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r10.u32);
	// bgt 0x8809d440
	if (ctx.cr0.gt) goto loc_8809D440;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r9,r11,256
	ctx.r9.s64 = ctx.r11.s64 + 256;
	// lwz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// li r3,242
	ctx.r3.s64 = 242;
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// stw r8,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r8.u32);
	// bl 0x880958a0
	ctx.lr = 0x8809D42C;
	sub_880958A0(ctx, base);
loc_8809D42C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8809d270
	ctx.lr = 0x8809D434;
	sub_8809D270(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88094220
	ctx.lr = 0x8809D43C;
	sub_88094220(ctx, base);
	// b 0x8809d468
	goto loc_8809D468;
loc_8809D440:
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// bge 0x8809d468
	if (!ctx.cr0.lt) goto loc_8809D468;
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// clrlwi r8,r9,29
	ctx.r8.u64 = ctx.r9.u32 & 0x7;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// stw r8,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r8.u32);
loc_8809D468:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
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

__attribute__((alias("__imp__sub_8809D480"))) PPC_WEAK_FUNC(sub_8809D480);
PPC_FUNC_IMPL(__imp__sub_8809D480) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071140
	ctx.lr = 0x8809D488;
	__savegprlr_22(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30710
	ctx.r11.s64 = -2012610560;
	// li r4,212
	ctx.r4.s64 = 212;
	// addi r5,r11,-11136
	ctx.r5.s64 = ctx.r11.s64 + -11136;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x8809D4A0;
	sub_88094290(ctx, base);
	// li r5,212
	ctx.r5.s64 = 212;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r30,2304(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2304);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88073bd0
	ctx.lr = 0x8809D4B4;
	sub_88073BD0(ctx, base);
	// lis r10,16838
	ctx.r10.s64 = 1103495168;
	// lis r29,-30671
	ctx.r29.s64 = -2010054656;
	// stw r31,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r31.u32);
	// ori r10,r10,20077
	ctx.r10.u64 = ctx.r10.u64 | 20077;
	// lwz r5,32(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r9,216
	ctx.r9.s64 = 216;
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// mr r6,r10
	ctx.r6.u64 = ctx.r10.u64;
	// stw r9,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r9.u32);
	// lwz r10,4200(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4200);
	// addi r8,r31,120
	ctx.r8.s64 = ctx.r31.s64 + 120;
	// stw r5,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r5.u32);
	// li r3,32
	ctx.r3.s64 = 32;
	// mullw r10,r10,r6
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r6.s32);
	// lwz r4,36(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// stw r4,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r4.u32);
	// addi r10,r10,12345
	ctx.r10.s64 = ctx.r10.s64 + 12345;
	// lwz r6,100(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// li r28,48
	ctx.r28.s64 = 48;
	// stw r10,4200(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4200, ctx.r10.u32);
	// mullw r7,r10,r7
	ctx.r7.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32);
	// addi r10,r6,-1
	ctx.r10.s64 = ctx.r6.s64 + -1;
	// lwz r6,80(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 80);
	// addi r8,r7,12345
	ctx.r8.s64 = ctx.r7.s64 + 12345;
	// rlwinm r7,r10,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r7,-1
	ctx.r11.s64 = ctx.r7.s64 + -1;
	// li r9,1
	ctx.r9.s64 = 1;
	// and r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 & ctx.r10.u64;
	// lhz r10,4200(r29)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r29.u32 + 4200);
	// stw r8,4200(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4200, ctx.r8.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// stw r7,100(r30)
	PPC_STORE_U32(ctx.r30.u32 + 100, ctx.r7.u32);
	// clrlwi r8,r10,29
	ctx.r8.u64 = ctx.r10.u32 & 0x7;
	// lwz r7,132(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// li r11,16
	ctx.r11.s64 = 16;
	// stw r7,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r7.u32);
	// li r27,8
	ctx.r27.s64 = 8;
	// lwz r10,132(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// lis r7,-30710
	ctx.r7.s64 = -2012610560;
	// lwz r25,2304(r10)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2304);
	// lis r26,-30710
	ctx.r26.s64 = -2012610560;
	// lhz r10,4200(r29)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r29.u32 + 4200);
	// li r24,24
	ctx.r24.s64 = 24;
	// stw r25,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r25.u32);
	// li r29,9
	ctx.r29.s64 = 9;
	// lwz r23,136(r31)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r31.u32 + 136);
	// clrlwi r10,r10,29
	ctx.r10.u64 = ctx.r10.u32 & 0x7;
	// stw r23,28(r30)
	PPC_STORE_U32(ctx.r30.u32 + 28, ctx.r23.u32);
	// lis r23,-30710
	ctx.r23.s64 = -2012610560;
	// lwz r22,28(r30)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	// li r25,-32
	ctx.r25.s64 = -32;
	// stw r3,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r3.u32);
	// addi r7,r7,-11448
	ctx.r7.s64 = ctx.r7.s64 + -11448;
	// stw r28,32(r30)
	PPC_STORE_U32(ctx.r30.u32 + 32, ctx.r28.u32);
	// addi r26,r26,-12008
	ctx.r26.s64 = ctx.r26.s64 + -12008;
	// lwz r28,140(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// stw r5,160(r30)
	PPC_STORE_U32(ctx.r30.u32 + 160, ctx.r5.u32);
	// stw r5,164(r30)
	PPC_STORE_U32(ctx.r30.u32 + 164, ctx.r5.u32);
	// addi r5,r23,-12016
	ctx.r5.s64 = ctx.r23.s64 + -12016;
	// stw r28,36(r30)
	PPC_STORE_U32(ctx.r30.u32 + 36, ctx.r28.u32);
	// stw r22,136(r30)
	PPC_STORE_U32(ctx.r30.u32 + 136, ctx.r22.u32);
	// stw r8,40(r30)
	PPC_STORE_U32(ctx.r30.u32 + 40, ctx.r8.u32);
	// stw r4,48(r30)
	PPC_STORE_U32(ctx.r30.u32 + 48, ctx.r4.u32);
	// stw r9,56(r30)
	PPC_STORE_U32(ctx.r30.u32 + 56, ctx.r9.u32);
	// stw r10,60(r30)
	PPC_STORE_U32(ctx.r30.u32 + 60, ctx.r10.u32);
	// stw r9,64(r30)
	PPC_STORE_U32(ctx.r30.u32 + 64, ctx.r9.u32);
	// stw r3,68(r30)
	PPC_STORE_U32(ctx.r30.u32 + 68, ctx.r3.u32);
	// stw r27,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r27.u32);
	// stw r11,156(r30)
	PPC_STORE_U32(ctx.r30.u32 + 156, ctx.r11.u32);
	// stw r9,168(r30)
	PPC_STORE_U32(ctx.r30.u32 + 168, ctx.r9.u32);
	// stw r11,192(r30)
	PPC_STORE_U32(ctx.r30.u32 + 192, ctx.r11.u32);
	// stw r24,196(r30)
	PPC_STORE_U32(ctx.r30.u32 + 196, ctx.r24.u32);
	// stw r4,120(r30)
	PPC_STORE_U32(ctx.r30.u32 + 120, ctx.r4.u32);
	// stw r29,124(r30)
	PPC_STORE_U32(ctx.r30.u32 + 124, ctx.r29.u32);
	// stw r25,180(r30)
	PPC_STORE_U32(ctx.r30.u32 + 180, ctx.r25.u32);
	// stw r11,144(r30)
	PPC_STORE_U32(ctx.r30.u32 + 144, ctx.r11.u32);
	// stw r11,140(r30)
	PPC_STORE_U32(ctx.r30.u32 + 140, ctx.r11.u32);
	// stw r6,84(r30)
	PPC_STORE_U32(ctx.r30.u32 + 84, ctx.r6.u32);
	// stw r7,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r7.u32);
	// stw r26,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r26.u32);
	// stw r5,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r5.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x88071190
	__restgprlr_22(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809D604"))) PPC_WEAK_FUNC(sub_8809D604);
PPC_FUNC_IMPL(__imp__sub_8809D604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8809D608"))) PPC_WEAK_FUNC(sub_8809D608);
PPC_FUNC_IMPL(__imp__sub_8809D608) {
	PPC_FUNC_PROLOGUE();
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8809D610"))) PPC_WEAK_FUNC(sub_8809D610);
PPC_FUNC_IMPL(__imp__sub_8809D610) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r9,528(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 528);
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
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r7,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r7.u32);
	// stw r10,-104(r11)
	PPC_STORE_U32(ctx.r11.u32 + -104, ctx.r10.u32);
	// stwx r9,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + ctx.r11.u32, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8809D650"))) PPC_WEAK_FUNC(sub_8809D650);
PPC_FUNC_IMPL(__imp__sub_8809D650) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071140
	ctx.lr = 0x8809D658;
	__savegprlr_22(ctx, base);
	// stfd f30,-104(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -104, ctx.f30.u64);
	// stfd f31,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, ctx.f31.u64);
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// li r22,1
	ctx.r22.s64 = 1;
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8809d6b0
	if (ctx.cr6.lt) goto loc_8809D6B0;
	// bne cr6,0x8809d760
	if (!ctx.cr6.eq) goto loc_8809D760;
	// lwz r11,488(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 488);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,488(r31)
	PPC_STORE_U32(ctx.r31.u32 + 488, ctx.r11.u32);
	// bge 0x8809d760
	if (!ctx.cr0.lt) goto loc_8809D760;
	// lwz r11,476(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 476);
	// lwz r9,492(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 492);
	// lwz r10,560(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 560);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r9,488(r31)
	PPC_STORE_U32(ctx.r31.u32 + 488, ctx.r9.u32);
	// stw r8,476(r31)
	PPC_STORE_U32(ctx.r31.u32 + 476, ctx.r8.u32);
	// b 0x8809d760
	goto loc_8809D760;
loc_8809D6B0:
	// lwz r11,480(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 480);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// stw r11,480(r31)
	PPC_STORE_U32(ctx.r31.u32 + 480, ctx.r11.u32);
	// cmpwi cr6,r11,704
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 704, ctx.xer);
	// blt cr6,0x8809d6d0
	if (ctx.cr6.lt) goto loc_8809D6D0;
	// li r11,704
	ctx.r11.s64 = 704;
	// stw r22,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r22.u32);
	// stw r11,480(r31)
	PPC_STORE_U32(ctx.r31.u32 + 480, ctx.r11.u32);
loc_8809D6D0:
	// li r9,16
	ctx.r9.s64 = 16;
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// lis r9,-30714
	ctx.r9.s64 = -2012872704;
	// addi r7,r9,9552
	ctx.r7.s64 = ctx.r9.s64 + 9552;
loc_8809D6E8:
	// clrlwi r9,r11,23
	ctx.r9.u64 = ctx.r11.u32 & 0x1FF;
	// lwz r8,480(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 480);
	// rlwinm r6,r11,2,21,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x7FC;
	// addi r5,r9,128
	ctx.r5.s64 = ctx.r9.s64 + 128;
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// rlwinm r4,r5,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x7FC;
	// lwzx r3,r6,r7
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r7.u32);
	// mullw r9,r3,r8
	ctx.r9.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r8.s32);
	// lwzx r6,r4,r7
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r7.u32);
	// mullw r8,r6,r8
	ctx.r8.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r8.s32);
	// rlwinm r6,r9,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r5,r8,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r9,r6
	ctx.r9.u64 = ctx.r9.u64 + ctx.r6.u64;
	// add r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 + ctx.r5.u64;
	// stw r9,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r9.u32);
	// stw r8,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r8.u32);
	// stwu r29,28(r10)
	ea = 28 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r29.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8809d6e8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8809D6E8;
	// lwz r11,488(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 488);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,488(r31)
	PPC_STORE_U32(ctx.r31.u32 + 488, ctx.r11.u32);
	// bge 0x8809d758
	if (!ctx.cr0.lt) goto loc_8809D758;
	// lwz r11,476(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 476);
	// lwz r9,492(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 492);
	// lwz r10,560(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 560);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r9,488(r31)
	PPC_STORE_U32(ctx.r31.u32 + 488, ctx.r9.u32);
	// stw r8,476(r31)
	PPC_STORE_U32(ctx.r31.u32 + 476, ctx.r8.u32);
loc_8809D758:
	// li r11,-112
	ctx.r11.s64 = -112;
	// stw r11,468(r31)
	PPC_STORE_U32(ctx.r31.u32 + 468, ctx.r11.u32);
loc_8809D760:
	// lwz r11,548(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 548);
	// stw r29,556(r31)
	PPC_STORE_U32(ctx.r31.u32 + 556, ctx.r29.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8809d798
	if (ctx.cr6.eq) goto loc_8809D798;
	// lwz r10,540(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 540);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,540(r31)
	PPC_STORE_U32(ctx.r31.u32 + 540, ctx.r10.u32);
	// bge 0x8809d7c0
	if (!ctx.cr0.lt) goto loc_8809D7C0;
	// lwz r10,544(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 544);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// stw r22,556(r31)
	PPC_STORE_U32(ctx.r31.u32 + 556, ctx.r22.u32);
	// stw r9,548(r31)
	PPC_STORE_U32(ctx.r31.u32 + 548, ctx.r9.u32);
	// stw r10,540(r31)
	PPC_STORE_U32(ctx.r31.u32 + 540, ctx.r10.u32);
	// b 0x8809d7c0
	goto loc_8809D7C0;
loc_8809D798:
	// lwz r11,532(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 532);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,532(r31)
	PPC_STORE_U32(ctx.r31.u32 + 532, ctx.r11.u32);
	// bge 0x8809d7c0
	if (!ctx.cr0.lt) goto loc_8809D7C0;
	// lwz r11,536(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 536);
	// lwz r10,552(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 552);
	// lwz r9,572(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 572);
	// stw r11,532(r31)
	PPC_STORE_U32(ctx.r31.u32 + 532, ctx.r11.u32);
	// stw r10,548(r31)
	PPC_STORE_U32(ctx.r31.u32 + 548, ctx.r10.u32);
	// stw r9,568(r31)
	PPC_STORE_U32(ctx.r31.u32 + 568, ctx.r9.u32);
loc_8809D7C0:
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// addi r9,r11,13168
	ctx.r9.s64 = ctx.r11.s64 + 13168;
	// lis r8,0
	ctx.r8.s64 = 0;
	// addi r30,r31,20
	ctx.r30.s64 = ctx.r31.s64 + 20;
	// mr r25,r29
	ctx.r25.u64 = ctx.r29.u64;
	// lwz r24,26276(r10)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26276);
	// lis r27,500
	ctx.r27.s64 = 32768000;
	// lfd f31,24(r9)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r9.u32 + 24);
	// lis r28,250
	ctx.r28.s64 = 16384000;
	// lfd f30,16(r9)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r9.u32 + 16);
	// ori r26,r8,65408
	ctx.r26.u64 = ctx.r8.u64 | 65408;
loc_8809D7F0:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r5,476(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 476);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x88153548
	ctx.lr = 0x8809D800;
	sub_88153548(ctx, base);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lwz r5,472(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 472);
	// bl 0x88153608
	ctx.lr = 0x8809D810;
	sub_88153608(ctx, base);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r5,468(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 468);
	// bl 0x881536c8
	ctx.lr = 0x8809D820;
	sub_881536C8(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r10,92(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r8,88(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// extsw r5,r10
	ctx.r5.s64 = ctx.r10.s32;
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// std r7,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r7.u64);
	// lfd f0,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// std r5,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r5.u64);
	// lfd f13,104(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f11,f0
	ctx.f11.f64 = double(ctx.f0.s64);
	// lwz r11,96(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// fcfid f10,f13
	ctx.f10.f64 = double(ctx.f13.s64);
	// fmul f8,f11,f31
	ctx.f8.f64 = ctx.f11.f64 * ctx.f31.f64;
	// subf r6,r11,r27
	ctx.r6.s64 = ctx.r27.s64 - ctx.r11.s64;
	// srawi r3,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r3.s64 = ctx.r11.s32 >> 16;
	// extsw r4,r6
	ctx.r4.s64 = ctx.r6.s32;
	// addze r11,r3
	temp.s64 = ctx.r3.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r11.s64 = temp.s64;
	// std r4,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, ctx.r4.u64);
	// lfd f12,120(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f9,f12
	ctx.f9.f64 = double(ctx.f12.s64);
	// srawi r10,r11,3
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 3;
	// fdiv f6,f30,f9
	ctx.f6.f64 = ctx.f30.f64 / ctx.f9.f64;
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r11.s64 = temp.s64;
	// fmul f7,f10,f31
	ctx.f7.f64 = ctx.f10.f64 * ctx.f31.f64;
	// cmpwi cr6,r11,-8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -8, ctx.xer);
	// fmul f4,f8,f6
	ctx.f4.f64 = ctx.f8.f64 * ctx.f6.f64;
	// fmul f5,f7,f6
	ctx.f5.f64 = ctx.f7.f64 * ctx.f6.f64;
	// fctiwz f2,f4
	ctx.f2.s64 = (ctx.f4.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f4.f64));
	// fctiwz f3,f5
	ctx.f3.s64 = (ctx.f5.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f3.u64);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stfd f2,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f2.u64);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// add r5,r8,r28
	ctx.r5.u64 = ctx.r8.u64 + ctx.r28.u64;
	// add r4,r10,r9
	ctx.r4.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r5,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r5.u32);
	// stw r4,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r4.u32);
	// bge cr6,0x8809d8cc
	if (!ctx.cr6.lt) goto loc_8809D8CC;
	// li r11,-8
	ctx.r11.s64 = -8;
	// b 0x8809d8d8
	goto loc_8809D8D8;
loc_8809D8CC:
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// blt cr6,0x8809d8d8
	if (ctx.cr6.lt) goto loc_8809D8D8;
	// li r11,7
	ctx.r11.s64 = 7;
loc_8809D8D8:
	// stw r11,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r11.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x8809d988
	if (ctx.cr6.lt) goto loc_8809D988;
	// lwz r11,556(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 556);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8809d954
	if (ctx.cr6.eq) goto loc_8809D954;
	// lwz r11,560(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 560);
	// lwz r10,564(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 564);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r11,568(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 568);
	// blt cr6,0x8809d914
	if (ctx.cr6.lt) goto loc_8809D914;
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// bne cr6,0x8809d954
	if (!ctx.cr6.eq) goto loc_8809D954;
	// addi r10,r10,128
	ctx.r10.s64 = ctx.r10.s64 + 128;
	// b 0x8809d920
	goto loc_8809D920;
loc_8809D914:
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// bne cr6,0x8809d954
	if (!ctx.cr6.eq) goto loc_8809D954;
	// add r10,r10,r26
	ctx.r10.u64 = ctx.r10.u64 + ctx.r26.u64;
loc_8809D920:
	// clrlwi r7,r10,16
	ctx.r7.u64 = ctx.r10.u32 & 0xFFFF;
	// sth r29,166(r1)
	PPC_STORE_U16(ctx.r1.u32 + 166, ctx.r29.u16);
	// extsh r6,r11
	ctx.r6.s64 = ctx.r11.s16;
	// stw r23,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r23.u32);
	// li r3,34
	ctx.r3.s64 = 34;
	// bl 0x8815c948
	ctx.lr = 0x8809D938;
	sub_8815C948(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809d954
	if (ctx.cr6.eq) goto loc_8809D954;
	// stw r22,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r22.u32);
	// li r5,72
	ctx.r5.s64 = 72;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r3,r3,36
	ctx.r3.s64 = ctx.r3.s64 + 36;
	// bl 0x88072260
	ctx.lr = 0x8809D954;
	sub_88072260(ctx, base);
loc_8809D954:
	// lwz r11,528(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 528);
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809d980
	if (ctx.cr6.eq) goto loc_8809D980;
loc_8809D968:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8809d980
	if (ctx.cr6.eq) goto loc_8809D980;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8809d968
	if (!ctx.cr6.eq) goto loc_8809D968;
loc_8809D980:
	// stw r22,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r22.u32);
	// b 0x8809d9b8
	goto loc_8809D9B8;
loc_8809D988:
	// lwz r11,528(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 528);
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809d9b4
	if (ctx.cr6.eq) goto loc_8809D9B4;
loc_8809D99C:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8809d9b4
	if (ctx.cr6.eq) goto loc_8809D9B4;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8809d99c
	if (!ctx.cr6.eq) goto loc_8809D99C;
loc_8809D9B4:
	// stw r29,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r29.u32);
loc_8809D9B8:
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// addi r30,r30,28
	ctx.r30.s64 = ctx.r30.s64 + 28;
	// cmpwi cr6,r25,16
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 16, ctx.xer);
	// blt cr6,0x8809d7f0
	if (ctx.cr6.lt) goto loc_8809D7F0;
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f30,-104(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f31,-96(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x88071190
	__restgprlr_22(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809D9D8"))) PPC_WEAK_FUNC(sub_8809D9D8);
PPC_FUNC_IMPL(__imp__sub_8809D9D8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071130
	ctx.lr = 0x8809D9E0;
	__savegprlr_18(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r23,-30597
	ctx.r23.s64 = -2005204992;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,20
	ctx.r11.s64 = ctx.r11.s64 + 20;
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// addi r26,r11,20
	ctx.r26.s64 = ctx.r11.s64 + 20;
	// lis r11,-30681
	ctx.r11.s64 = -2010710016;
	// lwz r25,-11932(r23)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r23.u32 + -11932);
	// lis r8,128
	ctx.r8.s64 = 8388608;
	// lis r7,545
	ctx.r7.s64 = 35717120;
	// lis r6,128
	ctx.r6.s64 = 8388608;
	// li r18,16
	ctx.r18.s64 = 16;
	// ori r24,r10,34409
	ctx.r24.u64 = ctx.r10.u64 | 34409;
	// ori r19,r9,65280
	ctx.r19.u64 = ctx.r9.u64 | 65280;
	// ori r20,r8,8320
	ctx.r20.u64 = ctx.r8.u64 | 8320;
	// ori r21,r7,32768
	ctx.r21.u64 = ctx.r7.u64 | 32768;
	// ori r22,r6,32896
	ctx.r22.u64 = ctx.r6.u64 | 32896;
	// addi r27,r11,-25304
	ctx.r27.s64 = ctx.r11.s64 + -25304;
loc_8809DA2C:
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// li r28,202
	ctx.r28.s64 = 202;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bge cr6,0x8809da40
	if (!ctx.cr6.lt) goto loc_8809DA40;
	// li r28,113
	ctx.r28.s64 = 113;
loc_8809DA40:
	// subfic r11,r10,24
	ctx.xer.ca = ctx.r10.u32 <= 24;
	ctx.r11.s64 = 24 - ctx.r10.s64;
	// lwz r9,-8(r26)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r26.u32 + -8);
	// lwz r8,-4(r26)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r26.u32 + -4);
	// cmpwi cr6,r11,31
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 31, ctx.xer);
	// blt cr6,0x8809da58
	if (ctx.cr6.lt) goto loc_8809DA58;
	// li r11,31
	ctx.r11.s64 = 31;
loc_8809DA58:
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r5,r27,1
	ctx.r5.s64 = ctx.r27.s64 + 1;
	// subfic r4,r11,41
	ctx.xer.ca = ctx.r11.u32 <= 41;
	ctx.r4.s64 = 41 - ctx.r11.s64;
	// add r6,r10,r28
	ctx.r6.u64 = ctx.r10.u64 + ctx.r28.u64;
	// add r3,r11,r24
	ctx.r3.u64 = ctx.r11.u64 + ctx.r24.u64;
	// lbzx r11,r7,r27
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r27.u32);
	// rlwinm r29,r4,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lbzx r10,r7,r5
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r5.u32);
	// extsb r7,r11
	ctx.r7.s64 = ctx.r11.s8;
	// extsb r5,r10
	ctx.r5.s64 = ctx.r10.s8;
	// rlwinm r10,r7,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r5,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// add r31,r10,r9
	ctx.r31.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r30,r11,r8
	ctx.r30.u64 = ctx.r11.u64 + ctx.r8.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// bl 0x881538c0
	ctx.lr = 0x8809DA9C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809dab8
	if (ctx.cr6.eq) goto loc_8809DAB8;
	// rlwinm r11,r29,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 8) & 0xFFFFFF00;
	// or r10,r11,r29
	ctx.r10.u64 = ctx.r11.u64 | ctx.r29.u64;
	// rlwinm r9,r10,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// or r8,r9,r29
	ctx.r8.u64 = ctx.r9.u64 | ctx.r29.u64;
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
loc_8809DAB8:
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x8809db34
	if (ctx.cr6.lt) goto loc_8809DB34;
	// addi r10,r11,22593
	ctx.r10.s64 = ctx.r11.s64 + 22593;
	// add r6,r11,r28
	ctx.r6.u64 = ctx.r11.u64 + ctx.r28.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// rlwinm r3,r10,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// bl 0x881538c0
	ctx.lr = 0x8809DADC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809daf8
	if (ctx.cr6.eq) goto loc_8809DAF8;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// stw r20,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r20.u32);
	// or r10,r11,r19
	ctx.r10.u64 = ctx.r11.u64 | ctx.r19.u64;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_8809DAF8:
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// li r6,215
	ctx.r6.s64 = 215;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r11,r11,22590
	ctx.r11.s64 = ctx.r11.s64 + 22590;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// rlwinm r3,r11,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// bl 0x881538c0
	ctx.lr = 0x8809DB14;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809db34
	if (ctx.cr6.eq) goto loc_8809DB34;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// stw r22,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r22.u32);
	// or r10,r11,r21
	ctx.r10.u64 = ctx.r11.u64 | ctx.r21.u64;
	// stw r25,-11932(r23)
	PPC_STORE_U32(ctx.r23.u32 + -11932, ctx.r25.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_8809DB34:
	// addic. r18,r18,-1
	ctx.xer.ca = ctx.r18.u32 > 0;
	ctx.r18.s64 = ctx.r18.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r18.s32, 0, ctx.xer);
	// addi r26,r26,28
	ctx.r26.s64 = ctx.r26.s64 + 28;
	// bne 0x8809da2c
	if (!ctx.cr0.eq) goto loc_8809DA2C;
	// stw r25,-11932(r23)
	PPC_STORE_U32(ctx.r23.u32 + -11932, ctx.r25.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x88071180
	__restgprlr_18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809DB4C"))) PPC_WEAK_FUNC(sub_8809DB4C);
PPC_FUNC_IMPL(__imp__sub_8809DB4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8809DB50"))) PPC_WEAK_FUNC(sub_8809DB50);
PPC_FUNC_IMPL(__imp__sub_8809DB50) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x8809DB58;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// lwz r10,172(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 172);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// blt cr6,0x8809db7c
	if (ctx.cr6.lt) goto loc_8809DB7C;
	// lwz r11,188(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 188);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x8809db88
	goto loc_8809DB88;
loc_8809DB7C:
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 184);
	// lwz r11,168(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 168);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_8809DB88:
	// lwz r30,12(r4)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// lis r26,-30667
	ctx.r26.s64 = -2009792512;
	// lwz r29,16(r4)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// lis r27,-30667
	ctx.r27.s64 = -2009792512;
	// lis r25,-30667
	ctx.r25.s64 = -2009792512;
	// lwz r31,0(r24)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// lis r28,-30667
	ctx.r28.s64 = -2009792512;
	// addi r4,r11,2
	ctx.r4.s64 = ctx.r11.s64 + 2;
	// stw r30,12364(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12364, ctx.r30.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r29,12372(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12372, ctx.r29.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r4,12376(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12376, ctx.r4.u32);
	// stw r11,12380(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12380, ctx.r11.u32);
	// bl 0x880f52c8
	ctx.lr = 0x8809DBC4;
	sub_880F52C8(ctx, base);
	// lwz r11,1620(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1620);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8809dc20
	if (!ctx.cr6.eq) goto loc_8809DC20;
	// lwz r11,4(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 4);
	// lwz r8,1616(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1616);
	// lwz r7,1612(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1612);
	// lwz r6,1628(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1628);
	// lwz r5,1624(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1624);
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// bl 0x880f5438
	ctx.lr = 0x8809DBEC;
	sub_880F5438(ctx, base);
	// lwz r10,1624(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1624);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8809dc20
	if (!ctx.cr6.eq) goto loc_8809DC20;
	// stw r30,12364(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12364, ctx.r30.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r29,12372(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12372, ctx.r29.u32);
	// li r10,140
	ctx.r10.s64 = 140;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,12380(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12380, ctx.r11.u32);
	// li r4,140
	ctx.r4.s64 = 140;
	// stw r10,12376(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12376, ctx.r10.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x881607f8
	ctx.lr = 0x8809DC20;
	sub_881607F8(ctx, base);
loc_8809DC20:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809DC28"))) PPC_WEAK_FUNC(sub_8809DC28);
PPC_FUNC_IMPL(__imp__sub_8809DC28) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x8809DC30;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,1620(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1620);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8809dc70
	if (ctx.cr6.eq) goto loc_8809DC70;
	// addi r29,r31,20
	ctx.r29.s64 = ctx.r31.s64 + 20;
	// li r30,16
	ctx.r30.s64 = 16;
loc_8809DC54:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8809db50
	ctx.lr = 0x8809DC60;
	sub_8809DB50(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r29,r29,28
	ctx.r29.s64 = ctx.r29.s64 + 28;
	// bne 0x8809dc54
	if (!ctx.cr0.eq) goto loc_8809DC54;
	// b 0x8809dd00
	goto loc_8809DD00;
loc_8809DC70:
	// lwz r11,508(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 508);
	// lis r9,-30714
	ctx.r9.s64 = -2012872704;
	// lis r6,-30643
	ctx.r6.s64 = -2008219648;
	// lwz r7,504(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 504);
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r5,r9,9552
	ctx.r5.s64 = ctx.r9.s64 + 9552;
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r4,r11,128
	ctx.r4.s64 = ctx.r11.s64 + 128;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r4,2,21,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x7FC;
	// lwz r11,26272(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 26272);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwzx r6,r3,r5
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r5.u32);
	// lwzx r5,r9,r5
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r5.u32);
	// mullw r9,r6,r7
	ctx.r9.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r7.s32);
	// mullw r7,r5,r7
	ctx.r7.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r7.s32);
	// add r4,r9,r10
	ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r10,r7,r8
	ctx.r10.u64 = ctx.r7.u64 + ctx.r8.u64;
	// stw r4,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r4.u32);
	// stw r10,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r10.u32);
	// beq cr6,0x8809dcd0
	if (ctx.cr6.eq) goto loc_8809DCD0;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x8809dce8
	goto loc_8809DCE8;
loc_8809DCD0:
	// lwz r11,524(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 524);
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// addi r8,r11,51
	ctx.r8.s64 = ctx.r11.s64 + 51;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-11984(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -11984);
	// lwzx r11,r7,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r11.u32);
loc_8809DCE8:
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lis r8,-250
	ctx.r8.s64 = -16384000;
	// add r7,r9,r11
	ctx.r7.u64 = ctx.r9.u64 + ctx.r11.u64;
	// cmpw cr6,r10,r8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, ctx.xer);
	// stw r7,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r7.u32);
	// bgt cr6,0x8809dd14
	if (ctx.cr6.gt) goto loc_8809DD14;
loc_8809DD00:
	// lwz r11,528(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 528);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x88094220
	ctx.lr = 0x8809DD14;
	sub_88094220(ctx, base);
loc_8809DD14:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809DD1C"))) PPC_WEAK_FUNC(sub_8809DD1C);
PPC_FUNC_IMPL(__imp__sub_8809DD1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8809DD20"))) PPC_WEAK_FUNC(sub_8809DD20);
PPC_FUNC_IMPL(__imp__sub_8809DD20) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x8809DD28;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30710
	ctx.r11.s64 = -2012610560;
	// li r4,584
	ctx.r4.s64 = 584;
	// addi r5,r11,-8928
	ctx.r5.s64 = ctx.r11.s64 + -8928;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x8809DD40;
	sub_88094290(ctx, base);
	// li r5,584
	ctx.r5.s64 = 584;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,2304(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2304);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x8809DD54;
	sub_88073BD0(ctx, base);
	// stw r30,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// li r4,21
	ctx.r4.s64 = 21;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x881556a0
	ctx.lr = 0x8809DD64;
	sub_881556A0(ctx, base);
	// lis r10,-30710
	ctx.r10.s64 = -2012610560;
	// stw r3,528(r31)
	PPC_STORE_U32(ctx.r31.u32 + 528, ctx.r3.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r9,r10,-10744
	ctx.r9.s64 = ctx.r10.s64 + -10744;
	// stw r31,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r31.u32);
	// li r7,216
	ctx.r7.s64 = 216;
	// stw r9,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r9.u32);
	// addi r11,r31,20
	ctx.r11.s64 = ctx.r31.s64 + 20;
	// lwz r6,528(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 528);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r4,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r4.u32);
	// addi r10,r11,12
	ctx.r10.s64 = ctx.r11.s64 + 12;
	// lwz r5,32(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// li r6,4
	ctx.r6.s64 = 4;
	// stw r7,168(r30)
	PPC_STORE_U32(ctx.r30.u32 + 168, ctx.r7.u32);
	// stw r5,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r5.u32);
	// li r5,63
	ctx.r5.s64 = 63;
	// lwz r3,36(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// lwz r11,100(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 100);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// and r7,r9,r11
	ctx.r7.u64 = ctx.r9.u64 & ctx.r11.u64;
	// stw r7,524(r31)
	PPC_STORE_U32(ctx.r31.u32 + 524, ctx.r7.u32);
loc_8809DDC8:
	// lwz r7,528(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 528);
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// lwz r11,28(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809ddf4
	if (ctx.cr6.eq) goto loc_8809DDF4;
loc_8809DDDC:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8809defc
	if (ctx.cr6.eq) goto loc_8809DEFC;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8809dddc
	if (!ctx.cr6.eq) goto loc_8809DDDC;
loc_8809DDF4:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8809DDF8:
	// stw r10,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r10.u32);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stw r5,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r5.u32);
	// stw r6,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r6.u32);
	// cmpwi cr6,r8,16
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16, ctx.xer);
	// stw r6,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r6.u32);
	// stw r6,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r6.u32);
	// stw r6,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r6.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// addi r10,r10,28
	ctx.r10.s64 = ctx.r10.s64 + 28;
	// blt cr6,0x8809ddc8
	if (ctx.cr6.lt) goto loc_8809DDC8;
	// lwz r11,132(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 132);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addis r9,r10,-250
	ctx.r9.s64 = ctx.r10.s64 + -16384000;
	// lwz r8,2304(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2304);
	// stw r4,560(r31)
	PPC_STORE_U32(ctx.r31.u32 + 560, ctx.r4.u32);
	// stw r9,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r9.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// lwz r7,140(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 140);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x8809de60
	if (ctx.cr6.eq) goto loc_8809DE60;
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,560(r31)
	PPC_STORE_U32(ctx.r31.u32 + 560, ctx.r11.u32);
loc_8809DE60:
	// li r11,16
	ctx.r11.s64 = 16;
	// lis r9,-30710
	ctx.r9.s64 = -2012610560;
	// stw r11,504(r31)
	PPC_STORE_U32(ctx.r31.u32 + 504, ctx.r11.u32);
	// li r10,-40
	ctx.r10.s64 = -40;
	// addi r3,r9,-10672
	ctx.r3.s64 = ctx.r9.s64 + -10672;
	// lwz r26,136(r30)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r30.u32 + 136);
	// li r11,8
	ctx.r11.s64 = 8;
	// stw r26,564(r31)
	PPC_STORE_U32(ctx.r31.u32 + 564, ctx.r26.u32);
	// li r8,20
	ctx.r8.s64 = 20;
	// stw r26,508(r31)
	PPC_STORE_U32(ctx.r31.u32 + 508, ctx.r26.u32);
	// li r7,5
	ctx.r7.s64 = 5;
	// stw r10,568(r31)
	PPC_STORE_U32(ctx.r31.u32 + 568, ctx.r10.u32);
	// li r6,800
	ctx.r6.s64 = 800;
	// stw r8,536(r31)
	PPC_STORE_U32(ctx.r31.u32 + 536, ctx.r8.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r7,544(r31)
	PPC_STORE_U32(ctx.r31.u32 + 544, ctx.r7.u32);
	// lis r9,-30710
	ctx.r9.s64 = -2012610560;
	// stw r6,552(r31)
	PPC_STORE_U32(ctx.r31.u32 + 552, ctx.r6.u32);
	// lis r29,-30710
	ctx.r29.s64 = -2012610560;
	// stw r5,532(r31)
	PPC_STORE_U32(ctx.r31.u32 + 532, ctx.r5.u32);
	// lis r28,-30710
	ctx.r28.s64 = -2012610560;
	// stw r10,572(r31)
	PPC_STORE_U32(ctx.r31.u32 + 572, ctx.r10.u32);
	// stw r4,492(r31)
	PPC_STORE_U32(ctx.r31.u32 + 492, ctx.r4.u32);
	// li r27,-64
	ctx.r27.s64 = -64;
	// stw r4,488(r31)
	PPC_STORE_U32(ctx.r31.u32 + 488, ctx.r4.u32);
	// addi r9,r9,-9176
	ctx.r9.s64 = ctx.r9.s64 + -9176;
	// stw r11,500(r31)
	PPC_STORE_U32(ctx.r31.u32 + 500, ctx.r11.u32);
	// addi r29,r29,-9768
	ctx.r29.s64 = ctx.r29.s64 + -9768;
	// stw r11,496(r31)
	PPC_STORE_U32(ctx.r31.u32 + 496, ctx.r11.u32);
	// addi r28,r28,-10736
	ctx.r28.s64 = ctx.r28.s64 + -10736;
	// stw r3,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r3.u32);
	// lwz r8,564(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 564);
	// stw r27,468(r31)
	PPC_STORE_U32(ctx.r31.u32 + 468, ctx.r27.u32);
	// stw r8,472(r31)
	PPC_STORE_U32(ctx.r31.u32 + 472, ctx.r8.u32);
	// stw r9,64(r30)
	PPC_STORE_U32(ctx.r30.u32 + 64, ctx.r9.u32);
	// stw r29,68(r30)
	PPC_STORE_U32(ctx.r30.u32 + 68, ctx.r29.u32);
	// stw r28,84(r30)
	PPC_STORE_U32(ctx.r30.u32 + 84, ctx.r28.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_8809DEFC:
	// lwz r9,24(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8809df0c
	if (ctx.cr6.eq) goto loc_8809DF0C;
	// stw r9,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r9.u32);
loc_8809DF0C:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x8809ddf8
	goto loc_8809DDF8;
}

__attribute__((alias("__imp__sub_8809DF14"))) PPC_WEAK_FUNC(sub_8809DF14);
PPC_FUNC_IMPL(__imp__sub_8809DF14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8809DF18"))) PPC_WEAK_FUNC(sub_8809DF18);
PPC_FUNC_IMPL(__imp__sub_8809DF18) {
	PPC_FUNC_PROLOGUE();
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8809DF20"))) PPC_WEAK_FUNC(sub_8809DF20);
PPC_FUNC_IMPL(__imp__sub_8809DF20) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r9,96(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 96);
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
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r7,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r7.u32);
	// stw r10,-104(r11)
	PPC_STORE_U32(ctx.r11.u32 + -104, ctx.r10.u32);
	// stwx r9,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + ctx.r11.u32, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8809DF60"))) PPC_WEAK_FUNC(sub_8809DF60);
PPC_FUNC_IMPL(__imp__sub_8809DF60) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x8809DF68;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// li r6,214
	ctx.r6.s64 = 214;
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r28,r11,64
	ctx.r28.s64 = ctx.r11.s64 + 64;
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r25,r28,10750
	ctx.r25.s64 = ctx.r28.s64 + 10750;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x881538c0
	ctx.lr = 0x8809DF90;
	sub_881538C0(ctx, base);
	// lis r27,-30597
	ctx.r27.s64 = -2005204992;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809dfbc
	if (ctx.cr6.eq) goto loc_8809DFBC;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-11932(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
	// oris r9,r10,547
	ctx.r9.u64 = ctx.r10.u64 | 35848192;
	// addi r30,r11,1
	ctx.r30.s64 = ctx.r11.s64 + 1;
	// ori r9,r9,49152
	ctx.r9.u64 = ctx.r9.u64 | 49152;
	// stw r30,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r30.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// b 0x8809dfc0
	goto loc_8809DFC0;
loc_8809DFBC:
	// lwz r30,-11932(r27)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
loc_8809DFC0:
	// addi r26,r28,10878
	ctx.r26.s64 = ctx.r28.s64 + 10878;
	// lwz r29,8(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r28,12(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r6,214
	ctx.r6.s64 = 214;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x881538c0
	ctx.lr = 0x8809DFE0;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809e000
	if (ctx.cr6.eq) goto loc_8809E000;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// oris r10,r11,545
	ctx.r10.u64 = ctx.r11.u64 | 35717120;
	// stw r30,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r30.u32);
	// ori r10,r10,65280
	ctx.r10.u64 = ctx.r10.u64 | 65280;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_8809E000:
	// li r6,218
	ctx.r6.s64 = 218;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x881538c0
	ctx.lr = 0x8809E014;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809e034
	if (ctx.cr6.eq) goto loc_8809E034;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// oris r10,r11,547
	ctx.r10.u64 = ctx.r11.u64 | 35848192;
	// stw r30,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r30.u32);
	// ori r10,r10,32768
	ctx.r10.u64 = ctx.r10.u64 | 32768;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_8809E034:
	// li r6,218
	ctx.r6.s64 = 218;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x881538c0
	ctx.lr = 0x8809E048;
	sub_881538C0(ctx, base);
	// lis r11,545
	ctx.r11.s64 = 35717120;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// ori r31,r11,32768
	ctx.r31.u64 = ctx.r11.u64 | 32768;
	// beq cr6,0x8809e06c
	if (ctx.cr6.eq) goto loc_8809E06C;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// or r10,r11,r31
	ctx.r10.u64 = ctx.r11.u64 | ctx.r31.u64;
	// stw r30,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r30.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_8809E06C:
	// lis r3,0
	ctx.r3.s64 = 0;
	// li r6,218
	ctx.r6.s64 = 218;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// ori r3,r3,45204
	ctx.r3.u64 = ctx.r3.u64 | 45204;
	// bl 0x881538c0
	ctx.lr = 0x8809E084;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809e0ac
	if (ctx.cr6.eq) goto loc_8809E0AC;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,128
	ctx.r9.s64 = 8388608;
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// ori r8,r9,8320
	ctx.r8.u64 = ctx.r9.u64 | 8320;
	// or r7,r10,r31
	ctx.r7.u64 = ctx.r10.u64 | ctx.r31.u64;
	// stw r11,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r11.u32);
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
loc_8809E0AC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809E0B4"))) PPC_WEAK_FUNC(sub_8809E0B4);
PPC_FUNC_IMPL(__imp__sub_8809E0B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8809E0B8"))) PPC_WEAK_FUNC(sub_8809E0B8);
PPC_FUNC_IMPL(__imp__sub_8809E0B8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x8809E0C0;
	__savegprlr_27(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r11,184(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,184(r31)
	PPC_STORE_U32(ctx.r31.u32 + 184, ctx.r11.u32);
	// bge 0x8809e130
	if (!ctx.cr0.lt) goto loc_8809E130;
	// lwz r11,188(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 188);
	// lwz r28,8(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r29,12(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// stw r11,184(r31)
	PPC_STORE_U32(ctx.r31.u32 + 184, ctx.r11.u32);
	// bl 0x88095590
	ctx.lr = 0x8809E0F8;
	sub_88095590(ctx, base);
	// lis r10,64
	ctx.r10.s64 = 4194304;
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// cmpw cr6,r29,r10
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x8809e130
	if (ctx.cr6.lt) goto loc_8809E130;
	// li r11,4
	ctx.r11.s64 = 4;
	// li r10,8
	ctx.r10.s64 = 8;
	// li r9,41
	ctx.r9.s64 = 41;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// li r7,-48
	ctx.r7.s64 = -48;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// li r4,30
	ctx.r4.s64 = 30;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88094690
	ctx.lr = 0x8809E130;
	sub_88094690(ctx, base);
loc_8809E130:
	// lwz r11,116(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8809e1d4
	if (ctx.cr6.eq) goto loc_8809E1D4;
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
	// bge 0x8809e1d4
	if (!ctx.cr0.lt) goto loc_8809E1D4;
	// lwz r11,112(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r28,8(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r27,12(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r10,16
	ctx.r10.s64 = 16;
	// lwz r29,128(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// stw r8,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r8.u32);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// li r9,12
	ctx.r9.s64 = 12;
	// addi r8,r29,192
	ctx.r8.s64 = ctx.r29.s64 + 192;
	// lwz r7,172(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 172);
	// li r4,72
	ctx.r4.s64 = 72;
	// stw r11,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88094430
	ctx.lr = 0x8809E194;
	sub_88094430(ctx, base);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// li r11,-1
	ctx.r11.s64 = -1;
	// lwz r7,172(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 172);
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// li r10,16
	ctx.r10.s64 = 16;
	// li r9,12
	ctx.r9.s64 = 12;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
	// addi r8,r29,-192
	ctx.r8.s64 = ctx.r29.s64 + -192;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// li r4,72
	ctx.r4.s64 = 72;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88094430
	ctx.lr = 0x8809E1C8;
	sub_88094430(ctx, base);
	// lwz r11,116(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// addi r7,r11,-1
	ctx.r7.s64 = ctx.r11.s64 + -1;
	// stw r7,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r7.u32);
loc_8809E1D4:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809E1DC"))) PPC_WEAK_FUNC(sub_8809E1DC);
PPC_FUNC_IMPL(__imp__sub_8809E1DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8809E1E0"))) PPC_WEAK_FUNC(sub_8809E1E0);
PPC_FUNC_IMPL(__imp__sub_8809E1E0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x8809E1E8;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r10,172(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 172);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// blt cr6,0x8809e20c
	if (ctx.cr6.lt) goto loc_8809E20C;
	// lwz r11,188(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 188);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x8809e218
	goto loc_8809E218;
loc_8809E20C:
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 184);
	// lwz r11,168(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 168);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_8809E218:
	// lwz r29,8(r30)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// lis r25,-30667
	ctx.r25.s64 = -2009792512;
	// lwz r28,12(r30)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lis r26,-30667
	ctx.r26.s64 = -2009792512;
	// lis r24,-30667
	ctx.r24.s64 = -2009792512;
	// lwz r31,0(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lis r27,-30667
	ctx.r27.s64 = -2009792512;
	// addi r4,r11,2
	ctx.r4.s64 = ctx.r11.s64 + 2;
	// stw r29,12364(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12364, ctx.r29.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r28,12372(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12372, ctx.r28.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r4,12376(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12376, ctx.r4.u32);
	// stw r11,12380(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12380, ctx.r11.u32);
	// bl 0x880f52c8
	ctx.lr = 0x8809E254;
	sub_880F52C8(ctx, base);
	// lwz r11,1592(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1592);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8809e2b0
	if (!ctx.cr6.eq) goto loc_8809E2B0;
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r8,1588(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1588);
	// lwz r7,1584(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1584);
	// lwz r6,1600(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1600);
	// lwz r5,1596(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1596);
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// bl 0x880f5438
	ctx.lr = 0x8809E27C;
	sub_880F5438(ctx, base);
	// lwz r10,1596(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1596);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8809e2b0
	if (!ctx.cr6.eq) goto loc_8809E2B0;
	// stw r29,12364(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12364, ctx.r29.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r28,12372(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12372, ctx.r28.u32);
	// li r10,140
	ctx.r10.s64 = 140;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,12380(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12380, ctx.r11.u32);
	// li r4,140
	ctx.r4.s64 = 140;
	// stw r10,12376(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12376, ctx.r10.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x881607f8
	ctx.lr = 0x8809E2B0;
	sub_881607F8(ctx, base);
loc_8809E2B0:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809E2B8"))) PPC_WEAK_FUNC(sub_8809E2B8);
PPC_FUNC_IMPL(__imp__sub_8809E2B8) {
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
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,1592(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1592);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8809e304
	if (ctx.cr6.eq) goto loc_8809E304;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8809e1e0
	ctx.lr = 0x8809E2EC;
	sub_8809E1E0(ctx, base);
	// lwz r10,96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r11.u32);
	// bl 0x88094220
	ctx.lr = 0x8809E300;
	sub_88094220(ctx, base);
	// b 0x8809e440
	goto loc_8809E440;
loc_8809E304:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// lis r6,-30643
	ctx.r6.s64 = -2008219648;
	// lwz r7,20(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r5,r10,9552
	ctx.r5.s64 = ctx.r10.s64 + 9552;
	// addi r4,r11,128
	ctx.r4.s64 = ctx.r11.s64 + 128;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// rlwinm r9,r4,2,21,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x7FC;
	// lwz r10,26272(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 26272);
	// lis r6,-30597
	ctx.r6.s64 = -2005204992;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwzx r4,r3,r5
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r5.u32);
	// lwzx r3,r9,r5
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r5.u32);
	// mullw r9,r4,r7
	ctx.r9.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r7.s32);
	// lwz r6,-11984(r6)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + -11984);
	// mullw r7,r3,r7
	ctx.r7.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r7.s32);
	// add r10,r9,r11
	ctx.r10.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r11,r7,r8
	ctx.r11.u64 = ctx.r7.u64 + ctx.r8.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// beq cr6,0x8809e36c
	if (ctx.cr6.eq) goto loc_8809E36C;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x8809e37c
	goto loc_8809E37C;
loc_8809E36C:
	// lwz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// addi r10,r10,51
	ctx.r10.s64 = ctx.r10.s64 + 51;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r9,r6
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r6.u32);
loc_8809E37C:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lis r7,64
	ctx.r7.s64 = 4194304;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add. r9,r11,r7
	ctx.r9.u64 = ctx.r11.u64 + ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// lwz r11,100(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 100);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r8,r11,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// and r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 & ctx.r11.u64;
	// ble 0x8809e3ec
	if (!ctx.cr0.gt) goto loc_8809E3EC;
	// lis r8,128
	ctx.r8.s64 = 8388608;
	// lis r5,320
	ctx.r5.s64 = 20971520;
	// subf r4,r8,r9
	ctx.r4.s64 = ctx.r9.s64 - ctx.r8.s64;
	// cmpw cr6,r4,r5
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r5.s32, ctx.xer);
	// bge cr6,0x8809e3ec
	if (!ctx.cr6.lt) goto loc_8809E3EC;
	// addi r11,r11,55
	ctx.r11.s64 = ctx.r11.s64 + 55;
	// lis r9,-40
	ctx.r9.s64 = -2621440;
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r5,r6
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r6.u32);
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r11,r4,r7
	ctx.r11.u64 = ctx.r4.u64 + ctx.r7.u64;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// ble cr6,0x8809e3ec
	if (!ctx.cr6.gt) goto loc_8809E3EC;
	// lis r10,280
	ctx.r10.s64 = 18350080;
	// subf r9,r8,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r8.s64;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x8809e410
	if (ctx.cr6.lt) goto loc_8809E410;
loc_8809E3EC:
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8809e418
	if (ctx.cr6.eq) goto loc_8809E418;
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x88094220
	ctx.lr = 0x8809E40C;
	sub_88094220(ctx, base);
	// b 0x8809e440
	goto loc_8809E440;
loc_8809E410:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r11.u32);
loc_8809E418:
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// bge 0x8809e440
	if (!ctx.cr0.lt) goto loc_8809E440;
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// clrlwi r8,r9,29
	ctx.r8.u64 = ctx.r9.u32 & 0x7;
	// stw r10,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r10.u32);
	// stw r8,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r8.u32);
loc_8809E440:
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

