#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_8809E458"))) PPC_WEAK_FUNC(sub_8809E458);
PPC_FUNC_IMPL(__imp__sub_8809E458) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071138
	ctx.lr = 0x8809E460;
	__savegprlr_20(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30710
	ctx.r11.s64 = -2012610560;
	// li r4,204
	ctx.r4.s64 = 204;
	// addi r5,r11,-7080
	ctx.r5.s64 = ctx.r11.s64 + -7080;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x8809E478;
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
	ctx.lr = 0x8809E48C;
	sub_88073BD0(ctx, base);
	// stw r30,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// li r4,21
	ctx.r4.s64 = 21;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x881556a0
	ctx.lr = 0x8809E49C;
	sub_881556A0(ctx, base);
	// lis r10,-30710
	ctx.r10.s64 = -2012610560;
	// stw r3,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r3.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r9,r10,-8424
	ctx.r9.s64 = ctx.r10.s64 + -8424;
	// stw r31,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r31.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r9,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r9.u32);
	// lwz r8,96(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// stw r7,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r7.u32);
	// lwz r9,96(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// lwz r11,28(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809e4ec
	if (ctx.cr6.eq) goto loc_8809E4EC;
loc_8809E4D4:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8809e644
	if (ctx.cr6.eq) goto loc_8809E644;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8809e4d4
	if (!ctx.cr6.eq) goto loc_8809E4D4;
loc_8809E4EC:
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
loc_8809E4F0:
	// li r10,8
	ctx.r10.s64 = 8;
	// stw r6,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r6.u32);
	// addi r5,r31,8
	ctx.r5.s64 = ctx.r31.s64 + 8;
	// li r9,63
	ctx.r9.s64 = 63;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// stw r5,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r5.u32);
	// lis r3,-30671
	ctx.r3.s64 = -2010054656;
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// lis r4,16838
	ctx.r4.s64 = 1103495168;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// li r5,216
	ctx.r5.s64 = 216;
	// stw r10,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// ori r8,r4,20077
	ctx.r8.u64 = ctx.r4.u64 | 20077;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lis r29,-30710
	ctx.r29.s64 = -2012610560;
	// lwz r11,4200(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4200);
	// li r9,16
	ctx.r9.s64 = 16;
	// stw r5,168(r30)
	PPC_STORE_U32(ctx.r30.u32 + 168, ctx.r5.u32);
	// mr r5,r8
	ctx.r5.u64 = ctx.r8.u64;
	// mullw r11,r11,r8
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r8.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// li r28,2
	ctx.r28.s64 = 2;
	// mullw r4,r11,r8
	ctx.r4.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r8.s32);
	// stw r11,4200(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4200, ctx.r11.u32);
	// lhz r11,4200(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4200);
	// lwz r8,32(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// stw r8,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r8.u32);
	// clrlwi r26,r11,29
	ctx.r26.u64 = ctx.r11.u32 & 0x7;
	// lwz r5,36(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// lis r11,-30710
	ctx.r11.s64 = -2012610560;
	// stw r5,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r5.u32);
	// li r27,32
	ctx.r27.s64 = 32;
	// lwz r8,100(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 100);
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// rlwinm r5,r8,1,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0x1;
	// li r25,24
	ctx.r25.s64 = 24;
	// addi r20,r5,-1
	ctx.r20.s64 = ctx.r5.s64 + -1;
	// addi r5,r4,12345
	ctx.r5.s64 = ctx.r4.s64 + 12345;
	// and r8,r20,r8
	ctx.r8.u64 = ctx.r20.u64 & ctx.r8.u64;
	// stw r5,4200(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4200, ctx.r5.u32);
	// addi r5,r11,-7496
	ctx.r5.s64 = ctx.r11.s64 + -7496;
	// stw r8,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r8.u32);
	// li r24,5
	ctx.r24.s64 = 5;
	// lwz r8,132(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 132);
	// li r23,-32
	ctx.r23.s64 = -32;
	// lhz r11,4200(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4200);
	// clrlwi r3,r11,29
	ctx.r3.u64 = ctx.r11.u32 & 0x7;
	// lwz r11,2304(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2304);
	// addi r29,r29,-8008
	ctx.r29.s64 = ctx.r29.s64 + -8008;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lis r22,-30710
	ctx.r22.s64 = -2012610560;
	// lwz r8,136(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 136);
	// lis r21,-30710
	ctx.r21.s64 = -2012610560;
	// stw r8,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r8.u32);
	// addi r4,r22,-8352
	ctx.r4.s64 = ctx.r22.s64 + -8352;
	// lwz r11,140(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 140);
	// addi r22,r21,-8416
	ctx.r22.s64 = ctx.r21.s64 + -8416;
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// stw r10,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r10.u32);
	// stw r26,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r26.u32);
	// stw r28,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r28.u32);
	// stw r7,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r7.u32);
	// stw r3,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r3.u32);
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// stw r11,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r11.u32);
	// stw r7,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r7.u32);
	// stw r27,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r27.u32);
	// stw r9,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r9.u32);
	// stw r6,152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 152, ctx.r6.u32);
	// stw r6,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r6.u32);
	// stw r7,160(r31)
	PPC_STORE_U32(ctx.r31.u32 + 160, ctx.r7.u32);
	// stw r9,184(r31)
	PPC_STORE_U32(ctx.r31.u32 + 184, ctx.r9.u32);
	// stw r25,188(r31)
	PPC_STORE_U32(ctx.r31.u32 + 188, ctx.r25.u32);
	// stw r24,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r24.u32);
	// stw r23,172(r31)
	PPC_STORE_U32(ctx.r31.u32 + 172, ctx.r23.u32);
	// stw r9,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r9.u32);
	// stw r9,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r9.u32);
	// stw r29,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r29.u32);
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// stw r10,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r10.u32);
	// stw r5,64(r30)
	PPC_STORE_U32(ctx.r30.u32 + 64, ctx.r5.u32);
	// stw r4,68(r30)
	PPC_STORE_U32(ctx.r30.u32 + 68, ctx.r4.u32);
	// stw r22,84(r30)
	PPC_STORE_U32(ctx.r30.u32 + 84, ctx.r22.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x88071188
	__restgprlr_20(ctx, base);
	return;
loc_8809E644:
	// lwz r10,24(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8809e654
	if (ctx.cr6.eq) goto loc_8809E654;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_8809E654:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x8809e4f0
	goto loc_8809E4F0;
}

__attribute__((alias("__imp__sub_8809E65C"))) PPC_WEAK_FUNC(sub_8809E65C);
PPC_FUNC_IMPL(__imp__sub_8809E65C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8809E660"))) PPC_WEAK_FUNC(sub_8809E660);
PPC_FUNC_IMPL(__imp__sub_8809E660) {
	PPC_FUNC_PROLOGUE();
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8809E668"))) PPC_WEAK_FUNC(sub_8809E668);
PPC_FUNC_IMPL(__imp__sub_8809E668) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r10,116(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8809e6d0
	if (ctx.cr6.eq) goto loc_8809E6D0;
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 108);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,108(r11)
	PPC_STORE_U32(ctx.r11.u32 + 108, ctx.r10.u32);
	// bge 0x8809e6f8
	if (!ctx.cr0.lt) goto loc_8809E6F8;
	// lwz r10,112(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 112);
	// li r7,-1
	ctx.r7.s64 = -1;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r8,128(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 128);
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,70
	ctx.r4.s64 = 70;
	// lwz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// stw r10,108(r11)
	PPC_STORE_U32(ctx.r11.u32 + 108, ctx.r10.u32);
	// bl 0x88094858
	ctx.lr = 0x8809E6C0;
	sub_88094858(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_8809E6D0:
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 100);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,100(r11)
	PPC_STORE_U32(ctx.r11.u32 + 100, ctx.r10.u32);
	// bge 0x8809e6f8
	if (!ctx.cr0.lt) goto loc_8809E6F8;
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 104);
	// lwz r9,120(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 120);
	// lwz r8,176(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// stw r10,100(r11)
	PPC_STORE_U32(ctx.r11.u32 + 100, ctx.r10.u32);
	// stw r9,116(r11)
	PPC_STORE_U32(ctx.r11.u32 + 116, ctx.r9.u32);
	// stw r8,172(r11)
	PPC_STORE_U32(ctx.r11.u32 + 172, ctx.r8.u32);
loc_8809E6F8:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8809E708"))) PPC_WEAK_FUNC(sub_8809E708);
PPC_FUNC_IMPL(__imp__sub_8809E708) {
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

__attribute__((alias("__imp__sub_8809E748"))) PPC_WEAK_FUNC(sub_8809E748);
PPC_FUNC_IMPL(__imp__sub_8809E748) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x8809E750;
	__savegprlr_26(ctx, base);
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
	// addi r26,r11,64
	ctx.r26.s64 = ctx.r11.s64 + 64;
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r3,r26,10750
	ctx.r3.s64 = ctx.r26.s64 + 10750;
	// bl 0x881538c0
	ctx.lr = 0x8809E774;
	sub_881538C0(ctx, base);
	// lis r29,-30597
	ctx.r29.s64 = -2005204992;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809e7a0
	if (ctx.cr6.eq) goto loc_8809E7A0;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-11932(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -11932);
	// oris r9,r10,547
	ctx.r9.u64 = ctx.r10.u64 | 35848192;
	// addi r30,r11,1
	ctx.r30.s64 = ctx.r11.s64 + 1;
	// ori r9,r9,49152
	ctx.r9.u64 = ctx.r9.u64 | 49152;
	// stw r30,-11932(r29)
	PPC_STORE_U32(ctx.r29.u32 + -11932, ctx.r30.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// b 0x8809e7a4
	goto loc_8809E7A4;
loc_8809E7A0:
	// lwz r30,-11932(r29)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r29.u32 + -11932);
loc_8809E7A4:
	// lwz r28,8(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r6,214
	ctx.r6.s64 = 214;
	// lwz r27,12(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r3,r26,10878
	ctx.r3.s64 = ctx.r26.s64 + 10878;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// bl 0x881538c0
	ctx.lr = 0x8809E7C0;
	sub_881538C0(ctx, base);
	// lis r11,545
	ctx.r11.s64 = 35717120;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// ori r31,r11,65280
	ctx.r31.u64 = ctx.r11.u64 | 65280;
	// beq cr6,0x8809e7e4
	if (ctx.cr6.eq) goto loc_8809E7E4;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// or r10,r11,r31
	ctx.r10.u64 = ctx.r11.u64 | ctx.r31.u64;
	// stw r30,-11932(r29)
	PPC_STORE_U32(ctx.r29.u32 + -11932, ctx.r30.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_8809E7E4:
	// lis r3,0
	ctx.r3.s64 = 0;
	// li r6,214
	ctx.r6.s64 = 214;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// ori r3,r3,45204
	ctx.r3.u64 = ctx.r3.u64 | 45204;
	// bl 0x881538c0
	ctx.lr = 0x8809E7FC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809e824
	if (ctx.cr6.eq) goto loc_8809E824;
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
	// stw r11,-11932(r29)
	PPC_STORE_U32(ctx.r29.u32 + -11932, ctx.r11.u32);
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
loc_8809E824:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809E82C"))) PPC_WEAK_FUNC(sub_8809E82C);
PPC_FUNC_IMPL(__imp__sub_8809E82C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8809E830"))) PPC_WEAK_FUNC(sub_8809E830);
PPC_FUNC_IMPL(__imp__sub_8809E830) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x8809E838;
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
	// blt cr6,0x8809e85c
	if (ctx.cr6.lt) goto loc_8809E85C;
	// lwz r11,188(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 188);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x8809e868
	goto loc_8809E868;
loc_8809E85C:
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 184);
	// lwz r11,168(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 168);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_8809E868:
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
	ctx.lr = 0x8809E8A4;
	sub_880F52C8(ctx, base);
	// lwz r11,1592(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1592);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8809e900
	if (!ctx.cr6.eq) goto loc_8809E900;
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
	ctx.lr = 0x8809E8CC;
	sub_880F5438(ctx, base);
	// lwz r10,1596(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1596);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8809e900
	if (!ctx.cr6.eq) goto loc_8809E900;
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
	ctx.lr = 0x8809E900;
	sub_881607F8(ctx, base);
loc_8809E900:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809E908"))) PPC_WEAK_FUNC(sub_8809E908);
PPC_FUNC_IMPL(__imp__sub_8809E908) {
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
	// beq cr6,0x8809e954
	if (ctx.cr6.eq) goto loc_8809E954;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8809e830
	ctx.lr = 0x8809E93C;
	sub_8809E830(ctx, base);
	// lwz r10,96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r11.u32);
	// bl 0x88094220
	ctx.lr = 0x8809E950;
	sub_88094220(ctx, base);
	// b 0x8809ea90
	goto loc_8809EA90;
loc_8809E954:
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
	// beq cr6,0x8809e9bc
	if (ctx.cr6.eq) goto loc_8809E9BC;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x8809e9cc
	goto loc_8809E9CC;
loc_8809E9BC:
	// lwz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// addi r10,r10,51
	ctx.r10.s64 = ctx.r10.s64 + 51;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r9,r6
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r6.u32);
loc_8809E9CC:
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
	// ble 0x8809ea3c
	if (!ctx.cr0.gt) goto loc_8809EA3C;
	// lis r8,128
	ctx.r8.s64 = 8388608;
	// lis r5,320
	ctx.r5.s64 = 20971520;
	// subf r4,r8,r9
	ctx.r4.s64 = ctx.r9.s64 - ctx.r8.s64;
	// cmpw cr6,r4,r5
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r5.s32, ctx.xer);
	// bge cr6,0x8809ea3c
	if (!ctx.cr6.lt) goto loc_8809EA3C;
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
	// ble cr6,0x8809ea3c
	if (!ctx.cr6.gt) goto loc_8809EA3C;
	// lis r10,280
	ctx.r10.s64 = 18350080;
	// subf r9,r8,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r8.s64;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x8809ea60
	if (ctx.cr6.lt) goto loc_8809EA60;
loc_8809EA3C:
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8809ea68
	if (ctx.cr6.eq) goto loc_8809EA68;
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x88094220
	ctx.lr = 0x8809EA5C;
	sub_88094220(ctx, base);
	// b 0x8809ea90
	goto loc_8809EA90;
loc_8809EA60:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r11.u32);
loc_8809EA68:
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// bge 0x8809ea90
	if (!ctx.cr0.lt) goto loc_8809EA90;
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
loc_8809EA90:
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

__attribute__((alias("__imp__sub_8809EAA8"))) PPC_WEAK_FUNC(sub_8809EAA8);
PPC_FUNC_IMPL(__imp__sub_8809EAA8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x8809EAB0;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30710
	ctx.r11.s64 = -2012610560;
	// li r4,192
	ctx.r4.s64 = 192;
	// addi r5,r11,-5464
	ctx.r5.s64 = ctx.r11.s64 + -5464;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x8809EAC8;
	sub_88094290(ctx, base);
	// li r5,192
	ctx.r5.s64 = 192;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,2304(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2304);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x8809EADC;
	sub_88073BD0(ctx, base);
	// stw r30,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// li r4,21
	ctx.r4.s64 = 21;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x881556a0
	ctx.lr = 0x8809EAEC;
	sub_881556A0(ctx, base);
	// lis r10,-30710
	ctx.r10.s64 = -2012610560;
	// stw r3,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r3.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r9,r10,-6560
	ctx.r9.s64 = ctx.r10.s64 + -6560;
	// stw r31,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r31.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r9,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r9.u32);
	// lwz r8,96(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// stw r7,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r7.u32);
	// lwz r9,96(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// lwz r11,28(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809eb3c
	if (ctx.cr6.eq) goto loc_8809EB3C;
loc_8809EB24:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8809ec88
	if (ctx.cr6.eq) goto loc_8809EC88;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8809eb24
	if (!ctx.cr6.eq) goto loc_8809EB24;
loc_8809EB3C:
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
loc_8809EB40:
	// addi r5,r31,8
	ctx.r5.s64 = ctx.r31.s64 + 8;
	// stw r6,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r6.u32);
	// li r10,8
	ctx.r10.s64 = 8;
	// stw r5,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r5.u32);
	// lis r5,-30671
	ctx.r5.s64 = -2010054656;
	// li r9,63
	ctx.r9.s64 = 63;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// lis r4,16838
	ctx.r4.s64 = 1103495168;
	// stw r10,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// li r3,216
	ctx.r3.s64 = 216;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// ori r8,r4,20077
	ctx.r8.u64 = ctx.r4.u64 | 20077;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lis r25,-30710
	ctx.r25.s64 = -2012610560;
	// lwz r11,4200(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4200);
	// li r9,16
	ctx.r9.s64 = 16;
	// stw r3,168(r30)
	PPC_STORE_U32(ctx.r30.u32 + 168, ctx.r3.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// mullw r11,r11,r8
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r8.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// li r3,32
	ctx.r3.s64 = 32;
	// mullw r8,r11,r8
	ctx.r8.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r8.s32);
	// stw r11,4200(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4200, ctx.r11.u32);
	// lhz r11,4200(r5)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r5.u32 + 4200);
	// lwz r28,32(r30)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// stw r28,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r28.u32);
	// clrlwi r27,r11,29
	ctx.r27.u64 = ctx.r11.u32 & 0x7;
	// lwz r11,36(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// stw r8,4200(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4200, ctx.r8.u32);
	// lis r29,-30710
	ctx.r29.s64 = -2012610560;
	// lhz r8,4200(r5)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r5.u32 + 4200);
	// li r26,4
	ctx.r26.s64 = 4;
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// addi r29,r29,-6552
	ctx.r29.s64 = ctx.r29.s64 + -6552;
	// lwz r5,100(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 100);
	// addi r11,r5,-1
	ctx.r11.s64 = ctx.r5.s64 + -1;
	// rlwinm r5,r11,1,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// clrlwi r8,r8,29
	ctx.r8.u64 = ctx.r8.u32 & 0x7;
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
	// lis r28,-30710
	ctx.r28.s64 = -2012610560;
	// and r11,r5,r11
	ctx.r11.u64 = ctx.r5.u64 & ctx.r11.u64;
	// addi r5,r25,-6328
	ctx.r5.s64 = ctx.r25.s64 + -6328;
	// stw r11,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// lis r24,-30710
	ctx.r24.s64 = -2012610560;
	// lwz r25,132(r30)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r30.u32 + 132);
	// addi r28,r28,-5880
	ctx.r28.s64 = ctx.r28.s64 + -5880;
	// lwz r25,2304(r25)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r25.u32 + 2304);
	// addi r11,r24,-6392
	ctx.r11.s64 = ctx.r24.s64 + -6392;
	// stw r25,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r25.u32);
	// lwz r25,136(r30)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r30.u32 + 136);
	// stw r25,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r25.u32);
	// lwz r25,140(r30)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r30.u32 + 140);
	// stw r9,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r9.u32);
	// stw r9,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r9.u32);
	// stw r27,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r27.u32);
	// stw r4,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r4.u32);
	// stw r7,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r7.u32);
	// stw r8,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r8.u32);
	// stw r25,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r25.u32);
	// stw r25,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r25.u32);
	// stw r7,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r7.u32);
	// stw r3,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r3.u32);
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// stw r6,152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 152, ctx.r6.u32);
	// stw r6,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r6.u32);
	// stw r7,160(r31)
	PPC_STORE_U32(ctx.r31.u32 + 160, ctx.r7.u32);
	// stw r10,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r10.u32);
	// lwz r10,144(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 144);
	// stw r9,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r9.u32);
	// stw r9,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r9.u32);
	// stw r26,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r26.u32);
	// stw r10,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r10.u32);
	// stw r29,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r29.u32);
	// lwz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// stw r9,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r9.u32);
	// stw r28,64(r30)
	PPC_STORE_U32(ctx.r30.u32 + 64, ctx.r28.u32);
	// stw r5,68(r30)
	PPC_STORE_U32(ctx.r30.u32 + 68, ctx.r5.u32);
	// stw r11,84(r30)
	PPC_STORE_U32(ctx.r30.u32 + 84, ctx.r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
loc_8809EC88:
	// lwz r10,24(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8809ec98
	if (ctx.cr6.eq) goto loc_8809EC98;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_8809EC98:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x8809eb40
	goto loc_8809EB40;
}

__attribute__((alias("__imp__sub_8809ECA0"))) PPC_WEAK_FUNC(sub_8809ECA0);
PPC_FUNC_IMPL(__imp__sub_8809ECA0) {
	PPC_FUNC_PROLOGUE();
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8809ECA8"))) PPC_WEAK_FUNC(sub_8809ECA8);
PPC_FUNC_IMPL(__imp__sub_8809ECA8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r9,204(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 204);
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

__attribute__((alias("__imp__sub_8809ECE8"))) PPC_WEAK_FUNC(sub_8809ECE8);
PPC_FUNC_IMPL(__imp__sub_8809ECE8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x8809ECF0;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// li r6,214
	ctx.r6.s64 = 214;
	// lwz r11,160(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 160);
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// addi r26,r11,64
	ctx.r26.s64 = ctx.r11.s64 + 64;
	// lwz r5,32(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r3,r26,10750
	ctx.r3.s64 = ctx.r26.s64 + 10750;
	// bl 0x881538c0
	ctx.lr = 0x8809ED14;
	sub_881538C0(ctx, base);
	// lis r29,-30597
	ctx.r29.s64 = -2005204992;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809ed40
	if (ctx.cr6.eq) goto loc_8809ED40;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-11932(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -11932);
	// oris r9,r10,547
	ctx.r9.u64 = ctx.r10.u64 | 35848192;
	// addi r30,r11,1
	ctx.r30.s64 = ctx.r11.s64 + 1;
	// ori r9,r9,49152
	ctx.r9.u64 = ctx.r9.u64 | 49152;
	// stw r30,-11932(r29)
	PPC_STORE_U32(ctx.r29.u32 + -11932, ctx.r30.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// b 0x8809ed44
	goto loc_8809ED44;
loc_8809ED40:
	// lwz r30,-11932(r29)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r29.u32 + -11932);
loc_8809ED44:
	// lwz r28,8(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r6,214
	ctx.r6.s64 = 214;
	// lwz r27,12(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r3,r26,10878
	ctx.r3.s64 = ctx.r26.s64 + 10878;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// bl 0x881538c0
	ctx.lr = 0x8809ED60;
	sub_881538C0(ctx, base);
	// lis r11,545
	ctx.r11.s64 = 35717120;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// ori r31,r11,65280
	ctx.r31.u64 = ctx.r11.u64 | 65280;
	// beq cr6,0x8809ed84
	if (ctx.cr6.eq) goto loc_8809ED84;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// or r10,r11,r31
	ctx.r10.u64 = ctx.r11.u64 | ctx.r31.u64;
	// stw r30,-11932(r29)
	PPC_STORE_U32(ctx.r29.u32 + -11932, ctx.r30.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_8809ED84:
	// lis r3,0
	ctx.r3.s64 = 0;
	// li r6,214
	ctx.r6.s64 = 214;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// ori r3,r3,45204
	ctx.r3.u64 = ctx.r3.u64 | 45204;
	// bl 0x881538c0
	ctx.lr = 0x8809ED9C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809edc4
	if (ctx.cr6.eq) goto loc_8809EDC4;
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
	// stw r11,-11932(r29)
	PPC_STORE_U32(ctx.r29.u32 + -11932, ctx.r11.u32);
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
loc_8809EDC4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809EDCC"))) PPC_WEAK_FUNC(sub_8809EDCC);
PPC_FUNC_IMPL(__imp__sub_8809EDCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8809EDD0"))) PPC_WEAK_FUNC(sub_8809EDD0);
PPC_FUNC_IMPL(__imp__sub_8809EDD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071138
	ctx.lr = 0x8809EDD8;
	__savegprlr_20(ctx, base);
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// lis r22,-30643
	ctx.r22.s64 = -2008219648;
	// li r20,1
	ctx.r20.s64 = 1;
	// li r21,0
	ctx.r21.s64 = 0;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r23,0(r31)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x8809efd8
	if (ctx.cr6.gt) goto loc_8809EFD8;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x8809ee3c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8809EE3C;
	// bdzf 4*cr6+eq,0x8809ee60
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8809EE60;
	// bne cr6,0x8809eec8
	if (!ctx.cr6.eq) goto loc_8809EEC8;
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// cmpwi cr6,r11,320
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 320, ctx.xer);
	// blt cr6,0x8809efd8
	if (ctx.cr6.lt) goto loc_8809EFD8;
	// li r11,320
	ctx.r11.s64 = 320;
	// stw r20,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r20.u32);
	// stw r20,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r20.u32);
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// b 0x8809efd8
	goto loc_8809EFD8;
loc_8809EE3C:
	// lwz r11,1688(r23)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + 1688);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8809efd8
	if (ctx.cr6.eq) goto loc_8809EFD8;
	// li r11,96
	ctx.r11.s64 = 96;
	// stw r21,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r21.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stw r10,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r10.u32);
	// b 0x8809efd8
	goto loc_8809EFD8;
loc_8809EE60:
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8809ee80
	if (ctx.cr6.eq) goto loc_8809EE80;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// bgt 0x8809efd8
	if (ctx.cr0.gt) goto loc_8809EFD8;
	// stw r21,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r21.u32);
	// b 0x8809efd8
	goto loc_8809EFD8;
loc_8809EE80:
	// lwz r30,28(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// lwz r29,32(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x88095590
	ctx.lr = 0x8809EE98;
	sub_88095590(ctx, base);
	// li r11,144
	ctx.r11.s64 = 144;
	// li r10,-16
	ctx.r10.s64 = -16;
	// stw r30,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
	// li r9,3
	ctx.r9.s64 = 3;
	// stw r3,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r3.u32);
	// stw r21,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r21.u32);
	// stw r11,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// stw r29,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r29.u32);
	// stw r20,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r20.u32);
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// stw r9,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r9.u32);
	// b 0x8809efd8
	goto loc_8809EFD8;
loc_8809EEC8:
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r29,8(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r28,12(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// stw r29,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r29.u32);
	// stw r28,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r28.u32);
	// bge 0x8809eefc
	if (!ctx.cr0.lt) goto loc_8809EEFC;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stw r9,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r9.u32);
	// stw r10,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r10.u32);
loc_8809EEFC:
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// bge 0x8809efd8
	if (!ctx.cr0.lt) goto loc_8809EFD8;
	// lwz r10,60(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// li r25,2
	ctx.r25.s64 = 2;
	// lwz r30,26276(r22)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r22.u32 + 26276);
	// li r26,7
	ctx.r26.s64 = 7;
	// lwz r9,132(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// li r27,32
	ctx.r27.s64 = 32;
	// lwz r8,68(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// stw r10,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r10.u32);
	// subf r10,r8,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r8.s64;
	// bne cr6,0x8809ef78
	if (!ctx.cr6.eq) goto loc_8809EF78;
	// clrlwi r7,r10,16
	ctx.r7.u64 = ctx.r10.u32 & 0xFFFF;
	// stw r24,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r24.u32);
	// extsh r6,r11
	ctx.r6.s64 = ctx.r11.s16;
	// sth r21,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r21.u16);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,55
	ctx.r3.s64 = 55;
	// bl 0x8815c948
	ctx.lr = 0x8809EF5C;
	sub_8815C948(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809ef70
	if (ctx.cr6.eq) goto loc_8809EF70;
	// stb r25,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r25.u8);
	// sth r26,18(r3)
	PPC_STORE_U16(ctx.r3.u32 + 18, ctx.r26.u16);
	// sth r27,20(r3)
	PPC_STORE_U16(ctx.r3.u32 + 20, ctx.r27.u16);
loc_8809EF70:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x8809EF78;
	sub_8815C860(ctx, base);
loc_8809EF78:
	// lwz r9,132(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// bne cr6,0x8809efcc
	if (!ctx.cr6.eq) goto loc_8809EFCC;
	// clrlwi r7,r10,16
	ctx.r7.u64 = ctx.r10.u32 & 0xFFFF;
	// stw r24,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r24.u32);
	// extsh r6,r11
	ctx.r6.s64 = ctx.r11.s16;
	// sth r21,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r21.u16);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,55
	ctx.r3.s64 = 55;
	// bl 0x8815c948
	ctx.lr = 0x8809EFB0;
	sub_8815C948(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809efc4
	if (ctx.cr6.eq) goto loc_8809EFC4;
	// stb r25,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r25.u8);
	// sth r26,18(r3)
	PPC_STORE_U16(ctx.r3.u32 + 18, ctx.r26.u16);
	// sth r27,20(r3)
	PPC_STORE_U16(ctx.r3.u32 + 20, ctx.r27.u16);
loc_8809EFC4:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x8809EFCC;
	sub_8815C860(ctx, base);
loc_8809EFCC:
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// addi r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -2;
	// stw r11,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
loc_8809EFD8:
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8809f050
	if (!ctx.cr6.eq) goto loc_8809F050;
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r9,-30714
	ctx.r9.s64 = -2012872704;
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// addi r7,r9,9552
	ctx.r7.s64 = ctx.r9.s64 + 9552;
	// lwz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// rlwinm r5,r11,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x7FC;
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// lwz r4,8(r23)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r23.u32 + 8);
	// stw r4,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r4.u32);
	// rotlwi r8,r4,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r4.u32, 0);
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// lwz r3,12(r23)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r23.u32 + 12);
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// rotlwi r10,r3,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// rlwinm r9,r11,2,21,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x7FC;
	// lwzx r5,r5,r7
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r7.u32);
	// mullw r4,r5,r6
	ctx.r4.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r6.s32);
	// lwzx r3,r9,r7
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r7.u32);
	// mullw r11,r3,r6
	ctx.r11.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r6.s32);
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r9,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r9.u32);
	// stw r8,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r8.u32);
loc_8809F050:
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8809f2f0
	if (ctx.cr6.eq) goto loc_8809F2F0;
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// bge 0x8809f2a4
	if (!ctx.cr0.lt) goto loc_8809F2A4;
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r10,88(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// addic. r11,r11,-2
	ctx.xer.ca = ctx.r11.u32 > 1;
	ctx.r11.s64 = ctx.r11.s64 + -2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
	// stw r10,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r10.u32);
	// bgt 0x8809f088
	if (ctx.cr0.gt) goto loc_8809F088;
	// stw r21,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r21.u32);
loc_8809F088:
	// lwz r29,28(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// lwz r28,32(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x88095590
	ctx.lr = 0x8809F0A0;
	sub_88095590(ctx, base);
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8809f20c
	if (ctx.cr6.eq) goto loc_8809F20C;
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8809f20c
	if (!ctx.cr6.eq) goto loc_8809F20C;
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// clrlwi r10,r11,29
	ctx.r10.u64 = ctx.r11.u32 & 0x7;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8809f204
	if (!ctx.cr6.eq) goto loc_8809F204;
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8809f154
	if (ctx.cr6.eq) goto loc_8809F154;
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// addi r8,r3,40
	ctx.r8.s64 = ctx.r3.s64 + 40;
	// stw r20,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r20.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// li r4,73
	ctx.r4.s64 = 73;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x88094858
	ctx.lr = 0x8809F108;
	sub_88094858(ctx, base);
	// lwz r11,26276(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 26276);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// addi r10,r11,80
	ctx.r10.s64 = ctx.r11.s64 + 80;
	// srawi r9,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 1;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// subf r11,r8,r30
	ctx.r11.s64 = ctx.r30.s64 - ctx.r8.s64;
	// bne cr6,0x8809f1cc
	if (!ctx.cr6.eq) goto loc_8809F1CC;
	// clrlwi r7,r11,16
	ctx.r7.u64 = ctx.r11.u32 & 0xFFFF;
	// stw r24,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r24.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// sth r21,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r21.u16);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,55
	ctx.r3.s64 = 55;
	// bl 0x8815c948
	ctx.lr = 0x8809F148;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x8809F150;
	sub_8815C860(ctx, base);
	// b 0x8809f1cc
	goto loc_8809F1CC;
loc_8809F154:
	// lwz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// li r8,-1
	ctx.r8.s64 = -1;
	// lwz r10,26276(r22)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r22.u32 + 26276);
	// addi r11,r30,40
	ctx.r11.s64 = ctx.r30.s64 + 40;
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// bne cr6,0x8809f19c
	if (!ctx.cr6.eq) goto loc_8809F19C;
	// clrlwi r7,r11,16
	ctx.r7.u64 = ctx.r11.u32 & 0xFFFF;
	// stw r24,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r24.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// sth r21,166(r1)
	PPC_STORE_U16(ctx.r1.u32 + 166, ctx.r21.u16);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,55
	ctx.r3.s64 = 55;
	// bl 0x8815c948
	ctx.lr = 0x8809F194;
	sub_8815C948(ctx, base);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// bl 0x8815c860
	ctx.lr = 0x8809F19C;
	sub_8815C860(ctx, base);
loc_8809F19C:
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r11,r11,80
	ctx.r11.s64 = ctx.r11.s64 + 80;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// srawi r10,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 1;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addze r8,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r8.s64 = temp.s64;
	// li r4,73
	ctx.r4.s64 = 73;
	// subf r8,r8,r30
	ctx.r8.s64 = ctx.r30.s64 - ctx.r8.s64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x88094858
	ctx.lr = 0x8809F1CC;
	sub_88094858(ctx, base);
loc_8809F1CC:
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// stw r11,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8809f298
	if (!ctx.cr6.eq) goto loc_8809F298;
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bgt cr6,0x8809f298
	if (ctx.cr6.gt) goto loc_8809F298;
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// b 0x8809f298
	goto loc_8809F298;
loc_8809F204:
	// addi r11,r30,40
	ctx.r11.s64 = ctx.r30.s64 + 40;
	// b 0x8809f220
	goto loc_8809F220;
loc_8809F20C:
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// addi r11,r11,80
	ctx.r11.s64 = ctx.r11.s64 + 80;
	// srawi r10,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 1;
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r11.s64 = temp.s64;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
loc_8809F220:
	// lwz r27,26276(r22)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r22.u32 + 26276);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// bne cr6,0x8809f254
	if (!ctx.cr6.eq) goto loc_8809F254;
	// clrlwi r7,r11,16
	ctx.r7.u64 = ctx.r11.u32 & 0xFFFF;
	// sth r21,166(r1)
	PPC_STORE_U16(ctx.r1.u32 + 166, ctx.r21.u16);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r24,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r24.u32);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,55
	ctx.r3.s64 = 55;
	// bl 0x8815c948
	ctx.lr = 0x8809F24C;
	sub_8815C948(ctx, base);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// bl 0x8815c860
	ctx.lr = 0x8809F254;
	sub_8815C860(ctx, base);
loc_8809F254:
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// addi r11,r11,80
	ctx.r11.s64 = ctx.r11.s64 + 80;
	// srawi r10,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 1;
	// addze r9,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r9.s64 = temp.s64;
	// subf r11,r9,r30
	ctx.r11.s64 = ctx.r30.s64 - ctx.r9.s64;
	// bne cr6,0x8809f298
	if (!ctx.cr6.eq) goto loc_8809F298;
	// clrlwi r7,r11,16
	ctx.r7.u64 = ctx.r11.u32 & 0xFFFF;
	// sth r21,166(r1)
	PPC_STORE_U16(ctx.r1.u32 + 166, ctx.r21.u16);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r24,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r24.u32);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,55
	ctx.r3.s64 = 55;
	// bl 0x8815c948
	ctx.lr = 0x8809F290;
	sub_8815C948(ctx, base);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// bl 0x8815c860
	ctx.lr = 0x8809F298;
	sub_8815C860(ctx, base);
loc_8809F298:
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
loc_8809F2A4:
	// lwz r11,120(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8809f2d0
	if (ctx.cr6.eq) goto loc_8809F2D0;
	// lwz r11,112(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r11.u32);
	// bge 0x8809f2f0
	if (!ctx.cr0.lt) goto loc_8809F2F0;
	// lwz r11,116(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// stw r11,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r11.u32);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// b 0x88071188
	__restgprlr_20(ctx, base);
	return;
loc_8809F2D0:
	// lwz r11,104(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// bge 0x8809f2f0
	if (!ctx.cr0.lt) goto loc_8809F2F0;
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// lwz r10,124(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// stw r11,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// stw r10,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r10.u32);
loc_8809F2F0:
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// b 0x88071188
	__restgprlr_20(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809F2F8"))) PPC_WEAK_FUNC(sub_8809F2F8);
PPC_FUNC_IMPL(__imp__sub_8809F2F8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x8809F300;
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
	// blt cr6,0x8809f324
	if (ctx.cr6.lt) goto loc_8809F324;
	// lwz r11,188(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 188);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x8809f330
	goto loc_8809F330;
loc_8809F324:
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 184);
	// lwz r11,168(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 168);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_8809F330:
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
	ctx.lr = 0x8809F36C;
	sub_880F52C8(ctx, base);
	// lwz r11,1620(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1620);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8809f3c8
	if (!ctx.cr6.eq) goto loc_8809F3C8;
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
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
	ctx.lr = 0x8809F394;
	sub_880F5438(ctx, base);
	// lwz r10,1624(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1624);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8809f3c8
	if (!ctx.cr6.eq) goto loc_8809F3C8;
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
	ctx.lr = 0x8809F3C8;
	sub_881607F8(ctx, base);
loc_8809F3C8:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809F3D0"))) PPC_WEAK_FUNC(sub_8809F3D0);
PPC_FUNC_IMPL(__imp__sub_8809F3D0) {
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
	// lwz r10,1620(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1620);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8809f41c
	if (ctx.cr6.eq) goto loc_8809F41C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8809f2f8
	ctx.lr = 0x8809F404;
	sub_8809F2F8(ctx, base);
	// lwz r10,204(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 204);
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r11.u32);
	// bl 0x88094220
	ctx.lr = 0x8809F418;
	sub_88094220(ctx, base);
	// b 0x8809f558
	goto loc_8809F558;
loc_8809F41C:
	// lwz r11,132(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// lis r6,-30643
	ctx.r6.s64 = -2008219648;
	// lwz r7,128(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
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
	// beq cr6,0x8809f484
	if (ctx.cr6.eq) goto loc_8809F484;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x8809f494
	goto loc_8809F494;
loc_8809F484:
	// lwz r10,200(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 200);
	// addi r10,r10,51
	ctx.r10.s64 = ctx.r10.s64 + 51;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r9,r6
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r6.u32);
loc_8809F494:
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
	// ble 0x8809f504
	if (!ctx.cr0.gt) goto loc_8809F504;
	// lis r8,128
	ctx.r8.s64 = 8388608;
	// lis r5,320
	ctx.r5.s64 = 20971520;
	// subf r4,r8,r9
	ctx.r4.s64 = ctx.r9.s64 - ctx.r8.s64;
	// cmpw cr6,r4,r5
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r5.s32, ctx.xer);
	// bge cr6,0x8809f504
	if (!ctx.cr6.lt) goto loc_8809F504;
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
	// ble cr6,0x8809f504
	if (!ctx.cr6.gt) goto loc_8809F504;
	// lis r10,280
	ctx.r10.s64 = 18350080;
	// subf r9,r8,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r8.s64;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x8809f528
	if (ctx.cr6.lt) goto loc_8809F528;
loc_8809F504:
	// lwz r11,196(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 196);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8809f530
	if (ctx.cr6.eq) goto loc_8809F530;
	// lwz r11,204(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 204);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x88094220
	ctx.lr = 0x8809F524;
	sub_88094220(ctx, base);
	// b 0x8809f558
	goto loc_8809F558;
loc_8809F528:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,196(r31)
	PPC_STORE_U32(ctx.r31.u32 + 196, ctx.r11.u32);
loc_8809F530:
	// lwz r11,152(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 152);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 152, ctx.r11.u32);
	// bge 0x8809f558
	if (!ctx.cr0.lt) goto loc_8809F558;
	// lwz r11,160(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 160);
	// lwz r10,156(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 156);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// clrlwi r8,r9,29
	ctx.r8.u64 = ctx.r9.u32 & 0x7;
	// stw r10,152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 152, ctx.r10.u32);
	// stw r8,160(r31)
	PPC_STORE_U32(ctx.r31.u32 + 160, ctx.r8.u32);
loc_8809F558:
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

__attribute__((alias("__imp__sub_8809F570"))) PPC_WEAK_FUNC(sub_8809F570);
PPC_FUNC_IMPL(__imp__sub_8809F570) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x8809F578;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30710
	ctx.r11.s64 = -2012610560;
	// li r4,276
	ctx.r4.s64 = 276;
	// addi r5,r11,-2704
	ctx.r5.s64 = ctx.r11.s64 + -2704;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x8809F590;
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
	ctx.lr = 0x8809F5A4;
	sub_88073BD0(ctx, base);
	// stw r30,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// li r4,21
	ctx.r4.s64 = 21;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x881556a0
	ctx.lr = 0x8809F5B4;
	sub_881556A0(ctx, base);
	// lis r9,-30710
	ctx.r9.s64 = -2012610560;
	// stw r3,204(r31)
	PPC_STORE_U32(ctx.r31.u32 + 204, ctx.r3.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r8,r9,-4960
	ctx.r8.s64 = ctx.r9.s64 + -4960;
	// stw r31,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r31.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r8,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r8.u32);
	// lwz r7,204(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 204);
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// lwz r8,204(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 204);
	// lwz r11,28(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809f604
	if (ctx.cr6.eq) goto loc_8809F604;
loc_8809F5EC:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8809f790
	if (ctx.cr6.eq) goto loc_8809F790;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8809f5ec
	if (!ctx.cr6.eq) goto loc_8809F5EC;
loc_8809F604:
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
loc_8809F608:
	// li r8,8
	ctx.r8.s64 = 8;
	// stw r5,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r5.u32);
	// addi r9,r31,8
	ctx.r9.s64 = ctx.r31.s64 + 8;
	// li r7,61
	ctx.r7.s64 = 61;
	// stw r8,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
	// stw r9,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r9.u32);
	// li r6,216
	ctx.r6.s64 = 216;
	// stw r7,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// li r4,3
	ctx.r4.s64 = 3;
	// stw r8,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r8.u32);
	// stw r8,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r8.u32);
	// stw r8,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r8.u32);
	// lwz r3,32(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// stw r6,168(r30)
	PPC_STORE_U32(ctx.r30.u32 + 168, ctx.r6.u32);
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// lwz r11,36(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
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
	// stw r7,200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 200, ctx.r7.u32);
	// lwz r6,132(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 132);
	// lwz r3,2304(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 2304);
	// stw r3,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// lwz r11,136(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 136);
	// stw r11,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
	// stw r4,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r4.u32);
	// lwz r9,140(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 140);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8809f690
	if (ctx.cr6.eq) goto loc_8809F690;
	// li r11,-3
	ctx.r11.s64 = -3;
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
loc_8809F690:
	// lis r11,16838
	ctx.r11.s64 = 1103495168;
	// lwz r7,132(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// lis r4,-30671
	ctx.r4.s64 = -2010054656;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// ori r9,r11,20077
	ctx.r9.u64 = ctx.r11.u64 | 20077;
	// stw r10,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r10.u32);
	// stw r10,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r10.u32);
	// li r6,6
	ctx.r6.s64 = 6;
	// mr r29,r9
	ctx.r29.u64 = ctx.r9.u64;
	// stw r10,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r10.u32);
	// mr r28,r9
	ctx.r28.u64 = ctx.r9.u64;
	// stw r7,212(r31)
	PPC_STORE_U32(ctx.r31.u32 + 212, ctx.r7.u32);
	// lwz r9,4200(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4200);
	// li r11,16
	ctx.r11.s64 = 16;
	// stw r10,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r10.u32);
	// lis r3,-30710
	ctx.r3.s64 = -2012610560;
	// mullw r9,r9,r28
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r28.s32);
	// stw r10,164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 164, ctx.r10.u32);
	// stw r10,244(r31)
	PPC_STORE_U32(ctx.r31.u32 + 244, ctx.r10.u32);
	// stw r6,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r6.u32);
	// stw r6,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r6.u32);
	// stw r8,172(r31)
	PPC_STORE_U32(ctx.r31.u32 + 172, ctx.r8.u32);
	// stw r5,236(r31)
	PPC_STORE_U32(ctx.r31.u32 + 236, ctx.r5.u32);
	// stw r5,240(r31)
	PPC_STORE_U32(ctx.r31.u32 + 240, ctx.r5.u32);
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// stw r11,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// stw r11,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
	// addi r9,r9,12345
	ctx.r9.s64 = ctx.r9.s64 + 12345;
	// stw r11,232(r31)
	PPC_STORE_U32(ctx.r31.u32 + 232, ctx.r11.u32);
	// li r10,12
	ctx.r10.s64 = 12;
	// stw r11,220(r31)
	PPC_STORE_U32(ctx.r31.u32 + 220, ctx.r11.u32);
	// stw r9,4200(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4200, ctx.r9.u32);
	// mullw r9,r9,r28
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r28.s32);
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// stw r11,216(r31)
	PPC_STORE_U32(ctx.r31.u32 + 216, ctx.r11.u32);
	// addi r7,r9,12345
	ctx.r7.s64 = ctx.r9.s64 + 12345;
	// addi r5,r3,-4656
	ctx.r5.s64 = ctx.r3.s64 + -4656;
	// li r8,128
	ctx.r8.s64 = 128;
	// li r6,32
	ctx.r6.s64 = 32;
	// lis r3,-30710
	ctx.r3.s64 = -2012610560;
	// stw r8,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r8.u32);
	// lis r11,-30710
	ctx.r11.s64 = -2012610560;
	// stw r6,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r6.u32);
	// lis r10,-30710
	ctx.r10.s64 = -2012610560;
	// addi r8,r3,-3120
	ctx.r8.s64 = ctx.r3.s64 + -3120;
	// addi r6,r10,-4952
	ctx.r6.s64 = ctx.r10.s64 + -4952;
	// lhz r9,4200(r4)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r4.u32 + 4200);
	// stw r7,4200(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4200, ctx.r7.u32);
	// li r7,2
	ctx.r7.s64 = 2;
	// clrlwi r9,r9,29
	ctx.r9.u64 = ctx.r9.u32 & 0x7;
	// stw r7,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r7.u32);
	// addi r7,r11,-4888
	ctx.r7.s64 = ctx.r11.s64 + -4888;
	// stw r9,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r9.u32);
	// lhz r9,4200(r4)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r4.u32 + 4200);
	// clrlwi r4,r9,29
	ctx.r4.u64 = ctx.r9.u32 & 0x7;
	// stw r4,160(r31)
	PPC_STORE_U32(ctx.r31.u32 + 160, ctx.r4.u32);
	// stw r5,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r5.u32);
	// lwz r3,180(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 180);
	// stw r3,184(r31)
	PPC_STORE_U32(ctx.r31.u32 + 184, ctx.r3.u32);
	// stw r8,64(r30)
	PPC_STORE_U32(ctx.r30.u32 + 64, ctx.r8.u32);
	// stw r7,68(r30)
	PPC_STORE_U32(ctx.r30.u32 + 68, ctx.r7.u32);
	// stw r6,84(r30)
	PPC_STORE_U32(ctx.r30.u32 + 84, ctx.r6.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8809F790:
	// lwz r9,24(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8809f7a0
	if (ctx.cr6.eq) goto loc_8809F7A0;
	// stw r9,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r9.u32);
loc_8809F7A0:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x8809f608
	goto loc_8809F608;
}

__attribute__((alias("__imp__sub_8809F7A8"))) PPC_WEAK_FUNC(sub_8809F7A8);
PPC_FUNC_IMPL(__imp__sub_8809F7A8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8809F7AC"))) PPC_WEAK_FUNC(sub_8809F7AC);
PPC_FUNC_IMPL(__imp__sub_8809F7AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8809F7B0"))) PPC_WEAK_FUNC(sub_8809F7B0);
PPC_FUNC_IMPL(__imp__sub_8809F7B0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x8809F7B8;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r26,-30597
	ctx.r26.s64 = -2005204992;
	// lis r10,128
	ctx.r10.s64 = 8388608;
	// addi r11,r11,20
	ctx.r11.s64 = ctx.r11.s64 + 20;
	// li r27,8
	ctx.r27.s64 = 8;
	// addi r30,r11,16
	ctx.r30.s64 = ctx.r11.s64 + 16;
	// lis r11,545
	ctx.r11.s64 = 35717120;
	// lwz r31,-11932(r26)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r26.u32 + -11932);
	// ori r29,r10,8320
	ctx.r29.u64 = ctx.r10.u64 | 8320;
	// ori r28,r11,65280
	ctx.r28.u64 = ctx.r11.u64 | 65280;
loc_8809F7E4:
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r4,-4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + -4);
	// li r6,210
	ctx.r6.s64 = 210;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// ori r3,r3,45196
	ctx.r3.u64 = ctx.r3.u64 | 45196;
	// bl 0x881538c0
	ctx.lr = 0x8809F7FC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809f818
	if (ctx.cr6.eq) goto loc_8809F818;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// stw r29,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r29.u32);
	// or r10,r11,r28
	ctx.r10.u64 = ctx.r11.u64 | ctx.r28.u64;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_8809F818:
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// addi r30,r30,164
	ctx.r30.s64 = ctx.r30.s64 + 164;
	// bne 0x8809f7e4
	if (!ctx.cr0.eq) goto loc_8809F7E4;
	// stw r31,-11932(r26)
	PPC_STORE_U32(ctx.r26.u32 + -11932, ctx.r31.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809F830"))) PPC_WEAK_FUNC(sub_8809F830);
PPC_FUNC_IMPL(__imp__sub_8809F830) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071120
	ctx.lr = 0x8809F838;
	__savegprlr_14(ctx, base);
	// stfd f30,-168(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -168, ctx.f30.u64);
	// stfd f31,-160(r1)
	PPC_STORE_U64(ctx.r1.u32 + -160, ctx.f31.u64);
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r28,2304(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// addi r7,r11,9552
	ctx.r7.s64 = ctx.r11.s64 + 9552;
	// li r27,0
	ctx.r27.s64 = 0;
	// li r14,1
	ctx.r14.s64 = 1;
	// lwz r11,16(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8809f8c8
	if (ctx.cr6.lt) goto loc_8809F8C8;
	// bne cr6,0x8809f94c
	if (!ctx.cr6.eq) goto loc_8809F94C;
	// lwz r11,1348(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 1348);
	// lwz r10,1340(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 1340);
	// rlwinm r9,r11,2,21,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x7FC;
	// lwz r8,1344(r28)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r28.u32 + 1344);
	// lwzx r6,r9,r7
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r7.u32);
	// rlwinm r5,r6,4,0,27
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// srawi r9,r5,14
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x3FFF) != 0);
	ctx.r9.s64 = ctx.r5.s32 >> 14;
	// addic. r11,r8,-2
	ctx.xer.ca = ctx.r8.u32 > 1;
	ctx.r11.s64 = ctx.r8.s64 + -2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// add r3,r9,r10
	ctx.r3.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r3,1340(r28)
	PPC_STORE_U32(ctx.r28.u32 + 1340, ctx.r3.u32);
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r10,8(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8, ctx.r10.u32);
	// lwz r9,12(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// stw r9,12(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12, ctx.r9.u32);
	// stw r11,1344(r28)
	PPC_STORE_U32(ctx.r28.u32 + 1344, ctx.r11.u32);
	// bgt 0x8809f94c
	if (ctx.cr0.gt) goto loc_8809F94C;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x88094220
	ctx.lr = 0x8809F8B8;
	sub_88094220(ctx, base);
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// lfd f30,-168(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -168);
	// lfd f31,-160(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
loc_8809F8C8:
	// lwz r11,1344(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 1344);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r11,1344(r28)
	PPC_STORE_U32(ctx.r28.u32 + 1344, ctx.r11.u32);
	// cmpwi cr6,r11,288
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 288, ctx.xer);
	// blt cr6,0x8809f8e4
	if (ctx.cr6.lt) goto loc_8809F8E4;
	// li r11,288
	ctx.r11.s64 = 288;
	// stw r11,1344(r28)
	PPC_STORE_U32(ctx.r28.u32 + 1344, ctx.r11.u32);
loc_8809F8E4:
	// lwz r11,1352(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 1352);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,1352(r28)
	PPC_STORE_U32(ctx.r28.u32 + 1352, ctx.r11.u32);
	// bge 0x8809f908
	if (!ctx.cr0.lt) goto loc_8809F908;
	// lwz r11,1348(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 1348);
	// lwz r10,1356(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 1356);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stw r9,1348(r28)
	PPC_STORE_U32(ctx.r28.u32 + 1348, ctx.r9.u32);
	// stw r10,1352(r28)
	PPC_STORE_U32(ctx.r28.u32 + 1352, ctx.r10.u32);
loc_8809F908:
	// lwz r10,1348(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 1348);
	// lwz r11,1340(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 1340);
	// rlwinm r9,r10,2,21,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0x7FC;
	// lwzx r8,r9,r7
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r7.u32);
	// stw r27,1336(r28)
	PPC_STORE_U32(ctx.r28.u32 + 1336, ctx.r27.u32);
	// rlwinm r6,r8,4,0,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// srawi r10,r6,14
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x3FFF) != 0);
	ctx.r10.s64 = ctx.r6.s32 >> 14;
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r5,1340(r28)
	PPC_STORE_U32(ctx.r28.u32 + 1340, ctx.r5.u32);
	// lwz r3,8(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r3,8(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8, ctx.r3.u32);
	// lwz r11,12(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// stw r11,12(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12, ctx.r11.u32);
	// lwz r10,1684(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 1684);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8809f94c
	if (ctx.cr6.eq) goto loc_8809F94C;
	// stw r14,16(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16, ctx.r14.u32);
loc_8809F94C:
	// li r9,8
	ctx.r9.s64 = 8;
	// addi r31,r28,20
	ctx.r31.s64 = ctx.r28.s64 + 20;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// addi r10,r31,-156
	ctx.r10.s64 = ctx.r31.s64 + -156;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8809F960:
	// clrlwi r9,r11,23
	ctx.r9.u64 = ctx.r11.u32 & 0x1FF;
	// lwz r8,1344(r28)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r28.u32 + 1344);
	// rlwinm r6,r11,2,21,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x7FC;
	// addi r5,r9,128
	ctx.r5.s64 = ctx.r9.s64 + 128;
	// addi r11,r11,64
	ctx.r11.s64 = ctx.r11.s64 + 64;
	// rlwinm r3,r5,2,21,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x7FC;
	// lwzx r9,r6,r7
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r7.u32);
	// mullw r9,r9,r8
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// lwzx r6,r3,r7
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r7.u32);
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
	// stw r9,156(r10)
	PPC_STORE_U32(ctx.r10.u32 + 156, ctx.r9.u32);
	// stw r8,160(r10)
	PPC_STORE_U32(ctx.r10.u32 + 160, ctx.r8.u32);
	// stwu r27,164(r10)
	ea = 164 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r27.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8809f960
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8809F960;
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// lis r20,-30643
	ctx.r20.s64 = -2008219648;
	// addi r10,r11,13168
	ctx.r10.s64 = ctx.r11.s64 + 13168;
	// mr r23,r27
	ctx.r23.u64 = ctx.r27.u64;
	// addi r22,r4,1788
	ctx.r22.s64 = ctx.r4.s64 + 1788;
	// lis r21,500
	ctx.r21.s64 = 32768000;
	// lwz r26,26276(r20)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r20.u32 + 26276);
	// li r24,2
	ctx.r24.s64 = 2;
	// lfd f31,24(r10)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r10.u32 + 24);
	// li r19,3
	ctx.r19.s64 = 3;
	// lfd f30,16(r10)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r10.u32 + 16);
	// li r15,48
	ctx.r15.s64 = 48;
	// li r16,12
	ctx.r16.s64 = 12;
	// li r17,17
	ctx.r17.s64 = 17;
	// li r18,4
	ctx.r18.s64 = 4;
loc_8809F9E4:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r5,1336(r28)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r28.u32 + 1336);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x88153608
	ctx.lr = 0x8809F9F4;
	sub_88153608(ctx, base);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r5,1340(r28)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r28.u32 + 1340);
	// bl 0x88153548
	ctx.lr = 0x8809FA04;
	sub_88153548(ctx, base);
	// lwz r11,120(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r6,116(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// subf r7,r11,r21
	ctx.r7.s64 = ctx.r21.s64 - ctx.r11.s64;
	// lwz r8,112(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// extsw r3,r6
	ctx.r3.s64 = ctx.r6.s32;
	// lwz r9,12(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// extsw r4,r7
	ctx.r4.s64 = ctx.r7.s32;
	// lwz r10,8(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8);
	// std r3,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r3.u64);
	// extsw r5,r8
	ctx.r5.s64 = ctx.r8.s32;
	// std r4,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r4.u64);
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f0
	ctx.f8.f64 = double(ctx.f0.s64);
	// lfd f13,88(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fmul f6,f8,f31
	ctx.f6.f64 = ctx.f8.f64 * ctx.f31.f64;
	// lfd f11,96(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// fcfid f9,f11
	ctx.f9.f64 = double(ctx.f11.s64);
	// fmul f10,f12,f31
	ctx.f10.f64 = ctx.f12.f64 * ctx.f31.f64;
	// fdiv f7,f30,f9
	ctx.f7.f64 = ctx.f30.f64 / ctx.f9.f64;
	// fmul f5,f10,f7
	ctx.f5.f64 = ctx.f10.f64 * ctx.f7.f64;
	// fmul f4,f6,f7
	ctx.f4.f64 = ctx.f6.f64 * ctx.f7.f64;
	// fctiwz f3,f5
	ctx.f3.s64 = (ctx.f5.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f3,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.f3.u64);
	// lwz r8,108(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// add r29,r8,r9
	ctx.r29.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// fctiwz f2,f4
	ctx.f2.s64 = (ctx.f4.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f4.f64));
	// stfd f2,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.f2.u64);
	// lwz r11,108(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// add r30,r10,r11
	ctx.r30.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,1340(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 1340);
	// add r11,r11,r23
	ctx.r11.u64 = ctx.r11.u64 + ctx.r23.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r6,12(r28)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// lwz r5,8(r28)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8);
	// bl 0x88153070
	ctx.lr = 0x8809FAA8;
	sub_88153070(ctx, base);
	// clrlwi r10,r3,16
	ctx.r10.u64 = ctx.r3.u32 & 0xFFFF;
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// rotlwi r8,r10,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r10,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r10.u32);
	// stw r10,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r10.u32);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// stw r8,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r8.u32);
	// stw r9,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r9.u32);
	// blt cr6,0x8809fc94
	if (ctx.cr6.lt) goto loc_8809FC94;
	// beq cr6,0x8809fc08
	if (ctx.cr6.eq) goto loc_8809FC08;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x8809fd18
	if (!ctx.cr6.lt) goto loc_8809FD18;
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// bge 0x8809fd18
	if (!ctx.cr0.lt) goto loc_8809FD18;
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// stw r11,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// bl 0x88095590
	ctx.lr = 0x8809FB04;
	sub_88095590(ctx, base);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r9,84(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x8809fb28
	if (!ctx.cr6.eq) goto loc_8809FB28;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lwz r4,8(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8);
	// lwz r5,12(r28)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// bl 0x88095590
	ctx.lr = 0x8809FB24;
	sub_88095590(ctx, base);
	// stw r3,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r3.u32);
loc_8809FB28:
	// lwz r30,12(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lwz r29,16(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x88095590
	ctx.lr = 0x8809FB40;
	sub_88095590(ctx, base);
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// clrlwi r9,r3,23
	ctx.r9.u64 = ctx.r3.u32 & 0x1FF;
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// subf r10,r11,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r11.s64;
	// clrlwi r10,r10,23
	ctx.r10.u64 = ctx.r10.u32 & 0x1FF;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8809fb64
	if (!ctx.cr6.eq) goto loc_8809FB64;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// b 0x8809fb9c
	goto loc_8809FB9C;
loc_8809FB64:
	// cmpwi cr6,r10,256
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 256, ctx.xer);
	// blt cr6,0x8809fb84
	if (ctx.cr6.lt) goto loc_8809FB84;
	// subfic r10,r10,512
	ctx.xer.ca = ctx.r10.u32 <= 512;
	ctx.r10.s64 = 512 - ctx.r10.s64;
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// ble cr6,0x8809fb98
	if (!ctx.cr6.gt) goto loc_8809FB98;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// b 0x8809fb9c
	goto loc_8809FB9C;
loc_8809FB84:
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// ble cr6,0x8809fb98
	if (!ctx.cr6.gt) goto loc_8809FB98;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// b 0x8809fb9c
	goto loc_8809FB9C;
loc_8809FB98:
	// clrlwi r11,r9,16
	ctx.r11.u64 = ctx.r9.u32 & 0xFFFF;
loc_8809FB9C:
	// lwz r26,26276(r20)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r20.u32 + 26276);
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// lwz r10,96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// stw r11,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// bne cr6,0x8809fbf0
	if (!ctx.cr6.eq) goto loc_8809FBF0;
	// clrlwi r7,r11,16
	ctx.r7.u64 = ctx.r11.u32 & 0xFFFF;
	// stw r25,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r25.u32);
	// extsh r6,r10
	ctx.r6.s64 = ctx.r10.s16;
	// sth r27,150(r1)
	PPC_STORE_U16(ctx.r1.u32 + 150, ctx.r27.u16);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,72
	ctx.r3.s64 = 72;
	// bl 0x8815c948
	ctx.lr = 0x8809FBD4;
	sub_8815C948(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809fbf0
	if (ctx.cr6.eq) goto loc_8809FBF0;
	// stw r14,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r14.u32);
	// li r5,72
	ctx.r5.s64 = 72;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r3,r3,36
	ctx.r3.s64 = ctx.r3.s64 + 36;
	// bl 0x88072260
	ctx.lr = 0x8809FBF0;
	sub_88072260(ctx, base);
loc_8809FBF0:
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
	// bgt 0x8809fd18
	if (ctx.cr0.gt) goto loc_8809FD18;
	// stw r27,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r27.u32);
	// b 0x8809fd18
	goto loc_8809FD18;
loc_8809FC08:
	// lwz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// bge 0x8809fd18
	if (!ctx.cr0.lt) goto loc_8809FD18;
	// lwz r9,44(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// addi r10,r10,256
	ctx.r10.s64 = ctx.r10.s64 + 256;
	// stw r9,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r9.u32);
	// bne cr6,0x8809fc7c
	if (!ctx.cr6.eq) goto loc_8809FC7C;
	// clrlwi r7,r10,16
	ctx.r7.u64 = ctx.r10.u32 & 0xFFFF;
	// stw r25,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r25.u32);
	// extsh r6,r11
	ctx.r6.s64 = ctx.r11.s16;
	// sth r27,150(r1)
	PPC_STORE_U16(ctx.r1.u32 + 150, ctx.r27.u16);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,27
	ctx.r3.s64 = 27;
	// bl 0x8815c948
	ctx.lr = 0x8809FC54;
	sub_8815C948(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809fc7c
	if (ctx.cr6.eq) goto loc_8809FC7C;
	// stb r24,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r24.u8);
	// li r5,72
	ctx.r5.s64 = 72;
	// sth r19,18(r3)
	PPC_STORE_U16(ctx.r3.u32 + 18, ctx.r19.u16);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// sth r15,20(r3)
	PPC_STORE_U16(ctx.r3.u32 + 20, ctx.r15.u16);
	// stw r14,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r14.u32);
	// addi r3,r3,36
	ctx.r3.s64 = ctx.r3.s64 + 36;
	// bl 0x88072260
	ctx.lr = 0x8809FC7C;
	sub_88072260(ctx, base);
loc_8809FC7C:
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// bgt 0x8809fd18
	if (ctx.cr0.gt) goto loc_8809FD18;
	// stw r27,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r27.u32);
	// b 0x8809fd18
	goto loc_8809FD18;
loc_8809FC94:
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// li r10,-32
	ctx.r10.s64 = -32;
	// stw r27,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r27.u32);
	// stw r10,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r10.u32);
	// stw r11,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// lwz r9,-96(r22)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r22.u32 + -96);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8809fcbc
	if (ctx.cr6.eq) goto loc_8809FCBC;
	// stw r14,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r14.u32);
	// b 0x8809fd18
	goto loc_8809FD18;
loc_8809FCBC:
	// li r11,-24
	ctx.r11.s64 = -24;
	// stw r27,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r27.u32);
	// lwz r10,0(r22)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// stw r10,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r10.u32);
	// stw r11,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
	// stw r10,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r10.u32);
	// lwz r9,-64(r22)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r22.u32 + -64);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8809fce8
	if (ctx.cr6.eq) goto loc_8809FCE8;
	// stw r24,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r24.u32);
	// b 0x8809fd18
	goto loc_8809FD18;
loc_8809FCE8:
	// lwz r11,32(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8809fd00
	if (ctx.cr6.eq) goto loc_8809FD00;
	// lwz r11,120(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// stw r27,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r27.u32);
	// stw r11,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r11.u32);
loc_8809FD00:
	// lwz r11,64(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 64);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8809fd18
	if (ctx.cr6.eq) goto loc_8809FD18;
	// lwz r11,152(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 152);
	// stw r27,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r27.u32);
	// stw r11,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r11.u32);
loc_8809FD18:
	// lwz r11,116(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8809fda8
	if (ctx.cr6.eq) goto loc_8809FDA8;
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
	// bge 0x8809fda8
	if (!ctx.cr0.lt) goto loc_8809FDA8;
	// lwz r9,112(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// lwz r11,124(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// lwz r5,16(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// stw r9,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r9.u32);
	// bne cr6,0x8809fd94
	if (!ctx.cr6.eq) goto loc_8809FD94;
	// clrlwi r7,r11,16
	ctx.r7.u64 = ctx.r11.u32 & 0xFFFF;
	// stw r25,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r25.u32);
	// extsh r6,r10
	ctx.r6.s64 = ctx.r10.s16;
	// sth r27,150(r1)
	PPC_STORE_U16(ctx.r1.u32 + 150, ctx.r27.u16);
	// li r3,27
	ctx.r3.s64 = 27;
	// bl 0x8815c948
	ctx.lr = 0x8809FD6C;
	sub_8815C948(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809fd94
	if (ctx.cr6.eq) goto loc_8809FD94;
	// stb r24,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r24.u8);
	// li r5,72
	ctx.r5.s64 = 72;
	// sth r19,18(r3)
	PPC_STORE_U16(ctx.r3.u32 + 18, ctx.r19.u16);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// sth r16,20(r3)
	PPC_STORE_U16(ctx.r3.u32 + 20, ctx.r16.u16);
	// stw r14,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r14.u32);
	// addi r3,r3,36
	ctx.r3.s64 = ctx.r3.s64 + 36;
	// bl 0x88072260
	ctx.lr = 0x8809FD94;
	sub_88072260(ctx, base);
loc_8809FD94:
	// lwz r11,116(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r11.u32);
	// bgt 0x8809fda8
	if (ctx.cr0.gt) goto loc_8809FDA8;
	// stw r27,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r27.u32);
loc_8809FDA8:
	// lwz r11,148(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8809fe40
	if (ctx.cr6.eq) goto loc_8809FE40;
	// lwz r11,140(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r11.u32);
	// bge 0x8809fe40
	if (!ctx.cr0.lt) goto loc_8809FE40;
	// lwz r9,144(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// lwz r11,156(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 156);
	// lwz r10,160(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 160);
	// lwz r5,16(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// stw r9,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r9.u32);
	// bne cr6,0x8809fe2c
	if (!ctx.cr6.eq) goto loc_8809FE2C;
	// clrlwi r7,r11,16
	ctx.r7.u64 = ctx.r11.u32 & 0xFFFF;
	// stw r25,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r25.u32);
	// extsh r6,r10
	ctx.r6.s64 = ctx.r10.s16;
	// sth r27,150(r1)
	PPC_STORE_U16(ctx.r1.u32 + 150, ctx.r27.u16);
	// li r3,17
	ctx.r3.s64 = 17;
	// bl 0x8815c948
	ctx.lr = 0x8809FDFC;
	sub_8815C948(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809fe2c
	if (ctx.cr6.eq) goto loc_8809FE2C;
	// stb r24,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r24.u8);
	// li r5,72
	ctx.r5.s64 = 72;
	// sth r17,18(r3)
	PPC_STORE_U16(ctx.r3.u32 + 18, ctx.r17.u16);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r3,r3,36
	ctx.r3.s64 = ctx.r3.s64 + 36;
	// sth r18,20(r30)
	PPC_STORE_U16(ctx.r30.u32 + 20, ctx.r18.u16);
	// stw r14,32(r30)
	PPC_STORE_U32(ctx.r30.u32 + 32, ctx.r14.u32);
	// bl 0x88072260
	ctx.lr = 0x8809FE28;
	sub_88072260(ctx, base);
	// sth r14,16(r30)
	PPC_STORE_U16(ctx.r30.u32 + 16, ctx.r14.u16);
loc_8809FE2C:
	// lwz r11,148(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r11.u32);
	// bgt 0x8809fe40
	if (ctx.cr0.gt) goto loc_8809FE40;
	// stw r27,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r27.u32);
loc_8809FE40:
	// addi r23,r23,64
	ctx.r23.s64 = ctx.r23.s64 + 64;
	// addi r31,r31,164
	ctx.r31.s64 = ctx.r31.s64 + 164;
	// addi r22,r22,4
	ctx.r22.s64 = ctx.r22.s64 + 4;
	// cmpwi cr6,r23,512
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 512, ctx.xer);
	// blt cr6,0x8809f9e4
	if (ctx.cr6.lt) goto loc_8809F9E4;
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// lfd f30,-168(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -168);
	// lfd f31,-160(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809FE64"))) PPC_WEAK_FUNC(sub_8809FE64);
PPC_FUNC_IMPL(__imp__sub_8809FE64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8809FE68"))) PPC_WEAK_FUNC(sub_8809FE68);
PPC_FUNC_IMPL(__imp__sub_8809FE68) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x8809FE70;
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
	// blt cr6,0x8809fe94
	if (ctx.cr6.lt) goto loc_8809FE94;
	// lwz r11,188(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 188);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x8809fea0
	goto loc_8809FEA0;
loc_8809FE94:
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 184);
	// lwz r11,168(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 168);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_8809FEA0:
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
	ctx.lr = 0x8809FEDC;
	sub_880F52C8(ctx, base);
	// lwz r11,1592(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1592);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8809ff38
	if (!ctx.cr6.eq) goto loc_8809FF38;
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
	ctx.lr = 0x8809FF04;
	sub_880F5438(ctx, base);
	// lwz r10,1596(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1596);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8809ff38
	if (!ctx.cr6.eq) goto loc_8809FF38;
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
	ctx.lr = 0x8809FF38;
	sub_881607F8(ctx, base);
loc_8809FF38:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809FF40"))) PPC_WEAK_FUNC(sub_8809FF40);
PPC_FUNC_IMPL(__imp__sub_8809FF40) {
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
	// lwz r10,1592(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1592);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8809ff88
	if (ctx.cr6.eq) goto loc_8809FF88;
	// bl 0x8809fe68
	ctx.lr = 0x8809FF6C;
	sub_8809FE68(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88094220
	ctx.lr = 0x8809FF74;
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
loc_8809FF88:
	// lwz r11,1364(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1364);
	// lis r6,-30643
	ctx.r6.s64 = -2008219648;
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// lwz r7,1360(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1360);
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// lwz r8,12(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r5,r10,9552
	ctx.r5.s64 = ctx.r10.s64 + 9552;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r4,r11,128
	ctx.r4.s64 = ctx.r11.s64 + 128;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,26272(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 26272);
	// rlwinm r4,r4,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x7FC;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwzx r11,r9,r5
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r5.u32);
	// lwzx r6,r4,r5
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r5.u32);
	// mullw r9,r11,r7
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r7.s32);
	// mullw r7,r6,r7
	ctx.r7.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r7.s32);
	// add r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r4,r7,r8
	ctx.r4.u64 = ctx.r7.u64 + ctx.r8.u64;
	// stw r5,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r5.u32);
	// stw r4,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r4.u32);
	// beq cr6,0x8809ffe8
	if (ctx.cr6.eq) goto loc_8809FFE8;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x880a0000
	goto loc_880A0000;
loc_8809FFE8:
	// lwz r11,1432(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1432);
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// addi r9,r11,51
	ctx.r9.s64 = ctx.r11.s64 + 51;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-11984(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11984);
	// lwzx r11,r8,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
loc_880A0000:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r9,1384(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1384);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// stw r11,1384(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1384, ctx.r11.u32);
	// bge 0x880a0034
	if (!ctx.cr0.lt) goto loc_880A0034;
	// lwz r11,1392(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1392);
	// lwz r10,1388(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1388);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// clrlwi r8,r9,29
	ctx.r8.u64 = ctx.r9.u32 & 0x7;
	// stw r10,1384(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1384, ctx.r10.u32);
	// stw r8,1392(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1392, ctx.r8.u32);
loc_880A0034:
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

__attribute__((alias("__imp__sub_880A0048"))) PPC_WEAK_FUNC(sub_880A0048);
PPC_FUNC_IMPL(__imp__sub_880A0048) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x880A0050;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30710
	ctx.r11.s64 = -2012610560;
	// li r4,1532
	ctx.r4.s64 = 1532;
	// addi r5,r11,72
	ctx.r5.s64 = ctx.r11.s64 + 72;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x880A0068;
	sub_88094290(ctx, base);
	// li r5,1532
	ctx.r5.s64 = 1532;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,2304(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2304);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x880A007C;
	sub_88073BD0(ctx, base);
	// lis r9,16838
	ctx.r9.s64 = 1103495168;
	// lis r29,-30671
	ctx.r29.s64 = -2010054656;
	// stw r30,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// ori r11,r9,20077
	ctx.r11.u64 = ctx.r9.u64 | 20077;
	// lwz r4,32(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// li r10,216
	ctx.r10.s64 = 216;
	// mr r6,r11
	ctx.r6.u64 = ctx.r11.u64;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// stw r10,168(r30)
	PPC_STORE_U32(ctx.r30.u32 + 168, ctx.r10.u32);
	// lwz r11,4200(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4200);
	// lis r28,-30710
	ctx.r28.s64 = -2012610560;
	// stw r4,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r4.u32);
	// li r8,16
	ctx.r8.s64 = 16;
	// mullw r11,r11,r5
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r5.s32);
	// lwz r27,1364(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1364);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,4200(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4200, ctx.r11.u32);
	// mullw r11,r11,r5
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r5.s32);
	// addi r6,r11,12345
	ctx.r6.s64 = ctx.r11.s64 + 12345;
	// lhz r11,4200(r29)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r29.u32 + 4200);
	// stw r6,4200(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4200, ctx.r6.u32);
	// clrlwi r26,r11,29
	ctx.r26.u64 = ctx.r11.u32 & 0x7;
	// lwz r11,36(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// li r7,8
	ctx.r7.s64 = 8;
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r6,100(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 100);
	// addi r11,r6,-1
	ctx.r11.s64 = ctx.r6.s64 + -1;
	// rlwinm r5,r11,1,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// addi r6,r31,20
	ctx.r6.s64 = ctx.r31.s64 + 20;
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
	// li r3,2
	ctx.r3.s64 = 2;
	// and r5,r5,r11
	ctx.r5.u64 = ctx.r5.u64 & ctx.r11.u64;
	// lhz r11,4200(r29)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r29.u32 + 4200);
	// clrlwi r29,r11,29
	ctx.r29.u64 = ctx.r11.u32 & 0x7;
	// stw r5,1432(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1432, ctx.r5.u32);
	// li r4,32
	ctx.r4.s64 = 32;
	// li r25,4
	ctx.r25.s64 = 4;
	// lwz r24,132(r30)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r30.u32 + 132);
	// addi r28,r28,-2000
	ctx.r28.s64 = ctx.r28.s64 + -2000;
	// addi r11,r6,-4
	ctx.r11.s64 = ctx.r6.s64 + -4;
	// lwz r6,2304(r24)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r24.u32 + 2304);
	// li r5,-64
	ctx.r5.s64 = -64;
	// stw r8,1488(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1488, ctx.r8.u32);
	// stw r8,1440(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1440, ctx.r8.u32);
	// stw r8,1452(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1452, ctx.r8.u32);
	// stw r8,1476(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1476, ctx.r8.u32);
	// stw r8,1472(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1472, ctx.r8.u32);
	// stw r7,1404(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1404, ctx.r7.u32);
	// stw r6,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r6.u32);
	// stw r27,1468(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1468, ctx.r27.u32);
	// stw r26,1372(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1372, ctx.r26.u32);
	// stw r3,1380(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1380, ctx.r3.u32);
	// stw r9,1388(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1388, ctx.r9.u32);
	// stw r29,1392(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1392, ctx.r29.u32);
	// stw r9,1396(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1396, ctx.r9.u32);
	// stw r4,1400(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1400, ctx.r4.u32);
	// stw r10,1492(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1492, ctx.r10.u32);
	// stw r10,1496(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1496, ctx.r10.u32);
	// stw r9,1500(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1500, ctx.r9.u32);
	// stw r7,1444(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1444, ctx.r7.u32);
	// stw r25,1460(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1460, ctx.r25.u32);
	// stw r10,1356(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1356, ctx.r10.u32);
	// stw r10,1352(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1352, ctx.r10.u32);
	// stw r28,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r28.u32);
	// lwz r8,1412(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1412);
	// stw r5,1332(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1332, ctx.r5.u32);
	// li r5,128
	ctx.r5.s64 = 128;
	// stw r8,1416(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1416, ctx.r8.u32);
	// li r6,-36
	ctx.r6.s64 = -36;
	// li r8,-46
	ctx.r8.s64 = -46;
loc_880A01A0:
	// stw r10,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r10.u32);
	// stw r4,40(r11)
	PPC_STORE_U32(ctx.r11.u32 + 40, ctx.r4.u32);
	// stw r3,48(r11)
	PPC_STORE_U32(ctx.r11.u32 + 48, ctx.r3.u32);
	// stw r10,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r10.u32);
	// stw r5,56(r11)
	PPC_STORE_U32(ctx.r11.u32 + 56, ctx.r5.u32);
	// stw r10,68(r11)
	PPC_STORE_U32(ctx.r11.u32 + 68, ctx.r10.u32);
	// stw r7,72(r11)
	PPC_STORE_U32(ctx.r11.u32 + 72, ctx.r7.u32);
	// stw r10,76(r11)
	PPC_STORE_U32(ctx.r11.u32 + 76, ctx.r10.u32);
	// stw r9,80(r11)
	PPC_STORE_U32(ctx.r11.u32 + 80, ctx.r9.u32);
	// stw r10,84(r11)
	PPC_STORE_U32(ctx.r11.u32 + 84, ctx.r10.u32);
	// stw r10,88(r11)
	PPC_STORE_U32(ctx.r11.u32 + 88, ctx.r10.u32);
	// stw r10,92(r11)
	PPC_STORE_U32(ctx.r11.u32 + 92, ctx.r10.u32);
	// stw r10,96(r11)
	PPC_STORE_U32(ctx.r11.u32 + 96, ctx.r10.u32);
	// stw r10,100(r11)
	PPC_STORE_U32(ctx.r11.u32 + 100, ctx.r10.u32);
	// stw r10,104(r11)
	PPC_STORE_U32(ctx.r11.u32 + 104, ctx.r10.u32);
	// stw r7,108(r11)
	PPC_STORE_U32(ctx.r11.u32 + 108, ctx.r7.u32);
	// stw r10,112(r11)
	PPC_STORE_U32(ctx.r11.u32 + 112, ctx.r10.u32);
	// stw r9,116(r11)
	PPC_STORE_U32(ctx.r11.u32 + 116, ctx.r9.u32);
	// stw r10,120(r11)
	PPC_STORE_U32(ctx.r11.u32 + 120, ctx.r10.u32);
	// stw r9,124(r11)
	PPC_STORE_U32(ctx.r11.u32 + 124, ctx.r9.u32);
	// stw r10,128(r11)
	PPC_STORE_U32(ctx.r11.u32 + 128, ctx.r10.u32);
	// stw r6,132(r11)
	PPC_STORE_U32(ctx.r11.u32 + 132, ctx.r6.u32);
	// stw r10,136(r11)
	PPC_STORE_U32(ctx.r11.u32 + 136, ctx.r10.u32);
	// stw r10,140(r11)
	PPC_STORE_U32(ctx.r11.u32 + 140, ctx.r10.u32);
	// stw r10,144(r11)
	PPC_STORE_U32(ctx.r11.u32 + 144, ctx.r10.u32);
	// stw r10,148(r11)
	PPC_STORE_U32(ctx.r11.u32 + 148, ctx.r10.u32);
	// stw r10,152(r11)
	PPC_STORE_U32(ctx.r11.u32 + 152, ctx.r10.u32);
	// stw r9,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r9.u32);
	// stw r10,160(r11)
	PPC_STORE_U32(ctx.r11.u32 + 160, ctx.r10.u32);
	// stwu r8,164(r11)
	ea = 164 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x880a01a0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_880A01A0;
	// lis r11,-30710
	ctx.r11.s64 = -2012610560;
	// lis r10,-30710
	ctx.r10.s64 = -2012610560;
	// lis r9,-30710
	ctx.r9.s64 = -2012610560;
	// addi r8,r11,-192
	ctx.r8.s64 = ctx.r11.s64 + -192;
	// addi r7,r10,-2128
	ctx.r7.s64 = ctx.r10.s64 + -2128;
	// addi r6,r9,-2136
	ctx.r6.s64 = ctx.r9.s64 + -2136;
	// stw r8,64(r30)
	PPC_STORE_U32(ctx.r30.u32 + 64, ctx.r8.u32);
	// stw r7,68(r30)
	PPC_STORE_U32(ctx.r30.u32 + 68, ctx.r7.u32);
	// stw r6,84(r30)
	PPC_STORE_U32(ctx.r30.u32 + 84, ctx.r6.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A0248"))) PPC_WEAK_FUNC(sub_880A0248);
PPC_FUNC_IMPL(__imp__sub_880A0248) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// li r5,12
	ctx.r5.s64 = 12;
	// addi r3,r11,-18804
	ctx.r3.s64 = ctx.r11.s64 + -18804;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x88073bd0
	sub_88073BD0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A025C"))) PPC_WEAK_FUNC(sub_880A025C);
PPC_FUNC_IMPL(__imp__sub_880A025C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A0260"))) PPC_WEAK_FUNC(sub_880A0260);
PPC_FUNC_IMPL(__imp__sub_880A0260) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// lhz r10,5836(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 5836);
	// addi r9,r11,-18804
	ctx.r9.s64 = ctx.r11.s64 + -18804;
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
loc_880A028C:
	// lhz r9,92(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 92);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x880a02a8
	if (ctx.cr6.eq) goto loc_880A02A8;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880a028c
	if (!ctx.cr6.eq) goto loc_880A028C;
	// blr 
	return;
loc_880A02A8:
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r10,96(r11)
	PPC_STORE_U16(ctx.r11.u32 + 96, ctx.r10.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880A02B4"))) PPC_WEAK_FUNC(sub_880A02B4);
PPC_FUNC_IMPL(__imp__sub_880A02B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A02B8"))) PPC_WEAK_FUNC(sub_880A02B8);
PPC_FUNC_IMPL(__imp__sub_880A02B8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// lhz r10,5836(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 5836);
	// addi r9,r11,-18804
	ctx.r9.s64 = ctx.r11.s64 + -18804;
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
loc_880A02E4:
	// lhz r9,92(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 92);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x880a0300
	if (ctx.cr6.eq) goto loc_880A0300;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880a02e4
	if (!ctx.cr6.eq) goto loc_880A02E4;
	// blr 
	return;
loc_880A0300:
	// li r10,1
	ctx.r10.s64 = 1;
	// sth r10,96(r11)
	PPC_STORE_U16(ctx.r11.u32 + 96, ctx.r10.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880A030C"))) PPC_WEAK_FUNC(sub_880A030C);
PPC_FUNC_IMPL(__imp__sub_880A030C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A0310"))) PPC_WEAK_FUNC(sub_880A0310);
PPC_FUNC_IMPL(__imp__sub_880A0310) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// lhz r10,5836(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 5836);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwz r11,-18804(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -18804);
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
loc_880A0338:
	// lhz r9,92(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 92);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x880a0354
	if (ctx.cr6.eq) goto loc_880A0354;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880a0338
	if (!ctx.cr6.eq) goto loc_880A0338;
	// blr 
	return;
loc_880A0354:
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r10,96(r11)
	PPC_STORE_U16(ctx.r11.u32 + 96, ctx.r10.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880A0360"))) PPC_WEAK_FUNC(sub_880A0360);
PPC_FUNC_IMPL(__imp__sub_880A0360) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r10,2304(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r11,26472(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26472);
	// cmpwi cr6,r11,128
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 128, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r8,26468(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26468);
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
loc_880A037C:
	// addi r11,r8,1
	ctx.r11.s64 = ctx.r8.s64 + 1;
	// srawi r8,r11,7
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7F) != 0);
	ctx.r8.s64 = ctx.r11.s32 >> 7;
	// addze r7,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r7.s64 = temp.s64;
	// rlwinm r8,r7,7,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 7) & 0xFFFFFF80;
	// subf r11,r8,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r8.s64;
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r11,26468(r10)
	PPC_STORE_U32(ctx.r10.u32 + 26468, ctx.r11.u32);
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
	// add r7,r11,r7
	ctx.r7.u64 = ctx.r11.u64 + ctx.r7.u64;
	// rlwinm r11,r7,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r7,14180(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 14180);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x880a03c4
	if (ctx.cr6.eq) goto loc_880A03C4;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// cmpwi cr6,r3,128
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 128, ctx.xer);
	// blt cr6,0x880a037c
	if (ctx.cr6.lt) goto loc_880A037C;
	// blr 
	return;
loc_880A03C4:
	// lis r8,-30643
	ctx.r8.s64 = -2008219648;
	// stw r4,14192(r11)
	PPC_STORE_U32(ctx.r11.u32 + 14192, ctx.r4.u32);
	// stw r5,14196(r11)
	PPC_STORE_U32(ctx.r11.u32 + 14196, ctx.r5.u32);
	// li r7,3
	ctx.r7.s64 = 3;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r6,14216(r11)
	PPC_STORE_U32(ctx.r11.u32 + 14216, ctx.r6.u32);
	// li r4,79
	ctx.r4.s64 = 79;
	// stw r7,14220(r11)
	PPC_STORE_U32(ctx.r11.u32 + 14220, ctx.r7.u32);
	// li r3,213
	ctx.r3.s64 = 213;
	// stw r7,14224(r11)
	PPC_STORE_U32(ctx.r11.u32 + 14224, ctx.r7.u32);
	// lwz r8,26428(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 26428);
	// stw r5,14180(r11)
	PPC_STORE_U32(ctx.r11.u32 + 14180, ctx.r5.u32);
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r9,14184(r11)
	PPC_STORE_U32(ctx.r11.u32 + 14184, ctx.r9.u32);
	// stw r9,14240(r11)
	PPC_STORE_U32(ctx.r11.u32 + 14240, ctx.r9.u32);
	// stw r9,14188(r11)
	PPC_STORE_U32(ctx.r11.u32 + 14188, ctx.r9.u32);
	// stw r9,14208(r11)
	PPC_STORE_U32(ctx.r11.u32 + 14208, ctx.r9.u32);
	// stw r9,14212(r11)
	PPC_STORE_U32(ctx.r11.u32 + 14212, ctx.r9.u32);
	// stw r4,14228(r11)
	PPC_STORE_U32(ctx.r11.u32 + 14228, ctx.r4.u32);
	// stw r3,14232(r11)
	PPC_STORE_U32(ctx.r11.u32 + 14232, ctx.r3.u32);
	// stw r9,14236(r11)
	PPC_STORE_U32(ctx.r11.u32 + 14236, ctx.r9.u32);
	// stw r8,14244(r11)
	PPC_STORE_U32(ctx.r11.u32 + 14244, ctx.r8.u32);
	// lwz r11,26472(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26472);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r7,26472(r10)
	PPC_STORE_U32(ctx.r10.u32 + 26472, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880A042C"))) PPC_WEAK_FUNC(sub_880A042C);
PPC_FUNC_IMPL(__imp__sub_880A042C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A0430"))) PPC_WEAK_FUNC(sub_880A0430);
PPC_FUNC_IMPL(__imp__sub_880A0430) {
	PPC_FUNC_PROLOGUE();
	// li r10,128
	ctx.r10.s64 = 128;
	// lwz r9,2304(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// addi r11,r9,1884
	ctx.r11.s64 = ctx.r9.s64 + 1884;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// li r10,0
	ctx.r10.s64 = 0;
loc_880A0444:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r8,1
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 1, ctx.xer);
	// bne cr6,0x880a0454
	if (!ctx.cr6.eq) goto loc_880A0454;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_880A0454:
	// addi r11,r11,96
	ctx.r11.s64 = ctx.r11.s64 + 96;
	// bdnz 0x880a0444
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_880A0444;
	// stw r10,14176(r9)
	PPC_STORE_U32(ctx.r9.u32 + 14176, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880A0464"))) PPC_WEAK_FUNC(sub_880A0464);
PPC_FUNC_IMPL(__imp__sub_880A0464) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A0468"))) PPC_WEAK_FUNC(sub_880A0468);
PPC_FUNC_IMPL(__imp__sub_880A0468) {
	PPC_FUNC_PROLOGUE();
	// cmpwi cr6,r3,256
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 256, ctx.xer);
	// bltlr cr6
	if (ctx.cr6.lt) return;
	// subfic r3,r3,512
	ctx.xer.ca = ctx.r3.u32 <= 512;
	ctx.r3.s64 = 512 - ctx.r3.s64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880A0478"))) PPC_WEAK_FUNC(sub_880A0478);
PPC_FUNC_IMPL(__imp__sub_880A0478) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x880A0480;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r11,26472(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 26472);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880a0598
	if (ctx.cr6.eq) goto loc_880A0598;
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// addi r8,r31,14180
	ctx.r8.s64 = ctx.r31.s64 + 14180;
	// li r4,128
	ctx.r4.s64 = 128;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r30,16
	ctx.r30.s64 = 16;
	// addi r6,r11,9552
	ctx.r6.s64 = ctx.r11.s64 + 9552;
loc_880A04AC:
	// lwz r11,0(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x880a058c
	if (!ctx.cr6.eq) goto loc_880A058C;
	// lwz r11,4(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a0574
	if (!ctx.cr6.eq) goto loc_880A0574;
	// lwz r9,28(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r7,32(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 32);
	// clrlwi r11,r9,23
	ctx.r11.u64 = ctx.r9.u32 & 0x1FF;
	// lwz r10,12(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// rlwinm r29,r9,2,21,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x7FC;
	// lwz r9,16(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// rlwinm r28,r11,2,21,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x7FC;
	// lwzx r11,r29,r6
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r6.u32);
	// mullw r11,r11,r7
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r7.s32);
	// lwzx r29,r28,r6
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r28.u32 + ctx.r6.u32);
	// mullw r7,r29,r7
	ctx.r7.s64 = int64_t(ctx.r29.s32) * int64_t(ctx.r7.s32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r10,r7,r9
	ctx.r10.u64 = ctx.r7.u64 + ctx.r9.u64;
	// stw r11,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r11.u32);
	// rotlwi r7,r11,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// stw r10,16(r8)
	PPC_STORE_U32(ctx.r8.u32 + 16, ctx.r10.u32);
	// bl 0x88094af0
	ctx.lr = 0x880A0510;
	sub_88094AF0(ctx, base);
	// lwz r11,48(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 48);
	// add r10,r3,r7
	ctx.r10.u64 = ctx.r3.u64 + ctx.r7.u64;
	// addic. r11,r11,-2
	ctx.xer.ca = ctx.r11.u32 > 1;
	ctx.r11.s64 = ctx.r11.s64 + -2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r10,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r10.u32);
	// stw r11,48(r8)
	PPC_STORE_U32(ctx.r8.u32 + 48, ctx.r11.u32);
	// bgt 0x880a052c
	if (ctx.cr0.gt) goto loc_880A052C;
	// stw r5,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r5.u32);
loc_880A052C:
	// lwz r11,36(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 36);
	// addic. r11,r11,-4
	ctx.xer.ca = ctx.r11.u32 > 3;
	ctx.r11.s64 = ctx.r11.s64 + -4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,36(r8)
	PPC_STORE_U32(ctx.r8.u32 + 36, ctx.r11.u32);
	// bge 0x880a0544
	if (!ctx.cr0.lt) goto loc_880A0544;
	// stw r5,36(r8)
	PPC_STORE_U32(ctx.r8.u32 + 36, ctx.r5.u32);
	// stw r5,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r5.u32);
loc_880A0544:
	// lwz r11,40(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 40);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,40(r8)
	PPC_STORE_U32(ctx.r8.u32 + 40, ctx.r11.u32);
	// bge 0x880a0574
	if (!ctx.cr0.lt) goto loc_880A0574;
	// lwz r11,56(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	// lwz r10,44(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 44);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,56(r8)
	PPC_STORE_U32(ctx.r8.u32 + 56, ctx.r11.u32);
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// stw r10,40(r8)
	PPC_STORE_U32(ctx.r8.u32 + 40, ctx.r10.u32);
	// ble cr6,0x880a0574
	if (!ctx.cr6.gt) goto loc_880A0574;
	// stw r30,56(r8)
	PPC_STORE_U32(ctx.r8.u32 + 56, ctx.r30.u32);
loc_880A0574:
	// lwz r11,0(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a058c
	if (!ctx.cr6.eq) goto loc_880A058C;
	// lwz r11,26472(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 26472);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,26472(r31)
	PPC_STORE_U32(ctx.r31.u32 + 26472, ctx.r11.u32);
loc_880A058C:
	// addic. r4,r4,-1
	ctx.xer.ca = ctx.r4.u32 > 0;
	ctx.r4.s64 = ctx.r4.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// addi r8,r8,96
	ctx.r8.s64 = ctx.r8.s64 + 96;
	// bne 0x880a04ac
	if (!ctx.cr0.eq) goto loc_880A04AC;
loc_880A0598:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A05A0"))) PPC_WEAK_FUNC(sub_880A05A0);
PPC_FUNC_IMPL(__imp__sub_880A05A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071124
	ctx.lr = 0x880A05A8;
	__savegprlr_15(ctx, base);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r27,2304(r3)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
	// lwz r11,14176(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 14176);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880a0754
	if (ctx.cr6.eq) goto loc_880A0754;
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// lis r9,-30658
	ctx.r9.s64 = -2009202688;
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// addi r31,r27,1884
	ctx.r31.s64 = ctx.r27.s64 + 1884;
	// li r15,128
	ctx.r15.s64 = 128;
	// lwz r18,26276(r10)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26276);
	// li r23,15
	ctx.r23.s64 = 15;
	// lwz r25,156(r9)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r9.u32 + 156);
	// lis r24,16
	ctx.r24.s64 = 1048576;
	// li r26,0
	ctx.r26.s64 = 0;
	// li r16,255
	ctx.r16.s64 = 255;
	// li r19,1
	ctx.r19.s64 = 1;
	// li r17,16
	ctx.r17.s64 = 16;
	// li r20,-3
	ctx.r20.s64 = -3;
	// li r21,72
	ctx.r21.s64 = 72;
	// addi r28,r11,9552
	ctx.r28.s64 = ctx.r11.s64 + 9552;
loc_880A0600:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x880a0748
	if (!ctx.cr6.eq) goto loc_880A0748;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x880a081c
	if (ctx.cr6.lt) goto loc_880A081C;
	// bne cr6,0x880a0730
	if (!ctx.cr6.eq) goto loc_880A0730;
	// lwz r29,68(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// divw r30,r29,r23
	ctx.r30.s32 = ppc_divw(ctx.r29.s32, ctx.r23.s32);
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r7,12(r27)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// add r6,r30,r10
	ctx.r6.u64 = ctx.r30.u64 + ctx.r10.u64;
	// lwz r8,8(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 8);
	// addi r9,r11,-4
	ctx.r9.s64 = ctx.r11.s64 + -4;
	// clrlwi r10,r6,23
	ctx.r10.u64 = ctx.r6.u32 & 0x1FF;
	// subf r7,r24,r7
	ctx.r7.s64 = ctx.r7.s64 - ctx.r24.s64;
	// addi r5,r10,128
	ctx.r5.s64 = ctx.r10.s64 + 128;
	// stw r10,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r10.u32);
	// rlwinm r4,r10,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r3,r5,2,21,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x7FC;
	// cmpwi cr6,r9,4
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 4, ctx.xer);
	// lwzx r6,r4,r28
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r28.u32);
	// mullw r6,r6,r11
	ctx.r6.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r11.s32);
	// lwzx r5,r3,r28
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r28.u32);
	// mullw r11,r5,r11
	ctx.r11.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r11.s32);
	// stw r9,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r9.u32);
	// bge cr6,0x880a0674
	if (!ctx.cr6.lt) goto loc_880A0674;
	// stw r26,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r26.u32);
loc_880A0674:
	// lwz r5,36(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r6,r6,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r5,1
	ctx.r11.s64 = ctx.r5.s64 + 1;
	// add r4,r6,r8
	ctx.r4.u64 = ctx.r6.u64 + ctx.r8.u64;
	// add r5,r3,r7
	ctx.r5.u64 = ctx.r3.u64 + ctx.r7.u64;
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r4,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r4.u32);
	// cmpwi cr6,r11,64
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 64, ctx.xer);
	// stw r5,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r5.u32);
	// blt cr6,0x880a06a4
	if (ctx.cr6.lt) goto loc_880A06A4;
	// stw r26,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r26.u32);
loc_880A06A4:
	// cmpwi cr6,r9,960
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 960, ctx.xer);
	// bge cr6,0x880a06c4
	if (!ctx.cr6.lt) goto loc_880A06C4;
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r11.u32);
	// cmpwi cr6,r11,255
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 255, ctx.xer);
	// blt cr6,0x880a06c4
	if (ctx.cr6.lt) goto loc_880A06C4;
	// stw r16,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r16.u32);
loc_880A06C4:
	// cmpwi cr6,r9,512
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 512, ctx.xer);
	// bge cr6,0x880a0710
	if (!ctx.cr6.lt) goto loc_880A0710;
	// srawi r11,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r9.s32 >> 1;
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// stw r11,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bgt cr6,0x880a06e4
	if (ctx.cr6.gt) goto loc_880A06E4;
	// stw r26,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r26.u32);
loc_880A06E4:
	// cmpwi cr6,r9,512
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 512, ctx.xer);
	// bge cr6,0x880a0710
	if (!ctx.cr6.lt) goto loc_880A0710;
	// lwz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// bge 0x880a0710
	if (!ctx.cr0.lt) goto loc_880A0710;
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r9,44(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// stw r9,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r9.u32);
loc_880A0710:
	// lwz r11,26496(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 26496);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a0730
	if (!ctx.cr6.eq) goto loc_880A0730;
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880a075c
	if (ctx.cr6.eq) goto loc_880A075C;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
loc_880A0730:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a0748
	if (!ctx.cr6.eq) goto loc_880A0748;
loc_880A073C:
	// lwz r11,14176(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 14176);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,14176(r27)
	PPC_STORE_U32(ctx.r27.u32 + 14176, ctx.r11.u32);
loc_880A0748:
	// addic. r15,r15,-1
	ctx.xer.ca = ctx.r15.u32 > 0;
	ctx.r15.s64 = ctx.r15.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r15.s32, 0, ctx.xer);
	// addi r31,r31,96
	ctx.r31.s64 = ctx.r31.s64 + 96;
	// bne 0x880a0600
	if (!ctx.cr0.eq) goto loc_880A0600;
loc_880A0754:
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x88071174
	__restgprlr_15(ctx, base);
	return;
loc_880A075C:
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// stw r19,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r19.u32);
	// stw r17,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r17.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r19,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r19.u32);
	// stw r19,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r19.u32);
	// stw r26,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r26.u32);
	// beq cr6,0x880a07c8
	if (ctx.cr6.eq) goto loc_880A07C8;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x880a07c8
	if (ctx.cr6.eq) goto loc_880A07C8;
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// beq cr6,0x880a07c8
	if (ctx.cr6.eq) goto loc_880A07C8;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x880a0800
	if (!ctx.cr6.eq) goto loc_880A0800;
	// rlwinm r11,r30,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 8) & 0xFFFFFF00;
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bne cr6,0x880a0800
	if (!ctx.cr6.eq) goto loc_880A0800;
	// clrlwi r7,r11,16
	ctx.r7.u64 = ctx.r11.u32 & 0xFFFF;
	// stw r22,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r22.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// sth r26,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r26.u16);
	// li r3,132
	ctx.r3.s64 = 132;
	// bl 0x8815c948
	ctx.lr = 0x880A07BC;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x880A07C4;
	sub_8815C860(ctx, base);
	// b 0x880a0800
	goto loc_880A0800;
loc_880A07C8:
	// addi r11,r25,-40
	ctx.r11.s64 = ctx.r25.s64 + -40;
	// stw r21,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r21.u32);
	// divw r9,r29,r20
	ctx.r9.s32 = ppc_divw(ctx.r29.s32, ctx.r20.s32);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// rlwinm r11,r30,7,0,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 7) & 0xFFFFFF80;
	// stw r9,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r9.u32);
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// subfic r7,r25,32
	ctx.xer.ca = ctx.r25.u32 <= 32;
	ctx.r7.s64 = 32 - ctx.r25.s64;
	// li r4,134
	ctx.r4.s64 = 134;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x88094858
	ctx.lr = 0x880A0800;
	sub_88094858(ctx, base);
loc_880A0800:
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// ble cr6,0x880a0730
	if (!ctx.cr6.gt) goto loc_880A0730;
	// stw r26,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r26.u32);
	// b 0x880a0730
	goto loc_880A0730;
loc_880A081C:
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r8,32(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// clrlwi r11,r9,23
	ctx.r11.u64 = ctx.r9.u32 & 0x1FF;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// rlwinm r7,r9,2,21,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x7FC;
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r6,r11,128
	ctx.r6.s64 = ctx.r11.s64 + 128;
	// rlwinm r5,r6,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// lwzx r4,r7,r28
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r28.u32);
	// mullw r11,r4,r8
	ctx.r11.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r8.s32);
	// lwzx r7,r5,r28
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r28.u32);
	// mullw r8,r7,r8
	ctx.r8.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r8.s32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// rotlwi r6,r11,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// stw r10,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r10.u32);
	// bl 0x88094af0
	ctx.lr = 0x880A0868;
	sub_88094AF0(ctx, base);
	// lwz r5,48(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// add r4,r3,r6
	ctx.r4.u64 = ctx.r3.u64 + ctx.r6.u64;
	// addic. r11,r5,-2
	ctx.xer.ca = ctx.r5.u32 > 1;
	ctx.r11.s64 = ctx.r5.s64 + -2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r4,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r4.u32);
	// stw r11,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// bgt 0x880a0730
	if (ctx.cr0.gt) goto loc_880A0730;
	// stw r26,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r26.u32);
	// b 0x880a073c
	goto loc_880A073C;
}

__attribute__((alias("__imp__sub_880A0888"))) PPC_WEAK_FUNC(sub_880A0888);
PPC_FUNC_IMPL(__imp__sub_880A0888) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x880A0890;
	__savegprlr_28(ctx, base);
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r11,14176(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 14176);
	// cmpwi cr6,r11,128
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 128, ctx.xer);
	// bge cr6,0x880a09c4
	if (!ctx.cr6.lt) goto loc_880A09C4;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r31,14172(r29)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r29.u32 + 14172);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
loc_880A08AC:
	// addi r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 1;
	// srawi r31,r11,7
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7F) != 0);
	ctx.r31.s64 = ctx.r11.s32 >> 7;
	// addze r31,r31
	temp.s64 = ctx.r31.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r31.u32;
	ctx.r31.s64 = temp.s64;
	// rlwinm r31,r31,7,0,24
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 7) & 0xFFFFFF80;
	// subf r11,r31,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r31.s64;
	// rlwinm r30,r11,1,0,30
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r11,14172(r29)
	PPC_STORE_U32(ctx.r29.u32 + 14172, ctx.r11.u32);
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// rlwinm r11,r11,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// lwz r30,1884(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1884);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x880a08f4
	if (ctx.cr6.eq) goto loc_880A08F4;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// cmpwi cr6,r28,128
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 128, ctx.xer);
	// blt cr6,0x880a08ac
	if (ctx.cr6.lt) goto loc_880A08AC;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_880A08F4:
	// li r31,1
	ctx.r31.s64 = 1;
	// stw r4,1888(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1888, ctx.r4.u32);
	// stw r3,1944(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1944, ctx.r3.u32);
	// cmplwi cr6,r4,1
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 1, ctx.xer);
	// stw r31,1884(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1884, ctx.r31.u32);
	// blt cr6,0x880a0984
	if (ctx.cr6.lt) goto loc_880A0984;
	// bne cr6,0x880a09b8
	if (!ctx.cr6.eq) goto loc_880A09B8;
	// lis r4,-30671
	ctx.r4.s64 = -2010054656;
	// stw r9,1916(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1916, ctx.r9.u32);
	// lis r9,16838
	ctx.r9.s64 = 1103495168;
	// stw r5,1896(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1896, ctx.r5.u32);
	// stw r10,1952(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1952, ctx.r10.u32);
	// li r10,32
	ctx.r10.s64 = 32;
	// ori r5,r9,20077
	ctx.r5.u64 = ctx.r9.u64 | 20077;
	// stw r6,1900(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1900, ctx.r6.u32);
	// stw r10,1924(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1924, ctx.r10.u32);
	// li r6,4
	ctx.r6.s64 = 4;
	// lwz r9,4200(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4200);
	// li r31,255
	ctx.r31.s64 = 255;
	// li r30,40
	ctx.r30.s64 = 40;
	// stw r8,1976(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1976, ctx.r8.u32);
	// mullw r9,r9,r5
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r5.s32);
	// stw r6,1928(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1928, ctx.r6.u32);
	// stw r31,1932(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1932, ctx.r31.u32);
	// stw r30,1940(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1940, ctx.r30.u32);
	// stw r3,1948(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1948, ctx.r3.u32);
	// stw r3,1968(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1968, ctx.r3.u32);
	// stw r3,1972(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1972, ctx.r3.u32);
	// addi r10,r9,12345
	ctx.r10.s64 = ctx.r9.s64 + 12345;
	// li r5,144
	ctx.r5.s64 = 144;
	// stw r10,4200(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4200, ctx.r10.u32);
	// lhz r10,4200(r4)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r4.u32 + 4200);
	// clrlwi r4,r10,26
	ctx.r4.u64 = ctx.r10.u32 & 0x3F;
	// stw r5,1964(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1964, ctx.r5.u32);
	// stw r4,1920(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1920, ctx.r4.u32);
	// b 0x880a09ac
	goto loc_880A09AC;
loc_880A0984:
	// stw r5,1896(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1896, ctx.r5.u32);
	// li r4,63
	ctx.r4.s64 = 63;
	// li r5,30
	ctx.r5.s64 = 30;
	// stw r6,1900(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1900, ctx.r6.u32);
	// stw r9,1916(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1916, ctx.r9.u32);
	// stw r10,1920(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1920, ctx.r10.u32);
	// stw r3,1924(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1924, ctx.r3.u32);
	// stw r3,1928(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1928, ctx.r3.u32);
	// stw r4,1932(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1932, ctx.r4.u32);
	// stw r5,1940(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1940, ctx.r5.u32);
loc_880A09AC:
	// stw r7,1936(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1936, ctx.r7.u32);
	// stw r8,1912(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1912, ctx.r8.u32);
	// stw r3,1892(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1892, ctx.r3.u32);
loc_880A09B8:
	// lwz r11,14176(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 14176);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,14176(r29)
	PPC_STORE_U32(ctx.r29.u32 + 14176, ctx.r11.u32);
loc_880A09C4:
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A09C8"))) PPC_WEAK_FUNC(sub_880A09C8);
PPC_FUNC_IMPL(__imp__sub_880A09C8) {
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

__attribute__((alias("__imp__sub_880A0A10"))) PPC_WEAK_FUNC(sub_880A0A10);
PPC_FUNC_IMPL(__imp__sub_880A0A10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071120
	ctx.lr = 0x880A0A18;
	__savegprlr_14(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r10,26472(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26472);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880a0c3c
	if (ctx.cr6.eq) goto loc_880A0C3C;
	// li r10,128
	ctx.r10.s64 = 128;
	// lis r18,-30597
	ctx.r18.s64 = -2005204992;
	// addi r19,r11,14180
	ctx.r19.s64 = ctx.r11.s64 + 14180;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,255
	ctx.r9.s64 = 16711680;
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// lwz r28,-11932(r18)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r18.u32 + -11932);
	// li r14,10
	ctx.r14.s64 = 10;
	// ori r16,r10,65280
	ctx.r16.u64 = ctx.r10.u64 | 65280;
	// ori r17,r9,65535
	ctx.r17.u64 = ctx.r9.u64 | 65535;
	// addi r27,r11,9552
	ctx.r27.s64 = ctx.r11.s64 + 9552;
loc_880A0A5C:
	// lwz r11,0(r19)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r19.u32 + 0);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x880a0c24
	if (!ctx.cr6.eq) goto loc_880A0C24;
	// lwz r11,4(r19)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r19.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a0c24
	if (!ctx.cr6.eq) goto loc_880A0C24;
	// lwz r21,36(r19)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r19.u32 + 36);
	// li r26,0
	ctx.r26.s64 = 0;
	// lwz r10,56(r19)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r19.u32 + 56);
	// rlwinm r11,r21,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r25,12(r19)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r19.u32 + 12);
	// subfic r24,r10,419
	ctx.xer.ca = ctx.r10.u32 <= 419;
	ctx.r24.s64 = 419 - ctx.r10.s64;
	// lwz r23,16(r19)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r19.u32 + 16);
	// add r9,r21,r11
	ctx.r9.u64 = ctx.r21.u64 + ctx.r11.u64;
	// lwz r22,64(r19)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r19.u32 + 64);
	// lwz r20,48(r19)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r19.u32 + 48);
	// subfic r15,r10,404
	ctx.xer.ca = ctx.r10.u32 <= 404;
	ctx.r15.s64 = 404 - ctx.r10.s64;
	// divw r29,r9,r14
	ctx.r29.s32 = ppc_divw(ctx.r9.s32, ctx.r14.s32);
loc_880A0AA4:
	// srawi r11,r26,3
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0x7) != 0);
	ctx.r11.s64 = ctx.r26.s32 >> 3;
	// li r6,214
	ctx.r6.s64 = 214;
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// add r10,r11,r22
	ctx.r10.u64 = ctx.r11.u64 + ctx.r22.u64;
	// clrlwi r11,r10,23
	ctx.r11.u64 = ctx.r10.u32 & 0x1FF;
	// addi r9,r11,128
	ctx.r9.s64 = ctx.r11.s64 + 128;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r9,2,21,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x7FC;
	// lwzx r5,r8,r27
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r27.u32);
	// lwzx r4,r7,r27
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r27.u32);
	// mullw r10,r5,r29
	ctx.r10.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r29.s32);
	// mullw r11,r4,r29
	ctx.r11.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r29.s32);
	// add r31,r11,r23
	ctx.r31.u64 = ctx.r11.u64 + ctx.r23.u64;
	// add r30,r10,r25
	ctx.r30.u64 = ctx.r10.u64 + ctx.r25.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x881538c0
	ctx.lr = 0x880A0AEC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880a0b10
	if (ctx.cr6.eq) goto loc_880A0B10;
	// lis r11,545
	ctx.r11.s64 = 35717120;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// stw r16,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r16.u32);
	// rlwimi r11,r20,8,16,23
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r20.u32, 8) & 0xFF00) | (ctx.r11.u64 & 0xFFFFFFFFFFFF00FF);
	// or r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_880A0B10:
	// li r6,215
	ctx.r6.s64 = 215;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r15
	ctx.r3.u64 = ctx.r15.u64;
	// bl 0x881538c0
	ctx.lr = 0x880A0B24;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880a0b4c
	if (ctx.cr6.eq) goto loc_880A0B4C;
	// lis r11,545
	ctx.r11.s64 = 35717120;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// stw r17,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r17.u32);
	// rlwimi r11,r20,8,16,23
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r20.u32, 8) & 0xFF00) | (ctx.r11.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r28,-11932(r18)
	PPC_STORE_U32(ctx.r18.u32 + -11932, ctx.r28.u32);
	// or r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_880A0B4C:
	// addi r26,r26,512
	ctx.r26.s64 = ctx.r26.s64 + 512;
	// cmpwi cr6,r26,4096
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 4096, ctx.xer);
	// blt cr6,0x880a0aa4
	if (ctx.cr6.lt) goto loc_880A0AA4;
	// rlwinm r11,r21,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 1) & 0xFFFFFFFE;
	// li r26,0
	ctx.r26.s64 = 0;
	// add r11,r21,r11
	ctx.r11.u64 = ctx.r21.u64 + ctx.r11.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// divw r29,r10,r14
	ctx.r29.s32 = ppc_divw(ctx.r10.s32, ctx.r14.s32);
loc_880A0B6C:
	// srawi r11,r26,3
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0x7) != 0);
	ctx.r11.s64 = ctx.r26.s32 >> 3;
	// li r6,214
	ctx.r6.s64 = 214;
	// addze r10,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r10.s64 = temp.s64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// subf r9,r22,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r22.s64;
	// clrlwi r11,r9,23
	ctx.r11.u64 = ctx.r9.u32 & 0x1FF;
	// addi r8,r11,128
	ctx.r8.s64 = ctx.r11.s64 + 128;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r5,r8,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x7FC;
	// lwzx r4,r7,r27
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r27.u32);
	// lwzx r10,r5,r27
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r27.u32);
	// mullw r11,r4,r29
	ctx.r11.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r29.s32);
	// mullw r10,r10,r29
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r29.s32);
	// add r31,r10,r23
	ctx.r31.u64 = ctx.r10.u64 + ctx.r23.u64;
	// add r30,r11,r25
	ctx.r30.u64 = ctx.r11.u64 + ctx.r25.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x881538c0
	ctx.lr = 0x880A0BB4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880a0bdc
	if (ctx.cr6.eq) goto loc_880A0BDC;
	// lis r11,545
	ctx.r11.s64 = 35717120;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// stw r16,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r16.u32);
	// rlwimi r11,r20,8,16,23
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r20.u32, 8) & 0xFF00) | (ctx.r11.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r28,-11932(r18)
	PPC_STORE_U32(ctx.r18.u32 + -11932, ctx.r28.u32);
	// or r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_880A0BDC:
	// li r6,215
	ctx.r6.s64 = 215;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r15
	ctx.r3.u64 = ctx.r15.u64;
	// bl 0x881538c0
	ctx.lr = 0x880A0BF0;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880a0c18
	if (ctx.cr6.eq) goto loc_880A0C18;
	// lis r11,545
	ctx.r11.s64 = 35717120;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// stw r17,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r17.u32);
	// rlwimi r11,r20,8,16,23
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r20.u32, 8) & 0xFF00) | (ctx.r11.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r28,-11932(r18)
	PPC_STORE_U32(ctx.r18.u32 + -11932, ctx.r28.u32);
	// or r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_880A0C18:
	// addi r26,r26,512
	ctx.r26.s64 = ctx.r26.s64 + 512;
	// cmpwi cr6,r26,4096
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 4096, ctx.xer);
	// blt cr6,0x880a0b6c
	if (ctx.cr6.lt) goto loc_880A0B6C;
loc_880A0C24:
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r19,r19,96
	ctx.r19.s64 = ctx.r19.s64 + 96;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bne 0x880a0a5c
	if (!ctx.cr0.eq) goto loc_880A0A5C;
	// stw r28,-11932(r18)
	PPC_STORE_U32(ctx.r18.u32 + -11932, ctx.r28.u32);
loc_880A0C3C:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A0C44"))) PPC_WEAK_FUNC(sub_880A0C44);
PPC_FUNC_IMPL(__imp__sub_880A0C44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A0C48"))) PPC_WEAK_FUNC(sub_880A0C48);
PPC_FUNC_IMPL(__imp__sub_880A0C48) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071128
	ctx.lr = 0x880A0C50;
	__savegprlr_16(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r21,r3
	ctx.r21.u64 = ctx.r3.u64;
	// lwz r10,14176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 14176);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880a0e28
	if (ctx.cr6.eq) goto loc_880A0E28;
	// lis r26,-30597
	ctx.r26.s64 = -2005204992;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// addi r31,r11,1884
	ctx.r31.s64 = ctx.r11.s64 + 1884;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r11,-30682
	ctx.r11.s64 = -2010775552;
	// lwz r28,-11932(r26)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r26.u32 + -11932);
	// li r16,128
	ctx.r16.s64 = 128;
	// lwz r22,-11984(r10)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11984);
	// lis r25,24
	ctx.r25.s64 = 1572864;
	// lis r19,48
	ctx.r19.s64 = 3145728;
	// lis r17,320
	ctx.r17.s64 = 20971520;
	// lis r20,-40
	ctx.r20.s64 = -2621440;
	// lis r18,280
	ctx.r18.s64 = 18350080;
	// li r23,3
	ctx.r23.s64 = 3;
	// ori r24,r9,39094
	ctx.r24.u64 = ctx.r9.u64 | 39094;
	// addi r27,r11,-30340
	ctx.r27.s64 = ctx.r11.s64 + -30340;
loc_880A0CA8:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x880a0e18
	if (!ctx.cr6.eq) goto loc_880A0E18;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x880a0dac
	if (ctx.cr6.lt) goto loc_880A0DAC;
	// bne cr6,0x880a0e18
	if (!ctx.cr6.eq) goto loc_880A0E18;
	// lwz r11,100(r21)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r21.u32 + 100);
	// lwz r30,16(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// lwz r29,12(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// add. r10,r30,r25
	ctx.r10.u64 = ctx.r30.u64 + ctx.r25.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// and r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 & ctx.r11.u64;
	// ble 0x880a0e18
	if (!ctx.cr0.gt) goto loc_880A0E18;
	// subf r10,r19,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r19.s64;
	// cmpw cr6,r10,r17
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r17.s32, ctx.xer);
	// bge cr6,0x880a0e18
	if (!ctx.cr6.lt) goto loc_880A0E18;
	// addi r11,r11,55
	ctx.r11.s64 = ctx.r11.s64 + 55;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r10,r22
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r22.u32);
	// add r9,r11,r29
	ctx.r9.u64 = ctx.r11.u64 + ctx.r29.u64;
	// add r11,r9,r25
	ctx.r11.u64 = ctx.r9.u64 + ctx.r25.u64;
	// cmpw cr6,r11,r20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r20.s32, ctx.xer);
	// ble cr6,0x880a0e18
	if (!ctx.cr6.gt) goto loc_880A0E18;
	// subf r11,r19,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r19.s64;
	// cmpw cr6,r11,r18
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r18.s32, ctx.xer);
	// bge cr6,0x880a0e18
	if (!ctx.cr6.lt) goto loc_880A0E18;
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r6,52(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addi r3,r11,372
	ctx.r3.s64 = ctx.r11.s64 + 372;
	// bl 0x881538c0
	ctx.lr = 0x880A0D34;
	sub_881538C0(ctx, base);
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// divw r10,r11,r23
	ctx.r10.s32 = ppc_divw(ctx.r11.s32, ctx.r23.s32);
	// clrlwi r11,r10,24
	ctx.r11.u64 = ctx.r10.u32 & 0xFF;
	// beq cr6,0x880a0d7c
	if (ctx.cr6.eq) goto loc_880A0D7C;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// lwz r7,88(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// subfic r11,r7,255
	ctx.xer.ca = ctx.r7.u32 <= 255;
	ctx.r11.s64 = 255 - ctx.r7.s64;
	// rlwinm r5,r11,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r6,r7,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// or r4,r5,r6
	ctx.r4.u64 = ctx.r5.u64 | ctx.r6.u64;
	// or r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 | ctx.r11.u64;
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880A0D7C:
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r6,52(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// clrlwi r11,r11,27
	ctx.r11.u64 = ctx.r11.u32 & 0x1F;
	// addi r3,r11,5212
	ctx.r3.s64 = ctx.r11.s64 + 5212;
	// bl 0x881538c0
	ctx.lr = 0x880A0D98;
	sub_881538C0(ctx, base);
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// divw r8,r9,r23
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r23.s32);
	// clrlwi r11,r8,24
	ctx.r11.u64 = ctx.r8.u32 & 0xFF;
	// b 0x880a0df4
	goto loc_880A0DF4;
loc_880A0DAC:
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r9,r27,1
	ctx.r9.s64 = ctx.r27.s64 + 1;
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// add r3,r11,r24
	ctx.r3.u64 = ctx.r11.u64 + ctx.r24.u64;
	// lwz r6,52(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lbzx r5,r7,r27
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r27.u32);
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
	// add r4,r9,r8
	ctx.r4.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x880A0DEC;
	sub_881538C0(ctx, base);
	// lwz r6,48(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// clrlwi r11,r6,24
	ctx.r11.u64 = ctx.r6.u32 & 0xFF;
loc_880A0DF4:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880a0e18
	if (ctx.cr6.eq) goto loc_880A0E18;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r28,-11932(r26)
	PPC_STORE_U32(ctx.r26.u32 + -11932, ctx.r28.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880A0E18:
	// addic. r16,r16,-1
	ctx.xer.ca = ctx.r16.u32 > 0;
	ctx.r16.s64 = ctx.r16.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r16.s32, 0, ctx.xer);
	// addi r31,r31,96
	ctx.r31.s64 = ctx.r31.s64 + 96;
	// bne 0x880a0ca8
	if (!ctx.cr0.eq) goto loc_880A0CA8;
	// stw r28,-11932(r26)
	PPC_STORE_U32(ctx.r26.u32 + -11932, ctx.r28.u32);
loc_880A0E28:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071178
	__restgprlr_16(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A0E30"))) PPC_WEAK_FUNC(sub_880A0E30);
PPC_FUNC_IMPL(__imp__sub_880A0E30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071120
	ctx.lr = 0x880A0E38;
	__savegprlr_14(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r19,2304(r3)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r14,-30597
	ctx.r14.s64 = -2005204992;
	// lwz r10,184(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// li r28,160
	ctx.r28.s64 = 160;
	// lwz r11,168(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// lwz r20,4(r6)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r31,0(r6)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r17,8(r19)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r19.u32 + 8);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// lwz r27,12(r19)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r19.u32 + 12);
	// addi r30,r11,2
	ctx.r30.s64 = ctx.r11.s64 + 2;
	// stw r3,292(r1)
	PPC_STORE_U32(ctx.r1.u32 + 292, ctx.r3.u32);
	// stw r14,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r14.u32);
	// stw r17,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r17.u32);
	// stw r27,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r27.u32);
	// bne cr6,0x880a0ef8
	if (!ctx.cr6.eq) goto loc_880A0EF8;
	// lis r8,-30597
	ctx.r8.s64 = -2005204992;
	// lwz r10,1156(r19)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r19.u32 + 1156);
	// addi r6,r11,-1
	ctx.r6.s64 = ctx.r11.s64 + -1;
	// lwz r9,1160(r19)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r19.u32 + 1160);
	// li r3,15785
	ctx.r3.s64 = 15785;
	// add r5,r9,r27
	ctx.r5.u64 = ctx.r9.u64 + ctx.r27.u64;
	// lwz r11,-11984(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -11984);
	// lwz r11,220(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 220);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r7,r10,r17
	ctx.r7.u64 = ctx.r10.u64 + ctx.r17.u64;
	// srawi r4,r7,16
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFFFF) != 0);
	ctx.r4.s64 = ctx.r7.s32 >> 16;
	// addze r10,r4
	temp.s64 = ctx.r4.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r10.s64 = temp.s64;
	// addi r10,r10,-160
	ctx.r10.s64 = ctx.r10.s64 + -160;
	// mulli r9,r10,240
	ctx.r9.s64 = ctx.r10.s64 * 240;
	// srawi r8,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 1;
	// addze r7,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r7.s64 = temp.s64;
	// divw r10,r7,r28
	ctx.r10.s32 = ppc_divw(ctx.r7.s32, ctx.r28.s32);
	// addi r4,r10,160
	ctx.r4.s64 = ctx.r10.s64 + 160;
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// subf r4,r11,r10
	ctx.r4.s64 = ctx.r10.s64 - ctx.r11.s64;
	// bl 0x881538c0
	ctx.lr = 0x880A0ED4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880a0ef8
	if (ctx.cr6.eq) goto loc_880A0EF8;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-11932(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + -11932);
	// oris r9,r10,518
	ctx.r9.u64 = ctx.r10.u64 | 33947648;
	// addi r24,r11,1
	ctx.r24.s64 = ctx.r11.s64 + 1;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r24,-11932(r14)
	PPC_STORE_U32(ctx.r14.u32 + -11932, ctx.r24.u32);
	// b 0x880a0efc
	goto loc_880A0EFC;
loc_880A0EF8:
	// lwz r24,-11932(r14)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r14.u32 + -11932);
loc_880A0EFC:
	// lwz r11,152(r19)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r19.u32 + 152);
	// li r9,10
	ctx.r9.s64 = 10;
	// lwz r8,564(r19)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r19.u32 + 564);
	// lwz r10,492(r19)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r19.u32 + 492);
	// divw r29,r11,r9
	ctx.r29.s32 = ppc_divw(ctx.r11.s32, ctx.r9.s32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x880a0f70
	if (!ctx.cr6.eq) goto loc_880A0F70;
	// lis r11,-30682
	ctx.r11.s64 = -2010775552;
	// rlwinm r5,r10,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r11,-30340
	ctx.r11.s64 = ctx.r11.s64 + -30340;
	// addis r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 65536;
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// addi r3,r3,-26442
	ctx.r3.s64 = ctx.r3.s64 + -26442;
	// li r9,0
	ctx.r9.s64 = 0;
	// lbzx r11,r5,r11
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r11.u32);
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// lbzx r10,r5,r4
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r4.u32);
	// extsb r5,r11
	ctx.r5.s64 = ctx.r11.s8;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// extsb r11,r10
	ctx.r11.s64 = ctx.r10.s8;
	// rlwinm r10,r5,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// add r4,r10,r17
	ctx.r4.u64 = ctx.r10.u64 + ctx.r17.u64;
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// add r5,r11,r27
	ctx.r5.u64 = ctx.r11.u64 + ctx.r27.u64;
	// bl 0x880a51a0
	ctx.lr = 0x880A0F6C;
	sub_880A51A0(ctx, base);
	// lwz r24,-11932(r14)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r14.u32 + -11932);
loc_880A0F70:
	// lis r9,-30643
	ctx.r9.s64 = -2008219648;
	// lwz r11,404(r19)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r19.u32 + 404);
	// add r10,r29,r27
	ctx.r10.u64 = ctx.r29.u64 + ctx.r27.u64;
	// stw r17,416(r19)
	PPC_STORE_U32(ctx.r19.u32 + 416, ctx.r17.u32);
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// stw r10,420(r19)
	PPC_STORE_U32(ctx.r19.u32 + 420, ctx.r10.u32);
	// stw r17,1184(r19)
	PPC_STORE_U32(ctx.r19.u32 + 1184, ctx.r17.u32);
	// lwz r16,26428(r9)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r9.u32 + 26428);
	// stw r10,1188(r19)
	PPC_STORE_U32(ctx.r19.u32 + 1188, ctx.r10.u32);
	// lwz r9,472(r19)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r19.u32 + 472);
	// cmplwi cr6,r9,7
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 7, ctx.xer);
	// stw r16,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r16.u32);
	// bgt cr6,0x880a1490
	if (ctx.cr6.gt) goto loc_880A1490;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x880a1044
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_880A1044;
	// bdzf 4*cr6+eq,0x880a10c4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_880A10C4;
	// bdzf 4*cr6+eq,0x880a1148
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_880A1148;
	// bdzf 4*cr6+eq,0x880a11cc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_880A11CC;
	// bdzf 4*cr6+eq,0x880a1248
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_880A1248;
	// bdzf 4*cr6+eq,0x880a1344
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_880A1344;
	// bne cr6,0x880a1384
	if (!ctx.cr6.eq) goto loc_880A1384;
	// lis r9,-30682
	ctx.r9.s64 = -2010775552;
	// rlwinm r6,r11,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r8,r9,-30124
	ctx.r8.s64 = ctx.r9.s64 + -30124;
	// addis r27,r11,1
	ctx.r27.s64 = ctx.r11.s64 + 65536;
	// addi r5,r8,1
	ctx.r5.s64 = ctx.r8.s64 + 1;
	// addi r27,r27,-26238
	ctx.r27.s64 = ctx.r27.s64 + -26238;
	// li r9,0
	ctx.r9.s64 = 0;
	// lbzx r4,r6,r8
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r8.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// lbzx r11,r6,r5
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r5.u32);
	// extsb r6,r4
	ctx.r6.s64 = ctx.r4.s8;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// extsb r5,r11
	ctx.r5.s64 = ctx.r11.s8;
	// rlwinm r11,r6,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r6,r5,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// add r29,r11,r17
	ctx.r29.u64 = ctx.r11.u64 + ctx.r17.u64;
	// add r28,r6,r10
	ctx.r28.u64 = ctx.r6.u64 + ctx.r10.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// bl 0x880a51a0
	ctx.lr = 0x880A1020;
	sub_880A51A0(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// li r6,219
	ctx.r6.s64 = 219;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x880a5108
	ctx.lr = 0x880A1040;
	sub_880A5108(ctx, base);
	// b 0x880a148c
	goto loc_880A148C;
loc_880A1044:
	// lis r9,-30682
	ctx.r9.s64 = -2010775552;
	// rlwinm r6,r11,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r8,r9,-30012
	ctx.r8.s64 = ctx.r9.s64 + -30012;
	// addis r27,r11,1
	ctx.r27.s64 = ctx.r11.s64 + 65536;
	// addi r5,r8,1
	ctx.r5.s64 = ctx.r8.s64 + 1;
	// addi r27,r27,-26298
	ctx.r27.s64 = ctx.r27.s64 + -26298;
	// li r9,0
	ctx.r9.s64 = 0;
	// lbzx r4,r6,r8
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r8.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// lbzx r11,r6,r5
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r5.u32);
	// extsb r6,r4
	ctx.r6.s64 = ctx.r4.s8;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// rlwinm r6,r6,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// addi r5,r11,4
	ctx.r5.s64 = ctx.r11.s64 + 4;
	// add r29,r6,r17
	ctx.r29.u64 = ctx.r6.u64 + ctx.r17.u64;
	// rlwinm r11,r5,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// add r28,r11,r10
	ctx.r28.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x880a51a0
	ctx.lr = 0x880A10A0;
	sub_880A51A0(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// li r6,219
	ctx.r6.s64 = 219;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x880a5108
	ctx.lr = 0x880A10C0;
	sub_880A5108(ctx, base);
	// b 0x880a148c
	goto loc_880A148C;
loc_880A10C4:
	// lis r9,-30682
	ctx.r9.s64 = -2010775552;
	// rlwinm r6,r11,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r8,r9,-29996
	ctx.r8.s64 = ctx.r9.s64 + -29996;
	// addis r27,r11,1
	ctx.r27.s64 = ctx.r11.s64 + 65536;
	// addi r5,r8,1
	ctx.r5.s64 = ctx.r8.s64 + 1;
	// addi r27,r27,-26286
	ctx.r27.s64 = ctx.r27.s64 + -26286;
	// li r9,0
	ctx.r9.s64 = 0;
	// lbzx r4,r6,r8
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r8.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// lbzx r6,r6,r5
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r5.u32);
	// extsb r11,r4
	ctx.r11.s64 = ctx.r4.s8;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// extsb r6,r6
	ctx.r6.s64 = ctx.r6.s8;
	// addi r5,r11,4
	ctx.r5.s64 = ctx.r11.s64 + 4;
	// addi r4,r6,8
	ctx.r4.s64 = ctx.r6.s64 + 8;
	// rlwinm r11,r5,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r6,r4,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// add r29,r11,r17
	ctx.r29.u64 = ctx.r11.u64 + ctx.r17.u64;
	// add r28,r6,r10
	ctx.r28.u64 = ctx.r6.u64 + ctx.r10.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// bl 0x880a51a0
	ctx.lr = 0x880A1124;
	sub_880A51A0(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// li r6,219
	ctx.r6.s64 = 219;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x880a5108
	ctx.lr = 0x880A1144;
	sub_880A5108(ctx, base);
	// b 0x880a148c
	goto loc_880A148C;
loc_880A1148:
	// lis r9,-30682
	ctx.r9.s64 = -2010775552;
	// rlwinm r6,r11,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r8,r9,-29980
	ctx.r8.s64 = ctx.r9.s64 + -29980;
	// addis r27,r11,1
	ctx.r27.s64 = ctx.r11.s64 + 65536;
	// addi r5,r8,1
	ctx.r5.s64 = ctx.r8.s64 + 1;
	// addi r27,r27,-26290
	ctx.r27.s64 = ctx.r27.s64 + -26290;
	// li r9,0
	ctx.r9.s64 = 0;
	// lbzx r4,r6,r8
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r8.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// lbzx r6,r6,r5
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r5.u32);
	// extsb r11,r4
	ctx.r11.s64 = ctx.r4.s8;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// extsb r6,r6
	ctx.r6.s64 = ctx.r6.s8;
	// addi r5,r11,4
	ctx.r5.s64 = ctx.r11.s64 + 4;
	// addi r4,r6,8
	ctx.r4.s64 = ctx.r6.s64 + 8;
	// rlwinm r11,r5,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r6,r4,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// add r29,r11,r17
	ctx.r29.u64 = ctx.r11.u64 + ctx.r17.u64;
	// add r28,r6,r10
	ctx.r28.u64 = ctx.r6.u64 + ctx.r10.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// bl 0x880a51a0
	ctx.lr = 0x880A11A8;
	sub_880A51A0(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// li r6,219
	ctx.r6.s64 = 219;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x880a5108
	ctx.lr = 0x880A11C8;
	sub_880A5108(ctx, base);
	// b 0x880a148c
	goto loc_880A148C;
loc_880A11CC:
	// lis r9,-30682
	ctx.r9.s64 = -2010775552;
	// rlwinm r6,r11,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r8,r9,-30044
	ctx.r8.s64 = ctx.r9.s64 + -30044;
	// addis r27,r11,1
	ctx.r27.s64 = ctx.r11.s64 + 65536;
	// addi r5,r8,1
	ctx.r5.s64 = ctx.r8.s64 + 1;
	// addi r27,r27,-26278
	ctx.r27.s64 = ctx.r27.s64 + -26278;
	// li r9,0
	ctx.r9.s64 = 0;
	// lbzx r4,r6,r8
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r8.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// lbzx r11,r6,r5
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r5.u32);
	// extsb r6,r4
	ctx.r6.s64 = ctx.r4.s8;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// extsb r5,r11
	ctx.r5.s64 = ctx.r11.s8;
	// rlwinm r11,r6,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r6,r5,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// add r29,r11,r17
	ctx.r29.u64 = ctx.r11.u64 + ctx.r17.u64;
	// add r28,r6,r10
	ctx.r28.u64 = ctx.r6.u64 + ctx.r10.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// bl 0x880a51a0
	ctx.lr = 0x880A1224;
	sub_880A51A0(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// li r6,219
	ctx.r6.s64 = 219;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x880a5108
	ctx.lr = 0x880A1244;
	sub_880A5108(ctx, base);
	// b 0x880a148c
	goto loc_880A148C;
loc_880A1248:
	// lis r9,-30682
	ctx.r9.s64 = -2010775552;
	// rlwinm r5,r11,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r8,r9,-30124
	ctx.r8.s64 = ctx.r9.s64 + -30124;
	// addis r28,r11,1
	ctx.r28.s64 = ctx.r11.s64 + 65536;
	// addi r4,r8,1
	ctx.r4.s64 = ctx.r8.s64 + 1;
	// addi r28,r28,-26238
	ctx.r28.s64 = ctx.r28.s64 + -26238;
	// li r9,0
	ctx.r9.s64 = 0;
	// lbzx r3,r5,r8
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r8.u32);
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// lbzx r11,r5,r4
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r4.u32);
	// extsb r5,r3
	ctx.r5.s64 = ctx.r3.s8;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// extsb r4,r11
	ctx.r4.s64 = ctx.r11.s8;
	// rlwinm r11,r5,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r5,r4,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// add r27,r11,r17
	ctx.r27.u64 = ctx.r11.u64 + ctx.r17.u64;
	// add r26,r5,r10
	ctx.r26.u64 = ctx.r5.u64 + ctx.r10.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// bl 0x880a51a0
	ctx.lr = 0x880A12A0;
	sub_880A51A0(ctx, base);
	// mr r25,r16
	ctx.r25.u64 = ctx.r16.u64;
	// li r18,8
	ctx.r18.s64 = 8;
	// lis r21,-3
	ctx.r21.s64 = -196608;
	// li r22,15
	ctx.r22.s64 = 15;
	// li r23,255
	ctx.r23.s64 = 255;
	// lwz r24,-11932(r14)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r14.u32 + -11932);
loc_880A12B8:
	// clrlwi r11,r25,28
	ctx.r11.u64 = ctx.r25.u32 & 0xF;
	// lwz r10,72(r19)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r19.u32 + 72);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mullw r9,r11,r21
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r21.s32);
	// subfic r8,r11,15
	ctx.xer.ca = ctx.r11.u32 <= 15;
	ctx.r8.s64 = 15 - ctx.r11.s64;
	// srawi r7,r9,16
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xFFFF) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 16;
	// mulli r5,r8,111
	ctx.r5.s64 = ctx.r8.s64 * 111;
	// addze r4,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r4.s64 = temp.s64;
	// divw r3,r5,r22
	ctx.r3.s32 = ppc_divw(ctx.r5.s32, ctx.r22.s32);
	// rlwinm r9,r4,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// mullw r10,r3,r10
	ctx.r10.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r10.s32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// subf r5,r9,r26
	ctx.r5.s64 = ctx.r26.s64 - ctx.r9.s64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// divw r29,r10,r23
	ctx.r29.s32 = ppc_divw(ctx.r10.s32, ctx.r23.s32);
	// bl 0x881538c0
	ctx.lr = 0x880A12F8;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880a1318
	if (ctx.cr6.eq) goto loc_880A1318;
	// lis r11,545
	ctx.r11.s64 = 35717120;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// rlwimi r11,r29,8,16,23
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r29.u32, 8) & 0xFF00) | (ctx.r11.u64 & 0xFFFFFFFFFFFF00FF);
	// or r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_880A1318:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x880a1330
	if (ctx.cr6.eq) goto loc_880A1330;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880a1330
	if (ctx.cr6.eq) goto loc_880A1330;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880A1330:
	// addic. r18,r18,-1
	ctx.xer.ca = ctx.r18.u32 > 0;
	ctx.r18.s64 = ctx.r18.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r18.s32, 0, ctx.xer);
	// addi r25,r25,2
	ctx.r25.s64 = ctx.r25.s64 + 2;
	// bne 0x880a12b8
	if (!ctx.cr0.eq) goto loc_880A12B8;
	// stw r24,-11932(r14)
	PPC_STORE_U32(ctx.r14.u32 + -11932, ctx.r24.u32);
	// b 0x880a1490
	goto loc_880A1490;
loc_880A1344:
	// lis r9,-30682
	ctx.r9.s64 = -2010775552;
	// rlwinm r5,r11,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r7,r9,-30092
	ctx.r7.s64 = ctx.r9.s64 + -30092;
	// addis r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 65536;
	// addi r4,r7,1
	ctx.r4.s64 = ctx.r7.s64 + 1;
	// addi r3,r3,-26262
	ctx.r3.s64 = ctx.r3.s64 + -26262;
	// lbzx r11,r5,r7
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r7.u32);
	// lbzx r5,r5,r4
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r4.u32);
	// extsb r4,r11
	ctx.r4.s64 = ctx.r11.s8;
	// extsb r11,r5
	ctx.r11.s64 = ctx.r5.s8;
	// rlwinm r5,r4,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// add r4,r5,r17
	ctx.r4.u64 = ctx.r5.u64 + ctx.r17.u64;
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x880a1478
	goto loc_880A1478;
loc_880A1384:
	// lwz r9,476(r19)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r19.u32 + 476);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x880a1490
	if (!ctx.cr6.eq) goto loc_880A1490;
	// lis r9,-30682
	ctx.r9.s64 = -2010775552;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r9,r9,-30076
	ctx.r9.s64 = ctx.r9.s64 + -30076;
	// addis r28,r11,1
	ctx.r28.s64 = ctx.r11.s64 + 65536;
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// addi r28,r28,-26254
	ctx.r28.s64 = ctx.r28.s64 + -26254;
	// mr r29,r16
	ctx.r29.u64 = ctx.r16.u64;
	// lbzx r6,r8,r9
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// li r25,8
	ctx.r25.s64 = 8;
	// lis r21,-3
	ctx.r21.s64 = -196608;
	// lbzx r5,r8,r7
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r7.u32);
	// extsb r11,r6
	ctx.r11.s64 = ctx.r6.s8;
	// li r22,15
	ctx.r22.s64 = 15;
	// extsb r9,r5
	ctx.r9.s64 = ctx.r5.s8;
	// addi r4,r11,-4
	ctx.r4.s64 = ctx.r11.s64 + -4;
	// addi r3,r9,12
	ctx.r3.s64 = ctx.r9.s64 + 12;
	// rlwinm r11,r4,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r9,r3,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 16) & 0xFFFF0000;
	// add r27,r11,r17
	ctx.r27.u64 = ctx.r11.u64 + ctx.r17.u64;
	// add r26,r9,r10
	ctx.r26.u64 = ctx.r9.u64 + ctx.r10.u64;
	// li r23,255
	ctx.r23.s64 = 255;
loc_880A13E4:
	// clrlwi r11,r29,28
	ctx.r11.u64 = ctx.r29.u32 & 0xF;
	// lwz r10,72(r19)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r19.u32 + 72);
	// li r6,121
	ctx.r6.s64 = 121;
	// mullw r9,r11,r21
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r21.s32);
	// subfic r8,r11,15
	ctx.xer.ca = ctx.r11.u32 <= 15;
	ctx.r8.s64 = 15 - ctx.r11.s64;
	// srawi r7,r9,16
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xFFFF) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 16;
	// mulli r5,r8,111
	ctx.r5.s64 = ctx.r8.s64 * 111;
	// addze r4,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r4.s64 = temp.s64;
	// divw r3,r5,r22
	ctx.r3.s32 = ppc_divw(ctx.r5.s32, ctx.r22.s32);
	// rlwinm r9,r4,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// mullw r10,r3,r10
	ctx.r10.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r10.s32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// subf r5,r9,r26
	ctx.r5.s64 = ctx.r26.s64 - ctx.r9.s64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// divw r30,r10,r23
	ctx.r30.s32 = ppc_divw(ctx.r10.s32, ctx.r23.s32);
	// bl 0x881538c0
	ctx.lr = 0x880A1424;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880a1444
	if (ctx.cr6.eq) goto loc_880A1444;
	// lis r11,545
	ctx.r11.s64 = 35717120;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// rlwimi r11,r30,8,16,23
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r30.u32, 8) & 0xFF00) | (ctx.r11.u64 & 0xFFFFFFFFFFFF00FF);
	// or r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_880A1444:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x880a145c
	if (ctx.cr6.eq) goto loc_880A145C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880a145c
	if (ctx.cr6.eq) goto loc_880A145C;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880A145C:
	// addic. r25,r25,-1
	ctx.xer.ca = ctx.r25.u32 > 0;
	ctx.r25.s64 = ctx.r25.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// addi r29,r29,2
	ctx.r29.s64 = ctx.r29.s64 + 2;
	// bne 0x880a13e4
	if (!ctx.cr0.eq) goto loc_880A13E4;
	// stw r24,-11932(r14)
	PPC_STORE_U32(ctx.r14.u32 + -11932, ctx.r24.u32);
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
loc_880A1478:
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// li r6,121
	ctx.r6.s64 = 121;
	// bl 0x880a51a0
	ctx.lr = 0x880A148C;
	sub_880A51A0(ctx, base);
loc_880A148C:
	// lwz r24,-11932(r14)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r14.u32 + -11932);
loc_880A1490:
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// bne cr6,0x880a19a4
	if (!ctx.cr6.eq) goto loc_880A19A4;
	// lwz r25,1168(r19)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r19.u32 + 1168);
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// stw r25,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r25.u32);
	// beq cr6,0x880a19a4
	if (ctx.cr6.eq) goto loc_880A19A4;
	// lwz r11,1172(r19)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r19.u32 + 1172);
	// clrlwi r23,r16,23
	ctx.r23.u64 = ctx.r16.u32 & 0x1FF;
	// li r15,0
	ctx.r15.s64 = 0;
	// addi r11,r11,-32
	ctx.r11.s64 = ctx.r11.s64 + -32;
	// stw r23,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r23.u32);
	// rlwinm r10,r16,3,20,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 3) & 0xFF8;
	// rlwinm r26,r11,4,0,27
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// mr r27,r15
	ctx.r27.u64 = ctx.r15.u64;
	// stw r26,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r26.u32);
	// subf r28,r23,r10
	ctx.r28.s64 = ctx.r10.s64 - ctx.r23.s64;
	// mr r29,r15
	ctx.r29.u64 = ctx.r15.u64;
	// addi r16,r11,9552
	ctx.r16.s64 = ctx.r11.s64 + 9552;
loc_880A14DC:
	// srawi r11,r29,3
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x7) != 0);
	ctx.r11.s64 = ctx.r29.s32 >> 3;
	// lwz r9,96(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// li r6,214
	ctx.r6.s64 = 214;
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// li r3,419
	ctx.r3.s64 = 419;
	// add r8,r11,r28
	ctx.r8.u64 = ctx.r11.u64 + ctx.r28.u64;
	// clrlwi r11,r8,23
	ctx.r11.u64 = ctx.r8.u32 & 0x1FF;
	// addi r7,r11,128
	ctx.r7.s64 = ctx.r11.s64 + 128;
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r4,r7,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x7FC;
	// lwzx r11,r5,r16
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r16.u32);
	// lwzx r10,r4,r16
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r16.u32);
	// mullw r11,r11,r26
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r26.s32);
	// mullw r10,r10,r26
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r26.s32);
	// add r31,r10,r9
	ctx.r31.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r30,r11,r17
	ctx.r30.u64 = ctx.r11.u64 + ctx.r17.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x881538c0
	ctx.lr = 0x880A1528;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880a1554
	if (ctx.cr6.eq) goto loc_880A1554;
	// lis r11,545
	ctx.r11.s64 = 35717120;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,0
	ctx.r9.s64 = 0;
	// rlwimi r11,r25,8,16,23
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r25.u32, 8) & 0xFF00) | (ctx.r11.u64 & 0xFFFFFFFFFFFF00FF);
	// ori r8,r9,65280
	ctx.r8.u64 = ctx.r9.u64 | 65280;
	// or r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 | ctx.r10.u64;
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
loc_880A1554:
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r6,215
	ctx.r6.s64 = 215;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// add r10,r27,r11
	ctx.r10.u64 = ctx.r27.u64 + ctx.r11.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// clrlwi r11,r10,27
	ctx.r11.u64 = ctx.r10.u32 & 0x1F;
	// addi r3,r11,1815
	ctx.r3.s64 = ctx.r11.s64 + 1815;
	// bl 0x881538c0
	ctx.lr = 0x880A1574;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880a15a4
	if (ctx.cr6.eq) goto loc_880A15A4;
	// lis r11,545
	ctx.r11.s64 = 35717120;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,112
	ctx.r9.s64 = 7340032;
	// rlwimi r11,r25,8,16,23
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r25.u32, 8) & 0xFF00) | (ctx.r11.u64 & 0xFFFFFFFFFFFF00FF);
	// ori r8,r9,49008
	ctx.r8.u64 = ctx.r9.u64 | 49008;
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// or r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// stw r24,-11932(r14)
	PPC_STORE_U32(ctx.r14.u32 + -11932, ctx.r24.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
loc_880A15A4:
	// li r6,215
	ctx.r6.s64 = 215;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,404
	ctx.r3.s64 = 404;
	// bl 0x881538c0
	ctx.lr = 0x880A15B8;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880a15dc
	if (ctx.cr6.eq) goto loc_880A15DC;
	// lis r11,545
	ctx.r11.s64 = 35717120;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// rlwimi r11,r25,8,16,23
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r25.u32, 8) & 0xFF00) | (ctx.r11.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r24,-11932(r14)
	PPC_STORE_U32(ctx.r14.u32 + -11932, ctx.r24.u32);
	// or r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_880A15DC:
	// addi r29,r29,512
	ctx.r29.s64 = ctx.r29.s64 + 512;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// cmpwi cr6,r29,4096
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 4096, ctx.xer);
	// blt cr6,0x880a14dc
	if (ctx.cr6.lt) goto loc_880A14DC;
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r11,r26,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 1) & 0xFFFFFFFE;
	// li r9,3
	ctx.r9.s64 = 3;
	// stw r24,-11932(r14)
	PPC_STORE_U32(ctx.r14.u32 + -11932, ctx.r24.u32);
	// lis r28,-30671
	ctx.r28.s64 = -2010054656;
	// stw r15,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r15.u32);
	// clrlwi r8,r10,29
	ctx.r8.u64 = ctx.r10.u32 & 0x7;
	// divw r14,r11,r9
	ctx.r14.s32 = ppc_divw(ctx.r11.s32, ctx.r9.s32);
	// lis r11,16838
	ctx.r11.s64 = 1103495168;
	// stw r8,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r8.u32);
	// lis r10,-21846
	ctx.r10.s64 = -1431699456;
	// rlwinm r27,r23,3,0,28
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r29,4200(r28)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4200);
	// mr r23,r15
	ctx.r23.u64 = ctx.r15.u64;
	// li r17,7
	ctx.r17.s64 = 7;
	// ori r25,r11,20077
	ctx.r25.u64 = ctx.r11.u64 | 20077;
	// ori r26,r10,43691
	ctx.r26.u64 = ctx.r10.u64 | 43691;
	// lis r18,-30667
	ctx.r18.s64 = -2009792512;
	// lis r19,-30667
	ctx.r19.s64 = -2009792512;
	// lis r20,-30667
	ctx.r20.s64 = -2009792512;
	// lis r21,-30667
	ctx.r21.s64 = -2009792512;
	// lis r22,-30667
	ctx.r22.s64 = -2009792512;
loc_880A1644:
	// srawi r10,r15,3
	ctx.xer.ca = (ctx.r15.s32 < 0) & ((ctx.r15.u32 & 0x7) != 0);
	ctx.r10.s64 = ctx.r15.s32 >> 3;
	// lwz r9,96(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// neg r11,r27
	ctx.r11.s64 = -ctx.r27.s64;
	// lwz r8,100(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addze r7,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r7.s64 = temp.s64;
	// li r6,214
	ctx.r6.s64 = 214;
	// subf r5,r7,r11
	ctx.r5.s64 = ctx.r11.s64 - ctx.r7.s64;
	// li r3,419
	ctx.r3.s64 = 419;
	// clrlwi r11,r5,23
	ctx.r11.u64 = ctx.r5.u32 & 0x1FF;
	// addi r4,r11,128
	ctx.r4.s64 = ctx.r11.s64 + 128;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r4,2,21,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x7FC;
	// lwzx r7,r11,r16
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r16.u32);
	// lwzx r5,r10,r16
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r16.u32);
	// mullw r11,r7,r14
	ctx.r11.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r14.s32);
	// mullw r10,r5,r14
	ctx.r10.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r14.s32);
	// add r31,r10,r9
	ctx.r31.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r30,r11,r8
	ctx.r30.u64 = ctx.r11.u64 + ctx.r8.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x881538c0
	ctx.lr = 0x880A1698;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880a16c8
	if (ctx.cr6.eq) goto loc_880A16C8;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r8,0
	ctx.r8.s64 = 0;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// ori r7,r8,65280
	ctx.r7.u64 = ctx.r8.u64 | 65280;
	// or r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 | ctx.r9.u64;
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// stw r7,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r7.u32);
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
loc_880A16C8:
	// lwz r11,88(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// li r6,215
	ctx.r6.s64 = 215;
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// add r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 + ctx.r10.u64;
	// clrlwi r11,r9,27
	ctx.r11.u64 = ctx.r9.u32 & 0x1F;
	// addi r3,r11,1847
	ctx.r3.s64 = ctx.r11.s64 + 1847;
	// bl 0x881538c0
	ctx.lr = 0x880A16EC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880a1724
	if (ctx.cr6.eq) goto loc_880A1724;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r8,112
	ctx.r8.s64 = 7340032;
	// lwz r7,92(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// ori r6,r8,49008
	ctx.r6.u64 = ctx.r8.u64 | 49008;
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// or r5,r10,r9
	ctx.r5.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r6,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r6.u32);
	// stw r24,-11932(r7)
	PPC_STORE_U32(ctx.r7.u32 + -11932, ctx.r24.u32);
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
loc_880A1724:
	// li r6,215
	ctx.r6.s64 = 215;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,404
	ctx.r3.s64 = 404;
	// bl 0x881538c0
	ctx.lr = 0x880A1738;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880a1764
	if (ctx.cr6.eq) goto loc_880A1764;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// lwz r8,92(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// or r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r24,-11932(r8)
	PPC_STORE_U32(ctx.r8.u32 + -11932, ctx.r24.u32);
loc_880A1764:
	// lwz r11,104(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x880a1850
	if (!ctx.cr6.eq) goto loc_880A1850;
	// stw r30,12364(r21)
	PPC_STORE_U32(ctx.r21.u32 + 12364, ctx.r30.u32);
	// li r11,12
	ctx.r11.s64 = 12;
	// stw r31,12372(r20)
	PPC_STORE_U32(ctx.r20.u32 + 12372, ctx.r31.u32);
	// li r10,216
	ctx.r10.s64 = 216;
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r4,216
	ctx.r4.s64 = 216;
	// li r3,12
	ctx.r3.s64 = 12;
	// stw r11,12380(r22)
	PPC_STORE_U32(ctx.r22.u32 + 12380, ctx.r11.u32);
	// divwu r9,r9,r17
	ctx.r9.u32 = ppc_divwu(ctx.r9.u32, ctx.r17.u32);
	// stw r10,12376(r19)
	PPC_STORE_U32(ctx.r19.u32 + 12376, ctx.r10.u32);
	// add r8,r9,r27
	ctx.r8.u64 = ctx.r9.u64 + ctx.r27.u64;
	// clrlwi r5,r8,28
	ctx.r5.u64 = ctx.r8.u32 & 0xF;
	// stw r5,12384(r18)
	PPC_STORE_U32(ctx.r18.u32 + 12384, ctx.r5.u32);
	// bl 0x880f25b8
	ctx.lr = 0x880A17AC;
	sub_880F25B8(ctx, base);
	// mullw r11,r29,r25
	ctx.r11.s64 = int64_t(ctx.r29.s32) * int64_t(ctx.r25.s32);
	// addi r29,r11,12345
	ctx.r29.s64 = ctx.r11.s64 + 12345;
	// srawi r7,r23,3
	ctx.xer.ca = (ctx.r23.s32 < 0) & ((ctx.r23.u32 & 0x7) != 0);
	ctx.r7.s64 = ctx.r23.s32 >> 3;
	// stw r29,4200(r28)
	PPC_STORE_U32(ctx.r28.u32 + 4200, ctx.r29.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// lhz r6,4200(r28)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r28.u32 + 4200);
	// mulhwu r5,r6,r26
	ctx.r5.u64 = (uint64_t(ctx.r6.u32) * uint64_t(ctx.r26.u32)) >> 32;
	// rlwinm r11,r5,26,6,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 26) & 0x3FFFFFF;
	// addze r4,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r4.s64 = temp.s64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xFFFFFFE0;
	// subf r9,r10,r6
	ctx.r9.s64 = ctx.r6.s64 - ctx.r10.s64;
	// extsh r7,r9
	ctx.r7.s64 = ctx.r9.s16;
	// subf r6,r7,r4
	ctx.r6.s64 = ctx.r4.s64 - ctx.r7.s64;
	// subf r11,r27,r6
	ctx.r11.s64 = ctx.r6.s64 - ctx.r27.s64;
	// addi r5,r11,48
	ctx.r5.s64 = ctx.r11.s64 + 48;
	// clrlwi r11,r5,23
	ctx.r11.u64 = ctx.r5.u32 & 0x1FF;
	// beq cr6,0x880a1850
	if (ctx.cr6.eq) goto loc_880A1850;
	// li r8,28
	ctx.r8.s64 = 28;
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r11.u32);
	// addic. r10,r3,28
	ctx.xer.ca = ctx.r3.u32 > 4294967267;
	ctx.r10.s64 = ctx.r3.s64 + 28;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r9,r3,24
	ctx.r9.s64 = ctx.r3.s64 + 24;
	// stw r8,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r8.u32);
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// beq 0x880a1830
	if (ctx.cr0.eq) goto loc_880A1830;
	// addi r8,r11,128
	ctx.r8.s64 = ctx.r11.s64 + 128;
	// rlwinm r7,r8,2,21,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x7FC;
	// lwzx r6,r7,r16
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r16.u32);
	// rlwinm r5,r6,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r4,r6,r5
	ctx.r4.s64 = ctx.r5.s64 - ctx.r6.s64;
	// rlwinm r3,r4,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
loc_880A1830:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x880a1850
	if (ctx.cr6.eq) goto loc_880A1850;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r16
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r16.u32);
	// rlwinm r8,r10,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r7,r10,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r10.s64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r6,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r6.u32);
loc_880A1850:
	// lwz r11,88(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// addi r15,r15,512
	ctx.r15.s64 = ctx.r15.s64 + 512;
	// addi r23,r23,-512
	ctx.r23.s64 = ctx.r23.s64 + -512;
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r15,4096
	ctx.cr6.compare<int32_t>(ctx.r15.s32, 4096, ctx.xer);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// blt cr6,0x880a1644
	if (ctx.cr6.lt) goto loc_880A1644;
	// lwz r10,108(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// li r9,3
	ctx.r9.s64 = 3;
	// lwz r23,92(r1)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// li r28,0
	ctx.r28.s64 = 0;
	// lwz r22,112(r1)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// divw r29,r22,r9
	ctx.r29.s32 = ppc_divw(ctx.r22.s32, ctx.r9.s32);
	// add r27,r10,r11
	ctx.r27.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r24,-11932(r23)
	PPC_STORE_U32(ctx.r23.u32 + -11932, ctx.r24.u32);
loc_880A1890:
	// srawi r11,r28,3
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0x7) != 0);
	ctx.r11.s64 = ctx.r28.s32 >> 3;
	// lwz r25,96(r1)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r26,100(r1)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// li r6,214
	ctx.r6.s64 = 214;
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// li r3,419
	ctx.r3.s64 = 419;
	// add r10,r11,r27
	ctx.r10.u64 = ctx.r11.u64 + ctx.r27.u64;
	// clrlwi r11,r10,23
	ctx.r11.u64 = ctx.r10.u32 & 0x1FF;
	// addi r9,r11,128
	ctx.r9.s64 = ctx.r11.s64 + 128;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r9,2,21,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x7FC;
	// lwzx r5,r8,r16
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r16.u32);
	// lwzx r4,r7,r16
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r16.u32);
	// mullw r11,r5,r29
	ctx.r11.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r29.s32);
	// mullw r10,r4,r29
	ctx.r10.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r29.s32);
	// add r31,r10,r25
	ctx.r31.u64 = ctx.r10.u64 + ctx.r25.u64;
	// add r30,r11,r26
	ctx.r30.u64 = ctx.r11.u64 + ctx.r26.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x881538c0
	ctx.lr = 0x880A18E0;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880a1910
	if (ctx.cr6.eq) goto loc_880A1910;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r8,0
	ctx.r8.s64 = 0;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// ori r7,r8,65280
	ctx.r7.u64 = ctx.r8.u64 | 65280;
	// or r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 | ctx.r9.u64;
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// stw r7,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r7.u32);
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
loc_880A1910:
	// li r6,215
	ctx.r6.s64 = 215;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,404
	ctx.r3.s64 = 404;
	// bl 0x881538c0
	ctx.lr = 0x880A1924;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880a194c
	if (ctx.cr6.eq) goto loc_880A194C;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r24,-11932(r23)
	PPC_STORE_U32(ctx.r23.u32 + -11932, ctx.r24.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880A194C:
	// addi r28,r28,512
	ctx.r28.s64 = ctx.r28.s64 + 512;
	// cmpwi cr6,r28,4096
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 4096, ctx.xer);
	// blt cr6,0x880a1890
	if (ctx.cr6.lt) goto loc_880A1890;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// stw r24,-11932(r23)
	PPC_STORE_U32(ctx.r23.u32 + -11932, ctx.r24.u32);
	// lwz r11,26272(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26272);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880a199c
	if (!ctx.cr6.eq) goto loc_880A199C;
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// clrlwi r10,r11,30
	ctx.r10.u64 = ctx.r11.u32 & 0x3;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x880a19a4
	if (!ctx.cr6.eq) goto loc_880A19A4;
	// mr r6,r22
	ctx.r6.u64 = ctx.r22.u64;
	// lwz r3,292(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 292);
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x880a0360
	ctx.lr = 0x880A1990;
	sub_880A0360(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
loc_880A199C:
	// lwz r3,292(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 292);
	// bl 0x880a0478
	ctx.lr = 0x880A19A4;
	sub_880A0478(ctx, base);
loc_880A19A4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A19B0"))) PPC_WEAK_FUNC(sub_880A19B0);
PPC_FUNC_IMPL(__imp__sub_880A19B0) {
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
	// bl 0x880a0c48
	ctx.lr = 0x880A19C8;
	sub_880A0C48(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a0a10
	ctx.lr = 0x880A19D0;
	sub_880A0A10(ctx, base);
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

__attribute__((alias("__imp__sub_880A19E8"))) PPC_WEAK_FUNC(sub_880A19E8);
PPC_FUNC_IMPL(__imp__sub_880A19E8) {
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
	// addi r11,r4,1472
	ctx.r11.s64 = ctx.r4.s64 + 1472;
	// addi r9,r4,1468
	ctx.r9.s64 = ctx.r4.s64 + 1468;
	// ori r8,r10,65535
	ctx.r8.u64 = ctx.r10.u64 | 65535;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// lis r7,-30710
	ctx.r7.s64 = -2012610560;
	// stw r8,1472(r4)
	PPC_STORE_U32(ctx.r4.u32 + 1472, ctx.r8.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r7,3632
	ctx.r5.s64 = ctx.r7.s64 + 3632;
	// li r4,30
	ctx.r4.s64 = 30;
	// bl 0x88096460
	ctx.lr = 0x880A1A24;
	sub_88096460(ctx, base);
	// lis r6,-30641
	ctx.r6.s64 = -2008088576;
	// addi r5,r6,-18804
	ctx.r5.s64 = ctx.r6.s64 + -18804;
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

__attribute__((alias("__imp__sub_880A1A40"))) PPC_WEAK_FUNC(sub_880A1A40);
PPC_FUNC_IMPL(__imp__sub_880A1A40) {
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
	// addi r11,r4,1300
	ctx.r11.s64 = ctx.r4.s64 + 1300;
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
	// addi r5,r9,3632
	ctx.r5.s64 = ctx.r9.s64 + 3632;
	// li r4,30
	ctx.r4.s64 = 30;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x88096460
	ctx.lr = 0x880A1A78;
	sub_88096460(ctx, base);
	// lis r8,-30641
	ctx.r8.s64 = -2008088576;
	// lis r7,-30710
	ctx.r7.s64 = -2012610560;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r7,6576
	ctx.r5.s64 = ctx.r7.s64 + 6576;
	// li r4,30
	ctx.r4.s64 = 30;
	// stw r3,-18804(r8)
	PPC_STORE_U32(ctx.r8.u32 + -18804, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r31,r8,-18804
	ctx.r31.s64 = ctx.r8.s64 + -18804;
	// bl 0x88096460
	ctx.lr = 0x880A1A9C;
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

__attribute__((alias("__imp__sub_880A1AB4"))) PPC_WEAK_FUNC(sub_880A1AB4);
PPC_FUNC_IMPL(__imp__sub_880A1AB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A1AB8"))) PPC_WEAK_FUNC(sub_880A1AB8);
PPC_FUNC_IMPL(__imp__sub_880A1AB8) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,-11996(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11996, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880A1AC8"))) PPC_WEAK_FUNC(sub_880A1AC8);
PPC_FUNC_IMPL(__imp__sub_880A1AC8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880A1ACC"))) PPC_WEAK_FUNC(sub_880A1ACC);
PPC_FUNC_IMPL(__imp__sub_880A1ACC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A1AD0"))) PPC_WEAK_FUNC(sub_880A1AD0);
PPC_FUNC_IMPL(__imp__sub_880A1AD0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r10,7816(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 7816);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// li r10,32
	ctx.r10.s64 = 32;
	// addi r11,r11,132
	ctx.r11.s64 = ctx.r11.s64 + 132;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_880A1AEC:
	// addi r11,r11,240
	ctx.r11.s64 = ctx.r11.s64 + 240;
	// bdnz 0x880a1aec
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_880A1AEC;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880A1AF8"))) PPC_WEAK_FUNC(sub_880A1AF8);
PPC_FUNC_IMPL(__imp__sub_880A1AF8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x880A1B00;
	__savegprlr_24(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r30,2304(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// li r31,0
	ctx.r31.s64 = 0;
	// lwz r11,184(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// lwz r10,168(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// li r24,2
	ctx.r24.s64 = 2;
	// li r25,256
	ctx.r25.s64 = 256;
	// add r28,r11,r10
	ctx.r28.u64 = ctx.r11.u64 + ctx.r10.u64;
	// std r31,0(r9)
	PPC_STORE_U64(ctx.r9.u32 + 0, ctx.r31.u64);
	// addi r27,r30,4
	ctx.r27.s64 = ctx.r30.s64 + 4;
	// std r31,8(r9)
	PPC_STORE_U64(ctx.r9.u32 + 8, ctx.r31.u64);
	// addi r26,r30,24
	ctx.r26.s64 = ctx.r30.s64 + 24;
	// std r31,16(r9)
	PPC_STORE_U64(ctx.r9.u32 + 16, ctx.r31.u64);
	// lis r8,16
	ctx.r8.s64 = 1048576;
	// std r31,24(r9)
	PPC_STORE_U64(ctx.r9.u32 + 24, ctx.r31.u64);
	// lwz r7,7824(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 7824);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// stw r31,32(r9)
	PPC_STORE_U32(ctx.r9.u32 + 32, ctx.r31.u32);
	// stw r27,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r27.u32);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// stw r24,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r24.u32);
	// stw r26,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r26.u32);
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r31.u32);
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// stw r25,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r25.u32);
	// stw r28,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r28.u32);
	// stw r28,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r28.u32);
	// bne cr6,0x880a1b80
	if (!ctx.cr6.eq) goto loc_880A1B80;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x88093be8
	ctx.lr = 0x880A1B7C;
	sub_88093BE8(ctx, base);
	// stw r3,7824(r30)
	PPC_STORE_U32(ctx.r30.u32 + 7824, ctx.r3.u32);
loc_880A1B80:
	// lwz r10,7828(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 7828);
	// addi r11,r28,-1
	ctx.r11.s64 = ctx.r28.s64 + -1;
	// lis r9,-32
	ctx.r9.s64 = -2097152;
	// stw r27,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r27.u32);
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r26,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r26.u32);
	// stw r24,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r24.u32);
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r31.u32);
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r25,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r25.u32);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// bne cr6,0x880a1bc4
	if (!ctx.cr6.eq) goto loc_880A1BC4;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88093be8
	ctx.lr = 0x880A1BC0;
	sub_88093BE8(ctx, base);
	// stw r3,7828(r30)
	PPC_STORE_U32(ctx.r30.u32 + 7828, ctx.r3.u32);
loc_880A1BC4:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A1BCC"))) PPC_WEAK_FUNC(sub_880A1BCC);
PPC_FUNC_IMPL(__imp__sub_880A1BCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A1BD0"))) PPC_WEAK_FUNC(sub_880A1BD0);
PPC_FUNC_IMPL(__imp__sub_880A1BD0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x880A1BD8;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r11,-30682
	ctx.r11.s64 = -2010775552;
	// lwz r9,184(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// li r27,10
	ctx.r27.s64 = 10;
	// lwz r10,168(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// addi r11,r11,-30340
	ctx.r11.s64 = ctx.r11.s64 + -30340;
	// add r30,r9,r10
	ctx.r30.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// lwz r28,116(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// rlwinm r9,r4,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// divw r7,r3,r27
	ctx.r7.s32 = ppc_divw(ctx.r3.s32, ctx.r27.s32);
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// rlwinm r3,r28,8,0,23
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 8) & 0xFFFFFF00;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r29,60(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// or r25,r3,r28
	ctx.r25.u64 = ctx.r3.u64 | ctx.r28.u64;
	// lwz r26,112(r31)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// lbzx r5,r9,r5
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r5.u32);
	// addis r3,r4,1
	ctx.r3.s64 = ctx.r4.s64 + 65536;
	// lbzx r4,r9,r11
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r11.u32);
	// rlwinm r25,r25,8,0,23
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 8) & 0xFFFFFF00;
	// extsb r11,r5
	ctx.r11.s64 = ctx.r5.s8;
	// extsb r9,r4
	ctx.r9.s64 = ctx.r4.s8;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r9,r9,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// addi r3,r3,-26442
	ctx.r3.s64 = ctx.r3.s64 + -26442;
	// add r4,r9,r8
	ctx.r4.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// or r25,r25,r28
	ctx.r25.u64 = ctx.r25.u64 | ctx.r28.u64;
	// bl 0x881538c0
	ctx.lr = 0x880A1C6C;
	sub_881538C0(ctx, base);
	// lis r28,-30597
	ctx.r28.s64 = -2005204992;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880a1ca0
	if (ctx.cr6.eq) goto loc_880A1CA0;
	// lis r10,547
	ctx.r10.s64 = 35848192;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-11932(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -11932);
	// rlwimi r10,r26,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r26.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r25,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r25.u32);
	// addi r24,r11,1
	ctx.r24.s64 = ctx.r11.s64 + 1;
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r24,-11932(r28)
	PPC_STORE_U32(ctx.r28.u32 + -11932, ctx.r24.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// b 0x880a1ca4
	goto loc_880A1CA4;
loc_880A1CA0:
	// lwz r24,-11932(r28)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r28.u32 + -11932);
loc_880A1CA4:
	// lis r11,-30682
	ctx.r11.s64 = -2010775552;
	// lwz r9,128(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// rlwinm r5,r29,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r11,r11,-30124
	ctx.r11.s64 = ctx.r11.s64 + -30124;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// divw r7,r9,r27
	ctx.r7.s32 = ppc_divw(ctx.r9.s32, ctx.r27.s32);
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// addis r3,r29,1
	ctx.r3.s64 = ctx.r29.s64 + 65536;
	// addi r6,r30,2
	ctx.r6.s64 = ctx.r30.s64 + 2;
	// lbzx r11,r5,r11
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r11.u32);
	// addi r3,r3,-26238
	ctx.r3.s64 = ctx.r3.s64 + -26238;
	// lbzx r9,r5,r4
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r4.u32);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// extsb r5,r9
	ctx.r5.s64 = ctx.r9.s8;
	// addi r4,r11,2
	ctx.r4.s64 = ctx.r11.s64 + 2;
	// rlwinm r11,r5,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r9,r4,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// add r4,r9,r8
	ctx.r4.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x880A1CFC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880a1d24
	if (ctx.cr6.eq) goto loc_880A1D24;
	// lis r10,547
	ctx.r10.s64 = 35848192;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r11,r24,1
	ctx.r11.s64 = ctx.r24.s64 + 1;
	// stw r25,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r25.u32);
	// rlwimi r10,r26,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r26.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r11,-11932(r28)
	PPC_STORE_U32(ctx.r28.u32 + -11932, ctx.r11.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880A1D24:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A1D2C"))) PPC_WEAK_FUNC(sub_880A1D2C);
PPC_FUNC_IMPL(__imp__sub_880A1D2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A1D30"))) PPC_WEAK_FUNC(sub_880A1D30);
PPC_FUNC_IMPL(__imp__sub_880A1D30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x880A1D38;
	__savegprlr_28(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880a1d64
	if (ctx.cr6.eq) goto loc_880A1D64;
	// addic. r11,r11,-2
	ctx.xer.ca = ctx.r11.u32 > 1;
	ctx.r11.s64 = ctx.r11.s64 + -2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// bgt 0x880a1d64
	if (ctx.cr0.gt) goto loc_880A1D64;
	// stw r29,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r29.u32);
loc_880A1D64:
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a1e64
	if (!ctx.cr6.eq) goto loc_880A1E64;
	// lwz r11,120(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// lis r8,-30714
	ctx.r8.s64 = -2012872704;
	// lwz r10,88(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// addi r7,r11,6
	ctx.r7.s64 = ctx.r11.s64 + 6;
	// lwz r9,128(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// lwz r5,52(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// clrlwi r11,r7,23
	ctx.r11.u64 = ctx.r7.u32 & 0x1FF;
	// addi r6,r8,9552
	ctx.r6.s64 = ctx.r8.s64 + 9552;
	// addi r3,r11,128
	ctx.r3.s64 = ctx.r11.s64 + 128;
	// stw r11,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r11.u32);
	// addic. r11,r5,-1
	ctx.xer.ca = ctx.r5.u32 > 0;
	ctx.r11.s64 = ctx.r5.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r10,r3,2,21,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x7FC;
	// lwzx r8,r10,r6
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r6.u32);
	// rlwinm r10,r8,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 6) & 0xFFFFFFC0;
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r4,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r4.u32);
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// stw r7,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r7.u32);
	// bge 0x880a1de0
	if (!ctx.cr0.lt) goto loc_880A1DE0;
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// blt cr6,0x880a1de0
	if (ctx.cr6.lt) goto loc_880A1DE0;
	// stw r29,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r29.u32);
loc_880A1DE0:
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r5,4(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r6,8(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// subf. r11,r5,r3
	ctx.r11.s64 = ctx.r3.s64 - ctx.r5.s64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge 0x880a1dfc
	if (!ctx.cr0.lt) goto loc_880A1DFC;
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
loc_880A1DFC:
	// subf. r10,r6,r4
	ctx.r10.s64 = ctx.r4.s64 - ctx.r6.s64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bge 0x880a1e08
	if (!ctx.cr0.lt) goto loc_880A1E08;
	// neg r10,r10
	ctx.r10.s64 = -ctx.r10.s64;
loc_880A1E08:
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x880a1e20
	if (!ctx.cr6.lt) goto loc_880A1E20;
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x880a1e2c
	goto loc_880A1E2C;
loc_880A1E20:
	// srawi r10,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 1;
	// addze r10,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r10.s64 = temp.s64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_880A1E2C:
	// lis r10,16
	ctx.r10.s64 = 1048576;
	// lwz r28,24(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// li r11,4
	ctx.r11.s64 = 4;
	// ble cr6,0x880a1e44
	if (!ctx.cr6.gt) goto loc_880A1E44;
	// li r11,6
	ctx.r11.s64 = 6;
loc_880A1E44:
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// bl 0x88153070
	ctx.lr = 0x880A1E4C;
	sub_88153070(ctx, base);
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// clrlwi r3,r3,16
	ctx.r3.u64 = ctx.r3.u32 & 0xFFFF;
	// bl 0x88153010
	ctx.lr = 0x880A1E5C;
	sub_88153010(ctx, base);
	// clrlwi r10,r3,16
	ctx.r10.u64 = ctx.r3.u32 & 0xFFFF;
	// stw r10,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
loc_880A1E64:
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// bgt cr6,0x880a2000
	if (ctx.cr6.gt) goto loc_880A2000;
	// beq cr6,0x880a1fb0
	if (ctx.cr6.eq) goto loc_880A1FB0;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x880a1e88
	if (ctx.cr6.lt) goto loc_880A1E88;
	// beq cr6,0x880a1ea4
	if (ctx.cr6.eq) goto loc_880A1EA4;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_880A1E88:
	// li r11,2
	ctx.r11.s64 = 2;
	// li r10,91
	ctx.r10.s64 = 91;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// stw r10,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r10.u32);
	// stw r9,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r9.u32);
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
loc_880A1EA4:
	// lwz r11,116(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// li r10,255
	ctx.r10.s64 = 255;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r11.u32);
	// cmpwi cr6,r11,255
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 255, ctx.xer);
	// ble cr6,0x880a1ec0
	if (!ctx.cr6.gt) goto loc_880A1EC0;
	// stw r10,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r10.u32);
loc_880A1EC0:
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// cmpwi cr6,r11,255
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 255, ctx.xer);
	// ble cr6,0x880a1ed8
	if (!ctx.cr6.gt) goto loc_880A1ED8;
	// stw r10,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r10.u32);
loc_880A1ED8:
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r11,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// cmpwi cr6,r11,255
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 255, ctx.xer);
	// ble cr6,0x880a1ef0
	if (!ctx.cr6.gt) goto loc_880A1EF0;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
loc_880A1EF0:
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880a1f28
	if (ctx.cr6.eq) goto loc_880A1F28;
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// lwz r10,26428(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26428);
	// clrlwi r9,r10,30
	ctx.r9.u64 = ctx.r10.u32 & 0x3;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x880a1f18
	if (!ctx.cr6.eq) goto loc_880A1F18;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
loc_880A1F18:
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x880a1f28
	if (!ctx.cr6.lt) goto loc_880A1F28;
	// stw r29,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r29.u32);
loc_880A1F28:
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880a2020
	if (ctx.cr6.eq) goto loc_880A2020;
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// bge 0x880a2020
	if (!ctx.cr0.lt) goto loc_880A2020;
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// stw r29,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r29.u32);
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// addi r30,r11,-10888
	ctx.r30.s64 = ctx.r11.s64 + -10888;
	// addi r9,r10,26432
	ctx.r9.s64 = ctx.r10.s64 + 26432;
	// li r8,10
	ctx.r8.s64 = 10;
	// li r7,64
	ctx.r7.s64 = 64;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r8,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r8.u32);
	// lwz r11,-1096(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -1096);
	// lis r6,-30719
	ctx.r6.s64 = -2013200384;
	// addi r3,r6,-4572
	ctx.r3.s64 = ctx.r6.s64 + -4572;
	// stw r7,120(r11)
	PPC_STORE_U32(ctx.r11.u32 + 120, ctx.r7.u32);
	// stw r29,124(r11)
	PPC_STORE_U32(ctx.r11.u32 + 124, ctx.r29.u32);
	// stw r10,128(r9)
	PPC_STORE_U32(ctx.r9.u32 + 128, ctx.r10.u32);
	// bl 0x880e3888
	ctx.lr = 0x880A1F84;
	sub_880E3888(ctx, base);
	// lwz r11,-4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -4);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x880a2020
	if (!ctx.cr6.eq) goto loc_880A2020;
	// lis r9,-30628
	ctx.r9.s64 = -2007236608;
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// addi r8,r9,26648
	ctx.r8.s64 = ctx.r9.s64 + 26648;
	// stw r11,156(r8)
	PPC_STORE_U32(ctx.r8.u32 + 156, ctx.r11.u32);
	// sth r10,160(r8)
	PPC_STORE_U16(ctx.r8.u32 + 160, ctx.r10.u16);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_880A1FB0:
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// bge 0x880a2020
	if (!ctx.cr0.lt) goto loc_880A2020;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// li r9,10
	ctx.r9.s64 = 10;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// divw r11,r11,r9
	ctx.r11.s32 = ppc_divw(ctx.r11.s32, ctx.r9.s32);
	// li r3,243
	ctx.r3.s64 = 243;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addis r4,r8,2
	ctx.r4.s64 = ctx.r8.s64 + 131072;
	// bl 0x880958a0
	ctx.lr = 0x880A1FE8;
	sub_880958A0(ctx, base);
	// li r7,20
	ctx.r7.s64 = 20;
	// li r6,2
	ctx.r6.s64 = 2;
	// stw r7,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r7.u32);
	// stw r6,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r6.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_880A2000:
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bne cr6,0x880a2020
	if (!ctx.cr6.eq) goto loc_880A2020;
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// bgt 0x880a2020
	if (ctx.cr0.gt) goto loc_880A2020;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88094220
	ctx.lr = 0x880A2020;
	sub_88094220(ctx, base);
loc_880A2020:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A2028"))) PPC_WEAK_FUNC(sub_880A2028);
PPC_FUNC_IMPL(__imp__sub_880A2028) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880A2030;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-30643
	ctx.r30.s64 = -2008219648;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r11,26272(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 26272);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880a2134
	if (!ctx.cr6.eq) goto loc_880A2134;
	// bl 0x880a1d30
	ctx.lr = 0x880A2050;
	sub_880A1D30(ctx, base);
	// lwz r11,26272(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 26272);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880a2064
	if (ctx.cr6.eq) goto loc_880A2064;
	// li r7,0
	ctx.r7.s64 = 0;
	// b 0x880a207c
	goto loc_880A207C;
loc_880A2064:
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// addi r9,r11,51
	ctx.r9.s64 = ctx.r11.s64 + 51;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-11984(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11984);
	// lwzx r7,r8,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
loc_880A207C:
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// clrlwi r9,r10,23
	ctx.r9.u64 = ctx.r10.u32 & 0x1FF;
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r11,9552
	ctx.r11.s64 = ctx.r11.s64 + 9552;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// addi r4,r9,128
	ctx.r4.s64 = ctx.r9.s64 + 128;
	// rlwinm r3,r9,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r4,r4,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x7FC;
	// add r9,r8,r7
	ctx.r9.u64 = ctx.r8.u64 + ctx.r7.u64;
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// lwzx r3,r3,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r11.u32);
	// mullw r6,r3,r5
	ctx.r6.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r5.s32);
	// lwzx r8,r4,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r11.u32);
	// mullw r8,r8,r5
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r5.s32);
	// add r6,r6,r9
	ctx.r6.u64 = ctx.r6.u64 + ctx.r9.u64;
	// add r9,r8,r7
	ctx.r9.u64 = ctx.r8.u64 + ctx.r7.u64;
	// stw r6,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r6.u32);
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// beq cr6,0x880a2110
	if (ctx.cr6.eq) goto loc_880A2110;
	// lwz r8,32(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// rotlwi r7,r6,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// clrlwi r8,r8,23
	ctx.r8.u64 = ctx.r8.u32 & 0x1FF;
	// addi r6,r8,128
	ctx.r6.s64 = ctx.r8.s64 + 128;
	// rlwinm r5,r8,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r4,r6,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// lwzx r3,r5,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r11.u32);
	// lwzx r11,r4,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r11.u32);
	// mullw r8,r3,r10
	ctx.r8.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r10.s32);
	// mullw r11,r11,r10
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// add r10,r8,r7
	ctx.r10.u64 = ctx.r8.u64 + ctx.r7.u64;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
loc_880A2110:
	// lwz r11,2304(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 2304);
	// lwz r10,7816(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 7816);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880a2134
	if (ctx.cr6.eq) goto loc_880A2134;
	// li r10,128
	ctx.r10.s64 = 128;
	// addi r11,r11,132
	ctx.r11.s64 = ctx.r11.s64 + 132;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_880A212C:
	// addi r11,r11,60
	ctx.r11.s64 = ctx.r11.s64 + 60;
	// bdnz 0x880a212c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_880A212C;
loc_880A2134:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A213C"))) PPC_WEAK_FUNC(sub_880A213C);
PPC_FUNC_IMPL(__imp__sub_880A213C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A2140"))) PPC_WEAK_FUNC(sub_880A2140);
PPC_FUNC_IMPL(__imp__sub_880A2140) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880A2148;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30710
	ctx.r11.s64 = -2012610560;
	// li r4,7832
	ctx.r4.s64 = 7832;
	// addi r5,r11,8512
	ctx.r5.s64 = ctx.r11.s64 + 8512;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x880A2160;
	sub_88094290(ctx, base);
	// li r5,7832
	ctx.r5.s64 = 7832;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,2304(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2304);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x880A2174;
	sub_88073BD0(ctx, base);
	// lis r8,-30597
	ctx.r8.s64 = -2005204992;
	// li r29,1
	ctx.r29.s64 = 1;
	// lis r7,152
	ctx.r7.s64 = 9961472;
	// stw r29,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r29.u32);
	// lis r9,192
	ctx.r9.s64 = 12582912;
	// addi r5,r8,-11984
	ctx.r5.s64 = ctx.r8.s64 + -11984;
	// lwz r10,-11984(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + -11984);
	// li r6,130
	ctx.r6.s64 = 130;
	// lis r4,120
	ctx.r4.s64 = 7864320;
	// addic. r11,r30,120
	ctx.xer.ca = ctx.r30.u32 > 4294967175;
	ctx.r11.s64 = ctx.r30.s64 + 120;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r30,-12(r5)
	PPC_STORE_U32(ctx.r5.u32 + -12, ctx.r30.u32);
	// lwz r3,224(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 224);
	// subf r10,r3,r7
	ctx.r10.s64 = ctx.r7.s64 - ctx.r3.s64;
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// lwz r8,32(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// stw r6,168(r30)
	PPC_STORE_U32(ctx.r30.u32 + 168, ctx.r6.u32);
	// stw r8,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// lwz r7,36(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// stw r7,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r7.u32);
	// stw r4,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r4.u32);
	// stw r9,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r9.u32);
	// beq 0x880a2208
	if (ctx.cr0.eq) goto loc_880A2208;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r9.u32);
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// stw r8,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r8.u32);
	// lwz r7,16(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// stw r7,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r7.u32);
	// lwz r6,20(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// stw r6,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r6.u32);
	// lwz r5,24(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// stw r5,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r5.u32);
	// lwz r4,28(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// stw r4,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r4.u32);
loc_880A2208:
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// li r10,128
	ctx.r10.s64 = 128;
	// li r9,256
	ctx.r9.s64 = 256;
	// li r8,7
	ctx.r8.s64 = 7;
	// stw r10,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r10.u32);
	// stw r9,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r9.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,26428(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26428);
	// stw r8,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r8.u32);
	// stw r11,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r11.u32);
	// bl 0x880a1af8
	ctx.lr = 0x880A2234;
	sub_880A1AF8(ctx, base);
	// lis r7,-30710
	ctx.r7.s64 = -2012610560;
	// lis r6,-30710
	ctx.r6.s64 = -2012610560;
	// stw r30,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// lis r5,-30710
	ctx.r5.s64 = -2012610560;
	// stw r29,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r29.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r29,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r29.u32);
	// li r4,255
	ctx.r4.s64 = 255;
	// addi r3,r7,8232
	ctx.r3.s64 = ctx.r7.s64 + 8232;
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// addi r10,r6,7120
	ctx.r10.s64 = ctx.r6.s64 + 7120;
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// addi r9,r5,6840
	ctx.r9.s64 = ctx.r5.s64 + 6840;
	// stw r4,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r4.u32);
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stw r3,64(r30)
	PPC_STORE_U32(ctx.r30.u32 + 64, ctx.r3.u32);
	// stw r10,68(r30)
	PPC_STORE_U32(ctx.r30.u32 + 68, ctx.r10.u32);
	// stw r9,84(r30)
	PPC_STORE_U32(ctx.r30.u32 + 84, ctx.r9.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A2288"))) PPC_WEAK_FUNC(sub_880A2288);
PPC_FUNC_IMPL(__imp__sub_880A2288) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lwz r11,-11996(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11996);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,2304(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2304);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,84(r11)
	PPC_STORE_U32(ctx.r11.u32 + 84, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880A22A8"))) PPC_WEAK_FUNC(sub_880A22A8);
PPC_FUNC_IMPL(__imp__sub_880A22A8) {
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
	// lwz r4,80(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 80);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x880a22c8
	if (ctx.cr6.eq) goto loc_880A22C8;
	// bl 0x88093ae8
	ctx.lr = 0x880A22C8;
	sub_88093AE8(ctx, base);
loc_880A22C8:
	// lwz r4,84(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 84);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x880a22d8
	if (ctx.cr6.eq) goto loc_880A22D8;
	// bl 0x88093ae8
	ctx.lr = 0x880A22D8;
	sub_88093AE8(ctx, base);
loc_880A22D8:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,80(r7)
	PPC_STORE_U32(ctx.r7.u32 + 80, ctx.r11.u32);
	// stw r11,84(r7)
	PPC_STORE_U32(ctx.r7.u32 + 84, ctx.r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880A22F4"))) PPC_WEAK_FUNC(sub_880A22F4);
PPC_FUNC_IMPL(__imp__sub_880A22F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A22F8"))) PPC_WEAK_FUNC(sub_880A22F8);
PPC_FUNC_IMPL(__imp__sub_880A22F8) {
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
	ctx.lr = 0x880A2324;
	sub_88096BC8(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// cmpwi cr6,r10,6
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 6, ctx.xer);
	// beq cr6,0x880a2348
	if (ctx.cr6.eq) goto loc_880A2348;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880A2340;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880a23a8
	goto loc_880A23A8;
loc_880A2348:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// bgt 0x880a23a4
	if (ctx.cr0.gt) goto loc_880A23A4;
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
	// cmpwi cr6,r8,8
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 8, ctx.xer);
	// blt cr6,0x880a23a4
	if (ctx.cr6.lt) goto loc_880A23A4;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,7
	ctx.r9.s64 = 7;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,68(r8)
	PPC_STORE_U32(ctx.r8.u32 + 68, ctx.r9.u32);
	// bl 0x88096b40
	ctx.lr = 0x880A239C;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880a23a8
	goto loc_880A23A8;
loc_880A23A4:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880A23A8:
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

__attribute__((alias("__imp__sub_880A23C0"))) PPC_WEAK_FUNC(sub_880A23C0);
PPC_FUNC_IMPL(__imp__sub_880A23C0) {
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
	ctx.lr = 0x880A23EC;
	sub_88096BC8(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// cmpwi cr6,r10,4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4, ctx.xer);
	// beq cr6,0x880a2410
	if (ctx.cr6.eq) goto loc_880A2410;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880A2408;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880a246c
	goto loc_880A246C;
loc_880A2410:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// bgt 0x880a2468
	if (ctx.cr0.gt) goto loc_880A2468;
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
	// cmpwi cr6,r8,16
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16, ctx.xer);
	// blt cr6,0x880a2468
	if (ctx.cr6.lt) goto loc_880A2468;
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
	// stw r10,68(r11)
	PPC_STORE_U32(ctx.r11.u32 + 68, ctx.r10.u32);
	// bl 0x88096b40
	ctx.lr = 0x880A2460;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880a246c
	goto loc_880A246C;
loc_880A2468:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880A246C:
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

__attribute__((alias("__imp__sub_880A2484"))) PPC_WEAK_FUNC(sub_880A2484);
PPC_FUNC_IMPL(__imp__sub_880A2484) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A2488"))) PPC_WEAK_FUNC(sub_880A2488);
PPC_FUNC_IMPL(__imp__sub_880A2488) {
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
	ctx.lr = 0x880A24B4;
	sub_88096BC8(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// beq cr6,0x880a24d8
	if (ctx.cr6.eq) goto loc_880A24D8;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880A24D0;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880a2534
	goto loc_880A2534;
loc_880A24D8:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// bgt 0x880a2530
	if (ctx.cr0.gt) goto loc_880A2530;
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
	// cmpwi cr6,r8,4
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 4, ctx.xer);
	// blt cr6,0x880a2530
	if (ctx.cr6.lt) goto loc_880A2530;
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
	// stw r10,68(r11)
	PPC_STORE_U32(ctx.r11.u32 + 68, ctx.r10.u32);
	// bl 0x88096b40
	ctx.lr = 0x880A2528;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880a2534
	goto loc_880A2534;
loc_880A2530:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880A2534:
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

__attribute__((alias("__imp__sub_880A254C"))) PPC_WEAK_FUNC(sub_880A254C);
PPC_FUNC_IMPL(__imp__sub_880A254C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A2550"))) PPC_WEAK_FUNC(sub_880A2550);
PPC_FUNC_IMPL(__imp__sub_880A2550) {
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
	ctx.lr = 0x880A257C;
	sub_88096BC8(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// beq cr6,0x880a25a0
	if (ctx.cr6.eq) goto loc_880A25A0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880A2598;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880a2600
	goto loc_880A2600;
loc_880A25A0:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// bgt 0x880a25fc
	if (ctx.cr0.gt) goto loc_880A25FC;
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
	// cmpwi cr6,r8,8
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 8, ctx.xer);
	// blt cr6,0x880a25fc
	if (ctx.cr6.lt) goto loc_880A25FC;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,68(r8)
	PPC_STORE_U32(ctx.r8.u32 + 68, ctx.r9.u32);
	// bl 0x88096b40
	ctx.lr = 0x880A25F4;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880a2600
	goto loc_880A2600;
loc_880A25FC:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880A2600:
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

__attribute__((alias("__imp__sub_880A2618"))) PPC_WEAK_FUNC(sub_880A2618);
PPC_FUNC_IMPL(__imp__sub_880A2618) {
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
	// lwz r10,1468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1468);
	// addic. r10,r10,-8
	ctx.xer.ca = ctx.r10.u32 > 7;
	ctx.r10.s64 = ctx.r10.s64 + -8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,1468(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1468, ctx.r10.u32);
	// bgt 0x880a2668
	if (ctx.cr0.gt) goto loc_880A2668;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// stw r10,1468(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1468, ctx.r10.u32);
	// bl 0x880a0260
	ctx.lr = 0x880A264C;
	sub_880A0260(ctx, base);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// bl 0x88096b40
	ctx.lr = 0x880A2654;
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
loc_880A2668:
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

__attribute__((alias("__imp__sub_880A267C"))) PPC_WEAK_FUNC(sub_880A267C);
PPC_FUNC_IMPL(__imp__sub_880A267C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A2680"))) PPC_WEAK_FUNC(sub_880A2680);
PPC_FUNC_IMPL(__imp__sub_880A2680) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x880A2688;
	__savegprlr_24(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r30,2304(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// li r31,0
	ctx.r31.s64 = 0;
	// lwz r11,184(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// lwz r10,168(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// li r24,2
	ctx.r24.s64 = 2;
	// li r25,256
	ctx.r25.s64 = 256;
	// add r28,r11,r10
	ctx.r28.u64 = ctx.r11.u64 + ctx.r10.u64;
	// std r31,0(r9)
	PPC_STORE_U64(ctx.r9.u32 + 0, ctx.r31.u64);
	// addi r27,r30,8
	ctx.r27.s64 = ctx.r30.s64 + 8;
	// std r31,8(r9)
	PPC_STORE_U64(ctx.r9.u32 + 8, ctx.r31.u64);
	// addi r26,r30,20
	ctx.r26.s64 = ctx.r30.s64 + 20;
	// std r31,16(r9)
	PPC_STORE_U64(ctx.r9.u32 + 16, ctx.r31.u64);
	// lis r8,16
	ctx.r8.s64 = 1048576;
	// std r31,24(r9)
	PPC_STORE_U64(ctx.r9.u32 + 24, ctx.r31.u64);
	// lwz r7,80(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 80);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// stw r31,32(r9)
	PPC_STORE_U32(ctx.r9.u32 + 32, ctx.r31.u32);
	// stw r27,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r27.u32);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// stw r24,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r24.u32);
	// stw r26,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r26.u32);
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r31.u32);
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// stw r25,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r25.u32);
	// stw r28,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r28.u32);
	// stw r28,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r28.u32);
	// bne cr6,0x880a2708
	if (!ctx.cr6.eq) goto loc_880A2708;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x88093be8
	ctx.lr = 0x880A2704;
	sub_88093BE8(ctx, base);
	// stw r3,80(r30)
	PPC_STORE_U32(ctx.r30.u32 + 80, ctx.r3.u32);
loc_880A2708:
	// lwz r10,84(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 84);
	// addi r11,r28,-1
	ctx.r11.s64 = ctx.r28.s64 + -1;
	// lis r9,-32
	ctx.r9.s64 = -2097152;
	// stw r27,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r27.u32);
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r26,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r26.u32);
	// stw r24,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r24.u32);
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r31.u32);
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r25,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r25.u32);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// bne cr6,0x880a274c
	if (!ctx.cr6.eq) goto loc_880A274C;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88093be8
	ctx.lr = 0x880A2748;
	sub_88093BE8(ctx, base);
	// stw r3,84(r30)
	PPC_STORE_U32(ctx.r30.u32 + 84, ctx.r3.u32);
loc_880A274C:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A2754"))) PPC_WEAK_FUNC(sub_880A2754);
PPC_FUNC_IMPL(__imp__sub_880A2754) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A2758"))) PPC_WEAK_FUNC(sub_880A2758);
PPC_FUNC_IMPL(__imp__sub_880A2758) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071130
	ctx.lr = 0x880A2760;
	__savegprlr_18(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r20,r4
	ctx.r20.u64 = ctx.r4.u64;
	// mr r19,r5
	ctx.r19.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r19
	ctx.r4.u64 = ctx.r19.u64;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880A277C;
	sub_88096BC8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r24,8(r3)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// li r18,0
	ctx.r18.s64 = 0;
	// li r21,2
	ctx.r21.s64 = 2;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x880a27a8
	if (ctx.cr6.lt) goto loc_880A27A8;
	// beq cr6,0x880a27bc
	if (ctx.cr6.eq) goto loc_880A27BC;
loc_880A279C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x88071180
	__restgprlr_18(ctx, base);
	return;
loc_880A27A8:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r18,16(r25)
	PPC_STORE_U32(ctx.r25.u32 + 16, ctx.r18.u32);
	// stw r21,20(r25)
	PPC_STORE_U32(ctx.r25.u32 + 20, ctx.r21.u32);
	// stw r18,24(r25)
	PPC_STORE_U32(ctx.r25.u32 + 24, ctx.r18.u32);
	// stw r11,0(r25)
	PPC_STORE_U32(ctx.r25.u32 + 0, ctx.r11.u32);
loc_880A27BC:
	// lwz r11,16(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 16);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,16(r25)
	PPC_STORE_U32(ctx.r25.u32 + 16, ctx.r11.u32);
	// bge 0x880a279c
	if (!ctx.cr0.lt) goto loc_880A279C;
	// lwz r11,24(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 24);
	// lis r9,-30683
	ctx.r9.s64 = -2010841088;
	// lwz r8,20(r25)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r25.u32 + 20);
	// lis r27,-30667
	ctx.r27.s64 = -2009792512;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r7,4(r25)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r25.u32 + 4);
	// addi r9,r9,27912
	ctx.r9.s64 = ctx.r9.s64 + 27912;
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lis r26,-30667
	ctx.r26.s64 = -2009792512;
	// rlwinm r11,r6,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,16(r25)
	PPC_STORE_U32(ctx.r25.u32 + 16, ctx.r8.u32);
	// lwz r8,12(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// add r31,r11,r9
	ctx.r31.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r7,16(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// lis r22,-30667
	ctx.r22.s64 = -2009792512;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// add r29,r8,r11
	ctx.r29.u64 = ctx.r8.u64 + ctx.r11.u64;
	// add r28,r7,r10
	ctx.r28.u64 = ctx.r7.u64 + ctx.r10.u64;
	// stw r29,12364(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12364, ctx.r29.u32);
	// stw r28,12372(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12372, ctx.r28.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880A282C;
	sub_880F52C8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x881534c8
	ctx.lr = 0x880A2838;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,16
	ctx.r3.s64 = 16;
	// addi r23,r11,240
	ctx.r23.s64 = ctx.r11.s64 + 240;
	// bl 0x881534c8
	ctx.lr = 0x880A2848;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r4,r11,72
	ctx.r4.s64 = ctx.r11.s64 + 72;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// bl 0x880f5570
	ctx.lr = 0x880A285C;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x880a2870
	if (ctx.cr6.eq) goto loc_880A2870;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// clrlwi r10,r11,16
	ctx.r10.u64 = ctx.r11.u32 & 0xFFFF;
	// stw r10,100(r30)
	PPC_STORE_U32(ctx.r30.u32 + 100, ctx.r10.u32);
loc_880A2870:
	// stw r29,12364(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12364, ctx.r29.u32);
	// addi r30,r24,1
	ctx.r30.s64 = ctx.r24.s64 + 1;
	// stw r28,12372(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12372, ctx.r28.u32);
	// lis r24,-30667
	ctx.r24.s64 = -2009792512;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// bl 0x880f52c8
	ctx.lr = 0x880A2890;
	sub_880F52C8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880a28a0
	if (ctx.cr6.eq) goto loc_880A28A0;
	// stw r21,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r21.u32);
loc_880A28A0:
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x881534c8
	ctx.lr = 0x880A28A8;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,32
	ctx.r3.s64 = 32;
	// addi r11,r11,72
	ctx.r11.s64 = ctx.r11.s64 + 72;
	// rlwinm r21,r11,1,0,30
	ctx.r21.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// bl 0x881534c8
	ctx.lr = 0x880A28BC;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
	// add r11,r11,r23
	ctx.r11.u64 = ctx.r11.u64 + ctx.r23.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r5,r11,-16
	ctx.r5.s64 = ctx.r11.s64 + -16;
	// bl 0x880f5570
	ctx.lr = 0x880A28D4;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x880a28ec
	if (ctx.cr6.eq) goto loc_880A28EC;
	// li r11,112
	ctx.r11.s64 = 112;
	// li r10,10
	ctx.r10.s64 = 10;
	// stw r11,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r11.u32);
	// stw r10,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r10.u32);
loc_880A28EC:
	// stw r29,12364(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12364, ctx.r29.u32);
	// li r11,24
	ctx.r11.s64 = 24;
	// stw r28,12372(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12372, ctx.r28.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,12380(r22)
	PPC_STORE_U32(ctx.r22.u32 + 12380, ctx.r11.u32);
	// bl 0x880f34b0
	ctx.lr = 0x880A2908;
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
	// beq cr6,0x880a295c
	if (ctx.cr6.eq) goto loc_880A295C;
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
loc_880A295C:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x880f34b0
	ctx.lr = 0x880A2968;
	sub_880F34B0(ctx, base);
	// mullw r11,r27,r29
	ctx.r11.s64 = int64_t(ctx.r27.s32) * int64_t(ctx.r29.s32);
	// addi r27,r11,12345
	ctx.r27.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r27,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r27.u32);
	// beq cr6,0x880a29a4
	if (ctx.cr6.eq) goto loc_880A29A4;
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
loc_880A29A4:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r30,12376(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12376, ctx.r30.u32);
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x880f34b0
	ctx.lr = 0x880A29B4;
	sub_880F34B0(ctx, base);
	// mullw r11,r27,r29
	ctx.r11.s64 = int64_t(ctx.r27.s32) * int64_t(ctx.r29.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r11,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r11.u32);
	// beq cr6,0x880a29f0
	if (ctx.cr6.eq) goto loc_880A29F0;
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
loc_880A29F0:
	// lwz r11,24(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 24);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,24(r25)
	PPC_STORE_U32(ctx.r25.u32 + 24, ctx.r11.u32);
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// blt cr6,0x880a279c
	if (ctx.cr6.lt) goto loc_880A279C;
	// stw r18,24(r25)
	PPC_STORE_U32(ctx.r25.u32 + 24, ctx.r18.u32);
	// mr r4,r19
	ctx.r4.u64 = ctx.r19.u64;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// bl 0x88096b40
	ctx.lr = 0x880A2A14;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x88071180
	__restgprlr_18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A2A20"))) PPC_WEAK_FUNC(sub_880A2A20);
PPC_FUNC_IMPL(__imp__sub_880A2A20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807112c
	ctx.lr = 0x880A2A28;
	__savegprlr_17(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r19,r4
	ctx.r19.u64 = ctx.r4.u64;
	// lwz r21,2304(r3)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r18,r5
	ctx.r18.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880A2A48;
	sub_88096BC8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r23,8(r3)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r17,0
	ctx.r17.s64 = 0;
	// li r20,2
	ctx.r20.s64 = 2;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x880a2a74
	if (ctx.cr6.lt) goto loc_880A2A74;
	// beq cr6,0x880a2a88
	if (ctx.cr6.eq) goto loc_880A2A88;
loc_880A2A68:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8807117c
	__restgprlr_17(ctx, base);
	return;
loc_880A2A74:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r17,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r17.u32);
	// stw r20,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r20.u32);
	// stw r17,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r17.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_880A2A88:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// bge 0x880a2a68
	if (!ctx.cr0.lt) goto loc_880A2A68;
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lis r9,-30683
	ctx.r9.s64 = -2010841088;
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lis r26,-30667
	ctx.r26.s64 = -2009792512;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r9,r9,27480
	ctx.r9.s64 = ctx.r9.s64 + 27480;
	// lwz r7,60(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// lis r25,-30667
	ctx.r25.s64 = -2009792512;
	// rlwinm r11,r4,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r8.u32);
	// lwz r8,12(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// add r30,r11,r9
	ctx.r30.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r6,16(r6)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// lis r22,-30667
	ctx.r22.s64 = -2009792512;
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// srawi r11,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r9.s32 >> 2;
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// addze r10,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r10.s64 = temp.s64;
	// add r28,r11,r7
	ctx.r28.u64 = ctx.r11.u64 + ctx.r7.u64;
	// add r11,r10,r6
	ctx.r11.u64 = ctx.r10.u64 + ctx.r6.u64;
	// stw r28,12364(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12364, ctx.r28.u32);
	// add r27,r11,r5
	ctx.r27.u64 = ctx.r11.u64 + ctx.r5.u64;
	// stw r27,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r27.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880A2B18;
	sub_880F52C8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x881534c8
	ctx.lr = 0x880A2B24;
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
	// addi r24,r11,248
	ctx.r24.s64 = ctx.r11.s64 + 248;
	// bl 0x881534c8
	ctx.lr = 0x880A2B48;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r4,r11,72
	ctx.r4.s64 = ctx.r11.s64 + 72;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// bl 0x880f5570
	ctx.lr = 0x880A2B5C;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x880a2b70
	if (ctx.cr6.eq) goto loc_880A2B70;
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// clrlwi r10,r11,16
	ctx.r10.u64 = ctx.r11.u32 & 0xFFFF;
	// stw r10,100(r29)
	PPC_STORE_U32(ctx.r29.u32 + 100, ctx.r10.u32);
loc_880A2B70:
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// mulli r11,r10,28
	ctx.r11.s64 = ctx.r10.s64 * 28;
	// add r11,r11,r21
	ctx.r11.u64 = ctx.r11.u64 + ctx.r21.u64;
	// lwz r9,1592(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1592);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x880a2bb0
	if (!ctx.cr6.eq) goto loc_880A2BB0;
	// addi r10,r10,57
	ctx.r10.s64 = ctx.r10.s64 + 57;
	// lwz r9,0(r21)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r21.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r8,1608(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1608);
	// mulli r5,r10,28
	ctx.r5.s64 = ctx.r10.s64 * 28;
	// lwz r7,1604(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1604);
	// lwz r6,1600(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1600);
	// lwz r4,12(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwzx r5,r5,r21
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r21.u32);
	// bl 0x880f5438
	ctx.lr = 0x880A2BB0;
	sub_880F5438(ctx, base);
loc_880A2BB0:
	// stw r28,12364(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12364, ctx.r28.u32);
	// addi r29,r23,1
	ctx.r29.s64 = ctx.r23.s64 + 1;
	// stw r27,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r27.u32);
	// lis r23,-30667
	ctx.r23.s64 = -2009792512;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// bl 0x880f52c8
	ctx.lr = 0x880A2BD0;
	sub_880F52C8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880a2be0
	if (ctx.cr6.eq) goto loc_880A2BE0;
	// stw r20,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r20.u32);
loc_880A2BE0:
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x881534c8
	ctx.lr = 0x880A2BE8;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,32
	ctx.r3.s64 = 32;
	// addi r11,r11,72
	ctx.r11.s64 = ctx.r11.s64 + 72;
	// rlwinm r21,r11,1,0,30
	ctx.r21.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// bl 0x881534c8
	ctx.lr = 0x880A2BFC;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
	// add r11,r11,r24
	ctx.r11.u64 = ctx.r11.u64 + ctx.r24.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r5,r11,-16
	ctx.r5.s64 = ctx.r11.s64 + -16;
	// bl 0x880f5570
	ctx.lr = 0x880A2C14;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x880a2c2c
	if (ctx.cr6.eq) goto loc_880A2C2C;
	// li r11,112
	ctx.r11.s64 = 112;
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r11,140(r30)
	PPC_STORE_U32(ctx.r30.u32 + 140, ctx.r11.u32);
	// stw r10,100(r30)
	PPC_STORE_U32(ctx.r30.u32 + 100, ctx.r10.u32);
loc_880A2C2C:
	// stw r28,12364(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12364, ctx.r28.u32);
	// li r11,24
	ctx.r11.s64 = 24;
	// stw r27,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r27.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,12380(r22)
	PPC_STORE_U32(ctx.r22.u32 + 12380, ctx.r11.u32);
	// bl 0x880f34b0
	ctx.lr = 0x880A2C48;
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
	// beq cr6,0x880a2c9c
	if (ctx.cr6.eq) goto loc_880A2C9C;
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
	// add r11,r11,r24
	ctx.r11.u64 = ctx.r11.u64 + ctx.r24.u64;
	// addi r4,r11,-32
	ctx.r4.s64 = ctx.r11.s64 + -32;
	// sth r4,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, ctx.r4.u16);
loc_880A2C9C:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x880f34b0
	ctx.lr = 0x880A2CA8;
	sub_880F34B0(ctx, base);
	// mullw r11,r26,r28
	ctx.r11.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r28.s32);
	// addi r26,r11,12345
	ctx.r26.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r26,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r26.u32);
	// beq cr6,0x880a2ce4
	if (ctx.cr6.eq) goto loc_880A2CE4;
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
	// add r11,r11,r24
	ctx.r11.u64 = ctx.r11.u64 + ctx.r24.u64;
	// addi r4,r11,-32
	ctx.r4.s64 = ctx.r11.s64 + -32;
	// sth r4,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, ctx.r4.u16);
loc_880A2CE4:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r29,12376(r23)
	PPC_STORE_U32(ctx.r23.u32 + 12376, ctx.r29.u32);
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x880f34b0
	ctx.lr = 0x880A2CF4;
	sub_880F34B0(ctx, base);
	// mullw r11,r26,r28
	ctx.r11.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r28.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r11,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r11.u32);
	// beq cr6,0x880a2d30
	if (ctx.cr6.eq) goto loc_880A2D30;
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
	// add r11,r11,r24
	ctx.r11.u64 = ctx.r11.u64 + ctx.r24.u64;
	// addi r4,r11,-32
	ctx.r4.s64 = ctx.r11.s64 + -32;
	// sth r4,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, ctx.r4.u16);
loc_880A2D30:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// cmplwi cr6,r11,12
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 12, ctx.xer);
	// blt cr6,0x880a2a68
	if (ctx.cr6.lt) goto loc_880A2A68;
	// stw r17,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r17.u32);
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// bl 0x88096b40
	ctx.lr = 0x880A2D54;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8807117c
	__restgprlr_17(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A2D60"))) PPC_WEAK_FUNC(sub_880A2D60);
PPC_FUNC_IMPL(__imp__sub_880A2D60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807112c
	ctx.lr = 0x880A2D68;
	__savegprlr_17(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r18,r4
	ctx.r18.u64 = ctx.r4.u64;
	// lwz r21,2304(r3)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r17,r5
	ctx.r17.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880A2D88;
	sub_88096BC8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r30,8(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r19,0
	ctx.r19.s64 = 0;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x880a2db0
	if (ctx.cr6.lt) goto loc_880A2DB0;
	// beq cr6,0x880a2df4
	if (ctx.cr6.eq) goto loc_880A2DF4;
loc_880A2DA4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8807117c
	__restgprlr_17(ctx, base);
	return;
loc_880A2DB0:
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r19,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r19.u32);
	// li r10,48
	ctx.r10.s64 = 48;
	// stw r19,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r19.u32);
	// li r3,16
	ctx.r3.s64 = 16;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stw r10,36(r21)
	PPC_STORE_U32(ctx.r21.u32 + 36, ctx.r10.u32);
	// bl 0x881534c8
	ctx.lr = 0x880A2DD0;
	sub_881534C8(ctx, base);
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// extsh r10,r3
	ctx.r10.s64 = ctx.r3.s16;
	// mulli r11,r9,208
	ctx.r11.s64 = ctx.r9.s64 * 208;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r8,r11,251
	ctx.r8.s64 = ctx.r11.s64 + 251;
	// stw r8,40(r21)
	PPC_STORE_U32(ctx.r21.u32 + 40, ctx.r8.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r7,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
loc_880A2DF4:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// bge 0x880a2da4
	if (!ctx.cr0.lt) goto loc_880A2DA4;
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lis r10,-30683
	ctx.r10.s64 = -2010841088;
	// lwz r7,20(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addi r29,r30,1
	ctx.r29.s64 = ctx.r30.s64 + 1;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r8,r10,26976
	ctx.r8.s64 = ctx.r10.s64 + 26976;
	// lwz r28,28(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// add r4,r11,r9
	ctx.r4.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r5,60(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// lwz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r7,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r7.u32);
	// lwz r7,12(r6)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// lis r24,-30667
	ctx.r24.s64 = -2009792512;
	// add r30,r9,r8
	ctx.r30.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lis r25,-30667
	ctx.r25.s64 = -2009792512;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwzx r3,r9,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// lis r20,-30667
	ctx.r20.s64 = -2009792512;
	// lis r22,-30667
	ctx.r22.s64 = -2009792512;
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// srawi r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	// addze r9,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r9.s64 = temp.s64;
	// lwz r6,16(r6)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// srawi r8,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r11.s32 >> 2;
	// addis r11,r9,24
	ctx.r11.s64 = ctx.r9.s64 + 1572864;
	// addze r9,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r9.s64 = temp.s64;
	// mullw r11,r11,r28
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// add r8,r11,r7
	ctx.r8.u64 = ctx.r11.u64 + ctx.r7.u64;
	// add r11,r9,r6
	ctx.r11.u64 = ctx.r9.u64 + ctx.r6.u64;
	// add r27,r8,r5
	ctx.r27.u64 = ctx.r8.u64 + ctx.r5.u64;
	// add r26,r11,r10
	ctx.r26.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r27,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r27.u32);
	// stw r26,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r26.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880A2E9C;
	sub_880F52C8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x881534c8
	ctx.lr = 0x880A2EA8;
	sub_881534C8(ctx, base);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// extsh r9,r3
	ctx.r9.s64 = ctx.r3.s16;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r3,16
	ctx.r3.s64 = 16;
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r7,r8,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r11,r7,r9
	ctx.r11.s64 = ctx.r9.s64 - ctx.r7.s64;
	// addi r23,r11,248
	ctx.r23.s64 = ctx.r11.s64 + 248;
	// bl 0x881534c8
	ctx.lr = 0x880A2ECC;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r4,r11,72
	ctx.r4.s64 = ctx.r11.s64 + 72;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// bl 0x880f5570
	ctx.lr = 0x880A2EE0;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x880a2efc
	if (ctx.cr6.eq) goto loc_880A2EFC;
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// clrlwi r10,r11,16
	ctx.r10.u64 = ctx.r11.u32 & 0xFFFF;
	// stw r10,100(r28)
	PPC_STORE_U32(ctx.r28.u32 + 100, ctx.r10.u32);
	// lwz r9,32(r21)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r21.u32 + 32);
	// stw r9,144(r28)
	PPC_STORE_U32(ctx.r28.u32 + 144, ctx.r9.u32);
loc_880A2EFC:
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// mulli r11,r10,28
	ctx.r11.s64 = ctx.r10.s64 * 28;
	// add r11,r11,r21
	ctx.r11.u64 = ctx.r11.u64 + ctx.r21.u64;
	// lwz r9,1592(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1592);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x880a2f3c
	if (!ctx.cr6.eq) goto loc_880A2F3C;
	// addi r10,r10,57
	ctx.r10.s64 = ctx.r10.s64 + 57;
	// lwz r9,0(r21)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r21.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r8,1608(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1608);
	// mulli r5,r10,28
	ctx.r5.s64 = ctx.r10.s64 * 28;
	// lwz r7,1604(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1604);
	// lwz r6,1600(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1600);
	// lwz r4,12(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwzx r5,r5,r21
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r21.u32);
	// bl 0x880f5438
	ctx.lr = 0x880A2F3C;
	sub_880F5438(ctx, base);
loc_880A2F3C:
	// stw r27,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r27.u32);
	// li r11,24
	ctx.r11.s64 = 24;
	// stw r26,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r26.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,12380(r22)
	PPC_STORE_U32(ctx.r22.u32 + 12380, ctx.r11.u32);
	// bl 0x880f34b0
	ctx.lr = 0x880A2F58;
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
	// beq cr6,0x880a2fac
	if (ctx.cr6.eq) goto loc_880A2FAC;
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
loc_880A2FAC:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x880f34b0
	ctx.lr = 0x880A2FB8;
	sub_880F34B0(ctx, base);
	// mullw r11,r26,r28
	ctx.r11.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r28.s32);
	// addi r26,r11,12345
	ctx.r26.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r26,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r26.u32);
	// beq cr6,0x880a2ff4
	if (ctx.cr6.eq) goto loc_880A2FF4;
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
loc_880A2FF4:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r29,12376(r20)
	PPC_STORE_U32(ctx.r20.u32 + 12376, ctx.r29.u32);
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x880f34b0
	ctx.lr = 0x880A3004;
	sub_880F34B0(ctx, base);
	// mullw r11,r26,r28
	ctx.r11.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r28.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r11,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r11.u32);
	// beq cr6,0x880a3040
	if (ctx.cr6.eq) goto loc_880A3040;
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
loc_880A3040:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// cmplwi cr6,r11,14
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 14, ctx.xer);
	// blt cr6,0x880a2da4
	if (ctx.cr6.lt) goto loc_880A2DA4;
	// stw r19,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r19.u32);
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// bl 0x88096b40
	ctx.lr = 0x880A3064;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8807117c
	__restgprlr_17(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A3070"))) PPC_WEAK_FUNC(sub_880A3070);
PPC_FUNC_IMPL(__imp__sub_880A3070) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880A3078;
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
	// li r5,24
	ctx.r5.s64 = 24;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880A3098;
	sub_88096BC8(ctx, base);
	// addi r10,r29,404
	ctx.r10.s64 = ctx.r29.s64 + 404;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r9,472(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 472);
	// cmpwi cr6,r9,6
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 6, ctx.xer);
	// beq cr6,0x880a30b8
	if (ctx.cr6.eq) goto loc_880A30B8;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_880A30B8:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r8,6
	ctx.r8.s64 = 6;
	// li r10,3
	ctx.r10.s64 = 3;
	// lis r7,-30710
	ctx.r7.s64 = -2012610560;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r7,8952
	ctx.r5.s64 = ctx.r7.s64 + 8952;
	// stw r8,68(r9)
	PPC_STORE_U32(ctx.r9.u32 + 68, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x88096c60
	ctx.lr = 0x880A30E4;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A30F0"))) PPC_WEAK_FUNC(sub_880A30F0);
PPC_FUNC_IMPL(__imp__sub_880A30F0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880A30F8;
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
	// li r5,24
	ctx.r5.s64 = 24;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880A3118;
	sub_88096BC8(ctx, base);
	// addi r10,r29,404
	ctx.r10.s64 = ctx.r29.s64 + 404;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r9,472(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 472);
	// cmpwi cr6,r9,4
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 4, ctx.xer);
	// beq cr6,0x880a3138
	if (ctx.cr6.eq) goto loc_880A3138;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_880A3138:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r8,4
	ctx.r8.s64 = 4;
	// li r10,2
	ctx.r10.s64 = 2;
	// lis r7,-30710
	ctx.r7.s64 = -2012610560;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r7,9152
	ctx.r5.s64 = ctx.r7.s64 + 9152;
	// stw r8,68(r9)
	PPC_STORE_U32(ctx.r9.u32 + 68, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x88096c60
	ctx.lr = 0x880A3164;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A3170"))) PPC_WEAK_FUNC(sub_880A3170);
PPC_FUNC_IMPL(__imp__sub_880A3170) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880A3178;
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
	// li r5,24
	ctx.r5.s64 = 24;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880A3198;
	sub_88096BC8(ctx, base);
	// addi r10,r29,404
	ctx.r10.s64 = ctx.r29.s64 + 404;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r9,472(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 472);
	// cmpwi cr6,r9,3
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 3, ctx.xer);
	// beq cr6,0x880a31b8
	if (ctx.cr6.eq) goto loc_880A31B8;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_880A31B8:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r10,3
	ctx.r10.s64 = 3;
	// lis r8,-30710
	ctx.r8.s64 = -2012610560;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r8,9352
	ctx.r5.s64 = ctx.r8.s64 + 9352;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,68(r9)
	PPC_STORE_U32(ctx.r9.u32 + 68, ctx.r10.u32);
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x88096c60
	ctx.lr = 0x880A31E0;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A31EC"))) PPC_WEAK_FUNC(sub_880A31EC);
PPC_FUNC_IMPL(__imp__sub_880A31EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A31F0"))) PPC_WEAK_FUNC(sub_880A31F0);
PPC_FUNC_IMPL(__imp__sub_880A31F0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880A31F8;
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
	// li r5,24
	ctx.r5.s64 = 24;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880A3218;
	sub_88096BC8(ctx, base);
	// addi r10,r29,404
	ctx.r10.s64 = ctx.r29.s64 + 404;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r9,472(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 472);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// beq cr6,0x880a3238
	if (ctx.cr6.eq) goto loc_880A3238;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_880A3238:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r10,2
	ctx.r10.s64 = 2;
	// lis r7,-30710
	ctx.r7.s64 = -2012610560;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r7,9552
	ctx.r5.s64 = ctx.r7.s64 + 9552;
	// stw r8,68(r9)
	PPC_STORE_U32(ctx.r9.u32 + 68, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x88096c60
	ctx.lr = 0x880A3264;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A3270"))) PPC_WEAK_FUNC(sub_880A3270);
PPC_FUNC_IMPL(__imp__sub_880A3270) {
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
	// li r6,255
	ctx.r6.s64 = 255;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// stw r6,1468(r7)
	PPC_STORE_U32(ctx.r7.u32 + 1468, ctx.r6.u32);
	// bl 0x880a02b8
	ctx.lr = 0x880A3294;
	sub_880A02B8(ctx, base);
	// lis r3,-30710
	ctx.r3.s64 = -2012610560;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// addi r5,r3,9752
	ctx.r5.s64 = ctx.r3.s64 + 9752;
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// bl 0x88096c60
	ctx.lr = 0x880A32A8;
	sub_88096C60(ctx, base);
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

__attribute__((alias("__imp__sub_880A32BC"))) PPC_WEAK_FUNC(sub_880A32BC);
PPC_FUNC_IMPL(__imp__sub_880A32BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A32C0"))) PPC_WEAK_FUNC(sub_880A32C0);
PPC_FUNC_IMPL(__imp__sub_880A32C0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807113c
	ctx.lr = 0x880A32C8;
	__savegprlr_21(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
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
	// bl 0x88096bc8
	ctx.lr = 0x880A32EC;
	sub_88096BC8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880a3380
	if (ctx.cr6.eq) goto loc_880A3380;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// beq cr6,0x880a3338
	if (ctx.cr6.eq) goto loc_880A3338;
	// cmpwi cr6,r11,30
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 30, ctx.xer);
	// bne cr6,0x880a370c
	if (!ctx.cr6.eq) goto loc_880A370C;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// bge 0x880a370c
	if (!ctx.cr0.lt) goto loc_880A370C;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// stw r11,472(r31)
	PPC_STORE_U32(ctx.r31.u32 + 472, ctx.r11.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88096b40
	ctx.lr = 0x880A332C;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8807118c
	__restgprlr_21(ctx, base);
	return;
loc_880A3338:
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// li r11,0
	ctx.r11.s64 = 0;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880a3358
	if (ctx.cr6.eq) goto loc_880A3358;
	// addic. r10,r10,-10
	ctx.xer.ca = ctx.r10.u32 > 9;
	ctx.r10.s64 = ctx.r10.s64 + -10;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// bge 0x880a3358
	if (!ctx.cr0.lt) goto loc_880A3358;
	// stw r11,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
loc_880A3358:
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// bge 0x880a370c
	if (!ctx.cr0.lt) goto loc_880A370C;
	// li r10,30
	ctx.r10.s64 = 30;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8807118c
	__restgprlr_21(ctx, base);
	return;
loc_880A3380:
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// bge 0x880a370c
	if (!ctx.cr0.lt) goto loc_880A370C;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,10
	ctx.r10.s64 = 10;
	// li r9,32
	ctx.r9.s64 = 32;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// li r8,72
	ctx.r8.s64 = 72;
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// li r27,64
	ctx.r27.s64 = 64;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// lis r22,-30667
	ctx.r22.s64 = -2009792512;
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// lis r26,-30667
	ctx.r26.s64 = -2009792512;
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// lis r25,-30667
	ctx.r25.s64 = -2009792512;
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r10,184(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 184);
	// lwz r11,168(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 168);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r23,12(r31)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r31,-30671
	ctx.r31.s64 = -2010054656;
	// addi r4,r11,2
	ctx.r4.s64 = ctx.r11.s64 + 2;
	// lis r11,16838
	ctx.r11.s64 = 1103495168;
	// lis r10,15887
	ctx.r10.s64 = 1041170432;
	// addis r24,r7,-2
	ctx.r24.s64 = ctx.r7.s64 + -131072;
	// lwz r28,4200(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4200);
	// ori r30,r11,20077
	ctx.r30.u64 = ctx.r11.u64 | 20077;
	// ori r29,r10,33761
	ctx.r29.u64 = ctx.r10.u64 | 33761;
loc_880A33FC:
	// mullw r11,r28,r30
	ctx.r11.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r30.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// li r6,8
	ctx.r6.s64 = 8;
	// stw r11,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r11.u32);
	// mullw r11,r11,r30
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// li r3,11
	ctx.r3.s64 = 11;
	// mullw r9,r11,r30
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// lhz r8,4200(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// stw r11,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r11.u32);
	// mulhwu r7,r8,r29
	ctx.r7.u64 = (uint64_t(ctx.r8.u32) * uint64_t(ctx.r29.u32)) >> 32;
	// rlwinm r11,r7,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 29) & 0x1FFFFFFF;
	// addi r28,r9,12345
	ctx.r28.s64 = ctx.r9.s64 + 12345;
	// rlwinm r9,r11,5,0,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xFFFFFFE0;
	// lhz r5,4200(r31)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stw r28,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r28.u32);
	// mulhwu r10,r5,r29
	ctx.r10.u64 = (uint64_t(ctx.r5.u32) * uint64_t(ctx.r29.u32)) >> 32;
	// lhz r9,4200(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// rlwinm r10,r10,29,3,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFFFFFF;
	// subf r8,r11,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r11.s64;
	// rlwinm r11,r10,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// extsh r11,r8
	ctx.r11.s64 = ctx.r8.s16;
	// subf r8,r10,r5
	ctx.r8.s64 = ctx.r5.s64 - ctx.r10.s64;
	// addi r7,r11,-16
	ctx.r7.s64 = ctx.r11.s64 + -16;
	// extsh r11,r8
	ctx.r11.s64 = ctx.r8.s16;
	// rlwinm r10,r7,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// clrlwi r5,r9,23
	ctx.r5.u64 = ctx.r9.u32 & 0x1FF;
	// addi r9,r11,-16
	ctx.r9.s64 = ctx.r11.s64 + -16;
	// stw r5,12368(r22)
	PPC_STORE_U32(ctx.r22.u32 + 12368, ctx.r5.u32);
	// add r11,r10,r24
	ctx.r11.u64 = ctx.r10.u64 + ctx.r24.u64;
	// rlwinm r10,r9,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// stw r11,12364(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12364, ctx.r11.u32);
	// add r11,r10,r23
	ctx.r11.u64 = ctx.r10.u64 + ctx.r23.u64;
	// stw r11,12372(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12372, ctx.r11.u32);
	// bl 0x880f83f8
	ctx.lr = 0x880A3490;
	sub_880F83F8(ctx, base);
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// bne 0x880a33fc
	if (!ctx.cr0.eq) goto loc_880A33FC;
	// lis r10,-30667
	ctx.r10.s64 = -2009792512;
	// li r11,2
	ctx.r11.s64 = 2;
	// lis r9,-30667
	ctx.r9.s64 = -2009792512;
	// addis r27,r23,-8
	ctx.r27.s64 = ctx.r23.s64 + -524288;
	// li r21,8
	ctx.r21.s64 = 8;
	// stw r11,12380(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12380, ctx.r11.u32);
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// lis r23,-30667
	ctx.r23.s64 = -2009792512;
	// stw r4,12376(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12376, ctx.r4.u32);
	// addi r22,r11,9552
	ctx.r22.s64 = ctx.r11.s64 + 9552;
loc_880A34C0:
	// mullw r11,r28,r30
	ctx.r11.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r30.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// li r3,2
	ctx.r3.s64 = 2;
	// stw r11,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r11.u32);
	// mullw r11,r11,r30
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// lhz r8,4200(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// mulhwu r7,r8,r29
	ctx.r7.u64 = (uint64_t(ctx.r8.u32) * uint64_t(ctx.r29.u32)) >> 32;
	// stw r11,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r11.u32);
	// mullw r9,r11,r30
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// lhz r6,4200(r31)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// rlwinm r11,r7,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 29) & 0x1FFFFFFF;
	// addi r28,r9,12345
	ctx.r28.s64 = ctx.r9.s64 + 12345;
	// rlwinm r9,r11,5,0,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xFFFFFFE0;
	// stw r28,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r28.u32);
	// add r5,r9,r11
	ctx.r5.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lhz r9,4200(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// mulhwu r11,r6,r29
	ctx.r11.u64 = (uint64_t(ctx.r6.u32) * uint64_t(ctx.r29.u32)) >> 32;
	// rlwinm r10,r11,29,3,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// subf r8,r5,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r5.s64;
	// rlwinm r11,r10,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// extsh r11,r8
	ctx.r11.s64 = ctx.r8.s16;
	// subf r7,r5,r6
	ctx.r7.s64 = ctx.r6.s64 - ctx.r5.s64;
	// addi r8,r11,-16
	ctx.r8.s64 = ctx.r11.s64 + -16;
	// extsh r11,r7
	ctx.r11.s64 = ctx.r7.s16;
	// rlwinm r10,r8,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// addi r6,r11,-16
	ctx.r6.s64 = ctx.r11.s64 + -16;
	// add r11,r10,r24
	ctx.r11.u64 = ctx.r10.u64 + ctx.r24.u64;
	// rlwinm r10,r6,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// stw r11,12364(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12364, ctx.r11.u32);
	// clrlwi r5,r9,28
	ctx.r5.u64 = ctx.r9.u32 & 0xF;
	// add r11,r10,r27
	ctx.r11.u64 = ctx.r10.u64 + ctx.r27.u64;
	// stw r11,12372(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12372, ctx.r11.u32);
	// bl 0x880f25b8
	ctx.lr = 0x880A354C;
	sub_880F25B8(ctx, base);
	// mullw r11,r28,r30
	ctx.r11.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r30.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r11,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r11.u32);
	// mullw r11,r11,r30
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// lhz r5,4200(r31)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// addi r10,r11,12345
	ctx.r10.s64 = ctx.r11.s64 + 12345;
	// mulhwu r11,r5,r29
	ctx.r11.u64 = (uint64_t(ctx.r5.u32) * uint64_t(ctx.r29.u32)) >> 32;
	// rlwinm r11,r11,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// stw r10,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r10.u32);
	// lhz r9,4200(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// clrlwi r8,r9,27
	ctx.r8.u64 = ctx.r9.u32 & 0x1F;
	// rlwinm r9,r11,5,0,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xFFFFFFE0;
	// subfic r7,r8,136
	ctx.xer.ca = ctx.r8.u32 <= 136;
	ctx.r7.s64 = 136 - ctx.r8.s64;
	// add r6,r9,r11
	ctx.r6.u64 = ctx.r9.u64 + ctx.r11.u64;
	// clrlwi r9,r7,23
	ctx.r9.u64 = ctx.r7.u32 & 0x1FF;
	// subf r5,r6,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r6.s64;
	// extsh r11,r5
	ctx.r11.s64 = ctx.r5.s16;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// beq cr6,0x880a35e0
	if (ctx.cr6.eq) goto loc_880A35E0;
	// stw r9,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r9.u32);
	// addic. r8,r3,28
	ctx.xer.ca = ctx.r3.u32 > 4294967267;
	ctx.r8.s64 = ctx.r3.s64 + 28;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r11.u32);
	// addi r7,r3,24
	ctx.r7.s64 = ctx.r3.s64 + 24;
	// clrlwi r9,r9,23
	ctx.r9.u64 = ctx.r9.u32 & 0x1FF;
	// beq 0x880a35c8
	if (ctx.cr0.eq) goto loc_880A35C8;
	// addi r6,r9,128
	ctx.r6.s64 = ctx.r9.s64 + 128;
	// rlwinm r5,r6,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// lwzx r3,r5,r22
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r22.u32);
	// mullw r6,r3,r11
	ctx.r6.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r11.s32);
	// stw r6,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r6.u32);
loc_880A35C8:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x880a35e0
	if (ctx.cr6.eq) goto loc_880A35E0;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r22
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r22.u32);
	// mullw r6,r8,r11
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r11.s32);
	// stw r6,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r6.u32);
loc_880A35E0:
	// mullw r11,r10,r30
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r30.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// li r3,2
	ctx.r3.s64 = 2;
	// stw r11,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r11.u32);
	// mullw r11,r11,r30
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// mullw r9,r11,r30
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// lhz r8,4200(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// stw r11,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r11.u32);
	// mulhwu r6,r8,r29
	ctx.r6.u64 = (uint64_t(ctx.r8.u32) * uint64_t(ctx.r29.u32)) >> 32;
	// rlwinm r10,r6,29,3,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 29) & 0x1FFFFFFF;
	// addi r28,r9,12345
	ctx.r28.s64 = ctx.r9.s64 + 12345;
	// rlwinm r9,r10,5,0,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// lhz r7,4200(r31)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r28,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r28.u32);
	// mulhwu r5,r7,r29
	ctx.r5.u64 = (uint64_t(ctx.r7.u32) * uint64_t(ctx.r29.u32)) >> 32;
	// rlwinm r11,r5,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 29) & 0x1FFFFFFF;
	// subf r8,r10,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r10.s64;
	// rlwinm r9,r11,5,0,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r6,r9,r11
	ctx.r6.u64 = ctx.r9.u64 + ctx.r11.u64;
	// extsh r11,r8
	ctx.r11.s64 = ctx.r8.s16;
	// subf r10,r6,r7
	ctx.r10.s64 = ctx.r7.s64 - ctx.r6.s64;
	// addi r8,r11,-16
	ctx.r8.s64 = ctx.r11.s64 + -16;
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// lhz r10,4200(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// rlwinm r11,r8,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// addi r7,r9,-16
	ctx.r7.s64 = ctx.r9.s64 + -16;
	// add r11,r11,r24
	ctx.r11.u64 = ctx.r11.u64 + ctx.r24.u64;
	// rlwinm r9,r7,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// stw r11,12364(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12364, ctx.r11.u32);
	// clrlwi r5,r10,28
	ctx.r5.u64 = ctx.r10.u32 & 0xF;
	// add r11,r9,r27
	ctx.r11.u64 = ctx.r9.u64 + ctx.r27.u64;
	// stw r5,12384(r23)
	PPC_STORE_U32(ctx.r23.u32 + 12384, ctx.r5.u32);
	// stw r11,12372(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12372, ctx.r11.u32);
	// bl 0x880f25b8
	ctx.lr = 0x880A3670;
	sub_880F25B8(ctx, base);
	// mullw r11,r28,r30
	ctx.r11.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r30.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// mullw r10,r11,r30
	ctx.r10.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// stw r11,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r11.u32);
	// lhz r6,4200(r31)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// addi r28,r10,12345
	ctx.r28.s64 = ctx.r10.s64 + 12345;
	// mulhwu r5,r6,r29
	ctx.r5.u64 = (uint64_t(ctx.r6.u32) * uint64_t(ctx.r29.u32)) >> 32;
	// stw r28,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r28.u32);
	// rlwinm r11,r5,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 29) & 0x1FFFFFFF;
	// rlwinm r10,r11,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r8,r10,r6
	ctx.r8.s64 = ctx.r6.s64 - ctx.r10.s64;
	// lhz r11,4200(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// clrlwi r9,r11,27
	ctx.r9.u64 = ctx.r11.u32 & 0x1F;
	// subfic r7,r9,-104
	ctx.xer.ca = ctx.r9.u32 <= 4294967192;
	ctx.r7.s64 = -104 - ctx.r9.s64;
	// extsh r11,r8
	ctx.r11.s64 = ctx.r8.s16;
	// clrlwi r10,r7,23
	ctx.r10.u64 = ctx.r7.u32 & 0x1FF;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// beq cr6,0x880a3704
	if (ctx.cr6.eq) goto loc_880A3704;
	// stw r10,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r10.u32);
	// addic. r9,r3,28
	ctx.xer.ca = ctx.r3.u32 > 4294967267;
	ctx.r9.s64 = ctx.r3.s64 + 28;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r11.u32);
	// addi r8,r3,24
	ctx.r8.s64 = ctx.r3.s64 + 24;
	// clrlwi r10,r10,23
	ctx.r10.u64 = ctx.r10.u32 & 0x1FF;
	// beq 0x880a36ec
	if (ctx.cr0.eq) goto loc_880A36EC;
	// addi r7,r10,128
	ctx.r7.s64 = ctx.r10.s64 + 128;
	// rlwinm r6,r7,2,21,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x7FC;
	// lwzx r5,r6,r22
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r22.u32);
	// mullw r3,r5,r11
	ctx.r3.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r11.s32);
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
loc_880A36EC:
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x880a3704
	if (ctx.cr6.eq) goto loc_880A3704;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r22
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r22.u32);
	// mullw r7,r9,r11
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// stw r7,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
loc_880A3704:
	// addic. r21,r21,-1
	ctx.xer.ca = ctx.r21.u32 > 0;
	ctx.r21.s64 = ctx.r21.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// bne 0x880a34c0
	if (!ctx.cr0.eq) goto loc_880A34C0;
loc_880A370C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8807118c
	__restgprlr_21(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A3718"))) PPC_WEAK_FUNC(sub_880A3718);
PPC_FUNC_IMPL(__imp__sub_880A3718) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x880A3720;
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
	// li r5,68
	ctx.r5.s64 = 68;
	// bl 0x88096bc8
	ctx.lr = 0x880A3744;
	sub_88096BC8(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r31,404
	ctx.r7.s64 = ctx.r31.s64 + 404;
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
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
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
	ctx.lr = 0x880A3788;
	sub_880E32D0(ctx, base);
	// lis r9,-30710
	ctx.r9.s64 = -2012610560;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r5,r9,10072
	ctx.r5.s64 = ctx.r9.s64 + 10072;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88096c60
	ctx.lr = 0x880A379C;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A37A8"))) PPC_WEAK_FUNC(sub_880A37A8);
PPC_FUNC_IMPL(__imp__sub_880A37A8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x880A37B0;
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
	// li r5,68
	ctx.r5.s64 = 68;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880A37D8;
	sub_88096BC8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r7,r31,404
	ctx.r7.s64 = ctx.r31.s64 + 404;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r6,33
	ctx.r6.s64 = 33;
	// lwz r9,184(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 184);
	// li r5,60
	ctx.r5.s64 = 60;
	// lwz r10,168(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 168);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r10,6
	ctx.r10.s64 = ctx.r10.s64 + 6;
	// li r4,94
	ctx.r4.s64 = 94;
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// li r3,5
	ctx.r3.s64 = 5;
	// lwz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// stw r9,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r9.u32);
	// stw r11,60(r8)
	PPC_STORE_U32(ctx.r8.u32 + 60, ctx.r11.u32);
	// stw r11,64(r8)
	PPC_STORE_U32(ctx.r8.u32 + 64, ctx.r11.u32);
	// stw r11,28(r8)
	PPC_STORE_U32(ctx.r8.u32 + 28, ctx.r11.u32);
	// lwz r7,0(r27)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// stw r7,56(r8)
	PPC_STORE_U32(ctx.r8.u32 + 56, ctx.r7.u32);
	// bl 0x880e32d0
	ctx.lr = 0x880A3830;
	sub_880E32D0(ctx, base);
	// lis r6,-30710
	ctx.r6.s64 = -2012610560;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r5,r6,10784
	ctx.r5.s64 = ctx.r6.s64 + 10784;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88096c60
	ctx.lr = 0x880A3844;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A3850"))) PPC_WEAK_FUNC(sub_880A3850);
PPC_FUNC_IMPL(__imp__sub_880A3850) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x880A3858;
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
	// li r5,68
	ctx.r5.s64 = 68;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880A3880;
	sub_88096BC8(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r7,r31,404
	ctx.r7.s64 = ctx.r31.s64 + 404;
	// li r3,1
	ctx.r3.s64 = 1;
	// li r6,35
	ctx.r6.s64 = 35;
	// stw r3,28(r8)
	PPC_STORE_U32(ctx.r8.u32 + 28, ctx.r3.u32);
	// li r5,50
	ctx.r5.s64 = 50;
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// li r4,95
	ctx.r4.s64 = 95;
	// stw r7,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r7.u32);
	// li r3,5
	ctx.r3.s64 = 5;
	// lwz r9,184(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 184);
	// lwz r10,168(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 168);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r10,6
	ctx.r10.s64 = ctx.r10.s64 + 6;
	// stw r11,60(r8)
	PPC_STORE_U32(ctx.r8.u32 + 60, ctx.r11.u32);
	// stw r11,64(r8)
	PPC_STORE_U32(ctx.r8.u32 + 64, ctx.r11.u32);
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// stw r9,56(r8)
	PPC_STORE_U32(ctx.r8.u32 + 56, ctx.r9.u32);
	// bl 0x880e32d0
	ctx.lr = 0x880A38D4;
	sub_880E32D0(ctx, base);
	// lis r8,-30710
	ctx.r8.s64 = -2012610560;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r5,r8,11616
	ctx.r5.s64 = ctx.r8.s64 + 11616;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88096c60
	ctx.lr = 0x880A38E8;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A38F4"))) PPC_WEAK_FUNC(sub_880A38F4);
PPC_FUNC_IMPL(__imp__sub_880A38F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A38F8"))) PPC_WEAK_FUNC(sub_880A38F8);
PPC_FUNC_IMPL(__imp__sub_880A38F8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x880A3900;
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
	// li r5,68
	ctx.r5.s64 = 68;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880A3928;
	sub_88096BC8(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r7,r31,404
	ctx.r7.s64 = ctx.r31.s64 + 404;
	// li r3,-1
	ctx.r3.s64 = -1;
	// li r6,35
	ctx.r6.s64 = 35;
	// stw r3,28(r8)
	PPC_STORE_U32(ctx.r8.u32 + 28, ctx.r3.u32);
	// li r5,50
	ctx.r5.s64 = 50;
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// li r4,95
	ctx.r4.s64 = 95;
	// stw r7,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r7.u32);
	// li r3,5
	ctx.r3.s64 = 5;
	// lwz r9,184(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 184);
	// lwz r10,168(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 168);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r10,6
	ctx.r10.s64 = ctx.r10.s64 + 6;
	// stw r11,60(r8)
	PPC_STORE_U32(ctx.r8.u32 + 60, ctx.r11.u32);
	// stw r11,64(r8)
	PPC_STORE_U32(ctx.r8.u32 + 64, ctx.r11.u32);
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// stw r9,56(r8)
	PPC_STORE_U32(ctx.r8.u32 + 56, ctx.r9.u32);
	// bl 0x880e32d0
	ctx.lr = 0x880A397C;
	sub_880E32D0(ctx, base);
	// lis r8,-30710
	ctx.r8.s64 = -2012610560;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r5,r8,11616
	ctx.r5.s64 = ctx.r8.s64 + 11616;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88096c60
	ctx.lr = 0x880A3990;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A399C"))) PPC_WEAK_FUNC(sub_880A399C);
PPC_FUNC_IMPL(__imp__sub_880A399C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A39A0"))) PPC_WEAK_FUNC(sub_880A39A0);
PPC_FUNC_IMPL(__imp__sub_880A39A0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880A39A8;
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
	// li r5,28
	ctx.r5.s64 = 28;
	// bl 0x88096bc8
	ctx.lr = 0x880A39C8;
	sub_88096BC8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,255
	ctx.r10.s64 = 255;
	// li r9,5
	ctx.r9.s64 = 5;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// lis r8,-30710
	ctx.r8.s64 = -2012610560;
	// stw r10,72(r29)
	PPC_STORE_U32(ctx.r29.u32 + 72, ctx.r10.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r9,472(r29)
	PPC_STORE_U32(ctx.r29.u32 + 472, ctx.r9.u32);
	// addi r5,r8,12992
	ctx.r5.s64 = ctx.r8.s64 + 12992;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096c60
	ctx.lr = 0x880A39F8;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A3A04"))) PPC_WEAK_FUNC(sub_880A3A04);
PPC_FUNC_IMPL(__imp__sub_880A3A04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A3A08"))) PPC_WEAK_FUNC(sub_880A3A08);
PPC_FUNC_IMPL(__imp__sub_880A3A08) {
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
	// addi r10,r11,1468
	ctx.r10.s64 = ctx.r11.s64 + 1468;
	// addi r9,r11,1472
	ctx.r9.s64 = ctx.r11.s64 + 1472;
	// stw r6,1472(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1472, ctx.r6.u32);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// lis r5,-30710
	ctx.r5.s64 = -2012610560;
	// stw r7,1468(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1468, ctx.r7.u32);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r5,3632
	ctx.r5.s64 = ctx.r5.s64 + 3632;
	// li r4,30
	ctx.r4.s64 = 30;
	// bl 0x88096460
	ctx.lr = 0x880A3A64;
	sub_88096460(ctx, base);
	// lis r4,-30641
	ctx.r4.s64 = -2008088576;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r10,r4,-18804
	ctx.r10.s64 = ctx.r4.s64 + -18804;
	// lis r9,-30710
	ctx.r9.s64 = -2012610560;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r9,9752
	ctx.r5.s64 = ctx.r9.s64 + 9752;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// bl 0x88096c60
	ctx.lr = 0x880A3A88;
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

__attribute__((alias("__imp__sub_880A3AA4"))) PPC_WEAK_FUNC(sub_880A3AA4);
PPC_FUNC_IMPL(__imp__sub_880A3AA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A3AA8"))) PPC_WEAK_FUNC(sub_880A3AA8);
PPC_FUNC_IMPL(__imp__sub_880A3AA8) {
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

__attribute__((alias("__imp__sub_880A3AC8"))) PPC_WEAK_FUNC(sub_880A3AC8);
PPC_FUNC_IMPL(__imp__sub_880A3AC8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r11,9736(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 9736);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r4,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880A3AE0"))) PPC_WEAK_FUNC(sub_880A3AE0);
PPC_FUNC_IMPL(__imp__sub_880A3AE0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// li r10,2
	ctx.r10.s64 = 2;
	// lwz r9,9736(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 9736);
	// lwz r11,28(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880a3b10
	if (ctx.cr6.eq) goto loc_880A3B10;
loc_880A3AF8:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880a3b10
	if (ctx.cr6.eq) goto loc_880A3B10;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880a3af8
	if (!ctx.cr6.eq) goto loc_880A3AF8;
loc_880A3B10:
	// stw r4,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880A3B18"))) PPC_WEAK_FUNC(sub_880A3B18);
PPC_FUNC_IMPL(__imp__sub_880A3B18) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// li r10,2
	ctx.r10.s64 = 2;
	// lwz r9,9736(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 9736);
	// lwz r11,28(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880a3b48
	if (ctx.cr6.eq) goto loc_880A3B48;
loc_880A3B30:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880a3b48
	if (ctx.cr6.eq) goto loc_880A3B48;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880a3b30
	if (!ctx.cr6.eq) goto loc_880A3B30;
loc_880A3B48:
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880A3B54"))) PPC_WEAK_FUNC(sub_880A3B54);
PPC_FUNC_IMPL(__imp__sub_880A3B54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A3B58"))) PPC_WEAK_FUNC(sub_880A3B58);
PPC_FUNC_IMPL(__imp__sub_880A3B58) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r8,9736(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 9736);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x880a3ba0
	if (ctx.cr6.eq) goto loc_880A3BA0;
	// lis r11,-30658
	ctx.r11.s64 = -2009202688;
	// addi r11,r11,576
	ctx.r11.s64 = ctx.r11.s64 + 576;
	// lwz r10,-104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -104);
	// cmpwi cr6,r10,3000
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3000, ctx.xer);
	// bge cr6,0x880a3ba0
	if (!ctx.cr6.lt) goto loc_880A3BA0;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r6,-30597
	ctx.r6.s64 = -2005204992;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r9,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r9.u32);
	// stw r10,-104(r11)
	PPC_STORE_U32(ctx.r11.u32 + -104, ctx.r10.u32);
	// stw r9,-12000(r6)
	PPC_STORE_U32(ctx.r6.u32 + -12000, ctx.r9.u32);
	// stwx r8,r7,r11
	PPC_STORE_U32(ctx.r7.u32 + ctx.r11.u32, ctx.r8.u32);
	// blr 
	return;
loc_880A3BA0:
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,-12000(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12000, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880A3BB0"))) PPC_WEAK_FUNC(sub_880A3BB0);
PPC_FUNC_IMPL(__imp__sub_880A3BB0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// bne cr6,0x880a3c00
	if (!ctx.cr6.eq) goto loc_880A3C00;
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
loc_880A3C00:
	// lwz r5,4(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne cr6,0x880a3c44
	if (!ctx.cr6.eq) goto loc_880A3C44;
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
loc_880A3C44:
	// addi r11,r11,-11984
	ctx.r11.s64 = ctx.r11.s64 + -11984;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r10,84(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x880a3c68
	if (!ctx.cr6.eq) goto loc_880A3C68;
	// lwz r6,16(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// li r3,96
	ctx.r3.s64 = 96;
	// lwz r4,8(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// b 0x8815d688
	sub_8815D688(ctx, base);
	return;
loc_880A3C68:
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
	// li r6,96
	ctx.r6.s64 = 96;
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

__attribute__((alias("__imp__sub_880A3CA0"))) PPC_WEAK_FUNC(sub_880A3CA0);
PPC_FUNC_IMPL(__imp__sub_880A3CA0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880A3CA4"))) PPC_WEAK_FUNC(sub_880A3CA4);
PPC_FUNC_IMPL(__imp__sub_880A3CA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A3CA8"))) PPC_WEAK_FUNC(sub_880A3CA8);
PPC_FUNC_IMPL(__imp__sub_880A3CA8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x880A3CB0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// li r29,1
	ctx.r29.s64 = 1;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// stw r29,9900(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9900, ctx.r29.u32);
	// beq cr6,0x880a3edc
	if (ctx.cr6.eq) goto loc_880A3EDC;
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x880a3de8
	if (ctx.cr6.eq) goto loc_880A3DE8;
	// cmpwi cr6,r3,3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 3, ctx.xer);
	// bne cr6,0x880a3f8c
	if (!ctx.cr6.eq) goto loc_880A3F8C;
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lis r9,-30683
	ctx.r9.s64 = -2010841088;
	// stw r29,9892(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9892, ctx.r29.u32);
	// addi r30,r11,-16616
	ctx.r30.s64 = ctx.r11.s64 + -16616;
	// stw r29,9984(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9984, ctx.r29.u32);
	// addi r8,r9,28176
	ctx.r8.s64 = ctx.r9.s64 + 28176;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r28,0
	ctx.r28.s64 = 0;
	// lwz r11,4632(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4632);
	// lwzx r5,r7,r8
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// lwz r6,84(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// cmpwi cr6,r6,1
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 1, ctx.xer);
	// beq cr6,0x880a3d48
	if (ctx.cr6.eq) goto loc_880A3D48;
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
	// blt cr6,0x880a3d44
	if (ctx.cr6.lt) goto loc_880A3D44;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// beq cr6,0x880a3d40
	if (ctx.cr6.eq) goto loc_880A3D40;
	// lwz r11,164(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 164);
loc_880A3D40:
	// mulli r11,r11,100
	ctx.r11.s64 = ctx.r11.s64 * 100;
loc_880A3D44:
	// add r5,r11,r5
	ctx.r5.u64 = ctx.r11.u64 + ctx.r5.u64;
loc_880A3D48:
	// bl 0x88095178
	ctx.lr = 0x880A3D4C;
	sub_88095178(ctx, base);
	// stw r29,9888(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9888, ctx.r29.u32);
	// stw r28,9836(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9836, ctx.r28.u32);
	// stw r29,9852(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9852, ctx.r29.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,2304(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2304);
	// lwz r11,9736(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 9736);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880a3d70
	if (ctx.cr6.eq) goto loc_880A3D70;
	// stw r28,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r28.u32);
loc_880A3D70:
	// addi r3,r31,10028
	ctx.r3.s64 = ctx.r31.s64 + 10028;
	// bl 0x880a3bb0
	ctx.lr = 0x880A3D78;
	sub_880A3BB0(ctx, base);
	// bl 0x880971a8
	ctx.lr = 0x880A3D7C;
	sub_880971A8(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096e80
	ctx.lr = 0x880A3D84;
	sub_88096E80(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x880967b8
	ctx.lr = 0x880A3D8C;
	sub_880967B8(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096ac0
	ctx.lr = 0x880A3D94;
	sub_88096AC0(ctx, base);
	// lis r11,-30689
	ctx.r11.s64 = -2011234304;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r4,r11,6504
	ctx.r4.s64 = ctx.r11.s64 + 6504;
	// bl 0x880969a8
	ctx.lr = 0x880A3DA8;
	sub_880969A8(ctx, base);
	// lwz r11,5876(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5876);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880a3f8c
	if (ctx.cr6.eq) goto loc_880A3F8C;
	// lwz r11,5868(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5868);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// ble cr6,0x880a3f8c
	if (!ctx.cr6.gt) goto loc_880A3F8C;
	// lwz r11,64(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 64);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880a3ddc
	if (!ctx.cr6.eq) goto loc_880A3DDC;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x8808d1b8
	ctx.lr = 0x880A3DD4;
	sub_8808D1B8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_880A3DDC:
	// stw r29,68(r30)
	PPC_STORE_U32(ctx.r30.u32 + 68, ctx.r29.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_880A3DE8:
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r29,9892(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9892, ctx.r29.u32);
	// stw r29,9980(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9980, ctx.r29.u32);
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// stw r10,9896(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9896, ctx.r10.u32);
	// lis r8,-30683
	ctx.r8.s64 = -2010841088;
	// addi r30,r11,-16616
	ctx.r30.s64 = ctx.r11.s64 + -16616;
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// addi r11,r8,28176
	ctx.r11.s64 = ctx.r8.s64 + 28176;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r11,-16
	ctx.r6.s64 = ctx.r11.s64 + -16;
	// lwz r11,4632(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4632);
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// lwzx r5,r7,r6
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// beq cr6,0x880a3e5c
	if (ctx.cr6.eq) goto loc_880A3E5C;
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
	// blt cr6,0x880a3e58
	if (ctx.cr6.lt) goto loc_880A3E58;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// li r11,0
	ctx.r11.s64 = 0;
	// beq cr6,0x880a3e54
	if (ctx.cr6.eq) goto loc_880A3E54;
	// lwz r11,164(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 164);
loc_880A3E54:
	// mulli r11,r11,100
	ctx.r11.s64 = ctx.r11.s64 * 100;
loc_880A3E58:
	// add r5,r11,r5
	ctx.r5.u64 = ctx.r11.u64 + ctx.r5.u64;
loc_880A3E5C:
	// bl 0x88095178
	ctx.lr = 0x880A3E60;
	sub_88095178(ctx, base);
	// lwz r11,9944(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9944);
	// addi r3,r31,10008
	ctx.r3.s64 = ctx.r31.s64 + 10008;
	// stw r11,9836(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9836, ctx.r11.u32);
	// bl 0x880a3bb0
	ctx.lr = 0x880A3E70;
	sub_880A3BB0(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096e80
	ctx.lr = 0x880A3E78;
	sub_88096E80(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x880967b8
	ctx.lr = 0x880A3E80;
	sub_880967B8(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096ac0
	ctx.lr = 0x880A3E88;
	sub_88096AC0(ctx, base);
	// lis r10,-30689
	ctx.r10.s64 = -2011234304;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r4,r10,10088
	ctx.r4.s64 = ctx.r10.s64 + 10088;
	// bl 0x880969a8
	ctx.lr = 0x880A3E9C;
	sub_880969A8(ctx, base);
	// lwz r11,5876(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5876);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880a3f8c
	if (ctx.cr6.eq) goto loc_880A3F8C;
	// lwz r11,5868(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5868);
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// ble cr6,0x880a3f8c
	if (!ctx.cr6.gt) goto loc_880A3F8C;
	// lwz r11,56(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 56);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880a3ed0
	if (!ctx.cr6.eq) goto loc_880A3ED0;
	// li r3,7
	ctx.r3.s64 = 7;
	// bl 0x8808d1b8
	ctx.lr = 0x880A3EC8;
	sub_8808D1B8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_880A3ED0:
	// stw r29,60(r30)
	PPC_STORE_U32(ctx.r30.u32 + 60, ctx.r29.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_880A3EDC:
	// stw r29,9892(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9892, ctx.r29.u32);
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// stw r29,9896(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9896, ctx.r29.u32);
	// lis r10,-30683
	ctx.r10.s64 = -2010841088;
	// stw r29,9976(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9976, ctx.r29.u32);
	// addi r9,r11,-16616
	ctx.r9.s64 = ctx.r11.s64 + -16616;
	// addi r11,r10,28176
	ctx.r11.s64 = ctx.r10.s64 + 28176;
	// lwz r8,28(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r6,r11,-32
	ctx.r6.s64 = ctx.r11.s64 + -32;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,4632(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4632);
	// lwz r5,84(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// cmpwi cr6,r5,1
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 1, ctx.xer);
	// lwzx r5,r7,r6
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// beq cr6,0x880a3f4c
	if (ctx.cr6.eq) goto loc_880A3F4C;
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
	// blt cr6,0x880a3f48
	if (ctx.cr6.lt) goto loc_880A3F48;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// li r11,0
	ctx.r11.s64 = 0;
	// beq cr6,0x880a3f44
	if (ctx.cr6.eq) goto loc_880A3F44;
	// lwz r11,164(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 164);
loc_880A3F44:
	// mulli r11,r11,100
	ctx.r11.s64 = ctx.r11.s64 * 100;
loc_880A3F48:
	// add r5,r11,r5
	ctx.r5.u64 = ctx.r11.u64 + ctx.r5.u64;
loc_880A3F4C:
	// bl 0x88095178
	ctx.lr = 0x880A3F50;
	sub_88095178(ctx, base);
	// lwz r11,9940(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9940);
	// addi r3,r31,9988
	ctx.r3.s64 = ctx.r31.s64 + 9988;
	// stw r11,9836(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9836, ctx.r11.u32);
	// bl 0x880a3bb0
	ctx.lr = 0x880A3F60;
	sub_880A3BB0(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096e80
	ctx.lr = 0x880A3F68;
	sub_88096E80(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x880967b8
	ctx.lr = 0x880A3F70;
	sub_880967B8(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096ac0
	ctx.lr = 0x880A3F78;
	sub_88096AC0(ctx, base);
	// lis r10,-30689
	ctx.r10.s64 = -2011234304;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r4,r10,10208
	ctx.r4.s64 = ctx.r10.s64 + 10208;
	// bl 0x880969a8
	ctx.lr = 0x880A3F8C;
	sub_880969A8(ctx, base);
loc_880A3F8C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A3F94"))) PPC_WEAK_FUNC(sub_880A3F94);
PPC_FUNC_IMPL(__imp__sub_880A3F94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A3F98"))) PPC_WEAK_FUNC(sub_880A3F98);
PPC_FUNC_IMPL(__imp__sub_880A3F98) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880A3FA0;
	__savegprlr_29(ctx, base);
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
	// bne cr6,0x880a4188
	if (!ctx.cr6.eq) goto loc_880A4188;
	// lwz r10,9896(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 9896);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x880a4040
	if (!ctx.cr6.eq) goto loc_880A4040;
	// lwz r11,9976(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 9976);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a4040
	if (!ctx.cr6.eq) goto loc_880A4040;
	// lwz r11,9964(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 9964);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,9964(r3)
	PPC_STORE_U32(ctx.r3.u32 + 9964, ctx.r11.u32);
	// bge 0x880a4040
	if (!ctx.cr0.lt) goto loc_880A4040;
	// lwz r11,9940(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 9940);
	// li r30,1
	ctx.r30.s64 = 1;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r30,9900(r3)
	PPC_STORE_U32(ctx.r3.u32 + 9900, ctx.r30.u32);
	// addi r3,r3,9988
	ctx.r3.s64 = ctx.r3.s64 + 9988;
	// stw r30,9896(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9896, ctx.r30.u32);
	// stw r30,9892(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9892, ctx.r30.u32);
	// stw r30,9976(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9976, ctx.r30.u32);
	// stw r10,9988(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9988, ctx.r10.u32);
	// stw r11,9836(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9836, ctx.r11.u32);
	// bl 0x880a3bb0
	ctx.lr = 0x880A400C;
	sub_880A3BB0(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096e80
	ctx.lr = 0x880A4014;
	sub_88096E80(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x880967b8
	ctx.lr = 0x880A401C;
	sub_880967B8(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096ac0
	ctx.lr = 0x880A4024;
	sub_88096AC0(ctx, base);
	// lis r9,-30689
	ctx.r9.s64 = -2011234304;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r4,r9,10208
	ctx.r4.s64 = ctx.r9.s64 + 10208;
	// bl 0x880969a8
	ctx.lr = 0x880A4038;
	sub_880969A8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_880A4040:
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x880a40c4
	if (!ctx.cr6.eq) goto loc_880A40C4;
	// lwz r11,9980(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9980);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a40c4
	if (!ctx.cr6.eq) goto loc_880A40C4;
	// lwz r11,9968(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9968);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,9968(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9968, ctx.r11.u32);
	// bge 0x880a40c4
	if (!ctx.cr0.lt) goto loc_880A40C4;
	// lwz r10,9944(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9944);
	// li r30,1
	ctx.r30.s64 = 1;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r30,9900(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9900, ctx.r30.u32);
	// addi r3,r31,10008
	ctx.r3.s64 = ctx.r31.s64 + 10008;
	// stw r11,9896(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9896, ctx.r11.u32);
	// stw r30,9892(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9892, ctx.r30.u32);
	// stw r30,9980(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9980, ctx.r30.u32);
	// stw r11,10008(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10008, ctx.r11.u32);
	// stw r10,9836(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9836, ctx.r10.u32);
	// bl 0x880a3bb0
	ctx.lr = 0x880A4090;
	sub_880A3BB0(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096e80
	ctx.lr = 0x880A4098;
	sub_88096E80(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x880967b8
	ctx.lr = 0x880A40A0;
	sub_880967B8(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096ac0
	ctx.lr = 0x880A40A8;
	sub_88096AC0(ctx, base);
	// lis r9,-30689
	ctx.r9.s64 = -2011234304;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r4,r9,10088
	ctx.r4.s64 = ctx.r9.s64 + 10088;
	// bl 0x880969a8
	ctx.lr = 0x880A40BC;
	sub_880969A8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_880A40C4:
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// bne cr6,0x880a4188
	if (!ctx.cr6.eq) goto loc_880A4188;
	// lwz r11,9984(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9984);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a4188
	if (!ctx.cr6.eq) goto loc_880A4188;
	// lwz r11,9972(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9972);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,9972(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9972, ctx.r11.u32);
	// bge 0x880a4188
	if (!ctx.cr0.lt) goto loc_880A4188;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r10,r11,26432
	ctx.r10.s64 = ctx.r11.s64 + 26432;
	// lwz r11,324(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 324);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880a410c
	if (!ctx.cr6.eq) goto loc_880A410C;
	// li r11,300
	ctx.r11.s64 = 300;
	// stw r11,9972(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9972, ctx.r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_880A410C:
	// li r30,1
	ctx.r30.s64 = 1;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r30,9900(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9900, ctx.r30.u32);
	// addi r29,r31,10028
	ctx.r29.s64 = ctx.r31.s64 + 10028;
	// stw r30,9892(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9892, ctx.r30.u32);
	// stw r30,9984(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9984, ctx.r30.u32);
	// stw r11,10028(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10028, ctx.r11.u32);
	// bl 0x880971a8
	ctx.lr = 0x880A412C;
	sub_880971A8(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r30,9888(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9888, ctx.r30.u32);
	// stw r10,9836(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9836, ctx.r10.u32);
	// stw r30,9852(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9852, ctx.r30.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r8,2304(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2304);
	// lwz r11,9736(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 9736);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880a4154
	if (ctx.cr6.eq) goto loc_880A4154;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
loc_880A4154:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x880a3bb0
	ctx.lr = 0x880A415C;
	sub_880A3BB0(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096e80
	ctx.lr = 0x880A4164;
	sub_88096E80(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x880967b8
	ctx.lr = 0x880A416C;
	sub_880967B8(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x88096ac0
	ctx.lr = 0x880A4174;
	sub_88096AC0(ctx, base);
	// lis r11,-30689
	ctx.r11.s64 = -2011234304;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r4,r11,6504
	ctx.r4.s64 = ctx.r11.s64 + 6504;
	// bl 0x880969a8
	ctx.lr = 0x880A4188;
	sub_880969A8(ctx, base);
loc_880A4188:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A4190"))) PPC_WEAK_FUNC(sub_880A4190);
PPC_FUNC_IMPL(__imp__sub_880A4190) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880A4198;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r11,-30642
	ctx.r11.s64 = -2008154112;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r30,r11,-32760
	ctx.r30.s64 = ctx.r11.s64 + -32760;
	// lwz r11,9888(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9888);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a44dc
	if (!ctx.cr6.eq) goto loc_880A44DC;
	// lis r10,128
	ctx.r10.s64 = 8388608;
	// lwz r11,9736(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9736);
	// addi r9,r31,9736
	ctx.r9.s64 = ctx.r31.s64 + 9736;
	// ori r8,r10,32896
	ctx.r8.u64 = ctx.r10.u64 | 32896;
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// stw r8,9856(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9856, ctx.r8.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880a41fc
	if (ctx.cr6.eq) goto loc_880A41FC;
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880a41fc
	if (ctx.cr6.eq) goto loc_880A41FC;
loc_880A41E4:
	// lwz r8,20(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// stw r29,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r29.u32);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// or r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 | ctx.r8.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880a41e4
	if (!ctx.cr6.eq) goto loc_880A41E4;
loc_880A41FC:
	// clrlwi r11,r10,20
	ctx.r11.u64 = ctx.r10.u32 & 0xFFF;
	// rlwinm r11,r11,0,26,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFC3F;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880a4270
	if (!ctx.cr6.eq) goto loc_880A4270;
	// lwz r11,9904(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9904);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a4270
	if (!ctx.cr6.eq) goto loc_880A4270;
	// lwz r11,100(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 100);
	// lwz r10,108(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 108);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x880a4298
	if (!ctx.cr6.lt) goto loc_880A4298;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26428(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26428);
	// rlwinm r10,r11,0,28,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xE;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x880a4298
	if (!ctx.cr6.eq) goto loc_880A4298;
	// lwz r11,136(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 136);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880a4258
	if (ctx.cr6.eq) goto loc_880A4258;
	// lis r11,255
	ctx.r11.s64 = 16711680;
	// ori r10,r11,4112
	ctx.r10.u64 = ctx.r11.u64 | 4112;
	// stw r10,9856(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9856, ctx.r10.u32);
	// b 0x880a4298
	goto loc_880A4298;
loc_880A4258:
	// lwz r11,116(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 116);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a4298
	if (!ctx.cr6.eq) goto loc_880A4298;
	// lis r11,255
	ctx.r11.s64 = 16711680;
	// ori r10,r11,4112
	ctx.r10.u64 = ctx.r11.u64 | 4112;
	// b 0x880a4294
	goto loc_880A4294;
loc_880A4270:
	// lwz r11,124(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 124);
	// stw r29,112(r9)
	PPC_STORE_U32(ctx.r9.u32 + 112, ctx.r29.u32);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r8,124(r9)
	PPC_STORE_U32(ctx.r9.u32 + 124, ctx.r8.u32);
	// beq cr6,0x880a4298
	if (ctx.cr6.eq) goto loc_880A4298;
	// lis r11,192
	ctx.r11.s64 = 12582912;
	// ori r10,r11,49152
	ctx.r10.u64 = ctx.r11.u64 | 49152;
loc_880A4294:
	// stw r10,120(r9)
	PPC_STORE_U32(ctx.r9.u32 + 120, ctx.r10.u32);
loc_880A4298:
	// lwz r10,9904(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9904);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880a44dc
	if (ctx.cr6.eq) goto loc_880A44DC;
	// lwz r11,9892(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9892);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a44d8
	if (!ctx.cr6.eq) goto loc_880A44D8;
	// lwz r11,100(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 100);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x880a44d8
	if (!ctx.cr6.gt) goto loc_880A44D8;
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// stw r11,100(r9)
	PPC_STORE_U32(ctx.r9.u32 + 100, ctx.r11.u32);
	// lwz r10,9896(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9896);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x880a436c
	if (!ctx.cr6.eq) goto loc_880A436C;
	// lwz r10,9940(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9940);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bgt cr6,0x880a44d8
	if (ctx.cr6.gt) goto loc_880A44D8;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r11,9916(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9916);
	// stw r10,9988(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9988, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// beq cr6,0x880a42f8
	if (ctx.cr6.eq) goto loc_880A42F8;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
loc_880A42F8:
	// stw r10,9992(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9992, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r11,9996(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9996, ctx.r11.u32);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// beq cr6,0x880a4314
	if (ctx.cr6.eq) goto loc_880A4314;
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// bne cr6,0x880a431c
	if (!ctx.cr6.eq) goto loc_880A431C;
loc_880A4314:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// b 0x880a4320
	goto loc_880A4320;
loc_880A431C:
	// lwz r11,164(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_880A4320:
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r10,2332(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2332, ctx.r10.u32);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// stw r11,2328(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2328, ctx.r11.u32);
	// lwz r11,9916(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9916);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880a4340
	if (ctx.cr6.eq) goto loc_880A4340;
	// lwz r10,164(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_880A4340:
	// stw r10,10000(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10000, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880a435c
	if (!ctx.cr6.eq) goto loc_880A435C;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// stw r29,10004(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10004, ctx.r29.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x880a44cc
	goto loc_880A44CC;
loc_880A435C:
	// lwz r11,176(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,10004(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10004, ctx.r11.u32);
	// b 0x880a44cc
	goto loc_880A44CC;
loc_880A436C:
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x880a4410
	if (!ctx.cr6.eq) goto loc_880A4410;
	// lwz r10,9944(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9944);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bgt cr6,0x880a44d8
	if (ctx.cr6.gt) goto loc_880A44D8;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r11,9916(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9916);
	// stw r10,10008(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10008, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// beq cr6,0x880a439c
	if (ctx.cr6.eq) goto loc_880A439C;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
loc_880A439C:
	// stw r10,10012(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10012, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r11,10016(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10016, ctx.r11.u32);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// beq cr6,0x880a43b8
	if (ctx.cr6.eq) goto loc_880A43B8;
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// bne cr6,0x880a43c0
	if (!ctx.cr6.eq) goto loc_880A43C0;
loc_880A43B8:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// b 0x880a43c4
	goto loc_880A43C4;
loc_880A43C0:
	// lwz r11,164(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_880A43C4:
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r10,2332(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2332, ctx.r10.u32);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// stw r11,2328(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2328, ctx.r11.u32);
	// lwz r11,9916(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9916);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880a43e4
	if (ctx.cr6.eq) goto loc_880A43E4;
	// lwz r10,164(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_880A43E4:
	// stw r10,10020(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10020, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880a4400
	if (!ctx.cr6.eq) goto loc_880A4400;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// stw r29,10024(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10024, ctx.r29.u32);
	// li r3,2
	ctx.r3.s64 = 2;
	// b 0x880a44cc
	goto loc_880A44CC;
loc_880A4400:
	// lwz r11,176(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// li r3,2
	ctx.r3.s64 = 2;
	// stw r11,10024(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10024, ctx.r11.u32);
	// b 0x880a44cc
	goto loc_880A44CC;
loc_880A4410:
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// bne cr6,0x880a44d8
	if (!ctx.cr6.eq) goto loc_880A44D8;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt cr6,0x880a44d8
	if (ctx.cr6.gt) goto loc_880A44D8;
	// lwz r11,-6020(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -6020);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880a4438
	if (!ctx.cr6.eq) goto loc_880A4438;
	// li r11,512
	ctx.r11.s64 = 512;
	// stw r11,100(r9)
	PPC_STORE_U32(ctx.r9.u32 + 100, ctx.r11.u32);
	// b 0x880a44d8
	goto loc_880A44D8;
loc_880A4438:
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r11,9916(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9916);
	// stw r10,10028(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10028, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// beq cr6,0x880a4454
	if (ctx.cr6.eq) goto loc_880A4454;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
loc_880A4454:
	// stw r10,10032(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10032, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r11,10036(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10036, ctx.r11.u32);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// beq cr6,0x880a4470
	if (ctx.cr6.eq) goto loc_880A4470;
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// bne cr6,0x880a4478
	if (!ctx.cr6.eq) goto loc_880A4478;
loc_880A4470:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// b 0x880a447c
	goto loc_880A447C;
loc_880A4478:
	// lwz r11,164(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_880A447C:
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r11,2328(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2328, ctx.r11.u32);
	// stw r10,2332(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2332, ctx.r10.u32);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// lwz r11,9916(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9916);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880a449c
	if (ctx.cr6.eq) goto loc_880A449C;
	// lwz r10,164(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_880A449C:
	// stw r10,10040(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10040, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880a44b0
	if (!ctx.cr6.eq) goto loc_880A44B0;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// b 0x880a44b4
	goto loc_880A44B4;
loc_880A44B0:
	// lwz r11,176(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
loc_880A44B4:
	// lis r10,-30633
	ctx.r10.s64 = -2007564288;
	// stw r11,10044(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10044, ctx.r11.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,-29776(r10)
	PPC_STORE_U32(ctx.r10.u32 + -29776, ctx.r11.u32);
	// bl 0x880971a8
	ctx.lr = 0x880A44C8;
	sub_880971A8(ctx, base);
	// li r3,3
	ctx.r3.s64 = 3;
loc_880A44CC:
	// addi r5,r31,9908
	ctx.r5.s64 = ctx.r31.s64 + 9908;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x880a3ca8
	ctx.lr = 0x880A44D8;
	sub_880A3CA8(ctx, base);
loc_880A44D8:
	// stw r29,9904(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9904, ctx.r29.u32);
loc_880A44DC:
	// lwz r11,9940(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9940);
	// lwz r9,9836(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9836);
	// lwz r8,9956(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9956);
	// subf. r10,r11,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r11.s64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r11,9952(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9952);
	// bgt 0x880a450c
	if (ctx.cr0.gt) goto loc_880A450C;
	// lwz r11,9944(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9944);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// subf. r11,r11,r9
	ctx.r11.s64 = ctx.r9.s64 - ctx.r11.s64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt 0x880a450c
	if (ctx.cr0.gt) goto loc_880A450C;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
loc_880A450C:
	// lwz r9,9948(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9948);
	// stw r10,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r10.u32);
	// stw r9,40(r30)
	PPC_STORE_U32(ctx.r30.u32 + 40, ctx.r9.u32);
	// lwz r10,9952(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9952);
	// stw r11,76(r30)
	PPC_STORE_U32(ctx.r30.u32 + 76, ctx.r11.u32);
	// stw r10,44(r30)
	PPC_STORE_U32(ctx.r30.u32 + 44, ctx.r10.u32);
	// lwz r11,9956(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9956);
	// stw r11,48(r30)
	PPC_STORE_U32(ctx.r30.u32 + 48, ctx.r11.u32);
	// stw r8,80(r30)
	PPC_STORE_U32(ctx.r30.u32 + 80, ctx.r8.u32);
	// lwz r11,10232(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10232);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r11,10240(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10240);
	// beq cr6,0x880a455c
	if (ctx.cr6.eq) goto loc_880A455C;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r11,10240(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10240, ctx.r11.u32);
	// cmpwi cr6,r11,255
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 255, ctx.xer);
	// blt cr6,0x880a4578
	if (ctx.cr6.lt) goto loc_880A4578;
	// li r11,255
	ctx.r11.s64 = 255;
	// stw r11,10240(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10240, ctx.r11.u32);
	// b 0x880a4578
	goto loc_880A4578;
loc_880A455C:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880a4578
	if (ctx.cr6.eq) goto loc_880A4578;
	// addic. r11,r11,-8
	ctx.xer.ca = ctx.r11.u32 > 7;
	ctx.r11.s64 = ctx.r11.s64 + -8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,10240(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10240, ctx.r11.u32);
	// bgt 0x880a4578
	if (ctx.cr0.gt) goto loc_880A4578;
	// stw r29,10240(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10240, ctx.r29.u32);
	// stw r29,10236(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10236, ctx.r29.u32);
loc_880A4578:
	// lwz r11,10248(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10248);
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// addi r9,r11,2
	ctx.r9.s64 = ctx.r11.s64 + 2;
	// lwz r11,10252(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10252);
	// addi r8,r10,9552
	ctx.r8.s64 = ctx.r10.s64 + 9552;
	// clrlwi r7,r9,23
	ctx.r7.u64 = ctx.r9.u32 & 0x1FF;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r6,r7,2,21,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x7FC;
	// stw r7,10248(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10248, ctx.r7.u32);
	// cmpwi cr6,r11,64
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 64, ctx.xer);
	// lwzx r5,r6,r8
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
	// mulli r4,r5,112
	ctx.r4.s64 = ctx.r5.s64 * 112;
	// srawi r3,r4,16
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0xFFFF) != 0);
	ctx.r3.s64 = ctx.r4.s32 >> 16;
	// stw r11,10252(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10252, ctx.r11.u32);
	// addze r11,r3
	temp.s64 = ctx.r3.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r11.s64 = temp.s64;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// stw r11,10244(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10244, ctx.r11.u32);
	// blt cr6,0x880a45c4
	if (ctx.cr6.lt) goto loc_880A45C4;
	// stw r29,10252(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10252, ctx.r29.u32);
loc_880A45C4:
	// lwz r11,10256(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10256);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r11,10260(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10260);
	// beq cr6,0x880a45f4
	if (ctx.cr6.eq) goto loc_880A45F4;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r11,10260(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10260, ctx.r11.u32);
	// cmpwi cr6,r11,128
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 128, ctx.xer);
	// blt cr6,0x880a4614
	if (ctx.cr6.lt) goto loc_880A4614;
	// li r11,128
	ctx.r11.s64 = 128;
	// stw r11,10260(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10260, ctx.r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_880A45F4:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880a4614
	if (ctx.cr6.eq) goto loc_880A4614;
	// addi r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -2;
	// stw r11,10260(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10260, ctx.r11.u32);
	// cmpwi cr6,r11,64
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 64, ctx.xer);
	// bgt cr6,0x880a4614
	if (ctx.cr6.gt) goto loc_880A4614;
	// li r11,64
	ctx.r11.s64 = 64;
	// stw r11,10260(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10260, ctx.r11.u32);
loc_880A4614:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A461C"))) PPC_WEAK_FUNC(sub_880A461C);
PPC_FUNC_IMPL(__imp__sub_880A461C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A4620"))) PPC_WEAK_FUNC(sub_880A4620);
PPC_FUNC_IMPL(__imp__sub_880A4620) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,2304(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// b 0x880a3f98
	sub_880A3F98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A4628"))) PPC_WEAK_FUNC(sub_880A4628);
PPC_FUNC_IMPL(__imp__sub_880A4628) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x880A4630;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30710
	ctx.r11.s64 = -2012610560;
	// li r4,10264
	ctx.r4.s64 = 10264;
	// addi r5,r11,17960
	ctx.r5.s64 = ctx.r11.s64 + 17960;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x880A4648;
	sub_88094290(ctx, base);
	// li r5,10264
	ctx.r5.s64 = 10264;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,2304(r29)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r29.u32 + 2304);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x880A465C;
	sub_88073BD0(ctx, base);
	// lis r10,-30641
	ctx.r10.s64 = -2008088576;
	// li r5,12
	ctx.r5.s64 = 12;
	// addi r3,r10,-18816
	ctx.r3.s64 = ctx.r10.s64 + -18816;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x88073bd0
	ctx.lr = 0x880A4670;
	sub_88073BD0(ctx, base);
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// lis r8,-30710
	ctx.r8.s64 = -2012610560;
	// addi r7,r9,-11984
	ctx.r7.s64 = ctx.r9.s64 + -11984;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r4,r8,17952
	ctx.r4.s64 = ctx.r8.s64 + 17952;
	// lwz r28,-11984(r9)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r9.u32 + -11984);
	// stw r29,-16(r7)
	PPC_STORE_U32(ctx.r7.u32 + -16, ctx.r29.u32);
	// lwz r6,84(r28)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r28.u32 + 84);
	// stw r6,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r6.u32);
	// bl 0x88096200
	ctx.lr = 0x880A4698;
	sub_88096200(ctx, base);
	// lis r11,-30683
	ctx.r11.s64 = -2010841088;
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r29,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// addi r26,r11,23172
	ctx.r26.s64 = ctx.r11.s64 + 23172;
	// stw r28,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r28.u32);
	// lis r5,27
	ctx.r5.s64 = 1769472;
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// lis r4,7
	ctx.r4.s64 = 458752;
	// stw r7,9872(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9872, ctx.r7.u32);
	// lis r9,8
	ctx.r9.s64 = 524288;
	// lwz r7,28(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lis r11,11
	ctx.r11.s64 = 720896;
	// ori r8,r5,38272
	ctx.r8.u64 = ctx.r5.u64 | 38272;
	// ori r10,r4,64640
	ctx.r10.u64 = ctx.r4.u64 | 64640;
	// ori r9,r9,21376
	ctx.r9.u64 = ctx.r9.u64 | 21376;
	// ori r11,r11,17792
	ctx.r11.u64 = ctx.r11.u64 | 17792;
	// addi r30,r26,-6640
	ctx.r30.s64 = ctx.r26.s64 + -6640;
	// cmplwi cr6,r7,1
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 1, ctx.xer);
	// blt cr6,0x880a4740
	if (ctx.cr6.lt) goto loc_880A4740;
	// beq cr6,0x880a4718
	if (ctx.cr6.eq) goto loc_880A4718;
	// cmplwi cr6,r7,3
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 3, ctx.xer);
	// bge cr6,0x880a474c
	if (!ctx.cr6.lt) goto loc_880A474C;
	// lis r8,44
	ctx.r8.s64 = 2883584;
	// lis r11,18
	ctx.r11.s64 = 1179648;
	// lis r10,10
	ctx.r10.s64 = 655360;
	// lis r9,15
	ctx.r9.s64 = 983040;
	// addi r30,r26,-2120
	ctx.r30.s64 = ctx.r26.s64 + -2120;
	// ori r8,r8,15488
	ctx.r8.u64 = ctx.r8.u64 | 15488;
	// ori r11,r11,41600
	ctx.r11.u64 = ctx.r11.u64 | 41600;
	// ori r10,r10,38784
	ctx.r10.u64 = ctx.r10.u64 | 38784;
	// ori r9,r9,640
	ctx.r9.u64 = ctx.r9.u64 | 640;
	// b 0x880a474c
	goto loc_880A474C;
loc_880A4718:
	// lis r8,38
	ctx.r8.s64 = 2490368;
	// lis r11,14
	ctx.r11.s64 = 917504;
	// lis r10,10
	ctx.r10.s64 = 655360;
	// lis r9,12
	ctx.r9.s64 = 786432;
	// addi r30,r26,-2608
	ctx.r30.s64 = ctx.r26.s64 + -2608;
	// ori r8,r8,384
	ctx.r8.u64 = ctx.r8.u64 | 384;
	// ori r11,r11,43904
	ctx.r11.u64 = ctx.r11.u64 | 43904;
	// ori r10,r10,23936
	ctx.r10.u64 = ctx.r10.u64 | 23936;
	// ori r9,r9,63616
	ctx.r9.u64 = ctx.r9.u64 | 63616;
	// b 0x880a474c
	goto loc_880A474C;
loc_880A4740:
	// lis r11,11
	ctx.r11.s64 = 720896;
	// addi r30,r26,-6640
	ctx.r30.s64 = ctx.r26.s64 + -6640;
	// ori r11,r11,17792
	ctx.r11.u64 = ctx.r11.u64 | 17792;
loc_880A474C:
	// subf r8,r11,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r11.s64;
	// srawi r7,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 2;
	// subf r6,r10,r8
	ctx.r6.s64 = ctx.r8.s64 - ctx.r10.s64;
	// stw r8,9940(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9940, ctx.r8.u32);
	// addze r5,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r5.s64 = temp.s64;
	// stw r6,9944(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9944, ctx.r6.u32);
	// stw r5,9844(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9844, ctx.r5.u32);
	// stw r11,9948(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9948, ctx.r11.u32);
	// stw r10,9952(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9952, ctx.r10.u32);
	// stw r9,9956(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9956, ctx.r9.u32);
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addi r11,r11,9736
	ctx.r11.s64 = ctx.r11.s64 + 9736;
	// lwz r10,136(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 136);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r4,104(r11)
	PPC_STORE_U32(ctx.r11.u32 + 104, ctx.r4.u32);
	// stw r4,100(r11)
	PPC_STORE_U32(ctx.r11.u32 + 100, ctx.r4.u32);
	// bne cr6,0x880a47b4
	if (!ctx.cr6.eq) goto loc_880A47B4;
	// rotlwi r10,r4,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r4.u32, 0);
	// srawi r9,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 2;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// stw r8,108(r11)
	PPC_STORE_U32(ctx.r11.u32 + 108, ctx.r8.u32);
loc_880A47B4:
	// lis r11,-30689
	ctx.r11.s64 = -2011234304;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,10408
	ctx.r4.s64 = ctx.r11.s64 + 10408;
	// bl 0x880969a8
	ctx.lr = 0x880A47C4;
	sub_880969A8(ctx, base);
	// li r10,72
	ctx.r10.s64 = 72;
	// li r27,0
	ctx.r27.s64 = 0;
	// li r9,83
	ctx.r9.s64 = 83;
	// stw r27,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r27.u32);
	// lis r8,32
	ctx.r8.s64 = 2097152;
	// stw r9,168(r29)
	PPC_STORE_U32(ctx.r29.u32 + 168, ctx.r9.u32);
	// lis r7,-96
	ctx.r7.s64 = -6291456;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lis r6,120
	ctx.r6.s64 = 7864320;
	// stw r8,9728(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9728, ctx.r8.u32);
	// lis r5,500
	ctx.r5.s64 = 32768000;
	// stw r7,9732(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9732, ctx.r7.u32);
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r11,r31,9148
	ctx.r11.s64 = ctx.r31.s64 + 9148;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r3,r10,55
	ctx.r3.s64 = ctx.r10.s64 + 55;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r28
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r28.u32);
	// subf r8,r9,r6
	ctx.r8.s64 = ctx.r6.s64 - ctx.r9.s64;
	// stw r5,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r5.u32);
	// stw r8,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r8.u32);
	// stw r4,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r4.u32);
	// lwz r7,32(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 32);
	// stw r7,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r7.u32);
	// lwz r6,36(r29)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + 36);
	// stw r6,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r6.u32);
loc_880A482C:
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
	// bdnz 0x880a482c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_880A482C;
	// li r5,220
	ctx.r5.s64 = 220;
	// li r3,266
	ctx.r3.s64 = 266;
	// stw r5,932(r31)
	PPC_STORE_U32(ctx.r31.u32 + 932, ctx.r5.u32);
	// li r4,258
	ctx.r4.s64 = 258;
	// stw r3,5828(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5828, ctx.r3.u32);
	// li r5,296
	ctx.r5.s64 = 296;
	// li r25,304
	ctx.r25.s64 = 304;
	// stw r4,5540(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5540, ctx.r4.u32);
	// li r10,294
	ctx.r10.s64 = 294;
	// stw r5,3812(r31)
	PPC_STORE_U32(ctx.r31.u32 + 3812, ctx.r5.u32);
	// li r3,268
	ctx.r3.s64 = 268;
	// stw r25,4100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4100, ctx.r25.u32);
	// lis r7,-30710
	ctx.r7.s64 = -2012610560;
	// stw r10,4964(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4964, ctx.r10.u32);
	// lis r6,-30710
	ctx.r6.s64 = -2012610560;
	// stw r10,4388(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4388, ctx.r10.u32);
	// stw r3,3524(r31)
	PPC_STORE_U32(ctx.r31.u32 + 3524, ctx.r3.u32);
	// li r11,302
	ctx.r11.s64 = 302;
	// stw r10,1796(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1796, ctx.r10.u32);
	// li r8,292
	ctx.r8.s64 = 292;
	// li r9,328
	ctx.r9.s64 = 328;
	// stw r11,5252(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5252, ctx.r11.u32);
	// li r28,256
	ctx.r28.s64 = 256;
	// stw r8,2372(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2372, ctx.r8.u32);
	// li r4,260
	ctx.r4.s64 = 260;
	// stw r9,2660(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2660, ctx.r9.u32);
	// li r5,210
	ctx.r5.s64 = 210;
	// stw r28,356(r31)
	PPC_STORE_U32(ctx.r31.u32 + 356, ctx.r28.u32);
	// li r25,218
	ctx.r25.s64 = 218;
	// stw r4,3236(r31)
	PPC_STORE_U32(ctx.r31.u32 + 3236, ctx.r4.u32);
	// li r24,148
	ctx.r24.s64 = 148;
	// stw r28,2948(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2948, ctx.r28.u32);
	// addi r3,r7,16784
	ctx.r3.s64 = ctx.r7.s64 + 16784;
	// stw r11,4676(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4676, ctx.r11.u32);
	// addi r10,r6,15192
	ctx.r10.s64 = ctx.r6.s64 + 15192;
	// stw r11,2084(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2084, ctx.r11.u32);
	// stw r5,1220(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1220, ctx.r5.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r25,1508(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1508, ctx.r25.u32);
	// stw r8,6116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 6116, ctx.r8.u32);
	// stw r9,6404(r31)
	PPC_STORE_U32(ctx.r31.u32 + 6404, ctx.r9.u32);
	// stw r24,644(r31)
	PPC_STORE_U32(ctx.r31.u32 + 644, ctx.r24.u32);
	// stw r3,64(r29)
	PPC_STORE_U32(ctx.r29.u32 + 64, ctx.r3.u32);
	// stw r10,84(r29)
	PPC_STORE_U32(ctx.r29.u32 + 84, ctx.r10.u32);
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// bl 0x881556a0
	ctx.lr = 0x880A48F8;
	sub_881556A0(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r8,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// add r7,r11,r31
	ctx.r7.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stw r3,9736(r7)
	PPC_STORE_U32(ctx.r7.u32 + 9736, ctx.r3.u32);
	// lwz r6,8(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r5,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// add r4,r11,r31
	ctx.r4.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lwz r3,9736(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 9736);
	// stw r6,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r6.u32);
	// stw r29,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r29.u32);
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// ble cr6,0x880a4a18
	if (!ctx.cr6.gt) goto loc_880A4A18;
	// addi r10,r11,-4
	ctx.r10.s64 = ctx.r11.s64 + -4;
loc_880A494C:
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
	// lwz r7,9736(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + 9736);
	// lwz r11,28(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880a498c
	if (ctx.cr6.eq) goto loc_880A498C;
loc_880A4974:
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x880a4b08
	if (ctx.cr6.eq) goto loc_880A4B08;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880a4974
	if (!ctx.cr6.eq) goto loc_880A4974;
loc_880A498C:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_880A4990:
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
	// addi r5,r8,9740
	ctx.r5.s64 = ctx.r8.s64 + 9740;
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
	// blt cr6,0x880a494c
	if (ctx.cr6.lt) goto loc_880A494C;
loc_880A4A18:
	// lwz r11,2304(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 2304);
	// li r10,2
	ctx.r10.s64 = 2;
	// lwz r9,9736(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 9736);
	// lwz r11,28(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880a4a48
	if (ctx.cr6.eq) goto loc_880A4A48;
loc_880A4A30:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880a4a48
	if (ctx.cr6.eq) goto loc_880A4A48;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880a4a30
	if (!ctx.cr6.eq) goto loc_880A4A30;
loc_880A4A48:
	// lis r10,128
	ctx.r10.s64 = 8388608;
	// stw r27,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r27.u32);
	// li r11,8
	ctx.r11.s64 = 8;
	// ori r9,r10,32896
	ctx.r9.u64 = ctx.r10.u64 | 32896;
	// lis r10,64
	ctx.r10.s64 = 4194304;
	// stw r9,9856(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9856, ctx.r9.u32);
	// lis r8,-30642
	ctx.r8.s64 = -2008154112;
	// mr r6,r10
	ctx.r6.u64 = ctx.r10.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// addi r11,r8,-32760
	ctx.r11.s64 = ctx.r8.s64 + -32760;
	// lis r5,48
	ctx.r5.s64 = 3145728;
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// addi r10,r11,118
	ctx.r10.s64 = ctx.r11.s64 + 118;
	// addi r11,r11,68
	ctx.r11.s64 = ctx.r11.s64 + 68;
	// lwz r9,0(r26)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// stw r9,9964(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9964, ctx.r9.u32);
	// lwz r9,4(r26)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// stw r9,9968(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9968, ctx.r9.u32);
	// lwz r9,8(r26)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r26.u32 + 8);
	// stw r9,9972(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9972, ctx.r9.u32);
	// stw r28,8848(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8848, ctx.r28.u32);
	// stw r28,8936(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8936, ctx.r28.u32);
	// stw r28,7440(r31)
	PPC_STORE_U32(ctx.r31.u32 + 7440, ctx.r28.u32);
	// stw r6,256(r31)
	PPC_STORE_U32(ctx.r31.u32 + 256, ctx.r6.u32);
	// stw r6,260(r31)
	PPC_STORE_U32(ctx.r31.u32 + 260, ctx.r6.u32);
	// stw r28,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r28.u32);
	// stw r27,300(r31)
	PPC_STORE_U32(ctx.r31.u32 + 300, ctx.r27.u32);
	// stw r5,304(r31)
	PPC_STORE_U32(ctx.r31.u32 + 304, ctx.r5.u32);
	// stw r27,324(r31)
	PPC_STORE_U32(ctx.r31.u32 + 324, ctx.r27.u32);
loc_880A4ABC:
	// stw r27,-28(r11)
	PPC_STORE_U32(ctx.r11.u32 + -28, ctx.r27.u32);
	// stwu r27,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r27.u32);
	ctx.r11.u32 = ea;
	// sth r27,-14(r10)
	PPC_STORE_U16(ctx.r10.u32 + -14, ctx.r27.u16);
	// sthu r27,2(r10)
	ea = 2 + ctx.r10.u32;
	PPC_STORE_U16(ea, ctx.r27.u16);
	ctx.r10.u32 = ea;
	// bdnz 0x880a4abc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_880A4ABC;
	// lis r8,-30633
	ctx.r8.s64 = -2007564288;
	// stw r27,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r27.u32);
	// lis r7,-30633
	ctx.r7.s64 = -2007564288;
	// lis r6,-30633
	ctx.r6.s64 = -2007564288;
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// stw r5,10260(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10260, ctx.r5.u32);
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// stw r27,-29732(r8)
	PPC_STORE_U32(ctx.r8.u32 + -29732, ctx.r27.u32);
	// stw r27,-29736(r7)
	PPC_STORE_U32(ctx.r7.u32 + -29736, ctx.r27.u32);
	// stw r27,-29760(r6)
	PPC_STORE_U32(ctx.r6.u32 + -29760, ctx.r27.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
loc_880A4B08:
	// lwz r8,24(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x880a4b18
	if (ctx.cr6.eq) goto loc_880A4B18;
	// stw r8,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r8.u32);
loc_880A4B18:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x880a4990
	goto loc_880A4990;
}

__attribute__((alias("__imp__sub_880A4B20"))) PPC_WEAK_FUNC(sub_880A4B20);
PPC_FUNC_IMPL(__imp__sub_880A4B20) {
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
	// addi r11,r31,9736
	ctx.r11.s64 = ctx.r31.s64 + 9736;
	// stw r8,9848(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9848, ctx.r8.u32);
	// lwz r10,9892(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9892);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x880a4c0c
	if (!ctx.cr6.eq) goto loc_880A4C0C;
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 100);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x880a4c0c
	if (!ctx.cr6.gt) goto loc_880A4C0C;
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// subf r10,r9,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r9.s64;
	// stw r10,100(r11)
	PPC_STORE_U32(ctx.r11.u32 + 100, ctx.r10.u32);
	// lwz r9,9896(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9896);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x880a4c28
	if (!ctx.cr6.eq) goto loc_880A4C28;
	// lwz r7,9940(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9940);
	// cmpw cr6,r10,r7
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, ctx.xer);
	// bgt cr6,0x880a4c28
	if (ctx.cr6.gt) goto loc_880A4C28;
	// stw r8,9988(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9988, ctx.r8.u32);
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880a4b98
	if (ctx.cr6.eq) goto loc_880A4B98;
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
loc_880A4B98:
	// stw r11,9992(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9992, ctx.r11.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// stw r11,9996(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9996, ctx.r11.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880a4bb8
	if (ctx.cr6.eq) goto loc_880A4BB8;
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
loc_880A4BB8:
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880a4bc8
	if (ctx.cr6.eq) goto loc_880A4BC8;
	// lwz r11,164(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_880A4BC8:
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r10,2332(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2332, ctx.r10.u32);
	// stw r11,2328(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2328, ctx.r11.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880a4be4
	if (ctx.cr6.eq) goto loc_880A4BE4;
	// lwz r11,164(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_880A4BE4:
	// stw r11,10000(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10000, ctx.r11.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880a4bf8
	if (ctx.cr6.eq) goto loc_880A4BF8;
	// lwz r11,176(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
loc_880A4BF8:
	// stw r11,10004(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10004, ctx.r11.u32);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,1
	ctx.r3.s64 = 1;
loc_880A4C08:
	// bl 0x880a3ca8
	ctx.lr = 0x880A4C0C;
	sub_880A3CA8(ctx, base);
loc_880A4C0C:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880A4C10:
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
loc_880A4C28:
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x880a4cdc
	if (!ctx.cr6.eq) goto loc_880A4CDC;
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 100);
	// lwz r7,9944(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9944);
	// cmpw cr6,r10,r7
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, ctx.xer);
	// bgt cr6,0x880a4cdc
	if (ctx.cr6.gt) goto loc_880A4CDC;
	// stw r8,10008(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10008, ctx.r8.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880a4c54
	if (ctx.cr6.eq) goto loc_880A4C54;
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
loc_880A4C54:
	// stw r11,10012(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10012, ctx.r11.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// stw r11,10016(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10016, ctx.r11.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880a4c74
	if (ctx.cr6.eq) goto loc_880A4C74;
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
loc_880A4C74:
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880a4c84
	if (ctx.cr6.eq) goto loc_880A4C84;
	// lwz r11,164(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_880A4C84:
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r11,2328(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2328, ctx.r11.u32);
	// stw r10,2332(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2332, ctx.r10.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880a4ca0
	if (ctx.cr6.eq) goto loc_880A4CA0;
	// lwz r11,164(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_880A4CA0:
	// stw r11,10020(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10020, ctx.r11.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880a4cc4
	if (!ctx.cr6.eq) goto loc_880A4CC4;
	// stw r11,10024(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10024, ctx.r11.u32);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,2
	ctx.r3.s64 = 2;
	// b 0x880a4c08
	goto loc_880A4C08;
loc_880A4CC4:
	// lwz r11,176(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,2
	ctx.r3.s64 = 2;
	// stw r11,10024(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10024, ctx.r11.u32);
	// b 0x880a4c08
	goto loc_880A4C08;
loc_880A4CDC:
	// cmpwi cr6,r9,2
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 2, ctx.xer);
	// bne cr6,0x880a4c0c
	if (!ctx.cr6.eq) goto loc_880A4C0C;
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 100);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bgt cr6,0x880a4c0c
	if (ctx.cr6.gt) goto loc_880A4C0C;
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// addi r9,r10,26432
	ctx.r9.s64 = ctx.r10.s64 + 26432;
	// lwz r10,324(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 324);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x880a4d10
	if (!ctx.cr6.eq) goto loc_880A4D10;
	// li r10,512
	ctx.r10.s64 = 512;
	// stw r10,100(r11)
	PPC_STORE_U32(ctx.r11.u32 + 100, ctx.r10.u32);
	// b 0x880a4c0c
	goto loc_880A4C0C;
loc_880A4D10:
	// stw r8,10028(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10028, ctx.r8.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880a4d24
	if (ctx.cr6.eq) goto loc_880A4D24;
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
loc_880A4D24:
	// stw r11,10032(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10032, ctx.r11.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// stw r11,10036(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10036, ctx.r11.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880a4d44
	if (ctx.cr6.eq) goto loc_880A4D44;
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
loc_880A4D44:
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880a4d54
	if (ctx.cr6.eq) goto loc_880A4D54;
	// lwz r11,164(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_880A4D54:
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r11,2328(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2328, ctx.r11.u32);
	// stw r10,2332(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2332, ctx.r10.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880a4d70
	if (ctx.cr6.eq) goto loc_880A4D70;
	// lwz r11,164(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_880A4D70:
	// stw r11,10040(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10040, ctx.r11.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880a4d84
	if (ctx.cr6.eq) goto loc_880A4D84;
	// lwz r11,176(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
loc_880A4D84:
	// lis r10,-30633
	ctx.r10.s64 = -2007564288;
	// stw r11,10044(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10044, ctx.r11.u32);
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// stw r8,-29776(r10)
	PPC_STORE_U32(ctx.r10.u32 + -29776, ctx.r8.u32);
	// bl 0x880971a8
	ctx.lr = 0x880A4D98;
	sub_880971A8(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x880a3ca8
	ctx.lr = 0x880A4DA8;
	sub_880A3CA8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880a4c10
	goto loc_880A4C10;
}

__attribute__((alias("__imp__sub_880A4DB0"))) PPC_WEAK_FUNC(sub_880A4DB0);
PPC_FUNC_IMPL(__imp__sub_880A4DB0) {
	PPC_FUNC_PROLOGUE();
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// b 0x880a4b20
	sub_880A4B20(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A4DB8"))) PPC_WEAK_FUNC(sub_880A4DB8);
PPC_FUNC_IMPL(__imp__sub_880A4DB8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// li r5,12
	ctx.r5.s64 = 12;
	// addi r3,r11,-18816
	ctx.r3.s64 = ctx.r11.s64 + -18816;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x88073bd0
	sub_88073BD0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A4DCC"))) PPC_WEAK_FUNC(sub_880A4DCC);
PPC_FUNC_IMPL(__imp__sub_880A4DCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A4DD0"))) PPC_WEAK_FUNC(sub_880A4DD0);
PPC_FUNC_IMPL(__imp__sub_880A4DD0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// lhz r10,5836(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 5836);
	// addi r9,r11,-18816
	ctx.r9.s64 = ctx.r11.s64 + -18816;
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
loc_880A4DFC:
	// lhz r9,92(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 92);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x880a4e18
	if (ctx.cr6.eq) goto loc_880A4E18;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880a4dfc
	if (!ctx.cr6.eq) goto loc_880A4DFC;
	// blr 
	return;
loc_880A4E18:
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r10,96(r11)
	PPC_STORE_U16(ctx.r11.u32 + 96, ctx.r10.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880A4E24"))) PPC_WEAK_FUNC(sub_880A4E24);
PPC_FUNC_IMPL(__imp__sub_880A4E24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A4E28"))) PPC_WEAK_FUNC(sub_880A4E28);
PPC_FUNC_IMPL(__imp__sub_880A4E28) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// lhz r10,5836(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 5836);
	// addi r9,r11,-18816
	ctx.r9.s64 = ctx.r11.s64 + -18816;
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
loc_880A4E54:
	// lhz r9,92(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 92);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x880a4e70
	if (ctx.cr6.eq) goto loc_880A4E70;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880a4e54
	if (!ctx.cr6.eq) goto loc_880A4E54;
	// blr 
	return;
loc_880A4E70:
	// li r10,1
	ctx.r10.s64 = 1;
	// sth r10,96(r11)
	PPC_STORE_U16(ctx.r11.u32 + 96, ctx.r10.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880A4E7C"))) PPC_WEAK_FUNC(sub_880A4E7C);
PPC_FUNC_IMPL(__imp__sub_880A4E7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A4E80"))) PPC_WEAK_FUNC(sub_880A4E80);
PPC_FUNC_IMPL(__imp__sub_880A4E80) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30641
	ctx.r11.s64 = -2008088576;
	// lhz r10,5836(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 5836);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwz r11,-18816(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -18816);
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
loc_880A4EA8:
	// lhz r9,92(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 92);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x880a4ec4
	if (ctx.cr6.eq) goto loc_880A4EC4;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880a4ea8
	if (!ctx.cr6.eq) goto loc_880A4EA8;
	// blr 
	return;
loc_880A4EC4:
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r10,96(r11)
	PPC_STORE_U16(ctx.r11.u32 + 96, ctx.r10.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880A4ED0"))) PPC_WEAK_FUNC(sub_880A4ED0);
PPC_FUNC_IMPL(__imp__sub_880A4ED0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880A4ED4"))) PPC_WEAK_FUNC(sub_880A4ED4);
PPC_FUNC_IMPL(__imp__sub_880A4ED4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A4ED8"))) PPC_WEAK_FUNC(sub_880A4ED8);
PPC_FUNC_IMPL(__imp__sub_880A4ED8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880A4EDC"))) PPC_WEAK_FUNC(sub_880A4EDC);
PPC_FUNC_IMPL(__imp__sub_880A4EDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A4EE0"))) PPC_WEAK_FUNC(sub_880A4EE0);
PPC_FUNC_IMPL(__imp__sub_880A4EE0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880A4EE4"))) PPC_WEAK_FUNC(sub_880A4EE4);
PPC_FUNC_IMPL(__imp__sub_880A4EE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A4EE8"))) PPC_WEAK_FUNC(sub_880A4EE8);
PPC_FUNC_IMPL(__imp__sub_880A4EE8) {
	PPC_FUNC_PROLOGUE();
	// cmpwi cr6,r3,256
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 256, ctx.xer);
	// bltlr cr6
	if (ctx.cr6.lt) return;
	// subfic r3,r3,512
	ctx.xer.ca = ctx.r3.u32 <= 512;
	ctx.r3.s64 = 512 - ctx.r3.s64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880A4EF8"))) PPC_WEAK_FUNC(sub_880A4EF8);
PPC_FUNC_IMPL(__imp__sub_880A4EF8) {
	PPC_FUNC_PROLOGUE();
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880A4F00"))) PPC_WEAK_FUNC(sub_880A4F00);
PPC_FUNC_IMPL(__imp__sub_880A4F00) {
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

__attribute__((alias("__imp__sub_880A4F48"))) PPC_WEAK_FUNC(sub_880A4F48);
PPC_FUNC_IMPL(__imp__sub_880A4F48) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x880A4F50;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// mr r25,r7
	ctx.r25.u64 = ctx.r7.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880a5100
	if (ctx.cr6.eq) goto loc_880A5100;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26428(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26428);
	// clrlwi r10,r11,29
	ctx.r10.u64 = ctx.r11.u32 & 0x7;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x880a505c
	if (!ctx.cr6.eq) goto loc_880A505C;
	// lis r10,-30667
	ctx.r10.s64 = -2009792512;
	// li r11,14
	ctx.r11.s64 = 14;
	// li r3,7
	ctx.r3.s64 = 7;
	// stw r11,12380(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12380, ctx.r11.u32);
	// bl 0x881534c8
	ctx.lr = 0x880A4F9C;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lis r9,-30667
	ctx.r9.s64 = -2009792512;
	// addi r8,r11,-4
	ctx.r8.s64 = ctx.r11.s64 + -4;
	// li r3,7
	ctx.r3.s64 = 7;
	// rlwinm r11,r8,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// stw r11,12364(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12364, ctx.r11.u32);
	// bl 0x881534c8
	ctx.lr = 0x880A4FBC;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lwz r7,10252(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 10252);
	// lis r6,-30667
	ctx.r6.s64 = -2009792512;
	// addi r5,r11,-4
	ctx.r5.s64 = ctx.r11.s64 + -4;
	// lis r3,-30667
	ctx.r3.s64 = -2009792512;
	// rlwinm r11,r5,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// clrlwi r5,r7,27
	ctx.r5.u64 = ctx.r7.u32 & 0x1F;
	// add r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
	// lis r10,-30667
	ctx.r10.s64 = -2009792512;
	// stw r11,12372(r6)
	PPC_STORE_U32(ctx.r6.u32 + 12372, ctx.r11.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r5,12384(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12384, ctx.r5.u32);
	// li r3,14
	ctx.r3.s64 = 14;
	// stw r30,12376(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12376, ctx.r30.u32);
	// bl 0x880f25b8
	ctx.lr = 0x880A4FF8;
	sub_880F25B8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x881534c8
	ctx.lr = 0x880A5004;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r4,20
	ctx.r4.s64 = 20;
	// addi r9,r11,-16
	ctx.r9.s64 = ctx.r11.s64 + -16;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// clrlwi r5,r9,23
	ctx.r5.u64 = ctx.r9.u32 & 0x1FF;
	// bl 0x880f26e0
	ctx.lr = 0x880A501C;
	sub_880F26E0(ctx, base);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x880a502c
	if (ctx.cr6.eq) goto loc_880A502C;
	// lis r11,255
	ctx.r11.s64 = 16711680;
	// stw r11,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
loc_880A502C:
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x881534c8
	ctx.lr = 0x880A5034;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lis r10,-30682
	ctx.r10.s64 = -2010775552;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r10,-29972
	ctx.r8.s64 = ctx.r10.s64 + -29972;
	// lwzx r11,r9,r8
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880a505c
	if (ctx.cr6.eq) goto loc_880A505C;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x880a505c
	if (ctx.cr6.eq) goto loc_880A505C;
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
loc_880A505C:
	// lwz r11,10244(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 10244);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r11,394
	ctx.r3.s64 = ctx.r11.s64 + 394;
	// bl 0x881538c0
	ctx.lr = 0x880A5074;
	sub_881538C0(ctx, base);
	// lwz r11,0(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// lis r31,-30597
	ctx.r31.s64 = -2005204992;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880a50b8
	if (ctx.cr6.eq) goto loc_880A50B8;
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,-11932(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -11932);
	// lis r7,128
	ctx.r7.s64 = 8388608;
	// rlwimi r9,r11,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// ori r6,r7,4112
	ctx.r6.u64 = ctx.r7.u64 | 4112;
	// addi r26,r10,1
	ctx.r26.s64 = ctx.r10.s64 + 1;
	// or r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 | ctx.r8.u64;
	// stw r6,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r6.u32);
	// stw r26,-11932(r31)
	PPC_STORE_U32(ctx.r31.u32 + -11932, ctx.r26.u32);
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// b 0x880a50bc
	goto loc_880A50BC;
loc_880A50B8:
	// lwz r26,-11932(r31)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r31.u32 + -11932);
loc_880A50BC:
	// lwz r11,10244(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 10244);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r11,380
	ctx.r3.s64 = ctx.r11.s64 + 380;
	// bl 0x881538c0
	ctx.lr = 0x880A50D4;
	sub_881538C0(ctx, base);
	// lwz r11,0(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880a5100
	if (ctx.cr6.eq) goto loc_880A5100;
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r10,r26,1
	ctx.r10.s64 = ctx.r26.s64 + 1;
	// rlwimi r9,r11,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r10,-11932(r31)
	PPC_STORE_U32(ctx.r31.u32 + -11932, ctx.r10.u32);
	// or r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 | ctx.r8.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
loc_880A5100:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A5108"))) PPC_WEAK_FUNC(sub_880A5108);
PPC_FUNC_IMPL(__imp__sub_880A5108) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880A5110;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r7
	ctx.r31.u64 = ctx.r7.u64;
	// mr r30,r8
	ctx.r30.u64 = ctx.r8.u64;
	// mr r29,r9
	ctx.r29.u64 = ctx.r9.u64;
	// bl 0x881538c0
	ctx.lr = 0x880A5124;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x880a5178
	if (ctx.cr6.eq) goto loc_880A5178;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880a513c
	if (ctx.cr6.eq) goto loc_880A513C;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880A513C:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x880a5178
	if (ctx.cr6.eq) goto loc_880A5178;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880a5178
	if (ctx.cr6.eq) goto loc_880A5178;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r8,547
	ctx.r8.s64 = 35848192;
	// rlwimi r8,r11,8,16,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r8.u64 & 0xFFFFFFFFFFFF00FF);
	// lwz r11,-11932(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11932);
	// or r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 | ctx.r9.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r11,-11932(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11932, ctx.r11.u32);
loc_880A5178:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x880a5198
	if (ctx.cr6.eq) goto loc_880A5198;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880a5198
	if (ctx.cr6.eq) goto loc_880A5198;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r29,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_880A5198:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A51A0"))) PPC_WEAK_FUNC(sub_880A51A0);
PPC_FUNC_IMPL(__imp__sub_880A51A0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880A51A8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r7
	ctx.r31.u64 = ctx.r7.u64;
	// mr r30,r8
	ctx.r30.u64 = ctx.r8.u64;
	// mr r29,r9
	ctx.r29.u64 = ctx.r9.u64;
	// bl 0x881538c0
	ctx.lr = 0x880A51BC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x880a5210
	if (ctx.cr6.eq) goto loc_880A5210;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880a51d4
	if (ctx.cr6.eq) goto loc_880A51D4;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880A51D4:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x880a5210
	if (ctx.cr6.eq) goto loc_880A5210;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880a5210
	if (ctx.cr6.eq) goto loc_880A5210;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r8,545
	ctx.r8.s64 = 35717120;
	// rlwimi r8,r11,8,16,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r8.u64 & 0xFFFFFFFFFFFF00FF);
	// lwz r11,-11932(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11932);
	// or r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 | ctx.r9.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r11,-11932(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11932, ctx.r11.u32);
loc_880A5210:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x880a5230
	if (ctx.cr6.eq) goto loc_880A5230;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880a5230
	if (ctx.cr6.eq) goto loc_880A5230;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r29,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_880A5230:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A5238"))) PPC_WEAK_FUNC(sub_880A5238);
PPC_FUNC_IMPL(__imp__sub_880A5238) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071134
	ctx.lr = 0x880A5240;
	__savegprlr_19(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r24,180(r3)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r3.u32 + 180);
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// mr r21,r4
	ctx.r21.u64 = ctx.r4.u64;
	// addi r22,r3,88
	ctx.r22.s64 = ctx.r3.s64 + 88;
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// ble cr6,0x880a5328
	if (!ctx.cr6.gt) goto loc_880A5328;
	// lwz r11,84(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 84);
	// addi r9,r1,92
	ctx.r9.s64 = ctx.r1.s64 + 92;
	// lwz r6,92(r22)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r22.u32 + 92);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r4,r11,128
	ctx.r4.s64 = ctx.r11.s64 + 128;
	// lwz r8,76(r22)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r22.u32 + 76);
	// lwz r7,68(r22)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r22.u32 + 68);
	// lwz r11,60(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 60);
	// addi r3,r8,128
	ctx.r3.s64 = ctx.r8.s64 + 128;
	// lwz r31,88(r22)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r22.u32 + 88);
	// addi r30,r7,128
	ctx.r30.s64 = ctx.r7.s64 + 128;
	// lwz r29,80(r22)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r22.u32 + 80);
	// addi r28,r11,128
	ctx.r28.s64 = ctx.r11.s64 + 128;
	// lwz r27,72(r22)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r22.u32 + 72);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// lwz r26,64(r22)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r22.u32 + 64);
	// lis r25,128
	ctx.r25.s64 = 8388608;
loc_880A52A0:
	// divw r5,r10,r24
	ctx.r5.s32 = ppc_divw(ctx.r10.s32, ctx.r24.s32);
	// addi r10,r10,128
	ctx.r10.s64 = ctx.r10.s64 + 128;
	// subfic r11,r5,128
	ctx.xer.ca = ctx.r5.u32 <= 128;
	ctx.r11.s64 = 128 - ctx.r5.s64;
	// mullw r20,r5,r5
	ctx.r20.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r5.s32);
	// mullw r19,r11,r11
	ctx.r19.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r11.s32);
	// mullw r8,r19,r5
	ctx.r8.s64 = int64_t(ctx.r19.s32) * int64_t(ctx.r5.s32);
	// mullw r7,r11,r5
	ctx.r7.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r5.s32);
	// rlwinm r6,r8,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// mullw r7,r7,r5
	ctx.r7.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r5.s32);
	// mullw r19,r19,r11
	ctx.r19.s64 = int64_t(ctx.r19.s32) * int64_t(ctx.r11.s32);
	// add r11,r8,r6
	ctx.r11.u64 = ctx.r8.u64 + ctx.r6.u64;
	// rlwinm r8,r7,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// mullw r6,r28,r19
	ctx.r6.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r19.s32);
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// mullw r7,r30,r11
	ctx.r7.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r11.s32);
	// add r6,r6,r7
	ctx.r6.u64 = ctx.r6.u64 + ctx.r7.u64;
	// mullw r7,r3,r8
	ctx.r7.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r8.s32);
	// mullw r20,r20,r5
	ctx.r20.s64 = int64_t(ctx.r20.s32) * int64_t(ctx.r5.s32);
	// mullw r11,r27,r11
	ctx.r11.s64 = int64_t(ctx.r27.s32) * int64_t(ctx.r11.s32);
	// mullw r5,r26,r19
	ctx.r5.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r19.s32);
	// add r6,r6,r7
	ctx.r6.u64 = ctx.r6.u64 + ctx.r7.u64;
	// mullw r8,r29,r8
	ctx.r8.s64 = int64_t(ctx.r29.s32) * int64_t(ctx.r8.s32);
	// add r11,r5,r11
	ctx.r11.u64 = ctx.r5.u64 + ctx.r11.u64;
	// mullw r7,r4,r20
	ctx.r7.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r20.s32);
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r6,r6,r7
	ctx.r6.u64 = ctx.r6.u64 + ctx.r7.u64;
	// mullw r8,r31,r20
	ctx.r8.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r20.s32);
	// rlwinm r5,r6,27,5,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x7FFFFFF;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// subf r8,r25,r5
	ctx.r8.s64 = ctx.r5.s64 - ctx.r25.s64;
	// rlwinm r7,r11,27,5,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x7FFFFFF;
	// stw r8,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// stwu r7,8(r9)
	ea = 8 + ctx.r9.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x880a52a0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_880A52A0;
loc_880A5328:
	// lwz r3,0(r23)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r23.u32 + 0);
	// lwz r5,12(r22)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r22.u32 + 12);
	// lwz r4,8(r22)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r22.u32 + 8);
	// bl 0x88095590
	ctx.lr = 0x880A5338;
	sub_88095590(ctx, base);
	// cmpwi cr6,r3,320
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 320, ctx.xer);
	// ble cr6,0x880a5348
	if (!ctx.cr6.gt) goto loc_880A5348;
	// li r3,320
	ctx.r3.s64 = 320;
	// b 0x880a5354
	goto loc_880A5354;
loc_880A5348:
	// cmpwi cr6,r3,192
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 192, ctx.xer);
	// bge cr6,0x880a5354
	if (!ctx.cr6.lt) goto loc_880A5354;
	// li r3,192
	ctx.r3.s64 = 192;
loc_880A5354:
	// lwz r11,48(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 48);
	// clrlwi r9,r11,23
	ctx.r9.u64 = ctx.r11.u32 & 0x1FF;
	// subf r10,r9,r3
	ctx.r10.s64 = ctx.r3.s64 - ctx.r9.s64;
	// clrlwi r11,r10,23
	ctx.r11.u64 = ctx.r10.u32 & 0x1FF;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880a53dc
	if (ctx.cr6.eq) goto loc_880A53DC;
	// cmpwi cr6,r11,256
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 256, ctx.xer);
	// blt cr6,0x880a5378
	if (ctx.cr6.lt) goto loc_880A5378;
	// subfic r11,r11,512
	ctx.xer.ca = ctx.r11.u32 <= 512;
	ctx.r11.s64 = 512 - ctx.r11.s64;
loc_880A5378:
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// blt cr6,0x880a53dc
	if (ctx.cr6.lt) goto loc_880A53DC;
	// clrlwi r10,r3,23
	ctx.r10.u64 = ctx.r3.u32 & 0x1FF;
	// subf r11,r9,r10
	ctx.r11.s64 = ctx.r10.s64 - ctx.r9.s64;
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a539c
	if (!ctx.cr6.eq) goto loc_880A539C;
	// clrlwi r11,r9,16
	ctx.r11.u64 = ctx.r9.u32 & 0xFFFF;
	// b 0x880a53d4
	goto loc_880A53D4;
loc_880A539C:
	// cmpwi cr6,r11,256
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 256, ctx.xer);
	// blt cr6,0x880a53bc
	if (ctx.cr6.lt) goto loc_880A53BC;
	// subfic r11,r11,512
	ctx.xer.ca = ctx.r11.u32 <= 512;
	ctx.r11.s64 = 512 - ctx.r11.s64;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// ble cr6,0x880a53d0
	if (!ctx.cr6.gt) goto loc_880A53D0;
	// addi r11,r9,-2
	ctx.r11.s64 = ctx.r9.s64 + -2;
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// b 0x880a53d4
	goto loc_880A53D4;
loc_880A53BC:
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// ble cr6,0x880a53d0
	if (!ctx.cr6.gt) goto loc_880A53D0;
	// addi r11,r9,2
	ctx.r11.s64 = ctx.r9.s64 + 2;
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// b 0x880a53d4
	goto loc_880A53D4;
loc_880A53D0:
	// clrlwi r11,r10,16
	ctx.r11.u64 = ctx.r10.u32 & 0xFFFF;
loc_880A53D4:
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// stw r11,48(r22)
	PPC_STORE_U32(ctx.r22.u32 + 48, ctx.r11.u32);
loc_880A53DC:
	// lwz r11,48(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 48);
	// cmpwi cr6,r11,320
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 320, ctx.xer);
	// ble cr6,0x880a53f0
	if (!ctx.cr6.gt) goto loc_880A53F0;
	// li r11,320
	ctx.r11.s64 = 320;
	// b 0x880a53fc
	goto loc_880A53FC;
loc_880A53F0:
	// cmpwi cr6,r11,192
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 192, ctx.xer);
	// bge cr6,0x880a53fc
	if (!ctx.cr6.lt) goto loc_880A53FC;
	// li r11,192
	ctx.r11.s64 = 192;
loc_880A53FC:
	// addi r11,r11,-188
	ctx.r11.s64 = ctx.r11.s64 + -188;
	// lwz r4,10260(r23)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r23.u32 + 10260);
	// lis r3,-30683
	ctx.r3.s64 = -2010841088;
	// lwz r9,652(r23)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r23.u32 + 652);
	// srawi r7,r11,3
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7) != 0);
	ctx.r7.s64 = ctx.r11.s32 >> 3;
	// lwz r8,12(r22)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r22.u32 + 12);
	// addi r10,r3,29500
	ctx.r10.s64 = ctx.r3.s64 + 29500;
	// lwz r6,8(r22)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r22.u32 + 8);
	// clrlwi r5,r7,26
	ctx.r5.u64 = ctx.r7.u32 & 0x3F;
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// subfic r11,r5,16
	ctx.xer.ca = ctx.r5.u32 <= 16;
	ctx.r11.s64 = 16 - ctx.r5.s64;
	// li r7,10
	ctx.r7.s64 = 10;
	// rlwinm r31,r11,1,0,30
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r30,r4,8,0,23
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// divw r5,r9,r7
	ctx.r5.s32 = ppc_divw(ctx.r9.s32, ctx.r7.s32);
	// or r7,r30,r4
	ctx.r7.u64 = ctx.r30.u64 | ctx.r4.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// lbzx r30,r31,r3
	ctx.r30.u64 = PPC_LOAD_U8(ctx.r31.u32 + ctx.r3.u32);
	// rlwinm r29,r7,8,0,23
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// lbzx r10,r31,r10
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + ctx.r10.u32);
	// addis r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 65536;
	// extsb r7,r30
	ctx.r7.s64 = ctx.r30.s8;
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// addi r7,r7,-8
	ctx.r7.s64 = ctx.r7.s64 + -8;
	// addi r11,r10,-14
	ctx.r11.s64 = ctx.r10.s64 + -14;
	// rlwinm r10,r7,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r7,r11,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// add r10,r10,r5
	ctx.r10.u64 = ctx.r10.u64 + ctx.r5.u64;
	// add r31,r7,r6
	ctx.r31.u64 = ctx.r7.u64 + ctx.r6.u64;
	// add r30,r10,r8
	ctx.r30.u64 = ctx.r10.u64 + ctx.r8.u64;
	// or r10,r29,r4
	ctx.r10.u64 = ctx.r29.u64 | ctx.r4.u64;
	// stw r31,7052(r23)
	PPC_STORE_U32(ctx.r23.u32 + 7052, ctx.r31.u32);
	// stw r30,7056(r23)
	PPC_STORE_U32(ctx.r23.u32 + 7056, ctx.r30.u32);
	// addi r3,r3,-26353
	ctx.r3.s64 = ctx.r3.s64 + -26353;
	// stw r31,10180(r23)
	PPC_STORE_U32(ctx.r23.u32 + 10180, ctx.r31.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r30,10184(r23)
	PPC_STORE_U32(ctx.r23.u32 + 10184, ctx.r30.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stw r31,9748(r23)
	PPC_STORE_U32(ctx.r23.u32 + 9748, ctx.r31.u32);
	// mr r6,r21
	ctx.r6.u64 = ctx.r21.u64;
	// stw r30,9752(r23)
	PPC_STORE_U32(ctx.r23.u32 + 9752, ctx.r30.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// bl 0x880a51a0
	ctx.lr = 0x880A54B0;
	sub_880A51A0(ctx, base);
	// lwz r9,10236(r23)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r23.u32 + 10236);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x880a54d4
	if (!ctx.cr6.eq) goto loc_880A54D4;
	// addi r7,r23,10240
	ctx.r7.s64 = ctx.r23.s64 + 10240;
	// mr r6,r21
	ctx.r6.u64 = ctx.r21.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x880a4f48
	ctx.lr = 0x880A54D4;
	sub_880A4F48(ctx, base);
loc_880A54D4:
	// lwz r11,92(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 92);
	// addic. r31,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r31.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x880a5584
	if (ctx.cr0.lt) goto loc_880A5584;
	// rlwinm r10,r31,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r11,r31,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r31,r10
	ctx.r9.u64 = ctx.r31.u64 + ctx.r10.u64;
	// addi r10,r1,100
	ctx.r10.s64 = ctx.r1.s64 + 100;
	// rlwinm r26,r9,4,0,27
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// add r29,r11,r10
	ctx.r29.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r27,2
	ctx.r27.s64 = 131072;
	// ori r28,r11,39200
	ctx.r28.u64 = ctx.r11.u64 | 39200;
loc_880A5504:
	// lwz r9,-4(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + -4);
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// lwz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// cmpwi cr6,r31,3
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 3, ctx.xer);
	// ble cr6,0x880a551c
	if (!ctx.cr6.gt) goto loc_880A551C;
	// li r10,3
	ctx.r10.s64 = 3;
loc_880A551C:
	// lwz r11,92(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 92);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// divw r11,r26,r11
	ctx.r11.s32 = ppc_divw(ctx.r26.s32, ctx.r11.s32);
	// bgt cr6,0x880a5530
	if (ctx.cr6.gt) goto loc_880A5530;
	// li r11,48
	ctx.r11.s64 = 48;
loc_880A5530:
	// subfic r11,r11,112
	ctx.xer.ca = ctx.r11.u32 <= 112;
	ctx.r11.s64 = 112 - ctx.r11.s64;
	// add r4,r9,r27
	ctx.r4.u64 = ctx.r9.u64 + ctx.r27.u64;
	// rlwinm r9,r11,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r8,r11,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// or r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 | ctx.r8.u64;
	// or r30,r7,r11
	ctx.r30.u64 = ctx.r7.u64 | ctx.r11.u64;
	// beq cr6,0x880a5558
	if (ctx.cr6.eq) goto loc_880A5558;
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// bne cr6,0x880a555c
	if (!ctx.cr6.eq) goto loc_880A555C;
loc_880A5558:
	// add r5,r5,r27
	ctx.r5.u64 = ctx.r5.u64 + ctx.r27.u64;
loc_880A555C:
	// mr r6,r21
	ctx.r6.u64 = ctx.r21.u64;
	// add r3,r10,r28
	ctx.r3.u64 = ctx.r10.u64 + ctx.r28.u64;
	// bl 0x881538c0
	ctx.lr = 0x880A5568;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880a5574
	if (ctx.cr6.eq) goto loc_880A5574;
	// stw r30,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r30.u32);
loc_880A5574:
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// addi r29,r29,-8
	ctx.r29.s64 = ctx.r29.s64 + -8;
	// addi r26,r26,-48
	ctx.r26.s64 = ctx.r26.s64 + -48;
	// bge 0x880a5504
	if (!ctx.cr0.lt) goto loc_880A5504;
loc_880A5584:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x88071184
	__restgprlr_19(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A558C"))) PPC_WEAK_FUNC(sub_880A558C);
PPC_FUNC_IMPL(__imp__sub_880A558C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A5590"))) PPC_WEAK_FUNC(sub_880A5590);
PPC_FUNC_IMPL(__imp__sub_880A5590) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071120
	ctx.lr = 0x880A5598;
	__savegprlr_14(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r21,-30597
	ctx.r21.s64 = -2005204992;
	// lwz r10,184(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// lwz r11,168(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// lwz r20,4(r6)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r19,0(r6)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// addi r9,r11,7
	ctx.r9.s64 = ctx.r11.s64 + 7;
	// lwz r27,12(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// stw r21,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r21.u32);
	// addi r26,r11,2
	ctx.r26.s64 = ctx.r11.s64 + 2;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addis r28,r10,2
	ctx.r28.s64 = ctx.r10.s64 + 131072;
	// bne cr6,0x880a5708
	if (!ctx.cr6.eq) goto loc_880A5708;
	// lis r8,-30597
	ctx.r8.s64 = -2005204992;
	// lwz r10,7728(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7728);
	// addi r30,r11,-1
	ctx.r30.s64 = ctx.r11.s64 + -1;
	// lwz r9,9732(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9732);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r10,9728(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9728);
	// add r29,r9,r27
	ctx.r29.u64 = ctx.r9.u64 + ctx.r27.u64;
	// li r7,160
	ctx.r7.s64 = 160;
	// lwz r11,-11984(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -11984);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r11,220(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 220);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r4,r10,r28
	ctx.r4.u64 = ctx.r10.u64 + ctx.r28.u64;
	// srawi r10,r4,16
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0xFFFF) != 0);
	ctx.r10.s64 = ctx.r4.s32 >> 16;
	// addze r10,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r10.s64 = temp.s64;
	// addi r9,r10,-160
	ctx.r9.s64 = ctx.r10.s64 + -160;
	// mulli r8,r9,240
	ctx.r8.s64 = ctx.r9.s64 * 240;
	// srawi r4,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r4.s64 = ctx.r8.s32 >> 1;
	// addze r10,r4
	temp.s64 = ctx.r4.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r10.s64 = temp.s64;
	// divw r10,r10,r7
	ctx.r10.s32 = ppc_divw(ctx.r10.s32, ctx.r7.s32);
	// addi r9,r10,160
	ctx.r9.s64 = ctx.r10.s64 + 160;
	// rlwinm r8,r9,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// subf r25,r11,r8
	ctx.r25.s64 = ctx.r8.s64 - ctx.r11.s64;
	// bne cr6,0x880a5690
	if (!ctx.cr6.eq) goto loc_880A5690;
	// lis r23,36
	ctx.r23.s64 = 2359296;
	// li r3,13570
	ctx.r3.s64 = 13570;
	// subf r4,r23,r25
	ctx.r4.s64 = ctx.r25.s64 - ctx.r23.s64;
	// bl 0x881538c0
	ctx.lr = 0x880A5650;
	sub_881538C0(ctx, base);
	// lis r7,208
	ctx.r7.s64 = 13631488;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// ori r24,r7,53456
	ctx.r24.u64 = ctx.r7.u64 | 53456;
	// beq cr6,0x880a5684
	if (ctx.cr6.eq) goto loc_880A5684;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-11932(r21)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r21.u32 + -11932);
	// oris r9,r10,518
	ctx.r9.u64 = ctx.r10.u64 | 33947648;
	// stw r24,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r24.u32);
	// addi r22,r11,1
	ctx.r22.s64 = ctx.r11.s64 + 1;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// li r3,13570
	ctx.r3.s64 = 13570;
	// stw r22,-11932(r21)
	PPC_STORE_U32(ctx.r21.u32 + -11932, ctx.r22.u32);
	// b 0x880a56d8
	goto loc_880A56D8;
loc_880A5684:
	// lwz r22,-11932(r21)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r21.u32 + -11932);
	// li r3,13570
	ctx.r3.s64 = 13570;
	// b 0x880a56d8
	goto loc_880A56D8;
loc_880A5690:
	// lis r23,32
	ctx.r23.s64 = 2097152;
	// li r3,13569
	ctx.r3.s64 = 13569;
	// subf r4,r23,r25
	ctx.r4.s64 = ctx.r25.s64 - ctx.r23.s64;
	// bl 0x881538c0
	ctx.lr = 0x880A56A0;
	sub_881538C0(ctx, base);
	// lis r7,208
	ctx.r7.s64 = 13631488;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// ori r24,r7,53456
	ctx.r24.u64 = ctx.r7.u64 | 53456;
	// beq cr6,0x880a56d0
	if (ctx.cr6.eq) goto loc_880A56D0;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-11932(r21)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r21.u32 + -11932);
	// oris r9,r10,518
	ctx.r9.u64 = ctx.r10.u64 | 33947648;
	// stw r24,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r24.u32);
	// addi r22,r11,1
	ctx.r22.s64 = ctx.r11.s64 + 1;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r22,-11932(r21)
	PPC_STORE_U32(ctx.r21.u32 + -11932, ctx.r22.u32);
	// b 0x880a56d4
	goto loc_880A56D4;
loc_880A56D0:
	// lwz r22,-11932(r21)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r21.u32 + -11932);
loc_880A56D4:
	// li r3,13569
	ctx.r3.s64 = 13569;
loc_880A56D8:
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// add r4,r25,r23
	ctx.r4.u64 = ctx.r25.u64 + ctx.r23.u64;
	// bl 0x881538c0
	ctx.lr = 0x880A56E8;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880a5708
	if (ctx.cr6.eq) goto loc_880A5708;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r11,r22,1
	ctx.r11.s64 = ctx.r22.s64 + 1;
	// oris r9,r10,1542
	ctx.r9.u64 = ctx.r10.u64 | 101056512;
	// stw r11,-11932(r21)
	PPC_STORE_U32(ctx.r21.u32 + -11932, ctx.r11.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r24,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r24.u32);
loc_880A5708:
	// lwz r11,7108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7108);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// blt cr6,0x880a5728
	if (ctx.cr6.lt) goto loc_880A5728;
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// bne cr6,0x880a5728
	if (!ctx.cr6.eq) goto loc_880A5728;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a5238
	ctx.lr = 0x880A5728;
	sub_880A5238(ctx, base);
loc_880A5728:
	// lis r11,-30682
	ctx.r11.s64 = -2010775552;
	// lwz r6,7128(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7128);
	// lwz r5,940(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 940);
	// li r29,10
	ctx.r29.s64 = 10;
	// addi r30,r11,-30156
	ctx.r30.s64 = ctx.r11.s64 + -30156;
	// rlwinm r3,r6,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r30,-168
	ctx.r11.s64 = ctx.r30.s64 + -168;
	// addi r7,r30,-168
	ctx.r7.s64 = ctx.r30.s64 + -168;
	// addi r25,r11,1
	ctx.r25.s64 = ctx.r11.s64 + 1;
	// divw r4,r5,r29
	ctx.r4.s32 = ppc_divw(ctx.r5.s32, ctx.r29.s32);
	// lwz r11,-816(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -816);
	// lwz r10,-820(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -820);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// lbzx r5,r3,r7
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r7.u32);
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// lbzx r25,r3,r25
	ctx.r25.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r25.u32);
	// addis r3,r6,1
	ctx.r3.s64 = ctx.r6.s64 + 65536;
	// extsb r5,r5
	ctx.r5.s64 = ctx.r5.s8;
	// extsb r6,r25
	ctx.r6.s64 = ctx.r25.s8;
	// add r10,r5,r10
	ctx.r10.u64 = ctx.r5.u64 + ctx.r10.u64;
	// add r6,r6,r11
	ctx.r6.u64 = ctx.r6.u64 + ctx.r11.u64;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r6,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// addi r3,r3,-26434
	ctx.r3.s64 = ctx.r3.s64 + -26434;
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// add r4,r10,r28
	ctx.r4.u64 = ctx.r10.u64 + ctx.r28.u64;
	// add r5,r11,r27
	ctx.r5.u64 = ctx.r11.u64 + ctx.r27.u64;
	// bl 0x880a51a0
	ctx.lr = 0x880A57A0;
	sub_880A51A0(ctx, base);
	// lwz r5,7284(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7284);
	// addi r25,r31,7216
	ctx.r25.s64 = ctx.r31.s64 + 7216;
	// li r18,20
	ctx.r18.s64 = 20;
	// li r24,18
	ctx.r24.s64 = 18;
	// cmpwi cr6,r5,1
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 1, ctx.xer);
	// bgt cr6,0x880a5828
	if (ctx.cr6.gt) goto loc_880A5828;
	// lwz r10,72(r25)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r25.u32 + 72);
	// lwz r11,0(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x880a5930
	if (!ctx.cr6.eq) goto loc_880A5930;
	// addi r8,r30,-96
	ctx.r8.s64 = ctx.r30.s64 + -96;
	// lwz r3,1228(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1228);
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,-604(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + -604);
	// addi r4,r8,1
	ctx.r4.s64 = ctx.r8.s64 + 1;
	// lwz r10,-600(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -600);
	// addi r8,r30,-96
	ctx.r8.s64 = ctx.r30.s64 + -96;
	// lwz r5,1224(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1224);
	// divw r6,r3,r29
	ctx.r6.s32 = ppc_divw(ctx.r3.s32, ctx.r29.s32);
	// addis r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 65536;
	// divw r5,r5,r29
	ctx.r5.s32 = ppc_divw(ctx.r5.s32, ctx.r29.s32);
	// lbzx r4,r7,r4
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r4.u32);
	// addi r3,r3,-26391
	ctx.r3.s64 = ctx.r3.s64 + -26391;
	// lbzx r11,r7,r8
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r8.u32);
	// extsb r8,r4
	ctx.r8.s64 = ctx.r4.s8;
	// extsb r7,r11
	ctx.r7.s64 = ctx.r11.s8;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 + ctx.r9.u64;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r9,r9,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// add r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 + ctx.r6.u64;
	// add r4,r9,r5
	ctx.r4.u64 = ctx.r9.u64 + ctx.r5.u64;
	// add r4,r4,r28
	ctx.r4.u64 = ctx.r4.u64 + ctx.r28.u64;
	// b 0x880a5918
	goto loc_880A5918;
loc_880A5828:
	// lwz r11,72(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 72);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a5880
	if (!ctx.cr6.eq) goto loc_880A5880;
	// lwz r10,1228(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1228);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r8,1224(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1224);
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// divw r9,r10,r29
	ctx.r9.s32 = ppc_divw(ctx.r10.s32, ctx.r29.s32);
	// lwz r11,-656(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -656);
	// lwz r10,-660(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -660);
	// divw r8,r8,r29
	ctx.r8.s32 = ppc_divw(ctx.r8.s32, ctx.r29.s32);
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// add r5,r11,r27
	ctx.r5.u64 = ctx.r11.u64 + ctx.r27.u64;
	// add r4,r10,r28
	ctx.r4.u64 = ctx.r10.u64 + ctx.r28.u64;
	// ori r3,r3,39181
	ctx.r3.u64 = ctx.r3.u64 | 39181;
	// bl 0x880a51a0
	ctx.lr = 0x880A5880;
	sub_880A51A0(ctx, base);
loc_880A5880:
	// lwz r11,72(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 72);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a58d8
	if (!ctx.cr6.eq) goto loc_880A58D8;
	// lwz r10,1324(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1324);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r8,1320(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1320);
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// divw r9,r10,r24
	ctx.r9.s32 = ppc_divw(ctx.r10.s32, ctx.r24.s32);
	// lwz r11,-672(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -672);
	// lwz r10,-676(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -676);
	// divw r8,r8,r24
	ctx.r8.s32 = ppc_divw(ctx.r8.s32, ctx.r24.s32);
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// add r5,r11,r27
	ctx.r5.u64 = ctx.r11.u64 + ctx.r27.u64;
	// add r4,r10,r28
	ctx.r4.u64 = ctx.r10.u64 + ctx.r28.u64;
	// ori r3,r3,39179
	ctx.r3.u64 = ctx.r3.u64 | 39179;
	// bl 0x880a51a0
	ctx.lr = 0x880A58D8;
	sub_880A51A0(ctx, base);
loc_880A58D8:
	// lwz r11,72(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 72);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a5930
	if (!ctx.cr6.eq) goto loc_880A5930;
	// lwz r11,-688(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -688);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r9,1420(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1420);
	// lwz r10,-692(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -692);
	// rlwinm r7,r11,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lwz r5,1416(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1416);
	// divw r8,r9,r18
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r18.s32);
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// divw r9,r5,r18
	ctx.r9.s32 = ppc_divw(ctx.r5.s32, ctx.r18.s32);
	// add r10,r8,r7
	ctx.r10.u64 = ctx.r8.u64 + ctx.r7.u64;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// ori r3,r3,39177
	ctx.r3.u64 = ctx.r3.u64 | 39177;
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + ctx.r28.u64;
loc_880A5918:
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// add r5,r10,r27
	ctx.r5.u64 = ctx.r10.u64 + ctx.r27.u64;
	// bl 0x880a51a0
	ctx.lr = 0x880A5930;
	sub_880A51A0(ctx, base);
loc_880A5930:
	// lwz r11,7372(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7372);
	// addi r25,r31,7304
	ctx.r25.s64 = ctx.r31.s64 + 7304;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bgt cr6,0x880a59b4
	if (ctx.cr6.gt) goto loc_880A59B4;
	// lwz r10,72(r25)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r25.u32 + 72);
	// lwz r11,0(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x880a5abc
	if (!ctx.cr6.eq) goto loc_880A5ABC;
	// addi r8,r30,-64
	ctx.r8.s64 = ctx.r30.s64 + -64;
	// lwz r3,1512(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1512);
	// rlwinm r6,r11,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r4,1516(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1516);
	// addi r5,r8,1
	ctx.r5.s64 = ctx.r8.s64 + 1;
	// lwz r10,-592(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -592);
	// addi r25,r30,-64
	ctx.r25.s64 = ctx.r30.s64 + -64;
	// lwz r9,-596(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + -596);
	// divw r8,r3,r29
	ctx.r8.s32 = ppc_divw(ctx.r3.s32, ctx.r29.s32);
	// addis r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 65536;
	// divw r7,r4,r29
	ctx.r7.s32 = ppc_divw(ctx.r4.s32, ctx.r29.s32);
	// lbzx r11,r6,r5
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r5.u32);
	// addi r3,r3,-26375
	ctx.r3.s64 = ctx.r3.s64 + -26375;
	// lbzx r6,r6,r25
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r25.u32);
	// extsb r5,r11
	ctx.r5.s64 = ctx.r11.s8;
	// extsb r6,r6
	ctx.r6.s64 = ctx.r6.s8;
	// add r5,r5,r10
	ctx.r5.u64 = ctx.r5.u64 + ctx.r10.u64;
	// add r4,r6,r9
	ctx.r4.u64 = ctx.r6.u64 + ctx.r9.u64;
	// rlwinm r9,r5,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// add r5,r9,r7
	ctx.r5.u64 = ctx.r9.u64 + ctx.r7.u64;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r5,r5,r27
	ctx.r5.u64 = ctx.r5.u64 + ctx.r27.u64;
	// add r4,r10,r28
	ctx.r4.u64 = ctx.r10.u64 + ctx.r28.u64;
	// b 0x880a5aa8
	goto loc_880A5AA8;
loc_880A59B4:
	// lwz r11,72(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 72);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a5a0c
	if (!ctx.cr6.eq) goto loc_880A5A0C;
	// lwz r11,-648(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -648);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r9,1516(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1516);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// lwz r10,-652(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -652);
	// rlwinm r7,r11,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lwz r5,1512(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1512);
	// divw r8,r9,r29
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r29.s32);
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// divw r9,r5,r29
	ctx.r9.s32 = ppc_divw(ctx.r5.s32, ctx.r29.s32);
	// add r10,r8,r7
	ctx.r10.u64 = ctx.r8.u64 + ctx.r7.u64;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// add r5,r10,r27
	ctx.r5.u64 = ctx.r10.u64 + ctx.r27.u64;
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + ctx.r28.u64;
	// ori r3,r3,39182
	ctx.r3.u64 = ctx.r3.u64 | 39182;
	// bl 0x880a51a0
	ctx.lr = 0x880A5A0C;
	sub_880A51A0(ctx, base);
loc_880A5A0C:
	// lwz r11,72(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 72);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a5a64
	if (!ctx.cr6.eq) goto loc_880A5A64;
	// lwz r11,-664(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -664);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r9,1612(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1612);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// lwz r10,-668(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -668);
	// rlwinm r7,r11,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lwz r5,1608(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1608);
	// divw r8,r9,r24
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r24.s32);
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// divw r9,r5,r24
	ctx.r9.s32 = ppc_divw(ctx.r5.s32, ctx.r24.s32);
	// add r10,r8,r7
	ctx.r10.u64 = ctx.r8.u64 + ctx.r7.u64;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// add r5,r10,r27
	ctx.r5.u64 = ctx.r10.u64 + ctx.r27.u64;
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + ctx.r28.u64;
	// ori r3,r3,39180
	ctx.r3.u64 = ctx.r3.u64 | 39180;
	// bl 0x880a51a0
	ctx.lr = 0x880A5A64;
	sub_880A51A0(ctx, base);
loc_880A5A64:
	// lwz r11,72(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 72);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a5abc
	if (!ctx.cr6.eq) goto loc_880A5ABC;
	// lwz r11,-680(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -680);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r9,1708(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1708);
	// lwz r10,-684(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -684);
	// rlwinm r7,r11,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lwz r5,1704(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1704);
	// divw r8,r9,r18
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r18.s32);
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// divw r9,r5,r18
	ctx.r9.s32 = ppc_divw(ctx.r5.s32, ctx.r18.s32);
	// add r10,r8,r7
	ctx.r10.u64 = ctx.r8.u64 + ctx.r7.u64;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r5,r10,r27
	ctx.r5.u64 = ctx.r10.u64 + ctx.r27.u64;
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + ctx.r28.u64;
	// ori r3,r3,39178
	ctx.r3.u64 = ctx.r3.u64 | 39178;
loc_880A5AA8:
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// bl 0x880a51a0
	ctx.lr = 0x880A5ABC;
	sub_880A51A0(ctx, base);
loc_880A5ABC:
	// lwz r11,7460(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7460);
	// addi r24,r31,7392
	ctx.r24.s64 = ctx.r31.s64 + 7392;
	// lis r21,16
	ctx.r21.s64 = 1048576;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x880a604c
	if (ctx.cr6.lt) goto loc_880A604C;
	// beq cr6,0x880a5e30
	if (ctx.cr6.eq) goto loc_880A5E30;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x880a62ec
	if (!ctx.cr6.lt) goto loc_880A62EC;
	// lwz r11,72(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 72);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a5b38
	if (!ctx.cr6.eq) goto loc_880A5B38;
	// lwz r11,-776(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -776);
	// li r9,12
	ctx.r9.s64 = 12;
	// lwz r8,1852(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1852);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r10,-780(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -780);
	// rlwinm r7,r11,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lwz r6,1848(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1848);
	// divw r8,r8,r9
	ctx.r8.s32 = ppc_divw(ctx.r8.s32, ctx.r9.s32);
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// divw r9,r6,r9
	ctx.r9.s32 = ppc_divw(ctx.r6.s32, ctx.r9.s32);
	// add r10,r8,r7
	ctx.r10.u64 = ctx.r8.u64 + ctx.r7.u64;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// add r5,r10,r27
	ctx.r5.u64 = ctx.r10.u64 + ctx.r27.u64;
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + ctx.r28.u64;
	// ori r3,r3,39045
	ctx.r3.u64 = ctx.r3.u64 | 39045;
	// bl 0x880a51a0
	ctx.lr = 0x880A5B38;
	sub_880A51A0(ctx, base);
loc_880A5B38:
	// lwz r11,-772(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -772);
	// li r9,14
	ctx.r9.s64 = 14;
	// lwz r8,1896(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1896);
	// lwz r10,-768(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -768);
	// rlwinm r7,r11,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lwz r6,1900(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1900);
	// divw r8,r8,r9
	ctx.r8.s32 = ppc_divw(ctx.r8.s32, ctx.r9.s32);
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// lwz r3,72(r24)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r24.u32 + 72);
	// divw r9,r6,r9
	ctx.r9.s32 = ppc_divw(ctx.r6.s32, ctx.r9.s32);
	// add r10,r8,r7
	ctx.r10.u64 = ctx.r8.u64 + ctx.r7.u64;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r4,r10,r28
	ctx.r4.u64 = ctx.r10.u64 + ctx.r28.u64;
	// add r5,r11,r27
	ctx.r5.u64 = ctx.r11.u64 + ctx.r27.u64;
	// stw r4,12(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12, ctx.r4.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// stw r5,16(r24)
	PPC_STORE_U32(ctx.r24.u32 + 16, ctx.r5.u32);
	// bne cr6,0x880a5b9c
	if (!ctx.cr6.eq) goto loc_880A5B9C;
	// lis r3,0
	ctx.r3.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// ori r3,r3,39044
	ctx.r3.u64 = ctx.r3.u64 | 39044;
	// bl 0x880a51a0
	ctx.lr = 0x880A5B9C;
	sub_880A51A0(ctx, base);
loc_880A5B9C:
	// lwz r9,48(r24)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r24.u32 + 48);
	// addi r11,r9,-190
	ctx.r11.s64 = ctx.r9.s64 + -190;
	// srawi r10,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 2;
	// addze r8,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r8.s64 = temp.s64;
	// subfic r3,r8,32
	ctx.xer.ca = ctx.r8.u32 <= 32;
	ctx.r3.s64 = 32 - ctx.r8.s64;
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,22
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 22, ctx.xer);
	// ble cr6,0x880a5bc0
	if (!ctx.cr6.gt) goto loc_880A5BC0;
	// li r3,22
	ctx.r3.s64 = 22;
loc_880A5BC0:
	// addi r8,r30,-468
	ctx.r8.s64 = ctx.r30.s64 + -468;
	// lwz r11,-760(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -760);
	// rlwinm r6,r3,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,-764(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -764);
	// addi r5,r8,1
	ctx.r5.s64 = ctx.r8.s64 + 1;
	// clrlwi r8,r9,23
	ctx.r8.u64 = ctx.r9.u32 & 0x1FF;
	// addi r4,r30,-468
	ctx.r4.s64 = ctx.r30.s64 + -468;
	// addi r23,r8,128
	ctx.r23.s64 = ctx.r8.s64 + 128;
	// lis r7,-30714
	ctx.r7.s64 = -2012872704;
	// lbzx r8,r6,r5
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r5.u32);
	// rlwinm r5,r9,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x7FC;
	// addi r25,r7,9552
	ctx.r25.s64 = ctx.r7.s64 + 9552;
	// extsb r8,r8
	ctx.r8.s64 = ctx.r8.s8;
	// lbzx r4,r6,r4
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r4.u32);
	// rlwinm r6,r23,2,21,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 2) & 0x7FC;
	// add r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 + ctx.r11.u64;
	// extsb r8,r4
	ctx.r8.s64 = ctx.r4.s8;
	// addi r4,r7,8
	ctx.r4.s64 = ctx.r7.s64 + 8;
	// lwzx r23,r5,r25
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r25.u32);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// lwzx r5,r6,r25
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r25.u32);
	// rlwinm r6,r4,9,0,22
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 9) & 0xFFFFFE00;
	// rlwinm r7,r8,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r8,r23,7,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 7) & 0xFFFFFF80;
	// add r5,r6,r5
	ctx.r5.u64 = ctx.r6.u64 + ctx.r5.u64;
	// add r6,r7,r8
	ctx.r6.u64 = ctx.r7.u64 + ctx.r8.u64;
	// rlwinm r7,r5,7,0,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 7) & 0xFFFFFF80;
	// li r23,3
	ctx.r23.s64 = 3;
	// add r4,r6,r28
	ctx.r4.u64 = ctx.r6.u64 + ctx.r28.u64;
	// add r5,r7,r27
	ctx.r5.u64 = ctx.r7.u64 + ctx.r27.u64;
	// cmpwi cr6,r9,256
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 256, ctx.xer);
	// ble cr6,0x880a5c4c
	if (!ctx.cr6.gt) goto loc_880A5C4C;
	// rlwinm r9,r8,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// divw r9,r9,r23
	ctx.r9.s32 = ppc_divw(ctx.r9.s32, ctx.r23.s32);
	// add r4,r9,r4
	ctx.r4.u64 = ctx.r9.u64 + ctx.r4.u64;
loc_880A5C4C:
	// lwz r9,72(r24)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r24.u32 + 72);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x880a5c94
	if (!ctx.cr6.eq) goto loc_880A5C94;
	// lwz r10,1948(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1948);
	// li r11,17
	ctx.r11.s64 = 17;
	// lwz r8,1944(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1944);
	// addis r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 65536;
	// divw r10,r10,r11
	ctx.r10.s32 = ppc_divw(ctx.r10.s32, ctx.r11.s32);
	// divw r11,r8,r11
	ctx.r11.s32 = ppc_divw(ctx.r8.s32, ctx.r11.s32);
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// add r5,r10,r5
	ctx.r5.u64 = ctx.r10.u64 + ctx.r5.u64;
	// add r4,r11,r4
	ctx.r4.u64 = ctx.r11.u64 + ctx.r4.u64;
	// addi r3,r3,-26566
	ctx.r3.s64 = ctx.r3.s64 + -26566;
	// bl 0x880a51a0
	ctx.lr = 0x880A5C8C;
	sub_880A51A0(ctx, base);
	// lwz r11,-760(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -760);
	// lwz r10,-764(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -764);
loc_880A5C94:
	// lwz r9,48(r24)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r24.u32 + 48);
	// rlwinm r7,r11,7,0,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 7) & 0xFFFFFF80;
	// lwz r8,1992(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1992);
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// clrlwi r11,r9,23
	ctx.r11.u64 = ctx.r9.u32 & 0x1FF;
	// lwz r6,1996(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1996);
	// addi r5,r11,128
	ctx.r5.s64 = ctx.r11.s64 + 128;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r3,r5,2,21,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x7FC;
	// divw r11,r8,r29
	ctx.r11.s32 = ppc_divw(ctx.r8.s32, ctx.r29.s32);
	// divw r8,r6,r29
	ctx.r8.s32 = ppc_divw(ctx.r6.s32, ctx.r29.s32);
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwzx r11,r4,r25
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r25.u32);
	// lwzx r9,r3,r25
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r25.u32);
	// rlwinm r11,r11,9,0,22
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 9) & 0xFFFFFE00;
	// add r7,r9,r7
	ctx.r7.u64 = ctx.r9.u64 + ctx.r7.u64;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r10,r7,9,0,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 9) & 0xFFFFFE00;
	// rlwinm r6,r11,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r11,r9,r28
	ctx.r11.u64 = ctx.r9.u64 + ctx.r28.u64;
	// add r10,r10,r27
	ctx.r10.u64 = ctx.r10.u64 + ctx.r27.u64;
	// divw r9,r6,r23
	ctx.r9.s32 = ppc_divw(ctx.r6.s32, ctx.r23.s32);
	// subf r5,r21,r10
	ctx.r5.s64 = ctx.r10.s64 - ctx.r21.s64;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stw r5,10192(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10192, ctx.r5.u32);
	// stw r9,10188(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10188, ctx.r9.u32);
	// lwz r4,48(r24)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r24.u32 + 48);
	// cmpwi cr6,r4,256
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 256, ctx.xer);
	// ble cr6,0x880a5d10
	if (!ctx.cr6.gt) goto loc_880A5D10;
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
loc_880A5D10:
	// lwz r9,72(r24)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r24.u32 + 72);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x880a5db0
	if (!ctx.cr6.eq) goto loc_880A5DB0;
	// addi r9,r30,-348
	ctx.r9.s64 = ctx.r30.s64 + -348;
	// rlwinm r5,r22,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r4,r30,-348
	ctx.r4.s64 = ctx.r30.s64 + -348;
	// addi r3,r9,1
	ctx.r3.s64 = ctx.r9.s64 + 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// lbzx r4,r5,r4
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r4.u32);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// lbzx r3,r5,r3
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r3.u32);
	// extsb r5,r4
	ctx.r5.s64 = ctx.r4.s8;
	// extsb r4,r3
	ctx.r4.s64 = ctx.r3.s8;
	// rlwinm r5,r5,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r3,r4,16,0,15
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r5,r11
	ctx.r4.u64 = ctx.r5.u64 + ctx.r11.u64;
	// add r5,r3,r10
	ctx.r5.u64 = ctx.r3.u64 + ctx.r10.u64;
	// addis r3,r22,1
	ctx.r3.s64 = ctx.r22.s64 + 65536;
	// addi r3,r3,-26525
	ctx.r3.s64 = ctx.r3.s64 + -26525;
	// bl 0x880a51a0
	ctx.lr = 0x880A5D68;
	sub_880A51A0(ctx, base);
	// lwz r3,10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10236);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// bne cr6,0x880a5d8c
	if (!ctx.cr6.eq) goto loc_880A5D8C;
	// addi r7,r31,10240
	ctx.r7.s64 = ctx.r31.s64 + 10240;
	// lwz r5,10192(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10192);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// lwz r4,10188(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10188);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a4f48
	ctx.lr = 0x880A5D8C;
	sub_880A4F48(ctx, base);
loc_880A5D8C:
	// lwz r11,10236(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10236);
	// cmpwi cr6,r11,9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 9, ctx.xer);
	// bne cr6,0x880a5db0
	if (!ctx.cr6.eq) goto loc_880A5DB0;
	// addi r7,r31,10240
	ctx.r7.s64 = ctx.r31.s64 + 10240;
	// lwz r5,10192(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10192);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// lwz r4,10188(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10188);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a4f48
	ctx.lr = 0x880A5DB0;
	sub_880A4F48(ctx, base);
loc_880A5DB0:
	// lwz r11,-756(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -756);
	// lwz r10,-752(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -752);
	// lwz r7,1800(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1800);
	// rlwinm r8,r11,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lwz r6,1804(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1804);
	// rlwinm r9,r10,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// divw r11,r7,r29
	ctx.r11.s32 = ppc_divw(ctx.r7.s32, ctx.r29.s32);
	// lwz r3,0(r24)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// divw r10,r6,r29
	ctx.r10.s32 = ppc_divw(ctx.r6.s32, ctx.r29.s32);
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// add r10,r10,r27
	ctx.r10.u64 = ctx.r10.u64 + ctx.r27.u64;
	// stw r11,10164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10164, ctx.r11.u32);
	// stw r10,10168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10168, ctx.r10.u32);
	// lwz r5,72(r24)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r24.u32 + 72);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne cr6,0x880a62ec
	if (!ctx.cr6.eq) goto loc_880A62EC;
	// addi r9,r30,-400
	ctx.r9.s64 = ctx.r30.s64 + -400;
	// rlwinm r5,r3,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r4,r30,-400
	ctx.r4.s64 = ctx.r30.s64 + -400;
	// addi r25,r9,1
	ctx.r25.s64 = ctx.r9.s64 + 1;
	// addis r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 65536;
	// lbzx r4,r5,r4
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r4.u32);
	// lbzx r5,r5,r25
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r25.u32);
	// extsb r4,r4
	ctx.r4.s64 = ctx.r4.s8;
	// extsb r25,r5
	ctx.r25.s64 = ctx.r5.s8;
	// rlwinm r5,r4,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r25,r25,16,0,15
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r5,r11
	ctx.r4.u64 = ctx.r5.u64 + ctx.r11.u64;
	// add r5,r25,r10
	ctx.r5.u64 = ctx.r25.u64 + ctx.r10.u64;
	// b 0x880a62d4
	goto loc_880A62D4;
loc_880A5E30:
	// lwz r11,72(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 72);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a5e90
	if (!ctx.cr6.eq) goto loc_880A5E90;
	// lwz r11,-776(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -776);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r9,1852(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1852);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// lwz r8,1848(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1848);
	// rlwinm r7,r11,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lwz r10,-780(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -780);
	// divw r9,r9,r29
	ctx.r9.s32 = ppc_divw(ctx.r9.s32, ctx.r29.s32);
	// divw r11,r8,r29
	ctx.r11.s32 = ppc_divw(ctx.r8.s32, ctx.r29.s32);
	// lwz r8,256(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 256);
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r10,r9,r8
	ctx.r10.u64 = ctx.r9.u64 + ctx.r8.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// add r5,r10,r27
	ctx.r5.u64 = ctx.r10.u64 + ctx.r27.u64;
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + ctx.r28.u64;
	// ori r3,r3,39045
	ctx.r3.u64 = ctx.r3.u64 | 39045;
	// bl 0x880a51a0
	ctx.lr = 0x880A5E90;
	sub_880A51A0(ctx, base);
loc_880A5E90:
	// lwz r11,72(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 72);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a5ef0
	if (!ctx.cr6.eq) goto loc_880A5EF0;
	// lwz r11,-768(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -768);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r9,1900(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1900);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// lwz r8,1896(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1896);
	// rlwinm r7,r11,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lwz r10,-772(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -772);
	// divw r9,r9,r29
	ctx.r9.s32 = ppc_divw(ctx.r9.s32, ctx.r29.s32);
	// divw r11,r8,r29
	ctx.r11.s32 = ppc_divw(ctx.r8.s32, ctx.r29.s32);
	// lwz r8,256(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 256);
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r10,r9,r8
	ctx.r10.u64 = ctx.r9.u64 + ctx.r8.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// add r5,r10,r27
	ctx.r5.u64 = ctx.r10.u64 + ctx.r27.u64;
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + ctx.r28.u64;
	// ori r3,r3,39044
	ctx.r3.u64 = ctx.r3.u64 | 39044;
	// bl 0x880a51a0
	ctx.lr = 0x880A5EF0;
	sub_880A51A0(ctx, base);
loc_880A5EF0:
	// lwz r11,72(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 72);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a5f68
	if (!ctx.cr6.eq) goto loc_880A5F68;
	// lbz r11,-435(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + -435);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lbz r10,-436(r30)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r30.u32 + -436);
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// lwz r9,-760(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + -760);
	// extsb r8,r11
	ctx.r8.s64 = ctx.r11.s8;
	// lwz r11,-764(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -764);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// add r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lwz r5,1948(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1948);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r25,1944(r31)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1944);
	// divw r9,r5,r29
	ctx.r9.s32 = ppc_divw(ctx.r5.s32, ctx.r29.s32);
	// lwz r8,256(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 256);
	// rlwinm r10,r6,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r4,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// divw r9,r25,r29
	ctx.r9.s32 = ppc_divw(ctx.r25.s32, ctx.r29.s32);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// add r5,r10,r27
	ctx.r5.u64 = ctx.r10.u64 + ctx.r27.u64;
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + ctx.r28.u64;
	// ori r3,r3,38986
	ctx.r3.u64 = ctx.r3.u64 | 38986;
	// bl 0x880a51a0
	ctx.lr = 0x880A5F68;
	sub_880A51A0(ctx, base);
loc_880A5F68:
	// lbz r11,-315(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + -315);
	// lwz r10,-744(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -744);
	// extsb r9,r11
	ctx.r9.s64 = ctx.r11.s8;
	// lbz r11,-316(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + -316);
	// lwz r8,1996(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1996);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r10,-748(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -748);
	// extsb r7,r11
	ctx.r7.s64 = ctx.r11.s8;
	// lwz r5,1992(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1992);
	// divw r8,r8,r29
	ctx.r8.s32 = ppc_divw(ctx.r8.s32, ctx.r29.s32);
	// lwz r9,256(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 256);
	// rlwinm r11,r6,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r7,r10
	ctx.r4.u64 = ctx.r7.u64 + ctx.r10.u64;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// divw r8,r5,r29
	ctx.r8.s32 = ppc_divw(ctx.r5.s32, ctx.r29.s32);
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r5,r11,r9
	ctx.r5.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r4,r10,r28
	ctx.r4.u64 = ctx.r10.u64 + ctx.r28.u64;
	// subf r3,r21,r5
	ctx.r3.s64 = ctx.r5.s64 - ctx.r21.s64;
	// stw r4,10188(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10188, ctx.r4.u32);
	// stw r3,10192(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10192, ctx.r3.u32);
	// lwz r11,72(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 72);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a6034
	if (!ctx.cr6.eq) goto loc_880A6034;
	// lis r3,0
	ctx.r3.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// ori r3,r3,39027
	ctx.r3.u64 = ctx.r3.u64 | 39027;
	// bl 0x880a51a0
	ctx.lr = 0x880A5FEC;
	sub_880A51A0(ctx, base);
	// lwz r11,10236(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10236);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x880a6010
	if (!ctx.cr6.eq) goto loc_880A6010;
	// addi r7,r31,10240
	ctx.r7.s64 = ctx.r31.s64 + 10240;
	// lwz r5,10192(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10192);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// lwz r4,10188(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10188);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a4f48
	ctx.lr = 0x880A6010;
	sub_880A4F48(ctx, base);
loc_880A6010:
	// lwz r11,10236(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10236);
	// cmpwi cr6,r11,9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 9, ctx.xer);
	// bne cr6,0x880a6034
	if (!ctx.cr6.eq) goto loc_880A6034;
	// addi r7,r31,10240
	ctx.r7.s64 = ctx.r31.s64 + 10240;
	// lwz r5,10192(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10192);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// lwz r4,10188(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10188);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a4f48
	ctx.lr = 0x880A6034;
	sub_880A4F48(ctx, base);
loc_880A6034:
	// lwz r11,-756(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -756);
	// lwz r10,-752(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -752);
	// rlwinm r8,r11,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r9,r10,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r10,r8,r28
	ctx.r10.u64 = ctx.r8.u64 + ctx.r28.u64;
	// b 0x880a6264
	goto loc_880A6264;
loc_880A604C:
	// lwz r11,72(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 72);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a60ac
	if (!ctx.cr6.eq) goto loc_880A60AC;
	// lwz r11,-776(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -776);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r9,1852(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1852);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// lwz r8,1848(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1848);
	// rlwinm r7,r11,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lwz r10,-780(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -780);
	// divw r9,r9,r29
	ctx.r9.s32 = ppc_divw(ctx.r9.s32, ctx.r29.s32);
	// divw r11,r8,r29
	ctx.r11.s32 = ppc_divw(ctx.r8.s32, ctx.r29.s32);
	// lwz r8,256(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 256);
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r10,r9,r8
	ctx.r10.u64 = ctx.r9.u64 + ctx.r8.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// add r5,r10,r27
	ctx.r5.u64 = ctx.r10.u64 + ctx.r27.u64;
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + ctx.r28.u64;
	// ori r3,r3,39045
	ctx.r3.u64 = ctx.r3.u64 | 39045;
	// bl 0x880a51a0
	ctx.lr = 0x880A60AC;
	sub_880A51A0(ctx, base);
loc_880A60AC:
	// lwz r11,72(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 72);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a610c
	if (!ctx.cr6.eq) goto loc_880A610C;
	// lwz r11,-768(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -768);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r9,1900(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1900);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// lwz r8,1896(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1896);
	// rlwinm r7,r11,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lwz r10,-772(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -772);
	// divw r9,r9,r29
	ctx.r9.s32 = ppc_divw(ctx.r9.s32, ctx.r29.s32);
	// divw r11,r8,r29
	ctx.r11.s32 = ppc_divw(ctx.r8.s32, ctx.r29.s32);
	// lwz r8,256(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 256);
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r10,r9,r8
	ctx.r10.u64 = ctx.r9.u64 + ctx.r8.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// add r5,r10,r27
	ctx.r5.u64 = ctx.r10.u64 + ctx.r27.u64;
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + ctx.r28.u64;
	// ori r3,r3,39044
	ctx.r3.u64 = ctx.r3.u64 | 39044;
	// bl 0x880a51a0
	ctx.lr = 0x880A610C;
	sub_880A51A0(ctx, base);
loc_880A610C:
	// lwz r11,72(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 72);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a6184
	if (!ctx.cr6.eq) goto loc_880A6184;
	// lbz r11,-435(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + -435);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lbz r10,-436(r30)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r30.u32 + -436);
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// lwz r9,-760(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + -760);
	// extsb r8,r11
	ctx.r8.s64 = ctx.r11.s8;
	// lwz r11,-764(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -764);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// add r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lwz r5,1948(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1948);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r25,1944(r31)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1944);
	// divw r9,r5,r29
	ctx.r9.s32 = ppc_divw(ctx.r5.s32, ctx.r29.s32);
	// lwz r8,256(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 256);
	// rlwinm r10,r6,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r4,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// divw r9,r25,r29
	ctx.r9.s32 = ppc_divw(ctx.r25.s32, ctx.r29.s32);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// add r5,r10,r27
	ctx.r5.u64 = ctx.r10.u64 + ctx.r27.u64;
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + ctx.r28.u64;
	// ori r3,r3,38986
	ctx.r3.u64 = ctx.r3.u64 | 38986;
	// bl 0x880a51a0
	ctx.lr = 0x880A6184;
	sub_880A51A0(ctx, base);
loc_880A6184:
	// lbz r11,-315(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + -315);
	// lwz r10,-744(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -744);
	// extsb r9,r11
	ctx.r9.s64 = ctx.r11.s8;
	// lwz r8,1996(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1996);
	// lbz r11,-316(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + -316);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r10,-748(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -748);
	// divw r7,r8,r29
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r29.s32);
	// lwz r9,256(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 256);
	// rlwinm r8,r6,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// lwz r4,1992(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1992);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// extsb r7,r11
	ctx.r7.s64 = ctx.r11.s8;
	// add r11,r8,r27
	ctx.r11.u64 = ctx.r8.u64 + ctx.r27.u64;
	// add r3,r7,r10
	ctx.r3.u64 = ctx.r7.u64 + ctx.r10.u64;
	// add r5,r11,r9
	ctx.r5.u64 = ctx.r11.u64 + ctx.r9.u64;
	// divw r10,r4,r29
	ctx.r10.s32 = ppc_divw(ctx.r4.s32, ctx.r29.s32);
	// rlwinm r11,r3,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 16) & 0xFFFF0000;
	// subf r9,r21,r5
	ctx.r9.s64 = ctx.r5.s64 - ctx.r21.s64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r9,10192(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10192, ctx.r9.u32);
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + ctx.r28.u64;
	// stw r4,10188(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10188, ctx.r4.u32);
	// lwz r8,72(r24)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r24.u32 + 72);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x880a6250
	if (!ctx.cr6.eq) goto loc_880A6250;
	// lis r3,0
	ctx.r3.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// ori r3,r3,39027
	ctx.r3.u64 = ctx.r3.u64 | 39027;
	// bl 0x880a51a0
	ctx.lr = 0x880A6208;
	sub_880A51A0(ctx, base);
	// lwz r11,10236(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10236);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x880a622c
	if (!ctx.cr6.eq) goto loc_880A622C;
	// addi r7,r31,10240
	ctx.r7.s64 = ctx.r31.s64 + 10240;
	// lwz r5,10192(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10192);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// lwz r4,10188(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10188);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a4f48
	ctx.lr = 0x880A622C;
	sub_880A4F48(ctx, base);
loc_880A622C:
	// lwz r11,10236(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10236);
	// cmpwi cr6,r11,9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 9, ctx.xer);
	// bne cr6,0x880a6250
	if (!ctx.cr6.eq) goto loc_880A6250;
	// addi r7,r31,10240
	ctx.r7.s64 = ctx.r31.s64 + 10240;
	// lwz r5,10192(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10192);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// lwz r4,10188(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10188);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a4f48
	ctx.lr = 0x880A6250;
	sub_880A4F48(ctx, base);
loc_880A6250:
	// lwz r10,-756(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -756);
	// lwz r11,-752(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -752);
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r9,r11,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// add r10,r10,r28
	ctx.r10.u64 = ctx.r10.u64 + ctx.r28.u64;
loc_880A6264:
	// add r9,r9,r27
	ctx.r9.u64 = ctx.r9.u64 + ctx.r27.u64;
	// lwz r11,0(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// stw r10,10164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10164, ctx.r10.u32);
	// stw r9,10168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10168, ctx.r9.u32);
	// lwz r8,72(r24)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r24.u32 + 72);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x880a62ec
	if (!ctx.cr6.eq) goto loc_880A62EC;
	// addi r8,r30,-400
	ctx.r8.s64 = ctx.r30.s64 + -400;
	// lwz r7,1804(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1804);
	// rlwinm r4,r11,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r6,1800(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1800);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lwz r3,256(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 256);
	// addi r25,r30,-400
	ctx.r25.s64 = ctx.r30.s64 + -400;
	// divw r5,r7,r29
	ctx.r5.s32 = ppc_divw(ctx.r7.s32, ctx.r29.s32);
	// divw r6,r6,r29
	ctx.r6.s32 = ppc_divw(ctx.r6.s32, ctx.r29.s32);
	// lbzx r7,r4,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r8.u32);
	// lbzx r4,r4,r25
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r25.u32);
	// extsb r8,r7
	ctx.r8.s64 = ctx.r7.s8;
	// extsb r7,r4
	ctx.r7.s64 = ctx.r4.s8;
	// rlwinm r8,r8,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r7,r7,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// add r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 + ctx.r5.u64;
	// add r4,r7,r6
	ctx.r4.u64 = ctx.r7.u64 + ctx.r6.u64;
	// add r5,r8,r9
	ctx.r5.u64 = ctx.r8.u64 + ctx.r9.u64;
	// add r4,r4,r10
	ctx.r4.u64 = ctx.r4.u64 + ctx.r10.u64;
	// add r5,r5,r3
	ctx.r5.u64 = ctx.r5.u64 + ctx.r3.u64;
	// addis r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 65536;
loc_880A62D4:
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// addi r3,r3,-26533
	ctx.r3.s64 = ctx.r3.s64 + -26533;
	// bl 0x880a51a0
	ctx.lr = 0x880A62EC;
	sub_880A51A0(ctx, base);
loc_880A62EC:
	// lwz r10,7552(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7552);
	// addi r25,r31,7480
	ctx.r25.s64 = ctx.r31.s64 + 7480;
	// lwz r11,7480(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7480);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x880a637c
	if (!ctx.cr6.eq) goto loc_880A637C;
	// addi r9,r30,-280
	ctx.r9.s64 = ctx.r30.s64 + -280;
	// lwz r3,2088(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2088);
	// rlwinm r5,r11,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r4,2092(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2092);
	// addi r24,r9,1
	ctx.r24.s64 = ctx.r9.s64 + 1;
	// lwz r10,-736(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -736);
	// addi r23,r30,-280
	ctx.r23.s64 = ctx.r30.s64 + -280;
	// lwz r9,-740(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + -740);
	// divw r7,r3,r29
	ctx.r7.s32 = ppc_divw(ctx.r3.s32, ctx.r29.s32);
	// lwz r8,260(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 260);
	// addis r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 65536;
	// divw r6,r4,r29
	ctx.r6.s32 = ppc_divw(ctx.r4.s32, ctx.r29.s32);
	// lbzx r11,r5,r24
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r24.u32);
	// addi r3,r3,-26490
	ctx.r3.s64 = ctx.r3.s64 + -26490;
	// lbzx r5,r5,r23
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r23.u32);
	// extsb r4,r11
	ctx.r4.s64 = ctx.r11.s8;
	// extsb r5,r5
	ctx.r5.s64 = ctx.r5.s8;
	// add r4,r4,r10
	ctx.r4.u64 = ctx.r4.u64 + ctx.r10.u64;
	// add r11,r5,r9
	ctx.r11.u64 = ctx.r5.u64 + ctx.r9.u64;
	// rlwinm r9,r4,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r11,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// add r9,r9,r6
	ctx.r9.u64 = ctx.r9.u64 + ctx.r6.u64;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// add r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 + ctx.r8.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// add r5,r5,r27
	ctx.r5.u64 = ctx.r5.u64 + ctx.r27.u64;
	// add r4,r10,r28
	ctx.r4.u64 = ctx.r10.u64 + ctx.r28.u64;
	// bl 0x880a51a0
	ctx.lr = 0x880A637C;
	sub_880A51A0(ctx, base);
loc_880A637C:
	// lis r11,-30682
	ctx.r11.s64 = -2010775552;
	// lwz r10,7636(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7636);
	// lis r9,0
	ctx.r9.s64 = 0;
	// addi r23,r11,-30340
	ctx.r23.s64 = ctx.r11.s64 + -30340;
	// ori r22,r9,39094
	ctx.r22.u64 = ctx.r9.u64 | 39094;
	// stw r23,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r23.u32);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x880a6424
	if (!ctx.cr6.eq) goto loc_880A6424;
	// stw r26,2944(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2944, ctx.r26.u32);
	// addi r10,r23,1
	ctx.r10.s64 = ctx.r23.s64 + 1;
	// lwz r3,7640(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7640);
	// lwz r11,7568(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7568);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lbzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// lbzx r8,r9,r23
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r23.u32);
	// addi r4,r10,4
	ctx.r4.s64 = ctx.r10.s64 + 4;
	// lwz r10,2284(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2284);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// lwz r9,2280(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2280);
	// extsb r7,r8
	ctx.r7.s64 = ctx.r8.s8;
	// divw r8,r10,r29
	ctx.r8.s32 = ppc_divw(ctx.r10.s32, ctx.r29.s32);
	// lwz r6,300(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 300);
	// divw r5,r9,r29
	ctx.r5.s32 = ppc_divw(ctx.r9.s32, ctx.r29.s32);
	// lwz r9,304(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 304);
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r7,r7,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r7,r7,r5
	ctx.r7.u64 = ctx.r7.u64 + ctx.r5.u64;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r8,r7,r6
	ctx.r8.u64 = ctx.r7.u64 + ctx.r6.u64;
	// add r5,r10,r27
	ctx.r5.u64 = ctx.r10.u64 + ctx.r27.u64;
	// add r4,r8,r28
	ctx.r4.u64 = ctx.r8.u64 + ctx.r28.u64;
	// stw r5,7584(r31)
	PPC_STORE_U32(ctx.r31.u32 + 7584, ctx.r5.u32);
	// stw r4,7580(r31)
	PPC_STORE_U32(ctx.r31.u32 + 7580, ctx.r4.u32);
	// bne cr6,0x880a6424
	if (!ctx.cr6.eq) goto loc_880A6424;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// add r3,r11,r22
	ctx.r3.u64 = ctx.r11.u64 + ctx.r22.u64;
	// bl 0x880a51a0
	ctx.lr = 0x880A6424;
	sub_880A51A0(ctx, base);
loc_880A6424:
	// lwz r11,0(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// addi r8,r30,-232
	ctx.r8.s64 = ctx.r30.s64 + -232;
	// addi r6,r30,-232
	ctx.r6.s64 = ctx.r30.s64 + -232;
	// lwz r9,-728(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + -728);
	// rlwinm r5,r11,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,-732(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -732);
	// addi r4,r8,1
	ctx.r4.s64 = ctx.r8.s64 + 1;
	// lwz r3,2284(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2284);
	// lwz r8,260(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 260);
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// divw r7,r3,r29
	ctx.r7.s32 = ppc_divw(ctx.r3.s32, ctx.r29.s32);
	// lwz r3,2280(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2280);
	// lbzx r6,r5,r6
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r6.u32);
	// lbzx r4,r5,r4
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r4.u32);
	// extsb r5,r6
	ctx.r5.s64 = ctx.r6.s8;
	// extsb r6,r4
	ctx.r6.s64 = ctx.r4.s8;
	// add r5,r5,r10
	ctx.r5.u64 = ctx.r5.u64 + ctx.r10.u64;
	// add r4,r6,r9
	ctx.r4.u64 = ctx.r6.u64 + ctx.r9.u64;
	// divw r6,r3,r29
	ctx.r6.s32 = ppc_divw(ctx.r3.s32, ctx.r29.s32);
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r9,r5,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// add r9,r9,r6
	ctx.r9.u64 = ctx.r9.u64 + ctx.r6.u64;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r4,r9,r28
	ctx.r4.u64 = ctx.r9.u64 + ctx.r28.u64;
	// add r5,r10,r27
	ctx.r5.u64 = ctx.r10.u64 + ctx.r27.u64;
	// stw r4,10196(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10196, ctx.r4.u32);
	// subf r3,r21,r5
	ctx.r3.s64 = ctx.r5.s64 - ctx.r21.s64;
	// stw r3,10200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10200, ctx.r3.u32);
	// lwz r10,72(r25)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r25.u32 + 72);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x880a6508
	if (!ctx.cr6.eq) goto loc_880A6508;
	// addis r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 65536;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// addi r3,r3,-26466
	ctx.r3.s64 = ctx.r3.s64 + -26466;
	// bl 0x880a51a0
	ctx.lr = 0x880A64C0;
	sub_880A51A0(ctx, base);
	// lwz r11,10236(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10236);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x880a64e4
	if (!ctx.cr6.eq) goto loc_880A64E4;
	// addi r7,r31,10240
	ctx.r7.s64 = ctx.r31.s64 + 10240;
	// lwz r5,10200(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10200);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// lwz r4,10196(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10196);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a4f48
	ctx.lr = 0x880A64E4;
	sub_880A4F48(ctx, base);
loc_880A64E4:
	// lwz r11,10236(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10236);
	// cmpwi cr6,r11,9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 9, ctx.xer);
	// bne cr6,0x880a6508
	if (!ctx.cr6.eq) goto loc_880A6508;
	// addi r7,r31,10240
	ctx.r7.s64 = ctx.r31.s64 + 10240;
	// lwz r5,10200(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10200);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// lwz r4,10196(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10196);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a4f48
	ctx.lr = 0x880A6508;
	sub_880A4F48(ctx, base);
loc_880A6508:
	// lwz r11,7728(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7728);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a6554
	if (!ctx.cr6.eq) goto loc_880A6554;
	// lwz r11,-536(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -536);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r8,2716(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2716);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r10,-540(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -540);
	// rlwinm r7,r11,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// divw r8,r8,r29
	ctx.r8.s32 = ppc_divw(ctx.r8.s32, ctx.r29.s32);
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r10,r8,r7
	ctx.r10.u64 = ctx.r8.u64 + ctx.r7.u64;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// add r5,r10,r27
	ctx.r5.u64 = ctx.r10.u64 + ctx.r27.u64;
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + ctx.r28.u64;
	// ori r3,r3,38923
	ctx.r3.u64 = ctx.r3.u64 | 38923;
	// bl 0x880a51a0
	ctx.lr = 0x880A6554;
	sub_880A51A0(ctx, base);
loc_880A6554:
	// lwz r11,-512(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -512);
	// lwz r8,2668(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2668);
	// rlwinm r9,r11,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lwz r10,-516(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -516);
	// divw r11,r8,r29
	ctx.r11.s32 = ppc_divw(ctx.r8.s32, ctx.r29.s32);
	// lwz r3,7744(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7744);
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r4,r10,r28
	ctx.r4.u64 = ctx.r10.u64 + ctx.r28.u64;
	// add r5,r11,r27
	ctx.r5.u64 = ctx.r11.u64 + ctx.r27.u64;
	// stw r4,10092(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10092, ctx.r4.u32);
	// stw r5,10096(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10096, ctx.r5.u32);
	// lwz r7,7816(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7816);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne cr6,0x880a65d0
	if (!ctx.cr6.eq) goto loc_880A65D0;
	// addis r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 65536;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// addi r3,r3,-26587
	ctx.r3.s64 = ctx.r3.s64 + -26587;
	// bl 0x880a51a0
	ctx.lr = 0x880A65AC;
	sub_880A51A0(ctx, base);
	// lwz r11,10236(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10236);
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// bne cr6,0x880a65d0
	if (!ctx.cr6.eq) goto loc_880A65D0;
	// addi r7,r31,10240
	ctx.r7.s64 = ctx.r31.s64 + 10240;
	// lwz r5,10096(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10096);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// lwz r4,10092(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10092);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a4f48
	ctx.lr = 0x880A65D0;
	sub_880A4F48(ctx, base);
loc_880A65D0:
	// lwz r11,364(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 364);
	// addi r24,r26,2
	ctx.r24.s64 = ctx.r26.s64 + 2;
	// stw r28,6964(r31)
	PPC_STORE_U32(ctx.r31.u32 + 6964, ctx.r28.u32);
	// divw r11,r11,r29
	ctx.r11.s32 = ppc_divw(ctx.r11.s32, ctx.r29.s32);
	// add r5,r11,r27
	ctx.r5.u64 = ctx.r11.u64 + ctx.r27.u64;
	// stw r5,6968(r31)
	PPC_STORE_U32(ctx.r31.u32 + 6968, ctx.r5.u32);
	// stw r5,9744(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9744, ctx.r5.u32);
	// stw r28,9740(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9740, ctx.r28.u32);
	// lwz r10,7024(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7024);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x880a661c
	if (!ctx.cr6.eq) goto loc_880A661C;
	// lis r3,0
	ctx.r3.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// ori r3,r3,39118
	ctx.r3.u64 = ctx.r3.u64 | 39118;
	// bl 0x880a51a0
	ctx.lr = 0x880A661C;
	sub_880A51A0(ctx, base);
loc_880A661C:
	// lwz r11,7904(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7904);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a6668
	if (!ctx.cr6.eq) goto loc_880A6668;
	// lwz r11,-504(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -504);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r8,2956(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2956);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r10,-508(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -508);
	// rlwinm r7,r11,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// divw r8,r8,r29
	ctx.r8.s32 = ppc_divw(ctx.r8.s32, ctx.r29.s32);
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r10,r8,r7
	ctx.r10.u64 = ctx.r8.u64 + ctx.r7.u64;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// add r5,r10,r27
	ctx.r5.u64 = ctx.r10.u64 + ctx.r27.u64;
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + ctx.r28.u64;
	// ori r3,r3,38965
	ctx.r3.u64 = ctx.r3.u64 | 38965;
	// bl 0x880a51a0
	ctx.lr = 0x880A6668;
	sub_880A51A0(ctx, base);
loc_880A6668:
	// lwz r11,7992(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7992);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a66c0
	if (!ctx.cr6.eq) goto loc_880A66C0;
	// lwz r11,-792(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -792);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r9,3244(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 3244);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// lwz r10,-796(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -796);
	// rlwinm r7,r11,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lwz r5,3240(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 3240);
	// divw r8,r9,r29
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r29.s32);
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// divw r9,r5,r29
	ctx.r9.s32 = ppc_divw(ctx.r5.s32, ctx.r29.s32);
	// add r10,r8,r7
	ctx.r10.u64 = ctx.r8.u64 + ctx.r7.u64;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// add r5,r10,r27
	ctx.r5.u64 = ctx.r10.u64 + ctx.r27.u64;
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + ctx.r28.u64;
	// ori r3,r3,39116
	ctx.r3.u64 = ctx.r3.u64 | 39116;
	// bl 0x880a51a0
	ctx.lr = 0x880A66C0;
	sub_880A51A0(ctx, base);
loc_880A66C0:
	// lwz r11,8080(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8080);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a6718
	if (!ctx.cr6.eq) goto loc_880A6718;
	// lwz r11,-784(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -784);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r9,3532(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 3532);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// lwz r10,-788(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -788);
	// rlwinm r7,r11,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lwz r5,3528(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 3528);
	// divw r8,r9,r29
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r29.s32);
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// divw r9,r5,r29
	ctx.r9.s32 = ppc_divw(ctx.r5.s32, ctx.r29.s32);
	// add r10,r8,r7
	ctx.r10.u64 = ctx.r8.u64 + ctx.r7.u64;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// add r5,r10,r27
	ctx.r5.u64 = ctx.r10.u64 + ctx.r27.u64;
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + ctx.r28.u64;
	// ori r3,r3,39117
	ctx.r3.u64 = ctx.r3.u64 | 39117;
	// bl 0x880a51a0
	ctx.lr = 0x880A6718;
	sub_880A51A0(ctx, base);
loc_880A6718:
	// lwz r11,-812(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -812);
	// lis r26,28
	ctx.r26.s64 = 1835008;
	// lwz r10,-808(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -808);
	// lis r14,4
	ctx.r14.s64 = 262144;
	// lwz r8,3816(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 3816);
	// rlwinm r7,r11,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lwz r6,3820(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 3820);
	// rlwinm r9,r10,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// divw r8,r8,r29
	ctx.r8.s32 = ppc_divw(ctx.r8.s32, ctx.r29.s32);
	// divw r11,r6,r29
	ctx.r11.s32 = ppc_divw(ctx.r6.s32, ctx.r29.s32);
	// add r10,r8,r7
	ctx.r10.u64 = ctx.r8.u64 + ctx.r7.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r4,r10,r28
	ctx.r4.u64 = ctx.r10.u64 + ctx.r28.u64;
	// add r5,r11,r27
	ctx.r5.u64 = ctx.r11.u64 + ctx.r27.u64;
	// add r3,r4,r26
	ctx.r3.u64 = ctx.r4.u64 + ctx.r26.u64;
	// stw r4,8108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8108, ctx.r4.u32);
	// subf r11,r14,r5
	ctx.r11.s64 = ctx.r5.s64 - ctx.r14.s64;
	// stw r5,8112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8112, ctx.r5.u32);
	// stw r3,10148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10148, ctx.r3.u32);
	// stw r11,10152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10152, ctx.r11.u32);
	// lwz r10,8168(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8168);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x880a67b4
	if (!ctx.cr6.eq) goto loc_880A67B4;
	// lis r3,0
	ctx.r3.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// ori r3,r3,39114
	ctx.r3.u64 = ctx.r3.u64 | 39114;
	// bl 0x880a51a0
	ctx.lr = 0x880A6790;
	sub_880A51A0(ctx, base);
	// lwz r11,10236(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10236);
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// bne cr6,0x880a67b4
	if (!ctx.cr6.eq) goto loc_880A67B4;
	// addi r7,r31,10240
	ctx.r7.s64 = ctx.r31.s64 + 10240;
	// lwz r5,10152(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10152);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// lwz r4,10148(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10148);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a4f48
	ctx.lr = 0x880A67B4;
	sub_880A4F48(ctx, base);
loc_880A67B4:
	// lwz r10,-800(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -800);
	// lwz r8,4108(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4108);
	// lwz r11,-804(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -804);
	// rlwinm r9,r10,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// lwz r6,4104(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4104);
	// divw r10,r8,r29
	ctx.r10.s32 = ppc_divw(ctx.r8.s32, ctx.r29.s32);
	// rlwinm r7,r11,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// divw r8,r6,r29
	ctx.r8.s32 = ppc_divw(ctx.r6.s32, ctx.r29.s32);
	// add r11,r10,r9
	ctx.r11.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r10,r8,r7
	ctx.r10.u64 = ctx.r8.u64 + ctx.r7.u64;
	// add r5,r11,r27
	ctx.r5.u64 = ctx.r11.u64 + ctx.r27.u64;
	// add r4,r10,r28
	ctx.r4.u64 = ctx.r10.u64 + ctx.r28.u64;
	// subf r3,r14,r5
	ctx.r3.s64 = ctx.r5.s64 - ctx.r14.s64;
	// stw r5,8200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8200, ctx.r5.u32);
	// subf r11,r26,r4
	ctx.r11.s64 = ctx.r4.s64 - ctx.r26.s64;
	// stw r4,8196(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8196, ctx.r4.u32);
	// stw r3,10160(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10160, ctx.r3.u32);
	// stw r11,10156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10156, ctx.r11.u32);
	// lwz r10,8256(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8256);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x880a6848
	if (!ctx.cr6.eq) goto loc_880A6848;
	// lis r3,0
	ctx.r3.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// ori r3,r3,39115
	ctx.r3.u64 = ctx.r3.u64 | 39115;
	// bl 0x880a51a0
	ctx.lr = 0x880A6824;
	sub_880A51A0(ctx, base);
	// lwz r11,10236(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10236);
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// bne cr6,0x880a6848
	if (!ctx.cr6.eq) goto loc_880A6848;
	// addi r7,r31,10240
	ctx.r7.s64 = ctx.r31.s64 + 10240;
	// lwz r5,10160(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10160);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// lwz r4,10156(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10156);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a4f48
	ctx.lr = 0x880A6848;
	sub_880A4F48(ctx, base);
loc_880A6848:
	// lwz r11,-528(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -528);
	// lwz r10,-532(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -532);
	// rlwinm r9,r11,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lwz r8,2380(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2380);
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + ctx.r28.u64;
	// divw r11,r8,r29
	ctx.r11.s32 = ppc_divw(ctx.r8.s32, ctx.r29.s32);
	// addis r7,r4,-74
	ctx.r7.s64 = ctx.r4.s64 + -4849664;
	// stw r4,7668(r31)
	PPC_STORE_U32(ctx.r31.u32 + 7668, ctx.r4.u32);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addis r6,r4,72
	ctx.r6.s64 = ctx.r4.s64 + 4718592;
	// add r5,r11,r27
	ctx.r5.u64 = ctx.r11.u64 + ctx.r27.u64;
	// stw r5,7672(r31)
	PPC_STORE_U32(ctx.r31.u32 + 7672, ctx.r5.u32);
	// add r3,r5,r14
	ctx.r3.u64 = ctx.r5.u64 + ctx.r14.u64;
	// stw r7,10076(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10076, ctx.r7.u32);
	// stw r3,10080(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10080, ctx.r3.u32);
	// stw r6,10084(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10084, ctx.r6.u32);
	// stw r3,10088(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10088, ctx.r3.u32);
	// lwz r11,7728(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7728);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a6900
	if (!ctx.cr6.eq) goto loc_880A6900;
	// lis r3,0
	ctx.r3.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// ori r3,r3,38922
	ctx.r3.u64 = ctx.r3.u64 | 38922;
	// bl 0x880a51a0
	ctx.lr = 0x880A68B8;
	sub_880A51A0(ctx, base);
	// lwz r11,10236(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10236);
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// bne cr6,0x880a68dc
	if (!ctx.cr6.eq) goto loc_880A68DC;
	// addi r7,r31,10240
	ctx.r7.s64 = ctx.r31.s64 + 10240;
	// lwz r5,10080(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10080);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// lwz r4,10076(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10076);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a4f48
	ctx.lr = 0x880A68DC;
	sub_880A4F48(ctx, base);
loc_880A68DC:
	// lwz r11,10236(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10236);
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// bne cr6,0x880a6900
	if (!ctx.cr6.eq) goto loc_880A6900;
	// addi r7,r31,10240
	ctx.r7.s64 = ctx.r31.s64 + 10240;
	// lwz r5,10088(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10088);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// lwz r4,10084(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10084);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a4f48
	ctx.lr = 0x880A6900;
	sub_880A4F48(ctx, base);
loc_880A6900:
	// lwz r11,7636(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7636);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a6988
	if (!ctx.cr6.eq) goto loc_880A6988;
	// stw r24,2944(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2944, ctx.r24.u32);
	// addi r10,r23,1
	ctx.r10.s64 = ctx.r23.s64 + 1;
	// lwz r9,2956(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2956);
	// lwz r7,300(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 300);
	// divw r6,r9,r29
	ctx.r6.s32 = ppc_divw(ctx.r9.s32, ctx.r29.s32);
	// lwz r8,304(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 304);
	// lwz r11,7568(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7568);
	// lwz r5,7640(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7640);
	// rlwinm r4,r11,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// lbzx r9,r4,r23
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r23.u32);
	// lbzx r3,r4,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r10.u32);
	// extsb r10,r3
	ctx.r10.s64 = ctx.r3.s8;
	// addi r5,r10,4
	ctx.r5.s64 = ctx.r10.s64 + 4;
	// extsb r4,r9
	ctx.r4.s64 = ctx.r9.s8;
	// rlwinm r10,r5,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r9,r4,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// add r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 + ctx.r6.u64;
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r4,r9,r28
	ctx.r4.u64 = ctx.r9.u64 + ctx.r28.u64;
	// add r5,r10,r27
	ctx.r5.u64 = ctx.r10.u64 + ctx.r27.u64;
	// stw r4,7580(r31)
	PPC_STORE_U32(ctx.r31.u32 + 7580, ctx.r4.u32);
	// stw r5,7584(r31)
	PPC_STORE_U32(ctx.r31.u32 + 7584, ctx.r5.u32);
	// bne cr6,0x880a6988
	if (!ctx.cr6.eq) goto loc_880A6988;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// add r3,r11,r22
	ctx.r3.u64 = ctx.r11.u64 + ctx.r22.u64;
	// bl 0x880a51a0
	ctx.lr = 0x880A6988;
	sub_880A51A0(ctx, base);
loc_880A6988:
	// lwz r11,8696(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8696);
	// addi r26,r31,8624
	ctx.r26.s64 = ctx.r31.s64 + 8624;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a69d8
	if (!ctx.cr6.eq) goto loc_880A69D8;
	// lwz r11,-696(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -696);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r8,6124(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 6124);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r10,-700(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -700);
	// rlwinm r7,r11,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// divw r8,r8,r29
	ctx.r8.s32 = ppc_divw(ctx.r8.s32, ctx.r29.s32);
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r10,r8,r7
	ctx.r10.u64 = ctx.r8.u64 + ctx.r7.u64;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// add r5,r10,r27
	ctx.r5.u64 = ctx.r10.u64 + ctx.r27.u64;
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + ctx.r28.u64;
	// ori r3,r3,39144
	ctx.r3.u64 = ctx.r3.u64 | 39144;
	// bl 0x880a51a0
	ctx.lr = 0x880A69D8;
	sub_880A51A0(ctx, base);
loc_880A69D8:
	// lwz r11,72(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 72);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a6a30
	if (!ctx.cr6.eq) goto loc_880A6A30;
	// lwz r10,6844(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 6844);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r8,6268(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 6268);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// lwz r11,-704(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -704);
	// divw r9,r10,r18
	ctx.r9.s32 = ppc_divw(ctx.r10.s32, ctx.r18.s32);
	// divw r7,r8,r29
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r29.s32);
	// lwz r10,-708(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -708);
	// rlwinm r8,r11,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r10,r9,r8
	ctx.r10.u64 = ctx.r9.u64 + ctx.r8.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// add r5,r10,r27
	ctx.r5.u64 = ctx.r10.u64 + ctx.r27.u64;
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + ctx.r28.u64;
	// ori r3,r3,39143
	ctx.r3.u64 = ctx.r3.u64 | 39143;
	// bl 0x880a51a0
	ctx.lr = 0x880A6A30;
	sub_880A51A0(ctx, base);
loc_880A6A30:
	// lwz r11,8780(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8780);
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r17,r31,8712
	ctx.r17.s64 = ctx.r31.s64 + 8712;
	// ori r15,r10,39131
	ctx.r15.u64 = ctx.r10.u64 | 39131;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a6b3c
	if (!ctx.cr6.eq) goto loc_880A6B3C;
	// lwz r25,0(r17)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r17.u32 + 0);
	// addi r9,r30,-144
	ctx.r9.s64 = ctx.r30.s64 + -144;
	// addi r8,r30,-144
	ctx.r8.s64 = ctx.r30.s64 + -144;
	// lwz r11,-720(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -720);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// lwz r10,-724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -724);
	// rlwinm r26,r25,1,0,30
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r6,2956(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2956);
	// lwz r5,72(r17)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r17.u32 + 72);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// lbzx r4,r26,r7
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r26.u32 + ctx.r7.u32);
	// lbzx r3,r26,r8
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r26.u32 + ctx.r8.u32);
	// extsb r8,r4
	ctx.r8.s64 = ctx.r4.s8;
	// extsb r9,r3
	ctx.r9.s64 = ctx.r3.s8;
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r8,r11,-6
	ctx.r8.s64 = ctx.r11.s64 + -6;
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// divw r9,r6,r29
	ctx.r9.s32 = ppc_divw(ctx.r6.s32, ctx.r29.s32);
	// rlwinm r10,r8,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + ctx.r28.u64;
	// add r11,r10,r9
	ctx.r11.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r4,12(r17)
	PPC_STORE_U32(ctx.r17.u32 + 12, ctx.r4.u32);
	// add r5,r11,r27
	ctx.r5.u64 = ctx.r11.u64 + ctx.r27.u64;
	// stw r5,16(r17)
	PPC_STORE_U32(ctx.r17.u32 + 16, ctx.r5.u32);
	// bne cr6,0x880a6acc
	if (!ctx.cr6.eq) goto loc_880A6ACC;
	// addis r3,r25,1
	ctx.r3.s64 = ctx.r25.s64 + 65536;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// addi r3,r3,-26417
	ctx.r3.s64 = ctx.r3.s64 + -26417;
	// bl 0x880a51a0
	ctx.lr = 0x880A6ACC;
	sub_880A51A0(ctx, base);
loc_880A6ACC:
	// lwz r11,72(r17)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r17.u32 + 72);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a6b3c
	if (!ctx.cr6.eq) goto loc_880A6B3C;
	// addi r11,r30,-120
	ctx.r11.s64 = ctx.r30.s64 + -120;
	// lwz r6,2956(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2956);
	// addi r7,r30,-120
	ctx.r7.s64 = ctx.r30.s64 + -120;
	// lwz r10,-712(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -712);
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// lwz r11,-716(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -716);
	// divw r5,r6,r29
	ctx.r5.s32 = ppc_divw(ctx.r6.s32, ctx.r29.s32);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// lbzx r7,r26,r7
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r26.u32 + ctx.r7.u32);
	// add r3,r25,r15
	ctx.r3.u64 = ctx.r25.u64 + ctx.r15.u64;
	// lbzx r4,r26,r4
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r26.u32 + ctx.r4.u32);
	// extsb r6,r7
	ctx.r6.s64 = ctx.r7.s8;
	// extsb r7,r4
	ctx.r7.s64 = ctx.r4.s8;
	// add r6,r6,r11
	ctx.r6.u64 = ctx.r6.u64 + ctx.r11.u64;
	// add r11,r7,r10
	ctx.r11.u64 = ctx.r7.u64 + ctx.r10.u64;
	// rlwinm r10,r6,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// addi r4,r11,-6
	ctx.r4.s64 = ctx.r11.s64 + -6;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// rlwinm r11,r4,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// add r4,r10,r28
	ctx.r4.u64 = ctx.r10.u64 + ctx.r28.u64;
	// add r5,r11,r27
	ctx.r5.u64 = ctx.r11.u64 + ctx.r27.u64;
	// bl 0x880a51a0
	ctx.lr = 0x880A6B3C;
	sub_880A51A0(ctx, base);
loc_880A6B3C:
	// lwz r11,8344(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8344);
	// addi r26,r31,8272
	ctx.r26.s64 = ctx.r31.s64 + 8272;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a6b98
	if (!ctx.cr6.eq) goto loc_880A6B98;
	// lwz r11,-480(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -480);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r9,5548(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5548);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// lwz r10,-484(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -484);
	// rlwinm r7,r11,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lwz r5,5544(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5544);
	// divw r8,r9,r29
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r29.s32);
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// divw r9,r5,r29
	ctx.r9.s32 = ppc_divw(ctx.r5.s32, ctx.r29.s32);
	// add r10,r8,r7
	ctx.r10.u64 = ctx.r8.u64 + ctx.r7.u64;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// add r5,r10,r27
	ctx.r5.u64 = ctx.r10.u64 + ctx.r27.u64;
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + ctx.r28.u64;
	// ori r3,r3,38968
	ctx.r3.u64 = ctx.r3.u64 | 38968;
	// bl 0x880a51a0
	ctx.lr = 0x880A6B98;
	sub_880A51A0(ctx, base);
loc_880A6B98:
	// lwz r11,-588(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -588);
	// lis r21,6
	ctx.r21.s64 = 393216;
	// lwz r10,-584(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -584);
	// lis r16,15
	ctx.r16.s64 = 983040;
	// lwz r9,4392(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4392);
	// rlwinm r8,r11,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lwz r7,4396(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4396);
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// divw r10,r9,r29
	ctx.r10.s32 = ppc_divw(ctx.r9.s32, ctx.r29.s32);
	// divw r9,r7,r29
	ctx.r9.s32 = ppc_divw(ctx.r7.s32, ctx.r29.s32);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r4,r10,r28
	ctx.r4.u64 = ctx.r10.u64 + ctx.r28.u64;
	// add r5,r11,r27
	ctx.r5.u64 = ctx.r11.u64 + ctx.r27.u64;
	// stw r4,12(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12, ctx.r4.u32);
	// stw r5,16(r26)
	PPC_STORE_U32(ctx.r26.u32 + 16, ctx.r5.u32);
	// stw r5,10120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10120, ctx.r5.u32);
	// stw r4,10116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10116, ctx.r4.u32);
	// lwz r6,72(r26)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r26.u32 + 72);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne cr6,0x880a6d1c
	if (!ctx.cr6.eq) goto loc_880A6D1C;
	// lis r3,0
	ctx.r3.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// ori r3,r3,39236
	ctx.r3.u64 = ctx.r3.u64 | 39236;
	// bl 0x880a51a0
	ctx.lr = 0x880A6C08;
	sub_880A51A0(ctx, base);
	// lwz r11,10236(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10236);
	// cmpwi cr6,r11,9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 9, ctx.xer);
	// bne cr6,0x880a6c34
	if (!ctx.cr6.eq) goto loc_880A6C34;
	// lwz r11,10120(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10120);
	// addi r7,r31,10240
	ctx.r7.s64 = ctx.r31.s64 + 10240;
	// lwz r10,10116(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10116);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// add r5,r11,r21
	ctx.r5.u64 = ctx.r11.u64 + ctx.r21.u64;
	// subf r4,r16,r10
	ctx.r4.s64 = ctx.r10.s64 - ctx.r16.s64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a4f48
	ctx.lr = 0x880A6C34;
	sub_880A4F48(ctx, base);
loc_880A6C34:
	// lwz r11,10236(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10236);
	// lis r22,9
	ctx.r22.s64 = 589824;
	// cmpwi cr6,r11,9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 9, ctx.xer);
	// bne cr6,0x880a6c64
	if (!ctx.cr6.eq) goto loc_880A6C64;
	// lwz r11,10120(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10120);
	// addi r7,r31,10240
	ctx.r7.s64 = ctx.r31.s64 + 10240;
	// lwz r10,10116(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10116);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// subf r5,r22,r11
	ctx.r5.s64 = ctx.r11.s64 - ctx.r22.s64;
	// subf r4,r21,r10
	ctx.r4.s64 = ctx.r10.s64 - ctx.r21.s64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a4f48
	ctx.lr = 0x880A6C64;
	sub_880A4F48(ctx, base);
loc_880A6C64:
	// lwz r11,10236(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10236);
	// lis r23,22
	ctx.r23.s64 = 1441792;
	// lis r25,8
	ctx.r25.s64 = 524288;
	// cmpwi cr6,r11,9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 9, ctx.xer);
	// bne cr6,0x880a6c98
	if (!ctx.cr6.eq) goto loc_880A6C98;
	// lwz r11,10120(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10120);
	// addi r7,r31,10240
	ctx.r7.s64 = ctx.r31.s64 + 10240;
	// lwz r10,10116(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10116);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// subf r5,r23,r11
	ctx.r5.s64 = ctx.r11.s64 - ctx.r23.s64;
	// add r4,r10,r25
	ctx.r4.u64 = ctx.r10.u64 + ctx.r25.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a4f48
	ctx.lr = 0x880A6C98;
	sub_880A4F48(ctx, base);
loc_880A6C98:
	// lwz r11,10236(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10236);
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// bne cr6,0x880a6cc4
	if (!ctx.cr6.eq) goto loc_880A6CC4;
	// lwz r11,10120(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10120);
	// addi r7,r31,10240
	ctx.r7.s64 = ctx.r31.s64 + 10240;
	// lwz r10,10116(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10116);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// add r5,r11,r21
	ctx.r5.u64 = ctx.r11.u64 + ctx.r21.u64;
	// subf r4,r16,r10
	ctx.r4.s64 = ctx.r10.s64 - ctx.r16.s64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a4f48
	ctx.lr = 0x880A6CC4;
	sub_880A4F48(ctx, base);
loc_880A6CC4:
	// lwz r11,10236(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10236);
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// bne cr6,0x880a6cf0
	if (!ctx.cr6.eq) goto loc_880A6CF0;
	// lwz r11,10120(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10120);
	// addi r7,r31,10240
	ctx.r7.s64 = ctx.r31.s64 + 10240;
	// lwz r10,10116(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10116);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// subf r5,r22,r11
	ctx.r5.s64 = ctx.r11.s64 - ctx.r22.s64;
	// subf r4,r21,r10
	ctx.r4.s64 = ctx.r10.s64 - ctx.r21.s64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a4f48
	ctx.lr = 0x880A6CF0;
	sub_880A4F48(ctx, base);
loc_880A6CF0:
	// lwz r11,10236(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10236);
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// bne cr6,0x880a6d1c
	if (!ctx.cr6.eq) goto loc_880A6D1C;
	// lwz r11,10120(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10120);
	// addi r7,r31,10240
	ctx.r7.s64 = ctx.r31.s64 + 10240;
	// lwz r10,10116(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10116);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// subf r5,r23,r11
	ctx.r5.s64 = ctx.r11.s64 - ctx.r23.s64;
	// add r4,r10,r25
	ctx.r4.u64 = ctx.r10.u64 + ctx.r25.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a4f48
	ctx.lr = 0x880A6D1C;
	sub_880A4F48(ctx, base);
loc_880A6D1C:
	// lwz r11,-572(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -572);
	// lwz r9,4392(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4392);
	// rlwinm r10,r11,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lwz r11,-568(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -568);
	// divw r9,r9,r29
	ctx.r9.s32 = ppc_divw(ctx.r9.s32, ctx.r29.s32);
	// lwz r8,4396(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4396);
	// lwz r3,0(r26)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r10,r11,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r9,r28
	ctx.r11.u64 = ctx.r9.u64 + ctx.r28.u64;
	// divw r9,r8,r29
	ctx.r9.s32 = ppc_divw(ctx.r8.s32, ctx.r29.s32);
	// addis r7,r11,-42
	ctx.r7.s64 = ctx.r11.s64 + -2752512;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r7,10132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10132, ctx.r7.u32);
	// add r10,r10,r27
	ctx.r10.u64 = ctx.r10.u64 + ctx.r27.u64;
	// stw r10,10136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10136, ctx.r10.u32);
	// lwz r6,72(r26)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r26.u32 + 72);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne cr6,0x880a6db4
	if (!ctx.cr6.eq) goto loc_880A6DB4;
	// addi r9,r30,-32
	ctx.r9.s64 = ctx.r30.s64 + -32;
	// rlwinm r5,r3,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r4,r30,-32
	ctx.r4.s64 = ctx.r30.s64 + -32;
	// addi r26,r9,1
	ctx.r26.s64 = ctx.r9.s64 + 1;
	// addis r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 65536;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// lbzx r4,r5,r4
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r4.u32);
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// lbzx r5,r5,r26
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r26.u32);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// extsb r4,r4
	ctx.r4.s64 = ctx.r4.s8;
	// extsb r26,r5
	ctx.r26.s64 = ctx.r5.s8;
	// rlwinm r5,r4,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r26,r26,16,0,15
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r5,r11
	ctx.r4.u64 = ctx.r5.u64 + ctx.r11.u64;
	// addi r3,r3,-26332
	ctx.r3.s64 = ctx.r3.s64 + -26332;
	// add r5,r26,r10
	ctx.r5.u64 = ctx.r26.u64 + ctx.r10.u64;
	// bl 0x880a51a0
	ctx.lr = 0x880A6DB4;
	sub_880A51A0(ctx, base);
loc_880A6DB4:
	// lwz r11,8432(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8432);
	// addi r26,r31,8360
	ctx.r26.s64 = ctx.r31.s64 + 8360;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a6e10
	if (!ctx.cr6.eq) goto loc_880A6E10;
	// lwz r11,-472(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -472);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r9,5836(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5836);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// lwz r10,-476(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -476);
	// rlwinm r7,r11,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lwz r5,5832(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5832);
	// divw r8,r9,r29
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r29.s32);
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// divw r9,r5,r29
	ctx.r9.s32 = ppc_divw(ctx.r5.s32, ctx.r29.s32);
	// add r10,r8,r7
	ctx.r10.u64 = ctx.r8.u64 + ctx.r7.u64;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// add r5,r10,r27
	ctx.r5.u64 = ctx.r10.u64 + ctx.r27.u64;
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + ctx.r28.u64;
	// ori r3,r3,38969
	ctx.r3.u64 = ctx.r3.u64 | 38969;
	// bl 0x880a51a0
	ctx.lr = 0x880A6E10;
	sub_880A51A0(ctx, base);
loc_880A6E10:
	// lwz r11,-580(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -580);
	// lis r18,14
	ctx.r18.s64 = 917504;
	// lwz r10,-576(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -576);
	// lwz r9,4680(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4680);
	// rlwinm r8,r11,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lwz r7,4684(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4684);
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// divw r10,r9,r29
	ctx.r10.s32 = ppc_divw(ctx.r9.s32, ctx.r29.s32);
	// divw r9,r7,r29
	ctx.r9.s32 = ppc_divw(ctx.r7.s32, ctx.r29.s32);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r4,r10,r28
	ctx.r4.u64 = ctx.r10.u64 + ctx.r28.u64;
	// add r5,r11,r27
	ctx.r5.u64 = ctx.r11.u64 + ctx.r27.u64;
	// stw r4,12(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12, ctx.r4.u32);
	// stw r5,16(r26)
	PPC_STORE_U32(ctx.r26.u32 + 16, ctx.r5.u32);
	// stw r5,10128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10128, ctx.r5.u32);
	// stw r4,10124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10124, ctx.r4.u32);
	// lwz r6,72(r26)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r26.u32 + 72);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne cr6,0x880a6f90
	if (!ctx.cr6.eq) goto loc_880A6F90;
	// lis r3,0
	ctx.r3.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// ori r3,r3,39237
	ctx.r3.u64 = ctx.r3.u64 | 39237;
	// bl 0x880a51a0
	ctx.lr = 0x880A6E7C;
	sub_880A51A0(ctx, base);
	// lwz r11,10236(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10236);
	// lis r22,1
	ctx.r22.s64 = 65536;
	// cmpwi cr6,r11,9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 9, ctx.xer);
	// bne cr6,0x880a6eac
	if (!ctx.cr6.eq) goto loc_880A6EAC;
	// lwz r11,10128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10128);
	// addi r7,r31,10240
	ctx.r7.s64 = ctx.r31.s64 + 10240;
	// lwz r10,10124(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10124);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// add r5,r11,r22
	ctx.r5.u64 = ctx.r11.u64 + ctx.r22.u64;
	// addis r4,r10,16
	ctx.r4.s64 = ctx.r10.s64 + 1048576;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a4f48
	ctx.lr = 0x880A6EAC;
	sub_880A4F48(ctx, base);
loc_880A6EAC:
	// lwz r11,10236(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10236);
	// cmpwi cr6,r11,9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 9, ctx.xer);
	// bne cr6,0x880a6ed8
	if (!ctx.cr6.eq) goto loc_880A6ED8;
	// lwz r11,10128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10128);
	// addi r7,r31,10240
	ctx.r7.s64 = ctx.r31.s64 + 10240;
	// lwz r10,10124(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10124);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// subf r5,r18,r11
	ctx.r5.s64 = ctx.r11.s64 - ctx.r18.s64;
	// add r4,r10,r21
	ctx.r4.u64 = ctx.r10.u64 + ctx.r21.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a4f48
	ctx.lr = 0x880A6ED8;
	sub_880A4F48(ctx, base);
loc_880A6ED8:
	// lwz r11,10236(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10236);
	// lis r23,27
	ctx.r23.s64 = 1769472;
	// lis r25,7
	ctx.r25.s64 = 458752;
	// cmpwi cr6,r11,9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 9, ctx.xer);
	// bne cr6,0x880a6f0c
	if (!ctx.cr6.eq) goto loc_880A6F0C;
	// lwz r11,10128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10128);
	// addi r7,r31,10240
	ctx.r7.s64 = ctx.r31.s64 + 10240;
	// lwz r10,10124(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10124);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// subf r5,r23,r11
	ctx.r5.s64 = ctx.r11.s64 - ctx.r23.s64;
	// subf r4,r25,r10
	ctx.r4.s64 = ctx.r10.s64 - ctx.r25.s64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a4f48
	ctx.lr = 0x880A6F0C;
	sub_880A4F48(ctx, base);
loc_880A6F0C:
	// lwz r11,10236(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10236);
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// bne cr6,0x880a6f38
	if (!ctx.cr6.eq) goto loc_880A6F38;
	// lwz r11,10128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10128);
	// addi r7,r31,10240
	ctx.r7.s64 = ctx.r31.s64 + 10240;
	// lwz r10,10124(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10124);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// add r5,r11,r22
	ctx.r5.u64 = ctx.r11.u64 + ctx.r22.u64;
	// addis r4,r10,16
	ctx.r4.s64 = ctx.r10.s64 + 1048576;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a4f48
	ctx.lr = 0x880A6F38;
	sub_880A4F48(ctx, base);
loc_880A6F38:
	// lwz r11,10236(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10236);
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// bne cr6,0x880a6f64
	if (!ctx.cr6.eq) goto loc_880A6F64;
	// lwz r11,10128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10128);
	// addi r7,r31,10240
	ctx.r7.s64 = ctx.r31.s64 + 10240;
	// lwz r10,10124(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10124);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// subf r5,r18,r11
	ctx.r5.s64 = ctx.r11.s64 - ctx.r18.s64;
	// add r4,r10,r21
	ctx.r4.u64 = ctx.r10.u64 + ctx.r21.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a4f48
	ctx.lr = 0x880A6F64;
	sub_880A4F48(ctx, base);
loc_880A6F64:
	// lwz r11,10236(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10236);
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// bne cr6,0x880a6f90
	if (!ctx.cr6.eq) goto loc_880A6F90;
	// lwz r11,10128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10128);
	// addi r7,r31,10240
	ctx.r7.s64 = ctx.r31.s64 + 10240;
	// lwz r10,10124(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10124);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// subf r5,r23,r11
	ctx.r5.s64 = ctx.r11.s64 - ctx.r23.s64;
	// subf r4,r25,r10
	ctx.r4.s64 = ctx.r10.s64 - ctx.r25.s64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a4f48
	ctx.lr = 0x880A6F90;
	sub_880A4F48(ctx, base);
loc_880A6F90:
	// lwz r11,-564(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -564);
	// lwz r9,4680(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4680);
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lwz r10,-560(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -560);
	// divw r9,r9,r29
	ctx.r9.s32 = ppc_divw(ctx.r9.s32, ctx.r29.s32);
	// lwz r8,4684(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4684);
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// lwz r3,0(r26)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// divw r9,r8,r29
	ctx.r9.s32 = ppc_divw(ctx.r8.s32, ctx.r29.s32);
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// addis r7,r11,46
	ctx.r7.s64 = ctx.r11.s64 + 3014656;
	// add r10,r10,r27
	ctx.r10.u64 = ctx.r10.u64 + ctx.r27.u64;
	// stw r7,10140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10140, ctx.r7.u32);
	// stw r10,10144(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10144, ctx.r10.u32);
	// lwz r6,72(r26)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r26.u32 + 72);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne cr6,0x880a7020
	if (!ctx.cr6.eq) goto loc_880A7020;
	// rlwinm r5,r3,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r4,r30,1
	ctx.r4.s64 = ctx.r30.s64 + 1;
	// addis r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 65536;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// lbzx r26,r5,r30
	ctx.r26.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r30.u32);
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// lbzx r5,r5,r4
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r4.u32);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// extsb r4,r26
	ctx.r4.s64 = ctx.r26.s8;
	// extsb r26,r5
	ctx.r26.s64 = ctx.r5.s8;
	// rlwinm r5,r4,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r26,r26,16,0,15
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r5,r11
	ctx.r4.u64 = ctx.r5.u64 + ctx.r11.u64;
	// addi r3,r3,-26316
	ctx.r3.s64 = ctx.r3.s64 + -26316;
	// add r5,r26,r10
	ctx.r5.u64 = ctx.r26.u64 + ctx.r10.u64;
	// bl 0x880a51a0
	ctx.lr = 0x880A7020;
	sub_880A51A0(ctx, base);
loc_880A7020:
	// lwz r10,-488(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -488);
	// lis r26,24
	ctx.r26.s64 = 1572864;
	// lwz r8,4972(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4972);
	// lwz r11,-492(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -492);
	// rlwinm r9,r10,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// lwz r6,4968(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4968);
	// divw r10,r8,r29
	ctx.r10.s32 = ppc_divw(ctx.r8.s32, ctx.r29.s32);
	// rlwinm r7,r11,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// divw r8,r6,r29
	ctx.r8.s32 = ppc_divw(ctx.r6.s32, ctx.r29.s32);
	// add r11,r10,r9
	ctx.r11.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r10,r8,r7
	ctx.r10.u64 = ctx.r8.u64 + ctx.r7.u64;
	// add r5,r11,r27
	ctx.r5.u64 = ctx.r11.u64 + ctx.r27.u64;
	// add r4,r10,r28
	ctx.r4.u64 = ctx.r10.u64 + ctx.r28.u64;
	// add r3,r5,r14
	ctx.r3.u64 = ctx.r5.u64 + ctx.r14.u64;
	// stw r5,8464(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8464, ctx.r5.u32);
	// stw r4,8460(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8460, ctx.r4.u32);
	// addis r11,r4,-11
	ctx.r11.s64 = ctx.r4.s64 + -720896;
	// stw r3,10064(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10064, ctx.r3.u32);
	// stw r11,10060(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10060, ctx.r11.u32);
	// lwz r10,8520(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8520);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x880a7110
	if (!ctx.cr6.eq) goto loc_880A7110;
	// lis r3,0
	ctx.r3.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// ori r3,r3,38966
	ctx.r3.u64 = ctx.r3.u64 | 38966;
	// bl 0x880a51a0
	ctx.lr = 0x880A7094;
	sub_880A51A0(ctx, base);
	// lwz r11,10236(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10236);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x880a70c0
	if (!ctx.cr6.eq) goto loc_880A70C0;
	// lwz r11,10064(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10064);
	// addi r7,r31,10240
	ctx.r7.s64 = ctx.r31.s64 + 10240;
	// lwz r10,10060(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10060);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// add r5,r11,r18
	ctx.r5.u64 = ctx.r11.u64 + ctx.r18.u64;
	// subf r4,r26,r10
	ctx.r4.s64 = ctx.r10.s64 - ctx.r26.s64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a4f48
	ctx.lr = 0x880A70C0;
	sub_880A4F48(ctx, base);
loc_880A70C0:
	// lwz r11,10236(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10236);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x880a70e4
	if (!ctx.cr6.eq) goto loc_880A70E4;
	// addi r7,r31,10240
	ctx.r7.s64 = ctx.r31.s64 + 10240;
	// lwz r5,10064(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10064);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// lwz r4,10060(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10060);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a4f48
	ctx.lr = 0x880A70E4;
	sub_880A4F48(ctx, base);
loc_880A70E4:
	// lwz r11,10236(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10236);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x880a7110
	if (!ctx.cr6.eq) goto loc_880A7110;
	// lwz r11,10064(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10064);
	// addi r7,r31,10240
	ctx.r7.s64 = ctx.r31.s64 + 10240;
	// lwz r10,10060(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10060);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// subf r5,r18,r11
	ctx.r5.s64 = ctx.r11.s64 - ctx.r18.s64;
	// add r4,r10,r26
	ctx.r4.u64 = ctx.r10.u64 + ctx.r26.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a4f48
	ctx.lr = 0x880A7110;
	sub_880A4F48(ctx, base);
loc_880A7110:
	// lwz r11,-500(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -500);
	// lwz r9,5256(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5256);
	// lwz r10,-496(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -496);
	// rlwinm r7,r11,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lwz r6,5260(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5260);
	// divw r8,r9,r29
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r29.s32);
	// rlwinm r9,r10,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// divw r11,r6,r29
	ctx.r11.s32 = ppc_divw(ctx.r6.s32, ctx.r29.s32);
	// add r10,r8,r7
	ctx.r10.u64 = ctx.r8.u64 + ctx.r7.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r4,r10,r28
	ctx.r4.u64 = ctx.r10.u64 + ctx.r28.u64;
	// add r5,r11,r27
	ctx.r5.u64 = ctx.r11.u64 + ctx.r27.u64;
	// add r3,r4,r16
	ctx.r3.u64 = ctx.r4.u64 + ctx.r16.u64;
	// stw r4,8548(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8548, ctx.r4.u32);
	// add r11,r5,r14
	ctx.r11.u64 = ctx.r5.u64 + ctx.r14.u64;
	// stw r5,8552(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8552, ctx.r5.u32);
	// stw r3,10068(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10068, ctx.r3.u32);
	// stw r11,10072(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10072, ctx.r11.u32);
	// lwz r10,8608(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8608);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x880a71fc
	if (!ctx.cr6.eq) goto loc_880A71FC;
	// lis r3,0
	ctx.r3.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// ori r3,r3,38967
	ctx.r3.u64 = ctx.r3.u64 | 38967;
	// bl 0x880a51a0
	ctx.lr = 0x880A7180;
	sub_880A51A0(ctx, base);
	// lwz r11,10236(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10236);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x880a71ac
	if (!ctx.cr6.eq) goto loc_880A71AC;
	// lwz r11,10072(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10072);
	// addi r7,r31,10240
	ctx.r7.s64 = ctx.r31.s64 + 10240;
	// lwz r10,10068(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10068);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// add r5,r11,r18
	ctx.r5.u64 = ctx.r11.u64 + ctx.r18.u64;
	// add r4,r10,r26
	ctx.r4.u64 = ctx.r10.u64 + ctx.r26.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a4f48
	ctx.lr = 0x880A71AC;
	sub_880A4F48(ctx, base);
loc_880A71AC:
	// lwz r11,10236(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10236);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x880a71d0
	if (!ctx.cr6.eq) goto loc_880A71D0;
	// addi r7,r31,10240
	ctx.r7.s64 = ctx.r31.s64 + 10240;
	// lwz r5,10072(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10072);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// lwz r4,10068(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10068);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a4f48
	ctx.lr = 0x880A71D0;
	sub_880A4F48(ctx, base);
loc_880A71D0:
	// lwz r11,10236(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10236);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x880a71fc
	if (!ctx.cr6.eq) goto loc_880A71FC;
	// lwz r11,10072(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10072);
	// addi r7,r31,10240
	ctx.r7.s64 = ctx.r31.s64 + 10240;
	// lwz r10,10068(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10068);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// subf r5,r18,r11
	ctx.r5.s64 = ctx.r11.s64 - ctx.r18.s64;
	// subf r4,r26,r10
	ctx.r4.s64 = ctx.r10.s64 - ctx.r26.s64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a4f48
	ctx.lr = 0x880A71FC;
	sub_880A4F48(ctx, base);
loc_880A71FC:
	// lwz r11,68(r17)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r17.u32 + 68);
	// lis r23,2
	ctx.r23.s64 = 131072;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// blt cr6,0x880a7374
	if (ctx.cr6.lt) goto loc_880A7374;
	// lwz r25,0(r17)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r17.u32 + 0);
	// addi r9,r30,-144
	ctx.r9.s64 = ctx.r30.s64 + -144;
	// addi r7,r30,-144
	ctx.r7.s64 = ctx.r30.s64 + -144;
	// lwz r11,-720(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -720);
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// lwz r10,-724(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -724);
	// rlwinm r26,r25,1,0,30
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r5,6412(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 6412);
	// lwz r4,6700(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 6700);
	// divw r8,r5,r29
	ctx.r8.s32 = ppc_divw(ctx.r5.s32, ctx.r29.s32);
	// lbzx r3,r26,r6
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r26.u32 + ctx.r6.u32);
	// lbzx r9,r26,r7
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r26.u32 + ctx.r7.u32);
	// extsb r7,r3
	ctx.r7.s64 = ctx.r3.s8;
	// extsb r9,r9
	ctx.r9.s64 = ctx.r9.s8;
	// add r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 + ctx.r11.u64;
	// add r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r6,r11,-4
	ctx.r6.s64 = ctx.r11.s64 + -4;
	// rlwinm r11,r7,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r6,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// divw r9,r4,r29
	ctx.r9.s32 = ppc_divw(ctx.r4.s32, ctx.r29.s32);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + ctx.r28.u64;
	// add r11,r10,r9
	ctx.r11.u64 = ctx.r10.u64 + ctx.r9.u64;
	// subf r3,r23,r4
	ctx.r3.s64 = ctx.r4.s64 - ctx.r23.s64;
	// add r5,r11,r27
	ctx.r5.u64 = ctx.r11.u64 + ctx.r27.u64;
	// stw r3,10172(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10172, ctx.r3.u32);
	// addis r11,r5,-20
	ctx.r11.s64 = ctx.r5.s64 + -1310720;
	// stw r11,10176(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10176, ctx.r11.u32);
	// stw r4,12(r17)
	PPC_STORE_U32(ctx.r17.u32 + 12, ctx.r4.u32);
	// stw r5,16(r17)
	PPC_STORE_U32(ctx.r17.u32 + 16, ctx.r5.u32);
	// lwz r10,72(r17)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r17.u32 + 72);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x880a72ac
	if (!ctx.cr6.eq) goto loc_880A72AC;
	// addis r3,r25,1
	ctx.r3.s64 = ctx.r25.s64 + 65536;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// addi r3,r3,-26417
	ctx.r3.s64 = ctx.r3.s64 + -26417;
	// bl 0x880a51a0
	ctx.lr = 0x880A72AC;
	sub_880A51A0(ctx, base);
loc_880A72AC:
	// lwz r11,72(r17)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r17.u32 + 72);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880a7374
	if (!ctx.cr6.eq) goto loc_880A7374;
	// addi r11,r30,-120
	ctx.r11.s64 = ctx.r30.s64 + -120;
	// lwz r8,6412(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 6412);
	// addi r9,r30,-120
	ctx.r9.s64 = ctx.r30.s64 + -120;
	// lwz r10,-712(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -712);
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// lwz r4,6700(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 6700);
	// divw r7,r8,r29
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r29.s32);
	// lwz r11,-716(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -716);
	// divw r6,r4,r29
	ctx.r6.s32 = ppc_divw(ctx.r4.s32, ctx.r29.s32);
	// add r3,r25,r15
	ctx.r3.u64 = ctx.r25.u64 + ctx.r15.u64;
	// lbzx r9,r26,r9
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r26.u32 + ctx.r9.u32);
	// lbzx r5,r26,r5
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r26.u32 + ctx.r5.u32);
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// lwz r26,80(r1)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// extsb r9,r5
	ctx.r9.s64 = ctx.r5.s8;
	// add r4,r8,r11
	ctx.r4.u64 = ctx.r8.u64 + ctx.r11.u64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rlwinm r11,r4,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// li r9,0
	ctx.r9.s64 = 0;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// add r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 + ctx.r6.u64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// add r5,r10,r27
	ctx.r5.u64 = ctx.r10.u64 + ctx.r27.u64;
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + ctx.r28.u64;
	// bl 0x880a51a0
	ctx.lr = 0x880A732C;
	sub_880A51A0(ctx, base);
	// lwz r9,10236(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10236);
	// cmpwi cr6,r9,10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 10, ctx.xer);
	// bne cr6,0x880a7350
	if (!ctx.cr6.eq) goto loc_880A7350;
	// addi r7,r31,10240
	ctx.r7.s64 = ctx.r31.s64 + 10240;
	// lwz r5,10176(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10176);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// lwz r4,10172(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10172);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a4f48
	ctx.lr = 0x880A7350;
	sub_880A4F48(ctx, base);
loc_880A7350:
	// lwz r11,10236(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10236);
	// cmpwi cr6,r11,11
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 11, ctx.xer);
	// bne cr6,0x880a7374
	if (!ctx.cr6.eq) goto loc_880A7374;
	// addi r7,r31,10240
	ctx.r7.s64 = ctx.r31.s64 + 10240;
	// lwz r5,10176(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10176);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// lwz r4,10172(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10172);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a4f48
	ctx.lr = 0x880A7374;
	sub_880A4F48(ctx, base);
loc_880A7374:
	// lwz r9,2380(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2380);
	// lwz r11,-552(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -552);
	// lwz r10,-556(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -556);
	// divw r9,r9,r29
	ctx.r9.s32 = ppc_divw(ctx.r9.s32, ctx.r29.s32);
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r4,r10,r28
	ctx.r4.u64 = ctx.r10.u64 + ctx.r28.u64;
	// lwz r10,8800(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8800);
	// add r5,r11,r27
	ctx.r5.u64 = ctx.r11.u64 + ctx.r27.u64;
	// subf r8,r23,r4
	ctx.r8.s64 = ctx.r4.s64 - ctx.r23.s64;
	// stw r4,8812(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8812, ctx.r4.u32);
	// stw r5,8816(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8816, ctx.r5.u32);
	// stw r8,10100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10100, ctx.r8.u32);
	// stw r5,10104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10104, ctx.r5.u32);
	// lwz r7,8872(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8872);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne cr6,0x880a7400
	if (!ctx.cr6.eq) goto loc_880A7400;
	// addis r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 65536;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// addi r3,r3,-26611
	ctx.r3.s64 = ctx.r3.s64 + -26611;
	// bl 0x880a51a0
	ctx.lr = 0x880A73D8;
	sub_880A51A0(ctx, base);
	// lwz r11,10236(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10236);
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bne cr6,0x880a7400
	if (!ctx.cr6.eq) goto loc_880A7400;
	// lwz r11,10104(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10104);
	// addi r7,r31,10240
	ctx.r7.s64 = ctx.r31.s64 + 10240;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// lwz r4,10100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10100);
	// subf r5,r23,r11
	ctx.r5.s64 = ctx.r11.s64 - ctx.r23.s64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a4f48
	ctx.lr = 0x880A7400;
	sub_880A4F48(ctx, base);
loc_880A7400:
	// lwz r9,2380(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2380);
	// lwz r11,-544(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -544);
	// lwz r10,-548(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -548);
	// divw r9,r9,r29
	ctx.r9.s32 = ppc_divw(ctx.r9.s32, ctx.r29.s32);
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r4,r10,r28
	ctx.r4.u64 = ctx.r10.u64 + ctx.r28.u64;
	// lwz r10,8888(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8888);
	// add r5,r11,r27
	ctx.r5.u64 = ctx.r11.u64 + ctx.r27.u64;
	// subf r8,r23,r4
	ctx.r8.s64 = ctx.r4.s64 - ctx.r23.s64;
	// stw r4,8900(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8900, ctx.r4.u32);
	// stw r5,8904(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8904, ctx.r5.u32);
	// stw r8,10108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10108, ctx.r8.u32);
	// stw r5,10112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10112, ctx.r5.u32);
	// lwz r7,8960(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8960);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne cr6,0x880a748c
	if (!ctx.cr6.eq) goto loc_880A748C;
	// addis r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 65536;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// addi r3,r3,-26599
	ctx.r3.s64 = ctx.r3.s64 + -26599;
	// bl 0x880a51a0
	ctx.lr = 0x880A7464;
	sub_880A51A0(ctx, base);
	// lwz r11,10236(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10236);
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bne cr6,0x880a748c
	if (!ctx.cr6.eq) goto loc_880A748C;
	// lwz r11,10112(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10112);
	// addi r7,r31,10240
	ctx.r7.s64 = ctx.r31.s64 + 10240;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// lwz r4,10108(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 10108);
	// subf r5,r23,r11
	ctx.r5.s64 = ctx.r11.s64 - ctx.r23.s64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a4f48
	ctx.lr = 0x880A748C;
	sub_880A4F48(ctx, base);
loc_880A748C:
	// lwz r11,-520(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -520);
	// lwz r10,-524(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -524);
	// lwz r8,2956(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2956);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// rlwinm r9,r10,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// lwz r6,9048(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9048);
	// rlwinm r11,r7,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// divw r10,r8,r29
	ctx.r10.s32 = ppc_divw(ctx.r8.s32, ctx.r29.s32);
	// add r4,r9,r28
	ctx.r4.u64 = ctx.r9.u64 + ctx.r28.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r4,8988(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8988, ctx.r4.u32);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// add r5,r11,r27
	ctx.r5.u64 = ctx.r11.u64 + ctx.r27.u64;
	// stw r5,8992(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8992, ctx.r5.u32);
	// bne cr6,0x880a74e4
	if (!ctx.cr6.eq) goto loc_880A74E4;
	// lis r3,0
	ctx.r3.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// ori r3,r3,38924
	ctx.r3.u64 = ctx.r3.u64 | 38924;
	// bl 0x880a51a0
	ctx.lr = 0x880A74E4;
	sub_880A51A0(ctx, base);
loc_880A74E4:
	// lwz r11,7636(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7636);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x880a7590
	if (!ctx.cr6.eq) goto loc_880A7590;
	// lwz r11,9132(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9132);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bne cr6,0x880a750c
	if (!ctx.cr6.eq) goto loc_880A750C;
	// li r11,95
	ctx.r11.s64 = 95;
	// stw r11,2944(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2944, ctx.r11.u32);
	// b 0x880a7510
	goto loc_880A7510;
loc_880A750C:
	// stw r24,2944(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2944, ctx.r24.u32);
loc_880A7510:
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r11,7568(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7568);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lwz r4,7640(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7640);
	// rlwinm r5,r11,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r7,2956(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2956);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// lwz r6,300(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 300);
	// divw r7,r7,r29
	ctx.r7.s32 = ppc_divw(ctx.r7.s32, ctx.r29.s32);
	// lwz r9,304(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 304);
	// lbzx r3,r5,r8
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r8.u32);
	// lbzx r8,r5,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r10.u32);
	// extsb r10,r3
	ctx.r10.s64 = ctx.r3.s8;
	// extsb r5,r8
	ctx.r5.s64 = ctx.r8.s8;
	// addi r4,r10,4
	ctx.r4.s64 = ctx.r10.s64 + 4;
	// rlwinm r8,r5,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// add r4,r8,r28
	ctx.r4.u64 = ctx.r8.u64 + ctx.r28.u64;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r4,7580(r31)
	PPC_STORE_U32(ctx.r31.u32 + 7580, ctx.r4.u32);
	// add r5,r10,r27
	ctx.r5.u64 = ctx.r10.u64 + ctx.r27.u64;
	// stw r5,7584(r31)
	PPC_STORE_U32(ctx.r31.u32 + 7584, ctx.r5.u32);
	// bne cr6,0x880a7590
	if (!ctx.cr6.eq) goto loc_880A7590;
	// addis r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 65536;
	// lwz r6,2944(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2944);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// addi r3,r3,-26442
	ctx.r3.s64 = ctx.r3.s64 + -26442;
	// bl 0x880a51a0
	ctx.lr = 0x880A7590;
	sub_880A51A0(ctx, base);
loc_880A7590:
	// lwz r11,7636(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7636);
	// li r8,0
	ctx.r8.s64 = 0;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x880a75b8
	if (!ctx.cr6.eq) goto loc_880A75B8;
	// lwz r11,2280(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2280);
	// addi r24,r24,-3
	ctx.r24.s64 = ctx.r24.s64 + -3;
	// lwz r10,2284(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2284);
	// divw r8,r11,r29
	ctx.r8.s32 = ppc_divw(ctx.r11.s32, ctx.r29.s32);
	// divw r9,r10,r29
	ctx.r9.s32 = ppc_divw(ctx.r10.s32, ctx.r29.s32);
	// b 0x880a75c0
	goto loc_880A75C0;
loc_880A75B8:
	// lwz r11,2956(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2956);
	// divw r9,r11,r29
	ctx.r9.s32 = ppc_divw(ctx.r11.s32, ctx.r29.s32);
loc_880A75C0:
	// lwz r10,300(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 300);
	// lwz r11,304(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 304);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r10,r10,r28
	ctx.r10.u64 = ctx.r10.u64 + ctx.r28.u64;
	// add r5,r11,r27
	ctx.r5.u64 = ctx.r11.u64 + ctx.r27.u64;
	// lwz r11,9064(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9064);
	// stw r10,10204(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10204, ctx.r10.u32);
	// stw r5,10208(r31)
	PPC_STORE_U32(ctx.r31.u32 + 10208, ctx.r5.u32);
	// lwz r9,9132(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9132);
	// cmplwi cr6,r9,7
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 7, ctx.xer);
	// bgt cr6,0x880a78f8
	if (ctx.cr6.gt) goto loc_880A78F8;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x880a7654
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_880A7654;
	// bdzf 4*cr6+eq,0x880a7698
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_880A7698;
	// bdzf 4*cr6+eq,0x880a76e0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_880A76E0;
	// bdzf 4*cr6+eq,0x880a7728
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_880A7728;
	// bdzf 4*cr6+eq,0x880a7768
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_880A7768;
	// bdzf 4*cr6+eq,0x880a77a4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_880A77A4;
	// bne cr6,0x880a77e4
	if (!ctx.cr6.eq) goto loc_880A77E4;
	// lis r9,-30682
	ctx.r9.s64 = -2010775552;
	// rlwinm r4,r11,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r7,r9,-30124
	ctx.r7.s64 = ctx.r9.s64 + -30124;
	// addis r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 65536;
	// addi r11,r7,1
	ctx.r11.s64 = ctx.r7.s64 + 1;
	// addi r3,r3,-26238
	ctx.r3.s64 = ctx.r3.s64 + -26238;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// lbzx r31,r4,r7
	ctx.r31.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r7.u32);
	// lbzx r4,r4,r11
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r11.u32);
	// extsb r11,r31
	ctx.r11.s64 = ctx.r31.s8;
	// extsb r4,r4
	ctx.r4.s64 = ctx.r4.s8;
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r31,r4,16,0,15
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r5,r31,r5
	ctx.r5.u64 = ctx.r31.u64 + ctx.r5.u64;
	// b 0x880a78e8
	goto loc_880A78E8;
loc_880A7654:
	// lis r9,-30682
	ctx.r9.s64 = -2010775552;
	// rlwinm r4,r11,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r7,r9,-30012
	ctx.r7.s64 = ctx.r9.s64 + -30012;
	// addis r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 65536;
	// addi r11,r7,1
	ctx.r11.s64 = ctx.r7.s64 + 1;
	// addi r3,r3,-26298
	ctx.r3.s64 = ctx.r3.s64 + -26298;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// lbzx r31,r4,r7
	ctx.r31.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r7.u32);
	// lbzx r4,r4,r11
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r11.u32);
	// extsb r11,r31
	ctx.r11.s64 = ctx.r31.s8;
	// extsb r4,r4
	ctx.r4.s64 = ctx.r4.s8;
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// addi r31,r4,4
	ctx.r31.s64 = ctx.r4.s64 + 4;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r31,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 16) & 0xFFFF0000;
	// add r5,r11,r5
	ctx.r5.u64 = ctx.r11.u64 + ctx.r5.u64;
	// b 0x880a78e8
	goto loc_880A78E8;
loc_880A7698:
	// lis r9,-30682
	ctx.r9.s64 = -2010775552;
	// rlwinm r4,r11,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r7,r9,-29996
	ctx.r7.s64 = ctx.r9.s64 + -29996;
	// addis r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 65536;
	// addi r11,r7,1
	ctx.r11.s64 = ctx.r7.s64 + 1;
	// addi r3,r3,-26286
	ctx.r3.s64 = ctx.r3.s64 + -26286;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// lbzx r31,r4,r7
	ctx.r31.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r7.u32);
	// lbzx r11,r4,r11
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r11.u32);
	// extsb r4,r31
	ctx.r4.s64 = ctx.r31.s8;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// addi r31,r11,8
	ctx.r31.s64 = ctx.r11.s64 + 8;
	// rlwinm r11,r4,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r31,r31,16,0,15
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r5,r31,r5
	ctx.r5.u64 = ctx.r31.u64 + ctx.r5.u64;
	// b 0x880a78e8
	goto loc_880A78E8;
loc_880A76E0:
	// lis r9,-30682
	ctx.r9.s64 = -2010775552;
	// rlwinm r4,r11,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r7,r9,-29980
	ctx.r7.s64 = ctx.r9.s64 + -29980;
	// addis r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 65536;
	// addi r11,r7,1
	ctx.r11.s64 = ctx.r7.s64 + 1;
	// addi r3,r3,-26290
	ctx.r3.s64 = ctx.r3.s64 + -26290;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// lbzx r31,r4,r7
	ctx.r31.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r7.u32);
	// lbzx r11,r4,r11
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r11.u32);
	// extsb r4,r31
	ctx.r4.s64 = ctx.r31.s8;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// addi r31,r11,8
	ctx.r31.s64 = ctx.r11.s64 + 8;
	// rlwinm r11,r4,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r31,r31,16,0,15
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r5,r31,r5
	ctx.r5.u64 = ctx.r31.u64 + ctx.r5.u64;
	// b 0x880a78e8
	goto loc_880A78E8;
loc_880A7728:
	// lis r9,-30682
	ctx.r9.s64 = -2010775552;
	// rlwinm r4,r11,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r7,r9,-30044
	ctx.r7.s64 = ctx.r9.s64 + -30044;
	// addis r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 65536;
	// addi r11,r7,1
	ctx.r11.s64 = ctx.r7.s64 + 1;
	// addi r3,r3,-26278
	ctx.r3.s64 = ctx.r3.s64 + -26278;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// lbzx r31,r4,r7
	ctx.r31.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r7.u32);
	// lbzx r4,r4,r11
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r11.u32);
	// extsb r11,r31
	ctx.r11.s64 = ctx.r31.s8;
	// extsb r4,r4
	ctx.r4.s64 = ctx.r4.s8;
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r31,r4,16,0,15
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r5,r31,r5
	ctx.r5.u64 = ctx.r31.u64 + ctx.r5.u64;
	// b 0x880a78e8
	goto loc_880A78E8;
loc_880A7768:
	// lis r9,-30682
	ctx.r9.s64 = -2010775552;
	// rlwinm r4,r11,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r7,r9,-30124
	ctx.r7.s64 = ctx.r9.s64 + -30124;
	// addis r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 65536;
	// addi r11,r7,1
	ctx.r11.s64 = ctx.r7.s64 + 1;
	// addi r3,r3,-26238
	ctx.r3.s64 = ctx.r3.s64 + -26238;
	// lbzx r31,r4,r7
	ctx.r31.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r7.u32);
	// lbzx r4,r4,r11
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r11.u32);
	// extsb r11,r31
	ctx.r11.s64 = ctx.r31.s8;
	// extsb r4,r4
	ctx.r4.s64 = ctx.r4.s8;
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r31,r4,16,0,15
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r5,r31,r5
	ctx.r5.u64 = ctx.r31.u64 + ctx.r5.u64;
	// b 0x880a78e4
	goto loc_880A78E4;
loc_880A77A4:
	// lis r9,-30682
	ctx.r9.s64 = -2010775552;
	// rlwinm r4,r11,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r7,r9,-30092
	ctx.r7.s64 = ctx.r9.s64 + -30092;
	// addis r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 65536;
	// addi r11,r7,1
	ctx.r11.s64 = ctx.r7.s64 + 1;
	// addi r3,r3,-26262
	ctx.r3.s64 = ctx.r3.s64 + -26262;
	// lbzx r31,r4,r7
	ctx.r31.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r7.u32);
	// lbzx r4,r4,r11
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r11.u32);
	// extsb r11,r31
	ctx.r11.s64 = ctx.r31.s8;
	// extsb r4,r4
	ctx.r4.s64 = ctx.r4.s8;
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// addi r31,r4,4
	ctx.r31.s64 = ctx.r4.s64 + 4;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r31,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 16) & 0xFFFF0000;
	// add r5,r11,r5
	ctx.r5.u64 = ctx.r11.u64 + ctx.r5.u64;
	// b 0x880a78e4
	goto loc_880A78E4;
loc_880A77E4:
	// lwz r9,9136(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9136);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x880a78f8
	if (!ctx.cr6.eq) goto loc_880A78F8;
	// lis r9,-30682
	ctx.r9.s64 = -2010775552;
	// lwz r18,88(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r9,r9,-30076
	ctx.r9.s64 = ctx.r9.s64 + -30076;
	// lis r8,-30643
	ctx.r8.s64 = -2008219648;
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// addis r28,r11,1
	ctx.r28.s64 = ctx.r11.s64 + 65536;
	// lwz r22,-11932(r18)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r18.u32 + -11932);
	// li r21,8
	ctx.r21.s64 = 8;
	// lbzx r4,r7,r9
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r9.u32);
	// addi r28,r28,-26254
	ctx.r28.s64 = ctx.r28.s64 + -26254;
	// lwz r29,26428(r8)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + 26428);
	// lis r23,-3
	ctx.r23.s64 = -196608;
	// lbzx r3,r7,r6
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r6.u32);
	// extsb r9,r4
	ctx.r9.s64 = ctx.r4.s8;
	// li r24,15
	ctx.r24.s64 = 15;
	// extsb r11,r3
	ctx.r11.s64 = ctx.r3.s8;
	// addi r9,r9,-4
	ctx.r9.s64 = ctx.r9.s64 + -4;
	// addi r8,r11,12
	ctx.r8.s64 = ctx.r11.s64 + 12;
	// rlwinm r9,r9,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r8,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// add r27,r9,r10
	ctx.r27.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r26,r11,r5
	ctx.r26.u64 = ctx.r11.u64 + ctx.r5.u64;
	// li r25,255
	ctx.r25.s64 = 255;
loc_880A7850:
	// clrlwi r11,r29,28
	ctx.r11.u64 = ctx.r29.u32 & 0xF;
	// lwz r10,252(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// li r6,95
	ctx.r6.s64 = 95;
	// mullw r9,r11,r23
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r23.s32);
	// subfic r8,r11,15
	ctx.xer.ca = ctx.r11.u32 <= 15;
	ctx.r8.s64 = 15 - ctx.r11.s64;
	// srawi r7,r9,16
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xFFFF) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 16;
	// mulli r5,r8,111
	ctx.r5.s64 = ctx.r8.s64 * 111;
	// addze r4,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r4.s64 = temp.s64;
	// divw r3,r5,r24
	ctx.r3.s32 = ppc_divw(ctx.r5.s32, ctx.r24.s32);
	// rlwinm r9,r4,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// mullw r10,r3,r10
	ctx.r10.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r10.s32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// subf r5,r9,r26
	ctx.r5.s64 = ctx.r26.s64 - ctx.r9.s64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// divw r30,r10,r25
	ctx.r30.s32 = ppc_divw(ctx.r10.s32, ctx.r25.s32);
	// bl 0x881538c0
	ctx.lr = 0x880A7890;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880a78b0
	if (ctx.cr6.eq) goto loc_880A78B0;
	// lis r11,545
	ctx.r11.s64 = 35717120;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r22,r22,1
	ctx.r22.s64 = ctx.r22.s64 + 1;
	// rlwimi r11,r30,8,16,23
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r30.u32, 8) & 0xFF00) | (ctx.r11.u64 & 0xFFFFFFFFFFFF00FF);
	// or r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_880A78B0:
	// cmplwi cr6,r19,0
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, 0, ctx.xer);
	// beq cr6,0x880a78c8
	if (ctx.cr6.eq) goto loc_880A78C8;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880a78c8
	if (ctx.cr6.eq) goto loc_880A78C8;
	// lwz r11,0(r19)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r19.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880A78C8:
	// addic. r21,r21,-1
	ctx.xer.ca = ctx.r21.u32 > 0;
	ctx.r21.s64 = ctx.r21.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// addi r29,r29,2
	ctx.r29.s64 = ctx.r29.s64 + 2;
	// bne 0x880a7850
	if (!ctx.cr0.eq) goto loc_880A7850;
	// stw r22,-11932(r18)
	PPC_STORE_U32(ctx.r18.u32 + -11932, ctx.r22.u32);
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
loc_880A78E4:
	// li r6,95
	ctx.r6.s64 = 95;
loc_880A78E8:
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r19
	ctx.r7.u64 = ctx.r19.u64;
	// bl 0x880a51a0
	ctx.lr = 0x880A78F8;
	sub_880A51A0(ctx, base);
loc_880A78F8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A7904"))) PPC_WEAK_FUNC(sub_880A7904);
PPC_FUNC_IMPL(__imp__sub_880A7904) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A7908"))) PPC_WEAK_FUNC(sub_880A7908);
PPC_FUNC_IMPL(__imp__sub_880A7908) {
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
	// addi r11,r4,9884
	ctx.r11.s64 = ctx.r4.s64 + 9884;
	// addi r9,r4,9880
	ctx.r9.s64 = ctx.r4.s64 + 9880;
	// ori r8,r10,65535
	ctx.r8.u64 = ctx.r10.u64 | 65535;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// lis r7,-30710
	ctx.r7.s64 = -2012610560;
	// stw r8,9884(r4)
	PPC_STORE_U32(ctx.r4.u32 + 9884, ctx.r8.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r7,21904
	ctx.r5.s64 = ctx.r7.s64 + 21904;
	// li r4,30
	ctx.r4.s64 = 30;
	// bl 0x88096460
	ctx.lr = 0x880A7944;
	sub_88096460(ctx, base);
	// lis r6,-30641
	ctx.r6.s64 = -2008088576;
	// addi r5,r6,-18816
	ctx.r5.s64 = ctx.r6.s64 + -18816;
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

__attribute__((alias("__imp__sub_880A7960"))) PPC_WEAK_FUNC(sub_880A7960);
PPC_FUNC_IMPL(__imp__sub_880A7960) {
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
	// addi r11,r4,9856
	ctx.r11.s64 = ctx.r4.s64 + 9856;
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
	// addi r5,r9,21904
	ctx.r5.s64 = ctx.r9.s64 + 21904;
	// li r4,30
	ctx.r4.s64 = 30;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x88096460
	ctx.lr = 0x880A7998;
	sub_88096460(ctx, base);
	// lis r8,-30641
	ctx.r8.s64 = -2008088576;
	// lis r7,-30710
	ctx.r7.s64 = -2012610560;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r7,20216
	ctx.r5.s64 = ctx.r7.s64 + 20216;
	// li r4,30
	ctx.r4.s64 = 30;
	// stw r3,-18816(r8)
	PPC_STORE_U32(ctx.r8.u32 + -18816, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r31,r8,-18816
	ctx.r31.s64 = ctx.r8.s64 + -18816;
	// bl 0x88096460
	ctx.lr = 0x880A79BC;
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

__attribute__((alias("__imp__sub_880A79D4"))) PPC_WEAK_FUNC(sub_880A79D4);
PPC_FUNC_IMPL(__imp__sub_880A79D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A79D8"))) PPC_WEAK_FUNC(sub_880A79D8);
PPC_FUNC_IMPL(__imp__sub_880A79D8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880A79DC"))) PPC_WEAK_FUNC(sub_880A79DC);
PPC_FUNC_IMPL(__imp__sub_880A79DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A79E0"))) PPC_WEAK_FUNC(sub_880A79E0);
PPC_FUNC_IMPL(__imp__sub_880A79E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071124
	ctx.lr = 0x880A79E8;
	__savegprlr_15(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r22,r6
	ctx.r22.u64 = ctx.r6.u64;
	// mr r16,r7
	ctx.r16.u64 = ctx.r7.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x880a7bf0
	if (ctx.cr6.eq) goto loc_880A7BF0;
	// lis r29,-30671
	ctx.r29.s64 = -2010054656;
	// lis r10,16838
	ctx.r10.s64 = 1103495168;
	// lis r9,-3856
	ctx.r9.s64 = -252706816;
	// lis r8,-13755
	ctx.r8.s64 = -901447680;
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// lwz r30,4200(r29)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4200);
	// mr r15,r4
	ctx.r15.u64 = ctx.r4.u64;
	// ori r28,r10,20077
	ctx.r28.u64 = ctx.r10.u64 | 20077;
	// ori r21,r9,61681
	ctx.r21.u64 = ctx.r9.u64 | 61681;
	// li r17,112
	ctx.r17.s64 = 112;
	// ori r19,r8,34791
	ctx.r19.u64 = ctx.r8.u64 | 34791;
	// lis r20,-30667
	ctx.r20.s64 = -2009792512;
	// lis r26,-30667
	ctx.r26.s64 = -2009792512;
	// lis r25,-30667
	ctx.r25.s64 = -2009792512;
	// lis r24,-30667
	ctx.r24.s64 = -2009792512;
	// addi r18,r11,9552
	ctx.r18.s64 = ctx.r11.s64 + 9552;
loc_880A7A44:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r9,4(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// add r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stw r11,12364(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12364, ctx.r11.u32);
	// stw r22,12376(r20)
	PPC_STORE_U32(ctx.r20.u32 + 12376, ctx.r22.u32);
	// stw r10,12372(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12372, ctx.r10.u32);
	// stw r3,12380(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12380, ctx.r3.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880A7A78;
	sub_880F52C8(ctx, base);
	// mullw r11,r30,r28
	ctx.r11.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r28.s32);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addi r8,r11,12345
	ctx.r8.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r8,4200(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4200, ctx.r8.u32);
	// lhz r7,4200(r29)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r29.u32 + 4200);
	// mulhwu r6,r7,r21
	ctx.r6.u64 = (uint64_t(ctx.r7.u32) * uint64_t(ctx.r21.u32)) >> 32;
	// rlwinm r11,r6,28,4,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 28) & 0xFFFFFFF;
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
	// addi r11,r11,-8
	ctx.r11.s64 = ctx.r11.s64 + -8;
	// beq cr6,0x880a7b18
	if (ctx.cr6.eq) goto loc_880A7B18;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// clrlwi r9,r11,23
	ctx.r9.u64 = ctx.r11.u32 & 0x1FF;
	// stw r11,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, ctx.r11.u32);
	// addi r7,r3,36
	ctx.r7.s64 = ctx.r3.s64 + 36;
	// rlwinm r11,r10,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// srawi r10,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 1;
	// addze r6,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r6.s64 = temp.s64;
	// addic. r11,r3,40
	ctx.xer.ca = ctx.r3.u32 > 4294967255;
	ctx.r11.s64 = ctx.r3.s64 + 40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r6,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, ctx.r6.u32);
	// rotlwi r10,r6,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// beq 0x880a7af8
	if (ctx.cr0.eq) goto loc_880A7AF8;
	// addi r6,r9,128
	ctx.r6.s64 = ctx.r9.s64 + 128;
	// rlwinm r5,r6,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// lwzx r4,r5,r18
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r18.u32);
	// mullw r6,r4,r10
	ctx.r6.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r10.s32);
	// stw r6,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r6.u32);
loc_880A7AF8:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x880a7b10
	if (ctx.cr6.eq) goto loc_880A7B10;
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r18
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r18.u32);
	// mullw r6,r9,r10
	ctx.r6.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// stw r6,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r6.u32);
loc_880A7B10:
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// stw r11,148(r3)
	PPC_STORE_U32(ctx.r3.u32 + 148, ctx.r11.u32);
loc_880A7B18:
	// mullw r11,r8,r28
	ctx.r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r28.s32);
	// addi r30,r11,12345
	ctx.r30.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r30,4200(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4200, ctx.r30.u32);
	// beq cr6,0x880a7b54
	if (ctx.cr6.eq) goto loc_880A7B54;
	// lhz r11,4200(r29)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r29.u32 + 4200);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// rlwinm r11,r11,1,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x2;
	// stw r17,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r17.u32);
	// stw r16,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r16.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r11,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r11.u32);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// clrlwi r9,r10,16
	ctx.r9.u64 = ctx.r10.u32 & 0xFFFF;
	// stw r9,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r9.u32);
loc_880A7B54:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r23,0
	ctx.r23.s64 = 0;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x880a7be4
	if (!ctx.cr6.gt) goto loc_880A7BE4;
	// addi r4,r22,1
	ctx.r4.s64 = ctx.r22.s64 + 1;
	// stw r4,12376(r20)
	PPC_STORE_U32(ctx.r20.u32 + 12376, ctx.r4.u32);
loc_880A7B70:
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r8,0(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r9,4(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r11,12364(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12372, ctx.r10.u32);
	// stw r3,12380(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12380, ctx.r3.u32);
	// bl 0x880f34b0
	ctx.lr = 0x880A7B9C;
	sub_880F34B0(ctx, base);
	// mullw r11,r30,r28
	ctx.r11.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r28.s32);
	// addi r30,r11,12345
	ctx.r30.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r30,4200(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4200, ctx.r30.u32);
	// beq cr6,0x880a7bd0
	if (ctx.cr6.eq) goto loc_880A7BD0;
	// lhz r11,4200(r29)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r29.u32 + 4200);
	// mulhwu r10,r11,r19
	ctx.r10.u64 = (uint64_t(ctx.r11.u32) * uint64_t(ctx.r19.u32)) >> 32;
	// rlwinm r9,r10,26,6,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 26) & 0x3FFFFFF;
	// mulli r8,r9,81
	ctx.r8.s64 = ctx.r9.s64 * 81;
	// subf r7,r8,r11
	ctx.r7.s64 = ctx.r11.s64 - ctx.r8.s64;
	// clrlwi r11,r7,16
	ctx.r11.u64 = ctx.r7.u32 & 0xFFFF;
	// addi r5,r11,8
	ctx.r5.s64 = ctx.r11.s64 + 8;
	// sth r5,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, ctx.r5.u16);
loc_880A7BD0:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r23,r23,1
	ctx.r23.s64 = ctx.r23.s64 + 1;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r23,r10
	ctx.cr6.compare<int32_t>(ctx.r23.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x880a7b70
	if (ctx.cr6.lt) goto loc_880A7B70;
loc_880A7BE4:
	// addic. r15,r15,-1
	ctx.xer.ca = ctx.r15.u32 > 0;
	ctx.r15.s64 = ctx.r15.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r15.s32, 0, ctx.xer);
	// addi r31,r31,40
	ctx.r31.s64 = ctx.r31.s64 + 40;
	// bne 0x880a7a44
	if (!ctx.cr0.eq) goto loc_880A7A44;
loc_880A7BF0:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071174
	__restgprlr_15(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A7BF8"))) PPC_WEAK_FUNC(sub_880A7BF8);
PPC_FUNC_IMPL(__imp__sub_880A7BF8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x880A7C00;
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
	// ble cr6,0x880a7c6c
	if (!ctx.cr6.gt) goto loc_880A7C6C;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r31,0
	ctx.r31.s64 = 0;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// ble cr6,0x880a7c6c
	if (!ctx.cr6.gt) goto loc_880A7C6C;
	// addi r30,r11,-1
	ctx.r30.s64 = ctx.r11.s64 + -1;
loc_880A7C34:
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
	ctx.lr = 0x880A7C60;
	sub_881538C0(ctx, base);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmpw cr6,r31,r29
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r29.s32, ctx.xer);
	// blt cr6,0x880a7c34
	if (ctx.cr6.lt) goto loc_880A7C34;
loc_880A7C6C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A7C74"))) PPC_WEAK_FUNC(sub_880A7C74);
PPC_FUNC_IMPL(__imp__sub_880A7C74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A7C78"))) PPC_WEAK_FUNC(sub_880A7C78);
PPC_FUNC_IMPL(__imp__sub_880A7C78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071120
	ctx.lr = 0x880A7C80;
	__savegprlr_14(ctx, base);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r18,2304(r3)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// li r14,0
	ctx.r14.s64 = 0;
	// lwz r11,20(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880a7ca8
	if (ctx.cr6.eq) goto loc_880A7CA8;
	// addic. r11,r11,-2
	ctx.xer.ca = ctx.r11.u32 > 1;
	ctx.r11.s64 = ctx.r11.s64 + -2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,20(r18)
	PPC_STORE_U32(ctx.r18.u32 + 20, ctx.r11.u32);
	// bgt 0x880a7ca8
	if (ctx.cr0.gt) goto loc_880A7CA8;
	// stw r14,20(r18)
	PPC_STORE_U32(ctx.r18.u32 + 20, ctx.r14.u32);
loc_880A7CA8:
	// lwz r11,28(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 28);
	// cmplwi cr6,r11,20
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 20, ctx.xer);
	// bgt cr6,0x880a88b4
	if (ctx.cr6.gt) goto loc_880A88B4;
	// li r19,2
	ctx.r19.s64 = 2;
	// lis r12,-30710
	ctx.r12.s64 = -2012610560;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,31952
	ctx.r12.s64 = ctx.r12.s64 + 31952;
	// lwzx r0,r12,r0
	ctx.r0.u64 = PPC_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u64) {
	case 0:
		goto loc_880A7D24;
	case 1:
		goto loc_880A7EC4;
	case 2:
		goto loc_880A7F40;
	case 3:
		goto loc_880A82F8;
	case 4:
		goto loc_880A844C;
	case 5:
		goto loc_880A884C;
	case 6:
		goto loc_880A88B4;
	case 7:
		goto loc_880A88B4;
	case 8:
		goto loc_880A88B4;
	case 9:
		goto loc_880A88B4;
	case 10:
		goto loc_880A886C;
	case 11:
		goto loc_880A88B4;
	case 12:
		goto loc_880A88B4;
	case 13:
		goto loc_880A88B4;
	case 14:
		goto loc_880A88B4;
	case 15:
		goto loc_880A88B4;
	case 16:
		goto loc_880A88B4;
	case 17:
		goto loc_880A88B4;
	case 18:
		goto loc_880A88B4;
	case 19:
		goto loc_880A88B4;
	case 20:
		goto loc_880A88A0;
	default:
		__builtin_unreachable();
	}
	// lbz r0,32036(r10)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r10.u32 + 32036);
	// lbz r0,32452(r10)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r10.u32 + 32452);
	// lbz r0,32576(r10)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r10.u32 + 32576);
	// lbz r0,-32008(r10)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r10.u32 + -32008);
	// lbz r0,-31668(r10)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r10.u32 + -31668);
	// lbz r0,-30644(r10)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r10.u32 + -30644);
	// lbz r0,-30540(r10)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r10.u32 + -30540);
	// lbz r0,-30540(r10)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r10.u32 + -30540);
	// lbz r0,-30540(r10)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r10.u32 + -30540);
	// lbz r0,-30540(r10)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r10.u32 + -30540);
	// lbz r0,-30612(r10)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r10.u32 + -30612);
	// lbz r0,-30540(r10)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r10.u32 + -30540);
	// lbz r0,-30540(r10)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r10.u32 + -30540);
	// lbz r0,-30540(r10)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r10.u32 + -30540);
	// lbz r0,-30540(r10)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r10.u32 + -30540);
	// lbz r0,-30540(r10)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r10.u32 + -30540);
	// lbz r0,-30540(r10)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r10.u32 + -30540);
	// lbz r0,-30540(r10)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r10.u32 + -30540);
	// lbz r0,-30540(r10)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r10.u32 + -30540);
	// lbz r0,-30540(r10)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r10.u32 + -30540);
	// lbz r0,-30560(r10)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r10.u32 + -30560);
loc_880A7D24:
	// lis r11,-30682
	ctx.r11.s64 = -2010775552;
	// lwz r10,8(r18)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// li r9,180
	ctx.r9.s64 = 180;
	// lwz r22,4(r18)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r18.u32 + 4);
	// addi r11,r11,-19424
	ctx.r11.s64 = ctx.r11.s64 + -19424;
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r9,32(r18)
	PPC_STORE_U32(ctx.r18.u32 + 32, ctx.r9.u32);
	// addi r11,r11,-1480
	ctx.r11.s64 = ctx.r11.s64 + -1480;
	// li r7,42
	ctx.r7.s64 = 42;
	// stw r8,28(r18)
	PPC_STORE_U32(ctx.r18.u32 + 28, ctx.r8.u32);
	// li r6,39
	ctx.r6.s64 = 39;
	// addis r20,r10,32
	ctx.r20.s64 = ctx.r10.s64 + 2097152;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// mr r28,r14
	ctx.r28.u64 = ctx.r14.u64;
	// addi r31,r11,20
	ctx.r31.s64 = ctx.r11.s64 + 20;
	// li r21,10
	ctx.r21.s64 = 10;
	// li r15,128
	ctx.r15.s64 = 128;
	// lis r26,-30667
	ctx.r26.s64 = -2009792512;
	// lis r25,-30667
	ctx.r25.s64 = -2009792512;
	// lis r24,-30667
	ctx.r24.s64 = -2009792512;
	// lis r23,-30667
	ctx.r23.s64 = -2009792512;
loc_880A7D7C:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x881534c8
	ctx.lr = 0x880A7D84;
	sub_881534C8(ctx, base);
	// lwz r30,-20(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + -20);
	// extsh r29,r3
	ctx.r29.s64 = ctx.r3.s16;
	// li r3,8
	ctx.r3.s64 = 8;
	// stw r30,12380(r23)
	PPC_STORE_U32(ctx.r23.u32 + 12380, ctx.r30.u32);
	// bl 0x881534c8
	ctx.lr = 0x880A7D98;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,8
	ctx.r3.s64 = 8;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r22
	ctx.r11.u64 = ctx.r11.u64 + ctx.r22.u64;
	// stw r11,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r11.u32);
	// bl 0x881534c8
	ctx.lr = 0x880A7DB4;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// rlwinm r10,r29,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-4
	ctx.r9.s64 = ctx.r11.s64 + -4;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// rlwinm r11,r9,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// add r11,r11,r20
	ctx.r11.u64 = ctx.r11.u64 + ctx.r20.u64;
	// stw r11,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r11.u32);
	// lwzx r4,r10,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// stw r4,12376(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12376, ctx.r4.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880A7DE0;
	sub_880F52C8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r29,-4(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + -4);
	// cmpwi cr6,r28,10
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 10, ctx.xer);
	// li r3,16
	ctx.r3.s64 = 16;
	// bge cr6,0x880a7e38
	if (!ctx.cr6.lt) goto loc_880A7E38;
	// bl 0x881534c8
	ctx.lr = 0x880A7DF8;
	sub_881534C8(ctx, base);
	// rlwinm r11,r29,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// extsh r10,r3
	ctx.r10.s64 = ctx.r3.s16;
	// lwz r27,0(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// srawi r9,r28,3
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0x7) != 0);
	ctx.r9.s64 = ctx.r28.s32 >> 3;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addze r9,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r9.s64 = temp.s64;
	// divw r11,r8,r21
	ctx.r11.s32 = ppc_divw(ctx.r8.s32, ctx.r21.s32);
	// li r3,8
	ctx.r3.s64 = 8;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r29,r11,r9
	ctx.r29.u64 = ctx.r11.u64 + ctx.r9.u64;
	// bl 0x881534c8
	ctx.lr = 0x880A7E28;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// add r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
	// addi r5,r11,252
	ctx.r5.s64 = ctx.r11.s64 + 252;
	// b 0x880a7e70
	goto loc_880A7E70;
loc_880A7E38:
	// bl 0x881534c8
	ctx.lr = 0x880A7E3C;
	sub_881534C8(ctx, base);
	// mulli r11,r29,11
	ctx.r11.s64 = ctx.r29.s64 * 11;
	// lwz r27,0(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// extsh r10,r3
	ctx.r10.s64 = ctx.r3.s16;
	// srawi r9,r28,3
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0x7) != 0);
	ctx.r9.s64 = ctx.r28.s32 >> 3;
	// divw r11,r11,r21
	ctx.r11.s32 = ppc_divw(ctx.r11.s32, ctx.r21.s32);
	// addze r9,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r9.s64 = temp.s64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// li r3,24
	ctx.r3.s64 = 24;
	// add r29,r11,r9
	ctx.r29.u64 = ctx.r11.u64 + ctx.r9.u64;
	// bl 0x881534c8
	ctx.lr = 0x880A7E64;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// add r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
	// addi r5,r11,244
	ctx.r5.s64 = ctx.r11.s64 + 244;
loc_880A7E70:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880f5570
	ctx.lr = 0x880A7E7C;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x880a7e8c
	if (ctx.cr6.eq) goto loc_880A7E8C;
	// lwz r11,36(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 36);
	// stw r11,144(r30)
	PPC_STORE_U32(ctx.r30.u32 + 144, ctx.r11.u32);
loc_880A7E8C:
	// cmpwi cr6,r28,5
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 5, ctx.xer);
	// ble cr6,0x880a7ea4
	if (!ctx.cr6.gt) goto loc_880A7EA4;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x880a7eb4
	if (ctx.cr6.eq) goto loc_880A7EB4;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,112(r30)
	PPC_STORE_U32(ctx.r30.u32 + 112, ctx.r11.u32);
loc_880A7EA4:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x880a7eb4
	if (ctx.cr6.eq) goto loc_880A7EB4;
	// stw r19,100(r30)
	PPC_STORE_U32(ctx.r30.u32 + 100, ctx.r19.u32);
	// stw r15,140(r30)
	PPC_STORE_U32(ctx.r30.u32 + 140, ctx.r15.u32);
loc_880A7EB4:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r31,r31,40
	ctx.r31.s64 = ctx.r31.s64 + 40;
	// cmplwi cr6,r28,26
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 26, ctx.xer);
	// blt cr6,0x880a7d7c
	if (ctx.cr6.lt) goto loc_880A7D7C;
loc_880A7EC4:
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26428(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26428);
	// clrlwi r10,r11,30
	ctx.r10.u64 = ctx.r11.u32 & 0x3;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x880a7f00
	if (!ctx.cr6.eq) goto loc_880A7F00;
	// lis r11,-30679
	ctx.r11.s64 = -2010578944;
	// lis r8,-30643
	ctx.r8.s64 = -2008219648;
	// addi r7,r11,-15272
	ctx.r7.s64 = ctx.r11.s64 + -15272;
	// addi r6,r8,32248
	ctx.r6.s64 = ctx.r8.s64 + 32248;
	// li r10,7
	ctx.r10.s64 = 7;
	// mr r11,r14
	ctx.r11.u64 = ctx.r14.u64;
	// stw r10,32248(r8)
	PPC_STORE_U32(ctx.r8.u32 + 32248, ctx.r10.u32);
	// lwz r9,28(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 28);
	// stw r14,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r14.u32);
	// stw r9,16(r6)
	PPC_STORE_U32(ctx.r6.u32 + 16, ctx.r9.u32);
loc_880A7F00:
	// lwz r11,32(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 32);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,32(r18)
	PPC_STORE_U32(ctx.r18.u32 + 32, ctx.r11.u32);
	// bge 0x880a88b4
	if (!ctx.cr0.lt) goto loc_880A88B4;
	// li r11,32
	ctx.r11.s64 = 32;
	// li r10,496
	ctx.r10.s64 = 496;
	// stw r11,20(r18)
	PPC_STORE_U32(ctx.r18.u32 + 20, ctx.r11.u32);
	// lis r9,-30719
	ctx.r9.s64 = -2013200384;
	// stw r10,24(r18)
	PPC_STORE_U32(ctx.r18.u32 + 24, ctx.r10.u32);
	// addi r3,r9,-4572
	ctx.r3.s64 = ctx.r9.s64 + -4572;
	// bl 0x880e3888
	ctx.lr = 0x880A7F2C;
	sub_880E3888(ctx, base);
	// li r8,30
	ctx.r8.s64 = 30;
	// stw r19,28(r18)
	PPC_STORE_U32(ctx.r18.u32 + 28, ctx.r19.u32);
	// stw r8,32(r18)
	PPC_STORE_U32(ctx.r18.u32 + 32, ctx.r8.u32);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
loc_880A7F40:
	// lwz r11,32(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 32);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,32(r18)
	PPC_STORE_U32(ctx.r18.u32 + 32, ctx.r11.u32);
	// bge 0x880a88b4
	if (!ctx.cr0.lt) goto loc_880A88B4;
	// lis r11,-30679
	ctx.r11.s64 = -2010578944;
	// lis r7,-30643
	ctx.r7.s64 = -2008219648;
	// addi r6,r11,-15272
	ctx.r6.s64 = ctx.r11.s64 + -15272;
	// lis r11,-30682
	ctx.r11.s64 = -2010775552;
	// addi r5,r7,32248
	ctx.r5.s64 = ctx.r7.s64 + 32248;
	// addi r24,r11,-19424
	ctx.r24.s64 = ctx.r11.s64 + -19424;
	// li r10,7
	ctx.r10.s64 = 7;
	// lwz r9,28(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 28);
	// addi r8,r24,-440
	ctx.r8.s64 = ctx.r24.s64 + -440;
	// li r4,42
	ctx.r4.s64 = 42;
	// stw r10,32248(r7)
	PPC_STORE_U32(ctx.r7.u32 + 32248, ctx.r10.u32);
	// li r3,39
	ctx.r3.s64 = 39;
	// stw r14,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r14.u32);
	// mr r11,r14
	ctx.r11.u64 = ctx.r14.u64;
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// mr r28,r14
	ctx.r28.u64 = ctx.r14.u64;
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// stw r9,16(r5)
	PPC_STORE_U32(ctx.r5.u32 + 16, ctx.r9.u32);
	// addi r31,r8,20
	ctx.r31.s64 = ctx.r8.s64 + 20;
	// lwz r11,8(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// addis r25,r11,40
	ctx.r25.s64 = ctx.r11.s64 + 2621440;
	// lwz r26,4(r18)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r18.u32 + 4);
	// li r21,10
	ctx.r21.s64 = 10;
	// lis r19,-30667
	ctx.r19.s64 = -2009792512;
	// li r23,2
	ctx.r23.s64 = 2;
	// li r15,128
	ctx.r15.s64 = 128;
	// lis r22,-30667
	ctx.r22.s64 = -2009792512;
	// lis r20,-30667
	ctx.r20.s64 = -2009792512;
	// lis r17,-30667
	ctx.r17.s64 = -2009792512;
loc_880A7FC4:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x881534c8
	ctx.lr = 0x880A7FCC;
	sub_881534C8(ctx, base);
	// extsh r29,r3
	ctx.r29.s64 = ctx.r3.s16;
	// li r3,32
	ctx.r3.s64 = 32;
	// lwz r30,-20(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + -20);
	// bl 0x881534c8
	ctx.lr = 0x880A7FDC;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,32
	ctx.r3.s64 = 32;
	// addi r11,r11,-16
	ctx.r11.s64 = ctx.r11.s64 + -16;
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// stw r11,12364(r20)
	PPC_STORE_U32(ctx.r20.u32 + 12364, ctx.r11.u32);
	// bl 0x881534c8
	ctx.lr = 0x880A7FF8;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// rlwinm r10,r29,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-16
	ctx.r9.s64 = ctx.r11.s64 + -16;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// rlwinm r11,r9,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// add r11,r11,r25
	ctx.r11.u64 = ctx.r11.u64 + ctx.r25.u64;
	// stw r11,12372(r22)
	PPC_STORE_U32(ctx.r22.u32 + 12372, ctx.r11.u32);
	// lwzx r4,r10,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880A8020;
	sub_880F52C8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r29,-4(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + -4);
	// cmpwi cr6,r28,10
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 10, ctx.xer);
	// li r3,16
	ctx.r3.s64 = 16;
	// bge cr6,0x880a8078
	if (!ctx.cr6.lt) goto loc_880A8078;
	// bl 0x881534c8
	ctx.lr = 0x880A8038;
	sub_881534C8(ctx, base);
	// rlwinm r11,r29,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// extsh r10,r3
	ctx.r10.s64 = ctx.r3.s16;
	// lwz r27,0(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// srawi r9,r28,3
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0x7) != 0);
	ctx.r9.s64 = ctx.r28.s32 >> 3;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addze r9,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r9.s64 = temp.s64;
	// divw r11,r8,r21
	ctx.r11.s32 = ppc_divw(ctx.r8.s32, ctx.r21.s32);
	// li r3,8
	ctx.r3.s64 = 8;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r29,r11,r9
	ctx.r29.u64 = ctx.r11.u64 + ctx.r9.u64;
	// bl 0x881534c8
	ctx.lr = 0x880A8068;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// add r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
	// addi r5,r11,252
	ctx.r5.s64 = ctx.r11.s64 + 252;
	// b 0x880a80b0
	goto loc_880A80B0;
loc_880A8078:
	// bl 0x881534c8
	ctx.lr = 0x880A807C;
	sub_881534C8(ctx, base);
	// mulli r11,r29,11
	ctx.r11.s64 = ctx.r29.s64 * 11;
	// lwz r27,0(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// extsh r10,r3
	ctx.r10.s64 = ctx.r3.s16;
	// srawi r9,r28,3
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0x7) != 0);
	ctx.r9.s64 = ctx.r28.s32 >> 3;
	// divw r11,r11,r21
	ctx.r11.s32 = ppc_divw(ctx.r11.s32, ctx.r21.s32);
	// addze r9,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r9.s64 = temp.s64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// li r3,24
	ctx.r3.s64 = 24;
	// add r29,r11,r9
	ctx.r29.u64 = ctx.r11.u64 + ctx.r9.u64;
	// bl 0x881534c8
	ctx.lr = 0x880A80A4;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// add r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
	// addi r5,r11,244
	ctx.r5.s64 = ctx.r11.s64 + 244;
loc_880A80B0:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880f5570
	ctx.lr = 0x880A80BC;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x880a80cc
	if (ctx.cr6.eq) goto loc_880A80CC;
	// lwz r11,36(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 36);
	// stw r11,144(r30)
	PPC_STORE_U32(ctx.r30.u32 + 144, ctx.r11.u32);
loc_880A80CC:
	// cmpwi cr6,r28,5
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 5, ctx.xer);
	// ble cr6,0x880a80e4
	if (!ctx.cr6.gt) goto loc_880A80E4;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x880a80f4
	if (ctx.cr6.eq) goto loc_880A80F4;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,112(r30)
	PPC_STORE_U32(ctx.r30.u32 + 112, ctx.r11.u32);
loc_880A80E4:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x880a80f4
	if (ctx.cr6.eq) goto loc_880A80F4;
	// stw r23,100(r30)
	PPC_STORE_U32(ctx.r30.u32 + 100, ctx.r23.u32);
	// stw r15,140(r30)
	PPC_STORE_U32(ctx.r30.u32 + 140, ctx.r15.u32);
loc_880A80F4:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r31,r31,40
	ctx.r31.s64 = ctx.r31.s64 + 40;
	// cmplwi cr6,r28,11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 11, ctx.xer);
	// blt cr6,0x880a7fc4
	if (ctx.cr6.lt) goto loc_880A7FC4;
	// addi r11,r24,-440
	ctx.r11.s64 = ctx.r24.s64 + -440;
	// lis r10,15887
	ctx.r10.s64 = 1041170432;
	// addi r28,r11,20
	ctx.r28.s64 = ctx.r11.s64 + 20;
	// lis r11,16838
	ctx.r11.s64 = 1103495168;
	// addis r24,r26,16
	ctx.r24.s64 = ctx.r26.s64 + 1048576;
	// addis r23,r25,4
	ctx.r23.s64 = ctx.r25.s64 + 262144;
	// mr r26,r14
	ctx.r26.u64 = ctx.r14.u64;
	// li r16,1
	ctx.r16.s64 = 1;
	// ori r30,r11,20077
	ctx.r30.u64 = ctx.r11.u64 | 20077;
	// lis r31,-30671
	ctx.r31.s64 = -2010054656;
	// ori r29,r10,33761
	ctx.r29.u64 = ctx.r10.u64 | 33761;
loc_880A8130:
	// lwz r11,4200(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4200);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lwz r3,-20(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + -20);
	// mullw r11,r11,r30
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// stw r3,12380(r17)
	PPC_STORE_U32(ctx.r17.u32 + 12380, ctx.r3.u32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// stw r11,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r11.u32);
	// mullw r11,r11,r30
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// lhz r6,4200(r31)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// rlwinm r5,r6,2,29,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x4;
	// stw r11,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r11.u32);
	// mullw r9,r11,r30
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// lwzx r4,r5,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r8.u32);
	// stw r4,12376(r19)
	PPC_STORE_U32(ctx.r19.u32 + 12376, ctx.r4.u32);
	// addi r10,r9,12345
	ctx.r10.s64 = ctx.r9.s64 + 12345;
	// lhz r9,4200(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// stw r10,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r10.u32);
	// mulhwu r8,r9,r29
	ctx.r8.u64 = (uint64_t(ctx.r9.u32) * uint64_t(ctx.r29.u32)) >> 32;
	// lhz r6,4200(r31)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// rlwinm r10,r8,29,3,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 29) & 0x1FFFFFFF;
	// mulhwu r5,r6,r29
	ctx.r5.u64 = (uint64_t(ctx.r6.u32) * uint64_t(ctx.r29.u32)) >> 32;
	// rlwinm r8,r10,5,0,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// rlwinm r11,r5,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 29) & 0x1FFFFFFF;
	// add r7,r8,r10
	ctx.r7.u64 = ctx.r8.u64 + ctx.r10.u64;
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// rlwinm r9,r11,5,0,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xFFFFFFE0;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// add r7,r9,r11
	ctx.r7.u64 = ctx.r9.u64 + ctx.r11.u64;
	// addi r5,r10,-16
	ctx.r5.s64 = ctx.r10.s64 + -16;
	// subf r6,r7,r6
	ctx.r6.s64 = ctx.r6.s64 - ctx.r7.s64;
	// extsh r11,r6
	ctx.r11.s64 = ctx.r6.s16;
	// addi r10,r11,-16
	ctx.r10.s64 = ctx.r11.s64 + -16;
	// rlwinm r11,r5,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r24
	ctx.r11.u64 = ctx.r11.u64 + ctx.r24.u64;
	// add r10,r10,r23
	ctx.r10.u64 = ctx.r10.u64 + ctx.r23.u64;
	// stw r11,12364(r20)
	PPC_STORE_U32(ctx.r20.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r22)
	PPC_STORE_U32(ctx.r22.u32 + 12372, ctx.r10.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880A81D0;
	sub_880F52C8(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// lwz r25,-4(r28)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r28.u32 + -4);
	// cmpwi cr6,r26,10
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 10, ctx.xer);
	// li r3,16
	ctx.r3.s64 = 16;
	// bge cr6,0x880a8228
	if (!ctx.cr6.lt) goto loc_880A8228;
	// bl 0x881534c8
	ctx.lr = 0x880A81E8;
	sub_881534C8(ctx, base);
	// rlwinm r11,r25,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 1) & 0xFFFFFFFE;
	// srawi r10,r26,3
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0x7) != 0);
	ctx.r10.s64 = ctx.r26.s32 >> 3;
	// lwz r14,0(r28)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// add r9,r25,r11
	ctx.r9.u64 = ctx.r25.u64 + ctx.r11.u64;
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addze r10,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r10.s64 = temp.s64;
	// divw r9,r8,r21
	ctx.r9.s32 = ppc_divw(ctx.r8.s32, ctx.r21.s32);
	// li r3,8
	ctx.r3.s64 = 8;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r25,r11,r10
	ctx.r25.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881534c8
	ctx.lr = 0x880A8218;
	sub_881534C8(ctx, base);
	// extsh r7,r3
	ctx.r7.s64 = ctx.r3.s16;
	// subf r11,r14,r7
	ctx.r11.s64 = ctx.r7.s64 - ctx.r14.s64;
	// addi r5,r11,252
	ctx.r5.s64 = ctx.r11.s64 + 252;
	// b 0x880a8260
	goto loc_880A8260;
loc_880A8228:
	// bl 0x881534c8
	ctx.lr = 0x880A822C;
	sub_881534C8(ctx, base);
	// mulli r10,r25,11
	ctx.r10.s64 = ctx.r25.s64 * 11;
	// lwz r14,0(r28)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// divw r9,r10,r21
	ctx.r9.s32 = ppc_divw(ctx.r10.s32, ctx.r21.s32);
	// srawi r8,r26,3
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0x7) != 0);
	ctx.r8.s64 = ctx.r26.s32 >> 3;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addze r10,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r10.s64 = temp.s64;
	// li r3,24
	ctx.r3.s64 = 24;
	// add r25,r11,r10
	ctx.r25.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881534c8
	ctx.lr = 0x880A8254;
	sub_881534C8(ctx, base);
	// extsh r7,r3
	ctx.r7.s64 = ctx.r3.s16;
	// subf r11,r14,r7
	ctx.r11.s64 = ctx.r7.s64 - ctx.r14.s64;
	// addi r5,r11,244
	ctx.r5.s64 = ctx.r11.s64 + 244;
loc_880A8260:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x880f5570
	ctx.lr = 0x880A826C;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x880a8280
	if (ctx.cr6.eq) goto loc_880A8280;
	// stw r16,148(r27)
	PPC_STORE_U32(ctx.r27.u32 + 148, ctx.r16.u32);
	// lwz r11,36(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 36);
	// stw r11,144(r27)
	PPC_STORE_U32(ctx.r27.u32 + 144, ctx.r11.u32);
loc_880A8280:
	// cmpwi cr6,r26,5
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 5, ctx.xer);
	// ble cr6,0x880a82a0
	if (!ctx.cr6.gt) goto loc_880A82A0;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x880a82b4
	if (ctx.cr6.eq) goto loc_880A82B4;
	// lwz r11,4(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r10,112(r27)
	PPC_STORE_U32(ctx.r27.u32 + 112, ctx.r10.u32);
loc_880A82A0:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x880a82b4
	if (ctx.cr6.eq) goto loc_880A82B4;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r15,140(r27)
	PPC_STORE_U32(ctx.r27.u32 + 140, ctx.r15.u32);
	// stw r11,100(r27)
	PPC_STORE_U32(ctx.r27.u32 + 100, ctx.r11.u32);
loc_880A82B4:
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// addi r28,r28,40
	ctx.r28.s64 = ctx.r28.s64 + 40;
	// cmplwi cr6,r26,11
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 11, ctx.xer);
	// blt cr6,0x880a8130
	if (ctx.cr6.lt) goto loc_880A8130;
	// li r11,2
	ctx.r11.s64 = 2;
	// li r10,48
	ctx.r10.s64 = 48;
	// li r9,496
	ctx.r9.s64 = 496;
	// stw r11,40(r18)
	PPC_STORE_U32(ctx.r18.u32 + 40, ctx.r11.u32);
	// li r8,3
	ctx.r8.s64 = 3;
	// stw r10,20(r18)
	PPC_STORE_U32(ctx.r18.u32 + 20, ctx.r10.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r9,24(r18)
	PPC_STORE_U32(ctx.r18.u32 + 24, ctx.r9.u32);
	// stw r8,28(r18)
	PPC_STORE_U32(ctx.r18.u32 + 28, ctx.r8.u32);
	// stw r7,32(r18)
	PPC_STORE_U32(ctx.r18.u32 + 32, ctx.r7.u32);
	// stw r11,44(r18)
	PPC_STORE_U32(ctx.r18.u32 + 44, ctx.r11.u32);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
loc_880A82F8:
	// lwz r11,40(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 40);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,40(r18)
	PPC_STORE_U32(ctx.r18.u32 + 40, ctx.r11.u32);
	// bge 0x880a88b4
	if (!ctx.cr0.lt) goto loc_880A88B4;
	// lwz r11,44(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 44);
	// lwz r8,48(r18)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r18.u32 + 48);
	// cmpwi cr6,r8,11
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 11, ctx.xer);
	// stw r11,40(r18)
	PPC_STORE_U32(ctx.r18.u32 + 40, ctx.r11.u32);
	// blt cr6,0x880a8324
	if (ctx.cr6.lt) goto loc_880A8324;
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r11,40(r18)
	PPC_STORE_U32(ctx.r18.u32 + 40, ctx.r11.u32);
loc_880A8324:
	// cmpwi cr6,r8,14
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 14, ctx.xer);
	// blt cr6,0x880a8334
	if (ctx.cr6.lt) goto loc_880A8334;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,40(r18)
	PPC_STORE_U32(ctx.r18.u32 + 40, ctx.r11.u32);
loc_880A8334:
	// lis r9,-30682
	ctx.r9.s64 = -2010775552;
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// lis r11,-30679
	ctx.r11.s64 = -2010578944;
	// cmpwi cr6,r8,16
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16, ctx.xer);
	// addi r30,r9,-19424
	ctx.r30.s64 = ctx.r9.s64 + -19424;
	// addi r31,r10,32248
	ctx.r31.s64 = ctx.r10.s64 + 32248;
	// addi r29,r11,-15272
	ctx.r29.s64 = ctx.r11.s64 + -15272;
	// bne cr6,0x880a839c
	if (!ctx.cr6.eq) goto loc_880A839C;
	// lwz r9,24(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// li r10,6
	ctx.r10.s64 = 6;
	// stw r14,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r14.u32);
	// mr r11,r14
	ctx.r11.u64 = ctx.r14.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// addi r3,r30,400
	ctx.r3.s64 = ctx.r30.s64 + 400;
	// li r6,62
	ctx.r6.s64 = 62;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r9,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r9.u32);
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r7,36(r18)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r18.u32 + 36);
	// lwz r11,4(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 4);
	// addis r8,r11,40
	ctx.r8.s64 = ctx.r11.s64 + 2621440;
	// lwz r10,8(r18)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// addis r9,r10,-24
	ctx.r9.s64 = ctx.r10.s64 + -1572864;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// bl 0x880a79e0
	ctx.lr = 0x880A839C;
	sub_880A79E0(ctx, base);
loc_880A839C:
	// lwz r11,48(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 48);
	// cmpwi cr6,r11,18
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 18, ctx.xer);
	// bne cr6,0x880a83f0
	if (!ctx.cr6.eq) goto loc_880A83F0;
	// li r10,6
	ctx.r10.s64 = 6;
	// stw r14,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r14.u32);
	// lwz r9,24(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// mr r11,r14
	ctx.r11.u64 = ctx.r14.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// addi r3,r30,760
	ctx.r3.s64 = ctx.r30.s64 + 760;
	// li r6,62
	ctx.r6.s64 = 62;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,9
	ctx.r4.s64 = 9;
	// stw r9,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r9.u32);
	// lwz r11,4(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 4);
	// lwz r9,8(r18)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// addis r8,r9,32
	ctx.r8.s64 = ctx.r9.s64 + 2097152;
	// addis r10,r11,-96
	ctx.r10.s64 = ctx.r11.s64 + -6291456;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// lwz r7,36(r18)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r18.u32 + 36);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x880a79e0
	ctx.lr = 0x880A83F0;
	sub_880A79E0(ctx, base);
loc_880A83F0:
	// lwz r11,48(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 48);
	// cmpwi cr6,r11,18
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 18, ctx.xer);
	// bne cr6,0x880a8408
	if (!ctx.cr6.eq) goto loc_880A8408;
	// li r10,15
	ctx.r10.s64 = 15;
	// cmpwi cr6,r11,18
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 18, ctx.xer);
	// stw r10,40(r18)
	PPC_STORE_U32(ctx.r18.u32 + 40, ctx.r10.u32);
loc_880A8408:
	// ble cr6,0x880a8414
	if (!ctx.cr6.gt) goto loc_880A8414;
	// li r10,6
	ctx.r10.s64 = 6;
	// stw r10,40(r18)
	PPC_STORE_U32(ctx.r18.u32 + 40, ctx.r10.u32);
loc_880A8414:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,48(r18)
	PPC_STORE_U32(ctx.r18.u32 + 48, ctx.r11.u32);
	// cmpwi cr6,r11,23
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 23, ctx.xer);
	// blt cr6,0x880a88b4
	if (ctx.cr6.lt) goto loc_880A88B4;
	// li r11,23
	ctx.r11.s64 = 23;
	// stw r14,40(r18)
	PPC_STORE_U32(ctx.r18.u32 + 40, ctx.r14.u32);
	// li r10,8
	ctx.r10.s64 = 8;
	// stw r14,44(r18)
	PPC_STORE_U32(ctx.r18.u32 + 44, ctx.r14.u32);
	// li r9,4
	ctx.r9.s64 = 4;
	// stw r11,48(r18)
	PPC_STORE_U32(ctx.r18.u32 + 48, ctx.r11.u32);
	// stw r10,32(r18)
	PPC_STORE_U32(ctx.r18.u32 + 32, ctx.r10.u32);
	// stw r9,28(r18)
	PPC_STORE_U32(ctx.r18.u32 + 28, ctx.r9.u32);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
loc_880A844C:
	// lwz r11,32(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 32);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,32(r18)
	PPC_STORE_U32(ctx.r18.u32 + 32, ctx.r11.u32);
	// bge 0x880a88b4
	if (!ctx.cr0.lt) goto loc_880A88B4;
	// lwz r11,40(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 40);
	// stw r14,32(r18)
	PPC_STORE_U32(ctx.r18.u32 + 32, ctx.r14.u32);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,40(r18)
	PPC_STORE_U32(ctx.r18.u32 + 40, ctx.r11.u32);
	// bge 0x880a88b4
	if (!ctx.cr0.lt) goto loc_880A88B4;
	// lwz r11,44(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 44);
	// lwz r10,48(r18)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r18.u32 + 48);
	// cmpwi cr6,r10,23
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 23, ctx.xer);
	// stw r11,40(r18)
	PPC_STORE_U32(ctx.r18.u32 + 40, ctx.r11.u32);
	// bne cr6,0x880a8804
	if (!ctx.cr6.eq) goto loc_880A8804;
	// lis r10,-30679
	ctx.r10.s64 = -2010578944;
	// stw r14,24(r18)
	PPC_STORE_U32(ctx.r18.u32 + 24, ctx.r14.u32);
	// li r16,1
	ctx.r16.s64 = 1;
	// addi r8,r10,-15272
	ctx.r8.s64 = ctx.r10.s64 + -15272;
	// li r11,80
	ctx.r11.s64 = 80;
	// stw r16,40(r18)
	PPC_STORE_U32(ctx.r18.u32 + 40, ctx.r16.u32);
	// lis r9,-30643
	ctx.r9.s64 = -2008219648;
	// stw r16,44(r18)
	PPC_STORE_U32(ctx.r18.u32 + 44, ctx.r16.u32);
	// stw r11,20(r18)
	PPC_STORE_U32(ctx.r18.u32 + 20, ctx.r11.u32);
	// li r10,6
	ctx.r10.s64 = 6;
	// stw r16,56(r18)
	PPC_STORE_U32(ctx.r18.u32 + 56, ctx.r16.u32);
	// addi r7,r9,32248
	ctx.r7.s64 = ctx.r9.s64 + 32248;
	// stw r10,32248(r9)
	PPC_STORE_U32(ctx.r9.u32 + 32248, ctx.r10.u32);
	// mr r11,r14
	ctx.r11.u64 = ctx.r14.u64;
	// lwz r9,24(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// lis r10,-30682
	ctx.r10.s64 = -2010775552;
	// stw r9,16(r7)
	PPC_STORE_U32(ctx.r7.u32 + 16, ctx.r9.u32);
	// li r6,63
	ctx.r6.s64 = 63;
	// stw r14,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r14.u32);
	// addi r22,r10,-19424
	ctx.r22.s64 = ctx.r10.s64 + -19424;
	// lwz r11,4(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 4);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r7,36(r18)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r18.u32 + 36);
	// addi r3,r22,1120
	ctx.r3.s64 = ctx.r22.s64 + 1120;
	// lwz r10,8(r18)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// addis r9,r10,-48
	ctx.r9.s64 = ctx.r10.s64 + -3145728;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// li r4,18
	ctx.r4.s64 = 18;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// bl 0x880a79e0
	ctx.lr = 0x880A84FC;
	sub_880A79E0(ctx, base);
	// addi r3,r22,1840
	ctx.r3.s64 = ctx.r22.s64 + 1840;
	// li r6,64
	ctx.r6.s64 = 64;
	// lwz r7,36(r18)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r18.u32 + 36);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,12
	ctx.r4.s64 = 12;
	// bl 0x880a79e0
	ctx.lr = 0x880A8514;
	sub_880A79E0(ctx, base);
	// lwz r8,4(r18)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r18.u32 + 4);
	// lwz r11,8(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// lis r30,112
	ctx.r30.s64 = 7340032;
	// lis r31,56
	ctx.r31.s64 = 3670016;
	// lwz r7,36(r18)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r18.u32 + 36);
	// subf r10,r30,r8
	ctx.r10.s64 = ctx.r8.s64 - ctx.r30.s64;
	// subf r9,r31,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r31.s64;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r3,r22,1120
	ctx.r3.s64 = ctx.r22.s64 + 1120;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// li r6,62
	ctx.r6.s64 = 62;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,18
	ctx.r4.s64 = 18;
	// bl 0x880a79e0
	ctx.lr = 0x880A854C;
	sub_880A79E0(ctx, base);
	// lwz r8,4(r18)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r18.u32 + 4);
	// lwz r11,8(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// addi r3,r22,1120
	ctx.r3.s64 = ctx.r22.s64 + 1120;
	// add r10,r8,r30
	ctx.r10.u64 = ctx.r8.u64 + ctx.r30.u64;
	// lwz r7,36(r18)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r18.u32 + 36);
	// subf r9,r31,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r31.s64;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// li r6,62
	ctx.r6.s64 = 62;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,18
	ctx.r4.s64 = 18;
	// bl 0x880a79e0
	ctx.lr = 0x880A857C;
	sub_880A79E0(ctx, base);
	// lwz r6,8(r18)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// li r8,62
	ctx.r8.s64 = 62;
	// li r7,59
	ctx.r7.s64 = 59;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// mr r27,r14
	ctx.r27.u64 = ctx.r14.u64;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// addi r31,r22,20
	ctx.r31.s64 = ctx.r22.s64 + 20;
	// addis r23,r6,40
	ctx.r23.s64 = ctx.r6.s64 + 2621440;
	// li r21,10
	ctx.r21.s64 = 10;
	// lis r19,-30667
	ctx.r19.s64 = -2009792512;
	// lis r25,-30667
	ctx.r25.s64 = -2009792512;
	// lis r26,-30667
	ctx.r26.s64 = -2009792512;
	// lis r20,-30667
	ctx.r20.s64 = -2009792512;
	// lwz r24,4(r18)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r18.u32 + 4);
loc_880A85B4:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x881534c8
	ctx.lr = 0x880A85BC;
	sub_881534C8(ctx, base);
	// extsh r29,r3
	ctx.r29.s64 = ctx.r3.s16;
	// li r3,32
	ctx.r3.s64 = 32;
	// lwz r30,-20(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + -20);
	// bl 0x881534c8
	ctx.lr = 0x880A85CC;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,32
	ctx.r3.s64 = 32;
	// addi r11,r11,-16
	ctx.r11.s64 = ctx.r11.s64 + -16;
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r24
	ctx.r11.u64 = ctx.r11.u64 + ctx.r24.u64;
	// stw r11,12364(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12364, ctx.r11.u32);
	// bl 0x881534c8
	ctx.lr = 0x880A85E8;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// rlwinm r10,r29,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-16
	ctx.r9.s64 = ctx.r11.s64 + -16;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// rlwinm r11,r9,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// add r11,r11,r23
	ctx.r11.u64 = ctx.r11.u64 + ctx.r23.u64;
	// stw r11,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r11.u32);
	// lwzx r4,r10,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880A8610;
	sub_880F52C8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r3,16
	ctx.r3.s64 = 16;
	// lwz r29,-4(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + -4);
	// bl 0x881534c8
	ctx.lr = 0x880A8620;
	sub_881534C8(ctx, base);
	// rlwinm r11,r29,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 3) & 0xFFFFFFF8;
	// srawi r7,r27,3
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x7) != 0);
	ctx.r7.s64 = ctx.r27.s32 >> 3;
	// lwz r28,0(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// add r6,r29,r11
	ctx.r6.u64 = ctx.r29.u64 + ctx.r11.u64;
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// divw r9,r6,r21
	ctx.r9.s32 = ppc_divw(ctx.r6.s32, ctx.r21.s32);
	// addze r10,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r10.s64 = temp.s64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// li r3,8
	ctx.r3.s64 = 8;
	// add r29,r11,r10
	ctx.r29.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881534c8
	ctx.lr = 0x880A864C;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r5,r11,252
	ctx.r5.s64 = ctx.r11.s64 + 252;
	// bl 0x880f5570
	ctx.lr = 0x880A8664;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x880a8674
	if (ctx.cr6.eq) goto loc_880A8674;
	// lwz r11,36(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 36);
	// stw r11,144(r30)
	PPC_STORE_U32(ctx.r30.u32 + 144, ctx.r11.u32);
loc_880A8674:
	// cmpwi cr6,r27,5
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 5, ctx.xer);
	// ble cr6,0x880a868c
	if (!ctx.cr6.gt) goto loc_880A868C;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x880a868c
	if (ctx.cr6.eq) goto loc_880A868C;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,112(r30)
	PPC_STORE_U32(ctx.r30.u32 + 112, ctx.r11.u32);
loc_880A868C:
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// addi r31,r31,40
	ctx.r31.s64 = ctx.r31.s64 + 40;
	// cmplwi cr6,r27,10
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 10, ctx.xer);
	// blt cr6,0x880a85b4
	if (ctx.cr6.lt) goto loc_880A85B4;
	// addis r27,r24,16
	ctx.r27.s64 = ctx.r24.s64 + 1048576;
	// addis r24,r23,4
	ctx.r24.s64 = ctx.r23.s64 + 262144;
	// mr r28,r14
	ctx.r28.u64 = ctx.r14.u64;
	// addi r30,r22,20
	ctx.r30.s64 = ctx.r22.s64 + 20;
loc_880A86AC:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x881534c8
	ctx.lr = 0x880A86B4;
	sub_881534C8(ctx, base);
	// lwz r31,-20(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + -20);
	// extsh r29,r3
	ctx.r29.s64 = ctx.r3.s16;
	// li r3,32
	ctx.r3.s64 = 32;
	// stw r31,12380(r20)
	PPC_STORE_U32(ctx.r20.u32 + 12380, ctx.r31.u32);
	// bl 0x881534c8
	ctx.lr = 0x880A86C8;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,32
	ctx.r3.s64 = 32;
	// addi r11,r11,-16
	ctx.r11.s64 = ctx.r11.s64 + -16;
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
	// stw r11,12364(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12364, ctx.r11.u32);
	// bl 0x881534c8
	ctx.lr = 0x880A86E4;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// rlwinm r10,r29,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-16
	ctx.r9.s64 = ctx.r11.s64 + -16;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// rlwinm r11,r9,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// add r11,r11,r24
	ctx.r11.u64 = ctx.r11.u64 + ctx.r24.u64;
	// stw r11,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r11.u32);
	// lwzx r4,r10,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// stw r4,12376(r19)
	PPC_STORE_U32(ctx.r19.u32 + 12376, ctx.r4.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880A8710;
	sub_880F52C8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r3,16
	ctx.r3.s64 = 16;
	// lwz r29,-4(r30)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r30.u32 + -4);
	// bl 0x881534c8
	ctx.lr = 0x880A8720;
	sub_881534C8(ctx, base);
	// rlwinm r11,r29,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 3) & 0xFFFFFFF8;
	// srawi r7,r28,3
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0x7) != 0);
	ctx.r7.s64 = ctx.r28.s32 >> 3;
	// lwz r23,0(r30)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// add r6,r29,r11
	ctx.r6.u64 = ctx.r29.u64 + ctx.r11.u64;
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// divw r9,r6,r21
	ctx.r9.s32 = ppc_divw(ctx.r6.s32, ctx.r21.s32);
	// addze r10,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r10.s64 = temp.s64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// li r3,8
	ctx.r3.s64 = 8;
	// add r29,r11,r10
	ctx.r29.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881534c8
	ctx.lr = 0x880A874C;
	sub_881534C8(ctx, base);
	// extsh r5,r3
	ctx.r5.s64 = ctx.r3.s16;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// subf r11,r23,r5
	ctx.r11.s64 = ctx.r5.s64 - ctx.r23.s64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r5,r11,252
	ctx.r5.s64 = ctx.r11.s64 + 252;
	// bl 0x880f5570
	ctx.lr = 0x880A8764;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x880a8778
	if (ctx.cr6.eq) goto loc_880A8778;
	// stw r16,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r16.u32);
	// lwz r11,36(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 36);
	// stw r11,144(r31)
	PPC_STORE_U32(ctx.r31.u32 + 144, ctx.r11.u32);
loc_880A8778:
	// cmpwi cr6,r28,5
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 5, ctx.xer);
	// ble cr6,0x880a8798
	if (!ctx.cr6.gt) goto loc_880A8798;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x880a8798
	if (ctx.cr6.eq) goto loc_880A8798;
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r10,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r10.u32);
loc_880A8798:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r30,r30,40
	ctx.r30.s64 = ctx.r30.s64 + 40;
	// cmplwi cr6,r28,10
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 10, ctx.xer);
	// blt cr6,0x880a86ac
	if (ctx.cr6.lt) goto loc_880A86AC;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// addi r7,r11,30408
	ctx.r7.s64 = ctx.r11.s64 + 30408;
	// addi r6,r10,9552
	ctx.r6.s64 = ctx.r10.s64 + 9552;
	// lwz r11,372(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 372);
	// lwz r10,376(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 376);
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// lwz r9,32(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 32);
	// addi r10,r10,44
	ctx.r10.s64 = ctx.r10.s64 + 44;
	// addi r5,r11,128
	ctx.r5.s64 = ctx.r11.s64 + 128;
	// stw r11,372(r7)
	PPC_STORE_U32(ctx.r7.u32 + 372, ctx.r11.u32);
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r10,376(r7)
	PPC_STORE_U32(ctx.r7.u32 + 376, ctx.r10.u32);
	// rlwinm r3,r5,2,21,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x7FC;
	// lwzx r11,r4,r6
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r6.u32);
	// lwzx r6,r3,r6
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r6.u32);
	// mullw r8,r11,r10
	ctx.r8.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// stw r8,380(r7)
	PPC_STORE_U32(ctx.r7.u32 + 380, ctx.r8.u32);
	// mullw r11,r6,r10
	ctx.r11.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r10.s32);
	// stw r11,384(r7)
	PPC_STORE_U32(ctx.r7.u32 + 384, ctx.r11.u32);
	// stw r8,244(r9)
	PPC_STORE_U32(ctx.r9.u32 + 244, ctx.r8.u32);
	// neg r5,r11
	ctx.r5.s64 = -ctx.r11.s64;
	// stw r5,248(r9)
	PPC_STORE_U32(ctx.r9.u32 + 248, ctx.r5.u32);
loc_880A8804:
	// lwz r11,48(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 48);
	// cmpwi cr6,r11,29
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 29, ctx.xer);
	// blt cr6,0x880a8818
	if (ctx.cr6.lt) goto loc_880A8818;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r10,40(r18)
	PPC_STORE_U32(ctx.r18.u32 + 40, ctx.r10.u32);
loc_880A8818:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,48(r18)
	PPC_STORE_U32(ctx.r18.u32 + 48, ctx.r11.u32);
	// cmpwi cr6,r11,31
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 31, ctx.xer);
	// blt cr6,0x880a88b4
	if (ctx.cr6.lt) goto loc_880A88B4;
	// li r11,31
	ctx.r11.s64 = 31;
	// stw r14,32(r18)
	PPC_STORE_U32(ctx.r18.u32 + 32, ctx.r14.u32);
	// li r10,5
	ctx.r10.s64 = 5;
	// li r9,64
	ctx.r9.s64 = 64;
	// stw r11,48(r18)
	PPC_STORE_U32(ctx.r18.u32 + 48, ctx.r11.u32);
	// stw r10,28(r18)
	PPC_STORE_U32(ctx.r18.u32 + 28, ctx.r10.u32);
	// stw r9,12(r18)
	PPC_STORE_U32(ctx.r18.u32 + 12, ctx.r9.u32);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
loc_880A884C:
	// lwz r11,8(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// lis r10,320
	ctx.r10.s64 = 20971520;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x880a88b4
	if (!ctx.cr6.gt) goto loc_880A88B4;
	// li r11,10
	ctx.r11.s64 = 10;
	// stw r11,28(r18)
	PPC_STORE_U32(ctx.r18.u32 + 28, ctx.r11.u32);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
loc_880A886C:
	// lwz r11,8(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lwz r10,4(r18)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r18.u32 + 4);
	// li r3,208
	ctx.r3.s64 = 208;
	// addis r5,r11,80
	ctx.r5.s64 = ctx.r11.s64 + 5242880;
	// addis r4,r10,-16
	ctx.r4.s64 = ctx.r10.s64 + -1048576;
	// bl 0x880958a0
	ctx.lr = 0x880A8888;
	sub_880958A0(ctx, base);
	// li r9,20
	ctx.r9.s64 = 20;
	// li r8,2
	ctx.r8.s64 = 2;
	// stw r9,28(r18)
	PPC_STORE_U32(ctx.r18.u32 + 28, ctx.r9.u32);
	// stw r8,32(r18)
	PPC_STORE_U32(ctx.r18.u32 + 32, ctx.r8.u32);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
loc_880A88A0:
	// lwz r11,32(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 32);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,32(r18)
	PPC_STORE_U32(ctx.r18.u32 + 32, ctx.r11.u32);
	// bgt 0x880a88b4
	if (ctx.cr0.gt) goto loc_880A88B4;
	// bl 0x88094220
	ctx.lr = 0x880A88B4;
	sub_88094220(ctx, base);
loc_880A88B4:
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A88BC"))) PPC_WEAK_FUNC(sub_880A88BC);
PPC_FUNC_IMPL(__imp__sub_880A88BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A88C0"))) PPC_WEAK_FUNC(sub_880A88C0);
PPC_FUNC_IMPL(__imp__sub_880A88C0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x880A88C8;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r9,184(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// lwz r10,168(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// add r26,r9,r10
	ctx.r26.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r27,48(r11)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r11.u32 + 48);
	// cmpwi cr6,r27,9
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 9, ctx.xer);
	// ble cr6,0x880a88ec
	if (!ctx.cr6.gt) goto loc_880A88EC;
	// li r26,60
	ctx.r26.s64 = 60;
loc_880A88EC:
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 56);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880a8904
	if (ctx.cr6.eq) goto loc_880A8904;
	// lwz r29,4(r11)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r28,8(r11)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x880a8920
	goto loc_880A8920;
loc_880A8904:
	// lwz r10,2300(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2300);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r7,156(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 156);
	// lwz r6,160(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 160);
	// subf r29,r7,r9
	ctx.r29.s64 = ctx.r9.s64 - ctx.r7.s64;
	// subf r28,r6,r8
	ctx.r28.s64 = ctx.r8.s64 - ctx.r6.s64;
loc_880A8920:
	// lis r11,-30682
	ctx.r11.s64 = -2010775552;
	// rlwinm r30,r27,3,0,28
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r31,r11,-21416
	ctx.r31.s64 = ctx.r11.s64 + -21416;
	// li r6,40
	ctx.r6.s64 = 40;
	// addi r11,r31,-8288
	ctx.r11.s64 = ctx.r31.s64 + -8288;
	// addi r10,r31,-8288
	ctx.r10.s64 = ctx.r31.s64 + -8288;
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// addi r11,r31,256
	ctx.r11.s64 = ctx.r31.s64 + 256;
	// add r3,r30,r11
	ctx.r3.u64 = ctx.r30.u64 + ctx.r11.u64;
	// lwzx r11,r30,r10
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r10.u32);
	// lwzx r10,r30,r9
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r9.u32);
	// addi r8,r11,16
	ctx.r8.s64 = ctx.r11.s64 + 16;
	// addi r7,r10,-52
	ctx.r7.s64 = ctx.r10.s64 + -52;
	// rlwinm r11,r8,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r7,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r11,r29
	ctx.r4.u64 = ctx.r11.u64 + ctx.r29.u64;
	// add r5,r10,r28
	ctx.r5.u64 = ctx.r10.u64 + ctx.r28.u64;
	// bl 0x880a7bf8
	ctx.lr = 0x880A8968;
	sub_880A7BF8(ctx, base);
	// addi r11,r31,-8352
	ctx.r11.s64 = ctx.r31.s64 + -8352;
	// rlwinm r5,r27,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// addi r11,r31,-8352
	ctx.r11.s64 = ctx.r31.s64 + -8352;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// add r3,r30,r31
	ctx.r3.u64 = ctx.r30.u64 + ctx.r31.u64;
	// lbzx r10,r5,r4
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r4.u32);
	// lbzx r9,r5,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r11.u32);
	// extsb r8,r10
	ctx.r8.s64 = ctx.r10.s8;
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// rlwinm r10,r8,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r7,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// add r5,r10,r28
	ctx.r5.u64 = ctx.r10.u64 + ctx.r28.u64;
	// add r4,r11,r29
	ctx.r4.u64 = ctx.r11.u64 + ctx.r29.u64;
	// bl 0x880a7bf8
	ctx.lr = 0x880A89A4;
	sub_880A7BF8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A89AC"))) PPC_WEAK_FUNC(sub_880A89AC);
PPC_FUNC_IMPL(__imp__sub_880A89AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A89B0"))) PPC_WEAK_FUNC(sub_880A89B0);
PPC_FUNC_IMPL(__imp__sub_880A89B0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880A89B8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-30643
	ctx.r30.s64 = -2008219648;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r11,26272(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 26272);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880a8ae0
	if (!ctx.cr6.eq) goto loc_880A8AE0;
	// bl 0x880a7c78
	ctx.lr = 0x880A89D8;
	sub_880A7C78(ctx, base);
	// lwz r11,26272(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 26272);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880a89ec
	if (ctx.cr6.eq) goto loc_880A89EC;
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x880a8a04
	goto loc_880A8A04;
loc_880A89EC:
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// addi r9,r11,51
	ctx.r9.s64 = ctx.r11.s64 + 51;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-11984(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11984);
	// lwzx r8,r8,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
loc_880A8A04:
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// clrlwi r10,r10,23
	ctx.r10.u64 = ctx.r10.u32 & 0x1FF;
	// lwz r4,56(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// addi r11,r11,9552
	ctx.r11.s64 = ctx.r11.s64 + 9552;
	// lwz r6,12(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r5,r10,128
	ctx.r5.s64 = ctx.r10.s64 + 128;
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// rlwinm r3,r10,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r5,r5,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x7FC;
	// add r10,r9,r8
	ctx.r10.u64 = ctx.r9.u64 + ctx.r8.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// lwzx r4,r3,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r11.u32);
	// mullw r8,r4,r6
	ctx.r8.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r6.s32);
	// lwzx r3,r5,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r11.u32);
	// mullw r9,r3,r6
	ctx.r9.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r6.s32);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r10,r9,r7
	ctx.r10.u64 = ctx.r9.u64 + ctx.r7.u64;
	// stw r8,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// bne cr6,0x880a8a98
	if (!ctx.cr6.eq) goto loc_880A8A98;
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lwz r7,2300(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 2300);
	// rlwinm r8,r9,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r5,r9,34
	ctx.r5.s64 = ctx.r9.s64 + 34;
	// add r4,r8,r7
	ctx.r4.u64 = ctx.r8.u64 + ctx.r7.u64;
	// rlwinm r3,r5,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r9,268(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 268);
	// subf r8,r9,r6
	ctx.r8.s64 = ctx.r6.s64 - ctx.r9.s64;
	// stw r8,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// lwz r7,2300(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 2300);
	// lwzx r6,r3,r7
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r7.u32);
	// subf r5,r6,r10
	ctx.r5.s64 = ctx.r10.s64 - ctx.r6.s64;
	// stw r5,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r5.u32);
loc_880A8A98:
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880a8ae0
	if (ctx.cr6.eq) goto loc_880A8AE0;
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// clrlwi r9,r9,23
	ctx.r9.u64 = ctx.r9.u32 & 0x1FF;
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r6,r9,128
	ctx.r6.s64 = ctx.r9.s64 + 128;
	// rlwinm r5,r9,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r4,r6,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// lwzx r3,r5,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r11.u32);
	// lwzx r11,r4,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r11.u32);
	// mullw r9,r3,r10
	ctx.r9.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r10.s32);
	// mullw r11,r11,r10
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// add r10,r9,r7
	ctx.r10.u64 = ctx.r9.u64 + ctx.r7.u64;
	// add r9,r11,r8
	ctx.r9.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
loc_880A8AE0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A8AE8"))) PPC_WEAK_FUNC(sub_880A8AE8);
PPC_FUNC_IMPL(__imp__sub_880A8AE8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880A8AF0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30709
	ctx.r11.s64 = -2012545024;
	// li r4,60
	ctx.r4.s64 = 60;
	// addi r5,r11,-29976
	ctx.r5.s64 = ctx.r11.s64 + -29976;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x880A8B08;
	sub_88094290(ctx, base);
	// li r5,60
	ctx.r5.s64 = 60;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r30,2304(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2304);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88073bd0
	ctx.lr = 0x880A8B1C;
	sub_88073BD0(ctx, base);
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r8,152
	ctx.r8.s64 = 9961472;
	// stw r10,36(r30)
	PPC_STORE_U32(ctx.r30.u32 + 36, ctx.r10.u32);
	// lis r7,192
	ctx.r7.s64 = 12582912;
	// lis r6,-30709
	ctx.r6.s64 = -2012545024;
	// lwz r9,-11984(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + -11984);
	// lis r5,-30709
	ctx.r5.s64 = -2012545024;
	// lis r4,-30710
	ctx.r4.s64 = -2012610560;
	// li r3,40
	ctx.r3.s64 = 40;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r29,255
	ctx.r29.s64 = 255;
	// addi r6,r6,-30288
	ctx.r6.s64 = ctx.r6.s64 + -30288;
	// addi r5,r5,-30528
	ctx.r5.s64 = ctx.r5.s64 + -30528;
	// addi r4,r4,31192
	ctx.r4.s64 = ctx.r4.s64 + 31192;
	// lwz r9,224(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 224);
	// subf r8,r9,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r9.s64;
	// stw r8,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r8.u32);
	// stw r7,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r7.u32);
	// stw r3,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r3.u32);
	// stw r31,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r31.u32);
	// stw r11,28(r30)
	PPC_STORE_U32(ctx.r30.u32 + 28, ctx.r11.u32);
	// stw r11,32(r30)
	PPC_STORE_U32(ctx.r30.u32 + 32, ctx.r11.u32);
	// stw r10,40(r30)
	PPC_STORE_U32(ctx.r30.u32 + 40, ctx.r10.u32);
	// stw r10,44(r30)
	PPC_STORE_U32(ctx.r30.u32 + 44, ctx.r10.u32);
	// stw r29,52(r30)
	PPC_STORE_U32(ctx.r30.u32 + 52, ctx.r29.u32);
	// stw r11,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r11.u32);
	// stw r11,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r11.u32);
	// stw r6,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r6.u32);
	// stw r5,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r5.u32);
	// stw r4,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r4.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A8BA0"))) PPC_WEAK_FUNC(sub_880A8BA0);
PPC_FUNC_IMPL(__imp__sub_880A8BA0) {
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
	// lwz r4,296(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 296);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x880a8bc0
	if (ctx.cr6.eq) goto loc_880A8BC0;
	// bl 0x88093ae8
	ctx.lr = 0x880A8BC0;
	sub_88093AE8(ctx, base);
loc_880A8BC0:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,296(r7)
	PPC_STORE_U32(ctx.r7.u32 + 296, ctx.r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880A8BD8"))) PPC_WEAK_FUNC(sub_880A8BD8);
PPC_FUNC_IMPL(__imp__sub_880A8BD8) {
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
	// lwz r4,280(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 280);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x880a8bf8
	if (ctx.cr6.eq) goto loc_880A8BF8;
	// bl 0x88093ae8
	ctx.lr = 0x880A8BF8;
	sub_88093AE8(ctx, base);
loc_880A8BF8:
	// lwz r4,284(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 284);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x880a8c08
	if (ctx.cr6.eq) goto loc_880A8C08;
	// bl 0x88093ae8
	ctx.lr = 0x880A8C08;
	sub_88093AE8(ctx, base);
loc_880A8C08:
	// lwz r4,288(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 288);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x880a8c18
	if (ctx.cr6.eq) goto loc_880A8C18;
	// bl 0x88093ae8
	ctx.lr = 0x880A8C18;
	sub_88093AE8(ctx, base);
loc_880A8C18:
	// lwz r4,292(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 292);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x880a8c28
	if (ctx.cr6.eq) goto loc_880A8C28;
	// bl 0x88093ae8
	ctx.lr = 0x880A8C28;
	sub_88093AE8(ctx, base);
loc_880A8C28:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,280(r7)
	PPC_STORE_U32(ctx.r7.u32 + 280, ctx.r11.u32);
	// stw r11,284(r7)
	PPC_STORE_U32(ctx.r7.u32 + 284, ctx.r11.u32);
	// stw r11,288(r7)
	PPC_STORE_U32(ctx.r7.u32 + 288, ctx.r11.u32);
	// stw r11,292(r7)
	PPC_STORE_U32(ctx.r7.u32 + 292, ctx.r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880A8C4C"))) PPC_WEAK_FUNC(sub_880A8C4C);
PPC_FUNC_IMPL(__imp__sub_880A8C4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A8C50"))) PPC_WEAK_FUNC(sub_880A8C50);
PPC_FUNC_IMPL(__imp__sub_880A8C50) {
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
	// lwz r4,272(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 272);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x880a8c70
	if (ctx.cr6.eq) goto loc_880A8C70;
	// bl 0x88093ae8
	ctx.lr = 0x880A8C70;
	sub_88093AE8(ctx, base);
loc_880A8C70:
	// lwz r4,276(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 276);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x880a8c80
	if (ctx.cr6.eq) goto loc_880A8C80;
	// bl 0x88093ae8
	ctx.lr = 0x880A8C80;
	sub_88093AE8(ctx, base);
loc_880A8C80:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,272(r7)
	PPC_STORE_U32(ctx.r7.u32 + 272, ctx.r11.u32);
	// stw r11,276(r7)
	PPC_STORE_U32(ctx.r7.u32 + 276, ctx.r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880A8C9C"))) PPC_WEAK_FUNC(sub_880A8C9C);
PPC_FUNC_IMPL(__imp__sub_880A8C9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A8CA0"))) PPC_WEAK_FUNC(sub_880A8CA0);
PPC_FUNC_IMPL(__imp__sub_880A8CA0) {
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
	// lwz r4,264(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 264);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x880a8cc0
	if (ctx.cr6.eq) goto loc_880A8CC0;
	// bl 0x88093ae8
	ctx.lr = 0x880A8CC0;
	sub_88093AE8(ctx, base);
loc_880A8CC0:
	// lwz r4,268(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 268);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x880a8cd0
	if (ctx.cr6.eq) goto loc_880A8CD0;
	// bl 0x88093ae8
	ctx.lr = 0x880A8CD0;
	sub_88093AE8(ctx, base);
loc_880A8CD0:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,264(r7)
	PPC_STORE_U32(ctx.r7.u32 + 264, ctx.r11.u32);
	// stw r11,268(r7)
	PPC_STORE_U32(ctx.r7.u32 + 268, ctx.r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880A8CEC"))) PPC_WEAK_FUNC(sub_880A8CEC);
PPC_FUNC_IMPL(__imp__sub_880A8CEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A8CF0"))) PPC_WEAK_FUNC(sub_880A8CF0);
PPC_FUNC_IMPL(__imp__sub_880A8CF0) {
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
	ctx.lr = 0x880A8D1C;
	sub_88096BC8(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// cmpwi cr6,r10,6
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 6, ctx.xer);
	// beq cr6,0x880a8d40
	if (ctx.cr6.eq) goto loc_880A8D40;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880A8D38;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880a8da0
	goto loc_880A8DA0;
loc_880A8D40:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// bgt 0x880a8d9c
	if (ctx.cr0.gt) goto loc_880A8D9C;
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
	// cmpwi cr6,r8,8
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 8, ctx.xer);
	// blt cr6,0x880a8d9c
	if (ctx.cr6.lt) goto loc_880A8D9C;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,7
	ctx.r9.s64 = 7;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,68(r8)
	PPC_STORE_U32(ctx.r8.u32 + 68, ctx.r9.u32);
	// bl 0x88096b40
	ctx.lr = 0x880A8D94;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880a8da0
	goto loc_880A8DA0;
loc_880A8D9C:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880A8DA0:
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

__attribute__((alias("__imp__sub_880A8DB8"))) PPC_WEAK_FUNC(sub_880A8DB8);
PPC_FUNC_IMPL(__imp__sub_880A8DB8) {
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
	ctx.lr = 0x880A8DE4;
	sub_88096BC8(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// cmpwi cr6,r10,4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4, ctx.xer);
	// beq cr6,0x880a8e08
	if (ctx.cr6.eq) goto loc_880A8E08;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880A8E00;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880a8e68
	goto loc_880A8E68;
loc_880A8E08:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// bgt 0x880a8e64
	if (ctx.cr0.gt) goto loc_880A8E64;
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
	// cmpwi cr6,r8,16
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16, ctx.xer);
	// blt cr6,0x880a8e64
	if (ctx.cr6.lt) goto loc_880A8E64;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,5
	ctx.r9.s64 = 5;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,68(r8)
	PPC_STORE_U32(ctx.r8.u32 + 68, ctx.r9.u32);
	// bl 0x88096b40
	ctx.lr = 0x880A8E5C;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880a8e68
	goto loc_880A8E68;
loc_880A8E64:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880A8E68:
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

__attribute__((alias("__imp__sub_880A8E80"))) PPC_WEAK_FUNC(sub_880A8E80);
PPC_FUNC_IMPL(__imp__sub_880A8E80) {
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
	ctx.lr = 0x880A8EAC;
	sub_88096BC8(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// cmpwi cr6,r10,4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4, ctx.xer);
	// beq cr6,0x880a8ed0
	if (ctx.cr6.eq) goto loc_880A8ED0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880A8EC8;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880a8f2c
	goto loc_880A8F2C;
loc_880A8ED0:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// bgt 0x880a8f28
	if (ctx.cr0.gt) goto loc_880A8F28;
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
	// cmpwi cr6,r8,16
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16, ctx.xer);
	// blt cr6,0x880a8f28
	if (ctx.cr6.lt) goto loc_880A8F28;
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
	// stw r10,68(r11)
	PPC_STORE_U32(ctx.r11.u32 + 68, ctx.r10.u32);
	// bl 0x88096b40
	ctx.lr = 0x880A8F20;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880a8f2c
	goto loc_880A8F2C;
loc_880A8F28:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880A8F2C:
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

__attribute__((alias("__imp__sub_880A8F44"))) PPC_WEAK_FUNC(sub_880A8F44);
PPC_FUNC_IMPL(__imp__sub_880A8F44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A8F48"))) PPC_WEAK_FUNC(sub_880A8F48);
PPC_FUNC_IMPL(__imp__sub_880A8F48) {
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
	ctx.lr = 0x880A8F74;
	sub_88096BC8(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// beq cr6,0x880a8f98
	if (ctx.cr6.eq) goto loc_880A8F98;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880A8F90;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880a8ff4
	goto loc_880A8FF4;
loc_880A8F98:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// bgt 0x880a8ff0
	if (ctx.cr0.gt) goto loc_880A8FF0;
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
	// cmpwi cr6,r8,4
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 4, ctx.xer);
	// blt cr6,0x880a8ff0
	if (ctx.cr6.lt) goto loc_880A8FF0;
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
	// stw r10,68(r11)
	PPC_STORE_U32(ctx.r11.u32 + 68, ctx.r10.u32);
	// bl 0x88096b40
	ctx.lr = 0x880A8FE8;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880a8ff4
	goto loc_880A8FF4;
loc_880A8FF0:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880A8FF4:
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

__attribute__((alias("__imp__sub_880A900C"))) PPC_WEAK_FUNC(sub_880A900C);
PPC_FUNC_IMPL(__imp__sub_880A900C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A9010"))) PPC_WEAK_FUNC(sub_880A9010);
PPC_FUNC_IMPL(__imp__sub_880A9010) {
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
	ctx.lr = 0x880A903C;
	sub_88096BC8(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// beq cr6,0x880a9060
	if (ctx.cr6.eq) goto loc_880A9060;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880A9058;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880a90c0
	goto loc_880A90C0;
loc_880A9060:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// bgt 0x880a90bc
	if (ctx.cr0.gt) goto loc_880A90BC;
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
	// cmpwi cr6,r8,8
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 8, ctx.xer);
	// blt cr6,0x880a90bc
	if (ctx.cr6.lt) goto loc_880A90BC;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,68(r8)
	PPC_STORE_U32(ctx.r8.u32 + 68, ctx.r9.u32);
	// bl 0x88096b40
	ctx.lr = 0x880A90B4;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880a90c0
	goto loc_880A90C0;
loc_880A90BC:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880A90C0:
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

__attribute__((alias("__imp__sub_880A90D8"))) PPC_WEAK_FUNC(sub_880A90D8);
PPC_FUNC_IMPL(__imp__sub_880A90D8) {
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
	ctx.lr = 0x880A9104;
	sub_88096BC8(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// beq cr6,0x880a9128
	if (ctx.cr6.eq) goto loc_880A9128;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880A9120;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880a9188
	goto loc_880A9188;
loc_880A9128:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// bgt 0x880a9184
	if (ctx.cr0.gt) goto loc_880A9184;
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
	// cmpwi cr6,r8,23
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 23, ctx.xer);
	// blt cr6,0x880a9184
	if (ctx.cr6.lt) goto loc_880A9184;
	// li r10,23
	ctx.r10.s64 = 23;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,68(r8)
	PPC_STORE_U32(ctx.r8.u32 + 68, ctx.r9.u32);
	// bl 0x88096b40
	ctx.lr = 0x880A917C;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880a9188
	goto loc_880A9188;
loc_880A9184:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880A9188:
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

__attribute__((alias("__imp__sub_880A91A0"))) PPC_WEAK_FUNC(sub_880A91A0);
PPC_FUNC_IMPL(__imp__sub_880A91A0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880A91A8;
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
	ctx.lr = 0x880A91C8;
	sub_88096BC8(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// beq cr6,0x880a91f0
	if (ctx.cr6.eq) goto loc_880A91F0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880A91E4;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_880A91F0:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// bgt 0x880a9258
	if (ctx.cr0.gt) goto loc_880A9258;
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
	// blt cr6,0x880a9258
	if (ctx.cr6.lt) goto loc_880A9258;
	// li r10,11
	ctx.r10.s64 = 11;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r7,4(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r9,68(r7)
	PPC_STORE_U32(ctx.r7.u32 + 68, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r8,7108(r29)
	PPC_STORE_U32(ctx.r29.u32 + 7108, ctx.r8.u32);
	// bl 0x88096b40
	ctx.lr = 0x880A924C;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_880A9258:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A9264"))) PPC_WEAK_FUNC(sub_880A9264);
PPC_FUNC_IMPL(__imp__sub_880A9264) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A9268"))) PPC_WEAK_FUNC(sub_880A9268);
PPC_FUNC_IMPL(__imp__sub_880A9268) {
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
	ctx.lr = 0x880A9294;
	sub_88096BC8(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// beq cr6,0x880a92b8
	if (ctx.cr6.eq) goto loc_880A92B8;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880A92B0;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880a9318
	goto loc_880A9318;
loc_880A92B8:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// bgt 0x880a9314
	if (ctx.cr0.gt) goto loc_880A9314;
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
	// cmpwi cr6,r8,15
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 15, ctx.xer);
	// blt cr6,0x880a9314
	if (ctx.cr6.lt) goto loc_880A9314;
	// li r10,15
	ctx.r10.s64 = 15;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,68(r8)
	PPC_STORE_U32(ctx.r8.u32 + 68, ctx.r9.u32);
	// bl 0x88096b40
	ctx.lr = 0x880A930C;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880a9318
	goto loc_880A9318;
loc_880A9314:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880A9318:
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

__attribute__((alias("__imp__sub_880A9330"))) PPC_WEAK_FUNC(sub_880A9330);
PPC_FUNC_IMPL(__imp__sub_880A9330) {
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
	ctx.lr = 0x880A935C;
	sub_88096BC8(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// cmpwi cr6,r10,5
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 5, ctx.xer);
	// beq cr6,0x880a9380
	if (ctx.cr6.eq) goto loc_880A9380;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880A9378;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880a93e0
	goto loc_880A93E0;
loc_880A9380:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// bgt 0x880a93dc
	if (ctx.cr0.gt) goto loc_880A93DC;
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
	// bgt cr6,0x880a93dc
	if (ctx.cr6.gt) goto loc_880A93DC;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,68(r8)
	PPC_STORE_U32(ctx.r8.u32 + 68, ctx.r9.u32);
	// bl 0x88096b40
	ctx.lr = 0x880A93D4;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880a93e0
	goto loc_880A93E0;
loc_880A93DC:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880A93E0:
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

__attribute__((alias("__imp__sub_880A93F8"))) PPC_WEAK_FUNC(sub_880A93F8);
PPC_FUNC_IMPL(__imp__sub_880A93F8) {
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
	ctx.lr = 0x880A9424;
	sub_88096BC8(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// beq cr6,0x880a9448
	if (ctx.cr6.eq) goto loc_880A9448;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880A9440;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880a94a8
	goto loc_880A94A8;
loc_880A9448:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// bgt 0x880a94a4
	if (ctx.cr0.gt) goto loc_880A94A4;
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
	// blt cr6,0x880a94a4
	if (ctx.cr6.lt) goto loc_880A94A4;
	// li r10,11
	ctx.r10.s64 = 11;
	// li r9,4
	ctx.r9.s64 = 4;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,68(r8)
	PPC_STORE_U32(ctx.r8.u32 + 68, ctx.r9.u32);
	// bl 0x88096b40
	ctx.lr = 0x880A949C;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880a94a8
	goto loc_880A94A8;
loc_880A94A4:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880A94A8:
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

__attribute__((alias("__imp__sub_880A94C0"))) PPC_WEAK_FUNC(sub_880A94C0);
PPC_FUNC_IMPL(__imp__sub_880A94C0) {
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
	ctx.lr = 0x880A94EC;
	sub_88096BC8(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// beq cr6,0x880a9510
	if (ctx.cr6.eq) goto loc_880A9510;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880A9508;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880a956c
	goto loc_880A956C;
loc_880A9510:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// bgt 0x880a9568
	if (ctx.cr0.gt) goto loc_880A9568;
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
	// bgt cr6,0x880a9568
	if (ctx.cr6.gt) goto loc_880A9568;
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
	// stw r10,68(r11)
	PPC_STORE_U32(ctx.r11.u32 + 68, ctx.r10.u32);
	// bl 0x88096b40
	ctx.lr = 0x880A9560;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880a956c
	goto loc_880A956C;
loc_880A9568:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880A956C:
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

__attribute__((alias("__imp__sub_880A9584"))) PPC_WEAK_FUNC(sub_880A9584);
PPC_FUNC_IMPL(__imp__sub_880A9584) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A9588"))) PPC_WEAK_FUNC(sub_880A9588);
PPC_FUNC_IMPL(__imp__sub_880A9588) {
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
	ctx.lr = 0x880A95B4;
	sub_88096BC8(ctx, base);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// beq cr6,0x880a95dc
	if (ctx.cr6.eq) goto loc_880A95DC;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880A95D4;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880a9668
	goto loc_880A9668;
loc_880A95DC:
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// bgt 0x880a9664
	if (ctx.cr0.gt) goto loc_880A9664;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r8,9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 9, ctx.xer);
	// blt cr6,0x880a9608
	if (ctx.cr6.lt) goto loc_880A9608;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
loc_880A9608:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,12
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 12, ctx.xer);
	// blt cr6,0x880a9620
	if (ctx.cr6.lt) goto loc_880A9620;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
loc_880A9620:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r8,15
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 15, ctx.xer);
	// blt cr6,0x880a9664
	if (ctx.cr6.lt) goto loc_880A9664;
	// li r9,15
	ctx.r9.s64 = 15;
	// li r8,2
	ctx.r8.s64 = 2;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r8,68(r7)
	PPC_STORE_U32(ctx.r7.u32 + 68, ctx.r8.u32);
	// bl 0x88096b40
	ctx.lr = 0x880A965C;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880a9668
	goto loc_880A9668;
loc_880A9664:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880A9668:
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

__attribute__((alias("__imp__sub_880A9680"))) PPC_WEAK_FUNC(sub_880A9680);
PPC_FUNC_IMPL(__imp__sub_880A9680) {
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
	ctx.lr = 0x880A96AC;
	sub_88096BC8(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// beq cr6,0x880a96d0
	if (ctx.cr6.eq) goto loc_880A96D0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880A96C8;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880a972c
	goto loc_880A972C;
loc_880A96D0:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// bgt 0x880a9728
	if (ctx.cr0.gt) goto loc_880A9728;
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
	// bgt cr6,0x880a9728
	if (ctx.cr6.gt) goto loc_880A9728;
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
	// stw r10,68(r11)
	PPC_STORE_U32(ctx.r11.u32 + 68, ctx.r10.u32);
	// bl 0x88096b40
	ctx.lr = 0x880A9720;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880a972c
	goto loc_880A972C;
loc_880A9728:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880A972C:
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

__attribute__((alias("__imp__sub_880A9744"))) PPC_WEAK_FUNC(sub_880A9744);
PPC_FUNC_IMPL(__imp__sub_880A9744) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A9748"))) PPC_WEAK_FUNC(sub_880A9748);
PPC_FUNC_IMPL(__imp__sub_880A9748) {
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
	ctx.lr = 0x880A9774;
	sub_88096BC8(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// beq cr6,0x880a9798
	if (ctx.cr6.eq) goto loc_880A9798;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880A9790;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880a97f8
	goto loc_880A97F8;
loc_880A9798:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// bgt 0x880a97f4
	if (ctx.cr0.gt) goto loc_880A97F4;
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
	// cmpwi cr6,r8,15
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 15, ctx.xer);
	// blt cr6,0x880a97f4
	if (ctx.cr6.lt) goto loc_880A97F4;
	// li r10,15
	ctx.r10.s64 = 15;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,68(r8)
	PPC_STORE_U32(ctx.r8.u32 + 68, ctx.r9.u32);
	// bl 0x88096b40
	ctx.lr = 0x880A97EC;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880a97f8
	goto loc_880A97F8;
loc_880A97F4:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880A97F8:
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

__attribute__((alias("__imp__sub_880A9810"))) PPC_WEAK_FUNC(sub_880A9810);
PPC_FUNC_IMPL(__imp__sub_880A9810) {
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
	// lwz r10,9880(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 9880);
	// addic. r10,r10,-8
	ctx.xer.ca = ctx.r10.u32 > 7;
	ctx.r10.s64 = ctx.r10.s64 + -8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,9880(r11)
	PPC_STORE_U32(ctx.r11.u32 + 9880, ctx.r10.u32);
	// bgt 0x880a9860
	if (ctx.cr0.gt) goto loc_880A9860;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// stw r10,9880(r11)
	PPC_STORE_U32(ctx.r11.u32 + 9880, ctx.r10.u32);
	// bl 0x880a4dd0
	ctx.lr = 0x880A9844;
	sub_880A4DD0(ctx, base);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// bl 0x88096b40
	ctx.lr = 0x880A984C;
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
loc_880A9860:
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

__attribute__((alias("__imp__sub_880A9874"))) PPC_WEAK_FUNC(sub_880A9874);
PPC_FUNC_IMPL(__imp__sub_880A9874) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A9878"))) PPC_WEAK_FUNC(sub_880A9878);
PPC_FUNC_IMPL(__imp__sub_880A9878) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880A9880;
	__savegprlr_29(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r9,184(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lwz r10,168(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// li r7,2
	ctx.r7.s64 = 2;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r6,r31,7580
	ctx.r6.s64 = ctx.r31.s64 + 7580;
	// std r11,0(r8)
	PPC_STORE_U64(ctx.r8.u32 + 0, ctx.r11.u64);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// std r11,8(r8)
	PPC_STORE_U64(ctx.r8.u32 + 8, ctx.r11.u64);
	// addi r5,r31,7616
	ctx.r5.s64 = ctx.r31.s64 + 7616;
	// std r11,16(r8)
	PPC_STORE_U64(ctx.r8.u32 + 16, ctx.r11.u64);
	// lis r4,16
	ctx.r4.s64 = 1048576;
	// std r11,24(r8)
	PPC_STORE_U64(ctx.r8.u32 + 24, ctx.r11.u64);
	// li r9,256
	ctx.r9.s64 = 256;
	// lwz r30,296(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 296);
	// addi r29,r10,4
	ctx.r29.s64 = ctx.r10.s64 + 4;
	// stw r11,32(r8)
	PPC_STORE_U32(ctx.r8.u32 + 32, ctx.r11.u32);
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// stw r5,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r5.u32);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// stw r4,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r4.u32);
	// stw r9,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r9.u32);
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r29.u32);
	// bne cr6,0x880a9904
	if (!ctx.cr6.eq) goto loc_880A9904;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x88093be8
	ctx.lr = 0x880A9900;
	sub_88093BE8(ctx, base);
	// stw r3,296(r31)
	PPC_STORE_U32(ctx.r31.u32 + 296, ctx.r3.u32);
loc_880A9904:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A990C"))) PPC_WEAK_FUNC(sub_880A990C);
PPC_FUNC_IMPL(__imp__sub_880A990C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A9910"))) PPC_WEAK_FUNC(sub_880A9910);
PPC_FUNC_IMPL(__imp__sub_880A9910) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x880A9918;
	__savegprlr_25(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r10,184(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// lwz r11,168(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// li r31,0
	ctx.r31.s64 = 0;
	// lwz r30,2304(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// li r25,2
	ctx.r25.s64 = 2;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lis r26,32
	ctx.r26.s64 = 2097152;
	// std r31,0(r9)
	PPC_STORE_U64(ctx.r9.u32 + 0, ctx.r31.u64);
	// addi r28,r11,2
	ctx.r28.s64 = ctx.r11.s64 + 2;
	// std r31,8(r9)
	PPC_STORE_U64(ctx.r9.u32 + 8, ctx.r31.u64);
	// addi r8,r30,8284
	ctx.r8.s64 = ctx.r30.s64 + 8284;
	// std r31,16(r9)
	PPC_STORE_U64(ctx.r9.u32 + 16, ctx.r31.u64);
	// addi r27,r28,2
	ctx.r27.s64 = ctx.r28.s64 + 2;
	// std r31,24(r9)
	PPC_STORE_U64(ctx.r9.u32 + 24, ctx.r31.u64);
	// lis r7,-24
	ctx.r7.s64 = -1572864;
	// lwz r6,280(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 280);
	// li r5,320
	ctx.r5.s64 = 320;
	// stw r31,32(r9)
	PPC_STORE_U32(ctx.r9.u32 + 32, ctx.r31.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// stw r28,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r28.u32);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// stw r25,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r25.u32);
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// stw r31,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r31.u32);
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// stw r26,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r26.u32);
	// stw r5,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r5.u32);
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r27.u32);
	// bne cr6,0x880a99a0
	if (!ctx.cr6.eq) goto loc_880A99A0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x88093be8
	ctx.lr = 0x880A999C;
	sub_88093BE8(ctx, base);
	// stw r3,280(r30)
	PPC_STORE_U32(ctx.r30.u32 + 280, ctx.r3.u32);
loc_880A99A0:
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lwz r10,284(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 284);
	// addi r9,r30,8372
	ctx.r9.s64 = ctx.r30.s64 + 8372;
	// lis r8,24
	ctx.r8.s64 = 1572864;
	// li r7,192
	ctx.r7.s64 = 192;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// std r31,0(r11)
	PPC_STORE_U64(ctx.r11.u32 + 0, ctx.r31.u64);
	// std r31,8(r11)
	PPC_STORE_U64(ctx.r11.u32 + 8, ctx.r31.u64);
	// std r31,16(r11)
	PPC_STORE_U64(ctx.r11.u32 + 16, ctx.r31.u64);
	// std r31,24(r11)
	PPC_STORE_U64(ctx.r11.u32 + 24, ctx.r31.u64);
	// stw r31,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r31.u32);
	// stw r25,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r25.u32);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// stw r31,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r31.u32);
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// stw r26,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r26.u32);
	// stw r7,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r7.u32);
	// stw r28,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r28.u32);
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r27.u32);
	// bne cr6,0x880a9a00
	if (!ctx.cr6.eq) goto loc_880A9A00;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88093be8
	ctx.lr = 0x880A99FC;
	sub_88093BE8(ctx, base);
	// stw r3,284(r30)
	PPC_STORE_U32(ctx.r30.u32 + 284, ctx.r3.u32);
loc_880A9A00:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A9A08"))) PPC_WEAK_FUNC(sub_880A9A08);
PPC_FUNC_IMPL(__imp__sub_880A9A08) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x880A9A10;
	__savegprlr_25(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r10,184(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// lwz r11,168(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// li r31,0
	ctx.r31.s64 = 0;
	// lwz r30,2304(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// li r25,2
	ctx.r25.s64 = 2;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lis r26,8
	ctx.r26.s64 = 524288;
	// std r31,0(r9)
	PPC_STORE_U64(ctx.r9.u32 + 0, ctx.r31.u64);
	// addi r28,r11,3
	ctx.r28.s64 = ctx.r11.s64 + 3;
	// std r31,8(r9)
	PPC_STORE_U64(ctx.r9.u32 + 8, ctx.r31.u64);
	// addi r8,r30,8108
	ctx.r8.s64 = ctx.r30.s64 + 8108;
	// std r31,16(r9)
	PPC_STORE_U64(ctx.r9.u32 + 16, ctx.r31.u64);
	// addi r27,r28,2
	ctx.r27.s64 = ctx.r28.s64 + 2;
	// std r31,24(r9)
	PPC_STORE_U64(ctx.r9.u32 + 24, ctx.r31.u64);
	// lis r7,-16
	ctx.r7.s64 = -1048576;
	// lwz r6,264(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 264);
	// li r5,416
	ctx.r5.s64 = 416;
	// stw r31,32(r9)
	PPC_STORE_U32(ctx.r9.u32 + 32, ctx.r31.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// stw r28,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r28.u32);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// stw r25,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r25.u32);
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// stw r31,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r31.u32);
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// stw r26,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r26.u32);
	// stw r5,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r5.u32);
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r27.u32);
	// bne cr6,0x880a9a98
	if (!ctx.cr6.eq) goto loc_880A9A98;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x88093be8
	ctx.lr = 0x880A9A94;
	sub_88093BE8(ctx, base);
	// stw r3,264(r30)
	PPC_STORE_U32(ctx.r30.u32 + 264, ctx.r3.u32);
loc_880A9A98:
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lwz r10,268(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 268);
	// addi r9,r30,8196
	ctx.r9.s64 = ctx.r30.s64 + 8196;
	// lis r8,16
	ctx.r8.s64 = 1048576;
	// li r7,96
	ctx.r7.s64 = 96;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// std r31,0(r11)
	PPC_STORE_U64(ctx.r11.u32 + 0, ctx.r31.u64);
	// std r31,8(r11)
	PPC_STORE_U64(ctx.r11.u32 + 8, ctx.r31.u64);
	// std r31,16(r11)
	PPC_STORE_U64(ctx.r11.u32 + 16, ctx.r31.u64);
	// std r31,24(r11)
	PPC_STORE_U64(ctx.r11.u32 + 24, ctx.r31.u64);
	// stw r31,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r31.u32);
	// stw r25,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r25.u32);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// stw r31,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r31.u32);
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// stw r26,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r26.u32);
	// stw r7,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r7.u32);
	// stw r28,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r28.u32);
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r27.u32);
	// bne cr6,0x880a9af8
	if (!ctx.cr6.eq) goto loc_880A9AF8;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88093be8
	ctx.lr = 0x880A9AF4;
	sub_88093BE8(ctx, base);
	// stw r3,268(r30)
	PPC_STORE_U32(ctx.r30.u32 + 268, ctx.r3.u32);
loc_880A9AF8:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A9B00"))) PPC_WEAK_FUNC(sub_880A9B00);
PPC_FUNC_IMPL(__imp__sub_880A9B00) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071130
	ctx.lr = 0x880A9B08;
	__savegprlr_18(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r19,r4
	ctx.r19.u64 = ctx.r4.u64;
	// mr r18,r5
	ctx.r18.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880A9B24;
	sub_88096BC8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r23,8(r3)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r20,0
	ctx.r20.s64 = 0;
	// li r21,2
	ctx.r21.s64 = 2;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x880a9b50
	if (ctx.cr6.lt) goto loc_880A9B50;
	// beq cr6,0x880a9b88
	if (ctx.cr6.eq) goto loc_880A9B88;
loc_880A9B44:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x88071180
	__restgprlr_18(ctx, base);
	return;
loc_880A9B50:
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r9,6
	ctx.r9.s64 = 6;
	// stw r11,64(r10)
	PPC_STORE_U32(ctx.r10.u32 + 64, ctx.r11.u32);
	// lwz r8,4(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// stw r11,72(r8)
	PPC_STORE_U32(ctx.r8.u32 + 72, ctx.r11.u32);
	// lwz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// stw r9,68(r7)
	PPC_STORE_U32(ctx.r7.u32 + 68, ctx.r9.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// addi r6,r11,1
	ctx.r6.s64 = ctx.r11.s64 + 1;
	// stw r20,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r20.u32);
	// stw r21,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r21.u32);
	// stw r20,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r20.u32);
	// stw r6,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r6.u32);
loc_880A9B88:
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r11.u32);
	// bge 0x880a9b44
	if (!ctx.cr0.lt) goto loc_880A9B44;
	// lwz r11,24(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// lis r9,-30682
	ctx.r9.s64 = -2010775552;
	// lwz r8,20(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// lis r26,-30667
	ctx.r26.s64 = -2009792512;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// addi r9,r9,-15176
	ctx.r9.s64 = ctx.r9.s64 + -15176;
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lis r25,-30667
	ctx.r25.s64 = -2009792512;
	// rlwinm r11,r6,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r8.u32);
	// lwz r8,12(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// add r31,r11,r9
	ctx.r31.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lis r22,-30667
	ctx.r22.s64 = -2009792512;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// add r28,r8,r11
	ctx.r28.u64 = ctx.r8.u64 + ctx.r11.u64;
	// lwz r11,16(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// add r27,r11,r10
	ctx.r27.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r28,12364(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12364, ctx.r28.u32);
	// stw r27,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r27.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x880f52c8
	ctx.lr = 0x880A9BF8;
	sub_880F52C8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x881534c8
	ctx.lr = 0x880A9C04;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,16
	ctx.r3.s64 = 16;
	// addi r24,r11,240
	ctx.r24.s64 = ctx.r11.s64 + 240;
	// bl 0x881534c8
	ctx.lr = 0x880A9C14;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r4,r11,72
	ctx.r4.s64 = ctx.r11.s64 + 72;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// bl 0x880f5570
	ctx.lr = 0x880A9C28;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x880a9c3c
	if (ctx.cr6.eq) goto loc_880A9C3C;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// clrlwi r10,r11,16
	ctx.r10.u64 = ctx.r11.u32 & 0xFFFF;
	// stw r10,100(r29)
	PPC_STORE_U32(ctx.r29.u32 + 100, ctx.r10.u32);
loc_880A9C3C:
	// stw r28,12364(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12364, ctx.r28.u32);
	// addi r29,r23,1
	ctx.r29.s64 = ctx.r23.s64 + 1;
	// stw r27,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r27.u32);
	// lis r23,-30667
	ctx.r23.s64 = -2009792512;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// bl 0x880f52c8
	ctx.lr = 0x880A9C5C;
	sub_880F52C8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880a9c6c
	if (ctx.cr6.eq) goto loc_880A9C6C;
	// stw r21,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r21.u32);
loc_880A9C6C:
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x881534c8
	ctx.lr = 0x880A9C74;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,32
	ctx.r3.s64 = 32;
	// addi r11,r11,72
	ctx.r11.s64 = ctx.r11.s64 + 72;
	// rlwinm r21,r11,1,0,30
	ctx.r21.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// bl 0x881534c8
	ctx.lr = 0x880A9C88;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
	// add r11,r11,r24
	ctx.r11.u64 = ctx.r11.u64 + ctx.r24.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r5,r11,-16
	ctx.r5.s64 = ctx.r11.s64 + -16;
	// bl 0x880f5570
	ctx.lr = 0x880A9CA0;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x880a9cb8
	if (ctx.cr6.eq) goto loc_880A9CB8;
	// li r11,112
	ctx.r11.s64 = 112;
	// li r10,10
	ctx.r10.s64 = 10;
	// stw r11,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r11.u32);
	// stw r10,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r10.u32);
loc_880A9CB8:
	// stw r28,12364(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12364, ctx.r28.u32);
	// li r11,24
	ctx.r11.s64 = 24;
	// stw r27,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r27.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,12380(r22)
	PPC_STORE_U32(ctx.r22.u32 + 12380, ctx.r11.u32);
	// bl 0x880f34b0
	ctx.lr = 0x880A9CD4;
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
	// beq cr6,0x880a9d28
	if (ctx.cr6.eq) goto loc_880A9D28;
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
	// add r11,r11,r24
	ctx.r11.u64 = ctx.r11.u64 + ctx.r24.u64;
	// addi r4,r11,-32
	ctx.r4.s64 = ctx.r11.s64 + -32;
	// sth r4,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, ctx.r4.u16);
loc_880A9D28:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x880f34b0
	ctx.lr = 0x880A9D34;
	sub_880F34B0(ctx, base);
	// mullw r11,r26,r28
	ctx.r11.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r28.s32);
	// addi r26,r11,12345
	ctx.r26.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r26,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r26.u32);
	// beq cr6,0x880a9d70
	if (ctx.cr6.eq) goto loc_880A9D70;
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
	// add r11,r11,r24
	ctx.r11.u64 = ctx.r11.u64 + ctx.r24.u64;
	// addi r4,r11,-32
	ctx.r4.s64 = ctx.r11.s64 + -32;
	// sth r4,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, ctx.r4.u16);
loc_880A9D70:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r29,12376(r23)
	PPC_STORE_U32(ctx.r23.u32 + 12376, ctx.r29.u32);
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x880f34b0
	ctx.lr = 0x880A9D80;
	sub_880F34B0(ctx, base);
	// mullw r11,r26,r28
	ctx.r11.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r28.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r11,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r11.u32);
	// beq cr6,0x880a9dbc
	if (ctx.cr6.eq) goto loc_880A9DBC;
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
	// add r11,r11,r24
	ctx.r11.u64 = ctx.r11.u64 + ctx.r24.u64;
	// addi r4,r11,-32
	ctx.r4.s64 = ctx.r11.s64 + -32;
	// sth r4,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, ctx.r4.u16);
loc_880A9DBC:
	// lwz r11,24(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r11.u32);
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// blt cr6,0x880a9b44
	if (ctx.cr6.lt) goto loc_880A9B44;
	// stw r20,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r20.u32);
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// bl 0x88096b40
	ctx.lr = 0x880A9DE0;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x88071180
	__restgprlr_18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880A9DEC"))) PPC_WEAK_FUNC(sub_880A9DEC);
PPC_FUNC_IMPL(__imp__sub_880A9DEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880A9DF0"))) PPC_WEAK_FUNC(sub_880A9DF0);
PPC_FUNC_IMPL(__imp__sub_880A9DF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807112c
	ctx.lr = 0x880A9DF8;
	__savegprlr_17(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r18,r4
	ctx.r18.u64 = ctx.r4.u64;
	// lwz r22,2304(r3)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r17,r5
	ctx.r17.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880A9E18;
	sub_88096BC8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r23,8(r3)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r19,0
	ctx.r19.s64 = 0;
	// li r20,2
	ctx.r20.s64 = 2;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x880a9e44
	if (ctx.cr6.lt) goto loc_880A9E44;
	// beq cr6,0x880a9e84
	if (ctx.cr6.eq) goto loc_880A9E84;
loc_880A9E38:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8807117c
	__restgprlr_17(ctx, base);
	return;
loc_880A9E44:
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,64(r10)
	PPC_STORE_U32(ctx.r10.u32 + 64, ctx.r11.u32);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,72(r9)
	PPC_STORE_U32(ctx.r9.u32 + 72, ctx.r11.u32);
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,68(r8)
	PPC_STORE_U32(ctx.r8.u32 + 68, ctx.r11.u32);
	// stw r11,8872(r22)
	PPC_STORE_U32(ctx.r22.u32 + 8872, ctx.r11.u32);
	// stw r11,8960(r22)
	PPC_STORE_U32(ctx.r22.u32 + 8960, ctx.r11.u32);
	// stw r11,7816(r22)
	PPC_STORE_U32(ctx.r22.u32 + 7816, ctx.r11.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r19,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r19.u32);
	// stw r20,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r20.u32);
	// stw r19,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r19.u32);
	// stw r7,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
loc_880A9E84:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// bge 0x880a9e38
	if (!ctx.cr0.lt) goto loc_880A9E38;
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lis r9,-30682
	ctx.r9.s64 = -2010775552;
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lis r26,-30667
	ctx.r26.s64 = -2009792512;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r9,r9,-15608
	ctx.r9.s64 = ctx.r9.s64 + -15608;
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lis r25,-30667
	ctx.r25.s64 = -2009792512;
	// rlwinm r11,r6,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r8.u32);
	// lwz r8,12(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// add r30,r11,r9
	ctx.r30.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r7,16(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// lis r21,-30667
	ctx.r21.s64 = -2009792512;
	// lwz r5,12(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// srawi r10,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 2;
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r11.s64 = temp.s64;
	// srawi r9,r5,2
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r5.s32 >> 2;
	// add r28,r11,r8
	ctx.r28.u64 = ctx.r11.u64 + ctx.r8.u64;
	// addze r11,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r11.s64 = temp.s64;
	// stw r28,12364(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12364, ctx.r28.u32);
	// add r8,r11,r7
	ctx.r8.u64 = ctx.r11.u64 + ctx.r7.u64;
	// addis r27,r8,64
	ctx.r27.s64 = ctx.r8.s64 + 4194304;
	// stw r27,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r27.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880A9F08;
	sub_880F52C8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x881534c8
	ctx.lr = 0x880A9F14;
	sub_881534C8(ctx, base);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// extsh r7,r3
	ctx.r7.s64 = ctx.r3.s16;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// li r3,16
	ctx.r3.s64 = 16;
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r5,r6,5,0,26
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFFE0;
	// subf r11,r5,r7
	ctx.r11.s64 = ctx.r7.s64 - ctx.r5.s64;
	// addi r24,r11,248
	ctx.r24.s64 = ctx.r11.s64 + 248;
	// bl 0x881534c8
	ctx.lr = 0x880A9F38;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r4,r11,72
	ctx.r4.s64 = ctx.r11.s64 + 72;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// bl 0x880f5570
	ctx.lr = 0x880A9F4C;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x880a9f60
	if (ctx.cr6.eq) goto loc_880A9F60;
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// clrlwi r10,r11,16
	ctx.r10.u64 = ctx.r11.u32 & 0xFFFF;
	// stw r10,100(r29)
	PPC_STORE_U32(ctx.r29.u32 + 100, ctx.r10.u32);
loc_880A9F60:
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r22
	ctx.r11.u64 = ctx.r11.u64 + ctx.r22.u64;
	// lwz r9,9988(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 9988);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x880a9fb0
	if (!ctx.cr6.eq) goto loc_880A9FB0;
	// addi r10,r10,500
	ctx.r10.s64 = ctx.r10.s64 + 500;
	// lwz r8,10004(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 10004);
	// lwz r6,9996(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 9996);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r5,9992(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 9992);
	// lwz r7,0(r22)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// add r11,r10,r9
	ctx.r11.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r4,12(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lwzx r7,r10,r22
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r22.u32);
	// bl 0x880f5438
	ctx.lr = 0x880A9FB0;
	sub_880F5438(ctx, base);
loc_880A9FB0:
	// stw r28,12364(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12364, ctx.r28.u32);
	// addi r29,r23,1
	ctx.r29.s64 = ctx.r23.s64 + 1;
	// stw r27,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r27.u32);
	// lis r23,-30667
	ctx.r23.s64 = -2009792512;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// bl 0x880f52c8
	ctx.lr = 0x880A9FD0;
	sub_880F52C8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880a9fe0
	if (ctx.cr6.eq) goto loc_880A9FE0;
	// stw r20,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r20.u32);
loc_880A9FE0:
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x881534c8
	ctx.lr = 0x880A9FE8;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,32
	ctx.r3.s64 = 32;
	// addi r11,r11,72
	ctx.r11.s64 = ctx.r11.s64 + 72;
	// rlwinm r22,r11,1,0,30
	ctx.r22.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// bl 0x881534c8
	ctx.lr = 0x880A9FFC;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// add r11,r11,r24
	ctx.r11.u64 = ctx.r11.u64 + ctx.r24.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r5,r11,-16
	ctx.r5.s64 = ctx.r11.s64 + -16;
	// bl 0x880f5570
	ctx.lr = 0x880AA014;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x880aa02c
	if (ctx.cr6.eq) goto loc_880AA02C;
	// li r11,112
	ctx.r11.s64 = 112;
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r11,140(r30)
	PPC_STORE_U32(ctx.r30.u32 + 140, ctx.r11.u32);
	// stw r10,100(r30)
	PPC_STORE_U32(ctx.r30.u32 + 100, ctx.r10.u32);
loc_880AA02C:
	// stw r28,12364(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12364, ctx.r28.u32);
	// li r11,24
	ctx.r11.s64 = 24;
	// stw r27,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r27.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,12380(r21)
	PPC_STORE_U32(ctx.r21.u32 + 12380, ctx.r11.u32);
	// bl 0x880f34b0
	ctx.lr = 0x880AA048;
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
	// beq cr6,0x880aa09c
	if (ctx.cr6.eq) goto loc_880AA09C;
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
	// add r11,r11,r24
	ctx.r11.u64 = ctx.r11.u64 + ctx.r24.u64;
	// addi r4,r11,-32
	ctx.r4.s64 = ctx.r11.s64 + -32;
	// sth r4,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, ctx.r4.u16);
loc_880AA09C:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x880f34b0
	ctx.lr = 0x880AA0A8;
	sub_880F34B0(ctx, base);
	// mullw r11,r26,r28
	ctx.r11.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r28.s32);
	// addi r26,r11,12345
	ctx.r26.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r26,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r26.u32);
	// beq cr6,0x880aa0e4
	if (ctx.cr6.eq) goto loc_880AA0E4;
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
	// add r11,r11,r24
	ctx.r11.u64 = ctx.r11.u64 + ctx.r24.u64;
	// addi r4,r11,-32
	ctx.r4.s64 = ctx.r11.s64 + -32;
	// sth r4,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, ctx.r4.u16);
loc_880AA0E4:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r29,12376(r23)
	PPC_STORE_U32(ctx.r23.u32 + 12376, ctx.r29.u32);
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x880f34b0
	ctx.lr = 0x880AA0F4;
	sub_880F34B0(ctx, base);
	// mullw r11,r26,r28
	ctx.r11.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r28.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r11,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r11.u32);
	// beq cr6,0x880aa130
	if (ctx.cr6.eq) goto loc_880AA130;
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
	// add r11,r11,r24
	ctx.r11.u64 = ctx.r11.u64 + ctx.r24.u64;
	// addi r4,r11,-32
	ctx.r4.s64 = ctx.r11.s64 + -32;
	// sth r4,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, ctx.r4.u16);
loc_880AA130:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// cmplwi cr6,r11,12
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 12, ctx.xer);
	// blt cr6,0x880a9e38
	if (ctx.cr6.lt) goto loc_880A9E38;
	// stw r19,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r19.u32);
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// bl 0x88096b40
	ctx.lr = 0x880AA154;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8807117c
	__restgprlr_17(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880AA160"))) PPC_WEAK_FUNC(sub_880AA160);
PPC_FUNC_IMPL(__imp__sub_880AA160) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807112c
	ctx.lr = 0x880AA168;
	__savegprlr_17(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r18,r4
	ctx.r18.u64 = ctx.r4.u64;
	// lwz r21,2304(r3)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r17,r5
	ctx.r17.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880AA188;
	sub_88096BC8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r30,8(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r19,0
	ctx.r19.s64 = 0;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x880aa1b0
	if (ctx.cr6.lt) goto loc_880AA1B0;
	// beq cr6,0x880aa208
	if (ctx.cr6.eq) goto loc_880AA208;
loc_880AA1A4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8807117c
	__restgprlr_17(ctx, base);
	return;
loc_880AA1B0:
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,48
	ctx.r8.s64 = 48;
	// li r3,16
	ctx.r3.s64 = 16;
	// stw r11,64(r10)
	PPC_STORE_U32(ctx.r10.u32 + 64, ctx.r11.u32);
	// lwz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,72(r7)
	PPC_STORE_U32(ctx.r7.u32 + 72, ctx.r11.u32);
	// stw r9,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
	// stw r19,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r19.u32);
	// stw r19,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r19.u32);
	// stw r8,36(r21)
	PPC_STORE_U32(ctx.r21.u32 + 36, ctx.r8.u32);
	// bl 0x881534c8
	ctx.lr = 0x880AA1E4;
	sub_881534C8(ctx, base);
	// lwz r6,28(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// extsh r10,r3
	ctx.r10.s64 = ctx.r3.s16;
	// mulli r11,r6,208
	ctx.r11.s64 = ctx.r6.s64 * 208;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r5,r11,251
	ctx.r5.s64 = ctx.r11.s64 + 251;
	// stw r5,40(r21)
	PPC_STORE_U32(ctx.r21.u32 + 40, ctx.r5.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// stw r4,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r4.u32);
loc_880AA208:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// bge 0x880aa1a4
	if (!ctx.cr0.lt) goto loc_880AA1A4;
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
	// addi r9,r9,-16456
	ctx.r9.s64 = ctx.r9.s64 + -16456;
	// lwz r6,28(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r8.u32);
	// lwz r8,12(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lis r25,-30667
	ctx.r25.s64 = -2009792512;
	// add r30,r10,r9
	ctx.r30.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r7,16(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// lis r24,-30667
	ctx.r24.s64 = -2009792512;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwzx r3,r10,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// lis r20,-30667
	ctx.r20.s64 = -2009792512;
	// lis r22,-30667
	ctx.r22.s64 = -2009792512;
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// srawi r9,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 1;
	// addze r5,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r5.s64 = temp.s64;
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// addis r9,r5,24
	ctx.r9.s64 = ctx.r5.s64 + 1572864;
	// addze r10,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r10.s64 = temp.s64;
	// mullw r11,r9,r6
	ctx.r11.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r6.s32);
	// add r27,r11,r8
	ctx.r27.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r26,r10,r7
	ctx.r26.u64 = ctx.r10.u64 + ctx.r7.u64;
	// stw r27,12364(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12364, ctx.r27.u32);
	// stw r26,12372(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12372, ctx.r26.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880AA2A0;
	sub_880F52C8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x881534c8
	ctx.lr = 0x880AA2AC;
	sub_881534C8(ctx, base);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// extsh r8,r3
	ctx.r8.s64 = ctx.r3.s16;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r3,16
	ctx.r3.s64 = 16;
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r6,r7,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r11,r6,r8
	ctx.r11.s64 = ctx.r8.s64 - ctx.r6.s64;
	// addi r23,r11,248
	ctx.r23.s64 = ctx.r11.s64 + 248;
	// bl 0x881534c8
	ctx.lr = 0x880AA2D0;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r4,r11,72
	ctx.r4.s64 = ctx.r11.s64 + 72;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// bl 0x880f5570
	ctx.lr = 0x880AA2E4;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x880aa300
	if (ctx.cr6.eq) goto loc_880AA300;
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// clrlwi r10,r11,16
	ctx.r10.u64 = ctx.r11.u32 & 0xFFFF;
	// stw r10,100(r28)
	PPC_STORE_U32(ctx.r28.u32 + 100, ctx.r10.u32);
	// lwz r9,32(r21)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r21.u32 + 32);
	// stw r9,144(r28)
	PPC_STORE_U32(ctx.r28.u32 + 144, ctx.r9.u32);
loc_880AA300:
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
	ctx.lr = 0x880AA31C;
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
	// beq cr6,0x880aa370
	if (ctx.cr6.eq) goto loc_880AA370;
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
loc_880AA370:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x880f34b0
	ctx.lr = 0x880AA37C;
	sub_880F34B0(ctx, base);
	// mullw r11,r26,r28
	ctx.r11.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r28.s32);
	// addi r26,r11,12345
	ctx.r26.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r26,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r26.u32);
	// beq cr6,0x880aa3b8
	if (ctx.cr6.eq) goto loc_880AA3B8;
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
loc_880AA3B8:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r29,12376(r20)
	PPC_STORE_U32(ctx.r20.u32 + 12376, ctx.r29.u32);
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x880f34b0
	ctx.lr = 0x880AA3C8;
	sub_880F34B0(ctx, base);
	// mullw r11,r26,r28
	ctx.r11.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r28.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r11,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r11.u32);
	// beq cr6,0x880aa404
	if (ctx.cr6.eq) goto loc_880AA404;
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
loc_880AA404:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// cmplwi cr6,r11,23
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 23, ctx.xer);
	// blt cr6,0x880aa1a4
	if (ctx.cr6.lt) goto loc_880AA1A4;
	// stw r19,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r19.u32);
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// bl 0x88096b40
	ctx.lr = 0x880AA428;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8807117c
	__restgprlr_17(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880AA434"))) PPC_WEAK_FUNC(sub_880AA434);
PPC_FUNC_IMPL(__imp__sub_880AA434) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880AA438"))) PPC_WEAK_FUNC(sub_880AA438);
PPC_FUNC_IMPL(__imp__sub_880AA438) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807112c
	ctx.lr = 0x880AA440;
	__savegprlr_17(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r18,r4
	ctx.r18.u64 = ctx.r4.u64;
	// lwz r21,2304(r3)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r17,r5
	ctx.r17.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880AA460;
	sub_88096BC8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r30,8(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r19,0
	ctx.r19.s64 = 0;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x880aa488
	if (ctx.cr6.lt) goto loc_880AA488;
	// beq cr6,0x880aa4e8
	if (ctx.cr6.eq) goto loc_880AA4E8;
loc_880AA47C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8807117c
	__restgprlr_17(ctx, base);
	return;
loc_880AA488:
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,48
	ctx.r8.s64 = 48;
	// li r3,16
	ctx.r3.s64 = 16;
	// stw r11,64(r10)
	PPC_STORE_U32(ctx.r10.u32 + 64, ctx.r11.u32);
	// lwz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,72(r7)
	PPC_STORE_U32(ctx.r7.u32 + 72, ctx.r11.u32);
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,68(r6)
	PPC_STORE_U32(ctx.r6.u32 + 68, ctx.r11.u32);
	// stw r9,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
	// stw r19,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r19.u32);
	// stw r19,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r19.u32);
	// stw r8,36(r21)
	PPC_STORE_U32(ctx.r21.u32 + 36, ctx.r8.u32);
	// bl 0x881534c8
	ctx.lr = 0x880AA4C4;
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
	// stw r4,40(r21)
	PPC_STORE_U32(ctx.r21.u32 + 40, ctx.r4.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// stw r3,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
loc_880AA4E8:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// bge 0x880aa47c
	if (!ctx.cr0.lt) goto loc_880AA47C;
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lis r9,-30682
	ctx.r9.s64 = -2010775552;
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addi r28,r30,1
	ctx.r28.s64 = ctx.r30.s64 + 1;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r9,r9,-16456
	ctx.r9.s64 = ctx.r9.s64 + -16456;
	// lwz r6,28(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r8.u32);
	// lwz r8,12(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lis r25,-30667
	ctx.r25.s64 = -2009792512;
	// add r30,r10,r9
	ctx.r30.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r10,16(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// lis r24,-30667
	ctx.r24.s64 = -2009792512;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lis r20,-30667
	ctx.r20.s64 = -2009792512;
	// lis r22,-30667
	ctx.r22.s64 = -2009792512;
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// srawi r7,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 2;
	// addze r5,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r5.s64 = temp.s64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// addis r7,r5,24
	ctx.r7.s64 = ctx.r5.s64 + 1572864;
	// addze r9,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r9.s64 = temp.s64;
	// mullw r11,r7,r6
	ctx.r11.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r6.s32);
	// add r27,r11,r8
	ctx.r27.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r26,r9,r10
	ctx.r26.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r27,12364(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12364, ctx.r27.u32);
	// stw r26,12372(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12372, ctx.r26.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880AA580;
	sub_880F52C8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x881534c8
	ctx.lr = 0x880AA58C;
	sub_881534C8(ctx, base);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// extsh r6,r3
	ctx.r6.s64 = ctx.r3.s16;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r3,16
	ctx.r3.s64 = 16;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r4,r5,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r11,r4,r6
	ctx.r11.s64 = ctx.r6.s64 - ctx.r4.s64;
	// addi r23,r11,248
	ctx.r23.s64 = ctx.r11.s64 + 248;
	// bl 0x881534c8
	ctx.lr = 0x880AA5B0;
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
	ctx.lr = 0x880AA5C4;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x880aa5e0
	if (ctx.cr6.eq) goto loc_880AA5E0;
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// clrlwi r10,r11,16
	ctx.r10.u64 = ctx.r11.u32 & 0xFFFF;
	// stw r10,100(r29)
	PPC_STORE_U32(ctx.r29.u32 + 100, ctx.r10.u32);
	// lwz r9,32(r21)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r21.u32 + 32);
	// stw r9,144(r29)
	PPC_STORE_U32(ctx.r29.u32 + 144, ctx.r9.u32);
loc_880AA5E0:
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r21
	ctx.r11.u64 = ctx.r11.u64 + ctx.r21.u64;
	// lwz r9,9988(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 9988);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x880aa630
	if (!ctx.cr6.eq) goto loc_880AA630;
	// addi r10,r10,500
	ctx.r10.s64 = ctx.r10.s64 + 500;
	// lwz r8,10004(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 10004);
	// lwz r6,9996(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 9996);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r5,9992(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 9992);
	// lwz r7,0(r21)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r21.u32 + 0);
	// add r11,r10,r9
	ctx.r11.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r4,12(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lwzx r7,r10,r21
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r21.u32);
	// bl 0x880f5438
	ctx.lr = 0x880AA630;
	sub_880F5438(ctx, base);
loc_880AA630:
	// stw r27,12364(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12364, ctx.r27.u32);
	// li r11,24
	ctx.r11.s64 = 24;
	// stw r26,12372(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12372, ctx.r26.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,12380(r22)
	PPC_STORE_U32(ctx.r22.u32 + 12380, ctx.r11.u32);
	// bl 0x880f34b0
	ctx.lr = 0x880AA64C;
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
	// beq cr6,0x880aa6a0
	if (ctx.cr6.eq) goto loc_880AA6A0;
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
loc_880AA6A0:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x880f34b0
	ctx.lr = 0x880AA6AC;
	sub_880F34B0(ctx, base);
	// mullw r11,r26,r29
	ctx.r11.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r29.s32);
	// addi r26,r11,12345
	ctx.r26.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r26,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r26.u32);
	// beq cr6,0x880aa6e8
	if (ctx.cr6.eq) goto loc_880AA6E8;
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
loc_880AA6E8:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// stw r28,12376(r20)
	PPC_STORE_U32(ctx.r20.u32 + 12376, ctx.r28.u32);
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x880f34b0
	ctx.lr = 0x880AA6F8;
	sub_880F34B0(ctx, base);
	// mullw r11,r26,r29
	ctx.r11.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r29.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r11,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r11.u32);
	// beq cr6,0x880aa734
	if (ctx.cr6.eq) goto loc_880AA734;
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
loc_880AA734:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// cmplwi cr6,r11,23
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 23, ctx.xer);
	// blt cr6,0x880aa47c
	if (ctx.cr6.lt) goto loc_880AA47C;
	// stw r19,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r19.u32);
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// bl 0x88096b40
	ctx.lr = 0x880AA758;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8807117c
	__restgprlr_17(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880AA764"))) PPC_WEAK_FUNC(sub_880AA764);
PPC_FUNC_IMPL(__imp__sub_880AA764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880AA768"))) PPC_WEAK_FUNC(sub_880AA768);
PPC_FUNC_IMPL(__imp__sub_880AA768) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807112c
	ctx.lr = 0x880AA770;
	__savegprlr_17(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r18,r4
	ctx.r18.u64 = ctx.r4.u64;
	// lwz r21,2304(r3)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r17,r5
	ctx.r17.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880AA790;
	sub_88096BC8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r30,8(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r19,0
	ctx.r19.s64 = 0;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x880aa7b8
	if (ctx.cr6.lt) goto loc_880AA7B8;
	// beq cr6,0x880aa818
	if (ctx.cr6.eq) goto loc_880AA818;
loc_880AA7AC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8807117c
	__restgprlr_17(ctx, base);
	return;
loc_880AA7B8:
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,48
	ctx.r8.s64 = 48;
	// li r3,16
	ctx.r3.s64 = 16;
	// stw r11,64(r10)
	PPC_STORE_U32(ctx.r10.u32 + 64, ctx.r11.u32);
	// lwz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,72(r7)
	PPC_STORE_U32(ctx.r7.u32 + 72, ctx.r11.u32);
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,68(r6)
	PPC_STORE_U32(ctx.r6.u32 + 68, ctx.r11.u32);
	// stw r9,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
	// stw r19,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r19.u32);
	// stw r19,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r19.u32);
	// stw r8,36(r21)
	PPC_STORE_U32(ctx.r21.u32 + 36, ctx.r8.u32);
	// bl 0x881534c8
	ctx.lr = 0x880AA7F4;
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
	// stw r4,40(r21)
	PPC_STORE_U32(ctx.r21.u32 + 40, ctx.r4.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// stw r3,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
loc_880AA818:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// bge 0x880aa7ac
	if (!ctx.cr0.lt) goto loc_880AA7AC;
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lis r9,-30682
	ctx.r9.s64 = -2010775552;
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addi r28,r30,1
	ctx.r28.s64 = ctx.r30.s64 + 1;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r9,r9,-16456
	ctx.r9.s64 = ctx.r9.s64 + -16456;
	// lwz r6,28(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r8.u32);
	// lwz r8,12(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lis r25,-30667
	ctx.r25.s64 = -2009792512;
	// add r30,r10,r9
	ctx.r30.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r10,16(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// lis r24,-30667
	ctx.r24.s64 = -2009792512;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lis r20,-30667
	ctx.r20.s64 = -2009792512;
	// lis r22,-30667
	ctx.r22.s64 = -2009792512;
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// srawi r7,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 2;
	// addze r5,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r5.s64 = temp.s64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// addis r7,r5,24
	ctx.r7.s64 = ctx.r5.s64 + 1572864;
	// addze r9,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r9.s64 = temp.s64;
	// mullw r11,r7,r6
	ctx.r11.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r6.s32);
	// add r27,r11,r8
	ctx.r27.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r26,r9,r10
	ctx.r26.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r27,12364(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12364, ctx.r27.u32);
	// stw r26,12372(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12372, ctx.r26.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880AA8B0;
	sub_880F52C8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x881534c8
	ctx.lr = 0x880AA8BC;
	sub_881534C8(ctx, base);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// extsh r6,r3
	ctx.r6.s64 = ctx.r3.s16;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r3,16
	ctx.r3.s64 = 16;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r4,r5,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r11,r4,r6
	ctx.r11.s64 = ctx.r6.s64 - ctx.r4.s64;
	// addi r23,r11,248
	ctx.r23.s64 = ctx.r11.s64 + 248;
	// bl 0x881534c8
	ctx.lr = 0x880AA8E0;
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
	ctx.lr = 0x880AA8F4;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x880aa910
	if (ctx.cr6.eq) goto loc_880AA910;
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// clrlwi r10,r11,16
	ctx.r10.u64 = ctx.r11.u32 & 0xFFFF;
	// stw r10,100(r29)
	PPC_STORE_U32(ctx.r29.u32 + 100, ctx.r10.u32);
	// lwz r9,32(r21)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r21.u32 + 32);
	// stw r9,144(r29)
	PPC_STORE_U32(ctx.r29.u32 + 144, ctx.r9.u32);
loc_880AA910:
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r21
	ctx.r11.u64 = ctx.r11.u64 + ctx.r21.u64;
	// lwz r9,9988(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 9988);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x880aa960
	if (!ctx.cr6.eq) goto loc_880AA960;
	// addi r10,r10,500
	ctx.r10.s64 = ctx.r10.s64 + 500;
	// lwz r8,10004(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 10004);
	// lwz r6,9996(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 9996);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r5,9992(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 9992);
	// lwz r7,0(r21)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r21.u32 + 0);
	// add r11,r10,r9
	ctx.r11.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r4,12(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lwzx r7,r10,r21
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r21.u32);
	// bl 0x880f5438
	ctx.lr = 0x880AA960;
	sub_880F5438(ctx, base);
loc_880AA960:
	// stw r27,12364(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12364, ctx.r27.u32);
	// li r11,24
	ctx.r11.s64 = 24;
	// stw r26,12372(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12372, ctx.r26.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,12380(r22)
	PPC_STORE_U32(ctx.r22.u32 + 12380, ctx.r11.u32);
	// bl 0x880f34b0
	ctx.lr = 0x880AA97C;
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
	// beq cr6,0x880aa9d0
	if (ctx.cr6.eq) goto loc_880AA9D0;
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
loc_880AA9D0:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x880f34b0
	ctx.lr = 0x880AA9DC;
	sub_880F34B0(ctx, base);
	// mullw r11,r26,r29
	ctx.r11.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r29.s32);
	// addi r26,r11,12345
	ctx.r26.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r26,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r26.u32);
	// beq cr6,0x880aaa18
	if (ctx.cr6.eq) goto loc_880AAA18;
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
loc_880AAA18:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// stw r28,12376(r20)
	PPC_STORE_U32(ctx.r20.u32 + 12376, ctx.r28.u32);
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x880f34b0
	ctx.lr = 0x880AAA28;
	sub_880F34B0(ctx, base);
	// mullw r11,r26,r29
	ctx.r11.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r29.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r11,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r11.u32);
	// beq cr6,0x880aaa64
	if (ctx.cr6.eq) goto loc_880AAA64;
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
loc_880AAA64:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// cmplwi cr6,r11,23
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 23, ctx.xer);
	// blt cr6,0x880aa7ac
	if (ctx.cr6.lt) goto loc_880AA7AC;
	// stw r19,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r19.u32);
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// bl 0x88096b40
	ctx.lr = 0x880AAA88;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8807117c
	__restgprlr_17(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880AAA94"))) PPC_WEAK_FUNC(sub_880AAA94);
PPC_FUNC_IMPL(__imp__sub_880AAA94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880AAA98"))) PPC_WEAK_FUNC(sub_880AAA98);
PPC_FUNC_IMPL(__imp__sub_880AAA98) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880AAAA0;
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
	ctx.lr = 0x880AAAC0;
	sub_88096BC8(ctx, base);
	// addi r10,r29,9064
	ctx.r10.s64 = ctx.r29.s64 + 9064;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r9,9132(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 9132);
	// cmpwi cr6,r9,6
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 6, ctx.xer);
	// beq cr6,0x880aaae0
	if (ctx.cr6.eq) goto loc_880AAAE0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_880AAAE0:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r8,6
	ctx.r8.s64 = 6;
	// li r10,3
	ctx.r10.s64 = 3;
	// lis r7,-30709
	ctx.r7.s64 = -2012545024;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r7,-29456
	ctx.r5.s64 = ctx.r7.s64 + -29456;
	// stw r8,68(r9)
	PPC_STORE_U32(ctx.r9.u32 + 68, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x88096c60
	ctx.lr = 0x880AAB0C;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880AAB18"))) PPC_WEAK_FUNC(sub_880AAB18);
PPC_FUNC_IMPL(__imp__sub_880AAB18) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880AAB20;
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
	ctx.lr = 0x880AAB40;
	sub_88096BC8(ctx, base);
	// addi r10,r29,9064
	ctx.r10.s64 = ctx.r29.s64 + 9064;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r9,9132(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 9132);
	// cmpwi cr6,r9,4
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 4, ctx.xer);
	// beq cr6,0x880aab60
	if (ctx.cr6.eq) goto loc_880AAB60;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_880AAB60:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r8,4
	ctx.r8.s64 = 4;
	// li r10,3
	ctx.r10.s64 = 3;
	// lis r7,-30709
	ctx.r7.s64 = -2012545024;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r7,-29256
	ctx.r5.s64 = ctx.r7.s64 + -29256;
	// stw r8,68(r9)
	PPC_STORE_U32(ctx.r9.u32 + 68, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x88096c60
	ctx.lr = 0x880AAB8C;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880AAB98"))) PPC_WEAK_FUNC(sub_880AAB98);
PPC_FUNC_IMPL(__imp__sub_880AAB98) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880AABA0;
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
	ctx.lr = 0x880AABC0;
	sub_88096BC8(ctx, base);
	// addi r10,r29,9064
	ctx.r10.s64 = ctx.r29.s64 + 9064;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r9,9132(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 9132);
	// cmpwi cr6,r9,4
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 4, ctx.xer);
	// beq cr6,0x880aabe0
	if (ctx.cr6.eq) goto loc_880AABE0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_880AABE0:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r8,4
	ctx.r8.s64 = 4;
	// li r10,2
	ctx.r10.s64 = 2;
	// lis r7,-30709
	ctx.r7.s64 = -2012545024;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r7,-29056
	ctx.r5.s64 = ctx.r7.s64 + -29056;
	// stw r8,68(r9)
	PPC_STORE_U32(ctx.r9.u32 + 68, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x88096c60
	ctx.lr = 0x880AAC0C;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880AAC18"))) PPC_WEAK_FUNC(sub_880AAC18);
PPC_FUNC_IMPL(__imp__sub_880AAC18) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880AAC20;
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
	ctx.lr = 0x880AAC40;
	sub_88096BC8(ctx, base);
	// addi r10,r29,9064
	ctx.r10.s64 = ctx.r29.s64 + 9064;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r9,9132(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 9132);
	// cmpwi cr6,r9,3
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 3, ctx.xer);
	// beq cr6,0x880aac60
	if (ctx.cr6.eq) goto loc_880AAC60;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_880AAC60:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r8,3
	ctx.r8.s64 = 3;
	// li r10,2
	ctx.r10.s64 = 2;
	// lis r7,-30709
	ctx.r7.s64 = -2012545024;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r7,-28856
	ctx.r5.s64 = ctx.r7.s64 + -28856;
	// stw r8,68(r9)
	PPC_STORE_U32(ctx.r9.u32 + 68, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x88096c60
	ctx.lr = 0x880AAC8C;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880AAC98"))) PPC_WEAK_FUNC(sub_880AAC98);
PPC_FUNC_IMPL(__imp__sub_880AAC98) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880AACA0;
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
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880AACC0;
	sub_88096BC8(ctx, base);
	// addi r11,r31,9064
	ctx.r11.s64 = ctx.r31.s64 + 9064;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// lwz r10,9132(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9132);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// beq cr6,0x880aacdc
	if (ctx.cr6.eq) goto loc_880AACDC;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_880AACDC:
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r9,68(r10)
	PPC_STORE_U32(ctx.r10.u32 + 68, ctx.r9.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// lwz r8,9896(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9896);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x880aad14
	if (!ctx.cr6.eq) goto loc_880AAD14;
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,125
	ctx.r5.s64 = 125;
	// li r4,216
	ctx.r4.s64 = 216;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x880e31b0
	ctx.lr = 0x880AAD14;
	sub_880E31B0(ctx, base);
loc_880AAD14:
	// lwz r11,9896(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9896);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x880aad34
	if (!ctx.cr6.eq) goto loc_880AAD34;
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,125
	ctx.r5.s64 = 125;
	// li r4,215
	ctx.r4.s64 = 215;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x880e31b0
	ctx.lr = 0x880AAD34;
	sub_880E31B0(ctx, base);
loc_880AAD34:
	// lis r11,-30709
	ctx.r11.s64 = -2012545024;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r5,r11,-28656
	ctx.r5.s64 = ctx.r11.s64 + -28656;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096c60
	ctx.lr = 0x880AAD48;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880AAD54"))) PPC_WEAK_FUNC(sub_880AAD54);
PPC_FUNC_IMPL(__imp__sub_880AAD54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880AAD58"))) PPC_WEAK_FUNC(sub_880AAD58);
PPC_FUNC_IMPL(__imp__sub_880AAD58) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x880AAD60;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880AAD80;
	sub_88096BC8(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// bgt 0x880aaf70
	if (ctx.cr0.gt) goto loc_880AAF70;
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// neg r8,r11
	ctx.r8.s64 = -ctx.r11.s64;
	// addi r7,r11,3
	ctx.r7.s64 = ctx.r11.s64 + 3;
	// rlwinm r27,r8,12,0,19
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 12) & 0xFFFFF000;
	// lwz r11,26428(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26428);
	// stw r7,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r7.u32);
	// clrlwi r6,r11,30
	ctx.r6.u64 = ctx.r11.u32 & 0x3;
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne cr6,0x880aaef8
	if (!ctx.cr6.eq) goto loc_880AAEF8;
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmpwi cr6,r9,-1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, -1, ctx.xer);
	// bne cr6,0x880aaddc
	if (!ctx.cr6.eq) goto loc_880AADDC;
	// lwz r11,10188(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 10188);
	// lwz r10,10192(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 10192);
	// b 0x880aade4
	goto loc_880AADE4;
loc_880AADDC:
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_880AADE4:
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x880aadf4
	if (!ctx.cr6.eq) goto loc_880AADF4;
	// lwz r11,10196(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 10196);
	// lwz r10,10200(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 10200);
loc_880AADF4:
	// lis r9,-30667
	ctx.r9.s64 = -2009792512;
	// lis r8,-30667
	ctx.r8.s64 = -2009792512;
	// lis r24,-30671
	ctx.r24.s64 = -2010054656;
	// lis r7,16838
	ctx.r7.s64 = 1103495168;
	// lis r6,-30667
	ctx.r6.s64 = -2009792512;
	// stw r11,12364(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12364, ctx.r11.u32);
	// ori r31,r7,20077
	ctx.r31.u64 = ctx.r7.u64 | 20077;
	// stw r10,12372(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12372, ctx.r10.u32);
	// lis r8,-30667
	ctx.r8.s64 = -2009792512;
	// lwz r11,4200(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 4200);
	// lis r7,-30667
	ctx.r7.s64 = -2009792512;
	// li r10,88
	ctx.r10.s64 = 88;
	// mullw r11,r11,r31
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r31.s32);
	// stw r10,12376(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12376, ctx.r10.u32);
	// addi r30,r11,12345
	ctx.r30.s64 = ctx.r11.s64 + 12345;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r30,4200(r24)
	PPC_STORE_U32(ctx.r24.u32 + 4200, ctx.r30.u32);
	// li r4,88
	ctx.r4.s64 = 88;
	// lhz r9,4200(r24)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r24.u32 + 4200);
	// clrlwi r5,r9,28
	ctx.r5.u64 = ctx.r9.u32 & 0xF;
	// li r3,2
	ctx.r3.s64 = 2;
	// stw r5,12384(r6)
	PPC_STORE_U32(ctx.r6.u32 + 12384, ctx.r5.u32);
	// stw r11,12380(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12380, ctx.r11.u32);
	// bl 0x880f25b8
	ctx.lr = 0x880AAE54;
	sub_880F25B8(ctx, base);
	// mullw r11,r30,r31
	ctx.r11.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r31.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// lis r6,15887
	ctx.r6.s64 = 1041170432;
	// stw r11,4200(r24)
	PPC_STORE_U32(ctx.r24.u32 + 4200, ctx.r11.u32);
	// mullw r11,r11,r31
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r31.s32);
	// lhz r5,4200(r24)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r24.u32 + 4200);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// ori r4,r6,33761
	ctx.r4.u64 = ctx.r6.u64 | 33761;
	// stw r11,4200(r24)
	PPC_STORE_U32(ctx.r24.u32 + 4200, ctx.r11.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// lhz r10,4200(r24)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r24.u32 + 4200);
	// mulhwu r9,r5,r4
	ctx.r9.u64 = (uint64_t(ctx.r5.u32) * uint64_t(ctx.r4.u32)) >> 32;
	// rlwinm r11,r9,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 29) & 0x1FFFFFFF;
	// clrlwi r8,r10,27
	ctx.r8.u64 = ctx.r10.u32 & 0x1F;
	// rlwinm r10,r11,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xFFFFFFE0;
	// subfic r6,r8,-240
	ctx.xer.ca = ctx.r8.u32 <= 4294967056;
	ctx.r6.s64 = -240 - ctx.r8.s64;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// clrlwi r10,r6,23
	ctx.r10.u64 = ctx.r6.u32 & 0x1FF;
	// subf r5,r7,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r7.s64;
	// extsh r11,r5
	ctx.r11.s64 = ctx.r5.s16;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// beq cr6,0x880aaef8
	if (ctx.cr6.eq) goto loc_880AAEF8;
	// lis r8,-30714
	ctx.r8.s64 = -2012872704;
	// stw r10,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r10.u32);
	// addic. r9,r3,28
	ctx.xer.ca = ctx.r3.u32 > 4294967267;
	ctx.r9.s64 = ctx.r3.s64 + 28;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r11.u32);
	// addi r7,r3,24
	ctx.r7.s64 = ctx.r3.s64 + 24;
	// clrlwi r10,r10,23
	ctx.r10.u64 = ctx.r10.u32 & 0x1FF;
	// addi r8,r8,9552
	ctx.r8.s64 = ctx.r8.s64 + 9552;
	// beq 0x880aaee0
	if (ctx.cr0.eq) goto loc_880AAEE0;
	// addi r6,r10,128
	ctx.r6.s64 = ctx.r10.s64 + 128;
	// rlwinm r5,r6,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// lwzx r4,r5,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r8.u32);
	// mullw r3,r4,r11
	ctx.r3.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r11.s32);
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
loc_880AAEE0:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x880aaef8
	if (ctx.cr6.eq) goto loc_880AAEF8;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r8
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// mullw r8,r9,r11
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// stw r8,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r8.u32);
loc_880AAEF8:
	// lwz r11,16(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x880aaf34
	if (!ctx.cr6.eq) goto loc_880AAF34;
	// lwz r11,256(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 256);
	// add. r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,256(r29)
	PPC_STORE_U32(ctx.r29.u32 + 256, ctx.r11.u32);
	// bgt 0x880aaf34
	if (ctx.cr0.gt) goto loc_880AAF34;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// stw r11,256(r29)
	PPC_STORE_U32(ctx.r29.u32 + 256, ctx.r11.u32);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x88096b40
	ctx.lr = 0x880AAF28;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
loc_880AAF34:
	// lwz r11,16(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x880aaf70
	if (!ctx.cr6.eq) goto loc_880AAF70;
	// lwz r11,260(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 260);
	// add. r11,r27,r11
	ctx.r11.u64 = ctx.r27.u64 + ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,260(r29)
	PPC_STORE_U32(ctx.r29.u32 + 260, ctx.r11.u32);
	// bgt 0x880aaf70
	if (ctx.cr0.gt) goto loc_880AAF70;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// stw r11,260(r29)
	PPC_STORE_U32(ctx.r29.u32 + 260, ctx.r11.u32);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x88096b40
	ctx.lr = 0x880AAF64;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
loc_880AAF70:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880AAF7C"))) PPC_WEAK_FUNC(sub_880AAF7C);
PPC_FUNC_IMPL(__imp__sub_880AAF7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880AAF80"))) PPC_WEAK_FUNC(sub_880AAF80);
PPC_FUNC_IMPL(__imp__sub_880AAF80) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880AAF88;
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
	ctx.lr = 0x880AAFA8;
	sub_88096BC8(ctx, base);
	// addi r10,r29,7480
	ctx.r10.s64 = ctx.r29.s64 + 7480;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r9,7548(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 7548);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// beq cr6,0x880aafc8
	if (ctx.cr6.eq) goto loc_880AAFC8;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_880AAFC8:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r10,2
	ctx.r10.s64 = 2;
	// lis r7,-30709
	ctx.r7.s64 = -2012545024;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r7,-28456
	ctx.r5.s64 = ctx.r7.s64 + -28456;
	// stw r8,68(r9)
	PPC_STORE_U32(ctx.r9.u32 + 68, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x88096c60
	ctx.lr = 0x880AAFF4;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880AB000"))) PPC_WEAK_FUNC(sub_880AB000);
PPC_FUNC_IMPL(__imp__sub_880AB000) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880AB008;
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
	ctx.lr = 0x880AB028;
	sub_88096BC8(ctx, base);
	// addi r10,r29,7128
	ctx.r10.s64 = ctx.r29.s64 + 7128;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r9,7196(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 7196);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// beq cr6,0x880ab048
	if (ctx.cr6.eq) goto loc_880AB048;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_880AB048:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r10,2
	ctx.r10.s64 = 2;
	// lis r7,-30709
	ctx.r7.s64 = -2012545024;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r7,-28256
	ctx.r5.s64 = ctx.r7.s64 + -28256;
	// stw r8,68(r9)
	PPC_STORE_U32(ctx.r9.u32 + 68, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x88096c60
	ctx.lr = 0x880AB074;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880AB080"))) PPC_WEAK_FUNC(sub_880AB080);
PPC_FUNC_IMPL(__imp__sub_880AB080) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880AB088;
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
	ctx.lr = 0x880AB0A8;
	sub_88096BC8(ctx, base);
	// addi r10,r29,7304
	ctx.r10.s64 = ctx.r29.s64 + 7304;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r9,7372(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 7372);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// beq cr6,0x880ab0c8
	if (ctx.cr6.eq) goto loc_880AB0C8;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_880AB0C8:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r10,2
	ctx.r10.s64 = 2;
	// lis r7,-30709
	ctx.r7.s64 = -2012545024;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r7,-28056
	ctx.r5.s64 = ctx.r7.s64 + -28056;
	// stw r8,68(r9)
	PPC_STORE_U32(ctx.r9.u32 + 68, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x88096c60
	ctx.lr = 0x880AB0F4;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880AB100"))) PPC_WEAK_FUNC(sub_880AB100);
PPC_FUNC_IMPL(__imp__sub_880AB100) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880AB108;
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
	ctx.lr = 0x880AB128;
	sub_88096BC8(ctx, base);
	// addi r10,r29,7216
	ctx.r10.s64 = ctx.r29.s64 + 7216;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r9,7284(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 7284);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// beq cr6,0x880ab148
	if (ctx.cr6.eq) goto loc_880AB148;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_880AB148:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r10,2
	ctx.r10.s64 = 2;
	// lis r7,-30709
	ctx.r7.s64 = -2012545024;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r7,-28056
	ctx.r5.s64 = ctx.r7.s64 + -28056;
	// stw r8,68(r9)
	PPC_STORE_U32(ctx.r9.u32 + 68, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x88096c60
	ctx.lr = 0x880AB174;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880AB180"))) PPC_WEAK_FUNC(sub_880AB180);
PPC_FUNC_IMPL(__imp__sub_880AB180) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880AB188;
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
	ctx.lr = 0x880AB1A8;
	sub_88096BC8(ctx, base);
	// addi r10,r29,8712
	ctx.r10.s64 = ctx.r29.s64 + 8712;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r9,8780(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8780);
	// cmpwi cr6,r9,2
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 2, ctx.xer);
	// bne cr6,0x880ab1c8
	if (!ctx.cr6.eq) goto loc_880AB1C8;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_880AB1C8:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r8,5
	ctx.r8.s64 = 5;
	// li r10,2
	ctx.r10.s64 = 2;
	// lis r7,-30709
	ctx.r7.s64 = -2012545024;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r7,-27856
	ctx.r5.s64 = ctx.r7.s64 + -27856;
	// stw r8,68(r9)
	PPC_STORE_U32(ctx.r9.u32 + 68, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x88096c60
	ctx.lr = 0x880AB1F4;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880AB200"))) PPC_WEAK_FUNC(sub_880AB200);
PPC_FUNC_IMPL(__imp__sub_880AB200) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880AB208;
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
	ctx.lr = 0x880AB228;
	sub_88096BC8(ctx, base);
	// addi r10,r29,8712
	ctx.r10.s64 = ctx.r29.s64 + 8712;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r9,8780(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8780);
	// cmpwi cr6,r9,2
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 2, ctx.xer);
	// bne cr6,0x880ab248
	if (!ctx.cr6.eq) goto loc_880AB248;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_880AB248:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r8,3
	ctx.r8.s64 = 3;
	// li r10,2
	ctx.r10.s64 = 2;
	// lis r7,-30709
	ctx.r7.s64 = -2012545024;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r7,-27656
	ctx.r5.s64 = ctx.r7.s64 + -27656;
	// stw r8,68(r9)
	PPC_STORE_U32(ctx.r9.u32 + 68, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x88096c60
	ctx.lr = 0x880AB274;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880AB280"))) PPC_WEAK_FUNC(sub_880AB280);
PPC_FUNC_IMPL(__imp__sub_880AB280) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880AB288;
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
	ctx.lr = 0x880AB2A8;
	sub_88096BC8(ctx, base);
	// addi r10,r29,8360
	ctx.r10.s64 = ctx.r29.s64 + 8360;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r9,8428(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8428);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x880ab2c4
	if (!ctx.cr6.eq) goto loc_880AB2C4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_880AB2C4:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r8,-30709
	ctx.r8.s64 = -2012545024;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r8,-27256
	ctx.r5.s64 = ctx.r8.s64 + -27256;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,68(r9)
	PPC_STORE_U32(ctx.r9.u32 + 68, ctx.r10.u32);
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x88096c60
	ctx.lr = 0x880AB2EC;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880AB2F8"))) PPC_WEAK_FUNC(sub_880AB2F8);
PPC_FUNC_IMPL(__imp__sub_880AB2F8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880AB300;
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
	ctx.lr = 0x880AB320;
	sub_88096BC8(ctx, base);
	// addi r10,r29,8272
	ctx.r10.s64 = ctx.r29.s64 + 8272;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r9,8340(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8340);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x880ab33c
	if (!ctx.cr6.eq) goto loc_880AB33C;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_880AB33C:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r8,-30709
	ctx.r8.s64 = -2012545024;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r8,-27256
	ctx.r5.s64 = ctx.r8.s64 + -27256;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,68(r9)
	PPC_STORE_U32(ctx.r9.u32 + 68, ctx.r10.u32);
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x88096c60
	ctx.lr = 0x880AB364;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880AB370"))) PPC_WEAK_FUNC(sub_880AB370);
PPC_FUNC_IMPL(__imp__sub_880AB370) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880AB378;
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
	ctx.lr = 0x880AB398;
	sub_88096BC8(ctx, base);
	// addi r10,r29,7744
	ctx.r10.s64 = ctx.r29.s64 + 7744;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r9,7812(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 7812);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x880ab3b4
	if (!ctx.cr6.eq) goto loc_880AB3B4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_880AB3B4:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r8,3
	ctx.r8.s64 = 3;
	// li r10,2
	ctx.r10.s64 = 2;
	// lis r7,-30709
	ctx.r7.s64 = -2012545024;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r7,-27008
	ctx.r5.s64 = ctx.r7.s64 + -27008;
	// stw r8,68(r9)
	PPC_STORE_U32(ctx.r9.u32 + 68, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x88096c60
	ctx.lr = 0x880AB3E0;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880AB3EC"))) PPC_WEAK_FUNC(sub_880AB3EC);
PPC_FUNC_IMPL(__imp__sub_880AB3EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880AB3F0"))) PPC_WEAK_FUNC(sub_880AB3F0);
PPC_FUNC_IMPL(__imp__sub_880AB3F0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880AB3F8;
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
	ctx.lr = 0x880AB418;
	sub_88096BC8(ctx, base);
	// addi r10,r29,7744
	ctx.r10.s64 = ctx.r29.s64 + 7744;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r9,7812(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 7812);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x880ab434
	if (!ctx.cr6.eq) goto loc_880AB434;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_880AB434:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r10,2
	ctx.r10.s64 = 2;
	// lis r7,-30709
	ctx.r7.s64 = -2012545024;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r7,-26808
	ctx.r5.s64 = ctx.r7.s64 + -26808;
	// stw r8,68(r9)
	PPC_STORE_U32(ctx.r9.u32 + 68, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x88096c60
	ctx.lr = 0x880AB460;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880AB46C"))) PPC_WEAK_FUNC(sub_880AB46C);
PPC_FUNC_IMPL(__imp__sub_880AB46C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880AB470"))) PPC_WEAK_FUNC(sub_880AB470);
PPC_FUNC_IMPL(__imp__sub_880AB470) {
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
	// li r6,255
	ctx.r6.s64 = 255;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// stw r6,9880(r7)
	PPC_STORE_U32(ctx.r7.u32 + 9880, ctx.r6.u32);
	// bl 0x880a4e28
	ctx.lr = 0x880AB494;
	sub_880A4E28(ctx, base);
	// lis r3,-30709
	ctx.r3.s64 = -2012545024;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// addi r5,r3,-26608
	ctx.r5.s64 = ctx.r3.s64 + -26608;
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// bl 0x88096c60
	ctx.lr = 0x880AB4A8;
	sub_88096C60(ctx, base);
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

__attribute__((alias("__imp__sub_880AB4BC"))) PPC_WEAK_FUNC(sub_880AB4BC);
PPC_FUNC_IMPL(__imp__sub_880AB4BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880AB4C0"))) PPC_WEAK_FUNC(sub_880AB4C0);
PPC_FUNC_IMPL(__imp__sub_880AB4C0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880AB4C8;
	__savegprlr_29(ctx, base);
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
	ctx.lr = 0x880AB4E4;
	sub_88096BC8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x880ab500
	if (ctx.cr6.lt) goto loc_880AB500;
	// beq cr6,0x880ab514
	if (ctx.cr6.eq) goto loc_880AB514;
loc_880AB4F4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_880AB500:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
loc_880AB514:
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r4,r11,30408
	ctx.r4.s64 = ctx.r11.s64 + 30408;
	// rlwinm r9,r10,12,0,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFFFF000;
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
	// neg r29,r9
	ctx.r29.s64 = -ctx.r9.s64;
	// mr r5,r8
	ctx.r5.u64 = ctx.r8.u64;
	// lwz r11,32(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 32);
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// stw r10,376(r4)
	PPC_STORE_U32(ctx.r4.u32 + 376, ctx.r10.u32);
	// stw r9,384(r4)
	PPC_STORE_U32(ctx.r4.u32 + 384, ctx.r9.u32);
	// stw r8,372(r4)
	PPC_STORE_U32(ctx.r4.u32 + 372, ctx.r8.u32);
	// stw r8,380(r4)
	PPC_STORE_U32(ctx.r4.u32 + 380, ctx.r8.u32);
	// stw r29,248(r11)
	PPC_STORE_U32(ctx.r11.u32 + 248, ctx.r29.u32);
	// stw r8,244(r11)
	PPC_STORE_U32(ctx.r11.u32 + 244, ctx.r8.u32);
	// lwz r9,32(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 32);
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r10,r11,12,0,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 12) & 0xFFFFF000;
	// neg r29,r10
	ctx.r29.s64 = -ctx.r10.s64;
	// stw r11,588(r4)
	PPC_STORE_U32(ctx.r4.u32 + 588, ctx.r11.u32);
	// stw r10,596(r4)
	PPC_STORE_U32(ctx.r4.u32 + 596, ctx.r10.u32);
	// stw r8,584(r4)
	PPC_STORE_U32(ctx.r4.u32 + 584, ctx.r8.u32);
	// stw r8,592(r4)
	PPC_STORE_U32(ctx.r4.u32 + 592, ctx.r8.u32);
	// stw r8,252(r9)
	PPC_STORE_U32(ctx.r9.u32 + 252, ctx.r8.u32);
	// stw r29,256(r9)
	PPC_STORE_U32(ctx.r9.u32 + 256, ctx.r29.u32);
	// lwz r9,32(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 32);
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r10,r11,12,0,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 12) & 0xFFFFF000;
	// neg r6,r10
	ctx.r6.s64 = -ctx.r10.s64;
	// stw r11,800(r4)
	PPC_STORE_U32(ctx.r4.u32 + 800, ctx.r11.u32);
	// stw r8,796(r4)
	PPC_STORE_U32(ctx.r4.u32 + 796, ctx.r8.u32);
	// stw r8,804(r4)
	PPC_STORE_U32(ctx.r4.u32 + 804, ctx.r8.u32);
	// stw r10,808(r4)
	PPC_STORE_U32(ctx.r4.u32 + 808, ctx.r10.u32);
	// stw r8,260(r9)
	PPC_STORE_U32(ctx.r9.u32 + 260, ctx.r8.u32);
	// stw r6,264(r9)
	PPC_STORE_U32(ctx.r9.u32 + 264, ctx.r6.u32);
	// lwz r5,12(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addic. r11,r5,-1
	ctx.xer.ca = ctx.r5.u32 > 0;
	ctx.r11.s64 = ctx.r5.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// bge 0x880ab4f4
	if (!ctx.cr0.lt) goto loc_880AB4F4;
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// cmpwi cr6,r11,24
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 24, ctx.xer);
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// blt cr6,0x880ab4f4
	if (ctx.cr6.lt) goto loc_880AB4F4;
	// li r11,24
	ctx.r11.s64 = 24;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096b40
	ctx.lr = 0x880AB5E4;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880AB5F0"))) PPC_WEAK_FUNC(sub_880AB5F0);
PPC_FUNC_IMPL(__imp__sub_880AB5F0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x880AB5F8;
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
	ctx.lr = 0x880AB61C;
	sub_88096BC8(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r31,8712
	ctx.r7.s64 = ctx.r31.s64 + 8712;
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
	// addi r11,r11,7
	ctx.r11.s64 = ctx.r11.s64 + 7;
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
	ctx.lr = 0x880AB660;
	sub_880E32D0(ctx, base);
	// lis r9,-30709
	ctx.r9.s64 = -2012545024;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r5,r9,-25856
	ctx.r5.s64 = ctx.r9.s64 + -25856;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88096c60
	ctx.lr = 0x880AB674;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880AB680"))) PPC_WEAK_FUNC(sub_880AB680);
PPC_FUNC_IMPL(__imp__sub_880AB680) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x880AB688;
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
	ctx.lr = 0x880AB6B0;
	sub_88096BC8(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r7,r31,7656
	ctx.r7.s64 = ctx.r31.s64 + 7656;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
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
	// addi r11,r11,9
	ctx.r11.s64 = ctx.r11.s64 + 9;
	// li r4,94
	ctx.r4.s64 = 94;
	// stw r11,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r11.u32);
	// li r3,5
	ctx.r3.s64 = 5;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// stw r10,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r10.u32);
	// stw r9,28(r8)
	PPC_STORE_U32(ctx.r8.u32 + 28, ctx.r9.u32);
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// stw r9,56(r8)
	PPC_STORE_U32(ctx.r8.u32 + 56, ctx.r9.u32);
	// bl 0x880e32d0
	ctx.lr = 0x880AB700;
	sub_880E32D0(ctx, base);
	// lis r8,-30709
	ctx.r8.s64 = -2012545024;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r5,r8,-25104
	ctx.r5.s64 = ctx.r8.s64 + -25104;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88096c60
	ctx.lr = 0x880AB714;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880AB720"))) PPC_WEAK_FUNC(sub_880AB720);
PPC_FUNC_IMPL(__imp__sub_880AB720) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x880AB728;
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
	ctx.lr = 0x880AB74C;
	sub_88096BC8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r31,8360
	ctx.r7.s64 = ctx.r31.s64 + 8360;
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
	// addi r11,r11,10
	ctx.r11.s64 = ctx.r11.s64 + 10;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r11.u32);
	// bl 0x880e32d0
	ctx.lr = 0x880AB790;
	sub_880E32D0(ctx, base);
	// lis r10,-30709
	ctx.r10.s64 = -2012545024;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r5,r10,-24224
	ctx.r5.s64 = ctx.r10.s64 + -24224;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88096c60
	ctx.lr = 0x880AB7A4;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880AB7B0"))) PPC_WEAK_FUNC(sub_880AB7B0);
PPC_FUNC_IMPL(__imp__sub_880AB7B0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x880AB7B8;
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
	ctx.lr = 0x880AB7DC;
	sub_88096BC8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r31,8272
	ctx.r7.s64 = ctx.r31.s64 + 8272;
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
	// addi r11,r11,10
	ctx.r11.s64 = ctx.r11.s64 + 10;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r11.u32);
	// bl 0x880e32d0
	ctx.lr = 0x880AB820;
	sub_880E32D0(ctx, base);
	// lis r10,-30709
	ctx.r10.s64 = -2012545024;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r5,r10,-24224
	ctx.r5.s64 = ctx.r10.s64 + -24224;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88096c60
	ctx.lr = 0x880AB834;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880AB840"))) PPC_WEAK_FUNC(sub_880AB840);
PPC_FUNC_IMPL(__imp__sub_880AB840) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x880AB848;
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
	ctx.lr = 0x880AB870;
	sub_88096BC8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r31,8184
	ctx.r7.s64 = ctx.r31.s64 + 8184;
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
	// addi r11,r11,10
	ctx.r11.s64 = ctx.r11.s64 + 10;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r11.u32);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// stw r10,56(r9)
	PPC_STORE_U32(ctx.r9.u32 + 56, ctx.r10.u32);
	// bl 0x880e32d0
	ctx.lr = 0x880AB8BC;
	sub_880E32D0(ctx, base);
	// lis r9,-30709
	ctx.r9.s64 = -2012545024;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r5,r9,-23496
	ctx.r5.s64 = ctx.r9.s64 + -23496;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88096c60
	ctx.lr = 0x880AB8D0;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880AB8DC"))) PPC_WEAK_FUNC(sub_880AB8DC);
PPC_FUNC_IMPL(__imp__sub_880AB8DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880AB8E0"))) PPC_WEAK_FUNC(sub_880AB8E0);
PPC_FUNC_IMPL(__imp__sub_880AB8E0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x880AB8E8;
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
	ctx.lr = 0x880AB910;
	sub_88096BC8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r31,8096
	ctx.r7.s64 = ctx.r31.s64 + 8096;
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
	// addi r11,r11,10
	ctx.r11.s64 = ctx.r11.s64 + 10;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r11.u32);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// stw r10,56(r9)
	PPC_STORE_U32(ctx.r9.u32 + 56, ctx.r10.u32);
	// bl 0x880e32d0
	ctx.lr = 0x880AB95C;
	sub_880E32D0(ctx, base);
	// lis r9,-30709
	ctx.r9.s64 = -2012545024;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r5,r9,-23496
	ctx.r5.s64 = ctx.r9.s64 + -23496;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88096c60
	ctx.lr = 0x880AB970;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880AB97C"))) PPC_WEAK_FUNC(sub_880AB97C);
PPC_FUNC_IMPL(__imp__sub_880AB97C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880AB980"))) PPC_WEAK_FUNC(sub_880AB980);
PPC_FUNC_IMPL(__imp__sub_880AB980) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x880AB988;
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
	ctx.lr = 0x880AB9B0;
	sub_88096BC8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r31,8536
	ctx.r7.s64 = ctx.r31.s64 + 8536;
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
	// addi r11,r11,10
	ctx.r11.s64 = ctx.r11.s64 + 10;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r11.u32);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// stw r10,56(r9)
	PPC_STORE_U32(ctx.r9.u32 + 56, ctx.r10.u32);
	// bl 0x880e32d0
	ctx.lr = 0x880AB9FC;
	sub_880E32D0(ctx, base);
	// lis r9,-30709
	ctx.r9.s64 = -2012545024;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r5,r9,-22680
	ctx.r5.s64 = ctx.r9.s64 + -22680;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88096c60
	ctx.lr = 0x880ABA10;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880ABA1C"))) PPC_WEAK_FUNC(sub_880ABA1C);
PPC_FUNC_IMPL(__imp__sub_880ABA1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880ABA20"))) PPC_WEAK_FUNC(sub_880ABA20);
PPC_FUNC_IMPL(__imp__sub_880ABA20) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x880ABA28;
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
	ctx.lr = 0x880ABA50;
	sub_88096BC8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r31,8448
	ctx.r7.s64 = ctx.r31.s64 + 8448;
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
	// addi r11,r11,10
	ctx.r11.s64 = ctx.r11.s64 + 10;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r11.u32);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// stw r10,56(r9)
	PPC_STORE_U32(ctx.r9.u32 + 56, ctx.r10.u32);
	// bl 0x880e32d0
	ctx.lr = 0x880ABA9C;
	sub_880E32D0(ctx, base);
	// lis r9,-30709
	ctx.r9.s64 = -2012545024;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r5,r9,-22680
	ctx.r5.s64 = ctx.r9.s64 + -22680;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88096c60
	ctx.lr = 0x880ABAB0;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880ABABC"))) PPC_WEAK_FUNC(sub_880ABABC);
PPC_FUNC_IMPL(__imp__sub_880ABABC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880ABAC0"))) PPC_WEAK_FUNC(sub_880ABAC0);
PPC_FUNC_IMPL(__imp__sub_880ABAC0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x880ABAC8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880ABAE8;
	sub_88096BC8(ctx, base);
	// lwz r11,6708(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 6708);
	// addi r31,r29,6664
	ctx.r31.s64 = ctx.r29.s64 + 6664;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x880abb14
	if (ctx.cr6.eq) goto loc_880ABB14;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x88096b40
	ctx.lr = 0x880ABB08;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_880ABB14:
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// bgt 0x880abc18
	if (ctx.cr0.gt) goto loc_880ABC18;
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// stw r11,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r11,128
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 128, ctx.xer);
	// bgt cr6,0x880abb40
	if (ctx.cr6.gt) goto loc_880ABB40;
	// addi r11,r11,3
	ctx.r11.s64 = ctx.r11.s64 + 3;
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
loc_880ABB40:
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880abbb8
	if (!ctx.cr6.eq) goto loc_880ABBB8;
	// lwz r11,8712(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8712);
	// cmpwi cr6,r11,11
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 11, ctx.xer);
	// bge cr6,0x880abb90
	if (!ctx.cr6.lt) goto loc_880ABB90;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,8712(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8712, ctx.r11.u32);
	// cmpwi cr6,r11,11
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 11, ctx.xer);
	// blt cr6,0x880abb90
	if (ctx.cr6.lt) goto loc_880ABB90;
	// li r11,11
	ctx.r11.s64 = 11;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// lis r10,-30709
	ctx.r10.s64 = -2012545024;
	// stw r11,8712(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8712, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-19344
	ctx.r4.s64 = ctx.r10.s64 + -19344;
	// bl 0x88096cb8
	ctx.lr = 0x880ABB90;
	sub_88096CB8(ctx, base);
loc_880ABB90:
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r11,120
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 120, ctx.xer);
	// blt cr6,0x880abbe4
	if (ctx.cr6.lt) goto loc_880ABBE4;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,16
	ctx.r10.s64 = 16;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r11,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r11.u32);
	// stw r10,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r10.u32);
	// stw r9,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r9.u32);
	// b 0x880abbe4
	goto loc_880ABBE4;
loc_880ABBB8:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x880abbe4
	if (!ctx.cr6.eq) goto loc_880ABBE4;
	// li r11,3
	ctx.r11.s64 = 3;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// lis r10,-30709
	ctx.r10.s64 = -2012545024;
	// stw r11,8780(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8780, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-20096
	ctx.r4.s64 = ctx.r10.s64 + -20096;
	// bl 0x88096cb8
	ctx.lr = 0x880ABBDC;
	sub_88096CB8(ctx, base);
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r9,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r9.u32);
loc_880ABBE4:
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r11,192
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 192, ctx.xer);
	// blt cr6,0x880abc18
	if (ctx.cr6.lt) goto loc_880ABC18;
	// li r11,192
	ctx.r11.s64 = 192;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// stw r10,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r10.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x88096b40
	ctx.lr = 0x880ABC0C;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_880ABC18:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880ABC24"))) PPC_WEAK_FUNC(sub_880ABC24);
PPC_FUNC_IMPL(__imp__sub_880ABC24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880ABC28"))) PPC_WEAK_FUNC(sub_880ABC28);
PPC_FUNC_IMPL(__imp__sub_880ABC28) {
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
	ctx.lr = 0x880ABC54;
	sub_88096BC8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r9,24
	ctx.r9.s64 = 24;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// lis r7,-30709
	ctx.r7.s64 = -2012545024;
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r11,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r11.u32);
	// addi r5,r7,-21160
	ctx.r5.s64 = ctx.r7.s64 + -21160;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096c60
	ctx.lr = 0x880ABC88;
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

__attribute__((alias("__imp__sub_880ABCA4"))) PPC_WEAK_FUNC(sub_880ABCA4);
PPC_FUNC_IMPL(__imp__sub_880ABCA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880ABCA8"))) PPC_WEAK_FUNC(sub_880ABCA8);
PPC_FUNC_IMPL(__imp__sub_880ABCA8) {
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
	ctx.lr = 0x880ABCD4;
	sub_88096BC8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,-1
	ctx.r8.s64 = -1;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// lis r7,-30709
	ctx.r7.s64 = -2012545024;
	// stw r9,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r9.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r8,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r8.u32);
	// addi r5,r7,-21160
	ctx.r5.s64 = ctx.r7.s64 + -21160;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096c60
	ctx.lr = 0x880ABD08;
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

__attribute__((alias("__imp__sub_880ABD24"))) PPC_WEAK_FUNC(sub_880ABD24);
PPC_FUNC_IMPL(__imp__sub_880ABD24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880ABD28"))) PPC_WEAK_FUNC(sub_880ABD28);
PPC_FUNC_IMPL(__imp__sub_880ABD28) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x880ABD30;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
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
	// bl 0x88096bc8
	ctx.lr = 0x880ABD50;
	sub_88096BC8(ctx, base);
	// lwz r5,16(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r4,12(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r5,-1
	ctx.cr6.compare<int32_t>(ctx.r5.s32, -1, ctx.xer);
	// bne cr6,0x880abd7c
	if (!ctx.cr6.eq) goto loc_880ABD7C;
loc_880ABD64:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88096b40
	ctx.lr = 0x880ABD70;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_880ABD7C:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x880abd98
	if (ctx.cr6.lt) goto loc_880ABD98;
	// beq cr6,0x880abda8
	if (ctx.cr6.eq) goto loc_880ABDA8;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_880ABD98:
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
loc_880ABDA8:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bge 0x880abe24
	if (!ctx.cr0.lt) goto loc_880ABE24;
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880abdf4
	if (ctx.cr6.eq) goto loc_880ABDF4;
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// mulli r10,r5,196
	ctx.r10.s64 = ctx.r5.s64 * 196;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r3,r11,1448
	ctx.r3.s64 = ctx.r11.s64 + 1448;
	// bl 0x881344b8
	ctx.lr = 0x880ABDD8;
	sub_881344B8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x880abd64
	if (ctx.cr6.eq) goto loc_880ABD64;
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x880ABDF0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x880abe00
	goto loc_880ABE00;
loc_880ABDF4:
	// lwz r11,4(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x880ABE00;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_880ABE00:
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r10,r11,12
	ctx.r10.s64 = ctx.r11.s64 + 12;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r10,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r10.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// ble 0x880abd64
	if (!ctx.cr0.gt) goto loc_880ABD64;
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
loc_880ABE24:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880ABE30"))) PPC_WEAK_FUNC(sub_880ABE30);
PPC_FUNC_IMPL(__imp__sub_880ABE30) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880ABE38;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,26432
	ctx.r9.s64 = ctx.r11.s64 + 26432;
	// li r8,-1
	ctx.r8.s64 = -1;
	// stw r10,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r8,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r8.u32);
	// lwz r11,324(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 324);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x880abea0
	if (!ctx.cr6.eq) goto loc_880ABEA0;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,1456
	ctx.r11.s64 = ctx.r11.s64 + 1456;
loc_880ABE6C:
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stw r8,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r8.u32);
	// beq cr6,0x880abe94
	if (ctx.cr6.eq) goto loc_880ABE94;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,196
	ctx.r11.s64 = ctx.r11.s64 + 196;
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// blt cr6,0x880abe6c
	if (ctx.cr6.lt) goto loc_880ABE6C;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_880ABE94:
	// stw r10,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r10.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_880ABEA0:
	// mr r29,r10
	ctx.r29.u64 = ctx.r10.u64;
	// mr r31,r10
	ctx.r31.u64 = ctx.r10.u64;
loc_880ABEA8:
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// add r6,r31,r11
	ctx.r6.u64 = ctx.r31.u64 + ctx.r11.u64;
	// lbz r11,1448(r6)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r6.u32 + 1448);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880abef0
	if (ctx.cr6.eq) goto loc_880ABEF0;
	// lbz r11,1449(r6)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r6.u32 + 1449);
	// lwz r10,1576(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 1576);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addi r9,r11,13
	ctx.r9.s64 = ctx.r11.s64 + 13;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r8,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// bl 0x88152b00
	ctx.lr = 0x880ABEDC;
	sub_88152B00(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x880abef0
	if (ctx.cr6.eq) goto loc_880ABEF0;
	// lwz r11,1584(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 1584);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880abf08
	if (ctx.cr6.eq) goto loc_880ABF08;
loc_880ABEF0:
	// addi r31,r31,196
	ctx.r31.s64 = ctx.r31.s64 + 196;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmpwi cr6,r31,392
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 392, ctx.xer);
	// blt cr6,0x880abea8
	if (ctx.cr6.lt) goto loc_880ABEA8;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_880ABF08:
	// lbz r11,1456(r6)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r6.u32 + 1456);
	// stw r29,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r29.u32);
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880ABF1C"))) PPC_WEAK_FUNC(sub_880ABF1C);
PPC_FUNC_IMPL(__imp__sub_880ABF1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880ABF20"))) PPC_WEAK_FUNC(sub_880ABF20);
PPC_FUNC_IMPL(__imp__sub_880ABF20) {
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
	ctx.lr = 0x880ABF4C;
	sub_88096BC8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r9,-30709
	ctx.r9.s64 = -2012545024;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r9,-19264
	ctx.r5.s64 = ctx.r9.s64 + -19264;
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096c60
	ctx.lr = 0x880ABF70;
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

__attribute__((alias("__imp__sub_880ABF8C"))) PPC_WEAK_FUNC(sub_880ABF8C);
PPC_FUNC_IMPL(__imp__sub_880ABF8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880ABF90"))) PPC_WEAK_FUNC(sub_880ABF90);
PPC_FUNC_IMPL(__imp__sub_880ABF90) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880ABF98;
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
	ctx.lr = 0x880ABFB8;
	sub_88096BC8(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,16
	ctx.r9.s64 = 16;
	// stw r11,6708(r29)
	PPC_STORE_U32(ctx.r29.u32 + 6708, ctx.r11.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// lis r8,-30709
	ctx.r8.s64 = -2012545024;
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// addi r5,r8,-17728
	ctx.r5.s64 = ctx.r8.s64 + -17728;
	// stw r11,8780(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8780, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,8712(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8712, ctx.r10.u32);
	// bl 0x88096c60
	ctx.lr = 0x880ABFF0;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880ABFFC"))) PPC_WEAK_FUNC(sub_880ABFFC);
PPC_FUNC_IMPL(__imp__sub_880ABFFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880AC000"))) PPC_WEAK_FUNC(sub_880AC000);
PPC_FUNC_IMPL(__imp__sub_880AC000) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x880AC008;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,20
	ctx.r5.s64 = 20;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880AC028;
	sub_88096BC8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bl 0x880abe30
	ctx.lr = 0x880AC054;
	sub_880ABE30(ctx, base);
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880ac068
	if (ctx.cr6.eq) goto loc_880AC068;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x880ac084
	if (!ctx.cr6.eq) goto loc_880AC084;
loc_880AC068:
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r10,-30682
	ctx.r10.s64 = -2010775552;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r8,r10,-25644
	ctx.r8.s64 = ctx.r10.s64 + -25644;
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// stw r8,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r8.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
loc_880AC084:
	// lis r11,-30709
	ctx.r11.s64 = -2012545024;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r5,r11,-17112
	ctx.r5.s64 = ctx.r11.s64 + -17112;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096c60
	ctx.lr = 0x880AC098;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880AC0A4"))) PPC_WEAK_FUNC(sub_880AC0A4);
PPC_FUNC_IMPL(__imp__sub_880AC0A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880AC0A8"))) PPC_WEAK_FUNC(sub_880AC0A8);
PPC_FUNC_IMPL(__imp__sub_880AC0A8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x880AC0B0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,20
	ctx.r5.s64 = 20;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880AC0D0;
	sub_88096BC8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bl 0x880abe30
	ctx.lr = 0x880AC0FC;
	sub_880ABE30(ctx, base);
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880ac120
	if (!ctx.cr6.eq) goto loc_880AC120;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r11,-30682
	ctx.r11.s64 = -2010775552;
	// addi r11,r11,-27004
	ctx.r11.s64 = ctx.r11.s64 + -27004;
	// addi r8,r11,-760
	ctx.r8.s64 = ctx.r11.s64 + -760;
	// stw r10,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r10.u32);
	// b 0x880ac138
	goto loc_880AC138;
loc_880AC120:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x880ac144
	if (!ctx.cr6.eq) goto loc_880AC144;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r10,-30682
	ctx.r10.s64 = -2010775552;
	// addi r8,r10,-27004
	ctx.r8.s64 = ctx.r10.s64 + -27004;
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
loc_880AC138:
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r8,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r8.u32);
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
loc_880AC144:
	// lis r11,-30709
	ctx.r11.s64 = -2012545024;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r5,r11,-17112
	ctx.r5.s64 = ctx.r11.s64 + -17112;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096c60
	ctx.lr = 0x880AC158;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880AC164"))) PPC_WEAK_FUNC(sub_880AC164);
PPC_FUNC_IMPL(__imp__sub_880AC164) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880AC168"))) PPC_WEAK_FUNC(sub_880AC168);
PPC_FUNC_IMPL(__imp__sub_880AC168) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x880AC170;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lwz r27,2304(r3)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r5,20
	ctx.r5.s64 = 20;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880AC190;
	sub_88096BC8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stw r30,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// bl 0x880abe30
	ctx.lr = 0x880AC1BC;
	sub_880ABE30(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880ac1d8
	if (!ctx.cr6.eq) goto loc_880AC1D8;
	// lis r11,-30682
	ctx.r11.s64 = -2010775552;
	// addi r11,r11,-29076
	ctx.r11.s64 = ctx.r11.s64 + -29076;
	// addi r9,r11,-704
	ctx.r9.s64 = ctx.r11.s64 + -704;
	// b 0x880ac1e8
	goto loc_880AC1E8;
loc_880AC1D8:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x880ac1f8
	if (!ctx.cr6.eq) goto loc_880AC1F8;
	// lis r11,-30682
	ctx.r11.s64 = -2010775552;
	// addi r9,r11,-29076
	ctx.r9.s64 = ctx.r11.s64 + -29076;
loc_880AC1E8:
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r9,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r9.u32);
	// stw r30,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
loc_880AC1F8:
	// lis r11,-30709
	ctx.r11.s64 = -2012545024;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r5,r11,-17112
	ctx.r5.s64 = ctx.r11.s64 + -17112;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88096c60
	ctx.lr = 0x880AC20C;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880AC218"))) PPC_WEAK_FUNC(sub_880AC218);
PPC_FUNC_IMPL(__imp__sub_880AC218) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x880AC220;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,20
	ctx.r5.s64 = 20;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880AC240;
	sub_88096BC8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bl 0x880abe30
	ctx.lr = 0x880AC26C;
	sub_880ABE30(ctx, base);
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880ac290
	if (!ctx.cr6.eq) goto loc_880AC290;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r11,-30682
	ctx.r11.s64 = -2010775552;
	// addi r11,r11,-30540
	ctx.r11.s64 = ctx.r11.s64 + -30540;
	// addi r8,r11,-5208
	ctx.r8.s64 = ctx.r11.s64 + -5208;
	// stw r10,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r10.u32);
	// b 0x880ac2a8
	goto loc_880AC2A8;
loc_880AC290:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x880ac2b4
	if (!ctx.cr6.eq) goto loc_880AC2B4;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r10,-30682
	ctx.r10.s64 = -2010775552;
	// addi r8,r10,-30540
	ctx.r8.s64 = ctx.r10.s64 + -30540;
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
loc_880AC2A8:
	// li r9,3
	ctx.r9.s64 = 3;
	// stw r8,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r8.u32);
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
loc_880AC2B4:
	// lis r11,-30709
	ctx.r11.s64 = -2012545024;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r5,r11,-17112
	ctx.r5.s64 = ctx.r11.s64 + -17112;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88096c60
	ctx.lr = 0x880AC2C8;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880AC2D4"))) PPC_WEAK_FUNC(sub_880AC2D4);
PPC_FUNC_IMPL(__imp__sub_880AC2D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880AC2D8"))) PPC_WEAK_FUNC(sub_880AC2D8);
PPC_FUNC_IMPL(__imp__sub_880AC2D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807112c
	ctx.lr = 0x880AC2E0;
	__savegprlr_17(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r18,r4
	ctx.r18.u64 = ctx.r4.u64;
	// lwz r20,2304(r3)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r17,r5
	ctx.r17.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880AC300;
	sub_88096BC8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r23,8(r3)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r19,0
	ctx.r19.s64 = 0;
	// li r21,2
	ctx.r21.s64 = 2;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x880ac32c
	if (ctx.cr6.lt) goto loc_880AC32C;
	// beq cr6,0x880ac36c
	if (ctx.cr6.eq) goto loc_880AC36C;
loc_880AC320:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8807117c
	__restgprlr_17(ctx, base);
	return;
loc_880AC32C:
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,64(r10)
	PPC_STORE_U32(ctx.r10.u32 + 64, ctx.r11.u32);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,72(r9)
	PPC_STORE_U32(ctx.r9.u32 + 72, ctx.r11.u32);
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,68(r8)
	PPC_STORE_U32(ctx.r8.u32 + 68, ctx.r11.u32);
	// stw r11,8872(r20)
	PPC_STORE_U32(ctx.r20.u32 + 8872, ctx.r11.u32);
	// stw r11,8960(r20)
	PPC_STORE_U32(ctx.r20.u32 + 8960, ctx.r11.u32);
	// stw r11,7816(r20)
	PPC_STORE_U32(ctx.r20.u32 + 7816, ctx.r11.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r19,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r19.u32);
	// stw r21,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r21.u32);
	// stw r19,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r19.u32);
	// stw r7,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
loc_880AC36C:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// bge 0x880ac320
	if (!ctx.cr0.lt) goto loc_880AC320;
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lis r9,-30682
	ctx.r9.s64 = -2010775552;
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lis r26,-30667
	ctx.r26.s64 = -2009792512;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r9,r9,-15608
	ctx.r9.s64 = ctx.r9.s64 + -15608;
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lis r25,-30667
	ctx.r25.s64 = -2009792512;
	// rlwinm r11,r6,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r8.u32);
	// lwz r8,12(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// add r30,r11,r9
	ctx.r30.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r7,16(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// lis r22,-30667
	ctx.r22.s64 = -2009792512;
	// lwz r5,12(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// srawi r10,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 2;
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r11.s64 = temp.s64;
	// srawi r9,r5,2
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r5.s32 >> 2;
	// add r28,r11,r8
	ctx.r28.u64 = ctx.r11.u64 + ctx.r8.u64;
	// addze r11,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r11.s64 = temp.s64;
	// stw r28,12364(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12364, ctx.r28.u32);
	// add r8,r11,r7
	ctx.r8.u64 = ctx.r11.u64 + ctx.r7.u64;
	// addis r27,r8,64
	ctx.r27.s64 = ctx.r8.s64 + 4194304;
	// stw r27,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r27.u32);
	// bl 0x880f52c8
	ctx.lr = 0x880AC3F0;
	sub_880F52C8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x881534c8
	ctx.lr = 0x880AC3FC;
	sub_881534C8(ctx, base);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// extsh r7,r3
	ctx.r7.s64 = ctx.r3.s16;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// li r3,16
	ctx.r3.s64 = 16;
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r5,r6,5,0,26
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFFE0;
	// subf r11,r5,r7
	ctx.r11.s64 = ctx.r7.s64 - ctx.r5.s64;
	// addi r24,r11,248
	ctx.r24.s64 = ctx.r11.s64 + 248;
	// bl 0x881534c8
	ctx.lr = 0x880AC420;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r4,r11,72
	ctx.r4.s64 = ctx.r11.s64 + 72;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// bl 0x880f5570
	ctx.lr = 0x880AC434;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x880ac448
	if (ctx.cr6.eq) goto loc_880AC448;
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// clrlwi r10,r11,16
	ctx.r10.u64 = ctx.r11.u32 & 0xFFFF;
	// stw r10,100(r29)
	PPC_STORE_U32(ctx.r29.u32 + 100, ctx.r10.u32);
loc_880AC448:
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r20
	ctx.r11.u64 = ctx.r11.u64 + ctx.r20.u64;
	// lwz r9,9988(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 9988);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x880ac498
	if (!ctx.cr6.eq) goto loc_880AC498;
	// addi r10,r10,500
	ctx.r10.s64 = ctx.r10.s64 + 500;
	// lwz r8,10004(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 10004);
	// lwz r6,9996(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 9996);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r5,9992(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 9992);
	// lwz r7,0(r20)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// add r11,r10,r9
	ctx.r11.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r4,12(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lwzx r7,r10,r20
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r20.u32);
	// bl 0x880f5438
	ctx.lr = 0x880AC498;
	sub_880F5438(ctx, base);
loc_880AC498:
	// stw r28,12364(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12364, ctx.r28.u32);
	// addi r29,r23,1
	ctx.r29.s64 = ctx.r23.s64 + 1;
	// stw r27,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r27.u32);
	// lis r23,-30667
	ctx.r23.s64 = -2009792512;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// bl 0x880f52c8
	ctx.lr = 0x880AC4B8;
	sub_880F52C8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880ac4c8
	if (ctx.cr6.eq) goto loc_880AC4C8;
	// stw r21,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r21.u32);
loc_880AC4C8:
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x881534c8
	ctx.lr = 0x880AC4D0;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,32
	ctx.r3.s64 = 32;
	// addi r11,r11,72
	ctx.r11.s64 = ctx.r11.s64 + 72;
	// rlwinm r21,r11,1,0,30
	ctx.r21.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// bl 0x881534c8
	ctx.lr = 0x880AC4E4;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
	// add r11,r11,r24
	ctx.r11.u64 = ctx.r11.u64 + ctx.r24.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r5,r11,-16
	ctx.r5.s64 = ctx.r11.s64 + -16;
	// bl 0x880f5570
	ctx.lr = 0x880AC4FC;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x880ac514
	if (ctx.cr6.eq) goto loc_880AC514;
	// li r11,112
	ctx.r11.s64 = 112;
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r11,140(r30)
	PPC_STORE_U32(ctx.r30.u32 + 140, ctx.r11.u32);
	// stw r10,100(r30)
	PPC_STORE_U32(ctx.r30.u32 + 100, ctx.r10.u32);
loc_880AC514:
	// stw r28,12364(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12364, ctx.r28.u32);
	// li r11,24
	ctx.r11.s64 = 24;
	// stw r27,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r27.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,12380(r22)
	PPC_STORE_U32(ctx.r22.u32 + 12380, ctx.r11.u32);
	// bl 0x880f34b0
	ctx.lr = 0x880AC530;
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
	// beq cr6,0x880ac584
	if (ctx.cr6.eq) goto loc_880AC584;
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
	// add r11,r11,r24
	ctx.r11.u64 = ctx.r11.u64 + ctx.r24.u64;
	// addi r4,r11,-32
	ctx.r4.s64 = ctx.r11.s64 + -32;
	// sth r4,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, ctx.r4.u16);
loc_880AC584:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x880f34b0
	ctx.lr = 0x880AC590;
	sub_880F34B0(ctx, base);
	// mullw r11,r26,r28
	ctx.r11.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r28.s32);
	// addi r26,r11,12345
	ctx.r26.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r26,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r26.u32);
	// beq cr6,0x880ac5cc
	if (ctx.cr6.eq) goto loc_880AC5CC;
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
	// add r11,r11,r24
	ctx.r11.u64 = ctx.r11.u64 + ctx.r24.u64;
	// addi r4,r11,-32
	ctx.r4.s64 = ctx.r11.s64 + -32;
	// sth r4,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, ctx.r4.u16);
loc_880AC5CC:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r29,12376(r23)
	PPC_STORE_U32(ctx.r23.u32 + 12376, ctx.r29.u32);
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x880f34b0
	ctx.lr = 0x880AC5DC;
	sub_880F34B0(ctx, base);
	// mullw r11,r26,r28
	ctx.r11.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r28.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r11,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r11.u32);
	// beq cr6,0x880ac618
	if (ctx.cr6.eq) goto loc_880AC618;
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
	// add r11,r11,r24
	ctx.r11.u64 = ctx.r11.u64 + ctx.r24.u64;
	// addi r4,r11,-32
	ctx.r4.s64 = ctx.r11.s64 + -32;
	// sth r4,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, ctx.r4.u16);
loc_880AC618:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// cmplwi cr6,r11,12
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 12, ctx.xer);
	// blt cr6,0x880ac320
	if (ctx.cr6.lt) goto loc_880AC320;
	// stw r19,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r19.u32);
	// lis r11,-30709
	ctx.r11.s64 = -2012545024;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-16496
	ctx.r4.s64 = ctx.r11.s64 + -16496;
	// lwz r3,24(r20)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r20.u32 + 24);
	// bl 0x88096cb8
	ctx.lr = 0x880AC644;
	sub_88096CB8(ctx, base);
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// bl 0x88096b40
	ctx.lr = 0x880AC650;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8807117c
	__restgprlr_17(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880AC65C"))) PPC_WEAK_FUNC(sub_880AC65C);
PPC_FUNC_IMPL(__imp__sub_880AC65C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880AC660"))) PPC_WEAK_FUNC(sub_880AC660);
PPC_FUNC_IMPL(__imp__sub_880AC660) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807112c
	ctx.lr = 0x880AC668;
	__savegprlr_17(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r19,r4
	ctx.r19.u64 = ctx.r4.u64;
	// lwz r27,2304(r3)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r18,r5
	ctx.r18.u64 = ctx.r5.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880AC68C;
	sub_88096BC8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x880aca10
	if (ctx.cr6.lt) goto loc_880ACA10;
	// beq cr6,0x880aca60
	if (ctx.cr6.eq) goto loc_880ACA60;
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// bne cr6,0x880acc00
	if (!ctx.cr6.eq) goto loc_880ACC00;
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// lwz r9,24(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r20,r11,9552
	ctx.r20.s64 = ctx.r11.s64 + 9552;
	// rlwinm r8,r10,2,21,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0x7FC;
	// srawi r7,r9,12
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xFFF) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 12;
	// cmpwi cr6,r10,80
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 80, ctx.xer);
	// addze r6,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r6.s64 = temp.s64;
	// lwzx r5,r8,r20
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r20.u32);
	// mullw r11,r5,r6
	ctx.r11.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r6.s32);
	// blt cr6,0x880ac6dc
	if (ctx.cr6.lt) goto loc_880AC6DC;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,7636(r27)
	PPC_STORE_U32(ctx.r27.u32 + 7636, ctx.r10.u32);
loc_880AC6DC:
	// lis r8,-30643
	ctx.r8.s64 = -2008219648;
	// lwz r7,24(r22)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r22.u32 + 24);
	// lwz r10,16(r22)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r22.u32 + 16);
	// lis r23,16
	ctx.r23.s64 = 1048576;
	// subf r9,r11,r7
	ctx.r9.s64 = ctx.r7.s64 - ctx.r11.s64;
	// lis r21,-30667
	ctx.r21.s64 = -2009792512;
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r11,26428(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 26428);
	// lis r28,-30667
	ctx.r28.s64 = -2009792512;
	// lis r26,-30667
	ctx.r26.s64 = -2009792512;
	// stw r6,304(r27)
	PPC_STORE_U32(ctx.r27.u32 + 304, ctx.r6.u32);
	// clrlwi r5,r11,31
	ctx.r5.u64 = ctx.r11.u32 & 0x1;
	// lis r25,-30667
	ctx.r25.s64 = -2009792512;
	// lis r24,-30667
	ctx.r24.s64 = -2009792512;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bne cr6,0x880ac804
	if (!ctx.cr6.eq) goto loc_880AC804;
	// lwz r11,28(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 28);
	// cmpwi cr6,r11,80
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 80, ctx.xer);
	// blt cr6,0x880ac804
	if (ctx.cr6.lt) goto loc_880AC804;
	// lwz r10,16(r22)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r22.u32 + 16);
	// li r11,2
	ctx.r11.s64 = 2;
	// lwz r9,12(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// li r30,2
	ctx.r30.s64 = 2;
	// lwz r7,12(r22)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r22.u32 + 12);
	// lwz r8,8(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 8);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r31,2944(r27)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r27.u32 + 2944);
	// stw r11,12380(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12380, ctx.r11.u32);
	// add r10,r7,r8
	ctx.r10.u64 = ctx.r7.u64 + ctx.r8.u64;
	// subf r11,r23,r9
	ctx.r11.s64 = ctx.r9.s64 - ctx.r23.s64;
	// stw r10,12364(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12364, ctx.r10.u32);
	// stw r11,12372(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12372, ctx.r11.u32);
	// stw r31,12376(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12376, ctx.r31.u32);
loc_880AC760:
	// li r3,15
	ctx.r3.s64 = 15;
	// bl 0x881534c8
	ctx.lr = 0x880AC768;
	sub_881534C8(ctx, base);
	// extsh r5,r3
	ctx.r5.s64 = ctx.r3.s16;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x880f25b8
	ctx.lr = 0x880AC778;
	sub_880F25B8(ctx, base);
	// mr r17,r3
	ctx.r17.u64 = ctx.r3.u64;
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x881534c8
	ctx.lr = 0x880AC784;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,31
	ctx.r3.s64 = 31;
	// addi r29,r11,4
	ctx.r29.s64 = ctx.r11.s64 + 4;
	// bl 0x881534c8
	ctx.lr = 0x880AC794;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// subfic r10,r11,136
	ctx.xer.ca = ctx.r11.u32 <= 136;
	ctx.r10.s64 = 136 - ctx.r11.s64;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// clrlwi r5,r10,23
	ctx.r5.u64 = ctx.r10.u32 & 0x1FF;
	// bl 0x880f26e0
	ctx.lr = 0x880AC7AC;
	sub_880F26E0(ctx, base);
	// li r3,15
	ctx.r3.s64 = 15;
	// bl 0x881534c8
	ctx.lr = 0x880AC7B4;
	sub_881534C8(ctx, base);
	// extsh r5,r3
	ctx.r5.s64 = ctx.r3.s16;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,2
	ctx.r3.s64 = 2;
	// stw r5,12384(r21)
	PPC_STORE_U32(ctx.r21.u32 + 12384, ctx.r5.u32);
	// bl 0x880f25b8
	ctx.lr = 0x880AC7C8;
	sub_880F25B8(ctx, base);
	// mr r17,r3
	ctx.r17.u64 = ctx.r3.u64;
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x881534c8
	ctx.lr = 0x880AC7D4;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,31
	ctx.r3.s64 = 31;
	// addi r29,r11,4
	ctx.r29.s64 = ctx.r11.s64 + 4;
	// bl 0x881534c8
	ctx.lr = 0x880AC7E4;
	sub_881534C8(ctx, base);
	// extsh r9,r3
	ctx.r9.s64 = ctx.r3.s16;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// subfic r8,r9,-104
	ctx.xer.ca = ctx.r9.u32 <= 4294967192;
	ctx.r8.s64 = -104 - ctx.r9.s64;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// clrlwi r5,r8,23
	ctx.r5.u64 = ctx.r8.u32 & 0x1FF;
	// bl 0x880f26e0
	ctx.lr = 0x880AC7FC;
	sub_880F26E0(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x880ac760
	if (!ctx.cr0.eq) goto loc_880AC760;
loc_880AC804:
	// lwz r11,28(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 28);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// stw r11,28(r22)
	PPC_STORE_U32(ctx.r22.u32 + 28, ctx.r11.u32);
	// cmpwi cr6,r11,128
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 128, ctx.xer);
	// blt cr6,0x880acc00
	if (ctx.cr6.lt) goto loc_880ACC00;
	// lwz r10,16(r22)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r22.u32 + 16);
	// li r11,2
	ctx.r11.s64 = 2;
	// lwz r9,12(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// lis r30,-30671
	ctx.r30.s64 = -2010054656;
	// lwz r8,8(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 8);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r10,12(r22)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r22.u32 + 12);
	// lwz r4,2944(r27)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r27.u32 + 2944);
	// stw r11,12380(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12380, ctx.r11.u32);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// subf r11,r23,r9
	ctx.r11.s64 = ctx.r9.s64 - ctx.r23.s64;
	// stw r10,12364(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12364, ctx.r10.u32);
	// lis r10,-3856
	ctx.r10.s64 = -252706816;
	// stw r11,12372(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12372, ctx.r11.u32);
	// lis r11,16838
	ctx.r11.s64 = 1103495168;
	// stw r4,12376(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12376, ctx.r4.u32);
	// ori r28,r10,61681
	ctx.r28.u64 = ctx.r10.u64 | 61681;
	// lwz r10,4200(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4200);
	// li r24,8
	ctx.r24.s64 = 8;
	// ori r31,r11,20077
	ctx.r31.u64 = ctx.r11.u64 | 20077;
loc_880AC868:
	// mullw r11,r10,r31
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r31.s32);
	// addi r29,r11,12345
	ctx.r29.s64 = ctx.r11.s64 + 12345;
	// li r3,2
	ctx.r3.s64 = 2;
	// stw r29,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r29.u32);
	// lhz r11,4200(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4200);
	// clrlwi r5,r11,28
	ctx.r5.u64 = ctx.r11.u32 & 0xF;
	// bl 0x880f25b8
	ctx.lr = 0x880AC884;
	sub_880F25B8(ctx, base);
	// mullw r11,r29,r31
	ctx.r11.s64 = int64_t(ctx.r29.s32) * int64_t(ctx.r31.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r11,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r11.u32);
	// mullw r11,r11,r31
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r31.s32);
	// lhz r8,4200(r30)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4200);
	// addi r10,r11,12345
	ctx.r10.s64 = ctx.r11.s64 + 12345;
	// mulhwu r7,r8,r28
	ctx.r7.u64 = (uint64_t(ctx.r8.u32) * uint64_t(ctx.r28.u32)) >> 32;
	// rlwinm r11,r7,28,4,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 28) & 0xFFFFFFF;
	// stw r10,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r10.u32);
	// lhz r9,4200(r30)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4200);
	// clrlwi r6,r9,26
	ctx.r6.u64 = ctx.r9.u32 & 0x3F;
	// rlwinm r9,r11,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// subfic r5,r6,152
	ctx.xer.ca = ctx.r6.u32 <= 152;
	ctx.r5.s64 = 152 - ctx.r6.s64;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// clrlwi r9,r5,23
	ctx.r9.u64 = ctx.r5.u32 & 0x1FF;
	// subf r8,r11,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r11.s64;
	// extsh r11,r8
	ctx.r11.s64 = ctx.r8.s16;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// beq cr6,0x880ac918
	if (ctx.cr6.eq) goto loc_880AC918;
	// stw r9,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r9.u32);
	// addic. r8,r3,28
	ctx.xer.ca = ctx.r3.u32 > 4294967267;
	ctx.r8.s64 = ctx.r3.s64 + 28;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r11.u32);
	// addi r7,r3,24
	ctx.r7.s64 = ctx.r3.s64 + 24;
	// clrlwi r9,r9,23
	ctx.r9.u64 = ctx.r9.u32 & 0x1FF;
	// beq 0x880ac900
	if (ctx.cr0.eq) goto loc_880AC900;
	// addi r6,r9,128
	ctx.r6.s64 = ctx.r9.s64 + 128;
	// rlwinm r5,r6,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// lwzx r3,r5,r20
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r20.u32);
	// mullw r6,r3,r11
	ctx.r6.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r11.s32);
	// stw r6,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r6.u32);
loc_880AC900:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x880ac918
	if (ctx.cr6.eq) goto loc_880AC918;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r20
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r20.u32);
	// mullw r6,r8,r11
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r11.s32);
	// stw r6,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r6.u32);
loc_880AC918:
	// mullw r11,r10,r31
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r31.s32);
	// addi r29,r11,12345
	ctx.r29.s64 = ctx.r11.s64 + 12345;
	// li r3,2
	ctx.r3.s64 = 2;
	// stw r29,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r29.u32);
	// lhz r11,4200(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4200);
	// clrlwi r5,r11,28
	ctx.r5.u64 = ctx.r11.u32 & 0xF;
	// stw r5,12384(r21)
	PPC_STORE_U32(ctx.r21.u32 + 12384, ctx.r5.u32);
	// bl 0x880f25b8
	ctx.lr = 0x880AC938;
	sub_880F25B8(ctx, base);
	// mullw r11,r29,r31
	ctx.r11.s64 = int64_t(ctx.r29.s32) * int64_t(ctx.r31.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r11,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r11.u32);
	// mullw r10,r11,r31
	ctx.r10.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r31.s32);
	// lhz r8,4200(r30)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4200);
	// mulhwu r7,r8,r28
	ctx.r7.u64 = (uint64_t(ctx.r8.u32) * uint64_t(ctx.r28.u32)) >> 32;
	// rlwinm r11,r7,28,4,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 28) & 0xFFFFFFF;
	// addi r10,r10,12345
	ctx.r10.s64 = ctx.r10.s64 + 12345;
	// rlwinm r9,r11,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r10,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r10.u32);
	// add r6,r9,r11
	ctx.r6.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lhz r11,4200(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4200);
	// clrlwi r5,r11,26
	ctx.r5.u64 = ctx.r11.u32 & 0x3F;
	// subf r11,r6,r8
	ctx.r11.s64 = ctx.r8.s64 - ctx.r6.s64;
	// subfic r9,r5,-88
	ctx.xer.ca = ctx.r5.u32 <= 4294967208;
	ctx.r9.s64 = -88 - ctx.r5.s64;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// clrlwi r9,r9,23
	ctx.r9.u64 = ctx.r9.u32 & 0x1FF;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// beq cr6,0x880ac9cc
	if (ctx.cr6.eq) goto loc_880AC9CC;
	// stw r9,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r9.u32);
	// addic. r8,r3,28
	ctx.xer.ca = ctx.r3.u32 > 4294967267;
	ctx.r8.s64 = ctx.r3.s64 + 28;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r11.u32);
	// addi r7,r3,24
	ctx.r7.s64 = ctx.r3.s64 + 24;
	// clrlwi r9,r9,23
	ctx.r9.u64 = ctx.r9.u32 & 0x1FF;
	// beq 0x880ac9b4
	if (ctx.cr0.eq) goto loc_880AC9B4;
	// addi r6,r9,128
	ctx.r6.s64 = ctx.r9.s64 + 128;
	// rlwinm r5,r6,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// lwzx r3,r5,r20
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r20.u32);
	// mullw r6,r3,r11
	ctx.r6.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r11.s32);
	// stw r6,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r6.u32);
loc_880AC9B4:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x880ac9cc
	if (ctx.cr6.eq) goto loc_880AC9CC;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r20
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r20.u32);
	// mullw r6,r8,r11
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r11.s32);
	// stw r6,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r6.u32);
loc_880AC9CC:
	// addic. r24,r24,-1
	ctx.xer.ca = ctx.r24.u32 > 0;
	ctx.r24.s64 = ctx.r24.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// bne 0x880ac868
	if (!ctx.cr0.eq) goto loc_880AC868;
	// lwz r11,12(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 12);
	// lis r10,-30709
	ctx.r10.s64 = -2012545024;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-16216
	ctx.r4.s64 = ctx.r10.s64 + -16216;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// stw r11,300(r27)
	PPC_STORE_U32(ctx.r27.u32 + 300, ctx.r11.u32);
	// lwz r9,16(r22)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r22.u32 + 16);
	// stw r9,304(r27)
	PPC_STORE_U32(ctx.r27.u32 + 304, ctx.r9.u32);
	// bl 0x88096cb8
	ctx.lr = 0x880AC9F8;
	sub_88096CB8(ctx, base);
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// bl 0x88096b40
	ctx.lr = 0x880ACA04;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8807117c
	__restgprlr_17(ctx, base);
	return;
loc_880ACA10:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a9878
	ctx.lr = 0x880ACA18;
	sub_880A9878(ctx, base);
	// li r11,2
	ctx.r11.s64 = 2;
	// li r31,1
	ctx.r31.s64 = 1;
	// lis r10,64
	ctx.r10.s64 = 4194304;
	// stw r11,7636(r27)
	PPC_STORE_U32(ctx.r27.u32 + 7636, ctx.r11.u32);
	// lis r9,-36
	ctx.r9.s64 = -2359296;
	// stw r31,7904(r27)
	PPC_STORE_U32(ctx.r27.u32 + 7904, ctx.r31.u32);
	// li r8,64
	ctx.r8.s64 = 64;
	// stw r10,12(r22)
	PPC_STORE_U32(ctx.r22.u32 + 12, ctx.r10.u32);
	// li r3,16
	ctx.r3.s64 = 16;
	// stw r9,16(r22)
	PPC_STORE_U32(ctx.r22.u32 + 16, ctx.r9.u32);
	// stw r8,316(r27)
	PPC_STORE_U32(ctx.r27.u32 + 316, ctx.r8.u32);
	// bl 0x881534c8
	ctx.lr = 0x880ACA48;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r7,32
	ctx.r7.s64 = 32;
	// addi r6,r11,8
	ctx.r6.s64 = ctx.r11.s64 + 8;
	// stw r6,320(r27)
	PPC_STORE_U32(ctx.r27.u32 + 320, ctx.r6.u32);
	// stw r7,8(r22)
	PPC_STORE_U32(ctx.r22.u32 + 8, ctx.r7.u32);
	// stw r31,0(r22)
	PPC_STORE_U32(ctx.r22.u32 + 0, ctx.r31.u32);
loc_880ACA60:
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r10,8(r22)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r22.u32 + 8);
	// lwz r9,304(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 304);
	// rlwinm r10,r10,12,0,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFFFF000;
	// lwz r8,300(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 300);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r11,26428(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26428);
	// stw r9,304(r27)
	PPC_STORE_U32(ctx.r27.u32 + 304, ctx.r9.u32);
	// clrlwi r7,r11,30
	ctx.r7.u64 = ctx.r11.u32 & 0x3;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x880acb9c
	if (!ctx.cr6.eq) goto loc_880ACB9C;
	// lwz r11,8(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 8);
	// lis r7,-30667
	ctx.r7.s64 = -2009792512;
	// lwz r10,12(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// lis r5,-30667
	ctx.r5.s64 = -2009792512;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lwz r4,2944(r27)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r27.u32 + 2944);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lis r29,-30671
	ctx.r29.s64 = -2010054656;
	// stw r11,12364(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12364, ctx.r11.u32);
	// lis r6,16838
	ctx.r6.s64 = 1103495168;
	// stw r10,12372(r5)
	PPC_STORE_U32(ctx.r5.u32 + 12372, ctx.r10.u32);
	// lis r9,-30667
	ctx.r9.s64 = -2009792512;
	// ori r31,r6,20077
	ctx.r31.u64 = ctx.r6.u64 | 20077;
	// lis r8,-30667
	ctx.r8.s64 = -2009792512;
	// lwz r11,4200(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4200);
	// lis r7,-30667
	ctx.r7.s64 = -2009792512;
	// li r3,2
	ctx.r3.s64 = 2;
	// mullw r11,r11,r31
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r31.s32);
	// stw r4,12376(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12376, ctx.r4.u32);
	// addi r30,r11,12345
	ctx.r30.s64 = ctx.r11.s64 + 12345;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r30,4200(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4200, ctx.r30.u32);
	// lhz r10,4200(r29)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r29.u32 + 4200);
	// clrlwi r5,r10,28
	ctx.r5.u64 = ctx.r10.u32 & 0xF;
	// stw r11,12380(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12380, ctx.r11.u32);
	// stw r5,12384(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12384, ctx.r5.u32);
	// bl 0x880f25b8
	ctx.lr = 0x880ACAF8;
	sub_880F25B8(ctx, base);
	// mullw r11,r30,r31
	ctx.r11.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r31.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// lis r6,15887
	ctx.r6.s64 = 1041170432;
	// stw r11,4200(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4200, ctx.r11.u32);
	// mullw r11,r11,r31
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r31.s32);
	// lhz r5,4200(r29)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r29.u32 + 4200);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// ori r4,r6,33761
	ctx.r4.u64 = ctx.r6.u64 | 33761;
	// stw r11,4200(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4200, ctx.r11.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// lhz r10,4200(r29)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r29.u32 + 4200);
	// mulhwu r9,r5,r4
	ctx.r9.u64 = (uint64_t(ctx.r5.u32) * uint64_t(ctx.r4.u32)) >> 32;
	// rlwinm r11,r9,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 29) & 0x1FFFFFFF;
	// clrlwi r8,r10,27
	ctx.r8.u64 = ctx.r10.u32 & 0x1F;
	// rlwinm r10,r11,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xFFFFFFE0;
	// subfic r6,r8,-240
	ctx.xer.ca = ctx.r8.u32 <= 4294967056;
	ctx.r6.s64 = -240 - ctx.r8.s64;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// clrlwi r10,r6,23
	ctx.r10.u64 = ctx.r6.u32 & 0x1FF;
	// subf r5,r7,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r7.s64;
	// extsh r11,r5
	ctx.r11.s64 = ctx.r5.s16;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// beq cr6,0x880acb9c
	if (ctx.cr6.eq) goto loc_880ACB9C;
	// lis r8,-30714
	ctx.r8.s64 = -2012872704;
	// stw r10,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r10.u32);
	// addic. r9,r3,28
	ctx.xer.ca = ctx.r3.u32 > 4294967267;
	ctx.r9.s64 = ctx.r3.s64 + 28;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r11.u32);
	// addi r7,r3,24
	ctx.r7.s64 = ctx.r3.s64 + 24;
	// clrlwi r10,r10,23
	ctx.r10.u64 = ctx.r10.u32 & 0x1FF;
	// addi r8,r8,9552
	ctx.r8.s64 = ctx.r8.s64 + 9552;
	// beq 0x880acb84
	if (ctx.cr0.eq) goto loc_880ACB84;
	// addi r6,r10,128
	ctx.r6.s64 = ctx.r10.s64 + 128;
	// rlwinm r5,r6,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// lwzx r4,r5,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r8.u32);
	// mullw r3,r4,r11
	ctx.r3.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r11.s32);
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
loc_880ACB84:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x880acb9c
	if (ctx.cr6.eq) goto loc_880ACB9C;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r8
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// mullw r8,r9,r11
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// stw r8,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r8.u32);
loc_880ACB9C:
	// lwz r11,12(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// lis r9,384
	ctx.r9.s64 = 25165824;
	// lwz r10,304(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 304);
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// ble cr6,0x880acc00
	if (!ctx.cr6.gt) goto loc_880ACC00;
	// lwz r11,12(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 12);
	// li r10,7
	ctx.r10.s64 = 7;
	// li r9,10
	ctx.r9.s64 = 10;
	// li r8,4
	ctx.r8.s64 = 4;
	// stw r10,7568(r27)
	PPC_STORE_U32(ctx.r27.u32 + 7568, ctx.r10.u32);
	// lis r7,-30709
	ctx.r7.s64 = -2012545024;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,300(r27)
	PPC_STORE_U32(ctx.r27.u32 + 300, ctx.r11.u32);
	// addi r4,r7,-20608
	ctx.r4.s64 = ctx.r7.s64 + -20608;
	// stw r9,0(r22)
	PPC_STORE_U32(ctx.r22.u32 + 0, ctx.r9.u32);
	// stw r8,8(r22)
	PPC_STORE_U32(ctx.r22.u32 + 8, ctx.r8.u32);
	// lwz r3,24(r27)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r27.u32 + 24);
	// bl 0x88096cb8
	ctx.lr = 0x880ACBE8;
	sub_88096CB8(ctx, base);
	// lwz r5,304(r27)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r27.u32 + 304);
	// lwz r4,16(r22)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r22.u32 + 16);
	// li r6,0
	ctx.r6.s64 = 0;
	// subf r3,r4,r5
	ctx.r3.s64 = ctx.r5.s64 - ctx.r4.s64;
	// stw r6,28(r22)
	PPC_STORE_U32(ctx.r22.u32 + 28, ctx.r6.u32);
	// stw r3,24(r22)
	PPC_STORE_U32(ctx.r22.u32 + 24, ctx.r3.u32);
loc_880ACC00:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8807117c
	__restgprlr_17(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880ACC0C"))) PPC_WEAK_FUNC(sub_880ACC0C);
PPC_FUNC_IMPL(__imp__sub_880ACC0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880ACC10"))) PPC_WEAK_FUNC(sub_880ACC10);
PPC_FUNC_IMPL(__imp__sub_880ACC10) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x880ACC18;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// lwz r30,2304(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x88096bc8
	ctx.lr = 0x880ACC38;
	sub_88096BC8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// bgt cr6,0x880acefc
	if (ctx.cr6.gt) goto loc_880ACEFC;
	// li r27,0
	ctx.r27.s64 = 0;
	// beq cr6,0x880acd20
	if (ctx.cr6.eq) goto loc_880ACD20;
	// li r29,32
	ctx.r29.s64 = 32;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x880acc6c
	if (ctx.cr6.lt) goto loc_880ACC6C;
	// beq cr6,0x880acc90
	if (ctx.cr6.eq) goto loc_880ACC90;
loc_880ACC60:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_880ACC6C:
	// li r11,48
	ctx.r11.s64 = 48;
	// stw r27,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r27.u32);
	// li r10,52
	ctx.r10.s64 = 52;
	// stw r29,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r29.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
loc_880ACC90:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r9,2300(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2300);
	// lwz r8,280(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 280);
	// subf r7,r8,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r7,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r7.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880acccc
	if (ctx.cr6.eq) goto loc_880ACCCC;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x880acccc
	if (ctx.cr0.gt) goto loc_880ACCCC;
	// stw r27,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r27.u32);
	// li r3,96
	ctx.r3.s64 = 96;
	// bl 0x880900a0
	ctx.lr = 0x880ACCCC;
	sub_880900A0(ctx, base);
loc_880ACCCC:
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addi r11,r11,-12768
	ctx.r11.s64 = ctx.r11.s64 + -12768;
	// lwz r10,784(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 784);
	// lwz r10,176(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 176);
	// cmpwi cr6,r10,1747
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1747, ctx.xer);
	// blt cr6,0x880acc60
	if (ctx.cr6.lt) goto loc_880ACC60;
	// lwz r10,1876(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1876);
	// li r9,10
	ctx.r9.s64 = 10;
	// stw r29,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// bne cr6,0x880acc60
	if (!ctx.cr6.eq) goto loc_880ACC60;
	// lis r9,-30628
	ctx.r9.s64 = -2007236608;
	// lwz r10,1884(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1884);
	// lwz r11,1880(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1880);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r8,r9,26648
	ctx.r8.s64 = ctx.r9.s64 + 26648;
	// stw r10,148(r8)
	PPC_STORE_U32(ctx.r8.u32 + 148, ctx.r10.u32);
	// sth r11,152(r8)
	PPC_STORE_U16(ctx.r8.u32 + 152, ctx.r11.u16);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_880ACD20:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r9,2300(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2300);
	// lwz r8,280(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 280);
	// subf r7,r8,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r7,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r7.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880acd98
	if (ctx.cr6.eq) goto loc_880ACD98;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x880acd98
	if (ctx.cr0.gt) goto loc_880ACD98;
	// stw r27,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r27.u32);
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lis r9,-30709
	ctx.r9.s64 = -2012545024;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,-15848
	ctx.r4.s64 = ctx.r9.s64 + -15848;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r11,-12768(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12768, ctx.r11.u32);
	// bl 0x88096cb8
	ctx.lr = 0x880ACD74;
	sub_88096CB8(ctx, base);
	// lis r8,-30709
	ctx.r8.s64 = -2012545024;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r8,-16024
	ctx.r4.s64 = ctx.r8.s64 + -16024;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x88096cb8
	ctx.lr = 0x880ACD88;
	sub_88096CB8(ctx, base);
	// lwz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// stw r3,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r3.u32);
	// addi r7,r11,4
	ctx.r7.s64 = ctx.r11.s64 + 4;
	// stw r7,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r7.u32);
loc_880ACD98:
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r11,r11,30408
	ctx.r11.s64 = ctx.r11.s64 + 30408;
	// lwz r10,588(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 588);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x880acec8
	if (!ctx.cr6.gt) goto loc_880ACEC8;
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// bge 0x880acec8
	if (!ctx.cr0.lt) goto loc_880ACEC8;
	// lwz r9,40(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// addi r10,r10,9552
	ctx.r10.s64 = ctx.r10.s64 + 9552;
	// stw r9,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r9.u32);
	// lwz r9,376(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 376);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x880ace20
	if (!ctx.cr6.gt) goto loc_880ACE20;
	// lwz r6,372(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 372);
	// addi r8,r9,-1
	ctx.r8.s64 = ctx.r9.s64 + -1;
	// lwz r7,32(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// clrlwi r9,r6,23
	ctx.r9.u64 = ctx.r6.u32 & 0x1FF;
	// stw r8,376(r11)
	PPC_STORE_U32(ctx.r11.u32 + 376, ctx.r8.u32);
	// addi r6,r9,128
	ctx.r6.s64 = ctx.r9.s64 + 128;
	// stw r9,372(r11)
	PPC_STORE_U32(ctx.r11.u32 + 372, ctx.r9.u32);
	// rlwinm r5,r9,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r4,r6,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// lwzx r3,r5,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r10.u32);
	// lwzx r9,r4,r10
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r10.u32);
	// mullw r6,r3,r8
	ctx.r6.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r8.s32);
	// stw r6,380(r11)
	PPC_STORE_U32(ctx.r11.u32 + 380, ctx.r6.u32);
	// mullw r9,r9,r8
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// stw r9,384(r11)
	PPC_STORE_U32(ctx.r11.u32 + 384, ctx.r9.u32);
	// stw r6,244(r7)
	PPC_STORE_U32(ctx.r7.u32 + 244, ctx.r6.u32);
	// neg r8,r9
	ctx.r8.s64 = -ctx.r9.s64;
	// stw r8,248(r7)
	PPC_STORE_U32(ctx.r7.u32 + 248, ctx.r8.u32);
loc_880ACE20:
	// lwz r8,800(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 800);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// ble cr6,0x880ace74
	if (!ctx.cr6.gt) goto loc_880ACE74;
	// lwz r9,796(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 796);
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// lwz r7,32(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// clrlwi r9,r9,23
	ctx.r9.u64 = ctx.r9.u32 & 0x1FF;
	// stw r8,800(r11)
	PPC_STORE_U32(ctx.r11.u32 + 800, ctx.r8.u32);
	// addi r6,r9,128
	ctx.r6.s64 = ctx.r9.s64 + 128;
	// stw r9,796(r11)
	PPC_STORE_U32(ctx.r11.u32 + 796, ctx.r9.u32);
	// rlwinm r5,r9,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r4,r6,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// lwzx r3,r5,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r10.u32);
	// lwzx r9,r4,r10
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r10.u32);
	// mullw r6,r3,r8
	ctx.r6.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r8.s32);
	// stw r6,804(r11)
	PPC_STORE_U32(ctx.r11.u32 + 804, ctx.r6.u32);
	// mullw r9,r9,r8
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// stw r9,808(r11)
	PPC_STORE_U32(ctx.r11.u32 + 808, ctx.r9.u32);
	// stw r6,260(r7)
	PPC_STORE_U32(ctx.r7.u32 + 260, ctx.r6.u32);
	// neg r8,r9
	ctx.r8.s64 = -ctx.r9.s64;
	// stw r8,264(r7)
	PPC_STORE_U32(ctx.r7.u32 + 264, ctx.r8.u32);
loc_880ACE74:
	// lwz r8,588(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 588);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// ble cr6,0x880acec8
	if (!ctx.cr6.gt) goto loc_880ACEC8;
	// lwz r9,584(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 584);
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// lwz r7,32(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// clrlwi r9,r9,23
	ctx.r9.u64 = ctx.r9.u32 & 0x1FF;
	// stw r8,588(r11)
	PPC_STORE_U32(ctx.r11.u32 + 588, ctx.r8.u32);
	// addi r6,r9,128
	ctx.r6.s64 = ctx.r9.s64 + 128;
	// stw r9,584(r11)
	PPC_STORE_U32(ctx.r11.u32 + 584, ctx.r9.u32);
	// rlwinm r5,r9,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r4,r6,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// lwzx r3,r5,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r10.u32);
	// lwzx r10,r4,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r10.u32);
	// mullw r9,r3,r8
	ctx.r9.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r8.s32);
	// stw r9,592(r11)
	PPC_STORE_U32(ctx.r11.u32 + 592, ctx.r9.u32);
	// mullw r10,r10,r8
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r8.s32);
	// stw r10,596(r11)
	PPC_STORE_U32(ctx.r11.u32 + 596, ctx.r10.u32);
	// stw r9,252(r7)
	PPC_STORE_U32(ctx.r7.u32 + 252, ctx.r9.u32);
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// stw r9,256(r7)
	PPC_STORE_U32(ctx.r7.u32 + 256, ctx.r9.u32);
loc_880ACEC8:
	// lwz r4,44(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x880acc60
	if (ctx.cr6.eq) goto loc_880ACC60;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x88096a68
	ctx.lr = 0x880ACEDC;
	sub_88096A68(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x880acc60
	if (!ctx.cr6.eq) goto loc_880ACC60;
	// li r11,20
	ctx.r11.s64 = 20;
	// stw r27,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r27.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_880ACEFC:
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bne cr6,0x880acc60
	if (!ctx.cr6.eq) goto loc_880ACC60;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bge 0x880acc60
	if (!ctx.cr0.lt) goto loc_880ACC60;
	// lis r11,-30709
	ctx.r11.s64 = -2012545024;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-16608
	ctx.r4.s64 = ctx.r11.s64 + -16608;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x88096cb8
	ctx.lr = 0x880ACF28;
	sub_88096CB8(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x88096b40
	ctx.lr = 0x880ACF34;
	sub_88096B40(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880ACF40"))) PPC_WEAK_FUNC(sub_880ACF40);
PPC_FUNC_IMPL(__imp__sub_880ACF40) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x880ACF48;
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
	ctx.lr = 0x880ACF70;
	sub_88096BC8(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r7,r31,8976
	ctx.r7.s64 = ctx.r31.s64 + 8976;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
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
	// addi r11,r11,9
	ctx.r11.s64 = ctx.r11.s64 + 9;
	// li r4,94
	ctx.r4.s64 = 94;
	// stw r11,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r11.u32);
	// li r3,5
	ctx.r3.s64 = 5;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// stw r10,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r10.u32);
	// stw r9,28(r8)
	PPC_STORE_U32(ctx.r8.u32 + 28, ctx.r9.u32);
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// stw r9,56(r8)
	PPC_STORE_U32(ctx.r8.u32 + 56, ctx.r9.u32);
	// bl 0x880e32d0
	ctx.lr = 0x880ACFC0;
	sub_880E32D0(ctx, base);
	// lis r8,-30709
	ctx.r8.s64 = -2012545024;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r5,r8,-15656
	ctx.r5.s64 = ctx.r8.s64 + -15656;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88096c60
	ctx.lr = 0x880ACFD4;
	sub_88096C60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880ACFE0"))) PPC_WEAK_FUNC(sub_880ACFE0);
PPC_FUNC_IMPL(__imp__sub_880ACFE0) {
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
	// addi r10,r11,9880
	ctx.r10.s64 = ctx.r11.s64 + 9880;
	// addi r9,r11,9884
	ctx.r9.s64 = ctx.r11.s64 + 9884;
	// stw r6,9884(r11)
	PPC_STORE_U32(ctx.r11.u32 + 9884, ctx.r6.u32);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// lis r5,-30710
	ctx.r5.s64 = -2012610560;
	// stw r7,9880(r11)
	PPC_STORE_U32(ctx.r11.u32 + 9880, ctx.r7.u32);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r5,21904
	ctx.r5.s64 = ctx.r5.s64 + 21904;
	// li r4,30
	ctx.r4.s64 = 30;
	// bl 0x88096460
	ctx.lr = 0x880AD03C;
	sub_88096460(ctx, base);
	// lis r4,-30641
	ctx.r4.s64 = -2008088576;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r10,r4,-18816
	ctx.r10.s64 = ctx.r4.s64 + -18816;
	// lis r9,-30709
	ctx.r9.s64 = -2012545024;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r9,-26608
	ctx.r5.s64 = ctx.r9.s64 + -26608;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// bl 0x88096c60
	ctx.lr = 0x880AD060;
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

__attribute__((alias("__imp__sub_880AD07C"))) PPC_WEAK_FUNC(sub_880AD07C);
PPC_FUNC_IMPL(__imp__sub_880AD07C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880AD080"))) PPC_WEAK_FUNC(sub_880AD080);
PPC_FUNC_IMPL(__imp__sub_880AD080) {
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
	// li r5,48
	ctx.r5.s64 = 48;
	// bl 0x88096bc8
	ctx.lr = 0x880AD0AC;
	sub_88096BC8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// lis r9,-30709
	ctx.r9.s64 = -2012545024;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r9,-14752
	ctx.r5.s64 = ctx.r9.s64 + -14752;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88096c60
	ctx.lr = 0x880AD0D0;
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

