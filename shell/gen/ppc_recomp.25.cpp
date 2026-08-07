#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_8215C288"))) PPC_WEAK_FUNC(sub_8215C288);
PPC_FUNC_IMPL(__imp__sub_8215C288) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8215C290;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8215c31c
	if (!ctx.cr6.eq) goto loc_8215C31C;
	// lwz r3,0(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// cmplw cr6,r3,r6
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r6.u32, ctx.xer);
	// bne cr6,0x8215c2f8
	if (!ctx.cr6.eq) goto loc_8215C2F8;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x8207e150
	ctx.lr = 0x8215C2C8;
	sub_8207E150(ctx, base);
	// stw r3,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8215c2dc
	if (!ctx.cr0.eq) goto loc_8215C2DC;
loc_8215C2D4:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8215c320
	goto loc_8215C320;
loc_8215C2DC:
	// li r11,1
	ctx.r11.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r11,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x8207dac0
	ctx.lr = 0x8215C2F4;
	sub_8207DAC0(ctx, base);
	// b 0x8215c310
	goto loc_8215C310;
loc_8215C2F8:
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// bl 0x8215f0f0
	ctx.lr = 0x8215C304;
	sub_8215F0F0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8215c2d4
	if (ctx.cr0.eq) goto loc_8215C2D4;
	// stw r3,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r3.u32);
loc_8215C310:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_8215C31C:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8215C320:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215C328"))) PPC_WEAK_FUNC(sub_8215C328);
PPC_FUNC_IMPL(__imp__sub_8215C328) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c950
	ctx.lr = 0x8215C330;
	__savegprlr_14(ctx, base);
	// stwu r1,-688(r1)
	ea = -688 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r22,0
	ctx.r22.s64 = 0;
	// stw r4,716(r1)
	PPC_STORE_U32(ctx.r1.u32 + 716, ctx.r4.u32);
	// li r11,350
	ctx.r11.s64 = 350;
	// stw r6,732(r1)
	PPC_STORE_U32(ctx.r1.u32 + 732, ctx.r6.u32);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// stw r22,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r22.u32);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// sth r22,96(r1)
	PPC_STORE_U16(ctx.r1.u32 + 96, ctx.r22.u16);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bne cr6,0x8215c394
	if (!ctx.cr6.eq) goto loc_8215C394;
loc_8215C368:
	// bl 0x8207d4d8
	ctx.lr = 0x8215C36C;
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
	ctx.lr = 0x8215C38C;
	sub_8207D940(ctx, base);
loc_8215C38C:
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x8215d53c
	goto loc_8215D53C;
loc_8215C394:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x8215c368
	if (ctx.cr6.eq) goto loc_8215C368;
	// lwz r11,12(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 12);
	// rlwinm. r11,r11,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8215c438
	if (!ctx.cr0.eq) goto loc_8215C438;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x820809e8
	ctx.lr = 0x8215C3B0;
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
	// beq cr6,0x8215c3ec
	if (ctx.cr6.eq) goto loc_8215C3EC;
	// cmpwi cr6,r3,-2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -2, ctx.xer);
	// beq cr6,0x8215c3ec
	if (ctx.cr6.eq) goto loc_8215C3EC;
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
	// b 0x8215c3f0
	goto loc_8215C3F0;
loc_8215C3EC:
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
loc_8215C3F0:
	// lbz r10,40(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 40);
	// rlwinm. r10,r10,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8215c368
	if (!ctx.cr0.eq) goto loc_8215C368;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8215c428
	if (ctx.cr6.eq) goto loc_8215C428;
	// cmpwi cr6,r3,-2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -2, ctx.xer);
	// beq cr6,0x8215c428
	if (ctx.cr6.eq) goto loc_8215C428;
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
	// b 0x8215c42c
	goto loc_8215C42C;
loc_8215C428:
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
loc_8215C42C:
	// lbz r11,40(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 40);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8215c368
	if (!ctx.cr0.eq) goto loc_8215C368;
loc_8215C438:
	// lbz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// mr r14,r22
	ctx.r14.u64 = ctx.r22.u64;
	// stb r22,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r22.u8);
	// stw r22,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r22.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8215d538
	if (ctx.cr0.eq) goto loc_8215D538;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lwz r19,716(r1)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 716);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r11,r11,2792
	ctx.r11.s64 = ctx.r11.s64 + 2792;
	// addi r10,r10,2800
	ctx.r10.s64 = ctx.r10.s64 + 2800;
	// stw r11,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r11.u32);
	// stw r10,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r10.u32);
loc_8215C46C:
	// bl 0x820854d8
	ctx.lr = 0x8215C470;
	sub_820854D8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8215c4e8
	if (ctx.cr0.eq) goto loc_8215C4E8;
	// addi r14,r14,-1
	ctx.r14.s64 = ctx.r14.s64 + -1;
loc_8215C47C:
	// lwz r11,4(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// addi r14,r14,1
	ctx.r14.s64 = ctx.r14.s64 + 1;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r26)
	PPC_STORE_U32(ctx.r26.u32 + 4, ctx.r11.u32);
	// blt 0x8215c4a4
	if (ctx.cr0.lt) goto loc_8215C4A4;
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// lbz r31,0(r11)
	ctx.r31.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// stw r10,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r10.u32);
	// b 0x8215c4b0
	goto loc_8215C4B0;
loc_8215C4A4:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8215d548
	ctx.lr = 0x8215C4AC;
	sub_8215D548(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_8215C4B0:
	// cmpwi cr6,r31,-1
	ctx.cr6.compare<int32_t>(ctx.r31.s32, -1, ctx.xer);
	// beq cr6,0x8215c4d4
	if (ctx.cr6.eq) goto loc_8215C4D4;
	// clrlwi r3,r31,24
	ctx.r3.u64 = ctx.r31.u32 & 0xFF;
	// bl 0x820854d8
	ctx.lr = 0x8215C4C0;
	sub_820854D8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8215c47c
	if (!ctx.cr0.eq) goto loc_8215C47C;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8215f1a0
	ctx.lr = 0x8215C4D4;
	sub_8215F1A0(ctx, base);
loc_8215C4D4:
	// lbzu r3,1(r19)
	ea = 1 + ctx.r19.u32;
	ctx.r3.u64 = PPC_LOAD_U8(ea);
	ctx.r19.u32 = ea;
	// bl 0x820854d8
	ctx.lr = 0x8215C4DC;
	sub_820854D8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8215c4d4
	if (!ctx.cr0.eq) goto loc_8215C4D4;
	// b 0x8215d4cc
	goto loc_8215D4CC;
loc_8215C4E8:
	// lbz r11,0(r19)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r19.u32 + 0);
	// cmplwi cr6,r11,37
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 37, ctx.xer);
	// bne cr6,0x8215d404
	if (!ctx.cr6.eq) goto loc_8215D404;
	// lbz r10,1(r19)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r19.u32 + 1);
	// cmplwi cr6,r10,37
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 37, ctx.xer);
	// beq cr6,0x8215d3e8
	if (ctx.cr6.eq) goto loc_8215D3E8;
	// li r27,0
	ctx.r27.s64 = 0;
	// li r16,1
	ctx.r16.s64 = 1;
	// mr r23,r27
	ctx.r23.u64 = ctx.r27.u64;
	// mr r18,r27
	ctx.r18.u64 = ctx.r27.u64;
	// mr r17,r27
	ctx.r17.u64 = ctx.r27.u64;
	// mr r15,r27
	ctx.r15.u64 = ctx.r27.u64;
	// mr r25,r27
	ctx.r25.u64 = ctx.r27.u64;
	// mr r20,r27
	ctx.r20.u64 = ctx.r27.u64;
	// mr r29,r27
	ctx.r29.u64 = ctx.r27.u64;
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// mr r24,r27
	ctx.r24.u64 = ctx.r27.u64;
	// mr r28,r27
	ctx.r28.u64 = ctx.r27.u64;
	// mr r21,r27
	ctx.r21.u64 = ctx.r27.u64;
loc_8215C534:
	// lbzu r31,1(r19)
	ea = 1 + ctx.r19.u32;
	ctx.r31.u64 = PPC_LOAD_U8(ea);
	ctx.r19.u32 = ea;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r19,716(r1)
	PPC_STORE_U32(ctx.r1.u32 + 716, ctx.r19.u32);
	// bl 0x82085498
	ctx.lr = 0x8215C544;
	sub_82085498(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8215c560
	if (ctx.cr0.eq) goto loc_8215C560;
	// mulli r11,r15,10
	ctx.r11.s64 = ctx.r15.s64 * 10;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// addi r15,r11,-48
	ctx.r15.s64 = ctx.r11.s64 + -48;
	// b 0x8215c680
	goto loc_8215C680;
loc_8215C560:
	// cmpwi cr6,r31,78
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 78, ctx.xer);
	// bgt cr6,0x8215c618
	if (ctx.cr6.gt) goto loc_8215C618;
	// beq cr6,0x8215c680
	if (ctx.cr6.eq) goto loc_8215C680;
	// cmpwi cr6,r31,42
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 42, ctx.xer);
	// beq cr6,0x8215c60c
	if (ctx.cr6.eq) goto loc_8215C60C;
	// cmpwi cr6,r31,70
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 70, ctx.xer);
	// beq cr6,0x8215c680
	if (ctx.cr6.eq) goto loc_8215C680;
	// cmpwi cr6,r31,73
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 73, ctx.xer);
	// beq cr6,0x8215c594
	if (ctx.cr6.eq) goto loc_8215C594;
	// cmpwi cr6,r31,76
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 76, ctx.xer);
	// bne cr6,0x8215c630
	if (!ctx.cr6.eq) goto loc_8215C630;
	// addi r11,r16,1
	ctx.r11.s64 = ctx.r16.s64 + 1;
	// b 0x8215c67c
	goto loc_8215C67C;
loc_8215C594:
	// lwz r19,716(r1)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 716);
	// lbz r10,1(r19)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r19.u32 + 1);
	// cmplwi cr6,r10,54
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 54, ctx.xer);
	// bne cr6,0x8215c5c8
	if (!ctx.cr6.eq) goto loc_8215C5C8;
	// lbz r9,2(r19)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r19.u32 + 2);
	// addi r11,r19,2
	ctx.r11.s64 = ctx.r19.s64 + 2;
	// cmplwi cr6,r9,52
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 52, ctx.xer);
	// bne cr6,0x8215c5c8
	if (!ctx.cr6.eq) goto loc_8215C5C8;
loc_8215C5B4:
	// std r27,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r27.u64);
	// addi r21,r21,1
	ctx.r21.s64 = ctx.r21.s64 + 1;
loc_8215C5BC:
	// mr r19,r11
	ctx.r19.u64 = ctx.r11.u64;
	// stw r11,716(r1)
	PPC_STORE_U32(ctx.r1.u32 + 716, ctx.r11.u32);
	// b 0x8215c684
	goto loc_8215C684;
loc_8215C5C8:
	// cmplwi cr6,r10,51
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 51, ctx.xer);
	// bne cr6,0x8215c5e0
	if (!ctx.cr6.eq) goto loc_8215C5E0;
	// lbz r9,2(r19)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r19.u32 + 2);
	// addi r11,r19,2
	ctx.r11.s64 = ctx.r19.s64 + 2;
	// cmplwi cr6,r9,50
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 50, ctx.xer);
	// beq cr6,0x8215c5bc
	if (ctx.cr6.eq) goto loc_8215C5BC;
loc_8215C5E0:
	// cmplwi cr6,r10,100
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 100, ctx.xer);
	// beq cr6,0x8215c684
	if (ctx.cr6.eq) goto loc_8215C684;
	// cmplwi cr6,r10,105
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 105, ctx.xer);
	// beq cr6,0x8215c684
	if (ctx.cr6.eq) goto loc_8215C684;
	// cmplwi cr6,r10,111
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 111, ctx.xer);
	// beq cr6,0x8215c684
	if (ctx.cr6.eq) goto loc_8215C684;
	// cmplwi cr6,r10,120
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 120, ctx.xer);
	// beq cr6,0x8215c684
	if (ctx.cr6.eq) goto loc_8215C684;
	// cmplwi cr6,r10,88
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 88, ctx.xer);
	// bne cr6,0x8215c634
	if (!ctx.cr6.eq) goto loc_8215C634;
	// b 0x8215c684
	goto loc_8215C684;
loc_8215C60C:
	// addi r11,r29,1
	ctx.r11.s64 = ctx.r29.s64 + 1;
	// extsb r29,r11
	ctx.r29.s64 = ctx.r11.s8;
	// b 0x8215c680
	goto loc_8215C680;
loc_8215C618:
	// cmpwi cr6,r31,104
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 104, ctx.xer);
	// beq cr6,0x8215c670
	if (ctx.cr6.eq) goto loc_8215C670;
	// cmpwi cr6,r31,108
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 108, ctx.xer);
	// beq cr6,0x8215c640
	if (ctx.cr6.eq) goto loc_8215C640;
	// cmpwi cr6,r31,119
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 119, ctx.xer);
	// beq cr6,0x8215c660
	if (ctx.cr6.eq) goto loc_8215C660;
loc_8215C630:
	// lwz r19,716(r1)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 716);
loc_8215C634:
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// extsb r30,r11
	ctx.r30.s64 = ctx.r11.s8;
	// b 0x8215c684
	goto loc_8215C684;
loc_8215C640:
	// lwz r19,716(r1)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 716);
	// addi r11,r19,1
	ctx.r11.s64 = ctx.r19.s64 + 1;
	// lbz r10,1(r19)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r19.u32 + 1);
	// cmplwi cr6,r10,108
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 108, ctx.xer);
	// beq cr6,0x8215c5b4
	if (ctx.cr6.eq) goto loc_8215C5B4;
	// addi r11,r16,1
	ctx.r11.s64 = ctx.r16.s64 + 1;
	// extsb r16,r11
	ctx.r16.s64 = ctx.r11.s8;
	// b 0x8215c664
	goto loc_8215C664;
loc_8215C660:
	// lwz r19,716(r1)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 716);
loc_8215C664:
	// addi r11,r28,1
	ctx.r11.s64 = ctx.r28.s64 + 1;
	// extsb r28,r11
	ctx.r28.s64 = ctx.r11.s8;
	// b 0x8215c684
	goto loc_8215C684;
loc_8215C670:
	// addi r10,r28,-1
	ctx.r10.s64 = ctx.r28.s64 + -1;
	// addi r11,r16,-1
	ctx.r11.s64 = ctx.r16.s64 + -1;
	// extsb r28,r10
	ctx.r28.s64 = ctx.r10.s8;
loc_8215C67C:
	// extsb r16,r11
	ctx.r16.s64 = ctx.r11.s8;
loc_8215C680:
	// lwz r19,716(r1)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 716);
loc_8215C684:
	// extsb. r11,r30
	ctx.r11.s64 = ctx.r30.s8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8215c534
	if (ctx.cr0.eq) goto loc_8215C534;
	// extsb. r11,r29
	ctx.r11.s64 = ctx.r29.s8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r11.u32);
	// bne 0x8215c6bc
	if (!ctx.cr0.eq) goto loc_8215C6BC;
	// lwz r11,732(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 732);
	// addi r10,r11,7
	ctx.r10.s64 = ctx.r11.s64 + 7;
	// stw r11,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r11.u32);
	// rlwinm r11,r10,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// stw r11,732(r1)
	PPC_STORE_U32(ctx.r1.u32 + 732, ctx.r11.u32);
	// lwz r11,-4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -4);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// b 0x8215c6c0
	goto loc_8215C6C0;
loc_8215C6BC:
	// stw r27,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r27.u32);
loc_8215C6C0:
	// extsb. r11,r28
	ctx.r11.s64 = ctx.r28.s8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// mr r29,r27
	ctx.r29.u64 = ctx.r27.u64;
	// bne 0x8215c6e8
	if (!ctx.cr0.eq) goto loc_8215C6E8;
	// lbz r11,0(r19)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r19.u32 + 0);
	// cmplwi cr6,r11,83
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 83, ctx.xer);
	// beq cr6,0x8215c6e4
	if (ctx.cr6.eq) goto loc_8215C6E4;
	// cmplwi cr6,r11,67
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 67, ctx.xer);
	// li r28,-1
	ctx.r28.s64 = -1;
	// bne cr6,0x8215c6e8
	if (!ctx.cr6.eq) goto loc_8215C6E8;
loc_8215C6E4:
	// li r28,1
	ctx.r28.s64 = 1;
loc_8215C6E8:
	// lwz r10,716(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 716);
	// lbz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// ori r19,r11,32
	ctx.r19.u64 = ctx.r11.u64 | 32;
	// cmpwi cr6,r19,110
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 110, ctx.xer);
	// beq cr6,0x8215c7a0
	if (ctx.cr6.eq) goto loc_8215C7A0;
	// cmpwi cr6,r19,99
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 99, ctx.xer);
	// beq cr6,0x8215c760
	if (ctx.cr6.eq) goto loc_8215C760;
	// cmpwi cr6,r19,123
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 123, ctx.xer);
	// beq cr6,0x8215c760
	if (ctx.cr6.eq) goto loc_8215C760;
loc_8215C70C:
	// lwz r11,4(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// addi r14,r14,1
	ctx.r14.s64 = ctx.r14.s64 + 1;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r26)
	PPC_STORE_U32(ctx.r26.u32 + 4, ctx.r11.u32);
	// blt 0x8215c734
	if (ctx.cr0.lt) goto loc_8215C734;
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// lbz r31,0(r11)
	ctx.r31.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// stw r10,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r10.u32);
	// b 0x8215c740
	goto loc_8215C740;
loc_8215C734:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8215d548
	ctx.lr = 0x8215C73C;
	sub_8215D548(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_8215C740:
	// cmpwi cr6,r31,-1
	ctx.cr6.compare<int32_t>(ctx.r31.s32, -1, ctx.xer);
	// beq cr6,0x8215c758
	if (ctx.cr6.eq) goto loc_8215C758;
	// clrlwi r3,r31,24
	ctx.r3.u64 = ctx.r31.u32 & 0xFF;
	// bl 0x820854d8
	ctx.lr = 0x8215C750;
	sub_820854D8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8215c70c
	if (!ctx.cr0.eq) goto loc_8215C70C;
loc_8215C758:
	// mr r22,r31
	ctx.r22.u64 = ctx.r31.u64;
	// b 0x8215c794
	goto loc_8215C794;
loc_8215C760:
	// lwz r11,4(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// addi r14,r14,1
	ctx.r14.s64 = ctx.r14.s64 + 1;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r26)
	PPC_STORE_U32(ctx.r26.u32 + 4, ctx.r11.u32);
	// blt 0x8215c788
	if (ctx.cr0.lt) goto loc_8215C788;
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// lbz r22,0(r11)
	ctx.r22.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// stw r10,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r10.u32);
	// b 0x8215c794
	goto loc_8215C794;
loc_8215C788:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8215d548
	ctx.lr = 0x8215C790;
	sub_8215D548(ctx, base);
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
loc_8215C794:
	// cmpwi cr6,r22,-1
	ctx.cr6.compare<int32_t>(ctx.r22.s32, -1, ctx.xer);
	// beq cr6,0x8215d500
	if (ctx.cr6.eq) goto loc_8215D500;
	// lwz r10,716(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 716);
loc_8215C7A0:
	// cmpwi cr6,r17,0
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 0, ctx.xer);
	// beq cr6,0x8215c7b0
	if (ctx.cr6.eq) goto loc_8215C7B0;
	// cmpwi cr6,r15,0
	ctx.cr6.compare<int32_t>(ctx.r15.s32, 0, ctx.xer);
	// beq cr6,0x8215d4ec
	if (ctx.cr6.eq) goto loc_8215D4EC;
loc_8215C7B0:
	// addi r11,r19,-99
	ctx.r11.s64 = ctx.r19.s64 + -99;
	// cmplwi cr6,r11,24
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 24, ctx.xer);
	// bgt cr6,0x8215d39c
	if (ctx.cr6.gt) goto loc_8215D39C;
	// lis r12,-32253
	ctx.r12.s64 = -2113732608;
	// rlwinm r0,r11,1,0,30
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r12,r12,29384
	ctx.r12.s64 = ctx.r12.s64 + 29384;
	// lhzx r0,r12,r0
	ctx.r0.u64 = PPC_LOAD_U16(ctx.r12.u32 + ctx.r0.u32);
	// lis r12,-32234
	ctx.r12.s64 = -2112487424;
	// addi r12,r12,-14364
	ctx.r12.s64 = ctx.r12.s64 + -14364;
	// nop 
	// add r12,r12,r0
	ctx.r12.u64 = ctx.r12.u64 + ctx.r0.u64;
	// mtctr r12
	ctx.ctr.u64 = ctx.r12.u64;
	// bctr 
	switch (ctx.r11.u64) {
	case 0:
		goto loc_8215C7E4;
	case 1:
		goto loc_8215CC84;
	case 2:
		goto loc_8215CFC4;
	case 3:
		goto loc_8215CFC4;
	case 4:
		goto loc_8215CFC4;
	case 5:
		goto loc_8215D39C;
	case 6:
		goto loc_8215CB24;
	case 7:
		goto loc_8215D39C;
	case 8:
		goto loc_8215D39C;
	case 9:
		goto loc_8215D39C;
	case 10:
		goto loc_8215D39C;
	case 11:
		goto loc_8215CF74;
	case 12:
		goto loc_8215CC84;
	case 13:
		goto loc_8215CC80;
	case 14:
		goto loc_8215D39C;
	case 15:
		goto loc_8215D39C;
	case 16:
		goto loc_8215C7F4;
	case 17:
		goto loc_8215D39C;
	case 18:
		goto loc_8215CC84;
	case 19:
		goto loc_8215D39C;
	case 20:
		goto loc_8215D39C;
	case 21:
		goto loc_8215CB28;
	case 22:
		goto loc_8215D39C;
	case 23:
		goto loc_8215D39C;
	case 24:
		goto loc_8215C804;
	default:
		__builtin_unreachable();
	}
loc_8215C7E4:
	// cmpwi cr6,r17,0
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 0, ctx.xer);
	// bne cr6,0x8215c7f4
	if (!ctx.cr6.eq) goto loc_8215C7F4;
	// li r17,1
	ctx.r17.s64 = 1;
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
loc_8215C7F4:
	// extsb. r11,r28
	ctx.r11.s64 = ctx.r28.s8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble 0x8215c948
	if (!ctx.cr0.gt) goto loc_8215C948;
	// li r24,1
	ctx.r24.s64 = 1;
	// b 0x8215c948
	goto loc_8215C948;
loc_8215C804:
	// extsb. r11,r28
	ctx.r11.s64 = ctx.r28.s8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble 0x8215c810
	if (!ctx.cr0.gt) goto loc_8215C810;
	// li r24,1
	ctx.r24.s64 = 1;
loc_8215C810:
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// stw r7,716(r1)
	PPC_STORE_U32(ctx.r1.u32 + 716, ctx.r7.u32);
	// lbz r11,0(r7)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r7.u32 + 0);
	// cmplwi cr6,r11,94
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 94, ctx.xer);
	// bne cr6,0x8215c82c
	if (!ctx.cr6.eq) goto loc_8215C82C;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// li r25,-1
	ctx.r25.s64 = -1;
loc_8215C82C:
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// li r6,0
	ctx.r6.s64 = 0;
	// cmpwi cr6,r19,123
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 123, ctx.xer);
	// std r6,0(r11)
	PPC_STORE_U64(ctx.r11.u32 + 0, ctx.r6.u64);
	// std r6,8(r11)
	PPC_STORE_U64(ctx.r11.u32 + 8, ctx.r6.u64);
	// std r6,16(r11)
	PPC_STORE_U64(ctx.r11.u32 + 16, ctx.r6.u64);
	// std r6,24(r11)
	PPC_STORE_U64(ctx.r11.u32 + 24, ctx.r6.u64);
	// bne cr6,0x8215c868
	if (!ctx.cr6.eq) goto loc_8215C868;
	// lbz r11,0(r7)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r7.u32 + 0);
	// cmplwi cr6,r11,93
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 93, ctx.xer);
	// bne cr6,0x8215c868
	if (!ctx.cr6.eq) goto loc_8215C868;
	// li r11,32
	ctx.r11.s64 = 32;
	// li r27,93
	ctx.r27.s64 = 93;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// stb r11,155(r1)
	PPC_STORE_U8(ctx.r1.u32 + 155, ctx.r11.u8);
loc_8215C868:
	// lbz r11,0(r7)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r7.u32 + 0);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,93
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 93, ctx.xer);
	// beq cr6,0x8215c934
	if (ctx.cr6.eq) goto loc_8215C934;
	// li r5,1
	ctx.r5.s64 = 1;
loc_8215C87C:
	// clrlwi r8,r11,24
	ctx.r8.u64 = ctx.r11.u32 & 0xFF;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// cmplwi cr6,r8,45
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 45, ctx.xer);
	// bne cr6,0x8215c904
	if (!ctx.cr6.eq) goto loc_8215C904;
	// clrlwi. r9,r27,24
	ctx.r9.u64 = ctx.r27.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x8215c904
	if (ctx.cr0.eq) goto loc_8215C904;
	// lbz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r7.u32 + 0);
	// cmplwi cr6,r10,93
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 93, ctx.xer);
	// beq cr6,0x8215c904
	if (ctx.cr6.eq) goto loc_8215C904;
	// clrlwi r11,r10,24
	ctx.r11.u64 = ctx.r10.u32 & 0xFF;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x8215c8b8
	if (!ctx.cr6.lt) goto loc_8215C8B8;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// b 0x8215c8c0
	goto loc_8215C8C0;
loc_8215C8B8:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// mr r27,r10
	ctx.r27.u64 = ctx.r10.u64;
loc_8215C8C0:
	// clrlwi r8,r11,24
	ctx.r8.u64 = ctx.r11.u32 & 0xFF;
	// clrlwi r11,r27,24
	ctx.r11.u64 = ctx.r27.u32 & 0xFF;
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// bgt cr6,0x8215c8fc
	if (ctx.cr6.gt) goto loc_8215C8FC;
loc_8215C8D0:
	// rlwinm r9,r11,29,3,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// clrlwi r4,r11,29
	ctx.r4.u64 = ctx.r11.u32 & 0x7;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// slw r4,r5,r4
	ctx.r4.u64 = ctx.r4.u8 & 0x20 ? 0 : (ctx.r5.u32 << (ctx.r4.u8 & 0x3F));
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// or r4,r4,r3
	ctx.r4.u64 = ctx.r4.u64 | ctx.r3.u64;
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// stbx r4,r9,r10
	PPC_STORE_U8(ctx.r9.u32 + ctx.r10.u32, ctx.r4.u8);
	// ble cr6,0x8215c8d0
	if (!ctx.cr6.gt) goto loc_8215C8D0;
loc_8215C8FC:
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// b 0x8215c924
	goto loc_8215C924;
loc_8215C904:
	// rlwinm r9,r8,29,3,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 29) & 0x1FFFFFFF;
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// clrlwi r8,r8,29
	ctx.r8.u64 = ctx.r8.u32 & 0x7;
	// mr r27,r11
	ctx.r27.u64 = ctx.r11.u64;
	// slw r11,r5,r8
	ctx.r11.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r5.u32 << (ctx.r8.u8 & 0x3F));
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// or r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 | ctx.r8.u64;
	// stbx r11,r9,r10
	PPC_STORE_U8(ctx.r9.u32 + ctx.r10.u32, ctx.r11.u8);
loc_8215C924:
	// lbz r11,0(r7)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r7.u32 + 0);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,93
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 93, ctx.xer);
	// bne cr6,0x8215c87c
	if (!ctx.cr6.eq) goto loc_8215C87C;
loc_8215C934:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8215d500
	if (ctx.cr6.eq) goto loc_8215D500;
	// cmpwi cr6,r19,123
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 123, ctx.xer);
	// bne cr6,0x8215c948
	if (!ctx.cr6.eq) goto loc_8215C948;
	// stw r7,716(r1)
	PPC_STORE_U32(ctx.r1.u32 + 716, ctx.r7.u32);
loc_8215C948:
	// lwz r30,88(r1)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// addi r14,r14,-1
	ctx.r14.s64 = ctx.r14.s64 + -1;
	// cmpwi cr6,r22,-1
	ctx.cr6.compare<int32_t>(ctx.r22.s32, -1, ctx.xer);
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
	// beq cr6,0x8215c968
	if (ctx.cr6.eq) goto loc_8215C968;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x8215f1a0
	ctx.lr = 0x8215C968;
	sub_8215F1A0(ctx, base);
loc_8215C968:
	// lwz r29,124(r1)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
loc_8215C96C:
	// cmpwi cr6,r17,0
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 0, ctx.xer);
	// beq cr6,0x8215c980
	if (ctx.cr6.eq) goto loc_8215C980;
	// cmpwi cr6,r15,0
	ctx.cr6.compare<int32_t>(ctx.r15.s32, 0, ctx.xer);
	// addi r15,r15,-1
	ctx.r15.s64 = ctx.r15.s64 + -1;
	// beq cr6,0x8215cad8
	if (ctx.cr6.eq) goto loc_8215CAD8;
loc_8215C980:
	// lwz r11,4(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// addi r14,r14,1
	ctx.r14.s64 = ctx.r14.s64 + 1;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r26)
	PPC_STORE_U32(ctx.r26.u32 + 4, ctx.r11.u32);
	// blt 0x8215c9a8
	if (ctx.cr0.lt) goto loc_8215C9A8;
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// lbz r22,0(r11)
	ctx.r22.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// stw r10,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r10.u32);
	// b 0x8215c9b4
	goto loc_8215C9B4;
loc_8215C9A8:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8215d548
	ctx.lr = 0x8215C9B0;
	sub_8215D548(ctx, base);
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
loc_8215C9B4:
	// cmpwi cr6,r22,-1
	ctx.cr6.compare<int32_t>(ctx.r22.s32, -1, ctx.xer);
	// beq cr6,0x8215cac0
	if (ctx.cr6.eq) goto loc_8215CAC0;
	// cmpwi cr6,r19,99
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 99, ctx.xer);
	// beq cr6,0x8215ca18
	if (ctx.cr6.eq) goto loc_8215CA18;
	// cmpwi cr6,r19,115
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 115, ctx.xer);
	// bne cr6,0x8215c9e4
	if (!ctx.cr6.eq) goto loc_8215C9E4;
	// cmpwi cr6,r22,9
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 9, ctx.xer);
	// blt cr6,0x8215c9dc
	if (ctx.cr6.lt) goto loc_8215C9DC;
	// cmpwi cr6,r22,13
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 13, ctx.xer);
	// ble cr6,0x8215cac0
	if (!ctx.cr6.gt) goto loc_8215CAC0;
loc_8215C9DC:
	// cmpwi cr6,r22,32
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 32, ctx.xer);
	// bne cr6,0x8215ca18
	if (!ctx.cr6.eq) goto loc_8215CA18;
loc_8215C9E4:
	// cmpwi cr6,r19,123
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 123, ctx.xer);
	// bne cr6,0x8215cac0
	if (!ctx.cr6.eq) goto loc_8215CAC0;
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// srawi r11,r22,3
	ctx.xer.ca = (ctx.r22.s32 < 0) & ((ctx.r22.u32 & 0x7) != 0);
	ctx.r11.s64 = ctx.r22.s32 >> 3;
	// clrlwi r9,r22,29
	ctx.r9.u64 = ctx.r22.u32 & 0x7;
	// extsb r8,r25
	ctx.r8.s64 = ctx.r25.s8;
	// li r7,1
	ctx.r7.s64 = 1;
	// lbzx r11,r11,r10
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r10.u32);
	// slw r10,r7,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r9.u8 & 0x3F));
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// xor r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 ^ ctx.r8.u64;
	// and. r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 & ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8215cac0
	if (ctx.cr0.eq) goto loc_8215CAC0;
loc_8215CA18:
	// lwz r11,108(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8215cab8
	if (!ctx.cr6.eq) goto loc_8215CAB8;
	// extsb. r11,r24
	ctx.r11.s64 = ctx.r24.s8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8215caa4
	if (ctx.cr0.eq) goto loc_8215CAA4;
	// stb r22,120(r1)
	PPC_STORE_U8(ctx.r1.u32 + 120, ctx.r22.u8);
	// clrlwi r3,r22,24
	ctx.r3.u64 = ctx.r22.u32 & 0xFF;
	// bl 0x82082ca8
	ctx.lr = 0x8215CA38;
	sub_82082CA8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8215ca74
	if (ctx.cr0.eq) goto loc_8215CA74;
	// lwz r11,4(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// addi r14,r14,1
	ctx.r14.s64 = ctx.r14.s64 + 1;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r26)
	PPC_STORE_U32(ctx.r26.u32 + 4, ctx.r11.u32);
	// blt 0x8215ca68
	if (ctx.cr0.lt) goto loc_8215CA68;
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// lbz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// stw r10,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r10.u32);
	// b 0x8215ca70
	goto loc_8215CA70;
loc_8215CA68:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8215d548
	ctx.lr = 0x8215CA70;
	sub_8215D548(ctx, base);
loc_8215CA70:
	// stb r3,121(r1)
	PPC_STORE_U8(ctx.r1.u32 + 121, ctx.r3.u8);
loc_8215CA74:
	// li r10,63
	ctx.r10.s64 = 63;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// sth r10,96(r1)
	PPC_STORE_U16(ctx.r1.u32 + 96, ctx.r10.u16);
	// addi r4,r1,120
	ctx.r4.s64 = ctx.r1.s64 + 120;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r5,172(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 172);
	// bl 0x8215f358
	ctx.lr = 0x8215CA94;
	sub_8215F358(ctx, base);
	// lhz r11,96(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 96);
	// sth r11,0(r30)
	PPC_STORE_U16(ctx.r30.u32 + 0, ctx.r11.u16);
	// addi r30,r30,2
	ctx.r30.s64 = ctx.r30.s64 + 2;
	// b 0x8215cab0
	goto loc_8215CAB0;
loc_8215CAA4:
	// extsb r11,r22
	ctx.r11.s64 = ctx.r22.s8;
	// stb r11,0(r30)
	PPC_STORE_U8(ctx.r30.u32 + 0, ctx.r11.u8);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
loc_8215CAB0:
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r30.u32);
	// b 0x8215c96c
	goto loc_8215C96C;
loc_8215CAB8:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// b 0x8215c96c
	goto loc_8215C96C;
loc_8215CAC0:
	// addi r14,r14,-1
	ctx.r14.s64 = ctx.r14.s64 + -1;
	// cmpwi cr6,r22,-1
	ctx.cr6.compare<int32_t>(ctx.r22.s32, -1, ctx.xer);
	// beq cr6,0x8215cad8
	if (ctx.cr6.eq) goto loc_8215CAD8;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x8215f1a0
	ctx.lr = 0x8215CAD8;
	sub_8215F1A0(ctx, base);
loc_8215CAD8:
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x8215d500
	if (ctx.cr6.eq) goto loc_8215D500;
	// lwz r11,108(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8215d3c8
	if (!ctx.cr6.eq) goto loc_8215D3C8;
	// lwz r11,92(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// cmpwi cr6,r19,99
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 99, ctx.xer);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// beq cr6,0x8215d3c8
	if (ctx.cr6.eq) goto loc_8215D3C8;
	// extsb. r11,r24
	ctx.r11.s64 = ctx.r24.s8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r11,88(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// beq 0x8215cb18
	if (ctx.cr0.eq) goto loc_8215CB18;
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r10,0(r11)
	PPC_STORE_U16(ctx.r11.u32 + 0, ctx.r10.u16);
	// b 0x8215d3c8
	goto loc_8215D3C8;
loc_8215CB18:
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// b 0x8215d3c8
	goto loc_8215D3C8;
loc_8215CB24:
	// li r19,100
	ctx.r19.s64 = 100;
loc_8215CB28:
	// cmpwi cr6,r22,45
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 45, ctx.xer);
	// bne cr6,0x8215cb38
	if (!ctx.cr6.eq) goto loc_8215CB38;
	// li r20,1
	ctx.r20.s64 = 1;
	// b 0x8215cb40
	goto loc_8215CB40;
loc_8215CB38:
	// cmpwi cr6,r22,43
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 43, ctx.xer);
	// bne cr6,0x8215cb8c
	if (!ctx.cr6.eq) goto loc_8215CB8C;
loc_8215CB40:
	// addic. r15,r15,-1
	ctx.xer.ca = ctx.r15.u32 > 0;
	ctx.r15.s64 = ctx.r15.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r15.s32, 0, ctx.xer);
	// bne 0x8215cb58
	if (!ctx.cr0.eq) goto loc_8215CB58;
	// cmpwi cr6,r17,0
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 0, ctx.xer);
	// beq cr6,0x8215cb58
	if (ctx.cr6.eq) goto loc_8215CB58;
	// li r29,1
	ctx.r29.s64 = 1;
	// b 0x8215cb8c
	goto loc_8215CB8C;
loc_8215CB58:
	// lwz r11,4(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// addi r14,r14,1
	ctx.r14.s64 = ctx.r14.s64 + 1;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r26)
	PPC_STORE_U32(ctx.r26.u32 + 4, ctx.r11.u32);
	// blt 0x8215cb80
	if (ctx.cr0.lt) goto loc_8215CB80;
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// lbz r22,0(r11)
	ctx.r22.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// stw r10,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r10.u32);
	// b 0x8215cb8c
	goto loc_8215CB8C;
loc_8215CB80:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8215d548
	ctx.lr = 0x8215CB88;
	sub_8215D548(ctx, base);
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
loc_8215CB8C:
	// cmpwi cr6,r22,48
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 48, ctx.xer);
	// bne cr6,0x8215cce8
	if (!ctx.cr6.eq) goto loc_8215CCE8;
	// lwz r11,4(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// addi r14,r14,1
	ctx.r14.s64 = ctx.r14.s64 + 1;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r26)
	PPC_STORE_U32(ctx.r26.u32 + 4, ctx.r11.u32);
	// blt 0x8215cbbc
	if (ctx.cr0.lt) goto loc_8215CBBC;
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// lbz r22,0(r11)
	ctx.r22.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// stw r10,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r10.u32);
	// b 0x8215cbc8
	goto loc_8215CBC8;
loc_8215CBBC:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8215d548
	ctx.lr = 0x8215CBC4;
	sub_8215D548(ctx, base);
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
loc_8215CBC8:
	// extsb r11,r22
	ctx.r11.s64 = ctx.r22.s8;
	// cmpwi cr6,r11,120
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 120, ctx.xer);
	// beq cr6,0x8215cc28
	if (ctx.cr6.eq) goto loc_8215CC28;
	// cmpwi cr6,r11,88
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 88, ctx.xer);
	// beq cr6,0x8215cc28
	if (ctx.cr6.eq) goto loc_8215CC28;
	// li r18,1
	ctx.r18.s64 = 1;
	// cmpwi cr6,r19,120
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 120, ctx.xer);
	// beq cr6,0x8215cc08
	if (ctx.cr6.eq) goto loc_8215CC08;
	// cmpwi cr6,r17,0
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 0, ctx.xer);
	// beq cr6,0x8215cc00
	if (ctx.cr6.eq) goto loc_8215CC00;
	// addic. r15,r15,-1
	ctx.xer.ca = ctx.r15.u32 > 0;
	ctx.r15.s64 = ctx.r15.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r15.s32, 0, ctx.xer);
	// bne 0x8215cc00
	if (!ctx.cr0.eq) goto loc_8215CC00;
	// addi r11,r29,1
	ctx.r11.s64 = ctx.r29.s64 + 1;
	// extsb r29,r11
	ctx.r29.s64 = ctx.r11.s8;
loc_8215CC00:
	// li r19,111
	ctx.r19.s64 = 111;
	// b 0x8215cce8
	goto loc_8215CCE8;
loc_8215CC08:
	// addi r14,r14,-1
	ctx.r14.s64 = ctx.r14.s64 + -1;
	// cmpwi cr6,r22,-1
	ctx.cr6.compare<int32_t>(ctx.r22.s32, -1, ctx.xer);
	// beq cr6,0x8215cc20
	if (ctx.cr6.eq) goto loc_8215CC20;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x8215f1a0
	ctx.lr = 0x8215CC20;
	sub_8215F1A0(ctx, base);
loc_8215CC20:
	// li r22,48
	ctx.r22.s64 = 48;
	// b 0x8215cce8
	goto loc_8215CCE8;
loc_8215CC28:
	// lwz r11,4(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// addi r14,r14,1
	ctx.r14.s64 = ctx.r14.s64 + 1;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r26)
	PPC_STORE_U32(ctx.r26.u32 + 4, ctx.r11.u32);
	// blt 0x8215cc50
	if (ctx.cr0.lt) goto loc_8215CC50;
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// lbz r22,0(r11)
	ctx.r22.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// stw r10,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r10.u32);
	// b 0x8215cc5c
	goto loc_8215CC5C;
loc_8215CC50:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8215d548
	ctx.lr = 0x8215CC58;
	sub_8215D548(ctx, base);
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
loc_8215CC5C:
	// cmpwi cr6,r17,0
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 0, ctx.xer);
	// beq cr6,0x8215cc78
	if (ctx.cr6.eq) goto loc_8215CC78;
	// addi r15,r15,-2
	ctx.r15.s64 = ctx.r15.s64 + -2;
	// cmpwi cr6,r15,1
	ctx.cr6.compare<int32_t>(ctx.r15.s32, 1, ctx.xer);
	// bge cr6,0x8215cc78
	if (!ctx.cr6.lt) goto loc_8215CC78;
	// addi r11,r29,1
	ctx.r11.s64 = ctx.r29.s64 + 1;
	// extsb r29,r11
	ctx.r29.s64 = ctx.r11.s8;
loc_8215CC78:
	// li r19,120
	ctx.r19.s64 = 120;
	// b 0x8215cce8
	goto loc_8215CCE8;
loc_8215CC80:
	// li r16,1
	ctx.r16.s64 = 1;
loc_8215CC84:
	// cmpwi cr6,r22,45
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 45, ctx.xer);
	// bne cr6,0x8215cc94
	if (!ctx.cr6.eq) goto loc_8215CC94;
	// li r20,1
	ctx.r20.s64 = 1;
	// b 0x8215cc9c
	goto loc_8215CC9C;
loc_8215CC94:
	// cmpwi cr6,r22,43
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 43, ctx.xer);
	// bne cr6,0x8215cce8
	if (!ctx.cr6.eq) goto loc_8215CCE8;
loc_8215CC9C:
	// addic. r15,r15,-1
	ctx.xer.ca = ctx.r15.u32 > 0;
	ctx.r15.s64 = ctx.r15.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r15.s32, 0, ctx.xer);
	// bne 0x8215ccb4
	if (!ctx.cr0.eq) goto loc_8215CCB4;
	// cmpwi cr6,r17,0
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 0, ctx.xer);
	// beq cr6,0x8215ccb4
	if (ctx.cr6.eq) goto loc_8215CCB4;
	// li r29,1
	ctx.r29.s64 = 1;
	// b 0x8215cce8
	goto loc_8215CCE8;
loc_8215CCB4:
	// lwz r11,4(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// addi r14,r14,1
	ctx.r14.s64 = ctx.r14.s64 + 1;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r26)
	PPC_STORE_U32(ctx.r26.u32 + 4, ctx.r11.u32);
	// blt 0x8215ccdc
	if (ctx.cr0.lt) goto loc_8215CCDC;
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// lbz r22,0(r11)
	ctx.r22.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// stw r10,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r10.u32);
	// b 0x8215cce8
	goto loc_8215CCE8;
loc_8215CCDC:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8215d548
	ctx.lr = 0x8215CCE4;
	sub_8215D548(ctx, base);
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
loc_8215CCE8:
	// cmpwi cr6,r21,0
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// extsb. r31,r29
	ctx.r31.s64 = ctx.r29.s8;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq cr6,0x8215ce30
	if (ctx.cr6.eq) goto loc_8215CE30;
	// bne 0x8215ce18
	if (!ctx.cr0.eq) goto loc_8215CE18;
loc_8215CCF8:
	// cmpwi cr6,r19,120
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 120, ctx.xer);
	// beq cr6,0x8215cd44
	if (ctx.cr6.eq) goto loc_8215CD44;
	// cmpwi cr6,r19,112
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 112, ctx.xer);
	// beq cr6,0x8215cd44
	if (ctx.cr6.eq) goto loc_8215CD44;
	// clrlwi r3,r22,24
	ctx.r3.u64 = ctx.r22.u32 & 0xFF;
	// bl 0x82085498
	ctx.lr = 0x8215CD10;
	sub_82085498(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8215cd80
	if (ctx.cr0.eq) goto loc_8215CD80;
	// cmpwi cr6,r19,111
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 111, ctx.xer);
	// bne cr6,0x8215cd38
	if (!ctx.cr6.eq) goto loc_8215CD38;
	// cmpwi cr6,r22,56
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 56, ctx.xer);
	// bge cr6,0x8215cd80
	if (!ctx.cr6.lt) goto loc_8215CD80;
	// ld r11,112(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// rldicr r11,r11,3,60
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 3) & 0xFFFFFFFFFFFFFFF8;
loc_8215CD30:
	// std r11,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// b 0x8215cd88
	goto loc_8215CD88;
loc_8215CD38:
	// ld r11,112(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// mulli r11,r11,10
	ctx.r11.s64 = ctx.r11.s64 * 10;
	// b 0x8215cd30
	goto loc_8215CD30;
loc_8215CD44:
	// clrlwi r30,r22,24
	ctx.r30.u64 = ctx.r22.u32 & 0xFF;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820854b8
	ctx.lr = 0x8215CD50;
	sub_820854B8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8215cd80
	if (ctx.cr0.eq) goto loc_8215CD80;
	// ld r11,112(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// rldicr r11,r11,4,59
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 4) & 0xFFFFFFFFFFFFFFF0;
	// std r11,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// bl 0x82085498
	ctx.lr = 0x8215CD6C;
	sub_82085498(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8215cd88
	if (!ctx.cr0.eq) goto loc_8215CD88;
	// rlwinm r11,r22,0,27,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// addi r22,r11,-7
	ctx.r22.s64 = ctx.r11.s64 + -7;
	// b 0x8215cd88
	goto loc_8215CD88;
loc_8215CD80:
	// addi r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 1;
	// extsb r29,r11
	ctx.r29.s64 = ctx.r11.s8;
loc_8215CD88:
	// extsb. r11,r29
	ctx.r11.s64 = ctx.r29.s8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8215cdf8
	if (!ctx.cr0.eq) goto loc_8215CDF8;
	// addi r11,r22,-48
	ctx.r11.s64 = ctx.r22.s64 + -48;
	// ld r10,112(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// cmpwi cr6,r17,0
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 0, ctx.xer);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// std r11,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// beq cr6,0x8215cdc0
	if (ctx.cr6.eq) goto loc_8215CDC0;
	// addic. r15,r15,-1
	ctx.xer.ca = ctx.r15.u32 > 0;
	ctx.r15.s64 = ctx.r15.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r15.s32, 0, ctx.xer);
	// bne 0x8215cdc0
	if (!ctx.cr0.eq) goto loc_8215CDC0;
	// li r29,1
	ctx.r29.s64 = 1;
	// b 0x8215ce10
	goto loc_8215CE10;
loc_8215CDC0:
	// lwz r11,4(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// addi r14,r14,1
	ctx.r14.s64 = ctx.r14.s64 + 1;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r26)
	PPC_STORE_U32(ctx.r26.u32 + 4, ctx.r11.u32);
	// blt 0x8215cde8
	if (ctx.cr0.lt) goto loc_8215CDE8;
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// lbz r22,0(r11)
	ctx.r22.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// stw r10,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r10.u32);
	// b 0x8215ce10
	goto loc_8215CE10;
loc_8215CDE8:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8215d548
	ctx.lr = 0x8215CDF0;
	sub_8215D548(ctx, base);
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
	// b 0x8215ce10
	goto loc_8215CE10;
loc_8215CDF8:
	// addi r14,r14,-1
	ctx.r14.s64 = ctx.r14.s64 + -1;
	// cmpwi cr6,r22,-1
	ctx.cr6.compare<int32_t>(ctx.r22.s32, -1, ctx.xer);
	// beq cr6,0x8215ce10
	if (ctx.cr6.eq) goto loc_8215CE10;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x8215f1a0
	ctx.lr = 0x8215CE10;
	sub_8215F1A0(ctx, base);
loc_8215CE10:
	// extsb. r31,r29
	ctx.r31.s64 = ctx.r29.s8;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x8215ccf8
	if (ctx.cr0.eq) goto loc_8215CCF8;
loc_8215CE18:
	// extsb. r11,r20
	ctx.r11.s64 = ctx.r20.s8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8215cf40
	if (ctx.cr0.eq) goto loc_8215CF40;
	// ld r11,112(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
	// std r11,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// b 0x8215cf40
	goto loc_8215CF40;
loc_8215CE30:
	// bne 0x8215cf34
	if (!ctx.cr0.eq) goto loc_8215CF34;
loc_8215CE34:
	// cmpwi cr6,r19,120
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 120, ctx.xer);
	// beq cr6,0x8215ce74
	if (ctx.cr6.eq) goto loc_8215CE74;
	// cmpwi cr6,r19,112
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 112, ctx.xer);
	// beq cr6,0x8215ce74
	if (ctx.cr6.eq) goto loc_8215CE74;
	// clrlwi r3,r22,24
	ctx.r3.u64 = ctx.r22.u32 & 0xFF;
	// bl 0x82085498
	ctx.lr = 0x8215CE4C;
	sub_82085498(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8215cea8
	if (ctx.cr0.eq) goto loc_8215CEA8;
	// cmpwi cr6,r19,111
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 111, ctx.xer);
	// bne cr6,0x8215ce6c
	if (!ctx.cr6.eq) goto loc_8215CE6C;
	// cmpwi cr6,r22,56
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 56, ctx.xer);
	// bge cr6,0x8215cea8
	if (!ctx.cr6.lt) goto loc_8215CEA8;
	// rlwinm r23,r23,3,0,28
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 3) & 0xFFFFFFF8;
	// b 0x8215ceb0
	goto loc_8215CEB0;
loc_8215CE6C:
	// mulli r23,r23,10
	ctx.r23.s64 = ctx.r23.s64 * 10;
	// b 0x8215ceb0
	goto loc_8215CEB0;
loc_8215CE74:
	// clrlwi r30,r22,24
	ctx.r30.u64 = ctx.r22.u32 & 0xFF;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820854b8
	ctx.lr = 0x8215CE80;
	sub_820854B8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8215cea8
	if (ctx.cr0.eq) goto loc_8215CEA8;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// rlwinm r23,r23,4,0,27
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 4) & 0xFFFFFFF0;
	// bl 0x82085498
	ctx.lr = 0x8215CE94;
	sub_82085498(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8215ceb0
	if (!ctx.cr0.eq) goto loc_8215CEB0;
	// rlwinm r11,r22,0,27,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// addi r22,r11,-7
	ctx.r22.s64 = ctx.r11.s64 + -7;
	// b 0x8215ceb0
	goto loc_8215CEB0;
loc_8215CEA8:
	// addi r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 1;
	// extsb r29,r11
	ctx.r29.s64 = ctx.r11.s8;
loc_8215CEB0:
	// extsb. r11,r29
	ctx.r11.s64 = ctx.r29.s8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8215cf14
	if (!ctx.cr0.eq) goto loc_8215CF14;
	// add r11,r23,r22
	ctx.r11.u64 = ctx.r23.u64 + ctx.r22.u64;
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// addi r23,r11,-48
	ctx.r23.s64 = ctx.r11.s64 + -48;
	// cmpwi cr6,r17,0
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 0, ctx.xer);
	// beq cr6,0x8215cedc
	if (ctx.cr6.eq) goto loc_8215CEDC;
	// addic. r15,r15,-1
	ctx.xer.ca = ctx.r15.u32 > 0;
	ctx.r15.s64 = ctx.r15.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r15.s32, 0, ctx.xer);
	// bne 0x8215cedc
	if (!ctx.cr0.eq) goto loc_8215CEDC;
	// li r29,1
	ctx.r29.s64 = 1;
	// b 0x8215cf2c
	goto loc_8215CF2C;
loc_8215CEDC:
	// lwz r11,4(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// addi r14,r14,1
	ctx.r14.s64 = ctx.r14.s64 + 1;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r26)
	PPC_STORE_U32(ctx.r26.u32 + 4, ctx.r11.u32);
	// blt 0x8215cf04
	if (ctx.cr0.lt) goto loc_8215CF04;
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// lbz r22,0(r11)
	ctx.r22.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// stw r10,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r10.u32);
	// b 0x8215cf2c
	goto loc_8215CF2C;
loc_8215CF04:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8215d548
	ctx.lr = 0x8215CF0C;
	sub_8215D548(ctx, base);
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
	// b 0x8215cf2c
	goto loc_8215CF2C;
loc_8215CF14:
	// addi r14,r14,-1
	ctx.r14.s64 = ctx.r14.s64 + -1;
	// cmpwi cr6,r22,-1
	ctx.cr6.compare<int32_t>(ctx.r22.s32, -1, ctx.xer);
	// beq cr6,0x8215cf2c
	if (ctx.cr6.eq) goto loc_8215CF2C;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x8215f1a0
	ctx.lr = 0x8215CF2C;
	sub_8215F1A0(ctx, base);
loc_8215CF2C:
	// extsb. r31,r29
	ctx.r31.s64 = ctx.r29.s8;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x8215ce34
	if (ctx.cr0.eq) goto loc_8215CE34;
loc_8215CF34:
	// extsb. r11,r20
	ctx.r11.s64 = ctx.r20.s8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8215cf40
	if (ctx.cr0.eq) goto loc_8215CF40;
	// neg r23,r23
	ctx.r23.s64 = -ctx.r23.s64;
loc_8215CF40:
	// addi r11,r19,-70
	ctx.r11.s64 = ctx.r19.s64 + -70;
	// subfic r11,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r11.s64 = 0 - ctx.r11.s64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r11,r18
	ctx.r11.u64 = ctx.r11.u64 & ctx.r18.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8215d500
	if (ctx.cr6.eq) goto loc_8215D500;
	// lwz r11,108(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8215d3c8
	if (!ctx.cr6.eq) goto loc_8215D3C8;
	// lwz r11,92(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// b 0x8215cf90
	goto loc_8215CF90;
loc_8215CF74:
	// lwz r11,108(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// mr r23,r14
	ctx.r23.u64 = ctx.r14.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8215d3c8
	if (!ctx.cr6.eq) goto loc_8215D3C8;
	// bl 0x8207bda0
	ctx.lr = 0x8215CF88;
	sub_8207BDA0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8215d3c8
	if (ctx.cr0.eq) goto loc_8215D3C8;
loc_8215CF90:
	// cmpwi cr6,r21,0
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// beq cr6,0x8215cfa8
	if (ctx.cr6.eq) goto loc_8215CFA8;
	// ld r11,112(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// std r11,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r11.u64);
	// b 0x8215d3c8
	goto loc_8215D3C8;
loc_8215CFA8:
	// extsb. r11,r16
	ctx.r11.s64 = ctx.r16.s8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r11,88(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// beq 0x8215cfbc
	if (ctx.cr0.eq) goto loc_8215CFBC;
	// stw r23,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r23.u32);
	// b 0x8215d3c8
	goto loc_8215D3C8;
loc_8215CFBC:
	// sth r23,0(r11)
	PPC_STORE_U16(ctx.r11.u32 + 0, ctx.r23.u16);
	// b 0x8215d3c8
	goto loc_8215D3C8;
loc_8215CFC4:
	// li r30,0
	ctx.r30.s64 = 0;
	// cmpwi cr6,r22,45
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 45, ctx.xer);
	// bne cr6,0x8215cfe4
	if (!ctx.cr6.eq) goto loc_8215CFE4;
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r10,45
	ctx.r10.s64 = 45;
	// li r30,1
	ctx.r30.s64 = 1;
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// b 0x8215cfec
	goto loc_8215CFEC;
loc_8215CFE4:
	// cmpwi cr6,r22,43
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 43, ctx.xer);
	// bne cr6,0x8215d024
	if (!ctx.cr6.eq) goto loc_8215D024;
loc_8215CFEC:
	// lwz r11,4(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// addi r15,r15,-1
	ctx.r15.s64 = ctx.r15.s64 + -1;
	// addi r14,r14,1
	ctx.r14.s64 = ctx.r14.s64 + 1;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r26)
	PPC_STORE_U32(ctx.r26.u32 + 4, ctx.r11.u32);
	// blt 0x8215d018
	if (ctx.cr0.lt) goto loc_8215D018;
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// lbz r22,0(r11)
	ctx.r22.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// stw r10,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r10.u32);
	// b 0x8215d024
	goto loc_8215D024;
loc_8215D018:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8215d548
	ctx.lr = 0x8215D020;
	sub_8215D548(ctx, base);
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
loc_8215D024:
	// cmpwi cr6,r17,0
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 0, ctx.xer);
	// bne cr6,0x8215d0a4
	if (!ctx.cr6.eq) goto loc_8215D0A4;
	// li r15,-1
	ctx.r15.s64 = -1;
	// b 0x8215d0a4
	goto loc_8215D0A4;
loc_8215D034:
	// cmpwi cr6,r15,0
	ctx.cr6.compare<int32_t>(ctx.r15.s32, 0, ctx.xer);
	// addi r15,r15,-1
	ctx.r15.s64 = ctx.r15.s64 + -1;
	// beq cr6,0x8215d0b8
	if (ctx.cr6.eq) goto loc_8215D0B8;
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r7,r1,100
	ctx.r7.s64 = ctx.r1.s64 + 100;
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// stbx r31,r30,r11
	PPC_STORE_U8(ctx.r30.u32 + ctx.r11.u32, ctx.r31.u8);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8215c288
	ctx.lr = 0x8215D068;
	sub_8215C288(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8215d500
	if (ctx.cr0.eq) goto loc_8215D500;
	// lwz r11,4(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// addi r14,r14,1
	ctx.r14.s64 = ctx.r14.s64 + 1;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r26)
	PPC_STORE_U32(ctx.r26.u32 + 4, ctx.r11.u32);
	// blt 0x8215d098
	if (ctx.cr0.lt) goto loc_8215D098;
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// lbz r22,0(r11)
	ctx.r22.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// stw r10,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r10.u32);
	// b 0x8215d0a4
	goto loc_8215D0A4;
loc_8215D098:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8215d548
	ctx.lr = 0x8215D0A0;
	sub_8215D548(ctx, base);
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
loc_8215D0A4:
	// clrlwi r31,r22,24
	ctx.r31.u64 = ctx.r22.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82085498
	ctx.lr = 0x8215D0B0;
	sub_82085498(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8215d034
	if (!ctx.cr0.eq) goto loc_8215D034;
loc_8215D0B8:
	// lwz r11,124(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// extsb r10,r31
	ctx.r10.s64 = ctx.r31.s8;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,188(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 188);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r31,0(r11)
	ctx.r31.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// extsb r11,r31
	ctx.r11.s64 = ctx.r31.s8;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x8215d1d0
	if (!ctx.cr6.eq) goto loc_8215D1D0;
	// cmpwi cr6,r15,0
	ctx.cr6.compare<int32_t>(ctx.r15.s32, 0, ctx.xer);
	// addi r15,r15,-1
	ctx.r15.s64 = ctx.r15.s64 + -1;
	// beq cr6,0x8215d1d0
	if (ctx.cr6.eq) goto loc_8215D1D0;
	// lwz r11,4(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// addi r14,r14,1
	ctx.r14.s64 = ctx.r14.s64 + 1;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r26)
	PPC_STORE_U32(ctx.r26.u32 + 4, ctx.r11.u32);
	// blt 0x8215d110
	if (ctx.cr0.lt) goto loc_8215D110;
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// lbz r22,0(r11)
	ctx.r22.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// stw r10,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r10.u32);
	// b 0x8215d11c
	goto loc_8215D11C;
loc_8215D110:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8215d548
	ctx.lr = 0x8215D118;
	sub_8215D548(ctx, base);
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
loc_8215D11C:
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r7,r1,100
	ctx.r7.s64 = ctx.r1.s64 + 100;
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// stbx r31,r30,r11
	PPC_STORE_U8(ctx.r30.u32 + ctx.r11.u32, ctx.r31.u8);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8215c288
	ctx.lr = 0x8215D140;
	sub_8215C288(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8215d500
	if (ctx.cr0.eq) goto loc_8215D500;
	// b 0x8215d1bc
	goto loc_8215D1BC;
loc_8215D14C:
	// cmpwi cr6,r15,0
	ctx.cr6.compare<int32_t>(ctx.r15.s32, 0, ctx.xer);
	// addi r15,r15,-1
	ctx.r15.s64 = ctx.r15.s64 + -1;
	// beq cr6,0x8215d1d0
	if (ctx.cr6.eq) goto loc_8215D1D0;
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r7,r1,100
	ctx.r7.s64 = ctx.r1.s64 + 100;
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// stbx r31,r30,r11
	PPC_STORE_U8(ctx.r30.u32 + ctx.r11.u32, ctx.r31.u8);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8215c288
	ctx.lr = 0x8215D180;
	sub_8215C288(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8215d500
	if (ctx.cr0.eq) goto loc_8215D500;
	// lwz r11,4(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// addi r14,r14,1
	ctx.r14.s64 = ctx.r14.s64 + 1;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r26)
	PPC_STORE_U32(ctx.r26.u32 + 4, ctx.r11.u32);
	// blt 0x8215d1b0
	if (ctx.cr0.lt) goto loc_8215D1B0;
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// lbz r22,0(r11)
	ctx.r22.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// stw r10,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r10.u32);
	// b 0x8215d1bc
	goto loc_8215D1BC;
loc_8215D1B0:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8215d548
	ctx.lr = 0x8215D1B8;
	sub_8215D548(ctx, base);
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
loc_8215D1BC:
	// clrlwi r31,r22,24
	ctx.r31.u64 = ctx.r22.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82085498
	ctx.lr = 0x8215D1C8;
	sub_82085498(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8215d14c
	if (!ctx.cr0.eq) goto loc_8215D14C;
loc_8215D1D0:
	// cmpwi cr6,r18,0
	ctx.cr6.compare<int32_t>(ctx.r18.s32, 0, ctx.xer);
	// beq cr6,0x8215d334
	if (ctx.cr6.eq) goto loc_8215D334;
	// cmpwi cr6,r22,101
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 101, ctx.xer);
	// beq cr6,0x8215d1e8
	if (ctx.cr6.eq) goto loc_8215D1E8;
	// cmpwi cr6,r22,69
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 69, ctx.xer);
	// bne cr6,0x8215d334
	if (!ctx.cr6.eq) goto loc_8215D334;
loc_8215D1E8:
	// cmpwi cr6,r15,0
	ctx.cr6.compare<int32_t>(ctx.r15.s32, 0, ctx.xer);
	// addi r29,r15,-1
	ctx.r29.s64 = ctx.r15.s64 + -1;
	// beq cr6,0x8215d334
	if (ctx.cr6.eq) goto loc_8215D334;
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r10,101
	ctx.r10.s64 = 101;
	// addi r7,r1,100
	ctx.r7.s64 = ctx.r1.s64 + 100;
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// stbx r10,r30,r11
	PPC_STORE_U8(ctx.r30.u32 + ctx.r11.u32, ctx.r10.u8);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8215c288
	ctx.lr = 0x8215D21C;
	sub_8215C288(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8215d500
	if (ctx.cr0.eq) goto loc_8215D500;
	// lwz r11,4(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// addi r14,r14,1
	ctx.r14.s64 = ctx.r14.s64 + 1;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r26)
	PPC_STORE_U32(ctx.r26.u32 + 4, ctx.r11.u32);
	// blt 0x8215d24c
	if (ctx.cr0.lt) goto loc_8215D24C;
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// lbz r22,0(r11)
	ctx.r22.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// stw r10,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r10.u32);
	// b 0x8215d258
	goto loc_8215D258;
loc_8215D24C:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8215d548
	ctx.lr = 0x8215D254;
	sub_8215D548(ctx, base);
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
loc_8215D258:
	// cmpwi cr6,r22,45
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 45, ctx.xer);
	// bne cr6,0x8215d294
	if (!ctx.cr6.eq) goto loc_8215D294;
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r10,45
	ctx.r10.s64 = 45;
	// addi r7,r1,100
	ctx.r7.s64 = ctx.r1.s64 + 100;
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// stbx r10,r30,r11
	PPC_STORE_U8(ctx.r30.u32 + ctx.r11.u32, ctx.r10.u8);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8215c288
	ctx.lr = 0x8215D288;
	sub_8215C288(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8215d500
	if (ctx.cr0.eq) goto loc_8215D500;
	// b 0x8215d29c
	goto loc_8215D29C;
loc_8215D294:
	// cmpwi cr6,r22,43
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 43, ctx.xer);
	// bne cr6,0x8215d320
	if (!ctx.cr6.eq) goto loc_8215D320;
loc_8215D29C:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r29,r29,-1
	ctx.r29.s64 = ctx.r29.s64 + -1;
	// bne cr6,0x8215d2ec
	if (!ctx.cr6.eq) goto loc_8215D2EC;
	// li r29,0
	ctx.r29.s64 = 0;
	// b 0x8215d320
	goto loc_8215D320;
loc_8215D2B0:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r29,r29,-1
	ctx.r29.s64 = ctx.r29.s64 + -1;
	// beq cr6,0x8215d334
	if (ctx.cr6.eq) goto loc_8215D334;
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r7,r1,100
	ctx.r7.s64 = ctx.r1.s64 + 100;
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// stbx r31,r30,r11
	PPC_STORE_U8(ctx.r30.u32 + ctx.r11.u32, ctx.r31.u8);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8215c288
	ctx.lr = 0x8215D2E4;
	sub_8215C288(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8215d500
	if (ctx.cr0.eq) goto loc_8215D500;
loc_8215D2EC:
	// lwz r11,4(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// addi r14,r14,1
	ctx.r14.s64 = ctx.r14.s64 + 1;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r26)
	PPC_STORE_U32(ctx.r26.u32 + 4, ctx.r11.u32);
	// blt 0x8215d314
	if (ctx.cr0.lt) goto loc_8215D314;
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// lbz r22,0(r11)
	ctx.r22.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// stw r10,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r10.u32);
	// b 0x8215d320
	goto loc_8215D320;
loc_8215D314:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8215d548
	ctx.lr = 0x8215D31C;
	sub_8215D548(ctx, base);
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
loc_8215D320:
	// clrlwi r31,r22,24
	ctx.r31.u64 = ctx.r22.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82085498
	ctx.lr = 0x8215D32C;
	sub_82085498(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8215d2b0
	if (!ctx.cr0.eq) goto loc_8215D2B0;
loc_8215D334:
	// addi r14,r14,-1
	ctx.r14.s64 = ctx.r14.s64 + -1;
	// cmpwi cr6,r22,-1
	ctx.cr6.compare<int32_t>(ctx.r22.s32, -1, ctx.xer);
	// beq cr6,0x8215d34c
	if (ctx.cr6.eq) goto loc_8215D34C;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x8215f1a0
	ctx.lr = 0x8215D34C;
	sub_8215F1A0(ctx, base);
loc_8215D34C:
	// cmpwi cr6,r18,0
	ctx.cr6.compare<int32_t>(ctx.r18.s32, 0, ctx.xer);
	// beq cr6,0x8215d500
	if (ctx.cr6.eq) goto loc_8215D500;
	// lwz r11,108(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8215d3c8
	if (!ctx.cr6.eq) goto loc_8215D3C8;
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r9,128(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// extsb r11,r16
	ctx.r11.s64 = ctx.r16.s8;
	// lwz r8,92(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// addi r3,r11,-1
	ctx.r3.s64 = ctx.r11.s64 + -1;
	// lwz r6,124(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// addi r11,r8,1
	ctx.r11.s64 = ctx.r8.s64 + 1;
	// lwz r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// stbx r10,r30,r5
	PPC_STORE_U8(ctx.r30.u32 + ctx.r5.u32, ctx.r10.u8);
	// lwz r10,28(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// bctrl 
	ctx.lr = 0x8215D398;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x8215d3c8
	goto loc_8215D3C8;
loc_8215D39C:
	// lbz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpw cr6,r11,r22
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r22.s32, ctx.xer);
	// bne cr6,0x8215d4ec
	if (!ctx.cr6.eq) goto loc_8215D4EC;
	// lbz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lwz r10,108(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// bne cr6,0x8215d3c8
	if (!ctx.cr6.eq) goto loc_8215D3C8;
	// lwz r11,132(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// stw r11,732(r1)
	PPC_STORE_U32(ctx.r1.u32 + 732, ctx.r11.u32);
loc_8215D3C8:
	// lbz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lwz r10,716(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 716);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// stw r10,716(r1)
	PPC_STORE_U32(ctx.r1.u32 + 716, ctx.r10.u32);
	// rotlwi r19,r10,0
	ctx.r19.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// b 0x8215d4a4
	goto loc_8215D4A4;
loc_8215D3E8:
	// cmplwi cr6,r11,37
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 37, ctx.xer);
	// bne cr6,0x8215d404
	if (!ctx.cr6.eq) goto loc_8215D404;
	// lbz r10,1(r19)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r19.u32 + 1);
	// addi r11,r19,1
	ctx.r11.s64 = ctx.r19.s64 + 1;
	// cmplwi cr6,r10,37
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 37, ctx.xer);
	// bne cr6,0x8215d404
	if (!ctx.cr6.eq) goto loc_8215D404;
	// mr r19,r11
	ctx.r19.u64 = ctx.r11.u64;
loc_8215D404:
	// lwz r11,4(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// addi r14,r14,1
	ctx.r14.s64 = ctx.r14.s64 + 1;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r26)
	PPC_STORE_U32(ctx.r26.u32 + 4, ctx.r11.u32);
	// blt 0x8215d42c
	if (ctx.cr0.lt) goto loc_8215D42C;
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// lbz r22,0(r11)
	ctx.r22.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// stw r10,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r10.u32);
	// b 0x8215d438
	goto loc_8215D438;
loc_8215D42C:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8215d548
	ctx.lr = 0x8215D434;
	sub_8215D548(ctx, base);
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
loc_8215D438:
	// lbz r11,0(r19)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r19.u32 + 0);
	// addi r19,r19,1
	ctx.r19.s64 = ctx.r19.s64 + 1;
	// stw r19,716(r1)
	PPC_STORE_U32(ctx.r1.u32 + 716, ctx.r19.u32);
	// cmpw cr6,r11,r22
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r22.s32, ctx.xer);
	// bne cr6,0x8215d4ec
	if (!ctx.cr6.eq) goto loc_8215D4EC;
	// clrlwi r3,r22,24
	ctx.r3.u64 = ctx.r22.u32 & 0xFF;
	// bl 0x82082ca8
	ctx.lr = 0x8215D454;
	sub_82082CA8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8215d4a4
	if (ctx.cr0.eq) goto loc_8215D4A4;
	// lwz r11,4(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// addi r31,r14,1
	ctx.r31.s64 = ctx.r14.s64 + 1;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r26)
	PPC_STORE_U32(ctx.r26.u32 + 4, ctx.r11.u32);
	// blt 0x8215d484
	if (ctx.cr0.lt) goto loc_8215D484;
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// lbz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// stw r10,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r10.u32);
	// b 0x8215d48c
	goto loc_8215D48C;
loc_8215D484:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8215d548
	ctx.lr = 0x8215D48C;
	sub_8215D548(ctx, base);
loc_8215D48C:
	// lbz r11,0(r19)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r19.u32 + 0);
	// addi r19,r19,1
	ctx.r19.s64 = ctx.r19.s64 + 1;
	// stw r19,716(r1)
	PPC_STORE_U32(ctx.r1.u32 + 716, ctx.r19.u32);
	// cmpw cr6,r11,r3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r3.s32, ctx.xer);
	// bne cr6,0x8215d4dc
	if (!ctx.cr6.eq) goto loc_8215D4DC;
	// addi r14,r31,-1
	ctx.r14.s64 = ctx.r31.s64 + -1;
loc_8215D4A4:
	// cmpwi cr6,r22,-1
	ctx.cr6.compare<int32_t>(ctx.r22.s32, -1, ctx.xer);
	// bne cr6,0x8215d4cc
	if (!ctx.cr6.eq) goto loc_8215D4CC;
	// lbz r11,0(r19)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r19.u32 + 0);
	// cmplwi cr6,r11,37
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 37, ctx.xer);
	// bne cr6,0x8215d500
	if (!ctx.cr6.eq) goto loc_8215D500;
	// lwz r11,716(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 716);
	// lbz r11,1(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// cmplwi cr6,r11,110
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 110, ctx.xer);
	// bne cr6,0x8215d500
	if (!ctx.cr6.eq) goto loc_8215D500;
	// lwz r19,716(r1)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 716);
loc_8215D4CC:
	// lbz r3,0(r19)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r19.u32 + 0);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8215c46c
	if (!ctx.cr0.eq) goto loc_8215C46C;
	// b 0x8215d500
	goto loc_8215D500;
loc_8215D4DC:
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8215d4ec
	if (ctx.cr6.eq) goto loc_8215D4EC;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x8215f1a0
	ctx.lr = 0x8215D4EC;
	sub_8215F1A0(ctx, base);
loc_8215D4EC:
	// cmpwi cr6,r22,-1
	ctx.cr6.compare<int32_t>(ctx.r22.s32, -1, ctx.xer);
	// beq cr6,0x8215d500
	if (ctx.cr6.eq) goto loc_8215D500;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x8215f1a0
	ctx.lr = 0x8215D500;
	sub_8215F1A0(ctx, base);
loc_8215D500:
	// lwz r11,100(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8215d514
	if (!ctx.cr6.eq) goto loc_8215D514;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8207c068
	ctx.lr = 0x8215D514;
	sub_8207C068(ctx, base);
loc_8215D514:
	// cmpwi cr6,r22,-1
	ctx.cr6.compare<int32_t>(ctx.r22.s32, -1, ctx.xer);
	// bne cr6,0x8215d538
	if (!ctx.cr6.eq) goto loc_8215D538;
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8215d53c
	if (!ctx.cr6.eq) goto loc_8215D53C;
	// lbz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8215d53c
	if (!ctx.cr0.eq) goto loc_8215D53C;
	// b 0x8215c38c
	goto loc_8215C38C;
loc_8215D538:
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
loc_8215D53C:
	// addi r1,r1,688
	ctx.r1.s64 = ctx.r1.s64 + 688;
	// b 0x8207c9a0
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215D544"))) PPC_WEAK_FUNC(sub_8215D544);
PPC_FUNC_IMPL(__imp__sub_8215D544) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8215D548"))) PPC_WEAK_FUNC(sub_8215D548);
PPC_FUNC_IMPL(__imp__sub_8215D548) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8215D550;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8215d588
	if (!ctx.cr6.eq) goto loc_8215D588;
	// bl 0x8207d4d8
	ctx.lr = 0x8215D564;
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
	ctx.lr = 0x8215D584;
	sub_8207D940(ctx, base);
	// b 0x8215d6fc
	goto loc_8215D6FC;
loc_8215D588:
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// andi. r10,r11,131
	ctx.r10.u64 = ctx.r11.u64 & 131;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// cmpwi r10,0
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8215d6fc
	if (ctx.cr0.eq) goto loc_8215D6FC;
	// rlwinm. r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8215d6fc
	if (!ctx.cr0.eq) goto loc_8215D6FC;
	// rlwinm. r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8215d5b0
	if (ctx.cr0.eq) goto loc_8215D5B0;
	// ori r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 | 32;
	// b 0x8215d6f8
	goto loc_8215D6F8;
loc_8215D5B0:
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// andi. r10,r11,268
	ctx.r10.u64 = ctx.r11.u64 & 268;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// cmpwi r10,0
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8215d5d0
	if (!ctx.cr0.eq) goto loc_8215D5D0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820829f8
	ctx.lr = 0x8215D5CC;
	sub_820829F8(ctx, base);
	// b 0x8215d5d8
	goto loc_8215D5D8;
loc_8215D5D0:
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_8215D5D8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r30,8(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r29,24(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x820809e8
	ctx.lr = 0x8215D5E8;
	sub_820809E8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x8215dd40
	ctx.lr = 0x8215D5F4;
	sub_8215DD40(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// stw r3,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// beq 0x8215d6d8
	if (ctx.cr0.eq) goto loc_8215D6D8;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8215d6d8
	if (ctx.cr6.eq) goto loc_8215D6D8;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// andi. r11,r11,130
	ctx.r11.u64 = ctx.r11.u64 & 130;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8215d690
	if (!ctx.cr0.eq) goto loc_8215D690;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820809e8
	ctx.lr = 0x8215D620;
	sub_820809E8(ctx, base);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8215d66c
	if (ctx.cr6.eq) goto loc_8215D66C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820809e8
	ctx.lr = 0x8215D630;
	sub_820809E8(ctx, base);
	// cmpwi cr6,r3,-2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -2, ctx.xer);
	// beq cr6,0x8215d66c
	if (ctx.cr6.eq) goto loc_8215D66C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820809e8
	ctx.lr = 0x8215D640;
	sub_820809E8(ctx, base);
	// srawi r11,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 5;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rlwinm r29,r11,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r30,r10,-23360
	ctx.r30.s64 = ctx.r10.s64 + -23360;
	// bl 0x820809e8
	ctx.lr = 0x8215D658;
	sub_820809E8(ctx, base);
	// clrlwi r10,r3,27
	ctx.r10.u64 = ctx.r3.u32 & 0x1F;
	// lwzx r11,r29,r30
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r30.u32);
	// mulli r10,r10,72
	ctx.r10.s64 = ctx.r10.s64 * 72;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// b 0x8215d674
	goto loc_8215D674;
loc_8215D66C:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,2456
	ctx.r11.s64 = ctx.r11.s64 + 2456;
loc_8215D674:
	// lbz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// andi. r11,r11,130
	ctx.r11.u64 = ctx.r11.u64 & 130;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmplwi cr6,r11,130
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 130, ctx.xer);
	// bne cr6,0x8215d690
	if (!ctx.cr6.eq) goto loc_8215D690;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// ori r11,r11,8192
	ctx.r11.u64 = ctx.r11.u64 | 8192;
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_8215D690:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmpwi cr6,r11,512
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 512, ctx.xer);
	// bne cr6,0x8215d6b8
	if (!ctx.cr6.eq) goto loc_8215D6B8;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// rlwinm. r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8215d6b8
	if (ctx.cr0.eq) goto loc_8215D6B8;
	// rlwinm. r11,r11,0,21,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x400;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8215d6b8
	if (!ctx.cr0.eq) goto loc_8215D6B8;
	// li r11,4096
	ctx.r11.s64 = 4096;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
loc_8215D6B8:
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// lbz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// b 0x8215d700
	goto loc_8215D700;
loc_8215D6D8:
	// subfic r11,r3,0
	ctx.xer.ca = ctx.r3.u32 <= 0;
	ctx.r11.s64 = 0 - ctx.r3.s64;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r9,0
	ctx.r9.s64 = 0;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// rlwinm r11,r11,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
loc_8215D6F8:
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_8215D6FC:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_8215D700:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215D708"))) PPC_WEAK_FUNC(sub_8215D708);
PPC_FUNC_IMPL(__imp__sub_8215D708) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c960
	ctx.lr = 0x8215D710;
	__savegprlr_18(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r21,r3
	ctx.r21.u64 = ctx.r3.u64;
	// mr r19,r4
	ctx.r19.u64 = ctx.r4.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// li r18,-2
	ctx.r18.s64 = -2;
	// mr r20,r5
	ctx.r20.u64 = ctx.r5.u64;
	// cmpwi cr6,r3,-2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -2, ctx.xer);
	// bne cr6,0x8215d754
	if (!ctx.cr6.eq) goto loc_8215D754;
	// bl 0x8207d510
	ctx.lr = 0x8215D734;
	sub_8207D510(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d4d8
	ctx.lr = 0x8215D740;
	sub_8207D4D8(ctx, base);
	// li r10,9
	ctx.r10.s64 = 9;
loc_8215D744:
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// b 0x8215dd2c
	goto loc_8215DD2C;
loc_8215D754:
	// cmpwi cr6,r21,0
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// blt cr6,0x8215d76c
	if (ctx.cr6.lt) goto loc_8215D76C;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-23372(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -23372);
	// cmplw cr6,r21,r11
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8215d7a4
	if (ctx.cr6.lt) goto loc_8215D7A4;
loc_8215D76C:
	// bl 0x8207d510
	ctx.lr = 0x8215D770;
	sub_8207D510(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d4d8
	ctx.lr = 0x8215D77C;
	sub_8207D4D8(ctx, base);
	// li r11,9
	ctx.r11.s64 = 9;
loc_8215D780:
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
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
	ctx.lr = 0x8215D79C;
	sub_8207D940(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x8215dd2c
	goto loc_8215DD2C;
loc_8215D7A4:
	// srawi r11,r21,5
	ctx.xer.ca = (ctx.r21.s32 < 0) & ((ctx.r21.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r21.s32 >> 5;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// rlwinm r27,r11,2,0,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r28,r10,-23360
	ctx.r28.s64 = ctx.r10.s64 + -23360;
	// clrlwi r11,r21,27
	ctx.r11.u64 = ctx.r21.u32 & 0x1F;
	// mulli r29,r11,72
	ctx.r29.s64 = ctx.r11.s64 * 72;
	// lwzx r11,r27,r28
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r28.u32);
	// add r10,r29,r11
	ctx.r10.u64 = ctx.r29.u64 + ctx.r11.u64;
	// lbz r11,4(r10)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 4);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// clrlwi. r9,r11,31
	ctx.r9.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x8215d76c
	if (ctx.cr0.eq) goto loc_8215D76C;
	// lis r9,32767
	ctx.r9.s64 = 2147418112;
	// ori r9,r9,65535
	ctx.r9.u64 = ctx.r9.u64 | 65535;
	// cmplw cr6,r31,r9
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r9.u32, ctx.xer);
	// ble cr6,0x8215d7fc
	if (!ctx.cr6.gt) goto loc_8215D7FC;
	// bl 0x8207d510
	ctx.lr = 0x8215D7E8;
	sub_8207D510(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
loc_8215D7F0:
	// bl 0x8207d4d8
	ctx.lr = 0x8215D7F4;
	sub_8207D4D8(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// b 0x8215d780
	goto loc_8215D780;
loc_8215D7FC:
	// li r26,0
	ctx.r26.s64 = 0;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// mr r30,r26
	ctx.r30.u64 = ctx.r26.u64;
	// beq cr6,0x8215dd28
	if (ctx.cr6.eq) goto loc_8215DD28;
	// rlwinm. r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8215dd28
	if (!ctx.cr0.eq) goto loc_8215DD28;
	// cmplwi cr6,r19,0
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, 0, ctx.xer);
	// bne cr6,0x8215d828
	if (!ctx.cr6.eq) goto loc_8215D828;
loc_8215D81C:
	// bl 0x8207d510
	ctx.lr = 0x8215D820;
	sub_8207D510(ctx, base);
	// stw r26,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r26.u32);
	// b 0x8215d7f0
	goto loc_8215D7F0;
loc_8215D828:
	// lbz r11,40(r10)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 40);
	// rotlwi r11,r11,24
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 24);
	// srawi r11,r11,25
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1FFFFFF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 25;
	// extsb r22,r11
	ctx.r22.s64 = ctx.r11.s8;
	// cmpwi cr6,r22,1
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 1, ctx.xer);
	// beq cr6,0x8215d860
	if (ctx.cr6.eq) goto loc_8215D860;
	// cmpwi cr6,r22,2
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 2, ctx.xer);
	// bne cr6,0x8215d858
	if (!ctx.cr6.eq) goto loc_8215D858;
	// not r11,r31
	ctx.r11.u64 = ~ctx.r31.u64;
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8215d81c
	if (ctx.cr0.eq) goto loc_8215D81C;
	// rlwinm r31,r31,0,0,30
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 0) & 0xFFFFFFFE;
loc_8215D858:
	// mr r23,r19
	ctx.r23.u64 = ctx.r19.u64;
	// b 0x8215d8c0
	goto loc_8215D8C0;
loc_8215D860:
	// not r11,r31
	ctx.r11.u64 = ~ctx.r31.u64;
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8215d81c
	if (ctx.cr0.eq) goto loc_8215D81C;
	// rlwinm r31,r31,31,1,31
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplwi cr6,r31,4
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 4, ctx.xer);
	// bge cr6,0x8215d87c
	if (!ctx.cr6.lt) goto loc_8215D87C;
	// li r31,4
	ctx.r31.s64 = 4;
loc_8215D87C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207a400
	ctx.lr = 0x8215D884;
	sub_8207A400(ctx, base);
	// mr. r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// bne 0x8215d8a4
	if (!ctx.cr0.eq) goto loc_8215D8A4;
	// bl 0x8207d4d8
	ctx.lr = 0x8215D890;
	sub_8207D4D8(ctx, base);
	// li r11,12
	ctx.r11.s64 = 12;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d510
	ctx.lr = 0x8215D89C;
	sub_8207D510(ctx, base);
	// li r10,8
	ctx.r10.s64 = 8;
	// b 0x8215d744
	goto loc_8215D744;
loc_8215D8A4:
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// bl 0x82082790
	ctx.lr = 0x8215D8B4;
	sub_82082790(ctx, base);
	// lwzx r11,r27,r28
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r28.u32);
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// std r3,48(r11)
	PPC_STORE_U64(ctx.r11.u32 + 48, ctx.r3.u64);
loc_8215D8C0:
	// lwzx r11,r27,r28
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r28.u32);
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// li r24,10
	ctx.r24.s64 = 10;
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// andi. r10,r10,72
	ctx.r10.u64 = ctx.r10.u64 & 72;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// cmpwi r10,0
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8215d990
	if (ctx.cr0.eq) goto loc_8215D990;
	// lbz r11,5(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 5);
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// beq cr6,0x8215d990
	if (ctx.cr6.eq) goto loc_8215D990;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8215d990
	if (ctx.cr6.eq) goto loc_8215D990;
	// stb r11,0(r23)
	PPC_STORE_U8(ctx.r23.u32 + 0, ctx.r11.u8);
	// addi r4,r23,1
	ctx.r4.s64 = ctx.r23.s64 + 1;
	// lwzx r11,r27,r28
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r28.u32);
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// li r30,1
	ctx.r30.s64 = 1;
	// stb r24,5(r11)
	PPC_STORE_U8(ctx.r11.u32 + 5, ctx.r24.u8);
	// addi r31,r31,-1
	ctx.r31.s64 = ctx.r31.s64 + -1;
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// beq cr6,0x8215d990
	if (ctx.cr6.eq) goto loc_8215D990;
	// lwzx r11,r27,r28
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r28.u32);
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// lbz r11,41(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 41);
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// beq cr6,0x8215d990
	if (ctx.cr6.eq) goto loc_8215D990;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8215d990
	if (ctx.cr6.eq) goto loc_8215D990;
	// stb r11,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, ctx.r11.u8);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// lwzx r11,r27,r28
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r28.u32);
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// li r30,2
	ctx.r30.s64 = 2;
	// stb r24,41(r11)
	PPC_STORE_U8(ctx.r11.u32 + 41, ctx.r24.u8);
	// addi r31,r31,-1
	ctx.r31.s64 = ctx.r31.s64 + -1;
	// cmpwi cr6,r22,1
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 1, ctx.xer);
	// bne cr6,0x8215d990
	if (!ctx.cr6.eq) goto loc_8215D990;
	// lwzx r11,r27,r28
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r28.u32);
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// lbz r11,42(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 42);
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// beq cr6,0x8215d990
	if (ctx.cr6.eq) goto loc_8215D990;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8215d990
	if (ctx.cr6.eq) goto loc_8215D990;
	// stb r11,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, ctx.r11.u8);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// lwzx r11,r27,r28
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r28.u32);
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// li r30,3
	ctx.r30.s64 = 3;
	// stb r24,42(r11)
	PPC_STORE_U8(ctx.r11.u32 + 42, ctx.r24.u8);
	// addi r31,r31,-1
	ctx.r31.s64 = ctx.r31.s64 + -1;
loc_8215D990:
	// lwzx r11,r27,r28
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r28.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// lwzx r3,r29,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// bl 0x82089890
	ctx.lr = 0x8215D9A8;
	sub_82089890(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8215dcf4
	if (ctx.cr0.eq) goto loc_8215DCF4;
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// blt cr6,0x8215dcf4
	if (ctx.cr6.lt) goto loc_8215DCF4;
	// cmplw cr6,r10,r31
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r31.u32, ctx.xer);
	// bgt cr6,0x8215dcf4
	if (ctx.cr6.gt) goto loc_8215DCF4;
	// lwzx r11,r27,r28
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r28.u32);
	// add r30,r10,r30
	ctx.r30.u64 = ctx.r10.u64 + ctx.r30.u64;
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// lbz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// rlwinm. r9,r9,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFF80;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x8215dcb0
	if (ctx.cr0.eq) goto loc_8215DCB0;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8215d9fc
	if (ctx.cr6.eq) goto loc_8215D9FC;
	// lbz r10,0(r23)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r23.u32 + 0);
	// cmplwi cr6,r10,10
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 10, ctx.xer);
	// bne cr6,0x8215d9fc
	if (!ctx.cr6.eq) goto loc_8215D9FC;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// ori r10,r10,4
	ctx.r10.u64 = ctx.r10.u64 | 4;
	// b 0x8215da08
	goto loc_8215DA08;
loc_8215D9FC:
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// rlwinm r10,r10,0,30,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
loc_8215DA08:
	// add r25,r23,r30
	ctx.r25.u64 = ctx.r23.u64 + ctx.r30.u64;
	// stb r10,4(r11)
	PPC_STORE_U8(ctx.r11.u32 + 4, ctx.r10.u8);
	// mr r31,r23
	ctx.r31.u64 = ctx.r23.u64;
	// mr r30,r23
	ctx.r30.u64 = ctx.r23.u64;
	// cmplw cr6,r23,r25
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r25.u32, ctx.xer);
	// bge cr6,0x8215db70
	if (!ctx.cr6.lt) goto loc_8215DB70;
	// li r26,13
	ctx.r26.s64 = 13;
loc_8215DA24:
	// lbz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r30.u32 + 0);
	// extsb r11,r10
	ctx.r11.s64 = ctx.r10.s8;
	// cmpwi cr6,r11,26
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 26, ctx.xer);
	// beq cr6,0x8215db44
	if (ctx.cr6.eq) goto loc_8215DB44;
	// cmpwi cr6,r11,13
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 13, ctx.xer);
	// beq cr6,0x8215da48
	if (ctx.cr6.eq) goto loc_8215DA48;
	// stb r10,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r10.u8);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// b 0x8215db34
	goto loc_8215DB34;
loc_8215DA48:
	// addi r11,r25,-1
	ctx.r11.s64 = ctx.r25.s64 + -1;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x8215da7c
	if (!ctx.cr6.lt) goto loc_8215DA7C;
	// lbz r9,1(r30)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r30.u32 + 1);
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// cmplwi cr6,r9,10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 10, ctx.xer);
	// bne cr6,0x8215da70
	if (!ctx.cr6.eq) goto loc_8215DA70;
	// stb r24,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r24.u8);
	// addi r30,r30,2
	ctx.r30.s64 = ctx.r30.s64 + 2;
	// b 0x8215db34
	goto loc_8215DB34;
loc_8215DA70:
	// stb r10,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r10.u8);
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// b 0x8215db34
	goto loc_8215DB34;
loc_8215DA7C:
	// lwzx r11,r27,r28
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r28.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// lwzx r3,r29,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// bl 0x82089890
	ctx.lr = 0x8215DA9C;
	sub_82089890(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8215dab0
	if (!ctx.cr0.eq) goto loc_8215DAB0;
	// bl 0x82089a10
	ctx.lr = 0x8215DAA8;
	sub_82089A10(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8215db30
	if (!ctx.cr0.eq) goto loc_8215DB30;
loc_8215DAB0:
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8215db30
	if (ctx.cr6.eq) goto loc_8215DB30;
	// lwzx r11,r27,r28
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r28.u32);
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// lbz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// andi. r11,r11,72
	ctx.r11.u64 = ctx.r11.u64 & 72;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8215db00
	if (ctx.cr0.eq) goto loc_8215DB00;
	// lbz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// bne cr6,0x8215dae8
	if (!ctx.cr6.eq) goto loc_8215DAE8;
loc_8215DAE0:
	// stb r24,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r24.u8);
	// b 0x8215db34
	goto loc_8215DB34;
loc_8215DAE8:
	// stb r26,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r26.u8);
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lwzx r11,r27,r28
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r28.u32);
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// stb r10,5(r11)
	PPC_STORE_U8(ctx.r11.u32 + 5, ctx.r10.u8);
	// b 0x8215db34
	goto loc_8215DB34;
loc_8215DB00:
	// cmplw cr6,r31,r23
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r23.u32, ctx.xer);
	// bne cr6,0x8215db14
	if (!ctx.cr6.eq) goto loc_8215DB14;
	// lbz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// beq cr6,0x8215dae0
	if (ctx.cr6.eq) goto loc_8215DAE0;
loc_8215DB14:
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// bl 0x82082790
	ctx.lr = 0x8215DB24;
	sub_82082790(ctx, base);
	// lbz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// beq cr6,0x8215db38
	if (ctx.cr6.eq) goto loc_8215DB38;
loc_8215DB30:
	// stb r26,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r26.u8);
loc_8215DB34:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
loc_8215DB38:
	// cmplw cr6,r30,r25
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r25.u32, ctx.xer);
	// blt cr6,0x8215da24
	if (ctx.cr6.lt) goto loc_8215DA24;
	// b 0x8215db70
	goto loc_8215DB70;
loc_8215DB44:
	// lwzx r11,r27,r28
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r28.u32);
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// lbz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// rlwinm. r9,r9,0,25,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x8215db68
	if (!ctx.cr0.eq) goto loc_8215DB68;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// ori r10,r10,2
	ctx.r10.u64 = ctx.r10.u64 | 2;
	// stb r10,4(r11)
	PPC_STORE_U8(ctx.r11.u32 + 4, ctx.r10.u8);
	// b 0x8215db70
	goto loc_8215DB70;
loc_8215DB68:
	// stb r10,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r10.u8);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
loc_8215DB70:
	// subf r30,r23,r31
	ctx.r30.s64 = ctx.r31.s64 - ctx.r23.s64;
	// cmpwi cr6,r22,1
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 1, ctx.xer);
	// bne cr6,0x8215dcb0
	if (!ctx.cr6.eq) goto loc_8215DCB0;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x8215dcb0
	if (ctx.cr6.eq) goto loc_8215DCB0;
	// lbzu r7,-1(r31)
	ea = -1 + ctx.r31.u32;
	ctx.r7.u64 = PPC_LOAD_U8(ea);
	ctx.r31.u32 = ea;
	// rlwinm. r11,r7,0,0,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFF80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// bne 0x8215db9c
	if (!ctx.cr0.eq) goto loc_8215DB9C;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// b 0x8215dc78
	goto loc_8215DC78;
loc_8215DB9C:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,-15616
	ctx.r9.s64 = ctx.r11.s64 + -15616;
	// lbzx r11,r8,r9
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// b 0x8215dbd0
	goto loc_8215DBD0;
loc_8215DBB0:
	// cmpwi cr6,r10,4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4, ctx.xer);
	// bgt cr6,0x8215dbd8
	if (ctx.cr6.gt) goto loc_8215DBD8;
	// cmplw cr6,r31,r23
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r23.u32, ctx.xer);
	// blt cr6,0x8215dbd8
	if (ctx.cr6.lt) goto loc_8215DBD8;
	// lbzu r7,-1(r31)
	ea = -1 + ctx.r31.u32;
	ctx.r7.u64 = PPC_LOAD_U8(ea);
	ctx.r31.u32 = ea;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
	// lbzx r11,r11,r9
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r9.u32);
loc_8215DBD0:
	// extsb. r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8215dbb0
	if (ctx.cr0.eq) goto loc_8215DBB0;
loc_8215DBD8:
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8215dbf0
	if (!ctx.cr0.eq) goto loc_8215DBF0;
	// bl 0x8207d4d8
	ctx.lr = 0x8215DBE4;
	sub_8207D4D8(ctx, base);
	// li r11,42
	ctx.r11.s64 = 42;
loc_8215DBE8:
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// b 0x8215dcac
	goto loc_8215DCAC;
loc_8215DBF0:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x8215dc04
	if (!ctx.cr6.eq) goto loc_8215DC04;
	// add r31,r10,r31
	ctx.r31.u64 = ctx.r10.u64 + ctx.r31.u64;
	// b 0x8215dc78
	goto loc_8215DC78;
loc_8215DC04:
	// lwzx r11,r27,r28
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r28.u32);
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// lbz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// andi. r9,r9,72
	ctx.r9.u64 = ctx.r9.u64 & 72;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x8215dc64
	if (ctx.cr0.eq) goto loc_8215DC64;
	// stb r7,5(r11)
	PPC_STORE_U8(ctx.r11.u32 + 5, ctx.r7.u8);
	// addi r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 1;
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// blt cr6,0x8215dc40
	if (ctx.cr6.lt) goto loc_8215DC40;
	// lwzx r9,r27,r28
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r28.u32);
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// add r9,r29,r9
	ctx.r9.u64 = ctx.r29.u64 + ctx.r9.u64;
	// stb r8,41(r9)
	PPC_STORE_U8(ctx.r9.u32 + 41, ctx.r8.u8);
loc_8215DC40:
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// bne cr6,0x8215dc5c
	if (!ctx.cr6.eq) goto loc_8215DC5C;
	// lwzx r9,r27,r28
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r28.u32);
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// add r9,r29,r9
	ctx.r9.u64 = ctx.r29.u64 + ctx.r9.u64;
	// stb r8,42(r9)
	PPC_STORE_U8(ctx.r9.u32 + 42, ctx.r8.u8);
loc_8215DC5C:
	// subf r31,r10,r11
	ctx.r31.s64 = ctx.r11.s64 - ctx.r10.s64;
	// b 0x8215dc78
	goto loc_8215DC78;
loc_8215DC64:
	// neg r11,r10
	ctx.r11.s64 = -ctx.r10.s64;
	// li r5,1
	ctx.r5.s64 = 1;
	// extsw r4,r11
	ctx.r4.s64 = ctx.r11.s32;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// bl 0x82082790
	ctx.lr = 0x8215DC78;
	sub_82082790(ctx, base);
loc_8215DC78:
	// subf r31,r23,r31
	ctx.r31.s64 = ctx.r31.s64 - ctx.r23.s64;
	// lis r3,0
	ctx.r3.s64 = 0;
	// rlwinm r8,r20,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 31) & 0x7FFFFFFF;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r3,r3,65001
	ctx.r3.u64 = ctx.r3.u64 | 65001;
	// bl 0x8208a5b0
	ctx.lr = 0x8215DC9C;
	sub_8208A5B0(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x8215dcd4
	if (!ctx.cr0.eq) goto loc_8215DCD4;
	// bl 0x82089a10
	ctx.lr = 0x8215DCA8;
	sub_82089A10(ctx, base);
loc_8215DCA8:
	// bl 0x8207d548
	ctx.lr = 0x8215DCAC;
	sub_8207D548(ctx, base);
loc_8215DCAC:
	// li r18,-1
	ctx.r18.s64 = -1;
loc_8215DCB0:
	// cmplw cr6,r23,r19
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r19.u32, ctx.xer);
	// beq cr6,0x8215dcc0
	if (ctx.cr6.eq) goto loc_8215DCC0;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x8207c068
	ctx.lr = 0x8215DCC0;
	sub_8207C068(ctx, base);
loc_8215DCC0:
	// cmpwi cr6,r18,-2
	ctx.cr6.compare<int32_t>(ctx.r18.s32, -2, ctx.xer);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// beq cr6,0x8215dd2c
	if (ctx.cr6.eq) goto loc_8215DD2C;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// b 0x8215dd2c
	goto loc_8215DD2C;
loc_8215DCD4:
	// lwzx r11,r27,r28
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r28.u32);
	// subf r10,r30,r31
	ctx.r10.s64 = ctx.r31.s64 - ctx.r30.s64;
	// rlwinm r30,r30,1,0,30
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// addic r9,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// subfe r10,r9,r10
	temp.u8 = (~ctx.r9.u32 + ctx.r10.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r9.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r10,56(r11)
	PPC_STORE_U32(ctx.r11.u32 + 56, ctx.r10.u32);
	// b 0x8215dcb0
	goto loc_8215DCB0;
loc_8215DCF4:
	// bl 0x82089a10
	ctx.lr = 0x8215DCF8;
	sub_82089A10(ctx, base);
	// cmplwi cr6,r3,5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 5, ctx.xer);
	// bne cr6,0x8215dd18
	if (!ctx.cr6.eq) goto loc_8215DD18;
	// bl 0x8207d4d8
	ctx.lr = 0x8215DD04;
	sub_8207D4D8(ctx, base);
	// li r11,9
	ctx.r11.s64 = 9;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d510
	ctx.lr = 0x8215DD10;
	sub_8207D510(ctx, base);
	// li r11,5
	ctx.r11.s64 = 5;
	// b 0x8215dbe8
	goto loc_8215DBE8;
loc_8215DD18:
	// cmplwi cr6,r3,109
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 109, ctx.xer);
	// bne cr6,0x8215dca8
	if (!ctx.cr6.eq) goto loc_8215DCA8;
	// mr r18,r26
	ctx.r18.u64 = ctx.r26.u64;
	// b 0x8215dcb0
	goto loc_8215DCB0;
loc_8215DD28:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8215DD2C:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8207c9b0
	__restgprlr_18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215DD34"))) PPC_WEAK_FUNC(sub_8215DD34);
PPC_FUNC_IMPL(__imp__sub_8215DD34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8215DD38"))) PPC_WEAK_FUNC(sub_8215DD38);
PPC_FUNC_IMPL(__imp__sub_8215DD38) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lwz r16,21428(r29)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r29.u32 + 21428);
	// lwz r16,7536(r5)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r5.u32 + 7536);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x8215DD48;
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
	// mr r24,r4
	ctx.r24.u64 = ctx.r4.u64;
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// cmpwi cr6,r3,-2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -2, ctx.xer);
	// bne cr6,0x8215dd8c
	if (!ctx.cr6.eq) goto loc_8215DD8C;
	// bl 0x8207d510
	ctx.lr = 0x8215DD6C;
	sub_8207D510(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d4d8
	ctx.lr = 0x8215DD78;
	sub_8207D4D8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,9
	ctx.r10.s64 = 9;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// b 0x8215de9c
	goto loc_8215DE9C;
loc_8215DD8C:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8215dda4
	if (ctx.cr6.lt) goto loc_8215DDA4;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-23372(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -23372);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8215dddc
	if (ctx.cr6.lt) goto loc_8215DDDC;
loc_8215DDA4:
	// bl 0x8207d510
	ctx.lr = 0x8215DDA8;
	sub_8207D510(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d4d8
	ctx.lr = 0x8215DDB4;
	sub_8207D4D8(ctx, base);
	// li r11,9
	ctx.r11.s64 = 9;
loc_8215DDB8:
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
	ctx.lr = 0x8215DDD4;
	sub_8207D940(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x8215de9c
	goto loc_8215DE9C;
loc_8215DDDC:
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
	// beq 0x8215dda4
	if (ctx.cr0.eq) goto loc_8215DDA4;
	// lis r11,32767
	ctx.r11.s64 = 2147418112;
	// li r26,-1
	ctx.r26.s64 = -1;
	// ori r11,r11,65535
	ctx.r11.u64 = ctx.r11.u64 | 65535;
	// subfc r11,r25,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r25.u32;
	ctx.r11.s64 = ctx.r11.s64 - ctx.r25.s64;
	// subfze. r11,r26
	{ uint8_t _ca = (~ctx.r26.u32 + ctx.xer.ca < ctx.xer.ca); // FIX 2026-07-24: insn was silently dropped by the recompiler
	ctx.r11.u64 = ~ctx.r26.u64 + ctx.xer.ca;
	ctx.xer.ca = _ca; }
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8215de38
	if (!ctx.cr0.eq) goto loc_8215DE38;
	// bl 0x8207d510
	ctx.lr = 0x8215DE24;
	sub_8207D510(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d4d8
	ctx.lr = 0x8215DE30;
	sub_8207D4D8(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// b 0x8215ddb8
	goto loc_8215DDB8;
loc_8215DE38:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82084d80
	ctx.lr = 0x8215DE40;
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
	// beq 0x8215de70
	if (ctx.cr0.eq) goto loc_8215DE70;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8215d708
	ctx.lr = 0x8215DE68;
	sub_8215D708(ctx, base);
	// stw r3,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r3.u32);
	// b 0x8215de8c
	goto loc_8215DE8C;
loc_8215DE70:
	// bl 0x8207d4d8
	ctx.lr = 0x8215DE74;
	sub_8207D4D8(ctx, base);
	// li r11,9
	ctx.r11.s64 = 9;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d510
	ctx.lr = 0x8215DE80;
	sub_8207D510(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r26,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r26.u32);
loc_8215DE8C:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,160
	ctx.r12.s64 = ctx.r31.s64 + 160;
	// bl 0x8215dec4
	ctx.lr = 0x8215DE98;
	sub_8215DEC4(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
loc_8215DE9C:
	// addi r1,r31,160
	ctx.r1.s64 = ctx.r31.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215DD40"))) PPC_WEAK_FUNC(sub_8215DD40);
PPC_FUNC_IMPL(__imp__sub_8215DD40) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x8215DD48;
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
	// mr r24,r4
	ctx.r24.u64 = ctx.r4.u64;
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// cmpwi cr6,r3,-2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -2, ctx.xer);
	// bne cr6,0x8215dd8c
	if (!ctx.cr6.eq) goto loc_8215DD8C;
	// bl 0x8207d510
	ctx.lr = 0x8215DD6C;
	sub_8207D510(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d4d8
	ctx.lr = 0x8215DD78;
	sub_8207D4D8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,9
	ctx.r10.s64 = 9;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// b 0x8215de9c
	goto loc_8215DE9C;
loc_8215DD8C:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8215dda4
	if (ctx.cr6.lt) goto loc_8215DDA4;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-23372(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -23372);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8215dddc
	if (ctx.cr6.lt) goto loc_8215DDDC;
loc_8215DDA4:
	// bl 0x8207d510
	ctx.lr = 0x8215DDA8;
	sub_8207D510(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d4d8
	ctx.lr = 0x8215DDB4;
	sub_8207D4D8(ctx, base);
	// li r11,9
	ctx.r11.s64 = 9;
loc_8215DDB8:
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
	ctx.lr = 0x8215DDD4;
	sub_8207D940(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x8215de9c
	goto loc_8215DE9C;
loc_8215DDDC:
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
	// beq 0x8215dda4
	if (ctx.cr0.eq) goto loc_8215DDA4;
	// lis r11,32767
	ctx.r11.s64 = 2147418112;
	// li r26,-1
	ctx.r26.s64 = -1;
	// ori r11,r11,65535
	ctx.r11.u64 = ctx.r11.u64 | 65535;
	// subfc r11,r25,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r25.u32;
	ctx.r11.s64 = ctx.r11.s64 - ctx.r25.s64;
	// subfze. r11,r26
	{ uint8_t _ca = (~ctx.r26.u32 + ctx.xer.ca < ctx.xer.ca); // FIX 2026-07-24: insn was silently dropped by the recompiler
	ctx.r11.u64 = ~ctx.r26.u64 + ctx.xer.ca;
	ctx.xer.ca = _ca; }
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8215de38
	if (!ctx.cr0.eq) goto loc_8215DE38;
	// bl 0x8207d510
	ctx.lr = 0x8215DE24;
	sub_8207D510(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d4d8
	ctx.lr = 0x8215DE30;
	sub_8207D4D8(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// b 0x8215ddb8
	goto loc_8215DDB8;
loc_8215DE38:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82084d80
	ctx.lr = 0x8215DE40;
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
	// beq 0x8215de70
	if (ctx.cr0.eq) goto loc_8215DE70;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8215d708
	ctx.lr = 0x8215DE68;
	sub_8215D708(ctx, base);
	// stw r3,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r3.u32);
	// b 0x8215de8c
	goto loc_8215DE8C;
loc_8215DE70:
	// bl 0x8207d4d8
	ctx.lr = 0x8215DE74;
	sub_8207D4D8(ctx, base);
	// li r11,9
	ctx.r11.s64 = 9;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d510
	ctx.lr = 0x8215DE80;
	sub_8207D510(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r26,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r26.u32);
loc_8215DE8C:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,160
	ctx.r12.s64 = ctx.r31.s64 + 160;
	// bl 0x8215dec4
	ctx.lr = 0x8215DE98;
	sub_8215DEC4(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
loc_8215DE9C:
	// addi r1,r31,160
	ctx.r1.s64 = ctx.r31.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215DEA4"))) PPC_WEAK_FUNC(sub_8215DEA4);
PPC_FUNC_IMPL(__imp__sub_8215DEA4) {
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
	// b 0x8215dedc
	goto loc_8215DEDC;
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
loc_8215DEDC:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82084e80
	ctx.lr = 0x8215DEE4;
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

__attribute__((alias("__imp__sub_8215DEC4"))) PPC_WEAK_FUNC(sub_8215DEC4);
PPC_FUNC_IMPL(__imp__sub_8215DEC4) {
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
	ctx.lr = 0x8215DEE4;
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

__attribute__((alias("__imp__sub_8215DEFC"))) PPC_WEAK_FUNC(sub_8215DEFC);
PPC_FUNC_IMPL(__imp__sub_8215DEFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8215DF00"))) PPC_WEAK_FUNC(sub_8215DF00);
PPC_FUNC_IMPL(__imp__sub_8215DF00) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8215DF08;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// bl 0x82084cb0
	ctx.lr = 0x8215DF1C;
	sub_82084CB0(ctx, base);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x8215df3c
	if (!ctx.cr6.eq) goto loc_8215DF3C;
	// bl 0x8207d4d8
	ctx.lr = 0x8215DF28;
	sub_8207D4D8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,9
	ctx.r10.s64 = 9;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// b 0x8215dfb0
	goto loc_8215DFB0;
loc_8215DF3C:
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82089528
	ctx.lr = 0x8215DF4C;
	sub_82089528(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x8215df60
	if (!ctx.cr6.eq) goto loc_8215DF60;
	// bl 0x82089a10
	ctx.lr = 0x8215DF5C;
	sub_82089A10(ctx, base);
	// b 0x8215df64
	goto loc_8215DF64;
loc_8215DF60:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8215DF64:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8215df78
	if (ctx.cr6.eq) goto loc_8215DF78;
	// bl 0x8207d548
	ctx.lr = 0x8215DF70;
	sub_8207D548(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x8215dfb0
	goto loc_8215DFB0;
loc_8215DF78:
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
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
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
loc_8215DFB0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215DFB8"))) PPC_WEAK_FUNC(sub_8215DFB8);
PPC_FUNC_IMPL(__imp__sub_8215DFB8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lwz r16,21428(r29)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r29.u32 + 21428);
	// lwz r16,7560(r5)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r5.u32 + 7560);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x8215DFC8;
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
	// bne cr6,0x8215e00c
	if (!ctx.cr6.eq) goto loc_8215E00C;
	// bl 0x8207d510
	ctx.lr = 0x8215DFEC;
	sub_8207D510(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d4d8
	ctx.lr = 0x8215DFF8;
	sub_8207D4D8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,9
	ctx.r10.s64 = 9;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// b 0x8215e0f0
	goto loc_8215E0F0;
loc_8215E00C:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8215e024
	if (ctx.cr6.lt) goto loc_8215E024;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-23372(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -23372);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8215e05c
	if (ctx.cr6.lt) goto loc_8215E05C;
loc_8215E024:
	// bl 0x8207d510
	ctx.lr = 0x8215E028;
	sub_8207D510(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d4d8
	ctx.lr = 0x8215E034;
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
	ctx.lr = 0x8215E054;
	sub_8207D940(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x8215e0f0
	goto loc_8215E0F0;
loc_8215E05C:
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
	// beq 0x8215e024
	if (ctx.cr0.eq) goto loc_8215E024;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82084d80
	ctx.lr = 0x8215E090;
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
	// beq 0x8215e0c0
	if (ctx.cr0.eq) goto loc_8215E0C0;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8215df00
	ctx.lr = 0x8215E0B8;
	sub_8215DF00(ctx, base);
	// stw r3,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r3.u32);
	// b 0x8215e0e0
	goto loc_8215E0E0;
loc_8215E0C0:
	// bl 0x8207d4d8
	ctx.lr = 0x8215E0C4;
	sub_8207D4D8(ctx, base);
	// li r11,9
	ctx.r11.s64 = 9;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d510
	ctx.lr = 0x8215E0D0;
	sub_8207D510(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r10.u32);
loc_8215E0E0:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,160
	ctx.r12.s64 = ctx.r31.s64 + 160;
	// bl 0x8215e118
	ctx.lr = 0x8215E0EC;
	sub_8215E118(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
loc_8215E0F0:
	// addi r1,r31,160
	ctx.r1.s64 = ctx.r31.s64 + 160;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215DFC0"))) PPC_WEAK_FUNC(sub_8215DFC0);
PPC_FUNC_IMPL(__imp__sub_8215DFC0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x8215DFC8;
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
	// bne cr6,0x8215e00c
	if (!ctx.cr6.eq) goto loc_8215E00C;
	// bl 0x8207d510
	ctx.lr = 0x8215DFEC;
	sub_8207D510(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d4d8
	ctx.lr = 0x8215DFF8;
	sub_8207D4D8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,9
	ctx.r10.s64 = 9;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// b 0x8215e0f0
	goto loc_8215E0F0;
loc_8215E00C:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8215e024
	if (ctx.cr6.lt) goto loc_8215E024;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-23372(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -23372);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8215e05c
	if (ctx.cr6.lt) goto loc_8215E05C;
loc_8215E024:
	// bl 0x8207d510
	ctx.lr = 0x8215E028;
	sub_8207D510(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d4d8
	ctx.lr = 0x8215E034;
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
	ctx.lr = 0x8215E054;
	sub_8207D940(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x8215e0f0
	goto loc_8215E0F0;
loc_8215E05C:
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
	// beq 0x8215e024
	if (ctx.cr0.eq) goto loc_8215E024;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82084d80
	ctx.lr = 0x8215E090;
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
	// beq 0x8215e0c0
	if (ctx.cr0.eq) goto loc_8215E0C0;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8215df00
	ctx.lr = 0x8215E0B8;
	sub_8215DF00(ctx, base);
	// stw r3,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r3.u32);
	// b 0x8215e0e0
	goto loc_8215E0E0;
loc_8215E0C0:
	// bl 0x8207d4d8
	ctx.lr = 0x8215E0C4;
	sub_8207D4D8(ctx, base);
	// li r11,9
	ctx.r11.s64 = 9;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d510
	ctx.lr = 0x8215E0D0;
	sub_8207D510(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r10.u32);
loc_8215E0E0:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,160
	ctx.r12.s64 = ctx.r31.s64 + 160;
	// bl 0x8215e118
	ctx.lr = 0x8215E0EC;
	sub_8215E118(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
loc_8215E0F0:
	// addi r1,r31,160
	ctx.r1.s64 = ctx.r31.s64 + 160;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215E0F8"))) PPC_WEAK_FUNC(sub_8215E0F8);
PPC_FUNC_IMPL(__imp__sub_8215E0F8) {
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
	// b 0x8215e130
	goto loc_8215E130;
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
loc_8215E130:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82084e80
	ctx.lr = 0x8215E138;
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

__attribute__((alias("__imp__sub_8215E118"))) PPC_WEAK_FUNC(sub_8215E118);
PPC_FUNC_IMPL(__imp__sub_8215E118) {
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
	ctx.lr = 0x8215E138;
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

__attribute__((alias("__imp__sub_8215E150"))) PPC_WEAK_FUNC(sub_8215E150);
PPC_FUNC_IMPL(__imp__sub_8215E150) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x8215E158;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8215e194
	if (!ctx.cr6.eq) goto loc_8215E194;
	// bl 0x8207d4d8
	ctx.lr = 0x8215E16C;
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
	ctx.lr = 0x8215E18C;
	sub_8207D940(ctx, base);
loc_8215E18C:
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x8215e380
	goto loc_8215E380;
loc_8215E194:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x820809e8
	ctx.lr = 0x8215E19C;
	sub_820809E8(ctx, base);
	// lwz r11,4(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x8215e1b4
	if (!ctx.cr6.lt) goto loc_8215E1B4;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,4(r27)
	PPC_STORE_U32(ctx.r27.u32 + 4, ctx.r11.u32);
loc_8215E1B4:
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8215dfc0
	ctx.lr = 0x8215E1C4;
	sub_8215DFC0(ctx, base);
	// mr. r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// blt 0x8215e18c
	if (ctx.cr0.lt) goto loc_8215E18C;
	// lwz r7,12(r27)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// andi. r11,r7,264
	ctx.r11.u64 = ctx.r7.u64 & 264;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8215e1e8
	if (!ctx.cr0.eq) goto loc_8215E1E8;
	// lwz r11,4(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// subf r3,r11,r24
	ctx.r3.s64 = ctx.r24.s64 - ctx.r11.s64;
	// b 0x8215e380
	goto loc_8215E380;
loc_8215E1E8:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// clrlwi. r10,r7,30
	ctx.r10.u64 = ctx.r7.u32 & 0x3;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r26,r11,-23360
	ctx.r26.s64 = ctx.r11.s64 + -23360;
	// lwz r11,8(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 8);
	// subf r25,r11,r9
	ctx.r25.s64 = ctx.r9.s64 - ctx.r11.s64;
	// beq 0x8215e268
	if (ctx.cr0.eq) goto loc_8215E268;
	// srawi r10,r29,5
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r29.s32 >> 5;
	// clrlwi r8,r29,27
	ctx.r8.u64 = ctx.r29.u32 & 0x1F;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mulli r10,r8,72
	ctx.r10.s64 = ctx.r8.s64 * 72;
	// lwzx r8,r6,r26
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r26.u32);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// lbz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 4);
	// rlwinm. r10,r10,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8215e258
	if (ctx.cr0.eq) goto loc_8215E258;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x8215e258
	if (!ctx.cr6.lt) goto loc_8215E258;
	// rotlwi r8,r9,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// subf r8,r11,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r11.s64;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_8215E240:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r8,10
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 10, ctx.xer);
	// bne cr6,0x8215e250
	if (!ctx.cr6.eq) goto loc_8215E250;
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
loc_8215E250:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x8215e240
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8215E240;
loc_8215E258:
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// bne cr6,0x8215e288
	if (!ctx.cr6.eq) goto loc_8215E288;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// b 0x8215e380
	goto loc_8215E380;
loc_8215E268:
	// rlwinm. r10,r7,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8215e258
	if (!ctx.cr0.eq) goto loc_8215E258;
	// bl 0x8207d4d8
	ctx.lr = 0x8215E274;
	sub_8207D4D8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,22
	ctx.r10.s64 = 22;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// b 0x8215e380
	goto loc_8215E380;
loc_8215E288:
	// clrlwi. r10,r7,31
	ctx.r10.u64 = ctx.r7.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8215e37c
	if (ctx.cr0.eq) goto loc_8215E37C;
	// lwz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8215e2a4
	if (!ctx.cr6.eq) goto loc_8215E2A4;
	// li r25,0
	ctx.r25.s64 = 0;
	// b 0x8215e37c
	goto loc_8215E37C;
loc_8215E2A4:
	// srawi r8,r29,5
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x1F) != 0);
	ctx.r8.s64 = ctx.r29.s32 >> 5;
	// subf r11,r11,r9
	ctx.r11.s64 = ctx.r9.s64 - ctx.r11.s64;
	// rlwinm r28,r8,2,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r9,r29,27
	ctx.r9.u64 = ctx.r29.u32 & 0x1F;
	// add r31,r11,r10
	ctx.r31.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mulli r30,r9,72
	ctx.r30.s64 = ctx.r9.s64 * 72;
	// lwzx r11,r28,r26
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + ctx.r26.u32);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// lbz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// rlwinm. r11,r11,0,0,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8215e378
	if (ctx.cr0.eq) goto loc_8215E378;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8215dfc0
	ctx.lr = 0x8215E2E0;
	sub_8215DFC0(ctx, base);
	// cmpw cr6,r3,r24
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r24.s32, ctx.xer);
	// bne cr6,0x8215e324
	if (!ctx.cr6.eq) goto loc_8215E324;
	// lwz r11,8(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 8);
	// add r10,r11,r31
	ctx.r10.u64 = ctx.r11.u64 + ctx.r31.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8215e318
	if (!ctx.cr6.lt) goto loc_8215E318;
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r11.s64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8215E300:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,10
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 10, ctx.xer);
	// bne cr6,0x8215e310
	if (!ctx.cr6.eq) goto loc_8215E310;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
loc_8215E310:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bdnz 0x8215e300
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8215E300;
loc_8215E318:
	// lwz r11,12(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// rlwinm. r11,r11,0,18,18
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// b 0x8215e370
	goto loc_8215E370;
loc_8215E324:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8215dfc0
	ctx.lr = 0x8215E334;
	sub_8215DFC0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8215e18c
	if (ctx.cr0.lt) goto loc_8215E18C;
	// cmplwi cr6,r31,512
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 512, ctx.xer);
	// bgt cr6,0x8215e35c
	if (ctx.cr6.gt) goto loc_8215E35C;
	// lwz r11,12(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// rlwinm. r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8215e35c
	if (ctx.cr0.eq) goto loc_8215E35C;
	// rlwinm. r11,r11,0,21,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x400;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r31,512
	ctx.r31.s64 = 512;
	// beq 0x8215e360
	if (ctx.cr0.eq) goto loc_8215E360;
loc_8215E35C:
	// lwz r31,24(r27)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r27.u32 + 24);
loc_8215E360:
	// lwzx r11,r28,r26
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + ctx.r26.u32);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// lbz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// rlwinm. r11,r11,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
loc_8215E370:
	// beq 0x8215e378
	if (ctx.cr0.eq) goto loc_8215E378;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
loc_8215E378:
	// subf r24,r31,r24
	ctx.r24.s64 = ctx.r24.s64 - ctx.r31.s64;
loc_8215E37C:
	// add r3,r25,r24
	ctx.r3.u64 = ctx.r25.u64 + ctx.r24.u64;
loc_8215E380:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215E388"))) PPC_WEAK_FUNC(sub_8215E388);
PPC_FUNC_IMPL(__imp__sub_8215E388) {
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
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8215e3ac
	if (ctx.cr6.eq) goto loc_8215E3AC;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x8215e3d8
	if (!ctx.cr6.eq) goto loc_8215E3D8;
loc_8215E3AC:
	// bl 0x8207d4d8
	ctx.lr = 0x8215E3B0;
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
	ctx.lr = 0x8215E3D0;
	sub_8207D940(ctx, base);
	// li r3,22
	ctx.r3.s64 = 22;
	// b 0x8215e484
	goto loc_8215E484;
loc_8215E3D8:
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bne cr6,0x8215e3ec
	if (!ctx.cr6.eq) goto loc_8215E3EC;
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r11.u8);
	// b 0x8215e3ac
	goto loc_8215E3AC;
loc_8215E3EC:
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_8215E3F0:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x8215e408
	if (ctx.cr0.eq) goto loc_8215E408;
	// addic. r8,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bne 0x8215e3f0
	if (!ctx.cr0.eq) goto loc_8215E3F0;
loc_8215E408:
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8215e444
	if (!ctx.cr6.eq) goto loc_8215E444;
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r11.u8);
	// bl 0x8207d4d8
	ctx.lr = 0x8215E41C;
	sub_8207D4D8(ctx, base);
	// li r31,22
	ctx.r31.s64 = 22;
loc_8215E420:
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
	ctx.lr = 0x8215E43C;
	sub_8207D940(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x8215e484
	goto loc_8215E484;
loc_8215E444:
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// addi r10,r5,-1
	ctx.r10.s64 = ctx.r5.s64 + -1;
loc_8215E44C:
	// lbzu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r11.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stbu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	PPC_STORE_U8(ea, ctx.r11.u8);
	ctx.r9.u32 = ea;
	// beq 0x8215e464
	if (ctx.cr0.eq) goto loc_8215E464;
	// addic. r8,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8215e44c
	if (!ctx.cr0.eq) goto loc_8215E44C;
loc_8215E464:
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8215e480
	if (!ctx.cr6.eq) goto loc_8215E480;
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r11.u8);
	// bl 0x8207d4d8
	ctx.lr = 0x8215E478;
	sub_8207D4D8(ctx, base);
	// li r31,34
	ctx.r31.s64 = 34;
	// b 0x8215e420
	goto loc_8215E420;
loc_8215E480:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8215E484:
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

__attribute__((alias("__imp__sub_8215E498"))) PPC_WEAK_FUNC(sub_8215E498);
PPC_FUNC_IMPL(__imp__sub_8215E498) {
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
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x8215e4dc
	if (!ctx.cr6.eq) goto loc_8215E4DC;
	// bl 0x8207d4d8
	ctx.lr = 0x8215E4B4;
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
	ctx.lr = 0x8215E4D4;
	sub_8207D940(ctx, base);
	// li r3,22
	ctx.r3.s64 = 22;
	// b 0x8215e5f8
	goto loc_8215E5F8;
loc_8215E4DC:
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bne cr6,0x8215e510
	if (!ctx.cr6.eq) goto loc_8215E510;
loc_8215E4E4:
	// bl 0x8207d4d8
	ctx.lr = 0x8215E4E8;
	sub_8207D4D8(ctx, base);
	// li r31,22
	ctx.r31.s64 = 22;
loc_8215E4EC:
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
	ctx.lr = 0x8215E508;
	sub_8207D940(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x8215e5f8
	goto loc_8215E5F8;
loc_8215E510:
	// cntlzw r11,r7
	ctx.r11.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// li r31,0
	ctx.r31.s64 = 0;
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// stb r31,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, ctx.r31.u8);
	// xori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 ^ 1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplw cr6,r5,r11
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8215e53c
	if (ctx.cr6.gt) goto loc_8215E53C;
loc_8215E530:
	// bl 0x8207d4d8
	ctx.lr = 0x8215E534;
	sub_8207D4D8(ctx, base);
	// li r31,34
	ctx.r31.s64 = 34;
	// b 0x8215e4ec
	goto loc_8215E4EC;
loc_8215E53C:
	// cmplwi cr6,r6,2
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 2, ctx.xer);
	// blt cr6,0x8215e4e4
	if (ctx.cr6.lt) goto loc_8215E4E4;
	// cmplwi cr6,r6,36
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 36, ctx.xer);
	// bgt cr6,0x8215e4e4
	if (ctx.cr6.gt) goto loc_8215E4E4;
	// mr r9,r31
	ctx.r9.u64 = ctx.r31.u64;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x8215e570
	if (ctx.cr6.eq) goto loc_8215E570;
	// li r10,45
	ctx.r10.s64 = 45;
	// addi r11,r4,1
	ctx.r11.s64 = ctx.r4.s64 + 1;
	// stb r10,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, ctx.r10.u8);
	// li r9,1
	ctx.r9.s64 = 1;
	// neg r3,r3
	ctx.r3.s64 = -ctx.r3.s64;
loc_8215E570:
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
loc_8215E574:
	// divwu r10,r3,r6
	ctx.r10.u32 = ppc_divwu(ctx.r3.u32, ctx.r6.u32);
	// twllei r6,0
	// mullw r10,r10,r6
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r6.s32);
	// subf r10,r10,r3
	ctx.r10.s64 = ctx.r3.s64 - ctx.r10.s64;
	// divwu r3,r3,r6
	ctx.r3.u32 = ppc_divwu(ctx.r3.u32, ctx.r6.u32);
	// twllei r6,0
	// cmplwi cr6,r10,9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 9, ctx.xer);
	// ble cr6,0x8215e59c
	if (!ctx.cr6.gt) goto loc_8215E59C;
	// addi r10,r10,87
	ctx.r10.s64 = ctx.r10.s64 + 87;
	// b 0x8215e5a0
	goto loc_8215E5A0;
loc_8215E59C:
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
loc_8215E5A0:
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8215e5bc
	if (ctx.cr6.eq) goto loc_8215E5BC;
	// cmplw cr6,r9,r5
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r5.u32, ctx.xer);
	// blt cr6,0x8215e574
	if (ctx.cr6.lt) goto loc_8215E574;
loc_8215E5BC:
	// cmplw cr6,r9,r5
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r5.u32, ctx.xer);
	// blt cr6,0x8215e5cc
	if (ctx.cr6.lt) goto loc_8215E5CC;
	// stb r31,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, ctx.r31.u8);
	// b 0x8215e530
	goto loc_8215E530;
loc_8215E5CC:
	// stb r31,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r31.u8);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_8215E5D4:
	// lbz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stb r9,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r9.u8);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8215e5d4
	if (ctx.cr6.lt) goto loc_8215E5D4;
	// li r3,0
	ctx.r3.s64 = 0;
loc_8215E5F8:
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

__attribute__((alias("__imp__sub_8215E60C"))) PPC_WEAK_FUNC(sub_8215E60C);
PPC_FUNC_IMPL(__imp__sub_8215E60C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8215E610"))) PPC_WEAK_FUNC(sub_8215E610);
PPC_FUNC_IMPL(__imp__sub_8215E610) {
	PPC_FUNC_PROLOGUE();
	// li r7,0
	ctx.r7.s64 = 0;
	// b 0x8215e498
	sub_8215E498(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215E618"))) PPC_WEAK_FUNC(sub_8215E618);
PPC_FUNC_IMPL(__imp__sub_8215E618) {
	PPC_FUNC_PROLOGUE();
	// b 0x82085440
	sub_82085440(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215E61C"))) PPC_WEAK_FUNC(sub_8215E61C);
PPC_FUNC_IMPL(__imp__sub_8215E61C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8215E620"))) PPC_WEAK_FUNC(sub_8215E620);
PPC_FUNC_IMPL(__imp__sub_8215E620) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lwz r16,21428(r29)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r29.u32 + 21428);
	// lwz r16,7584(r5)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r5.u32 + 7584);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8215E630;
	__savegprlr_28(ctx, base);
	// addi r31,r1,-128
	ctx.r31.s64 = ctx.r1.s64 + -128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r28,0
	ctx.r28.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r28,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r28.u32);
	// bl 0x8207d808
	ctx.lr = 0x8215E648;
	sub_8207D808(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r30,r11,-23088
	ctx.r30.s64 = ctx.r11.s64 + -23088;
	// addi r10,r10,-23084
	ctx.r10.s64 = ctx.r10.s64 + -23084;
loc_8215E65C:
	// stw r28,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r28.u32);
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpw cr6,r28,r11
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x8215e6ec
	if (!ctx.cr6.lt) goto loc_8215E6EC;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// rlwinm r29,r28,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r29,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8215e6e0
	if (ctx.cr6.eq) goto loc_8215E6E0;
	// rotlwi r4,r9,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// lwz r11,12(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// andi. r11,r11,131
	ctx.r11.u64 = ctx.r11.u64 & 131;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8215e6e0
	if (ctx.cr0.eq) goto loc_8215E6E0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8207c4a0
	ctx.lr = 0x8215E69C;
	sub_8207C4A0(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwzx r3,r29,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// andi. r11,r11,131
	ctx.r11.u64 = ctx.r11.u64 & 131;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8215e6d4
	if (ctx.cr0.eq) goto loc_8215E6D4;
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8215e6d4
	if (ctx.cr6.eq) goto loc_8215E6D4;
	// bl 0x820849c8
	ctx.lr = 0x8215E6C8;
	sub_820849C8(ctx, base);
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
loc_8215E6D4:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,128
	ctx.r12.s64 = ctx.r31.s64 + 128;
	// bl 0x8215e754
	ctx.lr = 0x8215E6E0;
	sub_8215E754(ctx, base);
loc_8215E6E0:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// b 0x8215e65c
	goto loc_8215E65C;
loc_8215E6EC:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,128
	ctx.r12.s64 = ctx.r31.s64 + 128;
	// bl 0x8215e704
	ctx.lr = 0x8215E6F8;
	sub_8215E704(ctx, base);
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// addi r1,r31,128
	ctx.r1.s64 = ctx.r31.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215E628"))) PPC_WEAK_FUNC(sub_8215E628);
PPC_FUNC_IMPL(__imp__sub_8215E628) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8215E630;
	__savegprlr_28(ctx, base);
	// addi r31,r1,-128
	ctx.r31.s64 = ctx.r1.s64 + -128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r28,0
	ctx.r28.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r28,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r28.u32);
	// bl 0x8207d808
	ctx.lr = 0x8215E648;
	sub_8207D808(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r30,r11,-23088
	ctx.r30.s64 = ctx.r11.s64 + -23088;
	// addi r10,r10,-23084
	ctx.r10.s64 = ctx.r10.s64 + -23084;
loc_8215E65C:
	// stw r28,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r28.u32);
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpw cr6,r28,r11
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x8215e6ec
	if (!ctx.cr6.lt) goto loc_8215E6EC;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// rlwinm r29,r28,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r29,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8215e6e0
	if (ctx.cr6.eq) goto loc_8215E6E0;
	// rotlwi r4,r9,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// lwz r11,12(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// andi. r11,r11,131
	ctx.r11.u64 = ctx.r11.u64 & 131;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8215e6e0
	if (ctx.cr0.eq) goto loc_8215E6E0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8207c4a0
	ctx.lr = 0x8215E69C;
	sub_8207C4A0(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwzx r3,r29,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// andi. r11,r11,131
	ctx.r11.u64 = ctx.r11.u64 & 131;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8215e6d4
	if (ctx.cr0.eq) goto loc_8215E6D4;
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8215e6d4
	if (ctx.cr6.eq) goto loc_8215E6D4;
	// bl 0x820849c8
	ctx.lr = 0x8215E6C8;
	sub_820849C8(ctx, base);
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
loc_8215E6D4:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,128
	ctx.r12.s64 = ctx.r31.s64 + 128;
	// bl 0x8215e754
	ctx.lr = 0x8215E6E0;
	sub_8215E754(ctx, base);
loc_8215E6E0:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// b 0x8215e65c
	goto loc_8215E65C;
loc_8215E6EC:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,128
	ctx.r12.s64 = ctx.r31.s64 + 128;
	// bl 0x8215e704
	ctx.lr = 0x8215E6F8;
	sub_8215E704(ctx, base);
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// addi r1,r31,128
	ctx.r1.s64 = ctx.r31.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215E704"))) PPC_WEAK_FUNC(sub_8215E704);
PPC_FUNC_IMPL(__imp__sub_8215E704) {
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
	ctx.lr = 0x8215E718;
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

__attribute__((alias("__imp__sub_8215E728"))) PPC_WEAK_FUNC(sub_8215E728);
PPC_FUNC_IMPL(__imp__sub_8215E728) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r31,r12,-128
	ctx.r31.s64 = ctx.r12.s64 + -128;
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r28,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r28.u64);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-32(r1)
	PPC_STORE_U32(ctx.r1.u32 + -32, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r28,80(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// addi r30,r11,-23088
	ctx.r30.s64 = ctx.r11.s64 + -23088;
	// b 0x8215e770
	goto loc_8215E770;
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r31,r12,-128
	ctx.r31.s64 = ctx.r12.s64 + -128;
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r28,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r28.u64);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-32(r1)
	PPC_STORE_U32(ctx.r1.u32 + -32, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
loc_8215E770:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// rlwinm r10,r28,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwzx r4,r10,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// bl 0x8207c530
	ctx.lr = 0x8215E784;
	sub_8207C530(ctx, base);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lwz r28,80(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r30,r10,-23088
	ctx.r30.s64 = ctx.r10.s64 + -23088;
	// addi r10,r11,-23084
	ctx.r10.s64 = ctx.r11.s64 + -23084;
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r30,-16(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r28,-24(r1)
	ctx.r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// lwz r12,-32(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -32);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8215E754"))) PPC_WEAK_FUNC(sub_8215E754);
PPC_FUNC_IMPL(__imp__sub_8215E754) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r31,r12,-128
	ctx.r31.s64 = ctx.r12.s64 + -128;
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r28,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r28.u64);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-32(r1)
	PPC_STORE_U32(ctx.r1.u32 + -32, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// rlwinm r10,r28,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwzx r4,r10,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// bl 0x8207c530
	ctx.lr = 0x8215E784;
	sub_8207C530(ctx, base);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lwz r28,80(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r30,r10,-23088
	ctx.r30.s64 = ctx.r10.s64 + -23088;
	// addi r10,r11,-23084
	ctx.r10.s64 = ctx.r11.s64 + -23084;
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r30,-16(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r28,-24(r1)
	ctx.r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// lwz r12,-32(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -32);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8215E7B4"))) PPC_WEAK_FUNC(sub_8215E7B4);
PPC_FUNC_IMPL(__imp__sub_8215E7B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8215E7B8"))) PPC_WEAK_FUNC(sub_8215E7B8);
PPC_FUNC_IMPL(__imp__sub_8215E7B8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8215E7C0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8215e83c
	if (ctx.cr6.eq) goto loc_8215E83C;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_8215E7D4:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8215e7d4
	if (!ctx.cr6.eq) goto loc_8215E7D4;
	// subf r11,r29,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r29.s64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// addi r30,r11,1
	ctx.r30.s64 = ctx.r11.s64 + 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207a400
	ctx.lr = 0x8215E7FC;
	sub_8207A400(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x8215e83c
	if (ctx.cr0.eq) goto loc_8215E83C;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207abf0
	ctx.lr = 0x8215E814;
	sub_8207ABF0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8215e834
	if (ctx.cr0.eq) goto loc_8215E834;
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
	ctx.lr = 0x8215E834;
	sub_8207D988(ctx, base);
loc_8215E834:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x8215e840
	goto loc_8215E840;
loc_8215E83C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8215E840:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215E848"))) PPC_WEAK_FUNC(sub_8215E848);
PPC_FUNC_IMPL(__imp__sub_8215E848) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c968
	ctx.lr = 0x8215E850;
	__savegprlr_20(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r23,0
	ctx.r23.s64 = 0;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// stw r23,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r23.u32);
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r22,r5
	ctx.r22.u64 = ctx.r5.u64;
	// mr r21,r6
	ctx.r21.u64 = ctx.r6.u64;
	// mr r31,r7
	ctx.r31.u64 = ctx.r7.u64;
	// mr r30,r8
	ctx.r30.u64 = ctx.r8.u64;
	// mr r27,r23
	ctx.r27.u64 = ctx.r23.u64;
	// bl 0x8215f5c0
	ctx.lr = 0x8215E880;
	sub_8215F5C0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8215e8a0
	if (ctx.cr0.eq) goto loc_8215E8A0;
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
	ctx.lr = 0x8215E8A0;
	sub_8207D988(ctx, base);
loc_8215E8A0:
	// rlwinm. r11,r21,0,16,16
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 0) & 0x8000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8215e8ac
	if (!ctx.cr0.eq) goto loc_8215E8AC;
	// li r27,-128
	ctx.r27.s64 = -128;
loc_8215E8AC:
	// clrlwi r11,r21,30
	ctx.r11.u64 = ctx.r21.u32 & 0x3;
	// lis r20,-16384
	ctx.r20.s64 = -1073741824;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8215e914
	if (ctx.cr6.lt) goto loc_8215E914;
	// beq cr6,0x8215e90c
	if (ctx.cr6.eq) goto loc_8215E90C;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x8215e904
	if (ctx.cr6.lt) goto loc_8215E904;
loc_8215E8C8:
	// bl 0x8207d510
	ctx.lr = 0x8215E8CC;
	sub_8207D510(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r23,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r23.u32);
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// bl 0x8207d4d8
	ctx.lr = 0x8215E8DC;
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
	ctx.lr = 0x8215E8FC;
	sub_8207D940(ctx, base);
	// li r3,22
	ctx.r3.s64 = 22;
	// b 0x8215ed70
	goto loc_8215ED70;
loc_8215E904:
	// mr r25,r20
	ctx.r25.u64 = ctx.r20.u64;
	// b 0x8215e918
	goto loc_8215E918;
loc_8215E90C:
	// lis r25,16384
	ctx.r25.s64 = 1073741824;
	// b 0x8215e918
	goto loc_8215E918;
loc_8215E914:
	// lis r25,-32768
	ctx.r25.s64 = -2147483648;
loc_8215E918:
	// cmpwi cr6,r31,16
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 16, ctx.xer);
	// beq cr6,0x8215e96c
	if (ctx.cr6.eq) goto loc_8215E96C;
	// cmpwi cr6,r31,32
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 32, ctx.xer);
	// beq cr6,0x8215e964
	if (ctx.cr6.eq) goto loc_8215E964;
	// cmpwi cr6,r31,48
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 48, ctx.xer);
	// beq cr6,0x8215e95c
	if (ctx.cr6.eq) goto loc_8215E95C;
	// cmpwi cr6,r31,64
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 64, ctx.xer);
	// beq cr6,0x8215e954
	if (ctx.cr6.eq) goto loc_8215E954;
	// cmpwi cr6,r31,128
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 128, ctx.xer);
	// bne cr6,0x8215e8c8
	if (!ctx.cr6.eq) goto loc_8215E8C8;
	// lis r11,-32768
	ctx.r11.s64 = -2147483648;
	// subf r11,r25,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r25.s64;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r24,r11,27,31,31
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// b 0x8215e970
	goto loc_8215E970;
loc_8215E954:
	// li r24,3
	ctx.r24.s64 = 3;
	// b 0x8215e970
	goto loc_8215E970;
loc_8215E95C:
	// li r24,2
	ctx.r24.s64 = 2;
	// b 0x8215e970
	goto loc_8215E970;
loc_8215E964:
	// li r24,1
	ctx.r24.s64 = 1;
	// b 0x8215e970
	goto loc_8215E970;
loc_8215E96C:
	// mr r24,r23
	ctx.r24.u64 = ctx.r23.u64;
loc_8215E970:
	// rlwinm r11,r21,0,21,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 0) & 0x700;
	// cmpwi cr6,r11,1024
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1024, ctx.xer);
	// bgt cr6,0x8215e9b8
	if (ctx.cr6.gt) goto loc_8215E9B8;
	// beq cr6,0x8215e9b0
	if (ctx.cr6.eq) goto loc_8215E9B0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8215e9b0
	if (ctx.cr6.eq) goto loc_8215E9B0;
	// cmpwi cr6,r11,256
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 256, ctx.xer);
	// beq cr6,0x8215e9a8
	if (ctx.cr6.eq) goto loc_8215E9A8;
	// cmpwi cr6,r11,512
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 512, ctx.xer);
	// beq cr6,0x8215ea28
	if (ctx.cr6.eq) goto loc_8215EA28;
	// cmpwi cr6,r11,768
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 768, ctx.xer);
	// bne cr6,0x8215e8c8
	if (!ctx.cr6.eq) goto loc_8215E8C8;
	// li r31,2
	ctx.r31.s64 = 2;
	// b 0x8215e9d4
	goto loc_8215E9D4;
loc_8215E9A8:
	// li r31,4
	ctx.r31.s64 = 4;
	// b 0x8215e9d4
	goto loc_8215E9D4;
loc_8215E9B0:
	// li r31,3
	ctx.r31.s64 = 3;
	// b 0x8215e9d4
	goto loc_8215E9D4;
loc_8215E9B8:
	// cmpwi cr6,r11,1280
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1280, ctx.xer);
	// beq cr6,0x8215e9d0
	if (ctx.cr6.eq) goto loc_8215E9D0;
	// cmpwi cr6,r11,1536
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1536, ctx.xer);
	// beq cr6,0x8215ea28
	if (ctx.cr6.eq) goto loc_8215EA28;
	// cmpwi cr6,r11,1792
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1792, ctx.xer);
	// bne cr6,0x8215e8c8
	if (!ctx.cr6.eq) goto loc_8215E8C8;
loc_8215E9D0:
	// li r31,1
	ctx.r31.s64 = 1;
loc_8215E9D4:
	// rlwinm. r11,r21,0,23,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 0) & 0x100;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r26,128
	ctx.r26.s64 = 128;
	// beq 0x8215e9f8
	if (ctx.cr0.eq) goto loc_8215E9F8;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lwz r11,-12292(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -12292);
	// andc r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 & ~ctx.r11.u64;
	// rlwinm. r11,r11,0,24,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8215e9f8
	if (!ctx.cr0.eq) goto loc_8215E9F8;
	// li r26,1
	ctx.r26.s64 = 1;
loc_8215E9F8:
	// rlwinm. r11,r21,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8215ea0c
	if (ctx.cr0.eq) goto loc_8215EA0C;
	// oris r26,r26,1024
	ctx.r26.u64 = ctx.r26.u64 | 67108864;
	// oris r25,r25,1
	ctx.r25.u64 = ctx.r25.u64 | 65536;
	// ori r24,r24,4
	ctx.r24.u64 = ctx.r24.u64 | 4;
loc_8215EA0C:
	// rlwinm. r11,r21,0,19,19
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 0) & 0x1000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8215ea18
	if (ctx.cr0.eq) goto loc_8215EA18;
	// ori r26,r26,256
	ctx.r26.u64 = ctx.r26.u64 | 256;
loc_8215EA18:
	// rlwinm. r11,r21,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8215ea30
	if (ctx.cr0.eq) goto loc_8215EA30;
	// oris r26,r26,2048
	ctx.r26.u64 = ctx.r26.u64 | 134217728;
	// b 0x8215ea3c
	goto loc_8215EA3C;
loc_8215EA28:
	// li r31,5
	ctx.r31.s64 = 5;
	// b 0x8215e9d4
	goto loc_8215E9D4;
loc_8215EA30:
	// rlwinm. r11,r21,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8215ea3c
	if (ctx.cr0.eq) goto loc_8215EA3C;
	// oris r26,r26,4096
	ctx.r26.u64 = ctx.r26.u64 | 268435456;
loc_8215EA3C:
	// bl 0x82084eb0
	ctx.lr = 0x8215EA40;
	sub_82084EB0(ctx, base);
	// stw r3,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x8215ea74
	if (!ctx.cr6.eq) goto loc_8215EA74;
	// bl 0x8207d510
	ctx.lr = 0x8215EA50;
	sub_8207D510(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r23,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r23.u32);
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// bl 0x8207d4d8
	ctx.lr = 0x8215EA60;
	sub_8207D4D8(ctx, base);
	// li r11,24
	ctx.r11.s64 = 24;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d4d8
	ctx.lr = 0x8215EA6C;
	sub_8207D4D8(ctx, base);
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x8215ed70
	goto loc_8215ED70;
loc_8215EA74:
	// li r11,1
	ctx.r11.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x820891f8
	ctx.lr = 0x8215EA9C;
	sub_820891F8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x8215eb34
	if (!ctx.cr6.eq) goto loc_8215EB34;
	// rlwinm r11,r25,0,0,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0xC0000000;
	// cmplw cr6,r11,r20
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r20.u32, ctx.xer);
	// bne cr6,0x8215eaec
	if (!ctx.cr6.eq) goto loc_8215EAEC;
	// clrlwi. r11,r21,31
	ctx.r11.u64 = ctx.r21.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8215eaec
	if (ctx.cr0.eq) goto loc_8215EAEC;
	// clrlwi r25,r25,1
	ctx.r25.u64 = ctx.r25.u32 & 0x7FFFFFFF;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x820891f8
	ctx.lr = 0x8215EAE0;
	sub_820891F8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x8215eb34
	if (!ctx.cr6.eq) goto loc_8215EB34;
loc_8215EAEC:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// srawi r9,r11,5
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1F) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 5;
	// addi r10,r10,-23360
	ctx.r10.s64 = ctx.r10.s64 + -23360;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r11,r11,27
	ctx.r11.u64 = ctx.r11.u32 & 0x1F;
	// mulli r11,r11,72
	ctx.r11.s64 = ctx.r11.s64 * 72;
	// lwzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// rlwinm r10,r10,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// stb r10,4(r11)
	PPC_STORE_U8(ctx.r11.u32 + 4, ctx.r10.u8);
	// bl 0x82089a10
	ctx.lr = 0x8215EB24;
	sub_82089A10(ctx, base);
	// bl 0x8207d548
	ctx.lr = 0x8215EB28;
	sub_8207D548(ctx, base);
loc_8215EB28:
	// bl 0x8207d4d8
	ctx.lr = 0x8215EB2C;
	sub_8207D4D8(ctx, base);
	// lwz r23,0(r3)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x8215ed6c
	goto loc_8215ED6C;
loc_8215EB34:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x82084b90
	ctx.lr = 0x8215EB40;
	sub_82084B90(ctx, base);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// srawi r9,r10,5
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1F) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 5;
	// addi r31,r11,-23360
	ctx.r31.s64 = ctx.r11.s64 + -23360;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r10,r10,27
	ctx.r10.u64 = ctx.r10.u32 & 0x1F;
	// ori r11,r27,1
	ctx.r11.u64 = ctx.r27.u64 | 1;
	// mulli r10,r10,72
	ctx.r10.s64 = ctx.r10.s64 * 72;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// andi. r30,r11,72
	ctx.r30.u64 = ctx.r11.u64 & 72;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// lwzx r9,r9,r31
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// cmpwi r30,0
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stb r11,4(r10)
	PPC_STORE_U8(ctx.r10.u32 + 4, ctx.r11.u8);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// srawi r9,r10,5
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1F) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 5;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r10,r10,27
	ctx.r10.u64 = ctx.r10.u32 & 0x1F;
	// mulli r10,r10,72
	ctx.r10.s64 = ctx.r10.s64 * 72;
	// lwzx r9,r9,r31
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lbz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 40);
	// clrlwi r9,r9,31
	ctx.r9.u64 = ctx.r9.u32 & 0x1;
	// stb r9,40(r10)
	PPC_STORE_U8(ctx.r10.u32 + 40, ctx.r9.u8);
	// bne 0x8215ec40
	if (!ctx.cr0.eq) goto loc_8215EC40;
	// rlwinm. r11,r11,0,24,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8215ec40
	if (ctx.cr0.eq) goto loc_8215EC40;
	// rlwinm. r11,r21,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8215ec40
	if (ctx.cr0.eq) goto loc_8215EC40;
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x8215df00
	ctx.lr = 0x8215EBC4;
	sub_8215DF00(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x8215ebec
	if (!ctx.cr6.eq) goto loc_8215EBEC;
	// bl 0x8207d510
	ctx.lr = 0x8215EBD4;
	sub_8207D510(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,131
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 131, ctx.xer);
	// beq cr6,0x8215ec40
	if (ctx.cr6.eq) goto loc_8215EC40;
loc_8215EBE0:
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x82085a18
	ctx.lr = 0x8215EBE8;
	sub_82085A18(ctx, base);
	// b 0x8215eb28
	goto loc_8215EB28;
loc_8215EBEC:
	// stb r23,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r23.u8);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x8215d708
	ctx.lr = 0x8215EC00;
	sub_8215D708(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8215ec28
	if (!ctx.cr0.eq) goto loc_8215EC28;
	// lbz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,26
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 26, ctx.xer);
	// bne cr6,0x8215ec28
	if (!ctx.cr6.eq) goto loc_8215EC28;
	// extsw r4,r27
	ctx.r4.s64 = ctx.r27.s32;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x8215f3a0
	ctx.lr = 0x8215EC20;
	sub_8215F3A0(ctx, base);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8215ebe0
	if (ctx.cr6.eq) goto loc_8215EBE0;
loc_8215EC28:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8215df00
	ctx.lr = 0x8215EC38;
	sub_8215DF00(ctx, base);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8215ebe0
	if (ctx.cr6.eq) goto loc_8215EBE0;
loc_8215EC40:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// srawi r10,r11,5
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 5;
	// clrlwi r11,r11,27
	ctx.r11.u64 = ctx.r11.u32 & 0x1F;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mulli r11,r11,72
	ctx.r11.s64 = ctx.r11.s64 * 72;
	// lwzx r10,r10,r31
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lbz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 40);
	// clrlwi r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	// stb r10,40(r11)
	PPC_STORE_U8(ctx.r11.u32 + 40, ctx.r10.u8);
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// srawi r10,r11,5
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 5;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r11,r11,27
	ctx.r11.u64 = ctx.r11.u32 & 0x1F;
	// mulli r11,r11,72
	ctx.r11.s64 = ctx.r11.s64 * 72;
	// lwzx r10,r10,r31
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lbz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 40);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// rlwinm r10,r10,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// stb r10,40(r11)
	PPC_STORE_U8(ctx.r11.u32 + 40, ctx.r10.u8);
	// bne cr6,0x8215eccc
	if (!ctx.cr6.eq) goto loc_8215ECCC;
	// rlwinm. r11,r21,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8215eccc
	if (ctx.cr0.eq) goto loc_8215ECCC;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// srawi r10,r11,5
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 5;
	// clrlwi r11,r11,27
	ctx.r11.u64 = ctx.r11.u32 & 0x1F;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mulli r11,r11,72
	ctx.r11.s64 = ctx.r11.s64 * 72;
	// lwzx r10,r10,r31
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// ori r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 | 32;
	// stb r10,4(r11)
	PPC_STORE_U8(ctx.r11.u32 + 4, ctx.r10.u8);
loc_8215ECCC:
	// rlwinm r11,r25,0,0,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0xC0000000;
	// cmplw cr6,r11,r20
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r20.u32, ctx.xer);
	// bne cr6,0x8215ed6c
	if (!ctx.cr6.eq) goto loc_8215ED6C;
	// clrlwi. r11,r21,31
	ctx.r11.u64 = ctx.r21.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8215ed6c
	if (ctx.cr0.eq) goto loc_8215ED6C;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82088d00
	ctx.lr = 0x8215ECE8;
	sub_82088D00(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// clrlwi r4,r25,1
	ctx.r4.u64 = ctx.r25.u32 & 0x7FFFFFFF;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x820891f8
	ctx.lr = 0x8215ED08;
	sub_820891F8(ctx, base);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x8215ed50
	if (!ctx.cr6.eq) goto loc_8215ED50;
	// bl 0x82089a10
	ctx.lr = 0x8215ED14;
	sub_82089A10(ctx, base);
	// bl 0x8207d548
	ctx.lr = 0x8215ED18;
	sub_8207D548(ctx, base);
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// srawi r10,r11,5
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 5;
	// clrlwi r11,r11,27
	ctx.r11.u64 = ctx.r11.u32 & 0x1F;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mulli r11,r11,72
	ctx.r11.s64 = ctx.r11.s64 * 72;
	// lwzx r10,r10,r31
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// rlwinm r10,r10,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// stb r10,4(r11)
	PPC_STORE_U8(ctx.r11.u32 + 4, ctx.r10.u8);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x82084c18
	ctx.lr = 0x8215ED4C;
	sub_82084C18(ctx, base);
	// b 0x8215eb28
	goto loc_8215EB28;
loc_8215ED50:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// srawi r10,r11,5
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 5;
	// clrlwi r11,r11,27
	ctx.r11.u64 = ctx.r11.u32 & 0x1F;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mulli r11,r11,72
	ctx.r11.s64 = ctx.r11.s64 * 72;
	// lwzx r10,r10,r31
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// stwx r3,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + ctx.r11.u32, ctx.r3.u32);
loc_8215ED6C:
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
loc_8215ED70:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9b8
	__restgprlr_20(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215ED78"))) PPC_WEAK_FUNC(sub_8215ED78);
PPC_FUNC_IMPL(__imp__sub_8215ED78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lwz r16,21428(r29)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r29.u32 + 21428);
	// lwz r16,7624(r5)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r5.u32 + 7624);
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
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// stw r7,164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 164, ctx.r7.u32);
	// addic r11,r7,-1
	ctx.xer.ca = ctx.r7.u32 > 0;
	ctx.r11.s64 = ctx.r7.s64 + -1;
	// li r10,0
	ctx.r10.s64 = 0;
	// subfe. r11,r11,r7
	temp.u8 = (~ctx.r11.u32 + ctx.r7.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r7.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r7.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r10,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r10.u32);
	// bne 0x8215ede0
	if (!ctx.cr0.eq) goto loc_8215EDE0;
loc_8215EDB4:
	// bl 0x8207d4d8
	ctx.lr = 0x8215EDB8;
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
	ctx.lr = 0x8215EDD8;
	sub_8207D940(ctx, base);
	// li r3,22
	ctx.r3.s64 = 22;
	// b 0x8215ee58
	goto loc_8215EE58;
loc_8215EDE0:
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
	// stw r10,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// beq 0x8215edb4
	if (ctx.cr0.eq) goto loc_8215EDB4;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x8215ee0c
	if (ctx.cr6.eq) goto loc_8215EE0C;
	// rlwinm r11,r6,0,25,22
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFFFFFFFE7F;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm. r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8215edb4
	if (ctx.cr0.eq) goto loc_8215EDB4;
loc_8215EE0C:
	// nop 
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r31,80
	ctx.r3.s64 = ctx.r31.s64 + 80;
	// bl 0x8215e848
	ctx.lr = 0x8215EE30;
	sub_8215E848(ctx, base);
	// stw r3,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r3.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,112
	ctx.r12.s64 = ctx.r31.s64 + 112;
	// bl 0x8215ee90
	ctx.lr = 0x8215EE40;
	sub_8215EE90(ctx, base);
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8215ee58
	if (ctx.cr6.eq) goto loc_8215EE58;
	// lwz r11,164(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 164);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_8215EE58:
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

__attribute__((alias("__imp__sub_8215ED80"))) PPC_WEAK_FUNC(sub_8215ED80);
PPC_FUNC_IMPL(__imp__sub_8215ED80) {
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
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// stw r7,164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 164, ctx.r7.u32);
	// addic r11,r7,-1
	ctx.xer.ca = ctx.r7.u32 > 0;
	ctx.r11.s64 = ctx.r7.s64 + -1;
	// li r10,0
	ctx.r10.s64 = 0;
	// subfe. r11,r11,r7
	temp.u8 = (~ctx.r11.u32 + ctx.r7.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r7.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r7.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r10,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r10.u32);
	// bne 0x8215ede0
	if (!ctx.cr0.eq) goto loc_8215EDE0;
loc_8215EDB4:
	// bl 0x8207d4d8
	ctx.lr = 0x8215EDB8;
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
	ctx.lr = 0x8215EDD8;
	sub_8207D940(ctx, base);
	// li r3,22
	ctx.r3.s64 = 22;
	// b 0x8215ee58
	goto loc_8215EE58;
loc_8215EDE0:
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
	// stw r10,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// beq 0x8215edb4
	if (ctx.cr0.eq) goto loc_8215EDB4;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x8215ee0c
	if (ctx.cr6.eq) goto loc_8215EE0C;
	// rlwinm r11,r6,0,25,22
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFFFFFFFE7F;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm. r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8215edb4
	if (ctx.cr0.eq) goto loc_8215EDB4;
loc_8215EE0C:
	// nop 
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r31,80
	ctx.r3.s64 = ctx.r31.s64 + 80;
	// bl 0x8215e848
	ctx.lr = 0x8215EE30;
	sub_8215E848(ctx, base);
	// stw r3,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r3.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,112
	ctx.r12.s64 = ctx.r31.s64 + 112;
	// bl 0x8215ee90
	ctx.lr = 0x8215EE40;
	sub_8215EE90(ctx, base);
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8215ee58
	if (ctx.cr6.eq) goto loc_8215EE58;
	// lwz r11,164(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 164);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_8215EE58:
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

__attribute__((alias("__imp__sub_8215EE70"))) PPC_WEAK_FUNC(sub_8215EE70);
PPC_FUNC_IMPL(__imp__sub_8215EE70) {
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
	// lwz r30,164(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 164);
	// b 0x8215eea8
	goto loc_8215EEA8;
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
loc_8215EEA8:
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8215ef00
	if (ctx.cr6.eq) goto loc_8215EF00;
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8215eef8
	if (ctx.cr6.eq) goto loc_8215EEF8;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// srawi r9,r11,5
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1F) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 5;
	// addi r10,r10,-23360
	ctx.r10.s64 = ctx.r10.s64 + -23360;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r11,r11,27
	ctx.r11.u64 = ctx.r11.u32 & 0x1F;
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
	// rlwinm r10,r10,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// stb r10,4(r11)
	PPC_STORE_U8(ctx.r11.u32 + 4, ctx.r10.u8);
loc_8215EEF8:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x82084e80
	ctx.lr = 0x8215EF00;
	sub_82084E80(ctx, base);
loc_8215EF00:
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

__attribute__((alias("__imp__sub_8215EE90"))) PPC_WEAK_FUNC(sub_8215EE90);
PPC_FUNC_IMPL(__imp__sub_8215EE90) {
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
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8215ef00
	if (ctx.cr6.eq) goto loc_8215EF00;
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8215eef8
	if (ctx.cr6.eq) goto loc_8215EEF8;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// srawi r9,r11,5
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1F) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 5;
	// addi r10,r10,-23360
	ctx.r10.s64 = ctx.r10.s64 + -23360;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r11,r11,27
	ctx.r11.u64 = ctx.r11.u32 & 0x1F;
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
	// rlwinm r10,r10,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// stb r10,4(r11)
	PPC_STORE_U8(ctx.r11.u32 + 4, ctx.r10.u8);
loc_8215EEF8:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x82084e80
	ctx.lr = 0x8215EF00;
	sub_82084E80(ctx, base);
loc_8215EF00:
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

__attribute__((alias("__imp__sub_8215EF18"))) PPC_WEAK_FUNC(sub_8215EF18);
PPC_FUNC_IMPL(__imp__sub_8215EF18) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x8215ed80
	sub_8215ED80(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215EF38"))) PPC_WEAK_FUNC(sub_8215EF38);
PPC_FUNC_IMPL(__imp__sub_8215EF38) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lwz r16,21428(r29)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r29.u32 + 21428);
	// lwz r16,7648(r5)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r5.u32 + 7648);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x8215EF48;
	__savegprlr_25(ctx, base);
	// addi r31,r1,-160
	ctx.r31.s64 = ctx.r1.s64 + -160;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r26,0
	ctx.r26.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// mr r27,r26
	ctx.r27.u64 = ctx.r26.u64;
	// stw r26,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r26.u32);
	// bl 0x8207d808
	ctx.lr = 0x8215EF64;
	sub_8207D808(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r28,r26
	ctx.r28.u64 = ctx.r26.u64;
	// lis r29,-32224
	ctx.r29.s64 = -2111832064;
	// lis r25,-32224
	ctx.r25.s64 = -2111832064;
loc_8215EF74:
	// stw r28,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r28.u32);
	// lwz r11,-23084(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + -23084);
	// cmpw cr6,r28,r11
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x8215f088
	if (!ctx.cr6.lt) goto loc_8215F088;
	// lwz r11,-23088(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -23088);
	// rlwinm r30,r28,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r30,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8215f01c
	if (ctx.cr6.eq) goto loc_8215F01C;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// andi. r10,r11,131
	ctx.r10.u64 = ctx.r11.u64 & 131;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// cmpwi r10,0
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8215f004
	if (!ctx.cr0.eq) goto loc_8215F004;
	// rlwinm. r11,r11,0,16,16
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8215f004
	if (!ctx.cr0.eq) goto loc_8215F004;
	// cmpwi cr6,r28,2
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 2, ctx.xer);
	// ble cr6,0x8215efd4
	if (!ctx.cr6.gt) goto loc_8215EFD4;
	// cmpwi cr6,r28,20
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 20, ctx.xer);
	// bge cr6,0x8215efd4
	if (!ctx.cr6.lt) goto loc_8215EFD4;
	// addi r3,r28,16
	ctx.r3.s64 = ctx.r28.s64 + 16;
	// bl 0x8207d6c8
	ctx.lr = 0x8215EFCC;
	sub_8207D6C8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8215f088
	if (ctx.cr0.eq) goto loc_8215F088;
loc_8215EFD4:
	// lwz r11,-23088(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -23088);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwzx r4,r30,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// bl 0x8207c4a0
	ctx.lr = 0x8215EFE4;
	sub_8207C4A0(ctx, base);
	// lwz r11,-23088(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -23088);
	// lwzx r4,r30,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// lwz r11,12(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// andi. r11,r11,131
	ctx.r11.u64 = ctx.r11.u64 & 131;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8215f010
	if (ctx.cr0.eq) goto loc_8215F010;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8207c530
	ctx.lr = 0x8215F004;
	sub_8207C530(ctx, base);
loc_8215F004:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// b 0x8215ef74
	goto loc_8215EF74;
loc_8215F010:
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// stw r4,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r4.u32);
	// b 0x8215f088
	goto loc_8215F088;
loc_8215F01C:
	// li r3,60
	ctx.r3.s64 = 60;
	// bl 0x8207a400
	ctx.lr = 0x8215F024;
	sub_8207A400(ctx, base);
	// lwz r11,-23088(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -23088);
	// stwx r3,r30,r11
	PPC_STORE_U32(ctx.r30.u32 + ctx.r11.u32, ctx.r3.u32);
	// lwz r11,-23088(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -23088);
	// lwzx r10,r30,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8215f088
	if (ctx.cr6.eq) goto loc_8215F088;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// li r4,4000
	ctx.r4.s64 = 4000;
	// addi r3,r11,32
	ctx.r3.s64 = ctx.r11.s64 + 32;
	// bl 0x82082610
	ctx.lr = 0x8215F04C;
	sub_82082610(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// lwz r11,-23088(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -23088);
	// bne 0x8215f06c
	if (!ctx.cr0.eq) goto loc_8215F06C;
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// bl 0x8207c068
	ctx.lr = 0x8215F060;
	sub_8207C068(ctx, base);
	// lwz r11,-23088(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -23088);
	// stwx r26,r30,r11
	PPC_STORE_U32(ctx.r30.u32 + ctx.r11.u32, ctx.r26.u32);
	// b 0x8215f088
	goto loc_8215F088;
loc_8215F06C:
	// lwzx r11,r30,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// addi r3,r11,32
	ctx.r3.s64 = ctx.r11.s64 + 32;
	// bl 0x821d5384
	ctx.lr = 0x8215F078;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,-23088(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -23088);
	// lwzx r27,r30,r11
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// stw r27,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r27.u32);
	// stw r26,12(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12, ctx.r26.u32);
loc_8215F088:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x8215f0b4
	if (ctx.cr6.eq) goto loc_8215F0B4;
	// lwz r11,12(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// li r10,-1
	ctx.r10.s64 = -1;
	// rlwinm r11,r11,0,16,16
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000;
	// stw r11,12(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12, ctx.r11.u32);
	// stw r26,4(r27)
	PPC_STORE_U32(ctx.r27.u32 + 4, ctx.r26.u32);
	// stw r26,8(r27)
	PPC_STORE_U32(ctx.r27.u32 + 8, ctx.r26.u32);
	// stw r26,0(r27)
	PPC_STORE_U32(ctx.r27.u32 + 0, ctx.r26.u32);
	// stw r26,28(r27)
	PPC_STORE_U32(ctx.r27.u32 + 28, ctx.r26.u32);
	// stw r10,16(r27)
	PPC_STORE_U32(ctx.r27.u32 + 16, ctx.r10.u32);
loc_8215F0B4:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,160
	ctx.r12.s64 = ctx.r31.s64 + 160;
	// bl 0x8215f0cc
	ctx.lr = 0x8215F0C0;
	sub_8215F0CC(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// addi r1,r31,160
	ctx.r1.s64 = ctx.r31.s64 + 160;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215EF40"))) PPC_WEAK_FUNC(sub_8215EF40);
PPC_FUNC_IMPL(__imp__sub_8215EF40) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x8215EF48;
	__savegprlr_25(ctx, base);
	// addi r31,r1,-160
	ctx.r31.s64 = ctx.r1.s64 + -160;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r26,0
	ctx.r26.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// mr r27,r26
	ctx.r27.u64 = ctx.r26.u64;
	// stw r26,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r26.u32);
	// bl 0x8207d808
	ctx.lr = 0x8215EF64;
	sub_8207D808(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r28,r26
	ctx.r28.u64 = ctx.r26.u64;
	// lis r29,-32224
	ctx.r29.s64 = -2111832064;
	// lis r25,-32224
	ctx.r25.s64 = -2111832064;
loc_8215EF74:
	// stw r28,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r28.u32);
	// lwz r11,-23084(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + -23084);
	// cmpw cr6,r28,r11
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x8215f088
	if (!ctx.cr6.lt) goto loc_8215F088;
	// lwz r11,-23088(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -23088);
	// rlwinm r30,r28,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r30,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8215f01c
	if (ctx.cr6.eq) goto loc_8215F01C;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// andi. r10,r11,131
	ctx.r10.u64 = ctx.r11.u64 & 131;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// cmpwi r10,0
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8215f004
	if (!ctx.cr0.eq) goto loc_8215F004;
	// rlwinm. r11,r11,0,16,16
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8215f004
	if (!ctx.cr0.eq) goto loc_8215F004;
	// cmpwi cr6,r28,2
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 2, ctx.xer);
	// ble cr6,0x8215efd4
	if (!ctx.cr6.gt) goto loc_8215EFD4;
	// cmpwi cr6,r28,20
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 20, ctx.xer);
	// bge cr6,0x8215efd4
	if (!ctx.cr6.lt) goto loc_8215EFD4;
	// addi r3,r28,16
	ctx.r3.s64 = ctx.r28.s64 + 16;
	// bl 0x8207d6c8
	ctx.lr = 0x8215EFCC;
	sub_8207D6C8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8215f088
	if (ctx.cr0.eq) goto loc_8215F088;
loc_8215EFD4:
	// lwz r11,-23088(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -23088);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwzx r4,r30,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// bl 0x8207c4a0
	ctx.lr = 0x8215EFE4;
	sub_8207C4A0(ctx, base);
	// lwz r11,-23088(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -23088);
	// lwzx r4,r30,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// lwz r11,12(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// andi. r11,r11,131
	ctx.r11.u64 = ctx.r11.u64 & 131;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8215f010
	if (ctx.cr0.eq) goto loc_8215F010;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8207c530
	ctx.lr = 0x8215F004;
	sub_8207C530(ctx, base);
loc_8215F004:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// b 0x8215ef74
	goto loc_8215EF74;
loc_8215F010:
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// stw r4,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r4.u32);
	// b 0x8215f088
	goto loc_8215F088;
loc_8215F01C:
	// li r3,60
	ctx.r3.s64 = 60;
	// bl 0x8207a400
	ctx.lr = 0x8215F024;
	sub_8207A400(ctx, base);
	// lwz r11,-23088(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -23088);
	// stwx r3,r30,r11
	PPC_STORE_U32(ctx.r30.u32 + ctx.r11.u32, ctx.r3.u32);
	// lwz r11,-23088(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -23088);
	// lwzx r10,r30,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8215f088
	if (ctx.cr6.eq) goto loc_8215F088;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// li r4,4000
	ctx.r4.s64 = 4000;
	// addi r3,r11,32
	ctx.r3.s64 = ctx.r11.s64 + 32;
	// bl 0x82082610
	ctx.lr = 0x8215F04C;
	sub_82082610(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// lwz r11,-23088(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -23088);
	// bne 0x8215f06c
	if (!ctx.cr0.eq) goto loc_8215F06C;
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// bl 0x8207c068
	ctx.lr = 0x8215F060;
	sub_8207C068(ctx, base);
	// lwz r11,-23088(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -23088);
	// stwx r26,r30,r11
	PPC_STORE_U32(ctx.r30.u32 + ctx.r11.u32, ctx.r26.u32);
	// b 0x8215f088
	goto loc_8215F088;
loc_8215F06C:
	// lwzx r11,r30,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// addi r3,r11,32
	ctx.r3.s64 = ctx.r11.s64 + 32;
	// bl 0x821d5384
	ctx.lr = 0x8215F078;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,-23088(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -23088);
	// lwzx r27,r30,r11
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// stw r27,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r27.u32);
	// stw r26,12(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12, ctx.r26.u32);
loc_8215F088:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x8215f0b4
	if (ctx.cr6.eq) goto loc_8215F0B4;
	// lwz r11,12(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// li r10,-1
	ctx.r10.s64 = -1;
	// rlwinm r11,r11,0,16,16
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000;
	// stw r11,12(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12, ctx.r11.u32);
	// stw r26,4(r27)
	PPC_STORE_U32(ctx.r27.u32 + 4, ctx.r26.u32);
	// stw r26,8(r27)
	PPC_STORE_U32(ctx.r27.u32 + 8, ctx.r26.u32);
	// stw r26,0(r27)
	PPC_STORE_U32(ctx.r27.u32 + 0, ctx.r26.u32);
	// stw r26,28(r27)
	PPC_STORE_U32(ctx.r27.u32 + 28, ctx.r26.u32);
	// stw r10,16(r27)
	PPC_STORE_U32(ctx.r27.u32 + 16, ctx.r10.u32);
loc_8215F0B4:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,160
	ctx.r12.s64 = ctx.r31.s64 + 160;
	// bl 0x8215f0cc
	ctx.lr = 0x8215F0C0;
	sub_8215F0CC(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// addi r1,r31,160
	ctx.r1.s64 = ctx.r31.s64 + 160;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215F0CC"))) PPC_WEAK_FUNC(sub_8215F0CC);
PPC_FUNC_IMPL(__imp__sub_8215F0CC) {
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
	ctx.lr = 0x8215F0E0;
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

__attribute__((alias("__imp__sub_8215F0F0"))) PPC_WEAK_FUNC(sub_8215F0F0);
PPC_FUNC_IMPL(__imp__sub_8215F0F0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8215F0F8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8215f14c
	if (ctx.cr6.eq) goto loc_8215F14C;
	// li r11,-4096
	ctx.r11.s64 = -4096;
	// twllei r4,0
	// divwu r11,r11,r4
	ctx.r11.u32 = ppc_divwu(ctx.r11.u32, ctx.r4.u32);
	// cmplw cr6,r11,r5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r5.u32, ctx.xer);
	// bge cr6,0x8215f14c
	if (!ctx.cr6.lt) goto loc_8215F14C;
	// bl 0x8207d4d8
	ctx.lr = 0x8215F124;
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
	ctx.lr = 0x8215F144;
	sub_8207D940(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8215f194
	goto loc_8215F194;
loc_8215F14C:
	// mullw r30,r4,r5
	ctx.r30.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r5.s32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8215f164
	if (ctx.cr6.eq) goto loc_8215F164;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207e0e0
	ctx.lr = 0x8215F160;
	sub_8207E0E0(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
loc_8215F164:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207dff0
	ctx.lr = 0x8215F170;
	sub_8207DFF0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x8215f190
	if (ctx.cr0.eq) goto loc_8215F190;
	// cmplw cr6,r29,r30
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r30.u32, ctx.xer);
	// bge cr6,0x8215f190
	if (!ctx.cr6.lt) goto loc_8215F190;
	// subf r5,r29,r30
	ctx.r5.s64 = ctx.r30.s64 - ctx.r29.s64;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r3,r29,r31
	ctx.r3.u64 = ctx.r29.u64 + ctx.r31.u64;
	// bl 0x8207da20
	ctx.lr = 0x8215F190;
	sub_8207DA20(ctx, base);
loc_8215F190:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8215F194:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215F19C"))) PPC_WEAK_FUNC(sub_8215F19C);
PPC_FUNC_IMPL(__imp__sub_8215F19C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8215F1A0"))) PPC_WEAK_FUNC(sub_8215F1A0);
PPC_FUNC_IMPL(__imp__sub_8215F1A0) {
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
	// lwz r11,12(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// rlwinm. r11,r11,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8215f298
	if (!ctx.cr0.eq) goto loc_8215F298;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x820809e8
	ctx.lr = 0x8215F1D0;
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
	// beq cr6,0x8215f20c
	if (ctx.cr6.eq) goto loc_8215F20C;
	// cmpwi cr6,r3,-2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -2, ctx.xer);
	// beq cr6,0x8215f20c
	if (ctx.cr6.eq) goto loc_8215F20C;
	// srawi r10,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 5;
	// clrlwi r9,r3,27
	ctx.r9.u64 = ctx.r3.u32 & 0x1F;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mulli r9,r9,72
	ctx.r9.s64 = ctx.r9.s64 * 72;
	// lwzx r10,r10,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// b 0x8215f210
	goto loc_8215F210;
loc_8215F20C:
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
loc_8215F210:
	// lbz r10,40(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 40);
	// rlwinm. r10,r10,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8215f258
	if (!ctx.cr0.eq) goto loc_8215F258;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8215f248
	if (ctx.cr6.eq) goto loc_8215F248;
	// cmpwi cr6,r3,-2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -2, ctx.xer);
	// beq cr6,0x8215f248
	if (ctx.cr6.eq) goto loc_8215F248;
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
	// b 0x8215f24c
	goto loc_8215F24C;
loc_8215F248:
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
loc_8215F24C:
	// lbz r11,40(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 40);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8215f298
	if (ctx.cr0.eq) goto loc_8215F298;
loc_8215F258:
	// bl 0x8207d4d8
	ctx.lr = 0x8215F25C;
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
	ctx.lr = 0x8215F27C;
	sub_8207D940(ctx, base);
loc_8215F27C:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_8215F280:
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
loc_8215F298:
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// beq cr6,0x8215f27c
	if (ctx.cr6.eq) goto loc_8215F27C;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// clrlwi. r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8215f2bc
	if (!ctx.cr0.eq) goto loc_8215F2BC;
	// rlwinm. r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8215f27c
	if (ctx.cr0.eq) goto loc_8215F27C;
	// rlwinm. r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8215f27c
	if (!ctx.cr0.eq) goto loc_8215F27C;
loc_8215F2BC:
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8215f2d0
	if (!ctx.cr6.eq) goto loc_8215F2D0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820829f8
	ctx.lr = 0x8215F2D0;
	sub_820829F8(ctx, base);
loc_8215F2D0:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8215f2f4
	if (!ctx.cr6.eq) goto loc_8215F2F4;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8215f27c
	if (!ctx.cr6.eq) goto loc_8215F27C;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_8215F2F4:
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// rlwinm. r11,r11,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// beq 0x8215f32c
	if (ctx.cr0.eq) goto loc_8215F32C;
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// extsb r10,r30
	ctx.r10.s64 = ctx.r30.s8;
	// extsb r9,r9
	ctx.r9.s64 = ctx.r9.s8;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x8215f330
	if (ctx.cr6.eq) goto loc_8215F330;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// b 0x8215f27c
	goto loc_8215F27C;
loc_8215F32C:
	// stb r30,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r30.u8);
loc_8215F330:
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// clrlwi r3,r30,24
	ctx.r3.u64 = ctx.r30.u32 & 0xFF;
	// rlwimi r10,r9,0,31,31
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 0) & 0x1) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFFE);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwimi r10,r9,0,27,27
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 0) & 0x10) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFEF);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// stw r10,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r10.u32);
	// b 0x8215f280
	goto loc_8215F280;
}

__attribute__((alias("__imp__sub_8215F358"))) PPC_WEAK_FUNC(sub_8215F358);
PPC_FUNC_IMPL(__imp__sub_8215F358) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8215f384
	if (ctx.cr6.eq) goto loc_8215F384;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x8215f384
	if (ctx.cr6.eq) goto loc_8215F384;
	// lbz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8215f38c
	if (!ctx.cr0.eq) goto loc_8215F38C;
	// beq cr6,0x8215f384
	if (ctx.cr6.eq) goto loc_8215F384;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r11,0(r3)
	PPC_STORE_U16(ctx.r3.u32 + 0, ctx.r11.u16);
loc_8215F384:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8215F38C:
	// beq cr6,0x8215f398
	if (ctx.cr6.eq) goto loc_8215F398;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// sth r11,0(r3)
	PPC_STORE_U16(ctx.r3.u32 + 0, ctx.r11.u16);
loc_8215F398:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8215F3A0"))) PPC_WEAK_FUNC(sub_8215F3A0);
PPC_FUNC_IMPL(__imp__sub_8215F3A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x8215F3A8;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r27,0
	ctx.r27.s64 = 0;
	// bl 0x82082790
	ctx.lr = 0x8215F3C4;
	sub_82082790(ctx, base);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// cmpdi cr6,r3,-1
	ctx.cr6.compare<int64_t>(ctx.r3.s64, -1, ctx.xer);
	// beq cr6,0x8215f418
	if (ctx.cr6.eq) goto loc_8215F418;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82082790
	ctx.lr = 0x8215F3E0;
	sub_82082790(ctx, base);
	// cmpdi cr6,r3,-1
	ctx.cr6.compare<int64_t>(ctx.r3.s64, -1, ctx.xer);
	// beq cr6,0x8215f418
	if (ctx.cr6.eq) goto loc_8215F418;
	// subf r30,r3,r29
	ctx.r30.s64 = ctx.r29.s64 - ctx.r3.s64;
	// cmpdi cr6,r30,0
	ctx.cr6.compare<int64_t>(ctx.r30.s64, 0, ctx.xer);
	// ble cr6,0x8215f4b4
	if (!ctx.cr6.gt) goto loc_8215F4B4;
	// bl 0x8208d8f8
	ctx.lr = 0x8215F3F8;
	sub_8208D8F8(ctx, base);
	// li r4,8
	ctx.r4.s64 = 8;
	// li r5,4096
	ctx.r5.s64 = 4096;
	// bl 0x8208c458
	ctx.lr = 0x8215F404;
	sub_8208C458(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne 0x8215f428
	if (!ctx.cr0.eq) goto loc_8215F428;
	// bl 0x8207d4d8
	ctx.lr = 0x8215F410;
	sub_8207D4D8(ctx, base);
	// li r11,12
	ctx.r11.s64 = 12;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
loc_8215F418:
	// bl 0x8207d4d8
	ctx.lr = 0x8215F41C;
	sub_8207D4D8(ctx, base);
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
loc_8215F420:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
loc_8215F428:
	// lis r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// ori r4,r4,32768
	ctx.r4.u64 = ctx.r4.u64 | 32768;
	// bl 0x8215f530
	ctx.lr = 0x8215F438;
	sub_8215F530(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
loc_8215F43C:
	// cmpdi cr6,r30,4096
	ctx.cr6.compare<int64_t>(ctx.r30.s64, 4096, ctx.xer);
	// li r5,4096
	ctx.r5.s64 = 4096;
	// bge cr6,0x8215f44c
	if (!ctx.cr6.lt) goto loc_8215F44C;
	// extsw r5,r30
	ctx.r5.s64 = ctx.r30.s32;
loc_8215F44C:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82080b30
	ctx.lr = 0x8215F458;
	sub_82080B30(ctx, base);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8215f474
	if (ctx.cr6.eq) goto loc_8215F474;
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// subf r30,r11,r30
	ctx.r30.s64 = ctx.r30.s64 - ctx.r11.s64;
	// cmpdi cr6,r30,0
	ctx.cr6.compare<int64_t>(ctx.r30.s64, 0, ctx.xer);
	// bgt cr6,0x8215f43c
	if (ctx.cr6.gt) goto loc_8215F43C;
	// b 0x8215f494
	goto loc_8215F494;
loc_8215F474:
	// bl 0x8207d510
	ctx.lr = 0x8215F478;
	sub_8207D510(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bne cr6,0x8215f490
	if (!ctx.cr6.eq) goto loc_8215F490;
	// bl 0x8207d4d8
	ctx.lr = 0x8215F488;
	sub_8207D4D8(ctx, base);
	// li r11,13
	ctx.r11.s64 = 13;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
loc_8215F490:
	// li r27,-1
	ctx.r27.s64 = -1;
loc_8215F494:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8215f530
	ctx.lr = 0x8215F4A0;
	sub_8215F530(ctx, base);
	// bl 0x8208d8f8
	ctx.lr = 0x8215F4A4;
	sub_8208D8F8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x8208cd20
	ctx.lr = 0x8215F4B0;
	sub_8208CD20(ctx, base);
	// b 0x8215f508
	goto loc_8215F508;
loc_8215F4B4:
	// bge cr6,0x8215f510
	if (!ctx.cr6.lt) goto loc_8215F510;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82082790
	ctx.lr = 0x8215F4C8;
	sub_82082790(ctx, base);
	// cmpdi cr6,r3,-1
	ctx.cr6.compare<int64_t>(ctx.r3.s64, -1, ctx.xer);
	// beq cr6,0x8215f418
	if (ctx.cr6.eq) goto loc_8215F418;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82084cb0
	ctx.lr = 0x8215F4D8;
	sub_82084CB0(ctx, base);
	// bl 0x8215f8f0
	ctx.lr = 0x8215F4DC;
	sub_8215F8F0(ctx, base);
	// addic r11,r3,-1
	ctx.xer.ca = ctx.r3.u32 > 0;
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// subfe r27,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r27.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// cmpdi cr6,r27,-1
	ctx.cr6.compare<int64_t>(ctx.r27.s64, -1, ctx.xer);
	// bne cr6,0x8215f510
	if (!ctx.cr6.eq) goto loc_8215F510;
	// bl 0x8207d4d8
	ctx.lr = 0x8215F4F0;
	sub_8207D4D8(ctx, base);
	// li r11,13
	ctx.r11.s64 = 13;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8207d510
	ctx.lr = 0x8215F4FC;
	sub_8207D510(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x82089a10
	ctx.lr = 0x8215F504;
	sub_82089A10(ctx, base);
	// stw r3,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r3.u32);
loc_8215F508:
	// cmpdi cr6,r27,-1
	ctx.cr6.compare<int64_t>(ctx.r27.s64, -1, ctx.xer);
	// beq cr6,0x8215f418
	if (ctx.cr6.eq) goto loc_8215F418;
loc_8215F510:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82082790
	ctx.lr = 0x8215F520;
	sub_82082790(ctx, base);
	// cmpdi cr6,r3,-1
	ctx.cr6.compare<int64_t>(ctx.r3.s64, -1, ctx.xer);
	// beq cr6,0x8215f418
	if (ctx.cr6.eq) goto loc_8215F418;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8215f420
	goto loc_8215F420;
}

__attribute__((alias("__imp__sub_8215F530"))) PPC_WEAK_FUNC(sub_8215F530);
PPC_FUNC_IMPL(__imp__sub_8215F530) {
	PPC_FUNC_PROLOGUE();
	// srawi r11,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 5;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r10,-23360
	ctx.r9.s64 = ctx.r10.s64 + -23360;
	// clrlwi r11,r3,27
	ctx.r11.u64 = ctx.r3.u32 & 0x1F;
	// cmpwi cr6,r4,16384
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 16384, ctx.xer);
	// mulli r10,r11,72
	ctx.r10.s64 = ctx.r11.s64 * 72;
	// lwzx r11,r8,r9
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lbz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// rlwinm r7,r7,0,0,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFF80;
	// beq cr6,0x8215f578
	if (ctx.cr6.eq) goto loc_8215F578;
	// cmplwi cr6,r4,32768
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 32768, ctx.xer);
	// bne cr6,0x8215f5a0
	if (!ctx.cr6.eq) goto loc_8215F5A0;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// clrlwi r10,r10,25
	ctx.r10.u64 = ctx.r10.u32 & 0x7F;
	// stb r10,4(r11)
	PPC_STORE_U8(ctx.r11.u32 + 4, ctx.r10.u8);
	// b 0x8215f5a0
	goto loc_8215F5A0;
loc_8215F578:
	// lbz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// li r5,-128
	ctx.r5.s64 = -128;
	// or r6,r6,r5
	ctx.r6.u64 = ctx.r6.u64 | ctx.r5.u64;
	// stb r6,4(r11)
	PPC_STORE_U8(ctx.r11.u32 + 4, ctx.r6.u8);
	// lwzx r11,r8,r9
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lbz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 40);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// addi r10,r11,40
	ctx.r10.s64 = ctx.r11.s64 + 40;
	// stb r9,40(r11)
	PPC_STORE_U8(ctx.r11.u32 + 40, ctx.r9.u8);
loc_8215F5A0:
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne cr6,0x8215f5b4
	if (!ctx.cr6.eq) goto loc_8215F5B4;
	// lis r3,0
	ctx.r3.s64 = 0;
	// ori r3,r3,32768
	ctx.r3.u64 = ctx.r3.u64 | 32768;
	// blr 
	return;
loc_8215F5B4:
	// li r3,16384
	ctx.r3.s64 = 16384;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8215F5BC"))) PPC_WEAK_FUNC(sub_8215F5BC);
PPC_FUNC_IMPL(__imp__sub_8215F5BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8215F5C0"))) PPC_WEAK_FUNC(sub_8215F5C0);
PPC_FUNC_IMPL(__imp__sub_8215F5C0) {
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
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8215f604
	if (!ctx.cr6.eq) goto loc_8215F604;
	// bl 0x8207d4d8
	ctx.lr = 0x8215F5DC;
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
	ctx.lr = 0x8215F5FC;
	sub_8207D940(ctx, base);
	// li r3,22
	ctx.r3.s64 = 22;
	// b 0x8215f614
	goto loc_8215F614;
loc_8215F604:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,-32248(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -32248);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
loc_8215F614:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8215F624"))) PPC_WEAK_FUNC(sub_8215F624);
PPC_FUNC_IMPL(__imp__sub_8215F624) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8215F628"))) PPC_WEAK_FUNC(sub_8215F628);
PPC_FUNC_IMPL(__imp__sub_8215F628) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// oris r11,r3,544
	ctx.r11.u64 = ctx.r3.u64 | 35651584;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stfs f1,140(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lwz r9,140(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,1416(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1416);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8215f680
	if (ctx.cr6.eq) goto loc_8215F680;
	// lwz r11,24(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// li r3,67
	ctx.r3.s64 = 67;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8215F680;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8215F680:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8215F690"))) PPC_WEAK_FUNC(sub_8215F690);
PPC_FUNC_IMPL(__imp__sub_8215F690) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x8215F698;
	__savegprlr_27(ctx, base);
	// addi r31,r1,-176
	ctx.r31.s64 = ctx.r1.s64 + -176;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r5,3
	ctx.r11.s64 = ctx.r5.s64 + 3;
	// stw r4,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r4.u32);
	// lis r27,-32256
	ctx.r27.s64 = -2113929216;
	// stw r3,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r3.u32);
	// rlwinm r11,r11,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// stw r5,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r5.u32);
	// li r9,3
	ctx.r9.s64 = 3;
	// addi r29,r11,3
	ctx.r29.s64 = ctx.r11.s64 + 3;
	// stw r11,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
	// addi r11,r31,80
	ctx.r11.s64 = ctx.r31.s64 + 80;
	// stw r9,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r9.u32);
	// rlwinm r10,r29,24,0,7
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 24) & 0xFF000000;
	// stw r11,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r11,1416(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 1416);
	// ori r10,r10,98
	ctx.r10.u64 = ctx.r10.u64 | 98;
	// stw r8,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r8.u32);
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// stw r10,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r10.u32);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8215f714
	if (ctx.cr6.eq) goto loc_8215F714;
	// lwz r11,24(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// addi r4,r31,96
	ctx.r4.s64 = ctx.r31.s64 + 96;
	// li r3,94
	ctx.r3.s64 = 94;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8215F710;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x8215f718
	goto loc_8215F718;
loc_8215F714:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8215F718:
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble cr6,0x8215f728
	if (!ctx.cr6.gt) goto loc_8215F728;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8215f7a4
	goto loc_8215F7A4;
loc_8215F728:
	// blt cr6,0x8215f7a0
	if (ctx.cr6.lt) goto loc_8215F7A0;
	// rlwinm r11,r29,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
	// rlwinm r12,r11,0,0,27
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x8215c0b4
	ctx.lr = 0x8215F73C;
	sub_8215C0B4(ctx, base);
	// lwz r11,0(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r9,88(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r8,80(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// stwux r11,r1,r12
	ea = ctx.r1.u32 + ctx.r12.u32;
	PPC_STORE_U32(ea, ctx.r11.u32);
	ctx.r1.u32 = ea;
	// addi r30,r1,80
	ctx.r30.s64 = ctx.r1.s64 + 80;
	// addi r3,r30,12
	ctx.r3.s64 = ctx.r30.s64 + 12;
	// stw r8,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r8.u32);
	// stw r10,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r10.u32);
	// stw r9,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r9.u32);
	// bl 0x8207dac0
	ctx.lr = 0x8215F770;
	sub_8207DAC0(ctx, base);
	// lwz r11,1416(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 1416);
	// stw r30,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r30.u32);
	// stw r29,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r29.u32);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8215f7a0
	if (ctx.cr6.eq) goto loc_8215F7A0;
	// lwz r11,24(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// addi r4,r31,96
	ctx.r4.s64 = ctx.r31.s64 + 96;
	// li r3,67
	ctx.r3.s64 = 67;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8215F79C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x8215f7a4
	goto loc_8215F7A4;
loc_8215F7A0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8215F7A4:
	// addi r1,r31,176
	ctx.r1.s64 = ctx.r31.s64 + 176;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215F7AC"))) PPC_WEAK_FUNC(sub_8215F7AC);
PPC_FUNC_IMPL(__imp__sub_8215F7AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8215F7B0"))) PPC_WEAK_FUNC(sub_8215F7B0);
PPC_FUNC_IMPL(__imp__sub_8215F7B0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r11,1416(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1416);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8215f7d8
	if (ctx.cr6.eq) goto loc_8215F7D8;
	// lwz r11,24(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,68
	ctx.r3.s64 = 68;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
loc_8215F7D8:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8215F7E0"))) PPC_WEAK_FUNC(sub_8215F7E0);
PPC_FUNC_IMPL(__imp__sub_8215F7E0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8215F7E8;
	__savegprlr_28(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// bl 0x821d5454
	ctx.lr = 0x8215F804;
	__imp__RtlInitAnsiString(ctx, base);
	// li r11,-3
	ctx.r11.s64 = -3;
	// li r10,64
	ctx.r10.s64 = 64;
	// addi r9,r1,88
	ctx.r9.s64 = ctx.r1.s64 + 88;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// lis r8,128
	ctx.r8.s64 = 8388608;
	// stw r9,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r9.u32);
	// lis r4,16
	ctx.r4.s64 = 1048576;
	// ori r8,r8,33
	ctx.r8.u64 = ctx.r8.u64 | 33;
	// li r7,3
	ctx.r7.s64 = 3;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// ori r4,r4,1
	ctx.r4.u64 = ctx.r4.u64 | 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d5444
	ctx.lr = 0x8215F840;
	__imp__NtOpenFile(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x8215f868
	if (!ctx.cr0.lt) goto loc_8215F868;
	// bl 0x8208dc98
	ctx.lr = 0x8215F84C;
	sub_8208DC98(ctx, base);
	// bl 0x82089a10
	ctx.lr = 0x8215F850;
	sub_82089A10(ctx, base);
	// cmplwi cr6,r3,2
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 2, ctx.xer);
	// bne cr6,0x8215f860
	if (!ctx.cr6.eq) goto loc_8215F860;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x8208da08
	ctx.lr = 0x8215F860;
	sub_8208DA08(ctx, base);
loc_8215F860:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8215f8e8
	goto loc_8215F8E8;
loc_8215F868:
	// li r7,3
	ctx.r7.s64 = 3;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r6,24
	ctx.r6.s64 = 24;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x821d5724
	ctx.lr = 0x8215F880;
	__imp__NtQueryVolumeInformationFile(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x821d55b4
	ctx.lr = 0x8215F88C;
	__imp__NtClose(ctx, base);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge cr6,0x8215f8a0
	if (!ctx.cr6.lt) goto loc_8215F8A0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8208dc98
	ctx.lr = 0x8215F89C;
	sub_8208DC98(ctx, base);
	// b 0x8215f860
	goto loc_8215F860;
loc_8215F8A0:
	// lwz r10,144(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// lwz r11,148(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// ld r9,136(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// mullw r11,r10,r11
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// ld r10,128(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// clrldi r8,r11,32
	ctx.r8.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// mulld r11,r9,r8
	ctx.r11.s64 = ctx.r9.s64 * ctx.r8.s64;
	// mulld r10,r10,r8
	ctx.r10.s64 = ctx.r10.s64 * ctx.r8.s64;
	// beq cr6,0x8215f8cc
	if (ctx.cr6.eq) goto loc_8215F8CC;
	// std r11,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
loc_8215F8CC:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8215f8d8
	if (ctx.cr6.eq) goto loc_8215F8D8;
	// std r10,0(r29)
	PPC_STORE_U64(ctx.r29.u32 + 0, ctx.r10.u64);
loc_8215F8D8:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8215f8e4
	if (ctx.cr6.eq) goto loc_8215F8E4;
	// std r11,0(r28)
	PPC_STORE_U64(ctx.r28.u32 + 0, ctx.r11.u64);
loc_8215F8E4:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8215F8E8:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215F8F0"))) PPC_WEAK_FUNC(sub_8215F8F0);
PPC_FUNC_IMPL(__imp__sub_8215F8F0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r7,14
	ctx.r7.s64 = 14;
	// li r6,8
	ctx.r6.s64 = 8;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x821d5714
	ctx.lr = 0x8215F918;
	__imp__NtQueryInformationFile(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8215f978
	if (ctx.cr0.lt) goto loc_8215F978;
	// ld r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r7,20
	ctx.r7.s64 = 20;
	// li r6,8
	ctx.r6.s64 = 8;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// bl 0x821d55c4
	ctx.lr = 0x8215F940;
	__imp__NtSetInformationFile(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8215f978
	if (ctx.cr0.lt) goto loc_8215F978;
	// ld r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r7,19
	ctx.r7.s64 = 19;
	// li r6,8
	ctx.r6.s64 = 8;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// std r11,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r11.u64);
	// bl 0x821d55c4
	ctx.lr = 0x8215F968;
	__imp__NtSetInformationFile(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8215f978
	if (ctx.cr0.lt) goto loc_8215F978;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8215f980
	goto loc_8215F980;
loc_8215F978:
	// bl 0x8208dc98
	ctx.lr = 0x8215F97C;
	sub_8208DC98(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8215F980:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8215F994"))) PPC_WEAK_FUNC(sub_8215F994);
PPC_FUNC_IMPL(__imp__sub_8215F994) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8215F998"))) PPC_WEAK_FUNC(sub_8215F998);
PPC_FUNC_IMPL(__imp__sub_8215F998) {
	PPC_FUNC_PROLOGUE();
	// lis r11,32767
	ctx.r11.s64 = 2147418112;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,32767
	ctx.r10.s64 = 2147418112;
	// ori r9,r11,65517
	ctx.r9.u64 = ctx.r11.u64 | 65517;
	// ori r10,r10,65475
	ctx.r10.u64 = ctx.r10.u64 | 65475;
	// mullw r8,r8,r9
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// lis r11,32767
	ctx.r11.s64 = 2147418112;
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// ori r11,r11,65535
	ctx.r11.u64 = ctx.r11.u64 | 65535;
	// lis r7,-32225
	ctx.r7.s64 = -2111897600;
	// divwu r6,r8,r11
	ctx.r6.u32 = ppc_divwu(ctx.r8.u32, ctx.r11.u32);
	// mullw r6,r6,r11
	ctx.r6.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r11.s32);
	// subf r8,r6,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r6.s64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// mullw r9,r8,r9
	ctx.r9.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// divwu r9,r10,r11
	ctx.r9.u32 = ppc_divwu(ctx.r10.u32, ctx.r11.u32);
	// mullw r11,r9,r11
	ctx.r11.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// addi r11,r7,-15352
	ctx.r11.s64 = ctx.r7.s64 + -15352;
	// rlwinm r10,r9,2,23,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x1FC;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// stwx r8,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + ctx.r11.u32, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8215F9FC"))) PPC_WEAK_FUNC(sub_8215F9FC);
PPC_FUNC_IMPL(__imp__sub_8215F9FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8215FA00"))) PPC_WEAK_FUNC(sub_8215FA00);
PPC_FUNC_IMPL(__imp__sub_8215FA00) {
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
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,259
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 259, ctx.xer);
	// bne cr6,0x8215fa6c
	if (!ctx.cr6.eq) goto loc_8215FA6C;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq cr6,0x8215fa4c
	if (ctx.cr6.eq) goto loc_8215FA4C;
	// lwz r11,16(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8215fa40
	if (ctx.cr6.eq) goto loc_8215FA40;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
loc_8215FA40:
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x82088438
	ctx.lr = 0x8215FA48;
	sub_82088438(ctx, base);
	// b 0x8215fa50
	goto loc_8215FA50;
loc_8215FA4C:
	// li r3,258
	ctx.r3.s64 = 258;
loc_8215FA50:
	// cmplwi cr6,r3,258
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 258, ctx.xer);
	// bne cr6,0x8215fa64
	if (!ctx.cr6.eq) goto loc_8215FA64;
	// li r3,996
	ctx.r3.s64 = 996;
	// bl 0x8208da08
	ctx.lr = 0x8215FA60;
	sub_8208DA08(ctx, base);
	// b 0x8215fa8c
	goto loc_8215FA8C;
loc_8215FA64:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8215fa8c
	if (!ctx.cr6.eq) goto loc_8215FA8C;
loc_8215FA6C:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8215fa88
	if (ctx.cr6.lt) goto loc_8215FA88;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8215fa90
	goto loc_8215FA90;
loc_8215FA88:
	// bl 0x8208dc98
	ctx.lr = 0x8215FA8C;
	sub_8208DC98(ctx, base);
loc_8215FA8C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8215FA90:
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

__attribute__((alias("__imp__sub_8215FAA8"))) PPC_WEAK_FUNC(sub_8215FAA8);
PPC_FUNC_IMPL(__imp__sub_8215FAA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// li r11,-1
	ctx.r11.s64 = -1;
	// stfs f1,28(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 28, temp.u32);
	// stw r3,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r3.u32);
	// rlwinm. r10,r3,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r11.u32);
	// beq 0x8215fad8
	if (ctx.cr0.eq) goto loc_8215FAD8;
	// rlwinm r11,r3,30,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 30) & 0x1;
	// rlwinm r9,r3,31,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 31) & 0x1;
	// clrlwi r10,r3,31
	ctx.r10.u64 = ctx.r3.u32 & 0x1;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r11.u32);
loc_8215FAD8:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r11.u32);
loc_8215FAE0:
	// addi r10,r3,-1
	ctx.r10.s64 = ctx.r3.s64 + -1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// and. r3,r10,r3
	ctx.r3.u64 = ctx.r10.u64 & ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8215fae0
	if (!ctx.cr0.eq) goto loc_8215FAE0;
	// lwz r10,28(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 28);
	// stfs f1,-16(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lwz r9,-16(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r11,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r11.u32);
	// stw r9,12(r5)
	PPC_STORE_U32(ctx.r5.u32 + 12, ctx.r9.u32);
	// stw r10,-16(r1)
	PPC_STORE_U32(ctx.r1.u32 + -16, ctx.r10.u32);
	// lfs f0,-16(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-16(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lwz r11,-16(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// stw r11,16(r5)
	PPC_STORE_U32(ctx.r5.u32 + 16, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8215FB20"))) PPC_WEAK_FUNC(sub_8215FB20);
PPC_FUNC_IMPL(__imp__sub_8215FB20) {
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
	// stfd f31,-32(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,36(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 36);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r31,r6
	ctx.r31.u64 = ctx.r6.u64;
	// lfs f0,-22560(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -22560);
	ctx.f0.f64 = double(temp.f32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// lfs f31,9388(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 9388);
	ctx.f31.f64 = double(temp.f32);
	// ble cr6,0x8215fb94
	if (!ctx.cr6.gt) goto loc_8215FB94;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r30,28
	ctx.r4.s64 = ctx.r30.s64 + 28;
	// addi r3,r11,24
	ctx.r3.s64 = ctx.r11.s64 + 24;
	// bl 0x82161a20
	ctx.lr = 0x8215FB78;
	sub_82161A20(ctx, base);
	// addi r4,r30,4
	ctx.r4.s64 = ctx.r30.s64 + 4;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821619f8
	ctx.lr = 0x8215FB84;
	sub_821619F8(ctx, base);
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fdivs f31,f1,f0
	ctx.f31.f64 = double(float(ctx.f1.f64 / ctx.f0.f64));
loc_8215FB94:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8207c060
	ctx.lr = 0x8215FB9C;
	sub_8207C060(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f31,-32(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8215FBCC"))) PPC_WEAK_FUNC(sub_8215FBCC);
PPC_FUNC_IMPL(__imp__sub_8215FBCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8215FBD0"))) PPC_WEAK_FUNC(sub_8215FBD0);
PPC_FUNC_IMPL(__imp__sub_8215FBD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r11,1
	ctx.r11.s64 = 1;
	// cmplwi cr6,r8,1
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1, ctx.xer);
	// ble cr6,0x8215fca8
	if (!ctx.cr6.gt) goto loc_8215FCA8;
	// addi r10,r8,-1
	ctx.r10.s64 = ctx.r8.s64 + -1;
	// cmpwi cr6,r10,4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4, ctx.xer);
	// blt cr6,0x8215fc58
	if (ctx.cr6.lt) goto loc_8215FC58;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 + 24;
loc_8215FBF4:
	// lwz r9,-16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + -16);
	// stw r9,-16(r1)
	PPC_STORE_U32(ctx.r1.u32 + -16, ctx.r9.u32);
	// lfs f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f1
	ctx.cr6.compare(ctx.f0.f64, ctx.f1.f64);
	// bgt cr6,0x8215fca8
	if (ctx.cr6.gt) goto loc_8215FCA8;
	// lwz r9,-8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8);
	// stw r9,-12(r1)
	PPC_STORE_U32(ctx.r1.u32 + -12, ctx.r9.u32);
	// lfs f0,-12(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f1
	ctx.cr6.compare(ctx.f0.f64, ctx.f1.f64);
	// bgt cr6,0x8215fc94
	if (ctx.cr6.gt) goto loc_8215FC94;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r9.u32);
	// lfs f0,-8(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f1
	ctx.cr6.compare(ctx.f0.f64, ctx.f1.f64);
	// bgt cr6,0x8215fc9c
	if (ctx.cr6.gt) goto loc_8215FC9C;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// stw r9,-4(r1)
	PPC_STORE_U32(ctx.r1.u32 + -4, ctx.r9.u32);
	// lfs f0,-4(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f1
	ctx.cr6.compare(ctx.f0.f64, ctx.f1.f64);
	// bgt cr6,0x8215fca4
	if (ctx.cr6.gt) goto loc_8215FCA4;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// addi r9,r8,-3
	ctx.r9.s64 = ctx.r8.s64 + -3;
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x8215fbf4
	if (ctx.cr6.lt) goto loc_8215FBF4;
loc_8215FC58:
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x8215fd10
	if (!ctx.cr6.lt) goto loc_8215FD10;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
loc_8215FC6C:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,-4(r1)
	PPC_STORE_U32(ctx.r1.u32 + -4, ctx.r9.u32);
	// lfs f0,-4(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f1
	ctx.cr6.compare(ctx.f0.f64, ctx.f1.f64);
	// bgt cr6,0x8215fca8
	if (ctx.cr6.gt) goto loc_8215FCA8;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8215fc6c
	if (ctx.cr6.lt) goto loc_8215FC6C;
	// b 0x8215fca8
	goto loc_8215FCA8;
loc_8215FC94:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// b 0x8215fca8
	goto loc_8215FCA8;
loc_8215FC9C:
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// b 0x8215fca8
	goto loc_8215FCA8;
loc_8215FCA4:
	// addi r11,r11,3
	ctx.r11.s64 = ctx.r11.s64 + 3;
loc_8215FCA8:
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x8215fd10
	if (!ctx.cr6.lt) goto loc_8215FD10;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r8,-4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + -4);
	// lwz r6,-8(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// stw r10,-4(r1)
	PPC_STORE_U32(ctx.r1.u32 + -4, ctx.r10.u32);
	// lfs f0,-4(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// stw r9,-4(r1)
	PPC_STORE_U32(ctx.r1.u32 + -4, ctx.r9.u32);
	// lfs f13,-4(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// stw r8,-4(r1)
	PPC_STORE_U32(ctx.r1.u32 + -4, ctx.r8.u32);
	// lfs f12,-4(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -4);
	ctx.f12.f64 = double(temp.f32);
	// stw r8,-4(r1)
	PPC_STORE_U32(ctx.r1.u32 + -4, ctx.r8.u32);
	// lfs f11,-4(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -4);
	ctx.f11.f64 = double(temp.f32);
	// stw r6,-4(r1)
	PPC_STORE_U32(ctx.r1.u32 + -4, ctx.r6.u32);
	// lfs f10,-4(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -4);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f8,f13,f12
	ctx.f8.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// fsubs f7,f0,f10
	ctx.f7.f64 = double(float(ctx.f0.f64 - ctx.f10.f64));
	// fsubs f9,f1,f10
	ctx.f9.f64 = double(float(ctx.f1.f64 - ctx.f10.f64));
	// fdivs f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 / ctx.f7.f64));
	// fmadds f1,f6,f9,f11
	ctx.f1.f64 = double(float(ctx.f6.f64 * ctx.f9.f64 + ctx.f11.f64));
	// blr 
	return;
loc_8215FD10:
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r8,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,-4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -4);
	// stw r10,-4(r1)
	PPC_STORE_U32(ctx.r1.u32 + -4, ctx.r10.u32);
	// lfs f1,-4(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -4);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8215FD2C"))) PPC_WEAK_FUNC(sub_8215FD2C);
PPC_FUNC_IMPL(__imp__sub_8215FD2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8215FD30"))) PPC_WEAK_FUNC(sub_8215FD30);
PPC_FUNC_IMPL(__imp__sub_8215FD30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8215FD38;
	__savegprlr_29(ctx, base);
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,36(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 36);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,92(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 92);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// mr r31,r6
	ctx.r31.u64 = ctx.r6.u64;
	// rlwinm r6,r5,0,29,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x4;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// lfs f2,9388(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 9388);
	ctx.f2.f64 = double(temp.f32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lfs f4,14004(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14004);
	ctx.f4.f64 = double(temp.f32);
	// li r30,2
	ctx.r30.s64 = 2;
	// lfs f3,23104(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 23104);
	ctx.f3.f64 = double(temp.f32);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// fdivs f5,f0,f13
	ctx.f5.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
	// beq cr6,0x8215fdf4
	if (ctx.cr6.eq) goto loc_8215FDF4;
	// lwz r3,80(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 80);
	// fmr f1,f5
	ctx.f1.f64 = ctx.f5.f64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8215fda4
	if (ctx.cr6.eq) goto loc_8215FDA4;
	// bl 0x8215fbd0
	ctx.lr = 0x8215FDA0;
	sub_8215FBD0(ctx, base);
	// b 0x8215fde8
	goto loc_8215FDE8;
loc_8215FDA4:
	// stfs f4,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stfs f3,80(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stfs f2,84(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stfs f4,80(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r11.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// stw r10,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r10.u32);
	// stw r8,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r8.u32);
	// stw r7,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r7.u32);
	// bl 0x8215fbd0
	ctx.lr = 0x8215FDE8;
	sub_8215FBD0(ctx, base);
loc_8215FDE8:
	// stfs f1,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
loc_8215FDF4:
	// rlwinm r11,r5,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8215fe68
	if (ctx.cr6.eq) goto loc_8215FE68;
	// lwz r3,84(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 84);
	// fmr f1,f5
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f5.f64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8215fe18
	if (ctx.cr6.eq) goto loc_8215FE18;
	// bl 0x8215fbd0
	ctx.lr = 0x8215FE14;
	sub_8215FBD0(ctx, base);
	// b 0x8215fe5c
	goto loc_8215FE5C;
loc_8215FE18:
	// stfs f4,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f3,80(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stfs f3,84(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stfs f2,84(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r10,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r10.u32);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r11.u32);
	// stw r7,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r7.u32);
	// stw r8,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// bl 0x8215fbd0
	ctx.lr = 0x8215FE5C;
	sub_8215FBD0(ctx, base);
loc_8215FE5C:
	// stfs f1,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
loc_8215FE68:
	// rlwinm r11,r5,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8215fedc
	if (ctx.cr6.eq) goto loc_8215FEDC;
	// lwz r3,88(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 88);
	// fmr f1,f5
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f5.f64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8215fe8c
	if (ctx.cr6.eq) goto loc_8215FE8C;
	// bl 0x8215fbd0
	ctx.lr = 0x8215FE88;
	sub_8215FBD0(ctx, base);
	// b 0x8215fed0
	goto loc_8215FED0;
loc_8215FE8C:
	// stfs f4,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stfs f2,96(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f4,88(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stw r30,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r30.u32);
	// stfs f2,84(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r11.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r7,96(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r8,88(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// stw r9,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// stw r8,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r8.u32);
	// stw r7,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r7.u32);
	// bl 0x8215fbd0
	ctx.lr = 0x8215FED0;
	sub_8215FBD0(ctx, base);
loc_8215FED0:
	// stfs f1,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lwz r11,96(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
loc_8215FEDC:
	// clrlwi r11,r5,31
	ctx.r11.u64 = ctx.r5.u32 & 0x1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821601d8
	if (ctx.cr6.eq) goto loc_821601D8;
	// lwz r3,72(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 72);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8215ff04
	if (ctx.cr6.eq) goto loc_8215FF04;
	// fmr f1,f5
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f5.f64;
	// bl 0x8215fbd0
	ctx.lr = 0x8215FEFC;
	sub_8215FBD0(ctx, base);
	// fmr f3,f1
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = ctx.f1.f64;
	// b 0x8215ff18
	goto loc_8215FF18;
loc_8215FF04:
	// fmr f0,f4
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f4.f64;
	// fcmpu cr6,f5,f4
	ctx.cr6.compare(ctx.f5.f64, ctx.f4.f64);
	// ble cr6,0x8215ff14
	if (!ctx.cr6.gt) goto loc_8215FF14;
	// fdivs f0,f4,f5
	ctx.f0.f64 = double(float(ctx.f4.f64 / ctx.f5.f64));
loc_8215FF14:
	// fmr f3,f0
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = ctx.f0.f64;
loc_8215FF18:
	// lwz r11,60(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 60);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x8215ffc8
	if (!ctx.cr6.eq) goto loc_8215FFC8;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stfs f3,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// ble cr6,0x8215ff5c
	if (!ctx.cr6.gt) goto loc_8215FF5C;
loc_8215FF38:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mullw r8,r10,r11
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stfsx f2,r7,r9
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r7.u32 + ctx.r9.u32, temp.u32);
	// lwz r6,12(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplw cr6,r11,r6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r6.u32, ctx.xer);
	// blt cr6,0x8215ff38
	if (ctx.cr6.lt) goto loc_8215FF38;
loc_8215FF5C:
	// rlwinm r11,r5,0,14,14
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x20000;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821601d8
	if (ctx.cr6.eq) goto loc_821601D8;
	// lwz r3,76(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 76);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8215ff9c
	if (ctx.cr6.eq) goto loc_8215FF9C;
	// fmr f1,f5
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f5.f64;
	// bl 0x8215fbd0
	ctx.lr = 0x8215FF7C;
	sub_8215FBD0(ctx, base);
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// fmr f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f1.f64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f1,r9,r10
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, temp.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-40(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_8215FF9C:
	// fmr f0,f4
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f4.f64;
	// fcmpu cr6,f5,f4
	ctx.cr6.compare(ctx.f5.f64, ctx.f4.f64);
	// ble cr6,0x8215ffac
	if (!ctx.cr6.gt) goto loc_8215FFAC;
	// fdivs f0,f4,f5
	ctx.f0.f64 = double(float(ctx.f4.f64 / ctx.f5.f64));
loc_8215FFAC:
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f0,r9,r10
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, temp.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-40(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_8215FFC8:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lfs f31,22944(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 22944);
	ctx.f31.f64 = double(temp.f32);
	// beq cr6,0x82160054
	if (ctx.cr6.eq) goto loc_82160054;
	// li r9,0
	ctx.r9.s64 = 0;
loc_8215FFE0:
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// ble cr6,0x82160018
	if (!ctx.cr6.gt) goto loc_82160018;
loc_8215FFF0:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// add r7,r10,r30
	ctx.r7.u64 = ctx.r10.u64 + ctx.r30.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f2,r6,r8
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r6.u32 + ctx.r8.u32, temp.u32);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// blt cr6,0x8215fff0
	if (ctx.cr6.lt) goto loc_8215FFF0;
loc_82160018:
	// lwz r11,68(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 68);
	// lfsx f0,r9,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// beq cr6,0x82160034
	if (ctx.cr6.eq) goto loc_82160034;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stfsx f3,r9,r11
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r11.u32, temp.u32);
	// b 0x82160040
	goto loc_82160040;
loc_82160034:
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x82160054
	if (!ctx.cr6.eq) goto loc_82160054;
loc_82160040:
	// lwz r11,60(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 60);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8215ffe0
	if (ctx.cr6.lt) goto loc_8215FFE0;
loc_82160054:
	// lwz r11,60(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 60);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x8216014c
	if (!ctx.cr6.lt) goto loc_8216014C;
	// lwz r3,76(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 76);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8216007c
	if (ctx.cr6.eq) goto loc_8216007C;
	// fmr f1,f5
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f5.f64;
	// bl 0x8215fbd0
	ctx.lr = 0x82160074;
	sub_8215FBD0(ctx, base);
	// fmr f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f1.f64;
	// b 0x8216008c
	goto loc_8216008C;
loc_8216007C:
	// fmr f0,f4
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f4.f64;
	// fcmpu cr6,f5,f4
	ctx.cr6.compare(ctx.f5.f64, ctx.f4.f64);
	// ble cr6,0x8216008c
	if (!ctx.cr6.gt) goto loc_8216008C;
	// fdivs f0,f4,f5
	ctx.f0.f64 = double(float(ctx.f4.f64 / ctx.f5.f64));
loc_8216008C:
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// addi r10,r30,1
	ctx.r10.s64 = ctx.r30.s64 + 1;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mullw r11,r9,r11
	ctx.r11.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// add r7,r11,r30
	ctx.r7.u64 = ctx.r11.u64 + ctx.r30.u64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f0,r6,r8
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + ctx.r8.u32, temp.u32);
	// lwz r5,60(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 60);
	// cmplw cr6,r10,r5
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r5.u32, ctx.xer);
	// bge cr6,0x821601d8
	if (!ctx.cr6.lt) goto loc_821601D8;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
loc_821600BC:
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// ble cr6,0x821600f4
	if (!ctx.cr6.gt) goto loc_821600F4;
loc_821600CC:
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mullw r9,r9,r11
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f2,r5,r7
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r5.u32 + ctx.r7.u32, temp.u32);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// blt cr6,0x821600cc
	if (ctx.cr6.lt) goto loc_821600CC;
loc_821600F4:
	// lwz r11,68(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 68);
	// lfsx f13,r8,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f31
	ctx.cr6.compare(ctx.f13.f64, ctx.f31.f64);
	// beq cr6,0x82160110
	if (ctx.cr6.eq) goto loc_82160110;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stfsx f3,r8,r11
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r8.u32 + ctx.r11.u32, temp.u32);
	// b 0x8216012c
	goto loc_8216012C;
loc_82160110:
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r9,8(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mullw r11,r11,r9
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r9.s32);
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f0,r5,r7
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + ctx.r7.u32, temp.u32);
loc_8216012C:
	// lwz r11,60(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 60);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x821600bc
	if (ctx.cr6.lt) goto loc_821600BC;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_8216014C:
	// rlwinm r11,r5,0,14,14
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x20000;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821601d8
	if (ctx.cr6.eq) goto loc_821601D8;
	// lwz r3,76(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 76);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82160174
	if (ctx.cr6.eq) goto loc_82160174;
	// fmr f1,f5
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f5.f64;
	// bl 0x8215fbd0
	ctx.lr = 0x8216016C;
	sub_8215FBD0(ctx, base);
	// fmr f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f1.f64;
	// b 0x82160184
	goto loc_82160184;
loc_82160174:
	// fmr f0,f4
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f4.f64;
	// fcmpu cr6,f5,f4
	ctx.cr6.compare(ctx.f5.f64, ctx.f4.f64);
	// ble cr6,0x82160184
	if (!ctx.cr6.gt) goto loc_82160184;
	// fdivs f0,f4,f5
	ctx.f0.f64 = double(float(ctx.f4.f64 / ctx.f5.f64));
loc_82160184:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// std r10,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r10.u64);
	// lfd f13,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fdivs f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 / ctx.f11.f64));
	// beq cr6,0x821601d8
	if (ctx.cr6.eq) goto loc_821601D8;
loc_821601AC:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r9,8(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mullw r10,r10,r9
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f0,r6,r8
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + ctx.r8.u32, temp.u32);
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmplw cr6,r11,r5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r5.u32, ctx.xer);
	// blt cr6,0x821601ac
	if (ctx.cr6.lt) goto loc_821601AC;
loc_821601D8:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821601E4"))) PPC_WEAK_FUNC(sub_821601E4);
PPC_FUNC_IMPL(__imp__sub_821601E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821601E8"))) PPC_WEAK_FUNC(sub_821601E8);
PPC_FUNC_IMPL(__imp__sub_821601E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821601F0;
	__savegprlr_28(ctx, base);
	// stfd f29,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.f29.u64);
	// stfd f30,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lfs f0,9388(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 9388);
	ctx.f0.f64 = double(temp.f32);
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bne cr6,0x82160290
	if (!ctx.cr6.eq) goto loc_82160290;
	// clrlwi r10,r6,31
	ctx.r10.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82160250
	if (ctx.cr6.eq) goto loc_82160250;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// b 0x82160254
	goto loc_82160254;
loc_82160250:
	// lfs f12,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
loc_82160254:
	// rlwinm r9,r30,0,28,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0xC;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82160270
	if (ctx.cr6.eq) goto loc_82160270;
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// b 0x82160274
	goto loc_82160274;
loc_82160270:
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
loc_82160274:
	// rlwinm r9,r30,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8216051c
	if (ctx.cr6.eq) goto loc_8216051C;
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// b 0x82160520
	goto loc_82160520;
loc_82160290:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f0,22944(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 22944);
	ctx.f0.f64 = double(temp.f32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// beq cr6,0x821604c0
	if (ctx.cr6.eq) goto loc_821604C0;
	// lwz r9,36(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 36);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f0,-22560(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -22560);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x821604c0
	if (!ctx.cr6.gt) goto loc_821604C0;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r31,28
	ctx.r4.s64 = ctx.r31.s64 + 28;
	// addi r3,r10,24
	ctx.r3.s64 = ctx.r10.s64 + 24;
	// bl 0x82161a20
	ctx.lr = 0x821602D8;
	sub_82161A20(ctx, base);
	// addi r4,r31,4
	ctx.r4.s64 = ctx.r31.s64 + 4;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821619f8
	ctx.lr = 0x821602E4;
	sub_821619F8(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,36(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 36);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lfs f29,12868(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12868);
	ctx.f29.f64 = double(temp.f32);
	// fdivs f31,f1,f0
	ctx.f31.f64 = double(float(ctx.f1.f64 / ctx.f0.f64));
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f13,f29
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f29.f64));
	// bl 0x8207af40
	ctx.lr = 0x82160314;
	sub_8207AF40(ctx, base);
	// frsp f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = double(float(ctx.f1.f64));
	// fcmpu cr6,f31,f30
	ctx.cr6.compare(ctx.f31.f64, ctx.f30.f64);
	// blt cr6,0x82160388
	if (ctx.cr6.lt) goto loc_82160388;
	// clrlwi r10,r30,31
	ctx.r10.u64 = ctx.r30.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82160340
	if (ctx.cr6.eq) goto loc_82160340;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// b 0x82160344
	goto loc_82160344;
loc_82160340:
	// lfs f12,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
loc_82160344:
	// rlwinm r11,r30,0,28,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0xC;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82160364
	if (ctx.cr6.eq) goto loc_82160364;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// b 0x82160368
	goto loc_82160368;
loc_82160364:
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
loc_82160368:
	// rlwinm r9,r30,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8216051c
	if (ctx.cr6.eq) goto loc_8216051C;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r8,24(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// b 0x82160520
	goto loc_82160520;
loc_82160388:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f1,f0,f29
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f29.f64));
	// bl 0x8207af40
	ctx.lr = 0x821603A0;
	sub_8207AF40(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// clrlwi r10,r30,31
	ctx.r10.u64 = ctx.r30.u32 & 0x1;
	// fcmpu cr6,f31,f0
	ctx.cr6.compare(ctx.f31.f64, ctx.f0.f64);
	// bgt cr6,0x82160414
	if (ctx.cr6.gt) goto loc_82160414;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821603cc
	if (ctx.cr6.eq) goto loc_821603CC;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// b 0x821603d0
	goto loc_821603D0;
loc_821603CC:
	// lfs f12,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
loc_821603D0:
	// rlwinm r11,r30,0,28,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0xC;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821603f0
	if (ctx.cr6.eq) goto loc_821603F0;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// b 0x821603f4
	goto loc_821603F4;
loc_821603F0:
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
loc_821603F4:
	// rlwinm r9,r30,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8216051c
	if (ctx.cr6.eq) goto loc_8216051C;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r8,28(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// b 0x82160520
	goto loc_82160520;
loc_82160414:
	// fsubs f13,f31,f30
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f31.f64 - ctx.f30.f64));
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// fsubs f12,f0,f30
	ctx.f12.f64 = double(float(ctx.f0.f64 - ctx.f30.f64));
	// fdivs f0,f13,f12
	ctx.f0.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
	// beq cr6,0x82160450
	if (ctx.cr6.eq) goto loc_82160450;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// lfs f12,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fmadds f12,f11,f0,f13
	ctx.f12.f64 = double(float(ctx.f11.f64 * ctx.f0.f64 + ctx.f13.f64));
	// b 0x82160454
	goto loc_82160454;
loc_82160450:
	// lfs f12,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
loc_82160454:
	// rlwinm r11,r30,0,28,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0xC;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82160488
	if (ctx.cr6.eq) goto loc_82160488;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r8,20(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f13,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// fmadds f13,f10,f0,f13
	ctx.f13.f64 = double(float(ctx.f10.f64 * ctx.f0.f64 + ctx.f13.f64));
	// b 0x8216048c
	goto loc_8216048C;
loc_82160488:
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
loc_8216048C:
	// rlwinm r9,r30,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8216051c
	if (ctx.cr6.eq) goto loc_8216051C;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r8,24(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// lwz r7,28(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// lfs f11,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f10,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f11.f64));
	// fmadds f0,f9,f0,f11
	ctx.f0.f64 = double(float(ctx.f9.f64 * ctx.f0.f64 + ctx.f11.f64));
	// b 0x82160520
	goto loc_82160520;
loc_821604C0:
	// clrlwi r10,r30,31
	ctx.r10.u64 = ctx.r30.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821604dc
	if (ctx.cr6.eq) goto loc_821604DC;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// lfs f12,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// b 0x821604e0
	goto loc_821604E0;
loc_821604DC:
	// lfs f12,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
loc_821604E0:
	// rlwinm r9,r30,0,28,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0xC;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x821604fc
	if (ctx.cr6.eq) goto loc_821604FC;
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// lfs f13,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// b 0x82160500
	goto loc_82160500;
loc_821604FC:
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
loc_82160500:
	// rlwinm r9,r30,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8216051c
	if (ctx.cr6.eq) goto loc_8216051C;
	// lwz r11,24(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// b 0x82160520
	goto loc_82160520;
loc_8216051C:
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
loc_82160520:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8216055c
	if (ctx.cr6.eq) goto loc_8216055C;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lfs f11,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// stfs f10,0(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lwz r10,8(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// beq cr6,0x8216055c
	if (ctx.cr6.eq) goto loc_8216055C;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f11,r10,r11
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// stfsx f10,r10,r11
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r11.u32, temp.u32);
loc_8216055C:
	// rlwinm r11,r30,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82160584
	if (ctx.cr6.eq) goto loc_82160584;
	// lwz r11,16(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// lfs f12,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// stfs f11,84(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r10,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r10.u32);
loc_82160584:
	// rlwinm r11,r30,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821605ac
	if (ctx.cr6.eq) goto loc_821605AC;
	// lwz r11,20(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// lfs f12,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// stfs f11,84(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r10,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r10.u32);
loc_821605AC:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x821605d0
	if (ctx.cr6.eq) goto loc_821605D0;
	// lwz r11,24(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// lfs f13,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r10,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r10.u32);
loc_821605D0:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f29,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f30,-56(r1)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821605E4"))) PPC_WEAK_FUNC(sub_821605E4);
PPC_FUNC_IMPL(__imp__sub_821605E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821605E8"))) PPC_WEAK_FUNC(sub_821605E8);
PPC_FUNC_IMPL(__imp__sub_821605E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x821605F0;
	__savegprlr_27(ctx, base);
	// addi r12,r1,-48
	ctx.r12.s64 = ctx.r1.s64 + -48;
	// bl 0x82080364
	ctx.lr = 0x821605F8;
	__savefpr_27(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,48(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 48);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lfs f28,9388(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 9388);
	ctx.f28.f64 = double(temp.f32);
	// lfs f27,22944(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 22944);
	ctx.f27.f64 = double(temp.f32);
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f28
	ctx.cr6.compare(ctx.f0.f64, ctx.f28.f64);
	// bne cr6,0x82160694
	if (!ctx.cr6.eq) goto loc_82160694;
	// clrlwi r10,r6,31
	ctx.r10.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82160654
	if (ctx.cr6.eq) goto loc_82160654;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// b 0x82160658
	goto loc_82160658;
loc_82160654:
	// lfs f12,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
loc_82160658:
	// rlwinm r9,r28,0,28,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0xC;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82160674
	if (ctx.cr6.eq) goto loc_82160674;
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// b 0x82160678
	goto loc_82160678;
loc_82160674:
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
loc_82160678:
	// rlwinm r7,r28,0,27,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82160918
	if (ctx.cr6.eq) goto loc_82160918;
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// b 0x8216091c
	goto loc_8216091C;
loc_82160694:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f27
	ctx.cr6.compare(ctx.f0.f64, ctx.f27.f64);
	// beq cr6,0x821608bc
	if (ctx.cr6.eq) goto loc_821608BC;
	// lwz r10,36(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lfs f0,-22560(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -22560);
	ctx.f0.f64 = double(temp.f32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x821608bc
	if (!ctx.cr6.gt) goto loc_821608BC;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r31,24
	ctx.r4.s64 = ctx.r31.s64 + 24;
	// addi r3,r29,28
	ctx.r3.s64 = ctx.r29.s64 + 28;
	// bl 0x82161a20
	ctx.lr = 0x821606D4;
	sub_82161A20(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821619f8
	ctx.lr = 0x821606E0;
	sub_821619F8(ctx, base);
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r10,36(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lfs f29,12868(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12868);
	ctx.f29.f64 = double(temp.f32);
	// fdivs f31,f1,f0
	ctx.f31.f64 = double(float(ctx.f1.f64 / ctx.f0.f64));
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f13,f29
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f29.f64));
	// bl 0x8207af40
	ctx.lr = 0x82160710;
	sub_8207AF40(ctx, base);
	// frsp f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = double(float(ctx.f1.f64));
	// fcmpu cr6,f31,f30
	ctx.cr6.compare(ctx.f31.f64, ctx.f30.f64);
	// blt cr6,0x82160784
	if (ctx.cr6.lt) goto loc_82160784;
	// clrlwi r10,r28,31
	ctx.r10.u64 = ctx.r28.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8216073c
	if (ctx.cr6.eq) goto loc_8216073C;
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// b 0x82160740
	goto loc_82160740;
loc_8216073C:
	// lfs f12,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
loc_82160740:
	// rlwinm r11,r28,0,28,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0xC;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82160760
	if (ctx.cr6.eq) goto loc_82160760;
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// b 0x82160764
	goto loc_82160764;
loc_82160760:
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
loc_82160764:
	// rlwinm r7,r28,0,27,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82160918
	if (ctx.cr6.eq) goto loc_82160918;
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// b 0x8216091c
	goto loc_8216091C;
loc_82160784:
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f1,f0,f29
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f29.f64));
	// bl 0x8207af40
	ctx.lr = 0x8216079C;
	sub_8207AF40(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// clrlwi r10,r28,31
	ctx.r10.u64 = ctx.r28.u32 & 0x1;
	// fcmpu cr6,f31,f0
	ctx.cr6.compare(ctx.f31.f64, ctx.f0.f64);
	// bgt cr6,0x82160810
	if (ctx.cr6.gt) goto loc_82160810;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821607c8
	if (ctx.cr6.eq) goto loc_821607C8;
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// b 0x821607cc
	goto loc_821607CC;
loc_821607C8:
	// lfs f12,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
loc_821607CC:
	// rlwinm r11,r28,0,28,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0xC;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821607ec
	if (ctx.cr6.eq) goto loc_821607EC;
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// b 0x821607f0
	goto loc_821607F0;
loc_821607EC:
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
loc_821607F0:
	// rlwinm r7,r28,0,27,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82160918
	if (ctx.cr6.eq) goto loc_82160918;
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// b 0x8216091c
	goto loc_8216091C;
loc_82160810:
	// fsubs f13,f31,f30
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f31.f64 - ctx.f30.f64));
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// fsubs f12,f0,f30
	ctx.f12.f64 = double(float(ctx.f0.f64 - ctx.f30.f64));
	// fdivs f0,f13,f12
	ctx.f0.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
	// beq cr6,0x8216084c
	if (ctx.cr6.eq) goto loc_8216084C;
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// lfs f12,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fmadds f12,f11,f0,f13
	ctx.f12.f64 = double(float(ctx.f11.f64 * ctx.f0.f64 + ctx.f13.f64));
	// b 0x82160850
	goto loc_82160850;
loc_8216084C:
	// lfs f12,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
loc_82160850:
	// rlwinm r11,r28,0,28,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0xC;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82160884
	if (ctx.cr6.eq) goto loc_82160884;
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r8,20(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f13,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// fmadds f13,f10,f0,f13
	ctx.f13.f64 = double(float(ctx.f10.f64 * ctx.f0.f64 + ctx.f13.f64));
	// b 0x82160888
	goto loc_82160888;
loc_82160884:
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
loc_82160888:
	// rlwinm r7,r28,0,27,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82160918
	if (ctx.cr6.eq) goto loc_82160918;
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// lwz r8,28(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f11,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f10,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f11.f64));
	// fmadds f0,f9,f0,f11
	ctx.f0.f64 = double(float(ctx.f9.f64 * ctx.f0.f64 + ctx.f11.f64));
	// b 0x8216091c
	goto loc_8216091C;
loc_821608BC:
	// clrlwi r10,r28,31
	ctx.r10.u64 = ctx.r28.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821608d8
	if (ctx.cr6.eq) goto loc_821608D8;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// lfs f12,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// b 0x821608dc
	goto loc_821608DC;
loc_821608D8:
	// lfs f12,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
loc_821608DC:
	// rlwinm r9,r28,0,28,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0xC;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x821608f8
	if (ctx.cr6.eq) goto loc_821608F8;
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// lfs f13,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// b 0x821608fc
	goto loc_821608FC;
loc_821608F8:
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
loc_821608FC:
	// rlwinm r7,r28,0,27,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82160918
	if (ctx.cr6.eq) goto loc_82160918;
	// lwz r11,24(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// b 0x8216091c
	goto loc_8216091C;
loc_82160918:
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
loc_8216091C:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821609e8
	if (ctx.cr6.eq) goto loc_821609E8;
	// lwz r9,60(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 60);
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82160960
	if (ctx.cr6.eq) goto loc_82160960;
	// li r10,0
	ctx.r10.s64 = 0;
loc_82160938:
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lfs f11,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// stfs f10,0(r9)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// lwz r9,60(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 60);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x82160938
	if (ctx.cr6.lt) goto loc_82160938;
loc_82160960:
	// lwz r11,8(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 8);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x821609e8
	if (ctx.cr6.eq) goto loc_821609E8;
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// bne cr6,0x82160990
	if (!ctx.cr6.eq) goto loc_82160990;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f11,r10,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f12,f11
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// stfsx f10,r10,r11
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r11.u32, temp.u32);
	// b 0x821609e8
	goto loc_821609E8;
loc_82160990:
	// li r8,0
	ctx.r8.s64 = 0;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x821609e8
	if (ctx.cr6.eq) goto loc_821609E8;
	// li r9,0
	ctx.r9.s64 = 0;
loc_821609A0:
	// lwz r11,68(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 68);
	// lfsx f11,r9,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f11,f27
	ctx.cr6.compare(ctx.f11.f64, ctx.f27.f64);
	// bne cr6,0x821609d4
	if (!ctx.cr6.eq) goto loc_821609D4;
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r6,8(r27)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r27.u32 + 8);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mullw r10,r10,r6
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r6.s32);
	// add r5,r10,r8
	ctx.r5.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f11,r10,r11
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// stfsx f10,r10,r11
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r11.u32, temp.u32);
loc_821609D4:
	// lwz r11,60(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 60);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x821609a0
	if (ctx.cr6.lt) goto loc_821609A0;
loc_821609E8:
	// rlwinm r11,r28,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82160a24
	if (ctx.cr6.eq) goto loc_82160A24;
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// lfs f12,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// stfs f11,84(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fcmpu cr6,f11,f28
	ctx.cr6.compare(ctx.f11.f64, ctx.f28.f64);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r10,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r10.u32);
	// bge cr6,0x82160a24
	if (!ctx.cr6.lt) goto loc_82160A24;
	// stfs f28,84(r1)
	temp.f32 = float(ctx.f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r11,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r11.u32);
loc_82160A24:
	// rlwinm r11,r28,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82160a60
	if (ctx.cr6.eq) goto loc_82160A60;
	// lwz r11,20(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// lfs f12,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// stfs f11,84(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fcmpu cr6,f11,f28
	ctx.cr6.compare(ctx.f11.f64, ctx.f28.f64);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r10,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r10.u32);
	// bge cr6,0x82160a60
	if (!ctx.cr6.lt) goto loc_82160A60;
	// stfs f28,84(r1)
	temp.f32 = float(ctx.f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r11,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r11.u32);
loc_82160A60:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82160a84
	if (ctx.cr6.eq) goto loc_82160A84;
	// lwz r11,24(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// lfs f13,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r10,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r10.u32);
loc_82160A84:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// addi r12,r1,-48
	ctx.r12.s64 = ctx.r1.s64 + -48;
	// bl 0x820803b0
	ctx.lr = 0x82160A90;
	__restfpr_27(ctx, base);
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82160A94"))) PPC_WEAK_FUNC(sub_82160A94);
PPC_FUNC_IMPL(__imp__sub_82160A94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82160A98"))) PPC_WEAK_FUNC(sub_82160A98);
PPC_FUNC_IMPL(__imp__sub_82160A98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82160AA0;
	__savegprlr_28(ctx, base);
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,36(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 36);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lfs f0,9388(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 9388);
	ctx.f0.f64 = double(temp.f32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f12,-22560(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -22560);
	ctx.f12.f64 = double(temp.f32);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// mr r31,r6
	ctx.r31.u64 = ctx.r6.u64;
	// lfs f13,14004(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14004);
	ctx.f13.f64 = double(temp.f32);
	// fmr f31,f0
	ctx.f31.f64 = ctx.f0.f64;
	// fmr f10,f0
	ctx.f10.f64 = ctx.f0.f64;
	// fcmpu cr6,f11,f12
	ctx.cr6.compare(ctx.f11.f64, ctx.f12.f64);
	// ble cr6,0x82160ba4
	if (!ctx.cr6.gt) goto loc_82160BA4;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r30,28
	ctx.r4.s64 = ctx.r30.s64 + 28;
	// addi r3,r29,24
	ctx.r3.s64 = ctx.r29.s64 + 24;
	// bl 0x82161a20
	ctx.lr = 0x82160AFC;
	sub_82161A20(ctx, base);
	// addi r4,r29,36
	ctx.r4.s64 = ctx.r29.s64 + 36;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821619f8
	ctx.lr = 0x82160B08;
	sub_821619F8(ctx, base);
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r4,r30,40
	ctx.r4.s64 = ctx.r30.s64 + 40;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fdivs f31,f1,f0
	ctx.f31.f64 = double(float(ctx.f1.f64 / ctx.f0.f64));
	// bl 0x821619f8
	ctx.lr = 0x82160B24;
	sub_821619F8(ctx, base);
	// lwz r10,96(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 96);
	// lwz r9,16(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// lwz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f12,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f13,f12,f31
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f31.f64));
	// fdivs f10,f1,f11
	ctx.f10.f64 = double(float(ctx.f1.f64 / ctx.f11.f64));
	// fmuls f12,f12,f10
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f10.f64));
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x82160b64
	if (!ctx.cr6.gt) goto loc_82160B64;
	// fmr f13,f0
	ctx.f13.f64 = ctx.f0.f64;
	// b 0x82160b74
	goto loc_82160B74;
loc_82160B64:
	// fneg f11,f0
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// fcmpu cr6,f13,f11
	ctx.cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// bge cr6,0x82160b74
	if (!ctx.cr6.lt) goto loc_82160B74;
	// fmr f13,f11
	ctx.f13.f64 = ctx.f11.f64;
loc_82160B74:
	// fcmpu cr6,f12,f0
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f12.f64, ctx.f0.f64);
	// bgt cr6,0x82160b88
	if (ctx.cr6.gt) goto loc_82160B88;
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// fcmpu cr6,f12,f0
	ctx.cr6.compare(ctx.f12.f64, ctx.f0.f64);
	// bge cr6,0x82160b8c
	if (!ctx.cr6.lt) goto loc_82160B8C;
loc_82160B88:
	// fmr f12,f0
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f0.f64;
loc_82160B8C:
	// lwz r11,12(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// fsubs f12,f0,f12
	ctx.f12.f64 = double(float(ctx.f0.f64 - ctx.f12.f64));
	// fdivs f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
loc_82160BA4:
	// stfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stfs f10,80(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stfs f31,80(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// stw r10,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r10.u32);
	// stw r9,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r9.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-48(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82160BD4"))) PPC_WEAK_FUNC(sub_82160BD4);
PPC_FUNC_IMPL(__imp__sub_82160BD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82160BD8"))) PPC_WEAK_FUNC(sub_82160BD8);
PPC_FUNC_IMPL(__imp__sub_82160BD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82160BE0;
	__savegprlr_28(ctx, base);
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.f31.u64);
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32253
	ctx.r11.s64 = -2113732608;
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r28,r8
	ctx.r28.u64 = ctx.r8.u64;
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// lfs f10,29320(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 29320);
	ctx.f10.f64 = double(temp.f32);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lfs f5,21000(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 21000);
	ctx.f5.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f0,29536(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 29536);
	ctx.f0.f64 = double(temp.f32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r11,-32253
	ctx.r11.s64 = -2113732608;
	// stfs f10,96(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// stfs f5,100(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lfs f13,29532(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 29532);
	ctx.f13.f64 = double(temp.f32);
	// lis r31,-32253
	ctx.r31.s64 = -2113732608;
	// lfs f7,9388(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 9388);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,22952(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 22952);
	ctx.f6.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f12,29528(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 29528);
	ctx.f12.f64 = double(temp.f32);
	// li r8,0
	ctx.r8.s64 = 0;
	// lfs f11,29524(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 29524);
	ctx.f11.f64 = double(temp.f32);
	// cmplwi cr6,r4,63
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 63, ctx.xer);
	// lfs f9,29520(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 29520);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,29516(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 29516);
	ctx.f8.f64 = double(temp.f32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f6,112(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f7,136(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f6,140(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f11,92(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f10,152(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f5,156(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f13,164(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f7,168(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f12,172(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f11,176(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f0,256(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// stfs f13,260(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// stfs f12,264(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// stfs f11,268(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// stfs f9,272(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 272, temp.u32);
	// stfs f8,276(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// stfs f0,288(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 288, temp.u32);
	// stfs f13,292(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 292, temp.u32);
	// stfs f7,296(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 296, temp.u32);
	// stfs f12,300(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 300, temp.u32);
	// stfs f11,304(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 304, temp.u32);
	// stfs f9,308(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 308, temp.u32);
	// stfs f8,312(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 312, temp.u32);
	// stfs f0,192(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// stfs f13,196(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f7,200(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// stfs f10,204(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// stfs f5,208(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// stfs f0,224(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// stfs f13,228(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// stfs f12,232(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// stfs f11,236(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// stfs f10,240(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// stfs f5,244(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// stfs f0,320(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 320, temp.u32);
	// stfs f13,324(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 324, temp.u32);
	// stfs f7,328(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 328, temp.u32);
	// stfs f12,332(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 332, temp.u32);
	// stfs f11,336(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 336, temp.u32);
	// stfs f10,340(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 340, temp.u32);
	// stfs f5,344(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 344, temp.u32);
	// bgt cr6,0x82160db4
	if (ctx.cr6.gt) goto loc_82160DB4;
	// beq cr6,0x82160d94
	if (ctx.cr6.eq) goto loc_82160D94;
	// cmplwi cr6,r4,11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 11, ctx.xer);
	// bgt cr6,0x82160d78
	if (ctx.cr6.gt) goto loc_82160D78;
	// beq cr6,0x82160d6c
	if (ctx.cr6.eq) goto loc_82160D6C;
	// cmplwi cr6,r4,3
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 3, ctx.xer);
	// beq cr6,0x82160d6c
	if (ctx.cr6.eq) goto loc_82160D6C;
	// cmplwi cr6,r4,4
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 4, ctx.xer);
	// bne cr6,0x82160e50
	if (!ctx.cr6.eq) goto loc_82160E50;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// rlwinm r10,r28,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r10,r11
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// stfsx f13,r10,r11
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r11.u32, temp.u32);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// lfd f31,-48(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_82160D6C:
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r8,2
	ctx.r8.s64 = 2;
	// b 0x82160e50
	goto loc_82160E50;
loc_82160D78:
	// cmplwi cr6,r4,51
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 51, ctx.xer);
	// beq cr6,0x82160d88
	if (ctx.cr6.eq) goto loc_82160D88;
	// cmplwi cr6,r4,59
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 59, ctx.xer);
	// bne cr6,0x82160e50
	if (!ctx.cr6.eq) goto loc_82160E50;
loc_82160D88:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r8,4
	ctx.r8.s64 = 4;
	// b 0x82160e50
	goto loc_82160E50;
loc_82160D94:
	// rlwinm r11,r6,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x10000;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// li r8,5
	ctx.r8.s64 = 5;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82160e50
	if (ctx.cr6.eq) goto loc_82160E50;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r8,4
	ctx.r8.s64 = 4;
	// b 0x82160e50
	goto loc_82160E50;
loc_82160DB4:
	// cmplwi cr6,r4,1551
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 1551, ctx.xer);
	// bgt cr6,0x82160e2c
	if (ctx.cr6.gt) goto loc_82160E2C;
	// beq cr6,0x82160e0c
	if (ctx.cr6.eq) goto loc_82160E0C;
	// cmplwi cr6,r4,255
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 255, ctx.xer);
	// beq cr6,0x82160df0
	if (ctx.cr6.eq) goto loc_82160DF0;
	// cmplwi cr6,r4,263
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 263, ctx.xer);
	// bne cr6,0x82160e50
	if (!ctx.cr6.eq) goto loc_82160E50;
	// rlwinm r11,r6,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x10000;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// li r8,4
	ctx.r8.s64 = 4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82160e50
	if (ctx.cr6.eq) goto loc_82160E50;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// li r8,3
	ctx.r8.s64 = 3;
	// b 0x82160e50
	goto loc_82160E50;
loc_82160DF0:
	// rlwinm r11,r6,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x10000;
	// addi r5,r1,288
	ctx.r5.s64 = ctx.r1.s64 + 288;
	// li r8,7
	ctx.r8.s64 = 7;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82160e50
	if (ctx.cr6.eq) goto loc_82160E50;
	// addi r5,r1,256
	ctx.r5.s64 = ctx.r1.s64 + 256;
	// b 0x82160e4c
	goto loc_82160E4C;
loc_82160E0C:
	// rlwinm r11,r6,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x10000;
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// li r8,5
	ctx.r8.s64 = 5;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82160e50
	if (ctx.cr6.eq) goto loc_82160E50;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// li r8,4
	ctx.r8.s64 = 4;
	// b 0x82160e50
	goto loc_82160E50;
loc_82160E2C:
	// cmplwi cr6,r4,1599
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 1599, ctx.xer);
	// bne cr6,0x82160e50
	if (!ctx.cr6.eq) goto loc_82160E50;
	// rlwinm r11,r6,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x10000;
	// addi r5,r1,320
	ctx.r5.s64 = ctx.r1.s64 + 320;
	// li r8,7
	ctx.r8.s64 = 7;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82160e50
	if (ctx.cr6.eq) goto loc_82160E50;
	// addi r5,r1,224
	ctx.r5.s64 = ctx.r1.s64 + 224;
loc_82160E4C:
	// li r8,6
	ctx.r8.s64 = 6;
loc_82160E50:
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r11,-32253
	ctx.r11.s64 = -2113732608;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// li r30,-1
	ctx.r30.s64 = -1;
	// lfs f10,29512(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 29512);
	ctx.f10.f64 = double(temp.f32);
	// li r31,-1
	ctx.r31.s64 = -1;
	// lfs f12,29508(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 29508);
	ctx.f12.f64 = double(temp.f32);
	// li r9,0
	ctx.r9.s64 = 0;
	// lfs f13,22756(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 22756);
	ctx.f13.f64 = double(temp.f32);
	// cmpwi cr6,r8,4
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 4, ctx.xer);
	// lfs f11,22944(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 22944);
	ctx.f11.f64 = double(temp.f32);
	// blt cr6,0x8216100c
	if (ctx.cr6.lt) goto loc_8216100C;
	// addi r10,r8,-4
	ctx.r10.s64 = ctx.r8.s64 + -4;
	// li r11,2
	ctx.r11.s64 = 2;
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r7,r5,8
	ctx.r7.s64 = ctx.r5.s64 + 8;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82160E9C:
	// lfs f0,-8(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -8);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f2,f0
	ctx.f0.f64 = double(float(ctx.f2.f64 - ctx.f0.f64));
	// fcmpu cr6,f0,f6
	ctx.cr6.compare(ctx.f0.f64, ctx.f6.f64);
	// ble cr6,0x82160eb4
	if (!ctx.cr6.gt) goto loc_82160EB4;
	// fsubs f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f11.f64));
	// b 0x82160ec0
	goto loc_82160EC0;
loc_82160EB4:
	// fcmpu cr6,f0,f10
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f10.f64);
	// bge cr6,0x82160ec0
	if (!ctx.cr6.lt) goto loc_82160EC0;
	// fadds f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f11.f64));
loc_82160EC0:
	// fcmpu cr6,f0,f7
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f7.f64);
	// bgt cr6,0x82160edc
	if (ctx.cr6.gt) goto loc_82160EDC;
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x82160edc
	if (!ctx.cr6.gt) goto loc_82160EDC;
	// mr r30,r9
	ctx.r30.u64 = ctx.r9.u64;
	// fmr f12,f0
	ctx.f12.f64 = ctx.f0.f64;
	// b 0x82160ef4
	goto loc_82160EF4;
loc_82160EDC:
	// fcmpu cr6,f0,f7
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f7.f64);
	// blt cr6,0x82160ef4
	if (ctx.cr6.lt) goto loc_82160EF4;
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82160ef4
	if (!ctx.cr6.lt) goto loc_82160EF4;
	// mr r31,r9
	ctx.r31.u64 = ctx.r9.u64;
	// fmr f13,f0
	ctx.f13.f64 = ctx.f0.f64;
loc_82160EF4:
	// lfs f0,-4(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f2,f0
	ctx.f0.f64 = double(float(ctx.f2.f64 - ctx.f0.f64));
	// fcmpu cr6,f0,f6
	ctx.cr6.compare(ctx.f0.f64, ctx.f6.f64);
	// ble cr6,0x82160f0c
	if (!ctx.cr6.gt) goto loc_82160F0C;
	// fsubs f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f11.f64));
	// b 0x82160f18
	goto loc_82160F18;
loc_82160F0C:
	// fcmpu cr6,f0,f10
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f10.f64);
	// bge cr6,0x82160f18
	if (!ctx.cr6.lt) goto loc_82160F18;
	// fadds f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f11.f64));
loc_82160F18:
	// fcmpu cr6,f0,f7
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f7.f64);
	// bgt cr6,0x82160f34
	if (ctx.cr6.gt) goto loc_82160F34;
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x82160f34
	if (!ctx.cr6.gt) goto loc_82160F34;
	// addi r30,r11,-1
	ctx.r30.s64 = ctx.r11.s64 + -1;
	// fmr f12,f0
	ctx.f12.f64 = ctx.f0.f64;
	// b 0x82160f4c
	goto loc_82160F4C;
loc_82160F34:
	// fcmpu cr6,f0,f7
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f7.f64);
	// blt cr6,0x82160f4c
	if (ctx.cr6.lt) goto loc_82160F4C;
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82160f4c
	if (!ctx.cr6.lt) goto loc_82160F4C;
	// addi r31,r11,-1
	ctx.r31.s64 = ctx.r11.s64 + -1;
	// fmr f13,f0
	ctx.f13.f64 = ctx.f0.f64;
loc_82160F4C:
	// lfs f0,0(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f2,f0
	ctx.f0.f64 = double(float(ctx.f2.f64 - ctx.f0.f64));
	// fcmpu cr6,f0,f6
	ctx.cr6.compare(ctx.f0.f64, ctx.f6.f64);
	// ble cr6,0x82160f64
	if (!ctx.cr6.gt) goto loc_82160F64;
	// fsubs f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f11.f64));
	// b 0x82160f70
	goto loc_82160F70;
loc_82160F64:
	// fcmpu cr6,f0,f10
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f10.f64);
	// bge cr6,0x82160f70
	if (!ctx.cr6.lt) goto loc_82160F70;
	// fadds f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f11.f64));
loc_82160F70:
	// fcmpu cr6,f0,f7
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f7.f64);
	// bgt cr6,0x82160f8c
	if (ctx.cr6.gt) goto loc_82160F8C;
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x82160f8c
	if (!ctx.cr6.gt) goto loc_82160F8C;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// fmr f12,f0
	ctx.f12.f64 = ctx.f0.f64;
	// b 0x82160fa4
	goto loc_82160FA4;
loc_82160F8C:
	// fcmpu cr6,f0,f7
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f7.f64);
	// blt cr6,0x82160fa4
	if (ctx.cr6.lt) goto loc_82160FA4;
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82160fa4
	if (!ctx.cr6.lt) goto loc_82160FA4;
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
	// fmr f13,f0
	ctx.f13.f64 = ctx.f0.f64;
loc_82160FA4:
	// lfs f0,4(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f2,f0
	ctx.f0.f64 = double(float(ctx.f2.f64 - ctx.f0.f64));
	// fcmpu cr6,f0,f6
	ctx.cr6.compare(ctx.f0.f64, ctx.f6.f64);
	// ble cr6,0x82160fbc
	if (!ctx.cr6.gt) goto loc_82160FBC;
	// fsubs f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f11.f64));
	// b 0x82160fc8
	goto loc_82160FC8;
loc_82160FBC:
	// fcmpu cr6,f0,f10
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f10.f64);
	// bge cr6,0x82160fc8
	if (!ctx.cr6.lt) goto loc_82160FC8;
	// fadds f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f11.f64));
loc_82160FC8:
	// fcmpu cr6,f0,f7
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f7.f64);
	// bgt cr6,0x82160fe4
	if (ctx.cr6.gt) goto loc_82160FE4;
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x82160fe4
	if (!ctx.cr6.gt) goto loc_82160FE4;
	// addi r30,r11,1
	ctx.r30.s64 = ctx.r11.s64 + 1;
	// fmr f12,f0
	ctx.f12.f64 = ctx.f0.f64;
	// b 0x82160ffc
	goto loc_82160FFC;
loc_82160FE4:
	// fcmpu cr6,f0,f7
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f7.f64);
	// blt cr6,0x82160ffc
	if (ctx.cr6.lt) goto loc_82160FFC;
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82160ffc
	if (!ctx.cr6.lt) goto loc_82160FFC;
	// addi r31,r11,1
	ctx.r31.s64 = ctx.r11.s64 + 1;
	// fmr f13,f0
	ctx.f13.f64 = ctx.f0.f64;
loc_82160FFC:
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// addi r7,r7,16
	ctx.r7.s64 = ctx.r7.s64 + 16;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x82160e9c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82160E9C;
loc_8216100C:
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x82161088
	if (!ctx.cr6.lt) goto loc_82161088;
	// subf r10,r9,r8
	ctx.r10.s64 = ctx.r8.s64 - ctx.r9.s64;
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82161024:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f2,f0
	ctx.f0.f64 = double(float(ctx.f2.f64 - ctx.f0.f64));
	// fcmpu cr6,f0,f6
	ctx.cr6.compare(ctx.f0.f64, ctx.f6.f64);
	// ble cr6,0x8216103c
	if (!ctx.cr6.gt) goto loc_8216103C;
	// fsubs f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f11.f64));
	// b 0x82161048
	goto loc_82161048;
loc_8216103C:
	// fcmpu cr6,f0,f10
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f10.f64);
	// bge cr6,0x82161048
	if (!ctx.cr6.lt) goto loc_82161048;
	// fadds f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f11.f64));
loc_82161048:
	// fcmpu cr6,f0,f7
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f7.f64);
	// bgt cr6,0x82161064
	if (ctx.cr6.gt) goto loc_82161064;
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x82161064
	if (!ctx.cr6.gt) goto loc_82161064;
	// mr r30,r9
	ctx.r30.u64 = ctx.r9.u64;
	// fmr f12,f0
	ctx.f12.f64 = ctx.f0.f64;
	// b 0x8216107c
	goto loc_8216107C;
loc_82161064:
	// fcmpu cr6,f0,f7
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f7.f64);
	// blt cr6,0x8216107c
	if (ctx.cr6.lt) goto loc_8216107C;
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8216107c
	if (!ctx.cr6.lt) goto loc_8216107C;
	// mr r31,r9
	ctx.r31.u64 = ctx.r9.u64;
	// fmr f13,f0
	ctx.f13.f64 = ctx.f0.f64;
loc_8216107C:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x82161024
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82161024;
loc_82161088:
	// fcmpu cr6,f12,f7
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f12.f64, ctx.f7.f64);
	// bge cr6,0x82161094
	if (!ctx.cr6.lt) goto loc_82161094;
	// fneg f12,f12
	ctx.f12.u64 = ctx.f12.u64 ^ 0x8000000000000000;
loc_82161094:
	// fcmpu cr6,f13,f7
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f13.f64, ctx.f7.f64);
	// bge cr6,0x821610a0
	if (!ctx.cr6.lt) goto loc_821610A0;
	// fneg f13,f13
	ctx.f13.u64 = ctx.f13.u64 ^ 0x8000000000000000;
loc_821610A0:
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// beq cr6,0x821610b0
	if (ctx.cr6.eq) goto loc_821610B0;
	// cmpwi cr6,r31,-1
	ctx.cr6.compare<int32_t>(ctx.r31.s32, -1, ctx.xer);
	// bne cr6,0x821610b8
	if (!ctx.cr6.eq) goto loc_821610B8;
loc_821610B0:
	// li r31,0
	ctx.r31.s64 = 0;
	// li r30,0
	ctx.r30.s64 = 0;
loc_821610B8:
	// rlwinm r11,r6,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x10000;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821610dc
	if (ctx.cr6.eq) goto loc_821610DC;
	// cmpwi cr6,r30,1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 1, ctx.xer);
	// ble cr6,0x821610d0
	if (!ctx.cr6.gt) goto loc_821610D0;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
loc_821610D0:
	// cmpwi cr6,r31,1
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 1, ctx.xer);
	// ble cr6,0x821610dc
	if (!ctx.cr6.gt) goto loc_821610DC;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
loc_821610DC:
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x82161120
	if (ctx.cr6.eq) goto loc_82161120;
	// rlwinm r11,r4,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82161108
	if (ctx.cr6.eq) goto loc_82161108;
	// cmpwi cr6,r30,2
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 2, ctx.xer);
	// ble cr6,0x82161100
	if (!ctx.cr6.gt) goto loc_82161100;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
loc_82161100:
	// cmpwi cr6,r31,2
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 2, ctx.xer);
	// b 0x82161118
	goto loc_82161118;
loc_82161108:
	// cmpwi cr6,r30,1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 1, ctx.xer);
	// ble cr6,0x82161114
	if (!ctx.cr6.gt) goto loc_82161114;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
loc_82161114:
	// cmpwi cr6,r31,1
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 1, ctx.xer);
loc_82161118:
	// ble cr6,0x82161120
	if (!ctx.cr6.gt) goto loc_82161120;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
loc_82161120:
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// lfs f0,-22560(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -22560);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	ctx.cr6.compare(ctx.f12.f64, ctx.f0.f64);
	// bge cr6,0x8216115c
	if (!ctx.cr6.lt) goto loc_8216115C;
	// lwz r10,8(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mullw r10,r10,r30
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r30.s32);
	// add r9,r10,r28
	ctx.r9.u64 = ctx.r10.u64 + ctx.r28.u64;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r10,r11
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfsx f13,r10,r11
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r11.u32, temp.u32);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// lfd f31,-48(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_8216115C:
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x82161190
	if (!ctx.cr6.lt) goto loc_82161190;
	// lwz r10,8(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mullw r10,r10,r31
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r31.s32);
	// add r9,r10,r28
	ctx.r9.u64 = ctx.r10.u64 + ctx.r28.u64;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r10,r11
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f31,f0
	ctx.f13.f64 = double(float(ctx.f31.f64 + ctx.f0.f64));
	// stfsx f13,r10,r11
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r11.u32, temp.u32);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// lfd f31,-48(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_82161190:
	// fmuls f0,f12,f5
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f5.f64));
	// fadds f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// fdivs f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
	// bl 0x82161ab0
	ctx.lr = 0x821611A0;
	sub_82161AB0(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r8,8(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mullw r10,r30,r8
	ctx.r10.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r8.s32);
	// lfs f0,14004(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14004);
	ctx.f0.f64 = double(temp.f32);
	// fadds f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 + ctx.f0.f64));
	// add r7,r10,r28
	ctx.r7.u64 = ctx.r10.u64 + ctx.r28.u64;
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// fdivs f10,f31,f11
	ctx.f10.f64 = double(float(ctx.f31.f64 / ctx.f11.f64));
	// lfsx f9,r10,r11
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	ctx.f9.f64 = double(temp.f32);
	// fadds f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 + ctx.f9.f64));
	// stfsx f8,r10,r11
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r11.u32, temp.u32);
	// lwz r6,8(r29)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// mullw r11,r31,r6
	ctx.r11.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r6.s32);
	// add r5,r11,r28
	ctx.r5.u64 = ctx.r11.u64 + ctx.r28.u64;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f7,r10,r11
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f6,f12,f10,f7
	ctx.f6.f64 = double(float(ctx.f12.f64 * ctx.f10.f64 + ctx.f7.f64));
	// stfsx f6,r10,r11
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r11.u32, temp.u32);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// lfd f31,-48(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82161200"))) PPC_WEAK_FUNC(sub_82161200);
PPC_FUNC_IMPL(__imp__sub_82161200) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x82161208;
	__savegprlr_24(ctx, base);
	// addi r12,r1,-72
	ctx.r12.s64 = ctx.r1.s64 + -72;
	// bl 0x82080334
	ctx.lr = 0x82161210;
	__savefpr_15(ctx, base);
	// stwu r1,-432(r1)
	ea = -432 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// li r5,12
	ctx.r5.s64 = 12;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// mr r26,r6
	ctx.r26.u64 = ctx.r6.u64;
	// mr r31,r7
	ctx.r31.u64 = ctx.r7.u64;
	// bl 0x8207dac0
	ctx.lr = 0x82161234;
	sub_8207DAC0(ctx, base);
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r3,r25,12
	ctx.r3.s64 = ctx.r25.s64 + 12;
	// bl 0x82161a58
	ctx.lr = 0x82161244;
	sub_82161A58(ctx, base);
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82161a58
	ctx.lr = 0x82161254;
	sub_82161A58(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,60(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 60);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// lfs f25,9388(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 9388);
	ctx.f25.f64 = double(temp.f32);
	// fmr f21,f25
	ctx.f21.f64 = ctx.f25.f64;
	// fmr f20,f25
	ctx.f20.f64 = ctx.f25.f64;
	// fmr f19,f25
	ctx.f19.f64 = ctx.f25.f64;
	// ble cr6,0x821612b0
	if (!ctx.cr6.gt) goto loc_821612B0;
	// lwz r10,12(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// lwz r9,4(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r8,8(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// lwz r7,64(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 64);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f20,f12,f11
	ctx.f20.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// fmuls f21,f13,f11
	ctx.f21.f64 = double(float(ctx.f13.f64 * ctx.f11.f64));
	// fmuls f19,f0,f11
	ctx.f19.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
loc_821612B0:
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82161710
	if (ctx.cr6.eq) goto loc_82161710;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// lfs f18,29540(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 29540);
	ctx.f18.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f16,12868(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12868);
	ctx.f16.f64 = double(temp.f32);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lfs f22,22952(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 22952);
	ctx.f22.f64 = double(temp.f32);
	// lfs f23,23040(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 23040);
	ctx.f23.f64 = double(temp.f32);
	// addi r24,r29,28
	ctx.r24.s64 = ctx.r29.s64 + 28;
	// lfs f24,21000(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 21000);
	ctx.f24.f64 = double(temp.f32);
	// li r27,0
	ctx.r27.s64 = 0;
	// lfs f26,-22560(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -22560);
	ctx.f26.f64 = double(temp.f32);
	// lfs f27,14004(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14004);
	ctx.f27.f64 = double(temp.f32);
	// lfs f17,22944(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 22944);
	ctx.f17.f64 = double(temp.f32);
loc_82161304:
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// ble cr6,0x82161414
	if (!ctx.cr6.gt) goto loc_82161414;
	// lwz r11,68(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 68);
	// lfsx f1,r27,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r11.u32);
	ctx.f1.f64 = double(temp.f32);
	// fcmpu cr6,f1,f17
	ctx.cr6.compare(ctx.f1.f64, ctx.f17.f64);
	// beq cr6,0x82161414
	if (ctx.cr6.eq) goto loc_82161414;
	// bl 0x8207af40
	ctx.lr = 0x82161320;
	sub_8207AF40(ctx, base);
	// lwz r11,68(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 68);
	// frsp f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = double(float(ctx.f1.f64));
	// lfsx f1,r27,r11
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r11.u32);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8207ae60
	ctx.lr = 0x82161330;
	sub_8207AE60(ctx, base);
	// lwz r9,24(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lwz r10,20(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// fsubs f0,f27,f31
	ctx.f0.f64 = double(float(ctx.f27.f64 - ctx.f31.f64));
	// lwz r8,16(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// lwz r7,32(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 32);
	// lwz r6,36(r29)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + 36);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// lfs f11,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f11.f64 = double(temp.f32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// lfs f10,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f8,f12,f10
	ctx.f8.f64 = double(float(ctx.f12.f64 * ctx.f10.f64));
	// stw r7,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r7.u32);
	// fmuls f7,f12,f11
	ctx.f7.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// stw r6,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r6.u32);
	// fmuls f1,f10,f11
	ctx.f1.f64 = double(float(ctx.f10.f64 * ctx.f11.f64));
	// lfs f6,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f5,f11,f13
	ctx.f5.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// lfs f4,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f3,f10,f13
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// lwz r5,0(r24)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// fmuls f2,f11,f11
	ctx.f2.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// fmuls f9,f10,f10
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmuls f10,f12,f13
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fmuls f11,f12,f12
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmuls f12,f8,f0
	ctx.f12.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// stw r5,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r5.u32);
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f8,f7,f0
	ctx.f8.f64 = double(float(ctx.f7.f64 * ctx.f0.f64));
	// fmadds f7,f2,f0,f31
	ctx.f7.f64 = double(float(ctx.f2.f64 * ctx.f0.f64 + ctx.f31.f64));
	// fmuls f2,f1,f0
	ctx.f2.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// fmadds f9,f9,f0,f31
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f0.f64 + ctx.f31.f64));
	// fmadds f1,f11,f0,f31
	ctx.f1.f64 = double(float(ctx.f11.f64 * ctx.f0.f64 + ctx.f31.f64));
	// fsubs f0,f12,f5
	ctx.f0.f64 = double(float(ctx.f12.f64 - ctx.f5.f64));
	// fadds f5,f5,f12
	ctx.f5.f64 = double(float(ctx.f5.f64 + ctx.f12.f64));
	// fsubs f11,f8,f3
	ctx.f11.f64 = double(float(ctx.f8.f64 - ctx.f3.f64));
	// fadds f8,f3,f8
	ctx.f8.f64 = double(float(ctx.f3.f64 + ctx.f8.f64));
	// fadds f3,f10,f2
	ctx.f3.f64 = double(float(ctx.f10.f64 + ctx.f2.f64));
	// fsubs f2,f2,f10
	ctx.f2.f64 = double(float(ctx.f2.f64 - ctx.f10.f64));
	// fmuls f0,f0,f20
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f20.f64));
	// fmuls f12,f11,f19
	ctx.f12.f64 = double(float(ctx.f11.f64 * ctx.f19.f64));
	// fmuls f11,f8,f20
	ctx.f11.f64 = double(float(ctx.f8.f64 * ctx.f20.f64));
	// fmadds f10,f9,f21,f0
	ctx.f10.f64 = double(float(ctx.f9.f64 * ctx.f21.f64 + ctx.f0.f64));
	// fmadds f9,f1,f20,f12
	ctx.f9.f64 = double(float(ctx.f1.f64 * ctx.f20.f64 + ctx.f12.f64));
	// fmadds f8,f7,f19,f11
	ctx.f8.f64 = double(float(ctx.f7.f64 * ctx.f19.f64 + ctx.f11.f64));
	// fmadds f7,f3,f19,f10
	ctx.f7.f64 = double(float(ctx.f3.f64 * ctx.f19.f64 + ctx.f10.f64));
	// fmadds f5,f5,f21,f9
	ctx.f5.f64 = double(float(ctx.f5.f64 * ctx.f21.f64 + ctx.f9.f64));
	// fmadds f3,f2,f21,f8
	ctx.f3.f64 = double(float(ctx.f2.f64 * ctx.f21.f64 + ctx.f8.f64));
	// fadds f2,f7,f13
	ctx.f2.f64 = double(float(ctx.f7.f64 + ctx.f13.f64));
	// stfs f2,160(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// fadds f1,f5,f6
	ctx.f1.f64 = double(float(ctx.f5.f64 + ctx.f6.f64));
	// stfs f1,164(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// fadds f0,f3,f4
	ctx.f0.f64 = double(float(ctx.f3.f64 + ctx.f4.f64));
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// b 0x82161424
	goto loc_82161424;
loc_82161414:
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// li r5,12
	ctx.r5.s64 = 12;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x8207dac0
	ctx.lr = 0x82161424;
	sub_8207DAC0(ctx, base);
loc_82161424:
	// lwz r11,60(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 60);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// ble cr6,0x82161440
	if (!ctx.cr6.gt) goto loc_82161440;
	// lwz r11,68(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 68);
	// lfsx f0,r11,r27
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r27.u32);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f17
	ctx.cr6.compare(ctx.f0.f64, ctx.f17.f64);
	// beq cr6,0x821616fc
	if (ctx.cr6.eq) goto loc_821616FC;
loc_82161440:
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// addi r4,r25,24
	ctx.r4.s64 = ctx.r25.s64 + 24;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82161a20
	ctx.lr = 0x82161450;
	sub_82161A20(ctx, base);
	// lfs f0,196(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	ctx.f0.f64 = double(temp.f32);
	// lfs f11,180(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	ctx.f11.f64 = double(temp.f32);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// fmuls f10,f0,f11
	ctx.f10.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// lfs f3,212(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	ctx.f3.f64 = double(temp.f32);
	// lfs f13,200(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f2,f3,f0
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f0.f64));
	// lfs f9,148(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,184(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f9,f0
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// lfs f1,216(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 216);
	ctx.f1.f64 = double(temp.f32);
	// lfs f12,192(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f12.f64 = double(temp.f32);
	// lfs f6,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,176(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f4.f64 = double(temp.f32);
	// fmadds f11,f13,f8,f10
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f8.f64 + ctx.f10.f64));
	// fmadds f9,f1,f13,f2
	ctx.f9.f64 = double(float(ctx.f1.f64 * ctx.f13.f64 + ctx.f2.f64));
	// fmadds f10,f6,f13,f7
	ctx.f10.f64 = double(float(ctx.f6.f64 * ctx.f13.f64 + ctx.f7.f64));
	// lfs f0,208(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 208);
	ctx.f0.f64 = double(temp.f32);
	// lfsx f28,r27,r11
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r11.u32);
	ctx.f28.f64 = double(temp.f32);
	// fmadds f1,f12,f5,f11
	ctx.f1.f64 = double(float(ctx.f12.f64 * ctx.f5.f64 + ctx.f11.f64));
	// stfsx f25,r27,r11
	temp.f32 = float(ctx.f25.f64);
	PPC_STORE_U32(ctx.r27.u32 + ctx.r11.u32, temp.u32);
	// fmadds f29,f0,f12,f9
	ctx.f29.f64 = double(float(ctx.f0.f64 * ctx.f12.f64 + ctx.f9.f64));
	// fmadds f2,f4,f12,f10
	ctx.f2.f64 = double(float(ctx.f4.f64 * ctx.f12.f64 + ctx.f10.f64));
	// fmuls f8,f1,f1
	ctx.f8.f64 = double(float(ctx.f1.f64 * ctx.f1.f64));
	// fmadds f7,f2,f2,f8
	ctx.f7.f64 = double(float(ctx.f2.f64 * ctx.f2.f64 + ctx.f8.f64));
	// fsqrts f31,f7
	ctx.f31.f64 = double(float(sqrt(ctx.f7.f64)));
	// fcmpu cr6,f31,f26
	ctx.cr6.compare(ctx.f31.f64, ctx.f26.f64);
	// bgt cr6,0x82161558
	if (ctx.cr6.gt) goto loc_82161558;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r9,8(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmpwi cr6,r9,-1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, -1, ctx.xer);
	// beq cr6,0x821614dc
	if (ctx.cr6.eq) goto loc_821614DC;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_821614DC:
	// rlwinm r9,r26,0,15,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x10000;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x821614ec
	if (ctx.cr6.eq) goto loc_821614EC;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_821614EC:
	// clrldi r8,r11,32
	ctx.r8.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// li r11,0
	ctx.r11.s64 = 0;
	// std r8,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r8.u64);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lfd f0,128(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fdivs f0,f28,f12
	ctx.f0.f64 = double(float(ctx.f28.f64 / ctx.f12.f64));
	// beq cr6,0x821616fc
	if (ctx.cr6.eq) goto loc_821616FC;
loc_82161510:
	// lwz r10,8(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x82161544
	if (ctx.cr6.eq) goto loc_82161544;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x8216152c
	if (!ctx.cr6.eq) goto loc_8216152C;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82161544
	if (!ctx.cr6.eq) goto loc_82161544;
loc_8216152C:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// add r7,r10,r30
	ctx.r7.u64 = ctx.r10.u64 + ctx.r30.u64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f0,r6,r8
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + ctx.r8.u32, temp.u32);
loc_82161544:
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82161510
	if (ctx.cr6.lt) goto loc_82161510;
	// b 0x821616fc
	goto loc_821616FC;
loc_82161558:
	// bl 0x8207b440
	ctx.lr = 0x8216155C;
	sub_8207B440(ctx, base);
	// lwz r11,56(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 56);
	// frsp f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = double(float(ctx.f1.f64));
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
	// lfs f1,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8207ae60
	ctx.lr = 0x82161570;
	sub_8207AE60(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// lwz r10,52(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 52);
	// stw r10,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// lfs f13,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f12,f0,f29,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 * ctx.f29.f64 + ctx.f13.f64));
	// fcmpu cr6,f31,f12
	ctx.cr6.compare(ctx.f31.f64, ctx.f12.f64);
	// blt cr6,0x82161598
	if (ctx.cr6.lt) goto loc_82161598;
	// fmr f2,f30
	ctx.f2.f64 = ctx.f30.f64;
	// fmr f1,f28
	ctx.f1.f64 = ctx.f28.f64;
	// b 0x82161600
	goto loc_82161600;
loc_82161598:
	// lwz r11,56(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 56);
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r11.u32);
	// lfs f1,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8207ae60
	ctx.lr = 0x821615A8;
	sub_8207AE60(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// lwz r10,52(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 52);
	// stw r10,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r10.u32);
	// lfs f13,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f12,f0,f29,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 * ctx.f29.f64 + ctx.f13.f64));
	// fsubs f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f31.f64));
	// fmuls f10,f12,f23
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f23.f64));
	// fmuls f9,f11,f24
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f24.f64));
	// fdivs f1,f9,f10
	ctx.f1.f64 = double(float(ctx.f9.f64 / ctx.f10.f64));
	// bl 0x82161ab0
	ctx.lr = 0x821615D0;
	sub_82161AB0(ctx, base);
	// frsp f29,f1
	ctx.fpscr.disableFlushMode();
	ctx.f29.f64 = double(float(ctx.f1.f64));
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// fmr f2,f30
	ctx.f2.f64 = ctx.f30.f64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fadds f8,f29,f27
	ctx.f8.f64 = double(float(ctx.f29.f64 + ctx.f27.f64));
	// fdivs f15,f28,f8
	ctx.f15.f64 = double(float(ctx.f28.f64 / ctx.f8.f64));
	// fmr f1,f15
	ctx.f1.f64 = ctx.f15.f64;
	// bl 0x82160bd8
	ctx.lr = 0x821615F8;
	sub_82160BD8(ctx, base);
	// fadds f2,f30,f22
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = double(float(ctx.f30.f64 + ctx.f22.f64));
	// fmuls f1,f15,f29
	ctx.f1.f64 = double(float(ctx.f15.f64 * ctx.f29.f64));
loc_82161600:
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82160bd8
	ctx.lr = 0x82161614;
	sub_82160BD8(ctx, base);
	// lwz r11,52(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 52);
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r11.u32);
	// lfs f0,120(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f0,f16
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f16.f64));
	// fcmpu cr6,f0,f18
	ctx.cr6.compare(ctx.f0.f64, ctx.f18.f64);
	// bge cr6,0x82161630
	if (!ctx.cr6.lt) goto loc_82161630;
	// fmr f0,f18
	ctx.f0.f64 = ctx.f18.f64;
loc_82161630:
	// fcmpu cr6,f31,f0
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f0.f64);
	// bgt cr6,0x821616fc
	if (ctx.cr6.gt) goto loc_821616FC;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r9,8(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmpwi cr6,r9,-1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, -1, ctx.xer);
	// beq cr6,0x82161650
	if (ctx.cr6.eq) goto loc_82161650;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_82161650:
	// rlwinm r8,r26,0,15,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x10000;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82161660
	if (ctx.cr6.eq) goto loc_82161660;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_82161660:
	// clrldi r9,r11,32
	ctx.r9.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// fsubs f13,f31,f26
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f31.f64 - ctx.f26.f64));
	// li r11,0
	ctx.r11.s64 = 0;
	// std r9,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r9.u64);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// fdivs f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 / ctx.f0.f64));
	// lfd f12,136(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fdivs f13,f28,f10
	ctx.f13.f64 = double(float(ctx.f28.f64 / ctx.f10.f64));
	// beq cr6,0x821616fc
	if (ctx.cr6.eq) goto loc_821616FC;
loc_8216168C:
	// lwz r10,8(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x821616ec
	if (ctx.cr6.eq) goto loc_821616EC;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x821616a8
	if (!ctx.cr6.eq) goto loc_821616A8;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x821616ec
	if (!ctx.cr6.eq) goto loc_821616EC;
loc_821616A8:
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// fsubs f12,f27,f0
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f27.f64 - ctx.f0.f64));
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mullw r9,r9,r11
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// add r7,r9,r30
	ctx.r7.u64 = ctx.r9.u64 + ctx.r30.u64;
	// rlwinm r9,r7,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f11,r9,r10
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// stfsx f10,r9,r10
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, temp.u32);
	// lwz r6,8(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// mullw r10,r6,r11
	ctx.r10.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r11.s32);
	// add r5,r10,r30
	ctx.r5.u64 = ctx.r10.u64 + ctx.r30.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r9,r5,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f9,r9,r10
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	ctx.f9.f64 = double(temp.f32);
	// fmadds f8,f12,f13,f9
	ctx.f8.f64 = double(float(ctx.f12.f64 * ctx.f13.f64 + ctx.f9.f64));
	// stfsx f8,r9,r10
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, temp.u32);
loc_821616EC:
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8216168c
	if (ctx.cr6.lt) goto loc_8216168C;
loc_821616FC:
	// lwz r11,60(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 60);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r27,r27,4
	ctx.r27.s64 = ctx.r27.s64 + 4;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82161304
	if (ctx.cr6.lt) goto loc_82161304;
loc_82161710:
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// addi r12,r1,-72
	ctx.r12.s64 = ctx.r1.s64 + -72;
	// bl 0x82080380
	ctx.lr = 0x8216171C;
	__restfpr_15(ctx, base);
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82161720"))) PPC_WEAK_FUNC(sub_82161720);
PPC_FUNC_IMPL(__imp__sub_82161720) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82161728;
	__savegprlr_29(ctx, base);
	// stfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.f30.u64);
	// stfd f31,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r5,12
	ctx.r5.s64 = 12;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// bl 0x8207dac0
	ctx.lr = 0x8216174C;
	sub_8207DAC0(ctx, base);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,12
	ctx.r3.s64 = ctx.r31.s64 + 12;
	// bl 0x82161a58
	ctx.lr = 0x8216175C;
	sub_82161A58(ctx, base);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82161a58
	ctx.lr = 0x8216176C;
	sub_82161A58(ctx, base);
	// addi r4,r29,28
	ctx.r4.s64 = ctx.r29.s64 + 28;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// li r5,12
	ctx.r5.s64 = 12;
	// bl 0x8207dac0
	ctx.lr = 0x8216177C;
	sub_8207DAC0(ctx, base);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r31,24
	ctx.r4.s64 = ctx.r31.s64 + 24;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82161a20
	ctx.lr = 0x8216178C;
	sub_82161A20(ctx, base);
	// lfs f13,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f10.f64 = double(temp.f32);
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// fmuls f9,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f10.f64));
	// lfs f12,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f12.f64 = double(temp.f32);
	// lfs f8,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f6,f8,f13
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f13.f64));
	// lfs f11,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// lfs f5,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f4.f64 = double(temp.f32);
	// lfs f0,-22560(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -22560);
	ctx.f0.f64 = double(temp.f32);
	// lfs f3,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f3.f64 = double(temp.f32);
	// fmadds f2,f12,f7,f9
	ctx.f2.f64 = double(float(ctx.f12.f64 * ctx.f7.f64 + ctx.f9.f64));
	// fmadds f1,f5,f12,f6
	ctx.f1.f64 = double(float(ctx.f5.f64 * ctx.f12.f64 + ctx.f6.f64));
	// fmadds f31,f11,f4,f2
	ctx.f31.f64 = double(float(ctx.f11.f64 * ctx.f4.f64 + ctx.f2.f64));
	// fmadds f2,f3,f11,f1
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f11.f64 + ctx.f1.f64));
	// fcmpu cr6,f31,f0
	ctx.cr6.compare(ctx.f31.f64, ctx.f0.f64);
	// bgt cr6,0x82161820
	if (ctx.cr6.gt) goto loc_82161820;
	// fcmpu cr6,f2,f0
	ctx.cr6.compare(ctx.f2.f64, ctx.f0.f64);
	// bgt cr6,0x82161820
	if (ctx.cr6.gt) goto loc_82161820;
	// lis r11,-32253
	ctx.r11.s64 = -2113732608;
	// lfs f0,29544(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 29544);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	ctx.cr6.compare(ctx.f31.f64, ctx.f0.f64);
	// blt cr6,0x82161820
	if (ctx.cr6.lt) goto loc_82161820;
	// fcmpu cr6,f2,f0
	ctx.cr6.compare(ctx.f2.f64, ctx.f0.f64);
	// blt cr6,0x82161820
	if (ctx.cr6.lt) goto loc_82161820;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// lfs f0,9388(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 9388);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r10)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// stfs f0,4(r9)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f30,-48(r1)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_82161820:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8207b440
	ctx.lr = 0x82161828;
	sub_8207B440(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// frsp f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64));
	// lfs f30,9388(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 9388);
	ctx.f30.f64 = double(temp.f32);
	// fcmpu cr6,f31,f30
	ctx.cr6.compare(ctx.f31.f64, ctx.f30.f64);
	// ble cr6,0x82161864
	if (!ctx.cr6.gt) goto loc_82161864;
	// bl 0x8207ae60
	ctx.lr = 0x82161840;
	sub_8207AE60(ctx, base);
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// stfs f30,4(r10)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f30,-48(r1)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_82161864:
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// fneg f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// stfs f30,0(r11)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// bl 0x8207ae60
	ctx.lr = 0x82161874;
	sub_8207AE60(ctx, base);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,4(r10)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f30,-48(r1)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82161890"))) PPC_WEAK_FUNC(sub_82161890);
PPC_FUNC_IMPL(__imp__sub_82161890) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82161898;
	__savegprlr_27(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r31,28
	ctx.r4.s64 = ctx.r31.s64 + 28;
	// addi r3,r28,24
	ctx.r3.s64 = ctx.r28.s64 + 24;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// bl 0x82161a20
	ctx.lr = 0x821618C0;
	sub_82161A20(ctx, base);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821619d8
	ctx.lr = 0x821618C8;
	sub_821619D8(ctx, base);
	// rlwinm r11,r27,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x40;
	// stfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r10,36(r30)
	PPC_STORE_U32(ctx.r30.u32 + 36, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821618f4
	if (ctx.cr6.eq) goto loc_821618F4;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8215fb20
	ctx.lr = 0x821618F4;
	sub_8215FB20(ctx, base);
loc_821618F4:
	// clrlwi r11,r27,27
	ctx.r11.u64 = ctx.r27.u32 & 0x1F;
	// rlwinm r11,r11,0,31,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82161990
	if (ctx.cr6.eq) goto loc_82161990;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8215fd30
	ctx.lr = 0x82161918;
	sub_8215FD30(ctx, base);
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x82161948
	if (!ctx.cr6.eq) goto loc_82161948;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82161948
	if (ctx.cr6.eq) goto loc_82161948;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x821601e8
	ctx.lr = 0x82161948;
	sub_821601E8(ctx, base);
loc_82161948:
	// lwz r11,48(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 48);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8216196c
	if (ctx.cr6.eq) goto loc_8216196C;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x821605e8
	ctx.lr = 0x8216196C;
	sub_821605E8(ctx, base);
loc_8216196C:
	// clrlwi r11,r27,31
	ctx.r11.u64 = ctx.r27.u32 & 0x1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82161990
	if (ctx.cr6.eq) goto loc_82161990;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82161200
	ctx.lr = 0x82161990;
	sub_82161200(ctx, base);
loc_82161990:
	// rlwinm r11,r27,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821619b0
	if (ctx.cr6.eq) goto loc_821619B0;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82161720
	ctx.lr = 0x821619B0;
	sub_82161720(ctx, base);
loc_821619B0:
	// rlwinm r11,r27,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821619d0
	if (ctx.cr6.eq) goto loc_821619D0;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82160a98
	ctx.lr = 0x821619D0;
	sub_82160A98(ctx, base);
loc_821619D0:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821619D8"))) PPC_WEAK_FUNC(sub_821619D8);
PPC_FUNC_IMPL(__imp__sub_821619D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// fmul f13,f0,f0
	ctx.f13.f64 = ctx.f0.f64 * ctx.f0.f64;
	// lfs f12,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fmadd f10,f12,f12,f13
	ctx.f10.f64 = ctx.f12.f64 * ctx.f12.f64 + ctx.f13.f64;
	// fmadd f9,f11,f11,f10
	ctx.f9.f64 = ctx.f11.f64 * ctx.f11.f64 + ctx.f10.f64;
	// fsqrts f1,f9
	ctx.f1.f64 = double(float(sqrt(ctx.f9.f64)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821619F8"))) PPC_WEAK_FUNC(sub_821619F8);
PPC_FUNC_IMPL(__imp__sub_821619F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// lfs f11,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f7,f11,f10,f12
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f10.f64 + ctx.f12.f64));
	// fmadds f1,f9,f8,f7
	ctx.f1.f64 = double(float(ctx.f9.f64 * ctx.f8.f64 + ctx.f7.f64));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82161A20"))) PPC_WEAK_FUNC(sub_82161A20);
PPC_FUNC_IMPL(__imp__sub_82161A20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f12,0(r5)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// lfs f11,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// stfs f9,4(r5)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r5.u32 + 4, temp.u32);
	// lfs f8,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f7.f64));
	// stfs f6,8(r5)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r5.u32 + 8, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82161A54"))) PPC_WEAK_FUNC(sub_82161A54);
PPC_FUNC_IMPL(__imp__sub_82161A54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82161A58"))) PPC_WEAK_FUNC(sub_82161A58);
PPC_FUNC_IMPL(__imp__sub_82161A58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f0,4(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// lfs f11,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// fmsubs f9,f11,f10,f12
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f10.f64 - ctx.f12.f64));
	// stfs f9,0(r5)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// lfs f8,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f4,f6,f5
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f5.f64));
	// fmsubs f3,f8,f7,f4
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f7.f64 - ctx.f4.f64));
	// stfs f3,4(r5)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r5.u32 + 4, temp.u32);
	// lfs f2,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lfs f0,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// fmsubs f11,f2,f1,f12
	ctx.f11.f64 = double(float(ctx.f2.f64 * ctx.f1.f64 - ctx.f12.f64));
	// stfs f11,8(r5)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r5.u32 + 8, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82161AB0"))) PPC_WEAK_FUNC(sub_82161AB0);
PPC_FUNC_IMPL(__imp__sub_82161AB0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfd f0,2432(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r11.u32 + 2432);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r11,-32253
	ctx.r11.s64 = -2113732608;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// addi r11,r11,29568
	ctx.r11.s64 = ctx.r11.s64 + 29568;
	// addi r9,r10,-14840
	ctx.r9.s64 = ctx.r10.s64 + -14840;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lfd f13,-14840(r10)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r10.u32 + -14840);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lfd f0,0(r11)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r11.u32 + 0);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// fmul f4,f1,f0
	ctx.f4.f64 = ctx.f1.f64 * ctx.f0.f64;
	// lfd f12,8(r9)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r9.u32 + 8);
	// lfd f10,32(r11)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r11.u32 + 32);
	// lfd f11,29680(r8)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r8.u32 + 29680);
	// lfd f9,80(r11)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r11.u32 + 80);
	// lfd f8,29672(r7)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r7.u32 + 29672);
	// lfd f7,29664(r10)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r10.u32 + 29664);
	// lfd f6,64(r11)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r11.u32 + 64);
	// lfd f0,48(r11)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r11.u32 + 48);
	// lfd f5,29656(r6)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r6.u32 + 29656);
	// fctid f4,f4
	ctx.f4.s64 = (ctx.f4.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvtsd_si64(simde_mm_load_sd(&ctx.f4.f64));
	// stfd f4,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f4.u64);
	// ld r10,-16(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// clrldi r10,r10,63
	ctx.r10.u64 = ctx.r10.u64 & 0x1;
	// fcfid f4,f4
	ctx.f4.f64 = double(ctx.f4.s64);
	// cmpdi cr6,r10,0
	ctx.cr6.compare<int64_t>(ctx.r10.s64, 0, ctx.xer);
	// fnmsub f13,f13,f4,f1
	ctx.f13.f64 = -(ctx.f13.f64 * ctx.f4.f64 - ctx.f1.f64);
	// fnmsub f13,f12,f4,f13
	ctx.f13.f64 = -(ctx.f12.f64 * ctx.f4.f64 - ctx.f13.f64);
	// fmul f12,f13,f13
	ctx.f12.f64 = ctx.f13.f64 * ctx.f13.f64;
	// fnmsub f11,f12,f11,f10
	ctx.f11.f64 = -(ctx.f12.f64 * ctx.f11.f64 - ctx.f10.f64);
	// fmsub f10,f12,f9,f8
	ctx.f10.f64 = ctx.f12.f64 * ctx.f9.f64 - ctx.f8.f64;
	// fmsub f11,f11,f12,f7
	ctx.f11.f64 = ctx.f11.f64 * ctx.f12.f64 - ctx.f7.f64;
	// fmadd f10,f10,f12,f6
	ctx.f10.f64 = ctx.f10.f64 * ctx.f12.f64 + ctx.f6.f64;
	// fmadd f11,f11,f12,f0
	ctx.f11.f64 = ctx.f11.f64 * ctx.f12.f64 + ctx.f0.f64;
	// fmsub f10,f10,f12,f5
	ctx.f10.f64 = ctx.f10.f64 * ctx.f12.f64 - ctx.f5.f64;
	// fmul f13,f11,f13
	ctx.f13.f64 = ctx.f11.f64 * ctx.f13.f64;
	// fmadd f0,f10,f12,f0
	ctx.f0.f64 = ctx.f10.f64 * ctx.f12.f64 + ctx.f0.f64;
	// beq cr6,0x82161b64
	if (ctx.cr6.eq) goto loc_82161B64;
	// fneg f13,f13
	ctx.f13.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// fdiv f0,f0,f13
	ctx.f0.f64 = ctx.f0.f64 / ctx.f13.f64;
	// b 0x82161b68
	goto loc_82161B68;
loc_82161B64:
	// fdiv f0,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f13.f64 / ctx.f0.f64;
loc_82161B68:
	// fabs f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = ctx.f1.u64 & ~0x8000000000000000;
	// lfd f13,16(r11)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r11.u32 + 16);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfd f12,2400(r11)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r11.u32 + 2400);
	// fsub f13,f11,f13
	ctx.f13.f64 = ctx.f11.f64 - ctx.f13.f64;
	// fsel f1,f13,f12,f0
	ctx.f1.f64 = ctx.f13.f64 >= 0.0 ? ctx.f12.f64 : ctx.f0.f64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82161B84"))) PPC_WEAK_FUNC(sub_82161B84);
PPC_FUNC_IMPL(__imp__sub_82161B84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82161B88"))) PPC_WEAK_FUNC(sub_82161B88);
PPC_FUNC_IMPL(__imp__sub_82161B88) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c950
	ctx.lr = 0x82161B90;
	__savegprlr_14(ctx, base);
	// li r11,16
	ctx.r11.s64 = 16;
	// stw r7,52(r1)
	PPC_STORE_U32(ctx.r1.u32 + 52, ctx.r7.u32);
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r10,r1,-226
	ctx.r10.s64 = ctx.r1.s64 + -226;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_82161BAC:
	// sthu r9,2(r10)
	ea = 2 + ctx.r10.u32;
	PPC_STORE_U16(ea, ctx.r9.u16);
	ctx.r10.u32 = ea;
	// bdnz 0x82161bac
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82161BAC;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82161be0
	if (ctx.cr6.eq) goto loc_82161BE0;
	// addi r9,r4,-2
	ctx.r9.s64 = ctx.r4.s64 + -2;
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
loc_82161BC4:
	// lhzu r10,2(r9)
	ea = 2 + ctx.r9.u32;
	ctx.r10.u64 = PPC_LOAD_U16(ea);
	ctx.r9.u32 = ea;
	// addi r11,r1,-224
	ctx.r11.s64 = ctx.r1.s64 + -224;
	// rotlwi r10,r10,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// lhzx r31,r10,r11
	ctx.r31.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r11.u32);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// sthx r31,r10,r11
	PPC_STORE_U16(ctx.r10.u32 + ctx.r11.u32, ctx.r31.u16);
	// bdnz 0x82161bc4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82161BC4;
loc_82161BE0:
	// lwz r14,0(r30)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// li r16,15
	ctx.r16.s64 = 15;
	// addi r11,r1,-194
	ctx.r11.s64 = ctx.r1.s64 + -194;
loc_82161BEC:
	// lhz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82161c08
	if (!ctx.cr6.eq) goto loc_82161C08;
	// addi r16,r16,-1
	ctx.r16.s64 = ctx.r16.s64 + -1;
	// addi r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -2;
	// cmplwi cr6,r16,1
	ctx.cr6.compare<uint32_t>(ctx.r16.u32, 1, ctx.xer);
	// bge cr6,0x82161bec
	if (!ctx.cr6.lt) goto loc_82161BEC;
loc_82161C08:
	// cmplw cr6,r14,r16
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, ctx.r16.u32, ctx.xer);
	// ble cr6,0x82161c14
	if (!ctx.cr6.gt) goto loc_82161C14;
	// mr r14,r16
	ctx.r14.u64 = ctx.r16.u64;
loc_82161C14:
	// cmplwi cr6,r16,0
	ctx.cr6.compare<uint32_t>(ctx.r16.u32, 0, ctx.xer);
	// li r21,1
	ctx.r21.s64 = 1;
	// bne cr6,0x82161c64
	if (!ctx.cr6.eq) goto loc_82161C64;
	// li r11,64
	ctx.r11.s64 = 64;
	// sth r7,-238(r1)
	PPC_STORE_U16(ctx.r1.u32 + -238, ctx.r7.u16);
	// stb r21,-239(r1)
	PPC_STORE_U8(ctx.r1.u32 + -239, ctx.r21.u8);
	// li r3,0
	ctx.r3.s64 = 0;
	// stb r11,-240(r1)
	PPC_STORE_U8(ctx.r1.u32 + -240, ctx.r11.u8);
	// lwz r9,0(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r10,-240(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -240);
	// stw r10,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// lwz r11,0(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r11,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r11.u32);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// lwz r11,0(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// addi r8,r11,4
	ctx.r8.s64 = ctx.r11.s64 + 4;
	// stw r8,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r8.u32);
	// stw r21,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r21.u32);
	// b 0x8207c9a0
	__restgprlr_14(ctx, base);
	return;
loc_82161C64:
	// addi r11,r1,-220
	ctx.r11.s64 = ctx.r1.s64 + -220;
	// mr r28,r21
	ctx.r28.u64 = ctx.r21.u64;
loc_82161C6C:
	// lhz r9,-2(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + -2);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82161cd8
	if (!ctx.cr6.eq) goto loc_82161CD8;
	// lhz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82161cbc
	if (!ctx.cr6.eq) goto loc_82161CBC;
	// lhz r9,2(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 2);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82161cc4
	if (!ctx.cr6.eq) goto loc_82161CC4;
	// lhz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82161ccc
	if (!ctx.cr6.eq) goto loc_82161CCC;
	// lhz r9,6(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 6);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82161cd4
	if (!ctx.cr6.eq) goto loc_82161CD4;
	// addi r28,r28,5
	ctx.r28.s64 = ctx.r28.s64 + 5;
	// addi r11,r11,10
	ctx.r11.s64 = ctx.r11.s64 + 10;
	// cmplwi cr6,r28,15
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 15, ctx.xer);
	// ble cr6,0x82161c6c
	if (!ctx.cr6.gt) goto loc_82161C6C;
	// b 0x82161cd8
	goto loc_82161CD8;
loc_82161CBC:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// b 0x82161cd8
	goto loc_82161CD8;
loc_82161CC4:
	// addi r28,r28,2
	ctx.r28.s64 = ctx.r28.s64 + 2;
	// b 0x82161cd8
	goto loc_82161CD8;
loc_82161CCC:
	// addi r28,r28,3
	ctx.r28.s64 = ctx.r28.s64 + 3;
	// b 0x82161cd8
	goto loc_82161CD8;
loc_82161CD4:
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
loc_82161CD8:
	// cmplw cr6,r14,r28
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, ctx.r28.u32, ctx.xer);
	// bge cr6,0x82161ce4
	if (!ctx.cr6.lt) goto loc_82161CE4;
	// mr r14,r28
	ctx.r14.u64 = ctx.r28.u64;
loc_82161CE4:
	// mr r10,r21
	ctx.r10.u64 = ctx.r21.u64;
	// mr r9,r21
	ctx.r9.u64 = ctx.r21.u64;
	// addi r11,r1,-222
	ctx.r11.s64 = ctx.r1.s64 + -222;
loc_82161CF0:
	// lhz r31,0(r11)
	ctx.r31.u64 = PPC_LOAD_U16(ctx.r11.u32 + 0);
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// subf. r10,r31,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r31.s64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// blt 0x82161df4
	if (ctx.cr0.lt) goto loc_82161DF4;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// cmplwi cr6,r9,15
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 15, ctx.xer);
	// ble cr6,0x82161cf0
	if (!ctx.cr6.gt) goto loc_82161CF0;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x82161d28
	if (!ctx.cr6.gt) goto loc_82161D28;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x82161df4
	if (ctx.cr6.eq) goto loc_82161DF4;
	// cmplwi cr6,r16,1
	ctx.cr6.compare<uint32_t>(ctx.r16.u32, 1, ctx.xer);
	// bne cr6,0x82161df4
	if (!ctx.cr6.eq) goto loc_82161DF4;
loc_82161D28:
	// li r10,7
	ctx.r10.s64 = 7;
	// sth r7,-190(r1)
	PPC_STORE_U16(ctx.r1.u32 + -190, ctx.r7.u16);
	// li r11,2
	ctx.r11.s64 = 2;
	// addi r31,r1,-192
	ctx.r31.s64 = ctx.r1.s64 + -192;
	// addi r30,r1,-224
	ctx.r30.s64 = ctx.r1.s64 + -224;
	// addi r29,r1,-190
	ctx.r29.s64 = ctx.r1.s64 + -190;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82161D44:
	// lhzx r9,r11,r31
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r31.u32);
	// addi r27,r1,-222
	ctx.r27.s64 = ctx.r1.s64 + -222;
	// lhzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r30.u32);
	// addi r26,r1,-188
	ctx.r26.s64 = ctx.r1.s64 + -188;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lhzx r9,r11,r27
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r27.u32);
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// sthx r10,r11,r29
	PPC_STORE_U16(ctx.r11.u32 + ctx.r29.u32, ctx.r10.u16);
	// sthx r9,r11,r26
	PPC_STORE_U16(ctx.r11.u32 + ctx.r26.u32, ctx.r9.u16);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x82161d44
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82161D44;
	// mr r31,r7
	ctx.r31.u64 = ctx.r7.u64;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82161dd0
	if (ctx.cr6.eq) goto loc_82161DD0;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
loc_82161D88:
	// lhz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82161dc4
	if (ctx.cr6.eq) goto loc_82161DC4;
	// clrlwi r10,r9,16
	ctx.r10.u64 = ctx.r9.u32 & 0xFFFF;
	// addi r9,r1,-192
	ctx.r9.s64 = ctx.r1.s64 + -192;
	// rotlwi r30,r10,1
	ctx.r30.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// addi r10,r1,-192
	ctx.r10.s64 = ctx.r1.s64 + -192;
	// lhzx r9,r30,r9
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r30.u32 + ctx.r9.u32);
	// rotlwi r9,r9,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// sthx r31,r9,r8
	PPC_STORE_U16(ctx.r9.u32 + ctx.r8.u32, ctx.r31.u16);
	// lhz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r11.u32 + 0);
	// rotlwi r9,r5,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r5.u32, 1);
	// lhzx r5,r9,r10
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r10.u32);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// sthx r5,r9,r10
	PPC_STORE_U16(ctx.r9.u32 + ctx.r10.u32, ctx.r5.u16);
loc_82161DC4:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// bdnz 0x82161d88
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82161D88;
loc_82161DD0:
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// blt cr6,0x82161e14
	if (ctx.cr6.lt) goto loc_82161E14;
	// lis r11,-32253
	ctx.r11.s64 = -2113732608;
	// addi r11,r11,29936
	ctx.r11.s64 = ctx.r11.s64 + 29936;
	// beq cr6,0x82161dfc
	if (ctx.cr6.eq) goto loc_82161DFC;
	// li r23,-1
	ctx.r23.s64 = -1;
	// addi r18,r11,-64
	ctx.r18.s64 = ctx.r11.s64 + -64;
	// mr r19,r11
	ctx.r19.u64 = ctx.r11.u64;
	// b 0x82161e20
	goto loc_82161E20;
loc_82161DF4:
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x8207c9a0
	__restgprlr_14(ctx, base);
	return;
loc_82161DFC:
	// addi r10,r11,-192
	ctx.r10.s64 = ctx.r11.s64 + -192;
	// addi r11,r11,-128
	ctx.r11.s64 = ctx.r11.s64 + -128;
	// li r23,256
	ctx.r23.s64 = 256;
	// addi r18,r10,-514
	ctx.r18.s64 = ctx.r10.s64 + -514;
	// addi r19,r11,-514
	ctx.r19.s64 = ctx.r11.s64 + -514;
	// b 0x82161e20
	goto loc_82161E20;
loc_82161E14:
	// mr r19,r8
	ctx.r19.u64 = ctx.r8.u64;
	// mr r18,r8
	ctx.r18.u64 = ctx.r8.u64;
	// li r23,19
	ctx.r23.s64 = 19;
loc_82161E20:
	// slw r11,r21,r14
	ctx.r11.u64 = ctx.r14.u8 & 0x20 ? 0 : (ctx.r21.u32 << (ctx.r14.u8 & 0x3F));
	// lwz r26,0(r6)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// li r25,-1
	ctx.r25.s64 = -1;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// mr r17,r11
	ctx.r17.u64 = ctx.r11.u64;
	// addi r15,r11,-1
	ctx.r15.s64 = ctx.r11.s64 + -1;
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x82161e50
	if (!ctx.cr6.eq) goto loc_82161E50;
	// cmplwi cr6,r11,1456
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1456, ctx.xer);
	// bge cr6,0x821620bc
	if (!ctx.cr6.lt) goto loc_821620BC;
loc_82161E50:
	// lis r11,0
	ctx.r11.s64 = 0;
	// mr r24,r8
	ctx.r24.u64 = ctx.r8.u64;
	// li r20,96
	ctx.r20.s64 = 96;
	// ori r22,r11,65535
	ctx.r22.u64 = ctx.r11.u64 | 65535;
loc_82161E60:
	// subf r10,r27,r28
	ctx.r10.s64 = ctx.r28.s64 - ctx.r27.s64;
	// lhz r11,0(r24)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r24.u32 + 0);
	// clrlwi r31,r10,24
	ctx.r31.u64 = ctx.r10.u32 & 0xFF;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// stb r31,-239(r1)
	PPC_STORE_U8(ctx.r1.u32 + -239, ctx.r31.u8);
	// cmpw cr6,r11,r23
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r23.s32, ctx.xer);
	// bge cr6,0x82161e88
	if (!ctx.cr6.lt) goto loc_82161E88;
	// sth r11,-238(r1)
	PPC_STORE_U16(ctx.r1.u32 + -238, ctx.r11.u16);
	// stb r7,-240(r1)
	PPC_STORE_U8(ctx.r1.u32 + -240, ctx.r7.u8);
	// b 0x82161eb0
	goto loc_82161EB0;
loc_82161E88:
	// ble cr6,0x82161ea8
	if (!ctx.cr6.gt) goto loc_82161EA8;
	// lhz r11,0(r24)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r24.u32 + 0);
	// rotlwi r9,r11,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// lhzx r8,r9,r19
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r19.u32);
	// lhzx r5,r9,r18
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r18.u32);
	// stb r8,-240(r1)
	PPC_STORE_U8(ctx.r1.u32 + -240, ctx.r8.u8);
	// sth r5,-238(r1)
	PPC_STORE_U16(ctx.r1.u32 + -238, ctx.r5.u16);
	// b 0x82161eb0
	goto loc_82161EB0;
loc_82161EA8:
	// stb r20,-240(r1)
	PPC_STORE_U8(ctx.r1.u32 + -240, ctx.r20.u8);
	// sth r7,-238(r1)
	PPC_STORE_U16(ctx.r1.u32 + -238, ctx.r7.u16);
loc_82161EB0:
	// srw r11,r29,r27
	ctx.r11.u64 = ctx.r27.u8 & 0x20 ? 0 : (ctx.r29.u32 >> (ctx.r27.u8 & 0x3F));
	// lwz r5,-240(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + -240);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// slw r9,r21,r10
	ctx.r9.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r21.u32 << (ctx.r10.u8 & 0x3F));
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
loc_82161ED0:
	// subf r11,r8,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r8.s64;
	// subf. r10,r9,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r9.s64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r5,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r5.u32);
	// bne 0x82161ed0
	if (!ctx.cr0.eq) goto loc_82161ED0;
	// addi r11,r28,-1
	ctx.r11.s64 = ctx.r28.s64 + -1;
	// slw r11,r21,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r21.u32 << (ctx.r11.u8 & 0x3F));
	// and r10,r11,r29
	ctx.r10.u64 = ctx.r11.u64 & ctx.r29.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82161f04
	if (ctx.cr6.eq) goto loc_82161F04;
loc_82161EF4:
	// rlwinm r11,r11,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// and r10,r11,r29
	ctx.r10.u64 = ctx.r11.u64 & ctx.r29.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82161ef4
	if (!ctx.cr6.eq) goto loc_82161EF4;
loc_82161F04:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82161f1c
	if (ctx.cr6.eq) goto loc_82161F1C;
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// and r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 & ctx.r29.u64;
	// add r29,r10,r11
	ctx.r29.u64 = ctx.r10.u64 + ctx.r11.u64;
	// b 0x82161f20
	goto loc_82161F20;
loc_82161F1C:
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
loc_82161F20:
	// rlwinm r10,r28,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r1,-224
	ctx.r11.s64 = ctx.r1.s64 + -224;
	// addi r24,r24,2
	ctx.r24.s64 = ctx.r24.s64 + 2;
	// lhzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r11.u32);
	// add r8,r9,r22
	ctx.r8.u64 = ctx.r9.u64 + ctx.r22.u64;
	// clrlwi r5,r8,16
	ctx.r5.u64 = ctx.r8.u32 & 0xFFFF;
	// sthx r5,r10,r11
	PPC_STORE_U16(ctx.r10.u32 + ctx.r11.u32, ctx.r5.u16);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bne cr6,0x82161f58
	if (!ctx.cr6.eq) goto loc_82161F58;
	// cmplw cr6,r28,r16
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r16.u32, ctx.xer);
	// beq cr6,0x82162014
	if (ctx.cr6.eq) goto loc_82162014;
	// lhz r11,0(r24)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r24.u32 + 0);
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// lhzx r28,r10,r4
	ctx.r28.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r4.u32);
loc_82161F58:
	// cmplw cr6,r28,r14
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r14.u32, ctx.xer);
	// ble cr6,0x82161e60
	if (!ctx.cr6.gt) goto loc_82161E60;
	// and r31,r15,r29
	ctx.r31.u64 = ctx.r15.u64 & ctx.r29.u64;
	// cmplw cr6,r31,r25
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r25.u32, ctx.xer);
	// beq cr6,0x82161e60
	if (ctx.cr6.eq) goto loc_82161E60;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// bne cr6,0x82161f78
	if (!ctx.cr6.eq) goto loc_82161F78;
	// mr r27,r14
	ctx.r27.u64 = ctx.r14.u64;
loc_82161F78:
	// subf r11,r27,r28
	ctx.r11.s64 = ctx.r28.s64 - ctx.r27.s64;
	// rlwinm r9,r30,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r27,r11
	ctx.r10.u64 = ctx.r27.u64 + ctx.r11.u64;
	// add r26,r9,r26
	ctx.r26.u64 = ctx.r9.u64 + ctx.r26.u64;
	// slw r8,r21,r11
	ctx.r8.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r21.u32 << (ctx.r11.u8 & 0x3F));
	// cmplw cr6,r10,r16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r16.u32, ctx.xer);
	// bge cr6,0x82161fc4
	if (!ctx.cr6.lt) goto loc_82161FC4;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r5,r1,-224
	ctx.r5.s64 = ctx.r1.s64 + -224;
	// add r9,r9,r5
	ctx.r9.u64 = ctx.r9.u64 + ctx.r5.u64;
loc_82161FA0:
	// lhz r5,0(r9)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r9.u32 + 0);
	// subf. r8,r5,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r5.s64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// ble 0x82161fc4
	if (!ctx.cr0.gt) goto loc_82161FC4;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplw cr6,r10,r16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r16.u32, ctx.xer);
	// blt cr6,0x82161fa0
	if (ctx.cr6.lt) goto loc_82161FA0;
loc_82161FC4:
	// slw r30,r21,r11
	ctx.r30.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r21.u32 << (ctx.r11.u8 & 0x3F));
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// add r17,r30,r17
	ctx.r17.u64 = ctx.r30.u64 + ctx.r17.u64;
	// bne cr6,0x82161fdc
	if (!ctx.cr6.eq) goto loc_82161FDC;
	// cmplwi cr6,r17,1456
	ctx.cr6.compare<uint32_t>(ctx.r17.u32, 1456, ctx.xer);
	// bge cr6,0x821620bc
	if (!ctx.cr6.lt) goto loc_821620BC;
loc_82161FDC:
	// lwz r9,0(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r25,r31
	ctx.r25.u64 = ctx.r31.u64;
	// stbx r11,r10,r9
	PPC_STORE_U8(ctx.r10.u32 + ctx.r9.u32, ctx.r11.u8);
	// lwz r11,0(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stb r14,1(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1, ctx.r14.u8);
	// lwz r11,0(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// subf r9,r11,r26
	ctx.r9.s64 = ctx.r26.s64 - ctx.r11.s64;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + ctx.r11.u64;
	// srawi r5,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r5.s64 = ctx.r9.s32 >> 2;
	// clrlwi r11,r5,16
	ctx.r11.u64 = ctx.r5.u32 & 0xFFFF;
	// sth r11,2(r8)
	PPC_STORE_U16(ctx.r8.u32 + 2, ctx.r11.u16);
	// b 0x82161e60
	goto loc_82161E60;
loc_82162014:
	// li r11,64
	ctx.r11.s64 = 64;
	// stb r31,-239(r1)
	PPC_STORE_U8(ctx.r1.u32 + -239, ctx.r31.u8);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// sth r7,-238(r1)
	PPC_STORE_U16(ctx.r1.u32 + -238, ctx.r7.u16);
	// stb r11,-240(r1)
	PPC_STORE_U8(ctx.r1.u32 + -240, ctx.r11.u8);
	// beq cr6,0x8216209c
	if (ctx.cr6.eq) goto loc_8216209C;
loc_8216202C:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82162050
	if (ctx.cr6.eq) goto loc_82162050;
	// and r11,r15,r29
	ctx.r11.u64 = ctx.r15.u64 & ctx.r29.u64;
	// cmplw cr6,r11,r25
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r25.u32, ctx.xer);
	// beq cr6,0x82162050
	if (ctx.cr6.eq) goto loc_82162050;
	// lwz r26,0(r6)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// stb r14,-239(r1)
	PPC_STORE_U8(ctx.r1.u32 + -239, ctx.r14.u8);
	// mr r28,r14
	ctx.r28.u64 = ctx.r14.u64;
loc_82162050:
	// srw r11,r29,r27
	ctx.r11.u64 = ctx.r27.u8 & 0x20 ? 0 : (ctx.r29.u32 >> (ctx.r27.u8 & 0x3F));
	// lwz r10,-240(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -240);
	// addi r9,r28,-1
	ctx.r9.s64 = ctx.r28.s64 + -1;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// slw r11,r21,r9
	ctx.r11.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r21.u32 << (ctx.r9.u8 & 0x3F));
	// and r5,r11,r29
	ctx.r5.u64 = ctx.r11.u64 & ctx.r29.u64;
	// stwx r10,r8,r26
	PPC_STORE_U32(ctx.r8.u32 + ctx.r26.u32, ctx.r10.u32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82162084
	if (ctx.cr6.eq) goto loc_82162084;
loc_82162074:
	// rlwinm r11,r11,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// and r10,r11,r29
	ctx.r10.u64 = ctx.r11.u64 & ctx.r29.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82162074
	if (!ctx.cr6.eq) goto loc_82162074;
loc_82162084:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8216209c
	if (ctx.cr6.eq) goto loc_8216209C;
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// and r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 & ctx.r29.u64;
	// add. r29,r10,r11
	ctx.r29.u64 = ctx.r10.u64 + ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne 0x8216202c
	if (!ctx.cr0.eq) goto loc_8216202C;
loc_8216209C:
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// rlwinm r11,r17,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,52(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 52);
	// li r3,0
	ctx.r3.s64 = 0;
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r8,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r8.u32);
	// stw r14,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r14.u32);
	// b 0x8207c9a0
	__restgprlr_14(ctx, base);
	return;
loc_821620BC:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8207c9a0
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821620C4"))) PPC_WEAK_FUNC(sub_821620C4);
PPC_FUNC_IMPL(__imp__sub_821620C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821620C8"))) PPC_WEAK_FUNC(sub_821620C8);
PPC_FUNC_IMPL(__imp__sub_821620C8) {
	PPC_FUNC_PROLOGUE();
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// b 0x8207c068
	sub_8207C068(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821620D0"))) PPC_WEAK_FUNC(sub_821620D0);
PPC_FUNC_IMPL(__imp__sub_821620D0) {
	PPC_FUNC_PROLOGUE();
	// mullw r3,r4,r5
	ctx.r3.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r5.s32);
	// b 0x8207a400
	sub_8207A400(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821620D8"))) PPC_WEAK_FUNC(sub_821620D8);
PPC_FUNC_IMPL(__imp__sub_821620D8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c964
	ctx.lr = 0x821620E0;
	__savegprlr_19(ctx, base);
	// rlwinm r10,r3,0,16,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFF00;
	// rlwinm r11,r3,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r9,r3,24,16,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 24) & 0xFF00;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r10,r3,8,24,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 8) & 0xFF;
	// rlwinm r11,r11,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r11,r8,30040
	ctx.r11.s64 = ctx.r8.s64 + 30040;
	// not r9,r10
	ctx.r9.u64 = ~ctx.r10.u64;
	// beq cr6,0x8216214c
	if (ctx.cr6.eq) goto loc_8216214C;
loc_82162114:
	// clrlwi r10,r4,30
	ctx.r10.u64 = ctx.r4.u32 & 0x3;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8216214c
	if (ctx.cr6.eq) goto loc_8216214C;
	// lbz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// rlwinm r8,r9,8,24,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFF;
	// addi r7,r11,4096
	ctx.r7.s64 = ctx.r11.s64 + 4096;
	// xor r6,r8,r10
	ctx.r6.u64 = ctx.r8.u64 ^ ctx.r10.u64;
	// rlwinm r3,r9,8,0,23
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r10,r6,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// addic. r5,r5,-1
	ctx.xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// lwzx r9,r10,r7
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r7.u32);
	// xor r9,r9,r3
	ctx.r9.u64 = ctx.r9.u64 ^ ctx.r3.u64;
	// bne 0x82162114
	if (!ctx.cr0.eq) goto loc_82162114;
loc_8216214C:
	// addi r10,r4,-4
	ctx.r10.s64 = ctx.r4.s64 + -4;
	// cmplwi cr6,r5,32
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 32, ctx.xer);
	// blt cr6,0x82162388
	if (ctx.cr6.lt) goto loc_82162388;
	// rlwinm r8,r5,27,5,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x7FFFFFF;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_82162160:
	// lwzu r8,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// addi r7,r11,6144
	ctx.r7.s64 = ctx.r11.s64 + 6144;
	// addi r6,r11,5120
	ctx.r6.s64 = ctx.r11.s64 + 5120;
	// xor r4,r8,r9
	ctx.r4.u64 = ctx.r8.u64 ^ ctx.r9.u64;
	// addi r3,r11,7168
	ctx.r3.s64 = ctx.r11.s64 + 7168;
	// rlwinm r8,r4,26,22,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 26) & 0x3FC;
	// rlwinm r9,r4,18,22,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 18) & 0x3FC;
	// lwzu r31,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r31.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// rlwinm r30,r4,10,22,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 10) & 0x3FC;
	// rlwinm r4,r4,2,22,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x3FC;
	// addi r29,r11,4096
	ctx.r29.s64 = ctx.r11.s64 + 4096;
	// lwzx r6,r8,r6
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r6.u32);
	// addi r8,r11,5120
	ctx.r8.s64 = ctx.r11.s64 + 5120;
	// lwzx r9,r9,r7
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r7.u32);
	// addi r7,r11,6144
	ctx.r7.s64 = ctx.r11.s64 + 6144;
	// lwzx r3,r30,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r3.u32);
	// addi r30,r11,7168
	ctx.r30.s64 = ctx.r11.s64 + 7168;
	// xor r9,r9,r6
	ctx.r9.u64 = ctx.r9.u64 ^ ctx.r6.u64;
	// lwzu r6,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r6.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// lwzx r4,r4,r29
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r29.u32);
	// addi r29,r11,4096
	ctx.r29.s64 = ctx.r11.s64 + 4096;
	// xor r3,r9,r3
	ctx.r3.u64 = ctx.r9.u64 ^ ctx.r3.u64;
	// addi r9,r11,6144
	ctx.r9.s64 = ctx.r11.s64 + 6144;
	// xor r4,r3,r4
	ctx.r4.u64 = ctx.r3.u64 ^ ctx.r4.u64;
	// addi r3,r11,5120
	ctx.r3.s64 = ctx.r11.s64 + 5120;
	// lwzu r28,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r28.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// xor r4,r4,r31
	ctx.r4.u64 = ctx.r4.u64 ^ ctx.r31.u64;
	// addi r31,r11,7168
	ctx.r31.s64 = ctx.r11.s64 + 7168;
	// rlwinm r27,r4,18,22,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 18) & 0x3FC;
	// rlwinm r26,r4,26,22,29
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 26) & 0x3FC;
	// rlwinm r25,r4,10,22,29
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 10) & 0x3FC;
	// lwzu r24,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r24.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// rlwinm r4,r4,2,22,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x3FC;
	// addi r23,r11,4096
	ctx.r23.s64 = ctx.r11.s64 + 4096;
	// lwzx r7,r27,r7
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r7.u32);
	// addi r27,r11,6144
	ctx.r27.s64 = ctx.r11.s64 + 6144;
	// lwzx r8,r26,r8
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r26.u32 + ctx.r8.u32);
	// addi r26,r11,5120
	ctx.r26.s64 = ctx.r11.s64 + 5120;
	// lwzx r30,r25,r30
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r25.u32 + ctx.r30.u32);
	// addi r25,r11,7168
	ctx.r25.s64 = ctx.r11.s64 + 7168;
	// xor r7,r7,r8
	ctx.r7.u64 = ctx.r7.u64 ^ ctx.r8.u64;
	// lwzx r4,r4,r29
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r29.u32);
	// addi r8,r11,4096
	ctx.r8.s64 = ctx.r11.s64 + 4096;
	// lwzu r29,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r29.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// xor r7,r7,r30
	ctx.r7.u64 = ctx.r7.u64 ^ ctx.r30.u64;
	// addi r30,r11,6144
	ctx.r30.s64 = ctx.r11.s64 + 6144;
	// xor r4,r7,r4
	ctx.r4.u64 = ctx.r7.u64 ^ ctx.r4.u64;
	// addi r7,r11,5120
	ctx.r7.s64 = ctx.r11.s64 + 5120;
	// xor r6,r4,r6
	ctx.r6.u64 = ctx.r4.u64 ^ ctx.r6.u64;
	// lwzu r4,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r4.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// addi r22,r11,7168
	ctx.r22.s64 = ctx.r11.s64 + 7168;
	// rlwinm r21,r6,18,22,29
	ctx.r21.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 18) & 0x3FC;
	// rlwinm r20,r6,26,22,29
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 26) & 0x3FC;
	// rlwinm r19,r6,10,22,29
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 10) & 0x3FC;
	// rlwinm r6,r6,2,22,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x3FC;
	// lwzx r9,r21,r9
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r21.u32 + ctx.r9.u32);
	// lwzx r3,r20,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r20.u32 + ctx.r3.u32);
	// lwzx r31,r19,r31
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r19.u32 + ctx.r31.u32);
	// xor r9,r9,r3
	ctx.r9.u64 = ctx.r9.u64 ^ ctx.r3.u64;
	// lwzx r6,r6,r23
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r23.u32);
	// xor r3,r9,r31
	ctx.r3.u64 = ctx.r9.u64 ^ ctx.r31.u64;
	// xor r9,r3,r6
	ctx.r9.u64 = ctx.r3.u64 ^ ctx.r6.u64;
	// xor r6,r9,r28
	ctx.r6.u64 = ctx.r9.u64 ^ ctx.r28.u64;
	// rlwinm r3,r6,18,22,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 18) & 0x3FC;
	// rlwinm r9,r6,26,22,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 26) & 0x3FC;
	// rlwinm r31,r6,10,22,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 10) & 0x3FC;
	// rlwinm r6,r6,2,22,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x3FC;
	// lwzx r3,r3,r27
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r27.u32);
	// lwzx r9,r9,r26
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r26.u32);
	// lwzx r31,r31,r25
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r25.u32);
	// xor r3,r3,r9
	ctx.r3.u64 = ctx.r3.u64 ^ ctx.r9.u64;
	// lwzx r9,r6,r8
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
	// xor r8,r3,r31
	ctx.r8.u64 = ctx.r3.u64 ^ ctx.r31.u64;
	// xor r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 ^ ctx.r9.u64;
	// xor r3,r6,r24
	ctx.r3.u64 = ctx.r6.u64 ^ ctx.r24.u64;
	// rlwinm r9,r3,18,22,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 18) & 0x3FC;
	// rlwinm r8,r3,26,22,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 26) & 0x3FC;
	// rlwinm r6,r3,10,22,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 10) & 0x3FC;
	// rlwinm r3,r3,2,22,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x3FC;
	// lwzx r9,r9,r30
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r30.u32);
	// lwzx r8,r8,r7
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// addi r7,r11,4096
	ctx.r7.s64 = ctx.r11.s64 + 4096;
	// lwzx r6,r6,r22
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r22.u32);
	// xor r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 ^ ctx.r8.u64;
	// lwzu r8,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// addi r31,r11,6144
	ctx.r31.s64 = ctx.r11.s64 + 6144;
	// xor r6,r9,r6
	ctx.r6.u64 = ctx.r9.u64 ^ ctx.r6.u64;
	// addi r9,r11,5120
	ctx.r9.s64 = ctx.r11.s64 + 5120;
	// lwzx r7,r3,r7
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r7.u32);
	// addi r3,r11,7168
	ctx.r3.s64 = ctx.r11.s64 + 7168;
	// addi r30,r11,4096
	ctx.r30.s64 = ctx.r11.s64 + 4096;
	// xor r7,r6,r7
	ctx.r7.u64 = ctx.r6.u64 ^ ctx.r7.u64;
	// addi r6,r11,6144
	ctx.r6.s64 = ctx.r11.s64 + 6144;
	// xor r7,r7,r29
	ctx.r7.u64 = ctx.r7.u64 ^ ctx.r29.u64;
	// addi r29,r11,5120
	ctx.r29.s64 = ctx.r11.s64 + 5120;
	// rlwinm r28,r7,18,22,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 18) & 0x3FC;
	// rlwinm r27,r7,26,22,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 26) & 0x3FC;
	// rlwinm r26,r7,10,22,29
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 10) & 0x3FC;
	// rlwinm r7,r7,2,22,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x3FC;
	// addi r25,r11,7168
	ctx.r25.s64 = ctx.r11.s64 + 7168;
	// lwzx r31,r28,r31
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r28.u32 + ctx.r31.u32);
	// addi r28,r11,4096
	ctx.r28.s64 = ctx.r11.s64 + 4096;
	// lwzx r9,r27,r9
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r9.u32);
	// addi r27,r11,6144
	ctx.r27.s64 = ctx.r11.s64 + 6144;
	// lwzx r3,r26,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r26.u32 + ctx.r3.u32);
	// addi r26,r11,5120
	ctx.r26.s64 = ctx.r11.s64 + 5120;
	// xor r9,r31,r9
	ctx.r9.u64 = ctx.r31.u64 ^ ctx.r9.u64;
	// lwzx r7,r7,r30
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r30.u32);
	// addi r31,r11,7168
	ctx.r31.s64 = ctx.r11.s64 + 7168;
	// xor r3,r9,r3
	ctx.r3.u64 = ctx.r9.u64 ^ ctx.r3.u64;
	// addi r9,r11,4096
	ctx.r9.s64 = ctx.r11.s64 + 4096;
	// xor r7,r3,r7
	ctx.r7.u64 = ctx.r3.u64 ^ ctx.r7.u64;
	// addi r5,r5,-32
	ctx.r5.s64 = ctx.r5.s64 + -32;
	// xor r4,r7,r4
	ctx.r4.u64 = ctx.r7.u64 ^ ctx.r4.u64;
	// rlwinm r3,r4,18,22,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 18) & 0x3FC;
	// rlwinm r7,r4,26,22,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 26) & 0x3FC;
	// rlwinm r30,r4,10,22,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 10) & 0x3FC;
	// rlwinm r4,r4,2,22,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x3FC;
	// lwzx r3,r3,r6
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r6.u32);
	// lwzx r7,r7,r29
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r29.u32);
	// lwzx r6,r30,r25
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r25.u32);
	// xor r3,r3,r7
	ctx.r3.u64 = ctx.r3.u64 ^ ctx.r7.u64;
	// lwzx r7,r4,r28
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r28.u32);
	// xor r6,r3,r6
	ctx.r6.u64 = ctx.r3.u64 ^ ctx.r6.u64;
	// xor r4,r6,r7
	ctx.r4.u64 = ctx.r6.u64 ^ ctx.r7.u64;
	// xor r3,r4,r8
	ctx.r3.u64 = ctx.r4.u64 ^ ctx.r8.u64;
	// rlwinm r8,r3,18,22,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 18) & 0x3FC;
	// rlwinm r7,r3,26,22,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 26) & 0x3FC;
	// rlwinm r6,r3,10,22,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 10) & 0x3FC;
	// rlwinm r4,r3,2,22,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x3FC;
	// lwzx r3,r8,r27
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r27.u32);
	// lwzx r8,r7,r26
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r26.u32);
	// lwzx r7,r6,r31
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r31.u32);
	// xor r6,r3,r8
	ctx.r6.u64 = ctx.r3.u64 ^ ctx.r8.u64;
	// lwzx r4,r4,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r9.u32);
	// xor r3,r6,r7
	ctx.r3.u64 = ctx.r6.u64 ^ ctx.r7.u64;
	// xor r9,r3,r4
	ctx.r9.u64 = ctx.r3.u64 ^ ctx.r4.u64;
	// bdnz 0x82162160
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82162160;
loc_82162388:
	// cmplwi cr6,r5,4
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 4, ctx.xer);
	// blt cr6,0x821623e4
	if (ctx.cr6.lt) goto loc_821623E4;
	// rlwinm r8,r5,30,2,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x3FFFFFFF;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_82162398:
	// lwzu r8,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// addi r7,r11,6144
	ctx.r7.s64 = ctx.r11.s64 + 6144;
	// addi r6,r11,5120
	ctx.r6.s64 = ctx.r11.s64 + 5120;
	// xor r4,r8,r9
	ctx.r4.u64 = ctx.r8.u64 ^ ctx.r9.u64;
	// addi r3,r11,7168
	ctx.r3.s64 = ctx.r11.s64 + 7168;
	// rlwinm r9,r4,18,22,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 18) & 0x3FC;
	// rlwinm r8,r4,26,22,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 26) & 0x3FC;
	// rlwinm r31,r4,10,22,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 10) & 0x3FC;
	// rlwinm r4,r4,2,22,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x3FC;
	// addi r30,r11,4096
	ctx.r30.s64 = ctx.r11.s64 + 4096;
	// lwzx r9,r9,r7
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r7.u32);
	// addi r5,r5,-4
	ctx.r5.s64 = ctx.r5.s64 + -4;
	// lwzx r8,r8,r6
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r6.u32);
	// lwzx r7,r31,r3
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r3.u32);
	// xor r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 ^ ctx.r8.u64;
	// lwzx r4,r4,r30
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r30.u32);
	// xor r3,r6,r7
	ctx.r3.u64 = ctx.r6.u64 ^ ctx.r7.u64;
	// xor r9,r3,r4
	ctx.r9.u64 = ctx.r3.u64 ^ ctx.r4.u64;
	// bdnz 0x82162398
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82162398;
loc_821623E4:
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x8216241c
	if (ctx.cr6.eq) goto loc_8216241C;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
loc_821623F4:
	// lbzu r4,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r4.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// rlwinm r7,r9,8,24,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFF;
	// rlwinm r3,r9,8,0,23
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// xor r9,r7,r4
	ctx.r9.u64 = ctx.r7.u64 ^ ctx.r4.u64;
	// addi r6,r11,4096
	ctx.r6.s64 = ctx.r11.s64 + 4096;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addic. r5,r5,-1
	ctx.xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// lwzx r7,r8,r6
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r6.u32);
	// xor r9,r7,r3
	ctx.r9.u64 = ctx.r7.u64 ^ ctx.r3.u64;
	// bne 0x821623f4
	if (!ctx.cr0.eq) goto loc_821623F4;
loc_8216241C:
	// not r8,r9
	ctx.r8.u64 = ~ctx.r9.u64;
	// rlwinm r10,r8,0,16,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFF00;
	// rlwinm r11,r8,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r9,r8,24,16,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 24) & 0xFF00;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r10,r8,8,24,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFF;
	// rlwinm r11,r7,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x8207c9b4
	__restgprlr_19(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82162444"))) PPC_WEAK_FUNC(sub_82162444);
PPC_FUNC_IMPL(__imp__sub_82162444) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82162448"))) PPC_WEAK_FUNC(sub_82162448);
PPC_FUNC_IMPL(__imp__sub_82162448) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c968
	ctx.lr = 0x82162450;
	__savegprlr_20(ctx, base);
	// lis r11,-32253
	ctx.r11.s64 = -2113732608;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// not r9,r3
	ctx.r9.u64 = ~ctx.r3.u64;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// addi r11,r11,30040
	ctx.r11.s64 = ctx.r11.s64 + 30040;
	// beq cr6,0x82162498
	if (ctx.cr6.eq) goto loc_82162498;
loc_82162468:
	// clrlwi r8,r10,30
	ctx.r8.u64 = ctx.r10.u32 & 0x3;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x82162498
	if (ctx.cr6.eq) goto loc_82162498;
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// rlwinm r7,r9,24,8,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 24) & 0xFFFFFF;
	// addic. r5,r5,-1
	ctx.xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// xor r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 ^ ctx.r9.u64;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r4,r6,2,22,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x3FC;
	// lwzx r3,r4,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r11.u32);
	// xor r9,r3,r7
	ctx.r9.u64 = ctx.r3.u64 ^ ctx.r7.u64;
	// bne 0x82162468
	if (!ctx.cr0.eq) goto loc_82162468;
loc_82162498:
	// cmplwi cr6,r5,32
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 32, ctx.xer);
	// blt cr6,0x821626b4
	if (ctx.cr6.lt) goto loc_821626B4;
	// rlwinm r8,r5,27,5,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x7FFFFFF;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_821624A8:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r7,r11,1024
	ctx.r7.s64 = ctx.r11.s64 + 1024;
	// addi r6,r11,2048
	ctx.r6.s64 = ctx.r11.s64 + 2048;
	// lwzu r4,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r4.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// xor r3,r8,r9
	ctx.r3.u64 = ctx.r8.u64 ^ ctx.r9.u64;
	// addi r9,r11,3072
	ctx.r9.s64 = ctx.r11.s64 + 3072;
	// rlwinm r31,r3,26,22,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 26) & 0x3FC;
	// rlwinm r8,r3,18,22,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 18) & 0x3FC;
	// rlwinm r30,r3,10,22,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 10) & 0x3FC;
	// lwzu r29,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r29.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// rlwinm r3,r3,2,22,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x3FC;
	// addi r28,r11,1024
	ctx.r28.s64 = ctx.r11.s64 + 1024;
	// lwzx r6,r31,r6
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r6.u32);
	// addi r31,r11,3072
	ctx.r31.s64 = ctx.r11.s64 + 3072;
	// lwzx r8,r8,r7
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// addi r7,r11,2048
	ctx.r7.s64 = ctx.r11.s64 + 2048;
	// lwzx r30,r30,r11
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// addi r27,r11,1024
	ctx.r27.s64 = ctx.r11.s64 + 1024;
	// xor r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 ^ ctx.r6.u64;
	// lwzx r6,r3,r9
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r9.u32);
	// addi r3,r11,2048
	ctx.r3.s64 = ctx.r11.s64 + 2048;
	// lwzu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r9.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// xor r8,r8,r30
	ctx.r8.u64 = ctx.r8.u64 ^ ctx.r30.u64;
	// addi r30,r11,3072
	ctx.r30.s64 = ctx.r11.s64 + 3072;
	// xor r6,r8,r6
	ctx.r6.u64 = ctx.r8.u64 ^ ctx.r6.u64;
	// addi r8,r11,1024
	ctx.r8.s64 = ctx.r11.s64 + 1024;
	// xor r6,r6,r4
	ctx.r6.u64 = ctx.r6.u64 ^ ctx.r4.u64;
	// lwzu r4,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r4.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// addi r26,r11,2048
	ctx.r26.s64 = ctx.r11.s64 + 2048;
	// rlwinm r25,r6,18,22,29
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 18) & 0x3FC;
	// rlwinm r24,r6,26,22,29
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 26) & 0x3FC;
	// rlwinm r23,r6,10,22,29
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 10) & 0x3FC;
	// rlwinm r6,r6,2,22,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x3FC;
	// lwzu r22,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r22.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// addi r21,r11,3072
	ctx.r21.s64 = ctx.r11.s64 + 3072;
	// lwzx r28,r25,r28
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r25.u32 + ctx.r28.u32);
	// addi r25,r11,1024
	ctx.r25.s64 = ctx.r11.s64 + 1024;
	// lwzx r7,r24,r7
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r24.u32 + ctx.r7.u32);
	// addi r24,r11,2048
	ctx.r24.s64 = ctx.r11.s64 + 2048;
	// lwzx r23,r23,r11
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r23.u32 + ctx.r11.u32);
	// addi r20,r11,3072
	ctx.r20.s64 = ctx.r11.s64 + 3072;
	// xor r7,r28,r7
	ctx.r7.u64 = ctx.r28.u64 ^ ctx.r7.u64;
	// lwzx r6,r6,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r31.u32);
	// lwzu r31,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r31.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// xor r7,r7,r23
	ctx.r7.u64 = ctx.r7.u64 ^ ctx.r23.u64;
	// xor r6,r7,r6
	ctx.r6.u64 = ctx.r7.u64 ^ ctx.r6.u64;
	// xor r7,r6,r29
	ctx.r7.u64 = ctx.r6.u64 ^ ctx.r29.u64;
	// rlwinm r29,r7,26,22,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 26) & 0x3FC;
	// rlwinm r6,r7,18,22,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 18) & 0x3FC;
	// rlwinm r28,r7,10,22,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 10) & 0x3FC;
	// rlwinm r7,r7,2,22,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x3FC;
	// lwzx r3,r29,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r3.u32);
	// lwzx r6,r6,r27
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r27.u32);
	// lwzx r29,r28,r11
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r28.u32 + ctx.r11.u32);
	// xor r6,r6,r3
	ctx.r6.u64 = ctx.r6.u64 ^ ctx.r3.u64;
	// lwzx r3,r7,r30
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r30.u32);
	// xor r7,r6,r29
	ctx.r7.u64 = ctx.r6.u64 ^ ctx.r29.u64;
	// xor r6,r7,r3
	ctx.r6.u64 = ctx.r7.u64 ^ ctx.r3.u64;
	// xor r3,r6,r9
	ctx.r3.u64 = ctx.r6.u64 ^ ctx.r9.u64;
	// rlwinm r9,r3,18,22,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 18) & 0x3FC;
	// rlwinm r7,r3,26,22,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 26) & 0x3FC;
	// rlwinm r6,r3,10,22,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 10) & 0x3FC;
	// rlwinm r3,r3,2,22,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x3FC;
	// lwzx r9,r9,r8
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// lwzx r8,r7,r26
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r26.u32);
	// lwzx r7,r6,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r11.u32);
	// xor r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 ^ ctx.r8.u64;
	// lwzx r3,r3,r21
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r21.u32);
	// xor r9,r6,r7
	ctx.r9.u64 = ctx.r6.u64 ^ ctx.r7.u64;
	// xor r8,r9,r3
	ctx.r8.u64 = ctx.r9.u64 ^ ctx.r3.u64;
	// xor r7,r8,r4
	ctx.r7.u64 = ctx.r8.u64 ^ ctx.r4.u64;
	// rlwinm r6,r7,18,22,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 18) & 0x3FC;
	// rlwinm r4,r7,26,22,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 26) & 0x3FC;
	// rlwinm r3,r7,10,22,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 10) & 0x3FC;
	// rlwinm r9,r7,2,22,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x3FC;
	// lwzx r8,r6,r25
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r25.u32);
	// lwzx r7,r4,r24
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r24.u32);
	// lwzx r6,r3,r11
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r11.u32);
	// xor r4,r8,r7
	ctx.r4.u64 = ctx.r8.u64 ^ ctx.r7.u64;
	// lwzx r3,r9,r20
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r20.u32);
	// xor r9,r4,r6
	ctx.r9.u64 = ctx.r4.u64 ^ ctx.r6.u64;
	// xor r8,r9,r3
	ctx.r8.u64 = ctx.r9.u64 ^ ctx.r3.u64;
	// lwzu r7,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r7.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// addi r6,r11,1024
	ctx.r6.s64 = ctx.r11.s64 + 1024;
	// xor r4,r8,r22
	ctx.r4.u64 = ctx.r8.u64 ^ ctx.r22.u64;
	// addi r3,r11,2048
	ctx.r3.s64 = ctx.r11.s64 + 2048;
	// rlwinm r8,r4,26,22,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 26) & 0x3FC;
	// rlwinm r9,r4,18,22,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 18) & 0x3FC;
	// rlwinm r30,r4,10,22,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 10) & 0x3FC;
	// rlwinm r4,r4,2,22,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x3FC;
	// addi r29,r11,3072
	ctx.r29.s64 = ctx.r11.s64 + 3072;
	// lwzx r3,r8,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r3.u32);
	// addi r8,r11,2048
	ctx.r8.s64 = ctx.r11.s64 + 2048;
	// lwzx r9,r9,r6
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r6.u32);
	// addi r6,r11,1024
	ctx.r6.s64 = ctx.r11.s64 + 1024;
	// lwzx r30,r30,r11
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// addi r28,r11,3072
	ctx.r28.s64 = ctx.r11.s64 + 3072;
	// xor r3,r9,r3
	ctx.r3.u64 = ctx.r9.u64 ^ ctx.r3.u64;
	// lwzx r9,r4,r29
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r29.u32);
	// addi r4,r11,1024
	ctx.r4.s64 = ctx.r11.s64 + 1024;
	// xor r3,r3,r30
	ctx.r3.u64 = ctx.r3.u64 ^ ctx.r30.u64;
	// addi r30,r11,2048
	ctx.r30.s64 = ctx.r11.s64 + 2048;
	// xor r9,r3,r9
	ctx.r9.u64 = ctx.r3.u64 ^ ctx.r9.u64;
	// addi r3,r11,3072
	ctx.r3.s64 = ctx.r11.s64 + 3072;
	// xor r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 ^ ctx.r31.u64;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// rlwinm r31,r9,18,22,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 18) & 0x3FC;
	// rlwinm r29,r9,26,22,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 26) & 0x3FC;
	// rlwinm r27,r9,10,22,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 10) & 0x3FC;
	// rlwinm r9,r9,2,22,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x3FC;
	// addi r5,r5,-32
	ctx.r5.s64 = ctx.r5.s64 + -32;
	// lwzx r6,r31,r6
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r6.u32);
	// lwzx r8,r29,r8
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r8.u32);
	// lwzx r31,r27,r11
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r11.u32);
	// xor r6,r6,r8
	ctx.r6.u64 = ctx.r6.u64 ^ ctx.r8.u64;
	// lwzx r9,r9,r28
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r28.u32);
	// xor r8,r6,r31
	ctx.r8.u64 = ctx.r6.u64 ^ ctx.r31.u64;
	// xor r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 ^ ctx.r9.u64;
	// xor r9,r6,r7
	ctx.r9.u64 = ctx.r6.u64 ^ ctx.r7.u64;
	// rlwinm r8,r9,18,22,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 18) & 0x3FC;
	// rlwinm r7,r9,26,22,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 26) & 0x3FC;
	// rlwinm r6,r9,10,22,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 10) & 0x3FC;
	// rlwinm r9,r9,2,22,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x3FC;
	// lwzx r8,r8,r4
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r4.u32);
	// lwzx r7,r7,r30
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r30.u32);
	// lwzx r6,r6,r11
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r11.u32);
	// xor r4,r8,r7
	ctx.r4.u64 = ctx.r8.u64 ^ ctx.r7.u64;
	// lwzx r3,r9,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r3.u32);
	// xor r9,r4,r6
	ctx.r9.u64 = ctx.r4.u64 ^ ctx.r6.u64;
	// xor r9,r9,r3
	ctx.r9.u64 = ctx.r9.u64 ^ ctx.r3.u64;
	// bdnz 0x821624a8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821624A8;
loc_821626B4:
	// cmplwi cr6,r5,4
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 4, ctx.xer);
	// blt cr6,0x82162710
	if (ctx.cr6.lt) goto loc_82162710;
	// rlwinm r8,r5,30,2,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x3FFFFFFF;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_821626C4:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r7,r11,1024
	ctx.r7.s64 = ctx.r11.s64 + 1024;
	// addi r6,r11,2048
	ctx.r6.s64 = ctx.r11.s64 + 2048;
	// xor r4,r8,r9
	ctx.r4.u64 = ctx.r8.u64 ^ ctx.r9.u64;
	// addi r3,r11,3072
	ctx.r3.s64 = ctx.r11.s64 + 3072;
	// rlwinm r9,r4,18,22,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 18) & 0x3FC;
	// rlwinm r8,r4,26,22,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 26) & 0x3FC;
	// rlwinm r31,r4,10,22,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 10) & 0x3FC;
	// rlwinm r4,r4,2,22,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x3FC;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lwzx r9,r9,r7
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r7.u32);
	// addi r5,r5,-4
	ctx.r5.s64 = ctx.r5.s64 + -4;
	// lwzx r8,r8,r6
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r6.u32);
	// lwzx r7,r31,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// xor r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 ^ ctx.r8.u64;
	// lwzx r4,r4,r3
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r3.u32);
	// xor r3,r6,r7
	ctx.r3.u64 = ctx.r6.u64 ^ ctx.r7.u64;
	// xor r9,r3,r4
	ctx.r9.u64 = ctx.r3.u64 ^ ctx.r4.u64;
	// bdnz 0x821626c4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821626C4;
loc_82162710:
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x8216273c
	if (ctx.cr6.eq) goto loc_8216273C;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
loc_8216271C:
	// lbzu r6,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r6.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// rlwinm r7,r9,24,8,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 24) & 0xFFFFFF;
	// addic. r5,r5,-1
	ctx.xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// xor r4,r6,r9
	ctx.r4.u64 = ctx.r6.u64 ^ ctx.r9.u64;
	// rlwinm r3,r4,2,22,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x3FC;
	// lwzx r9,r3,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r11.u32);
	// xor r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 ^ ctx.r7.u64;
	// bne 0x8216271c
	if (!ctx.cr0.eq) goto loc_8216271C;
loc_8216273C:
	// not r3,r9
	ctx.r3.u64 = ~ctx.r9.u64;
	// b 0x8207c9b8
	__restgprlr_20(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82162744"))) PPC_WEAK_FUNC(sub_82162744);
PPC_FUNC_IMPL(__imp__sub_82162744) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82162748"))) PPC_WEAK_FUNC(sub_82162748);
PPC_FUNC_IMPL(__imp__sub_82162748) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x82162758
	if (!ctx.cr6.eq) goto loc_82162758;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82162758:
	// b 0x821620d8
	sub_821620D8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216275C"))) PPC_WEAK_FUNC(sub_8216275C);
PPC_FUNC_IMPL(__imp__sub_8216275C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82162760"))) PPC_WEAK_FUNC(sub_82162760);
PPC_FUNC_IMPL(__imp__sub_82162760) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c958
	ctx.lr = 0x82162768;
	__savegprlr_16(ctx, base);
	// lwz r30,28(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// li r28,1
	ctx.r28.s64 = 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r16,3
	ctx.r16.s64 = 3;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r29,r11,-1
	ctx.r29.s64 = ctx.r11.s64 + -1;
	// lwz r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// lwz r10,84(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 84);
	// subf r8,r4,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r4.s64;
	// lwz r5,88(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 88);
	// add r9,r9,r29
	ctx.r9.u64 = ctx.r9.u64 + ctx.r29.u64;
	// slw r6,r28,r10
	ctx.r6.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r28.u32 << (ctx.r10.u8 & 0x3F));
	// lwz r24,40(r30)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r30.u32 + 40);
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// lwz r19,44(r30)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	// slw r5,r28,r5
	ctx.r5.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r28.u32 << (ctx.r5.u8 & 0x3F));
	// lwz r27,48(r30)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r30.u32 + 48);
	// addi r20,r9,-5
	ctx.r20.s64 = ctx.r9.s64 + -5;
	// lwz r18,52(r30)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r30.u32 + 52);
	// lwz r10,56(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 56);
	// add r23,r8,r7
	ctx.r23.u64 = ctx.r8.u64 + ctx.r7.u64;
	// lwz r9,60(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 60);
	// addi r17,r11,-257
	ctx.r17.s64 = ctx.r11.s64 + -257;
	// lwz r25,76(r30)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r30.u32 + 76);
	// addi r21,r6,-1
	ctx.r21.s64 = ctx.r6.s64 + -1;
	// lwz r26,80(r30)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r30.u32 + 80);
	// addi r22,r5,-1
	ctx.r22.s64 = ctx.r5.s64 + -1;
loc_821627DC:
	// cmplwi cr6,r9,15
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 15, ctx.xer);
	// bge cr6,0x82162804
	if (!ctx.cr6.lt) goto loc_82162804;
	// lbzu r8,1(r29)
	ea = 1 + ctx.r29.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r29.u32 = ea;
	// addi r11,r9,8
	ctx.r11.s64 = ctx.r9.s64 + 8;
	// slw r8,r8,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r9.u8 & 0x3F));
	// lbzu r6,1(r29)
	ea = 1 + ctx.r29.u32;
	ctx.r6.u64 = PPC_LOAD_U8(ea);
	ctx.r29.u32 = ea;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// slw r9,r6,r11
	ctx.r9.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r6.u32 << (ctx.r11.u8 & 0x3F));
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r9,r11,8
	ctx.r9.s64 = ctx.r11.s64 + 8;
loc_82162804:
	// and r11,r21,r10
	ctx.r11.u64 = ctx.r21.u64 & ctx.r10.u64;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r8,r25
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r25.u32);
	// stw r6,-144(r1)
	PPC_STORE_U32(ctx.r1.u32 + -144, ctx.r6.u32);
	// lbz r11,-144(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + -144);
	// lbz r8,-143(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + -143);
	// srw r10,r10,r8
	ctx.r10.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r8.u8 & 0x3F));
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82162880
	if (ctx.cr6.eq) goto loc_82162880;
loc_8216282C:
	// rlwinm r8,r11,0,27,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8216288c
	if (!ctx.cr6.eq) goto loc_8216288C;
	// rlwinm r8,r11,0,25,25
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82162b34
	if (!ctx.cr6.eq) goto loc_82162B34;
	// slw r11,r28,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r28.u32 << (ctx.r11.u8 & 0x3F));
	// lhz r8,-142(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + -142);
	// addi r6,r11,-1
	ctx.r6.s64 = ctx.r11.s64 + -1;
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// and r8,r6,r10
	ctx.r8.u64 = ctx.r6.u64 & ctx.r10.u64;
	// add r5,r8,r11
	ctx.r5.u64 = ctx.r8.u64 + ctx.r11.u64;
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r4,r25
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r25.u32);
	// stw r11,-144(r1)
	PPC_STORE_U32(ctx.r1.u32 + -144, ctx.r11.u32);
	// lbz r11,-144(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + -144);
	// lbz r5,-143(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + -143);
	// srw r10,r10,r5
	ctx.r10.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r5.u8 & 0x3F));
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// subf r9,r5,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r5.s64;
	// bne cr6,0x8216282c
	if (!ctx.cr6.eq) goto loc_8216282C;
loc_82162880:
	// lhz r11,-142(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + -142);
	// stbu r11,1(r7)
	ea = 1 + ctx.r7.u32;
	PPC_STORE_U8(ea, ctx.r11.u8);
	ctx.r7.u32 = ea;
	// b 0x82162b00
	goto loc_82162B00;
loc_8216288C:
	// clrlwi r11,r11,28
	ctx.r11.u64 = ctx.r11.u32 & 0xF;
	// lhz r4,-142(r1)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r1.u32 + -142);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821628cc
	if (ctx.cr6.eq) goto loc_821628CC;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x821628b4
	if (!ctx.cr6.lt) goto loc_821628B4;
	// lbzu r8,1(r29)
	ea = 1 + ctx.r29.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r29.u32 = ea;
	// slw r8,r8,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r9.u8 & 0x3F));
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
loc_821628B4:
	// slw r8,r28,r11
	ctx.r8.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r28.u32 << (ctx.r11.u8 & 0x3F));
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// subf r9,r11,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r11.s64;
	// and r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 & ctx.r10.u64;
	// srw r10,r10,r11
	ctx.r10.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r11.u8 & 0x3F));
	// add r4,r8,r4
	ctx.r4.u64 = ctx.r8.u64 + ctx.r4.u64;
loc_821628CC:
	// cmplwi cr6,r9,15
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 15, ctx.xer);
	// bge cr6,0x821628f4
	if (!ctx.cr6.lt) goto loc_821628F4;
	// lbzu r8,1(r29)
	ea = 1 + ctx.r29.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r29.u32 = ea;
	// addi r11,r9,8
	ctx.r11.s64 = ctx.r9.s64 + 8;
	// slw r8,r8,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r9.u8 & 0x3F));
	// lbzu r6,1(r29)
	ea = 1 + ctx.r29.u32;
	ctx.r6.u64 = PPC_LOAD_U8(ea);
	ctx.r29.u32 = ea;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// slw r9,r6,r11
	ctx.r9.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r6.u32 << (ctx.r11.u8 & 0x3F));
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r9,r11,8
	ctx.r9.s64 = ctx.r11.s64 + 8;
loc_821628F4:
	// and r11,r22,r10
	ctx.r11.u64 = ctx.r22.u64 & ctx.r10.u64;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r8,r26
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r26.u32);
	// stw r6,-144(r1)
	PPC_STORE_U32(ctx.r1.u32 + -144, ctx.r6.u32);
	// lbz r6,-143(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + -143);
	// srw r10,r10,r6
	ctx.r10.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r6.u8 & 0x3F));
	// lbz r11,-144(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + -144);
	// subf r9,r6,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r6.s64;
	// rlwinm r8,r11,0,27,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82162968
	if (!ctx.cr6.eq) goto loc_82162968;
loc_82162920:
	// rlwinm r8,r11,0,25,25
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82162b24
	if (!ctx.cr6.eq) goto loc_82162B24;
	// slw r11,r28,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r28.u32 << (ctx.r11.u8 & 0x3F));
	// lhz r8,-142(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + -142);
	// addi r6,r11,-1
	ctx.r6.s64 = ctx.r11.s64 + -1;
	// and r11,r6,r10
	ctx.r11.u64 = ctx.r6.u64 & ctx.r10.u64;
	// add r5,r11,r8
	ctx.r5.u64 = ctx.r11.u64 + ctx.r8.u64;
	// rlwinm r11,r5,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r11,r26
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r26.u32);
	// stw r8,-144(r1)
	PPC_STORE_U32(ctx.r1.u32 + -144, ctx.r8.u32);
	// lbz r8,-143(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + -143);
	// lbz r11,-144(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + -144);
	// rlwinm r5,r11,0,27,27
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	// srw r10,r10,r8
	ctx.r10.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r8.u8 & 0x3F));
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82162920
	if (ctx.cr6.eq) goto loc_82162920;
loc_82162968:
	// clrlwi r11,r11,28
	ctx.r11.u64 = ctx.r11.u32 & 0xF;
	// lhz r6,-142(r1)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r1.u32 + -142);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x821629a0
	if (!ctx.cr6.lt) goto loc_821629A0;
	// lbzu r8,1(r29)
	ea = 1 + ctx.r29.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r29.u32 = ea;
	// slw r8,r8,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r9.u8 & 0x3F));
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x821629a0
	if (!ctx.cr6.lt) goto loc_821629A0;
	// lbzu r8,1(r29)
	ea = 1 + ctx.r29.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r29.u32 = ea;
	// slw r8,r8,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r9.u8 & 0x3F));
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
loc_821629A0:
	// slw r8,r28,r11
	ctx.r8.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r28.u32 << (ctx.r11.u8 & 0x3F));
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// subf r9,r11,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r11.s64;
	// and r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 & ctx.r10.u64;
	// srw r10,r10,r11
	ctx.r10.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r11.u8 & 0x3F));
	// add r31,r8,r6
	ctx.r31.u64 = ctx.r8.u64 + ctx.r6.u64;
	// subf r11,r23,r7
	ctx.r11.s64 = ctx.r7.s64 - ctx.r23.s64;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82162ab8
	if (!ctx.cr6.gt) goto loc_82162AB8;
	// subf r8,r11,r31
	ctx.r8.s64 = ctx.r31.s64 - ctx.r11.s64;
	// cmplw cr6,r8,r19
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r19.u32, ctx.xer);
	// bgt cr6,0x82162b14
	if (ctx.cr6.gt) goto loc_82162B14;
	// addi r5,r18,-1
	ctx.r5.s64 = ctx.r18.s64 + -1;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// subf r11,r8,r5
	ctx.r11.s64 = ctx.r5.s64 - ctx.r8.s64;
	// bne cr6,0x82162a04
	if (!ctx.cr6.eq) goto loc_82162A04;
	// cmplw cr6,r8,r4
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, ctx.xer);
	// add r11,r11,r24
	ctx.r11.u64 = ctx.r11.u64 + ctx.r24.u64;
	// bge cr6,0x82162a7c
	if (!ctx.cr6.lt) goto loc_82162A7C;
	// subf r4,r8,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r8.s64;
loc_821629F0:
	// lbzu r6,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r6.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// addic. r8,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stbu r6,1(r7)
	ea = 1 + ctx.r7.u32;
	PPC_STORE_U8(ea, ctx.r6.u8);
	ctx.r7.u32 = ea;
	// bne 0x821629f0
	if (!ctx.cr0.eq) goto loc_821629F0;
	// b 0x82162a78
	goto loc_82162A78;
loc_82162A04:
	// cmplw cr6,r27,r8
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r8.u32, ctx.xer);
	// add r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
	// bge cr6,0x82162a5c
	if (!ctx.cr6.lt) goto loc_82162A5C;
	// subf r8,r27,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r27.s64;
	// add r11,r11,r24
	ctx.r11.u64 = ctx.r11.u64 + ctx.r24.u64;
	// cmplw cr6,r8,r4
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, ctx.xer);
	// bge cr6,0x82162a7c
	if (!ctx.cr6.lt) goto loc_82162A7C;
	// subf r4,r8,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r8.s64;
loc_82162A24:
	// lbzu r6,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r6.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// addic. r8,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stbu r6,1(r7)
	ea = 1 + ctx.r7.u32;
	PPC_STORE_U8(ea, ctx.r6.u8);
	ctx.r7.u32 = ea;
	// bne 0x82162a24
	if (!ctx.cr0.eq) goto loc_82162A24;
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// cmplw cr6,r27,r4
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r4.u32, ctx.xer);
	// bge cr6,0x82162a7c
	if (!ctx.cr6.lt) goto loc_82162A7C;
	// mr r8,r27
	ctx.r8.u64 = ctx.r27.u64;
	// subf r4,r27,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r27.s64;
loc_82162A48:
	// lbzu r6,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r6.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// addic. r8,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stbu r6,1(r7)
	ea = 1 + ctx.r7.u32;
	PPC_STORE_U8(ea, ctx.r6.u8);
	ctx.r7.u32 = ea;
	// bne 0x82162a48
	if (!ctx.cr0.eq) goto loc_82162A48;
	// b 0x82162a78
	goto loc_82162A78;
loc_82162A5C:
	// cmplw cr6,r8,r4
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, ctx.xer);
	// bge cr6,0x82162a7c
	if (!ctx.cr6.lt) goto loc_82162A7C;
	// subf r4,r8,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r8.s64;
loc_82162A68:
	// lbzu r6,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r6.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// addic. r8,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stbu r6,1(r7)
	ea = 1 + ctx.r7.u32;
	PPC_STORE_U8(ea, ctx.r6.u8);
	ctx.r7.u32 = ea;
	// bne 0x82162a68
	if (!ctx.cr0.eq) goto loc_82162A68;
loc_82162A78:
	// subf r11,r31,r7
	ctx.r11.s64 = ctx.r7.s64 - ctx.r31.s64;
loc_82162A7C:
	// cmplwi cr6,r4,2
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 2, ctx.xer);
	// ble cr6,0x82162ae0
	if (!ctx.cr6.gt) goto loc_82162AE0;
	// addi r8,r4,-3
	ctx.r8.s64 = ctx.r4.s64 + -3;
	// divwu r8,r8,r16
	ctx.r8.u32 = ppc_divwu(ctx.r8.u32, ctx.r16.u32);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_82162A94:
	// lbzu r8,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// addi r4,r4,-3
	ctx.r4.s64 = ctx.r4.s64 + -3;
	// stbu r8,1(r7)
	ea = 1 + ctx.r7.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r7.u32 = ea;
	// lbzu r6,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r6.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// stbu r6,1(r7)
	ea = 1 + ctx.r7.u32;
	PPC_STORE_U8(ea, ctx.r6.u8);
	ctx.r7.u32 = ea;
	// lbzu r5,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r5.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// stbu r5,1(r7)
	ea = 1 + ctx.r7.u32;
	PPC_STORE_U8(ea, ctx.r5.u8);
	ctx.r7.u32 = ea;
	// bdnz 0x82162a94
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82162A94;
	// b 0x82162ae0
	goto loc_82162AE0;
loc_82162AB8:
	// subf r11,r31,r7
	ctx.r11.s64 = ctx.r7.s64 - ctx.r31.s64;
loc_82162ABC:
	// lbzu r8,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// addi r4,r4,-3
	ctx.r4.s64 = ctx.r4.s64 + -3;
	// cmplwi cr6,r4,2
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 2, ctx.xer);
	// stbu r8,1(r7)
	ea = 1 + ctx.r7.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r7.u32 = ea;
	// lbzu r6,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r6.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// stbu r6,1(r7)
	ea = 1 + ctx.r7.u32;
	PPC_STORE_U8(ea, ctx.r6.u8);
	ctx.r7.u32 = ea;
	// lbzu r5,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r5.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// stbu r5,1(r7)
	ea = 1 + ctx.r7.u32;
	PPC_STORE_U8(ea, ctx.r5.u8);
	ctx.r7.u32 = ea;
	// bgt cr6,0x82162abc
	if (ctx.cr6.gt) goto loc_82162ABC;
loc_82162AE0:
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82162b00
	if (ctx.cr6.eq) goto loc_82162B00;
	// lbzu r8,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// cmplwi cr6,r4,1
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 1, ctx.xer);
	// stbu r8,1(r7)
	ea = 1 + ctx.r7.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r7.u32 = ea;
	// ble cr6,0x82162b00
	if (!ctx.cr6.gt) goto loc_82162B00;
	// lbz r11,1(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// stbu r11,1(r7)
	ea = 1 + ctx.r7.u32;
	PPC_STORE_U8(ea, ctx.r11.u8);
	ctx.r7.u32 = ea;
loc_82162B00:
	// cmplw cr6,r29,r20
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r20.u32, ctx.xer);
	// bge cr6,0x82162b60
	if (!ctx.cr6.lt) goto loc_82162B60;
	// cmplw cr6,r7,r17
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r17.u32, ctx.xer);
	// blt cr6,0x821627dc
	if (ctx.cr6.lt) goto loc_821627DC;
	// b 0x82162b60
	goto loc_82162B60;
loc_82162B14:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r11,r11,-14592
	ctx.r11.s64 = ctx.r11.s64 + -14592;
	// addi r6,r11,-56
	ctx.r6.s64 = ctx.r11.s64 + -56;
	// b 0x82162b54
	goto loc_82162B54;
loc_82162B24:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r11,r11,-14592
	ctx.r11.s64 = ctx.r11.s64 + -14592;
	// addi r6,r11,-24
	ctx.r6.s64 = ctx.r11.s64 + -24;
	// b 0x82162b54
	goto loc_82162B54;
loc_82162B34:
	// rlwinm r11,r11,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82162b4c
	if (ctx.cr6.eq) goto loc_82162B4C;
	// li r11,11
	ctx.r11.s64 = 11;
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// b 0x82162b60
	goto loc_82162B60;
loc_82162B4C:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r6,r11,-14592
	ctx.r6.s64 = ctx.r11.s64 + -14592;
loc_82162B54:
	// li r8,27
	ctx.r8.s64 = 27;
	// stw r6,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r6.u32);
	// stw r8,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r8.u32);
loc_82162B60:
	// rlwinm r11,r9,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFF8;
	// rlwinm r6,r9,29,3,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 29) & 0x1FFFFFFF;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r11.s64;
	// subf r11,r6,r29
	ctx.r11.s64 = ctx.r29.s64 - ctx.r6.s64;
	// slw r9,r28,r8
	ctx.r9.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r28.u32 << (ctx.r8.u8 & 0x3F));
	// stw r8,60(r30)
	PPC_STORE_U32(ctx.r30.u32 + 60, ctx.r8.u32);
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// cmplw cr6,r11,r20
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r20.u32, ctx.xer);
	// subf r11,r11,r20
	ctx.r11.s64 = ctx.r20.s64 - ctx.r11.s64;
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// addi r5,r9,-1
	ctx.r5.s64 = ctx.r9.s64 + -1;
	// addi r11,r11,5
	ctx.r11.s64 = ctx.r11.s64 + 5;
	// addi r9,r7,1
	ctx.r9.s64 = ctx.r7.s64 + 1;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// subf r11,r7,r17
	ctx.r11.s64 = ctx.r17.s64 - ctx.r7.s64;
	// and r10,r5,r10
	ctx.r10.u64 = ctx.r5.u64 & ctx.r10.u64;
	// stw r9,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r9.u32);
	// addi r11,r11,257
	ctx.r11.s64 = ctx.r11.s64 + 257;
	// cmplw cr6,r7,r17
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r17.u32, ctx.xer);
	// stw r10,56(r30)
	PPC_STORE_U32(ctx.r30.u32 + 56, ctx.r10.u32);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// b 0x8207c9a8
	__restgprlr_16(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82162BB8"))) PPC_WEAK_FUNC(sub_82162BB8);
PPC_FUNC_IMPL(__imp__sub_82162BB8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c974
	ctx.lr = 0x82162BC0;
	__savegprlr_23(ctx, base);
	// rlwinm r10,r3,16,16,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 16) & 0xFFFF;
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r5,1
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 1, ctx.xer);
	// bne cr6,0x82162c08
	if (!ctx.cr6.eq) goto loc_82162C08;
	// lbz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// lis r8,0
	ctx.r8.s64 = 0;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// ori r24,r8,65521
	ctx.r24.u64 = ctx.r8.u64 | 65521;
	// cmplwi cr6,r11,65521
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 65521, ctx.xer);
	// blt cr6,0x82162bec
	if (ctx.cr6.lt) goto loc_82162BEC;
	// subf r11,r24,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r24.s64;
loc_82162BEC:
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplwi cr6,r10,65521
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 65521, ctx.xer);
	// blt cr6,0x82162eb8
	if (ctx.cr6.lt) goto loc_82162EB8;
	// subf r10,r24,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r24.s64;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// or r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 | ctx.r11.u64;
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
loc_82162C08:
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x82162c18
	if (!ctx.cr6.eq) goto loc_82162C18;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
loc_82162C18:
	// cmplwi cr6,r5,16
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 16, ctx.xer);
	// bge cr6,0x82162c78
	if (!ctx.cr6.lt) goto loc_82162C78;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82162c40
	if (ctx.cr6.eq) goto loc_82162C40;
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// addi r9,r4,-1
	ctx.r9.s64 = ctx.r4.s64 + -1;
loc_82162C30:
	// lbzu r8,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bdnz 0x82162c30
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82162C30;
loc_82162C40:
	// lis r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r11,65521
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 65521, ctx.xer);
	// ori r24,r9,65521
	ctx.r24.u64 = ctx.r9.u64 | 65521;
	// blt cr6,0x82162c54
	if (ctx.cr6.lt) goto loc_82162C54;
	// subf r11,r24,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r24.s64;
loc_82162C54:
	// lis r9,-32761
	ctx.r9.s64 = -2147024896;
	// ori r8,r9,32881
	ctx.r8.u64 = ctx.r9.u64 | 32881;
	// mulhwu r7,r10,r8
	ctx.r7.u64 = (uint64_t(ctx.r10.u32) * uint64_t(ctx.r8.u32)) >> 32;
	// rlwinm r6,r7,17,15,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 17) & 0x1FFFF;
	// mullw r5,r6,r24
	ctx.r5.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r24.s32);
	// subf r4,r5,r10
	ctx.r4.s64 = ctx.r10.s64 - ctx.r5.s64;
	// rlwinm r3,r4,16,0,15
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// or r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 | ctx.r11.u64;
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
loc_82162C78:
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,-32761
	ctx.r8.s64 = -2147024896;
	// ori r24,r9,65521
	ctx.r24.u64 = ctx.r9.u64 | 65521;
	// ori r23,r8,32881
	ctx.r23.u64 = ctx.r8.u64 | 32881;
	// cmplwi cr6,r5,5552
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 5552, ctx.xer);
	// blt cr6,0x82162d94
	if (ctx.cr6.lt) goto loc_82162D94;
	// li r9,5552
	ctx.r9.s64 = 5552;
	// divwu r25,r5,r9
	ctx.r25.u32 = ppc_divwu(ctx.r5.u32, ctx.r9.u32);
loc_82162C98:
	// li r9,347
	ctx.r9.s64 = 347;
	// addi r5,r5,-5552
	ctx.r5.s64 = ctx.r5.s64 + -5552;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_82162CA4:
	// lbz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// lbz r6,1(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lbz r7,2(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 2);
	// lbz r8,3(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 3);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lbz r9,4(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 4);
	// add r11,r6,r11
	ctx.r11.u64 = ctx.r6.u64 + ctx.r11.u64;
	// lbz r26,5(r4)
	ctx.r26.u64 = PPC_LOAD_U8(ctx.r4.u32 + 5);
	// lbz r27,6(r4)
	ctx.r27.u64 = PPC_LOAD_U8(ctx.r4.u32 + 6);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lbz r28,7(r4)
	ctx.r28.u64 = PPC_LOAD_U8(ctx.r4.u32 + 7);
	// add r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 + ctx.r11.u64;
	// lbz r29,8(r4)
	ctx.r29.u64 = PPC_LOAD_U8(ctx.r4.u32 + 8);
	// lbz r30,9(r4)
	ctx.r30.u64 = PPC_LOAD_U8(ctx.r4.u32 + 9);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lbz r31,10(r4)
	ctx.r31.u64 = PPC_LOAD_U8(ctx.r4.u32 + 10);
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// lbz r3,11(r4)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r4.u32 + 11);
	// lbz r6,12(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 12);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lbz r7,13(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 13);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lbz r8,14(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 14);
	// lbz r9,15(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 15);
	// addi r4,r4,16
	ctx.r4.s64 = ctx.r4.s64 + 16;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r26,r11
	ctx.r11.u64 = ctx.r26.u64 + ctx.r11.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r27,r11
	ctx.r11.u64 = ctx.r27.u64 + ctx.r11.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r28,r11
	ctx.r11.u64 = ctx.r28.u64 + ctx.r11.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r31,r11
	ctx.r11.u64 = ctx.r31.u64 + ctx.r11.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r3,r11
	ctx.r11.u64 = ctx.r3.u64 + ctx.r11.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r6,r11
	ctx.r11.u64 = ctx.r6.u64 + ctx.r11.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 + ctx.r11.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bdnz 0x82162ca4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82162CA4;
	// mulhwu r9,r11,r23
	ctx.r9.u64 = (uint64_t(ctx.r11.u32) * uint64_t(ctx.r23.u32)) >> 32;
	// mulhwu r8,r10,r23
	ctx.r8.u64 = (uint64_t(ctx.r10.u32) * uint64_t(ctx.r23.u32)) >> 32;
	// rlwinm r7,r9,17,15,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 17) & 0x1FFFF;
	// rlwinm r6,r8,17,15,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 17) & 0x1FFFF;
	// mullw r3,r7,r24
	ctx.r3.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r24.s32);
	// mullw r9,r6,r24
	ctx.r9.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r24.s32);
	// addic. r25,r25,-1
	ctx.xer.ca = ctx.r25.u32 > 0;
	ctx.r25.s64 = ctx.r25.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// subf r11,r3,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r3.s64;
	// subf r10,r9,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r9.s64;
	// bne 0x82162c98
	if (!ctx.cr0.eq) goto loc_82162C98;
loc_82162D94:
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82162eb8
	if (ctx.cr6.eq) goto loc_82162EB8;
	// cmplwi cr6,r5,16
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 16, ctx.xer);
	// blt cr6,0x82162e78
	if (ctx.cr6.lt) goto loc_82162E78;
	// rlwinm r9,r5,28,4,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 28) & 0xFFFFFFF;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_82162DAC:
	// lbz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// addi r5,r5,-16
	ctx.r5.s64 = ctx.r5.s64 + -16;
	// lbz r6,1(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lbz r7,2(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 2);
	// lbz r8,3(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 3);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lbz r9,4(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 4);
	// add r11,r6,r11
	ctx.r11.u64 = ctx.r6.u64 + ctx.r11.u64;
	// lbz r26,5(r4)
	ctx.r26.u64 = PPC_LOAD_U8(ctx.r4.u32 + 5);
	// lbz r27,6(r4)
	ctx.r27.u64 = PPC_LOAD_U8(ctx.r4.u32 + 6);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lbz r28,7(r4)
	ctx.r28.u64 = PPC_LOAD_U8(ctx.r4.u32 + 7);
	// add r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 + ctx.r11.u64;
	// lbz r29,8(r4)
	ctx.r29.u64 = PPC_LOAD_U8(ctx.r4.u32 + 8);
	// lbz r30,9(r4)
	ctx.r30.u64 = PPC_LOAD_U8(ctx.r4.u32 + 9);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lbz r31,10(r4)
	ctx.r31.u64 = PPC_LOAD_U8(ctx.r4.u32 + 10);
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// lbz r3,11(r4)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r4.u32 + 11);
	// lbz r6,12(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 12);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lbz r7,13(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 13);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lbz r8,14(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 14);
	// lbz r9,15(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 15);
	// addi r4,r4,16
	ctx.r4.s64 = ctx.r4.s64 + 16;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r26,r11
	ctx.r11.u64 = ctx.r26.u64 + ctx.r11.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r27,r11
	ctx.r11.u64 = ctx.r27.u64 + ctx.r11.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r28,r11
	ctx.r11.u64 = ctx.r28.u64 + ctx.r11.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r31,r11
	ctx.r11.u64 = ctx.r31.u64 + ctx.r11.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r3,r11
	ctx.r11.u64 = ctx.r3.u64 + ctx.r11.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r6,r11
	ctx.r11.u64 = ctx.r6.u64 + ctx.r11.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 + ctx.r11.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bdnz 0x82162dac
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82162DAC;
loc_82162E78:
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82162e98
	if (ctx.cr6.eq) goto loc_82162E98;
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// addi r9,r4,-1
	ctx.r9.s64 = ctx.r4.s64 + -1;
loc_82162E88:
	// lbzu r8,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bdnz 0x82162e88
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82162E88;
loc_82162E98:
	// mulhwu r9,r11,r23
	ctx.r9.u64 = (uint64_t(ctx.r11.u32) * uint64_t(ctx.r23.u32)) >> 32;
	// mulhwu r8,r10,r23
	ctx.r8.u64 = (uint64_t(ctx.r10.u32) * uint64_t(ctx.r23.u32)) >> 32;
	// rlwinm r7,r9,17,15,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 17) & 0x1FFFF;
	// rlwinm r6,r8,17,15,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 17) & 0x1FFFF;
	// mullw r5,r7,r24
	ctx.r5.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r24.s32);
	// mullw r4,r6,r24
	ctx.r4.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r24.s32);
	// subf r11,r5,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r5.s64;
	// subf r10,r4,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r4.s64;
loc_82162EB8:
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// or r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 | ctx.r11.u64;
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82162EC4"))) PPC_WEAK_FUNC(sub_82162EC4);
PPC_FUNC_IMPL(__imp__sub_82162EC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82162EC8"))) PPC_WEAK_FUNC(sub_82162EC8);
PPC_FUNC_IMPL(__imp__sub_82162EC8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82162ECC"))) PPC_WEAK_FUNC(sub_82162ECC);
PPC_FUNC_IMPL(__imp__sub_82162ECC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82162ED0"))) PPC_WEAK_FUNC(sub_82162ED0);
PPC_FUNC_IMPL(__imp__sub_82162ED0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82162ED8;
	__savegprlr_28(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r30,0
	ctx.r30.s64 = 0;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r29,r3,280
	ctx.r29.s64 = ctx.r3.s64 + 280;
	// mr r28,r30
	ctx.r28.u64 = ctx.r30.u64;
	// addi r31,r11,6368
	ctx.r31.s64 = ctx.r11.s64 + 6368;
loc_82162EF0:
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stw r30,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r30.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// std r30,0(r11)
	PPC_STORE_U64(ctx.r11.u32 + 0, ctx.r30.u64);
	// std r30,8(r11)
	PPC_STORE_U64(ctx.r11.u32 + 8, ctx.r30.u64);
	// bl 0x82089db8
	ctx.lr = 0x82162F0C;
	sub_82089DB8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82163028
	if (!ctx.cr6.eq) goto loc_82163028;
	// li r10,4
	ctx.r10.s64 = 4;
	// lhz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r1.u32 + 84);
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// li r11,1
	ctx.r11.s64 = 1;
	// addi r8,r31,4
	ctx.r8.s64 = ctx.r31.s64 + 4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82162F2C:
	// lwz r10,-4(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// beq cr6,0x82162f4c
	if (ctx.cr6.eq) goto loc_82162F4C;
	// clrlwi r9,r6,16
	ctx.r9.u64 = ctx.r6.u32 & 0xFFFF;
	// and r5,r9,r11
	ctx.r5.u64 = ctx.r9.u64 & ctx.r11.u64;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq cr6,0x82162f4c
	if (ctx.cr6.eq) goto loc_82162F4C;
	// or r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 | ctx.r7.u64;
loc_82162F4C:
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// rotlwi r9,r11,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// beq cr6,0x82162f70
	if (ctx.cr6.eq) goto loc_82162F70;
	// clrlwi r11,r6,16
	ctx.r11.u64 = ctx.r6.u32 & 0xFFFF;
	// and r5,r11,r9
	ctx.r5.u64 = ctx.r11.u64 & ctx.r9.u64;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq cr6,0x82162f70
	if (ctx.cr6.eq) goto loc_82162F70;
	// or r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 | ctx.r7.u64;
loc_82162F70:
	// lwz r11,4(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// rotlwi r10,r9,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x82162f94
	if (ctx.cr6.eq) goto loc_82162F94;
	// clrlwi r9,r6,16
	ctx.r9.u64 = ctx.r6.u32 & 0xFFFF;
	// and r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq cr6,0x82162f94
	if (ctx.cr6.eq) goto loc_82162F94;
	// or r7,r11,r7
	ctx.r7.u64 = ctx.r11.u64 | ctx.r7.u64;
loc_82162F94:
	// lwz r11,8(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// rotlwi r10,r10,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x82162fb8
	if (ctx.cr6.eq) goto loc_82162FB8;
	// clrlwi r9,r6,16
	ctx.r9.u64 = ctx.r6.u32 & 0xFFFF;
	// and r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq cr6,0x82162fb8
	if (ctx.cr6.eq) goto loc_82162FB8;
	// or r7,r11,r7
	ctx.r7.u64 = ctx.r11.u64 | ctx.r7.u64;
loc_82162FB8:
	// rotlwi r11,r10,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// bdnz 0x82162f2c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82162F2C;
	// lbz r10,86(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 86);
	// cmplwi cr6,r10,30
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 30, ctx.xer);
	// ble cr6,0x82162fd4
	if (!ctx.cr6.gt) goto loc_82162FD4;
	// ori r7,r7,4096
	ctx.r7.u64 = ctx.r7.u64 | 4096;
loc_82162FD4:
	// lbz r10,87(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// cmplwi cr6,r10,30
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 30, ctx.xer);
	// ble cr6,0x82162fe4
	if (!ctx.cr6.gt) goto loc_82162FE4;
	// ori r7,r7,8192
	ctx.r7.u64 = ctx.r7.u64 | 8192;
loc_82162FE4:
	// lhz r11,88(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 88);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// cmpwi cr6,r11,8689
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8689, ctx.xer);
	// ble cr6,0x82162ff8
	if (!ctx.cr6.gt) goto loc_82162FF8;
	// ori r7,r7,2048
	ctx.r7.u64 = ctx.r7.u64 | 2048;
loc_82162FF8:
	// cmpwi cr6,r11,-8689
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -8689, ctx.xer);
	// bge cr6,0x82163004
	if (!ctx.cr6.lt) goto loc_82163004;
	// ori r7,r7,1024
	ctx.r7.u64 = ctx.r7.u64 | 1024;
loc_82163004:
	// lhz r11,90(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 90);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// cmpwi cr6,r11,8689
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8689, ctx.xer);
	// ble cr6,0x82163018
	if (!ctx.cr6.gt) goto loc_82163018;
	// ori r7,r7,256
	ctx.r7.u64 = ctx.r7.u64 | 256;
loc_82163018:
	// cmpwi cr6,r11,-8689
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -8689, ctx.xer);
	// bge cr6,0x82163024
	if (!ctx.cr6.lt) goto loc_82163024;
	// ori r7,r7,512
	ctx.r7.u64 = ctx.r7.u64 | 512;
loc_82163024:
	// stw r7,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r7.u32);
loc_82163028:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// cmplwi cr6,r28,4
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 4, ctx.xer);
	// blt cr6,0x82162ef0
	if (ctx.cr6.lt) goto loc_82162EF0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82163040"))) PPC_WEAK_FUNC(sub_82163040);
PPC_FUNC_IMPL(__imp__sub_82163040) {
	PPC_FUNC_PROLOGUE();
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82163048"))) PPC_WEAK_FUNC(sub_82163048);
PPC_FUNC_IMPL(__imp__sub_82163048) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,296(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 296);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,296(r3)
	PPC_STORE_U8(ctx.r3.u32 + 296, ctx.r11.u8);
	// b 0x82162ed0
	sub_82162ED0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82163060"))) PPC_WEAK_FUNC(sub_82163060);
PPC_FUNC_IMPL(__imp__sub_82163060) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82163064"))) PPC_WEAK_FUNC(sub_82163064);
PPC_FUNC_IMPL(__imp__sub_82163064) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82163068"))) PPC_WEAK_FUNC(sub_82163068);
PPC_FUNC_IMPL(__imp__sub_82163068) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-12
	ctx.r3.s64 = ctx.r3.s64 + -12;
	// lbz r11,296(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 296);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,296(r3)
	PPC_STORE_U8(ctx.r3.u32 + 296, ctx.r11.u8);
	// b 0x82162ed0
	sub_82162ED0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82163084"))) PPC_WEAK_FUNC(sub_82163084);
PPC_FUNC_IMPL(__imp__sub_82163084) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82163088"))) PPC_WEAK_FUNC(sub_82163088);
PPC_FUNC_IMPL(__imp__sub_82163088) {
	PPC_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,296(r3)
	PPC_STORE_U8(ctx.r3.u32 + 296, ctx.r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82163094"))) PPC_WEAK_FUNC(sub_82163094);
PPC_FUNC_IMPL(__imp__sub_82163094) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82163098"))) PPC_WEAK_FUNC(sub_82163098);
PPC_FUNC_IMPL(__imp__sub_82163098) {
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
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r8,r11,6432
	ctx.r8.s64 = ctx.r11.s64 + 6432;
	// addi r7,r10,6440
	ctx.r7.s64 = ctx.r10.s64 + 6440;
	// addi r6,r9,5680
	ctx.r6.s64 = ctx.r9.s64 + 5680;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stw r7,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r7.u32);
	// lis r30,-32224
	ctx.r30.s64 = -2111832064;
	// stw r6,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r6.u32);
	// addi r11,r3,12
	ctx.r11.s64 = ctx.r3.s64 + 12;
	// lwz r4,16(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r7,-31328(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31328);
	// addi r3,r7,32
	ctx.r3.s64 = ctx.r7.s64 + 32;
	// bl 0x82173a70
	ctx.lr = 0x821630EC;
	sub_82173A70(ctx, base);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82163110
	if (ctx.cr6.eq) goto loc_82163110;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8216310C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r7,-31328(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31328);
loc_82163110:
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r3,r7,88
	ctx.r3.s64 = ctx.r7.s64 + 88;
	// addi r10,r11,5720
	ctx.r10.s64 = ctx.r11.s64 + 5720;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// bl 0x82173a70
	ctx.lr = 0x82163128;
	sub_82173A70(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82163148
	if (ctx.cr6.eq) goto loc_82163148;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82163148;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82163148:
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

__attribute__((alias("__imp__sub_82163160"))) PPC_WEAK_FUNC(sub_82163160);
PPC_FUNC_IMPL(__imp__sub_82163160) {
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
	// bl 0x82170450
	ctx.lr = 0x82163178;
	sub_82170450(ctx, base);
	// addi r3,r31,12
	ctx.r3.s64 = ctx.r31.s64 + 12;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82170650
	ctx.lr = 0x82163184;
	sub_82170650(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// li r10,256
	ctx.r10.s64 = 256;
	// addi r7,r11,6432
	ctx.r7.s64 = ctx.r11.s64 + 6432;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r6,r8,6440
	ctx.r6.s64 = ctx.r8.s64 + 6440;
	// stw r7,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
	// addi r11,r31,24
	ctx.r11.s64 = ctx.r31.s64 + 24;
	// stb r9,296(r31)
	PPC_STORE_U8(ctx.r31.u32 + 296, ctx.r9.u8);
	// stw r6,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r6.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_821631B4:
	// stbu r9,1(r11)
	ea = 1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r9.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x821631b4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821631B4;
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

__attribute__((alias("__imp__sub_821631D4"))) PPC_WEAK_FUNC(sub_821631D4);
PPC_FUNC_IMPL(__imp__sub_821631D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821631D8"))) PPC_WEAK_FUNC(sub_821631D8);
PPC_FUNC_IMPL(__imp__sub_821631D8) {
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
	// beq cr6,0x82163258
	if (ctx.cr6.eq) goto loc_82163258;
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82163258
	if (ctx.cr6.eq) goto loc_82163258;
	// lwz r11,36(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82163258
	if (ctx.cr6.eq) goto loc_82163258;
	// lwz r4,52(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82163224
	if (ctx.cr6.eq) goto loc_82163224;
	// lwz r3,40(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82163224;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82163224:
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82163238;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r10.u32);
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
loc_82163258:
	// li r3,-2
	ctx.r3.s64 = -2;
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

__attribute__((alias("__imp__sub_82163270"))) PPC_WEAK_FUNC(sub_82163270);
PPC_FUNC_IMPL(__imp__sub_82163270) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82163278;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,28(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// li r30,1
	ctx.r30.s64 = 1;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x821632cc
	if (!ctx.cr6.eq) goto loc_821632CC;
	// lwz r11,32(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 32);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lwz r3,40(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 40);
	// slw r4,r30,r10
	ctx.r4.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r30.u32 << (ctx.r10.u8 & 0x3F));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821632B4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x821632cc
	if (!ctx.cr6.eq) goto loc_821632CC;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_821632CC:
	// lwz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// li r27,0
	ctx.r27.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821632f0
	if (!ctx.cr6.eq) goto loc_821632F0;
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// stw r27,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r27.u32);
	// slw r10,r30,r11
	ctx.r10.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r30.u32 << (ctx.r11.u8 & 0x3F));
	// stw r27,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r27.u32);
	// stw r10,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r10.u32);
loc_821632F0:
	// lwz r11,16(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// lwz r5,40(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// subf r30,r11,r29
	ctx.r30.s64 = ctx.r29.s64 - ctx.r11.s64;
	// cmplw cr6,r30,r5
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r5.u32, ctx.xer);
	// blt cr6,0x82163328
	if (ctx.cr6.lt) goto loc_82163328;
	// lwz r11,12(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// subf r4,r5,r11
	ctx.r4.s64 = ctx.r11.s64 - ctx.r5.s64;
	// bl 0x8207dac0
	ctx.lr = 0x82163310;
	sub_8207DAC0(ctx, base);
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// stw r27,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r27.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_82163328:
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r29,r11,r5
	ctx.r29.s64 = ctx.r5.s64 - ctx.r11.s64;
	// cmplw cr6,r29,r30
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r30.u32, ctx.xer);
	// ble cr6,0x8216333c
	if (!ctx.cr6.gt) goto loc_8216333C;
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
loc_8216333C:
	// lwz r28,12(r28)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// add r3,r11,r3
	ctx.r3.u64 = ctx.r11.u64 + ctx.r3.u64;
	// subf r4,r30,r28
	ctx.r4.s64 = ctx.r28.s64 - ctx.r30.s64;
	// bl 0x8207dac0
	ctx.lr = 0x82163350;
	sub_8207DAC0(ctx, base);
	// subf. r30,r29,r30
	ctx.r30.s64 = ctx.r30.s64 - ctx.r29.s64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x82163380
	if (ctx.cr0.eq) goto loc_82163380;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// subf r4,r30,r28
	ctx.r4.s64 = ctx.r28.s64 - ctx.r30.s64;
	// bl 0x8207dac0
	ctx.lr = 0x82163368;
	sub_8207DAC0(ctx, base);
	// lwz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// stw r30,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r30.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_82163380:
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// stw r11,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8216339c
	if (!ctx.cr6.eq) goto loc_8216339C;
	// stw r27,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r27.u32);
loc_8216339C:
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x821633b0
	if (!ctx.cr6.lt) goto loc_821633B0;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
loc_821633B0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821633BC"))) PPC_WEAK_FUNC(sub_821633BC);
PPC_FUNC_IMPL(__imp__sub_821633BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821633C0"))) PPC_WEAK_FUNC(sub_821633C0);
PPC_FUNC_IMPL(__imp__sub_821633C0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r10,9
	ctx.r10.s64 = 9;
	// addi r11,r11,-25240
	ctx.r11.s64 = ctx.r11.s64 + -25240;
	// li r9,5
	ctx.r9.s64 = 5;
	// stw r10,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, ctx.r10.u32);
	// addi r8,r11,-2048
	ctx.r8.s64 = ctx.r11.s64 + -2048;
	// stw r11,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, ctx.r11.u32);
	// stw r9,88(r3)
	PPC_STORE_U32(ctx.r3.u32 + 88, ctx.r9.u32);
	// stw r8,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821633E8"))) PPC_WEAK_FUNC(sub_821633E8);
PPC_FUNC_IMPL(__imp__sub_821633E8) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82163460
	if (ctx.cr6.eq) goto loc_82163460;
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82163460
	if (ctx.cr6.eq) goto loc_82163460;
	// lis r8,0
	ctx.r8.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r9,r11,1328
	ctx.r9.s64 = ctx.r11.s64 + 1328;
	// stw r10,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// ori r6,r8,32768
	ctx.r6.u64 = ctx.r8.u64 | 32768;
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// stw r10,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r10.u32);
	// stw r7,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r7.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r9,108(r11)
	PPC_STORE_U32(ctx.r11.u32 + 108, ctx.r9.u32);
	// stw r10,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r10.u32);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r6,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r6.u32);
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// stw r10,40(r11)
	PPC_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
	// stw r10,44(r11)
	PPC_STORE_U32(ctx.r11.u32 + 44, ctx.r10.u32);
	// stw r10,48(r11)
	PPC_STORE_U32(ctx.r11.u32 + 48, ctx.r10.u32);
	// stw r10,56(r11)
	PPC_STORE_U32(ctx.r11.u32 + 56, ctx.r10.u32);
	// stw r10,60(r11)
	PPC_STORE_U32(ctx.r11.u32 + 60, ctx.r10.u32);
	// stw r9,80(r11)
	PPC_STORE_U32(ctx.r11.u32 + 80, ctx.r9.u32);
	// stw r9,76(r11)
	PPC_STORE_U32(ctx.r11.u32 + 76, ctx.r9.u32);
	// blr 
	return;
loc_82163460:
	// li r3,-2
	ctx.r3.s64 = -2;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82163468"))) PPC_WEAK_FUNC(sub_82163468);
PPC_FUNC_IMPL(__imp__sub_82163468) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c950
	ctx.lr = 0x82163470;
	__savegprlr_14(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82164a7c
	if (ctx.cr6.eq) goto loc_82164A7C;
	// lwz r29,28(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82164a7c
	if (ctx.cr6.eq) goto loc_82164A7C;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82164a7c
	if (ctx.cr6.eq) goto loc_82164A7C;
	// lwz r28,0(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x821634b0
	if (!ctx.cr6.eq) goto loc_821634B0;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82164a7c
	if (!ctx.cr6.eq) goto loc_82164A7C;
loc_821634B0:
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// cmpwi cr6,r10,11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 11, ctx.xer);
	// bne cr6,0x821634c4
	if (!ctx.cr6.eq) goto loc_821634C4;
	// li r10,12
	ctx.r10.s64 = 12;
	// stw r10,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r10.u32);
loc_821634C4:
	// lwz r27,4(r23)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r23.u32 + 4);
	// li r19,0
	ctx.r19.s64 = 0;
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mr r18,r11
	ctx.r18.u64 = ctx.r11.u64;
	// lwz r20,16(r23)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16);
	// mr r15,r19
	ctx.r15.u64 = ctx.r19.u64;
	// lwz r30,56(r29)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r29.u32 + 56);
	// cmplwi cr6,r9,28
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 28, ctx.xer);
	// lwz r31,60(r29)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r29.u32 + 60);
	// mr r16,r20
	ctx.r16.u64 = ctx.r20.u64;
	// stw r27,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r27.u32);
	// bgt cr6,0x82164a7c
	if (ctx.cr6.gt) goto loc_82164A7C;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r24,1
	ctx.r24.s64 = 1;
	// addi r22,r11,-14076
	ctx.r22.s64 = ctx.r11.s64 + -14076;
	// li r21,27
	ctx.r21.s64 = 27;
	// li r14,9
	ctx.r14.s64 = 9;
	// addi r17,r10,-25240
	ctx.r17.s64 = ctx.r10.s64 + -25240;
	// li r25,18
	ctx.r25.s64 = 18;
loc_82163514:
	// li r26,5
	ctx.r26.s64 = 5;
	// lis r12,-32234
	ctx.r12.s64 = -2112487424;
	// rlwinm r0,r9,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,13616
	ctx.r12.s64 = ctx.r12.s64 + 13616;
	// lwzx r0,r12,r0
	ctx.r0.u64 = PPC_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r9.u64) {
	case 0:
		goto loc_821635A4;
	case 1:
		goto loc_8216372C;
	case 2:
		goto loc_821637E8;
	case 3:
		goto loc_8216387C;
	case 4:
		goto loc_8216390C;
	case 5:
		goto loc_821639B0;
	case 6:
		goto loc_82163A80;
	case 7:
		goto loc_82163B54;
	case 8:
		goto loc_82163C24;
	case 9:
		goto loc_82163CCC;
	case 10:
		goto loc_82163D34;
	case 11:
		goto loc_82163D60;
	case 12:
		goto loc_82163D60;
	case 13:
		goto loc_82163E48;
	case 14:
		goto loc_82163EB8;
	case 15:
		goto loc_82163F14;
	case 16:
		goto loc_82163F9C;
	case 17:
		goto loc_821640C0;
	case 18:
		goto loc_821643EC;
	case 19:
		goto loc_821645E4;
	case 20:
		goto loc_8216464C;
	case 21:
		goto loc_821647CC;
	case 22:
		goto loc_82164858;
	case 23:
		goto loc_82164900;
	case 24:
		goto loc_82164920;
	case 25:
		goto loc_82164A14;
	case 26:
		goto loc_82164ABC;
	case 27:
		goto loc_82164AC4;
	case 28:
		goto loc_82164C04;
	default:
		__builtin_unreachable();
	}
	// lwz r16,13732(r22)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r22.u32 + 13732);
	// lwz r16,14124(r22)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r22.u32 + 14124);
	// lwz r16,14312(r22)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r22.u32 + 14312);
	// lwz r16,14460(r22)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r22.u32 + 14460);
	// lwz r16,14604(r22)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r22.u32 + 14604);
	// lwz r16,14768(r22)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r22.u32 + 14768);
	// lwz r16,14976(r22)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r22.u32 + 14976);
	// lwz r16,15188(r22)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r22.u32 + 15188);
	// lwz r16,15396(r22)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r22.u32 + 15396);
	// lwz r16,15564(r22)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r22.u32 + 15564);
	// lwz r16,15668(r22)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r22.u32 + 15668);
	// lwz r16,15712(r22)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r22.u32 + 15712);
	// lwz r16,15712(r22)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r22.u32 + 15712);
	// lwz r16,15944(r22)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r22.u32 + 15944);
	// lwz r16,16056(r22)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r22.u32 + 16056);
	// lwz r16,16148(r22)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r22.u32 + 16148);
	// lwz r16,16284(r22)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r22.u32 + 16284);
	// lwz r16,16576(r22)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r22.u32 + 16576);
	// lwz r16,17388(r22)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r22.u32 + 17388);
	// lwz r16,17892(r22)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r22.u32 + 17892);
	// lwz r16,17996(r22)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r22.u32 + 17996);
	// lwz r16,18380(r22)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r22.u32 + 18380);
	// lwz r16,18520(r22)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r22.u32 + 18520);
	// lwz r16,18688(r22)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r22.u32 + 18688);
	// lwz r16,18720(r22)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r22.u32 + 18720);
	// lwz r16,18964(r22)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r22.u32 + 18964);
	// lwz r16,19132(r22)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r22.u32 + 19132);
	// lwz r16,19140(r22)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r22.u32 + 19140);
	// lwz r16,19460(r22)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r22.u32 + 19460);
loc_821635A4:
	// lwz r10,8(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x821635bc
	if (!ctx.cr6.eq) goto loc_821635BC;
	// li r11,12
	ctx.r11.s64 = 12;
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// b 0x82164a70
	goto loc_82164A70;
loc_821635BC:
	// cmplwi cr6,r31,16
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 16, ctx.xer);
	// bge cr6,0x821635ec
	if (!ctx.cr6.lt) goto loc_821635EC;
loc_821635C4:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82164ac8
	if (ctx.cr6.eq) goto loc_82164AC8;
	// lbz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// addi r27,r27,-1
	ctx.r27.s64 = ctx.r27.s64 + -1;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// slw r11,r11,r31
	ctx.r11.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r31.u8 & 0x3F));
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// cmplwi cr6,r31,16
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 16, ctx.xer);
	// blt cr6,0x821635c4
	if (ctx.cr6.lt) goto loc_821635C4;
loc_821635EC:
	// rlwinm r11,r10,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82163644
	if (ctx.cr6.eq) goto loc_82163644;
	// cmplwi cr6,r30,35615
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 35615, ctx.xer);
	// bne cr6,0x82163644
	if (!ctx.cr6.eq) goto loc_82163644;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82162748
	ctx.lr = 0x82163610;
	sub_82162748(ctx, base);
	// li r11,31
	ctx.r11.s64 = 31;
	// li r10,139
	ctx.r10.s64 = 139;
	// stw r3,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r3.u32);
	// stb r11,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r11.u8);
	// li r5,2
	ctx.r5.s64 = 2;
	// stb r10,85(r1)
	PPC_STORE_U8(ctx.r1.u32 + 85, ctx.r10.u8);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// bl 0x821620d8
	ctx.lr = 0x82163630;
	sub_821620D8(ctx, base);
	// stw r3,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r3.u32);
	// mr r30,r19
	ctx.r30.u64 = ctx.r19.u64;
	// stw r24,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r24.u32);
	// mr r31,r19
	ctx.r31.u64 = ctx.r19.u64;
	// b 0x82164a70
	goto loc_82164A70;
loc_82163644:
	// lwz r11,32(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 32);
	// stw r19,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r19.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8216365c
	if (ctx.cr6.eq) goto loc_8216365C;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r10,48(r11)
	PPC_STORE_U32(ctx.r11.u32 + 48, ctx.r10.u32);
loc_8216365C:
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82163720
	if (ctx.cr6.eq) goto loc_82163720;
	// rlwinm r10,r30,8,16,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 8) & 0xFF00;
	// lis r9,2114
	ctx.r9.s64 = 138543104;
	// rlwinm r11,r30,24,8,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 24) & 0xFFFFFF;
	// ori r8,r9,4229
	ctx.r8.u64 = ctx.r9.u64 | 4229;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// mulhwu r10,r11,r8
	ctx.r10.u64 = (uint64_t(ctx.r11.u32) * uint64_t(ctx.r8.u32)) >> 32;
	// subf r7,r10,r11
	ctx.r7.s64 = ctx.r11.s64 - ctx.r10.s64;
	// rlwinm r9,r7,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rlwinm r5,r6,28,4,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 28) & 0xFFFFFFF;
	// rlwinm r4,r5,5,0,26
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 5) & 0xFFFFFFE0;
	// subf r3,r5,r4
	ctx.r3.s64 = ctx.r4.s64 - ctx.r5.s64;
	// subf. r11,r3,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r3.s64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82163720
	if (!ctx.cr0.eq) goto loc_82163720;
	// clrlwi r11,r30,28
	ctx.r11.u64 = ctx.r30.u32 & 0xF;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// beq cr6,0x821636bc
	if (ctx.cr6.eq) goto loc_821636BC;
	// addi r11,r22,-456
	ctx.r11.s64 = ctx.r22.s64 + -456;
	// stw r11,24(r23)
	PPC_STORE_U32(ctx.r23.u32 + 24, ctx.r11.u32);
	// b 0x82164a6c
	goto loc_82164A6C;
loc_821636BC:
	// rlwinm r30,r30,28,4,31
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 28) & 0xFFFFFFF;
	// lwz r10,36(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 36);
	// addi r31,r31,-4
	ctx.r31.s64 = ctx.r31.s64 + -4;
	// clrlwi r11,r30,28
	ctx.r11.u64 = ctx.r30.u32 & 0xF;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x821636e4
	if (!ctx.cr6.gt) goto loc_821636E4;
	// addi r11,r22,-428
	ctx.r11.s64 = ctx.r22.s64 + -428;
	// stw r11,24(r23)
	PPC_STORE_U32(ctx.r23.u32 + 24, ctx.r11.u32);
	// b 0x82164a6c
	goto loc_82164A6C;
loc_821636E4:
	// slw r11,r24,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r24.u32 << (ctx.r11.u8 & 0x3F));
	// stw r11,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82162bb8
	ctx.lr = 0x821636FC;
	sub_82162BB8(ctx, base);
	// not r10,r30
	ctx.r10.u64 = ~ctx.r30.u64;
	// mr r9,r14
	ctx.r9.u64 = ctx.r14.u64;
	// stw r3,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r3.u32);
	// mr r30,r19
	ctx.r30.u64 = ctx.r19.u64;
	// stw r3,48(r23)
	PPC_STORE_U32(ctx.r23.u32 + 48, ctx.r3.u32);
	// rlwimi r9,r10,24,30,30
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 24) & 0x2) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFFFD);
	// mr r31,r19
	ctx.r31.u64 = ctx.r19.u64;
	// stw r9,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r9.u32);
	// b 0x82164a70
	goto loc_82164A70;
loc_82163720:
	// addi r11,r22,-480
	ctx.r11.s64 = ctx.r22.s64 + -480;
	// stw r11,24(r23)
	PPC_STORE_U32(ctx.r23.u32 + 24, ctx.r11.u32);
	// b 0x82164a6c
	goto loc_82164A6C;
loc_8216372C:
	// cmplwi cr6,r31,16
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 16, ctx.xer);
	// bge cr6,0x8216375c
	if (!ctx.cr6.lt) goto loc_8216375C;
loc_82163734:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82164ac8
	if (ctx.cr6.eq) goto loc_82164AC8;
	// lbz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// addi r27,r27,-1
	ctx.r27.s64 = ctx.r27.s64 + -1;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// slw r11,r11,r31
	ctx.r11.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r31.u8 & 0x3F));
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// cmplwi cr6,r31,16
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 16, ctx.xer);
	// blt cr6,0x82163734
	if (ctx.cr6.lt) goto loc_82163734;
loc_8216375C:
	// clrlwi r11,r30,24
	ctx.r11.u64 = ctx.r30.u32 & 0xFF;
	// stw r30,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r30.u32);
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// beq cr6,0x82163778
	if (ctx.cr6.eq) goto loc_82163778;
	// addi r11,r22,-408
	ctx.r11.s64 = ctx.r22.s64 + -408;
	// stw r11,24(r23)
	PPC_STORE_U32(ctx.r23.u32 + 24, ctx.r11.u32);
	// b 0x82164a6c
	goto loc_82164A6C;
loc_82163778:
	// rlwinm r11,r30,0,16,18
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0xE000;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82163790
	if (ctx.cr6.eq) goto loc_82163790;
	// addi r11,r22,-380
	ctx.r11.s64 = ctx.r22.s64 + -380;
	// stw r11,24(r23)
	PPC_STORE_U32(ctx.r23.u32 + 24, ctx.r11.u32);
	// b 0x82164a6c
	goto loc_82164A6C;
loc_82163790:
	// lwz r11,32(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821637a4
	if (ctx.cr6.eq) goto loc_821637A4;
	// rlwinm r10,r30,24,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 24) & 0x1;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_821637A4:
	// lwz r11,16(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// rlwinm r10,r11,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x200;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x821637d4
	if (ctx.cr6.eq) goto loc_821637D4;
	// rlwinm r10,r30,24,24,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 24) & 0xFF;
	// stb r30,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r30.u8);
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// stb r10,85(r1)
	PPC_STORE_U8(ctx.r1.u32 + 85, ctx.r10.u8);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// bl 0x821620d8
	ctx.lr = 0x821637D0;
	sub_821620D8(ctx, base);
	// stw r3,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r3.u32);
loc_821637D4:
	// li r11,2
	ctx.r11.s64 = 2;
	// mr r30,r19
	ctx.r30.u64 = ctx.r19.u64;
	// mr r31,r19
	ctx.r31.u64 = ctx.r19.u64;
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// b 0x821637f0
	goto loc_821637F0;
loc_821637E8:
	// cmplwi cr6,r31,32
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 32, ctx.xer);
	// bge cr6,0x82163818
	if (!ctx.cr6.lt) goto loc_82163818;
loc_821637F0:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82164ac8
	if (ctx.cr6.eq) goto loc_82164AC8;
	// lbz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// addi r27,r27,-1
	ctx.r27.s64 = ctx.r27.s64 + -1;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// slw r11,r11,r31
	ctx.r11.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r31.u8 & 0x3F));
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// cmplwi cr6,r31,32
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 32, ctx.xer);
	// blt cr6,0x821637f0
	if (ctx.cr6.lt) goto loc_821637F0;
loc_82163818:
	// lwz r11,32(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82163828
	if (ctx.cr6.eq) goto loc_82163828;
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
loc_82163828:
	// lwz r11,16(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// rlwinm r10,r11,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x200;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82163868
	if (ctx.cr6.eq) goto loc_82163868;
	// rlwinm r10,r30,24,24,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 24) & 0xFF;
	// stb r30,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r30.u8);
	// rlwinm r9,r30,16,24,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 16) & 0xFF;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// rlwinm r8,r30,8,24,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 8) & 0xFF;
	// stb r10,85(r1)
	PPC_STORE_U8(ctx.r1.u32 + 85, ctx.r10.u8);
	// stb r9,86(r1)
	PPC_STORE_U8(ctx.r1.u32 + 86, ctx.r9.u8);
	// li r5,4
	ctx.r5.s64 = 4;
	// stb r8,87(r1)
	PPC_STORE_U8(ctx.r1.u32 + 87, ctx.r8.u8);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// bl 0x821620d8
	ctx.lr = 0x82163864;
	sub_821620D8(ctx, base);
	// stw r3,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r3.u32);
loc_82163868:
	// li r11,3
	ctx.r11.s64 = 3;
	// mr r30,r19
	ctx.r30.u64 = ctx.r19.u64;
	// mr r31,r19
	ctx.r31.u64 = ctx.r19.u64;
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// b 0x82163884
	goto loc_82163884;
loc_8216387C:
	// cmplwi cr6,r31,16
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 16, ctx.xer);
	// bge cr6,0x821638ac
	if (!ctx.cr6.lt) goto loc_821638AC;
loc_82163884:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82164ac8
	if (ctx.cr6.eq) goto loc_82164AC8;
	// lbz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// addi r27,r27,-1
	ctx.r27.s64 = ctx.r27.s64 + -1;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// slw r11,r11,r31
	ctx.r11.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r31.u8 & 0x3F));
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// cmplwi cr6,r31,16
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 16, ctx.xer);
	// blt cr6,0x82163884
	if (ctx.cr6.lt) goto loc_82163884;
loc_821638AC:
	// lwz r11,32(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821638cc
	if (ctx.cr6.eq) goto loc_821638CC;
	// clrlwi r10,r30,24
	ctx.r10.u64 = ctx.r30.u32 & 0xFF;
	// rlwinm r9,r30,24,8,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 24) & 0xFFFFFF;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// lwz r8,32(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 32);
	// stw r9,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r9.u32);
loc_821638CC:
	// lwz r11,16(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// rlwinm r10,r11,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x200;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x821638fc
	if (ctx.cr6.eq) goto loc_821638FC;
	// rlwinm r10,r30,24,24,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 24) & 0xFF;
	// stb r30,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r30.u8);
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// stb r10,85(r1)
	PPC_STORE_U8(ctx.r1.u32 + 85, ctx.r10.u8);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// bl 0x821620d8
	ctx.lr = 0x821638F8;
	sub_821620D8(ctx, base);
	// stw r3,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r3.u32);
loc_821638FC:
	// li r11,4
	ctx.r11.s64 = 4;
	// mr r30,r19
	ctx.r30.u64 = ctx.r19.u64;
	// mr r31,r19
	ctx.r31.u64 = ctx.r19.u64;
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
loc_8216390C:
	// lwz r11,16(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// rlwinm r10,r11,0,21,21
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x400;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8216399c
	if (ctx.cr6.eq) goto loc_8216399C;
	// cmplwi cr6,r31,16
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 16, ctx.xer);
	// bge cr6,0x8216394c
	if (!ctx.cr6.lt) goto loc_8216394C;
loc_82163924:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82164ac8
	if (ctx.cr6.eq) goto loc_82164AC8;
	// lbz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// addi r27,r27,-1
	ctx.r27.s64 = ctx.r27.s64 + -1;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// slw r11,r11,r31
	ctx.r11.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r31.u8 & 0x3F));
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// cmplwi cr6,r31,16
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 16, ctx.xer);
	// blt cr6,0x82163924
	if (ctx.cr6.lt) goto loc_82163924;
loc_8216394C:
	// lwz r11,32(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 32);
	// stw r30,64(r29)
	PPC_STORE_U32(ctx.r29.u32 + 64, ctx.r30.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82163960
	if (ctx.cr6.eq) goto loc_82163960;
	// stw r30,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r30.u32);
loc_82163960:
	// lwz r11,16(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// rlwinm r10,r11,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x200;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82163990
	if (ctx.cr6.eq) goto loc_82163990;
	// rlwinm r10,r30,24,24,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 24) & 0xFF;
	// stb r30,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r30.u8);
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// stb r10,85(r1)
	PPC_STORE_U8(ctx.r1.u32 + 85, ctx.r10.u8);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// bl 0x821620d8
	ctx.lr = 0x8216398C;
	sub_821620D8(ctx, base);
	// stw r3,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r3.u32);
loc_82163990:
	// mr r30,r19
	ctx.r30.u64 = ctx.r19.u64;
	// mr r31,r19
	ctx.r31.u64 = ctx.r19.u64;
	// b 0x821639ac
	goto loc_821639AC;
loc_8216399C:
	// lwz r11,32(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821639ac
	if (ctx.cr6.eq) goto loc_821639AC;
	// stw r19,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r19.u32);
loc_821639AC:
	// stw r26,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r26.u32);
loc_821639B0:
	// lwz r11,16(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// rlwinm r10,r11,0,21,21
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x400;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82163a74
	if (ctx.cr6.eq) goto loc_82163A74;
	// lwz r9,64(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 64);
	// mr r26,r9
	ctx.r26.u64 = ctx.r9.u64;
	// cmplw cr6,r9,r27
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r27.u32, ctx.xer);
	// ble cr6,0x821639d4
	if (!ctx.cr6.gt) goto loc_821639D4;
	// mr r26,r27
	ctx.r26.u64 = ctx.r27.u64;
loc_821639D4:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x82163a68
	if (ctx.cr6.eq) goto loc_82163A68;
	// lwz r11,32(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82163a20
	if (ctx.cr6.eq) goto loc_82163A20;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82163a20
	if (ctx.cr6.eq) goto loc_82163A20;
	// lwz r7,20(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// subf r11,r9,r7
	ctx.r11.s64 = ctx.r7.s64 - ctx.r9.s64;
	// add r6,r26,r11
	ctx.r6.u64 = ctx.r26.u64 + ctx.r11.u64;
	// subf r5,r11,r10
	ctx.r5.s64 = ctx.r10.s64 - ctx.r11.s64;
	// cmplw cr6,r6,r10
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x82163a14
	if (ctx.cr6.gt) goto loc_82163A14;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
loc_82163A14:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// add r3,r8,r11
	ctx.r3.u64 = ctx.r8.u64 + ctx.r11.u64;
	// bl 0x8207dac0
	ctx.lr = 0x82163A20;
	sub_8207DAC0(ctx, base);
loc_82163A20:
	// lwz r11,16(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// rlwinm r10,r11,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x200;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82163a54
	if (ctx.cr6.eq) goto loc_82163A54;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x82163a44
	if (!ctx.cr6.eq) goto loc_82163A44;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// b 0x82163a50
	goto loc_82163A50;
loc_82163A44:
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x821620d8
	ctx.lr = 0x82163A50;
	sub_821620D8(ctx, base);
loc_82163A50:
	// stw r3,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r3.u32);
loc_82163A54:
	// lwz r11,64(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 64);
	// subf r27,r26,r27
	ctx.r27.s64 = ctx.r27.s64 - ctx.r26.s64;
	// add r28,r26,r28
	ctx.r28.u64 = ctx.r26.u64 + ctx.r28.u64;
	// subf r10,r26,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r26.s64;
	// stw r10,64(r29)
	PPC_STORE_U32(ctx.r29.u32 + 64, ctx.r10.u32);
loc_82163A68:
	// lwz r11,64(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 64);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82164ac8
	if (!ctx.cr6.eq) goto loc_82164AC8;
loc_82163A74:
	// li r11,6
	ctx.r11.s64 = 6;
	// stw r19,64(r29)
	PPC_STORE_U32(ctx.r29.u32 + 64, ctx.r19.u32);
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
loc_82163A80:
	// lwz r11,16(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// rlwinm r10,r11,0,20,20
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x800;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82163b38
	if (ctx.cr6.eq) goto loc_82163B38;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82164ac8
	if (ctx.cr6.eq) goto loc_82164AC8;
	// mr r26,r19
	ctx.r26.u64 = ctx.r19.u64;
loc_82163A9C:
	// lwz r11,32(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 32);
	// lbzx r25,r26,r28
	ctx.r25.u64 = PPC_LOAD_U8(ctx.r26.u32 + ctx.r28.u32);
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82163adc
	if (ctx.cr6.eq) goto loc_82163ADC;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82163adc
	if (ctx.cr6.eq) goto loc_82163ADC;
	// lwz r9,32(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// lwz r11,64(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 64);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x82163adc
	if (!ctx.cr6.lt) goto loc_82163ADC;
	// stbx r25,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + ctx.r11.u32, ctx.r25.u8);
	// lwz r11,64(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 64);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// stw r8,64(r29)
	PPC_STORE_U32(ctx.r29.u32 + 64, ctx.r8.u32);
loc_82163ADC:
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x82163aec
	if (ctx.cr6.eq) goto loc_82163AEC;
	// cmplw cr6,r26,r27
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r27.u32, ctx.xer);
	// blt cr6,0x82163a9c
	if (ctx.cr6.lt) goto loc_82163A9C;
loc_82163AEC:
	// lwz r11,16(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// rlwinm r10,r11,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x200;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82163b20
	if (ctx.cr6.eq) goto loc_82163B20;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x82163b10
	if (!ctx.cr6.eq) goto loc_82163B10;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// b 0x82163b1c
	goto loc_82163B1C;
loc_82163B10:
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x821620d8
	ctx.lr = 0x82163B1C;
	sub_821620D8(ctx, base);
loc_82163B1C:
	// stw r3,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r3.u32);
loc_82163B20:
	// subf r27,r26,r27
	ctx.r27.s64 = ctx.r27.s64 - ctx.r26.s64;
	// add r28,r26,r28
	ctx.r28.u64 = ctx.r26.u64 + ctx.r28.u64;
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// bne cr6,0x82164ac8
	if (!ctx.cr6.eq) goto loc_82164AC8;
	// li r25,18
	ctx.r25.s64 = 18;
	// b 0x82163b48
	goto loc_82163B48;
loc_82163B38:
	// lwz r11,32(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82163b48
	if (ctx.cr6.eq) goto loc_82163B48;
	// stw r19,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r19.u32);
loc_82163B48:
	// li r11,7
	ctx.r11.s64 = 7;
	// stw r19,64(r29)
	PPC_STORE_U32(ctx.r29.u32 + 64, ctx.r19.u32);
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
loc_82163B54:
	// lwz r11,16(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// rlwinm r10,r11,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x1000;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82163c0c
	if (ctx.cr6.eq) goto loc_82163C0C;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82164ac8
	if (ctx.cr6.eq) goto loc_82164AC8;
	// mr r26,r19
	ctx.r26.u64 = ctx.r19.u64;
loc_82163B70:
	// lwz r11,32(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 32);
	// lbzx r25,r26,r28
	ctx.r25.u64 = PPC_LOAD_U8(ctx.r26.u32 + ctx.r28.u32);
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82163bb0
	if (ctx.cr6.eq) goto loc_82163BB0;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82163bb0
	if (ctx.cr6.eq) goto loc_82163BB0;
	// lwz r9,40(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// lwz r11,64(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 64);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x82163bb0
	if (!ctx.cr6.lt) goto loc_82163BB0;
	// stbx r25,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + ctx.r11.u32, ctx.r25.u8);
	// lwz r11,64(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 64);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// stw r8,64(r29)
	PPC_STORE_U32(ctx.r29.u32 + 64, ctx.r8.u32);
loc_82163BB0:
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x82163bc0
	if (ctx.cr6.eq) goto loc_82163BC0;
	// cmplw cr6,r26,r27
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r27.u32, ctx.xer);
	// blt cr6,0x82163b70
	if (ctx.cr6.lt) goto loc_82163B70;
loc_82163BC0:
	// lwz r11,16(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// rlwinm r10,r11,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x200;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82163bf4
	if (ctx.cr6.eq) goto loc_82163BF4;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x82163be4
	if (!ctx.cr6.eq) goto loc_82163BE4;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// b 0x82163bf0
	goto loc_82163BF0;
loc_82163BE4:
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x821620d8
	ctx.lr = 0x82163BF0;
	sub_821620D8(ctx, base);
loc_82163BF0:
	// stw r3,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r3.u32);
loc_82163BF4:
	// subf r27,r26,r27
	ctx.r27.s64 = ctx.r27.s64 - ctx.r26.s64;
	// add r28,r26,r28
	ctx.r28.u64 = ctx.r26.u64 + ctx.r28.u64;
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// bne cr6,0x82164ac8
	if (!ctx.cr6.eq) goto loc_82164AC8;
	// li r25,18
	ctx.r25.s64 = 18;
	// b 0x82163c1c
	goto loc_82163C1C;
loc_82163C0C:
	// lwz r11,32(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82163c1c
	if (ctx.cr6.eq) goto loc_82163C1C;
	// stw r19,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r19.u32);
loc_82163C1C:
	// li r11,8
	ctx.r11.s64 = 8;
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
loc_82163C24:
	// lwz r11,16(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// rlwinm r10,r11,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x200;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82163c84
	if (ctx.cr6.eq) goto loc_82163C84;
	// cmplwi cr6,r31,16
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 16, ctx.xer);
	// bge cr6,0x82163c64
	if (!ctx.cr6.lt) goto loc_82163C64;
loc_82163C3C:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82164ac8
	if (ctx.cr6.eq) goto loc_82164AC8;
	// lbz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// addi r27,r27,-1
	ctx.r27.s64 = ctx.r27.s64 + -1;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// slw r11,r11,r31
	ctx.r11.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r31.u8 & 0x3F));
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// cmplwi cr6,r31,16
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 16, ctx.xer);
	// blt cr6,0x82163c3c
	if (ctx.cr6.lt) goto loc_82163C3C;
loc_82163C64:
	// lhz r11,26(r29)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r29.u32 + 26);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82163c7c
	if (ctx.cr6.eq) goto loc_82163C7C;
	// addi r11,r22,-352
	ctx.r11.s64 = ctx.r22.s64 + -352;
	// stw r11,24(r23)
	PPC_STORE_U32(ctx.r23.u32 + 24, ctx.r11.u32);
	// b 0x82164a6c
	goto loc_82164A6C;
loc_82163C7C:
	// mr r30,r19
	ctx.r30.u64 = ctx.r19.u64;
	// mr r31,r19
	ctx.r31.u64 = ctx.r19.u64;
loc_82163C84:
	// lwz r11,32(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82163ca8
	if (ctx.cr6.eq) goto loc_82163CA8;
	// lwz r10,16(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// srawi r9,r10,9
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1FF) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 9;
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// stw r8,44(r11)
	PPC_STORE_U32(ctx.r11.u32 + 44, ctx.r8.u32);
	// lwz r7,32(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 32);
	// stw r24,48(r7)
	PPC_STORE_U32(ctx.r7.u32 + 48, ctx.r24.u32);
loc_82163CA8:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82162748
	ctx.lr = 0x82163CB8;
	sub_82162748(ctx, base);
	// li r11,11
	ctx.r11.s64 = 11;
	// stw r3,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r3.u32);
	// stw r3,48(r23)
	PPC_STORE_U32(ctx.r23.u32 + 48, ctx.r3.u32);
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// b 0x82164a70
	goto loc_82164A70;
loc_82163CCC:
	// cmplwi cr6,r31,32
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 32, ctx.xer);
	// bge cr6,0x82163cfc
	if (!ctx.cr6.lt) goto loc_82163CFC;
loc_82163CD4:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82164ac8
	if (ctx.cr6.eq) goto loc_82164AC8;
	// lbz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// addi r27,r27,-1
	ctx.r27.s64 = ctx.r27.s64 + -1;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// slw r11,r11,r31
	ctx.r11.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r31.u8 & 0x3F));
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// cmplwi cr6,r31,32
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 32, ctx.xer);
	// blt cr6,0x82163cd4
	if (ctx.cr6.lt) goto loc_82163CD4;
loc_82163CFC:
	// rlwinm r10,r30,0,16,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0xFF00;
	// rlwinm r11,r30,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r9,r30,24,16,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 24) & 0xFF00;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r10,r30,8,24,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 8) & 0xFF;
	// rlwinm r11,r11,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// li r8,10
	ctx.r8.s64 = 10;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// mr r30,r19
	ctx.r30.u64 = ctx.r19.u64;
	// stw r8,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r8.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mr r31,r19
	ctx.r31.u64 = ctx.r19.u64;
	// stw r11,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r11.u32);
	// stw r11,48(r23)
	PPC_STORE_U32(ctx.r23.u32 + 48, ctx.r11.u32);
loc_82163D34:
	// lwz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82164a88
	if (ctx.cr6.eq) goto loc_82164A88;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82162bb8
	ctx.lr = 0x82163D50;
	sub_82162BB8(ctx, base);
	// li r11,11
	ctx.r11.s64 = 11;
	// stw r3,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r3.u32);
	// stw r3,48(r23)
	PPC_STORE_U32(ctx.r23.u32 + 48, ctx.r3.u32);
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
loc_82163D60:
	// lwz r11,4(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82163d84
	if (ctx.cr6.eq) goto loc_82163D84;
	// clrlwi r11,r31,29
	ctx.r11.u64 = ctx.r31.u32 & 0x7;
	// li r10,24
	ctx.r10.s64 = 24;
	// srw r30,r30,r11
	ctx.r30.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r30.u32 >> (ctx.r11.u8 & 0x3F));
	// subf r31,r11,r31
	ctx.r31.s64 = ctx.r31.s64 - ctx.r11.s64;
	// stw r10,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r10.u32);
	// b 0x82164a70
	goto loc_82164A70;
loc_82163D84:
	// cmplwi cr6,r31,3
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 3, ctx.xer);
	// bge cr6,0x82163db4
	if (!ctx.cr6.lt) goto loc_82163DB4;
loc_82163D8C:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82164ac8
	if (ctx.cr6.eq) goto loc_82164AC8;
	// lbz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// addi r27,r27,-1
	ctx.r27.s64 = ctx.r27.s64 + -1;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// slw r11,r11,r31
	ctx.r11.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r31.u8 & 0x3F));
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// cmplwi cr6,r31,3
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 3, ctx.xer);
	// blt cr6,0x82163d8c
	if (ctx.cr6.lt) goto loc_82163D8C;
loc_82163DB4:
	// rlwinm r10,r30,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 31) & 0x7FFFFFFF;
	// clrlwi r9,r30,31
	ctx.r9.u64 = ctx.r30.u32 & 0x1;
	// clrlwi r11,r10,30
	ctx.r11.u64 = ctx.r10.u32 & 0x3;
	// stw r9,4(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4, ctx.r9.u32);
	// addi r9,r31,-1
	ctx.r9.s64 = ctx.r31.s64 + -1;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x82163e3c
	if (ctx.cr6.gt) goto loc_82163E3C;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x82163df8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82163DF8;
	// bdzf 4*cr6+eq,0x82163e1c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82163E1C;
	// bne cr6,0x82163e30
	if (!ctx.cr6.eq) goto loc_82163E30;
	// li r11,13
	ctx.r11.s64 = 13;
	// rlwinm r30,r10,30,2,31
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// addi r31,r9,-2
	ctx.r31.s64 = ctx.r9.s64 + -2;
	// b 0x82164a70
	goto loc_82164A70;
loc_82163DF8:
	// addi r11,r17,-2048
	ctx.r11.s64 = ctx.r17.s64 + -2048;
	// stw r17,80(r29)
	PPC_STORE_U32(ctx.r29.u32 + 80, ctx.r17.u32);
	// stw r14,84(r29)
	PPC_STORE_U32(ctx.r29.u32 + 84, ctx.r14.u32);
	// rlwinm r30,r10,30,2,31
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// stw r11,76(r29)
	PPC_STORE_U32(ctx.r29.u32 + 76, ctx.r11.u32);
	// addi r31,r9,-2
	ctx.r31.s64 = ctx.r9.s64 + -2;
	// stw r26,88(r29)
	PPC_STORE_U32(ctx.r29.u32 + 88, ctx.r26.u32);
	// stw r25,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r25.u32);
	// b 0x82164a70
	goto loc_82164A70;
loc_82163E1C:
	// li r11,15
	ctx.r11.s64 = 15;
	// rlwinm r30,r10,30,2,31
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// addi r31,r9,-2
	ctx.r31.s64 = ctx.r9.s64 + -2;
	// b 0x82164a70
	goto loc_82164A70;
loc_82163E30:
	// addi r11,r22,-332
	ctx.r11.s64 = ctx.r22.s64 + -332;
	// stw r21,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r21.u32);
	// stw r11,24(r23)
	PPC_STORE_U32(ctx.r23.u32 + 24, ctx.r11.u32);
loc_82163E3C:
	// rlwinm r30,r10,30,2,31
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r31,r9,-2
	ctx.r31.s64 = ctx.r9.s64 + -2;
	// b 0x82164a70
	goto loc_82164A70;
loc_82163E48:
	// clrlwi r11,r31,29
	ctx.r11.u64 = ctx.r31.u32 & 0x7;
	// subf r31,r11,r31
	ctx.r31.s64 = ctx.r31.s64 - ctx.r11.s64;
	// srw r30,r30,r11
	ctx.r30.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r30.u32 >> (ctx.r11.u8 & 0x3F));
	// cmplwi cr6,r31,32
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 32, ctx.xer);
	// bge cr6,0x82163e84
	if (!ctx.cr6.lt) goto loc_82163E84;
loc_82163E5C:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82164ac8
	if (ctx.cr6.eq) goto loc_82164AC8;
	// lbz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// addi r27,r27,-1
	ctx.r27.s64 = ctx.r27.s64 + -1;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// slw r11,r11,r31
	ctx.r11.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r31.u8 & 0x3F));
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// cmplwi cr6,r31,32
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 32, ctx.xer);
	// blt cr6,0x82163e5c
	if (ctx.cr6.lt) goto loc_82163E5C;
loc_82163E84:
	// not r10,r30
	ctx.r10.u64 = ~ctx.r30.u64;
	// clrlwi r11,r30,16
	ctx.r11.u64 = ctx.r30.u32 & 0xFFFF;
	// rlwinm r9,r10,16,16,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82163ea4
	if (ctx.cr6.eq) goto loc_82163EA4;
	// addi r11,r22,-312
	ctx.r11.s64 = ctx.r22.s64 + -312;
	// stw r11,24(r23)
	PPC_STORE_U32(ctx.r23.u32 + 24, ctx.r11.u32);
	// b 0x82164a6c
	goto loc_82164A6C;
loc_82163EA4:
	// li r10,14
	ctx.r10.s64 = 14;
	// stw r11,64(r29)
	PPC_STORE_U32(ctx.r29.u32 + 64, ctx.r11.u32);
	// mr r30,r19
	ctx.r30.u64 = ctx.r19.u64;
	// mr r31,r19
	ctx.r31.u64 = ctx.r19.u64;
	// stw r10,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r10.u32);
loc_82163EB8:
	// lwz r26,64(r29)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r29.u32 + 64);
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x821645b0
	if (ctx.cr6.eq) goto loc_821645B0;
	// cmplw cr6,r26,r27
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r27.u32, ctx.xer);
	// ble cr6,0x82163ed0
	if (!ctx.cr6.gt) goto loc_82163ED0;
	// mr r26,r27
	ctx.r26.u64 = ctx.r27.u64;
loc_82163ED0:
	// cmplw cr6,r26,r20
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r20.u32, ctx.xer);
	// ble cr6,0x82163edc
	if (!ctx.cr6.gt) goto loc_82163EDC;
	// mr r26,r20
	ctx.r26.u64 = ctx.r20.u64;
loc_82163EDC:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x82164ac8
	if (ctx.cr6.eq) goto loc_82164AC8;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// bl 0x8207dac0
	ctx.lr = 0x82163EF4;
	sub_8207DAC0(ctx, base);
	// lwz r11,64(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 64);
	// subf r27,r26,r27
	ctx.r27.s64 = ctx.r27.s64 - ctx.r26.s64;
	// subf r10,r26,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r26.s64;
	// add r28,r26,r28
	ctx.r28.u64 = ctx.r26.u64 + ctx.r28.u64;
	// subf r20,r26,r20
	ctx.r20.s64 = ctx.r20.s64 - ctx.r26.s64;
	// stw r10,64(r29)
	PPC_STORE_U32(ctx.r29.u32 + 64, ctx.r10.u32);
	// add r18,r26,r18
	ctx.r18.u64 = ctx.r26.u64 + ctx.r18.u64;
	// b 0x82164a70
	goto loc_82164A70;
loc_82163F14:
	// cmplwi cr6,r31,14
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 14, ctx.xer);
	// bge cr6,0x82163f44
	if (!ctx.cr6.lt) goto loc_82163F44;
loc_82163F1C:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82164ac8
	if (ctx.cr6.eq) goto loc_82164AC8;
	// lbz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// addi r27,r27,-1
	ctx.r27.s64 = ctx.r27.s64 + -1;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// slw r11,r11,r31
	ctx.r11.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r31.u8 & 0x3F));
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// cmplwi cr6,r31,14
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 14, ctx.xer);
	// blt cr6,0x82163f1c
	if (ctx.cr6.lt) goto loc_82163F1C;
loc_82163F44:
	// rlwinm r11,r30,27,5,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r9,r30,27
	ctx.r9.u64 = ctx.r30.u32 & 0x1F;
	// rlwinm r8,r11,27,5,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r10,r11,27
	ctx.r10.u64 = ctx.r11.u32 & 0x1F;
	// addi r7,r9,257
	ctx.r7.s64 = ctx.r9.s64 + 257;
	// clrlwi r11,r8,28
	ctx.r11.u64 = ctx.r8.u32 & 0xF;
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// stw r7,96(r29)
	PPC_STORE_U32(ctx.r29.u32 + 96, ctx.r7.u32);
	// addi r5,r11,4
	ctx.r5.s64 = ctx.r11.s64 + 4;
	// rotlwi r4,r7,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// stw r6,100(r29)
	PPC_STORE_U32(ctx.r29.u32 + 100, ctx.r6.u32);
	// rlwinm r30,r8,28,4,31
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 28) & 0xFFFFFFF;
	// stw r5,92(r29)
	PPC_STORE_U32(ctx.r29.u32 + 92, ctx.r5.u32);
	// addi r31,r31,-14
	ctx.r31.s64 = ctx.r31.s64 + -14;
	// cmplwi cr6,r4,286
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 286, ctx.xer);
	// bgt cr6,0x821640a8
	if (ctx.cr6.gt) goto loc_821640A8;
	// rotlwi r11,r6,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// cmplwi cr6,r11,30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 30, ctx.xer);
	// bgt cr6,0x821640a8
	if (ctx.cr6.gt) goto loc_821640A8;
	// li r11,16
	ctx.r11.s64 = 16;
	// stw r19,104(r29)
	PPC_STORE_U32(ctx.r29.u32 + 104, ctx.r19.u32);
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
loc_82163F9C:
	// lwz r11,104(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 104);
	// lwz r10,92(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 92);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x82164020
	if (!ctx.cr6.lt) goto loc_82164020;
loc_82163FAC:
	// cmplwi cr6,r31,3
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 3, ctx.xer);
	// bge cr6,0x82163fdc
	if (!ctx.cr6.lt) goto loc_82163FDC;
loc_82163FB4:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82164ac8
	if (ctx.cr6.eq) goto loc_82164AC8;
	// lbz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// addi r27,r27,-1
	ctx.r27.s64 = ctx.r27.s64 + -1;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// slw r11,r11,r31
	ctx.r11.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r31.u8 & 0x3F));
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// cmplwi cr6,r31,3
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 3, ctx.xer);
	// blt cr6,0x82163fb4
	if (ctx.cr6.lt) goto loc_82163FB4;
loc_82163FDC:
	// lwz r11,104(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 104);
	// addi r10,r17,128
	ctx.r10.s64 = ctx.r17.s64 + 128;
	// clrlwi r9,r30,29
	ctx.r9.u64 = ctx.r30.u32 & 0x7;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r30,r30,29,3,31
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 29) & 0x1FFFFFFF;
	// addi r31,r31,-3
	ctx.r31.s64 = ctx.r31.s64 + -3;
	// lhzx r11,r8,r10
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r8.u32 + ctx.r10.u32);
	// addi r7,r11,56
	ctx.r7.s64 = ctx.r11.s64 + 56;
	// rlwinm r6,r7,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r9,r6,r29
	PPC_STORE_U16(ctx.r6.u32 + ctx.r29.u32, ctx.r9.u16);
	// lwz r11,104(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 104);
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r5,104(r29)
	PPC_STORE_U32(ctx.r29.u32 + 104, ctx.r5.u32);
	// lwz r3,92(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 92);
	// cmplw cr6,r4,r3
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r3.u32, ctx.xer);
	// blt cr6,0x82163fac
	if (ctx.cr6.lt) goto loc_82163FAC;
loc_82164020:
	// lwz r11,104(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 104);
	// cmplwi cr6,r11,19
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 19, ctx.xer);
	// bge cr6,0x82164060
	if (!ctx.cr6.lt) goto loc_82164060;
loc_8216402C:
	// lwz r11,104(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 104);
	// addi r10,r17,128
	ctx.r10.s64 = ctx.r17.s64 + 128;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r11,r9,r10
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r10.u32);
	// addi r8,r11,56
	ctx.r8.s64 = ctx.r11.s64 + 56;
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r19,r7,r29
	PPC_STORE_U16(ctx.r7.u32 + ctx.r29.u32, ctx.r19.u16);
	// lwz r11,104(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 104);
	// addi r6,r11,1
	ctx.r6.s64 = ctx.r11.s64 + 1;
	// rotlwi r5,r6,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// stw r6,104(r29)
	PPC_STORE_U32(ctx.r29.u32 + 104, ctx.r6.u32);
	// cmplwi cr6,r5,19
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 19, ctx.xer);
	// blt cr6,0x8216402c
	if (ctx.cr6.lt) goto loc_8216402C;
loc_82164060:
	// addi r11,r29,1328
	ctx.r11.s64 = ctx.r29.s64 + 1328;
	// li r10,7
	ctx.r10.s64 = 7;
	// stw r11,76(r29)
	PPC_STORE_U32(ctx.r29.u32 + 76, ctx.r11.u32);
	// addi r6,r29,108
	ctx.r6.s64 = ctx.r29.s64 + 108;
	// stw r11,108(r29)
	PPC_STORE_U32(ctx.r29.u32 + 108, ctx.r11.u32);
	// addi r7,r29,84
	ctx.r7.s64 = ctx.r29.s64 + 84;
	// stw r10,84(r29)
	PPC_STORE_U32(ctx.r29.u32 + 84, ctx.r10.u32);
	// addi r8,r29,752
	ctx.r8.s64 = ctx.r29.s64 + 752;
	// li r5,19
	ctx.r5.s64 = 19;
	// addi r4,r29,112
	ctx.r4.s64 = ctx.r29.s64 + 112;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82161b88
	ctx.lr = 0x82164090;
	sub_82161B88(ctx, base);
	// mr r15,r3
	ctx.r15.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x821640b4
	if (ctx.cr6.eq) goto loc_821640B4;
	// addi r11,r22,-244
	ctx.r11.s64 = ctx.r22.s64 + -244;
	// stw r11,24(r23)
	PPC_STORE_U32(ctx.r23.u32 + 24, ctx.r11.u32);
	// b 0x82164a6c
	goto loc_82164A6C;
loc_821640A8:
	// addi r11,r22,-280
	ctx.r11.s64 = ctx.r22.s64 + -280;
	// stw r11,24(r23)
	PPC_STORE_U32(ctx.r23.u32 + 24, ctx.r11.u32);
	// b 0x82164a6c
	goto loc_82164A6C;
loc_821640B4:
	// li r11,17
	ctx.r11.s64 = 17;
	// stw r19,104(r29)
	PPC_STORE_U32(ctx.r29.u32 + 104, ctx.r19.u32);
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
loc_821640C0:
	// lwz r11,100(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 100);
	// lwz r10,96(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 96);
	// lwz r9,104(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 104);
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x82164330
	if (!ctx.cr6.lt) goto loc_82164330;
loc_821640D8:
	// lwz r11,84(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 84);
	// lwz r10,76(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 76);
	// slw r11,r24,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r24.u32 << (ctx.r11.u8 & 0x3F));
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// and r8,r9,r30
	ctx.r8.u64 = ctx.r9.u64 & ctx.r30.u64;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r7,r10
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// lbz r11,81(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// ble cr6,0x82164150
	if (!ctx.cr6.gt) goto loc_82164150;
loc_82164104:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82164ac8
	if (ctx.cr6.eq) goto loc_82164AC8;
	// lbz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// addi r27,r27,-1
	ctx.r27.s64 = ctx.r27.s64 + -1;
	// lwz r9,84(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 84);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// slw r10,r11,r31
	ctx.r10.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r31.u8 & 0x3F));
	// lwz r8,76(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 76);
	// slw r11,r24,r9
	ctx.r11.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r24.u32 << (ctx.r9.u8 & 0x3F));
	// addi r7,r11,-1
	ctx.r7.s64 = ctx.r11.s64 + -1;
	// add r30,r10,r30
	ctx.r30.u64 = ctx.r10.u64 + ctx.r30.u64;
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// and r6,r7,r30
	ctx.r6.u64 = ctx.r7.u64 & ctx.r30.u64;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r5,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r8.u32);
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// lbz r11,81(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// bgt cr6,0x82164104
	if (ctx.cr6.gt) goto loc_82164104;
loc_82164150:
	// lhz r9,82(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 82);
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// bge cr6,0x821641b8
	if (!ctx.cr6.lt) goto loc_821641B8;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x82164190
	if (!ctx.cr6.lt) goto loc_82164190;
loc_82164168:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82164ac8
	if (ctx.cr6.eq) goto loc_82164AC8;
	// lbz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// addi r27,r27,-1
	ctx.r27.s64 = ctx.r27.s64 + -1;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// slw r10,r10,r31
	ctx.r10.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r31.u8 & 0x3F));
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// add r30,r10,r30
	ctx.r30.u64 = ctx.r10.u64 + ctx.r30.u64;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82164168
	if (ctx.cr6.lt) goto loc_82164168;
loc_82164190:
	// lwz r10,104(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 104);
	// srw r30,r30,r11
	ctx.r30.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r30.u32 >> (ctx.r11.u8 & 0x3F));
	// addi r10,r10,56
	ctx.r10.s64 = ctx.r10.s64 + 56;
	// subf r31,r11,r31
	ctx.r31.s64 = ctx.r31.s64 - ctx.r11.s64;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r9,r8,r29
	PPC_STORE_U16(ctx.r8.u32 + ctx.r29.u32, ctx.r9.u16);
	// lwz r11,104(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 104);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r7,104(r29)
	PPC_STORE_U32(ctx.r29.u32 + 104, ctx.r7.u32);
	// b 0x82164318
	goto loc_82164318;
loc_821641B8:
	// bne cr6,0x82164224
	if (!ctx.cr6.eq) goto loc_82164224;
	// addi r9,r11,2
	ctx.r9.s64 = ctx.r11.s64 + 2;
	// cmplw cr6,r31,r9
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x821641f0
	if (!ctx.cr6.lt) goto loc_821641F0;
loc_821641C8:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82164ac8
	if (ctx.cr6.eq) goto loc_82164AC8;
	// lbz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// addi r27,r27,-1
	ctx.r27.s64 = ctx.r27.s64 + -1;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// slw r10,r10,r31
	ctx.r10.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r31.u8 & 0x3F));
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// add r30,r10,r30
	ctx.r30.u64 = ctx.r10.u64 + ctx.r30.u64;
	// cmplw cr6,r31,r9
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x821641c8
	if (ctx.cr6.lt) goto loc_821641C8;
loc_821641F0:
	// lwz r10,104(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 104);
	// srw r30,r30,r11
	ctx.r30.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r30.u32 >> (ctx.r11.u8 & 0x3F));
	// subf r31,r11,r31
	ctx.r31.s64 = ctx.r31.s64 - ctx.r11.s64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82164384
	if (ctx.cr6.eq) goto loc_82164384;
	// addi r10,r10,55
	ctx.r10.s64 = ctx.r10.s64 + 55;
	// clrlwi r11,r30,30
	ctx.r11.u64 = ctx.r30.u32 & 0x3;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r11,3
	ctx.r11.s64 = ctx.r11.s64 + 3;
	// rlwinm r30,r30,30,2,31
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r31,r31,-2
	ctx.r31.s64 = ctx.r31.s64 + -2;
	// lhzx r10,r9,r29
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r29.u32);
	// b 0x821642cc
	goto loc_821642CC;
loc_82164224:
	// cmplwi cr6,r10,17
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 17, ctx.xer);
	// bne cr6,0x8216427c
	if (!ctx.cr6.eq) goto loc_8216427C;
	// addi r9,r11,3
	ctx.r9.s64 = ctx.r11.s64 + 3;
	// cmplw cr6,r31,r9
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x82164260
	if (!ctx.cr6.lt) goto loc_82164260;
loc_82164238:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82164ac8
	if (ctx.cr6.eq) goto loc_82164AC8;
	// lbz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// addi r27,r27,-1
	ctx.r27.s64 = ctx.r27.s64 + -1;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// slw r10,r10,r31
	ctx.r10.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r31.u8 & 0x3F));
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// add r30,r10,r30
	ctx.r30.u64 = ctx.r10.u64 + ctx.r30.u64;
	// cmplw cr6,r31,r9
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x82164238
	if (ctx.cr6.lt) goto loc_82164238;
loc_82164260:
	// srw r7,r30,r11
	ctx.r7.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r30.u32 >> (ctx.r11.u8 & 0x3F));
	// subf r9,r11,r31
	ctx.r9.s64 = ctx.r31.s64 - ctx.r11.s64;
	// clrlwi r8,r7,29
	ctx.r8.u64 = ctx.r7.u32 & 0x7;
	// rlwinm r30,r7,29,3,31
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 29) & 0x1FFFFFFF;
	// addi r11,r8,3
	ctx.r11.s64 = ctx.r8.s64 + 3;
	// addi r31,r9,-3
	ctx.r31.s64 = ctx.r9.s64 + -3;
	// b 0x821642c8
	goto loc_821642C8;
loc_8216427C:
	// addi r9,r11,7
	ctx.r9.s64 = ctx.r11.s64 + 7;
	// cmplw cr6,r31,r9
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x821642b0
	if (!ctx.cr6.lt) goto loc_821642B0;
loc_82164288:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82164ac8
	if (ctx.cr6.eq) goto loc_82164AC8;
	// lbz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// addi r27,r27,-1
	ctx.r27.s64 = ctx.r27.s64 + -1;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// slw r10,r10,r31
	ctx.r10.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r31.u8 & 0x3F));
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// add r30,r10,r30
	ctx.r30.u64 = ctx.r10.u64 + ctx.r30.u64;
	// cmplw cr6,r31,r9
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x82164288
	if (ctx.cr6.lt) goto loc_82164288;
loc_821642B0:
	// srw r7,r30,r11
	ctx.r7.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r30.u32 >> (ctx.r11.u8 & 0x3F));
	// subf r9,r11,r31
	ctx.r9.s64 = ctx.r31.s64 - ctx.r11.s64;
	// clrlwi r8,r7,25
	ctx.r8.u64 = ctx.r7.u32 & 0x7F;
	// rlwinm r30,r7,25,7,31
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 25) & 0x1FFFFFF;
	// addi r11,r8,11
	ctx.r11.s64 = ctx.r8.s64 + 11;
	// addi r31,r9,-7
	ctx.r31.s64 = ctx.r9.s64 + -7;
loc_821642C8:
	// mr r10,r19
	ctx.r10.u64 = ctx.r19.u64;
loc_821642CC:
	// lwz r7,96(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 96);
	// lwz r8,100(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 100);
	// lwz r9,104(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 104);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// add r7,r11,r9
	ctx.r7.u64 = ctx.r11.u64 + ctx.r9.u64;
	// cmplw cr6,r7,r8
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r8.u32, ctx.xer);
	// bgt cr6,0x82164390
	if (ctx.cr6.gt) goto loc_82164390;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82164318
	if (ctx.cr6.eq) goto loc_82164318;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_821642F8:
	// lwz r11,104(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 104);
	// addi r11,r11,56
	ctx.r11.s64 = ctx.r11.s64 + 56;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r10,r9,r29
	PPC_STORE_U16(ctx.r9.u32 + ctx.r29.u32, ctx.r10.u16);
	// lwz r11,104(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 104);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// stw r8,104(r29)
	PPC_STORE_U32(ctx.r29.u32 + 104, ctx.r8.u32);
	// bdnz 0x821642f8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821642F8;
loc_82164318:
	// lwz r11,100(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 100);
	// lwz r10,96(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 96);
	// lwz r9,104(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 104);
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x821640d8
	if (ctx.cr6.lt) goto loc_821640D8;
loc_82164330:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// cmpwi cr6,r11,27
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 27, ctx.xer);
	// beq cr6,0x82164a70
	if (ctx.cr6.eq) goto loc_82164A70;
	// addi r11,r29,1328
	ctx.r11.s64 = ctx.r29.s64 + 1328;
	// stw r14,84(r29)
	PPC_STORE_U32(ctx.r29.u32 + 84, ctx.r14.u32);
	// addi r26,r29,752
	ctx.r26.s64 = ctx.r29.s64 + 752;
	// lwz r5,96(r29)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r29.u32 + 96);
	// stw r11,76(r29)
	PPC_STORE_U32(ctx.r29.u32 + 76, ctx.r11.u32);
	// addi r6,r29,108
	ctx.r6.s64 = ctx.r29.s64 + 108;
	// stw r11,108(r29)
	PPC_STORE_U32(ctx.r29.u32 + 108, ctx.r11.u32);
	// addi r7,r29,84
	ctx.r7.s64 = ctx.r29.s64 + 84;
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// addi r4,r29,112
	ctx.r4.s64 = ctx.r29.s64 + 112;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82161b88
	ctx.lr = 0x8216436C;
	sub_82161B88(ctx, base);
	// mr r15,r3
	ctx.r15.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8216439c
	if (ctx.cr6.eq) goto loc_8216439C;
	// addi r11,r22,-160
	ctx.r11.s64 = ctx.r22.s64 + -160;
	// stw r11,24(r23)
	PPC_STORE_U32(ctx.r23.u32 + 24, ctx.r11.u32);
	// b 0x82164a6c
	goto loc_82164A6C;
loc_82164384:
	// addi r11,r22,-216
	ctx.r11.s64 = ctx.r22.s64 + -216;
	// stw r11,24(r23)
	PPC_STORE_U32(ctx.r23.u32 + 24, ctx.r11.u32);
	// b 0x82164a6c
	goto loc_82164A6C;
loc_82164390:
	// addi r11,r22,-188
	ctx.r11.s64 = ctx.r22.s64 + -188;
	// stw r11,24(r23)
	PPC_STORE_U32(ctx.r23.u32 + 24, ctx.r11.u32);
	// b 0x82164a6c
	goto loc_82164A6C;
loc_8216439C:
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// li r9,6
	ctx.r9.s64 = 6;
	// lwz r11,96(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 96);
	// addi r7,r29,88
	ctx.r7.s64 = ctx.r29.s64 + 88;
	// stw r9,88(r29)
	PPC_STORE_U32(ctx.r29.u32 + 88, ctx.r9.u32);
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// addi r4,r11,56
	ctx.r4.s64 = ctx.r11.s64 + 56;
	// lwz r5,100(r29)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r29.u32 + 100);
	// li r3,2
	ctx.r3.s64 = 2;
	// stw r10,80(r29)
	PPC_STORE_U32(ctx.r29.u32 + 80, ctx.r10.u32);
	// rlwinm r11,r4,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// add r4,r11,r29
	ctx.r4.u64 = ctx.r11.u64 + ctx.r29.u64;
	// bl 0x82161b88
	ctx.lr = 0x821643D0;
	sub_82161B88(ctx, base);
	// mr r15,r3
	ctx.r15.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x821643e8
	if (ctx.cr6.eq) goto loc_821643E8;
	// addi r11,r22,-132
	ctx.r11.s64 = ctx.r22.s64 + -132;
	// stw r11,24(r23)
	PPC_STORE_U32(ctx.r23.u32 + 24, ctx.r11.u32);
	// b 0x82164a6c
	goto loc_82164A6C;
loc_821643E8:
	// stw r25,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r25.u32);
loc_821643EC:
	// cmplwi cr6,r27,6
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 6, ctx.xer);
	// blt cr6,0x8216443c
	if (ctx.cr6.lt) goto loc_8216443C;
	// cmplwi cr6,r20,258
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 258, ctx.xer);
	// blt cr6,0x8216443c
	if (ctx.cr6.lt) goto loc_8216443C;
	// stw r18,12(r23)
	PPC_STORE_U32(ctx.r23.u32 + 12, ctx.r18.u32);
	// mr r4,r16
	ctx.r4.u64 = ctx.r16.u64;
	// stw r20,16(r23)
	PPC_STORE_U32(ctx.r23.u32 + 16, ctx.r20.u32);
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// stw r28,0(r23)
	PPC_STORE_U32(ctx.r23.u32 + 0, ctx.r28.u32);
	// stw r27,4(r23)
	PPC_STORE_U32(ctx.r23.u32 + 4, ctx.r27.u32);
	// stw r30,56(r29)
	PPC_STORE_U32(ctx.r29.u32 + 56, ctx.r30.u32);
	// stw r31,60(r29)
	PPC_STORE_U32(ctx.r29.u32 + 60, ctx.r31.u32);
	// bl 0x82162760
	ctx.lr = 0x82164420;
	sub_82162760(ctx, base);
	// lwz r18,12(r23)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r23.u32 + 12);
	// lwz r20,16(r23)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16);
	// lwz r28,0(r23)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r23.u32 + 0);
	// lwz r27,4(r23)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r23.u32 + 4);
	// lwz r30,56(r29)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r29.u32 + 56);
	// lwz r31,60(r29)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r29.u32 + 60);
	// b 0x82164a70
	goto loc_82164A70;
loc_8216443C:
	// lwz r11,84(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 84);
	// lwz r8,76(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 76);
	// slw r11,r24,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r24.u32 << (ctx.r11.u8 & 0x3F));
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// and r9,r10,r30
	ctx.r9.u64 = ctx.r10.u64 & ctx.r30.u64;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r7,r8
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lbz r11,81(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// ble cr6,0x821644b4
	if (!ctx.cr6.gt) goto loc_821644B4;
loc_82164468:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82164ac8
	if (ctx.cr6.eq) goto loc_82164AC8;
	// lbz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// addi r27,r27,-1
	ctx.r27.s64 = ctx.r27.s64 + -1;
	// lwz r9,84(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 84);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// slw r10,r11,r31
	ctx.r10.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r31.u8 & 0x3F));
	// lwz r7,76(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 76);
	// slw r11,r24,r9
	ctx.r11.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r24.u32 << (ctx.r9.u8 & 0x3F));
	// add r30,r10,r30
	ctx.r30.u64 = ctx.r10.u64 + ctx.r30.u64;
	// addi r6,r11,-1
	ctx.r6.s64 = ctx.r11.s64 + -1;
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// and r5,r6,r30
	ctx.r5.u64 = ctx.r6.u64 & ctx.r30.u64;
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r4,r7
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r7.u32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lbz r11,81(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// bgt cr6,0x82164468
	if (ctx.cr6.gt) goto loc_82164468;
loc_821644B4:
	// lbz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8216457c
	if (ctx.cr6.eq) goto loc_8216457C;
	// rlwinm r7,r9,0,24,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xF0;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x8216457c
	if (!ctx.cr6.eq) goto loc_8216457C;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// lhz r7,82(r1)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r1.u32 + 82);
	// slw r10,r24,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r24.u32 << (ctx.r9.u8 & 0x3F));
	// addi r6,r10,-1
	ctx.r6.s64 = ctx.r10.s64 + -1;
	// and r5,r6,r30
	ctx.r5.u64 = ctx.r6.u64 & ctx.r30.u64;
	// lbz r10,89(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 89);
	// srw r11,r5,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r5.u32 >> (ctx.r11.u8 & 0x3F));
	// add r3,r11,r7
	ctx.r3.u64 = ctx.r11.u64 + ctx.r7.u64;
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r8
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r8.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lbz r11,81(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplw cr6,r7,r31
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r31.u32, ctx.xer);
	// ble cr6,0x82164574
	if (!ctx.cr6.gt) goto loc_82164574;
	// lhz r8,90(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 90);
	// lbz r7,88(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 88);
loc_82164514:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82164ac8
	if (ctx.cr6.eq) goto loc_82164AC8;
	// clrlwi r11,r7,24
	ctx.r11.u64 = ctx.r7.u32 & 0xFF;
	// lbz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// lwz r6,76(r29)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + 76);
	// addi r27,r27,-1
	ctx.r27.s64 = ctx.r27.s64 + -1;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// slw r9,r9,r31
	ctx.r9.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r31.u8 & 0x3F));
	// slw r11,r24,r5
	ctx.r11.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r24.u32 << (ctx.r5.u8 & 0x3F));
	// addi r4,r11,-1
	ctx.r4.s64 = ctx.r11.s64 + -1;
	// add r30,r9,r30
	ctx.r30.u64 = ctx.r9.u64 + ctx.r30.u64;
	// clrlwi r9,r8,16
	ctx.r9.u64 = ctx.r8.u32 & 0xFFFF;
	// and r3,r4,r30
	ctx.r3.u64 = ctx.r4.u64 & ctx.r30.u64;
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// srw r11,r3,r10
	ctx.r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r3.u32 >> (ctx.r10.u8 & 0x3F));
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r9,r6
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r6.u32);
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// lbz r11,81(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplw cr6,r4,r31
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r31.u32, ctx.xer);
	// bgt cr6,0x82164514
	if (ctx.cr6.gt) goto loc_82164514;
loc_82164574:
	// srw r30,r30,r10
	ctx.r30.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r30.u32 >> (ctx.r10.u8 & 0x3F));
	// subf r31,r10,r31
	ctx.r31.s64 = ctx.r31.s64 - ctx.r10.s64;
loc_8216457C:
	// lhz r8,82(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 82);
	// srw r30,r30,r11
	ctx.r30.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r30.u32 >> (ctx.r11.u8 & 0x3F));
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// subf r31,r11,r31
	ctx.r31.s64 = ctx.r31.s64 - ctx.r11.s64;
	// stw r8,64(r29)
	PPC_STORE_U32(ctx.r29.u32 + 64, ctx.r8.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x821645a4
	if (!ctx.cr6.eq) goto loc_821645A4;
	// li r11,23
	ctx.r11.s64 = 23;
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// b 0x82164a70
	goto loc_82164A70;
loc_821645A4:
	// rlwinm r11,r10,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821645bc
	if (ctx.cr6.eq) goto loc_821645BC;
loc_821645B0:
	// li r11,11
	ctx.r11.s64 = 11;
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// b 0x82164a70
	goto loc_82164A70;
loc_821645BC:
	// rlwinm r11,r10,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821645d4
	if (ctx.cr6.eq) goto loc_821645D4;
	// addi r11,r22,-108
	ctx.r11.s64 = ctx.r22.s64 + -108;
	// stw r11,24(r23)
	PPC_STORE_U32(ctx.r23.u32 + 24, ctx.r11.u32);
	// b 0x82164a6c
	goto loc_82164A6C;
loc_821645D4:
	// clrlwi r11,r10,28
	ctx.r11.u64 = ctx.r10.u32 & 0xF;
	// li r10,19
	ctx.r10.s64 = 19;
	// stw r11,72(r29)
	PPC_STORE_U32(ctx.r29.u32 + 72, ctx.r11.u32);
	// stw r10,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r10.u32);
loc_821645E4:
	// lwz r10,72(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 72);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82164644
	if (ctx.cr6.eq) goto loc_82164644;
	// cmplw cr6,r31,r10
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x82164624
	if (!ctx.cr6.lt) goto loc_82164624;
loc_821645F8:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82164ac8
	if (ctx.cr6.eq) goto loc_82164AC8;
	// lbz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// addi r27,r27,-1
	ctx.r27.s64 = ctx.r27.s64 + -1;
	// lwz r9,72(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 72);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// slw r11,r11,r31
	ctx.r11.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r31.u8 & 0x3F));
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// cmplw cr6,r31,r9
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x821645f8
	if (ctx.cr6.lt) goto loc_821645F8;
loc_82164624:
	// slw r11,r24,r10
	ctx.r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r24.u32 << (ctx.r10.u8 & 0x3F));
	// lwz r9,64(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 64);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// subf r31,r10,r31
	ctx.r31.s64 = ctx.r31.s64 - ctx.r10.s64;
	// and r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 & ctx.r30.u64;
	// srw r30,r30,r10
	ctx.r30.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r30.u32 >> (ctx.r10.u8 & 0x3F));
	// add r10,r11,r9
	ctx.r10.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stw r10,64(r29)
	PPC_STORE_U32(ctx.r29.u32 + 64, ctx.r10.u32);
loc_82164644:
	// li r11,20
	ctx.r11.s64 = 20;
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
loc_8216464C:
	// lwz r11,88(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 88);
	// lwz r7,80(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 80);
	// slw r11,r24,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r24.u32 << (ctx.r11.u8 & 0x3F));
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// and r9,r10,r30
	ctx.r9.u64 = ctx.r10.u64 & ctx.r30.u64;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r8,r7
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lbz r11,81(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// ble cr6,0x821646c4
	if (!ctx.cr6.gt) goto loc_821646C4;
loc_82164678:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82164ac8
	if (ctx.cr6.eq) goto loc_82164AC8;
	// lbz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// addi r27,r27,-1
	ctx.r27.s64 = ctx.r27.s64 + -1;
	// lwz r9,88(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 88);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// slw r10,r11,r31
	ctx.r10.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r31.u8 & 0x3F));
	// lwz r8,80(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 80);
	// slw r11,r24,r9
	ctx.r11.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r24.u32 << (ctx.r9.u8 & 0x3F));
	// add r30,r10,r30
	ctx.r30.u64 = ctx.r10.u64 + ctx.r30.u64;
	// addi r6,r11,-1
	ctx.r6.s64 = ctx.r11.s64 + -1;
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// and r5,r6,r30
	ctx.r5.u64 = ctx.r6.u64 & ctx.r30.u64;
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r4,r8
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r8.u32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lbz r11,81(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// bgt cr6,0x82164678
	if (ctx.cr6.gt) goto loc_82164678;
loc_821646C4:
	// lbz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// rlwinm r6,r9,0,0,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFF0;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne cr6,0x82164790
	if (!ctx.cr6.eq) goto loc_82164790;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lhz r8,82(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 82);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// slw r9,r24,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r24.u32 << (ctx.r9.u8 & 0x3F));
	// addi r6,r9,-1
	ctx.r6.s64 = ctx.r9.s64 + -1;
	// and r5,r6,r30
	ctx.r5.u64 = ctx.r6.u64 & ctx.r30.u64;
	// lbz r4,89(r1)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r1.u32 + 89);
	// srw r11,r5,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r5.u32 >> (ctx.r11.u8 & 0x3F));
	// add r3,r11,r8
	ctx.r3.u64 = ctx.r11.u64 + ctx.r8.u64;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r7
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r7.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lbz r11,81(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// add r7,r4,r11
	ctx.r7.u64 = ctx.r4.u64 + ctx.r11.u64;
	// cmplw cr6,r7,r31
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r31.u32, ctx.xer);
	// ble cr6,0x82164784
	if (!ctx.cr6.gt) goto loc_82164784;
	// lhz r8,90(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 90);
	// lbz r7,88(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 88);
loc_82164724:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82164ac8
	if (ctx.cr6.eq) goto loc_82164AC8;
	// clrlwi r11,r7,24
	ctx.r11.u64 = ctx.r7.u32 & 0xFF;
	// lbz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// lwz r6,80(r29)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + 80);
	// addi r27,r27,-1
	ctx.r27.s64 = ctx.r27.s64 + -1;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// slw r9,r9,r31
	ctx.r9.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r31.u8 & 0x3F));
	// slw r11,r24,r5
	ctx.r11.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r24.u32 << (ctx.r5.u8 & 0x3F));
	// addi r4,r11,-1
	ctx.r4.s64 = ctx.r11.s64 + -1;
	// add r30,r9,r30
	ctx.r30.u64 = ctx.r9.u64 + ctx.r30.u64;
	// clrlwi r9,r8,16
	ctx.r9.u64 = ctx.r8.u32 & 0xFFFF;
	// and r3,r4,r30
	ctx.r3.u64 = ctx.r4.u64 & ctx.r30.u64;
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// srw r11,r3,r10
	ctx.r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r3.u32 >> (ctx.r10.u8 & 0x3F));
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r9,r6
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r6.u32);
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// lbz r11,81(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplw cr6,r4,r31
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r31.u32, ctx.xer);
	// bgt cr6,0x82164724
	if (ctx.cr6.gt) goto loc_82164724;
loc_82164784:
	// lbz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// srw r30,r30,r10
	ctx.r30.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r30.u32 >> (ctx.r10.u8 & 0x3F));
	// subf r31,r10,r31
	ctx.r31.s64 = ctx.r31.s64 - ctx.r10.s64;
loc_82164790:
	// rlwinm r10,r9,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x40;
	// srw r30,r30,r11
	ctx.r30.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r30.u32 >> (ctx.r11.u8 & 0x3F));
	// subf r31,r11,r31
	ctx.r31.s64 = ctx.r31.s64 - ctx.r11.s64;
	// clrlwi r11,r9,24
	ctx.r11.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821647b4
	if (ctx.cr6.eq) goto loc_821647B4;
	// addi r11,r22,-80
	ctx.r11.s64 = ctx.r22.s64 + -80;
	// stw r11,24(r23)
	PPC_STORE_U32(ctx.r23.u32 + 24, ctx.r11.u32);
	// b 0x82164a6c
	goto loc_82164A6C;
loc_821647B4:
	// lhz r7,82(r1)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r1.u32 + 82);
	// clrlwi r9,r11,28
	ctx.r9.u64 = ctx.r11.u32 & 0xF;
	// li r8,21
	ctx.r8.s64 = 21;
	// stw r9,72(r29)
	PPC_STORE_U32(ctx.r29.u32 + 72, ctx.r9.u32);
	// stw r8,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r8.u32);
	// stw r7,68(r29)
	PPC_STORE_U32(ctx.r29.u32 + 68, ctx.r7.u32);
loc_821647CC:
	// lwz r10,72(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 72);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8216482c
	if (ctx.cr6.eq) goto loc_8216482C;
	// cmplw cr6,r31,r10
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8216480c
	if (!ctx.cr6.lt) goto loc_8216480C;
loc_821647E0:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82164ac8
	if (ctx.cr6.eq) goto loc_82164AC8;
	// lbz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// addi r27,r27,-1
	ctx.r27.s64 = ctx.r27.s64 + -1;
	// lwz r9,72(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 72);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// slw r11,r11,r31
	ctx.r11.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r31.u8 & 0x3F));
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// cmplw cr6,r31,r9
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x821647e0
	if (ctx.cr6.lt) goto loc_821647E0;
loc_8216480C:
	// slw r11,r24,r10
	ctx.r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r24.u32 << (ctx.r10.u8 & 0x3F));
	// lwz r9,68(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 68);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// subf r31,r10,r31
	ctx.r31.s64 = ctx.r31.s64 - ctx.r10.s64;
	// and r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 & ctx.r30.u64;
	// srw r30,r30,r10
	ctx.r30.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r30.u32 >> (ctx.r10.u8 & 0x3F));
	// add r10,r11,r9
	ctx.r10.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stw r10,68(r29)
	PPC_STORE_U32(ctx.r29.u32 + 68, ctx.r10.u32);
loc_8216482C:
	// lwz r11,44(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 44);
	// lwz r10,68(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 68);
	// subf r11,r20,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r20.s64;
	// add r9,r11,r16
	ctx.r9.u64 = ctx.r11.u64 + ctx.r16.u64;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// ble cr6,0x82164850
	if (!ctx.cr6.gt) goto loc_82164850;
	// addi r11,r22,-56
	ctx.r11.s64 = ctx.r22.s64 + -56;
	// stw r11,24(r23)
	PPC_STORE_U32(ctx.r23.u32 + 24, ctx.r11.u32);
	// b 0x82164a6c
	goto loc_82164A6C;
loc_82164850:
	// li r11,22
	ctx.r11.s64 = 22;
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
loc_82164858:
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x82164ac8
	if (ctx.cr6.eq) goto loc_82164AC8;
	// lwz r11,68(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 68);
	// subf r9,r20,r16
	ctx.r9.s64 = ctx.r16.s64 - ctx.r20.s64;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// ble cr6,0x821648b0
	if (!ctx.cr6.gt) goto loc_821648B0;
	// lwz r10,48(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 48);
	// subf r11,r9,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r9.s64;
	// lwz r9,52(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 52);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x82164898
	if (!ctx.cr6.gt) goto loc_82164898;
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// lwz r10,40(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 40);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// b 0x821648a0
	goto loc_821648A0;
loc_82164898:
	// subf r9,r11,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r11.s64;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
loc_821648A0:
	// lwz r10,64(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 64);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x821648bc
	if (!ctx.cr6.gt) goto loc_821648BC;
	// b 0x821648b8
	goto loc_821648B8;
loc_821648B0:
	// lwz r10,64(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 64);
	// subf r9,r11,r18
	ctx.r9.s64 = ctx.r18.s64 - ctx.r11.s64;
loc_821648B8:
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_821648BC:
	// cmplw cr6,r11,r20
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r20.u32, ctx.xer);
	// ble cr6,0x821648c8
	if (!ctx.cr6.gt) goto loc_821648C8;
	// mr r11,r20
	ctx.r11.u64 = ctx.r20.u64;
loc_821648C8:
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r11.s64;
	// subf r20,r11,r20
	ctx.r20.s64 = ctx.r20.s64 - ctx.r11.s64;
	// stw r10,64(r29)
	PPC_STORE_U32(ctx.r29.u32 + 64, ctx.r10.u32);
	// addi r10,r9,-1
	ctx.r10.s64 = ctx.r9.s64 + -1;
loc_821648D8:
	// lbzu r9,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r9.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stb r9,0(r18)
	PPC_STORE_U8(ctx.r18.u32 + 0, ctx.r9.u8);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// bne 0x821648d8
	if (!ctx.cr0.eq) goto loc_821648D8;
	// lwz r11,64(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 64);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82164a70
	if (!ctx.cr6.eq) goto loc_82164A70;
	// stw r25,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r25.u32);
	// b 0x82164a70
	goto loc_82164A70;
loc_82164900:
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x82164ac8
	if (ctx.cr6.eq) goto loc_82164AC8;
	// lwz r11,64(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 64);
	// addi r20,r20,-1
	ctx.r20.s64 = ctx.r20.s64 + -1;
	// stb r11,0(r18)
	PPC_STORE_U8(ctx.r18.u32 + 0, ctx.r11.u8);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// stw r25,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r25.u32);
	// b 0x82164a70
	goto loc_82164A70;
loc_82164920:
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82164a0c
	if (ctx.cr6.eq) goto loc_82164A0C;
	// cmplwi cr6,r31,32
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 32, ctx.xer);
	// bge cr6,0x8216495c
	if (!ctx.cr6.lt) goto loc_8216495C;
loc_82164934:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82164ac8
	if (ctx.cr6.eq) goto loc_82164AC8;
	// lbz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// addi r27,r27,-1
	ctx.r27.s64 = ctx.r27.s64 + -1;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// slw r11,r11,r31
	ctx.r11.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r31.u8 & 0x3F));
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// cmplwi cr6,r31,32
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 32, ctx.xer);
	// blt cr6,0x82164934
	if (ctx.cr6.lt) goto loc_82164934;
loc_8216495C:
	// lwz r10,20(r23)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r23.u32 + 20);
	// subf. r5,r20,r16
	ctx.r5.s64 = ctx.r16.s64 - ctx.r20.s64;
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// lwz r11,28(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 28);
	// add r10,r10,r5
	ctx.r10.u64 = ctx.r10.u64 + ctx.r5.u64;
	// add r9,r11,r5
	ctx.r9.u64 = ctx.r11.u64 + ctx.r5.u64;
	// stw r10,20(r23)
	PPC_STORE_U32(ctx.r23.u32 + 20, ctx.r10.u32);
	// stw r9,28(r29)
	PPC_STORE_U32(ctx.r29.u32 + 28, ctx.r9.u32);
	// beq 0x821649b4
	if (ctx.cr0.eq) goto loc_821649B4;
	// lwz r11,16(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x821649a4
	if (ctx.cr6.eq) goto loc_821649A4;
	// subf. r4,r5,r18
	ctx.r4.s64 = ctx.r18.s64 - ctx.r5.s64;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne 0x8216499c
	if (!ctx.cr0.eq) goto loc_8216499C;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// b 0x821649ac
	goto loc_821649AC;
loc_8216499C:
	// bl 0x821620d8
	ctx.lr = 0x821649A0;
	sub_821620D8(ctx, base);
	// b 0x821649ac
	goto loc_821649AC;
loc_821649A4:
	// subf r4,r5,r18
	ctx.r4.s64 = ctx.r18.s64 - ctx.r5.s64;
	// bl 0x82162bb8
	ctx.lr = 0x821649AC;
	sub_82162BB8(ctx, base);
loc_821649AC:
	// stw r3,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r3.u32);
	// stw r3,48(r23)
	PPC_STORE_U32(ctx.r23.u32 + 48, ctx.r3.u32);
loc_821649B4:
	// lwz r11,16(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// mr r16,r20
	ctx.r16.u64 = ctx.r20.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x821649cc
	if (ctx.cr6.eq) goto loc_821649CC;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// b 0x821649ec
	goto loc_821649EC;
loc_821649CC:
	// rlwinm r10,r30,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r30,0,16,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0xFF00;
	// rlwinm r9,r30,24,16,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 24) & 0xFF00;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r10,r30,8,24,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 8) & 0xFF;
	// rlwinm r11,r11,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
loc_821649EC:
	// lwz r10,24(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x82164a04
	if (ctx.cr6.eq) goto loc_82164A04;
	// addi r11,r22,-24
	ctx.r11.s64 = ctx.r22.s64 + -24;
	// stw r11,24(r23)
	PPC_STORE_U32(ctx.r23.u32 + 24, ctx.r11.u32);
	// b 0x82164a6c
	goto loc_82164A6C;
loc_82164A04:
	// mr r30,r19
	ctx.r30.u64 = ctx.r19.u64;
	// mr r31,r19
	ctx.r31.u64 = ctx.r19.u64;
loc_82164A0C:
	// li r11,25
	ctx.r11.s64 = 25;
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
loc_82164A14:
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82164ab4
	if (ctx.cr6.eq) goto loc_82164AB4;
	// lwz r11,16(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82164ab4
	if (ctx.cr6.eq) goto loc_82164AB4;
	// cmplwi cr6,r31,32
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 32, ctx.xer);
	// bge cr6,0x82164a5c
	if (!ctx.cr6.lt) goto loc_82164A5C;
loc_82164A34:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82164ac8
	if (ctx.cr6.eq) goto loc_82164AC8;
	// lbz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// addi r27,r27,-1
	ctx.r27.s64 = ctx.r27.s64 + -1;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// slw r11,r11,r31
	ctx.r11.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r31.u8 & 0x3F));
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// cmplwi cr6,r31,32
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 32, ctx.xer);
	// blt cr6,0x82164a34
	if (ctx.cr6.lt) goto loc_82164A34;
loc_82164A5C:
	// lwz r11,28(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 28);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82164aac
	if (ctx.cr6.eq) goto loc_82164AAC;
	// stw r22,24(r23)
	PPC_STORE_U32(ctx.r23.u32 + 24, ctx.r22.u32);
loc_82164A6C:
	// stw r21,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r21.u32);
loc_82164A70:
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r9,28
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 28, ctx.xer);
	// ble cr6,0x82163514
	if (!ctx.cr6.gt) goto loc_82163514;
loc_82164A7C:
	// li r3,-2
	ctx.r3.s64 = -2;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x8207c9a0
	__restgprlr_14(ctx, base);
	return;
loc_82164A88:
	// stw r18,12(r23)
	PPC_STORE_U32(ctx.r23.u32 + 12, ctx.r18.u32);
	// li r3,2
	ctx.r3.s64 = 2;
	// stw r20,16(r23)
	PPC_STORE_U32(ctx.r23.u32 + 16, ctx.r20.u32);
	// stw r28,0(r23)
	PPC_STORE_U32(ctx.r23.u32 + 0, ctx.r28.u32);
	// stw r27,4(r23)
	PPC_STORE_U32(ctx.r23.u32 + 4, ctx.r27.u32);
	// stw r30,56(r29)
	PPC_STORE_U32(ctx.r29.u32 + 56, ctx.r30.u32);
	// stw r31,60(r29)
	PPC_STORE_U32(ctx.r29.u32 + 60, ctx.r31.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x8207c9a0
	__restgprlr_14(ctx, base);
	return;
loc_82164AAC:
	// mr r30,r19
	ctx.r30.u64 = ctx.r19.u64;
	// mr r31,r19
	ctx.r31.u64 = ctx.r19.u64;
loc_82164AB4:
	// li r11,26
	ctx.r11.s64 = 26;
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
loc_82164ABC:
	// mr r15,r24
	ctx.r15.u64 = ctx.r24.u64;
	// b 0x82164ac8
	goto loc_82164AC8;
loc_82164AC4:
	// li r15,-3
	ctx.r15.s64 = -3;
loc_82164AC8:
	// lwz r11,40(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 40);
	// stw r18,12(r23)
	PPC_STORE_U32(ctx.r23.u32 + 12, ctx.r18.u32);
	// stw r20,16(r23)
	PPC_STORE_U32(ctx.r23.u32 + 16, ctx.r20.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r28,0(r23)
	PPC_STORE_U32(ctx.r23.u32 + 0, ctx.r28.u32);
	// stw r27,4(r23)
	PPC_STORE_U32(ctx.r23.u32 + 4, ctx.r27.u32);
	// stw r30,56(r29)
	PPC_STORE_U32(ctx.r29.u32 + 56, ctx.r30.u32);
	// stw r31,60(r29)
	PPC_STORE_U32(ctx.r29.u32 + 60, ctx.r31.u32);
	// bne cr6,0x82164b00
	if (!ctx.cr6.eq) goto loc_82164B00;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// cmpwi cr6,r11,24
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 24, ctx.xer);
	// bge cr6,0x82164b28
	if (!ctx.cr6.lt) goto loc_82164B28;
	// cmplw cr6,r16,r20
	ctx.cr6.compare<uint32_t>(ctx.r16.u32, ctx.r20.u32, ctx.xer);
	// beq cr6,0x82164b28
	if (ctx.cr6.eq) goto loc_82164B28;
loc_82164B00:
	// mr r4,r16
	ctx.r4.u64 = ctx.r16.u64;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x82163270
	ctx.lr = 0x82164B0C;
	sub_82163270(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x82164b28
	if (ctx.cr6.eq) goto loc_82164B28;
	// li r11,28
	ctx.r11.s64 = 28;
	// li r3,-4
	ctx.r3.s64 = -4;
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x8207c9a0
	__restgprlr_14(ctx, base);
	return;
loc_82164B28:
	// lwz r10,4(r23)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r23.u32 + 4);
	// lwz r9,92(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r11,8(r23)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + 8);
	// subf r10,r10,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r10.s64;
	// lwz r8,16(r23)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16);
	// lwz r7,8(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,20(r23)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r23.u32 + 20);
	// lwz r11,28(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 28);
	// subf r5,r8,r16
	ctx.r5.s64 = ctx.r16.s64 - ctx.r8.s64;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stw r6,8(r23)
	PPC_STORE_U32(ctx.r23.u32 + 8, ctx.r6.u32);
	// add r4,r10,r5
	ctx.r4.u64 = ctx.r10.u64 + ctx.r5.u64;
	// add r3,r11,r5
	ctx.r3.u64 = ctx.r11.u64 + ctx.r5.u64;
	// stw r4,20(r23)
	PPC_STORE_U32(ctx.r23.u32 + 20, ctx.r4.u32);
	// stw r3,28(r29)
	PPC_STORE_U32(ctx.r29.u32 + 28, ctx.r3.u32);
	// beq cr6,0x82164bb0
	if (ctx.cr6.eq) goto loc_82164BB0;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82164bb0
	if (ctx.cr6.eq) goto loc_82164BB0;
	// lwz r11,16(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r11,12(r23)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + 12);
	// beq cr6,0x82164ba0
	if (ctx.cr6.eq) goto loc_82164BA0;
	// subf. r4,r5,r11
	ctx.r4.s64 = ctx.r11.s64 - ctx.r5.s64;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne 0x82164b98
	if (!ctx.cr0.eq) goto loc_82164B98;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// b 0x82164ba8
	goto loc_82164BA8;
loc_82164B98:
	// bl 0x821620d8
	ctx.lr = 0x82164B9C;
	sub_821620D8(ctx, base);
	// b 0x82164ba8
	goto loc_82164BA8;
loc_82164BA0:
	// subf r4,r5,r11
	ctx.r4.s64 = ctx.r11.s64 - ctx.r5.s64;
	// bl 0x82162bb8
	ctx.lr = 0x82164BA8;
	sub_82162BB8(ctx, base);
loc_82164BA8:
	// stw r3,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r3.u32);
	// stw r3,48(r23)
	PPC_STORE_U32(ctx.r23.u32 + 48, ctx.r3.u32);
loc_82164BB0:
	// lwz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// li r9,64
	ctx.r9.s64 = 64;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// li r8,128
	ctx.r8.s64 = 128;
	// subfic r7,r10,0
	ctx.xer.ca = ctx.r10.u32 <= 0;
	ctx.r7.s64 = 0 - ctx.r10.s64;
	// lwz r10,60(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 60);
	// addi r5,r11,-11
	ctx.r5.s64 = ctx.r11.s64 + -11;
	// subfe r4,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r4.u64 = ~ctx.r6.u64 + ctx.r6.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// addic r3,r5,-1
	ctx.xer.ca = ctx.r5.u32 > 0;
	ctx.r3.s64 = ctx.r5.s64 + -1;
	// and r11,r4,r9
	ctx.r11.u64 = ctx.r4.u64 & ctx.r9.u64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// cmpwi cr6,r15,0
	ctx.cr6.compare<int32_t>(ctx.r15.s32, 0, ctx.xer);
	// and r9,r6,r8
	ctx.r9.u64 = ctx.r6.u64 & ctx.r8.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r5,44(r23)
	PPC_STORE_U32(ctx.r23.u32 + 44, ctx.r5.u32);
	// bne cr6,0x82164bf8
	if (!ctx.cr6.eq) goto loc_82164BF8;
	// li r15,-5
	ctx.r15.s64 = -5;
loc_82164BF8:
	// mr r3,r15
	ctx.r3.u64 = ctx.r15.u64;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x8207c9a0
	__restgprlr_14(ctx, base);
	return;
loc_82164C04:
	// li r3,-4
	ctx.r3.s64 = -4;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x8207c9a0
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82164C10"))) PPC_WEAK_FUNC(sub_82164C10);
PPC_FUNC_IMPL(__imp__sub_82164C10) {
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
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r11,-14036
	ctx.r10.s64 = ctx.r11.s64 + -14036;
	// lbz r11,-14036(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + -14036);
	// lbz r10,-528(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + -528);
	// extsb r9,r11
	ctx.r9.s64 = ctx.r11.s8;
	// extsb r8,r10
	ctx.r8.s64 = ctx.r10.s8;
	// cmpw cr6,r9,r8
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, ctx.xer);
	// bne cr6,0x82164ce4
	if (!ctx.cr6.eq) goto loc_82164CE4;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82164c58
	if (!ctx.cr6.eq) goto loc_82164C58;
	// li r3,-2
	ctx.r3.s64 = -2;
	// b 0x82164ce8
	goto loc_82164CE8;
loc_82164C58:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r30,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r30.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82164c7c
	if (!ctx.cr6.eq) goto loc_82164C7C;
	// lis r11,-32234
	ctx.r11.s64 = -2112487424;
	// stw r30,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r30.u32);
	// addi r10,r11,8400
	ctx.r10.s64 = ctx.r11.s64 + 8400;
	// stw r10,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r10.u32);
loc_82164C7C:
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82164c94
	if (!ctx.cr6.eq) goto loc_82164C94;
	// lis r11,-32234
	ctx.r11.s64 = -2112487424;
	// addi r10,r11,8392
	ctx.r10.s64 = ctx.r11.s64 + 8392;
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
loc_82164C94:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r5,9520
	ctx.r5.s64 = 9520;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82164CAC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82164cc0
	if (!ctx.cr6.eq) goto loc_82164CC0;
	// li r3,-4
	ctx.r3.s64 = -4;
	// b 0x82164ce8
	goto loc_82164CE8;
loc_82164CC0:
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// li r9,15
	ctx.r9.s64 = 15;
	// stw r30,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r30.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r9.u32);
	// bl 0x821633e8
	ctx.lr = 0x82164CE0;
	sub_821633E8(ctx, base);
	// b 0x82164ce8
	goto loc_82164CE8;
loc_82164CE4:
	// li r3,-6
	ctx.r3.s64 = -6;
loc_82164CE8:
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

__attribute__((alias("__imp__sub_82164D00"))) PPC_WEAK_FUNC(sub_82164D00);
PPC_FUNC_IMPL(__imp__sub_82164D00) {
	PPC_FUNC_PROLOGUE();
	// b 0x82164c10
	sub_82164C10(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82164D04"))) PPC_WEAK_FUNC(sub_82164D04);
PPC_FUNC_IMPL(__imp__sub_82164D04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82164D08"))) PPC_WEAK_FUNC(sub_82164D08);
PPC_FUNC_IMPL(__imp__sub_82164D08) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8208a4b8
	ctx.lr = 0x82164D28;
	sub_8208A4B8(ctx, base);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lfd f0,-2064(r11)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r11.u32 + -2064);
	// fmul f31,f12,f0
	ctx.f31.f64 = ctx.f12.f64 * ctx.f0.f64;
	// bl 0x8208a498
	ctx.lr = 0x82164D44;
	sub_8208A498(ctx, base);
	// lfd f11,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// fdiv f9,f10,f31
	ctx.f9.f64 = ctx.f10.f64 / ctx.f31.f64;
	// fctidz f8,f9
	ctx.f8.s64 = (ctx.f9.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f8,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f8.u64);
	// lhz r10,94(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 94);
	// sth r10,0(r31)
	PPC_STORE_U16(ctx.r31.u32 + 0, ctx.r10.u16);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f31,-24(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82164D78"))) PPC_WEAK_FUNC(sub_82164D78);
PPC_FUNC_IMPL(__imp__sub_82164D78) {
	PPC_FUNC_PROLOGUE();
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82164D80"))) PPC_WEAK_FUNC(sub_82164D80);
PPC_FUNC_IMPL(__imp__sub_82164D80) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82164D84"))) PPC_WEAK_FUNC(sub_82164D84);
PPC_FUNC_IMPL(__imp__sub_82164D84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82164D88"))) PPC_WEAK_FUNC(sub_82164D88);
PPC_FUNC_IMPL(__imp__sub_82164D88) {
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
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82164DAC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_82164DC8"))) PPC_WEAK_FUNC(sub_82164DC8);
PPC_FUNC_IMPL(__imp__sub_82164DC8) {
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
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82164DEC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_82164E08"))) PPC_WEAK_FUNC(sub_82164E08);
PPC_FUNC_IMPL(__imp__sub_82164E08) {
	PPC_FUNC_PROLOGUE();
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,25(r3)
	PPC_STORE_U8(ctx.r3.u32 + 25, ctx.r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82164E14"))) PPC_WEAK_FUNC(sub_82164E14);
PPC_FUNC_IMPL(__imp__sub_82164E14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82164E18"))) PPC_WEAK_FUNC(sub_82164E18);
PPC_FUNC_IMPL(__imp__sub_82164E18) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r10,r11,-1456
	ctx.r10.s64 = ctx.r11.s64 + -1456;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82164E28"))) PPC_WEAK_FUNC(sub_82164E28);
PPC_FUNC_IMPL(__imp__sub_82164E28) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r4,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r4.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r9,r10,6352
	ctx.r9.s64 = ctx.r10.s64 + 6352;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r11.u8);
	// stb r11,24(r3)
	PPC_STORE_U8(ctx.r3.u32 + 24, ctx.r11.u8);
	// stb r11,25(r3)
	PPC_STORE_U8(ctx.r3.u32 + 25, ctx.r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82164E50"))) PPC_WEAK_FUNC(sub_82164E50);
PPC_FUNC_IMPL(__imp__sub_82164E50) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82164E54"))) PPC_WEAK_FUNC(sub_82164E54);
PPC_FUNC_IMPL(__imp__sub_82164E54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82164E58"))) PPC_WEAK_FUNC(sub_82164E58);
PPC_FUNC_IMPL(__imp__sub_82164E58) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82164E5C"))) PPC_WEAK_FUNC(sub_82164E5C);
PPC_FUNC_IMPL(__imp__sub_82164E5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82164E60"))) PPC_WEAK_FUNC(sub_82164E60);
PPC_FUNC_IMPL(__imp__sub_82164E60) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82164E64"))) PPC_WEAK_FUNC(sub_82164E64);
PPC_FUNC_IMPL(__imp__sub_82164E64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82164E68"))) PPC_WEAK_FUNC(sub_82164E68);
PPC_FUNC_IMPL(__imp__sub_82164E68) {
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
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// std r4,248(r1)
	PPC_STORE_U64(ctx.r1.u32 + 248, ctx.r4.u64);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8216f838
	ctx.lr = 0x82164E90;
	sub_8216F838(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82164fe0
	if (ctx.cr6.eq) goto loc_82164FE0;
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r9,52(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r11.s64;
	// srawi r7,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 2;
	// cmplw cr6,r10,r7
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, ctx.xer);
	// blt cr6,0x82164ebc
	if (ctx.cr6.lt) goto loc_82164EBC;
	// twi 31,r0,22
loc_82164EBC:
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r7,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r7.u32);
	// lfs f10,16(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	ctx.f10.f64 = double(temp.f32);
	// lfs f0,248(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 248);
	ctx.f0.f64 = double(temp.f32);
	// lis r6,-32224
	ctx.r6.s64 = -2111832064;
	// lfs f13,252(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 252);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lfs f12,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f12.f64 = double(temp.f32);
	// lwzx r8,r8,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
	// lfs f11,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// lfs f9,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f9.f64 = double(temp.f32);
	// fmadds f7,f10,f12,f0
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f12.f64 + ctx.f0.f64));
	// lfs f8,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f6,f10,f11,f13
	ctx.f6.f64 = double(float(ctx.f10.f64 * ctx.f11.f64 + ctx.f13.f64));
	// stfs f9,144(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f8,148(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lwz r11,16(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// stfs f12,136(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f11,140(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f13,168(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f7,164(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// lwz r11,-31312(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31312);
	// stfs f7,176(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f6,180(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f6,192(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// lbz r10,83(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 83);
	// lbz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lbz r3,81(r1)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// lbz r7,82(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// rlwimi r5,r10,8,16,23
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r10.u32, 8) & 0xFF00) | (ctx.r5.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lbz r31,83(r1)
	ctx.r31.u64 = PPC_LOAD_U8(ctx.r1.u32 + 83);
	// clrlwi r5,r5,16
	ctx.r5.u64 = ctx.r5.u32 & 0xFFFF;
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// rlwimi r10,r31,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r31.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// lbz r31,82(r1)
	ctx.r31.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// rlwimi r3,r5,8,0,23
	ctx.r3.u64 = (__builtin_rotateleft32(ctx.r5.u32, 8) & 0xFFFFFF00) | (ctx.r3.u64 & 0xFFFFFFFF000000FF);
	// lbz r5,81(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// rlwimi r5,r10,8,0,23
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r10.u32, 8) & 0xFFFFFF00) | (ctx.r5.u64 & 0xFFFFFFFF000000FF);
	// lbz r10,81(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// rlwimi r7,r3,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r3.u32, 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// lbz r30,83(r1)
	ctx.r30.u64 = PPC_LOAD_U8(ctx.r1.u32 + 83);
	// rlwimi r31,r5,8,0,23
	ctx.r31.u64 = (__builtin_rotateleft32(ctx.r5.u32, 8) & 0xFFFFFF00) | (ctx.r31.u64 & 0xFFFFFFFF000000FF);
	// lbz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// rlwimi r3,r30,8,16,23
	ctx.r3.u64 = (__builtin_rotateleft32(ctx.r30.u32, 8) & 0xFF00) | (ctx.r3.u64 & 0xFFFFFFFFFFFF00FF);
	// lbz r30,82(r1)
	ctx.r30.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// clrlwi r3,r3,16
	ctx.r3.u64 = ctx.r3.u32 & 0xFFFF;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lbz r9,81(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// rlwimi r10,r3,8,0,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r3.u32, 8) & 0xFFFFFF00) | (ctx.r10.u64 & 0xFFFFFFFF000000FF);
	// lbz r5,82(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// rlwimi r30,r10,8,0,23
	ctx.r30.u64 = (__builtin_rotateleft32(ctx.r10.u32, 8) & 0xFFFFFF00) | (ctx.r30.u64 & 0xFFFFFFFF000000FF);
	// lbz r10,83(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 83);
	// lbz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// rlwimi r3,r10,8,16,23
	ctx.r3.u64 = (__builtin_rotateleft32(ctx.r10.u32, 8) & 0xFF00) | (ctx.r3.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r3,r3,16
	ctx.r3.u64 = ctx.r3.u32 & 0xFFFF;
	// stw r7,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r7.u32);
	// stw r31,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r31.u32);
	// rlwimi r9,r3,8,0,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r3.u32, 8) & 0xFFFFFF00) | (ctx.r9.u64 & 0xFFFFFFFF000000FF);
	// stw r30,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r30.u32);
	// lwz r3,156(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 156);
	// rlwimi r5,r9,8,0,23
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r9.u32, 8) & 0xFFFFFF00) | (ctx.r5.u64 & 0xFFFFFFFF000000FF);
	// stw r5,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, ctx.r5.u32);
	// bl 0x8216daa0
	ctx.lr = 0x82164FE0;
	sub_8216DAA0(ctx, base);
loc_82164FE0:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
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

__attribute__((alias("__imp__sub_82164FF8"))) PPC_WEAK_FUNC(sub_82164FF8);
PPC_FUNC_IMPL(__imp__sub_82164FF8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82164FFC"))) PPC_WEAK_FUNC(sub_82164FFC);
PPC_FUNC_IMPL(__imp__sub_82164FFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82165000"))) PPC_WEAK_FUNC(sub_82165000);
PPC_FUNC_IMPL(__imp__sub_82165000) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
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
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,-31324(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31324);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82165028
	if (ctx.cr6.eq) goto loc_82165028;
	// bl 0x8216ea68
	ctx.lr = 0x82165028;
	sub_8216EA68(ctx, base);
loc_82165028:
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lwz r11,152(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 152);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// stw r11,-31296(r9)
	PPC_STORE_U32(ctx.r9.u32 + -31296, ctx.r11.u32);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// stfs f12,12(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r31.u32 + 12, temp.u32);
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

__attribute__((alias("__imp__sub_82165060"))) PPC_WEAK_FUNC(sub_82165060);
PPC_FUNC_IMPL(__imp__sub_82165060) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82165064"))) PPC_WEAK_FUNC(sub_82165064);
PPC_FUNC_IMPL(__imp__sub_82165064) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82165068"))) PPC_WEAK_FUNC(sub_82165068);
PPC_FUNC_IMPL(__imp__sub_82165068) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216506C"))) PPC_WEAK_FUNC(sub_8216506C);
PPC_FUNC_IMPL(__imp__sub_8216506C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82165070"))) PPC_WEAK_FUNC(sub_82165070);
PPC_FUNC_IMPL(__imp__sub_82165070) {
	PPC_FUNC_PROLOGUE();
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82165078"))) PPC_WEAK_FUNC(sub_82165078);
PPC_FUNC_IMPL(__imp__sub_82165078) {
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
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8216509C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
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

__attribute__((alias("__imp__sub_821650B4"))) PPC_WEAK_FUNC(sub_821650B4);
PPC_FUNC_IMPL(__imp__sub_821650B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821650B8"))) PPC_WEAK_FUNC(sub_821650B8);
PPC_FUNC_IMPL(__imp__sub_821650B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,12(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821650C0"))) PPC_WEAK_FUNC(sub_821650C0);
PPC_FUNC_IMPL(__imp__sub_821650C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r10,88(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 88);
	// lfs f0,12(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// std r10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r10.u64);
	// lfd f13,-16(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f10,f0,f11
	ctx.f10.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// stfs f10,0(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// fmuls f9,f0,f11
	ctx.f9.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// stfs f9,4(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821650EC"))) PPC_WEAK_FUNC(sub_821650EC);
PPC_FUNC_IMPL(__imp__sub_821650EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821650F0"))) PPC_WEAK_FUNC(sub_821650F0);
PPC_FUNC_IMPL(__imp__sub_821650F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x821650F8;
	__savegprlr_27(ctx, base);
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// li r8,-1
	ctx.r8.s64 = -1;
	// addi r7,r9,6316
	ctx.r7.s64 = ctx.r9.s64 + 6316;
	// lfs f0,21768(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// lfs f31,-21836(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -21836);
	ctx.f31.f64 = double(temp.f32);
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// stfs f0,4(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stfs f31,12(r28)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 12, temp.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// addi r31,r28,16
	ctx.r31.s64 = ctx.r28.s64 + 16;
	// bl 0x82079fd8
	ctx.lr = 0x8216513C;
	sub_82079FD8(ctx, base);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82165150
	if (ctx.cr6.eq) goto loc_82165150;
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r31.u32);
	// b 0x82165154
	goto loc_82165154;
loc_82165150:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_82165154:
	// stw r3,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x82079fd8
	ctx.lr = 0x82165160;
	sub_82079FD8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82165170
	if (ctx.cr6.eq) goto loc_82165170;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
loc_82165170:
	// addic. r10,r11,4
	ctx.xer.ca = ctx.r11.u32 > 4294967291;
	ctx.r10.s64 = ctx.r11.s64 + 4;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8216517c
	if (ctx.cr0.eq) goto loc_8216517C;
	// stw r29,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r29.u32);
loc_8216517C:
	// addic. r10,r11,8
	ctx.xer.ca = ctx.r11.u32 > 4294967287;
	ctx.r10.s64 = ctx.r11.s64 + 8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82165188
	if (ctx.cr0.eq) goto loc_82165188;
	// stw r29,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r29.u32);
loc_82165188:
	// li r27,1
	ctx.r27.s64 = 1;
	// stb r29,21(r11)
	PPC_STORE_U8(ctx.r11.u32 + 21, ctx.r29.u8);
	// li r3,4
	ctx.r3.s64 = 4;
	// stb r27,20(r11)
	PPC_STORE_U8(ctx.r11.u32 + 20, ctx.r27.u8);
	// addi r30,r28,52
	ctx.r30.s64 = ctx.r28.s64 + 52;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// stb r27,21(r11)
	PPC_STORE_U8(ctx.r11.u32 + 21, ctx.r27.u8);
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// stw r11,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// stw r10,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r10.u32);
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// stw r9,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r9.u32);
	// stw r29,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r29.u32);
	// bl 0x82079fd8
	ctx.lr = 0x821651C4;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821651d4
	if (ctx.cr6.eq) goto loc_821651D4;
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// b 0x821651d8
	goto loc_821651D8;
loc_821651D4:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_821651D8:
	// stw r3,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r3.u32);
	// li r3,36
	ctx.r3.s64 = 36;
	// bl 0x82079fd8
	ctx.lr = 0x821651E4;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821651f0
	if (ctx.cr6.eq) goto loc_821651F0;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
loc_821651F0:
	// addic. r11,r3,4
	ctx.xer.ca = ctx.r3.u32 > 4294967291;
	ctx.r11.s64 = ctx.r3.s64 + 4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x821651fc
	if (ctx.cr0.eq) goto loc_821651FC;
	// stw r29,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r29.u32);
loc_821651FC:
	// addic. r11,r3,8
	ctx.xer.ca = ctx.r3.u32 > 4294967287;
	ctx.r11.s64 = ctx.r3.s64 + 8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82165208
	if (ctx.cr0.eq) goto loc_82165208;
	// stw r29,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r29.u32);
loc_82165208:
	// stb r27,32(r3)
	PPC_STORE_U8(ctx.r3.u32 + 32, ctx.r27.u8);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// stb r29,33(r3)
	PPC_STORE_U8(ctx.r3.u32 + 33, ctx.r29.u8);
	// li r10,88
	ctx.r10.s64 = 88;
	// stw r3,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r3.u32);
	// addi r9,r11,-2064
	ctx.r9.s64 = ctx.r11.s64 + -2064;
	// stb r27,33(r3)
	PPC_STORE_U8(ctx.r3.u32 + 33, ctx.r27.u8);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lfs f0,224(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 224);
	ctx.f0.f64 = double(temp.f32);
	// lwz r8,24(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// stw r8,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r8.u32);
	// lwz r7,24(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// stw r7,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r7.u32);
	// lwz r6,24(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// stw r6,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r6.u32);
	// stw r29,28(r30)
	PPC_STORE_U32(ctx.r30.u32 + 28, ctx.r29.u32);
	// lfs f13,12(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f31,12(r28)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 12, temp.u32);
	// fctidz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stw r29,84(r28)
	PPC_STORE_U32(ctx.r28.u32 + 84, ctx.r29.u32);
	// stfiwx f11,r28,r10
	PPC_STORE_U32(ctx.r28.u32 + ctx.r10.u32, ctx.f11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216526C"))) PPC_WEAK_FUNC(sub_8216526C);
PPC_FUNC_IMPL(__imp__sub_8216526C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82165270"))) PPC_WEAK_FUNC(sub_82165270);
PPC_FUNC_IMPL(__imp__sub_82165270) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x82165278;
	__savegprlr_26(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r26,0
	ctx.r26.s64 = 0;
	// li r10,15
	ctx.r10.s64 = 15;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r26,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r26.u32);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// stw r10,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r10.u32);
	// stb r26,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, ctx.r26.u8);
loc_82165298:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82165298
	if (!ctx.cr6.eq) goto loc_82165298;
	// subf r11,r4,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r4.s64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x82060368
	ctx.lr = 0x821652BC;
	sub_82060368(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x821d3a20
	ctx.lr = 0x821652C8;
	sub_821D3A20(ctx, base);
	// lwz r10,184(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	// cmplwi cr6,r10,8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 8, ctx.xer);
	// lwz r28,164(r1)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// bge cr6,0x821652dc
	if (!ctx.cr6.lt) goto loc_821652DC;
	// addi r28,r1,164
	ctx.r28.s64 = ctx.r1.s64 + 164;
loc_821652DC:
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82079fd8
	ctx.lr = 0x821652E4;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821652fc
	if (ctx.cr6.eq) goto loc_821652FC;
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r3,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r3.u32);
	// b 0x82165300
	goto loc_82165300;
loc_821652FC:
	// stw r26,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r26.u32);
loc_82165300:
	// stw r26,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r26.u32);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// stw r26,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r26.u32);
	// stw r26,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r26.u32);
	// lhz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821653a8
	if (ctx.cr6.eq) goto loc_821653A8;
	// addi r27,r31,52
	ctx.r27.s64 = ctx.r31.s64 + 52;
loc_82165320:
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x820797b8
	ctx.lr = 0x82165334;
	sub_820797B8(ctx, base);
	// ld r11,96(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// mr r31,r26
	ctx.r31.u64 = ctx.r26.u64;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lwz r29,108(r1)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r30,104(r1)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
loc_82165348:
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8216535c
	if (ctx.cr6.eq) goto loc_8216535C;
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x82165360
	if (ctx.cr6.eq) goto loc_82165360;
loc_8216535C:
	// twi 31,r0,22
loc_82165360:
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x8216537c
	if (ctx.cr6.eq) goto loc_8216537C;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// bl 0x82079e90
	ctx.lr = 0x82165378;
	sub_82079E90(ctx, base);
	// b 0x82165348
	goto loc_82165348;
loc_8216537C:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82165398
	if (!ctx.cr6.eq) goto loc_82165398;
	// lhz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r28.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x8206e258
	ctx.lr = 0x82165398;
	sub_8206E258(ctx, base);
loc_82165398:
	// lhzu r11,2(r28)
	ea = 2 + ctx.r28.u32;
	ctx.r11.u64 = PPC_LOAD_U16(ea);
	ctx.r28.u32 = ea;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82165320
	if (!ctx.cr6.eq) goto loc_82165320;
	// lwz r3,140(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
loc_821653A8:
	// lwz r11,144(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// subf r10,r3,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r3.s64;
	// srawi. r11,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r10.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x821653dc
	if (ctx.cr0.eq) goto loc_821653DC;
	// mr r10,r26
	ctx.r10.u64 = ctx.r26.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821653dc
	if (ctx.cr6.eq) goto loc_821653DC;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_821653C8:
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x821653d4
	if (ctx.cr6.lt) goto loc_821653D4;
	// twi 31,r0,22
loc_821653D4:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x821653c8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821653C8;
loc_821653DC:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821653e8
	if (ctx.cr6.eq) goto loc_821653E8;
	// bl 0x8207a630
	ctx.lr = 0x821653E8;
	sub_8207A630(ctx, base);
loc_821653E8:
	// stw r26,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r26.u32);
	// stw r26,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r26.u32);
	// stw r26,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r26.u32);
	// lwz r3,128(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// bl 0x8207a630
	ctx.lr = 0x821653FC;
	sub_8207A630(ctx, base);
	// lwz r11,184(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// blt cr6,0x82165410
	if (ctx.cr6.lt) goto loc_82165410;
	// lwz r3,164(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// bl 0x8207a630
	ctx.lr = 0x82165410;
	sub_8207A630(ctx, base);
loc_82165410:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82165418"))) PPC_WEAK_FUNC(sub_82165418);
PPC_FUNC_IMPL(__imp__sub_82165418) {
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
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r3,r3,52
	ctx.r3.s64 = ctx.r3.s64 + 52;
	// addi r10,r11,6316
	ctx.r10.s64 = ctx.r11.s64 + 6316;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// bl 0x82079620
	ctx.lr = 0x82165440;
	sub_82079620(ctx, base);
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// bl 0x82078e48
	ctx.lr = 0x82165448;
	sub_82078E48(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r8,r9,5752
	ctx.r8.s64 = ctx.r9.s64 + 5752;
	// stw r8,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
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

__attribute__((alias("__imp__sub_82165468"))) PPC_WEAK_FUNC(sub_82165468);
PPC_FUNC_IMPL(__imp__sub_82165468) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,44(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82165470"))) PPC_WEAK_FUNC(sub_82165470);
PPC_FUNC_IMPL(__imp__sub_82165470) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,40(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// mulli r10,r4,520
	ctx.r10.s64 = ctx.r4.s64 * 520;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + ctx.r11.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82165480"))) PPC_WEAK_FUNC(sub_82165480);
PPC_FUNC_IMPL(__imp__sub_82165480) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82165484"))) PPC_WEAK_FUNC(sub_82165484);
PPC_FUNC_IMPL(__imp__sub_82165484) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82165488"))) PPC_WEAK_FUNC(sub_82165488);
PPC_FUNC_IMPL(__imp__sub_82165488) {
	PPC_FUNC_PROLOGUE();
	// stw r4,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r4.u32);
	// stw r5,224(r3)
	PPC_STORE_U32(ctx.r3.u32 + 224, ctx.r5.u32);
	// stw r5,216(r3)
	PPC_STORE_U32(ctx.r3.u32 + 216, ctx.r5.u32);
	// stw r6,220(r3)
	PPC_STORE_U32(ctx.r3.u32 + 220, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216549C"))) PPC_WEAK_FUNC(sub_8216549C);
PPC_FUNC_IMPL(__imp__sub_8216549C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821654A0"))) PPC_WEAK_FUNC(sub_821654A0);
PPC_FUNC_IMPL(__imp__sub_821654A0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,228(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 228);
	// lwz r10,232(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 232);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821654B4"))) PPC_WEAK_FUNC(sub_821654B4);
PPC_FUNC_IMPL(__imp__sub_821654B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821654B8"))) PPC_WEAK_FUNC(sub_821654B8);
PPC_FUNC_IMPL(__imp__sub_821654B8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ ctx.r11.u64;
	// and r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 & ctx.r11.u64;
	// and r3,r8,r4
	ctx.r3.u64 = ctx.r8.u64 & ctx.r4.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821654D0"))) PPC_WEAK_FUNC(sub_821654D0);
PPC_FUNC_IMPL(__imp__sub_821654D0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r3,r11,0,19,19
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x1000;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821654DC"))) PPC_WEAK_FUNC(sub_821654DC);
PPC_FUNC_IMPL(__imp__sub_821654DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821654E0"))) PPC_WEAK_FUNC(sub_821654E0);
PPC_FUNC_IMPL(__imp__sub_821654E0) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,500(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 500);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821654f4
	if (ctx.cr6.eq) goto loc_821654F4;
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,500(r3)
	PPC_STORE_U8(ctx.r3.u32 + 500, ctx.r11.u8);
loc_821654F4:
	// lwz r11,496(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 496);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,496(r3)
	PPC_STORE_U32(ctx.r3.u32 + 496, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216550C"))) PPC_WEAK_FUNC(sub_8216550C);
PPC_FUNC_IMPL(__imp__sub_8216550C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82165510"))) PPC_WEAK_FUNC(sub_82165510);
PPC_FUNC_IMPL(__imp__sub_82165510) {
	PPC_FUNC_PROLOGUE();
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82165518"))) PPC_WEAK_FUNC(sub_82165518);
PPC_FUNC_IMPL(__imp__sub_82165518) {
	PPC_FUNC_PROLOGUE();
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82165520"))) PPC_WEAK_FUNC(sub_82165520);
PPC_FUNC_IMPL(__imp__sub_82165520) {
	PPC_FUNC_PROLOGUE();
	// stb r4,33(r3)
	PPC_STORE_U8(ctx.r3.u32 + 33, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82165528"))) PPC_WEAK_FUNC(sub_82165528);
PPC_FUNC_IMPL(__imp__sub_82165528) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216552C"))) PPC_WEAK_FUNC(sub_8216552C);
PPC_FUNC_IMPL(__imp__sub_8216552C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82165530"))) PPC_WEAK_FUNC(sub_82165530);
PPC_FUNC_IMPL(__imp__sub_82165530) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lwz r9,24(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r8,16(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r7,r10,-1456
	ctx.r7.s64 = ctx.r10.s64 + -1456;
	// lwz r6,20(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// stw r9,224(r8)
	PPC_STORE_U32(ctx.r8.u32 + 224, ctx.r9.u32);
	// stw r6,16(r8)
	PPC_STORE_U32(ctx.r8.u32 + 16, ctx.r6.u32);
	// stw r9,216(r8)
	PPC_STORE_U32(ctx.r8.u32 + 216, ctx.r9.u32);
	// stw r11,220(r8)
	PPC_STORE_U32(ctx.r8.u32 + 220, ctx.r11.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82165560"))) PPC_WEAK_FUNC(sub_82165560);
PPC_FUNC_IMPL(__imp__sub_82165560) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// lfs f0,4(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,228(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 228, temp.u32);
	// lfs f13,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,232(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 232, temp.u32);
	// lwz r9,184(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// stw r9,200(r3)
	PPC_STORE_U32(ctx.r3.u32 + 200, ctx.r9.u32);
	// lbz r8,12(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 12);
	// stb r8,180(r3)
	PPC_STORE_U8(ctx.r3.u32 + 180, ctx.r8.u8);
	// lwz r7,16(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// stw r7,184(r3)
	PPC_STORE_U32(ctx.r3.u32 + 184, ctx.r7.u32);
	// lfs f12,224(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 224);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,256(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 256, temp.u32);
	// lfs f11,228(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 228);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,260(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 260, temp.u32);
	// lfs f10,256(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 256);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,288(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 288, temp.u32);
	// lfs f9,260(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 260);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,292(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 292, temp.u32);
	// lwz r6,188(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 188);
	// stw r6,204(r3)
	PPC_STORE_U32(ctx.r3.u32 + 204, ctx.r6.u32);
	// lbz r5,13(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 13);
	// stb r5,181(r3)
	PPC_STORE_U8(ctx.r3.u32 + 181, ctx.r5.u8);
	// lwz r11,20(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// stw r11,188(r3)
	PPC_STORE_U32(ctx.r3.u32 + 188, ctx.r11.u32);
	// lfs f8,232(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 232);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,264(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 264, temp.u32);
	// lfs f7,236(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 236);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,268(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 268, temp.u32);
	// lfs f6,264(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 264);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,296(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 296, temp.u32);
	// lfs f5,268(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 268);
	ctx.f5.f64 = double(temp.f32);
	// stfs f5,300(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 300, temp.u32);
	// lwz r10,192(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 192);
	// stw r10,208(r3)
	PPC_STORE_U32(ctx.r3.u32 + 208, ctx.r10.u32);
	// lbz r9,14(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 14);
	// stb r9,182(r3)
	PPC_STORE_U8(ctx.r3.u32 + 182, ctx.r9.u8);
	// lwz r8,24(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// stw r8,192(r3)
	PPC_STORE_U32(ctx.r3.u32 + 192, ctx.r8.u32);
	// lfs f4,240(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 240);
	ctx.f4.f64 = double(temp.f32);
	// stfs f4,272(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 272, temp.u32);
	// lfs f3,244(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 244);
	ctx.f3.f64 = double(temp.f32);
	// stfs f3,276(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 276, temp.u32);
	// lfs f2,272(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 272);
	ctx.f2.f64 = double(temp.f32);
	// stfs f2,304(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 304, temp.u32);
	// lfs f1,276(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 276);
	ctx.f1.f64 = double(temp.f32);
	// stfs f1,308(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 308, temp.u32);
	// lwz r7,196(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 196);
	// stw r7,212(r3)
	PPC_STORE_U32(ctx.r3.u32 + 212, ctx.r7.u32);
	// lbz r6,15(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 15);
	// stb r6,183(r3)
	PPC_STORE_U8(ctx.r3.u32 + 183, ctx.r6.u8);
	// lwz r5,28(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// stw r5,196(r3)
	PPC_STORE_U32(ctx.r3.u32 + 196, ctx.r5.u32);
	// lfs f0,248(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 248);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,280(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 280, temp.u32);
	// lfs f13,252(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 252);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,284(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 284, temp.u32);
	// lfs f12,280(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 280);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,312(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 312, temp.u32);
	// lfs f11,284(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 284);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,316(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 316, temp.u32);
	// lwz r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// and r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 & ctx.r10.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x821656a0
	if (ctx.cr6.eq) goto loc_821656A0;
	// lwz r9,224(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 224);
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r9,224(r3)
	PPC_STORE_U32(ctx.r3.u32 + 224, ctx.r9.u32);
	// bnelr 
	if (!ctx.cr0.eq) return;
	// lwz r9,220(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 220);
	// andc r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 & ~ctx.r11.u64;
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// stw r9,224(r3)
	PPC_STORE_U32(ctx.r3.u32 + 224, ctx.r9.u32);
	// blr 
	return;
loc_821656A0:
	// lwz r11,216(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 216);
	// stw r11,224(r3)
	PPC_STORE_U32(ctx.r3.u32 + 224, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821656AC"))) PPC_WEAK_FUNC(sub_821656AC);
PPC_FUNC_IMPL(__imp__sub_821656AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821656B0"))) PPC_WEAK_FUNC(sub_821656B0);
PPC_FUNC_IMPL(__imp__sub_821656B0) {
	PPC_FUNC_PROLOGUE();
	// b 0x82165560
	sub_82165560(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821656B4"))) PPC_WEAK_FUNC(sub_821656B4);
PPC_FUNC_IMPL(__imp__sub_821656B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821656B8"))) PPC_WEAK_FUNC(sub_821656B8);
PPC_FUNC_IMPL(__imp__sub_821656B8) {
	PPC_FUNC_PROLOGUE();
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821656dc
	if (!ctx.cr6.eq) goto loc_821656DC;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// ld r30,-16(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_821656DC:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r31,0
	ctx.r31.s64 = 0;
	// li r30,1
	ctx.r30.s64 = 1;
loc_821656E8:
	// slw r7,r30,r31
	ctx.r7.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r30.u32 << (ctx.r31.u8 & 0x3F));
	// and r11,r7,r4
	ctx.r11.u64 = ctx.r7.u64 & ctx.r4.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821657e4
	if (ctx.cr6.eq) goto loc_821657E4;
	// lwz r10,24(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24);
	// lwz r11,4(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lbz r9,21(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 21);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82165734
	if (!ctx.cr6.eq) goto loc_82165734;
loc_8216570C:
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r7
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x82165720
	if (!ctx.cr6.lt) goto loc_82165720;
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x82165728
	goto loc_82165728;
loc_82165720:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
loc_82165728:
	// lbz r9,21(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 21);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8216570c
	if (ctx.cr6.eq) goto loc_8216570C;
loc_82165734:
	// lwz r11,0(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r9,24(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24);
	// stw r10,-44(r1)
	PPC_STORE_U32(ctx.r1.u32 + -44, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r11,-48(r1)
	PPC_STORE_U32(ctx.r1.u32 + -48, ctx.r11.u32);
	// beq cr6,0x82165754
	if (ctx.cr6.eq) goto loc_82165754;
	// cmplw cr6,r11,r11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82165758
	if (ctx.cr6.eq) goto loc_82165758;
loc_82165754:
	// twi 31,r0,22
loc_82165758:
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82165774
	if (ctx.cr6.eq) goto loc_82165774;
	// lwz r10,12(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r7,r10
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82165774
	if (ctx.cr6.lt) goto loc_82165774;
	// addi r10,r1,-48
	ctx.r10.s64 = ctx.r1.s64 + -48;
	// b 0x82165780
	goto loc_82165780;
loc_82165774:
	// stw r9,-36(r1)
	PPC_STORE_U32(ctx.r1.u32 + -36, ctx.r9.u32);
	// addi r10,r1,-40
	ctx.r10.s64 = ctx.r1.s64 + -40;
	// stw r11,-40(r1)
	PPC_STORE_U32(ctx.r1.u32 + -40, ctx.r11.u32);
loc_82165780:
	// ld r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// std r10,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r10.u64);
	// lwz r10,-32(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8216579c
	if (ctx.cr6.eq) goto loc_8216579C;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x821657a0
	if (ctx.cr6.eq) goto loc_821657A0;
loc_8216579C:
	// twi 31,r0,22
loc_821657A0:
	// lwz r8,-28(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + -28);
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x821657e0
	if (ctx.cr6.eq) goto loc_821657E0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x821657d8
	if (!ctx.cr6.eq) goto loc_821657D8;
	// twi 31,r0,22
	// li r11,0
	ctx.r11.s64 = 0;
loc_821657BC:
	// lwz r11,24(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x821657cc
	if (!ctx.cr6.eq) goto loc_821657CC;
	// twi 31,r0,22
loc_821657CC:
	// lwz r11,16(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// or r5,r11,r5
	ctx.r5.u64 = ctx.r11.u64 | ctx.r5.u64;
	// b 0x821657e4
	goto loc_821657E4;
loc_821657D8:
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x821657bc
	goto loc_821657BC;
loc_821657E0:
	// or r5,r7,r5
	ctx.r5.u64 = ctx.r7.u64 | ctx.r5.u64;
loc_821657E4:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmplwi cr6,r31,24
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 24, ctx.xer);
	// blt cr6,0x821656e8
	if (ctx.cr6.lt) goto loc_821656E8;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// ld r30,-16(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82165800"))) PPC_WEAK_FUNC(sub_82165800);
PPC_FUNC_IMPL(__imp__sub_82165800) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x82165808;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32224
	ctx.r31.s64 = -2111832064;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// li r24,1
	ctx.r24.s64 = 1;
	// lwz r3,-31300(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31300);
	// lbz r11,296(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 296);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8216583c
	if (!ctx.cr6.eq) goto loc_8216583C;
	// stb r24,296(r3)
	PPC_STORE_U8(ctx.r3.u32 + 296, ctx.r24.u8);
	// bl 0x82162ed0
	ctx.lr = 0x82165838;
	sub_82162ED0(ctx, base);
	// lwz r3,-31300(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31300);
loc_8216583C:
	// addi r11,r29,70
	ctx.r11.s64 = ctx.r29.s64 + 70;
	// li r10,7
	ctx.r10.s64 = 7;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r25,0
	ctx.r25.s64 = 0;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r29,r25
	ctx.r29.u64 = ctx.r25.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// mr r26,r25
	ctx.r26.u64 = ctx.r25.u64;
	// lwzx r10,r9,r3
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r3.u32);
	// mr r31,r25
	ctx.r31.u64 = ctx.r25.u64;
	// addi r11,r11,-24944
	ctx.r11.s64 = ctx.r11.s64 + -24944;
	// mr r28,r25
	ctx.r28.u64 = ctx.r25.u64;
loc_8216586C:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x82165884
	if (ctx.cr6.eq) goto loc_82165884;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// or r31,r9,r31
	ctx.r31.u64 = ctx.r9.u64 | ctx.r31.u64;
loc_82165884:
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x8216589c
	if (ctx.cr6.eq) goto loc_8216589C;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// or r31,r9,r31
	ctx.r31.u64 = ctx.r9.u64 | ctx.r31.u64;
loc_8216589C:
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// bdnz 0x8216586c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8216586C;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x821658e8
	if (ctx.cr6.eq) goto loc_821658E8;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r27,52
	ctx.r3.s64 = ctx.r27.s64 + 52;
	// bl 0x821656b8
	ctx.lr = 0x821658B8;
	sub_821656B8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r3,r27,84
	ctx.r3.s64 = ctx.r27.s64 + 84;
	// bl 0x821656b8
	ctx.lr = 0x821658C4;
	sub_821656B8(ctx, base);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r27,116
	ctx.r3.s64 = ctx.r27.s64 + 116;
	// bl 0x821656b8
	ctx.lr = 0x821658D4;
	sub_821656B8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r27,148
	ctx.r3.s64 = ctx.r27.s64 + 148;
	// bl 0x821656b8
	ctx.lr = 0x821658E4;
	sub_821656B8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
loc_821658E8:
	// or r11,r28,r31
	ctx.r11.u64 = ctx.r28.u64 | ctx.r31.u64;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// or r4,r11,r29
	ctx.r4.u64 = ctx.r11.u64 | ctx.r29.u64;
	// beq cr6,0x82165904
	if (ctx.cr6.eq) goto loc_82165904;
	// addi r3,r27,20
	ctx.r3.s64 = ctx.r27.s64 + 20;
	// bl 0x821656b8
	ctx.lr = 0x82165900;
	sub_821656B8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
loc_82165904:
	// stw r4,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r4.u32);
	// stw r29,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r29.u32);
	// stb r24,12(r30)
	PPC_STORE_U8(ctx.r30.u32 + 12, ctx.r24.u8);
	// stb r25,13(r30)
	PPC_STORE_U8(ctx.r30.u32 + 13, ctx.r25.u8);
	// stb r24,14(r30)
	PPC_STORE_U8(ctx.r30.u32 + 14, ctx.r24.u8);
	// stb r25,15(r30)
	PPC_STORE_U8(ctx.r30.u32 + 15, ctx.r25.u8);
	// stw r26,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r26.u32);
	// stw r31,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r31.u32);
	// stw r28,28(r30)
	PPC_STORE_U32(ctx.r30.u32 + 28, ctx.r28.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82165930"))) PPC_WEAK_FUNC(sub_82165930);
PPC_FUNC_IMPL(__imp__sub_82165930) {
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
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r10,r11,-1456
	ctx.r10.s64 = ctx.r11.s64 + -1456;
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r30,12(r31)
	PPC_STORE_U8(ctx.r31.u32 + 12, ctx.r30.u8);
	// bl 0x82170650
	ctx.lr = 0x8216596C;
	sub_82170650(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stw r30,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r30.u32);
	// addi r7,r9,6244
	ctx.r7.s64 = ctx.r9.s64 + 6244;
	// stb r30,32(r31)
	PPC_STORE_U8(ctx.r31.u32 + 32, ctx.r30.u8);
	// addi r6,r8,6272
	ctx.r6.s64 = ctx.r8.s64 + 6272;
	// stb r30,33(r31)
	PPC_STORE_U8(ctx.r31.u32 + 33, ctx.r30.u8);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r7,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
	// stw r6,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r6.u32);
	// addi r10,r31,34
	ctx.r10.s64 = ctx.r31.s64 + 34;
	// stb r11,34(r31)
	PPC_STORE_U8(ctx.r31.u32 + 34, ctx.r11.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r11,35(r31)
	PPC_STORE_U8(ctx.r31.u32 + 35, ctx.r11.u8);
	// stb r11,36(r31)
	PPC_STORE_U8(ctx.r31.u32 + 36, ctx.r11.u8);
	// stb r11,37(r31)
	PPC_STORE_U8(ctx.r31.u32 + 37, ctx.r11.u8);
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

__attribute__((alias("__imp__sub_821659C4"))) PPC_WEAK_FUNC(sub_821659C4);
PPC_FUNC_IMPL(__imp__sub_821659C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821659C8"))) PPC_WEAK_FUNC(sub_821659C8);
PPC_FUNC_IMPL(__imp__sub_821659C8) {
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
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lbz r10,33(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 33);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r8,r11,6244
	ctx.r8.s64 = ctx.r11.s64 + 6244;
	// addi r7,r9,6272
	ctx.r7.s64 = ctx.r9.s64 + 6272;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r7,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r7.u32);
	// beq cr6,0x82165a08
	if (ctx.cr6.eq) goto loc_82165A08;
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,33(r3)
	PPC_STORE_U8(ctx.r3.u32 + 33, ctx.r11.u8);
loc_82165A08:
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r9,r11,5680
	ctx.r9.s64 = ctx.r11.s64 + 5680;
	// stw r9,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r9.u32);
	// lwz r11,-31328(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -31328);
	// addi r3,r11,32
	ctx.r3.s64 = ctx.r11.s64 + 32;
	// bl 0x82173a70
	ctx.lr = 0x82165A28;
	sub_82173A70(ctx, base);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82165a48
	if (ctx.cr6.eq) goto loc_82165A48;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82165A48;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82165A48:
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r10,r11,-1456
	ctx.r10.s64 = ctx.r11.s64 + -1456;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_82165A68"))) PPC_WEAK_FUNC(sub_82165A68);
PPC_FUNC_IMPL(__imp__sub_82165A68) {
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
	// lis r31,-32224
	ctx.r31.s64 = -2111832064;
	// lwz r11,-31300(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31300);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82165abc
	if (!ctx.cr6.eq) goto loc_82165ABC;
	// li r3,300
	ctx.r3.s64 = 300;
	// bl 0x82079fd8
	ctx.lr = 0x82165A90;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82165ab4
	if (ctx.cr6.eq) goto loc_82165AB4;
	// bl 0x82163160
	ctx.lr = 0x82165A9C;
	sub_82163160(ctx, base);
	// stw r3,-31300(r31)
	PPC_STORE_U32(ctx.r31.u32 + -31300, ctx.r3.u32);
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
loc_82165AB4:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,-31300(r31)
	PPC_STORE_U32(ctx.r31.u32 + -31300, ctx.r11.u32);
loc_82165ABC:
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

__attribute__((alias("__imp__sub_82165AD0"))) PPC_WEAK_FUNC(sub_82165AD0);
PPC_FUNC_IMPL(__imp__sub_82165AD0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82165AD8;
	__savegprlr_28(ctx, base);
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// li r28,0
	ctx.r28.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x82165b78
	if (!ctx.cr6.gt) goto loc_82165B78;
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
loc_82165AF8:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// add r5,r11,r30
	ctx.r5.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x82165800
	ctx.lr = 0x82165B0C;
	sub_82165800(ctx, base);
	// lbz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82165b28
	if (ctx.cr6.eq) goto loc_82165B28;
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// add r3,r11,r30
	ctx.r3.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x82165560
	ctx.lr = 0x82165B28;
	sub_82165560(ctx, base);
loc_82165B28:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// add r3,r11,r30
	ctx.r3.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x82165560
	ctx.lr = 0x82165B38;
	sub_82165560(ctx, base);
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// lbz r10,500(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 500);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82165b50
	if (ctx.cr6.eq) goto loc_82165B50;
	// stb r28,500(r11)
	PPC_STORE_U8(ctx.r11.u32 + 500, ctx.r28.u8);
loc_82165B50:
	// lwz r10,496(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 496);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82165b64
	if (ctx.cr6.eq) goto loc_82165B64;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,496(r11)
	PPC_STORE_U32(ctx.r11.u32 + 496, ctx.r10.u32);
loc_82165B64:
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r30,r30,520
	ctx.r30.s64 = ctx.r30.s64 + 520;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82165af8
	if (ctx.cr6.lt) goto loc_82165AF8;
loc_82165B78:
	// stb r28,32(r31)
	PPC_STORE_U8(ctx.r31.u32 + 32, ctx.r28.u8);
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82165B84"))) PPC_WEAK_FUNC(sub_82165B84);
PPC_FUNC_IMPL(__imp__sub_82165B84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82165B88"))) PPC_WEAK_FUNC(sub_82165B88);
PPC_FUNC_IMPL(__imp__sub_82165B88) {
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
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lwz r11,40(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r8,r10,6280
	ctx.r8.s64 = ctx.r10.s64 + 6280;
	// addi r7,r9,6308
	ctx.r7.s64 = ctx.r9.s64 + 6308;
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r7,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r7.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stb r6,24(r3)
	PPC_STORE_U8(ctx.r3.u32 + 24, ctx.r6.u8);
	// beq cr6,0x82165bf8
	if (ctx.cr6.eq) goto loc_82165BF8;
	// lwz r10,-8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// addi r3,r11,-8
	ctx.r3.s64 = ctx.r11.s64 + -8;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82165bf4
	if (ctx.cr6.eq) goto loc_82165BF4;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82165BF0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82165bf8
	goto loc_82165BF8;
loc_82165BF4:
	// bl 0x8207a8a0
	ctx.lr = 0x82165BF8;
	sub_8207A8A0(ctx, base);
loc_82165BF8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821659c8
	ctx.lr = 0x82165C00;
	sub_821659C8(ctx, base);
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

__attribute__((alias("__imp__sub_82165C14"))) PPC_WEAK_FUNC(sub_82165C14);
PPC_FUNC_IMPL(__imp__sub_82165C14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82165C18"))) PPC_WEAK_FUNC(sub_82165C18);
PPC_FUNC_IMPL(__imp__sub_82165C18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82165C20;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r10,r11,6240
	ctx.r10.s64 = ctx.r11.s64 + 6240;
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// addi r29,r3,20
	ctx.r29.s64 = ctx.r3.s64 + 20;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r30,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r30.u32);
	// stw r30,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r30.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82078d90
	ctx.lr = 0x82165C50;
	sub_82078D90(ctx, base);
	// addi r28,r29,32
	ctx.r28.s64 = ctx.r29.s64 + 32;
	// li r29,3
	ctx.r29.s64 = 3;
loc_82165C58:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82078d90
	ctx.lr = 0x82165C60;
	sub_82078D90(ctx, base);
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r28,r28,32
	ctx.r28.s64 = ctx.r28.s64 + 32;
	// bge 0x82165c58
	if (!ctx.cr0.lt) goto loc_82165C58;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// stb r30,236(r31)
	PPC_STORE_U8(ctx.r31.u32 + 236, ctx.r30.u8);
	// li r11,4
	ctx.r11.s64 = 4;
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// addi r10,r31,180
	ctx.r10.s64 = ctx.r31.s64 + 180;
	// addi r8,r31,512
	ctx.r8.s64 = ctx.r31.s64 + 512;
	// lfs f0,21768(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stfs f0,240(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 240, temp.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stfs f0,244(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 244, temp.u32);
	// addi r11,r31,284
	ctx.r11.s64 = ctx.r31.s64 + 284;
	// stfs f0,248(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 248, temp.u32);
	// stfs f0,252(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 252, temp.u32);
	// stw r30,496(r31)
	PPC_STORE_U32(ctx.r31.u32 + 496, ctx.r30.u32);
	// stb r30,500(r31)
	PPC_STORE_U8(ctx.r31.u32 + 500, ctx.r30.u8);
loc_82165CAC:
	// stw r30,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r30.u32);
	// stwu r30,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r30.u32);
	ctx.r10.u32 = ea;
	// stbx r7,r8,r9
	PPC_STORE_U8(ctx.r8.u32 + ctx.r9.u32, ctx.r7.u8);
	// stfs f0,-28(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + -28, temp.u32);
	// stfs f0,-24(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + -24, temp.u32);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stfs f0,4(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// stfsu f0,8(r11)
	temp.f32 = float(ctx.f0.f64);
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82165cac
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82165CAC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82165CDC"))) PPC_WEAK_FUNC(sub_82165CDC);
PPC_FUNC_IMPL(__imp__sub_82165CDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82165CE0"))) PPC_WEAK_FUNC(sub_82165CE0);
PPC_FUNC_IMPL(__imp__sub_82165CE0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82165CE8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// bl 0x82165930
	ctx.lr = 0x82165CF4;
	sub_82165930(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r9,r11,6280
	ctx.r9.s64 = ctx.r11.s64 + 6280;
	// addi r8,r10,6308
	ctx.r8.s64 = ctx.r10.s64 + 6308;
	// li r7,2
	ctx.r7.s64 = 2;
	// stw r9,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r9.u32);
	// li r27,1
	ctx.r27.s64 = 1;
	// stw r8,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r8.u32);
	// stw r7,44(r29)
	PPC_STORE_U32(ctx.r29.u32 + 44, ctx.r7.u32);
	// li r3,2088
	ctx.r3.s64 = 2088;
	// stb r27,48(r29)
	PPC_STORE_U8(ctx.r29.u32 + 48, ctx.r27.u8);
	// bl 0x8207a030
	ctx.lr = 0x82165D24;
	sub_8207A030(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82165d6c
	if (ctx.cr6.eq) goto loc_82165D6C;
	// li r11,4
	ctx.r11.s64 = 4;
	// addi r28,r3,8
	ctx.r28.s64 = ctx.r3.s64 + 8;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r31,3
	ctx.r31.s64 = 3;
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
loc_82165D40:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82165c18
	ctx.lr = 0x82165D48;
	sub_82165C18(ctx, base);
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// addi r30,r30,520
	ctx.r30.s64 = ctx.r30.s64 + 520;
	// bge 0x82165d40
	if (!ctx.cr0.lt) goto loc_82165D40;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stw r28,40(r29)
	PPC_STORE_U32(ctx.r29.u32 + 40, ctx.r28.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stb r27,24(r29)
	PPC_STORE_U8(ctx.r29.u32 + 24, ctx.r27.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_82165D6C:
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r27,24(r29)
	PPC_STORE_U8(ctx.r29.u32 + 24, ctx.r27.u8);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r11,40(r29)
	PPC_STORE_U32(ctx.r29.u32 + 40, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82165D84"))) PPC_WEAK_FUNC(sub_82165D84);
PPC_FUNC_IMPL(__imp__sub_82165D84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82165D88"))) PPC_WEAK_FUNC(sub_82165D88);
PPC_FUNC_IMPL(__imp__sub_82165D88) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r3,r3,20
	ctx.r3.s64 = ctx.r3.s64 + 20;
	// addi r9,r10,6240
	ctx.r9.s64 = ctx.r10.s64 + 6240;
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// b 0x82078c18
	sub_82078C18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82165DA0"))) PPC_WEAK_FUNC(sub_82165DA0);
PPC_FUNC_IMPL(__imp__sub_82165DA0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82165DAC"))) PPC_WEAK_FUNC(sub_82165DAC);
PPC_FUNC_IMPL(__imp__sub_82165DAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82165DB0"))) PPC_WEAK_FUNC(sub_82165DB0);
PPC_FUNC_IMPL(__imp__sub_82165DB0) {
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
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82165DE0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r8,32(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82165DF8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
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

__attribute__((alias("__imp__sub_82165E10"))) PPC_WEAK_FUNC(sub_82165E10);
PPC_FUNC_IMPL(__imp__sub_82165E10) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82165E14"))) PPC_WEAK_FUNC(sub_82165E14);
PPC_FUNC_IMPL(__imp__sub_82165E14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82165E18"))) PPC_WEAK_FUNC(sub_82165E18);
PPC_FUNC_IMPL(__imp__sub_82165E18) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82165E1C"))) PPC_WEAK_FUNC(sub_82165E1C);
PPC_FUNC_IMPL(__imp__sub_82165E1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82165E20"))) PPC_WEAK_FUNC(sub_82165E20);
PPC_FUNC_IMPL(__imp__sub_82165E20) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82165E24"))) PPC_WEAK_FUNC(sub_82165E24);
PPC_FUNC_IMPL(__imp__sub_82165E24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82165E28"))) PPC_WEAK_FUNC(sub_82165E28);
PPC_FUNC_IMPL(__imp__sub_82165E28) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82165E2C"))) PPC_WEAK_FUNC(sub_82165E2C);
PPC_FUNC_IMPL(__imp__sub_82165E2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82165E30"))) PPC_WEAK_FUNC(sub_82165E30);
PPC_FUNC_IMPL(__imp__sub_82165E30) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82165E34"))) PPC_WEAK_FUNC(sub_82165E34);
PPC_FUNC_IMPL(__imp__sub_82165E34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82165E38"))) PPC_WEAK_FUNC(sub_82165E38);
PPC_FUNC_IMPL(__imp__sub_82165E38) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,80(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82165E40"))) PPC_WEAK_FUNC(sub_82165E40);
PPC_FUNC_IMPL(__imp__sub_82165E40) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,76(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82165E48"))) PPC_WEAK_FUNC(sub_82165E48);
PPC_FUNC_IMPL(__imp__sub_82165E48) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82165E4C"))) PPC_WEAK_FUNC(sub_82165E4C);
PPC_FUNC_IMPL(__imp__sub_82165E4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82165E50"))) PPC_WEAK_FUNC(sub_82165E50);
PPC_FUNC_IMPL(__imp__sub_82165E50) {
	PPC_FUNC_PROLOGUE();
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82165E5C"))) PPC_WEAK_FUNC(sub_82165E5C);
PPC_FUNC_IMPL(__imp__sub_82165E5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82165E60"))) PPC_WEAK_FUNC(sub_82165E60);
PPC_FUNC_IMPL(__imp__sub_82165E60) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82165E64"))) PPC_WEAK_FUNC(sub_82165E64);
PPC_FUNC_IMPL(__imp__sub_82165E64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82165E68"))) PPC_WEAK_FUNC(sub_82165E68);
PPC_FUNC_IMPL(__imp__sub_82165E68) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82165E6C"))) PPC_WEAK_FUNC(sub_82165E6C);
PPC_FUNC_IMPL(__imp__sub_82165E6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82165E70"))) PPC_WEAK_FUNC(sub_82165E70);
PPC_FUNC_IMPL(__imp__sub_82165E70) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82165E74"))) PPC_WEAK_FUNC(sub_82165E74);
PPC_FUNC_IMPL(__imp__sub_82165E74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82165E78"))) PPC_WEAK_FUNC(sub_82165E78);
PPC_FUNC_IMPL(__imp__sub_82165E78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stfd f30,-32(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.f30.u64);
	// stfd f31,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,84(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// std r4,152(r1)
	PPC_STORE_U64(ctx.r1.u32 + 152, ctx.r4.u64);
	// lwz r31,16(r11)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82165f2c
	if (ctx.cr6.eq) goto loc_82165F2C;
	// lfs f31,156(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	ctx.f31.f64 = double(temp.f32);
	// lfs f30,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f30.f64 = double(temp.f32);
loc_82165EAC:
	// lbz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 76);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82165f20
	if (ctx.cr6.eq) goto loc_82165F20;
	// lbz r11,79(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 79);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82165f20
	if (!ctx.cr6.eq) goto loc_82165F20;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82165EDC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// bgt cr6,0x82165f10
	if (ctx.cr6.gt) goto loc_82165F10;
	// lfs f0,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f30,f0
	ctx.cr6.compare(ctx.f30.f64, ctx.f0.f64);
	// bge cr6,0x82165f10
	if (!ctx.cr6.lt) goto loc_82165F10;
	// lfs f0,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bgt cr6,0x82165f10
	if (ctx.cr6.gt) goto loc_82165F10;
	// lfs f0,12(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// li r11,1
	ctx.r11.s64 = 1;
	// fcmpu cr6,f31,f0
	ctx.cr6.compare(ctx.f31.f64, ctx.f0.f64);
	// blt cr6,0x82165f14
	if (ctx.cr6.lt) goto loc_82165F14;
loc_82165F10:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82165F14:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82165f4c
	if (!ctx.cr6.eq) goto loc_82165F4C;
loc_82165F20:
	// lwz r31,4(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82165eac
	if (!ctx.cr6.eq) goto loc_82165EAC;
loc_82165F2C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82165F30:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f30,-32(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// lfd f31,-24(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82165F4C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x82165f30
	goto loc_82165F30;
}

__attribute__((alias("__imp__sub_82165F54"))) PPC_WEAK_FUNC(sub_82165F54);
PPC_FUNC_IMPL(__imp__sub_82165F54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82165F58"))) PPC_WEAK_FUNC(sub_82165F58);
PPC_FUNC_IMPL(__imp__sub_82165F58) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,84(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82165f90
	if (ctx.cr6.eq) goto loc_82165F90;
loc_82165F68:
	// lbz r11,76(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 76);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82165f84
	if (ctx.cr6.eq) goto loc_82165F84;
	// lwz r11,80(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// and r10,r11,r4
	ctx.r10.u64 = ctx.r11.u64 & ctx.r4.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
loc_82165F84:
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82165f68
	if (!ctx.cr6.eq) goto loc_82165F68;
loc_82165F90:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82165F98"))) PPC_WEAK_FUNC(sub_82165F98);
PPC_FUNC_IMPL(__imp__sub_82165F98) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,84(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82165fcc
	if (ctx.cr6.eq) goto loc_82165FCC;
loc_82165FA8:
	// lbz r11,76(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 76);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82165fc0
	if (ctx.cr6.eq) goto loc_82165FC0;
	// lbz r11,77(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 77);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
loc_82165FC0:
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82165fa8
	if (!ctx.cr6.eq) goto loc_82165FA8;
loc_82165FCC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82165FD4"))) PPC_WEAK_FUNC(sub_82165FD4);
PPC_FUNC_IMPL(__imp__sub_82165FD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82165FD8"))) PPC_WEAK_FUNC(sub_82165FD8);
PPC_FUNC_IMPL(__imp__sub_82165FD8) {
	PPC_FUNC_PROLOGUE();
	// stw r3,72(r4)
	PPC_STORE_U32(ctx.r4.u32 + 72, ctx.r3.u32);
	// addi r11,r4,4
	ctx.r11.s64 = ctx.r4.s64 + 4;
	// lwz r10,84(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r8,20(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// stw r4,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r4.u32);
	// stw r11,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r11.u32);
	// stw r9,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82165FFC"))) PPC_WEAK_FUNC(sub_82165FFC);
PPC_FUNC_IMPL(__imp__sub_82165FFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82166000"))) PPC_WEAK_FUNC(sub_82166000);
PPC_FUNC_IMPL(__imp__sub_82166000) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82166008;
	__savegprlr_28(ctx, base);
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x82080364
	ctx.lr = 0x82166010;
	__savefpr_27(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,84(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// std r4,200(r1)
	PPC_STORE_U64(ctx.r1.u32 + 200, ctx.r4.u64);
	// lwz r31,16(r11)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82166054
	if (ctx.cr6.eq) goto loc_82166054;
loc_82166030:
	// lbz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 76);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82166048
	if (ctx.cr6.eq) goto loc_82166048;
	// lbz r10,77(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 77);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82166170
	if (!ctx.cr6.eq) goto loc_82166170;
loc_82166048:
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82166030
	if (!ctx.cr6.eq) goto loc_82166030;
loc_82166054:
	// li r28,0
	ctx.r28.s64 = 0;
loc_82166058:
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r11,r11,-2064
	ctx.r11.s64 = ctx.r11.s64 + -2064;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// lfs f31,128(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 128);
	ctx.f31.f64 = double(temp.f32);
	// beq cr6,0x8216615c
	if (ctx.cr6.eq) goto loc_8216615C;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f29,204(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 204);
	ctx.f29.f64 = double(temp.f32);
	// lfs f28,200(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	ctx.f28.f64 = double(temp.f32);
	// lfs f27,28(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	ctx.f27.f64 = double(temp.f32);
	// lfs f30,21768(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 21768);
	ctx.f30.f64 = double(temp.f32);
loc_82166084:
	// cmplw cr6,r31,r28
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x82166150
	if (ctx.cr6.eq) goto loc_82166150;
	// lbz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 76);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82166150
	if (ctx.cr6.eq) goto loc_82166150;
	// lbz r11,78(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 78);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82166150
	if (!ctx.cr6.eq) goto loc_82166150;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821660BC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lfs f13,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r29,8
	ctx.r11.s64 = ctx.r29.s64 + 8;
	// lfs f12,12(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// fadds f11,f0,f13
	ctx.f11.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lfs f10,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fadds f9,f12,f10
	ctx.f9.f64 = double(float(ctx.f12.f64 + ctx.f10.f64));
	// fmuls f0,f11,f27
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f27.f64));
	// fmuls f13,f9,f27
	ctx.f13.f64 = double(float(ctx.f9.f64 * ctx.f27.f64));
loc_821660E4:
	// lfs f12,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f0,f12
	ctx.f11.f64 = double(float(ctx.f0.f64 - ctx.f12.f64));
	// lfs f10,4(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,-8(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f13,f10
	ctx.f8.f64 = double(float(ctx.f13.f64 - ctx.f10.f64));
	// lfs f7,0(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f6,f11,f9
	ctx.f6.f64 = double(float(ctx.f11.f64 * ctx.f9.f64));
	// fmadds f5,f8,f7,f6
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f7.f64 + ctx.f6.f64));
	// fcmpu cr6,f5,f30
	ctx.cr6.compare(ctx.f5.f64, ctx.f30.f64);
	// blt cr6,0x82166178
	if (ctx.cr6.lt) goto loc_82166178;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// blt cr6,0x821660e4
	if (ctx.cr6.lt) goto loc_821660E4;
	// li r11,1
	ctx.r11.s64 = 1;
loc_82166120:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82166150
	if (ctx.cr6.eq) goto loc_82166150;
	// fsubs f0,f28,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f28.f64 - ctx.f0.f64));
	// fsubs f13,f29,f13
	ctx.f13.f64 = double(float(ctx.f29.f64 - ctx.f13.f64));
	// fabs f12,f0
	ctx.f12.u64 = ctx.f0.u64 & ~0x8000000000000000;
	// fabs f11,f13
	ctx.f11.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fadds f0,f12,f11
	ctx.f0.f64 = double(float(ctx.f12.f64 + ctx.f11.f64));
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x82166150
	if (!ctx.cr6.lt) goto loc_82166150;
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
	// fmr f31,f0
	ctx.f31.f64 = ctx.f0.f64;
loc_82166150:
	// lwz r31,4(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82166084
	if (!ctx.cr6.eq) goto loc_82166084;
loc_8216615C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x820803b0
	ctx.lr = 0x8216616C;
	__restfpr_27(ctx, base);
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_82166170:
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
	// b 0x82166058
	goto loc_82166058;
loc_82166178:
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x82166120
	goto loc_82166120;
}

__attribute__((alias("__imp__sub_82166180"))) PPC_WEAK_FUNC(sub_82166180);
PPC_FUNC_IMPL(__imp__sub_82166180) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r6,-1
	ctx.r11.s64 = ctx.r6.s64 + -1;
	// std r4,192(r1)
	PPC_STORE_U64(ctx.r1.u32 + 192, ctx.r4.u64);
	// std r5,200(r1)
	PPC_STORE_U64(ctx.r1.u32 + 200, ctx.r5.u64);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x82166424
	if (ctx.cr6.gt) goto loc_82166424;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x82166250
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82166250;
	// bdzf 4*cr6+eq,0x821662ec
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_821662EC;
	// bne cr6,0x82166388
	if (!ctx.cr6.eq) goto loc_82166388;
	// lfs f0,204(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 204);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lfs f13,196(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f12,200(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	ctx.f12.f64 = double(temp.f32);
	// fadds f10,f0,f13
	ctx.f10.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lfs f9,192(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f9.f64 = double(temp.f32);
	// addi r9,r11,-2064
	ctx.r9.s64 = ctx.r11.s64 + -2064;
	// fadds f8,f9,f12
	ctx.f8.f64 = double(float(ctx.f9.f64 + ctx.f12.f64));
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lfs f0,-21836(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -21836);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,28(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,21768(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 21768);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,56(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	ctx.f11.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmuls f7,f10,f13
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fmuls f6,f10,f13
	ctx.f6.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// fmuls f5,f8,f13
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f13.f64));
	// stfs f11,120(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// fmuls f4,f8,f13
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f13.f64));
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f7,108(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f5,100(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f5,116(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f5,132(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f4,80(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f6,84(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x82166000
	ctx.lr = 0x82166240;
	sub_82166000(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82166250:
	// lfs f0,192(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lfs f13,200(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f12,204(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 204);
	ctx.f12.f64 = double(temp.f32);
	// fadds f10,f0,f13
	ctx.f10.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lfs f9,196(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	ctx.f9.f64 = double(temp.f32);
	// addi r9,r11,-2064
	ctx.r9.s64 = ctx.r11.s64 + -2064;
	// fadds f8,f12,f9
	ctx.f8.f64 = double(float(ctx.f12.f64 + ctx.f9.f64));
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lfs f12,21768(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 21768);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,28(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-21836(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -21836);
	ctx.f0.f64 = double(temp.f32);
	// lfs f11,56(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	ctx.f11.f64 = double(temp.f32);
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmuls f7,f10,f13
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// stfs f7,80(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmuls f6,f10,f13
	ctx.f6.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fmuls f5,f8,f13
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f13.f64));
	// stfs f5,84(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fmuls f4,f8,f13
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f13.f64));
	// stfs f11,112(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f6,100(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f4,108(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f4,124(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f4,140(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x82166000
	ctx.lr = 0x821662DC;
	sub_82166000(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_821662EC:
	// lfs f0,204(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 204);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lfs f13,196(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f12,200(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	ctx.f12.f64 = double(temp.f32);
	// fadds f10,f0,f13
	ctx.f10.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lfs f9,192(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f9.f64 = double(temp.f32);
	// addi r9,r11,-2064
	ctx.r9.s64 = ctx.r11.s64 + -2064;
	// fadds f8,f9,f12
	ctx.f8.f64 = double(float(ctx.f9.f64 + ctx.f12.f64));
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lfs f12,21768(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 21768);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,28(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,56(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	ctx.f0.f64 = double(temp.f32);
	// lfs f11,-21836(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -21836);
	ctx.f11.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmuls f7,f10,f13
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// stfs f7,84(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fmuls f6,f10,f13
	ctx.f6.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fmuls f5,f8,f13
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f13.f64));
	// stfs f5,80(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmuls f4,f8,f13
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f13.f64));
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f11,136(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f6,108(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f4,100(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f4,116(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f4,132(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x82166000
	ctx.lr = 0x82166378;
	sub_82166000(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82166388:
	// lfs f0,192(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lfs f13,200(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f12,204(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 204);
	ctx.f12.f64 = double(temp.f32);
	// fadds f10,f0,f13
	ctx.f10.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lfs f9,196(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	ctx.f9.f64 = double(temp.f32);
	// addi r9,r11,-2064
	ctx.r9.s64 = ctx.r11.s64 + -2064;
	// fadds f8,f12,f9
	ctx.f8.f64 = double(float(ctx.f12.f64 + ctx.f9.f64));
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lfs f12,21768(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 21768);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,28(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,56(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	ctx.f0.f64 = double(temp.f32);
	// lfs f11,-21836(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -21836);
	ctx.f11.f64 = double(temp.f32);
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmuls f7,f10,f13
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// stfs f7,80(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmuls f6,f10,f13
	ctx.f6.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fmuls f5,f8,f13
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f13.f64));
	// stfs f5,84(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fmuls f4,f8,f13
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f13.f64));
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f11,128(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f6,100(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f4,108(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f4,124(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f4,140(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x82166000
	ctx.lr = 0x82166414;
	sub_82166000(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82166424:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82166438"))) PPC_WEAK_FUNC(sub_82166438);
PPC_FUNC_IMPL(__imp__sub_82166438) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82166440;
	__savegprlr_27(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r4,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, ctx.r4.u32);
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// addi r4,r3,104
	ctx.r4.s64 = ctx.r3.s64 + 104;
	// addi r5,r1,188
	ctx.r5.s64 = ctx.r1.s64 + 188;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82078a90
	ctx.lr = 0x82166464;
	sub_82078A90(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r28,88(r1)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// beq cr6,0x8216647c
	if (ctx.cr6.eq) goto loc_8216647C;
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x82166480
	if (ctx.cr6.eq) goto loc_82166480;
loc_8216647C:
	// twi 31,r0,22
loc_82166480:
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r29,92(r1)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x821665dc
	if (ctx.cr6.eq) goto loc_821665DC;
	// ld r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
loc_82166498:
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821664ac
	if (ctx.cr6.eq) goto loc_821664AC;
	// cmplw cr6,r10,r28
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x821664b0
	if (ctx.cr6.eq) goto loc_821664B0;
loc_821664AC:
	// twi 31,r0,22
loc_821664B0:
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplw cr6,r9,r29
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x821665d0
	if (ctx.cr6.eq) goto loc_821665D0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x821664f4
	if (!ctx.cr6.eq) goto loc_821664F4;
	// twi 31,r0,22
	// li r11,0
	ctx.r11.s64 = 0;
loc_821664CC:
	// lwz r11,24(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x821664dc
	if (!ctx.cr6.eq) goto loc_821664DC;
	// twi 31,r0,22
loc_821664DC:
	// lwz r11,16(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// cmpw cr6,r11,r31
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r31.s32, ctx.xer);
	// beq cr6,0x821664fc
	if (ctx.cr6.eq) goto loc_821664FC;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82074418
	ctx.lr = 0x821664F0;
	sub_82074418(ctx, base);
	// b 0x82166498
	goto loc_82166498;
loc_821664F4:
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x821664cc
	goto loc_821664CC;
loc_821664FC:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x821665a4
	if (!ctx.cr6.eq) goto loc_821665A4;
	// twi 31,r0,22
	// li r11,0
	ctx.r11.s64 = 0;
loc_8216650C:
	// lwz r11,24(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8216651c
	if (!ctx.cr6.eq) goto loc_8216651C;
	// twi 31,r0,22
loc_8216651C:
	// lwz r3,20(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821665c4
	if (ctx.cr6.eq) goto loc_821665C4;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x821665ac
	if (!ctx.cr6.eq) goto loc_821665AC;
	// twi 31,r0,22
	// li r11,0
	ctx.r11.s64 = 0;
loc_82166538:
	// lwz r11,24(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82166548
	if (!ctx.cr6.eq) goto loc_82166548;
	// twi 31,r0,22
loc_82166548:
	// lbz r11,76(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 76);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821665c4
	if (ctx.cr6.eq) goto loc_821665C4;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x821665b4
	if (!ctx.cr6.eq) goto loc_821665B4;
	// twi 31,r0,22
	// li r11,0
	ctx.r11.s64 = 0;
loc_82166564:
	// lwz r11,24(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82166574
	if (!ctx.cr6.eq) goto loc_82166574;
	// twi 31,r0,22
loc_82166574:
	// lbz r11,78(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 78);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821665c4
	if (!ctx.cr6.eq) goto loc_821665C4;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x821665bc
	if (!ctx.cr6.eq) goto loc_821665BC;
	// twi 31,r0,22
loc_8216658C:
	// lwz r11,24(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82166608
	if (!ctx.cr6.eq) goto loc_82166608;
	// twi 31,r0,22
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_821665A4:
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x8216650c
	goto loc_8216650C;
loc_821665AC:
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x82166538
	goto loc_82166538;
loc_821665B4:
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x82166564
	goto loc_82166564;
loc_821665BC:
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x8216658c
	goto loc_8216658C;
loc_821665C4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_821665D0:
	// lbz r11,136(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + 136);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821665c4
	if (ctx.cr6.eq) goto loc_821665C4;
loc_821665DC:
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821665F4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// ld r4,96(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// ld r5,104(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// bl 0x82166180
	ctx.lr = 0x82166608;
	sub_82166180(ctx, base);
loc_82166608:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82166610"))) PPC_WEAK_FUNC(sub_82166610);
PPC_FUNC_IMPL(__imp__sub_82166610) {
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
	// addi r12,r1,-24
	ctx.r12.s64 = ctx.r1.s64 + -24;
	// bl 0x82080368
	ctx.lr = 0x82166628;
	__savefpr_28(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,84(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// std r4,184(r1)
	PPC_STORE_U64(ctx.r1.u32 + 184, ctx.r4.u64);
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r11,r11,-2064
	ctx.r11.s64 = ctx.r11.s64 + -2064;
	// lwz r31,16(r10)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lfs f30,128(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 128);
	ctx.f30.f64 = double(temp.f32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x821666dc
	if (ctx.cr6.eq) goto loc_821666DC;
	// lfs f29,188(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 188);
	ctx.f29.f64 = double(temp.f32);
	// lfs f28,184(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	ctx.f28.f64 = double(temp.f32);
	// lfs f31,28(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	ctx.f31.f64 = double(temp.f32);
loc_8216665C:
	// lbz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 76);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821666d0
	if (ctx.cr6.eq) goto loc_821666D0;
	// lbz r11,78(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 78);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821666d0
	if (!ctx.cr6.eq) goto loc_821666D0;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8216668C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,12(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// fadds f11,f0,f13
	ctx.f11.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lfs f10,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fadds f9,f12,f10
	ctx.f9.f64 = double(float(ctx.f12.f64 + ctx.f10.f64));
	// fmuls f8,f11,f31
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f31.f64));
	// fmuls f7,f9,f31
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f31.f64));
	// fsubs f6,f8,f28
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f28.f64));
	// fsubs f5,f7,f29
	ctx.f5.f64 = double(float(ctx.f7.f64 - ctx.f29.f64));
	// fabs f4,f6
	ctx.f4.u64 = ctx.f6.u64 & ~0x8000000000000000;
	// fabs f3,f5
	ctx.f3.u64 = ctx.f5.u64 & ~0x8000000000000000;
	// fadds f0,f4,f3
	ctx.f0.f64 = double(float(ctx.f4.f64 + ctx.f3.f64));
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// bge cr6,0x821666d0
	if (!ctx.cr6.lt) goto loc_821666D0;
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
	// fmr f30,f0
	ctx.f30.f64 = ctx.f0.f64;
loc_821666D0:
	// lwz r31,4(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8216665c
	if (!ctx.cr6.eq) goto loc_8216665C;
loc_821666DC:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// addi r12,r1,-24
	ctx.r12.s64 = ctx.r1.s64 + -24;
	// bl 0x820803b4
	ctx.lr = 0x821666EC;
	__restfpr_28(ctx, base);
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

__attribute__((alias("__imp__sub_82166700"))) PPC_WEAK_FUNC(sub_82166700);
PPC_FUNC_IMPL(__imp__sub_82166700) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82166708;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82166728
	if (ctx.cr6.eq) goto loc_82166728;
	// lbz r11,78(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 78);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82166834
	if (!ctx.cr6.eq) goto loc_82166834;
loc_82166728:
	// lwz r11,84(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 84);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8216675c
	if (ctx.cr6.eq) goto loc_8216675C;
loc_82166738:
	// lbz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 76);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82166750
	if (ctx.cr6.eq) goto loc_82166750;
	// lbz r10,77(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 77);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8216683c
	if (!ctx.cr6.eq) goto loc_8216683C;
loc_82166750:
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82166738
	if (!ctx.cr6.eq) goto loc_82166738;
loc_8216675C:
	// li r31,0
	ctx.r31.s64 = 0;
loc_82166760:
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x82166834
	if (ctx.cr6.eq) goto loc_82166834;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82166780;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x821667a8
	if (ctx.cr6.eq) goto loc_821667A8;
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r11,77(r31)
	PPC_STORE_U8(ctx.r31.u32 + 77, ctx.r11.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821667A8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_821667A8:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8216681c
	if (ctx.cr6.eq) goto loc_8216681C;
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// stb r11,77(r29)
	PPC_STORE_U8(ctx.r29.u32 + 77, ctx.r11.u8);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821667D0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r7,16(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x821667E8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// lfs f13,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,12(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// fadds f11,f0,f13
	ctx.f11.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lfs f10,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// addi r5,r6,-2064
	ctx.r5.s64 = ctx.r6.s64 + -2064;
	// fadds f9,f12,f10
	ctx.f9.f64 = double(float(ctx.f12.f64 + ctx.f10.f64));
	// lfs f0,28(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f8,f11,f0
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// stfs f8,96(r30)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r30.u32 + 96, temp.u32);
	// fmuls f7,f9,f0
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// stfs f7,100(r30)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r30.u32 + 100, temp.u32);
loc_8216681C:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82166834;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82166834:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_8216683C:
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
	// b 0x82166760
	goto loc_82166760;
}

__attribute__((alias("__imp__sub_82166844"))) PPC_WEAK_FUNC(sub_82166844);
PPC_FUNC_IMPL(__imp__sub_82166844) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82166848"))) PPC_WEAK_FUNC(sub_82166848);
PPC_FUNC_IMPL(__imp__sub_82166848) {
	PPC_FUNC_PROLOGUE();
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,72(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// b 0x82166700
	sub_82166700(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82166854"))) PPC_WEAK_FUNC(sub_82166854);
PPC_FUNC_IMPL(__imp__sub_82166854) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82166858"))) PPC_WEAK_FUNC(sub_82166858);
PPC_FUNC_IMPL(__imp__sub_82166858) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82166860;
	__savegprlr_29(ctx, base);
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,92(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 92);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82166c74
	if (ctx.cr6.eq) goto loc_82166C74;
	// lwz r11,76(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r9,r10,-2064
	ctx.r9.s64 = ctx.r10.s64 + -2064;
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// rlwinm r7,r8,0,19,19
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x1000;
	// lfs f31,28(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	ctx.f31.f64 = double(temp.f32);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x821669a8
	if (ctx.cr6.eq) goto loc_821669A8;
	// ld r9,228(r11)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r11.u32 + 228);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,-31312(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -31312);
	// addi r10,r11,76
	ctx.r10.s64 = ctx.r11.s64 + 76;
	// lwz r4,84(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// lwz r6,76(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r5,80(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// lwz r10,88(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// mr r9,r6
	ctx.r9.u64 = ctx.r6.u64;
	// stw r4,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r4.u32);
	// stw r6,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r6.u32);
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// stw r5,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r5.u32);
	// stw r10,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r10.u32);
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
	// lfs f12,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f12.f64 = double(temp.f32);
	// mr r5,r10
	ctx.r5.u64 = ctx.r10.u64;
	// lfs f11,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f11.f64 = double(temp.f32);
	// stw r4,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r4.u32);
	// stw r9,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r9.u32);
	// fsubs f7,f12,f11
	ctx.f7.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// stw r8,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r8.u32);
	// stw r10,12(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12, ctx.r10.u32);
	// lfs f10,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 - ctx.f9.f64));
	// fmuls f6,f8,f13
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f13.f64));
	// fmuls f5,f7,f0
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f0.f64));
	// fmuls f4,f6,f31
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f31.f64));
	// stfs f4,84(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fmuls f3,f5,f31
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f31.f64));
	// stfs f3,80(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x82165e78
	ctx.lr = 0x82166934;
	sub_82165E78(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8216694c
	if (ctx.cr6.eq) goto loc_8216694C;
	// lbz r11,79(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 79);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821669a0
	if (ctx.cr6.eq) goto loc_821669A0;
loc_8216694C:
	// lwz r11,84(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 84);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82166980
	if (ctx.cr6.eq) goto loc_82166980;
loc_8216695C:
	// lbz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 76);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82166974
	if (ctx.cr6.eq) goto loc_82166974;
	// lbz r10,77(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 77);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82166984
	if (!ctx.cr6.eq) goto loc_82166984;
loc_82166974:
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8216695c
	if (!ctx.cr6.eq) goto loc_8216695C;
loc_82166980:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82166984:
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x821669a8
	if (!ctx.cr6.eq) goto loc_821669A8;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821669a8
	if (ctx.cr6.eq) goto loc_821669A8;
	// lbz r11,78(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 78);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821669a8
	if (ctx.cr6.eq) goto loc_821669A8;
loc_821669A0:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82166700
	ctx.lr = 0x821669A8;
	sub_82166700(ctx, base);
loc_821669A8:
	// lwz r11,76(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 76);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// xor r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// and r7,r8,r10
	ctx.r7.u64 = ctx.r8.u64 & ctx.r10.u64;
	// clrlwi r6,r7,8
	ctx.r6.u64 = ctx.r7.u32 & 0xFFFFFF;
	// rlwinm r6,r6,0,20,17
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFFFFFFCFFF;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x82166a1c
	if (ctx.cr6.eq) goto loc_82166A1C;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r8,84(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 84);
	// rotlwi r9,r9,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// xor r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// and r6,r7,r10
	ctx.r6.u64 = ctx.r7.u64 & ctx.r10.u64;
	// lwz r31,16(r8)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// clrlwi r10,r6,8
	ctx.r10.u64 = ctx.r6.u32 & 0xFFFFFF;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// rlwinm r10,r10,0,20,17
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFCFFF;
	// beq cr6,0x82166a1c
	if (ctx.cr6.eq) goto loc_82166A1C;
loc_821669F4:
	// lbz r9,76(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 76);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82166a10
	if (ctx.cr6.eq) goto loc_82166A10;
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82166adc
	if (!ctx.cr6.eq) goto loc_82166ADC;
loc_82166A10:
	// lwz r31,4(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x821669f4
	if (!ctx.cr6.eq) goto loc_821669F4;
loc_82166A1C:
	// lwz r10,84(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 84);
	// lwz r31,16(r10)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82166a50
	if (ctx.cr6.eq) goto loc_82166A50;
loc_82166A2C:
	// lbz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 76);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82166a44
	if (ctx.cr6.eq) goto loc_82166A44;
	// lbz r10,77(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 77);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82166b00
	if (!ctx.cr6.eq) goto loc_82166B00;
loc_82166A44:
	// lwz r31,4(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82166a2c
	if (!ctx.cr6.eq) goto loc_82166A2C;
loc_82166A50:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82166A54:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// xor r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// and r7,r8,r10
	ctx.r7.u64 = ctx.r8.u64 & ctx.r10.u64;
	// rlwinm r5,r7,0,27,27
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82166a78
	if (ctx.cr6.eq) goto loc_82166A78;
	// li r6,1
	ctx.r6.s64 = 1;
loc_82166A78:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// xor r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// and r7,r8,r10
	ctx.r7.u64 = ctx.r8.u64 & ctx.r10.u64;
	// rlwinm r5,r7,0,26,26
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82166a98
	if (ctx.cr6.eq) goto loc_82166A98;
	// li r6,3
	ctx.r6.s64 = 3;
loc_82166A98:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// xor r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// and r7,r8,r10
	ctx.r7.u64 = ctx.r8.u64 & ctx.r10.u64;
	// rlwinm r5,r7,0,25,25
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82166ab8
	if (ctx.cr6.eq) goto loc_82166AB8;
	// li r6,4
	ctx.r6.s64 = 4;
loc_82166AB8:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// xor r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// and r7,r8,r10
	ctx.r7.u64 = ctx.r8.u64 & ctx.r10.u64;
	// rlwinm r5,r7,0,24,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82166bc8
	if (ctx.cr6.eq) goto loc_82166BC8;
	// li r6,2
	ctx.r6.s64 = 2;
	// b 0x82166bd0
	goto loc_82166BD0;
loc_82166ADC:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82166700
	ctx.lr = 0x82166AE8;
	sub_82166700(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82165db0
	ctx.lr = 0x82166AF4;
	sub_82165DB0(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_82166B00:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// xor r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// and r7,r8,r10
	ctx.r7.u64 = ctx.r8.u64 & ctx.r10.u64;
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x82166a54
	if (ctx.cr6.eq) goto loc_82166A54;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82166B34;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r30,r29,96
	ctx.r30.s64 = ctx.r29.s64 + 96;
	// lfs f0,8(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,12(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// fadds f11,f0,f13
	ctx.f11.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lfs f10,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fadds f9,f12,f10
	ctx.f9.f64 = double(float(ctx.f12.f64 + ctx.f10.f64));
	// fmuls f8,f11,f31
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f31.f64));
	// stfs f8,96(r29)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r29.u32 + 96, temp.u32);
	// fmuls f7,f9,f31
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f31.f64));
	// stfs f7,100(r29)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r29.u32 + 100, temp.u32);
	// bl 0x82165db0
	ctx.lr = 0x82166B70;
	sub_82165DB0(ctx, base);
	// lwz r8,84(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 84);
	// lwz r11,16(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82166ba4
	if (ctx.cr6.eq) goto loc_82166BA4;
loc_82166B80:
	// lbz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 76);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82166b98
	if (ctx.cr6.eq) goto loc_82166B98;
	// lbz r10,77(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 77);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82166c74
	if (!ctx.cr6.eq) goto loc_82166C74;
loc_82166B98:
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82166b80
	if (!ctx.cr6.eq) goto loc_82166B80;
loc_82166BA4:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// ld r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r30.u32 + 0);
	// bl 0x82166610
	ctx.lr = 0x82166BB0;
	sub_82166610(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82166700
	ctx.lr = 0x82166BBC;
	sub_82166700(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_82166BC8:
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq cr6,0x82166c60
	if (ctx.cr6.eq) goto loc_82166C60;
loc_82166BD0:
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bne cr6,0x82166c34
	if (!ctx.cr6.eq) goto loc_82166C34;
	// ld r11,96(r29)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r29.u32 + 96);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f12,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// ld r5,88(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f11,84(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x82166180
	ctx.lr = 0x82166C18;
	sub_82166180(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82166c48
	if (!ctx.cr6.eq) goto loc_82166C48;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// ld r4,96(r29)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r29.u32 + 96);
	// bl 0x82166610
	ctx.lr = 0x82166C30;
	sub_82166610(ctx, base);
	// b 0x82166c40
	goto loc_82166C40;
loc_82166C34:
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// bl 0x82166438
	ctx.lr = 0x82166C3C;
	sub_82166438(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_82166C40:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82166c60
	if (ctx.cr6.eq) goto loc_82166C60;
loc_82166C48:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82166700
	ctx.lr = 0x82166C54;
	sub_82166700(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_82166C60:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82166C74;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82166C74:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82166C80"))) PPC_WEAK_FUNC(sub_82166C80);
PPC_FUNC_IMPL(__imp__sub_82166C80) {
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
	// bl 0x82166610
	ctx.lr = 0x82166C98;
	sub_82166610(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82166700
	ctx.lr = 0x82166CA4;
	sub_82166700(ctx, base);
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

__attribute__((alias("__imp__sub_82166CB8"))) PPC_WEAK_FUNC(sub_82166CB8);
PPC_FUNC_IMPL(__imp__sub_82166CB8) {
	PPC_FUNC_PROLOGUE();
	// addi r9,r3,16
	ctx.r9.s64 = ctx.r3.s64 + 16;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// addi r8,r3,44
	ctx.r8.s64 = ctx.r3.s64 + 44;
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r11.u8);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// stw r9,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r9.u32);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// addi r5,r10,-1396
	ctx.r5.s64 = ctx.r10.s64 + -1396;
	// stb r11,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, ctx.r11.u8);
	// addi r9,r8,16
	ctx.r9.s64 = ctx.r8.s64 + 16;
	// stb r11,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r11.u8);
	// addi r4,r7,840
	ctx.r4.s64 = ctx.r7.s64 + 840;
	// stw r5,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r5.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r11,31(r3)
	PPC_STORE_U8(ctx.r3.u32 + 31, ctx.r11.u8);
	// addi r8,r6,6156
	ctx.r8.s64 = ctx.r6.s64 + 6156;
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r11.u32);
	// stb r11,30(r3)
	PPC_STORE_U8(ctx.r3.u32 + 30, ctx.r11.u8);
	// stw r4,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r4.u32);
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r11.u32);
	// stb r11,56(r3)
	PPC_STORE_U8(ctx.r3.u32 + 56, ctx.r11.u8);
	// stb r11,57(r3)
	PPC_STORE_U8(ctx.r3.u32 + 57, ctx.r11.u8);
	// stb r11,59(r3)
	PPC_STORE_U8(ctx.r3.u32 + 59, ctx.r11.u8);
	// stw r9,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r9.u32);
	// stw r11,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r11.u32);
	// stb r11,58(r3)
	PPC_STORE_U8(ctx.r3.u32 + 58, ctx.r11.u8);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stb r10,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r10.u8);
	// stb r10,57(r3)
	PPC_STORE_U8(ctx.r3.u32 + 57, ctx.r10.u8);
	// stw r11,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r11.u32);
	// stb r10,76(r3)
	PPC_STORE_U8(ctx.r3.u32 + 76, ctx.r10.u8);
	// stb r11,77(r3)
	PPC_STORE_U8(ctx.r3.u32 + 77, ctx.r11.u8);
	// stb r11,78(r3)
	PPC_STORE_U8(ctx.r3.u32 + 78, ctx.r11.u8);
	// stb r11,79(r3)
	PPC_STORE_U8(ctx.r3.u32 + 79, ctx.r11.u8);
	// stw r11,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82166D58"))) PPC_WEAK_FUNC(sub_82166D58);
PPC_FUNC_IMPL(__imp__sub_82166D58) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x82166D60;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,76(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82166dcc
	if (!ctx.cr6.eq) goto loc_82166DCC;
	// li r3,52
	ctx.r3.s64 = 52;
	// bl 0x82079fd8
	ctx.lr = 0x82166D80;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82166d90
	if (ctx.cr6.eq) goto loc_82166D90;
	// bl 0x82165ce0
	ctx.lr = 0x82166D8C;
	sub_82165CE0(ctx, base);
	// b 0x82166d94
	goto loc_82166D94;
loc_82166D90:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_82166D94:
	// stw r3,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82166DAC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// addi r10,r31,44
	ctx.r10.s64 = ctx.r31.s64 + 44;
	// stw r3,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r3.u32);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// lwz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r11.u32);
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
loc_82166DCC:
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82079fd8
	ctx.lr = 0x82166DD4;
	sub_82079FD8(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r29,r11,840
	ctx.r29.s64 = ctx.r11.s64 + 840;
	// beq cr6,0x82166e10
	if (ctx.cr6.eq) goto loc_82166E10;
	// addi r11,r3,16
	ctx.r11.s64 = ctx.r3.s64 + 16;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stb r30,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r30.u8);
	// stb r30,13(r3)
	PPC_STORE_U8(ctx.r3.u32 + 13, ctx.r30.u8);
	// stb r30,15(r3)
	PPC_STORE_U8(ctx.r3.u32 + 15, ctx.r30.u8);
	// stw r30,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r30.u32);
	// stb r30,14(r3)
	PPC_STORE_U8(ctx.r3.u32 + 14, ctx.r30.u8);
	// b 0x82166e14
	goto loc_82166E14;
loc_82166E10:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_82166E14:
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82079fd8
	ctx.lr = 0x82166E20;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82166e54
	if (ctx.cr6.eq) goto loc_82166E54;
	// addi r11,r3,16
	ctx.r11.s64 = ctx.r3.s64 + 16;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// stb r30,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r30.u8);
	// stb r30,13(r3)
	PPC_STORE_U8(ctx.r3.u32 + 13, ctx.r30.u8);
	// stb r30,15(r3)
	PPC_STORE_U8(ctx.r3.u32 + 15, ctx.r30.u8);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// stw r30,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r30.u32);
	// stb r30,14(r3)
	PPC_STORE_U8(ctx.r3.u32 + 14, ctx.r30.u8);
	// b 0x82166e58
	goto loc_82166E58;
loc_82166E54:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
loc_82166E58:
	// stw r10,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r10.u32);
	// addi r29,r31,44
	ctx.r29.s64 = ctx.r31.s64 + 44;
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r11.u32);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// lwz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// lbz r7,137(r31)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r31.u32 + 137);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x82166ec4
	if (!ctx.cr6.eq) goto loc_82166EC4;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82166EB0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32234
	ctx.r11.s64 = -2112487424;
	// addi r10,r11,26712
	ctx.r10.s64 = ctx.r11.s64 + 26712;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
loc_82166EC4:
	// li r11,1
	ctx.r11.s64 = 1;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// stb r11,59(r31)
	PPC_STORE_U8(ctx.r31.u32 + 59, ctx.r11.u8);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stb r11,31(r31)
	PPC_STORE_U8(ctx.r31.u32 + 31, ctx.r11.u8);
	// addi r4,r10,192
	ctx.r4.s64 = ctx.r10.s64 + 192;
	// bl 0x820735c8
	ctx.lr = 0x82166EE0;
	sub_820735C8(ctx, base);
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// addi r4,r9,13736
	ctx.r4.s64 = ctx.r9.s64 + 13736;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820735c8
	ctx.lr = 0x82166EF4;
	sub_820735C8(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// li r3,36
	ctx.r3.s64 = 36;
	// bl 0x82079fd8
	ctx.lr = 0x82166F00;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82166f40
	if (ctx.cr6.eq) goto loc_82166F40;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// stw r31,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r31.u32);
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// addi r9,r11,6224
	ctx.r9.s64 = ctx.r11.s64 + 6224;
	// stb r30,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r30.u8);
	// addi r8,r10,-29768
	ctx.r8.s64 = ctx.r10.s64 + -29768;
	// stw r30,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r30.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// stb r30,24(r3)
	PPC_STORE_U8(ctx.r3.u32 + 24, ctx.r30.u8);
	// stb r30,25(r3)
	PPC_STORE_U8(ctx.r3.u32 + 25, ctx.r30.u8);
	// stw r8,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r8.u32);
	// b 0x82166f44
	goto loc_82166F44;
loc_82166F40:
	// mr r27,r30
	ctx.r27.u64 = ctx.r30.u64;
loc_82166F44:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r4,r11,2952
	ctx.r4.s64 = ctx.r11.s64 + 2952;
	// bl 0x820735c8
	ctx.lr = 0x82166F54;
	sub_820735C8(ctx, base);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r4,r10,13752
	ctx.r4.s64 = ctx.r10.s64 + 13752;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820735c8
	ctx.lr = 0x82166F68;
	sub_820735C8(ctx, base);
	// lwz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r10,r28,4
	ctx.r10.s64 = ctx.r28.s64 + 4;
	// addi r9,r25,4
	ctx.r9.s64 = ctx.r25.s64 + 4;
	// stw r3,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r3.u32);
	// addi r8,r31,16
	ctx.r8.s64 = ctx.r31.s64 + 16;
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// addi r11,r27,4
	ctx.r11.s64 = ctx.r27.s64 + 4;
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
	// lwz r7,36(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// stw r28,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r28.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// addi r10,r26,4
	ctx.r10.s64 = ctx.r26.s64 + 4;
	// stw r30,4(r28)
	PPC_STORE_U32(ctx.r28.u32 + 4, ctx.r30.u32);
	// lwz r6,36(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// stw r27,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r27.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// lis r11,-32234
	ctx.r11.s64 = -2112487424;
	// stw r30,4(r27)
	PPC_STORE_U32(ctx.r27.u32 + 4, ctx.r30.u32);
	// lwz r5,36(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// stw r25,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r25.u32);
	// stw r9,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r9.u32);
	// stw r30,4(r25)
	PPC_STORE_U32(ctx.r25.u32 + 4, ctx.r30.u32);
	// lwz r4,36(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// stw r26,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r26.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// addi r10,r11,26712
	ctx.r10.s64 = ctx.r11.s64 + 26712;
	// stw r30,4(r26)
	PPC_STORE_U32(ctx.r26.u32 + 4, ctx.r30.u32);
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82166FE4"))) PPC_WEAK_FUNC(sub_82166FE4);
PPC_FUNC_IMPL(__imp__sub_82166FE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82166FE8"))) PPC_WEAK_FUNC(sub_82166FE8);
PPC_FUNC_IMPL(__imp__sub_82166FE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82166FF0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r3,16
	ctx.r11.s64 = ctx.r3.s64 + 16;
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stb r30,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r30.u8);
	// addi r10,r3,44
	ctx.r10.s64 = ctx.r3.s64 + 44;
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r11.u32);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stw r30,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r30.u32);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// stb r30,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, ctx.r30.u8);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// stb r30,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r30.u8);
	// stb r30,31(r3)
	PPC_STORE_U8(ctx.r3.u32 + 31, ctx.r30.u8);
	// addi r5,r9,-1396
	ctx.r5.s64 = ctx.r9.s64 + -1396;
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// stw r30,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r30.u32);
	// addi r3,r8,840
	ctx.r3.s64 = ctx.r8.s64 + 840;
	// stw r5,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r5.u32);
	// li r28,1
	ctx.r28.s64 = 1;
	// stb r30,30(r31)
	PPC_STORE_U8(ctx.r31.u32 + 30, ctx.r30.u8);
	// addi r10,r7,6188
	ctx.r10.s64 = ctx.r7.s64 + 6188;
	// stw r3,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r3.u32);
	// stw r30,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
	// lfs f0,21768(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// stb r30,56(r31)
	PPC_STORE_U8(ctx.r31.u32 + 56, ctx.r30.u8);
	// li r3,4
	ctx.r3.s64 = 4;
	// stb r30,57(r31)
	PPC_STORE_U8(ctx.r31.u32 + 57, ctx.r30.u8);
	// addi r29,r31,104
	ctx.r29.s64 = ctx.r31.s64 + 104;
	// stb r30,59(r31)
	PPC_STORE_U8(ctx.r31.u32 + 59, ctx.r30.u8);
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// stw r30,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r30.u32);
	// stb r30,58(r31)
	PPC_STORE_U8(ctx.r31.u32 + 58, ctx.r30.u8);
	// stb r28,29(r31)
	PPC_STORE_U8(ctx.r31.u32 + 29, ctx.r28.u8);
	// stb r28,57(r31)
	PPC_STORE_U8(ctx.r31.u32 + 57, ctx.r28.u8);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r4,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r4.u32);
	// stw r30,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r30.u32);
	// stb r28,92(r31)
	PPC_STORE_U8(ctx.r31.u32 + 92, ctx.r28.u8);
	// stfs f0,96(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 96, temp.u32);
	// stfs f0,100(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 100, temp.u32);
	// bl 0x82079fd8
	ctx.lr = 0x821670A4;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821670b4
	if (ctx.cr6.eq) goto loc_821670B4;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// b 0x821670b8
	goto loc_821670B8;
loc_821670B4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_821670B8:
	// stw r3,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82079fd8
	ctx.lr = 0x821670C4;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821670d0
	if (ctx.cr6.eq) goto loc_821670D0;
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
loc_821670D0:
	// addic. r11,r3,4
	ctx.xer.ca = ctx.r3.u32 > 4294967291;
	ctx.r11.s64 = ctx.r3.s64 + 4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x821670dc
	if (ctx.cr0.eq) goto loc_821670DC;
	// stw r30,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r30.u32);
loc_821670DC:
	// addic. r11,r3,8
	ctx.xer.ca = ctx.r3.u32 > 4294967287;
	ctx.r11.s64 = ctx.r3.s64 + 8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x821670e8
	if (ctx.cr0.eq) goto loc_821670E8;
	// stw r30,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r30.u32);
loc_821670E8:
	// stb r28,24(r3)
	PPC_STORE_U8(ctx.r3.u32 + 24, ctx.r28.u8);
	// lis r11,-32234
	ctx.r11.s64 = -2112487424;
	// stb r30,25(r3)
	PPC_STORE_U8(ctx.r3.u32 + 25, ctx.r30.u8);
	// stw r3,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r3.u32);
	// addi r10,r11,27992
	ctx.r10.s64 = ctx.r11.s64 + 27992;
	// stb r28,25(r3)
	PPC_STORE_U8(ctx.r3.u32 + 25, ctx.r28.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r9,24(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// stw r9,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r9.u32);
	// lwz r8,24(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// stw r8,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r8.u32);
	// lwz r7,24(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// stw r7,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r7.u32);
	// stw r30,28(r29)
	PPC_STORE_U32(ctx.r29.u32 + 28, ctx.r30.u32);
	// stb r30,136(r31)
	PPC_STORE_U8(ctx.r31.u32 + 136, ctx.r30.u8);
	// stb r30,137(r31)
	PPC_STORE_U8(ctx.r31.u32 + 137, ctx.r30.u8);
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82167134"))) PPC_WEAK_FUNC(sub_82167134);
PPC_FUNC_IMPL(__imp__sub_82167134) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82167138"))) PPC_WEAK_FUNC(sub_82167138);
PPC_FUNC_IMPL(__imp__sub_82167138) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r10,-1
	ctx.r10.s64 = -1;
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// addic r8,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r8.s64 = ctx.r9.s64 + -1;
	// subfe r3,r8,r9
	temp.u8 = (~ctx.r8.u32 + ctx.r9.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ~ctx.r8.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82167150"))) PPC_WEAK_FUNC(sub_82167150);
PPC_FUNC_IMPL(__imp__sub_82167150) {
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
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8216717c
	if (ctx.cr6.eq) goto loc_8216717C;
	// bl 0x82088d00
	ctx.lr = 0x82167174;
	sub_82088D00(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
loc_8216717C:
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

__attribute__((alias("__imp__sub_82167190"))) PPC_WEAK_FUNC(sub_82167190);
PPC_FUNC_IMPL(__imp__sub_82167190) {
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
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// addi r10,r11,6152
	ctx.r10.s64 = ctx.r11.s64 + 6152;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// beq cr6,0x821671c8
	if (ctx.cr6.eq) goto loc_821671C8;
	// bl 0x82088d00
	ctx.lr = 0x821671C0;
	sub_82088D00(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
loc_821671C8:
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

__attribute__((alias("__imp__sub_821671DC"))) PPC_WEAK_FUNC(sub_821671DC);
PPC_FUNC_IMPL(__imp__sub_821671DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821671E0"))) PPC_WEAK_FUNC(sub_821671E0);
PPC_FUNC_IMPL(__imp__sub_821671E0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821671E8"))) PPC_WEAK_FUNC(sub_821671E8);
PPC_FUNC_IMPL(__imp__sub_821671E8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821671F0"))) PPC_WEAK_FUNC(sub_821671F0);
PPC_FUNC_IMPL(__imp__sub_821671F0) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r9,r10,6148
	ctx.r9.s64 = ctx.r10.s64 + 6148;
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// b 0x8207a8a0
	sub_8207A8A0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82167208"))) PPC_WEAK_FUNC(sub_82167208);
PPC_FUNC_IMPL(__imp__sub_82167208) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82167210;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r27,0
	ctx.r27.s64 = 0;
	// addi r10,r11,6148
	ctx.r10.s64 = ctx.r11.s64 + 6148;
	// stw r27,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r27.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// lwz r9,24(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// addi r30,r4,4
	ctx.r30.s64 = ctx.r4.s64 + 4;
	// blt cr6,0x82167248
	if (ctx.cr6.lt) goto loc_82167248;
	// lwz r3,4(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// b 0x8216724c
	goto loc_8216724C;
loc_82167248:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_8216724C:
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,128
	ctx.r8.s64 = 128;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// lis r4,-32768
	ctx.r4.s64 = -2147483648;
	// bl 0x820891f8
	ctx.lr = 0x82167268;
	sub_820891F8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x821672b0
	if (ctx.cr6.eq) goto loc_821672B0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x820893f0
	ctx.lr = 0x8216727C;
	sub_820893F0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,8(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8, ctx.r3.u32);
	// beq cr6,0x821672a8
	if (ctx.cr6.eq) goto loc_821672A8;
	// bl 0x8207a030
	ctx.lr = 0x8216728C;
	sub_8207A030(ctx, base);
	// stw r3,4(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4, ctx.r3.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r5,8(r29)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82089890
	ctx.lr = 0x821672A8;
	sub_82089890(ctx, base);
loc_821672A8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82088d00
	ctx.lr = 0x821672B0;
	sub_82088D00(ctx, base);
loc_821672B0:
	// lwz r11,24(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821672c4
	if (ctx.cr6.lt) goto loc_821672C4;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x821672C4;
	sub_8207A630(ctx, base);
loc_821672C4:
	// li r11,15
	ctx.r11.s64 = 15;
	// stw r27,20(r28)
	PPC_STORE_U32(ctx.r28.u32 + 20, ctx.r27.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r11,24(r28)
	PPC_STORE_U32(ctx.r28.u32 + 24, ctx.r11.u32);
	// stb r27,0(r30)
	PPC_STORE_U8(ctx.r30.u32 + 0, ctx.r27.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821672E0"))) PPC_WEAK_FUNC(sub_821672E0);
PPC_FUNC_IMPL(__imp__sub_821672E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f11,f12
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// lfs f8,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f10,f0
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// fmuls f6,f8,f13
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f13.f64));
	// fmsubs f5,f13,f0,f9
	ctx.f5.f64 = double(float(ctx.f13.f64 * ctx.f0.f64 - ctx.f9.f64));
	// stfs f5,0(r5)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// fmsubs f4,f8,f11,f7
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f11.f64 - ctx.f7.f64));
	// stfs f4,8(r5)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r5.u32 + 8, temp.u32);
	// fmsubs f3,f10,f12,f6
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f12.f64 - ctx.f6.f64));
	// stfs f3,4(r5)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r5.u32 + 4, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82167320"))) PPC_WEAK_FUNC(sub_82167320);
PPC_FUNC_IMPL(__imp__sub_82167320) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f0,f1
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f1.f64));
	// stfs f13,0(r4)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// lfs f12,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f12,f1
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f1.f64));
	// stfs f11,4(r4)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// lfs f10,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f10,f1
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f1.f64));
	// stfs f9,8(r4)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r4.u32 + 8, temp.u32);
	// lfs f8,12(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f8,f1
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f1.f64));
	// stfs f7,12(r4)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r4.u32 + 12, temp.u32);
	// lfs f6,16(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f5,f6,f2
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f2.f64));
	// stfs f5,16(r4)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r4.u32 + 16, temp.u32);
	// lfs f4,20(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f3,f4,f2
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f2.f64));
	// stfs f3,20(r4)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r4.u32 + 20, temp.u32);
	// lfs f1,24(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	ctx.f1.f64 = double(temp.f32);
	// fmuls f0,f1,f2
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f2.f64));
	// stfs f0,24(r4)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 24, temp.u32);
	// lfs f13,28(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f2
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f2.f64));
	// stfs f12,28(r4)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r4.u32 + 28, temp.u32);
	// lfs f11,32(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,32(r4)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r4.u32 + 32, temp.u32);
	// lfs f10,36(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,36(r4)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r4.u32 + 36, temp.u32);
	// lfs f9,40(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,40(r4)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r4.u32 + 40, temp.u32);
	// lfs f8,44(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,44(r4)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r4.u32 + 44, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821673A4"))) PPC_WEAK_FUNC(sub_821673A4);
PPC_FUNC_IMPL(__imp__sub_821673A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821673A8"))) PPC_WEAK_FUNC(sub_821673A8);
PPC_FUNC_IMPL(__imp__sub_821673A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// fneg f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stfs f0,4(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f2,0(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stfs f1,16(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f2,20(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// lfs f0,21768(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-21836(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -21836);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,8(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f0,12(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f0,24(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stfs f0,28(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stfs f0,32(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// stfs f0,36(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stfs f13,40(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stfs f0,44(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821673F0"))) PPC_WEAK_FUNC(sub_821673F0);
PPC_FUNC_IMPL(__imp__sub_821673F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// cmplw cr6,r3,r4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x82167440
	if (ctx.cr6.eq) goto loc_82167440;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r4)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// lfs f13,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,4(r4)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// lfs f12,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,8(r4)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r4.u32 + 8, temp.u32);
	// lfs f11,16(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,16(r4)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r4.u32 + 16, temp.u32);
	// lfs f10,20(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,20(r4)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r4.u32 + 20, temp.u32);
	// lfs f9,24(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,24(r4)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r4.u32 + 24, temp.u32);
	// lfs f8,32(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,32(r4)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r4.u32 + 32, temp.u32);
	// lfs f7,36(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,36(r4)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r4.u32 + 36, temp.u32);
	// lfs f6,40(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,40(r4)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r4.u32 + 40, temp.u32);
loc_82167440:
	// lfs f0,12(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f0,f1
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f1.f64));
	// stfs f13,12(r4)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r4.u32 + 12, temp.u32);
	// lfs f12,28(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	ctx.f12.f64 = double(temp.f32);
	// fadds f11,f12,f2
	ctx.f11.f64 = double(float(ctx.f12.f64 + ctx.f2.f64));
	// stfs f11,28(r4)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r4.u32 + 28, temp.u32);
	// lfs f10,44(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,44(r4)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r4.u32 + 44, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82167464"))) PPC_WEAK_FUNC(sub_82167464);
PPC_FUNC_IMPL(__imp__sub_82167464) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82167468"))) PPC_WEAK_FUNC(sub_82167468);
PPC_FUNC_IMPL(__imp__sub_82167468) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f13,-21836(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -21836);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,21768(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,0(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stfs f0,4(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f0,8(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f0,12(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f0,16(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f13,20(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f0,24(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stfs f0,28(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stfs f0,32(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// stfs f0,36(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stfs f13,40(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stfs f0,44(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821674AC"))) PPC_WEAK_FUNC(sub_821674AC);
PPC_FUNC_IMPL(__imp__sub_821674AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821674B0"))) PPC_WEAK_FUNC(sub_821674B0);
PPC_FUNC_IMPL(__imp__sub_821674B0) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r5,48
	ctx.r5.s64 = 48;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x8207dac0
	sub_8207DAC0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821674C4"))) PPC_WEAK_FUNC(sub_821674C4);
PPC_FUNC_IMPL(__imp__sub_821674C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821674C8"))) PPC_WEAK_FUNC(sub_821674C8);
PPC_FUNC_IMPL(__imp__sub_821674C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// fmuls f13,f0,f0
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f0.f64));
	// lfs f12,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,-21836(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -21836);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f10,f12,f12,f13
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f13.f64));
	// fmadds f9,f11,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f10.f64));
	// fsqrts f8,f9
	ctx.f8.f64 = double(float(sqrt(ctx.f9.f64)));
	// fdivs f7,f0,f8
	ctx.f7.f64 = double(float(ctx.f0.f64 / ctx.f8.f64));
	// fmuls f6,f12,f7
	ctx.f6.f64 = double(float(ctx.f12.f64 * ctx.f7.f64));
	// stfs f6,0(r4)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// lfs f5,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f4,f5,f7
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f7.f64));
	// stfs f4,4(r4)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// lfs f3,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f3.f64 = double(temp.f32);
	// fmuls f2,f7,f3
	ctx.f2.f64 = double(float(ctx.f7.f64 * ctx.f3.f64));
	// stfs f2,8(r4)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r4.u32 + 8, temp.u32);
	// blr 
	return;
}

