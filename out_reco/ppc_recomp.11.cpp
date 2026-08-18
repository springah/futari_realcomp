#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_880DC774"))) PPC_WEAK_FUNC(sub_880DC774);
PPC_FUNC_IMPL(__imp__sub_880DC774) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880DC778"))) PPC_WEAK_FUNC(sub_880DC778);
PPC_FUNC_IMPL(__imp__sub_880DC778) {
	PPC_FUNC_PROLOGUE();
	// srawi r11,r3,1
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 1;
	// li r10,1
	ctx.r10.s64 = 1;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r11,96
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 96, ctx.xer);
	// blt cr6,0x880dc7c0
	if (ctx.cr6.lt) goto loc_880DC7C0;
	// cmpwi cr6,r11,128
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 128, ctx.xer);
	// bgt cr6,0x880dc7ac
	if (ctx.cr6.gt) goto loc_880DC7AC;
	// subfic r11,r11,128
	ctx.xer.ca = ctx.r11.u32 <= 128;
	ctx.r11.s64 = 128 - ctx.r11.s64;
	// stw r9,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r9.u32);
	// stw r10,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r10.u32);
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// blr 
	return;
loc_880DC7AC:
	// cmpwi cr6,r11,160
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 160, ctx.xer);
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r11,r11,-128
	ctx.r11.s64 = ctx.r11.s64 + -128;
	// ble cr6,0x880dc7c4
	if (!ctx.cr6.gt) goto loc_880DC7C4;
loc_880DC7C0:
	// li r11,32
	ctx.r11.s64 = 32;
loc_880DC7C4:
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// stw r9,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r9.u32);
	// stw r10,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880DC7D4"))) PPC_WEAK_FUNC(sub_880DC7D4);
PPC_FUNC_IMPL(__imp__sub_880DC7D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880DC7D8"))) PPC_WEAK_FUNC(sub_880DC7D8);
PPC_FUNC_IMPL(__imp__sub_880DC7D8) {
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
	// blt cr6,0x880dc820
	if (ctx.cr6.lt) goto loc_880DC820;
	// cmpwi cr6,r11,64
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 64, ctx.xer);
	// bgt cr6,0x880dc80c
	if (ctx.cr6.gt) goto loc_880DC80C;
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
loc_880DC80C:
	// cmpwi cr6,r11,80
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 80, ctx.xer);
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r11,r11,-64
	ctx.r11.s64 = ctx.r11.s64 + -64;
	// ble cr6,0x880dc824
	if (!ctx.cr6.gt) goto loc_880DC824;
loc_880DC820:
	// li r11,16
	ctx.r11.s64 = 16;
loc_880DC824:
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// stw r9,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r9.u32);
	// stw r10,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880DC834"))) PPC_WEAK_FUNC(sub_880DC834);
PPC_FUNC_IMPL(__imp__sub_880DC834) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880DC838"))) PPC_WEAK_FUNC(sub_880DC838);
PPC_FUNC_IMPL(__imp__sub_880DC838) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x880DC840;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// li r30,128
	ctx.r30.s64 = 128;
	// lis r4,-40
	ctx.r4.s64 = -2621440;
	// addi r8,r11,9112
	ctx.r8.s64 = ctx.r11.s64 + 9112;
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// lis r28,392
	ctx.r28.s64 = 25690112;
	// li r31,0
	ctx.r31.s64 = 0;
	// lis r29,280
	ctx.r29.s64 = 18350080;
	// addi r5,r11,9552
	ctx.r5.s64 = ctx.r11.s64 + 9552;
loc_880DC868:
	// lwz r11,0(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x880dc8fc
	if (!ctx.cr6.eq) goto loc_880DC8FC;
	// lwz r11,4(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bge cr6,0x880dc8fc
	if (!ctx.cr6.lt) goto loc_880DC8FC;
	// lwz r11,20(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r9,24(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// lwz r10,16(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// lwz r6,12(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// addi r7,r11,128
	ctx.r7.s64 = ctx.r11.s64 + 128;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r7,2,21,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x7FC;
	// lwzx r11,r11,r5
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r5.u32);
	// lwzx r7,r7,r5
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r5.u32);
	// mullw r11,r11,r9
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r9.s32);
	// mullw r9,r7,r9
	ctx.r9.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r9.s32);
	// add r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r6,r11,r6
	ctx.r6.u64 = ctx.r11.u64 + ctx.r6.u64;
	// stw r7,16(r8)
	PPC_STORE_U32(ctx.r8.u32 + 16, ctx.r7.u32);
	// stw r6,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r6.u32);
	// bl 0x88094af0
	ctx.lr = 0x880DC8C8;
	sub_88094AF0(ctx, base);
	// rotlwi r11,r6,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// cmpw cr6,r7,r4
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r4.s32, ctx.xer);
	// add r11,r3,r11
	ctx.r11.u64 = ctx.r3.u64 + ctx.r11.u64;
	// stw r11,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r11.u32);
	// ble cr6,0x880dc8e4
	if (!ctx.cr6.gt) goto loc_880DC8E4;
	// cmpw cr6,r7,r28
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r28.s32, ctx.xer);
	// blt cr6,0x880dc8e8
	if (ctx.cr6.lt) goto loc_880DC8E8;
loc_880DC8E4:
	// stw r31,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r31.u32);
loc_880DC8E8:
	// cmpw cr6,r11,r4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r4.s32, ctx.xer);
	// ble cr6,0x880dc8f8
	if (!ctx.cr6.gt) goto loc_880DC8F8;
	// cmpw cr6,r11,r29
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r29.s32, ctx.xer);
	// blt cr6,0x880dc8fc
	if (ctx.cr6.lt) goto loc_880DC8FC;
loc_880DC8F8:
	// stw r31,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r31.u32);
loc_880DC8FC:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r8,r8,56
	ctx.r8.s64 = ctx.r8.s64 + 56;
	// bne 0x880dc868
	if (!ctx.cr0.eq) goto loc_880DC868;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880DC910"))) PPC_WEAK_FUNC(sub_880DC910);
PPC_FUNC_IMPL(__imp__sub_880DC910) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x880DC918;
	__savegprlr_28(ctx, base);
	// lwz r10,2304(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
	// lwz r3,16280(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16280);
loc_880DC928:
	// addi r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 1;
	// srawi r3,r11,7
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7F) != 0);
	ctx.r3.s64 = ctx.r11.s32 >> 7;
	// addze r3,r3
	temp.s64 = ctx.r3.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r3.s64 = temp.s64;
	// rlwinm r3,r3,7,0,24
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 7) & 0xFFFFFF80;
	// subf r11,r3,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r3.s64;
	// mulli r3,r11,56
	ctx.r3.s64 = ctx.r11.s64 * 56;
	// stw r11,16280(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16280, ctx.r11.u32);
	// add r31,r3,r10
	ctx.r31.u64 = ctx.r3.u64 + ctx.r10.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// addi r11,r31,9112
	ctx.r11.s64 = ctx.r31.s64 + 9112;
	// lwz r31,9112(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9112);
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq cr6,0x880dc96c
	if (ctx.cr6.eq) goto loc_880DC96C;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmpwi cr6,r29,128
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 128, ctx.xer);
	// blt cr6,0x880dc928
	if (ctx.cr6.lt) goto loc_880DC928;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_880DC96C:
	// lis r3,-30671
	ctx.r3.s64 = -2010054656;
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// lis r10,16838
	ctx.r10.s64 = 1103495168;
	// stw r30,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r30.u32);
	// lis r31,-13108
	ctx.r31.s64 = -859045888;
	// ori r29,r10,20077
	ctx.r29.u64 = ctx.r10.u64 | 20077;
	// ori r28,r31,52429
	ctx.r28.u64 = ctx.r31.u64 | 52429;
	// lwz r10,4200(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4200);
	// li r31,1
	ctx.r31.s64 = 1;
	// mullw r10,r10,r29
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r29.s32);
	// stw r31,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r31.u32);
	// addi r10,r10,12345
	ctx.r10.s64 = ctx.r10.s64 + 12345;
	// stw r10,4200(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4200, ctx.r10.u32);
	// lhz r29,4200(r3)
	ctx.r29.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4200);
	// mulhwu r3,r29,r28
	ctx.r3.u64 = (uint64_t(ctx.r29.u32) * uint64_t(ctx.r28.u32)) >> 32;
	// rlwinm r10,r3,29,3,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 29) & 0x1FFFFFFF;
	// rlwinm r3,r10,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// rlwinm r3,r10,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r10,r3,r29
	ctx.r10.s64 = ctx.r29.s64 - ctx.r3.s64;
	// clrlwi r3,r10,31
	ctx.r3.u64 = ctx.r10.u32 & 0x1;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x880dc9cc
	if (ctx.cr6.eq) goto loc_880DC9CC;
	// stw r31,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r31.u32);
loc_880DC9CC:
	// stw r4,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r4.u32);
	// li r10,255
	ctx.r10.s64 = 255;
	// li r4,30
	ctx.r4.s64 = 30;
	// stw r5,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r5.u32);
	// stw r30,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r30.u32);
	// stw r7,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r7.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r8.u32);
	// stw r9,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r9.u32);
	// stw r30,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r30.u32);
	// stw r30,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r30.u32);
	// stw r10,40(r11)
	PPC_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
	// stw r6,44(r11)
	PPC_STORE_U32(ctx.r11.u32 + 44, ctx.r6.u32);
	// stw r4,48(r11)
	PPC_STORE_U32(ctx.r11.u32 + 48, ctx.r4.u32);
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880DCA04"))) PPC_WEAK_FUNC(sub_880DCA04);
PPC_FUNC_IMPL(__imp__sub_880DCA04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880DCA08"))) PPC_WEAK_FUNC(sub_880DCA08);
PPC_FUNC_IMPL(__imp__sub_880DCA08) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071120
	ctx.lr = 0x880DCA10;
	__savegprlr_14(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r10,128
	ctx.r10.s64 = 128;
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r28,-30671
	ctx.r28.s64 = -2010054656;
	// lwz r30,84(r1)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// addi r29,r11,9112
	ctx.r29.s64 = ctx.r11.s64 + 9112;
	// lwz r31,84(r1)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lis r11,-30680
	ctx.r11.s64 = -2010644480;
	// lis r9,16838
	ctx.r9.s64 = 1103495168;
	// lis r8,14563
	ctx.r8.s64 = 954400768;
	// lwz r25,4200(r28)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4200);
	// lwz r7,26428(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26428);
	// lis r6,-3856
	ctx.r6.s64 = -252706816;
	// lis r17,24
	ctx.r17.s64 = 1572864;
	// lis r16,16
	ctx.r16.s64 = 1048576;
	// lis r15,32
	ctx.r15.s64 = 2097152;
	// lis r21,-30667
	ctx.r21.s64 = -2009792512;
	// lis r20,-30667
	ctx.r20.s64 = -2009792512;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// ori r26,r9,20077
	ctx.r26.u64 = ctx.r9.u64 | 20077;
	// ori r23,r8,36409
	ctx.r23.u64 = ctx.r8.u64 | 36409;
	// ori r24,r6,61681
	ctx.r24.u64 = ctx.r6.u64 | 61681;
	// lis r19,-30667
	ctx.r19.s64 = -2009792512;
	// lis r18,-30667
	ctx.r18.s64 = -2009792512;
	// addi r22,r11,-26588
	ctx.r22.s64 = ctx.r11.s64 + -26588;
loc_880DCA7C:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x880dcd54
	if (!ctx.cr6.eq) goto loc_880DCD54;
	// lwz r11,4(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x880dcc64
	if (ctx.cr6.lt) goto loc_880DCC64;
	// bne cr6,0x880dcd54
	if (!ctx.cr6.eq) goto loc_880DCD54;
	// lwz r11,28(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 28);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880dcb48
	if (!ctx.cr6.eq) goto loc_880DCB48;
	// lwz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// li r3,966
	ctx.r3.s64 = 966;
	// lwz r31,16(r29)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// lwz r14,44(r29)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r29.u32 + 44);
	// addis r30,r11,-80
	ctx.r30.s64 = ctx.r11.s64 + -5242880;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r6,r14
	ctx.r6.u64 = ctx.r14.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x881538c0
	ctx.lr = 0x880DCAC8;
	sub_881538C0(ctx, base);
	// add r27,r30,r17
	ctx.r27.u64 = ctx.r30.u64 + ctx.r17.u64;
	// mr r6,r14
	ctx.r6.u64 = ctx.r14.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// add r5,r31,r16
	ctx.r5.u64 = ctx.r31.u64 + ctx.r16.u64;
	// li r3,967
	ctx.r3.s64 = 967;
	// bl 0x881538c0
	ctx.lr = 0x880DCAE0;
	sub_881538C0(ctx, base);
	// mr r6,r14
	ctx.r6.u64 = ctx.r14.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// li r3,968
	ctx.r3.s64 = 968;
	// bl 0x881538c0
	ctx.lr = 0x880DCAF4;
	sub_881538C0(ctx, base);
	// mr r6,r14
	ctx.r6.u64 = ctx.r14.u64;
	// addis r5,r31,-40
	ctx.r5.s64 = ctx.r31.s64 + -2621440;
	// add r4,r30,r16
	ctx.r4.u64 = ctx.r30.u64 + ctx.r16.u64;
	// li r3,969
	ctx.r3.s64 = 969;
	// bl 0x881538c0
	ctx.lr = 0x880DCB08;
	sub_881538C0(ctx, base);
	// mr r6,r14
	ctx.r6.u64 = ctx.r14.u64;
	// addis r5,r31,-72
	ctx.r5.s64 = ctx.r31.s64 + -4718592;
	// addis r4,r30,64
	ctx.r4.s64 = ctx.r30.s64 + 4194304;
	// li r3,970
	ctx.r3.s64 = 970;
	// bl 0x881538c0
	ctx.lr = 0x880DCB1C;
	sub_881538C0(ctx, base);
	// lis r27,88
	ctx.r27.s64 = 5767168;
	// mr r6,r14
	ctx.r6.u64 = ctx.r14.u64;
	// subf r5,r27,r31
	ctx.r5.s64 = ctx.r31.s64 - ctx.r27.s64;
	// addis r4,r30,80
	ctx.r4.s64 = ctx.r30.s64 + 5242880;
	// li r3,971
	ctx.r3.s64 = 971;
	// bl 0x881538c0
	ctx.lr = 0x880DCB34;
	sub_881538C0(ctx, base);
	// mr r6,r14
	ctx.r6.u64 = ctx.r14.u64;
	// addis r5,r31,-112
	ctx.r5.s64 = ctx.r31.s64 + -7340032;
	// add r4,r30,r27
	ctx.r4.u64 = ctx.r30.u64 + ctx.r27.u64;
	// li r3,972
	ctx.r3.s64 = 972;
	// bl 0x881538c0
	ctx.lr = 0x880DCB48;
	sub_881538C0(ctx, base);
loc_880DCB48:
	// lwz r11,28(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 28);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x880dcc04
	if (!ctx.cr6.eq) goto loc_880DCC04;
	// lwz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// li r3,973
	ctx.r3.s64 = 973;
	// lwz r10,16(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// lwz r27,44(r29)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r29.u32 + 44);
	// subf r30,r15,r11
	ctx.r30.s64 = ctx.r11.s64 - ctx.r15.s64;
	// addis r31,r10,64
	ctx.r31.s64 = ctx.r10.s64 + 4194304;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x881538c0
	ctx.lr = 0x880DCB7C;
	sub_881538C0(ctx, base);
	// subf r15,r15,r31
	ctx.r15.s64 = ctx.r31.s64 - ctx.r15.s64;
	// addis r14,r30,-8
	ctx.r14.s64 = ctx.r30.s64 + -524288;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r15
	ctx.r5.u64 = ctx.r15.u64;
	// mr r4,r14
	ctx.r4.u64 = ctx.r14.u64;
	// li r3,974
	ctx.r3.s64 = 974;
	// bl 0x881538c0
	ctx.lr = 0x880DCB98;
	sub_881538C0(ctx, base);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r15
	ctx.r5.u64 = ctx.r15.u64;
	// addis r4,r30,56
	ctx.r4.s64 = ctx.r30.s64 + 3670016;
	// li r3,975
	ctx.r3.s64 = 975;
	// bl 0x881538c0
	ctx.lr = 0x880DCBAC;
	sub_881538C0(ctx, base);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r4,r14
	ctx.r4.u64 = ctx.r14.u64;
	// addis r5,r31,-104
	ctx.r5.s64 = ctx.r31.s64 + -6815744;
	// li r3,976
	ctx.r3.s64 = 976;
	// bl 0x881538c0
	ctx.lr = 0x880DCBC0;
	sub_881538C0(ctx, base);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// addis r5,r31,-136
	ctx.r5.s64 = ctx.r31.s64 + -8912896;
	// mr r4,r14
	ctx.r4.u64 = ctx.r14.u64;
	// li r3,977
	ctx.r3.s64 = 977;
	// bl 0x881538c0
	ctx.lr = 0x880DCBD4;
	sub_881538C0(ctx, base);
	// addis r15,r31,-160
	ctx.r15.s64 = ctx.r31.s64 + -10485760;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r15
	ctx.r5.u64 = ctx.r15.u64;
	// addis r4,r30,8
	ctx.r4.s64 = ctx.r30.s64 + 524288;
	// li r3,978
	ctx.r3.s64 = 978;
	// bl 0x881538c0
	ctx.lr = 0x880DCBEC;
	sub_881538C0(ctx, base);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r15
	ctx.r5.u64 = ctx.r15.u64;
	// add r4,r30,r17
	ctx.r4.u64 = ctx.r30.u64 + ctx.r17.u64;
	// li r3,979
	ctx.r3.s64 = 979;
	// bl 0x881538c0
	ctx.lr = 0x880DCC00;
	sub_881538C0(ctx, base);
	// lis r15,32
	ctx.r15.s64 = 2097152;
loc_880DCC04:
	// lwz r11,28(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 28);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x880dcd54
	if (!ctx.cr6.eq) goto loc_880DCD54;
	// lwz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// li r3,980
	ctx.r3.s64 = 980;
	// lwz r10,16(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// lwz r27,44(r29)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r29.u32 + 44);
	// subf r30,r16,r11
	ctx.r30.s64 = ctx.r11.s64 - ctx.r16.s64;
	// add r31,r10,r17
	ctx.r31.u64 = ctx.r10.u64 + ctx.r17.u64;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x881538c0
	ctx.lr = 0x880DCC38;
	sub_881538C0(ctx, base);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// addis r5,r31,-40
	ctx.r5.s64 = ctx.r31.s64 + -2621440;
	// subf r4,r16,r30
	ctx.r4.s64 = ctx.r30.s64 - ctx.r16.s64;
	// li r3,981
	ctx.r3.s64 = 981;
	// bl 0x881538c0
	ctx.lr = 0x880DCC4C;
	sub_881538C0(ctx, base);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// addis r5,r31,-96
	ctx.r5.s64 = ctx.r31.s64 + -6291456;
	// subf r4,r15,r30
	ctx.r4.s64 = ctx.r30.s64 - ctx.r15.s64;
	// li r3,982
	ctx.r3.s64 = 982;
	// bl 0x881538c0
	ctx.lr = 0x880DCC60;
	sub_881538C0(ctx, base);
	// b 0x880dcd54
	goto loc_880DCD54;
loc_880DCC64:
	// lwz r11,28(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 28);
	// cmpwi cr6,r11,14
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 14, ctx.xer);
	// bgt cr6,0x880dcca8
	if (ctx.cr6.gt) goto loc_880DCCA8;
	// lwz r30,12(r29)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// addi r3,r11,951
	ctx.r3.s64 = ctx.r11.s64 + 951;
	// lwz r31,16(r29)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r6,44(r29)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + 44);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// bl 0x881538c0
	ctx.lr = 0x880DCC8C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880dcca8
	if (ctx.cr6.eq) goto loc_880DCCA8;
	// lwz r11,52(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 52);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r11,26,0,5
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 26) & 0xFC000000;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880DCCA8:
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// clrlwi r10,r11,29
	ctx.r10.u64 = ctx.r11.u32 & 0x7;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x880dcd54
	if (!ctx.cr6.eq) goto loc_880DCD54;
	// stw r30,12364(r19)
	PPC_STORE_U32(ctx.r19.u32 + 12364, ctx.r30.u32);
	// stw r31,12372(r20)
	PPC_STORE_U32(ctx.r20.u32 + 12372, ctx.r31.u32);
	// lwz r10,28(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 28);
	// lwz r11,44(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 44);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r4,r11,-1
	ctx.r4.s64 = ctx.r11.s64 + -1;
	// stw r4,12376(r21)
	PPC_STORE_U32(ctx.r21.u32 + 12376, ctx.r4.u32);
	// lwzx r3,r9,r22
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r22.u32);
	// stw r3,12380(r18)
	PPC_STORE_U32(ctx.r18.u32 + 12380, ctx.r3.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880DCCE0;
	sub_880F52C8(ctx, base);
	// mullw r11,r25,r26
	ctx.r11.s64 = int64_t(ctx.r25.s32) * int64_t(ctx.r26.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mullw r10,r11,r26
	ctx.r10.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r26.s32);
	// stw r11,4200(r28)
	PPC_STORE_U32(ctx.r28.u32 + 4200, ctx.r11.u32);
	// lhz r7,4200(r28)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r28.u32 + 4200);
	// addi r25,r10,12345
	ctx.r25.s64 = ctx.r10.s64 + 12345;
	// mulhwu r6,r7,r23
	ctx.r6.u64 = (uint64_t(ctx.r7.u32) * uint64_t(ctx.r23.u32)) >> 32;
	// stw r25,4200(r28)
	PPC_STORE_U32(ctx.r28.u32 + 4200, ctx.r25.u32);
	// rlwinm r11,r6,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 31) & 0x7FFFFFFF;
	// lhz r5,4200(r28)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r28.u32 + 4200);
	// mulhwu r4,r5,r24
	ctx.r4.u64 = (uint64_t(ctx.r5.u32) * uint64_t(ctx.r24.u32)) >> 32;
	// rlwinm r10,r4,28,4,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 28) & 0xFFFFFFF;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r8,r10,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r11,r9
	ctx.r3.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r11,r8,r10
	ctx.r11.u64 = ctx.r8.u64 + ctx.r10.u64;
	// subf r10,r3,r7
	ctx.r10.s64 = ctx.r7.s64 - ctx.r3.s64;
	// subf r9,r11,r5
	ctx.r9.s64 = ctx.r5.s64 - ctx.r11.s64;
	// extsh r11,r10
	ctx.r11.s64 = ctx.r10.s16;
	// extsh r10,r9
	ctx.r10.s64 = ctx.r9.s16;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r4,r11,16
	ctx.r4.s64 = ctx.r11.s64 + 16;
	// addi r5,r10,8
	ctx.r5.s64 = ctx.r10.s64 + 8;
	// bl 0x880f5570
	ctx.lr = 0x880DCD44;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x880dcd54
	if (ctx.cr6.eq) goto loc_880DCD54;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,144(r27)
	PPC_STORE_U32(ctx.r27.u32 + 144, ctx.r11.u32);
loc_880DCD54:
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r29,r29,56
	ctx.r29.s64 = ctx.r29.s64 + 56;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bne 0x880dca7c
	if (!ctx.cr0.eq) goto loc_880DCA7C;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880DCD70"))) PPC_WEAK_FUNC(sub_880DCD70);
PPC_FUNC_IMPL(__imp__sub_880DCD70) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071138
	ctx.lr = 0x880DCD78;
	__savegprlr_20(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lhz r10,2(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 2);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r22,r7
	ctx.r22.u64 = ctx.r7.u64;
	// mr r23,r8
	ctx.r23.u64 = ctx.r8.u64;
	// mr r24,r9
	ctx.r24.u64 = ctx.r9.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x880dce88
	if (!ctx.cr6.gt) goto loc_880DCE88;
	// lwz r31,4(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x880dce88
	if (!ctx.cr6.gt) goto loc_880DCE88;
	// lis r21,-30597
	ctx.r21.s64 = -2005204992;
	// clrlwi r20,r9,31
	ctx.r20.u64 = ctx.r9.u32 & 0x1;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// mr r25,r10
	ctx.r25.u64 = ctx.r10.u64;
	// lwz r26,-11932(r21)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r21.u32 + -11932);
loc_880DCDC4:
	// lbz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// lbz r10,1(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// extsb r9,r11
	ctx.r9.s64 = ctx.r11.s8;
	// extsb r8,r10
	ctx.r8.s64 = ctx.r10.s8;
	// beq cr6,0x880dcdf8
	if (ctx.cr6.eq) goto loc_880DCDF8;
	// rlwinm r7,r9,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r8,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// subf r4,r7,r29
	ctx.r4.s64 = ctx.r29.s64 - ctx.r7.s64;
	// add r5,r11,r28
	ctx.r5.u64 = ctx.r11.u64 + ctx.r28.u64;
	// b 0x880dce08
	goto loc_880DCE08;
loc_880DCDF8:
	// rlwinm r11,r9,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r8,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r11,r29
	ctx.r4.u64 = ctx.r11.u64 + ctx.r29.u64;
	// add r5,r10,r28
	ctx.r5.u64 = ctx.r10.u64 + ctx.r28.u64;
loc_880DCE08:
	// bl 0x881538c0
	ctx.lr = 0x880DCE0C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x880dce54
	if (ctx.cr6.eq) goto loc_880DCE54;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880dce24
	if (ctx.cr6.eq) goto loc_880DCE24;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880DCE24:
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x880dce54
	if (ctx.cr6.eq) goto loc_880DCE54;
	// lwz r11,0(r23)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880dce54
	if (ctx.cr6.eq) goto loc_880DCE54;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880DCE54:
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// beq cr6,0x880dce74
	if (ctx.cr6.eq) goto loc_880DCE74;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880dce74
	if (ctx.cr6.eq) goto loc_880DCE74;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r24,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_880DCE74:
	// addic. r25,r25,-1
	ctx.xer.ca = ctx.r25.u32 > 0;
	ctx.r25.s64 = ctx.r25.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// addi r31,r31,2
	ctx.r31.s64 = ctx.r31.s64 + 2;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// bne 0x880dcdc4
	if (!ctx.cr0.eq) goto loc_880DCDC4;
	// stw r26,-11932(r21)
	PPC_STORE_U32(ctx.r21.u32 + -11932, ctx.r26.u32);
loc_880DCE88:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x88071188
	__restgprlr_20(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880DCE90"))) PPC_WEAK_FUNC(sub_880DCE90);
PPC_FUNC_IMPL(__imp__sub_880DCE90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071120
	ctx.lr = 0x880DCE98;
	__savegprlr_14(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r30,2304(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// li r27,-1
	ctx.r27.s64 = -1;
	// lwz r7,4(r6)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// li r17,0
	ctx.r17.s64 = 0;
	// lwz r18,0(r6)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// addi r21,r30,2396
	ctx.r21.s64 = ctx.r30.s64 + 2396;
	// lwz r10,184(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// addi r15,r30,92
	ctx.r15.s64 = ctx.r30.s64 + 92;
	// lwz r11,168(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// addi r19,r30,7052
	ctx.r19.s64 = ctx.r30.s64 + 7052;
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// li r29,10
	ctx.r29.s64 = 10;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r3,292(r1)
	PPC_STORE_U32(ctx.r1.u32 + 292, ctx.r3.u32);
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// addi r4,r11,5
	ctx.r4.s64 = ctx.r11.s64 + 5;
	// lwz r5,852(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 852);
	// addi r16,r11,2
	ctx.r16.s64 = ctx.r11.s64 + 2;
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r10,2300(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 2300);
	// stw r4,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// addi r14,r16,-2
	ctx.r14.s64 = ctx.r16.s64 + -2;
	// lwz r3,856(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 856);
	// lwz r9,16(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// lwz r8,12(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r7,156(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 156);
	// lwz r6,160(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 160);
	// srawi r4,r7,2
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3) != 0);
	ctx.r4.s64 = ctx.r7.s32 >> 2;
	// addze r10,r4
	temp.s64 = ctx.r4.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r10.s64 = temp.s64;
	// srawi r7,r6,1
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	ctx.r7.s64 = ctx.r6.s32 >> 1;
	// subf r10,r10,r5
	ctx.r10.s64 = ctx.r5.s64 - ctx.r10.s64;
	// addze r6,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r6.s64 = temp.s64;
	// add r25,r10,r11
	ctx.r25.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r11,r6,r3
	ctx.r11.s64 = ctx.r3.s64 - ctx.r6.s64;
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// stw r25,8144(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8144, ctx.r25.u32);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lis r9,-30679
	ctx.r9.s64 = -2010578944;
	// add r20,r11,r8
	ctx.r20.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lis r11,-30680
	ctx.r11.s64 = -2010644480;
	// addi r10,r10,32248
	ctx.r10.s64 = ctx.r10.s64 + 32248;
	// stw r20,8148(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8148, ctx.r20.u32);
	// addi r9,r9,-15272
	ctx.r9.s64 = ctx.r9.s64 + -15272;
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// addi r31,r11,-19912
	ctx.r31.s64 = ctx.r11.s64 + -19912;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
loc_880DCF54:
	// lwz r10,0(r19)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r19.u32 + 0);
	// srawi r9,r10,4
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 4;
	// addze r11,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r11.s64 = temp.s64;
	// srawi r8,r11,5
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1F) != 0);
	ctx.r8.s64 = ctx.r11.s32 >> 5;
	// addze r7,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r7.s64 = temp.s64;
	// srawi r6,r10,4
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r6.s64 = ctx.r10.s32 >> 4;
	// rlwinm r5,r7,5,0,26
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// addze r4,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r4.s64 = temp.s64;
	// subf r23,r5,r11
	ctx.r23.s64 = ctx.r11.s64 - ctx.r5.s64;
	// rlwinm r3,r4,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// cmpwi cr6,r23,31
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 31, ctx.xer);
	// subf r26,r3,r10
	ctx.r26.s64 = ctx.r10.s64 - ctx.r3.s64;
	// bne cr6,0x880dd00c
	if (!ctx.cr6.eq) goto loc_880DD00C;
	// lwz r11,0(r15)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880dd004
	if (!ctx.cr6.eq) goto loc_880DD004;
	// lis r10,-30671
	ctx.r10.s64 = -2010054656;
	// lis r11,16838
	ctx.r11.s64 = 1103495168;
	// ori r9,r11,20077
	ctx.r9.u64 = ctx.r11.u64 | 20077;
	// lwz r11,4200(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4200);
	// mullw r11,r11,r9
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r9.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// stw r11,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r11.u32);
	// lhz r11,4200(r10)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// addi r11,r11,5
	ctx.r11.s64 = ctx.r11.s64 + 5;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bge cr6,0x880dcfe4
	if (!ctx.cr6.lt) goto loc_880DCFE4;
	// lwz r9,92(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,96(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r11.u32);
	// lwzx r11,r8,r7
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// stw r10,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// stw r11,16(r9)
	PPC_STORE_U32(ctx.r9.u32 + 16, ctx.r11.u32);
loc_880DCFE4:
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
	// lwz r3,292(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 292);
	// bl 0x880e27e8
	ctx.lr = 0x880DCFF0;
	sub_880E27E8(ctx, base);
	// li r6,50
	ctx.r6.s64 = 50;
	// li r5,60
	ctx.r5.s64 = 60;
	// li r4,122
	ctx.r4.s64 = 122;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x880e32d0
	ctx.lr = 0x880DD004;
	sub_880E32D0(ctx, base);
loc_880DD004:
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x880dd010
	goto loc_880DD010;
loc_880DD00C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_880DD010:
	// stw r11,0(r15)
	PPC_STORE_U32(ctx.r15.u32 + 0, ctx.r11.u32);
	// addi r9,r27,1
	ctx.r9.s64 = ctx.r27.s64 + 1;
	// lwz r10,-15644(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15644);
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// lwz r11,-15648(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15648);
	// mullw r8,r11,r27
	ctx.r8.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r27.s32);
	// rlwinm r11,r8,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// cntlzw r7,r9
	ctx.r7.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r5,r11,r25
	ctx.r5.u64 = ctx.r11.u64 + ctx.r25.u64;
	// rlwinm r22,r7,27,31,31
	ctx.r22.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// add r11,r10,r20
	ctx.r11.u64 = ctx.r10.u64 + ctx.r20.u64;
	// beq cr6,0x880dd098
	if (ctx.cr6.eq) goto loc_880DD098;
	// addi r10,r23,1
	ctx.r10.s64 = ctx.r23.s64 + 1;
	// addi r9,r31,-15280
	ctx.r9.s64 = ctx.r31.s64 + -15280;
	// srawi r7,r10,5
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1F) != 0);
	ctx.r7.s64 = ctx.r10.s32 >> 5;
	// addi r8,r31,-15280
	ctx.r8.s64 = ctx.r31.s64 + -15280;
	// addze r6,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r6.s64 = temp.s64;
	// addi r4,r9,2
	ctx.r4.s64 = ctx.r9.s64 + 2;
	// rlwinm r3,r6,5,0,26
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFFE0;
	// addi r6,r8,2
	ctx.r6.s64 = ctx.r8.s64 + 2;
	// subf r7,r3,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r3.s64;
	// rlwinm r9,r23,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r3,r7,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lhzx r10,r9,r6
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r6.u32);
	// lhzx r9,r3,r4
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + ctx.r4.u32);
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// extsh r7,r9
	ctx.r7.s64 = ctx.r9.s16;
	// subf r6,r8,r7
	ctx.r6.s64 = ctx.r7.s64 - ctx.r8.s64;
	// mullw r4,r6,r26
	ctx.r4.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r26.s32);
	// srawi r3,r4,4
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0xF) != 0);
	ctx.r3.s64 = ctx.r4.s32 >> 4;
	// addze r10,r3
	temp.s64 = ctx.r3.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r10.s64 = temp.s64;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_880DD098:
	// rlwinm r6,r23,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r4,r31,-15280
	ctx.r4.s64 = ctx.r31.s64 + -15280;
	// addi r10,r31,-15280
	ctx.r10.s64 = ctx.r31.s64 + -15280;
	// addi r3,r31,-256
	ctx.r3.s64 = ctx.r31.s64 + -256;
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// rlwinm r24,r23,3,0,28
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 3) & 0xFFFFFFF8;
	// lhzx r4,r6,r4
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r6.u32 + ctx.r4.u32);
	// mr r9,r22
	ctx.r9.u64 = ctx.r22.u64;
	// mr r7,r18
	ctx.r7.u64 = ctx.r18.u64;
	// extsh r4,r4
	ctx.r4.s64 = ctx.r4.s16;
	// lhzx r6,r6,r10
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r6.u32 + ctx.r10.u32);
	// add r3,r24,r3
	ctx.r3.u64 = ctx.r24.u64 + ctx.r3.u64;
	// mullw r4,r4,r27
	ctx.r4.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r27.s32);
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// rotlwi r6,r6,16
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r6.u32, 16);
	// add r4,r10,r5
	ctx.r4.u64 = ctx.r10.u64 + ctx.r5.u64;
	// add r5,r6,r11
	ctx.r5.u64 = ctx.r6.u64 + ctx.r11.u64;
	// stw r4,12(r19)
	PPC_STORE_U32(ctx.r19.u32 + 12, ctx.r4.u32);
	// mr r6,r14
	ctx.r6.u64 = ctx.r14.u64;
	// stw r5,16(r19)
	PPC_STORE_U32(ctx.r19.u32 + 16, ctx.r5.u32);
	// bl 0x880dcd70
	ctx.lr = 0x880DD0F0;
	sub_880DCD70(ctx, base);
	// addi r3,r31,-15088
	ctx.r3.s64 = ctx.r31.s64 + -15088;
	// rlwinm r28,r23,1,0,30
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,-15632(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15632);
	// lwz r11,-15628(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15628);
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lbzx r9,r28,r3
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r28.u32 + ctx.r3.u32);
	// add r11,r11,r20
	ctx.r11.u64 = ctx.r11.u64 + ctx.r20.u64;
	// extsb r9,r9
	ctx.r9.s64 = ctx.r9.s8;
	// add r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r7,r8,r27
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r27.s32);
	// rlwinm r10,r7,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r10,r25
	ctx.r4.u64 = ctx.r10.u64 + ctx.r25.u64;
	// bne cr6,0x880dd140
	if (!ctx.cr6.eq) goto loc_880DD140;
	// addi r10,r31,-15088
	ctx.r10.s64 = ctx.r31.s64 + -15088;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbzx r9,r28,r10
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r28.u32 + ctx.r10.u32);
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// rlwinm r10,r8,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// b 0x880dd190
	goto loc_880DD190;
loc_880DD140:
	// addi r10,r23,1
	ctx.r10.s64 = ctx.r23.s64 + 1;
	// addi r9,r31,-15088
	ctx.r9.s64 = ctx.r31.s64 + -15088;
	// srawi r7,r10,5
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1F) != 0);
	ctx.r7.s64 = ctx.r10.s32 >> 5;
	// addi r8,r31,-15088
	ctx.r8.s64 = ctx.r31.s64 + -15088;
	// addze r6,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r6.s64 = temp.s64;
	// addi r5,r9,1
	ctx.r5.s64 = ctx.r9.s64 + 1;
	// rlwinm r3,r6,5,0,26
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFFE0;
	// addi r9,r8,1
	ctx.r9.s64 = ctx.r8.s64 + 1;
	// subf r8,r3,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r3.s64;
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lbzx r6,r28,r5
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r28.u32 + ctx.r5.u32);
	// extsb r10,r6
	ctx.r10.s64 = ctx.r6.s8;
	// lbzx r5,r7,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r9.u32);
	// extsb r3,r5
	ctx.r3.s64 = ctx.r5.s8;
	// subf r9,r10,r3
	ctx.r9.s64 = ctx.r3.s64 - ctx.r10.s64;
	// mullw r8,r9,r26
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r26.s32);
	// srawi r7,r8,4
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xF) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 4;
	// addze r9,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r9.s64 = temp.s64;
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rlwinm r10,r6,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
loc_880DD190:
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r9,6380(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6380);
	// lwz r11,912(r21)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r21.u32 + 912);
	// li r10,30
	ctx.r10.s64 = 30;
	// lwz r7,908(r21)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r21.u32 + 908);
	// addi r3,r31,-512
	ctx.r3.s64 = ctx.r31.s64 + -512;
	// divw r10,r9,r10
	ctx.r10.s32 = ppc_divw(ctx.r9.s32, ctx.r10.s32);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// divw r11,r11,r29
	ctx.r11.s32 = ppc_divw(ctx.r11.s32, ctx.r29.s32);
	// mr r9,r22
	ctx.r9.u64 = ctx.r22.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// divw r10,r7,r29
	ctx.r10.s32 = ppc_divw(ctx.r7.s32, ctx.r29.s32);
	// mr r7,r18
	ctx.r7.u64 = ctx.r18.u64;
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// add r5,r11,r5
	ctx.r5.u64 = ctx.r11.u64 + ctx.r5.u64;
	// add r4,r10,r4
	ctx.r4.u64 = ctx.r10.u64 + ctx.r4.u64;
	// add r3,r24,r3
	ctx.r3.u64 = ctx.r24.u64 + ctx.r3.u64;
	// bl 0x880dcd70
	ctx.lr = 0x880DD1D8;
	sub_880DCD70(ctx, base);
	// addi r6,r31,-15152
	ctx.r6.s64 = ctx.r31.s64 + -15152;
	// lwz r10,-15640(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15640);
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// lwz r11,-15636(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15636);
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lbzx r5,r28,r6
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r28.u32 + ctx.r6.u32);
	// add r11,r11,r20
	ctx.r11.u64 = ctx.r11.u64 + ctx.r20.u64;
	// extsb r9,r5
	ctx.r9.s64 = ctx.r5.s8;
	// add r4,r9,r10
	ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r3,r4,r27
	ctx.r3.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r27.s32);
	// rlwinm r10,r3,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r10,r25
	ctx.r4.u64 = ctx.r10.u64 + ctx.r25.u64;
	// bne cr6,0x880dd224
	if (!ctx.cr6.eq) goto loc_880DD224;
	// addi r10,r31,-15152
	ctx.r10.s64 = ctx.r31.s64 + -15152;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbzx r9,r28,r10
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r28.u32 + ctx.r10.u32);
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// rlwinm r10,r8,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// b 0x880dd274
	goto loc_880DD274;
loc_880DD224:
	// addi r10,r23,1
	ctx.r10.s64 = ctx.r23.s64 + 1;
	// addi r9,r31,-15152
	ctx.r9.s64 = ctx.r31.s64 + -15152;
	// srawi r7,r10,5
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1F) != 0);
	ctx.r7.s64 = ctx.r10.s32 >> 5;
	// addi r8,r31,-15152
	ctx.r8.s64 = ctx.r31.s64 + -15152;
	// addze r6,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r6.s64 = temp.s64;
	// addi r5,r9,1
	ctx.r5.s64 = ctx.r9.s64 + 1;
	// rlwinm r3,r6,5,0,26
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFFE0;
	// addi r9,r8,1
	ctx.r9.s64 = ctx.r8.s64 + 1;
	// subf r8,r3,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r3.s64;
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lbzx r6,r28,r5
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r28.u32 + ctx.r5.u32);
	// extsb r10,r6
	ctx.r10.s64 = ctx.r6.s8;
	// lbzx r5,r7,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r9.u32);
	// extsb r3,r5
	ctx.r3.s64 = ctx.r5.s8;
	// subf r9,r10,r3
	ctx.r9.s64 = ctx.r3.s64 - ctx.r10.s64;
	// mullw r8,r9,r26
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r26.s32);
	// srawi r7,r8,4
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xF) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 4;
	// addze r9,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r9.s64 = temp.s64;
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rlwinm r10,r6,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
loc_880DD274:
	// lwz r6,284(r21)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r21.u32 + 284);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwzu r11,288(r21)
	ea = 288 + ctx.r21.u32;
	ctx.r11.u64 = PPC_LOAD_U32(ea);
	ctx.r21.u32 = ea;
	// li r7,14
	ctx.r7.s64 = 14;
	// lwz r28,6476(r30)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6476);
	// addi r3,r31,-768
	ctx.r3.s64 = ctx.r31.s64 + -768;
	// divw r10,r11,r29
	ctx.r10.s32 = ppc_divw(ctx.r11.s32, ctx.r29.s32);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// divw r11,r28,r7
	ctx.r11.s32 = ppc_divw(ctx.r28.s32, ctx.r7.s32);
	// mr r9,r22
	ctx.r9.u64 = ctx.r22.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// divw r10,r6,r29
	ctx.r10.s32 = ppc_divw(ctx.r6.s32, ctx.r29.s32);
	// mr r7,r18
	ctx.r7.u64 = ctx.r18.u64;
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// add r5,r11,r5
	ctx.r5.u64 = ctx.r11.u64 + ctx.r5.u64;
	// add r4,r10,r4
	ctx.r4.u64 = ctx.r10.u64 + ctx.r4.u64;
	// add r3,r24,r3
	ctx.r3.u64 = ctx.r24.u64 + ctx.r3.u64;
	// bl 0x880dcd70
	ctx.lr = 0x880DD2BC;
	sub_880DCD70(ctx, base);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// neg r27,r27
	ctx.r27.s64 = -ctx.r27.s64;
	// addi r15,r15,4
	ctx.r15.s64 = ctx.r15.s64 + 4;
	// addi r19,r19,84
	ctx.r19.s64 = ctx.r19.s64 + 84;
	// cmpwi cr6,r17,2
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 2, ctx.xer);
	// blt cr6,0x880dcf54
	if (ctx.cr6.lt) goto loc_880DCF54;
	// lwz r11,6524(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6524);
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// stw r25,6644(r30)
	PPC_STORE_U32(ctx.r30.u32 + 6644, ctx.r25.u32);
	// li r3,20649
	ctx.r3.s64 = 20649;
	// divw r11,r11,r29
	ctx.r11.s32 = ppc_divw(ctx.r11.s32, ctx.r29.s32);
	// stw r20,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r20.u32);
	// add r26,r11,r20
	ctx.r26.u64 = ctx.r11.u64 + ctx.r20.u64;
	// stw r26,6648(r30)
	PPC_STORE_U32(ctx.r30.u32 + 6648, ctx.r26.u32);
	// lwz r8,5608(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5608);
	// lwz r9,1196(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 1196);
	// divw r9,r9,r29
	ctx.r9.s32 = ppc_divw(ctx.r9.s32, ctx.r29.s32);
	// lwz r11,-15668(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15668);
	// rlwinm r10,r11,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// divw r8,r8,r29
	ctx.r8.s32 = ppc_divw(ctx.r8.s32, ctx.r29.s32);
	// lwz r11,-15672(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15672);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rlwinm r28,r11,16,0,15
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// add r27,r8,r25
	ctx.r27.u64 = ctx.r8.u64 + ctx.r25.u64;
	// add r24,r10,r26
	ctx.r24.u64 = ctx.r10.u64 + ctx.r26.u64;
	// add r4,r28,r27
	ctx.r4.u64 = ctx.r28.u64 + ctx.r27.u64;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// bl 0x881538c0
	ctx.lr = 0x880DD32C;
	sub_881538C0(ctx, base);
	// lis r22,-30597
	ctx.r22.s64 = -2005204992;
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// beq cr6,0x880dd388
	if (ctx.cr6.eq) goto loc_880DD388;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880dd348
	if (ctx.cr6.eq) goto loc_880DD348;
	// lwz r11,0(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880DD348:
	// lwz r23,84(r1)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x880dd38c
	if (ctx.cr6.eq) goto loc_880DD38C;
	// lwz r11,0(r23)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880dd38c
	if (ctx.cr6.eq) goto loc_880DD38C;
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-11932(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + -11932);
	// rlwimi r9,r10,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// addi r15,r11,1
	ctx.r15.s64 = ctx.r11.s64 + 1;
	// or r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 | ctx.r8.u64;
	// stw r15,-11932(r22)
	PPC_STORE_U32(ctx.r22.u32 + -11932, ctx.r15.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// b 0x880dd390
	goto loc_880DD390;
loc_880DD388:
	// lwz r23,84(r1)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_880DD38C:
	// lwz r15,-11932(r22)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r22.u32 + -11932);
loc_880DD390:
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// subf r4,r28,r27
	ctx.r4.s64 = ctx.r27.s64 - ctx.r28.s64;
	// li r3,20649
	ctx.r3.s64 = 20649;
	// bl 0x881538c0
	ctx.lr = 0x880DD3A4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// beq cr6,0x880dd3f0
	if (ctx.cr6.eq) goto loc_880DD3F0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880dd3bc
	if (ctx.cr6.eq) goto loc_880DD3BC;
	// lwz r11,0(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880DD3BC:
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x880dd3f0
	if (ctx.cr6.eq) goto loc_880DD3F0;
	// lwz r11,0(r23)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880dd404
	if (ctx.cr6.eq) goto loc_880DD404;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r15,-11932(r22)
	PPC_STORE_U32(ctx.r22.u32 + -11932, ctx.r15.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880DD3F0:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880dd404
	if (ctx.cr6.eq) goto loc_880DD404;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// oris r10,r11,1024
	ctx.r10.u64 = ctx.r11.u64 | 67108864;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_880DD404:
	// lwz r11,-15680(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15680);
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// lwz r10,908(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 908);
	// li r3,20648
	ctx.r3.s64 = 20648;
	// lwz r9,5656(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5656);
	// rlwinm r28,r11,16,0,15
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// divw r11,r10,r29
	ctx.r11.s32 = ppc_divw(ctx.r10.s32, ctx.r29.s32);
	// divw r10,r9,r29
	ctx.r10.s32 = ppc_divw(ctx.r9.s32, ctx.r29.s32);
	// add r27,r11,r26
	ctx.r27.u64 = ctx.r11.u64 + ctx.r26.u64;
	// add r24,r10,r25
	ctx.r24.u64 = ctx.r10.u64 + ctx.r25.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// add r4,r28,r24
	ctx.r4.u64 = ctx.r28.u64 + ctx.r24.u64;
	// bl 0x881538c0
	ctx.lr = 0x880DD438;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// beq cr6,0x880dd484
	if (ctx.cr6.eq) goto loc_880DD484;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880dd450
	if (ctx.cr6.eq) goto loc_880DD450;
	// lwz r11,0(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880DD450:
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x880dd484
	if (ctx.cr6.eq) goto loc_880DD484;
	// lwz r11,0(r23)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880dd484
	if (ctx.cr6.eq) goto loc_880DD484;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r15,-11932(r22)
	PPC_STORE_U32(ctx.r22.u32 + -11932, ctx.r15.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880DD484:
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// subf r4,r28,r24
	ctx.r4.s64 = ctx.r24.s64 - ctx.r28.s64;
	// li r3,20648
	ctx.r3.s64 = 20648;
	// bl 0x881538c0
	ctx.lr = 0x880DD498;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// beq cr6,0x880dd4e4
	if (ctx.cr6.eq) goto loc_880DD4E4;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880dd4b0
	if (ctx.cr6.eq) goto loc_880DD4B0;
	// lwz r11,0(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880DD4B0:
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x880dd4e4
	if (ctx.cr6.eq) goto loc_880DD4E4;
	// lwz r11,0(r23)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880dd4f8
	if (ctx.cr6.eq) goto loc_880DD4F8;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r15,-11932(r22)
	PPC_STORE_U32(ctx.r22.u32 + -11932, ctx.r15.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880DD4E4:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880dd4f8
	if (ctx.cr6.eq) goto loc_880DD4F8;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// oris r10,r11,1024
	ctx.r10.u64 = ctx.r11.u64 | 67108864;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_880DD4F8:
	// lwz r14,84(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r23,r30,8724
	ctx.r23.s64 = ctx.r30.s64 + 8724;
	// li r27,-1
	ctx.r27.s64 = -1;
	// addi r28,r30,4456
	ctx.r28.s64 = ctx.r30.s64 + 4456;
	// addi r24,r30,7400
	ctx.r24.s64 = ctx.r30.s64 + 7400;
	// li r21,2
	ctx.r21.s64 = 2;
loc_880DD510:
	// lwz r11,52(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 52);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x880dd618
	if (ctx.cr6.lt) goto loc_880DD618;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x880dd6a8
	if (!ctx.cr6.lt) goto loc_880DD6A8;
	// lwz r11,-15560(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15560);
	// addi r3,r27,1
	ctx.r3.s64 = ctx.r27.s64 + 1;
	// lwz r10,5704(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5704);
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// mullw r9,r11,r27
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r27.s32);
	// lwz r11,-15556(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15556);
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r5,4(r28)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// divw r7,r10,r29
	ctx.r7.s32 = ppc_divw(ctx.r10.s32, ctx.r29.s32);
	// rlwinm r9,r9,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r8,r11,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r7,r9
	ctx.r11.u64 = ctx.r7.u64 + ctx.r9.u64;
	// divw r9,r4,r29
	ctx.r9.s32 = ppc_divw(ctx.r4.s32, ctx.r29.s32);
	// divw r10,r5,r29
	ctx.r10.s32 = ppc_divw(ctx.r5.s32, ctx.r29.s32);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r4,r11,r25
	ctx.r4.u64 = ctx.r11.u64 + ctx.r25.u64;
	// cntlzw r11,r3
	ctx.r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// add r5,r10,r26
	ctx.r5.u64 = ctx.r10.u64 + ctx.r26.u64;
	// li r3,27202
	ctx.r3.s64 = 27202;
	// rlwinm r22,r11,27,31,31
	ctx.r22.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// bl 0x881538c0
	ctx.lr = 0x880DD57C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// beq cr6,0x880dd5c4
	if (ctx.cr6.eq) goto loc_880DD5C4;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880dd594
	if (ctx.cr6.eq) goto loc_880DD594;
	// lwz r11,0(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880DD594:
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x880dd5c4
	if (ctx.cr6.eq) goto loc_880DD5C4;
	// lwz r11,0(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880dd5c4
	if (ctx.cr6.eq) goto loc_880DD5C4;
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
loc_880DD5C4:
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// beq cr6,0x880dd5e4
	if (ctx.cr6.eq) goto loc_880DD5E4;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880dd5e4
	if (ctx.cr6.eq) goto loc_880DD5E4;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r22,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_880DD5E4:
	// lwz r11,-15544(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15544);
	// lwz r10,5752(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5752);
	// mullw r9,r11,r27
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r27.s32);
	// lwz r11,-15540(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15540);
	// lwz r7,100(r28)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r28.u32 + 100);
	// lwz r6,96(r28)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r28.u32 + 96);
	// rlwinm r9,r9,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// divw r10,r10,r29
	ctx.r10.s32 = ppc_divw(ctx.r10.s32, ctx.r29.s32);
	// rlwinm r8,r11,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// divw r11,r7,r29
	ctx.r11.s32 = ppc_divw(ctx.r7.s32, ctx.r29.s32);
	// divw r9,r6,r29
	ctx.r9.s32 = ppc_divw(ctx.r6.s32, ctx.r29.s32);
	// b 0x880dd690
	goto loc_880DD690;
loc_880DD618:
	// lwz r11,-15552(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15552);
	// lwz r10,5704(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5704);
	// mullw r9,r11,r27
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r27.s32);
	// lwz r11,-15548(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15548);
	// lwz r7,4(r28)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// lwz r6,0(r28)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// divw r10,r10,r29
	ctx.r10.s32 = ppc_divw(ctx.r10.s32, ctx.r29.s32);
	// rlwinm r9,r9,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r8,r11,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// divw r9,r6,r29
	ctx.r9.s32 = ppc_divw(ctx.r6.s32, ctx.r29.s32);
	// divw r11,r7,r29
	ctx.r11.s32 = ppc_divw(ctx.r7.s32, ctx.r29.s32);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r10,r10,r25
	ctx.r10.u64 = ctx.r10.u64 + ctx.r25.u64;
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// stw r10,-4(r23)
	PPC_STORE_U32(ctx.r23.u32 + -4, ctx.r10.u32);
	// stw r11,0(r23)
	PPC_STORE_U32(ctx.r23.u32 + 0, ctx.r11.u32);
	// lwz r5,5752(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5752);
	// lwz r4,100(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + 100);
	// lwz r3,96(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 96);
	// lwz r11,-15544(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15544);
	// mullw r11,r11,r27
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r27.s32);
	// rlwinm r9,r11,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lwz r11,-15540(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15540);
	// divw r10,r5,r29
	ctx.r10.s32 = ppc_divw(ctx.r5.s32, ctx.r29.s32);
	// rlwinm r8,r11,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// divw r11,r4,r29
	ctx.r11.s32 = ppc_divw(ctx.r4.s32, ctx.r29.s32);
	// divw r9,r3,r29
	ctx.r9.s32 = ppc_divw(ctx.r3.s32, ctx.r29.s32);
loc_880DD690:
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r10,r10,r25
	ctx.r10.u64 = ctx.r10.u64 + ctx.r25.u64;
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// stw r10,0(r24)
	PPC_STORE_U32(ctx.r24.u32 + 0, ctx.r10.u32);
	// stw r11,4(r24)
	PPC_STORE_U32(ctx.r24.u32 + 4, ctx.r11.u32);
loc_880DD6A8:
	// addic. r21,r21,-1
	ctx.xer.ca = ctx.r21.u32 > 0;
	ctx.r21.s64 = ctx.r21.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// neg r27,r27
	ctx.r27.s64 = -ctx.r27.s64;
	// addi r24,r24,84
	ctx.r24.s64 = ctx.r24.s64 + 84;
	// addi r23,r23,144
	ctx.r23.s64 = ctx.r23.s64 + 144;
	// addi r28,r28,288
	ctx.r28.s64 = ctx.r28.s64 + 288;
	// bne 0x880dd510
	if (!ctx.cr0.eq) goto loc_880DD510;
	// lwz r11,-15660(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15660);
	// lis r21,-30597
	ctx.r21.s64 = -2005204992;
	// lwz r10,908(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 908);
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// lwz r7,5656(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5656);
	// rlwinm r9,r11,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// divw r8,r10,r29
	ctx.r8.s32 = ppc_divw(ctx.r10.s32, ctx.r29.s32);
	// lwz r11,-15664(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15664);
	// divw r10,r7,r29
	ctx.r10.s32 = ppc_divw(ctx.r7.s32, ctx.r29.s32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// stw r15,-11932(r21)
	PPC_STORE_U32(ctx.r21.u32 + -11932, ctx.r15.u32);
	// rlwinm r28,r11,16,0,15
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// add r27,r9,r26
	ctx.r27.u64 = ctx.r9.u64 + ctx.r26.u64;
	// add r24,r10,r25
	ctx.r24.u64 = ctx.r10.u64 + ctx.r25.u64;
	// li r3,20650
	ctx.r3.s64 = 20650;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// add r4,r28,r24
	ctx.r4.u64 = ctx.r28.u64 + ctx.r24.u64;
	// bl 0x881538c0
	ctx.lr = 0x880DD708;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// beq cr6,0x880dd754
	if (ctx.cr6.eq) goto loc_880DD754;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880dd720
	if (ctx.cr6.eq) goto loc_880DD720;
	// lwz r11,0(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880DD720:
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x880dd754
	if (ctx.cr6.eq) goto loc_880DD754;
	// lwz r11,0(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880dd754
	if (ctx.cr6.eq) goto loc_880DD754;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r15,-11932(r21)
	PPC_STORE_U32(ctx.r21.u32 + -11932, ctx.r15.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880DD754:
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// subf r4,r28,r24
	ctx.r4.s64 = ctx.r24.s64 - ctx.r28.s64;
	// li r3,20650
	ctx.r3.s64 = 20650;
	// bl 0x881538c0
	ctx.lr = 0x880DD768;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// beq cr6,0x880dd7b4
	if (ctx.cr6.eq) goto loc_880DD7B4;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880dd780
	if (ctx.cr6.eq) goto loc_880DD780;
	// lwz r11,0(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880DD780:
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x880dd7b4
	if (ctx.cr6.eq) goto loc_880DD7B4;
	// lwz r11,0(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880dd7c8
	if (ctx.cr6.eq) goto loc_880DD7C8;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r15,-11932(r21)
	PPC_STORE_U32(ctx.r21.u32 + -11932, ctx.r15.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880DD7B4:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880dd7c8
	if (ctx.cr6.eq) goto loc_880DD7C8;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// oris r10,r11,1024
	ctx.r10.u64 = ctx.r11.u64 | 67108864;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_880DD7C8:
	// lwz r11,-15508(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15508);
	// lis r9,-30714
	ctx.r9.s64 = -2012872704;
	// lwz r8,6716(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6716);
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// rlwinm r10,r11,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lwz r11,-15512(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15512);
	// addi r22,r9,9552
	ctx.r22.s64 = ctx.r9.s64 + 9552;
	// lwz r7,5656(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5656);
	// rlwinm r23,r8,2,21,29
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x7FC;
	// lwz r5,908(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 908);
	// rlwinm r9,r11,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// divw r11,r7,r29
	ctx.r11.s32 = ppc_divw(ctx.r7.s32, ctx.r29.s32);
	// divw r8,r5,r29
	ctx.r8.s32 = ppc_divw(ctx.r5.s32, ctx.r29.s32);
	// add r28,r11,r25
	ctx.r28.u64 = ctx.r11.u64 + ctx.r25.u64;
	// lwzx r4,r23,r22
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r23.u32 + ctx.r22.u32);
	// li r3,20652
	ctx.r3.s64 = 20652;
	// mulli r11,r4,240
	ctx.r11.s64 = ctx.r4.s64 * 240;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mulli r10,r4,400
	ctx.r10.s64 = ctx.r4.s64 * 400;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r27,r10,r9
	ctx.r27.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r24,r11,r26
	ctx.r24.u64 = ctx.r11.u64 + ctx.r26.u64;
	// add r4,r27,r28
	ctx.r4.u64 = ctx.r27.u64 + ctx.r28.u64;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// bl 0x881538c0
	ctx.lr = 0x880DD82C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// beq cr6,0x880dd878
	if (ctx.cr6.eq) goto loc_880DD878;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880dd844
	if (ctx.cr6.eq) goto loc_880DD844;
	// lwz r11,0(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880DD844:
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x880dd878
	if (ctx.cr6.eq) goto loc_880DD878;
	// lwz r11,0(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880dd878
	if (ctx.cr6.eq) goto loc_880DD878;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r15,-11932(r21)
	PPC_STORE_U32(ctx.r21.u32 + -11932, ctx.r15.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880DD878:
	// subf r11,r27,r28
	ctx.r11.s64 = ctx.r28.s64 - ctx.r27.s64;
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// addis r4,r11,4
	ctx.r4.s64 = ctx.r11.s64 + 262144;
	// li r3,20652
	ctx.r3.s64 = 20652;
	// bl 0x881538c0
	ctx.lr = 0x880DD890;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// beq cr6,0x880dd8dc
	if (ctx.cr6.eq) goto loc_880DD8DC;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880dd8a8
	if (ctx.cr6.eq) goto loc_880DD8A8;
	// lwz r11,0(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880DD8A8:
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x880dd8dc
	if (ctx.cr6.eq) goto loc_880DD8DC;
	// lwz r11,0(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880dd8f0
	if (ctx.cr6.eq) goto loc_880DD8F0;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r15,-11932(r21)
	PPC_STORE_U32(ctx.r21.u32 + -11932, ctx.r15.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880DD8DC:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880dd8f0
	if (ctx.cr6.eq) goto loc_880DD8F0;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// oris r10,r11,1024
	ctx.r10.u64 = ctx.r11.u64 | 67108864;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_880DD8F0:
	// lwzx r10,r23,r22
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r23.u32 + ctx.r22.u32);
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// lwz r11,-15500(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15500);
	// li r3,20651
	ctx.r3.s64 = 20651;
	// mulli r9,r10,352
	ctx.r9.s64 = ctx.r10.s64 * 352;
	// lwz r8,908(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 908);
	// lwz r7,5656(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5656);
	// lwz r10,-15504(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15504);
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// divw r8,r8,r29
	ctx.r8.s32 = ppc_divw(ctx.r8.s32, ctx.r29.s32);
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// divw r11,r7,r29
	ctx.r11.s32 = ppc_divw(ctx.r7.s32, ctx.r29.s32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r25
	ctx.r11.u64 = ctx.r11.u64 + ctx.r25.u64;
	// add r5,r9,r26
	ctx.r5.u64 = ctx.r9.u64 + ctx.r26.u64;
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bl 0x881538c0
	ctx.lr = 0x880DD938;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// beq cr6,0x880dd984
	if (ctx.cr6.eq) goto loc_880DD984;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880dd950
	if (ctx.cr6.eq) goto loc_880DD950;
	// lwz r11,0(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880DD950:
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x880dd984
	if (ctx.cr6.eq) goto loc_880DD984;
	// lwz r11,0(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880dd984
	if (ctx.cr6.eq) goto loc_880DD984;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r15,-11932(r21)
	PPC_STORE_U32(ctx.r21.u32 + -11932, ctx.r15.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880DD984:
	// addi r11,r31,-15680
	ctx.r11.s64 = ctx.r31.s64 + -15680;
	// li r24,-1
	ctx.r24.s64 = -1;
	// li r21,0
	ctx.r21.s64 = 0;
	// addi r22,r11,144
	ctx.r22.s64 = ctx.r11.s64 + 144;
	// addi r27,r30,3784
	ctx.r27.s64 = ctx.r30.s64 + 3784;
	// addi r23,r30,8436
	ctx.r23.s64 = ctx.r30.s64 + 8436;
	// addi r28,r30,6896
	ctx.r28.s64 = ctx.r30.s64 + 6896;
	// li r17,6
	ctx.r17.s64 = 6;
	// li r19,14
	ctx.r19.s64 = 14;
loc_880DD9A8:
	// addi r10,r24,1
	ctx.r10.s64 = ctx.r24.s64 + 1;
	// lwz r11,52(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 52);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// rlwinm r20,r9,27,31,31
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bgt cr6,0x880ddcb0
	if (ctx.cr6.gt) goto loc_880DDCB0;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x880ddaf8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_880DDAF8;
	// bdzf 4*cr6+eq,0x880ddaf8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_880DDAF8;
	// bne cr6,0x880ddc10
	if (!ctx.cr6.eq) goto loc_880DDC10;
	// lwz r11,-12(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -12);
	// divw r10,r11,r17
	ctx.r10.s32 = ppc_divw(ctx.r11.s32, ctx.r17.s32);
	// clrlwi r9,r10,29
	ctx.r9.u64 = ctx.r10.u32 & 0x7;
	// cmplwi cr6,r9,4
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 4, ctx.xer);
	// blt cr6,0x880dd9ec
	if (ctx.cr6.lt) goto loc_880DD9EC;
	// subfic r9,r9,8
	ctx.xer.ca = ctx.r9.u32 <= 8;
	ctx.r9.s64 = 8 - ctx.r9.s64;
loc_880DD9EC:
	// lwz r8,4(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// addi r10,r31,-15488
	ctx.r10.s64 = ctx.r31.s64 + -15488;
	// stw r8,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// rlwinm r5,r9,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r11,-15656(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15656);
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// lwz r4,5704(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5704);
	// mullw r3,r11,r24
	ctx.r3.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r24.s32);
	// lwz r11,-15652(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15652);
	// lwz r7,0(r27)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// divw r10,r4,r19
	ctx.r10.s32 = ppc_divw(ctx.r4.s32, ctx.r19.s32);
	// rlwinm r8,r3,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r6,r11,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// divw r7,r7,r29
	ctx.r7.s32 = ppc_divw(ctx.r7.s32, ctx.r29.s32);
	// addi r8,r31,-15488
	ctx.r8.s64 = ctx.r31.s64 + -15488;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lwz r4,96(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// addi r3,r9,20622
	ctx.r3.s64 = ctx.r9.s64 + 20622;
	// add r10,r10,r25
	ctx.r10.u64 = ctx.r10.u64 + ctx.r25.u64;
	// divw r11,r4,r29
	ctx.r11.s32 = ppc_divw(ctx.r4.s32, ctx.r29.s32);
	// lwz r4,92(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// stw r10,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r10.u32);
	// addi r9,r8,1
	ctx.r9.s64 = ctx.r8.s64 + 1;
	// add r11,r11,r6
	ctx.r11.u64 = ctx.r11.u64 + ctx.r6.u64;
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// stw r11,4(r28)
	PPC_STORE_U32(ctx.r28.u32 + 4, ctx.r11.u32);
	// stw r10,-4(r23)
	PPC_STORE_U32(ctx.r23.u32 + -4, ctx.r10.u32);
	// stw r11,0(r23)
	PPC_STORE_U32(ctx.r23.u32 + 0, ctx.r11.u32);
	// lbzx r8,r5,r4
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r4.u32);
	// extsb r7,r8
	ctx.r7.s64 = ctx.r8.s8;
	// lbzx r5,r5,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r9.u32);
	// mullw r4,r7,r24
	ctx.r4.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r24.s32);
	// extsb r9,r5
	ctx.r9.s64 = ctx.r5.s8;
	// rlwinm r8,r4,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r9,r9,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r8,r10
	ctx.r4.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r5,r9,r11
	ctx.r5.u64 = ctx.r9.u64 + ctx.r11.u64;
	// bl 0x881538c0
	ctx.lr = 0x880DDA8C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// beq cr6,0x880ddad4
	if (ctx.cr6.eq) goto loc_880DDAD4;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880ddaa4
	if (ctx.cr6.eq) goto loc_880DDAA4;
	// lwz r11,0(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880DDAA4:
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x880ddad4
	if (ctx.cr6.eq) goto loc_880DDAD4;
	// lwz r11,0(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880ddad4
	if (ctx.cr6.eq) goto loc_880DDAD4;
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
loc_880DDAD4:
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// beq cr6,0x880ddcb0
	if (ctx.cr6.eq) goto loc_880DDCB0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880ddcb0
	if (ctx.cr6.eq) goto loc_880DDCB0;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r20,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// b 0x880ddcb0
	goto loc_880DDCB0;
loc_880DDAF8:
	// lwz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// addi r5,r31,-15488
	ctx.r5.s64 = ctx.r31.s64 + -15488;
	// lwz r11,-15656(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15656);
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r4,5704(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5704);
	// mullw r3,r11,r24
	ctx.r3.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r24.s32);
	// lwz r11,-15652(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15652);
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// lwz r9,-12(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + -12);
	// divw r10,r4,r19
	ctx.r10.s32 = ppc_divw(ctx.r4.s32, ctx.r19.s32);
	// lwz r4,96(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// rlwinm r8,r3,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r7,r11,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// divw r8,r4,r29
	ctx.r8.s32 = ppc_divw(ctx.r4.s32, ctx.r29.s32);
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// addi r8,r31,-15488
	ctx.r8.s64 = ctx.r31.s64 + -15488;
	// divw r11,r3,r29
	ctx.r11.s32 = ppc_divw(ctx.r3.s32, ctx.r29.s32);
	// add r10,r10,r25
	ctx.r10.u64 = ctx.r10.u64 + ctx.r25.u64;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// stw r10,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r10.u32);
	// rlwinm r7,r9,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r4,r8,1
	ctx.r4.s64 = ctx.r8.s64 + 1;
	// stw r11,4(r28)
	PPC_STORE_U32(ctx.r28.u32 + 4, ctx.r11.u32);
	// addi r3,r9,20622
	ctx.r3.s64 = ctx.r9.s64 + 20622;
	// stw r11,0(r23)
	PPC_STORE_U32(ctx.r23.u32 + 0, ctx.r11.u32);
	// stw r10,-4(r23)
	PPC_STORE_U32(ctx.r23.u32 + -4, ctx.r10.u32);
	// lbzx r8,r7,r5
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r5.u32);
	// lbzx r9,r7,r4
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r4.u32);
	// extsb r4,r9
	ctx.r4.s64 = ctx.r9.s8;
	// extsb r7,r8
	ctx.r7.s64 = ctx.r8.s8;
	// rlwinm r9,r4,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// mullw r5,r7,r24
	ctx.r5.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r24.s32);
	// rlwinm r8,r5,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// add r5,r9,r11
	ctx.r5.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r4,r8,r10
	ctx.r4.u64 = ctx.r8.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x880DDB9C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// beq cr6,0x880ddbec
	if (ctx.cr6.eq) goto loc_880DDBEC;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880ddbb4
	if (ctx.cr6.eq) goto loc_880DDBB4;
	// lwz r11,0(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880DDBB4:
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x880ddbec
	if (ctx.cr6.eq) goto loc_880DDBEC;
	// lwz r11,0(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880ddbec
	if (ctx.cr6.eq) goto loc_880DDBEC;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stw r15,-11932(r11)
	PPC_STORE_U32(ctx.r11.u32 + -11932, ctx.r15.u32);
loc_880DDBEC:
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// beq cr6,0x880ddcb0
	if (ctx.cr6.eq) goto loc_880DDCB0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880ddcb0
	if (ctx.cr6.eq) goto loc_880DDCB0;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r20,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// b 0x880ddcb0
	goto loc_880DDCB0;
loc_880DDC10:
	// lwz r10,0(r22)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// lwz r11,5704(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5704);
	// addi r3,r21,20646
	ctx.r3.s64 = ctx.r21.s64 + 20646;
	// rlwinm r9,r10,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// lwz r5,0(r27)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// divw r11,r11,r19
	ctx.r11.s32 = ppc_divw(ctx.r11.s32, ctx.r19.s32);
	// lwz r8,4(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// lwz r7,4(r22)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r22.u32 + 4);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// divw r9,r5,r29
	ctx.r9.s32 = ppc_divw(ctx.r5.s32, ctx.r29.s32);
	// divw r8,r8,r29
	ctx.r8.s32 = ppc_divw(ctx.r8.s32, ctx.r29.s32);
	// rlwinm r10,r7,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r4,r11,r25
	ctx.r4.u64 = ctx.r11.u64 + ctx.r25.u64;
	// add r5,r10,r26
	ctx.r5.u64 = ctx.r10.u64 + ctx.r26.u64;
	// stw r4,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r4.u32);
	// stw r5,4(r28)
	PPC_STORE_U32(ctx.r28.u32 + 4, ctx.r5.u32);
	// bl 0x881538c0
	ctx.lr = 0x880DDC60;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// beq cr6,0x880ddcb0
	if (ctx.cr6.eq) goto loc_880DDCB0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880ddc78
	if (ctx.cr6.eq) goto loc_880DDC78;
	// lwz r11,0(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880DDC78:
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x880ddcb0
	if (ctx.cr6.eq) goto loc_880DDCB0;
	// lwz r11,0(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880ddcb0
	if (ctx.cr6.eq) goto loc_880DDCB0;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stw r15,-11932(r11)
	PPC_STORE_U32(ctx.r11.u32 + -11932, ctx.r15.u32);
loc_880DDCB0:
	// addi r11,r31,-15680
	ctx.r11.s64 = ctx.r31.s64 + -15680;
	// addi r22,r22,8
	ctx.r22.s64 = ctx.r22.s64 + 8;
	// addi r11,r11,160
	ctx.r11.s64 = ctx.r11.s64 + 160;
	// neg r24,r24
	ctx.r24.s64 = -ctx.r24.s64;
	// addi r21,r21,1
	ctx.r21.s64 = ctx.r21.s64 + 1;
	// addi r28,r28,84
	ctx.r28.s64 = ctx.r28.s64 + 84;
	// addi r23,r23,144
	ctx.r23.s64 = ctx.r23.s64 + 144;
	// addi r27,r27,288
	ctx.r27.s64 = ctx.r27.s64 + 288;
	// cmpw cr6,r22,r11
	ctx.cr6.compare<int32_t>(ctx.r22.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x880dd9a8
	if (ctx.cr6.lt) goto loc_880DD9A8;
	// lwz r6,1772(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 1772);
	// li r7,12
	ctx.r7.s64 = 12;
	// lwz r11,-15564(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15564);
	// lis r22,-30597
	ctx.r22.s64 = -2005204992;
	// divw r9,r6,r29
	ctx.r9.s32 = ppc_divw(ctx.r6.s32, ctx.r29.s32);
	// lwz r4,5656(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5656);
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lwz r3,5704(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5704);
	// li r5,11
	ctx.r5.s64 = 11;
	// lwz r10,-15568(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15568);
	// add r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lwz r23,100(r1)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// divw r9,r3,r7
	ctx.r9.s32 = ppc_divw(ctx.r3.s32, ctx.r7.s32);
	// stw r15,-11932(r22)
	PPC_STORE_U32(ctx.r22.u32 + -11932, ctx.r15.u32);
	// divw. r11,r4,r5
	ctx.r11.s32 = ppc_divw(ctx.r4.s32, ctx.r5.s32);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r26,r10,16,0,15
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r8,r8,r23
	ctx.r8.u64 = ctx.r8.u64 + ctx.r23.u64;
	// add r9,r9,r25
	ctx.r9.u64 = ctx.r9.u64 + ctx.r25.u64;
	// neg r7,r11
	ctx.r7.s64 = -ctx.r11.s64;
	// blt 0x880ddd2c
	if (ctx.cr0.lt) goto loc_880DDD2C;
	// mr r7,r11
	ctx.r7.u64 = ctx.r11.u64;
loc_880DDD2C:
	// lwz r11,6332(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6332);
	// li r6,30
	ctx.r6.s64 = 30;
	// lwz r10,6044(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6044);
	// li r3,26921
	ctx.r3.s64 = 26921;
	// divw r11,r11,r6
	ctx.r11.s32 = ppc_divw(ctx.r11.s32, ctx.r6.s32);
	// lwz r5,6572(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6572);
	// divw r10,r10,r6
	ctx.r10.s32 = ppc_divw(ctx.r10.s32, ctx.r6.s32);
	// lwz r4,6328(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6328);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// divw r10,r5,r29
	ctx.r10.s32 = ppc_divw(ctx.r5.s32, ctx.r29.s32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// divw r10,r4,r6
	ctx.r10.s32 = ppc_divw(ctx.r4.s32, ctx.r6.s32);
	// subf r11,r7,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r7.s64;
	// add r28,r10,r9
	ctx.r28.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r27,r11,r8
	ctx.r27.u64 = ctx.r11.u64 + ctx.r8.u64;
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// add r4,r26,r28
	ctx.r4.u64 = ctx.r26.u64 + ctx.r28.u64;
	// bl 0x881538c0
	ctx.lr = 0x880DDD78;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// beq cr6,0x880dddc4
	if (ctx.cr6.eq) goto loc_880DDDC4;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880ddd90
	if (ctx.cr6.eq) goto loc_880DDD90;
	// lwz r11,0(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880DDD90:
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x880dddc4
	if (ctx.cr6.eq) goto loc_880DDDC4;
	// lwz r11,0(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880dddc4
	if (ctx.cr6.eq) goto loc_880DDDC4;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r15,-11932(r22)
	PPC_STORE_U32(ctx.r22.u32 + -11932, ctx.r15.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880DDDC4:
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// subf r4,r26,r28
	ctx.r4.s64 = ctx.r28.s64 - ctx.r26.s64;
	// li r3,26921
	ctx.r3.s64 = 26921;
	// bl 0x881538c0
	ctx.lr = 0x880DDDD8;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// beq cr6,0x880dde24
	if (ctx.cr6.eq) goto loc_880DDE24;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880dddf0
	if (ctx.cr6.eq) goto loc_880DDDF0;
	// lwz r11,0(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880DDDF0:
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x880dde24
	if (ctx.cr6.eq) goto loc_880DDE24;
	// lwz r11,0(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880dde38
	if (ctx.cr6.eq) goto loc_880DDE38;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r15,-11932(r22)
	PPC_STORE_U32(ctx.r22.u32 + -11932, ctx.r15.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880DDE24:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880dde38
	if (ctx.cr6.eq) goto loc_880DDE38;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// oris r10,r11,1024
	ctx.r10.u64 = ctx.r11.u64 | 67108864;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_880DDE38:
	// lwz r10,1484(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 1484);
	// lwz r11,-15572(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15572);
	// divw r9,r10,r29
	ctx.r9.s32 = ppc_divw(ctx.r10.s32, ctx.r29.s32);
	// lwz r8,5752(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5752);
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lwz r7,5704(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5704);
	// srawi r6,r8,4
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xF) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 4;
	// lwz r10,-15576(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15576);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// rlwinm r26,r10,16,0,15
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r9,r11,r23
	ctx.r9.u64 = ctx.r11.u64 + ctx.r23.u64;
	// addze r11,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r11.s64 = temp.s64;
	// srawi r5,r7,3
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7) != 0);
	ctx.r5.s64 = ctx.r7.s32 >> 3;
	// add r8,r11,r25
	ctx.r8.u64 = ctx.r11.u64 + ctx.r25.u64;
	// addze. r11,r5
	temp.s64 = ctx.r5.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r11.s64 = temp.s64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// neg r7,r11
	ctx.r7.s64 = -ctx.r11.s64;
	// blt 0x880dde80
	if (ctx.cr0.lt) goto loc_880DDE80;
	// mr r7,r11
	ctx.r7.u64 = ctx.r11.u64;
loc_880DDE80:
	// lwz r11,6236(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6236);
	// li r24,20
	ctx.r24.s64 = 20;
	// lwz r10,5948(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5948);
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// divw r11,r11,r24
	ctx.r11.s32 = ppc_divw(ctx.r11.s32, ctx.r24.s32);
	// lwz r5,6572(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6572);
	// divw r10,r10,r24
	ctx.r10.s32 = ppc_divw(ctx.r10.s32, ctx.r24.s32);
	// lwz r4,6232(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6232);
	// li r3,26922
	ctx.r3.s64 = 26922;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// divw r10,r5,r29
	ctx.r10.s32 = ppc_divw(ctx.r5.s32, ctx.r29.s32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// divw r10,r4,r24
	ctx.r10.s32 = ppc_divw(ctx.r4.s32, ctx.r24.s32);
	// subf r11,r7,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r7.s64;
	// add r28,r10,r8
	ctx.r28.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r27,r11,r9
	ctx.r27.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r4,r26,r28
	ctx.r4.u64 = ctx.r26.u64 + ctx.r28.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// bl 0x881538c0
	ctx.lr = 0x880DDECC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// beq cr6,0x880ddf18
	if (ctx.cr6.eq) goto loc_880DDF18;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880ddee4
	if (ctx.cr6.eq) goto loc_880DDEE4;
	// lwz r11,0(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880DDEE4:
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x880ddf18
	if (ctx.cr6.eq) goto loc_880DDF18;
	// lwz r11,0(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880ddf18
	if (ctx.cr6.eq) goto loc_880DDF18;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r15,-11932(r22)
	PPC_STORE_U32(ctx.r22.u32 + -11932, ctx.r15.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880DDF18:
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// subf r4,r26,r28
	ctx.r4.s64 = ctx.r28.s64 - ctx.r26.s64;
	// li r3,26922
	ctx.r3.s64 = 26922;
	// bl 0x881538c0
	ctx.lr = 0x880DDF2C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// beq cr6,0x880ddf78
	if (ctx.cr6.eq) goto loc_880DDF78;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880ddf44
	if (ctx.cr6.eq) goto loc_880DDF44;
	// lwz r11,0(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880DDF44:
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x880ddf78
	if (ctx.cr6.eq) goto loc_880DDF78;
	// lwz r11,0(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880ddf8c
	if (ctx.cr6.eq) goto loc_880DDF8C;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r15,-11932(r22)
	PPC_STORE_U32(ctx.r22.u32 + -11932, ctx.r15.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880DDF78:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880ddf8c
	if (ctx.cr6.eq) goto loc_880DDF8C;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// oris r10,r11,1024
	ctx.r10.u64 = ctx.r11.u64 | 67108864;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_880DDF8C:
	// lwz r11,-15572(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15572);
	// lwz r10,1580(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 1580);
	// addi r8,r11,-20
	ctx.r8.s64 = ctx.r11.s64 + -20;
	// lwz r7,5752(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5752);
	// divw r9,r10,r29
	ctx.r9.s32 = ppc_divw(ctx.r10.s32, ctx.r29.s32);
	// lwz r10,-15576(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15576);
	// rlwinm r11,r8,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r26,r10,16,0,15
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r8,r11,r9
	ctx.r8.u64 = ctx.r11.u64 + ctx.r9.u64;
	// divw r9,r7,r24
	ctx.r9.s32 = ppc_divw(ctx.r7.s32, ctx.r24.s32);
	// divw. r11,r7,r17
	ctx.r11.s32 = ppc_divw(ctx.r7.s32, ctx.r17.s32);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// add r8,r8,r23
	ctx.r8.u64 = ctx.r8.u64 + ctx.r23.u64;
	// add r7,r9,r25
	ctx.r7.u64 = ctx.r9.u64 + ctx.r25.u64;
	// bge 0x880ddfc8
	if (!ctx.cr0.lt) goto loc_880DDFC8;
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
loc_880DDFC8:
	// lwz r10,6140(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6140);
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// lwz r9,5852(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5852);
	// li r3,26922
	ctx.r3.s64 = 26922;
	// divw r10,r10,r29
	ctx.r10.s32 = ppc_divw(ctx.r10.s32, ctx.r29.s32);
	// lwz r5,6620(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6620);
	// divw r9,r9,r29
	ctx.r9.s32 = ppc_divw(ctx.r9.s32, ctx.r29.s32);
	// lwz r4,6136(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6136);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// divw r9,r5,r29
	ctx.r9.s32 = ppc_divw(ctx.r5.s32, ctx.r29.s32);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// divw r10,r4,r29
	ctx.r10.s32 = ppc_divw(ctx.r4.s32, ctx.r29.s32);
	// subf r11,r11,r9
	ctx.r11.s64 = ctx.r9.s64 - ctx.r11.s64;
	// add r28,r10,r7
	ctx.r28.u64 = ctx.r10.u64 + ctx.r7.u64;
	// add r27,r11,r8
	ctx.r27.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r4,r26,r28
	ctx.r4.u64 = ctx.r26.u64 + ctx.r28.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// bl 0x881538c0
	ctx.lr = 0x880DE010;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// beq cr6,0x880de05c
	if (ctx.cr6.eq) goto loc_880DE05C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880de028
	if (ctx.cr6.eq) goto loc_880DE028;
	// lwz r11,0(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880DE028:
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x880de05c
	if (ctx.cr6.eq) goto loc_880DE05C;
	// lwz r11,0(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880de05c
	if (ctx.cr6.eq) goto loc_880DE05C;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r15,-11932(r22)
	PPC_STORE_U32(ctx.r22.u32 + -11932, ctx.r15.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880DE05C:
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// subf r4,r26,r28
	ctx.r4.s64 = ctx.r28.s64 - ctx.r26.s64;
	// li r3,26922
	ctx.r3.s64 = 26922;
	// bl 0x881538c0
	ctx.lr = 0x880DE070;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// beq cr6,0x880de0bc
	if (ctx.cr6.eq) goto loc_880DE0BC;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880de088
	if (ctx.cr6.eq) goto loc_880DE088;
	// lwz r11,0(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880DE088:
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x880de0bc
	if (ctx.cr6.eq) goto loc_880DE0BC;
	// lwz r11,0(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880de0d0
	if (ctx.cr6.eq) goto loc_880DE0D0;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r15,-11932(r22)
	PPC_STORE_U32(ctx.r22.u32 + -11932, ctx.r15.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880DE0BC:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880de0d0
	if (ctx.cr6.eq) goto loc_880DE0D0;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// oris r10,r11,1024
	ctx.r10.u64 = ctx.r11.u64 | 67108864;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_880DE0D0:
	// lwz r10,6620(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6620);
	// li r17,5
	ctx.r17.s64 = 5;
	// lwz r11,6864(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6864);
	// divw r10,r10,r24
	ctx.r10.s32 = ppc_divw(ctx.r10.s32, ctx.r24.s32);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// add r28,r10,r23
	ctx.r28.u64 = ctx.r10.u64 + ctx.r23.u64;
	// bgt cr6,0x880deb70
	if (ctx.cr6.gt) goto loc_880DEB70;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x880de408
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_880DE408;
	// bdzf 4*cr6+eq,0x880de408
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_880DE408;
	// bdzf 4*cr6+eq,0x880de5d0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_880DE5D0;
	// bne cr6,0x880de95c
	if (!ctx.cr6.eq) goto loc_880DE95C;
	// lwz r11,6800(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6800);
	// lis r10,-21846
	ctx.r10.s64 = -1431699456;
	// srawi r9,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 2;
	// ori r8,r10,43691
	ctx.r8.u64 = ctx.r10.u64 | 43691;
	// addze r11,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r11.s64 = temp.s64;
	// mulhwu r7,r11,r8
	ctx.r7.u64 = (uint64_t(ctx.r11.u32) * uint64_t(ctx.r8.u32)) >> 32;
	// rlwinm r10,r7,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r5,r6,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r7,r5,r11
	ctx.r7.s64 = ctx.r11.s64 - ctx.r5.s64;
	// cmplwi cr6,r7,3
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 3, ctx.xer);
	// blt cr6,0x880de13c
	if (ctx.cr6.lt) goto loc_880DE13C;
	// subfic r7,r7,6
	ctx.xer.ca = ctx.r7.u32 <= 6;
	ctx.r7.s64 = 6 - ctx.r7.s64;
loc_880DE13C:
	// addi r10,r31,-15312
	ctx.r10.s64 = ctx.r31.s64 + -15312;
	// lwz r11,-15588(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15588);
	// rlwinm r21,r7,1,0,30
	ctx.r21.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,2348(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2348);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// lwz r10,-15592(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15592);
	// addi r5,r31,-15312
	ctx.r5.s64 = ctx.r31.s64 + -15312;
	// lwz r4,5752(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5752);
	// divw r8,r9,r29
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r29.s32);
	// divw r9,r4,r29
	ctx.r9.s32 = ppc_divw(ctx.r4.s32, ctx.r29.s32);
	// lbzx r3,r21,r6
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r21.u32 + ctx.r6.u32);
	// lbzx r6,r21,r5
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r21.u32 + ctx.r5.u32);
	// extsb r5,r3
	ctx.r5.s64 = ctx.r3.s8;
	// extsb r6,r6
	ctx.r6.s64 = ctx.r6.s8;
	// add r5,r5,r11
	ctx.r5.u64 = ctx.r5.u64 + ctx.r11.u64;
	// add r3,r6,r10
	ctx.r3.u64 = ctx.r6.u64 + ctx.r10.u64;
	// rlwinm r10,r5,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// divw. r11,r4,r17
	ctx.r11.s32 = ppc_divw(ctx.r4.s32, ctx.r17.s32);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r22,r3,16,0,15
	ctx.r22.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 16) & 0xFFFF0000;
	// add r6,r10,r28
	ctx.r6.u64 = ctx.r10.u64 + ctx.r28.u64;
	// add r5,r9,r25
	ctx.r5.u64 = ctx.r9.u64 + ctx.r25.u64;
	// neg r4,r11
	ctx.r4.s64 = -ctx.r11.s64;
	// blt 0x880de1a0
	if (ctx.cr0.lt) goto loc_880DE1A0;
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
loc_880DE1A0:
	// lwz r10,6092(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6092);
	// rlwinm r23,r7,3,0,28
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r8,5804(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5804);
	// addi r11,r31,-896
	ctx.r11.s64 = ctx.r31.s64 + -896;
	// divw r9,r10,r29
	ctx.r9.s32 = ppc_divw(ctx.r10.s32, ctx.r29.s32);
	// lwz r7,6088(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6088);
	// divw r8,r8,r29
	ctx.r8.s32 = ppc_divw(ctx.r8.s32, ctx.r29.s32);
	// divw r10,r7,r29
	ctx.r10.s32 = ppc_divw(ctx.r7.s32, ctx.r29.s32);
	// add r3,r9,r8
	ctx.r3.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r26,r10,r5
	ctx.r26.u64 = ctx.r10.u64 + ctx.r5.u64;
	// subf r9,r4,r3
	ctx.r9.s64 = ctx.r3.s64 - ctx.r4.s64;
	// add r24,r23,r11
	ctx.r24.u64 = ctx.r23.u64 + ctx.r11.u64;
	// add r27,r9,r6
	ctx.r27.u64 = ctx.r9.u64 + ctx.r6.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r14
	ctx.r8.u64 = ctx.r14.u64;
	// mr r7,r18
	ctx.r7.u64 = ctx.r18.u64;
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// add r4,r22,r26
	ctx.r4.u64 = ctx.r22.u64 + ctx.r26.u64;
	// bl 0x880dcd70
	ctx.lr = 0x880DE1F4;
	sub_880DCD70(ctx, base);
	// li r9,1
	ctx.r9.s64 = 1;
	// mr r8,r14
	ctx.r8.u64 = ctx.r14.u64;
	// mr r7,r18
	ctx.r7.u64 = ctx.r18.u64;
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// subf r4,r22,r26
	ctx.r4.s64 = ctx.r26.s64 - ctx.r22.s64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x880dcd70
	ctx.lr = 0x880DE214;
	sub_880DCD70(ctx, base);
	// lwz r9,2060(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2060);
	// lwz r11,-15580(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15580);
	// lwz r7,5752(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5752);
	// divw r8,r9,r29
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r29.s32);
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lwz r10,-15584(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15584);
	// divw r9,r7,r29
	ctx.r9.s32 = ppc_divw(ctx.r7.s32, ctx.r29.s32);
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + ctx.r11.u64;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// divw. r11,r7,r17
	ctx.r11.s32 = ppc_divw(ctx.r7.s32, ctx.r17.s32);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// add r8,r8,r28
	ctx.r8.u64 = ctx.r8.u64 + ctx.r28.u64;
	// add r9,r9,r25
	ctx.r9.u64 = ctx.r9.u64 + ctx.r25.u64;
	// bge 0x880de24c
	if (!ctx.cr0.lt) goto loc_880DE24C;
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
loc_880DE24C:
	// lwz r4,5804(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5804);
	// addi r5,r31,-15296
	ctx.r5.s64 = ctx.r31.s64 + -15296;
	// lwz r7,6092(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6092);
	// divw r6,r4,r29
	ctx.r6.s32 = ppc_divw(ctx.r4.s32, ctx.r29.s32);
	// lwz r3,6088(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6088);
	// divw r7,r7,r29
	ctx.r7.s32 = ppc_divw(ctx.r7.s32, ctx.r29.s32);
	// lwz r20,88(r1)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// add r6,r7,r6
	ctx.r6.u64 = ctx.r7.u64 + ctx.r6.u64;
	// divw r7,r3,r29
	ctx.r7.s32 = ppc_divw(ctx.r3.s32, ctx.r29.s32);
	// subf r11,r11,r6
	ctx.r11.s64 = ctx.r6.s64 - ctx.r11.s64;
	// add r28,r7,r9
	ctx.r28.u64 = ctx.r7.u64 + ctx.r9.u64;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stw r28,8288(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8288, ctx.r28.u32);
	// addi r8,r31,-15296
	ctx.r8.s64 = ctx.r31.s64 + -15296;
	// stw r11,8292(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8292, ctx.r11.u32);
	// addi r9,r31,-832
	ctx.r9.s64 = ctx.r31.s64 + -832;
	// stw r28,6812(r30)
	PPC_STORE_U32(ctx.r30.u32 + 6812, ctx.r28.u32);
	// addi r4,r8,1
	ctx.r4.s64 = ctx.r8.s64 + 1;
	// stw r11,6816(r30)
	PPC_STORE_U32(ctx.r30.u32 + 6816, ctx.r11.u32);
	// add r26,r23,r9
	ctx.r26.u64 = ctx.r23.u64 + ctx.r9.u64;
	// mr r6,r20
	ctx.r6.u64 = ctx.r20.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// mr r7,r18
	ctx.r7.u64 = ctx.r18.u64;
	// lbzx r9,r21,r4
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r21.u32 + ctx.r4.u32);
	// extsb r4,r9
	ctx.r4.s64 = ctx.r9.s8;
	// lbzx r8,r21,r5
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r21.u32 + ctx.r5.u32);
	// extsb r5,r8
	ctx.r5.s64 = ctx.r8.s8;
	// rlwinm r8,r5,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r9,r4,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// add r25,r8,r10
	ctx.r25.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r27,r9,r11
	ctx.r27.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r24,r25,r28
	ctx.r24.u64 = ctx.r25.u64 + ctx.r28.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r8,r14
	ctx.r8.u64 = ctx.r14.u64;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x880dcd70
	ctx.lr = 0x880DE2E0;
	sub_880DCD70(ctx, base);
	// subf r28,r25,r28
	ctx.r28.s64 = ctx.r28.s64 - ctx.r25.s64;
	// li r9,1
	ctx.r9.s64 = 1;
	// mr r8,r14
	ctx.r8.u64 = ctx.r14.u64;
	// mr r7,r18
	ctx.r7.u64 = ctx.r18.u64;
	// mr r6,r20
	ctx.r6.u64 = ctx.r20.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x880dcd70
	ctx.lr = 0x880DE304;
	sub_880DCD70(ctx, base);
	// lwz r11,860(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 860);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880deb74
	if (ctx.cr6.eq) goto loc_880DEB74;
	// lis r25,8
	ctx.r25.s64 = 524288;
	// addis r27,r27,-4
	ctx.r27.s64 = ctx.r27.s64 + -262144;
	// subfic r3,r11,27212
	ctx.xer.ca = ctx.r11.u32 <= 27212;
	ctx.r3.s64 = 27212 - ctx.r11.s64;
	// mr r6,r20
	ctx.r6.u64 = ctx.r20.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// add r4,r24,r25
	ctx.r4.u64 = ctx.r24.u64 + ctx.r25.u64;
	// bl 0x881538c0
	ctx.lr = 0x880DE32C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// beq cr6,0x880de384
	if (ctx.cr6.eq) goto loc_880DE384;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880de344
	if (ctx.cr6.eq) goto loc_880DE344;
	// lwz r11,0(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880DE344:
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x880de384
	if (ctx.cr6.eq) goto loc_880DE384;
	// lwz r11,0(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880de384
	if (ctx.cr6.eq) goto loc_880DE384;
	// lis r24,-30597
	ctx.r24.s64 = -2005204992;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r8,545
	ctx.r8.s64 = 35717120;
	// rlwimi r8,r10,8,16,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r10.u32, 8) & 0xFF00) | (ctx.r8.u64 & 0xFFFFFFFFFFFF00FF);
	// lwz r11,-11932(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + -11932);
	// or r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 | ctx.r9.u64;
	// addi r26,r11,1
	ctx.r26.s64 = ctx.r11.s64 + 1;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r26,-11932(r24)
	PPC_STORE_U32(ctx.r24.u32 + -11932, ctx.r26.u32);
	// b 0x880de38c
	goto loc_880DE38C;
loc_880DE384:
	// lis r24,-30597
	ctx.r24.s64 = -2005204992;
	// lwz r26,-11932(r24)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r24.u32 + -11932);
loc_880DE38C:
	// lwz r11,860(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 860);
	// mr r6,r20
	ctx.r6.u64 = ctx.r20.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// subfic r3,r11,27212
	ctx.xer.ca = ctx.r11.u32 <= 27212;
	ctx.r3.s64 = 27212 - ctx.r11.s64;
	// subf r4,r25,r28
	ctx.r4.s64 = ctx.r28.s64 - ctx.r25.s64;
	// bl 0x881538c0
	ctx.lr = 0x880DE3A4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// beq cr6,0x880de3f0
	if (ctx.cr6.eq) goto loc_880DE3F0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880de3bc
	if (ctx.cr6.eq) goto loc_880DE3BC;
	// lwz r11,0(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880DE3BC:
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x880de3f0
	if (ctx.cr6.eq) goto loc_880DE3F0;
	// lwz r11,0(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880deb74
	if (ctx.cr6.eq) goto loc_880DEB74;
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r11,r26,1
	ctx.r11.s64 = ctx.r26.s64 + 1;
	// rlwimi r9,r10,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r11,-11932(r24)
	PPC_STORE_U32(ctx.r24.u32 + -11932, ctx.r11.u32);
	// or r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 | ctx.r8.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
loc_880DE3F0:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880deb74
	if (ctx.cr6.eq) goto loc_880DEB74;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// oris r10,r11,1024
	ctx.r10.u64 = ctx.r11.u64 | 67108864;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x880deb74
	goto loc_880DEB74;
loc_880DE408:
	// lwz r11,6800(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6800);
	// addi r9,r31,-15312
	ctx.r9.s64 = ctx.r31.s64 + -15312;
	// addi r6,r31,-15312
	ctx.r6.s64 = ctx.r31.s64 + -15312;
	// lwz r4,2348(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2348);
	// addi r5,r9,1
	ctx.r5.s64 = ctx.r9.s64 + 1;
	// lwz r10,-15588(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15588);
	// rlwinm r21,r11,1,0,30
	ctx.r21.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,-15592(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15592);
	// divw r7,r4,r29
	ctx.r7.s32 = ppc_divw(ctx.r4.s32, ctx.r29.s32);
	// lwz r3,5752(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5752);
	// divw r8,r3,r29
	ctx.r8.s32 = ppc_divw(ctx.r3.s32, ctx.r29.s32);
	// lbzx r5,r21,r5
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r21.u32 + ctx.r5.u32);
	// lbzx r4,r21,r6
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r21.u32 + ctx.r6.u32);
	// extsb r5,r5
	ctx.r5.s64 = ctx.r5.s8;
	// extsb r6,r4
	ctx.r6.s64 = ctx.r4.s8;
	// add r10,r5,r10
	ctx.r10.u64 = ctx.r5.u64 + ctx.r10.u64;
	// add r6,r6,r9
	ctx.r6.u64 = ctx.r6.u64 + ctx.r9.u64;
	// rlwinm r9,r10,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// divw. r10,r3,r17
	ctx.r10.s32 = ppc_divw(ctx.r3.s32, ctx.r17.s32);
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// rlwinm r22,r6,16,0,15
	ctx.r22.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// add r5,r8,r25
	ctx.r5.u64 = ctx.r8.u64 + ctx.r25.u64;
	// add r6,r9,r28
	ctx.r6.u64 = ctx.r9.u64 + ctx.r28.u64;
	// neg r4,r10
	ctx.r4.s64 = -ctx.r10.s64;
	// blt 0x880de470
	if (ctx.cr0.lt) goto loc_880DE470;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
loc_880DE470:
	// lwz r9,6092(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6092);
	// rlwinm r23,r11,3,0,28
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r7,5804(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5804);
	// addi r10,r31,-896
	ctx.r10.s64 = ctx.r31.s64 + -896;
	// divw r8,r9,r29
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r29.s32);
	// lwz r3,6088(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6088);
	// divw r7,r7,r29
	ctx.r7.s32 = ppc_divw(ctx.r7.s32, ctx.r29.s32);
	// divw r9,r3,r29
	ctx.r9.s32 = ppc_divw(ctx.r3.s32, ctx.r29.s32);
	// add r11,r8,r7
	ctx.r11.u64 = ctx.r8.u64 + ctx.r7.u64;
	// add r26,r9,r5
	ctx.r26.u64 = ctx.r9.u64 + ctx.r5.u64;
	// subf r11,r4,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r4.s64;
	// add r24,r23,r10
	ctx.r24.u64 = ctx.r23.u64 + ctx.r10.u64;
	// add r27,r11,r6
	ctx.r27.u64 = ctx.r11.u64 + ctx.r6.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r14
	ctx.r8.u64 = ctx.r14.u64;
	// mr r7,r18
	ctx.r7.u64 = ctx.r18.u64;
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// add r4,r22,r26
	ctx.r4.u64 = ctx.r22.u64 + ctx.r26.u64;
	// bl 0x880dcd70
	ctx.lr = 0x880DE4C4;
	sub_880DCD70(ctx, base);
	// li r9,1
	ctx.r9.s64 = 1;
	// mr r8,r14
	ctx.r8.u64 = ctx.r14.u64;
	// mr r7,r18
	ctx.r7.u64 = ctx.r18.u64;
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// subf r4,r22,r26
	ctx.r4.s64 = ctx.r26.s64 - ctx.r22.s64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x880dcd70
	ctx.lr = 0x880DE4E4;
	sub_880DCD70(ctx, base);
	// lwz r9,2060(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2060);
	// lwz r11,-15580(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15580);
	// lwz r7,5752(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5752);
	// divw r8,r9,r29
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r29.s32);
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lwz r10,-15584(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15584);
	// divw r9,r7,r29
	ctx.r9.s32 = ppc_divw(ctx.r7.s32, ctx.r29.s32);
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + ctx.r11.u64;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// divw. r11,r7,r17
	ctx.r11.s32 = ppc_divw(ctx.r7.s32, ctx.r17.s32);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// add r8,r8,r28
	ctx.r8.u64 = ctx.r8.u64 + ctx.r28.u64;
	// add r9,r9,r25
	ctx.r9.u64 = ctx.r9.u64 + ctx.r25.u64;
	// bge 0x880de51c
	if (!ctx.cr0.lt) goto loc_880DE51C;
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
loc_880DE51C:
	// lwz r4,5804(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5804);
	// addi r5,r31,-15296
	ctx.r5.s64 = ctx.r31.s64 + -15296;
	// lwz r7,6092(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6092);
	// divw r6,r4,r29
	ctx.r6.s32 = ppc_divw(ctx.r4.s32, ctx.r29.s32);
	// lwz r3,6088(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6088);
	// divw r7,r7,r29
	ctx.r7.s32 = ppc_divw(ctx.r7.s32, ctx.r29.s32);
	// lwz r20,88(r1)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// add r6,r7,r6
	ctx.r6.u64 = ctx.r7.u64 + ctx.r6.u64;
	// divw r7,r3,r29
	ctx.r7.s32 = ppc_divw(ctx.r3.s32, ctx.r29.s32);
	// subf r11,r11,r6
	ctx.r11.s64 = ctx.r6.s64 - ctx.r11.s64;
	// add r28,r7,r9
	ctx.r28.u64 = ctx.r7.u64 + ctx.r9.u64;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stw r28,8288(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8288, ctx.r28.u32);
	// addi r9,r31,-15296
	ctx.r9.s64 = ctx.r31.s64 + -15296;
	// stw r11,8292(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8292, ctx.r11.u32);
	// addi r8,r31,-832
	ctx.r8.s64 = ctx.r31.s64 + -832;
	// stw r11,6816(r30)
	PPC_STORE_U32(ctx.r30.u32 + 6816, ctx.r11.u32);
	// addi r4,r9,1
	ctx.r4.s64 = ctx.r9.s64 + 1;
	// stw r28,6812(r30)
	PPC_STORE_U32(ctx.r30.u32 + 6812, ctx.r28.u32);
	// add r27,r23,r8
	ctx.r27.u64 = ctx.r23.u64 + ctx.r8.u64;
	// mr r6,r20
	ctx.r6.u64 = ctx.r20.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r14
	ctx.r8.u64 = ctx.r14.u64;
	// mr r7,r18
	ctx.r7.u64 = ctx.r18.u64;
	// lbzx r5,r21,r5
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r21.u32 + ctx.r5.u32);
	// extsb r26,r5
	ctx.r26.s64 = ctx.r5.s8;
	// lbzx r4,r21,r4
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r21.u32 + ctx.r4.u32);
	// extsb r4,r4
	ctx.r4.s64 = ctx.r4.s8;
	// rlwinm r5,r4,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r4,r26,16,0,15
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 16) & 0xFFFF0000;
	// add r25,r5,r11
	ctx.r25.u64 = ctx.r5.u64 + ctx.r11.u64;
	// add r26,r4,r10
	ctx.r26.u64 = ctx.r4.u64 + ctx.r10.u64;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// add r4,r26,r28
	ctx.r4.u64 = ctx.r26.u64 + ctx.r28.u64;
	// bl 0x880dcd70
	ctx.lr = 0x880DE5AC;
	sub_880DCD70(ctx, base);
	// li r9,1
	ctx.r9.s64 = 1;
	// mr r8,r14
	ctx.r8.u64 = ctx.r14.u64;
	// mr r7,r18
	ctx.r7.u64 = ctx.r18.u64;
	// mr r6,r20
	ctx.r6.u64 = ctx.r20.u64;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// subf r4,r26,r28
	ctx.r4.s64 = ctx.r28.s64 - ctx.r26.s64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x880dcd70
	ctx.lr = 0x880DE5CC;
	sub_880DCD70(ctx, base);
	// b 0x880deb74
	goto loc_880DEB74;
loc_880DE5D0:
	// lwz r11,6848(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6848);
	// li r23,1
	ctx.r23.s64 = 1;
	// li r22,0
	ctx.r22.s64 = 0;
	// srawi r10,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 1;
	// clrlwi r11,r10,24
	ctx.r11.u64 = ctx.r10.u32 & 0xFF;
	// cmpwi cr6,r11,96
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 96, ctx.xer);
	// blt cr6,0x880de7bc
	if (ctx.cr6.lt) goto loc_880DE7BC;
	// cmpwi cr6,r11,128
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 128, ctx.xer);
	// bgt cr6,0x880de7a4
	if (ctx.cr6.gt) goto loc_880DE7A4;
	// subfic r11,r11,128
	ctx.xer.ca = ctx.r11.u32 <= 128;
	ctx.r11.s64 = 128 - ctx.r11.s64;
loc_880DE5F8:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880de7c0
	if (!ctx.cr6.eq) goto loc_880DE7C0;
	// lbz r11,-15297(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + -15297);
	// lwz r10,-15588(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15588);
	// extsb r9,r11
	ctx.r9.s64 = ctx.r11.s8;
	// lbz r11,-15298(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + -15298);
	// lwz r7,2348(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2348);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r10,-15592(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15592);
	// extsb r8,r11
	ctx.r8.s64 = ctx.r11.s8;
	// lwz r5,5752(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5752);
	// rlwinm r11,r6,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// divw r9,r7,r29
	ctx.r9.s32 = ppc_divw(ctx.r7.s32, ctx.r29.s32);
	// add r4,r8,r10
	ctx.r4.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// divw r10,r5,r29
	ctx.r10.s32 = ppc_divw(ctx.r5.s32, ctx.r29.s32);
	// divw. r11,r5,r17
	ctx.r11.s32 = ppc_divw(ctx.r5.s32, ctx.r17.s32);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r24,r4,16,0,15
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// add r7,r9,r28
	ctx.r7.u64 = ctx.r9.u64 + ctx.r28.u64;
	// add r6,r10,r25
	ctx.r6.u64 = ctx.r10.u64 + ctx.r25.u64;
	// neg r5,r11
	ctx.r5.s64 = -ctx.r11.s64;
	// blt 0x880de654
	if (ctx.cr0.lt) goto loc_880DE654;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
loc_880DE654:
	// lwz r10,6092(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6092);
	// addi r11,r31,-896
	ctx.r11.s64 = ctx.r31.s64 + -896;
	// lwz r8,5804(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5804);
	// lwz r4,6088(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6088);
	// divw r9,r10,r29
	ctx.r9.s32 = ppc_divw(ctx.r10.s32, ctx.r29.s32);
	// divw r8,r8,r29
	ctx.r8.s32 = ppc_divw(ctx.r8.s32, ctx.r29.s32);
	// divw r10,r4,r29
	ctx.r10.s32 = ppc_divw(ctx.r4.s32, ctx.r29.s32);
	// add r3,r9,r8
	ctx.r3.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r27,r10,r6
	ctx.r27.u64 = ctx.r10.u64 + ctx.r6.u64;
	// subf r10,r5,r3
	ctx.r10.s64 = ctx.r3.s64 - ctx.r5.s64;
	// li r9,0
	ctx.r9.s64 = 0;
	// add r26,r10,r7
	ctx.r26.u64 = ctx.r10.u64 + ctx.r7.u64;
	// mr r8,r14
	ctx.r8.u64 = ctx.r14.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r7,r18
	ctx.r7.u64 = ctx.r18.u64;
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// add r4,r24,r27
	ctx.r4.u64 = ctx.r24.u64 + ctx.r27.u64;
	// addi r3,r11,56
	ctx.r3.s64 = ctx.r11.s64 + 56;
	// bl 0x880dcd70
	ctx.lr = 0x880DE6A0;
	sub_880DCD70(ctx, base);
	// addi r11,r31,-896
	ctx.r11.s64 = ctx.r31.s64 + -896;
	// li r9,1
	ctx.r9.s64 = 1;
	// mr r8,r14
	ctx.r8.u64 = ctx.r14.u64;
	// mr r7,r18
	ctx.r7.u64 = ctx.r18.u64;
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// subf r4,r24,r27
	ctx.r4.s64 = ctx.r27.s64 - ctx.r24.s64;
	// addi r3,r11,56
	ctx.r3.s64 = ctx.r11.s64 + 56;
	// bl 0x880dcd70
	ctx.lr = 0x880DE6C4;
	sub_880DCD70(ctx, base);
	// lwz r9,2060(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2060);
	// lwz r11,-15580(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15580);
	// lwz r7,5752(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5752);
	// divw r8,r9,r29
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r29.s32);
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lwz r10,-15584(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15584);
	// divw r9,r7,r29
	ctx.r9.s32 = ppc_divw(ctx.r7.s32, ctx.r29.s32);
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + ctx.r11.u64;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// divw. r11,r7,r17
	ctx.r11.s32 = ppc_divw(ctx.r7.s32, ctx.r17.s32);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// add r8,r8,r28
	ctx.r8.u64 = ctx.r8.u64 + ctx.r28.u64;
	// add r9,r9,r25
	ctx.r9.u64 = ctx.r9.u64 + ctx.r25.u64;
	// bge 0x880de6fc
	if (!ctx.cr0.lt) goto loc_880DE6FC;
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
loc_880DE6FC:
	// lbz r7,-15281(r31)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r31.u32 + -15281);
	// lwz r6,6092(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6092);
	// extsb r5,r7
	ctx.r5.s64 = ctx.r7.s8;
	// lwz r3,5804(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5804);
	// divw r4,r6,r29
	ctx.r4.s32 = ppc_divw(ctx.r6.s32, ctx.r29.s32);
	// lwz r28,6088(r30)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6088);
	// rlwinm r6,r5,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// lbz r7,-15282(r31)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r31.u32 + -15282);
	// divw r5,r3,r29
	ctx.r5.s32 = ppc_divw(ctx.r3.s32, ctx.r29.s32);
	// lwz r20,88(r1)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// add r6,r6,r4
	ctx.r6.u64 = ctx.r6.u64 + ctx.r4.u64;
	// extsb r7,r7
	ctx.r7.s64 = ctx.r7.s8;
	// add r5,r6,r5
	ctx.r5.u64 = ctx.r6.u64 + ctx.r5.u64;
	// divw r6,r28,r29
	ctx.r6.s32 = ppc_divw(ctx.r28.s32, ctx.r29.s32);
	// subf r11,r11,r5
	ctx.r11.s64 = ctx.r5.s64 - ctx.r11.s64;
	// add r28,r6,r9
	ctx.r28.u64 = ctx.r6.u64 + ctx.r9.u64;
	// add r27,r11,r8
	ctx.r27.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stw r28,8288(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8288, ctx.r28.u32);
	// rlwinm r9,r7,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// stw r27,8292(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8292, ctx.r27.u32);
	// addi r11,r31,-832
	ctx.r11.s64 = ctx.r31.s64 + -832;
	// stw r27,6816(r30)
	PPC_STORE_U32(ctx.r30.u32 + 6816, ctx.r27.u32);
	// add r26,r9,r10
	ctx.r26.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r28,6812(r30)
	PPC_STORE_U32(ctx.r30.u32 + 6812, ctx.r28.u32);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r6,r20
	ctx.r6.u64 = ctx.r20.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r14
	ctx.r8.u64 = ctx.r14.u64;
	// mr r7,r18
	ctx.r7.u64 = ctx.r18.u64;
	// add r4,r26,r28
	ctx.r4.u64 = ctx.r26.u64 + ctx.r28.u64;
	// addi r3,r11,56
	ctx.r3.s64 = ctx.r11.s64 + 56;
	// bl 0x880dcd70
	ctx.lr = 0x880DE77C;
	sub_880DCD70(ctx, base);
	// addi r11,r31,-832
	ctx.r11.s64 = ctx.r31.s64 + -832;
	// li r9,1
	ctx.r9.s64 = 1;
	// mr r8,r14
	ctx.r8.u64 = ctx.r14.u64;
	// mr r7,r18
	ctx.r7.u64 = ctx.r18.u64;
	// mr r6,r20
	ctx.r6.u64 = ctx.r20.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// subf r4,r26,r28
	ctx.r4.s64 = ctx.r28.s64 - ctx.r26.s64;
	// addi r3,r11,56
	ctx.r3.s64 = ctx.r11.s64 + 56;
	// bl 0x880dcd70
	ctx.lr = 0x880DE7A0;
	sub_880DCD70(ctx, base);
	// b 0x880deb74
	goto loc_880DEB74;
loc_880DE7A4:
	// li r23,-1
	ctx.r23.s64 = -1;
	// li r22,1
	ctx.r22.s64 = 1;
	// cmpwi cr6,r11,160
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 160, ctx.xer);
	// bgt cr6,0x880de7bc
	if (ctx.cr6.gt) goto loc_880DE7BC;
	// addi r11,r11,-128
	ctx.r11.s64 = ctx.r11.s64 + -128;
	// b 0x880de5f8
	goto loc_880DE5F8;
loc_880DE7BC:
	// li r11,32
	ctx.r11.s64 = 32;
loc_880DE7C0:
	// addi r7,r11,-1
	ctx.r7.s64 = ctx.r11.s64 + -1;
	// lwz r11,-15604(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15604);
	// addi r8,r31,-15440
	ctx.r8.s64 = ctx.r31.s64 + -15440;
	// lwz r10,-15608(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15608);
	// rlwinm r24,r7,1,0,30
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lis r21,9
	ctx.r21.s64 = 589824;
	// add r9,r11,r28
	ctx.r9.u64 = ctx.r11.u64 + ctx.r28.u64;
	// cmpwi cr6,r23,-1
	ctx.cr6.compare<int32_t>(ctx.r23.s32, -1, ctx.xer);
	// lbzx r6,r24,r8
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r24.u32 + ctx.r8.u32);
	// extsb r5,r6
	ctx.r5.s64 = ctx.r6.s8;
	// mullw r11,r5,r23
	ctx.r11.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r23.s32);
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r26,r4,16,0,15
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// bne cr6,0x880de800
	if (!ctx.cr6.eq) goto loc_880DE800;
	// subf r26,r21,r26
	ctx.r26.s64 = ctx.r26.s64 - ctx.r21.s64;
loc_880DE800:
	// addi r11,r31,-15440
	ctx.r11.s64 = ctx.r31.s64 + -15440;
	// lwz r8,5752(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5752);
	// lwz r6,2348(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2348);
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// divw r11,r8,r29
	ctx.r11.s32 = ppc_divw(ctx.r8.s32, ctx.r29.s32);
	// divw r10,r6,r29
	ctx.r10.s32 = ppc_divw(ctx.r6.s32, ctx.r29.s32);
	// add r4,r11,r25
	ctx.r4.u64 = ctx.r11.u64 + ctx.r25.u64;
	// divw. r6,r8,r17
	ctx.r6.s32 = ppc_divw(ctx.r8.s32, ctx.r17.s32);
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// lbzx r3,r24,r5
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r24.u32 + ctx.r5.u32);
	// extsb r11,r3
	ctx.r11.s64 = ctx.r3.s8;
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r3,r11,r9
	ctx.r3.u64 = ctx.r11.u64 + ctx.r9.u64;
	// bge 0x880de83c
	if (!ctx.cr0.lt) goto loc_880DE83C;
	// neg r6,r6
	ctx.r6.s64 = -ctx.r6.s64;
loc_880DE83C:
	// lwz r10,6092(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6092);
	// rlwinm r27,r7,3,0,28
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r8,5804(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5804);
	// addi r11,r31,-1408
	ctx.r11.s64 = ctx.r31.s64 + -1408;
	// divw r9,r10,r29
	ctx.r9.s32 = ppc_divw(ctx.r10.s32, ctx.r29.s32);
	// lwz r7,6088(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6088);
	// divw r8,r8,r29
	ctx.r8.s32 = ppc_divw(ctx.r8.s32, ctx.r29.s32);
	// divw r10,r7,r29
	ctx.r10.s32 = ppc_divw(ctx.r7.s32, ctx.r29.s32);
	// add r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r10,r10,r26
	ctx.r10.u64 = ctx.r10.u64 + ctx.r26.u64;
	// subf r5,r6,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r6.s64;
	// mr r9,r22
	ctx.r9.u64 = ctx.r22.u64;
	// add r5,r5,r3
	ctx.r5.u64 = ctx.r5.u64 + ctx.r3.u64;
	// mr r8,r14
	ctx.r8.u64 = ctx.r14.u64;
	// mr r7,r18
	ctx.r7.u64 = ctx.r18.u64;
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// add r4,r10,r4
	ctx.r4.u64 = ctx.r10.u64 + ctx.r4.u64;
	// add r3,r27,r11
	ctx.r3.u64 = ctx.r27.u64 + ctx.r11.u64;
	// bl 0x880dcd70
	ctx.lr = 0x880DE888;
	sub_880DCD70(ctx, base);
	// lwz r11,-15596(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15596);
	// lwz r4,2060(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2060);
	// lwz r3,5752(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5752);
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// divw r8,r4,r29
	ctx.r8.s32 = ppc_divw(ctx.r4.s32, ctx.r29.s32);
	// lwz r10,-15600(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15600);
	// divw r9,r3,r29
	ctx.r9.s32 = ppc_divw(ctx.r3.s32, ctx.r29.s32);
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + ctx.r11.u64;
	// rlwinm r7,r10,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// divw. r11,r3,r17
	ctx.r11.s32 = ppc_divw(ctx.r3.s32, ctx.r17.s32);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// add r10,r8,r28
	ctx.r10.u64 = ctx.r8.u64 + ctx.r28.u64;
	// add r9,r9,r25
	ctx.r9.u64 = ctx.r9.u64 + ctx.r25.u64;
	// bge 0x880de8c0
	if (!ctx.cr0.lt) goto loc_880DE8C0;
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
loc_880DE8C0:
	// lwz r4,5804(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5804);
	// addi r5,r31,-15376
	ctx.r5.s64 = ctx.r31.s64 + -15376;
	// lwz r8,6092(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6092);
	// cmpwi cr6,r23,-1
	ctx.cr6.compare<int32_t>(ctx.r23.s32, -1, ctx.xer);
	// divw r6,r4,r29
	ctx.r6.s32 = ppc_divw(ctx.r4.s32, ctx.r29.s32);
	// lwz r3,6088(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6088);
	// divw r8,r8,r29
	ctx.r8.s32 = ppc_divw(ctx.r8.s32, ctx.r29.s32);
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// divw r6,r3,r29
	ctx.r6.s32 = ppc_divw(ctx.r3.s32, ctx.r29.s32);
	// subf r8,r11,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r11.s64;
	// add r11,r6,r9
	ctx.r11.u64 = ctx.r6.u64 + ctx.r9.u64;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// stw r11,8288(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8288, ctx.r11.u32);
	// stw r10,8292(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8292, ctx.r10.u32);
	// stw r11,6812(r30)
	PPC_STORE_U32(ctx.r30.u32 + 6812, ctx.r11.u32);
	// stw r10,6816(r30)
	PPC_STORE_U32(ctx.r30.u32 + 6816, ctx.r10.u32);
	// lbzx r6,r24,r5
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r24.u32 + ctx.r5.u32);
	// extsb r5,r6
	ctx.r5.s64 = ctx.r6.s8;
	// mullw r4,r5,r23
	ctx.r4.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r23.s32);
	// rlwinm r9,r4,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// add r5,r9,r7
	ctx.r5.u64 = ctx.r9.u64 + ctx.r7.u64;
	// bne cr6,0x880de91c
	if (!ctx.cr6.eq) goto loc_880DE91C;
	// subf r5,r21,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r21.s64;
loc_880DE91C:
	// addi r9,r31,-15376
	ctx.r9.s64 = ctx.r31.s64 + -15376;
	// lwz r20,88(r1)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// add r4,r5,r11
	ctx.r4.u64 = ctx.r5.u64 + ctx.r11.u64;
	// addi r11,r9,1
	ctx.r11.s64 = ctx.r9.s64 + 1;
	// addi r3,r31,-1152
	ctx.r3.s64 = ctx.r31.s64 + -1152;
	// mr r9,r22
	ctx.r9.u64 = ctx.r22.u64;
	// mr r8,r14
	ctx.r8.u64 = ctx.r14.u64;
	// mr r7,r18
	ctx.r7.u64 = ctx.r18.u64;
	// lbzx r5,r24,r11
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r24.u32 + ctx.r11.u32);
	// mr r6,r20
	ctx.r6.u64 = ctx.r20.u64;
	// add r3,r27,r3
	ctx.r3.u64 = ctx.r27.u64 + ctx.r3.u64;
	// extsb r11,r5
	ctx.r11.s64 = ctx.r5.s8;
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x880dcd70
	ctx.lr = 0x880DE958;
	sub_880DCD70(ctx, base);
	// b 0x880deb74
	goto loc_880DEB74;
loc_880DE95C:
	// lwz r11,-15620(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15620);
	// lwz r10,2348(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2348);
	// addi r8,r11,16
	ctx.r8.s64 = ctx.r11.s64 + 16;
	// lwz r7,5752(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5752);
	// divw r9,r10,r29
	ctx.r9.s32 = ppc_divw(ctx.r10.s32, ctx.r29.s32);
	// lwz r10,-15624(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15624);
	// rlwinm r11,r8,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r24,r10,16,0,15
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r8,r11,r9
	ctx.r8.u64 = ctx.r11.u64 + ctx.r9.u64;
	// divw r9,r7,r29
	ctx.r9.s32 = ppc_divw(ctx.r7.s32, ctx.r29.s32);
	// divw. r11,r7,r17
	ctx.r11.s32 = ppc_divw(ctx.r7.s32, ctx.r17.s32);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// add r7,r8,r28
	ctx.r7.u64 = ctx.r8.u64 + ctx.r28.u64;
	// add r5,r9,r25
	ctx.r5.u64 = ctx.r9.u64 + ctx.r25.u64;
	// bge 0x880de998
	if (!ctx.cr0.lt) goto loc_880DE998;
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
loc_880DE998:
	// lwz r10,6092(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6092);
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// lwz r8,5804(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5804);
	// li r3,26920
	ctx.r3.s64 = 26920;
	// divw r9,r10,r29
	ctx.r9.s32 = ppc_divw(ctx.r10.s32, ctx.r29.s32);
	// lwz r4,6088(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6088);
	// divw r8,r8,r29
	ctx.r8.s32 = ppc_divw(ctx.r8.s32, ctx.r29.s32);
	// divw r10,r4,r29
	ctx.r10.s32 = ppc_divw(ctx.r4.s32, ctx.r29.s32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r27,r10,r5
	ctx.r27.u64 = ctx.r10.u64 + ctx.r5.u64;
	// subf r11,r11,r9
	ctx.r11.s64 = ctx.r9.s64 - ctx.r11.s64;
	// add r4,r24,r27
	ctx.r4.u64 = ctx.r24.u64 + ctx.r27.u64;
	// add r26,r11,r7
	ctx.r26.u64 = ctx.r11.u64 + ctx.r7.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// bl 0x881538c0
	ctx.lr = 0x880DE9D4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// beq cr6,0x880dea20
	if (ctx.cr6.eq) goto loc_880DEA20;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880de9ec
	if (ctx.cr6.eq) goto loc_880DE9EC;
	// lwz r11,0(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880DE9EC:
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x880dea20
	if (ctx.cr6.eq) goto loc_880DEA20;
	// lwz r11,0(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880dea20
	if (ctx.cr6.eq) goto loc_880DEA20;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r15,-11932(r22)
	PPC_STORE_U32(ctx.r22.u32 + -11932, ctx.r15.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880DEA20:
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// subf r4,r24,r27
	ctx.r4.s64 = ctx.r27.s64 - ctx.r24.s64;
	// li r3,26920
	ctx.r3.s64 = 26920;
	// bl 0x881538c0
	ctx.lr = 0x880DEA34;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// beq cr6,0x880dea80
	if (ctx.cr6.eq) goto loc_880DEA80;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880dea4c
	if (ctx.cr6.eq) goto loc_880DEA4C;
	// lwz r11,0(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880DEA4C:
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x880dea80
	if (ctx.cr6.eq) goto loc_880DEA80;
	// lwz r11,0(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880dea94
	if (ctx.cr6.eq) goto loc_880DEA94;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r15,-11932(r22)
	PPC_STORE_U32(ctx.r22.u32 + -11932, ctx.r15.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880DEA80:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880dea94
	if (ctx.cr6.eq) goto loc_880DEA94;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// oris r10,r11,1024
	ctx.r10.u64 = ctx.r11.u64 | 67108864;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_880DEA94:
	// lwz r11,-15612(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15612);
	// lwz r10,2060(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2060);
	// addi r8,r11,16
	ctx.r8.s64 = ctx.r11.s64 + 16;
	// lwz r6,5752(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5752);
	// divw r9,r10,r29
	ctx.r9.s32 = ppc_divw(ctx.r10.s32, ctx.r29.s32);
	// lwz r10,-15616(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -15616);
	// rlwinm r11,r8,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r7,r10,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r8,r11,r9
	ctx.r8.u64 = ctx.r11.u64 + ctx.r9.u64;
	// divw r9,r6,r29
	ctx.r9.s32 = ppc_divw(ctx.r6.s32, ctx.r29.s32);
	// divw. r11,r6,r17
	ctx.r11.s32 = ppc_divw(ctx.r6.s32, ctx.r17.s32);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// add r8,r8,r28
	ctx.r8.u64 = ctx.r8.u64 + ctx.r28.u64;
	// add r6,r9,r25
	ctx.r6.u64 = ctx.r9.u64 + ctx.r25.u64;
	// bge 0x880dead0
	if (!ctx.cr0.lt) goto loc_880DEAD0;
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
loc_880DEAD0:
	// lwz r10,6092(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6092);
	// li r3,26919
	ctx.r3.s64 = 26919;
	// lwz r9,5804(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5804);
	// divw r10,r10,r29
	ctx.r10.s32 = ppc_divw(ctx.r10.s32, ctx.r29.s32);
	// lwz r5,6088(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6088);
	// divw r9,r9,r29
	ctx.r9.s32 = ppc_divw(ctx.r9.s32, ctx.r29.s32);
	// lwz r20,88(r1)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// add r4,r10,r9
	ctx.r4.u64 = ctx.r10.u64 + ctx.r9.u64;
	// divw r9,r5,r29
	ctx.r9.s32 = ppc_divw(ctx.r5.s32, ctx.r29.s32);
	// subf r10,r11,r4
	ctx.r10.s64 = ctx.r4.s64 - ctx.r11.s64;
	// add r11,r9,r6
	ctx.r11.u64 = ctx.r9.u64 + ctx.r6.u64;
	// add r5,r10,r8
	ctx.r5.u64 = ctx.r10.u64 + ctx.r8.u64;
	// stw r11,8288(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8288, ctx.r11.u32);
	// mr r6,r20
	ctx.r6.u64 = ctx.r20.u64;
	// stw r5,8292(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8292, ctx.r5.u32);
	// add r4,r7,r11
	ctx.r4.u64 = ctx.r7.u64 + ctx.r11.u64;
	// stw r5,6816(r30)
	PPC_STORE_U32(ctx.r30.u32 + 6816, ctx.r5.u32);
	// stw r11,6812(r30)
	PPC_STORE_U32(ctx.r30.u32 + 6812, ctx.r11.u32);
	// bl 0x881538c0
	ctx.lr = 0x880DEB1C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// beq cr6,0x880deb74
	if (ctx.cr6.eq) goto loc_880DEB74;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880deb34
	if (ctx.cr6.eq) goto loc_880DEB34;
	// lwz r11,0(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880DEB34:
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x880deb74
	if (ctx.cr6.eq) goto loc_880DEB74;
	// lwz r11,0(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880deb74
	if (ctx.cr6.eq) goto loc_880DEB74;
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r11,r15,1
	ctx.r11.s64 = ctx.r15.s64 + 1;
	// rlwimi r9,r10,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// or r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 | ctx.r8.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r11,-11932(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11932, ctx.r11.u32);
	// b 0x880deb74
	goto loc_880DEB74;
loc_880DEB70:
	// lwz r20,88(r1)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
loc_880DEB74:
	// addi r21,r30,4940
	ctx.r21.s64 = ctx.r30.s64 + 4940;
	// li r19,2
	ctx.r19.s64 = 2;
	// addi r24,r30,8724
	ctx.r24.s64 = ctx.r30.s64 + 8724;
	// stw r21,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r21.u32);
	// addi r25,r30,5180
	ctx.r25.s64 = ctx.r30.s64 + 5180;
	// stw r19,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r19.u32);
	// addi r22,r30,7452
	ctx.r22.s64 = ctx.r30.s64 + 7452;
	// addi r28,r30,328
	ctx.r28.s64 = ctx.r30.s64 + 328;
	// lis r23,128
	ctx.r23.s64 = 8388608;
loc_880DEB98:
	// lwz r11,4(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880dee38
	if (!ctx.cr6.eq) goto loc_880DEE38;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x880ded74
	if (ctx.cr6.eq) goto loc_880DED74;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x880dee38
	if (!ctx.cr6.eq) goto loc_880DEE38;
	// lwz r11,92(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 92);
	// li r26,0
	ctx.r26.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x880decd0
	if (!ctx.cr6.gt) goto loc_880DECD0;
	// li r27,0
	ctx.r27.s64 = 0;
loc_880DEBCC:
	// divw r5,r27,r11
	ctx.r5.s32 = ppc_divw(ctx.r27.s32, ctx.r11.s32);
	// std r31,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r31.u64);
	// lwz r8,-100(r28)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r28.u32 + -100);
	// li r3,26923
	ctx.r3.s64 = 26923;
	// subfic r11,r5,128
	ctx.xer.ca = ctx.r5.u32 <= 128;
	ctx.r11.s64 = 128 - ctx.r5.s64;
	// lwz r7,44(r28)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r28.u32 + 44);
	// mullw r19,r5,r5
	ctx.r19.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r5.s32);
	// lwz r21,48(r28)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r28.u32 + 48);
	// lwz r17,-96(r28)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r28.u32 + -96);
	// lwz r4,-52(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + -52);
	// lwz r16,-48(r28)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r28.u32 + -48);
	// lwz r6,-4(r28)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r28.u32 + -4);
	// lwz r15,0(r28)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r14,0(r25)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// mullw r10,r11,r11
	ctx.r10.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r11.s32);
	// mullw r31,r11,r5
	ctx.r31.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r5.s32);
	// mullw r11,r10,r11
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// mullw r9,r10,r5
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r5.s32);
	// mullw r10,r31,r5
	ctx.r10.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r5.s32);
	// mullw r19,r19,r5
	ctx.r19.s64 = int64_t(ctx.r19.s32) * int64_t(ctx.r5.s32);
	// addi r5,r8,128
	ctx.r5.s64 = ctx.r8.s64 + 128;
	// lwz r8,100(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// rlwinm r11,r9,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r4,r4,128
	ctx.r4.s64 = ctx.r4.s64 + 128;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// addi r9,r7,128
	ctx.r9.s64 = ctx.r7.s64 + 128;
	// stw r8,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r8.u32);
	// rlwinm r7,r10,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// mullw r9,r21,r19
	ctx.r9.s64 = int64_t(ctx.r21.s32) * int64_t(ctx.r19.s32);
	// mullw r8,r17,r8
	ctx.r8.s64 = int64_t(ctx.r17.s32) * int64_t(ctx.r8.s32);
	// lwz r21,100(r1)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// mullw r5,r5,r21
	ctx.r5.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r21.s32);
	// lwz r21,96(r1)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// mullw r7,r21,r19
	ctx.r7.s64 = int64_t(ctx.r21.s32) * int64_t(ctx.r19.s32);
	// mullw r8,r16,r11
	ctx.r8.s64 = int64_t(ctx.r16.s32) * int64_t(ctx.r11.s32);
	// mullw r11,r4,r11
	ctx.r11.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r11.s32);
	// add r7,r7,r5
	ctx.r7.u64 = ctx.r7.u64 + ctx.r5.u64;
	// addi r6,r6,128
	ctx.r6.s64 = ctx.r6.s64 + 128;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// mullw r8,r15,r10
	ctx.r8.s64 = int64_t(ctx.r15.s32) * int64_t(ctx.r10.s32);
	// mullw r10,r6,r10
	ctx.r10.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r10.s32);
	// add r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 + ctx.r11.u64;
	// add r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r10,r5,27,5,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x7FFFFFF;
	// divw r11,r14,r29
	ctx.r11.s32 = ppc_divw(ctx.r14.s32, ctx.r29.s32);
	// rlwinm r9,r4,27,5,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x7FFFFFF;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// subf r4,r23,r9
	ctx.r4.s64 = ctx.r9.s64 - ctx.r23.s64;
	// mr r6,r20
	ctx.r6.u64 = ctx.r20.u64;
	// bl 0x881538c0
	ctx.lr = 0x880DECA8;
	sub_881538C0(ctx, base);
	// lwz r11,92(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 92);
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// ld r31,104(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// addi r27,r27,128
	ctx.r27.s64 = ctx.r27.s64 + 128;
	// cmpw cr6,r26,r11
	ctx.cr6.compare<int32_t>(ctx.r26.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x880debcc
	if (ctx.cr6.lt) goto loc_880DEBCC;
	// lwz r21,92(r1)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// li r17,5
	ctx.r17.s64 = 5;
	// lwz r19,88(r1)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r14,84(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_880DECD0:
	// lwz r11,-140(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -140);
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
	// blt cr6,0x880ded10
	if (ctx.cr6.lt) goto loc_880DED10;
	// cmpwi cr6,r11,64
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 64, ctx.xer);
	// bgt cr6,0x880decfc
	if (ctx.cr6.gt) goto loc_880DECFC;
	// subfic r8,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r8.s64 = 64 - ctx.r11.s64;
	// b 0x880ded14
	goto loc_880DED14;
loc_880DECFC:
	// li r4,-1
	ctx.r4.s64 = -1;
	// li r9,1
	ctx.r9.s64 = 1;
	// cmpwi cr6,r11,80
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 80, ctx.xer);
	// addi r8,r11,-64
	ctx.r8.s64 = ctx.r11.s64 + -64;
	// ble cr6,0x880ded14
	if (!ctx.cr6.gt) goto loc_880DED14;
loc_880DED10:
	// li r8,16
	ctx.r8.s64 = 16;
loc_880DED14:
	// lwz r10,-220(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + -220);
	// rlwinm r5,r8,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r6,-216(r28)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r28.u32 + -216);
	// addi r27,r31,-19796
	ctx.r27.s64 = ctx.r31.s64 + -19796;
	// lwz r11,0(r21)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r21.u32 + 0);
	// addi r7,r31,-19796
	ctx.r7.s64 = ctx.r31.s64 + -19796;
	// rlwinm r3,r8,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// divw r11,r11,r17
	ctx.r11.s32 = ppc_divw(ctx.r11.s32, ctx.r17.s32);
	// stw r10,-4(r24)
	PPC_STORE_U32(ctx.r24.u32 + -4, ctx.r10.u32);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// add r11,r11,r6
	ctx.r11.u64 = ctx.r11.u64 + ctx.r6.u64;
	// add r3,r3,r31
	ctx.r3.u64 = ctx.r3.u64 + ctx.r31.u64;
	// stw r11,0(r24)
	PPC_STORE_U32(ctx.r24.u32 + 0, ctx.r11.u32);
	// lbzx r6,r5,r27
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r27.u32);
	// extsb r6,r6
	ctx.r6.s64 = ctx.r6.s8;
	// lbzx r5,r5,r7
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r7.u32);
	// addi r7,r6,4
	ctx.r7.s64 = ctx.r6.s64 + 4;
	// extsb r5,r5
	ctx.r5.s64 = ctx.r5.s8;
	// mullw r6,r7,r4
	ctx.r6.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r4.s32);
	// rlwinm r4,r6,16,0,15
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r5,r5,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r4,r10
	ctx.r4.u64 = ctx.r4.u64 + ctx.r10.u64;
	// add r5,r5,r11
	ctx.r5.u64 = ctx.r5.u64 + ctx.r11.u64;
	// b 0x880dee28
	goto loc_880DEE28;
loc_880DED74:
	// lwz r11,-140(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -140);
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
	// blt cr6,0x880dedb4
	if (ctx.cr6.lt) goto loc_880DEDB4;
	// cmpwi cr6,r11,64
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 64, ctx.xer);
	// bgt cr6,0x880deda0
	if (ctx.cr6.gt) goto loc_880DEDA0;
	// subfic r8,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r8.s64 = 64 - ctx.r11.s64;
	// b 0x880dedb8
	goto loc_880DEDB8;
loc_880DEDA0:
	// li r4,-1
	ctx.r4.s64 = -1;
	// li r9,1
	ctx.r9.s64 = 1;
	// cmpwi cr6,r11,80
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 80, ctx.xer);
	// addi r8,r11,-64
	ctx.r8.s64 = ctx.r11.s64 + -64;
	// ble cr6,0x880dedb8
	if (!ctx.cr6.gt) goto loc_880DEDB8;
loc_880DEDB4:
	// li r8,16
	ctx.r8.s64 = 16;
loc_880DEDB8:
	// lwz r10,-48(r22)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r22.u32 + -48);
	// addi r7,r31,-19796
	ctx.r7.s64 = ctx.r31.s64 + -19796;
	// lwz r11,-52(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + -52);
	// rlwinm r16,r8,1,0,30
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r26,r7,1
	ctx.r26.s64 = ctx.r7.s64 + 1;
	// addi r15,r31,-19796
	ctx.r15.s64 = ctx.r31.s64 + -19796;
	// rlwinm r5,r8,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r10,-216(r28)
	PPC_STORE_U32(ctx.r28.u32 + -216, ctx.r10.u32);
	// stw r11,-220(r28)
	PPC_STORE_U32(ctx.r28.u32 + -220, ctx.r11.u32);
	// add r3,r5,r31
	ctx.r3.u64 = ctx.r5.u64 + ctx.r31.u64;
	// stw r11,-4(r24)
	PPC_STORE_U32(ctx.r24.u32 + -4, ctx.r11.u32);
	// stw r10,0(r24)
	PPC_STORE_U32(ctx.r24.u32 + 0, ctx.r10.u32);
	// lbzx r5,r16,r26
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r16.u32 + ctx.r26.u32);
	// lbzx r16,r16,r15
	ctx.r16.u64 = PPC_LOAD_U8(ctx.r16.u32 + ctx.r15.u32);
	// lwz r26,848(r30)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r30.u32 + 848);
	// stb r5,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r5.u8);
	// extsb r5,r16
	ctx.r5.s64 = ctx.r16.s8;
	// lbz r16,80(r1)
	ctx.r16.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lwz r27,844(r30)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r30.u32 + 844);
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// mullw r4,r5,r4
	ctx.r4.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r4.s32);
	// extsb r5,r16
	ctx.r5.s64 = ctx.r16.s8;
	// rlwinm r4,r4,16,0,15
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r5,r5,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r4,r27
	ctx.r4.u64 = ctx.r4.u64 + ctx.r27.u64;
	// add r5,r5,r26
	ctx.r5.u64 = ctx.r5.u64 + ctx.r26.u64;
	// add r4,r4,r11
	ctx.r4.u64 = ctx.r4.u64 + ctx.r11.u64;
	// add r5,r5,r10
	ctx.r5.u64 = ctx.r5.u64 + ctx.r10.u64;
loc_880DEE28:
	// mr r8,r14
	ctx.r8.u64 = ctx.r14.u64;
	// mr r7,r18
	ctx.r7.u64 = ctx.r18.u64;
	// mr r6,r20
	ctx.r6.u64 = ctx.r20.u64;
	// bl 0x880dcd70
	ctx.lr = 0x880DEE38;
	sub_880DCD70(ctx, base);
loc_880DEE38:
	// addic. r19,r19,-1
	ctx.xer.ca = ctx.r19.u32 > 0;
	ctx.r19.s64 = ctx.r19.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r19.s32, 0, ctx.xer);
	// addi r21,r21,288
	ctx.r21.s64 = ctx.r21.s64 + 288;
	// stw r19,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r19.u32);
	// addi r22,r22,84
	ctx.r22.s64 = ctx.r22.s64 + 84;
	// addi r25,r25,288
	ctx.r25.s64 = ctx.r25.s64 + 288;
	// stw r21,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r21.u32);
	// addi r28,r28,372
	ctx.r28.s64 = ctx.r28.s64 + 372;
	// addi r24,r24,144
	ctx.r24.s64 = ctx.r24.s64 + 144;
	// bne 0x880deb98
	if (!ctx.cr0.eq) goto loc_880DEB98;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880DEE68"))) PPC_WEAK_FUNC(sub_880DEE68);
PPC_FUNC_IMPL(__imp__sub_880DEE68) {
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
	// bl 0x880dca08
	ctx.lr = 0x880DEE78;
	sub_880DCA08(ctx, base);
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

__attribute__((alias("__imp__sub_880DEE8C"))) PPC_WEAK_FUNC(sub_880DEE8C);
PPC_FUNC_IMPL(__imp__sub_880DEE8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880DEE90"))) PPC_WEAK_FUNC(sub_880DEE90);
PPC_FUNC_IMPL(__imp__sub_880DEE90) {
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
	// addi r11,r4,9008
	ctx.r11.s64 = ctx.r4.s64 + 9008;
	// addi r9,r4,9004
	ctx.r9.s64 = ctx.r4.s64 + 9004;
	// ori r8,r10,65535
	ctx.r8.u64 = ctx.r10.u64 | 65535;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// lis r7,-30706
	ctx.r7.s64 = -2012348416;
	// stw r8,9008(r4)
	PPC_STORE_U32(ctx.r4.u32 + 9008, ctx.r8.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r7,-12656
	ctx.r5.s64 = ctx.r7.s64 + -12656;
	// li r4,30
	ctx.r4.s64 = 30;
	// bl 0x88096460
	ctx.lr = 0x880DEECC;
	sub_88096460(ctx, base);
	// lis r6,-30641
	ctx.r6.s64 = -2008088576;
	// addi r5,r6,-18908
	ctx.r5.s64 = ctx.r6.s64 + -18908;
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

__attribute__((alias("__imp__sub_880DEEE8"))) PPC_WEAK_FUNC(sub_880DEEE8);
PPC_FUNC_IMPL(__imp__sub_880DEEE8) {
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
	// addi r11,r4,8260
	ctx.r11.s64 = ctx.r4.s64 + 8260;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lis r9,-30706
	ctx.r9.s64 = -2012348416;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r9,-12656
	ctx.r5.s64 = ctx.r9.s64 + -12656;
	// li r4,30
	ctx.r4.s64 = 30;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x88096460
	ctx.lr = 0x880DEF20;
	sub_88096460(ctx, base);
	// lis r8,-30641
	ctx.r8.s64 = -2008088576;
	// lis r7,-30706
	ctx.r7.s64 = -2012348416;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r7,-4504
	ctx.r5.s64 = ctx.r7.s64 + -4504;
	// li r4,30
	ctx.r4.s64 = 30;
	// stw r3,-18908(r8)
	PPC_STORE_U32(ctx.r8.u32 + -18908, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r31,r8,-18908
	ctx.r31.s64 = ctx.r8.s64 + -18908;
	// bl 0x88096460
	ctx.lr = 0x880DEF44;
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

__attribute__((alias("__imp__sub_880DEF5C"))) PPC_WEAK_FUNC(sub_880DEF5C);
PPC_FUNC_IMPL(__imp__sub_880DEF5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880DEF60"))) PPC_WEAK_FUNC(sub_880DEF60);
PPC_FUNC_IMPL(__imp__sub_880DEF60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r3,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880DEF70"))) PPC_WEAK_FUNC(sub_880DEF70);
PPC_FUNC_IMPL(__imp__sub_880DEF70) {
	PPC_FUNC_PROLOGUE();
	// li r11,1
	ctx.r11.s64 = 1;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// stw r10,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880DEF84"))) PPC_WEAK_FUNC(sub_880DEF84);
PPC_FUNC_IMPL(__imp__sub_880DEF84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880DEF88"))) PPC_WEAK_FUNC(sub_880DEF88);
PPC_FUNC_IMPL(__imp__sub_880DEF88) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880DEF90;
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
	ctx.lr = 0x880DEFB0;
	sub_88096BC8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x880df018
	if (ctx.cr6.lt) goto loc_880DF018;
	// bne cr6,0x880df074
	if (!ctx.cr6.eq) goto loc_880DF074;
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x880df074
	if (!ctx.cr0.lt) goto loc_880DF074;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// lwz r10,860(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 860);
	// addic. r11,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r11.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,860(r31)
	PPC_STORE_U32(ctx.r31.u32 + 860, ctx.r11.u32);
	// bgt 0x880df074
	if (ctx.cr0.gt) goto loc_880DF074;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,860(r31)
	PPC_STORE_U32(ctx.r31.u32 + 860, ctx.r10.u32);
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// bgt 0x880df070
	if (ctx.cr0.gt) goto loc_880DF070;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096b40
	ctx.lr = 0x880DF00C;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_880DF018:
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880df044
	if (ctx.cr6.eq) goto loc_880DF044;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// bgt 0x880df074
	if (ctx.cr0.gt) goto loc_880DF074;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_880DF044:
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x880df074
	if (!ctx.cr0.lt) goto loc_880DF074;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// lwz r11,860(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 860);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,860(r31)
	PPC_STORE_U32(ctx.r31.u32 + 860, ctx.r11.u32);
	// cmpwi cr6,r11,9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 9, ctx.xer);
	// blt cr6,0x880df074
	if (ctx.cr6.lt) goto loc_880DF074;
loc_880DF070:
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_880DF074:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880DF080"))) PPC_WEAK_FUNC(sub_880DF080);
PPC_FUNC_IMPL(__imp__sub_880DF080) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880DF088;
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
	ctx.lr = 0x880DF0A8;
	sub_88096BC8(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,844(r31)
	PPC_STORE_U32(ctx.r31.u32 + 844, ctx.r10.u32);
	// lwz r9,2300(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2300);
	// lwz r8,160(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
	// neg r7,r8
	ctx.r7.s64 = -ctx.r8.s64;
	// stw r7,848(r31)
	PPC_STORE_U32(ctx.r31.u32 + 848, ctx.r7.u32);
	// lwz r6,44(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// addic. r11,r6,-1
	ctx.xer.ca = ctx.r6.u32 > 0;
	ctx.r11.s64 = ctx.r6.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r11.u32);
	// bge 0x880df0f4
	if (!ctx.cr0.lt) goto loc_880DF0F4;
	// stw r10,844(r31)
	PPC_STORE_U32(ctx.r31.u32 + 844, ctx.r10.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r10,848(r31)
	PPC_STORE_U32(ctx.r31.u32 + 848, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096b40
	ctx.lr = 0x880DF0E8;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_880DF0F4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880DF100"))) PPC_WEAK_FUNC(sub_880DF100);
PPC_FUNC_IMPL(__imp__sub_880DF100) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x880DF108;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880DF128;
	sub_88096BC8(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// mulli r9,r11,372
	ctx.r9.s64 = ctx.r11.s64 * 372;
	// add r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 + ctx.r31.u64;
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// addi r6,r9,100
	ctx.r6.s64 = ctx.r9.s64 + 100;
	// blt cr6,0x880df158
	if (ctx.cr6.lt) goto loc_880DF158;
	// beq cr6,0x880df190
	if (ctx.cr6.eq) goto loc_880DF190;
loc_880DF14C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_880DF158:
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// li r10,6
	ctx.r10.s64 = 6;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r9,r9,5,0,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// add r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 + ctx.r31.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// addi r10,r9,4892
	ctx.r10.s64 = ctx.r9.s64 + 4892;
loc_880DF174:
	// stwu r5,48(r10)
	ea = 48 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x880df174
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_880DF174;
	// li r10,7
	ctx.r10.s64 = 7;
	// stw r10,104(r6)
	PPC_STORE_U32(ctx.r6.u32 + 104, ctx.r10.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_880DF190:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// bge 0x880df14c
	if (!ctx.cr0.lt) goto loc_880DF14C;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// li r30,1
	ctx.r30.s64 = 1;
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// lwz r9,104(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 104);
	// cmpwi cr6,r9,7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 7, ctx.xer);
	// bne cr6,0x880df22c
	if (!ctx.cr6.eq) goto loc_880DF22C;
	// mulli r10,r11,84
	ctx.r10.s64 = ctx.r11.s64 * 84;
	// stw r30,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r30.u32);
	// add r8,r10,r31
	ctx.r8.u64 = ctx.r10.u64 + ctx.r31.u64;
	// li r7,2
	ctx.r7.s64 = 2;
	// li r9,24
	ctx.r9.s64 = 24;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r10,r6,124
	ctx.r10.s64 = ctx.r6.s64 + 124;
	// stw r7,7452(r8)
	PPC_STORE_U32(ctx.r8.u32 + 7452, ctx.r7.u32);
	// lwz r8,12(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// lwz r3,8(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// stw r4,112(r6)
	PPC_STORE_U32(ctx.r6.u32 + 112, ctx.r4.u32);
	// stw r5,348(r6)
	PPC_STORE_U32(ctx.r6.u32 + 348, ctx.r5.u32);
	// stw r5,352(r6)
	PPC_STORE_U32(ctx.r6.u32 + 352, ctx.r5.u32);
	// stw r3,332(r6)
	PPC_STORE_U32(ctx.r6.u32 + 332, ctx.r3.u32);
	// stw r8,336(r6)
	PPC_STORE_U32(ctx.r6.u32 + 336, ctx.r8.u32);
	// stw r3,340(r6)
	PPC_STORE_U32(ctx.r6.u32 + 340, ctx.r3.u32);
	// stw r8,344(r6)
	PPC_STORE_U32(ctx.r6.u32 + 344, ctx.r8.u32);
	// stw r5,92(r6)
	PPC_STORE_U32(ctx.r6.u32 + 92, ctx.r5.u32);
	// stw r5,356(r6)
	PPC_STORE_U32(ctx.r6.u32 + 356, ctx.r5.u32);
loc_880DF208:
	// stw r5,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r5.u32);
	// stwu r5,8(r10)
	ea = 8 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x880df208
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_880DF208;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880df224
	if (ctx.cr6.eq) goto loc_880DF224;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x880df22c
	if (!ctx.cr6.eq) goto loc_880DF22C;
loc_880DF224:
	// li r11,256
	ctx.r11.s64 = 256;
	// stw r11,116(r6)
	PPC_STORE_U32(ctx.r6.u32 + 116, ctx.r11.u32);
loc_880DF22C:
	// lwz r11,104(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 104);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,104(r6)
	PPC_STORE_U32(ctx.r6.u32 + 104, ctx.r11.u32);
	// cmpwi cr6,r11,15
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 15, ctx.xer);
	// blt cr6,0x880df14c
	if (ctx.cr6.lt) goto loc_880DF14C;
	// li r11,15
	ctx.r11.s64 = 15;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// stw r11,104(r6)
	PPC_STORE_U32(ctx.r6.u32 + 104, ctx.r11.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88096b40
	ctx.lr = 0x880DF254;
	sub_88096B40(ctx, base);
	// stw r5,108(r6)
	PPC_STORE_U32(ctx.r6.u32 + 108, ctx.r5.u32);
	// stw r30,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r30.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r5,48(r6)
	PPC_STORE_U32(ctx.r6.u32 + 48, ctx.r5.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880DF26C"))) PPC_WEAK_FUNC(sub_880DF26C);
PPC_FUNC_IMPL(__imp__sub_880DF26C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880DF270"))) PPC_WEAK_FUNC(sub_880DF270);
PPC_FUNC_IMPL(__imp__sub_880DF270) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880DF278;
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
	ctx.lr = 0x880DF298;
	sub_88096BC8(ctx, base);
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x880df2dc
	if (!ctx.cr6.eq) goto loc_880DF2DC;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// bgt 0x880df31c
	if (ctx.cr0.gt) goto loc_880DF31C;
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// lwz r10,88(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x880df2f4
	if (ctx.cr6.lt) goto loc_880DF2F4;
	// stw r10,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r10.u32);
loc_880DF2DC:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096b40
	ctx.lr = 0x880DF2E8;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_880DF2F4:
	// cmpwi cr6,r11,15
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 15, ctx.xer);
	// blt cr6,0x880df31c
	if (ctx.cr6.lt) goto loc_880DF31C;
	// li r11,15
	ctx.r11.s64 = 15;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096b40
	ctx.lr = 0x880DF310;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_880DF31C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880DF328"))) PPC_WEAK_FUNC(sub_880DF328);
PPC_FUNC_IMPL(__imp__sub_880DF328) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880DF330;
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
	ctx.lr = 0x880DF350;
	sub_88096BC8(ctx, base);
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x880df394
	if (!ctx.cr6.eq) goto loc_880DF394;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// bgt 0x880df3d4
	if (ctx.cr0.gt) goto loc_880DF3D4;
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// lwz r10,88(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bgt cr6,0x880df3ac
	if (ctx.cr6.gt) goto loc_880DF3AC;
	// stw r10,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r10.u32);
loc_880DF394:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096b40
	ctx.lr = 0x880DF3A0;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_880DF3AC:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt cr6,0x880df3d4
	if (ctx.cr6.gt) goto loc_880DF3D4;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096b40
	ctx.lr = 0x880DF3C8;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_880DF3D4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880DF3E0"))) PPC_WEAK_FUNC(sub_880DF3E0);
PPC_FUNC_IMPL(__imp__sub_880DF3E0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880DF3E8;
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
	ctx.lr = 0x880DF408;
	sub_88096BC8(ctx, base);
	// lwz r10,5812(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 5812);
	// addi r11,r29,5768
	ctx.r11.s64 = ctx.r29.s64 + 5768;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880df430
	if (ctx.cr6.eq) goto loc_880DF430;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880DF424;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_880DF430:
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// bgt 0x880df478
	if (ctx.cr0.gt) goto loc_880DF478;
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
	// bgt 0x880df478
	if (ctx.cr0.gt) goto loc_880DF478;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r10,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880DF46C;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_880DF478:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880DF484"))) PPC_WEAK_FUNC(sub_880DF484);
PPC_FUNC_IMPL(__imp__sub_880DF484) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880DF488"))) PPC_WEAK_FUNC(sub_880DF488);
PPC_FUNC_IMPL(__imp__sub_880DF488) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880DF490;
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
	ctx.lr = 0x880DF4B0;
	sub_88096BC8(ctx, base);
	// lwz r10,5812(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5812);
	// addi r11,r31,5768
	ctx.r11.s64 = ctx.r31.s64 + 5768;
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// beq cr6,0x880df4d8
	if (ctx.cr6.eq) goto loc_880DF4D8;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096b40
	ctx.lr = 0x880DF4CC;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_880DF4D8:
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// bgt 0x880df538
	if (ctx.cr0.gt) goto loc_880DF538;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmpwi cr6,r10,128
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 128, ctx.xer);
	// blt cr6,0x880df504
	if (ctx.cr6.lt) goto loc_880DF504;
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// stw r10,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r10.u32);
loc_880DF504:
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// addi r10,r10,5
	ctx.r10.s64 = ctx.r10.s64 + 5;
	// stw r10,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r10.u32);
	// cmpwi cr6,r10,240
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 240, ctx.xer);
	// blt cr6,0x880df538
	if (ctx.cr6.lt) goto loc_880DF538;
	// li r10,240
	ctx.r10.s64 = 240;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r10,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096b40
	ctx.lr = 0x880DF52C;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_880DF538:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880DF544"))) PPC_WEAK_FUNC(sub_880DF544);
PPC_FUNC_IMPL(__imp__sub_880DF544) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880DF548"))) PPC_WEAK_FUNC(sub_880DF548);
PPC_FUNC_IMPL(__imp__sub_880DF548) {
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
	ctx.lr = 0x880DF574;
	sub_88096BC8(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// beq cr6,0x880df598
	if (ctx.cr6.eq) goto loc_880DF598;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880DF590;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880df5f4
	goto loc_880DF5F4;
loc_880DF598:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// bgt 0x880df5f0
	if (ctx.cr0.gt) goto loc_880DF5F0;
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
	// bgt cr6,0x880df5f0
	if (ctx.cr6.gt) goto loc_880DF5F0;
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
	ctx.lr = 0x880DF5E8;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880df5f4
	goto loc_880DF5F4;
loc_880DF5F0:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880DF5F4:
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

__attribute__((alias("__imp__sub_880DF60C"))) PPC_WEAK_FUNC(sub_880DF60C);
PPC_FUNC_IMPL(__imp__sub_880DF60C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880DF610"))) PPC_WEAK_FUNC(sub_880DF610);
PPC_FUNC_IMPL(__imp__sub_880DF610) {
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
	ctx.lr = 0x880DF63C;
	sub_88096BC8(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// beq cr6,0x880df660
	if (ctx.cr6.eq) goto loc_880DF660;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880DF658;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880df6b4
	goto loc_880DF6B4;
loc_880DF660:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// bgt 0x880df6b0
	if (ctx.cr0.gt) goto loc_880DF6B0;
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
	// cmpwi cr6,r8,128
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 128, ctx.xer);
	// blt cr6,0x880df6b0
	if (ctx.cr6.lt) goto loc_880DF6B0;
	// li r10,128
	ctx.r10.s64 = 128;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880DF6A8;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880df6b4
	goto loc_880DF6B4;
loc_880DF6B0:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880DF6B4:
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

__attribute__((alias("__imp__sub_880DF6CC"))) PPC_WEAK_FUNC(sub_880DF6CC);
PPC_FUNC_IMPL(__imp__sub_880DF6CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880DF6D0"))) PPC_WEAK_FUNC(sub_880DF6D0);
PPC_FUNC_IMPL(__imp__sub_880DF6D0) {
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
	ctx.lr = 0x880DF6FC;
	sub_88096BC8(ctx, base);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// bgt 0x880df76c
	if (ctx.cr0.gt) goto loc_880DF76C;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r7,21
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 21, ctx.xer);
	// blt cr6,0x880df76c
	if (ctx.cr6.lt) goto loc_880DF76C;
	// li r9,21
	ctx.r9.s64 = 21;
	// li r8,1
	ctx.r8.s64 = 1;
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
	ctx.lr = 0x880DF764;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880df770
	goto loc_880DF770;
loc_880DF76C:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880DF770:
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

__attribute__((alias("__imp__sub_880DF788"))) PPC_WEAK_FUNC(sub_880DF788);
PPC_FUNC_IMPL(__imp__sub_880DF788) {
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
	ctx.lr = 0x880DF7B4;
	sub_88096BC8(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// beq cr6,0x880df7d8
	if (ctx.cr6.eq) goto loc_880DF7D8;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880DF7D0;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880df834
	goto loc_880DF834;
loc_880DF7D8:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// bgt 0x880df830
	if (ctx.cr0.gt) goto loc_880DF830;
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
	// bgt cr6,0x880df830
	if (ctx.cr6.gt) goto loc_880DF830;
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
	ctx.lr = 0x880DF828;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880df834
	goto loc_880DF834;
loc_880DF830:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880DF834:
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

__attribute__((alias("__imp__sub_880DF84C"))) PPC_WEAK_FUNC(sub_880DF84C);
PPC_FUNC_IMPL(__imp__sub_880DF84C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880DF850"))) PPC_WEAK_FUNC(sub_880DF850);
PPC_FUNC_IMPL(__imp__sub_880DF850) {
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
	ctx.lr = 0x880DF87C;
	sub_88096BC8(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// beq cr6,0x880df8a0
	if (ctx.cr6.eq) goto loc_880DF8A0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880DF898;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880df8f4
	goto loc_880DF8F4;
loc_880DF8A0:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// bgt 0x880df8f0
	if (ctx.cr0.gt) goto loc_880DF8F0;
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
	// cmpwi cr6,r8,24
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 24, ctx.xer);
	// blt cr6,0x880df8f0
	if (ctx.cr6.lt) goto loc_880DF8F0;
	// li r10,23
	ctx.r10.s64 = 23;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880DF8E8;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880df8f4
	goto loc_880DF8F4;
loc_880DF8F0:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880DF8F4:
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

__attribute__((alias("__imp__sub_880DF90C"))) PPC_WEAK_FUNC(sub_880DF90C);
PPC_FUNC_IMPL(__imp__sub_880DF90C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880DF910"))) PPC_WEAK_FUNC(sub_880DF910);
PPC_FUNC_IMPL(__imp__sub_880DF910) {
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
	ctx.lr = 0x880DF93C;
	sub_88096BC8(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// bne cr6,0x880df960
	if (!ctx.cr6.eq) goto loc_880DF960;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 48);
	// cmpwi cr6,r10,256
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 256, ctx.xer);
	// bne cr6,0x880df9dc
	if (!ctx.cr6.eq) goto loc_880DF9DC;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_880DF960:
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// beq cr6,0x880df984
	if (ctx.cr6.eq) goto loc_880DF984;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880DF97C;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880df9e0
	goto loc_880DF9E0;
loc_880DF984:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// bgt 0x880df9dc
	if (ctx.cr0.gt) goto loc_880DF9DC;
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
	// bgt cr6,0x880df9dc
	if (ctx.cr6.gt) goto loc_880DF9DC;
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
	ctx.lr = 0x880DF9D4;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880df9e0
	goto loc_880DF9E0;
loc_880DF9DC:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880DF9E0:
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

__attribute__((alias("__imp__sub_880DF9F8"))) PPC_WEAK_FUNC(sub_880DF9F8);
PPC_FUNC_IMPL(__imp__sub_880DF9F8) {
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
	ctx.lr = 0x880DFA24;
	sub_88096BC8(ctx, base);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// beq cr6,0x880dfa4c
	if (ctx.cr6.eq) goto loc_880DFA4C;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880DFA44;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880dfac4
	goto loc_880DFAC4;
loc_880DFA4C:
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// bgt 0x880dfac0
	if (ctx.cr0.gt) goto loc_880DFAC0;
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
	// cmpwi cr6,r7,8
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 8, ctx.xer);
	// blt cr6,0x880dfac0
	if (ctx.cr6.lt) goto loc_880DFAC0;
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
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r8,64(r6)
	PPC_STORE_U32(ctx.r6.u32 + 64, ctx.r8.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r7,48(r10)
	PPC_STORE_U32(ctx.r10.u32 + 48, ctx.r7.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// stw r5,72(r9)
	PPC_STORE_U32(ctx.r9.u32 + 72, ctx.r5.u32);
	// bl 0x88096b40
	ctx.lr = 0x880DFAB8;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880dfac4
	goto loc_880DFAC4;
loc_880DFAC0:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880DFAC4:
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

__attribute__((alias("__imp__sub_880DFADC"))) PPC_WEAK_FUNC(sub_880DFADC);
PPC_FUNC_IMPL(__imp__sub_880DFADC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880DFAE0"))) PPC_WEAK_FUNC(sub_880DFAE0);
PPC_FUNC_IMPL(__imp__sub_880DFAE0) {
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
	// lwz r10,9004(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 9004);
	// addic. r10,r10,-8
	ctx.xer.ca = ctx.r10.u32 > 7;
	ctx.r10.s64 = ctx.r10.s64 + -8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,9004(r11)
	PPC_STORE_U32(ctx.r11.u32 + 9004, ctx.r10.u32);
	// bgt 0x880dfb30
	if (ctx.cr0.gt) goto loc_880DFB30;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// stw r10,9004(r11)
	PPC_STORE_U32(ctx.r11.u32 + 9004, ctx.r10.u32);
	// bl 0x880dc6d0
	ctx.lr = 0x880DFB14;
	sub_880DC6D0(ctx, base);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// bl 0x88096b40
	ctx.lr = 0x880DFB1C;
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
loc_880DFB30:
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

__attribute__((alias("__imp__sub_880DFB44"))) PPC_WEAK_FUNC(sub_880DFB44);
PPC_FUNC_IMPL(__imp__sub_880DFB44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880DFB48"))) PPC_WEAK_FUNC(sub_880DFB48);
PPC_FUNC_IMPL(__imp__sub_880DFB48) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x880DFB50;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
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
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880DFB74;
	sub_88096BC8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// lis r8,-30706
	ctx.r8.s64 = -2012348416;
	// stw r11,860(r28)
	PPC_STORE_U32(ctx.r28.u32 + 860, ctx.r11.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r7,0(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// addi r5,r8,-4216
	ctx.r5.s64 = ctx.r8.s64 + -4216;
	// stw r7,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r6,4(r29)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// stw r6,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r6.u32);
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// bl 0x88096c60
	ctx.lr = 0x880DFBB0;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880DFBBC"))) PPC_WEAK_FUNC(sub_880DFBBC);
PPC_FUNC_IMPL(__imp__sub_880DFBBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880DFBC0"))) PPC_WEAK_FUNC(sub_880DFBC0);
PPC_FUNC_IMPL(__imp__sub_880DFBC0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071128
	ctx.lr = 0x880DFBC8;
	__savegprlr_16(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r17,r4
	ctx.r17.u64 = ctx.r4.u64;
	// lwz r19,2304(r3)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r16,r5
	ctx.r16.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r16
	ctx.r4.u64 = ctx.r16.u64;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880DFBE8;
	sub_88096BC8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,8(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r18,0
	ctx.r18.s64 = 0;
	// li r20,2
	ctx.r20.s64 = 2;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x880dfc14
	if (ctx.cr6.lt) goto loc_880DFC14;
	// beq cr6,0x880dfc28
	if (ctx.cr6.eq) goto loc_880DFC28;
loc_880DFC08:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071178
	__restgprlr_16(ctx, base);
	return;
loc_880DFC14:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r18,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r18.u32);
	// stw r20,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r20.u32);
	// stw r18,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r18.u32);
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
loc_880DFC28:
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r11.u32);
	// bge 0x880dfc08
	if (!ctx.cr0.lt) goto loc_880DFC08;
	// lwz r11,24(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// lis r10,-30680
	ctx.r10.s64 = -2010644480;
	// lwz r7,20(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// lis r24,-30667
	ctx.r24.s64 = -2009792512;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r5,4(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// addi r8,r10,-16016
	ctx.r8.s64 = ctx.r10.s64 + -16016;
	// add r4,r11,r9
	ctx.r4.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lis r25,-30667
	ctx.r25.s64 = -2009792512;
	// rlwinm r11,r4,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r7,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r7.u32);
	// lwz r10,16(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 16);
	// addi r29,r6,1
	ctx.r29.s64 = ctx.r6.s64 + 1;
	// add r31,r11,r8
	ctx.r31.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lwz r7,12(r5)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lis r21,-30667
	ctx.r21.s64 = -2009792512;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// add r27,r7,r9
	ctx.r27.u64 = ctx.r7.u64 + ctx.r9.u64;
	// add r26,r10,r11
	ctx.r26.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r27,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r27.u32);
	// stw r26,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r26.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880DFC9C;
	sub_880F52C8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880dfcb4
	if (ctx.cr6.eq) goto loc_880DFCB4;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// clrlwi r10,r11,16
	ctx.r10.u64 = ctx.r11.u32 & 0xFFFF;
	// stw r10,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r10.u32);
loc_880DFCB4:
	// li r3,63
	ctx.r3.s64 = 63;
	// bl 0x881534c8
	ctx.lr = 0x880DFCBC;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// rlwinm r23,r11,3,0,28
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// beq cr6,0x880dfcdc
	if (ctx.cr6.eq) goto loc_880DFCDC;
	// lwz r11,44(r19)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r19.u32 + 44);
	// li r10,112
	ctx.r10.s64 = 112;
	// stw r10,140(r28)
	PPC_STORE_U32(ctx.r28.u32 + 140, ctx.r10.u32);
	// stw r11,144(r28)
	PPC_STORE_U32(ctx.r28.u32 + 144, ctx.r11.u32);
loc_880DFCDC:
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x881534c8
	ctx.lr = 0x880DFCE4;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// addi r4,r11,8
	ctx.r4.s64 = ctx.r11.s64 + 8;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x880f5570
	ctx.lr = 0x880DFCF8;
	sub_880F5570(ctx, base);
	// stw r27,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r27.u32);
	// stw r26,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r26.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// lis r22,-30667
	ctx.r22.s64 = -2009792512;
	// bl 0x880f52c8
	ctx.lr = 0x880DFD14;
	sub_880F52C8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880dfd30
	if (ctx.cr6.eq) goto loc_880DFD30;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r20,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r20.u32);
	// clrlwi r10,r11,16
	ctx.r10.u64 = ctx.r11.u32 & 0xFFFF;
	// stw r10,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r10.u32);
loc_880DFD30:
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x881534c8
	ctx.lr = 0x880DFD38;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,32
	ctx.r3.s64 = 32;
	// addi r31,r11,8
	ctx.r31.s64 = ctx.r11.s64 + 8;
	// bl 0x881534c8
	ctx.lr = 0x880DFD48;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// add r11,r11,r23
	ctx.r11.u64 = ctx.r11.u64 + ctx.r23.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r5,r11,-16
	ctx.r5.s64 = ctx.r11.s64 + -16;
	// bl 0x880f5570
	ctx.lr = 0x880DFD60;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x880dfd78
	if (ctx.cr6.eq) goto loc_880DFD78;
	// li r11,96
	ctx.r11.s64 = 96;
	// stw r11,140(r28)
	PPC_STORE_U32(ctx.r28.u32 + 140, ctx.r11.u32);
	// lwz r10,44(r19)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r19.u32 + 44);
	// stw r10,144(r28)
	PPC_STORE_U32(ctx.r28.u32 + 144, ctx.r10.u32);
loc_880DFD78:
	// mr r11,r18
	ctx.r11.u64 = ctx.r18.u64;
	// stw r27,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r27.u32);
	// stw r26,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r26.u32);
	// li r31,3
	ctx.r31.s64 = 3;
	// stw r18,12380(r21)
	PPC_STORE_U32(ctx.r21.u32 + 12380, ctx.r18.u32);
	// stw r29,12376(r22)
	PPC_STORE_U32(ctx.r22.u32 + 12376, ctx.r29.u32);
loc_880DFD90:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x880f34b0
	ctx.lr = 0x880DFD9C;
	sub_880F34B0(ctx, base);
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x880dfd90
	if (!ctx.cr0.eq) goto loc_880DFD90;
	// lwz r11,24(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r11.u32);
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// blt cr6,0x880dfc08
	if (ctx.cr6.lt) goto loc_880DFC08;
	// stw r18,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r18.u32);
	// mr r4,r16
	ctx.r4.u64 = ctx.r16.u64;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// bl 0x88096b40
	ctx.lr = 0x880DFDC8;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071178
	__restgprlr_16(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880DFDD4"))) PPC_WEAK_FUNC(sub_880DFDD4);
PPC_FUNC_IMPL(__imp__sub_880DFDD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880DFDD8"))) PPC_WEAK_FUNC(sub_880DFDD8);
PPC_FUNC_IMPL(__imp__sub_880DFDD8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071128
	ctx.lr = 0x880DFDE0;
	__savegprlr_16(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r17,r4
	ctx.r17.u64 = ctx.r4.u64;
	// lwz r22,2304(r3)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r16,r5
	ctx.r16.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r16
	ctx.r4.u64 = ctx.r16.u64;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880DFE00;
	sub_88096BC8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r24,8(r3)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r18,0
	ctx.r18.s64 = 0;
	// li r19,2
	ctx.r19.s64 = 2;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x880dfe2c
	if (ctx.cr6.lt) goto loc_880DFE2C;
	// beq cr6,0x880dfe94
	if (ctx.cr6.eq) goto loc_880DFE94;
loc_880DFE20:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071178
	__restgprlr_16(ctx, base);
	return;
loc_880DFE2C:
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r8,4
	ctx.r8.s64 = 4;
	// mr r10,r18
	ctx.r10.u64 = ctx.r18.u64;
	// stw r11,60(r9)
	PPC_STORE_U32(ctx.r9.u32 + 60, ctx.r11.u32);
	// lwz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// stw r11,68(r7)
	PPC_STORE_U32(ctx.r7.u32 + 68, ctx.r11.u32);
	// lwz r6,4(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// stw r8,64(r6)
	PPC_STORE_U32(ctx.r6.u32 + 64, ctx.r8.u32);
	// lwz r5,8140(r22)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r22.u32 + 8140);
	// lwz r11,28(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880dfe78
	if (ctx.cr6.eq) goto loc_880DFE78;
loc_880DFE60:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880dfe78
	if (ctx.cr6.eq) goto loc_880DFE78;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880dfe60
	if (!ctx.cr6.eq) goto loc_880DFE60;
loc_880DFE78:
	// stw r18,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r18.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r18,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r18.u32);
	// stw r19,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r19.u32);
	// stw r18,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r18.u32);
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
loc_880DFE94:
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r11.u32);
	// bge 0x880dfe20
	if (!ctx.cr0.lt) goto loc_880DFE20;
	// lwz r8,20(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// lis r7,-30680
	ctx.r7.s64 = -2010644480;
	// lwz r6,4(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// lis r26,-30667
	ctx.r26.s64 = -2009792512;
	// lwz r11,24(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// addi r9,r7,-16448
	ctx.r9.s64 = ctx.r7.s64 + -16448;
	// lis r25,-30667
	ctx.r25.s64 = -2009792512;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r8,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r8.u32);
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// lwz r8,16(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r7,12(r6)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// lis r21,-30667
	ctx.r21.s64 = -2009792512;
	// rlwinm r11,r5,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r31,r11,r9
	ctx.r31.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// add r27,r7,r11
	ctx.r27.u64 = ctx.r7.u64 + ctx.r11.u64;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// add r28,r8,r11
	ctx.r28.u64 = ctx.r8.u64 + ctx.r11.u64;
	// stw r27,12364(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12364, ctx.r27.u32);
	// stw r28,12372(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12372, ctx.r28.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x880f52c8
	ctx.lr = 0x880DFF04;
	sub_880F52C8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x881534c8
	ctx.lr = 0x880DFF10;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,16
	ctx.r3.s64 = 16;
	// addi r23,r11,240
	ctx.r23.s64 = ctx.r11.s64 + 240;
	// bl 0x881534c8
	ctx.lr = 0x880DFF20;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r4,r11,72
	ctx.r4.s64 = ctx.r11.s64 + 72;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// bl 0x880f5570
	ctx.lr = 0x880DFF34;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x880dff48
	if (ctx.cr6.eq) goto loc_880DFF48;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// clrlwi r10,r11,16
	ctx.r10.u64 = ctx.r11.u32 & 0xFFFF;
	// stw r10,100(r29)
	PPC_STORE_U32(ctx.r29.u32 + 100, ctx.r10.u32);
loc_880DFF48:
	// lwz r11,56(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 56);
	// addi r10,r11,453
	ctx.r10.s64 = ctx.r11.s64 + 453;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r22
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r22.u32);
	// cmpwi cr6,r8,1
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 1, ctx.xer);
	// bne cr6,0x880dff98
	if (!ctx.cr6.eq) goto loc_880DFF98;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,0(r22)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r8,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r4,12(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// add r11,r11,r22
	ctx.r11.u64 = ctx.r11.u64 + ctx.r22.u64;
	// lwz r8,9076(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 9076);
	// lwz r7,9072(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 9072);
	// lwz r6,9068(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 9068);
	// lwz r5,9064(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 9064);
	// bl 0x880f5438
	ctx.lr = 0x880DFF98;
	sub_880F5438(ctx, base);
loc_880DFF98:
	// stw r27,12364(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12364, ctx.r27.u32);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// stw r28,12372(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12372, ctx.r28.u32);
	// lis r20,-30667
	ctx.r20.s64 = -2009792512;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
	// bl 0x880f52c8
	ctx.lr = 0x880DFFB8;
	sub_880F52C8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880dffc8
	if (ctx.cr6.eq) goto loc_880DFFC8;
	// stw r19,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r19.u32);
loc_880DFFC8:
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x881534c8
	ctx.lr = 0x880DFFD0;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,32
	ctx.r3.s64 = 32;
	// addi r11,r11,72
	ctx.r11.s64 = ctx.r11.s64 + 72;
	// rlwinm r29,r11,1,0,30
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// bl 0x881534c8
	ctx.lr = 0x880DFFE4;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// add r11,r11,r23
	ctx.r11.u64 = ctx.r11.u64 + ctx.r23.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r5,r11,-16
	ctx.r5.s64 = ctx.r11.s64 + -16;
	// bl 0x880f5570
	ctx.lr = 0x880DFFFC;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x880e0014
	if (ctx.cr6.eq) goto loc_880E0014;
	// li r11,112
	ctx.r11.s64 = 112;
	// li r10,10
	ctx.r10.s64 = 10;
	// stw r11,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r11.u32);
	// stw r10,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r10.u32);
loc_880E0014:
	// lwz r11,56(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 56);
	// addi r10,r11,453
	ctx.r10.s64 = ctx.r11.s64 + 453;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r22
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r22.u32);
	// cmpwi cr6,r8,1
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 1, ctx.xer);
	// bne cr6,0x880e0064
	if (!ctx.cr6.eq) goto loc_880E0064;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,0(r22)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r8,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r4,12(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// add r11,r11,r22
	ctx.r11.u64 = ctx.r11.u64 + ctx.r22.u64;
	// lwz r8,9076(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 9076);
	// lwz r7,9072(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 9072);
	// lwz r6,9068(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 9068);
	// lwz r5,9064(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 9064);
	// bl 0x880f5438
	ctx.lr = 0x880E0064;
	sub_880F5438(ctx, base);
loc_880E0064:
	// stw r27,12364(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12364, ctx.r27.u32);
	// li r11,24
	ctx.r11.s64 = 24;
	// stw r28,12372(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12372, ctx.r28.u32);
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,12380(r21)
	PPC_STORE_U32(ctx.r21.u32 + 12380, ctx.r11.u32);
	// bl 0x880f34b0
	ctx.lr = 0x880E0080;
	sub_880F34B0(ctx, base);
	// lis r31,-30671
	ctx.r31.s64 = -2010054656;
	// lis r11,16838
	ctx.r11.s64 = 1103495168;
	// lis r10,-1009
	ctx.r10.s64 = -66125824;
	// ori r29,r11,20077
	ctx.r29.u64 = ctx.r11.u64 | 20077;
	// ori r28,r10,49405
	ctx.r28.u64 = ctx.r10.u64 | 49405;
	// lwz r11,4200(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4200);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// mullw r11,r11,r29
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r29.s32);
	// addi r27,r11,12345
	ctx.r27.s64 = ctx.r11.s64 + 12345;
	// stw r27,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r27.u32);
	// beq cr6,0x880e00d4
	if (ctx.cr6.eq) goto loc_880E00D4;
	// lhz r9,4200(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// mulhwu r8,r9,r28
	ctx.r8.u64 = (uint64_t(ctx.r9.u32) * uint64_t(ctx.r28.u32)) >> 32;
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
loc_880E00D4:
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x880f34b0
	ctx.lr = 0x880E00E0;
	sub_880F34B0(ctx, base);
	// mullw r11,r27,r29
	ctx.r11.s64 = int64_t(ctx.r27.s32) * int64_t(ctx.r29.s32);
	// addi r27,r11,12345
	ctx.r27.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r27,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r27.u32);
	// beq cr6,0x880e011c
	if (ctx.cr6.eq) goto loc_880E011C;
	// lhz r9,4200(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// mulhwu r8,r9,r28
	ctx.r8.u64 = (uint64_t(ctx.r9.u32) * uint64_t(ctx.r28.u32)) >> 32;
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
loc_880E011C:
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// stw r24,12376(r20)
	PPC_STORE_U32(ctx.r20.u32 + 12376, ctx.r24.u32);
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x880f34b0
	ctx.lr = 0x880E012C;
	sub_880F34B0(ctx, base);
	// mullw r11,r27,r29
	ctx.r11.s64 = int64_t(ctx.r27.s32) * int64_t(ctx.r29.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r11,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r11.u32);
	// beq cr6,0x880e0168
	if (ctx.cr6.eq) goto loc_880E0168;
	// lhz r9,4200(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// mulhwu r8,r9,r28
	ctx.r8.u64 = (uint64_t(ctx.r9.u32) * uint64_t(ctx.r28.u32)) >> 32;
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
loc_880E0168:
	// lwz r11,24(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r11.u32);
	// cmplwi cr6,r11,12
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 12, ctx.xer);
	// blt cr6,0x880dfe20
	if (ctx.cr6.lt) goto loc_880DFE20;
	// stw r18,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r18.u32);
	// mr r4,r16
	ctx.r4.u64 = ctx.r16.u64;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// bl 0x88096b40
	ctx.lr = 0x880E018C;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071178
	__restgprlr_16(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E0198"))) PPC_WEAK_FUNC(sub_880E0198);
PPC_FUNC_IMPL(__imp__sub_880E0198) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071128
	ctx.lr = 0x880E01A0;
	__savegprlr_16(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r17,r4
	ctx.r17.u64 = ctx.r4.u64;
	// lwz r21,2304(r3)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r16,r5
	ctx.r16.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r16
	ctx.r4.u64 = ctx.r16.u64;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880E01C0;
	sub_88096BC8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r30,8(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r18,0
	ctx.r18.s64 = 0;
	// li r20,2
	ctx.r20.s64 = 2;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x880e01ec
	if (ctx.cr6.lt) goto loc_880E01EC;
	// beq cr6,0x880e024c
	if (ctx.cr6.eq) goto loc_880E024C;
loc_880E01E0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071178
	__restgprlr_16(ctx, base);
	return;
loc_880E01EC:
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
	// stw r18,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r18.u32);
	// stw r20,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r20.u32);
	// stw r18,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r18.u32);
	// stw r8,48(r21)
	PPC_STORE_U32(ctx.r21.u32 + 48, ctx.r8.u32);
	// bl 0x881534c8
	ctx.lr = 0x880E0228;
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
	// stw r4,52(r21)
	PPC_STORE_U32(ctx.r21.u32 + 52, ctx.r4.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// stw r3,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
loc_880E024C:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// bge 0x880e01e0
	if (!ctx.cr0.lt) goto loc_880E01E0;
	// lwz r7,20(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addi r28,r30,1
	ctx.r28.s64 = ctx.r30.s64 + 1;
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lis r5,-30680
	ctx.r5.s64 = -2010644480;
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r8,r5,-17064
	ctx.r8.s64 = ctx.r5.s64 + -17064;
	// lwz r5,28(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r7,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r7.u32);
	// lis r24,-30667
	ctx.r24.s64 = -2009792512;
	// lwz r10,16(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// add r4,r11,r9
	ctx.r4.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lis r25,-30667
	ctx.r25.s64 = -2009792512;
	// rlwinm r11,r4,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// add r30,r11,r8
	ctx.r30.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lis r19,-30667
	ctx.r19.s64 = -2009792512;
	// lis r22,-30667
	ctx.r22.s64 = -2009792512;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// mullw r11,r11,r5
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r5.s32);
	// lwz r7,12(r6)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// add r27,r11,r7
	ctx.r27.u64 = ctx.r11.u64 + ctx.r7.u64;
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// add r26,r10,r11
	ctx.r26.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r27,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r27.u32);
	// stw r26,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r26.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880E02D0;
	sub_880F52C8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x881534c8
	ctx.lr = 0x880E02DC;
	sub_881534C8(ctx, base);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// extsh r9,r3
	ctx.r9.s64 = ctx.r3.s16;
	// rlwinm r8,r10,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// li r3,16
	ctx.r3.s64 = 16;
	// subf r11,r8,r9
	ctx.r11.s64 = ctx.r9.s64 - ctx.r8.s64;
	// addi r23,r11,248
	ctx.r23.s64 = ctx.r11.s64 + 248;
	// bl 0x881534c8
	ctx.lr = 0x880E02F8;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r7,r11,72
	ctx.r7.s64 = ctx.r11.s64 + 72;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// rlwinm r4,r7,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// bl 0x880f5570
	ctx.lr = 0x880E0310;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x880e0338
	if (ctx.cr6.eq) goto loc_880E0338;
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// stw r18,172(r29)
	PPC_STORE_U32(ctx.r29.u32 + 172, ctx.r18.u32);
	// clrlwi r10,r11,16
	ctx.r10.u64 = ctx.r11.u32 & 0xFFFF;
	// stw r20,164(r29)
	PPC_STORE_U32(ctx.r29.u32 + 164, ctx.r20.u32);
	// stw r18,168(r29)
	PPC_STORE_U32(ctx.r29.u32 + 168, ctx.r18.u32);
	// stw r10,100(r29)
	PPC_STORE_U32(ctx.r29.u32 + 100, ctx.r10.u32);
	// lwz r9,44(r21)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r21.u32 + 44);
	// stw r9,144(r29)
	PPC_STORE_U32(ctx.r29.u32 + 144, ctx.r9.u32);
loc_880E0338:
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// addi r10,r11,453
	ctx.r10.s64 = ctx.r11.s64 + 453;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r21
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r21.u32);
	// cmpwi cr6,r8,1
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 1, ctx.xer);
	// bne cr6,0x880e0388
	if (!ctx.cr6.eq) goto loc_880E0388;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,0(r21)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r21.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r8,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r4,12(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// add r11,r11,r21
	ctx.r11.u64 = ctx.r11.u64 + ctx.r21.u64;
	// lwz r8,9076(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 9076);
	// lwz r7,9072(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 9072);
	// lwz r6,9068(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 9068);
	// lwz r5,9064(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 9064);
	// bl 0x880f5438
	ctx.lr = 0x880E0388;
	sub_880F5438(ctx, base);
loc_880E0388:
	// stw r27,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r27.u32);
	// li r11,24
	ctx.r11.s64 = 24;
	// stw r26,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r26.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,12380(r22)
	PPC_STORE_U32(ctx.r22.u32 + 12380, ctx.r11.u32);
	// bl 0x880f34b0
	ctx.lr = 0x880E03A4;
	sub_880F34B0(ctx, base);
	// lis r30,-30671
	ctx.r30.s64 = -2010054656;
	// lis r11,16838
	ctx.r11.s64 = 1103495168;
	// lis r10,-1009
	ctx.r10.s64 = -66125824;
	// ori r29,r11,20077
	ctx.r29.u64 = ctx.r11.u64 | 20077;
	// ori r27,r10,49405
	ctx.r27.u64 = ctx.r10.u64 | 49405;
	// lwz r11,4200(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4200);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// mullw r11,r11,r29
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r29.s32);
	// addi r26,r11,12345
	ctx.r26.s64 = ctx.r11.s64 + 12345;
	// stw r26,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r26.u32);
	// beq cr6,0x880e03f8
	if (ctx.cr6.eq) goto loc_880E03F8;
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
loc_880E03F8:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x880f34b0
	ctx.lr = 0x880E0404;
	sub_880F34B0(ctx, base);
	// mullw r11,r26,r29
	ctx.r11.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r29.s32);
	// addi r26,r11,12345
	ctx.r26.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r26,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r26.u32);
	// beq cr6,0x880e0440
	if (ctx.cr6.eq) goto loc_880E0440;
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
loc_880E0440:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// stw r28,12376(r19)
	PPC_STORE_U32(ctx.r19.u32 + 12376, ctx.r28.u32);
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x880f34b0
	ctx.lr = 0x880E0450;
	sub_880F34B0(ctx, base);
	// mullw r11,r26,r29
	ctx.r11.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r29.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r11,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r11.u32);
	// beq cr6,0x880e048c
	if (ctx.cr6.eq) goto loc_880E048C;
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
loc_880E048C:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// cmplwi cr6,r11,17
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 17, ctx.xer);
	// blt cr6,0x880e01e0
	if (ctx.cr6.lt) goto loc_880E01E0;
	// stw r18,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r18.u32);
	// mr r4,r16
	ctx.r4.u64 = ctx.r16.u64;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// bl 0x88096b40
	ctx.lr = 0x880E04B0;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071178
	__restgprlr_16(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E04BC"))) PPC_WEAK_FUNC(sub_880E04BC);
PPC_FUNC_IMPL(__imp__sub_880E04BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E04C0"))) PPC_WEAK_FUNC(sub_880E04C0);
PPC_FUNC_IMPL(__imp__sub_880E04C0) {
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
	// li r5,96
	ctx.r5.s64 = 96;
	// bl 0x88096bc8
	ctx.lr = 0x880E04EC;
	sub_88096BC8(ctx, base);
	// li r11,10
	ctx.r11.s64 = 10;
	// lis r10,-30706
	ctx.r10.s64 = -2012348416;
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r11.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r10,-3968
	ctx.r5.s64 = ctx.r10.s64 + -3968;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096c60
	ctx.lr = 0x880E0508;
	sub_88096C60(ctx, base);
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

__attribute__((alias("__imp__sub_880E0524"))) PPC_WEAK_FUNC(sub_880E0524);
PPC_FUNC_IMPL(__imp__sub_880E0524) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E0528"))) PPC_WEAK_FUNC(sub_880E0528);
PPC_FUNC_IMPL(__imp__sub_880E0528) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x880E0530;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880E0550;
	sub_88096BC8(ctx, base);
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mulli r10,r8,372
	ctx.r10.s64 = ctx.r8.s64 * 372;
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + ctx.r29.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// addi r6,r10,100
	ctx.r6.s64 = ctx.r10.s64 + 100;
	// blt cr6,0x880e06b8
	if (ctx.cr6.lt) goto loc_880E06B8;
	// beq cr6,0x880e05c8
	if (ctx.cr6.eq) goto loc_880E05C8;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x880e06e0
	if (!ctx.cr6.lt) goto loc_880E06E0;
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x880e06e0
	if (!ctx.cr0.lt) goto loc_880E06E0;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// lwz r10,104(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 104);
	// addic. r11,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r11.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,104(r6)
	PPC_STORE_U32(ctx.r6.u32 + 104, ctx.r11.u32);
	// bgt 0x880e06e0
	if (ctx.cr0.gt) goto loc_880E06E0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r5,104(r6)
	PPC_STORE_U32(ctx.r6.u32 + 104, ctx.r5.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x88096b40
	ctx.lr = 0x880E05B8;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r5,108(r6)
	PPC_STORE_U32(ctx.r6.u32 + 108, ctx.r5.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_880E05C8:
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r4,88(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 88);
	// li r3,256
	ctx.r3.s64 = 256;
	// bl 0x88153010
	ctx.lr = 0x880E05D8;
	sub_88153010(ctx, base);
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// li r9,7
	ctx.r9.s64 = 7;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,88(r6)
	PPC_STORE_U32(ctx.r6.u32 + 88, ctx.r11.u32);
	// li r7,15
	ctx.r7.s64 = 15;
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x880e060c
	if (!ctx.cr6.eq) goto loc_880E060C;
	// cmpwi cr6,r11,256
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 256, ctx.xer);
	// bne cr6,0x880e060c
	if (!ctx.cr6.eq) goto loc_880E060C;
	// stw r5,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r5.u32);
	// stw r7,104(r6)
	PPC_STORE_U32(ctx.r6.u32 + 104, ctx.r7.u32);
	// b 0x880e0614
	goto loc_880E0614;
loc_880E060C:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x880e0644
	if (!ctx.cr6.eq) goto loc_880E0644;
loc_880E0614:
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// bge 0x880e0644
	if (!ctx.cr0.lt) goto loc_880E0644;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// lwz r11,104(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 104);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,104(r6)
	PPC_STORE_U32(ctx.r6.u32 + 104, ctx.r11.u32);
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bge cr6,0x880e0644
	if (!ctx.cr6.lt) goto loc_880E0644;
	// stw r9,104(r6)
	PPC_STORE_U32(ctx.r6.u32 + 104, ctx.r9.u32);
loc_880E0644:
	// lwz r11,368(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 368);
	// addic. r11,r11,-3
	ctx.xer.ca = ctx.r11.u32 > 2;
	ctx.r11.s64 = ctx.r11.s64 + -3;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,368(r6)
	PPC_STORE_U32(ctx.r6.u32 + 368, ctx.r11.u32);
	// bgt 0x880e06e0
	if (ctx.cr0.gt) goto loc_880E06E0;
	// lwz r11,0(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x880e0664
	if (!ctx.cr6.eq) goto loc_880E0664;
	// stw r7,104(r6)
	PPC_STORE_U32(ctx.r6.u32 + 104, ctx.r7.u32);
loc_880E0664:
	// mulli r11,r8,84
	ctx.r11.s64 = ctx.r8.s64 * 84;
	// stw r5,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r5.u32);
	// stw r5,368(r6)
	PPC_STORE_U32(ctx.r6.u32 + 368, ctx.r5.u32);
	// stw r5,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r5.u32);
	// stw r9,48(r6)
	PPC_STORE_U32(ctx.r6.u32 + 48, ctx.r9.u32);
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// stw r8,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r8.u32);
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,-30706
	ctx.r9.s64 = -2012348416;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,1216
	ctx.r4.s64 = ctx.r9.s64 + 1216;
	// stw r10,7452(r11)
	PPC_STORE_U32(ctx.r11.u32 + 7452, ctx.r10.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x88096cb8
	ctx.lr = 0x880E06A0;
	sub_88096CB8(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r7,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_880E06B8:
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,5
	ctx.r10.s64 = 5;
	// li r9,128
	ctx.r9.s64 = 128;
	// stw r11,92(r6)
	PPC_STORE_U32(ctx.r6.u32 + 92, ctx.r11.u32);
	// stw r11,356(r6)
	PPC_STORE_U32(ctx.r6.u32 + 356, ctx.r11.u32);
	// stw r10,48(r6)
	PPC_STORE_U32(ctx.r6.u32 + 48, ctx.r10.u32);
	// stw r9,368(r6)
	PPC_STORE_U32(ctx.r6.u32 + 368, ctx.r9.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// stw r8,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
loc_880E06E0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E06EC"))) PPC_WEAK_FUNC(sub_880E06EC);
PPC_FUNC_IMPL(__imp__sub_880E06EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E06F0"))) PPC_WEAK_FUNC(sub_880E06F0);
PPC_FUNC_IMPL(__imp__sub_880E06F0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880E06F8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// li r5,96
	ctx.r5.s64 = 96;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880E0718;
	sub_88096BC8(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// stw r9,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r9.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// lwz r4,580(r29)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r29.u32 + 580);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x880e074c
	if (ctx.cr6.eq) goto loc_880E074C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096b40
	ctx.lr = 0x880E074C;
	sub_88096B40(ctx, base);
loc_880E074C:
	// lwz r11,4(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// lis r10,-30706
	ctx.r10.s64 = -2012348416;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mulli r11,r11,372
	ctx.r11.s64 = ctx.r11.s64 * 372;
	// add r9,r11,r29
	ctx.r9.u64 = ctx.r11.u64 + ctx.r29.u64;
	// addi r5,r10,-3840
	ctx.r5.s64 = ctx.r10.s64 + -3840;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r31,208(r9)
	PPC_STORE_U32(ctx.r9.u32 + 208, ctx.r31.u32);
	// bl 0x88096c60
	ctx.lr = 0x880E0770;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E077C"))) PPC_WEAK_FUNC(sub_880E077C);
PPC_FUNC_IMPL(__imp__sub_880E077C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E0780"))) PPC_WEAK_FUNC(sub_880E0780);
PPC_FUNC_IMPL(__imp__sub_880E0780) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880E0788;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// li r5,96
	ctx.r5.s64 = 96;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880E07A8;
	sub_88096BC8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// stw r9,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r9.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// lwz r4,208(r29)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r29.u32 + 208);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x880e07dc
	if (ctx.cr6.eq) goto loc_880E07DC;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096b40
	ctx.lr = 0x880E07DC;
	sub_88096B40(ctx, base);
loc_880E07DC:
	// lwz r11,4(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// lis r10,-30706
	ctx.r10.s64 = -2012348416;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mulli r11,r11,372
	ctx.r11.s64 = ctx.r11.s64 * 372;
	// add r9,r11,r29
	ctx.r9.u64 = ctx.r11.u64 + ctx.r29.u64;
	// addi r5,r10,-3840
	ctx.r5.s64 = ctx.r10.s64 + -3840;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r31,208(r9)
	PPC_STORE_U32(ctx.r9.u32 + 208, ctx.r31.u32);
	// bl 0x88096c60
	ctx.lr = 0x880E0800;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E080C"))) PPC_WEAK_FUNC(sub_880E080C);
PPC_FUNC_IMPL(__imp__sub_880E080C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E0810"))) PPC_WEAK_FUNC(sub_880E0810);
PPC_FUNC_IMPL(__imp__sub_880E0810) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x880E0818;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880E083C;
	sub_88096BC8(ctx, base);
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// lwz r10,88(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 88);
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r9,84(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 84);
	// lwz r8,88(r28)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r28.u32 + 88);
	// cmpw cr6,r9,r8
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, ctx.xer);
	// bge cr6,0x880e0880
	if (!ctx.cr6.lt) goto loc_880E0880;
	// lis r11,-30706
	ctx.r11.s64 = -2012348416;
	// addi r5,r11,-3472
	ctx.r5.s64 = ctx.r11.s64 + -3472;
	// bl 0x88096c60
	ctx.lr = 0x880E0874;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_880E0880:
	// lis r11,-30706
	ctx.r11.s64 = -2012348416;
	// addi r5,r11,-3288
	ctx.r5.s64 = ctx.r11.s64 + -3288;
	// bl 0x88096c60
	ctx.lr = 0x880E088C;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E0898"))) PPC_WEAK_FUNC(sub_880E0898);
PPC_FUNC_IMPL(__imp__sub_880E0898) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880E08A0;
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
	ctx.lr = 0x880E08C0;
	sub_88096BC8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r9,-30706
	ctx.r9.s64 = -2012348416;
	// stw r11,5812(r29)
	PPC_STORE_U32(ctx.r29.u32 + 5812, ctx.r11.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// addi r5,r9,-3104
	ctx.r5.s64 = ctx.r9.s64 + -3104;
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096c60
	ctx.lr = 0x880E08E8;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E08F4"))) PPC_WEAK_FUNC(sub_880E08F4);
PPC_FUNC_IMPL(__imp__sub_880E08F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E08F8"))) PPC_WEAK_FUNC(sub_880E08F8);
PPC_FUNC_IMPL(__imp__sub_880E08F8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880E0900;
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
	ctx.lr = 0x880E0920;
	sub_88096BC8(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r10,5812(r29)
	PPC_STORE_U32(ctx.r29.u32 + 5812, ctx.r10.u32);
	// lis r9,-30706
	ctx.r9.s64 = -2012348416;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// addi r5,r9,-2936
	ctx.r5.s64 = ctx.r9.s64 + -2936;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096c60
	ctx.lr = 0x880E0948;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E0954"))) PPC_WEAK_FUNC(sub_880E0954);
PPC_FUNC_IMPL(__imp__sub_880E0954) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E0958"))) PPC_WEAK_FUNC(sub_880E0958);
PPC_FUNC_IMPL(__imp__sub_880E0958) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880E0960;
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
	ctx.lr = 0x880E0980;
	sub_88096BC8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r11,r31,7472
	ctx.r11.s64 = ctx.r31.s64 + 7472;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r8,7536(r31)
	PPC_STORE_U32(ctx.r31.u32 + 7536, ctx.r8.u32);
	// lis r7,-30706
	ctx.r7.s64 = -2012348416;
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// addi r5,r7,-2352
	ctx.r5.s64 = ctx.r7.s64 + -2352;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096c60
	ctx.lr = 0x880E09B4;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E09C0"))) PPC_WEAK_FUNC(sub_880E09C0);
PPC_FUNC_IMPL(__imp__sub_880E09C0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880E09C8;
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
	ctx.lr = 0x880E09E8;
	sub_88096BC8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r11,r31,7388
	ctx.r11.s64 = ctx.r31.s64 + 7388;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r8,7452(r31)
	PPC_STORE_U32(ctx.r31.u32 + 7452, ctx.r8.u32);
	// lis r7,-30706
	ctx.r7.s64 = -2012348416;
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// addi r5,r7,-2352
	ctx.r5.s64 = ctx.r7.s64 + -2352;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096c60
	ctx.lr = 0x880E0A1C;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E0A28"))) PPC_WEAK_FUNC(sub_880E0A28);
PPC_FUNC_IMPL(__imp__sub_880E0A28) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880E0A30;
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
	ctx.lr = 0x880E0A50;
	sub_88096BC8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r10,r31,6968
	ctx.r10.s64 = ctx.r31.s64 + 6968;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lis r8,-30706
	ctx.r8.s64 = -2012348416;
	// stw r11,7032(r31)
	PPC_STORE_U32(ctx.r31.u32 + 7032, ctx.r11.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r11,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r11.u32);
	// addi r5,r8,-2168
	ctx.r5.s64 = ctx.r8.s64 + -2168;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096c60
	ctx.lr = 0x880E0A80;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E0A8C"))) PPC_WEAK_FUNC(sub_880E0A8C);
PPC_FUNC_IMPL(__imp__sub_880E0A8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E0A90"))) PPC_WEAK_FUNC(sub_880E0A90);
PPC_FUNC_IMPL(__imp__sub_880E0A90) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880E0A98;
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
	ctx.lr = 0x880E0AB8;
	sub_88096BC8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r10,r31,6884
	ctx.r10.s64 = ctx.r31.s64 + 6884;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lis r8,-30706
	ctx.r8.s64 = -2012348416;
	// stw r11,6948(r31)
	PPC_STORE_U32(ctx.r31.u32 + 6948, ctx.r11.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r11,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r11.u32);
	// addi r5,r8,-2168
	ctx.r5.s64 = ctx.r8.s64 + -2168;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096c60
	ctx.lr = 0x880E0AE8;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E0AF4"))) PPC_WEAK_FUNC(sub_880E0AF4);
PPC_FUNC_IMPL(__imp__sub_880E0AF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E0AF8"))) PPC_WEAK_FUNC(sub_880E0AF8);
PPC_FUNC_IMPL(__imp__sub_880E0AF8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880E0B00;
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
	ctx.lr = 0x880E0B20;
	sub_88096BC8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r11,r31,6968
	ctx.r11.s64 = ctx.r31.s64 + 6968;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r8,7032(r31)
	PPC_STORE_U32(ctx.r31.u32 + 7032, ctx.r8.u32);
	// lis r7,-30706
	ctx.r7.s64 = -2012348416;
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// addi r5,r7,-1968
	ctx.r5.s64 = ctx.r7.s64 + -1968;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096c60
	ctx.lr = 0x880E0B54;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E0B60"))) PPC_WEAK_FUNC(sub_880E0B60);
PPC_FUNC_IMPL(__imp__sub_880E0B60) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880E0B68;
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
	ctx.lr = 0x880E0B88;
	sub_88096BC8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r11,r31,6884
	ctx.r11.s64 = ctx.r31.s64 + 6884;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r8,6948(r31)
	PPC_STORE_U32(ctx.r31.u32 + 6948, ctx.r8.u32);
	// lis r7,-30706
	ctx.r7.s64 = -2012348416;
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// addi r5,r7,-1968
	ctx.r5.s64 = ctx.r7.s64 + -1968;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096c60
	ctx.lr = 0x880E0BBC;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E0BC8"))) PPC_WEAK_FUNC(sub_880E0BC8);
PPC_FUNC_IMPL(__imp__sub_880E0BC8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880E0BD0;
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
	ctx.lr = 0x880E0BF0;
	sub_88096BC8(ctx, base);
	// addi r11,r30,6800
	ctx.r11.s64 = ctx.r30.s64 + 6800;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// lwz r9,6848(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6848);
	// cmpwi cr6,r9,256
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 256, ctx.xer);
	// bne cr6,0x880e0c10
	if (!ctx.cr6.eq) goto loc_880E0C10;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
	// b 0x880e0c18
	goto loc_880E0C18;
loc_880E0C10:
	// li r9,3
	ctx.r9.s64 = 3;
	// stw r9,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r9.u32);
loc_880E0C18:
	// li r11,5
	ctx.r11.s64 = 5;
	// li r9,256
	ctx.r9.s64 = 256;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// lis r8,-30706
	ctx.r8.s64 = -2012348416;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r9,76(r30)
	PPC_STORE_U32(ctx.r30.u32 + 76, ctx.r9.u32);
	// addi r4,r8,2200
	ctx.r4.s64 = ctx.r8.s64 + 2200;
	// stw r10,80(r30)
	PPC_STORE_U32(ctx.r30.u32 + 80, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096cb8
	ctx.lr = 0x880E0C44;
	sub_88096CB8(ctx, base);
	// lis r7,-30706
	ctx.r7.s64 = -2012348416;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r5,r7,-1776
	ctx.r5.s64 = ctx.r7.s64 + -1776;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096c60
	ctx.lr = 0x880E0C58;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E0C64"))) PPC_WEAK_FUNC(sub_880E0C64);
PPC_FUNC_IMPL(__imp__sub_880E0C64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E0C68"))) PPC_WEAK_FUNC(sub_880E0C68);
PPC_FUNC_IMPL(__imp__sub_880E0C68) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880E0C70;
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
	ctx.lr = 0x880E0C90;
	sub_88096BC8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r11,r31,6800
	ctx.r11.s64 = ctx.r31.s64 + 6800;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r8,6864(r31)
	PPC_STORE_U32(ctx.r31.u32 + 6864, ctx.r8.u32);
	// lis r7,-30706
	ctx.r7.s64 = -2012348416;
	// stw r10,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r7,2296
	ctx.r4.s64 = ctx.r7.s64 + 2296;
	// bl 0x88096cb8
	ctx.lr = 0x880E0CC4;
	sub_88096CB8(ctx, base);
	// lis r6,-30706
	ctx.r6.s64 = -2012348416;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r5,r6,-1544
	ctx.r5.s64 = ctx.r6.s64 + -1544;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096c60
	ctx.lr = 0x880E0CD8;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E0CE4"))) PPC_WEAK_FUNC(sub_880E0CE4);
PPC_FUNC_IMPL(__imp__sub_880E0CE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E0CE8"))) PPC_WEAK_FUNC(sub_880E0CE8);
PPC_FUNC_IMPL(__imp__sub_880E0CE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071120
	ctx.lr = 0x880E0CF0;
	__savegprlr_14(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30667
	ctx.r11.s64 = -2009792512;
	// stw r6,284(r1)
	PPC_STORE_U32(ctx.r1.u32 + 284, ctx.r6.u32);
	// lis r31,-30671
	ctx.r31.s64 = -2010054656;
	// lis r9,16838
	ctx.r9.s64 = 1103495168;
	// lis r8,14563
	ctx.r8.s64 = 954400768;
	// lis r7,-3856
	ctx.r7.s64 = -252706816;
	// stw r5,12376(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12376, ctx.r5.u32);
	// lis r11,-30680
	ctx.r11.s64 = -2010644480;
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// lwz r30,4200(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4200);
	// mr r22,r4
	ctx.r22.u64 = ctx.r4.u64;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// li r14,0
	ctx.r14.s64 = 0;
	// ori r29,r9,20077
	ctx.r29.u64 = ctx.r9.u64 | 20077;
	// ori r23,r8,36409
	ctx.r23.u64 = ctx.r8.u64 | 36409;
	// li r16,112
	ctx.r16.s64 = 112;
	// li r15,64
	ctx.r15.s64 = 64;
	// ori r24,r7,61681
	ctx.r24.u64 = ctx.r7.u64 | 61681;
	// lis r21,-30667
	ctx.r21.s64 = -2009792512;
	// lis r20,-30667
	ctx.r20.s64 = -2009792512;
	// lis r18,-30667
	ctx.r18.s64 = -2009792512;
	// addi r17,r11,-19648
	ctx.r17.s64 = ctx.r11.s64 + -19648;
	// addi r19,r10,9552
	ctx.r19.s64 = ctx.r10.s64 + 9552;
	// b 0x880e0d60
	goto loc_880E0D60;
loc_880E0D5C:
	// lwz r27,284(r1)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 284);
loc_880E0D60:
	// lwz r10,8(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8);
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// lwz r8,12(r28)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// lwz r9,4(r22)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r22.u32 + 4);
	// add r26,r10,r11
	ctx.r26.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// add r25,r8,r9
	ctx.r25.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stw r26,12364(r20)
	PPC_STORE_U32(ctx.r20.u32 + 12364, ctx.r26.u32);
	// stw r25,12372(r21)
	PPC_STORE_U32(ctx.r21.u32 + 12372, ctx.r25.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880E0D88;
	sub_880F52C8(ctx, base);
	// mullw r10,r30,r29
	ctx.r10.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r29.s32);
	// lwz r11,20(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 20);
	// addi r10,r10,12345
	ctx.r10.s64 = ctx.r10.s64 + 12345;
	// cmpwi cr6,r11,32
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 32, ctx.xer);
	// stw r10,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r10.u32);
	// lhz r7,4200(r31)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// mulhwu r6,r7,r23
	ctx.r6.u64 = (uint64_t(ctx.r7.u32) * uint64_t(ctx.r23.u32)) >> 32;
	// ble cr6,0x880e0dcc
	if (!ctx.cr6.gt) goto loc_880E0DCC;
	// rlwinm r8,r11,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r11,r6,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r5,r11,r9
	ctx.r5.u64 = ctx.r11.u64 + ctx.r9.u64;
	// subf r11,r5,r7
	ctx.r11.s64 = ctx.r7.s64 - ctx.r5.s64;
	// extsh r7,r11
	ctx.r7.s64 = ctx.r11.s16;
	// subf r11,r7,r8
	ctx.r11.s64 = ctx.r8.s64 - ctx.r7.s64;
	// addi r11,r11,-8
	ctx.r11.s64 = ctx.r11.s64 + -8;
	// b 0x880e0dec
	goto loc_880E0DEC;
loc_880E0DCC:
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// rlwinm r11,r6,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r8,r9,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r5,r11,r9
	ctx.r5.u64 = ctx.r11.u64 + ctx.r9.u64;
	// subf r11,r5,r7
	ctx.r11.s64 = ctx.r7.s64 - ctx.r5.s64;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
loc_880E0DEC:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880e0e50
	if (ctx.cr6.eq) goto loc_880E0E50;
	// lwz r9,16(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// clrlwi r7,r11,23
	ctx.r7.u64 = ctx.r11.u32 & 0x1FF;
	// stw r11,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, ctx.r11.u32);
	// addi r6,r3,36
	ctx.r6.s64 = ctx.r3.s64 + 36;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r9,r8
	ctx.r11.u64 = ctx.r9.u64 + ctx.r8.u64;
	// srawi r9,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 1;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// addic. r11,r3,40
	ctx.xer.ca = ctx.r3.u32 > 4294967255;
	ctx.r11.s64 = ctx.r3.s64 + 40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r8,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, ctx.r8.u32);
	// rotlwi r9,r8,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// beq 0x880e0e38
	if (ctx.cr0.eq) goto loc_880E0E38;
	// addi r8,r7,128
	ctx.r8.s64 = ctx.r7.s64 + 128;
	// rlwinm r5,r8,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x7FC;
	// lwzx r8,r5,r19
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r19.u32);
	// mullw r5,r8,r9
	ctx.r5.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// stw r5,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r5.u32);
loc_880E0E38:
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x880e0e50
	if (ctx.cr6.eq) goto loc_880E0E50;
	// rlwinm r11,r7,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r11,r19
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r19.u32);
	// mullw r7,r8,r9
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// stw r7,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r7.u32);
loc_880E0E50:
	// cmpwi cr6,r14,1
	ctx.cr6.compare<int32_t>(ctx.r14.s32, 1, ctx.xer);
	// ble cr6,0x880e0e80
	if (!ctx.cr6.gt) goto loc_880E0E80;
	// mullw r11,r10,r29
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r29.s32);
	// addi r10,r11,12345
	ctx.r10.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r10,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r10.u32);
	// beq cr6,0x880e0e90
	if (ctx.cr6.eq) goto loc_880E0E90;
	// lhz r11,4200(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// lwz r9,24(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 24);
	// rlwinm r11,r11,1,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x2;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stw r11,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r11.u32);
loc_880E0E80:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880e0e90
	if (ctx.cr6.eq) goto loc_880E0E90;
	// stw r27,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r27.u32);
	// stw r16,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r16.u32);
loc_880E0E90:
	// mullw r11,r10,r29
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r29.s32);
	// addi r30,r11,12345
	ctx.r30.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r30,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r30.u32);
	// beq cr6,0x880e0eb4
	if (ctx.cr6.eq) goto loc_880E0EB4;
	// lhz r11,4200(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// rlwinm r11,r11,2,28,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xC;
	// lwzx r10,r11,r17
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r17.u32);
	// stw r10,148(r3)
	PPC_STORE_U32(ctx.r3.u32 + 148, ctx.r10.u32);
loc_880E0EB4:
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// li r9,13
	ctx.r9.s64 = 13;
	// lwz r10,4(r22)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r22.u32 + 4);
	// li r3,13
	ctx.r3.s64 = 13;
	// stw r9,12380(r18)
	PPC_STORE_U32(ctx.r18.u32 + 12380, ctx.r9.u32);
	// stw r11,12364(r20)
	PPC_STORE_U32(ctx.r20.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r21)
	PPC_STORE_U32(ctx.r21.u32 + 12372, ctx.r10.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880E0ED4;
	sub_880F52C8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880e0ee0
	if (ctx.cr6.eq) goto loc_880E0EE0;
	// stw r27,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r27.u32);
loc_880E0EE0:
	// mullw r11,r30,r29
	ctx.r11.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r29.s32);
	// addi r8,r11,12345
	ctx.r8.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r8,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r8.u32);
	// beq cr6,0x880e0f3c
	if (ctx.cr6.eq) goto loc_880E0F3C;
	// lhz r11,4200(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// addic. r10,r3,40
	ctx.xer.ca = ctx.r3.u32 > 4294967255;
	ctx.r10.s64 = ctx.r3.s64 + 40;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r15,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, ctx.r15.u32);
	// addi r9,r3,36
	ctx.r9.s64 = ctx.r3.s64 + 36;
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// stw r11,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, ctx.r11.u32);
	// beq 0x880e0f24
	if (ctx.cr0.eq) goto loc_880E0F24;
	// addi r7,r11,128
	ctx.r7.s64 = ctx.r11.s64 + 128;
	// rlwinm r6,r7,2,21,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x7FC;
	// lwzx r5,r6,r19
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r19.u32);
	// rlwinm r7,r5,6,0,25
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 6) & 0xFFFFFFC0;
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
loc_880E0F24:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x880e0f3c
	if (ctx.cr6.eq) goto loc_880E0F3C;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r19
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r19.u32);
	// rlwinm r7,r10,6,0,25
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// stw r7,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r7.u32);
loc_880E0F3C:
	// mullw r11,r8,r29
	ctx.r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r29.s32);
	// addi r9,r11,12345
	ctx.r9.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r9,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r9.u32);
	// beq cr6,0x880e0f70
	if (ctx.cr6.eq) goto loc_880E0F70;
	// lhz r11,4200(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// lwz r10,24(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 24);
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// stw r16,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r16.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r10,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r10.u32);
loc_880E0F70:
	// mullw r11,r9,r29
	ctx.r11.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r29.s32);
	// addi r30,r11,12345
	ctx.r30.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r30,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r30.u32);
	// beq cr6,0x880e0f94
	if (ctx.cr6.eq) goto loc_880E0F94;
	// lhz r11,4200(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// rlwinm r11,r11,2,28,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xC;
	// lwzx r10,r11,r17
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r17.u32);
	// stw r10,148(r3)
	PPC_STORE_U32(ctx.r3.u32 + 148, ctx.r10.u32);
loc_880E0F94:
	// lwz r11,32(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 32);
	// li r27,0
	ctx.r27.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x880e1020
	if (!ctx.cr6.gt) goto loc_880E1020;
	// stw r26,12364(r20)
	PPC_STORE_U32(ctx.r20.u32 + 12364, ctx.r26.u32);
	// stw r25,12372(r21)
	PPC_STORE_U32(ctx.r21.u32 + 12372, ctx.r25.u32);
loc_880E0FAC:
	// lwz r3,28(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 28);
	// stw r3,12380(r18)
	PPC_STORE_U32(ctx.r18.u32 + 12380, ctx.r3.u32);
	// bl 0x880f34b0
	ctx.lr = 0x880E0FB8;
	sub_880F34B0(ctx, base);
	// mullw r10,r30,r29
	ctx.r10.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r29.s32);
	// lwz r11,20(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 20);
	// addi r30,r10,12345
	ctx.r30.s64 = ctx.r10.s64 + 12345;
	// cmpwi cr6,r11,32
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 32, ctx.xer);
	// stw r30,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r30.u32);
	// ble cr6,0x880e0fe0
	if (!ctx.cr6.gt) goto loc_880E0FE0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880e1010
	if (ctx.cr6.eq) goto loc_880E1010;
	// addi r10,r11,11
	ctx.r10.s64 = ctx.r11.s64 + 11;
	// b 0x880e0fec
	goto loc_880E0FEC;
loc_880E0FE0:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880e1010
	if (ctx.cr6.eq) goto loc_880E1010;
	// addi r10,r11,-9
	ctx.r10.s64 = ctx.r11.s64 + -9;
loc_880E0FEC:
	// lhz r8,4200(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// mulhwu r7,r8,r24
	ctx.r7.u64 = (uint64_t(ctx.r8.u32) * uint64_t(ctx.r24.u32)) >> 32;
	// rlwinm r11,r7,28,4,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 28) & 0xFFFFFFF;
	// rlwinm r9,r11,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r6,r9,r11
	ctx.r6.u64 = ctx.r9.u64 + ctx.r11.u64;
	// subf r11,r6,r8
	ctx.r11.s64 = ctx.r8.s64 - ctx.r6.s64;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// sth r5,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, ctx.r5.u16);
loc_880E1010:
	// lwz r11,32(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 32);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// cmpw cr6,r27,r11
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x880e0fac
	if (ctx.cr6.lt) goto loc_880E0FAC;
loc_880E1020:
	// addi r14,r14,1
	ctx.r14.s64 = ctx.r14.s64 + 1;
	// addi r28,r28,36
	ctx.r28.s64 = ctx.r28.s64 + 36;
	// cmpwi cr6,r14,5
	ctx.cr6.compare<int32_t>(ctx.r14.s32, 5, ctx.xer);
	// blt cr6,0x880e0d5c
	if (ctx.cr6.lt) goto loc_880E0D5C;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E1038"))) PPC_WEAK_FUNC(sub_880E1038);
PPC_FUNC_IMPL(__imp__sub_880E1038) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071120
	ctx.lr = 0x880E1040;
	__savegprlr_14(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30667
	ctx.r11.s64 = -2009792512;
	// lis r30,-30671
	ctx.r30.s64 = -2010054656;
	// lis r9,16838
	ctx.r9.s64 = 1103495168;
	// lis r8,-3856
	ctx.r8.s64 = -252706816;
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// stw r5,12376(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12376, ctx.r5.u32);
	// lis r11,-30680
	ctx.r11.s64 = -2010644480;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// lwz r28,4200(r30)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4200);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r14,r6
	ctx.r14.u64 = ctx.r6.u64;
	// li r15,0
	ctx.r15.s64 = 0;
	// ori r27,r9,20077
	ctx.r27.u64 = ctx.r9.u64 | 20077;
	// ori r21,r8,61681
	ctx.r21.u64 = ctx.r8.u64 | 61681;
	// li r17,112
	ctx.r17.s64 = 112;
	// li r16,64
	ctx.r16.s64 = 64;
	// lis r23,-30667
	ctx.r23.s64 = -2009792512;
	// lis r22,-30667
	ctx.r22.s64 = -2009792512;
	// lis r20,-30667
	ctx.r20.s64 = -2009792512;
	// addi r18,r11,-19648
	ctx.r18.s64 = ctx.r11.s64 + -19648;
	// addi r19,r10,9552
	ctx.r19.s64 = ctx.r10.s64 + 9552;
loc_880E109C:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r9,4(r26)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// add r25,r10,r11
	ctx.r25.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// add r24,r8,r9
	ctx.r24.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stw r25,12364(r22)
	PPC_STORE_U32(ctx.r22.u32 + 12364, ctx.r25.u32);
	// stw r24,12372(r23)
	PPC_STORE_U32(ctx.r23.u32 + 12372, ctx.r24.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880E10C4;
	sub_880F52C8(ctx, base);
	// mullw r11,r28,r27
	ctx.r11.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r27.s32);
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addi r8,r11,12345
	ctx.r8.s64 = ctx.r11.s64 + 12345;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r8,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r8.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// lhz r7,4200(r30)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4200);
	// mulhwu r6,r7,r21
	ctx.r6.u64 = (uint64_t(ctx.r7.u32) * uint64_t(ctx.r21.u32)) >> 32;
	// rlwinm r11,r6,28,4,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 28) & 0xFFFFFFF;
	// rlwinm r9,r10,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r11,r5,r7
	ctx.r11.s64 = ctx.r7.s64 - ctx.r5.s64;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// beq cr6,0x880e1150
	if (ctx.cr6.eq) goto loc_880E1150;
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addic. r10,r3,40
	ctx.xer.ca = ctx.r3.u32 > 4294967255;
	ctx.r10.s64 = ctx.r3.s64 + 40;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, ctx.r11.u32);
	// addi r7,r3,36
	ctx.r7.s64 = ctx.r3.s64 + 36;
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// stw r9,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, ctx.r9.u32);
	// rotlwi r9,r9,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// beq 0x880e1138
	if (ctx.cr0.eq) goto loc_880E1138;
	// addi r6,r11,128
	ctx.r6.s64 = ctx.r11.s64 + 128;
	// rlwinm r5,r6,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// lwzx r6,r5,r19
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r19.u32);
	// mullw r5,r6,r9
	ctx.r5.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r9.s32);
	// stw r5,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r5.u32);
loc_880E1138:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x880e1150
	if (ctx.cr6.eq) goto loc_880E1150;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r19
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r19.u32);
	// mullw r9,r10,r9
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// stw r9,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r9.u32);
loc_880E1150:
	// cmpwi cr6,r15,0
	ctx.cr6.compare<int32_t>(ctx.r15.s32, 0, ctx.xer);
	// ble cr6,0x880e1180
	if (!ctx.cr6.gt) goto loc_880E1180;
	// mullw r11,r8,r27
	ctx.r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r27.s32);
	// addi r8,r11,12345
	ctx.r8.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r8,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r8.u32);
	// beq cr6,0x880e1190
	if (ctx.cr6.eq) goto loc_880E1190;
	// lhz r11,4200(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4200);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// rlwinm r11,r11,1,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x2;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r11,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r11.u32);
loc_880E1180:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880e1190
	if (ctx.cr6.eq) goto loc_880E1190;
	// stw r14,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r14.u32);
	// stw r17,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r17.u32);
loc_880E1190:
	// mullw r11,r8,r27
	ctx.r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r27.s32);
	// addi r29,r11,12345
	ctx.r29.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r29,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r29.u32);
	// beq cr6,0x880e11b4
	if (ctx.cr6.eq) goto loc_880E11B4;
	// lhz r11,4200(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4200);
	// rlwinm r11,r11,2,28,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xC;
	// lwzx r10,r11,r18
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r18.u32);
	// stw r10,148(r3)
	PPC_STORE_U32(ctx.r3.u32 + 148, ctx.r10.u32);
loc_880E11B4:
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// li r9,13
	ctx.r9.s64 = 13;
	// lwz r10,4(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// li r3,13
	ctx.r3.s64 = 13;
	// stw r9,12380(r20)
	PPC_STORE_U32(ctx.r20.u32 + 12380, ctx.r9.u32);
	// stw r11,12364(r22)
	PPC_STORE_U32(ctx.r22.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r23)
	PPC_STORE_U32(ctx.r23.u32 + 12372, ctx.r10.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880E11D4;
	sub_880F52C8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880e11e0
	if (ctx.cr6.eq) goto loc_880E11E0;
	// stw r14,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r14.u32);
loc_880E11E0:
	// mullw r11,r29,r27
	ctx.r11.s64 = int64_t(ctx.r29.s32) * int64_t(ctx.r27.s32);
	// addi r8,r11,12345
	ctx.r8.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r8,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r8.u32);
	// beq cr6,0x880e123c
	if (ctx.cr6.eq) goto loc_880E123C;
	// lhz r11,4200(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4200);
	// addic. r10,r3,40
	ctx.xer.ca = ctx.r3.u32 > 4294967255;
	ctx.r10.s64 = ctx.r3.s64 + 40;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r16,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, ctx.r16.u32);
	// addi r9,r3,36
	ctx.r9.s64 = ctx.r3.s64 + 36;
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// stw r11,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, ctx.r11.u32);
	// beq 0x880e1224
	if (ctx.cr0.eq) goto loc_880E1224;
	// addi r7,r11,128
	ctx.r7.s64 = ctx.r11.s64 + 128;
	// rlwinm r6,r7,2,21,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x7FC;
	// lwzx r5,r6,r19
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r19.u32);
	// rlwinm r7,r5,6,0,25
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 6) & 0xFFFFFFC0;
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
loc_880E1224:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x880e123c
	if (ctx.cr6.eq) goto loc_880E123C;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r19
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r19.u32);
	// rlwinm r7,r10,6,0,25
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// stw r7,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r7.u32);
loc_880E123C:
	// mullw r11,r8,r27
	ctx.r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r27.s32);
	// addi r9,r11,12345
	ctx.r9.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r9,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r9.u32);
	// beq cr6,0x880e1270
	if (ctx.cr6.eq) goto loc_880E1270;
	// lhz r11,4200(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4200);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// stw r17,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r17.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r10,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r10.u32);
loc_880E1270:
	// mullw r11,r9,r27
	ctx.r11.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r27.s32);
	// addi r28,r11,12345
	ctx.r28.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r28,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r28.u32);
	// beq cr6,0x880e1294
	if (ctx.cr6.eq) goto loc_880E1294;
	// lhz r11,4200(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4200);
	// rlwinm r11,r11,2,28,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xC;
	// lwzx r10,r11,r18
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r18.u32);
	// stw r10,148(r3)
	PPC_STORE_U32(ctx.r3.u32 + 148, ctx.r10.u32);
loc_880E1294:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x880e12c8
	if (!ctx.cr6.gt) goto loc_880E12C8;
	// stw r25,12364(r22)
	PPC_STORE_U32(ctx.r22.u32 + 12364, ctx.r25.u32);
	// stw r24,12372(r23)
	PPC_STORE_U32(ctx.r23.u32 + 12372, ctx.r24.u32);
loc_880E12AC:
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// stw r3,12380(r20)
	PPC_STORE_U32(ctx.r20.u32 + 12380, ctx.r3.u32);
	// bl 0x880f34b0
	ctx.lr = 0x880E12B8;
	sub_880F34B0(ctx, base);
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmpw cr6,r29,r11
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x880e12ac
	if (ctx.cr6.lt) goto loc_880E12AC;
loc_880E12C8:
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// addi r31,r31,36
	ctx.r31.s64 = ctx.r31.s64 + 36;
	// cmpwi cr6,r15,4
	ctx.cr6.compare<int32_t>(ctx.r15.s32, 4, ctx.xer);
	// blt cr6,0x880e109c
	if (ctx.cr6.lt) goto loc_880E109C;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E12E0"))) PPC_WEAK_FUNC(sub_880E12E0);
PPC_FUNC_IMPL(__imp__sub_880E12E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071120
	ctx.lr = 0x880E12E8;
	__savegprlr_14(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30680
	ctx.r11.s64 = -2010644480;
	// stw r5,292(r1)
	PPC_STORE_U32(ctx.r1.u32 + 292, ctx.r5.u32);
	// li r10,29
	ctx.r10.s64 = 29;
	// stw r6,300(r1)
	PPC_STORE_U32(ctx.r1.u32 + 300, ctx.r6.u32);
	// addi r11,r11,-19056
	ctx.r11.s64 = ctx.r11.s64 + -19056;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// lis r10,16838
	ctx.r10.s64 = 1103495168;
	// addi r29,r11,24
	ctx.r29.s64 = ctx.r11.s64 + 24;
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// lis r9,-3856
	ctx.r9.s64 = -252706816;
	// lis r27,-30667
	ctx.r27.s64 = -2009792512;
	// lis r8,15887
	ctx.r8.s64 = 1041170432;
	// lis r7,21399
	ctx.r7.s64 = 1402404864;
	// stw r27,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r27.u32);
	// lis r6,-1009
	ctx.r6.s64 = -66125824;
	// lis r5,14563
	ctx.r5.s64 = 954400768;
	// addi r28,r11,9552
	ctx.r28.s64 = ctx.r11.s64 + 9552;
	// mr r21,r3
	ctx.r21.u64 = ctx.r3.u64;
	// mr r20,r4
	ctx.r20.u64 = ctx.r4.u64;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// ori r30,r10,20077
	ctx.r30.u64 = ctx.r10.u64 | 20077;
	// ori r24,r9,61681
	ctx.r24.u64 = ctx.r9.u64 | 61681;
	// lis r31,-30671
	ctx.r31.s64 = -2010054656;
	// li r15,6
	ctx.r15.s64 = 6;
	// ori r22,r8,33761
	ctx.r22.u64 = ctx.r8.u64 | 33761;
	// ori r23,r7,33437
	ctx.r23.u64 = ctx.r7.u64 | 33437;
	// ori r16,r6,49405
	ctx.r16.u64 = ctx.r6.u64 | 49405;
	// lis r19,-30667
	ctx.r19.s64 = -2009792512;
	// ori r17,r5,36409
	ctx.r17.u64 = ctx.r5.u64 | 36409;
	// lis r18,-30667
	ctx.r18.s64 = -2009792512;
	// lis r14,-30667
	ctx.r14.s64 = -2009792512;
	// b 0x880e1374
	goto loc_880E1374;
loc_880E136C:
	// lwz r27,84(r1)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r28,80(r1)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_880E1374:
	// lwz r11,-12(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -12);
	// lwz r9,-16(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + -16);
	// lwz r10,0(r20)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// srawi r7,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r7.s64 = ctx.r11.s32 >> 16;
	// lwz r8,4(r20)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r20.u32 + 4);
	// add r26,r9,r10
	ctx.r26.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r6,292(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 292);
	// add r25,r11,r8
	ctx.r25.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lwz r3,-24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + -24);
	// stw r26,12364(r18)
	PPC_STORE_U32(ctx.r18.u32 + 12364, ctx.r26.u32);
	// addze r5,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r5.s64 = temp.s64;
	// stw r25,12372(r19)
	PPC_STORE_U32(ctx.r19.u32 + 12372, ctx.r25.u32);
	// srawi r4,r5,6
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x3F) != 0);
	ctx.r4.s64 = ctx.r5.s32 >> 6;
	// addze r11,r4
	temp.s64 = ctx.r4.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r11.s64 = temp.s64;
	// add r4,r11,r6
	ctx.r4.u64 = ctx.r11.u64 + ctx.r6.u64;
	// bl 0x880f52c8
	ctx.lr = 0x880E13B4;
	sub_880F52C8(ctx, base);
	// lwz r11,4200(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4200);
	// lwz r10,-4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + -4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// mullw r11,r11,r30
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// addi r8,r11,12345
	ctx.r8.s64 = ctx.r11.s64 + 12345;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r8,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r8.u32);
	// lhz r7,4200(r31)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// mulhwu r6,r7,r24
	ctx.r6.u64 = (uint64_t(ctx.r7.u32) * uint64_t(ctx.r24.u32)) >> 32;
	// rlwinm r11,r6,28,4,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 28) & 0xFFFFFFF;
	// rlwinm r9,r10,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r11,r5,r7
	ctx.r11.s64 = ctx.r7.s64 - ctx.r5.s64;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// beq cr6,0x880e1444
	if (ctx.cr6.eq) goto loc_880E1444;
	// lwz r9,-8(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + -8);
	// addic. r10,r3,40
	ctx.xer.ca = ctx.r3.u32 > 4294967255;
	ctx.r10.s64 = ctx.r3.s64 + 40;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, ctx.r11.u32);
	// addi r7,r3,36
	ctx.r7.s64 = ctx.r3.s64 + 36;
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// stw r9,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, ctx.r9.u32);
	// rotlwi r9,r9,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// beq 0x880e142c
	if (ctx.cr0.eq) goto loc_880E142C;
	// addi r6,r11,128
	ctx.r6.s64 = ctx.r11.s64 + 128;
	// rlwinm r5,r6,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// lwzx r6,r5,r28
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r28.u32);
	// mullw r5,r6,r9
	ctx.r5.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r9.s32);
	// stw r5,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r5.u32);
loc_880E142C:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x880e1444
	if (ctx.cr6.eq) goto loc_880E1444;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r28
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r28.u32);
	// mullw r9,r10,r9
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// stw r9,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r9.u32);
loc_880E1444:
	// mullw r11,r8,r30
	ctx.r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r30.s32);
	// addi r28,r11,12345
	ctx.r28.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r28,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r28.u32);
	// beq cr6,0x880e147c
	if (ctx.cr6.eq) goto loc_880E147C;
	// lhz r11,4200(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// li r9,112
	ctx.r9.s64 = 112;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r8,300(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 300);
	// rlwinm r11,r11,1,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x2;
	// stw r9,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r9.u32);
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r7,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r7.u32);
	// stw r8,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r8.u32);
loc_880E147C:
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// li r9,13
	ctx.r9.s64 = 13;
	// lwz r10,4(r20)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r20.u32 + 4);
	// li r3,13
	ctx.r3.s64 = 13;
	// stw r9,12380(r14)
	PPC_STORE_U32(ctx.r14.u32 + 12380, ctx.r9.u32);
	// stw r4,12376(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12376, ctx.r4.u32);
	// stw r11,12364(r18)
	PPC_STORE_U32(ctx.r18.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r19)
	PPC_STORE_U32(ctx.r19.u32 + 12372, ctx.r10.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880E14A0;
	sub_880F52C8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880e14b0
	if (ctx.cr6.eq) goto loc_880E14B0;
	// lwz r11,300(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 300);
	// stw r11,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r11.u32);
loc_880E14B0:
	// mullw r11,r28,r30
	ctx.r11.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r30.s32);
	// addi r8,r11,12345
	ctx.r8.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r8,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r8.u32);
	// beq cr6,0x880e1514
	if (ctx.cr6.eq) goto loc_880E1514;
	// lhz r11,4200(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// li r9,64
	ctx.r9.s64 = 64;
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addic. r10,r3,40
	ctx.xer.ca = ctx.r3.u32 > 4294967255;
	ctx.r10.s64 = ctx.r3.s64 + 40;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// stw r9,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, ctx.r9.u32);
	// addi r9,r3,36
	ctx.r9.s64 = ctx.r3.s64 + 36;
	// stw r11,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, ctx.r11.u32);
	// beq 0x880e14fc
	if (ctx.cr0.eq) goto loc_880E14FC;
	// addi r6,r11,128
	ctx.r6.s64 = ctx.r11.s64 + 128;
	// rlwinm r5,r6,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// lwzx r6,r5,r7
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r7.u32);
	// rlwinm r5,r6,6,0,25
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 6) & 0xFFFFFFC0;
	// stw r5,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r5.u32);
loc_880E14FC:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x880e1514
	if (ctx.cr6.eq) goto loc_880E1514;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r7
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r7.u32);
	// rlwinm r7,r10,6,0,25
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// stw r7,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r7.u32);
loc_880E1514:
	// mullw r11,r8,r30
	ctx.r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r30.s32);
	// addi r27,r11,12345
	ctx.r27.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r27,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r27.u32);
	// beq cr6,0x880e154c
	if (ctx.cr6.eq) goto loc_880E154C;
	// lhz r11,4200(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// li r9,112
	ctx.r9.s64 = 112;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// stw r9,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r9.u32);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// rlwinm r11,r8,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r7,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r7.u32);
loc_880E154C:
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// li r28,0
	ctx.r28.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x880e1588
	if (!ctx.cr6.gt) goto loc_880E1588;
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r26,12364(r18)
	PPC_STORE_U32(ctx.r18.u32 + 12364, ctx.r26.u32);
	// stw r25,12372(r19)
	PPC_STORE_U32(ctx.r19.u32 + 12372, ctx.r25.u32);
	// stw r4,12376(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12376, ctx.r4.u32);
loc_880E156C:
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// stw r3,12380(r14)
	PPC_STORE_U32(ctx.r14.u32 + 12380, ctx.r3.u32);
	// bl 0x880f34b0
	ctx.lr = 0x880E1578;
	sub_880F34B0(ctx, base);
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// cmpw cr6,r28,r11
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x880e156c
	if (ctx.cr6.lt) goto loc_880E156C;
loc_880E1588:
	// mullw r11,r27,r30
	ctx.r11.s64 = int64_t(ctx.r27.s32) * int64_t(ctx.r30.s32);
	// lwz r10,-12(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + -12);
	// lwz r8,-16(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + -16);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// srawi r5,r10,16
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xFFFF) != 0);
	ctx.r5.s64 = ctx.r10.s32 >> 16;
	// mullw r9,r11,r30
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// stw r11,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r11.u32);
	// lhz r3,4200(r31)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// addi r11,r9,12345
	ctx.r11.s64 = ctx.r9.s64 + 12345;
	// mulhwu r9,r3,r24
	ctx.r9.u64 = (uint64_t(ctx.r3.u32) * uint64_t(ctx.r24.u32)) >> 32;
	// stw r11,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r11.u32);
	// rlwinm r10,r9,28,4,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 28) & 0xFFFFFFF;
	// lhz r28,4200(r31)
	ctx.r28.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// mulhwu r7,r28,r24
	ctx.r7.u64 = (uint64_t(ctx.r28.u32) * uint64_t(ctx.r24.u32)) >> 32;
	// rlwinm r9,r7,28,4,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 28) & 0xFFFFFFF;
	// rlwinm r7,r10,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r6,r9,4,0,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 + ctx.r10.u64;
	// add r9,r6,r9
	ctx.r9.u64 = ctx.r6.u64 + ctx.r9.u64;
	// subf r7,r10,r3
	ctx.r7.s64 = ctx.r3.s64 - ctx.r10.s64;
	// subf r6,r9,r28
	ctx.r6.s64 = ctx.r28.s64 - ctx.r9.s64;
	// extsh r10,r7
	ctx.r10.s64 = ctx.r7.s16;
	// extsh r9,r6
	ctx.r9.s64 = ctx.r6.s16;
	// addze r7,r5
	temp.s64 = ctx.r5.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r7.s64 = temp.s64;
	// addi r6,r10,-8
	ctx.r6.s64 = ctx.r10.s64 + -8;
	// addi r5,r9,64
	ctx.r5.s64 = ctx.r9.s64 + 64;
	// divw r10,r7,r15
	ctx.r10.s32 = ppc_divw(ctx.r7.s32, ctx.r15.s32);
	// rlwinm r9,r6,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r7,r5,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// addi r6,r10,16
	ctx.r6.s64 = ctx.r10.s64 + 16;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// add r10,r9,r26
	ctx.r10.u64 = ctx.r9.u64 + ctx.r26.u64;
	// add r5,r7,r25
	ctx.r5.u64 = ctx.r7.u64 + ctx.r25.u64;
	// bge cr6,0x880e1614
	if (!ctx.cr6.lt) goto loc_880E1614;
	// neg r8,r8
	ctx.r8.s64 = -ctx.r8.s64;
loc_880E1614:
	// mullw r11,r11,r30
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// srawi r9,r8,16
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFF) != 0);
	ctx.r9.s64 = ctx.r8.s32 >> 16;
	// lwz r8,0(r20)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// stw r11,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r11.u32);
	// mullw r11,r11,r30
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// li r7,12
	ctx.r7.s64 = 12;
	// addze r3,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r3.s64 = temp.s64;
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// divw r9,r3,r7
	ctx.r9.s32 = ppc_divw(ctx.r3.s32, ctx.r7.s32);
	// mullw r7,r11,r30
	ctx.r7.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// lhz r28,4200(r31)
	ctx.r28.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// stw r11,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r11.u32);
	// subf r9,r9,r6
	ctx.r9.s64 = ctx.r6.s64 - ctx.r9.s64;
	// addi r6,r4,-1
	ctx.r6.s64 = ctx.r4.s64 + -1;
	// addi r7,r7,12345
	ctx.r7.s64 = ctx.r7.s64 + 12345;
	// cmpw cr6,r8,r10
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r10.s32, ctx.xer);
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// lhz r10,4200(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// stw r7,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r7.u32);
	// ble cr6,0x880e16b0
	if (!ctx.cr6.gt) goto loc_880E16B0;
	// mulhwu r11,r28,r22
	ctx.r11.u64 = (uint64_t(ctx.r28.u32) * uint64_t(ctx.r22.u32)) >> 32;
	// rlwinm r11,r11,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// rlwinm r7,r11,5,0,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r8,r7,r11
	ctx.r8.u64 = ctx.r7.u64 + ctx.r11.u64;
	// mulhwu r7,r10,r23
	ctx.r7.u64 = (uint64_t(ctx.r10.u32) * uint64_t(ctx.r23.u32)) >> 32;
	// rlwinm r11,r7,28,4,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 28) & 0xFFFFFFF;
	// subf r8,r8,r28
	ctx.r8.s64 = ctx.r28.s64 - ctx.r8.s64;
	// mulli r7,r11,49
	ctx.r7.s64 = ctx.r11.s64 * 49;
	// lhz r11,4200(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// subf r10,r7,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r7.s64;
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// clrlwi r28,r11,31
	ctx.r28.u64 = ctx.r11.u32 & 0x1;
	// extsh r11,r7
	ctx.r11.s64 = ctx.r7.s16;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r7,r11,260
	ctx.r7.s64 = ctx.r11.s64 + 260;
	// addi r8,r9,56
	ctx.r8.s64 = ctx.r9.s64 + 56;
	// b 0x880e173c
	goto loc_880E173C;
loc_880E16B0:
	// bne cr6,0x880e16fc
	if (!ctx.cr6.eq) goto loc_880E16FC;
	// mulhwu r11,r28,r17
	ctx.r11.u64 = (uint64_t(ctx.r28.u32) * uint64_t(ctx.r17.u32)) >> 32;
	// rlwinm r8,r11,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r7,r8,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// mulhwu r7,r10,r16
	ctx.r7.u64 = (uint64_t(ctx.r10.u32) * uint64_t(ctx.r16.u32)) >> 32;
	// rlwinm r11,r7,26,6,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 26) & 0x3FFFFFF;
	// subf r27,r8,r28
	ctx.r27.s64 = ctx.r28.s64 - ctx.r8.s64;
	// lhz r8,4200(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// rlwinm r7,r11,6,0,25
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 6) & 0xFFFFFFC0;
	// clrlwi r28,r8,31
	ctx.r28.u64 = ctx.r8.u32 & 0x1;
	// add r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 + ctx.r11.u64;
	// extsh r8,r27
	ctx.r8.s64 = ctx.r27.s16;
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r11.s64;
	// addi r7,r8,252
	ctx.r7.s64 = ctx.r8.s64 + 252;
	// extsh r11,r10
	ctx.r11.s64 = ctx.r10.s16;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addi r8,r11,64
	ctx.r8.s64 = ctx.r11.s64 + 64;
	// b 0x880e173c
	goto loc_880E173C;
loc_880E16FC:
	// mulhwu r11,r28,r22
	ctx.r11.u64 = (uint64_t(ctx.r28.u32) * uint64_t(ctx.r22.u32)) >> 32;
	// rlwinm r11,r11,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// rlwinm r7,r11,5,0,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r8,r7,r11
	ctx.r8.u64 = ctx.r7.u64 + ctx.r11.u64;
	// mulhwu r7,r10,r23
	ctx.r7.u64 = (uint64_t(ctx.r10.u32) * uint64_t(ctx.r23.u32)) >> 32;
	// rlwinm r11,r7,28,4,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 28) & 0xFFFFFFF;
	// subf r8,r8,r28
	ctx.r8.s64 = ctx.r28.s64 - ctx.r8.s64;
	// mulli r7,r11,49
	ctx.r7.s64 = ctx.r11.s64 * 49;
	// lhz r11,4200(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// subf r10,r7,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r7.s64;
	// clrlwi r28,r11,31
	ctx.r28.u64 = ctx.r11.u32 & 0x1;
	// extsh r11,r10
	ctx.r11.s64 = ctx.r10.s16;
	// extsh r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// subfic r7,r8,252
	ctx.xer.ca = ctx.r8.u32 <= 252;
	ctx.r7.s64 = 252 - ctx.r8.s64;
	// addi r8,r11,56
	ctx.r8.s64 = ctx.r11.s64 + 56;
loc_880E173C:
	// addi r9,r28,13
	ctx.r9.s64 = ctx.r28.s64 + 13;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// bl 0x880dc910
	ctx.lr = 0x880E1748;
	sub_880DC910(ctx, base);
	// lwz r11,88(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// addi r29,r29,36
	ctx.r29.s64 = ctx.r29.s64 + 36;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// bne 0x880e136c
	if (!ctx.cr0.eq) goto loc_880E136C;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E1764"))) PPC_WEAK_FUNC(sub_880E1764);
PPC_FUNC_IMPL(__imp__sub_880E1764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E1768"))) PPC_WEAK_FUNC(sub_880E1768);
PPC_FUNC_IMPL(__imp__sub_880E1768) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071120
	ctx.lr = 0x880E1770;
	__savegprlr_14(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r18,r3
	ctx.r18.u64 = ctx.r3.u64;
	// stw r8,316(r1)
	PPC_STORE_U32(ctx.r1.u32 + 316, ctx.r8.u32);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r22,r6
	ctx.r22.u64 = ctx.r6.u64;
	// mr r17,r7
	ctx.r17.u64 = ctx.r7.u64;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// ble cr6,0x880e1c14
	if (!ctx.cr6.gt) goto loc_880E1C14;
	// lis r11,-30667
	ctx.r11.s64 = -2009792512;
	// stw r5,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// addi r19,r7,-1
	ctx.r19.s64 = ctx.r7.s64 + -1;
	// lis r10,16838
	ctx.r10.s64 = 1103495168;
	// lis r9,-3856
	ctx.r9.s64 = -252706816;
	// lis r8,15887
	ctx.r8.s64 = 1041170432;
	// stw r7,12376(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12376, ctx.r7.u32);
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// lis r7,21399
	ctx.r7.s64 = 1402404864;
	// lis r6,-30584
	ctx.r6.s64 = -2004353024;
	// lis r27,-30667
	ctx.r27.s64 = -2009792512;
	// lis r5,14563
	ctx.r5.s64 = 954400768;
	// addi r28,r11,9552
	ctx.r28.s64 = ctx.r11.s64 + 9552;
	// stw r27,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r27.u32);
	// lis r31,-30671
	ctx.r31.s64 = -2010054656;
	// ori r30,r10,20077
	ctx.r30.u64 = ctx.r10.u64 | 20077;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// ori r23,r9,61681
	ctx.r23.u64 = ctx.r9.u64 | 61681;
	// lis r16,-30667
	ctx.r16.s64 = -2009792512;
	// ori r20,r8,33761
	ctx.r20.u64 = ctx.r8.u64 | 33761;
	// lis r15,-30667
	ctx.r15.s64 = -2009792512;
	// ori r21,r7,33437
	ctx.r21.u64 = ctx.r7.u64 | 33437;
	// ori r26,r6,34953
	ctx.r26.u64 = ctx.r6.u64 | 34953;
	// ori r14,r5,36409
	ctx.r14.u64 = ctx.r5.u64 | 36409;
	// b 0x880e17fc
	goto loc_880E17FC;
loc_880E17F4:
	// lwz r27,84(r1)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r28,80(r1)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_880E17FC:
	// lwz r10,8(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// lwz r8,12(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// lwz r9,4(r22)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r22.u32 + 4);
	// add r25,r10,r11
	ctx.r25.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// add r24,r8,r9
	ctx.r24.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stw r25,12364(r15)
	PPC_STORE_U32(ctx.r15.u32 + 12364, ctx.r25.u32);
	// stw r24,12372(r16)
	PPC_STORE_U32(ctx.r16.u32 + 12372, ctx.r24.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880E1828;
	sub_880F52C8(ctx, base);
	// lwz r11,4200(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4200);
	// lwz r10,20(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// mullw r11,r11,r30
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// addi r8,r11,12345
	ctx.r8.s64 = ctx.r11.s64 + 12345;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r8,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r8.u32);
	// lhz r7,4200(r31)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// mulhwu r6,r7,r23
	ctx.r6.u64 = (uint64_t(ctx.r7.u32) * uint64_t(ctx.r23.u32)) >> 32;
	// rlwinm r11,r6,28,4,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 28) & 0xFFFFFFF;
	// rlwinm r9,r10,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r4,r5,r7
	ctx.r4.s64 = ctx.r7.s64 - ctx.r5.s64;
	// extsh r11,r4
	ctx.r11.s64 = ctx.r4.s16;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// beq cr6,0x880e18b8
	if (ctx.cr6.eq) goto loc_880E18B8;
	// lwz r9,16(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// addic. r10,r3,40
	ctx.xer.ca = ctx.r3.u32 > 4294967255;
	ctx.r10.s64 = ctx.r3.s64 + 40;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, ctx.r11.u32);
	// addi r7,r3,36
	ctx.r7.s64 = ctx.r3.s64 + 36;
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// stw r9,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, ctx.r9.u32);
	// rotlwi r9,r9,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// beq 0x880e18a0
	if (ctx.cr0.eq) goto loc_880E18A0;
	// addi r6,r11,128
	ctx.r6.s64 = ctx.r11.s64 + 128;
	// rlwinm r5,r6,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// lwzx r4,r5,r28
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r28.u32);
	// mullw r6,r4,r9
	ctx.r6.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r9.s32);
	// stw r6,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r6.u32);
loc_880E18A0:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x880e18b8
	if (ctx.cr6.eq) goto loc_880E18B8;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r28
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r28.u32);
	// mullw r9,r10,r9
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// stw r9,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r9.u32);
loc_880E18B8:
	// mullw r11,r8,r30
	ctx.r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r30.s32);
	// addi r28,r11,12345
	ctx.r28.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r28,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r28.u32);
	// beq cr6,0x880e18f0
	if (ctx.cr6.eq) goto loc_880E18F0;
	// lhz r11,4200(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// li r9,112
	ctx.r9.s64 = 112;
	// lwz r10,24(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// lwz r8,316(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 316);
	// rlwinm r11,r11,1,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x2;
	// stw r9,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r9.u32);
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r7,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r7.u32);
	// stw r8,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r8.u32);
loc_880E18F0:
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// li r9,13
	ctx.r9.s64 = 13;
	// lwz r10,4(r22)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r22.u32 + 4);
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
	// li r3,13
	ctx.r3.s64 = 13;
	// stw r9,12380(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12380, ctx.r9.u32);
	// stw r11,12364(r15)
	PPC_STORE_U32(ctx.r15.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r16)
	PPC_STORE_U32(ctx.r16.u32 + 12372, ctx.r10.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880E1914;
	sub_880F52C8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880e1924
	if (ctx.cr6.eq) goto loc_880E1924;
	// lwz r11,316(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 316);
	// stw r11,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r11.u32);
loc_880E1924:
	// mullw r11,r28,r30
	ctx.r11.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r30.s32);
	// addi r8,r11,12345
	ctx.r8.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r8,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r8.u32);
	// beq cr6,0x880e1988
	if (ctx.cr6.eq) goto loc_880E1988;
	// lhz r11,4200(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// li r9,64
	ctx.r9.s64 = 64;
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addic. r10,r3,40
	ctx.xer.ca = ctx.r3.u32 > 4294967255;
	ctx.r10.s64 = ctx.r3.s64 + 40;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// stw r9,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, ctx.r9.u32);
	// addi r9,r3,36
	ctx.r9.s64 = ctx.r3.s64 + 36;
	// stw r11,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, ctx.r11.u32);
	// beq 0x880e1970
	if (ctx.cr0.eq) goto loc_880E1970;
	// addi r6,r11,128
	ctx.r6.s64 = ctx.r11.s64 + 128;
	// rlwinm r5,r6,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// lwzx r4,r5,r7
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r7.u32);
	// rlwinm r6,r4,6,0,25
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 6) & 0xFFFFFFC0;
	// stw r6,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r6.u32);
loc_880E1970:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x880e1988
	if (ctx.cr6.eq) goto loc_880E1988;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r7
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r7.u32);
	// rlwinm r7,r10,6,0,25
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// stw r7,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r7.u32);
loc_880E1988:
	// mullw r11,r8,r30
	ctx.r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r30.s32);
	// addi r27,r11,12345
	ctx.r27.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r27,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r27.u32);
	// beq cr6,0x880e19c0
	if (ctx.cr6.eq) goto loc_880E19C0;
	// lhz r11,4200(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// li r9,112
	ctx.r9.s64 = 112;
	// lwz r10,24(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// stw r9,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r9.u32);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// rlwinm r11,r8,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r7,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r7.u32);
loc_880E19C0:
	// lwz r11,32(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 32);
	// li r28,0
	ctx.r28.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x880e19fc
	if (!ctx.cr6.gt) goto loc_880E19FC;
	// stw r25,12364(r15)
	PPC_STORE_U32(ctx.r15.u32 + 12364, ctx.r25.u32);
	// stw r24,12372(r16)
	PPC_STORE_U32(ctx.r16.u32 + 12372, ctx.r24.u32);
loc_880E19D8:
	// lwz r3,28(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 28);
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r3,12380(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12380, ctx.r3.u32);
	// bl 0x880f34b0
	ctx.lr = 0x880E19EC;
	sub_880F34B0(ctx, base);
	// lwz r10,32(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 32);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// cmpw cr6,r28,r10
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x880e19d8
	if (ctx.cr6.lt) goto loc_880E19D8;
loc_880E19FC:
	// mullw r11,r27,r30
	ctx.r11.s64 = int64_t(ctx.r27.s32) * int64_t(ctx.r30.s32);
	// lwz r10,12(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// lwz r8,0(r22)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// srawi r5,r10,16
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xFFFF) != 0);
	ctx.r5.s64 = ctx.r10.s32 >> 16;
	// mullw r9,r11,r30
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// stw r11,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r11.u32);
	// lhz r4,4200(r31)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// addi r11,r9,12345
	ctx.r11.s64 = ctx.r9.s64 + 12345;
	// stw r11,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r11.u32);
	// mulhwu r3,r4,r23
	ctx.r3.u64 = (uint64_t(ctx.r4.u32) * uint64_t(ctx.r23.u32)) >> 32;
	// rlwinm r10,r3,28,4,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 28) & 0xFFFFFFF;
	// lhz r28,4200(r31)
	ctx.r28.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// mulhwu r9,r28,r23
	ctx.r9.u64 = (uint64_t(ctx.r28.u32) * uint64_t(ctx.r23.u32)) >> 32;
	// rlwinm r7,r10,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r9,r9,28,4,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 28) & 0xFFFFFFF;
	// add r7,r7,r10
	ctx.r7.u64 = ctx.r7.u64 + ctx.r10.u64;
	// rlwinm r6,r9,4,0,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r4,r7,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r7.s64;
	// mullw r11,r11,r30
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// extsh r10,r4
	ctx.r10.s64 = ctx.r4.s16;
	// add r3,r6,r9
	ctx.r3.u64 = ctx.r6.u64 + ctx.r9.u64;
	// addi r6,r10,-8
	ctx.r6.s64 = ctx.r10.s64 + -8;
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// subf r9,r3,r28
	ctx.r9.s64 = ctx.r28.s64 - ctx.r3.s64;
	// rlwinm r10,r6,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// stw r11,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r11.u32);
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// mullw r11,r11,r30
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// add r4,r10,r25
	ctx.r4.u64 = ctx.r10.u64 + ctx.r25.u64;
	// addze r5,r5
	temp.s64 = ctx.r5.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r5.s64 = temp.s64;
	// addi r3,r9,32
	ctx.r3.s64 = ctx.r9.s64 + 32;
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// cmpw cr6,r8,r4
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r4.s32, ctx.xer);
	// srawi r10,r5,2
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r5.s32 >> 2;
	// rlwinm r9,r3,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 16) & 0xFFFF0000;
	// mullw r8,r11,r30
	ctx.r8.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// addze r10,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r10.s64 = temp.s64;
	// add r5,r9,r24
	ctx.r5.u64 = ctx.r9.u64 + ctx.r24.u64;
	// mr r6,r19
	ctx.r6.u64 = ctx.r19.u64;
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// ble cr6,0x880e1b14
	if (!ctx.cr6.gt) goto loc_880E1B14;
	// lhz r7,4200(r31)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// stw r11,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r11.u32);
	// lhz r9,4200(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// mulhwu r3,r7,r20
	ctx.r3.u64 = (uint64_t(ctx.r7.u32) * uint64_t(ctx.r20.u32)) >> 32;
	// stw r8,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r8.u32);
	// rlwinm r11,r3,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 29) & 0x1FFFFFFF;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// rlwinm r9,r11,5,0,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xFFFFFFE0;
	// mulhwu r28,r8,r21
	ctx.r28.u64 = (uint64_t(ctx.r8.u32) * uint64_t(ctx.r21.u32)) >> 32;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lhz r11,4200(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// rlwinm r28,r28,28,4,31
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 28) & 0xFFFFFFF;
	// subf r7,r9,r7
	ctx.r7.s64 = ctx.r7.s64 - ctx.r9.s64;
	// mulli r9,r28,49
	ctx.r9.s64 = ctx.r28.s64 * 49;
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
	// mulhwu r11,r11,r26
	ctx.r11.u64 = (uint64_t(ctx.r11.u32) * uint64_t(ctx.r26.u32)) >> 32;
	// subf r8,r9,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r9.s64;
	// rlwinm r9,r11,29,3,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// extsh r11,r8
	ctx.r11.s64 = ctx.r8.s16;
	// rlwinm r27,r9,4,0,27
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// subf r9,r9,r27
	ctx.r9.s64 = ctx.r27.s64 - ctx.r9.s64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// subf r7,r9,r28
	ctx.r7.s64 = ctx.r28.s64 - ctx.r9.s64;
	// extsh r10,r8
	ctx.r10.s64 = ctx.r8.s16;
	// extsh r9,r7
	ctx.r9.s64 = ctx.r7.s16;
	// addi r7,r10,260
	ctx.r7.s64 = ctx.r10.s64 + 260;
	// b 0x880e1bf4
	goto loc_880E1BF4;
loc_880E1B14:
	// bne cr6,0x880e1b8c
	if (!ctx.cr6.eq) goto loc_880E1B8C;
	// lhz r3,4200(r31)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// lis r9,-1009
	ctx.r9.s64 = -66125824;
	// stw r11,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r11.u32);
	// lhz r28,4200(r31)
	ctx.r28.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// mulhwu r11,r3,r14
	ctx.r11.u64 = (uint64_t(ctx.r3.u32) * uint64_t(ctx.r14.u32)) >> 32;
	// stw r8,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r8.u32);
	// rlwinm r11,r11,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// ori r7,r9,49405
	ctx.r7.u64 = ctx.r9.u64 | 49405;
	// rlwinm r8,r11,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// mulhwu r7,r28,r7
	ctx.r7.u64 = (uint64_t(ctx.r28.u32) * uint64_t(ctx.r7.u32)) >> 32;
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// rlwinm r9,r7,26,6,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 26) & 0x3FFFFFF;
	// subf r7,r8,r3
	ctx.r7.s64 = ctx.r3.s64 - ctx.r8.s64;
	// lhz r3,4200(r31)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// rlwinm r8,r9,6,0,25
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0xFFFFFFC0;
	// add r11,r8,r9
	ctx.r11.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mulhwu r9,r3,r26
	ctx.r9.u64 = (uint64_t(ctx.r3.u32) * uint64_t(ctx.r26.u32)) >> 32;
	// rlwinm r8,r9,29,3,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 29) & 0x1FFFFFFF;
	// subf r11,r11,r28
	ctx.r11.s64 = ctx.r28.s64 - ctx.r11.s64;
	// rlwinm r9,r8,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// subf r8,r9,r3
	ctx.r8.s64 = ctx.r3.s64 - ctx.r9.s64;
	// extsh r10,r7
	ctx.r10.s64 = ctx.r7.s16;
	// extsh r9,r8
	ctx.r9.s64 = ctx.r8.s16;
	// addi r8,r11,64
	ctx.r8.s64 = ctx.r11.s64 + 64;
	// addi r7,r10,252
	ctx.r7.s64 = ctx.r10.s64 + 252;
	// b 0x880e1bf8
	goto loc_880E1BF8;
loc_880E1B8C:
	// lhz r7,4200(r31)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// stw r11,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r11.u32);
	// lhz r9,4200(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// mulhwu r3,r7,r20
	ctx.r3.u64 = (uint64_t(ctx.r7.u32) * uint64_t(ctx.r20.u32)) >> 32;
	// stw r8,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r8.u32);
	// rlwinm r11,r3,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 29) & 0x1FFFFFFF;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// rlwinm r9,r11,5,0,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xFFFFFFE0;
	// mulhwu r28,r8,r21
	ctx.r28.u64 = (uint64_t(ctx.r8.u32) * uint64_t(ctx.r21.u32)) >> 32;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lhz r11,4200(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// rlwinm r28,r28,28,4,31
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 28) & 0xFFFFFFF;
	// subf r7,r9,r7
	ctx.r7.s64 = ctx.r7.s64 - ctx.r9.s64;
	// mulli r9,r28,49
	ctx.r9.s64 = ctx.r28.s64 * 49;
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
	// mulhwu r11,r11,r26
	ctx.r11.u64 = (uint64_t(ctx.r11.u32) * uint64_t(ctx.r26.u32)) >> 32;
	// subf r8,r9,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r9.s64;
	// rlwinm r9,r11,29,3,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// extsh r7,r7
	ctx.r7.s64 = ctx.r7.s16;
	// rlwinm r11,r9,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// subfic r7,r7,252
	ctx.xer.ca = ctx.r7.u32 <= 252;
	ctx.r7.s64 = 252 - ctx.r7.s64;
	// subf r9,r9,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r9.s64;
	// extsh r11,r8
	ctx.r11.s64 = ctx.r8.s16;
	// subf r8,r9,r28
	ctx.r8.s64 = ctx.r28.s64 - ctx.r9.s64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// extsh r9,r8
	ctx.r9.s64 = ctx.r8.s16;
loc_880E1BF4:
	// addi r8,r11,56
	ctx.r8.s64 = ctx.r11.s64 + 56;
loc_880E1BF8:
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// bl 0x880dc910
	ctx.lr = 0x880E1C00;
	sub_880DC910(ctx, base);
	// lwz r11,88(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// addi r29,r29,36
	ctx.r29.s64 = ctx.r29.s64 + 36;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// bne 0x880e17f4
	if (!ctx.cr0.eq) goto loc_880E17F4;
loc_880E1C14:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E1C1C"))) PPC_WEAK_FUNC(sub_880E1C1C);
PPC_FUNC_IMPL(__imp__sub_880E1C1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E1C20"))) PPC_WEAK_FUNC(sub_880E1C20);
PPC_FUNC_IMPL(__imp__sub_880E1C20) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x880E1C28;
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
	// li r5,60
	ctx.r5.s64 = 60;
	// bl 0x88096bc8
	ctx.lr = 0x880E1C4C;
	sub_88096BC8(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r31,6800
	ctx.r7.s64 = ctx.r31.s64 + 6800;
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
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// li r4,94
	ctx.r4.s64 = 94;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r11.u32);
	// li r3,5
	ctx.r3.s64 = 5;
	// lwz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// stw r10,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r10.u32);
	// bl 0x880e32d0
	ctx.lr = 0x880E1C90;
	sub_880E32D0(ctx, base);
	// lis r9,-30706
	ctx.r9.s64 = -2012348416;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r5,r9,-1088
	ctx.r5.s64 = ctx.r9.s64 + -1088;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88096c60
	ctx.lr = 0x880E1CA4;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E1CB0"))) PPC_WEAK_FUNC(sub_880E1CB0);
PPC_FUNC_IMPL(__imp__sub_880E1CB0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x880E1CB8;
	__savegprlr_27(ctx, base);
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
	// li r5,60
	ctx.r5.s64 = 60;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880E1CE0;
	sub_88096BC8(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r31,6800
	ctx.r7.s64 = ctx.r31.s64 + 6800;
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
	// addi r11,r11,5
	ctx.r11.s64 = ctx.r11.s64 + 5;
	// li r4,94
	ctx.r4.s64 = 94;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r11.u32);
	// li r3,5
	ctx.r3.s64 = 5;
	// lwz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// stw r10,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r10.u32);
	// lwz r8,0(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// stw r8,56(r9)
	PPC_STORE_U32(ctx.r9.u32 + 56, ctx.r8.u32);
	// bl 0x880e32d0
	ctx.lr = 0x880E1D2C;
	sub_880E32D0(ctx, base);
	// lis r7,-30706
	ctx.r7.s64 = -2012348416;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r5,r7,-552
	ctx.r5.s64 = ctx.r7.s64 + -552;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88096c60
	ctx.lr = 0x880E1D40;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E1D4C"))) PPC_WEAK_FUNC(sub_880E1D4C);
PPC_FUNC_IMPL(__imp__sub_880E1D4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E1D50"))) PPC_WEAK_FUNC(sub_880E1D50);
PPC_FUNC_IMPL(__imp__sub_880E1D50) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x880E1D58;
	__savegprlr_27(ctx, base);
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
	// li r5,60
	ctx.r5.s64 = 60;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880E1D80;
	sub_88096BC8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r31,6968
	ctx.r7.s64 = ctx.r31.s64 + 6968;
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
	// addi r11,r11,9
	ctx.r11.s64 = ctx.r11.s64 + 9;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r11.u32);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// stw r10,56(r9)
	PPC_STORE_U32(ctx.r9.u32 + 56, ctx.r10.u32);
	// bl 0x880e32d0
	ctx.lr = 0x880E1DCC;
	sub_880E32D0(ctx, base);
	// lis r9,-30706
	ctx.r9.s64 = -2012348416;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r5,r9,408
	ctx.r5.s64 = ctx.r9.s64 + 408;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88096c60
	ctx.lr = 0x880E1DE0;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E1DEC"))) PPC_WEAK_FUNC(sub_880E1DEC);
PPC_FUNC_IMPL(__imp__sub_880E1DEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E1DF0"))) PPC_WEAK_FUNC(sub_880E1DF0);
PPC_FUNC_IMPL(__imp__sub_880E1DF0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x880E1DF8;
	__savegprlr_27(ctx, base);
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
	// li r5,60
	ctx.r5.s64 = 60;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880E1E20;
	sub_88096BC8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r31,6884
	ctx.r7.s64 = ctx.r31.s64 + 6884;
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
	// addi r11,r11,9
	ctx.r11.s64 = ctx.r11.s64 + 9;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r11.u32);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// stw r10,56(r9)
	PPC_STORE_U32(ctx.r9.u32 + 56, ctx.r10.u32);
	// bl 0x880e32d0
	ctx.lr = 0x880E1E6C;
	sub_880E32D0(ctx, base);
	// lis r9,-30706
	ctx.r9.s64 = -2012348416;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r5,r9,408
	ctx.r5.s64 = ctx.r9.s64 + 408;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88096c60
	ctx.lr = 0x880E1E80;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E1E8C"))) PPC_WEAK_FUNC(sub_880E1E8C);
PPC_FUNC_IMPL(__imp__sub_880E1E8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E1E90"))) PPC_WEAK_FUNC(sub_880E1E90);
PPC_FUNC_IMPL(__imp__sub_880E1E90) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071120
	ctx.lr = 0x880E1E98;
	__savegprlr_14(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// stw r4,284(r1)
	PPC_STORE_U32(ctx.r1.u32 + 284, ctx.r4.u32);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// stw r5,292(r1)
	PPC_STORE_U32(ctx.r1.u32 + 292, ctx.r5.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r31.u32);
	// bl 0x88096bc8
	ctx.lr = 0x880E1EC8;
	sub_88096BC8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r15,r3
	ctx.r15.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x880e1f48
	if (ctx.cr6.lt) goto loc_880E1F48;
	// beq cr6,0x880e1f58
	if (ctx.cr6.eq) goto loc_880E1F58;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x880e225c
	if (!ctx.cr6.lt) goto loc_880E225C;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,256
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 256, ctx.xer);
	// bgt cr6,0x880e1ef8
	if (ctx.cr6.gt) goto loc_880E1EF8;
	// addi r11,r11,-256
	ctx.r11.s64 = ctx.r11.s64 + -256;
	// b 0x880e1f0c
	goto loc_880E1F0C;
loc_880E1EF8:
	// cmpwi cr6,r11,288
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 288, ctx.xer);
	// bgt cr6,0x880e1f08
	if (ctx.cr6.gt) goto loc_880E1F08;
	// addi r11,r11,-256
	ctx.r11.s64 = ctx.r11.s64 + -256;
	// b 0x880e1f0c
	goto loc_880E1F0C;
loc_880E1F08:
	// subfic r11,r11,-192
	ctx.xer.ca = ctx.r11.u32 <= 4294967104;
	ctx.r11.s64 = -192 - ctx.r11.s64;
loc_880E1F0C:
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// rlwinm r9,r11,2,21,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x7FC;
	// addi r8,r10,9552
	ctx.r8.s64 = ctx.r10.s64 + 9552;
	// lwzx r7,r9,r8
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// rlwinm r11,r7,14,0,17
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 14) & 0xFFFFC000;
	// stw r11,6380(r31)
	PPC_STORE_U32(ctx.r31.u32 + 6380, ctx.r11.u32);
	// lwz r11,4(r15)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r15.u32 + 4);
	// cmpwi cr6,r11,128
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 128, ctx.xer);
	// ble cr6,0x880e2230
	if (!ctx.cr6.gt) goto loc_880E2230;
	// cmpwi cr6,r11,288
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 288, ctx.xer);
	// ble cr6,0x880e1f40
	if (!ctx.cr6.gt) goto loc_880E1F40;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// b 0x880e2234
	goto loc_880E2234;
loc_880E1F40:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x880e2234
	goto loc_880E2234;
loc_880E1F48:
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,0(r15)
	PPC_STORE_U32(ctx.r15.u32 + 0, ctx.r11.u32);
	// stw r10,4(r15)
	PPC_STORE_U32(ctx.r15.u32 + 4, ctx.r10.u32);
loc_880E1F58:
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// lwz r9,12(r15)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r15.u32 + 12);
	// addi r10,r11,9552
	ctx.r10.s64 = ctx.r11.s64 + 9552;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stw r11,12(r15)
	PPC_STORE_U32(ctx.r15.u32 + 12, ctx.r11.u32);
	// bge 0x880e2194
	if (!ctx.cr0.lt) goto loc_880E2194;
	// lwz r11,16(r15)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r15.u32 + 16);
	// li r10,2
	ctx.r10.s64 = 2;
	// lis r9,21399
	ctx.r9.s64 = 1402404864;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// lis r10,16838
	ctx.r10.s64 = 1103495168;
	// lis r8,-256
	ctx.r8.s64 = -16777216;
	// lis r7,-21846
	ctx.r7.s64 = -1431699456;
	// stw r11,12(r15)
	PPC_STORE_U32(ctx.r15.u32 + 12, ctx.r11.u32);
	// lis r11,-30680
	ctx.r11.s64 = -2010644480;
	// addi r28,r31,7068
	ctx.r28.s64 = ctx.r31.s64 + 7068;
	// ori r30,r10,20077
	ctx.r30.u64 = ctx.r10.u64 | 20077;
	// lis r31,-30671
	ctx.r31.s64 = -2010054656;
	// ori r25,r9,33437
	ctx.r25.u64 = ctx.r9.u64 | 33437;
	// lis r22,48
	ctx.r22.s64 = 3145728;
	// ori r21,r8,65281
	ctx.r21.u64 = ctx.r8.u64 | 65281;
	// lis r20,-30667
	ctx.r20.s64 = -2009792512;
	// li r17,64
	ctx.r17.s64 = 64;
	// ori r16,r7,43691
	ctx.r16.u64 = ctx.r7.u64 | 43691;
	// li r14,112
	ctx.r14.s64 = 112;
	// lis r27,-30667
	ctx.r27.s64 = -2009792512;
	// lis r18,16
	ctx.r18.s64 = 1048576;
	// lis r26,-30667
	ctx.r26.s64 = -2009792512;
	// lis r19,-30667
	ctx.r19.s64 = -2009792512;
	// addi r23,r11,-19648
	ctx.r23.s64 = ctx.r11.s64 + -19648;
loc_880E1FD4:
	// lwz r11,4200(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4200);
	// addi r5,r23,-16
	ctx.r5.s64 = ctx.r23.s64 + -16;
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// mullw r11,r11,r30
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// lwz r6,-4(r28)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r28.u32 + -4);
	// lwz r7,184(r24)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r24.u32 + 184);
	// lwz r8,168(r24)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r24.u32 + 168);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// subf r10,r22,r4
	ctx.r10.s64 = ctx.r4.s64 - ctx.r22.s64;
	// stw r11,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r11.u32);
	// mullw r11,r11,r30
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// lhz r3,4200(r31)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// stw r10,12372(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12372, ctx.r10.u32);
	// addi r29,r11,12345
	ctx.r29.s64 = ctx.r11.s64 + 12345;
	// mulhwu r10,r3,r25
	ctx.r10.u64 = (uint64_t(ctx.r3.u32) * uint64_t(ctx.r25.u32)) >> 32;
	// rlwinm r9,r10,28,4,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0xFFFFFFF;
	// stw r29,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r29.u32);
	// lhz r11,4200(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// rlwinm r11,r11,2,28,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xC;
	// mulli r4,r9,49
	ctx.r4.s64 = ctx.r9.s64 * 49;
	// subf r10,r4,r3
	ctx.r10.s64 = ctx.r3.s64 - ctx.r4.s64;
	// lwzx r3,r11,r5
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r5.u32);
	// add r4,r7,r8
	ctx.r4.u64 = ctx.r7.u64 + ctx.r8.u64;
	// extsh r11,r10
	ctx.r11.s64 = ctx.r10.s16;
	// addi r9,r11,-24
	ctx.r9.s64 = ctx.r11.s64 + -24;
	// rlwinm r11,r9,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r6
	ctx.r11.u64 = ctx.r11.u64 + ctx.r6.u64;
	// stw r11,12364(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12364, ctx.r11.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880E2048;
	sub_880F52C8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880e2058
	if (ctx.cr6.eq) goto loc_880E2058;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r11.u32);
loc_880E2058:
	// mullw r11,r29,r30
	ctx.r11.s64 = int64_t(ctx.r29.s32) * int64_t(ctx.r30.s32);
	// addi r7,r11,12345
	ctx.r7.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r7,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r7.u32);
	// beq cr6,0x880e20d4
	if (ctx.cr6.eq) goto loc_880E20D4;
	// lhz r6,4200(r31)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// addic. r10,r3,40
	ctx.xer.ca = ctx.r3.u32 > 4294967255;
	ctx.r10.s64 = ctx.r3.s64 + 40;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r17,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, ctx.r17.u32);
	// addi r8,r3,36
	ctx.r8.s64 = ctx.r3.s64 + 36;
	// mulhwu r5,r6,r21
	ctx.r5.u64 = (uint64_t(ctx.r6.u32) * uint64_t(ctx.r21.u32)) >> 32;
	// rlwinm r11,r5,24,8,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 24) & 0xFFFFFF;
	// rlwinm r9,r11,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// add r4,r9,r11
	ctx.r4.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// subf r11,r4,r6
	ctx.r11.s64 = ctx.r6.s64 - ctx.r4.s64;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// stw r11,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, ctx.r11.u32);
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// beq 0x880e20bc
	if (ctx.cr0.eq) goto loc_880E20BC;
	// addi r6,r11,128
	ctx.r6.s64 = ctx.r11.s64 + 128;
	// rlwinm r5,r6,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// lwzx r4,r5,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r9.u32);
	// rlwinm r6,r4,6,0,25
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 6) & 0xFFFFFFC0;
	// stw r6,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r6.u32);
loc_880E20BC:
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x880e20d4
	if (ctx.cr6.eq) goto loc_880E20D4;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r9
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r9.u32);
	// rlwinm r9,r10,6,0,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// stw r9,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
loc_880E20D4:
	// mullw r11,r7,r30
	ctx.r11.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r30.s32);
	// addi r9,r11,12345
	ctx.r9.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r9,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r9.u32);
	// beq cr6,0x880e210c
	if (ctx.cr6.eq) goto loc_880E210C;
	// lhz r8,4200(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// stw r14,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r14.u32);
	// mulhwu r7,r8,r16
	ctx.r7.u64 = (uint64_t(ctx.r8.u32) * uint64_t(ctx.r16.u32)) >> 32;
	// rlwinm r11,r7,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// subf r5,r6,r8
	ctx.r5.s64 = ctx.r8.s64 - ctx.r6.s64;
	// extsh r11,r5
	ctx.r11.s64 = ctx.r5.s16;
	// stw r11,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r11.u32);
loc_880E210C:
	// mullw r11,r9,r30
	ctx.r11.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r30.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r11,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r11.u32);
	// beq cr6,0x880e2130
	if (ctx.cr6.eq) goto loc_880E2130;
	// lhz r11,4200(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// rlwinm r11,r11,2,28,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xC;
	// lwzx r10,r11,r23
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r23.u32);
	// stw r10,148(r3)
	PPC_STORE_U32(ctx.r3.u32 + 148, ctx.r10.u32);
loc_880E2130:
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// li r9,3
	ctx.r9.s64 = 3;
	// lwz r11,-4(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -4);
	// li r8,11
	ctx.r8.s64 = 11;
	// subf r10,r18,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r18.s64;
	// stw r9,12380(r19)
	PPC_STORE_U32(ctx.r19.u32 + 12380, ctx.r9.u32);
	// li r4,11
	ctx.r4.s64 = 11;
	// stw r8,12376(r20)
	PPC_STORE_U32(ctx.r20.u32 + 12376, ctx.r8.u32);
	// stw r10,12372(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12372, ctx.r10.u32);
	// li r3,3
	ctx.r3.s64 = 3;
	// stw r11,12364(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12364, ctx.r11.u32);
	// bl 0x880f8798
	ctx.lr = 0x880E2160;
	sub_880F8798(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880e2170
	if (ctx.cr6.eq) goto loc_880E2170;
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,24(r3)
	PPC_STORE_U8(ctx.r3.u32 + 24, ctx.r11.u8);
loc_880E2170:
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r28,r28,84
	ctx.r28.s64 = ctx.r28.s64 + 84;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bne 0x880e1fd4
	if (!ctx.cr0.eq) goto loc_880E1FD4;
	// lwz r30,284(r1)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 284);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r31,88(r1)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r29,292(r1)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 292);
loc_880E2194:
	// lwz r11,4(r15)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r15.u32 + 4);
	// cmpwi cr6,r11,256
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 256, ctx.xer);
	// bgt cr6,0x880e21a8
	if (ctx.cr6.gt) goto loc_880E21A8;
	// addi r11,r11,-256
	ctx.r11.s64 = ctx.r11.s64 + -256;
	// b 0x880e21bc
	goto loc_880E21BC;
loc_880E21A8:
	// cmpwi cr6,r11,288
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 288, ctx.xer);
	// bgt cr6,0x880e21b8
	if (ctx.cr6.gt) goto loc_880E21B8;
	// addi r11,r11,-256
	ctx.r11.s64 = ctx.r11.s64 + -256;
	// b 0x880e21bc
	goto loc_880E21BC;
loc_880E21B8:
	// subfic r11,r11,-192
	ctx.xer.ca = ctx.r11.u32 <= 4294967104;
	ctx.r11.s64 = -192 - ctx.r11.s64;
loc_880E21BC:
	// rlwinm r9,r11,2,21,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x7FC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// rlwinm r11,r8,14,0,17
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 14) & 0xFFFFC000;
	// stw r11,6380(r31)
	PPC_STORE_U32(ctx.r31.u32 + 6380, ctx.r11.u32);
	// lwz r11,4(r15)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r15.u32 + 4);
	// cmpwi cr6,r11,128
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 128, ctx.xer);
	// ble cr6,0x880e2230
	if (!ctx.cr6.gt) goto loc_880E2230;
	// cmpwi cr6,r11,288
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 288, ctx.xer);
	// ble cr6,0x880e21e8
	if (!ctx.cr6.gt) goto loc_880E21E8;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// b 0x880e21ec
	goto loc_880E21EC;
loc_880E21E8:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
loc_880E21EC:
	// stw r11,4(r15)
	PPC_STORE_U32(ctx.r15.u32 + 4, ctx.r11.u32);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// cmpwi cr6,r11,176
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 176, ctx.xer);
	// ble cr6,0x880e2238
	if (!ctx.cr6.gt) goto loc_880E2238;
	// lis r11,-30679
	ctx.r11.s64 = -2010578944;
	// lis r8,-30643
	ctx.r8.s64 = -2008219648;
	// addi r7,r11,-15272
	ctx.r7.s64 = ctx.r11.s64 + -15272;
	// addi r6,r8,32248
	ctx.r6.s64 = ctx.r8.s64 + 32248;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,5
	ctx.r10.s64 = 5;
	// stw r5,0(r15)
	PPC_STORE_U32(ctx.r15.u32 + 0, ctx.r5.u32);
	// lwz r9,20(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// stw r10,32248(r8)
	PPC_STORE_U32(ctx.r8.u32 + 32248, ctx.r10.u32);
	// stw r11,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r11.u32);
	// stw r9,16(r6)
	PPC_STORE_U32(ctx.r6.u32 + 16, ctx.r9.u32);
	// b 0x880e2238
	goto loc_880E2238;
loc_880E2230:
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
loc_880E2234:
	// stw r11,4(r15)
	PPC_STORE_U32(ctx.r15.u32 + 4, ctx.r11.u32);
loc_880E2238:
	// lwz r11,4(r15)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r15.u32 + 4);
	// cmpwi cr6,r11,288
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 288, ctx.xer);
	// ble cr6,0x880e225c
	if (!ctx.cr6.gt) goto loc_880E225C;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096b40
	ctx.lr = 0x880E2250;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
loc_880E225C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E2268"))) PPC_WEAK_FUNC(sub_880E2268);
PPC_FUNC_IMPL(__imp__sub_880E2268) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071120
	ctx.lr = 0x880E2270;
	__savegprlr_14(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// stw r4,268(r1)
	PPC_STORE_U32(ctx.r1.u32 + 268, ctx.r4.u32);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// stw r5,276(r1)
	PPC_STORE_U32(ctx.r1.u32 + 276, ctx.r5.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// bl 0x88096bc8
	ctx.lr = 0x880E22A0;
	sub_88096BC8(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r18,r3
	ctx.r18.u64 = ctx.r3.u64;
	// lwz r10,2300(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2300);
	// lwz r9,156(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 156);
	// neg r8,r9
	ctx.r8.s64 = -ctx.r9.s64;
	// stw r8,852(r31)
	PPC_STORE_U32(ctx.r31.u32 + 852, ctx.r8.u32);
	// lwz r7,2300(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2300);
	// lwz r6,160(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 160);
	// neg r5,r6
	ctx.r5.s64 = -ctx.r6.s64;
	// stw r5,856(r31)
	PPC_STORE_U32(ctx.r31.u32 + 856, ctx.r5.u32);
	// lwz r4,8(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r11,r4,-1
	ctx.xer.ca = ctx.r4.u32 > 0;
	ctx.r11.s64 = ctx.r4.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x880e22e4
	if (!ctx.cr0.lt) goto loc_880E22E4;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,852(r31)
	PPC_STORE_U32(ctx.r31.u32 + 852, ctx.r11.u32);
	// stw r11,856(r31)
	PPC_STORE_U32(ctx.r31.u32 + 856, ctx.r11.u32);
loc_880E22E4:
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// lwz r10,12(r18)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	// addi r14,r11,9552
	ctx.r14.s64 = ctx.r11.s64 + 9552;
	// addic. r11,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r11.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,12(r18)
	PPC_STORE_U32(ctx.r18.u32 + 12, ctx.r11.u32);
	// bge 0x880e24fc
	if (!ctx.cr0.lt) goto loc_880E24FC;
	// lwz r10,16(r18)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r18.u32 + 16);
	// lis r9,-30667
	ctx.r9.s64 = -2009792512;
	// li r11,3
	ctx.r11.s64 = 3;
	// li r8,2
	ctx.r8.s64 = 2;
	// lis r7,-21846
	ctx.r7.s64 = -1431699456;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lis r8,-256
	ctx.r8.s64 = -16777216;
	// stw r11,12380(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12380, ctx.r11.u32);
	// lis r11,-30680
	ctx.r11.s64 = -2010644480;
	// stw r10,12(r18)
	PPC_STORE_U32(ctx.r18.u32 + 12, ctx.r10.u32);
	// lis r10,16838
	ctx.r10.s64 = 1103495168;
	// lis r9,21399
	ctx.r9.s64 = 1402404864;
	// addi r28,r31,7068
	ctx.r28.s64 = ctx.r31.s64 + 7068;
	// ori r29,r10,20077
	ctx.r29.u64 = ctx.r10.u64 | 20077;
	// lis r31,-30671
	ctx.r31.s64 = -2010054656;
	// ori r25,r9,33437
	ctx.r25.u64 = ctx.r9.u64 | 33437;
	// lis r23,48
	ctx.r23.s64 = 3145728;
	// ori r22,r8,65281
	ctx.r22.u64 = ctx.r8.u64 | 65281;
	// lis r21,-30667
	ctx.r21.s64 = -2009792512;
	// li r20,64
	ctx.r20.s64 = 64;
	// ori r19,r7,43691
	ctx.r19.u64 = ctx.r7.u64 | 43691;
	// li r15,112
	ctx.r15.s64 = 112;
	// lis r27,-30667
	ctx.r27.s64 = -2009792512;
	// lis r17,16
	ctx.r17.s64 = 1048576;
	// lis r26,-30667
	ctx.r26.s64 = -2009792512;
	// addi r16,r11,-19648
	ctx.r16.s64 = ctx.r11.s64 + -19648;
loc_880E2364:
	// lwz r11,4200(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4200);
	// li r3,13
	ctx.r3.s64 = 13;
	// lwz r7,0(r28)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// mullw r11,r11,r29
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r29.s32);
	// lwz r10,184(r24)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r24.u32 + 184);
	// lwz r9,168(r24)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r24.u32 + 168);
	// lwz r8,-4(r28)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r28.u32 + -4);
	// addi r30,r11,12345
	ctx.r30.s64 = ctx.r11.s64 + 12345;
	// subf r11,r23,r7
	ctx.r11.s64 = ctx.r7.s64 - ctx.r23.s64;
	// stw r30,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r30.u32);
	// add r4,r9,r10
	ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lhz r6,4200(r31)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// mulhwu r5,r6,r25
	ctx.r5.u64 = (uint64_t(ctx.r6.u32) * uint64_t(ctx.r25.u32)) >> 32;
	// stw r11,12372(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12372, ctx.r11.u32);
	// rlwinm r11,r5,28,4,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 28) & 0xFFFFFFF;
	// mulli r10,r11,49
	ctx.r10.s64 = ctx.r11.s64 * 49;
	// subf r9,r10,r6
	ctx.r9.s64 = ctx.r6.s64 - ctx.r10.s64;
	// extsh r11,r9
	ctx.r11.s64 = ctx.r9.s16;
	// addi r6,r11,-24
	ctx.r6.s64 = ctx.r11.s64 + -24;
	// rlwinm r11,r6,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stw r11,12364(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12364, ctx.r11.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880E23C0;
	sub_880F52C8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880e23d0
	if (ctx.cr6.eq) goto loc_880E23D0;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r11.u32);
loc_880E23D0:
	// mullw r11,r30,r29
	ctx.r11.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r29.s32);
	// addi r7,r11,12345
	ctx.r7.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r7,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r7.u32);
	// beq cr6,0x880e2448
	if (ctx.cr6.eq) goto loc_880E2448;
	// lhz r6,4200(r31)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// addic. r10,r3,40
	ctx.xer.ca = ctx.r3.u32 > 4294967255;
	ctx.r10.s64 = ctx.r3.s64 + 40;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r20,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, ctx.r20.u32);
	// addi r8,r3,36
	ctx.r8.s64 = ctx.r3.s64 + 36;
	// mulhwu r5,r6,r22
	ctx.r5.u64 = (uint64_t(ctx.r6.u32) * uint64_t(ctx.r22.u32)) >> 32;
	// rlwinm r11,r5,24,8,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 24) & 0xFFFFFF;
	// rlwinm r9,r11,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// add r4,r9,r11
	ctx.r4.u64 = ctx.r9.u64 + ctx.r11.u64;
	// subf r11,r4,r6
	ctx.r11.s64 = ctx.r6.s64 - ctx.r4.s64;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// stw r11,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, ctx.r11.u32);
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// beq 0x880e2430
	if (ctx.cr0.eq) goto loc_880E2430;
	// addi r9,r11,128
	ctx.r9.s64 = ctx.r11.s64 + 128;
	// rlwinm r6,r9,2,21,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x7FC;
	// lwzx r5,r6,r14
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r14.u32);
	// rlwinm r4,r5,6,0,25
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 6) & 0xFFFFFFC0;
	// stw r4,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
loc_880E2430:
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x880e2448
	if (ctx.cr6.eq) goto loc_880E2448;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r14
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r14.u32);
	// rlwinm r9,r10,6,0,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// stw r9,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
loc_880E2448:
	// mullw r11,r7,r29
	ctx.r11.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r29.s32);
	// addi r9,r11,12345
	ctx.r9.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r9,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r9.u32);
	// beq cr6,0x880e2480
	if (ctx.cr6.eq) goto loc_880E2480;
	// lhz r8,4200(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// stw r15,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r15.u32);
	// mulhwu r7,r8,r19
	ctx.r7.u64 = (uint64_t(ctx.r8.u32) * uint64_t(ctx.r19.u32)) >> 32;
	// rlwinm r11,r7,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// subf r5,r6,r8
	ctx.r5.s64 = ctx.r8.s64 - ctx.r6.s64;
	// extsh r11,r5
	ctx.r11.s64 = ctx.r5.s16;
	// stw r11,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r11.u32);
loc_880E2480:
	// mullw r11,r9,r29
	ctx.r11.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r29.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r11,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r11.u32);
	// beq cr6,0x880e24a4
	if (ctx.cr6.eq) goto loc_880E24A4;
	// lhz r11,4200(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// rlwinm r11,r11,2,28,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xC;
	// lwzx r10,r11,r16
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r16.u32);
	// stw r10,148(r3)
	PPC_STORE_U32(ctx.r3.u32 + 148, ctx.r10.u32);
loc_880E24A4:
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// li r9,11
	ctx.r9.s64 = 11;
	// lwz r11,-4(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -4);
	// li r4,11
	ctx.r4.s64 = 11;
	// subf r10,r17,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r17.s64;
	// stw r9,12376(r21)
	PPC_STORE_U32(ctx.r21.u32 + 12376, ctx.r9.u32);
	// li r3,3
	ctx.r3.s64 = 3;
	// stw r10,12372(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12372, ctx.r10.u32);
	// stw r11,12364(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12364, ctx.r11.u32);
	// bl 0x880f8798
	ctx.lr = 0x880E24CC;
	sub_880F8798(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880e24dc
	if (ctx.cr6.eq) goto loc_880E24DC;
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,24(r3)
	PPC_STORE_U8(ctx.r3.u32 + 24, ctx.r11.u8);
loc_880E24DC:
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r28,r28,84
	ctx.r28.s64 = ctx.r28.s64 + 84;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bne 0x880e2364
	if (!ctx.cr0.eq) goto loc_880E2364;
	// lwz r31,84(r1)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r30,268(r1)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 268);
	// lwz r29,276(r1)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 276);
loc_880E24FC:
	// lwz r11,0(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x880e2518
	if (ctx.cr6.lt) goto loc_880E2518;
	// beq cr6,0x880e2528
	if (ctx.cr6.eq) goto loc_880E2528;
loc_880E250C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
loc_880E2518:
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,0(r18)
	PPC_STORE_U32(ctx.r18.u32 + 0, ctx.r11.u32);
	// stw r10,4(r18)
	PPC_STORE_U32(ctx.r18.u32 + 4, ctx.r10.u32);
loc_880E2528:
	// lwz r11,4(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 4);
	// cmpwi cr6,r11,256
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 256, ctx.xer);
	// bgt cr6,0x880e2548
	if (ctx.cr6.gt) goto loc_880E2548;
	// addi r11,r11,-256
	ctx.r11.s64 = ctx.r11.s64 + -256;
	// rlwinm r10,r11,2,21,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x7FC;
	// lwzx r9,r10,r14
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r14.u32);
	// rlwinm r11,r9,14,0,17
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 14) & 0xFFFFC000;
	// b 0x880e2568
	goto loc_880E2568;
loc_880E2548:
	// cmpwi cr6,r11,272
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 272, ctx.xer);
	// bgt cr6,0x880e2558
	if (ctx.cr6.gt) goto loc_880E2558;
	// addi r11,r11,-256
	ctx.r11.s64 = ctx.r11.s64 + -256;
	// b 0x880e255c
	goto loc_880E255C;
loc_880E2558:
	// subfic r11,r11,-224
	ctx.xer.ca = ctx.r11.u32 <= 4294967072;
	ctx.r11.s64 = -224 - ctx.r11.s64;
loc_880E255C:
	// rlwinm r10,r11,2,21,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x7FC;
	// lwzx r9,r10,r14
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r14.u32);
	// rlwinm r11,r9,13,0,18
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 13) & 0xFFFFE000;
loc_880E2568:
	// stw r11,6380(r31)
	PPC_STORE_U32(ctx.r31.u32 + 6380, ctx.r11.u32);
	// lwz r11,4(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 4);
	// cmpwi cr6,r11,128
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 128, ctx.xer);
	// ble cr6,0x880e2590
	if (!ctx.cr6.gt) goto loc_880E2590;
	// cmpwi cr6,r11,272
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 272, ctx.xer);
	// ble cr6,0x880e2588
	if (!ctx.cr6.gt) goto loc_880E2588;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// b 0x880e2594
	goto loc_880E2594;
loc_880E2588:
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// b 0x880e2594
	goto loc_880E2594;
loc_880E2590:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
loc_880E2594:
	// stw r11,4(r18)
	PPC_STORE_U32(ctx.r18.u32 + 4, ctx.r11.u32);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// cmpwi cr6,r11,288
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 288, ctx.xer);
	// ble cr6,0x880e250c
	if (!ctx.cr6.gt) goto loc_880E250C;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096b40
	ctx.lr = 0x880E25B0;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E25BC"))) PPC_WEAK_FUNC(sub_880E25BC);
PPC_FUNC_IMPL(__imp__sub_880E25BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E25C0"))) PPC_WEAK_FUNC(sub_880E25C0);
PPC_FUNC_IMPL(__imp__sub_880E25C0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880E25C8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// li r5,96
	ctx.r5.s64 = 96;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880E25E8;
	sub_88096BC8(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// stw r9,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r9.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// lwz r4,580(r29)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r29.u32 + 580);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x880e261c
	if (ctx.cr6.eq) goto loc_880E261C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096b40
	ctx.lr = 0x880E261C;
	sub_88096B40(ctx, base);
loc_880E261C:
	// lwz r11,4(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// lis r10,-30706
	ctx.r10.s64 = -2012348416;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mulli r11,r11,372
	ctx.r11.s64 = ctx.r11.s64 * 372;
	// add r9,r11,r29
	ctx.r9.u64 = ctx.r11.u64 + ctx.r29.u64;
	// addi r5,r10,1320
	ctx.r5.s64 = ctx.r10.s64 + 1320;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r31,208(r9)
	PPC_STORE_U32(ctx.r9.u32 + 208, ctx.r31.u32);
	// bl 0x88096c60
	ctx.lr = 0x880E2640;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E264C"))) PPC_WEAK_FUNC(sub_880E264C);
PPC_FUNC_IMPL(__imp__sub_880E264C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E2650"))) PPC_WEAK_FUNC(sub_880E2650);
PPC_FUNC_IMPL(__imp__sub_880E2650) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880E2658;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// li r5,96
	ctx.r5.s64 = 96;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880E2678;
	sub_88096BC8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// stw r9,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r9.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// lwz r4,208(r29)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r29.u32 + 208);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x880e26ac
	if (ctx.cr6.eq) goto loc_880E26AC;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096b40
	ctx.lr = 0x880E26AC;
	sub_88096B40(ctx, base);
loc_880E26AC:
	// lwz r11,4(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// lis r10,-30706
	ctx.r10.s64 = -2012348416;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mulli r11,r11,372
	ctx.r11.s64 = ctx.r11.s64 * 372;
	// add r9,r11,r29
	ctx.r9.u64 = ctx.r11.u64 + ctx.r29.u64;
	// addi r5,r10,1320
	ctx.r5.s64 = ctx.r10.s64 + 1320;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r31,208(r9)
	PPC_STORE_U32(ctx.r9.u32 + 208, ctx.r31.u32);
	// bl 0x88096c60
	ctx.lr = 0x880E26D0;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E26DC"))) PPC_WEAK_FUNC(sub_880E26DC);
PPC_FUNC_IMPL(__imp__sub_880E26DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E26E0"))) PPC_WEAK_FUNC(sub_880E26E0);
PPC_FUNC_IMPL(__imp__sub_880E26E0) {
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
	// lwz r10,2304(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// lis r9,-30706
	ctx.r9.s64 = -2012348416;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,2064
	ctx.r4.s64 = ctx.r9.s64 + 2064;
	// stw r11,88(r10)
	PPC_STORE_U32(ctx.r10.u32 + 88, ctx.r11.u32);
	// lwz r3,36(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// bl 0x88096cb8
	ctx.lr = 0x880E2710;
	sub_88096CB8(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880E2720"))) PPC_WEAK_FUNC(sub_880E2720);
PPC_FUNC_IMPL(__imp__sub_880E2720) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r10,6864(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 6864);
	// stw r4,76(r11)
	PPC_STORE_U32(ctx.r11.u32 + 76, ctx.r4.u32);
	// stw r5,80(r11)
	PPC_STORE_U32(ctx.r11.u32 + 80, ctx.r5.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880e2740
	if (ctx.cr6.eq) goto loc_880E2740;
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
loc_880E2740:
	// lis r10,-30706
	ctx.r10.s64 = -2012348416;
	// lwz r3,36(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,3176
	ctx.r4.s64 = ctx.r10.s64 + 3176;
	// b 0x88096cb8
	sub_88096CB8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E2754"))) PPC_WEAK_FUNC(sub_880E2754);
PPC_FUNC_IMPL(__imp__sub_880E2754) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880E2758"))) PPC_WEAK_FUNC(sub_880E2758);
PPC_FUNC_IMPL(__imp__sub_880E2758) {
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
	// lwz r10,2304(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mulli r11,r4,372
	ctx.r11.s64 = ctx.r4.s64 * 372;
	// lwz r8,184(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// lwz r9,168(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lis r7,120
	ctx.r7.s64 = 7864320;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r8,r11,100
	ctx.r8.s64 = ctx.r11.s64 + 100;
	// addi r5,r9,5
	ctx.r5.s64 = ctx.r9.s64 + 5;
	// lwz r6,108(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 108);
	// lwz r4,112(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 112);
	// lis r11,-30680
	ctx.r11.s64 = -2010644480;
	// cmpw cr6,r6,r7
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r7.s32, ctx.xer);
	// addis r3,r4,-32
	ctx.r3.s64 = ctx.r4.s64 + -2097152;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// lwz r6,44(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// ble cr6,0x880e27cc
	if (!ctx.cr6.gt) goto loc_880E27CC;
	// addi r11,r11,-17248
	ctx.r11.s64 = ctx.r11.s64 + -17248;
	// addi r3,r11,-184
	ctx.r3.s64 = ctx.r11.s64 + -184;
	// bl 0x880e0ce8
	ctx.lr = 0x880E27BC;
	sub_880E0CE8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_880E27CC:
	// addi r3,r11,-17248
	ctx.r3.s64 = ctx.r11.s64 + -17248;
	// bl 0x880e0ce8
	ctx.lr = 0x880E27D4;
	sub_880E0CE8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880E27E4"))) PPC_WEAK_FUNC(sub_880E27E4);
PPC_FUNC_IMPL(__imp__sub_880E27E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E27E8"))) PPC_WEAK_FUNC(sub_880E27E8);
PPC_FUNC_IMPL(__imp__sub_880E27E8) {
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
	// lwz r6,44(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r5,r8,r9
	ctx.r5.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lis r10,-30680
	ctx.r10.s64 = -2010644480;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r10,-18008
	ctx.r3.s64 = ctx.r10.s64 + -18008;
	// lwz r9,7068(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 7068);
	// lwz r8,7064(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 7064);
	// addi r11,r11,7052
	ctx.r11.s64 = ctx.r11.s64 + 7052;
	// addis r7,r9,-16
	ctx.r7.s64 = ctx.r9.s64 + -1048576;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// bl 0x880e1038
	ctx.lr = 0x880E2838;
	sub_880E1038(ctx, base);
	// lis r6,-30667
	ctx.r6.s64 = -2009792512;
	// lis r5,-30667
	ctx.r5.s64 = -2009792512;
	// li r11,3
	ctx.r11.s64 = 3;
	// li r10,11
	ctx.r10.s64 = 11;
	// lis r9,-30667
	ctx.r9.s64 = -2009792512;
	// stw r11,12380(r6)
	PPC_STORE_U32(ctx.r6.u32 + 12380, ctx.r11.u32);
	// lis r8,-30667
	ctx.r8.s64 = -2009792512;
	// stw r10,12376(r5)
	PPC_STORE_U32(ctx.r5.u32 + 12376, ctx.r10.u32);
	// li r4,11
	ctx.r4.s64 = 11;
	// li r3,3
	ctx.r3.s64 = 3;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r11,12364(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12372, ctx.r10.u32);
	// bl 0x880f8798
	ctx.lr = 0x880E2874;
	sub_880F8798(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880e2884
	if (ctx.cr6.eq) goto loc_880E2884;
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,24(r3)
	PPC_STORE_U8(ctx.r3.u32 + 24, ctx.r11.u8);
loc_880E2884:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880E2894"))) PPC_WEAK_FUNC(sub_880E2894);
PPC_FUNC_IMPL(__imp__sub_880E2894) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E2898"))) PPC_WEAK_FUNC(sub_880E2898);
PPC_FUNC_IMPL(__imp__sub_880E2898) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x880E28A0;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// lwz r30,2304(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880E28C4;
	sub_88096BC8(ctx, base);
	// lwz r11,168(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 168);
	// lwz r10,184(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r29,r10,7
	ctx.r29.s64 = ctx.r10.s64 + 7;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x880e2974
	if (ctx.cr6.lt) goto loc_880E2974;
	// beq cr6,0x880e292c
	if (ctx.cr6.eq) goto loc_880E292C;
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// bne cr6,0x880e2a30
	if (!ctx.cr6.eq) goto loc_880E2A30;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// bge 0x880e2a30
	if (!ctx.cr0.lt) goto loc_880E2A30;
	// lis r11,-30706
	ctx.r11.s64 = -2012348416;
	// lwz r3,36(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,3016
	ctx.r4.s64 = ctx.r11.s64 + 3016;
	// bl 0x88096cb8
	ctx.lr = 0x880E2914;
	sub_88096CB8(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x88096b40
	ctx.lr = 0x880E2920;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_880E292C:
	// lwz r11,4(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r11.u32);
	// bge 0x880e2a30
	if (!ctx.cr0.lt) goto loc_880E2A30;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,36(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// bl 0x880dc728
	ctx.lr = 0x880E2948;
	sub_880DC728(ctx, base);
	// li r11,10
	ctx.r11.s64 = 10;
	// li r10,12
	ctx.r10.s64 = 12;
	// li r9,80
	ctx.r9.s64 = 80;
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// li r7,256
	ctx.r7.s64 = 256;
	// stw r10,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r10.u32);
	// stw r9,48(r30)
	PPC_STORE_U32(ctx.r30.u32 + 48, ctx.r9.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r7,52(r30)
	PPC_STORE_U32(ctx.r30.u32 + 52, ctx.r7.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_880E2974:
	// lwz r11,4(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r11.u32);
	// bge 0x880e2a30
	if (!ctx.cr0.lt) goto loc_880E2A30;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r5,r11,30408
	ctx.r5.s64 = ctx.r11.s64 + 30408;
	// stw r9,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r7,20
	ctx.r7.s64 = 20;
	// lis r9,2560
	ctx.r9.s64 = 167772160;
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// stw r7,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r7.u32);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// stw r9,188(r5)
	PPC_STORE_U32(ctx.r5.u32 + 188, ctx.r9.u32);
	// li r6,256
	ctx.r6.s64 = 256;
	// li r9,80
	ctx.r9.s64 = 80;
	// lwz r11,32(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 32);
	// lis r8,-5
	ctx.r8.s64 = -327680;
	// stw r6,160(r5)
	PPC_STORE_U32(ctx.r5.u32 + 160, ctx.r6.u32);
	// lis r3,5
	ctx.r3.s64 = 327680;
	// stw r9,164(r5)
	PPC_STORE_U32(ctx.r5.u32 + 164, ctx.r9.u32);
	// lis r28,120
	ctx.r28.s64 = 7864320;
	// stw r10,184(r5)
	PPC_STORE_U32(ctx.r5.u32 + 184, ctx.r10.u32);
	// lis r27,192
	ctx.r27.s64 = 12582912;
	// stw r10,176(r5)
	PPC_STORE_U32(ctx.r5.u32 + 176, ctx.r10.u32);
	// stw r10,180(r5)
	PPC_STORE_U32(ctx.r5.u32 + 180, ctx.r10.u32);
	// lis r9,-30680
	ctx.r9.s64 = -2010644480;
	// stw r10,168(r5)
	PPC_STORE_U32(ctx.r5.u32 + 168, ctx.r10.u32);
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// stw r8,172(r5)
	PPC_STORE_U32(ctx.r5.u32 + 172, ctx.r8.u32);
	// addi r7,r29,1
	ctx.r7.s64 = ctx.r29.s64 + 1;
	// stw r3,240(r11)
	PPC_STORE_U32(ctx.r11.u32 + 240, ctx.r3.u32);
	// addi r4,r9,-19488
	ctx.r4.s64 = ctx.r9.s64 + -19488;
	// stw r10,236(r11)
	PPC_STORE_U32(ctx.r11.u32 + 236, ctx.r10.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// li r5,12
	ctx.r5.s64 = 12;
	// stw r27,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r27.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r8,44(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	// bl 0x880e1768
	ctx.lr = 0x880E2A1C;
	sub_880E1768(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r6,44(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880e12e0
	ctx.lr = 0x880E2A30;
	sub_880E12E0(ctx, base);
loc_880E2A30:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E2A3C"))) PPC_WEAK_FUNC(sub_880E2A3C);
PPC_FUNC_IMPL(__imp__sub_880E2A3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E2A40"))) PPC_WEAK_FUNC(sub_880E2A40);
PPC_FUNC_IMPL(__imp__sub_880E2A40) {
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
	// bl 0x88096bc8
	ctx.lr = 0x880E2A6C;
	sub_88096BC8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// lis r8,-30706
	ctx.r8.s64 = -2012348416;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r9,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r9.u32);
	// addi r5,r8,7824
	ctx.r5.s64 = ctx.r8.s64 + 7824;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096c60
	ctx.lr = 0x880E2A98;
	sub_88096C60(ctx, base);
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

__attribute__((alias("__imp__sub_880E2AB4"))) PPC_WEAK_FUNC(sub_880E2AB4);
PPC_FUNC_IMPL(__imp__sub_880E2AB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E2AB8"))) PPC_WEAK_FUNC(sub_880E2AB8);
PPC_FUNC_IMPL(__imp__sub_880E2AB8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071134
	ctx.lr = 0x880E2AC0;
	__savegprlr_19(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r19,r4
	ctx.r19.u64 = ctx.r4.u64;
	// lwz r30,2304(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r22,r5
	ctx.r22.u64 = ctx.r5.u64;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r5,20
	ctx.r5.s64 = 20;
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880E2AE4;
	sub_88096BC8(ctx, base);
	// lis r11,-30679
	ctx.r11.s64 = -2010578944;
	// lis r8,-30643
	ctx.r8.s64 = -2008219648;
	// addi r7,r11,-15272
	ctx.r7.s64 = ctx.r11.s64 + -15272;
	// addi r6,r8,32248
	ctx.r6.s64 = ctx.r8.s64 + 32248;
	// li r21,0
	ctx.r21.s64 = 0;
	// li r5,30
	ctx.r5.s64 = 30;
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r21,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r21.u32);
	// stw r5,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r5.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,16(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// mr r11,r21
	ctx.r11.u64 = ctx.r21.u64;
	// stw r10,32248(r8)
	PPC_STORE_U32(ctx.r8.u32 + 32248, ctx.r10.u32);
	// addi r31,r30,7068
	ctx.r31.s64 = ctx.r30.s64 + 7068;
	// stw r21,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r21.u32);
	// li r20,2
	ctx.r20.s64 = 2;
	// stw r9,16(r6)
	PPC_STORE_U32(ctx.r6.u32 + 16, ctx.r9.u32);
	// lis r23,32
	ctx.r23.s64 = 2097152;
	// stw r21,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r21.u32);
	// lis r25,-30667
	ctx.r25.s64 = -2009792512;
	// stw r4,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r4.u32);
	// lis r24,-30667
	ctx.r24.s64 = -2009792512;
	// lwz r11,168(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 168);
	// lis r26,-30667
	ctx.r26.s64 = -2009792512;
	// lwz r10,184(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 184);
	// add r28,r10,r11
	ctx.r28.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lis r11,-30680
	ctx.r11.s64 = -2010644480;
	// lis r27,-30667
	ctx.r27.s64 = -2009792512;
	// addi r29,r11,-17864
	ctx.r29.s64 = ctx.r11.s64 + -17864;
loc_880E2B58:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r3,r29,-144
	ctx.r3.s64 = ctx.r29.s64 + -144;
	// lwz r10,-4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -4);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// subf r9,r23,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r23.s64;
	// lwz r6,44(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x880e1038
	ctx.lr = 0x880E2B80;
	sub_880E1038(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// lwz r6,44(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x880e1038
	ctx.lr = 0x880E2B94;
	sub_880E1038(ctx, base);
	// li r11,3
	ctx.r11.s64 = 3;
	// li r10,11
	ctx.r10.s64 = 11;
	// stw r11,12380(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12380, ctx.r11.u32);
	// li r4,11
	ctx.r4.s64 = 11;
	// stw r10,12376(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12376, ctx.r10.u32);
	// li r3,3
	ctx.r3.s64 = 3;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r11,12364(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12372, ctx.r10.u32);
	// bl 0x880f8798
	ctx.lr = 0x880E2BC0;
	sub_880F8798(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880e2bcc
	if (ctx.cr6.eq) goto loc_880E2BCC;
	// stb r21,24(r3)
	PPC_STORE_U8(ctx.r3.u32 + 24, ctx.r21.u8);
loc_880E2BCC:
	// addic. r20,r20,-1
	ctx.xer.ca = ctx.r20.u32 > 0;
	ctx.r20.s64 = ctx.r20.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// addi r31,r31,84
	ctx.r31.s64 = ctx.r31.s64 + 84;
	// bne 0x880e2b58
	if (!ctx.cr0.eq) goto loc_880E2B58;
	// addi r11,r19,3640
	ctx.r11.s64 = ctx.r19.s64 + 3640;
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x880e2c30
	if (ctx.cr6.eq) goto loc_880E2C30;
	// clrlwi r9,r22,16
	ctx.r9.u64 = ctx.r22.u32 & 0xFFFF;
	// mr r10,r21
	ctx.r10.u64 = ctx.r21.u64;
loc_880E2BEC:
	// lhz r8,6(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 6);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x880e2c08
	if (ctx.cr6.eq) goto loc_880E2C08;
	// lhz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4);
	// clrlwi r7,r9,16
	ctx.r7.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x880e2c24
	if (ctx.cr6.eq) goto loc_880E2C24;
loc_880E2C08:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,104
	ctx.r11.s64 = ctx.r11.s64 + 104;
	// cmpwi cr6,r10,20
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 20, ctx.xer);
	// blt cr6,0x880e2bec
	if (ctx.cr6.lt) goto loc_880E2BEC;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x88071184
	__restgprlr_19(ctx, base);
	return;
loc_880E2C24:
	// lis r10,-30706
	ctx.r10.s64 = -2012348416;
	// addi r9,r10,8808
	ctx.r9.s64 = ctx.r10.s64 + 8808;
	// stw r9,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r9.u32);
loc_880E2C30:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x88071184
	__restgprlr_19(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E2C3C"))) PPC_WEAK_FUNC(sub_880E2C3C);
PPC_FUNC_IMPL(__imp__sub_880E2C3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E2C40"))) PPC_WEAK_FUNC(sub_880E2C40);
PPC_FUNC_IMPL(__imp__sub_880E2C40) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x880E2C48;
	__savegprlr_25(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r25,2304(r3)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// li r5,24
	ctx.r5.s64 = 24;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880E2C6C;
	sub_88096BC8(ctx, base);
	// li r31,0
	ctx.r31.s64 = 0;
	// li r27,1
	ctx.r27.s64 = 1;
	// lis r11,372
	ctx.r11.s64 = 24379392;
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r31.u32);
	// li r10,64
	ctx.r10.s64 = 64;
	// stw r27,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r27.u32);
	// li r9,256
	ctx.r9.s64 = 256;
	// lwz r8,0(r25)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// lis r28,120
	ctx.r28.s64 = 7864320;
	// stw r31,28(r25)
	PPC_STORE_U32(ctx.r25.u32 + 28, ctx.r31.u32);
	// stw r31,32(r25)
	PPC_STORE_U32(ctx.r25.u32 + 32, ctx.r31.u32);
	// li r7,15
	ctx.r7.s64 = 15;
	// stw r28,8(r25)
	PPC_STORE_U32(ctx.r25.u32 + 8, ctx.r28.u32);
	// lis r6,-30706
	ctx.r6.s64 = -2012348416;
	// stw r11,12(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12, ctx.r11.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stw r10,48(r25)
	PPC_STORE_U32(ctx.r25.u32 + 48, ctx.r10.u32);
	// addi r4,r6,2064
	ctx.r4.s64 = ctx.r6.s64 + 2064;
	// stw r9,52(r25)
	PPC_STORE_U32(ctx.r25.u32 + 52, ctx.r9.u32);
	// lwz r11,2304(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2304);
	// lwz r3,36(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// stw r31,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r31.u32);
	// stw r7,88(r11)
	PPC_STORE_U32(ctx.r11.u32 + 88, ctx.r7.u32);
	// bl 0x88096cb8
	ctx.lr = 0x880E2CCC;
	sub_88096CB8(ctx, base);
	// lis r10,192
	ctx.r10.s64 = 12582912;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// lis r9,-30680
	ctx.r9.s64 = -2010644480;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r11,168(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 168);
	// addi r4,r9,-19632
	ctx.r4.s64 = ctx.r9.s64 + -19632;
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r8,44(r25)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r25.u32 + 44);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r10,184(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 184);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r7,r11,9
	ctx.r7.s64 = ctx.r11.s64 + 9;
	// bl 0x880e1768
	ctx.lr = 0x880E2D04;
	sub_880E1768(ctx, base);
	// lis r8,-30679
	ctx.r8.s64 = -2010578944;
	// lis r7,-30643
	ctx.r7.s64 = -2008219648;
	// addi r6,r8,-15272
	ctx.r6.s64 = ctx.r8.s64 + -15272;
	// li r11,4
	ctx.r11.s64 = 4;
	// addi r5,r7,32248
	ctx.r5.s64 = ctx.r7.s64 + 32248;
	// li r4,320
	ctx.r4.s64 = 320;
	// stw r11,32248(r7)
	PPC_STORE_U32(ctx.r7.u32 + 32248, ctx.r11.u32);
	// stw r31,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r31.u32);
	// lwz r11,16(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// stw r11,16(r5)
	PPC_STORE_U32(ctx.r5.u32 + 16, ctx.r11.u32);
	// lwz r3,0(r25)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r10,6864(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 6864);
	// stw r4,76(r11)
	PPC_STORE_U32(ctx.r11.u32 + 76, ctx.r4.u32);
	// stw r27,80(r11)
	PPC_STORE_U32(ctx.r11.u32 + 80, ctx.r27.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880e2d50
	if (ctx.cr6.eq) goto loc_880E2D50;
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// bne cr6,0x880e2d64
	if (!ctx.cr6.eq) goto loc_880E2D64;
loc_880E2D50:
	// lis r10,-30706
	ctx.r10.s64 = -2012348416;
	// lwz r3,36(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,3176
	ctx.r4.s64 = ctx.r10.s64 + 3176;
	// bl 0x88096cb8
	ctx.lr = 0x880E2D64;
	sub_88096CB8(ctx, base);
loc_880E2D64:
	// lis r11,-30706
	ctx.r11.s64 = -2012348416;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r5,r11,10392
	ctx.r5.s64 = ctx.r11.s64 + 10392;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096c60
	ctx.lr = 0x880E2D78;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E2D84"))) PPC_WEAK_FUNC(sub_880E2D84);
PPC_FUNC_IMPL(__imp__sub_880E2D84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E2D88"))) PPC_WEAK_FUNC(sub_880E2D88);
PPC_FUNC_IMPL(__imp__sub_880E2D88) {
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
	// lwz r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880e2dfc
	if (ctx.cr6.eq) goto loc_880E2DFC;
	// lwz r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// add. r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// bgt 0x880e2df0
	if (ctx.cr0.gt) goto loc_880E2DF0;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r6,50
	ctx.r6.s64 = 50;
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// li r5,60
	ctx.r5.s64 = 60;
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// li r4,122
	ctx.r4.s64 = 122;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x880e32d0
	ctx.lr = 0x880E2DDC;
	sub_880E32D0(ctx, base);
	// lis r11,-30706
	ctx.r11.s64 = -2012348416;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r4,r11,10936
	ctx.r4.s64 = ctx.r11.s64 + 10936;
	// bl 0x88096cb8
	ctx.lr = 0x880E2DF0;
	sub_88096CB8(ctx, base);
loc_880E2DF0:
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r11,-6553
	ctx.r11.s64 = ctx.r11.s64 + -6553;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
loc_880E2DFC:
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

__attribute__((alias("__imp__sub_880E2E10"))) PPC_WEAK_FUNC(sub_880E2E10);
PPC_FUNC_IMPL(__imp__sub_880E2E10) {
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
	// addi r10,r11,9004
	ctx.r10.s64 = ctx.r11.s64 + 9004;
	// addi r9,r11,9008
	ctx.r9.s64 = ctx.r11.s64 + 9008;
	// stw r6,9008(r11)
	PPC_STORE_U32(ctx.r11.u32 + 9008, ctx.r6.u32);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// lis r5,-30706
	ctx.r5.s64 = -2012348416;
	// stw r7,9004(r11)
	PPC_STORE_U32(ctx.r11.u32 + 9004, ctx.r7.u32);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r5,-12656
	ctx.r5.s64 = ctx.r5.s64 + -12656;
	// li r4,30
	ctx.r4.s64 = 30;
	// bl 0x88096460
	ctx.lr = 0x880E2E6C;
	sub_88096460(ctx, base);
	// lis r4,-30641
	ctx.r4.s64 = -2008088576;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r10,r4,-18908
	ctx.r10.s64 = ctx.r4.s64 + -18908;
	// lis r9,-30706
	ctx.r9.s64 = -2012348416;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r9,-1312
	ctx.r5.s64 = ctx.r9.s64 + -1312;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// bl 0x88096c60
	ctx.lr = 0x880E2E90;
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

__attribute__((alias("__imp__sub_880E2EAC"))) PPC_WEAK_FUNC(sub_880E2EAC);
PPC_FUNC_IMPL(__imp__sub_880E2EAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E2EB0"))) PPC_WEAK_FUNC(sub_880E2EB0);
PPC_FUNC_IMPL(__imp__sub_880E2EB0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880E2EB8;
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
	ctx.lr = 0x880E2ED8;
	sub_88096BC8(ctx, base);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mulli r11,r10,372
	ctx.r11.s64 = ctx.r10.s64 * 372;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r7,r11,100
	ctx.r7.s64 = ctx.r11.s64 + 100;
	// bne cr6,0x880e2f10
	if (!ctx.cr6.eq) goto loc_880E2F10;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26428(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26428);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x880e2f28
	if (!ctx.cr6.eq) goto loc_880E2F28;
	// li r5,1
	ctx.r5.s64 = 1;
	// b 0x880e2f14
	goto loc_880E2F14;
loc_880E2F10:
	// li r5,4
	ctx.r5.s64 = 4;
loc_880E2F14:
	// lwz r4,88(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 88);
	// lwz r3,40(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 40);
	// bl 0x88153010
	ctx.lr = 0x880E2F20;
	sub_88153010(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// stw r11,88(r7)
	PPC_STORE_U32(ctx.r7.u32 + 88, ctx.r11.u32);
loc_880E2F28:
	// lwz r11,88(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 88);
	// lwz r10,40(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 40);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x880e2f50
	if (!ctx.cr6.eq) goto loc_880E2F50;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096b40
	ctx.lr = 0x880E2F44;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_880E2F50:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E2F5C"))) PPC_WEAK_FUNC(sub_880E2F5C);
PPC_FUNC_IMPL(__imp__sub_880E2F5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E2F60"))) PPC_WEAK_FUNC(sub_880E2F60);
PPC_FUNC_IMPL(__imp__sub_880E2F60) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880E2F68;
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
	ctx.lr = 0x880E2F88;
	sub_88096BC8(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x880e2ff0
	if (!ctx.cr6.eq) goto loc_880E2FF0;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// bge 0x880e2ff0
	if (!ctx.cr0.lt) goto loc_880E2FF0;
	// mulli r11,r11,372
	ctx.r11.s64 = ctx.r11.s64 * 372;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lwz r10,220(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 220);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,220(r11)
	PPC_STORE_U32(ctx.r11.u32 + 220, ctx.r10.u32);
	// cmpwi cr6,r10,6
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 6, ctx.xer);
	// blt cr6,0x880e2ff0
	if (ctx.cr6.lt) goto loc_880E2FF0;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r10,220(r11)
	PPC_STORE_U32(ctx.r11.u32 + 220, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r10,224(r11)
	PPC_STORE_U32(ctx.r11.u32 + 224, ctx.r10.u32);
	// bl 0x88096b40
	ctx.lr = 0x880E2FE4;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_880E2FF0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E2FFC"))) PPC_WEAK_FUNC(sub_880E2FFC);
PPC_FUNC_IMPL(__imp__sub_880E2FFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3000"))) PPC_WEAK_FUNC(sub_880E3000);
PPC_FUNC_IMPL(__imp__sub_880E3000) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880E3008;
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
	// li r5,96
	ctx.r5.s64 = 96;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880E3028;
	sub_88096BC8(ctx, base);
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r9,-30706
	ctx.r9.s64 = -2012348416;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r9,11952
	ctx.r5.s64 = ctx.r9.s64 + 11952;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// lwz r8,4(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// stw r8,40(r10)
	PPC_STORE_U32(ctx.r10.u32 + 40, ctx.r8.u32);
	// bl 0x88096c60
	ctx.lr = 0x880E3050;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E305C"))) PPC_WEAK_FUNC(sub_880E305C);
PPC_FUNC_IMPL(__imp__sub_880E305C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3060"))) PPC_WEAK_FUNC(sub_880E3060);
PPC_FUNC_IMPL(__imp__sub_880E3060) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880E3064"))) PPC_WEAK_FUNC(sub_880E3064);
PPC_FUNC_IMPL(__imp__sub_880E3064) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3068"))) PPC_WEAK_FUNC(sub_880E3068);
PPC_FUNC_IMPL(__imp__sub_880E3068) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880E306C"))) PPC_WEAK_FUNC(sub_880E306C);
PPC_FUNC_IMPL(__imp__sub_880E306C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3070"))) PPC_WEAK_FUNC(sub_880E3070);
PPC_FUNC_IMPL(__imp__sub_880E3070) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880E3074"))) PPC_WEAK_FUNC(sub_880E3074);
PPC_FUNC_IMPL(__imp__sub_880E3074) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3078"))) PPC_WEAK_FUNC(sub_880E3078);
PPC_FUNC_IMPL(__imp__sub_880E3078) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880E307C"))) PPC_WEAK_FUNC(sub_880E307C);
PPC_FUNC_IMPL(__imp__sub_880E307C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3080"))) PPC_WEAK_FUNC(sub_880E3080);
PPC_FUNC_IMPL(__imp__sub_880E3080) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880E3088;
	__savegprlr_29(ctx, base);
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
loc_880E308C:
	// lwz r10,-19564(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -19564);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x880e308c
	if (!ctx.cr6.eq) goto loc_880E308C;
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// li r8,128
	ctx.r8.s64 = 128;
	// addi r11,r11,-19564
	ctx.r11.s64 = ctx.r11.s64 + -19564;
	// rlwinm r5,r8,1,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0x1;
	// addi r6,r11,4
	ctx.r6.s64 = ctx.r11.s64 + 4;
	// addi r31,r3,3
	ctx.r31.s64 = ctx.r3.s64 + 3;
	// addi r30,r3,73
	ctx.r30.s64 = ctx.r3.s64 + 73;
	// lwz r10,-4824(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -4824);
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r29,r11,-12
	ctx.r29.s64 = ctx.r11.s64 + -12;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// add r10,r7,r6
	ctx.r10.u64 = ctx.r7.u64 + ctx.r6.u64;
	// rlwinm r7,r9,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1;
	// subfc r8,r8,r9
	ctx.xer.ca = ctx.r9.u32 >= ctx.r8.u32;
	ctx.r8.s64 = ctx.r9.s64 - ctx.r8.s64;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// subfe r8,r7,r5
	temp.u8 = (~ctx.r7.u32 + ctx.r5.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r5.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r7.u64 + ctx.r5.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwinm r3,r3,2,22,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x3FC;
	// stb r4,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, ctx.r4.u8);
	// stb r31,4(r10)
	PPC_STORE_U8(ctx.r10.u32 + 4, ctx.r31.u8);
	// li r7,1
	ctx.r7.s64 = 1;
	// stb r30,3(r10)
	PPC_STORE_U8(ctx.r10.u32 + 3, ctx.r30.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r6,2(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2, ctx.r6.u8);
	// and r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 & ctx.r9.u64;
	// stw r7,648(r11)
	PPC_STORE_U32(ctx.r11.u32 + 648, ctx.r7.u32);
	// stwx r5,r3,r29
	PPC_STORE_U32(ctx.r3.u32 + ctx.r29.u32, ctx.r5.u32);
	// stw r5,648(r11)
	PPC_STORE_U32(ctx.r11.u32 + 648, ctx.r5.u32);
	// stw r10,-4824(r11)
	PPC_STORE_U32(ctx.r11.u32 + -4824, ctx.r10.u32);
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3114"))) PPC_WEAK_FUNC(sub_880E3114);
PPC_FUNC_IMPL(__imp__sub_880E3114) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3118"))) PPC_WEAK_FUNC(sub_880E3118);
PPC_FUNC_IMPL(__imp__sub_880E3118) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880E311C"))) PPC_WEAK_FUNC(sub_880E311C);
PPC_FUNC_IMPL(__imp__sub_880E311C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3120"))) PPC_WEAK_FUNC(sub_880E3120);
PPC_FUNC_IMPL(__imp__sub_880E3120) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880E3124"))) PPC_WEAK_FUNC(sub_880E3124);
PPC_FUNC_IMPL(__imp__sub_880E3124) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3128"))) PPC_WEAK_FUNC(sub_880E3128);
PPC_FUNC_IMPL(__imp__sub_880E3128) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// lis r7,-30641
	ctx.r7.s64 = -2008088576;
	// addi r11,r11,-19564
	ctx.r11.s64 = ctx.r11.s64 + -19564;
	// addi r8,r11,4
	ctx.r8.s64 = ctx.r11.s64 + 4;
	// lwz r9,-4824(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + -4824);
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
loc_880E3150:
	// lwz r8,-19564(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + -19564);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x880e3150
	if (!ctx.cr6.eq) goto loc_880E3150;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stb r3,4(r10)
	PPC_STORE_U8(ctx.r10.u32 + 4, ctx.r3.u8);
	// li r8,128
	ctx.r8.s64 = 128;
	// stb r4,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r4.u8);
	// rlwinm r7,r9,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1;
	// stb r5,2(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2, ctx.r5.u8);
	// subfc r31,r8,r9
	ctx.xer.ca = ctx.r9.u32 >= ctx.r8.u32;
	ctx.r31.s64 = ctx.r9.s64 - ctx.r8.s64;
	// stb r6,3(r10)
	PPC_STORE_U8(ctx.r10.u32 + 3, ctx.r6.u8);
	// rlwinm r8,r8,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0x1;
	// li r30,1
	ctx.r30.s64 = 1;
	// subfe r7,r7,r8
	temp.u8 = (~ctx.r7.u32 + ctx.r8.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r7.u64 = ~ctx.r7.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// li r3,3
	ctx.r3.s64 = 3;
	// stw r30,648(r11)
	PPC_STORE_U32(ctx.r11.u32 + 648, ctx.r30.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// and r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 & ctx.r9.u64;
	// stb r3,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, ctx.r3.u8);
	// stw r8,648(r11)
	PPC_STORE_U32(ctx.r11.u32 + 648, ctx.r8.u32);
	// stw r9,-4824(r11)
	PPC_STORE_U32(ctx.r11.u32 + -4824, ctx.r9.u32);
	// ld r30,-16(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880E31B0"))) PPC_WEAK_FUNC(sub_880E31B0);
PPC_FUNC_IMPL(__imp__sub_880E31B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// lis r7,-30641
	ctx.r7.s64 = -2008088576;
	// addi r11,r11,-19564
	ctx.r11.s64 = ctx.r11.s64 + -19564;
	// addi r8,r11,4
	ctx.r8.s64 = ctx.r11.s64 + 4;
	// lwz r9,-4824(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + -4824);
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
loc_880E31D8:
	// lwz r8,-19564(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + -19564);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x880e31d8
	if (!ctx.cr6.eq) goto loc_880E31D8;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stb r3,4(r10)
	PPC_STORE_U8(ctx.r10.u32 + 4, ctx.r3.u8);
	// li r8,128
	ctx.r8.s64 = 128;
	// stb r4,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r4.u8);
	// rlwinm r7,r9,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1;
	// stb r5,2(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2, ctx.r5.u8);
	// subfc r31,r8,r9
	ctx.xer.ca = ctx.r9.u32 >= ctx.r8.u32;
	ctx.r31.s64 = ctx.r9.s64 - ctx.r8.s64;
	// stb r6,3(r10)
	PPC_STORE_U8(ctx.r10.u32 + 3, ctx.r6.u8);
	// rlwinm r8,r8,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0x1;
	// li r3,2
	ctx.r3.s64 = 2;
	// subfe r7,r7,r8
	temp.u8 = (~ctx.r7.u32 + ctx.r8.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r7.u64 = ~ctx.r7.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// li r30,1
	ctx.r30.s64 = 1;
	// stb r3,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, ctx.r3.u8);
	// li r8,0
	ctx.r8.s64 = 0;
	// and r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 & ctx.r9.u64;
	// stw r30,648(r11)
	PPC_STORE_U32(ctx.r11.u32 + 648, ctx.r30.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r8,648(r11)
	PPC_STORE_U32(ctx.r11.u32 + 648, ctx.r8.u32);
	// stw r9,-4824(r11)
	PPC_STORE_U32(ctx.r11.u32 + -4824, ctx.r9.u32);
	// ld r30,-16(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880E323C"))) PPC_WEAK_FUNC(sub_880E323C);
PPC_FUNC_IMPL(__imp__sub_880E323C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3240"))) PPC_WEAK_FUNC(sub_880E3240);
PPC_FUNC_IMPL(__imp__sub_880E3240) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// lis r7,-30641
	ctx.r7.s64 = -2008088576;
	// addi r11,r11,-19564
	ctx.r11.s64 = ctx.r11.s64 + -19564;
	// addi r8,r11,4
	ctx.r8.s64 = ctx.r11.s64 + 4;
	// lwz r9,-4824(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + -4824);
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
loc_880E3268:
	// lwz r8,-19564(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + -19564);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x880e3268
	if (!ctx.cr6.eq) goto loc_880E3268;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stb r3,4(r10)
	PPC_STORE_U8(ctx.r10.u32 + 4, ctx.r3.u8);
	// li r8,128
	ctx.r8.s64 = 128;
	// stb r4,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r4.u8);
	// rlwinm r31,r9,1,31,31
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1;
	// stb r6,3(r10)
	PPC_STORE_U8(ctx.r10.u32 + 3, ctx.r6.u8);
	// subfc r30,r8,r9
	ctx.xer.ca = ctx.r9.u32 >= ctx.r8.u32;
	ctx.r30.s64 = ctx.r9.s64 - ctx.r8.s64;
	// rlwinm r8,r8,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0x1;
	// li r7,1
	ctx.r7.s64 = 1;
	// subfe r8,r31,r8
	temp.u8 = (~ctx.r31.u32 + ctx.r8.u32 < ~ctx.r31.u32) | (~ctx.r31.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r31.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r7,648(r11)
	PPC_STORE_U32(ctx.r11.u32 + 648, ctx.r7.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r7,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, ctx.r7.u8);
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// and r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 & ctx.r9.u64;
	// stb r7,2(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2, ctx.r7.u8);
	// stw r5,648(r11)
	PPC_STORE_U32(ctx.r11.u32 + 648, ctx.r5.u32);
	// stw r9,-4824(r11)
	PPC_STORE_U32(ctx.r11.u32 + -4824, ctx.r9.u32);
	// ld r30,-16(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880E32CC"))) PPC_WEAK_FUNC(sub_880E32CC);
PPC_FUNC_IMPL(__imp__sub_880E32CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E32D0"))) PPC_WEAK_FUNC(sub_880E32D0);
PPC_FUNC_IMPL(__imp__sub_880E32D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// lis r7,-30641
	ctx.r7.s64 = -2008088576;
	// addi r11,r11,-19564
	ctx.r11.s64 = ctx.r11.s64 + -19564;
	// addi r8,r11,4
	ctx.r8.s64 = ctx.r11.s64 + 4;
	// lwz r9,-4824(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + -4824);
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
loc_880E32F8:
	// lwz r8,-19564(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + -19564);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x880e32f8
	if (!ctx.cr6.eq) goto loc_880E32F8;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stb r3,4(r10)
	PPC_STORE_U8(ctx.r10.u32 + 4, ctx.r3.u8);
	// li r8,128
	ctx.r8.s64 = 128;
	// stb r4,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r4.u8);
	// rlwinm r7,r9,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1;
	// stb r5,2(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2, ctx.r5.u8);
	// subfc r31,r8,r9
	ctx.xer.ca = ctx.r9.u32 >= ctx.r8.u32;
	ctx.r31.s64 = ctx.r9.s64 - ctx.r8.s64;
	// stb r6,3(r10)
	PPC_STORE_U8(ctx.r10.u32 + 3, ctx.r6.u8);
	// rlwinm r8,r8,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0x1;
	// li r30,1
	ctx.r30.s64 = 1;
	// subfe r8,r7,r8
	temp.u8 = (~ctx.r7.u32 + ctx.r8.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r7.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r30,648(r11)
	PPC_STORE_U32(ctx.r11.u32 + 648, ctx.r30.u32);
	// and r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 & ctx.r9.u64;
	// stb r7,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, ctx.r7.u8);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r7,648(r11)
	PPC_STORE_U32(ctx.r11.u32 + 648, ctx.r7.u32);
	// stw r9,-4824(r11)
	PPC_STORE_U32(ctx.r11.u32 + -4824, ctx.r9.u32);
	// ld r30,-16(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880E3358"))) PPC_WEAK_FUNC(sub_880E3358);
PPC_FUNC_IMPL(__imp__sub_880E3358) {
	PPC_FUNC_PROLOGUE();
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r31,1
	ctx.r31.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r11,23632
	ctx.r11.s64 = ctx.r11.s64 + 23632;
loc_880E3378:
	// rlwinm r8,r31,1,28,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xE;
	// clrlwi r10,r31,29
	ctx.r10.u64 = ctx.r31.u32 & 0x7;
	// addi r7,r11,4
	ctx.r7.s64 = ctx.r11.s64 + 4;
	// add r6,r10,r8
	ctx.r6.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r4,r6,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r8,r4,r7
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r7.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x880e33c4
	if (!ctx.cr6.eq) goto loc_880E33C4;
	// rlwinm r7,r10,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r6,r11,-16944
	ctx.r6.s64 = ctx.r11.s64 + -16944;
	// addi r8,r11,-16944
	ctx.r8.s64 = ctx.r11.s64 + -16944;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// addi r4,r11,-16944
	ctx.r4.s64 = ctx.r11.s64 + -16944;
	// rlwinm r7,r7,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// addi r8,r8,8
	ctx.r8.s64 = ctx.r8.s64 + 8;
	// stwx r9,r7,r4
	PPC_STORE_U32(ctx.r7.u32 + ctx.r4.u32, ctx.r9.u32);
	// stwx r9,r7,r6
	PPC_STORE_U32(ctx.r7.u32 + ctx.r6.u32, ctx.r9.u32);
	// stwx r9,r7,r8
	PPC_STORE_U32(ctx.r7.u32 + ctx.r8.u32, ctx.r9.u32);
loc_880E33C4:
	// rlwinm r7,r10,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r8,r11,-16944
	ctx.r8.s64 = ctx.r11.s64 + -16944;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplw cr6,r8,r30
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x880e33f0
	if (!ctx.cr6.eq) goto loc_880E33F0;
	// lwz r10,8(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplw cr6,r5,r10
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x880e3584
	if (!ctx.cr6.lt) goto loc_880E3584;
loc_880E33F0:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmpwi cr6,r31,8
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 8, ctx.xer);
	// blt cr6,0x880e3378
	if (ctx.cr6.lt) goto loc_880E3378;
	// rlwinm r8,r3,1,28,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xE;
	// clrlwi r10,r3,29
	ctx.r10.u64 = ctx.r3.u32 & 0x7;
	// addi r7,r11,4
	ctx.r7.s64 = ctx.r11.s64 + 4;
	// add r6,r10,r8
	ctx.r6.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r4,r6,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r8,r4,r7
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r7.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x880e3448
	if (!ctx.cr6.eq) goto loc_880E3448;
	// rlwinm r6,r10,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r7,r11,-16944
	ctx.r7.s64 = ctx.r11.s64 + -16944;
	// addi r8,r11,-16944
	ctx.r8.s64 = ctx.r11.s64 + -16944;
	// add r6,r10,r6
	ctx.r6.u64 = ctx.r10.u64 + ctx.r6.u64;
	// addi r4,r11,-16944
	ctx.r4.s64 = ctx.r11.s64 + -16944;
	// rlwinm r6,r6,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// addi r8,r8,8
	ctx.r8.s64 = ctx.r8.s64 + 8;
	// stwx r9,r6,r4
	PPC_STORE_U32(ctx.r6.u32 + ctx.r4.u32, ctx.r9.u32);
	// stwx r9,r6,r7
	PPC_STORE_U32(ctx.r6.u32 + ctx.r7.u32, ctx.r9.u32);
	// stwx r9,r6,r8
	PPC_STORE_U32(ctx.r6.u32 + ctx.r8.u32, ctx.r9.u32);
loc_880E3448:
	// rlwinm r7,r10,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r8,r11,-16944
	ctx.r8.s64 = ctx.r11.s64 + -16944;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x880e3578
	if (ctx.cr6.eq) goto loc_880E3578;
	// lwz r8,8(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplw cr6,r5,r8
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x880e3578
	if (!ctx.cr6.lt) goto loc_880E3578;
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplw cr6,r10,r30
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x880e3578
	if (ctx.cr6.eq) goto loc_880E3578;
	// li r3,1
	ctx.r3.s64 = 1;
loc_880E3484:
	// rlwinm r8,r3,1,28,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xE;
	// clrlwi r10,r3,29
	ctx.r10.u64 = ctx.r3.u32 & 0x7;
	// addi r7,r11,4
	ctx.r7.s64 = ctx.r11.s64 + 4;
	// add r6,r10,r8
	ctx.r6.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r4,r6,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r8,r4,r7
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r7.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x880e34d0
	if (!ctx.cr6.eq) goto loc_880E34D0;
	// rlwinm r6,r10,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r7,r11,-16944
	ctx.r7.s64 = ctx.r11.s64 + -16944;
	// addi r8,r11,-16944
	ctx.r8.s64 = ctx.r11.s64 + -16944;
	// add r6,r10,r6
	ctx.r6.u64 = ctx.r10.u64 + ctx.r6.u64;
	// addi r4,r11,-16944
	ctx.r4.s64 = ctx.r11.s64 + -16944;
	// rlwinm r6,r6,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// addi r8,r8,8
	ctx.r8.s64 = ctx.r8.s64 + 8;
	// stwx r9,r6,r4
	PPC_STORE_U32(ctx.r6.u32 + ctx.r4.u32, ctx.r9.u32);
	// stwx r9,r6,r7
	PPC_STORE_U32(ctx.r6.u32 + ctx.r7.u32, ctx.r9.u32);
	// stwx r9,r6,r8
	PPC_STORE_U32(ctx.r6.u32 + ctx.r8.u32, ctx.r9.u32);
loc_880E34D0:
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r7,r11,-16944
	ctx.r7.s64 = ctx.r11.s64 + -16944;
	// add r6,r10,r8
	ctx.r6.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r4,r6,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r4,r7
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r7.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880e3578
	if (ctx.cr6.eq) goto loc_880E3578;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// cmpwi cr6,r3,8
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 8, ctx.xer);
	// blt cr6,0x880e3484
	if (ctx.cr6.lt) goto loc_880E3484;
	// li r3,1
	ctx.r3.s64 = 1;
loc_880E34FC:
	// rlwinm r8,r3,1,28,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xE;
	// clrlwi r10,r3,29
	ctx.r10.u64 = ctx.r3.u32 & 0x7;
	// addi r7,r11,4
	ctx.r7.s64 = ctx.r11.s64 + 4;
	// add r6,r10,r8
	ctx.r6.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r4,r6,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r8,r4,r7
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r7.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x880e3548
	if (!ctx.cr6.eq) goto loc_880E3548;
	// rlwinm r6,r10,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r7,r11,-16944
	ctx.r7.s64 = ctx.r11.s64 + -16944;
	// addi r8,r11,-16944
	ctx.r8.s64 = ctx.r11.s64 + -16944;
	// add r6,r10,r6
	ctx.r6.u64 = ctx.r10.u64 + ctx.r6.u64;
	// addi r4,r11,-16944
	ctx.r4.s64 = ctx.r11.s64 + -16944;
	// rlwinm r6,r6,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// addi r8,r8,8
	ctx.r8.s64 = ctx.r8.s64 + 8;
	// stwx r9,r6,r4
	PPC_STORE_U32(ctx.r6.u32 + ctx.r4.u32, ctx.r9.u32);
	// stwx r9,r6,r7
	PPC_STORE_U32(ctx.r6.u32 + ctx.r7.u32, ctx.r9.u32);
	// stwx r9,r6,r8
	PPC_STORE_U32(ctx.r6.u32 + ctx.r8.u32, ctx.r9.u32);
loc_880E3548:
	// rlwinm r7,r10,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r8,r11,-16944
	ctx.r8.s64 = ctx.r11.s64 + -16944;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// addi r8,r8,8
	ctx.r8.s64 = ctx.r8.s64 + 8;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r7,r8
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// cmplw cr6,r5,r6
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r6.u32, ctx.xer);
	// bgt cr6,0x880e3578
	if (ctx.cr6.gt) goto loc_880E3578;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// cmpwi cr6,r3,8
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 8, ctx.xer);
	// blt cr6,0x880e34fc
	if (ctx.cr6.lt) goto loc_880E34FC;
	// li r3,0
	ctx.r3.s64 = 0;
loc_880E3578:
	// ld r30,-16(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_880E3584:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// ld r30,-16(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880E3594"))) PPC_WEAK_FUNC(sub_880E3594);
PPC_FUNC_IMPL(__imp__sub_880E3594) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3598"))) PPC_WEAK_FUNC(sub_880E3598);
PPC_FUNC_IMPL(__imp__sub_880E3598) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880E35A0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// clrlwi r3,r4,24
	ctx.r3.u64 = ctx.r4.u32 & 0xFF;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// bl 0x88093680
	ctx.lr = 0x880E35B8;
	sub_88093680(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880e35d0
	if (!ctx.cr6.eq) goto loc_880E35D0;
loc_880E35C4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_880E35D0:
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x880e35c4
	if (!ctx.cr6.lt) goto loc_880E35C4;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x880e35c4
	if (ctx.cr6.eq) goto loc_880E35C4;
	// li r31,1
	ctx.r31.s64 = 1;
loc_880E35EC:
	// clrlwi r3,r31,24
	ctx.r3.u64 = ctx.r31.u32 & 0xFF;
	// bl 0x88093680
	ctx.lr = 0x880E35F4;
	sub_88093680(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x880e360c
	if (!ctx.cr6.eq) goto loc_880E360C;
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x880e35c4
	if (!ctx.cr6.lt) goto loc_880E35C4;
loc_880E360C:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmpwi cr6,r31,8
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 8, ctx.xer);
	// blt cr6,0x880e35ec
	if (ctx.cr6.lt) goto loc_880E35EC;
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// li r3,1
	ctx.r3.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r11,23632
	ctx.r11.s64 = ctx.r11.s64 + 23632;
loc_880E3628:
	// clrlwi r10,r3,29
	ctx.r10.u64 = ctx.r3.u32 & 0x7;
	// rlwinm r8,r3,1,28,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xE;
	// addi r7,r11,4
	ctx.r7.s64 = ctx.r11.s64 + 4;
	// add r6,r10,r8
	ctx.r6.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r5,r6,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r4,r5,r7
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r7.u32);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne cr6,0x880e3674
	if (!ctx.cr6.eq) goto loc_880E3674;
	// rlwinm r6,r10,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r7,r11,-16944
	ctx.r7.s64 = ctx.r11.s64 + -16944;
	// add r6,r10,r6
	ctx.r6.u64 = ctx.r10.u64 + ctx.r6.u64;
	// addi r8,r11,-16944
	ctx.r8.s64 = ctx.r11.s64 + -16944;
	// rlwinm r4,r6,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r5,r11,-16944
	ctx.r5.s64 = ctx.r11.s64 + -16944;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// addi r6,r8,8
	ctx.r6.s64 = ctx.r8.s64 + 8;
	// stwx r9,r4,r5
	PPC_STORE_U32(ctx.r4.u32 + ctx.r5.u32, ctx.r9.u32);
	// stwx r9,r4,r7
	PPC_STORE_U32(ctx.r4.u32 + ctx.r7.u32, ctx.r9.u32);
	// stwx r9,r4,r6
	PPC_STORE_U32(ctx.r4.u32 + ctx.r6.u32, ctx.r9.u32);
loc_880E3674:
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r7,r11,-16944
	ctx.r7.s64 = ctx.r11.s64 + -16944;
	// add r6,r10,r8
	ctx.r6.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r5,r7
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r7.u32);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x880e371c
	if (ctx.cr6.eq) goto loc_880E371C;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// cmpwi cr6,r3,8
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 8, ctx.xer);
	// blt cr6,0x880e3628
	if (ctx.cr6.lt) goto loc_880E3628;
	// li r3,1
	ctx.r3.s64 = 1;
loc_880E36A0:
	// clrlwi r10,r3,29
	ctx.r10.u64 = ctx.r3.u32 & 0x7;
	// rlwinm r8,r3,1,28,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xE;
	// addi r7,r11,4
	ctx.r7.s64 = ctx.r11.s64 + 4;
	// add r6,r10,r8
	ctx.r6.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r5,r6,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r4,r5,r7
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r7.u32);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne cr6,0x880e36ec
	if (!ctx.cr6.eq) goto loc_880E36EC;
	// rlwinm r6,r10,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r7,r11,-16944
	ctx.r7.s64 = ctx.r11.s64 + -16944;
	// add r6,r10,r6
	ctx.r6.u64 = ctx.r10.u64 + ctx.r6.u64;
	// addi r8,r11,-16944
	ctx.r8.s64 = ctx.r11.s64 + -16944;
	// rlwinm r4,r6,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r5,r11,-16944
	ctx.r5.s64 = ctx.r11.s64 + -16944;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// addi r6,r8,8
	ctx.r6.s64 = ctx.r8.s64 + 8;
	// stwx r9,r4,r5
	PPC_STORE_U32(ctx.r4.u32 + ctx.r5.u32, ctx.r9.u32);
	// stwx r9,r4,r7
	PPC_STORE_U32(ctx.r4.u32 + ctx.r7.u32, ctx.r9.u32);
	// stwx r9,r4,r6
	PPC_STORE_U32(ctx.r4.u32 + ctx.r6.u32, ctx.r9.u32);
loc_880E36EC:
	// rlwinm r7,r10,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r8,r11,-16944
	ctx.r8.s64 = ctx.r11.s64 + -16944;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// addi r8,r8,8
	ctx.r8.s64 = ctx.r8.s64 + 8;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r7,r8
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// cmplw cr6,r29,r6
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r6.u32, ctx.xer);
	// bgt cr6,0x880e371c
	if (ctx.cr6.gt) goto loc_880E371C;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// cmpwi cr6,r3,8
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 8, ctx.xer);
	// blt cr6,0x880e36a0
	if (ctx.cr6.lt) goto loc_880E36A0;
	// li r3,0
	ctx.r3.s64 = 0;
loc_880E371C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3724"))) PPC_WEAK_FUNC(sub_880E3724);
PPC_FUNC_IMPL(__imp__sub_880E3724) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3728"))) PPC_WEAK_FUNC(sub_880E3728);
PPC_FUNC_IMPL(__imp__sub_880E3728) {
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
	// clrlwi r3,r3,24
	ctx.r3.u64 = ctx.r3.u32 & 0xFF;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x88093680
	ctx.lr = 0x880E374C;
	sub_88093680(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880e3760
	if (!ctx.cr6.eq) goto loc_880E3760;
loc_880E3758:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x880e381c
	goto loc_880E381C;
loc_880E3760:
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x880e3758
	if (ctx.cr6.gt) goto loc_880E3758;
	// li r31,1
	ctx.r31.s64 = 1;
loc_880E3770:
	// clrlwi r3,r31,24
	ctx.r3.u64 = ctx.r31.u32 & 0xFF;
	// bl 0x88093680
	ctx.lr = 0x880E3778;
	sub_88093680(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880e3758
	if (ctx.cr6.eq) goto loc_880E3758;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmpwi cr6,r31,8
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 8, ctx.xer);
	// blt cr6,0x880e3770
	if (ctx.cr6.lt) goto loc_880E3770;
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// li r3,1
	ctx.r3.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r11,r11,23632
	ctx.r11.s64 = ctx.r11.s64 + 23632;
loc_880E37A0:
	// clrlwi r10,r3,29
	ctx.r10.u64 = ctx.r3.u32 & 0x7;
	// rlwinm r9,r3,1,28,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xE;
	// addi r8,r11,4
	ctx.r8.s64 = ctx.r11.s64 + 4;
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r5,r7,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r4,r5,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r8.u32);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne cr6,0x880e37ec
	if (!ctx.cr6.eq) goto loc_880E37EC;
	// rlwinm r7,r10,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r8,r11,-16944
	ctx.r8.s64 = ctx.r11.s64 + -16944;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// addi r9,r11,-16944
	ctx.r9.s64 = ctx.r11.s64 + -16944;
	// rlwinm r4,r7,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r5,r11,-16944
	ctx.r5.s64 = ctx.r11.s64 + -16944;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r7,r9,8
	ctx.r7.s64 = ctx.r9.s64 + 8;
	// stwx r6,r4,r5
	PPC_STORE_U32(ctx.r4.u32 + ctx.r5.u32, ctx.r6.u32);
	// stwx r6,r4,r8
	PPC_STORE_U32(ctx.r4.u32 + ctx.r8.u32, ctx.r6.u32);
	// stwx r6,r4,r7
	PPC_STORE_U32(ctx.r4.u32 + ctx.r7.u32, ctx.r6.u32);
loc_880E37EC:
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r9,r11,-16944
	ctx.r9.s64 = ctx.r11.s64 + -16944;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// cmplw cr6,r30,r7
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r7.u32, ctx.xer);
	// bgt cr6,0x880e381c
	if (ctx.cr6.gt) goto loc_880E381C;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// cmpwi cr6,r3,8
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 8, ctx.xer);
	// blt cr6,0x880e37a0
	if (ctx.cr6.lt) goto loc_880E37A0;
	// li r3,0
	ctx.r3.s64 = 0;
loc_880E381C:
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

__attribute__((alias("__imp__sub_880E3834"))) PPC_WEAK_FUNC(sub_880E3834);
PPC_FUNC_IMPL(__imp__sub_880E3834) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3838"))) PPC_WEAK_FUNC(sub_880E3838);
PPC_FUNC_IMPL(__imp__sub_880E3838) {
	PPC_FUNC_PROLOGUE();
	// lis r6,-30641
	ctx.r6.s64 = -2008088576;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r5,r6,-18916
	ctx.r5.s64 = ctx.r6.s64 + -18916;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
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
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880E3880"))) PPC_WEAK_FUNC(sub_880E3880);
PPC_FUNC_IMPL(__imp__sub_880E3880) {
	PPC_FUNC_PROLOGUE();
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x88093880
	sub_88093880(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3888"))) PPC_WEAK_FUNC(sub_880E3888);
PPC_FUNC_IMPL(__imp__sub_880E3888) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r9,r10,26432
	ctx.r9.s64 = ctx.r10.s64 + 26432;
	// lwz r10,312(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 312);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lis r8,-30628
	ctx.r8.s64 = -2007236608;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r7,r8,6688
	ctx.r7.s64 = ctx.r8.s64 + 6688;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r10,6688(r8)
	PPC_STORE_U32(ctx.r8.u32 + 6688, ctx.r10.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// lhz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r11.u32 + 0);
	// extsh r10,r5
	ctx.r10.s64 = ctx.r5.s16;
	// stw r9,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r9.u32);
	// stw r10,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r10.u32);
	// lhz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r11.u32 + 0);
	// extsh r4,r4
	ctx.r4.s64 = ctx.r4.s16;
	// lhz r11,2(r11)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r11.u32 + 2);
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// srawi r9,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 1;
	// addze r5,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r5.s64 = temp.s64;
	// b 0x88090588
	sub_88090588(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E38E8"))) PPC_WEAK_FUNC(sub_880E38E8);
PPC_FUNC_IMPL(__imp__sub_880E38E8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880E38EC"))) PPC_WEAK_FUNC(sub_880E38EC);
PPC_FUNC_IMPL(__imp__sub_880E38EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E38F0"))) PPC_WEAK_FUNC(sub_880E38F0);
PPC_FUNC_IMPL(__imp__sub_880E38F0) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,135
	ctx.r5.s64 = 135;
	// li r4,220
	ctx.r4.s64 = 220;
	// li r3,6
	ctx.r3.s64 = 6;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3904"))) PPC_WEAK_FUNC(sub_880E3904);
PPC_FUNC_IMPL(__imp__sub_880E3904) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3908"))) PPC_WEAK_FUNC(sub_880E3908);
PPC_FUNC_IMPL(__imp__sub_880E3908) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,140
	ctx.r5.s64 = 140;
	// li r4,219
	ctx.r4.s64 = 219;
	// li r3,6
	ctx.r3.s64 = 6;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E391C"))) PPC_WEAK_FUNC(sub_880E391C);
PPC_FUNC_IMPL(__imp__sub_880E391C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3920"))) PPC_WEAK_FUNC(sub_880E3920);
PPC_FUNC_IMPL(__imp__sub_880E3920) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,125
	ctx.r5.s64 = 125;
	// li r4,218
	ctx.r4.s64 = 218;
	// li r3,6
	ctx.r3.s64 = 6;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3934"))) PPC_WEAK_FUNC(sub_880E3934);
PPC_FUNC_IMPL(__imp__sub_880E3934) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3938"))) PPC_WEAK_FUNC(sub_880E3938);
PPC_FUNC_IMPL(__imp__sub_880E3938) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,125
	ctx.r5.s64 = 125;
	// li r4,217
	ctx.r4.s64 = 217;
	// li r3,6
	ctx.r3.s64 = 6;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E394C"))) PPC_WEAK_FUNC(sub_880E394C);
PPC_FUNC_IMPL(__imp__sub_880E394C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3950"))) PPC_WEAK_FUNC(sub_880E3950);
PPC_FUNC_IMPL(__imp__sub_880E3950) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,125
	ctx.r5.s64 = 125;
	// li r4,216
	ctx.r4.s64 = 216;
	// li r3,6
	ctx.r3.s64 = 6;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3964"))) PPC_WEAK_FUNC(sub_880E3964);
PPC_FUNC_IMPL(__imp__sub_880E3964) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3968"))) PPC_WEAK_FUNC(sub_880E3968);
PPC_FUNC_IMPL(__imp__sub_880E3968) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,125
	ctx.r5.s64 = 125;
	// li r4,215
	ctx.r4.s64 = 215;
	// li r3,6
	ctx.r3.s64 = 6;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E397C"))) PPC_WEAK_FUNC(sub_880E397C);
PPC_FUNC_IMPL(__imp__sub_880E397C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3980"))) PPC_WEAK_FUNC(sub_880E3980);
PPC_FUNC_IMPL(__imp__sub_880E3980) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,125
	ctx.r5.s64 = 125;
	// li r4,214
	ctx.r4.s64 = 214;
	// li r3,6
	ctx.r3.s64 = 6;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3994"))) PPC_WEAK_FUNC(sub_880E3994);
PPC_FUNC_IMPL(__imp__sub_880E3994) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3998"))) PPC_WEAK_FUNC(sub_880E3998);
PPC_FUNC_IMPL(__imp__sub_880E3998) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,140
	ctx.r5.s64 = 140;
	// li r4,213
	ctx.r4.s64 = 213;
	// li r3,6
	ctx.r3.s64 = 6;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E39AC"))) PPC_WEAK_FUNC(sub_880E39AC);
PPC_FUNC_IMPL(__imp__sub_880E39AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E39B0"))) PPC_WEAK_FUNC(sub_880E39B0);
PPC_FUNC_IMPL(__imp__sub_880E39B0) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,125
	ctx.r5.s64 = 125;
	// li r4,212
	ctx.r4.s64 = 212;
	// li r3,6
	ctx.r3.s64 = 6;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E39C4"))) PPC_WEAK_FUNC(sub_880E39C4);
PPC_FUNC_IMPL(__imp__sub_880E39C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E39C8"))) PPC_WEAK_FUNC(sub_880E39C8);
PPC_FUNC_IMPL(__imp__sub_880E39C8) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,140
	ctx.r5.s64 = 140;
	// li r4,211
	ctx.r4.s64 = 211;
	// li r3,6
	ctx.r3.s64 = 6;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E39DC"))) PPC_WEAK_FUNC(sub_880E39DC);
PPC_FUNC_IMPL(__imp__sub_880E39DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E39E0"))) PPC_WEAK_FUNC(sub_880E39E0);
PPC_FUNC_IMPL(__imp__sub_880E39E0) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,140
	ctx.r5.s64 = 140;
	// li r4,210
	ctx.r4.s64 = 210;
	// li r3,6
	ctx.r3.s64 = 6;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E39F4"))) PPC_WEAK_FUNC(sub_880E39F4);
PPC_FUNC_IMPL(__imp__sub_880E39F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E39F8"))) PPC_WEAK_FUNC(sub_880E39F8);
PPC_FUNC_IMPL(__imp__sub_880E39F8) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,125
	ctx.r5.s64 = 125;
	// li r4,208
	ctx.r4.s64 = 208;
	// li r3,6
	ctx.r3.s64 = 6;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3A0C"))) PPC_WEAK_FUNC(sub_880E3A0C);
PPC_FUNC_IMPL(__imp__sub_880E3A0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3A10"))) PPC_WEAK_FUNC(sub_880E3A10);
PPC_FUNC_IMPL(__imp__sub_880E3A10) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,125
	ctx.r5.s64 = 125;
	// li r4,207
	ctx.r4.s64 = 207;
	// li r3,6
	ctx.r3.s64 = 6;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3A24"))) PPC_WEAK_FUNC(sub_880E3A24);
PPC_FUNC_IMPL(__imp__sub_880E3A24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3A28"))) PPC_WEAK_FUNC(sub_880E3A28);
PPC_FUNC_IMPL(__imp__sub_880E3A28) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,105
	ctx.r5.s64 = 105;
	// li r4,198
	ctx.r4.s64 = 198;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3A3C"))) PPC_WEAK_FUNC(sub_880E3A3C);
PPC_FUNC_IMPL(__imp__sub_880E3A3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3A40"))) PPC_WEAK_FUNC(sub_880E3A40);
PPC_FUNC_IMPL(__imp__sub_880E3A40) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,105
	ctx.r5.s64 = 105;
	// li r4,197
	ctx.r4.s64 = 197;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3A54"))) PPC_WEAK_FUNC(sub_880E3A54);
PPC_FUNC_IMPL(__imp__sub_880E3A54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3A58"))) PPC_WEAK_FUNC(sub_880E3A58);
PPC_FUNC_IMPL(__imp__sub_880E3A58) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,105
	ctx.r5.s64 = 105;
	// li r4,196
	ctx.r4.s64 = 196;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3A6C"))) PPC_WEAK_FUNC(sub_880E3A6C);
PPC_FUNC_IMPL(__imp__sub_880E3A6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3A70"))) PPC_WEAK_FUNC(sub_880E3A70);
PPC_FUNC_IMPL(__imp__sub_880E3A70) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,105
	ctx.r5.s64 = 105;
	// li r4,195
	ctx.r4.s64 = 195;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3A84"))) PPC_WEAK_FUNC(sub_880E3A84);
PPC_FUNC_IMPL(__imp__sub_880E3A84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3A88"))) PPC_WEAK_FUNC(sub_880E3A88);
PPC_FUNC_IMPL(__imp__sub_880E3A88) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,105
	ctx.r5.s64 = 105;
	// li r4,194
	ctx.r4.s64 = 194;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3A9C"))) PPC_WEAK_FUNC(sub_880E3A9C);
PPC_FUNC_IMPL(__imp__sub_880E3A9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3AA0"))) PPC_WEAK_FUNC(sub_880E3AA0);
PPC_FUNC_IMPL(__imp__sub_880E3AA0) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,105
	ctx.r5.s64 = 105;
	// li r4,193
	ctx.r4.s64 = 193;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3AB4"))) PPC_WEAK_FUNC(sub_880E3AB4);
PPC_FUNC_IMPL(__imp__sub_880E3AB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3AB8"))) PPC_WEAK_FUNC(sub_880E3AB8);
PPC_FUNC_IMPL(__imp__sub_880E3AB8) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,105
	ctx.r5.s64 = 105;
	// li r4,192
	ctx.r4.s64 = 192;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3ACC"))) PPC_WEAK_FUNC(sub_880E3ACC);
PPC_FUNC_IMPL(__imp__sub_880E3ACC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3AD0"))) PPC_WEAK_FUNC(sub_880E3AD0);
PPC_FUNC_IMPL(__imp__sub_880E3AD0) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,105
	ctx.r5.s64 = 105;
	// li r4,191
	ctx.r4.s64 = 191;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3AE4"))) PPC_WEAK_FUNC(sub_880E3AE4);
PPC_FUNC_IMPL(__imp__sub_880E3AE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3AE8"))) PPC_WEAK_FUNC(sub_880E3AE8);
PPC_FUNC_IMPL(__imp__sub_880E3AE8) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,105
	ctx.r5.s64 = 105;
	// li r4,190
	ctx.r4.s64 = 190;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3AFC"))) PPC_WEAK_FUNC(sub_880E3AFC);
PPC_FUNC_IMPL(__imp__sub_880E3AFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3B00"))) PPC_WEAK_FUNC(sub_880E3B00);
PPC_FUNC_IMPL(__imp__sub_880E3B00) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,105
	ctx.r5.s64 = 105;
	// li r4,189
	ctx.r4.s64 = 189;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3B14"))) PPC_WEAK_FUNC(sub_880E3B14);
PPC_FUNC_IMPL(__imp__sub_880E3B14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3B18"))) PPC_WEAK_FUNC(sub_880E3B18);
PPC_FUNC_IMPL(__imp__sub_880E3B18) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,105
	ctx.r5.s64 = 105;
	// li r4,188
	ctx.r4.s64 = 188;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3B2C"))) PPC_WEAK_FUNC(sub_880E3B2C);
PPC_FUNC_IMPL(__imp__sub_880E3B2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3B30"))) PPC_WEAK_FUNC(sub_880E3B30);
PPC_FUNC_IMPL(__imp__sub_880E3B30) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,105
	ctx.r5.s64 = 105;
	// li r4,187
	ctx.r4.s64 = 187;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3B44"))) PPC_WEAK_FUNC(sub_880E3B44);
PPC_FUNC_IMPL(__imp__sub_880E3B44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3B48"))) PPC_WEAK_FUNC(sub_880E3B48);
PPC_FUNC_IMPL(__imp__sub_880E3B48) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,105
	ctx.r5.s64 = 105;
	// li r4,186
	ctx.r4.s64 = 186;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3B5C"))) PPC_WEAK_FUNC(sub_880E3B5C);
PPC_FUNC_IMPL(__imp__sub_880E3B5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3B60"))) PPC_WEAK_FUNC(sub_880E3B60);
PPC_FUNC_IMPL(__imp__sub_880E3B60) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,105
	ctx.r5.s64 = 105;
	// li r4,185
	ctx.r4.s64 = 185;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3B74"))) PPC_WEAK_FUNC(sub_880E3B74);
PPC_FUNC_IMPL(__imp__sub_880E3B74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3B78"))) PPC_WEAK_FUNC(sub_880E3B78);
PPC_FUNC_IMPL(__imp__sub_880E3B78) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,105
	ctx.r5.s64 = 105;
	// li r4,184
	ctx.r4.s64 = 184;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3B8C"))) PPC_WEAK_FUNC(sub_880E3B8C);
PPC_FUNC_IMPL(__imp__sub_880E3B8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3B90"))) PPC_WEAK_FUNC(sub_880E3B90);
PPC_FUNC_IMPL(__imp__sub_880E3B90) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,105
	ctx.r5.s64 = 105;
	// li r4,183
	ctx.r4.s64 = 183;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3BA4"))) PPC_WEAK_FUNC(sub_880E3BA4);
PPC_FUNC_IMPL(__imp__sub_880E3BA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3BA8"))) PPC_WEAK_FUNC(sub_880E3BA8);
PPC_FUNC_IMPL(__imp__sub_880E3BA8) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,105
	ctx.r5.s64 = 105;
	// li r4,204
	ctx.r4.s64 = 204;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3BBC"))) PPC_WEAK_FUNC(sub_880E3BBC);
PPC_FUNC_IMPL(__imp__sub_880E3BBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3BC0"))) PPC_WEAK_FUNC(sub_880E3BC0);
PPC_FUNC_IMPL(__imp__sub_880E3BC0) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,105
	ctx.r5.s64 = 105;
	// li r4,206
	ctx.r4.s64 = 206;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3BD4"))) PPC_WEAK_FUNC(sub_880E3BD4);
PPC_FUNC_IMPL(__imp__sub_880E3BD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3BD8"))) PPC_WEAK_FUNC(sub_880E3BD8);
PPC_FUNC_IMPL(__imp__sub_880E3BD8) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,105
	ctx.r5.s64 = 105;
	// li r4,205
	ctx.r4.s64 = 205;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3BEC"))) PPC_WEAK_FUNC(sub_880E3BEC);
PPC_FUNC_IMPL(__imp__sub_880E3BEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3BF0"))) PPC_WEAK_FUNC(sub_880E3BF0);
PPC_FUNC_IMPL(__imp__sub_880E3BF0) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,105
	ctx.r5.s64 = 105;
	// li r4,203
	ctx.r4.s64 = 203;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3C04"))) PPC_WEAK_FUNC(sub_880E3C04);
PPC_FUNC_IMPL(__imp__sub_880E3C04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3C08"))) PPC_WEAK_FUNC(sub_880E3C08);
PPC_FUNC_IMPL(__imp__sub_880E3C08) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,105
	ctx.r5.s64 = 105;
	// li r4,202
	ctx.r4.s64 = 202;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3C1C"))) PPC_WEAK_FUNC(sub_880E3C1C);
PPC_FUNC_IMPL(__imp__sub_880E3C1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3C20"))) PPC_WEAK_FUNC(sub_880E3C20);
PPC_FUNC_IMPL(__imp__sub_880E3C20) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,105
	ctx.r5.s64 = 105;
	// li r4,200
	ctx.r4.s64 = 200;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3C34"))) PPC_WEAK_FUNC(sub_880E3C34);
PPC_FUNC_IMPL(__imp__sub_880E3C34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3C38"))) PPC_WEAK_FUNC(sub_880E3C38);
PPC_FUNC_IMPL(__imp__sub_880E3C38) {
	PPC_FUNC_PROLOGUE();
	// li r6,85
	ctx.r6.s64 = 85;
	// li r5,105
	ctx.r5.s64 = 105;
	// li r4,181
	ctx.r4.s64 = 181;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3C4C"))) PPC_WEAK_FUNC(sub_880E3C4C);
PPC_FUNC_IMPL(__imp__sub_880E3C4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3C50"))) PPC_WEAK_FUNC(sub_880E3C50);
PPC_FUNC_IMPL(__imp__sub_880E3C50) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,95
	ctx.r5.s64 = 95;
	// li r4,238
	ctx.r4.s64 = 238;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3C64"))) PPC_WEAK_FUNC(sub_880E3C64);
PPC_FUNC_IMPL(__imp__sub_880E3C64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3C68"))) PPC_WEAK_FUNC(sub_880E3C68);
PPC_FUNC_IMPL(__imp__sub_880E3C68) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,95
	ctx.r5.s64 = 95;
	// li r4,237
	ctx.r4.s64 = 237;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3C7C"))) PPC_WEAK_FUNC(sub_880E3C7C);
PPC_FUNC_IMPL(__imp__sub_880E3C7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3C80"))) PPC_WEAK_FUNC(sub_880E3C80);
PPC_FUNC_IMPL(__imp__sub_880E3C80) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,95
	ctx.r5.s64 = 95;
	// li r4,236
	ctx.r4.s64 = 236;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3C94"))) PPC_WEAK_FUNC(sub_880E3C94);
PPC_FUNC_IMPL(__imp__sub_880E3C94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3C98"))) PPC_WEAK_FUNC(sub_880E3C98);
PPC_FUNC_IMPL(__imp__sub_880E3C98) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,95
	ctx.r5.s64 = 95;
	// li r4,235
	ctx.r4.s64 = 235;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3CAC"))) PPC_WEAK_FUNC(sub_880E3CAC);
PPC_FUNC_IMPL(__imp__sub_880E3CAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3CB0"))) PPC_WEAK_FUNC(sub_880E3CB0);
PPC_FUNC_IMPL(__imp__sub_880E3CB0) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,95
	ctx.r5.s64 = 95;
	// li r4,234
	ctx.r4.s64 = 234;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3CC4"))) PPC_WEAK_FUNC(sub_880E3CC4);
PPC_FUNC_IMPL(__imp__sub_880E3CC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3CC8"))) PPC_WEAK_FUNC(sub_880E3CC8);
PPC_FUNC_IMPL(__imp__sub_880E3CC8) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,95
	ctx.r5.s64 = 95;
	// li r4,233
	ctx.r4.s64 = 233;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3CDC"))) PPC_WEAK_FUNC(sub_880E3CDC);
PPC_FUNC_IMPL(__imp__sub_880E3CDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3CE0"))) PPC_WEAK_FUNC(sub_880E3CE0);
PPC_FUNC_IMPL(__imp__sub_880E3CE0) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,95
	ctx.r5.s64 = 95;
	// li r4,232
	ctx.r4.s64 = 232;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3CF4"))) PPC_WEAK_FUNC(sub_880E3CF4);
PPC_FUNC_IMPL(__imp__sub_880E3CF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3CF8"))) PPC_WEAK_FUNC(sub_880E3CF8);
PPC_FUNC_IMPL(__imp__sub_880E3CF8) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,95
	ctx.r5.s64 = 95;
	// li r4,231
	ctx.r4.s64 = 231;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3D0C"))) PPC_WEAK_FUNC(sub_880E3D0C);
PPC_FUNC_IMPL(__imp__sub_880E3D0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3D10"))) PPC_WEAK_FUNC(sub_880E3D10);
PPC_FUNC_IMPL(__imp__sub_880E3D10) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,95
	ctx.r5.s64 = 95;
	// li r4,230
	ctx.r4.s64 = 230;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3D24"))) PPC_WEAK_FUNC(sub_880E3D24);
PPC_FUNC_IMPL(__imp__sub_880E3D24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3D28"))) PPC_WEAK_FUNC(sub_880E3D28);
PPC_FUNC_IMPL(__imp__sub_880E3D28) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,95
	ctx.r5.s64 = 95;
	// li r4,229
	ctx.r4.s64 = 229;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3D3C"))) PPC_WEAK_FUNC(sub_880E3D3C);
PPC_FUNC_IMPL(__imp__sub_880E3D3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3D40"))) PPC_WEAK_FUNC(sub_880E3D40);
PPC_FUNC_IMPL(__imp__sub_880E3D40) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,95
	ctx.r5.s64 = 95;
	// li r4,228
	ctx.r4.s64 = 228;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3D54"))) PPC_WEAK_FUNC(sub_880E3D54);
PPC_FUNC_IMPL(__imp__sub_880E3D54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3D58"))) PPC_WEAK_FUNC(sub_880E3D58);
PPC_FUNC_IMPL(__imp__sub_880E3D58) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,95
	ctx.r5.s64 = 95;
	// li r4,227
	ctx.r4.s64 = 227;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3D6C"))) PPC_WEAK_FUNC(sub_880E3D6C);
PPC_FUNC_IMPL(__imp__sub_880E3D6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3D70"))) PPC_WEAK_FUNC(sub_880E3D70);
PPC_FUNC_IMPL(__imp__sub_880E3D70) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,95
	ctx.r5.s64 = 95;
	// li r4,226
	ctx.r4.s64 = 226;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3D84"))) PPC_WEAK_FUNC(sub_880E3D84);
PPC_FUNC_IMPL(__imp__sub_880E3D84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3D88"))) PPC_WEAK_FUNC(sub_880E3D88);
PPC_FUNC_IMPL(__imp__sub_880E3D88) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,95
	ctx.r5.s64 = 95;
	// li r4,225
	ctx.r4.s64 = 225;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3D9C"))) PPC_WEAK_FUNC(sub_880E3D9C);
PPC_FUNC_IMPL(__imp__sub_880E3D9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3DA0"))) PPC_WEAK_FUNC(sub_880E3DA0);
PPC_FUNC_IMPL(__imp__sub_880E3DA0) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,95
	ctx.r5.s64 = 95;
	// li r4,224
	ctx.r4.s64 = 224;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3DB4"))) PPC_WEAK_FUNC(sub_880E3DB4);
PPC_FUNC_IMPL(__imp__sub_880E3DB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3DB8"))) PPC_WEAK_FUNC(sub_880E3DB8);
PPC_FUNC_IMPL(__imp__sub_880E3DB8) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,95
	ctx.r5.s64 = 95;
	// li r4,223
	ctx.r4.s64 = 223;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3DCC"))) PPC_WEAK_FUNC(sub_880E3DCC);
PPC_FUNC_IMPL(__imp__sub_880E3DCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880E3DD0"))) PPC_WEAK_FUNC(sub_880E3DD0);
PPC_FUNC_IMPL(__imp__sub_880E3DD0) {
	PPC_FUNC_PROLOGUE();
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,95
	ctx.r5.s64 = 95;
	// li r4,244
	ctx.r4.s64 = 244;
	// addi r3,r3,5
	ctx.r3.s64 = ctx.r3.s64 + 5;
	// b 0x880e31b0
	sub_880E31B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880E3DE4"))) PPC_WEAK_FUNC(sub_880E3DE4);
PPC_FUNC_IMPL(__imp__sub_880E3DE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

