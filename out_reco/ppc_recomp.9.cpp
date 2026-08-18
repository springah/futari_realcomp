#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_880BABF8"))) PPC_WEAK_FUNC(sub_880BABF8);
PPC_FUNC_IMPL(__imp__sub_880BABF8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071140
	ctx.lr = 0x880BAC00;
	__savegprlr_22(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x880bae20
	if (ctx.cr6.lt) goto loc_880BAE20;
	// beq cr6,0x880bacf0
	if (ctx.cr6.eq) goto loc_880BACF0;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x880bae8c
	if (!ctx.cr6.lt) goto loc_880BAE8C;
	// lwz r11,112(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880bacb0
	if (ctx.cr6.eq) goto loc_880BACB0;
	// lwz r11,104(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// bge 0x880bae8c
	if (!ctx.cr0.lt) goto loc_880BAE8C;
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// addi r30,r31,20
	ctx.r30.s64 = ctx.r31.s64 + 20;
	// addi r28,r31,52
	ctx.r28.s64 = ctx.r31.s64 + 52;
	// li r29,4
	ctx.r29.s64 = 4;
	// stw r11,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
loc_880BAC54:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r10,160(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 160);
	// li r3,214
	ctx.r3.s64 = 214;
	// lwzu r9,4(r28)
	ea = 4 + ctx.r28.u32;
	ctx.r9.u64 = PPC_LOAD_U32(ea);
	ctx.r28.u32 = ea;
	// lwz r8,124(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// stw r9,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// stw r8,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r8.u32);
	// lwzu r5,8(r30)
	ea = 8 + ctx.r30.u32;
	ctx.r5.u64 = PPC_LOAD_U32(ea);
	ctx.r30.u32 = ea;
	// bl 0x880958a0
	ctx.lr = 0x880BAC88;
	sub_880958A0(ctx, base);
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne 0x880bac54
	if (!ctx.cr0.eq) goto loc_880BAC54;
	// lwz r11,112(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r11.u32);
	// bgt 0x880bae8c
	if (ctx.cr0.gt) goto loc_880BAE8C;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x88071190
	__restgprlr_22(ctx, base);
	return;
loc_880BACB0:
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
	// bge 0x880bae8c
	if (!ctx.cr0.lt) goto loc_880BAE8C;
	// lwz r10,116(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// lwz r9,100(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// addi r11,r10,1
	ctx.r11.s64 = ctx.r10.s64 + 1;
	// stw r11,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r11.u32);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// stw r10,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r10.u32);
	// stw r9,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r9.u32);
	// blt cr6,0x880bae8c
	if (ctx.cr6.lt) goto loc_880BAE8C;
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r11,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r11.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x88071190
	__restgprlr_22(ctx, base);
	return;
loc_880BACF0:
	// lwz r11,188(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 188);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880badf0
	if (ctx.cr6.eq) goto loc_880BADF0;
	// lwz r11,180(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 180);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,180(r31)
	PPC_STORE_U32(ctx.r31.u32 + 180, ctx.r11.u32);
	// bge 0x880bae8c
	if (!ctx.cr0.lt) goto loc_880BAE8C;
	// lwz r11,184(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// addi r28,r31,204
	ctx.r28.s64 = ctx.r31.s64 + 204;
	// addi r27,r31,28
	ctx.r27.s64 = ctx.r31.s64 + 28;
	// li r23,4
	ctx.r23.s64 = 4;
	// lis r25,-30643
	ctx.r25.s64 = -2008219648;
	// li r24,0
	ctx.r24.s64 = 0;
	// stw r11,180(r31)
	PPC_STORE_U32(ctx.r31.u32 + 180, ctx.r11.u32);
	// li r22,-1
	ctx.r22.s64 = -1;
loc_880BAD2C:
	// lwz r30,-4(r27)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r27.u32 + -4);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r29,0(r27)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x88095590
	ctx.lr = 0x880BAD44;
	sub_88095590(ctx, base);
	// lwz r11,188(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 188);
	// lwz r10,192(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 192);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x880bad58
	if (!ctx.cr6.eq) goto loc_880BAD58;
	// stw r3,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r3.u32);
loc_880BAD58:
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// bl 0x88153010
	ctx.lr = 0x880BAD64;
	sub_88153010(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// lwz r10,26276(r25)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r25.u32 + 26276);
	// stw r11,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
	// lwz r9,196(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 196);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x880badb4
	if (!ctx.cr6.eq) goto loc_880BADB4;
	// clrlwi r7,r11,16
	ctx.r7.u64 = ctx.r11.u32 & 0xFFFF;
	// stw r26,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r26.u32);
	// extsh r6,r9
	ctx.r6.s64 = ctx.r9.s16;
	// sth r24,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r24.u16);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,55
	ctx.r3.s64 = 55;
	// bl 0x8815c948
	ctx.lr = 0x880BAD9C;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x8815c860
	ctx.lr = 0x880BADA8;
	sub_8815C860(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x880badb4
	if (ctx.cr6.eq) goto loc_880BADB4;
	// sth r22,16(r30)
	PPC_STORE_U16(ctx.r30.u32 + 16, ctx.r22.u16);
loc_880BADB4:
	// addic. r23,r23,-1
	ctx.xer.ca = ctx.r23.u32 > 0;
	ctx.r23.s64 = ctx.r23.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// addi r27,r27,8
	ctx.r27.s64 = ctx.r27.s64 + 8;
	// bne 0x880bad2c
	if (!ctx.cr0.eq) goto loc_880BAD2C;
	// lwz r11,196(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 196);
	// lwz r10,188(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 188);
	// addi r9,r11,2
	ctx.r9.s64 = ctx.r11.s64 + 2;
	// addic. r11,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r11.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r9,196(r31)
	PPC_STORE_U32(ctx.r31.u32 + 196, ctx.r9.u32);
	// stw r11,188(r31)
	PPC_STORE_U32(ctx.r31.u32 + 188, ctx.r11.u32);
	// bgt 0x880bae8c
	if (ctx.cr0.gt) goto loc_880BAE8C;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x88071190
	__restgprlr_22(ctx, base);
	return;
loc_880BADF0:
	// lwz r11,172(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 172);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,172(r31)
	PPC_STORE_U32(ctx.r31.u32 + 172, ctx.r11.u32);
	// bge 0x880bae8c
	if (!ctx.cr0.lt) goto loc_880BAE8C;
	// lwz r11,176(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 176);
	// lwz r10,192(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 192);
	// lwz r9,200(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 200);
	// stw r11,172(r31)
	PPC_STORE_U32(ctx.r31.u32 + 172, ctx.r11.u32);
	// stw r10,188(r31)
	PPC_STORE_U32(ctx.r31.u32 + 188, ctx.r10.u32);
	// stw r9,196(r31)
	PPC_STORE_U32(ctx.r31.u32 + 196, ctx.r9.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x88071190
	__restgprlr_22(ctx, base);
	return;
loc_880BAE20:
	// lwz r11,136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 136);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r11.u32);
	// bge 0x880bae84
	if (!ctx.cr0.lt) goto loc_880BAE84;
	// lwz r11,284(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 284);
	// lwz r10,140(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// lwz r11,164(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 164);
	// addi r11,r11,3
	ctx.r11.s64 = ctx.r11.s64 + 3;
	// stw r9,284(r31)
	PPC_STORE_U32(ctx.r31.u32 + 284, ctx.r9.u32);
	// stw r10,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r10.u32);
	// cmpwi cr6,r11,128
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 128, ctx.xer);
	// stw r11,164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 164, ctx.r11.u32);
	// blt cr6,0x880bae60
	if (ctx.cr6.lt) goto loc_880BAE60;
	// li r11,128
	ctx.r11.s64 = 128;
	// stw r11,164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 164, ctx.r11.u32);
loc_880BAE60:
	// lwz r11,124(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r11.u32);
	// cmpwi cr6,r11,47
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 47, ctx.xer);
	// blt cr6,0x880bae84
	if (ctx.cr6.lt) goto loc_880BAE84;
	// li r11,47
	ctx.r11.s64 = 47;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r11.u32);
	// stw r10,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r10.u32);
loc_880BAE84:
	// li r11,64
	ctx.r11.s64 = 64;
	// stw r11,248(r31)
	PPC_STORE_U32(ctx.r31.u32 + 248, ctx.r11.u32);
loc_880BAE8C:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x88071190
	__restgprlr_22(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880BAE94"))) PPC_WEAK_FUNC(sub_880BAE94);
PPC_FUNC_IMPL(__imp__sub_880BAE94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BAE98"))) PPC_WEAK_FUNC(sub_880BAE98);
PPC_FUNC_IMPL(__imp__sub_880BAE98) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071144
	ctx.lr = 0x880BAEA0;
	__savegprlr_23(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x880bb078
	if (ctx.cr6.lt) goto loc_880BB078;
	// beq cr6,0x880bb068
	if (ctx.cr6.eq) goto loc_880BB068;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x880bb0ec
	if (!ctx.cr6.lt) goto loc_880BB0EC;
	// lwz r11,112(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880bafd8
	if (ctx.cr6.eq) goto loc_880BAFD8;
	// lwz r11,104(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// bge 0x880bb0ec
	if (!ctx.cr0.lt) goto loc_880BB0EC;
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// addi r27,r31,56
	ctx.r27.s64 = ctx.r31.s64 + 56;
	// addi r30,r31,28
	ctx.r30.s64 = ctx.r31.s64 + 28;
	// li r26,4
	ctx.r26.s64 = 4;
	// li r25,0
	ctx.r25.s64 = 0;
	// li r23,2
	ctx.r23.s64 = 2;
	// stw r11,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
loc_880BAEFC:
	// lwz r29,-4(r30)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r30.u32 + -4);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// lwz r28,0(r30)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x88095590
	ctx.lr = 0x880BAF14;
	sub_88095590(ctx, base);
	// lwz r11,168(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 168);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// clrlwi r9,r11,31
	ctx.r9.u64 = ctx.r11.u32 & 0x1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// beq cr6,0x880baf48
	if (ctx.cr6.eq) goto loc_880BAF48;
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r10,160(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 160);
	// stw r25,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r25.u32);
	// stw r23,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r23.u32);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// b 0x880baf64
	goto loc_880BAF64;
loc_880BAF48:
	// lwz r11,160(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 160);
	// lwz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// addi r9,r11,16
	ctx.r9.s64 = ctx.r11.s64 + 16;
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// stw r25,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r25.u32);
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// stw r10,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
loc_880BAF64:
	// lwz r11,124(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,214
	ctx.r3.s64 = 214;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
	// bl 0x880958a0
	ctx.lr = 0x880BAF80;
	sub_880958A0(ctx, base);
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// addi r27,r27,4
	ctx.r27.s64 = ctx.r27.s64 + 4;
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// bne 0x880baefc
	if (!ctx.cr0.eq) goto loc_880BAEFC;
	// lwz r11,112(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r11.u32);
	// bgt 0x880bb0ec
	if (ctx.cr0.gt) goto loc_880BB0EC;
	// lwz r11,168(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 168);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r10,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r10.u32);
	// stw r11,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r11.u32);
	// cmpwi cr6,r11,32
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 32, ctx.xer);
	// blt cr6,0x880bafc8
	if (ctx.cr6.lt) goto loc_880BAFC8;
	// li r11,32
	ctx.r11.s64 = 32;
	// stw r11,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r11.u32);
loc_880BAFC8:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
loc_880BAFD8:
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
	// bge 0x880bb0ec
	if (!ctx.cr0.lt) goto loc_880BB0EC;
	// li r3,8
	ctx.r3.s64 = 8;
	// lwz r30,100(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// bl 0x881534c8
	ctx.lr = 0x880BAFF4;
	sub_881534C8(ctx, base);
	// lwz r9,168(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 168);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r10,8
	ctx.r10.s64 = 8;
	// add r8,r11,r30
	ctx.r8.u64 = ctx.r11.u64 + ctx.r30.u64;
	// li r7,3
	ctx.r7.s64 = 3;
	// stw r10,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r10.u32);
	// clrlwi r6,r9,31
	ctx.r6.u64 = ctx.r9.u32 & 0x1;
	// stw r8,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r8.u32);
	// stw r7,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r7.u32);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq cr6,0x880bb02c
	if (ctx.cr6.eq) goto loc_880BB02C;
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r10,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r10.u32);
	// stw r11,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
loc_880BB02C:
	// addi r11,r30,-8
	ctx.r11.s64 = ctx.r30.s64 + -8;
	// stw r11,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// bgt cr6,0x880bb044
	if (ctx.cr6.gt) goto loc_880BB044;
	// li r11,16
	ctx.r11.s64 = 16;
	// stw r11,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
loc_880BB044:
	// lwz r11,160(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 160);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r11,160(r31)
	PPC_STORE_U32(ctx.r31.u32 + 160, ctx.r11.u32);
	// cmpwi cr6,r11,48
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 48, ctx.xer);
	// blt cr6,0x880bb0ec
	if (ctx.cr6.lt) goto loc_880BB0EC;
	// li r11,48
	ctx.r11.s64 = 48;
	// stw r11,160(r31)
	PPC_STORE_U32(ctx.r31.u32 + 160, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
loc_880BB068:
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
loc_880BB078:
	// lwz r11,136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 136);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r11.u32);
	// bge 0x880bb0dc
	if (!ctx.cr0.lt) goto loc_880BB0DC;
	// lwz r11,284(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 284);
	// lwz r10,140(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// lwz r11,164(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 164);
	// addi r11,r11,3
	ctx.r11.s64 = ctx.r11.s64 + 3;
	// stw r9,284(r31)
	PPC_STORE_U32(ctx.r31.u32 + 284, ctx.r9.u32);
	// stw r10,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r10.u32);
	// cmpwi cr6,r11,128
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 128, ctx.xer);
	// stw r11,164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 164, ctx.r11.u32);
	// blt cr6,0x880bb0b8
	if (ctx.cr6.lt) goto loc_880BB0B8;
	// li r11,128
	ctx.r11.s64 = 128;
	// stw r11,164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 164, ctx.r11.u32);
loc_880BB0B8:
	// lwz r11,124(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r11.u32);
	// cmpwi cr6,r11,47
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 47, ctx.xer);
	// blt cr6,0x880bb0dc
	if (ctx.cr6.lt) goto loc_880BB0DC;
	// li r11,47
	ctx.r11.s64 = 47;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r11.u32);
	// stw r10,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r10.u32);
loc_880BB0DC:
	// li r11,16
	ctx.r11.s64 = 16;
	// li r10,32
	ctx.r10.s64 = 32;
	// stw r11,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r11.u32);
	// stw r10,248(r31)
	PPC_STORE_U32(ctx.r31.u32 + 248, ctx.r10.u32);
loc_880BB0EC:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880BB0F4"))) PPC_WEAK_FUNC(sub_880BB0F4);
PPC_FUNC_IMPL(__imp__sub_880BB0F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BB0F8"))) PPC_WEAK_FUNC(sub_880BB0F8);
PPC_FUNC_IMPL(__imp__sub_880BB0F8) {
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
	// lwz r3,2304(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,15492(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15492);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880bb140
	if (ctx.cr6.eq) goto loc_880BB140;
	// bl 0x880ba950
	ctx.lr = 0x880BB124;
	sub_880BA950(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88094220
	ctx.lr = 0x880BB12C;
	sub_88094220(ctx, base);
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
loc_880BB140:
	// lwz r10,72(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// lis r6,32
	ctx.r6.s64 = 2097152;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r10,288(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 288);
	// beq cr6,0x880bb168
	if (ctx.cr6.eq) goto loc_880BB168;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r10,288(r3)
	PPC_STORE_U32(ctx.r3.u32 + 288, ctx.r10.u32);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// addis r8,r9,72
	ctx.r8.s64 = ctx.r9.s64 + 4718592;
	// b 0x880bb178
	goto loc_880BB178;
loc_880BB168:
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// stw r10,288(r3)
	PPC_STORE_U32(ctx.r3.u32 + 288, ctx.r10.u32);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// addis r8,r9,-72
	ctx.r8.s64 = ctx.r9.s64 + -4718592;
loc_880BB178:
	// stw r8,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r8.u32);
	// rotlwi r8,r8,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// add r11,r7,r6
	ctx.r11.u64 = ctx.r7.u64 + ctx.r6.u64;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// lis r7,16
	ctx.r7.s64 = 1048576;
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rlwinm r9,r10,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// add. r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// and r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 & ctx.r10.u64;
	// ble 0x880bb1f4
	if (!ctx.cr0.gt) goto loc_880BB1F4;
	// lis r9,320
	ctx.r9.s64 = 20971520;
	// subf r5,r6,r11
	ctx.r5.s64 = ctx.r11.s64 - ctx.r6.s64;
	// cmpw cr6,r5,r9
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x880bb1f4
	if (!ctx.cr6.lt) goto loc_880BB1F4;
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addi r10,r10,55
	ctx.r10.s64 = ctx.r10.s64 + 55;
	// lis r9,-40
	ctx.r9.s64 = -2621440;
	// rlwinm r5,r10,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-11984(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11984);
	// lwzx r11,r5,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r11.u32);
	// add r4,r11,r8
	ctx.r4.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r11,r4,r7
	ctx.r11.u64 = ctx.r4.u64 + ctx.r7.u64;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// ble cr6,0x880bb1f4
	if (!ctx.cr6.gt) goto loc_880BB1F4;
	// lis r10,280
	ctx.r10.s64 = 18350080;
	// subf r9,r6,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r6.s64;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x880bb228
	if (ctx.cr6.lt) goto loc_880BB228;
loc_880BB1F4:
	// lwz r11,360(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 360);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880bb230
	if (ctx.cr6.eq) goto loc_880BB230;
	// lwz r11,372(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 372);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x88094220
	ctx.lr = 0x880BB214;
	sub_88094220(ctx, base);
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
loc_880BB228:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,360(r3)
	PPC_STORE_U32(ctx.r3.u32 + 360, ctx.r11.u32);
loc_880BB230:
	// li r9,4
	ctx.r9.s64 = 4;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r7,r3,52
	ctx.r7.s64 = ctx.r3.s64 + 52;
	// addi r10,r3,20
	ctx.r10.s64 = ctx.r3.s64 + 20;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// lis r9,-30714
	ctx.r9.s64 = -2012872704;
	// addi r6,r9,9552
	ctx.r6.s64 = ctx.r9.s64 + 9552;
loc_880BB24C:
	// lwz r8,288(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 288);
	// lwz r9,284(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 284);
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lwz r4,16(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r31,r9,1,0,30
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r5,20(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// clrlwi r8,r8,23
	ctx.r8.u64 = ctx.r8.u32 & 0x1FF;
	// add r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 + ctx.r31.u64;
	// addi r31,r8,128
	ctx.r31.s64 = ctx.r8.s64 + 128;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r31,r31,2,21,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0x7FC;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lwzx r8,r8,r6
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r6.u32);
	// lwzx r31,r31,r6
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r6.u32);
	// mullw r8,r8,r9
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// mullw r31,r31,r9
	ctx.r31.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r9.s32);
	// rlwinm r9,r8,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r31,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r9,r4
	ctx.r9.u64 = ctx.r9.u64 + ctx.r4.u64;
	// add r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 + ctx.r5.u64;
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// stwu r8,8(r10)
	ea = 8 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r10.u32 = ea;
	// lwz r9,288(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 288);
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// stwu r9,4(r7)
	ea = 4 + ctx.r7.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r7.u32 = ea;
	// bdnz 0x880bb24c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_880BB24C;
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

__attribute__((alias("__imp__sub_880BB2CC"))) PPC_WEAK_FUNC(sub_880BB2CC);
PPC_FUNC_IMPL(__imp__sub_880BB2CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BB2D0"))) PPC_WEAK_FUNC(sub_880BB2D0);
PPC_FUNC_IMPL(__imp__sub_880BB2D0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880BB2D8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30708
	ctx.r11.s64 = -2012479488;
	// li r4,376
	ctx.r4.s64 = 376;
	// addi r5,r11,-19760
	ctx.r5.s64 = ctx.r11.s64 + -19760;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x880BB2F0;
	sub_88094290(ctx, base);
	// li r5,376
	ctx.r5.s64 = 376;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,2304(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2304);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x880BB304;
	sub_88073BD0(ctx, base);
	// stw r30,344(r31)
	PPC_STORE_U32(ctx.r31.u32 + 344, ctx.r30.u32);
	// addi r10,r30,120
	ctx.r10.s64 = ctx.r30.s64 + 120;
	// lis r3,-30597
	ctx.r3.s64 = -2005204992;
	// li r5,130
	ctx.r5.s64 = 130;
	// li r4,256
	ctx.r4.s64 = 256;
	// li r8,32
	ctx.r8.s64 = 32;
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r7,-11984(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + -11984);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r9,3
	ctx.r9.s64 = 3;
	// li r29,-12
	ctx.r29.s64 = -12;
	// lwz r10,32(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// stw r10,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r10.u32);
	// lwz r3,36(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// stw r3,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r3.u32);
	// stw r5,168(r30)
	PPC_STORE_U32(ctx.r30.u32 + 168, ctx.r5.u32);
	// stw r4,300(r31)
	PPC_STORE_U32(ctx.r31.u32 + 300, ctx.r4.u32);
	// stw r8,292(r31)
	PPC_STORE_U32(ctx.r31.u32 + 292, ctx.r8.u32);
	// lwz r10,132(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 132);
	// lwz r5,2304(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2304);
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// stw r5,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r5.u32);
	// lwz r3,132(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 132);
	// addis r10,r4,-8
	ctx.r10.s64 = ctx.r4.s64 + -524288;
	// stw r3,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// stw r11,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r11.u32);
	// lwz r5,136(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 136);
	// stw r5,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r5.u32);
	// stw r10,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// stw r29,324(r31)
	PPC_STORE_U32(ctx.r31.u32 + 324, ctx.r29.u32);
	// stw r11,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r11.u32);
	// stw r11,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r11.u32);
	// stw r6,144(r31)
	PPC_STORE_U32(ctx.r31.u32 + 144, ctx.r6.u32);
	// stw r6,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r6.u32);
	// stw r9,152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 152, ctx.r9.u32);
	// stw r9,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r9.u32);
	// lwz r10,84(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 84);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// stw r10,368(r31)
	PPC_STORE_U32(ctx.r31.u32 + 368, ctx.r10.u32);
	// blt cr6,0x880bb43c
	if (ctx.cr6.lt) goto loc_880BB43C;
	// beq cr6,0x880bb3e4
	if (ctx.cr6.eq) goto loc_880BB3E4;
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// bge cr6,0x880bb470
	if (!ctx.cr6.lt) goto loc_880BB470;
	// lis r10,-30708
	ctx.r10.s64 = -2012479488;
	// stw r11,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// li r7,64
	ctx.r7.s64 = 64;
	// stw r9,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r9.u32);
	// li r6,96
	ctx.r6.s64 = 96;
	// stw r8,160(r31)
	PPC_STORE_U32(ctx.r31.u32 + 160, ctx.r8.u32);
	// li r5,16
	ctx.r5.s64 = 16;
	// stw r7,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r7.u32);
	// addi r4,r10,-21888
	ctx.r4.s64 = ctx.r10.s64 + -21888;
	// stw r6,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r6.u32);
	// stw r5,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r5.u32);
	// stw r4,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r4.u32);
	// b 0x880bb470
	goto loc_880BB470;
loc_880BB3E4:
	// lis r5,-30708
	ctx.r5.s64 = -2012479488;
	// stw r9,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r9.u32);
	// li r10,64
	ctx.r10.s64 = 64;
	// stw r11,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// li r6,2
	ctx.r6.s64 = 2;
	// stw r8,160(r31)
	PPC_STORE_U32(ctx.r31.u32 + 160, ctx.r8.u32);
	// li r7,-8
	ctx.r7.s64 = -8;
	// stw r10,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r10.u32);
	// li r4,128
	ctx.r4.s64 = 128;
	// stw r10,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r10.u32);
	// li r3,20
	ctx.r3.s64 = 20;
	// stw r6,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r6.u32);
	// addi r9,r5,-21512
	ctx.r9.s64 = ctx.r5.s64 + -21512;
	// stw r10,172(r31)
	PPC_STORE_U32(ctx.r31.u32 + 172, ctx.r10.u32);
	// stw r4,176(r31)
	PPC_STORE_U32(ctx.r31.u32 + 176, ctx.r4.u32);
	// stw r11,180(r31)
	PPC_STORE_U32(ctx.r31.u32 + 180, ctx.r11.u32);
	// stw r6,184(r31)
	PPC_STORE_U32(ctx.r31.u32 + 184, ctx.r6.u32);
	// stw r3,192(r31)
	PPC_STORE_U32(ctx.r31.u32 + 192, ctx.r3.u32);
	// stw r7,196(r31)
	PPC_STORE_U32(ctx.r31.u32 + 196, ctx.r7.u32);
	// stw r7,200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 200, ctx.r7.u32);
	// stw r9,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r9.u32);
	// b 0x880bb470
	goto loc_880BB470;
loc_880BB43C:
	// lis r10,-30708
	ctx.r10.s64 = -2012479488;
	// stw r8,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r8.u32);
	// li r9,16
	ctx.r9.s64 = 16;
	// stw r11,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// li r7,8
	ctx.r7.s64 = 8;
	// stw r8,160(r31)
	PPC_STORE_U32(ctx.r31.u32 + 160, ctx.r8.u32);
	// li r6,4
	ctx.r6.s64 = 4;
	// stw r9,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r9.u32);
	// addi r5,r10,-20840
	ctx.r5.s64 = ctx.r10.s64 + -20840;
	// stw r7,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r7.u32);
	// stw r6,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r6.u32);
	// stw r11,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r11.u32);
	// stw r5,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r5.u32);
loc_880BB470:
	// lis r11,-30708
	ctx.r11.s64 = -2012479488;
	// lis r10,-30708
	ctx.r10.s64 = -2012479488;
	// lis r9,-30708
	ctx.r9.s64 = -2012479488;
	// addi r8,r11,-20232
	ctx.r8.s64 = ctx.r11.s64 + -20232;
	// addi r7,r10,-22512
	ctx.r7.s64 = ctx.r10.s64 + -22512;
	// addi r6,r9,-22520
	ctx.r6.s64 = ctx.r9.s64 + -22520;
	// stw r8,64(r30)
	PPC_STORE_U32(ctx.r30.u32 + 64, ctx.r8.u32);
	// stw r7,68(r30)
	PPC_STORE_U32(ctx.r30.u32 + 68, ctx.r7.u32);
	// stw r6,84(r30)
	PPC_STORE_U32(ctx.r30.u32 + 84, ctx.r6.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880BB49C"))) PPC_WEAK_FUNC(sub_880BB49C);
PPC_FUNC_IMPL(__imp__sub_880BB49C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BB4A0"))) PPC_WEAK_FUNC(sub_880BB4A0);
PPC_FUNC_IMPL(__imp__sub_880BB4A0) {
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
	// lwz r10,7688(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 7688);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880bb4e4
	if (ctx.cr6.eq) goto loc_880BB4E4;
	// lwz r11,12(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lis r10,480
	ctx.r10.s64 = 31457280;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x880bb4e4
	if (!ctx.cr6.gt) goto loc_880BB4E4;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x880bbe60
	ctx.lr = 0x880BB4DC;
	sub_880BBE60(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88094220
	ctx.lr = 0x880BB4E4;
	sub_88094220(ctx, base);
loc_880BB4E4:
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

__attribute__((alias("__imp__sub_880BB4F8"))) PPC_WEAK_FUNC(sub_880BB4F8);
PPC_FUNC_IMPL(__imp__sub_880BB4F8) {
	PPC_FUNC_PROLOGUE();
	// lwz r8,2304(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r10,r11,576
	ctx.r10.s64 = ctx.r11.s64 + 576;
	// lwz r9,7332(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 7332);
	// lwz r11,-104(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -104);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x880bb534
	if (ctx.cr6.eq) goto loc_880BB534;
	// cmpwi cr6,r11,3000
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3000, ctx.xer);
	// bge cr6,0x880bb534
	if (!ctx.cr6.lt) goto loc_880BB534;
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r7,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r7.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-104(r10)
	PPC_STORE_U32(ctx.r10.u32 + -104, ctx.r11.u32);
	// stwx r9,r6,r10
	PPC_STORE_U32(ctx.r6.u32 + ctx.r10.u32, ctx.r9.u32);
loc_880BB534:
	// lwz r9,7476(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 7476);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// cmpwi cr6,r11,3000
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3000, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r7,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r7.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-104(r10)
	PPC_STORE_U32(ctx.r10.u32 + -104, ctx.r11.u32);
	// stwx r9,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880BB560"))) PPC_WEAK_FUNC(sub_880BB560);
PPC_FUNC_IMPL(__imp__sub_880BB560) {
	PPC_FUNC_PROLOGUE();
	// lwz r9,2304(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r11,7688(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 7688);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// beq cr6,0x880bb5b0
	if (ctx.cr6.eq) goto loc_880BB5B0;
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
	// li r6,96
	ctx.r6.s64 = 96;
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
loc_880BB5B0:
	// lwz r5,7700(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 7700);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne cr6,0x880bb5f4
	if (!ctx.cr6.eq) goto loc_880BB5F4;
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
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stwx r6,r11,r8
	PPC_STORE_U32(ctx.r11.u32 + ctx.r8.u32, ctx.r6.u32);
	// stwx r5,r11,r7
	PPC_STORE_U32(ctx.r11.u32 + ctx.r7.u32, ctx.r5.u32);
	// b 0x8815d040
	sub_8815D040(ctx, base);
	return;
loc_880BB5F4:
	// addi r11,r11,-11984
	ctx.r11.s64 = ctx.r11.s64 + -11984;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r10,84(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x880bb618
	if (!ctx.cr6.eq) goto loc_880BB618;
	// lwz r6,7712(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 7712);
	// li r3,176
	ctx.r3.s64 = 176;
	// lwz r4,7704(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 7704);
	// b 0x8815d688
	sub_8815D688(ctx, base);
	return;
loc_880BB618:
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
	// li r6,176
	ctx.r6.s64 = 176;
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

__attribute__((alias("__imp__sub_880BB650"))) PPC_WEAK_FUNC(sub_880BB650);
PPC_FUNC_IMPL(__imp__sub_880BB650) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880BB654"))) PPC_WEAK_FUNC(sub_880BB654);
PPC_FUNC_IMPL(__imp__sub_880BB654) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BB658"))) PPC_WEAK_FUNC(sub_880BB658);
PPC_FUNC_IMPL(__imp__sub_880BB658) {
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
	// li r30,1
	ctx.r30.s64 = 1;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r30,7632(r3)
	PPC_STORE_U32(ctx.r3.u32 + 7632, ctx.r30.u32);
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880bb688
	if (ctx.cr6.eq) goto loc_880BB688;
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
loc_880BB688:
	// stw r11,7700(r31)
	PPC_STORE_U32(ctx.r31.u32 + 7700, ctx.r11.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r11,7704(r31)
	PPC_STORE_U32(ctx.r31.u32 + 7704, ctx.r11.u32);
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880bb6a8
	if (ctx.cr6.eq) goto loc_880BB6A8;
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
loc_880BB6A8:
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880bb6b8
	if (ctx.cr6.eq) goto loc_880BB6B8;
	// lwz r11,164(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_880BB6B8:
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lis r8,-30682
	ctx.r8.s64 = -2010775552;
	// addi r7,r8,17728
	ctx.r7.s64 = ctx.r8.s64 + 17728;
	// stw r11,2328(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2328, ctx.r11.u32);
	// stw r10,2332(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2332, ctx.r10.u32);
	// lwz r6,32(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwzx r5,r5,r7
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r7.u32);
	// bl 0x88095178
	ctx.lr = 0x880BB6E0;
	sub_88095178(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r30,7628(r31)
	PPC_STORE_U32(ctx.r31.u32 + 7628, ctx.r30.u32);
	// stw r30,7448(r31)
	PPC_STORE_U32(ctx.r31.u32 + 7448, ctx.r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,7432(r31)
	PPC_STORE_U32(ctx.r31.u32 + 7432, ctx.r3.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x880bbe60
	ctx.lr = 0x880BB6FC;
	sub_880BBE60(ctx, base);
	// lwz r11,7700(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7700);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880bb748
	if (!ctx.cr6.eq) goto loc_880BB748;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lis r8,-30667
	ctx.r8.s64 = -2009792512;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r7,-30667
	ctx.r7.s64 = -2009792512;
	// lis r6,-30667
	ctx.r6.s64 = -2009792512;
	// lis r30,-30667
	ctx.r30.s64 = -2009792512;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,12364(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12364, ctx.r11.u32);
	// li r11,140
	ctx.r11.s64 = 140;
	// stw r10,12372(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12372, ctx.r10.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,140
	ctx.r4.s64 = 140;
	// stw r9,12380(r6)
	PPC_STORE_U32(ctx.r6.u32 + 12380, ctx.r9.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,12376(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12376, ctx.r11.u32);
	// bl 0x881607f8
	ctx.lr = 0x880BB748;
	sub_881607F8(ctx, base);
loc_880BB748:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x880bb560
	ctx.lr = 0x880BB750;
	sub_880BB560(ctx, base);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x88096e80
	ctx.lr = 0x880BB758;
	sub_88096E80(ctx, base);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x880967b8
	ctx.lr = 0x880BB760;
	sub_880967B8(ctx, base);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x88096ac0
	ctx.lr = 0x880BB768;
	sub_88096AC0(ctx, base);
	// lis r11,-30688
	ctx.r11.s64 = -2011168768;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-30448
	ctx.r4.s64 = ctx.r11.s64 + -30448;
	// bl 0x880969a8
	ctx.lr = 0x880BB77C;
	sub_880969A8(ctx, base);
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

__attribute__((alias("__imp__sub_880BB794"))) PPC_WEAK_FUNC(sub_880BB794);
PPC_FUNC_IMPL(__imp__sub_880BB794) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BB798"))) PPC_WEAK_FUNC(sub_880BB798);
PPC_FUNC_IMPL(__imp__sub_880BB798) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x880BB7A0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r11,-30642
	ctx.r11.s64 = -2008154112;
	// addi r28,r11,-32760
	ctx.r28.s64 = ctx.r11.s64 + -32760;
	// lwz r11,7628(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7628);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880bb934
	if (!ctx.cr6.eq) goto loc_880BB934;
	// lwz r9,7644(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7644);
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x880bb83c
	if (ctx.cr6.eq) goto loc_880BB83C;
	// lwz r10,7632(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7632);
	// li r29,1
	ctx.r29.s64 = 1;
	// addi r11,r31,7332
	ctx.r11.s64 = ctx.r31.s64 + 7332;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x880bb838
	if (!ctx.cr6.eq) goto loc_880BB838;
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 100);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x880bb838
	if (!ctx.cr6.gt) goto loc_880BB838;
	// lwz r8,7688(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7688);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x880bb804
	if (!ctx.cr6.eq) goto loc_880BB804;
	// subf r10,r9,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r9.s64;
	// stw r10,100(r11)
	PPC_STORE_U32(ctx.r11.u32 + 100, ctx.r10.u32);
loc_880BB804:
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 100);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bgt cr6,0x880bb838
	if (ctx.cr6.gt) goto loc_880BB838;
	// lwz r10,-6020(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + -6020);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x880bb828
	if (!ctx.cr6.eq) goto loc_880BB828;
	// li r10,512
	ctx.r10.s64 = 512;
	// stw r10,100(r11)
	PPC_STORE_U32(ctx.r11.u32 + 100, ctx.r10.u32);
	// b 0x880bb838
	goto loc_880BB838;
loc_880BB828:
	// stw r29,7640(r31)
	PPC_STORE_U32(ctx.r31.u32 + 7640, ctx.r29.u32);
	// addi r4,r31,7648
	ctx.r4.s64 = ctx.r31.s64 + 7648;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880bb658
	ctx.lr = 0x880BB838;
	sub_880BB658(ctx, base);
loc_880BB838:
	// stw r30,7644(r31)
	PPC_STORE_U32(ctx.r31.u32 + 7644, ctx.r30.u32);
loc_880BB83C:
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lis r10,128
	ctx.r10.s64 = 8388608;
	// lis r8,255
	ctx.r8.s64 = 16711680;
	// lis r5,192
	ctx.r5.s64 = 12582912;
	// addi r9,r31,7332
	ctx.r9.s64 = ctx.r31.s64 + 7332;
	// lwz r4,26428(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26428);
	// li r6,2
	ctx.r6.s64 = 2;
	// ori r7,r10,32896
	ctx.r7.u64 = ctx.r10.u64 | 32896;
	// ori r8,r8,4112
	ctx.r8.u64 = ctx.r8.u64 | 4112;
	// ori r5,r5,49152
	ctx.r5.u64 = ctx.r5.u64 | 49152;
loc_880BB864:
	// lwz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// stw r7,120(r9)
	PPC_STORE_U32(ctx.r9.u32 + 120, ctx.r7.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880bb89c
	if (ctx.cr6.eq) goto loc_880BB89C;
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880bb89c
	if (ctx.cr6.eq) goto loc_880BB89C;
loc_880BB884:
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
	// bne cr6,0x880bb884
	if (!ctx.cr6.eq) goto loc_880BB884;
loc_880BB89C:
	// clrlwi r11,r10,20
	ctx.r11.u64 = ctx.r10.u32 & 0xFFF;
	// rlwinm r11,r11,0,26,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFC3F;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880bb908
	if (!ctx.cr6.eq) goto loc_880BB908;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne cr6,0x880bb908
	if (!ctx.cr6.eq) goto loc_880BB908;
	// lwz r11,100(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 100);
	// lwz r10,108(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 108);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x880bb928
	if (!ctx.cr6.lt) goto loc_880BB928;
	// rlwinm r11,r4,0,28,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xE;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880bb928
	if (!ctx.cr6.eq) goto loc_880BB928;
	// lwz r11,136(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 136);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880bb8f4
	if (ctx.cr6.eq) goto loc_880BB8F4;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r11,r31,7308
	ctx.r11.s64 = ctx.r31.s64 + 7308;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_880BB8E8:
	// stwu r8,144(r11)
	ea = 144 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x880bb8e8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_880BB8E8;
	// b 0x880bb928
	goto loc_880BB928;
loc_880BB8F4:
	// lwz r11,116(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 116);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880bb928
	if (!ctx.cr6.eq) goto loc_880BB928;
	// stw r8,120(r9)
	PPC_STORE_U32(ctx.r9.u32 + 120, ctx.r8.u32);
	// b 0x880bb928
	goto loc_880BB928;
loc_880BB908:
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
	// beq cr6,0x880bb928
	if (ctx.cr6.eq) goto loc_880BB928;
	// stw r5,120(r9)
	PPC_STORE_U32(ctx.r9.u32 + 120, ctx.r5.u32);
loc_880BB928:
	// addic. r6,r6,-1
	ctx.xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// addi r9,r9,144
	ctx.r9.s64 = ctx.r9.s64 + 144;
	// bne 0x880bb864
	if (!ctx.cr0.eq) goto loc_880BB864;
loc_880BB934:
	// lwz r10,7432(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7432);
	// lwz r11,7680(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7680);
	// subfic r9,r10,0
	ctx.xer.ca = ctx.r10.u32 <= 0;
	ctx.r9.s64 = 0 - ctx.r10.s64;
	// rlwinm r8,r10,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// addme r7,r8
	{ uint8_t _ca = (ctx.r8.u32 + 0xFFFFFFFF < ctx.r8.u32) | (ctx.r8.u32 + 0xFFFFFFFF + ctx.xer.ca < ctx.xer.ca); // FIX 2026-07-24: insn was silently dropped by the recompiler
	ctx.r7.u64 = ctx.r8.u64 + 0xFFFFFFFFFFFFFFFFull + ctx.xer.ca;
	ctx.xer.ca = _ca; }
	// stw r11,40(r28)
	PPC_STORE_U32(ctx.r28.u32 + 40, ctx.r11.u32);
	// and r11,r7,r10
	ctx.r11.u64 = ctx.r7.u64 & ctx.r10.u64;
	// stw r11,72(r28)
	PPC_STORE_U32(ctx.r28.u32 + 72, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880BB95C"))) PPC_WEAK_FUNC(sub_880BB95C);
PPC_FUNC_IMPL(__imp__sub_880BB95C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BB960"))) PPC_WEAK_FUNC(sub_880BB960);
PPC_FUNC_IMPL(__imp__sub_880BB960) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x880BB968;
	__savegprlr_25(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30708
	ctx.r11.s64 = -2012479488;
	// li r4,7716
	ctx.r4.s64 = 7716;
	// addi r5,r11,-18080
	ctx.r5.s64 = ctx.r11.s64 + -18080;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x880BB980;
	sub_88094290(ctx, base);
	// li r5,7716
	ctx.r5.s64 = 7716;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,2304(r27)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r27.u32 + 2304);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x880BB994;
	sub_88073BD0(ctx, base);
	// lis r9,-30641
	ctx.r9.s64 = -2008088576;
	// li r10,8
	ctx.r10.s64 = 8;
	// addi r11,r9,-18844
	ctx.r11.s64 = ctx.r9.s64 + -18844;
	// li r26,0
	ctx.r26.s64 = 0;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_880BB9B0:
	// stbu r9,1(r11)
	ea = 1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r9.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x880bb9b0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_880BB9B0;
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lis r10,-30708
	ctx.r10.s64 = -2012479488;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r4,r10,-19296
	ctx.r4.s64 = ctx.r10.s64 + -19296;
	// lwz r29,-11984(r11)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11984);
	// lwz r9,84(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 84);
	// stw r9,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r9.u32);
	// bl 0x88096200
	ctx.lr = 0x880BB9D8;
	sub_88096200(ctx, base);
	// lis r8,1
	ctx.r8.s64 = 65536;
	// lis r11,-30682
	ctx.r11.s64 = -2010775552;
	// stw r27,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r27.u32);
	// li r25,1
	ctx.r25.s64 = 1;
	// stw r29,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// ori r10,r8,49536
	ctx.r10.u64 = ctx.r8.u64 | 49536;
	// stw r3,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r3.u32);
	// addi r11,r11,1644
	ctx.r11.s64 = ctx.r11.s64 + 1644;
	// stw r25,7468(r31)
	PPC_STORE_U32(ctx.r31.u32 + 7468, ctx.r25.u32);
	// lwz r8,32(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// addi r30,r11,-2032
	ctx.r30.s64 = ctx.r11.s64 + -2032;
	// cmplwi cr6,r8,1
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1, ctx.xer);
	// blt cr6,0x880bba48
	if (ctx.cr6.lt) goto loc_880BBA48;
	// beq cr6,0x880bba34
	if (ctx.cr6.eq) goto loc_880BBA34;
	// cmplwi cr6,r8,3
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 3, ctx.xer);
	// bge cr6,0x880bba50
	if (!ctx.cr6.lt) goto loc_880BBA50;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// ori r9,r10,56960
	ctx.r9.u64 = ctx.r10.u64 | 56960;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// b 0x880bba50
	goto loc_880BBA50;
loc_880BBA34:
	// lis r10,1
	ctx.r10.s64 = 65536;
	// addi r30,r11,-1320
	ctx.r30.s64 = ctx.r11.s64 + -1320;
	// ori r9,r10,56960
	ctx.r9.u64 = ctx.r10.u64 | 56960;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// b 0x880bba50
	goto loc_880BBA50;
loc_880BBA48:
	// addi r30,r11,-2032
	ctx.r30.s64 = ctx.r11.s64 + -2032;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
loc_880BBA50:
	// srawi r11,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r10.s32 >> 2;
	// addze r10,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r10.s64 = temp.s64;
	// stw r10,7440(r31)
	PPC_STORE_U32(ctx.r31.u32 + 7440, ctx.r10.u32);
	// stw r9,7680(r31)
	PPC_STORE_U32(ctx.r31.u32 + 7680, ctx.r9.u32);
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r8,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addi r11,r11,7332
	ctx.r11.s64 = ctx.r11.s64 + 7332;
	// lwz r7,136(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 136);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stw r9,104(r11)
	PPC_STORE_U32(ctx.r11.u32 + 104, ctx.r9.u32);
	// stw r9,100(r11)
	PPC_STORE_U32(ctx.r11.u32 + 100, ctx.r9.u32);
	// bne cr6,0x880bbaa0
	if (!ctx.cr6.eq) goto loc_880BBAA0;
	// rotlwi r10,r9,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// srawi r9,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 2;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// stw r8,108(r11)
	PPC_STORE_U32(ctx.r11.u32 + 108, ctx.r8.u32);
loc_880BBAA0:
	// lis r11,-30688
	ctx.r11.s64 = -2011168768;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-29512
	ctx.r4.s64 = ctx.r11.s64 + -29512;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x880969a8
	ctx.lr = 0x880BBAB4;
	sub_880969A8(ctx, base);
	// stw r26,7692(r31)
	PPC_STORE_U32(ctx.r31.u32 + 7692, ctx.r26.u32);
	// stw r26,7688(r31)
	PPC_STORE_U32(ctx.r31.u32 + 7688, ctx.r26.u32);
	// lis r10,-30688
	ctx.r10.s64 = -2011168768;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-30056
	ctx.r4.s64 = ctx.r10.s64 + -30056;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x880969a8
	ctx.lr = 0x880BBAD0;
	sub_880969A8(ctx, base);
	// li r28,3
	ctx.r28.s64 = 3;
	// li r9,120
	ctx.r9.s64 = 120;
	// stw r28,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r28.u32);
	// li r10,72
	ctx.r10.s64 = 72;
	// stw r9,168(r27)
	PPC_STORE_U32(ctx.r27.u32 + 168, ctx.r9.u32);
	// lis r8,120
	ctx.r8.s64 = 7864320;
	// lis r7,160
	ctx.r7.s64 = 10485760;
	// li r6,16
	ctx.r6.s64 = 16;
	// addi r11,r31,6752
	ctx.r11.s64 = ctx.r31.s64 + 6752;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r5,r10,55
	ctx.r5.s64 = ctx.r10.s64 + 55;
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r4,r29
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r29.u32);
	// subf r10,r3,r8
	ctx.r10.s64 = ctx.r8.s64 - ctx.r3.s64;
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// stw r7,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r7.u32);
	// stw r6,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r6.u32);
loc_880BBB18:
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
	// bdnz 0x880bbb18
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_880BBB18;
	// li r7,300
	ctx.r7.s64 = 300;
	// stw r7,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r7.u32);
	// lis r6,-30708
	ctx.r6.s64 = -2012479488;
	// lis r5,-30708
	ctx.r5.s64 = -2012479488;
	// stw r7,988(r31)
	PPC_STORE_U32(ctx.r31.u32 + 988, ctx.r7.u32);
	// li r11,344
	ctx.r11.s64 = 344;
	// li r9,388
	ctx.r9.s64 = 388;
	// li r10,432
	ctx.r10.s64 = 432;
	// stw r11,700(r31)
	PPC_STORE_U32(ctx.r31.u32 + 700, ctx.r11.u32);
	// li r8,476
	ctx.r8.s64 = 476;
	// stw r11,1276(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1276, ctx.r11.u32);
	// li r4,256
	ctx.r4.s64 = 256;
	// stw r9,1564(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1564, ctx.r9.u32);
	// li r3,520
	ctx.r3.s64 = 520;
	// stw r10,1852(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1852, ctx.r10.u32);
	// li r7,564
	ctx.r7.s64 = 564;
	// stw r4,412(r31)
	PPC_STORE_U32(ctx.r31.u32 + 412, ctx.r4.u32);
	// addi r6,r6,-18536
	ctx.r6.s64 = ctx.r6.s64 + -18536;
	// stw r11,2140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2140, ctx.r11.u32);
	// addi r5,r5,-19208
	ctx.r5.s64 = ctx.r5.s64 + -19208;
	// stw r9,2428(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2428, ctx.r9.u32);
	// stw r10,2716(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2716, ctx.r10.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r8,3004(r31)
	PPC_STORE_U32(ctx.r31.u32 + 3004, ctx.r8.u32);
	// stw r3,3292(r31)
	PPC_STORE_U32(ctx.r31.u32 + 3292, ctx.r3.u32);
	// stw r7,3580(r31)
	PPC_STORE_U32(ctx.r31.u32 + 3580, ctx.r7.u32);
	// stw r11,3868(r31)
	PPC_STORE_U32(ctx.r31.u32 + 3868, ctx.r11.u32);
	// stw r9,4156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4156, ctx.r9.u32);
	// stw r10,4444(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4444, ctx.r10.u32);
	// stw r8,4732(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4732, ctx.r8.u32);
	// stw r6,64(r27)
	PPC_STORE_U32(ctx.r27.u32 + 64, ctx.r6.u32);
	// stw r5,84(r27)
	PPC_STORE_U32(ctx.r27.u32 + 84, ctx.r5.u32);
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// bl 0x881556a0
	ctx.lr = 0x880BBBB4;
	sub_881556A0(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r4,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stw r3,7332(r11)
	PPC_STORE_U32(ctx.r11.u32 + 7332, ctx.r3.u32);
	// lwz r8,8(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r7,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// add r6,r11,r31
	ctx.r6.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lwz r5,7332(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 7332);
	// stw r8,32(r5)
	PPC_STORE_U32(ctx.r5.u32 + 32, ctx.r8.u32);
	// stw r27,36(r5)
	PPC_STORE_U32(ctx.r5.u32 + 36, ctx.r27.u32);
	// lwz r4,16(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// ble cr6,0x880bbcd4
	if (!ctx.cr6.gt) goto loc_880BBCD4;
	// addi r10,r11,-4
	ctx.r10.s64 = ctx.r11.s64 + -4;
loc_880BBC08:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
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
	// lwz r7,7332(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + 7332);
	// lwz r11,28(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880bbc48
	if (ctx.cr6.eq) goto loc_880BBC48;
loc_880BBC30:
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x880bbd8c
	if (ctx.cr6.eq) goto loc_880BBD8C;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880bbc30
	if (!ctx.cr6.eq) goto loc_880BBC30;
loc_880BBC48:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_880BBC4C:
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
	// addi r6,r8,917
	ctx.r6.s64 = ctx.r8.s64 + 917;
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
	// lwz r6,16(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// cmpw cr6,r9,r6
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r6.s32, ctx.xer);
	// blt cr6,0x880bbc08
	if (ctx.cr6.lt) goto loc_880BBC08;
loc_880BBCD4:
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r11,r31,7308
	ctx.r11.s64 = ctx.r31.s64 + 7308;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lis r10,128
	ctx.r10.s64 = 8388608;
	// ori r10,r10,32896
	ctx.r10.u64 = ctx.r10.u64 | 32896;
loc_880BBCE8:
	// stwu r10,144(r11)
	ea = 144 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x880bbce8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_880BBCE8;
	// li r11,2
	ctx.r11.s64 = 2;
	// li r9,4
	ctx.r9.s64 = 4;
	// stw r11,5076(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5076, ctx.r11.u32);
	// li r10,5
	ctx.r10.s64 = 5;
	// stw r28,5160(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5160, ctx.r28.u32);
	// lis r11,-30642
	ctx.r11.s64 = -2008154112;
	// stw r9,5244(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5244, ctx.r9.u32);
	// stw r10,5328(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5328, ctx.r10.u32);
	// addi r11,r11,-32760
	ctx.r11.s64 = ctx.r11.s64 + -32760;
	// stw r26,5664(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5664, ctx.r26.u32);
	// stw r25,5748(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5748, ctx.r25.u32);
	// addi r9,r11,118
	ctx.r9.s64 = ctx.r11.s64 + 118;
	// stw r10,5832(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5832, ctx.r10.u32);
	// li r10,8
	ctx.r10.s64 = 8;
	// stw r26,6588(r31)
	PPC_STORE_U32(ctx.r31.u32 + 6588, ctx.r26.u32);
	// stw r25,6672(r31)
	PPC_STORE_U32(ctx.r31.u32 + 6672, ctx.r25.u32);
	// stw r26,5412(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5412, ctx.r26.u32);
	// stw r25,5496(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5496, ctx.r25.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// addi r10,r11,68
	ctx.r10.s64 = ctx.r11.s64 + 68;
loc_880BBD40:
	// stw r26,-28(r10)
	PPC_STORE_U32(ctx.r10.u32 + -28, ctx.r26.u32);
	// stwu r26,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r26.u32);
	ctx.r10.u32 = ea;
	// sth r26,-14(r9)
	PPC_STORE_U16(ctx.r9.u32 + -14, ctx.r26.u16);
	// sthu r26,2(r9)
	ea = 2 + ctx.r9.u32;
	PPC_STORE_U16(ea, ctx.r26.u16);
	ctx.r9.u32 = ea;
	// bdnz 0x880bbd40
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_880BBD40;
	// stw r27,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r27.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stw r25,136(r11)
	PPC_STORE_U32(ctx.r11.u32 + 136, ctx.r25.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,142
	ctx.r3.s64 = 142;
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
	// bl 0x880958a0
	ctx.lr = 0x880BBD74;
	sub_880958A0(ctx, base);
	// lis r10,-30633
	ctx.r10.s64 = -2007564288;
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// stw r26,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r26.u32);
	// stw r26,-29732(r10)
	PPC_STORE_U32(ctx.r10.u32 + -29732, ctx.r26.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_880BBD8C:
	// lwz r8,24(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x880bbd9c
	if (ctx.cr6.eq) goto loc_880BBD9C;
	// stw r8,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r8.u32);
loc_880BBD9C:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x880bbc4c
	goto loc_880BBC4C;
}

__attribute__((alias("__imp__sub_880BBDA4"))) PPC_WEAK_FUNC(sub_880BBDA4);
PPC_FUNC_IMPL(__imp__sub_880BBDA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BBDA8"))) PPC_WEAK_FUNC(sub_880BBDA8);
PPC_FUNC_IMPL(__imp__sub_880BBDA8) {
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
	// lwz r11,2304(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 2304);
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r10,r11,7332
	ctx.r10.s64 = ctx.r11.s64 + 7332;
	// stw r8,7444(r11)
	PPC_STORE_U32(ctx.r11.u32 + 7444, ctx.r8.u32);
	// lwz r9,7632(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 7632);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x880bbe28
	if (!ctx.cr6.eq) goto loc_880BBE28;
	// lwz r9,100(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 100);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x880bbe28
	if (!ctx.cr6.gt) goto loc_880BBE28;
	// lwz r7,7688(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 7688);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne cr6,0x880bbdf4
	if (!ctx.cr6.eq) goto loc_880BBDF4;
	// lwz r7,4(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// subf r6,r7,r9
	ctx.r6.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r6,100(r10)
	PPC_STORE_U32(ctx.r10.u32 + 100, ctx.r6.u32);
loc_880BBDF4:
	// lwz r9,7636(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 7636);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x880bbe28
	if (!ctx.cr6.eq) goto loc_880BBE28;
	// lwz r9,100(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 100);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bgt cr6,0x880bbe28
	if (ctx.cr6.gt) goto loc_880BBE28;
	// lis r9,-30643
	ctx.r9.s64 = -2008219648;
	// addi r7,r9,26432
	ctx.r7.s64 = ctx.r9.s64 + 26432;
	// lwz r9,324(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 324);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x880bbe3c
	if (!ctx.cr6.eq) goto loc_880BBE3C;
	// li r11,512
	ctx.r11.s64 = 512;
	// stw r11,100(r10)
	PPC_STORE_U32(ctx.r10.u32 + 100, ctx.r11.u32);
loc_880BBE28:
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
loc_880BBE3C:
	// stw r8,7640(r11)
	PPC_STORE_U32(ctx.r11.u32 + 7640, ctx.r8.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x880bb658
	ctx.lr = 0x880BBE4C;
	sub_880BB658(ctx, base);
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

__attribute__((alias("__imp__sub_880BBE60"))) PPC_WEAK_FUNC(sub_880BBE60);
PPC_FUNC_IMPL(__imp__sub_880BBE60) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,2304(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r11,7332(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 7332);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880bbe74
	if (ctx.cr6.eq) goto loc_880BBE74;
	// stw r4,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r4.u32);
loc_880BBE74:
	// lwz r11,7476(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 7476);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r4,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880BBE88"))) PPC_WEAK_FUNC(sub_880BBE88);
PPC_FUNC_IMPL(__imp__sub_880BBE88) {
	PPC_FUNC_PROLOGUE();
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// b 0x880bbda8
	sub_880BBDA8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880BBE90"))) PPC_WEAK_FUNC(sub_880BBE90);
PPC_FUNC_IMPL(__imp__sub_880BBE90) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// li r10,8
	ctx.r10.s64 = 8;
	// addi r11,r11,-18844
	ctx.r11.s64 = ctx.r11.s64 + -18844;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_880BBEA8:
	// stbu r9,1(r11)
	ea = 1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r9.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x880bbea8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_880BBEA8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880BBEB4"))) PPC_WEAK_FUNC(sub_880BBEB4);
PPC_FUNC_IMPL(__imp__sub_880BBEB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BBEB8"))) PPC_WEAK_FUNC(sub_880BBEB8);
PPC_FUNC_IMPL(__imp__sub_880BBEB8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// lhz r10,5836(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 5836);
	// addi r9,r11,-18844
	ctx.r9.s64 = ctx.r11.s64 + -18844;
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
loc_880BBEE4:
	// lhz r9,92(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 92);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x880bbf00
	if (ctx.cr6.eq) goto loc_880BBF00;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880bbee4
	if (!ctx.cr6.eq) goto loc_880BBEE4;
	// blr 
	return;
loc_880BBF00:
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r10,96(r11)
	PPC_STORE_U16(ctx.r11.u32 + 96, ctx.r10.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880BBF0C"))) PPC_WEAK_FUNC(sub_880BBF0C);
PPC_FUNC_IMPL(__imp__sub_880BBF0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BBF10"))) PPC_WEAK_FUNC(sub_880BBF10);
PPC_FUNC_IMPL(__imp__sub_880BBF10) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// lhz r10,5836(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 5836);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwz r11,-18844(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -18844);
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
loc_880BBF38:
	// lhz r9,92(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 92);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x880bbf54
	if (ctx.cr6.eq) goto loc_880BBF54;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880bbf38
	if (!ctx.cr6.eq) goto loc_880BBF38;
	// blr 
	return;
loc_880BBF54:
	// sth r4,96(r11)
	PPC_STORE_U16(ctx.r11.u32 + 96, ctx.r4.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880BBF5C"))) PPC_WEAK_FUNC(sub_880BBF5C);
PPC_FUNC_IMPL(__imp__sub_880BBF5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BBF60"))) PPC_WEAK_FUNC(sub_880BBF60);
PPC_FUNC_IMPL(__imp__sub_880BBF60) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071120
	ctx.lr = 0x880BBF68;
	__savegprlr_14(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r19,2304(r3)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r9,-30682
	ctx.r9.s64 = -2010775552;
	// lwz r10,184(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// lis r27,28
	ctx.r27.s64 = 1835008;
	// addi r31,r9,3780
	ctx.r31.s64 = ctx.r9.s64 + 3780;
	// lwz r11,168(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// lwz r24,0(r6)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// li r3,17902
	ctx.r3.s64 = 17902;
	// lwz r14,4(r6)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// add r30,r10,r11
	ctx.r30.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r23,8(r19)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r19.u32 + 8);
	// lwz r25,12(r19)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r19.u32 + 12);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// addi r20,r30,2
	ctx.r20.s64 = ctx.r30.s64 + 2;
	// stw r23,7336(r19)
	PPC_STORE_U32(ctx.r19.u32 + 7336, ctx.r23.u32);
	// stw r25,7340(r19)
	PPC_STORE_U32(ctx.r19.u32 + 7340, ctx.r25.u32);
	// stw r23,7480(r19)
	PPC_STORE_U32(ctx.r19.u32 + 7480, ctx.r23.u32);
	// stw r25,7484(r19)
	PPC_STORE_U32(ctx.r19.u32 + 7484, ctx.r25.u32);
	// lwz r11,18852(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 18852);
	// lwz r10,18856(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 18856);
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// add r28,r10,r25
	ctx.r28.u64 = ctx.r10.u64 + ctx.r25.u64;
	// add r29,r11,r23
	ctx.r29.u64 = ctx.r11.u64 + ctx.r23.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// add r4,r29,r27
	ctx.r4.u64 = ctx.r29.u64 + ctx.r27.u64;
	// bl 0x881538c0
	ctx.lr = 0x880BBFD8;
	sub_881538C0(ctx, base);
	// lis r18,-30597
	ctx.r18.s64 = -2005204992;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r18,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r18.u32);
	// beq cr6,0x880bc004
	if (ctx.cr6.eq) goto loc_880BC004;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-11932(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + -11932);
	// oris r9,r10,518
	ctx.r9.u64 = ctx.r10.u64 | 33947648;
	// addi r26,r11,1
	ctx.r26.s64 = ctx.r11.s64 + 1;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r26,-11932(r18)
	PPC_STORE_U32(ctx.r18.u32 + -11932, ctx.r26.u32);
	// b 0x880bc008
	goto loc_880BC008;
loc_880BC004:
	// lwz r26,-11932(r18)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r18.u32 + -11932);
loc_880BC008:
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// subf r4,r27,r29
	ctx.r4.s64 = ctx.r29.s64 - ctx.r27.s64;
	// li r3,17902
	ctx.r3.s64 = 17902;
	// bl 0x881538c0
	ctx.lr = 0x880BC01C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880bc038
	if (ctx.cr6.eq) goto loc_880BC038;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r11,r26,1
	ctx.r11.s64 = ctx.r26.s64 + 1;
	// oris r9,r10,1542
	ctx.r9.u64 = ctx.r10.u64 | 101056512;
	// stw r11,-11932(r18)
	PPC_STORE_U32(ctx.r18.u32 + -11932, ctx.r11.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_880BC038:
	// li r28,-1
	ctx.r28.s64 = -1;
	// addi r27,r19,5160
	ctx.r27.s64 = ctx.r19.s64 + 5160;
	// addi r29,r19,3060
	ctx.r29.s64 = ctx.r19.s64 + 3060;
	// li r26,2
	ctx.r26.s64 = 2;
	// li r30,10
	ctx.r30.s64 = 10;
loc_880BC04C:
	// lwz r11,-84(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + -84);
	// addi r8,r31,18996
	ctx.r8.s64 = ctx.r31.s64 + 18996;
	// addi r7,r31,18996
	ctx.r7.s64 = ctx.r31.s64 + 18996;
	// lwz r10,18804(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 18804);
	// rlwinm r5,r11,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,18808(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 18808);
	// addi r4,r8,1
	ctx.r4.s64 = ctx.r8.s64 + 1;
	// lwz r8,-288(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + -288);
	// lwz r22,-292(r29)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r29.u32 + -292);
	// addi r21,r28,1
	ctx.r21.s64 = ctx.r28.s64 + 1;
	// divw r6,r8,r30
	ctx.r6.s32 = ppc_divw(ctx.r8.s32, ctx.r30.s32);
	// addi r3,r11,17861
	ctx.r3.s64 = ctx.r11.s64 + 17861;
	// lbzx r7,r5,r7
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r7.u32);
	// cntlzw r11,r21
	ctx.r11.u64 = ctx.r21.u32 == 0 ? 32 : __builtin_clz(ctx.r21.u32);
	// lbzx r5,r5,r4
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r4.u32);
	// extsb r8,r7
	ctx.r8.s64 = ctx.r7.s8;
	// extsb r7,r5
	ctx.r7.s64 = ctx.r5.s8;
	// add r4,r8,r10
	ctx.r4.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r10,r7,r9
	ctx.r10.u64 = ctx.r7.u64 + ctx.r9.u64;
	// mullw r9,r4,r28
	ctx.r9.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r28.s32);
	// rlwinm r8,r9,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// divw r9,r22,r30
	ctx.r9.s32 = ppc_divw(ctx.r22.s32, ctx.r30.s32);
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r8,r9
	ctx.r4.u64 = ctx.r8.u64 + ctx.r9.u64;
	// add r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 + ctx.r6.u64;
	// rlwinm r22,r11,27,31,31
	ctx.r22.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// mr r8,r14
	ctx.r8.u64 = ctx.r14.u64;
	// mr r9,r22
	ctx.r9.u64 = ctx.r22.u64;
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
	// mr r6,r20
	ctx.r6.u64 = ctx.r20.u64;
	// add r5,r10,r25
	ctx.r5.u64 = ctx.r10.u64 + ctx.r25.u64;
	// add r4,r4,r23
	ctx.r4.u64 = ctx.r4.u64 + ctx.r23.u64;
	// bl 0x880a51a0
	ctx.lr = 0x880BC0D0;
	sub_880A51A0(ctx, base);
	// addi r11,r31,19012
	ctx.r11.s64 = ctx.r31.s64 + 19012;
	// mr r9,r22
	ctx.r9.u64 = ctx.r22.u64;
	// lwz r10,18812(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 18812);
	// addi r17,r11,1
	ctx.r17.s64 = ctx.r11.s64 + 1;
	// lwz r5,18816(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 18816);
	// addi r4,r31,19012
	ctx.r4.s64 = ctx.r31.s64 + 19012;
	// mr r8,r14
	ctx.r8.u64 = ctx.r14.u64;
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
	// mr r6,r20
	ctx.r6.u64 = ctx.r20.u64;
	// lwzu r11,84(r27)
	ea = 84 + ctx.r27.u32;
	ctx.r11.u64 = PPC_LOAD_U32(ea);
	ctx.r27.u32 = ea;
	// lwz r22,284(r29)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r29.u32 + 284);
	// rlwinm r16,r11,1,0,30
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r3,r11,17869
	ctx.r3.s64 = ctx.r11.s64 + 17869;
	// lwzu r11,288(r29)
	ea = 288 + ctx.r29.u32;
	ctx.r11.u64 = PPC_LOAD_U32(ea);
	ctx.r29.u32 = ea;
	// divw r21,r22,r30
	ctx.r21.s32 = ppc_divw(ctx.r22.s32, ctx.r30.s32);
	// divw r22,r11,r30
	ctx.r22.s32 = ppc_divw(ctx.r11.s32, ctx.r30.s32);
	// lbzx r11,r16,r4
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r16.u32 + ctx.r4.u32);
	// lbzx r4,r16,r17
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r16.u32 + ctx.r17.u32);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// extsb r4,r4
	ctx.r4.s64 = ctx.r4.s8;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r10,r4,r5
	ctx.r10.u64 = ctx.r4.u64 + ctx.r5.u64;
	// mullw r5,r11,r28
	ctx.r5.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r5,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r22
	ctx.r11.u64 = ctx.r11.u64 + ctx.r22.u64;
	// add r10,r10,r21
	ctx.r10.u64 = ctx.r10.u64 + ctx.r21.u64;
	// add r5,r11,r25
	ctx.r5.u64 = ctx.r11.u64 + ctx.r25.u64;
	// add r4,r10,r23
	ctx.r4.u64 = ctx.r10.u64 + ctx.r23.u64;
	// bl 0x880a51a0
	ctx.lr = 0x880BC148;
	sub_880A51A0(ctx, base);
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// neg r28,r28
	ctx.r28.s64 = -ctx.r28.s64;
	// bne 0x880bc04c
	if (!ctx.cr0.eq) goto loc_880BC04C;
	// lwz r15,-11932(r18)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r18.u32 + -11932);
	// li r27,-1
	ctx.r27.s64 = -1;
	// addi r28,r19,2196
	ctx.r28.s64 = ctx.r19.s64 + 2196;
	// addi r29,r19,5424
	ctx.r29.s64 = ctx.r19.s64 + 5424;
	// li r22,2
	ctx.r22.s64 = 2;
loc_880BC168:
	// addi r9,r27,1
	ctx.r9.s64 = ctx.r27.s64 + 1;
	// lwz r10,52(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 52);
	// lwz r11,-12(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -12);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// rlwinm r26,r8,27,31,31
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// blt cr6,0x880bc234
	if (ctx.cr6.lt) goto loc_880BC234;
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// bge cr6,0x880bc310
	if (!ctx.cr6.lt) goto loc_880BC310;
	// rlwinm r4,r11,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r5,0(r28)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// addi r3,r31,18924
	ctx.r3.s64 = ctx.r31.s64 + 18924;
	// lwz r10,18756(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 18756);
	// addi r8,r31,18924
	ctx.r8.s64 = ctx.r31.s64 + 18924;
	// lwz r9,18760(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 18760);
	// lwz r7,-4(r28)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r28.u32 + -4);
	// mr r6,r20
	ctx.r6.u64 = ctx.r20.u64;
	// addi r21,r8,1
	ctx.r21.s64 = ctx.r8.s64 + 1;
	// divw r8,r5,r30
	ctx.r8.s32 = ppc_divw(ctx.r5.s32, ctx.r30.s32);
	// lbzx r17,r4,r3
	ctx.r17.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r3.u32);
	// addi r3,r11,17681
	ctx.r3.s64 = ctx.r11.s64 + 17681;
	// divw r7,r7,r30
	ctx.r7.s32 = ppc_divw(ctx.r7.s32, ctx.r30.s32);
	// extsb r5,r17
	ctx.r5.s64 = ctx.r17.s8;
	// lbzx r4,r4,r21
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r21.u32);
	// add r11,r5,r10
	ctx.r11.u64 = ctx.r5.u64 + ctx.r10.u64;
	// extsb r10,r4
	ctx.r10.s64 = ctx.r4.s8;
	// mullw r5,r11,r27
	ctx.r5.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r27.s32);
	// add r4,r10,r9
	ctx.r4.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r9,r5,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r4,r9,r23
	ctx.r4.u64 = ctx.r9.u64 + ctx.r23.u64;
	// add r5,r10,r25
	ctx.r5.u64 = ctx.r10.u64 + ctx.r25.u64;
	// stw r4,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r4.u32);
	// stw r5,4(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4, ctx.r5.u32);
	// bl 0x881538c0
	ctx.lr = 0x880BC1FC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x880bc2f0
	if (ctx.cr6.eq) goto loc_880BC2F0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880bc214
	if (ctx.cr6.eq) goto loc_880BC214;
	// lwz r11,0(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880BC214:
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x880bc2f0
	if (ctx.cr6.eq) goto loc_880BC2F0;
	// lwz r11,0(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880bc2f0
	if (ctx.cr6.eq) goto loc_880BC2F0;
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// b 0x880bc2dc
	goto loc_880BC2DC;
loc_880BC234:
	// rlwinm r4,r11,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r5,0(r28)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// addi r3,r31,18908
	ctx.r3.s64 = ctx.r31.s64 + 18908;
	// lwz r10,18748(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 18748);
	// addi r8,r31,18908
	ctx.r8.s64 = ctx.r31.s64 + 18908;
	// lwz r9,18752(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 18752);
	// lwz r7,-4(r28)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r28.u32 + -4);
	// mr r6,r20
	ctx.r6.u64 = ctx.r20.u64;
	// addi r21,r8,1
	ctx.r21.s64 = ctx.r8.s64 + 1;
	// divw r8,r5,r30
	ctx.r8.s32 = ppc_divw(ctx.r5.s32, ctx.r30.s32);
	// lbzx r17,r4,r3
	ctx.r17.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r3.u32);
	// addi r3,r11,17673
	ctx.r3.s64 = ctx.r11.s64 + 17673;
	// divw r7,r7,r30
	ctx.r7.s32 = ppc_divw(ctx.r7.s32, ctx.r30.s32);
	// extsb r5,r17
	ctx.r5.s64 = ctx.r17.s8;
	// lbzx r4,r4,r21
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r21.u32);
	// add r11,r5,r10
	ctx.r11.u64 = ctx.r5.u64 + ctx.r10.u64;
	// extsb r10,r4
	ctx.r10.s64 = ctx.r4.s8;
	// mullw r5,r11,r27
	ctx.r5.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r27.s32);
	// add r4,r10,r9
	ctx.r4.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r9,r5,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r4,r9,r23
	ctx.r4.u64 = ctx.r9.u64 + ctx.r23.u64;
	// add r5,r10,r25
	ctx.r5.u64 = ctx.r10.u64 + ctx.r25.u64;
	// stw r4,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r4.u32);
	// stw r5,4(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4, ctx.r5.u32);
	// bl 0x881538c0
	ctx.lr = 0x880BC2A4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x880bc2f0
	if (ctx.cr6.eq) goto loc_880BC2F0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880bc2bc
	if (ctx.cr6.eq) goto loc_880BC2BC;
	// lwz r11,0(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880BC2BC:
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x880bc2f0
	if (ctx.cr6.eq) goto loc_880BC2F0;
	// lwz r11,0(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880bc2f0
	if (ctx.cr6.eq) goto loc_880BC2F0;
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// stw r15,-11932(r18)
	PPC_STORE_U32(ctx.r18.u32 + -11932, ctx.r15.u32);
loc_880BC2DC:
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880BC2F0:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq cr6,0x880bc310
	if (ctx.cr6.eq) goto loc_880BC310;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880bc310
	if (ctx.cr6.eq) goto loc_880BC310;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r26,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_880BC310:
	// addic. r22,r22,-1
	ctx.xer.ca = ctx.r22.u32 > 0;
	ctx.r22.s64 = ctx.r22.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// neg r27,r27
	ctx.r27.s64 = -ctx.r27.s64;
	// addi r29,r29,84
	ctx.r29.s64 = ctx.r29.s64 + 84;
	// addi r28,r28,288
	ctx.r28.s64 = ctx.r28.s64 + 288;
	// bne 0x880bc168
	if (!ctx.cr0.eq) goto loc_880BC168;
	// lwz r11,5580(r19)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r19.u32 + 5580);
	// addi r10,r31,19028
	ctx.r10.s64 = ctx.r31.s64 + 19028;
	// addi r7,r31,19028
	ctx.r7.s64 = ctx.r31.s64 + 19028;
	// lwz r9,18820(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 18820);
	// rlwinm r4,r11,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r15,-11932(r18)
	PPC_STORE_U32(ctx.r18.u32 + -11932, ctx.r15.u32);
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// lwz r10,18824(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 18824);
	// addi r3,r11,17877
	ctx.r3.s64 = ctx.r11.s64 + 17877;
	// lwz r11,708(r19)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r19.u32 + 708);
	// mr r6,r20
	ctx.r6.u64 = ctx.r20.u64;
	// divw r8,r11,r30
	ctx.r8.s32 = ppc_divw(ctx.r11.s32, ctx.r30.s32);
	// lbzx r5,r4,r5
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r5.u32);
	// lbzx r4,r4,r7
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r7.u32);
	// extsb r7,r5
	ctx.r7.s64 = ctx.r5.s8;
	// extsb r11,r4
	ctx.r11.s64 = ctx.r4.s8;
	// add r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 + ctx.r10.u64;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r9,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r4,r10,r23
	ctx.r4.u64 = ctx.r10.u64 + ctx.r23.u64;
	// add r5,r11,r25
	ctx.r5.u64 = ctx.r11.u64 + ctx.r25.u64;
	// bl 0x881538c0
	ctx.lr = 0x880BC384;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x880bc3d0
	if (ctx.cr6.eq) goto loc_880BC3D0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880bc39c
	if (ctx.cr6.eq) goto loc_880BC39C;
	// lwz r11,0(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880BC39C:
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x880bc3d0
	if (ctx.cr6.eq) goto loc_880BC3D0;
	// lwz r11,0(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880bc3d0
	if (ctx.cr6.eq) goto loc_880BC3D0;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r15,-11932(r18)
	PPC_STORE_U32(ctx.r18.u32 + -11932, ctx.r15.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880BC3D0:
	// lwz r11,132(r19)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r19.u32 + 132);
	// mr r6,r20
	ctx.r6.u64 = ctx.r20.u64;
	// stw r23,5004(r19)
	PPC_STORE_U32(ctx.r19.u32 + 5004, ctx.r23.u32);
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// divw r11,r11,r30
	ctx.r11.s32 = ppc_divw(ctx.r11.s32, ctx.r30.s32);
	// li r3,17693
	ctx.r3.s64 = 17693;
	// add r5,r11,r25
	ctx.r5.u64 = ctx.r11.u64 + ctx.r25.u64;
	// stw r5,5008(r19)
	PPC_STORE_U32(ctx.r19.u32 + 5008, ctx.r5.u32);
	// bl 0x881538c0
	ctx.lr = 0x880BC3F4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x880bc440
	if (ctx.cr6.eq) goto loc_880BC440;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880bc40c
	if (ctx.cr6.eq) goto loc_880BC40C;
	// lwz r11,0(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880BC40C:
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x880bc440
	if (ctx.cr6.eq) goto loc_880BC440;
	// lwz r11,0(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880bc440
	if (ctx.cr6.eq) goto loc_880BC440;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r15,-11932(r18)
	PPC_STORE_U32(ctx.r18.u32 + -11932, ctx.r15.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880BC440:
	// li r28,-1
	ctx.r28.s64 = -1;
	// li r29,0
	ctx.r29.s64 = 0;
	// lis r26,2
	ctx.r26.s64 = 131072;
loc_880BC44C:
	// mulli r10,r29,84
	ctx.r10.s64 = ctx.r29.s64 * 84;
	// lwz r11,18740(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 18740);
	// lwz r9,18744(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 18744);
	// add r8,r10,r19
	ctx.r8.u64 = ctx.r10.u64 + ctx.r19.u64;
	// addi r10,r31,18892
	ctx.r10.s64 = ctx.r31.s64 + 18892;
	// addi r7,r31,18892
	ctx.r7.s64 = ctx.r31.s64 + 18892;
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// addi r5,r28,1
	ctx.r5.s64 = ctx.r28.s64 + 1;
	// lwz r10,5664(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 5664);
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// cntlzw r4,r5
	ctx.r4.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r3,r10,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r27,r4,27,31,31
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// lbzx r8,r3,r7
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r7.u32);
	// lbzx r6,r3,r6
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r6.u32);
	// extsb r7,r8
	ctx.r7.s64 = ctx.r8.s8;
	// extsb r8,r6
	ctx.r8.s64 = ctx.r6.s8;
	// add r5,r7,r11
	ctx.r5.u64 = ctx.r7.u64 + ctx.r11.u64;
	// add r4,r8,r9
	ctx.r4.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r3,r5,r28
	ctx.r3.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r28.s32);
	// rlwinm r9,r3,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r4,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// add r9,r9,r23
	ctx.r9.u64 = ctx.r9.u64 + ctx.r23.u64;
	// add r7,r11,r25
	ctx.r7.u64 = ctx.r11.u64 + ctx.r25.u64;
	// bne cr6,0x880bc4b4
	if (!ctx.cr6.eq) goto loc_880BC4B4;
	// subf r9,r26,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r26.s64;
loc_880BC4B4:
	// rlwinm r11,r29,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r8,420(r19)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r19.u32 + 420);
	// addi r3,r10,17665
	ctx.r3.s64 = ctx.r10.s64 + 17665;
	// add r6,r29,r11
	ctx.r6.u64 = ctx.r29.u64 + ctx.r11.u64;
	// divw r8,r8,r30
	ctx.r8.s32 = ppc_divw(ctx.r8.s32, ctx.r30.s32);
	// rlwinm r11,r6,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFFE0;
	// mr r6,r20
	ctx.r6.u64 = ctx.r20.u64;
	// add r11,r11,r19
	ctx.r11.u64 = ctx.r11.u64 + ctx.r19.u64;
	// lwz r5,1044(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1044);
	// lwz r4,1040(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1040);
	// divw r11,r5,r30
	ctx.r11.s32 = ppc_divw(ctx.r5.s32, ctx.r30.s32);
	// divw r10,r4,r30
	ctx.r10.s32 = ppc_divw(ctx.r4.s32, ctx.r30.s32);
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r4,r10,r9
	ctx.r4.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r5,r11,r7
	ctx.r5.u64 = ctx.r11.u64 + ctx.r7.u64;
	// bl 0x881538c0
	ctx.lr = 0x880BC4F4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x880bc53c
	if (ctx.cr6.eq) goto loc_880BC53C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880bc50c
	if (ctx.cr6.eq) goto loc_880BC50C;
	// lwz r11,0(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880BC50C:
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x880bc53c
	if (ctx.cr6.eq) goto loc_880BC53C;
	// lwz r11,0(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880bc53c
	if (ctx.cr6.eq) goto loc_880BC53C;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880BC53C:
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq cr6,0x880bc55c
	if (ctx.cr6.eq) goto loc_880BC55C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880bc55c
	if (ctx.cr6.eq) goto loc_880BC55C;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r27,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_880BC55C:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// neg r28,r28
	ctx.r28.s64 = -ctx.r28.s64;
	// cmpwi cr6,r29,2
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 2, ctx.xer);
	// blt cr6,0x880bc44c
	if (ctx.cr6.lt) goto loc_880BC44C;
	// lwz r28,5832(r19)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r19.u32 + 5832);
	// addi r11,r31,18860
	ctx.r11.s64 = ctx.r31.s64 + 18860;
	// addi r6,r31,18860
	ctx.r6.s64 = ctx.r31.s64 + 18860;
	// lwz r4,1572(r19)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r19.u32 + 1572);
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// lwz r11,18728(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 18728);
	// rlwinm r29,r28,1,0,30
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,18724(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 18724);
	// divw r7,r4,r30
	ctx.r7.s32 = ppc_divw(ctx.r4.s32, ctx.r30.s32);
	// lwz r9,1568(r19)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r19.u32 + 1568);
	// lwz r27,420(r19)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r19.u32 + 420);
	// addi r3,r28,17649
	ctx.r3.s64 = ctx.r28.s64 + 17649;
	// divw r8,r9,r30
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r30.s32);
	// stw r15,-11932(r18)
	PPC_STORE_U32(ctx.r18.u32 + -11932, ctx.r15.u32);
	// divw r9,r27,r30
	ctx.r9.s32 = ppc_divw(ctx.r27.s32, ctx.r30.s32);
	// lbzx r5,r29,r5
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r5.u32);
	// lbzx r4,r29,r6
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r6.u32);
	// extsb r5,r5
	ctx.r5.s64 = ctx.r5.s8;
	// extsb r6,r4
	ctx.r6.s64 = ctx.r4.s8;
	// add r11,r5,r11
	ctx.r11.u64 = ctx.r5.u64 + ctx.r11.u64;
	// add r10,r6,r10
	ctx.r10.u64 = ctx.r6.u64 + ctx.r10.u64;
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r4,r10,r23
	ctx.r4.u64 = ctx.r10.u64 + ctx.r23.u64;
	// add r5,r11,r25
	ctx.r5.u64 = ctx.r11.u64 + ctx.r25.u64;
	// mr r6,r20
	ctx.r6.u64 = ctx.r20.u64;
	// bl 0x881538c0
	ctx.lr = 0x880BC5E4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x880bc630
	if (ctx.cr6.eq) goto loc_880BC630;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880bc5fc
	if (ctx.cr6.eq) goto loc_880BC5FC;
	// lwz r11,0(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880BC5FC:
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x880bc630
	if (ctx.cr6.eq) goto loc_880BC630;
	// lwz r11,0(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880bc630
	if (ctx.cr6.eq) goto loc_880BC630;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r15,-11932(r18)
	PPC_STORE_U32(ctx.r18.u32 + -11932, ctx.r15.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880BC630:
	// addi r11,r31,18876
	ctx.r11.s64 = ctx.r31.s64 + 18876;
	// lwz r8,1860(r19)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r19.u32 + 1860);
	// addi r9,r31,18876
	ctx.r9.s64 = ctx.r31.s64 + 18876;
	// lwz r5,1856(r19)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r19.u32 + 1856);
	// addi r6,r11,1
	ctx.r6.s64 = ctx.r11.s64 + 1;
	// lwz r10,18736(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 18736);
	// divw r7,r8,r30
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r30.s32);
	// lwz r11,18732(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 18732);
	// divw r8,r5,r30
	ctx.r8.s32 = ppc_divw(ctx.r5.s32, ctx.r30.s32);
	// lwz r4,420(r19)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r19.u32 + 420);
	// addi r3,r28,17657
	ctx.r3.s64 = ctx.r28.s64 + 17657;
	// lbzx r9,r29,r9
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r9.u32);
	// lbzx r5,r29,r6
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r6.u32);
	// extsb r6,r9
	ctx.r6.s64 = ctx.r9.s8;
	// extsb r9,r5
	ctx.r9.s64 = ctx.r5.s8;
	// add r6,r6,r11
	ctx.r6.u64 = ctx.r6.u64 + ctx.r11.u64;
	// add r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 + ctx.r10.u64;
	// divw r9,r4,r30
	ctx.r9.s32 = ppc_divw(ctx.r4.s32, ctx.r30.s32);
	// rlwinm r11,r5,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r6,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r4,r10,r23
	ctx.r4.u64 = ctx.r10.u64 + ctx.r23.u64;
	// add r5,r11,r25
	ctx.r5.u64 = ctx.r11.u64 + ctx.r25.u64;
	// mr r6,r20
	ctx.r6.u64 = ctx.r20.u64;
	// bl 0x881538c0
	ctx.lr = 0x880BC69C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x880bc6e8
	if (ctx.cr6.eq) goto loc_880BC6E8;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880bc6b4
	if (ctx.cr6.eq) goto loc_880BC6B4;
	// lwz r11,0(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880BC6B4:
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x880bc6e8
	if (ctx.cr6.eq) goto loc_880BC6E8;
	// lwz r11,0(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880bc6e8
	if (ctx.cr6.eq) goto loc_880BC6E8;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r15,-11932(r18)
	PPC_STORE_U32(ctx.r18.u32 + -11932, ctx.r15.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880BC6E8:
	// lwz r9,420(r19)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r19.u32 + 420);
	// mr r6,r20
	ctx.r6.u64 = ctx.r20.u64;
	// lwz r11,18784(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 18784);
	// li r3,17836
	ctx.r3.s64 = 17836;
	// lwz r10,18780(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 18780);
	// divw r9,r9,r30
	ctx.r9.s32 = ppc_divw(ctx.r9.s32, ctx.r30.s32);
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r4,r10,r23
	ctx.r4.u64 = ctx.r10.u64 + ctx.r23.u64;
	// add r5,r11,r25
	ctx.r5.u64 = ctx.r11.u64 + ctx.r25.u64;
	// stw r4,6012(r19)
	PPC_STORE_U32(ctx.r19.u32 + 6012, ctx.r4.u32);
	// stw r5,6016(r19)
	PPC_STORE_U32(ctx.r19.u32 + 6016, ctx.r5.u32);
	// bl 0x881538c0
	ctx.lr = 0x880BC720;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x880bc76c
	if (ctx.cr6.eq) goto loc_880BC76C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880bc738
	if (ctx.cr6.eq) goto loc_880BC738;
	// lwz r11,0(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880BC738:
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x880bc76c
	if (ctx.cr6.eq) goto loc_880BC76C;
	// lwz r11,0(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880bc76c
	if (ctx.cr6.eq) goto loc_880BC76C;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r15,-11932(r18)
	PPC_STORE_U32(ctx.r18.u32 + -11932, ctx.r15.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880BC76C:
	// lwz r11,6084(r19)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r19.u32 + 6084);
	// addi r9,r31,18948
	ctx.r9.s64 = ctx.r31.s64 + 18948;
	// addi r7,r31,18948
	ctx.r7.s64 = ctx.r31.s64 + 18948;
	// lwz r4,420(r19)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r19.u32 + 420);
	// rlwinm r5,r11,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,18792(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 18792);
	// addi r29,r9,1
	ctx.r29.s64 = ctx.r9.s64 + 1;
	// lwz r9,18788(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 18788);
	// addi r3,r11,17837
	ctx.r3.s64 = ctx.r11.s64 + 17837;
	// divw r8,r4,r30
	ctx.r8.s32 = ppc_divw(ctx.r4.s32, ctx.r30.s32);
	// mr r6,r20
	ctx.r6.u64 = ctx.r20.u64;
	// lbzx r11,r5,r7
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r7.u32);
	// lbzx r7,r5,r29
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r29.u32);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// extsb r7,r7
	ctx.r7.s64 = ctx.r7.s8;
	// add r5,r11,r9
	ctx.r5.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r4,r7,r10
	ctx.r4.u64 = ctx.r7.u64 + ctx.r10.u64;
	// rlwinm r11,r5,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r11,r23
	ctx.r4.u64 = ctx.r11.u64 + ctx.r23.u64;
	// add r11,r10,r8
	ctx.r11.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r5,r11,r25
	ctx.r5.u64 = ctx.r11.u64 + ctx.r25.u64;
	// bl 0x881538c0
	ctx.lr = 0x880BC7C8;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x880bc814
	if (ctx.cr6.eq) goto loc_880BC814;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880bc7e0
	if (ctx.cr6.eq) goto loc_880BC7E0;
	// lwz r11,0(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880BC7E0:
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x880bc814
	if (ctx.cr6.eq) goto loc_880BC814;
	// lwz r11,0(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880bc814
	if (ctx.cr6.eq) goto loc_880BC814;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r15,-11932(r18)
	PPC_STORE_U32(ctx.r18.u32 + -11932, ctx.r15.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880BC814:
	// lwz r11,6168(r19)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r19.u32 + 6168);
	// addi r9,r31,18972
	ctx.r9.s64 = ctx.r31.s64 + 18972;
	// addi r7,r31,18972
	ctx.r7.s64 = ctx.r31.s64 + 18972;
	// lwz r4,420(r19)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r19.u32 + 420);
	// rlwinm r5,r11,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,18800(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 18800);
	// addi r29,r9,1
	ctx.r29.s64 = ctx.r9.s64 + 1;
	// lwz r9,18796(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 18796);
	// addi r3,r11,17849
	ctx.r3.s64 = ctx.r11.s64 + 17849;
	// divw r8,r4,r30
	ctx.r8.s32 = ppc_divw(ctx.r4.s32, ctx.r30.s32);
	// mr r6,r20
	ctx.r6.u64 = ctx.r20.u64;
	// lbzx r11,r5,r7
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r7.u32);
	// lbzx r7,r5,r29
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r29.u32);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// extsb r7,r7
	ctx.r7.s64 = ctx.r7.s8;
	// add r5,r11,r9
	ctx.r5.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r4,r7,r10
	ctx.r4.u64 = ctx.r7.u64 + ctx.r10.u64;
	// rlwinm r11,r5,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r11,r23
	ctx.r4.u64 = ctx.r11.u64 + ctx.r23.u64;
	// add r11,r10,r8
	ctx.r11.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r5,r11,r25
	ctx.r5.u64 = ctx.r11.u64 + ctx.r25.u64;
	// bl 0x881538c0
	ctx.lr = 0x880BC870;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x880bc8bc
	if (ctx.cr6.eq) goto loc_880BC8BC;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880bc888
	if (ctx.cr6.eq) goto loc_880BC888;
	// lwz r11,0(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880BC888:
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x880bc8bc
	if (ctx.cr6.eq) goto loc_880BC8BC;
	// lwz r11,0(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880bc8bc
	if (ctx.cr6.eq) goto loc_880BC8BC;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r15,-11932(r18)
	PPC_STORE_U32(ctx.r18.u32 + -11932, ctx.r15.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880BC8BC:
	// lwz r11,132(r19)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r19.u32 + 132);
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// li r22,-1
	ctx.r22.s64 = -1;
	// divw r11,r11,r30
	ctx.r11.s32 = ppc_divw(ctx.r11.s32, ctx.r30.s32);
	// li r21,0
	ctx.r21.s64 = 0;
	// add r25,r11,r25
	ctx.r25.u64 = ctx.r11.u64 + ctx.r25.u64;
	// lis r11,547
	ctx.r11.s64 = 35848192;
	// ori r17,r10,16384
	ctx.r17.u64 = ctx.r10.u64 | 16384;
	// ori r16,r11,32768
	ctx.r16.u64 = ctx.r11.u64 | 32768;
loc_880BC8E0:
	// rlwinm r9,r21,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r11,18844(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 18844);
	// lwz r10,18848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 18848);
	// addi r8,r22,1
	ctx.r8.s64 = ctx.r22.s64 + 1;
	// add r7,r21,r9
	ctx.r7.u64 = ctx.r21.u64 + ctx.r9.u64;
	// mullw r6,r11,r22
	ctx.r6.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r22.s32);
	// rlwinm r11,r7,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// cntlzw r5,r8
	ctx.r5.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// add r29,r11,r19
	ctx.r29.u64 = ctx.r11.u64 + ctx.r19.u64;
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r6,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r18,r5,27,31,31
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// mr r6,r20
	ctx.r6.u64 = ctx.r20.u64;
	// lwz r4,4448(r29)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4448);
	// li r3,17885
	ctx.r3.s64 = 17885;
	// lwz r9,4452(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4452);
	// divw r8,r4,r30
	ctx.r8.s32 = ppc_divw(ctx.r4.s32, ctx.r30.s32);
	// divw r9,r9,r30
	ctx.r9.s32 = ppc_divw(ctx.r9.s32, ctx.r30.s32);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r4,r10,r23
	ctx.r4.u64 = ctx.r10.u64 + ctx.r23.u64;
	// add r5,r11,r25
	ctx.r5.u64 = ctx.r11.u64 + ctx.r25.u64;
	// bl 0x881538c0
	ctx.lr = 0x880BC93C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x880bc984
	if (ctx.cr6.eq) goto loc_880BC984;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880bc954
	if (ctx.cr6.eq) goto loc_880BC954;
	// lwz r11,0(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880BC954:
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x880bc984
	if (ctx.cr6.eq) goto loc_880BC984;
	// lwz r11,0(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880bc984
	if (ctx.cr6.eq) goto loc_880BC984;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880BC984:
	// cmpwi cr6,r18,0
	ctx.cr6.compare<int32_t>(ctx.r18.s32, 0, ctx.xer);
	// beq cr6,0x880bc9a4
	if (ctx.cr6.eq) goto loc_880BC9A4;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880bc9a4
	if (ctx.cr6.eq) goto loc_880BC9A4;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r18,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_880BC9A4:
	// mulli r11,r21,84
	ctx.r11.s64 = ctx.r21.s64 * 84;
	// lwz r10,18828(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 18828);
	// lwz r9,18832(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 18832);
	// lwz r8,4448(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4448);
	// lwz r6,4452(r29)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4452);
	// add r28,r11,r19
	ctx.r28.u64 = ctx.r11.u64 + ctx.r19.u64;
	// addi r11,r31,19044
	ctx.r11.s64 = ctx.r31.s64 + 19044;
	// addi r5,r31,19044
	ctx.r5.s64 = ctx.r31.s64 + 19044;
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// divw r7,r8,r30
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r30.s32);
	// lwz r11,6252(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 6252);
	// divw r8,r6,r30
	ctx.r8.s32 = ppc_divw(ctx.r6.s32, ctx.r30.s32);
	// mr r6,r20
	ctx.r6.u64 = ctx.r20.u64;
	// rlwinm r27,r11,1,0,30
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r3,r11,17886
	ctx.r3.s64 = ctx.r11.s64 + 17886;
	// lbzx r11,r27,r5
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r27.u32 + ctx.r5.u32);
	// lbzx r4,r27,r4
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r27.u32 + ctx.r4.u32);
	// extsb r5,r11
	ctx.r5.s64 = ctx.r11.s8;
	// extsb r11,r4
	ctx.r11.s64 = ctx.r4.s8;
	// add r10,r5,r10
	ctx.r10.u64 = ctx.r5.u64 + ctx.r10.u64;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// mullw r5,r10,r22
	ctx.r5.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r22.s32);
	// rlwinm r10,r5,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r9,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r4,r10,r23
	ctx.r4.u64 = ctx.r10.u64 + ctx.r23.u64;
	// add r5,r11,r25
	ctx.r5.u64 = ctx.r11.u64 + ctx.r25.u64;
	// bl 0x881538c0
	ctx.lr = 0x880BCA18;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x880bca6c
	if (ctx.cr6.eq) goto loc_880BCA6C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880bca30
	if (ctx.cr6.eq) goto loc_880BCA30;
	// lwz r11,0(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880BCA30:
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x880bca6c
	if (ctx.cr6.eq) goto loc_880BCA6C;
	// lwz r11,0(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880bca6c
	if (ctx.cr6.eq) goto loc_880BCA6C;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r26,80(r1)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r15,-11932(r26)
	PPC_STORE_U32(ctx.r26.u32 + -11932, ctx.r15.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// b 0x880bca70
	goto loc_880BCA70;
loc_880BCA6C:
	// lwz r26,80(r1)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_880BCA70:
	// cmpwi cr6,r18,0
	ctx.cr6.compare<int32_t>(ctx.r18.s32, 0, ctx.xer);
	// beq cr6,0x880bca90
	if (ctx.cr6.eq) goto loc_880BCA90;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880bca90
	if (ctx.cr6.eq) goto loc_880BCA90;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r18,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_880BCA90:
	// lwz r11,6420(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 6420);
	// addi r8,r31,19060
	ctx.r8.s64 = ctx.r31.s64 + 19060;
	// addi r5,r31,19060
	ctx.r5.s64 = ctx.r31.s64 + 19060;
	// lwz r3,4448(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4448);
	// rlwinm r4,r11,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,18836(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 18836);
	// addi r27,r8,1
	ctx.r27.s64 = ctx.r8.s64 + 1;
	// lwz r9,18840(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 18840);
	// divw r7,r3,r30
	ctx.r7.s32 = ppc_divw(ctx.r3.s32, ctx.r30.s32);
	// lwz r8,4452(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4452);
	// addi r3,r11,17894
	ctx.r3.s64 = ctx.r11.s64 + 17894;
	// divw r8,r8,r30
	ctx.r8.s32 = ppc_divw(ctx.r8.s32, ctx.r30.s32);
	// lbzx r5,r4,r5
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r5.u32);
	// mr r6,r20
	ctx.r6.u64 = ctx.r20.u64;
	// lbzx r11,r4,r27
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r27.u32);
	// extsb r4,r5
	ctx.r4.s64 = ctx.r5.s8;
	// extsb r5,r11
	ctx.r5.s64 = ctx.r11.s8;
	// add r10,r4,r10
	ctx.r10.u64 = ctx.r4.u64 + ctx.r10.u64;
	// add r5,r5,r9
	ctx.r5.u64 = ctx.r5.u64 + ctx.r9.u64;
	// mullw r4,r10,r22
	ctx.r4.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r22.s32);
	// rlwinm r9,r4,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r5,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r4,r9,r23
	ctx.r4.u64 = ctx.r9.u64 + ctx.r23.u64;
	// add r5,r10,r25
	ctx.r5.u64 = ctx.r10.u64 + ctx.r25.u64;
	// bl 0x881538c0
	ctx.lr = 0x880BCAFC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x880bcb48
	if (ctx.cr6.eq) goto loc_880BCB48;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880bcb14
	if (ctx.cr6.eq) goto loc_880BCB14;
	// lwz r11,0(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880BCB14:
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x880bcb48
	if (ctx.cr6.eq) goto loc_880BCB48;
	// lwz r11,0(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880bcb48
	if (ctx.cr6.eq) goto loc_880BCB48;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r15,-11932(r26)
	PPC_STORE_U32(ctx.r26.u32 + -11932, ctx.r15.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880BCB48:
	// cmpwi cr6,r18,0
	ctx.cr6.compare<int32_t>(ctx.r18.s32, 0, ctx.xer);
	// beq cr6,0x880bcb68
	if (ctx.cr6.eq) goto loc_880BCB68;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880bcb68
	if (ctx.cr6.eq) goto loc_880BCB68;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r18,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_880BCB68:
	// lwz r11,6588(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 6588);
	// addi r8,r31,2
	ctx.r8.s64 = ctx.r31.s64 + 2;
	// lwz r10,18772(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 18772);
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r5,3872(r29)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r29.u32 + 3872);
	// lwz r9,18776(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 18776);
	// divw r7,r5,r30
	ctx.r7.s32 = ppc_divw(ctx.r5.s32, ctx.r30.s32);
	// lwz r4,3876(r29)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r29.u32 + 3876);
	// lhzx r3,r6,r31
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r6.u32 + ctx.r31.u32);
	// lhzx r8,r6,r8
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r6.u32 + ctx.r8.u32);
	// extsh r6,r3
	ctx.r6.s64 = ctx.r3.s16;
	// extsh r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	// add r6,r6,r10
	ctx.r6.u64 = ctx.r6.u64 + ctx.r10.u64;
	// add r5,r8,r9
	ctx.r5.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r3,r6,r22
	ctx.r3.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r22.s32);
	// rlwinm r10,r5,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// divw r8,r4,r30
	ctx.r8.s32 = ppc_divw(ctx.r4.s32, ctx.r30.s32);
	// rlwinm r9,r3,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 16) & 0xFFFF0000;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// add r27,r10,r25
	ctx.r27.u64 = ctx.r10.u64 + ctx.r25.u64;
	// add r28,r9,r23
	ctx.r28.u64 = ctx.r9.u64 + ctx.r23.u64;
	// mr r6,r20
	ctx.r6.u64 = ctx.r20.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// beq cr6,0x880bcc20
	if (ctx.cr6.eq) goto loc_880BCC20;
	// addi r3,r11,17695
	ctx.r3.s64 = ctx.r11.s64 + 17695;
	// bl 0x881538c0
	ctx.lr = 0x880BCBDC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x880bccc0
	if (ctx.cr6.eq) goto loc_880BCCC0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880bcbf4
	if (ctx.cr6.eq) goto loc_880BCBF4;
	// lwz r11,0(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880BCBF4:
	// lwz r11,0(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880bccc0
	if (ctx.cr6.eq) goto loc_880BCCC0;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r15,-11932(r26)
	PPC_STORE_U32(ctx.r26.u32 + -11932, ctx.r15.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// b 0x880bccbc
	goto loc_880BCCBC;
loc_880BCC20:
	// addi r26,r11,17695
	ctx.r26.s64 = ctx.r11.s64 + 17695;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x881538c0
	ctx.lr = 0x880BCC2C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x880bcc5c
	if (ctx.cr6.eq) goto loc_880BCC5C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880bcc5c
	if (ctx.cr6.eq) goto loc_880BCC5C;
	// lwz r11,0(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// or r8,r10,r16
	ctx.r8.u64 = ctx.r10.u64 | ctx.r16.u64;
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stw r15,-11932(r9)
	PPC_STORE_U32(ctx.r9.u32 + -11932, ctx.r15.u32);
loc_880BCC5C:
	// cmpwi cr6,r18,0
	ctx.cr6.compare<int32_t>(ctx.r18.s32, 0, ctx.xer);
	// beq cr6,0x880bcc7c
	if (ctx.cr6.eq) goto loc_880BCC7C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880bcc7c
	if (ctx.cr6.eq) goto loc_880BCC7C;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r18,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_880BCC7C:
	// mr r6,r20
	ctx.r6.u64 = ctx.r20.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x881538c0
	ctx.lr = 0x880BCC90;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x880bccc0
	if (ctx.cr6.eq) goto loc_880BCCC0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880bccc0
	if (ctx.cr6.eq) goto loc_880BCCC0;
	// lwz r11,0(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// or r8,r10,r17
	ctx.r8.u64 = ctx.r10.u64 | ctx.r17.u64;
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
	// stw r15,-11932(r9)
	PPC_STORE_U32(ctx.r9.u32 + -11932, ctx.r15.u32);
loc_880BCCBC:
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880BCCC0:
	// cmpwi cr6,r18,0
	ctx.cr6.compare<int32_t>(ctx.r18.s32, 0, ctx.xer);
	// beq cr6,0x880bcce0
	if (ctx.cr6.eq) goto loc_880BCCE0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880bcce0
	if (ctx.cr6.eq) goto loc_880BCCE0;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r18,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_880BCCE0:
	// lwz r11,18764(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 18764);
	// cmpwi cr6,r21,1
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 1, ctx.xer);
	// lwz r10,18768(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 18768);
	// mullw r11,r11,r22
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r22.s32);
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r23
	ctx.r11.u64 = ctx.r11.u64 + ctx.r23.u64;
	// add r8,r10,r25
	ctx.r8.u64 = ctx.r10.u64 + ctx.r25.u64;
	// bne cr6,0x880bcd08
	if (!ctx.cr6.eq) goto loc_880BCD08;
	// addis r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -131072;
loc_880BCD08:
	// lwz r10,3872(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 3872);
	// mr r6,r20
	ctx.r6.u64 = ctx.r20.u64;
	// lwz r7,3876(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 3876);
	// li r3,17694
	ctx.r3.s64 = 17694;
	// divw r9,r10,r30
	ctx.r9.s32 = ppc_divw(ctx.r10.s32, ctx.r30.s32);
	// divw r10,r7,r30
	ctx.r10.s32 = ppc_divw(ctx.r7.s32, ctx.r30.s32);
	// add r4,r9,r11
	ctx.r4.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r5,r10,r8
	ctx.r5.u64 = ctx.r10.u64 + ctx.r8.u64;
	// bl 0x881538c0
	ctx.lr = 0x880BCD2C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x880bcd80
	if (ctx.cr6.eq) goto loc_880BCD80;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880bcd44
	if (ctx.cr6.eq) goto loc_880BCD44;
	// lwz r11,0(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880BCD44:
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x880bcd80
	if (ctx.cr6.eq) goto loc_880BCD80;
	// lwz r11,0(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880bcd80
	if (ctx.cr6.eq) goto loc_880BCD80;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stw r15,-11932(r11)
	PPC_STORE_U32(ctx.r11.u32 + -11932, ctx.r15.u32);
	// b 0x880bcd84
	goto loc_880BCD84;
loc_880BCD80:
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_880BCD84:
	// cmpwi cr6,r18,0
	ctx.cr6.compare<int32_t>(ctx.r18.s32, 0, ctx.xer);
	// beq cr6,0x880bcda4
	if (ctx.cr6.eq) goto loc_880BCDA4;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880bcda4
	if (ctx.cr6.eq) goto loc_880BCDA4;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r18,26,0,5
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 26) & 0xFC000000;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880BCDA4:
	// addi r21,r21,1
	ctx.r21.s64 = ctx.r21.s64 + 1;
	// neg r22,r22
	ctx.r22.s64 = -ctx.r22.s64;
	// cmpwi cr6,r21,2
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 2, ctx.xer);
	// blt cr6,0x880bc8e0
	if (ctx.cr6.lt) goto loc_880BC8E0;
	// stw r15,-11932(r11)
	PPC_STORE_U32(ctx.r11.u32 + -11932, ctx.r15.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880BCDC4"))) PPC_WEAK_FUNC(sub_880BCDC4);
PPC_FUNC_IMPL(__imp__sub_880BCDC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BCDC8"))) PPC_WEAK_FUNC(sub_880BCDC8);
PPC_FUNC_IMPL(__imp__sub_880BCDC8) {
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
	// addi r11,r4,7624
	ctx.r11.s64 = ctx.r4.s64 + 7624;
	// addi r9,r4,7620
	ctx.r9.s64 = ctx.r4.s64 + 7620;
	// ori r8,r10,65535
	ctx.r8.u64 = ctx.r10.u64 | 65535;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// lis r7,-30708
	ctx.r7.s64 = -2012479488;
	// stw r8,7624(r4)
	PPC_STORE_U32(ctx.r4.u32 + 7624, ctx.r8.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r7,-16544
	ctx.r5.s64 = ctx.r7.s64 + -16544;
	// li r4,30
	ctx.r4.s64 = 30;
	// bl 0x88096460
	ctx.lr = 0x880BCE04;
	sub_88096460(ctx, base);
	// lis r6,-30641
	ctx.r6.s64 = -2008088576;
	// addi r5,r6,-18844
	ctx.r5.s64 = ctx.r6.s64 + -18844;
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

__attribute__((alias("__imp__sub_880BCE20"))) PPC_WEAK_FUNC(sub_880BCE20);
PPC_FUNC_IMPL(__imp__sub_880BCE20) {
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
	// addi r11,r4,7452
	ctx.r11.s64 = ctx.r4.s64 + 7452;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lis r9,-30708
	ctx.r9.s64 = -2012479488;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r9,-16544
	ctx.r5.s64 = ctx.r9.s64 + -16544;
	// li r4,30
	ctx.r4.s64 = 30;
	// bl 0x88096460
	ctx.lr = 0x880BCE50;
	sub_88096460(ctx, base);
	// lis r8,-30641
	ctx.r8.s64 = -2008088576;
	// stw r3,-18844(r8)
	PPC_STORE_U32(ctx.r8.u32 + -18844, ctx.r3.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880BCE68"))) PPC_WEAK_FUNC(sub_880BCE68);
PPC_FUNC_IMPL(__imp__sub_880BCE68) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880BCE6C"))) PPC_WEAK_FUNC(sub_880BCE6C);
PPC_FUNC_IMPL(__imp__sub_880BCE6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BCE70"))) PPC_WEAK_FUNC(sub_880BCE70);
PPC_FUNC_IMPL(__imp__sub_880BCE70) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x880BCE78;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r28,0(r3)
	ctx.r28.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// lhz r29,2(r3)
	ctx.r29.u64 = PPC_LOAD_U16(ctx.r3.u32 + 2);
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// mr r25,r6
	ctx.r25.u64 = ctx.r6.u64;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// ble cr6,0x880bcee4
	if (!ctx.cr6.gt) goto loc_880BCEE4;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r31,0
	ctx.r31.s64 = 0;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// ble cr6,0x880bcee4
	if (!ctx.cr6.gt) goto loc_880BCEE4;
	// addi r30,r11,-1
	ctx.r30.s64 = ctx.r11.s64 + -1;
loc_880BCEAC:
	// lbz r10,1(r30)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r30.u32 + 1);
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// lbzu r11,2(r30)
	ea = 2 + ctx.r30.u32;
	ctx.r11.u64 = PPC_LOAD_U8(ea);
	ctx.r30.u32 = ea;
	// add r3,r31,r28
	ctx.r3.u64 = ctx.r31.u64 + ctx.r28.u64;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// extsb r8,r11
	ctx.r8.s64 = ctx.r11.s8;
	// rlwinm r10,r9,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r8,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r10,r27
	ctx.r4.u64 = ctx.r10.u64 + ctx.r27.u64;
	// add r5,r11,r26
	ctx.r5.u64 = ctx.r11.u64 + ctx.r26.u64;
	// bl 0x881538c0
	ctx.lr = 0x880BCED8;
	sub_881538C0(ctx, base);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmpw cr6,r31,r29
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r29.s32, ctx.xer);
	// blt cr6,0x880bceac
	if (ctx.cr6.lt) goto loc_880BCEAC;
loc_880BCEE4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880BCEEC"))) PPC_WEAK_FUNC(sub_880BCEEC);
PPC_FUNC_IMPL(__imp__sub_880BCEEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BCEF0"))) PPC_WEAK_FUNC(sub_880BCEF0);
PPC_FUNC_IMPL(__imp__sub_880BCEF0) {
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
	// lwz r6,2304(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r5,-30682
	ctx.r5.s64 = -2010775552;
	// lwz r9,168(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// addi r11,r5,27440
	ctx.r11.s64 = ctx.r5.s64 + 27440;
	// lwz r7,184(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// addi r10,r11,-4448
	ctx.r10.s64 = ctx.r11.s64 + -4448;
	// lwz r4,56(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 56);
	// addi r5,r11,-4448
	ctx.r5.s64 = ctx.r11.s64 + -4448;
	// addi r31,r10,1
	ctx.r31.s64 = ctx.r10.s64 + 1;
	// lwz r8,12(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// rlwinm r30,r4,1,0,30
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,8(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// add r7,r7,r9
	ctx.r7.u64 = ctx.r7.u64 + ctx.r9.u64;
	// rlwinm r9,r4,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r6,r7,-1
	ctx.r6.s64 = ctx.r7.s64 + -1;
	// add r3,r9,r11
	ctx.r3.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lbzx r4,r30,r31
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r31.u32);
	// lbzx r11,r30,r5
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r5.u32);
	// extsb r9,r4
	ctx.r9.s64 = ctx.r4.s8;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addi r9,r9,-40
	ctx.r9.s64 = ctx.r9.s64 + -40;
	// addi r7,r11,8
	ctx.r7.s64 = ctx.r11.s64 + 8;
	// rlwinm r9,r9,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r7,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// add r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x880bce70
	ctx.lr = 0x880BCF70;
	sub_880BCE70(ctx, base);
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

__attribute__((alias("__imp__sub_880BCF88"))) PPC_WEAK_FUNC(sub_880BCF88);
PPC_FUNC_IMPL(__imp__sub_880BCF88) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071140
	ctx.lr = 0x880BCF90;
	__savegprlr_22(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmpwi cr6,r11,80
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 80, ctx.xer);
	// bgt cr6,0x880bcfd8
	if (ctx.cr6.gt) goto loc_880BCFD8;
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// bge 0x880bcfd8
	if (!ctx.cr0.lt) goto loc_880BCFD8;
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// cmplwi cr6,r11,32
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32, ctx.xer);
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// blt cr6,0x880bcfd8
	if (ctx.cr6.lt) goto loc_880BCFD8;
	// li r11,31
	ctx.r11.s64 = 31;
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
loc_880BCFD8:
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// li r22,0
	ctx.r22.s64 = 0;
	// addi r10,r11,-12192
	ctx.r10.s64 = ctx.r11.s64 + -12192;
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// lwz r23,208(r10)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r10.u32 + 208);
	// bgt cr6,0x880bd054
	if (ctx.cr6.gt) goto loc_880BD054;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x880bd0c4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_880BD0C4;
	// bdzf 4*cr6+eq,0x880bd18c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_880BD18C;
	// bne cr6,0x880bd1c8
	if (!ctx.cr6.eq) goto loc_880BD1C8;
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// lis r10,120
	ctx.r10.s64 = 7864320;
	// lis r4,256
	ctx.r4.s64 = 16777216;
	// lwz r6,12(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r9,r11,55
	ctx.r9.s64 = ctx.r11.s64 + 55;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r8,r23
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r23.u32);
	// subf r3,r7,r10
	ctx.r3.s64 = ctx.r10.s64 - ctx.r7.s64;
	// bl 0x88153070
	ctx.lr = 0x880BD030;
	sub_88153070(ctx, base);
	// lis r6,-30642
	ctx.r6.s64 = -2008154112;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r22,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r22.u32);
	// addi r5,r6,-32760
	ctx.r5.s64 = ctx.r6.s64 + -32760;
	// stw r22,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r22.u32);
	// clrlwi r4,r3,16
	ctx.r4.u64 = ctx.r3.u32 & 0xFFFF;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// stw r4,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r4.u32);
	// stw r11,136(r5)
	PPC_STORE_U32(ctx.r5.u32 + 136, ctx.r11.u32);
loc_880BD054:
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// lis r5,-30643
	ctx.r5.s64 = -2008219648;
	// lwz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r4,r10,9552
	ctx.r4.s64 = ctx.r10.s64 + 9552;
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r3,r11,128
	ctx.r3.s64 = ctx.r11.s64 + 128;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r3,2,21,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x7FC;
	// lwz r11,26272(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 26272);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwzx r5,r10,r4
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r4.u32);
	// lwzx r4,r8,r4
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r4.u32);
	// mullw r8,r5,r6
	ctx.r8.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r6.s32);
	// mullw r10,r4,r6
	ctx.r10.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r6.s32);
	// add r3,r8,r7
	ctx.r3.u64 = ctx.r8.u64 + ctx.r7.u64;
	// add r11,r10,r9
	ctx.r11.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// beq cr6,0x880bd1f0
	if (ctx.cr6.eq) goto loc_880BD1F0;
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// rotlwi r10,r3,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x88071190
	__restgprlr_22(ctx, base);
	return;
loc_880BD0C4:
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// cmpwi cr6,r11,24
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 24, ctx.xer);
	// bge cr6,0x880bd150
	if (!ctx.cr6.lt) goto loc_880BD150;
	// lwz r26,8(r31)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r24,4
	ctx.r24.s64 = 4;
	// lwz r25,12(r31)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r27,0(r10)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
loc_880BD0E0:
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x881534c8
	ctx.lr = 0x880BD0E8;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,16
	ctx.r3.s64 = 16;
	// addi r11,r11,-8
	ctx.r11.s64 = ctx.r11.s64 + -8;
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// add r30,r11,r26
	ctx.r30.u64 = ctx.r11.u64 + ctx.r26.u64;
	// bl 0x881534c8
	ctx.lr = 0x880BD100;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,16
	ctx.r3.s64 = 16;
	// addi r10,r11,-8
	ctx.r10.s64 = ctx.r11.s64 + -8;
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r29,r11,r25
	ctx.r29.u64 = ctx.r11.u64 + ctx.r25.u64;
	// bl 0x881534c8
	ctx.lr = 0x880BD118;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,80
	ctx.r3.s64 = 80;
	// addi r28,r11,440
	ctx.r28.s64 = ctx.r11.s64 + 440;
	// bl 0x881534c8
	ctx.lr = 0x880BD128;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// addi r6,r11,32
	ctx.r6.s64 = ctx.r11.s64 + 32;
	// beq cr6,0x880bd148
	if (ctx.cr6.eq) goto loc_880BD148;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880feae0
	ctx.lr = 0x880BD148;
	sub_880FEAE0(ctx, base);
loc_880BD148:
	// addic. r24,r24,-1
	ctx.xer.ca = ctx.r24.u32 > 0;
	ctx.r24.s64 = ctx.r24.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// bne 0x880bd0e0
	if (!ctx.cr0.eq) goto loc_880BD0E0;
loc_880BD150:
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// bge 0x880bd054
	if (!ctx.cr0.lt) goto loc_880BD054;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// cmpwi cr6,r11,18
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 18, ctx.xer);
	// stw r10,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r10.u32);
	// bgt cr6,0x880bd054
	if (ctx.cr6.gt) goto loc_880BD054;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r22,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r22.u32);
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// b 0x880bd054
	goto loc_880BD054;
loc_880BD18C:
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// cmplwi cr6,r11,31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 31, ctx.xer);
	// bne cr6,0x880bd054
	if (!ctx.cr6.eq) goto loc_880BD054;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r9,3
	ctx.r9.s64 = 3;
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// lwz r8,2304(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2304);
	// stw r11,16(r8)
	PPC_STORE_U32(ctx.r8.u32 + 16, ctx.r11.u32);
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// stw r7,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r7.u32);
	// lwz r6,12(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// stw r6,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r6.u32);
	// stw r9,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r9.u32);
	// b 0x880bd054
	goto loc_880BD054;
loc_880BD1C8:
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// bgt 0x880bd054
	if (ctx.cr0.gt) goto loc_880BD054;
	// lwz r3,60(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// bl 0x881551d0
	ctx.lr = 0x880BD1E0;
	sub_881551D0(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x88094220
	ctx.lr = 0x880BD1E8;
	sub_88094220(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x88071190
	__restgprlr_22(ctx, base);
	return;
loc_880BD1F0:
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addi r11,r11,51
	ctx.r11.s64 = ctx.r11.s64 + 51;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r10,r23
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r23.u32);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x88071190
	__restgprlr_22(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880BD214"))) PPC_WEAK_FUNC(sub_880BD214);
PPC_FUNC_IMPL(__imp__sub_880BD214) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BD218"))) PPC_WEAK_FUNC(sub_880BD218);
PPC_FUNC_IMPL(__imp__sub_880BD218) {
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
	// lis r11,-30708
	ctx.r11.s64 = -2012479488;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r5,r11,-11752
	ctx.r5.s64 = ctx.r11.s64 + -11752;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x880BD240;
	sub_88094290(ctx, base);
	// li r5,64
	ctx.r5.s64 = 64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r30,2304(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2304);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88073bd0
	ctx.lr = 0x880BD254;
	sub_88073BD0(ctx, base);
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r31,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r31.u32);
	// lis r8,360
	ctx.r8.s64 = 23592960;
	// stw r9,44(r30)
	PPC_STORE_U32(ctx.r30.u32 + 44, ctx.r9.u32);
	// lis r7,-120
	ctx.r7.s64 = -7864320;
	// lis r6,-30708
	ctx.r6.s64 = -2012479488;
	// lwz r10,-11984(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11984);
	// lis r5,-30708
	ctx.r5.s64 = -2012479488;
	// lis r4,-30708
	ctx.r4.s64 = -2012479488;
	// li r9,120
	ctx.r9.s64 = 120;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r6,r6,-12408
	ctx.r6.s64 = ctx.r6.s64 + -12408;
	// addi r5,r5,-12560
	ctx.r5.s64 = ctx.r5.s64 + -12560;
	// addi r4,r4,-12696
	ctx.r4.s64 = ctx.r4.s64 + -12696;
	// lwz r10,228(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 228);
	// subf r8,r10,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r10.s64;
	// stw r8,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r8.u32);
	// stw r7,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r7.u32);
	// lwz r7,132(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// stw r7,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r7.u32);
	// stw r9,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r9.u32);
	// stw r11,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r11.u32);
	// stw r9,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r9.u32);
	// stw r11,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r11.u32);
	// stw r11,56(r30)
	PPC_STORE_U32(ctx.r30.u32 + 56, ctx.r11.u32);
	// stw r11,48(r30)
	PPC_STORE_U32(ctx.r30.u32 + 48, ctx.r11.u32);
	// stw r3,52(r30)
	PPC_STORE_U32(ctx.r30.u32 + 52, ctx.r3.u32);
	// stw r6,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r6.u32);
	// stw r5,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r5.u32);
	// stw r4,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r4.u32);
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

__attribute__((alias("__imp__sub_880BD2EC"))) PPC_WEAK_FUNC(sub_880BD2EC);
PPC_FUNC_IMPL(__imp__sub_880BD2EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BD2F0"))) PPC_WEAK_FUNC(sub_880BD2F0);
PPC_FUNC_IMPL(__imp__sub_880BD2F0) {
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
	// lwz r7,2304(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r4,88(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 88);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x880bd310
	if (ctx.cr6.eq) goto loc_880BD310;
	// bl 0x88093ae8
	ctx.lr = 0x880BD310;
	sub_88093AE8(ctx, base);
loc_880BD310:
	// lwz r4,92(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 92);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x880bd320
	if (ctx.cr6.eq) goto loc_880BD320;
	// bl 0x88093ae8
	ctx.lr = 0x880BD320;
	sub_88093AE8(ctx, base);
loc_880BD320:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880BD330"))) PPC_WEAK_FUNC(sub_880BD330);
PPC_FUNC_IMPL(__imp__sub_880BD330) {
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
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880BD35C;
	sub_88096BC8(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// beq cr6,0x880bd380
	if (ctx.cr6.eq) goto loc_880BD380;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880BD378;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880bd3e0
	goto loc_880BD3E0;
loc_880BD380:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// bgt 0x880bd3dc
	if (ctx.cr0.gt) goto loc_880BD3DC;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r8,5
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 5, ctx.xer);
	// blt cr6,0x880bd3dc
	if (ctx.cr6.lt) goto loc_880BD3DC;
	// li r10,5
	ctx.r10.s64 = 5;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,64(r8)
	PPC_STORE_U32(ctx.r8.u32 + 64, ctx.r9.u32);
	// bl 0x88096b40
	ctx.lr = 0x880BD3D4;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880bd3e0
	goto loc_880BD3E0;
loc_880BD3DC:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880BD3E0:
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

__attribute__((alias("__imp__sub_880BD3F8"))) PPC_WEAK_FUNC(sub_880BD3F8);
PPC_FUNC_IMPL(__imp__sub_880BD3F8) {
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
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880BD424;
	sub_88096BC8(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// beq cr6,0x880bd448
	if (ctx.cr6.eq) goto loc_880BD448;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880BD440;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880bd49c
	goto loc_880BD49C;
loc_880BD448:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// bgt 0x880bd498
	if (ctx.cr0.gt) goto loc_880BD498;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bgt cr6,0x880bd498
	if (ctx.cr6.gt) goto loc_880BD498;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880BD490;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880bd49c
	goto loc_880BD49C;
loc_880BD498:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880BD49C:
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

__attribute__((alias("__imp__sub_880BD4B4"))) PPC_WEAK_FUNC(sub_880BD4B4);
PPC_FUNC_IMPL(__imp__sub_880BD4B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BD4B8"))) PPC_WEAK_FUNC(sub_880BD4B8);
PPC_FUNC_IMPL(__imp__sub_880BD4B8) {
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
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880BD4E4;
	sub_88096BC8(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// beq cr6,0x880bd508
	if (ctx.cr6.eq) goto loc_880BD508;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880BD500;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880bd564
	goto loc_880BD564;
loc_880BD508:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// bgt 0x880bd560
	if (ctx.cr0.gt) goto loc_880BD560;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bgt cr6,0x880bd560
	if (ctx.cr6.gt) goto loc_880BD560;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
	// bl 0x88096b40
	ctx.lr = 0x880BD558;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880bd564
	goto loc_880BD564;
loc_880BD560:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880BD564:
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

__attribute__((alias("__imp__sub_880BD57C"))) PPC_WEAK_FUNC(sub_880BD57C);
PPC_FUNC_IMPL(__imp__sub_880BD57C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BD580"))) PPC_WEAK_FUNC(sub_880BD580);
PPC_FUNC_IMPL(__imp__sub_880BD580) {
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
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880BD5AC;
	sub_88096BC8(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// beq cr6,0x880bd5d0
	if (ctx.cr6.eq) goto loc_880BD5D0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880BD5C8;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880bd624
	goto loc_880BD624;
loc_880BD5D0:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// bgt 0x880bd620
	if (ctx.cr0.gt) goto loc_880BD620;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r8,7
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 7, ctx.xer);
	// blt cr6,0x880bd620
	if (ctx.cr6.lt) goto loc_880BD620;
	// li r10,7
	ctx.r10.s64 = 7;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880BD618;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880bd624
	goto loc_880BD624;
loc_880BD620:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880BD624:
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

__attribute__((alias("__imp__sub_880BD63C"))) PPC_WEAK_FUNC(sub_880BD63C);
PPC_FUNC_IMPL(__imp__sub_880BD63C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BD640"))) PPC_WEAK_FUNC(sub_880BD640);
PPC_FUNC_IMPL(__imp__sub_880BD640) {
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
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880BD66C;
	sub_88096BC8(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// beq cr6,0x880bd690
	if (ctx.cr6.eq) goto loc_880BD690;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880BD688;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880bd6ec
	goto loc_880BD6EC;
loc_880BD690:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// bge 0x880bd6e8
	if (!ctx.cr0.lt) goto loc_880BD6E8;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r8,12
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 12, ctx.xer);
	// blt cr6,0x880bd6e8
	if (ctx.cr6.lt) goto loc_880BD6E8;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
	// bl 0x88096b40
	ctx.lr = 0x880BD6E0;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880bd6ec
	goto loc_880BD6EC;
loc_880BD6E8:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880BD6EC:
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

__attribute__((alias("__imp__sub_880BD704"))) PPC_WEAK_FUNC(sub_880BD704);
PPC_FUNC_IMPL(__imp__sub_880BD704) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BD708"))) PPC_WEAK_FUNC(sub_880BD708);
PPC_FUNC_IMPL(__imp__sub_880BD708) {
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
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880BD734;
	sub_88096BC8(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// beq cr6,0x880bd758
	if (ctx.cr6.eq) goto loc_880BD758;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880BD750;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880bd7ac
	goto loc_880BD7AC;
loc_880BD758:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// bge 0x880bd7a8
	if (!ctx.cr0.lt) goto loc_880BD7A8;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r8,7
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 7, ctx.xer);
	// blt cr6,0x880bd7a8
	if (ctx.cr6.lt) goto loc_880BD7A8;
	// li r10,7
	ctx.r10.s64 = 7;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880BD7A0;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880bd7ac
	goto loc_880BD7AC;
loc_880BD7A8:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880BD7AC:
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

__attribute__((alias("__imp__sub_880BD7C4"))) PPC_WEAK_FUNC(sub_880BD7C4);
PPC_FUNC_IMPL(__imp__sub_880BD7C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BD7C8"))) PPC_WEAK_FUNC(sub_880BD7C8);
PPC_FUNC_IMPL(__imp__sub_880BD7C8) {
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
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880BD7F4;
	sub_88096BC8(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// beq cr6,0x880bd818
	if (ctx.cr6.eq) goto loc_880BD818;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880BD810;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880bd874
	goto loc_880BD874;
loc_880BD818:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// bgt 0x880bd870
	if (ctx.cr0.gt) goto loc_880BD870;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bgt cr6,0x880bd870
	if (ctx.cr6.gt) goto loc_880BD870;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
	// bl 0x88096b40
	ctx.lr = 0x880BD868;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880bd874
	goto loc_880BD874;
loc_880BD870:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880BD874:
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

__attribute__((alias("__imp__sub_880BD88C"))) PPC_WEAK_FUNC(sub_880BD88C);
PPC_FUNC_IMPL(__imp__sub_880BD88C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BD890"))) PPC_WEAK_FUNC(sub_880BD890);
PPC_FUNC_IMPL(__imp__sub_880BD890) {
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
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880BD8BC;
	sub_88096BC8(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// beq cr6,0x880bd8e0
	if (ctx.cr6.eq) goto loc_880BD8E0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880BD8D8;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880bd934
	goto loc_880BD934;
loc_880BD8E0:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// bgt 0x880bd930
	if (ctx.cr0.gt) goto loc_880BD930;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r8,11
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 11, ctx.xer);
	// blt cr6,0x880bd930
	if (ctx.cr6.lt) goto loc_880BD930;
	// li r10,11
	ctx.r10.s64 = 11;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880BD928;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880bd934
	goto loc_880BD934;
loc_880BD930:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880BD934:
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

__attribute__((alias("__imp__sub_880BD94C"))) PPC_WEAK_FUNC(sub_880BD94C);
PPC_FUNC_IMPL(__imp__sub_880BD94C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BD950"))) PPC_WEAK_FUNC(sub_880BD950);
PPC_FUNC_IMPL(__imp__sub_880BD950) {
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
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// lwz r10,7620(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 7620);
	// addic. r10,r10,-8
	ctx.xer.ca = ctx.r10.u32 > 7;
	ctx.r10.s64 = ctx.r10.s64 + -8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,7620(r11)
	PPC_STORE_U32(ctx.r11.u32 + 7620, ctx.r10.u32);
	// bgt 0x880bd9a0
	if (ctx.cr0.gt) goto loc_880BD9A0;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// stw r10,7620(r11)
	PPC_STORE_U32(ctx.r11.u32 + 7620, ctx.r10.u32);
	// bl 0x880bbeb8
	ctx.lr = 0x880BD984;
	sub_880BBEB8(ctx, base);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// bl 0x88096b40
	ctx.lr = 0x880BD98C;
	sub_88096B40(ctx, base);
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
loc_880BD9A0:
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

__attribute__((alias("__imp__sub_880BD9B4"))) PPC_WEAK_FUNC(sub_880BD9B4);
PPC_FUNC_IMPL(__imp__sub_880BD9B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BD9B8"))) PPC_WEAK_FUNC(sub_880BD9B8);
PPC_FUNC_IMPL(__imp__sub_880BD9B8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x880BD9C0;
	__savegprlr_24(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// li r31,0
	ctx.r31.s64 = 0;
	// lwz r10,184(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// lwz r11,168(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// lis r8,-64
	ctx.r8.s64 = -4194304;
	// li r7,232
	ctx.r7.s64 = 232;
	// add r30,r10,r11
	ctx.r30.u64 = ctx.r10.u64 + ctx.r11.u64;
	// std r31,0(r9)
	PPC_STORE_U64(ctx.r9.u32 + 0, ctx.r31.u64);
	// li r25,5
	ctx.r25.s64 = 5;
	// std r31,8(r9)
	PPC_STORE_U64(ctx.r9.u32 + 8, ctx.r31.u64);
	// lis r26,32
	ctx.r26.s64 = 2097152;
	// std r31,16(r9)
	PPC_STORE_U64(ctx.r9.u32 + 16, ctx.r31.u64);
	// addi r28,r29,8
	ctx.r28.s64 = ctx.r29.s64 + 8;
	// std r31,24(r9)
	PPC_STORE_U64(ctx.r9.u32 + 24, ctx.r31.u64);
	// addi r27,r29,24
	ctx.r27.s64 = ctx.r29.s64 + 24;
	// stw r31,32(r9)
	PPC_STORE_U32(ctx.r9.u32 + 32, ctx.r31.u32);
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r28.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r25,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r25.u32);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// stw r27,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r27.u32);
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// stw r26,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r26.u32);
	// stw r7,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r7.u32);
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r30.u32);
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// bl 0x88093be8
	ctx.lr = 0x880BDA34;
	sub_88093BE8(ctx, base);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lis r5,64
	ctx.r5.s64 = 4194304;
	// stw r3,88(r29)
	PPC_STORE_U32(ctx.r29.u32 + 88, ctx.r3.u32);
	// li r11,280
	ctx.r11.s64 = 280;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// std r31,0(r6)
	PPC_STORE_U64(ctx.r6.u32 + 0, ctx.r31.u64);
	// std r31,8(r6)
	PPC_STORE_U64(ctx.r6.u32 + 8, ctx.r31.u64);
	// std r31,16(r6)
	PPC_STORE_U64(ctx.r6.u32 + 16, ctx.r31.u64);
	// std r31,24(r6)
	PPC_STORE_U64(ctx.r6.u32 + 24, ctx.r31.u64);
	// stw r31,32(r6)
	PPC_STORE_U32(ctx.r6.u32 + 32, ctx.r31.u32);
	// stw r25,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r25.u32);
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r28.u32);
	// stw r27,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r27.u32);
	// stw r5,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// stw r26,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r26.u32);
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r11.u32);
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r30.u32);
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// bl 0x88093be8
	ctx.lr = 0x880BDA84;
	sub_88093BE8(ctx, base);
	// stw r3,92(r29)
	PPC_STORE_U32(ctx.r29.u32 + 92, ctx.r3.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880BDA90"))) PPC_WEAK_FUNC(sub_880BDA90);
PPC_FUNC_IMPL(__imp__sub_880BDA90) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807112c
	ctx.lr = 0x880BDA98;
	__savegprlr_17(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r19,r4
	ctx.r19.u64 = ctx.r4.u64;
	// lwz r24,2304(r3)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r18,r5
	ctx.r18.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880BDAB8;
	sub_88096BC8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,8(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r17,0
	ctx.r17.s64 = 0;
	// li r20,2
	ctx.r20.s64 = 2;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x880bdae4
	if (ctx.cr6.lt) goto loc_880BDAE4;
	// beq cr6,0x880bdb10
	if (ctx.cr6.eq) goto loc_880BDB10;
loc_880BDAD8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8807117c
	__restgprlr_17(ctx, base);
	return;
loc_880BDAE4:
	// lwz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,60(r10)
	PPC_STORE_U32(ctx.r10.u32 + 60, ctx.r11.u32);
	// lwz r9,4(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// stw r11,68(r9)
	PPC_STORE_U32(ctx.r9.u32 + 68, ctx.r11.u32);
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// stw r17,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r17.u32);
	// stw r20,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r20.u32);
	// stw r17,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r17.u32);
	// stw r8,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r8.u32);
loc_880BDB10:
	// lwz r11,16(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r11.u32);
	// bge 0x880bdad8
	if (!ctx.cr0.lt) goto loc_880BDAD8;
	// lwz r11,24(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// lis r9,-30682
	ctx.r9.s64 = -2010775552;
	// lwz r8,20(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// lis r26,-30667
	ctx.r26.s64 = -2009792512;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r7,4(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// addi r9,r9,28200
	ctx.r9.s64 = ctx.r9.s64 + 28200;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lis r25,-30667
	ctx.r25.s64 = -2009792512;
	// rlwinm r11,r5,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r8.u32);
	// lwz r8,12(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// addi r30,r6,1
	ctx.r30.s64 = ctx.r6.s64 + 1;
	// add r31,r11,r9
	ctx.r31.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r7,16(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lis r22,-30667
	ctx.r22.s64 = -2009792512;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// add r28,r8,r11
	ctx.r28.u64 = ctx.r8.u64 + ctx.r11.u64;
	// add r27,r7,r10
	ctx.r27.u64 = ctx.r7.u64 + ctx.r10.u64;
	// stw r28,12364(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12364, ctx.r28.u32);
	// stw r27,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r27.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880BDB84;
	sub_880F52C8(ctx, base);
	// mr r21,r3
	ctx.r21.u64 = ctx.r3.u64;
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x881534c8
	ctx.lr = 0x880BDB90;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,16
	ctx.r3.s64 = 16;
	// addi r23,r11,240
	ctx.r23.s64 = ctx.r11.s64 + 240;
	// bl 0x881534c8
	ctx.lr = 0x880BDBA0;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// addi r4,r11,72
	ctx.r4.s64 = ctx.r11.s64 + 72;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// rlwinm r4,r4,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// bl 0x880f5570
	ctx.lr = 0x880BDBB8;
	sub_880F5570(ctx, base);
	// lwz r11,0(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// lwz r6,7704(r24)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r24.u32 + 7704);
	// lwz r5,7700(r24)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r24.u32 + 7700);
	// lwz r8,2332(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2332);
	// lwz r7,2328(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2328);
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// bl 0x880f5438
	ctx.lr = 0x880BDBD8;
	sub_880F5438(ctx, base);
	// stw r28,12364(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12364, ctx.r28.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r27,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r27.u32);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lis r21,-30667
	ctx.r21.s64 = -2009792512;
	// bl 0x880f52c8
	ctx.lr = 0x880BDBF4;
	sub_880F52C8(ctx, base);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880bdc10
	if (ctx.cr6.eq) goto loc_880BDC10;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r20,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r20.u32);
	// clrlwi r10,r11,16
	ctx.r10.u64 = ctx.r11.u32 & 0xFFFF;
	// stw r10,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r10.u32);
loc_880BDC10:
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x881534c8
	ctx.lr = 0x880BDC18;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,32
	ctx.r3.s64 = 32;
	// addi r11,r11,72
	ctx.r11.s64 = ctx.r11.s64 + 72;
	// rlwinm r31,r11,1,0,30
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// bl 0x881534c8
	ctx.lr = 0x880BDC2C;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// add r11,r11,r23
	ctx.r11.u64 = ctx.r11.u64 + ctx.r23.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// addi r5,r11,-16
	ctx.r5.s64 = ctx.r11.s64 + -16;
	// bl 0x880f5570
	ctx.lr = 0x880BDC44;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x880bdc54
	if (ctx.cr6.eq) goto loc_880BDC54;
	// li r11,112
	ctx.r11.s64 = 112;
	// stw r11,140(r24)
	PPC_STORE_U32(ctx.r24.u32 + 140, ctx.r11.u32);
loc_880BDC54:
	// stw r28,12364(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12364, ctx.r28.u32);
	// li r11,24
	ctx.r11.s64 = 24;
	// stw r27,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r27.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,12380(r22)
	PPC_STORE_U32(ctx.r22.u32 + 12380, ctx.r11.u32);
	// bl 0x880f34b0
	ctx.lr = 0x880BDC70;
	sub_880F34B0(ctx, base);
	// lis r31,-30671
	ctx.r31.s64 = -2010054656;
	// lis r11,16838
	ctx.r11.s64 = 1103495168;
	// lis r10,-1009
	ctx.r10.s64 = -66125824;
	// ori r28,r11,20077
	ctx.r28.u64 = ctx.r11.u64 | 20077;
	// ori r27,r10,49405
	ctx.r27.u64 = ctx.r10.u64 | 49405;
	// lwz r11,4200(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4200);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// mullw r11,r11,r28
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// addi r26,r11,12345
	ctx.r26.s64 = ctx.r11.s64 + 12345;
	// stw r26,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r26.u32);
	// beq cr6,0x880bdcc4
	if (ctx.cr6.eq) goto loc_880BDCC4;
	// lhz r9,4200(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// mulhwu r8,r9,r27
	ctx.r8.u64 = (uint64_t(ctx.r9.u32) * uint64_t(ctx.r27.u32)) >> 32;
	// rlwinm r11,r8,26,6,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 26) & 0x3FFFFFF;
	// rlwinm r10,r11,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r6,r7,r9
	ctx.r6.s64 = ctx.r9.s64 - ctx.r7.s64;
	// extsh r11,r6
	ctx.r11.s64 = ctx.r6.s16;
	// add r11,r11,r23
	ctx.r11.u64 = ctx.r11.u64 + ctx.r23.u64;
	// addi r4,r11,-32
	ctx.r4.s64 = ctx.r11.s64 + -32;
	// sth r4,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, ctx.r4.u16);
loc_880BDCC4:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x880f34b0
	ctx.lr = 0x880BDCD0;
	sub_880F34B0(ctx, base);
	// mullw r11,r26,r28
	ctx.r11.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r28.s32);
	// addi r26,r11,12345
	ctx.r26.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r26,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r26.u32);
	// beq cr6,0x880bdd0c
	if (ctx.cr6.eq) goto loc_880BDD0C;
	// lhz r9,4200(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// mulhwu r8,r9,r27
	ctx.r8.u64 = (uint64_t(ctx.r9.u32) * uint64_t(ctx.r27.u32)) >> 32;
	// rlwinm r11,r8,26,6,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 26) & 0x3FFFFFF;
	// rlwinm r10,r11,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r6,r7,r9
	ctx.r6.s64 = ctx.r9.s64 - ctx.r7.s64;
	// extsh r11,r6
	ctx.r11.s64 = ctx.r6.s16;
	// add r11,r11,r23
	ctx.r11.u64 = ctx.r11.u64 + ctx.r23.u64;
	// addi r4,r11,-32
	ctx.r4.s64 = ctx.r11.s64 + -32;
	// sth r4,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, ctx.r4.u16);
loc_880BDD0C:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r30,12376(r21)
	PPC_STORE_U32(ctx.r21.u32 + 12376, ctx.r30.u32);
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x880f34b0
	ctx.lr = 0x880BDD1C;
	sub_880F34B0(ctx, base);
	// mullw r11,r26,r28
	ctx.r11.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r28.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r11,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r11.u32);
	// beq cr6,0x880bdd58
	if (ctx.cr6.eq) goto loc_880BDD58;
	// lhz r9,4200(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// mulhwu r8,r9,r27
	ctx.r8.u64 = (uint64_t(ctx.r9.u32) * uint64_t(ctx.r27.u32)) >> 32;
	// rlwinm r11,r8,26,6,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 26) & 0x3FFFFFF;
	// rlwinm r10,r11,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r6,r7,r9
	ctx.r6.s64 = ctx.r9.s64 - ctx.r7.s64;
	// extsh r11,r6
	ctx.r11.s64 = ctx.r6.s16;
	// add r11,r11,r23
	ctx.r11.u64 = ctx.r11.u64 + ctx.r23.u64;
	// addi r4,r11,-32
	ctx.r4.s64 = ctx.r11.s64 + -32;
	// sth r4,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, ctx.r4.u16);
loc_880BDD58:
	// lwz r11,24(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r11.u32);
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// blt cr6,0x880bdad8
	if (ctx.cr6.lt) goto loc_880BDAD8;
	// stw r17,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r17.u32);
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// bl 0x88096b40
	ctx.lr = 0x880BDD7C;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8807117c
	__restgprlr_17(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880BDD88"))) PPC_WEAK_FUNC(sub_880BDD88);
PPC_FUNC_IMPL(__imp__sub_880BDD88) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807112c
	ctx.lr = 0x880BDD90;
	__savegprlr_17(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r18,r4
	ctx.r18.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r17,r5
	ctx.r17.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880BDDB0;
	sub_88096BC8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r30,8(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r19,0
	ctx.r19.s64 = 0;
	// li r20,2
	ctx.r20.s64 = 2;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x880bdddc
	if (ctx.cr6.lt) goto loc_880BDDDC;
	// beq cr6,0x880bde3c
	if (ctx.cr6.eq) goto loc_880BDE3C;
loc_880BDDD0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8807117c
	__restgprlr_17(ctx, base);
	return;
loc_880BDDDC:
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r9,3
	ctx.r9.s64 = 3;
	// li r8,48
	ctx.r8.s64 = 48;
	// li r3,16
	ctx.r3.s64 = 16;
	// stw r11,60(r10)
	PPC_STORE_U32(ctx.r10.u32 + 60, ctx.r11.u32);
	// lwz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,68(r7)
	PPC_STORE_U32(ctx.r7.u32 + 68, ctx.r11.u32);
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r9,64(r6)
	PPC_STORE_U32(ctx.r6.u32 + 64, ctx.r9.u32);
	// stw r19,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r19.u32);
	// stw r20,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r20.u32);
	// stw r19,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r19.u32);
	// stw r8,40(r28)
	PPC_STORE_U32(ctx.r28.u32 + 40, ctx.r8.u32);
	// bl 0x881534c8
	ctx.lr = 0x880BDE18;
	sub_881534C8(ctx, base);
	// lwz r5,28(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// extsh r10,r3
	ctx.r10.s64 = ctx.r3.s16;
	// mulli r11,r5,208
	ctx.r11.s64 = ctx.r5.s64 * 208;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r4,r11,251
	ctx.r4.s64 = ctx.r11.s64 + 251;
	// stw r4,44(r28)
	PPC_STORE_U32(ctx.r28.u32 + 44, ctx.r4.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// stw r3,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
loc_880BDE3C:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// bge 0x880bddd0
	if (!ctx.cr0.lt) goto loc_880BDDD0;
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lis r9,-30682
	ctx.r9.s64 = -2010775552;
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addi r29,r30,1
	ctx.r29.s64 = ctx.r30.s64 + 1;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r9,r9,27712
	ctx.r9.s64 = ctx.r9.s64 + 27712;
	// lwz r6,28(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lis r25,-30667
	ctx.r25.s64 = -2009792512;
	// rlwinm r11,r5,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r8.u32);
	// lwz r8,12(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lis r24,-30667
	ctx.r24.s64 = -2009792512;
	// add r30,r11,r9
	ctx.r30.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r7,16(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lis r22,-30667
	ctx.r22.s64 = -2009792512;
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// mullw r11,r11,r6
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r6.s32);
	// add r27,r11,r8
	ctx.r27.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r26,r7,r10
	ctx.r26.u64 = ctx.r7.u64 + ctx.r10.u64;
	// stw r27,12364(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12364, ctx.r27.u32);
	// stw r26,12372(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12372, ctx.r26.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880BDEB8;
	sub_880F52C8(ctx, base);
	// mr r21,r3
	ctx.r21.u64 = ctx.r3.u64;
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x881534c8
	ctx.lr = 0x880BDEC4;
	sub_881534C8(ctx, base);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// extsh r9,r3
	ctx.r9.s64 = ctx.r3.s16;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// li r3,16
	ctx.r3.s64 = 16;
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r7,r8,5,0,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// subf r11,r7,r9
	ctx.r11.s64 = ctx.r9.s64 - ctx.r7.s64;
	// addi r23,r11,240
	ctx.r23.s64 = ctx.r11.s64 + 240;
	// bl 0x881534c8
	ctx.lr = 0x880BDEE8;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// addi r4,r11,72
	ctx.r4.s64 = ctx.r11.s64 + 72;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// bl 0x880f5570
	ctx.lr = 0x880BDEFC;
	sub_880F5570(ctx, base);
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// lwz r6,7704(r28)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r28.u32 + 7704);
	// lwz r5,7700(r28)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r28.u32 + 7700);
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r8,2332(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 2332);
	// lwz r7,2328(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 2328);
	// lwz r4,12(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// bl 0x880f5438
	ctx.lr = 0x880BDF1C;
	sub_880F5438(ctx, base);
	// stw r27,12364(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12364, ctx.r27.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r26,12372(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12372, ctx.r26.u32);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lis r21,-30667
	ctx.r21.s64 = -2009792512;
	// bl 0x880f52c8
	ctx.lr = 0x880BDF38;
	sub_880F52C8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880bdf54
	if (ctx.cr6.eq) goto loc_880BDF54;
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// stw r20,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r20.u32);
	// clrlwi r10,r11,16
	ctx.r10.u64 = ctx.r11.u32 & 0xFFFF;
	// stw r10,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r10.u32);
loc_880BDF54:
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x881534c8
	ctx.lr = 0x880BDF5C;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,32
	ctx.r3.s64 = 32;
	// addi r30,r11,72
	ctx.r30.s64 = ctx.r11.s64 + 72;
	// bl 0x881534c8
	ctx.lr = 0x880BDF6C;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// add r11,r11,r23
	ctx.r11.u64 = ctx.r11.u64 + ctx.r23.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r5,r11,-16
	ctx.r5.s64 = ctx.r11.s64 + -16;
	// bl 0x880f5570
	ctx.lr = 0x880BDF84;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x880bdf94
	if (ctx.cr6.eq) goto loc_880BDF94;
	// li r11,112
	ctx.r11.s64 = 112;
	// stw r11,140(r28)
	PPC_STORE_U32(ctx.r28.u32 + 140, ctx.r11.u32);
loc_880BDF94:
	// stw r27,12364(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12364, ctx.r27.u32);
	// li r11,24
	ctx.r11.s64 = 24;
	// stw r26,12372(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12372, ctx.r26.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,12380(r22)
	PPC_STORE_U32(ctx.r22.u32 + 12380, ctx.r11.u32);
	// bl 0x880f34b0
	ctx.lr = 0x880BDFB0;
	sub_880F34B0(ctx, base);
	// lis r30,-30671
	ctx.r30.s64 = -2010054656;
	// lis r11,16838
	ctx.r11.s64 = 1103495168;
	// lis r10,-1009
	ctx.r10.s64 = -66125824;
	// ori r28,r11,20077
	ctx.r28.u64 = ctx.r11.u64 | 20077;
	// ori r27,r10,49405
	ctx.r27.u64 = ctx.r10.u64 | 49405;
	// lwz r11,4200(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4200);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// mullw r11,r11,r28
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// addi r26,r11,12345
	ctx.r26.s64 = ctx.r11.s64 + 12345;
	// stw r26,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r26.u32);
	// beq cr6,0x880be004
	if (ctx.cr6.eq) goto loc_880BE004;
	// lhz r9,4200(r30)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4200);
	// mulhwu r8,r9,r27
	ctx.r8.u64 = (uint64_t(ctx.r9.u32) * uint64_t(ctx.r27.u32)) >> 32;
	// rlwinm r11,r8,26,6,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 26) & 0x3FFFFFF;
	// rlwinm r10,r11,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r6,r7,r9
	ctx.r6.s64 = ctx.r9.s64 - ctx.r7.s64;
	// extsh r11,r6
	ctx.r11.s64 = ctx.r6.s16;
	// add r11,r11,r23
	ctx.r11.u64 = ctx.r11.u64 + ctx.r23.u64;
	// addi r4,r11,-32
	ctx.r4.s64 = ctx.r11.s64 + -32;
	// sth r4,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, ctx.r4.u16);
loc_880BE004:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x880f34b0
	ctx.lr = 0x880BE010;
	sub_880F34B0(ctx, base);
	// mullw r11,r26,r28
	ctx.r11.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r28.s32);
	// addi r26,r11,12345
	ctx.r26.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r26,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r26.u32);
	// beq cr6,0x880be04c
	if (ctx.cr6.eq) goto loc_880BE04C;
	// lhz r9,4200(r30)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4200);
	// mulhwu r8,r9,r27
	ctx.r8.u64 = (uint64_t(ctx.r9.u32) * uint64_t(ctx.r27.u32)) >> 32;
	// rlwinm r11,r8,26,6,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 26) & 0x3FFFFFF;
	// rlwinm r10,r11,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r6,r7,r9
	ctx.r6.s64 = ctx.r9.s64 - ctx.r7.s64;
	// extsh r11,r6
	ctx.r11.s64 = ctx.r6.s16;
	// add r11,r11,r23
	ctx.r11.u64 = ctx.r11.u64 + ctx.r23.u64;
	// addi r4,r11,-32
	ctx.r4.s64 = ctx.r11.s64 + -32;
	// sth r4,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, ctx.r4.u16);
loc_880BE04C:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r29,12376(r21)
	PPC_STORE_U32(ctx.r21.u32 + 12376, ctx.r29.u32);
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x880f34b0
	ctx.lr = 0x880BE05C;
	sub_880F34B0(ctx, base);
	// mullw r11,r26,r28
	ctx.r11.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r28.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r11,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r11.u32);
	// beq cr6,0x880be098
	if (ctx.cr6.eq) goto loc_880BE098;
	// lhz r9,4200(r30)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4200);
	// mulhwu r8,r9,r27
	ctx.r8.u64 = (uint64_t(ctx.r9.u32) * uint64_t(ctx.r27.u32)) >> 32;
	// rlwinm r11,r8,26,6,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 26) & 0x3FFFFFF;
	// rlwinm r10,r11,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r6,r7,r9
	ctx.r6.s64 = ctx.r9.s64 - ctx.r7.s64;
	// extsh r11,r6
	ctx.r11.s64 = ctx.r6.s16;
	// add r11,r11,r23
	ctx.r11.u64 = ctx.r11.u64 + ctx.r23.u64;
	// addi r4,r11,-32
	ctx.r4.s64 = ctx.r11.s64 + -32;
	// sth r4,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, ctx.r4.u16);
loc_880BE098:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// cmplwi cr6,r11,13
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 13, ctx.xer);
	// blt cr6,0x880bddd0
	if (ctx.cr6.lt) goto loc_880BDDD0;
	// stw r19,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r19.u32);
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// bl 0x88096b40
	ctx.lr = 0x880BE0BC;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8807117c
	__restgprlr_17(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880BE0C8"))) PPC_WEAK_FUNC(sub_880BE0C8);
PPC_FUNC_IMPL(__imp__sub_880BE0C8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880BE0D0;
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
	// bl 0x88096bc8
	ctx.lr = 0x880BE0F0;
	sub_88096BC8(ctx, base);
	// addi r10,r29,5832
	ctx.r10.s64 = ctx.r29.s64 + 5832;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// lwz r8,5896(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 5896);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x880be118
	if (!ctx.cr6.eq) goto loc_880BE118;
	// li r9,5
	ctx.r9.s64 = 5;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_880BE118:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r10,2
	ctx.r10.s64 = 2;
	// lis r8,-30708
	ctx.r8.s64 = -2012479488;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r8,-11472
	ctx.r5.s64 = ctx.r8.s64 + -11472;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,64(r9)
	PPC_STORE_U32(ctx.r9.u32 + 64, ctx.r10.u32);
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x88096c60
	ctx.lr = 0x880BE140;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880BE14C"))) PPC_WEAK_FUNC(sub_880BE14C);
PPC_FUNC_IMPL(__imp__sub_880BE14C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BE150"))) PPC_WEAK_FUNC(sub_880BE150);
PPC_FUNC_IMPL(__imp__sub_880BE150) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880BE158;
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
	// bl 0x88096bc8
	ctx.lr = 0x880BE178;
	sub_88096BC8(ctx, base);
	// addi r10,r29,5832
	ctx.r10.s64 = ctx.r29.s64 + 5832;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// lwz r8,5896(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 5896);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x880be1a0
	if (!ctx.cr6.eq) goto loc_880BE1A0;
	// li r9,5
	ctx.r9.s64 = 5;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_880BE1A0:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r10,2
	ctx.r10.s64 = 2;
	// lis r7,-30708
	ctx.r7.s64 = -2012479488;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r7,-11272
	ctx.r5.s64 = ctx.r7.s64 + -11272;
	// stw r8,64(r9)
	PPC_STORE_U32(ctx.r9.u32 + 64, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x88096c60
	ctx.lr = 0x880BE1CC;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880BE1D8"))) PPC_WEAK_FUNC(sub_880BE1D8);
PPC_FUNC_IMPL(__imp__sub_880BE1D8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880BE1E0;
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
	// bl 0x88096bc8
	ctx.lr = 0x880BE200;
	sub_88096BC8(ctx, base);
	// addi r10,r29,6504
	ctx.r10.s64 = ctx.r29.s64 + 6504;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r9,6568(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 6568);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x880be21c
	if (!ctx.cr6.eq) goto loc_880BE21C;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_880BE21C:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,8
	ctx.r8.s64 = 8;
	// li r7,2
	ctx.r7.s64 = 2;
	// lis r6,-30708
	ctx.r6.s64 = -2012479488;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r9,64(r10)
	PPC_STORE_U32(ctx.r10.u32 + 64, ctx.r9.u32);
	// addi r5,r6,-10880
	ctx.r5.s64 = ctx.r6.s64 + -10880;
	// stw r8,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r7,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r7.u32);
	// bl 0x88096c60
	ctx.lr = 0x880BE24C;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880BE258"))) PPC_WEAK_FUNC(sub_880BE258);
PPC_FUNC_IMPL(__imp__sub_880BE258) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880BE260;
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
	// bl 0x88096bc8
	ctx.lr = 0x880BE280;
	sub_88096BC8(ctx, base);
	// addi r10,r29,6420
	ctx.r10.s64 = ctx.r29.s64 + 6420;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r9,6484(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 6484);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x880be29c
	if (!ctx.cr6.eq) goto loc_880BE29C;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_880BE29C:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,8
	ctx.r8.s64 = 8;
	// li r7,2
	ctx.r7.s64 = 2;
	// lis r6,-30708
	ctx.r6.s64 = -2012479488;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r9,64(r10)
	PPC_STORE_U32(ctx.r10.u32 + 64, ctx.r9.u32);
	// addi r5,r6,-10880
	ctx.r5.s64 = ctx.r6.s64 + -10880;
	// stw r8,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r7,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r7.u32);
	// bl 0x88096c60
	ctx.lr = 0x880BE2CC;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880BE2D8"))) PPC_WEAK_FUNC(sub_880BE2D8);
PPC_FUNC_IMPL(__imp__sub_880BE2D8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880BE2E0;
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
	// bl 0x88096bc8
	ctx.lr = 0x880BE300;
	sub_88096BC8(ctx, base);
	// addi r10,r29,6336
	ctx.r10.s64 = ctx.r29.s64 + 6336;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r9,6400(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 6400);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x880be31c
	if (!ctx.cr6.eq) goto loc_880BE31C;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_880BE31C:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r10,2
	ctx.r10.s64 = 2;
	// lis r7,-30708
	ctx.r7.s64 = -2012479488;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r7,-10880
	ctx.r5.s64 = ctx.r7.s64 + -10880;
	// stw r8,64(r9)
	PPC_STORE_U32(ctx.r9.u32 + 64, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x88096c60
	ctx.lr = 0x880BE348;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880BE354"))) PPC_WEAK_FUNC(sub_880BE354);
PPC_FUNC_IMPL(__imp__sub_880BE354) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BE358"))) PPC_WEAK_FUNC(sub_880BE358);
PPC_FUNC_IMPL(__imp__sub_880BE358) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880BE360;
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
	// bl 0x88096bc8
	ctx.lr = 0x880BE380;
	sub_88096BC8(ctx, base);
	// addi r10,r29,6252
	ctx.r10.s64 = ctx.r29.s64 + 6252;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r9,6316(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 6316);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x880be39c
	if (!ctx.cr6.eq) goto loc_880BE39C;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_880BE39C:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r10,2
	ctx.r10.s64 = 2;
	// lis r7,-30708
	ctx.r7.s64 = -2012479488;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r7,-10880
	ctx.r5.s64 = ctx.r7.s64 + -10880;
	// stw r8,64(r9)
	PPC_STORE_U32(ctx.r9.u32 + 64, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x88096c60
	ctx.lr = 0x880BE3C8;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880BE3D4"))) PPC_WEAK_FUNC(sub_880BE3D4);
PPC_FUNC_IMPL(__imp__sub_880BE3D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BE3D8"))) PPC_WEAK_FUNC(sub_880BE3D8);
PPC_FUNC_IMPL(__imp__sub_880BE3D8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880BE3E0;
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
	// bl 0x88096bc8
	ctx.lr = 0x880BE400;
	sub_88096BC8(ctx, base);
	// addi r10,r29,6168
	ctx.r10.s64 = ctx.r29.s64 + 6168;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r9,6232(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 6232);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x880be41c
	if (!ctx.cr6.eq) goto loc_880BE41C;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_880BE41C:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r8,2
	ctx.r8.s64 = 2;
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r7,-30708
	ctx.r7.s64 = -2012479488;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r7,-10688
	ctx.r5.s64 = ctx.r7.s64 + -10688;
	// stw r8,64(r9)
	PPC_STORE_U32(ctx.r9.u32 + 64, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x88096c60
	ctx.lr = 0x880BE448;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880BE454"))) PPC_WEAK_FUNC(sub_880BE454);
PPC_FUNC_IMPL(__imp__sub_880BE454) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BE458"))) PPC_WEAK_FUNC(sub_880BE458);
PPC_FUNC_IMPL(__imp__sub_880BE458) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880BE460;
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
	// bl 0x88096bc8
	ctx.lr = 0x880BE480;
	sub_88096BC8(ctx, base);
	// addi r10,r29,6084
	ctx.r10.s64 = ctx.r29.s64 + 6084;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r9,6148(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 6148);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x880be49c
	if (!ctx.cr6.eq) goto loc_880BE49C;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_880BE49C:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r8,2
	ctx.r8.s64 = 2;
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r7,-30708
	ctx.r7.s64 = -2012479488;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r7,-10688
	ctx.r5.s64 = ctx.r7.s64 + -10688;
	// stw r8,64(r9)
	PPC_STORE_U32(ctx.r9.u32 + 64, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x88096c60
	ctx.lr = 0x880BE4C8;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880BE4D4"))) PPC_WEAK_FUNC(sub_880BE4D4);
PPC_FUNC_IMPL(__imp__sub_880BE4D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BE4D8"))) PPC_WEAK_FUNC(sub_880BE4D8);
PPC_FUNC_IMPL(__imp__sub_880BE4D8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880BE4E0;
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
	// bl 0x88096bc8
	ctx.lr = 0x880BE500;
	sub_88096BC8(ctx, base);
	// addi r10,r29,6168
	ctx.r10.s64 = ctx.r29.s64 + 6168;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r9,6232(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 6232);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x880be51c
	if (!ctx.cr6.eq) goto loc_880BE51C;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_880BE51C:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r10,2
	ctx.r10.s64 = 2;
	// lis r7,-30708
	ctx.r7.s64 = -2012479488;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r7,-10488
	ctx.r5.s64 = ctx.r7.s64 + -10488;
	// stw r8,64(r9)
	PPC_STORE_U32(ctx.r9.u32 + 64, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x88096c60
	ctx.lr = 0x880BE548;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880BE554"))) PPC_WEAK_FUNC(sub_880BE554);
PPC_FUNC_IMPL(__imp__sub_880BE554) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BE558"))) PPC_WEAK_FUNC(sub_880BE558);
PPC_FUNC_IMPL(__imp__sub_880BE558) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880BE560;
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
	// bl 0x88096bc8
	ctx.lr = 0x880BE580;
	sub_88096BC8(ctx, base);
	// addi r10,r29,6084
	ctx.r10.s64 = ctx.r29.s64 + 6084;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r9,6148(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 6148);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x880be59c
	if (!ctx.cr6.eq) goto loc_880BE59C;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_880BE59C:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r10,2
	ctx.r10.s64 = 2;
	// lis r7,-30708
	ctx.r7.s64 = -2012479488;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r7,-10488
	ctx.r5.s64 = ctx.r7.s64 + -10488;
	// stw r8,64(r9)
	PPC_STORE_U32(ctx.r9.u32 + 64, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x88096c60
	ctx.lr = 0x880BE5C8;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880BE5D4"))) PPC_WEAK_FUNC(sub_880BE5D4);
PPC_FUNC_IMPL(__imp__sub_880BE5D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BE5D8"))) PPC_WEAK_FUNC(sub_880BE5D8);
PPC_FUNC_IMPL(__imp__sub_880BE5D8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880BE5E0;
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
	// bl 0x88096bc8
	ctx.lr = 0x880BE600;
	sub_88096BC8(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r10,r29,5496
	ctx.r10.s64 = ctx.r29.s64 + 5496;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r8,5560(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 5560);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x880be624
	if (!ctx.cr6.eq) goto loc_880BE624;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_880BE624:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r10,2
	ctx.r10.s64 = 2;
	// lis r7,-30708
	ctx.r7.s64 = -2012479488;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r7,-10096
	ctx.r5.s64 = ctx.r7.s64 + -10096;
	// stw r8,64(r9)
	PPC_STORE_U32(ctx.r9.u32 + 64, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x88096c60
	ctx.lr = 0x880BE650;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880BE65C"))) PPC_WEAK_FUNC(sub_880BE65C);
PPC_FUNC_IMPL(__imp__sub_880BE65C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BE660"))) PPC_WEAK_FUNC(sub_880BE660);
PPC_FUNC_IMPL(__imp__sub_880BE660) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880BE668;
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
	// bl 0x88096bc8
	ctx.lr = 0x880BE688;
	sub_88096BC8(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r10,r29,5412
	ctx.r10.s64 = ctx.r29.s64 + 5412;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r8,5476(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 5476);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x880be6ac
	if (!ctx.cr6.eq) goto loc_880BE6AC;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_880BE6AC:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r10,2
	ctx.r10.s64 = 2;
	// lis r7,-30708
	ctx.r7.s64 = -2012479488;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r7,-10096
	ctx.r5.s64 = ctx.r7.s64 + -10096;
	// stw r8,64(r9)
	PPC_STORE_U32(ctx.r9.u32 + 64, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x88096c60
	ctx.lr = 0x880BE6D8;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880BE6E4"))) PPC_WEAK_FUNC(sub_880BE6E4);
PPC_FUNC_IMPL(__imp__sub_880BE6E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BE6E8"))) PPC_WEAK_FUNC(sub_880BE6E8);
PPC_FUNC_IMPL(__imp__sub_880BE6E8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x880BE6F0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r5,56
	ctx.r5.s64 = 56;
	// bl 0x88096bc8
	ctx.lr = 0x880BE714;
	sub_88096BC8(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r31,6000
	ctx.r7.s64 = ctx.r31.s64 + 6000;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r6,33
	ctx.r6.s64 = 33;
	// lwz r10,184(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 184);
	// li r5,60
	ctx.r5.s64 = 60;
	// lwz r11,168(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 168);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r11,r11,3
	ctx.r11.s64 = ctx.r11.s64 + 3;
	// li r4,94
	ctx.r4.s64 = 94;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r11.u32);
	// li r3,5
	ctx.r3.s64 = 5;
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// stw r10,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r10.u32);
	// bl 0x880e32d0
	ctx.lr = 0x880BE758;
	sub_880E32D0(ctx, base);
	// lis r9,-30708
	ctx.r9.s64 = -2012479488;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r5,r9,-9584
	ctx.r5.s64 = ctx.r9.s64 + -9584;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88096c60
	ctx.lr = 0x880BE76C;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880BE778"))) PPC_WEAK_FUNC(sub_880BE778);
PPC_FUNC_IMPL(__imp__sub_880BE778) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x880BE780;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r5,56
	ctx.r5.s64 = 56;
	// bl 0x88096bc8
	ctx.lr = 0x880BE7A4;
	sub_88096BC8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r31,5496
	ctx.r7.s64 = ctx.r31.s64 + 5496;
	// li r3,1
	ctx.r3.s64 = 1;
	// li r6,35
	ctx.r6.s64 = 35;
	// stw r3,28(r9)
	PPC_STORE_U32(ctx.r9.u32 + 28, ctx.r3.u32);
	// li r5,50
	ctx.r5.s64 = 50;
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// li r4,95
	ctx.r4.s64 = 95;
	// stw r7,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r7.u32);
	// li r3,5
	ctx.r3.s64 = 5;
	// lwz r10,184(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 184);
	// lwz r11,168(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 168);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r11,r11,3
	ctx.r11.s64 = ctx.r11.s64 + 3;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r11.u32);
	// bl 0x880e32d0
	ctx.lr = 0x880BE7E8;
	sub_880E32D0(ctx, base);
	// lis r10,-30708
	ctx.r10.s64 = -2012479488;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r5,r10,-8824
	ctx.r5.s64 = ctx.r10.s64 + -8824;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88096c60
	ctx.lr = 0x880BE7FC;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880BE808"))) PPC_WEAK_FUNC(sub_880BE808);
PPC_FUNC_IMPL(__imp__sub_880BE808) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x880BE810;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r5,56
	ctx.r5.s64 = 56;
	// bl 0x88096bc8
	ctx.lr = 0x880BE834;
	sub_88096BC8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r31,5412
	ctx.r7.s64 = ctx.r31.s64 + 5412;
	// li r3,-1
	ctx.r3.s64 = -1;
	// li r6,35
	ctx.r6.s64 = 35;
	// stw r3,28(r9)
	PPC_STORE_U32(ctx.r9.u32 + 28, ctx.r3.u32);
	// li r5,50
	ctx.r5.s64 = 50;
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// li r4,95
	ctx.r4.s64 = 95;
	// stw r7,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r7.u32);
	// li r3,5
	ctx.r3.s64 = 5;
	// lwz r10,184(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 184);
	// lwz r11,168(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 168);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r11,r11,3
	ctx.r11.s64 = ctx.r11.s64 + 3;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r11.u32);
	// bl 0x880e32d0
	ctx.lr = 0x880BE878;
	sub_880E32D0(ctx, base);
	// lis r10,-30708
	ctx.r10.s64 = -2012479488;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r5,r10,-8824
	ctx.r5.s64 = ctx.r10.s64 + -8824;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88096c60
	ctx.lr = 0x880BE88C;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880BE898"))) PPC_WEAK_FUNC(sub_880BE898);
PPC_FUNC_IMPL(__imp__sub_880BE898) {
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
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r8,255
	ctx.r8.s64 = 16711680;
	// li r7,255
	ctx.r7.s64 = 255;
	// ori r6,r8,65535
	ctx.r6.u64 = ctx.r8.u64 | 65535;
	// addi r10,r11,7620
	ctx.r10.s64 = ctx.r11.s64 + 7620;
	// addi r9,r11,7624
	ctx.r9.s64 = ctx.r11.s64 + 7624;
	// stw r6,7624(r11)
	PPC_STORE_U32(ctx.r11.u32 + 7624, ctx.r6.u32);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// lis r5,-30708
	ctx.r5.s64 = -2012479488;
	// stw r7,7620(r11)
	PPC_STORE_U32(ctx.r11.u32 + 7620, ctx.r7.u32);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r5,-16544
	ctx.r5.s64 = ctx.r5.s64 + -16544;
	// li r4,30
	ctx.r4.s64 = 30;
	// bl 0x88096460
	ctx.lr = 0x880BE8F4;
	sub_88096460(ctx, base);
	// lis r4,-30641
	ctx.r4.s64 = -2008088576;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r10,r4,-18844
	ctx.r10.s64 = ctx.r4.s64 + -18844;
	// lis r9,-30708
	ctx.r9.s64 = -2012479488;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r9,-9904
	ctx.r5.s64 = ctx.r9.s64 + -9904;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// bl 0x88096c60
	ctx.lr = 0x880BE918;
	sub_88096C60(ctx, base);
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

__attribute__((alias("__imp__sub_880BE934"))) PPC_WEAK_FUNC(sub_880BE934);
PPC_FUNC_IMPL(__imp__sub_880BE934) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BE938"))) PPC_WEAK_FUNC(sub_880BE938);
PPC_FUNC_IMPL(__imp__sub_880BE938) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880BE93C"))) PPC_WEAK_FUNC(sub_880BE93C);
PPC_FUNC_IMPL(__imp__sub_880BE93C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BE940"))) PPC_WEAK_FUNC(sub_880BE940);
PPC_FUNC_IMPL(__imp__sub_880BE940) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 48);
	// lwz r9,44(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// addi r8,r10,-256
	ctx.r8.s64 = ctx.r10.s64 + -256;
	// clrlwi r10,r9,23
	ctx.r10.u64 = ctx.r9.u32 & 0x1FF;
	// clrlwi r8,r8,23
	ctx.r8.u64 = ctx.r8.u32 & 0x1FF;
	// subf r7,r10,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r10.s64;
	// clrlwi r9,r7,23
	ctx.r9.u64 = ctx.r7.u32 & 0x1FF;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x880be970
	if (!ctx.cr6.eq) goto loc_880BE970;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// b 0x880be9a8
	goto loc_880BE9A8;
loc_880BE970:
	// cmpwi cr6,r9,256
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 256, ctx.xer);
	// blt cr6,0x880be990
	if (ctx.cr6.lt) goto loc_880BE990;
	// subfic r9,r9,512
	ctx.xer.ca = ctx.r9.u32 <= 512;
	ctx.r9.s64 = 512 - ctx.r9.s64;
	// cmplwi cr6,r9,4
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 4, ctx.xer);
	// ble cr6,0x880be9a4
	if (!ctx.cr6.gt) goto loc_880BE9A4;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// clrlwi r10,r10,23
	ctx.r10.u64 = ctx.r10.u32 & 0x1FF;
	// b 0x880be9a8
	goto loc_880BE9A8;
loc_880BE990:
	// cmplwi cr6,r9,4
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 4, ctx.xer);
	// ble cr6,0x880be9a4
	if (!ctx.cr6.gt) goto loc_880BE9A4;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// clrlwi r10,r10,23
	ctx.r10.u64 = ctx.r10.u32 & 0x1FF;
	// b 0x880be9a8
	goto loc_880BE9A8;
loc_880BE9A4:
	// clrlwi r10,r8,16
	ctx.r10.u64 = ctx.r8.u32 & 0xFFFF;
loc_880BE9A8:
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// clrlwi r8,r10,16
	ctx.r8.u64 = ctx.r10.u32 & 0xFFFF;
	// addic. r10,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r10.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r8,44(r11)
	PPC_STORE_U32(ctx.r11.u32 + 44, ctx.r8.u32);
	// stw r10,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r10.u32);
	// bgelr 
	if (!ctx.cr0.lt) return;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// lwz r9,32(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r10.u32);
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// stw r9,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r9.u32);
	// blelr cr6
	if (!ctx.cr6.gt) return;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880BE9E8"))) PPC_WEAK_FUNC(sub_880BE9E8);
PPC_FUNC_IMPL(__imp__sub_880BE9E8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r9,112(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 112);
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

__attribute__((alias("__imp__sub_880BEA28"))) PPC_WEAK_FUNC(sub_880BEA28);
PPC_FUNC_IMPL(__imp__sub_880BEA28) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r11,112(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880bea40
	if (ctx.cr6.eq) goto loc_880BEA40;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
loc_880BEA40:
	// b 0x88094220
	sub_88094220(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880BEA44"))) PPC_WEAK_FUNC(sub_880BEA44);
PPC_FUNC_IMPL(__imp__sub_880BEA44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BEA48"))) PPC_WEAK_FUNC(sub_880BEA48);
PPC_FUNC_IMPL(__imp__sub_880BEA48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x880BEA50;
	__savegprlr_24(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r5)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r5.u32 + 2304);
	// lwz r10,96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r9,184(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 184);
	// lwz r10,168(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 168);
	// add r27,r9,r10
	ctx.r27.u64 = ctx.r9.u64 + ctx.r10.u64;
	// ble cr6,0x880bece8
	if (!ctx.cr6.gt) goto loc_880BECE8;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// subf. r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r9,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r9.u32);
	// bgt 0x880bece8
	if (ctx.cr0.gt) goto loc_880BECE8;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,40
	ctx.r5.s64 = 40;
	// li r4,90
	ctx.r4.s64 = 90;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x880e3240
	ctx.lr = 0x880BEA98;
	sub_880E3240(ctx, base);
	// li r3,14
	ctx.r3.s64 = 14;
	// bl 0x881534c8
	ctx.lr = 0x880BEAA0;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// addic. r11,r11,-7
	ctx.xer.ca = ctx.r11.u32 > 6;
	ctx.r11.s64 = ctx.r11.s64 + -7;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r26,r11,-4
	ctx.r26.s64 = ctx.r11.s64 + -4;
	// blt 0x880beab4
	if (ctx.cr0.lt) goto loc_880BEAB4;
	// addi r26,r11,4
	ctx.r26.s64 = ctx.r11.s64 + 4;
loc_880BEAB4:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lis r29,-30667
	ctx.r29.s64 = -2009792512;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lis r28,-30667
	ctx.r28.s64 = -2009792512;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r11,12364(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12372, ctx.r10.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880BEAD8;
	sub_880F52C8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r25,2
	ctx.r25.s64 = 2;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880beaec
	if (ctx.cr6.eq) goto loc_880BEAEC;
	// stw r25,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r25.u32);
loc_880BEAEC:
	// lwz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// rlwinm r10,r26,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,36(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bl 0x880f5570
	ctx.lr = 0x880BEB04;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x880beb14
	if (ctx.cr6.eq) goto loc_880BEB14;
	// li r11,144
	ctx.r11.s64 = 144;
	// stw r11,140(r30)
	PPC_STORE_U32(ctx.r30.u32 + 140, ctx.r11.u32);
loc_880BEB14:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,12364(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12372, ctx.r10.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880BEB30;
	sub_880F52C8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880beb40
	if (ctx.cr6.eq) goto loc_880BEB40;
	// stw r25,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r25.u32);
loc_880BEB40:
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r5,40(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// srawi r10,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 1;
	// addze r4,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r4.s64 = temp.s64;
	// bl 0x880f5570
	ctx.lr = 0x880BEB58;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x880beb6c
	if (ctx.cr6.eq) goto loc_880BEB6C;
	// li r11,80
	ctx.r11.s64 = 80;
	// stw r25,112(r30)
	PPC_STORE_U32(ctx.r30.u32 + 112, ctx.r25.u32);
	// stw r11,140(r30)
	PPC_STORE_U32(ctx.r30.u32 + 140, ctx.r11.u32);
loc_880BEB6C:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lis r8,-30667
	ctx.r8.s64 = -2009792512;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lis r7,-30667
	ctx.r7.s64 = -2009792512;
	// li r24,0
	ctx.r24.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,12364(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12364, ctx.r11.u32);
	// mr r9,r24
	ctx.r9.u64 = ctx.r24.u64;
	// stw r10,12372(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12372, ctx.r10.u32);
	// stw r24,12380(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12380, ctx.r24.u32);
	// stw r27,12376(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12376, ctx.r27.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880BEBA0;
	sub_880F52C8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880bebb0
	if (ctx.cr6.eq) goto loc_880BEBB0;
	// stw r25,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r25.u32);
loc_880BEBB0:
	// li r3,63
	ctx.r3.s64 = 63;
	// bl 0x881534c8
	ctx.lr = 0x880BEBB8;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r4,20
	ctx.r4.s64 = 20;
	// rlwinm r5,r11,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880f5570
	ctx.lr = 0x880BEBCC;
	sub_880F5570(ctx, base);
	// li r29,1
	ctx.r29.s64 = 1;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x880bebe4
	if (ctx.cr6.eq) goto loc_880BEBE4;
	// li r11,64
	ctx.r11.s64 = 64;
	// stw r29,112(r30)
	PPC_STORE_U32(ctx.r30.u32 + 112, ctx.r29.u32);
	// stw r11,140(r30)
	PPC_STORE_U32(ctx.r30.u32 + 140, ctx.r11.u32);
loc_880BEBE4:
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r10,152(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 152);
	// lwz r28,16(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r27,20(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r26,26276(r11)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
	// bne cr6,0x880bec48
	if (!ctx.cr6.eq) goto loc_880BEC48;
	// lwz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// bne cr6,0x880bec48
	if (!ctx.cr6.eq) goto loc_880BEC48;
	// lwz r10,96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// clrlwi r7,r11,16
	ctx.r7.u64 = ctx.r11.u32 & 0xFFFF;
	// li r6,-7
	ctx.r6.s64 = -7;
	// sth r24,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r24.u16);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r3,25
	ctx.r3.s64 = 25;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x8815c948
	ctx.lr = 0x880BEC30;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x8815c860
	ctx.lr = 0x880BEC3C;
	sub_8815C860(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x880bec48
	if (ctx.cr6.eq) goto loc_880BEC48;
	// sth r29,16(r30)
	PPC_STORE_U16(ctx.r30.u32 + 16, ctx.r29.u16);
loc_880BEC48:
	// lwz r11,152(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 152);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x880becc0
	if (!ctx.cr6.eq) goto loc_880BECC0;
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// bne cr6,0x880becc0
	if (!ctx.cr6.eq) goto loc_880BECC0;
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// lwz r9,96(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// li r6,-1
	ctx.r6.s64 = -1;
	// sth r29,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r29.u16);
	// li r8,8
	ctx.r8.s64 = 8;
	// stw r29,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r29.u32);
	// stw r6,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r6.u32);
	// clrlwi r7,r10,16
	ctx.r7.u64 = ctx.r10.u32 & 0xFFFF;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// lwz r11,156(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 156);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r3,25
	ctx.r3.s64 = 25;
	// stw r29,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r29.u32);
	// subfic r11,r11,1
	ctx.xer.ca = ctx.r11.u32 <= 1;
	ctx.r11.s64 = 1 - ctx.r11.s64;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// extsh r6,r11
	ctx.r6.s64 = ctx.r11.s16;
	// bl 0x8815c948
	ctx.lr = 0x880BECA8;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x8815c860
	ctx.lr = 0x880BECB4;
	sub_8815C860(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x880becc0
	if (ctx.cr6.eq) goto loc_880BECC0;
	// sth r29,16(r30)
	PPC_STORE_U16(ctx.r30.u32 + 16, ctx.r29.u16);
loc_880BECC0:
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r11,112(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880becd8
	if (ctx.cr6.eq) goto loc_880BECD8;
	// stw r24,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r24.u32);
loc_880BECD8:
	// bl 0x88094220
	ctx.lr = 0x880BECDC;
	sub_88094220(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
loc_880BECE8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880BECF4"))) PPC_WEAK_FUNC(sub_880BECF4);
PPC_FUNC_IMPL(__imp__sub_880BECF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BECF8"))) PPC_WEAK_FUNC(sub_880BECF8);
PPC_FUNC_IMPL(__imp__sub_880BECF8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807113c
	ctx.lr = 0x880BED00;
	__savegprlr_21(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r11,-30682
	ctx.r11.s64 = -2010775552;
	// lwz r9,184(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// li r21,0
	ctx.r21.s64 = 0;
	// addi r29,r11,29056
	ctx.r29.s64 = ctx.r11.s64 + 29056;
	// lwz r10,168(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// li r26,1
	ctx.r26.s64 = 1;
	// addi r8,r29,-13812
	ctx.r8.s64 = ctx.r29.s64 + -13812;
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// add r25,r9,r10
	ctx.r25.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r7,24(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r6,r11,8
	ctx.r6.s64 = ctx.r11.s64 + 8;
	// srawi r5,r6,4
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xF) != 0);
	ctx.r5.s64 = ctx.r6.s32 >> 4;
	// lbzx r4,r7,r8
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r8.u32);
	// clrlwi r11,r5,27
	ctx.r11.u64 = ctx.r5.u32 & 0x1F;
	// extsb r9,r4
	ctx.r9.s64 = ctx.r4.s8;
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// blt cr6,0x880bed58
	if (ctx.cr6.lt) goto loc_880BED58;
	// subfic r11,r11,32
	ctx.xer.ca = ctx.r11.u32 <= 32;
	ctx.r11.s64 = 32 - ctx.r11.s64;
	// li r21,1
	ctx.r21.s64 = 1;
	// li r26,-1
	ctx.r26.s64 = -1;
loc_880BED58:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r27,r29,1
	ctx.r27.s64 = ctx.r29.s64 + 1;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addi r6,r25,-1
	ctx.r6.s64 = ctx.r25.s64 + -1;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r30,r11,1,0,30
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addis r28,r11,1
	ctx.r28.s64 = ctx.r11.s64 + 65536;
	// addi r28,r28,-31537
	ctx.r28.s64 = ctx.r28.s64 + -31537;
	// lbzx r11,r30,r29
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r29.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lbzx r9,r30,r27
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r27.u32);
	// extsb r7,r11
	ctx.r7.s64 = ctx.r11.s8;
	// extsb r11,r9
	ctx.r11.s64 = ctx.r9.s8;
	// mullw r9,r7,r26
	ctx.r9.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r26.s32);
	// addi r5,r9,24
	ctx.r5.s64 = ctx.r9.s64 + 24;
	// addi r4,r11,-88
	ctx.r4.s64 = ctx.r11.s64 + -88;
	// rlwinm r9,r5,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r4,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r9,r8
	ctx.r4.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x880BEDB4;
	sub_881538C0(ctx, base);
	// lis r11,547
	ctx.r11.s64 = 35848192;
	// lis r24,-30597
	ctx.r24.s64 = -2005204992;
	// ori r23,r11,32768
	ctx.r23.u64 = ctx.r11.u64 | 32768;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880bedf4
	if (ctx.cr6.eq) goto loc_880BEDF4;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r21,26,0,5
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 26) & 0xFC000000;
	// lwz r11,-11932(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + -11932);
	// li r8,0
	ctx.r8.s64 = 0;
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// addi r22,r11,1
	ctx.r22.s64 = ctx.r11.s64 + 1;
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// or r6,r7,r23
	ctx.r6.u64 = ctx.r7.u64 | ctx.r23.u64;
	// stw r22,-11932(r24)
	PPC_STORE_U32(ctx.r24.u32 + -11932, ctx.r22.u32);
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// b 0x880bedf8
	goto loc_880BEDF8;
loc_880BEDF4:
	// lwz r22,-11932(r24)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r24.u32 + -11932);
loc_880BEDF8:
	// lbzx r11,r30,r29
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r29.u32);
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// lbzx r10,r30,r27
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r27.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// extsb r9,r11
	ctx.r9.s64 = ctx.r11.s8;
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// extsb r7,r10
	ctx.r7.s64 = ctx.r10.s8;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// mullw r5,r9,r26
	ctx.r5.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r26.s32);
	// rlwinm r9,r5,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r7,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r9,r8
	ctx.r4.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x880BEE30;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880bee50
	if (ctx.cr6.eq) goto loc_880BEE50;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r21,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// lwz r8,116(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
loc_880BEE50:
	// lbzx r11,r30,r29
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r29.u32);
	// li r6,217
	ctx.r6.s64 = 217;
	// lbzx r10,r30,r27
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r27.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// extsb r9,r11
	ctx.r9.s64 = ctx.r11.s8;
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// extsb r7,r10
	ctx.r7.s64 = ctx.r10.s8;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// mullw r5,r9,r26
	ctx.r5.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r26.s32);
	// rlwinm r9,r5,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r7,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r9,r8
	ctx.r4.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x880BEE88;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880beeb8
	if (ctx.cr6.eq) goto loc_880BEEB8;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r21,26,0,5
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 26) & 0xFC000000;
	// addi r11,r22,1
	ctx.r11.s64 = ctx.r22.s64 + 1;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r11,-11932(r24)
	PPC_STORE_U32(ctx.r24.u32 + -11932, ctx.r11.u32);
	// or r7,r8,r23
	ctx.r7.u64 = ctx.r8.u64 | ctx.r23.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// lwz r6,116(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r6,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r6.u32);
loc_880BEEB8:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8807118c
	__restgprlr_21(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880BEEC0"))) PPC_WEAK_FUNC(sub_880BEEC0);
PPC_FUNC_IMPL(__imp__sub_880BEEC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x880BEEC8;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,15696(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15696);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880bf024
	if (ctx.cr6.eq) goto loc_880BF024;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lis r29,-30667
	ctx.r29.s64 = -2009792512;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lis r28,-30667
	ctx.r28.s64 = -2009792512;
	// lis r7,-30671
	ctx.r7.s64 = -2010054656;
	// lwz r6,96(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// lis r5,16838
	ctx.r5.s64 = 1103495168;
	// lis r27,-30667
	ctx.r27.s64 = -2009792512;
	// stw r11,12364(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12364, ctx.r11.u32);
	// ori r4,r5,20077
	ctx.r4.u64 = ctx.r5.u64 | 20077;
	// stw r10,12372(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12372, ctx.r10.u32);
	// lis r26,-30667
	ctx.r26.s64 = -2009792512;
	// lwz r11,4200(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4200);
	// li r24,0
	ctx.r24.s64 = 0;
	// lwz r9,184(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 184);
	// li r3,0
	ctx.r3.s64 = 0;
	// mullw r8,r11,r4
	ctx.r8.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r4.s32);
	// lwz r11,168(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 168);
	// stw r24,12380(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12380, ctx.r24.u32);
	// add r4,r9,r11
	ctx.r4.u64 = ctx.r9.u64 + ctx.r11.u64;
	// addi r11,r8,12345
	ctx.r11.s64 = ctx.r8.s64 + 12345;
	// mr r10,r24
	ctx.r10.u64 = ctx.r24.u64;
	// stw r4,12376(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12376, ctx.r4.u32);
	// stw r11,4200(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4200, ctx.r11.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880BEF48;
	sub_880F52C8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880bef5c
	if (ctx.cr6.eq) goto loc_880BEF5C;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r11.u32);
loc_880BEF5C:
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r5,40(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// srawi r10,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 1;
	// addze r4,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r4.s64 = temp.s64;
	// bl 0x880f5570
	ctx.lr = 0x880BEF74;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x880bef84
	if (ctx.cr6.eq) goto loc_880BEF84;
	// li r11,80
	ctx.r11.s64 = 80;
	// stw r11,140(r30)
	PPC_STORE_U32(ctx.r30.u32 + 140, ctx.r11.u32);
loc_880BEF84:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,15696(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15696);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x880befb4
	if (!ctx.cr6.eq) goto loc_880BEFB4;
	// lwz r10,96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r8,15712(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15712);
	// lwz r7,15708(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15708);
	// lwz r6,15704(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15704);
	// lwz r5,15700(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15700);
	// lwz r4,12(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// bl 0x880f5438
	ctx.lr = 0x880BEFB4;
	sub_880F5438(ctx, base);
loc_880BEFB4:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,15696(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15696);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x880bf000
	if (!ctx.cr6.eq) goto loc_880BF000;
	// lwz r11,15700(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15700);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880bf000
	if (!ctx.cr6.eq) goto loc_880BF000;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// li r8,140
	ctx.r8.s64 = 140;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,140
	ctx.r4.s64 = 140;
	// stw r24,12380(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12380, ctx.r24.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r8,12376(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12376, ctx.r8.u32);
	// mr r9,r24
	ctx.r9.u64 = ctx.r24.u64;
	// stw r11,12364(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12372, ctx.r10.u32);
	// bl 0x881607f8
	ctx.lr = 0x880BF000;
	sub_881607F8(ctx, base);
loc_880BF000:
	// lwz r11,2304(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 2304);
	// lwz r11,112(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880bf014
	if (ctx.cr6.eq) goto loc_880BF014;
	// stw r24,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r24.u32);
loc_880BF014:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x88094220
	ctx.lr = 0x880BF01C;
	sub_88094220(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
loc_880BF024:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x880be940
	ctx.lr = 0x880BF02C;
	sub_880BE940(ctx, base);
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// lis r7,-30597
	ctx.r7.s64 = -2005204992;
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// li r24,0
	ctx.r24.s64 = 0;
	// addi r11,r11,9552
	ctx.r11.s64 = ctx.r11.s64 + 9552;
	// lwz r10,26272(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26272);
	// lwz r6,-11984(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + -11984);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwz r5,40(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// lwz r4,36(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// clrlwi r10,r5,23
	ctx.r10.u64 = ctx.r5.u32 & 0x1FF;
	// addi r3,r10,128
	ctx.r3.s64 = ctx.r10.s64 + 128;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r3,2,21,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x7FC;
	// lwzx r5,r10,r11
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// lwzx r3,r7,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r11.u32);
	// mullw r10,r5,r4
	ctx.r10.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r4.s32);
	// mullw r7,r3,r4
	ctx.r7.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r4.s32);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r9,r7,r8
	ctx.r9.u64 = ctx.r7.u64 + ctx.r8.u64;
	// stw r10,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r10.u32);
	// stw r9,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
	// beq cr6,0x880bf098
	if (ctx.cr6.eq) goto loc_880BF098;
	// mr r10,r24
	ctx.r10.u64 = ctx.r24.u64;
	// b 0x880bf0a8
	goto loc_880BF0A8;
loc_880BF098:
	// lwz r10,108(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// addi r10,r10,51
	ctx.r10.s64 = ctx.r10.s64 + 51;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r8,r6
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r6.u32);
loc_880BF0A8:
	// lis r7,-30643
	ctx.r7.s64 = -2008219648;
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// stw r8,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r8.u32);
	// lwz r5,26428(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 26428);
	// clrlwi r4,r5,31
	ctx.r4.u64 = ctx.r5.u32 & 0x1;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x880bf0d4
	if (ctx.cr6.eq) goto loc_880BF0D4;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
loc_880BF0D4:
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lis r7,16
	ctx.r7.s64 = 1048576;
	// lwz r4,52(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addi r3,r10,-256
	ctx.r3.s64 = ctx.r10.s64 + -256;
	// clrlwi r10,r3,23
	ctx.r10.u64 = ctx.r3.u32 & 0x1FF;
	// addi r3,r10,128
	ctx.r3.s64 = ctx.r10.s64 + 128;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r3,r3,2,21,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x7FC;
	// lwzx r10,r10,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// lwzx r3,r3,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r11.u32);
	// mullw r10,r10,r4
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r4.s32);
	// mullw r11,r3,r4
	ctx.r11.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r4.s32);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r9,r10,r8
	ctx.r9.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add. r10,r11,r7
	ctx.r10.u64 = ctx.r11.u64 + ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stw r9,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r9.u32);
	// lwz r11,100(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 100);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r4,r9,-1
	ctx.r4.s64 = ctx.r9.s64 + -1;
	// and r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 & ctx.r11.u64;
	// ble 0x880bf178
	if (!ctx.cr0.gt) goto loc_880BF178;
	// lis r9,32
	ctx.r9.s64 = 2097152;
	// lis r4,320
	ctx.r4.s64 = 20971520;
	// subf r3,r9,r10
	ctx.r3.s64 = ctx.r10.s64 - ctx.r9.s64;
	// cmpw cr6,r3,r4
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r4.s32, ctx.xer);
	// bge cr6,0x880bf178
	if (!ctx.cr6.lt) goto loc_880BF178;
	// addi r11,r11,55
	ctx.r11.s64 = ctx.r11.s64 + 55;
	// lis r10,-40
	ctx.r10.s64 = -2621440;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r4,r6
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r6.u32);
	// add r3,r11,r8
	ctx.r3.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r11,r3,r7
	ctx.r11.u64 = ctx.r3.u64 + ctx.r7.u64;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x880bf178
	if (!ctx.cr6.gt) goto loc_880BF178;
	// lis r10,280
	ctx.r10.s64 = 18350080;
	// subf r9,r9,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r9.s64;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x880bf19c
	if (ctx.cr6.lt) goto loc_880BF19C;
loc_880BF178:
	// lwz r11,2304(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 2304);
	// lwz r11,112(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880bf18c
	if (ctx.cr6.eq) goto loc_880BF18C;
	// stw r24,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r24.u32);
loc_880BF18C:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x88094220
	ctx.lr = 0x880BF194;
	sub_88094220(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
loc_880BF19C:
	// lwz r11,112(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880bf23c
	if (ctx.cr6.eq) goto loc_880BF23C;
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// mr r10,r24
	ctx.r10.u64 = ctx.r24.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880bf1d0
	if (ctx.cr6.eq) goto loc_880BF1D0;
loc_880BF1B8:
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// stw r24,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r24.u32);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880bf1b8
	if (!ctx.cr6.eq) goto loc_880BF1B8;
loc_880BF1D0:
	// lis r11,128
	ctx.r11.s64 = 8388608;
	// clrlwi r10,r10,20
	ctx.r10.u64 = ctx.r10.u32 & 0xFFF;
	// ori r9,r11,32896
	ctx.r9.u64 = ctx.r11.u64 | 32896;
	// rlwinm r10,r10,0,26,21
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFC3F;
	// stw r9,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r9.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x880bf218
	if (ctx.cr6.eq) goto loc_880BF218;
	// lwz r11,120(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r9,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r9.u32);
	// beq cr6,0x880bf23c
	if (ctx.cr6.eq) goto loc_880BF23C;
	// lis r11,192
	ctx.r11.s64 = 12582912;
	// ori r10,r11,49152
	ctx.r10.u64 = ctx.r11.u64 | 49152;
	// stw r10,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r10.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
loc_880BF218:
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// cmpwi cr6,r11,64
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 64, ctx.xer);
	// bge cr6,0x880bf23c
	if (!ctx.cr6.lt) goto loc_880BF23C;
	// rlwinm r11,r5,0,28,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xE;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880bf23c
	if (!ctx.cr6.eq) goto loc_880BF23C;
	// lis r11,255
	ctx.r11.s64 = 16711680;
	// ori r10,r11,4112
	ctx.r10.u64 = ctx.r11.u64 | 4112;
	// stw r10,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r10.u32);
loc_880BF23C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880BF244"))) PPC_WEAK_FUNC(sub_880BF244);
PPC_FUNC_IMPL(__imp__sub_880BF244) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BF248"))) PPC_WEAK_FUNC(sub_880BF248);
PPC_FUNC_IMPL(__imp__sub_880BF248) {
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
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r11,80
	ctx.r11.s64 = 5242880;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmpw cr6,r5,r11
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x880bf318
	if (!ctx.cr6.gt) goto loc_880BF318;
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880bf2f8
	if (ctx.cr6.eq) goto loc_880BF2F8;
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// bge 0x880bf318
	if (!ctx.cr0.lt) goto loc_880BF318;
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// stw r11,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// bl 0x88095590
	ctx.lr = 0x880BF2A0;
	sub_88095590(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x880bf318
	if (ctx.cr6.lt) goto loc_880BF318;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26276(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880bf318
	if (!ctx.cr6.eq) goto loc_880BF318;
	// clrlwi r7,r3,16
	ctx.r7.u64 = ctx.r3.u32 & 0xFFFF;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// li r6,-16
	ctx.r6.s64 = -16;
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// li r3,17
	ctx.r3.s64 = 17;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// sth r11,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r11.u16);
	// bl 0x8815c948
	ctx.lr = 0x880BF2D8;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8815c860
	ctx.lr = 0x880BF2E4;
	sub_8815C860(ctx, base);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x880bf318
	if (ctx.cr6.eq) goto loc_880BF318;
	// li r11,1
	ctx.r11.s64 = 1;
	// sth r11,16(r31)
	PPC_STORE_U16(ctx.r31.u32 + 16, ctx.r11.u16);
	// b 0x880bf318
	goto loc_880BF318;
loc_880BF2F8:
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// bge 0x880bf318
	if (!ctx.cr0.lt) goto loc_880BF318;
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// stw r10,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r10.u32);
loc_880BF318:
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

__attribute__((alias("__imp__sub_880BF330"))) PPC_WEAK_FUNC(sub_880BF330);
PPC_FUNC_IMPL(__imp__sub_880BF330) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x880BF338;
	__savegprlr_24(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30708
	ctx.r11.s64 = -2012479488;
	// li r4,156
	ctx.r4.s64 = 156;
	// addi r5,r11,-3280
	ctx.r5.s64 = ctx.r11.s64 + -3280;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x880BF350;
	sub_88094290(ctx, base);
	// li r5,156
	ctx.r5.s64 = 156;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,2304(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2304);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x880BF364;
	sub_88073BD0(ctx, base);
	// lwz r10,32(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// addi r11,r30,120
	ctx.r11.s64 = ctx.r30.s64 + 120;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r27,r31,16
	ctx.r27.s64 = ctx.r31.s64 + 16;
	// addi r24,r31,44
	ctx.r24.s64 = ctx.r31.s64 + 44;
	// stw r10,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r10.u32);
	// lwz r9,36(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// stw r9,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
	// lwz r8,148(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 148);
	// lwz r7,2304(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2304);
	// stw r7,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
	// lwz r6,148(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 148);
	// stw r6,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r6.u32);
	// lwz r5,132(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 132);
	// stw r5,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r5.u32);
	// rotlwi r5,r9,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// lwz r4,136(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 136);
	// rotlwi r11,r4,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 0);
	// stw r4,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r4.u32);
	// rotlwi r4,r10,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r10,140(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 140);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// bl 0x88095590
	ctx.lr = 0x880BF3C4;
	sub_88095590(ctx, base);
	// li r28,1
	ctx.r28.s64 = 1;
	// li r29,0
	ctx.r29.s64 = 0;
	// stw r3,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r3.u32);
	// li r25,2
	ctx.r25.s64 = 2;
	// stw r28,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r28.u32);
	// li r9,128
	ctx.r9.s64 = 128;
	// stw r30,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r30.u32);
	// li r8,125
	ctx.r8.s64 = 125;
	// stw r29,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r29.u32);
	// stw r25,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r25.u32);
	// li r26,16
	ctx.r26.s64 = 16;
	// stw r28,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r28.u32);
	// stw r28,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r28.u32);
	// stw r9,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r9.u32);
	// stw r29,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r29.u32);
	// stw r8,168(r30)
	PPC_STORE_U32(ctx.r30.u32 + 168, ctx.r8.u32);
	// lwz r7,128(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x880bf480
	if (ctx.cr6.eq) goto loc_880BF480;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x881556a0
	ctx.lr = 0x880BF41C;
	sub_881556A0(ctx, base);
	// lis r11,-30708
	ctx.r11.s64 = -2012479488;
	// stw r3,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r3.u32);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// addi r9,r11,-5560
	ctx.r9.s64 = ctx.r11.s64 + -5560;
	// stw r30,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r30.u32);
	// stw r9,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r9.u32);
	// lwz r8,112(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// stw r28,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r28.u32);
	// lwz r9,112(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// lwz r11,28(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880bf464
	if (ctx.cr6.eq) goto loc_880BF464;
loc_880BF44C:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880bf4e8
	if (ctx.cr6.eq) goto loc_880BF4E8;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880bf44c
	if (!ctx.cr6.eq) goto loc_880BF44C;
loc_880BF464:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_880BF468:
	// stw r27,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r27.u32);
	// stw r28,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r28.u32);
	// stw r26,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r26.u32);
	// stw r26,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r26.u32);
	// stw r26,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r26.u32);
	// stw r26,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r26.u32);
loc_880BF480:
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// li r10,256
	ctx.r10.s64 = 256;
	// li r9,3
	ctx.r9.s64 = 3;
	// stw r10,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r10.u32);
	// lwz r11,-11984(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11984);
	// lwz r11,84(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// stw r11,152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 152, ctx.r11.u32);
	// blt cr6,0x880bf534
	if (ctx.cr6.lt) goto loc_880BF534;
	// beq cr6,0x880bf500
	if (ctx.cr6.eq) goto loc_880BF500;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x880bf570
	if (!ctx.cr6.lt) goto loc_880BF570;
	// lis r10,-30708
	ctx.r10.s64 = -2012479488;
	// stw r29,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r29.u32);
	// li r11,8
	ctx.r11.s64 = 8;
	// stw r29,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r29.u32);
	// li r8,80
	ctx.r8.s64 = 80;
	// stw r9,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r9.u32);
	// li r7,64
	ctx.r7.s64 = 64;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// addi r6,r10,-3512
	ctx.r6.s64 = ctx.r10.s64 + -3512;
	// stw r8,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r8.u32);
	// stw r7,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r7.u32);
	// stw r11,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// stw r6,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r6.u32);
	// b 0x880bf570
	goto loc_880BF570;
loc_880BF4E8:
	// lwz r10,24(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880bf4f8
	if (ctx.cr6.eq) goto loc_880BF4F8;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_880BF4F8:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x880bf468
	goto loc_880BF468;
loc_880BF500:
	// lis r11,-30708
	ctx.r11.s64 = -2012479488;
	// stw r10,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r10.u32);
	// li r10,24
	ctx.r10.s64 = 24;
	// stw r29,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r29.u32);
	// li r8,64
	ctx.r8.s64 = 64;
	// stw r26,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r26.u32);
	// addi r7,r11,-5832
	ctx.r7.s64 = ctx.r11.s64 + -5832;
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// stw r8,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r8.u32);
	// stw r29,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r29.u32);
	// stw r28,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r28.u32);
	// stw r7,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r7.u32);
	// b 0x880bf570
	goto loc_880BF570;
loc_880BF534:
	// lwz r11,140(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// li r8,64
	ctx.r8.s64 = 64;
	// li r7,8
	ctx.r7.s64 = 8;
	// stw r10,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r10.u32);
	// stw r29,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r29.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r8,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r8.u32);
	// stw r29,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r29.u32);
	// stw r7,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r7.u32);
	// stw r29,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r29.u32);
	// stw r25,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r25.u32);
	// bne cr6,0x880bf570
	if (!ctx.cr6.eq) goto loc_880BF570;
	// lis r11,-30708
	ctx.r11.s64 = -2012479488;
	// addi r10,r11,-5832
	ctx.r10.s64 = ctx.r11.s64 + -5832;
	// stw r10,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r10.u32);
loc_880BF570:
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lwz r10,184(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 184);
	// lwz r11,168(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 168);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// std r29,0(r8)
	PPC_STORE_U64(ctx.r8.u32 + 0, ctx.r29.u64);
	// addi r7,r11,-1
	ctx.r7.s64 = ctx.r11.s64 + -1;
	// std r29,8(r8)
	PPC_STORE_U64(ctx.r8.u32 + 8, ctx.r29.u64);
	// std r29,16(r8)
	PPC_STORE_U64(ctx.r8.u32 + 16, ctx.r29.u64);
	// std r29,24(r8)
	PPC_STORE_U64(ctx.r8.u32 + 24, ctx.r29.u64);
	// stw r29,32(r8)
	PPC_STORE_U32(ctx.r8.u32 + 32, ctx.r29.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// stw r7,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// stw r27,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r27.u32);
	// stw r24,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r24.u32);
	// bl 0x88093be8
	ctx.lr = 0x880BF5B4;
	sub_88093BE8(ctx, base);
	// lis r6,-30708
	ctx.r6.s64 = -2012479488;
	// lis r5,-30708
	ctx.r5.s64 = -2012479488;
	// stw r3,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r3.u32);
	// lis r4,-30708
	ctx.r4.s64 = -2012479488;
	// addi r3,r6,-4416
	ctx.r3.s64 = ctx.r6.s64 + -4416;
	// addi r11,r5,-4872
	ctx.r11.s64 = ctx.r5.s64 + -4872;
	// addi r10,r4,-5656
	ctx.r10.s64 = ctx.r4.s64 + -5656;
	// stw r3,64(r30)
	PPC_STORE_U32(ctx.r30.u32 + 64, ctx.r3.u32);
	// stw r11,68(r30)
	PPC_STORE_U32(ctx.r30.u32 + 68, ctx.r11.u32);
	// stw r10,84(r30)
	PPC_STORE_U32(ctx.r30.u32 + 84, ctx.r10.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880BF5E4"))) PPC_WEAK_FUNC(sub_880BF5E4);
PPC_FUNC_IMPL(__imp__sub_880BF5E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BF5E8"))) PPC_WEAK_FUNC(sub_880BF5E8);
PPC_FUNC_IMPL(__imp__sub_880BF5E8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// li r5,24
	ctx.r5.s64 = 24;
	// addi r3,r11,-18868
	ctx.r3.s64 = ctx.r11.s64 + -18868;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x88073bd0
	sub_88073BD0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880BF5FC"))) PPC_WEAK_FUNC(sub_880BF5FC);
PPC_FUNC_IMPL(__imp__sub_880BF5FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BF600"))) PPC_WEAK_FUNC(sub_880BF600);
PPC_FUNC_IMPL(__imp__sub_880BF600) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// lhz r10,5836(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 5836);
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,-18868
	ctx.r11.s64 = ctx.r11.s64 + -18868;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// addi r8,r11,12
	ctx.r8.s64 = ctx.r11.s64 + 12;
	// lwzx r7,r9,r8
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// clrlwi r10,r7,16
	ctx.r10.u64 = ctx.r7.u32 & 0xFFFF;
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
loc_880BF634:
	// lhz r9,92(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 92);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x880bf650
	if (ctx.cr6.eq) goto loc_880BF650;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880bf634
	if (!ctx.cr6.eq) goto loc_880BF634;
	// blr 
	return;
loc_880BF650:
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r10,96(r11)
	PPC_STORE_U16(ctx.r11.u32 + 96, ctx.r10.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880BF65C"))) PPC_WEAK_FUNC(sub_880BF65C);
PPC_FUNC_IMPL(__imp__sub_880BF65C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BF660"))) PPC_WEAK_FUNC(sub_880BF660);
PPC_FUNC_IMPL(__imp__sub_880BF660) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// lhz r10,5836(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 5836);
	// addi r9,r11,-18868
	ctx.r9.s64 = ctx.r11.s64 + -18868;
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
loc_880BF68C:
	// lhz r9,92(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 92);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x880bf6a8
	if (ctx.cr6.eq) goto loc_880BF6A8;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880bf68c
	if (!ctx.cr6.eq) goto loc_880BF68C;
	// blr 
	return;
loc_880BF6A8:
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r10,96(r11)
	PPC_STORE_U16(ctx.r11.u32 + 96, ctx.r10.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880BF6B4"))) PPC_WEAK_FUNC(sub_880BF6B4);
PPC_FUNC_IMPL(__imp__sub_880BF6B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BF6B8"))) PPC_WEAK_FUNC(sub_880BF6B8);
PPC_FUNC_IMPL(__imp__sub_880BF6B8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// lhz r10,5836(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 5836);
	// addi r9,r11,-18868
	ctx.r9.s64 = ctx.r11.s64 + -18868;
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
loc_880BF6E4:
	// lhz r9,92(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 92);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x880bf700
	if (ctx.cr6.eq) goto loc_880BF700;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880bf6e4
	if (!ctx.cr6.eq) goto loc_880BF6E4;
	// blr 
	return;
loc_880BF700:
	// li r10,1
	ctx.r10.s64 = 1;
	// sth r10,96(r11)
	PPC_STORE_U16(ctx.r11.u32 + 96, ctx.r10.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880BF70C"))) PPC_WEAK_FUNC(sub_880BF70C);
PPC_FUNC_IMPL(__imp__sub_880BF70C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BF710"))) PPC_WEAK_FUNC(sub_880BF710);
PPC_FUNC_IMPL(__imp__sub_880BF710) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// lhz r10,5836(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 5836);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwz r11,-18868(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -18868);
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
loc_880BF738:
	// lhz r9,92(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 92);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x880bf754
	if (ctx.cr6.eq) goto loc_880BF754;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880bf738
	if (!ctx.cr6.eq) goto loc_880BF738;
	// blr 
	return;
loc_880BF754:
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r10,96(r11)
	PPC_STORE_U16(ctx.r11.u32 + 96, ctx.r10.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880BF760"))) PPC_WEAK_FUNC(sub_880BF760);
PPC_FUNC_IMPL(__imp__sub_880BF760) {
	PPC_FUNC_PROLOGUE();
	// li r10,128
	ctx.r10.s64 = 128;
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// addi r11,r11,15784
	ctx.r11.s64 = ctx.r11.s64 + 15784;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// li r10,0
	ctx.r10.s64 = 0;
loc_880BF774:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x880bf784
	if (!ctx.cr6.eq) goto loc_880BF784;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_880BF784:
	// addi r11,r11,80
	ctx.r11.s64 = ctx.r11.s64 + 80;
	// bdnz 0x880bf774
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_880BF774;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880BF790"))) PPC_WEAK_FUNC(sub_880BF790);
PPC_FUNC_IMPL(__imp__sub_880BF790) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lwz r10,2304(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// li r31,0
	ctx.r31.s64 = 0;
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
	// lwz r9,26024(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26024);
loc_880BF7A8:
	// addi r11,r9,1
	ctx.r11.s64 = ctx.r9.s64 + 1;
	// srawi r9,r11,7
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7F) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 7;
	// addze r3,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r3.s64 = temp.s64;
	// rlwinm r9,r3,7,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 7) & 0xFFFFFF80;
	// subf r11,r9,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r9.s64;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,26024(r10)
	PPC_STORE_U32(ctx.r10.u32 + 26024, ctx.r11.u32);
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// add r3,r11,r3
	ctx.r3.u64 = ctx.r11.u64 + ctx.r3.u64;
	// rlwinm r11,r3,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r3,15784(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15784);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x880bf7f8
	if (ctx.cr6.eq) goto loc_880BF7F8;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmpwi cr6,r30,128
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 128, ctx.xer);
	// blt cr6,0x880bf7a8
	if (ctx.cr6.lt) goto loc_880BF7A8;
	// ld r30,-16(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_880BF7F8:
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r4,15796(r11)
	PPC_STORE_U32(ctx.r11.u32 + 15796, ctx.r4.u32);
	// li r9,220
	ctx.r9.s64 = 220;
	// stw r5,15800(r11)
	PPC_STORE_U32(ctx.r11.u32 + 15800, ctx.r5.u32);
	// stw r10,15784(r11)
	PPC_STORE_U32(ctx.r11.u32 + 15784, ctx.r10.u32);
	// stw r31,15788(r11)
	PPC_STORE_U32(ctx.r11.u32 + 15788, ctx.r31.u32);
	// stw r31,15844(r11)
	PPC_STORE_U32(ctx.r11.u32 + 15844, ctx.r31.u32);
	// stw r31,15792(r11)
	PPC_STORE_U32(ctx.r11.u32 + 15792, ctx.r31.u32);
	// stw r6,15812(r11)
	PPC_STORE_U32(ctx.r11.u32 + 15812, ctx.r6.u32);
	// stw r31,15820(r11)
	PPC_STORE_U32(ctx.r11.u32 + 15820, ctx.r31.u32);
	// stw r10,15828(r11)
	PPC_STORE_U32(ctx.r11.u32 + 15828, ctx.r10.u32);
	// stw r10,15824(r11)
	PPC_STORE_U32(ctx.r11.u32 + 15824, ctx.r10.u32);
	// stw r31,15832(r11)
	PPC_STORE_U32(ctx.r11.u32 + 15832, ctx.r31.u32);
	// stw r9,15836(r11)
	PPC_STORE_U32(ctx.r11.u32 + 15836, ctx.r9.u32);
	// stw r7,15816(r11)
	PPC_STORE_U32(ctx.r11.u32 + 15816, ctx.r7.u32);
	// stw r8,15848(r11)
	PPC_STORE_U32(ctx.r11.u32 + 15848, ctx.r8.u32);
	// ld r30,-16(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880BF844"))) PPC_WEAK_FUNC(sub_880BF844);
PPC_FUNC_IMPL(__imp__sub_880BF844) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880BF848"))) PPC_WEAK_FUNC(sub_880BF848);
PPC_FUNC_IMPL(__imp__sub_880BF848) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807113c
	ctx.lr = 0x880BF850;
	__savegprlr_21(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r6,2304(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// li r27,128
	ctx.r27.s64 = 128;
	// addi r8,r6,15784
	ctx.r8.s64 = ctx.r6.s64 + 15784;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r23,160
	ctx.r23.s64 = 160;
	// li r28,31
	ctx.r28.s64 = 31;
	// li r30,1
	ctx.r30.s64 = 1;
	// li r24,192
	ctx.r24.s64 = 192;
	// li r29,47
	ctx.r29.s64 = 47;
	// lis r31,-40
	ctx.r31.s64 = -2621440;
	// lis r25,392
	ctx.r25.s64 = 25690112;
	// lis r26,280
	ctx.r26.s64 = 18350080;
	// addi r5,r11,9552
	ctx.r5.s64 = ctx.r11.s64 + 9552;
loc_880BF88C:
	// lwz r11,0(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x880bfb44
	if (!ctx.cr6.eq) goto loc_880BFB44;
	// lwz r11,4(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x880bfb44
	if (ctx.cr6.gt) goto loc_880BFB44;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x880bf974
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_880BF974;
	// bdzf 4*cr6+eq,0x880bf9dc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_880BF9DC;
	// bne cr6,0x880bfac8
	if (!ctx.cr6.eq) goto loc_880BFAC8;
	// lwz r9,14672(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 14672);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r10,14664(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 14664);
	// lwz r11,12(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// subf r10,r9,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r9.s64;
	// lwz r9,16(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r7,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r7.u32);
	// lwz r10,14676(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 14676);
	// lwz r11,14668(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 14668);
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stw r9,16(r8)
	PPC_STORE_U32(ctx.r8.u32 + 16, ctx.r9.u32);
	// bl 0x88094af0
	ctx.lr = 0x880BF8F0;
	sub_88094AF0(ctx, base);
	// rotlwi r7,r7,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// lwz r11,8(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// add r3,r3,r7
	ctx.r3.u64 = ctx.r3.u64 + ctx.r7.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// stw r3,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r3.u32);
	// blt cr6,0x880bf924
	if (ctx.cr6.lt) goto loc_880BF924;
	// bne cr6,0x880bfb44
	if (!ctx.cr6.eq) goto loc_880BFB44;
	// lwz r11,48(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 48);
	// addic. r11,r11,-8
	ctx.xer.ca = ctx.r11.u32 > 7;
	ctx.r11.s64 = ctx.r11.s64 + -8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,48(r8)
	PPC_STORE_U32(ctx.r8.u32 + 48, ctx.r11.u32);
	// bgt 0x880bfb44
	if (ctx.cr0.gt) goto loc_880BFB44;
	// stw r4,48(r8)
	PPC_STORE_U32(ctx.r8.u32 + 48, ctx.r4.u32);
	// b 0x880bfb40
	goto loc_880BFB40;
loc_880BF924:
	// lwz r11,48(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 48);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// stw r11,48(r8)
	PPC_STORE_U32(ctx.r8.u32 + 48, ctx.r11.u32);
	// cmpwi cr6,r11,160
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 160, ctx.xer);
	// ble cr6,0x880bf93c
	if (!ctx.cr6.gt) goto loc_880BF93C;
	// stw r23,48(r8)
	PPC_STORE_U32(ctx.r8.u32 + 48, ctx.r23.u32);
loc_880BF93C:
	// lwz r11,40(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 40);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,40(r8)
	PPC_STORE_U32(ctx.r8.u32 + 40, ctx.r11.u32);
	// bge 0x880bfb44
	if (!ctx.cr0.lt) goto loc_880BFB44;
	// lwz r11,36(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 36);
	// lwz r10,44(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 44);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,36(r8)
	PPC_STORE_U32(ctx.r8.u32 + 36, ctx.r11.u32);
	// cmpwi cr6,r11,30
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 30, ctx.xer);
	// stw r10,40(r8)
	PPC_STORE_U32(ctx.r8.u32 + 40, ctx.r10.u32);
	// ble cr6,0x880bfb44
	if (!ctx.cr6.gt) goto loc_880BFB44;
	// stw r28,36(r8)
	PPC_STORE_U32(ctx.r8.u32 + 36, ctx.r28.u32);
	// stw r30,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r30.u32);
	// b 0x880bfb44
	goto loc_880BFB44;
loc_880BF974:
	// lwz r10,14672(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 14672);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,14664(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 14664);
	// lwz r9,12(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// lwz r10,16(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stw r9,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r9.u32);
	// lwz r7,14668(r6)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + 14668);
	// lwz r11,14676(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 14676);
	// subf r11,r11,r7
	ctx.r11.s64 = ctx.r7.s64 - ctx.r11.s64;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r10,16(r8)
	PPC_STORE_U32(ctx.r8.u32 + 16, ctx.r10.u32);
	// bl 0x88094af0
	ctx.lr = 0x880BF9AC;
	sub_88094AF0(ctx, base);
	// lwz r9,12(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// add r3,r3,r9
	ctx.r3.u64 = ctx.r3.u64 + ctx.r9.u64;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stw r3,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r3.u32);
	// bne cr6,0x880bfb44
	if (!ctx.cr6.eq) goto loc_880BFB44;
	// lwz r11,48(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 48);
	// addic. r11,r11,-8
	ctx.xer.ca = ctx.r11.u32 > 7;
	ctx.r11.s64 = ctx.r11.s64 + -8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,48(r8)
	PPC_STORE_U32(ctx.r8.u32 + 48, ctx.r11.u32);
	// bgt 0x880bfb44
	if (ctx.cr0.gt) goto loc_880BFB44;
	// stw r4,48(r8)
	PPC_STORE_U32(ctx.r8.u32 + 48, ctx.r4.u32);
	// b 0x880bfb40
	goto loc_880BFB40;
loc_880BF9DC:
	// lwz r10,14672(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 14672);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,14664(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 14664);
	// lwz r9,12(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// lwz r10,16(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stw r9,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r9.u32);
	// lwz r11,14676(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 14676);
	// lwz r7,14668(r6)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + 14668);
	// subf r11,r11,r7
	ctx.r11.s64 = ctx.r7.s64 - ctx.r11.s64;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r10,16(r8)
	PPC_STORE_U32(ctx.r8.u32 + 16, ctx.r10.u32);
	// bl 0x88094af0
	ctx.lr = 0x880BFA14;
	sub_88094AF0(ctx, base);
	// lwz r9,12(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// lwz r11,8(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// add r7,r3,r9
	ctx.r7.u64 = ctx.r3.u64 + ctx.r9.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// stw r7,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r7.u32);
	// blt cr6,0x880bfa78
	if (ctx.cr6.lt) goto loc_880BFA78;
	// bne cr6,0x880bfb44
	if (!ctx.cr6.eq) goto loc_880BFB44;
	// lwz r11,48(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 48);
	// addic. r11,r11,-2
	ctx.xer.ca = ctx.r11.u32 > 1;
	ctx.r11.s64 = ctx.r11.s64 + -2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,48(r8)
	PPC_STORE_U32(ctx.r8.u32 + 48, ctx.r11.u32);
	// bgt 0x880bfa48
	if (ctx.cr0.gt) goto loc_880BFA48;
	// stw r4,48(r8)
	PPC_STORE_U32(ctx.r8.u32 + 48, ctx.r4.u32);
	// stw r4,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r4.u32);
loc_880BFA48:
	// lwz r11,40(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 40);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,40(r8)
	PPC_STORE_U32(ctx.r8.u32 + 40, ctx.r11.u32);
	// bge 0x880bfb44
	if (!ctx.cr0.lt) goto loc_880BFB44;
	// lwz r11,36(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 36);
	// lwz r10,44(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 44);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,36(r8)
	PPC_STORE_U32(ctx.r8.u32 + 36, ctx.r11.u32);
	// stw r10,40(r8)
	PPC_STORE_U32(ctx.r8.u32 + 40, ctx.r10.u32);
	// bge 0x880bfb44
	if (!ctx.cr0.lt) goto loc_880BFB44;
	// stw r4,36(r8)
	PPC_STORE_U32(ctx.r8.u32 + 36, ctx.r4.u32);
	// b 0x880bfb40
	goto loc_880BFB40;
loc_880BFA78:
	// lwz r11,48(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 48);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// stw r11,48(r8)
	PPC_STORE_U32(ctx.r8.u32 + 48, ctx.r11.u32);
	// cmpwi cr6,r11,192
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 192, ctx.xer);
	// ble cr6,0x880bfa90
	if (!ctx.cr6.gt) goto loc_880BFA90;
	// stw r24,48(r8)
	PPC_STORE_U32(ctx.r8.u32 + 48, ctx.r24.u32);
loc_880BFA90:
	// lwz r11,40(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 40);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,40(r8)
	PPC_STORE_U32(ctx.r8.u32 + 40, ctx.r11.u32);
	// bge 0x880bfb44
	if (!ctx.cr0.lt) goto loc_880BFB44;
	// lwz r11,36(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 36);
	// lwz r10,44(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 44);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r11,36(r8)
	PPC_STORE_U32(ctx.r8.u32 + 36, ctx.r11.u32);
	// cmpwi cr6,r11,47
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 47, ctx.xer);
	// stw r10,40(r8)
	PPC_STORE_U32(ctx.r8.u32 + 40, ctx.r10.u32);
	// ble cr6,0x880bfb44
	if (!ctx.cr6.gt) goto loc_880BFB44;
	// stw r29,36(r8)
	PPC_STORE_U32(ctx.r8.u32 + 36, ctx.r29.u32);
	// stw r30,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r30.u32);
	// b 0x880bfb44
	goto loc_880BFB44;
loc_880BFAC8:
	// lwz r11,28(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r22,32(r8)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r8.u32 + 32);
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// lwz r7,12(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// lwz r10,16(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// addi r9,r11,128
	ctx.r9.s64 = ctx.r11.s64 + 128;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r9,2,21,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x7FC;
	// lwzx r11,r11,r5
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r5.u32);
	// lwzx r21,r9,r5
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r5.u32);
	// mullw r9,r11,r22
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r22.s32);
	// mullw r11,r21,r22
	ctx.r11.s64 = int64_t(ctx.r21.s32) * int64_t(ctx.r22.s32);
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r9,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r9.u32);
	// stw r7,16(r8)
	PPC_STORE_U32(ctx.r8.u32 + 16, ctx.r7.u32);
	// bl 0x88094af0
	ctx.lr = 0x880BFB10;
	sub_88094AF0(ctx, base);
	// lwz r11,12(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// cmpw cr6,r7,r31
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r31.s32, ctx.xer);
	// add r11,r3,r11
	ctx.r11.u64 = ctx.r3.u64 + ctx.r11.u64;
	// stw r11,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r11.u32);
	// ble cr6,0x880bfb2c
	if (!ctx.cr6.gt) goto loc_880BFB2C;
	// cmpw cr6,r7,r25
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r25.s32, ctx.xer);
	// blt cr6,0x880bfb30
	if (ctx.cr6.lt) goto loc_880BFB30;
loc_880BFB2C:
	// stw r4,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r4.u32);
loc_880BFB30:
	// cmpw cr6,r11,r31
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r31.s32, ctx.xer);
	// ble cr6,0x880bfb40
	if (!ctx.cr6.gt) goto loc_880BFB40;
	// cmpw cr6,r11,r26
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r26.s32, ctx.xer);
	// blt cr6,0x880bfb44
	if (ctx.cr6.lt) goto loc_880BFB44;
loc_880BFB40:
	// stw r4,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r4.u32);
loc_880BFB44:
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// addi r8,r8,80
	ctx.r8.s64 = ctx.r8.s64 + 80;
	// bne 0x880bf88c
	if (!ctx.cr0.eq) goto loc_880BF88C;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8807118c
	__restgprlr_21(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880BFB58"))) PPC_WEAK_FUNC(sub_880BFB58);
PPC_FUNC_IMPL(__imp__sub_880BFB58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r9,160
	ctx.r9.s64 = 160;
	// lwz r11,-11984(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11984);
	// lwz r11,220(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 220);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + ctx.r11.u64;
	// srawi r7,r8,16
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFF) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 16;
	// addze r10,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r10.s64 = temp.s64;
	// addi r6,r10,-160
	ctx.r6.s64 = ctx.r10.s64 + -160;
	// mulli r5,r6,240
	ctx.r5.s64 = ctx.r6.s64 * 240;
	// srawi r4,r5,1
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	ctx.r4.s64 = ctx.r5.s32 >> 1;
	// addze r10,r4
	temp.s64 = ctx.r4.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r10.s64 = temp.s64;
	// divw r10,r10,r9
	ctx.r10.s32 = ppc_divw(ctx.r10.s32, ctx.r9.s32);
	// addi r9,r10,160
	ctx.r9.s64 = ctx.r10.s64 + 160;
	// rlwinm r8,r9,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// subf r7,r11,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r11.s64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880BFBA0"))) PPC_WEAK_FUNC(sub_880BFBA0);
PPC_FUNC_IMPL(__imp__sub_880BFBA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071124
	ctx.lr = 0x880BFBA8;
	__savegprlr_15(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r18,2304(r3)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r11,-30667
	ctx.r11.s64 = -2009792512;
	// lwz r9,184(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// lis r15,-30597
	ctx.r15.s64 = -2005204992;
	// lwz r10,168(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// addi r11,r11,8424
	ctx.r11.s64 = ctx.r11.s64 + 8424;
	// lwz r8,8(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// li r28,6
	ctx.r28.s64 = 6;
	// addi r29,r11,8
	ctx.r29.s64 = ctx.r11.s64 + 8;
	// lwz r22,0(r6)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r7,0(r18)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// add r11,r9,r10
	ctx.r11.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r16,4(r6)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// lwz r5,14664(r18)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r18.u32 + 14664);
	// addi r19,r11,2
	ctx.r19.s64 = ctx.r11.s64 + 2;
	// lwz r30,0(r8)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r11,100(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 100);
	// lwz r3,2300(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2300);
	// lwz r4,14668(r18)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r18.u32 + 14668);
	// lwz r9,104(r18)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r18.u32 + 104);
	// lwz r17,-11932(r15)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r15.u32 + -11932);
	// lwz r10,156(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 156);
	// lwz r8,160(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// srawi r7,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r7.s64 = ctx.r10.s32 >> 1;
	// addze r6,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r6.s64 = temp.s64;
	// srawi r3,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r3.s64 = ctx.r8.s32 >> 1;
	// subf r10,r6,r5
	ctx.r10.s64 = ctx.r5.s64 - ctx.r6.s64;
	// addze r8,r3
	temp.s64 = ctx.r3.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r8.s64 = temp.s64;
	// add r21,r10,r11
	ctx.r21.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r11,r8,r4
	ctx.r11.s64 = ctx.r4.s64 - ctx.r8.s64;
	// add r20,r11,r9
	ctx.r20.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lis r11,-30681
	ctx.r11.s64 = -2010710016;
	// addi r31,r11,-27392
	ctx.r31.s64 = ctx.r11.s64 + -27392;
loc_880BFC30:
	// lwz r11,-8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -8);
	// mulli r11,r11,88
	ctx.r11.s64 = ctx.r11.s64 * 88;
	// add r10,r11,r18
	ctx.r10.u64 = ctx.r11.u64 + ctx.r18.u64;
	// lwz r9,10856(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 10856);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x880bfd1c
	if (!ctx.cr6.eq) goto loc_880BFD1C;
	// lwz r8,-4(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + -4);
	// addi r7,r31,-1680
	ctx.r7.s64 = ctx.r31.s64 + -1680;
	// addi r9,r31,-1680
	ctx.r9.s64 = ctx.r31.s64 + -1680;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// rlwinm r6,r8,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,10784(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 10784);
	// addi r5,r9,4
	ctx.r5.s64 = ctx.r9.s64 + 4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwzx r4,r6,r7
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r7.u32);
	// lwzx r3,r6,r5
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r5.u32);
	// mullw r9,r4,r30
	ctx.r9.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r30.s32);
	// rlwinm r8,r9,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// mullw r7,r3,r30
	ctx.r7.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r30.s32);
	// srawi r6,r8,5
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1F) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 5;
	// rlwinm r5,r7,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// addze r9,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r9.s64 = temp.s64;
	// srawi r3,r5,5
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1F) != 0);
	ctx.r3.s64 = ctx.r5.s32 >> 5;
	// add r4,r9,r21
	ctx.r4.u64 = ctx.r9.u64 + ctx.r21.u64;
	// addze r9,r3
	temp.s64 = ctx.r3.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r9.s64 = temp.s64;
	// add r5,r9,r20
	ctx.r5.u64 = ctx.r9.u64 + ctx.r20.u64;
	// beq cr6,0x880bfcc4
	if (ctx.cr6.eq) goto loc_880BFCC4;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r8,1(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// extsb r6,r8
	ctx.r6.s64 = ctx.r8.s8;
	// rlwinm r11,r7,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r9,r6,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r11,r4
	ctx.r4.u64 = ctx.r11.u64 + ctx.r4.u64;
	// add r5,r9,r5
	ctx.r5.u64 = ctx.r9.u64 + ctx.r5.u64;
loc_880BFCC4:
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// mr r6,r19
	ctx.r6.u64 = ctx.r19.u64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x880BFCD4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x880bfd1c
	if (ctx.cr6.eq) goto loc_880BFD1C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880bfcec
	if (ctx.cr6.eq) goto loc_880BFCEC;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880BFCEC:
	// cmplwi cr6,r16,0
	ctx.cr6.compare<uint32_t>(ctx.r16.u32, 0, ctx.xer);
	// beq cr6,0x880bfd1c
	if (ctx.cr6.eq) goto loc_880BFD1C;
	// lwz r11,0(r16)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880bfd1c
	if (ctx.cr6.eq) goto loc_880BFD1C;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880BFD1C:
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// addi r29,r29,20
	ctx.r29.s64 = ctx.r29.s64 + 20;
	// bne 0x880bfc30
	if (!ctx.cr0.eq) goto loc_880BFC30;
	// lwz r11,-1368(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -1368);
	// mr r6,r19
	ctx.r6.u64 = ctx.r19.u64;
	// lwz r10,-1364(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -1364);
	// mullw r11,r11,r30
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// lwz r9,10784(r18)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r18.u32 + 10784);
	// stw r17,-11932(r15)
	PPC_STORE_U32(ctx.r15.u32 + -11932, ctx.r17.u32);
	// rlwinm r8,r11,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// mullw r7,r10,r30
	ctx.r7.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r30.s32);
	// srawi r5,r8,5
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1F) != 0);
	ctx.r5.s64 = ctx.r8.s32 >> 5;
	// rlwinm r4,r7,16,0,15
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// addze r11,r5
	temp.s64 = ctx.r5.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r11.s64 = temp.s64;
	// srawi r3,r4,5
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1F) != 0);
	ctx.r3.s64 = ctx.r4.s32 >> 5;
	// add r4,r11,r21
	ctx.r4.u64 = ctx.r11.u64 + ctx.r21.u64;
	// addze r11,r3
	temp.s64 = ctx.r3.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r11.s64 = temp.s64;
	// addis r3,r9,1
	ctx.r3.s64 = ctx.r9.s64 + 65536;
	// add r5,r11,r20
	ctx.r5.u64 = ctx.r11.u64 + ctx.r20.u64;
	// addi r3,r3,-31175
	ctx.r3.s64 = ctx.r3.s64 + -31175;
	// bl 0x881538c0
	ctx.lr = 0x880BFD70;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x880bfdbc
	if (ctx.cr6.eq) goto loc_880BFDBC;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880bfd88
	if (ctx.cr6.eq) goto loc_880BFD88;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880BFD88:
	// cmplwi cr6,r16,0
	ctx.cr6.compare<uint32_t>(ctx.r16.u32, 0, ctx.xer);
	// beq cr6,0x880bfdbc
	if (ctx.cr6.eq) goto loc_880BFDBC;
	// lwz r11,0(r16)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880bfdbc
	if (ctx.cr6.eq) goto loc_880BFDBC;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r17,-11932(r15)
	PPC_STORE_U32(ctx.r15.u32 + -11932, ctx.r17.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880BFDBC:
	// lwz r11,-1640(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -1640);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r10,-1636(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -1636);
	// mr r6,r19
	ctx.r6.u64 = ctx.r19.u64;
	// mullw r11,r11,r30
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// rlwinm r9,r11,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// mullw r8,r10,r30
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r30.s32);
	// srawi r7,r9,5
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1F) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 5;
	// rlwinm r5,r8,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// addze r11,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r11.s64 = temp.s64;
	// srawi r10,r5,5
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r5.s32 >> 5;
	// add r4,r11,r21
	ctx.r4.u64 = ctx.r11.u64 + ctx.r21.u64;
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r11.s64 = temp.s64;
	// ori r3,r3,34056
	ctx.r3.u64 = ctx.r3.u64 | 34056;
	// add r5,r11,r20
	ctx.r5.u64 = ctx.r11.u64 + ctx.r20.u64;
	// bl 0x881538c0
	ctx.lr = 0x880BFDFC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x880bfe48
	if (ctx.cr6.eq) goto loc_880BFE48;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880bfe14
	if (ctx.cr6.eq) goto loc_880BFE14;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880BFE14:
	// cmplwi cr6,r16,0
	ctx.cr6.compare<uint32_t>(ctx.r16.u32, 0, ctx.xer);
	// beq cr6,0x880bfe48
	if (ctx.cr6.eq) goto loc_880BFE48;
	// lwz r11,0(r16)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880bfe48
	if (ctx.cr6.eq) goto loc_880BFE48;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r17,-11932(r15)
	PPC_STORE_U32(ctx.r15.u32 + -11932, ctx.r17.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880BFE48:
	// lwz r11,10940(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 10940);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bgt cr6,0x880c040c
	if (ctx.cr6.gt) goto loc_880C040C;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x880bffc0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_880BFFC0;
	// bdzf 4*cr6+eq,0x880c017c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_880C017C;
	// bdzf 4*cr6+eq,0x880c017c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_880C017C;
	// bne cr6,0x880c017c
	if (!ctx.cr6.eq) goto loc_880C017C;
	// lwz r11,-1656(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -1656);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r10,-1652(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -1652);
	// mr r6,r19
	ctx.r6.u64 = ctx.r19.u64;
	// mullw r11,r11,r30
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// rlwinm r9,r11,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// mullw r8,r10,r30
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r30.s32);
	// srawi r7,r9,5
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1F) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 5;
	// rlwinm r5,r8,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// addze r11,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r11.s64 = temp.s64;
	// srawi r10,r5,5
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r5.s32 >> 5;
	// add r4,r11,r21
	ctx.r4.u64 = ctx.r11.u64 + ctx.r21.u64;
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r11.s64 = temp.s64;
	// ori r3,r3,34054
	ctx.r3.u64 = ctx.r3.u64 | 34054;
	// add r5,r11,r20
	ctx.r5.u64 = ctx.r11.u64 + ctx.r20.u64;
	// bl 0x881538c0
	ctx.lr = 0x880BFEAC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x880bfef8
	if (ctx.cr6.eq) goto loc_880BFEF8;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880bfec4
	if (ctx.cr6.eq) goto loc_880BFEC4;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880BFEC4:
	// cmplwi cr6,r16,0
	ctx.cr6.compare<uint32_t>(ctx.r16.u32, 0, ctx.xer);
	// beq cr6,0x880bfef8
	if (ctx.cr6.eq) goto loc_880BFEF8;
	// lwz r11,0(r16)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880bfef8
	if (ctx.cr6.eq) goto loc_880BFEF8;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r17,-11932(r15)
	PPC_STORE_U32(ctx.r15.u32 + -11932, ctx.r17.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880BFEF8:
	// lwz r11,-1664(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -1664);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r10,-1660(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -1660);
	// mr r6,r19
	ctx.r6.u64 = ctx.r19.u64;
	// mullw r11,r11,r30
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// rlwinm r9,r11,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// mullw r8,r10,r30
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r30.s32);
	// srawi r7,r9,5
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1F) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 5;
	// rlwinm r5,r8,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// addze r11,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r11.s64 = temp.s64;
	// srawi r10,r5,5
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r5.s32 >> 5;
	// add r4,r11,r21
	ctx.r4.u64 = ctx.r11.u64 + ctx.r21.u64;
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r11.s64 = temp.s64;
	// ori r3,r3,34053
	ctx.r3.u64 = ctx.r3.u64 | 34053;
	// add r5,r11,r20
	ctx.r5.u64 = ctx.r11.u64 + ctx.r20.u64;
	// bl 0x881538c0
	ctx.lr = 0x880BFF38;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x880bff84
	if (ctx.cr6.eq) goto loc_880BFF84;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880bff50
	if (ctx.cr6.eq) goto loc_880BFF50;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880BFF50:
	// cmplwi cr6,r16,0
	ctx.cr6.compare<uint32_t>(ctx.r16.u32, 0, ctx.xer);
	// beq cr6,0x880bff84
	if (ctx.cr6.eq) goto loc_880BFF84;
	// lwz r11,0(r16)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880bff84
	if (ctx.cr6.eq) goto loc_880BFF84;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r17,-11932(r15)
	PPC_STORE_U32(ctx.r15.u32 + -11932, ctx.r17.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880BFF84:
	// lwz r11,-1648(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -1648);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r10,-1644(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -1644);
	// mr r6,r19
	ctx.r6.u64 = ctx.r19.u64;
	// mullw r11,r11,r30
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// rlwinm r9,r11,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// mullw r8,r10,r30
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r30.s32);
	// srawi r7,r9,5
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1F) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 5;
	// rlwinm r5,r8,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// addze r11,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r11.s64 = temp.s64;
	// srawi r10,r5,5
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r5.s32 >> 5;
	// add r4,r11,r21
	ctx.r4.u64 = ctx.r11.u64 + ctx.r21.u64;
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r11.s64 = temp.s64;
	// ori r3,r3,34055
	ctx.r3.u64 = ctx.r3.u64 | 34055;
	// b 0x880c03b8
	goto loc_880C03B8;
loc_880BFFC0:
	// lwz r7,13336(r18)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r18.u32 + 13336);
	// addi r10,r31,-128
	ctx.r10.s64 = ctx.r31.s64 + -128;
	// lwz r11,-1384(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -1384);
	// addi r6,r31,-128
	ctx.r6.s64 = ctx.r31.s64 + -128;
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// rlwinm r3,r7,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// mullw r5,r11,r30
	ctx.r5.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// lwz r11,-1380(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -1380);
	// lbzx r6,r3,r6
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r6.u32);
	// rlwinm r10,r5,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// lbzx r5,r3,r4
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r4.u32);
	// mullw r9,r11,r30
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// srawi r4,r10,5
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1F) != 0);
	ctx.r4.s64 = ctx.r10.s32 >> 5;
	// rlwinm r3,r9,16,0,15
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// addze r8,r4
	temp.s64 = ctx.r4.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r8.s64 = temp.s64;
	// srawi r11,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 5;
	// extsb r10,r6
	ctx.r10.s64 = ctx.r6.s8;
	// extsb r6,r5
	ctx.r6.s64 = ctx.r5.s8;
	// addze r9,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r11,r6,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// addis r3,r7,1
	ctx.r3.s64 = ctx.r7.s64 + 65536;
	// add r4,r10,r21
	ctx.r4.u64 = ctx.r10.u64 + ctx.r21.u64;
	// add r5,r11,r20
	ctx.r5.u64 = ctx.r11.u64 + ctx.r20.u64;
	// mr r6,r19
	ctx.r6.u64 = ctx.r19.u64;
	// addi r3,r3,-31239
	ctx.r3.s64 = ctx.r3.s64 + -31239;
	// bl 0x881538c0
	ctx.lr = 0x880C0034;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x880c0080
	if (ctx.cr6.eq) goto loc_880C0080;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c004c
	if (ctx.cr6.eq) goto loc_880C004C;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C004C:
	// cmplwi cr6,r16,0
	ctx.cr6.compare<uint32_t>(ctx.r16.u32, 0, ctx.xer);
	// beq cr6,0x880c0080
	if (ctx.cr6.eq) goto loc_880C0080;
	// lwz r11,0(r16)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c0080
	if (ctx.cr6.eq) goto loc_880C0080;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r17,-11932(r15)
	PPC_STORE_U32(ctx.r15.u32 + -11932, ctx.r17.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C0080:
	// lwz r7,13424(r18)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r18.u32 + 13424);
	// addi r10,r31,-64
	ctx.r10.s64 = ctx.r31.s64 + -64;
	// lwz r11,-1376(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -1376);
	// addi r6,r31,-64
	ctx.r6.s64 = ctx.r31.s64 + -64;
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// rlwinm r3,r7,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// mullw r5,r11,r30
	ctx.r5.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// lwz r11,-1372(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -1372);
	// lbzx r6,r3,r6
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r6.u32);
	// rlwinm r10,r5,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// lbzx r5,r3,r4
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r4.u32);
	// mullw r9,r11,r30
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// srawi r4,r10,5
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1F) != 0);
	ctx.r4.s64 = ctx.r10.s32 >> 5;
	// rlwinm r3,r9,16,0,15
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// addze r8,r4
	temp.s64 = ctx.r4.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r8.s64 = temp.s64;
	// srawi r11,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 5;
	// extsb r10,r6
	ctx.r10.s64 = ctx.r6.s8;
	// extsb r6,r5
	ctx.r6.s64 = ctx.r5.s8;
	// addze r9,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r11,r6,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// addis r3,r7,1
	ctx.r3.s64 = ctx.r7.s64 + 65536;
	// add r4,r10,r21
	ctx.r4.u64 = ctx.r10.u64 + ctx.r21.u64;
	// add r5,r11,r20
	ctx.r5.u64 = ctx.r11.u64 + ctx.r20.u64;
	// mr r6,r19
	ctx.r6.u64 = ctx.r19.u64;
	// addi r3,r3,-31207
	ctx.r3.s64 = ctx.r3.s64 + -31207;
	// bl 0x881538c0
	ctx.lr = 0x880C00F4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x880c0140
	if (ctx.cr6.eq) goto loc_880C0140;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c010c
	if (ctx.cr6.eq) goto loc_880C010C;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C010C:
	// cmplwi cr6,r16,0
	ctx.cr6.compare<uint32_t>(ctx.r16.u32, 0, ctx.xer);
	// beq cr6,0x880c0140
	if (ctx.cr6.eq) goto loc_880C0140;
	// lwz r11,0(r16)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c0140
	if (ctx.cr6.eq) goto loc_880C0140;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r17,-11932(r15)
	PPC_STORE_U32(ctx.r15.u32 + -11932, ctx.r17.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C0140:
	// lwz r11,-1656(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -1656);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r10,-1652(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -1652);
	// mr r6,r19
	ctx.r6.u64 = ctx.r19.u64;
	// mullw r11,r11,r30
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// rlwinm r9,r11,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// mullw r8,r10,r30
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r30.s32);
	// srawi r7,r9,5
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1F) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 5;
	// rlwinm r5,r8,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// addze r11,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r11.s64 = temp.s64;
	// srawi r10,r5,5
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r5.s32 >> 5;
	// add r4,r11,r21
	ctx.r4.u64 = ctx.r11.u64 + ctx.r21.u64;
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r11.s64 = temp.s64;
	// ori r3,r3,34054
	ctx.r3.u64 = ctx.r3.u64 | 34054;
	// b 0x880c03b8
	goto loc_880C03B8;
loc_880C017C:
	// addi r11,r31,32
	ctx.r11.s64 = ctx.r31.s64 + 32;
	// lwz r23,10872(r18)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r18.u32 + 10872);
	// lwz r10,-1348(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -1348);
	// addi r24,r31,32
	ctx.r24.s64 = ctx.r31.s64 + 32;
	// addi r25,r11,1
	ctx.r25.s64 = ctx.r11.s64 + 1;
	// addi r11,r30,-32
	ctx.r11.s64 = ctx.r30.s64 + -32;
	// rlwinm r29,r23,1,0,30
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r11,r11,20,0,11
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 20) & 0xFFF00000;
	// mullw r10,r10,r30
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r30.s32);
	// lbzx r9,r29,r24
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r24.u32);
	// lbzx r8,r29,r25
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r25.u32);
	// srawi r7,r11,5
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1F) != 0);
	ctx.r7.s64 = ctx.r11.s32 >> 5;
	// rlwinm r6,r10,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// addze r28,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r28.s64 = temp.s64;
	// srawi r5,r6,5
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1F) != 0);
	ctx.r5.s64 = ctx.r6.s32 >> 5;
	// extsb r4,r9
	ctx.r4.s64 = ctx.r9.s8;
	// extsb r3,r8
	ctx.r3.s64 = ctx.r8.s8;
	// addze r11,r5
	temp.s64 = ctx.r5.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r11.s64 = temp.s64;
	// rlwinm r9,r3,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// addis r26,r23,1
	ctx.r26.s64 = ctx.r23.s64 + 65536;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// subf r10,r28,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r28.s64;
	// addi r27,r19,-3
	ctx.r27.s64 = ctx.r19.s64 + -3;
	// addi r26,r26,-31143
	ctx.r26.s64 = ctx.r26.s64 + -31143;
	// add r5,r11,r20
	ctx.r5.u64 = ctx.r11.u64 + ctx.r20.u64;
	// add r4,r10,r21
	ctx.r4.u64 = ctx.r10.u64 + ctx.r21.u64;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x881538c0
	ctx.lr = 0x880C01F4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x880c0240
	if (ctx.cr6.eq) goto loc_880C0240;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c020c
	if (ctx.cr6.eq) goto loc_880C020C;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C020C:
	// cmplwi cr6,r16,0
	ctx.cr6.compare<uint32_t>(ctx.r16.u32, 0, ctx.xer);
	// beq cr6,0x880c0240
	if (ctx.cr6.eq) goto loc_880C0240;
	// lwz r11,0(r16)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c0240
	if (ctx.cr6.eq) goto loc_880C0240;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r17,-11932(r15)
	PPC_STORE_U32(ctx.r15.u32 + -11932, ctx.r17.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C0240:
	// lwz r11,-1348(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -1348);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// lbzx r10,r29,r24
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r24.u32);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// mullw r9,r11,r30
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// lbzx r8,r29,r25
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r25.u32);
	// rlwinm r7,r9,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// extsb r5,r10
	ctx.r5.s64 = ctx.r10.s8;
	// extsb r10,r8
	ctx.r10.s64 = ctx.r8.s8;
	// srawi r4,r7,5
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1F) != 0);
	ctx.r4.s64 = ctx.r7.s32 >> 5;
	// rlwinm r9,r10,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// addze r11,r4
	temp.s64 = ctx.r4.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r11.s64 = temp.s64;
	// rlwinm r10,r5,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r10,r10,r28
	ctx.r10.u64 = ctx.r10.u64 + ctx.r28.u64;
	// add r5,r11,r20
	ctx.r5.u64 = ctx.r11.u64 + ctx.r20.u64;
	// add r4,r10,r21
	ctx.r4.u64 = ctx.r10.u64 + ctx.r21.u64;
	// bl 0x881538c0
	ctx.lr = 0x880C0288;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x880c02d4
	if (ctx.cr6.eq) goto loc_880C02D4;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c02a0
	if (ctx.cr6.eq) goto loc_880C02A0;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C02A0:
	// cmplwi cr6,r16,0
	ctx.cr6.compare<uint32_t>(ctx.r16.u32, 0, ctx.xer);
	// beq cr6,0x880c02d4
	if (ctx.cr6.eq) goto loc_880C02D4;
	// lwz r11,0(r16)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c02d4
	if (ctx.cr6.eq) goto loc_880C02D4;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r17,-11932(r15)
	PPC_STORE_U32(ctx.r15.u32 + -11932, ctx.r17.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C02D4:
	// lwz r11,-1356(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -1356);
	// addi r25,r31,1
	ctx.r25.s64 = ctx.r31.s64 + 1;
	// lbzx r10,r29,r31
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r31.u32);
	// addis r26,r23,1
	ctx.r26.s64 = ctx.r23.s64 + 65536;
	// mullw r9,r11,r30
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// lbzx r8,r29,r25
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r25.u32);
	// rlwinm r7,r9,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// extsb r6,r10
	ctx.r6.s64 = ctx.r10.s8;
	// srawi r5,r7,5
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1F) != 0);
	ctx.r5.s64 = ctx.r7.s32 >> 5;
	// extsb r4,r8
	ctx.r4.s64 = ctx.r8.s8;
	// rlwinm r3,r6,16,0,15
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// addze r11,r5
	temp.s64 = ctx.r5.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r11.s64 = temp.s64;
	// rlwinm r9,r4,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// subf r10,r28,r3
	ctx.r10.s64 = ctx.r3.s64 - ctx.r28.s64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addi r27,r19,-1
	ctx.r27.s64 = ctx.r19.s64 + -1;
	// addi r26,r26,-31159
	ctx.r26.s64 = ctx.r26.s64 + -31159;
	// add r5,r11,r20
	ctx.r5.u64 = ctx.r11.u64 + ctx.r20.u64;
	// add r4,r10,r21
	ctx.r4.u64 = ctx.r10.u64 + ctx.r21.u64;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x881538c0
	ctx.lr = 0x880C032C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x880c0378
	if (ctx.cr6.eq) goto loc_880C0378;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c0344
	if (ctx.cr6.eq) goto loc_880C0344;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C0344:
	// cmplwi cr6,r16,0
	ctx.cr6.compare<uint32_t>(ctx.r16.u32, 0, ctx.xer);
	// beq cr6,0x880c0378
	if (ctx.cr6.eq) goto loc_880C0378;
	// lwz r11,0(r16)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c0378
	if (ctx.cr6.eq) goto loc_880C0378;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r17,-11932(r15)
	PPC_STORE_U32(ctx.r15.u32 + -11932, ctx.r17.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C0378:
	// lwz r11,-1356(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -1356);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// lbzx r10,r29,r31
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r31.u32);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lbzx r8,r29,r25
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r25.u32);
	// mullw r9,r11,r30
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// extsb r5,r10
	ctx.r5.s64 = ctx.r10.s8;
	// extsb r10,r8
	ctx.r10.s64 = ctx.r8.s8;
	// rlwinm r7,r9,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r9,r10,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// srawi r4,r7,5
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1F) != 0);
	ctx.r4.s64 = ctx.r7.s32 >> 5;
	// rlwinm r10,r5,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// addze r11,r4
	temp.s64 = ctx.r4.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r11.s64 = temp.s64;
	// add r10,r10,r28
	ctx.r10.u64 = ctx.r10.u64 + ctx.r28.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r4,r10,r21
	ctx.r4.u64 = ctx.r10.u64 + ctx.r21.u64;
loc_880C03B8:
	// add r5,r11,r20
	ctx.r5.u64 = ctx.r11.u64 + ctx.r20.u64;
	// bl 0x881538c0
	ctx.lr = 0x880C03C0;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x880c040c
	if (ctx.cr6.eq) goto loc_880C040C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c03d8
	if (ctx.cr6.eq) goto loc_880C03D8;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C03D8:
	// cmplwi cr6,r16,0
	ctx.cr6.compare<uint32_t>(ctx.r16.u32, 0, ctx.xer);
	// beq cr6,0x880c040c
	if (ctx.cr6.eq) goto loc_880C040C;
	// lwz r11,0(r16)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c040c
	if (ctx.cr6.eq) goto loc_880C040C;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r17,-11932(r15)
	PPC_STORE_U32(ctx.r15.u32 + -11932, ctx.r17.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C040C:
	// lwz r11,-1680(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -1680);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r10,-1676(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -1676);
	// mr r6,r19
	ctx.r6.u64 = ctx.r19.u64;
	// mullw r11,r11,r30
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// rlwinm r9,r11,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// mullw r8,r10,r30
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r30.s32);
	// srawi r7,r9,5
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1F) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 5;
	// rlwinm r5,r8,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// addze r11,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r11.s64 = temp.s64;
	// srawi r10,r5,5
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r5.s32 >> 5;
	// add r4,r11,r21
	ctx.r4.u64 = ctx.r11.u64 + ctx.r21.u64;
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r11.s64 = temp.s64;
	// ori r3,r3,34051
	ctx.r3.u64 = ctx.r3.u64 | 34051;
	// add r5,r11,r20
	ctx.r5.u64 = ctx.r11.u64 + ctx.r20.u64;
	// bl 0x881538c0
	ctx.lr = 0x880C044C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x880c0498
	if (ctx.cr6.eq) goto loc_880C0498;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c0464
	if (ctx.cr6.eq) goto loc_880C0464;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C0464:
	// cmplwi cr6,r16,0
	ctx.cr6.compare<uint32_t>(ctx.r16.u32, 0, ctx.xer);
	// beq cr6,0x880c0498
	if (ctx.cr6.eq) goto loc_880C0498;
	// lwz r11,0(r16)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c0498
	if (ctx.cr6.eq) goto loc_880C0498;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r17,-11932(r15)
	PPC_STORE_U32(ctx.r15.u32 + -11932, ctx.r17.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C0498:
	// lis r11,-30667
	ctx.r11.s64 = -2009792512;
	// li r28,16
	ctx.r28.s64 = 16;
	// addi r11,r11,8544
	ctx.r11.s64 = ctx.r11.s64 + 8544;
	// addi r29,r11,8
	ctx.r29.s64 = ctx.r11.s64 + 8;
loc_880C04A8:
	// lwz r11,-4(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -4);
	// addi r8,r31,-1680
	ctx.r8.s64 = ctx.r31.s64 + -1680;
	// addi r10,r31,-1680
	ctx.r10.s64 = ctx.r31.s64 + -1680;
	// lwz r7,-8(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + -8);
	// rlwinm r6,r11,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// addi r5,r10,4
	ctx.r5.s64 = ctx.r10.s64 + 4;
	// mulli r9,r7,88
	ctx.r9.s64 = ctx.r7.s64 * 88;
	// lwzx r4,r6,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
	// lwzx r3,r6,r5
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r5.u32);
	// mullw r10,r4,r30
	ctx.r10.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r30.s32);
	// rlwinm r8,r10,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// mullw r7,r3,r30
	ctx.r7.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r30.s32);
	// srawi r6,r8,5
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1F) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 5;
	// rlwinm r5,r7,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// addze r10,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r10.s64 = temp.s64;
	// add r3,r9,r18
	ctx.r3.u64 = ctx.r9.u64 + ctx.r18.u64;
	// srawi r9,r5,5
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1F) != 0);
	ctx.r9.s64 = ctx.r5.s32 >> 5;
	// add r4,r10,r21
	ctx.r4.u64 = ctx.r10.u64 + ctx.r21.u64;
	// addze r9,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r9.s64 = temp.s64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r10,10784(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10784);
	// add r5,r9,r20
	ctx.r5.u64 = ctx.r9.u64 + ctx.r20.u64;
	// beq cr6,0x880c0530
	if (ctx.cr6.eq) goto loc_880C0530;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r8,1(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// extsb r6,r8
	ctx.r6.s64 = ctx.r8.s8;
	// rlwinm r9,r7,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r6,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r9,r4
	ctx.r4.u64 = ctx.r9.u64 + ctx.r4.u64;
	// add r5,r11,r5
	ctx.r5.u64 = ctx.r11.u64 + ctx.r5.u64;
loc_880C0530:
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// mr r6,r19
	ctx.r6.u64 = ctx.r19.u64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x880C0540;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x880c0588
	if (ctx.cr6.eq) goto loc_880C0588;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c0558
	if (ctx.cr6.eq) goto loc_880C0558;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C0558:
	// cmplwi cr6,r16,0
	ctx.cr6.compare<uint32_t>(ctx.r16.u32, 0, ctx.xer);
	// beq cr6,0x880c0588
	if (ctx.cr6.eq) goto loc_880C0588;
	// lwz r11,0(r16)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c0588
	if (ctx.cr6.eq) goto loc_880C0588;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C0588:
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// addi r29,r29,20
	ctx.r29.s64 = ctx.r29.s64 + 20;
	// bne 0x880c04a8
	if (!ctx.cr0.eq) goto loc_880C04A8;
	// stw r17,-11932(r15)
	PPC_STORE_U32(ctx.r15.u32 + -11932, ctx.r17.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071174
	__restgprlr_15(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C05A4"))) PPC_WEAK_FUNC(sub_880C05A4);
PPC_FUNC_IMPL(__imp__sub_880C05A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C05A8"))) PPC_WEAK_FUNC(sub_880C05A8);
PPC_FUNC_IMPL(__imp__sub_880C05A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071120
	ctx.lr = 0x880C05B0;
	__savegprlr_14(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r10,184(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// lwz r11,168(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// lwz r25,4(r6)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// add r16,r10,r11
	ctx.r16.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r20,0(r6)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r7,26028(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 26028);
	// addi r15,r16,2
	ctx.r15.s64 = ctx.r16.s64 + 2;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stw r25,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r25.u32);
	// lwz r10,2300(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2300);
	// lwz r11,156(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 156);
	// lwz r10,160(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 160);
	// beq cr6,0x880c0614
	if (ctx.cr6.eq) goto loc_880C0614;
	// srawi r6,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r11.s32 >> 1;
	// addze r5,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r5.s64 = temp.s64;
	// srawi r4,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r4.s64 = ctx.r10.s32 >> 1;
	// subf r9,r5,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r5.s64;
	// addze r3,r4
	temp.s64 = ctx.r4.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r3.s64 = temp.s64;
	// subf r8,r3,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r3.s64;
	// b 0x880c061c
	goto loc_880C061C;
loc_880C0614:
	// subf r9,r11,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r11.s64;
	// subf r8,r10,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r10.s64;
loc_880C061C:
	// mr r24,r9
	ctx.r24.u64 = ctx.r9.u64;
	// lwz r9,14664(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 14664);
	// mr r23,r8
	ctx.r23.u64 = ctx.r8.u64;
	// lwz r8,14668(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 14668);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x880c0650
	if (ctx.cr6.eq) goto loc_880C0650;
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// addze r7,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r7.s64 = temp.s64;
	// srawi r6,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r10.s32 >> 1;
	// subf r19,r7,r9
	ctx.r19.s64 = ctx.r9.s64 - ctx.r7.s64;
	// addze r5,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r5.s64 = temp.s64;
	// subf r18,r5,r8
	ctx.r18.s64 = ctx.r8.s64 - ctx.r5.s64;
	// b 0x880c0658
	goto loc_880C0658;
loc_880C0650:
	// subf r19,r11,r9
	ctx.r19.s64 = ctx.r9.s64 - ctx.r11.s64;
	// subf r18,r10,r8
	ctx.r18.s64 = ctx.r8.s64 - ctx.r10.s64;
loc_880C0658:
	// lis r11,-30667
	ctx.r11.s64 = -2009792512;
	// lis r21,-30597
	ctx.r21.s64 = -2005204992;
	// addi r11,r11,7784
	ctx.r11.s64 = ctx.r11.s64 + 7784;
	// li r22,6
	ctx.r22.s64 = 6;
	// stw r21,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r21.u32);
	// addi r29,r11,4
	ctx.r29.s64 = ctx.r11.s64 + 4;
	// lis r11,-30681
	ctx.r11.s64 = -2010710016;
	// lwz r17,-11932(r21)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r21.u32 + -11932);
	// li r26,10
	ctx.r26.s64 = 10;
	// lis r14,16
	ctx.r14.s64 = 1048576;
	// addi r30,r11,-27392
	ctx.r30.s64 = ctx.r11.s64 + -27392;
loc_880C0684:
	// lwz r10,-4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + -4);
	// addi r9,r30,-1680
	ctx.r9.s64 = ctx.r30.s64 + -1680;
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// addi r4,r30,-1680
	ctx.r4.s64 = ctx.r30.s64 + -1680;
	// mulli r10,r10,88
	ctx.r10.s64 = ctx.r10.s64 * 88;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r7,12(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// lwz r8,4(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// add r6,r10,r31
	ctx.r6.u64 = ctx.r10.u64 + ctx.r31.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r5,r9,4
	ctx.r5.s64 = ctx.r9.s64 + 4;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r9,r3,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r3,10784(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 10784);
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// srawi r3,r3,4
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xF) != 0);
	ctx.r3.s64 = ctx.r3.s32 >> 4;
	// add r10,r11,r31
	ctx.r10.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addze r11,r3
	temp.s64 = ctx.r3.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r11.s64 = temp.s64;
	// lwzx r5,r9,r5
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r5.u32);
	// lwzx r9,r9,r4
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r4.u32);
	// srawi r4,r11,5
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1F) != 0);
	ctx.r4.s64 = ctx.r11.s32 >> 5;
	// addze r3,r4
	temp.s64 = ctx.r4.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r3.s64 = temp.s64;
	// lwz r4,160(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 160);
	// lwz r10,164(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 164);
	// rlwinm r3,r3,5,0,26
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 5) & 0xFFFFFFE0;
	// divw r28,r10,r26
	ctx.r28.s32 = ppc_divw(ctx.r10.s32, ctx.r26.s32);
	// subf r11,r3,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r3.s64;
	// divw r4,r4,r26
	ctx.r4.s32 = ppc_divw(ctx.r4.s32, ctx.r26.s32);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r7,r11
	ctx.r3.u64 = ctx.r7.u64 + ctx.r11.u64;
	// add r11,r10,r8
	ctx.r11.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lbzx r10,r10,r8
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// lbz r8,1(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// extsb r11,r10
	ctx.r11.s64 = ctx.r10.s8;
	// extsb r10,r8
	ctx.r10.s64 = ctx.r8.s8;
	// add r7,r9,r11
	ctx.r7.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r5,r10,r5
	ctx.r5.u64 = ctx.r10.u64 + ctx.r5.u64;
	// rlwinm r11,r7,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r5,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// add r10,r10,r28
	ctx.r10.u64 = ctx.r10.u64 + ctx.r28.u64;
	// add r28,r11,r24
	ctx.r28.u64 = ctx.r11.u64 + ctx.r24.u64;
	// add r27,r10,r23
	ctx.r27.u64 = ctx.r10.u64 + ctx.r23.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// bl 0x881538c0
	ctx.lr = 0x880C0740;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x880c0788
	if (ctx.cr6.eq) goto loc_880C0788;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c0758
	if (ctx.cr6.eq) goto loc_880C0758;
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C0758:
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x880c0790
	if (ctx.cr6.eq) goto loc_880C0790;
	// lwz r11,0(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c0788
	if (ctx.cr6.eq) goto loc_880C0788;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C0788:
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// bne cr6,0x880c0814
	if (!ctx.cr6.eq) goto loc_880C0814;
loc_880C0790:
	// addi r25,r16,-1
	ctx.r25.s64 = ctx.r16.s64 + -1;
	// addis r27,r27,-32
	ctx.r27.s64 = ctx.r27.s64 + -2097152;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r3,15803
	ctx.r3.s64 = 15803;
	// bl 0x881538c0
	ctx.lr = 0x880C07AC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c07d4
	if (ctx.cr6.eq) goto loc_880C07D4;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,192
	ctx.r10.s64 = 12582912;
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// ori r9,r10,49344
	ctx.r9.u64 = ctx.r10.u64 | 49344;
	// oris r8,r11,518
	ctx.r8.u64 = ctx.r11.u64 | 33947648;
	// stw r17,-11932(r21)
	PPC_STORE_U32(ctx.r21.u32 + -11932, ctx.r17.u32);
	// stw r9,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r9.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C07D4:
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// subf r5,r14,r27
	ctx.r5.s64 = ctx.r27.s64 - ctx.r14.s64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r3,15803
	ctx.r3.s64 = 15803;
	// bl 0x881538c0
	ctx.lr = 0x880C07E8;
	sub_881538C0(ctx, base);
	// lwz r25,84(r1)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c0814
	if (ctx.cr6.eq) goto loc_880C0814;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,192
	ctx.r10.s64 = 12582912;
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// ori r9,r10,49344
	ctx.r9.u64 = ctx.r10.u64 | 49344;
	// oris r8,r11,518
	ctx.r8.u64 = ctx.r11.u64 | 33947648;
	// stw r17,-11932(r21)
	PPC_STORE_U32(ctx.r21.u32 + -11932, ctx.r17.u32);
	// stw r9,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r9.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C0814:
	// addic. r22,r22,-1
	ctx.xer.ca = ctx.r22.u32 > 0;
	ctx.r22.s64 = ctx.r22.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// addi r29,r29,20
	ctx.r29.s64 = ctx.r29.s64 + 20;
	// bne 0x880c0684
	if (!ctx.cr0.eq) goto loc_880C0684;
	// lis r11,-30667
	ctx.r11.s64 = -2009792512;
	// stw r17,-11932(r21)
	PPC_STORE_U32(ctx.r21.u32 + -11932, ctx.r17.u32);
	// lis r10,-30667
	ctx.r10.s64 = -2009792512;
	// lwz r27,84(r1)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r25,0
	ctx.r25.s64 = 0;
	// addi r21,r11,7944
	ctx.r21.s64 = ctx.r11.s64 + 7944;
	// addi r22,r10,7904
	ctx.r22.s64 = ctx.r10.s64 + 7904;
loc_880C083C:
	// lwzx r10,r25,r22
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r25.u32 + ctx.r22.u32);
	// add r11,r25,r22
	ctx.r11.u64 = ctx.r25.u64 + ctx.r22.u64;
	// mulli r10,r10,88
	ctx.r10.s64 = ctx.r10.s64 * 88;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + ctx.r31.u64;
	// lwz r9,10784(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 10784);
	// lwz r8,10852(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 10852);
	// srawi r7,r9,4
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xF) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 4;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// addze r10,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r10.s64 = temp.s64;
	// srawi r6,r10,5
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1F) != 0);
	ctx.r6.s64 = ctx.r10.s32 >> 5;
	// addze r5,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r5.s64 = temp.s64;
	// rlwinm r4,r5,5,0,26
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 5) & 0xFFFFFFE0;
	// subf r8,r4,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r4.s64;
	// beq cr6,0x880c087c
	if (ctx.cr6.eq) goto loc_880C087C;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// add r11,r25,r21
	ctx.r11.u64 = ctx.r25.u64 + ctx.r21.u64;
loc_880C087C:
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// addi r5,r30,-1680
	ctx.r5.s64 = ctx.r30.s64 + -1680;
	// rlwinm r6,r9,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// add r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 + ctx.r10.u64;
	// lwz r7,16(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// add r3,r9,r6
	ctx.r3.u64 = ctx.r9.u64 + ctx.r6.u64;
	// addi r9,r5,4
	ctx.r9.s64 = ctx.r5.s64 + 4;
	// rlwinm r6,r4,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r4,r30,-1680
	ctx.r4.s64 = ctx.r30.s64 + -1680;
	// rlwinm r11,r3,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// lbz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// lbz r29,1(r10)
	ctx.r29.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// add r3,r7,r8
	ctx.r3.u64 = ctx.r7.u64 + ctx.r8.u64;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lwzx r10,r6,r9
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// extsb r5,r5
	ctx.r5.s64 = ctx.r5.s8;
	// lwzx r6,r6,r4
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r4.u32);
	// extsb r9,r29
	ctx.r9.s64 = ctx.r29.s8;
	// add r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 + ctx.r5.u64;
	// lwz r5,164(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r8,160(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 160);
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// divw r9,r5,r26
	ctx.r9.s32 = ppc_divw(ctx.r5.s32, ctx.r26.s32);
	// divw r6,r8,r26
	ctx.r6.s32 = ppc_divw(ctx.r8.s32, ctx.r26.s32);
	// rlwinm r11,r7,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// add r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 + ctx.r6.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r29,r10,r24
	ctx.r29.u64 = ctx.r10.u64 + ctx.r24.u64;
	// add r28,r11,r23
	ctx.r28.u64 = ctx.r11.u64 + ctx.r23.u64;
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x881538c0
	ctx.lr = 0x880C0910;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x880c0958
	if (ctx.cr6.eq) goto loc_880C0958;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c0928
	if (ctx.cr6.eq) goto loc_880C0928;
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C0928:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x880c0960
	if (ctx.cr6.eq) goto loc_880C0960;
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c0958
	if (ctx.cr6.eq) goto loc_880C0958;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C0958:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// bne cr6,0x880c09ec
	if (!ctx.cr6.eq) goto loc_880C09EC;
loc_880C0960:
	// addi r27,r16,-1
	ctx.r27.s64 = ctx.r16.s64 + -1;
	// addis r28,r28,-32
	ctx.r28.s64 = ctx.r28.s64 + -2097152;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,15803
	ctx.r3.s64 = 15803;
	// bl 0x881538c0
	ctx.lr = 0x880C097C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c09a8
	if (ctx.cr6.eq) goto loc_880C09A8;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,192
	ctx.r10.s64 = 12582912;
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// ori r8,r10,49344
	ctx.r8.u64 = ctx.r10.u64 | 49344;
	// oris r7,r11,518
	ctx.r7.u64 = ctx.r11.u64 | 33947648;
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r17,-11932(r9)
	PPC_STORE_U32(ctx.r9.u32 + -11932, ctx.r17.u32);
loc_880C09A8:
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// subf r5,r14,r28
	ctx.r5.s64 = ctx.r28.s64 - ctx.r14.s64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,15803
	ctx.r3.s64 = 15803;
	// bl 0x881538c0
	ctx.lr = 0x880C09BC;
	sub_881538C0(ctx, base);
	// lwz r27,84(r1)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c09ec
	if (ctx.cr6.eq) goto loc_880C09EC;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,192
	ctx.r10.s64 = 12582912;
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// ori r8,r10,49344
	ctx.r8.u64 = ctx.r10.u64 | 49344;
	// oris r7,r11,518
	ctx.r7.u64 = ctx.r11.u64 | 33947648;
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r17,-11932(r9)
	PPC_STORE_U32(ctx.r9.u32 + -11932, ctx.r17.u32);
loc_880C09EC:
	// addi r25,r25,20
	ctx.r25.s64 = ctx.r25.s64 + 20;
	// cmplwi cr6,r25,40
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 40, ctx.xer);
	// blt cr6,0x880c083c
	if (ctx.cr6.lt) goto loc_880C083C;
	// lwz r22,80(r1)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r11,-30667
	ctx.r11.s64 = -2009792512;
	// lwz r9,100(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// li r28,6
	ctx.r28.s64 = 6;
	// lwz r10,104(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// addi r11,r11,7984
	ctx.r11.s64 = ctx.r11.s64 + 7984;
	// add r24,r9,r19
	ctx.r24.u64 = ctx.r9.u64 + ctx.r19.u64;
	// add r25,r10,r18
	ctx.r25.u64 = ctx.r10.u64 + ctx.r18.u64;
	// stw r17,-11932(r22)
	PPC_STORE_U32(ctx.r22.u32 + -11932, ctx.r17.u32);
	// addi r29,r11,8
	ctx.r29.s64 = ctx.r11.s64 + 8;
	// stw r24,15156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15156, ctx.r24.u32);
	// stw r25,15160(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15160, ctx.r25.u32);
loc_880C0A28:
	// lwz r11,-8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -8);
	// mulli r11,r11,88
	ctx.r11.s64 = ctx.r11.s64 * 88;
	// add r9,r11,r31
	ctx.r9.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lwz r10,10856(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 10856);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x880c0b28
	if (!ctx.cr6.eq) goto loc_880C0B28;
	// lwz r7,-4(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + -4);
	// addi r10,r30,-1680
	ctx.r10.s64 = ctx.r30.s64 + -1680;
	// addi r6,r30,-1680
	ctx.r6.s64 = ctx.r30.s64 + -1680;
	// lwz r8,10784(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 10784);
	// addi r5,r10,4
	ctx.r5.s64 = ctx.r10.s64 + 4;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// rlwinm r4,r7,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwzx r3,r4,r6
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r6.u32);
	// lwzx r9,r4,r5
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r5.u32);
	// rlwinm r10,r3,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r9,r9,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// add r10,r10,r24
	ctx.r10.u64 = ctx.r10.u64 + ctx.r24.u64;
	// add r9,r9,r25
	ctx.r9.u64 = ctx.r9.u64 + ctx.r25.u64;
	// beq cr6,0x880c0aa4
	if (ctx.cr6.eq) goto loc_880C0AA4;
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 + ctx.r11.u64;
	// lbz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r6,1(r11)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// extsb r5,r7
	ctx.r5.s64 = ctx.r7.s8;
	// extsb r4,r6
	ctx.r4.s64 = ctx.r6.s8;
	// rlwinm r7,r5,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r4,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// add r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 + ctx.r10.u64;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
loc_880C0AA4:
	// lwz r11,4(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r6,8(r29)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r6,r8
	ctx.r3.u64 = ctx.r6.u64 + ctx.r8.u64;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// mr r6,r15
	ctx.r6.u64 = ctx.r15.u64;
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lwz r8,160(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 160);
	// lwz r7,164(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
	// divw r8,r8,r26
	ctx.r8.s32 = ppc_divw(ctx.r8.s32, ctx.r26.s32);
	// divw r11,r7,r26
	ctx.r11.s32 = ppc_divw(ctx.r7.s32, ctx.r26.s32);
	// add r4,r8,r10
	ctx.r4.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r5,r11,r9
	ctx.r5.u64 = ctx.r11.u64 + ctx.r9.u64;
	// bl 0x881538c0
	ctx.lr = 0x880C0AE0;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x880c0b28
	if (ctx.cr6.eq) goto loc_880C0B28;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c0af8
	if (ctx.cr6.eq) goto loc_880C0AF8;
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C0AF8:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x880c0b28
	if (ctx.cr6.eq) goto loc_880C0B28;
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c0b28
	if (ctx.cr6.eq) goto loc_880C0B28;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C0B28:
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// addi r29,r29,20
	ctx.r29.s64 = ctx.r29.s64 + 20;
	// bne 0x880c0a28
	if (!ctx.cr0.eq) goto loc_880C0A28;
	// lwz r11,5924(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5924);
	// lis r3,0
	ctx.r3.s64 = 0;
	// stw r24,10796(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10796, ctx.r24.u32);
	// mr r6,r15
	ctx.r6.u64 = ctx.r15.u64;
	// divw r11,r11,r26
	ctx.r11.s32 = ppc_divw(ctx.r11.s32, ctx.r26.s32);
	// stw r17,-11932(r22)
	PPC_STORE_U32(ctx.r22.u32 + -11932, ctx.r17.u32);
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// add r29,r11,r25
	ctx.r29.u64 = ctx.r11.u64 + ctx.r25.u64;
	// ori r3,r3,34050
	ctx.r3.u64 = ctx.r3.u64 | 34050;
	// stw r29,10800(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10800, ctx.r29.u32);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x881538c0
	ctx.lr = 0x880C0B64;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x880c0bb0
	if (ctx.cr6.eq) goto loc_880C0BB0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c0b7c
	if (ctx.cr6.eq) goto loc_880C0B7C;
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C0B7C:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x880c0bb8
	if (ctx.cr6.eq) goto loc_880C0BB8;
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c0bb0
	if (ctx.cr6.eq) goto loc_880C0BB0;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r17,-11932(r22)
	PPC_STORE_U32(ctx.r22.u32 + -11932, ctx.r17.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C0BB0:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// bne cr6,0x880c0c3c
	if (!ctx.cr6.eq) goto loc_880C0C3C;
loc_880C0BB8:
	// lis r23,32
	ctx.r23.s64 = 2097152;
	// addi r28,r16,-1
	ctx.r28.s64 = ctx.r16.s64 + -1;
	// subf r29,r23,r29
	ctx.r29.s64 = ctx.r29.s64 - ctx.r23.s64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// li r3,15803
	ctx.r3.s64 = 15803;
	// bl 0x881538c0
	ctx.lr = 0x880C0BD8;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c0c00
	if (ctx.cr6.eq) goto loc_880C0C00;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,192
	ctx.r10.s64 = 12582912;
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// ori r9,r10,49344
	ctx.r9.u64 = ctx.r10.u64 | 49344;
	// oris r8,r11,518
	ctx.r8.u64 = ctx.r11.u64 | 33947648;
	// stw r17,-11932(r22)
	PPC_STORE_U32(ctx.r22.u32 + -11932, ctx.r17.u32);
	// stw r9,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r9.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C0C00:
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// subf r5,r23,r29
	ctx.r5.s64 = ctx.r29.s64 - ctx.r23.s64;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// li r3,15803
	ctx.r3.s64 = 15803;
	// bl 0x881538c0
	ctx.lr = 0x880C0C14;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c0c3c
	if (ctx.cr6.eq) goto loc_880C0C3C;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,192
	ctx.r10.s64 = 12582912;
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// ori r9,r10,49344
	ctx.r9.u64 = ctx.r10.u64 | 49344;
	// oris r8,r11,518
	ctx.r8.u64 = ctx.r11.u64 | 33947648;
	// stw r17,-11932(r22)
	PPC_STORE_U32(ctx.r22.u32 + -11932, ctx.r17.u32);
	// stw r9,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r9.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C0C3C:
	// lwz r9,5924(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5924);
	// mr r6,r15
	ctx.r6.u64 = ctx.r15.u64;
	// lwz r11,-1364(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -1364);
	// lwz r10,-1368(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -1368);
	// divw r9,r9,r26
	ctx.r9.s32 = ppc_divw(ctx.r9.s32, ctx.r26.s32);
	// lwz r8,10784(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10784);
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// addis r3,r8,1
	ctx.r3.s64 = ctx.r8.s64 + 65536;
	// add r4,r10,r24
	ctx.r4.u64 = ctx.r10.u64 + ctx.r24.u64;
	// add r5,r11,r25
	ctx.r5.u64 = ctx.r11.u64 + ctx.r25.u64;
	// addi r3,r3,-31175
	ctx.r3.s64 = ctx.r3.s64 + -31175;
	// bl 0x881538c0
	ctx.lr = 0x880C0C74;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x880c0cc0
	if (ctx.cr6.eq) goto loc_880C0CC0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c0c8c
	if (ctx.cr6.eq) goto loc_880C0C8C;
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C0C8C:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x880c0cc0
	if (ctx.cr6.eq) goto loc_880C0CC0;
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c0cc0
	if (ctx.cr6.eq) goto loc_880C0CC0;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r17,-11932(r22)
	PPC_STORE_U32(ctx.r22.u32 + -11932, ctx.r17.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C0CC0:
	// lwz r9,5060(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5060);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r11,-1636(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -1636);
	// mr r6,r15
	ctx.r6.u64 = ctx.r15.u64;
	// lwz r10,-1640(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -1640);
	// divw r9,r9,r26
	ctx.r9.s32 = ppc_divw(ctx.r9.s32, ctx.r26.s32);
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r4,r10,r24
	ctx.r4.u64 = ctx.r10.u64 + ctx.r24.u64;
	// add r5,r11,r25
	ctx.r5.u64 = ctx.r11.u64 + ctx.r25.u64;
	// stw r4,10972(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10972, ctx.r4.u32);
	// ori r3,r3,34056
	ctx.r3.u64 = ctx.r3.u64 | 34056;
	// stw r5,10976(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10976, ctx.r5.u32);
	// bl 0x881538c0
	ctx.lr = 0x880C0CFC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x880c0d48
	if (ctx.cr6.eq) goto loc_880C0D48;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c0d14
	if (ctx.cr6.eq) goto loc_880C0D14;
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C0D14:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x880c0d48
	if (ctx.cr6.eq) goto loc_880C0D48;
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c0d48
	if (ctx.cr6.eq) goto loc_880C0D48;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r17,-11932(r22)
	PPC_STORE_U32(ctx.r22.u32 + -11932, ctx.r17.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C0D48:
	// lwz r11,10940(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10940);
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bgt cr6,0x880c1558
	if (ctx.cr6.gt) goto loc_880C1558;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x880c0fa4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_880C0FA4;
	// bdzf 4*cr6+eq,0x880c1328
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_880C1328;
	// bdzf 4*cr6+eq,0x880c1328
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_880C1328;
	// bdzf 4*cr6+eq,0x880c1328
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_880C1328;
	// bne cr6,0x880c1538
	if (!ctx.cr6.eq) goto loc_880C1538;
	// lwz r11,-1652(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -1652);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r10,-1656(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -1656);
	// mr r6,r15
	ctx.r6.u64 = ctx.r15.u64;
	// rlwinm r9,r11,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lwz r8,5348(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5348);
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// ori r3,r3,34054
	ctx.r3.u64 = ctx.r3.u64 | 34054;
	// add r4,r11,r24
	ctx.r4.u64 = ctx.r11.u64 + ctx.r24.u64;
	// divw r11,r8,r26
	ctx.r11.s32 = ppc_divw(ctx.r8.s32, ctx.r26.s32);
	// stw r4,10884(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10884, ctx.r4.u32);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r5,r11,r25
	ctx.r5.u64 = ctx.r11.u64 + ctx.r25.u64;
	// stw r5,10888(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10888, ctx.r5.u32);
	// bl 0x881538c0
	ctx.lr = 0x880C0DAC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x880c0e04
	if (ctx.cr6.eq) goto loc_880C0E04;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c0dc4
	if (ctx.cr6.eq) goto loc_880C0DC4;
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C0DC4:
	// lwz r23,84(r1)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x880c0e08
	if (ctx.cr6.eq) goto loc_880C0E08;
	// lwz r11,0(r23)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c0e08
	if (ctx.cr6.eq) goto loc_880C0E08;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r27,80(r1)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r17,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r17.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// b 0x880c0e0c
	goto loc_880C0E0C;
loc_880C0E04:
	// lwz r23,84(r1)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_880C0E08:
	// lwz r27,80(r1)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_880C0E0C:
	// lwz r9,5348(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5348);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r11,-1660(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -1660);
	// mr r6,r15
	ctx.r6.u64 = ctx.r15.u64;
	// lwz r10,-1664(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -1664);
	// divw r9,r9,r26
	ctx.r9.s32 = ppc_divw(ctx.r9.s32, ctx.r26.s32);
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r4,r10,r24
	ctx.r4.u64 = ctx.r10.u64 + ctx.r24.u64;
	// add r5,r11,r25
	ctx.r5.u64 = ctx.r11.u64 + ctx.r25.u64;
	// ori r3,r3,34053
	ctx.r3.u64 = ctx.r3.u64 | 34053;
	// bl 0x881538c0
	ctx.lr = 0x880C0E40;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x880c0e8c
	if (ctx.cr6.eq) goto loc_880C0E8C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c0e58
	if (ctx.cr6.eq) goto loc_880C0E58;
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C0E58:
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x880c0e8c
	if (ctx.cr6.eq) goto loc_880C0E8C;
	// lwz r11,0(r23)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c0e8c
	if (ctx.cr6.eq) goto loc_880C0E8C;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r17,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r17.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C0E8C:
	// lwz r9,5348(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5348);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r11,-1644(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -1644);
	// mr r6,r15
	ctx.r6.u64 = ctx.r15.u64;
	// lwz r10,-1648(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -1648);
	// divw r9,r9,r26
	ctx.r9.s32 = ppc_divw(ctx.r9.s32, ctx.r26.s32);
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r29,r10,r24
	ctx.r29.u64 = ctx.r10.u64 + ctx.r24.u64;
	// add r28,r11,r25
	ctx.r28.u64 = ctx.r11.u64 + ctx.r25.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// ori r3,r3,34055
	ctx.r3.u64 = ctx.r3.u64 | 34055;
	// bl 0x881538c0
	ctx.lr = 0x880C0EC8;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x880c0f14
	if (ctx.cr6.eq) goto loc_880C0F14;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c0ee0
	if (ctx.cr6.eq) goto loc_880C0EE0;
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C0EE0:
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x880c0f1c
	if (ctx.cr6.eq) goto loc_880C0F1C;
	// lwz r11,0(r23)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c0f14
	if (ctx.cr6.eq) goto loc_880C0F14;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r17,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r17.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C0F14:
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// bne cr6,0x880c1558
	if (!ctx.cr6.eq) goto loc_880C1558;
loc_880C0F1C:
	// addi r27,r16,-1
	ctx.r27.s64 = ctx.r16.s64 + -1;
	// addis r28,r28,-32
	ctx.r28.s64 = ctx.r28.s64 + -2097152;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,15803
	ctx.r3.s64 = 15803;
	// bl 0x881538c0
	ctx.lr = 0x880C0F38;
	sub_881538C0(ctx, base);
	// lwz r23,80(r1)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c0f64
	if (ctx.cr6.eq) goto loc_880C0F64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,192
	ctx.r10.s64 = 12582912;
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// ori r9,r10,49344
	ctx.r9.u64 = ctx.r10.u64 | 49344;
	// oris r8,r11,518
	ctx.r8.u64 = ctx.r11.u64 | 33947648;
	// stw r17,-11932(r23)
	PPC_STORE_U32(ctx.r23.u32 + -11932, ctx.r17.u32);
	// stw r9,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r9.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C0F64:
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// subf r5,r14,r28
	ctx.r5.s64 = ctx.r28.s64 - ctx.r14.s64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,15803
	ctx.r3.s64 = 15803;
	// bl 0x881538c0
	ctx.lr = 0x880C0F78;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c1558
	if (ctx.cr6.eq) goto loc_880C1558;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,192
	ctx.r10.s64 = 12582912;
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// ori r9,r10,49344
	ctx.r9.u64 = ctx.r10.u64 | 49344;
	// oris r8,r11,518
	ctx.r8.u64 = ctx.r11.u64 | 33947648;
	// stw r17,-11932(r23)
	PPC_STORE_U32(ctx.r23.u32 + -11932, ctx.r17.u32);
	// stw r9,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r9.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// b 0x880c1558
	goto loc_880C1558;
loc_880C0FA4:
	// addi r11,r30,-128
	ctx.r11.s64 = ctx.r30.s64 + -128;
	// lwz r3,5636(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5636);
	// addi r5,r30,-128
	ctx.r5.s64 = ctx.r30.s64 + -128;
	// lwz r10,-1380(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -1380);
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// lwz r11,13336(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 13336);
	// divw r6,r3,r26
	ctx.r6.s32 = ppc_divw(ctx.r3.s32, ctx.r26.s32);
	// lwz r9,-1384(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + -1384);
	// rlwinm r27,r11,1,0,30
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,5632(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5632);
	// lwz r28,5348(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5348);
	// lis r29,128
	ctx.r29.s64 = 8388608;
	// divw r7,r8,r26
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r26.s32);
	// divw r8,r28,r26
	ctx.r8.s32 = ppc_divw(ctx.r28.s32, ctx.r26.s32);
	// ori r29,r29,32896
	ctx.r29.u64 = ctx.r29.u64 | 32896;
	// lbzx r4,r27,r4
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r27.u32 + ctx.r4.u32);
	// addi r28,r31,15416
	ctx.r28.s64 = ctx.r31.s64 + 15416;
	// lbzx r3,r27,r5
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r27.u32 + ctx.r5.u32);
	// extsb r4,r4
	ctx.r4.s64 = ctx.r4.s8;
	// extsb r5,r3
	ctx.r5.s64 = ctx.r3.s8;
	// add r10,r4,r10
	ctx.r10.u64 = ctx.r4.u64 + ctx.r10.u64;
	// add r9,r5,r9
	ctx.r9.u64 = ctx.r5.u64 + ctx.r9.u64;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r9,r9,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// add r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 + ctx.r6.u64;
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r4,r9,r24
	ctx.r4.u64 = ctx.r9.u64 + ctx.r24.u64;
	// add r5,r10,r25
	ctx.r5.u64 = ctx.r10.u64 + ctx.r25.u64;
	// addis r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 65536;
	// stw r4,13348(r31)
	PPC_STORE_U32(ctx.r31.u32 + 13348, ctx.r4.u32);
	// stw r5,13352(r31)
	PPC_STORE_U32(ctx.r31.u32 + 13352, ctx.r5.u32);
	// mr r6,r15
	ctx.r6.u64 = ctx.r15.u64;
	// lwz r8,15416(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 15416);
	// cmplw cr6,r8,r29
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r29.u32, ctx.xer);
	// stw r4,15300(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15300, ctx.r4.u32);
	// addi r3,r3,-31239
	ctx.r3.s64 = ctx.r3.s64 + -31239;
	// stw r5,15304(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15304, ctx.r5.u32);
	// beq cr6,0x880c109c
	if (ctx.cr6.eq) goto loc_880C109C;
	// bl 0x881538c0
	ctx.lr = 0x880C1044;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x880c10f8
	if (ctx.cr6.eq) goto loc_880C10F8;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c105c
	if (ctx.cr6.eq) goto loc_880C105C;
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C105C:
	// lwz r23,84(r1)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x880c10fc
	if (ctx.cr6.eq) goto loc_880C10FC;
	// lwz r11,0(r23)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c10fc
	if (ctx.cr6.eq) goto loc_880C10FC;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r27,80(r1)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r17,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r17.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// b 0x880c1100
	goto loc_880C1100;
loc_880C109C:
	// bl 0x881538c0
	ctx.lr = 0x880C10A0;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x880c10f8
	if (ctx.cr6.eq) goto loc_880C10F8;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c10b8
	if (ctx.cr6.eq) goto loc_880C10B8;
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C10B8:
	// lwz r23,84(r1)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x880c10fc
	if (ctx.cr6.eq) goto loc_880C10FC;
	// lwz r11,0(r23)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c10fc
	if (ctx.cr6.eq) goto loc_880C10FC;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r27,80(r1)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r17,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r17.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// b 0x880c1100
	goto loc_880C1100;
loc_880C10F8:
	// lwz r23,84(r1)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_880C10FC:
	// lwz r27,80(r1)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_880C1100:
	// addi r11,r30,-64
	ctx.r11.s64 = ctx.r30.s64 + -64;
	// lwz r3,5924(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5924);
	// addi r5,r30,-64
	ctx.r5.s64 = ctx.r30.s64 + -64;
	// lwz r10,-1372(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -1372);
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// lwz r11,13424(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 13424);
	// divw r6,r3,r26
	ctx.r6.s32 = ppc_divw(ctx.r3.s32, ctx.r26.s32);
	// lwz r9,-1376(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + -1376);
	// rlwinm r22,r11,1,0,30
	ctx.r22.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,5920(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5920);
	// lwz r21,5348(r31)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5348);
	// addi r28,r31,15560
	ctx.r28.s64 = ctx.r31.s64 + 15560;
	// divw r7,r8,r26
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r26.s32);
	// divw r8,r21,r26
	ctx.r8.s32 = ppc_divw(ctx.r21.s32, ctx.r26.s32);
	// lbzx r4,r22,r4
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r22.u32 + ctx.r4.u32);
	// lbzx r3,r22,r5
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r22.u32 + ctx.r5.u32);
	// extsb r4,r4
	ctx.r4.s64 = ctx.r4.s8;
	// extsb r5,r3
	ctx.r5.s64 = ctx.r3.s8;
	// add r10,r4,r10
	ctx.r10.u64 = ctx.r4.u64 + ctx.r10.u64;
	// add r9,r5,r9
	ctx.r9.u64 = ctx.r5.u64 + ctx.r9.u64;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r9,r9,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// add r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 + ctx.r6.u64;
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r4,r9,r24
	ctx.r4.u64 = ctx.r9.u64 + ctx.r24.u64;
	// add r5,r10,r25
	ctx.r5.u64 = ctx.r10.u64 + ctx.r25.u64;
	// addis r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 65536;
	// stw r4,13436(r31)
	PPC_STORE_U32(ctx.r31.u32 + 13436, ctx.r4.u32);
	// stw r5,13440(r31)
	PPC_STORE_U32(ctx.r31.u32 + 13440, ctx.r5.u32);
	// mr r6,r15
	ctx.r6.u64 = ctx.r15.u64;
	// lwz r8,15560(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 15560);
	// cmplw cr6,r8,r29
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r29.u32, ctx.xer);
	// stw r4,15444(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15444, ctx.r4.u32);
	// addi r3,r3,-31207
	ctx.r3.s64 = ctx.r3.s64 + -31207;
	// stw r5,15448(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15448, ctx.r5.u32);
	// beq cr6,0x880c11b0
	if (ctx.cr6.eq) goto loc_880C11B0;
	// bl 0x881538c0
	ctx.lr = 0x880C1198;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x880c1200
	if (ctx.cr6.eq) goto loc_880C1200;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c11cc
	if (ctx.cr6.eq) goto loc_880C11CC;
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// b 0x880c11c8
	goto loc_880C11C8;
loc_880C11B0:
	// bl 0x881538c0
	ctx.lr = 0x880C11B4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x880c1200
	if (ctx.cr6.eq) goto loc_880C1200;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c11cc
	if (ctx.cr6.eq) goto loc_880C11CC;
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
loc_880C11C8:
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C11CC:
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x880c1200
	if (ctx.cr6.eq) goto loc_880C1200;
	// lwz r11,0(r23)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c1200
	if (ctx.cr6.eq) goto loc_880C1200;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r17,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r17.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C1200:
	// lwz r9,5348(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5348);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r11,-1652(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -1652);
	// mr r6,r15
	ctx.r6.u64 = ctx.r15.u64;
	// lwz r10,-1656(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -1656);
	// divw r9,r9,r26
	ctx.r9.s32 = ppc_divw(ctx.r9.s32, ctx.r26.s32);
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r29,r10,r24
	ctx.r29.u64 = ctx.r10.u64 + ctx.r24.u64;
	// add r28,r11,r25
	ctx.r28.u64 = ctx.r11.u64 + ctx.r25.u64;
	// stw r29,10884(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10884, ctx.r29.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r28,10888(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10888, ctx.r28.u32);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// ori r3,r3,34054
	ctx.r3.u64 = ctx.r3.u64 | 34054;
	// bl 0x881538c0
	ctx.lr = 0x880C1244;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x880c1290
	if (ctx.cr6.eq) goto loc_880C1290;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c125c
	if (ctx.cr6.eq) goto loc_880C125C;
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C125C:
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x880c1298
	if (ctx.cr6.eq) goto loc_880C1298;
	// lwz r11,0(r23)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c1290
	if (ctx.cr6.eq) goto loc_880C1290;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r17,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r17.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C1290:
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// bne cr6,0x880c1558
	if (!ctx.cr6.eq) goto loc_880C1558;
loc_880C1298:
	// lis r23,32
	ctx.r23.s64 = 2097152;
	// addi r27,r16,-1
	ctx.r27.s64 = ctx.r16.s64 + -1;
	// subf r28,r23,r28
	ctx.r28.s64 = ctx.r28.s64 - ctx.r23.s64;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,15803
	ctx.r3.s64 = 15803;
	// bl 0x881538c0
	ctx.lr = 0x880C12B8;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c12e4
	if (ctx.cr6.eq) goto loc_880C12E4;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,192
	ctx.r10.s64 = 12582912;
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// ori r8,r10,49344
	ctx.r8.u64 = ctx.r10.u64 | 49344;
	// oris r7,r11,518
	ctx.r7.u64 = ctx.r11.u64 | 33947648;
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r17,-11932(r9)
	PPC_STORE_U32(ctx.r9.u32 + -11932, ctx.r17.u32);
loc_880C12E4:
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// subf r5,r23,r28
	ctx.r5.s64 = ctx.r28.s64 - ctx.r23.s64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,15803
	ctx.r3.s64 = 15803;
	// bl 0x881538c0
	ctx.lr = 0x880C12F8;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c1558
	if (ctx.cr6.eq) goto loc_880C1558;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,192
	ctx.r10.s64 = 12582912;
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// ori r8,r10,49344
	ctx.r8.u64 = ctx.r10.u64 | 49344;
	// oris r7,r11,518
	ctx.r7.u64 = ctx.r11.u64 | 33947648;
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r17,-11932(r9)
	PPC_STORE_U32(ctx.r9.u32 + -11932, ctx.r17.u32);
	// b 0x880c1558
	goto loc_880C1558;
loc_880C1328:
	// lwz r28,10872(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10872);
	// addi r9,r30,32
	ctx.r9.s64 = ctx.r30.s64 + 32;
	// addi r7,r30,32
	ctx.r7.s64 = ctx.r30.s64 + 32;
	// lwz r4,5348(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5348);
	// addi r5,r9,1
	ctx.r5.s64 = ctx.r9.s64 + 1;
	// lwz r11,-1348(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -1348);
	// rlwinm r29,r28,1,0,30
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,-1352(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -1352);
	// divw r8,r4,r26
	ctx.r8.s32 = ppc_divw(ctx.r4.s32, ctx.r26.s32);
	// lwz r9,10532(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10532);
	// addis r3,r28,1
	ctx.r3.s64 = ctx.r28.s64 + 65536;
	// addi r6,r15,-3
	ctx.r6.s64 = ctx.r15.s64 + -3;
	// addi r3,r3,-31143
	ctx.r3.s64 = ctx.r3.s64 + -31143;
	// lbzx r5,r29,r5
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r5.u32);
	// lbzx r4,r29,r7
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r7.u32);
	// extsb r5,r5
	ctx.r5.s64 = ctx.r5.s8;
	// extsb r7,r4
	ctx.r7.s64 = ctx.r4.s8;
	// add r11,r5,r11
	ctx.r11.u64 = ctx.r5.u64 + ctx.r11.u64;
	// add r7,r7,r10
	ctx.r7.u64 = ctx.r7.u64 + ctx.r10.u64;
	// rlwinm r10,r11,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r7,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r4,r11,r24
	ctx.r4.u64 = ctx.r11.u64 + ctx.r24.u64;
	// add r11,r10,r9
	ctx.r11.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r5,r11,r25
	ctx.r5.u64 = ctx.r11.u64 + ctx.r25.u64;
	// bl 0x881538c0
	ctx.lr = 0x880C1390;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x880c13e8
	if (ctx.cr6.eq) goto loc_880C13E8;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c13a8
	if (ctx.cr6.eq) goto loc_880C13A8;
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C13A8:
	// lwz r23,84(r1)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x880c13ec
	if (ctx.cr6.eq) goto loc_880C13EC;
	// lwz r11,0(r23)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c13ec
	if (ctx.cr6.eq) goto loc_880C13EC;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r27,80(r1)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r17,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r17.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// b 0x880c13f0
	goto loc_880C13F0;
loc_880C13E8:
	// lwz r23,84(r1)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_880C13EC:
	// lwz r27,80(r1)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_880C13F0:
	// lbzx r7,r29,r30
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r30.u32);
	// addi r8,r30,1
	ctx.r8.s64 = ctx.r30.s64 + 1;
	// lwz r11,-1360(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -1360);
	// addis r3,r28,1
	ctx.r3.s64 = ctx.r28.s64 + 65536;
	// extsb r7,r7
	ctx.r7.s64 = ctx.r7.s8;
	// lwz r5,5348(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5348);
	// lwz r10,-1356(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -1356);
	// addi r3,r3,-31159
	ctx.r3.s64 = ctx.r3.s64 + -31159;
	// add r4,r7,r11
	ctx.r4.u64 = ctx.r7.u64 + ctx.r11.u64;
	// lwz r9,10532(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10532);
	// lbzx r7,r29,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r8.u32);
	// divw r8,r5,r26
	ctx.r8.s32 = ppc_divw(ctx.r5.s32, ctx.r26.s32);
	// rlwinm r11,r4,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// extsb r7,r7
	ctx.r7.s64 = ctx.r7.s8;
	// add r29,r11,r24
	ctx.r29.u64 = ctx.r11.u64 + ctx.r24.u64;
	// add r5,r7,r10
	ctx.r5.u64 = ctx.r7.u64 + ctx.r10.u64;
	// stw r29,10884(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10884, ctx.r29.u32);
	// addi r6,r15,-1
	ctx.r6.s64 = ctx.r15.s64 + -1;
	// rlwinm r11,r5,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r28,r11,r25
	ctx.r28.u64 = ctx.r11.u64 + ctx.r25.u64;
	// stw r28,10888(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10888, ctx.r28.u32);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x881538c0
	ctx.lr = 0x880C1458;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x880c14a4
	if (ctx.cr6.eq) goto loc_880C14A4;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c1470
	if (ctx.cr6.eq) goto loc_880C1470;
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C1470:
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x880c14ac
	if (ctx.cr6.eq) goto loc_880C14AC;
	// lwz r11,0(r23)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c14a4
	if (ctx.cr6.eq) goto loc_880C14A4;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r17,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r17.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C14A4:
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// bne cr6,0x880c1558
	if (!ctx.cr6.eq) goto loc_880C1558;
loc_880C14AC:
	// addi r27,r16,-1
	ctx.r27.s64 = ctx.r16.s64 + -1;
	// addis r28,r28,-32
	ctx.r28.s64 = ctx.r28.s64 + -2097152;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,15803
	ctx.r3.s64 = 15803;
	// bl 0x881538c0
	ctx.lr = 0x880C14C8;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c14f4
	if (ctx.cr6.eq) goto loc_880C14F4;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,192
	ctx.r10.s64 = 12582912;
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// ori r8,r10,49344
	ctx.r8.u64 = ctx.r10.u64 | 49344;
	// oris r7,r11,518
	ctx.r7.u64 = ctx.r11.u64 | 33947648;
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r17,-11932(r9)
	PPC_STORE_U32(ctx.r9.u32 + -11932, ctx.r17.u32);
loc_880C14F4:
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// subf r5,r14,r28
	ctx.r5.s64 = ctx.r28.s64 - ctx.r14.s64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,15803
	ctx.r3.s64 = 15803;
	// bl 0x881538c0
	ctx.lr = 0x880C1508;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c1558
	if (ctx.cr6.eq) goto loc_880C1558;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,192
	ctx.r10.s64 = 12582912;
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// ori r8,r10,49344
	ctx.r8.u64 = ctx.r10.u64 | 49344;
	// oris r7,r11,518
	ctx.r7.u64 = ctx.r11.u64 | 33947648;
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r17,-11932(r9)
	PPC_STORE_U32(ctx.r9.u32 + -11932, ctx.r17.u32);
	// b 0x880c1558
	goto loc_880C1558;
loc_880C1538:
	// lwz r11,-1652(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -1652);
	// lwz r10,-1656(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -1656);
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r25
	ctx.r11.u64 = ctx.r11.u64 + ctx.r25.u64;
	// add r10,r10,r24
	ctx.r10.u64 = ctx.r10.u64 + ctx.r24.u64;
	// stw r11,10888(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10888, ctx.r11.u32);
	// stw r10,10884(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10884, ctx.r10.u32);
loc_880C1558:
	// lwz r10,4772(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4772);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r9,3620(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 3620);
	// mr r6,r15
	ctx.r6.u64 = ctx.r15.u64;
	// lwz r11,-1676(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -1676);
	// divw r8,r10,r26
	ctx.r8.s32 = ppc_divw(ctx.r10.s32, ctx.r26.s32);
	// lwz r10,-1680(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -1680);
	// divw r9,r9,r26
	ctx.r9.s32 = ppc_divw(ctx.r9.s32, ctx.r26.s32);
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r28,r8,r25
	ctx.r28.u64 = ctx.r8.u64 + ctx.r25.u64;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r4,r10,r24
	ctx.r4.u64 = ctx.r10.u64 + ctx.r24.u64;
	// add r5,r11,r28
	ctx.r5.u64 = ctx.r11.u64 + ctx.r28.u64;
	// stw r4,12996(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12996, ctx.r4.u32);
	// ori r3,r3,34051
	ctx.r3.u64 = ctx.r3.u64 | 34051;
	// stw r5,13000(r31)
	PPC_STORE_U32(ctx.r31.u32 + 13000, ctx.r5.u32);
	// bl 0x881538c0
	ctx.lr = 0x880C15A0;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x880c15f8
	if (ctx.cr6.eq) goto loc_880C15F8;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c15b8
	if (ctx.cr6.eq) goto loc_880C15B8;
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C15B8:
	// lwz r25,84(r1)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x880c15fc
	if (ctx.cr6.eq) goto loc_880C15FC;
	// lwz r11,0(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c15fc
	if (ctx.cr6.eq) goto loc_880C15FC;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r23,80(r1)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r17,-11932(r23)
	PPC_STORE_U32(ctx.r23.u32 + -11932, ctx.r17.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// b 0x880c1600
	goto loc_880C1600;
loc_880C15F8:
	// lwz r25,84(r1)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_880C15FC:
	// lwz r23,80(r1)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_880C1600:
	// lis r11,-30667
	ctx.r11.s64 = -2009792512;
	// li r27,16
	ctx.r27.s64 = 16;
	// addi r11,r11,8104
	ctx.r11.s64 = ctx.r11.s64 + 8104;
	// addi r29,r11,8
	ctx.r29.s64 = ctx.r11.s64 + 8;
loc_880C1610:
	// lwz r9,-4(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + -4);
	// addi r10,r30,-1680
	ctx.r10.s64 = ctx.r30.s64 + -1680;
	// lwz r8,-8(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + -8);
	// addi r7,r30,-1680
	ctx.r7.s64 = ctx.r30.s64 + -1680;
	// addi r6,r10,4
	ctx.r6.s64 = ctx.r10.s64 + 4;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// rlwinm r5,r9,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// mulli r10,r8,88
	ctx.r10.s64 = ctx.r8.s64 * 88;
	// lwzx r4,r5,r7
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r7.u32);
	// lwzx r3,r5,r6
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r6.u32);
	// add r8,r10,r31
	ctx.r8.u64 = ctx.r10.u64 + ctx.r31.u64;
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r9,r3,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 16) & 0xFFFF0000;
	// add r10,r10,r24
	ctx.r10.u64 = ctx.r10.u64 + ctx.r24.u64;
	// add r9,r9,r28
	ctx.r9.u64 = ctx.r9.u64 + ctx.r28.u64;
	// lwz r8,10784(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 10784);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880c1680
	if (ctx.cr6.eq) goto loc_880C1680;
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 + ctx.r11.u64;
	// lbz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r6,1(r11)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// extsb r5,r7
	ctx.r5.s64 = ctx.r7.s8;
	// extsb r4,r6
	ctx.r4.s64 = ctx.r6.s8;
	// rlwinm r7,r5,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r4,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// add r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 + ctx.r10.u64;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
loc_880C1680:
	// lwz r11,4(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r6,8(r29)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r6,r8
	ctx.r3.u64 = ctx.r6.u64 + ctx.r8.u64;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// mr r6,r15
	ctx.r6.u64 = ctx.r15.u64;
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lwz r8,160(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 160);
	// lwz r7,164(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
	// divw r8,r8,r26
	ctx.r8.s32 = ppc_divw(ctx.r8.s32, ctx.r26.s32);
	// divw r11,r7,r26
	ctx.r11.s32 = ppc_divw(ctx.r7.s32, ctx.r26.s32);
	// add r4,r8,r10
	ctx.r4.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r5,r11,r9
	ctx.r5.u64 = ctx.r11.u64 + ctx.r9.u64;
	// bl 0x881538c0
	ctx.lr = 0x880C16BC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x880c1704
	if (ctx.cr6.eq) goto loc_880C1704;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c16d4
	if (ctx.cr6.eq) goto loc_880C16D4;
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C16D4:
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x880c1704
	if (ctx.cr6.eq) goto loc_880C1704;
	// lwz r11,0(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c1704
	if (ctx.cr6.eq) goto loc_880C1704;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C1704:
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// addi r29,r29,20
	ctx.r29.s64 = ctx.r29.s64 + 20;
	// bne 0x880c1610
	if (!ctx.cr0.eq) goto loc_880C1610;
	// stw r17,-11932(r23)
	PPC_STORE_U32(ctx.r23.u32 + -11932, ctx.r17.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C1720"))) PPC_WEAK_FUNC(sub_880C1720);
PPC_FUNC_IMPL(__imp__sub_880C1720) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071120
	ctx.lr = 0x880C1728;
	__savegprlr_14(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// li r10,128
	ctx.r10.s64 = 128;
	// lis r27,-30597
	ctx.r27.s64 = -2005204992;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r31,r11,15784
	ctx.r31.s64 = ctx.r11.s64 + 15784;
	// lis r11,96
	ctx.r11.s64 = 6291456;
	// lis r10,0
	ctx.r10.s64 = 0;
	// li r25,3
	ctx.r25.s64 = 3;
	// lwz r28,-11932(r27)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
	// ori r20,r11,4224
	ctx.r20.u64 = ctx.r11.u64 | 4224;
	// ori r23,r10,45166
	ctx.r23.u64 = ctx.r10.u64 | 45166;
	// lis r16,80
	ctx.r16.s64 = 5242880;
	// lis r26,24
	ctx.r26.s64 = 1572864;
	// lis r24,16
	ctx.r24.s64 = 1048576;
	// lis r19,40
	ctx.r19.s64 = 2621440;
	// lis r21,64
	ctx.r21.s64 = 4194304;
	// lis r17,88
	ctx.r17.s64 = 5767168;
	// lis r22,32
	ctx.r22.s64 = 2097152;
	// lis r18,8
	ctx.r18.s64 = 524288;
loc_880C1778:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x880c1b6c
	if (!ctx.cr6.eq) goto loc_880C1B6C;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x880c1b6c
	if (ctx.cr6.gt) goto loc_880C1B6C;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x880c184c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_880C184C;
	// bdzf 4*cr6+eq,0x880c18f0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_880C18F0;
	// bne cr6,0x880c19a8
	if (!ctx.cr6.eq) goto loc_880C19A8;
	// lwz r30,12(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r29,16(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r6,52(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addi r3,r11,372
	ctx.r3.s64 = ctx.r11.s64 + 372;
	// bl 0x881538c0
	ctx.lr = 0x880C17C4;
	sub_881538C0(ctx, base);
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c17fc
	if (ctx.cr6.eq) goto loc_880C17FC;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r8,128
	ctx.r8.s64 = 8388608;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// ori r7,r8,24592
	ctx.r7.u64 = ctx.r8.u64 | 24592;
	// or r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 | ctx.r9.u64;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// stw r7,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r7.u32);
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
loc_880C17FC:
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// divw r10,r10,r25
	ctx.r10.s32 = ppc_divw(ctx.r10.s32, ctx.r25.s32);
	// addi r6,r11,1
	ctx.r6.s64 = ctx.r11.s64 + 1;
	// addi r3,r10,372
	ctx.r3.s64 = ctx.r10.s64 + 372;
	// bl 0x881538c0
	ctx.lr = 0x880C181C;
	sub_881538C0(ctx, base);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r9,24
	ctx.r11.u64 = ctx.r9.u32 & 0xFF;
	// beq cr6,0x880c1b6c
	if (ctx.cr6.eq) goto loc_880C1B6C;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r28,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r28.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// b 0x880c1b6c
	goto loc_880C1B6C;
loc_880C184C:
	// lwz r30,12(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r29,16(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r6,52(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addi r3,r11,372
	ctx.r3.s64 = ctx.r11.s64 + 372;
	// bl 0x881538c0
	ctx.lr = 0x880C186C;
	sub_881538C0(ctx, base);
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c18a0
	if (ctx.cr6.eq) goto loc_880C18A0;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// stw r20,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r20.u32);
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r28,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r28.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C18A0:
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// divw r10,r10,r25
	ctx.r10.s32 = ppc_divw(ctx.r10.s32, ctx.r25.s32);
	// addi r6,r11,1
	ctx.r6.s64 = ctx.r11.s64 + 1;
	// addi r3,r10,372
	ctx.r3.s64 = ctx.r10.s64 + 372;
	// bl 0x881538c0
	ctx.lr = 0x880C18C0;
	sub_881538C0(ctx, base);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r9,24
	ctx.r11.u64 = ctx.r9.u32 & 0xFF;
	// beq cr6,0x880c1b6c
	if (ctx.cr6.eq) goto loc_880C1B6C;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r28,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r28.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// b 0x880c1b6c
	goto loc_880C1B6C;
loc_880C18F0:
	// lwz r30,12(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r29,16(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r6,52(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// add r3,r11,r23
	ctx.r3.u64 = ctx.r11.u64 + ctx.r23.u64;
	// bl 0x881538c0
	ctx.lr = 0x880C1910;
	sub_881538C0(ctx, base);
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r10,r11,32
	ctx.r10.s64 = ctx.r11.s64 + 32;
	// clrlwi r11,r10,24
	ctx.r11.u64 = ctx.r10.u32 & 0xFF;
	// beq cr6,0x880c1944
	if (ctx.cr6.eq) goto loc_880C1944;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// stw r20,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r20.u32);
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r28,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r28.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C1944:
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r6,r11,1
	ctx.r6.s64 = ctx.r11.s64 + 1;
	// divw r8,r9,r25
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r25.s32);
	// add r3,r8,r23
	ctx.r3.u64 = ctx.r8.u64 + ctx.r23.u64;
	// bl 0x881538c0
	ctx.lr = 0x880C1968;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c1984
	if (ctx.cr6.eq) goto loc_880C1984;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// oris r10,r11,519
	ctx.r10.u64 = ctx.r11.u64 | 34013184;
	// stw r28,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r28.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_880C1984:
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c1b6c
	if (ctx.cr6.eq) goto loc_880C1B6C;
	// rlwinm r10,r11,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// rlwinm r8,r9,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// or r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 | ctx.r11.u64;
	// stw r7,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r7.u32);
	// b 0x880c1b6c
	goto loc_880C1B6C;
loc_880C19A8:
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880c1a54
	if (!ctx.cr6.eq) goto loc_880C1A54;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r3,966
	ctx.r3.s64 = 966;
	// lwz r30,16(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r29,52(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// subf r15,r16,r11
	ctx.r15.s64 = ctx.r11.s64 - ctx.r16.s64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r4,r15
	ctx.r4.u64 = ctx.r15.u64;
	// bl 0x881538c0
	ctx.lr = 0x880C19D8;
	sub_881538C0(ctx, base);
	// add r14,r15,r26
	ctx.r14.u64 = ctx.r15.u64 + ctx.r26.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r4,r14
	ctx.r4.u64 = ctx.r14.u64;
	// add r5,r30,r24
	ctx.r5.u64 = ctx.r30.u64 + ctx.r24.u64;
	// li r3,967
	ctx.r3.s64 = 967;
	// bl 0x881538c0
	ctx.lr = 0x880C19F0;
	sub_881538C0(ctx, base);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r14
	ctx.r4.u64 = ctx.r14.u64;
	// li r3,968
	ctx.r3.s64 = 968;
	// bl 0x881538c0
	ctx.lr = 0x880C1A04;
	sub_881538C0(ctx, base);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// subf r5,r19,r30
	ctx.r5.s64 = ctx.r30.s64 - ctx.r19.s64;
	// add r4,r15,r24
	ctx.r4.u64 = ctx.r15.u64 + ctx.r24.u64;
	// li r3,969
	ctx.r3.s64 = 969;
	// bl 0x881538c0
	ctx.lr = 0x880C1A18;
	sub_881538C0(ctx, base);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// addis r5,r30,-72
	ctx.r5.s64 = ctx.r30.s64 + -4718592;
	// add r4,r15,r21
	ctx.r4.u64 = ctx.r15.u64 + ctx.r21.u64;
	// li r3,970
	ctx.r3.s64 = 970;
	// bl 0x881538c0
	ctx.lr = 0x880C1A2C;
	sub_881538C0(ctx, base);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// subf r5,r17,r30
	ctx.r5.s64 = ctx.r30.s64 - ctx.r17.s64;
	// add r4,r15,r16
	ctx.r4.u64 = ctx.r15.u64 + ctx.r16.u64;
	// li r3,971
	ctx.r3.s64 = 971;
	// bl 0x881538c0
	ctx.lr = 0x880C1A40;
	sub_881538C0(ctx, base);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// addis r5,r30,-112
	ctx.r5.s64 = ctx.r30.s64 + -7340032;
	// add r4,r15,r17
	ctx.r4.u64 = ctx.r15.u64 + ctx.r17.u64;
	// li r3,972
	ctx.r3.s64 = 972;
	// bl 0x881538c0
	ctx.lr = 0x880C1A54;
	sub_881538C0(ctx, base);
loc_880C1A54:
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x880c1b10
	if (!ctx.cr6.eq) goto loc_880C1B10;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r3,973
	ctx.r3.s64 = 973;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r30,52(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// subf r29,r22,r11
	ctx.r29.s64 = ctx.r11.s64 - ctx.r22.s64;
	// add r16,r10,r21
	ctx.r16.u64 = ctx.r10.u64 + ctx.r21.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r16
	ctx.r5.u64 = ctx.r16.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x881538c0
	ctx.lr = 0x880C1A88;
	sub_881538C0(ctx, base);
	// subf r15,r22,r16
	ctx.r15.s64 = ctx.r16.s64 - ctx.r22.s64;
	// subf r14,r18,r29
	ctx.r14.s64 = ctx.r29.s64 - ctx.r18.s64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r15
	ctx.r5.u64 = ctx.r15.u64;
	// mr r4,r14
	ctx.r4.u64 = ctx.r14.u64;
	// li r3,974
	ctx.r3.s64 = 974;
	// bl 0x881538c0
	ctx.lr = 0x880C1AA4;
	sub_881538C0(ctx, base);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r15
	ctx.r5.u64 = ctx.r15.u64;
	// addis r4,r29,56
	ctx.r4.s64 = ctx.r29.s64 + 3670016;
	// li r3,975
	ctx.r3.s64 = 975;
	// bl 0x881538c0
	ctx.lr = 0x880C1AB8;
	sub_881538C0(ctx, base);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r4,r14
	ctx.r4.u64 = ctx.r14.u64;
	// addis r5,r16,-104
	ctx.r5.s64 = ctx.r16.s64 + -6815744;
	// li r3,976
	ctx.r3.s64 = 976;
	// bl 0x881538c0
	ctx.lr = 0x880C1ACC;
	sub_881538C0(ctx, base);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// addis r5,r16,-136
	ctx.r5.s64 = ctx.r16.s64 + -8912896;
	// mr r4,r14
	ctx.r4.u64 = ctx.r14.u64;
	// li r3,977
	ctx.r3.s64 = 977;
	// bl 0x881538c0
	ctx.lr = 0x880C1AE0;
	sub_881538C0(ctx, base);
	// addis r16,r16,-160
	ctx.r16.s64 = ctx.r16.s64 + -10485760;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r16
	ctx.r5.u64 = ctx.r16.u64;
	// add r4,r29,r18
	ctx.r4.u64 = ctx.r29.u64 + ctx.r18.u64;
	// li r3,978
	ctx.r3.s64 = 978;
	// bl 0x881538c0
	ctx.lr = 0x880C1AF8;
	sub_881538C0(ctx, base);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r16
	ctx.r5.u64 = ctx.r16.u64;
	// add r4,r29,r26
	ctx.r4.u64 = ctx.r29.u64 + ctx.r26.u64;
	// li r3,979
	ctx.r3.s64 = 979;
	// bl 0x881538c0
	ctx.lr = 0x880C1B0C;
	sub_881538C0(ctx, base);
	// lis r16,80
	ctx.r16.s64 = 5242880;
loc_880C1B10:
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x880c1b6c
	if (!ctx.cr6.eq) goto loc_880C1B6C;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r3,980
	ctx.r3.s64 = 980;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r30,52(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// subf r29,r24,r11
	ctx.r29.s64 = ctx.r11.s64 - ctx.r24.s64;
	// add r15,r10,r26
	ctx.r15.u64 = ctx.r10.u64 + ctx.r26.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r15
	ctx.r5.u64 = ctx.r15.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x881538c0
	ctx.lr = 0x880C1B44;
	sub_881538C0(ctx, base);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// subf r5,r19,r15
	ctx.r5.s64 = ctx.r15.s64 - ctx.r19.s64;
	// subf r4,r24,r29
	ctx.r4.s64 = ctx.r29.s64 - ctx.r24.s64;
	// li r3,981
	ctx.r3.s64 = 981;
	// bl 0x881538c0
	ctx.lr = 0x880C1B58;
	sub_881538C0(ctx, base);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// addis r5,r15,-96
	ctx.r5.s64 = ctx.r15.s64 + -6291456;
	// subf r4,r22,r29
	ctx.r4.s64 = ctx.r29.s64 - ctx.r22.s64;
	// li r3,982
	ctx.r3.s64 = 982;
	// bl 0x881538c0
	ctx.lr = 0x880C1B6C;
	sub_881538C0(ctx, base);
loc_880C1B6C:
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r31,r31,80
	ctx.r31.s64 = ctx.r31.s64 + 80;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bne 0x880c1778
	if (!ctx.cr0.eq) goto loc_880C1778;
	// stw r28,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r28.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C1B8C"))) PPC_WEAK_FUNC(sub_880C1B8C);
PPC_FUNC_IMPL(__imp__sub_880C1B8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C1B90"))) PPC_WEAK_FUNC(sub_880C1B90);
PPC_FUNC_IMPL(__imp__sub_880C1B90) {
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
	// addi r11,r5,6510
	ctx.r11.s64 = ctx.r5.s64 + 6510;
	// addi r9,r5,6507
	ctx.r9.s64 = ctx.r5.s64 + 6507;
	// addi r8,r5,6513
	ctx.r8.s64 = ctx.r5.s64 + 6513;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r8,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// add r6,r9,r4
	ctx.r6.u64 = ctx.r9.u64 + ctx.r4.u64;
	// add r5,r11,r4
	ctx.r5.u64 = ctx.r11.u64 + ctx.r4.u64;
	// add r7,r10,r4
	ctx.r7.u64 = ctx.r10.u64 + ctx.r4.u64;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// stw r5,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// lis r4,-30708
	ctx.r4.s64 = -2012479488;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r4,-1120
	ctx.r5.s64 = ctx.r4.s64 + -1120;
	// li r4,40
	ctx.r4.s64 = 40;
	// bl 0x88096460
	ctx.lr = 0x880C1BE8;
	sub_88096460(ctx, base);
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,-18868
	ctx.r11.s64 = ctx.r11.s64 + -18868;
	// addi r9,r11,12
	ctx.r9.s64 = ctx.r11.s64 + 12;
	// stwx r3,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_880C1C10"))) PPC_WEAK_FUNC(sub_880C1C10);
PPC_FUNC_IMPL(__imp__sub_880C1C10) {
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
	// addi r11,r4,15588
	ctx.r11.s64 = ctx.r4.s64 + 15588;
	// addi r9,r4,15584
	ctx.r9.s64 = ctx.r4.s64 + 15584;
	// ori r8,r10,65535
	ctx.r8.u64 = ctx.r10.u64 | 65535;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// lis r7,-30708
	ctx.r7.s64 = -2012479488;
	// stw r8,15588(r4)
	PPC_STORE_U32(ctx.r4.u32 + 15588, ctx.r8.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r7,1448
	ctx.r5.s64 = ctx.r7.s64 + 1448;
	// li r4,30
	ctx.r4.s64 = 30;
	// bl 0x88096460
	ctx.lr = 0x880C1C4C;
	sub_88096460(ctx, base);
	// lis r6,-30641
	ctx.r6.s64 = -2008088576;
	// addi r5,r6,-18868
	ctx.r5.s64 = ctx.r6.s64 + -18868;
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

__attribute__((alias("__imp__sub_880C1C68"))) PPC_WEAK_FUNC(sub_880C1C68);
PPC_FUNC_IMPL(__imp__sub_880C1C68) {
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
	// bl 0x880c1720
	ctx.lr = 0x880C1C78;
	sub_880C1720(ctx, base);
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

__attribute__((alias("__imp__sub_880C1C8C"))) PPC_WEAK_FUNC(sub_880C1C8C);
PPC_FUNC_IMPL(__imp__sub_880C1C8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C1C90"))) PPC_WEAK_FUNC(sub_880C1C90);
PPC_FUNC_IMPL(__imp__sub_880C1C90) {
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
	// addi r11,r4,15272
	ctx.r11.s64 = ctx.r4.s64 + 15272;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lis r9,-30708
	ctx.r9.s64 = -2012479488;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r9,1448
	ctx.r5.s64 = ctx.r9.s64 + 1448;
	// li r4,30
	ctx.r4.s64 = 30;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x88096460
	ctx.lr = 0x880C1CC8;
	sub_88096460(ctx, base);
	// lis r8,-30641
	ctx.r8.s64 = -2008088576;
	// lis r7,-30708
	ctx.r7.s64 = -2012479488;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r7,7272
	ctx.r5.s64 = ctx.r7.s64 + 7272;
	// li r4,30
	ctx.r4.s64 = 30;
	// stw r3,-18868(r8)
	PPC_STORE_U32(ctx.r8.u32 + -18868, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r31,r8,-18868
	ctx.r31.s64 = ctx.r8.s64 + -18868;
	// bl 0x88096460
	ctx.lr = 0x880C1CEC;
	sub_88096460(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_880C1D04"))) PPC_WEAK_FUNC(sub_880C1D04);
PPC_FUNC_IMPL(__imp__sub_880C1D04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C1D08"))) PPC_WEAK_FUNC(sub_880C1D08);
PPC_FUNC_IMPL(__imp__sub_880C1D08) {
	PPC_FUNC_PROLOGUE();
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880C1D10"))) PPC_WEAK_FUNC(sub_880C1D10);
PPC_FUNC_IMPL(__imp__sub_880C1D10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x880C1D18;
	__savegprlr_26(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// li r26,0
	ctx.r26.s64 = 0;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x880c1dfc
	if (ctx.cr6.lt) goto loc_880C1DFC;
	// bne cr6,0x880c1f9c
	if (!ctx.cr6.eq) goto loc_880C1F9C;
	// lwz r11,220(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 220);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880c1de4
	if (ctx.cr6.eq) goto loc_880C1DE4;
	// lwz r11,200(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 200);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 200, ctx.r11.u32);
	// bge 0x880c1de4
	if (!ctx.cr0.lt) goto loc_880C1DE4;
	// lwz r4,204(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 204);
	// lis r30,4
	ctx.r30.s64 = 262144;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// li r29,1
	ctx.r29.s64 = 1;
	// lwz r11,216(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 216);
	// li r10,8
	ctx.r10.s64 = 8;
	// add r5,r3,r30
	ctx.r5.u64 = ctx.r3.u64 + ctx.r30.u64;
	// lwz r8,208(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 208);
	// li r9,64
	ctx.r9.s64 = 64;
	// lwz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// stw r4,200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 200, ctx.r4.u32);
	// addi r7,r11,-16
	ctx.r7.s64 = ctx.r11.s64 + -16;
	// li r4,58
	ctx.r4.s64 = 58;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x88094690
	ctx.lr = 0x880C1D94;
	sub_88094690(ctx, base);
	// lwz r11,216(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 216);
	// li r10,8
	ctx.r10.s64 = 8;
	// lwz r8,212(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 212);
	// addi r7,r11,-16
	ctx.r7.s64 = ctx.r11.s64 + -16;
	// lwz r6,32(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// li r9,64
	ctx.r9.s64 = 64;
	// li r4,58
	ctx.r4.s64 = 58;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// subf r5,r30,r11
	ctx.r5.s64 = ctx.r11.s64 - ctx.r30.s64;
	// bl 0x88094690
	ctx.lr = 0x880C1DC4;
	sub_88094690(ctx, base);
	// lwz r11,216(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 216);
	// lwz r9,220(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 220);
	// addi r10,r11,-8
	ctx.r10.s64 = ctx.r11.s64 + -8;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r10,216(r31)
	PPC_STORE_U32(ctx.r31.u32 + 216, ctx.r10.u32);
	// stw r11,220(r31)
	PPC_STORE_U32(ctx.r31.u32 + 220, ctx.r11.u32);
	// bgt 0x880c1de4
	if (ctx.cr0.gt) goto loc_880C1DE4;
	// stw r26,220(r31)
	PPC_STORE_U32(ctx.r31.u32 + 220, ctx.r26.u32);
loc_880C1DE4:
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// clrlwi r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	// stw r10,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r10.u32);
	// b 0x880c1f9c
	goto loc_880C1F9C;
loc_880C1DFC:
	// lwz r10,60(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// li r29,1
	ctx.r29.s64 = 1;
	// addi r30,r11,9552
	ctx.r30.s64 = ctx.r11.s64 + 9552;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x880c1e84
	if (!ctx.cr6.eq) goto loc_880C1E84;
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r7,r11,128
	ctx.r7.s64 = ctx.r11.s64 + 128;
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r9,1
	ctx.r11.s64 = ctx.r9.s64 + 1;
	// rlwinm r5,r7,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x7FC;
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// lwzx r4,r6,r30
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r30.u32);
	// mullw r9,r4,r11
	ctx.r9.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r11.s32);
	// lwzx r3,r5,r30
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r30.u32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// mullw r11,r3,r11
	ctx.r11.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r11.s32);
	// rotlwi r8,r9,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// stw r9,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stw r7,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r7.u32);
	// bgt cr6,0x880c1e84
	if (ctx.cr6.gt) goto loc_880C1E84;
	// stw r26,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r26.u32);
	// li r3,511
	ctx.r3.s64 = 511;
	// stw r26,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r26.u32);
	// stw r29,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r29.u32);
	// bl 0x881534c8
	ctx.lr = 0x880C1E7C;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// stw r11,208(r31)
	PPC_STORE_U32(ctx.r31.u32 + 208, ctx.r11.u32);
loc_880C1E84:
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880c1f04
	if (!ctx.cr6.eq) goto loc_880C1F04;
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lis r7,240
	ctx.r7.s64 = 15728640;
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r8,32(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r6,r11,128
	ctx.r6.s64 = ctx.r11.s64 + 128;
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r10,1
	ctx.r11.s64 = ctx.r10.s64 + 1;
	// rlwinm r4,r6,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// lwzx r6,r4,r30
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r30.u32);
	// lwzx r3,r5,r30
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r30.u32);
	// mullw r10,r3,r11
	ctx.r10.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r11.s32);
	// add r5,r10,r9
	ctx.r5.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mullw r11,r6,r11
	ctx.r11.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r11.s32);
	// add r4,r11,r8
	ctx.r4.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stw r5,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r5.u32);
	// rotlwi r3,r5,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r4,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r4.u32);
	// cmpw cr6,r3,r7
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r7.s32, ctx.xer);
	// blt cr6,0x880c1f04
	if (ctx.cr6.lt) goto loc_880C1F04;
	// stw r7,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r7.u32);
	// li r3,511
	ctx.r3.s64 = 511;
	// stw r26,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r26.u32);
	// stw r29,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r29.u32);
	// bl 0x881534c8
	ctx.lr = 0x880C1EFC;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// stw r11,212(r31)
	PPC_STORE_U32(ctx.r31.u32 + 212, ctx.r11.u32);
loc_880C1F04:
	// lwz r11,180(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 180);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,180(r31)
	PPC_STORE_U32(ctx.r31.u32 + 180, ctx.r11.u32);
	// bge 0x880c1f80
	if (!ctx.cr0.lt) goto loc_880C1F80;
	// li r30,-2
	ctx.r30.s64 = -2;
	// lwz r11,184(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// li r10,128
	ctx.r10.s64 = 128;
	// lwz r8,188(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 188);
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// li r9,4
	ctx.r9.s64 = 4;
	// li r7,-28
	ctx.r7.s64 = -28;
	// lwz r6,32(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r4,59
	ctx.r4.s64 = 59;
	// lwz r5,28(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stw r11,180(r31)
	PPC_STORE_U32(ctx.r31.u32 + 180, ctx.r11.u32);
	// bl 0x88094690
	ctx.lr = 0x880C1F48;
	sub_88094690(ctx, base);
	// lwz r8,188(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 188);
	// li r10,128
	ctx.r10.s64 = 128;
	// lwz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// li r9,4
	ctx.r9.s64 = 4;
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// li r7,-28
	ctx.r7.s64 = -28;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// li r4,59
	ctx.r4.s64 = 59;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// neg r8,r8
	ctx.r8.s64 = -ctx.r8.s64;
	// bl 0x88094690
	ctx.lr = 0x880C1F74;
	sub_88094690(ctx, base);
	// lwz r11,188(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 188);
	// addi r7,r11,3
	ctx.r7.s64 = ctx.r11.s64 + 3;
	// stw r7,188(r31)
	PPC_STORE_U32(ctx.r31.u32 + 188, ctx.r7.u32);
loc_880C1F80:
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880c1f9c
	if (ctx.cr6.eq) goto loc_880C1F9C;
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880c1f9c
	if (ctx.cr6.eq) goto loc_880C1F9C;
	// stw r29,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r29.u32);
loc_880C1F9C:
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880c1fb4
	if (ctx.cr6.eq) goto loc_880C1FB4;
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// addi r11,r11,1985
	ctx.r11.s64 = ctx.r11.s64 + 1985;
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
loc_880C1FB4:
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880c1fcc
	if (ctx.cr6.eq) goto loc_880C1FCC;
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addi r11,r11,1985
	ctx.r11.s64 = ctx.r11.s64 + 1985;
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
loc_880C1FCC:
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880c20ac
	if (ctx.cr6.eq) goto loc_880C20AC;
	// lwz r11,172(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 172);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880c206c
	if (ctx.cr6.eq) goto loc_880C206C;
	// lwz r11,164(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 164);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 164, ctx.r11.u32);
	// bge 0x880c20ac
	if (!ctx.cr0.lt) goto loc_880C20AC;
	// lwz r11,168(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 168);
	// mr r28,r26
	ctx.r28.u64 = ctx.r26.u64;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 164, ctx.r11.u32);
	// ble cr6,0x880c20ac
	if (!ctx.cr6.gt) goto loc_880C20AC;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r30,r31,80
	ctx.r30.s64 = ctx.r31.s64 + 80;
	// lwz r29,26276(r11)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
loc_880C2018:
	// lwz r11,340(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 340);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// lwz r4,-4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + -4);
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// addi r11,r11,512
	ctx.r11.s64 = ctx.r11.s64 + 512;
	// bne cr6,0x880c2050
	if (!ctx.cr6.eq) goto loc_880C2050;
	// clrlwi r7,r11,16
	ctx.r7.u64 = ctx.r11.u32 & 0xFFFF;
	// stw r27,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r27.u32);
	// li r6,-31
	ctx.r6.s64 = -31;
	// sth r26,102(r1)
	PPC_STORE_U16(ctx.r1.u32 + 102, ctx.r26.u16);
	// li r3,25
	ctx.r3.s64 = 25;
	// bl 0x8815c948
	ctx.lr = 0x880C2048;
	sub_8815C948(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x8815c860
	ctx.lr = 0x880C2050;
	sub_8815C860(ctx, base);
loc_880C2050:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// cmpw cr6,r28,r11
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x880c2018
	if (ctx.cr6.lt) goto loc_880C2018;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_880C206C:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lis r9,96
	ctx.r9.s64 = 6291456;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// srawi r7,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 1;
	// addze r6,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r6.s64 = temp.s64;
	// cmpw cr6,r6,r9
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x880c20ac
	if (ctx.cr6.lt) goto loc_880C20AC;
	// lwz r11,156(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 156);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r11.u32);
	// bge 0x880c20ac
	if (!ctx.cr0.lt) goto loc_880C20AC;
	// lwz r11,160(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 160);
	// lwz r10,176(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 176);
	// stw r11,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r11.u32);
	// stw r10,172(r31)
	PPC_STORE_U32(ctx.r31.u32 + 172, ctx.r10.u32);
loc_880C20AC:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C20B4"))) PPC_WEAK_FUNC(sub_880C20B4);
PPC_FUNC_IMPL(__imp__sub_880C20B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C20B8"))) PPC_WEAK_FUNC(sub_880C20B8);
PPC_FUNC_IMPL(__imp__sub_880C20B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x880C20C0;
	__savegprlr_26(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// li r26,0
	ctx.r26.s64 = 0;
	// lwz r10,-11904(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -11904);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r10,300
	ctx.r10.s64 = ctx.r10.s64 + 300;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// stw r10,-11904(r9)
	PPC_STORE_U32(ctx.r9.u32 + -11904, ctx.r10.u32);
	// blt cr6,0x880c2108
	if (ctx.cr6.lt) goto loc_880C2108;
	// bne cr6,0x880c2284
	if (!ctx.cr6.eq) goto loc_880C2284;
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// clrlwi r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	// stw r10,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r10.u32);
	// b 0x880c2284
	goto loc_880C2284;
loc_880C2108:
	// lwz r9,60(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// li r30,1
	ctx.r30.s64 = 1;
	// addi r10,r11,9552
	ctx.r10.s64 = ctx.r11.s64 + 9552;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x880c2180
	if (!ctx.cr6.eq) goto loc_880C2180;
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r7,24(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r6,r11,128
	ctx.r6.s64 = ctx.r11.s64 + 128;
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r9,1
	ctx.r11.s64 = ctx.r9.s64 + 1;
	// rlwinm r4,r6,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// lwzx r3,r5,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r10.u32);
	// mullw r9,r3,r11
	ctx.r9.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r11.s32);
	// lwzx r6,r4,r10
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r10.u32);
	// add r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 + ctx.r8.u64;
	// mullw r11,r6,r11
	ctx.r11.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r11.s32);
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r5,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r5.u32);
	// add r3,r11,r7
	ctx.r3.u64 = ctx.r11.u64 + ctx.r7.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// bgt cr6,0x880c2180
	if (ctx.cr6.gt) goto loc_880C2180;
	// stw r26,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r26.u32);
	// stw r26,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r26.u32);
	// stw r30,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r30.u32);
loc_880C2180:
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880c21f0
	if (!ctx.cr6.eq) goto loc_880C21F0;
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lis r6,240
	ctx.r6.s64 = 15728640;
	// lwz r8,40(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// lwz r7,28(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r5,r11,128
	ctx.r5.s64 = ctx.r11.s64 + 128;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r8,1
	ctx.r11.s64 = ctx.r8.s64 + 1;
	// rlwinm r3,r5,2,21,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x7FC;
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// lwzx r5,r3,r10
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r10.u32);
	// lwzx r8,r4,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r10.u32);
	// mullw r8,r8,r11
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r11.s32);
	// mullw r11,r5,r11
	ctx.r11.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r11.s32);
	// add r4,r8,r7
	ctx.r4.u64 = ctx.r8.u64 + ctx.r7.u64;
	// add r3,r11,r9
	ctx.r3.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rotlwi r11,r4,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 0);
	// stw r4,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r4.u32);
	// stw r3,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r3.u32);
	// cmpw cr6,r11,r6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r6.s32, ctx.xer);
	// blt cr6,0x880c21f0
	if (ctx.cr6.lt) goto loc_880C21F0;
	// stw r6,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r6.u32);
	// stw r26,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r26.u32);
	// stw r30,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r30.u32);
loc_880C21F0:
	// lwz r11,180(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 180);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,180(r31)
	PPC_STORE_U32(ctx.r31.u32 + 180, ctx.r11.u32);
	// bge 0x880c2268
	if (!ctx.cr0.lt) goto loc_880C2268;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// li r10,128
	ctx.r10.s64 = 128;
	// lwz r11,184(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// li r9,4
	ctx.r9.s64 = 4;
	// li r7,-28
	ctx.r7.s64 = -28;
	// lwz r8,188(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 188);
	// li r4,59
	ctx.r4.s64 = 59;
	// lwz r6,32(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r5,28(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// stw r11,180(r31)
	PPC_STORE_U32(ctx.r31.u32 + 180, ctx.r11.u32);
	// bl 0x88094690
	ctx.lr = 0x880C2230;
	sub_88094690(ctx, base);
	// lwz r8,188(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 188);
	// li r10,128
	ctx.r10.s64 = 128;
	// lwz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// li r9,4
	ctx.r9.s64 = 4;
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// li r7,-28
	ctx.r7.s64 = -28;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// li r4,59
	ctx.r4.s64 = 59;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// neg r8,r8
	ctx.r8.s64 = -ctx.r8.s64;
	// bl 0x88094690
	ctx.lr = 0x880C225C;
	sub_88094690(ctx, base);
	// lwz r11,188(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 188);
	// addi r7,r11,16
	ctx.r7.s64 = ctx.r11.s64 + 16;
	// stw r7,188(r31)
	PPC_STORE_U32(ctx.r31.u32 + 188, ctx.r7.u32);
loc_880C2268:
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880c2284
	if (ctx.cr6.eq) goto loc_880C2284;
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880c2284
	if (ctx.cr6.eq) goto loc_880C2284;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
loc_880C2284:
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880c229c
	if (ctx.cr6.eq) goto loc_880C229C;
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// addi r11,r11,1985
	ctx.r11.s64 = ctx.r11.s64 + 1985;
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
loc_880C229C:
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880c22b4
	if (ctx.cr6.eq) goto loc_880C22B4;
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addi r11,r11,1985
	ctx.r11.s64 = ctx.r11.s64 + 1985;
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
loc_880C22B4:
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880c2394
	if (ctx.cr6.eq) goto loc_880C2394;
	// lwz r11,172(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 172);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880c2354
	if (ctx.cr6.eq) goto loc_880C2354;
	// lwz r11,164(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 164);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 164, ctx.r11.u32);
	// bge 0x880c2394
	if (!ctx.cr0.lt) goto loc_880C2394;
	// lwz r11,168(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 168);
	// mr r28,r26
	ctx.r28.u64 = ctx.r26.u64;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 164, ctx.r11.u32);
	// ble cr6,0x880c2394
	if (!ctx.cr6.gt) goto loc_880C2394;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r30,r31,80
	ctx.r30.s64 = ctx.r31.s64 + 80;
	// lwz r29,26276(r11)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
loc_880C2300:
	// lwz r11,340(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 340);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// lwz r4,-4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + -4);
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// addi r11,r11,512
	ctx.r11.s64 = ctx.r11.s64 + 512;
	// bne cr6,0x880c2338
	if (!ctx.cr6.eq) goto loc_880C2338;
	// clrlwi r7,r11,16
	ctx.r7.u64 = ctx.r11.u32 & 0xFFFF;
	// stw r27,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r27.u32);
	// li r6,-31
	ctx.r6.s64 = -31;
	// sth r26,102(r1)
	PPC_STORE_U16(ctx.r1.u32 + 102, ctx.r26.u16);
	// li r3,25
	ctx.r3.s64 = 25;
	// bl 0x8815c948
	ctx.lr = 0x880C2330;
	sub_8815C948(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x8815c860
	ctx.lr = 0x880C2338;
	sub_8815C860(ctx, base);
loc_880C2338:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// cmpw cr6,r28,r11
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x880c2300
	if (ctx.cr6.lt) goto loc_880C2300;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_880C2354:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lis r9,96
	ctx.r9.s64 = 6291456;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// srawi r7,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 1;
	// addze r6,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r6.s64 = temp.s64;
	// cmpw cr6,r6,r9
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x880c2394
	if (ctx.cr6.lt) goto loc_880C2394;
	// lwz r11,156(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 156);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r11.u32);
	// bge 0x880c2394
	if (!ctx.cr0.lt) goto loc_880C2394;
	// lwz r11,160(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 160);
	// lwz r10,176(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 176);
	// stw r11,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r11.u32);
	// stw r10,172(r31)
	PPC_STORE_U32(ctx.r31.u32 + 172, ctx.r10.u32);
loc_880C2394:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C239C"))) PPC_WEAK_FUNC(sub_880C239C);
PPC_FUNC_IMPL(__imp__sub_880C239C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C23A0"))) PPC_WEAK_FUNC(sub_880C23A0);
PPC_FUNC_IMPL(__imp__sub_880C23A0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r9,400(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 400);
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

__attribute__((alias("__imp__sub_880C23E0"))) PPC_WEAK_FUNC(sub_880C23E0);
PPC_FUNC_IMPL(__imp__sub_880C23E0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071144
	ctx.lr = 0x880C23E8;
	__savegprlr_23(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r26,2304(r3)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r24,-30597
	ctx.r24.s64 = -2005204992;
	// lis r11,545
	ctx.r11.s64 = 35717120;
	// lis r10,255
	ctx.r10.s64 = 16711680;
	// ori r27,r11,49152
	ctx.r27.u64 = ctx.r11.u64 | 49152;
	// ori r28,r10,255
	ctx.r28.u64 = ctx.r10.u64 | 255;
	// lwz r9,16(r26)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r26.u32 + 16);
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r31,-11932(r24)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r24.u32 + -11932);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x880c2484
	if (!ctx.cr6.gt) goto loc_880C2484;
	// addi r30,r26,80
	ctx.r30.s64 = ctx.r26.s64 + 80;
loc_880C241C:
	// lwz r25,-4(r30)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r30.u32 + -4);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r23,0(r30)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// li r6,211
	ctx.r6.s64 = 211;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// ori r3,r3,34441
	ctx.r3.u64 = ctx.r3.u64 | 34441;
	// bl 0x881538c0
	ctx.lr = 0x880C243C;
	sub_881538C0(ctx, base);
	// li r6,218
	ctx.r6.s64 = 218;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// li r3,403
	ctx.r3.s64 = 403;
	// bl 0x881538c0
	ctx.lr = 0x880C2450;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c246c
	if (ctx.cr6.eq) goto loc_880C246C;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// stw r28,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r28.u32);
	// or r10,r11,r27
	ctx.r10.u64 = ctx.r11.u64 | ctx.r27.u64;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_880C246C:
	// lwz r11,16(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 16);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// cmpw cr6,r29,r11
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x880c241c
	if (ctx.cr6.lt) goto loc_880C241C;
	// stw r31,-11932(r24)
	PPC_STORE_U32(ctx.r24.u32 + -11932, ctx.r31.u32);
loc_880C2484:
	// lwz r30,20(r26)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r26.u32 + 20);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r29,24(r26)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r26.u32 + 24);
	// li r6,211
	ctx.r6.s64 = 211;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// ori r3,r3,34409
	ctx.r3.u64 = ctx.r3.u64 | 34409;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x881538c0
	ctx.lr = 0x880C24A4;
	sub_881538C0(ctx, base);
	// lis r25,4
	ctx.r25.s64 = 262144;
	// li r6,211
	ctx.r6.s64 = 211;
	// add r5,r29,r25
	ctx.r5.u64 = ctx.r29.u64 + ctx.r25.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,419
	ctx.r3.s64 = 419;
	// bl 0x881538c0
	ctx.lr = 0x880C24BC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c24dc
	if (ctx.cr6.eq) goto loc_880C24DC;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// stw r28,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r28.u32);
	// or r10,r11,r27
	ctx.r10.u64 = ctx.r11.u64 | ctx.r27.u64;
	// stw r31,-11932(r24)
	PPC_STORE_U32(ctx.r24.u32 + -11932, ctx.r31.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_880C24DC:
	// li r6,211
	ctx.r6.s64 = 211;
	// subf r5,r25,r29
	ctx.r5.s64 = ctx.r29.s64 - ctx.r25.s64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,419
	ctx.r3.s64 = 419;
	// bl 0x881538c0
	ctx.lr = 0x880C24F0;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c2510
	if (ctx.cr6.eq) goto loc_880C2510;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// stw r28,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r28.u32);
	// or r10,r11,r27
	ctx.r10.u64 = ctx.r11.u64 | ctx.r27.u64;
	// stw r31,-11932(r24)
	PPC_STORE_U32(ctx.r24.u32 + -11932, ctx.r31.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_880C2510:
	// lwz r30,28(r26)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r26.u32 + 28);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r29,32(r26)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r26.u32 + 32);
	// li r6,211
	ctx.r6.s64 = 211;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// ori r3,r3,34409
	ctx.r3.u64 = ctx.r3.u64 | 34409;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x881538c0
	ctx.lr = 0x880C2530;
	sub_881538C0(ctx, base);
	// li r6,211
	ctx.r6.s64 = 211;
	// add r5,r29,r25
	ctx.r5.u64 = ctx.r29.u64 + ctx.r25.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,419
	ctx.r3.s64 = 419;
	// bl 0x881538c0
	ctx.lr = 0x880C2544;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c2564
	if (ctx.cr6.eq) goto loc_880C2564;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// stw r28,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r28.u32);
	// or r10,r11,r27
	ctx.r10.u64 = ctx.r11.u64 | ctx.r27.u64;
	// stw r31,-11932(r24)
	PPC_STORE_U32(ctx.r24.u32 + -11932, ctx.r31.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_880C2564:
	// li r6,211
	ctx.r6.s64 = 211;
	// subf r5,r25,r29
	ctx.r5.s64 = ctx.r29.s64 - ctx.r25.s64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,419
	ctx.r3.s64 = 419;
	// bl 0x881538c0
	ctx.lr = 0x880C2578;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c2598
	if (ctx.cr6.eq) goto loc_880C2598;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 1;
	// stw r28,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r28.u32);
	// or r9,r10,r27
	ctx.r9.u64 = ctx.r10.u64 | ctx.r27.u64;
	// stw r11,-11932(r24)
	PPC_STORE_U32(ctx.r24.u32 + -11932, ctx.r11.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_880C2598:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C25A0"))) PPC_WEAK_FUNC(sub_880C25A0);
PPC_FUNC_IMPL(__imp__sub_880C25A0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x880C25A8;
	__savegprlr_25(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x880c25dc
	if (ctx.cr6.lt) goto loc_880C25DC;
	// bne cr6,0x880c27cc
	if (!ctx.cr6.eq) goto loc_880C27CC;
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// clrlwi r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	// stw r10,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r10.u32);
	// b 0x880c27cc
	goto loc_880C27CC;
loc_880C25DC:
	// lwz r9,60(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// li r26,0
	ctx.r26.s64 = 0;
	// li r25,1
	ctx.r25.s64 = 1;
	// addi r10,r11,9552
	ctx.r10.s64 = ctx.r11.s64 + 9552;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x880c2658
	if (!ctx.cr6.eq) goto loc_880C2658;
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// lwz r7,20(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r6,r11,128
	ctx.r6.s64 = ctx.r11.s64 + 128;
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r8,1
	ctx.r11.s64 = ctx.r8.s64 + 1;
	// rlwinm r4,r6,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// lwzx r3,r5,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r10.u32);
	// mullw r8,r3,r11
	ctx.r8.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r11.s32);
	// lwzx r6,r4,r10
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r10.u32);
	// add r5,r8,r7
	ctx.r5.u64 = ctx.r8.u64 + ctx.r7.u64;
	// mullw r11,r6,r11
	ctx.r11.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r11.s32);
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r5,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r5.u32);
	// add r3,r11,r9
	ctx.r3.u64 = ctx.r11.u64 + ctx.r9.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// bgt cr6,0x880c2658
	if (ctx.cr6.gt) goto loc_880C2658;
	// stw r26,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r26.u32);
	// stw r26,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r26.u32);
	// stw r25,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r25.u32);
loc_880C2658:
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880c26c8
	if (!ctx.cr6.eq) goto loc_880C26C8;
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lis r6,240
	ctx.r6.s64 = 15728640;
	// lwz r8,40(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// lwz r7,28(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r5,r11,128
	ctx.r5.s64 = ctx.r11.s64 + 128;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r8,1
	ctx.r11.s64 = ctx.r8.s64 + 1;
	// rlwinm r3,r5,2,21,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x7FC;
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// lwzx r5,r3,r10
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r10.u32);
	// lwzx r8,r4,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r10.u32);
	// mullw r8,r8,r11
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r11.s32);
	// mullw r11,r5,r11
	ctx.r11.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r11.s32);
	// add r4,r8,r7
	ctx.r4.u64 = ctx.r8.u64 + ctx.r7.u64;
	// add r3,r11,r9
	ctx.r3.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rotlwi r11,r4,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 0);
	// stw r4,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r4.u32);
	// stw r3,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r3.u32);
	// cmpw cr6,r11,r6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r6.s32, ctx.xer);
	// blt cr6,0x880c26c8
	if (ctx.cr6.lt) goto loc_880C26C8;
	// stw r6,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r6.u32);
	// stw r26,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r26.u32);
	// stw r25,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r25.u32);
loc_880C26C8:
	// lwz r11,196(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 196);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880c27b0
	if (ctx.cr6.eq) goto loc_880C27B0;
	// lwz r11,180(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 180);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,180(r31)
	PPC_STORE_U32(ctx.r31.u32 + 180, ctx.r11.u32);
	// bge 0x880c27b0
	if (!ctx.cr0.lt) goto loc_880C27B0;
	// lwz r11,184(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r30,28(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r29,32(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// stw r11,180(r31)
	PPC_STORE_U32(ctx.r31.u32 + 180, ctx.r11.u32);
	// bl 0x88095590
	ctx.lr = 0x880C2704;
	sub_88095590(ctx, base);
	// lis r28,-30643
	ctx.r28.s64 = -2008219648;
	// lwz r10,192(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 192);
	// lwz r11,26276(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 26276);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880c2740
	if (!ctx.cr6.eq) goto loc_880C2740;
	// clrlwi r7,r3,16
	ctx.r7.u64 = ctx.r3.u32 & 0xFFFF;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r27.u32);
	// extsh r6,r10
	ctx.r6.s64 = ctx.r10.s16;
	// sth r26,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r26.u16);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,40
	ctx.r3.s64 = 40;
	// bl 0x8815c948
	ctx.lr = 0x880C2738;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x880C2740;
	sub_8815C860(ctx, base);
loc_880C2740:
	// lwz r30,20(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r29,24(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x88095590
	ctx.lr = 0x880C2758;
	sub_88095590(ctx, base);
	// lwz r11,26276(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 26276);
	// lwz r10,192(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 192);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880c2790
	if (!ctx.cr6.eq) goto loc_880C2790;
	// clrlwi r7,r3,16
	ctx.r7.u64 = ctx.r3.u32 & 0xFFFF;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r27.u32);
	// extsh r6,r10
	ctx.r6.s64 = ctx.r10.s16;
	// sth r26,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r26.u16);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,40
	ctx.r3.s64 = 40;
	// bl 0x8815c948
	ctx.lr = 0x880C2788;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x880C2790;
	sub_8815C860(ctx, base);
loc_880C2790:
	// lwz r11,192(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 192);
	// lwz r10,196(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 196);
	// addi r9,r11,6
	ctx.r9.s64 = ctx.r11.s64 + 6;
	// addic. r11,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r11.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r9,192(r31)
	PPC_STORE_U32(ctx.r31.u32 + 192, ctx.r9.u32);
	// stw r11,196(r31)
	PPC_STORE_U32(ctx.r31.u32 + 196, ctx.r11.u32);
	// bgt 0x880c27b0
	if (ctx.cr0.gt) goto loc_880C27B0;
	// stw r26,196(r31)
	PPC_STORE_U32(ctx.r31.u32 + 196, ctx.r26.u32);
loc_880C27B0:
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880c27cc
	if (ctx.cr6.eq) goto loc_880C27CC;
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880c27cc
	if (ctx.cr6.eq) goto loc_880C27CC;
	// stw r25,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r25.u32);
loc_880C27CC:
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880c27e4
	if (ctx.cr6.eq) goto loc_880C27E4;
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// addi r11,r11,4681
	ctx.r11.s64 = ctx.r11.s64 + 4681;
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
loc_880C27E4:
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880c27fc
	if (ctx.cr6.eq) goto loc_880C27FC;
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addi r11,r11,4681
	ctx.r11.s64 = ctx.r11.s64 + 4681;
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
loc_880C27FC:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C2804"))) PPC_WEAK_FUNC(sub_880C2804);
PPC_FUNC_IMPL(__imp__sub_880C2804) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C2808"))) PPC_WEAK_FUNC(sub_880C2808);
PPC_FUNC_IMPL(__imp__sub_880C2808) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071144
	ctx.lr = 0x880C2810;
	__savegprlr_23(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,376(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 376);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,172(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 172);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// blt cr6,0x880c2834
	if (ctx.cr6.lt) goto loc_880C2834;
	// lwz r11,188(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 188);
	// add r23,r11,r10
	ctx.r23.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x880c2840
	goto loc_880C2840;
loc_880C2834:
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 184);
	// lwz r11,168(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 168);
	// add r23,r10,r11
	ctx.r23.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_880C2840:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lis r26,-30667
	ctx.r26.s64 = -2009792512;
	// lis r27,-30667
	ctx.r27.s64 = -2009792512;
	// li r24,0
	ctx.r24.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x880c28f0
	if (!ctx.cr6.gt) goto loc_880C28F0;
	// addi r25,r23,2
	ctx.r25.s64 = ctx.r23.s64 + 2;
	// addi r30,r31,80
	ctx.r30.s64 = ctx.r31.s64 + 80;
loc_880C2860:
	// lwz r29,-4(r30)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r30.u32 + -4);
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// lwz r28,0(r30)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// li r3,5
	ctx.r3.s64 = 5;
	// stw r29,12364(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12364, ctx.r29.u32);
	// stw r28,12372(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12372, ctx.r28.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880C287C;
	sub_880F52C8(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,15696(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15696);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x880c28a8
	if (!ctx.cr6.eq) goto loc_880C28A8;
	// lwz r10,376(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 376);
	// lwz r8,15712(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15712);
	// lwz r7,15708(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15708);
	// lwz r6,15704(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15704);
	// lwz r5,15700(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15700);
	// lwz r4,12(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// bl 0x880f5438
	ctx.lr = 0x880C28A8;
	sub_880F5438(ctx, base);
loc_880C28A8:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,15696(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15696);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x880c28dc
	if (!ctx.cr6.eq) goto loc_880C28DC;
	// lwz r11,15700(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15700);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880c28dc
	if (!ctx.cr6.eq) goto loc_880C28DC;
	// stw r29,12364(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12364, ctx.r29.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r28,12372(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12372, ctx.r28.u32);
	// li r4,140
	ctx.r4.s64 = 140;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x881607f8
	ctx.lr = 0x880C28DC;
	sub_881607F8(ctx, base);
loc_880C28DC:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// cmpw cr6,r24,r11
	ctx.cr6.compare<int32_t>(ctx.r24.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x880c2860
	if (ctx.cr6.lt) goto loc_880C2860;
loc_880C28F0:
	// lwz r29,20(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addi r30,r23,2
	ctx.r30.s64 = ctx.r23.s64 + 2;
	// lwz r28,24(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// li r3,6
	ctx.r3.s64 = 6;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r29,12364(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12364, ctx.r29.u32);
	// stw r28,12372(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12372, ctx.r28.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880C2910;
	sub_880F52C8(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,15696(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15696);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x880c293c
	if (!ctx.cr6.eq) goto loc_880C293C;
	// lwz r10,376(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 376);
	// lwz r8,15712(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15712);
	// lwz r7,15708(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15708);
	// lwz r6,15704(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15704);
	// lwz r5,15700(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15700);
	// lwz r4,12(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// bl 0x880f5438
	ctx.lr = 0x880C293C;
	sub_880F5438(ctx, base);
loc_880C293C:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,15696(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15696);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x880c2970
	if (!ctx.cr6.eq) goto loc_880C2970;
	// lwz r11,15700(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15700);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880c2970
	if (!ctx.cr6.eq) goto loc_880C2970;
	// stw r29,12364(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12364, ctx.r29.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r28,12372(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12372, ctx.r28.u32);
	// li r4,140
	ctx.r4.s64 = 140;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x881607f8
	ctx.lr = 0x880C2970;
	sub_881607F8(ctx, base);
loc_880C2970:
	// lwz r29,28(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lis r24,-30667
	ctx.r24.s64 = -2009792512;
	// lwz r28,32(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lis r25,-30667
	ctx.r25.s64 = -2009792512;
	// li r11,6
	ctx.r11.s64 = 6;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,6
	ctx.r3.s64 = 6;
	// stw r29,12364(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12364, ctx.r29.u32);
	// stw r28,12372(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12372, ctx.r28.u32);
	// stw r11,12380(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12380, ctx.r11.u32);
	// stw r30,12376(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12376, ctx.r30.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880C29A0;
	sub_880F52C8(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,15696(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15696);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x880c29cc
	if (!ctx.cr6.eq) goto loc_880C29CC;
	// lwz r10,376(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 376);
	// lwz r8,15712(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15712);
	// lwz r7,15708(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15708);
	// lwz r6,15704(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15704);
	// lwz r5,15700(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15700);
	// lwz r4,12(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// bl 0x880f5438
	ctx.lr = 0x880C29CC;
	sub_880F5438(ctx, base);
loc_880C29CC:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,15696(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15696);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x880c2a0c
	if (!ctx.cr6.eq) goto loc_880C2A0C;
	// lwz r11,15700(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15700);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880c2a0c
	if (!ctx.cr6.eq) goto loc_880C2A0C;
	// stw r29,12364(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12364, ctx.r29.u32);
	// li r10,140
	ctx.r10.s64 = 140;
	// stw r28,12372(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12372, ctx.r28.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,140
	ctx.r4.s64 = 140;
	// stw r11,12380(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12380, ctx.r11.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,12376(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12376, ctx.r10.u32);
	// bl 0x881607f8
	ctx.lr = 0x880C2A0C;
	sub_881607F8(ctx, base);
loc_880C2A0C:
	// lwz r11,400(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 400);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C2A20"))) PPC_WEAK_FUNC(sub_880C2A20);
PPC_FUNC_IMPL(__imp__sub_880C2A20) {
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
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,15696(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15696);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880c2a68
	if (ctx.cr6.eq) goto loc_880C2A68;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880c2808
	ctx.lr = 0x880C2A4C;
	sub_880C2808(ctx, base);
	// lwz r3,376(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 376);
	// bl 0x88094220
	ctx.lr = 0x880C2A54;
	sub_88094220(ctx, base);
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
loc_880C2A68:
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// lis r11,-30640
	ctx.r11.s64 = -2008023040;
	// addi r8,r31,20
	ctx.r8.s64 = ctx.r31.s64 + 20;
	// addi r11,r11,31696
	ctx.r11.s64 = ctx.r11.s64 + 31696;
	// lwz r7,26272(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26272);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x880c2aa4
	if (!ctx.cr6.eq) goto loc_880C2AA4;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x880c2aa4
	if (ctx.cr6.eq) goto loc_880C2AA4;
	// lwz r9,396(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 396);
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// rlwinm r6,r9,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r6,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r11.u32);
	// add r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r5,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r5.u32);
loc_880C2AA4:
	// addi r10,r31,28
	ctx.r10.s64 = ctx.r31.s64 + 28;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x880c2ad0
	if (!ctx.cr6.eq) goto loc_880C2AD0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x880c2ad0
	if (ctx.cr6.eq) goto loc_880C2AD0;
	// lwz r7,396(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 396);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r6,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r11.u32);
	// add r5,r11,r9
	ctx.r5.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stw r5,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r5.u32);
loc_880C2AD0:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lis r7,-64
	ctx.r7.s64 = -4194304;
	// lwz r5,56(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r4,52(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// subf r9,r5,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r5.s64;
	// subf r11,r4,r6
	ctx.r11.s64 = ctx.r6.s64 - ctx.r4.s64;
	// stw r9,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r9.u32);
	// cmpw cr6,r9,r7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, ctx.xer);
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// bgt cr6,0x880c2b28
	if (ctx.cr6.gt) goto loc_880C2B28;
	// cmpw cr6,r11,r7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r7.s32, ctx.xer);
	// bgt cr6,0x880c2b28
	if (ctx.cr6.gt) goto loc_880C2B28;
	// lwz r11,400(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 400);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x88094220
	ctx.lr = 0x880C2B14;
	sub_88094220(ctx, base);
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
loc_880C2B28:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r8,0(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// rlwinm r7,r11,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// lwz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// subf r5,r10,r8
	ctx.r5.s64 = ctx.r8.s64 - ctx.r10.s64;
	// lwz r4,68(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// subf r3,r9,r6
	ctx.r3.s64 = ctx.r6.s64 - ctx.r9.s64;
	// divw r8,r5,r7
	ctx.r8.s32 = ppc_divw(ctx.r5.s32, ctx.r7.s32);
	// divw r7,r3,r7
	ctx.r7.s32 = ppc_divw(ctx.r3.s32, ctx.r7.s32);
	// mullw r5,r4,r8
	ctx.r5.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r8.s32);
	// mullw r6,r4,r7
	ctx.r6.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r7.s32);
	// add r10,r5,r10
	ctx.r10.u64 = ctx.r5.u64 + ctx.r10.u64;
	// add r9,r6,r9
	ctx.r9.u64 = ctx.r6.u64 + ctx.r9.u64;
	// ble cr6,0x880c2b8c
	if (!ctx.cr6.gt) goto loc_880C2B8C;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// rlwinm r8,r8,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r7,r7,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// addi r11,r31,72
	ctx.r11.s64 = ctx.r31.s64 + 72;
loc_880C2B78:
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// stwu r9,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// add r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 + ctx.r9.u64;
	// bdnz 0x880c2b78
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_880C2B78;
loc_880C2B8C:
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

__attribute__((alias("__imp__sub_880C2BA0"))) PPC_WEAK_FUNC(sub_880C2BA0);
PPC_FUNC_IMPL(__imp__sub_880C2BA0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071144
	ctx.lr = 0x880C2BA8;
	__savegprlr_23(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30708
	ctx.r11.s64 = -2012479488;
	// li r4,404
	ctx.r4.s64 = 404;
	// addi r5,r11,11168
	ctx.r5.s64 = ctx.r11.s64 + 11168;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x880C2BC0;
	sub_88094290(ctx, base);
	// li r5,404
	ctx.r5.s64 = 404;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,2304(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2304);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x880C2BD4;
	sub_88073BD0(ctx, base);
	// stw r30,376(r31)
	PPC_STORE_U32(ctx.r31.u32 + 376, ctx.r30.u32);
	// li r4,21
	ctx.r4.s64 = 21;
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x881556a0
	ctx.lr = 0x880C2BE4;
	sub_881556A0(ctx, base);
	// lis r10,-30708
	ctx.r10.s64 = -2012479488;
	// stw r3,400(r31)
	PPC_STORE_U32(ctx.r31.u32 + 400, ctx.r3.u32);
	// li r24,1
	ctx.r24.s64 = 1;
	// addi r9,r10,7432
	ctx.r9.s64 = ctx.r10.s64 + 7432;
	// stw r31,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r31.u32);
	// li r25,0
	ctx.r25.s64 = 0;
	// stw r9,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r9.u32);
	// lwz r8,400(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 400);
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
	// stw r24,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r24.u32);
	// lwz r9,400(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 400);
	// lwz r11,28(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880c2c34
	if (ctx.cr6.eq) goto loc_880C2C34;
loc_880C2C1C:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880c2f2c
	if (ctx.cr6.eq) goto loc_880C2F2C;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880c2c1c
	if (!ctx.cr6.eq) goto loc_880C2C1C;
loc_880C2C34:
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
loc_880C2C38:
	// li r10,24
	ctx.r10.s64 = 24;
	// li r6,63
	ctx.r6.s64 = 63;
	// addi r26,r31,20
	ctx.r26.s64 = ctx.r31.s64 + 20;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// stw r6,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r6.u32);
	// mr r9,r24
	ctx.r9.u64 = ctx.r24.u64;
	// stw r26,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r26.u32);
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r10,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r8,400(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 400);
	// lwz r11,28(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880c2c88
	if (ctx.cr6.eq) goto loc_880C2C88;
loc_880C2C70:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x880c2f44
	if (ctx.cr6.eq) goto loc_880C2F44;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880c2c70
	if (!ctx.cr6.eq) goto loc_880C2C70;
loc_880C2C88:
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
loc_880C2C8C:
	// addi r27,r31,28
	ctx.r27.s64 = ctx.r31.s64 + 28;
	// stw r6,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r6.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// mr r9,r25
	ctx.r9.u64 = ctx.r25.u64;
	// stw r27,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r27.u32);
	// addi r7,r31,76
	ctx.r7.s64 = ctx.r31.s64 + 76;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// li r29,4
	ctx.r29.s64 = 4;
	// stw r10,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
loc_880C2CB4:
	// lwz r8,400(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 400);
	// addi r10,r9,2
	ctx.r10.s64 = ctx.r9.s64 + 2;
	// lwz r11,28(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880c2ce0
	if (ctx.cr6.eq) goto loc_880C2CE0;
loc_880C2CC8:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880c2f5c
	if (ctx.cr6.eq) goto loc_880C2F5C;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880c2cc8
	if (!ctx.cr6.eq) goto loc_880C2CC8;
loc_880C2CE0:
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
loc_880C2CE4:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r7,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r7.u32);
	// stw r6,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r6.u32);
	// addi r7,r7,8
	ctx.r7.s64 = ctx.r7.s64 + 8;
	// stw r29,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r29.u32);
	// cmpwi cr6,r9,10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 10, ctx.xer);
	// stw r29,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r29.u32);
	// stw r29,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r29.u32);
	// stw r29,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r29.u32);
	// blt cr6,0x880c2cb4
	if (ctx.cr6.lt) goto loc_880C2CB4;
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// lwz r7,32(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// lis r6,16838
	ctx.r6.s64 = 1103495168;
	// lis r5,15887
	ctx.r5.s64 = 1041170432;
	// ori r9,r6,20077
	ctx.r9.u64 = ctx.r6.u64 | 20077;
	// ori r10,r5,33761
	ctx.r10.u64 = ctx.r5.u64 | 33761;
	// lwz r8,4200(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4200);
	// li r4,100
	ctx.r4.s64 = 100;
	// stw r7,224(r31)
	PPC_STORE_U32(ctx.r31.u32 + 224, ctx.r7.u32);
	// li r28,32
	ctx.r28.s64 = 32;
	// mullw r8,r8,r9
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// addi r7,r8,12345
	ctx.r7.s64 = ctx.r8.s64 + 12345;
	// li r3,5
	ctx.r3.s64 = 5;
	// stw r7,4200(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4200, ctx.r7.u32);
	// mullw r6,r7,r9
	ctx.r6.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r9.s32);
	// lwz r8,36(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// addi r6,r6,12345
	ctx.r6.s64 = ctx.r6.s64 + 12345;
	// stw r8,228(r31)
	PPC_STORE_U32(ctx.r31.u32 + 228, ctx.r8.u32);
	// addi r8,r30,120
	ctx.r8.s64 = ctx.r30.s64 + 120;
	// stw r4,168(r30)
	PPC_STORE_U32(ctx.r30.u32 + 168, ctx.r4.u32);
	// stw r28,332(r31)
	PPC_STORE_U32(ctx.r31.u32 + 332, ctx.r28.u32);
	// lhz r23,4200(r11)
	ctx.r23.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4200);
	// stw r6,4200(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4200, ctx.r6.u32);
	// mulhwu r7,r23,r10
	ctx.r7.u64 = (uint64_t(ctx.r23.u32) * uint64_t(ctx.r10.u32)) >> 32;
	// lhz r5,4200(r11)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4200);
	// rlwinm r7,r7,29,3,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 29) & 0x1FFFFFFF;
	// rlwinm r4,r7,5,0,26
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// add r4,r4,r7
	ctx.r4.u64 = ctx.r4.u64 + ctx.r7.u64;
	// subf r7,r4,r23
	ctx.r7.s64 = ctx.r23.s64 - ctx.r4.s64;
	// mr r23,r5
	ctx.r23.u64 = ctx.r5.u64;
	// mulhwu r4,r23,r10
	ctx.r4.u64 = (uint64_t(ctx.r23.u32) * uint64_t(ctx.r10.u32)) >> 32;
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// rlwinm r7,r4,29,3,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 29) & 0x1FFFFFFF;
	// extsh r4,r5
	ctx.r4.s64 = ctx.r5.s16;
	// rlwinm r5,r7,5,0,26
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// addi r4,r4,240
	ctx.r4.s64 = ctx.r4.s64 + 240;
	// add r7,r5,r7
	ctx.r7.u64 = ctx.r5.u64 + ctx.r7.u64;
	// stw r4,340(r31)
	PPC_STORE_U32(ctx.r31.u32 + 340, ctx.r4.u32);
	// lwz r4,132(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 132);
	// subf r5,r7,r23
	ctx.r5.s64 = ctx.r23.s64 - ctx.r7.s64;
	// lwz r7,2304(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 2304);
	// stw r7,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
	// extsh r7,r5
	ctx.r7.s64 = ctx.r5.s16;
	// addi r7,r7,256
	ctx.r7.s64 = ctx.r7.s64 + 256;
	// lwz r4,132(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 132);
	// stw r4,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r4.u32);
	// stw r3,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r3.u32);
	// stw r7,340(r31)
	PPC_STORE_U32(ctx.r31.u32 + 340, ctx.r7.u32);
	// lwz r5,136(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 136);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq cr6,0x880c2e14
	if (ctx.cr6.eq) goto loc_880C2E14;
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// mullw r10,r6,r9
	ctx.r10.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r9.s32);
	// addi r10,r10,12345
	ctx.r10.s64 = ctx.r10.s64 + 12345;
	// li r6,-5
	ctx.r6.s64 = -5;
	// stw r10,4200(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4200, ctx.r10.u32);
	// lhz r5,4200(r11)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4200);
	// mulhwu r4,r5,r7
	ctx.r4.u64 = (uint64_t(ctx.r5.u32) * uint64_t(ctx.r7.u32)) >> 32;
	// rlwinm r11,r4,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 29) & 0x1FFFFFFF;
	// stw r6,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r6.u32);
	// rlwinm r10,r11,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r10,r11,r5
	ctx.r10.s64 = ctx.r5.s64 - ctx.r11.s64;
	// extsh r11,r10
	ctx.r11.s64 = ctx.r10.s16;
	// addi r7,r11,224
	ctx.r7.s64 = ctx.r11.s64 + 224;
	// stw r7,340(r31)
	PPC_STORE_U32(ctx.r31.u32 + 340, ctx.r7.u32);
loc_880C2E14:
	// lwz r8,20(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// li r9,10
	ctx.r9.s64 = 10;
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r11,r31,72
	ctx.r11.s64 = ctx.r31.s64 + 72;
	// lwz r10,340(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 340);
	// addi r6,r10,128
	ctx.r6.s64 = ctx.r10.s64 + 128;
	// stw r8,252(r31)
	PPC_STORE_U32(ctx.r31.u32 + 252, ctx.r8.u32);
	// addi r5,r10,-128
	ctx.r5.s64 = ctx.r10.s64 + -128;
	// lwz r4,8(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// stw r4,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r4.u32);
	// rotlwi r9,r4,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r4.u32, 0);
	// lwz r10,12(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// addis r8,r10,64
	ctx.r8.s64 = ctx.r10.s64 + 4194304;
	// rotlwi r7,r8,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// stw r6,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r6.u32);
	// stw r5,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r5.u32);
	// stw r8,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r8.u32);
	// stw r9,0(r27)
	PPC_STORE_U32(ctx.r27.u32 + 0, ctx.r9.u32);
	// stw r7,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r7.u32);
loc_880C2E64:
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// stwu r9,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x880c2e64
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_880C2E64;
	// li r11,2
	ctx.r11.s64 = 2;
	// lwz r8,340(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 340);
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// stw r25,296(r31)
	PPC_STORE_U32(ctx.r31.u32 + 296, ctx.r25.u32);
	// sth r11,232(r31)
	PPC_STORE_U16(ctx.r31.u32 + 232, ctx.r11.u16);
	// addi r9,r8,256
	ctx.r9.s64 = ctx.r8.s64 + 256;
	// li r7,40
	ctx.r7.s64 = 40;
	// stw r29,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r29.u32);
	// stw r9,188(r31)
	PPC_STORE_U32(ctx.r31.u32 + 188, ctx.r9.u32);
	// li r9,16
	ctx.r9.s64 = 16;
	// li r8,47
	ctx.r8.s64 = 47;
	// stw r29,176(r31)
	PPC_STORE_U32(ctx.r31.u32 + 176, ctx.r29.u32);
	// lwz r10,-11984(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11984);
	// li r6,56
	ctx.r6.s64 = 56;
	// sth r7,238(r31)
	PPC_STORE_U16(ctx.r31.u32 + 238, ctx.r7.u16);
	// stw r8,260(r31)
	PPC_STORE_U32(ctx.r31.u32 + 260, ctx.r8.u32);
	// stw r9,160(r31)
	PPC_STORE_U32(ctx.r31.u32 + 160, ctx.r9.u32);
	// stw r6,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r6.u32);
	// sth r11,234(r31)
	PPC_STORE_U16(ctx.r31.u32 + 234, ctx.r11.u16);
	// sth r7,236(r31)
	PPC_STORE_U16(ctx.r31.u32 + 236, ctx.r7.u16);
	// stw r3,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r3.u32);
	// lwz r10,84(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// blt cr6,0x880c2f9c
	if (ctx.cr6.lt) goto loc_880C2F9C;
	// beq cr6,0x880c2f74
	if (ctx.cr6.eq) goto loc_880C2F74;
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// bge cr6,0x880c2fb8
	if (!ctx.cr6.lt) goto loc_880C2FB8;
	// lis r8,-30708
	ctx.r8.s64 = -2012479488;
	// stw r9,160(r31)
	PPC_STORE_U32(ctx.r31.u32 + 160, ctx.r9.u32);
	// li r10,7
	ctx.r10.s64 = 7;
	// stw r29,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r29.u32);
	// li r7,72
	ctx.r7.s64 = 72;
	// stw r29,176(r31)
	PPC_STORE_U32(ctx.r31.u32 + 176, ctx.r29.u32);
	// li r6,-16
	ctx.r6.s64 = -16;
	// stw r25,200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 200, ctx.r25.u32);
	// addi r5,r8,7440
	ctx.r5.s64 = ctx.r8.s64 + 7440;
	// stw r7,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r7.u32);
	// stw r28,204(r31)
	PPC_STORE_U32(ctx.r31.u32 + 204, ctx.r28.u32);
	// stw r6,216(r31)
	PPC_STORE_U32(ctx.r31.u32 + 216, ctx.r6.u32);
	// stw r24,220(r31)
	PPC_STORE_U32(ctx.r31.u32 + 220, ctx.r24.u32);
	// stw r10,180(r31)
	PPC_STORE_U32(ctx.r31.u32 + 180, ctx.r10.u32);
	// stw r11,184(r31)
	PPC_STORE_U32(ctx.r31.u32 + 184, ctx.r11.u32);
	// stw r10,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r10.u32);
	// stw r5,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r5.u32);
	// b 0x880c2fb8
	goto loc_880C2FB8;
loc_880C2F2C:
	// lwz r10,24(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880c2f3c
	if (ctx.cr6.eq) goto loc_880C2F3C;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_880C2F3C:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x880c2c38
	goto loc_880C2C38;
loc_880C2F44:
	// lwz r9,24(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x880c2f54
	if (ctx.cr6.eq) goto loc_880C2F54;
	// stw r9,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r9.u32);
loc_880C2F54:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x880c2c8c
	goto loc_880C2C8C;
loc_880C2F5C:
	// lwz r10,24(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880c2f6c
	if (ctx.cr6.eq) goto loc_880C2F6C;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_880C2F6C:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x880c2ce4
	goto loc_880C2CE4;
loc_880C2F74:
	// lis r11,-30708
	ctx.r11.s64 = -2012479488;
	// stw r9,160(r31)
	PPC_STORE_U32(ctx.r31.u32 + 160, ctx.r9.u32);
	// li r10,72
	ctx.r10.s64 = 72;
	// stw r29,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r29.u32);
	// addi r9,r11,8376
	ctx.r9.s64 = ctx.r11.s64 + 8376;
	// stw r29,176(r31)
	PPC_STORE_U32(ctx.r31.u32 + 176, ctx.r29.u32);
	// stw r10,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r10.u32);
	// stw r3,184(r31)
	PPC_STORE_U32(ctx.r31.u32 + 184, ctx.r3.u32);
	// stw r9,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r9.u32);
	// b 0x880c2fb8
	goto loc_880C2FB8;
loc_880C2F9C:
	// lis r10,-30708
	ctx.r10.s64 = -2012479488;
	// stw r11,184(r31)
	PPC_STORE_U32(ctx.r31.u32 + 184, ctx.r11.u32);
	// li r9,8
	ctx.r9.s64 = 8;
	// stw r25,192(r31)
	PPC_STORE_U32(ctx.r31.u32 + 192, ctx.r25.u32);
	// addi r8,r10,9632
	ctx.r8.s64 = ctx.r10.s64 + 9632;
	// stw r9,196(r31)
	PPC_STORE_U32(ctx.r31.u32 + 196, ctx.r9.u32);
	// stw r8,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r8.u32);
loc_880C2FB8:
	// lis r11,-30708
	ctx.r11.s64 = -2012479488;
	// lis r10,-30708
	ctx.r10.s64 = -2012479488;
	// lis r9,-30708
	ctx.r9.s64 = -2012479488;
	// addi r8,r11,10784
	ctx.r8.s64 = ctx.r11.s64 + 10784;
	// addi r7,r10,9184
	ctx.r7.s64 = ctx.r10.s64 + 9184;
	// addi r6,r9,9120
	ctx.r6.s64 = ctx.r9.s64 + 9120;
	// stw r8,64(r30)
	PPC_STORE_U32(ctx.r30.u32 + 64, ctx.r8.u32);
	// stw r7,68(r30)
	PPC_STORE_U32(ctx.r30.u32 + 68, ctx.r7.u32);
	// stw r6,84(r30)
	PPC_STORE_U32(ctx.r30.u32 + 84, ctx.r6.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C2FE4"))) PPC_WEAK_FUNC(sub_880C2FE4);
PPC_FUNC_IMPL(__imp__sub_880C2FE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C2FE8"))) PPC_WEAK_FUNC(sub_880C2FE8);
PPC_FUNC_IMPL(__imp__sub_880C2FE8) {
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
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r10,15608(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15608);
	// add r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r7,15608(r11)
	PPC_STORE_U32(ctx.r11.u32 + 15608, ctx.r7.u32);
	// lwz r11,0(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// addi r3,r11,15612
	ctx.r3.s64 = ctx.r11.s64 + 15612;
	// bl 0x88072260
	ctx.lr = 0x880C3020;
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

__attribute__((alias("__imp__sub_880C3034"))) PPC_WEAK_FUNC(sub_880C3034);
PPC_FUNC_IMPL(__imp__sub_880C3034) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C3038"))) PPC_WEAK_FUNC(sub_880C3038);
PPC_FUNC_IMPL(__imp__sub_880C3038) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x880C3040;
	__savegprlr_26(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880c3220
	if (ctx.cr6.eq) goto loc_880C3220;
	// cmpwi cr6,r10,10
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 10, ctx.xer);
	// beq cr6,0x880c31c4
	if (ctx.cr6.eq) goto loc_880C31C4;
	// cmpwi cr6,r10,20
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 20, ctx.xer);
	// bne cr6,0x880c3258
	if (!ctx.cr6.eq) goto loc_880C3258;
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// li r26,0
	ctx.r26.s64 = 0;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// bge 0x880c3124
	if (!ctx.cr0.lt) goto loc_880C3124;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// lwz r30,104(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// lwz r29,16(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r28,20(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r11,26276(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880c3124
	if (!ctx.cr6.eq) goto loc_880C3124;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// clrlwi r7,r30,16
	ctx.r7.u64 = ctx.r30.u32 & 0xFFFF;
	// li r6,-40
	ctx.r6.s64 = -40;
	// sth r26,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r26.u16);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,51
	ctx.r3.s64 = 51;
	// bl 0x8815c948
	ctx.lr = 0x880C30C4;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x880C30CC;
	sub_8815C860(ctx, base);
	// addi r11,r30,170
	ctx.r11.s64 = ctx.r30.s64 + 170;
	// li r6,-40
	ctx.r6.s64 = -40;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r27.u32);
	// clrlwi r7,r11,16
	ctx.r7.u64 = ctx.r11.u32 & 0xFFFF;
	// sth r26,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r26.u16);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,51
	ctx.r3.s64 = 51;
	// bl 0x8815c948
	ctx.lr = 0x880C30F0;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x880C30F8;
	sub_8815C860(ctx, base);
	// addi r10,r30,340
	ctx.r10.s64 = ctx.r30.s64 + 340;
	// li r6,-40
	ctx.r6.s64 = -40;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r27.u32);
	// clrlwi r7,r10,16
	ctx.r7.u64 = ctx.r10.u32 & 0xFFFF;
	// sth r26,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r26.u16);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,51
	ctx.r3.s64 = 51;
	// bl 0x8815c948
	ctx.lr = 0x880C311C;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x880C3124;
	sub_8815C860(ctx, base);
loc_880C3124:
	// lhz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 24);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// sth r9,24(r31)
	PPC_STORE_U16(ctx.r31.u32 + 24, ctx.r9.u16);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge cr6,0x880c3160
	if (!ctx.cr6.lt) goto loc_880C3160;
	// lwz r11,148(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// lhz r10,26(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 26);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r11.u32);
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// sth r10,24(r31)
	PPC_STORE_U16(ctx.r31.u32 + 24, ctx.r10.u16);
	// blt cr6,0x880c3160
	if (ctx.cr6.lt) goto loc_880C3160;
	// li r11,20
	ctx.r11.s64 = 20;
	// stw r11,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r11.u32);
loc_880C3160:
	// lwz r10,156(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 156);
	// cmpwi cr6,r10,128
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 128, ctx.xer);
	// bne cr6,0x880c3188
	if (!ctx.cr6.eq) goto loc_880C3188;
	// lwz r11,104(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// lis r9,300
	ctx.r9.s64 = 19660800;
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r7,r11,4
	ctx.r7.s64 = ctx.r11.s64 + 4;
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// stw r7,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r7.u32);
	// bge cr6,0x880c31ac
	if (!ctx.cr6.lt) goto loc_880C31AC;
loc_880C3188:
	// cmpwi cr6,r10,384
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 384, ctx.xer);
	// bne cr6,0x880c3258
	if (!ctx.cr6.eq) goto loc_880C3258;
	// lwz r11,104(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// lis r10,-60
	ctx.r10.s64 = -3932160;
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r8,r11,-4
	ctx.r8.s64 = ctx.r11.s64 + -4;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// stw r8,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r8.u32);
	// bgt cr6,0x880c3258
	if (ctx.cr6.gt) goto loc_880C3258;
loc_880C31AC:
	// lwz r11,212(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 212);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stw r26,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r26.u32);
	// bl 0x88094220
	ctx.lr = 0x880C31BC;
	sub_88094220(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_880C31C4:
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// lis r10,32
	ctx.r10.s64 = 2097152;
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addi r8,r11,2048
	ctx.r8.s64 = ctx.r11.s64 + 2048;
	// subf r7,r11,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r11.s64;
	// stw r8,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r8.u32);
	// rotlwi r6,r7,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// stw r7,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r7.u32);
	// cmpw cr6,r6,r10
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r10.s32, ctx.xer);
	// bgt cr6,0x880c3258
	if (ctx.cr6.gt) goto loc_880C3258;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// li r9,20
	ctx.r9.s64 = 20;
	// li r8,128
	ctx.r8.s64 = 128;
	// stw r10,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// lis r7,120
	ctx.r7.s64 = 7864320;
	// stw r9,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r9.u32);
	// stw r8,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r8.u32);
	// cmpw cr6,r11,r7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r7.s32, ctx.xer);
	// blt cr6,0x880c3258
	if (ctx.cr6.lt) goto loc_880C3258;
	// li r11,384
	ctx.r11.s64 = 384;
	// stw r11,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_880C3220:
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// stw r9,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r9.u32);
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r11,r10,2
	ctx.r11.s64 = ctx.r10.s64 + 2;
	// addis r7,r8,-72
	ctx.r7.s64 = ctx.r8.s64 + -4718592;
	// stw r11,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// cmpwi cr6,r11,47
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 47, ctx.xer);
	// stw r7,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r7.u32);
	// blt cr6,0x880c3258
	if (ctx.cr6.lt) goto loc_880C3258;
	// li r11,10
	ctx.r11.s64 = 10;
	// li r10,47
	ctx.r10.s64 = 47;
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stw r10,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r10.u32);
loc_880C3258:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C3260"))) PPC_WEAK_FUNC(sub_880C3260);
PPC_FUNC_IMPL(__imp__sub_880C3260) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r9,212(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 212);
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

__attribute__((alias("__imp__sub_880C32A0"))) PPC_WEAK_FUNC(sub_880C32A0);
PPC_FUNC_IMPL(__imp__sub_880C32A0) {
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
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// li r11,47
	ctx.r11.s64 = 47;
	// lis r10,-30681
	ctx.r10.s64 = -2010710016;
	// li r6,210
	ctx.r6.s64 = 210;
	// addi r10,r10,-25304
	ctx.r10.s64 = ctx.r10.s64 + -25304;
	// lwz r7,92(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// rlwinm r4,r7,5,0,26
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// subf r3,r7,r4
	ctx.r3.s64 = ctx.r4.s64 - ctx.r7.s64;
	// divw r11,r3,r11
	ctx.r11.s32 = ppc_divw(ctx.r3.s32, ctx.r11.s32);
	// subfic r11,r11,31
	ctx.xer.ca = ctx.r11.u32 <= 31;
	ctx.r11.s64 = 31 - ctx.r11.s64;
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addis r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 65536;
	// addi r3,r3,-31127
	ctx.r3.s64 = ctx.r3.s64 + -31127;
	// lbzx r4,r7,r10
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r10.u32);
	// lbzx r11,r7,r5
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r5.u32);
	// extsb r10,r4
	ctx.r10.s64 = ctx.r4.s8;
	// extsb r7,r11
	ctx.r7.s64 = ctx.r11.s8;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r7,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r10,r9
	ctx.r4.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r5,r11,r8
	ctx.r5.u64 = ctx.r11.u64 + ctx.r8.u64;
	// bl 0x881538c0
	ctx.lr = 0x880C3314;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c3328
	if (ctx.cr6.eq) goto loc_880C3328;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,15272(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15272);
	// stw r10,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r10.u32);
loc_880C3328:
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

__attribute__((alias("__imp__sub_880C333C"))) PPC_WEAK_FUNC(sub_880C333C);
PPC_FUNC_IMPL(__imp__sub_880C333C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C3340"))) PPC_WEAK_FUNC(sub_880C3340);
PPC_FUNC_IMPL(__imp__sub_880C3340) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x880C3348;
	__savegprlr_27(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880c3604
	if (ctx.cr6.eq) goto loc_880C3604;
	// cmpwi cr6,r10,10
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 10, ctx.xer);
	// beq cr6,0x880c34b8
	if (ctx.cr6.eq) goto loc_880C34B8;
	// cmpwi cr6,r10,20
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 20, ctx.xer);
	// bne cr6,0x880c363c
	if (!ctx.cr6.eq) goto loc_880C363C;
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// li r27,0
	ctx.r27.s64 = 0;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// bge 0x880c3430
	if (!ctx.cr0.lt) goto loc_880C3430;
	// lis r9,-30643
	ctx.r9.s64 = -2008219648;
	// lwz r8,40(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r11,104(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,26276(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 26276);
	// stw r8,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r8.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x880c33f0
	if (!ctx.cr6.eq) goto loc_880C33F0;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// clrlwi r7,r11,16
	ctx.r7.u64 = ctx.r11.u32 & 0xFFFF;
	// extsh r6,r10
	ctx.r6.s64 = ctx.r10.s16;
	// sth r27,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r27.u16);
	// li r3,27
	ctx.r3.s64 = 27;
	// bl 0x8815c948
	ctx.lr = 0x880C33C8;
	sub_8815C948(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c33e8
	if (ctx.cr6.eq) goto loc_880C33E8;
	// li r11,2
	ctx.r11.s64 = 2;
	// li r10,4
	ctx.r10.s64 = 4;
	// li r9,128
	ctx.r9.s64 = 128;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r11.u8);
	// sth r10,18(r3)
	PPC_STORE_U16(ctx.r3.u32 + 18, ctx.r10.u16);
	// sth r9,20(r3)
	PPC_STORE_U16(ctx.r3.u32 + 20, ctx.r9.u16);
loc_880C33E8:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x880C33F0;
	sub_8815C860(ctx, base);
loc_880C33F0:
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addic. r11,r11,1
	ctx.xer.ca = ctx.r11.u32 > 4294967294;
	ctx.r11.s64 = ctx.r11.s64 + 1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// blt 0x880c3404
	if (ctx.cr0.lt) goto loc_880C3404;
	// stw r27,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r27.u32);
loc_880C3404:
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// lwz r11,104(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r9,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r9.u32);
	// bge cr6,0x880c3428
	if (!ctx.cr6.lt) goto loc_880C3428;
	// addi r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -2;
	// b 0x880c342c
	goto loc_880C342C;
loc_880C3428:
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
loc_880C342C:
	// stw r11,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
loc_880C3430:
	// lhz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 24);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// sth r9,24(r31)
	PPC_STORE_U16(ctx.r31.u32 + 24, ctx.r9.u16);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge cr6,0x880c346c
	if (!ctx.cr6.lt) goto loc_880C346C;
	// lwz r11,148(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// lhz r10,26(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 26);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r11.u32);
	// cmpwi cr6,r11,11
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 11, ctx.xer);
	// sth r10,24(r31)
	PPC_STORE_U16(ctx.r31.u32 + 24, ctx.r10.u16);
	// blt cr6,0x880c346c
	if (ctx.cr6.lt) goto loc_880C346C;
	// li r11,11
	ctx.r11.s64 = 11;
	// stw r11,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r11.u32);
loc_880C346C:
	// lwz r11,156(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 156);
	// cmpwi cr6,r11,128
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 128, ctx.xer);
	// bne cr6,0x880c3488
	if (!ctx.cr6.eq) goto loc_880C3488;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lis r9,300
	ctx.r9.s64 = 19660800;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x880c34a0
	if (!ctx.cr6.lt) goto loc_880C34A0;
loc_880C3488:
	// cmpwi cr6,r11,384
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 384, ctx.xer);
	// bne cr6,0x880c363c
	if (!ctx.cr6.eq) goto loc_880C363C;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lis r10,-60
	ctx.r10.s64 = -3932160;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bgt cr6,0x880c363c
	if (ctx.cr6.gt) goto loc_880C363C;
loc_880C34A0:
	// lwz r11,212(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 212);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r27,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r27.u32);
	// bl 0x88094220
	ctx.lr = 0x880C34B0;
	sub_88094220(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_880C34B8:
	// lwz r11,148(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// li r27,0
	ctx.r27.s64 = 0;
	// lwz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r9,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r9.u32);
	// beq cr6,0x880c35a8
	if (ctx.cr6.eq) goto loc_880C35A8;
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// bge 0x880c35a8
	if (!ctx.cr0.lt) goto loc_880C35A8;
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r30,16(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r29,20(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// bl 0x88095590
	ctx.lr = 0x880C3504;
	sub_88095590(ctx, base);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x880c3520
	if (!ctx.cr6.eq) goto loc_880C3520;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,256
	ctx.r10.s64 = 256;
	// stw r11,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
	// stw r10,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r10.u32);
loc_880C3520:
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r4,76(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// bl 0x88153010
	ctx.lr = 0x880C352C;
	sub_88153010(ctx, base);
	// lis r9,-30643
	ctx.r9.s64 = -2008219648;
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// stw r11,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// lwz r9,26276(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 26276);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x880c3590
	if (!ctx.cr6.eq) goto loc_880C3590;
	// clrlwi r7,r11,16
	ctx.r7.u64 = ctx.r11.u32 & 0xFFFF;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// extsh r6,r10
	ctx.r6.s64 = ctx.r10.s16;
	// sth r27,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r27.u16);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,19
	ctx.r3.s64 = 19;
	// bl 0x8815c948
	ctx.lr = 0x880C3568;
	sub_8815C948(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c3588
	if (ctx.cr6.eq) goto loc_880C3588;
	// li r11,2
	ctx.r11.s64 = 2;
	// li r10,5
	ctx.r10.s64 = 5;
	// li r9,8
	ctx.r9.s64 = 8;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r11.u8);
	// sth r10,18(r3)
	PPC_STORE_U16(ctx.r3.u32 + 18, ctx.r10.u16);
	// sth r9,20(r3)
	PPC_STORE_U16(ctx.r3.u32 + 20, ctx.r9.u16);
loc_880C3588:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x880C3590;
	sub_8815C860(ctx, base);
loc_880C3590:
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// stw r9,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r9.u32);
loc_880C35A8:
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lis r11,32
	ctx.r11.s64 = 2097152;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bgt cr6,0x880c363c
	if (ctx.cr6.gt) goto loc_880C363C;
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// li r9,20
	ctx.r9.s64 = 20;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stw r27,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r27.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r9,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r9.u32);
	// bge cr6,0x880c35ec
	if (!ctx.cr6.lt) goto loc_880C35EC;
	// li r11,144
	ctx.r11.s64 = 144;
	// li r10,128
	ctx.r10.s64 = 128;
	// stw r11,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// stw r10,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_880C35EC:
	// li r11,368
	ctx.r11.s64 = 368;
	// li r10,384
	ctx.r10.s64 = 384;
	// stw r11,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// stw r10,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_880C3604:
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// stw r9,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r9.u32);
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r11,r10,2
	ctx.r11.s64 = ctx.r10.s64 + 2;
	// addis r7,r8,-72
	ctx.r7.s64 = ctx.r8.s64 + -4718592;
	// stw r11,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// cmpwi cr6,r11,47
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 47, ctx.xer);
	// stw r7,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r7.u32);
	// blt cr6,0x880c363c
	if (ctx.cr6.lt) goto loc_880C363C;
	// li r11,10
	ctx.r11.s64 = 10;
	// li r10,47
	ctx.r10.s64 = 47;
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stw r10,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r10.u32);
loc_880C363C:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C3644"))) PPC_WEAK_FUNC(sub_880C3644);
PPC_FUNC_IMPL(__imp__sub_880C3644) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C3648"))) PPC_WEAK_FUNC(sub_880C3648);
PPC_FUNC_IMPL(__imp__sub_880C3648) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x880C3650;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,192(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 192);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,172(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 172);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// blt cr6,0x880c3674
	if (ctx.cr6.lt) goto loc_880C3674;
	// lwz r11,188(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 188);
	// add r26,r11,r10
	ctx.r26.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x880c3680
	goto loc_880C3680;
loc_880C3674:
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 184);
	// lwz r11,168(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 168);
	// add r26,r10,r11
	ctx.r26.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_880C3680:
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,40
	ctx.r5.s64 = 40;
	// li r4,93
	ctx.r4.s64 = 93;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x880e32d0
	ctx.lr = 0x880C3694;
	sub_880E32D0(ctx, base);
	// addi r4,r26,1
	ctx.r4.s64 = ctx.r26.s64 + 1;
	// li r30,2
	ctx.r30.s64 = 2;
	// lis r28,-30667
	ctx.r28.s64 = -2009792512;
	// lis r29,-30667
	ctx.r29.s64 = -2009792512;
loc_880C36A4:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// stw r11,12364(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12372, ctx.r10.u32);
	// bl 0x880f34b0
	ctx.lr = 0x880C36BC;
	sub_880F34B0(ctx, base);
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,12364(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12372, ctx.r10.u32);
	// bl 0x880f34b0
	ctx.lr = 0x880C36D4;
	sub_880F34B0(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x880c36a4
	if (!ctx.cr0.eq) goto loc_880C36A4;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lis r27,-30667
	ctx.r27.s64 = -2009792512;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lis r30,-30667
	ctx.r30.s64 = -2009792512;
	// addi r4,r26,2
	ctx.r4.s64 = ctx.r26.s64 + 2;
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r11,12364(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12364, ctx.r11.u32);
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r10,12372(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12372, ctx.r10.u32);
	// stw r4,12376(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12376, ctx.r4.u32);
	// stw r11,12380(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12380, ctx.r11.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880C370C;
	sub_880F52C8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c371c
	if (ctx.cr6.eq) goto loc_880C371C;
	// lwz r11,208(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 208);
	// stw r11,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r11.u32);
loc_880C371C:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,15696(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15696);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x880c3748
	if (!ctx.cr6.eq) goto loc_880C3748;
	// lwz r10,192(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 192);
	// lwz r8,15712(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15712);
	// lwz r7,15708(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15708);
	// lwz r6,15704(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15704);
	// lwz r5,15700(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15700);
	// lwz r4,12(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// bl 0x880f5438
	ctx.lr = 0x880C3748;
	sub_880F5438(ctx, base);
loc_880C3748:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,15696(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15696);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x880c3794
	if (!ctx.cr6.eq) goto loc_880C3794;
	// lwz r11,15700(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15700);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880c3794
	if (!ctx.cr6.eq) goto loc_880C3794;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// li r8,140
	ctx.r8.s64 = 140;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r9,12380(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12380, ctx.r9.u32);
	// li r4,140
	ctx.r4.s64 = 140;
	// stw r8,12376(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12376, ctx.r8.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,12364(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12372, ctx.r10.u32);
	// bl 0x881607f8
	ctx.lr = 0x880C3794;
	sub_881607F8(ctx, base);
loc_880C3794:
	// lwz r11,212(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 212);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C37A8"))) PPC_WEAK_FUNC(sub_880C37A8);
PPC_FUNC_IMPL(__imp__sub_880C37A8) {
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
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,2304(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r11,-11984(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11984);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,84(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// cmpwi cr6,r9,2
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 2, ctx.xer);
	// bne cr6,0x880c37ec
	if (!ctx.cr6.eq) goto loc_880C37EC;
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// lwz r11,-11904(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -11904);
	// addis r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 65536;
	// addi r11,r11,24464
	ctx.r11.s64 = ctx.r11.s64 + 24464;
	// stw r11,-11904(r9)
	PPC_STORE_U32(ctx.r9.u32 + -11904, ctx.r11.u32);
loc_880C37EC:
	// lwz r11,15696(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 15696);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880c3818
	if (ctx.cr6.eq) goto loc_880C3818;
	// bl 0x880c3648
	ctx.lr = 0x880C37FC;
	sub_880C3648(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88094220
	ctx.lr = 0x880C3804;
	sub_88094220(ctx, base);
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
loc_880C3818:
	// lwz r11,156(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 156);
	// lis r7,-30643
	ctx.r7.s64 = -2008219648;
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// lwz r6,148(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 148);
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r5,r10,9552
	ctx.r5.s64 = ctx.r10.s64 + 9552;
	// lwz r8,20(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// addi r4,r11,128
	ctx.r4.s64 = ctx.r11.s64 + 128;
	// rlwinm r31,r11,2,0,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,26272(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 26272);
	// rlwinm r4,r4,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x7FC;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// addi r11,r3,16
	ctx.r11.s64 = ctx.r3.s64 + 16;
	// lwzx r10,r31,r5
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r5.u32);
	// lwzx r7,r4,r5
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r5.u32);
	// mullw r10,r10,r6
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r6.s32);
	// mullw r7,r7,r6
	ctx.r7.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r6.s32);
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r5,r7,r8
	ctx.r5.u64 = ctx.r7.u64 + ctx.r8.u64;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// stw r5,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r5.u32);
	// bne cr6,0x880c389c
	if (!ctx.cr6.eq) goto loc_880C389C;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880c389c
	if (ctx.cr6.eq) goto loc_880C389C;
	// lwz r9,208(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// lis r8,-30640
	ctx.r8.s64 = -2008023040;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r7,r8,31696
	ctx.r7.s64 = ctx.r8.s64 + 31696;
	// rlwinm r6,r9,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r6,r7
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r7.u32);
	// add r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r5,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r5.u32);
loc_880C389C:
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

__attribute__((alias("__imp__sub_880C38B0"))) PPC_WEAK_FUNC(sub_880C38B0);
PPC_FUNC_IMPL(__imp__sub_880C38B0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880C38B8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30708
	ctx.r11.s64 = -2012479488;
	// li r4,216
	ctx.r4.s64 = 216;
	// addi r5,r11,14512
	ctx.r5.s64 = ctx.r11.s64 + 14512;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x880C38D0;
	sub_88094290(ctx, base);
	// li r5,216
	ctx.r5.s64 = 216;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,2304(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2304);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x880C38E4;
	sub_88073BD0(ctx, base);
	// stw r30,192(r31)
	PPC_STORE_U32(ctx.r31.u32 + 192, ctx.r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x881556a0
	ctx.lr = 0x880C38F4;
	sub_881556A0(ctx, base);
	// lis r10,-30708
	ctx.r10.s64 = -2012479488;
	// stw r3,212(r31)
	PPC_STORE_U32(ctx.r31.u32 + 212, ctx.r3.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r8,r10,12264
	ctx.r8.s64 = ctx.r10.s64 + 12264;
	// stw r31,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r31.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r8,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r8.u32);
	// lwz r7,212(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 212);
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// stw r4,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r4.u32);
	// lwz r8,212(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 212);
	// lwz r11,28(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880c3944
	if (ctx.cr6.eq) goto loc_880C3944;
loc_880C392C:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880c3a9c
	if (ctx.cr6.eq) goto loc_880C3A9C;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880c392c
	if (!ctx.cr6.eq) goto loc_880C392C;
loc_880C3944:
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
loc_880C3948:
	// li r8,24
	ctx.r8.s64 = 24;
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// addi r10,r31,16
	ctx.r10.s64 = ctx.r31.s64 + 16;
	// stw r8,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
	// mr r7,r4
	ctx.r7.u64 = ctx.r4.u64;
	// stw r10,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r10.u32);
	// stw r8,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r8.u32);
	// stw r8,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r8.u32);
	// stw r8,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r8.u32);
	// lwz r8,212(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 212);
	// lwz r11,28(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880c3994
	if (ctx.cr6.eq) goto loc_880C3994;
loc_880C397C:
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x880c3ab4
	if (ctx.cr6.eq) goto loc_880C3AB4;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880c397c
	if (!ctx.cr6.eq) goto loc_880C397C;
loc_880C3994:
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
loc_880C3998:
	// li r6,19
	ctx.r6.s64 = 19;
	// stw r10,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r10.u32);
	// li r7,12
	ctx.r7.s64 = 12;
	// stw r4,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r4.u32);
	// stw r6,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r6.u32);
	// li r3,100
	ctx.r3.s64 = 100;
	// stw r6,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r6.u32);
	// lis r6,-30597
	ctx.r6.s64 = -2005204992;
	// stw r7,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r7.u32);
	// li r5,128
	ctx.r5.s64 = 128;
	// stw r7,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r7.u32);
	// addi r11,r30,120
	ctx.r11.s64 = ctx.r30.s64 + 120;
	// li r8,4
	ctx.r8.s64 = 4;
	// li r29,5
	ctx.r29.s64 = 5;
	// lwz r11,-11984(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -11984);
	// lwz r6,32(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// stw r6,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r6.u32);
	// lwz r6,36(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// stw r6,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r6.u32);
	// stw r3,168(r30)
	PPC_STORE_U32(ctx.r30.u32 + 168, ctx.r3.u32);
	// stw r5,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r5.u32);
	// stw r9,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r9.u32);
	// lwz r3,132(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 132);
	// lwz r6,2304(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// stw r6,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r6.u32);
	// lwz r3,132(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 132);
	// stw r3,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// lwz r6,136(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 136);
	// stw r6,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r6.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r6,140(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 140);
	// stw r6,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r6.u32);
	// lwz r6,8(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stw r6,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r6.u32);
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addis r10,r3,-72
	ctx.r10.s64 = ctx.r3.s64 + -4718592;
	// stw r10,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// stw r9,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r9.u32);
	// stw r9,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r9.u32);
	// stw r8,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r8.u32);
	// stw r29,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r29.u32);
	// stw r9,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r9.u32);
	// sth r8,24(r31)
	PPC_STORE_U16(ctx.r31.u32 + 24, ctx.r8.u16);
	// sth r4,26(r31)
	PPC_STORE_U16(ctx.r31.u32 + 26, ctx.r4.u16);
	// lwz r11,84(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x880c3acc
	if (ctx.cr6.eq) goto loc_880C3ACC;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x880c3adc
	if (!ctx.cr6.eq) goto loc_880C3ADC;
	// lwz r11,156(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 156);
	// lis r10,-30708
	ctx.r10.s64 = -2012479488;
	// li r6,2
	ctx.r6.s64 = 2;
	// stw r8,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r8.u32);
	// li r5,-24
	ctx.r5.s64 = -24;
	// stw r9,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r9.u32);
	// li r4,-16
	ctx.r4.s64 = -16;
	// stw r6,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r6.u32);
	// addi r3,r10,13120
	ctx.r3.s64 = ctx.r10.s64 + 13120;
	// stw r5,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r5.u32);
	// stw r11,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// stw r8,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r8.u32);
	// stw r7,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r7.u32);
	// stw r4,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r4.u32);
	// stw r3,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r3.u32);
	// b 0x880c3adc
	goto loc_880C3ADC;
loc_880C3A9C:
	// lwz r10,24(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880c3aac
	if (ctx.cr6.eq) goto loc_880C3AAC;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_880C3AAC:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x880c3948
	goto loc_880C3948;
loc_880C3AB4:
	// lwz r8,24(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x880c3ac4
	if (ctx.cr6.eq) goto loc_880C3AC4;
	// stw r8,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r8.u32);
loc_880C3AC4:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x880c3998
	goto loc_880C3998;
loc_880C3ACC:
	// lis r11,-30708
	ctx.r11.s64 = -2012479488;
	// stw r5,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r5.u32);
	// addi r10,r11,12344
	ctx.r10.s64 = ctx.r11.s64 + 12344;
	// stw r10,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r10.u32);
loc_880C3ADC:
	// lis r11,-30708
	ctx.r11.s64 = -2012479488;
	// lis r10,-30708
	ctx.r10.s64 = -2012479488;
	// lis r9,-30708
	ctx.r9.s64 = -2012479488;
	// addi r8,r11,14248
	ctx.r8.s64 = ctx.r11.s64 + 14248;
	// addi r7,r10,12960
	ctx.r7.s64 = ctx.r10.s64 + 12960;
	// addi r6,r9,12896
	ctx.r6.s64 = ctx.r9.s64 + 12896;
	// stw r8,64(r30)
	PPC_STORE_U32(ctx.r30.u32 + 64, ctx.r8.u32);
	// stw r7,68(r30)
	PPC_STORE_U32(ctx.r30.u32 + 68, ctx.r7.u32);
	// stw r6,84(r30)
	PPC_STORE_U32(ctx.r30.u32 + 84, ctx.r6.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C3B08"))) PPC_WEAK_FUNC(sub_880C3B08);
PPC_FUNC_IMPL(__imp__sub_880C3B08) {
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
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// rlwinm r9,r11,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x880c3b50
	if (!ctx.cr6.eq) goto loc_880C3B50;
	// lwz r11,0(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r8,15608(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15608);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// stw r9,15608(r11)
	PPC_STORE_U32(ctx.r11.u32 + 15608, ctx.r9.u32);
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r3,r11,15612
	ctx.r3.s64 = ctx.r11.s64 + 15612;
	// bl 0x88072260
	ctx.lr = 0x880C3B50;
	sub_88072260(ctx, base);
loc_880C3B50:
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

__attribute__((alias("__imp__sub_880C3B64"))) PPC_WEAK_FUNC(sub_880C3B64);
PPC_FUNC_IMPL(__imp__sub_880C3B64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C3B68"))) PPC_WEAK_FUNC(sub_880C3B68);
PPC_FUNC_IMPL(__imp__sub_880C3B68) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880C3B70;
	__savegprlr_29(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x880c3d68
	if (ctx.cr6.lt) goto loc_880C3D68;
	// beq cr6,0x880c3c90
	if (ctx.cr6.eq) goto loc_880C3C90;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x880c3d80
	if (!ctx.cr6.lt) goto loc_880C3D80;
	// lwz r11,184(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880c3c34
	if (ctx.cr6.eq) goto loc_880C3C34;
	// lwz r11,176(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 176);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,176(r31)
	PPC_STORE_U32(ctx.r31.u32 + 176, ctx.r11.u32);
	// bge 0x880c3c34
	if (!ctx.cr0.lt) goto loc_880C3C34;
	// lis r9,-30643
	ctx.r9.s64 = -2008219648;
	// lwz r8,180(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 180);
	// lwz r11,196(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 196);
	// lwz r5,16(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r10,192(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 192);
	// lwz r9,26276(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 26276);
	// stw r8,176(r31)
	PPC_STORE_U32(ctx.r31.u32 + 176, ctx.r8.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x880c3c1c
	if (!ctx.cr6.eq) goto loc_880C3C1C;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// clrlwi r7,r11,16
	ctx.r7.u64 = ctx.r11.u32 & 0xFFFF;
	// extsh r6,r10
	ctx.r6.s64 = ctx.r10.s16;
	// sth r29,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r29.u16);
	// li r3,27
	ctx.r3.s64 = 27;
	// bl 0x8815c948
	ctx.lr = 0x880C3BF4;
	sub_8815C948(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c3c14
	if (ctx.cr6.eq) goto loc_880C3C14;
	// li r11,2
	ctx.r11.s64 = 2;
	// li r10,16
	ctx.r10.s64 = 16;
	// li r9,32
	ctx.r9.s64 = 32;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r11.u8);
	// sth r10,18(r3)
	PPC_STORE_U16(ctx.r3.u32 + 18, ctx.r10.u16);
	// sth r9,20(r3)
	PPC_STORE_U16(ctx.r3.u32 + 20, ctx.r9.u16);
loc_880C3C14:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x880C3C1C;
	sub_8815C860(ctx, base);
loc_880C3C1C:
	// lwz r11,184(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// lwz r10,192(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 192);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// stw r11,184(r31)
	PPC_STORE_U32(ctx.r31.u32 + 184, ctx.r11.u32);
	// stw r10,192(r31)
	PPC_STORE_U32(ctx.r31.u32 + 192, ctx.r10.u32);
loc_880C3C34:
	// lwz r10,108(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// lis r9,-64
	ctx.r9.s64 = -4194304;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// stw r8,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r8.u32);
	// ble cr6,0x880c3c78
	if (!ctx.cr6.gt) goto loc_880C3C78;
	// lis r10,304
	ctx.r10.s64 = 19922944;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x880c3c78
	if (!ctx.cr6.lt) goto loc_880C3C78;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lis r10,-48
	ctx.r10.s64 = -3145728;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x880c3c78
	if (!ctx.cr6.gt) goto loc_880C3C78;
	// lis r10,384
	ctx.r10.s64 = 25165824;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x880c3d80
	if (ctx.cr6.lt) goto loc_880C3D80;
loc_880C3C78:
	// lwz r11,200(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 200);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r29,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r29.u32);
	// bl 0x88094220
	ctx.lr = 0x880C3C88;
	sub_88094220(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_880C3C90:
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// cmpwi cr6,r11,32
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 32, ctx.xer);
	// blt cr6,0x880c3cac
	if (ctx.cr6.lt) goto loc_880C3CAC;
	// li r11,32
	ctx.r11.s64 = 32;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
loc_880C3CAC:
	// lwz r11,116(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// lwz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// li r6,2
	ctx.r6.s64 = 2;
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// lwz r8,52(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addi r4,r10,9552
	ctx.r4.s64 = ctx.r10.s64 + 9552;
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// addi r3,r11,128
	ctx.r3.s64 = ctx.r11.s64 + 128;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r3,2,21,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x7FC;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwzx r3,r11,r4
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r4.u32);
	// lwzx r11,r9,r4
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r4.u32);
	// mullw r9,r3,r5
	ctx.r9.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r5.s32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// mullw r11,r11,r5
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r5.s32);
	// stw r9,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r9.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rotlwi r8,r9,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bgt cr6,0x880c3d14
	if (ctx.cr6.gt) goto loc_880C3D14;
	// stw r29,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r29.u32);
	// stw r7,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r7.u32);
	// stw r6,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
loc_880C3D14:
	// lwz r9,52(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lis r10,240
	ctx.r10.s64 = 15728640;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x880c3d30
	if (ctx.cr6.lt) goto loc_880C3D30;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// stw r7,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r7.u32);
	// stw r6,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
loc_880C3D30:
	// lis r10,16
	ctx.r10.s64 = 1048576;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bgt cr6,0x880c3d48
	if (ctx.cr6.gt) goto loc_880C3D48;
	// stw r10,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r10.u32);
	// stw r7,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r7.u32);
	// stw r6,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
loc_880C3D48:
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// lis r11,320
	ctx.r11.s64 = 20971520;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x880c3d80
	if (ctx.cr6.lt) goto loc_880C3D80;
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// stw r7,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r7.u32);
	// stw r6,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// b 0x880c3d80
	goto loc_880C3D80;
loc_880C3D68:
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
	// bgt 0x880c3d80
	if (ctx.cr0.gt) goto loc_880C3D80;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
loc_880C3D80:
	// lwz r7,56(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// li r11,7
	ctx.r11.s64 = 7;
	// lwz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// lwz r9,52(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// subf r4,r6,r7
	ctx.r4.s64 = ctx.r7.s64 - ctx.r6.s64;
	// subf r5,r8,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r8.s64;
	// divw r4,r4,r11
	ctx.r4.s32 = ppc_divw(ctx.r4.s32, ctx.r11.s32);
	// divw r5,r5,r11
	ctx.r5.s32 = ppc_divw(ctx.r5.s32, ctx.r11.s32);
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
loc_880C3DB0:
	// lwz r8,200(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 200);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// lwz r11,28(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880c3de0
	if (ctx.cr6.eq) goto loc_880C3DE0;
loc_880C3DC8:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x880c3e04
	if (ctx.cr6.eq) goto loc_880C3E04;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880c3dc8
	if (!ctx.cr6.eq) goto loc_880C3DC8;
loc_880C3DE0:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_880C3DE4:
	// stw r7,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r7.u32);
	// add r7,r7,r5
	ctx.r7.u64 = ctx.r7.u64 + ctx.r5.u64;
	// stw r6,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r6.u32);
	// add r6,r6,r4
	ctx.r6.u64 = ctx.r6.u64 + ctx.r4.u64;
	// cmpwi cr6,r10,7
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 7, ctx.xer);
	// blt cr6,0x880c3db0
	if (ctx.cr6.lt) goto loc_880C3DB0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_880C3E04:
	// lwz r9,24(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x880c3e14
	if (ctx.cr6.eq) goto loc_880C3E14;
	// stw r9,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r9.u32);
loc_880C3E14:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x880c3de4
	goto loc_880C3DE4;
}

__attribute__((alias("__imp__sub_880C3E1C"))) PPC_WEAK_FUNC(sub_880C3E1C);
PPC_FUNC_IMPL(__imp__sub_880C3E1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C3E20"))) PPC_WEAK_FUNC(sub_880C3E20);
PPC_FUNC_IMPL(__imp__sub_880C3E20) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// bgt cr6,0x880c3e5c
	if (ctx.cr6.gt) goto loc_880C3E5C;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x880c3edc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_880C3EDC;
	// bdzf 4*cr6+eq,0x880c3fb8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_880C3FB8;
	// bne cr6,0x880c3fd0
	if (!ctx.cr6.eq) goto loc_880C3FD0;
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 96);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,96(r11)
	PPC_STORE_U32(ctx.r11.u32 + 96, ctx.r10.u32);
	// bgt 0x880c3e5c
	if (ctx.cr0.gt) goto loc_880C3E5C;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
loc_880C3E5C:
	// lwz r6,56(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 56);
	// li r10,7
	ctx.r10.s64 = 7;
	// lwz r5,16(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r8,52(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 52);
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// subf r3,r5,r6
	ctx.r3.s64 = ctx.r6.s64 - ctx.r5.s64;
	// subf r4,r7,r8
	ctx.r4.s64 = ctx.r8.s64 - ctx.r7.s64;
	// divw r3,r3,r10
	ctx.r3.s32 = ppc_divw(ctx.r3.s32, ctx.r10.s32);
	// divw r4,r4,r10
	ctx.r4.s32 = ppc_divw(ctx.r4.s32, ctx.r10.s32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
loc_880C3E8C:
	// lwz r7,200(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 200);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// lwz r10,28(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 28);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x880c3ebc
	if (ctx.cr6.eq) goto loc_880C3EBC;
loc_880C3EA4:
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x880c4024
	if (ctx.cr6.eq) goto loc_880C4024;
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x880c3ea4
	if (!ctx.cr6.eq) goto loc_880C3EA4;
loc_880C3EBC:
	// li r10,0
	ctx.r10.s64 = 0;
loc_880C3EC0:
	// stw r6,28(r10)
	PPC_STORE_U32(ctx.r10.u32 + 28, ctx.r6.u32);
	// add r6,r6,r4
	ctx.r6.u64 = ctx.r6.u64 + ctx.r4.u64;
	// stw r5,32(r10)
	PPC_STORE_U32(ctx.r10.u32 + 32, ctx.r5.u32);
	// add r5,r5,r3
	ctx.r5.u64 = ctx.r5.u64 + ctx.r3.u64;
	// cmpwi cr6,r9,7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 7, ctx.xer);
	// blt cr6,0x880c3e8c
	if (ctx.cr6.lt) goto loc_880C3E8C;
	// blr 
	return;
loc_880C3EDC:
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
	// cmpwi cr6,r10,32
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 32, ctx.xer);
	// blt cr6,0x880c3ef8
	if (ctx.cr6.lt) goto loc_880C3EF8;
	// li r10,32
	ctx.r10.s64 = 32;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_880C3EF8:
	// lwz r10,116(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lis r8,-30714
	ctx.r8.s64 = -2012872704;
	// lwz r4,64(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// li r5,1
	ctx.r5.s64 = 1;
	// clrlwi r10,r10,23
	ctx.r10.u64 = ctx.r10.u32 & 0x1FF;
	// lwz r9,52(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 52);
	// addi r3,r8,9552
	ctx.r3.s64 = ctx.r8.s64 + 9552;
	// lwz r7,56(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 56);
	// addi r8,r10,128
	ctx.r8.s64 = ctx.r10.s64 + 128;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r8,2,21,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x7FC;
	// li r6,2
	ctx.r6.s64 = 2;
	// lwzx r10,r10,r3
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// lwzx r3,r8,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r3.u32);
	// mullw r8,r10,r4
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r4.s32);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r3,r4
	ctx.r10.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r4.s32);
	// stw r9,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r9.u32);
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// rotlwi r8,r9,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// stw r10,56(r11)
	PPC_STORE_U32(ctx.r11.u32 + 56, ctx.r10.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bgt cr6,0x880c3f64
	if (ctx.cr6.gt) goto loc_880C3F64;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r5,60(r11)
	PPC_STORE_U32(ctx.r11.u32 + 60, ctx.r5.u32);
	// stw r6,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r6.u32);
	// stw r9,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r9.u32);
loc_880C3F64:
	// lwz r8,52(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 52);
	// lis r9,240
	ctx.r9.s64 = 15728640;
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x880c3f80
	if (ctx.cr6.lt) goto loc_880C3F80;
	// stw r9,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r9.u32);
	// stw r5,60(r11)
	PPC_STORE_U32(ctx.r11.u32 + 60, ctx.r5.u32);
	// stw r6,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r6.u32);
loc_880C3F80:
	// lis r9,16
	ctx.r9.s64 = 1048576;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bgt cr6,0x880c3f98
	if (ctx.cr6.gt) goto loc_880C3F98;
	// stw r9,56(r11)
	PPC_STORE_U32(ctx.r11.u32 + 56, ctx.r9.u32);
	// stw r5,60(r11)
	PPC_STORE_U32(ctx.r11.u32 + 60, ctx.r5.u32);
	// stw r6,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r6.u32);
loc_880C3F98:
	// lwz r9,56(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 56);
	// lis r10,320
	ctx.r10.s64 = 20971520;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x880c3e5c
	if (ctx.cr6.lt) goto loc_880C3E5C;
	// stw r10,56(r11)
	PPC_STORE_U32(ctx.r11.u32 + 56, ctx.r10.u32);
	// stw r5,60(r11)
	PPC_STORE_U32(ctx.r11.u32 + 60, ctx.r5.u32);
	// stw r6,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r6.u32);
	// b 0x880c3e5c
	goto loc_880C3E5C;
loc_880C3FB8:
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 108);
	// li r9,3
	ctx.r9.s64 = 3;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// stw r8,108(r11)
	PPC_STORE_U32(ctx.r11.u32 + 108, ctx.r8.u32);
	// b 0x880c3e5c
	goto loc_880C3E5C;
loc_880C3FD0:
	// lwz r9,108(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 108);
	// lis r8,-64
	ctx.r8.s64 = -4194304;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// cmpw cr6,r10,r8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, ctx.xer);
	// stw r7,108(r11)
	PPC_STORE_U32(ctx.r11.u32 + 108, ctx.r7.u32);
	// ble cr6,0x880c4014
	if (!ctx.cr6.gt) goto loc_880C4014;
	// lis r9,304
	ctx.r9.s64 = 19922944;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x880c4014
	if (!ctx.cr6.lt) goto loc_880C4014;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lis r9,-48
	ctx.r9.s64 = -3145728;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// ble cr6,0x880c4014
	if (!ctx.cr6.gt) goto loc_880C4014;
	// lis r9,384
	ctx.r9.s64 = 25165824;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x880c3e5c
	if (ctx.cr6.lt) goto loc_880C3E5C;
loc_880C4014:
	// lwz r11,200(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 200);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// b 0x88094220
	sub_88094220(ctx, base);
	return;
loc_880C4024:
	// lwz r8,24(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x880c4034
	if (ctx.cr6.eq) goto loc_880C4034;
	// stw r8,64(r10)
	PPC_STORE_U32(ctx.r10.u32 + 64, ctx.r8.u32);
loc_880C4034:
	// addi r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 + 24;
	// b 0x880c3ec0
	goto loc_880C3EC0;
}

__attribute__((alias("__imp__sub_880C403C"))) PPC_WEAK_FUNC(sub_880C403C);
PPC_FUNC_IMPL(__imp__sub_880C403C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C4040"))) PPC_WEAK_FUNC(sub_880C4040);
PPC_FUNC_IMPL(__imp__sub_880C4040) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r9,200(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 200);
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

__attribute__((alias("__imp__sub_880C4080"))) PPC_WEAK_FUNC(sub_880C4080);
PPC_FUNC_IMPL(__imp__sub_880C4080) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071138
	ctx.lr = 0x880C4088;
	__savegprlr_20(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30681
	ctx.r11.s64 = -2010710016;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r3,0
	ctx.r3.s64 = 0;
	// addi r10,r11,-25304
	ctx.r10.s64 = ctx.r11.s64 + -25304;
	// li r6,210
	ctx.r6.s64 = 210;
	// ori r3,r3,34409
	ctx.r3.u64 = ctx.r3.u64 | 34409;
	// lbz r11,-25304(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + -25304);
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lbz r10,1(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// extsb r8,r11
	ctx.r8.s64 = ctx.r11.s8;
	// extsb r7,r10
	ctx.r7.s64 = ctx.r10.s8;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// rlwinm r8,r8,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r7,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r8,r9
	ctx.r4.u64 = ctx.r8.u64 + ctx.r9.u64;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x880C40D0;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c40e0
	if (ctx.cr6.eq) goto loc_880C40E0;
	// lwz r11,160(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 160);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C40E0:
	// lwz r30,12(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r28,4
	ctx.r28.s64 = 262144;
	// lwz r29,16(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// li r6,210
	ctx.r6.s64 = 210;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// add r5,r29,r28
	ctx.r5.u64 = ctx.r29.u64 + ctx.r28.u64;
	// li r3,419
	ctx.r3.s64 = 419;
	// bl 0x881538c0
	ctx.lr = 0x880C4100;
	sub_881538C0(ctx, base);
	// lis r11,545
	ctx.r11.s64 = 35717120;
	// lis r10,128
	ctx.r10.s64 = 8388608;
	// ori r23,r11,32768
	ctx.r23.u64 = ctx.r11.u64 | 32768;
	// ori r24,r10,64
	ctx.r24.u64 = ctx.r10.u64 | 64;
	// lis r20,-30597
	ctx.r20.s64 = -2005204992;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c413c
	if (ctx.cr6.eq) goto loc_880C413C;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-11932(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + -11932);
	// or r9,r10,r23
	ctx.r9.u64 = ctx.r10.u64 | ctx.r23.u64;
	// stw r24,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r24.u32);
	// addi r25,r11,1
	ctx.r25.s64 = ctx.r11.s64 + 1;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r25,-11932(r20)
	PPC_STORE_U32(ctx.r20.u32 + -11932, ctx.r25.u32);
	// b 0x880c4140
	goto loc_880C4140;
loc_880C413C:
	// lwz r25,-11932(r20)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r20.u32 + -11932);
loc_880C4140:
	// li r6,210
	ctx.r6.s64 = 210;
	// subf r5,r28,r29
	ctx.r5.s64 = ctx.r29.s64 - ctx.r28.s64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,419
	ctx.r3.s64 = 419;
	// bl 0x881538c0
	ctx.lr = 0x880C4154;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c4174
	if (ctx.cr6.eq) goto loc_880C4174;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// stw r24,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r24.u32);
	// or r10,r11,r23
	ctx.r10.u64 = ctx.r11.u64 | ctx.r23.u64;
	// stw r25,-11932(r20)
	PPC_STORE_U32(ctx.r20.u32 + -11932, ctx.r25.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_880C4174:
	// li r6,210
	ctx.r6.s64 = 210;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// add r4,r30,r28
	ctx.r4.u64 = ctx.r30.u64 + ctx.r28.u64;
	// li r3,419
	ctx.r3.s64 = 419;
	// bl 0x881538c0
	ctx.lr = 0x880C4188;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c41a8
	if (ctx.cr6.eq) goto loc_880C41A8;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// stw r24,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r24.u32);
	// or r10,r11,r23
	ctx.r10.u64 = ctx.r11.u64 | ctx.r23.u64;
	// stw r25,-11932(r20)
	PPC_STORE_U32(ctx.r20.u32 + -11932, ctx.r25.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_880C41A8:
	// li r6,210
	ctx.r6.s64 = 210;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// subf r4,r28,r30
	ctx.r4.s64 = ctx.r30.s64 - ctx.r28.s64;
	// li r3,419
	ctx.r3.s64 = 419;
	// bl 0x881538c0
	ctx.lr = 0x880C41BC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c41dc
	if (ctx.cr6.eq) goto loc_880C41DC;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// stw r24,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r24.u32);
	// or r10,r11,r23
	ctx.r10.u64 = ctx.r11.u64 | ctx.r23.u64;
	// stw r25,-11932(r20)
	PPC_STORE_U32(ctx.r20.u32 + -11932, ctx.r25.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_880C41DC:
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// li r11,7
	ctx.r11.s64 = 7;
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r28,0
	ctx.r28.s64 = 0;
	// lwz r8,56(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r7,16(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r6,r9,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r9.s64;
	// subf r5,r7,r8
	ctx.r5.s64 = ctx.r8.s64 - ctx.r7.s64;
	// divw r22,r6,r11
	ctx.r22.s32 = ppc_divw(ctx.r6.s32, ctx.r11.s32);
	// divw r21,r5,r11
	ctx.r21.s32 = ppc_divw(ctx.r5.s32, ctx.r11.s32);
	// mr r27,r22
	ctx.r27.u64 = ctx.r22.u64;
	// mr r26,r21
	ctx.r26.u64 = ctx.r21.u64;
loc_880C420C:
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// clrlwi r9,r28,31
	ctx.r9.u64 = ctx.r28.u32 & 0x1;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lis r3,0
	ctx.r3.s64 = 0;
	// add r30,r27,r10
	ctx.r30.u64 = ctx.r27.u64 + ctx.r10.u64;
	// add r29,r26,r11
	ctx.r29.u64 = ctx.r26.u64 + ctx.r11.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// beq cr6,0x880c4240
	if (ctx.cr6.eq) goto loc_880C4240;
	// li r6,211
	ctx.r6.s64 = 211;
	// ori r3,r3,34442
	ctx.r3.u64 = ctx.r3.u64 | 34442;
	// b 0x880c4248
	goto loc_880C4248;
loc_880C4240:
	// li r6,212
	ctx.r6.s64 = 212;
	// ori r3,r3,34441
	ctx.r3.u64 = ctx.r3.u64 | 34441;
loc_880C4248:
	// bl 0x881538c0
	ctx.lr = 0x880C424C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c425c
	if (ctx.cr6.eq) goto loc_880C425C;
	// lwz r11,160(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 160);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C425C:
	// li r6,212
	ctx.r6.s64 = 212;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,401
	ctx.r3.s64 = 401;
	// bl 0x881538c0
	ctx.lr = 0x880C4270;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c428c
	if (ctx.cr6.eq) goto loc_880C428C;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// stw r24,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r24.u32);
	// or r10,r11,r23
	ctx.r10.u64 = ctx.r11.u64 | ctx.r23.u64;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_880C428C:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// add r27,r27,r22
	ctx.r27.u64 = ctx.r27.u64 + ctx.r22.u64;
	// add r26,r26,r21
	ctx.r26.u64 = ctx.r26.u64 + ctx.r21.u64;
	// cmpwi cr6,r28,7
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 7, ctx.xer);
	// blt cr6,0x880c420c
	if (ctx.cr6.lt) goto loc_880C420C;
	// stw r25,-11932(r20)
	PPC_STORE_U32(ctx.r20.u32 + -11932, ctx.r25.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x88071188
	__restgprlr_20(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C42AC"))) PPC_WEAK_FUNC(sub_880C42AC);
PPC_FUNC_IMPL(__imp__sub_880C42AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C42B0"))) PPC_WEAK_FUNC(sub_880C42B0);
PPC_FUNC_IMPL(__imp__sub_880C42B0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x880C42B8;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,152(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 152);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,172(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 172);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// blt cr6,0x880c42dc
	if (ctx.cr6.lt) goto loc_880C42DC;
	// lwz r11,188(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 188);
	// add r26,r11,r10
	ctx.r26.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x880c42e8
	goto loc_880C42E8;
loc_880C42DC:
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 184);
	// lwz r11,168(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 168);
	// add r26,r10,r11
	ctx.r26.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_880C42E8:
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,40
	ctx.r5.s64 = 40;
	// li r4,93
	ctx.r4.s64 = 93;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x880e32d0
	ctx.lr = 0x880C42FC;
	sub_880E32D0(ctx, base);
	// addi r4,r26,1
	ctx.r4.s64 = ctx.r26.s64 + 1;
	// li r30,2
	ctx.r30.s64 = 2;
	// lis r28,-30667
	ctx.r28.s64 = -2009792512;
	// lis r29,-30667
	ctx.r29.s64 = -2009792512;
loc_880C430C:
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// stw r11,12364(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12372, ctx.r10.u32);
	// bl 0x880f34b0
	ctx.lr = 0x880C4324;
	sub_880F34B0(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,12364(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12372, ctx.r10.u32);
	// bl 0x880f34b0
	ctx.lr = 0x880C433C;
	sub_880F34B0(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x880c430c
	if (!ctx.cr0.eq) goto loc_880C430C;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r27,-30667
	ctx.r27.s64 = -2009792512;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lis r30,-30667
	ctx.r30.s64 = -2009792512;
	// addi r4,r26,2
	ctx.r4.s64 = ctx.r26.s64 + 2;
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r11,12364(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12364, ctx.r11.u32);
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r10,12372(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12372, ctx.r10.u32);
	// stw r4,12376(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12376, ctx.r4.u32);
	// stw r11,12380(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12380, ctx.r11.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880C4374;
	sub_880F52C8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c4384
	if (ctx.cr6.eq) goto loc_880C4384;
	// lwz r11,172(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 172);
	// stw r11,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r11.u32);
loc_880C4384:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,15736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15736);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x880c43b0
	if (!ctx.cr6.eq) goto loc_880C43B0;
	// lwz r10,152(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 152);
	// lwz r8,15752(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15752);
	// lwz r7,15748(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15748);
	// lwz r6,15744(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15744);
	// lwz r5,15740(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15740);
	// lwz r4,12(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// bl 0x880f5438
	ctx.lr = 0x880C43B0;
	sub_880F5438(ctx, base);
loc_880C43B0:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,15736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15736);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x880c43fc
	if (!ctx.cr6.eq) goto loc_880C43FC;
	// lwz r11,15740(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15740);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880c43fc
	if (!ctx.cr6.eq) goto loc_880C43FC;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// li r8,140
	ctx.r8.s64 = 140;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r9,12380(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12380, ctx.r9.u32);
	// li r4,140
	ctx.r4.s64 = 140;
	// stw r8,12376(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12376, ctx.r8.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,12364(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12372, ctx.r10.u32);
	// bl 0x881607f8
	ctx.lr = 0x880C43FC;
	sub_881607F8(ctx, base);
loc_880C43FC:
	// lwz r11,200(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 200);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C4410"))) PPC_WEAK_FUNC(sub_880C4410);
PPC_FUNC_IMPL(__imp__sub_880C4410) {
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
	// lwz r10,15736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15736);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880c444c
	if (ctx.cr6.eq) goto loc_880C444C;
	// bl 0x880c42b0
	ctx.lr = 0x880C4440;
	sub_880C42B0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88094220
	ctx.lr = 0x880C4448;
	sub_88094220(ctx, base);
	// b 0x880c4578
	goto loc_880C4578;
loc_880C444C:
	// lwz r11,200(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 200);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880c447c
	if (ctx.cr6.eq) goto loc_880C447C;
loc_880C4464:
	// lwz r8,20(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// stw r9,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r9.u32);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// or r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 | ctx.r8.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880c4464
	if (!ctx.cr6.eq) goto loc_880C4464;
loc_880C447C:
	// lis r11,128
	ctx.r11.s64 = 8388608;
	// clrlwi r10,r10,20
	ctx.r10.u64 = ctx.r10.u32 & 0xFFF;
	// ori r9,r11,32896
	ctx.r9.u64 = ctx.r11.u64 | 32896;
	// rlwinm r10,r10,0,26,21
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFC3F;
	// stw r9,160(r3)
	PPC_STORE_U32(ctx.r3.u32 + 160, ctx.r9.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x880c44bc
	if (ctx.cr6.eq) goto loc_880C44BC;
	// lwz r11,164(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// stw r11,164(r3)
	PPC_STORE_U32(ctx.r3.u32 + 164, ctx.r11.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880c44bc
	if (ctx.cr6.eq) goto loc_880C44BC;
	// lis r11,192
	ctx.r11.s64 = 12582912;
	// ori r10,r11,49152
	ctx.r10.u64 = ctx.r11.u64 | 49152;
	// stw r10,160(r3)
	PPC_STORE_U32(ctx.r3.u32 + 160, ctx.r10.u32);
loc_880C44BC:
	// lwz r11,116(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// lis r8,-30714
	ctx.r8.s64 = -2012872704;
	// lis r10,-30640
	ctx.r10.s64 = -2008023040;
	// lwz r7,108(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 108);
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r6,r8,9552
	ctx.r6.s64 = ctx.r8.s64 + 9552;
	// lwz r8,16(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r5,r11,128
	ctx.r5.s64 = ctx.r11.s64 + 128;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r31,r5,2,21,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x7FC;
	// addi r5,r10,31696
	ctx.r5.s64 = ctx.r10.s64 + 31696;
	// lis r30,-30643
	ctx.r30.s64 = -2008219648;
	// addi r11,r3,12
	ctx.r11.s64 = ctx.r3.s64 + 12;
	// lwzx r10,r4,r6
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r6.u32);
	// lwzx r4,r31,r6
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r6.u32);
	// mullw r10,r10,r7
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32);
	// lwz r6,26272(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 26272);
	// mullw r7,r4,r7
	ctx.r7.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r7.s32);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r9,r7,r8
	ctx.r9.u64 = ctx.r7.u64 + ctx.r8.u64;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// stw r9,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r9.u32);
	// bne cr6,0x880c4540
	if (!ctx.cr6.eq) goto loc_880C4540;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880c4540
	if (ctx.cr6.eq) goto loc_880C4540;
	// lwz r10,172(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 172);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r8,r5
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r5.u32);
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r7,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
loc_880C4540:
	// lwz r11,60(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880c4578
	if (!ctx.cr6.eq) goto loc_880C4578;
	// addi r11,r3,52
	ctx.r11.s64 = ctx.r3.s64 + 52;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne cr6,0x880c4578
	if (!ctx.cr6.eq) goto loc_880C4578;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880c4578
	if (ctx.cr6.eq) goto loc_880C4578;
	// lwz r10,172(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 172);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r8,r5
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r5.u32);
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r7,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
loc_880C4578:
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

__attribute__((alias("__imp__sub_880C4590"))) PPC_WEAK_FUNC(sub_880C4590);
PPC_FUNC_IMPL(__imp__sub_880C4590) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x880C4598;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30708
	ctx.r11.s64 = -2012479488;
	// li r4,204
	ctx.r4.s64 = 204;
	// addi r5,r11,17808
	ctx.r5.s64 = ctx.r11.s64 + 17808;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x880C45B0;
	sub_88094290(ctx, base);
	// li r5,204
	ctx.r5.s64 = 204;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,2304(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2304);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x880C45C4;
	sub_88073BD0(ctx, base);
	// stw r30,152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 152, ctx.r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x881556a0
	ctx.lr = 0x880C45D4;
	sub_881556A0(ctx, base);
	// lis r10,-30708
	ctx.r10.s64 = -2012479488;
	// stw r3,200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 200, ctx.r3.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r9,r10,15112
	ctx.r9.s64 = ctx.r10.s64 + 15112;
	// stw r31,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r31.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r9,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r9.u32);
	// lwz r8,200(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 200);
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// stw r5,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r5.u32);
	// lwz r9,200(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 200);
	// lwz r11,28(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880c4624
	if (ctx.cr6.eq) goto loc_880C4624;
loc_880C460C:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880c4810
	if (ctx.cr6.eq) goto loc_880C4810;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880c460c
	if (!ctx.cr6.eq) goto loc_880C460C;
loc_880C4624:
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
loc_880C4628:
	// li r9,20
	ctx.r9.s64 = 20;
	// stw r5,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r5.u32);
	// addi r6,r31,12
	ctx.r6.s64 = ctx.r31.s64 + 12;
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// stw r6,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r6.u32);
	// li r7,6
	ctx.r7.s64 = 6;
	// stw r9,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r9.u32);
	// stw r9,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r9.u32);
	// stw r9,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r9.u32);
loc_880C4650:
	// lwz r8,200(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 200);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// lwz r11,28(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880c4680
	if (ctx.cr6.eq) goto loc_880C4680;
loc_880C4668:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880c4828
	if (ctx.cr6.eq) goto loc_880C4828;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880c4668
	if (!ctx.cr6.eq) goto loc_880C4668;
loc_880C4680:
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
loc_880C4684:
	// stw r6,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r6.u32);
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// stw r5,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r5.u32);
	// cmpwi cr6,r9,7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 7, ctx.xer);
	// stw r7,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r7.u32);
	// stw r7,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r7.u32);
	// stw r7,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r7.u32);
	// stw r7,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r7.u32);
	// blt cr6,0x880c4650
	if (ctx.cr6.lt) goto loc_880C4650;
	// lwz r11,32(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// li r3,100
	ctx.r3.s64 = 100;
	// li r28,256
	ctx.r28.s64 = 256;
	// addi r10,r30,120
	ctx.r10.s64 = ctx.r30.s64 + 120;
	// li r7,16
	ctx.r7.s64 = 16;
	// li r29,47
	ctx.r29.s64 = 47;
	// stw r11,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r11.u32);
	// lis r27,-30597
	ctx.r27.s64 = -2005204992;
	// lwz r11,36(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// li r8,2
	ctx.r8.s64 = 2;
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// li r9,40
	ctx.r9.s64 = 40;
	// stw r3,168(r30)
	PPC_STORE_U32(ctx.r30.u32 + 168, ctx.r3.u32);
	// li r11,8
	ctx.r11.s64 = 8;
	// lwz r6,0(r6)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// stw r10,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r10.u32);
	// stw r28,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r28.u32);
	// stw r4,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r4.u32);
	// stw r7,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r7.u32);
	// stw r29,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r29.u32);
	// stw r6,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r6.u32);
	// lwz r10,-11984(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11984);
	// lwz r3,132(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 132);
	// stw r3,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r3.u32);
	// lwz r6,136(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 136);
	// stw r6,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r6.u32);
	// lwz r3,140(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 140);
	// lwz r6,2304(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// stw r6,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r6.u32);
	// lwz r3,140(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 140);
	// stw r3,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// sth r8,20(r31)
	PPC_STORE_U16(ctx.r31.u32 + 20, ctx.r8.u16);
	// sth r8,22(r31)
	PPC_STORE_U16(ctx.r31.u32 + 22, ctx.r8.u16);
	// sth r9,24(r31)
	PPC_STORE_U16(ctx.r31.u32 + 24, ctx.r9.u16);
	// sth r9,26(r31)
	PPC_STORE_U16(ctx.r31.u32 + 26, ctx.r9.u16);
	// stw r4,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r4.u32);
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// lwz r10,84(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// beq cr6,0x880c4870
	if (ctx.cr6.eq) goto loc_880C4870;
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// bne cr6,0x880c487c
	if (!ctx.cr6.eq) goto loc_880C487C;
	// stw r11,176(r31)
	PPC_STORE_U32(ctx.r31.u32 + 176, ctx.r11.u32);
	// li r8,-16
	ctx.r8.s64 = -16;
	// lwz r9,200(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 200);
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// stw r11,184(r31)
	PPC_STORE_U32(ctx.r31.u32 + 184, ctx.r11.u32);
	// stw r5,180(r31)
	PPC_STORE_U32(ctx.r31.u32 + 180, ctx.r5.u32);
	// stw r8,192(r31)
	PPC_STORE_U32(ctx.r31.u32 + 192, ctx.r8.u32);
	// lwz r11,28(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880c4798
	if (ctx.cr6.eq) goto loc_880C4798;
loc_880C4780:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880c4840
	if (ctx.cr6.eq) goto loc_880C4840;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880c4780
	if (!ctx.cr6.eq) goto loc_880C4780;
loc_880C4798:
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
loc_880C479C:
	// stw r7,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r7.u32);
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// stw r7,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r7.u32);
	// stw r7,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r7.u32);
	// stw r7,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r7.u32);
	// li r7,4
	ctx.r7.s64 = 4;
loc_880C47B4:
	// lwz r9,200(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 200);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// lwz r11,28(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880c47e4
	if (ctx.cr6.eq) goto loc_880C47E4;
loc_880C47CC:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880c4858
	if (ctx.cr6.eq) goto loc_880C4858;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880c47cc
	if (!ctx.cr6.eq) goto loc_880C47CC;
loc_880C47E4:
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
loc_880C47E8:
	// stw r7,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r7.u32);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// stw r7,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r7.u32);
	// cmpwi cr6,r8,7
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 7, ctx.xer);
	// stw r7,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r7.u32);
	// stw r7,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r7.u32);
	// blt cr6,0x880c47b4
	if (ctx.cr6.lt) goto loc_880C47B4;
	// lis r11,-30708
	ctx.r11.s64 = -2012479488;
	// addi r10,r11,15208
	ctx.r10.s64 = ctx.r11.s64 + 15208;
	// b 0x880c4878
	goto loc_880C4878;
loc_880C4810:
	// lwz r10,24(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880c4820
	if (ctx.cr6.eq) goto loc_880C4820;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_880C4820:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x880c4628
	goto loc_880C4628;
loc_880C4828:
	// lwz r10,24(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880c4838
	if (ctx.cr6.eq) goto loc_880C4838;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_880C4838:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x880c4684
	goto loc_880C4684;
loc_880C4840:
	// lwz r10,24(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880c4850
	if (ctx.cr6.eq) goto loc_880C4850;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_880C4850:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x880c479c
	goto loc_880C479C;
loc_880C4858:
	// lwz r10,24(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880c4868
	if (ctx.cr6.eq) goto loc_880C4868;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_880C4868:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x880c47e8
	goto loc_880C47E8;
loc_880C4870:
	// lis r11,-30708
	ctx.r11.s64 = -2012479488;
	// addi r10,r11,15904
	ctx.r10.s64 = ctx.r11.s64 + 15904;
loc_880C4878:
	// stw r10,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r10.u32);
loc_880C487C:
	// lis r11,-30708
	ctx.r11.s64 = -2012479488;
	// lis r10,-30708
	ctx.r10.s64 = -2012479488;
	// lis r9,-30708
	ctx.r9.s64 = -2012479488;
	// addi r8,r11,17424
	ctx.r8.s64 = ctx.r11.s64 + 17424;
	// addi r7,r10,16512
	ctx.r7.s64 = ctx.r10.s64 + 16512;
	// addi r6,r9,16448
	ctx.r6.s64 = ctx.r9.s64 + 16448;
	// stw r8,64(r30)
	PPC_STORE_U32(ctx.r30.u32 + 64, ctx.r8.u32);
	// stw r7,68(r30)
	PPC_STORE_U32(ctx.r30.u32 + 68, ctx.r7.u32);
	// stw r6,84(r30)
	PPC_STORE_U32(ctx.r30.u32 + 84, ctx.r6.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C48A8"))) PPC_WEAK_FUNC(sub_880C48A8);
PPC_FUNC_IMPL(__imp__sub_880C48A8) {
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
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// rlwinm r9,r11,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x880c48f0
	if (!ctx.cr6.eq) goto loc_880C48F0;
	// lwz r11,0(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r8,15608(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15608);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// stw r9,15608(r11)
	PPC_STORE_U32(ctx.r11.u32 + 15608, ctx.r9.u32);
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r3,r11,15612
	ctx.r3.s64 = ctx.r11.s64 + 15612;
	// bl 0x88072260
	ctx.lr = 0x880C48F0;
	sub_88072260(ctx, base);
loc_880C48F0:
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

__attribute__((alias("__imp__sub_880C4904"))) PPC_WEAK_FUNC(sub_880C4904);
PPC_FUNC_IMPL(__imp__sub_880C4904) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C4908"))) PPC_WEAK_FUNC(sub_880C4908);
PPC_FUNC_IMPL(__imp__sub_880C4908) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r9,272(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 272);
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

__attribute__((alias("__imp__sub_880C4948"))) PPC_WEAK_FUNC(sub_880C4948);
PPC_FUNC_IMPL(__imp__sub_880C4948) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071134
	ctx.lr = 0x880C4950;
	__savegprlr_19(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r22,2304(r3)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// li r19,0
	ctx.r19.s64 = 0;
	// lwz r11,144(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 144);
	// lwz r24,132(r22)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r22.u32 + 132);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x880c4b08
	if (!ctx.cr6.gt) goto loc_880C4B08;
	// lis r26,-30597
	ctx.r26.s64 = -2005204992;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,128
	ctx.r9.s64 = 8388608;
	// lis r11,-30681
	ctx.r11.s64 = -2010710016;
	// addi r27,r22,72
	ctx.r27.s64 = ctx.r22.s64 + 72;
	// lwz r31,-11932(r26)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r26.u32 + -11932);
	// li r20,47
	ctx.r20.s64 = 47;
	// ori r23,r10,34409
	ctx.r23.u64 = ctx.r10.u64 | 34409;
	// lis r21,4
	ctx.r21.s64 = 262144;
	// ori r30,r9,64
	ctx.r30.u64 = ctx.r9.u64 | 64;
	// addi r25,r11,-25304
	ctx.r25.s64 = ctx.r11.s64 + -25304;
loc_880C4998:
	// lwz r11,60(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 60);
	// addi r9,r25,1
	ctx.r9.s64 = ctx.r25.s64 + 1;
	// lwz r10,-4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + -4);
	// li r6,211
	ctx.r6.s64 = 211;
	// rlwinm r7,r11,5,0,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r8,0(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// subf r5,r11,r7
	ctx.r5.s64 = ctx.r7.s64 - ctx.r11.s64;
	// divw r4,r5,r20
	ctx.r4.s32 = ppc_divw(ctx.r5.s32, ctx.r20.s32);
	// subfic r11,r4,31
	ctx.xer.ca = ctx.r4.u32 <= 31;
	ctx.r11.s64 = 31 - ctx.r4.s64;
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r11,r23
	ctx.r3.u64 = ctx.r11.u64 + ctx.r23.u64;
	// lbzx r5,r7,r25
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r25.u32);
	// lbzx r4,r7,r9
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r9.u32);
	// extsb r11,r5
	ctx.r11.s64 = ctx.r5.s8;
	// extsb r7,r4
	ctx.r7.s64 = ctx.r4.s8;
	// rlwinm r9,r11,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r7,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r9,r10
	ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r5,r11,r8
	ctx.r5.u64 = ctx.r11.u64 + ctx.r8.u64;
	// bl 0x881538c0
	ctx.lr = 0x880C49E8;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c49fc
	if (ctx.cr6.eq) goto loc_880C49FC;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// lwz r10,15272(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15272);
	// stw r10,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r10.u32);
loc_880C49FC:
	// lwz r29,-4(r27)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r27.u32 + -4);
	// li r6,211
	ctx.r6.s64 = 211;
	// lwz r28,0(r27)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// li r3,419
	ctx.r3.s64 = 419;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// add r5,r28,r21
	ctx.r5.u64 = ctx.r28.u64 + ctx.r21.u64;
	// bl 0x881538c0
	ctx.lr = 0x880C4A18;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c4a3c
	if (ctx.cr6.eq) goto loc_880C4A3C;
	// lis r11,545
	ctx.r11.s64 = 35717120;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r30,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r30.u32);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// rlwimi r11,r24,8,16,23
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r24.u32, 8) & 0xFF00) | (ctx.r11.u64 & 0xFFFFFFFFFFFF00FF);
	// or r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_880C4A3C:
	// li r6,211
	ctx.r6.s64 = 211;
	// subf r5,r21,r28
	ctx.r5.s64 = ctx.r28.s64 - ctx.r21.s64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,419
	ctx.r3.s64 = 419;
	// bl 0x881538c0
	ctx.lr = 0x880C4A50;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c4a78
	if (ctx.cr6.eq) goto loc_880C4A78;
	// lis r11,545
	ctx.r11.s64 = 35717120;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// stw r30,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r30.u32);
	// rlwimi r11,r24,8,16,23
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r24.u32, 8) & 0xFF00) | (ctx.r11.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r31,-11932(r26)
	PPC_STORE_U32(ctx.r26.u32 + -11932, ctx.r31.u32);
	// or r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_880C4A78:
	// li r6,211
	ctx.r6.s64 = 211;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// add r4,r29,r21
	ctx.r4.u64 = ctx.r29.u64 + ctx.r21.u64;
	// li r3,419
	ctx.r3.s64 = 419;
	// bl 0x881538c0
	ctx.lr = 0x880C4A8C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c4ab4
	if (ctx.cr6.eq) goto loc_880C4AB4;
	// lis r11,545
	ctx.r11.s64 = 35717120;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// stw r30,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r30.u32);
	// rlwimi r11,r24,8,16,23
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r24.u32, 8) & 0xFF00) | (ctx.r11.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r31,-11932(r26)
	PPC_STORE_U32(ctx.r26.u32 + -11932, ctx.r31.u32);
	// or r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_880C4AB4:
	// li r6,211
	ctx.r6.s64 = 211;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// subf r4,r21,r29
	ctx.r4.s64 = ctx.r29.s64 - ctx.r21.s64;
	// li r3,419
	ctx.r3.s64 = 419;
	// bl 0x881538c0
	ctx.lr = 0x880C4AC8;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c4af0
	if (ctx.cr6.eq) goto loc_880C4AF0;
	// lis r11,545
	ctx.r11.s64 = 35717120;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// stw r30,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r30.u32);
	// rlwimi r11,r24,8,16,23
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r24.u32, 8) & 0xFF00) | (ctx.r11.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r31,-11932(r26)
	PPC_STORE_U32(ctx.r26.u32 + -11932, ctx.r31.u32);
	// or r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_880C4AF0:
	// lwz r11,144(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 144);
	// addi r19,r19,1
	ctx.r19.s64 = ctx.r19.s64 + 1;
	// addi r27,r27,8
	ctx.r27.s64 = ctx.r27.s64 + 8;
	// cmpw cr6,r19,r11
	ctx.cr6.compare<int32_t>(ctx.r19.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x880c4998
	if (ctx.cr6.lt) goto loc_880C4998;
	// stw r31,-11932(r26)
	PPC_STORE_U32(ctx.r26.u32 + -11932, ctx.r31.u32);
loc_880C4B08:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x88071184
	__restgprlr_19(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C4B10"))) PPC_WEAK_FUNC(sub_880C4B10);
PPC_FUNC_IMPL(__imp__sub_880C4B10) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x880C4B18;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,248(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 248);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,172(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 172);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// blt cr6,0x880c4b3c
	if (ctx.cr6.lt) goto loc_880C4B3C;
	// lwz r11,188(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 188);
	// add r26,r11,r10
	ctx.r26.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x880c4b48
	goto loc_880C4B48;
loc_880C4B3C:
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 184);
	// lwz r11,168(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 168);
	// add r26,r10,r11
	ctx.r26.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_880C4B48:
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,40
	ctx.r5.s64 = 40;
	// li r4,93
	ctx.r4.s64 = 93;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x880e32d0
	ctx.lr = 0x880C4B5C;
	sub_880E32D0(ctx, base);
	// addi r4,r26,1
	ctx.r4.s64 = ctx.r26.s64 + 1;
	// li r30,2
	ctx.r30.s64 = 2;
	// lis r28,-30667
	ctx.r28.s64 = -2009792512;
	// lis r29,-30667
	ctx.r29.s64 = -2009792512;
loc_880C4B6C:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// stw r11,12364(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12372, ctx.r10.u32);
	// bl 0x880f34b0
	ctx.lr = 0x880C4B84;
	sub_880F34B0(ctx, base);
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,12364(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12372, ctx.r10.u32);
	// bl 0x880f34b0
	ctx.lr = 0x880C4B9C;
	sub_880F34B0(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x880c4b6c
	if (!ctx.cr0.eq) goto loc_880C4B6C;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lis r27,-30667
	ctx.r27.s64 = -2009792512;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lis r30,-30667
	ctx.r30.s64 = -2009792512;
	// addi r4,r26,2
	ctx.r4.s64 = ctx.r26.s64 + 2;
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r11,12364(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12364, ctx.r11.u32);
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r10,12372(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12372, ctx.r10.u32);
	// stw r4,12376(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12376, ctx.r4.u32);
	// stw r11,12380(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12380, ctx.r11.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880C4BD4;
	sub_880F52C8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c4be4
	if (ctx.cr6.eq) goto loc_880C4BE4;
	// lwz r11,268(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 268);
	// stw r11,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r11.u32);
loc_880C4BE4:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,15736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15736);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x880c4c10
	if (!ctx.cr6.eq) goto loc_880C4C10;
	// lwz r10,248(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 248);
	// lwz r8,15752(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15752);
	// lwz r7,15748(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15748);
	// lwz r6,15744(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15744);
	// lwz r5,15740(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15740);
	// lwz r4,12(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// bl 0x880f5438
	ctx.lr = 0x880C4C10;
	sub_880F5438(ctx, base);
loc_880C4C10:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,15736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15736);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x880c4c5c
	if (!ctx.cr6.eq) goto loc_880C4C5C;
	// lwz r11,15740(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 15740);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880c4c5c
	if (!ctx.cr6.eq) goto loc_880C4C5C;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// li r8,140
	ctx.r8.s64 = 140;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r9,12380(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12380, ctx.r9.u32);
	// li r4,140
	ctx.r4.s64 = 140;
	// stw r8,12376(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12376, ctx.r8.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,12364(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12372, ctx.r10.u32);
	// bl 0x881607f8
	ctx.lr = 0x880C4C5C;
	sub_881607F8(ctx, base);
loc_880C4C5C:
	// lwz r11,272(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 272);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C4C70"))) PPC_WEAK_FUNC(sub_880C4C70);
PPC_FUNC_IMPL(__imp__sub_880C4C70) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x880C4C78;
	__savegprlr_27(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,15736(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 15736);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880c4cac
	if (ctx.cr6.eq) goto loc_880C4CAC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880c4b10
	ctx.lr = 0x880C4C9C;
	sub_880C4B10(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88094220
	ctx.lr = 0x880C4CA4;
	sub_88094220(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_880C4CAC:
	// lwz r11,212(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 212);
	// lis r3,-30643
	ctx.r3.s64 = -2008219648;
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// lwz r5,204(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 204);
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r10,r10,9552
	ctx.r10.s64 = ctx.r10.s64 + 9552;
	// lwz r6,20(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addi r9,r11,128
	ctx.r9.s64 = ctx.r11.s64 + 128;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,26272(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 26272);
	// rlwinm r29,r9,2,21,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x7FC;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// addi r9,r31,16
	ctx.r9.s64 = ctx.r31.s64 + 16;
	// lwzx r3,r7,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// lwzx r11,r29,r10
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r10.u32);
	// mullw r7,r3,r5
	ctx.r7.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r5.s32);
	// mullw r5,r11,r5
	ctx.r5.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r5.s32);
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// add r7,r5,r6
	ctx.r7.u64 = ctx.r5.u64 + ctx.r6.u64;
	// stw r8,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r8.u32);
	// stw r7,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r7.u32);
	// bne cr6,0x880c4d30
	if (!ctx.cr6.eq) goto loc_880C4D30;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x880c4d30
	if (ctx.cr6.eq) goto loc_880C4D30;
	// lwz r8,268(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 268);
	// lis r7,-30640
	ctx.r7.s64 = -2008023040;
	// lwz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r6,r7,31696
	ctx.r6.s64 = ctx.r7.s64 + 31696;
	// rlwinm r5,r8,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r5,r6
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r6.u32);
	// add r3,r8,r11
	ctx.r3.u64 = ctx.r8.u64 + ctx.r11.u64;
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
loc_880C4D30:
	// lwz r11,100(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 100);
	// lis r5,16
	ctx.r5.s64 = 1048576;
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// lwz r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// add. r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 + ctx.r5.u64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// rlwinm r7,r11,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// and r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 & ctx.r11.u64;
	// ble 0x880c4da4
	if (!ctx.cr0.gt) goto loc_880C4DA4;
	// lis r7,32
	ctx.r7.s64 = 2097152;
	// lis r3,320
	ctx.r3.s64 = 20971520;
	// subf r8,r7,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r7.s64;
	// cmpw cr6,r8,r3
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r3.s32, ctx.xer);
	// bge cr6,0x880c4da4
	if (!ctx.cr6.lt) goto loc_880C4DA4;
	// lis r8,-30597
	ctx.r8.s64 = -2005204992;
	// addi r3,r11,55
	ctx.r3.s64 = ctx.r11.s64 + 55;
	// lis r29,-40
	ctx.r29.s64 = -2621440;
	// rlwinm r3,r3,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-11984(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -11984);
	// lwzx r11,r3,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r11.u32);
	// add r11,r11,r6
	ctx.r11.u64 = ctx.r11.u64 + ctx.r6.u64;
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// cmpw cr6,r11,r29
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r29.s32, ctx.xer);
	// ble cr6,0x880c4da4
	if (!ctx.cr6.gt) goto loc_880C4DA4;
	// lis r8,280
	ctx.r8.s64 = 18350080;
	// subf r7,r7,r11
	ctx.r7.s64 = ctx.r11.s64 - ctx.r7.s64;
	// cmpw cr6,r7,r8
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x880c4db4
	if (ctx.cr6.lt) goto loc_880C4DB4;
loc_880C4DA4:
	// lwz r11,264(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 264);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880c4dbc
	if (ctx.cr6.eq) goto loc_880C4DBC;
	// b 0x880c5164
	goto loc_880C5164;
loc_880C4DB4:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,264(r31)
	PPC_STORE_U32(ctx.r31.u32 + 264, ctx.r11.u32);
loc_880C4DBC:
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bgt cr6,0x880c514c
	if (ctx.cr6.gt) goto loc_880C514C;
	// beq cr6,0x880c4fe0
	if (ctx.cr6.eq) goto loc_880C4FE0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880c4eec
	if (ctx.cr6.eq) goto loc_880C4EEC;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// bne cr6,0x880c5178
	if (!ctx.cr6.eq) goto loc_880C5178;
	// lwz r8,8(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r7,44(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addic. r11,r7,-1
	ctx.xer.ca = ctx.r7.u32 > 0;
	ctx.r11.s64 = ctx.r7.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// lwz r6,12(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// addis r5,r6,-72
	ctx.r5.s64 = ctx.r6.s64 + -4718592;
	// stw r5,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r5.u32);
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// bge 0x880c4e24
	if (!ctx.cr0.lt) goto loc_880C4E24;
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r8,48(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// stw r8,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r8.u32);
	// blt cr6,0x880c4e24
	if (ctx.cr6.lt) goto loc_880C4E24;
	// li r11,16
	ctx.r11.s64 = 16;
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
loc_880C4E24:
	// lwz r7,140(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r6,56(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// mullw r7,r7,r6
	ctx.r7.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r6.s32);
	// lwz r5,144(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// add r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 + ctx.r11.u64;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// ble cr6,0x880c4eb4
	if (!ctx.cr6.gt) goto loc_880C4EB4;
	// addi r7,r31,64
	ctx.r7.s64 = ctx.r31.s64 + 64;
	// li r30,512
	ctx.r30.s64 = 512;
loc_880C4E58:
	// clrlwi r6,r11,23
	ctx.r6.u64 = ctx.r11.u32 & 0x1FF;
	// lwz r5,60(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// rlwinm r28,r11,2,21,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x7FC;
	// lwz r4,0(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r6,r6,128
	ctx.r6.s64 = ctx.r6.s64 + 128;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// rlwinm r5,r5,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r27,r6,2,21,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lwzx r6,r28,r10
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r28.u32 + ctx.r10.u32);
	// mullw r6,r6,r5
	ctx.r6.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r5.s32);
	// lwzx r28,r27,r10
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r10.u32);
	// mullw r5,r28,r5
	ctx.r5.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r5.s32);
	// add r6,r6,r4
	ctx.r6.u64 = ctx.r6.u64 + ctx.r4.u64;
	// add r5,r5,r3
	ctx.r5.u64 = ctx.r5.u64 + ctx.r3.u64;
	// stw r6,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r6.u32);
	// stwu r5,8(r7)
	ea = 8 + ctx.r7.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r7.u32 = ea;
	// lwz r5,144(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// divw r6,r30,r5
	ctx.r6.s32 = ppc_divw(ctx.r30.s32, ctx.r5.s32);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// add r11,r6,r11
	ctx.r11.u64 = ctx.r6.u64 + ctx.r11.u64;
	// cmpw cr6,r8,r5
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r5.s32, ctx.xer);
	// blt cr6,0x880c4e58
	if (ctx.cr6.lt) goto loc_880C4E58;
loc_880C4EB4:
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// blt cr6,0x880c5178
	if (ctx.cr6.lt) goto loc_880C5178;
	// lwz r11,168(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 168);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r11.u32);
	// bgt 0x880c5178
	if (ctx.cr0.gt) goto loc_880C5178;
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// li r10,20
	ctx.r10.s64 = 20;
	// stw r29,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r29.u32);
	// stw r10,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r10.u32);
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_880C4EEC:
	// lwz r8,8(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r11,132(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// addi r11,r11,3
	ctx.r11.s64 = ctx.r11.s64 + 3;
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// cmpwi cr6,r11,128
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 128, ctx.xer);
	// lwz r7,12(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// addis r6,r7,-72
	ctx.r6.s64 = ctx.r7.s64 + -4718592;
	// stw r11,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r11.u32);
	// stw r6,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r6.u32);
	// blt cr6,0x880c4f1c
	if (ctx.cr6.lt) goto loc_880C4F1C;
	// li r11,128
	ctx.r11.s64 = 128;
	// stw r11,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r11.u32);
loc_880C4F1C:
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// cmpwi cr6,r11,47
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 47, ctx.xer);
	// blt cr6,0x880c4f54
	if (ctx.cr6.lt) goto loc_880C4F54;
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r29,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r29.u32);
	// li r8,10
	ctx.r8.s64 = 10;
	// li r7,47
	ctx.r7.s64 = 47;
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// stw r8,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r8.u32);
	// stw r7,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r7.u32);
	// stw r11,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
loc_880C4F54:
	// lwz r7,52(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// lwz r11,140(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r6,144(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// ble cr6,0x880c5178
	if (!ctx.cr6.gt) goto loc_880C5178;
	// addi r7,r31,64
	ctx.r7.s64 = ctx.r31.s64 + 64;
	// li r30,512
	ctx.r30.s64 = 512;
loc_880C4F7C:
	// clrlwi r6,r11,23
	ctx.r6.u64 = ctx.r11.u32 & 0x1FF;
	// lwz r5,60(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// rlwinm r29,r11,2,21,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x7FC;
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r6,r6,128
	ctx.r6.s64 = ctx.r6.s64 + 128;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// rlwinm r5,r5,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r28,r6,2,21,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lwzx r6,r29,r10
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r10.u32);
	// mullw r6,r6,r5
	ctx.r6.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r5.s32);
	// lwzx r29,r28,r10
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r28.u32 + ctx.r10.u32);
	// mullw r5,r29,r5
	ctx.r5.s64 = int64_t(ctx.r29.s32) * int64_t(ctx.r5.s32);
	// add r6,r6,r3
	ctx.r6.u64 = ctx.r6.u64 + ctx.r3.u64;
	// add r5,r5,r4
	ctx.r5.u64 = ctx.r5.u64 + ctx.r4.u64;
	// stw r6,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r6.u32);
	// stwu r5,8(r7)
	ea = 8 + ctx.r7.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r7.u32 = ea;
	// lwz r5,144(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// divw r6,r30,r5
	ctx.r6.s32 = ppc_divw(ctx.r30.s32, ctx.r5.s32);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// cmpw cr6,r8,r5
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r5.s32, ctx.xer);
	// add r11,r6,r11
	ctx.r11.u64 = ctx.r6.u64 + ctx.r11.u64;
	// blt cr6,0x880c4f7c
	if (ctx.cr6.lt) goto loc_880C4F7C;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_880C4FE0:
	// lwz r3,8(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r7,56(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// li r30,512
	ctx.r30.s64 = 512;
	// lwz r11,140(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// lwz r5,52(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// mullw r11,r7,r11
	ctx.r11.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r11.s32);
	// lwz r7,64(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// lwz r4,12(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// lwz r6,144(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// addi r3,r7,1
	ctx.r3.s64 = ctx.r7.s64 + 1;
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// addis r7,r4,-72
	ctx.r7.s64 = ctx.r4.s64 + -4718592;
	// stw r3,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r3.u32);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// stw r7,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r7.u32);
	// ble cr6,0x880c5090
	if (!ctx.cr6.gt) goto loc_880C5090;
	// addi r7,r31,64
	ctx.r7.s64 = ctx.r31.s64 + 64;
loc_880C5034:
	// clrlwi r6,r11,23
	ctx.r6.u64 = ctx.r11.u32 & 0x1FF;
	// lwz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// rlwinm r5,r11,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x7FC;
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r6,r6,128
	ctx.r6.s64 = ctx.r6.s64 + 128;
	// rlwinm r28,r4,3,0,28
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// rlwinm r27,r6,2,21,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lwzx r5,r5,r10
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r10.u32);
	// mullw r6,r5,r28
	ctx.r6.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r28.s32);
	// lwzx r5,r27,r10
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r10.u32);
	// mullw r5,r5,r28
	ctx.r5.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r28.s32);
	// add r6,r6,r3
	ctx.r6.u64 = ctx.r6.u64 + ctx.r3.u64;
	// add r5,r5,r4
	ctx.r5.u64 = ctx.r5.u64 + ctx.r4.u64;
	// stw r6,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r6.u32);
	// stwu r5,8(r7)
	ea = 8 + ctx.r7.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r7.u32 = ea;
	// lwz r4,144(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// divw r5,r30,r4
	ctx.r5.s32 = ppc_divw(ctx.r30.s32, ctx.r4.s32);
	// cmpw cr6,r8,r4
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r4.s32, ctx.xer);
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// add r11,r5,r11
	ctx.r11.u64 = ctx.r5.u64 + ctx.r11.u64;
	// blt cr6,0x880c5034
	if (ctx.cr6.lt) goto loc_880C5034;
loc_880C5090:
	// lwz r11,168(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 168);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880c50b4
	if (ctx.cr6.eq) goto loc_880C50B4;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r11.u32);
	// bgt 0x880c5178
	if (ctx.cr0.gt) goto loc_880C5178;
	// stw r29,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r29.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_880C50B4:
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// bge 0x880c5178
	if (!ctx.cr0.lt) goto loc_880C5178;
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// stw r10,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r10.u32);
	// bgt 0x880c5178
	if (ctx.cr0.gt) goto loc_880C5178;
	// li r11,30
	ctx.r11.s64 = 30;
	// lwz r28,52(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r29,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r29.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// stw r10,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r10.u32);
	// ble cr6,0x880c5178
	if (!ctx.cr6.gt) goto loc_880C5178;
	// addi r27,r31,64
	ctx.r27.s64 = ctx.r31.s64 + 64;
loc_880C5100:
	// lwz r11,140(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r3,197
	ctx.r3.s64 = 197;
	// stw r28,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r28.u32);
	// lwz r4,4(r27)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// lwzu r5,8(r27)
	ea = 8 + ctx.r27.u32;
	ctx.r5.u64 = PPC_LOAD_U32(ea);
	ctx.r27.u32 = ea;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// bl 0x880958a0
	ctx.lr = 0x880C5128;
	sub_880958A0(ctx, base);
	// lwz r9,144(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// divw r11,r30,r9
	ctx.r11.s32 = ppc_divw(ctx.r30.s32, ctx.r9.s32);
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// cmpw cr6,r29,r9
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r9.s32, ctx.xer);
	// add r28,r11,r28
	ctx.r28.u64 = ctx.r11.u64 + ctx.r28.u64;
	// blt cr6,0x880c5100
	if (ctx.cr6.lt) goto loc_880C5100;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_880C514C:
	// cmpwi cr6,r11,30
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 30, ctx.xer);
	// bne cr6,0x880c5178
	if (!ctx.cr6.eq) goto loc_880C5178;
	// lwz r11,168(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 168);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r11.u32);
	// bgt 0x880c5178
	if (ctx.cr0.gt) goto loc_880C5178;
loc_880C5164:
	// lwz r11,272(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 272);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x88094220
	ctx.lr = 0x880C5178;
	sub_88094220(ctx, base);
loc_880C5178:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C5180"))) PPC_WEAK_FUNC(sub_880C5180);
PPC_FUNC_IMPL(__imp__sub_880C5180) {
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
	// lis r11,-30708
	ctx.r11.s64 = -2012479488;
	// li r4,276
	ctx.r4.s64 = 276;
	// addi r5,r11,20864
	ctx.r5.s64 = ctx.r11.s64 + 20864;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x880C51A8;
	sub_88094290(ctx, base);
	// li r5,276
	ctx.r5.s64 = 276;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,2304(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2304);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x880C51BC;
	sub_88073BD0(ctx, base);
	// stw r30,248(r31)
	PPC_STORE_U32(ctx.r31.u32 + 248, ctx.r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x881556a0
	ctx.lr = 0x880C51CC;
	sub_881556A0(ctx, base);
	// lis r10,-30708
	ctx.r10.s64 = -2012479488;
	// stw r3,272(r31)
	PPC_STORE_U32(ctx.r31.u32 + 272, ctx.r3.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r9,r10,18600
	ctx.r9.s64 = ctx.r10.s64 + 18600;
	// stw r31,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r31.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r9,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r9.u32);
	// lwz r8,272(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 272);
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// stw r5,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r5.u32);
	// lwz r9,272(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 272);
	// lwz r11,28(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880c521c
	if (ctx.cr6.eq) goto loc_880C521C;
loc_880C5204:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880c5318
	if (ctx.cr6.eq) goto loc_880C5318;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880c5204
	if (!ctx.cr6.eq) goto loc_880C5204;
loc_880C521C:
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
loc_880C5220:
	// li r9,24
	ctx.r9.s64 = 24;
	// stw r5,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r5.u32);
	// addi r8,r31,16
	ctx.r8.s64 = ctx.r31.s64 + 16;
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// li r5,100
	ctx.r5.s64 = 100;
	// stw r8,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r8.u32);
	// li r4,32
	ctx.r4.s64 = 32;
	// stw r9,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r9.u32);
	// li r3,256
	ctx.r3.s64 = 256;
	// stw r9,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r9.u32);
	// lis r8,-30597
	ctx.r8.s64 = -2005204992;
	// stw r9,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r9.u32);
	// addi r11,r30,120
	ctx.r11.s64 = ctx.r30.s64 + 120;
	// lwz r7,32(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r7,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r7.u32);
	// li r7,40
	ctx.r7.s64 = 40;
	// lwz r11,36(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// li r9,4
	ctx.r9.s64 = 4;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stw r5,168(r30)
	PPC_STORE_U32(ctx.r30.u32 + 168, ctx.r5.u32);
	// stw r4,204(r31)
	PPC_STORE_U32(ctx.r31.u32 + 204, ctx.r4.u32);
	// stw r3,212(r31)
	PPC_STORE_U32(ctx.r31.u32 + 212, ctx.r3.u32);
	// lwz r5,132(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 132);
	// lwz r4,2304(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 2304);
	// stw r4,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r4.u32);
	// lwz r3,132(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 132);
	// stw r3,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// lwz r11,136(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 136);
	// stw r11,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r11.u32);
	// lwz r5,140(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 140);
	// stw r5,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r5.u32);
	// lwz r11,-11984(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -11984);
	// sth r10,24(r31)
	PPC_STORE_U16(ctx.r31.u32 + 24, ctx.r10.u16);
	// sth r10,26(r31)
	PPC_STORE_U16(ctx.r31.u32 + 26, ctx.r10.u16);
	// sth r7,28(r31)
	PPC_STORE_U16(ctx.r31.u32 + 28, ctx.r7.u16);
	// sth r7,30(r31)
	PPC_STORE_U16(ctx.r31.u32 + 30, ctx.r7.u16);
	// stw r6,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r6.u32);
	// stw r6,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r6.u32);
	// stw r10,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r10.u32);
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// stw r9,144(r31)
	PPC_STORE_U32(ctx.r31.u32 + 144, ctx.r9.u32);
	// lwz r4,84(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// cmpwi cr6,r4,2
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 2, ctx.xer);
	// bne cr6,0x880c52dc
	if (!ctx.cr6.eq) goto loc_880C52DC;
	// li r11,6
	ctx.r11.s64 = 6;
	// stw r11,144(r31)
	PPC_STORE_U32(ctx.r31.u32 + 144, ctx.r11.u32);
loc_880C52DC:
	// lis r11,-30708
	ctx.r11.s64 = -2012479488;
	// lis r10,-30708
	ctx.r10.s64 = -2012479488;
	// lis r9,-30708
	ctx.r9.s64 = -2012479488;
	// addi r8,r11,19568
	ctx.r8.s64 = ctx.r11.s64 + 19568;
	// addi r7,r10,18760
	ctx.r7.s64 = ctx.r10.s64 + 18760;
	// addi r6,r9,18696
	ctx.r6.s64 = ctx.r9.s64 + 18696;
	// stw r8,64(r30)
	PPC_STORE_U32(ctx.r30.u32 + 64, ctx.r8.u32);
	// stw r7,68(r30)
	PPC_STORE_U32(ctx.r30.u32 + 68, ctx.r7.u32);
	// stw r6,84(r30)
	PPC_STORE_U32(ctx.r30.u32 + 84, ctx.r6.u32);
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
loc_880C5318:
	// lwz r10,24(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880c5328
	if (ctx.cr6.eq) goto loc_880C5328;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_880C5328:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x880c5220
	goto loc_880C5220;
}

__attribute__((alias("__imp__sub_880C5330"))) PPC_WEAK_FUNC(sub_880C5330);
PPC_FUNC_IMPL(__imp__sub_880C5330) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// li r10,8
	ctx.r10.s64 = 8;
	// addi r11,r11,-18876
	ctx.r11.s64 = ctx.r11.s64 + -18876;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_880C5348:
	// stbu r9,1(r11)
	ea = 1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r9.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x880c5348
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_880C5348;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880C5354"))) PPC_WEAK_FUNC(sub_880C5354);
PPC_FUNC_IMPL(__imp__sub_880C5354) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C5358"))) PPC_WEAK_FUNC(sub_880C5358);
PPC_FUNC_IMPL(__imp__sub_880C5358) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// lhz r10,5836(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 5836);
	// addi r9,r11,-18876
	ctx.r9.s64 = ctx.r11.s64 + -18876;
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
loc_880C5384:
	// lhz r9,92(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 92);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x880c53a0
	if (ctx.cr6.eq) goto loc_880C53A0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880c5384
	if (!ctx.cr6.eq) goto loc_880C5384;
	// blr 
	return;
loc_880C53A0:
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r10,96(r11)
	PPC_STORE_U16(ctx.r11.u32 + 96, ctx.r10.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880C53AC"))) PPC_WEAK_FUNC(sub_880C53AC);
PPC_FUNC_IMPL(__imp__sub_880C53AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C53B0"))) PPC_WEAK_FUNC(sub_880C53B0);
PPC_FUNC_IMPL(__imp__sub_880C53B0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// lhz r10,5836(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 5836);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwz r11,-18876(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -18876);
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
loc_880C53D8:
	// lhz r9,92(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 92);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x880c53f4
	if (ctx.cr6.eq) goto loc_880C53F4;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880c53d8
	if (!ctx.cr6.eq) goto loc_880C53D8;
	// blr 
	return;
loc_880C53F4:
	// sth r4,96(r11)
	PPC_STORE_U16(ctx.r11.u32 + 96, ctx.r4.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880C53FC"))) PPC_WEAK_FUNC(sub_880C53FC);
PPC_FUNC_IMPL(__imp__sub_880C53FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C5400"))) PPC_WEAK_FUNC(sub_880C5400);
PPC_FUNC_IMPL(__imp__sub_880C5400) {
	PPC_FUNC_PROLOGUE();
	// srawi r11,r3,2
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 2;
	// li r10,1
	ctx.r10.s64 = 1;
	// clrlwi r11,r11,25
	ctx.r11.u64 = ctx.r11.u32 & 0x7F;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r11,48
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 48, ctx.xer);
	// blt cr6,0x880c5448
	if (ctx.cr6.lt) goto loc_880C5448;
	// cmpwi cr6,r11,64
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 64, ctx.xer);
	// bgt cr6,0x880c5434
	if (ctx.cr6.gt) goto loc_880C5434;
	// subfic r11,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r11.s64 = 64 - ctx.r11.s64;
	// stw r9,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r9.u32);
	// stw r10,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r10.u32);
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// blr 
	return;
loc_880C5434:
	// cmpwi cr6,r11,80
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 80, ctx.xer);
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r11,r11,-64
	ctx.r11.s64 = ctx.r11.s64 + -64;
	// ble cr6,0x880c544c
	if (!ctx.cr6.gt) goto loc_880C544C;
loc_880C5448:
	// li r11,16
	ctx.r11.s64 = 16;
loc_880C544C:
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// stw r9,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r9.u32);
	// stw r10,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880C545C"))) PPC_WEAK_FUNC(sub_880C545C);
PPC_FUNC_IMPL(__imp__sub_880C545C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C5460"))) PPC_WEAK_FUNC(sub_880C5460);
PPC_FUNC_IMPL(__imp__sub_880C5460) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071120
	ctx.lr = 0x880C5468;
	__savegprlr_14(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r21,2304(r3)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r10,184(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// lwz r11,168(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// lwz r26,4(r6)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r20,0(r6)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r10,0(r21)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r21.u32 + 0);
	// lwz r9,8(r21)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r21.u32 + 8);
	// addi r28,r11,2
	ctx.r28.s64 = ctx.r11.s64 + 2;
	// lwz r8,12(r21)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r21.u32 + 12);
	// addi r27,r28,-3
	ctx.r27.s64 = ctx.r28.s64 + -3;
	// stw r3,276(r1)
	PPC_STORE_U32(ctx.r1.u32 + 276, ctx.r3.u32);
	// li r3,17642
	ctx.r3.s64 = 17642;
	// stw r26,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r26.u32);
	// lwz r7,2300(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2300);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// stw r28,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r28.u32);
	// lwz r5,156(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 156);
	// lwz r4,160(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 160);
	// subf r16,r5,r9
	ctx.r16.s64 = ctx.r9.s64 - ctx.r5.s64;
	// subf r22,r4,r8
	ctx.r22.s64 = ctx.r8.s64 - ctx.r4.s64;
	// stw r16,8744(r21)
	PPC_STORE_U32(ctx.r21.u32 + 8744, ctx.r16.u32);
	// addis r4,r16,20
	ctx.r4.s64 = ctx.r16.s64 + 1310720;
	// stw r22,8748(r21)
	PPC_STORE_U32(ctx.r21.u32 + 8748, ctx.r22.u32);
	// addis r5,r22,-16
	ctx.r5.s64 = ctx.r22.s64 + -1048576;
	// bl 0x881538c0
	ctx.lr = 0x880C54D4;
	sub_881538C0(ctx, base);
	// lis r25,-30597
	ctx.r25.s64 = -2005204992;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r25,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r25.u32);
	// beq cr6,0x880c54fc
	if (ctx.cr6.eq) goto loc_880C54FC;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-11932(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + -11932);
	// oris r9,r10,518
	ctx.r9.u64 = ctx.r10.u64 | 33947648;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r11,-11932(r25)
	PPC_STORE_U32(ctx.r25.u32 + -11932, ctx.r11.u32);
loc_880C54FC:
	// lis r11,-30667
	ctx.r11.s64 = -2009792512;
	// lwz r10,8072(r21)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r21.u32 + 8072);
	// li r29,1
	ctx.r29.s64 = 1;
	// addi r11,r11,7312
	ctx.r11.s64 = ctx.r11.s64 + 7312;
	// rlwinm r9,r10,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r8,r11,4
	ctx.r8.s64 = ctx.r11.s64 + 4;
	// lwzx r11,r9,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// lwzx r9,r9,r8
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x880c5528
	if (!ctx.cr6.eq) goto loc_880C5528;
	// li r29,-1
	ctx.r29.s64 = -1;
loc_880C5528:
	// lis r10,-30681
	ctx.r10.s64 = -2010710016;
	// lwz r8,3584(r21)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r21.u32 + 3584);
	// rlwinm r6,r11,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r31,r10,-19456
	ctx.r31.s64 = ctx.r10.s64 + -19456;
	// li r18,10
	ctx.r18.s64 = 10;
	// addi r10,r31,-21492
	ctx.r10.s64 = ctx.r31.s64 + -21492;
	// addi r4,r31,-21492
	ctx.r4.s64 = ctx.r31.s64 + -21492;
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// lwz r10,-24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -24);
	// divw r30,r8,r18
	ctx.r30.s32 = ppc_divw(ctx.r8.s32, ctx.r18.s32);
	// lwz r5,-20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + -20);
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// mr r7,r20
	ctx.r7.u64 = ctx.r20.u64;
	// lbzx r4,r6,r4
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r4.u32);
	// lbzx r3,r6,r3
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r3.u32);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// extsb r4,r4
	ctx.r4.s64 = ctx.r4.s8;
	// extsb r3,r3
	ctx.r3.s64 = ctx.r3.s8;
	// add r10,r4,r10
	ctx.r10.u64 = ctx.r4.u64 + ctx.r10.u64;
	// add r5,r3,r5
	ctx.r5.u64 = ctx.r3.u64 + ctx.r5.u64;
	// mullw r4,r10,r29
	ctx.r4.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r29.s32);
	// rlwinm r10,r5,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r5,r4,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + ctx.r30.u64;
	// add r30,r5,r16
	ctx.r30.u64 = ctx.r5.u64 + ctx.r16.u64;
	// add r29,r10,r22
	ctx.r29.u64 = ctx.r10.u64 + ctx.r22.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r3,r11,17471
	ctx.r3.s64 = ctx.r11.s64 + 17471;
	// bl 0x880a51a0
	ctx.lr = 0x880C55A0;
	sub_880A51A0(ctx, base);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addis r4,r30,8
	ctx.r4.s64 = ctx.r30.s64 + 524288;
	// li r3,17648
	ctx.r3.s64 = 17648;
	// bl 0x881538c0
	ctx.lr = 0x880C55B4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c55d8
	if (ctx.cr6.eq) goto loc_880C55D8;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-11932(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + -11932);
	// oris r9,r10,518
	ctx.r9.u64 = ctx.r10.u64 | 33947648;
	// addi r23,r11,1
	ctx.r23.s64 = ctx.r11.s64 + 1;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r23,-11932(r25)
	PPC_STORE_U32(ctx.r25.u32 + -11932, ctx.r23.u32);
	// b 0x880c55dc
	goto loc_880C55DC;
loc_880C55D8:
	// lwz r23,-11932(r25)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r25.u32 + -11932);
loc_880C55DC:
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// li r26,-1
	ctx.r26.s64 = -1;
	// li r27,0
	ctx.r27.s64 = 0;
	// addi r19,r21,1040
	ctx.r19.s64 = ctx.r21.s64 + 1040;
	// addi r15,r21,76
	ctx.r15.s64 = ctx.r21.s64 + 76;
	// addi r25,r21,7484
	ctx.r25.s64 = ctx.r21.s64 + 7484;
	// addi r14,r11,9552
	ctx.r14.s64 = ctx.r11.s64 + 9552;
	// b 0x880c5604
	goto loc_880C5604;
loc_880C55FC:
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r23,-11932(r11)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11932);
loc_880C5604:
	// lwz r10,0(r25)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r9,64(r21)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r21.u32 + 64);
	// srawi r8,r10,5
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1F) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 5;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// addze r11,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r11.s64 = temp.s64;
	// srawi r7,r11,5
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1F) != 0);
	ctx.r7.s64 = ctx.r11.s32 >> 5;
	// addze r6,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r6.s64 = temp.s64;
	// srawi r5,r10,5
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1F) != 0);
	ctx.r5.s64 = ctx.r10.s32 >> 5;
	// rlwinm r4,r6,5,0,26
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFFE0;
	// addze r3,r5
	temp.s64 = ctx.r5.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r3.s64 = temp.s64;
	// subf r28,r4,r11
	ctx.r28.s64 = ctx.r11.s64 - ctx.r4.s64;
	// rlwinm r11,r3,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 5) & 0xFFFFFFE0;
	// subf r17,r11,r10
	ctx.r17.s64 = ctx.r10.s64 - ctx.r11.s64;
	// li r11,31
	ctx.r11.s64 = 31;
	// bge cr6,0x880c5644
	if (!ctx.cr6.lt) goto loc_880C5644;
	// li r11,17
	ctx.r11.s64 = 17;
loc_880C5644:
	// cmpw cr6,r28,r11
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x880c566c
	if (!ctx.cr6.eq) goto loc_880C566C;
	// lwz r11,0(r15)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880c5664
	if (!ctx.cr6.eq) goto loc_880C5664;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// lwz r3,276(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 276);
	// bl 0x880c7cb8
	ctx.lr = 0x880C5664;
	sub_880C7CB8(ctx, base);
loc_880C5664:
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x880c5670
	goto loc_880C5670;
loc_880C566C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_880C5670:
	// stw r11,0(r15)
	PPC_STORE_U32(ctx.r15.u32 + 0, ctx.r11.u32);
	// addi r11,r26,1
	ctx.r11.s64 = ctx.r26.s64 + 1;
	// mr r9,r22
	ctx.r9.u64 = ctx.r22.u64;
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// cmpwi cr6,r27,2
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 2, ctx.xer);
	// rlwinm r24,r10,27,31,31
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blt cr6,0x880c5690
	if (ctx.cr6.lt) goto loc_880C5690;
	// addis r9,r22,76
	ctx.r9.s64 = ctx.r22.s64 + 4980736;
loc_880C5690:
	// lwz r11,-64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -64);
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// lwz r10,-60(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -60);
	// mullw r11,r11,r26
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r26.s32);
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r30,r11,r16
	ctx.r30.u64 = ctx.r11.u64 + ctx.r16.u64;
	// add r29,r10,r9
	ctx.r29.u64 = ctx.r10.u64 + ctx.r9.u64;
	// beq cr6,0x880c56bc
	if (ctx.cr6.eq) goto loc_880C56BC;
	// cmpwi cr6,r27,2
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 2, ctx.xer);
	// bne cr6,0x880c573c
	if (!ctx.cr6.eq) goto loc_880C573C;
loc_880C56BC:
	// lwz r11,0(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r28,16
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 16, ctx.xer);
	// rlwinm r10,r11,9,0,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 9) & 0xFFFFFE00;
	// srawi r8,r10,10
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3FF) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 10;
	// addze r10,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r10.s64 = temp.s64;
	// addi r7,r10,128
	ctx.r7.s64 = ctx.r10.s64 + 128;
	// rlwinm r6,r7,2,21,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x7FC;
	// lwzx r11,r6,r14
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r14.u32);
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r5,r11,r8
	ctx.r5.u64 = ctx.r11.u64 + ctx.r8.u64;
	// rlwinm r11,r5,6,0,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 6) & 0xFFFFFFC0;
	// ble cr6,0x880c56fc
	if (!ctx.cr6.gt) goto loc_880C56FC;
	// rlwinm r10,r10,2,21,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0x7FC;
	// lwzx r9,r10,r14
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r14.u32);
	// rlwinm r9,r9,6,0,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0xFFFFFFC0;
loc_880C56FC:
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// subf r8,r11,r29
	ctx.r8.s64 = ctx.r29.s64 - ctx.r11.s64;
	// subf r7,r9,r30
	ctx.r7.s64 = ctx.r30.s64 - ctx.r9.s64;
	// addi r6,r10,-3
	ctx.r6.s64 = ctx.r10.s64 + -3;
	// addis r5,r8,4
	ctx.r5.s64 = ctx.r8.s64 + 262144;
	// addis r4,r7,8
	ctx.r4.s64 = ctx.r7.s64 + 524288;
	// li r3,17645
	ctx.r3.s64 = 17645;
	// bl 0x881538c0
	ctx.lr = 0x880C571C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c573c
	if (ctx.cr6.eq) goto loc_880C573C;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r23,r23,1
	ctx.r23.s64 = ctx.r23.s64 + 1;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// oris r9,r11,518
	ctx.r9.u64 = ctx.r11.u64 | 33947648;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r23,-11932(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11932, ctx.r23.u32);
loc_880C573C:
	// cmpwi cr6,r27,1
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 1, ctx.xer);
	// beq cr6,0x880c574c
	if (ctx.cr6.eq) goto loc_880C574C;
	// cmpwi cr6,r27,3
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 3, ctx.xer);
	// bne cr6,0x880c57cc
	if (!ctx.cr6.eq) goto loc_880C57CC;
loc_880C574C:
	// lwz r11,0(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r28,16
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 16, ctx.xer);
	// rlwinm r10,r11,9,0,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 9) & 0xFFFFFE00;
	// srawi r8,r10,10
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3FF) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 10;
	// addze r10,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r10.s64 = temp.s64;
	// addi r7,r10,128
	ctx.r7.s64 = ctx.r10.s64 + 128;
	// rlwinm r6,r7,2,21,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x7FC;
	// lwzx r11,r6,r14
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r14.u32);
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r5,r11,r8
	ctx.r5.u64 = ctx.r11.u64 + ctx.r8.u64;
	// rlwinm r11,r5,6,0,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 6) & 0xFFFFFFC0;
	// ble cr6,0x880c578c
	if (!ctx.cr6.gt) goto loc_880C578C;
	// rlwinm r10,r10,2,21,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0x7FC;
	// lwzx r9,r10,r14
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r14.u32);
	// rlwinm r9,r9,6,0,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0xFFFFFFC0;
loc_880C578C:
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// subf r8,r11,r29
	ctx.r8.s64 = ctx.r29.s64 - ctx.r11.s64;
	// subf r7,r9,r30
	ctx.r7.s64 = ctx.r30.s64 - ctx.r9.s64;
	// addi r6,r10,-3
	ctx.r6.s64 = ctx.r10.s64 + -3;
	// addis r5,r8,2
	ctx.r5.s64 = ctx.r8.s64 + 131072;
	// addis r4,r7,8
	ctx.r4.s64 = ctx.r7.s64 + 524288;
	// li r3,17647
	ctx.r3.s64 = 17647;
	// bl 0x881538c0
	ctx.lr = 0x880C57AC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c57cc
	if (ctx.cr6.eq) goto loc_880C57CC;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r11,r23,1
	ctx.r11.s64 = ctx.r23.s64 + 1;
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// oris r8,r10,518
	ctx.r8.u64 = ctx.r10.u64 | 33947648;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stw r11,-11932(r9)
	PPC_STORE_U32(ctx.r9.u32 + -11932, ctx.r11.u32);
loc_880C57CC:
	// rlwinm r10,r28,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r23,88(r1)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// addi r7,r31,96
	ctx.r7.s64 = ctx.r31.s64 + 96;
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r11,r31,96
	ctx.r11.s64 = ctx.r31.s64 + 96;
	// addi r6,r23,-2
	ctx.r6.s64 = ctx.r23.s64 + -2;
	// addi r5,r11,2
	ctx.r5.s64 = ctx.r11.s64 + 2;
	// mr r9,r24
	ctx.r9.u64 = ctx.r24.u64;
	// lhzx r4,r10,r7
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r7.u32);
	// mr r7,r20
	ctx.r7.u64 = ctx.r20.u64;
	// addi r3,r28,17341
	ctx.r3.s64 = ctx.r28.s64 + 17341;
	// extsh r11,r4
	ctx.r11.s64 = ctx.r4.s16;
	// lhzx r10,r10,r5
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r5.u32);
	// mullw r5,r11,r26
	ctx.r5.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r26.s32);
	// rlwinm r11,r5,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// rotlwi r10,r10,16
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 16);
	// add r4,r11,r30
	ctx.r4.u64 = ctx.r11.u64 + ctx.r30.u64;
	// add r5,r10,r29
	ctx.r5.u64 = ctx.r10.u64 + ctx.r29.u64;
	// stw r4,12(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12, ctx.r4.u32);
	// stw r5,16(r25)
	PPC_STORE_U32(ctx.r25.u32 + 16, ctx.r5.u32);
	// bl 0x880a51a0
	ctx.lr = 0x880C5820;
	sub_880A51A0(ctx, base);
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// cmpwi cr6,r27,2
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 2, ctx.xer);
	// blt cr6,0x880c5830
	if (ctx.cr6.lt) goto loc_880C5830;
	// addis r11,r22,76
	ctx.r11.s64 = ctx.r22.s64 + 4980736;
loc_880C5830:
	// addi r8,r31,288
	ctx.r8.s64 = ctx.r31.s64 + 288;
	// lwz r10,-44(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -44);
	// rlwinm r30,r28,1,0,30
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,-48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + -48);
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// lwz r29,84(r1)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r3,r28,17405
	ctx.r3.s64 = ctx.r28.s64 + 17405;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmpwi cr6,r17,0
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 0, ctx.xer);
	// lbzx r7,r30,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r8.u32);
	// extsb r11,r7
	ctx.r11.s64 = ctx.r7.s8;
	// mr r7,r20
	ctx.r7.u64 = ctx.r20.u64;
	// add r6,r11,r9
	ctx.r6.u64 = ctx.r11.u64 + ctx.r9.u64;
	// mullw r5,r6,r26
	ctx.r5.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r26.s32);
	// rlwinm r11,r5,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// add r4,r11,r16
	ctx.r4.u64 = ctx.r11.u64 + ctx.r16.u64;
	// addi r11,r31,288
	ctx.r11.s64 = ctx.r31.s64 + 288;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lbzx r9,r30,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r11.u32);
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// mr r9,r24
	ctx.r9.u64 = ctx.r24.u64;
	// rlwinm r11,r8,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// lwz r8,1488(r19)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r19.u32 + 1488);
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r11,1484(r19)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r19.u32 + 1484);
	// divw r10,r11,r18
	ctx.r10.s32 = ppc_divw(ctx.r11.s32, ctx.r18.s32);
	// divw r11,r8,r18
	ctx.r11.s32 = ppc_divw(ctx.r8.s32, ctx.r18.s32);
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// add r5,r11,r5
	ctx.r5.u64 = ctx.r11.u64 + ctx.r5.u64;
	// add r4,r10,r4
	ctx.r4.u64 = ctx.r10.u64 + ctx.r4.u64;
	// bl 0x880a51a0
	ctx.lr = 0x880C58B0;
	sub_880A51A0(ctx, base);
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// cmpwi cr6,r27,2
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 2, ctx.xer);
	// blt cr6,0x880c58c0
	if (ctx.cr6.lt) goto loc_880C58C0;
	// addis r11,r22,76
	ctx.r11.s64 = ctx.r22.s64 + 4980736;
loc_880C58C0:
	// addi r8,r31,224
	ctx.r8.s64 = ctx.r31.s64 + 224;
	// lwz r10,-52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -52);
	// lwz r9,-56(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + -56);
	// addi r3,r28,17373
	ctx.r3.s64 = ctx.r28.s64 + 17373;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// cmpwi cr6,r17,0
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 0, ctx.xer);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lbzx r7,r30,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r8.u32);
	// extsb r11,r7
	ctx.r11.s64 = ctx.r7.s8;
	// mr r7,r20
	ctx.r7.u64 = ctx.r20.u64;
	// add r6,r11,r9
	ctx.r6.u64 = ctx.r11.u64 + ctx.r9.u64;
	// mullw r5,r6,r26
	ctx.r5.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r26.s32);
	// rlwinm r11,r5,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// add r4,r11,r16
	ctx.r4.u64 = ctx.r11.u64 + ctx.r16.u64;
	// addi r11,r31,224
	ctx.r11.s64 = ctx.r31.s64 + 224;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lbzx r9,r30,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r11.u32);
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// mr r9,r24
	ctx.r9.u64 = ctx.r24.u64;
	// rlwinm r11,r8,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,284(r19)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r19.u32 + 284);
	// lwzu r11,288(r19)
	ea = 288 + ctx.r19.u32;
	ctx.r11.u64 = PPC_LOAD_U32(ea);
	ctx.r19.u32 = ea;
	// divw r10,r10,r18
	ctx.r10.s32 = ppc_divw(ctx.r10.s32, ctx.r18.s32);
	// divw r11,r11,r18
	ctx.r11.s32 = ppc_divw(ctx.r11.s32, ctx.r18.s32);
	// add r4,r10,r4
	ctx.r4.u64 = ctx.r10.u64 + ctx.r4.u64;
	// add r5,r11,r5
	ctx.r5.u64 = ctx.r11.u64 + ctx.r5.u64;
	// bl 0x880a51a0
	ctx.lr = 0x880C5938;
	sub_880A51A0(ctx, base);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// neg r26,r26
	ctx.r26.s64 = -ctx.r26.s64;
	// addi r15,r15,4
	ctx.r15.s64 = ctx.r15.s64 + 4;
	// addi r25,r25,84
	ctx.r25.s64 = ctx.r25.s64 + 84;
	// cmpwi cr6,r27,4
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 4, ctx.xer);
	// blt cr6,0x880c55fc
	if (ctx.cr6.lt) goto loc_880C55FC;
	// lwz r10,-192(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -192);
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// lwz r11,-188(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -188);
	// li r3,17275
	ctx.r3.s64 = 17275;
	// lwz r9,128(r21)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r21.u32 + 128);
	// rlwinm r8,r10,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// divw r10,r9,r18
	ctx.r10.s32 = ppc_divw(ctx.r9.s32, ctx.r18.s32);
	// subf r4,r8,r16
	ctx.r4.s64 = ctx.r16.s64 - ctx.r8.s64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r5,r11,r22
	ctx.r5.u64 = ctx.r11.u64 + ctx.r22.u64;
	// bl 0x881538c0
	ctx.lr = 0x880C5980;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x880c59d8
	if (ctx.cr6.eq) goto loc_880C59D8;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c5998
	if (ctx.cr6.eq) goto loc_880C5998;
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C5998:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x880c59d8
	if (ctx.cr6.eq) goto loc_880C59D8;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// lwz r19,80(r1)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// clrlwi r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c59f0
	if (ctx.cr6.eq) goto loc_880C59F0;
	// lis r11,545
	ctx.r11.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwimi r11,r10,8,16,23
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 8) & 0xFF00) | (ctx.r11.u64 & 0xFFFFFFFFFFFF00FF);
	// or r8,r11,r9
	ctx.r8.u64 = ctx.r11.u64 | ctx.r9.u64;
	// lwz r11,-11932(r19)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r19.u32 + -11932);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stw r7,-11932(r19)
	PPC_STORE_U32(ctx.r19.u32 + -11932, ctx.r7.u32);
	// b 0x880c59dc
	goto loc_880C59DC;
loc_880C59D8:
	// lwz r19,80(r1)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_880C59DC:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c59f0
	if (ctx.cr6.eq) goto loc_880C59F0;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// oris r10,r11,1024
	ctx.r10.u64 = ctx.r11.u64 | 67108864;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_880C59F0:
	// lwz r9,128(r21)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r21.u32 + 128);
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// lwz r11,-188(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -188);
	// li r3,17275
	ctx.r3.s64 = 17275;
	// lwz r10,-192(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -192);
	// divw r9,r9,r18
	ctx.r9.s32 = ppc_divw(ctx.r9.s32, ctx.r18.s32);
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r4,r10,r16
	ctx.r4.u64 = ctx.r10.u64 + ctx.r16.u64;
	// add r5,r11,r22
	ctx.r5.u64 = ctx.r11.u64 + ctx.r22.u64;
	// bl 0x881538c0
	ctx.lr = 0x880C5A20;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x880c5a70
	if (ctx.cr6.eq) goto loc_880C5A70;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c5a38
	if (ctx.cr6.eq) goto loc_880C5A38;
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C5A38:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x880c5a70
	if (ctx.cr6.eq) goto loc_880C5A70;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c5a70
	if (ctx.cr6.eq) goto loc_880C5A70;
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-11932(r19)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r19.u32 + -11932);
	// rlwimi r9,r10,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// or r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 | ctx.r8.u64;
	// stw r11,-11932(r19)
	PPC_STORE_U32(ctx.r19.u32 + -11932, ctx.r11.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
loc_880C5A70:
	// lwz r11,7952(r21)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r21.u32 + 7952);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// srawi r10,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 2;
	// clrlwi r11,r10,25
	ctx.r11.u64 = ctx.r10.u32 & 0x7F;
	// cmpwi cr6,r11,48
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 48, ctx.xer);
	// blt cr6,0x880c5ab0
	if (ctx.cr6.lt) goto loc_880C5AB0;
	// cmpwi cr6,r11,64
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 64, ctx.xer);
	// bgt cr6,0x880c5a9c
	if (ctx.cr6.gt) goto loc_880C5A9C;
	// subfic r10,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r10.s64 = 64 - ctx.r11.s64;
	// b 0x880c5ab4
	goto loc_880C5AB4;
loc_880C5A9C:
	// li r4,-1
	ctx.r4.s64 = -1;
	// li r9,1
	ctx.r9.s64 = 1;
	// cmpwi cr6,r11,80
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 80, ctx.xer);
	// addi r10,r11,-64
	ctx.r10.s64 = ctx.r11.s64 + -64;
	// ble cr6,0x880c5ab4
	if (!ctx.cr6.gt) goto loc_880C5AB4;
loc_880C5AB0:
	// li r10,16
	ctx.r10.s64 = 16;
loc_880C5AB4:
	// rlwinm r3,r10,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r6,4396(r21)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r21.u32 + 4396);
	// addi r30,r31,-22628
	ctx.r30.s64 = ctx.r31.s64 + -22628;
	// lwz r28,4400(r21)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r21.u32 + 4400);
	// addi r7,r31,-22628
	ctx.r7.s64 = ctx.r31.s64 + -22628;
	// lwz r11,-32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -32);
	// li r5,30
	ctx.r5.s64 = 30;
	// lwz r8,-28(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + -28);
	// addi r27,r7,1
	ctx.r27.s64 = ctx.r7.s64 + 1;
	// divw r6,r6,r5
	ctx.r6.s32 = ppc_divw(ctx.r6.s32, ctx.r5.s32);
	// lbzx r30,r3,r30
	ctx.r30.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r30.u32);
	// divw r7,r28,r5
	ctx.r7.s32 = ppc_divw(ctx.r28.s32, ctx.r5.s32);
	// extsb r5,r30
	ctx.r5.s64 = ctx.r30.s8;
	// lbzx r30,r3,r27
	ctx.r30.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r27.u32);
	// addi r3,r10,17454
	ctx.r3.s64 = ctx.r10.s64 + 17454;
	// add r5,r5,r11
	ctx.r5.u64 = ctx.r5.u64 + ctx.r11.u64;
	// extsb r11,r30
	ctx.r11.s64 = ctx.r30.s8;
	// mullw r4,r5,r4
	ctx.r4.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r4.s32);
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// rlwinm r8,r4,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// add r4,r8,r16
	ctx.r4.u64 = ctx.r8.u64 + ctx.r16.u64;
	// add r11,r11,r22
	ctx.r11.u64 = ctx.r11.u64 + ctx.r22.u64;
	// stw r4,7916(r21)
	PPC_STORE_U32(ctx.r21.u32 + 7916, ctx.r4.u32);
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// stw r11,7920(r21)
	PPC_STORE_U32(ctx.r21.u32 + 7920, ctx.r11.u32);
	// mr r7,r20
	ctx.r7.u64 = ctx.r20.u64;
	// lwz r10,416(r21)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r21.u32 + 416);
	// divw r5,r10,r18
	ctx.r5.s32 = ppc_divw(ctx.r10.s32, ctx.r18.s32);
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// add r5,r5,r11
	ctx.r5.u64 = ctx.r5.u64 + ctx.r11.u64;
	// bl 0x880a51a0
	ctx.lr = 0x880C5B3C;
	sub_880A51A0(ctx, base);
	// lwz r8,7868(r21)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r21.u32 + 7868);
	// li r10,1
	ctx.r10.s64 = 1;
	// srawi r7,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 2;
	// li r9,0
	ctx.r9.s64 = 0;
	// clrlwi r11,r7,25
	ctx.r11.u64 = ctx.r7.u32 & 0x7F;
	// cmpwi cr6,r11,48
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 48, ctx.xer);
	// blt cr6,0x880c5b7c
	if (ctx.cr6.lt) goto loc_880C5B7C;
	// cmpwi cr6,r11,64
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 64, ctx.xer);
	// bgt cr6,0x880c5b68
	if (ctx.cr6.gt) goto loc_880C5B68;
	// subfic r3,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r3.s64 = 64 - ctx.r11.s64;
	// b 0x880c5b80
	goto loc_880C5B80;
loc_880C5B68:
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r9,1
	ctx.r9.s64 = 1;
	// cmpwi cr6,r11,80
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 80, ctx.xer);
	// addi r3,r11,-64
	ctx.r3.s64 = ctx.r11.s64 + -64;
	// ble cr6,0x880c5b80
	if (!ctx.cr6.gt) goto loc_880C5B80;
loc_880C5B7C:
	// li r3,16
	ctx.r3.s64 = 16;
loc_880C5B80:
	// lwz r11,-40(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -40);
	// li r6,20
	ctx.r6.s64 = 20;
	// lwz r4,4304(r21)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r21.u32 + 4304);
	// addi r3,r3,17437
	ctx.r3.s64 = ctx.r3.s64 + 17437;
	// mullw r5,r10,r11
	ctx.r5.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// lwz r11,-36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -36);
	// lwz r7,4300(r21)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r21.u32 + 4300);
	// rlwinm r8,r11,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// divw r7,r7,r6
	ctx.r7.s32 = ppc_divw(ctx.r7.s32, ctx.r6.s32);
	// divw r11,r4,r6
	ctx.r11.s32 = ppc_divw(ctx.r4.s32, ctx.r6.s32);
	// rlwinm r10,r5,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// add r11,r11,r22
	ctx.r11.u64 = ctx.r11.u64 + ctx.r22.u64;
	// add r4,r10,r16
	ctx.r4.u64 = ctx.r10.u64 + ctx.r16.u64;
	// stw r11,7836(r21)
	PPC_STORE_U32(ctx.r21.u32 + 7836, ctx.r11.u32);
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// stw r4,7832(r21)
	PPC_STORE_U32(ctx.r21.u32 + 7832, ctx.r4.u32);
	// mr r7,r20
	ctx.r7.u64 = ctx.r20.u64;
	// lwz r10,704(r21)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r21.u32 + 704);
	// divw r10,r10,r18
	ctx.r10.s32 = ppc_divw(ctx.r10.s32, ctx.r18.s32);
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bl 0x880a51a0
	ctx.lr = 0x880C5BE0;
	sub_880A51A0(ctx, base);
	// lwz r11,8052(r21)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r21.u32 + 8052);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x880c5ee8
	if (ctx.cr6.lt) goto loc_880C5EE8;
	// bne cr6,0x880c5cd4
	if (!ctx.cr6.eq) goto loc_880C5CD4;
	// lwz r11,8036(r21)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r21.u32 + 8036);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// srawi r10,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 2;
	// clrlwi r11,r10,25
	ctx.r11.u64 = ctx.r10.u32 & 0x7F;
	// cmpwi cr6,r11,48
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 48, ctx.xer);
	// blt cr6,0x880c5c30
	if (ctx.cr6.lt) goto loc_880C5C30;
	// cmpwi cr6,r11,64
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 64, ctx.xer);
	// bgt cr6,0x880c5c1c
	if (ctx.cr6.gt) goto loc_880C5C1C;
	// subfic r11,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r11.s64 = 64 - ctx.r11.s64;
	// b 0x880c5c34
	goto loc_880C5C34;
loc_880C5C1C:
	// cmpwi cr6,r11,80
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 80, ctx.xer);
	// li r8,-1
	ctx.r8.s64 = -1;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r11,r11,-64
	ctx.r11.s64 = ctx.r11.s64 + -64;
	// ble cr6,0x880c5c34
	if (!ctx.cr6.gt) goto loc_880C5C34;
loc_880C5C30:
	// li r11,16
	ctx.r11.s64 = 16;
loc_880C5C34:
	// addi r10,r11,7
	ctx.r10.s64 = ctx.r11.s64 + 7;
	// lwz r5,4156(r21)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r21.u32 + 4156);
	// addi r3,r31,48
	ctx.r3.s64 = ctx.r31.s64 + 48;
	// lwz r30,4160(r21)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r21.u32 + 4160);
	// rlwinm r28,r10,1,0,30
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r11,-72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -72);
	// addi r6,r31,48
	ctx.r6.s64 = ctx.r31.s64 + 48;
	// lwz r7,-68(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + -68);
	// li r4,9
	ctx.r4.s64 = 9;
	// addi r27,r6,1
	ctx.r27.s64 = ctx.r6.s64 + 1;
	// divw r5,r5,r4
	ctx.r5.s32 = ppc_divw(ctx.r5.s32, ctx.r4.s32);
	// lbzx r3,r28,r3
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r28.u32 + ctx.r3.u32);
	// divw r6,r30,r4
	ctx.r6.s32 = ppc_divw(ctx.r30.s32, ctx.r4.s32);
	// cmpwi cr6,r8,-1
	ctx.cr6.compare<int32_t>(ctx.r8.s32, -1, ctx.xer);
	// extsb r4,r3
	ctx.r4.s64 = ctx.r3.s8;
	// lbzx r3,r28,r27
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r28.u32 + ctx.r27.u32);
	// add r4,r4,r11
	ctx.r4.u64 = ctx.r4.u64 + ctx.r11.u64;
	// extsb r11,r3
	ctx.r11.s64 = ctx.r3.s8;
	// mullw r3,r4,r8
	ctx.r3.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r8.s32);
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// rlwinm r7,r3,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// add r7,r7,r5
	ctx.r7.u64 = ctx.r7.u64 + ctx.r5.u64;
	// add r11,r11,r6
	ctx.r11.u64 = ctx.r11.u64 + ctx.r6.u64;
	// add r4,r7,r16
	ctx.r4.u64 = ctx.r7.u64 + ctx.r16.u64;
	// add r11,r11,r22
	ctx.r11.u64 = ctx.r11.u64 + ctx.r22.u64;
	// stw r4,8000(r21)
	PPC_STORE_U32(ctx.r21.u32 + 8000, ctx.r4.u32);
	// stw r11,8004(r21)
	PPC_STORE_U32(ctx.r21.u32 + 8004, ctx.r11.u32);
	// lwz r8,992(r21)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r21.u32 + 992);
	// divw r8,r8,r18
	ctx.r8.s32 = ppc_divw(ctx.r8.s32, ctx.r18.s32);
	// add r5,r8,r11
	ctx.r5.u64 = ctx.r8.u64 + ctx.r11.u64;
	// stw r4,8888(r21)
	PPC_STORE_U32(ctx.r21.u32 + 8888, ctx.r4.u32);
	// stw r5,8892(r21)
	PPC_STORE_U32(ctx.r21.u32 + 8892, ctx.r5.u32);
	// bne cr6,0x880c5cc0
	if (!ctx.cr6.eq) goto loc_880C5CC0;
	// addis r4,r4,-1
	ctx.r4.s64 = ctx.r4.s64 + -65536;
loc_880C5CC0:
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// mr r7,r20
	ctx.r7.u64 = ctx.r20.u64;
	// addi r6,r23,1
	ctx.r6.s64 = ctx.r23.s64 + 1;
	// addi r3,r10,17279
	ctx.r3.s64 = ctx.r10.s64 + 17279;
	// bl 0x880a51a0
	ctx.lr = 0x880C5CD4;
	sub_880A51A0(ctx, base);
loc_880C5CD4:
	// lwz r24,-11932(r19)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r19.u32 + -11932);
loc_880C5CD8:
	// lwz r11,8004(r21)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r21.u32 + 8004);
	// addi r6,r23,-3
	ctx.r6.s64 = ctx.r23.s64 + -3;
	// lwz r10,8000(r21)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r21.u32 + 8000);
	// li r3,17643
	ctx.r3.s64 = 17643;
	// addis r5,r11,-12
	ctx.r5.s64 = ctx.r11.s64 + -786432;
	// addis r4,r10,8
	ctx.r4.s64 = ctx.r10.s64 + 524288;
	// bl 0x881538c0
	ctx.lr = 0x880C5CF4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c5d10
	if (ctx.cr6.eq) goto loc_880C5D10;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// oris r10,r11,518
	ctx.r10.u64 = ctx.r11.u64 | 33947648;
	// stw r24,-11932(r19)
	PPC_STORE_U32(ctx.r19.u32 + -11932, ctx.r24.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_880C5D10:
	// lwz r9,224(r21)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r21.u32 + 224);
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// lwz r11,-168(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -168);
	// li r3,17277
	ctx.r3.s64 = 17277;
	// lwz r10,-164(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -164);
	// divw r8,r9,r18
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r18.s32);
	// rlwinm r9,r11,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r25,r8,r22
	ctx.r25.u64 = ctx.r8.u64 + ctx.r22.u64;
	// add r4,r9,r16
	ctx.r4.u64 = ctx.r9.u64 + ctx.r16.u64;
	// add r5,r11,r25
	ctx.r5.u64 = ctx.r11.u64 + ctx.r25.u64;
	// bl 0x881538c0
	ctx.lr = 0x880C5D40;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x880c5d8c
	if (ctx.cr6.eq) goto loc_880C5D8C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c5d58
	if (ctx.cr6.eq) goto loc_880C5D58;
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C5D58:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x880c5d8c
	if (ctx.cr6.eq) goto loc_880C5D8C;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c5d8c
	if (ctx.cr6.eq) goto loc_880C5D8C;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r24,-11932(r19)
	PPC_STORE_U32(ctx.r19.u32 + -11932, ctx.r24.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C5D8C:
	// li r30,-1
	ctx.r30.s64 = -1;
	// addi r28,r21,5600
	ctx.r28.s64 = ctx.r21.s64 + 5600;
	// addi r29,r21,7332
	ctx.r29.s64 = ctx.r21.s64 + 7332;
	// li r26,2
	ctx.r26.s64 = 2;
loc_880C5D9C:
	// lwz r11,-80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -80);
	// addi r9,r30,1
	ctx.r9.s64 = ctx.r30.s64 + 1;
	// lwz r10,-76(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -76);
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// mullw r8,r11,r30
	ctx.r8.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r8,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r25
	ctx.r11.u64 = ctx.r11.u64 + ctx.r25.u64;
	// add r10,r10,r16
	ctx.r10.u64 = ctx.r10.u64 + ctx.r16.u64;
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// cntlzw r7,r9
	ctx.r7.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// stw r10,-4(r29)
	PPC_STORE_U32(ctx.r29.u32 + -4, ctx.r10.u32);
	// li r3,17340
	ctx.r3.s64 = 17340;
	// lwz r5,0(r28)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// rlwinm r27,r7,27,31,31
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// lwz r4,-4(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + -4);
	// mullw r9,r4,r30
	ctx.r9.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r30.s32);
	// subf r4,r9,r10
	ctx.r4.s64 = ctx.r10.s64 - ctx.r9.s64;
	// subf r5,r5,r11
	ctx.r5.s64 = ctx.r11.s64 - ctx.r5.s64;
	// bl 0x881538c0
	ctx.lr = 0x880C5DEC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x880c5e38
	if (ctx.cr6.eq) goto loc_880C5E38;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c5e04
	if (ctx.cr6.eq) goto loc_880C5E04;
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C5E04:
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880c5e38
	if (ctx.cr6.eq) goto loc_880C5E38;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c5e38
	if (ctx.cr6.eq) goto loc_880C5E38;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C5E38:
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq cr6,0x880c5e58
	if (ctx.cr6.eq) goto loc_880C5E58;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c5e58
	if (ctx.cr6.eq) goto loc_880C5E58;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r27,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_880C5E58:
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// neg r30,r30
	ctx.r30.s64 = -ctx.r30.s64;
	// addi r29,r29,84
	ctx.r29.s64 = ctx.r29.s64 + 84;
	// addi r28,r28,288
	ctx.r28.s64 = ctx.r28.s64 + 288;
	// bne 0x880c5d9c
	if (!ctx.cr0.eq) goto loc_880C5D9C;
	// lwz r11,-176(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -176);
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// lwz r10,-172(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -172);
	// li r3,17276
	ctx.r3.s64 = 17276;
	// rlwinm r9,r11,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// stw r24,-11932(r19)
	PPC_STORE_U32(ctx.r19.u32 + -11932, ctx.r24.u32);
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r9,r16
	ctx.r4.u64 = ctx.r9.u64 + ctx.r16.u64;
	// add r5,r11,r25
	ctx.r5.u64 = ctx.r11.u64 + ctx.r25.u64;
	// bl 0x881538c0
	ctx.lr = 0x880C5E94;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x880c5fa8
	if (ctx.cr6.eq) goto loc_880C5FA8;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c5eac
	if (ctx.cr6.eq) goto loc_880C5EAC;
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C5EAC:
	// lwz r22,84(r1)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x880c5fac
	if (ctx.cr6.eq) goto loc_880C5FAC;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c5fac
	if (ctx.cr6.eq) goto loc_880C5FAC;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r24,-11932(r19)
	PPC_STORE_U32(ctx.r19.u32 + -11932, ctx.r24.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// b 0x880c5fac
	goto loc_880C5FAC;
loc_880C5EE8:
	// lwz r11,7988(r21)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r21.u32 + 7988);
	// addi r8,r31,48
	ctx.r8.s64 = ctx.r31.s64 + 48;
	// addi r7,r31,48
	ctx.r7.s64 = ctx.r31.s64 + 48;
	// lwz r10,-72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -72);
	// rlwinm r5,r11,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,-68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + -68);
	// addi r4,r8,1
	ctx.r4.s64 = ctx.r8.s64 + 1;
	// addi r3,r11,17279
	ctx.r3.s64 = ctx.r11.s64 + 17279;
	// addi r6,r23,1
	ctx.r6.s64 = ctx.r23.s64 + 1;
	// lbzx r11,r5,r7
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r7.u32);
	// lbzx r7,r5,r4
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r4.u32);
	// extsb r8,r11
	ctx.r8.s64 = ctx.r11.s8;
	// extsb r11,r7
	ctx.r11.s64 = ctx.r7.s8;
	// add r5,r8,r10
	ctx.r5.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r4,r11,r9
	ctx.r4.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r10,r5,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r4,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r10,r16
	ctx.r4.u64 = ctx.r10.u64 + ctx.r16.u64;
	// add r11,r11,r22
	ctx.r11.u64 = ctx.r11.u64 + ctx.r22.u64;
	// stw r4,8000(r21)
	PPC_STORE_U32(ctx.r21.u32 + 8000, ctx.r4.u32);
	// stw r11,8004(r21)
	PPC_STORE_U32(ctx.r21.u32 + 8004, ctx.r11.u32);
	// stw r4,8888(r21)
	PPC_STORE_U32(ctx.r21.u32 + 8888, ctx.r4.u32);
	// lwz r10,992(r21)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r21.u32 + 992);
	// divw r10,r10,r18
	ctx.r10.s32 = ppc_divw(ctx.r10.s32, ctx.r18.s32);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r5,8892(r21)
	PPC_STORE_U32(ctx.r21.u32 + 8892, ctx.r5.u32);
	// bl 0x881538c0
	ctx.lr = 0x880C5F54;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x880c5cd4
	if (ctx.cr6.eq) goto loc_880C5CD4;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c5f6c
	if (ctx.cr6.eq) goto loc_880C5F6C;
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C5F6C:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x880c5cd4
	if (ctx.cr6.eq) goto loc_880C5CD4;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c5cd4
	if (ctx.cr6.eq) goto loc_880C5CD4;
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-11932(r19)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r19.u32 + -11932);
	// rlwimi r9,r10,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// addi r24,r11,1
	ctx.r24.s64 = ctx.r11.s64 + 1;
	// or r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 | ctx.r8.u64;
	// stw r24,-11932(r19)
	PPC_STORE_U32(ctx.r19.u32 + -11932, ctx.r24.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// b 0x880c5cd8
	goto loc_880C5CD8;
loc_880C5FA8:
	// lwz r22,84(r1)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_880C5FAC:
	// lwz r11,-128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -128);
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// lwz r10,-124(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -124);
	// li r3,17313
	ctx.r3.s64 = 17313;
	// rlwinm r9,r11,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r9,r16
	ctx.r4.u64 = ctx.r9.u64 + ctx.r16.u64;
	// add r5,r11,r25
	ctx.r5.u64 = ctx.r11.u64 + ctx.r25.u64;
	// bl 0x881538c0
	ctx.lr = 0x880C5FD0;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x880c601c
	if (ctx.cr6.eq) goto loc_880C601C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c5fe8
	if (ctx.cr6.eq) goto loc_880C5FE8;
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C5FE8:
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x880c601c
	if (ctx.cr6.eq) goto loc_880C601C;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c601c
	if (ctx.cr6.eq) goto loc_880C601C;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r24,-11932(r19)
	PPC_STORE_U32(ctx.r19.u32 + -11932, ctx.r24.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C601C:
	// lwz r11,6392(r21)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r21.u32 + 6392);
	// addi r8,r31,-16
	ctx.r8.s64 = ctx.r31.s64 + -16;
	// addi r7,r31,-16
	ctx.r7.s64 = ctx.r31.s64 + -16;
	// lwz r9,-152(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + -152);
	// rlwinm r5,r11,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,-148(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -148);
	// addi r4,r8,1
	ctx.r4.s64 = ctx.r8.s64 + 1;
	// addi r3,r11,17303
	ctx.r3.s64 = ctx.r11.s64 + 17303;
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// lbzx r11,r5,r7
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r7.u32);
	// lbzx r8,r5,r4
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r4.u32);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// extsb r8,r8
	ctx.r8.s64 = ctx.r8.s8;
	// add r7,r11,r9
	ctx.r7.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// rlwinm r11,r7,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// addi r5,r10,16
	ctx.r5.s64 = ctx.r10.s64 + 16;
	// add r4,r11,r16
	ctx.r4.u64 = ctx.r11.u64 + ctx.r16.u64;
	// rlwinm r11,r5,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// add r5,r11,r25
	ctx.r5.u64 = ctx.r11.u64 + ctx.r25.u64;
	// bl 0x881538c0
	ctx.lr = 0x880C6070;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x880c60bc
	if (ctx.cr6.eq) goto loc_880C60BC;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c6088
	if (ctx.cr6.eq) goto loc_880C6088;
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C6088:
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x880c60bc
	if (ctx.cr6.eq) goto loc_880C60BC;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c60bc
	if (ctx.cr6.eq) goto loc_880C60BC;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r24,-11932(r19)
	PPC_STORE_U32(ctx.r19.u32 + -11932, ctx.r24.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C60BC:
	// li r30,-1
	ctx.r30.s64 = -1;
	// addi r29,r21,6812
	ctx.r29.s64 = ctx.r21.s64 + 6812;
	// li r27,2
	ctx.r27.s64 = 2;
loc_880C60C8:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// addi r8,r31,32
	ctx.r8.s64 = ctx.r31.s64 + 32;
	// addi r7,r31,32
	ctx.r7.s64 = ctx.r31.s64 + 32;
	// lwz r10,-104(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -104);
	// rlwinm r5,r11,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,-100(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + -100);
	// addi r4,r8,1
	ctx.r4.s64 = ctx.r8.s64 + 1;
	// addi r3,r11,17330
	ctx.r3.s64 = ctx.r11.s64 + 17330;
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// lbzx r8,r5,r7
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r7.u32);
	// cntlzw r7,r11
	ctx.r7.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// lbzx r5,r5,r4
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r4.u32);
	// extsb r8,r8
	ctx.r8.s64 = ctx.r8.s8;
	// extsb r11,r5
	ctx.r11.s64 = ctx.r5.s8;
	// add r4,r8,r10
	ctx.r4.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// mullw r10,r4,r30
	ctx.r10.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r30.s32);
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r10,r16
	ctx.r4.u64 = ctx.r10.u64 + ctx.r16.u64;
	// add r5,r11,r25
	ctx.r5.u64 = ctx.r11.u64 + ctx.r25.u64;
	// rlwinm r28,r7,27,31,31
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// bl 0x881538c0
	ctx.lr = 0x880C6128;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x880c6170
	if (ctx.cr6.eq) goto loc_880C6170;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c6140
	if (ctx.cr6.eq) goto loc_880C6140;
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C6140:
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x880c6170
	if (ctx.cr6.eq) goto loc_880C6170;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c6170
	if (ctx.cr6.eq) goto loc_880C6170;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C6170:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq cr6,0x880c6190
	if (ctx.cr6.eq) goto loc_880C6190;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c6190
	if (ctx.cr6.eq) goto loc_880C6190;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r28,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_880C6190:
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// neg r30,r30
	ctx.r30.s64 = -ctx.r30.s64;
	// addi r29,r29,84
	ctx.r29.s64 = ctx.r29.s64 + 84;
	// bne 0x880c60c8
	if (!ctx.cr0.eq) goto loc_880C60C8;
	// stw r24,-11932(r19)
	PPC_STORE_U32(ctx.r19.u32 + -11932, ctx.r24.u32);
	// li r30,-1
	ctx.r30.s64 = -1;
	// addi r28,r21,5024
	ctx.r28.s64 = ctx.r21.s64 + 5024;
	// addi r29,r21,7164
	ctx.r29.s64 = ctx.r21.s64 + 7164;
	// li r26,2
	ctx.r26.s64 = 2;
loc_880C61B4:
	// lwz r10,-92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -92);
	// addi r9,r30,1
	ctx.r9.s64 = ctx.r30.s64 + 1;
	// lwz r11,-96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -96);
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// mullw r8,r11,r30
	ctx.r8.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// add r11,r10,r25
	ctx.r11.u64 = ctx.r10.u64 + ctx.r25.u64;
	// rlwinm r10,r8,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// cntlzw r7,r9
	ctx.r7.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// add r10,r10,r16
	ctx.r10.u64 = ctx.r10.u64 + ctx.r16.u64;
	// li r3,17339
	ctx.r3.s64 = 17339;
	// stw r10,-4(r29)
	PPC_STORE_U32(ctx.r29.u32 + -4, ctx.r10.u32);
	// rlwinm r27,r7,27,31,31
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// lwz r5,0(r28)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// subf r5,r5,r11
	ctx.r5.s64 = ctx.r11.s64 - ctx.r5.s64;
	// lwz r4,-4(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + -4);
	// mullw r11,r4,r30
	ctx.r11.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r30.s32);
	// subf r4,r11,r10
	ctx.r4.s64 = ctx.r10.s64 - ctx.r11.s64;
	// bl 0x881538c0
	ctx.lr = 0x880C6204;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x880c624c
	if (ctx.cr6.eq) goto loc_880C624C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c621c
	if (ctx.cr6.eq) goto loc_880C621C;
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C621C:
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x880c624c
	if (ctx.cr6.eq) goto loc_880C624C;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c624c
	if (ctx.cr6.eq) goto loc_880C624C;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C624C:
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq cr6,0x880c626c
	if (ctx.cr6.eq) goto loc_880C626C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c626c
	if (ctx.cr6.eq) goto loc_880C626C;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r27,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_880C626C:
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// neg r30,r30
	ctx.r30.s64 = -ctx.r30.s64;
	// addi r29,r29,84
	ctx.r29.s64 = ctx.r29.s64 + 84;
	// addi r28,r28,288
	ctx.r28.s64 = ctx.r28.s64 + 288;
	// bne 0x880c61b4
	if (!ctx.cr0.eq) goto loc_880C61B4;
	// stw r16,6152(r21)
	PPC_STORE_U32(ctx.r21.u32 + 6152, ctx.r16.u32);
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// stw r25,6156(r21)
	PPC_STORE_U32(ctx.r21.u32 + 6156, ctx.r25.u32);
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r16
	ctx.r4.u64 = ctx.r16.u64;
	// stw r24,-11932(r19)
	PPC_STORE_U32(ctx.r19.u32 + -11932, ctx.r24.u32);
	// li r3,17274
	ctx.r3.s64 = 17274;
	// bl 0x881538c0
	ctx.lr = 0x880C62A0;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x880c62ec
	if (ctx.cr6.eq) goto loc_880C62EC;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c62b8
	if (ctx.cr6.eq) goto loc_880C62B8;
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C62B8:
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x880c62ec
	if (ctx.cr6.eq) goto loc_880C62EC;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c62ec
	if (ctx.cr6.eq) goto loc_880C62EC;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r24,-11932(r19)
	PPC_STORE_U32(ctx.r19.u32 + -11932, ctx.r24.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C62EC:
	// lwz r11,-136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -136);
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// lwz r10,-132(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -132);
	// li r3,17312
	ctx.r3.s64 = 17312;
	// rlwinm r9,r11,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r9,r16
	ctx.r4.u64 = ctx.r9.u64 + ctx.r16.u64;
	// add r5,r11,r25
	ctx.r5.u64 = ctx.r11.u64 + ctx.r25.u64;
	// bl 0x881538c0
	ctx.lr = 0x880C6310;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x880c635c
	if (ctx.cr6.eq) goto loc_880C635C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c6328
	if (ctx.cr6.eq) goto loc_880C6328;
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C6328:
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x880c635c
	if (ctx.cr6.eq) goto loc_880C635C;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c635c
	if (ctx.cr6.eq) goto loc_880C635C;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r24,-11932(r19)
	PPC_STORE_U32(ctx.r19.u32 + -11932, ctx.r24.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C635C:
	// lwz r11,6308(r21)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r21.u32 + 6308);
	// addi r8,r31,-16
	ctx.r8.s64 = ctx.r31.s64 + -16;
	// addi r7,r31,-16
	ctx.r7.s64 = ctx.r31.s64 + -16;
	// lwz r10,-152(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -152);
	// rlwinm r5,r11,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,-148(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + -148);
	// addi r4,r8,1
	ctx.r4.s64 = ctx.r8.s64 + 1;
	// addi r3,r11,17303
	ctx.r3.s64 = ctx.r11.s64 + 17303;
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// lbzx r11,r5,r7
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r7.u32);
	// lbzx r7,r5,r4
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r4.u32);
	// extsb r8,r11
	ctx.r8.s64 = ctx.r11.s8;
	// extsb r11,r7
	ctx.r11.s64 = ctx.r7.s8;
	// add r5,r8,r10
	ctx.r5.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r4,r11,r9
	ctx.r4.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r10,r5,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r4,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r10,r16
	ctx.r4.u64 = ctx.r10.u64 + ctx.r16.u64;
	// add r5,r11,r25
	ctx.r5.u64 = ctx.r11.u64 + ctx.r25.u64;
	// bl 0x881538c0
	ctx.lr = 0x880C63AC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x880c63f8
	if (ctx.cr6.eq) goto loc_880C63F8;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c63c4
	if (ctx.cr6.eq) goto loc_880C63C4;
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C63C4:
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x880c63f8
	if (ctx.cr6.eq) goto loc_880C63F8;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c63f8
	if (ctx.cr6.eq) goto loc_880C63F8;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r24,-11932(r19)
	PPC_STORE_U32(ctx.r19.u32 + -11932, ctx.r24.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C63F8:
	// li r30,-1
	ctx.r30.s64 = -1;
	// addi r28,r21,4448
	ctx.r28.s64 = ctx.r21.s64 + 4448;
	// addi r29,r21,6996
	ctx.r29.s64 = ctx.r21.s64 + 6996;
	// li r26,2
	ctx.r26.s64 = 2;
loc_880C6408:
	// lwz r11,-88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -88);
	// addi r9,r30,1
	ctx.r9.s64 = ctx.r30.s64 + 1;
	// lwz r10,-84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -84);
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// mullw r8,r11,r30
	ctx.r8.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// rlwinm r11,r8,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r16
	ctx.r11.u64 = ctx.r11.u64 + ctx.r16.u64;
	// add r10,r10,r25
	ctx.r10.u64 = ctx.r10.u64 + ctx.r25.u64;
	// stw r11,-4(r29)
	PPC_STORE_U32(ctx.r29.u32 + -4, ctx.r11.u32);
	// cntlzw r7,r9
	ctx.r7.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// stw r10,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r10.u32);
	// li r3,17338
	ctx.r3.s64 = 17338;
	// rlwinm r27,r7,27,31,31
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// lwz r4,-4(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + -4);
	// lwz r5,0(r28)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// subf r5,r5,r10
	ctx.r5.s64 = ctx.r10.s64 - ctx.r5.s64;
	// mullw r10,r4,r30
	ctx.r10.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r30.s32);
	// subf r4,r10,r11
	ctx.r4.s64 = ctx.r11.s64 - ctx.r10.s64;
	// bl 0x881538c0
	ctx.lr = 0x880C6458;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x880c64a0
	if (ctx.cr6.eq) goto loc_880C64A0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c6470
	if (ctx.cr6.eq) goto loc_880C6470;
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C6470:
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x880c64a0
	if (ctx.cr6.eq) goto loc_880C64A0;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c64a0
	if (ctx.cr6.eq) goto loc_880C64A0;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C64A0:
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq cr6,0x880c64c0
	if (ctx.cr6.eq) goto loc_880C64C0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c64c0
	if (ctx.cr6.eq) goto loc_880C64C0;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r27,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_880C64C0:
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// neg r30,r30
	ctx.r30.s64 = -ctx.r30.s64;
	// addi r29,r29,84
	ctx.r29.s64 = ctx.r29.s64 + 84;
	// addi r28,r28,288
	ctx.r28.s64 = ctx.r28.s64 + 288;
	// bne 0x880c6408
	if (!ctx.cr0.eq) goto loc_880C6408;
	// lwz r11,-144(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -144);
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// lwz r10,-140(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -140);
	// li r3,17311
	ctx.r3.s64 = 17311;
	// rlwinm r9,r11,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// stw r24,-11932(r19)
	PPC_STORE_U32(ctx.r19.u32 + -11932, ctx.r24.u32);
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r9,r16
	ctx.r4.u64 = ctx.r9.u64 + ctx.r16.u64;
	// add r5,r11,r25
	ctx.r5.u64 = ctx.r11.u64 + ctx.r25.u64;
	// bl 0x881538c0
	ctx.lr = 0x880C64FC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x880c6548
	if (ctx.cr6.eq) goto loc_880C6548;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c6514
	if (ctx.cr6.eq) goto loc_880C6514;
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C6514:
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x880c6548
	if (ctx.cr6.eq) goto loc_880C6548;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c6548
	if (ctx.cr6.eq) goto loc_880C6548;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r24,-11932(r19)
	PPC_STORE_U32(ctx.r19.u32 + -11932, ctx.r24.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C6548:
	// lwz r11,6224(r21)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r21.u32 + 6224);
	// addi r8,r31,-16
	ctx.r8.s64 = ctx.r31.s64 + -16;
	// addi r7,r31,-16
	ctx.r7.s64 = ctx.r31.s64 + -16;
	// lwz r9,-152(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + -152);
	// rlwinm r5,r11,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,-148(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -148);
	// addi r4,r8,1
	ctx.r4.s64 = ctx.r8.s64 + 1;
	// addi r3,r11,17303
	ctx.r3.s64 = ctx.r11.s64 + 17303;
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// lbzx r11,r5,r7
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r7.u32);
	// lbzx r8,r5,r4
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r4.u32);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// extsb r8,r8
	ctx.r8.s64 = ctx.r8.s8;
	// add r7,r11,r9
	ctx.r7.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// rlwinm r11,r7,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// addi r5,r10,-20
	ctx.r5.s64 = ctx.r10.s64 + -20;
	// add r4,r11,r16
	ctx.r4.u64 = ctx.r11.u64 + ctx.r16.u64;
	// rlwinm r11,r5,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// add r5,r11,r25
	ctx.r5.u64 = ctx.r11.u64 + ctx.r25.u64;
	// bl 0x881538c0
	ctx.lr = 0x880C659C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x880c65e8
	if (ctx.cr6.eq) goto loc_880C65E8;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c65b4
	if (ctx.cr6.eq) goto loc_880C65B4;
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C65B4:
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x880c65e8
	if (ctx.cr6.eq) goto loc_880C65E8;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c65e8
	if (ctx.cr6.eq) goto loc_880C65E8;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r24,-11932(r19)
	PPC_STORE_U32(ctx.r19.u32 + -11932, ctx.r24.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C65E8:
	// lwz r11,-184(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -184);
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// lwz r10,-180(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -180);
	// li r3,17273
	ctx.r3.s64 = 17273;
	// rlwinm r9,r11,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r9,r16
	ctx.r4.u64 = ctx.r9.u64 + ctx.r16.u64;
	// add r5,r11,r25
	ctx.r5.u64 = ctx.r11.u64 + ctx.r25.u64;
	// bl 0x881538c0
	ctx.lr = 0x880C660C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x880c6658
	if (ctx.cr6.eq) goto loc_880C6658;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c6624
	if (ctx.cr6.eq) goto loc_880C6624;
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C6624:
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x880c6658
	if (ctx.cr6.eq) goto loc_880C6658;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c6658
	if (ctx.cr6.eq) goto loc_880C6658;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r24,-11932(r19)
	PPC_STORE_U32(ctx.r19.u32 + -11932, ctx.r24.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C6658:
	// li r30,-1
	ctx.r30.s64 = -1;
	// li r28,2
	ctx.r28.s64 = 2;
loc_880C6660:
	// lwz r11,-160(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -160);
	// addi r9,r30,1
	ctx.r9.s64 = ctx.r30.s64 + 1;
	// lwz r10,-156(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -156);
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// mullw r8,r11,r30
	ctx.r8.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r8,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// cntlzw r7,r9
	ctx.r7.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// add r5,r11,r25
	ctx.r5.u64 = ctx.r11.u64 + ctx.r25.u64;
	// add r4,r10,r16
	ctx.r4.u64 = ctx.r10.u64 + ctx.r16.u64;
	// li r3,17278
	ctx.r3.s64 = 17278;
	// rlwinm r29,r7,27,31,31
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// bl 0x881538c0
	ctx.lr = 0x880C6694;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x880c66dc
	if (ctx.cr6.eq) goto loc_880C66DC;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c66ac
	if (ctx.cr6.eq) goto loc_880C66AC;
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C66AC:
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x880c66dc
	if (ctx.cr6.eq) goto loc_880C66DC;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c66dc
	if (ctx.cr6.eq) goto loc_880C66DC;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C66DC:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x880c66fc
	if (ctx.cr6.eq) goto loc_880C66FC;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c66fc
	if (ctx.cr6.eq) goto loc_880C66FC;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r29,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_880C66FC:
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// neg r30,r30
	ctx.r30.s64 = -ctx.r30.s64;
	// bne 0x880c6660
	if (!ctx.cr0.eq) goto loc_880C6660;
	// stw r24,-11932(r19)
	PPC_STORE_U32(ctx.r19.u32 + -11932, ctx.r24.u32);
	// li r30,-1
	ctx.r30.s64 = -1;
	// addi r29,r21,6644
	ctx.r29.s64 = ctx.r21.s64 + 6644;
	// li r27,2
	ctx.r27.s64 = 2;
loc_880C6718:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// addi r8,r31,16
	ctx.r8.s64 = ctx.r31.s64 + 16;
	// addi r7,r31,16
	ctx.r7.s64 = ctx.r31.s64 + 16;
	// lwz r10,-112(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -112);
	// rlwinm r5,r11,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,-108(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + -108);
	// addi r4,r8,1
	ctx.r4.s64 = ctx.r8.s64 + 1;
	// addi r3,r11,17322
	ctx.r3.s64 = ctx.r11.s64 + 17322;
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// lbzx r8,r5,r7
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r7.u32);
	// cntlzw r7,r11
	ctx.r7.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// lbzx r5,r5,r4
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r4.u32);
	// extsb r8,r8
	ctx.r8.s64 = ctx.r8.s8;
	// extsb r11,r5
	ctx.r11.s64 = ctx.r5.s8;
	// add r4,r8,r10
	ctx.r4.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// mullw r10,r4,r30
	ctx.r10.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r30.s32);
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r10,r16
	ctx.r4.u64 = ctx.r10.u64 + ctx.r16.u64;
	// add r5,r11,r25
	ctx.r5.u64 = ctx.r11.u64 + ctx.r25.u64;
	// rlwinm r28,r7,27,31,31
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// bl 0x881538c0
	ctx.lr = 0x880C6778;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x880c67c0
	if (ctx.cr6.eq) goto loc_880C67C0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c6790
	if (ctx.cr6.eq) goto loc_880C6790;
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C6790:
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x880c67c0
	if (ctx.cr6.eq) goto loc_880C67C0;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c67c0
	if (ctx.cr6.eq) goto loc_880C67C0;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C67C0:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq cr6,0x880c67e0
	if (ctx.cr6.eq) goto loc_880C67E0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c67e0
	if (ctx.cr6.eq) goto loc_880C67E0;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r28,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_880C67E0:
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// neg r30,r30
	ctx.r30.s64 = -ctx.r30.s64;
	// addi r29,r29,84
	ctx.r29.s64 = ctx.r29.s64 + 84;
	// bne 0x880c6718
	if (!ctx.cr0.eq) goto loc_880C6718;
	// stw r24,-11932(r19)
	PPC_STORE_U32(ctx.r19.u32 + -11932, ctx.r24.u32);
	// li r30,-1
	ctx.r30.s64 = -1;
	// addi r29,r21,6476
	ctx.r29.s64 = ctx.r21.s64 + 6476;
	// li r27,2
	ctx.r27.s64 = 2;
loc_880C6800:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// addi r8,r31,1
	ctx.r8.s64 = ctx.r31.s64 + 1;
	// addi r7,r30,1
	ctx.r7.s64 = ctx.r30.s64 + 1;
	// lwz r10,-120(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -120);
	// rlwinm r5,r11,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,-116(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + -116);
	// addi r3,r11,17314
	ctx.r3.s64 = ctx.r11.s64 + 17314;
	// cntlzw r4,r7
	ctx.r4.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// rlwinm r28,r4,27,31,31
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// lbzx r11,r5,r31
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r31.u32);
	// lbzx r7,r5,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r8.u32);
	// extsb r8,r11
	ctx.r8.s64 = ctx.r11.s8;
	// extsb r11,r7
	ctx.r11.s64 = ctx.r7.s8;
	// add r5,r8,r10
	ctx.r5.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r4,r11,r9
	ctx.r4.u64 = ctx.r11.u64 + ctx.r9.u64;
	// mullw r11,r5,r30
	ctx.r11.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r30.s32);
	// rlwinm r10,r11,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r4,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r10,r16
	ctx.r4.u64 = ctx.r10.u64 + ctx.r16.u64;
	// add r5,r11,r25
	ctx.r5.u64 = ctx.r11.u64 + ctx.r25.u64;
	// bl 0x881538c0
	ctx.lr = 0x880C6858;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x880c68a0
	if (ctx.cr6.eq) goto loc_880C68A0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c6870
	if (ctx.cr6.eq) goto loc_880C6870;
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C6870:
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x880c68a0
	if (ctx.cr6.eq) goto loc_880C68A0;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c68a0
	if (ctx.cr6.eq) goto loc_880C68A0;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C68A0:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq cr6,0x880c68c0
	if (ctx.cr6.eq) goto loc_880C68C0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c68c0
	if (ctx.cr6.eq) goto loc_880C68C0;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r28,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_880C68C0:
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// neg r30,r30
	ctx.r30.s64 = -ctx.r30.s64;
	// addi r29,r29,84
	ctx.r29.s64 = ctx.r29.s64 + 84;
	// bne 0x880c6800
	if (!ctx.cr0.eq) goto loc_880C6800;
	// stw r24,-11932(r19)
	PPC_STORE_U32(ctx.r19.u32 + -11932, ctx.r24.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C68E0"))) PPC_WEAK_FUNC(sub_880C68E0);
PPC_FUNC_IMPL(__imp__sub_880C68E0) {
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
	// addi r11,r4,9032
	ctx.r11.s64 = ctx.r4.s64 + 9032;
	// addi r9,r4,9028
	ctx.r9.s64 = ctx.r4.s64 + 9028;
	// ori r8,r10,65535
	ctx.r8.u64 = ctx.r10.u64 | 65535;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// lis r7,-30708
	ctx.r7.s64 = -2012479488;
	// stw r8,9032(r4)
	PPC_STORE_U32(ctx.r4.u32 + 9032, ctx.r8.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r7,21600
	ctx.r5.s64 = ctx.r7.s64 + 21600;
	// li r4,30
	ctx.r4.s64 = 30;
	// bl 0x88096460
	ctx.lr = 0x880C691C;
	sub_88096460(ctx, base);
	// lis r6,-30641
	ctx.r6.s64 = -2008088576;
	// addi r5,r6,-18876
	ctx.r5.s64 = ctx.r6.s64 + -18876;
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

__attribute__((alias("__imp__sub_880C6938"))) PPC_WEAK_FUNC(sub_880C6938);
PPC_FUNC_IMPL(__imp__sub_880C6938) {
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
	// addi r11,r4,8860
	ctx.r11.s64 = ctx.r4.s64 + 8860;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lis r9,-30708
	ctx.r9.s64 = -2012479488;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r9,21600
	ctx.r5.s64 = ctx.r9.s64 + 21600;
	// li r4,30
	ctx.r4.s64 = 30;
	// bl 0x88096460
	ctx.lr = 0x880C6968;
	sub_88096460(ctx, base);
	// lis r8,-30641
	ctx.r8.s64 = -2008088576;
	// stw r3,-18876(r8)
	PPC_STORE_U32(ctx.r8.u32 + -18876, ctx.r3.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880C6980"))) PPC_WEAK_FUNC(sub_880C6980);
PPC_FUNC_IMPL(__imp__sub_880C6980) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// clrlwi r10,r4,23
	ctx.r10.u64 = ctx.r4.u32 & 0x1FF;
	// cmpwi cr6,r10,320
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 320, ctx.xer);
	// stw r5,60(r11)
	PPC_STORE_U32(ctx.r11.u32 + 60, ctx.r5.u32);
	// stw r10,56(r11)
	PPC_STORE_U32(ctx.r11.u32 + 56, ctx.r10.u32);
	// blt cr6,0x880c69a0
	if (ctx.cr6.lt) goto loc_880C69A0;
	// li r10,320
	ctx.r10.s64 = 320;
	// stw r10,56(r11)
	PPC_STORE_U32(ctx.r11.u32 + 56, ctx.r10.u32);
loc_880C69A0:
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 56);
	// cmpwi cr6,r10,192
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 192, ctx.xer);
	// bgtlr cr6
	if (ctx.cr6.gt) return;
	// li r10,192
	ctx.r10.s64 = 192;
	// stw r10,56(r11)
	PPC_STORE_U32(ctx.r11.u32 + 56, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880C69B8"))) PPC_WEAK_FUNC(sub_880C69B8);
PPC_FUNC_IMPL(__imp__sub_880C69B8) {
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
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880C69E4;
	sub_88096BC8(ctx, base);
	// lwz r7,4(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r11,44(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 44);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x880c6a08
	if (ctx.cr6.eq) goto loc_880C6A08;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880C6A00;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880c6b04
	goto loc_880C6B04;
loc_880C6A08:
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x880c6a64
	if (ctx.cr6.lt) goto loc_880C6A64;
	// bne cr6,0x880c6b00
	if (!ctx.cr6.eq) goto loc_880C6B00;
	// lwz r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r10,-30682
	ctx.r10.s64 = -2010775552;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r10,25468
	ctx.r9.s64 = ctx.r10.s64 + 25468;
	// lwzx r6,r8,r9
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// stw r6,32(r7)
	PPC_STORE_U32(ctx.r7.u32 + 32, ctx.r6.u32);
	// lwz r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// blt cr6,0x880c6b00
	if (ctx.cr6.lt) goto loc_880C6B00;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// bl 0x88096b40
	ctx.lr = 0x880C6A5C;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880c6b04
	goto loc_880C6B04;
loc_880C6A64:
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bgt 0x880c6b00
	if (ctx.cr0.gt) goto loc_880C6B00;
	// lwz r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// li r6,3
	ctx.r6.s64 = 3;
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// addi r5,r10,9552
	ctx.r5.s64 = ctx.r10.s64 + 9552;
	// addi r4,r11,128
	ctx.r4.s64 = ctx.r11.s64 + 128;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r4,2,21,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x7FC;
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// lwzx r10,r11,r5
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r5.u32);
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lwzx r5,r8,r5
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r5.u32);
	// subfic r11,r5,4096
	ctx.xer.ca = ctx.r5.u32 <= 4096;
	ctx.r11.s64 = 4096 - ctx.r5.s64;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r4,r10,r9
	ctx.r4.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// rlwinm r10,r4,7,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 7) & 0xFFFFFF80;
	// rlwinm r9,r11,7,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 7) & 0xFFFFFF80;
	// stw r10,32(r7)
	PPC_STORE_U32(ctx.r7.u32 + 32, ctx.r10.u32);
	// divw r8,r9,r6
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r6.s32);
	// lwz r7,4(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// stw r8,36(r7)
	PPC_STORE_U32(ctx.r7.u32 + 36, ctx.r8.u32);
	// lwz r6,16(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addic. r11,r6,-4
	ctx.xer.ca = ctx.r6.u32 > 3;
	ctx.r11.s64 = ctx.r6.s64 + -4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// bgt 0x880c6b00
	if (ctx.cr0.gt) goto loc_880C6B00;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r11,32(r10)
	PPC_STORE_U32(ctx.r10.u32 + 32, ctx.r11.u32);
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,36(r8)
	PPC_STORE_U32(ctx.r8.u32 + 36, ctx.r11.u32);
loc_880C6B00:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880C6B04:
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

__attribute__((alias("__imp__sub_880C6B1C"))) PPC_WEAK_FUNC(sub_880C6B1C);
PPC_FUNC_IMPL(__imp__sub_880C6B1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C6B20"))) PPC_WEAK_FUNC(sub_880C6B20);
PPC_FUNC_IMPL(__imp__sub_880C6B20) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880C6B28;
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
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880C6B48;
	sub_88096BC8(ctx, base);
	// lwz r10,3880(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 3880);
	// addi r11,r29,3836
	ctx.r11.s64 = ctx.r29.s64 + 3836;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880c6b70
	if (ctx.cr6.eq) goto loc_880C6B70;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880C6B64;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_880C6B70:
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// bgt 0x880c6bb8
	if (ctx.cr0.gt) goto loc_880C6BB8;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// addic. r10,r9,-4
	ctx.xer.ca = ctx.r9.u32 > 3;
	ctx.r10.s64 = ctx.r9.s64 + -4;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r10.u32);
	// bgt 0x880c6bb8
	if (ctx.cr0.gt) goto loc_880C6BB8;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r10,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880C6BAC;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_880C6BB8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C6BC4"))) PPC_WEAK_FUNC(sub_880C6BC4);
PPC_FUNC_IMPL(__imp__sub_880C6BC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C6BC8"))) PPC_WEAK_FUNC(sub_880C6BC8);
PPC_FUNC_IMPL(__imp__sub_880C6BC8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880C6BD0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880C6BF0;
	sub_88096BC8(ctx, base);
	// lwz r10,3880(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 3880);
	// addi r11,r31,3836
	ctx.r11.s64 = ctx.r31.s64 + 3836;
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// beq cr6,0x880c6c18
	if (ctx.cr6.eq) goto loc_880C6C18;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096b40
	ctx.lr = 0x880C6C0C;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_880C6C18:
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// bgt 0x880c6c78
	if (ctx.cr0.gt) goto loc_880C6C78;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmpwi cr6,r10,128
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 128, ctx.xer);
	// blt cr6,0x880c6c44
	if (ctx.cr6.lt) goto loc_880C6C44;
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// stw r10,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r10.u32);
loc_880C6C44:
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// addi r10,r10,5
	ctx.r10.s64 = ctx.r10.s64 + 5;
	// stw r10,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r10.u32);
	// cmpwi cr6,r10,240
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 240, ctx.xer);
	// blt cr6,0x880c6c78
	if (ctx.cr6.lt) goto loc_880C6C78;
	// li r10,240
	ctx.r10.s64 = 240;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r10,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096b40
	ctx.lr = 0x880C6C6C;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_880C6C78:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C6C84"))) PPC_WEAK_FUNC(sub_880C6C84);
PPC_FUNC_IMPL(__imp__sub_880C6C84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C6C88"))) PPC_WEAK_FUNC(sub_880C6C88);
PPC_FUNC_IMPL(__imp__sub_880C6C88) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880C6C90;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880C6CB0;
	sub_88096BC8(ctx, base);
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x880c6d00
	if (!ctx.cr6.eq) goto loc_880C6D00;
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x880c6d00
	if (!ctx.cr6.eq) goto loc_880C6D00;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// bgt 0x880c6d2c
	if (ctx.cr0.gt) goto loc_880C6D2C;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x880c6d18
	if (ctx.cr6.lt) goto loc_880C6D18;
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
loc_880C6D00:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096b40
	ctx.lr = 0x880C6D0C;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_880C6D18:
	// cmpwi cr6,r11,31
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 31, ctx.xer);
	// blt cr6,0x880c6d2c
	if (ctx.cr6.lt) goto loc_880C6D2C;
	// li r11,31
	ctx.r11.s64 = 31;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// b 0x880c6d00
	goto loc_880C6D00;
loc_880C6D2C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C6D38"))) PPC_WEAK_FUNC(sub_880C6D38);
PPC_FUNC_IMPL(__imp__sub_880C6D38) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880C6D40;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880C6D60;
	sub_88096BC8(ctx, base);
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x880c6db0
	if (!ctx.cr6.eq) goto loc_880C6DB0;
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x880c6db0
	if (!ctx.cr6.eq) goto loc_880C6DB0;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// bgt 0x880c6dc8
	if (ctx.cr0.gt) goto loc_880C6DC8;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bgt cr6,0x880c6dc8
	if (ctx.cr6.gt) goto loc_880C6DC8;
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
loc_880C6DB0:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096b40
	ctx.lr = 0x880C6DBC;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_880C6DC8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C6DD4"))) PPC_WEAK_FUNC(sub_880C6DD4);
PPC_FUNC_IMPL(__imp__sub_880C6DD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C6DD8"))) PPC_WEAK_FUNC(sub_880C6DD8);
PPC_FUNC_IMPL(__imp__sub_880C6DD8) {
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
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880C6E04;
	sub_88096BC8(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mr r6,r9
	ctx.r6.u64 = ctx.r9.u64;
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// beq cr6,0x880c6e38
	if (ctx.cr6.eq) goto loc_880C6E38;
loc_880C6E24:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880C6E30;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880c6ee8
	goto loc_880C6EE8;
loc_880C6E38:
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// bgt 0x880c6ee4
	if (ctx.cr0.gt) goto loc_880C6EE4;
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// stw r10,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r5,r10,-1
	ctx.r5.s64 = ctx.r10.s64 + -1;
	// stw r5,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r5.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bgt cr6,0x880c6e7c
	if (ctx.cr6.gt) goto loc_880C6E7C;
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// stw r9,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r9.u32);
loc_880C6E7C:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r5,r11,-1
	ctx.r5.s64 = ctx.r11.s64 + -1;
	// stw r5,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r5.u32);
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bgt cr6,0x880c6ea4
	if (ctx.cr6.gt) goto loc_880C6EA4;
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
loc_880C6EA4:
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r5,r11,-1
	ctx.r5.s64 = ctx.r11.s64 + -1;
	// stw r5,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r5.u32);
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bgt cr6,0x880c6ecc
	if (ctx.cr6.gt) goto loc_880C6ECC;
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
loc_880C6ECC:
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x880c6ee4
	if (ctx.cr6.eq) goto loc_880C6EE4;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x880c6ee4
	if (ctx.cr6.eq) goto loc_880C6EE4;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne cr6,0x880c6e24
	if (!ctx.cr6.eq) goto loc_880C6E24;
loc_880C6EE4:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880C6EE8:
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

__attribute__((alias("__imp__sub_880C6F00"))) PPC_WEAK_FUNC(sub_880C6F00);
PPC_FUNC_IMPL(__imp__sub_880C6F00) {
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
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880C6F2C;
	sub_88096BC8(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// beq cr6,0x880c6f5c
	if (ctx.cr6.eq) goto loc_880C6F5C;
loc_880C6F48:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880C6F54;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880c7008
	goto loc_880C7008;
loc_880C6F5C:
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// bgt 0x880c7004
	if (ctx.cr0.gt) goto loc_880C7004;
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// li r9,7
	ctx.r9.s64 = 7;
	// stw r10,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// stw r5,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r5.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r4,7
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 7, ctx.xer);
	// blt cr6,0x880c6f9c
	if (ctx.cr6.lt) goto loc_880C6F9C;
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
loc_880C6F9C:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// stw r5,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r5.u32);
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r4,7
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 7, ctx.xer);
	// blt cr6,0x880c6fc4
	if (ctx.cr6.lt) goto loc_880C6FC4;
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
loc_880C6FC4:
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// stw r5,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r5.u32);
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r4,7
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 7, ctx.xer);
	// blt cr6,0x880c6fec
	if (ctx.cr6.lt) goto loc_880C6FEC;
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
loc_880C6FEC:
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x880c7004
	if (ctx.cr6.eq) goto loc_880C7004;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x880c7004
	if (ctx.cr6.eq) goto loc_880C7004;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne cr6,0x880c6f48
	if (!ctx.cr6.eq) goto loc_880C6F48;
loc_880C7004:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880C7008:
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

__attribute__((alias("__imp__sub_880C7020"))) PPC_WEAK_FUNC(sub_880C7020);
PPC_FUNC_IMPL(__imp__sub_880C7020) {
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
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880C704C;
	sub_88096BC8(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// bne cr6,0x880c7070
	if (!ctx.cr6.eq) goto loc_880C7070;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 48);
	// cmpwi cr6,r10,256
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 256, ctx.xer);
	// bne cr6,0x880c70ec
	if (!ctx.cr6.eq) goto loc_880C70EC;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_880C7070:
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// beq cr6,0x880c7094
	if (ctx.cr6.eq) goto loc_880C7094;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880C708C;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880c70f0
	goto loc_880C70F0;
loc_880C7094:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// bgt 0x880c70ec
	if (ctx.cr0.gt) goto loc_880C70EC;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bgt cr6,0x880c70ec
	if (ctx.cr6.gt) goto loc_880C70EC;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
	// bl 0x88096b40
	ctx.lr = 0x880C70E4;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880c70f0
	goto loc_880C70F0;
loc_880C70EC:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880C70F0:
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

__attribute__((alias("__imp__sub_880C7108"))) PPC_WEAK_FUNC(sub_880C7108);
PPC_FUNC_IMPL(__imp__sub_880C7108) {
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
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880C7134;
	sub_88096BC8(ctx, base);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// beq cr6,0x880c715c
	if (ctx.cr6.eq) goto loc_880C715C;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880C7154;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880c71c8
	goto loc_880C71C8;
loc_880C715C:
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// bgt 0x880c71c4
	if (ctx.cr0.gt) goto loc_880C71C4;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r7,7
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 7, ctx.xer);
	// blt cr6,0x880c71c4
	if (ctx.cr6.lt) goto loc_880C71C4;
	// li r9,7
	ctx.r9.s64 = 7;
	// li r8,3
	ctx.r8.s64 = 3;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// li r7,256
	ctx.r7.s64 = 256;
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r8,64(r6)
	PPC_STORE_U32(ctx.r6.u32 + 64, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,48(r5)
	PPC_STORE_U32(ctx.r5.u32 + 48, ctx.r7.u32);
	// bl 0x88096b40
	ctx.lr = 0x880C71BC;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880c71c8
	goto loc_880C71C8;
loc_880C71C4:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880C71C8:
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

__attribute__((alias("__imp__sub_880C71E0"))) PPC_WEAK_FUNC(sub_880C71E0);
PPC_FUNC_IMPL(__imp__sub_880C71E0) {
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
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// lwz r10,9028(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 9028);
	// addic. r10,r10,-8
	ctx.xer.ca = ctx.r10.u32 > 7;
	ctx.r10.s64 = ctx.r10.s64 + -8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,9028(r11)
	PPC_STORE_U32(ctx.r11.u32 + 9028, ctx.r10.u32);
	// bgt 0x880c7230
	if (ctx.cr0.gt) goto loc_880C7230;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// stw r10,9028(r11)
	PPC_STORE_U32(ctx.r11.u32 + 9028, ctx.r10.u32);
	// bl 0x880c5358
	ctx.lr = 0x880C7214;
	sub_880C5358(ctx, base);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// bl 0x88096b40
	ctx.lr = 0x880C721C;
	sub_88096B40(ctx, base);
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
loc_880C7230:
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

__attribute__((alias("__imp__sub_880C7244"))) PPC_WEAK_FUNC(sub_880C7244);
PPC_FUNC_IMPL(__imp__sub_880C7244) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C7248"))) PPC_WEAK_FUNC(sub_880C7248);
PPC_FUNC_IMPL(__imp__sub_880C7248) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880C7250;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r5,20
	ctx.r5.s64 = 20;
	// bl 0x88096bc8
	ctx.lr = 0x880C7270;
	sub_88096BC8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r31,5852
	ctx.r10.s64 = ctx.r31.s64 + 5852;
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r7,128
	ctx.r7.s64 = 128;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r8,5896(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5896, ctx.r8.u32);
	// lis r6,-30708
	ctx.r6.s64 = -2012479488;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r11.u32);
	// addi r5,r6,27064
	ctx.r5.s64 = ctx.r6.s64 + 27064;
	// stw r7,16(r9)
	PPC_STORE_U32(ctx.r9.u32 + 16, ctx.r7.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096c60
	ctx.lr = 0x880C72B0;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C72BC"))) PPC_WEAK_FUNC(sub_880C72BC);
PPC_FUNC_IMPL(__imp__sub_880C72BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C72C0"))) PPC_WEAK_FUNC(sub_880C72C0);
PPC_FUNC_IMPL(__imp__sub_880C72C0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880C72C8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r5,20
	ctx.r5.s64 = 20;
	// bl 0x88096bc8
	ctx.lr = 0x880C72E8;
	sub_88096BC8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r31,5564
	ctx.r10.s64 = ctx.r31.s64 + 5564;
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r7,128
	ctx.r7.s64 = 128;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r8,5608(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5608, ctx.r8.u32);
	// lis r6,-30708
	ctx.r6.s64 = -2012479488;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r11.u32);
	// addi r5,r6,27064
	ctx.r5.s64 = ctx.r6.s64 + 27064;
	// stw r7,16(r9)
	PPC_STORE_U32(ctx.r9.u32 + 16, ctx.r7.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096c60
	ctx.lr = 0x880C7328;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C7334"))) PPC_WEAK_FUNC(sub_880C7334);
PPC_FUNC_IMPL(__imp__sub_880C7334) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C7338"))) PPC_WEAK_FUNC(sub_880C7338);
PPC_FUNC_IMPL(__imp__sub_880C7338) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880C7340;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r5,20
	ctx.r5.s64 = 20;
	// bl 0x88096bc8
	ctx.lr = 0x880C7360;
	sub_88096BC8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r31,5276
	ctx.r10.s64 = ctx.r31.s64 + 5276;
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r7,128
	ctx.r7.s64 = 128;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r8,5320(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5320, ctx.r8.u32);
	// lis r6,-30708
	ctx.r6.s64 = -2012479488;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r11.u32);
	// addi r5,r6,27064
	ctx.r5.s64 = ctx.r6.s64 + 27064;
	// stw r7,16(r9)
	PPC_STORE_U32(ctx.r9.u32 + 16, ctx.r7.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096c60
	ctx.lr = 0x880C73A0;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C73AC"))) PPC_WEAK_FUNC(sub_880C73AC);
PPC_FUNC_IMPL(__imp__sub_880C73AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C73B0"))) PPC_WEAK_FUNC(sub_880C73B0);
PPC_FUNC_IMPL(__imp__sub_880C73B0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880C73B8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r5,20
	ctx.r5.s64 = 20;
	// bl 0x88096bc8
	ctx.lr = 0x880C73D8;
	sub_88096BC8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r31,4988
	ctx.r10.s64 = ctx.r31.s64 + 4988;
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r7,128
	ctx.r7.s64 = 128;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r8,5032(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5032, ctx.r8.u32);
	// lis r6,-30708
	ctx.r6.s64 = -2012479488;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r11.u32);
	// addi r5,r6,27064
	ctx.r5.s64 = ctx.r6.s64 + 27064;
	// stw r7,16(r9)
	PPC_STORE_U32(ctx.r9.u32 + 16, ctx.r7.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096c60
	ctx.lr = 0x880C7418;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C7424"))) PPC_WEAK_FUNC(sub_880C7424);
PPC_FUNC_IMPL(__imp__sub_880C7424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C7428"))) PPC_WEAK_FUNC(sub_880C7428);
PPC_FUNC_IMPL(__imp__sub_880C7428) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880C7430;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r5,20
	ctx.r5.s64 = 20;
	// bl 0x88096bc8
	ctx.lr = 0x880C7450;
	sub_88096BC8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r31,4700
	ctx.r10.s64 = ctx.r31.s64 + 4700;
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r7,128
	ctx.r7.s64 = 128;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r8,4744(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4744, ctx.r8.u32);
	// lis r6,-30708
	ctx.r6.s64 = -2012479488;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r11.u32);
	// addi r5,r6,27064
	ctx.r5.s64 = ctx.r6.s64 + 27064;
	// stw r7,16(r9)
	PPC_STORE_U32(ctx.r9.u32 + 16, ctx.r7.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096c60
	ctx.lr = 0x880C7490;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C749C"))) PPC_WEAK_FUNC(sub_880C749C);
PPC_FUNC_IMPL(__imp__sub_880C749C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C74A0"))) PPC_WEAK_FUNC(sub_880C74A0);
PPC_FUNC_IMPL(__imp__sub_880C74A0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880C74A8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r5,20
	ctx.r5.s64 = 20;
	// bl 0x88096bc8
	ctx.lr = 0x880C74C8;
	sub_88096BC8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r31,4412
	ctx.r10.s64 = ctx.r31.s64 + 4412;
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r7,128
	ctx.r7.s64 = 128;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r8,4456(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4456, ctx.r8.u32);
	// lis r6,-30708
	ctx.r6.s64 = -2012479488;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r11.u32);
	// addi r5,r6,27064
	ctx.r5.s64 = ctx.r6.s64 + 27064;
	// stw r7,16(r9)
	PPC_STORE_U32(ctx.r9.u32 + 16, ctx.r7.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096c60
	ctx.lr = 0x880C7508;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C7514"))) PPC_WEAK_FUNC(sub_880C7514);
PPC_FUNC_IMPL(__imp__sub_880C7514) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C7518"))) PPC_WEAK_FUNC(sub_880C7518);
PPC_FUNC_IMPL(__imp__sub_880C7518) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880C7520;
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
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// bl 0x88096bc8
	ctx.lr = 0x880C7540;
	sub_88096BC8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r9,-30708
	ctx.r9.s64 = -2012479488;
	// stw r11,3880(r29)
	PPC_STORE_U32(ctx.r29.u32 + 3880, ctx.r11.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// addi r5,r9,27424
	ctx.r5.s64 = ctx.r9.s64 + 27424;
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096c60
	ctx.lr = 0x880C7568;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C7574"))) PPC_WEAK_FUNC(sub_880C7574);
PPC_FUNC_IMPL(__imp__sub_880C7574) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C7578"))) PPC_WEAK_FUNC(sub_880C7578);
PPC_FUNC_IMPL(__imp__sub_880C7578) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880C7580;
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
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// bl 0x88096bc8
	ctx.lr = 0x880C75A0;
	sub_88096BC8(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r10,3880(r29)
	PPC_STORE_U32(ctx.r29.u32 + 3880, ctx.r10.u32);
	// lis r9,-30708
	ctx.r9.s64 = -2012479488;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// addi r5,r9,27592
	ctx.r5.s64 = ctx.r9.s64 + 27592;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096c60
	ctx.lr = 0x880C75C8;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C75D4"))) PPC_WEAK_FUNC(sub_880C75D4);
PPC_FUNC_IMPL(__imp__sub_880C75D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C75D8"))) PPC_WEAK_FUNC(sub_880C75D8);
PPC_FUNC_IMPL(__imp__sub_880C75D8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880C75E0;
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
	// bl 0x88096bc8
	ctx.lr = 0x880C7600;
	sub_88096BC8(ctx, base);
	// lwz r11,72(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 72);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// lwz r10,68(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 68);
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r9,64(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 64);
	// lwz r8,68(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 68);
	// cmpw cr6,r9,r8
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, ctx.xer);
	// bge cr6,0x880c7644
	if (!ctx.cr6.lt) goto loc_880C7644;
	// lis r11,-30708
	ctx.r11.s64 = -2012479488;
	// addi r5,r11,27784
	ctx.r5.s64 = ctx.r11.s64 + 27784;
	// bl 0x88096c60
	ctx.lr = 0x880C7638;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_880C7644:
	// lis r11,-30708
	ctx.r11.s64 = -2012479488;
	// addi r5,r11,27960
	ctx.r5.s64 = ctx.r11.s64 + 27960;
	// bl 0x88096c60
	ctx.lr = 0x880C7650;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C765C"))) PPC_WEAK_FUNC(sub_880C765C);
PPC_FUNC_IMPL(__imp__sub_880C765C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C7660"))) PPC_WEAK_FUNC(sub_880C7660);
PPC_FUNC_IMPL(__imp__sub_880C7660) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x880C7668;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r5,40
	ctx.r5.s64 = 40;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880C768C;
	sub_88096BC8(ctx, base);
	// addi r10,r31,6392
	ctx.r10.s64 = ctx.r31.s64 + 6392;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// stw r11,6456(r31)
	PPC_STORE_U32(ctx.r31.u32 + 6456, ctx.r11.u32);
	// addi r8,r31,6812
	ctx.r8.s64 = ctx.r31.s64 + 6812;
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// addi r7,r31,6896
	ctx.r7.s64 = ctx.r31.s64 + 6896;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// lis r6,-30708
	ctx.r6.s64 = -2012479488;
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// stw r8,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r8.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r7,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r7.u32);
	// addi r5,r6,28120
	ctx.r5.s64 = ctx.r6.s64 + 28120;
	// stw r11,16(r9)
	PPC_STORE_U32(ctx.r9.u32 + 16, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096c60
	ctx.lr = 0x880C76D8;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C76E4"))) PPC_WEAK_FUNC(sub_880C76E4);
PPC_FUNC_IMPL(__imp__sub_880C76E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C76E8"))) PPC_WEAK_FUNC(sub_880C76E8);
PPC_FUNC_IMPL(__imp__sub_880C76E8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x880C76F0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r5,40
	ctx.r5.s64 = 40;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880C7714;
	sub_88096BC8(ctx, base);
	// addi r10,r31,6308
	ctx.r10.s64 = ctx.r31.s64 + 6308;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// stw r11,6372(r31)
	PPC_STORE_U32(ctx.r31.u32 + 6372, ctx.r11.u32);
	// addi r8,r31,6644
	ctx.r8.s64 = ctx.r31.s64 + 6644;
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// addi r7,r31,6728
	ctx.r7.s64 = ctx.r31.s64 + 6728;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// lis r6,-30708
	ctx.r6.s64 = -2012479488;
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// stw r8,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r8.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r7,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r7.u32);
	// addi r5,r6,28120
	ctx.r5.s64 = ctx.r6.s64 + 28120;
	// stw r11,16(r9)
	PPC_STORE_U32(ctx.r9.u32 + 16, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096c60
	ctx.lr = 0x880C7760;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C776C"))) PPC_WEAK_FUNC(sub_880C776C);
PPC_FUNC_IMPL(__imp__sub_880C776C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C7770"))) PPC_WEAK_FUNC(sub_880C7770);
PPC_FUNC_IMPL(__imp__sub_880C7770) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x880C7778;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r5,40
	ctx.r5.s64 = 40;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880C779C;
	sub_88096BC8(ctx, base);
	// addi r10,r31,6224
	ctx.r10.s64 = ctx.r31.s64 + 6224;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// stw r11,6288(r31)
	PPC_STORE_U32(ctx.r31.u32 + 6288, ctx.r11.u32);
	// addi r8,r31,6476
	ctx.r8.s64 = ctx.r31.s64 + 6476;
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// addi r7,r31,6560
	ctx.r7.s64 = ctx.r31.s64 + 6560;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// lis r6,-30708
	ctx.r6.s64 = -2012479488;
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// stw r8,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r8.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r7,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r7.u32);
	// addi r5,r6,28120
	ctx.r5.s64 = ctx.r6.s64 + 28120;
	// stw r11,16(r9)
	PPC_STORE_U32(ctx.r9.u32 + 16, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096c60
	ctx.lr = 0x880C77E8;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C77F4"))) PPC_WEAK_FUNC(sub_880C77F4);
PPC_FUNC_IMPL(__imp__sub_880C77F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C77F8"))) PPC_WEAK_FUNC(sub_880C77F8);
PPC_FUNC_IMPL(__imp__sub_880C77F8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x880C7800;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r5,40
	ctx.r5.s64 = 40;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880C7824;
	sub_88096BC8(ctx, base);
	// addi r11,r31,6392
	ctx.r11.s64 = ctx.r31.s64 + 6392;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r8,6456(r31)
	PPC_STORE_U32(ctx.r31.u32 + 6456, ctx.r8.u32);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// stw r10,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// addi r7,r31,6812
	ctx.r7.s64 = ctx.r31.s64 + 6812;
	// stw r10,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// addi r6,r31,6896
	ctx.r6.s64 = ctx.r31.s64 + 6896;
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// stw r7,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r7.u32);
	// lis r5,-30708
	ctx.r5.s64 = -2012479488;
	// stw r6,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r6.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r11,16(r9)
	PPC_STORE_U32(ctx.r9.u32 + 16, ctx.r11.u32);
	// addi r5,r5,28416
	ctx.r5.s64 = ctx.r5.s64 + 28416;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096c60
	ctx.lr = 0x880C7874;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C7880"))) PPC_WEAK_FUNC(sub_880C7880);
PPC_FUNC_IMPL(__imp__sub_880C7880) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x880C7888;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r5,40
	ctx.r5.s64 = 40;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880C78AC;
	sub_88096BC8(ctx, base);
	// addi r11,r31,6308
	ctx.r11.s64 = ctx.r31.s64 + 6308;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r8,6372(r31)
	PPC_STORE_U32(ctx.r31.u32 + 6372, ctx.r8.u32);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// stw r10,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// addi r7,r31,6644
	ctx.r7.s64 = ctx.r31.s64 + 6644;
	// stw r10,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// addi r6,r31,6728
	ctx.r6.s64 = ctx.r31.s64 + 6728;
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// stw r7,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r7.u32);
	// lis r5,-30708
	ctx.r5.s64 = -2012479488;
	// stw r6,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r6.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r11,16(r9)
	PPC_STORE_U32(ctx.r9.u32 + 16, ctx.r11.u32);
	// addi r5,r5,28416
	ctx.r5.s64 = ctx.r5.s64 + 28416;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096c60
	ctx.lr = 0x880C78FC;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C7908"))) PPC_WEAK_FUNC(sub_880C7908);
PPC_FUNC_IMPL(__imp__sub_880C7908) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x880C7910;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r5,40
	ctx.r5.s64 = 40;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880C7934;
	sub_88096BC8(ctx, base);
	// addi r11,r31,6224
	ctx.r11.s64 = ctx.r31.s64 + 6224;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r8,6288(r31)
	PPC_STORE_U32(ctx.r31.u32 + 6288, ctx.r8.u32);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// stw r10,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// addi r7,r31,6476
	ctx.r7.s64 = ctx.r31.s64 + 6476;
	// stw r10,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// addi r6,r31,6560
	ctx.r6.s64 = ctx.r31.s64 + 6560;
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// stw r7,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r7.u32);
	// lis r5,-30708
	ctx.r5.s64 = -2012479488;
	// stw r6,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r6.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r11,16(r9)
	PPC_STORE_U32(ctx.r9.u32 + 16, ctx.r11.u32);
	// addi r5,r5,28416
	ctx.r5.s64 = ctx.r5.s64 + 28416;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096c60
	ctx.lr = 0x880C7984;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C7990"))) PPC_WEAK_FUNC(sub_880C7990);
PPC_FUNC_IMPL(__imp__sub_880C7990) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880C7998;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r30,2304(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,36
	ctx.r5.s64 = 36;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880C79B8;
	sub_88096BC8(ctx, base);
	// addi r11,r30,7988
	ctx.r11.s64 = ctx.r30.s64 + 7988;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// lwz r9,8036(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8036);
	// cmpwi cr6,r9,256
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 256, ctx.xer);
	// bne cr6,0x880c79d8
	if (!ctx.cr6.eq) goto loc_880C79D8;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
	// b 0x880c79e0
	goto loc_880C79E0;
loc_880C79D8:
	// li r9,3
	ctx.r9.s64 = 3;
	// stw r9,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r9.u32);
loc_880C79E0:
	// li r11,4
	ctx.r11.s64 = 4;
	// li r9,256
	ctx.r9.s64 = 256;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// lis r8,-30708
	ctx.r8.s64 = -2012479488;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r9,56(r30)
	PPC_STORE_U32(ctx.r30.u32 + 56, ctx.r9.u32);
	// addi r4,r8,29976
	ctx.r4.s64 = ctx.r8.s64 + 29976;
	// stw r10,60(r30)
	PPC_STORE_U32(ctx.r30.u32 + 60, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096cb8
	ctx.lr = 0x880C7A0C;
	sub_88096CB8(ctx, base);
	// lis r7,-30708
	ctx.r7.s64 = -2012479488;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r5,r7,28704
	ctx.r5.s64 = ctx.r7.s64 + 28704;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096c60
	ctx.lr = 0x880C7A20;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C7A2C"))) PPC_WEAK_FUNC(sub_880C7A2C);
PPC_FUNC_IMPL(__imp__sub_880C7A2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C7A30"))) PPC_WEAK_FUNC(sub_880C7A30);
PPC_FUNC_IMPL(__imp__sub_880C7A30) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880C7A38;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r5,36
	ctx.r5.s64 = 36;
	// bl 0x88096bc8
	ctx.lr = 0x880C7A58;
	sub_88096BC8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r11,r31,7988
	ctx.r11.s64 = ctx.r31.s64 + 7988;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r8,8052(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8052, ctx.r8.u32);
	// lis r7,-30708
	ctx.r7.s64 = -2012479488;
	// stw r10,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r7,30072
	ctx.r4.s64 = ctx.r7.s64 + 30072;
	// bl 0x88096cb8
	ctx.lr = 0x880C7A8C;
	sub_88096CB8(ctx, base);
	// lis r6,-30708
	ctx.r6.s64 = -2012479488;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r5,r6,28936
	ctx.r5.s64 = ctx.r6.s64 + 28936;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096c60
	ctx.lr = 0x880C7AA0;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C7AAC"))) PPC_WEAK_FUNC(sub_880C7AAC);
PPC_FUNC_IMPL(__imp__sub_880C7AAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C7AB0"))) PPC_WEAK_FUNC(sub_880C7AB0);
PPC_FUNC_IMPL(__imp__sub_880C7AB0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071124
	ctx.lr = 0x880C7AB8;
	__savegprlr_15(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30681
	ctx.r11.s64 = -2010710016;
	// lis r30,-30671
	ctx.r30.s64 = -2010054656;
	// addi r17,r11,-18856
	ctx.r17.s64 = ctx.r11.s64 + -18856;
	// lis r10,16838
	ctx.r10.s64 = 1103495168;
	// lis r9,-3856
	ctx.r9.s64 = -252706816;
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// lwz r29,4200(r30)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4200);
	// mr r20,r3
	ctx.r20.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r15,r5
	ctx.r15.u64 = ctx.r5.u64;
	// li r21,0
	ctx.r21.s64 = 0;
	// addi r31,r17,12
	ctx.r31.s64 = ctx.r17.s64 + 12;
	// ori r28,r10,20077
	ctx.r28.u64 = ctx.r10.u64 | 20077;
	// ori r22,r9,61681
	ctx.r22.u64 = ctx.r9.u64 | 61681;
	// li r18,3
	ctx.r18.s64 = 3;
	// li r16,112
	ctx.r16.s64 = 112;
	// lis r26,-30667
	ctx.r26.s64 = -2009792512;
	// lis r25,-30667
	ctx.r25.s64 = -2009792512;
	// lis r24,-30667
	ctx.r24.s64 = -2009792512;
	// lis r23,-30667
	ctx.r23.s64 = -2009792512;
	// addi r19,r11,9552
	ctx.r19.s64 = ctx.r11.s64 + 9552;
loc_880C7B10:
	// lwz r10,-4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -4);
	// cmpwi cr6,r21,0
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,4(r20)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r20.u32 + 4);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r3,-12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -12);
	// add r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stw r11,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r10.u32);
	// stw r3,12380(r23)
	PPC_STORE_U32(ctx.r23.u32 + 12380, ctx.r3.u32);
	// bne cr6,0x880c7b4c
	if (!ctx.cr6.eq) goto loc_880C7B4C;
	// addi r4,r27,-1
	ctx.r4.s64 = ctx.r27.s64 + -1;
	// stw r4,12376(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12376, ctx.r4.u32);
	// b 0x880c7b54
	goto loc_880C7B54;
loc_880C7B4C:
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// stw r27,12376(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12376, ctx.r27.u32);
loc_880C7B54:
	// bl 0x880f52c8
	ctx.lr = 0x880C7B58;
	sub_880F52C8(ctx, base);
	// mullw r10,r29,r28
	ctx.r10.s64 = int64_t(ctx.r29.s32) * int64_t(ctx.r28.s32);
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r8,r10,12345
	ctx.r8.s64 = ctx.r10.s64 + 12345;
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// stw r8,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r8.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// lhz r7,4200(r30)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4200);
	// mulhwu r6,r7,r22
	ctx.r6.u64 = (uint64_t(ctx.r7.u32) * uint64_t(ctx.r22.u32)) >> 32;
	// rlwinm r11,r6,28,4,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 28) & 0xFFFFFFF;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r9,r11,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r5,r9,r11
	ctx.r5.u64 = ctx.r9.u64 + ctx.r11.u64;
	// subf r4,r5,r7
	ctx.r4.s64 = ctx.r7.s64 - ctx.r5.s64;
	// extsh r11,r4
	ctx.r11.s64 = ctx.r4.s16;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// beq cr6,0x880c7bec
	if (ctx.cr6.eq) goto loc_880C7BEC;
	// lwz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// clrlwi r9,r11,23
	ctx.r9.u64 = ctx.r11.u32 & 0x1FF;
	// stw r11,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, ctx.r11.u32);
	// addic. r10,r3,40
	ctx.xer.ca = ctx.r3.u32 > 4294967255;
	ctx.r10.s64 = ctx.r3.s64 + 40;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// rlwinm r6,r7,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r7,r3,36
	ctx.r7.s64 = ctx.r3.s64 + 36;
	// divw r5,r6,r18
	ctx.r5.s32 = ppc_divw(ctx.r6.s32, ctx.r18.s32);
	// stw r5,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, ctx.r5.u32);
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// beq 0x880c7bd4
	if (ctx.cr0.eq) goto loc_880C7BD4;
	// addi r6,r9,128
	ctx.r6.s64 = ctx.r9.s64 + 128;
	// rlwinm r5,r6,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// lwzx r4,r5,r19
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r19.u32);
	// mullw r6,r4,r11
	ctx.r6.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r11.s32);
	// stw r6,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r6.u32);
loc_880C7BD4:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x880c7bec
	if (ctx.cr6.eq) goto loc_880C7BEC;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r19
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r19.u32);
	// mullw r6,r9,r11
	ctx.r6.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// stw r6,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r6.u32);
loc_880C7BEC:
	// cmpwi cr6,r21,0
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// ble cr6,0x880c7c1c
	if (!ctx.cr6.gt) goto loc_880C7C1C;
	// mullw r11,r8,r28
	ctx.r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r28.s32);
	// addi r8,r11,12345
	ctx.r8.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r8,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r8.u32);
	// beq cr6,0x880c7c2c
	if (ctx.cr6.eq) goto loc_880C7C2C;
	// lhz r11,4200(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4200);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// rlwinm r11,r11,1,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x2;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r11,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r11.u32);
loc_880C7C1C:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c7c2c
	if (ctx.cr6.eq) goto loc_880C7C2C;
	// stw r15,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r15.u32);
	// stw r16,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r16.u32);
loc_880C7C2C:
	// mullw r11,r8,r28
	ctx.r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r28.s32);
	// addi r29,r11,12345
	ctx.r29.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r29,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r29.u32);
	// beq cr6,0x880c7c60
	if (ctx.cr6.eq) goto loc_880C7C60;
	// lhz r11,4200(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4200);
	// addi r10,r17,-16
	ctx.r10.s64 = ctx.r17.s64 + -16;
	// rlwinm r9,r11,2,28,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,148(r3)
	PPC_STORE_U32(ctx.r3.u32 + 148, ctx.r8.u32);
	// lwz r7,-8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + -8);
	// clrlwi r6,r7,16
	ctx.r6.u64 = ctx.r7.u32 & 0xFFFF;
	// stw r6,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r6.u32);
loc_880C7C60:
	// addi r21,r21,1
	ctx.r21.s64 = ctx.r21.s64 + 1;
	// addi r31,r31,36
	ctx.r31.s64 = ctx.r31.s64 + 36;
	// cmplwi cr6,r21,5
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 5, ctx.xer);
	// blt cr6,0x880c7b10
	if (ctx.cr6.lt) goto loc_880C7B10;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071174
	__restgprlr_15(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C7C78"))) PPC_WEAK_FUNC(sub_880C7C78);
PPC_FUNC_IMPL(__imp__sub_880C7C78) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// cmpw cr6,r10,r4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r4.s32, ctx.xer);
	// bne cr6,0x880c7c94
	if (!ctx.cr6.eq) goto loc_880C7C94;
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 72);
	// cmpw cr6,r10,r5
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r5.s32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
loc_880C7C94:
	// lis r10,-30708
	ctx.r10.s64 = -2012479488;
	// stw r4,68(r11)
	PPC_STORE_U32(ctx.r11.u32 + 68, ctx.r4.u32);
	// stw r5,72(r11)
	PPC_STORE_U32(ctx.r11.u32 + 72, ctx.r5.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,24(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// addi r4,r10,30168
	ctx.r4.s64 = ctx.r10.s64 + 30168;
	// b 0x88096cb8
	sub_88096CB8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C7CB0"))) PPC_WEAK_FUNC(sub_880C7CB0);
PPC_FUNC_IMPL(__imp__sub_880C7CB0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880C7CB4"))) PPC_WEAK_FUNC(sub_880C7CB4);
PPC_FUNC_IMPL(__imp__sub_880C7CB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C7CB8"))) PPC_WEAK_FUNC(sub_880C7CB8);
PPC_FUNC_IMPL(__imp__sub_880C7CB8) {
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
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mulli r10,r4,84
	ctx.r10.s64 = ctx.r4.s64 * 84;
	// lwz r8,184(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// lwz r9,168(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// lwz r5,32(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r4,r8,r9
	ctx.r4.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r10,r11,7484
	ctx.r10.s64 = ctx.r11.s64 + 7484;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r10,7500(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 7500);
	// lwz r9,7496(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 7496);
	// addis r8,r10,4
	ctx.r8.s64 = ctx.r10.s64 + 262144;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x880c7ab0
	ctx.lr = 0x880C7D00;
	sub_880C7AB0(ctx, base);
	// lis r7,-30667
	ctx.r7.s64 = -2009792512;
	// lis r6,-30667
	ctx.r6.s64 = -2009792512;
	// li r11,16
	ctx.r11.s64 = 16;
	// li r10,11
	ctx.r10.s64 = 11;
	// lis r5,-30667
	ctx.r5.s64 = -2009792512;
	// stw r11,12380(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12380, ctx.r11.u32);
	// lis r9,-30667
	ctx.r9.s64 = -2009792512;
	// stw r10,12376(r6)
	PPC_STORE_U32(ctx.r6.u32 + 12376, ctx.r10.u32);
	// li r4,11
	ctx.r4.s64 = 11;
	// li r3,16
	ctx.r3.s64 = 16;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r11,12364(r5)
	PPC_STORE_U32(ctx.r5.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12372, ctx.r10.u32);
	// bl 0x880f8798
	ctx.lr = 0x880C7D3C;
	sub_880F8798(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c7d4c
	if (ctx.cr6.eq) goto loc_880C7D4C;
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,24(r3)
	PPC_STORE_U8(ctx.r3.u32 + 24, ctx.r11.u8);
loc_880C7D4C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880C7D5C"))) PPC_WEAK_FUNC(sub_880C7D5C);
PPC_FUNC_IMPL(__imp__sub_880C7D5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C7D60"))) PPC_WEAK_FUNC(sub_880C7D60);
PPC_FUNC_IMPL(__imp__sub_880C7D60) {
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
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r8,255
	ctx.r8.s64 = 16711680;
	// li r7,255
	ctx.r7.s64 = 255;
	// ori r6,r8,65535
	ctx.r6.u64 = ctx.r8.u64 | 65535;
	// addi r10,r11,9028
	ctx.r10.s64 = ctx.r11.s64 + 9028;
	// addi r9,r11,9032
	ctx.r9.s64 = ctx.r11.s64 + 9032;
	// stw r6,9032(r11)
	PPC_STORE_U32(ctx.r11.u32 + 9032, ctx.r6.u32);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// lis r5,-30708
	ctx.r5.s64 = -2012479488;
	// stw r7,9028(r11)
	PPC_STORE_U32(ctx.r11.u32 + 9028, ctx.r7.u32);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r5,21600
	ctx.r5.s64 = ctx.r5.s64 + 21600;
	// li r4,30
	ctx.r4.s64 = 30;
	// bl 0x88096460
	ctx.lr = 0x880C7DBC;
	sub_88096460(ctx, base);
	// lis r4,-30641
	ctx.r4.s64 = -2008088576;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r10,r4,-18876
	ctx.r10.s64 = ctx.r4.s64 + -18876;
	// lis r9,-30708
	ctx.r9.s64 = -2012479488;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r9,29152
	ctx.r5.s64 = ctx.r9.s64 + 29152;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// bl 0x88096c60
	ctx.lr = 0x880C7DE0;
	sub_88096C60(ctx, base);
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

__attribute__((alias("__imp__sub_880C7DFC"))) PPC_WEAK_FUNC(sub_880C7DFC);
PPC_FUNC_IMPL(__imp__sub_880C7DFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C7E00"))) PPC_WEAK_FUNC(sub_880C7E00);
PPC_FUNC_IMPL(__imp__sub_880C7E00) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071128
	ctx.lr = 0x880C7E08;
	__savegprlr_16(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r18,r4
	ctx.r18.u64 = ctx.r4.u64;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r17,r5
	ctx.r17.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880C7E28;
	sub_88096BC8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,8(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// li r16,0
	ctx.r16.s64 = 0;
	// li r19,2
	ctx.r19.s64 = 2;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x880c7e54
	if (ctx.cr6.lt) goto loc_880C7E54;
	// beq cr6,0x880c7e80
	if (ctx.cr6.eq) goto loc_880C7E80;
loc_880C7E48:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071178
	__restgprlr_16(ctx, base);
	return;
loc_880C7E54:
	// lwz r10,4(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,60(r10)
	PPC_STORE_U32(ctx.r10.u32 + 60, ctx.r11.u32);
	// lwz r9,4(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// stw r11,68(r9)
	PPC_STORE_U32(ctx.r9.u32 + 68, ctx.r11.u32);
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// stw r16,16(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16, ctx.r16.u32);
	// stw r19,20(r28)
	PPC_STORE_U32(ctx.r28.u32 + 20, ctx.r19.u32);
	// stw r16,24(r28)
	PPC_STORE_U32(ctx.r28.u32 + 24, ctx.r16.u32);
	// stw r8,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r8.u32);
loc_880C7E80:
	// lwz r11,16(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,16(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16, ctx.r11.u32);
	// bge 0x880c7e48
	if (!ctx.cr0.lt) goto loc_880C7E48;
	// lwz r11,24(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 24);
	// lis r9,-30681
	ctx.r9.s64 = -2010710016;
	// lwz r8,20(r28)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r28.u32 + 20);
	// lis r25,-30667
	ctx.r25.s64 = -2009792512;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r7,4(r28)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// addi r9,r9,-18168
	ctx.r9.s64 = ctx.r9.s64 + -18168;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lis r24,-30667
	ctx.r24.s64 = -2009792512;
	// rlwinm r11,r5,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,16(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16, ctx.r8.u32);
	// lwz r8,12(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// addi r29,r6,1
	ctx.r29.s64 = ctx.r6.s64 + 1;
	// add r30,r11,r9
	ctx.r30.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r7,16(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lis r21,-30667
	ctx.r21.s64 = -2009792512;
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// add r27,r8,r11
	ctx.r27.u64 = ctx.r8.u64 + ctx.r11.u64;
	// add r26,r7,r10
	ctx.r26.u64 = ctx.r7.u64 + ctx.r10.u64;
	// stw r27,12364(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12364, ctx.r27.u32);
	// stw r26,12372(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12372, ctx.r26.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880C7EF4;
	sub_880F52C8(ctx, base);
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x881534c8
	ctx.lr = 0x880C7F00;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,16
	ctx.r3.s64 = 16;
	// addi r22,r11,240
	ctx.r22.s64 = ctx.r11.s64 + 240;
	// bl 0x881534c8
	ctx.lr = 0x880C7F10;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// addi r4,r11,72
	ctx.r4.s64 = ctx.r11.s64 + 72;
	// mr r5,r22
	ctx.r5.u64 = ctx.r22.u64;
	// rlwinm r4,r4,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// bl 0x880f5570
	ctx.lr = 0x880C7F28;
	sub_880F5570(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// lwz r8,9084(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9084);
	// lwz r7,9080(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9080);
	// lwz r6,9076(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9076);
	// lwz r5,9072(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9072);
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// bl 0x880f5438
	ctx.lr = 0x880C7F48;
	sub_880F5438(ctx, base);
	// stw r27,12364(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12364, ctx.r27.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r26,12372(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12372, ctx.r26.u32);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lis r20,-30667
	ctx.r20.s64 = -2009792512;
	// bl 0x880f52c8
	ctx.lr = 0x880C7F64;
	sub_880F52C8(ctx, base);
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c7f74
	if (ctx.cr6.eq) goto loc_880C7F74;
	// stw r19,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r19.u32);
loc_880C7F74:
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x881534c8
	ctx.lr = 0x880C7F7C;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,32
	ctx.r3.s64 = 32;
	// addi r11,r11,72
	ctx.r11.s64 = ctx.r11.s64 + 72;
	// rlwinm r19,r11,1,0,30
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// bl 0x881534c8
	ctx.lr = 0x880C7F90;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// mr r4,r19
	ctx.r4.u64 = ctx.r19.u64;
	// add r11,r11,r22
	ctx.r11.u64 = ctx.r11.u64 + ctx.r22.u64;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// addi r5,r11,-16
	ctx.r5.s64 = ctx.r11.s64 + -16;
	// bl 0x880f5570
	ctx.lr = 0x880C7FA8;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x880c7fc4
	if (ctx.cr6.eq) goto loc_880C7FC4;
	// li r11,112
	ctx.r11.s64 = 112;
	// stw r11,140(r23)
	PPC_STORE_U32(ctx.r23.u32 + 140, ctx.r11.u32);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// clrlwi r9,r10,16
	ctx.r9.u64 = ctx.r10.u32 & 0xFFFF;
	// stw r9,100(r23)
	PPC_STORE_U32(ctx.r23.u32 + 100, ctx.r9.u32);
loc_880C7FC4:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// lwz r8,9084(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9084);
	// lwz r7,9080(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9080);
	// lwz r6,9076(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9076);
	// lwz r5,9072(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9072);
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// bl 0x880f5438
	ctx.lr = 0x880C7FE4;
	sub_880F5438(ctx, base);
	// stw r27,12364(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12364, ctx.r27.u32);
	// li r11,24
	ctx.r11.s64 = 24;
	// stw r26,12372(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12372, ctx.r26.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,12380(r21)
	PPC_STORE_U32(ctx.r21.u32 + 12380, ctx.r11.u32);
	// bl 0x880f34b0
	ctx.lr = 0x880C8000;
	sub_880F34B0(ctx, base);
	// lis r31,-30671
	ctx.r31.s64 = -2010054656;
	// lis r10,16838
	ctx.r10.s64 = 1103495168;
	// lis r9,-1009
	ctx.r9.s64 = -66125824;
	// ori r30,r10,20077
	ctx.r30.u64 = ctx.r10.u64 | 20077;
	// ori r27,r9,49405
	ctx.r27.u64 = ctx.r9.u64 | 49405;
	// lwz r11,4200(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4200);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// mullw r11,r11,r30
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// addi r26,r11,12345
	ctx.r26.s64 = ctx.r11.s64 + 12345;
	// stw r26,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r26.u32);
	// beq cr6,0x880c8054
	if (ctx.cr6.eq) goto loc_880C8054;
	// lhz r9,4200(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// mulhwu r8,r9,r27
	ctx.r8.u64 = (uint64_t(ctx.r9.u32) * uint64_t(ctx.r27.u32)) >> 32;
	// rlwinm r11,r8,26,6,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 26) & 0x3FFFFFF;
	// rlwinm r10,r11,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r6,r7,r9
	ctx.r6.s64 = ctx.r9.s64 - ctx.r7.s64;
	// extsh r11,r6
	ctx.r11.s64 = ctx.r6.s16;
	// add r11,r11,r22
	ctx.r11.u64 = ctx.r11.u64 + ctx.r22.u64;
	// addi r4,r11,-32
	ctx.r4.s64 = ctx.r11.s64 + -32;
	// sth r4,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, ctx.r4.u16);
loc_880C8054:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x880f34b0
	ctx.lr = 0x880C8060;
	sub_880F34B0(ctx, base);
	// mullw r11,r26,r30
	ctx.r11.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r30.s32);
	// addi r26,r11,12345
	ctx.r26.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r26,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r26.u32);
	// beq cr6,0x880c809c
	if (ctx.cr6.eq) goto loc_880C809C;
	// lhz r9,4200(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// mulhwu r8,r9,r27
	ctx.r8.u64 = (uint64_t(ctx.r9.u32) * uint64_t(ctx.r27.u32)) >> 32;
	// rlwinm r11,r8,26,6,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 26) & 0x3FFFFFF;
	// rlwinm r10,r11,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r6,r7,r9
	ctx.r6.s64 = ctx.r9.s64 - ctx.r7.s64;
	// extsh r11,r6
	ctx.r11.s64 = ctx.r6.s16;
	// add r11,r11,r22
	ctx.r11.u64 = ctx.r11.u64 + ctx.r22.u64;
	// addi r4,r11,-32
	ctx.r4.s64 = ctx.r11.s64 + -32;
	// sth r4,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, ctx.r4.u16);
loc_880C809C:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r29,12376(r20)
	PPC_STORE_U32(ctx.r20.u32 + 12376, ctx.r29.u32);
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x880f34b0
	ctx.lr = 0x880C80AC;
	sub_880F34B0(ctx, base);
	// mullw r11,r26,r30
	ctx.r11.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r30.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r11,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r11.u32);
	// beq cr6,0x880c80e8
	if (ctx.cr6.eq) goto loc_880C80E8;
	// lhz r9,4200(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// mulhwu r8,r9,r27
	ctx.r8.u64 = (uint64_t(ctx.r9.u32) * uint64_t(ctx.r27.u32)) >> 32;
	// rlwinm r11,r8,26,6,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 26) & 0x3FFFFFF;
	// rlwinm r10,r11,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r6,r7,r9
	ctx.r6.s64 = ctx.r9.s64 - ctx.r7.s64;
	// extsh r11,r6
	ctx.r11.s64 = ctx.r6.s16;
	// add r11,r11,r22
	ctx.r11.u64 = ctx.r11.u64 + ctx.r22.u64;
	// addi r4,r11,-32
	ctx.r4.s64 = ctx.r11.s64 + -32;
	// sth r4,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, ctx.r4.u16);
loc_880C80E8:
	// lwz r11,24(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 24);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,24(r28)
	PPC_STORE_U32(ctx.r28.u32 + 24, ctx.r11.u32);
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// blt cr6,0x880c7e48
	if (ctx.cr6.lt) goto loc_880C7E48;
	// stw r16,24(r28)
	PPC_STORE_U32(ctx.r28.u32 + 24, ctx.r16.u32);
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// bl 0x88096b40
	ctx.lr = 0x880C810C;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071178
	__restgprlr_16(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C8118"))) PPC_WEAK_FUNC(sub_880C8118);
PPC_FUNC_IMPL(__imp__sub_880C8118) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x880C8120;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r5,56
	ctx.r5.s64 = 56;
	// bl 0x88096bc8
	ctx.lr = 0x880C8144;
	sub_88096BC8(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r31,7988
	ctx.r7.s64 = ctx.r31.s64 + 7988;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r6,33
	ctx.r6.s64 = 33;
	// lwz r10,184(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 184);
	// li r5,60
	ctx.r5.s64 = 60;
	// lwz r11,168(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 168);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r11,r11,3
	ctx.r11.s64 = ctx.r11.s64 + 3;
	// li r4,94
	ctx.r4.s64 = 94;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r11.u32);
	// li r3,5
	ctx.r3.s64 = 5;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// stw r10,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r10.u32);
	// bl 0x880e32d0
	ctx.lr = 0x880C8188;
	sub_880E32D0(ctx, base);
	// lis r9,-30708
	ctx.r9.s64 = -2012479488;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r5,r9,32256
	ctx.r5.s64 = ctx.r9.s64 + 32256;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88096c60
	ctx.lr = 0x880C819C;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C81A8"))) PPC_WEAK_FUNC(sub_880C81A8);
PPC_FUNC_IMPL(__imp__sub_880C81A8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r10,112(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 112);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// blt cr6,0x880c8200
	if (ctx.cr6.lt) goto loc_880C8200;
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lwz r10,956(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 956);
	// lwz r9,960(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 960);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// stw r10,956(r11)
	PPC_STORE_U32(ctx.r11.u32 + 956, ctx.r10.u32);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// ble cr6,0x880c81d8
	if (!ctx.cr6.gt) goto loc_880C81D8;
	// stw r9,956(r11)
	PPC_STORE_U32(ctx.r11.u32 + 956, ctx.r9.u32);
loc_880C81D8:
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 60);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,60(r11)
	PPC_STORE_U32(ctx.r11.u32 + 60, ctx.r10.u32);
	// bgelr 
	if (!ctx.cr0.lt) return;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 52);
	// lwz r9,64(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r8.u32);
	// stw r9,60(r11)
	PPC_STORE_U32(ctx.r11.u32 + 60, ctx.r9.u32);
	// blr 
	return;
loc_880C8200:
	// lwz r10,956(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 956);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r9,960(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 960);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// stw r10,956(r11)
	PPC_STORE_U32(ctx.r11.u32 + 956, ctx.r10.u32);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// ble cr6,0x880c8224
	if (!ctx.cr6.gt) goto loc_880C8224;
	// stw r9,956(r11)
	PPC_STORE_U32(ctx.r11.u32 + 956, ctx.r9.u32);
	// stw r8,112(r11)
	PPC_STORE_U32(ctx.r11.u32 + 112, ctx.r8.u32);
loc_880C8224:
	// lwz r10,964(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 964);
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// beq cr6,0x880c824c
	if (ctx.cr6.eq) goto loc_880C824C;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 52);
	// lwz r9,56(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 56);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r10.u32);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// ble cr6,0x880c824c
	if (!ctx.cr6.gt) goto loc_880C824C;
	// stw r9,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r9.u32);
loc_880C824C:
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// stw r8,112(r11)
	PPC_STORE_U32(ctx.r11.u32 + 112, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880C8260"))) PPC_WEAK_FUNC(sub_880C8260);
PPC_FUNC_IMPL(__imp__sub_880C8260) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071144
	ctx.lr = 0x880C8268;
	__savegprlr_23(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r25,2304(r3)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// lwz r11,88(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 88);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880c838c
	if (ctx.cr6.eq) goto loc_880C838C;
	// lwz r11,80(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 80);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,80(r25)
	PPC_STORE_U32(ctx.r25.u32 + 80, ctx.r11.u32);
	// bge 0x880c83b8
	if (!ctx.cr0.lt) goto loc_880C83B8;
	// lwz r11,84(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 84);
	// addi r27,r25,168
	ctx.r27.s64 = ctx.r25.s64 + 168;
	// li r23,16
	ctx.r23.s64 = 16;
	// li r28,0
	ctx.r28.s64 = 0;
	// stw r11,80(r25)
	PPC_STORE_U32(ctx.r25.u32 + 80, ctx.r11.u32);
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r24,26276(r11)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
loc_880C82AC:
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880c836c
	if (ctx.cr6.eq) goto loc_880C836C;
	// lwz r31,16(r27)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r27.u32 + 16);
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// lwz r30,20(r27)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r27.u32 + 20);
	// lwz r29,4(r27)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// bne cr6,0x880c8328
	if (!ctx.cr6.eq) goto loc_880C8328;
	// clrlwi r7,r29,16
	ctx.r7.u64 = ctx.r29.u32 & 0xFFFF;
	// stw r26,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r26.u32);
	// li r6,-20
	ctx.r6.s64 = -20;
	// sth r28,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r28.u16);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,27
	ctx.r3.s64 = 27;
	// bl 0x8815c948
	ctx.lr = 0x880C82EC;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x880C82F4;
	sub_8815C860(ctx, base);
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// bne cr6,0x880c8328
	if (!ctx.cr6.eq) goto loc_880C8328;
	// addi r11,r29,32
	ctx.r11.s64 = ctx.r29.s64 + 32;
	// stw r26,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r26.u32);
	// li r6,-24
	ctx.r6.s64 = -24;
	// sth r28,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r28.u16);
	// clrlwi r7,r11,16
	ctx.r7.u64 = ctx.r11.u32 & 0xFFFF;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,27
	ctx.r3.s64 = 27;
	// bl 0x8815c948
	ctx.lr = 0x880C8320;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x880C8328;
	sub_8815C860(ctx, base);
loc_880C8328:
	// lwz r11,96(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 96);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880c836c
	if (ctx.cr6.eq) goto loc_880C836C;
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// bne cr6,0x880c836c
	if (!ctx.cr6.eq) goto loc_880C836C;
	// addi r11,r29,256
	ctx.r11.s64 = ctx.r29.s64 + 256;
	// stw r26,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r26.u32);
	// li r6,-28
	ctx.r6.s64 = -28;
	// sth r28,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r28.u16);
	// clrlwi r7,r11,16
	ctx.r7.u64 = ctx.r11.u32 & 0xFFFF;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,55
	ctx.r3.s64 = 55;
	// bl 0x8815c948
	ctx.lr = 0x880C8364;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x880C836C;
	sub_8815C860(ctx, base);
loc_880C836C:
	// addic. r23,r23,-1
	ctx.xer.ca = ctx.r23.u32 > 0;
	ctx.r23.s64 = ctx.r23.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// addi r27,r27,48
	ctx.r27.s64 = ctx.r27.s64 + 48;
	// bne 0x880c82ac
	if (!ctx.cr0.eq) goto loc_880C82AC;
	// lwz r11,96(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 96);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,96(r25)
	PPC_STORE_U32(ctx.r25.u32 + 96, ctx.r11.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
loc_880C838C:
	// lwz r11,52(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 52);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880c83b8
	if (ctx.cr6.eq) goto loc_880C83B8;
	// lwz r11,72(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 72);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,72(r25)
	PPC_STORE_U32(ctx.r25.u32 + 72, ctx.r11.u32);
	// bge 0x880c83b8
	if (!ctx.cr0.lt) goto loc_880C83B8;
	// lwz r11,76(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 76);
	// lwz r10,92(r25)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r25.u32 + 92);
	// stw r11,72(r25)
	PPC_STORE_U32(ctx.r25.u32 + 72, ctx.r11.u32);
	// stw r10,88(r25)
	PPC_STORE_U32(ctx.r25.u32 + 88, ctx.r10.u32);
loc_880C83B8:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C83C0"))) PPC_WEAK_FUNC(sub_880C83C0);
PPC_FUNC_IMPL(__imp__sub_880C83C0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x880C83C8;
	__savegprlr_25(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880c8498
	if (ctx.cr6.eq) goto loc_880C8498;
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
	// bge 0x880c84b8
	if (!ctx.cr0.lt) goto loc_880C84B8;
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r30,r31,168
	ctx.r30.s64 = ctx.r31.s64 + 168;
	// li r25,16
	ctx.r25.s64 = 16;
	// li r29,0
	ctx.r29.s64 = 0;
	// ori r27,r10,65408
	ctx.r27.u64 = ctx.r10.u64 | 65408;
	// stw r11,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r26,26276(r11)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
loc_880C8414:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880c8484
	if (ctx.cr6.eq) goto loc_880C8484;
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r10,948(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 948);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// lwz r4,16(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r5,20(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// rlwinm r11,r9,0,23,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1FE;
	// lwz r10,972(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 972);
	// lwz r9,976(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 976);
	// ble cr6,0x880c8458
	if (!ctx.cr6.gt) goto loc_880C8458;
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// bne cr6,0x880c8484
	if (!ctx.cr6.eq) goto loc_880C8484;
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// b 0x880c8464
	goto loc_880C8464;
loc_880C8458:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// bne cr6,0x880c8484
	if (!ctx.cr6.eq) goto loc_880C8484;
	// add r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
loc_880C8464:
	// clrlwi r7,r11,16
	ctx.r7.u64 = ctx.r11.u32 & 0xFFFF;
	// sth r29,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r29.u16);
	// extsh r6,r9
	ctx.r6.s64 = ctx.r9.s16;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// clrlwi r3,r10,24
	ctx.r3.u64 = ctx.r10.u32 & 0xFF;
	// bl 0x8815c948
	ctx.lr = 0x880C847C;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x880C8484;
	sub_8815C860(ctx, base);
loc_880C8484:
	// addic. r25,r25,-1
	ctx.xer.ca = ctx.r25.u32 > 0;
	ctx.r25.s64 = ctx.r25.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// addi r30,r30,48
	ctx.r30.s64 = ctx.r30.s64 + 48;
	// bne 0x880c8414
	if (!ctx.cr0.eq) goto loc_880C8414;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_880C8498:
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// bge 0x880c84b8
	if (!ctx.cr0.lt) goto loc_880C84B8;
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// lwz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// stw r11,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// stw r10,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r10.u32);
loc_880C84B8:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C84C0"))) PPC_WEAK_FUNC(sub_880C84C0);
PPC_FUNC_IMPL(__imp__sub_880C84C0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r9,124(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 124);
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

__attribute__((alias("__imp__sub_880C8500"))) PPC_WEAK_FUNC(sub_880C8500);
PPC_FUNC_IMPL(__imp__sub_880C8500) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r11,124(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 124);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880c8518
	if (ctx.cr6.eq) goto loc_880C8518;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
loc_880C8518:
	// b 0x88094220
	sub_88094220(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C851C"))) PPC_WEAK_FUNC(sub_880C851C);
PPC_FUNC_IMPL(__imp__sub_880C851C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C8520"))) PPC_WEAK_FUNC(sub_880C8520);
PPC_FUNC_IMPL(__imp__sub_880C8520) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071138
	ctx.lr = 0x880C8528;
	__savegprlr_20(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r11,168(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// lwz r10,184(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// add r26,r10,r11
	ctx.r26.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r11,136(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 136);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// stw r11,136(r29)
	PPC_STORE_U32(ctx.r29.u32 + 136, ctx.r11.u32);
	// cmpwi cr6,r11,160
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 160, ctx.xer);
	// ble cr6,0x880c8558
	if (!ctx.cr6.gt) goto loc_880C8558;
	// li r11,160
	ctx.r11.s64 = 160;
	// stw r11,136(r29)
	PPC_STORE_U32(ctx.r29.u32 + 136, ctx.r11.u32);
loc_880C8558:
	// lwz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880c86bc
	if (!ctx.cr6.eq) goto loc_880C86BC;
	// lis r24,-30597
	ctx.r24.s64 = -2005204992;
	// lis r11,128
	ctx.r11.s64 = 8388608;
	// lis r10,128
	ctx.r10.s64 = 8388608;
	// addi r28,r29,196
	ctx.r28.s64 = ctx.r29.s64 + 196;
	// li r22,16
	ctx.r22.s64 = 16;
	// lwz r27,-11932(r24)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r24.u32 + -11932);
	// ori r23,r11,32896
	ctx.r23.u64 = ctx.r11.u64 | 32896;
	// li r20,0
	ctx.r20.s64 = 0;
	// ori r21,r10,128
	ctx.r21.u64 = ctx.r10.u64 | 128;
loc_880C8588:
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// mr r25,r23
	ctx.r25.u64 = ctx.r23.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880c85b8
	if (ctx.cr6.eq) goto loc_880C85B8;
	// lwz r11,4(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// stw r11,4(r28)
	PPC_STORE_U32(ctx.r28.u32 + 4, ctx.r11.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880c85b8
	if (ctx.cr6.eq) goto loc_880C85B8;
	// lis r25,192
	ctx.r25.s64 = 12582912;
	// ori r25,r25,49152
	ctx.r25.u64 = ctx.r25.u64 | 49152;
loc_880C85B8:
	// lwz r11,-28(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -28);
	// stw r20,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r20.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880c86ac
	if (ctx.cr6.eq) goto loc_880C86AC;
	// lwz r31,-12(r28)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r28.u32 + -12);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// lwz r30,-8(r28)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r28.u32 + -8);
	// li r3,403
	ctx.r3.s64 = 403;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// bl 0x881538c0
	ctx.lr = 0x880C85E4;
	sub_881538C0(ctx, base);
	// lwz r11,136(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 136);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c8610
	if (ctx.cr6.eq) goto loc_880C8610;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C8610:
	// cmpw cr6,r25,r23
	ctx.cr6.compare<int32_t>(ctx.r25.s32, ctx.r23.s32, ctx.xer);
	// bne cr6,0x880c8628
	if (!ctx.cr6.eq) goto loc_880C8628;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c8634
	if (ctx.cr6.eq) goto loc_880C8634;
	// stw r21,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r21.u32);
	// b 0x880c8634
	goto loc_880C8634;
loc_880C8628:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c8634
	if (ctx.cr6.eq) goto loc_880C8634;
	// stw r25,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r25.u32);
loc_880C8634:
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// cmpwi cr6,r11,50
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 50, ctx.xer);
	// bne cr6,0x880c8668
	if (!ctx.cr6.eq) goto loc_880C8668;
	// lwz r11,44(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 44);
	// addi r6,r26,1
	ctx.r6.s64 = ctx.r26.s64 + 1;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r11,17617
	ctx.r3.s64 = ctx.r11.s64 + 17617;
	// bl 0x881538c0
	ctx.lr = 0x880C8658;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c8668
	if (ctx.cr6.eq) goto loc_880C8668;
	// lwz r11,128(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 128);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880C8668:
	// addi r6,r26,1
	ctx.r6.s64 = ctx.r26.s64 + 1;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,396
	ctx.r3.s64 = 396;
	// bl 0x881538c0
	ctx.lr = 0x880C867C;
	sub_881538C0(ctx, base);
	// lwz r11,136(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 136);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880c86ac
	if (ctx.cr6.eq) goto loc_880C86AC;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// stw r25,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r25.u32);
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r27,-11932(r24)
	PPC_STORE_U32(ctx.r24.u32 + -11932, ctx.r27.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880C86AC:
	// addic. r22,r22,-1
	ctx.xer.ca = ctx.r22.u32 > 0;
	ctx.r22.s64 = ctx.r22.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// addi r28,r28,48
	ctx.r28.s64 = ctx.r28.s64 + 48;
	// bne 0x880c8588
	if (!ctx.cr0.eq) goto loc_880C8588;
	// stw r27,-11932(r24)
	PPC_STORE_U32(ctx.r24.u32 + -11932, ctx.r27.u32);
loc_880C86BC:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x88071188
	__restgprlr_20(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C86C4"))) PPC_WEAK_FUNC(sub_880C86C4);
PPC_FUNC_IMPL(__imp__sub_880C86C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C86C8"))) PPC_WEAK_FUNC(sub_880C86C8);
PPC_FUNC_IMPL(__imp__sub_880C86C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807113c
	ctx.lr = 0x880C86D0;
	__savegprlr_21(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r5)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r5.u32 + 2304);
	// mr r23,r4
	ctx.r23.u64 = ctx.r4.u64;
	// lwz r11,40(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 40);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r6,108(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// addis r3,r9,1
	ctx.r3.s64 = ctx.r9.s64 + 65536;
	// addi r3,r3,-30484
	ctx.r3.s64 = ctx.r3.s64 + -30484;
	// lwz r11,168(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 168);
	// lwz r10,184(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 184);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// add r29,r10,r11
	ctx.r29.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// rlwinm r9,r7,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addis r3,r7,1
	ctx.r3.s64 = ctx.r7.s64 + 65536;
	// add r11,r9,r31
	ctx.r11.u64 = ctx.r9.u64 + ctx.r31.u64;
	// addi r3,r3,-30480
	ctx.r3.s64 = ctx.r3.s64 + -30480;
	// addi r28,r11,168
	ctx.r28.s64 = ctx.r11.s64 + 168;
	// bl 0x88072260
	ctx.lr = 0x880C873C;
	sub_88072260(ctx, base);
	// lwz r11,24(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x880c89d0
	if (!ctx.cr6.gt) goto loc_880C89D0;
	// li r21,1
	ctx.r21.s64 = 1;
	// stw r21,28(r28)
	PPC_STORE_U32(ctx.r28.u32 + 28, ctx.r21.u32);
	// lwz r10,968(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 968);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x880c8768
	if (!ctx.cr6.eq) goto loc_880C8768;
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// stw r9,24(r28)
	PPC_STORE_U32(ctx.r28.u32 + 24, ctx.r9.u32);
loc_880C8768:
	// lwz r11,24(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt cr6,0x880c89d0
	if (ctx.cr6.gt) goto loc_880C89D0;
	// li r22,0
	ctx.r22.s64 = 0;
	// stw r22,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r22.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880c8790
	if (!ctx.cr6.eq) goto loc_880C8790;
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// b 0x880c8794
	goto loc_880C8794;
loc_880C8790:
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
loc_880C8794:
	// stw r11,980(r31)
	PPC_STORE_U32(ctx.r31.u32 + 980, ctx.r11.u32);
	// mr r10,r22
	ctx.r10.u64 = ctx.r22.u64;
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// stw r11,984(r31)
	PPC_STORE_U32(ctx.r31.u32 + 984, ctx.r11.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880c87b4
	if (ctx.cr6.eq) goto loc_880C87B4;
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
loc_880C87B4:
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880c87c8
	if (!ctx.cr6.eq) goto loc_880C87C8;
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// b 0x880c87cc
	goto loc_880C87CC;
loc_880C87C8:
	// lwz r11,164(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_880C87CC:
	// lwz r9,108(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// li r5,10
	ctx.r5.s64 = 10;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r10,2332(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2332, ctx.r10.u32);
	// stw r11,2328(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2328, ctx.r11.u32);
	// lwz r3,108(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// bl 0x88095178
	ctx.lr = 0x880C87E8;
	sub_88095178(ctx, base);
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,40
	ctx.r5.s64 = 40;
	// li r4,90
	ctx.r4.s64 = 90;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x880e3240
	ctx.lr = 0x880C87FC;
	sub_880E3240(ctx, base);
	// lis r25,-30667
	ctx.r25.s64 = -2009792512;
	// lis r24,-30667
	ctx.r24.s64 = -2009792512;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// li r3,20
	ctx.r3.s64 = 20;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r27,16(r28)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// lwz r26,20(r28)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r28.u32 + 20);
	// stw r27,12364(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12364, ctx.r27.u32);
	// stw r26,12372(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12372, ctx.r26.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880C8824;
	sub_880F52C8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c8838
	if (ctx.cr6.eq) goto loc_880C8838;
	// li r11,8
	ctx.r11.s64 = 8;
	// stw r11,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r11.u32);
loc_880C8838:
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r5,4(r28)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880f5570
	ctx.lr = 0x880C8848;
	sub_880F5570(ctx, base);
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r6,984(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 984);
	// lwz r5,980(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 980);
	// lwz r8,2332(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2332);
	// lwz r7,2328(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2328);
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// bl 0x880f5438
	ctx.lr = 0x880C8868;
	sub_880F5438(ctx, base);
	// stw r27,12364(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12364, ctx.r27.u32);
	// lis r10,-30667
	ctx.r10.s64 = -2009792512;
	// stw r26,12372(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12372, ctx.r26.u32);
	// lis r9,-30667
	ctx.r9.s64 = -2009792512;
	// li r11,21
	ctx.r11.s64 = 21;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,21
	ctx.r3.s64 = 21;
	// stw r11,12380(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12380, ctx.r11.u32);
	// stw r29,12376(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12376, ctx.r29.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880C8890;
	sub_880F52C8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c88a8
	if (ctx.cr6.eq) goto loc_880C88A8;
	// li r11,144
	ctx.r11.s64 = 144;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r11,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r11.u32);
	// stw r10,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r10.u32);
loc_880C88A8:
	// li r4,12
	ctx.r4.s64 = 12;
	// lwz r5,4(r28)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// bl 0x880f5570
	ctx.lr = 0x880C88B4;
	sub_880F5570(ctx, base);
	// lwz r11,124(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r10,40(r23)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r23.u32 + 40);
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880c88e0
	if (ctx.cr6.eq) goto loc_880C88E0;
loc_880C88C8:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880c88e0
	if (ctx.cr6.eq) goto loc_880C88E0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880c88c8
	if (!ctx.cr6.eq) goto loc_880C88C8;
loc_880C88E0:
	// stw r22,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r22.u32);
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lwz r5,980(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 980);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne cr6,0x880c8900
	if (!ctx.cr6.eq) goto loc_880C8900;
	// addi r10,r11,-11984
	ctx.r10.s64 = ctx.r11.s64 + -11984;
	// lwz r11,-1972(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -1972);
	// b 0x880c8930
	goto loc_880C8930;
loc_880C8900:
	// addi r11,r11,-11984
	ctx.r11.s64 = ctx.r11.s64 + -11984;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r10,84(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x880c892c
	if (!ctx.cr6.eq) goto loc_880C892C;
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// li r3,3
	ctx.r3.s64 = 3;
	// lwz r4,984(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 984);
	// lwz r6,2332(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2332);
	// bl 0x8815d688
	ctx.lr = 0x880C8928;
	sub_8815D688(ctx, base);
	// b 0x880c8960
	goto loc_880C8960;
loc_880C892C:
	// lwz r11,-1972(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -1972);
loc_880C8930:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880c8960
	if (ctx.cr6.eq) goto loc_880C8960;
	// lis r10,4
	ctx.r10.s64 = 262144;
	// lis r9,4
	ctx.r9.s64 = 262144;
	// ori r8,r10,33876
	ctx.r8.u64 = ctx.r10.u64 | 33876;
	// ori r7,r9,33872
	ctx.r7.u64 = ctx.r9.u64 | 33872;
	// li r6,3
	ctx.r6.s64 = 3;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stwx r6,r11,r8
	PPC_STORE_U32(ctx.r11.u32 + ctx.r8.u32, ctx.r6.u32);
	// stwx r22,r11,r7
	PPC_STORE_U32(ctx.r11.u32 + ctx.r7.u32, ctx.r22.u32);
	// bl 0x8815d040
	ctx.lr = 0x880C8960;
	sub_8815D040(ctx, base);
loc_880C8960:
	// lwz r10,40(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 40);
	// li r9,2
	ctx.r9.s64 = 2;
loc_880C8968:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r11,124(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// srawi r8,r10,4
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 4;
	// addze r7,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r7.s64 = temp.s64;
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// rlwinm r6,r7,4,0,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// subf r10,r6,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r6.s64;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// beq cr6,0x880c89a8
	if (ctx.cr6.eq) goto loc_880C89A8;
loc_880C8990:
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x880c89a8
	if (ctx.cr6.eq) goto loc_880C89A8;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880c8990
	if (!ctx.cr6.eq) goto loc_880C8990;
loc_880C89A8:
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r22,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r22.u32);
	// add r11,r10,r8
	ctx.r11.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stw r9,204(r11)
	PPC_STORE_U32(ctx.r11.u32 + 204, ctx.r9.u32);
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// stw r21,212(r11)
	PPC_STORE_U32(ctx.r11.u32 + 212, ctx.r21.u32);
	// cmpwi cr6,r9,32
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 32, ctx.xer);
	// blt cr6,0x880c8968
	if (ctx.cr6.lt) goto loc_880C8968;
loc_880C89D0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8807118c
	__restgprlr_21(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C89DC"))) PPC_WEAK_FUNC(sub_880C89DC);
PPC_FUNC_IMPL(__imp__sub_880C89DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C89E0"))) PPC_WEAK_FUNC(sub_880C89E0);
PPC_FUNC_IMPL(__imp__sub_880C89E0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071140
	ctx.lr = 0x880C89E8;
	__savegprlr_22(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,16(r4)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// lis r29,-30667
	ctx.r29.s64 = -2009792512;
	// lwz r30,20(r4)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// lis r28,-30667
	ctx.r28.s64 = -2009792512;
	// lwz r10,108(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 108);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// li r3,20
	ctx.r3.s64 = 20;
	// mr r22,r5
	ctx.r22.u64 = ctx.r5.u64;
	// stw r31,12364(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12364, ctx.r31.u32);
	// stw r30,12372(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12372, ctx.r30.u32);
	// lwz r11,184(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 184);
	// lwz r10,168(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 168);
	// lwz r23,0(r27)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// bl 0x880f52c8
	ctx.lr = 0x880C8A2C;
	sub_880F52C8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c8a3c
	if (ctx.cr6.eq) goto loc_880C8A3C;
	// li r11,8
	ctx.r11.s64 = 8;
	// stw r11,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r11.u32);
loc_880C8A3C:
	// stw r31,12364(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12364, ctx.r31.u32);
	// lis r25,-30667
	ctx.r25.s64 = -2009792512;
	// stw r30,12372(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12372, ctx.r30.u32);
	// lis r26,-30667
	ctx.r26.s64 = -2009792512;
	// li r11,21
	ctx.r11.s64 = 21;
	// li r3,21
	ctx.r3.s64 = 21;
	// stw r11,12380(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12380, ctx.r11.u32);
	// stw r4,12376(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12376, ctx.r4.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880C8A60;
	sub_880F52C8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c8a78
	if (ctx.cr6.eq) goto loc_880C8A78;
	// li r11,2
	ctx.r11.s64 = 2;
	// li r10,144
	ctx.r10.s64 = 144;
	// stw r11,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r11.u32);
	// stw r10,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r10.u32);
loc_880C8A78:
	// addis r23,r23,1
	ctx.r23.s64 = ctx.r23.s64 + 65536;
	// lis r11,0
	ctx.r11.s64 = 0;
	// addi r23,r23,-30380
	ctx.r23.s64 = ctx.r23.s64 + -30380;
	// ori r24,r11,35160
	ctx.r24.u64 = ctx.r11.u64 | 35160;
	// lwz r10,0(r23)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r23.u32 + 0);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x880c8acc
	if (!ctx.cr6.eq) goto loc_880C8ACC;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lwz r8,108(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 108);
	// lis r9,0
	ctx.r9.s64 = 0;
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lis r7,0
	ctx.r7.s64 = 0;
	// ori r6,r11,35172
	ctx.r6.u64 = ctx.r11.u64 | 35172;
	// ori r11,r9,35168
	ctx.r11.u64 = ctx.r9.u64 | 35168;
	// ori r9,r7,35164
	ctx.r9.u64 = ctx.r7.u64 | 35164;
	// lwz r4,12(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// lwzx r5,r10,r24
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r24.u32);
	// lwzx r8,r10,r6
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r6.u32);
	// lwzx r7,r10,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// lwzx r6,r10,r9
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x880f5438
	ctx.lr = 0x880C8ACC;
	sub_880F5438(ctx, base);
loc_880C8ACC:
	// lwz r11,0(r23)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + 0);
	// li r23,0
	ctx.r23.s64 = 0;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x880c8b14
	if (!ctx.cr6.eq) goto loc_880C8B14;
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lwzx r10,r11,r24
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x880c8b14
	if (!ctx.cr6.eq) goto loc_880C8B14;
	// stw r31,12364(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12364, ctx.r31.u32);
	// li r10,140
	ctx.r10.s64 = 140;
	// stw r30,12372(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12372, ctx.r30.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,140
	ctx.r4.s64 = 140;
	// stw r23,12380(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12380, ctx.r23.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,12376(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12376, ctx.r10.u32);
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
	// bl 0x881607f8
	ctx.lr = 0x880C8B14;
	sub_881607F8(ctx, base);
loc_880C8B14:
	// lwz r11,124(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 124);
	// mr r10,r22
	ctx.r10.u64 = ctx.r22.u64;
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880c8b40
	if (ctx.cr6.eq) goto loc_880C8B40;
loc_880C8B28:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880c8b40
	if (ctx.cr6.eq) goto loc_880C8B40;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880c8b28
	if (!ctx.cr6.eq) goto loc_880C8B28;
loc_880C8B40:
	// stw r23,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r23.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x88071190
	__restgprlr_22(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C8B4C"))) PPC_WEAK_FUNC(sub_880C8B4C);
PPC_FUNC_IMPL(__imp__sub_880C8B4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880C8B50"))) PPC_WEAK_FUNC(sub_880C8B50);
PPC_FUNC_IMPL(__imp__sub_880C8B50) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071124
	ctx.lr = 0x880C8B58;
	__savegprlr_15(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r11,0
	ctx.r11.s64 = 0;
	// mr r15,r3
	ctx.r15.u64 = ctx.r3.u64;
	// ori r10,r11,35156
	ctx.r10.u64 = ctx.r11.u64 | 35156;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x880c8bcc
	if (ctx.cr6.eq) goto loc_880C8BCC;
	// li r16,0
	ctx.r16.s64 = 0;
	// addi r29,r31,168
	ctx.r29.s64 = ctx.r31.s64 + 168;
	// mr r30,r16
	ctx.r30.u64 = ctx.r16.u64;
loc_880C8B88:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880c89e0
	ctx.lr = 0x880C8B98;
	sub_880C89E0(ctx, base);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r29,r29,48
	ctx.r29.s64 = ctx.r29.s64 + 48;
	// cmpwi cr6,r30,16
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 16, ctx.xer);
	// blt cr6,0x880c8b88
	if (ctx.cr6.lt) goto loc_880C8B88;
	// lwz r11,2304(r15)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r15.u32 + 2304);
	// lwz r11,124(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 124);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880c8bbc
	if (ctx.cr6.eq) goto loc_880C8BBC;
	// stw r16,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r16.u32);
loc_880C8BBC:
	// mr r3,r15
	ctx.r3.u64 = ctx.r15.u64;
	// bl 0x88094220
	ctx.lr = 0x880C8BC4;
	sub_88094220(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071174
	__restgprlr_15(ctx, base);
	return;
loc_880C8BCC:
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lwz r17,-11984(r11)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11984);
	// lwz r10,1460(r17)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r17.u32 + 1460);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x880c8bec
	if (!ctx.cr6.eq) goto loc_880C8BEC;
	// lwz r11,1656(r17)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r17.u32 + 1656);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880c8c3c
	if (ctx.cr6.eq) goto loc_880C8C3C;
loc_880C8BEC:
	// li r16,0
	ctx.r16.s64 = 0;
	// addi r29,r31,168
	ctx.r29.s64 = ctx.r31.s64 + 168;
	// mr r30,r16
	ctx.r30.u64 = ctx.r16.u64;
loc_880C8BF8:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880c89e0
	ctx.lr = 0x880C8C08;
	sub_880C89E0(ctx, base);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r29,r29,48
	ctx.r29.s64 = ctx.r29.s64 + 48;
	// cmpwi cr6,r30,16
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 16, ctx.xer);
	// blt cr6,0x880c8bf8
	if (ctx.cr6.lt) goto loc_880C8BF8;
	// lwz r11,2304(r15)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r15.u32 + 2304);
	// lwz r11,124(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 124);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880c8c2c
	if (ctx.cr6.eq) goto loc_880C8C2C;
	// stw r16,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r16.u32);
loc_880C8C2C:
	// mr r3,r15
	ctx.r3.u64 = ctx.r15.u64;
	// bl 0x88094220
	ctx.lr = 0x880C8C34;
	sub_88094220(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071174
	__restgprlr_15(ctx, base);
	return;
loc_880C8C3C:
	// lwz r11,968(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 968);
	// li r16,0
	ctx.r16.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880c8c5c
	if (ctx.cr6.eq) goto loc_880C8C5C;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,968(r31)
	PPC_STORE_U32(ctx.r31.u32 + 968, ctx.r11.u32);
	// bgt 0x880c8c5c
	if (ctx.cr0.gt) goto loc_880C8C5C;
	// stw r16,968(r31)
	PPC_STORE_U32(ctx.r31.u32 + 968, ctx.r16.u32);
loc_880C8C5C:
	// mr r3,r15
	ctx.r3.u64 = ctx.r15.u64;
	// bl 0x880c81a8
	ctx.lr = 0x880C8C64;
	sub_880C81A8(ctx, base);
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26272(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26272);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880c8c7c
	if (ctx.cr6.eq) goto loc_880C8C7C;
	// mr r9,r16
	ctx.r9.u64 = ctx.r16.u64;
	// b 0x880c8c8c
	goto loc_880C8C8C;
loc_880C8C7C:
	// lwz r11,120(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// addi r11,r11,51
	ctx.r11.s64 = ctx.r11.s64 + 51;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r17
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r17.u32);
loc_880C8C8C:
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// lwz r8,52(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addi r30,r31,168
	ctx.r30.s64 = ctx.r31.s64 + 168;
	// clrlwi r10,r10,23
	ctx.r10.u64 = ctx.r10.u32 & 0x1FF;
	// addi r26,r11,9552
	ctx.r26.s64 = ctx.r11.s64 + 9552;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r7,r10,128
	ctx.r7.s64 = ctx.r10.s64 + 128;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// rlwinm r6,r7,2,21,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x7FC;
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// rlwinm r5,r10,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r23,r16
	ctx.r23.u64 = ctx.r16.u64;
	// lis r22,-30667
	ctx.r22.s64 = -2009792512;
	// li r18,8
	ctx.r18.s64 = 8;
	// lwzx r4,r6,r26
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r26.u32);
	// lis r25,-30667
	ctx.r25.s64 = -2009792512;
	// lwzx r3,r5,r26
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r26.u32);
	// mullw r10,r3,r8
	ctx.r10.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r8.s32);
	// mullw r8,r4,r8
	ctx.r8.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r8.s32);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// li r19,2
	ctx.r19.s64 = 2;
	// stw r10,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// li r20,144
	ctx.r20.s64 = 144;
	// lis r24,-30667
	ctx.r24.s64 = -2009792512;
	// lis r21,-30667
	ctx.r21.s64 = -2009792512;
loc_880C8D00:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880c8e30
	if (ctx.cr6.eq) goto loc_880C8E30;
	// lwz r11,936(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 936);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// add r11,r11,r23
	ctx.r11.u64 = ctx.r11.u64 + ctx.r23.u64;
	// lwz r9,956(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 956);
	// lwz r8,44(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// clrlwi r11,r7,23
	ctx.r11.u64 = ctx.r7.u32 & 0x1FF;
	// addi r6,r11,128
	ctx.r6.s64 = ctx.r11.s64 + 128;
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r4,r6,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// lwzx r3,r5,r26
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r26.u32);
	// lwzx r10,r4,r26
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r26.u32);
	// stw r11,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// mullw r11,r3,r9
	ctx.r11.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r9.s32);
	// stw r11,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
	// mullw r10,r10,r9
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// stw r10,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r10.u32);
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stw r11,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r11.u32);
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r11,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r11.u32);
	// beq cr6,0x880c8e30
	if (ctx.cr6.eq) goto loc_880C8E30;
	// lwz r11,36(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,36(r30)
	PPC_STORE_U32(ctx.r30.u32 + 36, ctx.r11.u32);
	// bgt 0x880c8e30
	if (ctx.cr0.gt) goto loc_880C8E30;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,40
	ctx.r5.s64 = 40;
	// li r4,90
	ctx.r4.s64 = 90;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x880e3240
	ctx.lr = 0x880C8D94;
	sub_880E3240(ctx, base);
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// li r3,3
	ctx.r3.s64 = 3;
	// lwz r5,980(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 980);
	// lwz r4,984(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 984);
	// lwz r6,2332(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2332);
	// bl 0x8815d688
	ctx.lr = 0x880C8DAC;
	sub_8815D688(ctx, base);
	// lwz r9,108(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// li r3,20
	ctx.r3.s64 = 20;
	// lwz r10,184(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 184);
	// lwz r11,168(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 168);
	// add r27,r10,r11
	ctx.r27.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r4,r27,2
	ctx.r4.s64 = ctx.r27.s64 + 2;
	// lwz r29,16(r30)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// lwz r28,20(r30)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// stw r29,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r29.u32);
	// stw r28,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r28.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880C8DD8;
	sub_880F52C8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c8de4
	if (ctx.cr6.eq) goto loc_880C8DE4;
	// stw r18,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r18.u32);
loc_880C8DE4:
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r5,4(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x880f5570
	ctx.lr = 0x880C8DF0;
	sub_880F5570(ctx, base);
	// stw r29,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r29.u32);
	// stw r28,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r28.u32);
	// addi r4,r27,1
	ctx.r4.s64 = ctx.r27.s64 + 1;
	// li r11,21
	ctx.r11.s64 = 21;
	// li r3,21
	ctx.r3.s64 = 21;
	// stw r4,12376(r22)
	PPC_STORE_U32(ctx.r22.u32 + 12376, ctx.r4.u32);
	// stw r11,12380(r21)
	PPC_STORE_U32(ctx.r21.u32 + 12380, ctx.r11.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880C8E10;
	sub_880F52C8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880c8e20
	if (ctx.cr6.eq) goto loc_880C8E20;
	// stw r19,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r19.u32);
	// stw r20,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r20.u32);
loc_880C8E20:
	// li r4,12
	ctx.r4.s64 = 12;
	// lwz r5,4(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x880f5570
	ctx.lr = 0x880C8E2C;
	sub_880F5570(ctx, base);
	// stw r16,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r16.u32);
loc_880C8E30:
	// addi r23,r23,32
	ctx.r23.s64 = ctx.r23.s64 + 32;
	// addi r30,r30,48
	ctx.r30.s64 = ctx.r30.s64 + 48;
	// cmpwi cr6,r23,512
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 512, ctx.xer);
	// blt cr6,0x880c8d00
	if (ctx.cr6.lt) goto loc_880C8D00;
	// lwz r10,936(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 936);
	// lis r7,64
	ctx.r7.s64 = 4194304;
	// lwz r11,948(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 948);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// add. r10,r9,r7
	ctx.r10.u64 = ctx.r9.u64 + ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// clrlwi r5,r6,23
	ctx.r5.u64 = ctx.r6.u32 & 0x1FF;
	// stw r5,936(r31)
	PPC_STORE_U32(ctx.r31.u32 + 936, ctx.r5.u32);
	// lwz r11,100(r15)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r15.u32 + 100);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r4,r9,-1
	ctx.r4.s64 = ctx.r9.s64 + -1;
	// and r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 & ctx.r11.u64;
	// ble 0x880c8ec0
	if (!ctx.cr0.gt) goto loc_880C8EC0;
	// lis r9,128
	ctx.r9.s64 = 8388608;
	// lis r6,320
	ctx.r6.s64 = 20971520;
	// subf r5,r9,r10
	ctx.r5.s64 = ctx.r10.s64 - ctx.r9.s64;
	// cmpw cr6,r5,r6
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r6.s32, ctx.xer);
	// bge cr6,0x880c8ec0
	if (!ctx.cr6.lt) goto loc_880C8EC0;
	// addi r11,r11,55
	ctx.r11.s64 = ctx.r11.s64 + 55;
	// lis r10,-40
	ctx.r10.s64 = -2621440;
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r6,r17
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r17.u32);
	// add r5,r11,r8
	ctx.r5.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r11,r5,r7
	ctx.r11.u64 = ctx.r5.u64 + ctx.r7.u64;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x880c8ec0
	if (!ctx.cr6.gt) goto loc_880C8EC0;
	// lis r10,280
	ctx.r10.s64 = 18350080;
	// subf r9,r9,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r9.s64;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x880c8ee4
	if (ctx.cr6.lt) goto loc_880C8EE4;
loc_880C8EC0:
	// lwz r11,2304(r15)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r15.u32 + 2304);
	// lwz r11,124(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 124);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880c8ed4
	if (ctx.cr6.eq) goto loc_880C8ED4;
	// stw r16,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r16.u32);
loc_880C8ED4:
	// mr r3,r15
	ctx.r3.u64 = ctx.r15.u64;
	// bl 0x88094220
	ctx.lr = 0x880C8EDC;
	sub_88094220(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071174
	__restgprlr_15(ctx, base);
	return;
loc_880C8EE4:
	// lwz r11,124(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880c8f58
	if (ctx.cr6.eq) goto loc_880C8F58;
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// mr r10,r16
	ctx.r10.u64 = ctx.r16.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880c8f18
	if (ctx.cr6.eq) goto loc_880C8F18;
loc_880C8F00:
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// stw r16,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r16.u32);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880c8f00
	if (!ctx.cr6.eq) goto loc_880C8F00;
loc_880C8F18:
	// lis r11,128
	ctx.r11.s64 = 8388608;
	// clrlwi r10,r10,20
	ctx.r10.u64 = ctx.r10.u32 & 0xFFF;
	// ori r9,r11,32896
	ctx.r9.u64 = ctx.r11.u64 | 32896;
	// rlwinm r10,r10,0,26,21
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFC3F;
	// stw r9,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r9.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x880c8f58
	if (ctx.cr6.eq) goto loc_880C8F58;
	// lwz r11,132(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r9,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r9.u32);
	// beq cr6,0x880c8f58
	if (ctx.cr6.eq) goto loc_880C8F58;
	// lis r11,192
	ctx.r11.s64 = 12582912;
	// ori r10,r11,49152
	ctx.r10.u64 = ctx.r11.u64 | 49152;
	// stw r10,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r10.u32);
loc_880C8F58:
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// bge 0x880c8f88
	if (!ctx.cr0.lt) goto loc_880C8F88;
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// cmpwi cr6,r11,24
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 24, ctx.xer);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// blt cr6,0x880c8f88
	if (ctx.cr6.lt) goto loc_880C8F88;
	// stw r16,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r16.u32);
loc_880C8F88:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071174
	__restgprlr_15(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C8F90"))) PPC_WEAK_FUNC(sub_880C8F90);
PPC_FUNC_IMPL(__imp__sub_880C8F90) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x880C8F98;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30707
	ctx.r11.s64 = -2012413952;
	// li r4,988
	ctx.r4.s64 = 988;
	// addi r5,r11,-28784
	ctx.r5.s64 = ctx.r11.s64 + -28784;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x880C8FB0;
	sub_88094290(ctx, base);
	// li r5,988
	ctx.r5.s64 = 988;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,2304(r28)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r28.u32 + 2304);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x880C8FC4;
	sub_88073BD0(ctx, base);
	// lwz r8,32(r28)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r28.u32 + 32);
	// li r10,6
	ctx.r10.s64 = 6;
	// li r6,45
	ctx.r6.s64 = 45;
	// li r9,-30
	ctx.r9.s64 = -30;
	// addic. r11,r28,120
	ctx.xer.ca = ctx.r28.u32 > 4294967175;
	ctx.r11.s64 = ctx.r28.s64 + 120;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r8,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r8.u32);
	// li r29,1
	ctx.r29.s64 = 1;
	// lwz r7,36(r28)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r28.u32 + 36);
	// li r30,0
	ctx.r30.s64 = 0;
	// li r27,256
	ctx.r27.s64 = 256;
	// stw r7,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r7.u32);
	// stw r6,972(r31)
	PPC_STORE_U32(ctx.r31.u32 + 972, ctx.r6.u32);
	// stw r9,976(r31)
	PPC_STORE_U32(ctx.r31.u32 + 976, ctx.r9.u32);
	// stw r10,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r10.u32);
	// stw r10,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r10.u32);
	// beq 0x880c90ac
	if (ctx.cr0.eq) goto loc_880C90AC;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// stw r9,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r9.u32);
	// lwz r8,20(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// stw r8,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r8.u32);
	// lwz r7,24(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// lwz r5,2304(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2304);
	// stw r5,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r5.u32);
	// lwz r4,24(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// stw r4,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r4.u32);
	// stw r30,940(r31)
	PPC_STORE_U32(ctx.r31.u32 + 940, ctx.r30.u32);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// addi r9,r10,-3
	ctx.r9.s64 = ctx.r10.s64 + -3;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r9,r7
	ctx.r3.u64 = ctx.r9.u64 + ctx.r7.u64;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r9,r3,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r10,r10,10,0,21
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 10) & 0xFFFFFC00;
	// stw r9,976(r31)
	PPC_STORE_U32(ctx.r31.u32 + 976, ctx.r9.u32);
	// lwz r8,28(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// addi r27,r10,256
	ctx.r27.s64 = ctx.r10.s64 + 256;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x880c9078
	if (ctx.cr6.eq) goto loc_880C9078;
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r6,972(r31)
	PPC_STORE_U32(ctx.r31.u32 + 972, ctx.r6.u32);
	// stw r10,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r10.u32);
	// stw r10,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r10.u32);
loc_880C9078:
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// cmpwi cr6,r9,256
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 256, ctx.xer);
	// stw r10,948(r31)
	PPC_STORE_U32(ctx.r31.u32 + 948, ctx.r10.u32);
	// lwz r8,36(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// stw r8,952(r31)
	PPC_STORE_U32(ctx.r31.u32 + 952, ctx.r8.u32);
	// lwz r7,40(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// stw r7,960(r31)
	PPC_STORE_U32(ctx.r31.u32 + 960, ctx.r7.u32);
	// ble cr6,0x880c90a8
	if (!ctx.cr6.gt) goto loc_880C90A8;
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
	// b 0x880c90ac
	goto loc_880C90AC;
loc_880C90A8:
	// stw r29,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r29.u32);
loc_880C90AC:
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r28,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r28.u32);
	// li r10,210
	ctx.r10.s64 = 210;
	// stw r30,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r30.u32);
	// li r26,32
	ctx.r26.s64 = 32;
	// stw r11,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r11.u32);
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// li r3,16
	ctx.r3.s64 = 16;
	// stw r30,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r30.u32);
	// stw r29,152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 152, ctx.r29.u32);
	// stw r29,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r29.u32);
	// stw r10,168(r28)
	PPC_STORE_U32(ctx.r28.u32 + 168, ctx.r10.u32);
	// stw r26,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r26.u32);
	// bl 0x881556a0
	ctx.lr = 0x880C90EC;
	sub_881556A0(ctx, base);
	// lis r9,-30707
	ctx.r9.s64 = -2012413952;
	// stw r3,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r3.u32);
	// li r8,48
	ctx.r8.s64 = 48;
	// addi r7,r9,-31032
	ctx.r7.s64 = ctx.r9.s64 + -31032;
	// stw r28,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r28.u32);
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// stw r7,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r7.u32);
	// addi r10,r31,184
	ctx.r10.s64 = ctx.r31.s64 + 184;
	// lwz r6,124(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// stw r29,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r29.u32);
	// stw r8,968(r31)
	PPC_STORE_U32(ctx.r31.u32 + 968, ctx.r8.u32);
	// li r8,8
	ctx.r8.s64 = 8;
loc_880C911C:
	// lwz r6,124(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// lwz r11,28(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880c9148
	if (ctx.cr6.eq) goto loc_880C9148;
loc_880C9130:
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x880c91f8
	if (ctx.cr6.eq) goto loc_880C91F8;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880c9130
	if (!ctx.cr6.eq) goto loc_880C9130;
loc_880C9148:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_880C914C:
	// stw r10,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r10.u32);
	// stw r9,40(r11)
	PPC_STORE_U32(ctx.r11.u32 + 40, ctx.r9.u32);
	// stw r8,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r8.u32);
	// stw r29,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r29.u32);
	// stw r8,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
	// stw r8,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r8.u32);
	// stw r8,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r8.u32);
	// stw r27,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r27.u32);
	// stw r29,-16(r10)
	PPC_STORE_U32(ctx.r10.u32 + -16, ctx.r29.u32);
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// lwz r7,20(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// stw r9,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r9.u32);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r7,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r7.u32);
	// stw r30,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r30.u32);
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// cmpwi cr6,r9,16
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 16, ctx.xer);
	// blt cr6,0x880c911c
	if (ctx.cr6.lt) goto loc_880C911C;
	// stw r29,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r29.u32);
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// stw r8,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r8.u32);
	// stw r8,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r8.u32);
	// lwz r11,-11984(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11984);
	// lwz r11,84(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// stw r11,964(r31)
	PPC_STORE_U32(ctx.r31.u32 + 964, ctx.r11.u32);
	// beq cr6,0x880c9210
	if (ctx.cr6.eq) goto loc_880C9210;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x880c922c
	if (!ctx.cr6.eq) goto loc_880C922C;
	// lis r10,-30707
	ctx.r10.s64 = -2012413952;
	// stw r30,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r30.u32);
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r30,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r30.u32);
	// li r9,16
	ctx.r9.s64 = 16;
	// stw r30,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r30.u32);
	// addi r8,r10,-32160
	ctx.r8.s64 = ctx.r10.s64 + -32160;
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// stw r9,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r9.u32);
	// stw r11,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// stw r26,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r26.u32);
	// stw r8,72(r28)
	PPC_STORE_U32(ctx.r28.u32 + 72, ctx.r8.u32);
	// b 0x880c922c
	goto loc_880C922C;
loc_880C91F8:
	// lwz r7,24(r6)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x880c9208
	if (ctx.cr6.eq) goto loc_880C9208;
	// stw r7,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r7.u32);
loc_880C9208:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x880c914c
	goto loc_880C914C;
loc_880C9210:
	// lis r11,-30707
	ctx.r11.s64 = -2012413952;
	// stw r30,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r30.u32);
	// stw r30,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r30.u32);
	// addi r10,r11,-31808
	ctx.r10.s64 = ctx.r11.s64 + -31808;
	// stw r30,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r30.u32);
	// stw r8,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r8.u32);
	// stw r10,72(r28)
	PPC_STORE_U32(ctx.r28.u32 + 72, ctx.r10.u32);
loc_880C922C:
	// lis r11,-30707
	ctx.r11.s64 = -2012413952;
	// lis r10,-30707
	ctx.r10.s64 = -2012413952;
	// lis r9,-30707
	ctx.r9.s64 = -2012413952;
	// addi r8,r11,-29872
	ctx.r8.s64 = ctx.r11.s64 + -29872;
	// addi r7,r10,-31456
	ctx.r7.s64 = ctx.r10.s64 + -31456;
	// addi r6,r9,-31552
	ctx.r6.s64 = ctx.r9.s64 + -31552;
	// stw r8,64(r28)
	PPC_STORE_U32(ctx.r28.u32 + 64, ctx.r8.u32);
	// stw r7,68(r28)
	PPC_STORE_U32(ctx.r28.u32 + 68, ctx.r7.u32);
	// stw r6,84(r28)
	PPC_STORE_U32(ctx.r28.u32 + 84, ctx.r6.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880C9258"))) PPC_WEAK_FUNC(sub_880C9258);
PPC_FUNC_IMPL(__imp__sub_880C9258) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,2304(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mulli r11,r4,804
	ctx.r11.s64 = ctx.r4.s64 * 804;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r10,876(r11)
	PPC_STORE_U32(ctx.r11.u32 + 876, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880C9270"))) PPC_WEAK_FUNC(sub_880C9270);
PPC_FUNC_IMPL(__imp__sub_880C9270) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,2304(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mulli r11,r4,804
	ctx.r11.s64 = ctx.r4.s64 * 804;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,168(r11)
	PPC_STORE_U32(ctx.r11.u32 + 168, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880C9288"))) PPC_WEAK_FUNC(sub_880C9288);
PPC_FUNC_IMPL(__imp__sub_880C9288) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,2304(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mulli r11,r4,804
	ctx.r11.s64 = ctx.r4.s64 * 804;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r10,r11,76
	ctx.r10.s64 = ctx.r11.s64 + 76;
	// stw r9,168(r11)
	PPC_STORE_U32(ctx.r11.u32 + 168, ctx.r9.u32);
	// stw r5,164(r11)
	PPC_STORE_U32(ctx.r11.u32 + 164, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880C92A8"))) PPC_WEAK_FUNC(sub_880C92A8);
PPC_FUNC_IMPL(__imp__sub_880C92A8) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,2304(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mulli r11,r4,804
	ctx.r11.s64 = ctx.r4.s64 * 804;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r10,r11,76
	ctx.r10.s64 = ctx.r11.s64 + 76;
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// lwz r9,88(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// stw r10,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r10.u32);
	// stw r9,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r9.u32);
	// blr 
	return;
}

