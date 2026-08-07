#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_8210A938"))) PPC_WEAK_FUNC(sub_8210A938);
PPC_FUNC_IMPL(__imp__sub_8210A938) {
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
	// li r10,2
	ctx.r10.s64 = 2;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8210A960:
	// lis r10,32767
	ctx.r10.s64 = 2147418112;
	// stw r9,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
	// stwu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8210a960
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8210A960;
	// addi r3,r31,20
	ctx.r3.s64 = ctx.r31.s64 + 20;
	// bl 0x82109a40
	ctx.lr = 0x8210A97C;
	sub_82109A40(ctx, base);
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

__attribute__((alias("__imp__sub_8210A994"))) PPC_WEAK_FUNC(sub_8210A994);
PPC_FUNC_IMPL(__imp__sub_8210A994) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210A998"))) PPC_WEAK_FUNC(sub_8210A998);
PPC_FUNC_IMPL(__imp__sub_8210A998) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8210A9A0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,44(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// addi r29,r3,44
	ctx.r29.s64 = ctx.r3.s64 + 44;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210A9C4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,176(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 176);
	// addi r30,r31,176
	ctx.r30.s64 = ctx.r31.s64 + 176;
	// stw r28,532(r31)
	PPC_STORE_U32(ctx.r31.u32 + 532, ctx.r28.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8210a9e4
	if (!ctx.cr6.eq) goto loc_8210A9E4;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8210b968
	ctx.lr = 0x8210A9E4;
	sub_8210B968(ctx, base);
loc_8210A9E4:
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8210aa94
	if (ctx.cr6.lt) goto loc_8210AA94;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// addi r6,r31,4
	ctx.r6.s64 = ctx.r31.s64 + 4;
	// li r5,375
	ctx.r5.s64 = 375;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210AA10;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8210aa94
	if (ctx.cr0.lt) goto loc_8210AA94;
	// addi r3,r31,592
	ctx.r3.s64 = ctx.r31.s64 + 592;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x8210ba28
	ctx.lr = 0x8210AA28;
	sub_8210BA28(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8210aa94
	if (ctx.cr0.lt) goto loc_8210AA94;
	// addi r5,r31,184
	ctx.r5.s64 = ctx.r31.s64 + 184;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82109330
	ctx.lr = 0x8210AA44;
	sub_82109330(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8210aa94
	if (ctx.cr0.lt) goto loc_8210AA94;
	// addi r5,r31,180
	ctx.r5.s64 = ctx.r31.s64 + 180;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82109330
	ctx.lr = 0x8210AA60;
	sub_82109330(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8210aa94
	if (ctx.cr0.lt) goto loc_8210AA94;
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r3,r31,16032
	ctx.r3.s64 = ctx.r31.s64 + 16032;
	// bl 0x8210a7f8
	ctx.lr = 0x8210AA78;
	sub_8210A7F8(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8210aa94
	if (ctx.cr0.lt) goto loc_8210AA94;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,160(r31)
	PPC_STORE_U32(ctx.r31.u32 + 160, ctx.r11.u32);
	// stw r11,164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 164, ctx.r11.u32);
	// b 0x8210aa9c
	goto loc_8210AA9C;
loc_8210AA94:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82108ed8
	ctx.lr = 0x8210AA9C;
	sub_82108ED8(ctx, base);
loc_8210AA9C:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210AAB0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82108da8
	ctx.lr = 0x8210AAB8;
	sub_82108DA8(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210AAC4"))) PPC_WEAK_FUNC(sub_8210AAC4);
PPC_FUNC_IMPL(__imp__sub_8210AAC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210AAC8"))) PPC_WEAK_FUNC(sub_8210AAC8);
PPC_FUNC_IMPL(__imp__sub_8210AAC8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8210AAD0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r11,r11,24644
	ctx.r11.s64 = ctx.r11.s64 + 24644;
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r28,r3,40
	ctx.r28.s64 = ctx.r3.s64 + 40;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// li r29,63
	ctx.r29.s64 = 63;
	// stw r30,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r30.u32);
loc_8210AAF8:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8210a938
	ctx.lr = 0x8210AB00;
	sub_8210A938(ctx, base);
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r28,r28,240
	ctx.r28.s64 = ctx.r28.s64 + 240;
	// bge 0x8210aaf8
	if (!ctx.cr0.lt) goto loc_8210AAF8;
	// addi r11,r31,15400
	ctx.r11.s64 = ctx.r31.s64 + 15400;
	// stw r30,15400(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15400, ctx.r30.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r30,15424(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15424, ctx.r30.u32);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// stw r30,15428(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15428, ctx.r30.u32);
	// stw r10,15436(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15436, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,15404(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15404, ctx.r11.u32);
	// stw r30,15432(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15432, ctx.r30.u32);
	// stw r30,15408(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15408, ctx.r30.u32);
	// lwz r10,15400(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 15400);
	// lwz r11,15404(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 15404);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// stw r11,15400(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15400, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210AB54"))) PPC_WEAK_FUNC(sub_8210AB54);
PPC_FUNC_IMPL(__imp__sub_8210AB54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210AB58"))) PPC_WEAK_FUNC(sub_8210AB58);
PPC_FUNC_IMPL(__imp__sub_8210AB58) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8210AB60;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r3,r3,15400
	ctx.r3.s64 = ctx.r3.s64 + 15400;
	// bl 0x8210ef58
	ctx.lr = 0x8210AB70;
	sub_8210EF58(ctx, base);
	// addi r11,r30,15400
	ctx.r11.s64 = ctx.r30.s64 + 15400;
	// li r29,63
	ctx.r29.s64 = 63;
	// addi r31,r11,4
	ctx.r31.s64 = ctx.r11.s64 + 4;
loc_8210AB7C:
	// addi r31,r31,-240
	ctx.r31.s64 = ctx.r31.s64 + -240;
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// bl 0x82118a58
	ctx.lr = 0x8210AB88;
	sub_82118A58(ctx, base);
	// lis r11,-32239
	ctx.r11.s64 = -2112815104;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r6,r11,-6024
	ctx.r6.s64 = ctx.r11.s64 + -6024;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82060818
	ctx.lr = 0x8210ABA0;
	sub_82060818(ctx, base);
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bge 0x8210ab7c
	if (!ctx.cr0.lt) goto loc_8210AB7C;
	// addi r3,r30,4
	ctx.r3.s64 = ctx.r30.s64 + 4;
	// bl 0x82108b60
	ctx.lr = 0x8210ABB0;
	sub_82108B60(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210ABB8"))) PPC_WEAK_FUNC(sub_8210ABB8);
PPC_FUNC_IMPL(__imp__sub_8210ABB8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c974
	ctx.lr = 0x8210ABC0;
	__savegprlr_23(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r11,472(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 472);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// mr r23,r5
	ctx.r23.u64 = ctx.r5.u64;
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
	// mr r24,r30
	ctx.r24.u64 = ctx.r30.u64;
	// b 0x8210ac10
	goto loc_8210AC10;
loc_8210ABE8:
	// lwz r31,0(r11)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplw cr6,r10,r28
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x8210ad6c
	if (ctx.cr6.eq) goto loc_8210AD6C;
	// bgt cr6,0x8210ac18
	if (ctx.cr6.gt) goto loc_8210AC18;
	// mr r29,r31
	ctx.r29.u64 = ctx.r31.u64;
	// mr r24,r11
	ctx.r24.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210ac18
	if (ctx.cr6.eq) goto loc_8210AC18;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
loc_8210AC10:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8210abe8
	if (!ctx.cr6.eq) goto loc_8210ABE8;
loc_8210AC18:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,-5536
	ctx.r3.s64 = ctx.r11.s64 + -5536;
	// ori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 | 1;
	// li r4,52
	ctx.r4.s64 = 52;
	// bl 0x82108aa8
	ctx.lr = 0x8210AC34;
	sub_82108AA8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8210ac80
	if (ctx.cr0.eq) goto loc_8210AC80;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r30,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r30.u32);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// stw r30,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r30.u32);
	// stw r10,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r10.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// stw r30,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r30.u32);
	// stw r30,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r30.u32);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// b 0x8210ac84
	goto loc_8210AC84;
loc_8210AC80:
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
loc_8210AC84:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8210ac9c
	if (!ctx.cr6.eq) goto loc_8210AC9C;
	// lis r11,-32761
	ctx.r11.s64 = -2147024896;
	// ori r11,r11,14
	ctx.r11.u64 = ctx.r11.u64 | 14;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// b 0x8210ad70
	goto loc_8210AD70;
loc_8210AC9C:
	// addi r26,r31,48
	ctx.r26.s64 = ctx.r31.s64 + 48;
	// stw r28,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// addi r27,r31,44
	ctx.r27.s64 = ctx.r31.s64 + 44;
	// stw r30,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r30.u32);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// stw r30,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r30.u32);
	// beq cr6,0x8210acc0
	if (ctx.cr6.eq) goto loc_8210ACC0;
	// lwz r28,48(r29)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r29.u32 + 48);
	// b 0x8210acc4
	goto loc_8210ACC4;
loc_8210ACC0:
	// lwz r28,180(r25)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r25.u32 + 180);
loc_8210ACC4:
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82109330
	ctx.lr = 0x8210ACD4;
	sub_82109330(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// blt 0x8210ad28
	if (ctx.cr0.lt) goto loc_8210AD28;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82109330
	ctx.lr = 0x8210ACF0;
	sub_82109330(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// blt 0x8210ad28
	if (ctx.cr0.lt) goto loc_8210AD28;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// addi r3,r25,448
	ctx.r3.s64 = ctx.r25.s64 + 448;
	// bl 0x82109ef0
	ctx.lr = 0x8210AD0C;
	sub_82109EF0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8210ad1c
	if (ctx.cr0.eq) goto loc_8210AD1C;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// b 0x8210ad6c
	goto loc_8210AD6C;
loc_8210AD1C:
	// lis r29,-32761
	ctx.r29.s64 = -2147024896;
	// ori r29,r29,14
	ctx.r29.u64 = ctx.r29.u64 | 14;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
loc_8210AD28:
	// lwz r4,0(r27)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8210ad3c
	if (ctx.cr6.eq) goto loc_8210AD3C;
	// lwz r3,16032(r25)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r25.u32 + 16032);
	// bl 0x82157518
	ctx.lr = 0x8210AD3C;
	sub_82157518(ctx, base);
loc_8210AD3C:
	// lwz r4,0(r26)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8210ad50
	if (ctx.cr6.eq) goto loc_8210AD50;
	// lwz r3,16032(r25)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r25.u32 + 16032);
	// bl 0x82157518
	ctx.lr = 0x8210AD50;
	sub_82157518(ctx, base);
loc_8210AD50:
	// addi r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 4;
	// bl 0x8210ef58
	ctx.lr = 0x8210AD58;
	sub_8210EF58(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82114628
	ctx.lr = 0x8210AD60;
	sub_82114628(ctx, base);
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt cr6,0x8210ad70
	if (ctx.cr6.lt) goto loc_8210AD70;
loc_8210AD6C:
	// stw r31,0(r23)
	PPC_STORE_U32(ctx.r23.u32 + 0, ctx.r31.u32);
loc_8210AD70:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82108da8
	ctx.lr = 0x8210AD78;
	sub_82108DA8(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210AD84"))) PPC_WEAK_FUNC(sub_8210AD84);
PPC_FUNC_IMPL(__imp__sub_8210AD84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210AD88"))) PPC_WEAK_FUNC(sub_8210AD88);
PPC_FUNC_IMPL(__imp__sub_8210AD88) {
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
	// b 0x8210adbc
	goto loc_8210ADBC;
loc_8210ADA4:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8210adbc
	if (ctx.cr6.eq) goto loc_8210ADBC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8210a8a0
	ctx.lr = 0x8210ADB4;
	sub_8210A8A0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82114628
	ctx.lr = 0x8210ADBC;
	sub_82114628(ctx, base);
loc_8210ADBC:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8210bb88
	ctx.lr = 0x8210ADC4;
	sub_8210BB88(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x8210ada4
	if (!ctx.cr0.eq) goto loc_8210ADA4;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82118a58
	ctx.lr = 0x8210ADD4;
	sub_82118A58(ctx, base);
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

__attribute__((alias("__imp__sub_8210ADEC"))) PPC_WEAK_FUNC(sub_8210ADEC);
PPC_FUNC_IMPL(__imp__sub_8210ADEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210ADF0"))) PPC_WEAK_FUNC(sub_8210ADF0);
PPC_FUNC_IMPL(__imp__sub_8210ADF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8210ADF8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r11,r11,24668
	ctx.r11.s64 = ctx.r11.s64 + 24668;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// li r29,1
	ctx.r29.s64 = 1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r10,24736
	ctx.r10.s64 = ctx.r10.s64 + 24736;
	// stw r29,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r29.u32);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// addi r11,r9,24716
	ctx.r11.s64 = ctx.r9.s64 + 24716;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r9,r8,24700
	ctx.r9.s64 = ctx.r8.s64 + 24700;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// addi r10,r7,24644
	ctx.r10.s64 = ctx.r7.s64 + 24644;
	// stw r30,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r30.u32);
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// addi r3,r3,188
	ctx.r3.s64 = ctx.r3.s64 + 188;
	// stw r30,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r30.u32);
	// addi r11,r31,8
	ctx.r11.s64 = ctx.r31.s64 + 8;
	// stw r30,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r30.u32);
	// stw r30,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r30.u32);
	// stw r30,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r30.u32);
	// stw r30,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r30.u32);
	// stw r30,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r30.u32);
	// stw r10,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r10.u32);
	// stw r30,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r30.u32);
	// stw r10,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r10.u32);
	// stw r30,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r30.u32);
	// stw r10,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r10.u32);
	// stw r30,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r30.u32);
	// stw r30,152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 152, ctx.r30.u32);
	// stw r30,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r30.u32);
	// stw r30,160(r31)
	PPC_STORE_U32(ctx.r31.u32 + 160, ctx.r30.u32);
	// stw r30,164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 164, ctx.r30.u32);
	// stw r30,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r30.u32);
	// stw r30,172(r31)
	PPC_STORE_U32(ctx.r31.u32 + 172, ctx.r30.u32);
	// stw r30,176(r31)
	PPC_STORE_U32(ctx.r31.u32 + 176, ctx.r30.u32);
	// stw r30,180(r31)
	PPC_STORE_U32(ctx.r31.u32 + 180, ctx.r30.u32);
	// stw r30,184(r31)
	PPC_STORE_U32(ctx.r31.u32 + 184, ctx.r30.u32);
	// bl 0x82109a40
	ctx.lr = 0x8210AEA8;
	sub_82109A40(ctx, base);
	// addi r11,r31,408
	ctx.r11.s64 = ctx.r31.s64 + 408;
	// stw r30,408(r31)
	PPC_STORE_U32(ctx.r31.u32 + 408, ctx.r30.u32);
	// addi r10,r31,448
	ctx.r10.s64 = ctx.r31.s64 + 448;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// stw r30,432(r31)
	PPC_STORE_U32(ctx.r31.u32 + 432, ctx.r30.u32);
	// stw r30,436(r31)
	PPC_STORE_U32(ctx.r31.u32 + 436, ctx.r30.u32);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// stw r11,412(r31)
	PPC_STORE_U32(ctx.r31.u32 + 412, ctx.r11.u32);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// stw r30,440(r31)
	PPC_STORE_U32(ctx.r31.u32 + 440, ctx.r30.u32);
	// addi r9,r31,488
	ctx.r9.s64 = ctx.r31.s64 + 488;
	// stw r29,444(r31)
	PPC_STORE_U32(ctx.r31.u32 + 444, ctx.r29.u32);
	// li r8,16
	ctx.r8.s64 = 16;
	// stw r30,416(r31)
	PPC_STORE_U32(ctx.r31.u32 + 416, ctx.r30.u32);
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// lwz r7,408(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 408);
	// addi r3,r31,592
	ctx.r3.s64 = ctx.r31.s64 + 592;
	// lfs f0,14004(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 14004);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,412(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 412);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r7,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r7.u32);
	// stw r11,408(r31)
	PPC_STORE_U32(ctx.r31.u32 + 408, ctx.r11.u32);
	// stw r10,452(r31)
	PPC_STORE_U32(ctx.r31.u32 + 452, ctx.r10.u32);
	// addi r10,r31,536
	ctx.r10.s64 = ctx.r31.s64 + 536;
	// stw r30,448(r31)
	PPC_STORE_U32(ctx.r31.u32 + 448, ctx.r30.u32);
	// stw r30,472(r31)
	PPC_STORE_U32(ctx.r31.u32 + 472, ctx.r30.u32);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// stw r30,476(r31)
	PPC_STORE_U32(ctx.r31.u32 + 476, ctx.r30.u32);
	// stw r30,480(r31)
	PPC_STORE_U32(ctx.r31.u32 + 480, ctx.r30.u32);
	// stw r29,484(r31)
	PPC_STORE_U32(ctx.r31.u32 + 484, ctx.r29.u32);
	// stw r30,456(r31)
	PPC_STORE_U32(ctx.r31.u32 + 456, ctx.r30.u32);
	// lwz r7,448(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 448);
	// lwz r11,452(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 452);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r7,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r7.u32);
	// stw r11,448(r31)
	PPC_STORE_U32(ctx.r31.u32 + 448, ctx.r11.u32);
	// stw r30,488(r31)
	PPC_STORE_U32(ctx.r31.u32 + 488, ctx.r30.u32);
	// stw r9,492(r31)
	PPC_STORE_U32(ctx.r31.u32 + 492, ctx.r9.u32);
	// stw r30,512(r31)
	PPC_STORE_U32(ctx.r31.u32 + 512, ctx.r30.u32);
	// stw r30,516(r31)
	PPC_STORE_U32(ctx.r31.u32 + 516, ctx.r30.u32);
	// stw r30,520(r31)
	PPC_STORE_U32(ctx.r31.u32 + 520, ctx.r30.u32);
	// stw r29,524(r31)
	PPC_STORE_U32(ctx.r31.u32 + 524, ctx.r29.u32);
	// stw r30,496(r31)
	PPC_STORE_U32(ctx.r31.u32 + 496, ctx.r30.u32);
	// lwz r11,492(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 492);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// lwz r9,488(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 488);
	// stw r9,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// stw r11,488(r31)
	PPC_STORE_U32(ctx.r31.u32 + 488, ctx.r11.u32);
	// stfs f0,528(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 528, temp.u32);
	// stw r8,532(r31)
	PPC_STORE_U32(ctx.r31.u32 + 532, ctx.r8.u32);
	// stw r30,536(r31)
	PPC_STORE_U32(ctx.r31.u32 + 536, ctx.r30.u32);
	// stw r10,540(r31)
	PPC_STORE_U32(ctx.r31.u32 + 540, ctx.r10.u32);
	// stw r30,560(r31)
	PPC_STORE_U32(ctx.r31.u32 + 560, ctx.r30.u32);
	// stw r30,564(r31)
	PPC_STORE_U32(ctx.r31.u32 + 564, ctx.r30.u32);
	// stw r30,568(r31)
	PPC_STORE_U32(ctx.r31.u32 + 568, ctx.r30.u32);
	// stw r29,572(r31)
	PPC_STORE_U32(ctx.r31.u32 + 572, ctx.r29.u32);
	// stw r30,544(r31)
	PPC_STORE_U32(ctx.r31.u32 + 544, ctx.r30.u32);
	// lwz r10,536(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 536);
	// lwz r11,540(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 540);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// stw r11,536(r31)
	PPC_STORE_U32(ctx.r31.u32 + 536, ctx.r11.u32);
	// bl 0x8210aac8
	ctx.lr = 0x8210AFA4;
	sub_8210AAC8(ctx, base);
	// stw r30,16032(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16032, ctx.r30.u32);
	// stw r30,16036(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16036, ctx.r30.u32);
	// addi r3,r31,16040
	ctx.r3.s64 = ctx.r31.s64 + 16040;
	// bl 0x82109a40
	ctx.lr = 0x8210AFB4;
	sub_82109A40(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,-22633
	ctx.r10.s64 = -1483276288;
	// ori r11,r11,32768
	ctx.r11.u64 = ctx.r11.u64 | 32768;
	// stw r10,16260(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16260, ctx.r10.u32);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stw r11,16264(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16264, ctx.r11.u32);
	// addi r3,r10,-5536
	ctx.r3.s64 = ctx.r10.s64 + -5536;
	// bl 0x82108990
	ctx.lr = 0x8210AFD4;
	sub_82108990(ctx, base);
	// addi r11,r31,576
	ctx.r11.s64 = ctx.r31.s64 + 576;
	// stw r30,576(r31)
	PPC_STORE_U32(ctx.r31.u32 + 576, ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,588(r31)
	PPC_STORE_U32(ctx.r31.u32 + 588, ctx.r11.u32);
	// stw r30,580(r31)
	PPC_STORE_U32(ctx.r31.u32 + 580, ctx.r30.u32);
	// stw r29,584(r31)
	PPC_STORE_U32(ctx.r31.u32 + 584, ctx.r29.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210AFF4"))) PPC_WEAK_FUNC(sub_8210AFF4);
PPC_FUNC_IMPL(__imp__sub_8210AFF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210AFF8"))) PPC_WEAK_FUNC(sub_8210AFF8);
PPC_FUNC_IMPL(__imp__sub_8210AFF8) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
	// b 0x8210b598
	sub_8210B598(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210B000"))) PPC_WEAK_FUNC(sub_8210B000);
PPC_FUNC_IMPL(__imp__sub_8210B000) {
	PPC_FUNC_PROLOGUE();
	// addi r11,r3,12
	ctx.r11.s64 = ctx.r3.s64 + 12;
loc_8210B004:
	// mfmsr r9
	ctx.r9.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r10,0,r11
	ctx.reserved.u32 = *(uint32_t*)(base + ctx.r11.u32);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stwcx. r10,0,r11
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + ctx.r11.u32), ctx.reserved.s32, __builtin_bswap32(ctx.r10.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x8210b004
	if (!ctx.cr0.eq) goto loc_8210B004;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8210B028"))) PPC_WEAK_FUNC(sub_8210B028);
PPC_FUNC_IMPL(__imp__sub_8210B028) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
	// b 0x82108e38
	sub_82108E38(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210B030"))) PPC_WEAK_FUNC(sub_8210B030);
PPC_FUNC_IMPL(__imp__sub_8210B030) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
	// b 0x8210b000
	sub_8210B000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210B038"))) PPC_WEAK_FUNC(sub_8210B038);
PPC_FUNC_IMPL(__imp__sub_8210B038) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,8
	ctx.r3.s64 = ctx.r3.s64 + 8;
	// b 0x82109958
	sub_82109958(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210B040"))) PPC_WEAK_FUNC(sub_8210B040);
PPC_FUNC_IMPL(__imp__sub_8210B040) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
	// b 0x8210b038
	sub_8210B038(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210B048"))) PPC_WEAK_FUNC(sub_8210B048);
PPC_FUNC_IMPL(__imp__sub_8210B048) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x8210B050;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r11,r11,24736
	ctx.r11.s64 = ctx.r11.s64 + 24736;
	// addi r10,r10,24716
	ctx.r10.s64 = ctx.r10.s64 + 24716;
	// addi r9,r9,24700
	ctx.r9.s64 = ctx.r9.s64 + 24700;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// addi r25,r3,44
	ctx.r25.s64 = ctx.r3.s64 + 44;
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,44(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210B094;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x8208da10
	ctx.lr = 0x8210B098;
	sub_8208DA10(ctx, base);
	// lwz r11,176(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 176);
	// li r24,0
	ctx.r24.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210b250
	if (ctx.cr6.eq) goto loc_8210B250;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82109280
	ctx.lr = 0x8210B0B4;
	sub_82109280(ctx, base);
	// lwz r3,156(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 156);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8210b0c8
	if (ctx.cr6.eq) goto loc_8210B0C8;
	// bl 0x82114628
	ctx.lr = 0x8210B0C4;
	sub_82114628(ctx, base);
	// stw r24,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r24.u32);
loc_8210B0C8:
	// lwz r11,400(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 400);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210b15c
	if (ctx.cr6.eq) goto loc_8210B15C;
	// addi r28,r31,188
	ctx.r28.s64 = ctx.r31.s64 + 188;
	// b 0x8210b14c
	goto loc_8210B14C;
loc_8210B0DC:
	// lwz r11,60(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 60);
	// rlwinm. r11,r11,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8210b118
	if (ctx.cr0.eq) goto loc_8210B118;
	// lwz r11,512(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 512);
	// addi r3,r31,488
	ctx.r3.s64 = ctx.r31.s64 + 488;
	// b 0x8210b104
	goto loc_8210B104;
loc_8210B0F4:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r30
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x8210b110
	if (ctx.cr6.eq) goto loc_8210B110;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
loc_8210B104:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8210b0f4
	if (!ctx.cr6.eq) goto loc_8210B0F4;
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
loc_8210B110:
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// bl 0x8210ea78
	ctx.lr = 0x8210B118;
	sub_8210EA78(ctx, base);
loc_8210B118:
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// addi r29,r30,4
	ctx.r29.s64 = ctx.r30.s64 + 4;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,80(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210B130;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,76(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210B148;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x82114628
	ctx.lr = 0x8210B14C;
	sub_82114628(ctx, base);
loc_8210B14C:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8210bb88
	ctx.lr = 0x8210B154;
	sub_8210BB88(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x8210b0dc
	if (!ctx.cr0.eq) goto loc_8210B0DC;
loc_8210B15C:
	// addi r26,r31,448
	ctx.r26.s64 = ctx.r31.s64 + 448;
	// b 0x8210b1d8
	goto loc_8210B1D8;
loc_8210B164:
	// lwz r4,44(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	// lwz r3,16032(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16032);
	// bl 0x82157518
	ctx.lr = 0x8210B170;
	sub_82157518(ctx, base);
	// lwz r3,16032(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16032);
	// lwz r4,48(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 48);
	// bl 0x82157518
	ctx.lr = 0x8210B17C;
	sub_82157518(ctx, base);
	// addi r28,r30,4
	ctx.r28.s64 = ctx.r30.s64 + 4;
	// b 0x8210b1b8
	goto loc_8210B1B8;
loc_8210B184:
	// lwz r11,4(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// addi r27,r29,4
	ctx.r27.s64 = ctx.r29.s64 + 4;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r11,80(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210B19C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,4(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r11,76(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210B1B4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x82114628
	ctx.lr = 0x8210B1B8;
	sub_82114628(ctx, base);
loc_8210B1B8:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82109678
	ctx.lr = 0x8210B1C0;
	sub_82109678(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne 0x8210b184
	if (!ctx.cr0.eq) goto loc_8210B184;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8210ef58
	ctx.lr = 0x8210B1D0;
	sub_8210EF58(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82114628
	ctx.lr = 0x8210B1D8;
	sub_82114628(ctx, base);
loc_8210B1D8:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82109678
	ctx.lr = 0x8210B1E0;
	sub_82109678(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x8210b164
	if (!ctx.cr0.eq) goto loc_8210B164;
	// lwz r11,440(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 440);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210b240
	if (ctx.cr6.eq) goto loc_8210B240;
	// addi r28,r31,408
	ctx.r28.s64 = ctx.r31.s64 + 408;
	// b 0x8210b230
	goto loc_8210B230;
loc_8210B1FC:
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// addi r29,r30,4
	ctx.r29.s64 = ctx.r30.s64 + 4;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,80(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210B214;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,76(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210B22C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x82114628
	ctx.lr = 0x8210B230;
	sub_82114628(ctx, base);
loc_8210B230:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82109678
	ctx.lr = 0x8210B238;
	sub_82109678(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x8210b1fc
	if (!ctx.cr0.eq) goto loc_8210B1FC;
loc_8210B240:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82108f60
	ctx.lr = 0x8210B248;
	sub_82108F60(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82108ed8
	ctx.lr = 0x8210B250;
	sub_82108ED8(ctx, base);
loc_8210B250:
	// stw r24,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r24.u32);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lwz r11,0(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210B268;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r31,16040
	ctx.r3.s64 = ctx.r31.s64 + 16040;
	// bl 0x8210ad88
	ctx.lr = 0x8210B270;
	sub_8210AD88(ctx, base);
	// addi r3,r31,16032
	ctx.r3.s64 = ctx.r31.s64 + 16032;
	// bl 0x82108248
	ctx.lr = 0x8210B278;
	sub_82108248(ctx, base);
	// addi r3,r31,592
	ctx.r3.s64 = ctx.r31.s64 + 592;
	// bl 0x8210ab58
	ctx.lr = 0x8210B280;
	sub_8210AB58(ctx, base);
	// addi r3,r31,536
	ctx.r3.s64 = ctx.r31.s64 + 536;
	// bl 0x8210ef58
	ctx.lr = 0x8210B288;
	sub_8210EF58(ctx, base);
	// addi r3,r31,488
	ctx.r3.s64 = ctx.r31.s64 + 488;
	// bl 0x8210ef58
	ctx.lr = 0x8210B290;
	sub_8210EF58(ctx, base);
	// addi r3,r31,448
	ctx.r3.s64 = ctx.r31.s64 + 448;
	// bl 0x8210ef58
	ctx.lr = 0x8210B298;
	sub_8210EF58(ctx, base);
	// addi r3,r31,408
	ctx.r3.s64 = ctx.r31.s64 + 408;
	// bl 0x8210ef58
	ctx.lr = 0x8210B2A0;
	sub_8210EF58(ctx, base);
	// addi r3,r31,188
	ctx.r3.s64 = ctx.r31.s64 + 188;
	// bl 0x82118a58
	ctx.lr = 0x8210B2A8;
	sub_82118A58(ctx, base);
	// addi r3,r31,116
	ctx.r3.s64 = ctx.r31.s64 + 116;
	// bl 0x82108b60
	ctx.lr = 0x8210B2B0;
	sub_82108B60(ctx, base);
	// addi r3,r31,80
	ctx.r3.s64 = ctx.r31.s64 + 80;
	// bl 0x82108b60
	ctx.lr = 0x8210B2B8;
	sub_82108B60(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82108b60
	ctx.lr = 0x8210B2C0;
	sub_82108B60(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r11,r11,24668
	ctx.r11.s64 = ctx.r11.s64 + 24668;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210B2D4"))) PPC_WEAK_FUNC(sub_8210B2D4);
PPC_FUNC_IMPL(__imp__sub_8210B2D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210B2D8"))) PPC_WEAK_FUNC(sub_8210B2D8);
PPC_FUNC_IMPL(__imp__sub_8210B2D8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c96c
	ctx.lr = 0x8210B2E0;
	__savegprlr_21(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,44(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// addi r25,r3,44
	ctx.r25.s64 = ctx.r3.s64 + 44;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// mr r21,r4
	ctx.r21.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mr r31,r6
	ctx.r31.u64 = ctx.r6.u64;
	// mr r24,r7
	ctx.r24.u64 = ctx.r7.u64;
	// mr r29,r8
	ctx.r29.u64 = ctx.r8.u64;
	// mr r23,r9
	ctx.r23.u64 = ctx.r9.u64;
	// mr r22,r10
	ctx.r22.u64 = ctx.r10.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210B31C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,375
	ctx.r11.s64 = 375;
	// divwu r11,r31,r11
	ctx.r11.u32 = ppc_divwu(ctx.r31.u32, ctx.r11.u32);
	// mulli r11,r11,375
	ctx.r11.s64 = ctx.r11.s64 * 375;
	// subf. r11,r11,r31
	ctx.r11.s64 = ctx.r31.s64 - ctx.r11.s64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8210b34c
	if (ctx.cr0.eq) goto loc_8210B34C;
	// subf r11,r11,r31
	ctx.r11.s64 = ctx.r31.s64 - ctx.r11.s64;
	// cmplwi cr6,r11,32000
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32000, ctx.xer);
	// bge cr6,0x8210b340
	if (!ctx.cr6.lt) goto loc_8210B340;
	// addi r11,r11,375
	ctx.r11.s64 = ctx.r11.s64 + 375;
loc_8210B340:
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x8210b34c
	if (ctx.cr6.eq) goto loc_8210B34C;
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
loc_8210B34C:
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8210abb8
	ctx.lr = 0x8210B364;
	sub_8210ABB8(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// blt 0x8210b458
	if (ctx.cr0.lt) goto loc_8210B458;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,-5536
	ctx.r3.s64 = ctx.r11.s64 + -5536;
	// ori r5,r5,2
	ctx.r5.u64 = ctx.r5.u64 | 2;
	// li r4,148
	ctx.r4.s64 = 148;
	// bl 0x82108aa8
	ctx.lr = 0x8210B38C;
	sub_82108AA8(ctx, base);
	// lwz r26,84(r1)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8210b3b8
	if (ctx.cr0.eq) goto loc_8210B3B8;
	// mr r8,r31
	ctx.r8.u64 = ctx.r31.u64;
	// lwz r6,44(r26)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r26.u32 + 44);
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x82113680
	ctx.lr = 0x8210B3B0;
	sub_82113680(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x8210b3bc
	goto loc_8210B3BC;
loc_8210B3B8:
	// li r31,0
	ctx.r31.s64 = 0;
loc_8210B3BC:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8210b3d4
	if (!ctx.cr6.eq) goto loc_8210B3D4;
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,14
	ctx.r30.u64 = ctx.r30.u64 | 14;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// b 0x8210b458
	goto loc_8210B458;
loc_8210B3D4:
	// mr r6,r22
	ctx.r6.u64 = ctx.r22.u64;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82113598
	ctx.lr = 0x8210B3E8;
	sub_82113598(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// blt 0x8210b424
	if (ctx.cr0.lt) goto loc_8210B424;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r26,4
	ctx.r3.s64 = ctx.r26.s64 + 4;
	// bl 0x82109f68
	ctx.lr = 0x8210B400;
	sub_82109F68(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8210b418
	if (ctx.cr0.eq) goto loc_8210B418;
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r31,0(r21)
	PPC_STORE_U32(ctx.r21.u32 + 0, ctx.r31.u32);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// b 0x8210b458
	goto loc_8210B458;
loc_8210B418:
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,14
	ctx.r30.u64 = ctx.r30.u64 | 14;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
loc_8210B424:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r29,r31,4
	ctx.r29.s64 = ctx.r31.s64 + 4;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,80(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210B43C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,76(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210B454;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x82114628
	ctx.lr = 0x8210B458;
	sub_82114628(ctx, base);
loc_8210B458:
	// lwz r11,0(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210B46C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge cr6,0x8210b47c
	if (!ctx.cr6.lt) goto loc_8210B47C;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82108f60
	ctx.lr = 0x8210B47C;
	sub_82108F60(ctx, base);
loc_8210B47C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82108da8
	ctx.lr = 0x8210B484;
	sub_82108DA8(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9bc
	__restgprlr_21(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210B490"))) PPC_WEAK_FUNC(sub_8210B490);
PPC_FUNC_IMPL(__imp__sub_8210B490) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x8210B498;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// li r31,0
	ctx.r31.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8210b4bc
	if (!ctx.cr6.eq) goto loc_8210B4BC;
	// lis r31,-30570
	ctx.r31.s64 = -2003435520;
	// ori r31,r31,1
	ctx.r31.u64 = ctx.r31.u64 | 1;
loc_8210B4BC:
	// rlwinm. r11,r28,0,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0xFFFFFFFE;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8210b4cc
	if (ctx.cr0.eq) goto loc_8210B4CC;
	// lis r31,-30570
	ctx.r31.s64 = -2003435520;
	// ori r31,r31,1
	ctx.r31.u64 = ctx.r31.u64 | 1;
loc_8210B4CC:
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt cr6,0x8210b588
	if (ctx.cr6.lt) goto loc_8210B588;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r29,r11,-5536
	ctx.r29.s64 = ctx.r11.s64 + -5536;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82108990
	ctx.lr = 0x8210B4E4;
	sub_82108990(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x8210b588
	if (ctx.cr0.lt) goto loc_8210B588;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// ori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 | 1;
	// li r4,16268
	ctx.r4.s64 = 16268;
	// bl 0x82108aa8
	ctx.lr = 0x8210B504;
	sub_82108AA8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8210b518
	if (ctx.cr0.eq) goto loc_8210B518;
	// bl 0x8210adf0
	ctx.lr = 0x8210B510;
	sub_8210ADF0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x8210b51c
	goto loc_8210B51C;
loc_8210B518:
	// li r30,0
	ctx.r30.s64 = 0;
loc_8210B51C:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x8210b530
	if (!ctx.cr6.eq) goto loc_8210B530;
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,14
	ctx.r31.u64 = ctx.r31.u64 | 14;
	// b 0x8210b580
	goto loc_8210B580;
loc_8210B530:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821081d0
	ctx.lr = 0x8210B538;
	sub_821081D0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x8210b56c
	if (ctx.cr0.lt) goto loc_8210B56C;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210B55C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x8210b56c
	if (ctx.cr0.lt) goto loc_8210B56C;
	// stw r30,0(r27)
	PPC_STORE_U32(ctx.r27.u32 + 0, ctx.r30.u32);
	// b 0x8210b580
	goto loc_8210B580;
loc_8210B56C:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210B580;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8210B580:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82108a28
	ctx.lr = 0x8210B588;
	sub_82108A28(ctx, base);
loc_8210B588:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210B594"))) PPC_WEAK_FUNC(sub_8210B594);
PPC_FUNC_IMPL(__imp__sub_8210B594) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210B598"))) PPC_WEAK_FUNC(sub_8210B598);
PPC_FUNC_IMPL(__imp__sub_8210B598) {
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
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x8210b048
	ctx.lr = 0x8210B5B8;
	sub_8210B048(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8210b5c8
	if (ctx.cr0.eq) goto loc_8210B5C8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82114628
	ctx.lr = 0x8210B5C8;
	sub_82114628(ctx, base);
loc_8210B5C8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
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

__attribute__((alias("__imp__sub_8210B5E4"))) PPC_WEAK_FUNC(sub_8210B5E4);
PPC_FUNC_IMPL(__imp__sub_8210B5E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210B5E8"))) PPC_WEAK_FUNC(sub_8210B5E8);
PPC_FUNC_IMPL(__imp__sub_8210B5E8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8210B5F0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r30,r11,-5536
	ctx.r30.s64 = ctx.r11.s64 + -5536;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82108990
	ctx.lr = 0x8210B608;
	sub_82108990(ctx, base);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8210b61c
	if (!ctx.cr6.eq) goto loc_8210B61C;
	// lis r31,-32768
	ctx.r31.s64 = -2147483648;
	// ori r31,r31,16387
	ctx.r31.u64 = ctx.r31.u64 | 16387;
	// b 0x8210b658
	goto loc_8210B658;
loc_8210B61C:
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// ori r5,r5,10
	ctx.r5.u64 = ctx.r5.u64 | 10;
	// li r4,104
	ctx.r4.s64 = 104;
	// bl 0x82108aa8
	ctx.lr = 0x8210B634;
	sub_82108AA8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8210b644
	if (ctx.cr0.eq) goto loc_8210B644;
	// bl 0x82113d38
	ctx.lr = 0x8210B640;
	sub_82113D38(ctx, base);
	// b 0x8210b648
	goto loc_8210B648;
loc_8210B644:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8210B648:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8210b66c
	if (ctx.cr6.eq) goto loc_8210B66C;
	// li r31,0
	ctx.r31.s64 = 0;
	// stw r3,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
loc_8210B658:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82108a28
	ctx.lr = 0x8210B660;
	sub_82108A28(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_8210B66C:
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,14
	ctx.r31.u64 = ctx.r31.u64 | 14;
	// b 0x8210b658
	goto loc_8210B658;
}

__attribute__((alias("__imp__sub_8210B678"))) PPC_WEAK_FUNC(sub_8210B678);
PPC_FUNC_IMPL(__imp__sub_8210B678) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8210B680;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r30,r11,-5536
	ctx.r30.s64 = ctx.r11.s64 + -5536;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82108990
	ctx.lr = 0x8210B698;
	sub_82108990(ctx, base);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8210b6ac
	if (!ctx.cr6.eq) goto loc_8210B6AC;
	// lis r31,-32768
	ctx.r31.s64 = -2147483648;
	// ori r31,r31,16387
	ctx.r31.u64 = ctx.r31.u64 | 16387;
	// b 0x8210b6e8
	goto loc_8210B6E8;
loc_8210B6AC:
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// ori r5,r5,10
	ctx.r5.u64 = ctx.r5.u64 | 10;
	// li r4,44
	ctx.r4.s64 = 44;
	// bl 0x82108aa8
	ctx.lr = 0x8210B6C4;
	sub_82108AA8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8210b6d4
	if (ctx.cr0.eq) goto loc_8210B6D4;
	// bl 0x82114388
	ctx.lr = 0x8210B6D0;
	sub_82114388(ctx, base);
	// b 0x8210b6d8
	goto loc_8210B6D8;
loc_8210B6D4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8210B6D8:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8210b6fc
	if (ctx.cr6.eq) goto loc_8210B6FC;
	// li r31,0
	ctx.r31.s64 = 0;
	// stw r3,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
loc_8210B6E8:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82108a28
	ctx.lr = 0x8210B6F0;
	sub_82108A28(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_8210B6FC:
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,14
	ctx.r31.u64 = ctx.r31.u64 | 14;
	// b 0x8210b6e8
	goto loc_8210B6E8;
}

__attribute__((alias("__imp__sub_8210B708"))) PPC_WEAK_FUNC(sub_8210B708);
PPC_FUNC_IMPL(__imp__sub_8210B708) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8210B710;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r30,r11,-5536
	ctx.r30.s64 = ctx.r11.s64 + -5536;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82108990
	ctx.lr = 0x8210B728;
	sub_82108990(ctx, base);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8210b73c
	if (!ctx.cr6.eq) goto loc_8210B73C;
	// lis r31,-32768
	ctx.r31.s64 = -2147483648;
	// ori r31,r31,16387
	ctx.r31.u64 = ctx.r31.u64 | 16387;
	// b 0x8210b778
	goto loc_8210B778;
loc_8210B73C:
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// ori r5,r5,10
	ctx.r5.u64 = ctx.r5.u64 | 10;
	// li r4,116
	ctx.r4.s64 = 116;
	// bl 0x82108aa8
	ctx.lr = 0x8210B754;
	sub_82108AA8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8210b764
	if (ctx.cr0.eq) goto loc_8210B764;
	// bl 0x82114928
	ctx.lr = 0x8210B760;
	sub_82114928(ctx, base);
	// b 0x8210b768
	goto loc_8210B768;
loc_8210B764:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8210B768:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8210b78c
	if (ctx.cr6.eq) goto loc_8210B78C;
	// li r31,0
	ctx.r31.s64 = 0;
	// stw r3,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
loc_8210B778:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82108a28
	ctx.lr = 0x8210B780;
	sub_82108A28(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_8210B78C:
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,14
	ctx.r31.u64 = ctx.r31.u64 | 14;
	// b 0x8210b778
	goto loc_8210B778;
}

__attribute__((alias("__imp__sub_8210B798"))) PPC_WEAK_FUNC(sub_8210B798);
PPC_FUNC_IMPL(__imp__sub_8210B798) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8210B7A0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r30,r11,-5536
	ctx.r30.s64 = ctx.r11.s64 + -5536;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82108990
	ctx.lr = 0x8210B7B8;
	sub_82108990(ctx, base);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8210b7cc
	if (!ctx.cr6.eq) goto loc_8210B7CC;
	// lis r31,-32768
	ctx.r31.s64 = -2147483648;
	// ori r31,r31,16387
	ctx.r31.u64 = ctx.r31.u64 | 16387;
	// b 0x8210b808
	goto loc_8210B808;
loc_8210B7CC:
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// ori r5,r5,10
	ctx.r5.u64 = ctx.r5.u64 | 10;
	// li r4,264
	ctx.r4.s64 = 264;
	// bl 0x82108aa8
	ctx.lr = 0x8210B7E4;
	sub_82108AA8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8210b7f4
	if (ctx.cr0.eq) goto loc_8210B7F4;
	// bl 0x82116098
	ctx.lr = 0x8210B7F0;
	sub_82116098(ctx, base);
	// b 0x8210b7f8
	goto loc_8210B7F8;
loc_8210B7F4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8210B7F8:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8210b81c
	if (ctx.cr6.eq) goto loc_8210B81C;
	// li r31,0
	ctx.r31.s64 = 0;
	// stw r3,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
loc_8210B808:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82108a28
	ctx.lr = 0x8210B810;
	sub_82108A28(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_8210B81C:
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,14
	ctx.r31.u64 = ctx.r31.u64 | 14;
	// b 0x8210b808
	goto loc_8210B808;
}

__attribute__((alias("__imp__sub_8210B828"))) PPC_WEAK_FUNC(sub_8210B828);
PPC_FUNC_IMPL(__imp__sub_8210B828) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8210B830;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r30,r11,-5536
	ctx.r30.s64 = ctx.r11.s64 + -5536;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82108990
	ctx.lr = 0x8210B848;
	sub_82108990(ctx, base);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8210b85c
	if (!ctx.cr6.eq) goto loc_8210B85C;
	// lis r31,-32768
	ctx.r31.s64 = -2147483648;
	// ori r31,r31,16387
	ctx.r31.u64 = ctx.r31.u64 | 16387;
	// b 0x8210b898
	goto loc_8210B898;
loc_8210B85C:
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// ori r5,r5,10
	ctx.r5.u64 = ctx.r5.u64 | 10;
	// li r4,60
	ctx.r4.s64 = 60;
	// bl 0x82108aa8
	ctx.lr = 0x8210B874;
	sub_82108AA8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8210b884
	if (ctx.cr0.eq) goto loc_8210B884;
	// bl 0x82116e30
	ctx.lr = 0x8210B880;
	sub_82116E30(ctx, base);
	// b 0x8210b888
	goto loc_8210B888;
loc_8210B884:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8210B888:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8210b8ac
	if (ctx.cr6.eq) goto loc_8210B8AC;
	// li r31,0
	ctx.r31.s64 = 0;
	// stw r3,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
loc_8210B898:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82108a28
	ctx.lr = 0x8210B8A0;
	sub_82108A28(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_8210B8AC:
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,14
	ctx.r31.u64 = ctx.r31.u64 | 14;
	// b 0x8210b898
	goto loc_8210B898;
}

__attribute__((alias("__imp__sub_8210B8B8"))) PPC_WEAK_FUNC(sub_8210B8B8);
PPC_FUNC_IMPL(__imp__sub_8210B8B8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8210B8C0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r30,r11,-5536
	ctx.r30.s64 = ctx.r11.s64 + -5536;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82108990
	ctx.lr = 0x8210B8D8;
	sub_82108990(ctx, base);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8210b8ec
	if (!ctx.cr6.eq) goto loc_8210B8EC;
	// lis r31,-32768
	ctx.r31.s64 = -2147483648;
	// ori r31,r31,16387
	ctx.r31.u64 = ctx.r31.u64 | 16387;
	// b 0x8210b928
	goto loc_8210B928;
loc_8210B8EC:
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// ori r5,r5,10
	ctx.r5.u64 = ctx.r5.u64 | 10;
	// li r4,236
	ctx.r4.s64 = 236;
	// bl 0x82108aa8
	ctx.lr = 0x8210B904;
	sub_82108AA8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8210b914
	if (ctx.cr0.eq) goto loc_8210B914;
	// bl 0x82117790
	ctx.lr = 0x8210B910;
	sub_82117790(ctx, base);
	// b 0x8210b918
	goto loc_8210B918;
loc_8210B914:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8210B918:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8210b93c
	if (ctx.cr6.eq) goto loc_8210B93C;
	// li r31,0
	ctx.r31.s64 = 0;
	// stw r3,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
loc_8210B928:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82108a28
	ctx.lr = 0x8210B930;
	sub_82108A28(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_8210B93C:
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,14
	ctx.r31.u64 = ctx.r31.u64 | 14;
	// b 0x8210b928
	goto loc_8210B928;
}

__attribute__((alias("__imp__sub_8210B948"))) PPC_WEAK_FUNC(sub_8210B948);
PPC_FUNC_IMPL(__imp__sub_8210B948) {
	PPC_FUNC_PROLOGUE();
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// b 0x82088c48
	sub_82088C48(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210B954"))) PPC_WEAK_FUNC(sub_8210B954);
PPC_FUNC_IMPL(__imp__sub_8210B954) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210B958"))) PPC_WEAK_FUNC(sub_8210B958);
PPC_FUNC_IMPL(__imp__sub_8210B958) {
	PPC_FUNC_PROLOGUE();
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// b 0x82088ce0
	sub_82088CE0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210B964"))) PPC_WEAK_FUNC(sub_8210B964);
PPC_FUNC_IMPL(__imp__sub_8210B964) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210B968"))) PPC_WEAK_FUNC(sub_8210B968);
PPC_FUNC_IMPL(__imp__sub_8210B968) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8210B970;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r28,r11,-5536
	ctx.r28.s64 = ctx.r11.s64 + -5536;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82108990
	ctx.lr = 0x8210B988;
	sub_82108990(ctx, base);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8210b99c
	if (!ctx.cr6.eq) goto loc_8210B99C;
	// lis r30,-32768
	ctx.r30.s64 = -2147483648;
	// ori r30,r30,16387
	ctx.r30.u64 = ctx.r30.u64 | 16387;
	// b 0x8210ba14
	goto loc_8210BA14;
loc_8210B99C:
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// ori r5,r5,6
	ctx.r5.u64 = ctx.r5.u64 | 6;
	// li r4,388
	ctx.r4.s64 = 388;
	// bl 0x82108aa8
	ctx.lr = 0x8210B9B4;
	sub_82108AA8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8210b9c8
	if (ctx.cr0.eq) goto loc_8210B9C8;
	// bl 0x82118c08
	ctx.lr = 0x8210B9C0;
	sub_82118C08(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x8210b9cc
	goto loc_8210B9CC;
loc_8210B9C8:
	// li r31,0
	ctx.r31.s64 = 0;
loc_8210B9CC:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8210b9e0
	if (!ctx.cr6.eq) goto loc_8210B9E0;
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,14
	ctx.r30.u64 = ctx.r30.u64 | 14;
	// b 0x8210ba14
	goto loc_8210BA14;
loc_8210B9E0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82117c48
	ctx.lr = 0x8210B9E8;
	sub_82117C48(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x8210b9f8
	if (ctx.cr0.lt) goto loc_8210B9F8;
	// stw r31,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r31.u32);
	// b 0x8210ba14
	goto loc_8210BA14;
loc_8210B9F8:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,12(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210BA10;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x82114628
	ctx.lr = 0x8210BA14;
	sub_82114628(ctx, base);
loc_8210BA14:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82108a28
	ctx.lr = 0x8210BA1C;
	sub_82108A28(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210BA28"))) PPC_WEAK_FUNC(sub_8210BA28);
PPC_FUNC_IMPL(__imp__sub_8210BA28) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8210BA30;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210BA50;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt 0x8210ba70
	if (ctx.cr0.lt) goto loc_8210BA70;
	// stw r30,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210BA70;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8210BA70:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210BA7C"))) PPC_WEAK_FUNC(sub_8210BA7C);
PPC_FUNC_IMPL(__imp__sub_8210BA7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210BA80"))) PPC_WEAK_FUNC(sub_8210BA80);
PPC_FUNC_IMPL(__imp__sub_8210BA80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// cmplwi cr6,r4,22125
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 22125, ctx.xer);
	// bne cr6,0x8210ba90
	if (!ctx.cr6.eq) goto loc_8210BA90;
	// li r3,3
	ctx.r3.s64 = 3;
	// blr 
	return;
loc_8210BA90:
	// cmplwi cr6,r4,43875
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 43875, ctx.xer);
	// bne cr6,0x8210baa0
	if (!ctx.cr6.eq) goto loc_8210BAA0;
	// li r3,6
	ctx.r3.s64 = 6;
	// blr 
	return;
loc_8210BAA0:
	// cmplwi cr6,r4,48000
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 48000, ctx.xer);
	// bne cr6,0x8210bab0
	if (!ctx.cr6.eq) goto loc_8210BAB0;
	// li r3,7
	ctx.r3.s64 = 7;
	// blr 
	return;
loc_8210BAB0:
	// cmplwi cr6,r4,11250
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 11250, ctx.xer);
	// bne cr6,0x8210bac0
	if (!ctx.cr6.eq) goto loc_8210BAC0;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8210BAC0:
	// cmplwi cr6,r4,32250
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 32250, ctx.xer);
	// bne cr6,0x8210bad0
	if (!ctx.cr6.eq) goto loc_8210BAD0;
	// li r3,5
	ctx.r3.s64 = 5;
	// blr 
	return;
loc_8210BAD0:
	// cmplwi cr6,r4,24000
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 24000, ctx.xer);
	// bne cr6,0x8210bae0
	if (!ctx.cr6.eq) goto loc_8210BAE0;
	// li r3,4
	ctx.r3.s64 = 4;
	// blr 
	return;
loc_8210BAE0:
	// cmplwi cr6,r4,16125
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 16125, ctx.xer);
	// bne cr6,0x8210baf0
	if (!ctx.cr6.eq) goto loc_8210BAF0;
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
loc_8210BAF0:
	// addi r11,r4,-8250
	ctx.r11.s64 = ctx.r4.s64 + -8250;
	// li r10,8
	ctx.r10.s64 = 8;
	// subfic r11,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r11.s64 = 0 - ctx.r11.s64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 & ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8210BB08"))) PPC_WEAK_FUNC(sub_8210BB08);
PPC_FUNC_IMPL(__imp__sub_8210BB08) {
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
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// clrlwi r6,r4,16
	ctx.r6.u64 = ctx.r4.u32 & 0xFFFF;
	// li r11,128
	ctx.r11.s64 = 128;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// sth r11,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r11.u16);
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,40
	ctx.r4.s64 = 40;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82112a78
	ctx.lr = 0x8210BB48;
	sub_82112A78(ctx, base);
	// lis r11,32767
	ctx.r11.s64 = 2147418112;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// ori r11,r11,65535
	ctx.r11.u64 = ctx.r11.u64 | 65535;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210BB70;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
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

__attribute__((alias("__imp__sub_8210BB88"))) PPC_WEAK_FUNC(sub_8210BB88);
PPC_FUNC_IMPL(__imp__sub_8210BB88) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,204(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 204);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8210bbdc
	if (ctx.cr6.eq) goto loc_8210BBDC;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stw r9,204(r11)
	PPC_STORE_U32(ctx.r11.u32 + 204, ctx.r9.u32);
	// beq cr6,0x8210bbb8
	if (ctx.cr6.eq) goto loc_8210BBB8;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r8,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r8.u32);
	// b 0x8210bbc0
	goto loc_8210BBC0;
loc_8210BBB8:
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,208(r11)
	PPC_STORE_U32(ctx.r11.u32 + 208, ctx.r9.u32);
loc_8210BBC0:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r9,212(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 212);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// addi r10,r9,-1
	ctx.r10.s64 = ctx.r9.s64 + -1;
	// stw r10,212(r11)
	PPC_STORE_U32(ctx.r11.u32 + 212, ctx.r10.u32);
	// blr 
	return;
loc_8210BBDC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8210BBE4"))) PPC_WEAK_FUNC(sub_8210BBE4);
PPC_FUNC_IMPL(__imp__sub_8210BBE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210BBE8"))) PPC_WEAK_FUNC(sub_8210BBE8);
PPC_FUNC_IMPL(__imp__sub_8210BBE8) {
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
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// lis r8,32767
	ctx.r8.s64 = 2147418112;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// ori r31,r8,65535
	ctx.r31.u64 = ctx.r8.u64 | 65535;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm r10,r9,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// xori r9,r9,1
	ctx.r9.u64 = ctx.r9.u64 ^ 1;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// addi r30,r10,4
	ctx.r30.s64 = ctx.r10.s64 + 4;
	// lwz r11,8(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmpw cr6,r11,r31
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r31.s32, ctx.xer);
	// bne cr6,0x8210bc50
	if (!ctx.cr6.eq) goto loc_8210BC50;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// bl 0x8210bb08
	ctx.lr = 0x8210BC3C;
	sub_8210BB08(ctx, base);
	// cmpw cr6,r3,r31
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r31.s32, ctx.xer);
	// bne cr6,0x8210bc4c
	if (!ctx.cr6.eq) goto loc_8210BC4C;
	// li r30,0
	ctx.r30.s64 = 0;
	// b 0x8210bc50
	goto loc_8210BC50;
loc_8210BC4C:
	// stw r3,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r3.u32);
loc_8210BC50:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
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

__attribute__((alias("__imp__sub_8210BC6C"))) PPC_WEAK_FUNC(sub_8210BC6C);
PPC_FUNC_IMPL(__imp__sub_8210BC6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210BC70"))) PPC_WEAK_FUNC(sub_8210BC70);
PPC_FUNC_IMPL(__imp__sub_8210BC70) {
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
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x821096d8
	ctx.lr = 0x8210BC90;
	sub_821096D8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8210bcd4
	if (ctx.cr0.eq) goto loc_8210BCD4;
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r10,204(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 204);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// lwz r11,204(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 204);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210bcc0
	if (ctx.cr6.eq) goto loc_8210BCC0;
	// stw r3,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r3.u32);
	// b 0x8210bcc4
	goto loc_8210BCC4;
loc_8210BCC0:
	// stw r3,208(r31)
	PPC_STORE_U32(ctx.r31.u32 + 208, ctx.r3.u32);
loc_8210BCC4:
	// lwz r11,212(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 212);
	// stw r3,204(r31)
	PPC_STORE_U32(ctx.r31.u32 + 204, ctx.r3.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,212(r31)
	PPC_STORE_U32(ctx.r31.u32 + 212, ctx.r11.u32);
loc_8210BCD4:
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

__attribute__((alias("__imp__sub_8210BCEC"))) PPC_WEAK_FUNC(sub_8210BCEC);
PPC_FUNC_IMPL(__imp__sub_8210BCEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210BCF0"))) PPC_WEAK_FUNC(sub_8210BCF0);
PPC_FUNC_IMPL(__imp__sub_8210BCF0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x8210BCF8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,32767
	ctx.r11.s64 = 2147418112;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// addi r31,r4,8
	ctx.r31.s64 = ctx.r4.s64 + 8;
	// li r30,2
	ctx.r30.s64 = 2;
	// ori r28,r11,65535
	ctx.r28.u64 = ctx.r11.u64 | 65535;
loc_8210BD14:
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpw cr6,r4,r28
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r28.s32, ctx.xer);
	// beq cr6,0x8210bd34
	if (ctx.cr6.eq) goto loc_8210BD34;
	// lwz r3,0(r27)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,36(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210BD34;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8210BD34:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// bne 0x8210bd14
	if (!ctx.cr0.eq) goto loc_8210BD14;
	// addi r30,r29,20
	ctx.r30.s64 = ctx.r29.s64 + 20;
	// b 0x8210bd70
	goto loc_8210BD70;
loc_8210BD48:
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpw cr6,r4,r28
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r28.s32, ctx.xer);
	// beq cr6,0x8210bd68
	if (ctx.cr6.eq) goto loc_8210BD68;
	// lwz r3,0(r27)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,36(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210BD68;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8210BD68:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82114628
	ctx.lr = 0x8210BD70;
	sub_82114628(ctx, base);
loc_8210BD70:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8210bb88
	ctx.lr = 0x8210BD78;
	sub_8210BB88(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x8210bd48
	if (!ctx.cr0.eq) goto loc_8210BD48;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210BD88"))) PPC_WEAK_FUNC(sub_8210BD88);
PPC_FUNC_IMPL(__imp__sub_8210BD88) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x8210BD90;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,32767
	ctx.r10.s64 = 2147418112;
	// lwz r11,224(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 224);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r26,r7
	ctx.r26.u64 = ctx.r7.u64;
	// ori r30,r10,65535
	ctx.r30.u64 = ctx.r10.u64 | 65535;
	// b 0x8210bde0
	goto loc_8210BDE0;
loc_8210BDB8:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210bdd0
	if (ctx.cr6.eq) goto loc_8210BDD0;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r31,0(r10)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x8210bdd4
	goto loc_8210BDD4;
loc_8210BDD0:
	// li r31,0
	ctx.r31.s64 = 0;
loc_8210BDD4:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8210bdec
	if (ctx.cr6.eq) goto loc_8210BDEC;
loc_8210BDE0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8210bdb8
	if (!ctx.cr6.eq) goto loc_8210BDB8;
	// b 0x8210be1c
	goto loc_8210BE1C;
loc_8210BDEC:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpw cr6,r11,r30
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r30.s32, ctx.xer);
	// bne cr6,0x8210be10
	if (!ctx.cr6.eq) goto loc_8210BE10;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8210bb08
	ctx.lr = 0x8210BE0C;
	sub_8210BB08(ctx, base);
	// stw r3,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
loc_8210BE10:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpw cr6,r11,r30
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r30.s32, ctx.xer);
	// bne cr6,0x8210be9c
	if (!ctx.cr6.eq) goto loc_8210BE9C;
loc_8210BE1C:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,-5536
	ctx.r3.s64 = ctx.r11.s64 + -5536;
	// ori r5,r5,3
	ctx.r5.u64 = ctx.r5.u64 | 3;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x82108aa8
	ctx.lr = 0x8210BE38;
	sub_82108AA8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8210be54
	if (ctx.cr0.eq) goto loc_8210BE54;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// b 0x8210be58
	goto loc_8210BE58;
loc_8210BE54:
	// li r31,0
	ctx.r31.s64 = 0;
loc_8210BE58:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8210be9c
	if (ctx.cr6.eq) goto loc_8210BE9C;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r25,20
	ctx.r3.s64 = ctx.r25.s64 + 20;
	// bl 0x8210bc70
	ctx.lr = 0x8210BE6C;
	sub_8210BC70(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8210be84
	if (!ctx.cr0.eq) goto loc_8210BE84;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82114628
	ctx.lr = 0x8210BE7C;
	sub_82114628(ctx, base);
	// li r31,0
	ctx.r31.s64 = 0;
	// b 0x8210be9c
	goto loc_8210BE9C;
loc_8210BE84:
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8210bb08
	ctx.lr = 0x8210BE98;
	sub_8210BB08(ctx, base);
	// stw r3,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
loc_8210BE9C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210BEA8"))) PPC_WEAK_FUNC(sub_8210BEA8);
PPC_FUNC_IMPL(__imp__sub_8210BEA8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8210BEB0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210bf4c
	if (ctx.cr6.eq) goto loc_8210BF4C;
	// addi r31,r3,40
	ctx.r31.s64 = ctx.r3.s64 + 40;
	// li r29,8
	ctx.r29.s64 = 8;
loc_8210BECC:
	// li r30,8
	ctx.r30.s64 = 8;
loc_8210BED0:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8210bcf0
	ctx.lr = 0x8210BEDC;
	sub_8210BCF0(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r31,r31,240
	ctx.r31.s64 = ctx.r31.s64 + 240;
	// bne 0x8210bed0
	if (!ctx.cr0.eq) goto loc_8210BED0;
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne 0x8210becc
	if (!ctx.cr0.eq) goto loc_8210BECC;
	// addi r29,r28,15400
	ctx.r29.s64 = ctx.r28.s64 + 15400;
	// b 0x8210bf20
	goto loc_8210BF20;
loc_8210BEF8:
	// addi r30,r31,12
	ctx.r30.s64 = ctx.r31.s64 + 12;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8210bcf0
	ctx.lr = 0x8210BF08;
	sub_8210BCF0(ctx, base);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8210bf20
	if (ctx.cr6.eq) goto loc_8210BF20;
	// addi r3,r30,20
	ctx.r3.s64 = ctx.r30.s64 + 20;
	// bl 0x82118a58
	ctx.lr = 0x8210BF18;
	sub_82118A58(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82114628
	ctx.lr = 0x8210BF20;
	sub_82114628(ctx, base);
loc_8210BF20:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82109678
	ctx.lr = 0x8210BF28;
	sub_82109678(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x8210bef8
	if (!ctx.cr0.eq) goto loc_8210BEF8;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210BF44;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
loc_8210BF4C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210BF54"))) PPC_WEAK_FUNC(sub_8210BF54);
PPC_FUNC_IMPL(__imp__sub_8210BF54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210BF58"))) PPC_WEAK_FUNC(sub_8210BF58);
PPC_FUNC_IMPL(__imp__sub_8210BF58) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c974
	ctx.lr = 0x8210BF60;
	__savegprlr_23(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r24,r3,4
	ctx.r24.s64 = ctx.r3.s64 + 4;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// mr r23,r4
	ctx.r23.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mr r26,r6
	ctx.r26.u64 = ctx.r6.u64;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210BF90;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r25,0
	ctx.r25.s64 = 0;
	// li r28,0
	ctx.r28.s64 = 0;
	// bl 0x8210ba80
	ctx.lr = 0x8210BFA4;
	sub_8210BA80(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,8
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 8, ctx.xer);
	// beq cr6,0x8210bfe0
	if (ctx.cr6.eq) goto loc_8210BFE0;
	// cmplwi cr6,r29,8
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 8, ctx.xer);
	// bgt cr6,0x8210bfe0
	if (ctx.cr6.gt) goto loc_8210BFE0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82112138
	ctx.lr = 0x8210BFC0;
	sub_82112138(ctx, base);
	// cmplw cr6,r26,r3
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r3.u32, ctx.xer);
	// bne cr6,0x8210bfe0
	if (!ctx.cr6.eq) goto loc_8210BFE0;
	// rlwinm r11,r29,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// mulli r11,r11,240
	ctx.r11.s64 = ctx.r11.s64 * 240;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r28,r11,-1880
	ctx.r28.s64 = ctx.r11.s64 + -1880;
	// b 0x8210c0b4
	goto loc_8210C0B4;
loc_8210BFE0:
	// lwz r10,15424(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 15424);
	// b 0x8210c028
	goto loc_8210C028;
loc_8210BFE8:
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8210c000
	if (ctx.cr6.eq) goto loc_8210C000;
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x8210c004
	goto loc_8210C004;
loc_8210C000:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8210C004:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r9,r29
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x8210c028
	if (!ctx.cr6.eq) goto loc_8210C028;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplw cr6,r9,r26
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r26.u32, ctx.xer);
	// bne cr6,0x8210c028
	if (!ctx.cr6.eq) goto loc_8210C028;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// cmplw cr6,r9,r27
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r27.u32, ctx.xer);
	// beq cr6,0x8210c034
	if (ctx.cr6.eq) goto loc_8210C034;
loc_8210C028:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8210bfe8
	if (!ctx.cr6.eq) goto loc_8210BFE8;
	// b 0x8210c03c
	goto loc_8210C03C;
loc_8210C034:
	// addic. r28,r11,12
	ctx.xer.ca = ctx.r11.u32 > 4294967283;
	ctx.r28.s64 = ctx.r11.s64 + 12;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bne 0x8210c0bc
	if (!ctx.cr0.eq) goto loc_8210C0BC;
loc_8210C03C:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,-5536
	ctx.r3.s64 = ctx.r11.s64 + -5536;
	// ori r5,r5,3
	ctx.r5.u64 = ctx.r5.u64 | 3;
	// li r4,252
	ctx.r4.s64 = 252;
	// bl 0x82108aa8
	ctx.lr = 0x8210C058;
	sub_82108AA8(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x8210c078
	if (ctx.cr0.eq) goto loc_8210C078;
	// stw r29,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// addi r3,r31,12
	ctx.r3.s64 = ctx.r31.s64 + 12;
	// stw r26,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r26.u32);
	// stw r27,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r27.u32);
	// bl 0x8210a938
	ctx.lr = 0x8210C074;
	sub_8210A938(ctx, base);
	// b 0x8210c07c
	goto loc_8210C07C;
loc_8210C078:
	// li r31,0
	ctx.r31.s64 = 0;
loc_8210C07C:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8210c10c
	if (ctx.cr6.eq) goto loc_8210C10C;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r30,15400
	ctx.r3.s64 = ctx.r30.s64 + 15400;
	// bl 0x821098d8
	ctx.lr = 0x8210C090;
	sub_821098D8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8210c0a0
	if (ctx.cr0.eq) goto loc_8210C0A0;
	// addi r28,r31,12
	ctx.r28.s64 = ctx.r31.s64 + 12;
	// b 0x8210c0b4
	goto loc_8210C0B4;
loc_8210C0A0:
	// addi r11,r31,12
	ctx.r11.s64 = ctx.r31.s64 + 12;
	// addi r3,r11,20
	ctx.r3.s64 = ctx.r11.s64 + 20;
	// bl 0x82118a58
	ctx.lr = 0x8210C0AC;
	sub_82118A58(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82114628
	ctx.lr = 0x8210C0B4;
	sub_82114628(ctx, base);
loc_8210C0B4:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8210c10c
	if (ctx.cr6.eq) goto loc_8210C10C;
loc_8210C0BC:
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bne cr6,0x8210c0e4
	if (!ctx.cr6.eq) goto loc_8210C0E4;
	// bl 0x8210bbe8
	ctx.lr = 0x8210C0DC;
	sub_8210BBE8(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// b 0x8210c10c
	goto loc_8210C10C;
loc_8210C0E4:
	// bl 0x8210bd88
	ctx.lr = 0x8210C0E8;
	sub_8210BD88(ctx, base);
	// mr. r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq 0x8210c10c
	if (ctx.cr0.eq) goto loc_8210C10C;
loc_8210C0F0:
	// mfmsr r10
	ctx.r10.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r11,0,r25
	ctx.reserved.u32 = *(uint32_t*)(base + ctx.r25.u32);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwcx. r11,0,r25
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + ctx.r25.u32), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x8210c0f0
	if (!ctx.cr0.eq) goto loc_8210C0F0;
loc_8210C10C:
	// lwz r11,0(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210C120;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210C12C"))) PPC_WEAK_FUNC(sub_8210C12C);
PPC_FUNC_IMPL(__imp__sub_8210C12C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210C130"))) PPC_WEAK_FUNC(sub_8210C130);
PPC_FUNC_IMPL(__imp__sub_8210C130) {
	PPC_FUNC_PROLOGUE();
	// lis r11,32746
	ctx.r11.s64 = 2146041856;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// ori r11,r11,6144
	ctx.r11.u64 = ctx.r11.u64 | 6144;
	// lwbrx r11,0,r11
	ctx.r11.u64 = __builtin_bswap32(PPC_LOAD_U32(ctx.r11.u32));
	// stw r11,-5408(r10)
	PPC_STORE_U32(ctx.r10.u32 + -5408, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8210C148"))) PPC_WEAK_FUNC(sub_8210C148);
PPC_FUNC_IMPL(__imp__sub_8210C148) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mulli r11,r3,96
	ctx.r11.s64 = ctx.r3.s64 * 96;
	// addi r11,r11,143
	ctx.r11.s64 = ctx.r11.s64 + 143;
	// li r10,0
	ctx.r10.s64 = 0;
	// rlwinm r8,r11,0,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8210c184
	if (ctx.cr6.eq) goto loc_8210C184;
	// addi r11,r4,-8
	ctx.r11.s64 = ctx.r4.s64 + -8;
	// mtctr r3
	ctx.ctr.u64 = ctx.r3.u64;
loc_8210C168:
	// lbz r7,16(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 16);
	// lwzu r9,12(r11)
	ea = 12 + ctx.r11.u32;
	ctx.r9.u64 = PPC_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// addi r9,r9,128
	ctx.r9.s64 = ctx.r9.s64 + 128;
	// mullw r9,r9,r7
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r7.s32);
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// bdnz 0x8210c168
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8210C168;
loc_8210C184:
	// add r3,r10,r8
	ctx.r3.u64 = ctx.r10.u64 + ctx.r8.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8210C18C"))) PPC_WEAK_FUNC(sub_8210C18C);
PPC_FUNC_IMPL(__imp__sub_8210C18C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210C190"))) PPC_WEAK_FUNC(sub_8210C190);
PPC_FUNC_IMPL(__imp__sub_8210C190) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c974
	ctx.lr = 0x8210C198;
	__savegprlr_23(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r23,0
	ctx.r23.s64 = 0;
	// li r25,0
	ctx.r25.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x8210c288
	if (!ctx.cr6.gt) goto loc_8210C288;
	// li r28,0
	ctx.r28.s64 = 0;
	// li r26,16
	ctx.r26.s64 = 16;
	// li r27,32
	ctx.r27.s64 = 32;
	// lis r24,-32225
	ctx.r24.s64 = -2111897600;
loc_8210C1C4:
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// add r31,r28,r11
	ctx.r31.u64 = ctx.r28.u64 + ctx.r11.u64;
	// addi r30,r31,64
	ctx.r30.s64 = ctx.r31.s64 + 64;
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8210c274
	if (!ctx.cr6.eq) goto loc_8210C274;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821d5b74
	ctx.lr = 0x8210C1E4;
	__imp__XMACreateContext(ctx, base);
	// mr. r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// blt 0x8210c294
	if (ctx.cr0.lt) goto loc_8210C294;
	// lwz r11,4(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// rlwinm. r11,r11,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8210c234
	if (ctx.cr0.eq) goto loc_8210C234;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r31,r26
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r31.u32 + ctx.r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r31,r27
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r31.u32 + ctx.r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r26
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r11.u32 + ctx.r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r27
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r11.u32 + ctx.r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x821d5994
	ctx.lr = 0x8210C21C;
	__imp__MmGetPhysicalAddress(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,1028
	ctx.r6.s64 = 1028;
	// li r5,64
	ctx.r5.s64 = 64;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x821d5b64
	ctx.lr = 0x8210C230;
	__imp__MmMapIoSpace(ctx, base);
	// stw r3,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r3.u32);
loc_8210C234:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x821d5994
	ctx.lr = 0x8210C23C;
	__imp__MmGetPhysicalAddress(ctx, base);
	// lwz r11,-5408(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + -5408);
	// li r10,1
	ctx.r10.s64 = 1;
	// subf r11,r11,r3
	ctx.r11.s64 = ctx.r3.s64 - ctx.r11.s64;
	// srawi r11,r11,6
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3F) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 6;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// rlwinm r9,r11,27,21,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x7FF;
	// sth r11,80(r31)
	PPC_STORE_U16(ctx.r31.u32 + 80, ctx.r11.u16);
	// clrlwi r11,r11,27
	ctx.r11.u64 = ctx.r11.u32 & 0x1F;
	// addis r9,r9,8187
	ctx.r9.s64 = ctx.r9.s64 + 536543232;
	// slw r11,r10,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r11.u8 & 0x3F));
	// addi r9,r9,-31072
	ctx.r9.s64 = ctx.r9.s64 + -31072;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stwbrx r11,0,r10
	PPC_MM_STORE_U32(ctx.r10.u32, __builtin_bswap32(ctx.r11.u32));
	// eieio 
loc_8210C274:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// addi r28,r28,96
	ctx.r28.s64 = ctx.r28.s64 + 96;
	// cmplw cr6,r25,r11
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8210c1c4
	if (ctx.cr6.lt) goto loc_8210C1C4;
loc_8210C288:
	// lwz r11,4(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// oris r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 262144;
	// stw r11,4(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4, ctx.r11.u32);
loc_8210C294:
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210C2A0"))) PPC_WEAK_FUNC(sub_8210C2A0);
PPC_FUNC_IMPL(__imp__sub_8210C2A0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8210C2A8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x8210c300
	if (!ctx.cr6.gt) goto loc_8210C300;
	// li r30,0
	ctx.r30.s64 = 0;
loc_8210C2C4:
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// lwz r3,64(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8210c2ec
	if (ctx.cr6.eq) goto loc_8210C2EC;
	// bl 0x821d5b84
	ctx.lr = 0x8210C2DC;
	__imp__XMAReleaseContext(ctx, base);
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r10,0
	ctx.r10.s64 = 0;
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_8210C2EC:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r30,r30,96
	ctx.r30.s64 = ctx.r30.s64 + 96;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8210c2c4
	if (ctx.cr6.lt) goto loc_8210C2C4;
loc_8210C300:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r3,0
	ctx.r3.s64 = 0;
	// rlwinm r11,r11,0,14,12
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFBFFFF;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210C318"))) PPC_WEAK_FUNC(sub_8210C318);
PPC_FUNC_IMPL(__imp__sub_8210C318) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm. r11,r11,0,14,14
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8210c334
	if (ctx.cr0.eq) goto loc_8210C334;
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mulli r10,r4,96
	ctx.r10.s64 = ctx.r4.s64 * 96;
	// lwzx r11,r10,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// b 0x8210c348
	goto loc_8210C348;
loc_8210C334:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mulli r11,r4,96
	ctx.r11.s64 = ctx.r4.s64 * 96;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r11,64(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
loc_8210C348:
	// rlwinm r11,r11,12,30,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 12) & 0x3;
	// addi r11,r11,0
	ctx.r11.s64 = ctx.r11.s64 + 0;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8210C35C"))) PPC_WEAK_FUNC(sub_8210C35C);
PPC_FUNC_IMPL(__imp__sub_8210C35C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210C360"))) PPC_WEAK_FUNC(sub_8210C360);
PPC_FUNC_IMPL(__imp__sub_8210C360) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm. r11,r11,0,14,14
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// mulli r11,r4,96
	ctx.r11.s64 = ctx.r4.s64 * 96;
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// bne 0x8210c380
	if (!ctx.cr0.eq) goto loc_8210C380;
	// lwz r11,64(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 64);
loc_8210C380:
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// rlwinm. r10,r7,0,0,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8210c3bc
	if (ctx.cr0.eq) goto loc_8210C3BC;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,36(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// rlwinm r10,r9,5,27,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0x1F;
	// clrlwi r11,r11,27
	ctx.r11.u64 = ctx.r11.u32 & 0x1F;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8210c3ac
	if (ctx.cr6.lt) goto loc_8210C3AC;
	// subf r11,r11,r10
	ctx.r11.s64 = ctx.r10.s64 - ctx.r11.s64;
	// b 0x8210c3c4
	goto loc_8210C3C4;
loc_8210C3AC:
	// rlwinm r9,r9,10,27,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 10) & 0x1F;
	// subf r11,r11,r9
	ctx.r11.s64 = ctx.r9.s64 - ctx.r11.s64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x8210c3c4
	goto loc_8210C3C4;
loc_8210C3BC:
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm r11,r11,10,27,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 10) & 0x1F;
loc_8210C3C4:
	// rlwinm r10,r11,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// lhz r9,82(r8)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r8.u32 + 82);
	// rlwinm r11,r7,3,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0x1;
	// subf r10,r9,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r9.s64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// srw r3,r10,r11
	ctx.r3.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r11.u8 & 0x3F));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8210C3E0"))) PPC_WEAK_FUNC(sub_8210C3E0);
PPC_FUNC_IMPL(__imp__sub_8210C3E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x8210C3E8;
	__savegprlr_27(ctx, base);
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mulli r30,r4,96
	ctx.r30.s64 = ctx.r4.s64 * 96;
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// li r28,1
	ctx.r28.s64 = 1;
	// lis r27,-32768
	ctx.r27.s64 = -2147483648;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r31,0
	ctx.r31.s64 = 0;
	// lwz r9,36(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// rlwinm r8,r9,8,19,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0x1F00;
	// lhz r9,82(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 82);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r10,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r10.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// rlwinm r10,r10,3,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0x1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// slw r10,r5,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r5.u32 << (ctx.r10.u8 & 0x3F));
	// beq 0x8210c4e0
	if (ctx.cr0.eq) goto loc_8210C4E0;
	// subfic r8,r9,256
	ctx.xer.ca = ctx.r9.u32 <= 256;
	ctx.r8.s64 = 256 - ctx.r9.s64;
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x8210c460
	if (!ctx.cr6.lt) goto loc_8210C460;
	// lwz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// add r8,r30,r8
	ctx.r8.u64 = ctx.r30.u64 + ctx.r8.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r9,82(r8)
	PPC_STORE_U16(ctx.r8.u32 + 82, ctx.r9.u16);
	// b 0x8210c4e0
	goto loc_8210C4E0;
loc_8210C460:
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// subf r7,r8,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r8.s64;
	// li r6,0
	ctx.r6.s64 = 0;
	// add r10,r30,r9
	ctx.r10.u64 = ctx.r30.u64 + ctx.r9.u64;
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// sth r6,82(r10)
	PPC_STORE_U16(ctx.r10.u32 + 82, ctx.r6.u16);
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r8,36(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// clrlwi r9,r8,27
	ctx.r9.u64 = ctx.r8.u32 & 0x1F;
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
	// rlwinm r6,r6,10,27,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 10) & 0x1F;
	// subfc r6,r6,r10
	ctx.xer.ca = ctx.r10.u32 >= ctx.r6.u32;
	ctx.r6.s64 = ctx.r10.s64 - ctx.r6.s64;
	// subfe r6,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ~ctx.r6.u64 + ctx.r6.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r10,r6,r10
	ctx.r10.u64 = ctx.r6.u64 & ctx.r10.u64;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8210c4ac
	if (ctx.cr6.eq) goto loc_8210C4AC;
	// rlwimi r8,r10,0,27,31
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r10.u32, 0) & 0x1F) | (ctx.r8.u64 & 0xFFFFFFFFFFFFFFE0);
	// stw r28,56(r11)
	PPC_STORE_U32(ctx.r11.u32 + 56, ctx.r28.u32);
	// stw r8,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r8.u32);
loc_8210C4AC:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// rlwinm r8,r9,0,0,0
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80000000;
	// cmplw cr6,r8,r27
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r27.u32, ctx.xer);
	// beq cr6,0x8210c4c8
	if (ctx.cr6.eq) goto loc_8210C4C8;
	// oris r9,r9,32768
	ctx.r9.u64 = ctx.r9.u64 | 2147483648;
	// stw r28,48(r11)
	PPC_STORE_U32(ctx.r11.u32 + 48, ctx.r28.u32);
	// stw r9,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
loc_8210C4C8:
	// addi r10,r10,0
	ctx.r10.s64 = ctx.r10.s64 + 0;
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r31,r10,27,31,31
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addic r10,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r10.s64 = ctx.r31.s64 + -1;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 & ctx.r7.u64;
loc_8210C4E0:
	// lwz r5,36(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// rlwinm r9,r10,24,8,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFFFFFF;
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// clrlwi r29,r10,24
	ctx.r29.u64 = ctx.r10.u32 & 0xFF;
	// clrlwi r10,r5,27
	ctx.r10.u64 = ctx.r5.u32 & 0x1F;
	// rlwinm r8,r6,5,27,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0x1F;
	// li r7,0
	ctx.r7.s64 = 0;
	// cmplw cr6,r8,r10
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x8210c520
	if (ctx.cr6.gt) goto loc_8210C520;
	// blt cr6,0x8210c51c
	if (ctx.cr6.lt) goto loc_8210C51C;
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// rlwinm. r8,r8,0,0,0
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x8210c51c
	if (ctx.cr0.eq) goto loc_8210C51C;
	// clrlwi. r8,r31,24
	ctx.r8.u64 = ctx.r31.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8210c524
	if (!ctx.cr0.eq) goto loc_8210C524;
loc_8210C51C:
	// rlwinm r8,r6,10,27,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 10) & 0x1F;
loc_8210C520:
	// subf r7,r10,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r10.s64;
loc_8210C524:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8210c588
	if (ctx.cr6.eq) goto loc_8210C588;
	// cmplw cr6,r9,r7
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, ctx.xer);
	// blt cr6,0x8210c538
	if (ctx.cr6.lt) goto loc_8210C538;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
loc_8210C538:
	// add r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r31,r6,10,27,31
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 10) & 0x1F;
	// rlwinm r6,r9,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// subfc r31,r31,r8
	ctx.xer.ca = ctx.r8.u32 >= ctx.r31.u32;
	ctx.r31.s64 = ctx.r8.s64 - ctx.r31.s64;
	// subf r7,r9,r7
	ctx.r7.s64 = ctx.r7.s64 - ctx.r9.s64;
	// subfe r9,r31,r31
	temp.u8 = (~ctx.r31.u32 + ctx.r31.u32 < ~ctx.r31.u32) | (~ctx.r31.u32 + ctx.r31.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r31.u64 + ctx.r31.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// add r4,r6,r4
	ctx.r4.u64 = ctx.r6.u64 + ctx.r4.u64;
	// and r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 & ctx.r8.u64;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x8210c56c
	if (ctx.cr6.eq) goto loc_8210C56C;
	// rlwimi r5,r9,0,27,31
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r9.u32, 0) & 0x1F) | (ctx.r5.u64 & 0xFFFFFFFFFFFFFFE0);
	// stw r28,56(r11)
	PPC_STORE_U32(ctx.r11.u32 + 56, ctx.r28.u32);
	// stw r5,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r5.u32);
loc_8210C56C:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// rlwinm r9,r10,0,0,0
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80000000;
	// cmplw cr6,r9,r27
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r27.u32, ctx.xer);
	// beq cr6,0x8210c588
	if (ctx.cr6.eq) goto loc_8210C588;
	// oris r10,r10,32768
	ctx.r10.u64 = ctx.r10.u64 | 2147483648;
	// stw r28,48(r11)
	PPC_STORE_U32(ctx.r11.u32 + 48, ctx.r28.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
loc_8210C588:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8210c5a8
	if (ctx.cr6.eq) goto loc_8210C5A8;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x8210c5a8
	if (ctx.cr6.eq) goto loc_8210C5A8;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// add r4,r29,r4
	ctx.r4.u64 = ctx.r29.u64 + ctx.r4.u64;
	// add r10,r30,r10
	ctx.r10.u64 = ctx.r30.u64 + ctx.r10.u64;
	// sth r29,82(r10)
	PPC_STORE_U16(ctx.r10.u32 + 82, ctx.r29.u16);
loc_8210C5A8:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// add r11,r30,r10
	ctx.r11.u64 = ctx.r30.u64 + ctx.r10.u64;
	// rlwinm r9,r9,3,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0x1;
	// addi r10,r11,76
	ctx.r10.s64 = ctx.r11.s64 + 76;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// srw r3,r4,r9
	ctx.r3.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r4.u32 >> (ctx.r9.u8 & 0x3F));
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// stw r10,76(r11)
	PPC_STORE_U32(ctx.r11.u32 + 76, ctx.r10.u32);
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210C5D4"))) PPC_WEAK_FUNC(sub_8210C5D4);
PPC_FUNC_IMPL(__imp__sub_8210C5D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210C5D8"))) PPC_WEAK_FUNC(sub_8210C5D8);
PPC_FUNC_IMPL(__imp__sub_8210C5D8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mulli r10,r4,96
	ctx.r10.s64 = ctx.r4.s64 * 96;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm r8,r7,3,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0x1;
	// rlwinm r9,r10,10,27,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 10) & 0x1F;
	// subfic r8,r8,7
	ctx.xer.ca = ctx.r8.u32 <= 7;
	ctx.r8.s64 = 7 - ctx.r8.s64;
	// srw r8,r5,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r5.u32 >> (ctx.r8.u8 & 0x3F));
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x8210c628
	if (!ctx.cr6.lt) goto loc_8210C628;
	// rlwinm r5,r10,5,27,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0x1F;
	// subf r8,r8,r5
	ctx.r8.s64 = ctx.r5.s64 - ctx.r8.s64;
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x8210c634
	if (ctx.cr6.lt) goto loc_8210C634;
	// subf r8,r9,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r9.s64;
	// b 0x8210c634
	goto loc_8210C634;
loc_8210C628:
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// li r3,0
	ctx.r3.s64 = 0;
	// clrlwi r8,r9,6
	ctx.r8.u64 = ctx.r9.u32 & 0x3FFFFFF;
loc_8210C634:
	// rlwinm r9,r10,5,27,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0x1F;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x8210c64c
	if (ctx.cr6.eq) goto loc_8210C64C;
	// rlwimi r10,r8,27,0,4
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r8.u32, 27) & 0xF8000000) | (ctx.r10.u64 & 0xFFFFFFFF07FFFFFF);
	// stw r6,48(r11)
	PPC_STORE_U32(ctx.r11.u32 + 48, ctx.r6.u32);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_8210C64C:
	// rlwinm r10,r7,0,0,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x80000000;
	// lis r9,-32768
	ctx.r9.s64 = -2147483648;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// oris r10,r7,32768
	ctx.r10.u64 = ctx.r7.u64 | 2147483648;
	// stw r6,48(r11)
	PPC_STORE_U32(ctx.r11.u32 + 48, ctx.r6.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8210C66C"))) PPC_WEAK_FUNC(sub_8210C66C);
PPC_FUNC_IMPL(__imp__sub_8210C66C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210C670"))) PPC_WEAK_FUNC(sub_8210C670);
PPC_FUNC_IMPL(__imp__sub_8210C670) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mulli r10,r4,96
	ctx.r10.s64 = ctx.r4.s64 * 96;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// rlwinm r9,r9,3,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0x1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// rlwinm. r9,r9,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble 0x8210c6ac
	if (!ctx.cr0.gt) goto loc_8210C6AC;
loc_8210C698:
	// lwz r7,72(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 72);
	// dcbz r10,r7
	memset(base + ((ctx.r10.u32 + ctx.r7.u32) & ~31), 0, 32);
	// addi r10,r10,128
	ctx.r10.s64 = ctx.r10.s64 + 128;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x8210c698
	if (ctx.cr6.lt) goto loc_8210C698;
loc_8210C6AC:
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// li r10,1
	ctx.r10.s64 = 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8210c6c4
	if (ctx.cr6.eq) goto loc_8210C6C4;
	// stw r8,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r8.u32);
	// stw r10,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r10.u32);
loc_8210C6C4:
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8210c6d8
	if (ctx.cr6.eq) goto loc_8210C6D8;
	// stw r8,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r8.u32);
	// stw r10,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r10.u32);
loc_8210C6D8:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// clrlwi. r7,r9,20
	ctx.r7.u64 = ctx.r9.u32 & 0xFFF;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq 0x8210c6f0
	if (ctx.cr0.eq) goto loc_8210C6F0;
	// rlwinm r9,r9,0,0,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFF000;
	// stw r10,48(r11)
	PPC_STORE_U32(ctx.r11.u32 + 48, ctx.r10.u32);
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
loc_8210C6F0:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// clrlwi. r7,r9,20
	ctx.r7.u64 = ctx.r9.u32 & 0xFFF;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq 0x8210c708
	if (ctx.cr0.eq) goto loc_8210C708;
	// rlwinm r9,r9,0,0,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFF000;
	// stw r10,48(r11)
	PPC_STORE_U32(ctx.r11.u32 + 48, ctx.r10.u32);
	// stw r9,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
loc_8210C708:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm. r7,r9,0,10,11
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x300000;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq 0x8210c720
	if (ctx.cr0.eq) goto loc_8210C720;
	// rlwinm r9,r9,0,12,9
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFCFFFFF;
	// stw r10,48(r11)
	PPC_STORE_U32(ctx.r11.u32 + 48, ctx.r10.u32);
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
loc_8210C720:
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// clrlwi. r7,r9,6
	ctx.r7.u64 = ctx.r9.u32 & 0x3FFFFFF;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq 0x8210c738
	if (ctx.cr0.eq) goto loc_8210C738;
	// rlwinm r9,r9,0,0,5
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFC000000;
	// stw r10,48(r11)
	PPC_STORE_U32(ctx.r11.u32 + 48, ctx.r10.u32);
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
loc_8210C738:
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// rlwinm. r7,r9,0,0,0
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq 0x8210c750
	if (ctx.cr0.eq) goto loc_8210C750;
	// clrlwi r9,r9,1
	ctx.r9.u64 = ctx.r9.u32 & 0x7FFFFFFF;
	// stw r10,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r10.u32);
	// stw r9,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r9.u32);
loc_8210C750:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r8,84(r11)
	PPC_STORE_U32(ctx.r11.u32 + 84, ctx.r8.u32);
	// rlwinm. r7,r9,0,0,4
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xF8000000;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stw r8,88(r11)
	PPC_STORE_U32(ctx.r11.u32 + 88, ctx.r8.u32);
	// stw r8,76(r11)
	PPC_STORE_U32(ctx.r11.u32 + 76, ctx.r8.u32);
	// beq 0x8210c774
	if (ctx.cr0.eq) goto loc_8210C774;
	// clrlwi r9,r9,5
	ctx.r9.u64 = ctx.r9.u32 & 0x7FFFFFF;
	// stw r10,48(r11)
	PPC_STORE_U32(ctx.r11.u32 + 48, ctx.r10.u32);
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
loc_8210C774:
	// lwz r9,36(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// clrlwi. r7,r9,27
	ctx.r7.u64 = ctx.r9.u32 & 0x1F;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq 0x8210c78c
	if (ctx.cr0.eq) goto loc_8210C78C;
	// rlwinm r9,r9,0,0,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFE0;
	// stw r10,56(r11)
	PPC_STORE_U32(ctx.r11.u32 + 56, ctx.r10.u32);
	// stw r9,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r9.u32);
loc_8210C78C:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lis r7,-32768
	ctx.r7.s64 = -2147483648;
	// rlwinm r6,r9,0,0,0
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80000000;
	// cmplw cr6,r6,r7
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x8210c7ac
	if (ctx.cr6.eq) goto loc_8210C7AC;
	// oris r9,r9,32768
	ctx.r9.u64 = ctx.r9.u64 | 2147483648;
	// stw r10,48(r11)
	PPC_STORE_U32(ctx.r11.u32 + 48, ctx.r10.u32);
	// stw r9,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
loc_8210C7AC:
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// sth r8,82(r11)
	PPC_STORE_U16(ctx.r11.u32 + 82, ctx.r8.u16);
	// rlwinm. r8,r9,0,1,5
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x7C000000;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x8210c7c8
	if (ctx.cr0.eq) goto loc_8210C7C8;
	// rlwinm r9,r9,0,6,0
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFF83FFFFFF;
	// stw r10,48(r11)
	PPC_STORE_U32(ctx.r11.u32 + 48, ctx.r10.u32);
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
loc_8210C7C8:
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// rlwinm. r8,r9,0,0,0
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x8210c7e0
	if (ctx.cr0.eq) goto loc_8210C7E0;
	// clrlwi r9,r9,1
	ctx.r9.u64 = ctx.r9.u32 & 0x7FFFFFFF;
	// stw r10,48(r11)
	PPC_STORE_U32(ctx.r11.u32 + 48, ctx.r10.u32);
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
loc_8210C7E0:
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// rlwinm. r8,r9,0,1,5
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x7C000000;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x8210c7f8
	if (ctx.cr0.eq) goto loc_8210C7F8;
	// rlwinm r9,r9,0,6,0
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFF83FFFFFF;
	// stw r10,48(r11)
	PPC_STORE_U32(ctx.r11.u32 + 48, ctx.r10.u32);
	// stw r9,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r9.u32);
loc_8210C7F8:
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// rlwinm. r8,r9,0,0,0
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x8210c810
	if (ctx.cr0.eq) goto loc_8210C810;
	// clrlwi r9,r9,1
	ctx.r9.u64 = ctx.r9.u32 & 0x7FFFFFFF;
	// stw r10,48(r11)
	PPC_STORE_U32(ctx.r11.u32 + 48, ctx.r10.u32);
	// stw r9,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r9.u32);
loc_8210C810:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8210C818"))) PPC_WEAK_FUNC(sub_8210C818);
PPC_FUNC_IMPL(__imp__sub_8210C818) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mulli r9,r4,96
	ctx.r9.s64 = ctx.r4.s64 * 96;
	// lbz r10,10(r5)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r5.u32 + 10);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm r7,r9,20,24,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 20) & 0xFF;
	// cmplw cr6,r7,r10
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8210c850
	if (ctx.cr6.eq) goto loc_8210C850;
	// rlwinm r10,r10,12,0,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFFFF000;
	// stw r8,48(r11)
	PPC_STORE_U32(ctx.r11.u32 + 48, ctx.r8.u32);
	// rlwinm r9,r9,0,20,11
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFF00FFF;
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_8210C850:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lbz r9,8(r5)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r5.u32 + 8);
	// rlwinm r7,r10,20,30,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 20) & 0x3;
	// cmplw cr6,r7,r9
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x8210c870
	if (ctx.cr6.eq) goto loc_8210C870;
	// rlwimi r10,r9,12,18,19
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 12) & 0x3000) | (ctx.r10.u64 & 0xFFFFFFFFFFFFCFFF);
	// stw r8,48(r11)
	PPC_STORE_U32(ctx.r11.u32 + 48, ctx.r8.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
loc_8210C870:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lbz r9,9(r5)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r5.u32 + 9);
	// rlwinm r7,r10,15,29,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x7;
	// cmplw cr6,r7,r9
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x8210c890
	if (ctx.cr6.eq) goto loc_8210C890;
	// rlwimi r10,r9,17,12,14
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 17) & 0xE0000) | (ctx.r10.u64 & 0xFFFFFFFFFFF1FFFF);
	// stw r8,48(r11)
	PPC_STORE_U32(ctx.r11.u32 + 48, ctx.r8.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
loc_8210C890:
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r9,0(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// clrlwi r7,r10,6
	ctx.r7.u64 = ctx.r10.u32 & 0x3FFFFFF;
	// cmplw cr6,r7,r9
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x8210c8b0
	if (ctx.cr6.eq) goto loc_8210C8B0;
	// rlwimi r10,r9,0,6,31
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 0) & 0x3FFFFFF) | (ctx.r10.u64 & 0xFFFFFFFFFC000000);
	// stw r8,48(r11)
	PPC_STORE_U32(ctx.r11.u32 + 48, ctx.r8.u32);
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
loc_8210C8B0:
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r9,4(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// clrlwi r7,r10,6
	ctx.r7.u64 = ctx.r10.u32 & 0x3FFFFFF;
	// cmplw cr6,r7,r9
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x8210c8d0
	if (ctx.cr6.eq) goto loc_8210C8D0;
	// rlwimi r10,r9,0,6,31
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 0) & 0x3FFFFFF) | (ctx.r10.u64 & 0xFFFFFFFFFC000000);
	// stw r8,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r8.u32);
	// stw r10,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
loc_8210C8D0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8210C8D8"))) PPC_WEAK_FUNC(sub_8210C8D8);
PPC_FUNC_IMPL(__imp__sub_8210C8D8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm. r11,r11,0,14,14
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8210c8f4
	if (ctx.cr0.eq) goto loc_8210C8F4;
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mulli r10,r4,96
	ctx.r10.s64 = ctx.r4.s64 * 96;
	// lwzx r11,r10,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// b 0x8210c908
	goto loc_8210C908;
loc_8210C8F4:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mulli r11,r4,96
	ctx.r11.s64 = ctx.r4.s64 * 96;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r11,64(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
loc_8210C908:
	// rlwinm r3,r11,20,24,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 20) & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8210C910"))) PPC_WEAK_FUNC(sub_8210C910);
PPC_FUNC_IMPL(__imp__sub_8210C910) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r8,0
	ctx.r8.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// blelr cr6
	if (!ctx.cr6.gt) return;
	// li r9,0
	ctx.r9.s64 = 0;
loc_8210C924:
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// add r10,r11,r9
	ctx.r10.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwzx r11,r11,r9
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r9.u32);
	// rlwinm r7,r11,20,24,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 20) & 0xFF;
	// cmplw cr6,r7,r4
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x8210c94c
	if (ctx.cr6.eq) goto loc_8210C94C;
	// li r7,1
	ctx.r7.s64 = 1;
	// rlwimi r11,r4,12,12,19
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 12) & 0xFF000) | (ctx.r11.u64 & 0xFFFFFFFFFFF00FFF);
	// stw r7,48(r10)
	PPC_STORE_U32(ctx.r10.u32 + 48, ctx.r7.u32);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
loc_8210C94C:
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r9,r9,96
	ctx.r9.s64 = ctx.r9.s64 + 96;
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8210c924
	if (ctx.cr6.lt) goto loc_8210C924;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8210C964"))) PPC_WEAK_FUNC(sub_8210C964);
PPC_FUNC_IMPL(__imp__sub_8210C964) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210C968"))) PPC_WEAK_FUNC(sub_8210C968);
PPC_FUNC_IMPL(__imp__sub_8210C968) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mulli r10,r4,96
	ctx.r10.s64 = ctx.r4.s64 * 96;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// clrlwi r8,r10,6
	ctx.r8.u64 = ctx.r10.u32 & 0x3FFFFFF;
	// cmplw cr6,r8,r5
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r5.u32, ctx.xer);
	// beq cr6,0x8210c994
	if (ctx.cr6.eq) goto loc_8210C994;
	// rlwimi r5,r10,0,0,5
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r10.u32, 0) & 0xFC000000) | (ctx.r5.u64 & 0xFFFFFFFF03FFFFFF);
	// stw r9,48(r11)
	PPC_STORE_U32(ctx.r11.u32 + 48, ctx.r9.u32);
	// stw r5,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r5.u32);
loc_8210C994:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// rlwinm r8,r10,8,29,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0x7;
	// cmplw cr6,r8,r6
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r6.u32, ctx.xer);
	// beq cr6,0x8210c9b0
	if (ctx.cr6.eq) goto loc_8210C9B0;
	// rlwimi r10,r6,24,5,7
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r6.u32, 24) & 0x7000000) | (ctx.r10.u64 & 0xFFFFFFFFF8FFFFFF);
	// stw r9,48(r11)
	PPC_STORE_U32(ctx.r11.u32 + 48, ctx.r9.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
loc_8210C9B0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8210C9B8"))) PPC_WEAK_FUNC(sub_8210C9B8);
PPC_FUNC_IMPL(__imp__sub_8210C9B8) {
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
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r31,r11,14452
	ctx.r31.s64 = ctx.r11.s64 + 14452;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821d5384
	ctx.lr = 0x8210C9D8;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lis r11,32746
	ctx.r11.s64 = 2146041856;
	// lis r10,512
	ctx.r10.s64 = 33554432;
	// ori r11,r11,6148
	ctx.r11.u64 = ctx.r11.u64 | 6148;
	// stwx r10,0,r11
	PPC_MM_STORE_U32(ctx.r11.u32, ctx.r10.u32);
	// eieio 
	// li r11,320
	ctx.r11.s64 = 320;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-5400
	ctx.r4.s64 = ctx.r10.s64 + -5400;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8210CA00:
	// lwz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8210caec
	if (ctx.cr6.eq) goto loc_8210CAEC;
	// lwz r11,4(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// rlwinm. r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8210caec
	if (ctx.cr0.eq) goto loc_8210CAEC;
	// rlwinm. r11,r11,0,14,14
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8210caec
	if (!ctx.cr0.eq) goto loc_8210CAEC;
	// lwz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x8210cae0
	if (!ctx.cr6.gt) goto loc_8210CAE0;
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
loc_8210CA34:
	// lwz r11,8(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm. r10,r10,0,10,11
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x300000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8210caa4
	if (ctx.cr0.eq) goto loc_8210CAA4;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm. r3,r10,12,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// rlwinm r7,r10,12,30,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0x3;
	// bne 0x8210ca74
	if (!ctx.cr0.eq) goto loc_8210CA74;
	// rlwinm r10,r10,0,0,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFF000;
	// stw r5,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r5.u32);
	// stw r5,84(r11)
	PPC_STORE_U32(ctx.r11.u32 + 84, ctx.r5.u32);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_8210CA74:
	// rlwinm. r10,r7,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8210ca90
	if (!ctx.cr0.eq) goto loc_8210CA90;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// stw r5,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r5.u32);
	// rlwinm r10,r10,0,0,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFF000;
	// stw r5,88(r11)
	PPC_STORE_U32(ctx.r11.u32 + 88, ctx.r5.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
loc_8210CA90:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x8210caa4
	if (!ctx.cr6.eq) goto loc_8210CAA4;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// clrlwi r10,r10,1
	ctx.r10.u64 = ctx.r10.u32 & 0x7FFFFFFF;
	// stw r10,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
loc_8210CAA4:
	// lhz r11,80(r11)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r11.u32 + 80);
	// li r10,1
	ctx.r10.s64 = 1;
	// rlwinm r7,r11,27,5,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r11,r11,27
	ctx.r11.u64 = ctx.r11.u32 & 0x1F;
	// addis r7,r7,8187
	ctx.r7.s64 = ctx.r7.s64 + 536543232;
	// slw r11,r10,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r11.u8 & 0x3F));
	// addi r7,r7,-31088
	ctx.r7.s64 = ctx.r7.s64 + -31088;
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// stwbrx r11,0,r10
	PPC_MM_STORE_U32(ctx.r10.u32, __builtin_bswap32(ctx.r11.u32));
	// eieio 
	// lwz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r8,r8,96
	ctx.r8.s64 = ctx.r8.s64 + 96;
	// cmplw cr6,r6,r11
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8210ca34
	if (ctx.cr6.lt) goto loc_8210CA34;
loc_8210CAE0:
	// lwz r11,4(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// oris r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 131072;
	// stw r11,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r11.u32);
loc_8210CAEC:
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// bdnz 0x8210ca00
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8210CA00;
	// lis r11,32746
	ctx.r11.s64 = 2146041856;
	// lis r10,768
	ctx.r10.s64 = 50331648;
	// ori r11,r11,6148
	ctx.r11.u64 = ctx.r11.u64 | 6148;
	// stwx r10,0,r11
	PPC_MM_STORE_U32(ctx.r11.u32, ctx.r10.u32);
	// eieio 
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821d5394
	ctx.lr = 0x8210CB10;
	__imp__RtlLeaveCriticalSection(ctx, base);
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

__attribute__((alias("__imp__sub_8210CB24"))) PPC_WEAK_FUNC(sub_8210CB24);
PPC_FUNC_IMPL(__imp__sub_8210CB24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210CB28"))) PPC_WEAK_FUNC(sub_8210CB28);
PPC_FUNC_IMPL(__imp__sub_8210CB28) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8210CB30;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r29,r11,14452
	ctx.r29.s64 = ctx.r11.s64 + 14452;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x821d5384
	ctx.lr = 0x8210CB48;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// ble cr6,0x8210cc30
	if (!ctx.cr6.gt) goto loc_8210CC30;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// li r30,16
	ctx.r30.s64 = 16;
	// li r3,32
	ctx.r3.s64 = 32;
loc_8210CB68:
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r7,64(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// rlwinm. r9,r10,0,10,11
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x300000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x8210cbf4
	if (ctx.cr0.eq) goto loc_8210CBF4;
	// lwz r8,68(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// rlwinm. r10,r10,18,19,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 18) & 0x1F00;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// mr r9,r6
	ctx.r9.u64 = ctx.r6.u64;
	// ble 0x8210cbac
	if (!ctx.cr0.gt) goto loc_8210CBAC;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rlwinm r10,r10,25,7,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1FFFFFF;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8210CBA0:
	// dcbf r9,r8
	// addi r9,r9,128
	ctx.r9.s64 = ctx.r9.s64 + 128;
	// bdnz 0x8210cba0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8210CBA0;
loc_8210CBAC:
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 48);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8210cbc4
	if (ctx.cr6.eq) goto loc_8210CBC4;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r6,48(r11)
	PPC_STORE_U32(ctx.r11.u32 + 48, ctx.r6.u32);
loc_8210CBC4:
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 52);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8210cbdc
	if (ctx.cr6.eq) goto loc_8210CBDC;
	// lvx128 v63,r11,r30
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r11.u32 + ctx.r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r7,r30
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r6,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r6.u32);
loc_8210CBDC:
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 56);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8210cbf4
	if (ctx.cr6.eq) goto loc_8210CBF4;
	// lvx128 v63,r11,r3
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r11.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r7,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r6,56(r11)
	PPC_STORE_U32(ctx.r11.u32 + 56, ctx.r6.u32);
loc_8210CBF4:
	// lhz r11,80(r11)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r11.u32 + 80);
	// li r10,1
	ctx.r10.s64 = 1;
	// rlwinm r9,r11,27,5,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r11,r11,27
	ctx.r11.u64 = ctx.r11.u32 & 0x1F;
	// addis r9,r9,8187
	ctx.r9.s64 = ctx.r9.s64 + 536543232;
	// slw r11,r10,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r11.u8 & 0x3F));
	// addi r9,r9,-31152
	ctx.r9.s64 = ctx.r9.s64 + -31152;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stwbrx r11,0,r10
	PPC_MM_STORE_U32(ctx.r10.u32, __builtin_bswap32(ctx.r11.u32));
	// eieio 
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// addi r5,r5,96
	ctx.r5.s64 = ctx.r5.s64 + 96;
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8210cb68
	if (ctx.cr6.lt) goto loc_8210CB68;
loc_8210CC30:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// rlwinm r11,r11,0,15,13
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFDFFFF;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bl 0x821d5394
	ctx.lr = 0x8210CC44;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210CC4C"))) PPC_WEAK_FUNC(sub_8210CC4C);
PPC_FUNC_IMPL(__imp__sub_8210CC4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210CC50"))) PPC_WEAK_FUNC(sub_8210CC50);
PPC_FUNC_IMPL(__imp__sub_8210CC50) {
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
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// rlwinm. r11,r11,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8210cca8
	if (ctx.cr0.eq) goto loc_8210CCA8;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r30,r11,14452
	ctx.r30.s64 = ctx.r11.s64 + 14452;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821d5384
	ctx.lr = 0x8210CC84;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,-5400
	ctx.r11.s64 = ctx.r11.s64 + -5400;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lhz r9,80(r9)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r9.u32 + 80);
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// stwx r10,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + ctx.r11.u32, ctx.r10.u32);
	// bl 0x821d5394
	ctx.lr = 0x8210CCA8;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_8210CCA8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8210c2a0
	ctx.lr = 0x8210CCB0;
	sub_8210C2A0(ctx, base);
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// rlwinm. r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8210ccc8
	if (!ctx.cr0.eq) goto loc_8210CCC8;
	// lis r4,-22633
	ctx.r4.s64 = -1483276288;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82088ce0
	ctx.lr = 0x8210CCC8;
	sub_82088CE0(ctx, base);
loc_8210CCC8:
	// li r3,0
	ctx.r3.s64 = 0;
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

__attribute__((alias("__imp__sub_8210CCE4"))) PPC_WEAK_FUNC(sub_8210CCE4);
PPC_FUNC_IMPL(__imp__sub_8210CCE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210CCE8"))) PPC_WEAK_FUNC(sub_8210CCE8);
PPC_FUNC_IMPL(__imp__sub_8210CCE8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x8210CCF0;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mulli r10,r4,96
	ctx.r10.s64 = ctx.r4.s64 * 96;
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// rlwinm r27,r9,12,30,31
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 12) & 0x3;
	// add r31,r10,r11
	ctx.r31.u64 = ctx.r10.u64 + ctx.r11.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// clrlwi. r11,r27,31
	ctx.r11.u64 = ctx.r27.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r29,r6,21,11,31
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 21) & 0x1FFFFF;
	// bne 0x8210cd88
	if (!ctx.cr0.eq) goto loc_8210CD88;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x821d5994
	ctx.lr = 0x8210CD20;
	__imp__MmGetPhysicalAddress(ctx, base);
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// li r30,1
	ctx.r30.s64 = 1;
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// beq cr6,0x8210cd40
	if (ctx.cr6.eq) goto loc_8210CD40;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x821d5994
	ctx.lr = 0x8210CD38;
	__imp__MmGetPhysicalAddress(ctx, base);
	// stw r3,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r3.u32);
	// stw r30,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
loc_8210CD40:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// clrlwi r10,r11,20
	ctx.r10.u64 = ctx.r11.u32 & 0xFFF;
	// cmplw cr6,r10,r29
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x8210cd5c
	if (ctx.cr6.eq) goto loc_8210CD5C;
	// rlwimi r11,r29,0,20,31
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r29.u32, 0) & 0xFFF) | (ctx.r11.u64 & 0xFFFFFFFFFFFFF000);
	// stw r30,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r30.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_8210CD5C:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// rlwinm r9,r11,0,10,11
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x300000;
	// rlwimi r10,r30,20,11,9
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r30.u32, 20) & 0xFFFFFFFFFFDFFFFF) | (ctx.r10.u64 & 0x200000);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8210cd80
	if (ctx.cr6.eq) goto loc_8210CD80;
	// oris r11,r11,16
	ctx.r11.u64 = ctx.r11.u64 | 1048576;
	// stw r30,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r30.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_8210CD80:
	// stw r28,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r28.u32);
	// b 0x8210cdfc
	goto loc_8210CDFC;
loc_8210CD88:
	// rlwinm. r11,r27,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8210ce40
	if (!ctx.cr0.eq) goto loc_8210CE40;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x821d5994
	ctx.lr = 0x8210CD98;
	__imp__MmGetPhysicalAddress(ctx, base);
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// li r30,1
	ctx.r30.s64 = 1;
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// beq cr6,0x8210cdb8
	if (ctx.cr6.eq) goto loc_8210CDB8;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x821d5994
	ctx.lr = 0x8210CDB0;
	__imp__MmGetPhysicalAddress(ctx, base);
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// stw r30,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
loc_8210CDB8:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// clrlwi r10,r11,20
	ctx.r10.u64 = ctx.r11.u32 & 0xFFF;
	// cmplw cr6,r10,r29
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x8210cdd4
	if (ctx.cr6.eq) goto loc_8210CDD4;
	// rlwimi r11,r29,0,20,31
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r29.u32, 0) & 0xFFF) | (ctx.r11.u64 & 0xFFFFFFFFFFFFF000);
	// stw r30,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r30.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
loc_8210CDD4:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// rlwinm r9,r11,0,10,11
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x300000;
	// rlwimi r10,r30,21,12,10
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r30.u32, 21) & 0xFFFFFFFFFFEFFFFF) | (ctx.r10.u64 & 0x100000);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8210cdf8
	if (ctx.cr6.eq) goto loc_8210CDF8;
	// oris r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 | 2097152;
	// stw r30,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r30.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_8210CDF8:
	// stw r28,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r28.u32);
loc_8210CDFC:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// bne cr6,0x8210ce38
	if (!ctx.cr6.eq) goto loc_8210CE38;
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,32767
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32767, ctx.xer);
	// beq cr6,0x8210ce38
	if (ctx.cr6.eq) goto loc_8210CE38;
	// rlwinm r11,r11,21,17,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 21) & 0x7FFF;
	// addic. r11,r11,32
	ctx.xer.ca = ctx.r11.u32 > 4294967263;
	ctx.r11.s64 = ctx.r11.s64 + 32;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8210ce38
	if (ctx.cr0.eq) goto loc_8210CE38;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// clrlwi r9,r10,6
	ctx.r9.u64 = ctx.r10.u32 & 0x3FFFFFF;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8210ce38
	if (ctx.cr6.eq) goto loc_8210CE38;
	// rlwimi r11,r10,0,0,5
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 0) & 0xFC000000) | (ctx.r11.u64 & 0xFFFFFFFF03FFFFFF);
	// stw r30,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r30.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
loc_8210CE38:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8210ce48
	goto loc_8210CE48;
loc_8210CE40:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,5
	ctx.r3.u64 = ctx.r3.u64 | 5;
loc_8210CE48:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210CE50"))) PPC_WEAK_FUNC(sub_8210CE50);
PPC_FUNC_IMPL(__imp__sub_8210CE50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c96c
	ctx.lr = 0x8210CE58;
	__savegprlr_21(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mulli r11,r3,96
	ctx.r11.s64 = ctx.r3.s64 * 96;
	// addi r10,r11,143
	ctx.r10.s64 = ctx.r11.s64 + 143;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r22,r5
	ctx.r22.u64 = ctx.r5.u64;
	// mr r21,r6
	ctx.r21.u64 = ctx.r6.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// rlwinm r31,r10,0,0,24
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8210ceac
	if (ctx.cr6.eq) goto loc_8210CEAC;
	// addi r10,r4,-8
	ctx.r10.s64 = ctx.r4.s64 + -8;
	// mtctr r3
	ctx.ctr.u64 = ctx.r3.u64;
loc_8210CE8C:
	// lbz r8,16(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 16);
	// lwzu r9,12(r10)
	ea = 12 + ctx.r10.u32;
	ctx.r9.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// rotlwi r6,r8,1
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// rotlwi r8,r8,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// mullw r9,r9,r6
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r6.s32);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// bdnz 0x8210ce8c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8210CE8C;
loc_8210CEAC:
	// add r29,r11,r31
	ctx.r29.u64 = ctx.r11.u64 + ctx.r31.u64;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x8210cf58
	if (ctx.cr6.eq) goto loc_8210CF58;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
loc_8210CEBC:
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// subf r29,r31,r29
	ctx.r29.s64 = ctx.r29.s64 - ctx.r31.s64;
	// bl 0x82088480
	ctx.lr = 0x8210CED0;
	sub_82088480(ctx, base);
	// addi r10,r28,16
	ctx.r10.s64 = ctx.r28.s64 + 16;
	// stw r30,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r30.u32);
	// add r26,r31,r28
	ctx.r26.u64 = ctx.r31.u64 + ctx.r28.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r10,8(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8, ctx.r10.u32);
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// ble cr6,0x8210cf08
	if (!ctx.cr6.gt) goto loc_8210CF08;
	// addi r10,r29,-1
	ctx.r10.s64 = ctx.r29.s64 + -1;
	// rlwinm r10,r10,25,7,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1FFFFFF;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8210CEFC:
	// dcbf r11,r26
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// bdnz 0x8210cefc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8210CEFC;
loc_8210CF08:
	// rlwinm. r23,r22,0,29,29
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// stw r22,4(r28)
	PPC_STORE_U32(ctx.r28.u32 + 4, ctx.r22.u32);
	// oris r11,r22,2
	ctx.r11.u64 = ctx.r22.u64 | 131072;
	// bne 0x8210cf1c
	if (!ctx.cr0.eq) goto loc_8210CF1C;
	// oris r11,r22,3
	ctx.r11.u64 = ctx.r22.u64 | 196608;
loc_8210CF1C:
	// stw r11,4(r28)
	PPC_STORE_U32(ctx.r28.u32 + 4, ctx.r11.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8210d0c8
	if (ctx.cr6.eq) goto loc_8210D0C8;
	// addi r29,r27,8
	ctx.r29.s64 = ctx.r27.s64 + 8;
	// li r25,0
	ctx.r25.s64 = 0;
	// mr r24,r30
	ctx.r24.u64 = ctx.r30.u64;
	// li r27,1
	ctx.r27.s64 = 1;
loc_8210CF38:
	// lwz r11,8(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8);
	// add r31,r25,r11
	ctx.r31.u64 = ctx.r25.u64 + ctx.r11.u64;
	// stw r26,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r26.u32);
	// lwz r11,-8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -8);
	// cmplwi cr6,r11,24000
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 24000, ctx.xer);
	// bgt cr6,0x8210cf78
	if (ctx.cr6.gt) goto loc_8210CF78;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x8210cfa0
	goto loc_8210CFA0;
loc_8210CF58:
	// lis r4,-22633
	ctx.r4.s64 = -1483276288;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82088c48
	ctx.lr = 0x8210CF64;
	sub_82088C48(ctx, base);
	// mr. r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bne 0x8210cebc
	if (!ctx.cr0.eq) goto loc_8210CEBC;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// b 0x8210d130
	goto loc_8210D130;
loc_8210CF78:
	// cmplwi cr6,r11,32000
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32000, ctx.xer);
	// bgt cr6,0x8210cf88
	if (ctx.cr6.gt) goto loc_8210CF88;
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// b 0x8210cfa0
	goto loc_8210CFA0;
loc_8210CF88:
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r10,r10,44100
	ctx.r10.u64 = ctx.r10.u64 | 44100;
	// subfc r11,r11,r10
	ctx.xer.ca = ctx.r10.u32 >= ctx.r11.u32;
	ctx.r11.s64 = ctx.r10.s64 - ctx.r11.s64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// addi r10,r11,2
	ctx.r10.s64 = ctx.r11.s64 + 2;
loc_8210CFA0:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// rlwinm r9,r11,5,30,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0x3;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8210cfbc
	if (ctx.cr6.eq) goto loc_8210CFBC;
	// rlwimi r11,r10,27,3,4
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 27) & 0x18000000) | (ctx.r11.u64 & 0xFFFFFFFFE7FFFFFF);
	// stw r27,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r27.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
loc_8210CFBC:
	// lbz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r29.u32 + 0);
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rlwinm r9,r11,3,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0x1;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8210cfe0
	if (ctx.cr6.eq) goto loc_8210CFE0;
	// rlwimi r11,r10,29,2,2
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 29) & 0x20000000) | (ctx.r11.u64 & 0xFFFFFFFFDFFFFFFF);
	// stw r27,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r27.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
loc_8210CFE0:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lbz r10,1(r29)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r29.u32 + 1);
	// rlwinm r9,r11,12,28,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 12) & 0xF;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8210d000
	if (ctx.cr6.eq) goto loc_8210D000;
	// rlwimi r11,r10,20,8,11
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 20) & 0xF00000) | (ctx.r11.u64 & 0xFFFFFFFFFF0FFFFF);
	// stw r27,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r27.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
loc_8210D000:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x821d5994
	ctx.lr = 0x8210D008;
	__imp__MmGetPhysicalAddress(ctx, base);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// beq cr6,0x8210d024
	if (ctx.cr6.eq) goto loc_8210D024;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x821d5994
	ctx.lr = 0x8210D01C;
	__imp__MmGetPhysicalAddress(ctx, base);
	// stw r3,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r3.u32);
	// stw r27,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r27.u32);
loc_8210D024:
	// lwz r9,-4(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + -4);
	// lbz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r29.u32 + 0);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mullw r10,r10,r9
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// rlwinm r9,r11,17,20,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xF80;
	// rlwinm r8,r10,0,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x8210d050
	if (ctx.cr6.eq) goto loc_8210D050;
	// rlwimi r11,r10,15,5,9
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 15) & 0x7C00000) | (ctx.r11.u64 & 0xFFFFFFFFF83FFFFF);
	// stw r27,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r27.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_8210D050:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// rlwinm r9,r11,0,0,0
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8210d070
	if (ctx.cr6.eq) goto loc_8210D070;
	// oris r11,r11,32768
	ctx.r11.u64 = ctx.r11.u64 | 2147483648;
	// stw r27,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r27.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
loc_8210D070:
	// lbz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r29.u32 + 0);
	// lwz r10,-4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + -4);
	// mullw r11,r11,r10
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r30,r11,r26
	ctx.r30.u64 = ctx.r11.u64 + ctx.r26.u64;
	// stw r30,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r30.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821d5994
	ctx.lr = 0x8210D090;
	__imp__MmGetPhysicalAddress(ctx, base);
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// beq cr6,0x8210d0ac
	if (ctx.cr6.eq) goto loc_8210D0AC;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821d5994
	ctx.lr = 0x8210D0A4;
	__imp__MmGetPhysicalAddress(ctx, base);
	// stw r3,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r3.u32);
	// stw r27,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r27.u32);
loc_8210D0AC:
	// lbz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r29.u32 + 0);
	// addic. r24,r24,-1
	ctx.xer.ca = ctx.r24.u32 > 0;
	ctx.r24.s64 = ctx.r24.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// addi r25,r25,96
	ctx.r25.s64 = ctx.r25.s64 + 96;
	// rotlwi r11,r11,8
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// addi r29,r29,12
	ctx.r29.s64 = ctx.r29.s64 + 12;
	// add r26,r11,r30
	ctx.r26.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bne 0x8210cf38
	if (!ctx.cr0.eq) goto loc_8210CF38;
loc_8210D0C8:
	// clrlwi. r11,r22,31
	ctx.r11.u64 = ctx.r22.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8210d0f0
	if (!ctx.cr0.eq) goto loc_8210D0F0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8210c190
	ctx.lr = 0x8210D0D8;
	sub_8210C190(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bge 0x8210d0f0
	if (!ctx.cr0.lt) goto loc_8210D0F0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8210cc50
	ctx.lr = 0x8210D0E8;
	sub_8210CC50(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x8210d130
	goto loc_8210D130;
loc_8210D0F0:
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x8210d128
	if (ctx.cr6.eq) goto loc_8210D128;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r31,r11,14452
	ctx.r31.s64 = ctx.r11.s64 + 14452;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821d5384
	ctx.lr = 0x8210D108;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r10,8(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r11,r11,-5400
	ctx.r11.s64 = ctx.r11.s64 + -5400;
	// lhz r10,80(r10)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + 80);
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// stwx r28,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + ctx.r11.u32, ctx.r28.u32);
	// bl 0x821d5394
	ctx.lr = 0x8210D128;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_8210D128:
	// stw r28,0(r21)
	PPC_STORE_U32(ctx.r21.u32 + 0, ctx.r28.u32);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8210D130:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9bc
	__restgprlr_21(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210D138"))) PPC_WEAK_FUNC(sub_8210D138);
PPC_FUNC_IMPL(__imp__sub_8210D138) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8210D15C"))) PPC_WEAK_FUNC(sub_8210D15C);
PPC_FUNC_IMPL(__imp__sub_8210D15C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8210D160"))) PPC_WEAK_FUNC(sub_8210D160);
PPC_FUNC_IMPL(__imp__sub_8210D160) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8210D180"))) PPC_WEAK_FUNC(sub_8210D180);
PPC_FUNC_IMPL(__imp__sub_8210D180) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8210D184"))) PPC_WEAK_FUNC(sub_8210D184);
PPC_FUNC_IMPL(__imp__sub_8210D184) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210D188"))) PPC_WEAK_FUNC(sub_8210D188);
PPC_FUNC_IMPL(__imp__sub_8210D188) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8210D1A8"))) PPC_WEAK_FUNC(sub_8210D1A8);
PPC_FUNC_IMPL(__imp__sub_8210D1A8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8210D1AC"))) PPC_WEAK_FUNC(sub_8210D1AC);
PPC_FUNC_IMPL(__imp__sub_8210D1AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210D1B0"))) PPC_WEAK_FUNC(sub_8210D1B0);
PPC_FUNC_IMPL(__imp__sub_8210D1B0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8210D1D0"))) PPC_WEAK_FUNC(sub_8210D1D0);
PPC_FUNC_IMPL(__imp__sub_8210D1D0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8210D1D4"))) PPC_WEAK_FUNC(sub_8210D1D4);
PPC_FUNC_IMPL(__imp__sub_8210D1D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210D1D8"))) PPC_WEAK_FUNC(sub_8210D1D8);
PPC_FUNC_IMPL(__imp__sub_8210D1D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210d25c
	if (ctx.cr6.eq) goto loc_8210D25C;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
loc_8210D1F0:
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8210d24c
	if (ctx.cr6.eq) goto loc_8210D24C;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
loc_8210D200:
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lfs f0,16(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// lwz r6,12(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mullw r10,r11,r10
	ctx.r10.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// lwz r7,20(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r4,24(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lfsx f13,r8,r6
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r6.u32);
	ctx.f13.f64 = double(temp.f32);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,3
	ctx.r10.s64 = ctx.r10.s64 + 3;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f12,r6,r7
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r7.u32);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfsx f0,r10,r4
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r4.u32, temp.u32);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8210d200
	if (ctx.cr6.lt) goto loc_8210D200;
loc_8210D24C:
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8210d1f0
	if (ctx.cr6.lt) goto loc_8210D1F0;
loc_8210D25C:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r6,24(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// mullw r11,r9,r11
	ctx.r11.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r9,8(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// addi r11,r11,3
	ctx.r11.s64 = ctx.r11.s64 + 3;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8210D28C"))) PPC_WEAK_FUNC(sub_8210D28C);
PPC_FUNC_IMPL(__imp__sub_8210D28C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210D290"))) PPC_WEAK_FUNC(sub_8210D290);
PPC_FUNC_IMPL(__imp__sub_8210D290) {
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
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x8210d2c4
	if (ctx.cr6.eq) goto loc_8210D2C4;
	// lwz r11,48(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r10,40(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// lwz r9,40(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// subf r10,r10,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r10.s64;
	// stw r10,40(r11)
	PPC_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
loc_8210D2C4:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8210d2e8
	if (!ctx.cr6.eq) goto loc_8210D2E8;
	// lwz r11,-4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -4);
	// addi r3,r31,-4
	ctx.r3.s64 = ctx.r31.s64 + -4;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,120(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210D2E8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8210D2E8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8211b360
	ctx.lr = 0x8210D2F0;
	sub_8211B360(ctx, base);
	// lwz r4,140(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8210d30c
	if (ctx.cr6.eq) goto loc_8210D30C;
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// bl 0x82108f58
	ctx.lr = 0x8210D304;
	sub_82108F58(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r11.u32);
loc_8210D30C:
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

__attribute__((alias("__imp__sub_8210D320"))) PPC_WEAK_FUNC(sub_8210D320);
PPC_FUNC_IMPL(__imp__sub_8210D320) {
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
	// lwz r11,52(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210D354;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// stw r11,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// lwz r11,168(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 168);
	// stw r11,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210D384;
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

__attribute__((alias("__imp__sub_8210D39C"))) PPC_WEAK_FUNC(sub_8210D39C);
PPC_FUNC_IMPL(__imp__sub_8210D39C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210D3A0"))) PPC_WEAK_FUNC(sub_8210D3A0);
PPC_FUNC_IMPL(__imp__sub_8210D3A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8210D3A8;
	__savegprlr_29(ctx, base);
	// stfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.f30.u64);
	// stfd f31,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,52(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210D3D8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r30,0
	ctx.r30.s64 = 0;
	// lfs f30,76(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	ctx.f30.f64 = double(temp.f32);
	// fcmpu cr6,f31,f30
	ctx.cr6.compare(ctx.f31.f64, ctx.f30.f64);
	// beq cr6,0x8210d42c
	if (ctx.cr6.eq) goto loc_8210D42C;
	// stfs f31,76(r31)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r31.u32 + 76, temp.u32);
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r5,80(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// addi r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210d408
	if (ctx.cr6.eq) goto loc_8210D408;
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x8210d40c
	goto loc_8210D40C;
loc_8210D408:
	// lwz r4,60(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
loc_8210D40C:
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// lwz r11,96(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 96);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210D420;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x8210d42c
	if (!ctx.cr0.lt) goto loc_8210D42C;
	// stfs f30,76(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r31.u32 + 76, temp.u32);
loc_8210D42C:
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210D444;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210D458"))) PPC_WEAK_FUNC(sub_8210D458);
PPC_FUNC_IMPL(__imp__sub_8210D458) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x8210D460;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,52(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210D48C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// rlwinm. r28,r29,2,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// li r29,0
	ctx.r29.s64 = 0;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// beq 0x8210d4c8
	if (ctx.cr0.eq) goto loc_8210D4C8;
	// add r8,r30,r28
	ctx.r8.u64 = ctx.r30.u64 + ctx.r28.u64;
loc_8210D4A8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x8210d4c8
	if (!ctx.cr0.eq) goto loc_8210D4C8;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// bne cr6,0x8210d4a8
	if (!ctx.cr6.eq) goto loc_8210D4A8;
loc_8210D4C8:
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x8210d51c
	if (ctx.cr0.eq) goto loc_8210D51C;
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// addi r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210d4e8
	if (ctx.cr6.eq) goto loc_8210D4E8;
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x8210d4ec
	goto loc_8210D4EC;
loc_8210D4E8:
	// lwz r4,60(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
loc_8210D4EC:
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r11,96(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 96);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210D504;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt 0x8210d51c
	if (ctx.cr0.lt) goto loc_8210D51C;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8207dac0
	ctx.lr = 0x8210D51C;
	sub_8207DAC0(ctx, base);
loc_8210D51C:
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210D534;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210D540"))) PPC_WEAK_FUNC(sub_8210D540);
PPC_FUNC_IMPL(__imp__sub_8210D540) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8210D548;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,52(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210D56C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8210d684
	if (ctx.cr6.eq) goto loc_8210D684;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x8210d590
	if (!ctx.cr6.eq) goto loc_8210D590;
	// lis r29,4919
	ctx.r29.s64 = 322371584;
	// ori r29,r29,61441
	ctx.r29.u64 = ctx.r29.u64 | 61441;
	// b 0x8210d594
	goto loc_8210D594;
loc_8210D590:
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
loc_8210D594:
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210D5AC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x8210d684
	if (ctx.cr0.lt) goto loc_8210D684;
	// lwz r3,136(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 136);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8210d5d8
	if (ctx.cr6.eq) goto loc_8210D5D8;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210D5D4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_8210D5D8:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8210d684
	if (ctx.cr6.lt) goto loc_8210D684;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x8210d5fc
	if (ctx.cr6.eq) goto loc_8210D5FC;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 4;
	// bl 0x82119c60
	ctx.lr = 0x8210D5F8;
	sub_82119C60(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_8210D5FC:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8210d684
	if (ctx.cr6.lt) goto loc_8210D684;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x8210d62c
	if (!ctx.cr6.eq) goto loc_8210D62C;
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r3,176(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,72(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210D628;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_8210D62C:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8210d684
	if (ctx.cr6.lt) goto loc_8210D684;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,120(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210D64C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x8210d66c
	if (ctx.cr6.eq) goto loc_8210D66C;
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,44(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r10,40(r11)
	PPC_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
loc_8210D66C:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 4;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,92(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 92);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210D684;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8210D684:
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210D69C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210D6A8"))) PPC_WEAK_FUNC(sub_8210D6A8);
PPC_FUNC_IMPL(__imp__sub_8210D6A8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x8210D6B0;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,52(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210D6D8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x8210d884
	if (ctx.cr6.eq) goto loc_8210D884;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8210d6f8
	if (!ctx.cr6.eq) goto loc_8210D6F8;
	// rlwinm. r11,r29,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8210d884
	if (!ctx.cr0.eq) goto loc_8210D884;
loc_8210D6F8:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// bne cr6,0x8210d70c
	if (!ctx.cr6.eq) goto loc_8210D70C;
	// lis r28,4919
	ctx.r28.s64 = 322371584;
	// ori r28,r28,61441
	ctx.r28.u64 = ctx.r28.u64 | 61441;
	// b 0x8210d710
	goto loc_8210D710;
loc_8210D70C:
	// mr r28,r26
	ctx.r28.u64 = ctx.r26.u64;
loc_8210D710:
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210D72C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x8210d884
	if (ctx.cr0.lt) goto loc_8210D884;
	// lwz r3,136(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 136);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8210d768
	if (ctx.cr6.eq) goto loc_8210D768;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x8210d768
	if (ctx.cr6.eq) goto loc_8210D768;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210D764;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_8210D768:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8210d884
	if (ctx.cr6.lt) goto loc_8210D884;
	// rlwinm. r27,r29,0,26,26
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// bne 0x8210d7f0
	if (!ctx.cr0.eq) goto loc_8210D7F0;
	// lwz r29,36(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// b 0x8210d7c8
	goto loc_8210D7C8;
loc_8210D780:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8210d884
	if (ctx.cr6.lt) goto loc_8210D884;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8210d7a0
	if (ctx.cr6.eq) goto loc_8210D7A0;
	// lwz r29,4(r29)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x8210d7a4
	goto loc_8210D7A4;
loc_8210D7A0:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8210D7A4:
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210D7C4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_8210D7C8:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8210d780
	if (!ctx.cr6.eq) goto loc_8210D780;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8210d884
	if (ctx.cr6.lt) goto loc_8210D884;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8210d7f0
	if (ctx.cr0.eq) goto loc_8210D7F0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82119510
	ctx.lr = 0x8210D7EC;
	sub_82119510(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_8210D7F0:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8210d884
	if (ctx.cr6.lt) goto loc_8210D884;
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// bne cr6,0x8210d820
	if (!ctx.cr6.eq) goto loc_8210D820;
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r3,176(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,72(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210D81C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_8210D820:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8210d884
	if (ctx.cr6.lt) goto loc_8210D884;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cntlzw r11,r27
	ctx.r11.u64 = ctx.r27.u32 == 0 ? 32 : __builtin_clz(ctx.r27.u32);
	// addi r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 4;
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// xori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 ^ 1;
	// lwz r10,92(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 92);
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8210D84C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x8210d86c
	if (ctx.cr6.eq) goto loc_8210D86C;
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r9,40(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// subf r10,r10,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r10.s64;
	// stw r10,40(r11)
	PPC_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
loc_8210D86C:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,120(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210D884;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8210D884:
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210D89C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210D8A8"))) PPC_WEAK_FUNC(sub_8210D8A8);
PPC_FUNC_IMPL(__imp__sub_8210D8A8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8210D8B0;
	__savegprlr_29(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,52(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210D8D4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x821d5474
	ctx.lr = 0x8210D8D8;
	__imp__KeGetCurrentProcessType(ctx, base);
	// lhz r11,172(r29)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r29.u32 + 172);
	// li r30,1
	ctx.r30.s64 = 1;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x8210d900
	if (!ctx.cr6.eq) goto loc_8210D900;
	// lwz r11,160(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 160);
	// lwz r10,64(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 64);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// twllei r10,0
	// divwu r11,r11,r10
	ctx.r11.u32 = ppc_divwu(ctx.r11.u32, ctx.r10.u32);
	// addi r30,r11,-12
	ctx.r30.s64 = ctx.r11.s64 + -12;
loc_8210D900:
	// li r5,36
	ctx.r5.s64 = 36;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x8207da20
	ctx.lr = 0x8210D910;
	sub_8207DA20(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// twllei r30,0
	// divwu r7,r11,r30
	ctx.r7.u32 = ppc_divwu(ctx.r11.u32, ctx.r30.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r6,8(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r5,32(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r11,160(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 160);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// mullw r7,r7,r11
	ctx.r7.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r11.s32);
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// stw r7,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8210d964
	if (ctx.cr6.eq) goto loc_8210D964;
	// divwu r10,r10,r30
	ctx.r10.u32 = ppc_divwu(ctx.r10.u32, ctx.r30.u32);
	// twllei r30,0
	// mullw r8,r10,r11
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// b 0x8210d968
	goto loc_8210D968;
loc_8210D964:
	// subf r8,r7,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r7.s64;
loc_8210D968:
	// lwz r6,28(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// stw r8,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r8.u32);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x8210d9b8
	if (ctx.cr6.eq) goto loc_8210D9B8;
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// twllei r30,0
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// divwu r9,r9,r30
	ctx.r9.u32 = ppc_divwu(ctx.r9.u32, ctx.r30.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// mullw r9,r9,r11
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// beq cr6,0x8210d9a8
	if (ctx.cr6.eq) goto loc_8210D9A8;
	// divwu r10,r10,r30
	ctx.r10.u32 = ppc_divwu(ctx.r10.u32, ctx.r30.u32);
	// twllei r30,0
	// mullw r11,r10,r11
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// b 0x8210d9b0
	goto loc_8210D9B0;
loc_8210D9A8:
	// subf r11,r9,r8
	ctx.r11.s64 = ctx.r8.s64 - ctx.r9.s64;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
loc_8210D9B0:
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r11.u32);
	// stw r6,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r6.u32);
loc_8210D9B8:
	// addi r30,r29,148
	ctx.r30.s64 = ctx.r29.s64 + 148;
loc_8210D9BC:
	// mfmsr r10
	ctx.r10.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r11,0,r30
	ctx.reserved.u32 = *(uint32_t*)(base + ctx.r30.u32);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwcx. r11,0,r30
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + ctx.r30.u32), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x8210d9bc
	if (!ctx.cr0.eq) goto loc_8210D9BC;
	// lwz r3,144(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 144);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210D9F4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bge 0x8210da18
	if (!ctx.cr0.lt) goto loc_8210DA18;
loc_8210D9FC:
	// mfmsr r10
	ctx.r10.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r11,0,r30
	ctx.reserved.u32 = *(uint32_t*)(base + ctx.r30.u32);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r30
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + ctx.r30.u32), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x8210d9fc
	if (!ctx.cr0.eq) goto loc_8210D9FC;
loc_8210DA18:
	// lwz r11,52(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 52);
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210DA30;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210DA3C"))) PPC_WEAK_FUNC(sub_8210DA3C);
PPC_FUNC_IMPL(__imp__sub_8210DA3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210DA40"))) PPC_WEAK_FUNC(sub_8210DA40);
PPC_FUNC_IMPL(__imp__sub_8210DA40) {
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
	// lwz r11,52(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210DA6C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210DA84;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210DAA0;
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

__attribute__((alias("__imp__sub_8210DAB8"))) PPC_WEAK_FUNC(sub_8210DAB8);
PPC_FUNC_IMPL(__imp__sub_8210DAB8) {
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
	// lwz r11,52(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210DAE4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,40(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210DAF8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210DB14;
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

__attribute__((alias("__imp__sub_8210DB2C"))) PPC_WEAK_FUNC(sub_8210DB2C);
PPC_FUNC_IMPL(__imp__sub_8210DB2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210DB30"))) PPC_WEAK_FUNC(sub_8210DB30);
PPC_FUNC_IMPL(__imp__sub_8210DB30) {
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
	// lwz r11,52(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210DB64;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,36(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210DB7C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210DB98;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
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

__attribute__((alias("__imp__sub_8210DBB4"))) PPC_WEAK_FUNC(sub_8210DBB4);
PPC_FUNC_IMPL(__imp__sub_8210DBB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210DBB8"))) PPC_WEAK_FUNC(sub_8210DBB8);
PPC_FUNC_IMPL(__imp__sub_8210DBB8) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,52(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210DBEC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,52(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210DC04;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// ld r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// lwz r11,148(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// stw r11,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// lwz r11,160(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 160);
	// tdllei r11,0
	// divdu r11,r10,r11
	ctx.r11.u64 = ppc_divdu(ctx.r10.u64, ctx.r11.u64);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// std r11,8(r30)
	PPC_STORE_U64(ctx.r30.u32 + 8, ctx.r11.u64);
	// lhz r11,172(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 172);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x8210dc60
	if (!ctx.cr6.eq) goto loc_8210DC60;
	// lwz r11,160(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 160);
	// lwz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// ld r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r30.u32 + 8);
	// twllei r10,0
	// divwu r11,r11,r10
	ctx.r11.u32 = ppc_divwu(ctx.r11.u32, ctx.r10.u32);
	// addi r11,r11,-12
	ctx.r11.s64 = ctx.r11.s64 + -12;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// mulld r11,r11,r9
	ctx.r11.s64 = ctx.r11.s64 * ctx.r9.s64;
	// std r11,8(r30)
	PPC_STORE_U64(ctx.r30.u32 + 8, ctx.r11.u64);
loc_8210DC60:
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210DC78;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
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

__attribute__((alias("__imp__sub_8210DC90"))) PPC_WEAK_FUNC(sub_8210DC90);
PPC_FUNC_IMPL(__imp__sub_8210DC90) {
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
	// lwz r11,52(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stfs f1,140(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210DCC8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f0,140(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,24832(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 24832);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x8210dcf0
	if (ctx.cr6.lt) goto loc_8210DCF0;
	// lfs f12,156(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 156);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x8210dcfc
	if (!ctx.cr6.gt) goto loc_8210DCFC;
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8210dcf8
	if (!ctx.cr6.lt) goto loc_8210DCF8;
loc_8210DCF0:
	// stfs f13,140(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// b 0x8210dcfc
	goto loc_8210DCFC;
loc_8210DCF8:
	// stfs f12,140(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
loc_8210DCFC:
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,140
	ctx.r6.s64 = ctx.r1.s64 + 140;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210DD20;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210DD3C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
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

__attribute__((alias("__imp__sub_8210DD58"))) PPC_WEAK_FUNC(sub_8210DD58);
PPC_FUNC_IMPL(__imp__sub_8210DD58) {
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
	// lwz r11,52(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210DD8C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// li r6,4
	ctx.r6.s64 = 4;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210DDAC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210DDC4;
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

__attribute__((alias("__imp__sub_8210DDDC"))) PPC_WEAK_FUNC(sub_8210DDDC);
PPC_FUNC_IMPL(__imp__sub_8210DDDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210DDE0"))) PPC_WEAK_FUNC(sub_8210DDE0);
PPC_FUNC_IMPL(__imp__sub_8210DDE0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8210DDE8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,52(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210DE0C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,168(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 168);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8210de40
	if (ctx.cr6.eq) goto loc_8210DE40;
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,48(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 48);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210DE34;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt 0x8210de40
	if (ctx.cr0.lt) goto loc_8210DE40;
	// stw r30,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r30.u32);
loc_8210DE40:
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210DE58;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210DE64"))) PPC_WEAK_FUNC(sub_8210DE64);
PPC_FUNC_IMPL(__imp__sub_8210DE64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210DE68"))) PPC_WEAK_FUNC(sub_8210DE68);
PPC_FUNC_IMPL(__imp__sub_8210DE68) {
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
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// addi r11,r3,8
	ctx.r11.s64 = ctx.r3.s64 + 8;
loc_8210DE84:
	// mfmsr r9
	ctx.r9.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r10,0,r11
	ctx.reserved.u32 = *(uint32_t*)(base + ctx.r11.u32);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stwcx. r10,0,r11
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + ctx.r11.u32), ctx.reserved.s32, __builtin_bswap32(ctx.r10.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x8210de84
	if (!ctx.cr0.eq) goto loc_8210DE84;
	// lwz r31,12(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8210dedc
	if (ctx.cr6.eq) goto loc_8210DEDC;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210DEC0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// rlwinm. r11,r30,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8210dedc
	if (ctx.cr0.eq) goto loc_8210DEDC;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210DEDC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8210DEDC:
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

__attribute__((alias("__imp__sub_8210DEF4"))) PPC_WEAK_FUNC(sub_8210DEF4);
PPC_FUNC_IMPL(__imp__sub_8210DEF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210DEF8"))) PPC_WEAK_FUNC(sub_8210DEF8);
PPC_FUNC_IMPL(__imp__sub_8210DEF8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8210DF00;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,64(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// li r28,0
	ctx.r28.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8210e04c
	if (ctx.cr6.eq) goto loc_8210E04C;
	// lwz r11,56(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// rlwinm. r11,r11,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8210df34
	if (ctx.cr0.eq) goto loc_8210DF34;
	// lis r30,-30570
	ctx.r30.s64 = -2003435520;
	// ori r30,r30,1
	ctx.r30.u64 = ctx.r30.u64 | 1;
	// b 0x8210e04c
	goto loc_8210E04C;
loc_8210DF34:
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r4,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r4.u32);
	// stw r4,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r4.u32);
	// stw r11,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// bl 0x8211b1b0
	ctx.lr = 0x8210DF4C;
	sub_8211B1B0(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x8210e04c
	if (ctx.cr0.lt) goto loc_8210E04C;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8210df6c
	if (ctx.cr6.eq) goto loc_8210DF6C;
	// bl 0x82119480
	ctx.lr = 0x8210DF64;
	sub_82119480(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x8210df70
	goto loc_8210DF70;
loc_8210DF6C:
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
loc_8210DF70:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8210e04c
	if (ctx.cr6.lt) goto loc_8210E04C;
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// rlwinm. r11,r11,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8210e01c
	if (ctx.cr0.eq) goto loc_8210E01C;
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// addi r29,r31,132
	ctx.r29.s64 = ctx.r31.s64 + 132;
	// lwz r4,132(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// bl 0x82108f58
	ctx.lr = 0x8210DF94;
	sub_82108F58(ctx, base);
	// stw r28,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r28.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// bl 0x8210b708
	ctx.lr = 0x8210DFA4;
	sub_8210B708(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x8210e04c
	if (ctx.cr0.lt) goto loc_8210E04C;
	// lwz r11,120(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r5,140(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// bl 0x8211a240
	ctx.lr = 0x8210DFCC;
	sub_8211A240(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,8(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210DFE8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8210e04c
	if (ctx.cr6.lt) goto loc_8210E04C;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8210e01c
	if (!ctx.cr6.eq) goto loc_8210E01C;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lis r4,4919
	ctx.r4.s64 = 322371584;
	// ori r4,r4,61441
	ctx.r4.u64 = ctx.r4.u64 | 61441;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210E018;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_8210E01C:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8210e04c
	if (ctx.cr6.lt) goto loc_8210E04C;
	// lwz r3,140(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// lis r5,4919
	ctx.r5.s64 = 322371584;
	// lwz r11,120(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// ori r5,r5,61441
	ctx.r5.u64 = ctx.r5.u64 | 61441;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,44(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210E048;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_8210E04C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210E058"))) PPC_WEAK_FUNC(sub_8210E058);
PPC_FUNC_IMPL(__imp__sub_8210E058) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,56(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// lwz r5,80(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8210e074
	if (ctx.cr6.eq) goto loc_8210E074;
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x8210e078
	goto loc_8210E078;
loc_8210E074:
	// lwz r4,60(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 60);
loc_8210E078:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r11,96(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 96);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8210E090"))) PPC_WEAK_FUNC(sub_8210E090);
PPC_FUNC_IMPL(__imp__sub_8210E090) {
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
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// rlwinm. r5,r4,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// beq 0x8210e0ec
	if (ctx.cr0.eq) goto loc_8210E0EC;
	// add r7,r3,r5
	ctx.r7.u64 = ctx.r3.u64 + ctx.r5.u64;
loc_8210E0CC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r6,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r6.s64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x8210e0ec
	if (!ctx.cr0.eq) goto loc_8210E0EC;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r7.s32, ctx.xer);
	// bne cr6,0x8210e0cc
	if (!ctx.cr6.eq) goto loc_8210E0CC;
loc_8210E0EC:
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x8210e10c
	if (ctx.cr0.eq) goto loc_8210E10C;
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// bl 0x8207dac0
	ctx.lr = 0x8210E0FC;
	sub_8207DAC0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8210d1d8
	ctx.lr = 0x8210E108;
	sub_8210D1D8(ctx, base);
	// b 0x8210e110
	goto loc_8210E110;
loc_8210E10C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8210E110:
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

__attribute__((alias("__imp__sub_8210E128"))) PPC_WEAK_FUNC(sub_8210E128);
PPC_FUNC_IMPL(__imp__sub_8210E128) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c970
	ctx.lr = 0x8210E130;
	__savegprlr_22(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r23,r6
	ctx.r23.u64 = ctx.r6.u64;
	// mr r31,r7
	ctx.r31.u64 = ctx.r7.u64;
	// mr r26,r8
	ctx.r26.u64 = ctx.r8.u64;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x8210e158
	if (!ctx.cr6.eq) goto loc_8210E158;
	// lwz r11,52(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// addi r31,r11,584
	ctx.r31.s64 = ctx.r11.s64 + 584;
loc_8210E158:
	// rlwinm. r11,r28,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8210e164
	if (ctx.cr0.eq) goto loc_8210E164;
	// ori r28,r28,2
	ctx.r28.u64 = ctx.r28.u64 | 2;
loc_8210E164:
	// stfs f1,156(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r30.u32 + 156, temp.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x821123b8
	ctx.lr = 0x8210E174;
	sub_821123B8(ctx, base);
	// stw r3,164(r30)
	PPC_STORE_U32(ctx.r30.u32 + 164, ctx.r3.u32);
	// lwz r11,4(r23)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + 4);
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// stw r11,168(r30)
	PPC_STORE_U32(ctx.r30.u32 + 168, ctx.r11.u32);
	// bl 0x821120d0
	ctx.lr = 0x8210E188;
	sub_821120D0(ctx, base);
	// sth r3,172(r30)
	PPC_STORE_U16(ctx.r30.u32 + 172, ctx.r3.u16);
	// lhz r11,12(r23)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r23.u32 + 12);
	// stw r11,160(r30)
	PPC_STORE_U32(ctx.r30.u32 + 160, ctx.r11.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8210e1a8
	if (!ctx.cr6.eq) goto loc_8210E1A8;
	// lwz r27,68(r30)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r30.u32 + 68);
	// b 0x8210e1b4
	goto loc_8210E1B4;
loc_8210E1A8:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r27,68(r11)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
loc_8210E1B4:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// bne cr6,0x8210e1e4
	if (!ctx.cr6.eq) goto loc_8210E1E4;
	// lwz r27,168(r30)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r30.u32 + 168);
	// li r11,375
	ctx.r11.s64 = 375;
	// divwu r11,r27,r11
	ctx.r11.u32 = ppc_divwu(ctx.r27.u32, ctx.r11.u32);
	// mulli r11,r11,375
	ctx.r11.s64 = ctx.r11.s64 * 375;
	// subf. r11,r11,r27
	ctx.r11.s64 = ctx.r27.s64 - ctx.r11.s64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8210e1e4
	if (ctx.cr0.eq) goto loc_8210E1E4;
	// subf r27,r11,r27
	ctx.r27.s64 = ctx.r27.s64 - ctx.r11.s64;
	// cmplwi cr6,r27,32000
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 32000, ctx.xer);
	// bge cr6,0x8210e1e4
	if (!ctx.cr6.lt) goto loc_8210E1E4;
	// addi r27,r27,375
	ctx.r27.s64 = ctx.r27.s64 + 375;
loc_8210E1E4:
	// lhz r11,2(r23)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r23.u32 + 2);
	// addi r29,r30,4
	ctx.r29.s64 = ctx.r30.s64 + 4;
	// stw r27,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r27.u32);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// stw r27,68(r30)
	PPC_STORE_U32(ctx.r30.u32 + 68, ctx.r27.u32);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r11,64(r30)
	PPC_STORE_U32(ctx.r30.u32 + 64, ctx.r11.u32);
	// bl 0x8211b6e0
	ctx.lr = 0x8210E20C;
	sub_8211B6E0(ctx, base);
	// li r25,0
	ctx.r25.s64 = 0;
	// lis r11,4919
	ctx.r11.s64 = 322371584;
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// stw r25,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r25.u32);
	// stw r25,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r25.u32);
	// ori r22,r11,61441
	ctx.r22.u64 = ctx.r11.u64 | 61441;
	// blt 0x8210e44c
	if (ctx.cr0.lt) goto loc_8210E44C;
	// lhz r11,0(r23)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r23.u32 + 0);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x8210e240
	if (!ctx.cr6.eq) goto loc_8210E240;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8210b828
	ctx.lr = 0x8210E23C;
	sub_8210B828(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_8210E240:
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt cr6,0x8210e44c
	if (ctx.cr6.lt) goto loc_8210E44C;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// rlwinm. r24,r28,0,30,30
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// li r28,1
	ctx.r28.s64 = 1;
	// addi r26,r11,24816
	ctx.r26.s64 = ctx.r11.s64 + 24816;
	// beq 0x8210e268
	if (ctx.cr0.eq) goto loc_8210E268;
	// lwz r11,168(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 168);
	// cmplw cr6,r11,r27
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r27.u32, ctx.xer);
	// beq cr6,0x8210e2f8
	if (ctx.cr6.eq) goto loc_8210E2F8;
loc_8210E268:
	// addi r3,r1,100
	ctx.r3.s64 = ctx.r1.s64 + 100;
	// bl 0x8210b5e8
	ctx.lr = 0x8210E270;
	sub_8210B5E8(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x8210e44c
	if (ctx.cr0.lt) goto loc_8210E44C;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// lfs f0,14004(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 14004);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// bne cr6,0x8210e2a4
	if (!ctx.cr6.eq) goto loc_8210E2A4;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f0,156(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 156);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lfs f0,24832(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 24832);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
loc_8210E2A4:
	// stw r25,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r25.u32);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210E2C4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,104(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r11,24(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210E2E0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,104(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210E2F4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r28,176(r30)
	PPC_STORE_U32(ctx.r30.u32 + 176, ctx.r28.u32);
loc_8210E2F8:
	// lwz r11,96(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8210e380
	if (!ctx.cr6.eq) goto loc_8210E380;
	// lwz r11,100(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8210e380
	if (!ctx.cr6.eq) goto loc_8210E380;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8210b798
	ctx.lr = 0x8210E318;
	sub_8210B798(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x8210e44c
	if (ctx.cr0.lt) goto loc_8210E44C;
	// stw r28,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r28.u32);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// stw r28,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r28.u32);
	// addi r5,r1,108
	ctx.r5.s64 = ctx.r1.s64 + 108;
	// stw r25,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r25.u32);
	// stw r25,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r25.u32);
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210E34C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,108(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,12
	ctx.r5.s64 = 12;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r11,24(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210E368;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,108(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210E37C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r28,180(r30)
	PPC_STORE_U32(ctx.r30.u32 + 180, ctx.r28.u32);
loc_8210E380:
	// lwz r11,52(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 52);
	// addi r9,r30,144
	ctx.r9.s64 = ctx.r30.s64 + 144;
	// lwz r3,120(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 120);
	// addi r10,r30,140
	ctx.r10.s64 = ctx.r30.s64 + 140;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r5,64
	ctx.r5.s64 = 64;
	// lwz r7,100(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// lwz r6,96(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r11,176(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// stw r22,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r22.u32);
	// lwz r31,0(r11)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210E3C8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x8210e44c
	if (ctx.cr0.eq) goto loc_8210E44C;
	// lis r11,-32761
	ctx.r11.s64 = -2147024896;
	// ori r11,r11,14
	ctx.r11.u64 = ctx.r11.u64 | 14;
	// cmpw cr6,r31,r11
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x8210e44c
	if (ctx.cr6.eq) goto loc_8210E44C;
	// lis r11,-32768
	ctx.r11.s64 = -2147483648;
	// ori r11,r11,16385
	ctx.r11.u64 = ctx.r11.u64 | 16385;
	// cmpw cr6,r31,r11
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x8210e44c
	if (ctx.cr6.eq) goto loc_8210E44C;
	// srawi r11,r31,16
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0xFFFF) != 0);
	ctx.r11.s64 = ctx.r31.s32 >> 16;
	// clrlwi r11,r11,19
	ctx.r11.u64 = ctx.r11.u32 & 0x1FFF;
	// cmpwi cr6,r11,2198
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2198, ctx.xer);
	// beq cr6,0x8210e44c
	if (ctx.cr6.eq) goto loc_8210E44C;
	// lis r11,-30600
	ctx.r11.s64 = -2005401600;
	// ori r11,r11,120
	ctx.r11.u64 = ctx.r11.u64 | 120;
	// subf. r11,r11,r31
	ctx.r11.s64 = ctx.r31.s64 - ctx.r11.s64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8210e444
	if (ctx.cr0.eq) goto loc_8210E444;
	// cmplwi cr6,r11,30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 30, ctx.xer);
	// beq cr6,0x8210e444
	if (ctx.cr6.eq) goto loc_8210E444;
	// lis r10,15
	ctx.r10.s64 = 983040;
	// ori r10,r10,65417
	ctx.r10.u64 = ctx.r10.u64 | 65417;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8210e444
	if (ctx.cr6.eq) goto loc_8210E444;
	// lis r10,30
	ctx.r10.s64 = 1966080;
	// ori r10,r10,65417
	ctx.r10.u64 = ctx.r10.u64 | 65417;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8210e44c
	if (!ctx.cr6.eq) goto loc_8210E44C;
	// lis r31,-30570
	ctx.r31.s64 = -2003435520;
	// ori r31,r31,3
	ctx.r31.u64 = ctx.r31.u64 | 3;
	// b 0x8210e44c
	goto loc_8210E44C;
loc_8210E444:
	// lis r31,-30570
	ctx.r31.s64 = -2003435520;
	// ori r31,r31,4
	ctx.r31.u64 = ctx.r31.u64 | 4;
loc_8210E44C:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821082b0
	ctx.lr = 0x8210E454;
	sub_821082B0(ctx, base);
	// addi r3,r1,100
	ctx.r3.s64 = ctx.r1.s64 + 100;
	// bl 0x821082b0
	ctx.lr = 0x8210E45C;
	sub_821082B0(ctx, base);
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt cr6,0x8210e4b8
	if (ctx.cr6.lt) goto loc_8210E4B8;
	// lwz r11,180(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 180);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8210e490
	if (ctx.cr6.eq) goto loc_8210E490;
	// lwz r3,144(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 144);
	// mr r5,r22
	ctx.r5.u64 = ctx.r22.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210E48C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_8210E490:
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt cr6,0x8210e4b8
	if (ctx.cr6.lt) goto loc_8210E4B8;
	// lwz r11,52(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 52);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// lwz r3,176(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,72(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210E4B4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_8210E4B8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9c0
	__restgprlr_22(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210E4C4"))) PPC_WEAK_FUNC(sub_8210E4C4);
PPC_FUNC_IMPL(__imp__sub_8210E4C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210E4C8"))) PPC_WEAK_FUNC(sub_8210E4C8);
PPC_FUNC_IMPL(__imp__sub_8210E4C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x8210E4D0;
	__savegprlr_24(ctx, base);
	// addi r31,r1,-160
	ctx.r31.s64 = ctx.r1.s64 + -160;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// mr r24,r6
	ctx.r24.u64 = ctx.r6.u64;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne cr6,0x8210e4f8
	if (!ctx.cr6.eq) goto loc_8210E4F8;
	// lis r26,4919
	ctx.r26.s64 = 322371584;
	// ori r26,r26,61441
	ctx.r26.u64 = ctx.r26.u64 | 61441;
	// b 0x8210e4fc
	goto loc_8210E4FC;
loc_8210E4F8:
	// mr r26,r24
	ctx.r26.u64 = ctx.r24.u64;
loc_8210E4FC:
	// lwz r11,52(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 52);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210e510
	if (ctx.cr6.eq) goto loc_8210E510;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x8210e514
	goto loc_8210E514;
loc_8210E510:
	// lwz r11,60(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 60);
loc_8210E514:
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
	// rlwinm r12,r11,0,0,27
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x8215c0b4
	ctx.lr = 0x8210E524;
	sub_8215C0B4(ctx, base);
	// lwz r11,0(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// stwux r11,r1,r12
	ea = ctx.r1.u32 + ctx.r12.u32;
	PPC_STORE_U32(ea, ctx.r11.u32);
	ctx.r1.u32 = ea;
	// addic. r29,r1,80
	ctx.xer.ca = ctx.r1.u32 > 4294967215;
	ctx.r29.s64 = ctx.r1.s64 + 80;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq 0x8210e558
	if (ctx.cr0.eq) goto loc_8210E558;
	// li r27,0
	ctx.r27.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// subf r8,r29,r5
	ctx.r8.s64 = ctx.r5.s64 - ctx.r29.s64;
loc_8210E544:
	// lwz r10,52(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 52);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8210e564
	if (ctx.cr6.eq) goto loc_8210E564;
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x8210e568
	goto loc_8210E568;
loc_8210E558:
	// lis r27,-32761
	ctx.r27.s64 = -2147024896;
	// ori r27,r27,14
	ctx.r27.u64 = ctx.r27.u64 | 14;
	// b 0x8210e60c
	goto loc_8210E60C;
loc_8210E564:
	// lwz r10,60(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 60);
loc_8210E568:
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8210e5a4
	if (!ctx.cr6.lt) goto loc_8210E5A4;
	// lwz r10,56(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 56);
	// lfs f0,72(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 72);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm. r10,r10,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8210e58c
	if (ctx.cr0.eq) goto loc_8210E58C;
	// lwz r10,48(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 48);
	// lfs f13,528(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 528);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
loc_8210E58C:
	// lfsx f13,r8,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// b 0x8210e544
	goto loc_8210E544;
loc_8210E5A4:
	// lwz r30,32(r28)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r28.u32 + 32);
	// b 0x8210e5dc
	goto loc_8210E5DC;
loc_8210E5AC:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8210e5c4
	if (ctx.cr6.eq) goto loc_8210E5C4;
	// lwz r30,4(r30)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x8210e5c8
	goto loc_8210E5C8;
loc_8210E5C4:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8210E5C8:
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// bl 0x8210e090
	ctx.lr = 0x8210E5DC;
	sub_8210E090(ctx, base);
loc_8210E5DC:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x8210e5ac
	if (!ctx.cr6.eq) goto loc_8210E5AC;
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// bne cr6,0x8210e60c
	if (!ctx.cr6.eq) goto loc_8210E60C;
	// lwz r11,48(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 48);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// lwz r3,176(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,72(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210E608;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
loc_8210E60C:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r1,r31,160
	ctx.r1.s64 = ctx.r31.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210E618"))) PPC_WEAK_FUNC(sub_8210E618);
PPC_FUNC_IMPL(__imp__sub_8210E618) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8211ad38
	ctx.lr = 0x8210E644;
	sub_8211AD38(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// stw r30,152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 152, ctx.r30.u32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// li r11,0
	ctx.r11.s64 = 0;
	// lfs f0,14004(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14004);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r8,25000
	ctx.r10.s64 = ctx.r8.s64 + 25000;
	// addi r9,r9,24872
	ctx.r9.s64 = ctx.r9.s64 + 24872;
	// stfs f0,156(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 156, temp.u32);
	// addi r8,r7,24836
	ctx.r8.s64 = ctx.r7.s64 + 24836;
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r8,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r8.u32);
	// stw r11,144(r31)
	PPC_STORE_U32(ctx.r31.u32 + 144, ctx.r11.u32);
	// stw r11,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r11.u32);
	// stw r11,160(r31)
	PPC_STORE_U32(ctx.r31.u32 + 160, ctx.r11.u32);
	// stw r11,164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 164, ctx.r11.u32);
	// stw r11,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r11.u32);
	// sth r11,172(r31)
	PPC_STORE_U16(ctx.r31.u32 + 172, ctx.r11.u16);
	// stw r11,176(r31)
	PPC_STORE_U32(ctx.r31.u32 + 176, ctx.r11.u32);
	// stw r11,180(r31)
	PPC_STORE_U32(ctx.r31.u32 + 180, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_8210E6B8"))) PPC_WEAK_FUNC(sub_8210E6B8);
PPC_FUNC_IMPL(__imp__sub_8210E6B8) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// b 0x8211ae00
	sub_8211AE00(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210E6C0"))) PPC_WEAK_FUNC(sub_8210E6C0);
PPC_FUNC_IMPL(__imp__sub_8210E6C0) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// b 0x8211a668
	sub_8211A668(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210E6C8"))) PPC_WEAK_FUNC(sub_8210E6C8);
PPC_FUNC_IMPL(__imp__sub_8210E6C8) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// b 0x8211a6d0
	sub_8211A6D0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210E6D0"))) PPC_WEAK_FUNC(sub_8210E6D0);
PPC_FUNC_IMPL(__imp__sub_8210E6D0) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// b 0x8211a730
	sub_8211A730(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210E6D8"))) PPC_WEAK_FUNC(sub_8210E6D8);
PPC_FUNC_IMPL(__imp__sub_8210E6D8) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// b 0x8211a040
	sub_8211A040(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210E6E0"))) PPC_WEAK_FUNC(sub_8210E6E0);
PPC_FUNC_IMPL(__imp__sub_8210E6E0) {
	PPC_FUNC_PROLOGUE();
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8210E6E8"))) PPC_WEAK_FUNC(sub_8210E6E8);
PPC_FUNC_IMPL(__imp__sub_8210E6E8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,160(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8210E6F0"))) PPC_WEAK_FUNC(sub_8210E6F0);
PPC_FUNC_IMPL(__imp__sub_8210E6F0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,52(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// bne cr6,0x8210e730
	if (!ctx.cr6.eq) goto loc_8210E730;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r11,52(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// lwz r9,176(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 176);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r10,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r10.u32);
	// lwz r11,52(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// lwz r10,180(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 180);
	// lwz r9,40(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// b 0x8210e75c
	goto loc_8210E75C;
loc_8210E730:
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r11,52(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// lwz r10,176(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 176);
	// lwz r9,36(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// subf r10,r10,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r10.s64;
	// stw r10,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r10.u32);
	// lwz r11,52(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// lwz r10,180(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 180);
	// lwz r9,40(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// subf r10,r10,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r10.s64;
loc_8210E75C:
	// stw r10,40(r11)
	PPC_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8210E764"))) PPC_WEAK_FUNC(sub_8210E764);
PPC_FUNC_IMPL(__imp__sub_8210E764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210E768"))) PPC_WEAK_FUNC(sub_8210E768);
PPC_FUNC_IMPL(__imp__sub_8210E768) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x8210e6d0
	sub_8210E6D0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210E770"))) PPC_WEAK_FUNC(sub_8210E770);
PPC_FUNC_IMPL(__imp__sub_8210E770) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x8210e6c8
	sub_8210E6C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210E778"))) PPC_WEAK_FUNC(sub_8210E778);
PPC_FUNC_IMPL(__imp__sub_8210E778) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x8210e6c0
	sub_8210E6C0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210E780"))) PPC_WEAK_FUNC(sub_8210E780);
PPC_FUNC_IMPL(__imp__sub_8210E780) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x8210e818
	sub_8210E818(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210E788"))) PPC_WEAK_FUNC(sub_8210E788);
PPC_FUNC_IMPL(__imp__sub_8210E788) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x82113440
	sub_82113440(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210E790"))) PPC_WEAK_FUNC(sub_8210E790);
PPC_FUNC_IMPL(__imp__sub_8210E790) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x8210e6d8
	sub_8210E6D8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210E798"))) PPC_WEAK_FUNC(sub_8210E798);
PPC_FUNC_IMPL(__imp__sub_8210E798) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x821136e0
	sub_821136E0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210E7A0"))) PPC_WEAK_FUNC(sub_8210E7A0);
PPC_FUNC_IMPL(__imp__sub_8210E7A0) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x8210d320
	sub_8210D320(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210E7A8"))) PPC_WEAK_FUNC(sub_8210E7A8);
PPC_FUNC_IMPL(__imp__sub_8210E7A8) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x8210d458
	sub_8210D458(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210E7B0"))) PPC_WEAK_FUNC(sub_8210E7B0);
PPC_FUNC_IMPL(__imp__sub_8210E7B0) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x8210d3a0
	sub_8210D3A0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210E7B8"))) PPC_WEAK_FUNC(sub_8210E7B8);
PPC_FUNC_IMPL(__imp__sub_8210E7B8) {
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
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r10,25000
	ctx.r10.s64 = ctx.r10.s64 + 25000;
	// addi r9,r9,24836
	ctx.r9.s64 = ctx.r9.s64 + 24836;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// addi r31,r3,4
	ctx.r31.s64 = ctx.r3.s64 + 4;
	// stw r9,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r9.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// addi r3,r31,80
	ctx.r3.s64 = ctx.r31.s64 + 80;
	// bl 0x8210ef58
	ctx.lr = 0x8210E7F8;
	sub_8210EF58(ctx, base);
	// addi r3,r31,8
	ctx.r3.s64 = ctx.r31.s64 + 8;
	// bl 0x8210ef58
	ctx.lr = 0x8210E800;
	sub_8210EF58(ctx, base);
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

__attribute__((alias("__imp__sub_8210E814"))) PPC_WEAK_FUNC(sub_8210E814);
PPC_FUNC_IMPL(__imp__sub_8210E814) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210E818"))) PPC_WEAK_FUNC(sub_8210E818);
PPC_FUNC_IMPL(__imp__sub_8210E818) {
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
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x8210e7b8
	ctx.lr = 0x8210E838;
	sub_8210E7B8(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8210e848
	if (ctx.cr0.eq) goto loc_8210E848;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82114628
	ctx.lr = 0x8210E848;
	sub_82114628(ctx, base);
loc_8210E848:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
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

__attribute__((alias("__imp__sub_8210E864"))) PPC_WEAK_FUNC(sub_8210E864);
PPC_FUNC_IMPL(__imp__sub_8210E864) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210E868"))) PPC_WEAK_FUNC(sub_8210E868);
PPC_FUNC_IMPL(__imp__sub_8210E868) {
	PPC_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,200(r3)
	PPC_STORE_U32(ctx.r3.u32 + 200, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8210E874"))) PPC_WEAK_FUNC(sub_8210E874);
PPC_FUNC_IMPL(__imp__sub_8210E874) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210E878"))) PPC_WEAK_FUNC(sub_8210E878);
PPC_FUNC_IMPL(__imp__sub_8210E878) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8210E87C"))) PPC_WEAK_FUNC(sub_8210E87C);
PPC_FUNC_IMPL(__imp__sub_8210E87C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210E880"))) PPC_WEAK_FUNC(sub_8210E880);
PPC_FUNC_IMPL(__imp__sub_8210E880) {
	PPC_FUNC_PROLOGUE();
	// clrldi r11,r3,32
	ctx.r11.u64 = ctx.r3.u64 & 0xFFFFFFFF;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r11.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fmuls f0,f0,f1
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f1.f64));
	// beq cr6,0x8210e8c0
	if (ctx.cr6.eq) goto loc_8210E8C0;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfd f13,2064(r11)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r11.u32 + 2064);
	// fadd f0,f0,f13
	ctx.f0.f64 = ctx.f0.f64 + ctx.f13.f64;
	// fctidz f0,f0
	ctx.f0.s64 = (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f0.u64);
	// lwz r11,-12(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// blr 
	return;
loc_8210E8C0:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfd f13,2072(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r11.u32 + 2072);
	// fadd f0,f0,f13
	ctx.f0.f64 = ctx.f0.f64 + ctx.f13.f64;
	// fctidz f0,f0
	ctx.f0.s64 = (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f0.u64);
	// lwz r3,-12(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8210E8DC"))) PPC_WEAK_FUNC(sub_8210E8DC);
PPC_FUNC_IMPL(__imp__sub_8210E8DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210E8E0"))) PPC_WEAK_FUNC(sub_8210E8E0);
PPC_FUNC_IMPL(__imp__sub_8210E8E0) {
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
	// lwz r11,52(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210E910;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,352(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 352);
	// addi r30,r31,352
	ctx.r30.s64 = ctx.r31.s64 + 352;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210E928;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,420(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 420);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210e95c
	if (ctx.cr6.eq) goto loc_8210E95C;
	// lwz r11,416(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 416);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210e948
	if (ctx.cr6.eq) goto loc_8210E948;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x8210e94c
	goto loc_8210E94C;
loc_8210E948:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8210E94C:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// ori r10,r10,64
	ctx.r10.u64 = ctx.r10.u64 | 64;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// b 0x8210e964
	goto loc_8210E964;
loc_8210E95C:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 200, ctx.r11.u32);
loc_8210E964:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210E978;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210E990;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
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

__attribute__((alias("__imp__sub_8210E9AC"))) PPC_WEAK_FUNC(sub_8210E9AC);
PPC_FUNC_IMPL(__imp__sub_8210E9AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210E9B0"))) PPC_WEAK_FUNC(sub_8210E9B0);
PPC_FUNC_IMPL(__imp__sub_8210E9B0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8210E9B8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,52(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210E9DC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,352(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 352);
	// addi r30,r31,352
	ctx.r30.s64 = ctx.r31.s64 + 352;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210E9F4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,420(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 420);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210ea1c
	if (ctx.cr6.eq) goto loc_8210EA1C;
	// lwz r11,412(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 412);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210ea14
	if (ctx.cr6.eq) goto loc_8210EA14;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x8210ea18
	goto loc_8210EA18;
loc_8210EA14:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8210EA18:
	// lwz r11,24(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
loc_8210EA1C:
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210EA34;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,148(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// stw r11,4(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4, ctx.r11.u32);
	// lwz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// ld r11,232(r31)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r31.u32 + 232);
	// divdu r11,r11,r10
	ctx.r11.u64 = ppc_divdu(ctx.r11.u64, ctx.r10.u64);
	// std r11,8(r29)
	PPC_STORE_U64(ctx.r29.u32 + 8, ctx.r11.u64);
	// tdllei r10,0
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210EA6C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210EA74"))) PPC_WEAK_FUNC(sub_8210EA74);
PPC_FUNC_IMPL(__imp__sub_8210EA74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210EA78"))) PPC_WEAK_FUNC(sub_8210EA78);
PPC_FUNC_IMPL(__imp__sub_8210EA78) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r3,0(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r4,r10
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8210ea98
	if (!ctx.cr6.eq) goto loc_8210EA98;
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r10,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r10.u32);
	// b 0x8210eaa4
	goto loc_8210EAA4;
loc_8210EA98:
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r9,4(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
loc_8210EAA4:
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmplw cr6,r4,r10
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8210eabc
	if (!ctx.cr6.eq) goto loc_8210EABC;
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r10,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r10.u32);
	// b 0x8210eac8
	goto loc_8210EAC8;
loc_8210EABC:
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r9,8(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
loc_8210EAC8:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r10.u32);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r4,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r4.u32);
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8210EAE4"))) PPC_WEAK_FUNC(sub_8210EAE4);
PPC_FUNC_IMPL(__imp__sub_8210EAE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210EAE8"))) PPC_WEAK_FUNC(sub_8210EAE8);
PPC_FUNC_IMPL(__imp__sub_8210EAE8) {
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
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x8210eb24
	if (!ctx.cr6.lt) goto loc_8210EB24;
	// bl 0x821d5474
	ctx.lr = 0x8210EB18;
	__imp__KeGetCurrentProcessType(ctx, base);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x8210eb24
	if (ctx.cr6.eq) goto loc_8210EB24;
	// li r30,1
	ctx.r30.s64 = 1;
loc_8210EB24:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210eb38
	if (ctx.cr6.eq) goto loc_8210EB38;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x8210eba4
	if (ctx.cr6.eq) goto loc_8210EBA4;
loc_8210EB38:
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r11,64
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 64, ctx.xer);
	// bgt cr6,0x8210eb94
	if (ctx.cr6.gt) goto loc_8210EB94;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,-5536
	ctx.r3.s64 = ctx.r11.s64 + -5536;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x82108aa8
	ctx.lr = 0x8210EB60;
	sub_82108AA8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8210eba4
	if (ctx.cr0.eq) goto loc_8210EBA4;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r3,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// b 0x8210eba4
	goto loc_8210EBA4;
loc_8210EB94:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r11,16296
	ctx.r3.s64 = ctx.r11.s64 + 16296;
	// bl 0x8208d988
	ctx.lr = 0x8210EBA0;
	sub_8208D988(ctx, base);
	// twi 31,r0,22
loc_8210EBA4:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8210ebbc
	if (ctx.cr6.eq) goto loc_8210EBBC;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// b 0x8210ebc0
	goto loc_8210EBC0;
loc_8210EBBC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8210EBC0:
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

__attribute__((alias("__imp__sub_8210EBD8"))) PPC_WEAK_FUNC(sub_8210EBD8);
PPC_FUNC_IMPL(__imp__sub_8210EBD8) {
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
	// bl 0x8210d290
	ctx.lr = 0x8210EBF4;
	sub_8210D290(ctx, base);
	// addi r30,r31,384
	ctx.r30.s64 = ctx.r31.s64 + 384;
	// b 0x8210ec08
	goto loc_8210EC08;
loc_8210EBFC:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8210ec08
	if (ctx.cr6.eq) goto loc_8210EC08;
	// bl 0x82114628
	ctx.lr = 0x8210EC08;
	sub_82114628(ctx, base);
loc_8210EC08:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82109678
	ctx.lr = 0x8210EC10;
	sub_82109678(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8210ebfc
	if (!ctx.cr0.eq) goto loc_8210EBFC;
	// addi r30,r31,424
	ctx.r30.s64 = ctx.r31.s64 + 424;
	// b 0x8210ec2c
	goto loc_8210EC2C;
loc_8210EC20:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8210ec2c
	if (ctx.cr6.eq) goto loc_8210EC2C;
	// bl 0x82114628
	ctx.lr = 0x8210EC2C;
	sub_82114628(ctx, base);
loc_8210EC2C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82109678
	ctx.lr = 0x8210EC34;
	sub_82109678(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8210ec20
	if (!ctx.cr0.eq) goto loc_8210EC20;
	// lwz r11,264(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 264);
	// addi r10,r31,240
	ctx.r10.s64 = ctx.r31.s64 + 240;
	// b 0x8210ec64
	goto loc_8210EC64;
loc_8210EC48:
	// lwz r11,24(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// rotlwi r11,r8,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// stw r8,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r8.u32);
loc_8210EC64:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8210ec48
	if (!ctx.cr6.eq) goto loc_8210EC48;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r11,r31,280
	ctx.r11.s64 = ctx.r31.s64 + 280;
	// stw r30,32(r10)
	PPC_STORE_U32(ctx.r10.u32 + 32, ctx.r30.u32);
	// stw r30,28(r10)
	PPC_STORE_U32(ctx.r10.u32 + 28, ctx.r30.u32);
	// lwz r10,304(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 304);
	// b 0x8210eca0
	goto loc_8210ECA0;
loc_8210EC84:
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// rotlwi r10,r8,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// stw r8,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r8.u32);
loc_8210ECA0:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8210ec84
	if (!ctx.cr6.eq) goto loc_8210EC84;
	// stw r30,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r30.u32);
	// stw r30,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r30.u32);
	// lwz r3,200(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 200);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8210ecc4
	if (ctx.cr6.eq) goto loc_8210ECC4;
	// bl 0x8211bdf0
	ctx.lr = 0x8210ECC0;
	sub_8211BDF0(ctx, base);
	// stw r30,200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 200, ctx.r30.u32);
loc_8210ECC4:
	// lwz r3,212(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 212);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8210ecd8
	if (ctx.cr6.eq) goto loc_8210ECD8;
	// bl 0x82114628
	ctx.lr = 0x8210ECD4;
	sub_82114628(ctx, base);
	// stw r30,212(r31)
	PPC_STORE_U32(ctx.r31.u32 + 212, ctx.r30.u32);
loc_8210ECD8:
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

__attribute__((alias("__imp__sub_8210ECF0"))) PPC_WEAK_FUNC(sub_8210ECF0);
PPC_FUNC_IMPL(__imp__sub_8210ECF0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x8210ECF8;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,52(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210ED18;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,352(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 352);
	// addi r26,r31,352
	ctx.r26.s64 = ctx.r31.s64 + 352;
	// li r25,0
	ctx.r25.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210ED34;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,420(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 420);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210edd4
	if (ctx.cr6.eq) goto loc_8210EDD4;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r30,412(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 412);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8210ed60
	if (!ctx.cr6.eq) goto loc_8210ED60;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8210edd4
	if (ctx.cr6.eq) goto loc_8210EDD4;
	// lwz r30,4(r30)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// b 0x8210ed7c
	goto loc_8210ED7C;
loc_8210ED60:
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210ED78;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
loc_8210ED7C:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8210edd4
	if (ctx.cr6.eq) goto loc_8210EDD4;
	// addi r28,r31,388
	ctx.r28.s64 = ctx.r31.s64 + 388;
	// addi r27,r31,140
	ctx.r27.s64 = ctx.r31.s64 + 140;
loc_8210ED8C:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8210eda8
	if (ctx.cr6.eq) goto loc_8210EDA8;
	// lwz r30,4(r30)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r29,0(r11)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x8210edac
	goto loc_8210EDAC;
loc_8210EDA8:
	// li r29,0
	ctx.r29.s64 = 0;
loc_8210EDAC:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8210ea78
	ctx.lr = 0x8210EDB4;
	sub_8210EA78(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r4,24(r29)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// bl 0x8210de68
	ctx.lr = 0x8210EDC4;
	sub_8210DE68(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82114628
	ctx.lr = 0x8210EDCC;
	sub_82114628(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x8210ed8c
	if (!ctx.cr6.eq) goto loc_8210ED8C;
loc_8210EDD4:
	// lwz r11,460(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 460);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,348(r31)
	PPC_STORE_U32(ctx.r31.u32 + 348, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210ee20
	if (ctx.cr6.eq) goto loc_8210EE20;
	// addi r29,r31,428
	ctx.r29.s64 = ctx.r31.s64 + 428;
loc_8210EDEC:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82109678
	ctx.lr = 0x8210EDF4;
	sub_82109678(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x8210ee14
	if (ctx.cr0.eq) goto loc_8210EE14;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,24(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// addi r3,r31,140
	ctx.r3.s64 = ctx.r31.s64 + 140;
	// bl 0x8210de68
	ctx.lr = 0x8210EE0C;
	sub_8210DE68(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82114628
	ctx.lr = 0x8210EE14;
	sub_82114628(ctx, base);
loc_8210EE14:
	// lwz r11,460(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 460);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8210edec
	if (!ctx.cr6.eq) goto loc_8210EDEC;
loc_8210EE20:
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210EE34;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210EE4C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210EE58"))) PPC_WEAK_FUNC(sub_8210EE58);
PPC_FUNC_IMPL(__imp__sub_8210EE58) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,128(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// addi r10,r3,104
	ctx.r10.s64 = ctx.r3.s64 + 104;
	// b 0x8210ee80
	goto loc_8210EE80;
loc_8210EE64:
	// lwz r11,24(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// rotlwi r11,r8,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// stw r8,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r8.u32);
loc_8210EE80:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8210ee64
	if (!ctx.cr6.eq) goto loc_8210EE64;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r3,144
	ctx.r11.s64 = ctx.r3.s64 + 144;
	// stw r9,32(r10)
	PPC_STORE_U32(ctx.r10.u32 + 32, ctx.r9.u32);
	// stw r9,28(r10)
	PPC_STORE_U32(ctx.r10.u32 + 28, ctx.r9.u32);
	// lwz r10,168(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// b 0x8210eebc
	goto loc_8210EEBC;
loc_8210EEA0:
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r7,4(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r8,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r8.u32);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// rotlwi r10,r7,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// stw r7,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r7.u32);
loc_8210EEBC:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8210eea0
	if (!ctx.cr6.eq) goto loc_8210EEA0;
	// stw r9,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r9.u32);
	// stw r9,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r9.u32);
	// stw r9,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8210EED4"))) PPC_WEAK_FUNC(sub_8210EED4);
PPC_FUNC_IMPL(__imp__sub_8210EED4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210EED8"))) PPC_WEAK_FUNC(sub_8210EED8);
PPC_FUNC_IMPL(__imp__sub_8210EED8) {
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
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x8210eae8
	ctx.lr = 0x8210EEF8;
	sub_8210EAE8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8210ef3c
	if (ctx.cr0.eq) goto loc_8210EF3C;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210ef28
	if (ctx.cr6.eq) goto loc_8210EF28;
	// stw r3,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r3.u32);
	// b 0x8210ef2c
	goto loc_8210EF2C;
loc_8210EF28:
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
loc_8210EF2C:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// stw r3,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r3.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
loc_8210EF3C:
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

__attribute__((alias("__imp__sub_8210EF54"))) PPC_WEAK_FUNC(sub_8210EF54);
PPC_FUNC_IMPL(__imp__sub_8210EF54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210EF58"))) PPC_WEAK_FUNC(sub_8210EF58);
PPC_FUNC_IMPL(__imp__sub_8210EF58) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8210EF60;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x8210ef84
	goto loc_8210EF84;
loc_8210EF6C:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r9,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r9.u32);
loc_8210EF84:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8210ef6c
	if (!ctx.cr6.eq) goto loc_8210EF6C;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r28,0
	ctx.r28.s64 = 0;
	// stw r28,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r28.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r28,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r28.u32);
	// beq cr6,0x8210efdc
	if (ctx.cr6.eq) goto loc_8210EFDC;
	// addi r29,r31,8
	ctx.r29.s64 = ctx.r31.s64 + 8;
loc_8210EFAC:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplw cr6,r3,r29
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r29.u32, ctx.xer);
	// lwz r30,0(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// beq cr6,0x8210efcc
	if (ctx.cr6.eq) goto loc_8210EFCC;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8210efcc
	if (ctx.cr6.eq) goto loc_8210EFCC;
	// bl 0x82114628
	ctx.lr = 0x8210EFC8;
	sub_82114628(ctx, base);
	// stw r28,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r28.u32);
loc_8210EFCC:
	// rotlwi r11,r30,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r30.u32, 0);
	// stw r30,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8210efac
	if (!ctx.cr6.eq) goto loc_8210EFAC;
loc_8210EFDC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210EFE4"))) PPC_WEAK_FUNC(sub_8210EFE4);
PPC_FUNC_IMPL(__imp__sub_8210EFE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210EFE8"))) PPC_WEAK_FUNC(sub_8210EFE8);
PPC_FUNC_IMPL(__imp__sub_8210EFE8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x8210EFF0;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,52(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210F018;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,-5536
	ctx.r3.s64 = ctx.r11.s64 + -5536;
	// ori r5,r5,2
	ctx.r5.u64 = ctx.r5.u64 | 2;
	// li r4,36
	ctx.r4.s64 = 36;
	// bl 0x82108aa8
	ctx.lr = 0x8210F034;
	sub_82108AA8(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x8210f048
	if (!ctx.cr0.eq) goto loc_8210F048;
	// lis r29,-32761
	ctx.r29.s64 = -2147024896;
	// ori r29,r29,14
	ctx.r29.u64 = ctx.r29.u64 | 14;
	// b 0x8210f184
	goto loc_8210F184;
loc_8210F048:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r11,64(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 64);
	// mullw r11,r10,r11
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8210f090
	if (ctx.cr6.eq) goto loc_8210F090;
	// lwz r11,64(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 64);
	// mullw r11,r10,r11
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// b 0x8210f0cc
	goto loc_8210F0CC;
loc_8210F090:
	// lwz r10,28(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8210f0b8
	if (!ctx.cr6.eq) goto loc_8210F0B8;
	// lwz r9,4(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r10,-4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// subf r11,r11,r10
	ctx.r11.s64 = ctx.r10.s64 - ctx.r11.s64;
	// b 0x8210f0cc
	goto loc_8210F0CC;
loc_8210F0B8:
	// lwz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r11,-4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -4);
loc_8210F0CC:
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// addi r27,r28,352
	ctx.r27.s64 = ctx.r28.s64 + 352;
	// lwz r11,28(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r11,32(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// lwz r11,4(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// lwz r11,352(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 352);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210F108;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r30,r28,148
	ctx.r30.s64 = ctx.r28.s64 + 148;
loc_8210F10C:
	// mfmsr r10
	ctx.r10.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r11,0,r30
	ctx.reserved.u32 = *(uint32_t*)(base + ctx.r30.u32);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwcx. r11,0,r30
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + ctx.r30.u32), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x8210f10c
	if (!ctx.cr0.eq) goto loc_8210F10C;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r28,388
	ctx.r3.s64 = ctx.r28.s64 + 388;
	// bl 0x8210eed8
	ctx.lr = 0x8210F134;
	sub_8210EED8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8210f144
	if (ctx.cr0.eq) goto loc_8210F144;
	// li r29,0
	ctx.r29.s64 = 0;
	// b 0x8210f170
	goto loc_8210F170;
loc_8210F144:
	// lis r29,-32761
	ctx.r29.s64 = -2147024896;
	// ori r29,r29,14
	ctx.r29.u64 = ctx.r29.u64 | 14;
loc_8210F14C:
	// mfmsr r10
	ctx.r10.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r11,0,r30
	ctx.reserved.u32 = *(uint32_t*)(base + ctx.r30.u32);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r30
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + ctx.r30.u32), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x8210f14c
	if (!ctx.cr0.eq) goto loc_8210F14C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82114628
	ctx.lr = 0x8210F170;
	sub_82114628(ctx, base);
loc_8210F170:
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210F184;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8210F184:
	// lwz r11,52(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 52);
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210F19C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210F1A8"))) PPC_WEAK_FUNC(sub_8210F1A8);
PPC_FUNC_IMPL(__imp__sub_8210F1A8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8210F1B0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,340(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 340);
	// addi r30,r3,352
	ctx.r30.s64 = ctx.r3.s64 + 352;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r11,352(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 352);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// beq cr6,0x8210f23c
	if (ctx.cr6.eq) goto loc_8210F23C;
	// bctrl 
	ctx.lr = 0x8210F1DC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,412(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 412);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210f1f4
	if (ctx.cr6.eq) goto loc_8210F1F4;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x8210f1f8
	goto loc_8210F1F8;
loc_8210F1F4:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_8210F1F8:
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// cmplwi cr6,r10,255
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 255, ctx.xer);
	// beq cr6,0x8210f20c
	if (ctx.cr6.eq) goto loc_8210F20C;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
loc_8210F20C:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r30,24(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// lwz r28,0(r11)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,20(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210F228;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r31,140
	ctx.r3.s64 = ctx.r31.s64 + 140;
	// bl 0x8210d1b0
	ctx.lr = 0x8210F238;
	sub_8210D1B0(ctx, base);
	// b 0x8210f274
	goto loc_8210F274;
loc_8210F23C:
	// bctrl 
	ctx.lr = 0x8210F240;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r31,388
	ctx.r3.s64 = ctx.r31.s64 + 388;
	// bl 0x82109678
	ctx.lr = 0x8210F248;
	sub_82109678(ctx, base);
	// lwz r11,352(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 352);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210F260;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r31,428
	ctx.r3.s64 = ctx.r31.s64 + 428;
	// bl 0x8210eed8
	ctx.lr = 0x8210F26C;
	sub_8210EED8(ctx, base);
	// li r29,0
	ctx.r29.s64 = 0;
	// stw r29,344(r31)
	PPC_STORE_U32(ctx.r31.u32 + 344, ctx.r29.u32);
loc_8210F274:
	// stw r29,188(r31)
	PPC_STORE_U32(ctx.r31.u32 + 188, ctx.r29.u32);
	// stw r29,192(r31)
	PPC_STORE_U32(ctx.r31.u32 + 192, ctx.r29.u32);
	// stw r29,200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 200, ctx.r29.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210F288"))) PPC_WEAK_FUNC(sub_8210F288);
PPC_FUNC_IMPL(__imp__sub_8210F288) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c96c
	ctx.lr = 0x8210F290;
	__savegprlr_21(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,240(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 240);
	// li r26,0
	ctx.r26.s64 = 0;
	// lwz r11,216(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 216);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r23,r4
	ctx.r23.u64 = ctx.r4.u64;
	// mr r27,r26
	ctx.r27.u64 = ctx.r26.u64;
	// mr r25,r26
	ctx.r25.u64 = ctx.r26.u64;
	// add r24,r10,r11
	ctx.r24.u64 = ctx.r10.u64 + ctx.r11.u64;
	// li r21,64
	ctx.r21.s64 = 64;
	// li r22,-2
	ctx.r22.s64 = -2;
loc_8210F2BC:
	// lwz r11,188(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 188);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8210f448
	if (!ctx.cr6.eq) goto loc_8210F448;
	// lwz r11,352(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 352);
	// addi r29,r31,352
	ctx.r29.s64 = ctx.r31.s64 + 352;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210F2E0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,412(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 412);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210f2f4
	if (ctx.cr6.eq) goto loc_8210F2F4;
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x8210f2f8
	goto loc_8210F2F8;
loc_8210F2F4:
	// mr r30,r26
	ctx.r30.u64 = ctx.r26.u64;
loc_8210F2F8:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8210f434
	if (ctx.cr6.eq) goto loc_8210F434;
	// lwz r9,12(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8210f334
	if (ctx.cr6.eq) goto loc_8210F334;
	// lwz r10,28(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 28);
loc_8210F314:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8210f334
	if (ctx.cr6.lt) goto loc_8210F334;
	// lwz r8,12(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8210f314
	if (!ctx.cr6.eq) goto loc_8210F314;
loc_8210F334:
	// lwz r10,196(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 196);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r9,188(r31)
	PPC_STORE_U32(ctx.r31.u32 + 188, ctx.r9.u32);
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// subf r10,r10,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r10.s64;
	// stw r10,192(r31)
	PPC_STORE_U32(ctx.r31.u32 + 192, ctx.r10.u32);
	// lwz r4,12(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// stw r26,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r26.u32);
	// beq cr6,0x8210f378
	if (ctx.cr6.eq) goto loc_8210F378;
	// lwz r10,28(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r11,-4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -4);
	// subf r4,r11,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r11.s64;
loc_8210F378:
	// addi r3,r31,244
	ctx.r3.s64 = ctx.r31.s64 + 244;
	// bl 0x82109f68
	ctx.lr = 0x8210F380;
	sub_82109F68(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8210f774
	if (ctx.cr0.eq) goto loc_8210F774;
	// lwz r11,20(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe. r11,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,340(r31)
	PPC_STORE_U32(ctx.r31.u32 + 340, ctx.r11.u32);
	// lwz r4,16(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// beq 0x8210f3a4
	if (ctx.cr0.eq) goto loc_8210F3A4;
	// li r4,-1
	ctx.r4.s64 = -1;
loc_8210F3A4:
	// addi r3,r31,284
	ctx.r3.s64 = ctx.r31.s64 + 284;
	// bl 0x82109f68
	ctx.lr = 0x8210F3AC;
	sub_82109F68(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8210f774
	if (ctx.cr0.eq) goto loc_8210F774;
	// lwz r11,340(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 340);
	// mr r27,r26
	ctx.r27.u64 = ctx.r26.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8210f3d4
	if (!ctx.cr6.eq) goto loc_8210F3D4;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,64
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 64, ctx.xer);
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// bne cr6,0x8210f3d8
	if (!ctx.cr6.eq) goto loc_8210F3D8;
loc_8210F3D4:
	// li r11,1
	ctx.r11.s64 = 1;
loc_8210F3D8:
	// stw r11,200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 200, ctx.r11.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// addi r11,r11,-64
	ctx.r11.s64 = ctx.r11.s64 + -64;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// stw r11,348(r31)
	PPC_STORE_U32(ctx.r31.u32 + 348, ctx.r11.u32);
	// lwz r11,20(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// lwz r29,24(r30)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// lwz r30,0(r30)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210F40C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,344(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 344);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8210f448
	if (!ctx.cr6.eq) goto loc_8210F448;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r31,140
	ctx.r3.s64 = ctx.r31.s64 + 140;
	// bl 0x8210d188
	ctx.lr = 0x8210F428;
	sub_8210D188(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,344(r31)
	PPC_STORE_U32(ctx.r31.u32 + 344, ctx.r11.u32);
	// b 0x8210f448
	goto loc_8210F448;
loc_8210F434:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210F448;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8210F448:
	// lwz r11,208(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 208);
	// addi r30,r31,208
	ctx.r30.s64 = ctx.r31.s64 + 208;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// blt cr6,0x8210f698
	if (ctx.cr6.lt) goto loc_8210F698;
	// beq cr6,0x8210f67c
	if (ctx.cr6.eq) goto loc_8210F67C;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bge cr6,0x8210f760
	if (!ctx.cr6.lt) goto loc_8210F760;
	// stw r26,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r26.u32);
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// lwz r4,212(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 212);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r3,204(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 204);
	// mr r7,r4
	ctx.r7.u64 = ctx.r4.u64;
	// stw r26,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r26.u32);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// stw r26,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r26.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// bl 0x82122ad0
	ctx.lr = 0x8210F494;
	sub_82122AD0(ctx, base);
	// mr. r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// blt 0x8210f790
	if (ctx.cr0.lt) goto loc_8210F790;
	// lwz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// lwz r9,96(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r11,328(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 328);
	// mullw r10,r10,r9
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// rlwinm r30,r10,1,0,30
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210f4e8
	if (ctx.cr6.eq) goto loc_8210F4E8;
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// blt cr6,0x8210f4cc
	if (ctx.cr6.lt) goto loc_8210F4CC;
	// subf r11,r30,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r30.s64;
	// stw r11,328(r31)
	PPC_STORE_U32(ctx.r31.u32 + 328, ctx.r11.u32);
	// b 0x8210f760
	goto loc_8210F760;
loc_8210F4CC:
	// subf r5,r11,r30
	ctx.r5.s64 = ctx.r30.s64 - ctx.r11.s64;
	// add r4,r11,r24
	ctx.r4.u64 = ctx.r11.u64 + ctx.r24.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x8207dac0
	ctx.lr = 0x8210F4DC;
	sub_8207DAC0(ctx, base);
	// lwz r11,328(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 328);
	// stw r26,328(r31)
	PPC_STORE_U32(ctx.r31.u32 + 328, ctx.r26.u32);
	// subf r30,r11,r30
	ctx.r30.s64 = ctx.r30.s64 - ctx.r11.s64;
loc_8210F4E8:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8210f760
	if (ctx.cr6.eq) goto loc_8210F760;
	// lwz r11,332(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 332);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// ble cr6,0x8210f508
	if (!ctx.cr6.gt) goto loc_8210F508;
	// subf r11,r30,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r30.s64;
	// stw r11,332(r31)
	PPC_STORE_U32(ctx.r31.u32 + 332, ctx.r11.u32);
	// b 0x8210f584
	goto loc_8210F584;
loc_8210F508:
	// lwz r10,316(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 316);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8210f55c
	if (ctx.cr6.eq) goto loc_8210F55C;
	// addi r29,r31,244
	ctx.r29.s64 = ctx.r31.s64 + 244;
	// addi r28,r31,284
	ctx.r28.s64 = ctx.r31.s64 + 284;
loc_8210F51C:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82109678
	ctx.lr = 0x8210F524;
	sub_82109678(ctx, base);
	// stw r3,328(r31)
	PPC_STORE_U32(ctx.r31.u32 + 328, ctx.r3.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82109678
	ctx.lr = 0x8210F530;
	sub_82109678(ctx, base);
	// lwz r11,332(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 332);
	// add r11,r3,r11
	ctx.r11.u64 = ctx.r3.u64 + ctx.r11.u64;
	// stw r11,332(r31)
	PPC_STORE_U32(ctx.r31.u32 + 332, ctx.r11.u32);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bgt cr6,0x8210f564
	if (ctx.cr6.gt) goto loc_8210F564;
	// lwz r10,324(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 324);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,324(r31)
	PPC_STORE_U32(ctx.r31.u32 + 324, ctx.r10.u32);
	// lwz r10,316(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 316);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8210f51c
	if (!ctx.cr6.eq) goto loc_8210F51C;
loc_8210F55C:
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// ble cr6,0x8210f570
	if (!ctx.cr6.gt) goto loc_8210F570;
loc_8210F564:
	// subf r11,r30,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r30.s64;
	// stw r11,332(r31)
	PPC_STORE_U32(ctx.r31.u32 + 332, ctx.r11.u32);
	// b 0x8210f578
	goto loc_8210F578;
loc_8210F570:
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// stw r26,332(r31)
	PPC_STORE_U32(ctx.r31.u32 + 332, ctx.r26.u32);
loc_8210F578:
	// lwz r11,324(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 324);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,324(r31)
	PPC_STORE_U32(ctx.r31.u32 + 324, ctx.r11.u32);
loc_8210F584:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8210f760
	if (ctx.cr6.eq) goto loc_8210F760;
	// lwz r10,220(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 220);
	// add r24,r30,r24
	ctx.r24.u64 = ctx.r30.u64 + ctx.r24.u64;
	// lwz r11,336(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 336);
	// add r25,r30,r25
	ctx.r25.u64 = ctx.r30.u64 + ctx.r25.u64;
	// lwz r9,216(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 216);
	// subf r23,r30,r23
	ctx.r23.s64 = ctx.r23.s64 - ctx.r30.s64;
	// mullw r11,r11,r10
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// subf r10,r9,r24
	ctx.r10.s64 = ctx.r24.s64 - ctx.r9.s64;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8210f760
	if (ctx.cr6.lt) goto loc_8210F760;
	// li r5,28
	ctx.r5.s64 = 28;
	// stw r26,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r26.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r26,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r26.u32);
	// addi r3,r1,124
	ctx.r3.s64 = ctx.r1.s64 + 124;
	// stw r21,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r21.u32);
	// bl 0x8207da20
	ctx.lr = 0x8210F5D0;
	sub_8207DA20(ctx, base);
	// lwz r11,324(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 324);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210f624
	if (ctx.cr6.eq) goto loc_8210F624;
	// lwz r11,460(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 460);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210f620
	if (ctx.cr6.eq) goto loc_8210F620;
	// addi r29,r31,428
	ctx.r29.s64 = ctx.r31.s64 + 428;
loc_8210F5EC:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82109678
	ctx.lr = 0x8210F5F4;
	sub_82109678(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x8210f614
	if (ctx.cr0.eq) goto loc_8210F614;
	// addi r3,r31,140
	ctx.r3.s64 = ctx.r31.s64 + 140;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r4,24(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// bl 0x8210de68
	ctx.lr = 0x8210F60C;
	sub_8210DE68(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82114628
	ctx.lr = 0x8210F614;
	sub_82114628(ctx, base);
loc_8210F614:
	// lwz r11,460(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 460);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8210f5ec
	if (!ctx.cr6.eq) goto loc_8210F5EC;
loc_8210F620:
	// stw r26,324(r31)
	PPC_STORE_U32(ctx.r31.u32 + 324, ctx.r26.u32);
loc_8210F624:
	// stw r25,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r25.u32);
	// mr r5,r22
	ctx.r5.u64 = ctx.r22.u64;
	// lwz r11,240(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 240);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r10,216(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 216);
	// stw r25,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r25.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210F658;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// ld r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r31.u32 + 232);
	// clrldi r11,r25,32
	ctx.r11.u64 = ctx.r25.u64 & 0xFFFFFFFF;
	// lwz r24,216(r31)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r31.u32 + 216);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r26,240(r31)
	PPC_STORE_U32(ctx.r31.u32 + 240, ctx.r26.u32);
	// mr r25,r26
	ctx.r25.u64 = ctx.r26.u64;
	// std r11,232(r31)
	PPC_STORE_U64(ctx.r31.u32 + 232, ctx.r11.u64);
	// b 0x8210f760
	goto loc_8210F760;
loc_8210F67C:
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,204(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 204);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r31,212
	ctx.r4.s64 = ctx.r31.s64 + 212;
	// bl 0x82122270
	ctx.lr = 0x8210F690;
	sub_82122270(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// b 0x8210f760
	goto loc_8210F760;
loc_8210F698:
	// lwz r11,188(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 188);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210f6d0
	if (ctx.cr6.eq) goto loc_8210F6D0;
	// lwz r3,204(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 204);
	// bl 0x8211c5e8
	ctx.lr = 0x8210F6AC;
	sub_8211C5E8(ctx, base);
	// li r11,2
	ctx.r11.s64 = 2;
	// addi r3,r31,244
	ctx.r3.s64 = ctx.r31.s64 + 244;
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// bl 0x82109678
	ctx.lr = 0x8210F6BC;
	sub_82109678(ctx, base);
	// stw r3,328(r31)
	PPC_STORE_U32(ctx.r31.u32 + 328, ctx.r3.u32);
	// addi r3,r31,284
	ctx.r3.s64 = ctx.r31.s64 + 284;
	// bl 0x82109678
	ctx.lr = 0x8210F6C8;
	sub_82109678(ctx, base);
	// stw r3,332(r31)
	PPC_STORE_U32(ctx.r31.u32 + 332, ctx.r3.u32);
	// b 0x8210f760
	goto loc_8210F760;
loc_8210F6D0:
	// lwz r11,352(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 352);
	// addi r28,r31,352
	ctx.r28.s64 = ctx.r31.s64 + 352;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210F6E8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,420(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 420);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8210f74c
	if (!ctx.cr6.eq) goto loc_8210F74C;
	// lwz r11,348(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 348);
	// mr r23,r26
	ctx.r23.u64 = ctx.r26.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8210f74c
	if (ctx.cr6.eq) goto loc_8210F74C;
	// lwz r11,460(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 460);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210f748
	if (ctx.cr6.eq) goto loc_8210F748;
	// addi r29,r31,428
	ctx.r29.s64 = ctx.r31.s64 + 428;
loc_8210F714:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82109678
	ctx.lr = 0x8210F71C;
	sub_82109678(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x8210f73c
	if (ctx.cr0.eq) goto loc_8210F73C;
	// addi r3,r31,140
	ctx.r3.s64 = ctx.r31.s64 + 140;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r4,24(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// bl 0x8210de68
	ctx.lr = 0x8210F734;
	sub_8210DE68(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82114628
	ctx.lr = 0x8210F73C;
	sub_82114628(ctx, base);
loc_8210F73C:
	// lwz r11,460(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 460);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8210f714
	if (!ctx.cr6.eq) goto loc_8210F714;
loc_8210F748:
	// stw r26,332(r31)
	PPC_STORE_U32(ctx.r31.u32 + 332, ctx.r26.u32);
loc_8210F74C:
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210F760;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8210F760:
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// blt cr6,0x8210f790
	if (ctx.cr6.lt) goto loc_8210F790;
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// bgt cr6,0x8210f2bc
	if (ctx.cr6.gt) goto loc_8210F2BC;
	// b 0x8210f790
	goto loc_8210F790;
loc_8210F774:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lis r27,-32761
	ctx.r27.s64 = -2147024896;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// ori r27,r27,14
	ctx.r27.u64 = ctx.r27.u64 | 14;
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210F790;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8210F790:
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x8210f85c
	if (ctx.cr6.eq) goto loc_8210F85C;
	// li r5,28
	ctx.r5.s64 = 28;
	// stw r26,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r26.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r26,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r26.u32);
	// addi r3,r1,124
	ctx.r3.s64 = ctx.r1.s64 + 124;
	// stw r21,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r21.u32);
	// bl 0x8207da20
	ctx.lr = 0x8210F7B4;
	sub_8207DA20(ctx, base);
	// lwz r11,324(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 324);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210f808
	if (ctx.cr6.eq) goto loc_8210F808;
	// lwz r11,460(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 460);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210f804
	if (ctx.cr6.eq) goto loc_8210F804;
	// addi r29,r31,428
	ctx.r29.s64 = ctx.r31.s64 + 428;
loc_8210F7D0:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82109678
	ctx.lr = 0x8210F7D8;
	sub_82109678(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x8210f7f8
	if (ctx.cr0.eq) goto loc_8210F7F8;
	// addi r3,r31,140
	ctx.r3.s64 = ctx.r31.s64 + 140;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r4,24(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// bl 0x8210de68
	ctx.lr = 0x8210F7F0;
	sub_8210DE68(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82114628
	ctx.lr = 0x8210F7F8;
	sub_82114628(ctx, base);
loc_8210F7F8:
	// lwz r11,460(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 460);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8210f7d0
	if (!ctx.cr6.eq) goto loc_8210F7D0;
loc_8210F804:
	// stw r26,324(r31)
	PPC_STORE_U32(ctx.r31.u32 + 324, ctx.r26.u32);
loc_8210F808:
	// stw r25,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r25.u32);
	// mr r5,r22
	ctx.r5.u64 = ctx.r22.u64;
	// stw r25,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r25.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r11,240(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 240);
	// lwz r10,216(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 216);
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210F83C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,240(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 240);
	// clrldi r11,r25,32
	ctx.r11.u64 = ctx.r25.u64 & 0xFFFFFFFF;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// add r9,r10,r25
	ctx.r9.u64 = ctx.r10.u64 + ctx.r25.u64;
	// ld r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r31.u32 + 232);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r9,240(r31)
	PPC_STORE_U32(ctx.r31.u32 + 240, ctx.r9.u32);
	// std r11,232(r31)
	PPC_STORE_U64(ctx.r31.u32 + 232, ctx.r11.u64);
loc_8210F85C:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x8207c9bc
	__restgprlr_21(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210F868"))) PPC_WEAK_FUNC(sub_8210F868);
PPC_FUNC_IMPL(__imp__sub_8210F868) {
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
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8210d138
	ctx.lr = 0x8210F890;
	sub_8210D138(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8210f8c4
	if (ctx.cr6.eq) goto loc_8210F8C4;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r31,-140
	ctx.r3.s64 = ctx.r31.s64 + -140;
	// bl 0x8210f288
	ctx.lr = 0x8210F8A4;
	sub_8210F288(ctx, base);
	// mr. r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bge 0x8210f8c4
	if (!ctx.cr0.lt) goto loc_8210F8C4;
	// lwz r11,-88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -88);
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210F8C4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8210F8C4:
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

__attribute__((alias("__imp__sub_8210F8DC"))) PPC_WEAK_FUNC(sub_8210F8DC);
PPC_FUNC_IMPL(__imp__sub_8210F8DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210F8E0"))) PPC_WEAK_FUNC(sub_8210F8E0);
PPC_FUNC_IMPL(__imp__sub_8210F8E0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8210F8E8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r29,1
	ctx.r29.s64 = 1;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210f95c
	if (ctx.cr6.eq) goto loc_8210F95C;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8210f944
	if (!ctx.cr6.gt) goto loc_8210F944;
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r11.u32);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r11,r11,r9
	ctx.r11.s64 = ctx.r9.s64 - ctx.r11.s64;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// stw r30,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, ctx.r30.u32);
	// b 0x8210f964
	goto loc_8210F964;
loc_8210F944:
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// lwz r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x8210f1a8
	ctx.lr = 0x8210F958;
	sub_8210F1A8(ctx, base);
	// b 0x8210f964
	goto loc_8210F964;
loc_8210F95C:
	// stw r30,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// stw r29,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r29.u32);
loc_8210F964:
	// stw r29,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r29.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r30,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// std r30,24(r31)
	PPC_STORE_U64(ctx.r31.u32 + 24, ctx.r30.u64);
	// stw r30,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r30.u32);
	// stw r30,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r30.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210F984"))) PPC_WEAK_FUNC(sub_8210F984);
PPC_FUNC_IMPL(__imp__sub_8210F984) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210F988"))) PPC_WEAK_FUNC(sub_8210F988);
PPC_FUNC_IMPL(__imp__sub_8210F988) {
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
	// bl 0x8210e618
	ctx.lr = 0x8210F9A0;
	sub_8210E618(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// addi r10,r10,25264
	ctx.r10.s64 = ctx.r10.s64 + 25264;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// addi r9,r31,244
	ctx.r9.s64 = ctx.r31.s64 + 244;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r8,r8,25152
	ctx.r8.s64 = ctx.r8.s64 + 25152;
	// addi r7,r7,25112
	ctx.r7.s64 = ctx.r7.s64 + 25112;
	// stw r11,204(r31)
	PPC_STORE_U32(ctx.r31.u32 + 204, ctx.r11.u32);
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// stw r8,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r7,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r7.u32);
	// stw r11,208(r31)
	PPC_STORE_U32(ctx.r31.u32 + 208, ctx.r11.u32);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// stw r11,212(r31)
	PPC_STORE_U32(ctx.r31.u32 + 212, ctx.r11.u32);
	// stw r11,216(r31)
	PPC_STORE_U32(ctx.r31.u32 + 216, ctx.r11.u32);
	// addi r7,r8,24644
	ctx.r7.s64 = ctx.r8.s64 + 24644;
	// stw r11,220(r31)
	PPC_STORE_U32(ctx.r31.u32 + 220, ctx.r11.u32);
	// stw r11,224(r31)
	PPC_STORE_U32(ctx.r31.u32 + 224, ctx.r11.u32);
	// std r11,232(r31)
	PPC_STORE_U64(ctx.r31.u32 + 232, ctx.r11.u64);
	// stw r11,240(r31)
	PPC_STORE_U32(ctx.r31.u32 + 240, ctx.r11.u32);
	// stw r9,248(r31)
	PPC_STORE_U32(ctx.r31.u32 + 248, ctx.r9.u32);
	// addi r9,r31,284
	ctx.r9.s64 = ctx.r31.s64 + 284;
	// stw r11,244(r31)
	PPC_STORE_U32(ctx.r31.u32 + 244, ctx.r11.u32);
	// stw r11,268(r31)
	PPC_STORE_U32(ctx.r31.u32 + 268, ctx.r11.u32);
	// addi r8,r9,8
	ctx.r8.s64 = ctx.r9.s64 + 8;
	// stw r11,272(r31)
	PPC_STORE_U32(ctx.r31.u32 + 272, ctx.r11.u32);
	// stw r11,276(r31)
	PPC_STORE_U32(ctx.r31.u32 + 276, ctx.r11.u32);
	// stw r10,280(r31)
	PPC_STORE_U32(ctx.r31.u32 + 280, ctx.r10.u32);
	// stw r11,252(r31)
	PPC_STORE_U32(ctx.r31.u32 + 252, ctx.r11.u32);
	// lwz r6,244(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 244);
	// lwz r9,248(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 248);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stw r6,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r6.u32);
	// stw r9,244(r31)
	PPC_STORE_U32(ctx.r31.u32 + 244, ctx.r9.u32);
	// stw r8,288(r31)
	PPC_STORE_U32(ctx.r31.u32 + 288, ctx.r8.u32);
	// addi r8,r31,428
	ctx.r8.s64 = ctx.r31.s64 + 428;
	// stw r11,284(r31)
	PPC_STORE_U32(ctx.r31.u32 + 284, ctx.r11.u32);
	// stw r11,308(r31)
	PPC_STORE_U32(ctx.r31.u32 + 308, ctx.r11.u32);
	// addi r8,r8,8
	ctx.r8.s64 = ctx.r8.s64 + 8;
	// stw r11,312(r31)
	PPC_STORE_U32(ctx.r31.u32 + 312, ctx.r11.u32);
	// stw r11,316(r31)
	PPC_STORE_U32(ctx.r31.u32 + 316, ctx.r11.u32);
	// stw r10,320(r31)
	PPC_STORE_U32(ctx.r31.u32 + 320, ctx.r10.u32);
	// stw r11,292(r31)
	PPC_STORE_U32(ctx.r31.u32 + 292, ctx.r11.u32);
	// lwz r6,284(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 284);
	// lwz r9,288(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 288);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stw r6,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r6.u32);
	// stw r9,284(r31)
	PPC_STORE_U32(ctx.r31.u32 + 284, ctx.r9.u32);
	// addi r9,r31,388
	ctx.r9.s64 = ctx.r31.s64 + 388;
	// stw r11,324(r31)
	PPC_STORE_U32(ctx.r31.u32 + 324, ctx.r11.u32);
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// stw r11,328(r31)
	PPC_STORE_U32(ctx.r31.u32 + 328, ctx.r11.u32);
	// stw r11,332(r31)
	PPC_STORE_U32(ctx.r31.u32 + 332, ctx.r11.u32);
	// stw r11,336(r31)
	PPC_STORE_U32(ctx.r31.u32 + 336, ctx.r11.u32);
	// stw r11,340(r31)
	PPC_STORE_U32(ctx.r31.u32 + 340, ctx.r11.u32);
	// stw r11,344(r31)
	PPC_STORE_U32(ctx.r31.u32 + 344, ctx.r11.u32);
	// stw r10,348(r31)
	PPC_STORE_U32(ctx.r31.u32 + 348, ctx.r10.u32);
	// stw r7,352(r31)
	PPC_STORE_U32(ctx.r31.u32 + 352, ctx.r7.u32);
	// stw r11,384(r31)
	PPC_STORE_U32(ctx.r31.u32 + 384, ctx.r11.u32);
	// stw r11,388(r31)
	PPC_STORE_U32(ctx.r31.u32 + 388, ctx.r11.u32);
	// stw r9,392(r31)
	PPC_STORE_U32(ctx.r31.u32 + 392, ctx.r9.u32);
	// stw r11,412(r31)
	PPC_STORE_U32(ctx.r31.u32 + 412, ctx.r11.u32);
	// stw r11,416(r31)
	PPC_STORE_U32(ctx.r31.u32 + 416, ctx.r11.u32);
	// stw r11,420(r31)
	PPC_STORE_U32(ctx.r31.u32 + 420, ctx.r11.u32);
	// stw r10,424(r31)
	PPC_STORE_U32(ctx.r31.u32 + 424, ctx.r10.u32);
	// stw r11,396(r31)
	PPC_STORE_U32(ctx.r31.u32 + 396, ctx.r11.u32);
	// lwz r7,388(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 388);
	// lwz r9,392(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 392);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stw r7,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r7.u32);
	// stw r9,388(r31)
	PPC_STORE_U32(ctx.r31.u32 + 388, ctx.r9.u32);
	// stw r11,428(r31)
	PPC_STORE_U32(ctx.r31.u32 + 428, ctx.r11.u32);
	// stw r8,432(r31)
	PPC_STORE_U32(ctx.r31.u32 + 432, ctx.r8.u32);
	// stw r11,452(r31)
	PPC_STORE_U32(ctx.r31.u32 + 452, ctx.r11.u32);
	// stw r11,456(r31)
	PPC_STORE_U32(ctx.r31.u32 + 456, ctx.r11.u32);
	// stw r11,460(r31)
	PPC_STORE_U32(ctx.r31.u32 + 460, ctx.r11.u32);
	// stw r10,464(r31)
	PPC_STORE_U32(ctx.r31.u32 + 464, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,436(r31)
	PPC_STORE_U32(ctx.r31.u32 + 436, ctx.r11.u32);
	// lwz r10,428(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 428);
	// lwz r11,432(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 432);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// stw r11,428(r31)
	PPC_STORE_U32(ctx.r31.u32 + 428, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_8210FB10"))) PPC_WEAK_FUNC(sub_8210FB10);
PPC_FUNC_IMPL(__imp__sub_8210FB10) {
	PPC_FUNC_PROLOGUE();
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8210FB18"))) PPC_WEAK_FUNC(sub_8210FB18);
PPC_FUNC_IMPL(__imp__sub_8210FB18) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x8210fb98
	sub_8210FB98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210FB20"))) PPC_WEAK_FUNC(sub_8210FB20);
PPC_FUNC_IMPL(__imp__sub_8210FB20) {
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
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r11,r11,25152
	ctx.r11.s64 = ctx.r11.s64 + 25152;
	// addi r10,r10,25112
	ctx.r10.s64 = ctx.r10.s64 + 25112;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r10.u32);
	// addi r3,r3,428
	ctx.r3.s64 = ctx.r3.s64 + 428;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// bl 0x8210ef58
	ctx.lr = 0x8210FB5C;
	sub_8210EF58(ctx, base);
	// addi r3,r31,388
	ctx.r3.s64 = ctx.r31.s64 + 388;
	// bl 0x8210ef58
	ctx.lr = 0x8210FB64;
	sub_8210EF58(ctx, base);
	// addi r3,r31,352
	ctx.r3.s64 = ctx.r31.s64 + 352;
	// bl 0x82108b60
	ctx.lr = 0x8210FB6C;
	sub_82108B60(ctx, base);
	// addi r3,r31,284
	ctx.r3.s64 = ctx.r31.s64 + 284;
	// bl 0x8210ef58
	ctx.lr = 0x8210FB74;
	sub_8210EF58(ctx, base);
	// addi r3,r31,244
	ctx.r3.s64 = ctx.r31.s64 + 244;
	// bl 0x8210ef58
	ctx.lr = 0x8210FB7C;
	sub_8210EF58(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8210e7b8
	ctx.lr = 0x8210FB84;
	sub_8210E7B8(ctx, base);
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

__attribute__((alias("__imp__sub_8210FB98"))) PPC_WEAK_FUNC(sub_8210FB98);
PPC_FUNC_IMPL(__imp__sub_8210FB98) {
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
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x8210fb20
	ctx.lr = 0x8210FBB8;
	sub_8210FB20(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8210fbc8
	if (ctx.cr0.eq) goto loc_8210FBC8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82114628
	ctx.lr = 0x8210FBC8;
	sub_82114628(ctx, base);
loc_8210FBC8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
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

__attribute__((alias("__imp__sub_8210FBE4"))) PPC_WEAK_FUNC(sub_8210FBE4);
PPC_FUNC_IMPL(__imp__sub_8210FBE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8210FBE8"))) PPC_WEAK_FUNC(sub_8210FBE8);
PPC_FUNC_IMPL(__imp__sub_8210FBE8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x8210FBF0;
	__savegprlr_24(ctx, base);
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, ctx.f31.u64);
	// stwu r1,-464(r1)
	ea = -464 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// addi r26,r11,-5536
	ctx.r26.s64 = ctx.r11.s64 + -5536;
	// lhz r11,16(r6)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r6.u32 + 16);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r11,18
	ctx.r4.s64 = ctx.r11.s64 + 18;
	// ori r5,r5,2
	ctx.r5.u64 = ctx.r5.u64 | 2;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// mr r24,r8
	ctx.r24.u64 = ctx.r8.u64;
	// bl 0x82108aa8
	ctx.lr = 0x8210FC34;
	sub_82108AA8(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x8210fe8c
	if (ctx.cr0.eq) goto loc_8210FE8C;
	// lhz r11,16(r29)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r29.u32 + 16);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r5,r11,18
	ctx.r5.s64 = ctx.r11.s64 + 18;
	// bl 0x8207dac0
	ctx.lr = 0x8210FC50;
	sub_8207DAC0(ctx, base);
	// lhz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 0);
	// li r25,16
	ctx.r25.s64 = 16;
	// cmplwi cr6,r11,65534
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 65534, ctx.xer);
	// bne cr6,0x8210fcac
	if (!ctx.cr6.eq) goto loc_8210FCAC;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r11,24800
	ctx.r9.s64 = ctx.r11.s64 + 24800;
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r3,r31,24
	ctx.r3.s64 = ctx.r31.s64 + 24;
	// lwz r11,24800(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24800);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r5,16
	ctx.r5.s64 = 16;
	// lwz r7,4(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r6,8(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r9,12(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// stw r7,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r7.u32);
	// stw r6,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r6.u32);
	// stw r9,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r9.u32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// bl 0x8207dac0
	ctx.lr = 0x8210FCA4;
	sub_8207DAC0(ctx, base);
	// sth r25,18(r31)
	PPC_STORE_U16(ctx.r31.u32 + 18, ctx.r25.u16);
	// b 0x8210fcb4
	goto loc_8210FCB4;
loc_8210FCAC:
	// li r11,1
	ctx.r11.s64 = 1;
	// sth r11,0(r31)
	PPC_STORE_U16(ctx.r31.u32 + 0, ctx.r11.u16);
loc_8210FCB4:
	// lhz r11,2(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 2);
	// mr r8,r24
	ctx.r8.u64 = ctx.r24.u64;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// rlwinm r11,r11,1,16,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFE;
	// sth r25,14(r31)
	PPC_STORE_U16(ctx.r31.u32 + 14, ctx.r25.u16);
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// sth r11,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r11.u16);
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8210e128
	ctx.lr = 0x8210FCEC;
	sub_8210E128(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82114628
	ctx.lr = 0x8210FCF8;
	sub_82114628(ctx, base);
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// blt cr6,0x8210fef8
	if (ctx.cr6.lt) goto loc_8210FEF8;
	// addi r11,r1,100
	ctx.r11.s64 = ctx.r1.s64 + 100;
	// lwz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// li r31,0
	ctx.r31.s64 = 0;
	// lhz r9,2(r29)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r29.u32 + 2);
	// li r8,2
	ctx.r8.s64 = 2;
	// li r5,22
	ctx.r5.s64 = 22;
	// sth r31,128(r1)
	PPC_STORE_U16(ctx.r1.u32 + 128, ctx.r31.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r31,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r31.u32);
	// addi r3,r1,130
	ctx.r3.s64 = ctx.r1.s64 + 130;
	// stw r31,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r31.u32);
	// stw r31,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r31.u32);
	// stw r31,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r31.u32);
	// stw r31,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r31.u32);
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// stw r9,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// stw r31,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r31.u32);
	// stw r25,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r25.u32);
	// stw r8,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// stw r31,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r31.u32);
	// bl 0x8207da20
	ctx.lr = 0x8210FD54;
	sub_8207DA20(ctx, base);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821247c0
	ctx.lr = 0x8210FD60;
	sub_821247C0(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x821120d0
	ctx.lr = 0x8210FD68;
	sub_821120D0(ctx, base);
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// sth r3,128(r1)
	PPC_STORE_U16(ctx.r1.u32 + 128, ctx.r3.u16);
	// li r5,112
	ctx.r5.s64 = 112;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r31,256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 256, ctx.r31.u32);
	// addi r3,r1,260
	ctx.r3.s64 = ctx.r1.s64 + 260;
	// stw r11,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r11.u32);
	// bl 0x8207da20
	ctx.lr = 0x8210FD88;
	sub_8207DA20(ctx, base);
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// bl 0x821246f0
	ctx.lr = 0x8210FD90;
	sub_821246F0(ctx, base);
	// li r5,90
	ctx.r5.s64 = 90;
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r31,160(r1)
	PPC_STORE_U16(ctx.r1.u32 + 160, ctx.r31.u16);
	// addi r3,r1,162
	ctx.r3.s64 = ctx.r1.s64 + 162;
	// bl 0x8207da20
	ctx.lr = 0x8210FDA4;
	sub_8207DA20(ctx, base);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// addi r4,r1,256
	ctx.r4.s64 = ctx.r1.s64 + 256;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82124678
	ctx.lr = 0x8210FDB4;
	sub_82124678(ctx, base);
	// std r31,184(r30)
	PPC_STORE_U64(ctx.r30.u32 + 184, ctx.r31.u64);
	// std r31,192(r30)
	PPC_STORE_U64(ctx.r30.u32 + 192, ctx.r31.u64);
	// addi r11,r30,4
	ctx.r11.s64 = ctx.r30.s64 + 4;
	// stw r31,200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 200, ctx.r31.u32);
	// not r9,r27
	ctx.r9.u64 = ~ctx.r27.u64;
	// stw r30,184(r30)
	PPC_STORE_U32(ctx.r30.u32 + 184, ctx.r30.u32);
	// li r10,375
	ctx.r10.s64 = 375;
	// rlwinm r5,r9,31,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x1;
	// addi r28,r30,184
	ctx.r28.s64 = ctx.r30.s64 + 184;
	// lhz r11,172(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 172);
	// lwz r27,64(r30)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r30.u32 + 64);
	// stw r11,196(r30)
	PPC_STORE_U32(ctx.r30.u32 + 196, ctx.r11.u32);
	// lwz r9,72(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 72);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// rotlwi r9,r9,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// lwz r11,4(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// rlwinm r11,r9,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// divwu r3,r11,r10
	ctx.r3.u32 = ppc_divwu(ctx.r11.u32, ctx.r10.u32);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fdivs f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 / ctx.f0.f64));
	// fmuls f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// bl 0x8210e880
	ctx.lr = 0x8210FE24;
	sub_8210E880(ctx, base);
	// mullw r11,r3,r27
	ctx.r11.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r27.s32);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// li r10,2048
	ctx.r10.s64 = 2048;
	// addi r9,r11,2048
	ctx.r9.s64 = ctx.r11.s64 + 2048;
	// stw r11,220(r30)
	PPC_STORE_U32(ctx.r30.u32 + 220, ctx.r11.u32);
	// twllei r11,0
	// divwu r11,r10,r11
	ctx.r11.u32 = ppc_divwu(ctx.r10.u32, ctx.r11.u32);
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// li r6,0
	ctx.r6.s64 = 0;
	// mullw r4,r9,r11
	ctx.r4.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// stw r11,336(r30)
	PPC_STORE_U32(ctx.r30.u32 + 336, ctx.r11.u32);
	// stw r4,224(r30)
	PPC_STORE_U32(ctx.r30.u32 + 224, ctx.r4.u32);
	// ori r5,r5,2
	ctx.r5.u64 = ctx.r5.u64 | 2;
	// bl 0x82108aa8
	ctx.lr = 0x8210FE68;
	sub_82108AA8(ctx, base);
	// stw r3,216(r30)
	PPC_STORE_U32(ctx.r30.u32 + 216, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8210fe8c
	if (ctx.cr0.eq) goto loc_8210FE8C;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8211bed0
	ctx.lr = 0x8210FE80;
	sub_8211BED0(ctx, base);
	// stw r3,204(r30)
	PPC_STORE_U32(ctx.r30.u32 + 204, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8210fe98
	if (!ctx.cr0.eq) goto loc_8210FE98;
loc_8210FE8C:
	// lis r28,-32761
	ctx.r28.s64 = -2147024896;
	// ori r28,r28,14
	ctx.r28.u64 = ctx.r28.u64 | 14;
	// b 0x8210fef8
	goto loc_8210FEF8;
loc_8210FE98:
	// addi r11,r1,84
	ctx.r11.s64 = ctx.r1.s64 + 84;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// lis r10,-32239
	ctx.r10.s64 = -2112815104;
	// addi r7,r30,208
	ctx.r7.s64 = ctx.r30.s64 + 208;
	// addi r10,r10,-1824
	ctx.r10.s64 = ctx.r10.s64 + -1824;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stw r31,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r31.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r31,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r31.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stw r31,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r31.u32);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// stw r28,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r28.u32);
	// bl 0x82122b58
	ctx.lr = 0x8210FED4;
	sub_82122B58(ctx, base);
	// mr. r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// stw r31,208(r30)
	PPC_STORE_U32(ctx.r30.u32 + 208, ctx.r31.u32);
	// blt 0x8210fef8
	if (ctx.cr0.lt) goto loc_8210FEF8;
	// lwz r11,352(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 352);
	// addi r3,r30,352
	ctx.r3.s64 = ctx.r30.s64 + 352;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8210FEF4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
loc_8210FEF8:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210FF08"))) PPC_WEAK_FUNC(sub_8210FF08);
PPC_FUNC_IMPL(__imp__sub_8210FF08) {
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
	// lwz r11,184(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r31,0
	ctx.r31.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x8210ff54
	if (!ctx.cr6.gt) goto loc_8210FF54;
loc_8210FF30:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r3,284(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 284);
	// bl 0x8210c318
	ctx.lr = 0x8210FF3C;
	sub_8210C318(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8210ff70
	if (ctx.cr0.eq) goto loc_8210FF70;
	// lwz r11,184(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 184);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8210ff30
	if (ctx.cr6.lt) goto loc_8210FF30;
loc_8210FF54:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8210FF58:
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
loc_8210FF70:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8210ff58
	goto loc_8210FF58;
}

__attribute__((alias("__imp__sub_8210FF78"))) PPC_WEAK_FUNC(sub_8210FF78);
PPC_FUNC_IMPL(__imp__sub_8210FF78) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8210FF80;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r29,0
	ctx.r29.s64 = 0;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r29,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r29.u32);
	// addi r31,r3,52
	ctx.r31.s64 = ctx.r3.s64 + 52;
	// stw r29,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r29.u32);
	// stw r29,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r29.u32);
	// lwz r11,44(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x8210ffc8
	if (!ctx.cr6.gt) goto loc_8210FFC8;
loc_8210FFA8:
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// lwz r3,144(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 144);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x8210c818
	ctx.lr = 0x8210FFB8;
	sub_8210C818(ctx, base);
	// lwz r11,44(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8210ffa8
	if (ctx.cr6.lt) goto loc_8210FFA8;
loc_8210FFC8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210FFD0"))) PPC_WEAK_FUNC(sub_8210FFD0);
PPC_FUNC_IMPL(__imp__sub_8210FFD0) {
	PPC_FUNC_PROLOGUE();
	// rlwinm. r11,r5,0,3,3
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x10000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8210ffdc
	if (ctx.cr0.eq) goto loc_8210FFDC;
	// b 0x8210de68
	sub_8210DE68(ctx, base);
	return;
loc_8210FFDC:
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x8210ffec
	if (!ctx.cr6.eq) goto loc_8210FFEC;
	// rlwinm. r11,r5,0,24,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beqlr 
	if (ctx.cr0.eq) return;
loc_8210FFEC:
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x8210de68
	sub_8210DE68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210FFF4"))) PPC_WEAK_FUNC(sub_8210FFF4);
PPC_FUNC_IMPL(__imp__sub_8210FFF4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8210FFF8"))) PPC_WEAK_FUNC(sub_8210FFF8);
PPC_FUNC_IMPL(__imp__sub_8210FFF8) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r11,r5,11,0,20
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 11) & 0xFFFFF800;
	// add r7,r3,r4
	ctx.r7.u64 = ctx.r3.u64 + ctx.r4.u64;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x82110034
	goto loc_82110034;
loc_8211000C:
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// rlwinm r9,r8,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0x3FFFFFFF;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmplw cr6,r9,r6
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r6.u32, ctx.xer);
	// bgt cr6,0x82110048
	if (ctx.cr6.gt) goto loc_82110048;
	// lbz r8,3(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 3);
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// addi r9,r8,1
	ctx.r9.s64 = ctx.r8.s64 + 1;
	// rlwinm r9,r9,11,0,20
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 11) & 0xFFFFF800;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
loc_82110034:
	// addi r9,r11,2048
	ctx.r9.s64 = ctx.r11.s64 + 2048;
	// cmplw cr6,r9,r7
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, ctx.xer);
	// ble cr6,0x8211000c
	if (!ctx.cr6.gt) goto loc_8211000C;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82110048:
	// lbz r9,1(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// rlwinm r8,r8,8,22,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0x300;
	// lbz r7,2(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 2);
	// subf. r10,r10,r6
	ctx.r10.s64 = ctx.r6.s64 - ctx.r10.s64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// or r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 | ctx.r9.u64;
	// rlwinm r8,r7,29,3,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 29) & 0x1FFFFFFF;
	// rlwinm r7,r9,5,0,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// or r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 | ctx.r8.u64;
	// addi r7,r11,2
	ctx.r7.s64 = ctx.r11.s64 + 2;
	// addi r6,r8,32
	ctx.r6.s64 = ctx.r8.s64 + 32;
	// beq 0x821100c8
	if (ctx.cr0.eq) goto loc_821100C8;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8211007C:
	// rlwinm r10,r6,29,3,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 29) & 0x1FFFFFFF;
	// clrlwi r8,r6,29
	ctx.r8.u64 = ctx.r6.u32 & 0x7;
	// cmplwi cr6,r8,2
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 2, ctx.xer);
	// lbzx r5,r10,r11
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r11.u32);
	// rotlwi r5,r5,8
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r5.u32, 8);
	// bge cr6,0x821100a0
	if (!ctx.cr6.lt) goto loc_821100A0;
	// lbzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// subfic r8,r8,1
	ctx.xer.ca = ctx.r8.u32 <= 1;
	ctx.r8.s64 = 1 - ctx.r8.s64;
	// b 0x821100b4
	goto loc_821100B4;
loc_821100A0:
	// lbzx r4,r9,r10
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// subfic r8,r8,9
	ctx.xer.ca = ctx.r8.u32 <= 9;
	ctx.r8.s64 = 9 - ctx.r8.s64;
	// lbzx r10,r7,r10
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r10.u32);
	// or r5,r5,r4
	ctx.r5.u64 = ctx.r5.u64 | ctx.r4.u64;
	// rlwinm r5,r5,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00;
loc_821100B4:
	// or r10,r5,r10
	ctx.r10.u64 = ctx.r5.u64 | ctx.r10.u64;
	// srw r10,r10,r8
	ctx.r10.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r8.u8 & 0x3F));
	// clrlwi r10,r10,17
	ctx.r10.u64 = ctx.r10.u32 & 0x7FFF;
	// add r6,r10,r6
	ctx.r6.u64 = ctx.r10.u64 + ctx.r6.u64;
	// bdnz 0x8211007c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8211007C;
loc_821100C8:
	// subf r11,r3,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r3.s64;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r3,r11,r6
	ctx.r3.u64 = ctx.r11.u64 + ctx.r6.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821100D8"))) PPC_WEAK_FUNC(sub_821100D8);
PPC_FUNC_IMPL(__imp__sub_821100D8) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r11,r5,11,0,20
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 11) & 0xFFFFF800;
	// add r8,r3,r4
	ctx.r8.u64 = ctx.r3.u64 + ctx.r4.u64;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lbz r10,3(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 3);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r9,r10,11,0,20
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 11) & 0xFFFFF800;
	// add r10,r9,r11
	ctx.r10.u64 = ctx.r9.u64 + ctx.r11.u64;
	// b 0x8211010c
	goto loc_8211010C;
loc_821100F8:
	// lbz r9,3(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 3);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// rlwinm r9,r9,11,0,20
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 11) & 0xFFFFF800;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
loc_8211010C:
	// addi r7,r10,2048
	ctx.r7.s64 = ctx.r10.s64 + 2048;
	// cmplw cr6,r7,r8
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r8.u32, ctx.xer);
	// ble cr6,0x821100f8
	if (!ctx.cr6.gt) goto loc_821100F8;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// rlwinm. r10,r10,0,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFC;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x82110128
	if (!ctx.cr0.eq) goto loc_82110128;
	// subf r11,r9,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r9.s64;
loc_82110128:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// lbz r9,1(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// addi r6,r11,2
	ctx.r6.s64 = ctx.r11.s64 + 2;
	// rlwinm r7,r10,8,22,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0x300;
	// lbz r5,2(r11)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r11.u32 + 2);
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// or r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 | ctx.r9.u64;
	// rlwinm r7,r5,29,3,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 29) & 0x1FFFFFFF;
	// rlwinm r9,r9,5,0,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// or r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 | ctx.r7.u64;
	// addi r7,r9,32
	ctx.r7.s64 = ctx.r9.s64 + 32;
	// beq 0x821101b0
	if (ctx.cr0.eq) goto loc_821101B0;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82110164:
	// rlwinm r10,r7,29,3,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 29) & 0x1FFFFFFF;
	// clrlwi r9,r7,29
	ctx.r9.u64 = ctx.r7.u32 & 0x7;
	// cmplwi cr6,r9,2
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 2, ctx.xer);
	// lbzx r5,r10,r11
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r11.u32);
	// rotlwi r5,r5,8
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r5.u32, 8);
	// bge cr6,0x82110188
	if (!ctx.cr6.lt) goto loc_82110188;
	// lbzx r10,r8,r10
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r10.u32);
	// subfic r9,r9,1
	ctx.xer.ca = ctx.r9.u32 <= 1;
	ctx.r9.s64 = 1 - ctx.r9.s64;
	// b 0x8211019c
	goto loc_8211019C;
loc_82110188:
	// lbzx r4,r8,r10
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r10.u32);
	// subfic r9,r9,9
	ctx.xer.ca = ctx.r9.u32 <= 9;
	ctx.r9.s64 = 9 - ctx.r9.s64;
	// lbzx r10,r6,r10
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r10.u32);
	// or r5,r5,r4
	ctx.r5.u64 = ctx.r5.u64 | ctx.r4.u64;
	// rlwinm r5,r5,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00;
loc_8211019C:
	// or r10,r5,r10
	ctx.r10.u64 = ctx.r5.u64 | ctx.r10.u64;
	// srw r10,r10,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r9.u8 & 0x3F));
	// clrlwi r10,r10,17
	ctx.r10.u64 = ctx.r10.u32 & 0x7FFF;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// bdnz 0x82110164
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82110164;
loc_821101B0:
	// subf r11,r3,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r3.s64;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r3,r11,r7
	ctx.r3.u64 = ctx.r11.u64 + ctx.r7.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821101C0"))) PPC_WEAK_FUNC(sub_821101C0);
PPC_FUNC_IMPL(__imp__sub_821101C0) {
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
	// lwz r11,52(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821101F0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 248);
	// addi r30,r31,248
	ctx.r30.s64 = ctx.r31.s64 + 248;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82110208;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,336(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 336);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82110238
	if (ctx.cr6.eq) goto loc_82110238;
	// lwz r11,332(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 332);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82110228
	if (ctx.cr6.eq) goto loc_82110228;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x8211022c
	goto loc_8211022C;
loc_82110228:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8211022C:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// ori r10,r10,64
	ctx.r10.u64 = ctx.r10.u64 | 64;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_82110238:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8211024C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82110264;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
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

__attribute__((alias("__imp__sub_82110280"))) PPC_WEAK_FUNC(sub_82110280);
PPC_FUNC_IMPL(__imp__sub_82110280) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82110288;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,184(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r31,0
	ctx.r31.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x821102cc
	if (!ctx.cr6.gt) goto loc_821102CC;
loc_821102A4:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r3,284(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 284);
	// bl 0x8210c8d8
	ctx.lr = 0x821102B0;
	sub_8210C8D8(ctx, base);
	// cmplw cr6,r29,r3
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r3.u32, ctx.xer);
	// bgt cr6,0x821102bc
	if (ctx.cr6.gt) goto loc_821102BC;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
loc_821102BC:
	// lwz r11,184(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 184);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x821102a4
	if (ctx.cr6.lt) goto loc_821102A4;
loc_821102CC:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821102D8"))) PPC_WEAK_FUNC(sub_821102D8);
PPC_FUNC_IMPL(__imp__sub_821102D8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821102E0;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,284(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 284);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x8210c3e0
	ctx.lr = 0x82110304;
	sub_8210C3E0(ctx, base);
	// lwz r11,184(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82110378
	if (!ctx.cr6.eq) goto loc_82110378;
	// lwz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// clrlwi. r11,r4,31
	ctx.r11.u64 = ctx.r4.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82110378
	if (ctx.cr0.eq) goto loc_82110378;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821103d8
	if (ctx.cr6.eq) goto loc_821103D8;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r5,r30,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,296(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 296);
	// mtctr r3
	ctx.ctr.u64 = ctx.r3.u64;
	// lwz r6,292(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 292);
	// addi r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -2;
loc_82110344:
	// add r7,r9,r29
	ctx.r7.u64 = ctx.r9.u64 + ctx.r29.u64;
	// lhzu r8,2(r11)
	ea = 2 + ctx.r11.u32;
	ctx.r8.u64 = PPC_LOAD_U16(ea);
	ctx.r11.u32 = ea;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// divwu r31,r7,r10
	ctx.r31.u32 = ppc_divwu(ctx.r7.u32, ctx.r10.u32);
	// twllei r10,0
	// mullw r31,r31,r10
	ctx.r31.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r10.s32);
	// subf r7,r31,r7
	ctx.r7.s64 = ctx.r7.s64 - ctx.r31.s64;
	// mullw r7,r4,r7
	ctx.r7.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r7.s32);
	// rlwinm r7,r7,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 + ctx.r6.u64;
	// sthx r8,r5,r7
	PPC_STORE_U16(ctx.r5.u32 + ctx.r7.u32, ctx.r8.u16);
	// bdnz 0x82110344
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82110344;
	// b 0x821103d8
	goto loc_821103D8;
loc_82110378:
	// li r8,0
	ctx.r8.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821103d8
	if (ctx.cr6.eq) goto loc_821103D8;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r5,r30,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,296(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 296);
	// mtctr r3
	ctx.ctr.u64 = ctx.r3.u64;
	// lwz r6,64(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// addi r10,r11,-2
	ctx.r10.s64 = ctx.r11.s64 + -2;
	// lwz r4,292(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 292);
loc_821103A0:
	// add r11,r8,r29
	ctx.r11.u64 = ctx.r8.u64 + ctx.r29.u64;
	// lhz r31,2(r10)
	ctx.r31.u64 = PPC_LOAD_U16(ctx.r10.u32 + 2);
	// lhzu r7,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r7.u64 = PPC_LOAD_U16(ea);
	ctx.r10.u32 = ea;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// divwu r30,r11,r9
	ctx.r30.u32 = ppc_divwu(ctx.r11.u32, ctx.r9.u32);
	// twllei r9,0
	// mullw r30,r30,r9
	ctx.r30.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r9.s32);
	// subf r11,r30,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r30.s64;
	// mullw r11,r11,r6
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r6.s32);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// sthux r31,r11,r5
	ea = ctx.r11.u32 + ctx.r5.u32;
	PPC_STORE_U16(ea, ctx.r31.u16);
	ctx.r11.u32 = ea;
	// sth r7,2(r11)
	PPC_STORE_U16(ctx.r11.u32 + 2, ctx.r7.u16);
	// bdnz 0x821103a0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821103A0;
loc_821103D8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821103E0"))) PPC_WEAK_FUNC(sub_821103E0);
PPC_FUNC_IMPL(__imp__sub_821103E0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x821103E8;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r28,0
	ctx.r28.s64 = 0;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,284(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 284);
	// bl 0x8210c3e0
	ctx.lr = 0x82110410;
	sub_8210C3E0(ctx, base);
	// lwz r11,296(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 296);
	// add r10,r3,r29
	ctx.r10.u64 = ctx.r3.u64 + ctx.r29.u64;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82110430
	if (!ctx.cr6.gt) goto loc_82110430;
	// subf r30,r29,r11
	ctx.r30.s64 = ctx.r11.s64 - ctx.r29.s64;
	// subf r28,r30,r3
	ctx.r28.s64 = ctx.r3.s64 - ctx.r30.s64;
loc_82110430:
	// lwz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// lwz r11,292(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 292);
	// mullw r10,r9,r29
	ctx.r10.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r29.s32);
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// mullw r9,r9,r30
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r30.s32);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r5,r9,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// bl 0x82088630
	ctx.lr = 0x82110454;
	sub_82088630(ctx, base);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x82110480
	if (ctx.cr6.eq) goto loc_82110480;
	// lwz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mullw r11,r9,r30
	ctx.r11.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r30.s32);
	// lwz r3,292(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 292);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mullw r9,r9,r28
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r28.s32);
	// rlwinm r5,r9,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x82088630
	ctx.lr = 0x82110480;
	sub_82088630(ctx, base);
loc_82110480:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8211048C"))) PPC_WEAK_FUNC(sub_8211048C);
PPC_FUNC_IMPL(__imp__sub_8211048C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82110490"))) PPC_WEAK_FUNC(sub_82110490);
PPC_FUNC_IMPL(__imp__sub_82110490) {
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
	// lwz r11,248(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 248);
	// addi r30,r3,248
	ctx.r30.s64 = ctx.r3.s64 + 248;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821104C0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,336(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 336);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821104d4
	if (!ctx.cr6.eq) goto loc_821104D4;
	// li r31,0
	ctx.r31.s64 = 0;
	// b 0x821104f0
	goto loc_821104F0;
loc_821104D4:
	// lwz r11,328(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 328);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821104e8
	if (ctx.cr6.eq) goto loc_821104E8;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x821104ec
	goto loc_821104EC;
loc_821104E8:
	// li r11,0
	ctx.r11.s64 = 0;
loc_821104EC:
	// lwz r31,32(r11)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
loc_821104F0:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82110504;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
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

__attribute__((alias("__imp__sub_82110520"))) PPC_WEAK_FUNC(sub_82110520);
PPC_FUNC_IMPL(__imp__sub_82110520) {
	PPC_FUNC_PROLOGUE();
	// li r10,8
	ctx.r10.s64 = 8;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r9,r3,8
	ctx.r9.s64 = ctx.r3.s64 + 8;
	// stw r10,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r10.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r11,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, ctx.r11.u32);
	// stw r11,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r11.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// stw r11,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r11.u32);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
loc_8211054C:
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r11,r11,12
	ctx.r11.s64 = ctx.r11.s64 + 12;
	// addi r9,r10,4
	ctx.r9.s64 = ctx.r10.s64 + 4;
	// stw r8,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r8.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// bdnz 0x8211054c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8211054C;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82110570"))) PPC_WEAK_FUNC(sub_82110570);
PPC_FUNC_IMPL(__imp__sub_82110570) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,108(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 108);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r3,0(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r4,r10
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82110590
	if (!ctx.cr6.eq) goto loc_82110590;
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r10,108(r11)
	PPC_STORE_U32(ctx.r11.u32 + 108, ctx.r10.u32);
	// b 0x8211059c
	goto loc_8211059C;
loc_82110590:
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r9,4(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
loc_8211059C:
	// lwz r10,112(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 112);
	// cmplw cr6,r4,r10
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x821105b4
	if (!ctx.cr6.eq) goto loc_821105B4;
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r10,112(r11)
	PPC_STORE_U32(ctx.r11.u32 + 112, ctx.r10.u32);
	// b 0x821105c0
	goto loc_821105C0;
loc_821105B4:
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r9,8(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
loc_821105C0:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r10.u32);
	// lwz r10,116(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r4,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r4.u32);
	// stw r10,116(r11)
	PPC_STORE_U32(ctx.r11.u32 + 116, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821105DC"))) PPC_WEAK_FUNC(sub_821105DC);
PPC_FUNC_IMPL(__imp__sub_821105DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821105E0"))) PPC_WEAK_FUNC(sub_821105E0);
PPC_FUNC_IMPL(__imp__sub_821105E0) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,208(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82110634
	if (ctx.cr6.eq) goto loc_82110634;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stw r9,208(r11)
	PPC_STORE_U32(ctx.r11.u32 + 208, ctx.r9.u32);
	// beq cr6,0x82110610
	if (ctx.cr6.eq) goto loc_82110610;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r8,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// b 0x82110618
	goto loc_82110618;
loc_82110610:
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,204(r11)
	PPC_STORE_U32(ctx.r11.u32 + 204, ctx.r9.u32);
loc_82110618:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r9,212(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 212);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// addi r10,r9,-1
	ctx.r10.s64 = ctx.r9.s64 + -1;
	// stw r10,212(r11)
	PPC_STORE_U32(ctx.r11.u32 + 212, ctx.r10.u32);
	// blr 
	return;
loc_82110634:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8211063C"))) PPC_WEAK_FUNC(sub_8211063C);
PPC_FUNC_IMPL(__imp__sub_8211063C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82110640"))) PPC_WEAK_FUNC(sub_82110640);
PPC_FUNC_IMPL(__imp__sub_82110640) {
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
	// lwz r11,116(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,120(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x8211067c
	if (!ctx.cr6.lt) goto loc_8211067C;
	// bl 0x821d5474
	ctx.lr = 0x82110670;
	__imp__KeGetCurrentProcessType(ctx, base);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x8211067c
	if (ctx.cr6.eq) goto loc_8211067C;
	// li r30,1
	ctx.r30.s64 = 1;
loc_8211067C:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82110690
	if (ctx.cr6.eq) goto loc_82110690;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x82110710
	if (ctx.cr6.eq) goto loc_82110710;
loc_82110690:
	// lwz r11,120(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// li r10,-1
	ctx.r10.s64 = -1;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x82110700
	if (ctx.cr6.gt) goto loc_82110700;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,-5536
	ctx.r3.s64 = ctx.r11.s64 + -5536;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// li r4,100
	ctx.r4.s64 = 100;
	// bl 0x82108aa8
	ctx.lr = 0x821106BC;
	sub_82108AA8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82110710
	if (ctx.cr0.eq) goto loc_82110710;
	// li r10,8
	ctx.r10.s64 = 8;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_821106D0:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// addi r11,r11,12
	ctx.r11.s64 = ctx.r11.s64 + 12;
	// bdnz 0x821106d0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821106D0;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// lwz r11,120(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// stw r3,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// stw r11,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r11.u32);
	// b 0x82110710
	goto loc_82110710;
loc_82110700:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r11,16296
	ctx.r3.s64 = ctx.r11.s64 + 16296;
	// bl 0x8208d988
	ctx.lr = 0x8211070C;
	sub_8208D988(ctx, base);
	// twi 31,r0,22
loc_82110710:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82110728
	if (ctx.cr6.eq) goto loc_82110728;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// b 0x8211072c
	goto loc_8211072C;
loc_82110728:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8211072C:
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

__attribute__((alias("__imp__sub_82110744"))) PPC_WEAK_FUNC(sub_82110744);
PPC_FUNC_IMPL(__imp__sub_82110744) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82110748"))) PPC_WEAK_FUNC(sub_82110748);
PPC_FUNC_IMPL(__imp__sub_82110748) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82110750;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// clrldi r10,r4,32
	ctx.r10.u64 = ctx.r4.u64 & 0xFFFFFFFF;
	// li r8,375
	ctx.r8.s64 = 375;
	// lfs f12,156(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 156);
	ctx.f12.f64 = double(temp.f32);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lwz r11,60(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// not r11,r11
	ctx.r11.u64 = ~ctx.r11.u64;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// rlwinm r10,r9,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// rlwinm r5,r11,31,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x1;
	// divwu r3,r10,r8
	ctx.r3.u32 = ppc_divwu(ctx.r10.u32, ctx.r8.u32);
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r11,r31,4
	ctx.r11.s64 = ctx.r31.s64 + 4;
	// fdivs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
	// fmuls f1,f0,f12
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
	// bl 0x8210e880
	ctx.lr = 0x821107B4;
	sub_8210E880(ctx, base);
	// lwz r11,292(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 292);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821107d0
	if (ctx.cr6.eq) goto loc_821107D0;
	// lwz r11,296(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 296);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82110848
	if (!ctx.cr6.gt) goto loc_82110848;
loc_821107D0:
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// mullw r11,r11,r29
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r29.s32);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r10,-5536
	ctx.r3.s64 = ctx.r10.s64 + -5536;
	// ori r5,r5,2
	ctx.r5.u64 = ctx.r5.u64 | 2;
	// rlwinm r4,r11,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// bl 0x82108aa8
	ctx.lr = 0x821107F4;
	sub_82108AA8(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x82110808
	if (!ctx.cr0.eq) goto loc_82110808;
	// lis r28,-32761
	ctx.r28.s64 = -2147024896;
	// ori r28,r28,14
	ctx.r28.u64 = ctx.r28.u64 | 14;
	// b 0x82110848
	goto loc_82110848;
loc_82110808:
	// lwz r4,292(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 292);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82110840
	if (ctx.cr6.eq) goto loc_82110840;
	// lwz r11,296(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 296);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// mullw r11,r11,r10
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// rlwinm r5,r11,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// bl 0x82088630
	ctx.lr = 0x8211082C;
	sub_82088630(ctx, base);
	// lwz r3,292(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 292);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82110840
	if (ctx.cr6.eq) goto loc_82110840;
	// bl 0x82114628
	ctx.lr = 0x8211083C;
	sub_82114628(ctx, base);
	// stw r28,292(r31)
	PPC_STORE_U32(ctx.r31.u32 + 292, ctx.r28.u32);
loc_82110840:
	// stw r30,292(r31)
	PPC_STORE_U32(ctx.r31.u32 + 292, ctx.r30.u32);
	// stw r29,296(r31)
	PPC_STORE_U32(ctx.r31.u32 + 296, ctx.r29.u32);
loc_82110848:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82110854"))) PPC_WEAK_FUNC(sub_82110854);
PPC_FUNC_IMPL(__imp__sub_82110854) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82110858"))) PPC_WEAK_FUNC(sub_82110858);
PPC_FUNC_IMPL(__imp__sub_82110858) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x82110860;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,52(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82110880;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 248);
	// addi r28,r31,248
	ctx.r28.s64 = ctx.r31.s64 + 248;
	// li r25,0
	ctx.r25.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8211089C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,336(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 336);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82110940
	if (ctx.cr6.eq) goto loc_82110940;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r30,328(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 328);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x821108c8
	if (!ctx.cr6.eq) goto loc_821108C8;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8211095c
	if (ctx.cr6.eq) goto loc_8211095C;
	// lwz r30,4(r30)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// b 0x821108e4
	goto loc_821108E4;
loc_821108C8:
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821108E0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
loc_821108E4:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8211095c
	if (ctx.cr6.eq) goto loc_8211095C;
	// addi r27,r31,304
	ctx.r27.s64 = ctx.r31.s64 + 304;
	// addi r26,r31,140
	ctx.r26.s64 = ctx.r31.s64 + 140;
loc_821108F4:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82110910
	if (ctx.cr6.eq) goto loc_82110910;
	// lwz r30,4(r30)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r29,0(r11)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x82110914
	goto loc_82110914;
loc_82110910:
	// li r29,0
	ctx.r29.s64 = 0;
loc_82110914:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8210ea78
	ctx.lr = 0x8211091C;
	sub_8210EA78(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r4,32(r29)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r29.u32 + 32);
	// bl 0x8210de68
	ctx.lr = 0x8211092C;
	sub_8210DE68(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82114628
	ctx.lr = 0x82110934;
	sub_82114628(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x821108f4
	if (!ctx.cr6.eq) goto loc_821108F4;
	// b 0x8211095c
	goto loc_8211095C;
loc_82110940:
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82110958;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
loc_8211095C:
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82110970;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82110988;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82110994"))) PPC_WEAK_FUNC(sub_82110994);
PPC_FUNC_IMPL(__imp__sub_82110994) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82110998"))) PPC_WEAK_FUNC(sub_82110998);
PPC_FUNC_IMPL(__imp__sub_82110998) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,52(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821109CC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82110490
	ctx.lr = 0x821109D4;
	sub_82110490(ctx, base);
	// stw r3,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r3.u32);
	// lwz r11,148(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r11,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,52(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821109F8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// ld r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// tdllei r11,0
	// divdu r11,r10,r11
	ctx.r11.u64 = ppc_divdu(ctx.r10.u64, ctx.r11.u64);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// std r11,8(r30)
	PPC_STORE_U64(ctx.r30.u32 + 8, ctx.r11.u64);
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82110A2C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
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

__attribute__((alias("__imp__sub_82110A44"))) PPC_WEAK_FUNC(sub_82110A44);
PPC_FUNC_IMPL(__imp__sub_82110A44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82110A48"))) PPC_WEAK_FUNC(sub_82110A48);
PPC_FUNC_IMPL(__imp__sub_82110A48) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x82110A50;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,328(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 328);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82110a70
	if (ctx.cr6.eq) goto loc_82110A70;
	// lwz r31,0(r11)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x82110a74
	goto loc_82110A74;
loc_82110A70:
	// mr r31,r29
	ctx.r31.u64 = ctx.r29.u64;
loc_82110A74:
	// stw r29,192(r30)
	PPC_STORE_U32(ctx.r30.u32 + 192, ctx.r29.u32);
	// addi r28,r30,192
	ctx.r28.s64 = ctx.r30.s64 + 192;
	// stw r29,196(r30)
	PPC_STORE_U32(ctx.r30.u32 + 196, ctx.r29.u32);
	// mr r26,r29
	ctx.r26.u64 = ctx.r29.u64;
	// stw r29,200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 200, ctx.r29.u32);
	// mr r27,r29
	ctx.r27.u64 = ctx.r29.u64;
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82110b04
	if (ctx.cr6.eq) goto loc_82110B04;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// rlwinm. r10,r11,25,30,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x3;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// rlwinm r26,r11,23,9,31
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 23) & 0x7FFFFF;
	// stb r10,201(r30)
	PPC_STORE_U8(ctx.r30.u32 + 201, ctx.r10.u8);
	// bne 0x82110ac0
	if (!ctx.cr0.eq) goto loc_82110AC0;
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x82110ac0
	if (ctx.cr6.eq) goto loc_82110AC0;
	// li r11,4
	ctx.r11.s64 = 4;
	// addi r26,r26,-1
	ctx.r26.s64 = ctx.r26.s64 + -1;
	// stb r11,201(r30)
	PPC_STORE_U8(ctx.r30.u32 + 201, ctx.r11.u8);
loc_82110AC0:
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82110ae8
	if (ctx.cr6.eq) goto loc_82110AE8;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r11,r11,-128
	ctx.r11.s64 = ctx.r11.s64 + -128;
	// rlwinm r10,r11,25,30,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x3;
	// rlwinm r27,r11,23,9,31
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 23) & 0x7FFFFF;
	// stb r10,200(r30)
	PPC_STORE_U8(ctx.r30.u32 + 200, ctx.r10.u8);
	// b 0x82110af0
	goto loc_82110AF0;
loc_82110AE8:
	// li r11,3
	ctx.r11.s64 = 3;
	// stb r11,200(r30)
	PPC_STORE_U8(ctx.r30.u32 + 200, ctx.r11.u8);
loc_82110AF0:
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// cmplwi cr6,r11,255
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 255, ctx.xer);
	// bne cr6,0x82110b00
	if (!ctx.cr6.eq) goto loc_82110B00;
	// li r11,254
	ctx.r11.s64 = 254;
loc_82110B00:
	// stb r11,202(r30)
	PPC_STORE_U8(ctx.r30.u32 + 202, ctx.r11.u8);
loc_82110B04:
	// lwz r11,184(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 184);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x82110b80
	if (!ctx.cr6.gt) goto loc_82110B80;
loc_82110B10:
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82110b60
	if (ctx.cr6.eq) goto loc_82110B60;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x8210fff8
	ctx.lr = 0x82110B30;
	sub_8210FFF8(ctx, base);
	// stw r3,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r3.u32);
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// beq cr6,0x82110b58
	if (ctx.cr6.eq) goto loc_82110B58;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// bl 0x8210fff8
	ctx.lr = 0x82110B54;
	sub_8210FFF8(ctx, base);
	// b 0x82110b5c
	goto loc_82110B5C;
loc_82110B58:
	// bl 0x821100d8
	ctx.lr = 0x82110B5C;
	sub_821100D8(ctx, base);
loc_82110B5C:
	// stw r3,196(r30)
	PPC_STORE_U32(ctx.r30.u32 + 196, ctx.r3.u32);
loc_82110B60:
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// lwz r3,284(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 284);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x8210c818
	ctx.lr = 0x82110B70;
	sub_8210C818(ctx, base);
	// lwz r11,184(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 184);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82110b10
	if (ctx.cr6.lt) goto loc_82110B10;
loc_82110B80:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82110B88"))) PPC_WEAK_FUNC(sub_82110B88);
PPC_FUNC_IMPL(__imp__sub_82110B88) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x82110B90;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,328(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 328);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82110bac
	if (ctx.cr6.eq) goto loc_82110BAC;
	// lwz r29,0(r11)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x82110bb0
	goto loc_82110BB0;
loc_82110BAC:
	// li r29,0
	ctx.r29.s64 = 0;
loc_82110BB0:
	// lwz r11,16(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r10,12(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r8,184(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stb r9,202(r31)
	PPC_STORE_U8(ctx.r31.u32 + 202, ctx.r9.u8);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// addi r25,r11,-128
	ctx.r25.s64 = ctx.r11.s64 + -128;
	// ble cr6,0x82110c50
	if (!ctx.cr6.gt) goto loc_82110C50;
	// lwz r27,80(r1)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r24,r25,23,9,31
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 23) & 0x7FFFFF;
	// lwz r28,80(r1)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r26,r31,192
	ctx.r26.s64 = ctx.r31.s64 + 192;
loc_82110BE8:
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// lwz r4,4(r29)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r3,8(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// bl 0x8210fff8
	ctx.lr = 0x82110BFC;
	sub_8210FFF8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82110c0c
	if (ctx.cr0.eq) goto loc_82110C0C;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// rlwinm r27,r25,25,30,31
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 25) & 0x3;
loc_82110C0C:
	// stw r28,196(r31)
	PPC_STORE_U32(ctx.r31.u32 + 196, ctx.r28.u32);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// stb r27,200(r31)
	PPC_STORE_U8(ctx.r31.u32 + 200, ctx.r27.u8);
	// lwz r4,4(r29)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r3,8(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// bl 0x821100d8
	ctx.lr = 0x82110C24;
	sub_821100D8(ctx, base);
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r3,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r3.u32);
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// stb r11,201(r31)
	PPC_STORE_U8(ctx.r31.u32 + 201, ctx.r11.u8);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r3,284(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 284);
	// bl 0x8210c818
	ctx.lr = 0x82110C40;
	sub_8210C818(ctx, base);
	// lwz r11,184(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82110be8
	if (ctx.cr6.lt) goto loc_82110BE8;
loc_82110C50:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82110C58"))) PPC_WEAK_FUNC(sub_82110C58);
PPC_FUNC_IMPL(__imp__sub_82110C58) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82110C60;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,204(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 204);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82110d20
	if (!ctx.cr6.eq) goto loc_82110D20;
	// bl 0x82110280
	ctx.lr = 0x82110C78;
	sub_82110280(ctx, base);
	// lbz r11,202(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + 202);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// subf. r11,r3,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r3.s64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82110d20
	if (ctx.cr0.eq) goto loc_82110D20;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82110ce0
	if (ctx.cr6.eq) goto loc_82110CE0;
	// addi r29,r30,140
	ctx.r29.s64 = ctx.r30.s64 + 140;
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
loc_82110C98:
	// lwz r11,328(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 328);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82110cac
	if (ctx.cr6.eq) goto loc_82110CAC;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x82110cb0
	goto loc_82110CB0;
loc_82110CAC:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82110CB0:
	// lwz r11,328(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 328);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82110cc4
	if (ctx.cr6.eq) goto loc_82110CC4;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x82110cc8
	goto loc_82110CC8;
loc_82110CC4:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82110CC8:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r4,32(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// bl 0x8210d1b0
	ctx.lr = 0x82110CD8;
	sub_8210D1B0(ctx, base);
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x82110c98
	if (!ctx.cr0.eq) goto loc_82110C98;
loc_82110CE0:
	// lwz r11,328(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 328);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82110cf4
	if (ctx.cr6.eq) goto loc_82110CF4;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x82110cf8
	goto loc_82110CF8;
loc_82110CF4:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82110CF8:
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmplwi cr6,r11,255
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 255, ctx.xer);
	// bne cr6,0x82110d1c
	if (!ctx.cr6.eq) goto loc_82110D1C;
	// li r4,254
	ctx.r4.s64 = 254;
	// lwz r3,284(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 284);
	// bl 0x8210c910
	ctx.lr = 0x82110D10;
	sub_8210C910(ctx, base);
	// li r11,254
	ctx.r11.s64 = 254;
	// stb r11,202(r30)
	PPC_STORE_U8(ctx.r30.u32 + 202, ctx.r11.u8);
	// b 0x82110d20
	goto loc_82110D20;
loc_82110D1C:
	// stb r28,202(r30)
	PPC_STORE_U8(ctx.r30.u32 + 202, ctx.r28.u8);
loc_82110D20:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82110D28"))) PPC_WEAK_FUNC(sub_82110D28);
PPC_FUNC_IMPL(__imp__sub_82110D28) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82110D30;
	__savegprlr_28(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// li r5,36
	ctx.r5.s64 = 36;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x8207da20
	ctx.lr = 0x82110D50;
	sub_8207DA20(ctx, base);
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// lwz r10,292(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 292);
	// mullw r9,r11,r30
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// lwz r29,232(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 232);
	// mullw r11,r11,r28
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// b 0x82110df0
	goto loc_82110DF0;
loc_82110D80:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82110d9c
	if (ctx.cr6.eq) goto loc_82110D9C;
	// lwz r29,4(r29)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x82110da0
	goto loc_82110DA0;
loc_82110D9C:
	// li r30,0
	ctx.r30.s64 = 0;
loc_82110DA0:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x82110db8
	if (!ctx.cr6.lt) goto loc_82110DB8;
	// subf r11,r28,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r28.s64;
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// b 0x82110df0
	goto loc_82110DF0;
loc_82110DB8:
	// lis r11,4096
	ctx.r11.s64 = 268435456;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// rlwinm. r11,r11,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82110dd8
	if (ctx.cr0.eq) goto loc_82110DD8;
	// lis r11,4096
	ctx.r11.s64 = 268435456;
	// ori r11,r11,64
	ctx.r11.u64 = ctx.r11.u64 | 64;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
loc_82110DD8:
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// addi r3,r31,208
	ctx.r3.s64 = ctx.r31.s64 + 208;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bl 0x8210ea78
	ctx.lr = 0x82110DE8;
	sub_8210EA78(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82114628
	ctx.lr = 0x82110DF0;
	sub_82114628(ctx, base);
loc_82110DF0:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x82110d80
	if (!ctx.cr6.eq) goto loc_82110D80;
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// li r5,-2
	ctx.r5.s64 = -2;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82110E14;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr. r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bge 0x82110e34
	if (!ctx.cr0.lt) goto loc_82110E34;
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82110E34;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82110E34:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82110E3C"))) PPC_WEAK_FUNC(sub_82110E3C);
PPC_FUNC_IMPL(__imp__sub_82110E3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82110E40"))) PPC_WEAK_FUNC(sub_82110E40);
PPC_FUNC_IMPL(__imp__sub_82110E40) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82110E48;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8210c9b8
	ctx.lr = 0x82110E54;
	sub_8210C9B8(ctx, base);
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// li r28,0
	ctx.r28.s64 = 0;
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x82110e84
	if (!ctx.cr6.gt) goto loc_82110E84;
loc_82110E68:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// bl 0x8210c670
	ctx.lr = 0x82110E74;
	sub_8210C670(ctx, base);
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82110e68
	if (ctx.cr6.lt) goto loc_82110E68;
loc_82110E84:
	// stw r28,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r28.u32);
	// addi r29,r31,68
	ctx.r29.s64 = ctx.r31.s64 + 68;
	// stw r28,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r28.u32);
	// b 0x82110eac
	goto loc_82110EAC;
loc_82110E94:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8210de68
	ctx.lr = 0x82110EA4;
	sub_8210DE68(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82114628
	ctx.lr = 0x82110EAC;
	sub_82114628(ctx, base);
loc_82110EAC:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82109678
	ctx.lr = 0x82110EB4;
	sub_82109678(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x82110e94
	if (!ctx.cr0.eq) goto loc_82110E94;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82110EC4"))) PPC_WEAK_FUNC(sub_82110EC4);
PPC_FUNC_IMPL(__imp__sub_82110EC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82110EC8"))) PPC_WEAK_FUNC(sub_82110EC8);
PPC_FUNC_IMPL(__imp__sub_82110EC8) {
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
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x82110640
	ctx.lr = 0x82110EE8;
	sub_82110640(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82110f2c
	if (ctx.cr0.eq) goto loc_82110F2C;
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r10,108(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82110f18
	if (ctx.cr6.eq) goto loc_82110F18;
	// stw r3,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r3.u32);
	// b 0x82110f1c
	goto loc_82110F1C;
loc_82110F18:
	// stw r3,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r3.u32);
loc_82110F1C:
	// lwz r11,116(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// stw r3,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r3.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r11.u32);
loc_82110F2C:
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

__attribute__((alias("__imp__sub_82110F44"))) PPC_WEAK_FUNC(sub_82110F44);
PPC_FUNC_IMPL(__imp__sub_82110F44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82110F48"))) PPC_WEAK_FUNC(sub_82110F48);
PPC_FUNC_IMPL(__imp__sub_82110F48) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82110F50;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,52(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82110F74;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,-5536
	ctx.r3.s64 = ctx.r11.s64 + -5536;
	// ori r5,r5,2
	ctx.r5.u64 = ctx.r5.u64 | 2;
	// li r4,36
	ctx.r4.s64 = 36;
	// bl 0x82108aa8
	ctx.lr = 0x82110F90;
	sub_82108AA8(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x82110fac
	if (ctx.cr0.eq) goto loc_82110FAC;
	// li r5,36
	ctx.r5.s64 = 36;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207dac0
	ctx.lr = 0x82110FA8;
	sub_8207DAC0(ctx, base);
	// b 0x82110fb0
	goto loc_82110FB0;
loc_82110FAC:
	// li r31,0
	ctx.r31.s64 = 0;
loc_82110FB0:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82110fc4
	if (!ctx.cr6.eq) goto loc_82110FC4;
	// lis r29,-32761
	ctx.r29.s64 = -2147024896;
	// ori r29,r29,14
	ctx.r29.u64 = ctx.r29.u64 | 14;
	// b 0x82111090
	goto loc_82111090;
loc_82110FC4:
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82110ffc
	if (ctx.cr6.eq) goto loc_82110FFC;
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82110ffc
	if (!ctx.cr6.eq) goto loc_82110FFC;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82110ffc
	if (ctx.cr6.eq) goto loc_82110FFC;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// subf r10,r9,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r9.s64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
loc_82110FFC:
	// lwz r11,248(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 248);
	// addi r28,r27,248
	ctx.r28.s64 = ctx.r27.s64 + 248;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82111014;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r30,r27,148
	ctx.r30.s64 = ctx.r27.s64 + 148;
loc_82111018:
	// mfmsr r10
	ctx.r10.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r11,0,r30
	ctx.reserved.u32 = *(uint32_t*)(base + ctx.r30.u32);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwcx. r11,0,r30
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + ctx.r30.u32), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x82111018
	if (!ctx.cr0.eq) goto loc_82111018;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r27,304
	ctx.r3.s64 = ctx.r27.s64 + 304;
	// bl 0x8210eed8
	ctx.lr = 0x82111040;
	sub_8210EED8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82111050
	if (ctx.cr0.eq) goto loc_82111050;
	// li r29,0
	ctx.r29.s64 = 0;
	// b 0x8211107c
	goto loc_8211107C;
loc_82111050:
	// lis r29,-32761
	ctx.r29.s64 = -2147024896;
	// ori r29,r29,14
	ctx.r29.u64 = ctx.r29.u64 | 14;
loc_82111058:
	// mfmsr r10
	ctx.r10.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r11,0,r30
	ctx.reserved.u32 = *(uint32_t*)(base + ctx.r30.u32);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r30
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + ctx.r30.u32), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x82111058
	if (!ctx.cr0.eq) goto loc_82111058;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82114628
	ctx.lr = 0x8211107C;
	sub_82114628(ctx, base);
loc_8211107C:
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82111090;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82111090:
	// lwz r11,52(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 52);
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821110A8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821110B4"))) PPC_WEAK_FUNC(sub_821110B4);
PPC_FUNC_IMPL(__imp__sub_821110B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821110B8"))) PPC_WEAK_FUNC(sub_821110B8);
PPC_FUNC_IMPL(__imp__sub_821110B8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x821110C0;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,328(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 328);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821110dc
	if (ctx.cr6.eq) goto loc_821110DC;
	// lwz r31,0(r11)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x821110e0
	goto loc_821110E0;
loc_821110DC:
	// li r31,0
	ctx.r31.s64 = 0;
loc_821110E0:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x821111a4
	if (ctx.cr6.eq) goto loc_821111A4;
	// lwz r11,184(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 184);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x82111160
	if (!ctx.cr6.gt) goto loc_82111160;
	// lwz r26,80(r1)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r27,80(r1)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_82111100:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r3,284(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 284);
	// bl 0x8210cce8
	ctx.lr = 0x82111114;
	sub_8210CCE8(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r28,12(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// rlwinm r6,r28,23,9,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 23) & 0x7FFFFF;
	// bl 0x8210fff8
	ctx.lr = 0x8211112C;
	sub_8210FFF8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8211113c
	if (ctx.cr0.eq) goto loc_8211113C;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// rlwinm r26,r28,25,30,31
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 25) & 0x3;
loc_8211113C:
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// lwz r3,284(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 284);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8210c968
	ctx.lr = 0x82111150;
	sub_8210C968(ctx, base);
	// lwz r11,184(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 184);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82111100
	if (ctx.cr6.lt) goto loc_82111100;
loc_82111160:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82110a48
	ctx.lr = 0x82111168;
	sub_82110A48(ctx, base);
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// li r30,1
	ctx.r30.s64 = 1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82111190
	if (ctx.cr6.eq) goto loc_82111190;
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82111190
	if (!ctx.cr6.eq) goto loc_82111190;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82110b88
	ctx.lr = 0x8211118C;
	sub_82110B88(ctx, base);
	// stw r30,204(r29)
	PPC_STORE_U32(ctx.r29.u32 + 204, ctx.r30.u32);
loc_82111190:
	// addi r3,r29,140
	ctx.r3.s64 = ctx.r29.s64 + 140;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x8210d188
	ctx.lr = 0x821111A0;
	sub_8210D188(ctx, base);
	// stw r30,288(r29)
	PPC_STORE_U32(ctx.r29.u32 + 288, ctx.r30.u32);
loc_821111A4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821111AC"))) PPC_WEAK_FUNC(sub_821111AC);
PPC_FUNC_IMPL(__imp__sub_821111AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821111B0"))) PPC_WEAK_FUNC(sub_821111B0);
PPC_FUNC_IMPL(__imp__sub_821111B0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821111B8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r3,r3,304
	ctx.r3.s64 = ctx.r3.s64 + 304;
	// bl 0x82109678
	ctx.lr = 0x821111C8;
	sub_82109678(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq 0x8211123c
	if (ctx.cr0.eq) goto loc_8211123C;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,-5536
	ctx.r3.s64 = ctx.r11.s64 + -5536;
	// ori r5,r5,2
	ctx.r5.u64 = ctx.r5.u64 | 2;
	// li r4,12
	ctx.r4.s64 = 12;
	// bl 0x82108aa8
	ctx.lr = 0x821111EC;
	sub_82108AA8(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x82111234
	if (ctx.cr0.eq) goto loc_82111234;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r30,208
	ctx.r3.s64 = ctx.r30.s64 + 208;
	// bl 0x82109f68
	ctx.lr = 0x82111200;
	sub_82109F68(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x82111214
	if (!ctx.cr0.eq) goto loc_82111214;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82114628
	ctx.lr = 0x82111210;
	sub_82114628(ctx, base);
	// b 0x82111234
	goto loc_82111234;
loc_82111214:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// lwz r11,32(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 32);
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// lwz r3,284(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 284);
	// bl 0x8210c360
	ctx.lr = 0x82111230;
	sub_8210C360(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
loc_82111234:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82114628
	ctx.lr = 0x8211123C;
	sub_82114628(ctx, base);
loc_8211123C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82111244"))) PPC_WEAK_FUNC(sub_82111244);
PPC_FUNC_IMPL(__imp__sub_82111244) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82111248"))) PPC_WEAK_FUNC(sub_82111248);
PPC_FUNC_IMPL(__imp__sub_82111248) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82111250;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,64(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,296(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 296);
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// twllei r11,0
	// divwu r11,r5,r11
	ctx.r11.u32 = ppc_divwu(ctx.r5.u32, ctx.r11.u32);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x82111288
	if (!ctx.cr6.gt) goto loc_82111288;
	// lwz r4,168(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// bl 0x82110748
	ctx.lr = 0x82111280;
	sub_82110748(ctx, base);
	// mr. r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// blt 0x82111414
	if (ctx.cr0.lt) goto loc_82111414;
loc_82111288:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,284(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 284);
	// bl 0x8210c360
	ctx.lr = 0x82111294;
	sub_8210C360(ctx, base);
	// lwz r11,184(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r29,1
	ctx.r29.s64 = 1;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// ble cr6,0x821112d0
	if (!ctx.cr6.gt) goto loc_821112D0;
loc_821112A8:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r3,284(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 284);
	// bl 0x8210c360
	ctx.lr = 0x821112B4;
	sub_8210C360(ctx, base);
	// cmplw cr6,r30,r3
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r3.u32, ctx.xer);
	// blt cr6,0x821112c0
	if (ctx.cr6.lt) goto loc_821112C0;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_821112C0:
	// lwz r11,184(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x821112a8
	if (ctx.cr6.lt) goto loc_821112A8;
loc_821112D0:
	// lwz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// lwz r11,296(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 296);
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// twllei r9,0
	// divwu r9,r28,r9
	ctx.r9.u32 = ppc_divwu(ctx.r28.u32, ctx.r9.u32);
	// subf r11,r9,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r9.s64;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x821112f4
	if (ctx.cr6.lt) goto loc_821112F4;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
loc_821112F4:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8211142c
	if (ctx.cr6.eq) goto loc_8211142C;
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// bgt cr6,0x8211134c
	if (ctx.cr6.gt) goto loc_8211134C;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r5,300(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 300);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821103e0
	ctx.lr = 0x82111314;
	sub_821103E0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplw cr6,r3,r30
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x821113b4
	if (ctx.cr6.eq) goto loc_821113B4;
	// lwz r10,300(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 300);
	// subf r4,r3,r30
	ctx.r4.s64 = ctx.r30.s64 - ctx.r3.s64;
	// lwz r9,296(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 296);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// twllei r9,0
	// divwu r10,r11,r9
	ctx.r10.u32 = ppc_divwu(ctx.r11.u32, ctx.r9.u32);
	// mullw r10,r10,r9
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// subf r5,r10,r11
	ctx.r5.s64 = ctx.r11.s64 - ctx.r10.s64;
	// bl 0x821103e0
	ctx.lr = 0x82111348;
	sub_821103E0(ctx, base);
	// b 0x821113b4
	goto loc_821113B4;
loc_8211134C:
	// lwz r11,184(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x821113b4
	if (!ctx.cr6.gt) goto loc_821113B4;
loc_8211135C:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r6,300(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 300);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821102d8
	ctx.lr = 0x82111370;
	sub_821102D8(ctx, base);
	// cmplw cr6,r3,r30
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x821113a4
	if (ctx.cr6.eq) goto loc_821113A4;
	// lwz r11,300(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 300);
	// subf r5,r3,r30
	ctx.r5.s64 = ctx.r30.s64 - ctx.r3.s64;
	// lwz r10,296(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 296);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// twllei r10,0
	// divwu r9,r11,r10
	ctx.r9.u32 = ppc_divwu(ctx.r11.u32, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mullw r10,r9,r10
	ctx.r10.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// subf r6,r10,r11
	ctx.r6.s64 = ctx.r11.s64 - ctx.r10.s64;
	// bl 0x821102d8
	ctx.lr = 0x821113A4;
	sub_821102D8(ctx, base);
loc_821113A4:
	// lwz r11,184(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8211135c
	if (ctx.cr6.lt) goto loc_8211135C;
loc_821113B4:
	// lwz r5,300(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 300);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,296(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 296);
	// add r10,r5,r30
	ctx.r10.u64 = ctx.r5.u64 + ctx.r30.u64;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x821113e8
	if (!ctx.cr6.gt) goto loc_821113E8;
	// subf r29,r5,r11
	ctx.r29.s64 = ctx.r11.s64 - ctx.r5.s64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82110d28
	ctx.lr = 0x821113D8;
	sub_82110D28(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// subf r4,r29,r30
	ctx.r4.s64 = ctx.r30.s64 - ctx.r29.s64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x821113ec
	goto loc_821113EC;
loc_821113E8:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
loc_821113EC:
	// bl 0x82110d28
	ctx.lr = 0x821113F0;
	sub_82110D28(ctx, base);
	// lwz r11,300(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 300);
	// lwz r10,296(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 296);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// twllei r10,0
	// divwu r9,r11,r10
	ctx.r9.u32 = ppc_divwu(ctx.r11.u32, ctx.r10.u32);
	// mullw r10,r9,r10
	ctx.r10.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// stw r11,300(r31)
	PPC_STORE_U32(ctx.r31.u32 + 300, ctx.r11.u32);
	// b 0x8211142c
	goto loc_8211142C;
loc_82111414:
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8211142C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8211142C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82111434"))) PPC_WEAK_FUNC(sub_82111434);
PPC_FUNC_IMPL(__imp__sub_82111434) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82111438"))) PPC_WEAK_FUNC(sub_82111438);
PPC_FUNC_IMPL(__imp__sub_82111438) {
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
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x82110520
	ctx.lr = 0x82111458;
	sub_82110520(ctx, base);
	// addi r3,r31,124
	ctx.r3.s64 = ctx.r31.s64 + 124;
	// bl 0x82110520
	ctx.lr = 0x82111460;
	sub_82110520(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r30,248(r31)
	PPC_STORE_U32(ctx.r31.u32 + 248, ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,252(r31)
	PPC_STORE_U32(ctx.r31.u32 + 252, ctx.r11.u32);
	// stw r11,256(r31)
	PPC_STORE_U32(ctx.r31.u32 + 256, ctx.r11.u32);
	// stw r11,260(r31)
	PPC_STORE_U32(ctx.r31.u32 + 260, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_82111490"))) PPC_WEAK_FUNC(sub_82111490);
PPC_FUNC_IMPL(__imp__sub_82111490) {
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
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r4,248(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 248);
	// bl 0x82088c48
	ctx.lr = 0x821114B8;
	sub_82088C48(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,252(r31)
	PPC_STORE_U32(ctx.r31.u32 + 252, ctx.r3.u32);
	// beq 0x8211151c
	if (ctx.cr0.eq) goto loc_8211151C;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,-5536
	ctx.r3.s64 = ctx.r11.s64 + -5536;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x82108aa8
	ctx.lr = 0x821114DC;
	sub_82108AA8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x821114f8
	if (ctx.cr0.eq) goto loc_821114F8;
	// lwz r11,252(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// b 0x821114fc
	goto loc_821114FC;
loc_821114F8:
	// li r4,0
	ctx.r4.s64 = 0;
loc_821114FC:
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8211151c
	if (ctx.cr6.eq) goto loc_8211151C;
	// addi r3,r31,124
	ctx.r3.s64 = ctx.r31.s64 + 124;
	// bl 0x82110ec8
	ctx.lr = 0x8211150C;
	sub_82110EC8(ctx, base);
	// stw r30,256(r31)
	PPC_STORE_U32(ctx.r31.u32 + 256, ctx.r30.u32);
	// stw r30,260(r31)
	PPC_STORE_U32(ctx.r31.u32 + 260, ctx.r30.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82111524
	goto loc_82111524;
loc_8211151C:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
loc_82111524:
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

__attribute__((alias("__imp__sub_8211153C"))) PPC_WEAK_FUNC(sub_8211153C);
PPC_FUNC_IMPL(__imp__sub_8211153C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82111540"))) PPC_WEAK_FUNC(sub_82111540);
PPC_FUNC_IMPL(__imp__sub_82111540) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82111548;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r11,232(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 232);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// li r30,-1
	ctx.r30.s64 = -1;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x82111598
	goto loc_82111598;
loc_82111568:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmplw cr6,r10,r31
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r31.u32, ctx.xer);
	// blt cr6,0x8211158c
	if (ctx.cr6.lt) goto loc_8211158C;
	// cmplw cr6,r10,r30
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r30.u32, ctx.xer);
	// bge cr6,0x8211158c
	if (!ctx.cr6.lt) goto loc_8211158C;
	// mr r28,r9
	ctx.r28.u64 = ctx.r9.u64;
	// mr r30,r10
	ctx.r30.u64 = ctx.r10.u64;
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
loc_8211158C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821115a0
	if (ctx.cr6.eq) goto loc_821115A0;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
loc_82111598:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82111568
	if (!ctx.cr6.eq) goto loc_82111568;
loc_821115A0:
	// addi r29,r27,124
	ctx.r29.s64 = ctx.r27.s64 + 124;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82110570
	ctx.lr = 0x821115AC;
	sub_82110570(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82110ec8
	ctx.lr = 0x821115B8;
	sub_82110EC8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82111634
	if (ctx.cr0.eq) goto loc_82111634;
	// cmplw cr6,r30,r31
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x82111640
	if (ctx.cr6.eq) goto loc_82111640;
	// stw r31,4(r28)
	PPC_STORE_U32(ctx.r28.u32 + 4, ctx.r31.u32);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,-5536
	ctx.r3.s64 = ctx.r11.s64 + -5536;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x82108aa8
	ctx.lr = 0x821115E4;
	sub_82108AA8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8211160c
	if (ctx.cr0.eq) goto loc_8211160C;
	// lwz r11,4(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// subf r9,r31,r30
	ctx.r9.s64 = ctx.r30.s64 - ctx.r31.s64;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// b 0x82111610
	goto loc_82111610;
loc_8211160C:
	// li r31,0
	ctx.r31.s64 = 0;
loc_82111610:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82111634
	if (ctx.cr6.eq) goto loc_82111634;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82110ec8
	ctx.lr = 0x82111624;
	sub_82110EC8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x82111640
	if (!ctx.cr0.eq) goto loc_82111640;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82114628
	ctx.lr = 0x82111634;
	sub_82114628(ctx, base);
loc_82111634:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82111638:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_82111640:
	// lwz r11,260(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 260);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82111694
	if (!ctx.cr6.eq) goto loc_82111694;
	// lwz r9,232(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 232);
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x82111688
	goto loc_82111688;
loc_82111658:
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82111670
	if (ctx.cr6.eq) goto loc_82111670;
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x82111674
	goto loc_82111674;
loc_82111670:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82111674:
	// lwz r11,260(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 260);
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x82111688
	if (ctx.cr6.gt) goto loc_82111688;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_82111688:
	// stw r11,260(r27)
	PPC_STORE_U32(ctx.r27.u32 + 260, ctx.r11.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82111658
	if (!ctx.cr6.eq) goto loc_82111658;
loc_82111694:
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// b 0x82111638
	goto loc_82111638;
}

__attribute__((alias("__imp__sub_8211169C"))) PPC_WEAK_FUNC(sub_8211169C);
PPC_FUNC_IMPL(__imp__sub_8211169C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821116A0"))) PPC_WEAK_FUNC(sub_821116A0);
PPC_FUNC_IMPL(__imp__sub_821116A0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x821116A8;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,108(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 108);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// li r24,0
	ctx.r24.s64 = 0;
	// b 0x821116dc
	goto loc_821116DC;
loc_821116C0:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r4
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x821116e8
	if (ctx.cr6.eq) goto loc_821116E8;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821116f0
	if (ctx.cr6.eq) goto loc_821116F0;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
loc_821116DC:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821116c0
	if (!ctx.cr6.eq) goto loc_821116C0;
	// b 0x821116f0
	goto loc_821116F0;
loc_821116E8:
	// mr r28,r10
	ctx.r28.u64 = ctx.r10.u64;
	// mr r24,r11
	ctx.r24.u64 = ctx.r11.u64;
loc_821116F0:
	// lwz r11,232(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 232);
	// li r3,0
	ctx.r3.s64 = 0;
	// li r26,0
	ctx.r26.s64 = 0;
	// li r27,0
	ctx.r27.s64 = 0;
	// li r25,0
	ctx.r25.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82111760
	if (ctx.cr6.eq) goto loc_82111760;
	// lwz r7,0(r28)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
loc_82111710:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// bne cr6,0x82111734
	if (!ctx.cr6.eq) goto loc_82111734;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// mr r27,r11
	ctx.r27.u64 = ctx.r11.u64;
	// b 0x8211174c
	goto loc_8211174C;
loc_82111734:
	// lwz r8,4(r28)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x8211174c
	if (!ctx.cr6.eq) goto loc_8211174C;
	// mr r26,r10
	ctx.r26.u64 = ctx.r10.u64;
	// mr r25,r11
	ctx.r25.u64 = ctx.r11.u64;
loc_8211174C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82111760
	if (ctx.cr6.eq) goto loc_82111760;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82111710
	if (!ctx.cr6.eq) goto loc_82111710;
loc_82111760:
	// lwz r30,0(r28)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// lwz r31,4(r28)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// beq cr6,0x8211178c
	if (ctx.cr6.eq) goto loc_8211178C;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r30,0(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// add r31,r11,r31
	ctx.r31.u64 = ctx.r11.u64 + ctx.r31.u64;
	// bl 0x82114628
	ctx.lr = 0x82111780;
	sub_82114628(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r29,124
	ctx.r3.s64 = ctx.r29.s64 + 124;
	// bl 0x82110570
	ctx.lr = 0x8211178C;
	sub_82110570(ctx, base);
loc_8211178C:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x821117b0
	if (ctx.cr6.eq) goto loc_821117B0;
	// lwz r11,4(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// add r31,r11,r31
	ctx.r31.u64 = ctx.r11.u64 + ctx.r31.u64;
	// bl 0x82114628
	ctx.lr = 0x821117A4;
	sub_82114628(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// addi r3,r29,124
	ctx.r3.s64 = ctx.r29.s64 + 124;
	// bl 0x82110570
	ctx.lr = 0x821117B0;
	sub_82110570(ctx, base);
loc_821117B0:
	// stw r30,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r30.u32);
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// stw r31,4(r28)
	PPC_STORE_U32(ctx.r28.u32 + 4, ctx.r31.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82110570
	ctx.lr = 0x821117C4;
	sub_82110570(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r29,124
	ctx.r3.s64 = ctx.r29.s64 + 124;
	// bl 0x82110ec8
	ctx.lr = 0x821117D0;
	sub_82110EC8(ctx, base);
	// lwz r11,260(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 260);
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// bgt cr6,0x821117e0
	if (ctx.cr6.gt) goto loc_821117E0;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
loc_821117E0:
	// stw r11,260(r29)
	PPC_STORE_U32(ctx.r29.u32 + 260, ctx.r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821117EC"))) PPC_WEAK_FUNC(sub_821117EC);
PPC_FUNC_IMPL(__imp__sub_821117EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821117F0"))) PPC_WEAK_FUNC(sub_821117F0);
PPC_FUNC_IMPL(__imp__sub_821117F0) {
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
	// bl 0x8210e618
	ctx.lr = 0x82111808;
	sub_8210E618(ctx, base);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// addi r6,r8,25552
	ctx.r6.s64 = ctx.r8.s64 + 25552;
	// addi r10,r31,208
	ctx.r10.s64 = ctx.r31.s64 + 208;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r6,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r6.u32);
	// addi r9,r9,25424
	ctx.r9.s64 = ctx.r9.s64 + 25424;
	// addi r7,r7,25388
	ctx.r7.s64 = ctx.r7.s64 + 25388;
	// stw r11,184(r31)
	PPC_STORE_U32(ctx.r31.u32 + 184, ctx.r11.u32);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// stw r11,188(r31)
	PPC_STORE_U32(ctx.r31.u32 + 188, ctx.r11.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r11,204(r31)
	PPC_STORE_U32(ctx.r31.u32 + 204, ctx.r11.u32);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// stw r7,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r7.u32);
	// addi r9,r31,304
	ctx.r9.s64 = ctx.r31.s64 + 304;
	// stw r11,208(r31)
	PPC_STORE_U32(ctx.r31.u32 + 208, ctx.r11.u32);
	// addi r7,r6,24644
	ctx.r7.s64 = ctx.r6.s64 + 24644;
	// stw r10,212(r31)
	PPC_STORE_U32(ctx.r31.u32 + 212, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,232(r31)
	PPC_STORE_U32(ctx.r31.u32 + 232, ctx.r11.u32);
	// stw r11,236(r31)
	PPC_STORE_U32(ctx.r31.u32 + 236, ctx.r11.u32);
	// stw r11,240(r31)
	PPC_STORE_U32(ctx.r31.u32 + 240, ctx.r11.u32);
	// stw r8,244(r31)
	PPC_STORE_U32(ctx.r31.u32 + 244, ctx.r8.u32);
	// stw r11,216(r31)
	PPC_STORE_U32(ctx.r31.u32 + 216, ctx.r11.u32);
	// lwz r6,208(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 208);
	// lwz r10,212(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 212);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r6,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r6.u32);
	// stw r10,208(r31)
	PPC_STORE_U32(ctx.r31.u32 + 208, ctx.r10.u32);
	// addi r10,r9,8
	ctx.r10.s64 = ctx.r9.s64 + 8;
	// stw r11,280(r31)
	PPC_STORE_U32(ctx.r31.u32 + 280, ctx.r11.u32);
	// stw r7,248(r31)
	PPC_STORE_U32(ctx.r31.u32 + 248, ctx.r7.u32);
	// stw r11,284(r31)
	PPC_STORE_U32(ctx.r31.u32 + 284, ctx.r11.u32);
	// stw r11,288(r31)
	PPC_STORE_U32(ctx.r31.u32 + 288, ctx.r11.u32);
	// stw r11,292(r31)
	PPC_STORE_U32(ctx.r31.u32 + 292, ctx.r11.u32);
	// stw r11,296(r31)
	PPC_STORE_U32(ctx.r31.u32 + 296, ctx.r11.u32);
	// stw r11,300(r31)
	PPC_STORE_U32(ctx.r31.u32 + 300, ctx.r11.u32);
	// stw r11,304(r31)
	PPC_STORE_U32(ctx.r31.u32 + 304, ctx.r11.u32);
	// stw r11,328(r31)
	PPC_STORE_U32(ctx.r31.u32 + 328, ctx.r11.u32);
	// stw r11,332(r31)
	PPC_STORE_U32(ctx.r31.u32 + 332, ctx.r11.u32);
	// stw r11,336(r31)
	PPC_STORE_U32(ctx.r31.u32 + 336, ctx.r11.u32);
	// stw r10,308(r31)
	PPC_STORE_U32(ctx.r31.u32 + 308, ctx.r10.u32);
	// stw r8,340(r31)
	PPC_STORE_U32(ctx.r31.u32 + 340, ctx.r8.u32);
	// stw r11,312(r31)
	PPC_STORE_U32(ctx.r31.u32 + 312, ctx.r11.u32);
	// lwz r10,304(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 304);
	// lwz r11,308(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 308);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// stw r11,304(r31)
	PPC_STORE_U32(ctx.r31.u32 + 304, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_821118EC"))) PPC_WEAK_FUNC(sub_821118EC);
PPC_FUNC_IMPL(__imp__sub_821118EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821118F0"))) PPC_WEAK_FUNC(sub_821118F0);
PPC_FUNC_IMPL(__imp__sub_821118F0) {
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
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x8210e6f0
	ctx.lr = 0x82111910;
	sub_8210E6F0(ctx, base);
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// bne cr6,0x8211193c
	if (!ctx.cr6.eq) goto loc_8211193C;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r10.u32);
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,184(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// b 0x82111954
	goto loc_82111954;
loc_8211193C:
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r10.u32);
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r10,184(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// lwz r9,32(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// subf r10,r10,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r10.s64;
loc_82111954:
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_82111970"))) PPC_WEAK_FUNC(sub_82111970);
PPC_FUNC_IMPL(__imp__sub_82111970) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x821119e0
	sub_821119E0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82111978"))) PPC_WEAK_FUNC(sub_82111978);
PPC_FUNC_IMPL(__imp__sub_82111978) {
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
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r11,r11,25552
	ctx.r11.s64 = ctx.r11.s64 + 25552;
	// addi r10,r10,25388
	ctx.r10.s64 = ctx.r10.s64 + 25388;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r10.u32);
	// addi r3,r3,304
	ctx.r3.s64 = ctx.r3.s64 + 304;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// bl 0x8210ef58
	ctx.lr = 0x821119B4;
	sub_8210EF58(ctx, base);
	// addi r3,r31,248
	ctx.r3.s64 = ctx.r31.s64 + 248;
	// bl 0x82108b60
	ctx.lr = 0x821119BC;
	sub_82108B60(ctx, base);
	// addi r3,r31,208
	ctx.r3.s64 = ctx.r31.s64 + 208;
	// bl 0x8210ef58
	ctx.lr = 0x821119C4;
	sub_8210EF58(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8210e7b8
	ctx.lr = 0x821119CC;
	sub_8210E7B8(ctx, base);
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

__attribute__((alias("__imp__sub_821119E0"))) PPC_WEAK_FUNC(sub_821119E0);
PPC_FUNC_IMPL(__imp__sub_821119E0) {
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
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x82111978
	ctx.lr = 0x82111A00;
	sub_82111978(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82111a10
	if (ctx.cr0.eq) goto loc_82111A10;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82114628
	ctx.lr = 0x82111A10;
	sub_82114628(ctx, base);
loc_82111A10:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
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

__attribute__((alias("__imp__sub_82111A2C"))) PPC_WEAK_FUNC(sub_82111A2C);
PPC_FUNC_IMPL(__imp__sub_82111A2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82111A30"))) PPC_WEAK_FUNC(sub_82111A30);
PPC_FUNC_IMPL(__imp__sub_82111A30) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82111A38;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x8210d290
	ctx.lr = 0x82111A44;
	sub_8210D290(ctx, base);
	// lwz r3,280(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 280);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82111a5c
	if (ctx.cr6.eq) goto loc_82111A5C;
	// bl 0x8210cc50
	ctx.lr = 0x82111A58;
	sub_8210CC50(ctx, base);
	// stw r29,280(r30)
	PPC_STORE_U32(ctx.r30.u32 + 280, ctx.r29.u32);
loc_82111A5C:
	// lwz r4,184(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 184);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82111aac
	if (ctx.cr6.eq) goto loc_82111AAC;
	// lwz r11,48(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 48);
	// lwz r9,16244(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16244);
loc_82111A70:
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82111a88
	if (ctx.cr6.eq) goto loc_82111A88;
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x82111a8c
	goto loc_82111A8C;
loc_82111A88:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_82111A8C:
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82111a70
	if (ctx.cr6.lt) goto loc_82111A70;
	// lwz r10,256(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 256);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x82111a70
	if (!ctx.cr6.lt) goto loc_82111A70;
	// bl 0x821116a0
	ctx.lr = 0x82111AAC;
	sub_821116A0(ctx, base);
loc_82111AAC:
	// addi r31,r30,300
	ctx.r31.s64 = ctx.r30.s64 + 300;
	// b 0x82111ac0
	goto loc_82111AC0;
loc_82111AB4:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82111ac0
	if (ctx.cr6.eq) goto loc_82111AC0;
	// bl 0x82114628
	ctx.lr = 0x82111AC0;
	sub_82114628(ctx, base);
loc_82111AC0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82109678
	ctx.lr = 0x82111AC8;
	sub_82109678(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x82111ab4
	if (!ctx.cr0.eq) goto loc_82111AB4;
	// addi r31,r30,204
	ctx.r31.s64 = ctx.r30.s64 + 204;
	// b 0x82111ae4
	goto loc_82111AE4;
loc_82111AD8:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82111ae4
	if (ctx.cr6.eq) goto loc_82111AE4;
	// bl 0x82114628
	ctx.lr = 0x82111AE4;
	sub_82114628(ctx, base);
loc_82111AE4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82109678
	ctx.lr = 0x82111AEC;
	sub_82109678(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x82111ad8
	if (!ctx.cr0.eq) goto loc_82111AD8;
	// lwz r3,288(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 288);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82111b08
	if (ctx.cr6.eq) goto loc_82111B08;
	// bl 0x82114628
	ctx.lr = 0x82111B04;
	sub_82114628(ctx, base);
	// stw r29,288(r30)
	PPC_STORE_U32(ctx.r30.u32 + 288, ctx.r29.u32);
loc_82111B08:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82111B10"))) PPC_WEAK_FUNC(sub_82111B10);
PPC_FUNC_IMPL(__imp__sub_82111B10) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82111B18;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,248(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 248);
	// addi r29,r3,248
	ctx.r29.s64 = ctx.r3.s64 + 248;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82111B38;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r30,288(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 288);
	// bl 0x8210ff08
	ctx.lr = 0x82111B44;
	sub_8210FF08(ctx, base);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r3,288(r31)
	PPC_STORE_U32(ctx.r31.u32 + 288, ctx.r3.u32);
	// beq cr6,0x82111bac
	if (ctx.cr6.eq) goto loc_82111BAC;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82111bb8
	if (!ctx.cr6.eq) goto loc_82111BB8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82110c58
	ctx.lr = 0x82111B60;
	sub_82110C58(ctx, base);
	// lwz r11,204(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 204);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82111ba4
	if (ctx.cr6.eq) goto loc_82111BA4;
	// lwz r11,184(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x82111b9c
	if (!ctx.cr6.gt) goto loc_82111B9C;
loc_82111B7C:
	// li r5,128
	ctx.r5.s64 = 128;
	// lwz r3,284(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 284);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8210c5d8
	ctx.lr = 0x82111B8C;
	sub_8210C5D8(ctx, base);
	// lwz r11,184(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82111b7c
	if (ctx.cr6.lt) goto loc_82111B7C;
loc_82111B9C:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,204(r31)
	PPC_STORE_U32(ctx.r31.u32 + 204, ctx.r11.u32);
loc_82111BA4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821111b0
	ctx.lr = 0x82111BAC;
	sub_821111B0(ctx, base);
loc_82111BAC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821110b8
	ctx.lr = 0x82111BB4;
	sub_821110B8(ctx, base);
	// b 0x82111c1c
	goto loc_82111C1C;
loc_82111BB8:
	// lwz r11,336(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 336);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82111c1c
	if (ctx.cr6.eq) goto loc_82111C1C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82110c58
	ctx.lr = 0x82111BCC;
	sub_82110C58(ctx, base);
	// lwz r11,328(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 328);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82111be0
	if (ctx.cr6.eq) goto loc_82111BE0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x82111be4
	goto loc_82111BE4;
loc_82111BE0:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82111BE4:
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82111c1c
	if (ctx.cr6.eq) goto loc_82111C1C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82110280
	ctx.lr = 0x82111BF8;
	sub_82110280(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x82111c1c
	if (!ctx.cr0.eq) goto loc_82111C1C;
	// lwz r11,204(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 204);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82111c1c
	if (!ctx.cr6.eq) goto loc_82111C1C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82110b88
	ctx.lr = 0x82111C14;
	sub_82110B88(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,204(r31)
	PPC_STORE_U32(ctx.r31.u32 + 204, ctx.r11.u32);
loc_82111C1C:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82111C30;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82111C38"))) PPC_WEAK_FUNC(sub_82111C38);
PPC_FUNC_IMPL(__imp__sub_82111C38) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82111C40;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8210d138
	ctx.lr = 0x82111C5C;
	sub_8210D138(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82111c74
	if (ctx.cr6.eq) goto loc_82111C74;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r31,-140
	ctx.r3.s64 = ctx.r31.s64 + -140;
	// bl 0x82111248
	ctx.lr = 0x82111C74;
	sub_82111248(ctx, base);
loc_82111C74:
	// addi r3,r31,-140
	ctx.r3.s64 = ctx.r31.s64 + -140;
	// bl 0x82111b10
	ctx.lr = 0x82111C7C;
	sub_82111B10(ctx, base);
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// bl 0x8210cb28
	ctx.lr = 0x82111C84;
	sub_8210CB28(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82111C8C"))) PPC_WEAK_FUNC(sub_82111C8C);
PPC_FUNC_IMPL(__imp__sub_82111C8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82111C90"))) PPC_WEAK_FUNC(sub_82111C90);
PPC_FUNC_IMPL(__imp__sub_82111C90) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82111C98;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,204(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 204);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// li r27,0
	ctx.r27.s64 = 0;
	// b 0x82111cd8
	goto loc_82111CD8;
loc_82111CB0:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82111cc8
	if (ctx.cr6.eq) goto loc_82111CC8;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x82111ccc
	goto loc_82111CCC;
loc_82111CC8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82111CCC:
	// lwz r10,260(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// cmplw cr6,r10,r29
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r29.u32, ctx.xer);
	// bge cr6,0x82111ce4
	if (!ctx.cr6.lt) goto loc_82111CE4;
loc_82111CD8:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82111cb0
	if (!ctx.cr6.eq) goto loc_82111CB0;
	// b 0x82111cf4
	goto loc_82111CF4;
loc_82111CE4:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82111540
	ctx.lr = 0x82111CEC;
	sub_82111540(ctx, base);
	// mr. r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// bne 0x82111da0
	if (!ctx.cr0.eq) goto loc_82111DA0;
loc_82111CF4:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,-5536
	ctx.r3.s64 = ctx.r11.s64 + -5536;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// li r4,264
	ctx.r4.s64 = 264;
	// bl 0x82108aa8
	ctx.lr = 0x82111D0C;
	sub_82108AA8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82111d24
	if (ctx.cr0.eq) goto loc_82111D24;
	// lwz r4,220(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + 220);
	// bl 0x82111438
	ctx.lr = 0x82111D1C;
	sub_82111438(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x82111d28
	goto loc_82111D28;
loc_82111D24:
	// li r31,0
	ctx.r31.s64 = 0;
loc_82111D28:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82111da0
	if (ctx.cr6.eq) goto loc_82111DA0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82109e70
	ctx.lr = 0x82111D3C;
	sub_82109E70(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82111d90
	if (ctx.cr0.eq) goto loc_82111D90;
	// lwz r11,224(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 224);
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// bgt cr6,0x82111d54
	if (ctx.cr6.gt) goto loc_82111D54;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_82111D54:
	// addi r11,r11,4095
	ctx.r11.s64 = ctx.r11.s64 + 4095;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rlwinm r4,r11,0,0,19
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFF000;
	// bl 0x82111490
	ctx.lr = 0x82111D64;
	sub_82111490(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x82111d80
	if (ctx.cr0.lt) goto loc_82111D80;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82111540
	ctx.lr = 0x82111D78;
	sub_82111540(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// b 0x82111d88
	goto loc_82111D88;
loc_82111D80:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x821105e0
	ctx.lr = 0x82111D88;
	sub_821105E0(ctx, base);
loc_82111D88:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge cr6,0x82111da0
	if (!ctx.cr6.lt) goto loc_82111DA0;
loc_82111D90:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8210a8a0
	ctx.lr = 0x82111D98;
	sub_8210A8A0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82114628
	ctx.lr = 0x82111DA0;
	sub_82114628(ctx, base);
loc_82111DA0:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82111DAC"))) PPC_WEAK_FUNC(sub_82111DAC);
PPC_FUNC_IMPL(__imp__sub_82111DAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82111DB0"))) PPC_WEAK_FUNC(sub_82111DB0);
PPC_FUNC_IMPL(__imp__sub_82111DB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x82111DB8;
	__savegprlr_25(ctx, base);
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.f31.u64);
	// addi r31,r1,-224
	ctx.r31.s64 = ctx.r1.s64 + -224;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r11,2(r6)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r6.u32 + 2);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r25,4(r6)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// mr r26,r8
	ctx.r26.u64 = ctx.r8.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x82111e1c
	if (!ctx.cr6.eq) goto loc_82111E1C;
	// clrldi r10,r25,32
	ctx.r10.u64 = ctx.r25.u64 & 0xFFFFFFFF;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// std r10,96(r31)
	PPC_STORE_U64(ctx.r31.u32 + 96, ctx.r10.u64);
	// lfd f0,96(r31)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r31.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f13,f0
	ctx.f13.f64 = double(float(ctx.f0.f64));
	// lfs f0,25668(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 25668);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f13,f1
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f1.f64));
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bgt cr6,0x82111e44
	if (ctx.cr6.gt) goto loc_82111E44;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x82111e50
	if (ctx.cr6.eq) goto loc_82111E50;
loc_82111E1C:
	// clrldi r11,r25,32
	ctx.r11.u64 = ctx.r25.u64 & 0xFFFFFFFF;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// std r11,96(r31)
	PPC_STORE_U64(ctx.r31.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r31)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r31.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f13,f0
	ctx.f13.f64 = double(float(ctx.f0.f64));
	// lfs f0,25664(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 25664);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f13,f31
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f31.f64));
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x82111e50
	if (!ctx.cr6.gt) goto loc_82111E50;
loc_82111E44:
	// lis r3,-30570
	ctx.r3.s64 = -2003435520;
	// ori r3,r3,1
	ctx.r3.u64 = ctx.r3.u64 | 1;
	// b 0x82112028
	goto loc_82112028;
loc_82111E50:
	// lwz r11,248(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 248);
	// addi r3,r30,248
	ctx.r3.s64 = ctx.r30.s64 + 248;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82111E64;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82112028
	if (ctx.cr0.lt) goto loc_82112028;
	// li r11,128
	ctx.r11.s64 = 128;
	// lwz r10,20(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// li r9,16
	ctx.r9.s64 = 16;
	// lhz r6,2(r29)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r29.u32 + 2);
	// li r8,16
	ctx.r8.s64 = 16;
	// sth r11,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r11.u16);
	// mr r7,r25
	ctx.r7.u64 = ctx.r25.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,40
	ctx.r4.s64 = 40;
	// addi r3,r31,112
	ctx.r3.s64 = ctx.r31.s64 + 112;
	// bl 0x82112a78
	ctx.lr = 0x82111E98;
	sub_82112A78(ctx, base);
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// addi r6,r31,112
	ctx.r6.s64 = ctx.r31.s64 + 112;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8210e128
	ctx.lr = 0x82111EB4;
	sub_8210E128(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82112028
	if (ctx.cr0.lt) goto loc_82112028;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,4(r29)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// bl 0x82110748
	ctx.lr = 0x82111EC8;
	sub_82110748(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82112028
	if (ctx.cr0.lt) goto loc_82112028;
	// lwz r8,64(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 64);
	// li r10,256
	ctx.r10.s64 = 256;
	// li r6,7936
	ctx.r6.s64 = 7936;
	// lwz r7,296(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 296);
	// subfic r11,r8,1
	ctx.xer.ca = ctx.r8.u32 <= 1;
	ctx.r11.s64 = 1 - ctx.r8.s64;
	// li r5,4
	ctx.r5.s64 = 4;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// li r9,512
	ctx.r9.s64 = 512;
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// divwu r10,r10,r11
	ctx.r10.u32 = ppc_divwu(ctx.r10.u32, ctx.r11.u32);
	// twllei r11,0
	// divwu r6,r6,r11
	ctx.r6.u32 = ppc_divwu(ctx.r6.u32, ctx.r11.u32);
	// twllei r11,0
	// add r11,r7,r10
	ctx.r11.u64 = ctx.r7.u64 + ctx.r10.u64;
	// twllei r10,0
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// divwu r7,r11,r10
	ctx.r7.u32 = ppc_divwu(ctx.r11.u32, ctx.r10.u32);
	// mullw r10,r7,r10
	ctx.r10.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// subf r10,r10,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r10.s64;
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
loc_82111F28:
	// rlwinm r10,r9,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplw cr6,r10,r6
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r6.u32, ctx.xer);
	// ble cr6,0x82111f44
	if (!ctx.cr6.gt) goto loc_82111F44;
	// rlwinm. r5,r5,31,25,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 31) & 0x7F;
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// rlwinm r9,r9,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// bne 0x82111f28
	if (!ctx.cr0.eq) goto loc_82111F28;
loc_82111F44:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// rlwinm r10,r9,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r9,r8,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + ctx.r11.u64;
	// mulli r11,r9,12
	ctx.r11.s64 = ctx.r9.s64 * 12;
	// stw r9,184(r30)
	PPC_STORE_U32(ctx.r30.u32 + 184, ctx.r9.u32);
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
	// rlwinm r12,r11,0,0,27
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x8215c0b4
	ctx.lr = 0x82111F68;
	sub_8215C0B4(ctx, base);
	// lwz r11,0(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stwux r11,r1,r12
	ea = ctx.r1.u32 + ctx.r12.u32;
	PPC_STORE_U32(ea, ctx.r11.u32);
	ctx.r1.u32 = ea;
	// addi r28,r1,96
	ctx.r28.s64 = ctx.r1.s64 + 96;
	// beq cr6,0x82111fd4
	if (ctx.cr6.eq) goto loc_82111FD4;
	// addi r11,r28,-3
	ctx.r11.s64 = ctx.r28.s64 + -3;
loc_82111F84:
	// lwz r9,184(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 184);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x82111fa4
	if (!ctx.cr6.eq) goto loc_82111FA4;
	// lwz r9,64(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 64);
	// clrlwi. r9,r9,31
	ctx.r9.u64 = ctx.r9.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// li r9,1
	ctx.r9.s64 = 1;
	// bne 0x82111fa8
	if (!ctx.cr0.eq) goto loc_82111FA8;
loc_82111FA4:
	// li r9,0
	ctx.r9.s64 = 0;
loc_82111FA8:
	// cntlzw r9,r9
	ctx.r9.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// stw r25,3(r11)
	PPC_STORE_U32(ctx.r11.u32 + 3, ctx.r25.u32);
	// stw r8,7(r11)
	PPC_STORE_U32(ctx.r11.u32 + 7, ctx.r8.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r9,r9,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stb r9,11(r11)
	PPC_STORE_U8(ctx.r11.u32 + 11, ctx.r9.u8);
	// stbu r5,12(r11)
	ea = 12 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r5.u8);
	ctx.r11.u32 = ea;
	// lwz r9,184(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 184);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x82111f84
	if (ctx.cr6.lt) goto loc_82111F84;
loc_82111FD4:
	// bl 0x8210c130
	ctx.lr = 0x82111FD8;
	sub_8210C130(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r3,184(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 184);
	// bl 0x8210c148
	ctx.lr = 0x82111FE4;
	sub_8210C148(ctx, base);
	// lwz r11,52(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 52);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r3,r11,16040
	ctx.r3.s64 = ctx.r11.s64 + 16040;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82111c90
	ctx.lr = 0x82111FF8;
	sub_82111C90(ctx, base);
	// mr. r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stw r7,188(r30)
	PPC_STORE_U32(ctx.r30.u32 + 188, ctx.r7.u32);
	// bne 0x82112010
	if (!ctx.cr0.eq) goto loc_82112010;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// b 0x82112028
	goto loc_82112028;
loc_82112010:
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// lwz r3,184(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 184);
	// addi r6,r30,284
	ctx.r6.s64 = ctx.r30.s64 + 284;
	// li r5,6
	ctx.r5.s64 = 6;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x8210ce50
	ctx.lr = 0x82112028;
	sub_8210CE50(ctx, base);
loc_82112028:
	// addi r1,r31,224
	ctx.r1.s64 = ctx.r31.s64 + 224;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82112034"))) PPC_WEAK_FUNC(sub_82112034);
PPC_FUNC_IMPL(__imp__sub_82112034) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82112038"))) PPC_WEAK_FUNC(sub_82112038);
PPC_FUNC_IMPL(__imp__sub_82112038) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82112040;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r29,0(r5)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// cmplwi cr6,r11,357
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 357, ctx.xer);
	// bne cr6,0x82112060
	if (!ctx.cr6.eq) goto loc_82112060;
	// li r11,32
	ctx.r11.s64 = 32;
	// b 0x82112078
	goto loc_82112078;
loc_82112060:
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x82112070
	if (!ctx.cr6.eq) goto loc_82112070;
	// li r11,18
	ctx.r11.s64 = 18;
	// b 0x82112078
	goto loc_82112078;
loc_82112070:
	// lhz r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 16);
	// addi r11,r11,18
	ctx.r11.s64 = ctx.r11.s64 + 18;
loc_82112078:
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
	// lhz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,357
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 357, ctx.xer);
	// bne cr6,0x82112090
	if (!ctx.cr6.eq) goto loc_82112090;
	// li r31,32
	ctx.r31.s64 = 32;
	// b 0x821120a8
	goto loc_821120A8;
loc_82112090:
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x821120a0
	if (!ctx.cr6.eq) goto loc_821120A0;
	// li r31,16
	ctx.r31.s64 = 16;
	// b 0x821120a8
	goto loc_821120A8;
loc_821120A0:
	// lhz r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 16);
	// addi r31,r11,18
	ctx.r31.s64 = ctx.r11.s64 + 18;
loc_821120A8:
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207dac0
	ctx.lr = 0x821120B8;
	sub_8207DAC0(ctx, base);
	// subf r5,r31,r29
	ctx.r5.s64 = ctx.r29.s64 - ctx.r31.s64;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r3,r31,r30
	ctx.r3.u64 = ctx.r31.u64 + ctx.r30.u64;
	// bl 0x8207da20
	ctx.lr = 0x821120C8;
	sub_8207DA20(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821120D0"))) PPC_WEAK_FUNC(sub_821120D0);
PPC_FUNC_IMPL(__imp__sub_821120D0) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lhz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// cmplwi cr6,r3,65534
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 65534, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// addi r9,r11,24
	ctx.r9.s64 = ctx.r11.s64 + 24;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r11,r9,4
	ctx.r11.s64 = ctx.r9.s64 + 4;
	// addi r10,r10,24800
	ctx.r10.s64 = ctx.r10.s64 + 24800;
	// addi r8,r11,12
	ctx.r8.s64 = ctx.r11.s64 + 12;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
loc_821120F8:
	// lbz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r7,r6,r7
	ctx.r7.s64 = ctx.r7.s64 - ctx.r6.s64;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne 0x82112118
	if (!ctx.cr0.eq) goto loc_82112118;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// bne cr6,0x821120f8
	if (!ctx.cr6.eq) goto loc_821120F8;
loc_82112118:
	// cmpwi r7,0
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne 0x8211212c
	if (!ctx.cr0.eq) goto loc_8211212C;
	// lwz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// clrlwi r3,r11,16
	ctx.r3.u64 = ctx.r11.u32 & 0xFFFF;
	// blr 
	return;
loc_8211212C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82112134"))) PPC_WEAK_FUNC(sub_82112134);
PPC_FUNC_IMPL(__imp__sub_82112134) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82112138"))) PPC_WEAK_FUNC(sub_82112138);
PPC_FUNC_IMPL(__imp__sub_82112138) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bltlr cr6
	if (ctx.cr6.lt) return;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bgtlr cr6
	if (ctx.cr6.gt) return;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,14480
	ctx.r10.s64 = ctx.r10.s64 + 14480;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r3,-4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -4);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82112168"))) PPC_WEAK_FUNC(sub_82112168);
PPC_FUNC_IMPL(__imp__sub_82112168) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lhz r9,2(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 2);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// beq cr6,0x8211218c
	if (ctx.cr6.eq) goto loc_8211218C;
	// addi r9,r9,-2
	ctx.r9.s64 = ctx.r9.s64 + -2;
	// addic r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// subfe r9,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 & ctx.r10.u64;
loc_8211218C:
	// lhz r9,14(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 14);
	// lhz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 16);
	// addi r9,r9,-4
	ctx.r9.s64 = ctx.r9.s64 + -4;
	// addi r8,r8,-32
	ctx.r8.s64 = ctx.r8.s64 + -32;
	// addic r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// subfe r9,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// addic r8,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// and r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 & ctx.r10.u64;
	// subfe r9,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r8.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r3,r9,r10
	ctx.r3.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lhz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + 20);
	// cmplwi cr6,r10,7
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 7, ctx.xer);
	// beq cr6,0x821121d0
	if (ctx.cr6.eq) goto loc_821121D0;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82112228
	goto loc_82112228;
loc_821121D0:
	// li r8,7
	ctx.r8.s64 = 7;
	// addi r10,r11,24
	ctx.r10.s64 = ctx.r11.s64 + 24;
	// li r9,0
	ctx.r9.s64 = 0;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// addi r8,r8,25672
	ctx.r8.s64 = ctx.r8.s64 + 25672;
loc_821121E8:
	// addi r6,r8,16
	ctx.r6.s64 = ctx.r8.s64 + 16;
	// lhz r7,-2(r10)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r10.u32 + -2);
	// lhzx r5,r9,r8
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r8.u32);
	// lhz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// subf r7,r7,r5
	ctx.r7.s64 = ctx.r5.s64 - ctx.r7.s64;
	// lhzx r6,r9,r6
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r6.u32);
	// addic r7,r7,-1
	ctx.xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// subf r6,r4,r6
	ctx.r6.s64 = ctx.r6.s64 - ctx.r4.s64;
	// subfe r7,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r7.u64 = ~ctx.r7.u64 + ctx.r7.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// addic r6,r6,-1
	ctx.xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// and r7,r7,r3
	ctx.r7.u64 = ctx.r7.u64 & ctx.r3.u64;
	// subfe r6,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ~ctx.r6.u64 + ctx.r6.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r3,r6,r7
	ctx.r3.u64 = ctx.r6.u64 & ctx.r7.u64;
	// bdnz 0x821121e8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821121E8;
loc_82112228:
	// lhz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + 2);
	// lhz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 12);
	// mulli r8,r10,7
	ctx.r8.s64 = ctx.r10.s64 * 7;
	// lhz r7,18(r11)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r11.u32 + 18);
	// subf r11,r8,r9
	ctx.r11.s64 = ctx.r9.s64 - ctx.r8.s64;
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// twllei r9,0
	// divw r11,r10,r9
	ctx.r11.s32 = ppc_divw(ctx.r10.s32, ctx.r9.s32);
	// rotlwi r10,r10,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// subf r11,r7,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r7.s64;
	// andc r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 & ~ctx.r10.u64;
	// addic r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// twlgei r10,-1
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// subfic r10,r7,0
	ctx.xer.ca = ctx.r7.u32 <= 0;
	ctx.r10.s64 = 0 - ctx.r7.s64;
	// and r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 & ctx.r3.u64;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 & ctx.r11.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82112280"))) PPC_WEAK_FUNC(sub_82112280);
PPC_FUNC_IMPL(__imp__sub_82112280) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
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
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x821120d0
	ctx.lr = 0x8211229C;
	sub_821120D0(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x821122c8
	if (ctx.cr6.eq) goto loc_821122C8;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x821120d0
	ctx.lr = 0x821122B0;
	sub_821120D0(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x821122c8
	if (ctx.cr6.eq) goto loc_821122C8;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821122e4
	goto loc_821122E4;
loc_821122C8:
	// lhz r11,14(r5)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r5.u32 + 14);
	// li r10,128
	ctx.r10.s64 = 128;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// addi r11,r11,-8
	ctx.r11.s64 = ctx.r11.s64 + -8;
	// addic r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 & ctx.r10.u64;
loc_821122E4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207da20
	ctx.lr = 0x821122EC;
	sub_8207DA20(ctx, base);
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

__attribute__((alias("__imp__sub_82112300"))) PPC_WEAK_FUNC(sub_82112300);
PPC_FUNC_IMPL(__imp__sub_82112300) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82112308;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,357
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 357, ctx.xer);
	// bne cr6,0x82112324
	if (!ctx.cr6.eq) goto loc_82112324;
	// li r29,32
	ctx.r29.s64 = 32;
	// b 0x8211233c
	goto loc_8211233C;
loc_82112324:
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x82112334
	if (!ctx.cr6.eq) goto loc_82112334;
	// li r29,16
	ctx.r29.s64 = 16;
	// b 0x8211233c
	goto loc_8211233C;
loc_82112334:
	// lhz r11,16(r28)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r28.u32 + 16);
	// addi r29,r11,18
	ctx.r29.s64 = ctx.r11.s64 + 18;
loc_8211233C:
	// cmplwi cr6,r10,357
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 357, ctx.xer);
	// bne cr6,0x8211234c
	if (!ctx.cr6.eq) goto loc_8211234C;
	// li r30,32
	ctx.r30.s64 = 32;
	// b 0x82112364
	goto loc_82112364;
loc_8211234C:
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x8211235c
	if (!ctx.cr6.eq) goto loc_8211235C;
	// li r30,18
	ctx.r30.s64 = 18;
	// b 0x82112364
	goto loc_82112364;
loc_8211235C:
	// lhz r11,16(r28)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r28.u32 + 16);
	// addi r30,r11,18
	ctx.r30.s64 = ctx.r11.s64 + 18;
loc_82112364:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,-5536
	ctx.r3.s64 = ctx.r11.s64 + -5536;
	// ori r5,r5,6
	ctx.r5.u64 = ctx.r5.u64 | 6;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82108aa8
	ctx.lr = 0x82112380;
	sub_82108AA8(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x821123a8
	if (ctx.cr0.eq) goto loc_821123A8;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207dac0
	ctx.lr = 0x82112398;
	sub_8207DAC0(ctx, base);
	// subf r5,r29,r30
	ctx.r5.s64 = ctx.r30.s64 - ctx.r29.s64;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r3,r31,r29
	ctx.r3.u64 = ctx.r31.u64 + ctx.r29.u64;
	// bl 0x8207da20
	ctx.lr = 0x821123A8;
	sub_8207DA20(ctx, base);
loc_821123A8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821123B4"))) PPC_WEAK_FUNC(sub_821123B4);
PPC_FUNC_IMPL(__imp__sub_821123B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821123B8"))) PPC_WEAK_FUNC(sub_821123B8);
PPC_FUNC_IMPL(__imp__sub_821123B8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lhz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r10,357
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 357, ctx.xer);
	// bne cr6,0x821123fc
	if (!ctx.cr6.eq) goto loc_821123FC;
	// lhz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + 8);
	// cmpwi r10,0
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// blelr 
	if (!ctx.cr0.gt) return;
	// addi r9,r11,10
	ctx.r9.s64 = ctx.r11.s64 + 10;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_821123E0:
	// lhzu r11,20(r9)
	ea = 20 + ctx.r9.u32;
	ctx.r11.u64 = PPC_LOAD_U16(ea);
	ctx.r9.u32 = ea;
	// clrlwi r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	// rlwinm r11,r11,24,8,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 24) & 0xFFFFFF;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// or r3,r11,r3
	ctx.r3.u64 = ctx.r11.u64 | ctx.r3.u64;
	// bdnz 0x821123e0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821123E0;
	// blr 
	return;
loc_821123FC:
	// cmplwi cr6,r10,358
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 358, ctx.xer);
	// beq cr6,0x8211240c
	if (ctx.cr6.eq) goto loc_8211240C;
	// cmplwi cr6,r10,65534
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 65534, ctx.xer);
	// bne cr6,0x82112414
	if (!ctx.cr6.eq) goto loc_82112414;
loc_8211240C:
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// blr 
	return;
loc_82112414:
	// lhz r11,2(r11)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r11.u32 + 2);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x82112428
	if (!ctx.cr6.eq) goto loc_82112428;
	// li r3,4
	ctx.r3.s64 = 4;
	// blr 
	return;
loc_82112428:
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x82112438
	if (!ctx.cr6.eq) goto loc_82112438;
	// li r3,3
	ctx.r3.s64 = 3;
	// blr 
	return;
loc_82112438:
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bltlr cr6
	if (ctx.cr6.lt) return;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bgtlr cr6
	if (ctx.cr6.gt) return;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,14480
	ctx.r10.s64 = ctx.r10.s64 + 14480;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r3,-4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -4);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82112464"))) PPC_WEAK_FUNC(sub_82112464);
PPC_FUNC_IMPL(__imp__sub_82112464) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82112468"))) PPC_WEAK_FUNC(sub_82112468);
PPC_FUNC_IMPL(__imp__sub_82112468) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lhz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 16);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// cmplwi cr6,r10,32
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 32, ctx.xer);
	// bge cr6,0x82112484
	if (!ctx.cr6.lt) goto loc_82112484;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82112484:
	// lhz r9,2(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 2);
	// lbz r8,11(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 11);
	// addi r9,r9,-16
	ctx.r9.s64 = ctx.r9.s64 + -16;
	// lhz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + 8);
	// addi r8,r8,-2
	ctx.r8.s64 = ctx.r8.s64 + -2;
	// lwz r6,16(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// addic r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// subfe r9,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// addic r8,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// and r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 & ctx.r7.u64;
	// subfe r8,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r8.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// subfic r7,r10,0
	ctx.xer.ca = ctx.r10.u32 <= 0;
	ctx.r7.s64 = 0 - ctx.r10.s64;
	// and r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 & ctx.r9.u64;
	// subfe r8,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r7.u64 + ctx.r7.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// subfic r7,r6,0
	ctx.xer.ca = ctx.r6.u32 <= 0;
	ctx.r7.s64 = 0 - ctx.r6.s64;
	// and r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 & ctx.r9.u64;
	// subfe r8,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r7.u64 + ctx.r7.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r3,r8,r9
	ctx.r3.u64 = ctx.r8.u64 & ctx.r9.u64;
	// blelr cr6
	if (!ctx.cr6.gt) return;
	// addi r9,r11,28
	ctx.r9.s64 = ctx.r11.s64 + 28;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_821124DC:
	// lwz r11,-12(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12);
	// lbz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// subf r8,r11,r6
	ctx.r8.s64 = ctx.r6.s64 - ctx.r11.s64;
	// lbz r11,1(r9)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 1);
	// clrlwi r7,r10,28
	ctx.r7.u64 = ctx.r10.u32 & 0xF;
	// addic r8,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// rlwinm r10,r10,0,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF0;
	// subfe r8,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r8.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// subfic r5,r7,4
	ctx.xer.ca = ctx.r7.u32 <= 4;
	ctx.r5.s64 = 4 - ctx.r7.s64;
	// and r8,r8,r3
	ctx.r8.u64 = ctx.r8.u64 & ctx.r3.u64;
	// addze r4,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r4.s64 = temp.s64;
	// subfic r3,r10,48
	ctx.xer.ca = ctx.r10.u32 <= 48;
	ctx.r3.s64 = 48 - ctx.r10.s64;
	// subf r7,r4,r7
	ctx.r7.s64 = ctx.r7.s64 - ctx.r4.s64;
	// addze r5,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r5.s64 = temp.s64;
	// and r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 & ctx.r8.u64;
	// subf r10,r5,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r5.s64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// and r3,r10,r8
	ctx.r3.u64 = ctx.r10.u64 & ctx.r8.u64;
	// beq cr6,0x82112538
	if (ctx.cr6.eq) goto loc_82112538;
	// addi r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -2;
	// addic r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r3,r11,r3
	ctx.r3.u64 = ctx.r11.u64 & ctx.r3.u64;
loc_82112538:
	// lhz r11,2(r9)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 2);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82112588
	if (ctx.cr0.eq) goto loc_82112588;
	// clrlwi. r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r10,0
	ctx.r10.s64 = 0;
	// beq 0x82112570
	if (ctx.cr0.eq) goto loc_82112570;
loc_82112550:
	// addis r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 65536;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// and r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 & ctx.r11.u64;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// clrlwi. r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82112550
	if (!ctx.cr0.eq) goto loc_82112550;
loc_82112570:
	// lbz r11,1(r9)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 1);
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// addic r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r3,r11,r3
	ctx.r3.u64 = ctx.r11.u64 & ctx.r3.u64;
loc_82112588:
	// addi r9,r9,20
	ctx.r9.s64 = ctx.r9.s64 + 20;
	// bdnz 0x821124dc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821124DC;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82112594"))) PPC_WEAK_FUNC(sub_82112594);
PPC_FUNC_IMPL(__imp__sub_82112594) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82112598"))) PPC_WEAK_FUNC(sub_82112598);
PPC_FUNC_IMPL(__imp__sub_82112598) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x821125A0;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r27,0(r3)
	ctx.r27.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// bl 0x82112038
	ctx.lr = 0x821125BC;
	sub_82112038(ctx, base);
	// mr r8,r27
	ctx.r8.u64 = ctx.r27.u64;
	// cmplwi cr6,r27,65534
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 65534, ctx.xer);
	// beq cr6,0x82112638
	if (ctx.cr6.eq) goto loc_82112638;
	// li r11,-2
	ctx.r11.s64 = -2;
	// li r10,22
	ctx.r10.s64 = 22;
	// sth r11,0(r31)
	PPC_STORE_U16(ctx.r31.u32 + 0, ctx.r11.u16);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// sth r10,16(r31)
	PPC_STORE_U16(ctx.r31.u32 + 16, ctx.r10.u16);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lhz r11,14(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + 14);
	// sth r11,18(r31)
	PPC_STORE_U16(ctx.r31.u32 + 18, ctx.r11.u16);
	// bl 0x821123b8
	ctx.lr = 0x821125EC;
	sub_821123B8(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stw r3,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r3.u32);
	// addi r9,r11,24800
	ctx.r9.s64 = ctx.r11.s64 + 24800;
	// addi r3,r31,24
	ctx.r3.s64 = ctx.r31.s64 + 24;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,24800(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24800);
	// li r5,16
	ctx.r5.s64 = 16;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// lwz r11,12(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r7,4(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r9,8(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// stw r11,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r11.u32);
	// stw r7,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r7.u32);
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r27.u32);
	// bl 0x8207dac0
	ctx.lr = 0x82112630;
	sub_8207DAC0(ctx, base);
	// li r11,40
	ctx.r11.s64 = 40;
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
loc_82112638:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

