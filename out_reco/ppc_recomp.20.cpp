#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_88152BB8"))) PPC_WEAK_FUNC(sub_88152BB8);
PPC_FUNC_IMPL(__imp__sub_88152BB8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30651
	ctx.r11.s64 = -2008743936;
	// lwz r11,-25268(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -25268);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
loc_88152BC8:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// cmplw cr6,r10,r3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r3.u32, ctx.xer);
	// beq cr6,0x88152be4
	if (ctx.cr6.eq) goto loc_88152BE4;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88152bc8
	if (!ctx.cr6.eq) goto loc_88152BC8;
	// blr 
	return;
loc_88152BE4:
	// stw r4,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88152BEC"))) PPC_WEAK_FUNC(sub_88152BEC);
PPC_FUNC_IMPL(__imp__sub_88152BEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88152BF0"))) PPC_WEAK_FUNC(sub_88152BF0);
PPC_FUNC_IMPL(__imp__sub_88152BF0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30651
	ctx.r11.s64 = -2008743936;
	// lwz r11,-25268(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -25268);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
loc_88152C00:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// cmplw cr6,r10,r3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r3.u32, ctx.xer);
	// beq cr6,0x88152c1c
	if (ctx.cr6.eq) goto loc_88152C1C;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88152c00
	if (!ctx.cr6.eq) goto loc_88152C00;
	// blr 
	return;
loc_88152C1C:
	// stw r4,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r4.u32);
	// stw r5,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88152C28"))) PPC_WEAK_FUNC(sub_88152C28);
PPC_FUNC_IMPL(__imp__sub_88152C28) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30651
	ctx.r11.s64 = -2008743936;
	// lwz r11,-25268(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -25268);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
loc_88152C38:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// cmplw cr6,r10,r3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r3.u32, ctx.xer);
	// beq cr6,0x88152c54
	if (ctx.cr6.eq) goto loc_88152C54;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88152c38
	if (!ctx.cr6.eq) goto loc_88152C38;
	// blr 
	return;
loc_88152C54:
	// stw r4,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88152C5C"))) PPC_WEAK_FUNC(sub_88152C5C);
PPC_FUNC_IMPL(__imp__sub_88152C5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88152C60"))) PPC_WEAK_FUNC(sub_88152C60);
PPC_FUNC_IMPL(__imp__sub_88152C60) {
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
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88152ce0
	if (ctx.cr6.eq) goto loc_88152CE0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x88152660
	ctx.lr = 0x88152C80;
	sub_88152660(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88152ca4
	if (ctx.cr6.eq) goto loc_88152CA4;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r10,0
	ctx.r10.s64 = 0;
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
loc_88152CA4:
	// lis r8,-30651
	ctx.r8.s64 = -2008743936;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r11,r8,-24460
	ctx.r11.s64 = ctx.r8.s64 + -24460;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// lwz r11,-24460(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -24460);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,-24460(r8)
	PPC_STORE_U32(ctx.r8.u32 + -24460, ctx.r11.u32);
	// add r11,r10,r9
	ctx.r11.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stwx r6,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r6.u32);
	// stw r7,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r7.u32);
	// stw r5,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r5.u32);
loc_88152CE0:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88152CF0"))) PPC_WEAK_FUNC(sub_88152CF0);
PPC_FUNC_IMPL(__imp__sub_88152CF0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88152CF8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30651
	ctx.r11.s64 = -2008743936;
	// addi r30,r11,-25268
	ctx.r30.s64 = ctx.r11.s64 + -25268;
	// lwz r11,808(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 808);
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88152d2c
	if (ctx.cr6.eq) goto loc_88152D2C;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r4,r30,812
	ctx.r4.s64 = ctx.r30.s64 + 812;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r3,r30,-412
	ctx.r3.s64 = ctx.r30.s64 + -412;
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x88072260
	ctx.lr = 0x88152D2C;
	sub_88072260(ctx, base);
loc_88152D2C:
	// li r28,0
	ctx.r28.s64 = 0;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stw r28,808(r30)
	PPC_STORE_U32(ctx.r30.u32 + 808, ctx.r28.u32);
	// ble cr6,0x88152d68
	if (!ctx.cr6.gt) goto loc_88152D68;
	// addi r31,r30,-412
	ctx.r31.s64 = ctx.r30.s64 + -412;
loc_88152D44:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88152d5c
	if (ctx.cr6.eq) goto loc_88152D5C;
	// stw r28,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x881527b8
	ctx.lr = 0x88152D5C;
	sub_881527B8(ctx, base);
loc_88152D5C:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r31,r31,20
	ctx.r31.s64 = ctx.r31.s64 + 20;
	// bne 0x88152d44
	if (!ctx.cr0.eq) goto loc_88152D44;
loc_88152D68:
	// lwz r29,-12(r30)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r30.u32 + -12);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x88152d9c
	if (ctx.cr6.eq) goto loc_88152D9C;
	// addi r31,r30,-812
	ctx.r31.s64 = ctx.r30.s64 + -812;
loc_88152D78:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88152d90
	if (ctx.cr6.eq) goto loc_88152D90;
	// stw r28,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88152900
	ctx.lr = 0x88152D90;
	sub_88152900(ctx, base);
loc_88152D90:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r31,r31,20
	ctx.r31.s64 = ctx.r31.s64 + 20;
	// bne 0x88152d78
	if (!ctx.cr0.eq) goto loc_88152D78;
loc_88152D9C:
	// lwz r31,0(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stw r28,-12(r30)
	PPC_STORE_U32(ctx.r30.u32 + -12, ctx.r28.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x88152de0
	if (ctx.cr6.eq) goto loc_88152DE0;
loc_88152DB0:
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x88152DC4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x88152dd4
	if (!ctx.cr6.eq) goto loc_88152DD4;
	// stw r28,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r28.u32);
loc_88152DD4:
	// lwz r31,0(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x88152db0
	if (!ctx.cr6.eq) goto loc_88152DB0;
loc_88152DE0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88152DE8"))) PPC_WEAK_FUNC(sub_88152DE8);
PPC_FUNC_IMPL(__imp__sub_88152DE8) {
	PPC_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071144
	ctx.lr = 0x88152DF0;
	__savegprlr_23(ctx, base);
	// cmplwi cr6,r3,128
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 128, ctx.xer);
	// ble cr6,0x88152dfc
	if (!ctx.cr6.gt) goto loc_88152DFC;
	// li r3,128
	ctx.r3.s64 = 128;
loc_88152DFC:
	// subfic r11,r3,128
	ctx.xer.ca = ctx.r3.u32 <= 128;
	ctx.r11.s64 = 128 - ctx.r3.s64;
	// lwz r26,0(r5)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// lwz r24,4(r5)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mullw r29,r3,r3
	ctx.r29.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r3.s32);
	// lwz r31,4(r7)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r30,0(r7)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r28,4(r6)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// lwz r27,0(r6)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r25,0(r4)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r4,4(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// mullw r5,r11,r11
	ctx.r5.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r11.s32);
	// mullw r9,r11,r3
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r3.s32);
	// mullw r10,r5,r3
	ctx.r10.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r3.s32);
	// mullw r9,r9,r3
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r3.s32);
	// rlwinm r7,r10,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// mullw r23,r5,r11
	ctx.r23.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r11.s32);
	// rlwinm r6,r9,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r10,r7
	ctx.r11.u64 = ctx.r10.u64 + ctx.r7.u64;
	// add r10,r9,r6
	ctx.r10.u64 = ctx.r9.u64 + ctx.r6.u64;
	// mullw r3,r29,r3
	ctx.r3.s64 = int64_t(ctx.r29.s32) * int64_t(ctx.r3.s32);
	// mullw r7,r26,r11
	ctx.r7.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r11.s32);
	// mullw r9,r25,r23
	ctx.r9.s64 = int64_t(ctx.r25.s32) * int64_t(ctx.r23.s32);
	// mullw r5,r28,r10
	ctx.r5.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r10.s32);
	// mullw r6,r31,r3
	ctx.r6.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r3.s32);
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// mullw r7,r27,r10
	ctx.r7.s64 = int64_t(ctx.r27.s32) * int64_t(ctx.r10.s32);
	// add r10,r6,r5
	ctx.r10.u64 = ctx.r6.u64 + ctx.r5.u64;
	// mullw r11,r24,r11
	ctx.r11.s64 = int64_t(ctx.r24.s32) * int64_t(ctx.r11.s32);
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// mullw r7,r30,r3
	ctx.r7.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r3.s32);
	// mullw r10,r4,r23
	ctx.r10.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r23.s32);
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r6,r9,11,21,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 11) & 0x7FF;
	// rlwinm r5,r7,11,21,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 11) & 0x7FF;
	// stw r6,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r6.u32);
	// stw r5,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r5.u32);
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88152E98"))) PPC_WEAK_FUNC(sub_88152E98);
PPC_FUNC_IMPL(__imp__sub_88152E98) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lis r9,500
	ctx.r9.s64 = 32768000;
	// lwz r5,8(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r8,4(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// extsw r6,r10
	ctx.r6.s64 = ctx.r10.s32;
	// subf r3,r5,r9
	ctx.r3.s64 = ctx.r9.s64 - ctx.r5.s64;
	// extsw r4,r8
	ctx.r4.s64 = ctx.r8.s32;
	// std r6,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r6.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// extsw r9,r3
	ctx.r9.s64 = ctx.r3.s32;
	// std r4,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r4.u64);
	// lfd f13,-16(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r9.u64);
	// lfd f12,-16(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f10,f0
	ctx.f10.f64 = double(ctx.f0.s64);
	// lis r7,-30714
	ctx.r7.s64 = -2012872704;
	// fcfid f9,f13
	ctx.f9.f64 = double(ctx.f13.s64);
	// addi r10,r7,13168
	ctx.r10.s64 = ctx.r7.s64 + 13168;
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// li r8,4
	ctx.r8.s64 = 4;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfd f0,24(r10)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r10.u32 + 24);
	// lfd f13,16(r10)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r10.u32 + 16);
	// fmul f7,f10,f0
	ctx.f7.f64 = ctx.f10.f64 * ctx.f0.f64;
	// fmul f6,f9,f0
	ctx.f6.f64 = ctx.f9.f64 * ctx.f0.f64;
	// fdiv f8,f13,f11
	ctx.f8.f64 = ctx.f13.f64 / ctx.f11.f64;
	// fmul f5,f7,f8
	ctx.f5.f64 = ctx.f7.f64 * ctx.f8.f64;
	// fmul f4,f6,f8
	ctx.f4.f64 = ctx.f6.f64 * ctx.f8.f64;
	// fctiwz f3,f5
	ctx.f3.s64 = (ctx.f5.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// stfiwx f3,0,r11
	PPC_STORE_U32(ctx.r11.u32, ctx.f3.u32);
	// fctiwz f2,f4
	ctx.f2.s64 = (ctx.f4.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f4.f64));
	// stfiwx f2,r11,r8
	PPC_STORE_U32(ctx.r11.u32 + ctx.r8.u32, ctx.f2.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88152F20"))) PPC_WEAK_FUNC(sub_88152F20);
PPC_FUNC_IMPL(__imp__sub_88152F20) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// li r10,10
	ctx.r10.s64 = 10;
loc_88152F34:
	// divwu. r11,r11,r10
	ctx.r11.u32 = ppc_divwu(ctx.r11.u32, ctx.r10.u32);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// bne 0x88152f34
	if (!ctx.cr0.eq) goto loc_88152F34;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88152F44"))) PPC_WEAK_FUNC(sub_88152F44);
PPC_FUNC_IMPL(__imp__sub_88152F44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88152F48"))) PPC_WEAK_FUNC(sub_88152F48);
PPC_FUNC_IMPL(__imp__sub_88152F48) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// clrlwi r11,r4,23
	ctx.r11.u64 = ctx.r4.u32 & 0x1FF;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// addi r10,r10,9552
	ctx.r10.s64 = ctx.r10.s64 + 9552;
	// beq cr6,0x88152f70
	if (ctx.cr6.eq) goto loc_88152F70;
	// addi r9,r11,128
	ctx.r9.s64 = ctx.r11.s64 + 128;
	// rlwinm r8,r9,2,21,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x7FC;
	// lwzx r7,r8,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// mullw r4,r7,r3
	ctx.r4.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r3.s32);
	// stw r4,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r4.u32);
loc_88152F70:
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// mullw r9,r10,r3
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r3.s32);
	// stw r9,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88152F8C"))) PPC_WEAK_FUNC(sub_88152F8C);
PPC_FUNC_IMPL(__imp__sub_88152F8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88152F90"))) PPC_WEAK_FUNC(sub_88152F90);
PPC_FUNC_IMPL(__imp__sub_88152F90) {
	PPC_FUNC_PROLOGUE();
	// divwu r11,r3,r5
	ctx.r11.u32 = ppc_divwu(ctx.r3.u32, ctx.r5.u32);
	// divwu r10,r4,r5
	ctx.r10.u32 = ppc_divwu(ctx.r4.u32, ctx.r5.u32);
	// mullw r9,r11,r5
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r5.s32);
	// mullw r8,r10,r5
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r5.s32);
	// subf r10,r8,r4
	ctx.r10.s64 = ctx.r4.s64 - ctx.r8.s64;
	// subf r3,r9,r3
	ctx.r3.s64 = ctx.r3.s64 - ctx.r9.s64;
	// subf r7,r10,r3
	ctx.r7.s64 = ctx.r3.s64 - ctx.r10.s64;
	// divwu r6,r7,r5
	ctx.r6.u32 = ppc_divwu(ctx.r7.u32, ctx.r5.u32);
	// mullw r4,r6,r5
	ctx.r4.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r5.s32);
	// subf. r11,r4,r7
	ctx.r11.s64 = ctx.r7.s64 - ctx.r4.s64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x88152fc4
	if (!ctx.cr0.eq) goto loc_88152FC4;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// blr 
	return;
loc_88152FC4:
	// rlwinm r9,r5,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x88152ff0
	if (ctx.cr6.lt) goto loc_88152FF0;
	// subf r11,r11,r5
	ctx.r11.s64 = ctx.r5.s64 - ctx.r11.s64;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// blelr cr6
	if (!ctx.cr6.gt) return;
	// addi r11,r10,-2
	ctx.r11.s64 = ctx.r10.s64 + -2;
	// divwu r10,r11,r5
	ctx.r10.u32 = ppc_divwu(ctx.r11.u32, ctx.r5.u32);
	// mullw r9,r10,r5
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r5.s32);
	// subf r3,r9,r11
	ctx.r3.s64 = ctx.r11.s64 - ctx.r9.s64;
	// blr 
	return;
loc_88152FF0:
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// blelr cr6
	if (!ctx.cr6.gt) return;
	// addi r11,r10,2
	ctx.r11.s64 = ctx.r10.s64 + 2;
	// divwu r10,r11,r5
	ctx.r10.u32 = ppc_divwu(ctx.r11.u32, ctx.r5.u32);
	// mullw r9,r10,r5
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r5.s32);
	// subf r3,r9,r11
	ctx.r3.s64 = ctx.r11.s64 - ctx.r9.s64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8815300C"))) PPC_WEAK_FUNC(sub_8815300C);
PPC_FUNC_IMPL(__imp__sub_8815300C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88153010"))) PPC_WEAK_FUNC(sub_88153010);
PPC_FUNC_IMPL(__imp__sub_88153010) {
	PPC_FUNC_PROLOGUE();
	// clrlwi r9,r3,23
	ctx.r9.u64 = ctx.r3.u32 & 0x1FF;
	// clrlwi r10,r4,23
	ctx.r10.u64 = ctx.r4.u32 & 0x1FF;
	// subf r11,r10,r9
	ctx.r11.s64 = ctx.r9.s64 - ctx.r10.s64;
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88153030
	if (!ctx.cr6.eq) goto loc_88153030;
	// clrlwi r3,r10,16
	ctx.r3.u64 = ctx.r10.u32 & 0xFFFF;
	// blr 
	return;
loc_88153030:
	// cmpwi cr6,r11,256
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 256, ctx.xer);
	// blt cr6,0x88153050
	if (ctx.cr6.lt) goto loc_88153050;
	// subfic r11,r11,512
	ctx.xer.ca = ctx.r11.u32 <= 512;
	ctx.r11.s64 = 512 - ctx.r11.s64;
	// cmplw cr6,r11,r5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r5.u32, ctx.xer);
	// ble cr6,0x88153064
	if (!ctx.cr6.gt) goto loc_88153064;
	// subf r11,r5,r10
	ctx.r11.s64 = ctx.r10.s64 - ctx.r5.s64;
	// clrlwi r3,r11,23
	ctx.r3.u64 = ctx.r11.u32 & 0x1FF;
	// blr 
	return;
loc_88153050:
	// cmplw cr6,r11,r5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r5.u32, ctx.xer);
	// ble cr6,0x88153064
	if (!ctx.cr6.gt) goto loc_88153064;
	// add r11,r10,r5
	ctx.r11.u64 = ctx.r10.u64 + ctx.r5.u64;
	// clrlwi r3,r11,23
	ctx.r3.u64 = ctx.r11.u32 & 0x1FF;
	// blr 
	return;
loc_88153064:
	// clrlwi r3,r9,16
	ctx.r3.u64 = ctx.r9.u32 & 0xFFFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8815306C"))) PPC_WEAK_FUNC(sub_8815306C);
PPC_FUNC_IMPL(__imp__sub_8815306C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88153070"))) PPC_WEAK_FUNC(sub_88153070);
PPC_FUNC_IMPL(__imp__sub_88153070) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// subf r11,r5,r3
	ctx.r11.s64 = ctx.r3.s64 - ctx.r5.s64;
	// subf r9,r6,r4
	ctx.r9.s64 = ctx.r4.s64 - ctx.r6.s64;
	// rlwinm r10,r11,0,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFF0000;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// rlwinm r9,r9,0,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFF0000;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bge cr6,0x88153098
	if (!ctx.cr6.lt) goto loc_88153098;
	// neg r10,r10
	ctx.r10.s64 = -ctx.r10.s64;
	// li r6,-1
	ctx.r6.s64 = -1;
loc_88153098:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge cr6,0x881530a8
	if (!ctx.cr6.lt) goto loc_881530A8;
	// neg r9,r9
	ctx.r9.s64 = -ctx.r9.s64;
	// li r5,-1
	ctx.r5.s64 = -1;
loc_881530A8:
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x881530f8
	if (!ctx.cr6.eq) goto loc_881530F8;
	// cmpwi cr6,r6,1
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 1, ctx.xer);
	// bne cr6,0x881530d8
	if (!ctx.cr6.eq) goto loc_881530D8;
	// cmpwi cr6,r5,1
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 1, ctx.xer);
	// bne cr6,0x881530c8
	if (!ctx.cr6.eq) goto loc_881530C8;
	// li r3,64
	ctx.r3.s64 = 64;
	// blr 
	return;
loc_881530C8:
	// cmpwi cr6,r5,-1
	ctx.cr6.compare<int32_t>(ctx.r5.s32, -1, ctx.xer);
	// bne cr6,0x881530f0
	if (!ctx.cr6.eq) goto loc_881530F0;
	// li r3,192
	ctx.r3.s64 = 192;
	// blr 
	return;
loc_881530D8:
	// cmpwi cr6,r6,-1
	ctx.cr6.compare<int32_t>(ctx.r6.s32, -1, ctx.xer);
	// bne cr6,0x881530f0
	if (!ctx.cr6.eq) goto loc_881530F0;
	// cmpwi cr6,r5,-1
	ctx.cr6.compare<int32_t>(ctx.r5.s32, -1, ctx.xer);
	// bne cr6,0x881530f0
	if (!ctx.cr6.eq) goto loc_881530F0;
	// li r3,320
	ctx.r3.s64 = 320;
	// blr 
	return;
loc_881530F0:
	// li r3,448
	ctx.r3.s64 = 448;
	// blr 
	return;
loc_881530F8:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x88153110
	if (!ctx.cr6.eq) goto loc_88153110;
	// li r11,256
	ctx.r11.s64 = 256;
	// srawi r10,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r5.s32 >> 31;
	// and r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 & ctx.r11.u64;
	// blr 
	return;
loc_88153110:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x88153130
	if (!ctx.cr6.eq) goto loc_88153130;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bge cr6,0x88153128
	if (!ctx.cr6.lt) goto loc_88153128;
	// li r3,384
	ctx.r3.s64 = 384;
	// blr 
	return;
loc_88153128:
	// li r3,128
	ctx.r3.s64 = 128;
	// blr 
	return;
loc_88153130:
	// lis r11,32
	ctx.r11.s64 = 2097152;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bgt cr6,0x881531bc
	if (ctx.cr6.gt) goto loc_881531BC;
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// bgt cr6,0x881531bc
	if (ctx.cr6.gt) goto loc_881531BC;
	// srawi r11,r9,16
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xFFFF) != 0);
	ctx.r11.s64 = ctx.r9.s32 >> 16;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// srawi r9,r10,16
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xFFFF) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 16;
	// rlwinm r10,r11,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xFFFFFFE0;
	// addze r9,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r9.s64 = temp.s64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lis r10,-30671
	ctx.r10.s64 = -2010054656;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addi r9,r10,2888
	ctx.r9.s64 = ctx.r10.s64 + 2888;
	// addi r11,r11,-33
	ctx.r11.s64 = ctx.r11.s64 + -33;
	// ble cr6,0x88153194
	if (!ctx.cr6.gt) goto loc_88153194;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bge cr6,0x8815318c
	if (!ctx.cr6.lt) goto loc_8815318C;
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r9.u32);
	// subfic r7,r8,-256
	ctx.xer.ca = ctx.r8.u32 <= 4294967040;
	ctx.r7.s64 = -256 - ctx.r8.s64;
loc_88153184:
	// clrlwi r3,r7,23
	ctx.r3.u64 = ctx.r7.u32 & 0x1FF;
	// blr 
	return;
loc_8815318C:
	// lbzx r3,r11,r9
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r9.u32);
	// blr 
	return;
loc_88153194:
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bge cr6,0x881531ac
	if (!ctx.cr6.lt) goto loc_881531AC;
	// lbzx r11,r11,r9
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r9.u32);
	// addi r8,r11,-256
	ctx.r8.s64 = ctx.r11.s64 + -256;
	// clrlwi r3,r8,23
	ctx.r3.u64 = ctx.r8.u32 & 0x1FF;
	// blr 
	return;
loc_881531AC:
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r9.u32);
	// neg r7,r8
	ctx.r7.s64 = -ctx.r8.s64;
	// clrlwi r3,r7,23
	ctx.r3.u64 = ctx.r7.u32 & 0x1FF;
	// blr 
	return;
loc_881531BC:
	// lis r8,-30714
	ctx.r8.s64 = -2012872704;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// addi r8,r8,9552
	ctx.r8.s64 = ctx.r8.s64 + 9552;
	// ble cr6,0x8815331c
	if (!ctx.cr6.gt) goto loc_8815331C;
	// li r7,64
	ctx.r7.s64 = 64;
	// li r11,128
	ctx.r11.s64 = 128;
loc_881531D4:
	// addi r4,r11,-128
	ctx.r4.s64 = ctx.r11.s64 + -128;
	// rlwinm r3,r11,2,21,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x7FC;
	// rlwinm r4,r4,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x7FC;
	// lwzx r3,r3,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r8.u32);
	// lwzx r4,r4,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r8.u32);
	// srawi r4,r4,5
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1F) != 0);
	ctx.r4.s64 = ctx.r4.s32 >> 5;
	// srawi r3,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r3.s64 = ctx.r3.s32 >> 5;
	// mullw r4,r4,r10
	ctx.r4.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r10.s32);
	// neg r4,r4
	ctx.r4.s64 = -ctx.r4.s64;
	// mullw r3,r3,r9
	ctx.r3.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r9.s32);
	// cmpw cr6,r4,r3
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r3.s32, ctx.xer);
	// bge cr6,0x88153314
	if (!ctx.cr6.lt) goto loc_88153314;
	// addi r4,r11,-129
	ctx.r4.s64 = ctx.r11.s64 + -129;
	// addi r3,r11,-1
	ctx.r3.s64 = ctx.r11.s64 + -1;
	// rlwinm r4,r4,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x7FC;
	// rlwinm r3,r3,2,21,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x7FC;
	// lwzx r4,r4,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r8.u32);
	// lwzx r3,r3,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r8.u32);
	// srawi r4,r4,5
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1F) != 0);
	ctx.r4.s64 = ctx.r4.s32 >> 5;
	// srawi r3,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r3.s64 = ctx.r3.s32 >> 5;
	// mullw r4,r4,r10
	ctx.r4.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r10.s32);
	// neg r4,r4
	ctx.r4.s64 = -ctx.r4.s64;
	// mullw r3,r3,r9
	ctx.r3.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r9.s32);
	// cmpw cr6,r4,r3
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r3.s32, ctx.xer);
	// bge cr6,0x881532ec
	if (!ctx.cr6.lt) goto loc_881532EC;
	// addi r4,r11,-130
	ctx.r4.s64 = ctx.r11.s64 + -130;
	// addi r3,r11,-2
	ctx.r3.s64 = ctx.r11.s64 + -2;
	// rlwinm r4,r4,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x7FC;
	// rlwinm r3,r3,2,21,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x7FC;
	// lwzx r4,r4,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r8.u32);
	// lwzx r3,r3,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r8.u32);
	// srawi r4,r4,5
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1F) != 0);
	ctx.r4.s64 = ctx.r4.s32 >> 5;
	// srawi r3,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r3.s64 = ctx.r3.s32 >> 5;
	// mullw r4,r4,r10
	ctx.r4.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r10.s32);
	// neg r4,r4
	ctx.r4.s64 = -ctx.r4.s64;
	// mullw r3,r3,r9
	ctx.r3.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r9.s32);
	// cmpw cr6,r4,r3
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r3.s32, ctx.xer);
	// bge cr6,0x881532f8
	if (!ctx.cr6.lt) goto loc_881532F8;
	// addi r4,r11,-131
	ctx.r4.s64 = ctx.r11.s64 + -131;
	// addi r3,r11,-3
	ctx.r3.s64 = ctx.r11.s64 + -3;
	// rlwinm r4,r4,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x7FC;
	// rlwinm r3,r3,2,21,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x7FC;
	// lwzx r4,r4,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r8.u32);
	// lwzx r3,r3,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r8.u32);
	// srawi r4,r4,5
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1F) != 0);
	ctx.r4.s64 = ctx.r4.s32 >> 5;
	// srawi r3,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r3.s64 = ctx.r3.s32 >> 5;
	// mullw r4,r4,r10
	ctx.r4.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r10.s32);
	// neg r4,r4
	ctx.r4.s64 = -ctx.r4.s64;
	// mullw r3,r3,r9
	ctx.r3.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r9.s32);
	// cmpw cr6,r4,r3
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r3.s32, ctx.xer);
	// bge cr6,0x88153304
	if (!ctx.cr6.lt) goto loc_88153304;
	// addi r4,r11,-132
	ctx.r4.s64 = ctx.r11.s64 + -132;
	// addi r3,r11,-4
	ctx.r3.s64 = ctx.r11.s64 + -4;
	// rlwinm r4,r4,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x7FC;
	// rlwinm r3,r3,2,21,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x7FC;
	// lwzx r4,r4,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r8.u32);
	// lwzx r3,r3,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r8.u32);
	// srawi r4,r4,5
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1F) != 0);
	ctx.r4.s64 = ctx.r4.s32 >> 5;
	// srawi r3,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r3.s64 = ctx.r3.s32 >> 5;
	// mullw r4,r4,r10
	ctx.r4.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r10.s32);
	// neg r4,r4
	ctx.r4.s64 = -ctx.r4.s64;
	// mullw r3,r3,r9
	ctx.r3.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r9.s32);
	// cmpw cr6,r4,r3
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r3.s32, ctx.xer);
	// bge cr6,0x88153310
	if (!ctx.cr6.lt) goto loc_88153310;
	// addi r11,r11,-5
	ctx.r11.s64 = ctx.r11.s64 + -5;
	// addi r7,r7,-5
	ctx.r7.s64 = ctx.r7.s64 + -5;
	// cmpwi cr6,r11,64
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 64, ctx.xer);
	// bge cr6,0x881531d4
	if (!ctx.cr6.lt) goto loc_881531D4;
	// addi r7,r7,64
	ctx.r7.s64 = ctx.r7.s64 + 64;
	// b 0x88153414
	goto loc_88153414;
loc_881532EC:
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// addi r7,r7,64
	ctx.r7.s64 = ctx.r7.s64 + 64;
	// b 0x88153414
	goto loc_88153414;
loc_881532F8:
	// addi r7,r7,-2
	ctx.r7.s64 = ctx.r7.s64 + -2;
	// addi r7,r7,64
	ctx.r7.s64 = ctx.r7.s64 + 64;
	// b 0x88153414
	goto loc_88153414;
loc_88153304:
	// addi r7,r7,-3
	ctx.r7.s64 = ctx.r7.s64 + -3;
	// addi r7,r7,64
	ctx.r7.s64 = ctx.r7.s64 + 64;
	// b 0x88153414
	goto loc_88153414;
loc_88153310:
	// addi r7,r7,-4
	ctx.r7.s64 = ctx.r7.s64 + -4;
loc_88153314:
	// addi r7,r7,64
	ctx.r7.s64 = ctx.r7.s64 + 64;
	// b 0x88153414
	goto loc_88153414;
loc_8815331C:
	// li r7,0
	ctx.r7.s64 = 0;
	// li r11,1
	ctx.r11.s64 = 1;
loc_88153324:
	// addi r4,r11,-129
	ctx.r4.s64 = ctx.r11.s64 + -129;
	// rlwinm r3,r7,2,21,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x7FC;
	// rlwinm r4,r4,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x7FC;
	// lwzx r3,r3,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r8.u32);
	// lwzx r4,r4,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r8.u32);
	// srawi r4,r4,5
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1F) != 0);
	ctx.r4.s64 = ctx.r4.s32 >> 5;
	// srawi r3,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r3.s64 = ctx.r3.s32 >> 5;
	// mullw r4,r4,r10
	ctx.r4.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r10.s32);
	// mullw r3,r3,r9
	ctx.r3.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r9.s32);
	// neg r3,r3
	ctx.r3.s64 = -ctx.r3.s64;
	// cmpw cr6,r4,r3
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r3.s32, ctx.xer);
	// bge cr6,0x88153414
	if (!ctx.cr6.lt) goto loc_88153414;
	// addi r4,r11,-128
	ctx.r4.s64 = ctx.r11.s64 + -128;
	// rlwinm r3,r11,2,21,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x7FC;
	// rlwinm r4,r4,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x7FC;
	// lwzx r3,r3,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r8.u32);
	// lwzx r4,r4,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r8.u32);
	// srawi r4,r4,5
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1F) != 0);
	ctx.r4.s64 = ctx.r4.s32 >> 5;
	// srawi r3,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r3.s64 = ctx.r3.s32 >> 5;
	// mullw r4,r4,r10
	ctx.r4.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r10.s32);
	// mullw r3,r3,r9
	ctx.r3.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r9.s32);
	// neg r3,r3
	ctx.r3.s64 = -ctx.r3.s64;
	// cmpw cr6,r4,r3
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r3.s32, ctx.xer);
	// bge cr6,0x88153400
	if (!ctx.cr6.lt) goto loc_88153400;
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// addi r3,r11,-127
	ctx.r3.s64 = ctx.r11.s64 + -127;
	// rlwinm r4,r4,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x7FC;
	// rlwinm r3,r3,2,21,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x7FC;
	// lwzx r4,r4,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r8.u32);
	// lwzx r3,r3,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r8.u32);
	// srawi r4,r4,5
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1F) != 0);
	ctx.r4.s64 = ctx.r4.s32 >> 5;
	// srawi r3,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r3.s64 = ctx.r3.s32 >> 5;
	// mullw r4,r4,r9
	ctx.r4.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r9.s32);
	// neg r4,r4
	ctx.r4.s64 = -ctx.r4.s64;
	// mullw r3,r3,r10
	ctx.r3.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r10.s32);
	// cmpw cr6,r3,r4
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r4.s32, ctx.xer);
	// bge cr6,0x88153408
	if (!ctx.cr6.lt) goto loc_88153408;
	// addi r4,r11,2
	ctx.r4.s64 = ctx.r11.s64 + 2;
	// addi r3,r11,-126
	ctx.r3.s64 = ctx.r11.s64 + -126;
	// rlwinm r4,r4,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x7FC;
	// rlwinm r3,r3,2,21,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x7FC;
	// lwzx r4,r4,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r8.u32);
	// lwzx r3,r3,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r8.u32);
	// srawi r4,r4,5
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1F) != 0);
	ctx.r4.s64 = ctx.r4.s32 >> 5;
	// srawi r3,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r3.s64 = ctx.r3.s32 >> 5;
	// mullw r4,r4,r9
	ctx.r4.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r9.s32);
	// neg r4,r4
	ctx.r4.s64 = -ctx.r4.s64;
	// mullw r3,r3,r10
	ctx.r3.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r10.s32);
	// cmpw cr6,r3,r4
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r4.s32, ctx.xer);
	// bge cr6,0x88153410
	if (!ctx.cr6.lt) goto loc_88153410;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// cmpwi cr6,r11,65
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 65, ctx.xer);
	// blt cr6,0x88153324
	if (ctx.cr6.lt) goto loc_88153324;
	// b 0x88153414
	goto loc_88153414;
loc_88153400:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// b 0x88153414
	goto loc_88153414;
loc_88153408:
	// addi r7,r7,2
	ctx.r7.s64 = ctx.r7.s64 + 2;
	// b 0x88153414
	goto loc_88153414;
loc_88153410:
	// addi r7,r7,3
	ctx.r7.s64 = ctx.r7.s64 + 3;
loc_88153414:
	// cmpwi cr6,r6,1
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 1, ctx.xer);
	// bne cr6,0x88153438
	if (!ctx.cr6.eq) goto loc_88153438;
	// cmpwi cr6,r5,1
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 1, ctx.xer);
	// beq cr6,0x88153184
	if (ctx.cr6.eq) goto loc_88153184;
	// cmpwi cr6,r5,-1
	ctx.cr6.compare<int32_t>(ctx.r5.s32, -1, ctx.xer);
	// bne cr6,0x8815344c
	if (!ctx.cr6.eq) goto loc_8815344C;
	// subfic r11,r7,-256
	ctx.xer.ca = ctx.r7.u32 <= 4294967040;
	ctx.r11.s64 = -256 - ctx.r7.s64;
	// clrlwi r3,r11,23
	ctx.r3.u64 = ctx.r11.u32 & 0x1FF;
	// blr 
	return;
loc_88153438:
	// cmpwi cr6,r6,-1
	ctx.cr6.compare<int32_t>(ctx.r6.s32, -1, ctx.xer);
	// bne cr6,0x8815344c
	if (!ctx.cr6.eq) goto loc_8815344C;
	// cmpwi cr6,r5,-1
	ctx.cr6.compare<int32_t>(ctx.r5.s32, -1, ctx.xer);
	// addi r11,r7,-256
	ctx.r11.s64 = ctx.r7.s64 + -256;
	// beq cr6,0x88153450
	if (ctx.cr6.eq) goto loc_88153450;
loc_8815344C:
	// neg r11,r7
	ctx.r11.s64 = -ctx.r7.s64;
loc_88153450:
	// clrlwi r3,r11,23
	ctx.r3.u64 = ctx.r11.u32 & 0x1FF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88153458"))) PPC_WEAK_FUNC(sub_88153458);
PPC_FUNC_IMPL(__imp__sub_88153458) {
	PPC_FUNC_PROLOGUE();
	// lis r9,-30628
	ctx.r9.s64 = -2007236608;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r8,r9,13264
	ctx.r8.s64 = ctx.r9.s64 + 13264;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// stw r10,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
	// lwz r10,92(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 92);
	// clrlwi r10,r10,28
	ctx.r10.u64 = ctx.r10.u32 & 0xF;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r9,-30671
	ctx.r9.s64 = -2010054656;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r9,4204
	ctx.r7.s64 = ctx.r9.s64 + 4204;
	// lis r6,-30714
	ctx.r6.s64 = -2012872704;
	// addi r5,r6,9552
	ctx.r5.s64 = ctx.r6.s64 + 9552;
	// lwzx r3,r8,r7
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// clrlwi r10,r3,23
	ctx.r10.u64 = ctx.r3.u32 & 0x1FF;
	// rlwinm r9,r3,2,21,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x7FC;
	// addi r8,r10,128
	ctx.r8.s64 = ctx.r10.s64 + 128;
	// rlwinm r7,r8,2,21,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x7FC;
	// lwzx r6,r9,r5
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r5.u32);
	// rlwinm r10,r6,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// lwzx r9,r7,r5
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r5.u32);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// rlwinm r8,r9,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r8,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881534C8"))) PPC_WEAK_FUNC(sub_881534C8);
PPC_FUNC_IMPL(__imp__sub_881534C8) {
	PPC_FUNC_PROLOGUE();
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x881534dc
	if (!ctx.cr6.eq) goto loc_881534DC;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_881534DC:
	// lis r10,-30671
	ctx.r10.s64 = -2010054656;
	// lis r9,16838
	ctx.r9.s64 = 1103495168;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// ori r7,r9,20077
	ctx.r7.u64 = ctx.r9.u64 | 20077;
	// lwz r11,4200(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4200);
	// mullw r11,r11,r7
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r7.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// stw r11,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r11.u32);
	// lhz r6,4200(r10)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// divwu r5,r6,r8
	ctx.r5.u32 = ppc_divwu(ctx.r6.u32, ctx.r8.u32);
	// mullw r4,r5,r8
	ctx.r4.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r8.s32);
	// subf r3,r4,r6
	ctx.r3.s64 = ctx.r6.s64 - ctx.r4.s64;
	// clrlwi r3,r3,16
	ctx.r3.u64 = ctx.r3.u32 & 0xFFFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88153514"))) PPC_WEAK_FUNC(sub_88153514);
PPC_FUNC_IMPL(__imp__sub_88153514) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88153518"))) PPC_WEAK_FUNC(sub_88153518);
PPC_FUNC_IMPL(__imp__sub_88153518) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// lwz r3,4200(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4200);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88153524"))) PPC_WEAK_FUNC(sub_88153524);
PPC_FUNC_IMPL(__imp__sub_88153524) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88153528"))) PPC_WEAK_FUNC(sub_88153528);
PPC_FUNC_IMPL(__imp__sub_88153528) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// stw r3,4200(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4200, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88153534"))) PPC_WEAK_FUNC(sub_88153534);
PPC_FUNC_IMPL(__imp__sub_88153534) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88153538"))) PPC_WEAK_FUNC(sub_88153538);
PPC_FUNC_IMPL(__imp__sub_88153538) {
	PPC_FUNC_PROLOGUE();
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// neg r3,r3
	ctx.r3.s64 = -ctx.r3.s64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88153548"))) PPC_WEAK_FUNC(sub_88153548);
PPC_FUNC_IMPL(__imp__sub_88153548) {
	PPC_FUNC_PROLOGUE();
	// neg r9,r5
	ctx.r9.s64 = -ctx.r5.s64;
	// lwz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lis r7,-30714
	ctx.r7.s64 = -2012872704;
	// lwz r6,4(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// clrlwi r11,r9,23
	ctx.r11.u64 = ctx.r9.u32 & 0x1FF;
	// lwz r4,8(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addi r5,r11,128
	ctx.r5.s64 = ctx.r11.s64 + 128;
	// addi r3,r7,9552
	ctx.r3.s64 = ctx.r7.s64 + 9552;
	// rlwinm r9,r5,2,21,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x7FC;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// extsw r8,r8
	ctx.r8.s64 = ctx.r8.s32;
	// stw r4,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r4.u32);
	// extsw r6,r6
	ctx.r6.s64 = ctx.r6.s32;
	// std r8,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwzx r5,r9,r3
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r3.u32);
	// fcfid f11,f0
	ctx.f11.f64 = double(ctx.f0.s64);
	// lwzx r9,r7,r3
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r3.u32);
	// rlwinm r11,r5,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// std r6,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r6.u64);
	// lfd f13,-16(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// rlwinm r6,r9,4,0,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// extsw r7,r11
	ctx.r7.s64 = ctx.r11.s32;
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// std r7,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r7.u64);
	// lfd f10,-16(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r5,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r5.u64);
	// lfd f9,-16(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f7,f10
	ctx.f7.f64 = double(ctx.f10.s64);
	// lis r4,-30714
	ctx.r4.s64 = -2012872704;
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// addi r8,r4,13168
	ctx.r8.s64 = ctx.r4.s64 + 13168;
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfd f0,64(r8)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r8.u32 + 64);
	// fmul f6,f8,f12
	ctx.f6.f64 = ctx.f8.f64 * ctx.f12.f64;
	// fmul f5,f8,f11
	ctx.f5.f64 = ctx.f8.f64 * ctx.f11.f64;
	// fmsub f4,f7,f11,f6
	ctx.f4.f64 = ctx.f7.f64 * ctx.f11.f64 - ctx.f6.f64;
	// fmadd f3,f12,f7,f5
	ctx.f3.f64 = ctx.f12.f64 * ctx.f7.f64 + ctx.f5.f64;
	// fmul f2,f4,f0
	ctx.f2.f64 = ctx.f4.f64 * ctx.f0.f64;
	// fmul f1,f3,f0
	ctx.f1.f64 = ctx.f3.f64 * ctx.f0.f64;
	// fctiwz f0,f2
	ctx.f0.s64 = (ctx.f2.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f2.f64));
	// stfiwx f0,0,r10
	PPC_STORE_U32(ctx.r10.u32, ctx.f0.u32);
	// fctiwz f13,f1
	ctx.f13.s64 = (ctx.f1.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// stfiwx f13,r10,r4
	PPC_STORE_U32(ctx.r10.u32 + ctx.r4.u32, ctx.f13.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88153608"))) PPC_WEAK_FUNC(sub_88153608);
PPC_FUNC_IMPL(__imp__sub_88153608) {
	PPC_FUNC_PROLOGUE();
	// neg r9,r5
	ctx.r9.s64 = -ctx.r5.s64;
	// lwz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lis r7,-30714
	ctx.r7.s64 = -2012872704;
	// lwz r6,8(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// clrlwi r11,r9,23
	ctx.r11.u64 = ctx.r9.u32 & 0x1FF;
	// lwz r4,4(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addi r5,r11,128
	ctx.r5.s64 = ctx.r11.s64 + 128;
	// addi r3,r7,9552
	ctx.r3.s64 = ctx.r7.s64 + 9552;
	// rlwinm r9,r5,2,21,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x7FC;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// extsw r8,r8
	ctx.r8.s64 = ctx.r8.s32;
	// stw r4,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r4.u32);
	// extsw r6,r6
	ctx.r6.s64 = ctx.r6.s32;
	// std r8,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwzx r5,r9,r3
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r3.u32);
	// fcfid f11,f0
	ctx.f11.f64 = double(ctx.f0.s64);
	// lwzx r9,r7,r3
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r3.u32);
	// rlwinm r11,r5,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// std r6,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r6.u64);
	// lfd f13,-16(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// rlwinm r6,r9,4,0,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// extsw r7,r11
	ctx.r7.s64 = ctx.r11.s32;
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// std r7,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r7.u64);
	// lfd f10,-16(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r5,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r5.u64);
	// lfd f9,-16(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f7,f10
	ctx.f7.f64 = double(ctx.f10.s64);
	// lis r4,-30714
	ctx.r4.s64 = -2012872704;
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// addi r8,r4,13168
	ctx.r8.s64 = ctx.r4.s64 + 13168;
	// li r4,8
	ctx.r4.s64 = 8;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfd f0,64(r8)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r8.u32 + 64);
	// fmul f6,f8,f12
	ctx.f6.f64 = ctx.f8.f64 * ctx.f12.f64;
	// fmul f5,f11,f8
	ctx.f5.f64 = ctx.f11.f64 * ctx.f8.f64;
	// fmadd f4,f7,f11,f6
	ctx.f4.f64 = ctx.f7.f64 * ctx.f11.f64 + ctx.f6.f64;
	// fmsub f3,f7,f12,f5
	ctx.f3.f64 = ctx.f7.f64 * ctx.f12.f64 - ctx.f5.f64;
	// fmul f2,f4,f0
	ctx.f2.f64 = ctx.f4.f64 * ctx.f0.f64;
	// fmul f1,f3,f0
	ctx.f1.f64 = ctx.f3.f64 * ctx.f0.f64;
	// fctiwz f0,f2
	ctx.f0.s64 = (ctx.f2.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f2.f64));
	// stfiwx f0,0,r10
	PPC_STORE_U32(ctx.r10.u32, ctx.f0.u32);
	// fctiwz f13,f1
	ctx.f13.s64 = (ctx.f1.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// stfiwx f13,r10,r4
	PPC_STORE_U32(ctx.r10.u32 + ctx.r4.u32, ctx.f13.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881536C8"))) PPC_WEAK_FUNC(sub_881536C8);
PPC_FUNC_IMPL(__imp__sub_881536C8) {
	PPC_FUNC_PROLOGUE();
	// neg r9,r5
	ctx.r9.s64 = -ctx.r5.s64;
	// lwz r8,4(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lis r7,-30714
	ctx.r7.s64 = -2012872704;
	// lwz r6,8(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// clrlwi r11,r9,23
	ctx.r11.u64 = ctx.r9.u32 & 0x1FF;
	// lwz r4,0(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addi r5,r11,128
	ctx.r5.s64 = ctx.r11.s64 + 128;
	// addi r3,r7,9552
	ctx.r3.s64 = ctx.r7.s64 + 9552;
	// rlwinm r9,r5,2,21,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x7FC;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// extsw r8,r8
	ctx.r8.s64 = ctx.r8.s32;
	// stw r4,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
	// extsw r6,r6
	ctx.r6.s64 = ctx.r6.s32;
	// std r8,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwzx r5,r9,r3
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r3.u32);
	// fcfid f11,f0
	ctx.f11.f64 = double(ctx.f0.s64);
	// lwzx r9,r7,r3
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r3.u32);
	// rlwinm r11,r5,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// std r6,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r6.u64);
	// lfd f13,-16(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// rlwinm r6,r9,4,0,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// extsw r7,r11
	ctx.r7.s64 = ctx.r11.s32;
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// std r7,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r7.u64);
	// lfd f10,-16(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r5,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r5.u64);
	// lfd f9,-16(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f7,f10
	ctx.f7.f64 = double(ctx.f10.s64);
	// lis r4,-30714
	ctx.r4.s64 = -2012872704;
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// addi r8,r4,13168
	ctx.r8.s64 = ctx.r4.s64 + 13168;
	// li r4,4
	ctx.r4.s64 = 4;
	// li r11,8
	ctx.r11.s64 = 8;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfd f0,64(r8)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r8.u32 + 64);
	// fmul f6,f8,f12
	ctx.f6.f64 = ctx.f8.f64 * ctx.f12.f64;
	// fmul f5,f8,f11
	ctx.f5.f64 = ctx.f8.f64 * ctx.f11.f64;
	// fmsub f4,f7,f11,f6
	ctx.f4.f64 = ctx.f7.f64 * ctx.f11.f64 - ctx.f6.f64;
	// fmadd f3,f12,f7,f5
	ctx.f3.f64 = ctx.f12.f64 * ctx.f7.f64 + ctx.f5.f64;
	// fmul f2,f4,f0
	ctx.f2.f64 = ctx.f4.f64 * ctx.f0.f64;
	// fmul f1,f3,f0
	ctx.f1.f64 = ctx.f3.f64 * ctx.f0.f64;
	// fctiwz f0,f2
	ctx.f0.s64 = (ctx.f2.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f2.f64));
	// stfiwx f0,r10,r4
	PPC_STORE_U32(ctx.r10.u32 + ctx.r4.u32, ctx.f0.u32);
	// fctiwz f13,f1
	ctx.f13.s64 = (ctx.f1.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// stfiwx f13,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + ctx.r11.u32, ctx.f13.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8815378C"))) PPC_WEAK_FUNC(sub_8815378C);
PPC_FUNC_IMPL(__imp__sub_8815378C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88153790"))) PPC_WEAK_FUNC(sub_88153790);
PPC_FUNC_IMPL(__imp__sub_88153790) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cmplwi cr6,r3,49589
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 49589, ctx.xer);
	// blt cr6,0x881537b8
	if (ctx.cr6.lt) goto loc_881537B8;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_881537B8:
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r10,-30679
	ctx.r10.s64 = -2010578944;
	// add r9,r3,r11
	ctx.r9.u64 = ctx.r3.u64 + ctx.r11.u64;
	// addi r10,r10,3432
	ctx.r10.s64 = ctx.r10.s64 + 3432;
	// rlwinm r11,r9,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r4,16,16,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r7,r5,16,16,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// lbz r5,3(r11)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r11.u32 + 3);
	// lhz r10,6(r11)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + 6);
	// lbz r9,2(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 2);
	// subfic r8,r5,256
	ctx.xer.ca = ctx.r5.u32 <= 256;
	ctx.r8.s64 = 256 - ctx.r5.s64;
	// lhz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4);
	// subf r6,r10,r8
	ctx.r6.s64 = ctx.r8.s64 - ctx.r10.s64;
	// lhz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r11.u32 + 0);
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// stw r7,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r7.u32);
	// stw r6,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r6.u32);
	// bl 0x88091c98
	ctx.lr = 0x8815381C;
	sub_88091C98(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8815382C"))) PPC_WEAK_FUNC(sub_8815382C);
PPC_FUNC_IMPL(__imp__sub_8815382C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88153830"))) PPC_WEAK_FUNC(sub_88153830);
PPC_FUNC_IMPL(__imp__sub_88153830) {
	PPC_FUNC_PROLOGUE();
	// clrlwi r11,r4,23
	ctx.r11.u64 = ctx.r4.u32 & 0x1FF;
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// addi r9,r11,128
	ctx.r9.s64 = ctx.r11.s64 + 128;
	// addi r10,r10,9552
	ctx.r10.s64 = ctx.r10.s64 + 9552;
	// rlwinm r8,r9,2,21,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x7FC;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// lwzx r7,r8,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// mullw r9,r7,r3
	ctx.r9.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r3.s32);
	// beq cr6,0x88153864
	if (ctx.cr6.eq) goto loc_88153864;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// mullw r8,r10,r3
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r3.s32);
	// stw r8,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r8.u32);
loc_88153864:
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r9,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88153874"))) PPC_WEAK_FUNC(sub_88153874);
PPC_FUNC_IMPL(__imp__sub_88153874) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88153878"))) PPC_WEAK_FUNC(sub_88153878);
PPC_FUNC_IMPL(__imp__sub_88153878) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// subf. r11,r5,r3
	ctx.r11.s64 = ctx.r3.s64 - ctx.r5.s64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// neg r10,r11
	ctx.r10.s64 = -ctx.r11.s64;
	// blt 0x88153888
	if (ctx.cr0.lt) goto loc_88153888;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_88153888:
	// subf. r11,r6,r4
	ctx.r11.s64 = ctx.r4.s64 - ctx.r6.s64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge 0x88153894
	if (!ctx.cr0.lt) goto loc_88153894;
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
loc_88153894:
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x881538ac
	if (!ctx.cr6.lt) goto loc_881538AC;
	// srawi r10,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 1;
	// addze r10,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r10.s64 = temp.s64;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + ctx.r11.u64;
	// blr 
	return;
loc_881538AC:
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881538BC"))) PPC_WEAK_FUNC(sub_881538BC);
PPC_FUNC_IMPL(__imp__sub_881538BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881538C0"))) PPC_WEAK_FUNC(sub_881538C0);
PPC_FUNC_IMPL(__imp__sub_881538C0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cmplwi cr6,r3,49589
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 49589, ctx.xer);
	// blt cr6,0x881538e8
	if (ctx.cr6.lt) goto loc_881538E8;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_881538E8:
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// lis r10,-30679
	ctx.r10.s64 = -2010578944;
	// add r9,r3,r11
	ctx.r9.u64 = ctx.r3.u64 + ctx.r11.u64;
	// addi r11,r10,3432
	ctx.r11.s64 = ctx.r10.s64 + 3432;
	// rlwinm r10,r9,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r4,16,16,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r7,r5,16,16,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// lbz r6,3(r11)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r11.u32 + 3);
	// lhz r5,6(r11)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r11.u32 + 6);
	// lbz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 2);
	// subfic r9,r6,256
	ctx.xer.ca = ctx.r6.u32 <= 256;
	ctx.r9.s64 = 256 - ctx.r6.s64;
	// lhz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4);
	// subf r7,r5,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r5.s64;
	// lhz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r11.u32 + 0);
	// stw r5,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r5.u32);
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// stw r8,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r8.u32);
	// stw r7,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r7.u32);
	// bl 0x88091de8
	ctx.lr = 0x88153948;
	sub_88091DE8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88153978
	if (ctx.cr6.eq) goto loc_88153978;
	// lwz r11,36(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// lwz r10,40(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// rlwinm r8,r11,15,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 15) & 0xFFFF0000;
	// lwz r7,16(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r6,r10,31,1,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// subf r5,r8,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r8.s64;
	// subf r4,r6,r7
	ctx.r4.s64 = ctx.r7.s64 - ctx.r6.s64;
	// stw r5,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r5.u32);
	// stw r4,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r4.u32);
loc_88153978:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88153988"))) PPC_WEAK_FUNC(sub_88153988);
PPC_FUNC_IMPL(__imp__sub_88153988) {
	PPC_FUNC_PROLOGUE();
	// lis r9,-30714
	ctx.r9.s64 = -2012872704;
	// lis r10,-30651
	ctx.r10.s64 = -2008743936;
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r9,r9,11616
	ctx.r9.s64 = ctx.r9.s64 + 11616;
	// addi r10,r10,-26112
	ctx.r10.s64 = ctx.r10.s64 + -26112;
loc_881539A4:
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x881539b4
	if (!ctx.cr6.eq) goto loc_881539B4;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x881539c8
	if (!ctx.cr6.eq) goto loc_881539C8;
loc_881539B4:
	// addi r7,r10,20
	ctx.r7.s64 = ctx.r10.s64 + 20;
	// lbzx r6,r11,r9
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r9.u32);
	// lbzx r5,r11,r7
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r7.u32);
	// cmplw cr6,r5,r6
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r6.u32, ctx.xer);
	// bne cr6,0x881539d8
	if (!ctx.cr6.eq) goto loc_881539D8;
loc_881539C8:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// blt cr6,0x881539a4
	if (ctx.cr6.lt) goto loc_881539A4;
	// blr 
	return;
loc_881539D8:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881539E0"))) PPC_WEAK_FUNC(sub_881539E0);
PPC_FUNC_IMPL(__imp__sub_881539E0) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-30651
	ctx.r10.s64 = -2008743936;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r9,r10,-26112
	ctx.r9.s64 = ctx.r10.s64 + -26112;
	// stb r11,19(r9)
	PPC_STORE_U8(ctx.r9.u32 + 19, ctx.r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881539F4"))) PPC_WEAK_FUNC(sub_881539F4);
PPC_FUNC_IMPL(__imp__sub_881539F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881539F8"))) PPC_WEAK_FUNC(sub_881539F8);
PPC_FUNC_IMPL(__imp__sub_881539F8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// lis r10,-30651
	ctx.r10.s64 = -2008743936;
	// addi r4,r11,26648
	ctx.r4.s64 = ctx.r11.s64 + 26648;
	// addi r3,r10,-26112
	ctx.r3.s64 = ctx.r10.s64 + -26112;
	// lbz r8,12(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 12);
	// lbz r10,9(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 9);
	// lbz r11,10(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 10);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lbz r9,11(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 11);
	// lbz r7,13(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 13);
	// lbz r6,14(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 14);
	// lbz r5,15(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 15);
	// lbz r4,16(r4)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r4.u32 + 16);
	// stb r10,21(r3)
	PPC_STORE_U8(ctx.r3.u32 + 21, ctx.r10.u8);
	// stb r11,22(r3)
	PPC_STORE_U8(ctx.r3.u32 + 22, ctx.r11.u8);
	// stb r9,23(r3)
	PPC_STORE_U8(ctx.r3.u32 + 23, ctx.r9.u8);
	// stb r8,24(r3)
	PPC_STORE_U8(ctx.r3.u32 + 24, ctx.r8.u8);
	// stb r7,26(r3)
	PPC_STORE_U8(ctx.r3.u32 + 26, ctx.r7.u8);
	// stb r6,27(r3)
	PPC_STORE_U8(ctx.r3.u32 + 27, ctx.r6.u8);
	// stb r5,15(r3)
	PPC_STORE_U8(ctx.r3.u32 + 15, ctx.r5.u8);
	// stb r4,19(r3)
	PPC_STORE_U8(ctx.r3.u32 + 19, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88153A50"))) PPC_WEAK_FUNC(sub_88153A50);
PPC_FUNC_IMPL(__imp__sub_88153A50) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30651
	ctx.r11.s64 = -2008743936;
	// addi r11,r11,-26112
	ctx.r11.s64 = ctx.r11.s64 + -26112;
	// lbz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 12);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r8,r9,-14504
	ctx.r8.s64 = ctx.r9.s64 + -14504;
	// stb r10,12(r11)
	PPC_STORE_U8(ctx.r11.u32 + 12, ctx.r10.u8);
	// lhz r11,12(r11)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r11.u32 + 12);
	// sth r11,12(r8)
	PPC_STORE_U16(ctx.r8.u32 + 12, ctx.r11.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88153A80"))) PPC_WEAK_FUNC(sub_88153A80);
PPC_FUNC_IMPL(__imp__sub_88153A80) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30651
	ctx.r11.s64 = -2008743936;
	// addi r10,r11,-26112
	ctx.r10.s64 = ctx.r11.s64 + -26112;
	// lbz r3,12(r10)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r10.u32 + 12);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88153A90"))) PPC_WEAK_FUNC(sub_88153A90);
PPC_FUNC_IMPL(__imp__sub_88153A90) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30651
	ctx.r11.s64 = -2008743936;
	// addi r10,r11,-26112
	ctx.r10.s64 = ctx.r11.s64 + -26112;
	// stb r3,10(r10)
	PPC_STORE_U8(ctx.r10.u32 + 10, ctx.r3.u8);
	// stb r4,11(r10)
	PPC_STORE_U8(ctx.r10.u32 + 11, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88153AA4"))) PPC_WEAK_FUNC(sub_88153AA4);
PPC_FUNC_IMPL(__imp__sub_88153AA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88153AA8"))) PPC_WEAK_FUNC(sub_88153AA8);
PPC_FUNC_IMPL(__imp__sub_88153AA8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30651
	ctx.r11.s64 = -2008743936;
	// lis r9,-30641
	ctx.r9.s64 = -2008088576;
	// addi r8,r11,-26112
	ctx.r8.s64 = ctx.r11.s64 + -26112;
	// lbz r11,10(r8)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r8.u32 + 10);
	// lbz r10,11(r8)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r8.u32 + 11);
	// stb r11,-18732(r9)
	PPC_STORE_U8(ctx.r9.u32 + -18732, ctx.r11.u8);
	// stb r10,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88153AC8"))) PPC_WEAK_FUNC(sub_88153AC8);
PPC_FUNC_IMPL(__imp__sub_88153AC8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30651
	ctx.r11.s64 = -2008743936;
	// addi r11,r11,-26112
	ctx.r11.s64 = ctx.r11.s64 + -26112;
	// addi r10,r11,20
	ctx.r10.s64 = ctx.r11.s64 + 20;
	// stbx r4,r3,r10
	PPC_STORE_U8(ctx.r3.u32 + ctx.r10.u32, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88153ADC"))) PPC_WEAK_FUNC(sub_88153ADC);
PPC_FUNC_IMPL(__imp__sub_88153ADC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88153AE0"))) PPC_WEAK_FUNC(sub_88153AE0);
PPC_FUNC_IMPL(__imp__sub_88153AE0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30651
	ctx.r11.s64 = -2008743936;
	// addi r11,r11,-26112
	ctx.r11.s64 = ctx.r11.s64 + -26112;
	// addi r10,r11,13
	ctx.r10.s64 = ctx.r11.s64 + 13;
	// stbx r4,r3,r10
	PPC_STORE_U8(ctx.r3.u32 + ctx.r10.u32, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88153AF4"))) PPC_WEAK_FUNC(sub_88153AF4);
PPC_FUNC_IMPL(__imp__sub_88153AF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88153AF8"))) PPC_WEAK_FUNC(sub_88153AF8);
PPC_FUNC_IMPL(__imp__sub_88153AF8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30651
	ctx.r11.s64 = -2008743936;
	// addi r11,r11,-26112
	ctx.r11.s64 = ctx.r11.s64 + -26112;
	// addi r10,r11,20
	ctx.r10.s64 = ctx.r11.s64 + 20;
	// lbzx r3,r10,r3
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88153B0C"))) PPC_WEAK_FUNC(sub_88153B0C);
PPC_FUNC_IMPL(__imp__sub_88153B0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88153B10"))) PPC_WEAK_FUNC(sub_88153B10);
PPC_FUNC_IMPL(__imp__sub_88153B10) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30651
	ctx.r11.s64 = -2008743936;
	// addi r11,r11,-26112
	ctx.r11.s64 = ctx.r11.s64 + -26112;
	// addi r10,r11,13
	ctx.r10.s64 = ctx.r11.s64 + 13;
	// lbzx r3,r10,r3
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88153B24"))) PPC_WEAK_FUNC(sub_88153B24);
PPC_FUNC_IMPL(__imp__sub_88153B24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88153B28"))) PPC_WEAK_FUNC(sub_88153B28);
PPC_FUNC_IMPL(__imp__sub_88153B28) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lis r10,-30642
	ctx.r10.s64 = -2008154112;
	// addi r11,r11,-14504
	ctx.r11.s64 = ctx.r11.s64 + -14504;
	// addi r4,r10,31504
	ctx.r4.s64 = ctx.r10.s64 + 31504;
	// li r5,480
	ctx.r5.s64 = 480;
	// addi r3,r11,28
	ctx.r3.s64 = ctx.r11.s64 + 28;
	// b 0x880726e8
	sub_880726E8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88153B44"))) PPC_WEAK_FUNC(sub_88153B44);
PPC_FUNC_IMPL(__imp__sub_88153B44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88153B48"))) PPC_WEAK_FUNC(sub_88153B48);
PPC_FUNC_IMPL(__imp__sub_88153B48) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r10,r4,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r11,r5,31,17,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 31) & 0x7FFF;
	// addi r9,r10,14
	ctx.r9.s64 = ctx.r10.s64 + 14;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// rlwinm r9,r9,1,23,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1FE;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lis r8,-30597
	ctx.r8.s64 = -2005204992;
	// subf r9,r3,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r3.s64;
	// addi r11,r8,-14504
	ctx.r11.s64 = ctx.r8.s64 + -14504;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
loc_88153B7C:
	// lhz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// sthx r9,r11,r10
	PPC_STORE_U16(ctx.r11.u32 + ctx.r10.u32, ctx.r9.u16);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// bdnz 0x88153b7c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88153B7C;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88153B90"))) PPC_WEAK_FUNC(sub_88153B90);
PPC_FUNC_IMPL(__imp__sub_88153B90) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lis r10,-30642
	ctx.r10.s64 = -2008154112;
	// addi r11,r11,-14504
	ctx.r11.s64 = ctx.r11.s64 + -14504;
	// addi r3,r10,31504
	ctx.r3.s64 = ctx.r10.s64 + 31504;
	// li r5,480
	ctx.r5.s64 = 480;
	// addi r4,r11,28
	ctx.r4.s64 = ctx.r11.s64 + 28;
	// b 0x880726e8
	sub_880726E8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88153BAC"))) PPC_WEAK_FUNC(sub_88153BAC);
PPC_FUNC_IMPL(__imp__sub_88153BAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88153BB0"))) PPC_WEAK_FUNC(sub_88153BB0);
PPC_FUNC_IMPL(__imp__sub_88153BB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// addi r10,r11,4256
	ctx.r10.s64 = ctx.r11.s64 + 4256;
	// addi r8,r9,-14504
	ctx.r8.s64 = ctx.r9.s64 + -14504;
	// lwz r11,4256(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4256);
	// lwz r9,-4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// lwz r7,560(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 560);
	// add r6,r11,r9
	ctx.r6.u64 = ctx.r11.u64 + ctx.r9.u64;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// bne cr6,0x88153c1c
	if (!ctx.cr6.eq) goto loc_88153C1C;
	// lis r11,-30651
	ctx.r11.s64 = -2008743936;
	// srawi r7,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 1;
	// addi r11,r11,-26112
	ctx.r11.s64 = ctx.r11.s64 + -26112;
	// addze r6,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r6.s64 = temp.s64;
	// add r7,r9,r11
	ctx.r7.u64 = ctx.r9.u64 + ctx.r11.u64;
	// rlwinm r6,r6,1,23,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0x1FE;
	// addi r11,r9,2
	ctx.r11.s64 = ctx.r9.s64 + 2;
	// stw r11,-4(r10)
	PPC_STORE_U32(ctx.r10.u32 + -4, ctx.r11.u32);
	// cmplwi cr6,r11,28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 28, ctx.xer);
	// lhz r5,0(r7)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r7.u32 + 0);
	// sthx r5,r6,r8
	PPC_STORE_U16(ctx.r6.u32 + ctx.r8.u32, ctx.r5.u16);
	// blt cr6,0x88153c5c
	if (ctx.cr6.lt) goto loc_88153C5C;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,560(r8)
	PPC_STORE_U32(ctx.r8.u32 + 560, ctx.r11.u32);
	// blr 
	return;
loc_88153C1C:
	// cmpwi cr6,r7,1
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 1, ctx.xer);
	// bne cr6,0x88153c5c
	if (!ctx.cr6.eq) goto loc_88153C5C;
	// srawi r9,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 1;
	// lis r7,-30642
	ctx.r7.s64 = -2008154112;
	// addze r9,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r9.s64 = temp.s64;
	// addi r7,r7,31504
	ctx.r7.s64 = ctx.r7.s64 + 31504;
	// addi r6,r9,14
	ctx.r6.s64 = ctx.r9.s64 + 14;
	// add r9,r11,r7
	ctx.r9.u64 = ctx.r11.u64 + ctx.r7.u64;
	// rlwinm r7,r6,1,23,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0x1FE;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// cmplwi cr6,r11,480
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 480, ctx.xer);
	// lhz r5,0(r9)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r9.u32 + 0);
	// sthx r5,r7,r8
	PPC_STORE_U16(ctx.r7.u32 + ctx.r8.u32, ctx.r5.u16);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
loc_88153C5C:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88153C64"))) PPC_WEAK_FUNC(sub_88153C64);
PPC_FUNC_IMPL(__imp__sub_88153C64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88153C68"))) PPC_WEAK_FUNC(sub_88153C68);
PPC_FUNC_IMPL(__imp__sub_88153C68) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// lis r10,-30651
	ctx.r10.s64 = -2008743936;
	// addi r11,r11,11616
	ctx.r11.s64 = ctx.r11.s64 + 11616;
	// li r7,7
	ctx.r7.s64 = 7;
	// addi r9,r11,-8
	ctx.r9.s64 = ctx.r11.s64 + -8;
	// addi r10,r10,-26112
	ctx.r10.s64 = ctx.r10.s64 + -26112;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// addi r8,r10,12
	ctx.r8.s64 = ctx.r10.s64 + 12;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_88153C8C:
	// lbzu r7,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r7.u64 = PPC_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// stbu r7,1(r8)
	ea = 1 + ctx.r8.u32;
	PPC_STORE_U8(ea, ctx.r7.u8);
	ctx.r8.u32 = ea;
	// bdnz 0x88153c8c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88153C8C;
	// li r9,8
	ctx.r9.s64 = 8;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r10,r10,19
	ctx.r10.s64 = ctx.r10.s64 + 19;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_88153CA8:
	// lbzu r9,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r9.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// stbu r9,1(r10)
	ea = 1 + ctx.r10.u32;
	PPC_STORE_U8(ea, ctx.r9.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x88153ca8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88153CA8;
	// b 0x880f1178
	sub_880F1178(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88153CB8"))) PPC_WEAK_FUNC(sub_88153CB8);
PPC_FUNC_IMPL(__imp__sub_88153CB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// addi r11,r11,-14504
	ctx.r11.s64 = ctx.r11.s64 + -14504;
	// lhz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4);
	// lhz r8,6(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 6);
	// sth r9,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r9.u16);
	// sth r8,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, ctx.r8.u16);
	// lwz r7,-16(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// addi r11,r7,-28
	ctx.r11.s64 = ctx.r7.s64 + -28;
	// addic r6,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r6.s64 = ctx.r11.s64 + -1;
	// subfe r3,r6,r11
	temp.u8 = (~ctx.r6.u32 + ctx.r11.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ~ctx.r6.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88153CE8"))) PPC_WEAK_FUNC(sub_88153CE8);
PPC_FUNC_IMPL(__imp__sub_88153CE8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-30651
	ctx.r11.s64 = -2008743936;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// li r9,14
	ctx.r9.s64 = 14;
	// addi r11,r11,-26112
	ctx.r11.s64 = ctx.r11.s64 + -26112;
	// addi r10,r10,-14504
	ctx.r10.s64 = ctx.r10.s64 + -14504;
	// addi r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -2;
	// addi r10,r10,-2
	ctx.r10.s64 = ctx.r10.s64 + -2;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_88153D08:
	// lhzu r9,2(r11)
	ea = 2 + ctx.r11.u32;
	ctx.r9.u64 = PPC_LOAD_U16(ea);
	ctx.r11.u32 = ea;
	// sthu r9,2(r10)
	ea = 2 + ctx.r10.u32;
	PPC_STORE_U16(ea, ctx.r9.u16);
	ctx.r10.u32 = ea;
	// bdnz 0x88153d08
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88153D08;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88153D18"))) PPC_WEAK_FUNC(sub_88153D18);
PPC_FUNC_IMPL(__imp__sub_88153D18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// addi r10,r11,4256
	ctx.r10.s64 = ctx.r11.s64 + 4256;
	// addi r8,r9,-14504
	ctx.r8.s64 = ctx.r9.s64 + -14504;
	// lwz r11,4256(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4256);
	// lwz r9,-4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// lwz r7,560(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 560);
	// add r6,r11,r9
	ctx.r6.u64 = ctx.r11.u64 + ctx.r9.u64;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// bne cr6,0x88153d84
	if (!ctx.cr6.eq) goto loc_88153D84;
	// srawi r11,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r9.s32 >> 1;
	// lis r7,-30651
	ctx.r7.s64 = -2008743936;
	// addze r6,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r6.s64 = temp.s64;
	// addi r11,r7,-26112
	ctx.r11.s64 = ctx.r7.s64 + -26112;
	// rlwinm r6,r6,1,23,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0x1FE;
	// add r7,r9,r11
	ctx.r7.u64 = ctx.r9.u64 + ctx.r11.u64;
	// addi r11,r9,2
	ctx.r11.s64 = ctx.r9.s64 + 2;
	// stw r11,-4(r10)
	PPC_STORE_U32(ctx.r10.u32 + -4, ctx.r11.u32);
	// cmplwi cr6,r11,28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 28, ctx.xer);
	// lhzx r5,r6,r8
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r6.u32 + ctx.r8.u32);
	// sth r5,0(r7)
	PPC_STORE_U16(ctx.r7.u32 + 0, ctx.r5.u16);
	// blt cr6,0x88153dc4
	if (ctx.cr6.lt) goto loc_88153DC4;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,560(r8)
	PPC_STORE_U32(ctx.r8.u32 + 560, ctx.r11.u32);
	// blr 
	return;
loc_88153D84:
	// cmpwi cr6,r7,1
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 1, ctx.xer);
	// bne cr6,0x88153dc4
	if (!ctx.cr6.eq) goto loc_88153DC4;
	// srawi r9,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 1;
	// lis r7,-30642
	ctx.r7.s64 = -2008154112;
	// addze r9,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r9.s64 = temp.s64;
	// addi r7,r7,31504
	ctx.r7.s64 = ctx.r7.s64 + 31504;
	// addi r6,r9,14
	ctx.r6.s64 = ctx.r9.s64 + 14;
	// add r9,r11,r7
	ctx.r9.u64 = ctx.r11.u64 + ctx.r7.u64;
	// rlwinm r7,r6,1,23,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0x1FE;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// cmplwi cr6,r11,480
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 480, ctx.xer);
	// lhzx r5,r7,r8
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r7.u32 + ctx.r8.u32);
	// sth r5,0(r9)
	PPC_STORE_U16(ctx.r9.u32 + 0, ctx.r5.u16);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
loc_88153DC4:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88153DCC"))) PPC_WEAK_FUNC(sub_88153DCC);
PPC_FUNC_IMPL(__imp__sub_88153DCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88153DD0"))) PPC_WEAK_FUNC(sub_88153DD0);
PPC_FUNC_IMPL(__imp__sub_88153DD0) {
	PPC_FUNC_PROLOGUE();
	// lis r8,-30671
	ctx.r8.s64 = -2010054656;
	// lis r7,-30597
	ctx.r7.s64 = -2005204992;
	// addi r6,r8,4256
	ctx.r6.s64 = ctx.r8.s64 + 4256;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,4256(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4256, ctx.r10.u32);
	// stw r11,-4(r6)
	PPC_STORE_U32(ctx.r6.u32 + -4, ctx.r11.u32);
	// stw r9,-13944(r7)
	PPC_STORE_U32(ctx.r7.u32 + -13944, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88153DF8"))) PPC_WEAK_FUNC(sub_88153DF8);
PPC_FUNC_IMPL(__imp__sub_88153DF8) {
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
	// lis r11,-30651
	ctx.r11.s64 = -2008743936;
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r31,r11,-26112
	ctx.r31.s64 = ctx.r11.s64 + -26112;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r31,-4
	ctx.r11.s64 = ctx.r31.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_88153E20:
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x88153e20
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88153E20;
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r11,r11,11616
	ctx.r11.s64 = ctx.r11.s64 + 11616;
	// li r9,28
	ctx.r9.s64 = 28;
	// addi r8,r11,-8
	ctx.r8.s64 = ctx.r11.s64 + -8;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// lbz r5,-16(r11)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r11.u32 + -16);
	// addi r7,r31,12
	ctx.r7.s64 = ctx.r31.s64 + 12;
	// lbz r4,-15(r11)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r11.u32 + -15);
	// lbz r3,-14(r11)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r11.u32 + -14);
	// lbz r10,-13(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + -13);
	// stb r5,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r5.u8);
	// stb r4,1(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1, ctx.r4.u8);
	// stb r3,2(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2, ctx.r3.u8);
	// stb r10,3(r31)
	PPC_STORE_U8(ctx.r31.u32 + 3, ctx.r10.u8);
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
loc_88153E70:
	// lbzu r10,1(r8)
	ea = 1 + ctx.r8.u32;
	ctx.r10.u64 = PPC_LOAD_U8(ea);
	ctx.r8.u32 = ea;
	// stbu r10,1(r7)
	ea = 1 + ctx.r7.u32;
	PPC_STORE_U8(ea, ctx.r10.u8);
	ctx.r7.u32 = ea;
	// bdnz 0x88153e70
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88153E70;
	// li r9,8
	ctx.r9.s64 = 8;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r10,r31,19
	ctx.r10.s64 = ctx.r31.s64 + 19;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_88153E8C:
	// lbzu r9,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r9.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// stbu r9,1(r10)
	ea = 1 + ctx.r10.u32;
	PPC_STORE_U8(ea, ctx.r9.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x88153e8c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88153E8C;
	// bl 0x880f1178
	ctx.lr = 0x88153E9C;
	sub_880F1178(ctx, base);
	// bl 0x880f1448
	ctx.lr = 0x88153EA0;
	sub_880F1448(ctx, base);
	// lis r7,-30671
	ctx.r7.s64 = -2010054656;
	// lis r6,-30597
	ctx.r6.s64 = -2005204992;
	// addi r5,r7,4256
	ctx.r5.s64 = ctx.r7.s64 + 4256;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r10,4256(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4256, ctx.r10.u32);
	// stw r11,-4(r5)
	PPC_STORE_U32(ctx.r5.u32 + -4, ctx.r11.u32);
	// stw r9,-13944(r6)
	PPC_STORE_U32(ctx.r6.u32 + -13944, ctx.r9.u32);
	// stb r8,12(r31)
	PPC_STORE_U8(ctx.r31.u32 + 12, ctx.r8.u8);
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

__attribute__((alias("__imp__sub_88153EE0"))) PPC_WEAK_FUNC(sub_88153EE0);
PPC_FUNC_IMPL(__imp__sub_88153EE0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071144
	ctx.lr = 0x88153EE8;
	__savegprlr_23(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// rlwinm r11,r3,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r10,-30658
	ctx.r10.s64 = -2009202688;
	// add r9,r3,r11
	ctx.r9.u64 = ctx.r3.u64 + ctx.r11.u64;
	// addi r11,r10,208
	ctx.r11.s64 = ctx.r10.s64 + 208;
	// mr r25,r7
	ctx.r25.u64 = ctx.r7.u64;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r11,4
	ctx.r7.s64 = ctx.r11.s64 + 4;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r23,r6
	ctx.r23.u64 = ctx.r6.u64;
	// addi r26,r5,24
	ctx.r26.s64 = ctx.r5.s64 + 24;
	// lwzx r28,r8,r7
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x881540d4
	if (ctx.cr6.eq) goto loc_881540D4;
	// li r31,0
	ctx.r31.s64 = 0;
	// li r24,1024
	ctx.r24.s64 = 1024;
loc_88153F2C:
	// lwz r11,8(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x881540c8
	if (ctx.cr6.eq) goto loc_881540C8;
	// cmpw cr6,r23,r28
	ctx.cr6.compare<int32_t>(ctx.r23.s32, ctx.r28.s32, ctx.xer);
	// beq cr6,0x881540c8
	if (ctx.cr6.eq) goto loc_881540C8;
	// lwz r30,28(r28)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r28.u32 + 28);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x881540c8
	if (ctx.cr6.eq) goto loc_881540C8;
loc_88153F4C:
	// lwz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x881540c8
	if (ctx.cr6.eq) goto loc_881540C8;
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x881540bc
	if (ctx.cr6.eq) goto loc_881540BC;
	// lwz r11,24(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// addi r4,r30,24
	ctx.r4.s64 = ctx.r30.s64 + 24;
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x881540bc
	if (!ctx.cr6.eq) goto loc_881540BC;
	// lhz r11,28(r4)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 28);
	// lhz r9,32(r4)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r4.u32 + 32);
	// lwz r8,36(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 36);
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// extsh r11,r9
	ctx.r11.s64 = ctx.r9.s16;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x88153fb0
	if (ctx.cr6.eq) goto loc_88153FB0;
	// rotlwi r9,r8,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// lhz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 0);
	// lhz r7,4(r9)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// extsh r9,r8
	ctx.r9.s64 = ctx.r8.s16;
	// extsh r8,r7
	ctx.r8.s64 = ctx.r7.s16;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
loc_88153FB0:
	// lwz r9,16(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// lwz r8,12(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// add r7,r9,r11
	ctx.r7.u64 = ctx.r9.u64 + ctx.r11.u64;
	// cmpw cr6,r7,r8
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x881540bc
	if (ctx.cr6.lt) goto loc_881540BC;
	// lwz r9,12(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x881540bc
	if (ctx.cr6.eq) goto loc_881540BC;
	// lwz r9,20(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// lwz r8,8(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 8);
	// subf r7,r9,r11
	ctx.r7.s64 = ctx.r11.s64 - ctx.r9.s64;
	// cmpw cr6,r7,r8
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, ctx.xer);
	// bgt cr6,0x881540bc
	if (ctx.cr6.gt) goto loc_881540BC;
	// lwz r11,12(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// subf r8,r11,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r11.s64;
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// bgt cr6,0x881540bc
	if (ctx.cr6.gt) goto loc_881540BC;
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r9,4(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x881540bc
	if (ctx.cr6.lt) goto loc_881540BC;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// extsh r9,r25
	ctx.r9.s64 = ctx.r25.s16;
	// std r31,0(r11)
	PPC_STORE_U64(ctx.r11.u32 + 0, ctx.r31.u64);
	// std r31,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r31.u64);
	// std r31,8(r11)
	PPC_STORE_U64(ctx.r11.u32 + 8, ctx.r31.u64);
	// std r31,8(r10)
	PPC_STORE_U64(ctx.r10.u32 + 8, ctx.r31.u64);
	// std r31,16(r11)
	PPC_STORE_U64(ctx.r11.u32 + 16, ctx.r31.u64);
	// std r31,16(r10)
	PPC_STORE_U64(ctx.r10.u32 + 16, ctx.r31.u64);
	// std r31,24(r11)
	PPC_STORE_U64(ctx.r11.u32 + 24, ctx.r31.u64);
	// std r31,24(r10)
	PPC_STORE_U64(ctx.r10.u32 + 24, ctx.r31.u64);
	// lwz r8,20(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// ori r7,r8,1024
	ctx.r7.u64 = ctx.r8.u64 | 1024;
	// stw r7,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r7.u32);
	// lwz r6,20(r29)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// or r5,r9,r6
	ctx.r5.u64 = ctx.r9.u64 | ctx.r6.u64;
	// stw r5,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r5.u32);
	// lwz r3,24(r26)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r26.u32 + 24);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// lwz r11,24(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r11.u32);
	// stw r24,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r24.u32);
	// stw r9,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r9.u32);
	// lwz r11,32(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88154090
	if (ctx.cr6.eq) goto loc_88154090;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r5,36(r28)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r28.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x88154084;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88154090
	if (!ctx.cr6.eq) goto loc_88154090;
	// stw r31,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r31.u32);
loc_88154090:
	// lwz r11,32(r23)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + 32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x881540bc
	if (ctx.cr6.eq) goto loc_881540BC;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// lwz r5,36(r23)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r23.u32 + 36);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x881540B0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x881540bc
	if (!ctx.cr6.eq) goto loc_881540BC;
	// stw r31,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r31.u32);
loc_881540BC:
	// lwz r30,0(r30)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x88153f4c
	if (!ctx.cr6.eq) goto loc_88153F4C;
loc_881540C8:
	// lwz r28,0(r28)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x88153f2c
	if (!ctx.cr6.eq) goto loc_88153F2C;
loc_881540D4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_881540E0"))) PPC_WEAK_FUNC(sub_881540E0);
PPC_FUNC_IMPL(__imp__sub_881540E0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807113c
	ctx.lr = 0x881540E8;
	__savegprlr_21(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// addi r10,r11,208
	ctx.r10.s64 = ctx.r11.s64 + 208;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r22,r5
	ctx.r22.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r26,r7
	ctx.r26.u64 = ctx.r7.u64;
	// lwz r28,244(r10)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r10.u32 + 244);
	// addi r21,r4,24
	ctx.r21.s64 = ctx.r4.s64 + 24;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8815428c
	if (ctx.cr6.eq) goto loc_8815428C;
	// li r31,0
	ctx.r31.s64 = 0;
	// li r24,1024
	ctx.r24.s64 = 1024;
	// li r25,16
	ctx.r25.s64 = 16;
loc_88154124:
	// lwz r11,8(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88154280
	if (ctx.cr6.eq) goto loc_88154280;
	// lwz r30,28(r28)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r28.u32 + 28);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x88154280
	if (ctx.cr6.eq) goto loc_88154280;
loc_8815413C:
	// lwz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88154280
	if (ctx.cr6.eq) goto loc_88154280;
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88154274
	if (ctx.cr6.eq) goto loc_88154274;
	// lwz r11,24(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// addi r4,r30,24
	ctx.r4.s64 = ctx.r30.s64 + 24;
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x88154274
	if (!ctx.cr6.eq) goto loc_88154274;
	// lwz r11,36(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 36);
	// lwz r9,12(r23)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r23.u32 + 12);
	// lhz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4);
	// lhz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r11.u32 + 0);
	// extsh r11,r8
	ctx.r11.s64 = ctx.r8.s16;
	// extsh r10,r7
	ctx.r10.s64 = ctx.r7.s16;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x88154274
	if (ctx.cr6.lt) goto loc_88154274;
	// lwz r9,12(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x88154274
	if (ctx.cr6.eq) goto loc_88154274;
	// lwz r9,8(r23)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r23.u32 + 8);
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// bgt cr6,0x88154274
	if (ctx.cr6.gt) goto loc_88154274;
	// lwz r9,0(r23)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r23.u32 + 0);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bgt cr6,0x88154274
	if (ctx.cr6.gt) goto loc_88154274;
	// lwz r9,4(r23)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r23.u32 + 4);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x88154274
	if (ctx.cr6.lt) goto loc_88154274;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// rlwinm r7,r11,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r3,r10,16,0,15
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r6,r27,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 16) & 0xFFFF0000;
	// std r31,0(r9)
	PPC_STORE_U64(ctx.r9.u32 + 0, ctx.r31.u64);
	// rlwinm r5,r26,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 16) & 0xFFFF0000;
	// std r31,0(r8)
	PPC_STORE_U64(ctx.r8.u32 + 0, ctx.r31.u64);
	// std r31,8(r9)
	PPC_STORE_U64(ctx.r9.u32 + 8, ctx.r31.u64);
	// std r31,8(r8)
	PPC_STORE_U64(ctx.r8.u32 + 8, ctx.r31.u64);
	// std r31,16(r9)
	PPC_STORE_U64(ctx.r9.u32 + 16, ctx.r31.u64);
	// std r31,16(r8)
	PPC_STORE_U64(ctx.r8.u32 + 16, ctx.r31.u64);
	// std r31,24(r9)
	PPC_STORE_U64(ctx.r9.u32 + 24, ctx.r31.u64);
	// std r31,24(r8)
	PPC_STORE_U64(ctx.r8.u32 + 24, ctx.r31.u64);
	// lwz r11,20(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// ori r10,r11,1024
	ctx.r10.u64 = ctx.r11.u64 | 1024;
	// stw r10,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r10.u32);
	// lwz r9,20(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// ori r8,r9,16
	ctx.r8.u64 = ctx.r9.u64 | 16;
	// stw r24,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r24.u32);
	// stw r6,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r6.u32);
	// stw r5,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r5.u32);
	// stw r25,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r25.u32);
	// stw r3,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r3.u32);
	// stw r7,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r7.u32);
	// stw r8,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r8.u32);
	// lwz r11,32(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88154248
	if (ctx.cr6.eq) goto loc_88154248;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r5,36(r28)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r28.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8815423C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88154248
	if (!ctx.cr6.eq) goto loc_88154248;
	// stw r31,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r31.u32);
loc_88154248:
	// lwz r11,32(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88154274
	if (ctx.cr6.eq) goto loc_88154274;
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
	// lwz r5,36(r22)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r22.u32 + 36);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x88154268;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88154274
	if (!ctx.cr6.eq) goto loc_88154274;
	// stw r31,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r31.u32);
loc_88154274:
	// lwz r30,0(r30)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x8815413c
	if (!ctx.cr6.eq) goto loc_8815413C;
loc_88154280:
	// lwz r28,0(r28)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x88154124
	if (!ctx.cr6.eq) goto loc_88154124;
loc_8815428C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8807118c
	__restgprlr_21(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88154298"))) PPC_WEAK_FUNC(sub_88154298);
PPC_FUNC_IMPL(__imp__sub_88154298) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807112c
	ctx.lr = 0x881542A0;
	__savegprlr_17(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// rlwinm r10,r8,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r29,r11,508
	ctx.r29.s64 = ctx.r11.s64 + 508;
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// mr r17,r9
	ctx.r17.u64 = ctx.r9.u64;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// addi r9,r29,-300
	ctx.r9.s64 = ctx.r29.s64 + -300;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r20,r7
	ctx.r20.u64 = ctx.r7.u64;
	// lwz r11,-13952(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -13952);
	// mr r30,r8
	ctx.r30.u64 = ctx.r8.u64;
	// lis r8,-30671
	ctx.r8.s64 = -2010054656;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r9,4
	ctx.r6.s64 = ctx.r9.s64 + 4;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// mr r24,r5
	ctx.r24.u64 = ctx.r5.u64;
	// addi r5,r8,4276
	ctx.r5.s64 = ctx.r8.s64 + 4276;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r25,r7,r6
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// lwzx r19,r4,r5
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r5.u32);
	// beq cr6,0x881544cc
	if (ctx.cr6.eq) goto loc_881544CC;
	// lis r11,-30656
	ctx.r11.s64 = -2009071616;
	// li r18,1
	ctx.r18.s64 = 1;
	// li r21,0
	ctx.r21.s64 = 0;
	// addi r28,r11,1504
	ctx.r28.s64 = ctx.r11.s64 + 1504;
loc_88154310:
	// lwz r11,8(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x881544c0
	if (ctx.cr6.eq) goto loc_881544C0;
	// lwz r23,28(r25)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r25.u32 + 28);
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x881544c0
	if (ctx.cr6.eq) goto loc_881544C0;
loc_88154328:
	// lwz r11,12(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 12);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x881544c0
	if (ctx.cr6.eq) goto loc_881544C0;
	// lwz r11,8(r23)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x881544b4
	if (ctx.cr6.eq) goto loc_881544B4;
	// lhz r11,52(r23)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r23.u32 + 52);
	// addi r31,r23,24
	ctx.r31.s64 = ctx.r23.s64 + 24;
	// lhz r8,56(r23)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r23.u32 + 56);
	// lwz r10,60(r23)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r23.u32 + 60);
	// extsh r9,r11
	ctx.r9.s64 = ctx.r11.s16;
	// extsh r11,r8
	ctx.r11.s64 = ctx.r8.s16;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x88154378
	if (ctx.cr6.eq) goto loc_88154378;
	// lhz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// lhz r7,4(r10)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// extsh r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	// extsh r10,r7
	ctx.r10.s64 = ctx.r7.s16;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_88154378:
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r6,12(r26)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r26.u32 + 12);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmpw cr6,r10,r6
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, ctx.xer);
	// blt cr6,0x881544b4
	if (ctx.cr6.lt) goto loc_881544B4;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r7,8(r26)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r26.u32 + 8);
	// subf r8,r10,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r10.s64;
	// cmpw cr6,r8,r7
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, ctx.xer);
	// bgt cr6,0x881544b4
	if (ctx.cr6.gt) goto loc_881544B4;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r11.s64;
	// cmpw cr6,r8,r10
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r10.s32, ctx.xer);
	// bgt cr6,0x881544b4
	if (ctx.cr6.gt) goto loc_881544B4;
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,4(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x881544b4
	if (ctx.cr6.lt) goto loc_881544B4;
	// stw r7,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r7.u32);
	// stw r6,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r6.u32);
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// lwz r11,32(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r27,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r27.u32);
	// beq cr6,0x881544b4
	if (ctx.cr6.eq) goto loc_881544B4;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r5,36(r25)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r25.u32 + 36);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x881543FC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x881544b4
	if (ctx.cr6.eq) goto loc_881544B4;
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// stw r18,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r18.u32);
	// bne cr6,0x88154430
	if (!ctx.cr6.eq) goto loc_88154430;
	// addi r11,r30,-6
	ctx.r11.s64 = ctx.r30.s64 + -6;
	// addi r10,r29,-20
	ctx.r10.s64 = ctx.r29.s64 + -20;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r29,48
	ctx.r8.s64 = ctx.r29.s64 + 48;
	// addi r7,r28,24
	ctx.r7.s64 = ctx.r28.s64 + 24;
	// stwx r24,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r24.u32);
	// stwx r27,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r27.u32);
	// b 0x8815444c
	goto loc_8815444C;
loc_88154430:
	// addi r11,r30,-11
	ctx.r11.s64 = ctx.r30.s64 + -11;
	// addi r10,r28,44
	ctx.r10.s64 = ctx.r28.s64 + 44;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r29,-320
	ctx.r8.s64 = ctx.r29.s64 + -320;
	// addi r7,r29,24
	ctx.r7.s64 = ctx.r29.s64 + 24;
	// stwx r27,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r27.u32);
	// stwx r24,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r24.u32);
loc_8815444C:
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r17,0
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 0, ctx.xer);
	// stwx r6,r9,r7
	PPC_STORE_U32(ctx.r9.u32 + ctx.r7.u32, ctx.r6.u32);
	// beq cr6,0x88154464
	if (ctx.cr6.eq) goto loc_88154464;
	// cmpw cr6,r20,r19
	ctx.cr6.compare<int32_t>(ctx.r20.s32, ctx.r19.s32, ctx.xer);
	// bge cr6,0x88154480
	if (!ctx.cr6.lt) goto loc_88154480;
loc_88154464:
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// bne cr6,0x881544a8
	if (!ctx.cr6.eq) goto loc_881544A8;
	// addi r11,r30,-6
	ctx.r11.s64 = ctx.r30.s64 + -6;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r9,r29
	PPC_STORE_U32(ctx.r9.u32 + ctx.r29.u32, ctx.r10.u32);
	// b 0x881544b4
	goto loc_881544B4;
loc_88154480:
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// bne cr6,0x88154498
	if (!ctx.cr6.eq) goto loc_88154498;
	// addi r11,r30,-6
	ctx.r11.s64 = ctx.r30.s64 + -6;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r21,r10,r29
	PPC_STORE_U32(ctx.r10.u32 + ctx.r29.u32, ctx.r21.u32);
	// b 0x881544b4
	goto loc_881544B4;
loc_88154498:
	// addi r11,r30,-11
	ctx.r11.s64 = ctx.r30.s64 + -11;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r21,r10,r28
	PPC_STORE_U32(ctx.r10.u32 + ctx.r28.u32, ctx.r21.u32);
	// b 0x881544b4
	goto loc_881544B4;
loc_881544A8:
	// addi r11,r30,-11
	ctx.r11.s64 = ctx.r30.s64 + -11;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r9,r28
	PPC_STORE_U32(ctx.r9.u32 + ctx.r28.u32, ctx.r10.u32);
loc_881544B4:
	// lwz r23,0(r23)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r23.u32 + 0);
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// bne cr6,0x88154328
	if (!ctx.cr6.eq) goto loc_88154328;
loc_881544C0:
	// lwz r25,0(r25)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// bne cr6,0x88154310
	if (!ctx.cr6.eq) goto loc_88154310;
loc_881544CC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8807117c
	__restgprlr_17(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_881544D8"))) PPC_WEAK_FUNC(sub_881544D8);
PPC_FUNC_IMPL(__imp__sub_881544D8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071120
	ctx.lr = 0x881544E0;
	__savegprlr_14(ctx, base);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r9
	ctx.r23.u64 = ctx.r9.u64;
	// stw r7,372(r1)
	PPC_STORE_U32(ctx.r1.u32 + 372, ctx.r7.u32);
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// addi r16,r9,-13948
	ctx.r16.s64 = ctx.r9.s64 + -13948;
	// addi r28,r11,552
	ctx.r28.s64 = ctx.r11.s64 + 552;
	// mr r15,r8
	ctx.r15.u64 = ctx.r8.u64;
	// mr r22,r10
	ctx.r22.u64 = ctx.r10.u64;
	// rlwinm r10,r3,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r11,-4(r16)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r16.u32 + -4);
	// lis r8,-30671
	ctx.r8.s64 = -2010054656;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r26,r6
	ctx.r26.u64 = ctx.r6.u64;
	// add r7,r3,r10
	ctx.r7.u64 = ctx.r3.u64 + ctx.r10.u64;
	// addi r9,r28,-344
	ctx.r9.s64 = ctx.r28.s64 + -344;
	// addi r6,r8,4276
	ctx.r6.s64 = ctx.r8.s64 + 4276;
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// mr r24,r4
	ctx.r24.u64 = ctx.r4.u64;
	// rlwinm r4,r7,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r9,52
	ctx.r3.s64 = ctx.r9.s64 + 52;
	// lwzx r11,r5,r6
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r6.u32);
	// addi r18,r27,24
	ctx.r18.s64 = ctx.r27.s64 + 24;
	// lwzx r20,r4,r3
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r3.u32);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x881547ec
	if (ctx.cr6.eq) goto loc_881547EC;
	// li r21,2
	ctx.r21.s64 = 2;
	// li r29,0
	ctx.r29.s64 = 0;
	// lis r14,-30633
	ctx.r14.s64 = -2007564288;
	// li r19,1
	ctx.r19.s64 = 1;
	// li r17,48
	ctx.r17.s64 = 48;
loc_88154564:
	// lwz r11,8(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x881547e0
	if (ctx.cr6.eq) goto loc_881547E0;
	// lwz r30,28(r20)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r20.u32 + 28);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x881547e0
	if (ctx.cr6.eq) goto loc_881547E0;
loc_8815457C:
	// lwz r11,12(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x881547e0
	if (ctx.cr6.eq) goto loc_881547E0;
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x881547d4
	if (ctx.cr6.eq) goto loc_881547D4;
	// addi r31,r30,24
	ctx.r31.s64 = ctx.r30.s64 + 24;
	// cmplwi cr6,r15,21
	ctx.cr6.compare<uint32_t>(ctx.r15.u32, 21, ctx.xer);
	// bne cr6,0x881545b0
	if (!ctx.cr6.eq) goto loc_881545B0;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x881547d4
	if (!ctx.cr6.eq) goto loc_881547D4;
loc_881545B0:
	// lhz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 28);
	// lhz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 32);
	// lwz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// extsh r9,r11
	ctx.r9.s64 = ctx.r11.s16;
	// extsh r11,r10
	ctx.r11.s64 = ctx.r10.s16;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x881545e8
	if (ctx.cr6.eq) goto loc_881545E8;
	// rotlwi r10,r8,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// lhz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// lhz r7,4(r10)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// extsh r10,r8
	ctx.r10.s64 = ctx.r8.s16;
	// extsh r8,r7
	ctx.r8.s64 = ctx.r7.s16;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
loc_881545E8:
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r10,12(r24)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r24.u32 + 12);
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + ctx.r11.u64;
	// cmpw cr6,r8,r10
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x881547d4
	if (ctx.cr6.lt) goto loc_881547D4;
	// lwz r8,12(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x881547d4
	if (ctx.cr6.eq) goto loc_881547D4;
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r7,8(r24)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r24.u32 + 8);
	// subf r6,r8,r11
	ctx.r6.s64 = ctx.r11.s64 - ctx.r8.s64;
	// cmpw cr6,r6,r7
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r7.s32, ctx.xer);
	// bgt cr6,0x881547d4
	if (ctx.cr6.gt) goto loc_881547D4;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r8,0(r24)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// subf r7,r11,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r11.s64;
	// cmpw cr6,r7,r8
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, ctx.xer);
	// bgt cr6,0x881547d4
	if (ctx.cr6.gt) goto loc_881547D4;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r8,4(r24)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r24.u32 + 4);
	// add r7,r11,r9
	ctx.r7.u64 = ctx.r11.u64 + ctx.r9.u64;
	// cmpw cr6,r7,r8
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x881547d4
	if (ctx.cr6.lt) goto loc_881547D4;
	// lwz r11,20(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// extsh r9,r22
	ctx.r9.s64 = ctx.r22.s16;
	// addi r8,r28,-76
	ctx.r8.s64 = ctx.r28.s64 + -76;
	// stw r26,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r26.u32);
	// or r7,r9,r11
	ctx.r7.u64 = ctx.r9.u64 | ctx.r11.u64;
	// stw r9,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r9.u32);
	// rlwinm r6,r25,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r10,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r10.u32);
	// stw r7,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r7.u32);
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// lwz r5,20(r27)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r27.u32 + 20);
	// ori r4,r5,2
	ctx.r4.u64 = ctx.r5.u64 | 2;
	// stw r4,20(r27)
	PPC_STORE_U32(ctx.r27.u32 + 20, ctx.r4.u32);
	// lwzx r11,r6,r8
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r21,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r21.u32);
	// stw r29,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r29.u32);
	// stw r9,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r9.u32);
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
	// beq cr6,0x881546b0
	if (ctx.cr6.eq) goto loc_881546B0;
	// lwz r10,372(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 372);
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpw cr6,r10,r8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x881546b0
	if (ctx.cr6.lt) goto loc_881546B0;
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// stw r29,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r29.u32);
	// b 0x881546bc
	goto loc_881546BC;
loc_881546B0:
	// lwz r8,24(r18)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r18.u32 + 24);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// stw r8,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r8.u32);
loc_881546BC:
	// lwz r8,0(r16)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// cmplwi cr6,r8,2
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 2, ctx.xer);
	// bne cr6,0x881546e4
	if (!ctx.cr6.eq) goto loc_881546E4;
	// mulli r10,r10,70
	ctx.r10.s64 = ctx.r10.s64 * 70;
	// li r8,100
	ctx.r8.s64 = 100;
	// divwu. r10,r10,r8
	ctx.r10.u32 = ppc_divwu(ctx.r10.u32, ctx.r8.u32);
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// bne 0x881546e4
	if (!ctx.cr0.eq) goto loc_881546E4;
	// stw r19,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r19.u32);
loc_881546E4:
	// lwz r10,-29776(r14)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r14.u32 + -29776);
	// lwz r8,32(r26)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r26.u32 + 32);
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// beq cr6,0x88154704
	if (ctx.cr6.eq) goto loc_88154704;
	// lis r10,-30633
	ctx.r10.s64 = -2007564288;
	// lwz r10,-29780(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -29780);
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// bne cr6,0x88154780
	if (!ctx.cr6.eq) goto loc_88154780;
loc_88154704:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x88154780
	if (!ctx.cr6.eq) goto loc_88154780;
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// bne cr6,0x88154750
	if (!ctx.cr6.eq) goto loc_88154750;
	// lwz r11,-376(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -376);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88154780
	if (!ctx.cr6.eq) goto loc_88154780;
	// lwz r11,-76(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -76);
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// stw r29,184(r11)
	PPC_STORE_U32(ctx.r11.u32 + 184, ctx.r29.u32);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r10,176(r11)
	PPC_STORE_U32(ctx.r11.u32 + 176, ctx.r10.u32);
	// cmpwi cr6,r9,48
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 48, ctx.xer);
	// blt cr6,0x88154748
	if (ctx.cr6.lt) goto loc_88154748;
	// stw r17,176(r11)
	PPC_STORE_U32(ctx.r11.u32 + 176, ctx.r17.u32);
	// stw r19,184(r11)
	PPC_STORE_U32(ctx.r11.u32 + 184, ctx.r19.u32);
loc_88154748:
	// stw r19,-376(r28)
	PPC_STORE_U32(ctx.r28.u32 + -376, ctx.r19.u32);
	// b 0x88154780
	goto loc_88154780;
loc_88154750:
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x88154780
	if (!ctx.cr6.eq) goto loc_88154780;
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// stw r29,184(r11)
	PPC_STORE_U32(ctx.r11.u32 + 184, ctx.r29.u32);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// stw r10,176(r11)
	PPC_STORE_U32(ctx.r11.u32 + 176, ctx.r10.u32);
	// cmpwi cr6,r10,48
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 48, ctx.xer);
	// blt cr6,0x8815477c
	if (ctx.cr6.lt) goto loc_8815477C;
	// stw r17,176(r11)
	PPC_STORE_U32(ctx.r11.u32 + 176, ctx.r17.u32);
	// stw r19,184(r11)
	PPC_STORE_U32(ctx.r11.u32 + 184, ctx.r19.u32);
loc_8815477C:
	// stw r19,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r19.u32);
loc_88154780:
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x881547a8
	if (ctx.cr6.eq) goto loc_881547A8;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// lwz r5,36(r26)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r26.u32 + 36);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8815479C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x881547a8
	if (!ctx.cr6.eq) goto loc_881547A8;
	// stw r29,12(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12, ctx.r29.u32);
loc_881547A8:
	// lwz r11,32(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x881547d4
	if (ctx.cr6.eq) goto loc_881547D4;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r5,36(r20)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r20.u32 + 36);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x881547C8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x881547d4
	if (!ctx.cr6.eq) goto loc_881547D4;
	// stw r29,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r29.u32);
loc_881547D4:
	// lwz r30,0(r30)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x8815457c
	if (!ctx.cr6.eq) goto loc_8815457C;
loc_881547E0:
	// lwz r20,0(r20)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// bne cr6,0x88154564
	if (!ctx.cr6.eq) goto loc_88154564;
loc_881547EC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_881547F8"))) PPC_WEAK_FUNC(sub_881547F8);
PPC_FUNC_IMPL(__imp__sub_881547F8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071130
	ctx.lr = 0x88154800;
	__savegprlr_18(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// mr r24,r10
	ctx.r24.u64 = ctx.r10.u64;
	// addi r11,r11,208
	ctx.r11.s64 = ctx.r11.s64 + 208;
	// mr r25,r9
	ctx.r25.u64 = ctx.r9.u64;
	// mulli r9,r4,196
	ctx.r9.s64 = ctx.r4.s64 * 196;
	// lwz r10,276(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 276);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r22,r6
	ctx.r22.u64 = ctx.r6.u64;
	// mr r23,r7
	ctx.r23.u64 = ctx.r7.u64;
	// mr r21,r8
	ctx.r21.u64 = ctx.r8.u64;
	// addic. r26,r10,1448
	ctx.xer.ca = ctx.r10.u32 > 4294965847;
	ctx.r26.s64 = ctx.r10.s64 + 1448;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne 0x88154844
	if (!ctx.cr0.eq) goto loc_88154844;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x88071180
	__restgprlr_18(ctx, base);
	return;
loc_88154844:
	// rlwinm r10,r3,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r9,-30643
	ctx.r9.s64 = -2008219648;
	// add r8,r3,r10
	ctx.r8.u64 = ctx.r3.u64 + ctx.r10.u64;
	// addi r7,r11,4
	ctx.r7.s64 = ctx.r11.s64 + 4;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r5,r9,26432
	ctx.r5.s64 = ctx.r9.s64 + 26432;
	// addi r28,r22,24
	ctx.r28.s64 = ctx.r22.s64 + 24;
	// lwzx r27,r6,r7
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r7.u32);
	// lwz r19,324(r5)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + 324);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x88154a40
	if (ctx.cr6.eq) goto loc_88154A40;
	// li r31,0
	ctx.r31.s64 = 0;
	// li r20,100
	ctx.r20.s64 = 100;
	// li r18,1
	ctx.r18.s64 = 1;
loc_8815487C:
	// lwz r11,8(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88154a34
	if (ctx.cr6.eq) goto loc_88154A34;
	// lwz r30,28(r27)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r27.u32 + 28);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x88154a34
	if (ctx.cr6.eq) goto loc_88154A34;
loc_88154894:
	// lwz r11,12(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 12);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88154a34
	if (ctx.cr6.eq) goto loc_88154A34;
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88154a28
	if (ctx.cr6.eq) goto loc_88154A28;
	// addi r4,r30,24
	ctx.r4.s64 = ctx.r30.s64 + 24;
	// cmpwi cr6,r21,0
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// beq cr6,0x881548c8
	if (ctx.cr6.eq) goto loc_881548C8;
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88154a28
	if (ctx.cr6.eq) goto loc_88154A28;
loc_881548C8:
	// lhz r11,28(r4)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 28);
	// lhz r9,32(r4)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r4.u32 + 32);
	// lwz r8,36(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 36);
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// extsh r11,r9
	ctx.r11.s64 = ctx.r9.s16;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x88154900
	if (ctx.cr6.eq) goto loc_88154900;
	// rotlwi r9,r8,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// lhz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 0);
	// lhz r7,4(r9)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// extsh r9,r8
	ctx.r9.s64 = ctx.r8.s16;
	// extsh r8,r7
	ctx.r8.s64 = ctx.r7.s16;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
loc_88154900:
	// lwz r9,16(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// lwz r8,12(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// add r7,r9,r11
	ctx.r7.u64 = ctx.r9.u64 + ctx.r11.u64;
	// cmpw cr6,r7,r8
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x88154a28
	if (ctx.cr6.lt) goto loc_88154A28;
	// lwz r9,12(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x88154a28
	if (ctx.cr6.eq) goto loc_88154A28;
	// lwz r9,20(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// lwz r8,8(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// subf r7,r9,r11
	ctx.r7.s64 = ctx.r11.s64 - ctx.r9.s64;
	// cmpw cr6,r7,r8
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, ctx.xer);
	// bgt cr6,0x88154a28
	if (ctx.cr6.gt) goto loc_88154A28;
	// lwz r11,12(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// subf r8,r11,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r11.s64;
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// bgt cr6,0x88154a28
	if (ctx.cr6.gt) goto loc_88154A28;
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r9,4(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x88154a28
	if (ctx.cr6.lt) goto loc_88154A28;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// extsh r9,r25
	ctx.r9.s64 = ctx.r25.s16;
	// extsh r8,r24
	ctx.r8.s64 = ctx.r24.s16;
	// cmpwi cr6,r9,32
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 32, ctx.xer);
	// std r31,0(r11)
	PPC_STORE_U64(ctx.r11.u32 + 0, ctx.r31.u64);
	// std r31,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r31.u64);
	// std r31,8(r11)
	PPC_STORE_U64(ctx.r11.u32 + 8, ctx.r31.u64);
	// std r31,8(r10)
	PPC_STORE_U64(ctx.r10.u32 + 8, ctx.r31.u64);
	// std r31,16(r11)
	PPC_STORE_U64(ctx.r11.u32 + 16, ctx.r31.u64);
	// std r31,16(r10)
	PPC_STORE_U64(ctx.r10.u32 + 16, ctx.r31.u64);
	// std r31,24(r11)
	PPC_STORE_U64(ctx.r11.u32 + 24, ctx.r31.u64);
	// std r31,24(r10)
	PPC_STORE_U64(ctx.r10.u32 + 24, ctx.r31.u64);
	// lwz r7,20(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// or r6,r9,r7
	ctx.r6.u64 = ctx.r9.u64 | ctx.r7.u64;
	// stw r6,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r6.u32);
	// lwz r11,24(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 24);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// stw r26,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r26.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// stw r8,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// stw r31,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r31.u32);
	// bne cr6,0x881549d4
	if (!ctx.cr6.eq) goto loc_881549D4;
	// cmpwi cr6,r19,2
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 2, ctx.xer);
	// bne cr6,0x881549d4
	if (!ctx.cr6.eq) goto loc_881549D4;
	// mulli r11,r11,70
	ctx.r11.s64 = ctx.r11.s64 * 70;
	// divwu. r11,r11,r20
	ctx.r11.u32 = ppc_divwu(ctx.r11.u32, ctx.r20.u32);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bne 0x881549d4
	if (!ctx.cr0.eq) goto loc_881549D4;
	// stw r18,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r18.u32);
loc_881549D4:
	// lwz r11,32(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x881549fc
	if (ctx.cr6.eq) goto loc_881549FC;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r5,36(r27)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r27.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x881549F0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x881549fc
	if (!ctx.cr6.eq) goto loc_881549FC;
	// stw r31,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r31.u32);
loc_881549FC:
	// lwz r11,32(r23)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + 32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88154a28
	if (ctx.cr6.eq) goto loc_88154A28;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r5,36(r23)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r23.u32 + 36);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x88154A1C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88154a28
	if (!ctx.cr6.eq) goto loc_88154A28;
	// stw r31,12(r22)
	PPC_STORE_U32(ctx.r22.u32 + 12, ctx.r31.u32);
loc_88154A28:
	// lwz r30,0(r30)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x88154894
	if (!ctx.cr6.eq) goto loc_88154894;
loc_88154A34:
	// lwz r27,0(r27)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// bne cr6,0x8815487c
	if (!ctx.cr6.eq) goto loc_8815487C;
loc_88154A40:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x88071180
	__restgprlr_18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88154A4C"))) PPC_WEAK_FUNC(sub_88154A4C);
PPC_FUNC_IMPL(__imp__sub_88154A4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88154A50"))) PPC_WEAK_FUNC(sub_88154A50);
PPC_FUNC_IMPL(__imp__sub_88154A50) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071144
	ctx.lr = 0x88154A58;
	__savegprlr_23(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// mulli r9,r3,196
	ctx.r9.s64 = ctx.r3.s64 * 196;
	// addi r11,r11,208
	ctx.r11.s64 = ctx.r11.s64 + 208;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// lwz r10,276(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 276);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addic. r28,r10,1448
	ctx.xer.ca = ctx.r10.u32 > 4294965847;
	ctx.r28.s64 = ctx.r10.s64 + 1448;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bne 0x88154a8c
	if (!ctx.cr0.eq) goto loc_88154A8C;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
loc_88154A8C:
	// lwz r11,232(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 232);
	// lwz r25,28(r27)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r27.u32 + 28);
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// addi r23,r25,24
	ctx.r23.s64 = ctx.r25.s64 + 24;
	// beq cr6,0x88154bfc
	if (ctx.cr6.eq) goto loc_88154BFC;
	// li r26,128
	ctx.r26.s64 = 128;
	// li r24,0
	ctx.r24.s64 = 0;
loc_88154AAC:
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88154bf0
	if (ctx.cr6.eq) goto loc_88154BF0;
	// lwz r31,28(r29)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r29.u32 + 28);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x88154bf0
	if (ctx.cr6.eq) goto loc_88154BF0;
loc_88154AC4:
	// lwz r11,12(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 12);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88154bf0
	if (ctx.cr6.eq) goto loc_88154BF0;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88154be4
	if (ctx.cr6.eq) goto loc_88154BE4;
	// lhz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 52);
	// addi r4,r31,24
	ctx.r4.s64 = ctx.r31.s64 + 24;
	// lhz r9,56(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 56);
	// lwz r8,60(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// extsh r11,r9
	ctx.r11.s64 = ctx.r9.s16;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x88154b18
	if (ctx.cr6.eq) goto loc_88154B18;
	// lwz r9,36(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 36);
	// lhz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 0);
	// lhz r7,4(r9)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// extsh r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	// extsh r9,r7
	ctx.r9.s64 = ctx.r7.s16;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
loc_88154B18:
	// lwz r9,16(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// lwz r8,12(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// add r7,r9,r11
	ctx.r7.u64 = ctx.r9.u64 + ctx.r11.u64;
	// cmpw cr6,r7,r8
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x88154be4
	if (ctx.cr6.lt) goto loc_88154BE4;
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x88154be4
	if (ctx.cr6.eq) goto loc_88154BE4;
	// lwz r9,20(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// lwz r8,8(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// subf r7,r9,r11
	ctx.r7.s64 = ctx.r11.s64 - ctx.r9.s64;
	// cmpw cr6,r7,r8
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, ctx.xer);
	// bgt cr6,0x88154be4
	if (ctx.cr6.gt) goto loc_88154BE4;
	// lwz r11,12(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// subf r8,r11,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r11.s64;
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// bgt cr6,0x88154be4
	if (ctx.cr6.gt) goto loc_88154BE4;
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x88154be4
	if (ctx.cr6.lt) goto loc_88154BE4;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// stw r28,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r28.u32);
	// ori r10,r11,128
	ctx.r10.u64 = ctx.r11.u64 | 128;
	// stw r26,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r26.u32);
	// stw r10,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// lwz r11,32(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 32);
	// lwz r9,44(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 44);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88154bb8
	if (ctx.cr6.eq) goto loc_88154BB8;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r5,36(r29)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r29.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x88154BAC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88154bb8
	if (!ctx.cr6.eq) goto loc_88154BB8;
	// stw r24,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r24.u32);
loc_88154BB8:
	// lwz r11,32(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88154be4
	if (ctx.cr6.eq) goto loc_88154BE4;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// lwz r5,36(r27)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r27.u32 + 36);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x88154BD8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88154be4
	if (!ctx.cr6.eq) goto loc_88154BE4;
	// stw r24,12(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12, ctx.r24.u32);
loc_88154BE4:
	// lwz r31,0(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x88154ac4
	if (!ctx.cr6.eq) goto loc_88154AC4;
loc_88154BF0:
	// lwz r29,0(r29)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x88154aac
	if (!ctx.cr6.eq) goto loc_88154AAC;
loc_88154BFC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88154C08"))) PPC_WEAK_FUNC(sub_88154C08);
PPC_FUNC_IMPL(__imp__sub_88154C08) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071144
	ctx.lr = 0x88154C10;
	__savegprlr_23(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// mulli r9,r3,196
	ctx.r9.s64 = ctx.r3.s64 * 196;
	// addi r11,r11,208
	ctx.r11.s64 = ctx.r11.s64 + 208;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// lwz r10,276(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 276);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addic. r28,r10,1448
	ctx.xer.ca = ctx.r10.u32 > 4294965847;
	ctx.r28.s64 = ctx.r10.s64 + 1448;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bne 0x88154c44
	if (!ctx.cr0.eq) goto loc_88154C44;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
loc_88154C44:
	// lwz r11,220(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 220);
	// lwz r25,28(r27)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r27.u32 + 28);
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// addi r23,r25,24
	ctx.r23.s64 = ctx.r25.s64 + 24;
	// beq cr6,0x88154db4
	if (ctx.cr6.eq) goto loc_88154DB4;
	// li r26,64
	ctx.r26.s64 = 64;
	// li r24,0
	ctx.r24.s64 = 0;
loc_88154C64:
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88154da8
	if (ctx.cr6.eq) goto loc_88154DA8;
	// lwz r31,28(r29)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r29.u32 + 28);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x88154da8
	if (ctx.cr6.eq) goto loc_88154DA8;
loc_88154C7C:
	// lwz r11,12(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 12);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88154da8
	if (ctx.cr6.eq) goto loc_88154DA8;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88154d9c
	if (ctx.cr6.eq) goto loc_88154D9C;
	// lhz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 52);
	// addi r4,r31,24
	ctx.r4.s64 = ctx.r31.s64 + 24;
	// lhz r9,56(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 56);
	// lwz r8,60(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// extsh r11,r9
	ctx.r11.s64 = ctx.r9.s16;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x88154cd0
	if (ctx.cr6.eq) goto loc_88154CD0;
	// lwz r9,36(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 36);
	// lhz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 0);
	// lhz r7,4(r9)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// extsh r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	// extsh r9,r7
	ctx.r9.s64 = ctx.r7.s16;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
loc_88154CD0:
	// lwz r9,16(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// lwz r8,12(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// add r7,r9,r11
	ctx.r7.u64 = ctx.r9.u64 + ctx.r11.u64;
	// cmpw cr6,r7,r8
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x88154d9c
	if (ctx.cr6.lt) goto loc_88154D9C;
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x88154d9c
	if (ctx.cr6.eq) goto loc_88154D9C;
	// lwz r9,20(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// lwz r8,8(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// subf r7,r9,r11
	ctx.r7.s64 = ctx.r11.s64 - ctx.r9.s64;
	// cmpw cr6,r7,r8
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, ctx.xer);
	// bgt cr6,0x88154d9c
	if (ctx.cr6.gt) goto loc_88154D9C;
	// lwz r11,12(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// subf r8,r11,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r11.s64;
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// bgt cr6,0x88154d9c
	if (ctx.cr6.gt) goto loc_88154D9C;
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x88154d9c
	if (ctx.cr6.lt) goto loc_88154D9C;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// stw r28,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r28.u32);
	// ori r10,r11,1
	ctx.r10.u64 = ctx.r11.u64 | 1;
	// stw r26,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r26.u32);
	// stw r10,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// lwz r11,32(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 32);
	// lwz r9,44(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 44);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88154d70
	if (ctx.cr6.eq) goto loc_88154D70;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r5,36(r29)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r29.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x88154D64;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88154d70
	if (!ctx.cr6.eq) goto loc_88154D70;
	// stw r24,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r24.u32);
loc_88154D70:
	// lwz r11,32(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88154d9c
	if (ctx.cr6.eq) goto loc_88154D9C;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// lwz r5,36(r27)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r27.u32 + 36);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x88154D90;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88154d9c
	if (!ctx.cr6.eq) goto loc_88154D9C;
	// stw r24,12(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12, ctx.r24.u32);
loc_88154D9C:
	// lwz r31,0(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x88154c7c
	if (!ctx.cr6.eq) goto loc_88154C7C;
loc_88154DA8:
	// lwz r29,0(r29)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x88154c64
	if (!ctx.cr6.eq) goto loc_88154C64;
loc_88154DB4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88154DC0"))) PPC_WEAK_FUNC(sub_88154DC0);
PPC_FUNC_IMPL(__imp__sub_88154DC0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071140
	ctx.lr = 0x88154DC8;
	__savegprlr_22(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// mulli r9,r3,196
	ctx.r9.s64 = ctx.r3.s64 * 196;
	// addi r11,r11,208
	ctx.r11.s64 = ctx.r11.s64 + 208;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r24,r5
	ctx.r24.u64 = ctx.r5.u64;
	// lwz r10,276(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 276);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addic. r27,r10,1448
	ctx.xer.ca = ctx.r10.u32 > 4294965847;
	ctx.r27.s64 = ctx.r10.s64 + 1448;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// bne 0x88154dfc
	if (!ctx.cr0.eq) goto loc_88154DFC;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x88071190
	__restgprlr_22(ctx, base);
	return;
loc_88154DFC:
	// lwz r11,244(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 244);
	// lwz r23,28(r24)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r24.u32 + 28);
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// addi r22,r23,24
	ctx.r22.s64 = ctx.r23.s64 + 24;
	// beq cr6,0x88154f50
	if (ctx.cr6.eq) goto loc_88154F50;
	// li r31,0
	ctx.r31.s64 = 0;
	// li r25,1
	ctx.r25.s64 = 1;
	// li r26,16
	ctx.r26.s64 = 16;
loc_88154E20:
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88154f44
	if (ctx.cr6.eq) goto loc_88154F44;
	// lwz r30,28(r29)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r29.u32 + 28);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x88154f44
	if (ctx.cr6.eq) goto loc_88154F44;
loc_88154E38:
	// lwz r11,12(r23)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + 12);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88154f44
	if (ctx.cr6.eq) goto loc_88154F44;
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88154f38
	if (ctx.cr6.eq) goto loc_88154F38;
	// lwz r11,60(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 60);
	// addi r4,r30,24
	ctx.r4.s64 = ctx.r30.s64 + 24;
	// lwz r9,12(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// lhz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4);
	// lhz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r11.u32 + 0);
	// extsh r11,r8
	ctx.r11.s64 = ctx.r8.s16;
	// extsh r10,r7
	ctx.r10.s64 = ctx.r7.s16;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x88154f38
	if (ctx.cr6.lt) goto loc_88154F38;
	// lwz r9,12(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x88154f38
	if (ctx.cr6.eq) goto loc_88154F38;
	// lwz r9,8(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8);
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// bgt cr6,0x88154f38
	if (ctx.cr6.gt) goto loc_88154F38;
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bgt cr6,0x88154f38
	if (ctx.cr6.gt) goto loc_88154F38;
	// lwz r11,4(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x88154f38
	if (ctx.cr6.lt) goto loc_88154F38;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// std r31,0(r11)
	PPC_STORE_U64(ctx.r11.u32 + 0, ctx.r31.u64);
	// std r31,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r31.u64);
	// std r31,8(r11)
	PPC_STORE_U64(ctx.r11.u32 + 8, ctx.r31.u64);
	// std r31,8(r10)
	PPC_STORE_U64(ctx.r10.u32 + 8, ctx.r31.u64);
	// std r31,16(r11)
	PPC_STORE_U64(ctx.r11.u32 + 16, ctx.r31.u64);
	// std r31,16(r10)
	PPC_STORE_U64(ctx.r10.u32 + 16, ctx.r31.u64);
	// std r31,24(r11)
	PPC_STORE_U64(ctx.r11.u32 + 24, ctx.r31.u64);
	// std r31,24(r10)
	PPC_STORE_U64(ctx.r10.u32 + 24, ctx.r31.u64);
	// lwz r9,20(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// ori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 | 1;
	// stw r8,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r8.u32);
	// stw r27,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r27.u32);
	// stw r25,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r25.u32);
	// stw r26,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r26.u32);
	// lwz r11,32(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88154f0c
	if (ctx.cr6.eq) goto loc_88154F0C;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r5,36(r29)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r29.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x88154F00;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88154f0c
	if (!ctx.cr6.eq) goto loc_88154F0C;
	// stw r31,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r31.u32);
loc_88154F0C:
	// lwz r11,32(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88154f38
	if (ctx.cr6.eq) goto loc_88154F38;
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// lwz r5,36(r24)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r24.u32 + 36);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x88154F2C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88154f38
	if (!ctx.cr6.eq) goto loc_88154F38;
	// stw r31,12(r23)
	PPC_STORE_U32(ctx.r23.u32 + 12, ctx.r31.u32);
loc_88154F38:
	// lwz r30,0(r30)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x88154e38
	if (!ctx.cr6.eq) goto loc_88154E38;
loc_88154F44:
	// lwz r29,0(r29)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x88154e20
	if (!ctx.cr6.eq) goto loc_88154E20;
loc_88154F50:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x88071190
	__restgprlr_22(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88154F5C"))) PPC_WEAK_FUNC(sub_88154F5C);
PPC_FUNC_IMPL(__imp__sub_88154F5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88154F60"))) PPC_WEAK_FUNC(sub_88154F60);
PPC_FUNC_IMPL(__imp__sub_88154F60) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
loc_88154F70:
	// lwz r11,8(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88154fa4
	if (ctx.cr6.eq) goto loc_88154FA4;
	// lwz r11,28(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88154fa4
	if (ctx.cr6.eq) goto loc_88154FA4;
loc_88154F88:
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x88154f98
	if (ctx.cr6.eq) goto loc_88154F98;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
loc_88154F98:
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88154f88
	if (!ctx.cr6.eq) goto loc_88154F88;
loc_88154FA4:
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x88154f70
	if (!ctx.cr6.eq) goto loc_88154F70;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88154FB4"))) PPC_WEAK_FUNC(sub_88154FB4);
PPC_FUNC_IMPL(__imp__sub_88154FB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88154FB8"))) PPC_WEAK_FUNC(sub_88154FB8);
PPC_FUNC_IMPL(__imp__sub_88154FB8) {
	PPC_FUNC_PROLOGUE();
	// stw r4,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r4.u32);
	// stw r5,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88154FC4"))) PPC_WEAK_FUNC(sub_88154FC4);
PPC_FUNC_IMPL(__imp__sub_88154FC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88154FC8"))) PPC_WEAK_FUNC(sub_88154FC8);
PPC_FUNC_IMPL(__imp__sub_88154FC8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
loc_88154FDC:
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// or r3,r3,r9
	ctx.r3.u64 = ctx.r3.u64 | ctx.r9.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88154fdc
	if (!ctx.cr6.eq) goto loc_88154FDC;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88154FF8"))) PPC_WEAK_FUNC(sub_88154FF8);
PPC_FUNC_IMPL(__imp__sub_88154FF8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88155000"))) PPC_WEAK_FUNC(sub_88155000);
PPC_FUNC_IMPL(__imp__sub_88155000) {
	PPC_FUNC_PROLOGUE();
	// stw r4,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88155008"))) PPC_WEAK_FUNC(sub_88155008);
PPC_FUNC_IMPL(__imp__sub_88155008) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88155034
	if (ctx.cr6.eq) goto loc_88155034;
loc_8815501C:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88155034
	if (ctx.cr6.eq) goto loc_88155034;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8815501c
	if (!ctx.cr6.eq) goto loc_8815501C;
loc_88155034:
	// stw r9,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8815503C"))) PPC_WEAK_FUNC(sub_8815503C);
PPC_FUNC_IMPL(__imp__sub_8815503C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88155040"))) PPC_WEAK_FUNC(sub_88155040);
PPC_FUNC_IMPL(__imp__sub_88155040) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88155064
	if (ctx.cr6.eq) goto loc_88155064;
loc_8815504C:
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x88155064
	if (ctx.cr6.eq) goto loc_88155064;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r4,r4,-1
	ctx.r4.s64 = ctx.r4.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8815504c
	if (!ctx.cr6.eq) goto loc_8815504C;
loc_88155064:
	// stw r5,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8815506C"))) PPC_WEAK_FUNC(sub_8815506C);
PPC_FUNC_IMPL(__imp__sub_8815506C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88155070"))) PPC_WEAK_FUNC(sub_88155070);
PPC_FUNC_IMPL(__imp__sub_88155070) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88155094
	if (ctx.cr6.eq) goto loc_88155094;
loc_8815507C:
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x8815509c
	if (ctx.cr6.eq) goto loc_8815509C;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r4,r4,-1
	ctx.r4.s64 = ctx.r4.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8815507c
	if (!ctx.cr6.eq) goto loc_8815507C;
loc_88155094:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8815509C:
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x881550ac
	if (ctx.cr6.eq) goto loc_881550AC;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_881550AC:
	// addi r3,r11,24
	ctx.r3.s64 = ctx.r11.s64 + 24;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881550B4"))) PPC_WEAK_FUNC(sub_881550B4);
PPC_FUNC_IMPL(__imp__sub_881550B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881550B8"))) PPC_WEAK_FUNC(sub_881550B8);
PPC_FUNC_IMPL(__imp__sub_881550B8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// addi r6,r11,184
	ctx.r6.s64 = ctx.r11.s64 + 184;
	// lwz r5,288(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 288);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,0(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// addi r9,r6,392
	ctx.r9.s64 = ctx.r6.s64 + 392;
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r4,-4(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + -4);
	// subf r11,r5,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r5.s64;
	// add r3,r10,r9
	ctx.r3.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r11,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r11.u32);
	// li r8,0
	ctx.r8.s64 = 0;
loc_881550EC:
	// lwzu r7,-4(r3)
	ea = -4 + ctx.r3.u32;
	ctx.r7.u64 = PPC_LOAD_U32(ea);
	ctx.r3.u32 = ea;
	// addi r10,r6,24
	ctx.r10.s64 = ctx.r6.s64 + 24;
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
	// lwz r11,16(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r11,4(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88155188
	if (ctx.cr6.eq) goto loc_88155188;
loc_88155118:
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x88155130
	if (ctx.cr6.eq) goto loc_88155130;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88155118
	if (!ctx.cr6.eq) goto loc_88155118;
	// b 0x88155188
	goto loc_88155188;
loc_88155130:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x88155160
	if (!ctx.cr6.eq) goto loc_88155160;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88155154
	if (!ctx.cr6.eq) goto loc_88155154;
	// stw r8,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r8.u32);
	// stw r8,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r8.u32);
	// b 0x8815517c
	goto loc_8815517C;
loc_88155154:
	// stw r8,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r8.u32);
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// b 0x8815517c
	goto loc_8815517C;
loc_88155160:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88155174
	if (!ctx.cr6.eq) goto loc_88155174;
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// b 0x8815517c
	goto loc_8815517C;
loc_88155174:
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r11.u32);
	// stw r9,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
loc_8815517C:
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
loc_88155188:
	// lwz r11,28(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x881551b4
	if (ctx.cr6.eq) goto loc_881551B4;
loc_88155194:
	// stw r8,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r8.u32);
	// addi r4,r4,-1
	ctx.r4.s64 = ctx.r4.s64 + -1;
	// stw r8,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r8.u32);
	// stw r8,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r4,-4(r6)
	PPC_STORE_U32(ctx.r6.u32 + -4, ctx.r4.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88155194
	if (!ctx.cr6.eq) goto loc_88155194;
loc_881551B4:
	// stw r8,12(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12, ctx.r8.u32);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// stw r8,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r8.u32);
	// stw r8,20(r7)
	PPC_STORE_U32(ctx.r7.u32 + 20, ctx.r8.u32);
	// bne cr6,0x881550ec
	if (!ctx.cr6.eq) goto loc_881550EC;
	// stw r5,288(r6)
	PPC_STORE_U32(ctx.r6.u32 + 288, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881551D0"))) PPC_WEAK_FUNC(sub_881551D0);
PPC_FUNC_IMPL(__imp__sub_881551D0) {
	PPC_FUNC_PROLOGUE();
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x881551e4
	if (!ctx.cr6.eq) goto loc_881551E4;
loc_881551DC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_881551E4:
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// addi r11,r11,576
	ctx.r11.s64 = ctx.r11.s64 + 576;
	// lwz r10,-104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -104);
	// cmpwi cr6,r10,3000
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3000, ctx.xer);
	// bge cr6,0x881551dc
	if (!ctx.cr6.lt) goto loc_881551DC;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r7,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r7.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,-104(r11)
	PPC_STORE_U32(ctx.r11.u32 + -104, ctx.r10.u32);
	// stwx r9,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + ctx.r11.u32, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88155218"))) PPC_WEAK_FUNC(sub_88155218);
PPC_FUNC_IMPL(__imp__sub_88155218) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r10,-30658
	ctx.r10.s64 = -2009202688;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r10,208
	ctx.r10.s64 = ctx.r10.s64 + 208;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x8815525c
	if (ctx.cr6.eq) goto loc_8815525C;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// stw r3,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r3.u32);
	// b 0x88155264
	goto loc_88155264;
loc_8815525C:
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r3,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r3.u32);
loc_88155264:
	// stw r3,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r3.u32);
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x88155288
	if (ctx.cr6.eq) goto loc_88155288;
	// li r9,1
	ctx.r9.s64 = 1;
loc_88155278:
	// stw r9,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r9.u32);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x88155278
	if (!ctx.cr6.eq) goto loc_88155278;
loc_88155288:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88155298"))) PPC_WEAK_FUNC(sub_88155298);
PPC_FUNC_IMPL(__imp__sub_88155298) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x881552A0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// lis r8,-30656
	ctx.r8.s64 = -2009071616;
	// addi r30,r11,12576
	ctx.r30.s64 = ctx.r11.s64 + 12576;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lis r5,4
	ctx.r5.s64 = 262144;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r11,r11,26432
	ctx.r11.s64 = ctx.r11.s64 + 26432;
	// addi r3,r8,1568
	ctx.r3.s64 = ctx.r8.s64 + 1568;
	// stw r31,-12396(r30)
	PPC_STORE_U32(ctx.r30.u32 + -12396, ctx.r31.u32);
	// ori r5,r5,37856
	ctx.r5.u64 = ctx.r5.u64 | 37856;
	// stw r31,-12048(r30)
	PPC_STORE_U32(ctx.r30.u32 + -12048, ctx.r31.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,-12092(r30)
	PPC_STORE_U32(ctx.r30.u32 + -12092, ctx.r11.u32);
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// mr r9,r31
	ctx.r9.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x881552E4;
	sub_88073BD0(ctx, base);
	// lis r7,-30656
	ctx.r7.s64 = -2009071616;
	// stw r31,-12392(r30)
	PPC_STORE_U32(ctx.r30.u32 + -12392, ctx.r31.u32);
	// lis r5,1
	ctx.r5.s64 = 65536;
	// addi r29,r7,1528
	ctx.r29.s64 = ctx.r7.s64 + 1528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// ori r5,r5,54464
	ctx.r5.u64 = ctx.r5.u64 | 54464;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// stw r31,-4(r29)
	PPC_STORE_U32(ctx.r29.u32 + -4, ctx.r31.u32);
	// bl 0x88073bd0
	ctx.lr = 0x88155310;
	sub_88073BD0(ctx, base);
	// lis r28,-30658
	ctx.r28.s64 = -2009202688;
	// li r5,264
	ctx.r5.s64 = 264;
	// addi r30,r28,552
	ctx.r30.s64 = ctx.r28.s64 + 552;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r30,-344
	ctx.r3.s64 = ctx.r30.s64 + -344;
	// bl 0x88073bd0
	ctx.lr = 0x88155328;
	sub_88073BD0(ctx, base);
	// stw r31,-20(r30)
	PPC_STORE_U32(ctx.r30.u32 + -20, ctx.r31.u32);
	// stw r31,-24(r29)
	PPC_STORE_U32(ctx.r29.u32 + -24, ctx.r31.u32);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// stw r31,-44(r30)
	PPC_STORE_U32(ctx.r30.u32 + -44, ctx.r31.u32);
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// stw r31,-364(r30)
	PPC_STORE_U32(ctx.r30.u32 + -364, ctx.r31.u32);
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// stw r31,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r31.u32);
	// stw r31,-64(r30)
	PPC_STORE_U32(ctx.r30.u32 + -64, ctx.r31.u32);
	// stw r31,-16(r30)
	PPC_STORE_U32(ctx.r30.u32 + -16, ctx.r31.u32);
	// stw r31,4(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4, ctx.r31.u32);
	// stw r31,-20(r29)
	PPC_STORE_U32(ctx.r29.u32 + -20, ctx.r31.u32);
	// stw r31,-40(r30)
	PPC_STORE_U32(ctx.r30.u32 + -40, ctx.r31.u32);
	// stw r31,-360(r30)
	PPC_STORE_U32(ctx.r30.u32 + -360, ctx.r31.u32);
	// stw r31,-60(r30)
	PPC_STORE_U32(ctx.r30.u32 + -60, ctx.r31.u32);
	// stw r31,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r31.u32);
	// stw r31,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r31.u32);
	// stw r31,-12(r30)
	PPC_STORE_U32(ctx.r30.u32 + -12, ctx.r31.u32);
	// stw r31,8(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8, ctx.r31.u32);
	// stw r31,-16(r29)
	PPC_STORE_U32(ctx.r29.u32 + -16, ctx.r31.u32);
	// stw r31,-36(r30)
	PPC_STORE_U32(ctx.r30.u32 + -36, ctx.r31.u32);
	// stw r31,-356(r30)
	PPC_STORE_U32(ctx.r30.u32 + -356, ctx.r31.u32);
	// stw r31,-56(r30)
	PPC_STORE_U32(ctx.r30.u32 + -56, ctx.r31.u32);
	// stw r31,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r31.u32);
	// stw r31,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r31.u32);
	// stw r31,-8(r30)
	PPC_STORE_U32(ctx.r30.u32 + -8, ctx.r31.u32);
	// stw r31,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r31.u32);
	// stw r31,-12(r29)
	PPC_STORE_U32(ctx.r29.u32 + -12, ctx.r31.u32);
	// stw r31,-32(r30)
	PPC_STORE_U32(ctx.r30.u32 + -32, ctx.r31.u32);
	// stw r31,-352(r30)
	PPC_STORE_U32(ctx.r30.u32 + -352, ctx.r31.u32);
	// stw r31,-52(r30)
	PPC_STORE_U32(ctx.r30.u32 + -52, ctx.r31.u32);
	// stw r31,28(r29)
	PPC_STORE_U32(ctx.r29.u32 + 28, ctx.r31.u32);
	// stw r31,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r31.u32);
	// stw r31,-4(r30)
	PPC_STORE_U32(ctx.r30.u32 + -4, ctx.r31.u32);
	// stw r31,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r31.u32);
	// stw r31,-8(r29)
	PPC_STORE_U32(ctx.r29.u32 + -8, ctx.r31.u32);
	// stw r31,-28(r30)
	PPC_STORE_U32(ctx.r30.u32 + -28, ctx.r31.u32);
	// stw r31,-348(r30)
	PPC_STORE_U32(ctx.r30.u32 + -348, ctx.r31.u32);
	// stw r31,-48(r30)
	PPC_STORE_U32(ctx.r30.u32 + -48, ctx.r31.u32);
	// stw r31,-80(r30)
	PPC_STORE_U32(ctx.r30.u32 + -80, ctx.r31.u32);
	// stw r31,32(r29)
	PPC_STORE_U32(ctx.r29.u32 + 32, ctx.r31.u32);
	// stw r31,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r31.u32);
	// stw r31,36(r29)
	PPC_STORE_U32(ctx.r29.u32 + 36, ctx.r31.u32);
	// stw r31,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r31.u32);
	// stw r31,-376(r30)
	PPC_STORE_U32(ctx.r30.u32 + -376, ctx.r31.u32);
	// stw r31,552(r28)
	PPC_STORE_U32(ctx.r28.u32 + 552, ctx.r31.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_881553E8"))) PPC_WEAK_FUNC(sub_881553E8);
PPC_FUNC_IMPL(__imp__sub_881553E8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x881553F0;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// rlwinm r10,r3,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// add r10,r3,r10
	ctx.r10.u64 = ctx.r3.u64 + ctx.r10.u64;
	// addi r28,r11,208
	ctx.r28.s64 = ctx.r11.s64 + 208;
	// rlwinm r27,r10,2,0,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r28,196
	ctx.r9.s64 = ctx.r28.s64 + 196;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwzx r29,r27,r9
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r9.u32);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x88155540
	if (ctx.cr6.eq) goto loc_88155540;
loc_8815541C:
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88155534
	if (ctx.cr6.eq) goto loc_88155534;
	// lwz r30,28(r29)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r29.u32 + 28);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x88155534
	if (ctx.cr6.eq) goto loc_88155534;
loc_88155434:
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88155528
	if (ctx.cr6.eq) goto loc_88155528;
	// lhz r10,52(r30)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r30.u32 + 52);
	// addi r11,r30,24
	ctx.r11.s64 = ctx.r30.s64 + 24;
	// lhz r9,56(r30)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r30.u32 + 56);
	// lwz r8,60(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 60);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8815547c
	if (ctx.cr6.eq) goto loc_8815547C;
	// lwz r8,36(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// lhz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r8.u32 + 0);
	// lhz r6,4(r8)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4);
	// extsh r7,r7
	ctx.r7.s64 = ctx.r7.s16;
	// extsh r8,r6
	ctx.r8.s64 = ctx.r6.s16;
	// add r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 + ctx.r10.u64;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
loc_8815547C:
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r6,20(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// subf r3,r7,r10
	ctx.r3.s64 = ctx.r10.s64 - ctx.r7.s64;
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// subf r8,r6,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r6.s64;
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// add r7,r11,r9
	ctx.r7.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// bl 0x88154dc0
	ctx.lr = 0x881554BC;
	sub_88154DC0(ctx, base);
	// li r10,8
	ctx.r10.s64 = 8;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x881547f8
	ctx.lr = 0x881554E0;
	sub_881547F8(ctx, base);
	// li r10,2048
	ctx.r10.s64 = 2048;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x881547f8
	ctx.lr = 0x88155504;
	sub_881547F8(ctx, base);
	// li r10,1024
	ctx.r10.s64 = 1024;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,21
	ctx.r3.s64 = 21;
	// bl 0x881547f8
	ctx.lr = 0x88155528;
	sub_881547F8(ctx, base);
loc_88155528:
	// lwz r30,0(r30)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x88155434
	if (!ctx.cr6.eq) goto loc_88155434;
loc_88155534:
	// lwz r29,0(r29)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8815541c
	if (!ctx.cr6.eq) goto loc_8815541C;
loc_88155540:
	// addi r11,r28,28
	ctx.r11.s64 = ctx.r28.s64 + 28;
	// lwzx r30,r27,r11
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r11.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x88155694
	if (ctx.cr6.eq) goto loc_88155694;
loc_88155550:
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88155688
	if (ctx.cr6.eq) goto loc_88155688;
	// lwz r29,28(r30)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x88155688
	if (ctx.cr6.eq) goto loc_88155688;
loc_88155568:
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8815567c
	if (ctx.cr6.eq) goto loc_8815567C;
	// lhz r10,52(r29)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r29.u32 + 52);
	// addi r11,r29,24
	ctx.r11.s64 = ctx.r29.s64 + 24;
	// lhz r9,56(r29)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r29.u32 + 56);
	// lwz r8,60(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 60);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x881555b0
	if (ctx.cr6.eq) goto loc_881555B0;
	// lwz r8,36(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// lhz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r8.u32 + 0);
	// lhz r6,4(r8)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4);
	// extsh r7,r7
	ctx.r7.s64 = ctx.r7.s16;
	// extsh r8,r6
	ctx.r8.s64 = ctx.r6.s16;
	// add r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 + ctx.r10.u64;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
loc_881555B0:
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r6,20(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// subf r3,r7,r10
	ctx.r3.s64 = ctx.r10.s64 - ctx.r7.s64;
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// subf r8,r6,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r6.s64;
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// add r7,r11,r9
	ctx.r7.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// bl 0x88154dc0
	ctx.lr = 0x881555F0;
	sub_88154DC0(ctx, base);
	// li r10,8
	ctx.r10.s64 = 8;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x881547f8
	ctx.lr = 0x88155614;
	sub_881547F8(ctx, base);
	// li r10,2048
	ctx.r10.s64 = 2048;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x881547f8
	ctx.lr = 0x88155638;
	sub_881547F8(ctx, base);
	// li r10,1024
	ctx.r10.s64 = 1024;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,21
	ctx.r3.s64 = 21;
	// bl 0x881547f8
	ctx.lr = 0x8815565C;
	sub_881547F8(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88154c08
	ctx.lr = 0x8815566C;
	sub_88154C08(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88154a50
	ctx.lr = 0x8815567C;
	sub_88154A50(ctx, base);
loc_8815567C:
	// lwz r29,0(r29)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x88155568
	if (!ctx.cr6.eq) goto loc_88155568;
loc_88155688:
	// lwz r30,0(r30)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x88155550
	if (!ctx.cr6.eq) goto loc_88155550;
loc_88155694:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8815569C"))) PPC_WEAK_FUNC(sub_8815569C);
PPC_FUNC_IMPL(__imp__sub_8815569C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881556A0"))) PPC_WEAK_FUNC(sub_881556A0);
PPC_FUNC_IMPL(__imp__sub_881556A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x881556A8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// addi r6,r11,12576
	ctx.r6.s64 = ctx.r11.s64 + 12576;
	// lwz r29,-12396(r6)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r6.u32 + -12396);
	// subfic r11,r29,3000
	ctx.xer.ca = ctx.r29.u32 <= 3000;
	ctx.r11.s64 = 3000 - ctx.r29.s64;
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// bge cr6,0x881556d4
	if (!ctx.cr6.lt) goto loc_881556D4;
loc_881556C8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_881556D4:
	// lwz r8,-12392(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + -12392);
	// cmpwi cr6,r8,3000
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 3000, ctx.xer);
	// bge cr6,0x881556c8
	if (!ctx.cr6.lt) goto loc_881556C8;
	// lis r11,-30656
	ctx.r11.s64 = -2009071616;
	// addi r31,r11,1568
	ctx.r31.s64 = ctx.r11.s64 + 1568;
	// lwz r11,-44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -44);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r3,r10,r6
	ctx.r3.u64 = ctx.r10.u64 + ctx.r6.u64;
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x88155740
	if (ctx.cr6.eq) goto loc_88155740;
loc_88155708:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// li r10,3000
	ctx.r10.s64 = 3000;
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// subfc r5,r10,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r10.u32;
	ctx.r5.s64 = ctx.r11.s64 - ctx.r10.s64;
	// rlwinm r3,r10,1,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// subfe r10,r9,r3
	temp.u8 = (~ctx.r9.u32 + ctx.r3.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r3.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r9.u64 + ctx.r3.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 & ctx.r11.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r10,r9,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// add r3,r10,r6
	ctx.r3.u64 = ctx.r10.u64 + ctx.r6.u64;
	// lwz r5,12(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne cr6,0x88155708
	if (!ctx.cr6.eq) goto loc_88155708;
loc_88155740:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r4,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r4.u32);
	// li r9,3000
	ctx.r9.s64 = 3000;
	// stw r7,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r7.u32);
	// rlwinm r5,r11,1,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// subfc r4,r9,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r9.u32;
	ctx.r4.s64 = ctx.r11.s64 - ctx.r9.s64;
	// rlwinm r9,r9,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1;
	// lis r30,-30658
	ctx.r30.s64 = -2009202688;
	// subfe r4,r5,r9
	temp.u8 = (~ctx.r5.u32 + ctx.r9.u32 < ~ctx.r5.u32) | (~ctx.r5.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r4.u64 = ~ctx.r5.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// addi r9,r8,1
	ctx.r9.s64 = ctx.r8.s64 + 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// and r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 & ctx.r11.u64;
	// stw r9,-12392(r6)
	PPC_STORE_U32(ctx.r6.u32 + -12392, ctx.r9.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r9,528(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 528);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// stw r10,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r10.u32);
	// li r4,32767
	ctx.r4.s64 = 32767;
	// stw r10,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r10.u32);
	// stw r10,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r10.u32);
	// stw r5,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r5.u32);
	// stw r11,-44(r31)
	PPC_STORE_U32(ctx.r31.u32 + -44, ctx.r11.u32);
loc_8815579C:
	// mulli r11,r9,100
	ctx.r11.s64 = ctx.r9.s64 * 100;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lwz r28,16(r11)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bne cr6,0x88155804
	if (!ctx.cr6.eq) goto loc_88155804;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// beq cr6,0x881557c8
	if (ctx.cr6.eq) goto loc_881557C8;
	// stw r8,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r8.u32);
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// b 0x881557d0
	goto loc_881557D0;
loc_881557C8:
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r11.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
loc_881557D0:
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
	// stw r5,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r5.u32);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// stw r5,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r5.u32);
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// stw r10,60(r11)
	PPC_STORE_U32(ctx.r11.u32 + 60, ctx.r10.u32);
	// stw r10,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r10.u32);
	// stw r10,56(r11)
	PPC_STORE_U32(ctx.r11.u32 + 56, ctx.r10.u32);
	// stw r10,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r10.u32);
	// stw r10,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r10.u32);
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
	// stw r4,48(r11)
	PPC_STORE_U32(ctx.r11.u32 + 48, ctx.r4.u32);
loc_88155804:
	// addi r11,r9,1
	ctx.r11.s64 = ctx.r9.s64 + 1;
	// li r9,3000
	ctx.r9.s64 = 3000;
	// rlwinm r28,r11,1,31,31
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// subfc r27,r9,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r9.u32;
	ctx.r27.s64 = ctx.r11.s64 - ctx.r9.s64;
	// rlwinm r9,r9,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// subfe r9,r28,r9
	temp.u8 = (~ctx.r28.u32 + ctx.r9.u32 < ~ctx.r28.u32) | (~ctx.r28.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r28.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 & ctx.r11.u64;
	// bne cr6,0x8815579c
	if (!ctx.cr6.eq) goto loc_8815579C;
	// stw r9,528(r30)
	PPC_STORE_U32(ctx.r30.u32 + 528, ctx.r9.u32);
	// stw r29,-12396(r6)
	PPC_STORE_U32(ctx.r6.u32 + -12396, ctx.r29.u32);
	// bl 0x88155218
	ctx.lr = 0x88155834;
	sub_88155218(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8815583C"))) PPC_WEAK_FUNC(sub_8815583C);
PPC_FUNC_IMPL(__imp__sub_8815583C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88155840"))) PPC_WEAK_FUNC(sub_88155840);
PPC_FUNC_IMPL(__imp__sub_88155840) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x88155848;
	__savegprlr_24(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// addi r27,r11,208
	ctx.r27.s64 = ctx.r11.s64 + 208;
	// addi r9,r10,26432
	ctx.r9.s64 = ctx.r10.s64 + 26432;
	// lis r8,-30597
	ctx.r8.s64 = -2005204992;
	// addi r7,r8,-13948
	ctx.r7.s64 = ctx.r8.s64 + -13948;
	// lwz r11,276(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 276);
	// lwz r9,324(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 324);
	// addi r3,r11,1448
	ctx.r3.s64 = ctx.r11.s64 + 1448;
	// addi r10,r11,1644
	ctx.r10.s64 = ctx.r11.s64 + 1644;
	// lwz r11,88(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// stw r3,268(r27)
	PPC_STORE_U32(ctx.r27.u32 + 268, ctx.r3.u32);
	// stw r10,272(r27)
	PPC_STORE_U32(ctx.r27.u32 + 272, ctx.r10.u32);
	// stw r9,-13948(r8)
	PPC_STORE_U32(ctx.r8.u32 + -13948, ctx.r9.u32);
	// stw r11,-4(r7)
	PPC_STORE_U32(ctx.r7.u32 + -4, ctx.r11.u32);
	// bl 0x881344b8
	ctx.lr = 0x8815588C;
	sub_881344B8(ctx, base);
	// lwz r11,272(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 272);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x881344b8
	ctx.lr = 0x8815589C;
	sub_881344B8(ctx, base);
	// lwz r11,4(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88155a20
	if (ctx.cr6.eq) goto loc_88155A20;
loc_881558B0:
	// lwz r11,8(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88155a14
	if (ctx.cr6.eq) goto loc_88155A14;
	// lwz r29,28(r28)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r28.u32 + 28);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x88155a14
	if (ctx.cr6.eq) goto loc_88155A14;
loc_881558C8:
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88155a08
	if (ctx.cr6.eq) goto loc_88155A08;
	// lhz r10,52(r29)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r29.u32 + 52);
	// addi r11,r29,24
	ctx.r11.s64 = ctx.r29.s64 + 24;
	// lhz r9,56(r29)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r29.u32 + 56);
	// lwz r8,60(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 60);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// extsh r31,r9
	ctx.r31.s64 = ctx.r9.s16;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x88155910
	if (ctx.cr6.eq) goto loc_88155910;
	// lwz r9,36(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// lhz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 0);
	// lhz r7,4(r9)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// extsh r9,r8
	ctx.r9.s64 = ctx.r8.s16;
	// extsh r8,r7
	ctx.r8.s64 = ctx.r7.s16;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r31,r8,r31
	ctx.r31.u64 = ctx.r8.u64 + ctx.r31.u64;
loc_88155910:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r7,20(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// subf r6,r8,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r8.s64;
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// add r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 + ctx.r10.u64;
	// subf r4,r7,r31
	ctx.r4.s64 = ctx.r31.s64 - ctx.r7.s64;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// add r3,r11,r31
	ctx.r3.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// stw r4,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r4.u32);
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// beq cr6,0x8815596c
	if (ctx.cr6.eq) goto loc_8815596C;
	// li r10,8
	ctx.r10.s64 = 8;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x881544d8
	ctx.lr = 0x8815596C;
	sub_881544D8(ctx, base);
loc_8815596C:
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// beq cr6,0x88155998
	if (ctx.cr6.eq) goto loc_88155998;
	// li r10,8
	ctx.r10.s64 = 8;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x881544d8
	ctx.lr = 0x88155998;
	sub_881544D8(ctx, base);
loc_88155998:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq cr6,0x881559d0
	if (ctx.cr6.eq) goto loc_881559D0;
	// li r30,0
	ctx.r30.s64 = 0;
loc_881559A4:
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r8,r30,6
	ctx.r8.s64 = ctx.r30.s64 + 6;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x88154298
	ctx.lr = 0x881559C4;
	sub_88154298(ctx, base);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmpwi cr6,r30,5
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 5, ctx.xer);
	// blt cr6,0x881559a4
	if (ctx.cr6.lt) goto loc_881559A4;
loc_881559D0:
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// beq cr6,0x88155a08
	if (ctx.cr6.eq) goto loc_88155A08;
	// li r30,0
	ctx.r30.s64 = 0;
loc_881559DC:
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r8,r30,11
	ctx.r8.s64 = ctx.r30.s64 + 11;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x88154298
	ctx.lr = 0x881559FC;
	sub_88154298(ctx, base);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmpwi cr6,r30,5
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 5, ctx.xer);
	// blt cr6,0x881559dc
	if (ctx.cr6.lt) goto loc_881559DC;
loc_88155A08:
	// lwz r29,0(r29)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x881558c8
	if (!ctx.cr6.eq) goto loc_881558C8;
loc_88155A14:
	// lwz r28,0(r28)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x881558b0
	if (!ctx.cr6.eq) goto loc_881558B0;
loc_88155A20:
	// lwz r28,16(r27)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r27.u32 + 16);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x88155bac
	if (ctx.cr6.eq) goto loc_88155BAC;
loc_88155A2C:
	// lwz r11,8(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88155ba0
	if (ctx.cr6.eq) goto loc_88155BA0;
	// lwz r29,28(r28)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r28.u32 + 28);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x88155ba0
	if (ctx.cr6.eq) goto loc_88155BA0;
loc_88155A44:
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88155b94
	if (ctx.cr6.eq) goto loc_88155B94;
	// lhz r10,52(r29)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r29.u32 + 52);
	// addi r11,r29,24
	ctx.r11.s64 = ctx.r29.s64 + 24;
	// lhz r9,56(r29)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r29.u32 + 56);
	// lwz r8,60(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 60);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// extsh r31,r9
	ctx.r31.s64 = ctx.r9.s16;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x88155a8c
	if (ctx.cr6.eq) goto loc_88155A8C;
	// lwz r9,36(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// lhz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 0);
	// lhz r7,4(r9)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// extsh r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	// extsh r9,r7
	ctx.r9.s64 = ctx.r7.s16;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r31,r9,r31
	ctx.r31.u64 = ctx.r9.u64 + ctx.r31.u64;
loc_88155A8C:
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// add r3,r9,r10
	ctx.r3.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r5,20(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// rlwinm r6,r8,0,30,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x2;
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r4,r7,r10
	ctx.r4.s64 = ctx.r10.s64 - ctx.r7.s64;
	// subf r10,r5,r31
	ctx.r10.s64 = ctx.r31.s64 - ctx.r5.s64;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// add r9,r11,r31
	ctx.r9.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// bne cr6,0x88155b94
	if (!ctx.cr6.eq) goto loc_88155B94;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq cr6,0x88155af8
	if (ctx.cr6.eq) goto loc_88155AF8;
	// li r10,2048
	ctx.r10.s64 = 2048;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x881544d8
	ctx.lr = 0x88155AF8;
	sub_881544D8(ctx, base);
loc_88155AF8:
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// beq cr6,0x88155b24
	if (ctx.cr6.eq) goto loc_88155B24;
	// li r10,2048
	ctx.r10.s64 = 2048;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x881544d8
	ctx.lr = 0x88155B24;
	sub_881544D8(ctx, base);
loc_88155B24:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq cr6,0x88155b5c
	if (ctx.cr6.eq) goto loc_88155B5C;
	// li r30,0
	ctx.r30.s64 = 0;
loc_88155B30:
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r30,6
	ctx.r8.s64 = ctx.r30.s64 + 6;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x88154298
	ctx.lr = 0x88155B50;
	sub_88154298(ctx, base);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmpwi cr6,r30,5
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 5, ctx.xer);
	// blt cr6,0x88155b30
	if (ctx.cr6.lt) goto loc_88155B30;
loc_88155B5C:
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// beq cr6,0x88155b94
	if (ctx.cr6.eq) goto loc_88155B94;
	// li r30,0
	ctx.r30.s64 = 0;
loc_88155B68:
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r30,11
	ctx.r8.s64 = ctx.r30.s64 + 11;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x88154298
	ctx.lr = 0x88155B88;
	sub_88154298(ctx, base);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmpwi cr6,r30,5
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 5, ctx.xer);
	// blt cr6,0x88155b68
	if (ctx.cr6.lt) goto loc_88155B68;
loc_88155B94:
	// lwz r29,0(r29)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x88155a44
	if (!ctx.cr6.eq) goto loc_88155A44;
loc_88155BA0:
	// lwz r28,0(r28)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x88155a2c
	if (!ctx.cr6.eq) goto loc_88155A2C;
loc_88155BAC:
	// lwz r27,256(r27)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r27.u32 + 256);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x88155dd8
	if (ctx.cr6.eq) goto loc_88155DD8;
loc_88155BB8:
	// lwz r11,8(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88155dcc
	if (ctx.cr6.eq) goto loc_88155DCC;
	// lwz r29,28(r27)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r27.u32 + 28);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x88155dcc
	if (ctx.cr6.eq) goto loc_88155DCC;
loc_88155BD0:
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88155dc0
	if (ctx.cr6.eq) goto loc_88155DC0;
	// lhz r11,52(r29)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r29.u32 + 52);
	// addi r28,r29,24
	ctx.r28.s64 = ctx.r29.s64 + 24;
	// lhz r10,56(r29)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r29.u32 + 56);
	// lwz r9,60(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 60);
	// extsh r26,r11
	ctx.r26.s64 = ctx.r11.s16;
	// extsh r30,r10
	ctx.r30.s64 = ctx.r10.s16;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x88155c18
	if (ctx.cr6.eq) goto loc_88155C18;
	// lwz r11,36(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 36);
	// lhz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + 0);
	// lhz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// extsh r11,r9
	ctx.r11.s64 = ctx.r9.s16;
	// add r26,r10,r26
	ctx.r26.u64 = ctx.r10.u64 + ctx.r26.u64;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
loc_88155C18:
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r9,12(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// rlwinm r8,r11,0,30,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	// lwz r10,8(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8);
	// lwz r7,20(r28)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r28.u32 + 20);
	// subf r6,r9,r26
	ctx.r6.s64 = ctx.r26.s64 - ctx.r9.s64;
	// lwz r11,16(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// add r5,r10,r26
	ctx.r5.u64 = ctx.r10.u64 + ctx.r26.u64;
	// subf r4,r7,r30
	ctx.r4.s64 = ctx.r30.s64 - ctx.r7.s64;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// add r3,r11,r30
	ctx.r3.u64 = ctx.r11.u64 + ctx.r30.u64;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// stw r4,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r4.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// bne cr6,0x88155d20
	if (!ctx.cr6.eq) goto loc_88155D20;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq cr6,0x88155c84
	if (ctx.cr6.eq) goto loc_88155C84;
	// li r10,1024
	ctx.r10.s64 = 1024;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,21
	ctx.r8.s64 = 21;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x881544d8
	ctx.lr = 0x88155C84;
	sub_881544D8(ctx, base);
loc_88155C84:
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// beq cr6,0x88155cb0
	if (ctx.cr6.eq) goto loc_88155CB0;
	// li r10,1024
	ctx.r10.s64 = 1024;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,21
	ctx.r8.s64 = 21;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x881544d8
	ctx.lr = 0x88155CB0;
	sub_881544D8(ctx, base);
loc_88155CB0:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq cr6,0x88155ce8
	if (ctx.cr6.eq) goto loc_88155CE8;
	// li r31,0
	ctx.r31.s64 = 0;
loc_88155CBC:
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r8,r31,6
	ctx.r8.s64 = ctx.r31.s64 + 6;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x88154298
	ctx.lr = 0x88155CDC;
	sub_88154298(ctx, base);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmpwi cr6,r31,5
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 5, ctx.xer);
	// blt cr6,0x88155cbc
	if (ctx.cr6.lt) goto loc_88155CBC;
loc_88155CE8:
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// beq cr6,0x88155d20
	if (ctx.cr6.eq) goto loc_88155D20;
	// li r31,0
	ctx.r31.s64 = 0;
loc_88155CF4:
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r8,r31,11
	ctx.r8.s64 = ctx.r31.s64 + 11;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x88154298
	ctx.lr = 0x88155D14;
	sub_88154298(ctx, base);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmpwi cr6,r31,5
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 5, ctx.xer);
	// blt cr6,0x88155cf4
	if (ctx.cr6.lt) goto loc_88155CF4;
loc_88155D20:
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x88155d48
	if (!ctx.cr6.eq) goto loc_88155D48;
	// li r7,8
	ctx.r7.s64 = 8;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x88153ee0
	ctx.lr = 0x88155D48;
	sub_88153EE0(ctx, base);
loc_88155D48:
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x88155d70
	if (!ctx.cr6.eq) goto loc_88155D70;
	// li r7,2048
	ctx.r7.s64 = 2048;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x88153ee0
	ctx.lr = 0x88155D70;
	sub_88153EE0(ctx, base);
loc_88155D70:
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x88155d98
	if (!ctx.cr6.eq) goto loc_88155D98;
	// li r7,2048
	ctx.r7.s64 = 2048;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,21
	ctx.r3.s64 = 21;
	// bl 0x88153ee0
	ctx.lr = 0x88155D98;
	sub_88153EE0(ctx, base);
loc_88155D98:
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x88155dc0
	if (!ctx.cr6.eq) goto loc_88155DC0;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x881540e0
	ctx.lr = 0x88155DC0;
	sub_881540E0(ctx, base);
loc_88155DC0:
	// lwz r29,0(r29)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x88155bd0
	if (!ctx.cr6.eq) goto loc_88155BD0;
loc_88155DCC:
	// lwz r27,0(r27)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// bne cr6,0x88155bb8
	if (!ctx.cr6.eq) goto loc_88155BB8;
loc_88155DD8:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88155DE0"))) PPC_WEAK_FUNC(sub_88155DE0);
PPC_FUNC_IMPL(__imp__sub_88155DE0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807113c
	ctx.lr = 0x88155DE8;
	__savegprlr_21(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x881550b8
	ctx.lr = 0x88155DF0;
	sub_881550B8(ctx, base);
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// addi r31,r11,532
	ctx.r31.s64 = ctx.r11.s64 + 532;
	// addi r11,r31,-324
	ctx.r11.s64 = ctx.r31.s64 + -324;
	// addi r3,r11,252
	ctx.r3.s64 = ctx.r11.s64 + 252;
	// bl 0x88154f60
	ctx.lr = 0x88155E04;
	sub_88154F60(ctx, base);
	// addi r11,r31,-324
	ctx.r11.s64 = ctx.r31.s64 + -324;
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// addi r3,r11,228
	ctx.r3.s64 = ctx.r11.s64 + 228;
	// bl 0x88154f60
	ctx.lr = 0x88155E14;
	sub_88154F60(ctx, base);
	// addi r11,r31,-324
	ctx.r11.s64 = ctx.r31.s64 + -324;
	// add r7,r8,r3
	ctx.r7.u64 = ctx.r8.u64 + ctx.r3.u64;
	// addi r3,r11,216
	ctx.r3.s64 = ctx.r11.s64 + 216;
	// bl 0x88154f60
	ctx.lr = 0x88155E24;
	sub_88154F60(ctx, base);
	// addi r11,r31,-324
	ctx.r11.s64 = ctx.r31.s64 + -324;
	// add r6,r7,r3
	ctx.r6.u64 = ctx.r7.u64 + ctx.r3.u64;
	// addi r3,r11,240
	ctx.r3.s64 = ctx.r11.s64 + 240;
	// bl 0x88154f60
	ctx.lr = 0x88155E34;
	sub_88154F60(ctx, base);
	// addi r11,r31,-324
	ctx.r11.s64 = ctx.r31.s64 + -324;
	// add r5,r6,r3
	ctx.r5.u64 = ctx.r6.u64 + ctx.r3.u64;
	// addi r3,r11,12
	ctx.r3.s64 = ctx.r11.s64 + 12;
	// bl 0x88154f60
	ctx.lr = 0x88155E44;
	sub_88154F60(ctx, base);
	// addi r4,r31,-324
	ctx.r4.s64 = ctx.r31.s64 + -324;
	// add r8,r5,r3
	ctx.r8.u64 = ctx.r5.u64 + ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x88154f60
	ctx.lr = 0x88155E54;
	sub_88154F60(ctx, base);
	// lis r7,-30597
	ctx.r7.s64 = -2005204992;
	// addi r10,r31,-324
	ctx.r10.s64 = ctx.r31.s64 + -324;
	// add r11,r8,r3
	ctx.r11.u64 = ctx.r8.u64 + ctx.r3.u64;
	// addi r3,r10,60
	ctx.r3.s64 = ctx.r10.s64 + 60;
	// stw r11,-11928(r7)
	PPC_STORE_U32(ctx.r7.u32 + -11928, ctx.r11.u32);
	// bl 0x88154f60
	ctx.lr = 0x88155E6C;
	sub_88154F60(ctx, base);
	// addi r11,r31,-324
	ctx.r11.s64 = ctx.r31.s64 + -324;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r3,r11,48
	ctx.r3.s64 = ctx.r11.s64 + 48;
	// bl 0x88154f60
	ctx.lr = 0x88155E7C;
	sub_88154F60(ctx, base);
	// addi r11,r31,-324
	ctx.r11.s64 = ctx.r31.s64 + -324;
	// lis r6,-30597
	ctx.r6.s64 = -2005204992;
	// add r7,r5,r3
	ctx.r7.u64 = ctx.r5.u64 + ctx.r3.u64;
	// addi r8,r11,72
	ctx.r8.s64 = ctx.r11.s64 + 72;
loc_88155E8C:
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// bl 0x88154f60
	ctx.lr = 0x88155E94;
	sub_88154F60(ctx, base);
	// addi r11,r31,-324
	ctx.r11.s64 = ctx.r31.s64 + -324;
	// addi r8,r8,12
	ctx.r8.s64 = ctx.r8.s64 + 12;
	// addi r11,r11,132
	ctx.r11.s64 = ctx.r11.s64 + 132;
	// add r7,r3,r7
	ctx.r7.u64 = ctx.r3.u64 + ctx.r7.u64;
	// cmpw cr6,r8,r11
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x88155e8c
	if (ctx.cr6.lt) goto loc_88155E8C;
	// stw r7,-11924(r6)
	PPC_STORE_U32(ctx.r6.u32 + -11924, ctx.r7.u32);
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26428(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26428);
	// clrlwi r3,r11,31
	ctx.r3.u64 = ctx.r11.u32 & 0x1;
	// bl 0x881553e8
	ctx.lr = 0x88155EC0;
	sub_881553E8(ctx, base);
	// lis r11,-30656
	ctx.r11.s64 = -2009071616;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r28,r11,1504
	ctx.r28.s64 = ctx.r11.s64 + 1504;
	// lwz r9,-48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + -48);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r29,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r29.u32);
	// stw r29,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r29.u32);
	// addi r24,r9,1448
	ctx.r24.s64 = ctx.r9.s64 + 1448;
	// rlwinm r8,r10,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// stw r29,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r29.u32);
	// stw r29,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r29.u32);
	// addi r23,r9,1644
	ctx.r23.s64 = ctx.r9.s64 + 1644;
	// stw r29,44(r28)
	PPC_STORE_U32(ctx.r28.u32 + 44, ctx.r29.u32);
	// stw r29,48(r28)
	PPC_STORE_U32(ctx.r28.u32 + 48, ctx.r29.u32);
	// stw r29,52(r28)
	PPC_STORE_U32(ctx.r28.u32 + 52, ctx.r29.u32);
	// stw r29,56(r28)
	PPC_STORE_U32(ctx.r28.u32 + 56, ctx.r29.u32);
	// stw r29,60(r28)
	PPC_STORE_U32(ctx.r28.u32 + 60, ctx.r29.u32);
	// stw r29,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r29.u32);
	// lwz r11,-356(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -356);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// subfic r7,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r7.s64 = 0 - ctx.r11.s64;
	// rlwinm r6,r11,1,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addme r5,r6
	{ uint8_t _ca = (ctx.r6.u32 + 0xFFFFFFFF < ctx.r6.u32) | (ctx.r6.u32 + 0xFFFFFFFF + ctx.xer.ca < ctx.xer.ca); // FIX 2026-07-24: insn was silently dropped by the recompiler
	ctx.r5.u64 = ctx.r6.u64 + 0xFFFFFFFFFFFFFFFFull + ctx.xer.ca;
	ctx.xer.ca = _ca; }
	// subfic r4,r10,0
	ctx.xer.ca = ctx.r10.u32 <= 0;
	ctx.r4.s64 = 0 - ctx.r10.s64;
	// and r11,r5,r11
	ctx.r11.u64 = ctx.r5.u64 & ctx.r11.u64;
	// addme r3,r8
	{ uint8_t _ca = (ctx.r8.u32 + 0xFFFFFFFF < ctx.r8.u32) | (ctx.r8.u32 + 0xFFFFFFFF + ctx.xer.ca < ctx.xer.ca); // FIX 2026-07-24: insn was silently dropped by the recompiler
	ctx.r3.u64 = ctx.r8.u64 + 0xFFFFFFFFFFFFFFFFull + ctx.xer.ca;
	ctx.xer.ca = _ca; }
	// stw r11,-356(r31)
	PPC_STORE_U32(ctx.r31.u32 + -356, ctx.r11.u32);
	// and r11,r3,r10
	ctx.r11.u64 = ctx.r3.u64 & ctx.r10.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// bl 0x88155840
	ctx.lr = 0x88155F3C;
	sub_88155840(ctx, base);
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// addi r10,r11,26432
	ctx.r10.s64 = ctx.r11.s64 + 26432;
	// li r25,4
	ctx.r25.s64 = 4;
	// li r22,100
	ctx.r22.s64 = 100;
	// li r21,1
	ctx.r21.s64 = 1;
	// lwz r26,324(r10)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r10.u32 + 324);
loc_88155F58:
	// addi r10,r31,24
	ctx.r10.s64 = ctx.r31.s64 + 24;
	// lwzx r11,r30,r10
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88156004
	if (ctx.cr6.eq) goto loc_88156004;
	// addi r27,r31,-44
	ctx.r27.s64 = ctx.r31.s64 + -44;
	// lwzx r11,r30,r27
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r27.u32);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x88156004
	if (ctx.cr6.eq) goto loc_88156004;
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x88156004
	if (ctx.cr6.eq) goto loc_88156004;
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// addi r7,r31,-24
	ctx.r7.s64 = ctx.r31.s64 + -24;
	// addi r8,r28,24
	ctx.r8.s64 = ctx.r28.s64 + 24;
	// ori r6,r9,4
	ctx.r6.u64 = ctx.r9.u64 | 4;
	// cmpwi cr6,r26,2
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 2, ctx.xer);
	// stw r6,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r6.u32);
	// lwzx r11,r30,r7
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r7.u32);
	// lwzx r5,r30,r8
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r8.u32);
	// stw r24,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r24.u32);
	// stw r25,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r25.u32);
	// stw r5,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r5.u32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bne cr6,0x88155fcc
	if (!ctx.cr6.eq) goto loc_88155FCC;
	// mulli r11,r11,70
	ctx.r11.s64 = ctx.r11.s64 * 70;
	// divwu. r11,r11,r22
	ctx.r11.u32 = ppc_divwu(ctx.r11.u32, ctx.r22.u32);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bne 0x88155fcc
	if (!ctx.cr0.eq) goto loc_88155FCC;
	// stw r21,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r21.u32);
loc_88155FCC:
	// lwzx r11,r30,r10
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r10.u32);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x88156004
	if (ctx.cr6.eq) goto loc_88156004;
	// lwzx r9,r30,r27
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r27.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r5,36(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// addi r4,r9,24
	ctx.r4.s64 = ctx.r9.s64 + 24;
	// bctrl 
	ctx.lr = 0x88155FF4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88156004
	if (!ctx.cr6.eq) goto loc_88156004;
	// lwzx r11,r30,r27
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r27.u32);
	// stw r29,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r29.u32);
loc_88156004:
	// addi r10,r28,44
	ctx.r10.s64 = ctx.r28.s64 + 44;
	// lwzx r11,r30,r10
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x881560a8
	if (ctx.cr6.eq) goto loc_881560A8;
	// addi r27,r31,-344
	ctx.r27.s64 = ctx.r31.s64 + -344;
	// lwzx r11,r30,r27
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r27.u32);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x881560a8
	if (ctx.cr6.eq) goto loc_881560A8;
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x881560a8
	if (ctx.cr6.eq) goto loc_881560A8;
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r26,2
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 2, ctx.xer);
	// ori r8,r9,4
	ctx.r8.u64 = ctx.r9.u64 | 4;
	// stw r8,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r8.u32);
	// lwzx r7,r30,r31
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r31.u32);
	// lwzx r11,r30,r28
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r28.u32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// stw r23,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r23.u32);
	// stw r25,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r25.u32);
	// stw r7,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r7.u32);
	// bne cr6,0x88156070
	if (!ctx.cr6.eq) goto loc_88156070;
	// mulli r11,r11,70
	ctx.r11.s64 = ctx.r11.s64 * 70;
	// divwu. r11,r11,r22
	ctx.r11.u32 = ppc_divwu(ctx.r11.u32, ctx.r22.u32);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bne 0x88156070
	if (!ctx.cr0.eq) goto loc_88156070;
	// stw r21,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r21.u32);
loc_88156070:
	// lwzx r11,r30,r10
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r10.u32);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x881560a8
	if (ctx.cr6.eq) goto loc_881560A8;
	// lwzx r9,r30,r27
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r27.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r5,36(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// addi r4,r9,24
	ctx.r4.s64 = ctx.r9.s64 + 24;
	// bctrl 
	ctx.lr = 0x88156098;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x881560a8
	if (!ctx.cr6.eq) goto loc_881560A8;
	// lwzx r11,r30,r27
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r27.u32);
	// stw r29,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r29.u32);
loc_881560A8:
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// cmpwi cr6,r30,20
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 20, ctx.xer);
	// blt cr6,0x88155f58
	if (ctx.cr6.lt) goto loc_88155F58;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8807118c
	__restgprlr_21(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_881560BC"))) PPC_WEAK_FUNC(sub_881560BC);
PPC_FUNC_IMPL(__imp__sub_881560BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881560C0"))) PPC_WEAK_FUNC(sub_881560C0);
PPC_FUNC_IMPL(__imp__sub_881560C0) {
	PPC_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x881560C8;
	__savegprlr_29(ctx, base);
	// lhz r11,50(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 50);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r9,20(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// lis r5,-30671
	ctx.r5.s64 = -2010054656;
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// addi r10,r5,4456
	ctx.r10.s64 = ctx.r5.s64 + 4456;
	// srawi r7,r3,3
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7) != 0);
	ctx.r7.s64 = ctx.r3.s32 >> 3;
	// rlwinm r5,r11,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x7FC;
	// lwz r8,24(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24);
	// rlwinm r7,r7,2,24,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFC;
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// addi r31,r10,2
	ctx.r31.s64 = ctx.r10.s64 + 2;
	// lis r4,-30714
	ctx.r4.s64 = -2012872704;
	// addi r3,r11,128
	ctx.r3.s64 = ctx.r11.s64 + 128;
	// lhzx r10,r7,r10
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + ctx.r10.u32);
	// addi r11,r4,9552
	ctx.r11.s64 = ctx.r4.s64 + 9552;
	// rlwinm r4,r3,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x7FC;
	// li r30,2719
	ctx.r30.s64 = 2719;
	// li r29,1
	ctx.r29.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// sth r10,12(r6)
	PPC_STORE_U16(ctx.r6.u32 + 12, ctx.r10.u16);
	// lhzx r10,r7,r31
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + ctx.r31.u32);
	// lhz r7,12(r6)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r6.u32 + 12);
	// stb r10,10(r6)
	PPC_STORE_U8(ctx.r6.u32 + 10, ctx.r10.u8);
	// lwzx r4,r4,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r11.u32);
	// lwzx r11,r5,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r11.u32);
	// rlwinm r10,r11,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 6) & 0xFFFFFFC0;
	// rotlwi r11,r7,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// sth r30,14(r6)
	PPC_STORE_U16(ctx.r6.u32 + 14, ctx.r30.u16);
	// rlwinm r7,r4,6,0,25
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 6) & 0xFFFFFFC0;
	// stb r29,41(r6)
	PPC_STORE_U8(ctx.r6.u32 + 41, ctx.r29.u8);
	// addi r5,r11,2431
	ctx.r5.s64 = ctx.r11.s64 + 2431;
	// add r4,r10,r9
	ctx.r4.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r11,r7,r8
	ctx.r11.u64 = ctx.r7.u64 + ctx.r8.u64;
	// sth r5,12(r6)
	PPC_STORE_U16(ctx.r6.u32 + 12, ctx.r5.u16);
	// stw r4,20(r6)
	PPC_STORE_U32(ctx.r6.u32 + 20, ctx.r4.u32);
	// stw r11,24(r6)
	PPC_STORE_U32(ctx.r6.u32 + 24, ctx.r11.u32);
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88156160"))) PPC_WEAK_FUNC(sub_88156160);
PPC_FUNC_IMPL(__imp__sub_88156160) {
	PPC_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88156168;
	__savegprlr_28(ctx, base);
	// lhz r5,50(r3)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r3.u32 + 50);
	// lis r4,-30714
	ctx.r4.s64 = -2012872704;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r9,24(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// clrlwi r11,r5,23
	ctx.r11.u64 = ctx.r5.u32 & 0x1FF;
	// lwz r7,20(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// addi r3,r4,9552
	ctx.r3.s64 = ctx.r4.s64 + 9552;
	// addi r8,r11,128
	ctx.r8.s64 = ctx.r11.s64 + 128;
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r4,r8,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x7FC;
	// li r8,2719
	ctx.r8.s64 = 2719;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r31,372
	ctx.r31.s64 = 372;
	// lwzx r5,r5,r3
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r3.u32);
	// li r30,47
	ctx.r30.s64 = 47;
	// lwzx r4,r4,r3
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r3.u32);
	// li r29,128
	ctx.r29.s64 = 128;
	// rlwinm r11,r5,6,0,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 6) & 0xFFFFFFC0;
	// sth r8,14(r6)
	PPC_STORE_U16(ctx.r6.u32 + 14, ctx.r8.u16);
	// rlwinm r8,r4,6,0,25
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 6) & 0xFFFFFFC0;
	// sth r31,12(r6)
	PPC_STORE_U16(ctx.r6.u32 + 12, ctx.r31.u16);
	// add r3,r11,r7
	ctx.r3.u64 = ctx.r11.u64 + ctx.r7.u64;
	// stb r30,11(r6)
	PPC_STORE_U8(ctx.r6.u32 + 11, ctx.r30.u8);
	// li r28,10
	ctx.r28.s64 = 10;
	// stb r10,41(r6)
	PPC_STORE_U8(ctx.r6.u32 + 41, ctx.r10.u8);
	// add r11,r8,r9
	ctx.r11.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stw r3,20(r6)
	PPC_STORE_U32(ctx.r6.u32 + 20, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r29,72(r6)
	PPC_STORE_U32(ctx.r6.u32 + 72, ctx.r29.u32);
	// stw r11,24(r6)
	PPC_STORE_U32(ctx.r6.u32 + 24, ctx.r11.u32);
	// stw r10,76(r6)
	PPC_STORE_U32(ctx.r6.u32 + 76, ctx.r10.u32);
	// stw r28,80(r6)
	PPC_STORE_U32(ctx.r6.u32 + 80, ctx.r28.u32);
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_881561EC"))) PPC_WEAK_FUNC(sub_881561EC);
PPC_FUNC_IMPL(__imp__sub_881561EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881561F0"))) PPC_WEAK_FUNC(sub_881561F0);
PPC_FUNC_IMPL(__imp__sub_881561F0) {
	PPC_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x881561F8;
	__savegprlr_28(ctx, base);
	// lhz r11,50(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 50);
	// lis r5,-30671
	ctx.r5.s64 = -2010054656;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lhz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r3.u32 + 16);
	// addi r7,r11,4
	ctx.r7.s64 = ctx.r11.s64 + 4;
	// addi r10,r5,4456
	ctx.r10.s64 = ctx.r5.s64 + 4456;
	// srawi r5,r7,3
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7) != 0);
	ctx.r5.s64 = ctx.r7.s32 >> 3;
	// rlwinm r31,r11,2,21,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x7FC;
	// rlwinm r5,r5,2,24,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFC;
	// lwz r9,80(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 80);
	// addi r30,r10,2
	ctx.r30.s64 = ctx.r10.s64 + 2;
	// lwz r8,20(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// lwz r7,24(r6)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24);
	// lis r4,-30714
	ctx.r4.s64 = -2012872704;
	// addi r29,r11,128
	ctx.r29.s64 = ctx.r11.s64 + 128;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lhzx r3,r5,r30
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r5.u32 + ctx.r30.u32);
	// rlwinm r30,r29,2,21,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0x7FC;
	// addi r4,r4,9552
	ctx.r4.s64 = ctx.r4.s64 + 9552;
	// add r29,r9,r11
	ctx.r29.u64 = ctx.r9.u64 + ctx.r11.u64;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,2719
	ctx.r3.s64 = 2719;
	// stb r11,10(r6)
	PPC_STORE_U8(ctx.r6.u32 + 10, ctx.r11.u8);
	// li r28,1
	ctx.r28.s64 = 1;
	// lwzx r9,r30,r4
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r4.u32);
	// rlwinm r9,r9,6,0,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0xFFFFFFC0;
	// lwzx r4,r31,r4
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r4.u32);
	// rlwinm r11,r4,6,0,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 6) & 0xFFFFFFC0;
	// sth r3,14(r6)
	PPC_STORE_U16(ctx.r6.u32 + 14, ctx.r3.u16);
	// add r3,r11,r8
	ctx.r3.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r11,r9,r7
	ctx.r11.u64 = ctx.r9.u64 + ctx.r7.u64;
	// stw r3,20(r6)
	PPC_STORE_U32(ctx.r6.u32 + 20, ctx.r3.u32);
	// li r30,48
	ctx.r30.s64 = 48;
	// stw r11,24(r6)
	PPC_STORE_U32(ctx.r6.u32 + 24, ctx.r11.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// lhzx r11,r5,r10
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r5.u32 + ctx.r10.u32);
	// addi r7,r11,859
	ctx.r7.s64 = ctx.r11.s64 + 859;
	// rlwinm r5,r7,2,16,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFC;
	// stb r28,41(r6)
	PPC_STORE_U8(ctx.r6.u32 + 41, ctx.r28.u8);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r30,11(r6)
	PPC_STORE_U8(ctx.r6.u32 + 11, ctx.r30.u8);
	// stw r9,72(r6)
	PPC_STORE_U32(ctx.r6.u32 + 72, ctx.r9.u32);
	// sth r29,16(r6)
	PPC_STORE_U16(ctx.r6.u32 + 16, ctx.r29.u16);
	// sth r5,12(r6)
	PPC_STORE_U16(ctx.r6.u32 + 12, ctx.r5.u16);
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_881562B0"))) PPC_WEAK_FUNC(sub_881562B0);
PPC_FUNC_IMPL(__imp__sub_881562B0) {
	PPC_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x881562B8;
	__savegprlr_27(ctx, base);
	// lhz r10,50(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 50);
	// lis r9,-30671
	ctx.r9.s64 = -2010054656;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r6,24(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r4,r10,4
	ctx.r4.s64 = ctx.r10.s64 + 4;
	// lwz r8,20(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r5,140(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// addi r9,r9,4456
	ctx.r9.s64 = ctx.r9.s64 + 4456;
	// srawi r3,r4,3
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7) != 0);
	ctx.r3.s64 = ctx.r4.s32 >> 3;
	// rlwinm r30,r10,2,21,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0x7FC;
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// rlwinm r4,r3,2,24,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFC;
	// clrlwi r10,r10,23
	ctx.r10.u64 = ctx.r10.u32 & 0x1FF;
	// lis r7,-30714
	ctx.r7.s64 = -2012872704;
	// addi r10,r10,128
	ctx.r10.s64 = ctx.r10.s64 + 128;
	// addi r3,r7,9552
	ctx.r3.s64 = ctx.r7.s64 + 9552;
	// lhzx r9,r4,r9
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r4.u32 + ctx.r9.u32);
	// rlwinm r7,r10,2,21,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0x7FC;
	// lis r29,-30658
	ctx.r29.s64 = -2009202688;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r31,1
	ctx.r31.s64 = 1;
	// li r28,2719
	ctx.r28.s64 = 2719;
	// stb r9,10(r11)
	PPC_STORE_U8(ctx.r11.u32 + 10, ctx.r9.u8);
	// li r27,372
	ctx.r27.s64 = 372;
	// lwzx r9,r7,r3
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r3.u32);
	// rlwinm r9,r9,6,0,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0xFFFFFFC0;
	// lwzx r7,r30,r3
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r3.u32);
	// li r3,48
	ctx.r3.s64 = 48;
	// lwz r10,156(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 156);
	// rlwinm r7,r7,6,0,25
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 6) & 0xFFFFFFC0;
	// add r9,r9,r6
	ctx.r9.u64 = ctx.r9.u64 + ctx.r6.u64;
	// stb r3,11(r11)
	PPC_STORE_U8(ctx.r11.u32 + 11, ctx.r3.u8);
	// neg r6,r10
	ctx.r6.s64 = -ctx.r10.s64;
	// sth r28,14(r11)
	PPC_STORE_U16(ctx.r11.u32 + 14, ctx.r28.u16);
	// li r10,17
	ctx.r10.s64 = 17;
	// stw r9,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r9.u32);
	// add r3,r7,r8
	ctx.r3.u64 = ctx.r7.u64 + ctx.r8.u64;
	// sth r27,12(r11)
	PPC_STORE_U16(ctx.r11.u32 + 12, ctx.r27.u16);
	// stb r31,41(r11)
	PPC_STORE_U8(ctx.r11.u32 + 41, ctx.r31.u8);
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// stw r3,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r3.u32);
	// stw r10,80(r11)
	PPC_STORE_U32(ctx.r11.u32 + 80, ctx.r10.u32);
	// stw r6,84(r11)
	PPC_STORE_U32(ctx.r11.u32 + 84, ctx.r6.u32);
	// stw r4,108(r11)
	PPC_STORE_U32(ctx.r11.u32 + 108, ctx.r4.u32);
	// lwz r10,28(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 28);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x881563a0
	if (ctx.cr6.eq) goto loc_881563A0;
loc_88156374:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x88156390
	if (ctx.cr6.eq) goto loc_88156390;
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x88156374
	if (!ctx.cr6.eq) goto loc_88156374;
	// b 0x881563a0
	goto loc_881563A0;
loc_88156390:
	// lwz r9,24(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x881563a0
	if (ctx.cr6.eq) goto loc_881563A0;
	// stw r9,64(r10)
	PPC_STORE_U32(ctx.r10.u32 + 64, ctx.r9.u32);
loc_881563A0:
	// lwz r10,140(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 140);
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// lwz r10,28(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x881563cc
	if (ctx.cr6.eq) goto loc_881563CC;
loc_881563B4:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x881563cc
	if (ctx.cr6.eq) goto loc_881563CC;
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x881563b4
	if (!ctx.cr6.eq) goto loc_881563B4;
loc_881563CC:
	// stw r4,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r4.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lhz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + 16);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r31,104(r11)
	PPC_STORE_U32(ctx.r11.u32 + 104, ctx.r31.u32);
	// sth r9,16(r11)
	PPC_STORE_U16(ctx.r11.u32 + 16, ctx.r9.u16);
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_881563E8"))) PPC_WEAK_FUNC(sub_881563E8);
PPC_FUNC_IMPL(__imp__sub_881563E8) {
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
	// bl 0x881562b0
	ctx.lr = 0x88156400;
	sub_881562B0(ctx, base);
	// li r11,-2
	ctx.r11.s64 = -2;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// lhz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// addi r9,r11,-3
	ctx.r9.s64 = ctx.r11.s64 + -3;
	// sth r9,16(r31)
	PPC_STORE_U16(ctx.r31.u32 + 16, ctx.r9.u16);
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

__attribute__((alias("__imp__sub_8815642C"))) PPC_WEAK_FUNC(sub_8815642C);
PPC_FUNC_IMPL(__imp__sub_8815642C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88156430"))) PPC_WEAK_FUNC(sub_88156430);
PPC_FUNC_IMPL(__imp__sub_88156430) {
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
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lbz r9,40(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 40);
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r8,20(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// lwz r9,28(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// stw r5,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r5.u32);
	// addi r7,r11,-1
	ctx.r7.s64 = ctx.r11.s64 + -1;
	// add r4,r9,r8
	ctx.r4.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsb r6,r7
	ctx.r6.s64 = ctx.r7.s8;
	// stw r4,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r4.u32);
	// stb r6,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, ctx.r6.u8);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bge cr6,0x8815649c
	if (!ctx.cr6.lt) goto loc_8815649C;
	// lbz r11,11(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 11);
	// lbz r10,41(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 41);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// clrlwi r8,r9,30
	ctx.r8.u64 = ctx.r9.u32 & 0x3;
	// stb r10,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, ctx.r10.u8);
	// stb r8,11(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11, ctx.r8.u8);
loc_8815649C:
	// lbz r10,11(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lhz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// extsh r6,r9
	ctx.r6.s64 = ctx.r9.s16;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x881564B8;
	sub_881538C0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// beq cr6,0x881564dc
	if (ctx.cr6.eq) goto loc_881564DC;
	// lbz r10,10(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm r8,r10,26,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 26) & 0xFFFFFFFC;
	// or r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 | ctx.r9.u64;
	// stw r7,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
loc_881564DC:
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

__attribute__((alias("__imp__sub_881564F0"))) PPC_WEAK_FUNC(sub_881564F0);
PPC_FUNC_IMPL(__imp__sub_881564F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x881564F8;
	__savegprlr_28(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// srawi r7,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r7.s64 = ctx.r11.s32 >> 1;
	// lwz r8,24(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r9,28(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// addze r7,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r7.s64 = temp.s64;
	// lhz r6,16(r3)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r3.u32 + 16);
	// add r4,r9,r10
	ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lbz r3,11(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 11);
	// add r5,r7,r8
	ctx.r5.u64 = ctx.r7.u64 + ctx.r8.u64;
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// stw r4,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r4.u32);
	// extsh r10,r6
	ctx.r10.s64 = ctx.r6.s16;
	// stw r5,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r5.u32);
	// addi r6,r10,3
	ctx.r6.s64 = ctx.r10.s64 + 3;
	// extsb r10,r3
	ctx.r10.s64 = ctx.r3.s8;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x88156548;
	sub_881538C0(ctx, base);
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// lis r30,-30597
	ctx.r30.s64 = -2005204992;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x8815658c
	if (ctx.cr6.eq) goto loc_8815658C;
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,-11932(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -11932);
	// lis r7,128
	ctx.r7.s64 = 8388608;
	// rlwimi r9,r11,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// ori r6,r7,8224
	ctx.r6.u64 = ctx.r7.u64 | 8224;
	// addi r29,r10,1
	ctx.r29.s64 = ctx.r10.s64 + 1;
	// or r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 | ctx.r8.u64;
	// stw r6,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r6.u32);
	// stw r29,-11932(r30)
	PPC_STORE_U32(ctx.r30.u32 + -11932, ctx.r29.u32);
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// b 0x88156590
	goto loc_88156590;
loc_8815658C:
	// lwz r29,-11932(r30)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r30.u32 + -11932);
loc_88156590:
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// lhz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// extsh r11,r9
	ctx.r11.s64 = ctx.r9.s16;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addi r6,r11,3
	ctx.r6.s64 = ctx.r11.s64 + 3;
	// lwz r28,26428(r10)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26428);
	// clrlwi r11,r28,27
	ctx.r11.u64 = ctx.r28.u32 & 0x1F;
	// addi r3,r11,5260
	ctx.r3.s64 = ctx.r11.s64 + 5260;
	// bl 0x881538c0
	ctx.lr = 0x881565B8;
	sub_881538C0(ctx, base);
	// lwz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r8,24
	ctx.r11.u64 = ctx.r8.u32 & 0xFF;
	// beq cr6,0x881565e4
	if (ctx.cr6.eq) goto loc_881565E4;
	// lis r9,547
	ctx.r9.s64 = 35848192;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r10,r29,1
	ctx.r10.s64 = ctx.r29.s64 + 1;
	// rlwimi r9,r11,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r10,-11932(r30)
	PPC_STORE_U32(ctx.r30.u32 + -11932, ctx.r10.u32);
	// or r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 | ctx.r8.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
loc_881565E4:
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// bne cr6,0x8815674c
	if (!ctx.cr6.eq) goto loc_8815674C;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// stw r11,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// cmpwi cr6,r11,255
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 255, ctx.xer);
	// blt cr6,0x88156710
	if (ctx.cr6.lt) goto loc_88156710;
	// lhz r11,50(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// li r10,255
	ctx.r10.s64 = 255;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r11,96
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 96, ctx.xer);
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// ble cr6,0x88156644
	if (!ctx.cr6.gt) goto loc_88156644;
	// cmplwi cr6,r11,416
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 416, ctx.xer);
	// bge cr6,0x88156644
	if (!ctx.cr6.lt) goto loc_88156644;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r11,26276(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88156694
	if (!ctx.cr6.eq) goto loc_88156694;
	// li r7,0
	ctx.r7.s64 = 0;
	// b 0x88156660
	goto loc_88156660;
loc_88156644:
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r11,26276(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88156694
	if (!ctx.cr6.eq) goto loc_88156694;
	// li r7,256
	ctx.r7.s64 = 256;
loc_88156660:
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// li r6,-30
	ctx.r6.s64 = -30;
	// li r3,131
	ctx.r3.s64 = 131;
	// sth r29,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r29.u16);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x8815c948
	ctx.lr = 0x88156678;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x8815c860
	ctx.lr = 0x88156684;
	sub_8815C860(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x88156694
	if (ctx.cr6.eq) goto loc_88156694;
	// li r11,2
	ctx.r11.s64 = 2;
	// sth r11,16(r30)
	PPC_STORE_U16(ctx.r30.u32 + 16, ctx.r11.u16);
loc_88156694:
	// lwz r9,140(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r29,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r29.u32);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// stw r11,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// lwz r11,28(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x881566e0
	if (ctx.cr6.eq) goto loc_881566E0;
loc_881566B4:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x881566d0
	if (ctx.cr6.eq) goto loc_881566D0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x881566b4
	if (!ctx.cr6.eq) goto loc_881566B4;
	// b 0x881566e0
	goto loc_881566E0;
loc_881566D0:
	// lwz r10,24(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x881566e0
	if (ctx.cr6.eq) goto loc_881566E0;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_881566E0:
	// lwz r11,140(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8815670c
	if (ctx.cr6.eq) goto loc_8815670C;
loc_881566F4:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8815670c
	if (ctx.cr6.eq) goto loc_8815670C;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x881566f4
	if (!ctx.cr6.eq) goto loc_881566F4;
loc_8815670C:
	// stw r29,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r29.u32);
loc_88156710:
	// clrlwi r11,r28,31
	ctx.r11.u64 = ctx.r28.u32 & 0x1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88156740
	if (!ctx.cr6.eq) goto loc_88156740;
	// lbz r10,11(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// stb r8,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r8.u8);
	// cmpw cr6,r8,r11
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r11.s32, ctx.xer);
	// bgt cr6,0x88156740
	if (ctx.cr6.gt) goto loc_88156740;
	// stb r11,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r11.u8);
loc_88156740:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8815674C:
	// addic. r11,r11,-16
	ctx.xer.ca = ctx.r11.u32 > 15;
	ctx.r11.s64 = ctx.r11.s64 + -16;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// bgt 0x88156710
	if (ctx.cr0.gt) goto loc_88156710;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88156764"))) PPC_WEAK_FUNC(sub_88156764);
PPC_FUNC_IMPL(__imp__sub_88156764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88156768"))) PPC_WEAK_FUNC(sub_88156768);
PPC_FUNC_IMPL(__imp__sub_88156768) {
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
	// lhz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 36);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,64(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// li r8,0
	ctx.r8.s64 = 0;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x881567d0
	if (!ctx.cr6.lt) goto loc_881567D0;
	// lwz r9,56(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r9,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r9.u32);
	// bgt 0x881567d0
	if (ctx.cr0.gt) goto loc_881567D0;
	// lwz r9,52(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// lwz r8,60(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// add r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 + ctx.r10.u64;
	// extsh r6,r7
	ctx.r6.s64 = ctx.r7.s16;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// stw r8,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r8.u32);
	// sth r6,36(r3)
	PPC_STORE_U16(ctx.r3.u32 + 36, ctx.r6.u16);
	// cmpw cr6,r6,r11
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x881567cc
	if (ctx.cr6.lt) goto loc_881567CC;
	// sth r11,36(r3)
	PPC_STORE_U16(ctx.r3.u32 + 36, ctx.r11.u16);
loc_881567CC:
	// li r8,1
	ctx.r8.s64 = 1;
loc_881567D0:
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88156844
	if (ctx.cr6.eq) goto loc_88156844;
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// addic. r11,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r11.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r9,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r9.u32);
	// stw r11,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// bge 0x88156844
	if (!ctx.cr0.lt) goto loc_88156844;
	// lhz r11,50(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// lis r10,-30671
	ctx.r10.s64 = -2010054656;
	// lwz r9,112(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// lwz r8,68(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// addi r10,r10,4456
	ctx.r10.s64 = ctx.r10.s64 + 4456;
	// add r7,r9,r11
	ctx.r7.u64 = ctx.r9.u64 + ctx.r11.u64;
	// addi r6,r10,2
	ctx.r6.s64 = ctx.r10.s64 + 2;
	// clrlwi r11,r7,23
	ctx.r11.u64 = ctx.r7.u32 & 0x1FF;
	// addi r5,r11,4
	ctx.r5.s64 = ctx.r11.s64 + 4;
	// stw r8,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r8.u32);
	// sth r11,50(r31)
	PPC_STORE_U16(ctx.r31.u32 + 50, ctx.r11.u16);
	// srawi r4,r5,3
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7) != 0);
	ctx.r4.s64 = ctx.r5.s32 >> 3;
	// rlwinm r9,r4,2,24,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFC;
	// lhzx r11,r9,r10
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r10.u32);
	// addi r8,r11,859
	ctx.r8.s64 = ctx.r11.s64 + 859;
	// rlwinm r7,r8,2,16,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFC;
	// sth r7,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r7.u16);
	// lhzx r6,r9,r6
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r6.u32);
	// stb r6,10(r31)
	PPC_STORE_U8(ctx.r31.u32 + 10, ctx.r6.u8);
	// b 0x8815684c
	goto loc_8815684C;
loc_88156844:
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x8815689c
	if (ctx.cr6.eq) goto loc_8815689C;
loc_8815684C:
	// lhz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 36);
	// lis r8,-30714
	ctx.r8.s64 = -2012872704;
	// lhz r9,50(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// addic. r11,r31,32
	ctx.xer.ca = ctx.r31.u32 > 4294967263;
	ctx.r11.s64 = ctx.r31.s64 + 32;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r7,r31,28
	ctx.r7.s64 = ctx.r31.s64 + 28;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// clrlwi r9,r9,23
	ctx.r9.u64 = ctx.r9.u32 & 0x1FF;
	// addi r8,r8,9552
	ctx.r8.s64 = ctx.r8.s64 + 9552;
	// beq 0x88156884
	if (ctx.cr0.eq) goto loc_88156884;
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
loc_88156884:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x8815689c
	if (ctx.cr6.eq) goto loc_8815689C;
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r8
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r8.u32);
	// mullw r8,r9,r10
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// stw r8,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r8.u32);
loc_8815689C:
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lbz r9,40(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 40);
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// stw r5,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r5.u32);
	// addi r7,r11,-1
	ctx.r7.s64 = ctx.r11.s64 + -1;
	// add r4,r9,r8
	ctx.r4.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsb r6,r7
	ctx.r6.s64 = ctx.r7.s8;
	// stw r4,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r4.u32);
	// stb r6,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r6.u8);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bge cr6,0x88156900
	if (!ctx.cr6.lt) goto loc_88156900;
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lbz r10,41(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 41);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// stb r10,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r10.u8);
	// cmpwi cr6,r8,3
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 3, ctx.xer);
	// stb r8,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r8.u8);
	// ble cr6,0x88156900
	if (!ctx.cr6.gt) goto loc_88156900;
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r11.u8);
loc_88156900:
	// lbz r10,11(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lhz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// extsh r6,r9
	ctx.r6.s64 = ctx.r9.s16;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x8815691C;
	sub_881538C0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// beq cr6,0x88156940
	if (ctx.cr6.eq) goto loc_88156940;
	// lbz r10,10(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm r8,r10,26,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 26) & 0xFFFFFFFC;
	// or r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 | ctx.r9.u64;
	// stw r7,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
loc_88156940:
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

__attribute__((alias("__imp__sub_88156954"))) PPC_WEAK_FUNC(sub_88156954);
PPC_FUNC_IMPL(__imp__sub_88156954) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88156958"))) PPC_WEAK_FUNC(sub_88156958);
PPC_FUNC_IMPL(__imp__sub_88156958) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88156960;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r11,124(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 124);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88156a0c
	if (ctx.cr6.eq) goto loc_88156A0C;
	// lwz r11,56(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r11.u32);
	// bgt 0x88156a0c
	if (ctx.cr0.gt) goto loc_88156A0C;
	// lhz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 36);
	// lwz r9,52(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// lwz r8,60(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// add r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r11,64(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// extsh r10,r7
	ctx.r10.s64 = ctx.r7.s16;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r8,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r8.u32);
	// sth r10,36(r3)
	PPC_STORE_U16(ctx.r3.u32 + 36, ctx.r10.u16);
	// ble cr6,0x881569bc
	if (!ctx.cr6.gt) goto loc_881569BC;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x881569bc
	if (ctx.cr6.lt) goto loc_881569BC;
	// sth r11,36(r3)
	PPC_STORE_U16(ctx.r3.u32 + 36, ctx.r11.u16);
loc_881569BC:
	// lhz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 36);
	// lis r8,-30714
	ctx.r8.s64 = -2012872704;
	// lhz r9,50(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// addic. r11,r31,32
	ctx.xer.ca = ctx.r31.u32 > 4294967263;
	ctx.r11.s64 = ctx.r31.s64 + 32;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r7,r31,28
	ctx.r7.s64 = ctx.r31.s64 + 28;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// clrlwi r9,r9,23
	ctx.r9.u64 = ctx.r9.u32 & 0x1FF;
	// addi r8,r8,9552
	ctx.r8.s64 = ctx.r8.s64 + 9552;
	// beq 0x881569f4
	if (ctx.cr0.eq) goto loc_881569F4;
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
loc_881569F4:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x88156a0c
	if (ctx.cr6.eq) goto loc_88156A0C;
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r8
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r8.u32);
	// mullw r8,r9,r10
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// stw r8,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r8.u32);
loc_88156A0C:
	// lbz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 40);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// extsb r4,r7
	ctx.r4.s64 = ctx.r7.s8;
	// add r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stb r4,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r4.u8);
	// stw r5,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r5.u32);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// stw r6,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r6.u32);
	// bge cr6,0x88156a8c
	if (!ctx.cr6.lt) goto loc_88156A8C;
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r9.u8);
	// cmpwi cr6,r9,15
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 15, ctx.xer);
	// bne cr6,0x88156b18
	if (!ctx.cr6.eq) goto loc_88156B18;
	// lwz r30,104(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// li r29,7
	ctx.r29.s64 = 7;
	// lhz r11,50(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// li r10,16
	ctx.r10.s64 = 16;
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r7,84(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// addi r8,r11,256
	ctx.r8.s64 = ctx.r11.s64 + 256;
	// lwz r4,80(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// bl 0x880947c8
	ctx.lr = 0x88156A8C;
	sub_880947C8(ctx, base);
loc_88156A8C:
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r11,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
	// cmpwi cr6,r11,255
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 255, ctx.xer);
	// blt cr6,0x88156aa8
	if (ctx.cr6.lt) goto loc_88156AA8;
	// li r11,255
	ctx.r11.s64 = 255;
	// stw r11,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
loc_88156AA8:
	// lbz r10,11(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lhz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// extsh r6,r9
	ctx.r6.s64 = ctx.r9.s16;
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// bl 0x881538c0
	ctx.lr = 0x88156ACC;
	sub_881538C0(ctx, base);
	// lwz r8,108(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r8,24
	ctx.r11.u64 = ctx.r8.u32 & 0xFF;
	// beq cr6,0x88156b0c
	if (ctx.cr6.eq) goto loc_88156B0C;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r8,545
	ctx.r8.s64 = 35717120;
	// lis r7,128
	ctx.r7.s64 = 8388608;
	// rlwimi r8,r11,8,16,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r8.u64 & 0xFFFFFFFFFFFF00FF);
	// ori r6,r7,16512
	ctx.r6.u64 = ctx.r7.u64 | 16512;
	// lwz r11,-11932(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11932);
	// or r5,r8,r9
	ctx.r5.u64 = ctx.r8.u64 | ctx.r9.u64;
	// stw r6,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r6.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// stw r11,-11932(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11932, ctx.r11.u32);
loc_88156B0C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_88156B18:
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// cmplwi cr6,r11,13
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 13, ctx.xer);
	// bne cr6,0x88156a8c
	if (!ctx.cr6.eq) goto loc_88156A8C;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88156B30"))) PPC_WEAK_FUNC(sub_88156B30);
PPC_FUNC_IMPL(__imp__sub_88156B30) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x88156B38;
	__savegprlr_24(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,40(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 40);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r9,20(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r7,r11,-1
	ctx.r7.s64 = ctx.r11.s64 + -1;
	// lwz r8,24(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// extsb r6,r7
	ctx.r6.s64 = ctx.r7.s8;
	// add r4,r9,r10
	ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r5,r11,r8
	ctx.r5.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stb r6,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, ctx.r6.u8);
	// stw r4,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r4.u32);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// stw r5,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r5.u32);
	// bge cr6,0x88156ba0
	if (!ctx.cr6.lt) goto loc_88156BA0;
	// lbz r11,11(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 11);
	// lbz r10,41(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 41);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// stb r10,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, ctx.r10.u8);
	// cmpwi cr6,r8,5
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 5, ctx.xer);
	// stb r8,11(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11, ctx.r8.u8);
	// ble cr6,0x88156ba0
	if (!ctx.cr6.gt) goto loc_88156BA0;
	// stb r29,11(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11, ctx.r29.u8);
loc_88156BA0:
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88156ef4
	if (ctx.cr6.eq) goto loc_88156EF4;
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// bgt 0x88156ef4
	if (ctx.cr0.gt) goto loc_88156EF4;
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// li r25,1
	ctx.r25.s64 = 1;
	// lwz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// li r26,2
	ctx.r26.s64 = 2;
	// li r27,-1
	ctx.r27.s64 = -1;
	// cmpwi cr6,r10,128
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 128, ctx.xer);
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// blt cr6,0x88156c58
	if (ctx.cr6.lt) goto loc_88156C58;
	// cmpwi cr6,r10,384
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 384, ctx.xer);
	// bgt cr6,0x88156c58
	if (ctx.cr6.gt) goto loc_88156C58;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lhz r8,50(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// addi r11,r11,26276
	ctx.r11.s64 = ctx.r11.s64 + 26276;
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r28,0(r11)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x88156ccc
	if (!ctx.cr6.eq) goto loc_88156CCC;
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// lwz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// extsh r6,r10
	ctx.r6.s64 = ctx.r10.s16;
	// addi r3,r11,16
	ctx.r3.s64 = ctx.r11.s64 + 16;
	// sth r25,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r25.u16);
	// stw r26,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r26.u32);
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// clrlwi r3,r9,24
	ctx.r3.u64 = ctx.r9.u32 & 0xFF;
	// stw r29,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r29.u32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r27.u32);
	// bl 0x8815c948
	ctx.lr = 0x88156C3C;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x8815c860
	ctx.lr = 0x88156C48;
	sub_8815C860(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x88156ccc
	if (ctx.cr6.eq) goto loc_88156CCC;
	// sth r26,16(r30)
	PPC_STORE_U16(ctx.r30.u32 + 16, ctx.r26.u16);
	// b 0x88156ccc
	goto loc_88156CCC;
loc_88156C58:
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// lhz r7,50(r31)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// addi r11,r11,26276
	ctx.r11.s64 = ctx.r11.s64 + 26276;
	// addi r8,r9,-1
	ctx.r8.s64 = ctx.r9.s64 + -1;
	// lwz r9,84(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// add r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 + ctx.r10.u64;
	// lwz r28,0(r11)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x88156ccc
	if (!ctx.cr6.eq) goto loc_88156CCC;
	// clrlwi r7,r10,16
	ctx.r7.u64 = ctx.r10.u32 & 0xFFFF;
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// extsh r6,r9
	ctx.r6.s64 = ctx.r9.s16;
	// addi r9,r11,16
	ctx.r9.s64 = ctx.r11.s64 + 16;
	// sth r25,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r25.u16);
	// clrlwi r3,r8,24
	ctx.r3.u64 = ctx.r8.u32 & 0xFF;
	// stw r26,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r26.u32);
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r29,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r29.u32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r27.u32);
	// bl 0x8815c948
	ctx.lr = 0x88156CB4;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x8815c860
	ctx.lr = 0x88156CC0;
	sub_8815C860(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x88156ccc
	if (ctx.cr6.eq) goto loc_88156CCC;
	// sth r27,16(r30)
	PPC_STORE_U16(ctx.r30.u32 + 16, ctx.r27.u16);
loc_88156CCC:
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// addi r10,r11,170
	ctx.r10.s64 = ctx.r11.s64 + 170;
	// clrlwi r10,r10,23
	ctx.r10.u64 = ctx.r10.u32 & 0x1FF;
	// cmpwi cr6,r10,128
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 128, ctx.xer);
	// blt cr6,0x88156d5c
	if (ctx.cr6.lt) goto loc_88156D5C;
	// cmpwi cr6,r10,384
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 384, ctx.xer);
	// bgt cr6,0x88156d5c
	if (ctx.cr6.gt) goto loc_88156D5C;
	// lhz r9,50(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r9,84(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// addi r8,r11,170
	ctx.r8.s64 = ctx.r11.s64 + 170;
	// bne cr6,0x88156dd0
	if (!ctx.cr6.eq) goto loc_88156DD0;
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// lwz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// extsh r6,r9
	ctx.r6.s64 = ctx.r9.s16;
	// addi r3,r11,16
	ctx.r3.s64 = ctx.r11.s64 + 16;
	// sth r25,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r25.u16);
	// stw r26,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r26.u32);
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// clrlwi r3,r10,24
	ctx.r3.u64 = ctx.r10.u32 & 0xFF;
	// stw r29,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r29.u32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r27.u32);
	// bl 0x8815c948
	ctx.lr = 0x88156D40;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x8815c860
	ctx.lr = 0x88156D4C;
	sub_8815C860(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x88156dd0
	if (ctx.cr6.eq) goto loc_88156DD0;
	// sth r26,16(r30)
	PPC_STORE_U16(ctx.r30.u32 + 16, ctx.r26.u16);
	// b 0x88156dd0
	goto loc_88156DD0;
loc_88156D5C:
	// lhz r10,50(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addi r10,r9,-1
	ctx.r10.s64 = ctx.r9.s64 + -1;
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r9,84(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// addi r8,r11,170
	ctx.r8.s64 = ctx.r11.s64 + 170;
	// bne cr6,0x88156dd0
	if (!ctx.cr6.eq) goto loc_88156DD0;
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// lwz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// extsh r6,r9
	ctx.r6.s64 = ctx.r9.s16;
	// addi r3,r11,16
	ctx.r3.s64 = ctx.r11.s64 + 16;
	// sth r25,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r25.u16);
	// stw r26,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r26.u32);
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// clrlwi r3,r10,24
	ctx.r3.u64 = ctx.r10.u32 & 0xFF;
	// stw r29,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r29.u32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r27.u32);
	// bl 0x8815c948
	ctx.lr = 0x88156DB8;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x8815c860
	ctx.lr = 0x88156DC4;
	sub_8815C860(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x88156dd0
	if (ctx.cr6.eq) goto loc_88156DD0;
	// sth r27,16(r30)
	PPC_STORE_U16(ctx.r30.u32 + 16, ctx.r27.u16);
loc_88156DD0:
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// addi r10,r11,-172
	ctx.r10.s64 = ctx.r11.s64 + -172;
	// clrlwi r10,r10,23
	ctx.r10.u64 = ctx.r10.u32 & 0x1FF;
	// cmpwi cr6,r10,128
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 128, ctx.xer);
	// blt cr6,0x88156e60
	if (ctx.cr6.lt) goto loc_88156E60;
	// cmpwi cr6,r10,384
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 384, ctx.xer);
	// bgt cr6,0x88156e60
	if (ctx.cr6.gt) goto loc_88156E60;
	// lhz r9,50(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r9,84(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// addi r8,r11,340
	ctx.r8.s64 = ctx.r11.s64 + 340;
	// bne cr6,0x88156ed4
	if (!ctx.cr6.eq) goto loc_88156ED4;
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// lwz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// extsh r6,r9
	ctx.r6.s64 = ctx.r9.s16;
	// addi r3,r11,16
	ctx.r3.s64 = ctx.r11.s64 + 16;
	// sth r25,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r25.u16);
	// stw r26,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r26.u32);
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// clrlwi r3,r10,24
	ctx.r3.u64 = ctx.r10.u32 & 0xFF;
	// stw r29,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r29.u32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r27.u32);
	// bl 0x8815c948
	ctx.lr = 0x88156E44;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x8815c860
	ctx.lr = 0x88156E50;
	sub_8815C860(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x88156ed4
	if (ctx.cr6.eq) goto loc_88156ED4;
	// sth r26,16(r30)
	PPC_STORE_U16(ctx.r30.u32 + 16, ctx.r26.u16);
	// b 0x88156ed4
	goto loc_88156ED4;
loc_88156E60:
	// lhz r9,50(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// lwz r9,84(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// addi r8,r11,340
	ctx.r8.s64 = ctx.r11.s64 + 340;
	// bne cr6,0x88156ed4
	if (!ctx.cr6.eq) goto loc_88156ED4;
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// lwz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// extsh r6,r9
	ctx.r6.s64 = ctx.r9.s16;
	// addi r3,r11,16
	ctx.r3.s64 = ctx.r11.s64 + 16;
	// sth r25,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r25.u16);
	// stw r26,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r26.u32);
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// clrlwi r3,r10,24
	ctx.r3.u64 = ctx.r10.u32 & 0xFF;
	// stw r29,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r29.u32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r27.u32);
	// bl 0x8815c948
	ctx.lr = 0x88156EBC;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x8815c860
	ctx.lr = 0x88156EC8;
	sub_8815C860(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x88156ed4
	if (ctx.cr6.eq) goto loc_88156ED4;
	// sth r27,16(r30)
	PPC_STORE_U16(ctx.r30.u32 + 16, ctx.r27.u16);
loc_88156ED4:
	// lwz r9,76(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// lwz r10,88(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// clrlwi r8,r10,23
	ctx.r8.u64 = ctx.r10.u32 & 0x1FF;
	// stw r9,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r9.u32);
	// stw r8,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r8.u32);
loc_88156EF4:
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lis r9,-30671
	ctx.r9.s64 = -2010054656;
	// lhz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// extsb r7,r11
	ctx.r7.s64 = ctx.r11.s8;
	// lhz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// addi r3,r9,4316
	ctx.r3.s64 = ctx.r9.s64 + 4316;
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// rlwinm r11,r7,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// lhzx r11,r11,r3
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r3.u32);
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x88156F28;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88156f44
	if (ctx.cr6.eq) goto loc_88156F44;
	// lbz r11,10(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r11,26,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 26) & 0xFFFFFFFC;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_88156F44:
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// lhz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 36);
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r8,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r7,r11,42
	ctx.r7.s64 = ctx.r11.s64 + 42;
	// cmpw cr6,r9,r7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, ctx.xer);
	// blt cr6,0x88157030
	if (ctx.cr6.lt) goto loc_88157030;
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x88157030
	if (!ctx.cr6.gt) goto loc_88157030;
	// lis r27,-30597
	ctx.r27.s64 = -2005204992;
	// lis r11,-30663
	ctx.r11.s64 = -2009530368;
	// lis r10,-30663
	ctx.r10.s64 = -2009530368;
	// lis r9,-30658
	ctx.r9.s64 = -2009202688;
	// lwz r30,-11932(r27)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
	// lwz r24,-30240(r11)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r11.u32 + -30240);
	// lwz r25,-22224(r10)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + -22224);
	// lwz r26,160(r9)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
loc_88156F9C:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r28,r29,1
	ctx.r28.s64 = ctx.r29.s64 + 1;
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lbz r8,11(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// mullw r7,r28,r11
	ctx.r7.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r11.s32);
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lhz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// mullw r3,r28,r9
	ctx.r3.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r9.s32);
	// extsb r10,r8
	ctx.r10.s64 = ctx.r8.s8;
	// subf r4,r3,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r3.s64;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// subf r5,r7,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r7.s64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x88156FDC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8815701c
	if (ctx.cr6.eq) goto loc_8815701C;
	// subf r11,r29,r24
	ctx.r11.s64 = ctx.r24.s64 - ctx.r29.s64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// mullw r11,r11,r25
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r25.s32);
	// add r8,r11,r26
	ctx.r8.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// rlwimi r9,r8,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r30,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r30.u32);
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// lbz r6,10(r31)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10);
	// rlwinm r5,r6,26,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 26) & 0xFFFFFFFC;
	// or r4,r5,r7
	ctx.r4.u64 = ctx.r5.u64 | ctx.r7.u64;
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
loc_8815701C:
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpw cr6,r28,r10
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x88156f9c
	if (ctx.cr6.lt) goto loc_88156F9C;
loc_88157030:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8815703C"))) PPC_WEAK_FUNC(sub_8815703C);
PPC_FUNC_IMPL(__imp__sub_8815703C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88157040"))) PPC_WEAK_FUNC(sub_88157040);
PPC_FUNC_IMPL(__imp__sub_88157040) {
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
	// bl 0x8815a220
	ctx.lr = 0x88157058;
	sub_8815A220(ctx, base);
	// lis r11,16838
	ctx.r11.s64 = 1103495168;
	// lis r7,-30671
	ctx.r7.s64 = -2010054656;
	// ori r11,r11,20077
	ctx.r11.u64 = ctx.r11.u64 | 20077;
	// lis r6,-30658
	ctx.r6.s64 = -2009202688;
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// lwz r11,4200(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4200);
	// li r3,3233
	ctx.r3.s64 = 3233;
	// li r10,0
	ctx.r10.s64 = 0;
	// mullw r11,r11,r4
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r4.s32);
	// lwz r9,156(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 156);
	// sth r3,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r3.u16);
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// stw r10,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r10.u32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r5,112(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// mullw r8,r11,r4
	ctx.r8.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r4.s32);
	// stw r11,4200(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4200, ctx.r11.u32);
	// lhz r11,4200(r7)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 4200);
	// stb r6,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r6.u8);
	// stb r5,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r5.u8);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// clrlwi r4,r11,23
	ctx.r4.u64 = ctx.r11.u32 & 0x1FF;
	// stw r8,4200(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4200, ctx.r8.u32);
	// li r3,136
	ctx.r3.s64 = 136;
	// lhz r11,4200(r7)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 4200);
	// neg r9,r9
	ctx.r9.s64 = -ctx.r9.s64;
	// li r8,16
	ctx.r8.s64 = 16;
	// stw r3,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r3.u32);
	// clrlwi r6,r11,31
	ctx.r6.u64 = ctx.r11.u32 & 0x1;
	// stw r9,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r9.u32);
	// stw r8,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r8.u32);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// stw r4,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r4.u32);
	// beq cr6,0x881570f0
	if (ctx.cr6.eq) goto loc_881570F0;
	// li r11,-16
	ctx.r11.s64 = -16;
	// stw r11,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r11.u32);
loc_881570F0:
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r9,88(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// neg r8,r11
	ctx.r8.s64 = -ctx.r11.s64;
	// stw r10,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r10.u32);
	// neg r7,r9
	ctx.r7.s64 = -ctx.r9.s64;
	// stw r8,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r8.u32);
	// stw r7,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r7.u32);
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

__attribute__((alias("__imp__sub_88157124"))) PPC_WEAK_FUNC(sub_88157124);
PPC_FUNC_IMPL(__imp__sub_88157124) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88157128"))) PPC_WEAK_FUNC(sub_88157128);
PPC_FUNC_IMPL(__imp__sub_88157128) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x88157130;
	__savegprlr_24(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,40(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 40);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r9,20(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// addi r7,r11,-1
	ctx.r7.s64 = ctx.r11.s64 + -1;
	// lwz r8,24(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// extsb r6,r7
	ctx.r6.s64 = ctx.r7.s8;
	// add r4,r9,r10
	ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r5,r11,r8
	ctx.r5.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stb r6,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, ctx.r6.u8);
	// stw r4,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r4.u32);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// stw r5,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r5.u32);
	// bge cr6,0x8815718c
	if (!ctx.cr6.lt) goto loc_8815718C;
	// lbz r11,11(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 11);
	// lbz r10,41(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 41);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// clrlwi r8,r9,30
	ctx.r8.u64 = ctx.r9.u32 & 0x3;
	// stb r10,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, ctx.r10.u8);
	// stb r8,11(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11, ctx.r8.u8);
loc_8815718C:
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x881572cc
	if (ctx.cr6.eq) goto loc_881572CC;
	// lis r11,8
	ctx.r11.s64 = 524288;
	// cmpw cr6,r5,r11
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r11.s32, ctx.xer);
	// bgt cr6,0x881571b0
	if (ctx.cr6.gt) goto loc_881571B0;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// b 0x881572cc
	goto loc_881572CC;
loc_881571B0:
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// bgt 0x881572cc
	if (ctx.cr0.gt) goto loc_881572CC;
	// lis r8,-30643
	ctx.r8.s64 = -2008219648;
	// lwz r7,68(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// lwz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// li r30,1
	ctx.r30.s64 = 1;
	// lhz r9,50(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// li r27,4
	ctx.r27.s64 = 4;
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// li r28,-1
	ctx.r28.s64 = -1;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r29,26276(r8)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + 26276);
	// stw r7,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r7.u32);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x88157234
	if (!ctx.cr6.eq) goto loc_88157234;
	// clrlwi r7,r9,16
	ctx.r7.u64 = ctx.r9.u32 & 0xFFFF;
	// lwz r8,100(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r9,128(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// extsh r6,r10
	ctx.r6.s64 = ctx.r10.s16;
	// addi r8,r8,48
	ctx.r8.s64 = ctx.r8.s64 + 48;
	// sth r30,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r30.u16);
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r30.u32);
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// stw r27,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r27.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// stw r28,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r28.u32);
	// bl 0x8815c948
	ctx.lr = 0x8815722C;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x88157234;
	sub_8815C860(ctx, base);
loc_88157234:
	// lhz r11,50(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// lwz r9,76(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// subf r9,r9,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r9.s64;
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r8,84(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// bne cr6,0x88157294
	if (!ctx.cr6.eq) goto loc_88157294;
	// clrlwi r7,r9,16
	ctx.r7.u64 = ctx.r9.u32 & 0xFFFF;
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r9,128(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// addi r8,r11,48
	ctx.r8.s64 = ctx.r11.s64 + 48;
	// sth r30,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r30.u16);
	// clrlwi r3,r10,24
	ctx.r3.u64 = ctx.r10.u32 & 0xFF;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r30.u32);
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// stw r27,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r27.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// stw r28,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r28.u32);
	// bl 0x8815c948
	ctx.lr = 0x8815728C;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x88157294;
	sub_8815C860(ctx, base);
loc_88157294:
	// lwz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// lwz r7,92(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// lwz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r9,100(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r5,96(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// addi r6,r8,-1
	ctx.r6.s64 = ctx.r8.s64 + -1;
	// addi r4,r9,3
	ctx.r4.s64 = ctx.r9.s64 + 3;
	// stw r3,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r3.u32);
	// subf r11,r5,r7
	ctx.r11.s64 = ctx.r7.s64 - ctx.r5.s64;
	// stw r6,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r6.u32);
	// stw r4,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r4.u32);
	// stw r11,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
loc_881572CC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8815a360
	ctx.lr = 0x881572D4;
	sub_8815A360(ctx, base);
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// lhz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 36);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r11,42
	ctx.r9.s64 = ctx.r11.s64 + 42;
	// cmpw cr6,r7,r9
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x881573c4
	if (ctx.cr6.lt) goto loc_881573C4;
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// li r29,0
	ctx.r29.s64 = 0;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x881573c4
	if (!ctx.cr6.gt) goto loc_881573C4;
	// lis r27,-30597
	ctx.r27.s64 = -2005204992;
	// lis r11,-30663
	ctx.r11.s64 = -2009530368;
	// lis r10,-30663
	ctx.r10.s64 = -2009530368;
	// lis r9,-30658
	ctx.r9.s64 = -2009202688;
	// lwz r30,-11932(r27)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
	// lwz r24,-30240(r11)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r11.u32 + -30240);
	// lwz r25,-22224(r10)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + -22224);
	// lwz r26,160(r9)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
loc_88157330:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r28,r29,1
	ctx.r28.s64 = ctx.r29.s64 + 1;
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lbz r8,11(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// mullw r7,r11,r28
	ctx.r7.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lhz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// mullw r3,r28,r9
	ctx.r3.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r9.s32);
	// extsb r10,r8
	ctx.r10.s64 = ctx.r8.s8;
	// subf r4,r3,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r3.s64;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// subf r5,r7,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r7.s64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x88157370;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x881573b0
	if (ctx.cr6.eq) goto loc_881573B0;
	// subf r11,r29,r24
	ctx.r11.s64 = ctx.r24.s64 - ctx.r29.s64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// mullw r11,r11,r25
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r25.s32);
	// add r8,r11,r26
	ctx.r8.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// rlwimi r9,r8,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r30,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r30.u32);
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// lbz r6,10(r31)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10);
	// rlwinm r5,r6,26,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 26) & 0xFFFFFFFC;
	// or r4,r5,r7
	ctx.r4.u64 = ctx.r5.u64 | ctx.r7.u64;
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
loc_881573B0:
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpw cr6,r28,r10
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x88157330
	if (ctx.cr6.lt) goto loc_88157330;
loc_881573C4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_881573D0"))) PPC_WEAK_FUNC(sub_881573D0);
PPC_FUNC_IMPL(__imp__sub_881573D0) {
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
	// bl 0x8815a220
	ctx.lr = 0x881573E8;
	sub_8815A220(ctx, base);
	// li r10,3169
	ctx.r10.s64 = 3169;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r3,16
	ctx.r3.s64 = 16;
	// sth r10,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r10.u16);
	// stb r9,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r9.u8);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r8,2
	ctx.r8.s64 = 2;
	// stw r3,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r3.u32);
	// li r7,500
	ctx.r7.s64 = 500;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// li r6,64
	ctx.r6.s64 = 64;
	// stw r8,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r8.u32);
	// li r5,45
	ctx.r5.s64 = 45;
	// stw r7,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r7.u32);
	// li r4,-40
	ctx.r4.s64 = -40;
	// stw r6,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r6.u32);
	// li r10,-64
	ctx.r10.s64 = -64;
	// stw r5,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r5.u32);
	// li r9,-16
	ctx.r9.s64 = -16;
	// stw r4,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r4.u32);
	// stw r10,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r9.u32);
	// stw r11,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_8815745C"))) PPC_WEAK_FUNC(sub_8815745C);
PPC_FUNC_IMPL(__imp__sub_8815745C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88157460"))) PPC_WEAK_FUNC(sub_88157460);
PPC_FUNC_IMPL(__imp__sub_88157460) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x88157468;
	__savegprlr_24(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,40(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 40);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r9,20(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// addi r7,r11,-1
	ctx.r7.s64 = ctx.r11.s64 + -1;
	// lwz r8,24(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// extsb r6,r7
	ctx.r6.s64 = ctx.r7.s8;
	// add r4,r9,r10
	ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r5,r11,r8
	ctx.r5.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stb r6,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, ctx.r6.u8);
	// stw r4,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r4.u32);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// stw r5,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r5.u32);
	// bge cr6,0x881574c4
	if (!ctx.cr6.lt) goto loc_881574C4;
	// lbz r11,11(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 11);
	// lbz r10,41(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 41);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// clrlwi r8,r9,30
	ctx.r8.u64 = ctx.r9.u32 & 0x3;
	// stb r10,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, ctx.r10.u8);
	// stb r8,11(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11, ctx.r8.u8);
loc_881574C4:
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x881575c0
	if (ctx.cr6.eq) goto loc_881575C0;
	// lis r11,8
	ctx.r11.s64 = 524288;
	// cmpw cr6,r5,r11
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r11.s32, ctx.xer);
	// bgt cr6,0x881574e8
	if (ctx.cr6.gt) goto loc_881574E8;
	// stw r29,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r29.u32);
	// b 0x881575c0
	goto loc_881575C0;
loc_881574E8:
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// bgt 0x881575c0
	if (ctx.cr0.gt) goto loc_881575C0;
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// clrlwi r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	// lwz r9,84(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26276(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
	// beq cr6,0x8815752c
	if (ctx.cr6.eq) goto loc_8815752C;
	// lhz r7,50(r31)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// lwz r8,76(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// b 0x88157538
	goto loc_88157538;
loc_8815752C:
	// lhz r8,50(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// lwz r7,76(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// subf r8,r7,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r7.s64;
loc_88157538:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88157588
	if (!ctx.cr6.eq) goto loc_88157588;
	// lwz r7,100(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// li r28,-1
	ctx.r28.s64 = -1;
	// subfic r6,r7,112
	ctx.xer.ca = ctx.r7.u32 <= 112;
	ctx.r6.s64 = 112 - ctx.r7.s64;
	// sth r11,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r11.u16);
	// li r30,3
	ctx.r30.s64 = 3;
	// stw r28,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r28.u32);
	// stw r6,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r6.u32);
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// extsh r6,r9
	ctx.r6.s64 = ctx.r9.s16;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r30.u32);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// clrlwi r3,r10,24
	ctx.r3.u64 = ctx.r10.u32 & 0xFF;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// bl 0x8815c948
	ctx.lr = 0x88157580;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x88157588;
	sub_8815C860(ctx, base);
loc_88157588:
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r9,76(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// lwz r8,92(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// addi r4,r11,4
	ctx.r4.s64 = ctx.r11.s64 + 4;
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// lwz r7,88(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// lwz r5,96(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// addi r6,r10,-1
	ctx.r6.s64 = ctx.r10.s64 + -1;
	// subf r3,r7,r9
	ctx.r3.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r4,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r4.u32);
	// subf r11,r5,r8
	ctx.r11.s64 = ctx.r8.s64 - ctx.r5.s64;
	// stw r6,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r6.u32);
	// stw r3,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r3.u32);
	// stw r11,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
loc_881575C0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8815a360
	ctx.lr = 0x881575C8;
	sub_8815A360(ctx, base);
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// lhz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 36);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r11,42
	ctx.r9.s64 = ctx.r11.s64 + 42;
	// cmpw cr6,r7,r9
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x881576b4
	if (ctx.cr6.lt) goto loc_881576B4;
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x881576b4
	if (!ctx.cr6.gt) goto loc_881576B4;
	// lis r27,-30597
	ctx.r27.s64 = -2005204992;
	// lis r11,-30663
	ctx.r11.s64 = -2009530368;
	// lis r10,-30663
	ctx.r10.s64 = -2009530368;
	// lis r9,-30658
	ctx.r9.s64 = -2009202688;
	// lwz r30,-11932(r27)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
	// lwz r24,-30240(r11)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r11.u32 + -30240);
	// lwz r25,-22224(r10)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + -22224);
	// lwz r26,160(r9)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
loc_88157620:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r28,r29,1
	ctx.r28.s64 = ctx.r29.s64 + 1;
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lbz r8,11(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// mullw r7,r11,r28
	ctx.r7.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lhz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// mullw r3,r28,r9
	ctx.r3.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r9.s32);
	// extsb r10,r8
	ctx.r10.s64 = ctx.r8.s8;
	// subf r4,r3,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r3.s64;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// subf r5,r7,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r7.s64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x88157660;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x881576a0
	if (ctx.cr6.eq) goto loc_881576A0;
	// subf r11,r29,r24
	ctx.r11.s64 = ctx.r24.s64 - ctx.r29.s64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// mullw r11,r11,r25
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r25.s32);
	// add r8,r11,r26
	ctx.r8.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// rlwimi r9,r8,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r30,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r30.u32);
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// lbz r6,10(r31)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10);
	// rlwinm r5,r6,26,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 26) & 0xFFFFFFFC;
	// or r4,r5,r7
	ctx.r4.u64 = ctx.r5.u64 | ctx.r7.u64;
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
loc_881576A0:
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpw cr6,r28,r10
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x88157620
	if (ctx.cr6.lt) goto loc_88157620;
loc_881576B4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_881576C0"))) PPC_WEAK_FUNC(sub_881576C0);
PPC_FUNC_IMPL(__imp__sub_881576C0) {
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
	// bl 0x8815a220
	ctx.lr = 0x881576D8;
	sub_8815A220(ctx, base);
	// lis r10,-30658
	ctx.r10.s64 = -2009202688;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// li r8,2
	ctx.r8.s64 = 2;
	// stw r11,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r11.u32);
	// li r7,80
	ctx.r7.s64 = 80;
	// lwz r10,156(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 156);
	// li r6,96
	ctx.r6.s64 = 96;
	// stw r11,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
	// li r5,26
	ctx.r5.s64 = 26;
	// stw r11,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
	// neg r11,r10
	ctx.r11.s64 = -ctx.r10.s64;
	// stb r9,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r9.u8);
	// li r4,-96
	ctx.r4.s64 = -96;
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r8,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r8.u32);
	// stw r7,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r7.u32);
	// stw r6,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r6.u32);
	// stw r5,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r5.u32);
	// stw r4,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r4.u32);
	// lhz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// rotlwi r11,r10,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r9,r11,3555
	ctx.r9.s64 = ctx.r11.s64 + 3555;
	// sth r9,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r9.u16);
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

__attribute__((alias("__imp__sub_88157754"))) PPC_WEAK_FUNC(sub_88157754);
PPC_FUNC_IMPL(__imp__sub_88157754) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88157758"))) PPC_WEAK_FUNC(sub_88157758);
PPC_FUNC_IMPL(__imp__sub_88157758) {
	PPC_FUNC_PROLOGUE();
	// lhz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 36);
	// li r11,0
	ctx.r11.s64 = 0;
	// lhz r9,50(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 50);
	// li r8,3169
	ctx.r8.s64 = 3169;
	// extsb r7,r10
	ctx.r7.s64 = ctx.r10.s8;
	// stb r11,41(r3)
	PPC_STORE_U8(ctx.r3.u32 + 41, ctx.r11.u8);
	// li r6,2
	ctx.r6.s64 = 2;
	// sth r8,12(r3)
	PPC_STORE_U16(ctx.r3.u32 + 12, ctx.r8.u16);
	// stw r11,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, ctx.r11.u32);
	// cmpwi cr6,r7,31
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 31, ctx.xer);
	// stw r11,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, ctx.r11.u32);
	// stw r6,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r6.u32);
	// stw r9,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r9.u32);
	// stb r7,11(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11, ctx.r7.u8);
	// blt cr6,0x8815779c
	if (ctx.cr6.lt) goto loc_8815779C;
	// li r10,31
	ctx.r10.s64 = 31;
	// stb r10,11(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11, ctx.r10.u8);
loc_8815779C:
	// lwz r10,140(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881577AC"))) PPC_WEAK_FUNC(sub_881577AC);
PPC_FUNC_IMPL(__imp__sub_881577AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881577B0"))) PPC_WEAK_FUNC(sub_881577B0);
PPC_FUNC_IMPL(__imp__sub_881577B0) {
	PPC_FUNC_PROLOGUE();
	// li r7,3229
	ctx.r7.s64 = 3229;
	// lwz r9,56(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r8,140(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// sth r7,12(r3)
	PPC_STORE_U16(ctx.r3.u32 + 12, ctx.r7.u16);
	// stb r6,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, ctx.r6.u8);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,7
	ctx.r4.s64 = 7;
	// stb r11,41(r3)
	PPC_STORE_U8(ctx.r3.u32 + 41, ctx.r11.u8);
	// li r7,-24
	ctx.r7.s64 = -24;
	// stw r9,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, ctx.r9.u32);
	// li r6,28
	ctx.r6.s64 = 28;
	// stw r5,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r5.u32);
	// stw r4,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r4.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,80(r10)
	PPC_STORE_U32(ctx.r10.u32 + 80, ctx.r11.u32);
	// stw r11,84(r10)
	PPC_STORE_U32(ctx.r10.u32 + 84, ctx.r11.u32);
	// stw r7,88(r10)
	PPC_STORE_U32(ctx.r10.u32 + 88, ctx.r7.u32);
	// stb r6,11(r10)
	PPC_STORE_U8(ctx.r10.u32 + 11, ctx.r6.u8);
	// stw r11,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8815780C"))) PPC_WEAK_FUNC(sub_8815780C);
PPC_FUNC_IMPL(__imp__sub_8815780C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88157810"))) PPC_WEAK_FUNC(sub_88157810);
PPC_FUNC_IMPL(__imp__sub_88157810) {
	PPC_FUNC_PROLOGUE();
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r9,140(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r8,3169
	ctx.r8.s64 = 3169;
	// li r7,1
	ctx.r7.s64 = 1;
	// stb r11,41(r3)
	PPC_STORE_U8(ctx.r3.u32 + 41, ctx.r11.u8);
	// li r6,10
	ctx.r6.s64 = 10;
	// sth r8,12(r3)
	PPC_STORE_U16(ctx.r3.u32 + 12, ctx.r8.u16);
	// li r5,96
	ctx.r5.s64 = 96;
	// stb r7,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, ctx.r7.u8);
	// li r4,31
	ctx.r4.s64 = 31;
	// stw r6,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, ctx.r6.u32);
	// stw r11,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,88(r10)
	PPC_STORE_U32(ctx.r10.u32 + 88, ctx.r11.u32);
	// stw r5,76(r10)
	PPC_STORE_U32(ctx.r10.u32 + 76, ctx.r5.u32);
	// stw r11,92(r10)
	PPC_STORE_U32(ctx.r10.u32 + 92, ctx.r11.u32);
	// stb r4,11(r10)
	PPC_STORE_U8(ctx.r10.u32 + 11, ctx.r4.u8);
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88157860"))) PPC_WEAK_FUNC(sub_88157860);
PPC_FUNC_IMPL(__imp__sub_88157860) {
	PPC_FUNC_PROLOGUE();
	// li r7,3229
	ctx.r7.s64 = 3229;
	// lhz r9,50(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 50);
	// lwz r8,92(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r6,140(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r7,12(r3)
	PPC_STORE_U16(ctx.r3.u32 + 12, ctx.r7.u16);
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,-18
	ctx.r4.s64 = -18;
	// li r7,1
	ctx.r7.s64 = 1;
	// stb r5,41(r3)
	PPC_STORE_U8(ctx.r3.u32 + 41, ctx.r5.u8);
	// stw r4,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r4.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,80(r10)
	PPC_STORE_U32(ctx.r10.u32 + 80, ctx.r9.u32);
	// stw r11,84(r10)
	PPC_STORE_U32(ctx.r10.u32 + 84, ctx.r11.u32);
	// stw r7,88(r10)
	PPC_STORE_U32(ctx.r10.u32 + 88, ctx.r7.u32);
	// stw r8,96(r10)
	PPC_STORE_U32(ctx.r10.u32 + 96, ctx.r8.u32);
	// stw r11,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881578AC"))) PPC_WEAK_FUNC(sub_881578AC);
PPC_FUNC_IMPL(__imp__sub_881578AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881578B0"))) PPC_WEAK_FUNC(sub_881578B0);
PPC_FUNC_IMPL(__imp__sub_881578B0) {
	PPC_FUNC_PROLOGUE();
	// lhz r9,50(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 50);
	// li r8,2
	ctx.r8.s64 = 2;
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// li r11,3169
	ctx.r11.s64 = 3169;
	// stb r8,41(r3)
	PPC_STORE_U8(ctx.r3.u32 + 41, ctx.r8.u8);
	// li r6,10
	ctx.r6.s64 = 10;
	// li r7,0
	ctx.r7.s64 = 0;
	// sth r11,12(r3)
	PPC_STORE_U16(ctx.r3.u32 + 12, ctx.r11.u16);
	// addi r5,r9,-256
	ctx.r5.s64 = ctx.r9.s64 + -256;
	// stw r6,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, ctx.r6.u32);
	// addi r8,r10,9552
	ctx.r8.s64 = ctx.r10.s64 + 9552;
	// stw r7,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, ctx.r7.u32);
	// addic. r11,r3,32
	ctx.xer.ca = ctx.r3.u32 > 4294967263;
	ctx.r11.s64 = ctx.r3.s64 + 32;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r7,88(r3)
	PPC_STORE_U32(ctx.r3.u32 + 88, ctx.r7.u32);
	// addi r6,r3,28
	ctx.r6.s64 = ctx.r3.s64 + 28;
	// clrlwi r10,r5,23
	ctx.r10.u64 = ctx.r5.u32 & 0x1FF;
	// beq 0x88157908
	if (ctx.cr0.eq) goto loc_88157908;
	// addi r9,r10,128
	ctx.r9.s64 = ctx.r10.s64 + 128;
	// rlwinm r5,r9,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x7FC;
	// lwzx r4,r5,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r8.u32);
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
loc_88157908:
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x88157920
	if (ctx.cr6.eq) goto loc_88157920;
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r8
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r8.u32);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r9,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r9.u32);
loc_88157920:
	// lwz r11,140(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// li r10,96
	ctx.r10.s64 = 96;
	// li r9,31
	ctx.r9.s64 = 31;
	// stw r7,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, ctx.r7.u32);
	// stw r10,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r10.u32);
	// stb r9,11(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11, ctx.r9.u8);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r7,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88157944"))) PPC_WEAK_FUNC(sub_88157944);
PPC_FUNC_IMPL(__imp__sub_88157944) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88157948"))) PPC_WEAK_FUNC(sub_88157948);
PPC_FUNC_IMPL(__imp__sub_88157948) {
	PPC_FUNC_PROLOGUE();
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r9,140(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r8,3169
	ctx.r8.s64 = 3169;
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r11,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, ctx.r11.u32);
	// li r6,10
	ctx.r6.s64 = 10;
	// sth r8,12(r3)
	PPC_STORE_U16(ctx.r3.u32 + 12, ctx.r8.u16);
	// li r5,96
	ctx.r5.s64 = 96;
	// stb r7,41(r3)
	PPC_STORE_U8(ctx.r3.u32 + 41, ctx.r7.u8);
	// li r4,31
	ctx.r4.s64 = 31;
	// stw r6,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, ctx.r6.u32);
	// stw r11,88(r3)
	PPC_STORE_U32(ctx.r3.u32 + 88, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r5,76(r10)
	PPC_STORE_U32(ctx.r10.u32 + 76, ctx.r5.u32);
	// stw r11,92(r10)
	PPC_STORE_U32(ctx.r10.u32 + 92, ctx.r11.u32);
	// stb r4,11(r10)
	PPC_STORE_U8(ctx.r10.u32 + 11, ctx.r4.u8);
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88157994"))) PPC_WEAK_FUNC(sub_88157994);
PPC_FUNC_IMPL(__imp__sub_88157994) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88157998"))) PPC_WEAK_FUNC(sub_88157998);
PPC_FUNC_IMPL(__imp__sub_88157998) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-30658
	ctx.r10.s64 = -2009202688;
	// lbz r9,1(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// addi r11,r10,172
	ctx.r11.s64 = ctx.r10.s64 + 172;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// addi r7,r11,-8
	ctx.r7.s64 = ctx.r11.s64 + -8;
	// lwz r11,172(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 172);
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,172(r10)
	PPC_STORE_U32(ctx.r10.u32 + 172, ctx.r11.u32);
	// stwx r3,r6,r7
	PPC_STORE_U32(ctx.r6.u32 + ctx.r7.u32, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881579C4"))) PPC_WEAK_FUNC(sub_881579C4);
PPC_FUNC_IMPL(__imp__sub_881579C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881579C8"))) PPC_WEAK_FUNC(sub_881579C8);
PPC_FUNC_IMPL(__imp__sub_881579C8) {
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
	// lwz r9,20(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r6,24(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r7,32(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r8,76(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r6,r7,r6
	ctx.r6.u64 = ctx.r7.u64 + ctx.r6.u64;
	// stw r9,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r9.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stw r6,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r6.u32);
	// ble cr6,0x88157a64
	if (!ctx.cr6.gt) goto loc_88157A64;
	// lis r5,8
	ctx.r5.s64 = 524288;
	// cmpw cr6,r9,r5
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r5.s32, ctx.xer);
	// ble cr6,0x88157a1c
	if (!ctx.cr6.gt) goto loc_88157A1C;
	// lis r4,232
	ctx.r4.s64 = 15204352;
	// cmpw cr6,r9,r4
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r4.s32, ctx.xer);
	// blt cr6,0x88157a34
	if (ctx.cr6.lt) goto loc_88157A34;
loc_88157A1C:
	// addi r3,r8,-1
	ctx.r3.s64 = ctx.r8.s64 + -1;
	// neg r4,r10
	ctx.r4.s64 = -ctx.r10.s64;
	// subf r9,r10,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r10.s64;
	// stw r3,76(r11)
	PPC_STORE_U32(ctx.r11.u32 + 76, ctx.r3.u32);
	// stw r4,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r4.u32);
	// stw r9,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r9.u32);
loc_88157A34:
	// cmpw cr6,r6,r5
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r5.s32, ctx.xer);
	// ble cr6,0x88157a48
	if (!ctx.cr6.gt) goto loc_88157A48;
	// lis r10,312
	ctx.r10.s64 = 20447232;
	// cmpw cr6,r6,r10
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x88157a64
	if (ctx.cr6.lt) goto loc_88157A64;
loc_88157A48:
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// subf r9,r7,r6
	ctx.r9.s64 = ctx.r6.s64 - ctx.r7.s64;
	// neg r8,r7
	ctx.r8.s64 = -ctx.r7.s64;
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// stw r9,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r9.u32);
	// stw r8,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r8.u32);
	// stw r7,76(r11)
	PPC_STORE_U32(ctx.r11.u32 + 76, ctx.r7.u32);
loc_88157A64:
	// lbz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 40);
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// stb r8,40(r11)
	PPC_STORE_U8(ctx.r11.u32 + 40, ctx.r8.u8);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bge cr6,0x88157a98
	if (!ctx.cr6.lt) goto loc_88157A98;
	// lbz r10,11(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 11);
	// lbz r9,41(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 41);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// clrlwi r7,r8,30
	ctx.r7.u64 = ctx.r8.u32 & 0x3;
	// stb r9,40(r11)
	PPC_STORE_U8(ctx.r11.u32 + 40, ctx.r9.u8);
	// stb r7,11(r11)
	PPC_STORE_U8(ctx.r11.u32 + 11, ctx.r7.u8);
loc_88157A98:
	// lbz r9,11(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 11);
	// lhz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 16);
	// lhz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + 12);
	// extsb r9,r9
	ctx.r9.s64 = ctx.r9.s8;
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// lwz r5,24(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// add r3,r10,r9
	ctx.r3.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r4,20(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// bl 0x881538c0
	ctx.lr = 0x88157ABC;
	sub_881538C0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// beq cr6,0x88157ad8
	if (ctx.cr6.eq) goto loc_88157AD8;
	// lis r10,-30663
	ctx.r10.s64 = -2009530368;
	// lwz r10,-30236(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -30236);
	// stw r10,48(r11)
	PPC_STORE_U32(ctx.r11.u32 + 48, ctx.r10.u32);
loc_88157AD8:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88157AE8"))) PPC_WEAK_FUNC(sub_88157AE8);
PPC_FUNC_IMPL(__imp__sub_88157AE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,20(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lbz r8,40(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 40);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r9,24(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// lwz r8,32(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// stw r4,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r4.u32);
	// addi r7,r11,-1
	ctx.r7.s64 = ctx.r11.s64 + -1;
	// add r5,r8,r9
	ctx.r5.u64 = ctx.r8.u64 + ctx.r9.u64;
	// extsb r6,r7
	ctx.r6.s64 = ctx.r7.s8;
	// stw r5,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r5.u32);
	// stb r6,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, ctx.r6.u8);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bge cr6,0x88157bc0
	if (!ctx.cr6.lt) goto loc_88157BC0;
	// lbz r11,11(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 11);
	// lbz r10,41(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 41);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// stb r10,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, ctx.r10.u8);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stb r8,11(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11, ctx.r8.u8);
	// bgt cr6,0x88157bc0
	if (ctx.cr6.gt) goto loc_88157BC0;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lhz r10,50(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 50);
	// lwz r11,26276(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// addi r11,r10,256
	ctx.r11.s64 = ctx.r10.s64 + 256;
	// bne cr6,0x88157ba8
	if (!ctx.cr6.eq) goto loc_88157BA8;
	// lwz r10,128(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// li r9,0
	ctx.r9.s64 = 0;
	// clrlwi r7,r11,16
	ctx.r7.u64 = ctx.r11.u32 & 0xFFFF;
	// li r6,-36
	ctx.r6.s64 = -36;
	// sth r9,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r9.u16);
	// li r3,18
	ctx.r3.s64 = 18;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x8815c948
	ctx.lr = 0x88157B8C;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8815c860
	ctx.lr = 0x88157B98;
	sub_8815C860(ctx, base);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x88157ba8
	if (ctx.cr6.eq) goto loc_88157BA8;
	// li r11,1
	ctx.r11.s64 = 1;
	// sth r11,16(r31)
	PPC_STORE_U16(ctx.r31.u32 + 16, ctx.r11.u16);
loc_88157BA8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_88157BC0:
	// lbz r11,11(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 11);
	// li r6,213
	ctx.r6.s64 = 213;
	// extsb r9,r11
	ctx.r9.s64 = ctx.r11.s8;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// srawi r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// addze r11,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r11.s64 = temp.s64;
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addis r3,r7,1
	ctx.r3.s64 = ctx.r7.s64 + 65536;
	// addi r3,r3,-20370
	ctx.r3.s64 = ctx.r3.s64 + -20370;
	// bl 0x881538c0
	ctx.lr = 0x88157BEC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88157c14
	if (ctx.cr6.eq) goto loc_88157C14;
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
loc_88157C14:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88157C2C"))) PPC_WEAK_FUNC(sub_88157C2C);
PPC_FUNC_IMPL(__imp__sub_88157C2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88157C30"))) PPC_WEAK_FUNC(sub_88157C30);
PPC_FUNC_IMPL(__imp__sub_88157C30) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x88157C38;
	__savegprlr_25(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,40(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 40);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, ctx.r9.u8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge cr6,0x88157d2c
	if (!ctx.cr6.lt) goto loc_88157D2C;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lbz r10,41(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 41);
	// lwz r29,20(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r28,24(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lhz r27,50(r3)
	ctx.r27.u64 = PPC_LOAD_U16(ctx.r3.u32 + 50);
	// lwz r11,26276(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
	// stb r10,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, ctx.r10.u8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88157d08
	if (!ctx.cr6.eq) goto loc_88157D08;
	// lwz r11,128(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// addi r10,r27,128
	ctx.r10.s64 = ctx.r27.s64 + 128;
	// li r26,0
	ctx.r26.s64 = 0;
	// li r6,-24
	ctx.r6.s64 = -24;
	// clrlwi r7,r10,16
	ctx.r7.u64 = ctx.r10.u32 & 0xFFFF;
	// sth r26,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r26.u16);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// li r3,30
	ctx.r3.s64 = 30;
	// bl 0x8815c948
	ctx.lr = 0x88157CA8;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x8815c860
	ctx.lr = 0x88157CB4;
	sub_8815C860(ctx, base);
	// li r25,-1
	ctx.r25.s64 = -1;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x88157cc4
	if (ctx.cr6.eq) goto loc_88157CC4;
	// sth r25,16(r30)
	PPC_STORE_U16(ctx.r30.u32 + 16, ctx.r25.u16);
loc_88157CC4:
	// addis r10,r27,1
	ctx.r10.s64 = ctx.r27.s64 + 65536;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// li r6,-24
	ctx.r6.s64 = -24;
	// sth r26,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r26.u16);
	// addi r10,r10,-128
	ctx.r10.s64 = ctx.r10.s64 + -128;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// clrlwi r7,r10,16
	ctx.r7.u64 = ctx.r10.u32 & 0xFFFF;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// li r3,30
	ctx.r3.s64 = 30;
	// bl 0x8815c948
	ctx.lr = 0x88157CF0;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x8815c860
	ctx.lr = 0x88157CFC;
	sub_8815C860(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x88157d08
	if (ctx.cr6.eq) goto loc_88157D08;
	// sth r25,16(r30)
	PPC_STORE_U16(ctx.r30.u32 + 16, ctx.r25.u16);
loc_88157D08:
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// addi r10,r11,-2
	ctx.r10.s64 = ctx.r11.s64 + -2;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r9.u8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bgt cr6,0x88157d2c
	if (ctx.cr6.gt) goto loc_88157D2C;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_88157D2C:
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// li r6,219
	ctx.r6.s64 = 219;
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addis r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 65536;
	// addi r3,r3,-20370
	ctx.r3.s64 = ctx.r3.s64 + -20370;
	// bl 0x881538c0
	ctx.lr = 0x88157D4C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88157d74
	if (ctx.cr6.eq) goto loc_88157D74;
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
loc_88157D74:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88157D80"))) PPC_WEAK_FUNC(sub_88157D80);
PPC_FUNC_IMPL(__imp__sub_88157D80) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,40(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 40);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, ctx.r9.u8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge cr6,0x88157f08
	if (!ctx.cr6.lt) goto loc_88157F08;
	// lbz r11,41(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 41);
	// lbz r10,11(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 11);
	// cmplwi cr6,r10,20
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 20, ctx.xer);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, ctx.r11.u8);
	// bne cr6,0x88157ed8
	if (!ctx.cr6.eq) goto loc_88157ED8;
	// lwz r11,56(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// lwz r4,20(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r5,24(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lhz r10,50(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 50);
	// lwz r11,52(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// beq cr6,0x88157e58
	if (ctx.cr6.eq) goto loc_88157E58;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26276(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
	// ble cr6,0x88157e20
	if (!ctx.cr6.gt) goto loc_88157E20;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88157ed8
	if (!ctx.cr6.eq) goto loc_88157ED8;
	// lis r9,-30658
	ctx.r9.s64 = -2009202688;
	// lwz r8,128(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// li r3,5
	ctx.r3.s64 = 5;
	// addi r7,r10,128
	ctx.r7.s64 = ctx.r10.s64 + 128;
	// stw r3,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r3.u32);
	// li r3,35
	ctx.r3.s64 = 35;
	// lwz r10,156(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 156);
	// li r9,32
	ctx.r9.s64 = 32;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// subfic r8,r10,8
	ctx.xer.ca = ctx.r10.u32 <= 8;
	ctx.r8.s64 = 8 - ctx.r10.s64;
	// b 0x88157eac
	goto loc_88157EAC;
loc_88157E20:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88157ed8
	if (!ctx.cr6.eq) goto loc_88157ED8;
	// lis r9,-30658
	ctx.r9.s64 = -2009202688;
	// lwz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// addis r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 65536;
	// li r3,5
	ctx.r3.s64 = 5;
	// addi r7,r7,-128
	ctx.r7.s64 = ctx.r7.s64 + -128;
	// stw r3,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r3.u32);
	// li r3,35
	ctx.r3.s64 = 35;
	// lwz r10,156(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 156);
	// li r9,32
	ctx.r9.s64 = 32;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// subfic r8,r10,8
	ctx.xer.ca = ctx.r10.u32 <= 8;
	ctx.r8.s64 = 8 - ctx.r10.s64;
	// b 0x88157eac
	goto loc_88157EAC;
loc_88157E58:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26276(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
	// ble cr6,0x88157e7c
	if (!ctx.cr6.gt) goto loc_88157E7C;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88157ed8
	if (!ctx.cr6.eq) goto loc_88157ED8;
	// addis r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 65536;
	// addi r7,r7,-128
	ctx.r7.s64 = ctx.r7.s64 + -128;
	// b 0x88157e88
	goto loc_88157E88;
loc_88157E7C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88157ed8
	if (!ctx.cr6.eq) goto loc_88157ED8;
	// addi r7,r10,128
	ctx.r7.s64 = ctx.r10.s64 + 128;
loc_88157E88:
	// lis r9,-30658
	ctx.r9.s64 = -2009202688;
	// lwz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r3,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r3.u32);
	// li r3,61
	ctx.r3.s64 = 61;
	// lwz r10,156(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 156);
	// li r9,40
	ctx.r9.s64 = 40;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// subfic r8,r10,16
	ctx.xer.ca = ctx.r10.u32 <= 16;
	ctx.r8.s64 = 16 - ctx.r10.s64;
loc_88157EAC:
	// li r6,16
	ctx.r6.s64 = 16;
	// stw r9,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r6,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r6.u32);
	// clrlwi r7,r7,16
	ctx.r7.u64 = ctx.r7.u32 & 0xFFFF;
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// sth r11,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r11.u16);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// bl 0x8815c948
	ctx.lr = 0x88157ED0;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x88157ED8;
	sub_8815C860(ctx, base);
loc_88157ED8:
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r9.u8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bgt cr6,0x88157f08
	if (ctx.cr6.gt) goto loc_88157F08;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_88157F08:
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// li r6,214
	ctx.r6.s64 = 214;
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addis r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 65536;
	// addi r3,r3,-20370
	ctx.r3.s64 = ctx.r3.s64 + -20370;
	// bl 0x881538c0
	ctx.lr = 0x88157F28;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88157f50
	if (ctx.cr6.eq) goto loc_88157F50;
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
loc_88157F50:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88157F68"))) PPC_WEAK_FUNC(sub_88157F68);
PPC_FUNC_IMPL(__imp__sub_88157F68) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88157F70;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-30658
	ctx.r10.s64 = -2009202688;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r31,r10,164
	ctx.r31.s64 = ctx.r10.s64 + 164;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lis r6,-30671
	ctx.r6.s64 = -2010054656;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lis r5,16838
	ctx.r5.s64 = 1103495168;
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r3,132(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// ori r11,r5,20077
	ctx.r11.u64 = ctx.r5.u64 | 20077;
	// lwz r10,4200(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4200);
	// lis r9,-30699
	ctx.r9.s64 = -2011889664;
	// stw r8,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r8.u32);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// addi r11,r10,12345
	ctx.r11.s64 = ctx.r10.s64 + 12345;
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// stw r11,4200(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4200, ctx.r11.u32);
	// addi r4,r9,31128
	ctx.r4.s64 = ctx.r9.s64 + 31128;
	// lhz r11,4200(r6)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r6.u32 + 4200);
	// clrlwi r30,r11,31
	ctx.r30.u64 = ctx.r11.u32 & 0x1;
	// bl 0x881363e0
	ctx.lr = 0x88157FD8;
	sub_881363E0(ctx, base);
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88157ff0
	if (!ctx.cr6.eq) goto loc_88157FF0;
loc_88157FE4:
	// li r3,256
	ctx.r3.s64 = 256;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_88157FF0:
	// extsh r11,r30
	ctx.r11.s64 = ctx.r30.s16;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88158010
	if (!ctx.cr6.eq) goto loc_88158010;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88158028
	if (!ctx.cr6.eq) goto loc_88158028;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// b 0x88158020
	goto loc_88158020;
loc_88158010:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88158028
	if (!ctx.cr6.eq) goto loc_88158028;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
loc_88158020:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88157fe4
	if (ctx.cr6.eq) goto loc_88157FE4;
loc_88158028:
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// lwz r4,68(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r3,64(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// bl 0x88153070
	ctx.lr = 0x8815803C;
	sub_88153070(ctx, base);
	// clrlwi r3,r3,16
	ctx.r3.u64 = ctx.r3.u32 & 0xFFFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88158048"))) PPC_WEAK_FUNC(sub_88158048);
PPC_FUNC_IMPL(__imp__sub_88158048) {
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
	// bl 0x8815a220
	ctx.lr = 0x88158060;
	sub_8815A220(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,2
	ctx.r10.s64 = 2;
	// li r9,3165
	ctx.r9.s64 = 3165;
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// li r8,4
	ctx.r8.s64 = 4;
	// stb r10,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r10.u8);
	// li r7,1
	ctx.r7.s64 = 1;
	// sth r9,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r9.u16);
	// stw r10,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r8,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r8.u32);
	// stw r11,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r11.u32);
	// stw r11,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// stw r7,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r7.u32);
	// stw r11,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
	// stw r11,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// stw r11,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_881580B8"))) PPC_WEAK_FUNC(sub_881580B8);
PPC_FUNC_IMPL(__imp__sub_881580B8) {
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
	// lwz r8,52(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// addi r5,r10,9552
	ctx.r5.s64 = ctx.r10.s64 + 9552;
	// beq cr6,0x88158144
	if (ctx.cr6.eq) goto loc_88158144;
	// lwz r10,56(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r10.u32);
	// bgt 0x88158144
	if (ctx.cr0.gt) goto loc_88158144;
	// lhz r9,36(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 36);
	// addic. r10,r3,32
	ctx.xer.ca = ctx.r3.u32 > 4294967263;
	ctx.r10.s64 = ctx.r3.s64 + 32;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r6,60(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// addi r7,r3,28
	ctx.r7.s64 = ctx.r3.s64 + 28;
	// lhz r4,50(r3)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r3.u32 + 50);
	// add r3,r9,r8
	ctx.r3.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsh r8,r3
	ctx.r8.s64 = ctx.r3.s16;
	// clrlwi r9,r4,23
	ctx.r9.u64 = ctx.r4.u32 & 0x1FF;
	// stw r6,56(r11)
	PPC_STORE_U32(ctx.r11.u32 + 56, ctx.r6.u32);
	// sth r8,36(r11)
	PPC_STORE_U16(ctx.r11.u32 + 36, ctx.r8.u16);
	// beq 0x8815812c
	if (ctx.cr0.eq) goto loc_8815812C;
	// addi r6,r9,128
	ctx.r6.s64 = ctx.r9.s64 + 128;
	// rlwinm r4,r6,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// lwzx r3,r4,r5
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r5.u32);
	// mullw r6,r3,r8
	ctx.r6.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r8.s32);
	// stw r6,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r6.u32);
loc_8815812C:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x88158144
	if (ctx.cr6.eq) goto loc_88158144;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r5
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r5.u32);
	// mullw r8,r9,r8
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// stw r8,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r8.u32);
loc_88158144:
	// lwz r6,20(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r7,28(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// lwz r8,24(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// lwz r9,32(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// add r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 + ctx.r6.u64;
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 72);
	// add r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 + ctx.r8.u64;
	// stw r7,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r7.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r6,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r6.u32);
	// beq cr6,0x88158208
	if (ctx.cr6.eq) goto loc_88158208;
	// lwz r9,80(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r9,80(r11)
	PPC_STORE_U32(ctx.r11.u32 + 80, ctx.r9.u32);
	// bgt 0x881581e8
	if (ctx.cr0.gt) goto loc_881581E8;
	// lwz r8,68(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// lwz r7,84(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// stw r10,68(r11)
	PPC_STORE_U32(ctx.r11.u32 + 68, ctx.r10.u32);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// stw r7,80(r11)
	PPC_STORE_U32(ctx.r11.u32 + 80, ctx.r7.u32);
	// ble cr6,0x881581a4
	if (!ctx.cr6.gt) goto loc_881581A4;
	// stw r9,68(r11)
	PPC_STORE_U32(ctx.r11.u32 + 68, ctx.r9.u32);
loc_881581A4:
	// lwz r8,64(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// addic. r10,r11,112
	ctx.xer.ca = ctx.r11.u32 > 4294967183;
	ctx.r10.s64 = ctx.r11.s64 + 112;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r9,68(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// addi r7,r11,108
	ctx.r7.s64 = ctx.r11.s64 + 108;
	// clrlwi r8,r8,23
	ctx.r8.u64 = ctx.r8.u32 & 0x1FF;
	// beq 0x881581d0
	if (ctx.cr0.eq) goto loc_881581D0;
	// addi r6,r8,128
	ctx.r6.s64 = ctx.r8.s64 + 128;
	// rlwinm r4,r6,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// lwzx r3,r4,r5
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r5.u32);
	// mullw r6,r3,r9
	ctx.r6.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r9.s32);
	// stw r6,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r6.u32);
loc_881581D0:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x881581e8
	if (ctx.cr6.eq) goto loc_881581E8;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r10,r5
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r5.u32);
	// mullw r6,r8,r9
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// stw r6,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r6.u32);
loc_881581E8:
	// lwz r7,20(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r8,108(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 108);
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// lwz r10,112(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 112);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r8,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r8.u32);
	// stw r7,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r7.u32);
loc_88158208:
	// lbz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 40);
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// stb r8,40(r11)
	PPC_STORE_U8(ctx.r11.u32 + 40, ctx.r8.u8);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bge cr6,0x8815823c
	if (!ctx.cr6.lt) goto loc_8815823C;
	// lbz r10,11(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 11);
	// lbz r9,41(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 41);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// clrlwi r7,r8,30
	ctx.r7.u64 = ctx.r8.u32 & 0x3;
	// stb r9,40(r11)
	PPC_STORE_U8(ctx.r11.u32 + 40, ctx.r9.u8);
	// stb r7,11(r11)
	PPC_STORE_U8(ctx.r11.u32 + 11, ctx.r7.u8);
loc_8815823C:
	// lbz r9,11(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 11);
	// lhz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 16);
	// lhz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + 12);
	// extsb r9,r9
	ctx.r9.s64 = ctx.r9.s8;
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// lwz r5,24(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// add r3,r10,r9
	ctx.r3.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r4,20(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// bl 0x881538c0
	ctx.lr = 0x88158260;
	sub_881538C0(ctx, base);
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

__attribute__((alias("__imp__sub_88158274"))) PPC_WEAK_FUNC(sub_88158274);
PPC_FUNC_IMPL(__imp__sub_88158274) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88158278"))) PPC_WEAK_FUNC(sub_88158278);
PPC_FUNC_IMPL(__imp__sub_88158278) {
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
	// bl 0x8815a220
	ctx.lr = 0x88158290;
	sub_8815A220(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,3139
	ctx.r10.s64 = 3139;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r11,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
	// sth r10,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r10.u16);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r9,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r9.u8);
	// stw r11,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_881582C4"))) PPC_WEAK_FUNC(sub_881582C4);
PPC_FUNC_IMPL(__imp__sub_881582C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881582C8"))) PPC_WEAK_FUNC(sub_881582C8);
PPC_FUNC_IMPL(__imp__sub_881582C8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x881582D0;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r9,20(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r8,28(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r7,76(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// add r30,r8,r9
	ctx.r30.u64 = ctx.r8.u64 + ctx.r9.u64;
	// add r29,r11,r10
	ctx.r29.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r30,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r30.u32);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stw r29,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r29.u32);
	// beq cr6,0x88158360
	if (ctx.cr6.eq) goto loc_88158360;
	// lwz r11,68(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, ctx.r11.u32);
	// bge 0x88158360
	if (!ctx.cr0.lt) goto loc_88158360;
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r11,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, ctx.r11.u32);
	// bl 0x88157f68
	ctx.lr = 0x88158328;
	sub_88157F68(ctx, base);
	// li r9,-4
	ctx.r9.s64 = -4;
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// li r10,64
	ctx.r10.s64 = 64;
	// li r9,3
	ctx.r9.s64 = 3;
	// li r7,-32
	ctx.r7.s64 = -32;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r4,18
	ctx.r4.s64 = 18;
	// bl 0x88094690
	ctx.lr = 0x88158354;
	sub_88094690(ctx, base);
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// addi r8,r11,-1
	ctx.r8.s64 = ctx.r11.s64 + -1;
	// stw r8,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r8.u32);
loc_88158360:
	// lbz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 40);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r9.u8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge cr6,0x88158394
	if (!ctx.cr6.lt) goto loc_88158394;
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lbz r10,41(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 41);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// clrlwi r8,r9,30
	ctx.r8.u64 = ctx.r9.u32 & 0x3;
	// stb r10,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r10.u8);
	// stb r8,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r8.u8);
loc_88158394:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8815a360
	ctx.lr = 0x8815839C;
	sub_8815A360(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_881583A8"))) PPC_WEAK_FUNC(sub_881583A8);
PPC_FUNC_IMPL(__imp__sub_881583A8) {
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
	// bl 0x8815a140
	ctx.lr = 0x881583C0;
	sub_8815A140(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// lhz r6,12(r31)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r11,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r11.u8);
	// rotlwi r11,r6,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r6.u32, 2);
	// li r9,4
	ctx.r9.s64 = 4;
	// stb r10,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r10.u8);
	// li r8,2
	ctx.r8.s64 = 2;
	// li r7,7
	ctx.r7.s64 = 7;
	// stw r9,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r9.u32);
	// addi r5,r11,2363
	ctx.r5.s64 = ctx.r11.s64 + 2363;
	// stw r8,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r8.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r7,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r7.u32);
	// sth r5,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r5.u16);
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

__attribute__((alias("__imp__sub_88158410"))) PPC_WEAK_FUNC(sub_88158410);
PPC_FUNC_IMPL(__imp__sub_88158410) {
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
	// lwz r11,20(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r9,24(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r7,68(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r8,32(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// addic. r11,r7,-1
	ctx.xer.ca = ctx.r7.u32 > 0;
	ctx.r11.s64 = ctx.r7.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r4,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r4.u32);
	// add r5,r8,r9
	ctx.r5.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stw r11,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, ctx.r11.u32);
	// stw r5,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r5.u32);
	// bge 0x881584ec
	if (!ctx.cr0.lt) goto loc_881584EC;
	// lwz r9,72(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// lwz r8,52(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// lhz r11,50(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 50);
	// lwz r10,76(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stw r9,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, ctx.r9.u32);
	// lis r9,-30643
	ctx.r9.s64 = -2008219648;
	// lwz r9,26276(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 26276);
	// bge cr6,0x88158494
	if (!ctx.cr6.lt) goto loc_88158494;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x881584e0
	if (!ctx.cr6.eq) goto loc_881584E0;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r8,r11,24
	ctx.r8.s64 = ctx.r11.s64 + 24;
	// sth r3,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r3.u16);
	// b 0x881584ac
	goto loc_881584AC;
loc_88158494:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x881584e0
	if (!ctx.cr6.eq) goto loc_881584E0;
	// addis r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 65536;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r8,r8,-24
	ctx.r8.s64 = ctx.r8.s64 + -24;
	// sth r7,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r7.u16);
loc_881584AC:
	// lwz r9,128(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// extsh r6,r10
	ctx.r6.s64 = ctx.r10.s16;
	// li r3,30
	ctx.r3.s64 = 30;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x8815c948
	ctx.lr = 0x881584C4;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x8815c860
	ctx.lr = 0x881584D0;
	sub_8815C860(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x881584e0
	if (ctx.cr6.eq) goto loc_881584E0;
	// li r11,1
	ctx.r11.s64 = 1;
	// sth r11,16(r30)
	PPC_STORE_U16(ctx.r30.u32 + 16, ctx.r11.u16);
loc_881584E0:
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
loc_881584EC:
	// lbz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 40);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r9.u8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge cr6,0x88158520
	if (!ctx.cr6.lt) goto loc_88158520;
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lbz r10,41(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 41);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// clrlwi r8,r9,30
	ctx.r8.u64 = ctx.r9.u32 & 0x3;
	// stb r10,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r10.u8);
	// stb r8,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r8.u8);
loc_88158520:
	// lbz r10,11(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lhz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// extsh r6,r9
	ctx.r6.s64 = ctx.r9.s16;
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// bl 0x881538c0
	ctx.lr = 0x88158544;
	sub_881538C0(ctx, base);
	// lis r3,0
	ctx.r3.s64 = 0;
	// li r6,218
	ctx.r6.s64 = 218;
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// ori r3,r3,45190
	ctx.r3.u64 = ctx.r3.u64 | 45190;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// bl 0x881538c0
	ctx.lr = 0x8815855C;
	sub_881538C0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// beq cr6,0x8815858c
	if (ctx.cr6.eq) goto loc_8815858C;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// oris r7,r8,545
	ctx.r7.u64 = ctx.r8.u64 | 35717120;
	// ori r7,r7,65280
	ctx.r7.u64 = ctx.r7.u64 | 65280;
	// lwz r10,-11932(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -11932);
	// stw r7,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// addi r11,r10,1
	ctx.r11.s64 = ctx.r10.s64 + 1;
	// stw r11,-11932(r9)
	PPC_STORE_U32(ctx.r9.u32 + -11932, ctx.r11.u32);
loc_8815858C:
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

__attribute__((alias("__imp__sub_881585A4"))) PPC_WEAK_FUNC(sub_881585A4);
PPC_FUNC_IMPL(__imp__sub_881585A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881585A8"))) PPC_WEAK_FUNC(sub_881585A8);
PPC_FUNC_IMPL(__imp__sub_881585A8) {
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
	// bl 0x8815a220
	ctx.lr = 0x881585C0;
	sub_8815A220(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r9,3169
	ctx.r9.s64 = 3169;
	// stb r10,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r10.u8);
	// li r8,-8
	ctx.r8.s64 = -8;
	// stb r11,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r11.u8);
	// sth r9,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r9.u16);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r10.u32);
	// stw r11,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// stw r8,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r8.u32);
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

__attribute__((alias("__imp__sub_88158600"))) PPC_WEAK_FUNC(sub_88158600);
PPC_FUNC_IMPL(__imp__sub_88158600) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x88158608;
	__savegprlr_24(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r9,20(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r8,24(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r11,68(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r7,32(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// add r30,r9,r10
	ctx.r30.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r28,r7,r8
	ctx.r28.u64 = ctx.r7.u64 + ctx.r8.u64;
	// stw r11,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, ctx.r11.u32);
	// stw r30,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r30.u32);
	// stw r28,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r28.u32);
	// bge 0x881586d0
	if (!ctx.cr0.lt) goto loc_881586D0;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r10,72(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// lhz r27,50(r3)
	ctx.r27.u64 = PPC_LOAD_U16(ctx.r3.u32 + 50);
	// stw r29,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r29.u32);
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r29.u32);
	// lwz r26,26276(r11)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
	// stw r10,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, ctx.r10.u32);
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// bne cr6,0x88158694
	if (!ctx.cr6.eq) goto loc_88158694;
	// lwz r11,128(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// clrlwi r7,r27,16
	ctx.r7.u64 = ctx.r27.u32 & 0xFFFF;
	// li r6,0
	ctx.r6.s64 = 0;
	// sth r29,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r29.u16);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,69
	ctx.r3.s64 = 69;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x8815c948
	ctx.lr = 0x8815868C;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x88158694;
	sub_8815C860(ctx, base);
loc_88158694:
	// li r11,1
	ctx.r11.s64 = 1;
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// bne cr6,0x881586d0
	if (!ctx.cr6.eq) goto loc_881586D0;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// clrlwi r7,r27,16
	ctx.r7.u64 = ctx.r27.u32 & 0xFFFF;
	// li r6,0
	ctx.r6.s64 = 0;
	// sth r29,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r29.u16);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,69
	ctx.r3.s64 = 69;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x8815c948
	ctx.lr = 0x881586C8;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x881586D0;
	sub_8815C860(ctx, base);
loc_881586D0:
	// lbz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 40);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r9.u8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge cr6,0x8815870c
	if (!ctx.cr6.lt) goto loc_8815870C;
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lbz r10,41(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 41);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// stb r10,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r10.u8);
	// cmpwi cr6,r8,3
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 3, ctx.xer);
	// stb r8,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r8.u8);
	// ble cr6,0x8815870c
	if (!ctx.cr6.gt) goto loc_8815870C;
	// stb r29,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r29.u8);
loc_8815870C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8815a360
	ctx.lr = 0x88158714;
	sub_8815A360(ctx, base);
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// lhz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 36);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r11,42
	ctx.r9.s64 = ctx.r11.s64 + 42;
	// cmpw cr6,r7,r9
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x88158800
	if (ctx.cr6.lt) goto loc_88158800;
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x88158800
	if (!ctx.cr6.gt) goto loc_88158800;
	// lis r27,-30597
	ctx.r27.s64 = -2005204992;
	// lis r11,-30663
	ctx.r11.s64 = -2009530368;
	// lis r10,-30663
	ctx.r10.s64 = -2009530368;
	// lis r9,-30658
	ctx.r9.s64 = -2009202688;
	// lwz r30,-11932(r27)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
	// lwz r24,-30240(r11)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r11.u32 + -30240);
	// lwz r25,-22224(r10)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + -22224);
	// lwz r26,160(r9)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
loc_8815876C:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r28,r29,1
	ctx.r28.s64 = ctx.r29.s64 + 1;
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lbz r8,11(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// mullw r7,r11,r28
	ctx.r7.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lhz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// mullw r3,r28,r9
	ctx.r3.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r9.s32);
	// extsb r10,r8
	ctx.r10.s64 = ctx.r8.s8;
	// subf r4,r3,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r3.s64;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// subf r5,r7,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r7.s64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x881587AC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x881587ec
	if (ctx.cr6.eq) goto loc_881587EC;
	// subf r11,r29,r24
	ctx.r11.s64 = ctx.r24.s64 - ctx.r29.s64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// mullw r11,r11,r25
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r25.s32);
	// add r8,r11,r26
	ctx.r8.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// rlwimi r9,r8,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r30,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r30.u32);
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// lbz r6,10(r31)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10);
	// rlwinm r5,r6,26,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 26) & 0xFFFFFFFC;
	// or r4,r5,r7
	ctx.r4.u64 = ctx.r5.u64 | ctx.r7.u64;
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
loc_881587EC:
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpw cr6,r28,r10
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x8815876c
	if (ctx.cr6.lt) goto loc_8815876C;
loc_88158800:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8815880C"))) PPC_WEAK_FUNC(sub_8815880C);
PPC_FUNC_IMPL(__imp__sub_8815880C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88158810"))) PPC_WEAK_FUNC(sub_88158810);
PPC_FUNC_IMPL(__imp__sub_88158810) {
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
	// bl 0x8815a220
	ctx.lr = 0x88158828;
	sub_8815A220(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// lhz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r11,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r11.u8);
	// li r9,3
	ctx.r9.s64 = 3;
	// stw r11,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// rotlwi r11,r8,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r10,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r10.u8);
	// addi r7,r11,2363
	ctx.r7.s64 = ctx.r11.s64 + 2363;
	// stw r9,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r9.u32);
	// sth r7,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r7.u16);
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

__attribute__((alias("__imp__sub_8815886C"))) PPC_WEAK_FUNC(sub_8815886C);
PPC_FUNC_IMPL(__imp__sub_8815886C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88158870"))) PPC_WEAK_FUNC(sub_88158870);
PPC_FUNC_IMPL(__imp__sub_88158870) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88158878;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r9,20(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r8,24(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r6,r3,28
	ctx.r6.s64 = ctx.r3.s64 + 28;
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// addi r11,r3,32
	ctx.r11.s64 = ctx.r3.s64 + 32;
	// lwz r7,32(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r5,80(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// add r4,r9,r10
	ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r3,r7,r8
	ctx.r3.u64 = ctx.r7.u64 + ctx.r8.u64;
	// stw r4,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r4.u32);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// bne cr6,0x881588dc
	if (!ctx.cr6.eq) goto loc_881588DC;
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r10.u32);
	// bge 0x881588dc
	if (!ctx.cr0.lt) goto loc_881588DC;
	// lwz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// lwz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// lwz r9,52(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// add r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r8,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r8.u32);
	// stw r7,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r7.u32);
loc_881588DC:
	// lbz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 40);
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// stb r8,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r8.u8);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bge cr6,0x881589ec
	if (!ctx.cr6.lt) goto loc_881589EC;
	// lhz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 36);
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// lbz r7,41(r31)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r31.u32 + 41);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// addi r4,r9,-1
	ctx.r4.s64 = ctx.r9.s64 + -1;
	// lhz r5,50(r31)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// addi r8,r10,9552
	ctx.r8.s64 = ctx.r10.s64 + 9552;
	// extsh r3,r4
	ctx.r3.s64 = ctx.r4.s16;
	// clrlwi r10,r5,23
	ctx.r10.u64 = ctx.r5.u32 & 0x1FF;
	// stb r7,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r7.u8);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// sth r3,36(r31)
	PPC_STORE_U16(ctx.r31.u32 + 36, ctx.r3.u16);
	// beq cr6,0x8815893c
	if (ctx.cr6.eq) goto loc_8815893C;
	// addi r7,r10,128
	ctx.r7.s64 = ctx.r10.s64 + 128;
	// rlwinm r5,r7,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x7FC;
	// lwzx r4,r5,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r8.u32);
	// mullw r3,r4,r3
	ctx.r3.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r3.s32);
	// stw r3,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
loc_8815893C:
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x88158954
	if (ctx.cr6.eq) goto loc_88158954;
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r8
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r8.u32);
	// mullw r9,r10,r9
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// stw r9,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r9.u32);
loc_88158954:
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x881589b8
	if (!ctx.cr6.eq) goto loc_881589B8;
	// lhz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 36);
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// cmpwi cr6,r10,8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 8, ctx.xer);
	// bgt cr6,0x881589b8
	if (ctx.cr6.gt) goto loc_881589B8;
	// lwz r29,20(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r28,24(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x88157f68
	ctx.lr = 0x88158988;
	sub_88157F68(ctx, base);
	// li r30,1
	ctx.r30.s64 = 1;
	// li r10,20
	ctx.r10.s64 = 20;
	// lhz r8,50(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// li r9,3
	ctx.r9.s64 = 3;
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// li r7,-40
	ctx.r7.s64 = -40;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// li r4,49
	ctx.r4.s64 = 49;
	// bl 0x88094690
	ctx.lr = 0x881589B4;
	sub_88094690(ctx, base);
	// stw r30,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r30.u32);
loc_881589B8:
	// lhz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 36);
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// stb r10,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r10.u8);
	// cmpwi cr6,r10,31
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 31, ctx.xer);
	// blt cr6,0x881589d4
	if (ctx.cr6.lt) goto loc_881589D4;
	// li r10,31
	ctx.r10.s64 = 31;
	// stb r10,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r10.u8);
loc_881589D4:
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt cr6,0x881589ec
	if (ctx.cr6.gt) goto loc_881589EC;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_881589EC:
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// li r6,218
	ctx.r6.s64 = 218;
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addis r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 65536;
	// addi r3,r3,-20370
	ctx.r3.s64 = ctx.r3.s64 + -20370;
	// bl 0x881538c0
	ctx.lr = 0x88158A0C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88158a34
	if (ctx.cr6.eq) goto loc_88158A34;
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
loc_88158A34:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88158A40"))) PPC_WEAK_FUNC(sub_88158A40);
PPC_FUNC_IMPL(__imp__sub_88158A40) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x88158A48;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,112(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88158bac
	if (!ctx.cr6.eq) goto loc_88158BAC;
	// lwz r8,52(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// addi r6,r11,9552
	ctx.r6.s64 = ctx.r11.s64 + 9552;
	// beq cr6,0x88158adc
	if (ctx.cr6.eq) goto loc_88158ADC;
	// lwz r11,56(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r11.u32);
	// bgt 0x88158adc
	if (ctx.cr0.gt) goto loc_88158ADC;
	// lhz r9,36(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 36);
	// addic. r11,r3,32
	ctx.xer.ca = ctx.r3.u32 > 4294967263;
	ctx.r11.s64 = ctx.r3.s64 + 32;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r5,60(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// addi r7,r3,28
	ctx.r7.s64 = ctx.r3.s64 + 28;
	// lhz r4,50(r3)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r3.u32 + 50);
	// add r3,r9,r8
	ctx.r3.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsh r9,r3
	ctx.r9.s64 = ctx.r3.s16;
	// clrlwi r10,r4,23
	ctx.r10.u64 = ctx.r4.u32 & 0x1FF;
	// stw r5,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r5.u32);
	// sth r9,36(r31)
	PPC_STORE_U16(ctx.r31.u32 + 36, ctx.r9.u16);
	// beq 0x88158ac4
	if (ctx.cr0.eq) goto loc_88158AC4;
	// addi r8,r10,128
	ctx.r8.s64 = ctx.r10.s64 + 128;
	// rlwinm r5,r8,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x7FC;
	// lwzx r4,r5,r6
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r6.u32);
	// mullw r3,r4,r9
	ctx.r3.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r9.s32);
	// stw r3,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
loc_88158AC4:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x88158adc
	if (ctx.cr6.eq) goto loc_88158ADC;
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r6
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r6.u32);
	// mullw r9,r10,r9
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// stw r9,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r9.u32);
loc_88158ADC:
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// bge 0x88158cc4
	if (!ctx.cr0.lt) goto loc_88158CC4;
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,92(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// stw r29,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r29.u32);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r10,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r10.u32);
	// stw r11,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
	// bne cr6,0x88158b50
	if (!ctx.cr6.eq) goto loc_88158B50;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// lis r10,-30671
	ctx.r10.s64 = -2010054656;
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// sth r11,50(r31)
	PPC_STORE_U16(ctx.r31.u32 + 50, ctx.r11.u16);
	// addi r11,r10,4456
	ctx.r11.s64 = ctx.r10.s64 + 4456;
	// srawi r8,r9,3
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 3;
	// addi r7,r11,2
	ctx.r7.s64 = ctx.r11.s64 + 2;
	// rlwinm r4,r8,2,24,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFC;
	// lhzx r3,r4,r11
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r4.u32 + ctx.r11.u32);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// sth r3,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r3.u16);
	// lhzx r9,r4,r7
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r4.u32 + ctx.r7.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stb r9,10(r31)
	PPC_STORE_U8(ctx.r31.u32 + 10, ctx.r9.u8);
	// addi r7,r11,3385
	ctx.r7.s64 = ctx.r11.s64 + 3385;
	// sth r7,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r7.u16);
loc_88158B50:
	// lhz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 36);
	// addic. r11,r31,32
	ctx.xer.ca = ctx.r31.u32 > 4294967263;
	ctx.r11.s64 = ctx.r31.s64 + 32;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r8,68(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// addi r7,r31,28
	ctx.r7.s64 = ctx.r31.s64 + 28;
	// lhz r5,50(r31)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// add r4,r8,r9
	ctx.r4.u64 = ctx.r8.u64 + ctx.r9.u64;
	// clrlwi r10,r5,23
	ctx.r10.u64 = ctx.r5.u32 & 0x1FF;
	// extsh r3,r4
	ctx.r3.s64 = ctx.r4.s16;
	// sth r3,36(r31)
	PPC_STORE_U16(ctx.r31.u32 + 36, ctx.r3.u16);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// beq 0x88158b90
	if (ctx.cr0.eq) goto loc_88158B90;
	// addi r8,r10,128
	ctx.r8.s64 = ctx.r10.s64 + 128;
	// rlwinm r5,r8,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x7FC;
	// lwzx r4,r5,r6
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r6.u32);
	// mullw r3,r4,r3
	ctx.r3.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r3.s32);
	// stw r3,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
loc_88158B90:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x88158cc4
	if (ctx.cr6.eq) goto loc_88158CC4;
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r6
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r6.u32);
	// mullw r9,r10,r9
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// stw r9,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r9.u32);
	// b 0x88158cc4
	goto loc_88158CC4;
loc_88158BAC:
	// lwz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88158c2c
	if (ctx.cr6.eq) goto loc_88158C2C;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x88158c2c
	if (!ctx.cr6.eq) goto loc_88158C2C;
	// lhz r8,50(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r3,108(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// bl 0x88153010
	ctx.lr = 0x88158BD4;
	sub_88153010(ctx, base);
	// clrlwi r7,r3,16
	ctx.r7.u64 = ctx.r3.u32 & 0xFFFF;
	// sth r3,50(r31)
	PPC_STORE_U16(ctx.r31.u32 + 50, ctx.r3.u16);
	// cmpw cr6,r8,r7
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, ctx.xer);
	// bne cr6,0x88158bec
	if (!ctx.cr6.eq) goto loc_88158BEC;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r11.u32);
loc_88158BEC:
	// lhz r10,50(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r11,r11,4456
	ctx.r11.s64 = ctx.r11.s64 + 4456;
	// srawi r9,r10,3
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 3;
	// addi r8,r11,2
	ctx.r8.s64 = ctx.r11.s64 + 2;
	// rlwinm r6,r9,2,24,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFC;
	// lhzx r5,r6,r11
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r6.u32 + ctx.r11.u32);
	// clrlwi r11,r5,16
	ctx.r11.u64 = ctx.r5.u32 & 0xFFFF;
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// sth r5,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r5.u16);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lhzx r4,r6,r8
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r6.u32 + ctx.r8.u32);
	// stb r4,10(r31)
	PPC_STORE_U8(ctx.r31.u32 + 10, ctx.r4.u8);
	// addi r3,r11,3385
	ctx.r3.s64 = ctx.r11.s64 + 3385;
	// sth r3,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r3.u16);
loc_88158C2C:
	// lwz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x88158cc4
	if (ctx.cr6.eq) goto loc_88158CC4;
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
	// bgt 0x88158cc4
	if (ctx.cr0.gt) goto loc_88158CC4;
	// lhz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 36);
	// lwz r8,84(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// extsh r6,r7
	ctx.r6.s64 = ctx.r7.s16;
	// stw r8,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r8.u32);
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// sth r6,36(r31)
	PPC_STORE_U16(ctx.r31.u32 + 36, ctx.r6.u16);
	// cmpw cr6,r6,r11
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x88158c74
	if (!ctx.cr6.gt) goto loc_88158C74;
	// sth r11,36(r31)
	PPC_STORE_U16(ctx.r31.u32 + 36, ctx.r11.u16);
loc_88158C74:
	// lhz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 36);
	// lis r8,-30714
	ctx.r8.s64 = -2012872704;
	// lhz r9,50(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// addic. r11,r31,32
	ctx.xer.ca = ctx.r31.u32 > 4294967263;
	ctx.r11.s64 = ctx.r31.s64 + 32;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r7,r31,28
	ctx.r7.s64 = ctx.r31.s64 + 28;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// clrlwi r9,r9,23
	ctx.r9.u64 = ctx.r9.u32 & 0x1FF;
	// addi r8,r8,9552
	ctx.r8.s64 = ctx.r8.s64 + 9552;
	// beq 0x88158cac
	if (ctx.cr0.eq) goto loc_88158CAC;
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
loc_88158CAC:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x88158cc4
	if (ctx.cr6.eq) goto loc_88158CC4;
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r8
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r8.u32);
	// mullw r8,r9,r10
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// stw r8,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r8.u32);
loc_88158CC4:
	// lbz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 40);
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addi r7,r11,-1
	ctx.r7.s64 = ctx.r11.s64 + -1;
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// extsb r5,r7
	ctx.r5.s64 = ctx.r7.s8;
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r4,r11,r8
	ctx.r4.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stb r5,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r5.u8);
	// stw r6,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r6.u32);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// stw r4,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r4.u32);
	// bge cr6,0x88158d20
	if (!ctx.cr6.lt) goto loc_88158D20;
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lbz r10,41(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 41);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// stb r10,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r10.u8);
	// cmpwi cr6,r8,2
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 2, ctx.xer);
	// stb r8,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r8.u8);
	// ble cr6,0x88158d20
	if (!ctx.cr6.gt) goto loc_88158D20;
	// stb r29,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r29.u8);
loc_88158D20:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8815a360
	ctx.lr = 0x88158D28;
	sub_8815A360(ctx, base);
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// lhz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 36);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r11,42
	ctx.r9.s64 = ctx.r11.s64 + 42;
	// cmpw cr6,r7,r9
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x88158e14
	if (ctx.cr6.lt) goto loc_88158E14;
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x88158e14
	if (!ctx.cr6.gt) goto loc_88158E14;
	// lis r27,-30597
	ctx.r27.s64 = -2005204992;
	// lis r11,-30663
	ctx.r11.s64 = -2009530368;
	// lis r10,-30663
	ctx.r10.s64 = -2009530368;
	// lis r9,-30658
	ctx.r9.s64 = -2009202688;
	// lwz r30,-11932(r27)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
	// lwz r24,-30240(r11)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r11.u32 + -30240);
	// lwz r25,-22224(r10)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + -22224);
	// lwz r26,160(r9)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
loc_88158D80:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r28,r29,1
	ctx.r28.s64 = ctx.r29.s64 + 1;
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lbz r8,11(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// mullw r7,r28,r11
	ctx.r7.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r11.s32);
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lhz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// mullw r3,r28,r9
	ctx.r3.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r9.s32);
	// extsb r10,r8
	ctx.r10.s64 = ctx.r8.s8;
	// subf r4,r3,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r3.s64;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// subf r5,r7,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r7.s64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x88158DC0;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88158e00
	if (ctx.cr6.eq) goto loc_88158E00;
	// subf r11,r29,r24
	ctx.r11.s64 = ctx.r24.s64 - ctx.r29.s64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// mullw r11,r11,r25
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r25.s32);
	// add r8,r11,r26
	ctx.r8.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// rlwimi r9,r8,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r30,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r30.u32);
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// lbz r6,10(r31)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10);
	// rlwinm r5,r6,26,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 26) & 0xFFFFFFFC;
	// or r4,r5,r7
	ctx.r4.u64 = ctx.r5.u64 | ctx.r7.u64;
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
loc_88158E00:
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpw cr6,r28,r10
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x88158d80
	if (ctx.cr6.lt) goto loc_88158D80;
loc_88158E14:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88158E20"))) PPC_WEAK_FUNC(sub_88158E20);
PPC_FUNC_IMPL(__imp__sub_88158E20) {
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
	// bl 0x8815a220
	ctx.lr = 0x88158E38;
	sub_8815A220(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r11,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r11.u32);
	// stb r10,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r10.u8);
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r9,r11,3385
	ctx.r9.s64 = ctx.r11.s64 + 3385;
	// sth r9,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r9.u16);
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

__attribute__((alias("__imp__sub_88158E78"))) PPC_WEAK_FUNC(sub_88158E78);
PPC_FUNC_IMPL(__imp__sub_88158E78) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x88158E80;
	__savegprlr_24(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30638
	ctx.r11.s64 = -2007891968;
	// lwz r9,20(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r8,24(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r7,32(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// add r30,r9,r10
	ctx.r30.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r11,-1172(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -1172);
	// add r28,r7,r8
	ctx.r28.u64 = ctx.r7.u64 + ctx.r8.u64;
	// stw r30,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r30.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r28,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r28.u32);
	// beq cr6,0x88158f58
	if (ctx.cr6.eq) goto loc_88158F58;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lhz r26,50(r3)
	ctx.r26.u64 = PPC_LOAD_U16(ctx.r3.u32 + 50);
	// lwz r11,26276(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88158f58
	if (!ctx.cr6.eq) goto loc_88158F58;
	// lwz r11,128(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// addi r10,r26,128
	ctx.r10.s64 = ctx.r26.s64 + 128;
	// li r6,-46
	ctx.r6.s64 = -46;
	// sth r29,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r29.u16);
	// clrlwi r7,r10,16
	ctx.r7.u64 = ctx.r10.u32 & 0xFFFF;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,17
	ctx.r3.s64 = 17;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x8815c948
	ctx.lr = 0x88158EF8;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// bl 0x8815c860
	ctx.lr = 0x88158F04;
	sub_8815C860(ctx, base);
	// li r25,1
	ctx.r25.s64 = 1;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x88158f14
	if (ctx.cr6.eq) goto loc_88158F14;
	// sth r25,16(r27)
	PPC_STORE_U16(ctx.r27.u32 + 16, ctx.r25.u16);
loc_88158F14:
	// addis r10,r26,1
	ctx.r10.s64 = ctx.r26.s64 + 65536;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// li r6,-46
	ctx.r6.s64 = -46;
	// sth r29,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r29.u16);
	// addi r10,r10,-128
	ctx.r10.s64 = ctx.r10.s64 + -128;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// clrlwi r7,r10,16
	ctx.r7.u64 = ctx.r10.u32 & 0xFFFF;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// li r3,17
	ctx.r3.s64 = 17;
	// bl 0x8815c948
	ctx.lr = 0x88158F40;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x8815c860
	ctx.lr = 0x88158F4C;
	sub_8815C860(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x88158f58
	if (ctx.cr6.eq) goto loc_88158F58;
	// sth r25,16(r30)
	PPC_STORE_U16(ctx.r30.u32 + 16, ctx.r25.u16);
loc_88158F58:
	// lbz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 40);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r9.u8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge cr6,0x88158f94
	if (!ctx.cr6.lt) goto loc_88158F94;
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lbz r10,41(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 41);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// stb r10,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r10.u8);
	// cmpwi cr6,r8,3
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 3, ctx.xer);
	// stb r8,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r8.u8);
	// ble cr6,0x88158f94
	if (!ctx.cr6.gt) goto loc_88158F94;
	// stb r29,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r29.u8);
loc_88158F94:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8815a360
	ctx.lr = 0x88158F9C;
	sub_8815A360(ctx, base);
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// lhz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 36);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r11,42
	ctx.r9.s64 = ctx.r11.s64 + 42;
	// cmpw cr6,r7,r9
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x88159088
	if (ctx.cr6.lt) goto loc_88159088;
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x88159088
	if (!ctx.cr6.gt) goto loc_88159088;
	// lis r27,-30597
	ctx.r27.s64 = -2005204992;
	// lis r11,-30663
	ctx.r11.s64 = -2009530368;
	// lis r10,-30663
	ctx.r10.s64 = -2009530368;
	// lis r9,-30658
	ctx.r9.s64 = -2009202688;
	// lwz r30,-11932(r27)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
	// lwz r24,-30240(r11)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r11.u32 + -30240);
	// lwz r25,-22224(r10)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + -22224);
	// lwz r26,160(r9)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
loc_88158FF4:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r28,r29,1
	ctx.r28.s64 = ctx.r29.s64 + 1;
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lbz r8,11(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// mullw r7,r11,r28
	ctx.r7.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lhz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// mullw r3,r28,r9
	ctx.r3.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r9.s32);
	// extsb r10,r8
	ctx.r10.s64 = ctx.r8.s8;
	// subf r4,r3,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r3.s64;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// subf r5,r7,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r7.s64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x88159034;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88159074
	if (ctx.cr6.eq) goto loc_88159074;
	// subf r11,r29,r24
	ctx.r11.s64 = ctx.r24.s64 - ctx.r29.s64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// mullw r11,r11,r25
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r25.s32);
	// add r8,r11,r26
	ctx.r8.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// rlwimi r9,r8,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r30,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r30.u32);
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// lbz r6,10(r31)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10);
	// rlwinm r5,r6,26,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 26) & 0xFFFFFFFC;
	// or r4,r5,r7
	ctx.r4.u64 = ctx.r5.u64 | ctx.r7.u64;
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
loc_88159074:
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpw cr6,r28,r10
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x88158ff4
	if (ctx.cr6.lt) goto loc_88158FF4;
loc_88159088:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88159094"))) PPC_WEAK_FUNC(sub_88159094);
PPC_FUNC_IMPL(__imp__sub_88159094) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88159098"))) PPC_WEAK_FUNC(sub_88159098);
PPC_FUNC_IMPL(__imp__sub_88159098) {
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
	// bl 0x8815a220
	ctx.lr = 0x881590B0;
	sub_8815A220(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// lhz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r11,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r11.u8);
	// rotlwi r11,r9,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r10,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r10.u8);
	// addi r8,r11,3555
	ctx.r8.s64 = ctx.r11.s64 + 3555;
	// sth r8,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r8.u16);
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

__attribute__((alias("__imp__sub_881590E8"))) PPC_WEAK_FUNC(sub_881590E8);
PPC_FUNC_IMPL(__imp__sub_881590E8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x881590F0;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r9,24(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r8,32(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r7,76(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stw r5,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r5.u32);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stw r6,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r6.u32);
	// beq cr6,0x88159190
	if (ctx.cr6.eq) goto loc_88159190;
	// lwz r11,68(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, ctx.r11.u32);
	// bge 0x88159190
	if (!ctx.cr0.lt) goto loc_88159190;
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// li r4,-1
	ctx.r4.s64 = -1;
	// li r10,24
	ctx.r10.s64 = 24;
	// lhz r8,50(r3)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r3.u32 + 50);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// li r9,3
	ctx.r9.s64 = 3;
	// li r4,18
	ctx.r4.s64 = 18;
	// lwz r7,88(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// lwz r3,128(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// stw r11,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// bl 0x88094690
	ctx.lr = 0x88159160;
	sub_88094690(ctx, base);
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// stw r3,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r3.u32);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// bgt 0x88159190
	if (ctx.cr0.gt) goto loc_88159190;
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stw r10,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r10.u32);
	// stw r9,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r9.u32);
loc_88159190:
	// lbz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 40);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r9.u8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge cr6,0x881591c4
	if (!ctx.cr6.lt) goto loc_881591C4;
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lbz r10,41(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 41);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// clrlwi r8,r9,30
	ctx.r8.u64 = ctx.r9.u32 & 0x3;
	// stb r10,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r10.u8);
	// stb r8,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r8.u8);
loc_881591C4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8815a360
	ctx.lr = 0x881591CC;
	sub_8815A360(ctx, base);
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// lhz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 36);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r11,42
	ctx.r9.s64 = ctx.r11.s64 + 42;
	// cmpw cr6,r7,r9
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x881592bc
	if (ctx.cr6.lt) goto loc_881592BC;
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// li r29,0
	ctx.r29.s64 = 0;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x881592bc
	if (!ctx.cr6.gt) goto loc_881592BC;
	// lis r27,-30597
	ctx.r27.s64 = -2005204992;
	// lis r11,-30663
	ctx.r11.s64 = -2009530368;
	// lis r10,-30663
	ctx.r10.s64 = -2009530368;
	// lis r9,-30658
	ctx.r9.s64 = -2009202688;
	// lwz r30,-11932(r27)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
	// lwz r24,-30240(r11)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r11.u32 + -30240);
	// lwz r25,-22224(r10)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + -22224);
	// lwz r26,160(r9)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
loc_88159228:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r28,r29,1
	ctx.r28.s64 = ctx.r29.s64 + 1;
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lbz r8,11(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// mullw r7,r11,r28
	ctx.r7.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lhz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// mullw r3,r28,r9
	ctx.r3.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r9.s32);
	// extsb r10,r8
	ctx.r10.s64 = ctx.r8.s8;
	// subf r4,r3,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r3.s64;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// subf r5,r7,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r7.s64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x88159268;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x881592a8
	if (ctx.cr6.eq) goto loc_881592A8;
	// subf r11,r29,r24
	ctx.r11.s64 = ctx.r24.s64 - ctx.r29.s64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// mullw r11,r11,r25
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r25.s32);
	// add r8,r11,r26
	ctx.r8.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// rlwimi r9,r8,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r30,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r30.u32);
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// lbz r6,10(r31)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10);
	// rlwinm r5,r6,26,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 26) & 0xFFFFFFFC;
	// or r4,r5,r7
	ctx.r4.u64 = ctx.r5.u64 | ctx.r7.u64;
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
loc_881592A8:
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpw cr6,r28,r10
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x88159228
	if (ctx.cr6.lt) goto loc_88159228;
loc_881592BC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_881592C8"))) PPC_WEAK_FUNC(sub_881592C8);
PPC_FUNC_IMPL(__imp__sub_881592C8) {
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
	// bl 0x8815a220
	ctx.lr = 0x881592E0;
	sub_8815A220(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lhz r7,12(r31)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r11.u8);
	// li r9,8
	ctx.r9.s64 = 8;
	// stb r11,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r11.u8);
	// li r8,-44
	ctx.r8.s64 = -44;
	// stw r11,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// rotlwi r11,r7,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// stw r10,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r10.u32);
	// addi r6,r11,2363
	ctx.r6.s64 = ctx.r11.s64 + 2363;
	// stw r9,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r9.u32);
	// stw r10,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r10.u32);
	// stw r10,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r10.u32);
	// stw r8,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r8.u32);
	// sth r6,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r6.u16);
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

__attribute__((alias("__imp__sub_8815933C"))) PPC_WEAK_FUNC(sub_8815933C);
PPC_FUNC_IMPL(__imp__sub_8815933C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88159340"))) PPC_WEAK_FUNC(sub_88159340);
PPC_FUNC_IMPL(__imp__sub_88159340) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88159348;
	__savegprlr_29(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r8,24(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r7,r11,2048
	ctx.r7.s64 = ctx.r11.s64 + 2048;
	// lwz r9,28(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r6,76(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// add r5,r11,r8
	ctx.r5.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r4,r9,r10
	ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r7,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r7.u32);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// stw r5,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r5.u32);
	// stw r4,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r4.u32);
	// beq cr6,0x88159404
	if (ctx.cr6.eq) goto loc_88159404;
	// lwz r11,68(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, ctx.r11.u32);
	// bge 0x88159404
	if (!ctx.cr0.lt) goto loc_88159404;
	// lhz r11,50(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 50);
	// lis r8,-30643
	ctx.r8.s64 = -2008219648;
	// lwz r10,52(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// rotlwi r5,r5,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// lwz r7,72(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r9,88(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// lwz r10,26276(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 26276);
	// clrlwi r11,r6,16
	ctx.r11.u64 = ctx.r6.u32 & 0xFFFF;
	// stw r7,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, ctx.r7.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// sth r11,50(r3)
	PPC_STORE_U16(ctx.r3.u32 + 50, ctx.r11.u16);
	// bne cr6,0x88159404
	if (!ctx.cr6.eq) goto loc_88159404;
	// lwz r10,128(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// clrlwi r7,r11,16
	ctx.r7.u64 = ctx.r11.u32 & 0xFFFF;
	// extsh r6,r9
	ctx.r6.s64 = ctx.r9.s16;
	// sth r29,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r29.u16);
	// li r3,33
	ctx.r3.s64 = 33;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x8815c948
	ctx.lr = 0x881593E8;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x8815c860
	ctx.lr = 0x881593F4;
	sub_8815C860(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x88159404
	if (ctx.cr6.eq) goto loc_88159404;
	// li r11,1
	ctx.r11.s64 = 1;
	// sth r11,16(r30)
	PPC_STORE_U16(ctx.r30.u32 + 16, ctx.r11.u16);
loc_88159404:
	// lbz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 40);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r9.u8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge cr6,0x88159440
	if (!ctx.cr6.lt) goto loc_88159440;
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lbz r10,41(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 41);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// stb r10,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r10.u8);
	// cmpwi cr6,r8,5
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 5, ctx.xer);
	// stb r8,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r8.u8);
	// ble cr6,0x88159440
	if (!ctx.cr6.gt) goto loc_88159440;
	// stb r29,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r29.u8);
loc_88159440:
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lis r10,-30671
	ctx.r10.s64 = -2010054656;
	// lhz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// extsb r8,r11
	ctx.r8.s64 = ctx.r11.s8;
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// addi r7,r10,4744
	ctx.r7.s64 = ctx.r10.s64 + 4744;
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// rlwinm r3,r8,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// extsh r6,r9
	ctx.r6.s64 = ctx.r9.s16;
	// lhzx r10,r3,r7
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + ctx.r7.u32);
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x88159474;
	sub_881538C0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// beq cr6,0x88159498
	if (ctx.cr6.eq) goto loc_88159498;
	// lbz r10,10(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm r8,r10,26,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 26) & 0xFFFFFFFC;
	// or r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 | ctx.r9.u64;
	// stw r7,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
loc_88159498:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_881594A0"))) PPC_WEAK_FUNC(sub_881594A0);
PPC_FUNC_IMPL(__imp__sub_881594A0) {
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
	// bl 0x8815a220
	ctx.lr = 0x881594B8;
	sub_8815A220(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r9,3229
	ctx.r9.s64 = 3229;
	// stb r10,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r10.u8);
	// li r8,28
	ctx.r8.s64 = 28;
	// stb r10,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r10.u8);
	// li r7,4
	ctx.r7.s64 = 4;
	// sth r9,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r9.u16);
	// li r6,7
	ctx.r6.s64 = 7;
	// stw r8,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r8.u32);
	// li r5,-30
	ctx.r5.s64 = -30;
	// stw r7,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r7.u32);
	// stw r6,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r6.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// stw r5,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r5.u32);
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

__attribute__((alias("__imp__sub_88159510"))) PPC_WEAK_FUNC(sub_88159510);
PPC_FUNC_IMPL(__imp__sub_88159510) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88159518;
	__savegprlr_28(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r9,20(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r8,28(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r7,76(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// add r30,r8,r9
	ctx.r30.u64 = ctx.r8.u64 + ctx.r9.u64;
	// add r29,r11,r10
	ctx.r29.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stw r30,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r30.u32);
	// stw r29,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r29.u32);
	// beq cr6,0x881595f4
	if (ctx.cr6.eq) goto loc_881595F4;
	// lwz r11,68(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, ctx.r11.u32);
	// bge 0x881595f4
	if (!ctx.cr0.lt) goto loc_881595F4;
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// li r28,1
	ctx.r28.s64 = 1;
	// lwz r10,80(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, ctx.r11.u32);
	// bne cr6,0x88159588
	if (!ctx.cr6.eq) goto loc_88159588;
	// stw r28,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, ctx.r28.u32);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x88157f68
	ctx.lr = 0x88159584;
	sub_88157F68(ctx, base);
	// stw r3,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r3.u32);
loc_88159588:
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lhz r11,50(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// blt cr6,0x881595a0
	if (ctx.cr6.lt) goto loc_881595A0;
	// addi r11,r11,-38
	ctx.r11.s64 = ctx.r11.s64 + -38;
	// b 0x881595a4
	goto loc_881595A4;
loc_881595A0:
	// addi r11,r11,38
	ctx.r11.s64 = ctx.r11.s64 + 38;
loc_881595A4:
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// lwz r10,26276(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26276);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x881595f4
	if (!ctx.cr6.eq) goto loc_881595F4;
	// lwz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// li r9,0
	ctx.r9.s64 = 0;
	// clrlwi r7,r11,16
	ctx.r7.u64 = ctx.r11.u32 & 0xFFFF;
	// li r6,-4
	ctx.r6.s64 = -4;
	// sth r9,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r9.u16);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,33
	ctx.r3.s64 = 33;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x8815c948
	ctx.lr = 0x881595DC;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x8815c860
	ctx.lr = 0x881595E8;
	sub_8815C860(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x881595f4
	if (ctx.cr6.eq) goto loc_881595F4;
	// sth r28,16(r30)
	PPC_STORE_U16(ctx.r30.u32 + 16, ctx.r28.u16);
loc_881595F4:
	// lbz r10,11(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// li r6,213
	ctx.r6.s64 = 213;
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x88159614;
	sub_881538C0(ctx, base);
	// lis r3,0
	ctx.r3.s64 = 0;
	// li r6,215
	ctx.r6.s64 = 215;
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// ori r3,r3,45190
	ctx.r3.u64 = ctx.r3.u64 | 45190;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// bl 0x881538c0
	ctx.lr = 0x8815962C;
	sub_881538C0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// beq cr6,0x8815965c
	if (ctx.cr6.eq) goto loc_8815965C;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// oris r7,r8,545
	ctx.r7.u64 = ctx.r8.u64 | 35717120;
	// ori r7,r7,65280
	ctx.r7.u64 = ctx.r7.u64 | 65280;
	// lwz r10,-11932(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -11932);
	// stw r7,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// addi r11,r10,1
	ctx.r11.s64 = ctx.r10.s64 + 1;
	// stw r11,-11932(r9)
	PPC_STORE_U32(ctx.r9.u32 + -11932, ctx.r11.u32);
loc_8815965C:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88159664"))) PPC_WEAK_FUNC(sub_88159664);
PPC_FUNC_IMPL(__imp__sub_88159664) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88159668"))) PPC_WEAK_FUNC(sub_88159668);
PPC_FUNC_IMPL(__imp__sub_88159668) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071144
	ctx.lr = 0x88159670;
	__savegprlr_23(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r8,20(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// li r28,0
	ctx.r28.s64 = 0;
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r7,r11,4096
	ctx.r7.s64 = ctx.r11.s64 + 4096;
	// lwz r9,28(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r6,92(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r4,r8,r9
	ctx.r4.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stw r7,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r7.u32);
	// stw r5,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r5.u32);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// stw r4,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r4.u32);
	// beq cr6,0x88159744
	if (ctx.cr6.eq) goto loc_88159744;
	// lwz r11,84(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, ctx.r11.u32);
	// bge 0x88159744
	if (!ctx.cr0.lt) goto loc_88159744;
	// lis r9,-30643
	ctx.r9.s64 = -2008219648;
	// lwz r8,88(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// lwz r11,76(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// rotlwi r5,r5,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// lwz r10,80(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// lwz r9,26276(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 26276);
	// stw r8,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, ctx.r8.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x88159708
	if (!ctx.cr6.eq) goto loc_88159708;
	// lwz r9,128(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// clrlwi r7,r10,16
	ctx.r7.u64 = ctx.r10.u32 & 0xFFFF;
	// extsh r6,r11
	ctx.r6.s64 = ctx.r11.s16;
	// sth r28,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r28.u16);
	// li r3,61
	ctx.r3.s64 = 61;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x8815c948
	ctx.lr = 0x88159700;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x88159708;
	sub_8815C860(ctx, base);
loc_88159708:
	// lwz r9,52(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,92(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addic. r11,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r11.s64 = ctx.r8.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r7,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r7.u32);
	// stw r6,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r6.u32);
	// stw r11,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// bgt 0x88159744
	if (ctx.cr0.gt) goto loc_88159744;
	// li r11,8
	ctx.r11.s64 = 8;
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// stw r11,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r11.u32);
loc_88159744:
	// lbz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 40);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r9.u8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge cr6,0x88159780
	if (!ctx.cr6.lt) goto loc_88159780;
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lbz r10,41(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 41);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// stb r10,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r10.u8);
	// cmpwi cr6,r8,5
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 5, ctx.xer);
	// stb r8,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r8.u8);
	// ble cr6,0x88159780
	if (!ctx.cr6.gt) goto loc_88159780;
	// stb r28,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r28.u8);
loc_88159780:
	// lbz r10,11(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// lhz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// extsb r8,r10
	ctx.r8.s64 = ctx.r10.s8;
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r23,r11,4744
	ctx.r23.s64 = ctx.r11.s64 + 4744;
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// extsh r6,r9
	ctx.r6.s64 = ctx.r9.s16;
	// lhzx r10,r7,r23
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + ctx.r23.u32);
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x881597B4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x881597d0
	if (ctx.cr6.eq) goto loc_881597D0;
	// lbz r11,10(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r11,26,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 26) & 0xFFFFFFFC;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_881597D0:
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// lhz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 36);
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r8,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r7,r11,42
	ctx.r7.s64 = ctx.r11.s64 + 42;
	// cmpw cr6,r9,r7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, ctx.xer);
	// blt cr6,0x881598b4
	if (ctx.cr6.lt) goto loc_881598B4;
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x881598b4
	if (!ctx.cr6.gt) goto loc_881598B4;
	// lis r27,-30597
	ctx.r27.s64 = -2005204992;
	// lis r11,-30663
	ctx.r11.s64 = -2009530368;
	// lis r10,-30663
	ctx.r10.s64 = -2009530368;
	// lis r9,-30658
	ctx.r9.s64 = -2009202688;
	// lwz r30,-11932(r27)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
	// lwz r24,-30240(r11)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r11.u32 + -30240);
	// lwz r25,-22224(r10)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + -22224);
	// lwz r26,160(r9)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
loc_88159828:
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// addi r29,r28,1
	ctx.r29.s64 = ctx.r28.s64 + 1;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// extsb r9,r11
	ctx.r9.s64 = ctx.r11.s8;
	// lwz r8,28(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// mullw r5,r10,r29
	ctx.r5.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r29.s32);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lhz r7,16(r31)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// lhz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// rlwinm r11,r9,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// mullw r9,r29,r8
	ctx.r9.s64 = int64_t(ctx.r29.s32) * int64_t(ctx.r8.s32);
	// lhzx r11,r11,r23
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r23.u32);
	// subf r5,r5,r4
	ctx.r5.s64 = ctx.r4.s64 - ctx.r5.s64;
	// subf r4,r9,r3
	ctx.r4.s64 = ctx.r3.s64 - ctx.r9.s64;
	// extsh r6,r7
	ctx.r6.s64 = ctx.r7.s16;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x88159870;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x881598a0
	if (ctx.cr6.eq) goto loc_881598A0;
	// subf r11,r28,r24
	ctx.r11.s64 = ctx.r24.s64 - ctx.r28.s64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// mullw r11,r11,r25
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r25.s32);
	// add r8,r11,r26
	ctx.r8.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// rlwimi r9,r8,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r30,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r30.u32);
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
loc_881598A0:
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// mr r28,r29
	ctx.r28.u64 = ctx.r29.u64;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpw cr6,r29,r10
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x88159828
	if (ctx.cr6.lt) goto loc_88159828;
loc_881598B4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_881598C0"))) PPC_WEAK_FUNC(sub_881598C0);
PPC_FUNC_IMPL(__imp__sub_881598C0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x881598C8;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,40(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 40);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r9,20(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// addi r7,r11,-1
	ctx.r7.s64 = ctx.r11.s64 + -1;
	// lwz r8,24(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// extsb r6,r7
	ctx.r6.s64 = ctx.r7.s8;
	// add r4,r9,r10
	ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r5,r11,r8
	ctx.r5.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stb r6,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, ctx.r6.u8);
	// stw r4,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r4.u32);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// stw r5,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r5.u32);
	// bge cr6,0x88159924
	if (!ctx.cr6.lt) goto loc_88159924;
	// lbz r11,11(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 11);
	// lbz r10,41(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 41);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// clrlwi r8,r9,30
	ctx.r8.u64 = ctx.r9.u32 & 0x3;
	// stb r10,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, ctx.r10.u8);
	// stb r8,11(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11, ctx.r8.u8);
loc_88159924:
	// lbz r10,11(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lhz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// extsh r6,r9
	ctx.r6.s64 = ctx.r9.s16;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x88159940;
	sub_881538C0(ctx, base);
	// lis r8,-30658
	ctx.r8.s64 = -2009202688;
	// lhz r5,36(r31)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r31.u32 + 36);
	// extsh r4,r5
	ctx.r4.s64 = ctx.r5.s16;
	// lwz r11,152(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 152);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r7,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r6,r11,42
	ctx.r6.s64 = ctx.r11.s64 + 42;
	// cmpw cr6,r4,r6
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r6.s32, ctx.xer);
	// blt cr6,0x88159a20
	if (ctx.cr6.lt) goto loc_88159A20;
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// li r29,0
	ctx.r29.s64 = 0;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x88159a20
	if (!ctx.cr6.gt) goto loc_88159A20;
	// lis r27,-30597
	ctx.r27.s64 = -2005204992;
	// lis r11,-30663
	ctx.r11.s64 = -2009530368;
	// lis r10,-30663
	ctx.r10.s64 = -2009530368;
	// lis r9,-30658
	ctx.r9.s64 = -2009202688;
	// lwz r30,-11932(r27)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
	// lwz r24,-30240(r11)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r11.u32 + -30240);
	// lwz r25,-22224(r10)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + -22224);
	// lwz r26,160(r9)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
loc_8815999C:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r28,r29,1
	ctx.r28.s64 = ctx.r29.s64 + 1;
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lbz r8,11(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// mullw r7,r11,r28
	ctx.r7.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lhz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// mullw r3,r28,r9
	ctx.r3.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r9.s32);
	// extsb r10,r8
	ctx.r10.s64 = ctx.r8.s8;
	// subf r4,r3,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r3.s64;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// subf r5,r7,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r7.s64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x881599DC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88159a0c
	if (ctx.cr6.eq) goto loc_88159A0C;
	// subf r11,r29,r24
	ctx.r11.s64 = ctx.r24.s64 - ctx.r29.s64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// mullw r11,r11,r25
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r25.s32);
	// add r8,r11,r26
	ctx.r8.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// rlwimi r9,r8,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r30,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r30.u32);
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
loc_88159A0C:
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpw cr6,r28,r10
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x8815999c
	if (ctx.cr6.lt) goto loc_8815999C;
loc_88159A20:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88159A2C"))) PPC_WEAK_FUNC(sub_88159A2C);
PPC_FUNC_IMPL(__imp__sub_88159A2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88159A30"))) PPC_WEAK_FUNC(sub_88159A30);
PPC_FUNC_IMPL(__imp__sub_88159A30) {
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
	// bl 0x8815a220
	ctx.lr = 0x88159A48;
	sub_8815A220(ctx, base);
	// li r11,3147
	ctx.r11.s64 = 3147;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// sth r11,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r11.u16);
	// li r8,6
	ctx.r8.s64 = 6;
	// stb r10,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r10.u8);
	// li r7,3
	ctx.r7.s64 = 3;
	// stw r9,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r9.u32);
	// stw r8,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r8.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r7,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r7.u32);
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

__attribute__((alias("__imp__sub_88159A88"))) PPC_WEAK_FUNC(sub_88159A88);
PPC_FUNC_IMPL(__imp__sub_88159A88) {
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
	// lwz r8,24(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lbz r9,40(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 40);
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// lwz r9,28(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// stw r8,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r8.u32);
	// addi r7,r11,-1
	ctx.r7.s64 = ctx.r11.s64 + -1;
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// extsb r5,r7
	ctx.r5.s64 = ctx.r7.s8;
	// stw r6,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r6.u32);
	// stb r5,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, ctx.r5.u8);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bge cr6,0x88159b08
	if (!ctx.cr6.lt) goto loc_88159B08;
	// lbz r11,11(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 11);
	// lis r10,21845
	ctx.r10.s64 = 1431633920;
	// lbz r9,41(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 41);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// ori r8,r10,21846
	ctx.r8.u64 = ctx.r10.u64 | 21846;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// mulhw r10,r11,r8
	ctx.r10.s64 = (int64_t(ctx.r11.s32) * int64_t(ctx.r8.s32)) >> 32;
	// stb r9,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, ctx.r9.u8);
	// rlwinm r9,r10,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// subf r6,r7,r11
	ctx.r6.s64 = ctx.r11.s64 - ctx.r7.s64;
	// stb r6,11(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11, ctx.r6.u8);
loc_88159B08:
	// bl 0x8815a360
	ctx.lr = 0x88159B0C;
	sub_8815A360(ctx, base);
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

__attribute__((alias("__imp__sub_88159B20"))) PPC_WEAK_FUNC(sub_88159B20);
PPC_FUNC_IMPL(__imp__sub_88159B20) {
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
	// bl 0x8815a220
	ctx.lr = 0x88159B38;
	sub_8815A220(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lhz r7,12(r31)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r11.u8);
	// rlwinm r11,r7,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// li r9,6
	ctx.r9.s64 = 6;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// li r8,3
	ctx.r8.s64 = 3;
	// stw r9,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r9.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r8,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r8.u32);
	// addi r6,r11,3112
	ctx.r6.s64 = ctx.r11.s64 + 3112;
	// sth r6,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r6.u16);
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

__attribute__((alias("__imp__sub_88159B88"))) PPC_WEAK_FUNC(sub_88159B88);
PPC_FUNC_IMPL(__imp__sub_88159B88) {
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
	// lwz r11,80(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88159bc0
	if (ctx.cr6.eq) goto loc_88159BC0;
	// lwz r11,52(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r11.u32);
	// bge 0x88159bc0
	if (!ctx.cr0.lt) goto loc_88159BC0;
	// lwz r11,76(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r11.u32);
loc_88159BC0:
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lbz r8,40(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 40);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// lwz r8,32(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// stw r4,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r4.u32);
	// addi r7,r11,-1
	ctx.r7.s64 = ctx.r11.s64 + -1;
	// add r5,r8,r9
	ctx.r5.u64 = ctx.r8.u64 + ctx.r9.u64;
	// extsb r6,r7
	ctx.r6.s64 = ctx.r7.s8;
	// stw r5,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r5.u32);
	// stb r6,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r6.u8);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bge cr6,0x88159c24
	if (!ctx.cr6.lt) goto loc_88159C24;
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lbz r10,41(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 41);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// stb r10,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r10.u8);
	// cmpwi cr6,r8,5
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 5, ctx.xer);
	// stb r8,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r8.u8);
	// ble cr6,0x88159c24
	if (!ctx.cr6.gt) goto loc_88159C24;
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r11.u8);
loc_88159C24:
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lis r10,-30671
	ctx.r10.s64 = -2010054656;
	// lhz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// extsb r8,r11
	ctx.r8.s64 = ctx.r11.s8;
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// addi r7,r10,4744
	ctx.r7.s64 = ctx.r10.s64 + 4744;
	// rlwinm r3,r8,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// extsh r6,r9
	ctx.r6.s64 = ctx.r9.s16;
	// lhzx r10,r3,r7
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + ctx.r7.u32);
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x88159C50;
	sub_881538C0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// beq cr6,0x88159c74
	if (ctx.cr6.eq) goto loc_88159C74;
	// lbz r10,10(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm r8,r10,26,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 26) & 0xFFFFFFFC;
	// or r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 | ctx.r9.u64;
	// stw r7,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
loc_88159C74:
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

__attribute__((alias("__imp__sub_88159C88"))) PPC_WEAK_FUNC(sub_88159C88);
PPC_FUNC_IMPL(__imp__sub_88159C88) {
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
	// bl 0x8815a220
	ctx.lr = 0x88159CA0;
	sub_8815A220(ctx, base);
	// li r11,3169
	ctx.r11.s64 = 3169;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// sth r11,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r11.u16);
	// li r8,6
	ctx.r8.s64 = 6;
	// stb r10,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r10.u8);
	// li r7,3
	ctx.r7.s64 = 3;
	// stw r9,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r9.u32);
	// stw r8,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r8.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r7,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r7.u32);
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

__attribute__((alias("__imp__sub_88159CE0"))) PPC_WEAK_FUNC(sub_88159CE0);
PPC_FUNC_IMPL(__imp__sub_88159CE0) {
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
	// lwz r11,20(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// lis r6,-4
	ctx.r6.s64 = -262144;
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r8,32(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r11,56(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// lwz r9,24(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r7,52(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// add r10,r8,r11
	ctx.r10.u64 = ctx.r8.u64 + ctx.r11.u64;
	// stw r4,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r4.u32);
	// add r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 + ctx.r11.u64;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r11,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r11.u32);
	// cmpw cr6,r11,r6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r6.s32, ctx.xer);
	// stw r10,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r10.u32);
	// bgt cr6,0x88159d38
	if (ctx.cr6.gt) goto loc_88159D38;
	// stw r6,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r6.u32);
loc_88159D38:
	// lbz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 40);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r9.u8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge cr6,0x88159d78
	if (!ctx.cr6.lt) goto loc_88159D78;
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lbz r10,41(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 41);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// stb r10,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r10.u8);
	// cmpwi cr6,r8,5
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 5, ctx.xer);
	// stb r8,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r8.u8);
	// ble cr6,0x88159d78
	if (!ctx.cr6.gt) goto loc_88159D78;
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r11.u8);
loc_88159D78:
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lis r10,-30671
	ctx.r10.s64 = -2010054656;
	// lhz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// extsb r8,r11
	ctx.r8.s64 = ctx.r11.s8;
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// addi r7,r10,4744
	ctx.r7.s64 = ctx.r10.s64 + 4744;
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// rlwinm r3,r8,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// extsh r6,r9
	ctx.r6.s64 = ctx.r9.s16;
	// lhzx r10,r3,r7
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + ctx.r7.u32);
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x88159DA8;
	sub_881538C0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// beq cr6,0x88159dcc
	if (ctx.cr6.eq) goto loc_88159DCC;
	// lbz r10,10(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm r8,r10,26,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 26) & 0xFFFFFFFC;
	// or r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 | ctx.r9.u64;
	// stw r7,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
loc_88159DCC:
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

__attribute__((alias("__imp__sub_88159DE0"))) PPC_WEAK_FUNC(sub_88159DE0);
PPC_FUNC_IMPL(__imp__sub_88159DE0) {
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
	// bl 0x8815a220
	ctx.lr = 0x88159DF8;
	sub_8815A220(ctx, base);
	// li r11,3169
	ctx.r11.s64 = 3169;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// sth r11,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r11.u16);
	// stb r10,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r10.u8);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_88159E28"))) PPC_WEAK_FUNC(sub_88159E28);
PPC_FUNC_IMPL(__imp__sub_88159E28) {
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
	// lwz r11,84(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88159efc
	if (ctx.cr6.eq) goto loc_88159EFC;
	// lwz r11,68(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, ctx.r11.u32);
	// bge 0x88159f1c
	if (!ctx.cr0.lt) goto loc_88159F1C;
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// lwz r10,52(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// lwz r4,20(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r5,24(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, ctx.r11.u32);
	// ble cr6,0x88159e88
	if (!ctx.cr6.gt) goto loc_88159E88;
	// lwz r11,56(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// lwz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// b 0x88159e94
	goto loc_88159E94;
loc_88159E88:
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_88159E94:
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r10,60(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// lwz r11,26276(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88159eec
	if (!ctx.cr6.eq) goto loc_88159EEC;
	// lwz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// li r6,16
	ctx.r6.s64 = 16;
	// li r3,2
	ctx.r3.s64 = 2;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r6,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r6.u32);
	// stw r3,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r3.u32);
	// li r30,-1
	ctx.r30.s64 = -1;
	// clrlwi r7,r9,16
	ctx.r7.u64 = ctx.r9.u32 & 0xFFFF;
	// sth r11,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r11.u16);
	// extsh r6,r10
	ctx.r6.s64 = ctx.r10.s16;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// bl 0x8815c948
	ctx.lr = 0x88159EE4;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x88159EEC;
	sub_8815C860(ctx, base);
loc_88159EEC:
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// addi r11,r11,-12
	ctx.r11.s64 = ctx.r11.s64 + -12;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// b 0x88159f1c
	goto loc_88159F1C;
loc_88159EFC:
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// bge 0x88159f1c
	if (!ctx.cr0.lt) goto loc_88159F1C;
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r10,88(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// stw r11,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// stw r10,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r10.u32);
loc_88159F1C:
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lbz r8,40(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 40);
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// lwz r8,28(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// stw r5,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r5.u32);
	// addi r7,r11,-1
	ctx.r7.s64 = ctx.r11.s64 + -1;
	// add r4,r8,r9
	ctx.r4.u64 = ctx.r8.u64 + ctx.r9.u64;
	// extsb r6,r7
	ctx.r6.s64 = ctx.r7.s8;
	// stw r4,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r4.u32);
	// stb r6,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r6.u8);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bge cr6,0x88159f80
	if (!ctx.cr6.lt) goto loc_88159F80;
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lbz r10,41(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 41);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// stb r10,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r10.u8);
	// cmpwi cr6,r8,5
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 5, ctx.xer);
	// stb r8,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r8.u8);
	// ble cr6,0x88159f80
	if (!ctx.cr6.gt) goto loc_88159F80;
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r11.u8);
loc_88159F80:
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lis r10,-30671
	ctx.r10.s64 = -2010054656;
	// lhz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// extsb r8,r11
	ctx.r8.s64 = ctx.r11.s8;
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// addi r7,r10,4744
	ctx.r7.s64 = ctx.r10.s64 + 4744;
	// rlwinm r3,r8,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// extsh r6,r9
	ctx.r6.s64 = ctx.r9.s16;
	// lhzx r10,r3,r7
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + ctx.r7.u32);
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x88159FAC;
	sub_881538C0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// beq cr6,0x88159fd0
	if (ctx.cr6.eq) goto loc_88159FD0;
	// lbz r10,10(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm r8,r10,26,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 26) & 0xFFFFFFFC;
	// or r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 | ctx.r9.u64;
	// stw r7,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
loc_88159FD0:
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

__attribute__((alias("__imp__sub_88159FE8"))) PPC_WEAK_FUNC(sub_88159FE8);
PPC_FUNC_IMPL(__imp__sub_88159FE8) {
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
	// bl 0x8815a220
	ctx.lr = 0x8815A000;
	sub_8815A220(ctx, base);
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// li r9,16
	ctx.r9.s64 = 16;
	// li r10,4
	ctx.r10.s64 = 4;
	// li r8,3169
	ctx.r8.s64 = 3169;
	// stw r9,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r9.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r9,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r9.u32);
	// lwz r11,156(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 156);
	// li r6,256
	ctx.r6.s64 = 256;
	// li r5,0
	ctx.r5.s64 = 0;
	// sth r8,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r8.u16);
	// li r4,2
	ctx.r4.s64 = 2;
	// stb r7,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r7.u8);
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
	// stw r6,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r6.u32);
	// stw r5,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r5.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r4,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r4.u32);
	// stw r11,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// stw r10,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r10.u32);
	// stw r10,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_8815A068"))) PPC_WEAK_FUNC(sub_8815A068);
PPC_FUNC_IMPL(__imp__sub_8815A068) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// rlwinm r10,r3,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r11,r11,4816
	ctx.r11.s64 = ctx.r11.s64 + 4816;
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// lwzx r3,r10,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8815A080"))) PPC_WEAK_FUNC(sub_8815A080);
PPC_FUNC_IMPL(__imp__sub_8815A080) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// rlwinm r10,r3,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r11,4816
	ctx.r9.s64 = ctx.r11.s64 + 4816;
	// lwzx r3,r10,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8815A094"))) PPC_WEAK_FUNC(sub_8815A094);
PPC_FUNC_IMPL(__imp__sub_8815A094) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8815A098"))) PPC_WEAK_FUNC(sub_8815A098);
PPC_FUNC_IMPL(__imp__sub_8815A098) {
	PPC_FUNC_PROLOGUE();
	// lhz r11,124(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 124);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,56(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r11.u32);
	// bgtlr 
	if (ctx.cr0.gt) return;
	// lhz r9,36(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 36);
	// lwz r10,52(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// lwz r8,60(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r11,64(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// extsh r10,r7
	ctx.r10.s64 = ctx.r7.s16;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r8,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r8.u32);
	// sth r10,36(r3)
	PPC_STORE_U16(ctx.r3.u32 + 36, ctx.r10.u16);
	// ble cr6,0x8815a0ec
	if (!ctx.cr6.gt) goto loc_8815A0EC;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8815a0ec
	if (ctx.cr6.lt) goto loc_8815A0EC;
	// sth r11,36(r3)
	PPC_STORE_U16(ctx.r3.u32 + 36, ctx.r11.u16);
loc_8815A0EC:
	// lhz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 36);
	// lis r8,-30714
	ctx.r8.s64 = -2012872704;
	// lhz r9,50(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 50);
	// addic. r11,r3,32
	ctx.xer.ca = ctx.r3.u32 > 4294967263;
	ctx.r11.s64 = ctx.r3.s64 + 32;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r7,r3,28
	ctx.r7.s64 = ctx.r3.s64 + 28;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// clrlwi r9,r9,23
	ctx.r9.u64 = ctx.r9.u32 & 0x1FF;
	// addi r8,r8,9552
	ctx.r8.s64 = ctx.r8.s64 + 9552;
	// beq 0x8815a124
	if (ctx.cr0.eq) goto loc_8815A124;
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
loc_8815A124:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r8
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r8.u32);
	// mullw r8,r9,r10
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// stw r8,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8815A140"))) PPC_WEAK_FUNC(sub_8815A140);
PPC_FUNC_IMPL(__imp__sub_8815A140) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x8815A148;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r11,50(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 50);
	// lis r10,-30671
	ctx.r10.s64 = -2010054656;
	// lhz r5,16(r3)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r3.u32 + 16);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r4,r11,4
	ctx.r4.s64 = ctx.r11.s64 + 4;
	// lwz r8,20(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// addi r10,r10,4456
	ctx.r10.s64 = ctx.r10.s64 + 4456;
	// lwz r7,24(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// srawi r4,r4,3
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7) != 0);
	ctx.r4.s64 = ctx.r4.s32 >> 3;
	// clrlwi r9,r11,23
	ctx.r9.u64 = ctx.r11.u32 & 0x1FF;
	// rlwinm r4,r4,2,24,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFC;
	// addi r3,r10,2
	ctx.r3.s64 = ctx.r10.s64 + 2;
	// addi r9,r9,128
	ctx.r9.s64 = ctx.r9.s64 + 128;
	// lis r6,-30714
	ctx.r6.s64 = -2012872704;
	// rlwinm r9,r9,2,21,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x7FC;
	// lhzx r10,r4,r10
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r4.u32 + ctx.r10.u32);
	// addi r30,r6,9552
	ctx.r30.s64 = ctx.r6.s64 + 9552;
	// rlwinm r28,r11,2,21,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x7FC;
	// extsh r11,r5
	ctx.r11.s64 = ctx.r5.s16;
	// lis r29,-30663
	ctx.r29.s64 = -2009530368;
	// addi r6,r11,1
	ctx.r6.s64 = ctx.r11.s64 + 1;
	// sth r10,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r10.u16);
	// lhzx r5,r4,r3
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r4.u32 + ctx.r3.u32);
	// stb r5,10(r31)
	PPC_STORE_U8(ctx.r31.u32 + 10, ctx.r5.u8);
	// lwzx r3,r9,r30
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r30.u32);
	// clrlwi r9,r10,16
	ctx.r9.u64 = ctx.r10.u32 & 0xFFFF;
	// lwzx r5,r28,r30
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r28.u32 + ctx.r30.u32);
	// rlwinm r11,r3,6,0,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0xFFFFFFC0;
	// rlwinm r10,r5,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 6) & 0xFFFFFFC0;
	// lwz r30,-22208(r29)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r29.u32 + -22208);
	// add r5,r11,r7
	ctx.r5.u64 = ctx.r11.u64 + ctx.r7.u64;
	// add r4,r10,r8
	ctx.r4.u64 = ctx.r10.u64 + ctx.r8.u64;
	// stw r5,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r5.u32);
	// rotlwi r11,r9,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// stw r4,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r4.u32);
	// rotlwi r4,r4,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r4.u32, 0);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r3,r11,2635
	ctx.r3.s64 = ctx.r11.s64 + 2635;
	// bl 0x881538c0
	ctx.lr = 0x8815A1E8;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8815a204
	if (ctx.cr6.eq) goto loc_8815A204;
	// lbz r11,10(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r11,26,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 26) & 0xFFFFFFFC;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_8815A204:
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// li r10,2719
	ctx.r10.s64 = 2719;
	// clrlwi r11,r11,30
	ctx.r11.u64 = ctx.r11.u32 & 0x3;
	// sth r10,14(r31)
	PPC_STORE_U16(ctx.r31.u32 + 14, ctx.r10.u16);
	// stw r11,-22208(r29)
	PPC_STORE_U32(ctx.r29.u32 + -22208, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8815A220"))) PPC_WEAK_FUNC(sub_8815A220);
PPC_FUNC_IMPL(__imp__sub_8815A220) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x8815A228;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r11,50(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 50);
	// lis r10,-30671
	ctx.r10.s64 = -2010054656;
	// lwz r8,20(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r5,r11,4
	ctx.r5.s64 = ctx.r11.s64 + 4;
	// lwz r7,24(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r10,r10,4456
	ctx.r10.s64 = ctx.r10.s64 + 4456;
	// lhz r4,16(r3)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r3.u32 + 16);
	// srawi r5,r5,3
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7) != 0);
	ctx.r5.s64 = ctx.r5.s32 >> 3;
	// addi r3,r10,2
	ctx.r3.s64 = ctx.r10.s64 + 2;
	// rlwinm r5,r5,2,24,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFC;
	// lis r6,-30714
	ctx.r6.s64 = -2012872704;
	// clrlwi r9,r11,23
	ctx.r9.u64 = ctx.r11.u32 & 0x1FF;
	// addi r30,r6,9552
	ctx.r30.s64 = ctx.r6.s64 + 9552;
	// rlwinm r11,r11,2,21,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x7FC;
	// lhzx r10,r5,r10
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r5.u32 + ctx.r10.u32);
	// addi r9,r9,128
	ctx.r9.s64 = ctx.r9.s64 + 128;
	// extsh r6,r4
	ctx.r6.s64 = ctx.r4.s16;
	// rlwinm r9,r9,2,21,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x7FC;
	// lis r29,-30663
	ctx.r29.s64 = -2009530368;
	// sth r10,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r10.u16);
	// lhzx r5,r5,r3
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r5.u32 + ctx.r3.u32);
	// stb r5,10(r31)
	PPC_STORE_U8(ctx.r31.u32 + 10, ctx.r5.u8);
	// lwzx r5,r11,r30
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r30.u32);
	// lwzx r3,r9,r30
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r30.u32);
	// clrlwi r9,r10,16
	ctx.r9.u64 = ctx.r10.u32 & 0xFFFF;
	// rlwinm r11,r5,6,0,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 6) & 0xFFFFFFC0;
	// lwz r30,-22208(r29)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r29.u32 + -22208);
	// rlwinm r10,r3,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0xFFFFFFC0;
	// add r4,r11,r8
	ctx.r4.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r5,r10,r7
	ctx.r5.u64 = ctx.r10.u64 + ctx.r7.u64;
	// stw r4,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r4.u32);
	// rotlwi r11,r9,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// stw r5,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r5.u32);
	// rotlwi r4,r4,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r4.u32, 0);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r3,r11,2635
	ctx.r3.s64 = ctx.r11.s64 + 2635;
	// bl 0x881538c0
	ctx.lr = 0x8815A2C4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8815a2e0
	if (ctx.cr6.eq) goto loc_8815A2E0;
	// lbz r11,10(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r11,26,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 26) & 0xFFFFFFFC;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_8815A2E0:
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// li r10,2719
	ctx.r10.s64 = 2719;
	// clrlwi r11,r11,30
	ctx.r11.u64 = ctx.r11.u32 & 0x3;
	// sth r10,14(r31)
	PPC_STORE_U16(ctx.r31.u32 + 14, ctx.r10.u16);
	// stw r11,-22208(r29)
	PPC_STORE_U32(ctx.r29.u32 + -22208, ctx.r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8815A2FC"))) PPC_WEAK_FUNC(sub_8815A2FC);
PPC_FUNC_IMPL(__imp__sub_8815A2FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8815A300"))) PPC_WEAK_FUNC(sub_8815A300);
PPC_FUNC_IMPL(__imp__sub_8815A300) {
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
	// lhz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 16);
	// lhz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 12);
	// lwz r5,24(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// extsh r6,r10
	ctx.r6.s64 = ctx.r10.s16;
	// add r3,r11,r4
	ctx.r3.u64 = ctx.r11.u64 + ctx.r4.u64;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// bl 0x881538c0
	ctx.lr = 0x8815A330;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8815a34c
	if (ctx.cr6.eq) goto loc_8815A34C;
	// lbz r11,10(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r11,26,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 26) & 0xFFFFFFFC;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_8815A34C:
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

__attribute__((alias("__imp__sub_8815A360"))) PPC_WEAK_FUNC(sub_8815A360);
PPC_FUNC_IMPL(__imp__sub_8815A360) {
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
	// lbz r10,11(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 11);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lhz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 16);
	// lhz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 12);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// lwz r5,24(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// extsh r6,r9
	ctx.r6.s64 = ctx.r9.s16;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// bl 0x881538c0
	ctx.lr = 0x8815A398;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8815a3b4
	if (ctx.cr6.eq) goto loc_8815A3B4;
	// lbz r11,10(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r11,26,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 26) & 0xFFFFFFFC;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_8815A3B4:
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

__attribute__((alias("__imp__sub_8815A3C8"))) PPC_WEAK_FUNC(sub_8815A3C8);
PPC_FUNC_IMPL(__imp__sub_8815A3C8) {
	PPC_FUNC_PROLOGUE();
	// lbz r8,11(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 11);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lhz r7,16(r3)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r3.u32 + 16);
	// lhz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 12);
	// extsb r10,r8
	ctx.r10.s64 = ctx.r8.s8;
	// lwz r5,24(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// extsh r6,r7
	ctx.r6.s64 = ctx.r7.s16;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r4,20(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// b 0x881538c0
	sub_881538C0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8815A3F0"))) PPC_WEAK_FUNC(sub_8815A3F0);
PPC_FUNC_IMPL(__imp__sub_8815A3F0) {
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
	// bl 0x8815a220
	ctx.lr = 0x8815A408;
	sub_8815A220(ctx, base);
	// li r11,3847
	ctx.r11.s64 = 3847;
	// li r10,1
	ctx.r10.s64 = 1;
	// sth r11,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r11.u16);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r10,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r10.u8);
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

__attribute__((alias("__imp__sub_8815A430"))) PPC_WEAK_FUNC(sub_8815A430);
PPC_FUNC_IMPL(__imp__sub_8815A430) {
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
	// bl 0x8815a220
	ctx.lr = 0x8815A448;
	sub_8815A220(ctx, base);
	// li r11,3843
	ctx.r11.s64 = 3843;
	// li r10,1
	ctx.r10.s64 = 1;
	// sth r11,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r11.u16);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r10,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r10.u8);
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

__attribute__((alias("__imp__sub_8815A470"))) PPC_WEAK_FUNC(sub_8815A470);
PPC_FUNC_IMPL(__imp__sub_8815A470) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x8815A478;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8815a098
	ctx.lr = 0x8815A484;
	sub_8815A098(ctx, base);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// add r11,r9,r10
	ctx.r11.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lbz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 40);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// add r6,r11,r8
	ctx.r6.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stb r7,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r7.u8);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stw r6,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r6.u32);
	// bge cr6,0x8815a4e4
	if (!ctx.cr6.lt) goto loc_8815A4E4;
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lbz r10,41(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 41);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// srawi r9,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 2;
	// stb r10,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r10.u8);
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r6,r7,r11
	ctx.r6.s64 = ctx.r11.s64 - ctx.r7.s64;
	// stb r6,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r6.u8);
loc_8815A4E4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8815a360
	ctx.lr = 0x8815A4EC;
	sub_8815A360(ctx, base);
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// lhz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 36);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r11,42
	ctx.r9.s64 = ctx.r11.s64 + 42;
	// cmpw cr6,r7,r9
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x8815a5dc
	if (ctx.cr6.lt) goto loc_8815A5DC;
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// li r29,0
	ctx.r29.s64 = 0;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x8815a5dc
	if (!ctx.cr6.gt) goto loc_8815A5DC;
	// lis r27,-30597
	ctx.r27.s64 = -2005204992;
	// lis r11,-30663
	ctx.r11.s64 = -2009530368;
	// lis r10,-30663
	ctx.r10.s64 = -2009530368;
	// lis r9,-30658
	ctx.r9.s64 = -2009202688;
	// lwz r30,-11932(r27)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
	// lwz r24,-30240(r11)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r11.u32 + -30240);
	// lwz r25,-22224(r10)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + -22224);
	// lwz r26,160(r9)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
loc_8815A548:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r28,r29,1
	ctx.r28.s64 = ctx.r29.s64 + 1;
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lbz r8,11(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// mullw r7,r11,r28
	ctx.r7.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lhz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// mullw r3,r28,r9
	ctx.r3.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r9.s32);
	// extsb r10,r8
	ctx.r10.s64 = ctx.r8.s8;
	// subf r4,r3,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r3.s64;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// subf r5,r7,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r7.s64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x8815A588;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8815a5c8
	if (ctx.cr6.eq) goto loc_8815A5C8;
	// subf r11,r29,r24
	ctx.r11.s64 = ctx.r24.s64 - ctx.r29.s64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// mullw r11,r11,r25
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r25.s32);
	// add r8,r11,r26
	ctx.r8.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// rlwimi r9,r8,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r30,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r30.u32);
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// lbz r6,10(r31)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10);
	// rlwinm r5,r6,26,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 26) & 0xFFFFFFFC;
	// or r4,r5,r7
	ctx.r4.u64 = ctx.r5.u64 | ctx.r7.u64;
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
loc_8815A5C8:
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpw cr6,r28,r10
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x8815a548
	if (ctx.cr6.lt) goto loc_8815A548;
loc_8815A5DC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8815A5E8"))) PPC_WEAK_FUNC(sub_8815A5E8);
PPC_FUNC_IMPL(__imp__sub_8815A5E8) {
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
	// bl 0x8815a220
	ctx.lr = 0x8815A600;
	sub_8815A220(ctx, base);
	// li r11,2
	ctx.r11.s64 = 2;
	// lhz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r11,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r11.u8);
	// rlwinm r11,r10,1,15,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1FFFC;
	// addi r9,r11,2991
	ctx.r9.s64 = ctx.r11.s64 + 2991;
	// sth r9,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r9.u16);
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

__attribute__((alias("__imp__sub_8815A630"))) PPC_WEAK_FUNC(sub_8815A630);
PPC_FUNC_IMPL(__imp__sub_8815A630) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x8815A638;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8815a098
	ctx.lr = 0x8815A644;
	sub_8815A098(ctx, base);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// add r11,r9,r10
	ctx.r11.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lbz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 40);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// add r6,r11,r8
	ctx.r6.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stb r7,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r7.u8);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stw r6,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r6.u32);
	// bge cr6,0x8815a6bc
	if (!ctx.cr6.lt) goto loc_8815A6BC;
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lis r10,10922
	ctx.r10.s64 = 715784192;
	// lbz r9,41(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 41);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// ori r8,r10,43691
	ctx.r8.u64 = ctx.r10.u64 | 43691;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// mulhw r7,r11,r8
	ctx.r7.s64 = (int64_t(ctx.r11.s32) * int64_t(ctx.r8.s32)) >> 32;
	// stb r9,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r9.u8);
	// srawi r10,r7,1
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r7.s32 >> 1;
	// rlwinm r9,r10,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r4,r5,r11
	ctx.r4.s64 = ctx.r11.s64 - ctx.r5.s64;
	// stb r4,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r4.u8);
loc_8815A6BC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8815a360
	ctx.lr = 0x8815A6C4;
	sub_8815A360(ctx, base);
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// lhz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 36);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r11,42
	ctx.r9.s64 = ctx.r11.s64 + 42;
	// cmpw cr6,r7,r9
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x8815a7b4
	if (ctx.cr6.lt) goto loc_8815A7B4;
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// li r29,0
	ctx.r29.s64 = 0;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x8815a7b4
	if (!ctx.cr6.gt) goto loc_8815A7B4;
	// lis r27,-30597
	ctx.r27.s64 = -2005204992;
	// lis r11,-30663
	ctx.r11.s64 = -2009530368;
	// lis r10,-30663
	ctx.r10.s64 = -2009530368;
	// lis r9,-30658
	ctx.r9.s64 = -2009202688;
	// lwz r30,-11932(r27)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
	// lwz r24,-30240(r11)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r11.u32 + -30240);
	// lwz r25,-22224(r10)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + -22224);
	// lwz r26,160(r9)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
loc_8815A720:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r28,r29,1
	ctx.r28.s64 = ctx.r29.s64 + 1;
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lbz r8,11(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// mullw r7,r11,r28
	ctx.r7.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lhz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// mullw r3,r28,r9
	ctx.r3.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r9.s32);
	// extsb r10,r8
	ctx.r10.s64 = ctx.r8.s8;
	// subf r4,r3,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r3.s64;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// subf r5,r7,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r7.s64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x8815A760;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8815a7a0
	if (ctx.cr6.eq) goto loc_8815A7A0;
	// subf r11,r29,r24
	ctx.r11.s64 = ctx.r24.s64 - ctx.r29.s64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// mullw r11,r11,r25
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r25.s32);
	// add r8,r11,r26
	ctx.r8.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// rlwimi r9,r8,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r30,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r30.u32);
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// lbz r6,10(r31)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10);
	// rlwinm r5,r6,26,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 26) & 0xFFFFFFFC;
	// or r4,r5,r7
	ctx.r4.u64 = ctx.r5.u64 | ctx.r7.u64;
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
loc_8815A7A0:
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpw cr6,r28,r10
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x8815a720
	if (ctx.cr6.lt) goto loc_8815A720;
loc_8815A7B4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8815A7C0"))) PPC_WEAK_FUNC(sub_8815A7C0);
PPC_FUNC_IMPL(__imp__sub_8815A7C0) {
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
	// bl 0x8815a220
	ctx.lr = 0x8815A7D8;
	sub_8815A220(ctx, base);
	// li r11,2979
	ctx.r11.s64 = 2979;
	// li r10,2
	ctx.r10.s64 = 2;
	// sth r11,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r11.u16);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r10,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r10.u8);
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

__attribute__((alias("__imp__sub_8815A800"))) PPC_WEAK_FUNC(sub_8815A800);
PPC_FUNC_IMPL(__imp__sub_8815A800) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x8815A808;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8815a098
	ctx.lr = 0x8815A814;
	sub_8815A098(ctx, base);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// add r11,r9,r10
	ctx.r11.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lbz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 40);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// add r6,r11,r8
	ctx.r6.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stb r7,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r7.u8);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stw r6,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r6.u32);
	// bge cr6,0x8815a874
	if (!ctx.cr6.lt) goto loc_8815A874;
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lbz r10,41(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 41);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// srawi r9,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 2;
	// stb r10,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r10.u8);
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r6,r7,r11
	ctx.r6.s64 = ctx.r11.s64 - ctx.r7.s64;
	// stb r6,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r6.u8);
loc_8815A874:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8815a360
	ctx.lr = 0x8815A87C;
	sub_8815A360(ctx, base);
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// lhz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 36);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r11,42
	ctx.r9.s64 = ctx.r11.s64 + 42;
	// cmpw cr6,r7,r9
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x8815a96c
	if (ctx.cr6.lt) goto loc_8815A96C;
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// li r29,0
	ctx.r29.s64 = 0;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x8815a96c
	if (!ctx.cr6.gt) goto loc_8815A96C;
	// lis r27,-30597
	ctx.r27.s64 = -2005204992;
	// lis r11,-30663
	ctx.r11.s64 = -2009530368;
	// lis r10,-30663
	ctx.r10.s64 = -2009530368;
	// lis r9,-30658
	ctx.r9.s64 = -2009202688;
	// lwz r30,-11932(r27)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
	// lwz r24,-30240(r11)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r11.u32 + -30240);
	// lwz r25,-22224(r10)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + -22224);
	// lwz r26,160(r9)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
loc_8815A8D8:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r28,r29,1
	ctx.r28.s64 = ctx.r29.s64 + 1;
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lbz r8,11(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// mullw r7,r11,r28
	ctx.r7.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lhz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// mullw r3,r28,r9
	ctx.r3.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r9.s32);
	// extsb r10,r8
	ctx.r10.s64 = ctx.r8.s8;
	// subf r4,r3,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r3.s64;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// subf r5,r7,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r7.s64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x8815A918;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8815a958
	if (ctx.cr6.eq) goto loc_8815A958;
	// subf r11,r29,r24
	ctx.r11.s64 = ctx.r24.s64 - ctx.r29.s64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// mullw r11,r11,r25
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r25.s32);
	// add r8,r11,r26
	ctx.r8.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// rlwimi r9,r8,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r30,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r30.u32);
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// lbz r6,10(r31)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10);
	// rlwinm r5,r6,26,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 26) & 0xFFFFFFFC;
	// or r4,r5,r7
	ctx.r4.u64 = ctx.r5.u64 | ctx.r7.u64;
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
loc_8815A958:
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpw cr6,r28,r10
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x8815a8d8
	if (ctx.cr6.lt) goto loc_8815A8D8;
loc_8815A96C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8815A978"))) PPC_WEAK_FUNC(sub_8815A978);
PPC_FUNC_IMPL(__imp__sub_8815A978) {
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
	// bl 0x8815a220
	ctx.lr = 0x8815A990;
	sub_8815A220(ctx, base);
	// li r11,2
	ctx.r11.s64 = 2;
	// lhz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r11,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r11.u8);
	// rlwinm r11,r10,1,15,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1FFFC;
	// addi r9,r11,2943
	ctx.r9.s64 = ctx.r11.s64 + 2943;
	// sth r9,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r9.u16);
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

__attribute__((alias("__imp__sub_8815A9C0"))) PPC_WEAK_FUNC(sub_8815A9C0);
PPC_FUNC_IMPL(__imp__sub_8815A9C0) {
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
	// bl 0x8815a220
	ctx.lr = 0x8815A9D8;
	sub_8815A220(ctx, base);
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r3,1
	ctx.r3.s64 = 1;
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// stb r9,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r9.u8);
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r8,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r11,2747
	ctx.r7.s64 = ctx.r11.s64 + 2747;
	// sth r7,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r7.u16);
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

__attribute__((alias("__imp__sub_8815AA10"))) PPC_WEAK_FUNC(sub_8815AA10);
PPC_FUNC_IMPL(__imp__sub_8815AA10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x8815AA18;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8815a098
	ctx.lr = 0x8815AA24;
	sub_8815A098(ctx, base);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// add r11,r9,r10
	ctx.r11.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lbz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 40);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// add r6,r11,r8
	ctx.r6.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stb r7,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r7.u8);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stw r6,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r6.u32);
	// bge cr6,0x8815aa84
	if (!ctx.cr6.lt) goto loc_8815AA84;
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lbz r10,41(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 41);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// srawi r9,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 2;
	// stb r10,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r10.u8);
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r6,r7,r11
	ctx.r6.s64 = ctx.r11.s64 - ctx.r7.s64;
	// stb r6,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r6.u8);
loc_8815AA84:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8815a360
	ctx.lr = 0x8815AA8C;
	sub_8815A360(ctx, base);
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// lhz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 36);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r11,42
	ctx.r9.s64 = ctx.r11.s64 + 42;
	// cmpw cr6,r7,r9
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x8815ab7c
	if (ctx.cr6.lt) goto loc_8815AB7C;
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// li r29,0
	ctx.r29.s64 = 0;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x8815ab7c
	if (!ctx.cr6.gt) goto loc_8815AB7C;
	// lis r27,-30597
	ctx.r27.s64 = -2005204992;
	// lis r11,-30663
	ctx.r11.s64 = -2009530368;
	// lis r10,-30663
	ctx.r10.s64 = -2009530368;
	// lis r9,-30658
	ctx.r9.s64 = -2009202688;
	// lwz r30,-11932(r27)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
	// lwz r24,-30240(r11)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r11.u32 + -30240);
	// lwz r25,-22224(r10)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + -22224);
	// lwz r26,160(r9)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
loc_8815AAE8:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r28,r29,1
	ctx.r28.s64 = ctx.r29.s64 + 1;
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lbz r8,11(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// mullw r7,r11,r28
	ctx.r7.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lhz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// mullw r3,r28,r9
	ctx.r3.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r9.s32);
	// extsb r10,r8
	ctx.r10.s64 = ctx.r8.s8;
	// subf r4,r3,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r3.s64;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// subf r5,r7,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r7.s64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x8815AB28;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8815ab68
	if (ctx.cr6.eq) goto loc_8815AB68;
	// subf r11,r29,r24
	ctx.r11.s64 = ctx.r24.s64 - ctx.r29.s64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// mullw r11,r11,r25
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r25.s32);
	// add r8,r11,r26
	ctx.r8.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// rlwimi r9,r8,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r30,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r30.u32);
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// lbz r6,10(r31)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10);
	// rlwinm r5,r6,26,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 26) & 0xFFFFFFFC;
	// or r4,r5,r7
	ctx.r4.u64 = ctx.r5.u64 | ctx.r7.u64;
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
loc_8815AB68:
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpw cr6,r28,r10
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x8815aae8
	if (ctx.cr6.lt) goto loc_8815AAE8;
loc_8815AB7C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8815AB88"))) PPC_WEAK_FUNC(sub_8815AB88);
PPC_FUNC_IMPL(__imp__sub_8815AB88) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x8815AB90;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8815a098
	ctx.lr = 0x8815AB9C;
	sub_8815A098(ctx, base);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// add r11,r9,r10
	ctx.r11.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lbz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 40);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// add r6,r11,r8
	ctx.r6.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stb r7,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r7.u8);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stw r6,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r6.u32);
	// bge cr6,0x8815ac0c
	if (!ctx.cr6.lt) goto loc_8815AC0C;
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lis r10,21845
	ctx.r10.s64 = 1431633920;
	// lbz r9,41(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 41);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// ori r8,r10,21846
	ctx.r8.u64 = ctx.r10.u64 | 21846;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// mulhw r10,r11,r8
	ctx.r10.s64 = (int64_t(ctx.r11.s32) * int64_t(ctx.r8.s32)) >> 32;
	// stb r9,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r9.u8);
	// rlwinm r9,r10,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// subf r6,r7,r11
	ctx.r6.s64 = ctx.r11.s64 - ctx.r7.s64;
	// stb r6,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r6.u8);
loc_8815AC0C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8815a360
	ctx.lr = 0x8815AC14;
	sub_8815A360(ctx, base);
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// lhz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 36);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r11,42
	ctx.r9.s64 = ctx.r11.s64 + 42;
	// cmpw cr6,r7,r9
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x8815ad04
	if (ctx.cr6.lt) goto loc_8815AD04;
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// li r29,0
	ctx.r29.s64 = 0;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x8815ad04
	if (!ctx.cr6.gt) goto loc_8815AD04;
	// lis r27,-30597
	ctx.r27.s64 = -2005204992;
	// lis r11,-30663
	ctx.r11.s64 = -2009530368;
	// lis r10,-30663
	ctx.r10.s64 = -2009530368;
	// lis r9,-30658
	ctx.r9.s64 = -2009202688;
	// lwz r30,-11932(r27)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
	// lwz r24,-30240(r11)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r11.u32 + -30240);
	// lwz r25,-22224(r10)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + -22224);
	// lwz r26,160(r9)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
loc_8815AC70:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r28,r29,1
	ctx.r28.s64 = ctx.r29.s64 + 1;
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lbz r8,11(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// mullw r7,r11,r28
	ctx.r7.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lhz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// mullw r3,r28,r9
	ctx.r3.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r9.s32);
	// extsb r10,r8
	ctx.r10.s64 = ctx.r8.s8;
	// subf r4,r3,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r3.s64;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// subf r5,r7,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r7.s64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x8815ACB0;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8815acf0
	if (ctx.cr6.eq) goto loc_8815ACF0;
	// subf r11,r29,r24
	ctx.r11.s64 = ctx.r24.s64 - ctx.r29.s64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// mullw r11,r11,r25
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r25.s32);
	// add r8,r11,r26
	ctx.r8.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// rlwimi r9,r8,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r30,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r30.u32);
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// lbz r6,10(r31)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10);
	// rlwinm r5,r6,26,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 26) & 0xFFFFFFFC;
	// or r4,r5,r7
	ctx.r4.u64 = ctx.r5.u64 | ctx.r7.u64;
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
loc_8815ACF0:
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpw cr6,r28,r10
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x8815ac70
	if (ctx.cr6.lt) goto loc_8815AC70;
loc_8815AD04:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8815AD10"))) PPC_WEAK_FUNC(sub_8815AD10);
PPC_FUNC_IMPL(__imp__sub_8815AD10) {
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
	// bl 0x8815a220
	ctx.lr = 0x8815AD28;
	sub_8815A220(ctx, base);
	// li r11,2
	ctx.r11.s64 = 2;
	// lhz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r11,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r11.u8);
	// rlwinm r11,r10,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r9,r11,3112
	ctx.r9.s64 = ctx.r11.s64 + 3112;
	// sth r9,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r9.u16);
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

__attribute__((alias("__imp__sub_8815AD60"))) PPC_WEAK_FUNC(sub_8815AD60);
PPC_FUNC_IMPL(__imp__sub_8815AD60) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x8815AD68;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8815a098
	ctx.lr = 0x8815AD74;
	sub_8815A098(ctx, base);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// add r11,r9,r10
	ctx.r11.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lbz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 40);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// add r6,r11,r8
	ctx.r6.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stb r7,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r7.u8);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stw r6,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r6.u32);
	// bge cr6,0x8815ade4
	if (!ctx.cr6.lt) goto loc_8815ADE4;
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lis r10,21845
	ctx.r10.s64 = 1431633920;
	// lbz r9,41(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 41);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// ori r8,r10,21846
	ctx.r8.u64 = ctx.r10.u64 | 21846;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// mulhw r10,r11,r8
	ctx.r10.s64 = (int64_t(ctx.r11.s32) * int64_t(ctx.r8.s32)) >> 32;
	// stb r9,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r9.u8);
	// rlwinm r9,r10,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// subf r6,r7,r11
	ctx.r6.s64 = ctx.r11.s64 - ctx.r7.s64;
	// stb r6,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r6.u8);
loc_8815ADE4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8815a360
	ctx.lr = 0x8815ADEC;
	sub_8815A360(ctx, base);
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// lhz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 36);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r11,42
	ctx.r9.s64 = ctx.r11.s64 + 42;
	// cmpw cr6,r7,r9
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x8815aedc
	if (ctx.cr6.lt) goto loc_8815AEDC;
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// li r29,0
	ctx.r29.s64 = 0;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x8815aedc
	if (!ctx.cr6.gt) goto loc_8815AEDC;
	// lis r27,-30597
	ctx.r27.s64 = -2005204992;
	// lis r11,-30663
	ctx.r11.s64 = -2009530368;
	// lis r10,-30663
	ctx.r10.s64 = -2009530368;
	// lis r9,-30658
	ctx.r9.s64 = -2009202688;
	// lwz r30,-11932(r27)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
	// lwz r24,-30240(r11)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r11.u32 + -30240);
	// lwz r25,-22224(r10)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + -22224);
	// lwz r26,160(r9)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
loc_8815AE48:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r28,r29,1
	ctx.r28.s64 = ctx.r29.s64 + 1;
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lbz r8,11(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// mullw r7,r11,r28
	ctx.r7.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lhz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// mullw r3,r28,r9
	ctx.r3.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r9.s32);
	// extsb r10,r8
	ctx.r10.s64 = ctx.r8.s8;
	// subf r4,r3,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r3.s64;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// subf r5,r7,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r7.s64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x8815AE88;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8815aec8
	if (ctx.cr6.eq) goto loc_8815AEC8;
	// subf r11,r29,r24
	ctx.r11.s64 = ctx.r24.s64 - ctx.r29.s64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// mullw r11,r11,r25
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r25.s32);
	// add r8,r11,r26
	ctx.r8.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// rlwimi r9,r8,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r30,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r30.u32);
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// lbz r6,10(r31)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10);
	// rlwinm r5,r6,26,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 26) & 0xFFFFFFFC;
	// or r4,r5,r7
	ctx.r4.u64 = ctx.r5.u64 | ctx.r7.u64;
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
loc_8815AEC8:
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpw cr6,r28,r10
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x8815ae48
	if (ctx.cr6.lt) goto loc_8815AE48;
loc_8815AEDC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8815AEE8"))) PPC_WEAK_FUNC(sub_8815AEE8);
PPC_FUNC_IMPL(__imp__sub_8815AEE8) {
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
	// bl 0x8815a220
	ctx.lr = 0x8815AF00;
	sub_8815A220(ctx, base);
	// li r11,2
	ctx.r11.s64 = 2;
	// lhz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r11,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r11.u8);
	// rlwinm r11,r10,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r9,r11,3031
	ctx.r9.s64 = ctx.r11.s64 + 3031;
	// sth r9,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r9.u16);
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

__attribute__((alias("__imp__sub_8815AF38"))) PPC_WEAK_FUNC(sub_8815AF38);
PPC_FUNC_IMPL(__imp__sub_8815AF38) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x8815AF40;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8815a098
	ctx.lr = 0x8815AF4C;
	sub_8815A098(ctx, base);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// add r11,r9,r10
	ctx.r11.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lbz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 40);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// add r6,r11,r8
	ctx.r6.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stb r7,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r7.u8);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stw r6,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r6.u32);
	// bge cr6,0x8815afac
	if (!ctx.cr6.lt) goto loc_8815AFAC;
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lbz r10,41(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 41);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// stb r10,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r10.u8);
	// cmpwi cr6,r8,3
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 3, ctx.xer);
	// stb r8,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r8.u8);
	// ble cr6,0x8815afac
	if (!ctx.cr6.gt) goto loc_8815AFAC;
	// stb r29,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r29.u8);
loc_8815AFAC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8815a360
	ctx.lr = 0x8815AFB4;
	sub_8815A360(ctx, base);
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// lhz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 36);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r11,42
	ctx.r9.s64 = ctx.r11.s64 + 42;
	// cmpw cr6,r7,r9
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x8815b0a0
	if (ctx.cr6.lt) goto loc_8815B0A0;
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x8815b0a0
	if (!ctx.cr6.gt) goto loc_8815B0A0;
	// lis r27,-30597
	ctx.r27.s64 = -2005204992;
	// lis r11,-30663
	ctx.r11.s64 = -2009530368;
	// lis r10,-30663
	ctx.r10.s64 = -2009530368;
	// lis r9,-30658
	ctx.r9.s64 = -2009202688;
	// lwz r30,-11932(r27)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
	// lwz r24,-30240(r11)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r11.u32 + -30240);
	// lwz r25,-22224(r10)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + -22224);
	// lwz r26,160(r9)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
loc_8815B00C:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r28,r29,1
	ctx.r28.s64 = ctx.r29.s64 + 1;
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lbz r8,11(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// mullw r7,r11,r28
	ctx.r7.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lhz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// mullw r3,r28,r9
	ctx.r3.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r9.s32);
	// extsb r10,r8
	ctx.r10.s64 = ctx.r8.s8;
	// subf r4,r3,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r3.s64;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// subf r5,r7,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r7.s64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x8815B04C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8815b08c
	if (ctx.cr6.eq) goto loc_8815B08C;
	// subf r11,r29,r24
	ctx.r11.s64 = ctx.r24.s64 - ctx.r29.s64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// mullw r11,r11,r25
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r25.s32);
	// add r8,r11,r26
	ctx.r8.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// rlwimi r9,r8,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r30,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r30.u32);
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// lbz r6,10(r31)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10);
	// rlwinm r5,r6,26,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 26) & 0xFFFFFFFC;
	// or r4,r5,r7
	ctx.r4.u64 = ctx.r5.u64 | ctx.r7.u64;
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
loc_8815B08C:
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpw cr6,r28,r10
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x8815b00c
	if (ctx.cr6.lt) goto loc_8815B00C;
loc_8815B0A0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8815B0AC"))) PPC_WEAK_FUNC(sub_8815B0AC);
PPC_FUNC_IMPL(__imp__sub_8815B0AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8815B0B0"))) PPC_WEAK_FUNC(sub_8815B0B0);
PPC_FUNC_IMPL(__imp__sub_8815B0B0) {
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
	// bl 0x8815a220
	ctx.lr = 0x8815B0C8;
	sub_8815A220(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lhz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r11,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r11.u8);
	// rotlwi r11,r10,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r9,r11,3555
	ctx.r9.s64 = ctx.r11.s64 + 3555;
	// sth r9,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r9.u16);
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

__attribute__((alias("__imp__sub_8815B0F8"))) PPC_WEAK_FUNC(sub_8815B0F8);
PPC_FUNC_IMPL(__imp__sub_8815B0F8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x8815B100;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8815a098
	ctx.lr = 0x8815B10C;
	sub_8815A098(ctx, base);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// add r11,r9,r10
	ctx.r11.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lbz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 40);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// add r6,r11,r8
	ctx.r6.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stb r7,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r7.u8);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stw r6,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r6.u32);
	// bge cr6,0x8815b16c
	if (!ctx.cr6.lt) goto loc_8815B16C;
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lbz r10,41(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 41);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// stb r10,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r10.u8);
	// cmpwi cr6,r8,2
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 2, ctx.xer);
	// stb r8,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r8.u8);
	// ble cr6,0x8815b16c
	if (!ctx.cr6.gt) goto loc_8815B16C;
	// stb r29,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r29.u8);
loc_8815B16C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8815a360
	ctx.lr = 0x8815B174;
	sub_8815A360(ctx, base);
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// lhz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 36);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r11,42
	ctx.r9.s64 = ctx.r11.s64 + 42;
	// cmpw cr6,r7,r9
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x8815b260
	if (ctx.cr6.lt) goto loc_8815B260;
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x8815b260
	if (!ctx.cr6.gt) goto loc_8815B260;
	// lis r27,-30597
	ctx.r27.s64 = -2005204992;
	// lis r11,-30663
	ctx.r11.s64 = -2009530368;
	// lis r10,-30663
	ctx.r10.s64 = -2009530368;
	// lis r9,-30658
	ctx.r9.s64 = -2009202688;
	// lwz r30,-11932(r27)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
	// lwz r24,-30240(r11)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r11.u32 + -30240);
	// lwz r25,-22224(r10)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + -22224);
	// lwz r26,160(r9)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
loc_8815B1CC:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r28,r29,1
	ctx.r28.s64 = ctx.r29.s64 + 1;
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lbz r8,11(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// mullw r7,r11,r28
	ctx.r7.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lhz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// mullw r3,r28,r9
	ctx.r3.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r9.s32);
	// extsb r10,r8
	ctx.r10.s64 = ctx.r8.s8;
	// subf r4,r3,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r3.s64;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// subf r5,r7,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r7.s64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x8815B20C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8815b24c
	if (ctx.cr6.eq) goto loc_8815B24C;
	// subf r11,r29,r24
	ctx.r11.s64 = ctx.r24.s64 - ctx.r29.s64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// mullw r11,r11,r25
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r25.s32);
	// add r8,r11,r26
	ctx.r8.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// rlwimi r9,r8,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r30,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r30.u32);
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// lbz r6,10(r31)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10);
	// rlwinm r5,r6,26,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 26) & 0xFFFFFFFC;
	// or r4,r5,r7
	ctx.r4.u64 = ctx.r5.u64 | ctx.r7.u64;
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
loc_8815B24C:
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpw cr6,r28,r10
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x8815b1cc
	if (ctx.cr6.lt) goto loc_8815B1CC;
loc_8815B260:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8815B26C"))) PPC_WEAK_FUNC(sub_8815B26C);
PPC_FUNC_IMPL(__imp__sub_8815B26C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8815B270"))) PPC_WEAK_FUNC(sub_8815B270);
PPC_FUNC_IMPL(__imp__sub_8815B270) {
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
	// bl 0x8815a220
	ctx.lr = 0x8815B288;
	sub_8815A220(ctx, base);
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r11,r11,1168
	ctx.r11.s64 = ctx.r11.s64 + 1168;
	// stb r10,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r10.u8);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 + ctx.r10.u64;
	// sth r9,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r9.u16);
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

__attribute__((alias("__imp__sub_8815B2BC"))) PPC_WEAK_FUNC(sub_8815B2BC);
PPC_FUNC_IMPL(__imp__sub_8815B2BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8815B2C0"))) PPC_WEAK_FUNC(sub_8815B2C0);
PPC_FUNC_IMPL(__imp__sub_8815B2C0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x8815B2C8;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8815a098
	ctx.lr = 0x8815B2D4;
	sub_8815A098(ctx, base);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// add r11,r9,r10
	ctx.r11.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lbz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 40);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// add r6,r11,r8
	ctx.r6.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stb r7,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r7.u8);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stw r6,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r6.u32);
	// bge cr6,0x8815b334
	if (!ctx.cr6.lt) goto loc_8815B334;
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lbz r10,41(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 41);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// stb r10,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r10.u8);
	// cmpwi cr6,r8,3
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 3, ctx.xer);
	// stb r8,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r8.u8);
	// ble cr6,0x8815b334
	if (!ctx.cr6.gt) goto loc_8815B334;
	// stb r29,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r29.u8);
loc_8815B334:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8815a360
	ctx.lr = 0x8815B33C;
	sub_8815A360(ctx, base);
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// lhz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 36);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r11,42
	ctx.r9.s64 = ctx.r11.s64 + 42;
	// cmpw cr6,r7,r9
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x8815b428
	if (ctx.cr6.lt) goto loc_8815B428;
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x8815b428
	if (!ctx.cr6.gt) goto loc_8815B428;
	// lis r27,-30597
	ctx.r27.s64 = -2005204992;
	// lis r11,-30663
	ctx.r11.s64 = -2009530368;
	// lis r10,-30663
	ctx.r10.s64 = -2009530368;
	// lis r9,-30658
	ctx.r9.s64 = -2009202688;
	// lwz r30,-11932(r27)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
	// lwz r24,-30240(r11)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r11.u32 + -30240);
	// lwz r25,-22224(r10)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + -22224);
	// lwz r26,160(r9)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
loc_8815B394:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r28,r29,1
	ctx.r28.s64 = ctx.r29.s64 + 1;
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lbz r8,11(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// mullw r7,r11,r28
	ctx.r7.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lhz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// mullw r3,r28,r9
	ctx.r3.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r9.s32);
	// extsb r10,r8
	ctx.r10.s64 = ctx.r8.s8;
	// subf r4,r3,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r3.s64;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// subf r5,r7,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r7.s64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x8815B3D4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8815b414
	if (ctx.cr6.eq) goto loc_8815B414;
	// subf r11,r29,r24
	ctx.r11.s64 = ctx.r24.s64 - ctx.r29.s64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// mullw r11,r11,r25
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r25.s32);
	// add r8,r11,r26
	ctx.r8.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// rlwimi r9,r8,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r30,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r30.u32);
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// lbz r6,10(r31)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10);
	// rlwinm r5,r6,26,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 26) & 0xFFFFFFFC;
	// or r4,r5,r7
	ctx.r4.u64 = ctx.r5.u64 | ctx.r7.u64;
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
loc_8815B414:
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpw cr6,r28,r10
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x8815b394
	if (ctx.cr6.lt) goto loc_8815B394;
loc_8815B428:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8815B434"))) PPC_WEAK_FUNC(sub_8815B434);
PPC_FUNC_IMPL(__imp__sub_8815B434) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8815B438"))) PPC_WEAK_FUNC(sub_8815B438);
PPC_FUNC_IMPL(__imp__sub_8815B438) {
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
	// bl 0x8815a220
	ctx.lr = 0x8815B450;
	sub_8815A220(ctx, base);
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r9,r11,859
	ctx.r9.s64 = ctx.r11.s64 + 859;
	// stb r10,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r10.u8);
	// rlwinm r8,r9,2,16,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFC;
	// sth r8,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r8.u16);
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

__attribute__((alias("__imp__sub_8815B480"))) PPC_WEAK_FUNC(sub_8815B480);
PPC_FUNC_IMPL(__imp__sub_8815B480) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x8815B488;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8815a098
	ctx.lr = 0x8815B494;
	sub_8815A098(ctx, base);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// add r11,r9,r10
	ctx.r11.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lbz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 40);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// add r6,r11,r8
	ctx.r6.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stb r7,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r7.u8);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stw r6,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r6.u32);
	// bge cr6,0x8815b4f4
	if (!ctx.cr6.lt) goto loc_8815B4F4;
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lbz r10,41(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 41);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// stb r10,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r10.u8);
	// cmpwi cr6,r8,2
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 2, ctx.xer);
	// stb r8,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r8.u8);
	// ble cr6,0x8815b4f4
	if (!ctx.cr6.gt) goto loc_8815B4F4;
	// stb r29,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r29.u8);
loc_8815B4F4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8815a360
	ctx.lr = 0x8815B4FC;
	sub_8815A360(ctx, base);
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// lhz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 36);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r11,42
	ctx.r9.s64 = ctx.r11.s64 + 42;
	// cmpw cr6,r7,r9
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x8815b5e8
	if (ctx.cr6.lt) goto loc_8815B5E8;
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x8815b5e8
	if (!ctx.cr6.gt) goto loc_8815B5E8;
	// lis r27,-30597
	ctx.r27.s64 = -2005204992;
	// lis r11,-30663
	ctx.r11.s64 = -2009530368;
	// lis r10,-30663
	ctx.r10.s64 = -2009530368;
	// lis r9,-30658
	ctx.r9.s64 = -2009202688;
	// lwz r30,-11932(r27)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
	// lwz r24,-30240(r11)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r11.u32 + -30240);
	// lwz r25,-22224(r10)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + -22224);
	// lwz r26,160(r9)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
loc_8815B554:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r28,r29,1
	ctx.r28.s64 = ctx.r29.s64 + 1;
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lbz r8,11(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// mullw r7,r11,r28
	ctx.r7.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lhz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// mullw r3,r28,r9
	ctx.r3.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r9.s32);
	// extsb r10,r8
	ctx.r10.s64 = ctx.r8.s8;
	// subf r4,r3,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r3.s64;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// subf r5,r7,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r7.s64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x8815B594;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8815b5d4
	if (ctx.cr6.eq) goto loc_8815B5D4;
	// subf r11,r29,r24
	ctx.r11.s64 = ctx.r24.s64 - ctx.r29.s64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// mullw r11,r11,r25
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r25.s32);
	// add r8,r11,r26
	ctx.r8.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// rlwimi r9,r8,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r30,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r30.u32);
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// lbz r6,10(r31)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10);
	// rlwinm r5,r6,26,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 26) & 0xFFFFFFFC;
	// or r4,r5,r7
	ctx.r4.u64 = ctx.r5.u64 | ctx.r7.u64;
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
loc_8815B5D4:
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpw cr6,r28,r10
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x8815b554
	if (ctx.cr6.lt) goto loc_8815B554;
loc_8815B5E8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8815B5F4"))) PPC_WEAK_FUNC(sub_8815B5F4);
PPC_FUNC_IMPL(__imp__sub_8815B5F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8815B5F8"))) PPC_WEAK_FUNC(sub_8815B5F8);
PPC_FUNC_IMPL(__imp__sub_8815B5F8) {
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
	// bl 0x8815a220
	ctx.lr = 0x8815B610;
	sub_8815A220(ctx, base);
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// stb r9,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r9.u8);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r8,r11,3385
	ctx.r8.s64 = ctx.r11.s64 + 3385;
	// sth r8,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r8.u16);
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

__attribute__((alias("__imp__sub_8815B644"))) PPC_WEAK_FUNC(sub_8815B644);
PPC_FUNC_IMPL(__imp__sub_8815B644) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8815B648"))) PPC_WEAK_FUNC(sub_8815B648);
PPC_FUNC_IMPL(__imp__sub_8815B648) {
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
	// bl 0x8815a220
	ctx.lr = 0x8815B660;
	sub_8815A220(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lhz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r11,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r11.u8);
	// rotlwi r11,r10,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r9,r11,3759
	ctx.r9.s64 = ctx.r11.s64 + 3759;
	// sth r9,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r9.u16);
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

__attribute__((alias("__imp__sub_8815B690"))) PPC_WEAK_FUNC(sub_8815B690);
PPC_FUNC_IMPL(__imp__sub_8815B690) {
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
	// bl 0x8815a220
	ctx.lr = 0x8815B6A8;
	sub_8815A220(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lhz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r11,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r11.u8);
	// rotlwi r11,r10,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r9,r11,3691
	ctx.r9.s64 = ctx.r11.s64 + 3691;
	// sth r9,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r9.u16);
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

__attribute__((alias("__imp__sub_8815B6D8"))) PPC_WEAK_FUNC(sub_8815B6D8);
PPC_FUNC_IMPL(__imp__sub_8815B6D8) {
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
	// bl 0x8815a220
	ctx.lr = 0x8815B6F0;
	sub_8815A220(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lhz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r11,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r11.u8);
	// rotlwi r11,r10,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r9,r11,3623
	ctx.r9.s64 = ctx.r11.s64 + 3623;
	// sth r9,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r9.u16);
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

__attribute__((alias("__imp__sub_8815B720"))) PPC_WEAK_FUNC(sub_8815B720);
PPC_FUNC_IMPL(__imp__sub_8815B720) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x8815B728;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8815a098
	ctx.lr = 0x8815B734;
	sub_8815A098(ctx, base);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// add r11,r9,r10
	ctx.r11.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lbz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 40);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// add r6,r11,r8
	ctx.r6.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stb r7,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r7.u8);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stw r6,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r6.u32);
	// bge cr6,0x8815b788
	if (!ctx.cr6.lt) goto loc_8815B788;
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lbz r10,41(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 41);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// clrlwi r8,r9,30
	ctx.r8.u64 = ctx.r9.u32 & 0x3;
	// stb r10,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r10.u8);
	// stb r8,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r8.u8);
loc_8815B788:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8815a360
	ctx.lr = 0x8815B790;
	sub_8815A360(ctx, base);
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// lhz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 36);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r11,42
	ctx.r9.s64 = ctx.r11.s64 + 42;
	// cmpw cr6,r7,r9
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x8815b880
	if (ctx.cr6.lt) goto loc_8815B880;
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// li r29,0
	ctx.r29.s64 = 0;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x8815b880
	if (!ctx.cr6.gt) goto loc_8815B880;
	// lis r27,-30597
	ctx.r27.s64 = -2005204992;
	// lis r11,-30663
	ctx.r11.s64 = -2009530368;
	// lis r10,-30663
	ctx.r10.s64 = -2009530368;
	// lis r9,-30658
	ctx.r9.s64 = -2009202688;
	// lwz r30,-11932(r27)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
	// lwz r24,-30240(r11)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r11.u32 + -30240);
	// lwz r25,-22224(r10)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + -22224);
	// lwz r26,160(r9)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
loc_8815B7EC:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r28,r29,1
	ctx.r28.s64 = ctx.r29.s64 + 1;
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lbz r8,11(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// mullw r7,r11,r28
	ctx.r7.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lhz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// mullw r3,r28,r9
	ctx.r3.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r9.s32);
	// extsb r10,r8
	ctx.r10.s64 = ctx.r8.s8;
	// subf r4,r3,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r3.s64;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// subf r5,r7,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r7.s64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x8815B82C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8815b86c
	if (ctx.cr6.eq) goto loc_8815B86C;
	// subf r11,r29,r24
	ctx.r11.s64 = ctx.r24.s64 - ctx.r29.s64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// mullw r11,r11,r25
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r25.s32);
	// add r8,r11,r26
	ctx.r8.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// rlwimi r9,r8,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r30,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r30.u32);
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// lbz r6,10(r31)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10);
	// rlwinm r5,r6,26,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 26) & 0xFFFFFFFC;
	// or r4,r5,r7
	ctx.r4.u64 = ctx.r5.u64 | ctx.r7.u64;
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
loc_8815B86C:
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpw cr6,r28,r10
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x8815b7ec
	if (ctx.cr6.lt) goto loc_8815B7EC;
loc_8815B880:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8815B88C"))) PPC_WEAK_FUNC(sub_8815B88C);
PPC_FUNC_IMPL(__imp__sub_8815B88C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8815B890"))) PPC_WEAK_FUNC(sub_8815B890);
PPC_FUNC_IMPL(__imp__sub_8815B890) {
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
	// bl 0x8815a220
	ctx.lr = 0x8815B8A8;
	sub_8815A220(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lhz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r11,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r11.u8);
	// rotlwi r11,r10,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r9,r11,3317
	ctx.r9.s64 = ctx.r11.s64 + 3317;
	// sth r9,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r9.u16);
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

__attribute__((alias("__imp__sub_8815B8D8"))) PPC_WEAK_FUNC(sub_8815B8D8);
PPC_FUNC_IMPL(__imp__sub_8815B8D8) {
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
	// bl 0x8815a220
	ctx.lr = 0x8815B8F0;
	sub_8815A220(ctx, base);
	// lis r10,-30663
	ctx.r10.s64 = -2009530368;
	// li r9,3209
	ctx.r9.s64 = 3209;
	// li r8,0
	ctx.r8.s64 = 0;
	// sth r9,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r9.u16);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r8,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r8.u8);
	// lwz r11,-30232(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -30232);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// mr r6,r11
	ctx.r6.u64 = ctx.r11.u64;
	// clrlwi r11,r7,29
	ctx.r11.u64 = ctx.r7.u32 & 0x7;
	// stb r6,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r6.u8);
	// stw r11,-30232(r10)
	PPC_STORE_U32(ctx.r10.u32 + -30232, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_8815B934"))) PPC_WEAK_FUNC(sub_8815B934);
PPC_FUNC_IMPL(__imp__sub_8815B934) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8815B938"))) PPC_WEAK_FUNC(sub_8815B938);
PPC_FUNC_IMPL(__imp__sub_8815B938) {
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
	// bl 0x8815a220
	ctx.lr = 0x8815B950;
	sub_8815A220(ctx, base);
	// lis r10,-30663
	ctx.r10.s64 = -2009530368;
	// li r9,3201
	ctx.r9.s64 = 3201;
	// li r8,0
	ctx.r8.s64 = 0;
	// sth r9,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r9.u16);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r8,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r8.u8);
	// lwz r11,-30232(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -30232);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// mr r6,r11
	ctx.r6.u64 = ctx.r11.u64;
	// clrlwi r11,r7,29
	ctx.r11.u64 = ctx.r7.u32 & 0x7;
	// stb r6,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r6.u8);
	// stw r11,-30232(r10)
	PPC_STORE_U32(ctx.r10.u32 + -30232, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_8815B994"))) PPC_WEAK_FUNC(sub_8815B994);
PPC_FUNC_IMPL(__imp__sub_8815B994) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8815B998"))) PPC_WEAK_FUNC(sub_8815B998);
PPC_FUNC_IMPL(__imp__sub_8815B998) {
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
	// bl 0x8815a220
	ctx.lr = 0x8815B9B0;
	sub_8815A220(ctx, base);
	// lis r10,-30663
	ctx.r10.s64 = -2009530368;
	// li r9,3193
	ctx.r9.s64 = 3193;
	// li r8,0
	ctx.r8.s64 = 0;
	// sth r9,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r9.u16);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r8,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r8.u8);
	// lwz r11,-30232(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -30232);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// mr r6,r11
	ctx.r6.u64 = ctx.r11.u64;
	// clrlwi r11,r7,29
	ctx.r11.u64 = ctx.r7.u32 & 0x7;
	// stb r6,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r6.u8);
	// stw r11,-30232(r10)
	PPC_STORE_U32(ctx.r10.u32 + -30232, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_8815B9F4"))) PPC_WEAK_FUNC(sub_8815B9F4);
PPC_FUNC_IMPL(__imp__sub_8815B9F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8815B9F8"))) PPC_WEAK_FUNC(sub_8815B9F8);
PPC_FUNC_IMPL(__imp__sub_8815B9F8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x8815BA00;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8815a098
	ctx.lr = 0x8815BA0C;
	sub_8815A098(ctx, base);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// add r11,r9,r10
	ctx.r11.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lbz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 40);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// add r6,r11,r8
	ctx.r6.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stb r7,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r7.u8);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stw r6,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r6.u32);
	// bge cr6,0x8815ba60
	if (!ctx.cr6.lt) goto loc_8815BA60;
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lbz r10,41(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 41);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// clrlwi r8,r9,29
	ctx.r8.u64 = ctx.r9.u32 & 0x7;
	// stb r10,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r10.u8);
	// stb r8,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r8.u8);
loc_8815BA60:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8815a360
	ctx.lr = 0x8815BA68;
	sub_8815A360(ctx, base);
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// lhz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 36);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r11,42
	ctx.r9.s64 = ctx.r11.s64 + 42;
	// cmpw cr6,r7,r9
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x8815bb58
	if (ctx.cr6.lt) goto loc_8815BB58;
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// li r29,0
	ctx.r29.s64 = 0;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x8815bb58
	if (!ctx.cr6.gt) goto loc_8815BB58;
	// lis r27,-30597
	ctx.r27.s64 = -2005204992;
	// lis r11,-30663
	ctx.r11.s64 = -2009530368;
	// lis r10,-30663
	ctx.r10.s64 = -2009530368;
	// lis r9,-30658
	ctx.r9.s64 = -2009202688;
	// lwz r30,-11932(r27)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
	// lwz r24,-30240(r11)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r11.u32 + -30240);
	// lwz r25,-22224(r10)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + -22224);
	// lwz r26,160(r9)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
loc_8815BAC4:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r28,r29,1
	ctx.r28.s64 = ctx.r29.s64 + 1;
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lbz r8,11(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// mullw r7,r11,r28
	ctx.r7.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lhz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// mullw r3,r28,r9
	ctx.r3.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r9.s32);
	// extsb r10,r8
	ctx.r10.s64 = ctx.r8.s8;
	// subf r4,r3,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r3.s64;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// subf r5,r7,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r7.s64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x8815BB04;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8815bb44
	if (ctx.cr6.eq) goto loc_8815BB44;
	// subf r11,r29,r24
	ctx.r11.s64 = ctx.r24.s64 - ctx.r29.s64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// mullw r11,r11,r25
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r25.s32);
	// add r8,r11,r26
	ctx.r8.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// rlwimi r9,r8,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r30,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r30.u32);
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// lbz r6,10(r31)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10);
	// rlwinm r5,r6,26,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 26) & 0xFFFFFFFC;
	// or r4,r5,r7
	ctx.r4.u64 = ctx.r5.u64 | ctx.r7.u64;
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
loc_8815BB44:
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpw cr6,r28,r10
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x8815bac4
	if (ctx.cr6.lt) goto loc_8815BAC4;
loc_8815BB58:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8815BB64"))) PPC_WEAK_FUNC(sub_8815BB64);
PPC_FUNC_IMPL(__imp__sub_8815BB64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8815BB68"))) PPC_WEAK_FUNC(sub_8815BB68);
PPC_FUNC_IMPL(__imp__sub_8815BB68) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x8815BB70;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8815a098
	ctx.lr = 0x8815BB7C;
	sub_8815A098(ctx, base);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// add r11,r9,r10
	ctx.r11.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lbz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 40);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// add r6,r11,r8
	ctx.r6.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stb r7,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r7.u8);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stw r6,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r6.u32);
	// bge cr6,0x8815bbd0
	if (!ctx.cr6.lt) goto loc_8815BBD0;
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lbz r10,41(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 41);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// clrlwi r8,r9,29
	ctx.r8.u64 = ctx.r9.u32 & 0x7;
	// stb r10,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r10.u8);
	// stb r8,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r8.u8);
loc_8815BBD0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8815a360
	ctx.lr = 0x8815BBD8;
	sub_8815A360(ctx, base);
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// lhz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 36);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r11,42
	ctx.r9.s64 = ctx.r11.s64 + 42;
	// cmpw cr6,r7,r9
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x8815bcc8
	if (ctx.cr6.lt) goto loc_8815BCC8;
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// li r29,0
	ctx.r29.s64 = 0;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x8815bcc8
	if (!ctx.cr6.gt) goto loc_8815BCC8;
	// lis r27,-30597
	ctx.r27.s64 = -2005204992;
	// lis r11,-30663
	ctx.r11.s64 = -2009530368;
	// lis r10,-30663
	ctx.r10.s64 = -2009530368;
	// lis r9,-30658
	ctx.r9.s64 = -2009202688;
	// lwz r30,-11932(r27)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
	// lwz r24,-30240(r11)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r11.u32 + -30240);
	// lwz r25,-22224(r10)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + -22224);
	// lwz r26,160(r9)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
loc_8815BC34:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r28,r29,1
	ctx.r28.s64 = ctx.r29.s64 + 1;
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lbz r8,11(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// mullw r7,r11,r28
	ctx.r7.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lhz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// mullw r3,r28,r9
	ctx.r3.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r9.s32);
	// extsb r10,r8
	ctx.r10.s64 = ctx.r8.s8;
	// subf r4,r3,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r3.s64;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// subf r5,r7,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r7.s64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x8815BC74;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8815bcb4
	if (ctx.cr6.eq) goto loc_8815BCB4;
	// subf r11,r29,r24
	ctx.r11.s64 = ctx.r24.s64 - ctx.r29.s64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// mullw r11,r11,r25
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r25.s32);
	// add r8,r11,r26
	ctx.r8.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// rlwimi r9,r8,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r30,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r30.u32);
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// lbz r6,10(r31)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10);
	// rlwinm r5,r6,26,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 26) & 0xFFFFFFFC;
	// or r4,r5,r7
	ctx.r4.u64 = ctx.r5.u64 | ctx.r7.u64;
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
loc_8815BCB4:
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpw cr6,r28,r10
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x8815bc34
	if (ctx.cr6.lt) goto loc_8815BC34;
loc_8815BCC8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8815BCD4"))) PPC_WEAK_FUNC(sub_8815BCD4);
PPC_FUNC_IMPL(__imp__sub_8815BCD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8815BCD8"))) PPC_WEAK_FUNC(sub_8815BCD8);
PPC_FUNC_IMPL(__imp__sub_8815BCD8) {
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
	// bl 0x8815a220
	ctx.lr = 0x8815BCF0;
	sub_8815A220(ctx, base);
	// lis r10,-30663
	ctx.r10.s64 = -2009530368;
	// li r9,3185
	ctx.r9.s64 = 3185;
	// li r8,0
	ctx.r8.s64 = 0;
	// sth r9,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r9.u16);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r8,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r8.u8);
	// lwz r11,-30232(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -30232);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// mr r6,r11
	ctx.r6.u64 = ctx.r11.u64;
	// clrlwi r11,r7,29
	ctx.r11.u64 = ctx.r7.u32 & 0x7;
	// stb r6,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r6.u8);
	// stw r11,-30232(r10)
	PPC_STORE_U32(ctx.r10.u32 + -30232, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_8815BD34"))) PPC_WEAK_FUNC(sub_8815BD34);
PPC_FUNC_IMPL(__imp__sub_8815BD34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8815BD38"))) PPC_WEAK_FUNC(sub_8815BD38);
PPC_FUNC_IMPL(__imp__sub_8815BD38) {
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
	// bl 0x8815a220
	ctx.lr = 0x8815BD50;
	sub_8815A220(ctx, base);
	// li r11,3245
	ctx.r11.s64 = 3245;
	// li r10,1
	ctx.r10.s64 = 1;
	// sth r11,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r11.u16);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r10,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r10.u8);
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

__attribute__((alias("__imp__sub_8815BD78"))) PPC_WEAK_FUNC(sub_8815BD78);
PPC_FUNC_IMPL(__imp__sub_8815BD78) {
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
	// bl 0x8815a220
	ctx.lr = 0x8815BD90;
	sub_8815A220(ctx, base);
	// li r11,3241
	ctx.r11.s64 = 3241;
	// li r10,1
	ctx.r10.s64 = 1;
	// sth r11,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r11.u16);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r10,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r10.u8);
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

__attribute__((alias("__imp__sub_8815BDB8"))) PPC_WEAK_FUNC(sub_8815BDB8);
PPC_FUNC_IMPL(__imp__sub_8815BDB8) {
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
	// bl 0x8815a220
	ctx.lr = 0x8815BDD0;
	sub_8815A220(ctx, base);
	// li r11,3237
	ctx.r11.s64 = 3237;
	// li r10,1
	ctx.r10.s64 = 1;
	// sth r11,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r11.u16);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r10,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r10.u8);
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

__attribute__((alias("__imp__sub_8815BDF8"))) PPC_WEAK_FUNC(sub_8815BDF8);
PPC_FUNC_IMPL(__imp__sub_8815BDF8) {
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
	// bl 0x8815a220
	ctx.lr = 0x8815BE10;
	sub_8815A220(ctx, base);
	// li r11,3233
	ctx.r11.s64 = 3233;
	// li r10,1
	ctx.r10.s64 = 1;
	// sth r11,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r11.u16);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r10,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r10.u8);
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

__attribute__((alias("__imp__sub_8815BE38"))) PPC_WEAK_FUNC(sub_8815BE38);
PPC_FUNC_IMPL(__imp__sub_8815BE38) {
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
	// bl 0x8815a220
	ctx.lr = 0x8815BE50;
	sub_8815A220(ctx, base);
	// li r11,3229
	ctx.r11.s64 = 3229;
	// li r10,1
	ctx.r10.s64 = 1;
	// sth r11,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r11.u16);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r10,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r10.u8);
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

__attribute__((alias("__imp__sub_8815BE78"))) PPC_WEAK_FUNC(sub_8815BE78);
PPC_FUNC_IMPL(__imp__sub_8815BE78) {
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
	// bl 0x8815a220
	ctx.lr = 0x8815BE90;
	sub_8815A220(ctx, base);
	// li r11,3221
	ctx.r11.s64 = 3221;
	// li r10,1
	ctx.r10.s64 = 1;
	// sth r11,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r11.u16);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r10,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r10.u8);
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

__attribute__((alias("__imp__sub_8815BEB8"))) PPC_WEAK_FUNC(sub_8815BEB8);
PPC_FUNC_IMPL(__imp__sub_8815BEB8) {
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
	// bl 0x8815a220
	ctx.lr = 0x8815BED0;
	sub_8815A220(ctx, base);
	// li r11,3217
	ctx.r11.s64 = 3217;
	// li r10,1
	ctx.r10.s64 = 1;
	// sth r11,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r11.u16);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r10,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r10.u8);
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

__attribute__((alias("__imp__sub_8815BEF8"))) PPC_WEAK_FUNC(sub_8815BEF8);
PPC_FUNC_IMPL(__imp__sub_8815BEF8) {
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
	// bl 0x8815a220
	ctx.lr = 0x8815BF10;
	sub_8815A220(ctx, base);
	// li r11,3177
	ctx.r11.s64 = 3177;
	// li r10,1
	ctx.r10.s64 = 1;
	// sth r11,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r11.u16);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r10,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r10.u8);
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

__attribute__((alias("__imp__sub_8815BF38"))) PPC_WEAK_FUNC(sub_8815BF38);
PPC_FUNC_IMPL(__imp__sub_8815BF38) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071144
	ctx.lr = 0x8815BF40;
	__savegprlr_23(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8815a098
	ctx.lr = 0x8815BF4C;
	sub_8815A098(ctx, base);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// li r28,0
	ctx.r28.s64 = 0;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lbz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 40);
	// add r4,r9,r10
	ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// stw r4,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r4.u32);
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r9.u8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// add r5,r11,r8
	ctx.r5.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stw r5,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r5.u32);
	// bge cr6,0x8815bfac
	if (!ctx.cr6.lt) goto loc_8815BFAC;
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lbz r10,41(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 41);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// stb r10,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r10.u8);
	// cmpwi cr6,r8,5
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 5, ctx.xer);
	// stb r8,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r8.u8);
	// ble cr6,0x8815bfac
	if (!ctx.cr6.gt) goto loc_8815BFAC;
	// stb r28,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r28.u8);
loc_8815BFAC:
	// lbz r10,11(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// lhz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// extsb r8,r10
	ctx.r8.s64 = ctx.r10.s8;
	// addi r23,r11,4744
	ctx.r23.s64 = ctx.r11.s64 + 4744;
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// extsh r6,r9
	ctx.r6.s64 = ctx.r9.s16;
	// lhzx r10,r7,r23
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + ctx.r23.u32);
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x8815BFD8;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8815bff4
	if (ctx.cr6.eq) goto loc_8815BFF4;
	// lbz r11,10(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r11,26,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 26) & 0xFFFFFFFC;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_8815BFF4:
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// lhz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 36);
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r8,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r7,r11,42
	ctx.r7.s64 = ctx.r11.s64 + 42;
	// cmpw cr6,r9,r7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, ctx.xer);
	// blt cr6,0x8815c0d8
	if (ctx.cr6.lt) goto loc_8815C0D8;
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x8815c0d8
	if (!ctx.cr6.gt) goto loc_8815C0D8;
	// lis r27,-30597
	ctx.r27.s64 = -2005204992;
	// lis r11,-30663
	ctx.r11.s64 = -2009530368;
	// lis r10,-30663
	ctx.r10.s64 = -2009530368;
	// lis r9,-30658
	ctx.r9.s64 = -2009202688;
	// lwz r30,-11932(r27)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
	// lwz r24,-30240(r11)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r11.u32 + -30240);
	// lwz r25,-22224(r10)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + -22224);
	// lwz r26,160(r9)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
loc_8815C04C:
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// addi r29,r28,1
	ctx.r29.s64 = ctx.r28.s64 + 1;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// extsb r9,r11
	ctx.r9.s64 = ctx.r11.s8;
	// lwz r8,28(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// mullw r5,r10,r29
	ctx.r5.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r29.s32);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lhz r7,16(r31)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// lhz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// rlwinm r11,r9,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// mullw r9,r29,r8
	ctx.r9.s64 = int64_t(ctx.r29.s32) * int64_t(ctx.r8.s32);
	// lhzx r11,r11,r23
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r23.u32);
	// subf r5,r5,r4
	ctx.r5.s64 = ctx.r4.s64 - ctx.r5.s64;
	// subf r4,r9,r3
	ctx.r4.s64 = ctx.r3.s64 - ctx.r9.s64;
	// extsh r6,r7
	ctx.r6.s64 = ctx.r7.s16;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x8815C094;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8815c0c4
	if (ctx.cr6.eq) goto loc_8815C0C4;
	// subf r11,r28,r24
	ctx.r11.s64 = ctx.r24.s64 - ctx.r28.s64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// mullw r11,r11,r25
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r25.s32);
	// add r8,r11,r26
	ctx.r8.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// rlwimi r9,r8,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r30,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r30.u32);
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
loc_8815C0C4:
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// mr r28,r29
	ctx.r28.u64 = ctx.r29.u64;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpw cr6,r29,r10
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x8815c04c
	if (ctx.cr6.lt) goto loc_8815C04C;
loc_8815C0D8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8815C0E4"))) PPC_WEAK_FUNC(sub_8815C0E4);
PPC_FUNC_IMPL(__imp__sub_8815C0E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8815C0E8"))) PPC_WEAK_FUNC(sub_8815C0E8);
PPC_FUNC_IMPL(__imp__sub_8815C0E8) {
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
	// bl 0x8815a220
	ctx.lr = 0x8815C100;
	sub_8815A220(ctx, base);
	// li r11,3169
	ctx.r11.s64 = 3169;
	// li r10,1
	ctx.r10.s64 = 1;
	// sth r11,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r11.u16);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r10,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r10.u8);
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

__attribute__((alias("__imp__sub_8815C128"))) PPC_WEAK_FUNC(sub_8815C128);
PPC_FUNC_IMPL(__imp__sub_8815C128) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071144
	ctx.lr = 0x8815C130;
	__savegprlr_23(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8815a098
	ctx.lr = 0x8815C13C;
	sub_8815A098(ctx, base);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// li r28,0
	ctx.r28.s64 = 0;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lbz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 40);
	// add r4,r9,r10
	ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// stw r4,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r4.u32);
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r9.u8);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// add r5,r11,r8
	ctx.r5.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stw r5,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r5.u32);
	// bge cr6,0x8815c19c
	if (!ctx.cr6.lt) goto loc_8815C19C;
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lbz r10,41(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 41);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// stb r10,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r10.u8);
	// cmpwi cr6,r8,8
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 8, ctx.xer);
	// stb r8,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r8.u8);
	// blt cr6,0x8815c19c
	if (ctx.cr6.lt) goto loc_8815C19C;
	// stb r28,11(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11, ctx.r28.u8);
loc_8815C19C:
	// lbz r10,11(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// lhz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// extsb r8,r10
	ctx.r8.s64 = ctx.r10.s8;
	// addi r23,r11,4712
	ctx.r23.s64 = ctx.r11.s64 + 4712;
	// lhz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// extsh r6,r9
	ctx.r6.s64 = ctx.r9.s16;
	// lwzx r10,r7,r23
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r23.u32);
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x8815C1C8;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8815c1e4
	if (ctx.cr6.eq) goto loc_8815C1E4;
	// lbz r11,10(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r11,26,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 26) & 0xFFFFFFFC;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_8815C1E4:
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// lhz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 36);
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r8,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r7,r11,42
	ctx.r7.s64 = ctx.r11.s64 + 42;
	// cmpw cr6,r9,r7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, ctx.xer);
	// blt cr6,0x8815c2c8
	if (ctx.cr6.lt) goto loc_8815C2C8;
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x8815c2c8
	if (!ctx.cr6.gt) goto loc_8815C2C8;
	// lis r27,-30597
	ctx.r27.s64 = -2005204992;
	// lis r11,-30663
	ctx.r11.s64 = -2009530368;
	// lis r10,-30663
	ctx.r10.s64 = -2009530368;
	// lis r9,-30658
	ctx.r9.s64 = -2009202688;
	// lwz r30,-11932(r27)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
	// lwz r24,-30240(r11)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r11.u32 + -30240);
	// lwz r25,-22224(r10)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + -22224);
	// lwz r26,160(r9)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
loc_8815C23C:
	// lbz r11,11(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11);
	// addi r29,r28,1
	ctx.r29.s64 = ctx.r28.s64 + 1;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// extsb r9,r11
	ctx.r9.s64 = ctx.r11.s8;
	// lwz r8,28(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// mullw r5,r10,r29
	ctx.r5.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r29.s32);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lhz r7,16(r31)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// lhz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// mullw r9,r29,r8
	ctx.r9.s64 = int64_t(ctx.r29.s32) * int64_t(ctx.r8.s32);
	// lwzx r11,r11,r23
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r23.u32);
	// subf r5,r5,r4
	ctx.r5.s64 = ctx.r4.s64 - ctx.r5.s64;
	// subf r4,r9,r3
	ctx.r4.s64 = ctx.r3.s64 - ctx.r9.s64;
	// extsh r6,r7
	ctx.r6.s64 = ctx.r7.s16;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x8815C284;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8815c2b4
	if (ctx.cr6.eq) goto loc_8815C2B4;
	// subf r11,r28,r24
	ctx.r11.s64 = ctx.r24.s64 - ctx.r28.s64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// mullw r11,r11,r25
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r25.s32);
	// add r8,r11,r26
	ctx.r8.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// rlwimi r9,r8,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r30,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r30.u32);
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
loc_8815C2B4:
	// lbz r11,43(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 43);
	// mr r28,r29
	ctx.r28.u64 = ctx.r29.u64;
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpw cr6,r29,r10
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x8815c23c
	if (ctx.cr6.lt) goto loc_8815C23C;
loc_8815C2C8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8815C2D4"))) PPC_WEAK_FUNC(sub_8815C2D4);
PPC_FUNC_IMPL(__imp__sub_8815C2D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8815C2D8"))) PPC_WEAK_FUNC(sub_8815C2D8);
PPC_FUNC_IMPL(__imp__sub_8815C2D8) {
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
	// bl 0x8815a220
	ctx.lr = 0x8815C2F0;
	sub_8815A220(ctx, base);
	// li r11,3159
	ctx.r11.s64 = 3159;
	// li r10,1
	ctx.r10.s64 = 1;
	// sth r11,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r11.u16);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r10,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r10.u8);
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

__attribute__((alias("__imp__sub_8815C318"))) PPC_WEAK_FUNC(sub_8815C318);
PPC_FUNC_IMPL(__imp__sub_8815C318) {
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
	// bl 0x8815a220
	ctx.lr = 0x8815C330;
	sub_8815A220(ctx, base);
	// li r11,3153
	ctx.r11.s64 = 3153;
	// li r10,1
	ctx.r10.s64 = 1;
	// sth r11,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r11.u16);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r10,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r10.u8);
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

__attribute__((alias("__imp__sub_8815C358"))) PPC_WEAK_FUNC(sub_8815C358);
PPC_FUNC_IMPL(__imp__sub_8815C358) {
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
	// bl 0x8815a220
	ctx.lr = 0x8815C370;
	sub_8815A220(ctx, base);
	// li r11,3147
	ctx.r11.s64 = 3147;
	// li r10,1
	ctx.r10.s64 = 1;
	// sth r11,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r11.u16);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r10,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r10.u8);
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

__attribute__((alias("__imp__sub_8815C398"))) PPC_WEAK_FUNC(sub_8815C398);
PPC_FUNC_IMPL(__imp__sub_8815C398) {
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
	// bl 0x8815a220
	ctx.lr = 0x8815C3B0;
	sub_8815A220(ctx, base);
	// li r11,3143
	ctx.r11.s64 = 3143;
	// li r10,1
	ctx.r10.s64 = 1;
	// sth r11,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r11.u16);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r10,41(r31)
	PPC_STORE_U8(ctx.r31.u32 + 41, ctx.r10.u8);
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

