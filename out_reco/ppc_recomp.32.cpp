#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_88243950"))) PPC_WEAK_FUNC(sub_88243950);
PPC_FUNC_IMPL(__imp__sub_88243950) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88243958;
	__savegprlr_29(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x880968b8
	ctx.lr = 0x88243974;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x882439c8
	if (ctx.cr6.eq) goto loc_882439C8;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// bne cr6,0x882439bc
	if (!ctx.cr6.eq) goto loc_882439BC;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// bgt 0x882439bc
	if (ctx.cr0.gt) goto loc_882439BC;
	// lis r11,-30684
	ctx.r11.s64 = -2010906624;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,15808
	ctx.r4.s64 = ctx.r11.s64 + 15808;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x880969a8
	ctx.lr = 0x882439B0;
	sub_880969A8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88096830
	ctx.lr = 0x882439BC;
	sub_88096830(ctx, base);
loc_882439BC:
	// li r3,1
	ctx.r3.s64 = 1;
loc_882439C0:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_882439C8:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x882439f4
	if (ctx.cr6.eq) goto loc_882439F4;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x882439bc
	if (ctx.cr0.gt) goto loc_882439BC;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_882439F4:
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// clrlwi r30,r10,31
	ctx.r30.u64 = ctx.r10.u32 & 0x1;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// bge 0x882439bc
	if (!ctx.cr0.lt) goto loc_882439BC;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r11,r11,-32
	ctx.r11.s64 = ctx.r11.s64 + -32;
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// cmpwi cr6,r11,64
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 64, ctx.xer);
	// bgt cr6,0x88243a28
	if (ctx.cr6.gt) goto loc_88243A28;
	// li r11,64
	ctx.r11.s64 = 64;
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_88243A28:
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// beq cr6,0x88243a48
	if (ctx.cr6.eq) goto loc_88243A48;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
loc_88243A48:
	// lis r11,-30686
	ctx.r11.s64 = -2011037696;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,12544
	ctx.r4.s64 = ctx.r11.s64 + 12544;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88097078
	ctx.lr = 0x88243A5C;
	sub_88097078(ctx, base);
	// addi r10,r30,6
	ctx.r10.s64 = ctx.r30.s64 + 6;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r3,r9,r31
	PPC_STORE_U32(ctx.r9.u32 + ctx.r31.u32, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addic. r11,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r11.s64 = ctx.r8.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// stw r7,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r7.u32);
	// bgt 0x882439c0
	if (ctx.cr0.gt) goto loc_882439C0;
	// li r11,10
	ctx.r11.s64 = 10;
	// li r10,96
	ctx.r10.s64 = 96;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88243AA0"))) PPC_WEAK_FUNC(sub_88243AA0);
PPC_FUNC_IMPL(__imp__sub_88243AA0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x88243AA8;
	__savegprlr_26(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lwz r26,2304(r3)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x880968b8
	ctx.lr = 0x88243ACC;
	sub_880968B8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r11,8
	ctx.r11.s64 = 8;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r10,112
	ctx.r10.s64 = 112;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stw r30,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// stw r30,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// stw r10,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r10.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// lwz r5,12(r26)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r26.u32 + 12);
	// lwz r4,8(r26)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r26.u32 + 8);
	// bl 0x88095590
	ctx.lr = 0x88243B00;
	sub_88095590(ctx, base);
	// li r9,1
	ctx.r9.s64 = 1;
	// cmpwi cr6,r3,256
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 256, ctx.xer);
	// stw r9,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
	// blt cr6,0x88243b14
	if (ctx.cr6.lt) goto loc_88243B14;
	// stw r30,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r30.u32);
loc_88243B14:
	// lis r11,-30706
	ctx.r11.s64 = -2012348416;
	// lwz r10,5728(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 5728);
	// li r9,4
	ctx.r9.s64 = 4;
	// addi r8,r11,-16944
	ctx.r8.s64 = ctx.r11.s64 + -16944;
	// lis r7,120
	ctx.r7.s64 = 7864320;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lis r6,360
	ctx.r6.s64 = 23592960;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// cmpw cr6,r10,r8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, ctx.xer);
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// beq cr6,0x88243b54
	if (ctx.cr6.eq) goto loc_88243B54;
	// lis r11,-30706
	ctx.r11.s64 = -2012348416;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-16944
	ctx.r4.s64 = ctx.r11.s64 + -16944;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x880966a8
	ctx.lr = 0x88243B54;
	sub_880966A8(ctx, base);
loc_88243B54:
	// stw r30,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r30.u32);
	// lis r11,-30684
	ctx.r11.s64 = -2010906624;
	// stw r30,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r30.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r5,r11,14672
	ctx.r5.s64 = ctx.r11.s64 + 14672;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88096950
	ctx.lr = 0x88243B70;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88243B7C"))) PPC_WEAK_FUNC(sub_88243B7C);
PPC_FUNC_IMPL(__imp__sub_88243B7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88243B80"))) PPC_WEAK_FUNC(sub_88243B80);
PPC_FUNC_IMPL(__imp__sub_88243B80) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x88243B88;
	__savegprlr_27(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x88243BAC;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bgt cr6,0x88243d2c
	if (ctx.cr6.gt) goto loc_88243D2C;
	// beq cr6,0x88243cf0
	if (ctx.cr6.eq) goto loc_88243CF0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88243c3c
	if (ctx.cr6.eq) goto loc_88243C3C;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// bne cr6,0x88243db0
	if (!ctx.cr6.eq) goto loc_88243DB0;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// bgt 0x88243db0
	if (ctx.cr0.gt) goto loc_88243DB0;
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r10,-30686
	ctx.r10.s64 = -2011037696;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,10344
	ctx.r4.s64 = ctx.r10.s64 + 10344;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x88243BFC;
	sub_88097078(ctx, base);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// lis r8,-30686
	ctx.r8.s64 = -2011037696;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,10344
	ctx.r4.s64 = ctx.r8.s64 + 10344;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x88243C1C;
	sub_88097078(ctx, base);
	// li r7,20
	ctx.r7.s64 = 20;
	// li r6,192
	ctx.r6.s64 = 192;
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// stw r7,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r6,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r6.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_88243C3C:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88243db0
	if (ctx.cr0.gt) goto loc_88243DB0;
	// lis r11,-30706
	ctx.r11.s64 = -2012348416;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,1920
	ctx.r4.s64 = ctx.r11.s64 + 1920;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096cb8
	ctx.lr = 0x88243C60;
	sub_88096CB8(ctx, base);
	// lis r10,-30706
	ctx.r10.s64 = -2012348416;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,1776
	ctx.r4.s64 = ctx.r10.s64 + 1776;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096cb8
	ctx.lr = 0x88243C74;
	sub_88096CB8(ctx, base);
	// lis r11,100
	ctx.r11.s64 = 6553600;
	// li r9,8
	ctx.r9.s64 = 8;
	// mr r7,r11
	ctx.r7.u64 = ctx.r11.u64;
	// mr r6,r11
	ctx.r6.u64 = ctx.r11.u64;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// li r10,4
	ctx.r10.s64 = 4;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r3,32
	ctx.r3.s64 = 32;
	// li r4,10
	ctx.r4.s64 = 10;
	// lwz r30,8(r28)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8);
	// lwz r11,2304(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 2304);
	// lwz r28,12(r28)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// subf r6,r6,r30
	ctx.r6.s64 = ctx.r30.s64 - ctx.r6.s64;
	// add r5,r30,r5
	ctx.r5.u64 = ctx.r30.u64 + ctx.r5.u64;
	// subf r7,r7,r28
	ctx.r7.s64 = ctx.r28.s64 - ctx.r7.s64;
	// stw r6,152(r11)
	PPC_STORE_U32(ctx.r11.u32 + 152, ctx.r6.u32);
	// stw r7,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r7.u32);
	// stw r9,144(r11)
	PPC_STORE_U32(ctx.r11.u32 + 144, ctx.r9.u32);
	// stw r10,164(r11)
	PPC_STORE_U32(ctx.r11.u32 + 164, ctx.r10.u32);
	// stw r8,148(r11)
	PPC_STORE_U32(ctx.r11.u32 + 148, ctx.r8.u32);
	// lwz r11,2304(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 2304);
	// stw r5,524(r11)
	PPC_STORE_U32(ctx.r11.u32 + 524, ctx.r5.u32);
	// stw r7,528(r11)
	PPC_STORE_U32(ctx.r11.u32 + 528, ctx.r7.u32);
	// stw r9,516(r11)
	PPC_STORE_U32(ctx.r11.u32 + 516, ctx.r9.u32);
	// stw r10,536(r11)
	PPC_STORE_U32(ctx.r11.u32 + 536, ctx.r10.u32);
	// stw r8,520(r11)
	PPC_STORE_U32(ctx.r11.u32 + 520, ctx.r8.u32);
	// stw r3,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r4,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r4.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_88243CF0:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88243db0
	if (ctx.cr0.gt) goto loc_88243DB0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096dd0
	ctx.lr = 0x88243D0C;
	sub_88096DD0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x88096dd0
	ctx.lr = 0x88243D18;
	sub_88096DD0(ctx, base);
	// li r11,30
	ctx.r11.s64 = 30;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_88243D2C:
	// cmpwi cr6,r11,30
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 30, ctx.xer);
	// beq cr6,0x88243d78
	if (ctx.cr6.eq) goto loc_88243D78;
	// cmpwi cr6,r11,40
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 40, ctx.xer);
	// bne cr6,0x88243db0
	if (!ctx.cr6.eq) goto loc_88243DB0;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88243db0
	if (ctx.cr0.gt) goto loc_88243DB0;
	// lis r11,-30684
	ctx.r11.s64 = -2010906624;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,15008
	ctx.r4.s64 = ctx.r11.s64 + 15008;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880969a8
	ctx.lr = 0x88243D60;
	sub_880969A8(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096830
	ctx.lr = 0x88243D6C;
	sub_88096830(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_88243D78:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096e28
	ctx.lr = 0x88243D84;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88243db0
	if (!ctx.cr6.eq) goto loc_88243DB0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x88096e28
	ctx.lr = 0x88243D98;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88243db0
	if (!ctx.cr6.eq) goto loc_88243DB0;
	// li r11,16
	ctx.r11.s64 = 16;
	// li r10,40
	ctx.r10.s64 = 40;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
loc_88243DB0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88243DBC"))) PPC_WEAK_FUNC(sub_88243DBC);
PPC_FUNC_IMPL(__imp__sub_88243DBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88243DC0"))) PPC_WEAK_FUNC(sub_88243DC0);
PPC_FUNC_IMPL(__imp__sub_88243DC0) {
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
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// bl 0x880968b8
	ctx.lr = 0x88243DEC;
	sub_880968B8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,96
	ctx.r9.s64 = 96;
	// li r8,4
	ctx.r8.s64 = 4;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// lis r7,120
	ctx.r7.s64 = 7864320;
	// lis r6,360
	ctx.r6.s64 = 23592960;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// lis r4,-30706
	ctx.r4.s64 = -2012348416;
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r4,-16944
	ctx.r4.s64 = ctx.r4.s64 + -16944;
	// bl 0x880966a8
	ctx.lr = 0x88243E2C;
	sub_880966A8(ctx, base);
	// lis r3,-30684
	ctx.r3.s64 = -2010906624;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r3,15232
	ctx.r5.s64 = ctx.r3.s64 + 15232;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096950
	ctx.lr = 0x88243E40;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
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

__attribute__((alias("__imp__sub_88243E5C"))) PPC_WEAK_FUNC(sub_88243E5C);
PPC_FUNC_IMPL(__imp__sub_88243E5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88243E60"))) PPC_WEAK_FUNC(sub_88243E60);
PPC_FUNC_IMPL(__imp__sub_88243E60) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88243E68;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x88243E88;
	sub_880968B8(ctx, base);
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x88243fec
	if (ctx.cr6.lt) goto loc_88243FEC;
	// beq cr6,0x88243f28
	if (ctx.cr6.eq) goto loc_88243F28;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x88244068
	if (!ctx.cr6.lt) goto loc_88244068;
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// addi r9,r11,-29576
	ctx.r9.s64 = ctx.r11.s64 + -29576;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x88244068
	if (!ctx.cr6.eq) goto loc_88244068;
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88243ff8
	if (!ctx.cr6.eq) goto loc_88243FF8;
	// li r29,1
	ctx.r29.s64 = 1;
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// bl 0x881534c8
	ctx.lr = 0x88243ED4;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r11,r11,11
	ctx.r11.s64 = ctx.r11.s64 + 11;
	// rlwinm r10,r11,19,0,12
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 19) & 0xFFF80000;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x881534c8
	ctx.lr = 0x88243EEC;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lis r9,-30685
	ctx.r9.s64 = -2010972160;
	// addi r8,r11,32
	ctx.r8.s64 = ctx.r11.s64 + 32;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// rlwinm r7,r8,19,0,12
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 19) & 0xFFF80000;
	// addi r4,r9,-27968
	ctx.r4.s64 = ctx.r9.s64 + -27968;
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x88243F10;
	sub_880966A8(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r29,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r29.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r6,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r6.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_88243F28:
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// addi r9,r11,-29576
	ctx.r9.s64 = ctx.r11.s64 + -29576;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x88244068
	if (!ctx.cr6.eq) goto loc_88244068;
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88243ff8
	if (!ctx.cr6.eq) goto loc_88243FF8;
	// lwz r11,68(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 68);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88243f64
	if (ctx.cr6.eq) goto loc_88243F64;
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// bgt 0x88243f90
	if (ctx.cr0.gt) goto loc_88243F90;
loc_88243F64:
	// lis r11,-30684
	ctx.r11.s64 = -2010906624;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,17368
	ctx.r4.s64 = ctx.r11.s64 + 17368;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880969a8
	ctx.lr = 0x88243F78;
	sub_880969A8(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096830
	ctx.lr = 0x88243F84;
	sub_88096830(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_88243F90:
	// lwz r11,60(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 60);
	// lis r10,200
	ctx.r10.s64 = 13107200;
	// clrlwi r9,r11,31
	ctx.r9.u64 = ctx.r11.u32 & 0x1;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x88243fb0
	if (ctx.cr6.eq) goto loc_88243FB0;
	// lis r11,40
	ctx.r11.s64 = 2621440;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
loc_88243FB0:
	// lis r11,248
	ctx.r11.s64 = 16252928;
	// lis r10,-30685
	ctx.r10.s64 = -2010972160;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-28240
	ctx.r4.s64 = ctx.r10.s64 + -28240;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x88243FCC;
	sub_880966A8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r9,16
	ctx.r9.s64 = 16;
	// stw r11,64(r29)
	PPC_STORE_U32(ctx.r29.u32 + 64, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r9.u32);
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_88243FEC:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88244018
	if (ctx.cr6.eq) goto loc_88244018;
loc_88243FF8:
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// bgt 0x88244068
	if (ctx.cr0.gt) goto loc_88244068;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_88244018:
	// lis r11,-30687
	ctx.r11.s64 = -2011103232;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-2440
	ctx.r4.s64 = ctx.r11.s64 + -2440;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x8824402C;
	sub_88097078(ctx, base);
	// lwz r11,60(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 60);
	// li r10,96
	ctx.r10.s64 = 96;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stw r9,60(r29)
	PPC_STORE_U32(ctx.r29.u32 + 60, ctx.r9.u32);
	// stw r10,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r10.u32);
	// lwz r8,68(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 68);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x88244060
	if (ctx.cr6.eq) goto loc_88244060;
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x88244060
	if (!ctx.cr6.eq) goto loc_88244060;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
loc_88244060:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
loc_88244068:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88244074"))) PPC_WEAK_FUNC(sub_88244074);
PPC_FUNC_IMPL(__imp__sub_88244074) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88244078"))) PPC_WEAK_FUNC(sub_88244078);
PPC_FUNC_IMPL(__imp__sub_88244078) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x88244080;
	__savegprlr_27(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lwz r27,2304(r3)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r5,40
	ctx.r5.s64 = 40;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x880968b8
	ctx.lr = 0x882440A0;
	sub_880968B8(ctx, base);
	// li r30,0
	ctx.r30.s64 = 0;
	// li r11,128
	ctx.r11.s64 = 128;
	// li r10,16
	ctx.r10.s64 = 16;
	// stw r30,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r30.u32);
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// lis r9,200
	ctx.r9.s64 = 13107200;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// stw r30,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r30.u32);
	// stw r10,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r10.u32);
	// lwz r8,60(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 60);
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x882440e8
	if (ctx.cr6.eq) goto loc_882440E8;
	// lis r11,40
	ctx.r11.s64 = 2621440;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
loc_882440E8:
	// lis r11,248
	ctx.r11.s64 = 16252928;
	// lis r10,-30685
	ctx.r10.s64 = -2010972160;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-28240
	ctx.r4.s64 = ctx.r10.s64 + -28240;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x880966a8
	ctx.lr = 0x88244104;
	sub_880966A8(ctx, base);
	// li r11,2
	ctx.r11.s64 = 2;
	// li r9,96
	ctx.r9.s64 = 96;
	// stw r30,64(r27)
	PPC_STORE_U32(ctx.r27.u32 + 64, ctx.r30.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// lis r8,-30684
	ctx.r8.s64 = -2010906624;
	// stw r30,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// stw r9,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
	// addi r5,r8,15968
	ctx.r5.s64 = ctx.r8.s64 + 15968;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88096950
	ctx.lr = 0x88244134;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88244140"))) PPC_WEAK_FUNC(sub_88244140);
PPC_FUNC_IMPL(__imp__sub_88244140) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x88244148;
	__savegprlr_25(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x88244168;
	sub_880968B8(ctx, base);
	// lwz r11,40(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r25,0
	ctx.r25.s64 = 0;
	// li r26,3
	ctx.r26.s64 = 3;
	// li r28,1
	ctx.r28.s64 = 1;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x88244254
	if (ctx.cr6.lt) goto loc_88244254;
	// bne cr6,0x88244260
	if (!ctx.cr6.eq) goto loc_88244260;
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// addi r9,r11,-29576
	ctx.r9.s64 = ctx.r11.s64 + -29576;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x88244260
	if (!ctx.cr6.eq) goto loc_88244260;
	// lwz r11,44(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x882441bc
	if (ctx.cr6.eq) goto loc_882441BC;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r11.u32);
	// bgt 0x88244260
	if (ctx.cr0.gt) goto loc_88244260;
	// stw r25,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r25.u32);
	// b 0x88244260
	goto loc_88244260;
loc_882441BC:
	// lwz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// lis r10,304
	ctx.r10.s64 = 19922944;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x88244260
	if (!ctx.cr6.lt) goto loc_88244260;
	// li r3,8
	ctx.r3.s64 = 8;
	// stw r26,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r26.u32);
	// bl 0x881534c8
	ctx.lr = 0x882441D8;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lwz r9,8(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// lis r10,120
	ctx.r10.s64 = 7864320;
	// addi r8,r11,8
	ctx.r8.s64 = ctx.r11.s64 + 8;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// rlwinm r11,r8,19,0,12
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 19) & 0xFFF80000;
	// blt cr6,0x882441f8
	if (ctx.cr6.lt) goto loc_882441F8;
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
loc_882441F8:
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// li r3,10
	ctx.r3.s64 = 10;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bl 0x881534c8
	ctx.lr = 0x88244208;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lis r10,-30685
	ctx.r10.s64 = -2010972160;
	// addi r9,r11,40
	ctx.r9.s64 = ctx.r11.s64 + 40;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// rlwinm r8,r9,19,0,12
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 19) & 0xFFF80000;
	// addi r4,r10,-27968
	ctx.r4.s64 = ctx.r10.s64 + -27968;
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x8824422C;
	sub_880966A8(ctx, base);
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// li r3,16
	ctx.r3.s64 = 16;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r7,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r7.u32);
	// bl 0x881534c8
	ctx.lr = 0x88244240;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// addi r6,r11,24
	ctx.r6.s64 = ctx.r11.s64 + 24;
	// rlwinm r5,r6,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r5,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r5.u32);
	// b 0x8824425c
	goto loc_8824425C;
loc_88244254:
	// li r11,16
	ctx.r11.s64 = 16;
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
loc_8824425C:
	// stw r28,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r28.u32);
loc_88244260:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x882443cc
	if (ctx.cr6.gt) goto loc_882443CC;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x882442f4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_882442F4;
	// bdzf 4*cr6+eq,0x88244368
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_88244368;
	// bne cr6,0x882443a0
	if (!ctx.cr6.eq) goto loc_882443A0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096e28
	ctx.lr = 0x8824428C;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x882443cc
	if (!ctx.cr6.eq) goto loc_882443CC;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x882442bc
	if (ctx.cr6.eq) goto loc_882442BC;
loc_882442A0:
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x882443cc
	if (ctx.cr0.gt) goto loc_882443CC;
	// stw r25,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r25.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_882442BC:
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r28,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// lis r10,-30687
	ctx.r10.s64 = -2011103232;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-2312
	ctx.r4.s64 = ctx.r10.s64 + -2312;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x882442DC;
	sub_88097078(ctx, base);
	// li r9,96
	ctx.r9.s64 = 96;
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_882442F4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096e28
	ctx.lr = 0x88244300;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x882443cc
	if (!ctx.cr6.eq) goto loc_882443CC;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x882442a0
	if (!ctx.cr6.eq) goto loc_882442A0;
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lis r10,-30687
	ctx.r10.s64 = -2011103232;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-3200
	ctx.r4.s64 = ctx.r10.s64 + -3200;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x88097078
	ctx.lr = 0x88244330;
	sub_88097078(ctx, base);
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// lis r8,-30687
	ctx.r8.s64 = -2011103232;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,-3368
	ctx.r4.s64 = ctx.r8.s64 + -3368;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x88097078
	ctx.lr = 0x88244350;
	sub_88097078(ctx, base);
	// li r7,2
	ctx.r7.s64 = 2;
	// stw r3,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r7,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_88244368:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// bl 0x88096e28
	ctx.lr = 0x88244374;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x882443cc
	if (!ctx.cr6.eq) goto loc_882443CC;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x88096dd0
	ctx.lr = 0x88244388;
	sub_88096DD0(ctx, base);
	// li r11,64
	ctx.r11.s64 = 64;
	// stw r26,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r26.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_882443A0:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x882442a0
	if (!ctx.cr6.eq) goto loc_882442A0;
	// lis r11,-30684
	ctx.r11.s64 = -2010906624;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,16504
	ctx.r4.s64 = ctx.r11.s64 + 16504;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880969a8
	ctx.lr = 0x882443C0;
	sub_880969A8(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096830
	ctx.lr = 0x882443CC;
	sub_88096830(ctx, base);
loc_882443CC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_882443D8"))) PPC_WEAK_FUNC(sub_882443D8);
PPC_FUNC_IMPL(__imp__sub_882443D8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x882443E0;
	__savegprlr_29(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,72
	ctx.r5.s64 = 72;
	// bl 0x880968b8
	ctx.lr = 0x882443FC;
	sub_880968B8(ctx, base);
	// lis r9,-30671
	ctx.r9.s64 = -2010054656;
	// lis r8,16838
	ctx.r8.s64 = 1103495168;
	// li r11,0
	ctx.r11.s64 = 0;
	// ori r7,r8,20077
	ctx.r7.u64 = ctx.r8.u64 | 20077;
	// li r6,128
	ctx.r6.s64 = 128;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// lwz r10,4200(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4200);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// li r5,3
	ctx.r5.s64 = 3;
	// mullw r10,r10,r7
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r11.u32);
	// stw r6,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r6.u32);
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// addi r10,r10,12345
	ctx.r10.s64 = ctx.r10.s64 + 12345;
	// lis r4,96
	ctx.r4.s64 = 6291456;
	// stw r10,4200(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4200, ctx.r10.u32);
	// lis r3,240
	ctx.r3.s64 = 15728640;
	// lhz r10,4200(r9)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4200);
	// clrlwi r11,r10,31
	ctx.r11.u64 = ctx.r10.u32 & 0x1;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r10,-30685
	ctx.r10.s64 = -2010972160;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,48(r29)
	PPC_STORE_U32(ctx.r29.u32 + 48, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-27968
	ctx.r4.s64 = ctx.r10.s64 + -27968;
	// bl 0x880966a8
	ctx.lr = 0x88244470;
	sub_880966A8(ctx, base);
	// li r11,20
	ctx.r11.s64 = 20;
	// li r9,4
	ctx.r9.s64 = 4;
	// stw r11,32(r29)
	PPC_STORE_U32(ctx.r29.u32 + 32, ctx.r11.u32);
	// lis r8,-30684
	ctx.r8.s64 = -2010906624;
	// stw r9,28(r29)
	PPC_STORE_U32(ctx.r29.u32 + 28, ctx.r9.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r11,36(r29)
	PPC_STORE_U32(ctx.r29.u32 + 36, ctx.r11.u32);
	// addi r5,r8,16704
	ctx.r5.s64 = ctx.r8.s64 + 16704;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096950
	ctx.lr = 0x88244498;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_882444A4"))) PPC_WEAK_FUNC(sub_882444A4);
PPC_FUNC_IMPL(__imp__sub_882444A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_882444A8"))) PPC_WEAK_FUNC(sub_882444A8);
PPC_FUNC_IMPL(__imp__sub_882444A8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x882444B0;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x882444D0;
	sub_880968B8(ctx, base);
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x88244668
	if (ctx.cr6.lt) goto loc_88244668;
	// beq cr6,0x88244570
	if (ctx.cr6.eq) goto loc_88244570;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x882446e4
	if (!ctx.cr6.lt) goto loc_882446E4;
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// addi r9,r11,-29576
	ctx.r9.s64 = ctx.r11.s64 + -29576;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x882446e4
	if (!ctx.cr6.eq) goto loc_882446E4;
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88244674
	if (!ctx.cr6.eq) goto loc_88244674;
	// li r29,1
	ctx.r29.s64 = 1;
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// bl 0x881534c8
	ctx.lr = 0x8824451C;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r11,r11,11
	ctx.r11.s64 = ctx.r11.s64 + 11;
	// rlwinm r10,r11,19,0,12
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 19) & 0xFFF80000;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x881534c8
	ctx.lr = 0x88244534;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lis r9,-30685
	ctx.r9.s64 = -2010972160;
	// addi r8,r11,32
	ctx.r8.s64 = ctx.r11.s64 + 32;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// rlwinm r7,r8,19,0,12
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 19) & 0xFFF80000;
	// addi r4,r9,-27968
	ctx.r4.s64 = ctx.r9.s64 + -27968;
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x88244558;
	sub_880966A8(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r29,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r29.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r6,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r6.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_88244570:
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// addi r9,r11,-29576
	ctx.r9.s64 = ctx.r11.s64 + -29576;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x882446e4
	if (!ctx.cr6.eq) goto loc_882446E4;
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88244674
	if (!ctx.cr6.eq) goto loc_88244674;
	// lwz r11,68(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 68);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88244634
	if (ctx.cr6.eq) goto loc_88244634;
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// bgt 0x882445d8
	if (ctx.cr0.gt) goto loc_882445D8;
	// lis r11,-30684
	ctx.r11.s64 = -2010906624;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,19024
	ctx.r4.s64 = ctx.r11.s64 + 19024;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880969a8
	ctx.lr = 0x882445C0;
	sub_880969A8(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096830
	ctx.lr = 0x882445CC;
	sub_88096830(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_882445D8:
	// lwz r11,60(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 60);
	// lis r10,200
	ctx.r10.s64 = 13107200;
	// clrlwi r9,r11,31
	ctx.r9.u64 = ctx.r11.u32 & 0x1;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x882445f8
	if (ctx.cr6.eq) goto loc_882445F8;
	// lis r11,40
	ctx.r11.s64 = 2621440;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
loc_882445F8:
	// lis r11,248
	ctx.r11.s64 = 16252928;
	// lis r10,-30685
	ctx.r10.s64 = -2010972160;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-28240
	ctx.r4.s64 = ctx.r10.s64 + -28240;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x88244614;
	sub_880966A8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r9,16
	ctx.r9.s64 = 16;
	// stw r11,64(r29)
	PPC_STORE_U32(ctx.r29.u32 + 64, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r9.u32);
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_88244634:
	// li r11,1
	ctx.r11.s64 = 1;
	// lis r10,-30684
	ctx.r10.s64 = -2010906624;
	// stw r11,68(r29)
	PPC_STORE_U32(ctx.r29.u32 + 68, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,19024
	ctx.r4.s64 = ctx.r10.s64 + 19024;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880969a8
	ctx.lr = 0x88244650;
	sub_880969A8(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096830
	ctx.lr = 0x8824465C;
	sub_88096830(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_88244668:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88244694
	if (ctx.cr6.eq) goto loc_88244694;
loc_88244674:
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// bgt 0x882446e4
	if (ctx.cr0.gt) goto loc_882446E4;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_88244694:
	// lis r11,-30687
	ctx.r11.s64 = -2011103232;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-528
	ctx.r4.s64 = ctx.r11.s64 + -528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x882446A8;
	sub_88097078(ctx, base);
	// lwz r11,60(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 60);
	// li r10,96
	ctx.r10.s64 = 96;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stw r9,60(r29)
	PPC_STORE_U32(ctx.r29.u32 + 60, ctx.r9.u32);
	// stw r10,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r10.u32);
	// lwz r8,68(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 68);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x882446dc
	if (ctx.cr6.eq) goto loc_882446DC;
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x882446dc
	if (!ctx.cr6.eq) goto loc_882446DC;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
loc_882446DC:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
loc_882446E4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_882446F0"))) PPC_WEAK_FUNC(sub_882446F0);
PPC_FUNC_IMPL(__imp__sub_882446F0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x882446F8;
	__savegprlr_27(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lwz r27,2304(r3)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r5,40
	ctx.r5.s64 = 40;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x880968b8
	ctx.lr = 0x88244718;
	sub_880968B8(ctx, base);
	// li r30,0
	ctx.r30.s64 = 0;
	// li r11,128
	ctx.r11.s64 = 128;
	// li r10,16
	ctx.r10.s64 = 16;
	// stw r30,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r30.u32);
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// lis r9,200
	ctx.r9.s64 = 13107200;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// stw r30,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r30.u32);
	// stw r10,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r10.u32);
	// lwz r8,60(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 60);
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x88244760
	if (ctx.cr6.eq) goto loc_88244760;
	// lis r11,40
	ctx.r11.s64 = 2621440;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
loc_88244760:
	// lis r11,248
	ctx.r11.s64 = 16252928;
	// lis r10,-30685
	ctx.r10.s64 = -2010972160;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-28240
	ctx.r4.s64 = ctx.r10.s64 + -28240;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x880966a8
	ctx.lr = 0x8824477C;
	sub_880966A8(ctx, base);
	// li r11,2
	ctx.r11.s64 = 2;
	// li r9,96
	ctx.r9.s64 = 96;
	// stw r30,64(r27)
	PPC_STORE_U32(ctx.r27.u32 + 64, ctx.r30.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// lis r8,-30684
	ctx.r8.s64 = -2010906624;
	// stw r30,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// stw r9,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
	// addi r5,r8,17576
	ctx.r5.s64 = ctx.r8.s64 + 17576;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88096950
	ctx.lr = 0x882447AC;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_882447B8"))) PPC_WEAK_FUNC(sub_882447B8);
PPC_FUNC_IMPL(__imp__sub_882447B8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x882447C0;
	__savegprlr_25(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x882447E0;
	sub_880968B8(ctx, base);
	// lwz r11,40(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r25,0
	ctx.r25.s64 = 0;
	// li r26,3
	ctx.r26.s64 = 3;
	// li r28,1
	ctx.r28.s64 = 1;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x882448cc
	if (ctx.cr6.lt) goto loc_882448CC;
	// bne cr6,0x882448d8
	if (!ctx.cr6.eq) goto loc_882448D8;
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// addi r9,r11,-29576
	ctx.r9.s64 = ctx.r11.s64 + -29576;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x882448d8
	if (!ctx.cr6.eq) goto loc_882448D8;
	// lwz r11,44(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88244834
	if (ctx.cr6.eq) goto loc_88244834;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r11.u32);
	// bgt 0x882448d8
	if (ctx.cr0.gt) goto loc_882448D8;
	// stw r25,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r25.u32);
	// b 0x882448d8
	goto loc_882448D8;
loc_88244834:
	// lwz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// lis r10,304
	ctx.r10.s64 = 19922944;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x882448d8
	if (!ctx.cr6.lt) goto loc_882448D8;
	// li r3,8
	ctx.r3.s64 = 8;
	// stw r26,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r26.u32);
	// bl 0x881534c8
	ctx.lr = 0x88244850;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lwz r9,8(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// lis r10,120
	ctx.r10.s64 = 7864320;
	// addi r8,r11,8
	ctx.r8.s64 = ctx.r11.s64 + 8;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// rlwinm r11,r8,19,0,12
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 19) & 0xFFF80000;
	// blt cr6,0x88244870
	if (ctx.cr6.lt) goto loc_88244870;
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
loc_88244870:
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// li r3,10
	ctx.r3.s64 = 10;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bl 0x881534c8
	ctx.lr = 0x88244880;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lis r10,-30685
	ctx.r10.s64 = -2010972160;
	// addi r9,r11,40
	ctx.r9.s64 = ctx.r11.s64 + 40;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// rlwinm r8,r9,19,0,12
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 19) & 0xFFF80000;
	// addi r4,r10,-27968
	ctx.r4.s64 = ctx.r10.s64 + -27968;
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x882448A4;
	sub_880966A8(ctx, base);
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// li r3,16
	ctx.r3.s64 = 16;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r7,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r7.u32);
	// bl 0x881534c8
	ctx.lr = 0x882448B8;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// addi r6,r11,24
	ctx.r6.s64 = ctx.r11.s64 + 24;
	// rlwinm r5,r6,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r5,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r5.u32);
	// b 0x882448d4
	goto loc_882448D4;
loc_882448CC:
	// li r11,16
	ctx.r11.s64 = 16;
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
loc_882448D4:
	// stw r28,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r28.u32);
loc_882448D8:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x88244a44
	if (ctx.cr6.gt) goto loc_88244A44;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x8824496c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8824496C;
	// bdzf 4*cr6+eq,0x882449e0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_882449E0;
	// bne cr6,0x88244a18
	if (!ctx.cr6.eq) goto loc_88244A18;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096e28
	ctx.lr = 0x88244904;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88244a44
	if (!ctx.cr6.eq) goto loc_88244A44;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88244934
	if (ctx.cr6.eq) goto loc_88244934;
loc_88244918:
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88244a44
	if (ctx.cr0.gt) goto loc_88244A44;
	// stw r25,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r25.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_88244934:
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r28,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// lis r10,-30687
	ctx.r10.s64 = -2011103232;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-400
	ctx.r4.s64 = ctx.r10.s64 + -400;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x88244954;
	sub_88097078(ctx, base);
	// li r9,96
	ctx.r9.s64 = 96;
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_8824496C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096e28
	ctx.lr = 0x88244978;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88244a44
	if (!ctx.cr6.eq) goto loc_88244A44;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88244918
	if (!ctx.cr6.eq) goto loc_88244918;
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lis r10,-30687
	ctx.r10.s64 = -2011103232;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-1120
	ctx.r4.s64 = ctx.r10.s64 + -1120;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x88097078
	ctx.lr = 0x882449A8;
	sub_88097078(ctx, base);
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// lis r8,-30687
	ctx.r8.s64 = -2011103232;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,-1272
	ctx.r4.s64 = ctx.r8.s64 + -1272;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x88097078
	ctx.lr = 0x882449C8;
	sub_88097078(ctx, base);
	// li r7,2
	ctx.r7.s64 = 2;
	// stw r3,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r7,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_882449E0:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// bl 0x88096e28
	ctx.lr = 0x882449EC;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88244a44
	if (!ctx.cr6.eq) goto loc_88244A44;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x88096dd0
	ctx.lr = 0x88244A00;
	sub_88096DD0(ctx, base);
	// li r11,64
	ctx.r11.s64 = 64;
	// stw r26,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r26.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_88244A18:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88244918
	if (!ctx.cr6.eq) goto loc_88244918;
	// lis r11,-30684
	ctx.r11.s64 = -2010906624;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,18160
	ctx.r4.s64 = ctx.r11.s64 + 18160;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880969a8
	ctx.lr = 0x88244A38;
	sub_880969A8(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096830
	ctx.lr = 0x88244A44;
	sub_88096830(ctx, base);
loc_88244A44:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88244A50"))) PPC_WEAK_FUNC(sub_88244A50);
PPC_FUNC_IMPL(__imp__sub_88244A50) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88244A58;
	__savegprlr_29(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,72
	ctx.r5.s64 = 72;
	// bl 0x880968b8
	ctx.lr = 0x88244A74;
	sub_880968B8(ctx, base);
	// lis r9,-30671
	ctx.r9.s64 = -2010054656;
	// lis r8,16838
	ctx.r8.s64 = 1103495168;
	// li r11,0
	ctx.r11.s64 = 0;
	// ori r7,r8,20077
	ctx.r7.u64 = ctx.r8.u64 | 20077;
	// li r6,128
	ctx.r6.s64 = 128;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// lwz r10,4200(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4200);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// li r5,3
	ctx.r5.s64 = 3;
	// mullw r10,r10,r7
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r11.u32);
	// stw r6,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r6.u32);
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// addi r10,r10,12345
	ctx.r10.s64 = ctx.r10.s64 + 12345;
	// lis r4,96
	ctx.r4.s64 = 6291456;
	// stw r10,4200(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4200, ctx.r10.u32);
	// lis r3,240
	ctx.r3.s64 = 15728640;
	// lhz r10,4200(r9)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4200);
	// clrlwi r11,r10,31
	ctx.r11.u64 = ctx.r10.u32 & 0x1;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r10,-30685
	ctx.r10.s64 = -2010972160;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,48(r29)
	PPC_STORE_U32(ctx.r29.u32 + 48, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-27968
	ctx.r4.s64 = ctx.r10.s64 + -27968;
	// bl 0x880966a8
	ctx.lr = 0x88244AE8;
	sub_880966A8(ctx, base);
	// li r9,4
	ctx.r9.s64 = 4;
	// li r8,10
	ctx.r8.s64 = 10;
	// li r7,5
	ctx.r7.s64 = 5;
	// stw r9,28(r29)
	PPC_STORE_U32(ctx.r29.u32 + 28, ctx.r9.u32);
	// stw r8,32(r29)
	PPC_STORE_U32(ctx.r29.u32 + 32, ctx.r8.u32);
	// lis r6,-30684
	ctx.r6.s64 = -2010906624;
	// stw r7,36(r29)
	PPC_STORE_U32(ctx.r29.u32 + 36, ctx.r7.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r6,18360
	ctx.r5.s64 = ctx.r6.s64 + 18360;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096950
	ctx.lr = 0x88244B14;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88244B20"))) PPC_WEAK_FUNC(sub_88244B20);
PPC_FUNC_IMPL(__imp__sub_88244B20) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88244B28;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x88244B48;
	sub_880968B8(ctx, base);
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x88244ce0
	if (ctx.cr6.lt) goto loc_88244CE0;
	// beq cr6,0x88244be8
	if (ctx.cr6.eq) goto loc_88244BE8;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x88244d5c
	if (!ctx.cr6.lt) goto loc_88244D5C;
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// addi r9,r11,-29576
	ctx.r9.s64 = ctx.r11.s64 + -29576;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x88244d5c
	if (!ctx.cr6.eq) goto loc_88244D5C;
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88244cec
	if (!ctx.cr6.eq) goto loc_88244CEC;
	// li r29,1
	ctx.r29.s64 = 1;
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// bl 0x881534c8
	ctx.lr = 0x88244B94;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r11,r11,11
	ctx.r11.s64 = ctx.r11.s64 + 11;
	// rlwinm r10,r11,19,0,12
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 19) & 0xFFF80000;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x881534c8
	ctx.lr = 0x88244BAC;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lis r9,-30685
	ctx.r9.s64 = -2010972160;
	// addi r8,r11,32
	ctx.r8.s64 = ctx.r11.s64 + 32;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// rlwinm r7,r8,19,0,12
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 19) & 0xFFF80000;
	// addi r4,r9,-27968
	ctx.r4.s64 = ctx.r9.s64 + -27968;
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x88244BD0;
	sub_880966A8(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r29,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r29.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r6,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r6.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_88244BE8:
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// addi r9,r11,-29576
	ctx.r9.s64 = ctx.r11.s64 + -29576;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x88244d5c
	if (!ctx.cr6.eq) goto loc_88244D5C;
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88244cec
	if (!ctx.cr6.eq) goto loc_88244CEC;
	// lwz r11,68(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 68);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88244cac
	if (ctx.cr6.eq) goto loc_88244CAC;
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// bgt 0x88244c50
	if (ctx.cr0.gt) goto loc_88244C50;
	// lis r11,-30684
	ctx.r11.s64 = -2010906624;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,20784
	ctx.r4.s64 = ctx.r11.s64 + 20784;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880969a8
	ctx.lr = 0x88244C38;
	sub_880969A8(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096830
	ctx.lr = 0x88244C44;
	sub_88096830(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_88244C50:
	// lwz r11,60(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 60);
	// lis r10,200
	ctx.r10.s64 = 13107200;
	// clrlwi r9,r11,31
	ctx.r9.u64 = ctx.r11.u32 & 0x1;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x88244c70
	if (ctx.cr6.eq) goto loc_88244C70;
	// lis r11,40
	ctx.r11.s64 = 2621440;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
loc_88244C70:
	// lis r11,248
	ctx.r11.s64 = 16252928;
	// lis r10,-30685
	ctx.r10.s64 = -2010972160;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-28240
	ctx.r4.s64 = ctx.r10.s64 + -28240;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x88244C8C;
	sub_880966A8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r9,16
	ctx.r9.s64 = 16;
	// stw r11,64(r29)
	PPC_STORE_U32(ctx.r29.u32 + 64, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r9.u32);
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_88244CAC:
	// li r11,1
	ctx.r11.s64 = 1;
	// lis r10,-30684
	ctx.r10.s64 = -2010906624;
	// stw r11,68(r29)
	PPC_STORE_U32(ctx.r29.u32 + 68, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,20784
	ctx.r4.s64 = ctx.r10.s64 + 20784;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880969a8
	ctx.lr = 0x88244CC8;
	sub_880969A8(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096830
	ctx.lr = 0x88244CD4;
	sub_88096830(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_88244CE0:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88244d0c
	if (ctx.cr6.eq) goto loc_88244D0C;
loc_88244CEC:
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// bgt 0x88244d5c
	if (ctx.cr0.gt) goto loc_88244D5C;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_88244D0C:
	// lis r11,-30687
	ctx.r11.s64 = -2011103232;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,2184
	ctx.r4.s64 = ctx.r11.s64 + 2184;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x88244D20;
	sub_88097078(ctx, base);
	// lwz r11,60(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 60);
	// li r10,96
	ctx.r10.s64 = 96;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stw r9,60(r29)
	PPC_STORE_U32(ctx.r29.u32 + 60, ctx.r9.u32);
	// stw r10,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r10.u32);
	// lwz r8,68(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 68);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x88244d54
	if (ctx.cr6.eq) goto loc_88244D54;
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x88244d54
	if (!ctx.cr6.eq) goto loc_88244D54;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
loc_88244D54:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
loc_88244D5C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88244D68"))) PPC_WEAK_FUNC(sub_88244D68);
PPC_FUNC_IMPL(__imp__sub_88244D68) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x88244D70;
	__savegprlr_27(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lwz r27,2304(r3)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r5,40
	ctx.r5.s64 = 40;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x880968b8
	ctx.lr = 0x88244D90;
	sub_880968B8(ctx, base);
	// lis r10,-30671
	ctx.r10.s64 = -2010054656;
	// lis r9,16838
	ctx.r9.s64 = 1103495168;
	// li r30,0
	ctx.r30.s64 = 0;
	// ori r8,r9,20077
	ctx.r8.u64 = ctx.r9.u64 | 20077;
	// li r7,128
	ctx.r7.s64 = 128;
	// stw r30,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r30.u32);
	// lwz r11,4200(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4200);
	// li r6,16
	ctx.r6.s64 = 16;
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mullw r11,r11,r8
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r8.s32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// stw r30,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r30.u32);
	// stw r6,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r6.u32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// lis r5,200
	ctx.r5.s64 = 13107200;
	// stw r11,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r11.u32);
	// lhz r11,4200(r10)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// clrlwi r4,r11,24
	ctx.r4.u64 = ctx.r11.u32 & 0xFF;
	// clrlwi r3,r11,31
	ctx.r3.u64 = ctx.r11.u32 & 0x1;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// stw r4,60(r27)
	PPC_STORE_U32(ctx.r27.u32 + 60, ctx.r4.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x88244dfc
	if (ctx.cr6.eq) goto loc_88244DFC;
	// lis r11,40
	ctx.r11.s64 = 2621440;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
loc_88244DFC:
	// lis r11,248
	ctx.r11.s64 = 16252928;
	// lis r10,-30685
	ctx.r10.s64 = -2010972160;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-28240
	ctx.r4.s64 = ctx.r10.s64 + -28240;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x880966a8
	ctx.lr = 0x88244E18;
	sub_880966A8(ctx, base);
	// li r11,2
	ctx.r11.s64 = 2;
	// li r9,96
	ctx.r9.s64 = 96;
	// stw r30,64(r27)
	PPC_STORE_U32(ctx.r27.u32 + 64, ctx.r30.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// lis r8,-30684
	ctx.r8.s64 = -2010906624;
	// stw r30,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// stw r9,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
	// addi r5,r8,19232
	ctx.r5.s64 = ctx.r8.s64 + 19232;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88096950
	ctx.lr = 0x88244E48;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88244E54"))) PPC_WEAK_FUNC(sub_88244E54);
PPC_FUNC_IMPL(__imp__sub_88244E54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88244E58"))) PPC_WEAK_FUNC(sub_88244E58);
PPC_FUNC_IMPL(__imp__sub_88244E58) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x88244E60;
	__savegprlr_25(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x88244E80;
	sub_880968B8(ctx, base);
	// lwz r11,40(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r25,0
	ctx.r25.s64 = 0;
	// li r26,3
	ctx.r26.s64 = 3;
	// li r27,1
	ctx.r27.s64 = 1;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x88244f6c
	if (ctx.cr6.lt) goto loc_88244F6C;
	// bne cr6,0x88244f78
	if (!ctx.cr6.eq) goto loc_88244F78;
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// addi r9,r11,-29576
	ctx.r9.s64 = ctx.r11.s64 + -29576;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x88244f78
	if (!ctx.cr6.eq) goto loc_88244F78;
	// lwz r11,44(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88244ed4
	if (ctx.cr6.eq) goto loc_88244ED4;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r11.u32);
	// bgt 0x88244f78
	if (ctx.cr0.gt) goto loc_88244F78;
	// stw r25,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r25.u32);
	// b 0x88244f78
	goto loc_88244F78;
loc_88244ED4:
	// lwz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// lis r10,304
	ctx.r10.s64 = 19922944;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x88244f78
	if (!ctx.cr6.lt) goto loc_88244F78;
	// li r3,8
	ctx.r3.s64 = 8;
	// stw r26,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r26.u32);
	// bl 0x881534c8
	ctx.lr = 0x88244EF0;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lwz r9,8(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// lis r10,120
	ctx.r10.s64 = 7864320;
	// addi r8,r11,8
	ctx.r8.s64 = ctx.r11.s64 + 8;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// rlwinm r11,r8,19,0,12
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 19) & 0xFFF80000;
	// blt cr6,0x88244f10
	if (ctx.cr6.lt) goto loc_88244F10;
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
loc_88244F10:
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// li r3,10
	ctx.r3.s64 = 10;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bl 0x881534c8
	ctx.lr = 0x88244F20;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lis r10,-30685
	ctx.r10.s64 = -2010972160;
	// addi r9,r11,40
	ctx.r9.s64 = ctx.r11.s64 + 40;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// rlwinm r8,r9,19,0,12
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 19) & 0xFFF80000;
	// addi r4,r10,-27968
	ctx.r4.s64 = ctx.r10.s64 + -27968;
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x88244F44;
	sub_880966A8(ctx, base);
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// li r3,16
	ctx.r3.s64 = 16;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r7,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r7.u32);
	// bl 0x881534c8
	ctx.lr = 0x88244F58;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// addi r6,r11,24
	ctx.r6.s64 = ctx.r11.s64 + 24;
	// rlwinm r5,r6,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r5,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r5.u32);
	// b 0x88244f74
	goto loc_88244F74;
loc_88244F6C:
	// li r11,16
	ctx.r11.s64 = 16;
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
loc_88244F74:
	// stw r27,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r27.u32);
loc_88244F78:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x88245124
	if (ctx.cr6.gt) goto loc_88245124;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x88245050
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_88245050;
	// bdzf 4*cr6+eq,0x882450c4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_882450C4;
	// bne cr6,0x882450f8
	if (!ctx.cr6.eq) goto loc_882450F8;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096e28
	ctx.lr = 0x88244FA4;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88245124
	if (!ctx.cr6.eq) goto loc_88245124;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88244fd4
	if (ctx.cr6.eq) goto loc_88244FD4;
loc_88244FB8:
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88245124
	if (ctx.cr0.gt) goto loc_88245124;
	// stw r25,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r25.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_88244FD4:
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// bge 0x88245124
	if (!ctx.cr0.lt) goto loc_88245124;
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// lis r10,-30687
	ctx.r10.s64 = -2011103232;
	// lwz r9,60(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r8,68(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// addi r4,r10,1976
	ctx.r4.s64 = ctx.r10.s64 + 1976;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// bl 0x88097078
	ctx.lr = 0x88245010;
	sub_88097078(ctx, base);
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// lwz r7,64(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// li r6,2
	ctx.r6.s64 = 2;
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// addic. r11,r7,-1
	ctx.xer.ca = ctx.r7.u32 > 0;
	ctx.r11.s64 = ctx.r7.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r6,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r6.u32);
	// stw r5,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r5.u32);
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// bgt 0x88245124
	if (ctx.cr0.gt) goto loc_88245124;
	// li r11,64
	ctx.r11.s64 = 64;
	// stw r27,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r27.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_88245050:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096e28
	ctx.lr = 0x8824505C;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88245124
	if (!ctx.cr6.eq) goto loc_88245124;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88244fb8
	if (!ctx.cr6.eq) goto loc_88244FB8;
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lis r10,-30687
	ctx.r10.s64 = -2011103232;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,1784
	ctx.r4.s64 = ctx.r10.s64 + 1784;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x88097078
	ctx.lr = 0x8824508C;
	sub_88097078(ctx, base);
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// lis r8,-30687
	ctx.r8.s64 = -2011103232;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,1624
	ctx.r4.s64 = ctx.r8.s64 + 1624;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x88097078
	ctx.lr = 0x882450AC;
	sub_88097078(ctx, base);
	// li r7,2
	ctx.r7.s64 = 2;
	// stw r3,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r7,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_882450C4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// bl 0x88096e28
	ctx.lr = 0x882450D0;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88245124
	if (!ctx.cr6.eq) goto loc_88245124;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x88096dd0
	ctx.lr = 0x882450E4;
	sub_88096DD0(ctx, base);
	// stw r26,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r26.u32);
	// stw r25,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r25.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_882450F8:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88244fb8
	if (!ctx.cr6.eq) goto loc_88244FB8;
	// lis r11,-30684
	ctx.r11.s64 = -2010906624;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,19816
	ctx.r4.s64 = ctx.r11.s64 + 19816;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880969a8
	ctx.lr = 0x88245118;
	sub_880969A8(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096830
	ctx.lr = 0x88245124;
	sub_88096830(ctx, base);
loc_88245124:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88245130"))) PPC_WEAK_FUNC(sub_88245130);
PPC_FUNC_IMPL(__imp__sub_88245130) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88245138;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r5,80
	ctx.r5.s64 = 80;
	// bl 0x880968b8
	ctx.lr = 0x88245154;
	sub_880968B8(ctx, base);
	// lis r10,-30671
	ctx.r10.s64 = -2010054656;
	// lis r9,16838
	ctx.r9.s64 = 1103495168;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// ori r8,r9,20077
	ctx.r8.u64 = ctx.r9.u64 | 20077;
	// li r31,0
	ctx.r31.s64 = 0;
	// lwz r11,4200(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4200);
	// li r7,128
	ctx.r7.s64 = 128;
	// li r6,3
	ctx.r6.s64 = 3;
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r31.u32);
	// mullw r11,r11,r8
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r8.s32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// stw r31,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r31.u32);
	// stw r31,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r31.u32);
	// stw r31,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r31.u32);
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// lis r5,96
	ctx.r5.s64 = 6291456;
	// stw r11,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r11.u32);
	// lis r4,240
	ctx.r4.s64 = 15728640;
	// lhz r11,4200(r10)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// lis r10,-30685
	ctx.r10.s64 = -2010972160;
	// stw r4,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,48(r28)
	PPC_STORE_U32(ctx.r28.u32 + 48, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-27968
	ctx.r4.s64 = ctx.r10.s64 + -27968;
	// bl 0x880966a8
	ctx.lr = 0x882451C8;
	sub_880966A8(ctx, base);
	// li r10,4
	ctx.r10.s64 = 4;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r31,72(r28)
	PPC_STORE_U32(ctx.r28.u32 + 72, ctx.r31.u32);
	// li r9,10
	ctx.r9.s64 = 10;
	// stw r10,28(r28)
	PPC_STORE_U32(ctx.r28.u32 + 28, ctx.r10.u32);
	// li r8,5
	ctx.r8.s64 = 5;
	// stw r11,60(r28)
	PPC_STORE_U32(ctx.r28.u32 + 60, ctx.r11.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// stw r9,32(r28)
	PPC_STORE_U32(ctx.r28.u32 + 32, ctx.r9.u32);
	// stw r8,36(r28)
	PPC_STORE_U32(ctx.r28.u32 + 36, ctx.r8.u32);
	// lis r6,-30684
	ctx.r6.s64 = -2010906624;
	// stw r11,64(r28)
	PPC_STORE_U32(ctx.r28.u32 + 64, ctx.r11.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r10,68(r28)
	PPC_STORE_U32(ctx.r28.u32 + 68, ctx.r10.u32);
	// addi r5,r6,20056
	ctx.r5.s64 = ctx.r6.s64 + 20056;
	// stw r7,76(r28)
	PPC_STORE_U32(ctx.r28.u32 + 76, ctx.r7.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096950
	ctx.lr = 0x88245210;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824521C"))) PPC_WEAK_FUNC(sub_8824521C);
PPC_FUNC_IMPL(__imp__sub_8824521C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88245220"))) PPC_WEAK_FUNC(sub_88245220);
PPC_FUNC_IMPL(__imp__sub_88245220) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x88245228;
	__savegprlr_27(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x88245244;
	sub_880968B8(ctx, base);
	// lwz r11,44(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r27,1
	ctx.r27.s64 = 1;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x882452f0
	if (!ctx.cr6.eq) goto loc_882452F0;
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x882452f0
	if (!ctx.cr6.eq) goto loc_882452F0;
	// lwz r11,48(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88245290
	if (ctx.cr6.eq) goto loc_88245290;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
	// bgt 0x882452f0
	if (ctx.cr0.gt) goto loc_882452F0;
	// stw r29,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r29.u32);
	// b 0x882452f0
	goto loc_882452F0;
loc_88245290:
	// li r11,12
	ctx.r11.s64 = 12;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r27.u32);
	// lis r9,272
	ctx.r9.s64 = 17825792;
	// stw r11,16(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16, ctx.r11.u32);
	// lis r8,-30685
	ctx.r8.s64 = -2010972160;
	// lwz r7,40(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// subfic r11,r7,12
	ctx.xer.ca = ctx.r7.u32 <= 12;
	ctx.r11.s64 = 12 - ctx.r7.s64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r4,r8,-19528
	ctx.r4.s64 = ctx.r8.s64 + -19528;
	// rlwinm r11,r6,17,0,14
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 17) & 0xFFFE0000;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bl 0x880966a8
	ctx.lr = 0x882452D0;
	sub_880966A8(ctx, base);
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// li r3,64
	ctx.r3.s64 = 64;
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// stw r9,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r9.u32);
	// bl 0x881534c8
	ctx.lr = 0x882452E4;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// addi r8,r11,64
	ctx.r8.s64 = ctx.r11.s64 + 64;
	// stw r8,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r8.u32);
loc_882452F0:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88245404
	if (ctx.cr6.eq) goto loc_88245404;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x88245364
	if (ctx.cr6.eq) goto loc_88245364;
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// bne cr6,0x88245474
	if (!ctx.cr6.eq) goto loc_88245474;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x88096e28
	ctx.lr = 0x88245318;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88245474
	if (!ctx.cr6.eq) goto loc_88245474;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88245474
	if (ctx.cr0.gt) goto loc_88245474;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-5496
	ctx.r4.s64 = ctx.r11.s64 + -5496;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x88245344;
	sub_88097078(ctx, base);
	// li r10,1000
	ctx.r10.s64 = 1000;
	// li r9,24
	ctx.r9.s64 = 24;
	// stw r3,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r3.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_88245364:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x88096e28
	ctx.lr = 0x88245370;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88245474
	if (!ctx.cr6.eq) goto loc_88245474;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88245474
	if (ctx.cr0.gt) goto loc_88245474;
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// bge 0x88245474
	if (!ctx.cr0.lt) goto loc_88245474;
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// li r10,20
	ctx.r10.s64 = 20;
	// lwz r9,52(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lis r8,-30696
	ctx.r8.s64 = -2011693056;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// addi r4,r8,-5288
	ctx.r4.s64 = ctx.r8.s64 + -5288;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// bl 0x88097078
	ctx.lr = 0x882453C8;
	sub_88097078(ctx, base);
	// lwz r7,56(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// li r6,5
	ctx.r6.s64 = 5;
	// stw r3,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r3.u32);
	// addic. r11,r7,-1
	ctx.xer.ca = ctx.r7.u32 > 0;
	ctx.r11.s64 = ctx.r7.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r6,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r6.u32);
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// bgt 0x88245474
	if (ctx.cr0.gt) goto loc_88245474;
	// li r11,6
	ctx.r11.s64 = 6;
	// stw r27,15644(r28)
	PPC_STORE_U32(ctx.r28.u32 + 15644, ctx.r27.u32);
	// li r10,16
	ctx.r10.s64 = 16;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_88245404:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88245474
	if (ctx.cr0.gt) goto loc_88245474;
	// li r11,10
	ctx.r11.s64 = 10;
	// stw r29,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r29.u32);
	// stw r29,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r29.u32);
	// lis r10,-30696
	ctx.r10.s64 = -2011693056;
	// stw r29,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r29.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r29,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r29.u32);
	// addi r4,r10,-7240
	ctx.r4.s64 = ctx.r10.s64 + -7240;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// bl 0x88097078
	ctx.lr = 0x88245444;
	sub_88097078(ctx, base);
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// stw r27,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r27.u32);
	// lis r9,-30696
	ctx.r9.s64 = -2011693056;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,-7240
	ctx.r4.s64 = ctx.r9.s64 + -7240;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x88245460;
	sub_88097078(ctx, base);
	// li r8,5
	ctx.r8.s64 = 5;
	// li r7,64
	ctx.r7.s64 = 64;
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// stw r7,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r7.u32);
loc_88245474:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88245480"))) PPC_WEAK_FUNC(sub_88245480);
PPC_FUNC_IMPL(__imp__sub_88245480) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88245488;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,68
	ctx.r5.s64 = 68;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x880968b8
	ctx.lr = 0x882454A8;
	sub_880968B8(ctx, base);
	// lis r8,-30671
	ctx.r8.s64 = -2010054656;
	// lis r7,16838
	ctx.r7.s64 = 1103495168;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// ori r5,r7,20077
	ctx.r5.u64 = ctx.r7.u64 | 20077;
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r10,4200(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4200);
	// li r9,64
	ctx.r9.s64 = 64;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// lis r4,-1009
	ctx.r4.s64 = -66125824;
	// mullw r10,r10,r5
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r5.s32);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// stw r11,44(r6)
	PPC_STORE_U32(ctx.r6.u32 + 44, ctx.r11.u32);
	// stw r11,60(r6)
	PPC_STORE_U32(ctx.r6.u32 + 60, ctx.r11.u32);
	// stw r3,40(r6)
	PPC_STORE_U32(ctx.r6.u32 + 40, ctx.r3.u32);
	// addi r10,r10,12345
	ctx.r10.s64 = ctx.r10.s64 + 12345;
	// stw r9,64(r6)
	PPC_STORE_U32(ctx.r6.u32 + 64, ctx.r9.u32);
	// ori r11,r4,49405
	ctx.r11.u64 = ctx.r4.u64 | 49405;
	// stw r10,4200(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4200, ctx.r10.u32);
	// li r9,5
	ctx.r9.s64 = 5;
	// lhz r8,4200(r8)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4200);
	// mulhwu r7,r8,r11
	ctx.r7.u64 = (uint64_t(ctx.r8.u32) * uint64_t(ctx.r11.u32)) >> 32;
	// rlwinm r11,r7,26,6,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 26) & 0x3FFFFFF;
	// stw r9,52(r6)
	PPC_STORE_U32(ctx.r6.u32 + 52, ctx.r9.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// rlwinm r10,r11,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 6) & 0xFFFFFFC0;
	// stw r5,56(r6)
	PPC_STORE_U32(ctx.r6.u32 + 56, ctx.r5.u32);
	// lis r4,-30684
	ctx.r4.s64 = -2010906624;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r5,r4,21024
	ctx.r5.s64 = ctx.r4.s64 + 21024;
	// subf r11,r3,r8
	ctx.r11.s64 = ctx.r8.s64 - ctx.r3.s64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r9,r11,64
	ctx.r9.s64 = ctx.r11.s64 + 64;
	// stw r9,48(r6)
	PPC_STORE_U32(ctx.r6.u32 + 48, ctx.r9.u32);
	// bl 0x88096950
	ctx.lr = 0x8824553C;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88245548"))) PPC_WEAK_FUNC(sub_88245548);
PPC_FUNC_IMPL(__imp__sub_88245548) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88245550;
	__savegprlr_29(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x8824556C;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824563c
	if (ctx.cr6.eq) goto loc_8824563C;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// beq cr6,0x882455d8
	if (ctx.cr6.eq) goto loc_882455D8;
	// cmpwi cr6,r11,90
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 90, ctx.xer);
	// bne cr6,0x88245630
	if (!ctx.cr6.eq) goto loc_88245630;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096710
	ctx.lr = 0x88245598;
	sub_88096710(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x88245630
	if (!ctx.cr6.eq) goto loc_88245630;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r3,1
	ctx.r3.s64 = 1;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88245634
	if (ctx.cr0.gt) goto loc_88245634;
	// lwz r11,15776(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 15776);
	// li r10,10
	ctx.r10.s64 = 10;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// stw r8,15776(r29)
	PPC_STORE_U32(ctx.r29.u32 + 15776, ctx.r8.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_882455D8:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88245630
	if (ctx.cr0.gt) goto loc_88245630;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r10,-30684
	ctx.r10.s64 = -2010906624;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// neg r9,r11
	ctx.r9.s64 = -ctx.r11.s64;
	// addi r4,r10,21632
	ctx.r4.s64 = ctx.r10.s64 + 21632;
	// stw r9,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r9.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x880969a8
	ctx.lr = 0x8824560C;
	sub_880969A8(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r8,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r8.u32);
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// bl 0x88096760
	ctx.lr = 0x88245620;
	sub_88096760(ctx, base);
	// li r7,90
	ctx.r7.s64 = 90;
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
	// stw r6,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r6.u32);
loc_88245630:
	// li r3,1
	ctx.r3.s64 = 1;
loc_88245634:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_8824563C:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r3,1
	ctx.r3.s64 = 1;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88245634
	if (ctx.cr0.gt) goto loc_88245634;
	// li r11,10
	ctx.r11.s64 = 10;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88245668"))) PPC_WEAK_FUNC(sub_88245668);
PPC_FUNC_IMPL(__imp__sub_88245668) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88245670;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880968b8
	ctx.lr = 0x88245690;
	sub_880968B8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// lis r9,120
	ctx.r9.s64 = 7864320;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// lwz r8,8(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x882456bc
	if (!ctx.cr6.lt) goto loc_882456BC;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
loc_882456BC:
	// stw r11,15776(r29)
	PPC_STORE_U32(ctx.r29.u32 + 15776, ctx.r11.u32);
	// lis r11,-30684
	ctx.r11.s64 = -2010906624;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r11,21832
	ctx.r5.s64 = ctx.r11.s64 + 21832;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096950
	ctx.lr = 0x882456D4;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_882456E0"))) PPC_WEAK_FUNC(sub_882456E0);
PPC_FUNC_IMPL(__imp__sub_882456E0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x882456E8;
	__savegprlr_27(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x88245704;
	sub_880968B8(ctx, base);
	// lwz r11,44(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r27,1
	ctx.r27.s64 = 1;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x882457b0
	if (!ctx.cr6.eq) goto loc_882457B0;
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x882457b0
	if (!ctx.cr6.eq) goto loc_882457B0;
	// lwz r11,48(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88245750
	if (ctx.cr6.eq) goto loc_88245750;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
	// bgt 0x882457b0
	if (ctx.cr0.gt) goto loc_882457B0;
	// stw r29,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r29.u32);
	// b 0x882457b0
	goto loc_882457B0;
loc_88245750:
	// li r11,12
	ctx.r11.s64 = 12;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r27.u32);
	// lis r9,272
	ctx.r9.s64 = 17825792;
	// stw r11,16(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16, ctx.r11.u32);
	// lis r8,-30685
	ctx.r8.s64 = -2010972160;
	// lwz r7,40(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// subfic r11,r7,6
	ctx.xer.ca = ctx.r7.u32 <= 6;
	ctx.r11.s64 = 6 - ctx.r7.s64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r4,r8,-19528
	ctx.r4.s64 = ctx.r8.s64 + -19528;
	// rlwinm r11,r6,18,0,13
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 18) & 0xFFFC0000;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bl 0x880966a8
	ctx.lr = 0x88245790;
	sub_880966A8(ctx, base);
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// li r3,64
	ctx.r3.s64 = 64;
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// stw r9,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r9.u32);
	// bl 0x881534c8
	ctx.lr = 0x882457A4;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// addi r8,r11,64
	ctx.r8.s64 = ctx.r11.s64 + 64;
	// stw r8,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r8.u32);
loc_882457B0:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x882458c4
	if (ctx.cr6.eq) goto loc_882458C4;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x88245824
	if (ctx.cr6.eq) goto loc_88245824;
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// bne cr6,0x88245934
	if (!ctx.cr6.eq) goto loc_88245934;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x88096e28
	ctx.lr = 0x882457D8;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88245934
	if (!ctx.cr6.eq) goto loc_88245934;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88245934
	if (ctx.cr0.gt) goto loc_88245934;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-3056
	ctx.r4.s64 = ctx.r11.s64 + -3056;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x88245804;
	sub_88097078(ctx, base);
	// li r10,1000
	ctx.r10.s64 = 1000;
	// li r9,24
	ctx.r9.s64 = 24;
	// stw r3,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r3.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_88245824:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x88096e28
	ctx.lr = 0x88245830;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88245934
	if (!ctx.cr6.eq) goto loc_88245934;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88245934
	if (ctx.cr0.gt) goto loc_88245934;
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// bge 0x88245934
	if (!ctx.cr0.lt) goto loc_88245934;
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// li r10,20
	ctx.r10.s64 = 20;
	// lwz r9,52(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lis r8,-30696
	ctx.r8.s64 = -2011693056;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// addi r4,r8,-3280
	ctx.r4.s64 = ctx.r8.s64 + -3280;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// bl 0x88097078
	ctx.lr = 0x88245888;
	sub_88097078(ctx, base);
	// lwz r7,56(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// li r6,5
	ctx.r6.s64 = 5;
	// stw r3,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r3.u32);
	// addic. r11,r7,-1
	ctx.xer.ca = ctx.r7.u32 > 0;
	ctx.r11.s64 = ctx.r7.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r6,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r6.u32);
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// bgt 0x88245934
	if (ctx.cr0.gt) goto loc_88245934;
	// li r11,6
	ctx.r11.s64 = 6;
	// stw r27,15644(r28)
	PPC_STORE_U32(ctx.r28.u32 + 15644, ctx.r27.u32);
	// li r10,16
	ctx.r10.s64 = 16;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_882458C4:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88245934
	if (ctx.cr0.gt) goto loc_88245934;
	// li r11,10
	ctx.r11.s64 = 10;
	// stw r29,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r29.u32);
	// stw r29,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r29.u32);
	// lis r10,-30696
	ctx.r10.s64 = -2011693056;
	// stw r29,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r29.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r29,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r29.u32);
	// addi r4,r10,-4288
	ctx.r4.s64 = ctx.r10.s64 + -4288;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// bl 0x88097078
	ctx.lr = 0x88245904;
	sub_88097078(ctx, base);
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// stw r27,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r27.u32);
	// lis r9,-30696
	ctx.r9.s64 = -2011693056;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,-4288
	ctx.r4.s64 = ctx.r9.s64 + -4288;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x88245920;
	sub_88097078(ctx, base);
	// li r8,5
	ctx.r8.s64 = 5;
	// li r7,64
	ctx.r7.s64 = 64;
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// stw r7,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r7.u32);
loc_88245934:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88245940"))) PPC_WEAK_FUNC(sub_88245940);
PPC_FUNC_IMPL(__imp__sub_88245940) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88245948;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,68
	ctx.r5.s64 = 68;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x880968b8
	ctx.lr = 0x88245968;
	sub_880968B8(ctx, base);
	// lis r8,-30671
	ctx.r8.s64 = -2010054656;
	// lis r7,16838
	ctx.r7.s64 = 1103495168;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// ori r5,r7,20077
	ctx.r5.u64 = ctx.r7.u64 | 20077;
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r10,4200(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4200);
	// li r9,64
	ctx.r9.s64 = 64;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// lis r4,-1009
	ctx.r4.s64 = -66125824;
	// mullw r10,r10,r5
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r5.s32);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// stw r11,44(r6)
	PPC_STORE_U32(ctx.r6.u32 + 44, ctx.r11.u32);
	// stw r11,60(r6)
	PPC_STORE_U32(ctx.r6.u32 + 60, ctx.r11.u32);
	// stw r3,40(r6)
	PPC_STORE_U32(ctx.r6.u32 + 40, ctx.r3.u32);
	// addi r10,r10,12345
	ctx.r10.s64 = ctx.r10.s64 + 12345;
	// stw r9,64(r6)
	PPC_STORE_U32(ctx.r6.u32 + 64, ctx.r9.u32);
	// ori r11,r4,49405
	ctx.r11.u64 = ctx.r4.u64 | 49405;
	// stw r10,4200(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4200, ctx.r10.u32);
	// li r9,5
	ctx.r9.s64 = 5;
	// lhz r8,4200(r8)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4200);
	// mulhwu r7,r8,r11
	ctx.r7.u64 = (uint64_t(ctx.r8.u32) * uint64_t(ctx.r11.u32)) >> 32;
	// rlwinm r11,r7,26,6,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 26) & 0x3FFFFFF;
	// stw r9,52(r6)
	PPC_STORE_U32(ctx.r6.u32 + 52, ctx.r9.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// rlwinm r10,r11,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 6) & 0xFFFFFFC0;
	// stw r5,56(r6)
	PPC_STORE_U32(ctx.r6.u32 + 56, ctx.r5.u32);
	// lis r4,-30684
	ctx.r4.s64 = -2010906624;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r5,r4,22240
	ctx.r5.s64 = ctx.r4.s64 + 22240;
	// subf r11,r3,r8
	ctx.r11.s64 = ctx.r8.s64 - ctx.r3.s64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r9,r11,64
	ctx.r9.s64 = ctx.r11.s64 + 64;
	// stw r9,48(r6)
	PPC_STORE_U32(ctx.r6.u32 + 48, ctx.r9.u32);
	// bl 0x88096950
	ctx.lr = 0x882459FC;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88245A08"))) PPC_WEAK_FUNC(sub_88245A08);
PPC_FUNC_IMPL(__imp__sub_88245A08) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88245A10;
	__savegprlr_29(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x88245A2C;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88245afc
	if (ctx.cr6.eq) goto loc_88245AFC;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// beq cr6,0x88245a98
	if (ctx.cr6.eq) goto loc_88245A98;
	// cmpwi cr6,r11,90
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 90, ctx.xer);
	// bne cr6,0x88245af0
	if (!ctx.cr6.eq) goto loc_88245AF0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096710
	ctx.lr = 0x88245A58;
	sub_88096710(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x88245af0
	if (!ctx.cr6.eq) goto loc_88245AF0;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r3,1
	ctx.r3.s64 = 1;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88245af4
	if (ctx.cr0.gt) goto loc_88245AF4;
	// lwz r11,15776(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 15776);
	// li r10,10
	ctx.r10.s64 = 10;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// stw r8,15776(r29)
	PPC_STORE_U32(ctx.r29.u32 + 15776, ctx.r8.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_88245A98:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88245af0
	if (ctx.cr0.gt) goto loc_88245AF0;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r10,-30684
	ctx.r10.s64 = -2010906624;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// neg r9,r11
	ctx.r9.s64 = -ctx.r11.s64;
	// addi r4,r10,22848
	ctx.r4.s64 = ctx.r10.s64 + 22848;
	// stw r9,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r9.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x880969a8
	ctx.lr = 0x88245ACC;
	sub_880969A8(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r8,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r8.u32);
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// bl 0x88096760
	ctx.lr = 0x88245AE0;
	sub_88096760(ctx, base);
	// li r7,90
	ctx.r7.s64 = 90;
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
	// stw r6,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r6.u32);
loc_88245AF0:
	// li r3,1
	ctx.r3.s64 = 1;
loc_88245AF4:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_88245AFC:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r3,1
	ctx.r3.s64 = 1;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88245af4
	if (ctx.cr0.gt) goto loc_88245AF4;
	// li r11,10
	ctx.r11.s64 = 10;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88245B28"))) PPC_WEAK_FUNC(sub_88245B28);
PPC_FUNC_IMPL(__imp__sub_88245B28) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88245B30;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880968b8
	ctx.lr = 0x88245B50;
	sub_880968B8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// lis r9,120
	ctx.r9.s64 = 7864320;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// lwz r8,8(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x88245b7c
	if (!ctx.cr6.lt) goto loc_88245B7C;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
loc_88245B7C:
	// stw r11,15776(r29)
	PPC_STORE_U32(ctx.r29.u32 + 15776, ctx.r11.u32);
	// lis r11,-30684
	ctx.r11.s64 = -2010906624;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r11,23048
	ctx.r5.s64 = ctx.r11.s64 + 23048;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096950
	ctx.lr = 0x88245B94;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88245BA0"))) PPC_WEAK_FUNC(sub_88245BA0);
PPC_FUNC_IMPL(__imp__sub_88245BA0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x88245BA8;
	__savegprlr_27(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x88245BC4;
	sub_880968B8(ctx, base);
	// lwz r11,44(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r27,1
	ctx.r27.s64 = 1;
	// li r28,0
	ctx.r28.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88245c70
	if (!ctx.cr6.eq) goto loc_88245C70;
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x88245c70
	if (!ctx.cr6.eq) goto loc_88245C70;
	// lwz r11,48(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88245c10
	if (ctx.cr6.eq) goto loc_88245C10;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
	// bgt 0x88245c70
	if (ctx.cr0.gt) goto loc_88245C70;
	// stw r28,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r28.u32);
	// b 0x88245c70
	goto loc_88245C70;
loc_88245C10:
	// li r11,12
	ctx.r11.s64 = 12;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r27.u32);
	// lis r9,272
	ctx.r9.s64 = 17825792;
	// stw r11,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r11.u32);
	// lis r8,-30685
	ctx.r8.s64 = -2010972160;
	// lwz r7,40(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// subfic r11,r7,6
	ctx.xer.ca = ctx.r7.u32 <= 6;
	ctx.r11.s64 = 6 - ctx.r7.s64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r4,r8,-19528
	ctx.r4.s64 = ctx.r8.s64 + -19528;
	// rlwinm r11,r6,18,0,13
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 18) & 0xFFFC0000;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bl 0x880966a8
	ctx.lr = 0x88245C50;
	sub_880966A8(ctx, base);
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// li r3,64
	ctx.r3.s64 = 64;
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// stw r9,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r9.u32);
	// bl 0x881534c8
	ctx.lr = 0x88245C64;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// addi r8,r11,64
	ctx.r8.s64 = ctx.r11.s64 + 64;
	// stw r8,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r8.u32);
loc_88245C70:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88245d14
	if (ctx.cr6.eq) goto loc_88245D14;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// bne cr6,0x88245d84
	if (!ctx.cr6.eq) goto loc_88245D84;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x88096e28
	ctx.lr = 0x88245C90;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88245d84
	if (!ctx.cr6.eq) goto loc_88245D84;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88245d84
	if (ctx.cr0.gt) goto loc_88245D84;
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// bge 0x88245d84
	if (!ctx.cr0.lt) goto loc_88245D84;
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// li r10,20
	ctx.r10.s64 = 20;
	// lwz r9,52(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lis r8,-30696
	ctx.r8.s64 = -2011693056;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r28.u32);
	// addi r4,r8,-1264
	ctx.r4.s64 = ctx.r8.s64 + -1264;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// bl 0x88097078
	ctx.lr = 0x88245CE8;
	sub_88097078(ctx, base);
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// stw r3,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// blt cr6,0x88245d88
	if (ctx.cr6.lt) goto loc_88245D88;
	// li r11,16
	ctx.r11.s64 = 16;
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_88245D14:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88245d84
	if (ctx.cr0.gt) goto loc_88245D84;
	// li r11,10
	ctx.r11.s64 = 10;
	// stw r28,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r28.u32);
	// stw r28,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r28.u32);
	// lis r10,-30696
	ctx.r10.s64 = -2011693056;
	// stw r28,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r28.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r28,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r28.u32);
	// addi r4,r10,-1968
	ctx.r4.s64 = ctx.r10.s64 + -1968;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r28.u32);
	// bl 0x88097078
	ctx.lr = 0x88245D54;
	sub_88097078(ctx, base);
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// stw r27,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r27.u32);
	// lis r9,-30696
	ctx.r9.s64 = -2011693056;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,-1968
	ctx.r4.s64 = ctx.r9.s64 + -1968;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x88245D70;
	sub_88097078(ctx, base);
	// li r8,5
	ctx.r8.s64 = 5;
	// li r7,64
	ctx.r7.s64 = 64;
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// stw r7,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r7.u32);
loc_88245D84:
	// li r3,1
	ctx.r3.s64 = 1;
loc_88245D88:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88245D90"))) PPC_WEAK_FUNC(sub_88245D90);
PPC_FUNC_IMPL(__imp__sub_88245D90) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88245D98;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,68
	ctx.r5.s64 = 68;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x880968b8
	ctx.lr = 0x88245DB8;
	sub_880968B8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r8,64
	ctx.r8.s64 = 64;
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// lis r7,-30671
	ctx.r7.s64 = -2010054656;
	// lis r6,16838
	ctx.r6.s64 = 1103495168;
	// lis r5,-1009
	ctx.r5.s64 = -66125824;
	// ori r4,r6,20077
	ctx.r4.u64 = ctx.r6.u64 | 20077;
	// ori r8,r5,49405
	ctx.r8.u64 = ctx.r5.u64 | 49405;
	// lwz r10,4200(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4200);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r6,5
	ctx.r6.s64 = 5;
	// mullw r10,r10,r4
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r4.s32);
	// addi r10,r10,12345
	ctx.r10.s64 = ctx.r10.s64 + 12345;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// li r4,32
	ctx.r4.s64 = 32;
	// stw r10,4200(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4200, ctx.r10.u32);
	// lhz r7,4200(r7)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r7.u32 + 4200);
	// stw r5,56(r9)
	PPC_STORE_U32(ctx.r9.u32 + 56, ctx.r5.u32);
	// mulhwu r5,r7,r8
	ctx.r5.u64 = (uint64_t(ctx.r7.u32) * uint64_t(ctx.r8.u32)) >> 32;
	// stw r11,44(r9)
	PPC_STORE_U32(ctx.r9.u32 + 44, ctx.r11.u32);
	// stw r11,60(r9)
	PPC_STORE_U32(ctx.r9.u32 + 60, ctx.r11.u32);
	// rlwinm r11,r5,26,6,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 26) & 0x3FFFFFF;
	// stw r6,52(r9)
	PPC_STORE_U32(ctx.r9.u32 + 52, ctx.r6.u32);
	// lis r6,-30684
	ctx.r6.s64 = -2010906624;
	// rlwinm r10,r11,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 6) & 0xFFFFFFC0;
	// stw r3,40(r9)
	PPC_STORE_U32(ctx.r9.u32 + 40, ctx.r3.u32);
	// stw r4,64(r9)
	PPC_STORE_U32(ctx.r9.u32 + 64, ctx.r4.u32);
	// addi r5,r6,23456
	ctx.r5.s64 = ctx.r6.s64 + 23456;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// subf r10,r11,r7
	ctx.r10.s64 = ctx.r7.s64 - ctx.r11.s64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// extsh r11,r10
	ctx.r11.s64 = ctx.r10.s16;
	// addi r7,r11,64
	ctx.r7.s64 = ctx.r11.s64 + 64;
	// stw r7,48(r9)
	PPC_STORE_U32(ctx.r9.u32 + 48, ctx.r7.u32);
	// bl 0x88096950
	ctx.lr = 0x88245E50;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88245E5C"))) PPC_WEAK_FUNC(sub_88245E5C);
PPC_FUNC_IMPL(__imp__sub_88245E5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88245E60"))) PPC_WEAK_FUNC(sub_88245E60);
PPC_FUNC_IMPL(__imp__sub_88245E60) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88245E68;
	__savegprlr_29(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x88245E84;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88245f54
	if (ctx.cr6.eq) goto loc_88245F54;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// beq cr6,0x88245ef0
	if (ctx.cr6.eq) goto loc_88245EF0;
	// cmpwi cr6,r11,90
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 90, ctx.xer);
	// bne cr6,0x88245f48
	if (!ctx.cr6.eq) goto loc_88245F48;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096710
	ctx.lr = 0x88245EB0;
	sub_88096710(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x88245f48
	if (!ctx.cr6.eq) goto loc_88245F48;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r3,1
	ctx.r3.s64 = 1;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88245f4c
	if (ctx.cr0.gt) goto loc_88245F4C;
	// lwz r11,15776(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 15776);
	// li r10,10
	ctx.r10.s64 = 10;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// stw r8,15776(r29)
	PPC_STORE_U32(ctx.r29.u32 + 15776, ctx.r8.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_88245EF0:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88245f48
	if (ctx.cr0.gt) goto loc_88245F48;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r10,-30684
	ctx.r10.s64 = -2010906624;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// neg r9,r11
	ctx.r9.s64 = -ctx.r11.s64;
	// addi r4,r10,23952
	ctx.r4.s64 = ctx.r10.s64 + 23952;
	// stw r9,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r9.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x880969a8
	ctx.lr = 0x88245F24;
	sub_880969A8(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r8,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r8.u32);
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// bl 0x88096760
	ctx.lr = 0x88245F38;
	sub_88096760(ctx, base);
	// li r7,90
	ctx.r7.s64 = 90;
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
	// stw r6,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r6.u32);
loc_88245F48:
	// li r3,1
	ctx.r3.s64 = 1;
loc_88245F4C:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_88245F54:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r3,1
	ctx.r3.s64 = 1;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88245f4c
	if (ctx.cr0.gt) goto loc_88245F4C;
	// li r11,10
	ctx.r11.s64 = 10;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88245F80"))) PPC_WEAK_FUNC(sub_88245F80);
PPC_FUNC_IMPL(__imp__sub_88245F80) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88245F88;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880968b8
	ctx.lr = 0x88245FA8;
	sub_880968B8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// lis r9,120
	ctx.r9.s64 = 7864320;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// lwz r8,8(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x88245fd4
	if (!ctx.cr6.lt) goto loc_88245FD4;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
loc_88245FD4:
	// stw r11,15776(r29)
	PPC_STORE_U32(ctx.r29.u32 + 15776, ctx.r11.u32);
	// lis r11,-30684
	ctx.r11.s64 = -2010906624;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r11,24160
	ctx.r5.s64 = ctx.r11.s64 + 24160;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096950
	ctx.lr = 0x88245FEC;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88245FF8"))) PPC_WEAK_FUNC(sub_88245FF8);
PPC_FUNC_IMPL(__imp__sub_88245FF8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x88246000;
	__savegprlr_27(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x88246020;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// bgt cr6,0x88246410
	if (ctx.cr6.gt) goto loc_88246410;
	// lis r12,-30684
	ctx.r12.s64 = -2010906624;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,24648
	ctx.r12.s64 = ctx.r12.s64 + 24648;
	// lwzx r0,r12,r0
	ctx.r0.u64 = PPC_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u64) {
	case 0:
		goto loc_88246074;
	case 1:
		goto loc_88246410;
	case 2:
		goto loc_88246410;
	case 3:
		goto loc_88246410;
	case 4:
		goto loc_88246410;
	case 5:
		goto loc_88246134;
	case 6:
		goto loc_88246228;
	case 7:
		goto loc_88246410;
	case 8:
		goto loc_882462C8;
	case 9:
		goto loc_88246390;
	case 10:
		goto loc_882463E4;
	default:
		__builtin_unreachable();
	}
	// lbz r1,24692(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 24692);
	// lbz r1,25616(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 25616);
	// lbz r1,25616(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 25616);
	// lbz r1,25616(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 25616);
	// lbz r1,25616(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 25616);
	// lbz r1,24884(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 24884);
	// lbz r1,25128(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 25128);
	// lbz r1,25616(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 25616);
	// lbz r1,25288(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 25288);
	// lbz r1,25488(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 25488);
	// lbz r1,25572(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 25572);
loc_88246074:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88246410
	if (ctx.cr0.gt) goto loc_88246410;
	// li r11,4
	ctx.r11.s64 = 4;
	// lis r10,60
	ctx.r10.s64 = 3932160;
	// stw r11,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r11.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r8,40(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// subfic r7,r8,2
	ctx.xer.ca = ctx.r8.u32 <= 2;
	ctx.r7.s64 = 2 - ctx.r8.s64;
	// mullw r6,r7,r10
	ctx.r6.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// lis r5,308
	ctx.r5.s64 = 20185088;
	// lis r4,-30685
	ctx.r4.s64 = -2010972160;
	// stw r5,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r4,-19528
	ctx.r4.s64 = ctx.r4.s64 + -19528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x882460C4;
	sub_880966A8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r3,-30696
	ctx.r3.s64 = -2011693056;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// addi r4,r3,15664
	ctx.r4.s64 = ctx.r3.s64 + 15664;
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// bl 0x88096cb8
	ctx.lr = 0x882460FC;
	sub_88096CB8(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,15536
	ctx.r4.s64 = ctx.r11.s64 + 15536;
	// bl 0x88096cb8
	ctx.lr = 0x88246114;
	sub_88096CB8(ctx, base);
	// li r10,5
	ctx.r10.s64 = 5;
	// li r9,32
	ctx.r9.s64 = 32;
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_88246134:
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// li r28,1
	ctx.r28.s64 = 1;
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x88246194
	if (!ctx.cr6.eq) goto loc_88246194;
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// lis r10,60
	ctx.r10.s64 = 3932160;
	// stw r11,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r11.u32);
	// lis r9,308
	ctx.r9.s64 = 20185088;
	// lis r6,-30685
	ctx.r6.s64 = -2010972160;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r6,-19528
	ctx.r4.s64 = ctx.r6.s64 + -19528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addi r8,r11,2
	ctx.r8.s64 = ctx.r11.s64 + 2;
	// mullw r7,r8,r10
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// bl 0x880966a8
	ctx.lr = 0x88246188;
	sub_880966A8(ctx, base);
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// neg r4,r5
	ctx.r4.s64 = -ctx.r5.s64;
	// stw r4,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r4.u32);
loc_88246194:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096e28
	ctx.lr = 0x882461A0;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88246410
	if (!ctx.cr6.eq) goto loc_88246410;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x88096e28
	ctx.lr = 0x882461B4;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88246410
	if (!ctx.cr6.eq) goto loc_88246410;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x882461e8
	if (ctx.cr6.eq) goto loc_882461E8;
loc_882461C8:
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88246410
	if (ctx.cr0.gt) goto loc_88246410;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_882461E8:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// lis r10,-30687
	ctx.r10.s64 = -2011103232;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,31664
	ctx.r4.s64 = ctx.r10.s64 + 31664;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x88246208;
	sub_88097078(ctx, base);
	// li r9,6
	ctx.r9.s64 = 6;
	// li r8,96
	ctx.r8.s64 = 96;
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r8,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_88246228:
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x88246288
	if (!ctx.cr6.eq) goto loc_88246288;
	// li r11,4
	ctx.r11.s64 = 4;
	// lis r10,60
	ctx.r10.s64 = 3932160;
	// stw r11,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r11.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addi r8,r11,2
	ctx.r8.s64 = ctx.r11.s64 + 2;
	// lis r7,308
	ctx.r7.s64 = 20185088;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// mullw r6,r8,r10
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// lis r4,-30685
	ctx.r4.s64 = -2010972160;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r4,-19528
	ctx.r4.s64 = ctx.r4.s64 + -19528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x8824627C;
	sub_880966A8(ctx, base);
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// neg r11,r3
	ctx.r11.s64 = -ctx.r3.s64;
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
loc_88246288:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x882461c8
	if (!ctx.cr6.eq) goto loc_882461C8;
	// li r11,32
	ctx.r11.s64 = 32;
	// lis r10,-30687
	ctx.r10.s64 = -2011103232;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,31296
	ctx.r4.s64 = ctx.r10.s64 + 31296;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x882462B0;
	sub_88097078(ctx, base);
	// li r9,8
	ctx.r9.s64 = 8;
	// stw r3,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_882462C8:
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// li r28,1
	ctx.r28.s64 = 1;
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// lis r27,308
	ctx.r27.s64 = 20185088;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x88246328
	if (!ctx.cr6.eq) goto loc_88246328;
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// lis r10,60
	ctx.r10.s64 = 3932160;
	// stw r27,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r27.u32);
	// stw r11,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r11.u32);
	// lis r9,-30685
	ctx.r9.s64 = -2010972160;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,-19528
	ctx.r4.s64 = ctx.r9.s64 + -19528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addi r8,r11,2
	ctx.r8.s64 = ctx.r11.s64 + 2;
	// mullw r7,r8,r10
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// bl 0x880966a8
	ctx.lr = 0x8824631C;
	sub_880966A8(ctx, base);
	// lwz r6,44(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// neg r5,r6
	ctx.r5.s64 = -ctx.r6.s64;
	// stw r5,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r5.u32);
loc_88246328:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x88096e28
	ctx.lr = 0x88246334;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88246410
	if (!ctx.cr6.eq) goto loc_88246410;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096dd0
	ctx.lr = 0x88246348;
	sub_88096DD0(ctx, base);
	// li r11,9
	ctx.r11.s64 = 9;
	// li r10,32
	ctx.r10.s64 = 32;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// li r9,12
	ctx.r9.s64 = 12;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lis r8,120
	ctx.r8.s64 = 7864320;
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// stw r9,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r9.u32);
	// lis r7,-30685
	ctx.r7.s64 = -2010972160;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r27,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r27.u32);
	// addi r4,r7,-19528
	ctx.r4.s64 = ctx.r7.s64 + -19528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x88246384;
	sub_880966A8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_88246390:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88246410
	if (ctx.cr0.gt) goto loc_88246410;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,15416
	ctx.r4.s64 = ctx.r11.s64 + 15416;
	// bl 0x88096cb8
	ctx.lr = 0x882463B4;
	sub_88096CB8(ctx, base);
	// lis r10,-30696
	ctx.r10.s64 = -2011693056;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// addi r4,r10,15296
	ctx.r4.s64 = ctx.r10.s64 + 15296;
	// bl 0x88096cb8
	ctx.lr = 0x882463C8;
	sub_88096CB8(ctx, base);
	// li r9,10
	ctx.r9.s64 = 10;
	// li r8,192
	ctx.r8.s64 = 192;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r8,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_882463E4:
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x88246410
	if (!ctx.cr6.eq) goto loc_88246410;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x882461c8
	if (!ctx.cr6.eq) goto loc_882461C8;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096830
	ctx.lr = 0x88246410;
	sub_88096830(ctx, base);
loc_88246410:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824641C"))) PPC_WEAK_FUNC(sub_8824641C);
PPC_FUNC_IMPL(__imp__sub_8824641C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88246420"))) PPC_WEAK_FUNC(sub_88246420);
PPC_FUNC_IMPL(__imp__sub_88246420) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88246428;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x88246448;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// bgt cr6,0x8824676c
	if (ctx.cr6.gt) goto loc_8824676C;
	// lis r12,-30684
	ctx.r12.s64 = -2010906624;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,25712
	ctx.r12.s64 = ctx.r12.s64 + 25712;
	// lwzx r0,r12,r0
	ctx.r0.u64 = PPC_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u64) {
	case 0:
		goto loc_8824649C;
	case 1:
		goto loc_88246558;
	case 2:
		goto loc_8824676C;
	case 3:
		goto loc_8824676C;
	case 4:
		goto loc_8824676C;
	case 5:
		goto loc_8824676C;
	case 6:
		goto loc_8824676C;
	case 7:
		goto loc_8824676C;
	case 8:
		goto loc_8824676C;
	case 9:
		goto loc_882466EC;
	case 10:
		goto loc_88246740;
	default:
		__builtin_unreachable();
	}
	// lbz r1,25756(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 25756);
	// lbz r1,25944(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 25944);
	// lbz r1,26476(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 26476);
	// lbz r1,26476(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 26476);
	// lbz r1,26476(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 26476);
	// lbz r1,26476(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 26476);
	// lbz r1,26476(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 26476);
	// lbz r1,26476(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 26476);
	// lbz r1,26476(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 26476);
	// lbz r1,26348(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 26348);
	// lbz r1,26432(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 26432);
loc_8824649C:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824676c
	if (ctx.cr0.gt) goto loc_8824676C;
	// li r11,4
	ctx.r11.s64 = 4;
	// lis r10,60
	ctx.r10.s64 = 3932160;
	// stw r11,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r11.u32);
	// lis r6,308
	ctx.r6.s64 = 20185088;
	// lwz r9,40(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// subfic r8,r9,2
	ctx.xer.ca = ctx.r9.u32 <= 2;
	ctx.r8.s64 = 2 - ctx.r9.s64;
	// mullw r7,r8,r10
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// li r28,1
	ctx.r28.s64 = 1;
	// lis r4,-30685
	ctx.r4.s64 = -2010972160;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r4,-19528
	ctx.r4.s64 = ctx.r4.s64 + -19528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x882464EC;
	sub_880966A8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r3,-30696
	ctx.r3.s64 = -2011693056;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// addi r4,r3,15664
	ctx.r4.s64 = ctx.r3.s64 + 15664;
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// bl 0x88096cb8
	ctx.lr = 0x88246524;
	sub_88096CB8(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,15536
	ctx.r4.s64 = ctx.r11.s64 + 15536;
	// bl 0x88096cb8
	ctx.lr = 0x8824653C;
	sub_88096CB8(ctx, base);
	// li r10,32
	ctx.r10.s64 = 32;
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r28,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_88246558:
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x882465b8
	if (!ctx.cr6.eq) goto loc_882465B8;
	// li r11,4
	ctx.r11.s64 = 4;
	// lis r10,60
	ctx.r10.s64 = 3932160;
	// stw r11,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r11.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addi r6,r11,2
	ctx.r6.s64 = ctx.r11.s64 + 2;
	// lis r8,308
	ctx.r8.s64 = 20185088;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// mullw r11,r6,r10
	ctx.r11.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r10.s32);
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// lis r7,-30685
	ctx.r7.s64 = -2010972160;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r7,-19528
	ctx.r4.s64 = ctx.r7.s64 + -19528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x882465AC;
	sub_880966A8(ctx, base);
	// lwz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// stw r9,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r9.u32);
loc_882465B8:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096e28
	ctx.lr = 0x882465C4;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8824676c
	if (!ctx.cr6.eq) goto loc_8824676C;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x882465f8
	if (ctx.cr6.eq) goto loc_882465F8;
loc_882465D8:
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824676c
	if (ctx.cr0.gt) goto loc_8824676C;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_882465F8:
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// bge 0x8824676c
	if (!ctx.cr0.lt) goto loc_8824676C;
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// lis r10,-30687
	ctx.r10.s64 = -2011103232;
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r8,52(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addi r4,r10,31912
	ctx.r4.s64 = ctx.r10.s64 + 31912;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// bl 0x88097078
	ctx.lr = 0x88246634;
	sub_88097078(ctx, base);
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// stw r3,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r3.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// blt cr6,0x88246654
	if (ctx.cr6.lt) goto loc_88246654;
	// li r11,8
	ctx.r11.s64 = 8;
	// stw r11,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
loc_88246654:
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// lis r9,-30687
	ctx.r9.s64 = -2011103232;
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// mulli r7,r10,-60
	ctx.r7.s64 = ctx.r10.s64 * -60;
	// lwz r6,64(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// rlwinm r3,r7,1,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0x1;
	// stw r4,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r4.u32);
	// addi r4,r9,31496
	ctx.r4.s64 = ctx.r9.s64 + 31496;
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x88246694;
	sub_88097078(ctx, base);
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// blt cr6,0x882466b8
	if (ctx.cr6.lt) goto loc_882466B8;
	// li r11,6
	ctx.r11.s64 = 6;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
loc_882466B8:
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r10,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r10.u32);
	// stw r11,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// bgt 0x8824676c
	if (ctx.cr0.gt) goto loc_8824676C;
	// li r11,9
	ctx.r11.s64 = 9;
	// li r10,32
	ctx.r10.s64 = 32;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_882466EC:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824676c
	if (ctx.cr0.gt) goto loc_8824676C;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,15416
	ctx.r4.s64 = ctx.r11.s64 + 15416;
	// bl 0x88096cb8
	ctx.lr = 0x88246710;
	sub_88096CB8(ctx, base);
	// lis r10,-30696
	ctx.r10.s64 = -2011693056;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// addi r4,r10,15296
	ctx.r4.s64 = ctx.r10.s64 + 15296;
	// bl 0x88096cb8
	ctx.lr = 0x88246724;
	sub_88096CB8(ctx, base);
	// li r9,160
	ctx.r9.s64 = 160;
	// li r8,10
	ctx.r8.s64 = 10;
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r8,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_88246740:
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x8824676c
	if (!ctx.cr6.eq) goto loc_8824676C;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x882465d8
	if (!ctx.cr6.eq) goto loc_882465D8;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096830
	ctx.lr = 0x8824676C;
	sub_88096830(ctx, base);
loc_8824676C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88246778"))) PPC_WEAK_FUNC(sub_88246778);
PPC_FUNC_IMPL(__imp__sub_88246778) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88246780;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x882467A0;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// bgt cr6,0x882469b4
	if (ctx.cr6.gt) goto loc_882469B4;
	// beq cr6,0x8824691c
	if (ctx.cr6.eq) goto loc_8824691C;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x88246854
	if (ctx.cr6.lt) goto loc_88246854;
	// bne cr6,0x88246a1c
	if (!ctx.cr6.eq) goto loc_88246A1C;
	// lwz r11,44(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r11.u32);
	// bge 0x88246a1c
	if (!ctx.cr0.lt) goto loc_88246A1C;
	// lwz r11,48(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lis r10,-30686
	ctx.r10.s64 = -2011037696;
	// lwz r9,40(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r8,56(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// addi r4,r10,-32400
	ctx.r4.s64 = ctx.r10.s64 + -32400;
	// lwz r7,64(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// clrlwi r6,r9,31
	ctx.r6.u64 = ctx.r9.u32 & 0x1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// bl 0x88097078
	ctx.lr = 0x88246808;
	sub_88097078(ctx, base);
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// stw r3,13396(r29)
	PPC_STORE_U32(ctx.r29.u32 + 13396, ctx.r3.u32);
	// lwz r5,52(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// addi r4,r9,1
	ctx.r4.s64 = ctx.r9.s64 + 1;
	// stw r3,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r3.u32);
	// addic. r11,r5,-1
	ctx.xer.ca = ctx.r5.u32 > 0;
	ctx.r11.s64 = ctx.r5.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r4,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r4.u32);
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// bgt 0x88246a1c
	if (ctx.cr0.gt) goto loc_88246A1C;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,5
	ctx.r10.s64 = 5;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_88246854:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88246a1c
	if (ctx.cr0.gt) goto loc_88246A1C;
	// li r11,12
	ctx.r11.s64 = 12;
	// lis r10,120
	ctx.r10.s64 = 7864320;
	// lis r9,292
	ctx.r9.s64 = 19136512;
	// stw r11,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r11.u32);
	// li r28,1
	ctx.r28.s64 = 1;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// lis r8,-30685
	ctx.r8.s64 = -2010972160;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,-19528
	ctx.r4.s64 = ctx.r8.s64 + -19528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x88246898;
	sub_880966A8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lwz r7,13404(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 13404);
	// cmpwi cr6,r7,5
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 5, ctx.xer);
	// beq cr6,0x882468e0
	if (ctx.cr6.eq) goto loc_882468E0;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,14872
	ctx.r4.s64 = ctx.r11.s64 + 14872;
	// bl 0x88096cb8
	ctx.lr = 0x882468DC;
	sub_88096CB8(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
loc_882468E0:
	// lwz r11,13492(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 13492);
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x88246904
	if (ctx.cr6.eq) goto loc_88246904;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,14760
	ctx.r4.s64 = ctx.r11.s64 + 14760;
	// bl 0x88096cb8
	ctx.lr = 0x88246900;
	sub_88096CB8(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
loc_88246904:
	// li r11,32
	ctx.r11.s64 = 32;
	// stw r28,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824691C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096e28
	ctx.lr = 0x88246928;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88246a1c
	if (!ctx.cr6.eq) goto loc_88246A1C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x88096e28
	ctx.lr = 0x8824693C;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88246a1c
	if (!ctx.cr6.eq) goto loc_88246A1C;
	// lwz r11,13404(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 13404);
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x88246968
	if (ctx.cr6.eq) goto loc_88246968;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,14648
	ctx.r4.s64 = ctx.r11.s64 + 14648;
	// bl 0x88096cb8
	ctx.lr = 0x88246964;
	sub_88096CB8(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
loc_88246968:
	// lwz r11,13492(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 13492);
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x8824698c
	if (ctx.cr6.eq) goto loc_8824698C;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,14536
	ctx.r4.s64 = ctx.r11.s64 + 14536;
	// bl 0x88096cb8
	ctx.lr = 0x88246988;
	sub_88096CB8(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
loc_8824698C:
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,90
	ctx.r10.s64 = 90;
	// li r9,64
	ctx.r9.s64 = 64;
	// stw r11,13396(r29)
	PPC_STORE_U32(ctx.r29.u32 + 13396, ctx.r11.u32);
	// stw r11,13484(r29)
	PPC_STORE_U32(ctx.r29.u32 + 13484, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_882469B4:
	// cmpwi cr6,r11,90
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 90, ctx.xer);
	// bne cr6,0x88246a1c
	if (!ctx.cr6.eq) goto loc_88246A1C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096a68
	ctx.lr = 0x882469C8;
	sub_88096A68(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88246a1c
	if (!ctx.cr6.eq) goto loc_88246A1C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x88096a68
	ctx.lr = 0x882469DC;
	sub_88096A68(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88246a1c
	if (!ctx.cr6.eq) goto loc_88246A1C;
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x88246a1c
	if (!ctx.cr6.eq) goto loc_88246A1C;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88246a1c
	if (ctx.cr0.gt) goto loc_88246A1C;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// stw r11,15780(r29)
	PPC_STORE_U32(ctx.r29.u32 + 15780, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096830
	ctx.lr = 0x88246A1C;
	sub_88096830(ctx, base);
loc_88246A1C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88246A28"))) PPC_WEAK_FUNC(sub_88246A28);
PPC_FUNC_IMPL(__imp__sub_88246A28) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88246A30;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,68
	ctx.r5.s64 = 68;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x880968b8
	ctx.lr = 0x88246A50;
	sub_880968B8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,3
	ctx.r10.s64 = 3;
	// li r8,32
	ctx.r8.s64 = 32;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r7,2
	ctx.r7.s64 = 2;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r30,0(r29)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r11.u32);
	// lis r6,-30684
	ctx.r6.s64 = -2010906624;
	// stw r8,56(r9)
	PPC_STORE_U32(ctx.r9.u32 + 56, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,60(r9)
	PPC_STORE_U32(ctx.r9.u32 + 60, ctx.r10.u32);
	// addi r5,r6,24568
	ctx.r5.s64 = ctx.r6.s64 + 24568;
	// stw r10,64(r9)
	PPC_STORE_U32(ctx.r9.u32 + 64, ctx.r10.u32);
	// stw r30,40(r9)
	PPC_STORE_U32(ctx.r9.u32 + 40, ctx.r30.u32);
	// stw r30,44(r9)
	PPC_STORE_U32(ctx.r9.u32 + 44, ctx.r30.u32);
	// stw r7,48(r9)
	PPC_STORE_U32(ctx.r9.u32 + 48, ctx.r7.u32);
	// bl 0x88096950
	ctx.lr = 0x88246AA0;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88246AAC"))) PPC_WEAK_FUNC(sub_88246AAC);
PPC_FUNC_IMPL(__imp__sub_88246AAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88246AB0"))) PPC_WEAK_FUNC(sub_88246AB0);
PPC_FUNC_IMPL(__imp__sub_88246AB0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88246AB8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,80
	ctx.r5.s64 = 80;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x880968b8
	ctx.lr = 0x88246AD8;
	sub_880968B8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,3
	ctx.r10.s64 = 3;
	// li r8,5
	ctx.r8.s64 = 5;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r7,32
	ctx.r7.s64 = 32;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// li r6,12
	ctx.r6.s64 = 12;
	// lwz r29,0(r29)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// li r28,1
	ctx.r28.s64 = 1;
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r11.u32);
	// lis r5,-30684
	ctx.r5.s64 = -2010906624;
	// stw r11,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r11.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r7,60(r9)
	PPC_STORE_U32(ctx.r9.u32 + 60, ctx.r7.u32);
	// addi r5,r5,25632
	ctx.r5.s64 = ctx.r5.s64 + 25632;
	// stw r29,40(r9)
	PPC_STORE_U32(ctx.r9.u32 + 40, ctx.r29.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r29,44(r9)
	PPC_STORE_U32(ctx.r9.u32 + 44, ctx.r29.u32);
	// stw r10,64(r9)
	PPC_STORE_U32(ctx.r9.u32 + 64, ctx.r10.u32);
	// stw r10,76(r9)
	PPC_STORE_U32(ctx.r9.u32 + 76, ctx.r10.u32);
	// stw r6,72(r9)
	PPC_STORE_U32(ctx.r9.u32 + 72, ctx.r6.u32);
	// stw r28,68(r9)
	PPC_STORE_U32(ctx.r9.u32 + 68, ctx.r28.u32);
	// bl 0x88096950
	ctx.lr = 0x88246B3C;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88246B48"))) PPC_WEAK_FUNC(sub_88246B48);
PPC_FUNC_IMPL(__imp__sub_88246B48) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88246B50;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,72
	ctx.r5.s64 = 72;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x880968b8
	ctx.lr = 0x88246B70;
	sub_880968B8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r8,48
	ctx.r8.s64 = 48;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r7,5
	ctx.r7.s64 = 5;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// li r6,20
	ctx.r6.s64 = 20;
	// lwz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// li r28,40
	ctx.r28.s64 = 40;
	// stw r5,40(r10)
	PPC_STORE_U32(ctx.r10.u32 + 40, ctx.r5.u32);
	// stw r9,44(r10)
	PPC_STORE_U32(ctx.r10.u32 + 44, ctx.r9.u32);
	// lis r3,-30684
	ctx.r3.s64 = -2010906624;
	// stw r8,48(r10)
	PPC_STORE_U32(ctx.r10.u32 + 48, ctx.r8.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r7,52(r10)
	PPC_STORE_U32(ctx.r10.u32 + 52, ctx.r7.u32);
	// addi r5,r3,26488
	ctx.r5.s64 = ctx.r3.s64 + 26488;
	// stw r6,56(r10)
	PPC_STORE_U32(ctx.r10.u32 + 56, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r28,60(r10)
	PPC_STORE_U32(ctx.r10.u32 + 60, ctx.r28.u32);
	// stw r11,64(r10)
	PPC_STORE_U32(ctx.r10.u32 + 64, ctx.r11.u32);
	// bl 0x88096950
	ctx.lr = 0x88246BC8;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88246BD4"))) PPC_WEAK_FUNC(sub_88246BD4);
PPC_FUNC_IMPL(__imp__sub_88246BD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88246BD8"))) PPC_WEAK_FUNC(sub_88246BD8);
PPC_FUNC_IMPL(__imp__sub_88246BD8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88246BE0;
	__savegprlr_29(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x88246BFC;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bgt cr6,0x88246d04
	if (ctx.cr6.gt) goto loc_88246D04;
	// beq cr6,0x88246ca8
	if (ctx.cr6.eq) goto loc_88246CA8;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88246c7c
	if (ctx.cr6.eq) goto loc_88246C7C;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// bne cr6,0x88246dc4
	if (!ctx.cr6.eq) goto loc_88246DC4;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096710
	ctx.lr = 0x88246C2C;
	sub_88096710(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x88246dc4
	if (!ctx.cr6.eq) goto loc_88246DC4;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88246dc4
	if (ctx.cr0.gt) goto loc_88246DC4;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r10,-30684
	ctx.r10.s64 = -2010906624;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,27312
	ctx.r4.s64 = ctx.r10.s64 + 27312;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x880969a8
	ctx.lr = 0x88246C60;
	sub_880969A8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// bl 0x88096760
	ctx.lr = 0x88246C74;
	sub_88096760(ctx, base);
	// li r8,20
	ctx.r8.s64 = 20;
	// b 0x88246db8
	goto loc_88246DB8;
loc_88246C7C:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88246dc4
	if (ctx.cr0.gt) goto loc_88246DC4;
	// li r11,10
	ctx.r11.s64 = 10;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_88246CA8:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096710
	ctx.lr = 0x88246CB4;
	sub_88096710(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x88246dc4
	if (!ctx.cr6.eq) goto loc_88246DC4;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88246dc4
	if (ctx.cr0.gt) goto loc_88246DC4;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r10,-30684
	ctx.r10.s64 = -2010906624;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,27464
	ctx.r4.s64 = ctx.r10.s64 + 27464;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x880969a8
	ctx.lr = 0x88246CE8;
	sub_880969A8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// bl 0x88096760
	ctx.lr = 0x88246CFC;
	sub_88096760(ctx, base);
	// li r8,40
	ctx.r8.s64 = 40;
	// b 0x88246db8
	goto loc_88246DB8;
loc_88246D04:
	// cmpwi cr6,r11,40
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 40, ctx.xer);
	// beq cr6,0x88246d60
	if (ctx.cr6.eq) goto loc_88246D60;
	// cmpwi cr6,r11,90
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 90, ctx.xer);
	// bne cr6,0x88246dc4
	if (!ctx.cr6.eq) goto loc_88246DC4;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096710
	ctx.lr = 0x88246D20;
	sub_88096710(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x88246dc4
	if (!ctx.cr6.eq) goto loc_88246DC4;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88246dc4
	if (ctx.cr0.gt) goto loc_88246DC4;
	// lwz r11,15772(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 15772);
	// li r10,10
	ctx.r10.s64 = 10;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r8,15772(r29)
	PPC_STORE_U32(ctx.r29.u32 + 15772, ctx.r8.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_88246D60:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096710
	ctx.lr = 0x88246D6C;
	sub_88096710(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x88246dc4
	if (!ctx.cr6.eq) goto loc_88246DC4;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88246dc4
	if (ctx.cr0.gt) goto loc_88246DC4;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r10,-30684
	ctx.r10.s64 = -2010906624;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,27176
	ctx.r4.s64 = ctx.r10.s64 + 27176;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x880969a8
	ctx.lr = 0x88246DA0;
	sub_880969A8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// bl 0x88096760
	ctx.lr = 0x88246DB4;
	sub_88096760(ctx, base);
	// li r8,90
	ctx.r8.s64 = 90;
loc_88246DB8:
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r8,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// stw r7,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r7.u32);
loc_88246DC4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88246DD0"))) PPC_WEAK_FUNC(sub_88246DD0);
PPC_FUNC_IMPL(__imp__sub_88246DD0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88246DD8;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x88246DF8;
	sub_880968B8(ctx, base);
	// li r28,0
	ctx.r28.s64 = 0;
	// li r11,-1
	ctx.r11.s64 = -1;
	// lis r10,120
	ctx.r10.s64 = 7864320;
	// stw r28,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r28.u32);
	// stw r28,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r28.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x88246e24
	if (!ctx.cr6.lt) goto loc_88246E24;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
loc_88246E24:
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// li r11,4
	ctx.r11.s64 = 4;
	// li r10,256
	ctx.r10.s64 = 256;
	// lis r9,248
	ctx.r9.s64 = 16252928;
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// stw r10,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// lis r8,-30685
	ctx.r8.s64 = -2010972160;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// addi r4,r8,-19528
	ctx.r4.s64 = ctx.r8.s64 + -19528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x88246E58;
	sub_880966A8(ctx, base);
	// stw r28,15772(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15772, ctx.r28.u32);
	// lis r7,-30684
	ctx.r7.s64 = -2010906624;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r5,r7,27608
	ctx.r5.s64 = ctx.r7.s64 + 27608;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096950
	ctx.lr = 0x88246E70;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88246E7C"))) PPC_WEAK_FUNC(sub_88246E7C);
PPC_FUNC_IMPL(__imp__sub_88246E7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88246E80"))) PPC_WEAK_FUNC(sub_88246E80);
PPC_FUNC_IMPL(__imp__sub_88246E80) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x88246E88;
	__savegprlr_27(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x88246EA8;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// bgt cr6,0x88247298
	if (ctx.cr6.gt) goto loc_88247298;
	// lis r12,-30684
	ctx.r12.s64 = -2010906624;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,28368
	ctx.r12.s64 = ctx.r12.s64 + 28368;
	// lwzx r0,r12,r0
	ctx.r0.u64 = PPC_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u64) {
	case 0:
		goto loc_88246EFC;
	case 1:
		goto loc_88247298;
	case 2:
		goto loc_88247298;
	case 3:
		goto loc_88247298;
	case 4:
		goto loc_88247298;
	case 5:
		goto loc_88246FBC;
	case 6:
		goto loc_882470B0;
	case 7:
		goto loc_88247298;
	case 8:
		goto loc_88247150;
	case 9:
		goto loc_88247218;
	case 10:
		goto loc_8824726C;
	default:
		__builtin_unreachable();
	}
	// lbz r1,28412(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 28412);
	// lbz r1,29336(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 29336);
	// lbz r1,29336(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 29336);
	// lbz r1,29336(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 29336);
	// lbz r1,29336(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 29336);
	// lbz r1,28604(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 28604);
	// lbz r1,28848(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 28848);
	// lbz r1,29336(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 29336);
	// lbz r1,29008(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 29008);
	// lbz r1,29208(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 29208);
	// lbz r1,29292(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 29292);
loc_88246EFC:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88247298
	if (ctx.cr0.gt) goto loc_88247298;
	// li r11,4
	ctx.r11.s64 = 4;
	// lis r10,60
	ctx.r10.s64 = 3932160;
	// stw r11,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r11.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r8,40(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// subfic r7,r8,2
	ctx.xer.ca = ctx.r8.u32 <= 2;
	ctx.r7.s64 = 2 - ctx.r8.s64;
	// mullw r6,r7,r10
	ctx.r6.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// lis r5,308
	ctx.r5.s64 = 20185088;
	// lis r4,-30685
	ctx.r4.s64 = -2010972160;
	// stw r5,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r4,-19528
	ctx.r4.s64 = ctx.r4.s64 + -19528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x88246F4C;
	sub_880966A8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r3,-30696
	ctx.r3.s64 = -2011693056;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// addi r4,r3,15664
	ctx.r4.s64 = ctx.r3.s64 + 15664;
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// bl 0x88096cb8
	ctx.lr = 0x88246F84;
	sub_88096CB8(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,15536
	ctx.r4.s64 = ctx.r11.s64 + 15536;
	// bl 0x88096cb8
	ctx.lr = 0x88246F9C;
	sub_88096CB8(ctx, base);
	// li r10,5
	ctx.r10.s64 = 5;
	// li r9,32
	ctx.r9.s64 = 32;
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_88246FBC:
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// li r28,1
	ctx.r28.s64 = 1;
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x8824701c
	if (!ctx.cr6.eq) goto loc_8824701C;
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// lis r10,60
	ctx.r10.s64 = 3932160;
	// stw r11,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r11.u32);
	// lis r9,308
	ctx.r9.s64 = 20185088;
	// lis r6,-30685
	ctx.r6.s64 = -2010972160;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r6,-19528
	ctx.r4.s64 = ctx.r6.s64 + -19528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addi r8,r11,2
	ctx.r8.s64 = ctx.r11.s64 + 2;
	// mullw r7,r8,r10
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// bl 0x880966a8
	ctx.lr = 0x88247010;
	sub_880966A8(ctx, base);
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// neg r4,r5
	ctx.r4.s64 = -ctx.r5.s64;
	// stw r4,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r4.u32);
loc_8824701C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096e28
	ctx.lr = 0x88247028;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88247298
	if (!ctx.cr6.eq) goto loc_88247298;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x88096e28
	ctx.lr = 0x8824703C;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88247298
	if (!ctx.cr6.eq) goto loc_88247298;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88247070
	if (ctx.cr6.eq) goto loc_88247070;
loc_88247050:
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88247298
	if (ctx.cr0.gt) goto loc_88247298;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_88247070:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// lis r10,-30696
	ctx.r10.s64 = -2011693056;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,2288
	ctx.r4.s64 = ctx.r10.s64 + 2288;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x88247090;
	sub_88097078(ctx, base);
	// li r9,6
	ctx.r9.s64 = 6;
	// li r8,96
	ctx.r8.s64 = 96;
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r8,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_882470B0:
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x88247110
	if (!ctx.cr6.eq) goto loc_88247110;
	// li r11,4
	ctx.r11.s64 = 4;
	// lis r10,60
	ctx.r10.s64 = 3932160;
	// stw r11,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r11.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addi r8,r11,2
	ctx.r8.s64 = ctx.r11.s64 + 2;
	// lis r7,308
	ctx.r7.s64 = 20185088;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// mullw r6,r8,r10
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// lis r4,-30685
	ctx.r4.s64 = -2010972160;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r4,-19528
	ctx.r4.s64 = ctx.r4.s64 + -19528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x88247104;
	sub_880966A8(ctx, base);
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// neg r11,r3
	ctx.r11.s64 = -ctx.r3.s64;
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
loc_88247110:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88247050
	if (!ctx.cr6.eq) goto loc_88247050;
	// li r11,20
	ctx.r11.s64 = 20;
	// lis r10,-30696
	ctx.r10.s64 = -2011693056;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,1864
	ctx.r4.s64 = ctx.r10.s64 + 1864;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x88247138;
	sub_88097078(ctx, base);
	// li r9,8
	ctx.r9.s64 = 8;
	// stw r3,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_88247150:
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// li r28,1
	ctx.r28.s64 = 1;
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// lis r27,308
	ctx.r27.s64 = 20185088;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x882471b0
	if (!ctx.cr6.eq) goto loc_882471B0;
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// lis r10,60
	ctx.r10.s64 = 3932160;
	// stw r27,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r27.u32);
	// stw r11,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r11.u32);
	// lis r9,-30685
	ctx.r9.s64 = -2010972160;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,-19528
	ctx.r4.s64 = ctx.r9.s64 + -19528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addi r8,r11,2
	ctx.r8.s64 = ctx.r11.s64 + 2;
	// mullw r7,r8,r10
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// bl 0x880966a8
	ctx.lr = 0x882471A4;
	sub_880966A8(ctx, base);
	// lwz r6,44(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// neg r5,r6
	ctx.r5.s64 = -ctx.r6.s64;
	// stw r5,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r5.u32);
loc_882471B0:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x88096e28
	ctx.lr = 0x882471BC;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88247298
	if (!ctx.cr6.eq) goto loc_88247298;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096dd0
	ctx.lr = 0x882471D0;
	sub_88096DD0(ctx, base);
	// li r11,9
	ctx.r11.s64 = 9;
	// li r10,32
	ctx.r10.s64 = 32;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// li r9,12
	ctx.r9.s64 = 12;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lis r8,120
	ctx.r8.s64 = 7864320;
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// stw r9,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r9.u32);
	// lis r7,-30685
	ctx.r7.s64 = -2010972160;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r27,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r27.u32);
	// addi r4,r7,-19528
	ctx.r4.s64 = ctx.r7.s64 + -19528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x8824720C;
	sub_880966A8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_88247218:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88247298
	if (ctx.cr0.gt) goto loc_88247298;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,15416
	ctx.r4.s64 = ctx.r11.s64 + 15416;
	// bl 0x88096cb8
	ctx.lr = 0x8824723C;
	sub_88096CB8(ctx, base);
	// lis r10,-30696
	ctx.r10.s64 = -2011693056;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// addi r4,r10,15296
	ctx.r4.s64 = ctx.r10.s64 + 15296;
	// bl 0x88096cb8
	ctx.lr = 0x88247250;
	sub_88096CB8(ctx, base);
	// li r9,10
	ctx.r9.s64 = 10;
	// li r8,64
	ctx.r8.s64 = 64;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r8,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_8824726C:
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x88247298
	if (!ctx.cr6.eq) goto loc_88247298;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88247050
	if (!ctx.cr6.eq) goto loc_88247050;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096830
	ctx.lr = 0x88247298;
	sub_88096830(ctx, base);
loc_88247298:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_882472A4"))) PPC_WEAK_FUNC(sub_882472A4);
PPC_FUNC_IMPL(__imp__sub_882472A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_882472A8"))) PPC_WEAK_FUNC(sub_882472A8);
PPC_FUNC_IMPL(__imp__sub_882472A8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x882472B0;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x882472D0;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// bgt cr6,0x882475f0
	if (ctx.cr6.gt) goto loc_882475F0;
	// lis r12,-30684
	ctx.r12.s64 = -2010906624;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,29432
	ctx.r12.s64 = ctx.r12.s64 + 29432;
	// lwzx r0,r12,r0
	ctx.r0.u64 = PPC_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u64) {
	case 0:
		goto loc_88247324;
	case 1:
		goto loc_882473E0;
	case 2:
		goto loc_882475F0;
	case 3:
		goto loc_882475F0;
	case 4:
		goto loc_882475F0;
	case 5:
		goto loc_882475F0;
	case 6:
		goto loc_882475F0;
	case 7:
		goto loc_882475F0;
	case 8:
		goto loc_882475F0;
	case 9:
		goto loc_88247570;
	case 10:
		goto loc_882475C4;
	default:
		__builtin_unreachable();
	}
	// lbz r1,29476(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 29476);
	// lbz r1,29664(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 29664);
	// lbz r1,30192(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 30192);
	// lbz r1,30192(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 30192);
	// lbz r1,30192(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 30192);
	// lbz r1,30192(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 30192);
	// lbz r1,30192(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 30192);
	// lbz r1,30192(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 30192);
	// lbz r1,30192(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 30192);
	// lbz r1,30064(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 30064);
	// lbz r1,30148(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 30148);
loc_88247324:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x882475f0
	if (ctx.cr0.gt) goto loc_882475F0;
	// li r11,4
	ctx.r11.s64 = 4;
	// lis r10,60
	ctx.r10.s64 = 3932160;
	// stw r11,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r11.u32);
	// lis r6,308
	ctx.r6.s64 = 20185088;
	// lwz r9,40(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// subfic r8,r9,2
	ctx.xer.ca = ctx.r9.u32 <= 2;
	ctx.r8.s64 = 2 - ctx.r9.s64;
	// mullw r7,r8,r10
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// li r28,1
	ctx.r28.s64 = 1;
	// lis r4,-30685
	ctx.r4.s64 = -2010972160;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r4,-19528
	ctx.r4.s64 = ctx.r4.s64 + -19528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x88247374;
	sub_880966A8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r3,-30696
	ctx.r3.s64 = -2011693056;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// addi r4,r3,15664
	ctx.r4.s64 = ctx.r3.s64 + 15664;
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// bl 0x88096cb8
	ctx.lr = 0x882473AC;
	sub_88096CB8(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,15536
	ctx.r4.s64 = ctx.r11.s64 + 15536;
	// bl 0x88096cb8
	ctx.lr = 0x882473C4;
	sub_88096CB8(ctx, base);
	// li r10,32
	ctx.r10.s64 = 32;
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r28,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_882473E0:
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// li r28,4
	ctx.r28.s64 = 4;
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x88247440
	if (!ctx.cr6.eq) goto loc_88247440;
	// stw r28,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r28.u32);
	// lis r10,60
	ctx.r10.s64 = 3932160;
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addi r9,r11,2
	ctx.r9.s64 = ctx.r11.s64 + 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// lis r7,308
	ctx.r7.s64 = 20185088;
	// mullw r6,r9,r10
	ctx.r6.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// lis r4,-30685
	ctx.r4.s64 = -2010972160;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r4,-19528
	ctx.r4.s64 = ctx.r4.s64 + -19528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x88247434;
	sub_880966A8(ctx, base);
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// neg r11,r3
	ctx.r11.s64 = -ctx.r3.s64;
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
loc_88247440:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096e28
	ctx.lr = 0x8824744C;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x882475f0
	if (!ctx.cr6.eq) goto loc_882475F0;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88247480
	if (ctx.cr6.eq) goto loc_88247480;
loc_88247460:
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x882475f0
	if (ctx.cr0.gt) goto loc_882475F0;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_88247480:
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// bge 0x882475f0
	if (!ctx.cr0.lt) goto loc_882475F0;
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lis r8,-30696
	ctx.r8.s64 = -2011693056;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,-392
	ctx.r4.s64 = ctx.r8.s64 + -392;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x88097078
	ctx.lr = 0x882474BC;
	sub_88097078(ctx, base);
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// stw r3,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r3.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// blt cr6,0x882474d8
	if (ctx.cr6.lt) goto loc_882474D8;
	// stw r28,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r28.u32);
loc_882474D8:
	// lwz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// lis r10,-30696
	ctx.r10.s64 = -2011693056;
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r8,60(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// mulli r7,r11,-60
	ctx.r7.s64 = ctx.r11.s64 * -60;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// rlwinm r6,r7,1,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0x1;
	// addi r4,r10,2056
	ctx.r4.s64 = ctx.r10.s64 + 2056;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x8824750C;
	sub_88097078(ctx, base);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// addi r5,r10,-3
	ctx.r5.s64 = ctx.r10.s64 + -3;
	// lwz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r5,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r5.u32);
	// stw r11,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// blt cr6,0x8824753c
	if (ctx.cr6.lt) goto loc_8824753C;
	// li r11,6
	ctx.r11.s64 = 6;
	// stw r11,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
loc_8824753C:
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// stw r11,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// bgt 0x882475f0
	if (ctx.cr0.gt) goto loc_882475F0;
	// li r11,9
	ctx.r11.s64 = 9;
	// li r10,32
	ctx.r10.s64 = 32;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_88247570:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x882475f0
	if (ctx.cr0.gt) goto loc_882475F0;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,15416
	ctx.r4.s64 = ctx.r11.s64 + 15416;
	// bl 0x88096cb8
	ctx.lr = 0x88247594;
	sub_88096CB8(ctx, base);
	// lis r10,-30696
	ctx.r10.s64 = -2011693056;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// addi r4,r10,15296
	ctx.r4.s64 = ctx.r10.s64 + 15296;
	// bl 0x88096cb8
	ctx.lr = 0x882475A8;
	sub_88096CB8(ctx, base);
	// li r9,16
	ctx.r9.s64 = 16;
	// li r8,10
	ctx.r8.s64 = 10;
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r8,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_882475C4:
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x882475f0
	if (!ctx.cr6.eq) goto loc_882475F0;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88247460
	if (!ctx.cr6.eq) goto loc_88247460;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096830
	ctx.lr = 0x882475F0;
	sub_88096830(ctx, base);
loc_882475F0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_882475FC"))) PPC_WEAK_FUNC(sub_882475FC);
PPC_FUNC_IMPL(__imp__sub_882475FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88247600"))) PPC_WEAK_FUNC(sub_88247600);
PPC_FUNC_IMPL(__imp__sub_88247600) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88247608;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x88247628;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// bgt cr6,0x8824783c
	if (ctx.cr6.gt) goto loc_8824783C;
	// beq cr6,0x882477a4
	if (ctx.cr6.eq) goto loc_882477A4;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x882476dc
	if (ctx.cr6.lt) goto loc_882476DC;
	// bne cr6,0x882478a4
	if (!ctx.cr6.eq) goto loc_882478A4;
	// lwz r11,44(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r11.u32);
	// bge 0x882478a4
	if (!ctx.cr0.lt) goto loc_882478A4;
	// lwz r11,48(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lis r10,-30696
	ctx.r10.s64 = -2011693056;
	// lwz r9,40(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r8,56(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// addi r4,r10,3264
	ctx.r4.s64 = ctx.r10.s64 + 3264;
	// lwz r7,64(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// clrlwi r6,r9,31
	ctx.r6.u64 = ctx.r9.u32 & 0x1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// bl 0x88097078
	ctx.lr = 0x88247690;
	sub_88097078(ctx, base);
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// stw r3,13396(r29)
	PPC_STORE_U32(ctx.r29.u32 + 13396, ctx.r3.u32);
	// lwz r5,52(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// addi r4,r9,1
	ctx.r4.s64 = ctx.r9.s64 + 1;
	// stw r3,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r3.u32);
	// addic. r11,r5,-1
	ctx.xer.ca = ctx.r5.u32 > 0;
	ctx.r11.s64 = ctx.r5.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r4,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r4.u32);
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// bgt 0x882478a4
	if (ctx.cr0.gt) goto loc_882478A4;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,5
	ctx.r10.s64 = 5;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_882476DC:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x882478a4
	if (ctx.cr0.gt) goto loc_882478A4;
	// li r11,12
	ctx.r11.s64 = 12;
	// lis r10,120
	ctx.r10.s64 = 7864320;
	// lis r9,292
	ctx.r9.s64 = 19136512;
	// stw r11,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r11.u32);
	// li r28,1
	ctx.r28.s64 = 1;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// lis r8,-30685
	ctx.r8.s64 = -2010972160;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,-19528
	ctx.r4.s64 = ctx.r8.s64 + -19528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x88247720;
	sub_880966A8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lwz r7,13404(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 13404);
	// cmpwi cr6,r7,5
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 5, ctx.xer);
	// beq cr6,0x88247768
	if (ctx.cr6.eq) goto loc_88247768;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,14872
	ctx.r4.s64 = ctx.r11.s64 + 14872;
	// bl 0x88096cb8
	ctx.lr = 0x88247764;
	sub_88096CB8(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
loc_88247768:
	// lwz r11,13492(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 13492);
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x8824778c
	if (ctx.cr6.eq) goto loc_8824778C;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,14760
	ctx.r4.s64 = ctx.r11.s64 + 14760;
	// bl 0x88096cb8
	ctx.lr = 0x88247788;
	sub_88096CB8(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
loc_8824778C:
	// li r11,32
	ctx.r11.s64 = 32;
	// stw r28,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_882477A4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096e28
	ctx.lr = 0x882477B0;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x882478a4
	if (!ctx.cr6.eq) goto loc_882478A4;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x88096e28
	ctx.lr = 0x882477C4;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x882478a4
	if (!ctx.cr6.eq) goto loc_882478A4;
	// lwz r11,13404(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 13404);
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x882477f0
	if (ctx.cr6.eq) goto loc_882477F0;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,14648
	ctx.r4.s64 = ctx.r11.s64 + 14648;
	// bl 0x88096cb8
	ctx.lr = 0x882477EC;
	sub_88096CB8(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
loc_882477F0:
	// lwz r11,13492(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 13492);
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x88247814
	if (ctx.cr6.eq) goto loc_88247814;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,14536
	ctx.r4.s64 = ctx.r11.s64 + 14536;
	// bl 0x88096cb8
	ctx.lr = 0x88247810;
	sub_88096CB8(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
loc_88247814:
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,90
	ctx.r10.s64 = 90;
	// li r9,64
	ctx.r9.s64 = 64;
	// stw r11,13396(r29)
	PPC_STORE_U32(ctx.r29.u32 + 13396, ctx.r11.u32);
	// stw r11,13484(r29)
	PPC_STORE_U32(ctx.r29.u32 + 13484, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824783C:
	// cmpwi cr6,r11,90
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 90, ctx.xer);
	// bne cr6,0x882478a4
	if (!ctx.cr6.eq) goto loc_882478A4;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096a68
	ctx.lr = 0x88247850;
	sub_88096A68(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x882478a4
	if (!ctx.cr6.eq) goto loc_882478A4;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x88096a68
	ctx.lr = 0x88247864;
	sub_88096A68(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x882478a4
	if (!ctx.cr6.eq) goto loc_882478A4;
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x882478a4
	if (!ctx.cr6.eq) goto loc_882478A4;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x882478a4
	if (ctx.cr0.gt) goto loc_882478A4;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// stw r11,15780(r29)
	PPC_STORE_U32(ctx.r29.u32 + 15780, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096830
	ctx.lr = 0x882478A4;
	sub_88096830(ctx, base);
loc_882478A4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_882478B0"))) PPC_WEAK_FUNC(sub_882478B0);
PPC_FUNC_IMPL(__imp__sub_882478B0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x882478B8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,68
	ctx.r5.s64 = 68;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x880968b8
	ctx.lr = 0x882478D8;
	sub_880968B8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,3
	ctx.r10.s64 = 3;
	// li r8,32
	ctx.r8.s64 = 32;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r7,2
	ctx.r7.s64 = 2;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r30,0(r29)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r11.u32);
	// lis r6,-30684
	ctx.r6.s64 = -2010906624;
	// stw r8,56(r9)
	PPC_STORE_U32(ctx.r9.u32 + 56, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,60(r9)
	PPC_STORE_U32(ctx.r9.u32 + 60, ctx.r10.u32);
	// addi r5,r6,28288
	ctx.r5.s64 = ctx.r6.s64 + 28288;
	// stw r10,64(r9)
	PPC_STORE_U32(ctx.r9.u32 + 64, ctx.r10.u32);
	// stw r30,40(r9)
	PPC_STORE_U32(ctx.r9.u32 + 40, ctx.r30.u32);
	// stw r30,44(r9)
	PPC_STORE_U32(ctx.r9.u32 + 44, ctx.r30.u32);
	// stw r7,48(r9)
	PPC_STORE_U32(ctx.r9.u32 + 48, ctx.r7.u32);
	// bl 0x88096950
	ctx.lr = 0x88247928;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88247934"))) PPC_WEAK_FUNC(sub_88247934);
PPC_FUNC_IMPL(__imp__sub_88247934) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88247938"))) PPC_WEAK_FUNC(sub_88247938);
PPC_FUNC_IMPL(__imp__sub_88247938) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88247940;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,76
	ctx.r5.s64 = 76;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x880968b8
	ctx.lr = 0x88247960;
	sub_880968B8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,3
	ctx.r10.s64 = 3;
	// li r8,32
	ctx.r8.s64 = 32;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r7,2
	ctx.r7.s64 = 2;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// li r6,12
	ctx.r6.s64 = 12;
	// lwz r29,0(r29)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// li r28,1
	ctx.r28.s64 = 1;
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r11.u32);
	// stw r8,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r8.u32);
	// lis r5,-30684
	ctx.r5.s64 = -2010906624;
	// stw r10,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r10.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r10,72(r9)
	PPC_STORE_U32(ctx.r9.u32 + 72, ctx.r10.u32);
	// addi r5,r5,29352
	ctx.r5.s64 = ctx.r5.s64 + 29352;
	// stw r29,40(r9)
	PPC_STORE_U32(ctx.r9.u32 + 40, ctx.r29.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r29,44(r9)
	PPC_STORE_U32(ctx.r9.u32 + 44, ctx.r29.u32);
	// stw r7,48(r9)
	PPC_STORE_U32(ctx.r9.u32 + 48, ctx.r7.u32);
	// stw r6,68(r9)
	PPC_STORE_U32(ctx.r9.u32 + 68, ctx.r6.u32);
	// stw r28,64(r9)
	PPC_STORE_U32(ctx.r9.u32 + 64, ctx.r28.u32);
	// bl 0x88096950
	ctx.lr = 0x882479C0;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_882479CC"))) PPC_WEAK_FUNC(sub_882479CC);
PPC_FUNC_IMPL(__imp__sub_882479CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_882479D0"))) PPC_WEAK_FUNC(sub_882479D0);
PPC_FUNC_IMPL(__imp__sub_882479D0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x882479D8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,72
	ctx.r5.s64 = 72;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x880968b8
	ctx.lr = 0x882479F8;
	sub_880968B8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r8,48
	ctx.r8.s64 = 48;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r7,5
	ctx.r7.s64 = 5;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// li r6,20
	ctx.r6.s64 = 20;
	// lwz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// li r28,40
	ctx.r28.s64 = 40;
	// stw r5,40(r10)
	PPC_STORE_U32(ctx.r10.u32 + 40, ctx.r5.u32);
	// stw r9,44(r10)
	PPC_STORE_U32(ctx.r10.u32 + 44, ctx.r9.u32);
	// lis r3,-30684
	ctx.r3.s64 = -2010906624;
	// stw r8,48(r10)
	PPC_STORE_U32(ctx.r10.u32 + 48, ctx.r8.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r7,52(r10)
	PPC_STORE_U32(ctx.r10.u32 + 52, ctx.r7.u32);
	// addi r5,r3,30208
	ctx.r5.s64 = ctx.r3.s64 + 30208;
	// stw r6,56(r10)
	PPC_STORE_U32(ctx.r10.u32 + 56, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r28,60(r10)
	PPC_STORE_U32(ctx.r10.u32 + 60, ctx.r28.u32);
	// stw r11,64(r10)
	PPC_STORE_U32(ctx.r10.u32 + 64, ctx.r11.u32);
	// bl 0x88096950
	ctx.lr = 0x88247A50;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88247A5C"))) PPC_WEAK_FUNC(sub_88247A5C);
PPC_FUNC_IMPL(__imp__sub_88247A5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88247A60"))) PPC_WEAK_FUNC(sub_88247A60);
PPC_FUNC_IMPL(__imp__sub_88247A60) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88247A68;
	__savegprlr_29(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x88247A84;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bgt cr6,0x88247b8c
	if (ctx.cr6.gt) goto loc_88247B8C;
	// beq cr6,0x88247b30
	if (ctx.cr6.eq) goto loc_88247B30;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88247b04
	if (ctx.cr6.eq) goto loc_88247B04;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// bne cr6,0x88247c4c
	if (!ctx.cr6.eq) goto loc_88247C4C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096710
	ctx.lr = 0x88247AB4;
	sub_88096710(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x88247c4c
	if (!ctx.cr6.eq) goto loc_88247C4C;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88247c4c
	if (ctx.cr0.gt) goto loc_88247C4C;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r10,-30684
	ctx.r10.s64 = -2010906624;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,31032
	ctx.r4.s64 = ctx.r10.s64 + 31032;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x880969a8
	ctx.lr = 0x88247AE8;
	sub_880969A8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// bl 0x88096760
	ctx.lr = 0x88247AFC;
	sub_88096760(ctx, base);
	// li r8,20
	ctx.r8.s64 = 20;
	// b 0x88247c40
	goto loc_88247C40;
loc_88247B04:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88247c4c
	if (ctx.cr0.gt) goto loc_88247C4C;
	// li r11,10
	ctx.r11.s64 = 10;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_88247B30:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096710
	ctx.lr = 0x88247B3C;
	sub_88096710(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x88247c4c
	if (!ctx.cr6.eq) goto loc_88247C4C;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88247c4c
	if (ctx.cr0.gt) goto loc_88247C4C;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r10,-30684
	ctx.r10.s64 = -2010906624;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,31184
	ctx.r4.s64 = ctx.r10.s64 + 31184;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x880969a8
	ctx.lr = 0x88247B70;
	sub_880969A8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// bl 0x88096760
	ctx.lr = 0x88247B84;
	sub_88096760(ctx, base);
	// li r8,40
	ctx.r8.s64 = 40;
	// b 0x88247c40
	goto loc_88247C40;
loc_88247B8C:
	// cmpwi cr6,r11,40
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 40, ctx.xer);
	// beq cr6,0x88247be8
	if (ctx.cr6.eq) goto loc_88247BE8;
	// cmpwi cr6,r11,90
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 90, ctx.xer);
	// bne cr6,0x88247c4c
	if (!ctx.cr6.eq) goto loc_88247C4C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096710
	ctx.lr = 0x88247BA8;
	sub_88096710(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x88247c4c
	if (!ctx.cr6.eq) goto loc_88247C4C;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88247c4c
	if (ctx.cr0.gt) goto loc_88247C4C;
	// lwz r11,15772(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 15772);
	// li r10,10
	ctx.r10.s64 = 10;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r8,15772(r29)
	PPC_STORE_U32(ctx.r29.u32 + 15772, ctx.r8.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_88247BE8:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096710
	ctx.lr = 0x88247BF4;
	sub_88096710(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x88247c4c
	if (!ctx.cr6.eq) goto loc_88247C4C;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88247c4c
	if (ctx.cr0.gt) goto loc_88247C4C;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r10,-30684
	ctx.r10.s64 = -2010906624;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,30896
	ctx.r4.s64 = ctx.r10.s64 + 30896;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x880969a8
	ctx.lr = 0x88247C28;
	sub_880969A8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// bl 0x88096760
	ctx.lr = 0x88247C3C;
	sub_88096760(ctx, base);
	// li r8,90
	ctx.r8.s64 = 90;
loc_88247C40:
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r8,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// stw r7,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r7.u32);
loc_88247C4C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88247C58"))) PPC_WEAK_FUNC(sub_88247C58);
PPC_FUNC_IMPL(__imp__sub_88247C58) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88247C60;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x88247C80;
	sub_880968B8(ctx, base);
	// li r28,0
	ctx.r28.s64 = 0;
	// li r11,-1
	ctx.r11.s64 = -1;
	// lis r10,120
	ctx.r10.s64 = 7864320;
	// stw r28,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r28.u32);
	// stw r28,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r28.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x88247cac
	if (!ctx.cr6.lt) goto loc_88247CAC;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
loc_88247CAC:
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// li r11,4
	ctx.r11.s64 = 4;
	// li r10,256
	ctx.r10.s64 = 256;
	// lis r9,248
	ctx.r9.s64 = 16252928;
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// stw r10,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// lis r8,-30685
	ctx.r8.s64 = -2010972160;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// addi r4,r8,-19528
	ctx.r4.s64 = ctx.r8.s64 + -19528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x88247CE0;
	sub_880966A8(ctx, base);
	// stw r28,15772(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15772, ctx.r28.u32);
	// lis r7,-30684
	ctx.r7.s64 = -2010906624;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r5,r7,31328
	ctx.r5.s64 = ctx.r7.s64 + 31328;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096950
	ctx.lr = 0x88247CF8;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88247D04"))) PPC_WEAK_FUNC(sub_88247D04);
PPC_FUNC_IMPL(__imp__sub_88247D04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88247D08"))) PPC_WEAK_FUNC(sub_88247D08);
PPC_FUNC_IMPL(__imp__sub_88247D08) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x88247D10;
	__savegprlr_27(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x88247D30;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// bgt cr6,0x88248120
	if (ctx.cr6.gt) goto loc_88248120;
	// lis r12,-30684
	ctx.r12.s64 = -2010906624;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,32088
	ctx.r12.s64 = ctx.r12.s64 + 32088;
	// lwzx r0,r12,r0
	ctx.r0.u64 = PPC_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u64) {
	case 0:
		goto loc_88247D84;
	case 1:
		goto loc_88248120;
	case 2:
		goto loc_88248120;
	case 3:
		goto loc_88248120;
	case 4:
		goto loc_88248120;
	case 5:
		goto loc_88247E44;
	case 6:
		goto loc_88247F38;
	case 7:
		goto loc_88248120;
	case 8:
		goto loc_88247FD8;
	case 9:
		goto loc_882480A0;
	case 10:
		goto loc_882480F4;
	default:
		__builtin_unreachable();
	}
	// lbz r1,32132(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 32132);
	// lbz r1,-32480(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -32480);
	// lbz r1,-32480(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -32480);
	// lbz r1,-32480(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -32480);
	// lbz r1,-32480(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -32480);
	// lbz r1,32324(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 32324);
	// lbz r1,32568(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 32568);
	// lbz r1,-32480(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -32480);
	// lbz r1,32728(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + 32728);
	// lbz r1,-32608(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -32608);
	// lbz r1,-32524(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -32524);
loc_88247D84:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88248120
	if (ctx.cr0.gt) goto loc_88248120;
	// li r11,4
	ctx.r11.s64 = 4;
	// lis r10,60
	ctx.r10.s64 = 3932160;
	// stw r11,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r11.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r8,40(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// subfic r7,r8,2
	ctx.xer.ca = ctx.r8.u32 <= 2;
	ctx.r7.s64 = 2 - ctx.r8.s64;
	// mullw r6,r7,r10
	ctx.r6.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// lis r5,308
	ctx.r5.s64 = 20185088;
	// lis r4,-30685
	ctx.r4.s64 = -2010972160;
	// stw r5,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r4,-19528
	ctx.r4.s64 = ctx.r4.s64 + -19528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x88247DD4;
	sub_880966A8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r3,-30696
	ctx.r3.s64 = -2011693056;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// addi r4,r3,15664
	ctx.r4.s64 = ctx.r3.s64 + 15664;
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// bl 0x88096cb8
	ctx.lr = 0x88247E0C;
	sub_88096CB8(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,15536
	ctx.r4.s64 = ctx.r11.s64 + 15536;
	// bl 0x88096cb8
	ctx.lr = 0x88247E24;
	sub_88096CB8(ctx, base);
	// li r10,5
	ctx.r10.s64 = 5;
	// li r9,32
	ctx.r9.s64 = 32;
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_88247E44:
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// li r28,1
	ctx.r28.s64 = 1;
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x88247ea4
	if (!ctx.cr6.eq) goto loc_88247EA4;
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// lis r10,60
	ctx.r10.s64 = 3932160;
	// stw r11,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r11.u32);
	// lis r9,308
	ctx.r9.s64 = 20185088;
	// lis r6,-30685
	ctx.r6.s64 = -2010972160;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r6,-19528
	ctx.r4.s64 = ctx.r6.s64 + -19528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addi r8,r11,2
	ctx.r8.s64 = ctx.r11.s64 + 2;
	// mullw r7,r8,r10
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// bl 0x880966a8
	ctx.lr = 0x88247E98;
	sub_880966A8(ctx, base);
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// neg r4,r5
	ctx.r4.s64 = -ctx.r5.s64;
	// stw r4,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r4.u32);
loc_88247EA4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096e28
	ctx.lr = 0x88247EB0;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88248120
	if (!ctx.cr6.eq) goto loc_88248120;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x88096e28
	ctx.lr = 0x88247EC4;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88248120
	if (!ctx.cr6.eq) goto loc_88248120;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88247ef8
	if (ctx.cr6.eq) goto loc_88247EF8;
loc_88247ED8:
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88248120
	if (ctx.cr0.gt) goto loc_88248120;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_88247EF8:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// lis r10,-30686
	ctx.r10.s64 = -2011037696;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-29040
	ctx.r4.s64 = ctx.r10.s64 + -29040;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x88247F18;
	sub_88097078(ctx, base);
	// li r9,6
	ctx.r9.s64 = 6;
	// li r8,96
	ctx.r8.s64 = 96;
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r8,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_88247F38:
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x88247f98
	if (!ctx.cr6.eq) goto loc_88247F98;
	// li r11,4
	ctx.r11.s64 = 4;
	// lis r10,60
	ctx.r10.s64 = 3932160;
	// stw r11,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r11.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addi r8,r11,2
	ctx.r8.s64 = ctx.r11.s64 + 2;
	// lis r7,308
	ctx.r7.s64 = 20185088;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// mullw r6,r8,r10
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// lis r4,-30685
	ctx.r4.s64 = -2010972160;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r4,-19528
	ctx.r4.s64 = ctx.r4.s64 + -19528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x88247F8C;
	sub_880966A8(ctx, base);
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// neg r11,r3
	ctx.r11.s64 = -ctx.r3.s64;
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
loc_88247F98:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88247ed8
	if (!ctx.cr6.eq) goto loc_88247ED8;
	// li r11,20
	ctx.r11.s64 = 20;
	// lis r10,-30686
	ctx.r10.s64 = -2011037696;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-29480
	ctx.r4.s64 = ctx.r10.s64 + -29480;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x88247FC0;
	sub_88097078(ctx, base);
	// li r9,8
	ctx.r9.s64 = 8;
	// stw r3,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_88247FD8:
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// li r28,1
	ctx.r28.s64 = 1;
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// lis r27,308
	ctx.r27.s64 = 20185088;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x88248038
	if (!ctx.cr6.eq) goto loc_88248038;
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// lis r10,60
	ctx.r10.s64 = 3932160;
	// stw r27,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r27.u32);
	// stw r11,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r11.u32);
	// lis r9,-30685
	ctx.r9.s64 = -2010972160;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,-19528
	ctx.r4.s64 = ctx.r9.s64 + -19528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addi r8,r11,2
	ctx.r8.s64 = ctx.r11.s64 + 2;
	// mullw r7,r8,r10
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// bl 0x880966a8
	ctx.lr = 0x8824802C;
	sub_880966A8(ctx, base);
	// lwz r6,44(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// neg r5,r6
	ctx.r5.s64 = -ctx.r6.s64;
	// stw r5,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r5.u32);
loc_88248038:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x88096e28
	ctx.lr = 0x88248044;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88248120
	if (!ctx.cr6.eq) goto loc_88248120;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096dd0
	ctx.lr = 0x88248058;
	sub_88096DD0(ctx, base);
	// li r11,9
	ctx.r11.s64 = 9;
	// li r10,32
	ctx.r10.s64 = 32;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// li r9,12
	ctx.r9.s64 = 12;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lis r8,120
	ctx.r8.s64 = 7864320;
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// stw r9,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r9.u32);
	// lis r7,-30685
	ctx.r7.s64 = -2010972160;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r27,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r27.u32);
	// addi r4,r7,-19528
	ctx.r4.s64 = ctx.r7.s64 + -19528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x88248094;
	sub_880966A8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_882480A0:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88248120
	if (ctx.cr0.gt) goto loc_88248120;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,15416
	ctx.r4.s64 = ctx.r11.s64 + 15416;
	// bl 0x88096cb8
	ctx.lr = 0x882480C4;
	sub_88096CB8(ctx, base);
	// lis r10,-30696
	ctx.r10.s64 = -2011693056;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// addi r4,r10,15296
	ctx.r4.s64 = ctx.r10.s64 + 15296;
	// bl 0x88096cb8
	ctx.lr = 0x882480D8;
	sub_88096CB8(ctx, base);
	// li r9,10
	ctx.r9.s64 = 10;
	// li r8,64
	ctx.r8.s64 = 64;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r8,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_882480F4:
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x88248120
	if (!ctx.cr6.eq) goto loc_88248120;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88247ed8
	if (!ctx.cr6.eq) goto loc_88247ED8;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096830
	ctx.lr = 0x88248120;
	sub_88096830(ctx, base);
loc_88248120:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824812C"))) PPC_WEAK_FUNC(sub_8824812C);
PPC_FUNC_IMPL(__imp__sub_8824812C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88248130"))) PPC_WEAK_FUNC(sub_88248130);
PPC_FUNC_IMPL(__imp__sub_88248130) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88248138;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lwz r30,2304(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x880968b8
	ctx.lr = 0x88248158;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// bgt cr6,0x88248478
	if (ctx.cr6.gt) goto loc_88248478;
	// lis r12,-30683
	ctx.r12.s64 = -2010841088;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,-32384
	ctx.r12.s64 = ctx.r12.s64 + -32384;
	// lwzx r0,r12,r0
	ctx.r0.u64 = PPC_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u64) {
	case 0:
		goto loc_882481AC;
	case 1:
		goto loc_88248268;
	case 2:
		goto loc_88248478;
	case 3:
		goto loc_88248478;
	case 4:
		goto loc_88248478;
	case 5:
		goto loc_88248478;
	case 6:
		goto loc_88248478;
	case 7:
		goto loc_88248478;
	case 8:
		goto loc_88248478;
	case 9:
		goto loc_8824840C;
	case 10:
		goto loc_88248460;
	default:
		__builtin_unreachable();
	}
	// lbz r1,-32340(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -32340);
	// lbz r1,-32152(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -32152);
	// lbz r1,-31624(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -31624);
	// lbz r1,-31624(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -31624);
	// lbz r1,-31624(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -31624);
	// lbz r1,-31624(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -31624);
	// lbz r1,-31624(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -31624);
	// lbz r1,-31624(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -31624);
	// lbz r1,-31624(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -31624);
	// lbz r1,-31732(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -31732);
	// lbz r1,-31648(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -31648);
loc_882481AC:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88248478
	if (ctx.cr0.gt) goto loc_88248478;
	// li r11,4
	ctx.r11.s64 = 4;
	// lis r10,60
	ctx.r10.s64 = 3932160;
	// stw r11,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r11.u32);
	// lis r6,308
	ctx.r6.s64 = 20185088;
	// lwz r9,40(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// subfic r8,r9,2
	ctx.xer.ca = ctx.r9.u32 <= 2;
	ctx.r8.s64 = 2 - ctx.r9.s64;
	// mullw r7,r8,r10
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// li r28,1
	ctx.r28.s64 = 1;
	// lis r4,-30685
	ctx.r4.s64 = -2010972160;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r4,-19528
	ctx.r4.s64 = ctx.r4.s64 + -19528;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x880966a8
	ctx.lr = 0x882481FC;
	sub_880966A8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r3,-30696
	ctx.r3.s64 = -2011693056;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// addi r4,r3,15664
	ctx.r4.s64 = ctx.r3.s64 + 15664;
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lwz r3,24(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// bl 0x88096cb8
	ctx.lr = 0x88248234;
	sub_88096CB8(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// lwz r3,24(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,15536
	ctx.r4.s64 = ctx.r11.s64 + 15536;
	// bl 0x88096cb8
	ctx.lr = 0x8824824C;
	sub_88096CB8(ctx, base);
	// li r10,32
	ctx.r10.s64 = 32;
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r28,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_88248268:
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 5724);
	// li r28,4
	ctx.r28.s64 = 4;
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x882482c8
	if (!ctx.cr6.eq) goto loc_882482C8;
	// stw r28,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r28.u32);
	// lis r10,60
	ctx.r10.s64 = 3932160;
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addi r9,r11,2
	ctx.r9.s64 = ctx.r11.s64 + 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// lis r7,308
	ctx.r7.s64 = 20185088;
	// mullw r6,r9,r10
	ctx.r6.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// lis r4,-30685
	ctx.r4.s64 = -2010972160;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r4,-19528
	ctx.r4.s64 = ctx.r4.s64 + -19528;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x880966a8
	ctx.lr = 0x882482BC;
	sub_880966A8(ctx, base);
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// neg r11,r3
	ctx.r11.s64 = -ctx.r3.s64;
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
loc_882482C8:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096e28
	ctx.lr = 0x882482D4;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88248478
	if (!ctx.cr6.eq) goto loc_88248478;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88248308
	if (ctx.cr6.eq) goto loc_88248308;
loc_882482E8:
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88248478
	if (ctx.cr0.gt) goto loc_88248478;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_88248308:
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// bge 0x88248478
	if (!ctx.cr0.lt) goto loc_88248478;
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lis r8,-30686
	ctx.r8.s64 = -2011037696;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,-28792
	ctx.r4.s64 = ctx.r8.s64 + -28792;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x88097078
	ctx.lr = 0x88248344;
	sub_88097078(ctx, base);
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// stw r3,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r3.u32);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x88248358
	if (!ctx.cr6.eq) goto loc_88248358;
	// stw r28,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r28.u32);
loc_88248358:
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x88248368
	if (!ctx.cr6.eq) goto loc_88248368;
	// li r11,6
	ctx.r11.s64 = 6;
	// stw r11,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
loc_88248368:
	// lwz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// lis r10,-30686
	ctx.r10.s64 = -2011037696;
	// lwz r9,60(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r8,68(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// mulli r7,r11,-60
	ctx.r7.s64 = ctx.r11.s64 * -60;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// rlwinm r6,r7,1,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0x1;
	// addi r4,r10,-29288
	ctx.r4.s64 = ctx.r10.s64 + -29288;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88097078
	ctx.lr = 0x8824839C;
	sub_88097078(ctx, base);
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// addi r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -2;
	// stw r11,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bgt cr6,0x882483b8
	if (ctx.cr6.gt) goto loc_882483B8;
	// stw r28,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r28.u32);
loc_882483B8:
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// lwz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r11,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// blt cr6,0x882483d8
	if (ctx.cr6.lt) goto loc_882483D8;
	// li r11,8
	ctx.r11.s64 = 8;
	// stw r11,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
loc_882483D8:
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// stw r11,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// bgt 0x88248478
	if (ctx.cr0.gt) goto loc_88248478;
	// li r11,9
	ctx.r11.s64 = 9;
	// li r10,32
	ctx.r10.s64 = 32;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824840C:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88248478
	if (ctx.cr0.gt) goto loc_88248478;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// lwz r3,24(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,15416
	ctx.r4.s64 = ctx.r11.s64 + 15416;
	// bl 0x88096cb8
	ctx.lr = 0x88248430;
	sub_88096CB8(ctx, base);
	// lis r10,-30696
	ctx.r10.s64 = -2011693056;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,24(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// addi r4,r10,15296
	ctx.r4.s64 = ctx.r10.s64 + 15296;
	// bl 0x88096cb8
	ctx.lr = 0x88248444;
	sub_88096CB8(ctx, base);
	// li r9,64
	ctx.r9.s64 = 64;
	// li r8,10
	ctx.r8.s64 = 10;
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r8,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_88248460:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x882482e8
	if (!ctx.cr6.eq) goto loc_882482E8;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88096830
	ctx.lr = 0x88248478;
	sub_88096830(ctx, base);
loc_88248478:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88248484"))) PPC_WEAK_FUNC(sub_88248484);
PPC_FUNC_IMPL(__imp__sub_88248484) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88248488"))) PPC_WEAK_FUNC(sub_88248488);
PPC_FUNC_IMPL(__imp__sub_88248488) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88248490;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x882484B0;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// bgt cr6,0x882486cc
	if (ctx.cr6.gt) goto loc_882486CC;
	// beq cr6,0x88248634
	if (ctx.cr6.eq) goto loc_88248634;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8824856c
	if (ctx.cr6.lt) goto loc_8824856C;
	// bne cr6,0x88248734
	if (!ctx.cr6.eq) goto loc_88248734;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096e28
	ctx.lr = 0x882484DC;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88248734
	if (!ctx.cr6.eq) goto loc_88248734;
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// bge 0x88248734
	if (!ctx.cr0.lt) goto loc_88248734;
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lis r10,-30686
	ctx.r10.s64 = -2011037696;
	// lwz r9,40(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r8,56(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// addi r4,r10,-28064
	ctx.r4.s64 = ctx.r10.s64 + -28064;
	// lwz r7,64(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// clrlwi r6,r9,31
	ctx.r6.u64 = ctx.r9.u32 & 0x1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// bl 0x88097078
	ctx.lr = 0x8824852C;
	sub_88097078(ctx, base);
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// stw r3,13396(r29)
	PPC_STORE_U32(ctx.r29.u32 + 13396, ctx.r3.u32);
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// lwz r5,52(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addic. r11,r5,-1
	ctx.xer.ca = ctx.r5.u32 > 0;
	ctx.r11.s64 = ctx.r5.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// stw r4,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r4.u32);
	// bgt 0x88248734
	if (ctx.cr0.gt) goto loc_88248734;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,5
	ctx.r10.s64 = 5;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824856C:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88248734
	if (ctx.cr0.gt) goto loc_88248734;
	// li r11,12
	ctx.r11.s64 = 12;
	// lis r10,120
	ctx.r10.s64 = 7864320;
	// lis r9,292
	ctx.r9.s64 = 19136512;
	// stw r11,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r11.u32);
	// li r28,1
	ctx.r28.s64 = 1;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// lis r8,-30685
	ctx.r8.s64 = -2010972160;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,-19528
	ctx.r4.s64 = ctx.r8.s64 + -19528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x882485B0;
	sub_880966A8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lwz r7,13404(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 13404);
	// cmpwi cr6,r7,5
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 5, ctx.xer);
	// beq cr6,0x882485f8
	if (ctx.cr6.eq) goto loc_882485F8;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,14872
	ctx.r4.s64 = ctx.r11.s64 + 14872;
	// bl 0x88096cb8
	ctx.lr = 0x882485F4;
	sub_88096CB8(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
loc_882485F8:
	// lwz r11,13492(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 13492);
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x8824861c
	if (ctx.cr6.eq) goto loc_8824861C;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,14760
	ctx.r4.s64 = ctx.r11.s64 + 14760;
	// bl 0x88096cb8
	ctx.lr = 0x88248618;
	sub_88096CB8(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
loc_8824861C:
	// li r11,32
	ctx.r11.s64 = 32;
	// stw r28,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_88248634:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096e28
	ctx.lr = 0x88248640;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88248734
	if (!ctx.cr6.eq) goto loc_88248734;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x88096e28
	ctx.lr = 0x88248654;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88248734
	if (!ctx.cr6.eq) goto loc_88248734;
	// lwz r11,13404(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 13404);
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x88248680
	if (ctx.cr6.eq) goto loc_88248680;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,14648
	ctx.r4.s64 = ctx.r11.s64 + 14648;
	// bl 0x88096cb8
	ctx.lr = 0x8824867C;
	sub_88096CB8(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
loc_88248680:
	// lwz r11,13492(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 13492);
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x882486a4
	if (ctx.cr6.eq) goto loc_882486A4;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,14536
	ctx.r4.s64 = ctx.r11.s64 + 14536;
	// bl 0x88096cb8
	ctx.lr = 0x882486A0;
	sub_88096CB8(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
loc_882486A4:
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,90
	ctx.r10.s64 = 90;
	// li r9,64
	ctx.r9.s64 = 64;
	// stw r11,13396(r29)
	PPC_STORE_U32(ctx.r29.u32 + 13396, ctx.r11.u32);
	// stw r11,13484(r29)
	PPC_STORE_U32(ctx.r29.u32 + 13484, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_882486CC:
	// cmpwi cr6,r11,90
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 90, ctx.xer);
	// bne cr6,0x88248734
	if (!ctx.cr6.eq) goto loc_88248734;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096a68
	ctx.lr = 0x882486E0;
	sub_88096A68(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88248734
	if (!ctx.cr6.eq) goto loc_88248734;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x88096a68
	ctx.lr = 0x882486F4;
	sub_88096A68(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88248734
	if (!ctx.cr6.eq) goto loc_88248734;
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x88248734
	if (!ctx.cr6.eq) goto loc_88248734;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88248734
	if (ctx.cr0.gt) goto loc_88248734;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// stw r11,15780(r29)
	PPC_STORE_U32(ctx.r29.u32 + 15780, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096830
	ctx.lr = 0x88248734;
	sub_88096830(ctx, base);
loc_88248734:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88248740"))) PPC_WEAK_FUNC(sub_88248740);
PPC_FUNC_IMPL(__imp__sub_88248740) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88248748;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,68
	ctx.r5.s64 = 68;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x880968b8
	ctx.lr = 0x88248768;
	sub_880968B8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,3
	ctx.r10.s64 = 3;
	// li r8,32
	ctx.r8.s64 = 32;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r7,2
	ctx.r7.s64 = 2;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r30,0(r29)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r11.u32);
	// lis r6,-30684
	ctx.r6.s64 = -2010906624;
	// stw r8,56(r9)
	PPC_STORE_U32(ctx.r9.u32 + 56, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,60(r9)
	PPC_STORE_U32(ctx.r9.u32 + 60, ctx.r10.u32);
	// addi r5,r6,32008
	ctx.r5.s64 = ctx.r6.s64 + 32008;
	// stw r10,64(r9)
	PPC_STORE_U32(ctx.r9.u32 + 64, ctx.r10.u32);
	// stw r30,40(r9)
	PPC_STORE_U32(ctx.r9.u32 + 40, ctx.r30.u32);
	// stw r30,44(r9)
	PPC_STORE_U32(ctx.r9.u32 + 44, ctx.r30.u32);
	// stw r7,48(r9)
	PPC_STORE_U32(ctx.r9.u32 + 48, ctx.r7.u32);
	// bl 0x88096950
	ctx.lr = 0x882487B8;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_882487C4"))) PPC_WEAK_FUNC(sub_882487C4);
PPC_FUNC_IMPL(__imp__sub_882487C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_882487C8"))) PPC_WEAK_FUNC(sub_882487C8);
PPC_FUNC_IMPL(__imp__sub_882487C8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x882487D0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,76
	ctx.r5.s64 = 76;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x880968b8
	ctx.lr = 0x882487F0;
	sub_880968B8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,3
	ctx.r11.s64 = 3;
	// li r8,32
	ctx.r8.s64 = 32;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// li r7,8
	ctx.r7.s64 = 8;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// li r6,2
	ctx.r6.s64 = 2;
	// lwz r29,0(r29)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// stw r10,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r10.u32);
	// lis r5,-30683
	ctx.r5.s64 = -2010841088;
	// stw r8,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r8.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r11,60(r9)
	PPC_STORE_U32(ctx.r9.u32 + 60, ctx.r11.u32);
	// addi r5,r5,-32464
	ctx.r5.s64 = ctx.r5.s64 + -32464;
	// stw r11,72(r9)
	PPC_STORE_U32(ctx.r9.u32 + 72, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r29,40(r9)
	PPC_STORE_U32(ctx.r9.u32 + 40, ctx.r29.u32);
	// stw r29,44(r9)
	PPC_STORE_U32(ctx.r9.u32 + 44, ctx.r29.u32);
	// stw r11,48(r9)
	PPC_STORE_U32(ctx.r9.u32 + 48, ctx.r11.u32);
	// stw r7,68(r9)
	PPC_STORE_U32(ctx.r9.u32 + 68, ctx.r7.u32);
	// stw r6,64(r9)
	PPC_STORE_U32(ctx.r9.u32 + 64, ctx.r6.u32);
	// bl 0x88096950
	ctx.lr = 0x8824884C;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88248858"))) PPC_WEAK_FUNC(sub_88248858);
PPC_FUNC_IMPL(__imp__sub_88248858) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88248860;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,72
	ctx.r5.s64 = 72;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x880968b8
	ctx.lr = 0x88248880;
	sub_880968B8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r8,6
	ctx.r8.s64 = 6;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// li r6,40
	ctx.r6.s64 = 40;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// stw r3,40(r10)
	PPC_STORE_U32(ctx.r10.u32 + 40, ctx.r3.u32);
	// lis r5,-30683
	ctx.r5.s64 = -2010841088;
	// stw r9,44(r10)
	PPC_STORE_U32(ctx.r10.u32 + 44, ctx.r9.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r11,48(r10)
	PPC_STORE_U32(ctx.r10.u32 + 48, ctx.r11.u32);
	// addi r5,r5,-31608
	ctx.r5.s64 = ctx.r5.s64 + -31608;
	// stw r8,52(r10)
	PPC_STORE_U32(ctx.r10.u32 + 52, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r7,56(r10)
	PPC_STORE_U32(ctx.r10.u32 + 56, ctx.r7.u32);
	// stw r6,60(r10)
	PPC_STORE_U32(ctx.r10.u32 + 60, ctx.r6.u32);
	// stw r11,64(r10)
	PPC_STORE_U32(ctx.r10.u32 + 64, ctx.r11.u32);
	// bl 0x88096950
	ctx.lr = 0x882488D4;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_882488E0"))) PPC_WEAK_FUNC(sub_882488E0);
PPC_FUNC_IMPL(__imp__sub_882488E0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x882488E8;
	__savegprlr_29(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x88248904;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bgt cr6,0x88248a0c
	if (ctx.cr6.gt) goto loc_88248A0C;
	// beq cr6,0x882489b0
	if (ctx.cr6.eq) goto loc_882489B0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88248984
	if (ctx.cr6.eq) goto loc_88248984;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// bne cr6,0x88248acc
	if (!ctx.cr6.eq) goto loc_88248ACC;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096710
	ctx.lr = 0x88248934;
	sub_88096710(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x88248acc
	if (!ctx.cr6.eq) goto loc_88248ACC;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88248acc
	if (ctx.cr0.gt) goto loc_88248ACC;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r10,-30683
	ctx.r10.s64 = -2010841088;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-30776
	ctx.r4.s64 = ctx.r10.s64 + -30776;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x880969a8
	ctx.lr = 0x88248968;
	sub_880969A8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// bl 0x88096760
	ctx.lr = 0x8824897C;
	sub_88096760(ctx, base);
	// li r8,20
	ctx.r8.s64 = 20;
	// b 0x88248ac0
	goto loc_88248AC0;
loc_88248984:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88248acc
	if (ctx.cr0.gt) goto loc_88248ACC;
	// li r11,10
	ctx.r11.s64 = 10;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_882489B0:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096710
	ctx.lr = 0x882489BC;
	sub_88096710(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x88248acc
	if (!ctx.cr6.eq) goto loc_88248ACC;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88248acc
	if (ctx.cr0.gt) goto loc_88248ACC;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r10,-30683
	ctx.r10.s64 = -2010841088;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-30632
	ctx.r4.s64 = ctx.r10.s64 + -30632;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x880969a8
	ctx.lr = 0x882489F0;
	sub_880969A8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// bl 0x88096760
	ctx.lr = 0x88248A04;
	sub_88096760(ctx, base);
	// li r8,40
	ctx.r8.s64 = 40;
	// b 0x88248ac0
	goto loc_88248AC0;
loc_88248A0C:
	// cmpwi cr6,r11,40
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 40, ctx.xer);
	// beq cr6,0x88248a68
	if (ctx.cr6.eq) goto loc_88248A68;
	// cmpwi cr6,r11,90
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 90, ctx.xer);
	// bne cr6,0x88248acc
	if (!ctx.cr6.eq) goto loc_88248ACC;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096710
	ctx.lr = 0x88248A28;
	sub_88096710(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x88248acc
	if (!ctx.cr6.eq) goto loc_88248ACC;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88248acc
	if (ctx.cr0.gt) goto loc_88248ACC;
	// lwz r11,15772(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 15772);
	// li r10,10
	ctx.r10.s64 = 10;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r8,15772(r29)
	PPC_STORE_U32(ctx.r29.u32 + 15772, ctx.r8.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_88248A68:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096710
	ctx.lr = 0x88248A74;
	sub_88096710(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x88248acc
	if (!ctx.cr6.eq) goto loc_88248ACC;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88248acc
	if (ctx.cr0.gt) goto loc_88248ACC;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r10,-30683
	ctx.r10.s64 = -2010841088;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-30912
	ctx.r4.s64 = ctx.r10.s64 + -30912;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x880969a8
	ctx.lr = 0x88248AA8;
	sub_880969A8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// bl 0x88096760
	ctx.lr = 0x88248ABC;
	sub_88096760(ctx, base);
	// li r8,90
	ctx.r8.s64 = 90;
loc_88248AC0:
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r8,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// stw r7,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r7.u32);
loc_88248ACC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88248AD8"))) PPC_WEAK_FUNC(sub_88248AD8);
PPC_FUNC_IMPL(__imp__sub_88248AD8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88248AE0;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x88248B00;
	sub_880968B8(ctx, base);
	// li r28,0
	ctx.r28.s64 = 0;
	// li r11,-1
	ctx.r11.s64 = -1;
	// lis r10,120
	ctx.r10.s64 = 7864320;
	// stw r28,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r28.u32);
	// stw r28,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r28.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x88248b2c
	if (!ctx.cr6.lt) goto loc_88248B2C;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
loc_88248B2C:
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// li r11,4
	ctx.r11.s64 = 4;
	// li r10,256
	ctx.r10.s64 = 256;
	// lis r9,320
	ctx.r9.s64 = 20971520;
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// stw r10,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// lis r8,-30685
	ctx.r8.s64 = -2010972160;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// addi r4,r8,-19528
	ctx.r4.s64 = ctx.r8.s64 + -19528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x88248B60;
	sub_880966A8(ctx, base);
	// stw r28,15772(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15772, ctx.r28.u32);
	// lis r7,-30683
	ctx.r7.s64 = -2010841088;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r5,r7,-30496
	ctx.r5.s64 = ctx.r7.s64 + -30496;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096950
	ctx.lr = 0x88248B78;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88248B84"))) PPC_WEAK_FUNC(sub_88248B84);
PPC_FUNC_IMPL(__imp__sub_88248B84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88248B88"))) PPC_WEAK_FUNC(sub_88248B88);
PPC_FUNC_IMPL(__imp__sub_88248B88) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x88248B90;
	__savegprlr_25(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x88248BB0;
	sub_880968B8(ctx, base);
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r27,3
	ctx.r27.s64 = 3;
	// li r25,0
	ctx.r25.s64 = 0;
	// li r26,1
	ctx.r26.s64 = 1;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x88248c50
	if (ctx.cr6.lt) goto loc_88248C50;
	// bne cr6,0x88248c7c
	if (!ctx.cr6.eq) goto loc_88248C7C;
	// lwz r11,36(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r11.u32);
	// bgt 0x88248c7c
	if (ctx.cr0.gt) goto loc_88248C7C;
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r27.u32);
	// li r3,24
	ctx.r3.s64 = 24;
	// stw r11,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r11.u32);
	// bl 0x881534c8
	ctx.lr = 0x88248BF4;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// li r3,32
	ctx.r3.s64 = 32;
	// addi r9,r11,8
	ctx.r9.s64 = ctx.r11.s64 + 8;
	// mullw r8,r9,r10
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// subfic r7,r8,60
	ctx.xer.ca = ctx.r8.u32 <= 60;
	ctx.r7.s64 = 60 - ctx.r8.s64;
	// rlwinm r6,r7,17,0,14
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 17) & 0xFFFE0000;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// bl 0x881534c8
	ctx.lr = 0x88248C18;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lis r4,-30685
	ctx.r4.s64 = -2010972160;
	// addi r3,r11,254
	ctx.r3.s64 = ctx.r11.s64 + 254;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// rlwinm r11,r3,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 16) & 0xFFFF0000;
	// addi r4,r4,-19528
	ctx.r4.s64 = ctx.r4.s64 + -19528;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x88248C3C;
	sub_880966A8(ctx, base);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// stw r25,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r25.u32);
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// stw r9,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r9.u32);
	// b 0x88248c7c
	goto loc_88248C7C;
loc_88248C50:
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x88248c7c
	if (!ctx.cr6.eq) goto loc_88248C7C;
	// stw r26,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r26.u32);
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x881534c8
	ctx.lr = 0x88248C70;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
loc_88248C7C:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 11, ctx.xer);
	// bgt cr6,0x88248e1c
	if (ctx.cr6.gt) goto loc_88248E1C;
	// lis r12,-30683
	ctx.r12.s64 = -2010841088;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,-29536
	ctx.r12.s64 = ctx.r12.s64 + -29536;
	// lwzx r0,r12,r0
	ctx.r0.u64 = PPC_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u64) {
	case 0:
		goto loc_88248CD0;
	case 1:
		goto loc_88248D24;
	case 2:
		goto loc_88248E1C;
	case 3:
		goto loc_88248E1C;
	case 4:
		goto loc_88248E1C;
	case 5:
		goto loc_88248E1C;
	case 6:
		goto loc_88248E1C;
	case 7:
		goto loc_88248E1C;
	case 8:
		goto loc_88248E1C;
	case 9:
		goto loc_88248E1C;
	case 10:
		goto loc_88248DA4;
	case 11:
		goto loc_88248DD8;
	default:
		__builtin_unreachable();
	}
	// lbz r1,-29488(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -29488);
	// lbz r1,-29404(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -29404);
	// lbz r1,-29156(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -29156);
	// lbz r1,-29156(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -29156);
	// lbz r1,-29156(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -29156);
	// lbz r1,-29156(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -29156);
	// lbz r1,-29156(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -29156);
	// lbz r1,-29156(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -29156);
	// lbz r1,-29156(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -29156);
	// lbz r1,-29156(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -29156);
	// lbz r1,-29276(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -29276);
	// lbz r1,-29224(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -29224);
loc_88248CD0:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// bl 0x88096e28
	ctx.lr = 0x88248CDC;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88248e1c
	if (!ctx.cr6.eq) goto loc_88248E1C;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88248d54
	if (!ctx.cr6.eq) goto loc_88248D54;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r27.u32);
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,5552
	ctx.r4.s64 = ctx.r11.s64 + 5552;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x88248D08;
	sub_88097078(ctx, base);
	// li r10,128
	ctx.r10.s64 = 128;
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// stw r26,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r26.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_88248D24:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88248d70
	if (ctx.cr6.eq) goto loc_88248D70;
	// cmpwi cr6,r11,64
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 64, ctx.xer);
	// bne cr6,0x88248d50
	if (!ctx.cr6.eq) goto loc_88248D50;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,14416
	ctx.r4.s64 = ctx.r11.s64 + 14416;
	// bl 0x88096cb8
	ctx.lr = 0x88248D4C;
	sub_88096CB8(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
loc_88248D50:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
loc_88248D54:
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88248e1c
	if (ctx.cr0.gt) goto loc_88248E1C;
	// stw r25,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r25.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_88248D70:
	// li r11,2
	ctx.r11.s64 = 2;
	// lis r10,-30696
	ctx.r10.s64 = -2011693056;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,9840
	ctx.r4.s64 = ctx.r10.s64 + 9840;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x88248D8C;
	sub_88097078(ctx, base);
	// li r9,10
	ctx.r9.s64 = 10;
	// stw r3,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_88248DA4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// bl 0x88096e28
	ctx.lr = 0x88248DB0;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88248e1c
	if (!ctx.cr6.eq) goto loc_88248E1C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x88096dd0
	ctx.lr = 0x88248DC4;
	sub_88096DD0(ctx, base);
	// li r11,11
	ctx.r11.s64 = 11;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_88248DD8:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x88096e28
	ctx.lr = 0x88248DE4;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88248e1c
	if (!ctx.cr6.eq) goto loc_88248E1C;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88248d54
	if (!ctx.cr6.eq) goto loc_88248D54;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,14304
	ctx.r4.s64 = ctx.r11.s64 + 14304;
	// bl 0x88096cb8
	ctx.lr = 0x88248E0C;
	sub_88096CB8(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096830
	ctx.lr = 0x88248E1C;
	sub_88096830(ctx, base);
loc_88248E1C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88248E28"))) PPC_WEAK_FUNC(sub_88248E28);
PPC_FUNC_IMPL(__imp__sub_88248E28) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x88248E30;
	__savegprlr_27(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lwz r27,2304(r3)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x880968b8
	ctx.lr = 0x88248E54;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bgt cr6,0x88249000
	if (ctx.cr6.gt) goto loc_88249000;
	// beq cr6,0x88248f94
	if (ctx.cr6.eq) goto loc_88248F94;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88248f40
	if (ctx.cr6.eq) goto loc_88248F40;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x88248f08
	if (ctx.cr6.eq) goto loc_88248F08;
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// bne cr6,0x88249134
	if (!ctx.cr6.eq) goto loc_88249134;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88248fc4
	if (!ctx.cr6.eq) goto loc_88248FC4;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880954e0
	ctx.lr = 0x88248E9C;
	sub_880954E0(ctx, base);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r11,-30682
	ctx.r11.s64 = -2010775552;
	// lis r10,120
	ctx.r10.s64 = 7864320;
	// addi r11,r11,29544
	ctx.r11.s64 = ctx.r11.s64 + 29544;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// bgt cr6,0x88248eb8
	if (ctx.cr6.gt) goto loc_88248EB8;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
loc_88248EB8:
	// li r10,4
	ctx.r10.s64 = 4;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r10,16(r27)
	PPC_STORE_U32(ctx.r27.u32 + 16, ctx.r10.u32);
	// lis r8,-30685
	ctx.r8.s64 = -2010972160;
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r4,r8,-19528
	ctx.r4.s64 = ctx.r8.s64 + -19528;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r7,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r7.u32);
	// stw r6,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r6.u32);
	// bl 0x880966a8
	ctx.lr = 0x88248EEC;
	sub_880966A8(ctx, base);
	// li r5,96
	ctx.r5.s64 = 96;
	// li r4,7
	ctx.r4.s64 = 7;
	// stw r5,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r5.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r4,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r4.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_88248F08:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88248fc4
	if (!ctx.cr6.eq) goto loc_88248FC4;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,8008
	ctx.r4.s64 = ctx.r11.s64 + 8008;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88097078
	ctx.lr = 0x88248F28;
	sub_88097078(ctx, base);
	// li r10,6
	ctx.r10.s64 = 6;
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_88248F40:
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 5724);
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x88249134
	if (!ctx.cr6.eq) goto loc_88249134;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88248fc4
	if (!ctx.cr6.eq) goto loc_88248FC4;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,7808
	ctx.r4.s64 = ctx.r11.s64 + 7808;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88097078
	ctx.lr = 0x88248F74;
	sub_88097078(ctx, base);
	// li r10,5
	ctx.r10.s64 = 5;
	// li r9,64
	ctx.r9.s64 = 64;
	// stw r3,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r3.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_88248F94:
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 5724);
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x88249134
	if (!ctx.cr6.eq) goto loc_88249134;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88248fe4
	if (ctx.cr6.eq) goto loc_88248FE4;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096dd0
	ctx.lr = 0x88248FC0;
	sub_88096DD0(ctx, base);
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
loc_88248FC4:
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88249134
	if (ctx.cr0.gt) goto loc_88249134;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_88248FE4:
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,8
	ctx.r10.s64 = 8;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_88249000:
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// beq cr6,0x882490d8
	if (ctx.cr6.eq) goto loc_882490D8;
	// cmpwi cr6,r11,9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 9, ctx.xer);
	// beq cr6,0x88249054
	if (ctx.cr6.eq) goto loc_88249054;
	// cmpwi cr6,r11,40
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 40, ctx.xer);
	// bne cr6,0x88249134
	if (!ctx.cr6.eq) goto loc_88249134;
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 5724);
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x88249134
	if (!ctx.cr6.eq) goto loc_88249134;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88249134
	if (ctx.cr0.gt) goto loc_88249134;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88096830
	ctx.lr = 0x88249048;
	sub_88096830(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_88249054:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096e28
	ctx.lr = 0x88249060;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88249134
	if (!ctx.cr6.eq) goto loc_88249134;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88248fc4
	if (!ctx.cr6.eq) goto loc_88248FC4;
	// li r11,4
	ctx.r11.s64 = 4;
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,120
	ctx.r9.s64 = 7864320;
	// stw r11,16(r27)
	PPC_STORE_U32(ctx.r27.u32 + 16, ctx.r11.u32);
	// lis r8,290
	ctx.r8.s64 = 19005440;
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// stw r9,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// lis r7,-30685
	ctx.r7.s64 = -2010972160;
	// stw r8,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r8.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r7,-19528
	ctx.r4.s64 = ctx.r7.s64 + -19528;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x880966a8
	ctx.lr = 0x882490A8;
	sub_880966A8(ctx, base);
	// lis r6,-30696
	ctx.r6.s64 = -2011693056;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,24(r27)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r27.u32 + 24);
	// addi r4,r6,14304
	ctx.r4.s64 = ctx.r6.s64 + 14304;
	// bl 0x88096cb8
	ctx.lr = 0x882490BC;
	sub_88096CB8(ctx, base);
	// li r5,40
	ctx.r5.s64 = 40;
	// li r4,192
	ctx.r4.s64 = 192;
	// stw r5,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r5.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r4,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r4.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_882490D8:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88248fc4
	if (!ctx.cr6.eq) goto loc_88248FC4;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,9512
	ctx.r4.s64 = ctx.r11.s64 + 9512;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88097078
	ctx.lr = 0x882490F8;
	sub_88097078(ctx, base);
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// li r30,0
	ctx.r30.s64 = 0;
loc_88249100:
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r30.u32);
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,7352
	ctx.r4.s64 = ctx.r11.s64 + 7352;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88097078
	ctx.lr = 0x88249118;
	sub_88097078(ctx, base);
	// addi r30,r30,48
	ctx.r30.s64 = ctx.r30.s64 + 48;
	// cmpwi cr6,r30,384
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 384, ctx.xer);
	// blt cr6,0x88249100
	if (ctx.cr6.lt) goto loc_88249100;
	// li r11,128
	ctx.r11.s64 = 128;
	// li r10,9
	ctx.r10.s64 = 9;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
loc_88249134:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88249140"))) PPC_WEAK_FUNC(sub_88249140);
PPC_FUNC_IMPL(__imp__sub_88249140) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88249148;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x88249168;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// bgt cr6,0x8824928c
	if (ctx.cr6.gt) goto loc_8824928C;
	// beq cr6,0x88249220
	if (ctx.cr6.eq) goto loc_88249220;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x882491b4
	if (ctx.cr6.eq) goto loc_882491B4;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x8824931c
	if (!ctx.cr6.eq) goto loc_8824931C;
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x8824931c
	if (!ctx.cr6.eq) goto loc_8824931C;
	// li r11,5
	ctx.r11.s64 = 5;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_882491B4:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824931c
	if (ctx.cr0.gt) goto loc_8824931C;
	// li r11,10
	ctx.r11.s64 = 10;
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,120
	ctx.r9.s64 = 7864320;
	// stw r11,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r11.u32);
	// lis r8,230
	ctx.r8.s64 = 15073280;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// lis r7,-30685
	ctx.r7.s64 = -2010972160;
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r7,-19528
	ctx.r4.s64 = ctx.r7.s64 + -19528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x882491F8;
	sub_880966A8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r6,3
	ctx.r6.s64 = 3;
	// li r5,32
	ctx.r5.s64 = 32;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r6,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r6.u32);
	// stw r5,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r5.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_88249220:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824931c
	if (ctx.cr0.gt) goto loc_8824931C;
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r9,10
	ctx.r9.s64 = 10;
	// mulli r8,r10,-60
	ctx.r8.s64 = ctx.r10.s64 * -60;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// rlwinm r7,r8,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0x1;
	// lis r6,-30696
	ctx.r6.s64 = -2011693056;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r6,9648
	ctx.r4.s64 = ctx.r6.s64 + 9648;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x8824926C;
	sub_88097078(ctx, base);
	// li r5,100
	ctx.r5.s64 = 100;
	// li r4,352
	ctx.r4.s64 = 352;
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// stw r5,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r5.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r4,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r4.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824928C:
	// cmpwi cr6,r11,100
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 100, ctx.xer);
	// bne cr6,0x8824931c
	if (!ctx.cr6.eq) goto loc_8824931C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096e28
	ctx.lr = 0x882492A0;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8824931c
	if (!ctx.cr6.eq) goto loc_8824931C;
	// lwz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88249300
	if (!ctx.cr6.eq) goto loc_88249300;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// li r9,3
	ctx.r9.s64 = 3;
	// stw r10,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r10.u32);
	// lis r8,120
	ctx.r8.s64 = 7864320;
	// li r3,32
	ctx.r3.s64 = 32;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// bl 0x881534c8
	ctx.lr = 0x882492DC;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lis r7,-30685
	ctx.r7.s64 = -2010972160;
	// addi r6,r11,274
	ctx.r6.s64 = ctx.r11.s64 + 274;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// rlwinm r3,r6,16,0,15
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// addi r4,r7,-19528
	ctx.r4.s64 = ctx.r7.s64 + -19528;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x88249300;
	sub_880966A8(ctx, base);
loc_88249300:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824931c
	if (ctx.cr0.gt) goto loc_8824931C;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096830
	ctx.lr = 0x8824931C;
	sub_88096830(ctx, base);
loc_8824931C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88249328"))) PPC_WEAK_FUNC(sub_88249328);
PPC_FUNC_IMPL(__imp__sub_88249328) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x88249330;
	__savegprlr_26(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r27,2304(r3)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x88249350;
	sub_880968B8(ctx, base);
	// lwz r11,92(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r26,1
	ctx.r26.s64 = 1;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x882493f0
	if (ctx.cr6.lt) goto loc_882493F0;
	// bne cr6,0x8824941c
	if (!ctx.cr6.eq) goto loc_8824941C;
	// lwz r11,96(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,96(r3)
	PPC_STORE_U32(ctx.r3.u32 + 96, ctx.r11.u32);
	// bgt 0x8824941c
	if (ctx.cr0.gt) goto loc_8824941C;
	// li r11,4
	ctx.r11.s64 = 4;
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r11,16(r27)
	PPC_STORE_U32(ctx.r27.u32 + 16, ctx.r11.u32);
	// li r3,24
	ctx.r3.s64 = 24;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x881534c8
	ctx.lr = 0x88249394;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lwz r9,84(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// li r3,32
	ctx.r3.s64 = 32;
	// addi r8,r11,8
	ctx.r8.s64 = ctx.r11.s64 + 8;
	// mullw r7,r8,r9
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// subfic r6,r7,60
	ctx.xer.ca = ctx.r7.u32 <= 60;
	ctx.r6.s64 = 60 - ctx.r7.s64;
	// rlwinm r5,r6,17,0,14
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 17) & 0xFFFE0000;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// bl 0x881534c8
	ctx.lr = 0x882493B8;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lis r4,-30685
	ctx.r4.s64 = -2010972160;
	// addi r3,r11,274
	ctx.r3.s64 = ctx.r11.s64 + 274;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// rlwinm r11,r3,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 16) & 0xFFFF0000;
	// addi r4,r4,-19528
	ctx.r4.s64 = ctx.r4.s64 + -19528;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x882493DC;
	sub_880966A8(ctx, base);
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// stw r29,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r29.u32);
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// stw r9,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r9.u32);
	// b 0x8824941c
	goto loc_8824941C;
loc_882493F0:
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x8824941c
	if (!ctx.cr6.eq) goto loc_8824941C;
	// stw r26,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r26.u32);
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x881534c8
	ctx.lr = 0x88249410;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// stw r11,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
loc_8824941C:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 11, ctx.xer);
	// bgt cr6,0x882496f4
	if (ctx.cr6.gt) goto loc_882496F4;
	// lis r12,-30683
	ctx.r12.s64 = -2010841088;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,-27584
	ctx.r12.s64 = ctx.r12.s64 + -27584;
	// lwzx r0,r12,r0
	ctx.r0.u64 = PPC_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u64) {
	case 0:
		goto loc_88249470;
	case 1:
		goto loc_882494CC;
	case 2:
		goto loc_882496F4;
	case 3:
		goto loc_882496F4;
	case 4:
		goto loc_882496F4;
	case 5:
		goto loc_882495C8;
	case 6:
		goto loc_882496F4;
	case 7:
		goto loc_882496F4;
	case 8:
		goto loc_882496F4;
	case 9:
		goto loc_882496F4;
	case 10:
		goto loc_882496F4;
	case 11:
		goto loc_882496C8;
	default:
		__builtin_unreachable();
	}
	// lbz r1,-27536(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -27536);
	// lbz r1,-27444(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -27444);
	// lbz r1,-26892(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -26892);
	// lbz r1,-26892(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -26892);
	// lbz r1,-26892(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -26892);
	// lbz r1,-27192(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -27192);
	// lbz r1,-26892(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -26892);
	// lbz r1,-26892(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -26892);
	// lbz r1,-26892(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -26892);
	// lbz r1,-26892(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -26892);
	// lbz r1,-26892(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -26892);
	// lbz r1,-26936(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -26936);
loc_88249470:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x882496f4
	if (ctx.cr0.gt) goto loc_882496F4;
	// stw r29,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r29.u32);
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r29,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r29.u32);
	// addi r4,r11,14416
	ctx.r4.s64 = ctx.r11.s64 + 14416;
	// lwz r3,24(r27)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r27.u32 + 24);
	// bl 0x88096cb8
	ctx.lr = 0x882494A0;
	sub_88096CB8(ctx, base);
	// li r10,64
	ctx.r10.s64 = 64;
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r29,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r29.u32);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// stw r29,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r29.u32);
	// stw r26,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r26.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// stw r29,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r29.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_882494CC:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096a68
	ctx.lr = 0x882494D8;
	sub_88096A68(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x882496f4
	if (!ctx.cr6.eq) goto loc_882496F4;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// bl 0x88096e28
	ctx.lr = 0x882494EC;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x882496f4
	if (!ctx.cr6.eq) goto loc_882496F4;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824951c
	if (ctx.cr6.eq) goto loc_8824951C;
loc_88249500:
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x882496f4
	if (ctx.cr0.gt) goto loc_882496F4;
	// stw r29,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_8824951C:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// bge 0x882496f4
	if (!ctx.cr0.lt) goto loc_882496F4;
	// lis r10,-30696
	ctx.r10.s64 = -2011693056;
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r8,32(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r4,r10,9312
	ctx.r4.s64 = ctx.r10.s64 + 9312;
	// lwz r7,48(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// clrlwi r6,r9,31
	ctx.r6.u64 = ctx.r9.u32 & 0x1;
	// clrlwi r10,r8,31
	ctx.r10.u64 = ctx.r8.u32 & 0x1;
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// bl 0x88097078
	ctx.lr = 0x88249568;
	sub_88097078(ctx, base);
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// lwz r7,40(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// addic. r11,r7,-1
	ctx.xer.ca = ctx.r7.u32 > 0;
	ctx.r11.s64 = ctx.r7.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// stw r6,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r6.u32);
	// stw r8,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r8.u32);
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// bgt 0x882496f4
	if (ctx.cr0.gt) goto loc_882496F4;
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// li r9,5
	ctx.r9.s64 = 5;
	// stw r29,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_882495C8:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x88096e28
	ctx.lr = 0x882495D4;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x882496f4
	if (!ctx.cr6.eq) goto loc_882496F4;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88249500
	if (!ctx.cr6.eq) goto loc_88249500;
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// bge 0x882496f4
	if (!ctx.cr0.lt) goto loc_882496F4;
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// lis r10,-30696
	ctx.r10.s64 = -2011693056;
	// lwz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r8,80(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// addi r4,r10,9048
	ctx.r4.s64 = ctx.r10.s64 + 9048;
	// lwz r7,68(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// bl 0x88097078
	ctx.lr = 0x8824962C;
	sub_88097078(ctx, base);
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// lwz r6,60(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// stw r3,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r3.u32);
	// addic. r11,r6,-1
	ctx.xer.ca = ctx.r6.u32 > 0;
	ctx.r11.s64 = ctx.r6.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r5,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r5.u32);
	// stw r11,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// bgt 0x882496f4
	if (ctx.cr0.gt) goto loc_882496F4;
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// lwz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r29,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r29.u32);
	// stw r11,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// stw r10,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r10.u32);
	// blt cr6,0x88249674
	if (ctx.cr6.lt) goto loc_88249674;
	// li r11,5
	ctx.r11.s64 = 5;
	// stw r11,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
loc_88249674:
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// li r10,32
	ctx.r10.s64 = 32;
	// stw r26,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r26.u32);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r26,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r26.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// stw r11,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// bgt 0x882496f4
	if (ctx.cr0.gt) goto loc_882496F4;
	// li r10,64
	ctx.r10.s64 = 64;
	// li r11,11
	ctx.r11.s64 = 11;
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// lis r9,-30696
	ctx.r9.s64 = -2011693056;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,14304
	ctx.r4.s64 = ctx.r9.s64 + 14304;
	// lwz r3,24(r27)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r27.u32 + 24);
	// bl 0x88096cb8
	ctx.lr = 0x882496B8;
	sub_88096CB8(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_882496C8:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096a68
	ctx.lr = 0x882496D4;
	sub_88096A68(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x882496f4
	if (!ctx.cr6.eq) goto loc_882496F4;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88249500
	if (!ctx.cr6.eq) goto loc_88249500;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096830
	ctx.lr = 0x882496F4;
	sub_88096830(ctx, base);
loc_882496F4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88249700"))) PPC_WEAK_FUNC(sub_88249700);
PPC_FUNC_IMPL(__imp__sub_88249700) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88249708;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,40
	ctx.r5.s64 = 40;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x880968b8
	ctx.lr = 0x88249728;
	sub_880968B8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r9,-30683
	ctx.r9.s64 = -2010841088;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r9,-29816
	ctx.r5.s64 = ctx.r9.s64 + -29816;
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,32(r10)
	PPC_STORE_U32(ctx.r10.u32 + 32, ctx.r11.u32);
	// stw r11,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r11.u32);
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// stw r8,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r8.u32);
	// bl 0x88096950
	ctx.lr = 0x8824975C;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88249768"))) PPC_WEAK_FUNC(sub_88249768);
PPC_FUNC_IMPL(__imp__sub_88249768) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x88249770;
	__savegprlr_27(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,56
	ctx.r5.s64 = 56;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x880968b8
	ctx.lr = 0x88249794;
	sub_880968B8(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,30
	ctx.r10.s64 = 30;
	// li r9,8
	ctx.r9.s64 = 8;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lis r7,120
	ctx.r7.s64 = 7864320;
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r11.u32);
	// lis r6,290
	ctx.r6.s64 = 19005440;
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r11.u32);
	// stw r11,32(r27)
	PPC_STORE_U32(ctx.r27.u32 + 32, ctx.r11.u32);
	// lis r4,-30685
	ctx.r4.s64 = -2010972160;
	// stw r11,52(r27)
	PPC_STORE_U32(ctx.r27.u32 + 52, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// addi r4,r4,-19528
	ctx.r4.s64 = ctx.r4.s64 + -19528;
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// stw r9,16(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16, ctx.r9.u32);
	// bl 0x880966a8
	ctx.lr = 0x882497EC;
	sub_880966A8(ctx, base);
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lis r3,-30683
	ctx.r3.s64 = -2010841088;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r3,-29144
	ctx.r5.s64 = ctx.r3.s64 + -29144;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,36(r27)
	PPC_STORE_U32(ctx.r27.u32 + 36, ctx.r11.u32);
	// bl 0x88096950
	ctx.lr = 0x88249808;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88249814"))) PPC_WEAK_FUNC(sub_88249814);
PPC_FUNC_IMPL(__imp__sub_88249814) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88249818"))) PPC_WEAK_FUNC(sub_88249818);
PPC_FUNC_IMPL(__imp__sub_88249818) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88249820;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,44
	ctx.r5.s64 = 44;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x880968b8
	ctx.lr = 0x88249840;
	sub_880968B8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r9,-30683
	ctx.r9.s64 = -2010841088;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r9,-28352
	ctx.r5.s64 = ctx.r9.s64 + -28352;
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// stw r8,36(r10)
	PPC_STORE_U32(ctx.r10.u32 + 36, ctx.r8.u32);
	// stw r11,40(r10)
	PPC_STORE_U32(ctx.r10.u32 + 40, ctx.r11.u32);
	// bl 0x88096950
	ctx.lr = 0x88249870;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824987C"))) PPC_WEAK_FUNC(sub_8824987C);
PPC_FUNC_IMPL(__imp__sub_8824987C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88249880"))) PPC_WEAK_FUNC(sub_88249880);
PPC_FUNC_IMPL(__imp__sub_88249880) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88249888;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,100
	ctx.r5.s64 = 100;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x880968b8
	ctx.lr = 0x882498A8;
	sub_880968B8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// lis r6,-30671
	ctx.r6.s64 = -2010054656;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// lis r5,16838
	ctx.r5.s64 = 1103495168;
	// stw r11,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, ctx.r11.u32);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// ori r4,r5,20077
	ctx.r4.u64 = ctx.r5.u64 | 20077;
	// li r8,4
	ctx.r8.s64 = 4;
	// lwz r9,4200(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4200);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r8,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r8.u32);
	// li r5,8
	ctx.r5.s64 = 8;
	// mullw r9,r9,r4
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r4.s32);
	// stw r8,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r8.u32);
	// stw r11,36(r7)
	PPC_STORE_U32(ctx.r7.u32 + 36, ctx.r11.u32);
	// stw r11,48(r7)
	PPC_STORE_U32(ctx.r7.u32 + 48, ctx.r11.u32);
	// stw r11,68(r7)
	PPC_STORE_U32(ctx.r7.u32 + 68, ctx.r11.u32);
	// stw r11,80(r7)
	PPC_STORE_U32(ctx.r7.u32 + 80, ctx.r11.u32);
	// stw r5,56(r7)
	PPC_STORE_U32(ctx.r7.u32 + 56, ctx.r5.u32);
	// stw r10,64(r7)
	PPC_STORE_U32(ctx.r7.u32 + 64, ctx.r10.u32);
	// stw r10,60(r7)
	PPC_STORE_U32(ctx.r7.u32 + 60, ctx.r10.u32);
	// stw r10,76(r7)
	PPC_STORE_U32(ctx.r7.u32 + 76, ctx.r10.u32);
	// addi r9,r9,12345
	ctx.r9.s64 = ctx.r9.s64 + 12345;
	// li r3,20
	ctx.r3.s64 = 20;
	// stw r9,4200(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4200, ctx.r9.u32);
	// li r8,64
	ctx.r8.s64 = 64;
	// lhz r9,4200(r6)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r6.u32 + 4200);
	// li r4,3
	ctx.r4.s64 = 3;
	// clrlwi r11,r9,31
	ctx.r11.u64 = ctx.r9.u32 & 0x1;
	// stw r3,28(r7)
	PPC_STORE_U32(ctx.r7.u32 + 28, ctx.r3.u32);
	// stw r4,72(r7)
	PPC_STORE_U32(ctx.r7.u32 + 72, ctx.r4.u32);
	// lis r3,-30683
	ctx.r3.s64 = -2010841088;
	// stw r8,52(r7)
	PPC_STORE_U32(ctx.r7.u32 + 52, ctx.r8.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r11,32(r7)
	PPC_STORE_U32(ctx.r7.u32 + 32, ctx.r11.u32);
	// addi r5,r3,-27864
	ctx.r5.s64 = ctx.r3.s64 + -27864;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,84(r7)
	PPC_STORE_U32(ctx.r7.u32 + 84, ctx.r10.u32);
	// bl 0x88096950
	ctx.lr = 0x88249950;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824995C"))) PPC_WEAK_FUNC(sub_8824995C);
PPC_FUNC_IMPL(__imp__sub_8824995C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88249960"))) PPC_WEAK_FUNC(sub_88249960);
PPC_FUNC_IMPL(__imp__sub_88249960) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88249968;
	__savegprlr_29(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x88249984;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bgt cr6,0x88249ac4
	if (ctx.cr6.gt) goto loc_88249AC4;
	// beq cr6,0x88249a68
	if (ctx.cr6.eq) goto loc_88249A68;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88249a04
	if (ctx.cr6.eq) goto loc_88249A04;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// bne cr6,0x88249b80
	if (!ctx.cr6.eq) goto loc_88249B80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096710
	ctx.lr = 0x882499B4;
	sub_88096710(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x88249b80
	if (!ctx.cr6.eq) goto loc_88249B80;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88249b80
	if (ctx.cr0.gt) goto loc_88249B80;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r10,-30683
	ctx.r10.s64 = -2010841088;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-26600
	ctx.r4.s64 = ctx.r10.s64 + -26600;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x880969a8
	ctx.lr = 0x882499E8;
	sub_880969A8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// bl 0x88096760
	ctx.lr = 0x882499FC;
	sub_88096760(ctx, base);
	// li r8,30
	ctx.r8.s64 = 30;
	// b 0x88249b74
	goto loc_88249B74;
loc_88249A04:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88249b80
	if (ctx.cr0.gt) goto loc_88249B80;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r10,-30683
	ctx.r10.s64 = -2010841088;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// neg r9,r11
	ctx.r9.s64 = -ctx.r11.s64;
	// addi r4,r10,-26496
	ctx.r4.s64 = ctx.r10.s64 + -26496;
	// stw r9,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r9.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x880969a8
	ctx.lr = 0x88249A38;
	sub_880969A8(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r8,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r8.u32);
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// bl 0x88096760
	ctx.lr = 0x88249A4C;
	sub_88096760(ctx, base);
	// li r7,20
	ctx.r7.s64 = 20;
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r6,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r6.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_88249A68:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096710
	ctx.lr = 0x88249A74;
	sub_88096710(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x88249b80
	if (!ctx.cr6.eq) goto loc_88249B80;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88249b80
	if (ctx.cr0.gt) goto loc_88249B80;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r10,-30683
	ctx.r10.s64 = -2010841088;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-26776
	ctx.r4.s64 = ctx.r10.s64 + -26776;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x880969a8
	ctx.lr = 0x88249AA8;
	sub_880969A8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// bl 0x88096760
	ctx.lr = 0x88249ABC;
	sub_88096760(ctx, base);
	// li r8,25
	ctx.r8.s64 = 25;
	// b 0x88249b74
	goto loc_88249B74;
loc_88249AC4:
	// cmpwi cr6,r11,25
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 25, ctx.xer);
	// beq cr6,0x88249b1c
	if (ctx.cr6.eq) goto loc_88249B1C;
	// cmpwi cr6,r11,30
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 30, ctx.xer);
	// bne cr6,0x88249b80
	if (!ctx.cr6.eq) goto loc_88249B80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096710
	ctx.lr = 0x88249AE0;
	sub_88096710(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x88249b80
	if (!ctx.cr6.eq) goto loc_88249B80;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88249b80
	if (ctx.cr0.gt) goto loc_88249B80;
	// lwz r11,15768(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 15768);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,15768(r29)
	PPC_STORE_U32(ctx.r29.u32 + 15768, ctx.r11.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_88249B1C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096710
	ctx.lr = 0x88249B28;
	sub_88096710(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x88249b80
	if (!ctx.cr6.eq) goto loc_88249B80;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88249b80
	if (ctx.cr0.gt) goto loc_88249B80;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r10,-30683
	ctx.r10.s64 = -2010841088;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-26880
	ctx.r4.s64 = ctx.r10.s64 + -26880;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x880969a8
	ctx.lr = 0x88249B5C;
	sub_880969A8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// bl 0x88096760
	ctx.lr = 0x88249B70;
	sub_88096760(ctx, base);
	// li r8,10
	ctx.r8.s64 = 10;
loc_88249B74:
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r8,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// stw r7,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r7.u32);
loc_88249B80:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88249B8C"))) PPC_WEAK_FUNC(sub_88249B8C);
PPC_FUNC_IMPL(__imp__sub_88249B8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88249B90"))) PPC_WEAK_FUNC(sub_88249B90);
PPC_FUNC_IMPL(__imp__sub_88249B90) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88249B98;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880968b8
	ctx.lr = 0x88249BB8;
	sub_880968B8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// lis r9,120
	ctx.r9.s64 = 7864320;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// lwz r8,8(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x88249be4
	if (!ctx.cr6.lt) goto loc_88249BE4;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
loc_88249BE4:
	// stw r11,15768(r29)
	PPC_STORE_U32(ctx.r29.u32 + 15768, ctx.r11.u32);
	// lis r11,-30683
	ctx.r11.s64 = -2010841088;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r11,-26272
	ctx.r5.s64 = ctx.r11.s64 + -26272;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096950
	ctx.lr = 0x88249BFC;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88249C08"))) PPC_WEAK_FUNC(sub_88249C08);
PPC_FUNC_IMPL(__imp__sub_88249C08) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x88249C10;
	__savegprlr_25(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x88249C30;
	sub_880968B8(ctx, base);
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r27,3
	ctx.r27.s64 = 3;
	// li r25,0
	ctx.r25.s64 = 0;
	// li r26,1
	ctx.r26.s64 = 1;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x88249cd0
	if (ctx.cr6.lt) goto loc_88249CD0;
	// bne cr6,0x88249cfc
	if (!ctx.cr6.eq) goto loc_88249CFC;
	// lwz r11,36(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r11.u32);
	// bgt 0x88249cfc
	if (ctx.cr0.gt) goto loc_88249CFC;
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r27.u32);
	// li r3,24
	ctx.r3.s64 = 24;
	// stw r11,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r11.u32);
	// bl 0x881534c8
	ctx.lr = 0x88249C74;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// li r3,32
	ctx.r3.s64 = 32;
	// addi r9,r11,8
	ctx.r9.s64 = ctx.r11.s64 + 8;
	// mullw r8,r9,r10
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// subfic r7,r8,60
	ctx.xer.ca = ctx.r8.u32 <= 60;
	ctx.r7.s64 = 60 - ctx.r8.s64;
	// rlwinm r6,r7,17,0,14
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 17) & 0xFFFE0000;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// bl 0x881534c8
	ctx.lr = 0x88249C98;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lis r4,-30685
	ctx.r4.s64 = -2010972160;
	// addi r3,r11,254
	ctx.r3.s64 = ctx.r11.s64 + 254;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// rlwinm r11,r3,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 16) & 0xFFFF0000;
	// addi r4,r4,-19528
	ctx.r4.s64 = ctx.r4.s64 + -19528;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x88249CBC;
	sub_880966A8(ctx, base);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// stw r25,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r25.u32);
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// stw r9,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r9.u32);
	// b 0x88249cfc
	goto loc_88249CFC;
loc_88249CD0:
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x88249cfc
	if (!ctx.cr6.eq) goto loc_88249CFC;
	// stw r26,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r26.u32);
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x881534c8
	ctx.lr = 0x88249CF0;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
loc_88249CFC:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 11, ctx.xer);
	// bgt cr6,0x88249e9c
	if (ctx.cr6.gt) goto loc_88249E9C;
	// lis r12,-30683
	ctx.r12.s64 = -2010841088;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,-25312
	ctx.r12.s64 = ctx.r12.s64 + -25312;
	// lwzx r0,r12,r0
	ctx.r0.u64 = PPC_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u64) {
	case 0:
		goto loc_88249D50;
	case 1:
		goto loc_88249DA4;
	case 2:
		goto loc_88249E9C;
	case 3:
		goto loc_88249E9C;
	case 4:
		goto loc_88249E9C;
	case 5:
		goto loc_88249E9C;
	case 6:
		goto loc_88249E9C;
	case 7:
		goto loc_88249E9C;
	case 8:
		goto loc_88249E9C;
	case 9:
		goto loc_88249E9C;
	case 10:
		goto loc_88249E24;
	case 11:
		goto loc_88249E58;
	default:
		__builtin_unreachable();
	}
	// lbz r1,-25264(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -25264);
	// lbz r1,-25180(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -25180);
	// lbz r1,-24932(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -24932);
	// lbz r1,-24932(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -24932);
	// lbz r1,-24932(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -24932);
	// lbz r1,-24932(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -24932);
	// lbz r1,-24932(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -24932);
	// lbz r1,-24932(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -24932);
	// lbz r1,-24932(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -24932);
	// lbz r1,-24932(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -24932);
	// lbz r1,-25052(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -25052);
	// lbz r1,-25000(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -25000);
loc_88249D50:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// bl 0x88096e28
	ctx.lr = 0x88249D5C;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88249e9c
	if (!ctx.cr6.eq) goto loc_88249E9C;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88249dd4
	if (!ctx.cr6.eq) goto loc_88249DD4;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r27.u32);
	// lis r11,-30686
	ctx.r11.s64 = -2011037696;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-24176
	ctx.r4.s64 = ctx.r11.s64 + -24176;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x88249D88;
	sub_88097078(ctx, base);
	// li r10,128
	ctx.r10.s64 = 128;
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// stw r26,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r26.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_88249DA4:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88249df0
	if (ctx.cr6.eq) goto loc_88249DF0;
	// cmpwi cr6,r11,64
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 64, ctx.xer);
	// bne cr6,0x88249dd0
	if (!ctx.cr6.eq) goto loc_88249DD0;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,14416
	ctx.r4.s64 = ctx.r11.s64 + 14416;
	// bl 0x88096cb8
	ctx.lr = 0x88249DCC;
	sub_88096CB8(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
loc_88249DD0:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
loc_88249DD4:
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88249e9c
	if (ctx.cr0.gt) goto loc_88249E9C;
	// stw r25,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r25.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_88249DF0:
	// li r11,2
	ctx.r11.s64 = 2;
	// lis r10,-30686
	ctx.r10.s64 = -2011037696;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-22600
	ctx.r4.s64 = ctx.r10.s64 + -22600;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x88249E0C;
	sub_88097078(ctx, base);
	// li r9,10
	ctx.r9.s64 = 10;
	// stw r3,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_88249E24:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// bl 0x88096e28
	ctx.lr = 0x88249E30;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88249e9c
	if (!ctx.cr6.eq) goto loc_88249E9C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x88096dd0
	ctx.lr = 0x88249E44;
	sub_88096DD0(ctx, base);
	// li r11,11
	ctx.r11.s64 = 11;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_88249E58:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x88096e28
	ctx.lr = 0x88249E64;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88249e9c
	if (!ctx.cr6.eq) goto loc_88249E9C;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88249dd4
	if (!ctx.cr6.eq) goto loc_88249DD4;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,14304
	ctx.r4.s64 = ctx.r11.s64 + 14304;
	// bl 0x88096cb8
	ctx.lr = 0x88249E8C;
	sub_88096CB8(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096830
	ctx.lr = 0x88249E9C;
	sub_88096830(ctx, base);
loc_88249E9C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88249EA8"))) PPC_WEAK_FUNC(sub_88249EA8);
PPC_FUNC_IMPL(__imp__sub_88249EA8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x88249EB0;
	__savegprlr_27(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lwz r27,2304(r3)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x880968b8
	ctx.lr = 0x88249ED4;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bgt cr6,0x8824a08c
	if (ctx.cr6.gt) goto loc_8824A08C;
	// beq cr6,0x8824a018
	if (ctx.cr6.eq) goto loc_8824A018;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88249fc4
	if (ctx.cr6.eq) goto loc_88249FC4;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x88249f8c
	if (ctx.cr6.eq) goto loc_88249F8C;
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// bne cr6,0x8824a1c0
	if (!ctx.cr6.eq) goto loc_8824A1C0;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8824a048
	if (!ctx.cr6.eq) goto loc_8824A048;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880954e0
	ctx.lr = 0x88249F1C;
	sub_880954E0(ctx, base);
	// lis r11,-30682
	ctx.r11.s64 = -2010775552;
	// lwz r8,8(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 8);
	// lis r9,120
	ctx.r9.s64 = 7864320;
	// addi r10,r11,29576
	ctx.r10.s64 = ctx.r11.s64 + 29576;
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// addi r11,r10,8
	ctx.r11.s64 = ctx.r10.s64 + 8;
	// bgt cr6,0x88249f3c
	if (ctx.cr6.gt) goto loc_88249F3C;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_88249F3C:
	// li r10,4
	ctx.r10.s64 = 4;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r10,16(r27)
	PPC_STORE_U32(ctx.r27.u32 + 16, ctx.r10.u32);
	// lis r8,-30685
	ctx.r8.s64 = -2010972160;
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r4,r8,-19528
	ctx.r4.s64 = ctx.r8.s64 + -19528;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r7,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r7.u32);
	// stw r6,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r6.u32);
	// bl 0x880966a8
	ctx.lr = 0x88249F70;
	sub_880966A8(ctx, base);
	// li r5,96
	ctx.r5.s64 = 96;
	// li r4,7
	ctx.r4.s64 = 7;
	// stw r5,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r5.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r4,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r4.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_88249F8C:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8824a048
	if (!ctx.cr6.eq) goto loc_8824A048;
	// lis r11,-30686
	ctx.r11.s64 = -2011037696;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,-24568
	ctx.r4.s64 = ctx.r11.s64 + -24568;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88097078
	ctx.lr = 0x88249FAC;
	sub_88097078(ctx, base);
	// li r10,6
	ctx.r10.s64 = 6;
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_88249FC4:
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 5724);
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x8824a1c0
	if (!ctx.cr6.eq) goto loc_8824A1C0;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8824a048
	if (!ctx.cr6.eq) goto loc_8824A048;
	// lis r11,-30686
	ctx.r11.s64 = -2011037696;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,-24768
	ctx.r4.s64 = ctx.r11.s64 + -24768;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88097078
	ctx.lr = 0x88249FF8;
	sub_88097078(ctx, base);
	// li r10,5
	ctx.r10.s64 = 5;
	// li r9,64
	ctx.r9.s64 = 64;
	// stw r3,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r3.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_8824A018:
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 5724);
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x8824a1c0
	if (!ctx.cr6.eq) goto loc_8824A1C0;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824a068
	if (ctx.cr6.eq) goto loc_8824A068;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096dd0
	ctx.lr = 0x8824A044;
	sub_88096DD0(ctx, base);
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
loc_8824A048:
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824a1c0
	if (ctx.cr0.gt) goto loc_8824A1C0;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_8824A068:
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x88096dd0
	ctx.lr = 0x8824A070;
	sub_88096DD0(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,8
	ctx.r10.s64 = 8;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_8824A08C:
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// beq cr6,0x8824a164
	if (ctx.cr6.eq) goto loc_8824A164;
	// cmpwi cr6,r11,9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 9, ctx.xer);
	// beq cr6,0x8824a0e0
	if (ctx.cr6.eq) goto loc_8824A0E0;
	// cmpwi cr6,r11,40
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 40, ctx.xer);
	// bne cr6,0x8824a1c0
	if (!ctx.cr6.eq) goto loc_8824A1C0;
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 5724);
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x8824a1c0
	if (!ctx.cr6.eq) goto loc_8824A1C0;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824a1c0
	if (ctx.cr0.gt) goto loc_8824A1C0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88096830
	ctx.lr = 0x8824A0D4;
	sub_88096830(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_8824A0E0:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096e28
	ctx.lr = 0x8824A0EC;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8824a1c0
	if (!ctx.cr6.eq) goto loc_8824A1C0;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8824a048
	if (!ctx.cr6.eq) goto loc_8824A048;
	// li r11,4
	ctx.r11.s64 = 4;
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,120
	ctx.r9.s64 = 7864320;
	// stw r11,16(r27)
	PPC_STORE_U32(ctx.r27.u32 + 16, ctx.r11.u32);
	// lis r8,290
	ctx.r8.s64 = 19005440;
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// stw r9,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// lis r7,-30685
	ctx.r7.s64 = -2010972160;
	// stw r8,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r8.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r7,-19528
	ctx.r4.s64 = ctx.r7.s64 + -19528;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x880966a8
	ctx.lr = 0x8824A134;
	sub_880966A8(ctx, base);
	// lis r6,-30696
	ctx.r6.s64 = -2011693056;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,24(r27)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r27.u32 + 24);
	// addi r4,r6,14304
	ctx.r4.s64 = ctx.r6.s64 + 14304;
	// bl 0x88096cb8
	ctx.lr = 0x8824A148;
	sub_88096CB8(ctx, base);
	// li r5,40
	ctx.r5.s64 = 40;
	// li r4,112
	ctx.r4.s64 = 112;
	// stw r5,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r5.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r4,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r4.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_8824A164:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8824a048
	if (!ctx.cr6.eq) goto loc_8824A048;
	// lis r11,-30686
	ctx.r11.s64 = -2011037696;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,-22952
	ctx.r4.s64 = ctx.r11.s64 + -22952;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88097078
	ctx.lr = 0x8824A184;
	sub_88097078(ctx, base);
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// li r30,0
	ctx.r30.s64 = 0;
loc_8824A18C:
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r30.u32);
	// lis r11,-30686
	ctx.r11.s64 = -2011037696;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,-25136
	ctx.r4.s64 = ctx.r11.s64 + -25136;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88097078
	ctx.lr = 0x8824A1A4;
	sub_88097078(ctx, base);
	// addi r30,r30,32
	ctx.r30.s64 = ctx.r30.s64 + 32;
	// cmpwi cr6,r30,256
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 256, ctx.xer);
	// blt cr6,0x8824a18c
	if (ctx.cr6.lt) goto loc_8824A18C;
	// li r11,128
	ctx.r11.s64 = 128;
	// li r10,9
	ctx.r10.s64 = 9;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
loc_8824A1C0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824A1CC"))) PPC_WEAK_FUNC(sub_8824A1CC);
PPC_FUNC_IMPL(__imp__sub_8824A1CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8824A1D0"))) PPC_WEAK_FUNC(sub_8824A1D0);
PPC_FUNC_IMPL(__imp__sub_8824A1D0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x8824A1D8;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x8824A1F8;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// bgt cr6,0x8824a31c
	if (ctx.cr6.gt) goto loc_8824A31C;
	// beq cr6,0x8824a2b0
	if (ctx.cr6.eq) goto loc_8824A2B0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824a244
	if (ctx.cr6.eq) goto loc_8824A244;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x8824a354
	if (!ctx.cr6.eq) goto loc_8824A354;
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x8824a354
	if (!ctx.cr6.eq) goto loc_8824A354;
	// li r11,5
	ctx.r11.s64 = 5;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824A244:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824a354
	if (ctx.cr0.gt) goto loc_8824A354;
	// li r11,10
	ctx.r11.s64 = 10;
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,120
	ctx.r9.s64 = 7864320;
	// stw r11,16(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16, ctx.r11.u32);
	// lis r8,260
	ctx.r8.s64 = 17039360;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// lis r7,-30685
	ctx.r7.s64 = -2010972160;
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r7,-19528
	ctx.r4.s64 = ctx.r7.s64 + -19528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x8824A288;
	sub_880966A8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r6,3
	ctx.r6.s64 = 3;
	// li r5,32
	ctx.r5.s64 = 32;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r6,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r6.u32);
	// stw r5,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r5.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824A2B0:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824a354
	if (ctx.cr0.gt) goto loc_8824A354;
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r9,10
	ctx.r9.s64 = 10;
	// mulli r8,r10,-60
	ctx.r8.s64 = ctx.r10.s64 * -60;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// rlwinm r7,r8,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0x1;
	// lis r6,-30686
	ctx.r6.s64 = -2011037696;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r6,-22792
	ctx.r4.s64 = ctx.r6.s64 + -22792;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x8824A2FC;
	sub_88097078(ctx, base);
	// li r5,100
	ctx.r5.s64 = 100;
	// li r4,256
	ctx.r4.s64 = 256;
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// stw r5,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r5.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r4,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r4.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824A31C:
	// cmpwi cr6,r11,100
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 100, ctx.xer);
	// bne cr6,0x8824a354
	if (!ctx.cr6.eq) goto loc_8824A354;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096e28
	ctx.lr = 0x8824A330;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8824a354
	if (!ctx.cr6.eq) goto loc_8824A354;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824a354
	if (ctx.cr0.gt) goto loc_8824A354;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096830
	ctx.lr = 0x8824A354;
	sub_88096830(ctx, base);
loc_8824A354:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824A360"))) PPC_WEAK_FUNC(sub_8824A360);
PPC_FUNC_IMPL(__imp__sub_8824A360) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x8824A368;
	__savegprlr_26(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r27,2304(r3)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x8824A388;
	sub_880968B8(ctx, base);
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r26,1
	ctx.r26.s64 = 1;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8824a428
	if (ctx.cr6.lt) goto loc_8824A428;
	// bne cr6,0x8824a454
	if (!ctx.cr6.eq) goto loc_8824A454;
	// lwz r11,76(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r11.u32);
	// bgt 0x8824a454
	if (ctx.cr0.gt) goto loc_8824A454;
	// li r11,4
	ctx.r11.s64 = 4;
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r11,16(r27)
	PPC_STORE_U32(ctx.r27.u32 + 16, ctx.r11.u32);
	// li r3,24
	ctx.r3.s64 = 24;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x881534c8
	ctx.lr = 0x8824A3CC;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lwz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// li r3,32
	ctx.r3.s64 = 32;
	// addi r8,r11,8
	ctx.r8.s64 = ctx.r11.s64 + 8;
	// mullw r7,r8,r9
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// subfic r6,r7,60
	ctx.xer.ca = ctx.r7.u32 <= 60;
	ctx.r6.s64 = 60 - ctx.r7.s64;
	// rlwinm r5,r6,17,0,14
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 17) & 0xFFFE0000;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// bl 0x881534c8
	ctx.lr = 0x8824A3F0;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lis r4,-30685
	ctx.r4.s64 = -2010972160;
	// addi r3,r11,274
	ctx.r3.s64 = ctx.r11.s64 + 274;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// rlwinm r11,r3,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 16) & 0xFFFF0000;
	// addi r4,r4,-19528
	ctx.r4.s64 = ctx.r4.s64 + -19528;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x8824A414;
	sub_880966A8(ctx, base);
	// lwz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// stw r29,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r29.u32);
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// stw r9,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r9.u32);
	// b 0x8824a454
	goto loc_8824A454;
loc_8824A428:
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x8824a454
	if (!ctx.cr6.eq) goto loc_8824A454;
	// stw r26,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r26.u32);
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x881534c8
	ctx.lr = 0x8824A448;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// stw r11,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
loc_8824A454:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 11, ctx.xer);
	// bgt cr6,0x8824a6e0
	if (ctx.cr6.gt) goto loc_8824A6E0;
	// lis r12,-30683
	ctx.r12.s64 = -2010841088;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,-23432
	ctx.r12.s64 = ctx.r12.s64 + -23432;
	// lwzx r0,r12,r0
	ctx.r0.u64 = PPC_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u64) {
	case 0:
		goto loc_8824A4A8;
	case 1:
		goto loc_8824A504;
	case 2:
		goto loc_8824A6E0;
	case 3:
		goto loc_8824A6E0;
	case 4:
		goto loc_8824A6E0;
	case 5:
		goto loc_8824A600;
	case 6:
		goto loc_8824A6E0;
	case 7:
		goto loc_8824A6E0;
	case 8:
		goto loc_8824A6E0;
	case 9:
		goto loc_8824A6E0;
	case 10:
		goto loc_8824A6E0;
	case 11:
		goto loc_8824A6B4;
	default:
		__builtin_unreachable();
	}
	// lbz r1,-23384(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -23384);
	// lbz r1,-23292(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -23292);
	// lbz r1,-22816(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -22816);
	// lbz r1,-22816(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -22816);
	// lbz r1,-22816(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -22816);
	// lbz r1,-23040(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -23040);
	// lbz r1,-22816(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -22816);
	// lbz r1,-22816(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -22816);
	// lbz r1,-22816(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -22816);
	// lbz r1,-22816(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -22816);
	// lbz r1,-22816(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -22816);
	// lbz r1,-22860(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -22860);
loc_8824A4A8:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824a6e0
	if (ctx.cr0.gt) goto loc_8824A6E0;
	// stw r29,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r29.u32);
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r29,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r29.u32);
	// addi r4,r11,14416
	ctx.r4.s64 = ctx.r11.s64 + 14416;
	// lwz r3,24(r27)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r27.u32 + 24);
	// bl 0x88096cb8
	ctx.lr = 0x8824A4D8;
	sub_88096CB8(ctx, base);
	// li r10,64
	ctx.r10.s64 = 64;
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r29,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r29.u32);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// stw r29,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r29.u32);
	// stw r26,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r26.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// stw r29,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r29.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_8824A504:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096a68
	ctx.lr = 0x8824A510;
	sub_88096A68(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8824a6e0
	if (!ctx.cr6.eq) goto loc_8824A6E0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// bl 0x88096e28
	ctx.lr = 0x8824A524;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8824a6e0
	if (!ctx.cr6.eq) goto loc_8824A6E0;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824a554
	if (ctx.cr6.eq) goto loc_8824A554;
loc_8824A538:
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824a6e0
	if (ctx.cr0.gt) goto loc_8824A6E0;
	// stw r29,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_8824A554:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// bge 0x8824a6e0
	if (!ctx.cr0.lt) goto loc_8824A6E0;
	// lis r10,-30686
	ctx.r10.s64 = -2011037696;
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r8,32(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r4,r10,-23152
	ctx.r4.s64 = ctx.r10.s64 + -23152;
	// lwz r7,48(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// clrlwi r6,r9,31
	ctx.r6.u64 = ctx.r9.u32 & 0x1;
	// clrlwi r10,r8,31
	ctx.r10.u64 = ctx.r8.u32 & 0x1;
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// bl 0x88097078
	ctx.lr = 0x8824A5A0;
	sub_88097078(ctx, base);
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// lwz r7,40(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// addic. r11,r7,-1
	ctx.xer.ca = ctx.r7.u32 > 0;
	ctx.r11.s64 = ctx.r7.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// stw r6,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r6.u32);
	// stw r8,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r8.u32);
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// bgt 0x8824a6e0
	if (ctx.cr0.gt) goto loc_8824A6E0;
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// li r9,5
	ctx.r9.s64 = 5;
	// stw r29,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_8824A600:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x88096e28
	ctx.lr = 0x8824A60C;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8824a6e0
	if (!ctx.cr6.eq) goto loc_8824A6E0;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8824a538
	if (!ctx.cr6.eq) goto loc_8824A538;
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lis r10,-30686
	ctx.r10.s64 = -2011037696;
	// lwz r9,60(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-23400
	ctx.r4.s64 = ctx.r10.s64 + -23400;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// bl 0x88097078
	ctx.lr = 0x8824A644;
	sub_88097078(ctx, base);
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// stw r3,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r3.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// blt cr6,0x8824a664
	if (ctx.cr6.lt) goto loc_8824A664;
	// li r11,5
	ctx.r11.s64 = 5;
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
loc_8824A664:
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// li r10,32
	ctx.r10.s64 = 32;
	// stw r26,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r26.u32);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r26,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r26.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// bgt 0x8824a6e0
	if (ctx.cr0.gt) goto loc_8824A6E0;
	// li r11,11
	ctx.r11.s64 = 11;
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// lis r10,-30696
	ctx.r10.s64 = -2011693056;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,14304
	ctx.r4.s64 = ctx.r10.s64 + 14304;
	// lwz r3,24(r27)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r27.u32 + 24);
	// bl 0x88096cb8
	ctx.lr = 0x8824A6A4;
	sub_88096CB8(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_8824A6B4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096a68
	ctx.lr = 0x8824A6C0;
	sub_88096A68(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8824a6e0
	if (!ctx.cr6.eq) goto loc_8824A6E0;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8824a538
	if (!ctx.cr6.eq) goto loc_8824A538;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096830
	ctx.lr = 0x8824A6E0;
	sub_88096830(ctx, base);
loc_8824A6E0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824A6EC"))) PPC_WEAK_FUNC(sub_8824A6EC);
PPC_FUNC_IMPL(__imp__sub_8824A6EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8824A6F0"))) PPC_WEAK_FUNC(sub_8824A6F0);
PPC_FUNC_IMPL(__imp__sub_8824A6F0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x8824A6F8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,40
	ctx.r5.s64 = 40;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x880968b8
	ctx.lr = 0x8824A718;
	sub_880968B8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r9,-30683
	ctx.r9.s64 = -2010841088;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r9,-25592
	ctx.r5.s64 = ctx.r9.s64 + -25592;
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,32(r10)
	PPC_STORE_U32(ctx.r10.u32 + 32, ctx.r11.u32);
	// stw r11,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r11.u32);
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// stw r8,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r8.u32);
	// bl 0x88096950
	ctx.lr = 0x8824A74C;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824A758"))) PPC_WEAK_FUNC(sub_8824A758);
PPC_FUNC_IMPL(__imp__sub_8824A758) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x8824A760;
	__savegprlr_27(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,56
	ctx.r5.s64 = 56;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x880968b8
	ctx.lr = 0x8824A784;
	sub_880968B8(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,30
	ctx.r10.s64 = 30;
	// li r9,8
	ctx.r9.s64 = 8;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r8,3
	ctx.r8.s64 = 3;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lis r7,120
	ctx.r7.s64 = 7864320;
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r11.u32);
	// lis r6,290
	ctx.r6.s64 = 19005440;
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r11.u32);
	// stw r11,32(r27)
	PPC_STORE_U32(ctx.r27.u32 + 32, ctx.r11.u32);
	// lis r4,-30685
	ctx.r4.s64 = -2010972160;
	// stw r11,52(r27)
	PPC_STORE_U32(ctx.r27.u32 + 52, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// addi r4,r4,-19528
	ctx.r4.s64 = ctx.r4.s64 + -19528;
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// stw r9,16(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16, ctx.r9.u32);
	// bl 0x880966a8
	ctx.lr = 0x8824A7DC;
	sub_880966A8(ctx, base);
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lis r3,-30683
	ctx.r3.s64 = -2010841088;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r3,-24920
	ctx.r5.s64 = ctx.r3.s64 + -24920;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,36(r27)
	PPC_STORE_U32(ctx.r27.u32 + 36, ctx.r11.u32);
	// bl 0x88096950
	ctx.lr = 0x8824A7F8;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824A804"))) PPC_WEAK_FUNC(sub_8824A804);
PPC_FUNC_IMPL(__imp__sub_8824A804) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8824A808"))) PPC_WEAK_FUNC(sub_8824A808);
PPC_FUNC_IMPL(__imp__sub_8824A808) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x8824A810;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,40
	ctx.r5.s64 = 40;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x880968b8
	ctx.lr = 0x8824A830;
	sub_880968B8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r9,-30683
	ctx.r9.s64 = -2010841088;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r9,-24112
	ctx.r5.s64 = ctx.r9.s64 + -24112;
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// stw r8,36(r10)
	PPC_STORE_U32(ctx.r10.u32 + 36, ctx.r8.u32);
	// bl 0x88096950
	ctx.lr = 0x8824A85C;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824A868"))) PPC_WEAK_FUNC(sub_8824A868);
PPC_FUNC_IMPL(__imp__sub_8824A868) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x8824A870;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,80
	ctx.r5.s64 = 80;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x880968b8
	ctx.lr = 0x8824A890;
	sub_880968B8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// lis r7,-30671
	ctx.r7.s64 = -2010054656;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// lis r6,16838
	ctx.r6.s64 = 1103495168;
	// stw r11,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r11.u32);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// ori r5,r6,20077
	ctx.r5.u64 = ctx.r6.u64 | 20077;
	// li r3,3
	ctx.r3.s64 = 3;
	// lwz r10,4200(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4200);
	// li r9,4
	ctx.r9.s64 = 4;
	// li r4,20
	ctx.r4.s64 = 20;
	// mullw r10,r10,r5
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r5.s32);
	// stw r3,52(r8)
	PPC_STORE_U32(ctx.r8.u32 + 52, ctx.r3.u32);
	// stw r4,28(r8)
	PPC_STORE_U32(ctx.r8.u32 + 28, ctx.r4.u32);
	// stw r11,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r11.u32);
	// stw r9,40(r8)
	PPC_STORE_U32(ctx.r8.u32 + 40, ctx.r9.u32);
	// stw r9,44(r8)
	PPC_STORE_U32(ctx.r8.u32 + 44, ctx.r9.u32);
	// stw r11,36(r8)
	PPC_STORE_U32(ctx.r8.u32 + 36, ctx.r11.u32);
	// stw r11,48(r8)
	PPC_STORE_U32(ctx.r8.u32 + 48, ctx.r11.u32);
	// stw r11,60(r8)
	PPC_STORE_U32(ctx.r8.u32 + 60, ctx.r11.u32);
	// addi r10,r10,12345
	ctx.r10.s64 = ctx.r10.s64 + 12345;
	// li r6,2
	ctx.r6.s64 = 2;
	// stw r10,4200(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4200, ctx.r10.u32);
	// lis r5,-30683
	ctx.r5.s64 = -2010841088;
	// lhz r10,4200(r7)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + 4200);
	// clrlwi r3,r10,31
	ctx.r3.u64 = ctx.r10.u32 & 0x1;
	// stw r3,32(r8)
	PPC_STORE_U32(ctx.r8.u32 + 32, ctx.r3.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r6,56(r8)
	PPC_STORE_U32(ctx.r8.u32 + 56, ctx.r6.u32);
	// addi r5,r5,-23712
	ctx.r5.s64 = ctx.r5.s64 + -23712;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,64(r8)
	PPC_STORE_U32(ctx.r8.u32 + 64, ctx.r11.u32);
	// bl 0x88096950
	ctx.lr = 0x8824A91C;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824A928"))) PPC_WEAK_FUNC(sub_8824A928);
PPC_FUNC_IMPL(__imp__sub_8824A928) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x8824A930;
	__savegprlr_29(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x8824A94C;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bgt cr6,0x8824aa8c
	if (ctx.cr6.gt) goto loc_8824AA8C;
	// beq cr6,0x8824aa30
	if (ctx.cr6.eq) goto loc_8824AA30;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824a9cc
	if (ctx.cr6.eq) goto loc_8824A9CC;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// bne cr6,0x8824ab48
	if (!ctx.cr6.eq) goto loc_8824AB48;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096710
	ctx.lr = 0x8824A97C;
	sub_88096710(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8824ab48
	if (!ctx.cr6.eq) goto loc_8824AB48;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824ab48
	if (ctx.cr0.gt) goto loc_8824AB48;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r10,-30683
	ctx.r10.s64 = -2010841088;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-22520
	ctx.r4.s64 = ctx.r10.s64 + -22520;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x880969a8
	ctx.lr = 0x8824A9B0;
	sub_880969A8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// bl 0x88096760
	ctx.lr = 0x8824A9C4;
	sub_88096760(ctx, base);
	// li r8,30
	ctx.r8.s64 = 30;
	// b 0x8824ab3c
	goto loc_8824AB3C;
loc_8824A9CC:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824ab48
	if (ctx.cr0.gt) goto loc_8824AB48;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r10,-30683
	ctx.r10.s64 = -2010841088;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// neg r9,r11
	ctx.r9.s64 = -ctx.r11.s64;
	// addi r4,r10,-22424
	ctx.r4.s64 = ctx.r10.s64 + -22424;
	// stw r9,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r9.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x880969a8
	ctx.lr = 0x8824AA00;
	sub_880969A8(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r8,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r8.u32);
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// bl 0x88096760
	ctx.lr = 0x8824AA14;
	sub_88096760(ctx, base);
	// li r7,20
	ctx.r7.s64 = 20;
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r6,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r6.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_8824AA30:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096710
	ctx.lr = 0x8824AA3C;
	sub_88096710(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8824ab48
	if (!ctx.cr6.eq) goto loc_8824AB48;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824ab48
	if (ctx.cr0.gt) goto loc_8824AB48;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r10,-30683
	ctx.r10.s64 = -2010841088;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-22696
	ctx.r4.s64 = ctx.r10.s64 + -22696;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x880969a8
	ctx.lr = 0x8824AA70;
	sub_880969A8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// bl 0x88096760
	ctx.lr = 0x8824AA84;
	sub_88096760(ctx, base);
	// li r8,25
	ctx.r8.s64 = 25;
	// b 0x8824ab3c
	goto loc_8824AB3C;
loc_8824AA8C:
	// cmpwi cr6,r11,25
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 25, ctx.xer);
	// beq cr6,0x8824aae4
	if (ctx.cr6.eq) goto loc_8824AAE4;
	// cmpwi cr6,r11,30
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 30, ctx.xer);
	// bne cr6,0x8824ab48
	if (!ctx.cr6.eq) goto loc_8824AB48;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096710
	ctx.lr = 0x8824AAA8;
	sub_88096710(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8824ab48
	if (!ctx.cr6.eq) goto loc_8824AB48;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824ab48
	if (ctx.cr0.gt) goto loc_8824AB48;
	// lwz r11,15768(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 15768);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,15768(r29)
	PPC_STORE_U32(ctx.r29.u32 + 15768, ctx.r11.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_8824AAE4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096710
	ctx.lr = 0x8824AAF0;
	sub_88096710(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8824ab48
	if (!ctx.cr6.eq) goto loc_8824AB48;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824ab48
	if (ctx.cr0.gt) goto loc_8824AB48;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r10,-30683
	ctx.r10.s64 = -2010841088;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-22800
	ctx.r4.s64 = ctx.r10.s64 + -22800;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x880969a8
	ctx.lr = 0x8824AB24;
	sub_880969A8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// bl 0x88096760
	ctx.lr = 0x8824AB38;
	sub_88096760(ctx, base);
	// li r8,10
	ctx.r8.s64 = 10;
loc_8824AB3C:
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r8,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// stw r7,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r7.u32);
loc_8824AB48:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824AB54"))) PPC_WEAK_FUNC(sub_8824AB54);
PPC_FUNC_IMPL(__imp__sub_8824AB54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8824AB58"))) PPC_WEAK_FUNC(sub_8824AB58);
PPC_FUNC_IMPL(__imp__sub_8824AB58) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x8824AB60;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880968b8
	ctx.lr = 0x8824AB80;
	sub_880968B8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// lis r9,120
	ctx.r9.s64 = 7864320;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// lwz r8,8(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x8824abac
	if (!ctx.cr6.lt) goto loc_8824ABAC;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
loc_8824ABAC:
	// stw r11,15768(r29)
	PPC_STORE_U32(ctx.r29.u32 + 15768, ctx.r11.u32);
	// lis r11,-30683
	ctx.r11.s64 = -2010841088;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r11,-22232
	ctx.r5.s64 = ctx.r11.s64 + -22232;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096950
	ctx.lr = 0x8824ABC4;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824ABD0"))) PPC_WEAK_FUNC(sub_8824ABD0);
PPC_FUNC_IMPL(__imp__sub_8824ABD0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x8824ABD8;
	__savegprlr_26(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x8824ABF8;
	sub_880968B8(ctx, base);
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r26,0
	ctx.r26.s64 = 0;
	// li r27,1
	ctx.r27.s64 = 1;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8824ac98
	if (ctx.cr6.lt) goto loc_8824AC98;
	// bne cr6,0x8824acc4
	if (!ctx.cr6.eq) goto loc_8824ACC4;
	// lwz r11,36(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r11.u32);
	// bgt 0x8824acc4
	if (ctx.cr0.gt) goto loc_8824ACC4;
	// li r11,4
	ctx.r11.s64 = 4;
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r11,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r11.u32);
	// li r3,24
	ctx.r3.s64 = 24;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x881534c8
	ctx.lr = 0x8824AC3C;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// li r3,32
	ctx.r3.s64 = 32;
	// addi r8,r11,8
	ctx.r8.s64 = ctx.r11.s64 + 8;
	// mullw r7,r8,r9
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// subfic r6,r7,60
	ctx.xer.ca = ctx.r7.u32 <= 60;
	ctx.r6.s64 = 60 - ctx.r7.s64;
	// rlwinm r5,r6,17,0,14
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 17) & 0xFFFE0000;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// bl 0x881534c8
	ctx.lr = 0x8824AC60;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lis r4,-30685
	ctx.r4.s64 = -2010972160;
	// addi r3,r11,264
	ctx.r3.s64 = ctx.r11.s64 + 264;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// rlwinm r11,r3,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 16) & 0xFFFF0000;
	// addi r4,r4,-19528
	ctx.r4.s64 = ctx.r4.s64 + -19528;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x8824AC84;
	sub_880966A8(ctx, base);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// stw r26,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r26.u32);
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// stw r9,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r9.u32);
	// b 0x8824acc4
	goto loc_8824ACC4;
loc_8824AC98:
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x8824acc4
	if (!ctx.cr6.eq) goto loc_8824ACC4;
	// stw r27,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r27.u32);
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x881534c8
	ctx.lr = 0x8824ACB8;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
loc_8824ACC4:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 11, ctx.xer);
	// bgt cr6,0x8824ae68
	if (ctx.cr6.gt) goto loc_8824AE68;
	// lis r12,-30683
	ctx.r12.s64 = -2010841088;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,-21272
	ctx.r12.s64 = ctx.r12.s64 + -21272;
	// lwzx r0,r12,r0
	ctx.r0.u64 = PPC_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u64) {
	case 0:
		goto loc_8824AD18;
	case 1:
		goto loc_8824AD70;
	case 2:
		goto loc_8824AE68;
	case 3:
		goto loc_8824AE68;
	case 4:
		goto loc_8824AE68;
	case 5:
		goto loc_8824AE68;
	case 6:
		goto loc_8824AE68;
	case 7:
		goto loc_8824AE68;
	case 8:
		goto loc_8824AE68;
	case 9:
		goto loc_8824AE68;
	case 10:
		goto loc_8824ADF0;
	case 11:
		goto loc_8824AE24;
	default:
		__builtin_unreachable();
	}
	// lbz r1,-21224(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -21224);
	// lbz r1,-21136(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -21136);
	// lbz r1,-20888(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -20888);
	// lbz r1,-20888(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -20888);
	// lbz r1,-20888(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -20888);
	// lbz r1,-20888(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -20888);
	// lbz r1,-20888(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -20888);
	// lbz r1,-20888(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -20888);
	// lbz r1,-20888(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -20888);
	// lbz r1,-20888(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -20888);
	// lbz r1,-21008(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -21008);
	// lbz r1,-20956(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -20956);
loc_8824AD18:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// bl 0x88096e28
	ctx.lr = 0x8824AD24;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8824ae68
	if (!ctx.cr6.eq) goto loc_8824AE68;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8824ada0
	if (!ctx.cr6.eq) goto loc_8824ADA0;
	// li r11,2
	ctx.r11.s64 = 2;
	// lis r10,-30686
	ctx.r10.s64 = -2011037696;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-18488
	ctx.r4.s64 = ctx.r10.s64 + -18488;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x8824AD54;
	sub_88097078(ctx, base);
	// li r9,128
	ctx.r9.s64 = 128;
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// stw r27,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r27.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_8824AD70:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824adbc
	if (ctx.cr6.eq) goto loc_8824ADBC;
	// cmpwi cr6,r11,64
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 64, ctx.xer);
	// bne cr6,0x8824ad9c
	if (!ctx.cr6.eq) goto loc_8824AD9C;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,14416
	ctx.r4.s64 = ctx.r11.s64 + 14416;
	// bl 0x88096cb8
	ctx.lr = 0x8824AD98;
	sub_88096CB8(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
loc_8824AD9C:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
loc_8824ADA0:
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824ae68
	if (ctx.cr0.gt) goto loc_8824AE68;
	// stw r26,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r26.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_8824ADBC:
	// li r11,2
	ctx.r11.s64 = 2;
	// lis r10,-30686
	ctx.r10.s64 = -2011037696;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-17120
	ctx.r4.s64 = ctx.r10.s64 + -17120;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x8824ADD8;
	sub_88097078(ctx, base);
	// li r9,10
	ctx.r9.s64 = 10;
	// stw r3,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_8824ADF0:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// bl 0x88096e28
	ctx.lr = 0x8824ADFC;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8824ae68
	if (!ctx.cr6.eq) goto loc_8824AE68;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x88096dd0
	ctx.lr = 0x8824AE10;
	sub_88096DD0(ctx, base);
	// li r11,11
	ctx.r11.s64 = 11;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_8824AE24:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x88096e28
	ctx.lr = 0x8824AE30;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8824ae68
	if (!ctx.cr6.eq) goto loc_8824AE68;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8824ada0
	if (!ctx.cr6.eq) goto loc_8824ADA0;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,14304
	ctx.r4.s64 = ctx.r11.s64 + 14304;
	// bl 0x88096cb8
	ctx.lr = 0x8824AE58;
	sub_88096CB8(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096830
	ctx.lr = 0x8824AE68;
	sub_88096830(ctx, base);
loc_8824AE68:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824AE74"))) PPC_WEAK_FUNC(sub_8824AE74);
PPC_FUNC_IMPL(__imp__sub_8824AE74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8824AE78"))) PPC_WEAK_FUNC(sub_8824AE78);
PPC_FUNC_IMPL(__imp__sub_8824AE78) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x8824AE80;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x880968b8
	ctx.lr = 0x8824AEA0;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bgt cr6,0x8824b068
	if (ctx.cr6.gt) goto loc_8824B068;
	// beq cr6,0x8824aff4
	if (ctx.cr6.eq) goto loc_8824AFF4;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824af80
	if (ctx.cr6.eq) goto loc_8824AF80;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x8824af48
	if (ctx.cr6.eq) goto loc_8824AF48;
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// bne cr6,0x8824b1c8
	if (!ctx.cr6.eq) goto loc_8824B1C8;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8824afa0
	if (!ctx.cr6.eq) goto loc_8824AFA0;
	// lis r11,-30682
	ctx.r11.s64 = -2010775552;
	// lwz r9,8(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8);
	// lis r8,120
	ctx.r8.s64 = 7864320;
	// addi r10,r11,29608
	ctx.r10.s64 = ctx.r11.s64 + 29608;
	// cmpw cr6,r9,r8
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, ctx.xer);
	// addi r11,r10,8
	ctx.r11.s64 = ctx.r10.s64 + 8;
	// bgt cr6,0x8824aef8
	if (ctx.cr6.gt) goto loc_8824AEF8;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_8824AEF8:
	// li r10,4
	ctx.r10.s64 = 4;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r10,16(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16, ctx.r10.u32);
	// lis r8,-30685
	ctx.r8.s64 = -2010972160;
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r4,r8,-19528
	ctx.r4.s64 = ctx.r8.s64 + -19528;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// bl 0x880966a8
	ctx.lr = 0x8824AF2C;
	sub_880966A8(ctx, base);
	// li r5,192
	ctx.r5.s64 = 192;
	// li r4,7
	ctx.r4.s64 = 7;
	// stw r5,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r5.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r4,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r4.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824AF48:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8824afa0
	if (!ctx.cr6.eq) goto loc_8824AFA0;
	// lis r11,-30686
	ctx.r11.s64 = -2011037696;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-18912
	ctx.r4.s64 = ctx.r11.s64 + -18912;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88097078
	ctx.lr = 0x8824AF68;
	sub_88097078(ctx, base);
	// li r10,6
	ctx.r10.s64 = 6;
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824AF80:
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 5724);
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x8824b1c8
	if (!ctx.cr6.eq) goto loc_8824B1C8;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824afc0
	if (ctx.cr6.eq) goto loc_8824AFC0;
loc_8824AFA0:
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824b1c8
	if (ctx.cr0.gt) goto loc_8824B1C8;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824AFC0:
	// lis r11,-30686
	ctx.r11.s64 = -2011037696;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-19144
	ctx.r4.s64 = ctx.r11.s64 + -19144;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88097078
	ctx.lr = 0x8824AFD4;
	sub_88097078(ctx, base);
	// li r10,5
	ctx.r10.s64 = 5;
	// li r9,64
	ctx.r9.s64 = 64;
	// stw r3,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r3.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824AFF4:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824b038
	if (ctx.cr6.eq) goto loc_8824B038;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824b1c8
	if (ctx.cr0.gt) goto loc_8824B1C8;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096dd0
	ctx.lr = 0x8824B018;
	sub_88096DD0(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x88096dd0
	ctx.lr = 0x8824B024;
	sub_88096DD0(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824B038:
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 5724);
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x8824b1c8
	if (!ctx.cr6.eq) goto loc_8824B1C8;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,8
	ctx.r10.s64 = 8;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824B068:
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// beq cr6,0x8824b138
	if (ctx.cr6.eq) goto loc_8824B138;
	// cmpwi cr6,r11,9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 9, ctx.xer);
	// beq cr6,0x8824b0bc
	if (ctx.cr6.eq) goto loc_8824B0BC;
	// cmpwi cr6,r11,40
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 40, ctx.xer);
	// bne cr6,0x8824b1c8
	if (!ctx.cr6.eq) goto loc_8824B1C8;
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 5724);
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x8824b1c8
	if (!ctx.cr6.eq) goto loc_8824B1C8;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824b1c8
	if (ctx.cr0.gt) goto loc_8824B1C8;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88096830
	ctx.lr = 0x8824B0B0;
	sub_88096830(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824B0BC:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824b0f4
	if (ctx.cr6.eq) goto loc_8824B0F4;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824b1c8
	if (ctx.cr0.gt) goto loc_8824B1C8;
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bl 0x88096dd0
	ctx.lr = 0x8824B0E8;
	sub_88096DD0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824B0F4:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096e28
	ctx.lr = 0x8824B100;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8824b1c8
	if (!ctx.cr6.eq) goto loc_8824B1C8;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// lwz r3,24(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,14304
	ctx.r4.s64 = ctx.r11.s64 + 14304;
	// bl 0x88096cb8
	ctx.lr = 0x8824B11C;
	sub_88096CB8(ctx, base);
	// li r10,40
	ctx.r10.s64 = 40;
	// li r9,112
	ctx.r9.s64 = 112;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824B138:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8824afa0
	if (!ctx.cr6.eq) goto loc_8824AFA0;
	// lis r11,-30686
	ctx.r11.s64 = -2011037696;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-19304
	ctx.r4.s64 = ctx.r11.s64 + -19304;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88097078
	ctx.lr = 0x8824B158;
	sub_88097078(ctx, base);
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// li r30,0
	ctx.r30.s64 = 0;
loc_8824B160:
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// lis r11,-30686
	ctx.r11.s64 = -2011037696;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-19480
	ctx.r4.s64 = ctx.r11.s64 + -19480;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88097078
	ctx.lr = 0x8824B178;
	sub_88097078(ctx, base);
	// addi r30,r30,32
	ctx.r30.s64 = ctx.r30.s64 + 32;
	// cmpwi cr6,r30,256
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 256, ctx.xer);
	// blt cr6,0x8824b160
	if (ctx.cr6.lt) goto loc_8824B160;
	// li r11,4
	ctx.r11.s64 = 4;
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,120
	ctx.r9.s64 = 7864320;
	// stw r11,16(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16, ctx.r11.u32);
	// lis r8,280
	ctx.r8.s64 = 18350080;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// lis r7,-30685
	ctx.r7.s64 = -2010972160;
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r7,-19528
	ctx.r4.s64 = ctx.r7.s64 + -19528;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x880966a8
	ctx.lr = 0x8824B1B8;
	sub_880966A8(ctx, base);
	// li r6,272
	ctx.r6.s64 = 272;
	// li r5,9
	ctx.r5.s64 = 9;
	// stw r6,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r6.u32);
	// stw r5,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r5.u32);
loc_8824B1C8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824B1D4"))) PPC_WEAK_FUNC(sub_8824B1D4);
PPC_FUNC_IMPL(__imp__sub_8824B1D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8824B1D8"))) PPC_WEAK_FUNC(sub_8824B1D8);
PPC_FUNC_IMPL(__imp__sub_8824B1D8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x8824B1E0;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x8824B200;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// bgt cr6,0x8824b30c
	if (ctx.cr6.gt) goto loc_8824B30C;
	// beq cr6,0x8824b2b8
	if (ctx.cr6.eq) goto loc_8824B2B8;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824b24c
	if (ctx.cr6.eq) goto loc_8824B24C;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x8824b344
	if (!ctx.cr6.eq) goto loc_8824B344;
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x8824b344
	if (!ctx.cr6.eq) goto loc_8824B344;
	// li r11,5
	ctx.r11.s64 = 5;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824B24C:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824b344
	if (ctx.cr0.gt) goto loc_8824B344;
	// li r11,10
	ctx.r11.s64 = 10;
	// li r10,2
	ctx.r10.s64 = 2;
	// lis r9,120
	ctx.r9.s64 = 7864320;
	// stw r11,16(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16, ctx.r11.u32);
	// lis r8,240
	ctx.r8.s64 = 15728640;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// lis r7,-30685
	ctx.r7.s64 = -2010972160;
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r7,-19528
	ctx.r4.s64 = ctx.r7.s64 + -19528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x8824B290;
	sub_880966A8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r6,3
	ctx.r6.s64 = 3;
	// li r5,16
	ctx.r5.s64 = 16;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r6,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r6.u32);
	// stw r5,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r5.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824B2B8:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824b344
	if (ctx.cr0.gt) goto loc_8824B344;
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r10,-30686
	ctx.r10.s64 = -2011037696;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// addi r4,r10,-17288
	ctx.r4.s64 = ctx.r10.s64 + -17288;
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x8824B2EC;
	sub_88097078(ctx, base);
	// li r9,100
	ctx.r9.s64 = 100;
	// li r8,256
	ctx.r8.s64 = 256;
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r8,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824B30C:
	// cmpwi cr6,r11,100
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 100, ctx.xer);
	// bne cr6,0x8824b344
	if (!ctx.cr6.eq) goto loc_8824B344;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096e28
	ctx.lr = 0x8824B320;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8824b344
	if (!ctx.cr6.eq) goto loc_8824B344;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824b344
	if (ctx.cr0.gt) goto loc_8824B344;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096830
	ctx.lr = 0x8824B344;
	sub_88096830(ctx, base);
loc_8824B344:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824B350"))) PPC_WEAK_FUNC(sub_8824B350);
PPC_FUNC_IMPL(__imp__sub_8824B350) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x8824B358;
	__savegprlr_25(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r27,2304(r3)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x8824B378;
	sub_880968B8(ctx, base);
	// lwz r11,80(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r25,4
	ctx.r25.s64 = 4;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r26,1
	ctx.r26.s64 = 1;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8824b418
	if (ctx.cr6.lt) goto loc_8824B418;
	// bne cr6,0x8824b444
	if (!ctx.cr6.eq) goto loc_8824B444;
	// lwz r11,84(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, ctx.r11.u32);
	// bgt 0x8824b444
	if (ctx.cr0.gt) goto loc_8824B444;
	// stw r25,16(r27)
	PPC_STORE_U32(ctx.r27.u32 + 16, ctx.r25.u32);
	// li r11,3
	ctx.r11.s64 = 3;
	// li r3,24
	ctx.r3.s64 = 24;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x881534c8
	ctx.lr = 0x8824B3BC;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// li r3,32
	ctx.r3.s64 = 32;
	// addi r9,r11,8
	ctx.r9.s64 = ctx.r11.s64 + 8;
	// mullw r8,r9,r10
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// subfic r7,r8,60
	ctx.xer.ca = ctx.r8.u32 <= 60;
	ctx.r7.s64 = 60 - ctx.r8.s64;
	// rlwinm r6,r7,17,0,14
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 17) & 0xFFFE0000;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// bl 0x881534c8
	ctx.lr = 0x8824B3E0;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lis r4,-30685
	ctx.r4.s64 = -2010972160;
	// addi r3,r11,294
	ctx.r3.s64 = ctx.r11.s64 + 294;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// rlwinm r11,r3,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 16) & 0xFFFF0000;
	// addi r4,r4,-19528
	ctx.r4.s64 = ctx.r4.s64 + -19528;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x8824B404;
	sub_880966A8(ctx, base);
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// stw r29,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r29.u32);
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// stw r9,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r9.u32);
	// b 0x8824b444
	goto loc_8824B444;
loc_8824B418:
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// lwz r10,5724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5724);
	// addi r9,r11,-20824
	ctx.r9.s64 = ctx.r11.s64 + -20824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x8824b444
	if (!ctx.cr6.eq) goto loc_8824B444;
	// stw r26,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r26.u32);
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x881534c8
	ctx.lr = 0x8824B438;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
loc_8824B444:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 11, ctx.xer);
	// bgt cr6,0x8824b700
	if (ctx.cr6.gt) goto loc_8824B700;
	// lis r12,-30683
	ctx.r12.s64 = -2010841088;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,-19352
	ctx.r12.s64 = ctx.r12.s64 + -19352;
	// lwzx r0,r12,r0
	ctx.r0.u64 = PPC_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u64) {
	case 0:
		goto loc_8824B498;
	case 1:
		goto loc_8824B4F4;
	case 2:
		goto loc_8824B700;
	case 3:
		goto loc_8824B700;
	case 4:
		goto loc_8824B700;
	case 5:
		goto loc_8824B61C;
	case 6:
		goto loc_8824B700;
	case 7:
		goto loc_8824B700;
	case 8:
		goto loc_8824B700;
	case 9:
		goto loc_8824B700;
	case 10:
		goto loc_8824B700;
	case 11:
		goto loc_8824B6D4;
	default:
		__builtin_unreachable();
	}
	// lbz r1,-19304(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -19304);
	// lbz r1,-19212(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -19212);
	// lbz r1,-18688(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -18688);
	// lbz r1,-18688(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -18688);
	// lbz r1,-18688(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -18688);
	// lbz r1,-18916(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -18916);
	// lbz r1,-18688(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -18688);
	// lbz r1,-18688(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -18688);
	// lbz r1,-18688(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -18688);
	// lbz r1,-18688(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -18688);
	// lbz r1,-18688(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -18688);
	// lbz r1,-18732(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -18732);
loc_8824B498:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824b700
	if (ctx.cr0.gt) goto loc_8824B700;
	// stw r29,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r29.u32);
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r29,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r29.u32);
	// addi r4,r11,14416
	ctx.r4.s64 = ctx.r11.s64 + 14416;
	// lwz r3,24(r27)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r27.u32 + 24);
	// bl 0x88096cb8
	ctx.lr = 0x8824B4C8;
	sub_88096CB8(ctx, base);
	// li r10,64
	ctx.r10.s64 = 64;
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r29,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r29.u32);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// stw r29,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r29.u32);
	// stw r26,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r26.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// stw r29,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r29.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_8824B4F4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096a68
	ctx.lr = 0x8824B500;
	sub_88096A68(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8824b700
	if (!ctx.cr6.eq) goto loc_8824B700;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// bl 0x88096e28
	ctx.lr = 0x8824B514;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8824b700
	if (!ctx.cr6.eq) goto loc_8824B700;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824b544
	if (ctx.cr6.eq) goto loc_8824B544;
loc_8824B528:
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824b700
	if (ctx.cr0.gt) goto loc_8824B700;
	// stw r29,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_8824B544:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// bge 0x8824b700
	if (!ctx.cr0.lt) goto loc_8824B700;
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r10,-30686
	ctx.r10.s64 = -2011037696;
	// lwz r8,32(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// clrlwi r6,r9,31
	ctx.r6.u64 = ctx.r9.u32 & 0x1;
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// clrlwi r9,r8,31
	ctx.r9.u64 = ctx.r8.u32 & 0x1;
	// lwz r7,48(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// addi r4,r10,-17496
	ctx.r4.s64 = ctx.r10.s64 + -17496;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r8,56(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// stw r8,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// bl 0x88097078
	ctx.lr = 0x8824B5A0;
	sub_88097078(ctx, base);
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r7,r8,1
	ctx.r7.s64 = ctx.r8.s64 + 1;
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// addi r4,r9,1
	ctx.r4.s64 = ctx.r9.s64 + 1;
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// addic. r11,r6,-1
	ctx.xer.ca = ctx.r6.u32 > 0;
	ctx.r11.s64 = ctx.r6.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// stw r7,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r7.u32);
	// stw r4,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r4.u32);
	// stw r5,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r5.u32);
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// bgt 0x8824b700
	if (ctx.cr0.gt) goto loc_8824B700;
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// addi r10,r10,-12
	ctx.r10.s64 = ctx.r10.s64 + -12;
	// lwz r9,44(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// li r8,5
	ctx.r8.s64 = 5;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// stw r25,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r25.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r7,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r7.u32);
	// stw r29,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// stw r9,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r9.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_8824B61C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x88096e28
	ctx.lr = 0x8824B628;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8824b700
	if (!ctx.cr6.eq) goto loc_8824B700;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8824b528
	if (!ctx.cr6.eq) goto loc_8824B528;
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// lis r10,-30686
	ctx.r10.s64 = -2011037696;
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-17752
	ctx.r4.s64 = ctx.r10.s64 + -17752;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// bl 0x88097078
	ctx.lr = 0x8824B660;
	sub_88097078(ctx, base);
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// stw r3,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r3.u32);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// stw r11,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// blt cr6,0x8824b680
	if (ctx.cr6.lt) goto loc_8824B680;
	// li r11,5
	ctx.r11.s64 = 5;
	// stw r11,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
loc_8824B680:
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// li r10,32
	ctx.r10.s64 = 32;
	// stw r26,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r26.u32);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r26,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r26.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// bgt 0x8824b700
	if (ctx.cr0.gt) goto loc_8824B700;
	// li r10,48
	ctx.r10.s64 = 48;
	// li r11,11
	ctx.r11.s64 = 11;
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// lis r9,-30696
	ctx.r9.s64 = -2011693056;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,14304
	ctx.r4.s64 = ctx.r9.s64 + 14304;
	// lwz r3,24(r27)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r27.u32 + 24);
	// bl 0x88096cb8
	ctx.lr = 0x8824B6C4;
	sub_88096CB8(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_8824B6D4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096a68
	ctx.lr = 0x8824B6E0;
	sub_88096A68(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8824b700
	if (!ctx.cr6.eq) goto loc_8824B700;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8824b528
	if (!ctx.cr6.eq) goto loc_8824B528;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096830
	ctx.lr = 0x8824B700;
	sub_88096830(ctx, base);
loc_8824B700:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824B70C"))) PPC_WEAK_FUNC(sub_8824B70C);
PPC_FUNC_IMPL(__imp__sub_8824B70C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8824B710"))) PPC_WEAK_FUNC(sub_8824B710);
PPC_FUNC_IMPL(__imp__sub_8824B710) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x8824B718;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,40
	ctx.r5.s64 = 40;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x880968b8
	ctx.lr = 0x8824B738;
	sub_880968B8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r9,-30683
	ctx.r9.s64 = -2010841088;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r9,-21552
	ctx.r5.s64 = ctx.r9.s64 + -21552;
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,32(r10)
	PPC_STORE_U32(ctx.r10.u32 + 32, ctx.r11.u32);
	// stw r11,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r11.u32);
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// stw r8,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r8.u32);
	// bl 0x88096950
	ctx.lr = 0x8824B76C;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824B778"))) PPC_WEAK_FUNC(sub_8824B778);
PPC_FUNC_IMPL(__imp__sub_8824B778) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x8824B780;
	__savegprlr_27(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,56
	ctx.r5.s64 = 56;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x880968b8
	ctx.lr = 0x8824B7A4;
	sub_880968B8(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,30
	ctx.r10.s64 = 30;
	// li r9,8
	ctx.r9.s64 = 8;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lis r7,120
	ctx.r7.s64 = 7864320;
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r11.u32);
	// lis r6,280
	ctx.r6.s64 = 18350080;
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r11.u32);
	// stw r11,32(r27)
	PPC_STORE_U32(ctx.r27.u32 + 32, ctx.r11.u32);
	// lis r4,-30685
	ctx.r4.s64 = -2010972160;
	// stw r11,52(r27)
	PPC_STORE_U32(ctx.r27.u32 + 52, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// addi r4,r4,-19528
	ctx.r4.s64 = ctx.r4.s64 + -19528;
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// stw r9,16(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16, ctx.r9.u32);
	// bl 0x880966a8
	ctx.lr = 0x8824B7FC;
	sub_880966A8(ctx, base);
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lis r3,-30683
	ctx.r3.s64 = -2010841088;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r3,-20872
	ctx.r5.s64 = ctx.r3.s64 + -20872;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,36(r27)
	PPC_STORE_U32(ctx.r27.u32 + 36, ctx.r11.u32);
	// bl 0x88096950
	ctx.lr = 0x8824B818;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824B824"))) PPC_WEAK_FUNC(sub_8824B824);
PPC_FUNC_IMPL(__imp__sub_8824B824) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8824B828"))) PPC_WEAK_FUNC(sub_8824B828);
PPC_FUNC_IMPL(__imp__sub_8824B828) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x8824B830;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,40
	ctx.r5.s64 = 40;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x880968b8
	ctx.lr = 0x8824B850;
	sub_880968B8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r9,-30683
	ctx.r9.s64 = -2010841088;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r9,-20008
	ctx.r5.s64 = ctx.r9.s64 + -20008;
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// stw r8,36(r10)
	PPC_STORE_U32(ctx.r10.u32 + 36, ctx.r8.u32);
	// bl 0x88096950
	ctx.lr = 0x8824B87C;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824B888"))) PPC_WEAK_FUNC(sub_8824B888);
PPC_FUNC_IMPL(__imp__sub_8824B888) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x8824B890;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,88
	ctx.r5.s64 = 88;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x880968b8
	ctx.lr = 0x8824B8B0;
	sub_880968B8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// lis r6,-30671
	ctx.r6.s64 = -2010054656;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// lis r5,16838
	ctx.r5.s64 = 1103495168;
	// stw r11,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, ctx.r11.u32);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// ori r4,r5,20077
	ctx.r4.u64 = ctx.r5.u64 | 20077;
	// li r8,4
	ctx.r8.s64 = 4;
	// lwz r10,4200(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4200);
	// li r9,3
	ctx.r9.s64 = 3;
	// li r3,20
	ctx.r3.s64 = 20;
	// mullw r10,r10,r4
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r4.s32);
	// stw r11,36(r7)
	PPC_STORE_U32(ctx.r7.u32 + 36, ctx.r11.u32);
	// stw r11,48(r7)
	PPC_STORE_U32(ctx.r7.u32 + 48, ctx.r11.u32);
	// stw r11,68(r7)
	PPC_STORE_U32(ctx.r7.u32 + 68, ctx.r11.u32);
	// stw r3,28(r7)
	PPC_STORE_U32(ctx.r7.u32 + 28, ctx.r3.u32);
	// stw r8,40(r7)
	PPC_STORE_U32(ctx.r7.u32 + 40, ctx.r8.u32);
	// stw r8,44(r7)
	PPC_STORE_U32(ctx.r7.u32 + 44, ctx.r8.u32);
	// stw r9,52(r7)
	PPC_STORE_U32(ctx.r7.u32 + 52, ctx.r9.u32);
	// stw r9,60(r7)
	PPC_STORE_U32(ctx.r7.u32 + 60, ctx.r9.u32);
	// addi r10,r10,12345
	ctx.r10.s64 = ctx.r10.s64 + 12345;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r10,4200(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4200, ctx.r10.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// lhz r10,4200(r6)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r6.u32 + 4200);
	// clrlwi r11,r10,31
	ctx.r11.u64 = ctx.r10.u32 & 0x1;
	// stw r5,56(r7)
	PPC_STORE_U32(ctx.r7.u32 + 56, ctx.r5.u32);
	// lis r3,-30683
	ctx.r3.s64 = -2010841088;
	// stw r4,64(r7)
	PPC_STORE_U32(ctx.r7.u32 + 64, ctx.r4.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r11,32(r7)
	PPC_STORE_U32(ctx.r7.u32 + 32, ctx.r11.u32);
	// addi r5,r3,-19632
	ctx.r5.s64 = ctx.r3.s64 + -19632;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,72(r7)
	PPC_STORE_U32(ctx.r7.u32 + 72, ctx.r10.u32);
	// bl 0x88096950
	ctx.lr = 0x8824B948;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824B954"))) PPC_WEAK_FUNC(sub_8824B954);
PPC_FUNC_IMPL(__imp__sub_8824B954) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8824B958"))) PPC_WEAK_FUNC(sub_8824B958);
PPC_FUNC_IMPL(__imp__sub_8824B958) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x8824B960;
	__savegprlr_29(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x8824B97C;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bgt cr6,0x8824babc
	if (ctx.cr6.gt) goto loc_8824BABC;
	// beq cr6,0x8824ba60
	if (ctx.cr6.eq) goto loc_8824BA60;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824b9fc
	if (ctx.cr6.eq) goto loc_8824B9FC;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// bne cr6,0x8824bb78
	if (!ctx.cr6.eq) goto loc_8824BB78;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096710
	ctx.lr = 0x8824B9AC;
	sub_88096710(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8824bb78
	if (!ctx.cr6.eq) goto loc_8824BB78;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824bb78
	if (ctx.cr0.gt) goto loc_8824BB78;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r10,-30683
	ctx.r10.s64 = -2010841088;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-18392
	ctx.r4.s64 = ctx.r10.s64 + -18392;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x880969a8
	ctx.lr = 0x8824B9E0;
	sub_880969A8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// bl 0x88096760
	ctx.lr = 0x8824B9F4;
	sub_88096760(ctx, base);
	// li r8,30
	ctx.r8.s64 = 30;
	// b 0x8824bb6c
	goto loc_8824BB6C;
loc_8824B9FC:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824bb78
	if (ctx.cr0.gt) goto loc_8824BB78;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r10,-30683
	ctx.r10.s64 = -2010841088;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// neg r9,r11
	ctx.r9.s64 = -ctx.r11.s64;
	// addi r4,r10,-18296
	ctx.r4.s64 = ctx.r10.s64 + -18296;
	// stw r9,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r9.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x880969a8
	ctx.lr = 0x8824BA30;
	sub_880969A8(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r8,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r8.u32);
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// bl 0x88096760
	ctx.lr = 0x8824BA44;
	sub_88096760(ctx, base);
	// li r7,20
	ctx.r7.s64 = 20;
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r6,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r6.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_8824BA60:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096710
	ctx.lr = 0x8824BA6C;
	sub_88096710(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8824bb78
	if (!ctx.cr6.eq) goto loc_8824BB78;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824bb78
	if (ctx.cr0.gt) goto loc_8824BB78;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r10,-30683
	ctx.r10.s64 = -2010841088;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-18568
	ctx.r4.s64 = ctx.r10.s64 + -18568;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x880969a8
	ctx.lr = 0x8824BAA0;
	sub_880969A8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// bl 0x88096760
	ctx.lr = 0x8824BAB4;
	sub_88096760(ctx, base);
	// li r8,25
	ctx.r8.s64 = 25;
	// b 0x8824bb6c
	goto loc_8824BB6C;
loc_8824BABC:
	// cmpwi cr6,r11,25
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 25, ctx.xer);
	// beq cr6,0x8824bb14
	if (ctx.cr6.eq) goto loc_8824BB14;
	// cmpwi cr6,r11,30
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 30, ctx.xer);
	// bne cr6,0x8824bb78
	if (!ctx.cr6.eq) goto loc_8824BB78;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096710
	ctx.lr = 0x8824BAD8;
	sub_88096710(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8824bb78
	if (!ctx.cr6.eq) goto loc_8824BB78;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824bb78
	if (ctx.cr0.gt) goto loc_8824BB78;
	// lwz r11,15768(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 15768);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,15768(r29)
	PPC_STORE_U32(ctx.r29.u32 + 15768, ctx.r11.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_8824BB14:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88096710
	ctx.lr = 0x8824BB20;
	sub_88096710(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8824bb78
	if (!ctx.cr6.eq) goto loc_8824BB78;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824bb78
	if (ctx.cr0.gt) goto loc_8824BB78;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r10,-30683
	ctx.r10.s64 = -2010841088;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-18672
	ctx.r4.s64 = ctx.r10.s64 + -18672;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x880969a8
	ctx.lr = 0x8824BB54;
	sub_880969A8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// bl 0x88096760
	ctx.lr = 0x8824BB68;
	sub_88096760(ctx, base);
	// li r8,10
	ctx.r8.s64 = 10;
loc_8824BB6C:
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r8,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// stw r7,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r7.u32);
loc_8824BB78:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824BB84"))) PPC_WEAK_FUNC(sub_8824BB84);
PPC_FUNC_IMPL(__imp__sub_8824BB84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8824BB88"))) PPC_WEAK_FUNC(sub_8824BB88);
PPC_FUNC_IMPL(__imp__sub_8824BB88) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x8824BB90;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880968b8
	ctx.lr = 0x8824BBB0;
	sub_880968B8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// lis r9,120
	ctx.r9.s64 = 7864320;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// lwz r8,8(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x8824bbdc
	if (!ctx.cr6.lt) goto loc_8824BBDC;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
loc_8824BBDC:
	// stw r11,15768(r29)
	PPC_STORE_U32(ctx.r29.u32 + 15768, ctx.r11.u32);
	// lis r11,-30683
	ctx.r11.s64 = -2010841088;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r11,-18088
	ctx.r5.s64 = ctx.r11.s64 + -18088;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096950
	ctx.lr = 0x8824BBF4;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824BC00"))) PPC_WEAK_FUNC(sub_8824BC00);
PPC_FUNC_IMPL(__imp__sub_8824BC00) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x8824BC08;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x8824BC28;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824bd10
	if (ctx.cr6.eq) goto loc_8824BD10;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// beq cr6,0x8824bca0
	if (ctx.cr6.eq) goto loc_8824BCA0;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bne cr6,0x8824bd7c
	if (!ctx.cr6.eq) goto loc_8824BD7C;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824bc74
	if (ctx.cr6.eq) goto loc_8824BC74;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// bgt 0x8824bd7c
	if (ctx.cr0.gt) goto loc_8824BD7C;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824BC74:
	// lis r11,-30683
	ctx.r11.s64 = -2010841088;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-14576
	ctx.r4.s64 = ctx.r11.s64 + -14576;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880969a8
	ctx.lr = 0x8824BC88;
	sub_880969A8(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096830
	ctx.lr = 0x8824BC94;
	sub_88096830(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824BCA0:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x88096e28
	ctx.lr = 0x8824BCAC;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8824bd7c
	if (!ctx.cr6.eq) goto loc_8824BD7C;
	// lis r11,-30706
	ctx.r11.s64 = -2012348416;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,3016
	ctx.r4.s64 = ctx.r11.s64 + 3016;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096cb8
	ctx.lr = 0x8824BCC8;
	sub_88096CB8(ctx, base);
	// lis r10,-30706
	ctx.r10.s64 = -2012348416;
	// li r9,20
	ctx.r9.s64 = 20;
	// li r8,96
	ctx.r8.s64 = 96;
	// addi r7,r10,-16944
	ctx.r7.s64 = ctx.r10.s64 + -16944;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r8,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// lis r5,120
	ctx.r5.s64 = 7864320;
	// lwz r3,5728(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5728);
	// lis r4,360
	ctx.r4.s64 = 23592960;
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// cmpw cr6,r3,r7
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r7.s32, ctx.xer);
	// stw r4,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// beq cr6,0x8824bd7c
	if (ctx.cr6.eq) goto loc_8824BD7C;
	// lis r11,-30706
	ctx.r11.s64 = -2012348416;
	// addi r4,r11,-16944
	ctx.r4.s64 = ctx.r11.s64 + -16944;
	// b 0x8824bd70
	goto loc_8824BD70;
loc_8824BD10:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824bd7c
	if (ctx.cr0.gt) goto loc_8824BD7C;
	// lwz r11,9100(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 9100);
	// lis r10,-30694
	ctx.r10.s64 = -2011561984;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-19216
	ctx.r4.s64 = ctx.r10.s64 + -19216;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x88097078
	ctx.lr = 0x8824BD3C;
	sub_88097078(ctx, base);
	// li r9,10
	ctx.r9.s64 = 10;
	// li r8,96
	ctx.r8.s64 = 96;
	// stw r3,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r3.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// lis r6,120
	ctx.r6.s64 = 7864320;
	// stw r8,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// lis r5,300
	ctx.r5.s64 = 19660800;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// lis r4,-30706
	ctx.r4.s64 = -2012348416;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// stw r5,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// addi r4,r4,-16944
	ctx.r4.s64 = ctx.r4.s64 + -16944;
loc_8824BD70:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x8824BD7C;
	sub_880966A8(ctx, base);
loc_8824BD7C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824BD88"))) PPC_WEAK_FUNC(sub_8824BD88);
PPC_FUNC_IMPL(__imp__sub_8824BD88) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x8824BD90;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x8824BDB0;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824be98
	if (ctx.cr6.eq) goto loc_8824BE98;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// beq cr6,0x8824be28
	if (ctx.cr6.eq) goto loc_8824BE28;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bne cr6,0x8824bf04
	if (!ctx.cr6.eq) goto loc_8824BF04;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824bdfc
	if (ctx.cr6.eq) goto loc_8824BDFC;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// bgt 0x8824bf04
	if (ctx.cr0.gt) goto loc_8824BF04;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824BDFC:
	// lis r11,-30683
	ctx.r11.s64 = -2010841088;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-14576
	ctx.r4.s64 = ctx.r11.s64 + -14576;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880969a8
	ctx.lr = 0x8824BE10;
	sub_880969A8(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096830
	ctx.lr = 0x8824BE1C;
	sub_88096830(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824BE28:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x88096e28
	ctx.lr = 0x8824BE34;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8824bf04
	if (!ctx.cr6.eq) goto loc_8824BF04;
	// lis r11,-30706
	ctx.r11.s64 = -2012348416;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,3016
	ctx.r4.s64 = ctx.r11.s64 + 3016;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096cb8
	ctx.lr = 0x8824BE50;
	sub_88096CB8(ctx, base);
	// lis r10,-30706
	ctx.r10.s64 = -2012348416;
	// li r9,20
	ctx.r9.s64 = 20;
	// li r8,64
	ctx.r8.s64 = 64;
	// addi r7,r10,-16944
	ctx.r7.s64 = ctx.r10.s64 + -16944;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r8,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// lis r5,120
	ctx.r5.s64 = 7864320;
	// lwz r3,5728(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5728);
	// lis r4,360
	ctx.r4.s64 = 23592960;
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// cmpw cr6,r3,r7
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r7.s32, ctx.xer);
	// stw r4,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// beq cr6,0x8824bf04
	if (ctx.cr6.eq) goto loc_8824BF04;
	// lis r11,-30706
	ctx.r11.s64 = -2012348416;
	// addi r4,r11,-16944
	ctx.r4.s64 = ctx.r11.s64 + -16944;
	// b 0x8824bef8
	goto loc_8824BEF8;
loc_8824BE98:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824bf04
	if (ctx.cr0.gt) goto loc_8824BF04;
	// lwz r11,9100(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 9100);
	// lis r10,-30694
	ctx.r10.s64 = -2011561984;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-18928
	ctx.r4.s64 = ctx.r10.s64 + -18928;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x88097078
	ctx.lr = 0x8824BEC4;
	sub_88097078(ctx, base);
	// li r9,10
	ctx.r9.s64 = 10;
	// li r8,96
	ctx.r8.s64 = 96;
	// stw r3,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r3.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// lis r6,120
	ctx.r6.s64 = 7864320;
	// stw r8,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// lis r5,280
	ctx.r5.s64 = 18350080;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// lis r4,-30706
	ctx.r4.s64 = -2012348416;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// stw r5,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// addi r4,r4,-16944
	ctx.r4.s64 = ctx.r4.s64 + -16944;
loc_8824BEF8:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x8824BF04;
	sub_880966A8(ctx, base);
loc_8824BF04:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824BF10"))) PPC_WEAK_FUNC(sub_8824BF10);
PPC_FUNC_IMPL(__imp__sub_8824BF10) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x8824BF18;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,48
	ctx.r5.s64 = 48;
	// bl 0x880968b8
	ctx.lr = 0x8824BF38;
	sub_880968B8(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,2
	ctx.r10.s64 = 2;
	// li r11,64
	ctx.r11.s64 = 64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// li r6,80
	ctx.r6.s64 = 80;
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// li r28,32
	ctx.r28.s64 = 32;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// lis r5,-30683
	ctx.r5.s64 = -2010841088;
	// stw r10,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r10.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r7,28(r8)
	PPC_STORE_U32(ctx.r8.u32 + 28, ctx.r7.u32);
	// addi r5,r5,-17408
	ctx.r5.s64 = ctx.r5.s64 + -17408;
	// stw r6,40(r8)
	PPC_STORE_U32(ctx.r8.u32 + 40, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r28,44(r8)
	PPC_STORE_U32(ctx.r8.u32 + 44, ctx.r28.u32);
	// lwz r11,868(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 868);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,868(r29)
	PPC_STORE_U32(ctx.r29.u32 + 868, ctx.r11.u32);
	// bl 0x88096950
	ctx.lr = 0x8824BF98;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824BFA4"))) PPC_WEAK_FUNC(sub_8824BFA4);
PPC_FUNC_IMPL(__imp__sub_8824BFA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8824BFA8"))) PPC_WEAK_FUNC(sub_8824BFA8);
PPC_FUNC_IMPL(__imp__sub_8824BFA8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x8824BFB0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,48
	ctx.r5.s64 = 48;
	// bl 0x880968b8
	ctx.lr = 0x8824BFD0;
	sub_880968B8(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,2
	ctx.r10.s64 = 2;
	// li r11,64
	ctx.r11.s64 = 64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// li r6,80
	ctx.r6.s64 = 80;
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// li r28,32
	ctx.r28.s64 = 32;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// lis r5,-30683
	ctx.r5.s64 = -2010841088;
	// stw r10,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r10.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r7,28(r8)
	PPC_STORE_U32(ctx.r8.u32 + 28, ctx.r7.u32);
	// addi r5,r5,-17016
	ctx.r5.s64 = ctx.r5.s64 + -17016;
	// stw r6,40(r8)
	PPC_STORE_U32(ctx.r8.u32 + 40, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r28,44(r8)
	PPC_STORE_U32(ctx.r8.u32 + 44, ctx.r28.u32);
	// lwz r11,864(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 864);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,864(r29)
	PPC_STORE_U32(ctx.r29.u32 + 864, ctx.r11.u32);
	// bl 0x88096950
	ctx.lr = 0x8824C030;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824C03C"))) PPC_WEAK_FUNC(sub_8824C03C);
PPC_FUNC_IMPL(__imp__sub_8824C03C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8824C040"))) PPC_WEAK_FUNC(sub_8824C040);
PPC_FUNC_IMPL(__imp__sub_8824C040) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x8824C048;
	__savegprlr_27(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r30,2304(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880968b8
	ctx.lr = 0x8824C06C;
	sub_880968B8(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8824c24c
	if (ctx.cr6.eq) goto loc_8824C24C;
	// cmpwi cr6,r10,10
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 10, ctx.xer);
	// beq cr6,0x8824c144
	if (ctx.cr6.eq) goto loc_8824C144;
	// cmpwi cr6,r10,20
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 20, ctx.xer);
	// bne cr6,0x8824c2c0
	if (!ctx.cr6.eq) goto loc_8824C2C0;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8824c258
	if (!ctx.cr6.eq) goto loc_8824C258;
	// lwz r11,2304(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 2304);
	// li r10,8
	ctx.r10.s64 = 8;
	// li r29,0
	ctx.r29.s64 = 0;
	// lis r9,-30706
	ctx.r9.s64 = -2012348416;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,2064
	ctx.r4.s64 = ctx.r9.s64 + 2064;
	// stw r10,88(r11)
	PPC_STORE_U32(ctx.r11.u32 + 88, ctx.r10.u32);
	// lwz r3,36(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// bl 0x88096cb8
	ctx.lr = 0x8824C0C0;
	sub_88096CB8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x881534c8
	ctx.lr = 0x8824C0C8;
	sub_881534C8(ctx, base);
	// extsh r8,r3
	ctx.r8.s64 = ctx.r3.s16;
	// li r5,0
	ctx.r5.s64 = 0;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// beq cr6,0x8824c110
	if (ctx.cr6.eq) goto loc_8824C110;
	// lwz r11,868(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 868);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// blt cr6,0x8824c11c
	if (ctx.cr6.lt) goto loc_8824C11C;
loc_8824C0E8:
	// lis r11,-30683
	ctx.r11.s64 = -2010841088;
	// addi r4,r11,-16472
	ctx.r4.s64 = ctx.r11.s64 + -16472;
	// bl 0x880969a8
	ctx.lr = 0x8824C0F4;
	sub_880969A8(ctx, base);
	// stw r29,868(r30)
	PPC_STORE_U32(ctx.r30.u32 + 868, ctx.r29.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096830
	ctx.lr = 0x8824C104;
	sub_88096830(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_8824C110:
	// lwz r11,864(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 864);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// blt cr6,0x8824c0e8
	if (ctx.cr6.lt) goto loc_8824C0E8;
loc_8824C11C:
	// lis r11,-30683
	ctx.r11.s64 = -2010841088;
	// addi r4,r11,-16624
	ctx.r4.s64 = ctx.r11.s64 + -16624;
	// bl 0x880969a8
	ctx.lr = 0x8824C128;
	sub_880969A8(ctx, base);
	// stw r29,864(r30)
	PPC_STORE_U32(ctx.r30.u32 + 864, ctx.r29.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096830
	ctx.lr = 0x8824C138;
	sub_88096830(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_8824C144:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8824c1d8
	if (ctx.cr6.eq) goto loc_8824C1D8;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// bgt 0x8824c2c0
	if (ctx.cr0.gt) goto loc_8824C2C0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r29,4
	ctx.r29.s64 = 4;
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// lis r9,-30694
	ctx.r9.s64 = -2011561984;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,-20792
	ctx.r4.s64 = ctx.r9.s64 + -20792;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88097078
	ctx.lr = 0x8824C180;
	sub_88097078(ctx, base);
	// lwz r6,9100(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 9100);
	// lis r8,220
	ctx.r8.s64 = 14417920;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// lis r7,360
	ctx.r7.s64 = 23592960;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// beq cr6,0x8824c1a8
	if (ctx.cr6.eq) goto loc_8824C1A8;
	// lis r11,20
	ctx.r11.s64 = 1310720;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
loc_8824C1A8:
	// lis r11,-30706
	ctx.r11.s64 = -2012348416;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-16944
	ctx.r4.s64 = ctx.r11.s64 + -16944;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880966a8
	ctx.lr = 0x8824C1BC;
	sub_880966A8(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// stw r10,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r9.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_8824C1D8:
	// lwz r10,24(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8824c2c0
	if (!ctx.cr6.eq) goto loc_8824C2C0;
	// li r10,20
	ctx.r10.s64 = 20;
	// li r9,128
	ctx.r9.s64 = 128;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// bl 0x881534c8
	ctx.lr = 0x8824C1FC;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r8,32
	ctx.r8.s64 = 32;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// lis r6,-30706
	ctx.r6.s64 = -2012348416;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r6,-1208
	ctx.r4.s64 = ctx.r6.s64 + -1208;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096cb8
	ctx.lr = 0x8824C224;
	sub_88096CB8(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,-30694
	ctx.r4.s64 = -2011561984;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r4,-18648
	ctx.r4.s64 = ctx.r4.s64 + -18648;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88097078
	ctx.lr = 0x8824C240;
	sub_88097078(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_8824C24C:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8824c278
	if (ctx.cr6.eq) goto loc_8824C278;
loc_8824C258:
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// bgt 0x8824c2c0
	if (ctx.cr0.gt) goto loc_8824C2C0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_8824C278:
	// li r10,10
	ctx.r10.s64 = 10;
	// li r9,64
	ctx.r9.s64 = 64;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// li r29,0
	ctx.r29.s64 = 0;
	// stw r9,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// lis r8,-30706
	ctx.r8.s64 = -2012348416;
	// lwz r7,2304(r28)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r28.u32 + 2304);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,36(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 36);
	// addi r4,r8,2064
	ctx.r4.s64 = ctx.r8.s64 + 2064;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// stw r29,88(r7)
	PPC_STORE_U32(ctx.r7.u32 + 88, ctx.r29.u32);
	// bl 0x88096cb8
	ctx.lr = 0x8824C2AC;
	sub_88096CB8(ctx, base);
	// lis r6,-30706
	ctx.r6.s64 = -2012348416;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,36(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// addi r4,r6,10816
	ctx.r4.s64 = ctx.r6.s64 + 10816;
	// bl 0x88096cb8
	ctx.lr = 0x8824C2C0;
	sub_88096CB8(ctx, base);
loc_8824C2C0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824C2CC"))) PPC_WEAK_FUNC(sub_8824C2CC);
PPC_FUNC_IMPL(__imp__sub_8824C2CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8824C2D0"))) PPC_WEAK_FUNC(sub_8824C2D0);
PPC_FUNC_IMPL(__imp__sub_8824C2D0) {
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
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,20
	ctx.r5.s64 = 20;
	// bl 0x880968b8
	ctx.lr = 0x8824C2FC;
	sub_880968B8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lis r8,-30683
	ctx.r8.s64 = -2010841088;
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r8,-16320
	ctx.r5.s64 = ctx.r8.s64 + -16320;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096950
	ctx.lr = 0x8824C328;
	sub_88096950(ctx, base);
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

__attribute__((alias("__imp__sub_8824C344"))) PPC_WEAK_FUNC(sub_8824C344);
PPC_FUNC_IMPL(__imp__sub_8824C344) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8824C348"))) PPC_WEAK_FUNC(sub_8824C348);
PPC_FUNC_IMPL(__imp__sub_8824C348) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x8824C350;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x8824C370;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,30
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 30, ctx.xer);
	// bgt cr6,0x8824c634
	if (ctx.cr6.gt) goto loc_8824C634;
	// beq cr6,0x8824c560
	if (ctx.cr6.eq) goto loc_8824C560;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824c51c
	if (ctx.cr6.eq) goto loc_8824C51C;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// beq cr6,0x8824c458
	if (ctx.cr6.eq) goto loc_8824C458;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bne cr6,0x8824c704
	if (!ctx.cr6.eq) goto loc_8824C704;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x88096e28
	ctx.lr = 0x8824C3A8;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8824c704
	if (!ctx.cr6.eq) goto loc_8824C704;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r10,10
	ctx.r10.s64 = 10;
	// li r9,96
	ctx.r9.s64 = 96;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// bgt 0x8824c3f0
	if (ctx.cr0.gt) goto loc_8824C3F0;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r11,30
	ctx.r11.s64 = 30;
	// stw r29,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r29,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r29.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824C3F0:
	// lis r11,-30706
	ctx.r11.s64 = -2012348416;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,2912
	ctx.r4.s64 = ctx.r11.s64 + 2912;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096cb8
	ctx.lr = 0x8824C404;
	sub_88096CB8(ctx, base);
	// lis r10,-30706
	ctx.r10.s64 = -2012348416;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,2808
	ctx.r4.s64 = ctx.r10.s64 + 2808;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096cb8
	ctx.lr = 0x8824C418;
	sub_88096CB8(ctx, base);
	// li r9,32
	ctx.r9.s64 = 32;
	// li r8,2
	ctx.r8.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// li r6,8
	ctx.r6.s64 = 8;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// lis r4,-30694
	ctx.r4.s64 = -2011561984;
	// stw r6,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r6.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r4,-19776
	ctx.r4.s64 = ctx.r4.s64 + -19776;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x8824C44C;
	sub_88097078(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824C458:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824c4b0
	if (ctx.cr6.eq) goto loc_8824C4B0;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824c704
	if (ctx.cr0.gt) goto loc_8824C704;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r29,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// bl 0x881534c8
	ctx.lr = 0x8824C480;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// lis r10,-30706
	ctx.r10.s64 = -2012348416;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r4,r10,-1208
	ctx.r4.s64 = ctx.r10.s64 + -1208;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096cb8
	ctx.lr = 0x8824C4A4;
	sub_88096CB8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824C4B0:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// bge 0x8824c704
	if (!ctx.cr0.lt) goto loc_8824C704;
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// li r10,6
	ctx.r10.s64 = 6;
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// li r8,8
	ctx.r8.s64 = 8;
	// lwz r7,20(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lis r6,-30694
	ctx.r6.s64 = -2011561984;
	// stw r10,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r8,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r8.u32);
	// addi r4,r6,-19376
	ctx.r4.s64 = ctx.r6.s64 + -19376;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// stw r7,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r7.u32);
	// bl 0x88097078
	ctx.lr = 0x8824C4FC;
	sub_88097078(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,20
	ctx.r4.s64 = 20;
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// stw r5,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r5.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r4,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r4.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824C51C:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824c704
	if (ctx.cr0.gt) goto loc_8824C704;
	// lis r11,-30694
	ctx.r11.s64 = -2011561984;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-19552
	ctx.r4.s64 = ctx.r11.s64 + -19552;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x8824C540;
	sub_88097078(ctx, base);
	// li r10,10
	ctx.r10.s64 = 10;
	// li r9,24
	ctx.r9.s64 = 24;
	// stw r3,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r3.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824C560:
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// bge 0x8824c704
	if (!ctx.cr0.lt) goto loc_8824C704;
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lis r10,-30706
	ctx.r10.s64 = -2012348416;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,2912
	ctx.r4.s64 = ctx.r10.s64 + 2912;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// bl 0x88096cb8
	ctx.lr = 0x8824C58C;
	sub_88096CB8(ctx, base);
	// lis r9,-30706
	ctx.r9.s64 = -2012348416;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,2808
	ctx.r4.s64 = ctx.r9.s64 + 2808;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096cb8
	ctx.lr = 0x8824C5A0;
	sub_88096CB8(ctx, base);
	// li r11,6
	ctx.r11.s64 = 6;
	// li r8,4
	ctx.r8.s64 = 4;
	// li r29,0
	ctx.r29.s64 = 0;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// lis r7,-30694
	ctx.r7.s64 = -2011561984;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// addi r4,r7,-19776
	ctx.r4.s64 = ctx.r7.s64 + -19776;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x8824C5D0;
	sub_88097078(ctx, base);
	// lis r6,40
	ctx.r6.s64 = 2621440;
	// lis r5,340
	ctx.r5.s64 = 22282240;
	// stw r3,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r3.u32);
	// lwz r4,9100(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + 9100);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// stw r5,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// beq cr6,0x8824c5fc
	if (ctx.cr6.eq) goto loc_8824C5FC;
	// lis r11,200
	ctx.r11.s64 = 13107200;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
loc_8824C5FC:
	// lis r11,-30706
	ctx.r11.s64 = -2012348416;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-16944
	ctx.r4.s64 = ctx.r11.s64 + -16944;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x8824C610;
	sub_880966A8(ctx, base);
	// li r10,40
	ctx.r10.s64 = 40;
	// stw r29,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x88096dd0
	ctx.lr = 0x8824C628;
	sub_88096DD0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824C634:
	// cmpwi cr6,r11,40
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 40, ctx.xer);
	// beq cr6,0x8824c6e0
	if (ctx.cr6.eq) goto loc_8824C6E0;
	// cmpwi cr6,r11,50
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 50, ctx.xer);
	// bne cr6,0x8824c704
	if (!ctx.cr6.eq) goto loc_8824C704;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824c670
	if (ctx.cr6.eq) goto loc_8824C670;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824c704
	if (ctx.cr0.gt) goto loc_8824C704;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824C670:
	// lis r11,-30683
	ctx.r11.s64 = -2010841088;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-15664
	ctx.r4.s64 = ctx.r11.s64 + -15664;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880969a8
	ctx.lr = 0x8824C684;
	sub_880969A8(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,9104(r28)
	PPC_STORE_U32(ctx.r28.u32 + 9104, ctx.r10.u32);
	// bl 0x881534c8
	ctx.lr = 0x8824C694;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// lis r7,-30706
	ctx.r7.s64 = -2012348416;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r7,-1208
	ctx.r4.s64 = ctx.r7.s64 + -1208;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096cb8
	ctx.lr = 0x8824C6BC;
	sub_88096CB8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,40(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// bl 0x88096f00
	ctx.lr = 0x8824C6C8;
	sub_88096F00(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096830
	ctx.lr = 0x8824C6D4;
	sub_88096830(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824C6E0:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,36(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// bl 0x88096e28
	ctx.lr = 0x8824C6EC;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8824c704
	if (!ctx.cr6.eq) goto loc_8824C704;
	// li r11,50
	ctx.r11.s64 = 50;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
loc_8824C704:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824C710"))) PPC_WEAK_FUNC(sub_8824C710);
PPC_FUNC_IMPL(__imp__sub_8824C710) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x8824C718;
	__savegprlr_27(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r27,2304(r3)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r5,52
	ctx.r5.s64 = 52;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x8824C738;
	sub_880968B8(ctx, base);
	// lwz r11,9100(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 9100);
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// li r10,2
	ctx.r10.s64 = 2;
	// clrlwi r8,r11,31
	ctx.r8.u64 = ctx.r11.u32 & 0x1;
	// li r7,32
	ctx.r7.s64 = 32;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r8,9100(r27)
	PPC_STORE_U32(ctx.r27.u32 + 9100, ctx.r8.u32);
	// lis r9,-30706
	ctx.r9.s64 = -2012348416;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r29.u32);
	// li r6,64
	ctx.r6.s64 = 64;
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// li r5,6
	ctx.r5.s64 = 6;
	// stw r7,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r7.u32);
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,16
	ctx.r3.s64 = 16;
	// stw r6,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r6.u32);
	// addi r11,r9,-16944
	ctx.r11.s64 = ctx.r9.s64 + -16944;
	// stw r5,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r5.u32);
	// lis r9,120
	ctx.r9.s64 = 7864320;
	// stw r4,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r4.u32);
	// lis r8,360
	ctx.r8.s64 = 23592960;
	// stw r3,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r3.u32);
	// stw r29,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r29.u32);
	// lwz r7,5728(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5728);
	// cmpw cr6,r7,r11
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r11.s32, ctx.xer);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// beq cr6,0x8824c7c8
	if (ctx.cr6.eq) goto loc_8824C7C8;
	// lis r11,-30706
	ctx.r11.s64 = -2012348416;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-16944
	ctx.r4.s64 = ctx.r11.s64 + -16944;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x8824C7C8;
	sub_880966A8(ctx, base);
loc_8824C7C8:
	// lis r10,-30671
	ctx.r10.s64 = -2010054656;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// lis r9,16838
	ctx.r9.s64 = 1103495168;
	// lis r8,-30706
	ctx.r8.s64 = -2012348416;
	// ori r7,r9,20077
	ctx.r7.u64 = ctx.r9.u64 | 20077;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r11,4200(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4200);
	// addi r4,r8,-1208
	ctx.r4.s64 = ctx.r8.s64 + -1208;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mullw r11,r11,r7
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r7.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// stw r11,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r11.u32);
	// lhz r11,4200(r10)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// addi r6,r11,1
	ctx.r6.s64 = ctx.r11.s64 + 1;
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// bl 0x88096cb8
	ctx.lr = 0x8824C80C;
	sub_88096CB8(ctx, base);
	// lis r4,-30694
	ctx.r4.s64 = -2011561984;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r4,-24320
	ctx.r4.s64 = ctx.r4.s64 + -24320;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x8824C820;
	sub_88097078(ctx, base);
	// stw r3,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r3.u32);
	// lis r3,-30683
	ctx.r3.s64 = -2010841088;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r5,r3,-15544
	ctx.r5.s64 = ctx.r3.s64 + -15544;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096950
	ctx.lr = 0x8824C838;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824C844"))) PPC_WEAK_FUNC(sub_8824C844);
PPC_FUNC_IMPL(__imp__sub_8824C844) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8824C848"))) PPC_WEAK_FUNC(sub_8824C848);
PPC_FUNC_IMPL(__imp__sub_8824C848) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x8824C850;
	__savegprlr_26(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x880968b8
	ctx.lr = 0x8824C874;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824ca60
	if (ctx.cr6.eq) goto loc_8824CA60;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// beq cr6,0x8824c908
	if (ctx.cr6.eq) goto loc_8824C908;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bne cr6,0x8824cad4
	if (!ctx.cr6.eq) goto loc_8824CAD4;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8824ca6c
	if (!ctx.cr6.eq) goto loc_8824CA6C;
	// lwz r11,2304(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 2304);
	// li r10,8
	ctx.r10.s64 = 8;
	// li r30,0
	ctx.r30.s64 = 0;
	// lis r9,-30706
	ctx.r9.s64 = -2012348416;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,2064
	ctx.r4.s64 = ctx.r9.s64 + 2064;
	// stw r10,88(r11)
	PPC_STORE_U32(ctx.r11.u32 + 88, ctx.r10.u32);
	// lwz r3,36(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// bl 0x88096cb8
	ctx.lr = 0x8824C8C8;
	sub_88096CB8(ctx, base);
	// lwz r11,9100(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 9100);
	// stw r30,9104(r29)
	PPC_STORE_U32(ctx.r29.u32 + 9104, ctx.r30.u32);
	// lis r8,-30683
	ctx.r8.s64 = -2010841088;
	// addi r7,r11,-1
	ctx.r7.s64 = ctx.r11.s64 + -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// addi r4,r8,-16624
	ctx.r4.s64 = ctx.r8.s64 + -16624;
	// stw r6,9100(r29)
	PPC_STORE_U32(ctx.r29.u32 + 9100, ctx.r6.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x880969a8
	ctx.lr = 0x8824C8F0;
	sub_880969A8(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x88096830
	ctx.lr = 0x8824C8FC;
	sub_88096830(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_8824C908:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824c9cc
	if (ctx.cr6.eq) goto loc_8824C9CC;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824cad4
	if (ctx.cr0.gt) goto loc_8824CAD4;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r9,-30694
	ctx.r9.s64 = -2011561984;
	// cntlzw r8,r11
	ctx.r8.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// addi r4,r9,-20792
	ctx.r4.s64 = ctx.r9.s64 + -20792;
	// xori r11,r7,1
	ctx.r11.u64 = ctx.r7.u64 ^ 1;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r6,r11,2
	ctx.r6.s64 = ctx.r11.s64 + 2;
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// bl 0x88097078
	ctx.lr = 0x8824C954;
	sub_88097078(ctx, base);
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r5,4
	ctx.r5.s64 = 4;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// beq cr6,0x8824c978
	if (ctx.cr6.eq) goto loc_8824C978;
	// lis r10,400
	ctx.r10.s64 = 26214400;
	// lis r11,120
	ctx.r11.s64 = 7864320;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// b 0x8824c998
	goto loc_8824C998;
loc_8824C978:
	// lwz r11,9100(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 9100);
	// lis r10,220
	ctx.r10.s64 = 14417920;
	// lis r9,360
	ctx.r9.s64 = 23592960;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// beq cr6,0x8824c99c
	if (ctx.cr6.eq) goto loc_8824C99C;
	// lis r11,20
	ctx.r11.s64 = 1310720;
loc_8824C998:
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
loc_8824C99C:
	// lis r11,-30706
	ctx.r11.s64 = -2012348416;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-16944
	ctx.r4.s64 = ctx.r11.s64 + -16944;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x880966a8
	ctx.lr = 0x8824C9B0;
	sub_880966A8(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// stw r10,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r9.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_8824C9CC:
	// lwz r11,24(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8824cad4
	if (!ctx.cr6.eq) goto loc_8824CAD4;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x8824ca14
	if (ctx.cr6.eq) goto loc_8824CA14;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lis r10,-30694
	ctx.r10.s64 = -2011561984;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-18648
	ctx.r4.s64 = ctx.r10.s64 + -18648;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x88097078
	ctx.lr = 0x8824CA00;
	sub_88097078(ctx, base);
	// li r9,20
	ctx.r9.s64 = 20;
	// li r8,128
	ctx.r8.s64 = 128;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// stw r8,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// b 0x8824ca24
	goto loc_8824CA24;
loc_8824CA14:
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stw r30,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// stw r30,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
loc_8824CA24:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x881534c8
	ctx.lr = 0x8824CA2C;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r10,32
	ctx.r10.s64 = 32;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// lis r8,-30706
	ctx.r8.s64 = -2012348416;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,-1208
	ctx.r4.s64 = ctx.r8.s64 + -1208;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x88096cb8
	ctx.lr = 0x8824CA54;
	sub_88096CB8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_8824CA60:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824ca8c
	if (ctx.cr6.eq) goto loc_8824CA8C;
loc_8824CA6C:
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824cad4
	if (ctx.cr0.gt) goto loc_8824CAD4;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_8824CA8C:
	// li r11,10
	ctx.r11.s64 = 10;
	// li r10,64
	ctx.r10.s64 = 64;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// lis r9,-30706
	ctx.r9.s64 = -2012348416;
	// lwz r8,2304(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 2304);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,36(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 36);
	// addi r4,r9,2064
	ctx.r4.s64 = ctx.r9.s64 + 2064;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// stw r30,88(r8)
	PPC_STORE_U32(ctx.r8.u32 + 88, ctx.r30.u32);
	// bl 0x88096cb8
	ctx.lr = 0x8824CAC0;
	sub_88096CB8(ctx, base);
	// lis r7,-30706
	ctx.r7.s64 = -2012348416;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,36(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 36);
	// addi r4,r7,10816
	ctx.r4.s64 = ctx.r7.s64 + 10816;
	// bl 0x88096cb8
	ctx.lr = 0x8824CAD4;
	sub_88096CB8(ctx, base);
loc_8824CAD4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824CAE0"))) PPC_WEAK_FUNC(sub_8824CAE0);
PPC_FUNC_IMPL(__imp__sub_8824CAE0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x8824CAE8;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x8824CB08;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824cbf0
	if (ctx.cr6.eq) goto loc_8824CBF0;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// beq cr6,0x8824cb80
	if (ctx.cr6.eq) goto loc_8824CB80;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bne cr6,0x8824cc5c
	if (!ctx.cr6.eq) goto loc_8824CC5C;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824cb54
	if (ctx.cr6.eq) goto loc_8824CB54;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// bgt 0x8824cc5c
	if (ctx.cr0.gt) goto loc_8824CC5C;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824CB54:
	// lis r11,-30683
	ctx.r11.s64 = -2010841088;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-11424
	ctx.r4.s64 = ctx.r11.s64 + -11424;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880969a8
	ctx.lr = 0x8824CB68;
	sub_880969A8(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096830
	ctx.lr = 0x8824CB74;
	sub_88096830(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824CB80:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x88096e28
	ctx.lr = 0x8824CB8C;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8824cc5c
	if (!ctx.cr6.eq) goto loc_8824CC5C;
	// lis r11,-30706
	ctx.r11.s64 = -2012348416;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,3016
	ctx.r4.s64 = ctx.r11.s64 + 3016;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096cb8
	ctx.lr = 0x8824CBA8;
	sub_88096CB8(ctx, base);
	// lis r10,-30706
	ctx.r10.s64 = -2012348416;
	// li r9,20
	ctx.r9.s64 = 20;
	// li r8,192
	ctx.r8.s64 = 192;
	// addi r7,r10,-16944
	ctx.r7.s64 = ctx.r10.s64 + -16944;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r8,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// lis r5,120
	ctx.r5.s64 = 7864320;
	// lwz r3,5728(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5728);
	// lis r4,360
	ctx.r4.s64 = 23592960;
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// cmpw cr6,r3,r7
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r7.s32, ctx.xer);
	// stw r4,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// beq cr6,0x8824cc5c
	if (ctx.cr6.eq) goto loc_8824CC5C;
	// lis r11,-30706
	ctx.r11.s64 = -2012348416;
	// addi r4,r11,-16944
	ctx.r4.s64 = ctx.r11.s64 + -16944;
	// b 0x8824cc50
	goto loc_8824CC50;
loc_8824CBF0:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824cc5c
	if (ctx.cr0.gt) goto loc_8824CC5C;
	// lwz r11,9100(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 9100);
	// lis r10,-30686
	ctx.r10.s64 = -2011037696;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,21232
	ctx.r4.s64 = ctx.r10.s64 + 21232;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x88097078
	ctx.lr = 0x8824CC1C;
	sub_88097078(ctx, base);
	// li r9,10
	ctx.r9.s64 = 10;
	// li r8,96
	ctx.r8.s64 = 96;
	// stw r3,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r3.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// lis r6,120
	ctx.r6.s64 = 7864320;
	// stw r8,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// lis r5,300
	ctx.r5.s64 = 19660800;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// lis r4,-30706
	ctx.r4.s64 = -2012348416;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// stw r5,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// addi r4,r4,-16944
	ctx.r4.s64 = ctx.r4.s64 + -16944;
loc_8824CC50:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x8824CC5C;
	sub_880966A8(ctx, base);
loc_8824CC5C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824CC68"))) PPC_WEAK_FUNC(sub_8824CC68);
PPC_FUNC_IMPL(__imp__sub_8824CC68) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x8824CC70;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,48
	ctx.r5.s64 = 48;
	// bl 0x880968b8
	ctx.lr = 0x8824CC8C;
	sub_880968B8(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,2
	ctx.r10.s64 = 2;
	// li r11,64
	ctx.r11.s64 = 64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// li r6,80
	ctx.r6.s64 = 80;
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// li r29,32
	ctx.r29.s64 = 32;
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// lis r5,-30683
	ctx.r5.s64 = -2010841088;
	// stw r10,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r10.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r7,28(r8)
	PPC_STORE_U32(ctx.r8.u32 + 28, ctx.r7.u32);
	// addi r5,r5,-13600
	ctx.r5.s64 = ctx.r5.s64 + -13600;
	// stw r6,40(r8)
	PPC_STORE_U32(ctx.r8.u32 + 40, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r29,44(r8)
	PPC_STORE_U32(ctx.r8.u32 + 44, ctx.r29.u32);
	// bl 0x88096950
	ctx.lr = 0x8824CCE0;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824CCEC"))) PPC_WEAK_FUNC(sub_8824CCEC);
PPC_FUNC_IMPL(__imp__sub_8824CCEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8824CCF0"))) PPC_WEAK_FUNC(sub_8824CCF0);
PPC_FUNC_IMPL(__imp__sub_8824CCF0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x8824CCF8;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880968b8
	ctx.lr = 0x8824CD1C;
	sub_880968B8(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8824cea8
	if (ctx.cr6.eq) goto loc_8824CEA8;
	// cmpwi cr6,r10,10
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 10, ctx.xer);
	// beq cr6,0x8824cd9c
	if (ctx.cr6.eq) goto loc_8824CD9C;
	// cmpwi cr6,r10,20
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 20, ctx.xer);
	// bne cr6,0x8824cf1c
	if (!ctx.cr6.eq) goto loc_8824CF1C;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8824ceb4
	if (!ctx.cr6.eq) goto loc_8824CEB4;
	// lwz r11,2304(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2304);
	// li r10,8
	ctx.r10.s64 = 8;
	// li r9,0
	ctx.r9.s64 = 0;
	// lis r8,-30706
	ctx.r8.s64 = -2012348416;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,2064
	ctx.r4.s64 = ctx.r8.s64 + 2064;
	// stw r10,88(r11)
	PPC_STORE_U32(ctx.r11.u32 + 88, ctx.r10.u32);
	// lwz r3,36(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// bl 0x88096cb8
	ctx.lr = 0x8824CD70;
	sub_88096CB8(ctx, base);
	// lis r7,-30683
	ctx.r7.s64 = -2010841088;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r7,-13208
	ctx.r4.s64 = ctx.r7.s64 + -13208;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880969a8
	ctx.lr = 0x8824CD84;
	sub_880969A8(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096830
	ctx.lr = 0x8824CD90;
	sub_88096830(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824CD9C:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8824ce34
	if (ctx.cr6.eq) goto loc_8824CE34;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// bgt 0x8824cf1c
	if (ctx.cr0.gt) goto loc_8824CF1C;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// lis r8,-30686
	ctx.r8.s64 = -2011037696;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,20264
	ctx.r4.s64 = ctx.r8.s64 + 20264;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88097078
	ctx.lr = 0x8824CDD8;
	sub_88097078(ctx, base);
	// lwz r4,9100(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + 9100);
	// li r7,4
	ctx.r7.s64 = 4;
	// lis r6,220
	ctx.r6.s64 = 14417920;
	// lis r5,360
	ctx.r5.s64 = 23592960;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// stw r5,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// beq cr6,0x8824ce04
	if (ctx.cr6.eq) goto loc_8824CE04;
	// lis r11,20
	ctx.r11.s64 = 1310720;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
loc_8824CE04:
	// lis r11,-30706
	ctx.r11.s64 = -2012348416;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-16944
	ctx.r4.s64 = ctx.r11.s64 + -16944;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880966a8
	ctx.lr = 0x8824CE18;
	sub_880966A8(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// stw r10,24(r28)
	PPC_STORE_U32(ctx.r28.u32 + 24, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,20(r28)
	PPC_STORE_U32(ctx.r28.u32 + 20, ctx.r9.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824CE34:
	// lwz r10,24(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8824cf1c
	if (!ctx.cr6.eq) goto loc_8824CF1C;
	// li r10,20
	ctx.r10.s64 = 20;
	// li r9,128
	ctx.r9.s64 = 128;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// bl 0x881534c8
	ctx.lr = 0x8824CE58;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r8,32
	ctx.r8.s64 = 32;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// lis r6,-30706
	ctx.r6.s64 = -2012348416;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r6,-1208
	ctx.r4.s64 = ctx.r6.s64 + -1208;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096cb8
	ctx.lr = 0x8824CE80;
	sub_88096CB8(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,-30686
	ctx.r4.s64 = -2011037696;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r4,21528
	ctx.r4.s64 = ctx.r4.s64 + 21528;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88097078
	ctx.lr = 0x8824CE9C;
	sub_88097078(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824CEA8:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8824ced4
	if (ctx.cr6.eq) goto loc_8824CED4;
loc_8824CEB4:
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// bgt 0x8824cf1c
	if (ctx.cr0.gt) goto loc_8824CF1C;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824CED4:
	// li r10,10
	ctx.r10.s64 = 10;
	// li r9,64
	ctx.r9.s64 = 64;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r9,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// lis r8,-30706
	ctx.r8.s64 = -2012348416;
	// lwz r7,2304(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2304);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,36(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 36);
	// addi r4,r8,2064
	ctx.r4.s64 = ctx.r8.s64 + 2064;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stw r10,88(r7)
	PPC_STORE_U32(ctx.r7.u32 + 88, ctx.r10.u32);
	// bl 0x88096cb8
	ctx.lr = 0x8824CF08;
	sub_88096CB8(ctx, base);
	// lis r6,-30706
	ctx.r6.s64 = -2012348416;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,36(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 36);
	// addi r4,r6,10816
	ctx.r4.s64 = ctx.r6.s64 + 10816;
	// bl 0x88096cb8
	ctx.lr = 0x8824CF1C;
	sub_88096CB8(ctx, base);
loc_8824CF1C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824CF28"))) PPC_WEAK_FUNC(sub_8824CF28);
PPC_FUNC_IMPL(__imp__sub_8824CF28) {
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
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,12
	ctx.r5.s64 = 12;
	// bl 0x880968b8
	ctx.lr = 0x8824CF54;
	sub_880968B8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lis r8,-30683
	ctx.r8.s64 = -2010841088;
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r8,-13072
	ctx.r5.s64 = ctx.r8.s64 + -13072;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096950
	ctx.lr = 0x8824CF80;
	sub_88096950(ctx, base);
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

__attribute__((alias("__imp__sub_8824CF9C"))) PPC_WEAK_FUNC(sub_8824CF9C);
PPC_FUNC_IMPL(__imp__sub_8824CF9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8824CFA0"))) PPC_WEAK_FUNC(sub_8824CFA0);
PPC_FUNC_IMPL(__imp__sub_8824CFA0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x8824CFA8;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x8824CFC8;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,30
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 30, ctx.xer);
	// bgt cr6,0x8824d28c
	if (ctx.cr6.gt) goto loc_8824D28C;
	// beq cr6,0x8824d1b8
	if (ctx.cr6.eq) goto loc_8824D1B8;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824d174
	if (ctx.cr6.eq) goto loc_8824D174;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// beq cr6,0x8824d0b0
	if (ctx.cr6.eq) goto loc_8824D0B0;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bne cr6,0x8824d350
	if (!ctx.cr6.eq) goto loc_8824D350;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x88096e28
	ctx.lr = 0x8824D000;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8824d350
	if (!ctx.cr6.eq) goto loc_8824D350;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r10,10
	ctx.r10.s64 = 10;
	// li r9,96
	ctx.r9.s64 = 96;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// bgt 0x8824d048
	if (ctx.cr0.gt) goto loc_8824D048;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r11,30
	ctx.r11.s64 = 30;
	// stw r29,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r29,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r29.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824D048:
	// lis r11,-30706
	ctx.r11.s64 = -2012348416;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,2912
	ctx.r4.s64 = ctx.r11.s64 + 2912;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096cb8
	ctx.lr = 0x8824D05C;
	sub_88096CB8(ctx, base);
	// lis r10,-30706
	ctx.r10.s64 = -2012348416;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,2808
	ctx.r4.s64 = ctx.r10.s64 + 2808;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096cb8
	ctx.lr = 0x8824D070;
	sub_88096CB8(ctx, base);
	// li r9,32
	ctx.r9.s64 = 32;
	// li r8,2
	ctx.r8.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// li r6,8
	ctx.r6.s64 = 8;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// lis r4,-30686
	ctx.r4.s64 = -2011037696;
	// stw r6,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r6.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r4,20680
	ctx.r4.s64 = ctx.r4.s64 + 20680;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x8824D0A4;
	sub_88097078(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824D0B0:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824d108
	if (ctx.cr6.eq) goto loc_8824D108;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824d350
	if (ctx.cr0.gt) goto loc_8824D350;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r29,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// bl 0x881534c8
	ctx.lr = 0x8824D0D8;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// lis r10,-30706
	ctx.r10.s64 = -2012348416;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r4,r10,-1208
	ctx.r4.s64 = ctx.r10.s64 + -1208;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096cb8
	ctx.lr = 0x8824D0FC;
	sub_88096CB8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824D108:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// bge 0x8824d350
	if (!ctx.cr0.lt) goto loc_8824D350;
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// li r10,4
	ctx.r10.s64 = 4;
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// li r8,12
	ctx.r8.s64 = 12;
	// lwz r7,20(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lis r6,-30686
	ctx.r6.s64 = -2011037696;
	// stw r10,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r8,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r8.u32);
	// addi r4,r6,21072
	ctx.r4.s64 = ctx.r6.s64 + 21072;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// stw r7,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r7.u32);
	// bl 0x88097078
	ctx.lr = 0x8824D154;
	sub_88097078(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,20
	ctx.r4.s64 = 20;
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// stw r5,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r5.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r4,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r4.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824D174:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824d350
	if (ctx.cr0.gt) goto loc_8824D350;
	// lis r11,-30686
	ctx.r11.s64 = -2011037696;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,20904
	ctx.r4.s64 = ctx.r11.s64 + 20904;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x8824D198;
	sub_88097078(ctx, base);
	// li r10,10
	ctx.r10.s64 = 10;
	// li r9,24
	ctx.r9.s64 = 24;
	// stw r3,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r3.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824D1B8:
	// lwz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// bge 0x8824d350
	if (!ctx.cr0.lt) goto loc_8824D350;
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// lis r10,-30706
	ctx.r10.s64 = -2012348416;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,2912
	ctx.r4.s64 = ctx.r10.s64 + 2912;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// bl 0x88096cb8
	ctx.lr = 0x8824D1E4;
	sub_88096CB8(ctx, base);
	// lis r9,-30706
	ctx.r9.s64 = -2012348416;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,2808
	ctx.r4.s64 = ctx.r9.s64 + 2808;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096cb8
	ctx.lr = 0x8824D1F8;
	sub_88096CB8(ctx, base);
	// li r11,6
	ctx.r11.s64 = 6;
	// li r8,4
	ctx.r8.s64 = 4;
	// li r29,0
	ctx.r29.s64 = 0;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// lis r7,-30686
	ctx.r7.s64 = -2011037696;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// addi r4,r7,20680
	ctx.r4.s64 = ctx.r7.s64 + 20680;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x8824D228;
	sub_88097078(ctx, base);
	// lis r6,40
	ctx.r6.s64 = 2621440;
	// lis r5,340
	ctx.r5.s64 = 22282240;
	// stw r3,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r3.u32);
	// lwz r4,9100(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + 9100);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// stw r5,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// beq cr6,0x8824d254
	if (ctx.cr6.eq) goto loc_8824D254;
	// lis r11,200
	ctx.r11.s64 = 13107200;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
loc_8824D254:
	// lis r11,-30706
	ctx.r11.s64 = -2012348416;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-16944
	ctx.r4.s64 = ctx.r11.s64 + -16944;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x8824D268;
	sub_880966A8(ctx, base);
	// li r10,40
	ctx.r10.s64 = 40;
	// stw r29,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x88096dd0
	ctx.lr = 0x8824D280;
	sub_88096DD0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824D28C:
	// cmpwi cr6,r11,40
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 40, ctx.xer);
	// beq cr6,0x8824d32c
	if (ctx.cr6.eq) goto loc_8824D32C;
	// cmpwi cr6,r11,50
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 50, ctx.xer);
	// bne cr6,0x8824d350
	if (!ctx.cr6.eq) goto loc_8824D350;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824d2c8
	if (ctx.cr6.eq) goto loc_8824D2C8;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824d350
	if (ctx.cr0.gt) goto loc_8824D350;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824D2C8:
	// lis r11,-30683
	ctx.r11.s64 = -2010841088;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-12504
	ctx.r4.s64 = ctx.r11.s64 + -12504;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880969a8
	ctx.lr = 0x8824D2DC;
	sub_880969A8(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,9104(r28)
	PPC_STORE_U32(ctx.r28.u32 + 9104, ctx.r10.u32);
	// bl 0x881534c8
	ctx.lr = 0x8824D2EC;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// lis r7,-30706
	ctx.r7.s64 = -2012348416;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r7,-1208
	ctx.r4.s64 = ctx.r7.s64 + -1208;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096cb8
	ctx.lr = 0x8824D314;
	sub_88096CB8(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096830
	ctx.lr = 0x8824D320;
	sub_88096830(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824D32C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,36(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// bl 0x88096e28
	ctx.lr = 0x8824D338;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8824d350
	if (!ctx.cr6.eq) goto loc_8824D350;
	// li r11,50
	ctx.r11.s64 = 50;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
loc_8824D350:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824D35C"))) PPC_WEAK_FUNC(sub_8824D35C);
PPC_FUNC_IMPL(__imp__sub_8824D35C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8824D360"))) PPC_WEAK_FUNC(sub_8824D360);
PPC_FUNC_IMPL(__imp__sub_8824D360) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x8824D368;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,48
	ctx.r5.s64 = 48;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880968b8
	ctx.lr = 0x8824D388;
	sub_880968B8(ctx, base);
	// lwz r10,9100(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 9100);
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r11,r10,-1
	ctx.r11.s64 = ctx.r10.s64 + -1;
	// lis r10,-30706
	ctx.r10.s64 = -2012348416;
	// clrlwi r9,r11,31
	ctx.r9.u64 = ctx.r11.u32 & 0x1;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r9,9100(r28)
	PPC_STORE_U32(ctx.r28.u32 + 9100, ctx.r9.u32);
	// li r9,16
	ctx.r9.s64 = 16;
	// li r8,32
	ctx.r8.s64 = 32;
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// li r7,64
	ctx.r7.s64 = 64;
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
	// addi r6,r10,-16944
	ctx.r6.s64 = ctx.r10.s64 + -16944;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// lis r5,120
	ctx.r5.s64 = 7864320;
	// stw r8,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r8.u32);
	// lis r4,360
	ctx.r4.s64 = 23592960;
	// stw r7,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r7.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// stw r9,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r9.u32);
	// stw r9,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r9.u32);
	// stw r30,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r30.u32);
	// lwz r3,5728(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5728);
	// cmpw cr6,r3,r6
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r6.s32, ctx.xer);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// stw r4,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// beq cr6,0x8824d40c
	if (ctx.cr6.eq) goto loc_8824D40C;
	// lis r11,-30706
	ctx.r11.s64 = -2012348416;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-16944
	ctx.r4.s64 = ctx.r11.s64 + -16944;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880966a8
	ctx.lr = 0x8824D40C;
	sub_880966A8(ctx, base);
loc_8824D40C:
	// lis r10,-30671
	ctx.r10.s64 = -2010054656;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// lis r9,16838
	ctx.r9.s64 = 1103495168;
	// lis r8,-30706
	ctx.r8.s64 = -2012348416;
	// ori r7,r9,20077
	ctx.r7.u64 = ctx.r9.u64 | 20077;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r11,4200(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4200);
	// addi r4,r8,-1208
	ctx.r4.s64 = ctx.r8.s64 + -1208;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mullw r11,r11,r7
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r7.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// stw r11,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r11.u32);
	// lhz r11,4200(r10)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// addi r6,r11,1
	ctx.r6.s64 = ctx.r11.s64 + 1;
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// bl 0x88096cb8
	ctx.lr = 0x8824D450;
	sub_88096CB8(ctx, base);
	// lis r5,-30683
	ctx.r5.s64 = -2010841088;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r5,r5,-12384
	ctx.r5.s64 = ctx.r5.s64 + -12384;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096950
	ctx.lr = 0x8824D464;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824D470"))) PPC_WEAK_FUNC(sub_8824D470);
PPC_FUNC_IMPL(__imp__sub_8824D470) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x8824D478;
	__savegprlr_26(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x880968b8
	ctx.lr = 0x8824D49C;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824d688
	if (ctx.cr6.eq) goto loc_8824D688;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// beq cr6,0x8824d530
	if (ctx.cr6.eq) goto loc_8824D530;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bne cr6,0x8824d6fc
	if (!ctx.cr6.eq) goto loc_8824D6FC;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8824d694
	if (!ctx.cr6.eq) goto loc_8824D694;
	// lwz r11,2304(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 2304);
	// li r10,8
	ctx.r10.s64 = 8;
	// li r30,0
	ctx.r30.s64 = 0;
	// lis r9,-30706
	ctx.r9.s64 = -2012348416;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,2064
	ctx.r4.s64 = ctx.r9.s64 + 2064;
	// stw r10,88(r11)
	PPC_STORE_U32(ctx.r11.u32 + 88, ctx.r10.u32);
	// lwz r3,36(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// bl 0x88096cb8
	ctx.lr = 0x8824D4F0;
	sub_88096CB8(ctx, base);
	// lwz r11,9100(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 9100);
	// stw r30,9104(r29)
	PPC_STORE_U32(ctx.r29.u32 + 9104, ctx.r30.u32);
	// lis r8,-30683
	ctx.r8.s64 = -2010841088;
	// addi r7,r11,-1
	ctx.r7.s64 = ctx.r11.s64 + -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// addi r4,r8,-13208
	ctx.r4.s64 = ctx.r8.s64 + -13208;
	// stw r6,9100(r29)
	PPC_STORE_U32(ctx.r29.u32 + 9100, ctx.r6.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x880969a8
	ctx.lr = 0x8824D518;
	sub_880969A8(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x88096830
	ctx.lr = 0x8824D524;
	sub_88096830(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_8824D530:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824d5f4
	if (ctx.cr6.eq) goto loc_8824D5F4;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824d6fc
	if (ctx.cr0.gt) goto loc_8824D6FC;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r9,-30686
	ctx.r9.s64 = -2011037696;
	// cntlzw r8,r11
	ctx.r8.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// addi r4,r9,20264
	ctx.r4.s64 = ctx.r9.s64 + 20264;
	// xori r11,r7,1
	ctx.r11.u64 = ctx.r7.u64 ^ 1;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r6,r11,2
	ctx.r6.s64 = ctx.r11.s64 + 2;
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// bl 0x88097078
	ctx.lr = 0x8824D57C;
	sub_88097078(ctx, base);
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r5,4
	ctx.r5.s64 = 4;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// beq cr6,0x8824d5a0
	if (ctx.cr6.eq) goto loc_8824D5A0;
	// lis r10,400
	ctx.r10.s64 = 26214400;
	// lis r11,120
	ctx.r11.s64 = 7864320;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// b 0x8824d5c0
	goto loc_8824D5C0;
loc_8824D5A0:
	// lwz r11,9100(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 9100);
	// lis r10,220
	ctx.r10.s64 = 14417920;
	// lis r9,360
	ctx.r9.s64 = 23592960;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// beq cr6,0x8824d5c4
	if (ctx.cr6.eq) goto loc_8824D5C4;
	// lis r11,20
	ctx.r11.s64 = 1310720;
loc_8824D5C0:
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
loc_8824D5C4:
	// lis r11,-30706
	ctx.r11.s64 = -2012348416;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-16944
	ctx.r4.s64 = ctx.r11.s64 + -16944;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x880966a8
	ctx.lr = 0x8824D5D8;
	sub_880966A8(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// stw r10,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r9.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_8824D5F4:
	// lwz r11,24(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8824d6fc
	if (!ctx.cr6.eq) goto loc_8824D6FC;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x8824d63c
	if (ctx.cr6.eq) goto loc_8824D63C;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lis r10,-30686
	ctx.r10.s64 = -2011037696;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,21528
	ctx.r4.s64 = ctx.r10.s64 + 21528;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x88097078
	ctx.lr = 0x8824D628;
	sub_88097078(ctx, base);
	// li r9,20
	ctx.r9.s64 = 20;
	// li r8,128
	ctx.r8.s64 = 128;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// stw r8,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// b 0x8824d64c
	goto loc_8824D64C;
loc_8824D63C:
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stw r30,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// stw r30,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
loc_8824D64C:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x881534c8
	ctx.lr = 0x8824D654;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r10,32
	ctx.r10.s64 = 32;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// lis r8,-30706
	ctx.r8.s64 = -2012348416;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,-1208
	ctx.r4.s64 = ctx.r8.s64 + -1208;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x88096cb8
	ctx.lr = 0x8824D67C;
	sub_88096CB8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_8824D688:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824d6b4
	if (ctx.cr6.eq) goto loc_8824D6B4;
loc_8824D694:
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824d6fc
	if (ctx.cr0.gt) goto loc_8824D6FC;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_8824D6B4:
	// li r11,10
	ctx.r11.s64 = 10;
	// li r10,64
	ctx.r10.s64 = 64;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// lis r9,-30706
	ctx.r9.s64 = -2012348416;
	// lwz r8,2304(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 2304);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,36(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 36);
	// addi r4,r9,2064
	ctx.r4.s64 = ctx.r9.s64 + 2064;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// stw r30,88(r8)
	PPC_STORE_U32(ctx.r8.u32 + 88, ctx.r30.u32);
	// bl 0x88096cb8
	ctx.lr = 0x8824D6E8;
	sub_88096CB8(ctx, base);
	// lis r7,-30706
	ctx.r7.s64 = -2012348416;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,36(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 36);
	// addi r4,r7,10816
	ctx.r4.s64 = ctx.r7.s64 + 10816;
	// bl 0x88096cb8
	ctx.lr = 0x8824D6FC;
	sub_88096CB8(ctx, base);
loc_8824D6FC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824D708"))) PPC_WEAK_FUNC(sub_8824D708);
PPC_FUNC_IMPL(__imp__sub_8824D708) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x8824D710;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x8824D730;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824d818
	if (ctx.cr6.eq) goto loc_8824D818;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// beq cr6,0x8824d7a8
	if (ctx.cr6.eq) goto loc_8824D7A8;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bne cr6,0x8824d884
	if (!ctx.cr6.eq) goto loc_8824D884;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824d77c
	if (ctx.cr6.eq) goto loc_8824D77C;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// bgt 0x8824d884
	if (ctx.cr0.gt) goto loc_8824D884;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824D77C:
	// lis r11,-30683
	ctx.r11.s64 = -2010841088;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-11424
	ctx.r4.s64 = ctx.r11.s64 + -11424;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880969a8
	ctx.lr = 0x8824D790;
	sub_880969A8(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096830
	ctx.lr = 0x8824D79C;
	sub_88096830(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824D7A8:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x88096e28
	ctx.lr = 0x8824D7B4;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8824d884
	if (!ctx.cr6.eq) goto loc_8824D884;
	// lis r11,-30706
	ctx.r11.s64 = -2012348416;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,3016
	ctx.r4.s64 = ctx.r11.s64 + 3016;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096cb8
	ctx.lr = 0x8824D7D0;
	sub_88096CB8(ctx, base);
	// lis r10,-30706
	ctx.r10.s64 = -2012348416;
	// li r9,20
	ctx.r9.s64 = 20;
	// li r8,128
	ctx.r8.s64 = 128;
	// addi r7,r10,-16944
	ctx.r7.s64 = ctx.r10.s64 + -16944;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r8,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// lis r5,120
	ctx.r5.s64 = 7864320;
	// lwz r3,5728(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5728);
	// lis r4,360
	ctx.r4.s64 = 23592960;
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// cmpw cr6,r3,r7
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r7.s32, ctx.xer);
	// stw r4,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// beq cr6,0x8824d884
	if (ctx.cr6.eq) goto loc_8824D884;
	// lis r11,-30706
	ctx.r11.s64 = -2012348416;
	// addi r4,r11,-16944
	ctx.r4.s64 = ctx.r11.s64 + -16944;
	// b 0x8824d878
	goto loc_8824D878;
loc_8824D818:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824d884
	if (ctx.cr0.gt) goto loc_8824D884;
	// lwz r11,9100(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 9100);
	// lis r10,-30686
	ctx.r10.s64 = -2011037696;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,22328
	ctx.r4.s64 = ctx.r10.s64 + 22328;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x88097078
	ctx.lr = 0x8824D844;
	sub_88097078(ctx, base);
	// li r9,10
	ctx.r9.s64 = 10;
	// li r8,96
	ctx.r8.s64 = 96;
	// stw r3,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r3.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// lis r6,120
	ctx.r6.s64 = 7864320;
	// stw r8,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// lis r5,280
	ctx.r5.s64 = 18350080;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// lis r4,-30706
	ctx.r4.s64 = -2012348416;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// stw r5,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// addi r4,r4,-16944
	ctx.r4.s64 = ctx.r4.s64 + -16944;
loc_8824D878:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x8824D884;
	sub_880966A8(ctx, base);
loc_8824D884:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824D890"))) PPC_WEAK_FUNC(sub_8824D890);
PPC_FUNC_IMPL(__imp__sub_8824D890) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x8824D898;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x8824D8B8;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824d9a0
	if (ctx.cr6.eq) goto loc_8824D9A0;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// beq cr6,0x8824d930
	if (ctx.cr6.eq) goto loc_8824D930;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bne cr6,0x8824da0c
	if (!ctx.cr6.eq) goto loc_8824DA0C;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824d904
	if (ctx.cr6.eq) goto loc_8824D904;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// bgt 0x8824da0c
	if (ctx.cr0.gt) goto loc_8824DA0C;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824D904:
	// lis r11,-30683
	ctx.r11.s64 = -2010841088;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-7944
	ctx.r4.s64 = ctx.r11.s64 + -7944;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880969a8
	ctx.lr = 0x8824D918;
	sub_880969A8(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096830
	ctx.lr = 0x8824D924;
	sub_88096830(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824D930:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x88096e28
	ctx.lr = 0x8824D93C;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8824da0c
	if (!ctx.cr6.eq) goto loc_8824DA0C;
	// lis r11,-30706
	ctx.r11.s64 = -2012348416;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,3016
	ctx.r4.s64 = ctx.r11.s64 + 3016;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096cb8
	ctx.lr = 0x8824D958;
	sub_88096CB8(ctx, base);
	// lis r10,-30706
	ctx.r10.s64 = -2012348416;
	// li r9,20
	ctx.r9.s64 = 20;
	// li r8,128
	ctx.r8.s64 = 128;
	// addi r7,r10,-16944
	ctx.r7.s64 = ctx.r10.s64 + -16944;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r8,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// lis r5,120
	ctx.r5.s64 = 7864320;
	// lwz r3,5728(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5728);
	// lis r4,360
	ctx.r4.s64 = 23592960;
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// cmpw cr6,r3,r7
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r7.s32, ctx.xer);
	// stw r4,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// beq cr6,0x8824da0c
	if (ctx.cr6.eq) goto loc_8824DA0C;
	// lis r11,-30706
	ctx.r11.s64 = -2012348416;
	// addi r4,r11,-16944
	ctx.r4.s64 = ctx.r11.s64 + -16944;
	// b 0x8824da00
	goto loc_8824DA00;
loc_8824D9A0:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824da0c
	if (ctx.cr0.gt) goto loc_8824DA0C;
	// lwz r11,9100(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 9100);
	// lis r10,-30686
	ctx.r10.s64 = -2011037696;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,26088
	ctx.r4.s64 = ctx.r10.s64 + 26088;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x88097078
	ctx.lr = 0x8824D9CC;
	sub_88097078(ctx, base);
	// li r9,10
	ctx.r9.s64 = 10;
	// li r8,96
	ctx.r8.s64 = 96;
	// stw r3,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r3.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// lis r6,120
	ctx.r6.s64 = 7864320;
	// stw r8,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// lis r5,280
	ctx.r5.s64 = 18350080;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// lis r4,-30706
	ctx.r4.s64 = -2012348416;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// stw r5,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// addi r4,r4,-16944
	ctx.r4.s64 = ctx.r4.s64 + -16944;
loc_8824DA00:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x8824DA0C;
	sub_880966A8(ctx, base);
loc_8824DA0C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824DA18"))) PPC_WEAK_FUNC(sub_8824DA18);
PPC_FUNC_IMPL(__imp__sub_8824DA18) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x8824DA20;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,48
	ctx.r5.s64 = 48;
	// bl 0x880968b8
	ctx.lr = 0x8824DA3C;
	sub_880968B8(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,2
	ctx.r10.s64 = 2;
	// li r11,64
	ctx.r11.s64 = 64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// li r6,80
	ctx.r6.s64 = 80;
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// li r29,32
	ctx.r29.s64 = 32;
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// lis r5,-30683
	ctx.r5.s64 = -2010841088;
	// stw r10,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r10.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r7,28(r8)
	PPC_STORE_U32(ctx.r8.u32 + 28, ctx.r7.u32);
	// addi r5,r5,-10096
	ctx.r5.s64 = ctx.r5.s64 + -10096;
	// stw r6,40(r8)
	PPC_STORE_U32(ctx.r8.u32 + 40, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r29,44(r8)
	PPC_STORE_U32(ctx.r8.u32 + 44, ctx.r29.u32);
	// bl 0x88096950
	ctx.lr = 0x8824DA90;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824DA9C"))) PPC_WEAK_FUNC(sub_8824DA9C);
PPC_FUNC_IMPL(__imp__sub_8824DA9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8824DAA0"))) PPC_WEAK_FUNC(sub_8824DAA0);
PPC_FUNC_IMPL(__imp__sub_8824DAA0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x8824DAA8;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880968b8
	ctx.lr = 0x8824DACC;
	sub_880968B8(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8824dc3c
	if (ctx.cr6.eq) goto loc_8824DC3C;
	// cmpwi cr6,r10,10
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 10, ctx.xer);
	// beq cr6,0x8824db4c
	if (ctx.cr6.eq) goto loc_8824DB4C;
	// cmpwi cr6,r10,20
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 20, ctx.xer);
	// bne cr6,0x8824dcb0
	if (!ctx.cr6.eq) goto loc_8824DCB0;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8824dc48
	if (!ctx.cr6.eq) goto loc_8824DC48;
	// lwz r11,2304(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2304);
	// li r10,8
	ctx.r10.s64 = 8;
	// li r9,0
	ctx.r9.s64 = 0;
	// lis r8,-30706
	ctx.r8.s64 = -2012348416;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,2064
	ctx.r4.s64 = ctx.r8.s64 + 2064;
	// stw r10,88(r11)
	PPC_STORE_U32(ctx.r11.u32 + 88, ctx.r10.u32);
	// lwz r3,36(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// bl 0x88096cb8
	ctx.lr = 0x8824DB20;
	sub_88096CB8(ctx, base);
	// lis r7,-30683
	ctx.r7.s64 = -2010841088;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r7,-9704
	ctx.r4.s64 = ctx.r7.s64 + -9704;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880969a8
	ctx.lr = 0x8824DB34;
	sub_880969A8(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096830
	ctx.lr = 0x8824DB40;
	sub_88096830(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824DB4C:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8824dbe4
	if (ctx.cr6.eq) goto loc_8824DBE4;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// bgt 0x8824dcb0
	if (ctx.cr0.gt) goto loc_8824DCB0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// lis r8,-30686
	ctx.r8.s64 = -2011037696;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,24680
	ctx.r4.s64 = ctx.r8.s64 + 24680;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88097078
	ctx.lr = 0x8824DB88;
	sub_88097078(ctx, base);
	// lwz r4,9100(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + 9100);
	// li r7,4
	ctx.r7.s64 = 4;
	// lis r6,220
	ctx.r6.s64 = 14417920;
	// lis r5,360
	ctx.r5.s64 = 23592960;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// stw r5,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// beq cr6,0x8824dbb4
	if (ctx.cr6.eq) goto loc_8824DBB4;
	// lis r11,20
	ctx.r11.s64 = 1310720;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
loc_8824DBB4:
	// lis r11,-30706
	ctx.r11.s64 = -2012348416;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-16944
	ctx.r4.s64 = ctx.r11.s64 + -16944;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880966a8
	ctx.lr = 0x8824DBC8;
	sub_880966A8(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// stw r10,24(r28)
	PPC_STORE_U32(ctx.r28.u32 + 24, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,20(r28)
	PPC_STORE_U32(ctx.r28.u32 + 20, ctx.r9.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824DBE4:
	// lwz r10,24(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8824dcb0
	if (!ctx.cr6.eq) goto loc_8824DCB0;
	// li r10,20
	ctx.r10.s64 = 20;
	// li r9,64
	ctx.r9.s64 = 64;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// bl 0x881534c8
	ctx.lr = 0x8824DC08;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r8,32
	ctx.r8.s64 = 32;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// lis r6,-30706
	ctx.r6.s64 = -2012348416;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r6,-1208
	ctx.r4.s64 = ctx.r6.s64 + -1208;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096cb8
	ctx.lr = 0x8824DC30;
	sub_88096CB8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824DC3C:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8824dc68
	if (ctx.cr6.eq) goto loc_8824DC68;
loc_8824DC48:
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// bgt 0x8824dcb0
	if (ctx.cr0.gt) goto loc_8824DCB0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824DC68:
	// li r10,10
	ctx.r10.s64 = 10;
	// li r9,64
	ctx.r9.s64 = 64;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r9,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// lis r8,-30706
	ctx.r8.s64 = -2012348416;
	// lwz r7,2304(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2304);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,36(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 36);
	// addi r4,r8,2064
	ctx.r4.s64 = ctx.r8.s64 + 2064;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stw r10,88(r7)
	PPC_STORE_U32(ctx.r7.u32 + 88, ctx.r10.u32);
	// bl 0x88096cb8
	ctx.lr = 0x8824DC9C;
	sub_88096CB8(ctx, base);
	// lis r6,-30706
	ctx.r6.s64 = -2012348416;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,36(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 36);
	// addi r4,r6,10816
	ctx.r4.s64 = ctx.r6.s64 + 10816;
	// bl 0x88096cb8
	ctx.lr = 0x8824DCB0;
	sub_88096CB8(ctx, base);
loc_8824DCB0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824DCBC"))) PPC_WEAK_FUNC(sub_8824DCBC);
PPC_FUNC_IMPL(__imp__sub_8824DCBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8824DCC0"))) PPC_WEAK_FUNC(sub_8824DCC0);
PPC_FUNC_IMPL(__imp__sub_8824DCC0) {
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
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,12
	ctx.r5.s64 = 12;
	// bl 0x880968b8
	ctx.lr = 0x8824DCEC;
	sub_880968B8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lis r8,-30683
	ctx.r8.s64 = -2010841088;
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r8,-9568
	ctx.r5.s64 = ctx.r8.s64 + -9568;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096950
	ctx.lr = 0x8824DD18;
	sub_88096950(ctx, base);
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

__attribute__((alias("__imp__sub_8824DD34"))) PPC_WEAK_FUNC(sub_8824DD34);
PPC_FUNC_IMPL(__imp__sub_8824DD34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8824DD38"))) PPC_WEAK_FUNC(sub_8824DD38);
PPC_FUNC_IMPL(__imp__sub_8824DD38) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x8824DD40;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x8824DD60;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,30
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 30, ctx.xer);
	// bgt cr6,0x8824e024
	if (ctx.cr6.gt) goto loc_8824E024;
	// beq cr6,0x8824df50
	if (ctx.cr6.eq) goto loc_8824DF50;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824df0c
	if (ctx.cr6.eq) goto loc_8824DF0C;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// beq cr6,0x8824de48
	if (ctx.cr6.eq) goto loc_8824DE48;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bne cr6,0x8824e0e8
	if (!ctx.cr6.eq) goto loc_8824E0E8;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x88096e28
	ctx.lr = 0x8824DD98;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8824e0e8
	if (!ctx.cr6.eq) goto loc_8824E0E8;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r10,10
	ctx.r10.s64 = 10;
	// li r9,96
	ctx.r9.s64 = 96;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// bgt 0x8824dde0
	if (ctx.cr0.gt) goto loc_8824DDE0;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r11,30
	ctx.r11.s64 = 30;
	// stw r29,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r29,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r29.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824DDE0:
	// lis r11,-30706
	ctx.r11.s64 = -2012348416;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,2912
	ctx.r4.s64 = ctx.r11.s64 + 2912;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096cb8
	ctx.lr = 0x8824DDF4;
	sub_88096CB8(ctx, base);
	// lis r10,-30706
	ctx.r10.s64 = -2012348416;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,2808
	ctx.r4.s64 = ctx.r10.s64 + 2808;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096cb8
	ctx.lr = 0x8824DE08;
	sub_88096CB8(ctx, base);
	// li r9,32
	ctx.r9.s64 = 32;
	// li r8,2
	ctx.r8.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// li r6,8
	ctx.r6.s64 = 8;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// lis r4,-30686
	ctx.r4.s64 = -2011037696;
	// stw r6,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r6.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r4,25536
	ctx.r4.s64 = ctx.r4.s64 + 25536;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x8824DE3C;
	sub_88097078(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824DE48:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824dea0
	if (ctx.cr6.eq) goto loc_8824DEA0;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824e0e8
	if (ctx.cr0.gt) goto loc_8824E0E8;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r29,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// bl 0x881534c8
	ctx.lr = 0x8824DE70;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// lis r10,-30706
	ctx.r10.s64 = -2012348416;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r4,r10,-1208
	ctx.r4.s64 = ctx.r10.s64 + -1208;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096cb8
	ctx.lr = 0x8824DE94;
	sub_88096CB8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824DEA0:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// bge 0x8824e0e8
	if (!ctx.cr0.lt) goto loc_8824E0E8;
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// li r10,4
	ctx.r10.s64 = 4;
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// li r8,12
	ctx.r8.s64 = 12;
	// lwz r7,20(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lis r6,-30686
	ctx.r6.s64 = -2011037696;
	// stw r10,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r8,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r8.u32);
	// addi r4,r6,25928
	ctx.r4.s64 = ctx.r6.s64 + 25928;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// stw r7,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r7.u32);
	// bl 0x88097078
	ctx.lr = 0x8824DEEC;
	sub_88097078(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,20
	ctx.r4.s64 = 20;
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// stw r5,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r5.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r4,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r4.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824DF0C:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824e0e8
	if (ctx.cr0.gt) goto loc_8824E0E8;
	// lis r11,-30686
	ctx.r11.s64 = -2011037696;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,25760
	ctx.r4.s64 = ctx.r11.s64 + 25760;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x8824DF30;
	sub_88097078(ctx, base);
	// li r10,10
	ctx.r10.s64 = 10;
	// li r9,24
	ctx.r9.s64 = 24;
	// stw r3,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r3.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824DF50:
	// lwz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// bge 0x8824e0e8
	if (!ctx.cr0.lt) goto loc_8824E0E8;
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// lis r10,-30706
	ctx.r10.s64 = -2012348416;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,2912
	ctx.r4.s64 = ctx.r10.s64 + 2912;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// bl 0x88096cb8
	ctx.lr = 0x8824DF7C;
	sub_88096CB8(ctx, base);
	// lis r9,-30706
	ctx.r9.s64 = -2012348416;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,2808
	ctx.r4.s64 = ctx.r9.s64 + 2808;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096cb8
	ctx.lr = 0x8824DF90;
	sub_88096CB8(ctx, base);
	// li r11,6
	ctx.r11.s64 = 6;
	// li r8,4
	ctx.r8.s64 = 4;
	// li r29,0
	ctx.r29.s64 = 0;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// lis r7,-30686
	ctx.r7.s64 = -2011037696;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// addi r4,r7,25536
	ctx.r4.s64 = ctx.r7.s64 + 25536;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88097078
	ctx.lr = 0x8824DFC0;
	sub_88097078(ctx, base);
	// lis r6,40
	ctx.r6.s64 = 2621440;
	// lis r5,340
	ctx.r5.s64 = 22282240;
	// stw r3,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r3.u32);
	// lwz r4,9100(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + 9100);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// stw r5,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// beq cr6,0x8824dfec
	if (ctx.cr6.eq) goto loc_8824DFEC;
	// lis r11,200
	ctx.r11.s64 = 13107200;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
loc_8824DFEC:
	// lis r11,-30706
	ctx.r11.s64 = -2012348416;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-16944
	ctx.r4.s64 = ctx.r11.s64 + -16944;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x8824E000;
	sub_880966A8(ctx, base);
	// li r10,40
	ctx.r10.s64 = 40;
	// stw r29,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x88096dd0
	ctx.lr = 0x8824E018;
	sub_88096DD0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824E024:
	// cmpwi cr6,r11,40
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 40, ctx.xer);
	// beq cr6,0x8824e0c4
	if (ctx.cr6.eq) goto loc_8824E0C4;
	// cmpwi cr6,r11,50
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 50, ctx.xer);
	// bne cr6,0x8824e0e8
	if (!ctx.cr6.eq) goto loc_8824E0E8;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824e060
	if (ctx.cr6.eq) goto loc_8824E060;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824e0e8
	if (ctx.cr0.gt) goto loc_8824E0E8;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824E060:
	// lis r11,-30683
	ctx.r11.s64 = -2010841088;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-9024
	ctx.r4.s64 = ctx.r11.s64 + -9024;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880969a8
	ctx.lr = 0x8824E074;
	sub_880969A8(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,9104(r28)
	PPC_STORE_U32(ctx.r28.u32 + 9104, ctx.r10.u32);
	// bl 0x881534c8
	ctx.lr = 0x8824E084;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// lis r7,-30706
	ctx.r7.s64 = -2012348416;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r7,-1208
	ctx.r4.s64 = ctx.r7.s64 + -1208;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096cb8
	ctx.lr = 0x8824E0AC;
	sub_88096CB8(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096830
	ctx.lr = 0x8824E0B8;
	sub_88096830(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824E0C4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,36(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// bl 0x88096e28
	ctx.lr = 0x8824E0D0;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8824e0e8
	if (!ctx.cr6.eq) goto loc_8824E0E8;
	// li r11,50
	ctx.r11.s64 = 50;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
loc_8824E0E8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824E0F4"))) PPC_WEAK_FUNC(sub_8824E0F4);
PPC_FUNC_IMPL(__imp__sub_8824E0F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8824E0F8"))) PPC_WEAK_FUNC(sub_8824E0F8);
PPC_FUNC_IMPL(__imp__sub_8824E0F8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x8824E100;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,48
	ctx.r5.s64 = 48;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880968b8
	ctx.lr = 0x8824E120;
	sub_880968B8(ctx, base);
	// lwz r10,9100(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 9100);
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r11,r10,-1
	ctx.r11.s64 = ctx.r10.s64 + -1;
	// lis r10,-30706
	ctx.r10.s64 = -2012348416;
	// clrlwi r9,r11,31
	ctx.r9.u64 = ctx.r11.u32 & 0x1;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r9,9100(r28)
	PPC_STORE_U32(ctx.r28.u32 + 9100, ctx.r9.u32);
	// li r9,16
	ctx.r9.s64 = 16;
	// li r8,32
	ctx.r8.s64 = 32;
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// li r7,64
	ctx.r7.s64 = 64;
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
	// addi r6,r10,-16944
	ctx.r6.s64 = ctx.r10.s64 + -16944;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// lis r5,120
	ctx.r5.s64 = 7864320;
	// stw r8,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r8.u32);
	// lis r4,360
	ctx.r4.s64 = 23592960;
	// stw r7,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r7.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// stw r9,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r9.u32);
	// stw r9,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r9.u32);
	// stw r30,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r30.u32);
	// lwz r3,5728(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5728);
	// cmpw cr6,r3,r6
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r6.s32, ctx.xer);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// stw r4,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// beq cr6,0x8824e1a4
	if (ctx.cr6.eq) goto loc_8824E1A4;
	// lis r11,-30706
	ctx.r11.s64 = -2012348416;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-16944
	ctx.r4.s64 = ctx.r11.s64 + -16944;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880966a8
	ctx.lr = 0x8824E1A4;
	sub_880966A8(ctx, base);
loc_8824E1A4:
	// lis r10,-30671
	ctx.r10.s64 = -2010054656;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// lis r9,16838
	ctx.r9.s64 = 1103495168;
	// lis r8,-30706
	ctx.r8.s64 = -2012348416;
	// ori r7,r9,20077
	ctx.r7.u64 = ctx.r9.u64 | 20077;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r11,4200(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4200);
	// addi r4,r8,-1208
	ctx.r4.s64 = ctx.r8.s64 + -1208;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mullw r11,r11,r7
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r7.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// stw r11,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r11.u32);
	// lhz r11,4200(r10)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// addi r6,r11,1
	ctx.r6.s64 = ctx.r11.s64 + 1;
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// bl 0x88096cb8
	ctx.lr = 0x8824E1E8;
	sub_88096CB8(ctx, base);
	// lis r5,-30683
	ctx.r5.s64 = -2010841088;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r5,r5,-8904
	ctx.r5.s64 = ctx.r5.s64 + -8904;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096950
	ctx.lr = 0x8824E1FC;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824E208"))) PPC_WEAK_FUNC(sub_8824E208);
PPC_FUNC_IMPL(__imp__sub_8824E208) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x8824E210;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880968b8
	ctx.lr = 0x8824E230;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824e318
	if (ctx.cr6.eq) goto loc_8824E318;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// beq cr6,0x8824e2a8
	if (ctx.cr6.eq) goto loc_8824E2A8;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bne cr6,0x8824e384
	if (!ctx.cr6.eq) goto loc_8824E384;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824e27c
	if (ctx.cr6.eq) goto loc_8824E27C;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// bgt 0x8824e384
	if (ctx.cr0.gt) goto loc_8824E384;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824E27C:
	// lis r11,-30683
	ctx.r11.s64 = -2010841088;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-7944
	ctx.r4.s64 = ctx.r11.s64 + -7944;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880969a8
	ctx.lr = 0x8824E290;
	sub_880969A8(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096830
	ctx.lr = 0x8824E29C;
	sub_88096830(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8824E2A8:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x88096e28
	ctx.lr = 0x8824E2B4;
	sub_88096E28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8824e384
	if (!ctx.cr6.eq) goto loc_8824E384;
	// lis r11,-30706
	ctx.r11.s64 = -2012348416;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,3016
	ctx.r4.s64 = ctx.r11.s64 + 3016;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096cb8
	ctx.lr = 0x8824E2D0;
	sub_88096CB8(ctx, base);
	// lis r10,-30706
	ctx.r10.s64 = -2012348416;
	// li r9,20
	ctx.r9.s64 = 20;
	// li r8,192
	ctx.r8.s64 = 192;
	// addi r7,r10,-16944
	ctx.r7.s64 = ctx.r10.s64 + -16944;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r8,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// lis r5,120
	ctx.r5.s64 = 7864320;
	// lwz r3,5728(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5728);
	// lis r4,360
	ctx.r4.s64 = 23592960;
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// cmpw cr6,r3,r7
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r7.s32, ctx.xer);
	// stw r4,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// beq cr6,0x8824e384
	if (ctx.cr6.eq) goto loc_8824E384;
	// lis r11,-30706
	ctx.r11.s64 = -2012348416;
	// addi r4,r11,-16944
	ctx.r4.s64 = ctx.r11.s64 + -16944;
	// b 0x8824e378
	goto loc_8824E378;
loc_8824E318:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824e384
	if (ctx.cr0.gt) goto loc_8824E384;
	// lwz r11,9100(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 9100);
	// lis r10,-30686
	ctx.r10.s64 = -2011037696;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,27192
	ctx.r4.s64 = ctx.r10.s64 + 27192;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x88097078
	ctx.lr = 0x8824E344;
	sub_88097078(ctx, base);
	// li r9,10
	ctx.r9.s64 = 10;
	// li r8,96
	ctx.r8.s64 = 96;
	// stw r3,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r3.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// lis r6,120
	ctx.r6.s64 = 7864320;
	// stw r8,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// lis r5,300
	ctx.r5.s64 = 19660800;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// lis r4,-30706
	ctx.r4.s64 = -2012348416;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// stw r5,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// addi r4,r4,-16944
	ctx.r4.s64 = ctx.r4.s64 + -16944;
loc_8824E378:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880966a8
	ctx.lr = 0x8824E384;
	sub_880966A8(ctx, base);
loc_8824E384:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824E390"))) PPC_WEAK_FUNC(sub_8824E390);
PPC_FUNC_IMPL(__imp__sub_8824E390) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x8824E398;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,48
	ctx.r5.s64 = 48;
	// bl 0x880968b8
	ctx.lr = 0x8824E3B4;
	sub_880968B8(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,2
	ctx.r10.s64 = 2;
	// li r11,64
	ctx.r11.s64 = 64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// li r6,80
	ctx.r6.s64 = 80;
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// li r29,32
	ctx.r29.s64 = 32;
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// lis r5,-30683
	ctx.r5.s64 = -2010841088;
	// stw r10,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r10.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r7,28(r8)
	PPC_STORE_U32(ctx.r8.u32 + 28, ctx.r7.u32);
	// addi r5,r5,-7672
	ctx.r5.s64 = ctx.r5.s64 + -7672;
	// stw r6,40(r8)
	PPC_STORE_U32(ctx.r8.u32 + 40, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r29,44(r8)
	PPC_STORE_U32(ctx.r8.u32 + 44, ctx.r29.u32);
	// bl 0x88096950
	ctx.lr = 0x8824E408;
	sub_88096950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824E414"))) PPC_WEAK_FUNC(sub_8824E414);
PPC_FUNC_IMPL(__imp__sub_8824E414) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8824E418"))) PPC_WEAK_FUNC(sub_8824E418);
PPC_FUNC_IMPL(__imp__sub_8824E418) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x8824E420;
	__savegprlr_26(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x880968b8
	ctx.lr = 0x8824E444;
	sub_880968B8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824e618
	if (ctx.cr6.eq) goto loc_8824E618;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// beq cr6,0x8824e4d8
	if (ctx.cr6.eq) goto loc_8824E4D8;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bne cr6,0x8824e68c
	if (!ctx.cr6.eq) goto loc_8824E68C;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8824e624
	if (!ctx.cr6.eq) goto loc_8824E624;
	// lwz r11,2304(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 2304);
	// li r10,8
	ctx.r10.s64 = 8;
	// li r30,0
	ctx.r30.s64 = 0;
	// lis r9,-30706
	ctx.r9.s64 = -2012348416;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,2064
	ctx.r4.s64 = ctx.r9.s64 + 2064;
	// stw r10,88(r11)
	PPC_STORE_U32(ctx.r11.u32 + 88, ctx.r10.u32);
	// lwz r3,36(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// bl 0x88096cb8
	ctx.lr = 0x8824E498;
	sub_88096CB8(ctx, base);
	// lwz r11,9100(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 9100);
	// stw r30,9104(r29)
	PPC_STORE_U32(ctx.r29.u32 + 9104, ctx.r30.u32);
	// lis r8,-30683
	ctx.r8.s64 = -2010841088;
	// addi r7,r11,-1
	ctx.r7.s64 = ctx.r11.s64 + -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// addi r4,r8,-7280
	ctx.r4.s64 = ctx.r8.s64 + -7280;
	// stw r6,9100(r29)
	PPC_STORE_U32(ctx.r29.u32 + 9100, ctx.r6.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x880969a8
	ctx.lr = 0x8824E4C0;
	sub_880969A8(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x88096830
	ctx.lr = 0x8824E4CC;
	sub_88096830(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_8824E4D8:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824e59c
	if (ctx.cr6.eq) goto loc_8824E59C;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824e68c
	if (ctx.cr0.gt) goto loc_8824E68C;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r9,-30686
	ctx.r9.s64 = -2011037696;
	// cntlzw r8,r11
	ctx.r8.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// addi r4,r9,24680
	ctx.r4.s64 = ctx.r9.s64 + 24680;
	// xori r11,r7,1
	ctx.r11.u64 = ctx.r7.u64 ^ 1;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r6,r11,2
	ctx.r6.s64 = ctx.r11.s64 + 2;
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// bl 0x88097078
	ctx.lr = 0x8824E524;
	sub_88097078(ctx, base);
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r5,4
	ctx.r5.s64 = 4;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// beq cr6,0x8824e548
	if (ctx.cr6.eq) goto loc_8824E548;
	// lis r10,400
	ctx.r10.s64 = 26214400;
	// lis r11,120
	ctx.r11.s64 = 7864320;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// b 0x8824e568
	goto loc_8824E568;
loc_8824E548:
	// lwz r11,9100(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 9100);
	// lis r10,220
	ctx.r10.s64 = 14417920;
	// lis r9,360
	ctx.r9.s64 = 23592960;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// beq cr6,0x8824e56c
	if (ctx.cr6.eq) goto loc_8824E56C;
	// lis r11,20
	ctx.r11.s64 = 1310720;
loc_8824E568:
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
loc_8824E56C:
	// lis r11,-30706
	ctx.r11.s64 = -2012348416;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-16944
	ctx.r4.s64 = ctx.r11.s64 + -16944;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x880966a8
	ctx.lr = 0x8824E580;
	sub_880966A8(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// stw r10,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r9.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_8824E59C:
	// lwz r11,24(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8824e68c
	if (!ctx.cr6.eq) goto loc_8824E68C;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824e5c8
	if (ctx.cr6.eq) goto loc_8824E5C8;
	// li r11,20
	ctx.r11.s64 = 20;
	// li r10,128
	ctx.r10.s64 = 128;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// b 0x8824e5dc
	goto loc_8824E5DC;
loc_8824E5C8:
	// li r30,0
	ctx.r30.s64 = 0;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r30,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stw r30,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
loc_8824E5DC:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x881534c8
	ctx.lr = 0x8824E5E4;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r10,32
	ctx.r10.s64 = 32;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// lis r8,-30706
	ctx.r8.s64 = -2012348416;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,-1208
	ctx.r4.s64 = ctx.r8.s64 + -1208;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x88096cb8
	ctx.lr = 0x8824E60C;
	sub_88096CB8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_8824E618:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8824e644
	if (ctx.cr6.eq) goto loc_8824E644;
loc_8824E624:
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8824e68c
	if (ctx.cr0.gt) goto loc_8824E68C;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_8824E644:
	// li r11,10
	ctx.r11.s64 = 10;
	// li r10,64
	ctx.r10.s64 = 64;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// lis r9,-30706
	ctx.r9.s64 = -2012348416;
	// lwz r8,2304(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 2304);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,36(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 36);
	// addi r4,r9,2064
	ctx.r4.s64 = ctx.r9.s64 + 2064;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// stw r30,88(r8)
	PPC_STORE_U32(ctx.r8.u32 + 88, ctx.r30.u32);
	// bl 0x88096cb8
	ctx.lr = 0x8824E678;
	sub_88096CB8(ctx, base);
	// lis r7,-30706
	ctx.r7.s64 = -2012348416;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,36(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 36);
	// addi r4,r7,10816
	ctx.r4.s64 = ctx.r7.s64 + 10816;
	// bl 0x88096cb8
	ctx.lr = 0x8824E68C;
	sub_88096CB8(ctx, base);
loc_8824E68C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824E698"))) PPC_WEAK_FUNC(sub_8824E698);
PPC_FUNC_IMPL(__imp__sub_8824E698) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x8824E6A0;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r11,19
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 19, ctx.xer);
	// bgt cr6,0x8824eac0
	if (ctx.cr6.gt) goto loc_8824EAC0;
	// lis r12,-30683
	ctx.r12.s64 = -2010841088;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,-6444
	ctx.r12.s64 = ctx.r12.s64 + -6444;
	// lwzx r0,r12,r0
	ctx.r0.u64 = PPC_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u64) {
	case 0:
		goto loc_8824E724;
	case 1:
		goto loc_8824E7BC;
	case 2:
		goto loc_8824E87C;
	case 3:
		goto loc_8824EAC0;
	case 4:
		goto loc_8824E894;
	case 5:
		goto loc_8824E8A8;
	case 6:
		goto loc_8824E8C4;
	case 7:
		goto loc_8824E8E0;
	case 8:
		goto loc_8824E904;
	case 9:
		goto loc_8824E960;
	case 10:
		goto loc_8824E980;
	case 11:
		goto loc_8824E99C;
	case 12:
		goto loc_8824E9D0;
	case 13:
		goto loc_8824E9E8;
	case 14:
		goto loc_8824EA10;
	case 15:
		goto loc_8824EA24;
	case 16:
		goto loc_8824EA38;
	case 17:
		goto loc_8824EA50;
	case 18:
		goto loc_8824EA60;
	case 19:
		goto loc_8824EAA8;
	default:
		__builtin_unreachable();
	}
	// lbz r1,-6364(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -6364);
	// lbz r1,-6212(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -6212);
	// lbz r1,-6020(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -6020);
	// lbz r1,-5440(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -5440);
	// lbz r1,-5996(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -5996);
	// lbz r1,-5976(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -5976);
	// lbz r1,-5948(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -5948);
	// lbz r1,-5920(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -5920);
	// lbz r1,-5884(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -5884);
	// lbz r1,-5792(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -5792);
	// lbz r1,-5760(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -5760);
	// lbz r1,-5732(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -5732);
	// lbz r1,-5680(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -5680);
	// lbz r1,-5656(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -5656);
	// lbz r1,-5616(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -5616);
	// lbz r1,-5596(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -5596);
	// lbz r1,-5576(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -5576);
	// lbz r1,-5552(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -5552);
	// lbz r1,-5536(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -5536);
	// lbz r1,-5464(r4)
	ctx.r1.u64 = PPC_LOAD_U8(ctx.r4.u32 + -5464);
loc_8824E724:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8824eac4
	if (ctx.cr6.eq) goto loc_8824EAC4;
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-30628
	ctx.r10.s64 = -2007236608;
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,-10868
	ctx.r11.s64 = ctx.r11.s64 + -10868;
	// lwz r7,8(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r6,12(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r4,r10,23472
	ctx.r4.s64 = ctx.r10.s64 + 23472;
	// lwz r5,16(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// li r31,3
	ctx.r31.s64 = 3;
	// lwz r29,20(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// stw r9,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r9.u32);
	// subf r4,r4,r29
	ctx.r4.s64 = ctx.r29.s64 - ctx.r4.s64;
	// stw r8,68(r11)
	PPC_STORE_U32(ctx.r11.u32 + 68, ctx.r8.u32);
	// stw r7,104(r11)
	PPC_STORE_U32(ctx.r11.u32 + 104, ctx.r7.u32);
	// stw r6,-128(r11)
	PPC_STORE_U32(ctx.r11.u32 + -128, ctx.r6.u32);
	// stw r5,-108(r11)
	PPC_STORE_U32(ctx.r11.u32 + -108, ctx.r5.u32);
loc_8824E774:
	// li r7,8
	ctx.r7.s64 = 8;
	// add r9,r4,r10
	ctx.r9.u64 = ctx.r4.u64 + ctx.r10.u64;
	// addi r8,r10,-4
	ctx.r8.s64 = ctx.r10.s64 + -4;
	// addi r9,r9,-4
	ctx.r9.s64 = ctx.r9.s64 + -4;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_8824E788:
	// lwzu r7,4(r9)
	ea = 4 + ctx.r9.u32;
	ctx.r7.u64 = PPC_LOAD_U32(ea);
	ctx.r9.u32 = ea;
	// stwu r7,4(r8)
	ea = 4 + ctx.r8.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r8.u32 = ea;
	// bdnz 0x8824e788
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8824E788;
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// bne 0x8824e774
	if (!ctx.cr0.eq) goto loc_8824E774;
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r9,28(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r10,-36(r11)
	PPC_STORE_U32(ctx.r11.u32 + -36, ctx.r10.u32);
	// stw r9,-32(r11)
	PPC_STORE_U32(ctx.r11.u32 + -32, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_8824E7BC:
	// bl 0x880923d0
	ctx.lr = 0x8824E7C0;
	sub_880923D0(ctx, base);
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// addi r10,r10,12932
	ctx.r10.s64 = ctx.r10.s64 + 12932;
	// addi r31,r9,-10868
	ctx.r31.s64 = ctx.r9.s64 + -10868;
loc_8824E7D4:
	// lbzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r10.u32);
	// addi r8,r31,-988
	ctx.r8.s64 = ctx.r31.s64 + -988;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stbx r9,r11,r8
	PPC_STORE_U8(ctx.r11.u32 + ctx.r8.u32, ctx.r9.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bne cr6,0x8824e7d4
	if (!ctx.cr6.eq) goto loc_8824E7D4;
	// addi r3,r31,-476
	ctx.r3.s64 = ctx.r31.s64 + -476;
	// li r5,256
	ctx.r5.s64 = 256;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x88073bd0
	ctx.lr = 0x8824E7FC;
	sub_88073BD0(ctx, base);
	// li r11,8
	ctx.r11.s64 = 8;
	// lis r10,-30719
	ctx.r10.s64 = -2013200384;
	// stw r30,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r30.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stw r30,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r30.u32);
	// addi r10,r10,-31808
	ctx.r10.s64 = ctx.r10.s64 + -31808;
	// stw r30,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r30.u32);
	// lis r9,-30697
	ctx.r9.s64 = -2011758592;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stw r10,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r10.u32);
	// addi r11,r9,-28776
	ctx.r11.s64 = ctx.r9.s64 + -28776;
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// std r30,0(r7)
	PPC_STORE_U64(ctx.r7.u32 + 0, ctx.r30.u64);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,-44(r31)
	PPC_STORE_U32(ctx.r31.u32 + -44, ctx.r11.u32);
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// addi r8,r31,-3700
	ctx.r8.s64 = ctx.r31.s64 + -3700;
	// stw r10,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r10.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r9,60
	ctx.r9.s64 = 60;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// addi r10,r8,-1
	ctx.r10.s64 = ctx.r8.s64 + -1;
	// stw r9,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r9.u32);
	// addi r11,r7,-1
	ctx.r11.s64 = ctx.r7.s64 + -1;
loc_8824E85C:
	// lbzu r9,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r9.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// stbu r9,1(r10)
	ea = 1 + ctx.r10.u32;
	PPC_STORE_U8(ea, ctx.r9.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x8824e85c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8824E85C;
	// bl 0x8808d0a8
	ctx.lr = 0x8824E86C;
	sub_8808D0A8(ctx, base);
	// bl 0x8808fdf8
	ctx.lr = 0x8824E870;
	sub_8808FDF8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_8824E87C:
	// bl 0x8808fab8
	ctx.lr = 0x8824E880;
	sub_8808FAB8(ctx, base);
	// bl 0x8808ff58
	ctx.lr = 0x8824E884;
	sub_8808FF58(ctx, base);
	// bl 0x8808d930
	ctx.lr = 0x8824E888;
	sub_8808D930(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_8824E894:
	// bl 0x8808fa68
	ctx.lr = 0x8824E898;
	sub_8808FA68(ctx, base);
	// bl 0x8808e468
	ctx.lr = 0x8824E89C;
	sub_8808E468(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_8824E8A8:
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addi r11,r11,-10868
	ctx.r11.s64 = ctx.r11.s64 + -10868;
	// addi r10,r11,72
	ctx.r10.s64 = ctx.r11.s64 + 72;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_8824E8C4:
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addi r11,r11,-10868
	ctx.r11.s64 = ctx.r11.s64 + -10868;
	// addi r10,r11,80
	ctx.r10.s64 = ctx.r11.s64 + 80;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_8824E8E0:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8824eac4
	if (ctx.cr6.eq) goto loc_8824EAC4;
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addi r11,r11,-10868
	ctx.r11.s64 = ctx.r11.s64 + -10868;
	// addi r10,r11,-72
	ctx.r10.s64 = ctx.r11.s64 + -72;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_8824E904:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8824eac4
	if (ctx.cr6.eq) goto loc_8824EAC4;
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r31,r9,-10868
	ctx.r31.s64 = ctx.r9.s64 + -10868;
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r8,12(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r7,16(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r6,20(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r5,24(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r4,28(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stw r10,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// stw r9,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r9.u32);
	// stw r8,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r8.u32);
	// stw r7,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r7.u32);
	// stw r6,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r6.u32);
	// stw r5,-180(r31)
	PPC_STORE_U32(ctx.r31.u32 + -180, ctx.r5.u32);
	// stw r4,-176(r31)
	PPC_STORE_U32(ctx.r31.u32 + -176, ctx.r4.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_8824E960:
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r9,r11,-10868
	ctx.r9.s64 = ctx.r11.s64 + -10868;
	// stw r10,-88(r9)
	PPC_STORE_U32(ctx.r9.u32 + -88, ctx.r10.u32);
	// stw r30,-84(r9)
	PPC_STORE_U32(ctx.r9.u32 + -84, ctx.r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_8824E980:
	// lis r11,-30683
	ctx.r11.s64 = -2010841088;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r9,r11,11608
	ctx.r9.s64 = ctx.r11.s64 + 11608;
	// stw r10,128(r9)
	PPC_STORE_U32(ctx.r9.u32 + 128, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_8824E99C:
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lis r8,-30683
	ctx.r8.s64 = -2010841088;
	// addi r7,r11,-10868
	ctx.r7.s64 = ctx.r11.s64 + -10868;
	// lis r9,0
	ctx.r9.s64 = 0;
	// li r11,3
	ctx.r11.s64 = 3;
	// li r10,-1
	ctx.r10.s64 = -1;
	// ori r9,r9,32768
	ctx.r9.u64 = ctx.r9.u64 | 32768;
	// stw r10,11608(r8)
	PPC_STORE_U32(ctx.r8.u32 + 11608, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,-8(r7)
	PPC_STORE_U32(ctx.r7.u32 + -8, ctx.r11.u32);
	// stw r9,16(r7)
	PPC_STORE_U32(ctx.r7.u32 + 16, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_8824E9D0:
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// li r11,1
	ctx.r11.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,-10868(r10)
	PPC_STORE_U32(ctx.r10.u32 + -10868, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_8824E9E8:
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addi r11,r11,-10868
	ctx.r11.s64 = ctx.r11.s64 + -10868;
	// lbz r10,-69(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + -69);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8824eac4
	if (!ctx.cr6.eq) goto loc_8824EAC4;
	// li r10,2
	ctx.r10.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_8824EA10:
	// lwz r4,16(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// bl 0x8808f1e8
	ctx.lr = 0x8824EA18;
	sub_8808F1E8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_8824EA24:
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x8808f150
	ctx.lr = 0x8824EA2C;
	sub_8808F150(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_8824EA38:
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x8808f098
	ctx.lr = 0x8824EA44;
	sub_8808F098(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_8824EA50:
	// bl 0x8808efa8
	ctx.lr = 0x8824EA54;
	sub_8808EFA8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_8824EA60:
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// blt cr6,0x8824ea7c
	if (ctx.cr6.lt) goto loc_8824EA7C;
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// blt cr6,0x8824ea90
	if (ctx.cr6.lt) goto loc_8824EA90;
	// cmplwi cr6,r11,15
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 15, ctx.xer);
	// bge cr6,0x8824ea90
	if (!ctx.cr6.lt) goto loc_8824EA90;
loc_8824EA7C:
	// lis r10,-30683
	ctx.r10.s64 = -2010841088;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,11608(r10)
	PPC_STORE_U32(ctx.r10.u32 + 11608, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_8824EA90:
	// lis r10,-30683
	ctx.r10.s64 = -2010841088;
	// li r11,-1
	ctx.r11.s64 = -1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,11608(r10)
	PPC_STORE_U32(ctx.r10.u32 + 11608, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_8824EAA8:
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x8808eec8
	ctx.lr = 0x8824EAB4;
	sub_8808EEC8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_8824EAC0:
	// li r30,-1
	ctx.r30.s64 = -1;
loc_8824EAC4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8824EE80"))) PPC_WEAK_FUNC(sub_8824EE80);
PPC_FUNC_IMPL(__imp__sub_8824EE80) {
	PPC_FUNC_PROLOGUE();
loc_8824EE80:
	// b 0x8824ee80
	goto loc_8824EE80;
}

__attribute__((alias("__imp__sub_8824EE84"))) PPC_WEAK_FUNC(sub_8824EE84);
PPC_FUNC_IMPL(__imp__sub_8824EE84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x485645
}

__attribute__((alias("__imp__sub_8824EE88"))) PPC_WEAK_FUNC(sub_8824EE88);
PPC_FUNC_IMPL(__imp__sub_8824EE88) {
	PPC_FUNC_PROLOGUE();
loc_8824EE88:
	// b 0x8824ee88
	goto loc_8824EE88;
}

__attribute__((alias("__imp__sub_8824EE8C"))) PPC_WEAK_FUNC(sub_8824EE8C);
PPC_FUNC_IMPL(__imp__sub_8824EE8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8824EE90"))) PPC_WEAK_FUNC(sub_8824EE90);
PPC_FUNC_IMPL(__imp__sub_8824EE90) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8824EE94"))) PPC_WEAK_FUNC(sub_8824EE94);
PPC_FUNC_IMPL(__imp__sub_8824EE94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8824EE98"))) PPC_WEAK_FUNC(sub_8824EE98);
PPC_FUNC_IMPL(__imp__sub_8824EE98) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8824EE9C"))) PPC_WEAK_FUNC(sub_8824EE9C);
PPC_FUNC_IMPL(__imp__sub_8824EE9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8824EEA0"))) PPC_WEAK_FUNC(sub_8824EEA0);
PPC_FUNC_IMPL(__imp__sub_8824EEA0) {
	PPC_FUNC_PROLOGUE();
	// .long 0x8800
}

__attribute__((alias("__imp__sub_8824EEA4"))) PPC_WEAK_FUNC(sub_8824EEA4);
PPC_FUNC_IMPL(__imp__sub_8824EEA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x1
}

__attribute__((alias("__imp__sub_8824EEA8"))) PPC_WEAK_FUNC(sub_8824EEA8);
PPC_FUNC_IMPL(__imp__sub_8824EEA8) {
	PPC_FUNC_PROLOGUE();
	// .long 0x1
}

__attribute__((alias("__imp__sub_8824EEAC"))) PPC_WEAK_FUNC(sub_8824EEAC);
PPC_FUNC_IMPL(__imp__sub_8824EEAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x24e698
}

