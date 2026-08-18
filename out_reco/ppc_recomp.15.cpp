#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_88109020"))) PPC_WEAK_FUNC(sub_88109020);
PPC_FUNC_IMPL(__imp__sub_88109020) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2304);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r4,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r4.u32);
	// stw r5,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r5.u32);
	// stw r10,96(r7)
	PPC_STORE_U32(ctx.r7.u32 + 96, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8810903C"))) PPC_WEAK_FUNC(sub_8810903C);
PPC_FUNC_IMPL(__imp__sub_8810903C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88109040"))) PPC_WEAK_FUNC(sub_88109040);
PPC_FUNC_IMPL(__imp__sub_88109040) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2304);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r4,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r4.u32);
	// stw r5,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r5.u32);
	// stw r10,96(r7)
	PPC_STORE_U32(ctx.r7.u32 + 96, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8810905C"))) PPC_WEAK_FUNC(sub_8810905C);
PPC_FUNC_IMPL(__imp__sub_8810905C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88109060"))) PPC_WEAK_FUNC(sub_88109060);
PPC_FUNC_IMPL(__imp__sub_88109060) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2304);
	// cmpwi cr6,r5,512
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 512, ctx.xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r4,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r4.u32);
	// stw r5,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r5.u32);
	// bltlr cr6
	if (ctx.cr6.lt) return;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r10,96(r7)
	PPC_STORE_U32(ctx.r7.u32 + 96, ctx.r10.u32);
	// stw r9,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8810908C"))) PPC_WEAK_FUNC(sub_8810908C);
PPC_FUNC_IMPL(__imp__sub_8810908C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88109090"))) PPC_WEAK_FUNC(sub_88109090);
PPC_FUNC_IMPL(__imp__sub_88109090) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2304);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r4,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r4.u32);
	// stw r5,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r5.u32);
	// stw r10,96(r7)
	PPC_STORE_U32(ctx.r7.u32 + 96, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881090AC"))) PPC_WEAK_FUNC(sub_881090AC);
PPC_FUNC_IMPL(__imp__sub_881090AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881090B0"))) PPC_WEAK_FUNC(sub_881090B0);
PPC_FUNC_IMPL(__imp__sub_881090B0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// li r11,0
	ctx.r11.s64 = 0;
	// std r11,0(r9)
	PPC_STORE_U64(ctx.r9.u32 + 0, ctx.r11.u64);
	// std r11,8(r9)
	PPC_STORE_U64(ctx.r9.u32 + 8, ctx.r11.u64);
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// std r11,16(r9)
	PPC_STORE_U64(ctx.r9.u32 + 16, ctx.r11.u64);
	// std r11,24(r9)
	PPC_STORE_U64(ctx.r9.u32 + 24, ctx.r11.u64);
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// stw r11,32(r9)
	PPC_STORE_U32(ctx.r9.u32 + 32, ctx.r11.u32);
	// bne cr6,0x88109108
	if (!ctx.cr6.eq) goto loc_88109108;
	// lwz r10,184(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// lwz r9,168(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// add r11,r10,r9
	ctx.r11.u64 = ctx.r10.u64 + ctx.r9.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// b 0x8810914c
	goto loc_8810914C;
loc_88109108:
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// beq cr6,0x88109130
	if (ctx.cr6.eq) goto loc_88109130;
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// beq cr6,0x88109130
	if (ctx.cr6.eq) goto loc_88109130;
	// lwz r10,184(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// lwz r9,168(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// add r11,r10,r9
	ctx.r11.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// b 0x8810914c
	goto loc_8810914C;
loc_88109130:
	// lwz r11,184(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// li r9,3
	ctx.r9.s64 = 3;
	// lwz r10,168(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r8,r11,-1
	ctx.r8.s64 = ctx.r11.s64 + -1;
	// stw r8,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
loc_8810914C:
	// addi r11,r31,8
	ctx.r11.s64 = ctx.r31.s64 + 8;
	// addi r10,r31,64
	ctx.r10.s64 = ctx.r31.s64 + 64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r10,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// bl 0x88093be8
	ctx.lr = 0x88109164;
	sub_88093BE8(ctx, base);
	// stw r3,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r3.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8810917C"))) PPC_WEAK_FUNC(sub_8810917C);
PPC_FUNC_IMPL(__imp__sub_8810917C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88109180"))) PPC_WEAK_FUNC(sub_88109180);
PPC_FUNC_IMPL(__imp__sub_88109180) {
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
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lis r10,-30633
	ctx.r10.s64 = -2007564288;
	// lwz r11,-11984(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11984);
	// lwz r10,-29780(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -29780);
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// lwz r11,88(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// beq cr6,0x881091b8
	if (ctx.cr6.eq) goto loc_881091B8;
	// lis r10,-30633
	ctx.r10.s64 = -2007564288;
	// lwz r10,-29740(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -29740);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x881091d0
	if (ctx.cr6.eq) goto loc_881091D0;
loc_881091B8:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x881091fc
	if (ctx.cr6.eq) goto loc_881091FC;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// beq cr6,0x881091fc
	if (ctx.cr6.eq) goto loc_881091FC;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x881091fc
	if (ctx.cr6.eq) goto loc_881091FC;
loc_881091D0:
	// lis r10,-30633
	ctx.r10.s64 = -2007564288;
	// lwz r10,-29784(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -29784);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x881091e8
	if (ctx.cr6.eq) goto loc_881091E8;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// beq cr6,0x881091fc
	if (ctx.cr6.eq) goto loc_881091FC;
loc_881091E8:
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
loc_881091FC:
	// bl 0x88094220
	ctx.lr = 0x88109200;
	sub_88094220(ctx, base);
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

__attribute__((alias("__imp__sub_88109214"))) PPC_WEAK_FUNC(sub_88109214);
PPC_FUNC_IMPL(__imp__sub_88109214) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88109218"))) PPC_WEAK_FUNC(sub_88109218);
PPC_FUNC_IMPL(__imp__sub_88109218) {
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
	// stw r3,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r3.u32);
	// lis r7,16
	ctx.r7.s64 = 1048576;
	// lwz r11,100(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// lwz r8,8(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// add. r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// and r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 & ctx.r11.u64;
	// ble 0x8810929c
	if (!ctx.cr0.gt) goto loc_8810929C;
	// lis r9,32
	ctx.r9.s64 = 2097152;
	// lis r6,320
	ctx.r6.s64 = 20971520;
	// subf r5,r9,r10
	ctx.r5.s64 = ctx.r10.s64 - ctx.r9.s64;
	// cmpw cr6,r5,r6
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r6.s32, ctx.xer);
	// bge cr6,0x8810929c
	if (!ctx.cr6.lt) goto loc_8810929C;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// addi r6,r11,55
	ctx.r6.s64 = ctx.r11.s64 + 55;
	// lis r5,-40
	ctx.r5.s64 = -2621440;
	// rlwinm r6,r6,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-11984(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11984);
	// lwzx r11,r6,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r11.u32);
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// cmpw cr6,r11,r5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r5.s32, ctx.xer);
	// ble cr6,0x8810929c
	if (!ctx.cr6.gt) goto loc_8810929C;
	// lis r10,280
	ctx.r10.s64 = 18350080;
	// subf r9,r9,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r9.s64;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x881092e0
	if (ctx.cr6.lt) goto loc_881092E0;
loc_8810929C:
	// lwz r11,120(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 120);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x881092bc
	if (!ctx.cr6.eq) goto loc_881092BC;
	// lwz r11,96(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 96);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,96(r4)
	PPC_STORE_U32(ctx.r4.u32 + 96, ctx.r11.u32);
	// cmpwi cr6,r11,300
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 300, ctx.xer);
	// blt cr6,0x881092e8
	if (ctx.cr6.lt) goto loc_881092E8;
loc_881092BC:
	// lwz r11,136(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 136);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x88094220
	ctx.lr = 0x881092CC;
	sub_88094220(ctx, base);
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
loc_881092E0:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,120(r4)
	PPC_STORE_U32(ctx.r4.u32 + 120, ctx.r11.u32);
loc_881092E8:
	// lwz r11,136(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 136);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88109318
	if (ctx.cr6.eq) goto loc_88109318;
loc_88109300:
	// lwz r8,20(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// stw r9,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r9.u32);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// or r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 | ctx.r10.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88109300
	if (!ctx.cr6.eq) goto loc_88109300;
loc_88109318:
	// lis r11,128
	ctx.r11.s64 = 8388608;
	// clrlwi r10,r10,20
	ctx.r10.u64 = ctx.r10.u32 & 0xFFF;
	// ori r8,r11,32896
	ctx.r8.u64 = ctx.r11.u64 | 32896;
	// rlwinm r10,r10,0,26,20
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFF83F;
	// stw r8,112(r4)
	PPC_STORE_U32(ctx.r4.u32 + 112, ctx.r8.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x88109358
	if (ctx.cr6.eq) goto loc_88109358;
	// lwz r11,116(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 116);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r8,116(r4)
	PPC_STORE_U32(ctx.r4.u32 + 116, ctx.r8.u32);
	// beq cr6,0x88109358
	if (ctx.cr6.eq) goto loc_88109358;
	// lis r11,192
	ctx.r11.s64 = 12582912;
	// ori r10,r11,49152
	ctx.r10.u64 = ctx.r11.u64 | 49152;
	// stw r10,112(r4)
	PPC_STORE_U32(ctx.r4.u32 + 112, ctx.r10.u32);
loc_88109358:
	// lwz r11,24(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,24(r4)
	PPC_STORE_U32(ctx.r4.u32 + 24, ctx.r11.u32);
	// bge 0x88109388
	if (!ctx.cr0.lt) goto loc_88109388;
	// lwz r11,32(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 32);
	// lwz r10,28(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,32(r4)
	PPC_STORE_U32(ctx.r4.u32 + 32, ctx.r11.u32);
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// stw r10,24(r4)
	PPC_STORE_U32(ctx.r4.u32 + 24, ctx.r10.u32);
	// blt cr6,0x88109388
	if (ctx.cr6.lt) goto loc_88109388;
	// stw r9,32(r4)
	PPC_STORE_U32(ctx.r4.u32 + 32, ctx.r9.u32);
loc_88109388:
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

__attribute__((alias("__imp__sub_8810939C"))) PPC_WEAK_FUNC(sub_8810939C);
PPC_FUNC_IMPL(__imp__sub_8810939C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881093A0"))) PPC_WEAK_FUNC(sub_881093A0);
PPC_FUNC_IMPL(__imp__sub_881093A0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r9,136(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 136);
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

__attribute__((alias("__imp__sub_881093E0"))) PPC_WEAK_FUNC(sub_881093E0);
PPC_FUNC_IMPL(__imp__sub_881093E0) {
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
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// lwz r7,100(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// li r11,15
	ctx.r11.s64 = 15;
	// cmplwi cr6,r7,2
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 2, ctx.xer);
	// blt cr6,0x88109410
	if (ctx.cr6.lt) goto loc_88109410;
	// li r11,18
	ctx.r11.s64 = 18;
loc_88109410:
	// lwz r7,132(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmplwi cr6,r7,1
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 1, ctx.xer);
	// blt cr6,0x881094a4
	if (ctx.cr6.lt) goto loc_881094A4;
	// beq cr6,0x8810948c
	if (ctx.cr6.eq) goto loc_8810948C;
	// cmplwi cr6,r7,3
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 3, ctx.xer);
	// bge cr6,0x881094d8
	if (!ctx.cr6.lt) goto loc_881094D8;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r9,r9,-6
	ctx.r9.s64 = ctx.r9.s64 + -6;
	// sth r3,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r3.u16);
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// extsh r6,r9
	ctx.r6.s64 = ctx.r9.s16;
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// bl 0x8815c948
	ctx.lr = 0x88109448;
	sub_8815C948(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x881094d8
	if (ctx.cr6.eq) goto loc_881094D8;
	// li r11,2
	ctx.r11.s64 = 2;
	// li r10,3
	ctx.r10.s64 = 3;
	// li r9,1
	ctx.r9.s64 = 1;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r11.u8);
	// sth r11,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, ctx.r11.u16);
	// li r5,72
	ctx.r5.s64 = 72;
	// sth r10,28(r3)
	PPC_STORE_U16(ctx.r3.u32 + 28, ctx.r10.u16);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r9,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r9.u32);
	// addi r3,r3,36
	ctx.r3.s64 = ctx.r3.s64 + 36;
	// bl 0x88072260
	ctx.lr = 0x8810947C;
	sub_88072260(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_8810948C:
	// lis r7,-30643
	ctx.r7.s64 = -2008219648;
	// lwz r7,26276(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + 26276);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x881094d8
	if (!ctx.cr6.eq) goto loc_881094D8;
	// addi r9,r9,-14
	ctx.r9.s64 = ctx.r9.s64 + -14;
	// b 0x881094b4
	goto loc_881094B4;
loc_881094A4:
	// lis r7,-30643
	ctx.r7.s64 = -2008219648;
	// lwz r7,26276(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + 26276);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x881094d8
	if (!ctx.cr6.eq) goto loc_881094D8;
loc_881094B4:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// sth r3,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r3.u16);
	// extsh r6,r9
	ctx.r6.s64 = ctx.r9.s16;
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// bl 0x8815c948
	ctx.lr = 0x881094D0;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x881094D8;
	sub_8815C860(ctx, base);
loc_881094D8:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881094E8"))) PPC_WEAK_FUNC(sub_881094E8);
PPC_FUNC_IMPL(__imp__sub_881094E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x881094F0;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x88109218
	ctx.lr = 0x88109504;
	sub_88109218(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x881096ec
	if (ctx.cr6.eq) goto loc_881096EC;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26272(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26272);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x881096ec
	if (!ctx.cr6.eq) goto loc_881096EC;
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lis r7,-30714
	ctx.r7.s64 = -2012872704;
	// lwz r10,104(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// lis r30,-30597
	ctx.r30.s64 = -2005204992;
	// clrlwi r11,r8,23
	ctx.r11.u64 = ctx.r8.u32 & 0x1FF;
	// lwz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r5,r7,9552
	ctx.r5.s64 = ctx.r7.s64 + 9552;
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r4,r11,128
	ctx.r4.s64 = ctx.r11.s64 + 128;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// rlwinm r3,r8,2,21,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x7FC;
	// rlwinm r7,r4,2,21,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x7FC;
	// lwz r4,-11984(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + -11984);
	// addi r10,r10,51
	ctx.r10.s64 = ctx.r10.s64 + 51;
	// cmpwi cr6,r8,512
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 512, ctx.xer);
	// rlwinm r27,r10,2,0,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r3,r5
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r5.u32);
	// li r28,1
	ctx.r28.s64 = 1;
	// lwzx r8,r7,r5
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r5.u32);
	// mullw r10,r3,r6
	ctx.r10.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r6.s32);
	// mullw r8,r8,r6
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r6.s32);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r5,r8,r9
	ctx.r5.u64 = ctx.r8.u64 + ctx.r9.u64;
	// rotlwi r10,r7,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// stw r7,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r7.u32);
	// stw r5,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r5.u32);
	// lwzx r11,r27,r4
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r4.u32);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r4,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r4.u32);
	// blt cr6,0x88109598
	if (ctx.cr6.lt) goto loc_88109598;
	// stw r28,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r28.u32);
loc_88109598:
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x881095ec
	if (ctx.cr6.eq) goto loc_881095EC;
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x881095ec
	if (ctx.cr6.eq) goto loc_881095EC;
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// bge 0x881095ec
	if (!ctx.cr0.lt) goto loc_881095EC;
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r10,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r10.u32);
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// bl 0x88095590
	ctx.lr = 0x881095D8;
	sub_88095590(ctx, base);
	// li r5,8
	ctx.r5.s64 = 8;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// bl 0x88153010
	ctx.lr = 0x881095E4;
	sub_88153010(ctx, base);
	// clrlwi r9,r3,16
	ctx.r9.u64 = ctx.r3.u32 & 0xFFFF;
	// stw r9,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
loc_881095EC:
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8810961c
	if (ctx.cr6.eq) goto loc_8810961C;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88095590
	ctx.lr = 0x88109608;
	sub_88095590(ctx, base);
	// li r5,8
	ctx.r5.s64 = 8;
	// lwz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// bl 0x88153010
	ctx.lr = 0x88109614;
	sub_88153010(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
loc_8810961C:
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x881096ec
	if (!ctx.cr6.eq) goto loc_881096EC;
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// bgt 0x881096ec
	if (ctx.cr0.gt) goto loc_881096EC;
	// lwz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// lis r11,-30680
	ctx.r11.s64 = -2010644480;
	// lwz r7,-11984(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + -11984);
	// li r9,0
	ctx.r9.s64 = 0;
	// srawi r6,r8,4
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xF) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 4;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r11,r11,14736
	ctx.r11.s64 = ctx.r11.s64 + 14736;
	// stw r9,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r9.u32);
	// addze r5,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r5.s64 = temp.s64;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r4,r11,4
	ctx.r4.s64 = ctx.r11.s64 + 4;
	// rlwinm r3,r5,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// li r6,4
	ctx.r6.s64 = 4;
	// lis r5,-30683
	ctx.r5.s64 = -2010841088;
	// stw r6,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r6.u32);
	// lwz r7,88(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + 88);
	// rlwinm r30,r7,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r3,r4
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r4.u32);
	// addi r6,r5,12112
	ctx.r6.s64 = ctx.r5.s64 + 12112;
	// lwzx r11,r3,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r11.u32);
	// lwzx r4,r30,r6
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r6.u32);
	// cmpw cr6,r10,r4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r4.s32, ctx.xer);
	// add r5,r11,r9
	ctx.r5.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r6,r7,r10
	ctx.r6.u64 = ctx.r7.u64 + ctx.r10.u64;
	// ble cr6,0x881096ac
	if (!ctx.cr6.gt) goto loc_881096AC;
	// li r7,12
	ctx.r7.s64 = 12;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x881093e0
	ctx.lr = 0x881096AC;
	sub_881093E0(ctx, base);
loc_881096AC:
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
	// bgt 0x881096ec
	if (ctx.cr0.gt) goto loc_881096EC;
	// lwz r11,132(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// li r10,2
	ctx.r10.s64 = 2;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r10,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r10.u32);
	// bne cr6,0x881096d4
	if (!ctx.cr6.eq) goto loc_881096D4;
	// stw r28,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r28.u32);
loc_881096D4:
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// stw r28,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r28.u32);
	// lwz r11,26424(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26424);
	// rlwinm r10,r11,29,4,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0xFFFFFFF;
	// subfic r9,r10,38
	ctx.xer.ca = ctx.r10.u32 <= 38;
	ctx.r9.s64 = 38 - ctx.r10.s64;
	// stw r9,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r9.u32);
loc_881096EC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_881096F4"))) PPC_WEAK_FUNC(sub_881096F4);
PPC_FUNC_IMPL(__imp__sub_881096F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881096F8"))) PPC_WEAK_FUNC(sub_881096F8);
PPC_FUNC_IMPL(__imp__sub_881096F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88109700;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x88109218
	ctx.lr = 0x88109714;
	sub_88109218(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x88109a04
	if (ctx.cr6.eq) goto loc_88109A04;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26272(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26272);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88109a04
	if (!ctx.cr6.eq) goto loc_88109A04;
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lis r7,-30714
	ctx.r7.s64 = -2012872704;
	// lwz r8,104(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// lis r30,-30597
	ctx.r30.s64 = -2005204992;
	// clrlwi r11,r9,23
	ctx.r11.u64 = ctx.r9.u32 & 0x1FF;
	// lwz r28,76(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// addi r5,r7,9552
	ctx.r5.s64 = ctx.r7.s64 + 9552;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r4,r11,128
	ctx.r4.s64 = ctx.r11.s64 + 128;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// rlwinm r3,r9,2,21,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x7FC;
	// lwz r6,12(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// rlwinm r4,r4,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x7FC;
	// lwz r7,-11984(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + -11984);
	// addi r8,r8,51
	ctx.r8.s64 = ctx.r8.s64 + 51;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// rlwinm r28,r8,2,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r3,r5
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r5.u32);
	// lwzx r5,r4,r5
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r5.u32);
	// mullw r8,r3,r10
	ctx.r8.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r10.s32);
	// mullw r5,r5,r10
	ctx.r5.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r10.s32);
	// add r4,r8,r11
	ctx.r4.u64 = ctx.r8.u64 + ctx.r11.u64;
	// add r11,r5,r6
	ctx.r11.u64 = ctx.r5.u64 + ctx.r6.u64;
	// rotlwi r6,r4,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r4.u32, 0);
	// stw r4,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r4.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// lwzx r8,r28,r7
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r28.u32 + ctx.r7.u32);
	// add r4,r6,r8
	ctx.r4.u64 = ctx.r6.u64 + ctx.r8.u64;
	// stw r4,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r4.u32);
	// bne cr6,0x881098f0
	if (!ctx.cr6.eq) goto loc_881098F0;
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r10.u32);
	// bgt 0x88109844
	if (ctx.cr0.gt) goto loc_88109844;
	// lwz r10,88(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r10,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r10.u32);
	// bl 0x88095590
	ctx.lr = 0x881097C8;
	sub_88095590(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x88109844
	if (ctx.cr6.lt) goto loc_88109844;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26276(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88109844
	if (!ctx.cr6.eq) goto loc_88109844;
	// lwz r9,-11984(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + -11984);
	// srawi r11,r3,4
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xF) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 4;
	// lis r6,-30680
	ctx.r6.s64 = -2010644480;
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addze r5,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r5.s64 = temp.s64;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r11,r6,14736
	ctx.r11.s64 = ctx.r6.s64 + 14736;
	// lis r4,-30683
	ctx.r4.s64 = -2010841088;
	// lwz r3,88(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 88);
	// rlwinm r9,r5,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r6,r11,4
	ctx.r6.s64 = ctx.r11.s64 + 4;
	// addi r4,r4,12112
	ctx.r4.s64 = ctx.r4.s64 + 12112;
	// rlwinm r3,r3,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r9,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// lwzx r9,r9,r6
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r6.u32);
	// add r5,r11,r7
	ctx.r5.u64 = ctx.r11.u64 + ctx.r7.u64;
	// lwzx r11,r3,r4
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r4.u32);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x88109844
	if (!ctx.cr6.gt) goto loc_88109844;
	// li r7,6
	ctx.r7.s64 = 6;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x881093e0
	ctx.lr = 0x88109844;
	sub_881093E0(ctx, base);
loc_88109844:
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// bge 0x881098c4
	if (!ctx.cr0.lt) goto loc_881098C4;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// addic. r11,r11,-2
	ctx.xer.ca = ctx.r11.u32 > 1;
	ctx.r11.s64 = ctx.r11.s64 + -2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// stw r10,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r10.u32);
	// bgt 0x881098c4
	if (ctx.cr0.gt) goto loc_881098C4;
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r10,60(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// li r9,1
	ctx.r9.s64 = 1;
	// rlwinm r11,r11,0,23,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x1E0;
	// stw r8,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r8.u32);
	// li r7,2
	ctx.r7.s64 = 2;
	// stw r9,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r9.u32);
	// li r6,48
	ctx.r6.s64 = 48;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stw r8,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r8.u32);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// stw r7,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r7.u32);
	// stw r9,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r9.u32);
	// stw r6,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r6.u32);
	// beq cr6,0x881098c4
	if (ctx.cr6.eq) goto loc_881098C4;
	// li r9,32
	ctx.r9.s64 = 32;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// stw r9,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r9.u32);
	// bge cr6,0x881098c4
	if (!ctx.cr6.lt) goto loc_881098C4;
	// li r11,-32
	ctx.r11.s64 = -32;
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
loc_881098C4:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88095590
	ctx.lr = 0x881098D4;
	sub_88095590(ctx, base);
	// li r5,8
	ctx.r5.s64 = 8;
	// lwz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// bl 0x88153010
	ctx.lr = 0x881098E0;
	sub_88153010(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_881098F0:
	// lwz r8,92(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x88109988
	if (!ctx.cr6.eq) goto loc_88109988;
	// lwz r6,80(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq cr6,0x88109988
	if (ctx.cr6.eq) goto loc_88109988;
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// bgt 0x88109a04
	if (ctx.cr0.gt) goto loc_88109A04;
	// lwz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// lis r10,-30680
	ctx.r10.s64 = -2010644480;
	// lwz r9,40(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// srawi r5,r8,4
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xF) != 0);
	ctx.r5.s64 = ctx.r8.s32 >> 4;
	// addi r10,r10,14736
	ctx.r10.s64 = ctx.r10.s64 + 14736;
	// stw r6,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r6.u32);
	// addze r3,r5
	temp.s64 = ctx.r5.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r3.s64 = temp.s64;
	// addi r6,r10,4
	ctx.r6.s64 = ctx.r10.s64 + 4;
	// rlwinm r5,r3,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r9,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r9.u32);
	// lwz r9,88(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 88);
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r5,r10
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r10.u32);
	// lis r3,-30683
	ctx.r3.s64 = -2010841088;
	// lwzx r10,r5,r6
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r6.u32);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r3,r3,12112
	ctx.r3.s64 = ctx.r3.s64 + 12112;
	// add r5,r9,r4
	ctx.r5.u64 = ctx.r9.u64 + ctx.r4.u64;
	// lwzx r7,r7,r3
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r3.u32);
	// cmpw cr6,r11,r7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r7.s32, ctx.xer);
	// ble cr6,0x88109a04
	if (!ctx.cr6.gt) goto loc_88109A04;
	// li r7,6
	ctx.r7.s64 = 6;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x881093e0
	ctx.lr = 0x88109980;
	sub_881093E0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_88109988:
	// cmpwi cr6,r10,56
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 56, ctx.xer);
	// bge cr6,0x881099b0
	if (!ctx.cr6.lt) goto loc_881099B0;
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// bge 0x881099b0
	if (!ctx.cr0.lt) goto loc_881099B0;
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// stw r10,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r10.u32);
	// stw r11,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
loc_881099B0:
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88109a04
	if (!ctx.cr6.eq) goto loc_88109A04;
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// bge 0x88109a04
	if (!ctx.cr0.lt) goto loc_88109A04;
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r8,60(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// rlwinm r7,r9,0,23,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1E0;
	// rotlwi r6,r7,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// stw r7,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r7.u32);
	// rotlwi r5,r7,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// stw r10,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r10.u32);
	// cmpw cr6,r8,r6
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r6.s32, ctx.xer);
	// stw r5,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r5.u32);
	// bne cr6,0x88109a04
	if (!ctx.cr6.eq) goto loc_88109A04;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
loc_88109A04:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88109A0C"))) PPC_WEAK_FUNC(sub_88109A0C);
PPC_FUNC_IMPL(__imp__sub_88109A0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88109A10"))) PPC_WEAK_FUNC(sub_88109A10);
PPC_FUNC_IMPL(__imp__sub_88109A10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88109A18;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x88109218
	ctx.lr = 0x88109A2C;
	sub_88109218(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x88109b9c
	if (ctx.cr6.eq) goto loc_88109B9C;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26272(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26272);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88109b9c
	if (!ctx.cr6.eq) goto loc_88109B9C;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lis r9,-30714
	ctx.r9.s64 = -2012872704;
	// lwz r10,104(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// lis r30,-30597
	ctx.r30.s64 = -2005204992;
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// lwz r7,16(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r6,r9,9552
	ctx.r6.s64 = ctx.r9.s64 + 9552;
	// lwz r4,132(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// addi r5,r11,128
	ctx.r5.s64 = ctx.r11.s64 + 128;
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r5,2,21,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x7FC;
	// lwz r11,-11984(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -11984);
	// addi r5,r10,51
	ctx.r5.s64 = ctx.r10.s64 + 51;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmpwi cr6,r4,1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 1, ctx.xer);
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r3,r6
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r6.u32);
	// lwzx r6,r9,r6
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r6.u32);
	// mullw r9,r3,r7
	ctx.r9.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r7.s32);
	// mullw r7,r6,r7
	ctx.r7.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r7.s32);
	// add r3,r9,r10
	ctx.r3.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r5,r7,r8
	ctx.r5.u64 = ctx.r7.u64 + ctx.r8.u64;
	// rotlwi r10,r3,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// stw r5,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r5.u32);
	// lwzx r11,r4,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r11.u32);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r4,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r4.u32);
	// beq cr6,0x88109b78
	if (ctx.cr6.eq) goto loc_88109B78;
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88109b78
	if (!ctx.cr6.eq) goto loc_88109B78;
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// bgt 0x88109b78
	if (ctx.cr0.gt) goto loc_88109B78;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,26424(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26424);
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// rlwinm r8,r9,28,4,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 28) & 0xFFFFFFF;
	// subfic r7,r8,132
	ctx.xer.ca = ctx.r8.u32 <= 132;
	ctx.r7.s64 = 132 - ctx.r8.s64;
	// stw r7,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r7.u32);
	// bl 0x88095590
	ctx.lr = 0x88109AFC;
	sub_88095590(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x88109b78
	if (ctx.cr6.lt) goto loc_88109B78;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26276(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88109b78
	if (!ctx.cr6.eq) goto loc_88109B78;
	// srawi r11,r3,4
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xF) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 4;
	// lwz r9,-11984(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + -11984);
	// lis r6,-30680
	ctx.r6.s64 = -2010644480;
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addze r5,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r5.s64 = temp.s64;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r11,r6,14736
	ctx.r11.s64 = ctx.r6.s64 + 14736;
	// rlwinm r6,r5,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r3,88(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 88);
	// lis r4,-30683
	ctx.r4.s64 = -2010841088;
	// addi r5,r11,4
	ctx.r5.s64 = ctx.r11.s64 + 4;
	// addi r4,r4,12112
	ctx.r4.s64 = ctx.r4.s64 + 12112;
	// rlwinm r3,r3,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r6,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r11.u32);
	// lwzx r11,r6,r5
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r5.u32);
	// add r5,r9,r7
	ctx.r5.u64 = ctx.r9.u64 + ctx.r7.u64;
	// lwzx r9,r3,r4
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r4.u32);
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// ble cr6,0x88109b78
	if (!ctx.cr6.gt) goto loc_88109B78;
	// li r7,6
	ctx.r7.s64 = 6;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x881093e0
	ctx.lr = 0x88109B78;
	sub_881093E0(ctx, base);
loc_88109B78:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88095590
	ctx.lr = 0x88109B88;
	sub_88095590(ctx, base);
	// li r5,8
	ctx.r5.s64 = 8;
	// lwz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// bl 0x88153010
	ctx.lr = 0x88109B94;
	sub_88153010(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
loc_88109B9C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88109BA4"))) PPC_WEAK_FUNC(sub_88109BA4);
PPC_FUNC_IMPL(__imp__sub_88109BA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88109BA8"))) PPC_WEAK_FUNC(sub_88109BA8);
PPC_FUNC_IMPL(__imp__sub_88109BA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88109BB0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x88109218
	ctx.lr = 0x88109BC4;
	sub_88109218(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x88109dd0
	if (ctx.cr6.eq) goto loc_88109DD0;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26272(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26272);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88109dd0
	if (!ctx.cr6.eq) goto loc_88109DD0;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lis r9,-30714
	ctx.r9.s64 = -2012872704;
	// lwz r10,104(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// lis r30,-30597
	ctx.r30.s64 = -2005204992;
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// addi r6,r9,9552
	ctx.r6.s64 = ctx.r9.s64 + 9552;
	// lwz r7,16(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r5,r11,128
	ctx.r5.s64 = ctx.r11.s64 + 128;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// rlwinm r5,r5,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x7FC;
	// lwz r11,-11984(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -11984);
	// addi r10,r10,51
	ctx.r10.s64 = ctx.r10.s64 + 51;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// rlwinm r3,r10,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r4,r6
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r6.u32);
	// lwzx r6,r5,r6
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r6.u32);
	// mullw r10,r10,r7
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32);
	// mullw r7,r6,r7
	ctx.r7.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r7.s32);
	// add r4,r10,r9
	ctx.r4.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r5,r7,r8
	ctx.r5.u64 = ctx.r7.u64 + ctx.r8.u64;
	// rotlwi r10,r4,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r4.u32, 0);
	// stw r4,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r4.u32);
	// stw r5,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r5.u32);
	// lwzx r11,r3,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r11.u32);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r4,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r4.u32);
	// bne cr6,0x88109cfc
	if (!ctx.cr6.eq) goto loc_88109CFC;
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// bgt 0x88109cfc
	if (ctx.cr0.gt) goto loc_88109CFC;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,26424(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26424);
	// rlwinm r10,r11,29,4,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0xFFFFFFF;
	// subfic r9,r10,38
	ctx.xer.ca = ctx.r10.u32 <= 38;
	ctx.r9.s64 = 38 - ctx.r10.s64;
	// stw r9,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r9.u32);
	// bl 0x88095590
	ctx.lr = 0x88109C80;
	sub_88095590(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x88109cfc
	if (ctx.cr6.lt) goto loc_88109CFC;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26276(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88109cfc
	if (!ctx.cr6.eq) goto loc_88109CFC;
	// srawi r11,r3,4
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xF) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 4;
	// lwz r9,-11984(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + -11984);
	// lis r6,-30680
	ctx.r6.s64 = -2010644480;
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addze r5,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r5.s64 = temp.s64;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r11,r6,14736
	ctx.r11.s64 = ctx.r6.s64 + 14736;
	// rlwinm r6,r5,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r3,88(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 88);
	// lis r4,-30683
	ctx.r4.s64 = -2010841088;
	// addi r5,r11,4
	ctx.r5.s64 = ctx.r11.s64 + 4;
	// addi r4,r4,12112
	ctx.r4.s64 = ctx.r4.s64 + 12112;
	// rlwinm r3,r3,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r6,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r11.u32);
	// lwzx r11,r6,r5
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r5.u32);
	// add r5,r9,r7
	ctx.r5.u64 = ctx.r9.u64 + ctx.r7.u64;
	// lwzx r9,r3,r4
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r4.u32);
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// ble cr6,0x88109cfc
	if (!ctx.cr6.gt) goto loc_88109CFC;
	// li r7,6
	ctx.r7.s64 = 6;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x881093e0
	ctx.lr = 0x88109CFC;
	sub_881093E0(ctx, base);
loc_88109CFC:
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88109d68
	if (!ctx.cr6.eq) goto loc_88109D68;
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// bge 0x88109dac
	if (!ctx.cr0.lt) goto loc_88109DAC;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// addic. r11,r11,-2
	ctx.xer.ca = ctx.r11.u32 > 1;
	ctx.r11.s64 = ctx.r11.s64 + -2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// stw r10,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r10.u32);
	// bgt 0x88109dac
	if (ctx.cr0.gt) goto loc_88109DAC;
	// lwz r9,60(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// li r11,48
	ctx.r11.s64 = 48;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// li r7,2
	ctx.r7.s64 = 2;
	// stw r10,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r10.u32);
	// li r6,8
	ctx.r6.s64 = 8;
	// stw r8,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r8.u32);
	// stw r7,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r7.u32);
	// stw r6,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r6.u32);
	// stw r9,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// b 0x88109da8
	goto loc_88109DA8;
loc_88109D68:
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88109d80
	if (ctx.cr6.eq) goto loc_88109D80;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// b 0x88109dac
	goto loc_88109DAC;
loc_88109D80:
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmpwi cr6,r10,64
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 64, ctx.xer);
	// beq cr6,0x88109dac
	if (ctx.cr6.eq) goto loc_88109DAC;
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// bge 0x88109dac
	if (!ctx.cr0.lt) goto loc_88109DAC;
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r11,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
loc_88109DA8:
	// stw r10,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r10.u32);
loc_88109DAC:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x88095590
	ctx.lr = 0x88109DBC;
	sub_88095590(ctx, base);
	// li r5,8
	ctx.r5.s64 = 8;
	// lwz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// bl 0x88153010
	ctx.lr = 0x88109DC8;
	sub_88153010(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
loc_88109DD0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88109DD8"))) PPC_WEAK_FUNC(sub_88109DD8);
PPC_FUNC_IMPL(__imp__sub_88109DD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88109DE0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x88109218
	ctx.lr = 0x88109DF4;
	sub_88109218(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8810a05c
	if (ctx.cr6.eq) goto loc_8810A05C;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26272(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26272);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8810a05c
	if (!ctx.cr6.eq) goto loc_8810A05C;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lis r8,-30714
	ctx.r8.s64 = -2012872704;
	// lwz r9,104(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// lis r30,-30597
	ctx.r30.s64 = -2005204992;
	// clrlwi r10,r11,23
	ctx.r10.u64 = ctx.r11.u32 & 0x1FF;
	// lwz r3,76(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// addi r6,r8,9552
	ctx.r6.s64 = ctx.r8.s64 + 9552;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r5,r10,128
	ctx.r5.s64 = ctx.r10.s64 + 128;
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// rlwinm r4,r10,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,12(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// rlwinm r5,r5,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x7FC;
	// lwz r10,-11984(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -11984);
	// addi r9,r9,51
	ctx.r9.s64 = ctx.r9.s64 + 51;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// rlwinm r3,r9,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r4,r6
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r6.u32);
	// lwzx r6,r5,r6
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r6.u32);
	// mullw r9,r9,r11
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// mullw r6,r6,r11
	ctx.r6.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r11.s32);
	// add r4,r9,r8
	ctx.r4.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r5,r6,r7
	ctx.r5.u64 = ctx.r6.u64 + ctx.r7.u64;
	// rotlwi r9,r4,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r4.u32, 0);
	// stw r4,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r4.u32);
	// stw r5,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r5.u32);
	// lwzx r10,r3,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r10.u32);
	// add r4,r9,r10
	ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r4,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r4.u32);
	// bne cr6,0x88109fd4
	if (!ctx.cr6.eq) goto loc_88109FD4;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88109ed8
	if (ctx.cr6.eq) goto loc_88109ED8;
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r10.u32);
	// bge 0x88109ed8
	if (!ctx.cr0.lt) goto loc_88109ED8;
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// addic. r11,r11,-2
	ctx.xer.ca = ctx.r11.u32 > 1;
	ctx.r11.s64 = ctx.r11.s64 + -2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// stw r10,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r10.u32);
	// bgt 0x88109ed8
	if (ctx.cr0.gt) goto loc_88109ED8;
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,16
	ctx.r8.s64 = 16;
	// stw r10,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r10.u32);
	// li r7,48
	ctx.r7.s64 = 48;
	// stw r9,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r9.u32);
	// stw r8,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r8.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stw r7,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r7.u32);
loc_88109ED8:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88095590
	ctx.lr = 0x88109EE0;
	sub_88095590(ctx, base);
	// li r5,8
	ctx.r5.s64 = 8;
	// lwz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// bl 0x88153010
	ctx.lr = 0x88109EEC;
	sub_88153010(ctx, base);
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// clrlwi r10,r3,16
	ctx.r10.u64 = ctx.r3.u32 & 0xFFFF;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// bne cr6,0x88109f10
	if (!ctx.cr6.eq) goto loc_88109F10;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_88109F10:
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8810a05c
	if (!ctx.cr6.eq) goto loc_8810A05C;
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// bge 0x8810a05c
	if (!ctx.cr0.lt) goto loc_8810A05C;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,26424(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26424);
	// rlwinm r10,r11,29,4,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0xFFFFFFF;
	// subfic r9,r10,38
	ctx.xer.ca = ctx.r10.u32 <= 38;
	ctx.r9.s64 = 38 - ctx.r10.s64;
	// stw r9,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r9.u32);
	// bl 0x88095590
	ctx.lr = 0x88109F50;
	sub_88095590(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8810a05c
	if (ctx.cr6.lt) goto loc_8810A05C;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26276(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8810a05c
	if (!ctx.cr6.eq) goto loc_8810A05C;
	// srawi r11,r3,4
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xF) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 4;
	// lwz r9,-11984(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + -11984);
	// lis r6,-30680
	ctx.r6.s64 = -2010644480;
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addze r5,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r5.s64 = temp.s64;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r11,r6,14736
	ctx.r11.s64 = ctx.r6.s64 + 14736;
	// rlwinm r6,r5,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r3,88(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 88);
	// lis r4,-30683
	ctx.r4.s64 = -2010841088;
	// addi r5,r11,4
	ctx.r5.s64 = ctx.r11.s64 + 4;
	// addi r4,r4,12112
	ctx.r4.s64 = ctx.r4.s64 + 12112;
	// rlwinm r3,r3,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r6,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r11.u32);
	// lwzx r11,r6,r5
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r5.u32);
	// add r5,r9,r7
	ctx.r5.u64 = ctx.r9.u64 + ctx.r7.u64;
	// lwzx r9,r3,r4
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r4.u32);
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// ble cr6,0x8810a05c
	if (!ctx.cr6.gt) goto loc_8810A05C;
	// li r7,12
	ctx.r7.s64 = 12;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x881093e0
	ctx.lr = 0x88109FCC;
	sub_881093E0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_88109FD4:
	// cmpwi cr6,r11,64
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 64, ctx.xer);
	// bge cr6,0x88109ffc
	if (!ctx.cr6.lt) goto loc_88109FFC;
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r10.u32);
	// bge 0x88109ffc
	if (!ctx.cr0.lt) goto loc_88109FFC;
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// addi r9,r11,2
	ctx.r9.s64 = ctx.r11.s64 + 2;
	// stw r9,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r9.u32);
	// stw r10,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r10.u32);
loc_88109FFC:
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8810a05c
	if (ctx.cr6.eq) goto loc_8810A05C;
	// lwz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r10.u32);
	// bge 0x8810a05c
	if (!ctx.cr0.lt) goto loc_8810A05C;
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r9,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r9.u32);
	// stw r10,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r10.u32);
	// bl 0x88095590
	ctx.lr = 0x8810A030;
	sub_88095590(ctx, base);
	// li r5,8
	ctx.r5.s64 = 8;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// bl 0x88153010
	ctx.lr = 0x8810A040;
	sub_88153010(ctx, base);
	// clrlwi r7,r3,16
	ctx.r7.u64 = ctx.r3.u32 & 0xFFFF;
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// lwz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// stw r7,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r7.u32);
	// bl 0x88153010
	ctx.lr = 0x8810A054;
	sub_88153010(ctx, base);
	// clrlwi r6,r3,16
	ctx.r6.u64 = ctx.r3.u32 & 0xFFFF;
	// stw r6,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r6.u32);
loc_8810A05C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810A064"))) PPC_WEAK_FUNC(sub_8810A064);
PPC_FUNC_IMPL(__imp__sub_8810A064) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810A068"))) PPC_WEAK_FUNC(sub_8810A068);
PPC_FUNC_IMPL(__imp__sub_8810A068) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x8810A070;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x88109218
	ctx.lr = 0x8810A084;
	sub_88109218(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8810a304
	if (ctx.cr6.eq) goto loc_8810A304;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26272(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26272);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8810a304
	if (!ctx.cr6.eq) goto loc_8810A304;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lis r7,-30714
	ctx.r7.s64 = -2012872704;
	// lwz r8,104(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// lis r30,-30597
	ctx.r30.s64 = -2005204992;
	// clrlwi r9,r10,23
	ctx.r9.u64 = ctx.r10.u32 & 0x1FF;
	// lwz r28,76(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// addi r5,r7,9552
	ctx.r5.s64 = ctx.r7.s64 + 9552;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r4,r9,128
	ctx.r4.s64 = ctx.r9.s64 + 128;
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// rlwinm r3,r10,2,21,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0x7FC;
	// lwz r6,12(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// rlwinm r4,r4,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x7FC;
	// lwz r9,-11984(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + -11984);
	// addi r8,r8,51
	ctx.r8.s64 = ctx.r8.s64 + 51;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// rlwinm r28,r8,2,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r3,r5
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r5.u32);
	// lwzx r5,r4,r5
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r5.u32);
	// mullw r8,r3,r11
	ctx.r8.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r11.s32);
	// mullw r5,r5,r11
	ctx.r5.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r11.s32);
	// add r4,r8,r7
	ctx.r4.u64 = ctx.r8.u64 + ctx.r7.u64;
	// add r5,r5,r6
	ctx.r5.u64 = ctx.r5.u64 + ctx.r6.u64;
	// rotlwi r8,r4,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r4.u32, 0);
	// stw r4,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r4.u32);
	// stw r5,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r5.u32);
	// lwzx r9,r28,r9
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + ctx.r9.u32);
	// add r4,r8,r9
	ctx.r4.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stw r4,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r4.u32);
	// bne cr6,0x8810a288
	if (!ctx.cr6.eq) goto loc_8810A288;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8810a18c
	if (ctx.cr6.eq) goto loc_8810A18C;
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r10.u32);
	// bge 0x8810a18c
	if (!ctx.cr0.lt) goto loc_8810A18C;
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// addic. r11,r11,-2
	ctx.xer.ca = ctx.r11.u32 > 1;
	ctx.r11.s64 = ctx.r11.s64 + -2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// stw r10,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r10.u32);
	// bgt 0x8810a18c
	if (ctx.cr0.gt) goto loc_8810A18C;
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r10,60(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// li r8,3
	ctx.r8.s64 = 3;
	// li r7,16
	ctx.r7.s64 = 16;
	// stw r9,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r9.u32);
	// li r6,48
	ctx.r6.s64 = 48;
	// stw r8,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r8.u32);
	// stw r7,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r7.u32);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stw r6,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r6.u32);
	// beq cr6,0x8810a18c
	if (ctx.cr6.eq) goto loc_8810A18C;
	// li r9,32
	ctx.r9.s64 = 32;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// stw r9,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r9.u32);
	// bge cr6,0x8810a18c
	if (!ctx.cr6.lt) goto loc_8810A18C;
	// li r11,-32
	ctx.r11.s64 = -32;
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
loc_8810A18C:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88095590
	ctx.lr = 0x8810A194;
	sub_88095590(ctx, base);
	// li r5,8
	ctx.r5.s64 = 8;
	// lwz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// bl 0x88153010
	ctx.lr = 0x8810A1A0;
	sub_88153010(ctx, base);
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// clrlwi r10,r3,16
	ctx.r10.u64 = ctx.r3.u32 & 0xFFFF;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// bne cr6,0x8810a1c4
	if (!ctx.cr6.eq) goto loc_8810A1C4;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8810A1C4:
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8810a304
	if (!ctx.cr6.eq) goto loc_8810A304;
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// bge 0x8810a304
	if (!ctx.cr0.lt) goto loc_8810A304;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,26424(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26424);
	// rlwinm r10,r11,29,4,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0xFFFFFFF;
	// subfic r9,r10,38
	ctx.xer.ca = ctx.r10.u32 <= 38;
	ctx.r9.s64 = 38 - ctx.r10.s64;
	// stw r9,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r9.u32);
	// bl 0x88095590
	ctx.lr = 0x8810A204;
	sub_88095590(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8810a304
	if (ctx.cr6.lt) goto loc_8810A304;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26276(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8810a304
	if (!ctx.cr6.eq) goto loc_8810A304;
	// srawi r10,r3,4
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xF) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 4;
	// lwz r9,-11984(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + -11984);
	// lis r6,-30680
	ctx.r6.s64 = -2010644480;
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addze r5,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r5.s64 = temp.s64;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r6,14736
	ctx.r10.s64 = ctx.r6.s64 + 14736;
	// rlwinm r6,r5,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r3,88(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 88);
	// lis r4,-30683
	ctx.r4.s64 = -2010841088;
	// addi r5,r10,4
	ctx.r5.s64 = ctx.r10.s64 + 4;
	// addi r4,r4,12112
	ctx.r4.s64 = ctx.r4.s64 + 12112;
	// rlwinm r3,r3,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r6,r10
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// lwzx r10,r6,r5
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r5.u32);
	// add r5,r9,r7
	ctx.r5.u64 = ctx.r9.u64 + ctx.r7.u64;
	// lwzx r9,r3,r4
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r4.u32);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// ble cr6,0x8810a304
	if (!ctx.cr6.gt) goto loc_8810A304;
	// li r7,12
	ctx.r7.s64 = 12;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x881093e0
	ctx.lr = 0x8810A280;
	sub_881093E0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8810A288:
	// cmpwi cr6,r11,56
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 56, ctx.xer);
	// bge cr6,0x8810a2b0
	if (!ctx.cr6.lt) goto loc_8810A2B0;
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r9,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r9.u32);
	// bge 0x8810a2b0
	if (!ctx.cr0.lt) goto loc_8810A2B0;
	// lwz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// addi r8,r11,2
	ctx.r8.s64 = ctx.r11.s64 + 2;
	// stw r8,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r8.u32);
	// stw r9,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r9.u32);
loc_8810A2B0:
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8810a304
	if (!ctx.cr6.eq) goto loc_8810A304;
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// bge 0x8810a304
	if (!ctx.cr0.lt) goto loc_8810A304;
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r7,60(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// rlwinm r6,r8,0,23,26
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x1E0;
	// rotlwi r5,r6,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// stw r6,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r6.u32);
	// rotlwi r4,r6,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// stw r9,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r9.u32);
	// cmpw cr6,r7,r5
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r5.s32, ctx.xer);
	// stw r4,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r4.u32);
	// bne cr6,0x8810a304
	if (!ctx.cr6.eq) goto loc_8810A304;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
loc_8810A304:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810A30C"))) PPC_WEAK_FUNC(sub_8810A30C);
PPC_FUNC_IMPL(__imp__sub_8810A30C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810A310"))) PPC_WEAK_FUNC(sub_8810A310);
PPC_FUNC_IMPL(__imp__sub_8810A310) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x8810A318;
	__savegprlr_27(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x88109218
	ctx.lr = 0x8810A32C;
	sub_88109218(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8810a530
	if (ctx.cr6.eq) goto loc_8810A530;
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// lwz r7,16(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lis r6,-30643
	ctx.r6.s64 = -2008219648;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r30,r11,9552
	ctx.r30.s64 = ctx.r11.s64 + 9552;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r27,0
	ctx.r27.s64 = 0;
	// clrlwi r10,r11,23
	ctx.r10.u64 = ctx.r11.u32 & 0x1FF;
	// rlwinm r5,r11,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x7FC;
	// addi r4,r10,128
	ctx.r4.s64 = ctx.r10.s64 + 128;
	// lwz r10,26272(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 26272);
	// lis r29,-30597
	ctx.r29.s64 = -2005204992;
	// rlwinm r3,r4,2,21,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x7FC;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwzx r10,r5,r30
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r30.u32);
	// mullw r10,r10,r7
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32);
	// lwzx r6,r3,r30
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r30.u32);
	// mullw r7,r6,r7
	ctx.r7.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r7.s32);
	// add r4,r10,r9
	ctx.r4.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r5,r7,r8
	ctx.r5.u64 = ctx.r7.u64 + ctx.r8.u64;
	// stw r4,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r4.u32);
	// stw r5,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r5.u32);
	// beq cr6,0x8810a39c
	if (ctx.cr6.eq) goto loc_8810A39C;
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// b 0x8810a3b0
	goto loc_8810A3B0;
loc_8810A39C:
	// lwz r9,104(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// lwz r10,-11984(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + -11984);
	// addi r9,r9,51
	ctx.r9.s64 = ctx.r9.s64 + 51;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r8,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
loc_8810A3B0:
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r8,52(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// add r4,r9,r10
	ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stw r4,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r4.u32);
	// beq cr6,0x8810a530
	if (ctx.cr6.eq) goto loc_8810A530;
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8810a530
	if (ctx.cr6.eq) goto loc_8810A530;
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// bge 0x8810a420
	if (!ctx.cr0.lt) goto loc_8810A420;
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// bl 0x88095590
	ctx.lr = 0x8810A3F8;
	sub_88095590(ctx, base);
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// bl 0x88153010
	ctx.lr = 0x8810A404;
	sub_88153010(ctx, base);
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// clrlwi r9,r3,16
	ctx.r9.u64 = ctx.r3.u32 & 0xFFFF;
	// addic. r11,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r11.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r9,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// bgt 0x8810a420
	if (ctx.cr0.gt) goto loc_8810A420;
	// stw r27,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r27.u32);
loc_8810A420:
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8810a530
	if (!ctx.cr6.eq) goto loc_8810A530;
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// bge 0x8810a530
	if (!ctx.cr0.lt) goto loc_8810A530;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,26424(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26424);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r9,r10,29,4,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0xFFFFFFF;
	// subfic r8,r9,132
	ctx.xer.ca = ctx.r9.u32 <= 132;
	ctx.r8.s64 = 132 - ctx.r9.s64;
	// stw r8,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r8.u32);
	// bl 0x88095590
	ctx.lr = 0x8810A468;
	sub_88095590(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8810a530
	if (ctx.cr6.lt) goto loc_8810A530;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26276(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8810a530
	if (!ctx.cr6.eq) goto loc_8810A530;
	// lwz r11,-11984(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -11984);
	// lis r10,-30683
	ctx.r10.s64 = -2010841088;
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r9,r10,12112
	ctx.r9.s64 = ctx.r10.s64 + 12112;
	// lwz r7,88(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r6,r9
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// cmpw cr6,r8,r5
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r5.s32, ctx.xer);
	// ble cr6,0x8810a530
	if (!ctx.cr6.gt) goto loc_8810A530;
	// clrlwi r11,r3,23
	ctx.r11.u64 = ctx.r3.u32 & 0x1FF;
	// lwz r7,132(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// rlwinm r10,r3,2,21,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x7FC;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r6,r11,128
	ctx.r6.s64 = ctx.r11.s64 + 128;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// sth r27,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r27.u16);
	// rlwinm r5,r6,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// clrlwi r7,r3,16
	ctx.r7.u64 = ctx.r3.u32 & 0xFFFF;
	// lwzx r4,r10,r30
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r30.u32);
	// li r6,8
	ctx.r6.s64 = 8;
	// li r3,15
	ctx.r3.s64 = 15;
	// mulli r10,r4,120
	ctx.r10.s64 = ctx.r4.s64 * 120;
	// lwzx r11,r5,r30
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r30.u32);
	// mulli r11,r11,120
	ctx.r11.s64 = ctx.r11.s64 * 120;
	// add r4,r10,r9
	ctx.r4.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r5,r11,r8
	ctx.r5.u64 = ctx.r11.u64 + ctx.r8.u64;
	// bne cr6,0x8810a504
	if (!ctx.cr6.eq) goto loc_8810A504;
	// bl 0x8815c948
	ctx.lr = 0x8810A4F4;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x8810A4FC;
	sub_8815C860(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_8810A504:
	// bl 0x8815c948
	ctx.lr = 0x8810A508;
	sub_8815C948(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810a528
	if (ctx.cr6.eq) goto loc_8810A528;
	// li r11,2
	ctx.r11.s64 = 2;
	// li r10,3
	ctx.r10.s64 = 3;
	// li r9,24
	ctx.r9.s64 = 24;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r11.u8);
	// sth r10,18(r3)
	PPC_STORE_U16(ctx.r3.u32 + 18, ctx.r10.u16);
	// sth r9,20(r3)
	PPC_STORE_U16(ctx.r3.u32 + 20, ctx.r9.u16);
loc_8810A528:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x8810A530;
	sub_8815C860(ctx, base);
loc_8810A530:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810A538"))) PPC_WEAK_FUNC(sub_8810A538);
PPC_FUNC_IMPL(__imp__sub_8810A538) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x8810A540;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x88109218
	ctx.lr = 0x8810A554;
	sub_88109218(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8810a6e8
	if (ctx.cr6.eq) goto loc_8810A6E8;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lis r8,-30714
	ctx.r8.s64 = -2012872704;
	// lis r7,-30643
	ctx.r7.s64 = -2008219648;
	// lwz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// clrlwi r10,r11,23
	ctx.r10.u64 = ctx.r11.u32 & 0x1FF;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r5,r8,9552
	ctx.r5.s64 = ctx.r8.s64 + 9552;
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r4,r10,128
	ctx.r4.s64 = ctx.r10.s64 + 128;
	// rlwinm r3,r11,2,21,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x7FC;
	// rlwinm r4,r4,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x7FC;
	// lwz r10,26272(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 26272);
	// lis r30,-30597
	ctx.r30.s64 = -2005204992;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwzx r3,r3,r5
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r5.u32);
	// lwzx r7,r4,r5
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r5.u32);
	// mullw r10,r3,r6
	ctx.r10.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r6.s32);
	// mullw r7,r7,r6
	ctx.r7.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r6.s32);
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r5,r7,r8
	ctx.r5.u64 = ctx.r7.u64 + ctx.r8.u64;
	// stw r6,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// stw r5,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r5.u32);
	// beq cr6,0x8810a5c0
	if (ctx.cr6.eq) goto loc_8810A5C0;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x8810a5d4
	goto loc_8810A5D4;
loc_8810A5C0:
	// lwz r9,104(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// lwz r10,-11984(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -11984);
	// addi r9,r9,51
	ctx.r9.s64 = ctx.r9.s64 + 51;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r8,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
loc_8810A5D4:
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// add r4,r9,r10
	ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addic. r11,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r11.s64 = ctx.r8.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r4,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r4.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// bge 0x8810a698
	if (!ctx.cr0.lt) goto loc_8810A698;
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8810a698
	if (!ctx.cr6.eq) goto loc_8810A698;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,26424(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26424);
	// rlwinm r10,r11,29,4,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0xFFFFFFF;
	// subfic r9,r10,38
	ctx.xer.ca = ctx.r10.u32 <= 38;
	ctx.r9.s64 = 38 - ctx.r10.s64;
	// stw r9,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r9.u32);
	// bl 0x88095590
	ctx.lr = 0x8810A61C;
	sub_88095590(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8810a698
	if (ctx.cr6.lt) goto loc_8810A698;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26276(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8810a698
	if (!ctx.cr6.eq) goto loc_8810A698;
	// srawi r11,r3,4
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xF) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 4;
	// lwz r9,-11984(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + -11984);
	// lis r6,-30680
	ctx.r6.s64 = -2010644480;
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addze r5,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r5.s64 = temp.s64;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r11,r6,14736
	ctx.r11.s64 = ctx.r6.s64 + 14736;
	// rlwinm r6,r5,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r3,88(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 88);
	// lis r4,-30683
	ctx.r4.s64 = -2010841088;
	// addi r5,r11,4
	ctx.r5.s64 = ctx.r11.s64 + 4;
	// addi r4,r4,12112
	ctx.r4.s64 = ctx.r4.s64 + 12112;
	// rlwinm r3,r3,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r6,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r11.u32);
	// lwzx r11,r6,r5
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r5.u32);
	// add r5,r9,r7
	ctx.r5.u64 = ctx.r9.u64 + ctx.r7.u64;
	// lwzx r9,r3,r4
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r4.u32);
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// ble cr6,0x8810a698
	if (!ctx.cr6.gt) goto loc_8810A698;
	// li r7,12
	ctx.r7.s64 = 12;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x881093e0
	ctx.lr = 0x8810A698;
	sub_881093E0(ctx, base);
loc_8810A698:
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// bge 0x8810a6e8
	if (!ctx.cr0.lt) goto loc_8810A6E8;
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8810a6e8
	if (ctx.cr6.eq) goto loc_8810A6E8;
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// stw r9,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r9.u32);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// stw r10,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r10.u32);
	// bl 0x88095590
	ctx.lr = 0x8810A6D4;
	sub_88095590(ctx, base);
	// li r5,8
	ctx.r5.s64 = 8;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// bl 0x88153010
	ctx.lr = 0x8810A6E0;
	sub_88153010(ctx, base);
	// clrlwi r8,r3,16
	ctx.r8.u64 = ctx.r3.u32 & 0xFFFF;
	// stw r8,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r8.u32);
loc_8810A6E8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810A6F0"))) PPC_WEAK_FUNC(sub_8810A6F0);
PPC_FUNC_IMPL(__imp__sub_8810A6F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071140
	ctx.lr = 0x8810A6F8;
	__savegprlr_22(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r9,0(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// rlwinm r8,r11,0,21,21
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x400;
	// lwz r10,184(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 184);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// lwz r11,168(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 168);
	// add r23,r10,r11
	ctx.r23.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bne cr6,0x8810ab7c
	if (!ctx.cr6.eq) goto loc_8810AB7C;
	// lwz r11,108(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 108);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8810ab7c
	if (!ctx.cr6.gt) goto loc_8810AB7C;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// subf. r8,r10,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r10.s64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stw r8,108(r5)
	PPC_STORE_U32(ctx.r5.u32 + 108, ctx.r8.u32);
	// bgt 0x8810ab7c
	if (ctx.cr0.gt) goto loc_8810AB7C;
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r22,0
	ctx.r22.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8810a758
	if (!ctx.cr6.eq) goto loc_8810A758;
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// b 0x8810a75c
	goto loc_8810A75C;
loc_8810A758:
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
loc_8810A75C:
	// stw r11,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r11.u32);
	// mr r10,r22
	ctx.r10.u64 = ctx.r22.u64;
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r11,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r11.u32);
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8810a77c
	if (ctx.cr6.eq) goto loc_8810A77C;
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
loc_8810A77C:
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8810a790
	if (!ctx.cr6.eq) goto loc_8810A790;
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// b 0x8810a794
	goto loc_8810A794;
loc_8810A790:
	// lwz r11,164(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_8810A794:
	// stw r11,2328(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2328, ctx.r11.u32);
	// li r5,240
	ctx.r5.s64 = 240;
	// stw r10,2332(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2332, ctx.r10.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x88095178
	ctx.lr = 0x8810A7A8;
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
	ctx.lr = 0x8810A7BC;
	sub_880E3240(ctx, base);
	// li r3,14
	ctx.r3.s64 = 14;
	// bl 0x881534c8
	ctx.lr = 0x8810A7C4;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// addic. r11,r11,-7
	ctx.xer.ca = ctx.r11.u32 > 6;
	ctx.r11.s64 = ctx.r11.s64 + -7;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r27,r11,-4
	ctx.r27.s64 = ctx.r11.s64 + -4;
	// blt 0x8810a7d8
	if (ctx.cr0.lt) goto loc_8810A7D8;
	// addi r27,r11,4
	ctx.r27.s64 = ctx.r11.s64 + 4;
loc_8810A7D8:
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lis r29,-30667
	ctx.r29.s64 = -2009792512;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r28,-30667
	ctx.r28.s64 = -2009792512;
	// addi r30,r23,-1
	ctx.r30.s64 = ctx.r23.s64 + -1;
	// li r3,8
	ctx.r3.s64 = 8;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r11,12364(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12372, ctx.r10.u32);
	// bl 0x880f52c8
	ctx.lr = 0x8810A800;
	sub_880F52C8(ctx, base);
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// rlwinm r10,r27,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bl 0x880f5570
	ctx.lr = 0x8810A818;
	sub_880F5570(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r6,128(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// lwz r5,124(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r8,2332(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2332);
	// lwz r7,2328(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2328);
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// bl 0x880f5438
	ctx.lr = 0x8810A838;
	sub_880F5438(ctx, base);
	// li r3,63
	ctx.r3.s64 = 63;
	// bl 0x881534c8
	ctx.lr = 0x8810A840;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// li r25,2
	ctx.r25.s64 = 2;
	// addi r9,r11,-32
	ctx.r9.s64 = ctx.r11.s64 + -32;
	// lwz r8,100(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// li r24,1
	ctx.r24.s64 = 1;
	// rlwinm r11,r9,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplwi cr6,r8,3
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 3, ctx.xer);
	// add r26,r11,r10
	ctx.r26.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bne cr6,0x8810a874
	if (!ctx.cr6.eq) goto loc_8810A874;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmpwi cr6,r11,72
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 72, ctx.xer);
	// beq cr6,0x8810a904
	if (ctx.cr6.eq) goto loc_8810A904;
loc_8810A874:
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,12364(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12372, ctx.r10.u32);
	// bl 0x880f52c8
	ctx.lr = 0x8810A890;
	sub_880F52C8(ctx, base);
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// srawi r10,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 2;
	// addze r4,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r4.s64 = temp.s64;
	// bl 0x880f5570
	ctx.lr = 0x8810A8B0;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x8810a8bc
	if (ctx.cr6.eq) goto loc_8810A8BC;
	// stw r25,112(r27)
	PPC_STORE_U32(ctx.r27.u32 + 112, ctx.r25.u32);
loc_8810A8BC:
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,12364(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12372, ctx.r10.u32);
	// bl 0x880f52c8
	ctx.lr = 0x8810A8D8;
	sub_880F52C8(ctx, base);
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// bl 0x880f5570
	ctx.lr = 0x8810A8E8;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x8810a904
	if (ctx.cr6.eq) goto loc_8810A904;
	// li r11,80
	ctx.r11.s64 = 80;
	// stw r24,112(r27)
	PPC_STORE_U32(ctx.r27.u32 + 112, ctx.r24.u32);
	// stw r25,100(r27)
	PPC_STORE_U32(ctx.r27.u32 + 100, ctx.r25.u32);
	// stw r11,140(r27)
	PPC_STORE_U32(ctx.r27.u32 + 140, ctx.r11.u32);
	// stw r24,148(r27)
	PPC_STORE_U32(ctx.r27.u32 + 148, ctx.r24.u32);
loc_8810A904:
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x8810a984
	if (!ctx.cr6.lt) goto loc_8810A984;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,12364(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12372, ctx.r10.u32);
	// bl 0x880f52c8
	ctx.lr = 0x8810A92C;
	sub_880F52C8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x881534c8
	ctx.lr = 0x8810A938;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r4,24
	ctx.r4.s64 = 24;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// add r5,r11,r26
	ctx.r5.u64 = ctx.r11.u64 + ctx.r26.u64;
	// bl 0x880f5570
	ctx.lr = 0x8810A950;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8810a968
	if (ctx.cr6.eq) goto loc_8810A968;
	// li r11,48
	ctx.r11.s64 = 48;
	// stw r24,112(r30)
	PPC_STORE_U32(ctx.r30.u32 + 112, ctx.r24.u32);
	// stw r25,100(r30)
	PPC_STORE_U32(ctx.r30.u32 + 100, ctx.r25.u32);
	// stw r11,140(r30)
	PPC_STORE_U32(ctx.r30.u32 + 140, ctx.r11.u32);
loc_8810A968:
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r4,r23,-2
	ctx.r4.s64 = ctx.r23.s64 + -2;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,12364(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12372, ctx.r10.u32);
	// bl 0x880f34b0
	ctx.lr = 0x8810A984;
	sub_880F34B0(ctx, base);
loc_8810A984:
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r4,r23,-2
	ctx.r4.s64 = ctx.r23.s64 + -2;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,12364(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12372, ctx.r10.u32);
	// bl 0x880f34b0
	ctx.lr = 0x8810A9A0;
	sub_880F34B0(ctx, base);
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r26,-30667
	ctx.r26.s64 = -2009792512;
	// lis r25,-30667
	ctx.r25.s64 = -2009792512;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,12372(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12372, ctx.r10.u32);
	// stw r22,12380(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12380, ctx.r22.u32);
	// stw r4,12376(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12376, ctx.r4.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// stw r11,12364(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12364, ctx.r11.u32);
	// bl 0x880f34b0
	ctx.lr = 0x8810A9CC;
	sub_880F34B0(ctx, base);
	// lwz r11,136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 136);
	// stw r22,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r22.u32);
	// lwz r11,132(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8810aaa0
	if (!ctx.cr6.eq) goto loc_8810AAA0;
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lis r5,32
	ctx.r5.s64 = 2097152;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// bl 0x88094c70
	ctx.lr = 0x8810A9F4;
	sub_88094C70(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8810ab2c
	if (ctx.cr6.eq) goto loc_8810AB2C;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// bl 0x88095590
	ctx.lr = 0x8810AA0C;
	sub_88095590(ctx, base);
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r27,26276(r11)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// bne cr6,0x8810aa4c
	if (!ctx.cr6.eq) goto loc_8810AA4C;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// clrlwi r7,r3,16
	ctx.r7.u64 = ctx.r3.u32 & 0xFFFF;
	// li r6,-2
	ctx.r6.s64 = -2;
	// sth r22,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r22.u16);
	// li r3,29
	ctx.r3.s64 = 29;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x8815c948
	ctx.lr = 0x8810AA44;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x8810AA4C;
	sub_8815C860(ctx, base);
loc_8810AA4C:
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bne cr6,0x8810aa80
	if (!ctx.cr6.eq) goto loc_8810AA80;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// clrlwi r7,r30,16
	ctx.r7.u64 = ctx.r30.u32 & 0xFFFF;
	// li r6,1
	ctx.r6.s64 = 1;
	// sth r22,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r22.u16);
	// li r3,31
	ctx.r3.s64 = 31;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x8815c948
	ctx.lr = 0x8810AA78;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x8810AA80;
	sub_8815C860(ctx, base);
loc_8810AA80:
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bne cr6,0x8810ab2c
	if (!ctx.cr6.eq) goto loc_8810AB2C;
	// clrlwi r7,r30,16
	ctx.r7.u64 = ctx.r30.u32 & 0xFFFF;
	// li r6,4
	ctx.r6.s64 = 4;
	// li r3,32
	ctx.r3.s64 = 32;
	// b 0x8810ab14
	goto loc_8810AB14;
loc_8810AAA0:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8810ab2c
	if (!ctx.cr6.eq) goto loc_8810AB2C;
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x8810ab2c
	if (!ctx.cr6.eq) goto loc_8810AB2C;
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,4(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// cmplwi cr6,r11,22
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 22, ctx.xer);
	// bne cr6,0x8810ab2c
	if (!ctx.cr6.eq) goto loc_8810AB2C;
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lis r5,64
	ctx.r5.s64 = 4194304;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// bl 0x88094c70
	ctx.lr = 0x8810AAD8;
	sub_88094C70(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8810ab2c
	if (ctx.cr6.eq) goto loc_8810AB2C;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// bl 0x88095590
	ctx.lr = 0x8810AAF0;
	sub_88095590(ctx, base);
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,26276(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8810ab2c
	if (!ctx.cr6.eq) goto loc_8810AB2C;
	// clrlwi r7,r3,16
	ctx.r7.u64 = ctx.r3.u32 & 0xFFFF;
	// li r6,-20
	ctx.r6.s64 = -20;
	// li r3,50
	ctx.r3.s64 = 50;
loc_8810AB14:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// sth r22,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r22.u16);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x8815c948
	ctx.lr = 0x8810AB24;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x8810AB2C;
	sub_8815C860(ctx, base);
loc_8810AB2C:
	// lwz r11,124(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8810ab68
	if (!ctx.cr6.eq) goto loc_8810AB68;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r8,140
	ctx.r8.s64 = 140;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,140
	ctx.r4.s64 = 140;
	// stw r22,12380(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12380, ctx.r22.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r8,12376(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12376, ctx.r8.u32);
	// mr r9,r22
	ctx.r9.u64 = ctx.r22.u64;
	// stw r11,12364(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12372, ctx.r10.u32);
	// bl 0x881607f8
	ctx.lr = 0x8810AB68;
	sub_881607F8(ctx, base);
loc_8810AB68:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x88094220
	ctx.lr = 0x8810AB70;
	sub_88094220(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x88071190
	__restgprlr_22(ctx, base);
	return;
loc_8810AB7C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x88071190
	__restgprlr_22(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810AB88"))) PPC_WEAK_FUNC(sub_8810AB88);
PPC_FUNC_IMPL(__imp__sub_8810AB88) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x8810AB90;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// lwz r11,168(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// li r26,0
	ctx.r26.s64 = 0;
	// lwz r10,184(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// li r28,1
	ctx.r28.s64 = 1;
	// add r29,r10,r11
	ctx.r29.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// srawi r10,r11,4
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xF) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 4;
	// clrlwi r30,r10,27
	ctx.r30.u64 = ctx.r10.u32 & 0x1F;
	// cmpwi cr6,r30,16
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 16, ctx.xer);
	// blt cr6,0x8810abd4
	if (ctx.cr6.lt) goto loc_8810ABD4;
	// subfic r30,r30,32
	ctx.xer.ca = ctx.r30.u32 <= 32;
	ctx.r30.s64 = 32 - ctx.r30.s64;
	// li r26,1
	ctx.r26.s64 = 1;
	// li r28,-1
	ctx.r28.s64 = -1;
loc_8810ABD4:
	// lis r11,-30680
	ctx.r11.s64 = -2010644480;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// rlwinm r10,r30,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r11,r11,13892
	ctx.r11.s64 = ctx.r11.s64 + 13892;
	// addi r6,r29,-1
	ctx.r6.s64 = ctx.r29.s64 + -1;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// addi r3,r30,15785
	ctx.r3.s64 = ctx.r30.s64 + 15785;
	// lbzx r5,r10,r11
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r11.u32);
	// lbzx r4,r10,r7
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r7.u32);
	// extsb r11,r5
	ctx.r11.s64 = ctx.r5.s8;
	// extsb r10,r4
	ctx.r10.s64 = ctx.r4.s8;
	// mullw r11,r11,r28
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// addi r5,r10,-88
	ctx.r5.s64 = ctx.r10.s64 + -88;
	// addi r7,r11,24
	ctx.r7.s64 = ctx.r11.s64 + 24;
	// rlwinm r10,r5,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r7,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// add r5,r10,r8
	ctx.r5.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r4,r11,r9
	ctx.r4.u64 = ctx.r11.u64 + ctx.r9.u64;
	// bl 0x881538c0
	ctx.lr = 0x8810AC24;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810ac50
	if (ctx.cr6.eq) goto loc_8810AC50;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r8,r26,26,0,5
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 26) & 0xFC000000;
	// or r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 | ctx.r9.u64;
	// lwz r11,-11932(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11932);
	// oris r6,r7,518
	ctx.r6.u64 = ctx.r7.u64 | 33947648;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// stw r11,-11932(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11932, ctx.r11.u32);
loc_8810AC50:
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r4,140(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// addi r9,r11,-256
	ctx.r9.s64 = ctx.r11.s64 + -256;
	// addi r8,r10,9552
	ctx.r8.s64 = ctx.r10.s64 + 9552;
	// clrlwi r11,r9,23
	ctx.r11.u64 = ctx.r9.u32 & 0x1FF;
	// addi r7,r11,128
	ctx.r7.s64 = ctx.r11.s64 + 128;
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r5,r7,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x7FC;
	// lwzx r11,r6,r8
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
	// lwzx r10,r5,r8
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r8.u32);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r5,r11,6,0,25
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 6) & 0xFFFFFFC0;
	// rlwinm r6,r10,6,0,25
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// bl 0x88093b38
	ctx.lr = 0x8810AC9C;
	sub_88093B38(ctx, base);
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bne cr6,0x8810ad7c
	if (!ctx.cr6.eq) goto loc_8810AD7C;
	// lwz r11,132(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8810acd4
	if (!ctx.cr6.eq) goto loc_8810ACD4;
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// lis r8,-30597
	ctx.r8.s64 = -2005204992;
	// lwz r11,-11900(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -11900);
	// lwz r10,-11904(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + -11904);
	// addi r11,r11,150
	ctx.r11.s64 = ctx.r11.s64 + 150;
	// addi r10,r10,100
	ctx.r10.s64 = ctx.r10.s64 + 100;
	// stw r11,-11900(r9)
	PPC_STORE_U32(ctx.r9.u32 + -11900, ctx.r11.u32);
	// stw r10,-11904(r8)
	PPC_STORE_U32(ctx.r8.u32 + -11904, ctx.r10.u32);
loc_8810ACD4:
	// lis r11,-30680
	ctx.r11.s64 = -2010644480;
	// lwz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r30,8(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r11,15128
	ctx.r11.s64 = ctx.r11.s64 + 15128;
	// lwz r27,12(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r11,-416
	ctx.r7.s64 = ctx.r11.s64 + -416;
	// addi r5,r11,256
	ctx.r5.s64 = ctx.r11.s64 + 256;
	// addi r11,r11,256
	ctx.r11.s64 = ctx.r11.s64 + 256;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// lwzx r11,r8,r7
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r3,r11,15206
	ctx.r3.s64 = ctx.r11.s64 + 15206;
	// lbzx r9,r10,r5
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r5.u32);
	// lbzx r8,r10,r4
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r4.u32);
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// extsb r5,r8
	ctx.r5.s64 = ctx.r8.s8;
	// mullw r4,r7,r28
	ctx.r4.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r28.s32);
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r5,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r10,r30
	ctx.r4.u64 = ctx.r10.u64 + ctx.r30.u64;
	// add r5,r11,r27
	ctx.r5.u64 = ctx.r11.u64 + ctx.r27.u64;
	// bl 0x881538c0
	ctx.lr = 0x8810AD3C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810ad5c
	if (ctx.cr6.eq) goto loc_8810AD5C;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r26,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// lwz r8,112(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
loc_8810AD5C:
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// lwz r7,112(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// addis r4,r27,8
	ctx.r4.s64 = ctx.r27.s64 + 524288;
	// lwz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88226bd8
	ctx.lr = 0x8810AD74;
	sub_88226BD8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_8810AD7C:
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// beq cr6,0x8810ae1c
	if (ctx.cr6.eq) goto loc_8810AE1C;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x8810ae1c
	if (ctx.cr6.eq) goto loc_8810AE1C;
	// lis r11,-30680
	ctx.r11.s64 = -2010644480;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// rlwinm r7,r30,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r11,r11,15128
	ctx.r11.s64 = ctx.r11.s64 + 15128;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// rlwinm r5,r10,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r4,r11,-416
	ctx.r4.s64 = ctx.r11.s64 + -416;
	// lis r3,-30680
	ctx.r3.s64 = -2010644480;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// addi r10,r3,14992
	ctx.r10.s64 = ctx.r3.s64 + 14992;
	// lwzx r11,r5,r4
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r4.u32);
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// rlwinm r4,r11,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r3,r11,9983
	ctx.r3.s64 = ctx.r11.s64 + 9983;
	// lbzx r11,r4,r10
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r10.u32);
	// lbzx r10,r4,r5
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r5.u32);
	// extsb r7,r11
	ctx.r7.s64 = ctx.r11.s8;
	// extsb r5,r10
	ctx.r5.s64 = ctx.r10.s8;
	// mullw r4,r7,r28
	ctx.r4.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r28.s32);
	// rlwinm r10,r5,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r4,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// add r5,r10,r8
	ctx.r5.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r4,r11,r9
	ctx.r4.u64 = ctx.r11.u64 + ctx.r9.u64;
	// bl 0x881538c0
	ctx.lr = 0x8810ADF4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810ae94
	if (ctx.cr6.eq) goto loc_8810AE94;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r26,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 26) & 0xFC000000;
	// lwz r11,112(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_8810AE1C:
	// lis r11,-30680
	ctx.r11.s64 = -2010644480;
	// lwz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// lwz r7,32(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// addi r11,r11,15128
	ctx.r11.s64 = ctx.r11.s64 + 15128;
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r5,r10,8
	ctx.r5.s64 = ctx.r10.s64 + 8;
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r4,r11,-416
	ctx.r4.s64 = ctx.r11.s64 + -416;
	// rlwinm r3,r7,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// srawi r10,r5,4
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xF) != 0);
	ctx.r10.s64 = ctx.r5.s32 >> 4;
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// rlwinm r10,r10,2,25,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0x7C;
	// lwzx r7,r3,r4
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r4.u32);
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// rlwinm r4,r10,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r3,r10,12145
	ctx.r3.s64 = ctx.r10.s64 + 12145;
	// lbzx r10,r4,r5
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r5.u32);
	// lbzx r11,r4,r11
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r11.u32);
	// extsb r5,r10
	ctx.r5.s64 = ctx.r10.s8;
	// extsb r7,r11
	ctx.r7.s64 = ctx.r11.s8;
	// rlwinm r11,r5,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r7,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// add r5,r11,r9
	ctx.r5.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r4,r10,r8
	ctx.r4.u64 = ctx.r10.u64 + ctx.r8.u64;
	// bl 0x881538c0
	ctx.lr = 0x8810AE84;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810ae94
	if (ctx.cr6.eq) goto loc_8810AE94;
	// lwz r11,112(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_8810AE94:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810AE9C"))) PPC_WEAK_FUNC(sub_8810AE9C);
PPC_FUNC_IMPL(__imp__sub_8810AE9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810AEA0"))) PPC_WEAK_FUNC(sub_8810AEA0);
PPC_FUNC_IMPL(__imp__sub_8810AEA0) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x881556a0
	ctx.lr = 0x8810AEC8;
	sub_881556A0(ctx, base);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r3,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r3.u32);
	// stw r7,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r7.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r11.u32);
	// lwz r9,136(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 136);
	// lwz r11,28(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8810af08
	if (ctx.cr6.eq) goto loc_8810AF08;
loc_8810AEF0:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8810af9c
	if (ctx.cr6.eq) goto loc_8810AF9C;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8810aef0
	if (!ctx.cr6.eq) goto loc_8810AEF0;
loc_8810AF08:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8810AF0C:
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// lwz r6,136(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 136);
	// lis r5,-30703
	ctx.r5.s64 = -2012151808;
	// li r10,18
	ctx.r10.s64 = 18;
	// addi r4,r5,-22800
	ctx.r4.s64 = ctx.r5.s64 + -22800;
	// addi r3,r31,8
	ctx.r3.s64 = ctx.r31.s64 + 8;
	// lwz r9,-11984(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + -11984);
	// lis r5,-30703
	ctx.r5.s64 = -2012151808;
	// stw r4,32(r6)
	PPC_STORE_U32(ctx.r6.u32 + 32, ctx.r4.u32);
	// li r8,2
	ctx.r8.s64 = 2;
	// lis r4,-30703
	ctx.r4.s64 = -2012151808;
	// stw r31,36(r6)
	PPC_STORE_U32(ctx.r6.u32 + 36, ctx.r31.u32);
	// stw r3,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r3.u32);
	// addi r6,r5,-21624
	ctx.r6.s64 = ctx.r5.s64 + -21624;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// addi r5,r4,-27744
	ctx.r5.s64 = ctx.r4.s64 + -27744;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r10,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// stw r7,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// stw r7,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r7.u32);
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// stw r8,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r8.u32);
	// stw r8,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r8.u32);
	// lwz r4,84(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 84);
	// stw r4,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r4.u32);
	// stw r6,68(r30)
	PPC_STORE_U32(ctx.r30.u32 + 68, ctx.r6.u32);
	// stw r5,84(r30)
	PPC_STORE_U32(ctx.r30.u32 + 84, ctx.r5.u32);
	// bl 0x881090b0
	ctx.lr = 0x8810AF84;
	sub_881090B0(ctx, base);
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
loc_8810AF9C:
	// lwz r10,24(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8810afac
	if (ctx.cr6.eq) goto loc_8810AFAC;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_8810AFAC:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x8810af0c
	goto loc_8810AF0C;
}

__attribute__((alias("__imp__sub_8810AFB4"))) PPC_WEAK_FUNC(sub_8810AFB4);
PPC_FUNC_IMPL(__imp__sub_8810AFB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810AFB8"))) PPC_WEAK_FUNC(sub_8810AFB8);
PPC_FUNC_IMPL(__imp__sub_8810AFB8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x8810AFC0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r5,-292
	ctx.r5.s64 = -19136512;
	// li r4,144
	ctx.r4.s64 = 144;
	// ori r5,r5,47768
	ctx.r5.u64 = ctx.r5.u64 | 47768;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x8810AFD8;
	sub_88094290(ctx, base);
	// li r5,144
	ctx.r5.s64 = 144;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,2304(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2304);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x8810AFEC;
	sub_88073BD0(ctx, base);
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lis r10,-30703
	ctx.r10.s64 = -2012151808;
	// stw r30,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// li r9,130
	ctx.r9.s64 = 130;
	// addi r8,r10,-28768
	ctx.r8.s64 = ctx.r10.s64 + -28768;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r11,-11984(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11984);
	// li r29,1
	ctx.r29.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r6,88(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// stw r6,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r6.u32);
	// stw r9,168(r30)
	PPC_STORE_U32(ctx.r30.u32 + 168, ctx.r9.u32);
	// stw r8,76(r30)
	PPC_STORE_U32(ctx.r30.u32 + 76, ctx.r8.u32);
	// stw r29,96(r30)
	PPC_STORE_U32(ctx.r30.u32 + 96, ctx.r29.u32);
	// stw r7,80(r30)
	PPC_STORE_U32(ctx.r30.u32 + 80, ctx.r7.u32);
	// bl 0x88169750
	ctx.lr = 0x8810B02C;
	sub_88169750(ctx, base);
	// lwz r5,32(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r5,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r5.u32);
	// lwz r5,36(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// stw r5,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r5.u32);
	// bl 0x88095590
	ctx.lr = 0x8810B048;
	sub_88095590(ctx, base);
	// lis r4,-30643
	ctx.r4.s64 = -2008219648;
	// lwz r9,132(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// li r10,4
	ctx.r10.s64 = 4;
	// li r8,64
	ctx.r8.s64 = 64;
	// stw r3,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r3.u32);
	// li r7,50
	ctx.r7.s64 = 50;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// li r6,2
	ctx.r6.s64 = 2;
	// stw r8,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r8.u32);
	// lwz r11,26424(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 26424);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r10,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r10.u32);
	// rlwinm r5,r11,28,4,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0xFFFFFFF;
	// stw r7,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r7.u32);
	// stw r6,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r6.u32);
	// subfic r4,r5,36
	ctx.xer.ca = ctx.r5.u32 <= 36;
	ctx.r4.s64 = 36 - ctx.r5.s64;
	// stw r4,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r4.u32);
	// bne cr6,0x8810b094
	if (!ctx.cr6.eq) goto loc_8810B094;
	// stw r29,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r29.u32);
loc_8810B094:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8810aea0
	ctx.lr = 0x8810B0A0;
	sub_8810AEA0(ctx, base);
	// lis r11,-30703
	ctx.r11.s64 = -2012151808;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r10,r11,-27416
	ctx.r10.s64 = ctx.r11.s64 + -27416;
	// stw r10,64(r30)
	PPC_STORE_U32(ctx.r30.u32 + 64, ctx.r10.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810B0B8"))) PPC_WEAK_FUNC(sub_8810B0B8);
PPC_FUNC_IMPL(__imp__sub_8810B0B8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x8810B0C0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r5,-292
	ctx.r5.s64 = -19136512;
	// li r4,144
	ctx.r4.s64 = 144;
	// ori r5,r5,47768
	ctx.r5.u64 = ctx.r5.u64 | 47768;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x8810B0D8;
	sub_88094290(ctx, base);
	// li r5,144
	ctx.r5.s64 = 144;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r29,2304(r30)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2304);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88073bd0
	ctx.lr = 0x8810B0EC;
	sub_88073BD0(ctx, base);
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lis r10,-30703
	ctx.r10.s64 = -2012151808;
	// stw r30,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r30.u32);
	// li r9,130
	ctx.r9.s64 = 130;
	// addi r8,r10,-28728
	ctx.r8.s64 = ctx.r10.s64 + -28728;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r11,-11984(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11984);
	// li r31,1
	ctx.r31.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r6,88(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// stw r6,100(r29)
	PPC_STORE_U32(ctx.r29.u32 + 100, ctx.r6.u32);
	// stw r9,168(r30)
	PPC_STORE_U32(ctx.r30.u32 + 168, ctx.r9.u32);
	// stw r8,76(r30)
	PPC_STORE_U32(ctx.r30.u32 + 76, ctx.r8.u32);
	// stw r31,96(r30)
	PPC_STORE_U32(ctx.r30.u32 + 96, ctx.r31.u32);
	// stw r7,80(r30)
	PPC_STORE_U32(ctx.r30.u32 + 80, ctx.r7.u32);
	// bl 0x88169750
	ctx.lr = 0x8810B12C;
	sub_88169750(ctx, base);
	// lwz r11,20(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// lwz r10,32(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r5,r11,-256
	ctx.r5.s64 = ctx.r11.s64 + -256;
	// rotlwi r4,r10,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// rlwinm r11,r5,0,23,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x1E0;
	// stw r10,8(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8, ctx.r10.u32);
	// lwz r9,36(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// rotlwi r5,r9,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// stw r9,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r9.u32);
	// stw r11,60(r29)
	PPC_STORE_U32(ctx.r29.u32 + 60, ctx.r11.u32);
	// bl 0x88095590
	ctx.lr = 0x8810B15C;
	sub_88095590(ctx, base);
	// lis r8,-30643
	ctx.r8.s64 = -2008219648;
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r31,68(r29)
	PPC_STORE_U32(ctx.r29.u32 + 68, ctx.r31.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// rlwinm r6,r3,0,23,26
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x1E0;
	// stw r11,40(r29)
	PPC_STORE_U32(ctx.r29.u32 + 40, ctx.r11.u32);
	// li r4,64
	ctx.r4.s64 = 64;
	// stw r9,28(r29)
	PPC_STORE_U32(ctx.r29.u32 + 28, ctx.r9.u32);
	// lwz r10,26424(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 26424);
	// li r8,80
	ctx.r8.s64 = 80;
	// stw r4,108(r29)
	PPC_STORE_U32(ctx.r29.u32 + 108, ctx.r4.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// rlwinm r7,r10,28,4,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0xFFFFFFF;
	// stw r11,48(r29)
	PPC_STORE_U32(ctx.r29.u32 + 48, ctx.r11.u32);
	// li r10,32
	ctx.r10.s64 = 32;
	// stw r6,64(r29)
	PPC_STORE_U32(ctx.r29.u32 + 64, ctx.r6.u32);
	// subfic r5,r7,36
	ctx.xer.ca = ctx.r7.u32 <= 36;
	ctx.r5.s64 = 36 - ctx.r7.s64;
	// stw r11,44(r29)
	PPC_STORE_U32(ctx.r29.u32 + 44, ctx.r11.u32);
	// stw r11,80(r29)
	PPC_STORE_U32(ctx.r29.u32 + 80, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r5,36(r29)
	PPC_STORE_U32(ctx.r29.u32 + 36, ctx.r5.u32);
	// stw r10,84(r29)
	PPC_STORE_U32(ctx.r29.u32 + 84, ctx.r10.u32);
	// stw r8,88(r29)
	PPC_STORE_U32(ctx.r29.u32 + 88, ctx.r8.u32);
	// stw r9,72(r29)
	PPC_STORE_U32(ctx.r29.u32 + 72, ctx.r9.u32);
	// bl 0x8810aea0
	ctx.lr = 0x8810B1C0;
	sub_8810AEA0(ctx, base);
	// lis r7,-30703
	ctx.r7.s64 = -2012151808;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r6,r7,-26888
	ctx.r6.s64 = ctx.r7.s64 + -26888;
	// stw r6,64(r30)
	PPC_STORE_U32(ctx.r30.u32 + 64, ctx.r6.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810B1D8"))) PPC_WEAK_FUNC(sub_8810B1D8);
PPC_FUNC_IMPL(__imp__sub_8810B1D8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x8810B1E0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r5,-292
	ctx.r5.s64 = -19136512;
	// li r4,144
	ctx.r4.s64 = 144;
	// ori r5,r5,47768
	ctx.r5.u64 = ctx.r5.u64 | 47768;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x8810B1F8;
	sub_88094290(ctx, base);
	// li r5,144
	ctx.r5.s64 = 144;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r29,2304(r30)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2304);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88073bd0
	ctx.lr = 0x8810B20C;
	sub_88073BD0(ctx, base);
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lis r10,-30703
	ctx.r10.s64 = -2012151808;
	// stw r30,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r30.u32);
	// li r9,130
	ctx.r9.s64 = 130;
	// addi r8,r10,-28696
	ctx.r8.s64 = ctx.r10.s64 + -28696;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r11,-11984(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11984);
	// li r31,1
	ctx.r31.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r6,88(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// stw r6,100(r29)
	PPC_STORE_U32(ctx.r29.u32 + 100, ctx.r6.u32);
	// stw r9,168(r30)
	PPC_STORE_U32(ctx.r30.u32 + 168, ctx.r9.u32);
	// stw r8,76(r30)
	PPC_STORE_U32(ctx.r30.u32 + 76, ctx.r8.u32);
	// stw r31,96(r30)
	PPC_STORE_U32(ctx.r30.u32 + 96, ctx.r31.u32);
	// stw r7,80(r30)
	PPC_STORE_U32(ctx.r30.u32 + 80, ctx.r7.u32);
	// bl 0x88169750
	ctx.lr = 0x8810B24C;
	sub_88169750(ctx, base);
	// lwz r5,32(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r5,8(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8, ctx.r5.u32);
	// lwz r5,36(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// stw r5,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r5.u32);
	// bl 0x88095590
	ctx.lr = 0x8810B268;
	sub_88095590(ctx, base);
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r3,64(r29)
	PPC_STORE_U32(ctx.r29.u32 + 64, ctx.r3.u32);
	// li r9,64
	ctx.r9.s64 = 64;
	// stw r31,68(r29)
	PPC_STORE_U32(ctx.r29.u32 + 68, ctx.r31.u32);
	// li r8,50
	ctx.r8.s64 = 50;
	// stw r11,48(r29)
	PPC_STORE_U32(ctx.r29.u32 + 48, ctx.r11.u32);
	// stw r9,108(r29)
	PPC_STORE_U32(ctx.r29.u32 + 108, ctx.r9.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r10,26424(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26424);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,44(r29)
	PPC_STORE_U32(ctx.r29.u32 + 44, ctx.r11.u32);
	// rlwinm r7,r10,28,4,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0xFFFFFFF;
	// stw r8,84(r29)
	PPC_STORE_U32(ctx.r29.u32 + 84, ctx.r8.u32);
	// stw r11,72(r29)
	PPC_STORE_U32(ctx.r29.u32 + 72, ctx.r11.u32);
	// subfic r6,r7,36
	ctx.xer.ca = ctx.r7.u32 <= 36;
	ctx.r6.s64 = 36 - ctx.r7.s64;
	// stw r6,36(r29)
	PPC_STORE_U32(ctx.r29.u32 + 36, ctx.r6.u32);
	// bl 0x8810aea0
	ctx.lr = 0x8810B2B0;
	sub_8810AEA0(ctx, base);
	// lis r5,-30703
	ctx.r5.s64 = -2012151808;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r4,r5,-26096
	ctx.r4.s64 = ctx.r5.s64 + -26096;
	// stw r4,64(r30)
	PPC_STORE_U32(ctx.r30.u32 + 64, ctx.r4.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810B2C8"))) PPC_WEAK_FUNC(sub_8810B2C8);
PPC_FUNC_IMPL(__imp__sub_8810B2C8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x8810B2D0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r5,-292
	ctx.r5.s64 = -19136512;
	// li r4,144
	ctx.r4.s64 = 144;
	// ori r5,r5,47768
	ctx.r5.u64 = ctx.r5.u64 | 47768;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x8810B2E8;
	sub_88094290(ctx, base);
	// li r5,144
	ctx.r5.s64 = 144;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r29,2304(r30)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2304);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88073bd0
	ctx.lr = 0x8810B2FC;
	sub_88073BD0(ctx, base);
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lis r10,-30703
	ctx.r10.s64 = -2012151808;
	// stw r30,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r30.u32);
	// li r9,130
	ctx.r9.s64 = 130;
	// addi r8,r10,-28672
	ctx.r8.s64 = ctx.r10.s64 + -28672;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r11,-11984(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11984);
	// li r31,1
	ctx.r31.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r6,88(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// stw r6,100(r29)
	PPC_STORE_U32(ctx.r29.u32 + 100, ctx.r6.u32);
	// stw r9,168(r30)
	PPC_STORE_U32(ctx.r30.u32 + 168, ctx.r9.u32);
	// stw r8,76(r30)
	PPC_STORE_U32(ctx.r30.u32 + 76, ctx.r8.u32);
	// stw r31,96(r30)
	PPC_STORE_U32(ctx.r30.u32 + 96, ctx.r31.u32);
	// stw r7,80(r30)
	PPC_STORE_U32(ctx.r30.u32 + 80, ctx.r7.u32);
	// bl 0x88169750
	ctx.lr = 0x8810B33C;
	sub_88169750(ctx, base);
	// lwz r11,20(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// lwz r10,32(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r5,r11,-256
	ctx.r5.s64 = ctx.r11.s64 + -256;
	// rotlwi r4,r10,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// rlwinm r11,r5,0,23,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x1E0;
	// stw r10,8(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8, ctx.r10.u32);
	// lwz r9,36(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// rotlwi r5,r9,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// stw r9,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r9.u32);
	// stw r11,60(r29)
	PPC_STORE_U32(ctx.r29.u32 + 60, ctx.r11.u32);
	// bl 0x88095590
	ctx.lr = 0x8810B36C;
	sub_88095590(ctx, base);
	// lis r8,-30643
	ctx.r8.s64 = -2008219648;
	// rlwinm r7,r3,0,23,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x1E0;
	// stw r31,48(r29)
	PPC_STORE_U32(ctx.r29.u32 + 48, ctx.r31.u32);
	// li r6,64
	ctx.r6.s64 = 64;
	// stw r31,44(r29)
	PPC_STORE_U32(ctx.r29.u32 + 44, ctx.r31.u32);
	// li r4,50
	ctx.r4.s64 = 50;
	// stw r7,64(r29)
	PPC_STORE_U32(ctx.r29.u32 + 64, ctx.r7.u32);
	// stw r6,108(r29)
	PPC_STORE_U32(ctx.r29.u32 + 108, ctx.r6.u32);
	// lwz r11,26424(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 26424);
	// stw r4,84(r29)
	PPC_STORE_U32(ctx.r29.u32 + 84, ctx.r4.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// rlwinm r5,r11,28,4,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0xFFFFFFF;
	// stw r31,68(r29)
	PPC_STORE_U32(ctx.r29.u32 + 68, ctx.r31.u32);
	// li r11,2
	ctx.r11.s64 = 2;
	// subfic r3,r5,36
	ctx.xer.ca = ctx.r5.u32 <= 36;
	ctx.r3.s64 = 36 - ctx.r5.s64;
	// stw r11,72(r29)
	PPC_STORE_U32(ctx.r29.u32 + 72, ctx.r11.u32);
	// stw r3,36(r29)
	PPC_STORE_U32(ctx.r29.u32 + 36, ctx.r3.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8810aea0
	ctx.lr = 0x8810B3B8;
	sub_8810AEA0(ctx, base);
	// lis r10,-30703
	ctx.r10.s64 = -2012151808;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r9,r10,-25688
	ctx.r9.s64 = ctx.r10.s64 + -25688;
	// stw r9,64(r30)
	PPC_STORE_U32(ctx.r30.u32 + 64, ctx.r9.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810B3D0"))) PPC_WEAK_FUNC(sub_8810B3D0);
PPC_FUNC_IMPL(__imp__sub_8810B3D0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x8810B3D8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r5,-292
	ctx.r5.s64 = -19136512;
	// li r4,144
	ctx.r4.s64 = 144;
	// ori r5,r5,47768
	ctx.r5.u64 = ctx.r5.u64 | 47768;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x8810B3F0;
	sub_88094290(ctx, base);
	// li r5,144
	ctx.r5.s64 = 144;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r29,2304(r30)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2304);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88073bd0
	ctx.lr = 0x8810B404;
	sub_88073BD0(ctx, base);
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lis r10,-30703
	ctx.r10.s64 = -2012151808;
	// stw r30,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r30.u32);
	// li r9,130
	ctx.r9.s64 = 130;
	// addi r8,r10,-28640
	ctx.r8.s64 = ctx.r10.s64 + -28640;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r11,-11984(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11984);
	// li r31,1
	ctx.r31.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r6,88(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// stw r6,100(r29)
	PPC_STORE_U32(ctx.r29.u32 + 100, ctx.r6.u32);
	// stw r9,168(r30)
	PPC_STORE_U32(ctx.r30.u32 + 168, ctx.r9.u32);
	// stw r8,76(r30)
	PPC_STORE_U32(ctx.r30.u32 + 76, ctx.r8.u32);
	// stw r31,96(r30)
	PPC_STORE_U32(ctx.r30.u32 + 96, ctx.r31.u32);
	// stw r7,80(r30)
	PPC_STORE_U32(ctx.r30.u32 + 80, ctx.r7.u32);
	// bl 0x88169750
	ctx.lr = 0x8810B444;
	sub_88169750(ctx, base);
	// lwz r5,32(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r5,8(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8, ctx.r5.u32);
	// lwz r5,36(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// stw r5,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r5.u32);
	// bl 0x88095590
	ctx.lr = 0x8810B460;
	sub_88095590(ctx, base);
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// li r10,64
	ctx.r10.s64 = 64;
	// stw r3,64(r29)
	PPC_STORE_U32(ctx.r29.u32 + 64, ctx.r3.u32);
	// li r9,10
	ctx.r9.s64 = 10;
	// stw r31,48(r29)
	PPC_STORE_U32(ctx.r29.u32 + 48, ctx.r31.u32);
	// li r8,2
	ctx.r8.s64 = 2;
	// stw r10,108(r29)
	PPC_STORE_U32(ctx.r29.u32 + 108, ctx.r10.u32);
	// stw r31,44(r29)
	PPC_STORE_U32(ctx.r29.u32 + 44, ctx.r31.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,26424(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26424);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r9,84(r29)
	PPC_STORE_U32(ctx.r29.u32 + 84, ctx.r9.u32);
	// rlwinm r7,r11,28,4,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0xFFFFFFF;
	// stw r31,68(r29)
	PPC_STORE_U32(ctx.r29.u32 + 68, ctx.r31.u32);
	// stw r8,72(r29)
	PPC_STORE_U32(ctx.r29.u32 + 72, ctx.r8.u32);
	// subfic r6,r7,36
	ctx.xer.ca = ctx.r7.u32 <= 36;
	ctx.r6.s64 = 36 - ctx.r7.s64;
	// stw r6,36(r29)
	PPC_STORE_U32(ctx.r29.u32 + 36, ctx.r6.u32);
	// bl 0x8810aea0
	ctx.lr = 0x8810B4A8;
	sub_8810AEA0(ctx, base);
	// lis r5,-30703
	ctx.r5.s64 = -2012151808;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r4,r5,-25128
	ctx.r4.s64 = ctx.r5.s64 + -25128;
	// stw r4,64(r30)
	PPC_STORE_U32(ctx.r30.u32 + 64, ctx.r4.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810B4C0"))) PPC_WEAK_FUNC(sub_8810B4C0);
PPC_FUNC_IMPL(__imp__sub_8810B4C0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x8810B4C8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r5,-292
	ctx.r5.s64 = -19136512;
	// li r4,144
	ctx.r4.s64 = 144;
	// ori r5,r5,47768
	ctx.r5.u64 = ctx.r5.u64 | 47768;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x8810B4E0;
	sub_88094290(ctx, base);
	// li r5,144
	ctx.r5.s64 = 144;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r29,2304(r30)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2304);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88073bd0
	ctx.lr = 0x8810B4F4;
	sub_88073BD0(ctx, base);
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lis r10,-30703
	ctx.r10.s64 = -2012151808;
	// stw r30,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r30.u32);
	// li r9,130
	ctx.r9.s64 = 130;
	// addi r8,r10,-28608
	ctx.r8.s64 = ctx.r10.s64 + -28608;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r11,-11984(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11984);
	// li r31,1
	ctx.r31.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r6,88(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// stw r6,100(r29)
	PPC_STORE_U32(ctx.r29.u32 + 100, ctx.r6.u32);
	// stw r9,168(r30)
	PPC_STORE_U32(ctx.r30.u32 + 168, ctx.r9.u32);
	// stw r8,76(r30)
	PPC_STORE_U32(ctx.r30.u32 + 76, ctx.r8.u32);
	// stw r31,96(r30)
	PPC_STORE_U32(ctx.r30.u32 + 96, ctx.r31.u32);
	// stw r7,80(r30)
	PPC_STORE_U32(ctx.r30.u32 + 80, ctx.r7.u32);
	// bl 0x88169750
	ctx.lr = 0x8810B534;
	sub_88169750(ctx, base);
	// lwz r11,20(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// lwz r10,32(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r5,r11,-256
	ctx.r5.s64 = ctx.r11.s64 + -256;
	// rotlwi r4,r10,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// rlwinm r11,r5,0,23,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x1E0;
	// stw r10,8(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8, ctx.r10.u32);
	// lwz r9,36(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// rotlwi r5,r9,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// stw r9,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r9.u32);
	// stw r11,60(r29)
	PPC_STORE_U32(ctx.r29.u32 + 60, ctx.r11.u32);
	// bl 0x88095590
	ctx.lr = 0x8810B564;
	sub_88095590(ctx, base);
	// lis r8,-30643
	ctx.r8.s64 = -2008219648;
	// rlwinm r7,r3,0,23,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x1E0;
	// stw r31,68(r29)
	PPC_STORE_U32(ctx.r29.u32 + 68, ctx.r31.u32);
	// li r11,2
	ctx.r11.s64 = 2;
	// li r5,64
	ctx.r5.s64 = 64;
	// stw r7,64(r29)
	PPC_STORE_U32(ctx.r29.u32 + 64, ctx.r7.u32);
	// li r3,80
	ctx.r3.s64 = 80;
	// stw r11,48(r29)
	PPC_STORE_U32(ctx.r29.u32 + 48, ctx.r11.u32);
	// lwz r10,26424(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 26424);
	// stw r3,40(r29)
	PPC_STORE_U32(ctx.r29.u32 + 40, ctx.r3.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// rlwinm r6,r10,28,4,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0xFFFFFFF;
	// stw r11,44(r29)
	PPC_STORE_U32(ctx.r29.u32 + 44, ctx.r11.u32);
	// li r10,50
	ctx.r10.s64 = 50;
	// stw r5,108(r29)
	PPC_STORE_U32(ctx.r29.u32 + 108, ctx.r5.u32);
	// subfic r4,r6,36
	ctx.xer.ca = ctx.r6.u32 <= 36;
	ctx.r4.s64 = 36 - ctx.r6.s64;
	// stw r11,72(r29)
	PPC_STORE_U32(ctx.r29.u32 + 72, ctx.r11.u32);
	// stw r10,84(r29)
	PPC_STORE_U32(ctx.r29.u32 + 84, ctx.r10.u32);
	// stw r4,36(r29)
	PPC_STORE_U32(ctx.r29.u32 + 36, ctx.r4.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x8810aea0
	ctx.lr = 0x8810B5B8;
	sub_8810AEA0(ctx, base);
	// lis r9,-30703
	ctx.r9.s64 = -2012151808;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r8,r9,-24472
	ctx.r8.s64 = ctx.r9.s64 + -24472;
	// stw r8,64(r30)
	PPC_STORE_U32(ctx.r30.u32 + 64, ctx.r8.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810B5D0"))) PPC_WEAK_FUNC(sub_8810B5D0);
PPC_FUNC_IMPL(__imp__sub_8810B5D0) {
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
	// lis r5,-292
	ctx.r5.s64 = -19136512;
	// li r4,144
	ctx.r4.s64 = 144;
	// ori r5,r5,47768
	ctx.r5.u64 = ctx.r5.u64 | 47768;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x8810B5F8;
	sub_88094290(ctx, base);
	// li r5,144
	ctx.r5.s64 = 144;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r30,2304(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2304);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88073bd0
	ctx.lr = 0x8810B60C;
	sub_88073BD0(ctx, base);
	// lis r11,-30703
	ctx.r11.s64 = -2012151808;
	// li r10,130
	ctx.r10.s64 = 130;
	// stw r31,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r31.u32);
	// addi r9,r11,-28576
	ctx.r9.s64 = ctx.r11.s64 + -28576;
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r10,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r10.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r9,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r9.u32);
	// stw r8,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r7,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r7.u32);
	// bl 0x88169750
	ctx.lr = 0x8810B63C;
	sub_88169750(ctx, base);
	// lis r6,-30643
	ctx.r6.s64 = -2008219648;
	// lis r5,-30597
	ctx.r5.s64 = -2005204992;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,64
	ctx.r8.s64 = 64;
	// li r7,50
	ctx.r7.s64 = 50;
	// lwz r11,26424(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 26424);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r10,-11984(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + -11984);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rlwinm r6,r11,28,4,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0xFFFFFFF;
	// subfic r5,r6,36
	ctx.xer.ca = ctx.r6.u32 <= 36;
	ctx.r5.s64 = 36 - ctx.r6.s64;
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// stw r11,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
	// lwz r6,36(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// stw r6,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r6.u32);
	// lwz r11,88(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 88);
	// stw r11,100(r30)
	PPC_STORE_U32(ctx.r30.u32 + 100, ctx.r11.u32);
	// stw r8,108(r30)
	PPC_STORE_U32(ctx.r30.u32 + 108, ctx.r8.u32);
	// stw r5,36(r30)
	PPC_STORE_U32(ctx.r30.u32 + 36, ctx.r5.u32);
	// stw r9,48(r30)
	PPC_STORE_U32(ctx.r30.u32 + 48, ctx.r9.u32);
	// stw r9,44(r30)
	PPC_STORE_U32(ctx.r30.u32 + 44, ctx.r9.u32);
	// stw r7,84(r30)
	PPC_STORE_U32(ctx.r30.u32 + 84, ctx.r7.u32);
	// bl 0x8810aea0
	ctx.lr = 0x8810B698;
	sub_8810AEA0(ctx, base);
	// lis r10,-30703
	ctx.r10.s64 = -2012151808;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r9,r10,-23792
	ctx.r9.s64 = ctx.r10.s64 + -23792;
	// stw r9,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_8810B6C0"))) PPC_WEAK_FUNC(sub_8810B6C0);
PPC_FUNC_IMPL(__imp__sub_8810B6C0) {
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
	// lis r5,-292
	ctx.r5.s64 = -19136512;
	// li r4,144
	ctx.r4.s64 = 144;
	// ori r5,r5,47768
	ctx.r5.u64 = ctx.r5.u64 | 47768;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x8810B6E8;
	sub_88094290(ctx, base);
	// li r5,144
	ctx.r5.s64 = 144;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r30,2304(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2304);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88073bd0
	ctx.lr = 0x8810B6FC;
	sub_88073BD0(ctx, base);
	// lis r11,-30703
	ctx.r11.s64 = -2012151808;
	// li r10,130
	ctx.r10.s64 = 130;
	// stw r31,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r31.u32);
	// addi r9,r11,-28528
	ctx.r9.s64 = ctx.r11.s64 + -28528;
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r10,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r10.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r9,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r9.u32);
	// stw r8,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r7,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r7.u32);
	// bl 0x88169750
	ctx.lr = 0x8810B72C;
	sub_88169750(ctx, base);
	// lis r6,-30643
	ctx.r6.s64 = -2008219648;
	// lis r5,-30597
	ctx.r5.s64 = -2005204992;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,64
	ctx.r8.s64 = 64;
	// li r7,50
	ctx.r7.s64 = 50;
	// lwz r11,26424(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 26424);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r10,-11984(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + -11984);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rlwinm r6,r11,28,4,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0xFFFFFFF;
	// subfic r5,r6,36
	ctx.xer.ca = ctx.r6.u32 <= 36;
	ctx.r5.s64 = 36 - ctx.r6.s64;
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// stw r11,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
	// lwz r6,36(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// stw r6,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r6.u32);
	// lwz r11,88(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 88);
	// stw r11,100(r30)
	PPC_STORE_U32(ctx.r30.u32 + 100, ctx.r11.u32);
	// stw r8,108(r30)
	PPC_STORE_U32(ctx.r30.u32 + 108, ctx.r8.u32);
	// stw r5,36(r30)
	PPC_STORE_U32(ctx.r30.u32 + 36, ctx.r5.u32);
	// stw r9,48(r30)
	PPC_STORE_U32(ctx.r30.u32 + 48, ctx.r9.u32);
	// stw r9,44(r30)
	PPC_STORE_U32(ctx.r30.u32 + 44, ctx.r9.u32);
	// stw r7,84(r30)
	PPC_STORE_U32(ctx.r30.u32 + 84, ctx.r7.u32);
	// bl 0x8810aea0
	ctx.lr = 0x8810B788;
	sub_8810AEA0(ctx, base);
	// lis r10,-30703
	ctx.r10.s64 = -2012151808;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r9,r10,-23240
	ctx.r9.s64 = ctx.r10.s64 + -23240;
	// stw r9,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_8810B7B0"))) PPC_WEAK_FUNC(sub_8810B7B0);
PPC_FUNC_IMPL(__imp__sub_8810B7B0) {
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
	// bl 0x88109180
	ctx.lr = 0x8810B7C4;
	sub_88109180(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8810b7d4
	if (ctx.cr6.eq) goto loc_8810B7D4;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x8810afb8
	ctx.lr = 0x8810B7D4;
	sub_8810AFB8(ctx, base);
loc_8810B7D4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8810B7E4"))) PPC_WEAK_FUNC(sub_8810B7E4);
PPC_FUNC_IMPL(__imp__sub_8810B7E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810B7E8"))) PPC_WEAK_FUNC(sub_8810B7E8);
PPC_FUNC_IMPL(__imp__sub_8810B7E8) {
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
	// bl 0x88109180
	ctx.lr = 0x8810B7FC;
	sub_88109180(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8810b81c
	if (ctx.cr6.eq) goto loc_8810B81C;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x8810afb8
	ctx.lr = 0x8810B80C;
	sub_8810AFB8(ctx, base);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,320
	ctx.r11.s64 = 20971520;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
loc_8810B81C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8810B82C"))) PPC_WEAK_FUNC(sub_8810B82C);
PPC_FUNC_IMPL(__imp__sub_8810B82C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810B830"))) PPC_WEAK_FUNC(sub_8810B830);
PPC_FUNC_IMPL(__imp__sub_8810B830) {
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
	// bl 0x88109180
	ctx.lr = 0x8810B844;
	sub_88109180(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8810b854
	if (ctx.cr6.eq) goto loc_8810B854;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x8810b0b8
	ctx.lr = 0x8810B854;
	sub_8810B0B8(ctx, base);
loc_8810B854:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8810B864"))) PPC_WEAK_FUNC(sub_8810B864);
PPC_FUNC_IMPL(__imp__sub_8810B864) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810B868"))) PPC_WEAK_FUNC(sub_8810B868);
PPC_FUNC_IMPL(__imp__sub_8810B868) {
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
	// bl 0x88109180
	ctx.lr = 0x8810B87C;
	sub_88109180(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8810b89c
	if (ctx.cr6.eq) goto loc_8810B89C;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x8810b0b8
	ctx.lr = 0x8810B88C;
	sub_8810B0B8(ctx, base);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,320
	ctx.r11.s64 = 20971520;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
loc_8810B89C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8810B8AC"))) PPC_WEAK_FUNC(sub_8810B8AC);
PPC_FUNC_IMPL(__imp__sub_8810B8AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810B8B0"))) PPC_WEAK_FUNC(sub_8810B8B0);
PPC_FUNC_IMPL(__imp__sub_8810B8B0) {
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
	// bl 0x88109180
	ctx.lr = 0x8810B8C4;
	sub_88109180(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8810b8d4
	if (ctx.cr6.eq) goto loc_8810B8D4;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x8810b1d8
	ctx.lr = 0x8810B8D4;
	sub_8810B1D8(ctx, base);
loc_8810B8D4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8810B8E4"))) PPC_WEAK_FUNC(sub_8810B8E4);
PPC_FUNC_IMPL(__imp__sub_8810B8E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810B8E8"))) PPC_WEAK_FUNC(sub_8810B8E8);
PPC_FUNC_IMPL(__imp__sub_8810B8E8) {
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
	// bl 0x88109180
	ctx.lr = 0x8810B8FC;
	sub_88109180(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8810b91c
	if (ctx.cr6.eq) goto loc_8810B91C;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x8810b1d8
	ctx.lr = 0x8810B90C;
	sub_8810B1D8(ctx, base);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,320
	ctx.r11.s64 = 20971520;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
loc_8810B91C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8810B92C"))) PPC_WEAK_FUNC(sub_8810B92C);
PPC_FUNC_IMPL(__imp__sub_8810B92C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810B930"))) PPC_WEAK_FUNC(sub_8810B930);
PPC_FUNC_IMPL(__imp__sub_8810B930) {
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
	// bl 0x88109180
	ctx.lr = 0x8810B944;
	sub_88109180(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8810b954
	if (ctx.cr6.eq) goto loc_8810B954;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x8810b2c8
	ctx.lr = 0x8810B954;
	sub_8810B2C8(ctx, base);
loc_8810B954:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8810B964"))) PPC_WEAK_FUNC(sub_8810B964);
PPC_FUNC_IMPL(__imp__sub_8810B964) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810B968"))) PPC_WEAK_FUNC(sub_8810B968);
PPC_FUNC_IMPL(__imp__sub_8810B968) {
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
	// bl 0x88109180
	ctx.lr = 0x8810B97C;
	sub_88109180(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8810b99c
	if (ctx.cr6.eq) goto loc_8810B99C;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x8810b2c8
	ctx.lr = 0x8810B98C;
	sub_8810B2C8(ctx, base);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,320
	ctx.r11.s64 = 20971520;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
loc_8810B99C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8810B9AC"))) PPC_WEAK_FUNC(sub_8810B9AC);
PPC_FUNC_IMPL(__imp__sub_8810B9AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810B9B0"))) PPC_WEAK_FUNC(sub_8810B9B0);
PPC_FUNC_IMPL(__imp__sub_8810B9B0) {
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
	// bl 0x88109180
	ctx.lr = 0x8810B9C4;
	sub_88109180(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8810b9d4
	if (ctx.cr6.eq) goto loc_8810B9D4;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x8810b3d0
	ctx.lr = 0x8810B9D4;
	sub_8810B3D0(ctx, base);
loc_8810B9D4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8810B9E4"))) PPC_WEAK_FUNC(sub_8810B9E4);
PPC_FUNC_IMPL(__imp__sub_8810B9E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810B9E8"))) PPC_WEAK_FUNC(sub_8810B9E8);
PPC_FUNC_IMPL(__imp__sub_8810B9E8) {
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
	// bl 0x88109180
	ctx.lr = 0x8810B9FC;
	sub_88109180(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8810ba1c
	if (ctx.cr6.eq) goto loc_8810BA1C;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x8810b3d0
	ctx.lr = 0x8810BA0C;
	sub_8810B3D0(ctx, base);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,320
	ctx.r11.s64 = 20971520;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
loc_8810BA1C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8810BA2C"))) PPC_WEAK_FUNC(sub_8810BA2C);
PPC_FUNC_IMPL(__imp__sub_8810BA2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810BA30"))) PPC_WEAK_FUNC(sub_8810BA30);
PPC_FUNC_IMPL(__imp__sub_8810BA30) {
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
	// bl 0x88109180
	ctx.lr = 0x8810BA48;
	sub_88109180(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8810ba60
	if (ctx.cr6.eq) goto loc_8810BA60;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8810b4c0
	ctx.lr = 0x8810BA58;
	sub_8810B4C0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88109180
	ctx.lr = 0x8810BA60;
	sub_88109180(ctx, base);
loc_8810BA60:
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

__attribute__((alias("__imp__sub_8810BA74"))) PPC_WEAK_FUNC(sub_8810BA74);
PPC_FUNC_IMPL(__imp__sub_8810BA74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810BA78"))) PPC_WEAK_FUNC(sub_8810BA78);
PPC_FUNC_IMPL(__imp__sub_8810BA78) {
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
	// bl 0x88109180
	ctx.lr = 0x8810BA90;
	sub_88109180(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8810babc
	if (ctx.cr6.eq) goto loc_8810BABC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8810b4c0
	ctx.lr = 0x8810BAA0;
	sub_8810B4C0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lis r10,240
	ctx.r10.s64 = 15728640;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// stw r8,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
	// bl 0x88109180
	ctx.lr = 0x8810BABC;
	sub_88109180(ctx, base);
loc_8810BABC:
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

__attribute__((alias("__imp__sub_8810BAD0"))) PPC_WEAK_FUNC(sub_8810BAD0);
PPC_FUNC_IMPL(__imp__sub_8810BAD0) {
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
	// bl 0x88109180
	ctx.lr = 0x8810BAE4;
	sub_88109180(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8810baf4
	if (ctx.cr6.eq) goto loc_8810BAF4;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x8810b5d0
	ctx.lr = 0x8810BAF4;
	sub_8810B5D0(ctx, base);
loc_8810BAF4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8810BB04"))) PPC_WEAK_FUNC(sub_8810BB04);
PPC_FUNC_IMPL(__imp__sub_8810BB04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810BB08"))) PPC_WEAK_FUNC(sub_8810BB08);
PPC_FUNC_IMPL(__imp__sub_8810BB08) {
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
	// bl 0x88109180
	ctx.lr = 0x8810BB1C;
	sub_88109180(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8810bb3c
	if (ctx.cr6.eq) goto loc_8810BB3C;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x8810b5d0
	ctx.lr = 0x8810BB2C;
	sub_8810B5D0(ctx, base);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,320
	ctx.r11.s64 = 20971520;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
loc_8810BB3C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8810BB4C"))) PPC_WEAK_FUNC(sub_8810BB4C);
PPC_FUNC_IMPL(__imp__sub_8810BB4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810BB50"))) PPC_WEAK_FUNC(sub_8810BB50);
PPC_FUNC_IMPL(__imp__sub_8810BB50) {
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
	// bl 0x88109180
	ctx.lr = 0x8810BB64;
	sub_88109180(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8810bb74
	if (ctx.cr6.eq) goto loc_8810BB74;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x8810b6c0
	ctx.lr = 0x8810BB74;
	sub_8810B6C0(ctx, base);
loc_8810BB74:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8810BB84"))) PPC_WEAK_FUNC(sub_8810BB84);
PPC_FUNC_IMPL(__imp__sub_8810BB84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810BB88"))) PPC_WEAK_FUNC(sub_8810BB88);
PPC_FUNC_IMPL(__imp__sub_8810BB88) {
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
	// bl 0x88109180
	ctx.lr = 0x8810BB9C;
	sub_88109180(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8810bbbc
	if (ctx.cr6.eq) goto loc_8810BBBC;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x8810b6c0
	ctx.lr = 0x8810BBAC;
	sub_8810B6C0(ctx, base);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,320
	ctx.r11.s64 = 20971520;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
loc_8810BBBC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8810BBCC"))) PPC_WEAK_FUNC(sub_8810BBCC);
PPC_FUNC_IMPL(__imp__sub_8810BBCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810BBD0"))) PPC_WEAK_FUNC(sub_8810BBD0);
PPC_FUNC_IMPL(__imp__sub_8810BBD0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8810BBD4"))) PPC_WEAK_FUNC(sub_8810BBD4);
PPC_FUNC_IMPL(__imp__sub_8810BBD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810BBD8"))) PPC_WEAK_FUNC(sub_8810BBD8);
PPC_FUNC_IMPL(__imp__sub_8810BBD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// li r11,512
	ctx.r11.s64 = 512;
	// lwz r10,2304(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2304);
	// rlwinm r9,r5,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0x1;
	// subfc r8,r11,r5
	ctx.xer.ca = ctx.r5.u32 >= ctx.r11.u32;
	ctx.r8.s64 = ctx.r5.s64 - ctx.r11.s64;
	// rlwinm r7,r11,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// li r3,1
	ctx.r3.s64 = 1;
	// subfe r6,r9,r7
	temp.u8 = (~ctx.r9.u32 + ctx.r7.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r7.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ~ctx.r9.u64 + ctx.r7.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r5,76(r10)
	PPC_STORE_U32(ctx.r10.u32 + 76, ctx.r5.u32);
	// and r5,r6,r4
	ctx.r5.u64 = ctx.r6.u64 & ctx.r4.u64;
	// stw r5,68(r10)
	PPC_STORE_U32(ctx.r10.u32 + 68, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8810BC04"))) PPC_WEAK_FUNC(sub_8810BC04);
PPC_FUNC_IMPL(__imp__sub_8810BC04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810BC08"))) PPC_WEAK_FUNC(sub_8810BC08);
PPC_FUNC_IMPL(__imp__sub_8810BC08) {
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
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// lwz r10,168(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 168);
	// lwz r10,28(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8810bc50
	if (ctx.cr6.eq) goto loc_8810BC50;
loc_8810BC38:
	// lwz r8,20(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// stw r4,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r4.u32);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// or r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 | ctx.r9.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8810bc38
	if (!ctx.cr6.eq) goto loc_8810BC38;
loc_8810BC50:
	// lis r10,128
	ctx.r10.s64 = 8388608;
	// clrlwi r9,r9,20
	ctx.r9.u64 = ctx.r9.u32 & 0xFFF;
	// ori r8,r10,32896
	ctx.r8.u64 = ctx.r10.u64 | 32896;
	// rlwinm r9,r9,0,26,21
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFC3F;
	// stw r8,128(r11)
	PPC_STORE_U32(ctx.r11.u32 + 128, ctx.r8.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8810bc90
	if (ctx.cr6.eq) goto loc_8810BC90;
	// lwz r10,132(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 132);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// stw r10,132(r11)
	PPC_STORE_U32(ctx.r11.u32 + 132, ctx.r10.u32);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8810bc90
	if (ctx.cr6.eq) goto loc_8810BC90;
	// lis r10,192
	ctx.r10.s64 = 12582912;
	// ori r9,r10,49152
	ctx.r9.u64 = ctx.r10.u64 | 49152;
	// stw r9,128(r11)
	PPC_STORE_U32(ctx.r11.u32 + 128, ctx.r9.u32);
loc_8810BC90:
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lis r7,-30643
	ctx.r7.s64 = -2008219648;
	// lis r8,-30714
	ctx.r8.s64 = -2012872704;
	// lwz r6,68(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// clrlwi r10,r10,23
	ctx.r10.u64 = ctx.r10.u32 & 0x1FF;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r5,r8,9552
	ctx.r5.s64 = ctx.r8.s64 + 9552;
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// addi r31,r10,128
	ctx.r31.s64 = ctx.r10.s64 + 128;
	// rlwinm r30,r10,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,26272(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 26272);
	// rlwinm r31,r31,2,21,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0x7FC;
	// lis r7,-30597
	ctx.r7.s64 = -2005204992;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwzx r10,r30,r5
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r5.u32);
	// lwzx r31,r31,r5
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r5.u32);
	// lwz r5,-11984(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + -11984);
	// mullw r10,r10,r6
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r6.s32);
	// mullw r7,r31,r6
	ctx.r7.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r6.s32);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r10,r7,r8
	ctx.r10.u64 = ctx.r7.u64 + ctx.r8.u64;
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// beq cr6,0x8810bcf8
	if (ctx.cr6.eq) goto loc_8810BCF8;
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// b 0x8810bd08
	goto loc_8810BD08;
loc_8810BCF8:
	// lwz r9,140(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 140);
	// addi r9,r9,51
	ctx.r9.s64 = ctx.r9.s64 + 51;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r8,r5
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r5.u32);
loc_8810BD08:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lis r6,64
	ctx.r6.s64 = 4194304;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add. r8,r10,r6
	ctx.r8.u64 = ctx.r10.u64 + ctx.r6.u64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// lwz r10,100(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rlwinm r7,r10,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// and r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 & ctx.r10.u64;
	// ble 0x8810bd78
	if (!ctx.cr0.gt) goto loc_8810BD78;
	// lis r7,128
	ctx.r7.s64 = 8388608;
	// lis r31,320
	ctx.r31.s64 = 20971520;
	// subf r8,r7,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r7.s64;
	// cmpw cr6,r8,r31
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r31.s32, ctx.xer);
	// bge cr6,0x8810bd78
	if (!ctx.cr6.lt) goto loc_8810BD78;
	// addi r10,r10,55
	ctx.r10.s64 = ctx.r10.s64 + 55;
	// lis r8,-40
	ctx.r8.s64 = -2621440;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r5
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r5.u32);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r10,r9,r6
	ctx.r10.u64 = ctx.r9.u64 + ctx.r6.u64;
	// cmpw cr6,r10,r8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, ctx.xer);
	// ble cr6,0x8810bd78
	if (!ctx.cr6.gt) goto loc_8810BD78;
	// lis r9,280
	ctx.r9.s64 = 18350080;
	// subf r8,r7,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r7.s64;
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x8810bd94
	if (ctx.cr6.lt) goto loc_8810BD94;
loc_8810BD78:
	// lwz r10,136(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 136);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8810bd9c
	if (ctx.cr6.eq) goto loc_8810BD9C;
	// lwz r11,168(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 168);
	// stw r4,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r4.u32);
	// bl 0x88094220
	ctx.lr = 0x8810BD90;
	sub_88094220(ctx, base);
	// b 0x8810bdcc
	goto loc_8810BDCC;
loc_8810BD94:
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,136(r11)
	PPC_STORE_U32(ctx.r11.u32 + 136, ctx.r10.u32);
loc_8810BD9C:
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 100);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,100(r11)
	PPC_STORE_U32(ctx.r11.u32 + 100, ctx.r10.u32);
	// bge 0x8810bdcc
	if (!ctx.cr0.lt) goto loc_8810BDCC;
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 108);
	// lwz r9,104(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 104);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,108(r11)
	PPC_STORE_U32(ctx.r11.u32 + 108, ctx.r10.u32);
	// cmpwi cr6,r10,16
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 16, ctx.xer);
	// stw r9,100(r11)
	PPC_STORE_U32(ctx.r11.u32 + 100, ctx.r9.u32);
	// blt cr6,0x8810bdcc
	if (ctx.cr6.lt) goto loc_8810BDCC;
	// stw r4,108(r11)
	PPC_STORE_U32(ctx.r11.u32 + 108, ctx.r4.u32);
loc_8810BDCC:
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

__attribute__((alias("__imp__sub_8810BDE4"))) PPC_WEAK_FUNC(sub_8810BDE4);
PPC_FUNC_IMPL(__imp__sub_8810BDE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810BDE8"))) PPC_WEAK_FUNC(sub_8810BDE8);
PPC_FUNC_IMPL(__imp__sub_8810BDE8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r9,168(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 168);
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

__attribute__((alias("__imp__sub_8810BE18"))) PPC_WEAK_FUNC(sub_8810BE18);
PPC_FUNC_IMPL(__imp__sub_8810BE18) {
	PPC_FUNC_PROLOGUE();
	// stw r7,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r7.u32);
	// stw r10,-104(r11)
	PPC_STORE_U32(ctx.r11.u32 + -104, ctx.r10.u32);
	// stwx r9,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + ctx.r11.u32, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8810BE28"))) PPC_WEAK_FUNC(sub_8810BE28);
PPC_FUNC_IMPL(__imp__sub_8810BE28) {
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
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r9,r6
	ctx.r9.u64 = ctx.r6.u64;
	// lwz r10,172(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 172);
	// lwz r10,28(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8810be70
	if (ctx.cr6.eq) goto loc_8810BE70;
loc_8810BE58:
	// lwz r8,20(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// stw r6,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r6.u32);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// or r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 | ctx.r9.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8810be58
	if (!ctx.cr6.eq) goto loc_8810BE58;
loc_8810BE70:
	// lis r10,128
	ctx.r10.s64 = 8388608;
	// clrlwi r9,r9,20
	ctx.r9.u64 = ctx.r9.u32 & 0xFFF;
	// ori r8,r10,32896
	ctx.r8.u64 = ctx.r10.u64 | 32896;
	// rlwinm r9,r9,0,26,21
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFC3F;
	// stw r8,128(r11)
	PPC_STORE_U32(ctx.r11.u32 + 128, ctx.r8.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8810beb0
	if (ctx.cr6.eq) goto loc_8810BEB0;
	// lwz r10,132(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 132);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// stw r10,132(r11)
	PPC_STORE_U32(ctx.r11.u32 + 132, ctx.r10.u32);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8810beb0
	if (ctx.cr6.eq) goto loc_8810BEB0;
	// lis r10,192
	ctx.r10.s64 = 12582912;
	// ori r9,r10,49152
	ctx.r9.u64 = ctx.r10.u64 | 49152;
	// stw r9,128(r11)
	PPC_STORE_U32(ctx.r11.u32 + 128, ctx.r9.u32);
loc_8810BEB0:
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lis r7,-30643
	ctx.r7.s64 = -2008219648;
	// lis r8,-30714
	ctx.r8.s64 = -2012872704;
	// lwz r5,68(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// clrlwi r10,r10,23
	ctx.r10.u64 = ctx.r10.u32 & 0x1FF;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r4,r8,9552
	ctx.r4.s64 = ctx.r8.s64 + 9552;
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// addi r31,r10,128
	ctx.r31.s64 = ctx.r10.s64 + 128;
	// rlwinm r30,r10,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,26272(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 26272);
	// rlwinm r31,r31,2,21,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0x7FC;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwzx r10,r30,r4
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r4.u32);
	// lwzx r7,r31,r4
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r4.u32);
	// mullw r10,r10,r5
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r5.s32);
	// mullw r7,r7,r5
	ctx.r7.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r5.s32);
	// add r5,r10,r9
	ctx.r5.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r10,r7,r8
	ctx.r10.u64 = ctx.r7.u64 + ctx.r8.u64;
	// stw r5,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r5.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// beq cr6,0x8810bf10
	if (ctx.cr6.eq) goto loc_8810BF10;
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
	// b 0x8810bf28
	goto loc_8810BF28;
loc_8810BF10:
	// lwz r9,140(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 140);
	// lis r8,-30597
	ctx.r8.s64 = -2005204992;
	// addi r7,r9,51
	ctx.r7.s64 = ctx.r9.s64 + 51;
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,-11984(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + -11984);
	// lwzx r8,r5,r9
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r9.u32);
loc_8810BF28:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lis r7,36
	ctx.r7.s64 = 2359296;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add. r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// ble 0x8810bf6c
	if (!ctx.cr0.gt) goto loc_8810BF6C;
	// lis r8,72
	ctx.r8.s64 = 4718592;
	// lis r5,320
	ctx.r5.s64 = 20971520;
	// subf r4,r8,r10
	ctx.r4.s64 = ctx.r10.s64 - ctx.r8.s64;
	// cmpw cr6,r4,r5
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r5.s32, ctx.xer);
	// bge cr6,0x8810bf6c
	if (!ctx.cr6.lt) goto loc_8810BF6C;
	// add. r10,r9,r7
	ctx.r10.u64 = ctx.r9.u64 + ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble 0x8810bf6c
	if (!ctx.cr0.gt) goto loc_8810BF6C;
	// lis r9,240
	ctx.r9.s64 = 15728640;
	// subf r8,r8,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r8.s64;
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x8810bf88
	if (ctx.cr6.lt) goto loc_8810BF88;
loc_8810BF6C:
	// lwz r10,136(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 136);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8810bf90
	if (ctx.cr6.eq) goto loc_8810BF90;
	// lwz r11,172(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 172);
	// stw r6,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r6.u32);
	// bl 0x88094220
	ctx.lr = 0x8810BF84;
	sub_88094220(ctx, base);
	// b 0x8810bfc0
	goto loc_8810BFC0;
loc_8810BF88:
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,136(r11)
	PPC_STORE_U32(ctx.r11.u32 + 136, ctx.r10.u32);
loc_8810BF90:
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 100);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,100(r11)
	PPC_STORE_U32(ctx.r11.u32 + 100, ctx.r10.u32);
	// bge 0x8810bfc0
	if (!ctx.cr0.lt) goto loc_8810BFC0;
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 108);
	// lwz r9,104(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 104);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,108(r11)
	PPC_STORE_U32(ctx.r11.u32 + 108, ctx.r10.u32);
	// cmpwi cr6,r10,24
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 24, ctx.xer);
	// stw r9,100(r11)
	PPC_STORE_U32(ctx.r11.u32 + 100, ctx.r9.u32);
	// blt cr6,0x8810bfc0
	if (ctx.cr6.lt) goto loc_8810BFC0;
	// stw r6,108(r11)
	PPC_STORE_U32(ctx.r11.u32 + 108, ctx.r6.u32);
loc_8810BFC0:
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

__attribute__((alias("__imp__sub_8810BFD8"))) PPC_WEAK_FUNC(sub_8810BFD8);
PPC_FUNC_IMPL(__imp__sub_8810BFD8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r9,172(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 172);
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

__attribute__((alias("__imp__sub_8810C018"))) PPC_WEAK_FUNC(sub_8810C018);
PPC_FUNC_IMPL(__imp__sub_8810C018) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x8810C020;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r24,2304(r3)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r10,184(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// lwz r11,168(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// li r3,419
	ctx.r3.s64 = 419;
	// add r26,r10,r11
	ctx.r26.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r11,12(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 12);
	// lwz r10,0(r24)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// lwz r9,4(r24)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r24.u32 + 4);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// lwz r31,108(r24)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r24.u32 + 108);
	// bne cr6,0x8810c160
	if (!ctx.cr6.eq) goto loc_8810C160;
	// lis r11,-30680
	ctx.r11.s64 = -2010644480;
	// rlwinm r8,r31,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r11,16160
	ctx.r11.s64 = ctx.r11.s64 + 16160;
	// addi r30,r26,-1
	ctx.r30.s64 = ctx.r26.s64 + -1;
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// extsb r5,r8
	ctx.r5.s64 = ctx.r8.s8;
	// extsb r4,r7
	ctx.r4.s64 = ctx.r7.s8;
	// rlwinm r8,r5,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r4,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// subf r29,r8,r10
	ctx.r29.s64 = ctx.r10.s64 - ctx.r8.s64;
	// add r28,r11,r9
	ctx.r28.u64 = ctx.r11.u64 + ctx.r9.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x881538c0
	ctx.lr = 0x8810C094;
	sub_881538C0(ctx, base);
	// lis r27,-30597
	ctx.r27.s64 = -2005204992;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810c0cc
	if (ctx.cr6.eq) goto loc_8810C0CC;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,48
	ctx.r9.s64 = 3145728;
	// lwz r11,-11932(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
	// oris r7,r10,545
	ctx.r7.u64 = ctx.r10.u64 | 35717120;
	// ori r8,r9,32880
	ctx.r8.u64 = ctx.r9.u64 | 32880;
	// ori r7,r7,40960
	ctx.r7.u64 = ctx.r7.u64 | 40960;
	// addi r25,r11,1
	ctx.r25.s64 = ctx.r11.s64 + 1;
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r25,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r25.u32);
	// b 0x8810c0d0
	goto loc_8810C0D0;
loc_8810C0CC:
	// lwz r25,-11932(r27)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
loc_8810C0D0:
	// addi r31,r31,10894
	ctx.r31.s64 = ctx.r31.s64 + 10894;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// addis r5,r28,-88
	ctx.r5.s64 = ctx.r28.s64 + -5767168;
	// addis r4,r29,4
	ctx.r4.s64 = ctx.r29.s64 + 262144;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x881538c0
	ctx.lr = 0x8810C0E8;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810c120
	if (ctx.cr6.eq) goto loc_8810C120;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r25,1
	ctx.r11.s64 = ctx.r25.s64 + 1;
	// oris r8,r10,547
	ctx.r8.u64 = ctx.r10.u64 | 35848192;
	// stw r9,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r9.u32);
	// stw r11,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r11.u32);
	// ori r8,r8,16384
	ctx.r8.u64 = ctx.r8.u64 | 16384;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// lwz r7,12(r24)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r24.u32 + 12);
	// rlwinm r6,r7,26,0,5
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 26) & 0xFC000000;
	// or r5,r6,r8
	ctx.r5.u64 = ctx.r6.u64 | ctx.r8.u64;
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
loc_8810C120:
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x881538c0
	ctx.lr = 0x8810C134;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810c244
	if (ctx.cr6.eq) goto loc_8810C244;
	// lwz r11,128(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 128);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
	// lwz r9,12(r24)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r24.u32 + 12);
	// rlwinm r8,r9,26,0,5
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 26) & 0xFC000000;
	// or r7,r8,r10
	ctx.r7.u64 = ctx.r8.u64 | ctx.r10.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
loc_8810C160:
	// lis r8,-30680
	ctx.r8.s64 = -2010644480;
	// rlwinm r11,r31,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r8,r8,16160
	ctx.r8.s64 = ctx.r8.s64 + 16160;
	// addi r28,r26,-1
	ctx.r28.s64 = ctx.r26.s64 + -1;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// lbz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r5,1(r11)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// extsb r4,r7
	ctx.r4.s64 = ctx.r7.s8;
	// extsb r11,r5
	ctx.r11.s64 = ctx.r5.s8;
	// rlwinm r8,r4,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// add r30,r8,r10
	ctx.r30.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r29,r11,r9
	ctx.r29.u64 = ctx.r11.u64 + ctx.r9.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x881538c0
	ctx.lr = 0x8810C1A4;
	sub_881538C0(ctx, base);
	// lis r27,-30597
	ctx.r27.s64 = -2005204992;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810c1dc
	if (ctx.cr6.eq) goto loc_8810C1DC;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,48
	ctx.r9.s64 = 3145728;
	// lwz r11,-11932(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
	// oris r7,r10,545
	ctx.r7.u64 = ctx.r10.u64 | 35717120;
	// ori r8,r9,32880
	ctx.r8.u64 = ctx.r9.u64 | 32880;
	// ori r7,r7,40960
	ctx.r7.u64 = ctx.r7.u64 | 40960;
	// addi r25,r11,1
	ctx.r25.s64 = ctx.r11.s64 + 1;
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r25,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r25.u32);
	// b 0x8810c1e0
	goto loc_8810C1E0;
loc_8810C1DC:
	// lwz r25,-11932(r27)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
loc_8810C1E0:
	// addi r31,r31,10894
	ctx.r31.s64 = ctx.r31.s64 + 10894;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// addis r5,r29,-88
	ctx.r5.s64 = ctx.r29.s64 + -5767168;
	// addis r4,r30,4
	ctx.r4.s64 = ctx.r30.s64 + 262144;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x881538c0
	ctx.lr = 0x8810C1F8;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810c220
	if (ctx.cr6.eq) goto loc_8810C220;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r25,1
	ctx.r11.s64 = ctx.r25.s64 + 1;
	// oris r8,r10,547
	ctx.r8.u64 = ctx.r10.u64 | 35848192;
	// stw r9,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r9.u32);
	// stw r11,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r11.u32);
	// ori r8,r8,16384
	ctx.r8.u64 = ctx.r8.u64 | 16384;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_8810C220:
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x881538c0
	ctx.lr = 0x8810C234;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810c244
	if (ctx.cr6.eq) goto loc_8810C244;
	// lwz r11,128(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 128);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_8810C244:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810C24C"))) PPC_WEAK_FUNC(sub_8810C24C);
PPC_FUNC_IMPL(__imp__sub_8810C24C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810C250"))) PPC_WEAK_FUNC(sub_8810C250);
PPC_FUNC_IMPL(__imp__sub_8810C250) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807113c
	ctx.lr = 0x8810C258;
	__savegprlr_21(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r5)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r5.u32 + 2304);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,112(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8810c5e0
	if (!ctx.cr6.gt) goto loc_8810C5E0;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// subf. r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r9,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r9.u32);
	// bgt 0x8810c5e0
	if (ctx.cr0.gt) goto loc_8810C5E0;
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8810c290
	if (ctx.cr6.eq) goto loc_8810C290;
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
loc_8810C290:
	// stw r11,144(r31)
	PPC_STORE_U32(ctx.r31.u32 + 144, ctx.r11.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r11,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r11.u32);
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8810c2b0
	if (ctx.cr6.eq) goto loc_8810C2B0;
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
loc_8810C2B0:
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8810c2c0
	if (ctx.cr6.eq) goto loc_8810C2C0;
	// lwz r11,164(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_8810C2C0:
	// lwz r9,116(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// stw r10,2332(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2332, ctx.r10.u32);
	// stw r11,2328(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2328, ctx.r11.u32);
	// lwz r8,148(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8810c2e4
	if (ctx.cr6.eq) goto loc_8810C2E4;
	// li r5,75
	ctx.r5.s64 = 75;
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// bl 0x88095178
	ctx.lr = 0x8810C2E4;
	sub_88095178(ctx, base);
loc_8810C2E4:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x881534c8
	ctx.lr = 0x8810C2EC;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,16
	ctx.r3.s64 = 16;
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r10,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r27,r11,18
	ctx.r27.s64 = ctx.r11.s64 + 18;
	// bl 0x881534c8
	ctx.lr = 0x8810C304;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,15
	ctx.r3.s64 = 15;
	// addi r26,r11,64
	ctx.r26.s64 = ctx.r11.s64 + 64;
	// bl 0x881534c8
	ctx.lr = 0x8810C314;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r9,r11,48
	ctx.r9.s64 = ctx.r11.s64 + 48;
	// rlwinm r25,r9,2,0,29
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x881534c8
	ctx.lr = 0x8810C328;
	sub_881534C8(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lis r30,-30667
	ctx.r30.s64 = -2009792512;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lis r29,-30667
	ctx.r29.s64 = -2009792512;
	// extsh r8,r3
	ctx.r8.s64 = ctx.r3.s16;
	// li r4,135
	ctx.r4.s64 = 135;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// stw r11,12364(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12364, ctx.r11.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stw r10,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r10.u32);
	// rlwinm r24,r7,27,31,31
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// bl 0x880f52c8
	ctx.lr = 0x8810C358;
	sub_880F52C8(ctx, base);
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x880f5570
	ctx.lr = 0x8810C368;
	sub_880F5570(ctx, base);
	// li r21,128
	ctx.r21.s64 = 128;
	// li r23,10
	ctx.r23.s64 = 10;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8810c384
	if (ctx.cr6.eq) goto loc_8810C384;
	// stw r24,148(r28)
	PPC_STORE_U32(ctx.r28.u32 + 148, ctx.r24.u32);
	// stw r21,140(r28)
	PPC_STORE_U32(ctx.r28.u32 + 140, ctx.r21.u32);
	// stw r23,100(r28)
	PPC_STORE_U32(ctx.r28.u32 + 100, ctx.r23.u32);
loc_8810C384:
	// lwz r11,116(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r6,148(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// lwz r5,144(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// lwz r8,2332(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2332);
	// lwz r7,2328(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2328);
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// bl 0x880f5438
	ctx.lr = 0x8810C3A4;
	sub_880F5438(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,127
	ctx.r4.s64 = 127;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stw r11,12364(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r10.u32);
	// bl 0x880f52c8
	ctx.lr = 0x8810C3C0;
	sub_880F52C8(ctx, base);
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x880f5570
	ctx.lr = 0x8810C3D0;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8810c3dc
	if (ctx.cr6.eq) goto loc_8810C3DC;
	// stw r24,148(r28)
	PPC_STORE_U32(ctx.r28.u32 + 148, ctx.r24.u32);
loc_8810C3DC:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x881534c8
	ctx.lr = 0x8810C3E4;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,16
	ctx.r3.s64 = 16;
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r10,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r27,r11,18
	ctx.r27.s64 = ctx.r11.s64 + 18;
	// bl 0x881534c8
	ctx.lr = 0x8810C3FC;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,15
	ctx.r3.s64 = 15;
	// addi r26,r11,96
	ctx.r26.s64 = ctx.r11.s64 + 96;
	// bl 0x881534c8
	ctx.lr = 0x8810C40C;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r9,r11,48
	ctx.r9.s64 = ctx.r11.s64 + 48;
	// rlwinm r25,r9,2,0,29
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x881534c8
	ctx.lr = 0x8810C420;
	sub_881534C8(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// extsh r8,r3
	ctx.r8.s64 = ctx.r3.s16;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r4,135
	ctx.r4.s64 = 135;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// rlwinm r24,r7,27,31,31
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// stw r11,12364(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r10.u32);
	// bl 0x880f52c8
	ctx.lr = 0x8810C448;
	sub_880F52C8(ctx, base);
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x880f5570
	ctx.lr = 0x8810C458;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8810c46c
	if (ctx.cr6.eq) goto loc_8810C46C;
	// stw r24,148(r28)
	PPC_STORE_U32(ctx.r28.u32 + 148, ctx.r24.u32);
	// stw r21,140(r28)
	PPC_STORE_U32(ctx.r28.u32 + 140, ctx.r21.u32);
	// stw r23,100(r28)
	PPC_STORE_U32(ctx.r28.u32 + 100, ctx.r23.u32);
loc_8810C46C:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,127
	ctx.r4.s64 = 127;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stw r11,12364(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r10.u32);
	// bl 0x880f52c8
	ctx.lr = 0x8810C488;
	sub_880F52C8(ctx, base);
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x880f5570
	ctx.lr = 0x8810C498;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8810c4a4
	if (ctx.cr6.eq) goto loc_8810C4A4;
	// stw r24,148(r28)
	PPC_STORE_U32(ctx.r28.u32 + 148, ctx.r24.u32);
loc_8810C4A4:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x881534c8
	ctx.lr = 0x8810C4AC;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,16
	ctx.r3.s64 = 16;
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r11,r9,1
	ctx.r11.u64 = ctx.r9.u64 ^ 1;
	// addi r27,r11,20
	ctx.r27.s64 = ctx.r11.s64 + 20;
	// bl 0x881534c8
	ctx.lr = 0x8810C4C8;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,31
	ctx.r3.s64 = 31;
	// addi r26,r11,112
	ctx.r26.s64 = ctx.r11.s64 + 112;
	// bl 0x881534c8
	ctx.lr = 0x8810C4D8;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r8,r11,40
	ctx.r8.s64 = ctx.r11.s64 + 40;
	// rlwinm r25,r8,2,0,29
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x881534c8
	ctx.lr = 0x8810C4EC;
	sub_881534C8(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// extsh r7,r3
	ctx.r7.s64 = ctx.r3.s16;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r4,135
	ctx.r4.s64 = 135;
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// rlwinm r22,r6,27,31,31
	ctx.r22.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// stw r11,12364(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r10.u32);
	// bl 0x880f52c8
	ctx.lr = 0x8810C514;
	sub_880F52C8(ctx, base);
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x880f5570
	ctx.lr = 0x8810C524;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8810c538
	if (ctx.cr6.eq) goto loc_8810C538;
	// stw r22,148(r28)
	PPC_STORE_U32(ctx.r28.u32 + 148, ctx.r22.u32);
	// stw r21,140(r28)
	PPC_STORE_U32(ctx.r28.u32 + 140, ctx.r21.u32);
	// stw r23,100(r28)
	PPC_STORE_U32(ctx.r28.u32 + 100, ctx.r23.u32);
loc_8810C538:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lis r23,-30667
	ctx.r23.s64 = -2009792512;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lis r24,-30667
	ctx.r24.s64 = -2009792512;
	// li r4,127
	ctx.r4.s64 = 127;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stw r11,12364(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12364, ctx.r11.u32);
	// li r11,127
	ctx.r11.s64 = 127;
	// stw r10,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r10.u32);
	// stw r27,12380(r23)
	PPC_STORE_U32(ctx.r23.u32 + 12380, ctx.r27.u32);
	// stw r11,12376(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12376, ctx.r11.u32);
	// bl 0x880f52c8
	ctx.lr = 0x8810C568;
	sub_880F52C8(ctx, base);
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x880f5570
	ctx.lr = 0x8810C578;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8810c584
	if (ctx.cr6.eq) goto loc_8810C584;
	// stw r22,148(r28)
	PPC_STORE_U32(ctx.r28.u32 + 148, ctx.r22.u32);
loc_8810C584:
	// lwz r11,144(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8810c5c0
	if (!ctx.cr6.eq) goto loc_8810C5C0;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r8,140
	ctx.r8.s64 = 140;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r9,12380(r23)
	PPC_STORE_U32(ctx.r23.u32 + 12380, ctx.r9.u32);
	// li r4,140
	ctx.r4.s64 = 140;
	// stw r8,12376(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12376, ctx.r8.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,12364(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r10.u32);
	// bl 0x881607f8
	ctx.lr = 0x8810C5C0;
	sub_881607F8(ctx, base);
loc_8810C5C0:
	// lwz r11,168(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 168);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// bl 0x88094220
	ctx.lr = 0x8810C5D4;
	sub_88094220(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8807118c
	__restgprlr_21(ctx, base);
	return;
loc_8810C5E0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8807118c
	__restgprlr_21(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810C2E8"))) PPC_WEAK_FUNC(sub_8810C2E8);
PPC_FUNC_IMPL(__imp__sub_8810C2E8) {
	PPC_FUNC_PROLOGUE();
	// bl 0x881534c8
	ctx.lr = 0x8810C2EC;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,16
	ctx.r3.s64 = 16;
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r10,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r27,r11,18
	ctx.r27.s64 = ctx.r11.s64 + 18;
	// bl 0x881534c8
	ctx.lr = 0x8810C304;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,15
	ctx.r3.s64 = 15;
	// addi r26,r11,64
	ctx.r26.s64 = ctx.r11.s64 + 64;
	// bl 0x881534c8
	ctx.lr = 0x8810C314;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r9,r11,48
	ctx.r9.s64 = ctx.r11.s64 + 48;
	// rlwinm r25,r9,2,0,29
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x881534c8
	ctx.lr = 0x8810C328;
	sub_881534C8(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lis r30,-30667
	ctx.r30.s64 = -2009792512;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lis r29,-30667
	ctx.r29.s64 = -2009792512;
	// extsh r8,r3
	ctx.r8.s64 = ctx.r3.s16;
	// li r4,135
	ctx.r4.s64 = 135;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// stw r11,12364(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12364, ctx.r11.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stw r10,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r10.u32);
	// rlwinm r24,r7,27,31,31
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// bl 0x880f52c8
	ctx.lr = 0x8810C358;
	sub_880F52C8(ctx, base);
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x880f5570
	ctx.lr = 0x8810C368;
	sub_880F5570(ctx, base);
	// li r21,128
	ctx.r21.s64 = 128;
	// li r23,10
	ctx.r23.s64 = 10;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8810c384
	if (ctx.cr6.eq) goto loc_8810C384;
	// stw r24,148(r28)
	PPC_STORE_U32(ctx.r28.u32 + 148, ctx.r24.u32);
	// stw r21,140(r28)
	PPC_STORE_U32(ctx.r28.u32 + 140, ctx.r21.u32);
	// stw r23,100(r28)
	PPC_STORE_U32(ctx.r28.u32 + 100, ctx.r23.u32);
loc_8810C384:
	// lwz r11,116(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r6,148(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// lwz r5,144(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// lwz r8,2332(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2332);
	// lwz r7,2328(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2328);
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// bl 0x880f5438
	ctx.lr = 0x8810C3A4;
	sub_880F5438(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,127
	ctx.r4.s64 = 127;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stw r11,12364(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r10.u32);
	// bl 0x880f52c8
	ctx.lr = 0x8810C3C0;
	sub_880F52C8(ctx, base);
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x880f5570
	ctx.lr = 0x8810C3D0;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8810c3dc
	if (ctx.cr6.eq) goto loc_8810C3DC;
	// stw r24,148(r28)
	PPC_STORE_U32(ctx.r28.u32 + 148, ctx.r24.u32);
loc_8810C3DC:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x881534c8
	ctx.lr = 0x8810C3E4;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,16
	ctx.r3.s64 = 16;
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r10,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r27,r11,18
	ctx.r27.s64 = ctx.r11.s64 + 18;
	// bl 0x881534c8
	ctx.lr = 0x8810C3FC;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,15
	ctx.r3.s64 = 15;
	// addi r26,r11,96
	ctx.r26.s64 = ctx.r11.s64 + 96;
	// bl 0x881534c8
	ctx.lr = 0x8810C40C;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r9,r11,48
	ctx.r9.s64 = ctx.r11.s64 + 48;
	// rlwinm r25,r9,2,0,29
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x881534c8
	ctx.lr = 0x8810C420;
	sub_881534C8(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// extsh r8,r3
	ctx.r8.s64 = ctx.r3.s16;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r4,135
	ctx.r4.s64 = 135;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// rlwinm r24,r7,27,31,31
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// stw r11,12364(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r10.u32);
	// bl 0x880f52c8
	ctx.lr = 0x8810C448;
	sub_880F52C8(ctx, base);
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x880f5570
	ctx.lr = 0x8810C458;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8810c46c
	if (ctx.cr6.eq) goto loc_8810C46C;
	// stw r24,148(r28)
	PPC_STORE_U32(ctx.r28.u32 + 148, ctx.r24.u32);
	// stw r21,140(r28)
	PPC_STORE_U32(ctx.r28.u32 + 140, ctx.r21.u32);
	// stw r23,100(r28)
	PPC_STORE_U32(ctx.r28.u32 + 100, ctx.r23.u32);
loc_8810C46C:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,127
	ctx.r4.s64 = 127;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stw r11,12364(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r10.u32);
	// bl 0x880f52c8
	ctx.lr = 0x8810C488;
	sub_880F52C8(ctx, base);
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x880f5570
	ctx.lr = 0x8810C498;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8810c4a4
	if (ctx.cr6.eq) {
		// ERROR 8810C4A4
		return;
	}
}

__attribute__((alias("__imp__sub_8810C4A0"))) PPC_WEAK_FUNC(sub_8810C4A0);
PPC_FUNC_IMPL(__imp__sub_8810C4A0) {
	PPC_FUNC_PROLOGUE();
	// stw r24,148(r28)
	PPC_STORE_U32(ctx.r28.u32 + 148, ctx.r24.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x881534c8
	ctx.lr = 0x8810C4AC;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,16
	ctx.r3.s64 = 16;
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r11,r9,1
	ctx.r11.u64 = ctx.r9.u64 ^ 1;
	// addi r27,r11,20
	ctx.r27.s64 = ctx.r11.s64 + 20;
	// bl 0x881534c8
	ctx.lr = 0x8810C4C8;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,31
	ctx.r3.s64 = 31;
	// addi r26,r11,112
	ctx.r26.s64 = ctx.r11.s64 + 112;
	// bl 0x881534c8
	ctx.lr = 0x8810C4D8;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r8,r11,40
	ctx.r8.s64 = ctx.r11.s64 + 40;
	// rlwinm r25,r8,2,0,29
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x881534c8
	ctx.lr = 0x8810C4EC;
	sub_881534C8(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// extsh r7,r3
	ctx.r7.s64 = ctx.r3.s16;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r4,135
	ctx.r4.s64 = 135;
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// rlwinm r22,r6,27,31,31
	ctx.r22.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// stw r11,12364(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r10.u32);
	// bl 0x880f52c8
	ctx.lr = 0x8810C514;
	sub_880F52C8(ctx, base);
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x880f5570
	ctx.lr = 0x8810C524;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8810c538
	if (ctx.cr6.eq) goto loc_8810C538;
	// stw r22,148(r28)
	PPC_STORE_U32(ctx.r28.u32 + 148, ctx.r22.u32);
	// stw r21,140(r28)
	PPC_STORE_U32(ctx.r28.u32 + 140, ctx.r21.u32);
	// stw r23,100(r28)
	PPC_STORE_U32(ctx.r28.u32 + 100, ctx.r23.u32);
loc_8810C538:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lis r23,-30667
	ctx.r23.s64 = -2009792512;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lis r24,-30667
	ctx.r24.s64 = -2009792512;
	// li r4,127
	ctx.r4.s64 = 127;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stw r11,12364(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12364, ctx.r11.u32);
	// li r11,127
	ctx.r11.s64 = 127;
	// stw r10,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r10.u32);
	// stw r27,12380(r23)
	PPC_STORE_U32(ctx.r23.u32 + 12380, ctx.r27.u32);
	// stw r11,12376(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12376, ctx.r11.u32);
	// bl 0x880f52c8
	ctx.lr = 0x8810C568;
	sub_880F52C8(ctx, base);
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x880f5570
	ctx.lr = 0x8810C578;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8810c584
	if (ctx.cr6.eq) goto loc_8810C584;
	// stw r22,148(r28)
	PPC_STORE_U32(ctx.r28.u32 + 148, ctx.r22.u32);
loc_8810C584:
	// lwz r11,144(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8810c5c0
	if (!ctx.cr6.eq) goto loc_8810C5C0;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r8,140
	ctx.r8.s64 = 140;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r9,12380(r23)
	PPC_STORE_U32(ctx.r23.u32 + 12380, ctx.r9.u32);
	// li r4,140
	ctx.r4.s64 = 140;
	// stw r8,12376(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12376, ctx.r8.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,12364(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r10.u32);
	// bl 0x881607f8
	ctx.lr = 0x8810C5C0;
	sub_881607F8(ctx, base);
loc_8810C5C0:
	// lwz r11,168(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 168);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// bl 0x88094220
	ctx.lr = 0x8810C5D4;
	sub_88094220(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8807118c
	__restgprlr_21(ctx, base);
	return;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8807118c
	__restgprlr_21(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810C5EC"))) PPC_WEAK_FUNC(sub_8810C5EC);
PPC_FUNC_IMPL(__imp__sub_8810C5EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810C5F0"))) PPC_WEAK_FUNC(sub_8810C5F0);
PPC_FUNC_IMPL(__imp__sub_8810C5F0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071144
	ctx.lr = 0x8810C5F8;
	__savegprlr_23(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r24,2304(r3)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lwz r10,168(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// li r25,11014
	ctx.r25.s64 = 11014;
	// lwz r9,184(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// addi r11,r11,-12436
	ctx.r11.s64 = ctx.r11.s64 + -12436;
	// li r3,404
	ctx.r3.s64 = 404;
	// add r23,r9,r10
	ctx.r23.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r10,16(r24)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r24.u32 + 16);
	// li r26,144
	ctx.r26.s64 = 144;
	// lwz r31,0(r24)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// lwz r30,4(r24)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r24.u32 + 4);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x8810c648
	if (!ctx.cr6.eq) goto loc_8810C648;
	// lis r11,-30680
	ctx.r11.s64 = -2010644480;
	// li r25,10990
	ctx.r25.s64 = 10990;
	// addi r11,r11,16064
	ctx.r11.s64 = ctx.r11.s64 + 16064;
	// li r3,416
	ctx.r3.s64 = 416;
	// li r26,160
	ctx.r26.s64 = 160;
loc_8810C648:
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// bne cr6,0x8810c664
	if (!ctx.cr6.eq) goto loc_8810C664;
	// lis r11,-30680
	ctx.r11.s64 = -2010644480;
	// li r25,10966
	ctx.r25.s64 = 10966;
	// addi r11,r11,16112
	ctx.r11.s64 = ctx.r11.s64 + 16112;
	// li r3,419
	ctx.r3.s64 = 419;
	// li r26,160
	ctx.r26.s64 = 160;
loc_8810C664:
	// lwz r9,12(r24)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r24.u32 + 12);
	// lwz r28,108(r24)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r24.u32 + 108);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8810c7e8
	if (ctx.cr6.eq) goto loc_8810C7E8;
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x8810c6a4
	if (!ctx.cr6.eq) goto loc_8810C6A4;
	// rlwinm r10,r28,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// lbz r7,1(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// extsb r6,r8
	ctx.r6.s64 = ctx.r8.s8;
	// extsb r5,r7
	ctx.r5.s64 = ctx.r7.s8;
	// rlwinm r4,r6,16,0,15
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r5,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// subf r31,r4,r31
	ctx.r31.s64 = ctx.r31.s64 - ctx.r4.s64;
	// add r30,r10,r30
	ctx.r30.u64 = ctx.r10.u64 + ctx.r30.u64;
loc_8810C6A4:
	// cmpwi cr6,r9,2
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 2, ctx.xer);
	// bne cr6,0x8810c6d4
	if (!ctx.cr6.eq) goto loc_8810C6D4;
	// rlwinm r10,r28,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// lbz r7,1(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// extsb r6,r8
	ctx.r6.s64 = ctx.r8.s8;
	// extsb r5,r7
	ctx.r5.s64 = ctx.r7.s8;
	// rlwinm r10,r6,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r4,r5,16,0,15
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// add r31,r10,r31
	ctx.r31.u64 = ctx.r10.u64 + ctx.r31.u64;
	// subf r30,r4,r30
	ctx.r30.s64 = ctx.r30.s64 - ctx.r4.s64;
loc_8810C6D4:
	// cmpwi cr6,r9,3
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 3, ctx.xer);
	// bne cr6,0x8810c704
	if (!ctx.cr6.eq) goto loc_8810C704;
	// rlwinm r10,r28,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r9,1(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// extsb r8,r10
	ctx.r8.s64 = ctx.r10.s8;
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// rlwinm r6,r8,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r5,r7,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// subf r31,r6,r31
	ctx.r31.s64 = ctx.r31.s64 - ctx.r6.s64;
	// subf r30,r5,r30
	ctx.r30.s64 = ctx.r30.s64 - ctx.r5.s64;
loc_8810C704:
	// addi r27,r23,-1
	ctx.r27.s64 = ctx.r23.s64 + -1;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x881538c0
	ctx.lr = 0x8810C718;
	sub_881538C0(ctx, base);
	// lis r29,-30597
	ctx.r29.s64 = -2005204992;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810c754
	if (ctx.cr6.eq) goto loc_8810C754;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-11932(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -11932);
	// lis r8,48
	ctx.r8.s64 = 3145728;
	// rlwimi r10,r26,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r26.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// ori r7,r8,32880
	ctx.r7.u64 = ctx.r8.u64 | 32880;
	// addi r26,r11,1
	ctx.r26.s64 = ctx.r11.s64 + 1;
	// or r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r7,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r7.u32);
	// stw r26,-11932(r29)
	PPC_STORE_U32(ctx.r29.u32 + -11932, ctx.r26.u32);
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// b 0x8810c758
	goto loc_8810C758;
loc_8810C754:
	// lwz r26,-11932(r29)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r29.u32 + -11932);
loc_8810C758:
	// add r28,r28,r25
	ctx.r28.u64 = ctx.r28.u64 + ctx.r25.u64;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// addis r5,r30,-88
	ctx.r5.s64 = ctx.r30.s64 + -5767168;
	// addis r4,r31,4
	ctx.r4.s64 = ctx.r31.s64 + 262144;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x881538c0
	ctx.lr = 0x8810C770;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810c7a8
	if (ctx.cr6.eq) goto loc_8810C7A8;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r26,1
	ctx.r11.s64 = ctx.r26.s64 + 1;
	// oris r8,r10,547
	ctx.r8.u64 = ctx.r10.u64 | 35848192;
	// stw r9,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r9.u32);
	// stw r11,-11932(r29)
	PPC_STORE_U32(ctx.r29.u32 + -11932, ctx.r11.u32);
	// ori r8,r8,24576
	ctx.r8.u64 = ctx.r8.u64 | 24576;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// lwz r7,12(r24)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r24.u32 + 12);
	// rlwinm r6,r7,26,0,5
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 26) & 0xFC000000;
	// or r5,r6,r8
	ctx.r5.u64 = ctx.r6.u64 | ctx.r8.u64;
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
loc_8810C7A8:
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x881538c0
	ctx.lr = 0x8810C7BC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810c8c8
	if (ctx.cr6.eq) goto loc_8810C8C8;
	// lwz r11,128(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 128);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
	// lwz r9,12(r24)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r24.u32 + 12);
	// rlwinm r8,r9,26,0,5
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 26) & 0xFC000000;
	// or r7,r8,r10
	ctx.r7.u64 = ctx.r8.u64 | ctx.r10.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
loc_8810C7E8:
	// rlwinm r10,r28,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r29,r23,-1
	ctx.r29.s64 = ctx.r23.s64 + -1;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r9,1(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// extsb r8,r10
	ctx.r8.s64 = ctx.r10.s8;
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// rlwinm r10,r8,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r7,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// add r31,r10,r31
	ctx.r31.u64 = ctx.r10.u64 + ctx.r31.u64;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// bl 0x881538c0
	ctx.lr = 0x8810C824;
	sub_881538C0(ctx, base);
	// lis r27,-30597
	ctx.r27.s64 = -2005204992;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810c860
	if (ctx.cr6.eq) goto loc_8810C860;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-11932(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
	// lis r8,48
	ctx.r8.s64 = 3145728;
	// rlwimi r10,r26,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r26.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// ori r7,r8,32880
	ctx.r7.u64 = ctx.r8.u64 | 32880;
	// addi r26,r11,1
	ctx.r26.s64 = ctx.r11.s64 + 1;
	// or r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r7,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r7.u32);
	// stw r26,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r26.u32);
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// b 0x8810c864
	goto loc_8810C864;
loc_8810C860:
	// lwz r26,-11932(r27)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11932);
loc_8810C864:
	// add r28,r28,r25
	ctx.r28.u64 = ctx.r28.u64 + ctx.r25.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// addis r5,r30,-88
	ctx.r5.s64 = ctx.r30.s64 + -5767168;
	// addis r4,r31,4
	ctx.r4.s64 = ctx.r31.s64 + 262144;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x881538c0
	ctx.lr = 0x8810C87C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810c8a4
	if (ctx.cr6.eq) goto loc_8810C8A4;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r26,1
	ctx.r11.s64 = ctx.r26.s64 + 1;
	// oris r8,r10,547
	ctx.r8.u64 = ctx.r10.u64 | 35848192;
	// stw r9,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r9.u32);
	// stw r11,-11932(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11932, ctx.r11.u32);
	// ori r8,r8,24576
	ctx.r8.u64 = ctx.r8.u64 | 24576;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_8810C8A4:
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x881538c0
	ctx.lr = 0x8810C8B8;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810c8c8
	if (ctx.cr6.eq) goto loc_8810C8C8;
	// lwz r11,128(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 128);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_8810C8C8:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810C8D0"))) PPC_WEAK_FUNC(sub_8810C8D0);
PPC_FUNC_IMPL(__imp__sub_8810C8D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071124
	ctx.lr = 0x8810C8D8;
	__savegprlr_15(ctx, base);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r5)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r5.u32 + 2304);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,112(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8810ce80
	if (!ctx.cr6.gt) goto loc_8810CE80;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// subf. r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r9,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r9.u32);
	// bgt 0x8810ce80
	if (ctx.cr0.gt) goto loc_8810CE80;
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8810c910
	if (ctx.cr6.eq) goto loc_8810C910;
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
loc_8810C910:
	// stw r11,144(r31)
	PPC_STORE_U32(ctx.r31.u32 + 144, ctx.r11.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r11,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r11.u32);
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8810c930
	if (ctx.cr6.eq) goto loc_8810C930;
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
loc_8810C930:
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8810c940
	if (ctx.cr6.eq) goto loc_8810C940;
	// lwz r11,164(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_8810C940:
	// lwz r9,116(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// stw r10,2332(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2332, ctx.r10.u32);
	// stw r11,2328(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2328, ctx.r11.u32);
	// lwz r8,148(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8810c964
	if (ctx.cr6.eq) goto loc_8810C964;
	// li r5,75
	ctx.r5.s64 = 75;
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// bl 0x88095178
	ctx.lr = 0x8810C964;
	sub_88095178(ctx, base);
loc_8810C964:
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// li r15,2
	ctx.r15.s64 = 2;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,-11984(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11984);
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// cmpwi cr6,r10,344
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 344, ctx.xer);
	// bge cr6,0x8810cb4c
	if (!ctx.cr6.lt) goto loc_8810CB4C;
	// bl 0x881534c8
	ctx.lr = 0x8810C984;
	sub_881534C8(ctx, base);
	// lis r10,-30667
	ctx.r10.s64 = -2009792512;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lis r9,-30667
	ctx.r9.s64 = -2009792512;
	// addi r22,r10,12364
	ctx.r22.s64 = ctx.r10.s64 + 12364;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// extsh r8,r3
	ctx.r8.s64 = ctx.r3.s16;
	// li r4,135
	ctx.r4.s64 = 135;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// li r3,18
	ctx.r3.s64 = 18;
	// stw r11,0(r22)
	PPC_STORE_U32(ctx.r22.u32 + 0, ctx.r11.u32);
	// addi r21,r9,12372
	ctx.r21.s64 = ctx.r9.s64 + 12372;
	// stw r10,12372(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12372, ctx.r10.u32);
	// rlwinm r29,r7,27,31,31
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// bl 0x880f52c8
	ctx.lr = 0x8810C9BC;
	sub_880F52C8(ctx, base);
	// lwz r5,76(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// lwz r4,68(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x880f5570
	ctx.lr = 0x8810C9CC;
	sub_880F5570(ctx, base);
	// li r26,128
	ctx.r26.s64 = 128;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8810c9e8
	if (ctx.cr6.eq) goto loc_8810C9E8;
	// li r11,10
	ctx.r11.s64 = 10;
	// stw r29,148(r30)
	PPC_STORE_U32(ctx.r30.u32 + 148, ctx.r29.u32);
	// stw r26,140(r30)
	PPC_STORE_U32(ctx.r30.u32 + 140, ctx.r26.u32);
	// stw r11,100(r30)
	PPC_STORE_U32(ctx.r30.u32 + 100, ctx.r11.u32);
loc_8810C9E8:
	// lwz r11,116(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r6,148(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// lwz r5,144(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// lwz r8,2332(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2332);
	// lwz r7,2328(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2328);
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// bl 0x880f5438
	ctx.lr = 0x8810CA08;
	sub_880F5438(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,127
	ctx.r4.s64 = 127;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r3,18
	ctx.r3.s64 = 18;
	// stw r11,0(r22)
	PPC_STORE_U32(ctx.r22.u32 + 0, ctx.r11.u32);
	// stw r10,0(r21)
	PPC_STORE_U32(ctx.r21.u32 + 0, ctx.r10.u32);
	// bl 0x880f52c8
	ctx.lr = 0x8810CA24;
	sub_880F52C8(ctx, base);
	// lwz r5,76(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// lwz r4,68(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x880f5570
	ctx.lr = 0x8810CA34;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8810ca48
	if (ctx.cr6.eq) goto loc_8810CA48;
	// li r11,8
	ctx.r11.s64 = 8;
	// stw r29,148(r30)
	PPC_STORE_U32(ctx.r30.u32 + 148, ctx.r29.u32);
	// stw r11,100(r30)
	PPC_STORE_U32(ctx.r30.u32 + 100, ctx.r11.u32);
loc_8810CA48:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x881534c8
	ctx.lr = 0x8810CA50;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,15
	ctx.r3.s64 = 15;
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r11,r9,1
	ctx.r11.u64 = ctx.r9.u64 ^ 1;
	// addi r29,r11,20
	ctx.r29.s64 = ctx.r11.s64 + 20;
	// bl 0x881534c8
	ctx.lr = 0x8810CA6C;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lwz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r8,r11,-8
	ctx.r8.s64 = ctx.r11.s64 + -8;
	// rlwinm r11,r8,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r28,r11,r10
	ctx.r28.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881534c8
	ctx.lr = 0x8810CA88;
	sub_881534C8(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// extsh r7,r3
	ctx.r7.s64 = ctx.r3.s16;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r4,135
	ctx.r4.s64 = 135;
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// rlwinm r27,r6,27,31,31
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// stw r11,0(r22)
	PPC_STORE_U32(ctx.r22.u32 + 0, ctx.r11.u32);
	// stw r10,0(r21)
	PPC_STORE_U32(ctx.r21.u32 + 0, ctx.r10.u32);
	// bl 0x880f52c8
	ctx.lr = 0x8810CAB0;
	sub_880F52C8(ctx, base);
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// srawi r11,r4,1
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r4.s32 >> 1;
	// addze r4,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r4.s64 = temp.s64;
	// bl 0x880f5570
	ctx.lr = 0x8810CAD0;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8810cae4
	if (ctx.cr6.eq) goto loc_8810CAE4;
	// stw r27,148(r30)
	PPC_STORE_U32(ctx.r30.u32 + 148, ctx.r27.u32);
	// stw r26,140(r30)
	PPC_STORE_U32(ctx.r30.u32 + 140, ctx.r26.u32);
	// stw r15,100(r30)
	PPC_STORE_U32(ctx.r30.u32 + 100, ctx.r15.u32);
loc_8810CAE4:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lis r9,-30667
	ctx.r9.s64 = -2009792512;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lis r8,-30667
	ctx.r8.s64 = -2009792512;
	// li r4,127
	ctx.r4.s64 = 127;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r20,r9,12380
	ctx.r20.s64 = ctx.r9.s64 + 12380;
	// stw r11,0(r22)
	PPC_STORE_U32(ctx.r22.u32 + 0, ctx.r11.u32);
	// li r11,127
	ctx.r11.s64 = 127;
	// stw r10,0(r21)
	PPC_STORE_U32(ctx.r21.u32 + 0, ctx.r10.u32);
	// addi r19,r8,12376
	ctx.r19.s64 = ctx.r8.s64 + 12376;
	// stw r29,12380(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12380, ctx.r29.u32);
	// stw r11,12376(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12376, ctx.r11.u32);
	// bl 0x880f52c8
	ctx.lr = 0x8810CB1C;
	sub_880F52C8(ctx, base);
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// srawi r10,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 1;
	// addze r4,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r4.s64 = temp.s64;
	// bl 0x880f5570
	ctx.lr = 0x8810CB3C;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8810cc8c
	if (ctx.cr6.eq) goto loc_8810CC8C;
	// stw r27,148(r30)
	PPC_STORE_U32(ctx.r30.u32 + 148, ctx.r27.u32);
	// b 0x8810cc8c
	goto loc_8810CC8C;
loc_8810CB4C:
	// bl 0x881534c8
	ctx.lr = 0x8810CB50;
	sub_881534C8(ctx, base);
	// lis r10,-30667
	ctx.r10.s64 = -2009792512;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lis r9,-30667
	ctx.r9.s64 = -2009792512;
	// addi r22,r10,12364
	ctx.r22.s64 = ctx.r10.s64 + 12364;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// extsh r8,r3
	ctx.r8.s64 = ctx.r3.s16;
	// li r4,135
	ctx.r4.s64 = 135;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// li r3,18
	ctx.r3.s64 = 18;
	// stw r11,0(r22)
	PPC_STORE_U32(ctx.r22.u32 + 0, ctx.r11.u32);
	// addi r21,r9,12372
	ctx.r21.s64 = ctx.r9.s64 + 12372;
	// stw r10,12372(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12372, ctx.r10.u32);
	// rlwinm r29,r7,27,31,31
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// bl 0x880f52c8
	ctx.lr = 0x8810CB88;
	sub_880F52C8(ctx, base);
	// lwz r5,76(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// lwz r4,68(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x880f5570
	ctx.lr = 0x8810CB98;
	sub_880F5570(ctx, base);
	// li r27,160
	ctx.r27.s64 = 160;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8810cbb4
	if (ctx.cr6.eq) goto loc_8810CBB4;
	// li r11,10
	ctx.r11.s64 = 10;
	// stw r29,148(r30)
	PPC_STORE_U32(ctx.r30.u32 + 148, ctx.r29.u32);
	// stw r27,140(r30)
	PPC_STORE_U32(ctx.r30.u32 + 140, ctx.r27.u32);
	// stw r11,100(r30)
	PPC_STORE_U32(ctx.r30.u32 + 100, ctx.r11.u32);
loc_8810CBB4:
	// lwz r11,116(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r6,148(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// lwz r5,144(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// lwz r8,2332(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2332);
	// lwz r7,2328(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2328);
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// bl 0x880f5438
	ctx.lr = 0x8810CBD4;
	sub_880F5438(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x881534c8
	ctx.lr = 0x8810CBDC;
	sub_881534C8(ctx, base);
	// extsh r10,r3
	ctx.r10.s64 = ctx.r3.s16;
	// li r3,15
	ctx.r3.s64 = 15;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r11,r8,1
	ctx.r11.u64 = ctx.r8.u64 ^ 1;
	// addi r30,r11,20
	ctx.r30.s64 = ctx.r11.s64 + 20;
	// bl 0x881534c8
	ctx.lr = 0x8810CBF8;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lwz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r7,r11,-8
	ctx.r7.s64 = ctx.r11.s64 + -8;
	// rlwinm r11,r7,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r29,r11,r10
	ctx.r29.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881534c8
	ctx.lr = 0x8810CC14;
	sub_881534C8(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lis r8,-30667
	ctx.r8.s64 = -2009792512;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lis r9,-30667
	ctx.r9.s64 = -2009792512;
	// extsh r6,r3
	ctx.r6.s64 = ctx.r3.s16;
	// li r4,135
	ctx.r4.s64 = 135;
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// stw r11,0(r22)
	PPC_STORE_U32(ctx.r22.u32 + 0, ctx.r11.u32);
	// li r11,135
	ctx.r11.s64 = 135;
	// stw r10,0(r21)
	PPC_STORE_U32(ctx.r21.u32 + 0, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r20,r8,12380
	ctx.r20.s64 = ctx.r8.s64 + 12380;
	// stw r30,12380(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12380, ctx.r30.u32);
	// addi r19,r9,12376
	ctx.r19.s64 = ctx.r9.s64 + 12376;
	// stw r11,12376(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12376, ctx.r11.u32);
	// rlwinm r28,r5,27,31,31
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// bl 0x880f52c8
	ctx.lr = 0x8810CC58;
	sub_880F52C8(ctx, base);
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// srawi r11,r4,1
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r4.s32 >> 1;
	// addze r4,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r4.s64 = temp.s64;
	// bl 0x880f5570
	ctx.lr = 0x8810CC78;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8810cc8c
	if (ctx.cr6.eq) goto loc_8810CC8C;
	// stw r28,148(r30)
	PPC_STORE_U32(ctx.r30.u32 + 148, ctx.r28.u32);
	// stw r27,140(r30)
	PPC_STORE_U32(ctx.r30.u32 + 140, ctx.r27.u32);
	// stw r15,100(r30)
	PPC_STORE_U32(ctx.r30.u32 + 100, ctx.r15.u32);
loc_8810CC8C:
	// lwz r11,152(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 152);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8810ce10
	if (!ctx.cr6.eq) goto loc_8810CE10;
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lis r5,96
	ctx.r5.s64 = 6291456;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// bl 0x88094c70
	ctx.lr = 0x8810CCAC;
	sub_88094C70(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8810ce10
	if (ctx.cr6.eq) goto loc_8810CE10;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// bl 0x88095590
	ctx.lr = 0x8810CCC4;
	sub_88095590(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x881534c8
	ctx.lr = 0x8810CCD0;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// addi r11,r11,-8
	ctx.r11.s64 = ctx.r11.s64 + -8;
	// li r16,16
	ctx.r16.s64 = 16;
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// li r23,1
	ctx.r23.s64 = 1;
	// addi r28,r11,-256
	ctx.r28.s64 = ctx.r11.s64 + -256;
	// lwz r27,26276(r10)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26276);
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// li r17,48
	ctx.r17.s64 = 48;
	// li r25,3
	ctx.r25.s64 = 3;
	// li r24,-1
	ctx.r24.s64 = -1;
	// li r18,64
	ctx.r18.s64 = 64;
	// addi r26,r11,9552
	ctx.r26.s64 = ctx.r11.s64 + 9552;
loc_8810CD08:
	// addi r11,r28,-256
	ctx.r11.s64 = ctx.r28.s64 + -256;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// addi r10,r11,128
	ctx.r10.s64 = ctx.r11.s64 + 128;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r6,r10,2,21,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0x7FC;
	// lwzx r11,r7,r26
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r26.u32);
	// lwzx r10,r6,r26
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r26.u32);
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r11,r7
	ctx.r5.u64 = ctx.r11.u64 + ctx.r7.u64;
	// add r4,r10,r6
	ctx.r4.u64 = ctx.r10.u64 + ctx.r6.u64;
	// rlwinm r29,r5,6,0,25
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 6) & 0xFFFFFFC0;
	// rlwinm r30,r4,6,0,25
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 6) & 0xFFFFFFC0;
	// add r4,r9,r29
	ctx.r4.u64 = ctx.r9.u64 + ctx.r29.u64;
	// add r5,r8,r30
	ctx.r5.u64 = ctx.r8.u64 + ctx.r30.u64;
	// bne cr6,0x8810cd88
	if (!ctx.cr6.eq) goto loc_8810CD88;
	// lwz r11,116(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// clrlwi r7,r28,23
	ctx.r7.u64 = ctx.r28.u32 & 0x1FF;
	// li r6,-45
	ctx.r6.s64 = -45;
	// sth r23,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r23.u16);
	// li r3,26
	ctx.r3.s64 = 26;
	// stw r15,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r15.u32);
	// stw r17,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r17.u32);
	// stw r25,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r25.u32);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r24,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r24.u32);
	// bl 0x8815c948
	ctx.lr = 0x8810CD80;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x8810CD88;
	sub_8815C860(ctx, base);
loc_8810CD88:
	// rlwinm r8,r29,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r11,r30,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// add r8,r29,r8
	ctx.r8.u64 = ctx.r29.u64 + ctx.r8.u64;
	// add r7,r30,r11
	ctx.r7.u64 = ctx.r30.u64 + ctx.r11.u64;
	// srawi r6,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 1;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// addze r11,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r11.s64 = temp.s64;
	// srawi r5,r7,1
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r5.s64 = ctx.r7.s32 >> 1;
	// add r4,r11,r9
	ctx.r4.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addze r11,r5
	temp.s64 = ctx.r5.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r11.s64 = temp.s64;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bne cr6,0x8810ce04
	if (!ctx.cr6.eq) goto loc_8810CE04;
	// lwz r11,116(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// clrlwi r7,r28,23
	ctx.r7.u64 = ctx.r28.u32 & 0x1FF;
	// li r6,-45
	ctx.r6.s64 = -45;
	// sth r23,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r23.u16);
	// li r3,59
	ctx.r3.s64 = 59;
	// stw r25,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r25.u32);
	// stw r18,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r18.u32);
	// stw r25,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r25.u32);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r24,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r24.u32);
	// bl 0x8815c948
	ctx.lr = 0x8810CDEC;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x8815c860
	ctx.lr = 0x8810CDF8;
	sub_8815C860(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8810ce04
	if (ctx.cr6.eq) goto loc_8810CE04;
	// sth r24,16(r30)
	PPC_STORE_U16(ctx.r30.u32 + 16, ctx.r24.u16);
loc_8810CE04:
	// addic. r16,r16,-1
	ctx.xer.ca = ctx.r16.u32 > 0;
	ctx.r16.s64 = ctx.r16.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r16.s32, 0, ctx.xer);
	// addi r28,r28,32
	ctx.r28.s64 = ctx.r28.s64 + 32;
	// bne 0x8810cd08
	if (!ctx.cr0.eq) goto loc_8810CD08;
loc_8810CE10:
	// lwz r11,144(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8810ce4c
	if (!ctx.cr6.eq) goto loc_8810CE4C;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r8,140
	ctx.r8.s64 = 140;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r9,0(r20)
	PPC_STORE_U32(ctx.r20.u32 + 0, ctx.r9.u32);
	// li r4,140
	ctx.r4.s64 = 140;
	// stw r8,0(r19)
	PPC_STORE_U32(ctx.r19.u32 + 0, ctx.r8.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,0(r22)
	PPC_STORE_U32(ctx.r22.u32 + 0, ctx.r11.u32);
	// stw r10,0(r21)
	PPC_STORE_U32(ctx.r21.u32 + 0, ctx.r10.u32);
	// bl 0x881607f8
	ctx.lr = 0x8810CE4C;
	sub_881607F8(ctx, base);
loc_8810CE4C:
	// lwz r11,172(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 172);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,40
	ctx.r5.s64 = 40;
	// li r4,93
	ctx.r4.s64 = 93;
	// li r3,5
	ctx.r3.s64 = 5;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x880e32d0
	ctx.lr = 0x8810CE6C;
	sub_880E32D0(ctx, base);
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// bl 0x88094220
	ctx.lr = 0x8810CE74;
	sub_88094220(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x88071174
	__restgprlr_15(ctx, base);
	return;
loc_8810CE80:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x88071174
	__restgprlr_15(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810C920"))) PPC_WEAK_FUNC(sub_8810C920);
PPC_FUNC_IMPL(__imp__sub_8810C920) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8810c930
	if (ctx.cr6.eq) goto loc_8810C930;
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
loc_8810C930:
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8810c940
	if (ctx.cr6.eq) goto loc_8810C940;
	// lwz r11,164(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_8810C940:
	// lwz r9,116(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// stw r10,2332(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2332, ctx.r10.u32);
	// stw r11,2328(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2328, ctx.r11.u32);
	// lwz r8,148(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8810c964
	if (ctx.cr6.eq) goto loc_8810C964;
	// li r5,75
	ctx.r5.s64 = 75;
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// bl 0x88095178
	ctx.lr = 0x8810C964;
	sub_88095178(ctx, base);
loc_8810C964:
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// li r15,2
	ctx.r15.s64 = 2;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,-11984(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11984);
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// cmpwi cr6,r10,344
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 344, ctx.xer);
	// bge cr6,0x8810cb4c
	if (!ctx.cr6.lt) goto loc_8810CB4C;
	// bl 0x881534c8
	ctx.lr = 0x8810C984;
	sub_881534C8(ctx, base);
	// lis r10,-30667
	ctx.r10.s64 = -2009792512;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lis r9,-30667
	ctx.r9.s64 = -2009792512;
	// addi r22,r10,12364
	ctx.r22.s64 = ctx.r10.s64 + 12364;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// extsh r8,r3
	ctx.r8.s64 = ctx.r3.s16;
	// li r4,135
	ctx.r4.s64 = 135;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// li r3,18
	ctx.r3.s64 = 18;
	// stw r11,0(r22)
	PPC_STORE_U32(ctx.r22.u32 + 0, ctx.r11.u32);
	// addi r21,r9,12372
	ctx.r21.s64 = ctx.r9.s64 + 12372;
	// stw r10,12372(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12372, ctx.r10.u32);
	// rlwinm r29,r7,27,31,31
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// bl 0x880f52c8
	ctx.lr = 0x8810C9BC;
	sub_880F52C8(ctx, base);
	// lwz r5,76(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// lwz r4,68(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x880f5570
	ctx.lr = 0x8810C9CC;
	sub_880F5570(ctx, base);
	// li r26,128
	ctx.r26.s64 = 128;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8810c9e8
	if (ctx.cr6.eq) goto loc_8810C9E8;
	// li r11,10
	ctx.r11.s64 = 10;
	// stw r29,148(r30)
	PPC_STORE_U32(ctx.r30.u32 + 148, ctx.r29.u32);
	// stw r26,140(r30)
	PPC_STORE_U32(ctx.r30.u32 + 140, ctx.r26.u32);
	// stw r11,100(r30)
	PPC_STORE_U32(ctx.r30.u32 + 100, ctx.r11.u32);
loc_8810C9E8:
	// lwz r11,116(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r6,148(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// lwz r5,144(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// lwz r8,2332(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2332);
	// lwz r7,2328(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2328);
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// bl 0x880f5438
	ctx.lr = 0x8810CA08;
	sub_880F5438(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,127
	ctx.r4.s64 = 127;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r3,18
	ctx.r3.s64 = 18;
	// stw r11,0(r22)
	PPC_STORE_U32(ctx.r22.u32 + 0, ctx.r11.u32);
	// stw r10,0(r21)
	PPC_STORE_U32(ctx.r21.u32 + 0, ctx.r10.u32);
	// bl 0x880f52c8
	ctx.lr = 0x8810CA24;
	sub_880F52C8(ctx, base);
	// lwz r5,76(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// lwz r4,68(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x880f5570
	ctx.lr = 0x8810CA34;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8810ca48
	if (ctx.cr6.eq) goto loc_8810CA48;
	// li r11,8
	ctx.r11.s64 = 8;
	// stw r29,148(r30)
	PPC_STORE_U32(ctx.r30.u32 + 148, ctx.r29.u32);
	// stw r11,100(r30)
	PPC_STORE_U32(ctx.r30.u32 + 100, ctx.r11.u32);
loc_8810CA48:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x881534c8
	ctx.lr = 0x8810CA50;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,15
	ctx.r3.s64 = 15;
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r11,r9,1
	ctx.r11.u64 = ctx.r9.u64 ^ 1;
	// addi r29,r11,20
	ctx.r29.s64 = ctx.r11.s64 + 20;
	// bl 0x881534c8
	ctx.lr = 0x8810CA6C;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lwz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r8,r11,-8
	ctx.r8.s64 = ctx.r11.s64 + -8;
	// rlwinm r11,r8,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r28,r11,r10
	ctx.r28.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881534c8
	ctx.lr = 0x8810CA88;
	sub_881534C8(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// extsh r7,r3
	ctx.r7.s64 = ctx.r3.s16;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r4,135
	ctx.r4.s64 = 135;
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// rlwinm r27,r6,27,31,31
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// stw r11,0(r22)
	PPC_STORE_U32(ctx.r22.u32 + 0, ctx.r11.u32);
	// stw r10,0(r21)
	PPC_STORE_U32(ctx.r21.u32 + 0, ctx.r10.u32);
	// bl 0x880f52c8
	ctx.lr = 0x8810CAB0;
	sub_880F52C8(ctx, base);
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// srawi r11,r4,1
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r4.s32 >> 1;
	// addze r4,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r4.s64 = temp.s64;
	// bl 0x880f5570
	ctx.lr = 0x8810CAD0;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8810cae4
	if (ctx.cr6.eq) goto loc_8810CAE4;
	// stw r27,148(r30)
	PPC_STORE_U32(ctx.r30.u32 + 148, ctx.r27.u32);
	// stw r26,140(r30)
	PPC_STORE_U32(ctx.r30.u32 + 140, ctx.r26.u32);
	// stw r15,100(r30)
	PPC_STORE_U32(ctx.r30.u32 + 100, ctx.r15.u32);
loc_8810CAE4:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lis r9,-30667
	ctx.r9.s64 = -2009792512;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lis r8,-30667
	ctx.r8.s64 = -2009792512;
	// li r4,127
	ctx.r4.s64 = 127;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r20,r9,12380
	ctx.r20.s64 = ctx.r9.s64 + 12380;
	// stw r11,0(r22)
	PPC_STORE_U32(ctx.r22.u32 + 0, ctx.r11.u32);
	// li r11,127
	ctx.r11.s64 = 127;
	// stw r10,0(r21)
	PPC_STORE_U32(ctx.r21.u32 + 0, ctx.r10.u32);
	// addi r19,r8,12376
	ctx.r19.s64 = ctx.r8.s64 + 12376;
	// stw r29,12380(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12380, ctx.r29.u32);
	// stw r11,12376(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12376, ctx.r11.u32);
	// bl 0x880f52c8
	ctx.lr = 0x8810CB1C;
	sub_880F52C8(ctx, base);
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// srawi r10,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 1;
	// addze r4,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r4.s64 = temp.s64;
	// bl 0x880f5570
	ctx.lr = 0x8810CB3C;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8810cc8c
	if (ctx.cr6.eq) goto loc_8810CC8C;
	// stw r27,148(r30)
	PPC_STORE_U32(ctx.r30.u32 + 148, ctx.r27.u32);
	// b 0x8810cc8c
	goto loc_8810CC8C;
loc_8810CB4C:
	// bl 0x881534c8
	ctx.lr = 0x8810CB50;
	sub_881534C8(ctx, base);
	// lis r10,-30667
	ctx.r10.s64 = -2009792512;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lis r9,-30667
	ctx.r9.s64 = -2009792512;
	// addi r22,r10,12364
	ctx.r22.s64 = ctx.r10.s64 + 12364;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// extsh r8,r3
	ctx.r8.s64 = ctx.r3.s16;
	// li r4,135
	ctx.r4.s64 = 135;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// li r3,18
	ctx.r3.s64 = 18;
	// stw r11,0(r22)
	PPC_STORE_U32(ctx.r22.u32 + 0, ctx.r11.u32);
	// addi r21,r9,12372
	ctx.r21.s64 = ctx.r9.s64 + 12372;
	// stw r10,12372(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12372, ctx.r10.u32);
	// rlwinm r29,r7,27,31,31
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// bl 0x880f52c8
	ctx.lr = 0x8810CB88;
	sub_880F52C8(ctx, base);
	// lwz r5,76(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// lwz r4,68(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x880f5570
	ctx.lr = 0x8810CB98;
	sub_880F5570(ctx, base);
	// li r27,160
	ctx.r27.s64 = 160;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8810cbb4
	if (ctx.cr6.eq) goto loc_8810CBB4;
	// li r11,10
	ctx.r11.s64 = 10;
	// stw r29,148(r30)
	PPC_STORE_U32(ctx.r30.u32 + 148, ctx.r29.u32);
	// stw r27,140(r30)
	PPC_STORE_U32(ctx.r30.u32 + 140, ctx.r27.u32);
	// stw r11,100(r30)
	PPC_STORE_U32(ctx.r30.u32 + 100, ctx.r11.u32);
loc_8810CBB4:
	// lwz r11,116(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r6,148(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// lwz r5,144(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// lwz r8,2332(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2332);
	// lwz r7,2328(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2328);
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// bl 0x880f5438
	ctx.lr = 0x8810CBD4;
	sub_880F5438(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x881534c8
	ctx.lr = 0x8810CBDC;
	sub_881534C8(ctx, base);
	// extsh r10,r3
	ctx.r10.s64 = ctx.r3.s16;
	// li r3,15
	ctx.r3.s64 = 15;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r11,r8,1
	ctx.r11.u64 = ctx.r8.u64 ^ 1;
	// addi r30,r11,20
	ctx.r30.s64 = ctx.r11.s64 + 20;
	// bl 0x881534c8
	ctx.lr = 0x8810CBF8;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lwz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r7,r11,-8
	ctx.r7.s64 = ctx.r11.s64 + -8;
	// rlwinm r11,r7,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r29,r11,r10
	ctx.r29.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881534c8
	ctx.lr = 0x8810CC14;
	sub_881534C8(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lis r8,-30667
	ctx.r8.s64 = -2009792512;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lis r9,-30667
	ctx.r9.s64 = -2009792512;
	// extsh r6,r3
	ctx.r6.s64 = ctx.r3.s16;
	// li r4,135
	ctx.r4.s64 = 135;
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// stw r11,0(r22)
	PPC_STORE_U32(ctx.r22.u32 + 0, ctx.r11.u32);
	// li r11,135
	ctx.r11.s64 = 135;
	// stw r10,0(r21)
	PPC_STORE_U32(ctx.r21.u32 + 0, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r20,r8,12380
	ctx.r20.s64 = ctx.r8.s64 + 12380;
	// stw r30,12380(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12380, ctx.r30.u32);
	// addi r19,r9,12376
	ctx.r19.s64 = ctx.r9.s64 + 12376;
	// stw r11,12376(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12376, ctx.r11.u32);
	// rlwinm r28,r5,27,31,31
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// bl 0x880f52c8
	ctx.lr = 0x8810CC58;
	sub_880F52C8(ctx, base);
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// srawi r11,r4,1
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r4.s32 >> 1;
	// addze r4,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r4.s64 = temp.s64;
	// bl 0x880f5570
	ctx.lr = 0x8810CC78;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8810cc8c
	if (ctx.cr6.eq) goto loc_8810CC8C;
	// stw r28,148(r30)
	PPC_STORE_U32(ctx.r30.u32 + 148, ctx.r28.u32);
	// stw r27,140(r30)
	PPC_STORE_U32(ctx.r30.u32 + 140, ctx.r27.u32);
	// stw r15,100(r30)
	PPC_STORE_U32(ctx.r30.u32 + 100, ctx.r15.u32);
loc_8810CC8C:
	// lwz r11,152(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 152);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8810ce10
	if (!ctx.cr6.eq) goto loc_8810CE10;
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lis r5,96
	ctx.r5.s64 = 6291456;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// bl 0x88094c70
	ctx.lr = 0x8810CCAC;
	sub_88094C70(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8810ce10
	if (ctx.cr6.eq) goto loc_8810CE10;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// bl 0x88095590
	ctx.lr = 0x8810CCC4;
	sub_88095590(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x881534c8
	ctx.lr = 0x8810CCD0;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// addi r11,r11,-8
	ctx.r11.s64 = ctx.r11.s64 + -8;
	// li r16,16
	ctx.r16.s64 = 16;
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// li r23,1
	ctx.r23.s64 = 1;
	// addi r28,r11,-256
	ctx.r28.s64 = ctx.r11.s64 + -256;
	// lwz r27,26276(r10)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26276);
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// li r17,48
	ctx.r17.s64 = 48;
	// li r25,3
	ctx.r25.s64 = 3;
	// li r24,-1
	ctx.r24.s64 = -1;
	// li r18,64
	ctx.r18.s64 = 64;
	// addi r26,r11,9552
	ctx.r26.s64 = ctx.r11.s64 + 9552;
loc_8810CD08:
	// addi r11,r28,-256
	ctx.r11.s64 = ctx.r28.s64 + -256;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// addi r10,r11,128
	ctx.r10.s64 = ctx.r11.s64 + 128;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r6,r10,2,21,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0x7FC;
	// lwzx r11,r7,r26
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r26.u32);
	// lwzx r10,r6,r26
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r26.u32);
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r11,r7
	ctx.r5.u64 = ctx.r11.u64 + ctx.r7.u64;
	// add r4,r10,r6
	ctx.r4.u64 = ctx.r10.u64 + ctx.r6.u64;
	// rlwinm r29,r5,6,0,25
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 6) & 0xFFFFFFC0;
	// rlwinm r30,r4,6,0,25
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 6) & 0xFFFFFFC0;
	// add r4,r9,r29
	ctx.r4.u64 = ctx.r9.u64 + ctx.r29.u64;
	// add r5,r8,r30
	ctx.r5.u64 = ctx.r8.u64 + ctx.r30.u64;
	// bne cr6,0x8810cd88
	if (!ctx.cr6.eq) goto loc_8810CD88;
	// lwz r11,116(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// clrlwi r7,r28,23
	ctx.r7.u64 = ctx.r28.u32 & 0x1FF;
	// li r6,-45
	ctx.r6.s64 = -45;
	// sth r23,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r23.u16);
	// li r3,26
	ctx.r3.s64 = 26;
	// stw r15,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r15.u32);
	// stw r17,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r17.u32);
	// stw r25,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r25.u32);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r24,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r24.u32);
	// bl 0x8815c948
	ctx.lr = 0x8810CD80;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x8810CD88;
	sub_8815C860(ctx, base);
loc_8810CD88:
	// rlwinm r8,r29,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r11,r30,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// add r8,r29,r8
	ctx.r8.u64 = ctx.r29.u64 + ctx.r8.u64;
	// add r7,r30,r11
	ctx.r7.u64 = ctx.r30.u64 + ctx.r11.u64;
	// srawi r6,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 1;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// addze r11,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r11.s64 = temp.s64;
	// srawi r5,r7,1
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r5.s64 = ctx.r7.s32 >> 1;
	// add r4,r11,r9
	ctx.r4.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addze r11,r5
	temp.s64 = ctx.r5.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r11.s64 = temp.s64;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bne cr6,0x8810ce04
	if (!ctx.cr6.eq) goto loc_8810CE04;
	// lwz r11,116(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// clrlwi r7,r28,23
	ctx.r7.u64 = ctx.r28.u32 & 0x1FF;
	// li r6,-45
	ctx.r6.s64 = -45;
	// sth r23,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r23.u16);
	// li r3,59
	ctx.r3.s64 = 59;
	// stw r25,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r25.u32);
	// stw r18,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r18.u32);
	// stw r25,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r25.u32);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r24,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r24.u32);
	// bl 0x8815c948
	ctx.lr = 0x8810CDEC;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x8815c860
	ctx.lr = 0x8810CDF8;
	sub_8815C860(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8810ce04
	if (ctx.cr6.eq) goto loc_8810CE04;
	// sth r24,16(r30)
	PPC_STORE_U16(ctx.r30.u32 + 16, ctx.r24.u16);
loc_8810CE04:
	// addic. r16,r16,-1
	ctx.xer.ca = ctx.r16.u32 > 0;
	ctx.r16.s64 = ctx.r16.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r16.s32, 0, ctx.xer);
	// addi r28,r28,32
	ctx.r28.s64 = ctx.r28.s64 + 32;
	// bne 0x8810cd08
	if (!ctx.cr0.eq) goto loc_8810CD08;
loc_8810CE10:
	// lwz r11,144(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8810ce4c
	if (!ctx.cr6.eq) goto loc_8810CE4C;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r8,140
	ctx.r8.s64 = 140;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r9,0(r20)
	PPC_STORE_U32(ctx.r20.u32 + 0, ctx.r9.u32);
	// li r4,140
	ctx.r4.s64 = 140;
	// stw r8,0(r19)
	PPC_STORE_U32(ctx.r19.u32 + 0, ctx.r8.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,0(r22)
	PPC_STORE_U32(ctx.r22.u32 + 0, ctx.r11.u32);
	// stw r10,0(r21)
	PPC_STORE_U32(ctx.r21.u32 + 0, ctx.r10.u32);
	// bl 0x881607f8
	ctx.lr = 0x8810CE4C;
	sub_881607F8(ctx, base);
loc_8810CE4C:
	// lwz r11,172(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 172);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,40
	ctx.r5.s64 = 40;
	// li r4,93
	ctx.r4.s64 = 93;
	// li r3,5
	ctx.r3.s64 = 5;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x880e32d0
	ctx.lr = 0x8810CE6C;
	sub_880E32D0(ctx, base);
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// bl 0x88094220
	ctx.lr = 0x8810CE74;
	sub_88094220(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x88071174
	__restgprlr_15(ctx, base);
	return;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x88071174
	__restgprlr_15(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810CE8C"))) PPC_WEAK_FUNC(sub_8810CE8C);
PPC_FUNC_IMPL(__imp__sub_8810CE8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810CE90"))) PPC_WEAK_FUNC(sub_8810CE90);
PPC_FUNC_IMPL(__imp__sub_8810CE90) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r9,-11984(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11984);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// lwz r9,180(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 180);
	// bgt cr6,0x8810cee8
	if (ctx.cr6.gt) goto loc_8810CEE8;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x8810cfcc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8810CFCC;
	// bdzf 4*cr6+eq,0x8810cfe0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8810CFE0;
	// bne cr6,0x8810cff4
	if (!ctx.cr6.eq) goto loc_8810CFF4;
	// cmpwi cr6,r9,272
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 272, ctx.xer);
	// blt cr6,0x8810cee8
	if (ctx.cr6.lt) goto loc_8810CEE8;
	// li r10,3
	ctx.r10.s64 = 3;
	// li r9,1
	ctx.r9.s64 = 1;
loc_8810CEE0:
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
loc_8810CEE8:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// bge 0x8810cfb8
	if (!ctx.cr0.lt) goto loc_8810CFB8;
	// lis r9,-30671
	ctx.r9.s64 = -2010054656;
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lis r7,16838
	ctx.r7.s64 = 1103495168;
	// lis r6,9362
	ctx.r6.s64 = 613548032;
	// ori r5,r7,20077
	ctx.r5.u64 = ctx.r7.u64 | 20077;
	// lis r4,-30633
	ctx.r4.s64 = -2007564288;
	// lwz r10,4200(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4200);
	// ori r3,r6,18725
	ctx.r3.u64 = ctx.r6.u64 | 18725;
	// stw r8,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r8.u32);
	// mullw r11,r10,r5
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r5.s32);
	// lwz r10,-29780(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + -29780);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,4200(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4200, ctx.r11.u32);
	// lhz r9,4200(r9)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4200);
	// mulhwu r11,r9,r3
	ctx.r11.u64 = (uint64_t(ctx.r9.u32) * uint64_t(ctx.r3.u32)) >> 32;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r11.s64;
	// rlwinm r10,r8,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r6,r7,30,2,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwinm r5,r6,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r4,r6,r5
	ctx.r4.s64 = ctx.r5.s64 - ctx.r6.s64;
	// subf r3,r4,r9
	ctx.r3.s64 = ctx.r9.s64 - ctx.r4.s64;
	// clrlwi r31,r3,16
	ctx.r31.u64 = ctx.r3.u32 & 0xFFFF;
	// bne cr6,0x8810cfb8
	if (!ctx.cr6.eq) goto loc_8810CFB8;
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x881534c8
	ctx.lr = 0x8810CF64;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,16
	ctx.r3.s64 = 16;
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// bl 0x881534c8
	ctx.lr = 0x8810CF78;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r10,138
	ctx.r10.s64 = 138;
	// addi r9,r11,56
	ctx.r9.s64 = ctx.r11.s64 + 56;
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// extsh r8,r31
	ctx.r8.s64 = ctx.r31.s16;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r6,-30680
	ctx.r6.s64 = -2010644480;
	// stw r7,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// rlwinm r4,r8,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r6,16744
	ctx.r11.s64 = ctx.r6.s64 + 16744;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lis r5,320
	ctx.r5.s64 = 20971520;
	// li r3,51
	ctx.r3.s64 = 51;
	// lwzx r10,r4,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r11.u32);
	// rlwinm r4,r10,19,0,12
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 19) & 0xFFF80000;
	// bl 0x880958a0
	ctx.lr = 0x8810CFB8;
	sub_880958A0(ctx, base);
loc_8810CFB8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8810CFCC:
	// cmpwi cr6,r9,280
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 280, ctx.xer);
	// blt cr6,0x8810cee8
	if (ctx.cr6.lt) goto loc_8810CEE8;
	// li r10,3
	ctx.r10.s64 = 3;
	// li r9,2
	ctx.r9.s64 = 2;
	// b 0x8810cee0
	goto loc_8810CEE0;
loc_8810CFE0:
	// cmpwi cr6,r9,336
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 336, ctx.xer);
	// blt cr6,0x8810cee8
	if (ctx.cr6.lt) goto loc_8810CEE8;
	// li r10,6
	ctx.r10.s64 = 6;
	// li r9,3
	ctx.r9.s64 = 3;
	// b 0x8810cee0
	goto loc_8810CEE0;
loc_8810CFF4:
	// cmpwi cr6,r9,392
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 392, ctx.xer);
	// blt cr6,0x8810cee8
	if (ctx.cr6.lt) goto loc_8810CEE8;
	// bl 0x88094220
	ctx.lr = 0x8810D000;
	sub_88094220(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8810D014"))) PPC_WEAK_FUNC(sub_8810D014);
PPC_FUNC_IMPL(__imp__sub_8810D014) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810D018"))) PPC_WEAK_FUNC(sub_8810D018);
PPC_FUNC_IMPL(__imp__sub_8810D018) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x8810D020;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30703
	ctx.r11.s64 = -2012151808;
	// li r4,172
	ctx.r4.s64 = 172;
	// addi r5,r11,-12264
	ctx.r5.s64 = ctx.r11.s64 + -12264;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x8810D038;
	sub_88094290(ctx, base);
	// li r5,172
	ctx.r5.s64 = 172;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,2304(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2304);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x8810D04C;
	sub_88073BD0(ctx, base);
	// li r10,138
	ctx.r10.s64 = 138;
	// stw r30,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r30.u32);
	// lis r9,-30703
	ctx.r9.s64 = -2012151808;
	// lwz r7,32(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// li r26,1
	ctx.r26.s64 = 1;
	// stw r10,168(r30)
	PPC_STORE_U32(ctx.r30.u32 + 168, ctx.r10.u32);
	// addi r8,r9,-17448
	ctx.r8.s64 = ctx.r9.s64 + -17448;
	// stw r7,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
	// li r27,0
	ctx.r27.s64 = 0;
	// lwz r6,36(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r6,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r6.u32);
	// stw r27,80(r30)
	PPC_STORE_U32(ctx.r30.u32 + 80, ctx.r27.u32);
	// stw r8,76(r30)
	PPC_STORE_U32(ctx.r30.u32 + 76, ctx.r8.u32);
	// stw r26,96(r30)
	PPC_STORE_U32(ctx.r30.u32 + 96, ctx.r26.u32);
	// bl 0x88169750
	ctx.lr = 0x8810D08C;
	sub_88169750(ctx, base);
	// lis r29,-30671
	ctx.r29.s64 = -2010054656;
	// lis r5,16838
	ctx.r5.s64 = 1103495168;
	// lwz r8,76(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// lis r4,-3856
	ctx.r4.s64 = -252706816;
	// ori r28,r5,20077
	ctx.r28.u64 = ctx.r5.u64 | 20077;
	// ori r7,r4,61681
	ctx.r7.u64 = ctx.r4.u64 | 61681;
	// lwz r11,4200(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4200);
	// li r24,3
	ctx.r24.s64 = 3;
	// li r4,21
	ctx.r4.s64 = 21;
	// mullw r11,r11,r28
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// stw r24,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r24.u32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// li r3,1
	ctx.r3.s64 = 1;
	// mullw r9,r11,r28
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// stw r11,4200(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4200, ctx.r11.u32);
	// lhz r10,4200(r29)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r29.u32 + 4200);
	// addi r11,r9,12345
	ctx.r11.s64 = ctx.r9.s64 + 12345;
	// clrlwi r6,r10,30
	ctx.r6.u64 = ctx.r10.u32 & 0x3;
	// mullw r9,r11,r28
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// stw r11,4200(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4200, ctx.r11.u32);
	// lhz r10,4200(r29)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r29.u32 + 4200);
	// stw r6,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r6.u32);
	// addi r11,r9,12345
	ctx.r11.s64 = ctx.r9.s64 + 12345;
	// clrlwi r10,r10,30
	ctx.r10.u64 = ctx.r10.u32 & 0x3;
	// mullw r9,r11,r28
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// stw r11,4200(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4200, ctx.r11.u32);
	// lhz r11,4200(r29)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r29.u32 + 4200);
	// addi r25,r9,12345
	ctx.r25.s64 = ctx.r9.s64 + 12345;
	// clrlwi r9,r11,31
	ctx.r9.u64 = ctx.r11.u32 & 0x1;
	// stw r25,4200(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4200, ctx.r25.u32);
	// addi r5,r10,3
	ctx.r5.s64 = ctx.r10.s64 + 3;
	// lhz r6,4200(r29)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r29.u32 + 4200);
	// mulhwu r11,r6,r7
	ctx.r11.u64 = (uint64_t(ctx.r6.u32) * uint64_t(ctx.r7.u32)) >> 32;
	// rlwinm r11,r11,28,4,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0xFFFFFFF;
	// stw r5,152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 152, ctx.r5.u32);
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r9,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r9.u32);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r6,r7,r6
	ctx.r6.s64 = ctx.r6.s64 - ctx.r7.s64;
	// extsh r11,r6
	ctx.r11.s64 = ctx.r6.s16;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// addi r11,r11,-8
	ctx.r11.s64 = ctx.r11.s64 + -8;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// bl 0x881556a0
	ctx.lr = 0x8810D140;
	sub_881556A0(ctx, base);
	// lis r10,-30703
	ctx.r10.s64 = -2012151808;
	// stw r3,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r3.u32);
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// addi r8,r10,-15792
	ctx.r8.s64 = ctx.r10.s64 + -15792;
	// stw r30,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r30.u32);
	// stw r8,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r8.u32);
	// lwz r7,168(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 168);
	// stw r26,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r26.u32);
	// stw r27,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r27.u32);
	// lwz r10,168(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 168);
	// lwz r11,28(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8810d18c
	if (ctx.cr6.eq) goto loc_8810D18C;
loc_8810D174:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8810d244
	if (ctx.cr6.eq) goto loc_8810D244;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8810d174
	if (!ctx.cr6.eq) goto loc_8810D174;
loc_8810D18C:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_8810D190:
	// li r9,32
	ctx.r9.s64 = 32;
	// stw r31,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r31.u32);
	// li r8,64
	ctx.r8.s64 = 64;
	// stw r27,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r27.u32);
	// li r7,53
	ctx.r7.s64 = 53;
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// li r6,20
	ctx.r6.s64 = 20;
	// stw r9,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r9.u32);
	// li r10,8
	ctx.r10.s64 = 8;
	// stw r8,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r8.u32);
	// li r5,4096
	ctx.r5.s64 = 4096;
	// stw r7,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// li r4,384
	ctx.r4.s64 = 384;
	// stw r6,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r6.u32);
	// stw r26,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r26.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmpwi cr6,r3,46
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 46, ctx.xer);
	// stw r5,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r5.u32);
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// stw r4,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r4.u32);
	// stw r26,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r26.u32);
	// stw r26,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r26.u32);
	// bne cr6,0x8810d1f4
	if (!ctx.cr6.eq) goto loc_8810D1F4;
	// stw r26,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r26.u32);
loc_8810D1F4:
	// mullw r11,r25,r28
	ctx.r11.s64 = int64_t(ctx.r25.s32) * int64_t(ctx.r28.s32);
	// lis r10,15887
	ctx.r10.s64 = 1041170432;
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// ori r8,r10,33761
	ctx.r8.u64 = ctx.r10.u64 | 33761;
	// stw r11,4200(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4200, ctx.r11.u32);
	// lhz r9,4200(r29)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r29.u32 + 4200);
	// mulhwu r7,r9,r8
	ctx.r7.u64 = (uint64_t(ctx.r9.u32) * uint64_t(ctx.r8.u32)) >> 32;
	// rlwinm r11,r7,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 29) & 0x1FFFFFFF;
	// rlwinm r10,r11,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r5,r6,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r6.s64;
	// extsh r11,r5
	ctx.r11.s64 = ctx.r5.s16;
	// addi r3,r11,112
	ctx.r3.s64 = ctx.r11.s64 + 112;
	// stw r3,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r3.u32);
	// lwz r11,136(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 136);
	// stw r27,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r27.u32);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8810d25c
	if (!ctx.cr6.eq) goto loc_8810D25C;
	// stw r26,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r26.u32);
	// b 0x8810d278
	goto loc_8810D278;
loc_8810D244:
	// lwz r10,24(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8810d254
	if (ctx.cr6.eq) goto loc_8810D254;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_8810D254:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x8810d190
	goto loc_8810D190;
loc_8810D25C:
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8810d26c
	if (!ctx.cr6.eq) goto loc_8810D26C;
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// b 0x8810d278
	goto loc_8810D278;
loc_8810D26C:
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x8810d278
	if (!ctx.cr6.eq) goto loc_8810D278;
	// stw r24,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r24.u32);
loc_8810D278:
	// lis r11,-30703
	ctx.r11.s64 = -2012151808;
	// lis r10,-30703
	ctx.r10.s64 = -2012151808;
	// lis r9,-30703
	ctx.r9.s64 = -2012151808;
	// addi r8,r11,-16360
	ctx.r8.s64 = ctx.r11.s64 + -16360;
	// addi r7,r10,-17400
	ctx.r7.s64 = ctx.r10.s64 + -17400;
	// addi r6,r9,-16920
	ctx.r6.s64 = ctx.r9.s64 + -16920;
	// stw r8,68(r30)
	PPC_STORE_U32(ctx.r30.u32 + 68, ctx.r8.u32);
	// stw r7,64(r30)
	PPC_STORE_U32(ctx.r30.u32 + 64, ctx.r7.u32);
	// stw r6,84(r30)
	PPC_STORE_U32(ctx.r30.u32 + 84, ctx.r6.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810D2A4"))) PPC_WEAK_FUNC(sub_8810D2A4);
PPC_FUNC_IMPL(__imp__sub_8810D2A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810D2A8"))) PPC_WEAK_FUNC(sub_8810D2A8);
PPC_FUNC_IMPL(__imp__sub_8810D2A8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x8810D2B0;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30703
	ctx.r11.s64 = -2012151808;
	// li r4,176
	ctx.r4.s64 = 176;
	// addi r5,r11,-11608
	ctx.r5.s64 = ctx.r11.s64 + -11608;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x8810D2C8;
	sub_88094290(ctx, base);
	// li r5,176
	ctx.r5.s64 = 176;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,2304(r29)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r29.u32 + 2304);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x8810D2DC;
	sub_88073BD0(ctx, base);
	// stw r29,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r29.u32);
	// lwz r7,32(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 32);
	// lis r30,-30671
	ctx.r30.s64 = -2010054656;
	// stw r7,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
	// lis r10,16838
	ctx.r10.s64 = 1103495168;
	// ori r28,r10,20077
	ctx.r28.u64 = ctx.r10.u64 | 20077;
	// lwz r11,4200(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4200);
	// lwz r6,36(r29)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + 36);
	// li r25,3
	ctx.r25.s64 = 3;
	// mullw r11,r11,r28
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// stw r6,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r6.u32);
	// stw r25,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r25.u32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// stw r11,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r11.u32);
	// lis r9,-3856
	ctx.r9.s64 = -252706816;
	// mullw r10,r11,r28
	ctx.r10.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// addi r11,r10,12345
	ctx.r11.s64 = ctx.r10.s64 + 12345;
	// ori r8,r9,61681
	ctx.r8.u64 = ctx.r9.u64 | 61681;
	// mullw r9,r11,r28
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// lwz r5,132(r29)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r29.u32 + 132);
	// stw r5,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r5.u32);
	// lhz r10,4200(r30)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4200);
	// addi r26,r9,12345
	ctx.r26.s64 = ctx.r9.s64 + 12345;
	// stw r11,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r11.u32);
	// li r27,0
	ctx.r27.s64 = 0;
	// lwz r7,136(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 136);
	// clrlwi r10,r10,30
	ctx.r10.u64 = ctx.r10.u32 & 0x3;
	// stw r7,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r7.u32);
	// li r4,21
	ctx.r4.s64 = 21;
	// lhz r11,4200(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4200);
	// addi r6,r10,3
	ctx.r6.s64 = ctx.r10.s64 + 3;
	// stw r26,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r26.u32);
	// li r3,2
	ctx.r3.s64 = 2;
	// lwz r10,140(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 140);
	// clrlwi r9,r11,31
	ctx.r9.u64 = ctx.r11.u32 & 0x1;
	// stw r10,168(r29)
	PPC_STORE_U32(ctx.r29.u32 + 168, ctx.r10.u32);
	// lhz r11,4200(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4200);
	// addi r5,r9,2
	ctx.r5.s64 = ctx.r9.s64 + 2;
	// stw r6,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r6.u32);
	// mulhwu r7,r11,r8
	ctx.r7.u64 = (uint64_t(ctx.r11.u32) * uint64_t(ctx.r8.u32)) >> 32;
	// stw r5,160(r31)
	PPC_STORE_U32(ctx.r31.u32 + 160, ctx.r5.u32);
	// lwz r8,76(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// rlwinm r11,r7,28,4,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 28) & 0xFFFFFFF;
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r5,r6,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r6.s64;
	// extsh r11,r5
	ctx.r11.s64 = ctx.r5.s16;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// addi r10,r11,-8
	ctx.r10.s64 = ctx.r11.s64 + -8;
	// stw r10,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// stw r27,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r27.u32);
	// bl 0x881556a0
	ctx.lr = 0x8810D3B0;
	sub_881556A0(ctx, base);
	// lis r9,-30703
	ctx.r9.s64 = -2012151808;
	// stw r3,172(r31)
	PPC_STORE_U32(ctx.r31.u32 + 172, ctx.r3.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r8,r9,-14128
	ctx.r8.s64 = ctx.r9.s64 + -14128;
	// stw r29,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r29.u32);
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// stw r8,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r8.u32);
	// lwz r7,172(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 172);
	// stw r6,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r6.u32);
	// lwz r10,172(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 172);
	// lwz r11,28(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8810d3fc
	if (ctx.cr6.eq) goto loc_8810D3FC;
loc_8810D3E4:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8810d51c
	if (ctx.cr6.eq) goto loc_8810D51C;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8810d3e4
	if (!ctx.cr6.eq) goto loc_8810D3E4;
loc_8810D3FC:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_8810D400:
	// li r10,8
	ctx.r10.s64 = 8;
	// stw r31,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r31.u32);
	// li r8,53
	ctx.r8.s64 = 53;
	// stw r6,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r6.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// mr r9,r6
	ctx.r9.u64 = ctx.r6.u64;
	// stw r8,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r10,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// stw r27,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r27.u32);
	// lwz r8,172(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 172);
	// lwz r11,28(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8810d454
	if (ctx.cr6.eq) goto loc_8810D454;
loc_8810D43C:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8810d534
	if (ctx.cr6.eq) goto loc_8810D534;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8810d43c
	if (!ctx.cr6.eq) goto loc_8810D43C;
loc_8810D454:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_8810D458:
	// li r9,24
	ctx.r9.s64 = 24;
	// stw r31,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r31.u32);
	// li r8,28
	ctx.r8.s64 = 28;
	// stw r27,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r27.u32);
	// li r7,52
	ctx.r7.s64 = 52;
	// stw r9,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r9.u32);
	// li r5,4
	ctx.r5.s64 = 4;
	// stw r8,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r8.u32);
	// li r4,384
	ctx.r4.s64 = 384;
	// stw r7,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// stw r8,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
	// stw r9,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r9.u32);
	// stw r6,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r6.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmpwi cr6,r3,46
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 46, ctx.xer);
	// stw r5,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r5.u32);
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// stw r4,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r4.u32);
	// bne cr6,0x8810d4ac
	if (!ctx.cr6.eq) goto loc_8810D4AC;
	// stw r6,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r6.u32);
loc_8810D4AC:
	// mullw r11,r26,r28
	ctx.r11.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r28.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// lis r9,15887
	ctx.r9.s64 = 1041170432;
	// stw r11,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r11.u32);
	// mullw r11,r11,r28
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// lhz r5,4200(r30)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4200);
	// addi r10,r11,12345
	ctx.r10.s64 = ctx.r11.s64 + 12345;
	// ori r4,r9,33761
	ctx.r4.u64 = ctx.r9.u64 | 33761;
	// stw r10,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r10.u32);
	// lis r3,-30597
	ctx.r3.s64 = -2005204992;
	// mulhwu r11,r5,r4
	ctx.r11.u64 = (uint64_t(ctx.r5.u32) * uint64_t(ctx.r4.u32)) >> 32;
	// rlwinm r11,r11,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// lhz r9,4200(r30)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4200);
	// lwz r8,-11984(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + -11984);
	// rlwinm r7,r11,5,0,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r7,r7,r11
	ctx.r7.u64 = ctx.r7.u64 + ctx.r11.u64;
	// clrlwi r11,r9,30
	ctx.r11.u64 = ctx.r9.u32 & 0x3;
	// subf r5,r7,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r7.s64;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// extsh r9,r5
	ctx.r9.s64 = ctx.r5.s16;
	// addi r3,r9,112
	ctx.r3.s64 = ctx.r9.s64 + 112;
	// stw r3,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r3.u32);
	// lwz r9,84(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 84);
	// stw r27,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r27.u32);
	// stw r9,152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 152, ctx.r9.u32);
	// bne cr6,0x8810d54c
	if (!ctx.cr6.eq) goto loc_8810D54C;
	// stw r6,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r6.u32);
	// b 0x8810d568
	goto loc_8810D568;
loc_8810D51C:
	// lwz r10,24(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8810d52c
	if (ctx.cr6.eq) goto loc_8810D52C;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_8810D52C:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x8810d400
	goto loc_8810D400;
loc_8810D534:
	// lwz r9,24(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8810d544
	if (ctx.cr6.eq) goto loc_8810D544;
	// stw r9,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r9.u32);
loc_8810D544:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x8810d458
	goto loc_8810D458;
loc_8810D54C:
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8810d55c
	if (!ctx.cr6.eq) goto loc_8810D55C;
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// b 0x8810d568
	goto loc_8810D568;
loc_8810D55C:
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x8810d568
	if (!ctx.cr6.eq) goto loc_8810D568;
	// stw r25,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r25.u32);
loc_8810D568:
	// mullw r11,r10,r28
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r28.s32);
	// lis r9,-21846
	ctx.r9.s64 = -1431699456;
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// ori r7,r9,43691
	ctx.r7.u64 = ctx.r9.u64 | 43691;
	// stw r11,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r11.u32);
	// lhz r8,4200(r30)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4200);
	// mulhwu r5,r8,r7
	ctx.r5.u64 = (uint64_t(ctx.r8.u32) * uint64_t(ctx.r7.u32)) >> 32;
	// rlwinm r10,r5,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r4,r10,r9
	ctx.r4.u64 = ctx.r10.u64 + ctx.r9.u64;
	// subf r3,r4,r8
	ctx.r3.s64 = ctx.r8.s64 - ctx.r4.s64;
	// extsh r9,r3
	ctx.r9.s64 = ctx.r3.s16;
	// stw r9,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r9.u32);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x8810d5c0
	if (!ctx.cr6.eq) goto loc_8810D5C0;
	// mullw r11,r11,r28
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// stw r11,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r11.u32);
	// lhz r10,4200(r30)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4200);
	// clrlwi r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	// stw r10,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r10.u32);
	// stw r10,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r10.u32);
loc_8810D5C0:
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x8810d5e8
	if (!ctx.cr6.eq) goto loc_8810D5E8;
	// mullw r11,r11,r28
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// stw r11,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r11.u32);
	// lhz r10,4200(r30)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4200);
	// clrlwi r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	// stw r10,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r10.u32);
	// stw r10,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r10.u32);
loc_8810D5E8:
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// bne cr6,0x8810d610
	if (!ctx.cr6.eq) goto loc_8810D610;
	// mullw r11,r11,r28
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// stw r11,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r11.u32);
	// lhz r11,4200(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4200);
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// stw r11,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// stw r11,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
loc_8810D610:
	// lis r11,-30703
	ctx.r11.s64 = -2012151808;
	// stw r6,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r6.u32);
	// lis r10,-30703
	ctx.r10.s64 = -2012151808;
	// stw r6,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r6.u32);
	// lis r9,-30703
	ctx.r9.s64 = -2012151808;
	// addi r8,r11,-14864
	ctx.r8.s64 = ctx.r11.s64 + -14864;
	// addi r7,r10,-16856
	ctx.r7.s64 = ctx.r10.s64 + -16856;
	// addi r6,r9,-16424
	ctx.r6.s64 = ctx.r9.s64 + -16424;
	// stw r8,68(r29)
	PPC_STORE_U32(ctx.r29.u32 + 68, ctx.r8.u32);
	// stw r7,64(r29)
	PPC_STORE_U32(ctx.r29.u32 + 64, ctx.r7.u32);
	// stw r6,84(r29)
	PPC_STORE_U32(ctx.r29.u32 + 84, ctx.r6.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810D644"))) PPC_WEAK_FUNC(sub_8810D644);
PPC_FUNC_IMPL(__imp__sub_8810D644) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810D648"))) PPC_WEAK_FUNC(sub_8810D648);
PPC_FUNC_IMPL(__imp__sub_8810D648) {
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
	// lis r11,-30703
	ctx.r11.s64 = -2012151808;
	// li r4,12
	ctx.r4.s64 = 12;
	// addi r5,r11,-10680
	ctx.r5.s64 = ctx.r11.s64 + -10680;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x8810D670;
	sub_88094290(ctx, base);
	// li r5,12
	ctx.r5.s64 = 12;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r30,2304(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2304);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88073bd0
	ctx.lr = 0x8810D684;
	sub_88073BD0(ctx, base);
	// lis r10,-30703
	ctx.r10.s64 = -2012151808;
	// lis r9,-30703
	ctx.r9.s64 = -2012151808;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r10,-12656
	ctx.r6.s64 = ctx.r10.s64 + -12656;
	// stw r8,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r8.u32);
	// addi r5,r9,-17456
	ctx.r5.s64 = ctx.r9.s64 + -17456;
	// stw r7,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r7.u32);
	// stw r6,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r6.u32);
	// stw r5,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r5.u32);
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

__attribute__((alias("__imp__sub_8810D6C4"))) PPC_WEAK_FUNC(sub_8810D6C4);
PPC_FUNC_IMPL(__imp__sub_8810D6C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810D6C8"))) PPC_WEAK_FUNC(sub_8810D6C8);
PPC_FUNC_IMPL(__imp__sub_8810D6C8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8810D6CC"))) PPC_WEAK_FUNC(sub_8810D6CC);
PPC_FUNC_IMPL(__imp__sub_8810D6CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810D6D0"))) PPC_WEAK_FUNC(sub_8810D6D0);
PPC_FUNC_IMPL(__imp__sub_8810D6D0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8810D6D4"))) PPC_WEAK_FUNC(sub_8810D6D4);
PPC_FUNC_IMPL(__imp__sub_8810D6D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810D6D8"))) PPC_WEAK_FUNC(sub_8810D6D8);
PPC_FUNC_IMPL(__imp__sub_8810D6D8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8810D6DC"))) PPC_WEAK_FUNC(sub_8810D6DC);
PPC_FUNC_IMPL(__imp__sub_8810D6DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810D6E0"))) PPC_WEAK_FUNC(sub_8810D6E0);
PPC_FUNC_IMPL(__imp__sub_8810D6E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// li r11,512
	ctx.r11.s64 = 512;
	// lwz r10,2304(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2304);
	// rlwinm r9,r5,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0x1;
	// subfc r8,r11,r5
	ctx.xer.ca = ctx.r5.u32 >= ctx.r11.u32;
	ctx.r8.s64 = ctx.r5.s64 - ctx.r11.s64;
	// rlwinm r7,r11,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// li r3,1
	ctx.r3.s64 = 1;
	// subfe r6,r9,r7
	temp.u8 = (~ctx.r9.u32 + ctx.r7.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r7.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ~ctx.r9.u64 + ctx.r7.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r5,28(r10)
	PPC_STORE_U32(ctx.r10.u32 + 28, ctx.r5.u32);
	// and r5,r6,r4
	ctx.r5.u64 = ctx.r6.u64 & ctx.r4.u64;
	// stw r5,32(r10)
	PPC_STORE_U32(ctx.r10.u32 + 32, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8810D70C"))) PPC_WEAK_FUNC(sub_8810D70C);
PPC_FUNC_IMPL(__imp__sub_8810D70C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810D710"))) PPC_WEAK_FUNC(sub_8810D710);
PPC_FUNC_IMPL(__imp__sub_8810D710) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// li r11,512
	ctx.r11.s64 = 512;
	// lwz r10,2304(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2304);
	// rlwinm r9,r5,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0x1;
	// subfc r8,r11,r5
	ctx.xer.ca = ctx.r5.u32 >= ctx.r11.u32;
	ctx.r8.s64 = ctx.r5.s64 - ctx.r11.s64;
	// rlwinm r7,r11,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// li r3,1
	ctx.r3.s64 = 1;
	// subfe r6,r9,r7
	temp.u8 = (~ctx.r9.u32 + ctx.r7.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r7.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ~ctx.r9.u64 + ctx.r7.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r5,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r5.u32);
	// and r5,r6,r4
	ctx.r5.u64 = ctx.r6.u64 & ctx.r4.u64;
	// stw r5,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8810D73C"))) PPC_WEAK_FUNC(sub_8810D73C);
PPC_FUNC_IMPL(__imp__sub_8810D73C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810D740"))) PPC_WEAK_FUNC(sub_8810D740);
PPC_FUNC_IMPL(__imp__sub_8810D740) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8810D744"))) PPC_WEAK_FUNC(sub_8810D744);
PPC_FUNC_IMPL(__imp__sub_8810D744) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810D748"))) PPC_WEAK_FUNC(sub_8810D748);
PPC_FUNC_IMPL(__imp__sub_8810D748) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r10,26272(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26272);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8810d764
	if (ctx.cr6.eq) goto loc_8810D764;
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x8810d77c
	goto loc_8810D77C;
loc_8810D764:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// addi r8,r10,51
	ctx.r8.s64 = ctx.r10.s64 + 51;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,-11984(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -11984);
	// lwzx r8,r7,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
loc_8810D77C:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lis r7,-64
	ctx.r7.s64 = -4194304;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// rlwinm r8,r9,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// addi r5,r9,34
	ctx.r5.s64 = ctx.r9.s64 + 34;
	// lwz r9,2300(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2300);
	// add r4,r8,r9
	ctx.r4.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lwz r9,268(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 268);
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// stw r8,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// rlwinm r5,r5,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r4,2300(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2300);
	// lwzx r10,r5,r4
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r4.u32);
	// subf r9,r10,r6
	ctx.r9.s64 = ctx.r6.s64 - ctx.r10.s64;
	// stw r9,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// cmpw cr6,r9,r7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, ctx.xer);
	// bgtlr cr6
	if (ctx.cr6.gt) return;
	// b 0x88094220
	sub_88094220(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810D7D0"))) PPC_WEAK_FUNC(sub_8810D7D0);
PPC_FUNC_IMPL(__imp__sub_8810D7D0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8810D7D4"))) PPC_WEAK_FUNC(sub_8810D7D4);
PPC_FUNC_IMPL(__imp__sub_8810D7D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810D7D8"))) PPC_WEAK_FUNC(sub_8810D7D8);
PPC_FUNC_IMPL(__imp__sub_8810D7D8) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r10,26272(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26272);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8810d7f4
	if (ctx.cr6.eq) goto loc_8810D7F4;
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x8810d80c
	goto loc_8810D80C;
loc_8810D7F4:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// addi r8,r10,51
	ctx.r8.s64 = ctx.r10.s64 + 51;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,-11984(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -11984);
	// lwzx r8,r7,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
loc_8810D80C:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lis r7,-200
	ctx.r7.s64 = -13107200;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// rlwinm r8,r9,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// addi r5,r9,34
	ctx.r5.s64 = ctx.r9.s64 + 34;
	// lwz r9,2300(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2300);
	// add r4,r8,r9
	ctx.r4.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lwz r9,268(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 268);
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// stw r8,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// rlwinm r5,r5,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r4,2300(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2300);
	// lwzx r10,r5,r4
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r4.u32);
	// subf r9,r10,r6
	ctx.r9.s64 = ctx.r6.s64 - ctx.r10.s64;
	// stw r9,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// cmpw cr6,r9,r7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, ctx.xer);
	// bgtlr cr6
	if (ctx.cr6.gt) return;
	// b 0x88094220
	sub_88094220(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810D860"))) PPC_WEAK_FUNC(sub_8810D860);
PPC_FUNC_IMPL(__imp__sub_8810D860) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8810D864"))) PPC_WEAK_FUNC(sub_8810D864);
PPC_FUNC_IMPL(__imp__sub_8810D864) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810D868"))) PPC_WEAK_FUNC(sub_8810D868);
PPC_FUNC_IMPL(__imp__sub_8810D868) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r10,26272(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26272);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8810d884
	if (ctx.cr6.eq) goto loc_8810D884;
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x8810d89c
	goto loc_8810D89C;
loc_8810D884:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// addi r8,r10,51
	ctx.r8.s64 = ctx.r10.s64 + 51;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,-11984(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -11984);
	// lwzx r8,r7,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
loc_8810D89C:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lis r7,-280
	ctx.r7.s64 = -18350080;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// rlwinm r8,r9,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// addi r5,r9,34
	ctx.r5.s64 = ctx.r9.s64 + 34;
	// lwz r9,2300(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2300);
	// add r4,r8,r9
	ctx.r4.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lwz r9,268(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 268);
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// stw r8,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// rlwinm r5,r5,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r4,2300(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2300);
	// lwzx r10,r5,r4
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r4.u32);
	// subf r9,r10,r6
	ctx.r9.s64 = ctx.r6.s64 - ctx.r10.s64;
	// stw r9,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// cmpw cr6,r9,r7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, ctx.xer);
	// bgtlr cr6
	if (ctx.cr6.gt) return;
	// b 0x88094220
	sub_88094220(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810D8F0"))) PPC_WEAK_FUNC(sub_8810D8F0);
PPC_FUNC_IMPL(__imp__sub_8810D8F0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8810D8F4"))) PPC_WEAK_FUNC(sub_8810D8F4);
PPC_FUNC_IMPL(__imp__sub_8810D8F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810D8F8"))) PPC_WEAK_FUNC(sub_8810D8F8);
PPC_FUNC_IMPL(__imp__sub_8810D8F8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r9,80(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
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

__attribute__((alias("__imp__sub_8810D938"))) PPC_WEAK_FUNC(sub_8810D938);
PPC_FUNC_IMPL(__imp__sub_8810D938) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r9,52(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 52);
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

__attribute__((alias("__imp__sub_8810D978"))) PPC_WEAK_FUNC(sub_8810D978);
PPC_FUNC_IMPL(__imp__sub_8810D978) {
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
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// lis r6,-30643
	ctx.r6.s64 = -2008219648;
	// addi r5,r10,9552
	ctx.r5.s64 = ctx.r10.s64 + 9552;
	// lwz r4,16(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// clrlwi r10,r4,23
	ctx.r10.u64 = ctx.r4.u32 & 0x1FF;
	// lwz r4,20(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// addi r9,r9,34
	ctx.r9.s64 = ctx.r9.s64 + 34;
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// addi r31,r10,128
	ctx.r31.s64 = ctx.r10.s64 + 128;
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm r30,r10,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,26272(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 26272);
	// rlwinm r6,r31,2,21,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0x7FC;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// rlwinm r31,r9,3,0,28
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r10,r30,r5
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r5.u32);
	// lwzx r6,r6,r5
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r5.u32);
	// mullw r9,r10,r4
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r4.s32);
	// mullw r10,r6,r4
	ctx.r10.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r4.s32);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r5,r9,r7
	ctx.r5.u64 = ctx.r9.u64 + ctx.r7.u64;
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// stw r5,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r5.u32);
	// lwz r4,2300(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2300);
	// lwzx r9,r31,r4
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r4.u32);
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// stw r8,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r8.u32);
	// beq cr6,0x8810da0c
	if (ctx.cr6.eq) goto loc_8810DA0C;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x8810da18
	goto loc_8810DA18;
loc_8810DA0C:
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r10,-11984(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11984);
	// lwz r10,212(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 212);
loc_8810DA18:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lis r8,-80
	ctx.r8.s64 = -5242880;
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmpw cr6,r7,r8
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, ctx.xer);
	// stw r6,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r6.u32);
	// bgt cr6,0x8810da38
	if (ctx.cr6.gt) goto loc_8810DA38;
	// bl 0x88094220
	ctx.lr = 0x8810DA38;
	sub_88094220(ctx, base);
loc_8810DA38:
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

__attribute__((alias("__imp__sub_8810DA50"))) PPC_WEAK_FUNC(sub_8810DA50);
PPC_FUNC_IMPL(__imp__sub_8810DA50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x8810DA58;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r9,2300(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2300);
	// lwz r10,184(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// lwz r11,168(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// lwz r8,2304(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// add r31,r10,r11
	ctx.r31.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r7,156(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 156);
	// lwz r6,160(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
	// srawi r5,r7,16
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFFFF) != 0);
	ctx.r5.s64 = ctx.r7.s32 >> 16;
	// lwz r4,0(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// addze r11,r5
	temp.s64 = ctx.r5.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r11.s64 = temp.s64;
	// lwz r3,4(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// srawi r9,r6,16
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xFFFF) != 0);
	ctx.r9.s64 = ctx.r6.s32 >> 16;
	// lwz r10,16(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// rlwinm r8,r11,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// addze r7,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r7.s64 = temp.s64;
	// subf r30,r8,r4
	ctx.r30.s64 = ctx.r4.s64 - ctx.r8.s64;
	// rlwinm r6,r7,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// cmpwi cr6,r10,227
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 227, ctx.xer);
	// subf r29,r6,r3
	ctx.r29.s64 = ctx.r3.s64 - ctx.r6.s64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bne cr6,0x8810db38
	if (!ctx.cr6.eq) goto loc_8810DB38;
	// li r3,983
	ctx.r3.s64 = 983;
	// bl 0x881538c0
	ctx.lr = 0x8810DAC0;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810dad8
	if (ctx.cr6.eq) goto loc_8810DAD8;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
loc_8810DAD8:
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addis r4,r30,32
	ctx.r4.s64 = ctx.r30.s64 + 2097152;
	// li r3,984
	ctx.r3.s64 = 984;
	// bl 0x881538c0
	ctx.lr = 0x8810DAEC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810db04
	if (ctx.cr6.eq) goto loc_8810DB04;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
loc_8810DB04:
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addis r4,r30,72
	ctx.r4.s64 = ctx.r30.s64 + 4718592;
	// li r3,985
	ctx.r3.s64 = 985;
	// bl 0x881538c0
	ctx.lr = 0x8810DB18;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810db30
	if (ctx.cr6.eq) goto loc_8810DB30;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
loc_8810DB30:
	// li r3,986
	ctx.r3.s64 = 986;
	// b 0x8810dbb4
	goto loc_8810DBB4;
loc_8810DB38:
	// li r3,987
	ctx.r3.s64 = 987;
	// bl 0x881538c0
	ctx.lr = 0x8810DB40;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810db58
	if (ctx.cr6.eq) goto loc_8810DB58;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
loc_8810DB58:
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addis r4,r30,32
	ctx.r4.s64 = ctx.r30.s64 + 2097152;
	// li r3,988
	ctx.r3.s64 = 988;
	// bl 0x881538c0
	ctx.lr = 0x8810DB6C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810db84
	if (ctx.cr6.eq) goto loc_8810DB84;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
loc_8810DB84:
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addis r4,r30,56
	ctx.r4.s64 = ctx.r30.s64 + 3670016;
	// li r3,989
	ctx.r3.s64 = 989;
	// bl 0x881538c0
	ctx.lr = 0x8810DB98;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810dbb0
	if (ctx.cr6.eq) goto loc_8810DBB0;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
loc_8810DBB0:
	// li r3,990
	ctx.r3.s64 = 990;
loc_8810DBB4:
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addis r4,r30,96
	ctx.r4.s64 = ctx.r30.s64 + 6291456;
	// bl 0x881538c0
	ctx.lr = 0x8810DBC4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810dbdc
	if (ctx.cr6.eq) goto loc_8810DBDC;
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
loc_8810DBDC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810DBC0"))) PPC_WEAK_FUNC(sub_8810DBC0);
PPC_FUNC_IMPL(__imp__sub_8810DBC0) {
	PPC_FUNC_PROLOGUE();
	// bl 0x881538c0
	ctx.lr = 0x8810DBC4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810dbdc
	if (ctx.cr6.eq) goto loc_8810DBDC;
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
loc_8810DBDC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810DBE4"))) PPC_WEAK_FUNC(sub_8810DBE4);
PPC_FUNC_IMPL(__imp__sub_8810DBE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810DBE8"))) PPC_WEAK_FUNC(sub_8810DBE8);
PPC_FUNC_IMPL(__imp__sub_8810DBE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x8810DBF0;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-30667
	ctx.r9.s64 = -2009792512;
	// lwz r10,184(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// lwz r11,168(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r9,r9,5816
	ctx.r9.s64 = ctx.r9.s64 + 5816;
	// lwz r30,2304(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// li r28,0
	ctx.r28.s64 = 0;
	// add r27,r10,r11
	ctx.r27.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r31,r9,2
	ctx.r31.s64 = ctx.r9.s64 + 2;
loc_8810DC18:
	// lwz r9,2300(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 2300);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// lhz r8,-2(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + -2);
	// addi r3,r28,943
	ctx.r3.s64 = ctx.r28.s64 + 943;
	// lhz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r31.u32 + 0);
	// extsh r5,r8
	ctx.r5.s64 = ctx.r8.s16;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// extsh r4,r7
	ctx.r4.s64 = ctx.r7.s16;
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r8,156(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 156);
	// lwz r7,160(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
	// srawi r9,r8,16
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFF) != 0);
	ctx.r9.s64 = ctx.r8.s32 >> 16;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// srawi r7,r7,16
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFFFF) != 0);
	ctx.r7.s64 = ctx.r7.s32 >> 16;
	// subf r5,r8,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r8.s64;
	// addze r8,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r8.s64 = temp.s64;
	// rlwinm r9,r5,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// subf r7,r8,r4
	ctx.r7.s64 = ctx.r4.s64 - ctx.r8.s64;
	// add r4,r9,r11
	ctx.r4.u64 = ctx.r9.u64 + ctx.r11.u64;
	// rlwinm r11,r7,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x8810DC70;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810dc88
	if (ctx.cr6.eq) goto loc_8810DC88;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
loc_8810DC88:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// cmplwi cr6,r28,8
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 8, ctx.xer);
	// blt cr6,0x8810dc18
	if (ctx.cr6.lt) goto loc_8810DC18;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810DCA0"))) PPC_WEAK_FUNC(sub_8810DCA0);
PPC_FUNC_IMPL(__imp__sub_8810DCA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x8810DCA8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-30667
	ctx.r9.s64 = -2009792512;
	// lwz r10,184(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// lwz r11,168(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r9,r9,5784
	ctx.r9.s64 = ctx.r9.s64 + 5784;
	// lwz r30,2304(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// li r28,0
	ctx.r28.s64 = 0;
	// add r27,r10,r11
	ctx.r27.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r31,r9,2
	ctx.r31.s64 = ctx.r9.s64 + 2;
loc_8810DCD0:
	// lwz r9,2300(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 2300);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// lhz r8,-2(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + -2);
	// addi r3,r28,935
	ctx.r3.s64 = ctx.r28.s64 + 935;
	// lhz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r31.u32 + 0);
	// extsh r5,r8
	ctx.r5.s64 = ctx.r8.s16;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// extsh r4,r7
	ctx.r4.s64 = ctx.r7.s16;
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r8,156(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 156);
	// lwz r7,160(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
	// srawi r9,r8,16
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFF) != 0);
	ctx.r9.s64 = ctx.r8.s32 >> 16;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// srawi r7,r7,16
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFFFF) != 0);
	ctx.r7.s64 = ctx.r7.s32 >> 16;
	// subf r5,r8,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r8.s64;
	// addze r8,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r8.s64 = temp.s64;
	// rlwinm r9,r5,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// subf r7,r8,r4
	ctx.r7.s64 = ctx.r4.s64 - ctx.r8.s64;
	// add r4,r9,r11
	ctx.r4.u64 = ctx.r9.u64 + ctx.r11.u64;
	// rlwinm r11,r7,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x8810DD28;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810dd40
	if (ctx.cr6.eq) goto loc_8810DD40;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
loc_8810DD40:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// cmplwi cr6,r28,8
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 8, ctx.xer);
	// blt cr6,0x8810dcd0
	if (ctx.cr6.lt) goto loc_8810DCD0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810DD58"))) PPC_WEAK_FUNC(sub_8810DD58);
PPC_FUNC_IMPL(__imp__sub_8810DD58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071138
	ctx.lr = 0x8810DD60;
	__savegprlr_20(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r8,2300(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2300);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r9,64
	ctx.r9.s64 = 4194304;
	// li r3,15803
	ctx.r3.s64 = 15803;
	// lwz r7,156(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 156);
	// lwz r10,184(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 184);
	// lwz r11,168(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 168);
	// srawi r5,r7,16
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFFFF) != 0);
	ctx.r5.s64 = ctx.r7.s32 >> 16;
	// lwz r6,160(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 160);
	// add r25,r10,r11
	ctx.r25.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addze r10,r5
	temp.s64 = ctx.r5.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r10.s64 = temp.s64;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// srawi r8,r6,16
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xFFFF) != 0);
	ctx.r8.s64 = ctx.r6.s32 >> 16;
	// rlwinm r7,r10,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// addze r6,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r6.s64 = temp.s64;
	// subf r30,r7,r4
	ctx.r30.s64 = ctx.r4.s64 - ctx.r7.s64;
	// rlwinm r5,r6,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// addi r21,r25,-1
	ctx.r21.s64 = ctx.r25.s64 + -1;
	// subf r28,r5,r11
	ctx.r28.s64 = ctx.r11.s64 - ctx.r5.s64;
	// mr r6,r21
	ctx.r6.u64 = ctx.r21.u64;
	// add r4,r30,r9
	ctx.r4.u64 = ctx.r30.u64 + ctx.r9.u64;
	// subf r5,r9,r28
	ctx.r5.s64 = ctx.r28.s64 - ctx.r9.s64;
	// bl 0x881538c0
	ctx.lr = 0x8810DDC8;
	sub_881538C0(ctx, base);
	// lis r20,-30597
	ctx.r20.s64 = -2005204992;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810ddf0
	if (ctx.cr6.eq) goto loc_8810DDF0;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-11932(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + -11932);
	// oris r9,r10,518
	ctx.r9.u64 = ctx.r10.u64 | 33947648;
	// addi r22,r11,1
	ctx.r22.s64 = ctx.r11.s64 + 1;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r22,-11932(r20)
	PPC_STORE_U32(ctx.r20.u32 + -11932, ctx.r22.u32);
	// b 0x8810ddf4
	goto loc_8810DDF4;
loc_8810DDF0:
	// lwz r22,-11932(r20)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r20.u32 + -11932);
loc_8810DDF4:
	// lhz r11,26(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 26);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8810de14
	if (ctx.cr6.eq) goto loc_8810DE14;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810de14
	if (ctx.cr6.eq) goto loc_8810DE14;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// oris r10,r11,1024
	ctx.r10.u64 = ctx.r11.u64 | 67108864;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_8810DE14:
	// lhz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 24);
	// lis r10,-30680
	ctx.r10.s64 = -2010644480;
	// li r27,0
	ctx.r27.s64 = 0;
	// rotlwi r9,r11,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// addi r10,r10,17540
	ctx.r10.s64 = ctx.r10.s64 + 17540;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r29,r11,r10
	ctx.r29.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r8,4(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// ble cr6,0x8810df58
	if (!ctx.cr6.gt) goto loc_8810DF58;
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// li r24,0
	ctx.r24.s64 = 0;
	// addi r23,r11,9552
	ctx.r23.s64 = ctx.r11.s64 + 9552;
loc_8810DE4C:
	// lwz r9,2300(r26)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r26.u32 + 2300);
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// add r11,r24,r11
	ctx.r11.u64 = ctx.r24.u64 + ctx.r11.u64;
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r5,r10,128
	ctx.r5.s64 = ctx.r10.s64 + 128;
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r4,156(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 156);
	// lwz r3,160(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
	// rlwinm r10,r5,2,21,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x7FC;
	// srawi r9,r4,16
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0xFFFF) != 0);
	ctx.r9.s64 = ctx.r4.s32 >> 16;
	// lhz r5,26(r31)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r31.u32 + 26);
	// lbz r4,1(r11)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// addze r9,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r9.s64 = temp.s64;
	// srawi r3,r3,16
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFFFF) != 0);
	ctx.r3.s64 = ctx.r3.s32 >> 16;
	// extsb r4,r4
	ctx.r4.s64 = ctx.r4.s8;
	// lwzx r7,r10,r23
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r23.u32);
	// addze r3,r3
	temp.s64 = ctx.r3.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r3.s64 = temp.s64;
	// rlwinm r10,r9,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// subf r9,r3,r4
	ctx.r9.s64 = ctx.r4.s64 - ctx.r3.s64;
	// subf r10,r10,r6
	ctx.r10.s64 = ctx.r6.s64 - ctx.r10.s64;
	// rlwinm r9,r9,9,0,22
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 9) & 0xFFFFFE00;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// add r7,r9,r7
	ctx.r7.u64 = ctx.r9.u64 + ctx.r7.u64;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// rlwinm r9,r7,7,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 7) & 0xFFFFFF80;
	// add r28,r9,r8
	ctx.r28.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// add r3,r11,r27
	ctx.r3.u64 = ctx.r11.u64 + ctx.r27.u64;
	// beq cr6,0x8810df14
	if (ctx.cr6.eq) goto loc_8810DF14;
	// subfic r7,r8,152
	ctx.xer.ca = ctx.r8.u32 <= 152;
	ctx.r7.s64 = 152 - ctx.r8.s64;
	// rlwinm r11,r7,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// add r30,r11,r10
	ctx.r30.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x881538c0
	ctx.lr = 0x8810DEE4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810df44
	if (ctx.cr6.eq) goto loc_8810DF44;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// oris r8,r11,1024
	ctx.r8.u64 = ctx.r11.u64 | 67108864;
	// lwz r7,40(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// subf r6,r7,r9
	ctx.r6.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r6,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r6.u32);
	// b 0x8810df3c
	goto loc_8810DF3C;
loc_8810DF14:
	// rlwinm r11,r8,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// add r30,r11,r10
	ctx.r30.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x881538c0
	ctx.lr = 0x8810DF24;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810df44
	if (ctx.cr6.eq) goto loc_8810DF44;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
loc_8810DF3C:
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_8810DF44:
	// lwz r11,4(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// addi r24,r24,2
	ctx.r24.s64 = ctx.r24.s64 + 2;
	// cmpw cr6,r27,r11
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8810de4c
	if (ctx.cr6.lt) goto loc_8810DE4C;
loc_8810DF58:
	// mr r6,r21
	ctx.r6.u64 = ctx.r21.u64;
	// addis r5,r28,20
	ctx.r5.s64 = ctx.r28.s64 + 1310720;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,419
	ctx.r3.s64 = 419;
	// bl 0x881538c0
	ctx.lr = 0x8810DF6C;
	sub_881538C0(ctx, base);
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lis r10,48
	ctx.r10.s64 = 3145728;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// ori r29,r10,32880
	ctx.r29.u64 = ctx.r10.u64 | 32880;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x8810dfa4
	if (ctx.cr6.eq) goto loc_8810DFA4;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r22,r22,1
	ctx.r22.s64 = ctx.r22.s64 + 1;
	// stw r29,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r29.u32);
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r22,-11932(r20)
	PPC_STORE_U32(ctx.r20.u32 + -11932, ctx.r22.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_8810DFA4:
	// lis r27,36
	ctx.r27.s64 = 2359296;
	// mr r6,r21
	ctx.r6.u64 = ctx.r21.u64;
	// addis r5,r28,35
	ctx.r5.s64 = ctx.r28.s64 + 2293760;
	// add r4,r30,r27
	ctx.r4.u64 = ctx.r30.u64 + ctx.r27.u64;
	// li r3,419
	ctx.r3.s64 = 419;
	// bl 0x881538c0
	ctx.lr = 0x8810DFBC;
	sub_881538C0(ctx, base);
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x8810dfec
	if (ctx.cr6.eq) goto loc_8810DFEC;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r22,r22,1
	ctx.r22.s64 = ctx.r22.s64 + 1;
	// stw r29,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r29.u32);
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r22,-11932(r20)
	PPC_STORE_U32(ctx.r20.u32 + -11932, ctx.r22.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_8810DFEC:
	// mr r6,r21
	ctx.r6.u64 = ctx.r21.u64;
	// addis r5,r28,48
	ctx.r5.s64 = ctx.r28.s64 + 3145728;
	// subf r4,r27,r30
	ctx.r4.s64 = ctx.r30.s64 - ctx.r27.s64;
	// li r3,419
	ctx.r3.s64 = 419;
	// bl 0x881538c0
	ctx.lr = 0x8810E000;
	sub_881538C0(ctx, base);
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x8810e030
	if (ctx.cr6.eq) goto loc_8810E030;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r29,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r29.u32);
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// addi r11,r22,1
	ctx.r11.s64 = ctx.r22.s64 + 1;
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r11,-11932(r20)
	PPC_STORE_U32(ctx.r20.u32 + -11932, ctx.r11.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_8810E030:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x88071188
	__restgprlr_20(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810E038"))) PPC_WEAK_FUNC(sub_8810E038);
PPC_FUNC_IMPL(__imp__sub_8810E038) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071134
	ctx.lr = 0x8810E040;
	__savegprlr_19(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// li r19,0
	ctx.r19.s64 = 0;
	// mr r20,r3
	ctx.r20.u64 = ctx.r3.u64;
	// mr r10,r19
	ctx.r10.u64 = ctx.r19.u64;
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8810e07c
	if (ctx.cr6.eq) goto loc_8810E07C;
loc_8810E064:
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// stw r19,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r19.u32);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8810e064
	if (!ctx.cr6.eq) goto loc_8810E064;
loc_8810E07C:
	// lis r11,128
	ctx.r11.s64 = 8388608;
	// clrlwi r10,r10,20
	ctx.r10.u64 = ctx.r10.u32 & 0xFFF;
	// ori r9,r11,32896
	ctx.r9.u64 = ctx.r11.u64 | 32896;
	// rlwinm r10,r10,0,26,21
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFC3F;
	// stw r9,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r9.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8810e0bc
	if (ctx.cr6.eq) goto loc_8810E0BC;
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// stw r11,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r11.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8810e0bc
	if (ctx.cr6.eq) goto loc_8810E0BC;
	// lis r11,192
	ctx.r11.s64 = 12582912;
	// ori r10,r11,49152
	ctx.r10.u64 = ctx.r11.u64 | 49152;
	// stw r10,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r10.u32);
loc_8810E0BC:
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// lwz r8,32(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r22,r31,4
	ctx.r22.s64 = ctx.r31.s64 + 4;
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r29,r10,9552
	ctx.r29.s64 = ctx.r10.s64 + 9552;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addi r7,r11,128
	ctx.r7.s64 = ctx.r11.s64 + 128;
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// rlwinm r10,r7,2,21,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x7FC;
	// addi r24,r31,8
	ctx.r24.s64 = ctx.r31.s64 + 8;
	// mr r5,r22
	ctx.r5.u64 = ctx.r22.u64;
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// lwzx r7,r6,r29
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r29.u32);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// lwzx r30,r10,r29
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r29.u32);
	// mullw r10,r7,r8
	ctx.r10.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r8.s32);
	// mullw r8,r30,r8
	ctx.r8.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r8.s32);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// bl 0x880940d8
	ctx.lr = 0x8810E120;
	sub_880940D8(ctx, base);
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r21,1
	ctx.r21.s64 = 1;
	// addi r8,r11,2
	ctx.r8.s64 = ctx.r11.s64 + 2;
	// lwz r5,4(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addis r9,r10,120
	ctx.r9.s64 = ctx.r10.s64 + 7864320;
	// stw r8,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r8.u32);
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// lwz r11,100(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 100);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r8,r11,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r7,r8,-1
	ctx.r7.s64 = ctx.r8.s64 + -1;
	// and r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 & ctx.r11.u64;
	// ble 0x8810e1a0
	if (!ctx.cr0.gt) goto loc_8810E1A0;
	// lis r8,320
	ctx.r8.s64 = 20971520;
	// addis r7,r9,-240
	ctx.r7.s64 = ctx.r9.s64 + -15728640;
	// cmpw cr6,r7,r8
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, ctx.xer);
	// bge cr6,0x8810e1a0
	if (!ctx.cr6.lt) goto loc_8810E1A0;
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// addi r8,r11,55
	ctx.r8.s64 = ctx.r11.s64 + 55;
	// lis r7,-40
	ctx.r7.s64 = -2621440;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-11984(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -11984);
	// lwzx r11,r6,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r11.u32);
	// add r4,r11,r5
	ctx.r4.u64 = ctx.r11.u64 + ctx.r5.u64;
	// addis r11,r4,144
	ctx.r11.s64 = ctx.r4.s64 + 9437184;
	// cmpw cr6,r11,r7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r7.s32, ctx.xer);
	// ble cr6,0x8810e1a0
	if (!ctx.cr6.gt) goto loc_8810E1A0;
	// lis r9,280
	ctx.r9.s64 = 18350080;
	// addis r8,r11,-288
	ctx.r8.s64 = ctx.r11.s64 + -18874368;
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x8810e1c4
	if (ctx.cr6.lt) goto loc_8810E1C4;
loc_8810E1A0:
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8810e1c8
	if (ctx.cr6.eq) goto loc_8810E1C8;
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// stw r19,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r19.u32);
	// bl 0x88094220
	ctx.lr = 0x8810E1BC;
	sub_88094220(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x88071184
	__restgprlr_19(ctx, base);
	return;
loc_8810E1C4:
	// stw r21,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r21.u32);
loc_8810E1C8:
	// lhz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 56);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8810e444
	if (ctx.cr6.eq) goto loc_8810E444;
	// lwz r9,44(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8810e20c
	if (ctx.cr6.eq) goto loc_8810E20C;
	// lhz r8,52(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 52);
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// stw r6,0(r24)
	PPC_STORE_U32(ctx.r24.u32 + 0, ctx.r6.u32);
	// beq cr6,0x8810e204
	if (ctx.cr6.eq) goto loc_8810E204;
	// addi r11,r11,-8
	ctx.r11.s64 = ctx.r11.s64 + -8;
	// stw r11,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
loc_8810E204:
	// addi r11,r9,-1
	ctx.r11.s64 = ctx.r9.s64 + -1;
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
loc_8810E20C:
	// lhz r11,58(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 58);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// sth r9,58(r31)
	PPC_STORE_U16(ctx.r31.u32 + 58, ctx.r9.u16);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge cr6,0x8810e570
	if (!ctx.cr6.lt) goto loc_8810E570;
	// lhz r11,54(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 54);
	// lis r10,-30680
	ctx.r10.s64 = -2010644480;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r3,8
	ctx.r3.s64 = 8;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// lwz r6,12(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r7,r10,17600
	ctx.r7.s64 = ctx.r10.s64 + 17600;
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,0(r24)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r30,r11,r7
	ctx.r30.u64 = ctx.r11.u64 + ctx.r7.u64;
	// lwz r10,24(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// sth r10,58(r31)
	PPC_STORE_U16(ctx.r31.u32 + 58, ctx.r10.u16);
	// lwz r7,8(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 + ctx.r6.u64;
	// lwz r11,184(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 184);
	// lwz r10,168(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 168);
	// add r25,r9,r8
	ctx.r25.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r26,r7,r5
	ctx.r26.u64 = ctx.r7.u64 + ctx.r5.u64;
	// add r29,r11,r10
	ctx.r29.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881534c8
	ctx.lr = 0x8810E288;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lis r27,-30667
	ctx.r27.s64 = -2009792512;
	// addi r6,r11,-4
	ctx.r6.s64 = ctx.r11.s64 + -4;
	// li r3,7
	ctx.r3.s64 = 7;
	// rlwinm r11,r6,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// stw r11,12364(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12364, ctx.r11.u32);
	// bl 0x881534c8
	ctx.lr = 0x8810E2A8;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lis r28,-30667
	ctx.r28.s64 = -2009792512;
	// addi r5,r11,-4
	ctx.r5.s64 = ctx.r11.s64 + -4;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// rlwinm r11,r5,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// add r11,r11,r25
	ctx.r11.u64 = ctx.r11.u64 + ctx.r25.u64;
	// li r3,36
	ctx.r3.s64 = 36;
	// stw r11,12372(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12372, ctx.r11.u32);
	// bl 0x880f34b0
	ctx.lr = 0x8810E2D0;
	sub_880F34B0(ctx, base);
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// li r3,63
	ctx.r3.s64 = 63;
	// bl 0x881534c8
	ctx.lr = 0x8810E2DC;
	sub_881534C8(ctx, base);
	// extsh r4,r3
	ctx.r4.s64 = ctx.r3.s16;
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// rlwinm r11,r4,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// beq cr6,0x8810e2f0
	if (ctx.cr6.eq) goto loc_8810E2F0;
	// sth r11,26(r23)
	PPC_STORE_U16(ctx.r23.u32 + 26, ctx.r11.u16);
loc_8810E2F0:
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x881534c8
	ctx.lr = 0x8810E2F8;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,7
	ctx.r3.s64 = 7;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// stw r11,12364(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12364, ctx.r11.u32);
	// bl 0x881534c8
	ctx.lr = 0x8810E314;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r10,r11,-4
	ctx.r10.s64 = ctx.r11.s64 + -4;
	// li r3,36
	ctx.r3.s64 = 36;
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r25
	ctx.r11.u64 = ctx.r11.u64 + ctx.r25.u64;
	// stw r11,12372(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12372, ctx.r11.u32);
	// bl 0x880f34b0
	ctx.lr = 0x8810E334;
	sub_880F34B0(ctx, base);
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// li r3,63
	ctx.r3.s64 = 63;
	// bl 0x881534c8
	ctx.lr = 0x8810E340;
	sub_881534C8(ctx, base);
	// extsh r9,r3
	ctx.r9.s64 = ctx.r3.s16;
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// rlwinm r11,r9,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// beq cr6,0x8810e354
	if (ctx.cr6.eq) goto loc_8810E354;
	// sth r11,26(r23)
	PPC_STORE_U16(ctx.r23.u32 + 26, ctx.r11.u16);
loc_8810E354:
	// stw r26,12364(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12364, ctx.r26.u32);
	// lis r23,-30667
	ctx.r23.s64 = -2009792512;
	// stw r25,12372(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12372, ctx.r25.u32);
	// lis r26,-30667
	ctx.r26.s64 = -2009792512;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r29,12376(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12376, ctx.r29.u32);
	// stw r3,12380(r23)
	PPC_STORE_U32(ctx.r23.u32 + 12380, ctx.r3.u32);
	// bl 0x880f52c8
	ctx.lr = 0x8810E378;
	sub_880F52C8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810e38c
	if (ctx.cr6.eq) goto loc_8810E38C;
	// li r11,192
	ctx.r11.s64 = 192;
	// stw r11,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r11.u32);
loc_8810E38C:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r5,20(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// lwz r4,16(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// bl 0x880f5570
	ctx.lr = 0x8810E39C;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8810e3c0
	if (ctx.cr6.eq) goto loc_8810E3C0;
	// lwz r11,36(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// stw r11,148(r29)
	PPC_STORE_U32(ctx.r29.u32 + 148, ctx.r11.u32);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// clrlwi r9,r10,16
	ctx.r9.u64 = ctx.r10.u32 & 0xFFFF;
	// stw r9,100(r29)
	PPC_STORE_U32(ctx.r29.u32 + 100, ctx.r9.u32);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// stw r8,144(r29)
	PPC_STORE_U32(ctx.r29.u32 + 144, ctx.r8.u32);
loc_8810E3C0:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r6,100(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r5,96(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// lwz r8,2332(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2332);
	// lwz r7,2328(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2328);
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// bl 0x880f5438
	ctx.lr = 0x8810E3E0;
	sub_880F5438(ctx, base);
	// lhz r11,54(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 54);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// extsh r8,r9
	ctx.r8.s64 = ctx.r9.s16;
	// sth r8,54(r31)
	PPC_STORE_U16(ctx.r31.u32 + 54, ctx.r8.u16);
	// cmpwi cr6,r8,17
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 17, ctx.xer);
	// blt cr6,0x8810e570
	if (ctx.cr6.lt) goto loc_8810E570;
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8810e434
	if (!ctx.cr6.eq) goto loc_8810E434;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// li r8,140
	ctx.r8.s64 = 140;
	// lwz r10,0(r24)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,140
	ctx.r4.s64 = 140;
	// stw r19,12380(r23)
	PPC_STORE_U32(ctx.r23.u32 + 12380, ctx.r19.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r8,12376(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12376, ctx.r8.u32);
	// mr r9,r19
	ctx.r9.u64 = ctx.r19.u64;
	// stw r11,12364(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12372, ctx.r10.u32);
	// bl 0x881607f8
	ctx.lr = 0x8810E434;
	sub_881607F8(ctx, base);
loc_8810E434:
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// bl 0x88094220
	ctx.lr = 0x8810E43C;
	sub_88094220(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x88071184
	__restgprlr_19(ctx, base);
	return;
loc_8810E444:
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8810e570
	if (!ctx.cr6.eq) goto loc_8810E570;
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// bge 0x8810e570
	if (!ctx.cr0.lt) goto loc_8810E570;
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// mr r23,r19
	ctx.r23.u64 = ctx.r19.u64;
	// mr r25,r19
	ctx.r25.u64 = ctx.r19.u64;
	// lis r26,88
	ctx.r26.s64 = 5767168;
	// lis r27,64
	ctx.r27.s64 = 4194304;
	// stw r11,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r28,26276(r11)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
loc_8810E480:
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// clrlwi r10,r23,31
	ctx.r10.u64 = ctx.r23.u32 & 0x1;
	// add r9,r11,r25
	ctx.r9.u64 = ctx.r11.u64 + ctx.r25.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// clrlwi r11,r9,23
	ctx.r11.u64 = ctx.r9.u32 & 0x1FF;
	// rlwinm r8,r9,2,21,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x7FC;
	// addi r7,r11,128
	ctx.r7.s64 = ctx.r11.s64 + 128;
	// rlwinm r6,r7,2,21,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x7FC;
	// lwzx r10,r8,r29
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r29.u32);
	// rlwinm r8,r10,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r11,r6,r29
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r29.u32);
	// add r5,r10,r8
	ctx.r5.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r8,r11,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r10,r5,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 6) & 0xFFFFFFC0;
	// add r4,r11,r8
	ctx.r4.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lwz r8,0(r24)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// rlwinm r11,r4,6,0,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 6) & 0xFFFFFFC0;
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// srawi r6,r7,2
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 2;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addze r11,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r11.s64 = temp.s64;
	// add r4,r5,r26
	ctx.r4.u64 = ctx.r5.u64 + ctx.r26.u64;
	// add r3,r11,r8
	ctx.r3.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r5,r3,r27
	ctx.r5.u64 = ctx.r3.u64 + ctx.r27.u64;
	// beq cr6,0x8810e514
	if (ctx.cr6.eq) goto loc_8810E514;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x8810e54c
	if (!ctx.cr6.eq) goto loc_8810E54C;
	// clrlwi r7,r9,16
	ctx.r7.u64 = ctx.r9.u32 & 0xFFFF;
	// stw r20,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r20.u32);
	// li r6,-8
	ctx.r6.s64 = -8;
	// sth r19,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r19.u16);
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x8815c948
	ctx.lr = 0x8810E508;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x8810E510;
	sub_8815C860(ctx, base);
	// b 0x8810e54c
	goto loc_8810E54C;
loc_8810E514:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x8810e54c
	if (!ctx.cr6.eq) goto loc_8810E54C;
	// clrlwi r7,r9,16
	ctx.r7.u64 = ctx.r9.u32 & 0xFFFF;
	// stw r20,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r20.u32);
	// li r6,-20
	ctx.r6.s64 = -20;
	// sth r19,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r19.u16);
	// li r3,50
	ctx.r3.s64 = 50;
	// bl 0x8815c948
	ctx.lr = 0x8810E534;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x8815c860
	ctx.lr = 0x8810E540;
	sub_8815C860(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8810e54c
	if (ctx.cr6.eq) goto loc_8810E54C;
	// sth r21,16(r30)
	PPC_STORE_U16(ctx.r30.u32 + 16, ctx.r21.u16);
loc_8810E54C:
	// addi r25,r25,8
	ctx.r25.s64 = ctx.r25.s64 + 8;
	// addi r23,r23,1
	ctx.r23.s64 = ctx.r23.s64 + 1;
	// cmpwi cr6,r25,512
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 512, ctx.xer);
	// blt cr6,0x8810e480
	if (ctx.cr6.lt) goto loc_8810E480;
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// clrlwi r10,r11,23
	ctx.r10.u64 = ctx.r11.u32 & 0x1FF;
	// stw r10,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r10.u32);
loc_8810E570:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x88071184
	__restgprlr_19(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810E370"))) PPC_WEAK_FUNC(sub_8810E370);
PPC_FUNC_IMPL(__imp__sub_8810E370) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stw r3,12380(r23)
	PPC_STORE_U32(ctx.r23.u32 + 12380, ctx.r3.u32);
	// bl 0x880f52c8
	ctx.lr = 0x8810E378;
	sub_880F52C8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810e38c
	if (ctx.cr6.eq) goto loc_8810E38C;
	// li r11,192
	ctx.r11.s64 = 192;
	// stw r11,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r11.u32);
loc_8810E38C:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r5,20(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// lwz r4,16(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// bl 0x880f5570
	ctx.lr = 0x8810E39C;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8810e3c0
	if (ctx.cr6.eq) goto loc_8810E3C0;
	// lwz r11,36(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// stw r11,148(r29)
	PPC_STORE_U32(ctx.r29.u32 + 148, ctx.r11.u32);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// clrlwi r9,r10,16
	ctx.r9.u64 = ctx.r10.u32 & 0xFFFF;
	// stw r9,100(r29)
	PPC_STORE_U32(ctx.r29.u32 + 100, ctx.r9.u32);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// stw r8,144(r29)
	PPC_STORE_U32(ctx.r29.u32 + 144, ctx.r8.u32);
loc_8810E3C0:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r6,100(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r5,96(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// lwz r8,2332(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2332);
	// lwz r7,2328(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2328);
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// bl 0x880f5438
	ctx.lr = 0x8810E3E0;
	sub_880F5438(ctx, base);
	// lhz r11,54(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 54);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// extsh r8,r9
	ctx.r8.s64 = ctx.r9.s16;
	// sth r8,54(r31)
	PPC_STORE_U16(ctx.r31.u32 + 54, ctx.r8.u16);
	// cmpwi cr6,r8,17
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 17, ctx.xer);
	// blt cr6,0x8810e570
	if (ctx.cr6.lt) goto loc_8810E570;
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8810e434
	if (!ctx.cr6.eq) goto loc_8810E434;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// li r8,140
	ctx.r8.s64 = 140;
	// lwz r10,0(r24)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,140
	ctx.r4.s64 = 140;
	// stw r19,12380(r23)
	PPC_STORE_U32(ctx.r23.u32 + 12380, ctx.r19.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r8,12376(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12376, ctx.r8.u32);
	// mr r9,r19
	ctx.r9.u64 = ctx.r19.u64;
	// stw r11,12364(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12372, ctx.r10.u32);
	// bl 0x881607f8
	ctx.lr = 0x8810E434;
	sub_881607F8(ctx, base);
loc_8810E434:
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// bl 0x88094220
	ctx.lr = 0x8810E43C;
	sub_88094220(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x88071184
	__restgprlr_19(ctx, base);
	return;
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8810e570
	if (!ctx.cr6.eq) goto loc_8810E570;
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// bge 0x8810e570
	if (!ctx.cr0.lt) goto loc_8810E570;
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// mr r23,r19
	ctx.r23.u64 = ctx.r19.u64;
	// mr r25,r19
	ctx.r25.u64 = ctx.r19.u64;
	// lis r26,88
	ctx.r26.s64 = 5767168;
	// lis r27,64
	ctx.r27.s64 = 4194304;
	// stw r11,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r28,26276(r11)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
loc_8810E480:
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// clrlwi r10,r23,31
	ctx.r10.u64 = ctx.r23.u32 & 0x1;
	// add r9,r11,r25
	ctx.r9.u64 = ctx.r11.u64 + ctx.r25.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// clrlwi r11,r9,23
	ctx.r11.u64 = ctx.r9.u32 & 0x1FF;
	// rlwinm r8,r9,2,21,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x7FC;
	// addi r7,r11,128
	ctx.r7.s64 = ctx.r11.s64 + 128;
	// rlwinm r6,r7,2,21,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x7FC;
	// lwzx r10,r8,r29
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r29.u32);
	// rlwinm r8,r10,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r11,r6,r29
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r29.u32);
	// add r5,r10,r8
	ctx.r5.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r8,r11,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r10,r5,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 6) & 0xFFFFFFC0;
	// add r4,r11,r8
	ctx.r4.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lwz r8,0(r24)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// rlwinm r11,r4,6,0,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 6) & 0xFFFFFFC0;
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// srawi r6,r7,2
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 2;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addze r11,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r11.s64 = temp.s64;
	// add r4,r5,r26
	ctx.r4.u64 = ctx.r5.u64 + ctx.r26.u64;
	// add r3,r11,r8
	ctx.r3.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r5,r3,r27
	ctx.r5.u64 = ctx.r3.u64 + ctx.r27.u64;
	// beq cr6,0x8810e514
	if (ctx.cr6.eq) goto loc_8810E514;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x8810e54c
	if (!ctx.cr6.eq) goto loc_8810E54C;
	// clrlwi r7,r9,16
	ctx.r7.u64 = ctx.r9.u32 & 0xFFFF;
	// stw r20,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r20.u32);
	// li r6,-8
	ctx.r6.s64 = -8;
	// sth r19,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r19.u16);
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x8815c948
	ctx.lr = 0x8810E508;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x8810E510;
	sub_8815C860(ctx, base);
	// b 0x8810e54c
	goto loc_8810E54C;
loc_8810E514:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x8810e54c
	if (!ctx.cr6.eq) goto loc_8810E54C;
	// clrlwi r7,r9,16
	ctx.r7.u64 = ctx.r9.u32 & 0xFFFF;
	// stw r20,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r20.u32);
	// li r6,-20
	ctx.r6.s64 = -20;
	// sth r19,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r19.u16);
	// li r3,50
	ctx.r3.s64 = 50;
	// bl 0x8815c948
	ctx.lr = 0x8810E534;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x8815c860
	ctx.lr = 0x8810E540;
	sub_8815C860(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8810e54c
	if (ctx.cr6.eq) goto loc_8810E54C;
	// sth r21,16(r30)
	PPC_STORE_U16(ctx.r30.u32 + 16, ctx.r21.u16);
loc_8810E54C:
	// addi r25,r25,8
	ctx.r25.s64 = ctx.r25.s64 + 8;
	// addi r23,r23,1
	ctx.r23.s64 = ctx.r23.s64 + 1;
	// cmpwi cr6,r25,512
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 512, ctx.xer);
	// blt cr6,0x8810e480
	if (ctx.cr6.lt) goto loc_8810E480;
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// clrlwi r10,r11,23
	ctx.r10.u64 = ctx.r11.u32 & 0x1FF;
	// stw r10,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r10.u32);
loc_8810E570:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x88071184
	__restgprlr_19(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810E578"))) PPC_WEAK_FUNC(sub_8810E578);
PPC_FUNC_IMPL(__imp__sub_8810E578) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x8810E580;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r10,-30680
	ctx.r10.s64 = -2010644480;
	// lwz r9,184(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r11,168(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// addi r10,r10,17540
	ctx.r10.s64 = ctx.r10.s64 + 17540;
	// li r30,0
	ctx.r30.s64 = 0;
	// add r27,r9,r11
	ctx.r27.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lhz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r29.u32 + 12);
	// rotlwi r9,r11,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r31,r11,r10
	ctx.r31.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// ble cr6,0x8810e6a4
	if (!ctx.cr6.gt) goto loc_8810E6A4;
	// li r26,0
	ctx.r26.s64 = 0;
loc_8810E5C8:
	// lwz r10,2300(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 2300);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lhz r7,14(r29)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r29.u32 + 14);
	// add r11,r26,r11
	ctx.r11.u64 = ctx.r26.u64 + ctx.r11.u64;
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// lwz r8,4(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r6,156(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 156);
	// lwz r5,160(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 160);
	// srawi r4,r6,16
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xFFFF) != 0);
	ctx.r4.s64 = ctx.r6.s32 >> 16;
	// lbz r3,1(r11)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// addze r10,r4
	temp.s64 = ctx.r4.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r10.s64 = temp.s64;
	// srawi r7,r5,16
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xFFFF) != 0);
	ctx.r7.s64 = ctx.r5.s32 >> 16;
	// extsb r6,r3
	ctx.r6.s64 = ctx.r3.s8;
	// addze r5,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r5.s64 = temp.s64;
	// rlwinm r4,r10,16,0,15
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// subf r3,r5,r6
	ctx.r3.s64 = ctx.r6.s64 - ctx.r5.s64;
	// subf r10,r4,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r4.s64;
	// rlwinm r9,r3,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 16) & 0xFFFF0000;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// add r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// add r3,r11,r30
	ctx.r3.u64 = ctx.r11.u64 + ctx.r30.u64;
	// beq cr6,0x8810e66c
	if (ctx.cr6.eq) goto loc_8810E66C;
	// rlwinm r7,r8,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// subf r4,r7,r10
	ctx.r4.s64 = ctx.r10.s64 - ctx.r7.s64;
	// bl 0x881538c0
	ctx.lr = 0x8810E63C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810e690
	if (ctx.cr6.eq) goto loc_8810E690;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// oris r8,r11,1024
	ctx.r8.u64 = ctx.r11.u64 | 67108864;
	// lwz r7,40(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// subf r6,r7,r9
	ctx.r6.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r6,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r6.u32);
	// b 0x8810e690
	goto loc_8810E690;
loc_8810E66C:
	// rlwinm r11,r8,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x8810E678;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810e690
	if (ctx.cr6.eq) goto loc_8810E690;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
loc_8810E690:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r26,r26,2
	ctx.r26.s64 = ctx.r26.s64 + 2;
	// cmpw cr6,r30,r11
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8810e5c8
	if (ctx.cr6.lt) goto loc_8810E5C8;
loc_8810E6A4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810E650"))) PPC_WEAK_FUNC(sub_8810E650);
PPC_FUNC_IMPL(__imp__sub_8810E650) {
	PPC_FUNC_PROLOGUE();
	// oris r8,r11,1024
	ctx.r8.u64 = ctx.r11.u64 | 67108864;
	// lwz r7,40(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// subf r6,r7,r9
	ctx.r6.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r6,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r6.u32);
	// b 0x8810e690
	goto loc_8810E690;
	// rlwinm r11,r8,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x8810E678;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810e690
	if (ctx.cr6.eq) goto loc_8810E690;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
loc_8810E690:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r26,r26,2
	ctx.r26.s64 = ctx.r26.s64 + 2;
	// cmpw cr6,r30,r11
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8810e5c8
	if (ctx.cr6.lt) {
		// ERROR 8810E5C8
		return;
	}
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810E6AC"))) PPC_WEAK_FUNC(sub_8810E6AC);
PPC_FUNC_IMPL(__imp__sub_8810E6AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810E6B0"))) PPC_WEAK_FUNC(sub_8810E6B0);
PPC_FUNC_IMPL(__imp__sub_8810E6B0) {
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
	// lwz r9,2300(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2300);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,915
	ctx.r3.s64 = 915;
	// lwz r8,156(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 156);
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 184);
	// lwz r31,2304(r11)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2304);
	// srawi r5,r8,16
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFF) != 0);
	ctx.r5.s64 = ctx.r8.s32 >> 16;
	// lwz r11,168(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 168);
	// lwz r7,160(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addze r10,r5
	temp.s64 = ctx.r5.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r10.s64 = temp.s64;
	// srawi r9,r7,16
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFFFF) != 0);
	ctx.r9.s64 = ctx.r7.s32 >> 16;
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// rlwinm r8,r10,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// addze r7,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r7.s64 = temp.s64;
	// subf r4,r8,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r8.s64;
	// rlwinm r5,r7,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// subf r5,r5,r11
	ctx.r5.s64 = ctx.r11.s64 - ctx.r5.s64;
	// bl 0x881538c0
	ctx.lr = 0x8810E710;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810e720
	if (ctx.cr6.eq) goto loc_8810E720;
	// lwz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_8810E720:
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

__attribute__((alias("__imp__sub_8810E734"))) PPC_WEAK_FUNC(sub_8810E734);
PPC_FUNC_IMPL(__imp__sub_8810E734) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810E738"))) PPC_WEAK_FUNC(sub_8810E738);
PPC_FUNC_IMPL(__imp__sub_8810E738) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071124
	ctx.lr = 0x8810E740;
	__savegprlr_15(ctx, base);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r17,r3
	ctx.r17.u64 = ctx.r3.u64;
	// li r16,0
	ctx.r16.s64 = 0;
	// lwz r11,26272(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26272);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8810e768
	if (ctx.cr6.eq) goto loc_8810E768;
	// mr r9,r16
	ctx.r9.u64 = ctx.r16.u64;
	// b 0x8810e780
	goto loc_8810E780;
loc_8810E768:
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
	// lwzx r9,r8,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
loc_8810E780:
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lis r8,320
	ctx.r8.s64 = 20971520;
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lwz r7,32(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// rlwinm r9,r10,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// addi r6,r10,34
	ctx.r6.s64 = ctx.r10.s64 + 34;
	// lwz r10,2300(r17)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r17.u32 + 2300);
	// add r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r4,268(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 268);
	// subf r3,r4,r11
	ctx.r3.s64 = ctx.r11.s64 - ctx.r4.s64;
	// stw r3,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r3.u32);
	// rlwinm r11,r6,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,2300(r17)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r17.u32 + 2300);
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// subf r7,r9,r7
	ctx.r7.s64 = ctx.r7.s64 - ctx.r9.s64;
	// stw r7,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r7.u32);
	// cmpw cr6,r7,r8
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, ctx.xer);
	// bgt cr6,0x8810e7e4
	if (ctx.cr6.gt) goto loc_8810E7E4;
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// bgt 0x8810e7e4
	if (ctx.cr0.gt) goto loc_8810E7E4;
	// stw r16,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r16.u32);
loc_8810E7E4:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lis r10,-64
	ctx.r10.s64 = -4194304;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// ble cr6,0x8810eb9c
	if (!ctx.cr6.gt) goto loc_8810EB9C;
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// mr r10,r16
	ctx.r10.u64 = ctx.r16.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8810e820
	if (ctx.cr6.eq) goto loc_8810E820;
loc_8810E808:
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
	// bne cr6,0x8810e808
	if (!ctx.cr6.eq) goto loc_8810E808;
loc_8810E820:
	// lis r11,128
	ctx.r11.s64 = 8388608;
	// clrlwi r10,r10,20
	ctx.r10.u64 = ctx.r10.u32 & 0xFFF;
	// ori r9,r11,32896
	ctx.r9.u64 = ctx.r11.u64 | 32896;
	// rlwinm r10,r10,0,26,21
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFC3F;
	// stw r9,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r9.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8810e860
	if (ctx.cr6.eq) goto loc_8810E860;
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8810e898
	if (ctx.cr6.eq) goto loc_8810E898;
	// lis r11,192
	ctx.r11.s64 = 12582912;
	// ori r10,r11,49152
	ctx.r10.u64 = ctx.r11.u64 | 49152;
	// b 0x8810e894
	goto loc_8810E894;
loc_8810E860:
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// srawi r9,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 2;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// cmpw cr6,r10,r8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, ctx.xer);
	// bge cr6,0x8810e898
	if (!ctx.cr6.lt) goto loc_8810E898;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26428(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26428);
	// rlwinm r10,r11,0,28,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xE;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8810e898
	if (!ctx.cr6.eq) goto loc_8810E898;
	// lis r11,255
	ctx.r11.s64 = 16711680;
	// ori r10,r11,4112
	ctx.r10.u64 = ctx.r11.u64 | 4112;
loc_8810E894:
	// stw r10,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r10.u32);
loc_8810E898:
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8810eba8
	if (!ctx.cr6.eq) goto loc_8810EBA8;
	// lwz r10,184(r17)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r17.u32 + 184);
	// lis r9,-30680
	ctx.r9.s64 = -2010644480;
	// lwz r11,168(r17)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r17.u32 + 168);
	// lwz r7,16(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r8,r9,16800
	ctx.r8.s64 = ctx.r9.s64 + 16800;
	// add r20,r10,r11
	ctx.r20.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addic. r11,r7,-1
	ctx.xer.ca = ctx.r7.u32 > 0;
	ctx.r11.s64 = ctx.r7.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r11,r6,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// add r25,r11,r8
	ctx.r25.u64 = ctx.r11.u64 + ctx.r8.u64;
	// bge 0x8810eba8
	if (!ctx.cr0.lt) goto loc_8810EBA8;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lis r23,-30667
	ctx.r23.s64 = -2009792512;
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lis r24,-30667
	ctx.r24.s64 = -2009792512;
	// lwz r8,32(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r4,r20,1
	ctx.r4.s64 = ctx.r20.s64 + 1;
	// lis r19,-30667
	ctx.r19.s64 = -2009792512;
	// lis r18,-30667
	ctx.r18.s64 = -2009792512;
	// stw r10,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r10.u32);
	// lwz r9,12(r25)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r25.u32 + 12);
	// lwz r3,0(r25)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r10,8(r25)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r25.u32 + 8);
	// add r22,r10,r11
	ctx.r22.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r21,r8,r9
	ctx.r21.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stw r22,12364(r23)
	PPC_STORE_U32(ctx.r23.u32 + 12364, ctx.r22.u32);
	// stw r21,12372(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12372, ctx.r21.u32);
	// bl 0x880f52c8
	ctx.lr = 0x8810E920;
	sub_880F52C8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810e934
	if (ctx.cr6.eq) goto loc_8810E934;
	// li r11,192
	ctx.r11.s64 = 192;
	// stw r11,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r11.u32);
loc_8810E934:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r5,20(r25)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r25.u32 + 20);
	// lwz r4,16(r25)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r25.u32 + 16);
	// bl 0x880f5570
	ctx.lr = 0x8810E944;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8810e968
	if (ctx.cr6.eq) goto loc_8810E968;
	// lwz r11,36(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 36);
	// stw r11,148(r30)
	PPC_STORE_U32(ctx.r30.u32 + 148, ctx.r11.u32);
	// lwz r10,4(r25)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r25.u32 + 4);
	// clrlwi r9,r10,16
	ctx.r9.u64 = ctx.r10.u32 & 0xFFFF;
	// stw r9,100(r30)
	PPC_STORE_U32(ctx.r30.u32 + 100, ctx.r9.u32);
	// lwz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// stw r8,144(r30)
	PPC_STORE_U32(ctx.r30.u32 + 144, ctx.r8.u32);
loc_8810E968:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r6,64(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// lwz r5,60(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// lwz r8,2332(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2332);
	// lwz r7,2328(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2328);
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// bl 0x880f5438
	ctx.lr = 0x8810E988;
	sub_880F5438(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lis r9,-30667
	ctx.r9.s64 = -2009792512;
	// lis r8,-30667
	ctx.r8.s64 = -2009792512;
	// stw r11,12380(r18)
	PPC_STORE_U32(ctx.r18.u32 + 12380, ctx.r11.u32);
	// li r10,256
	ctx.r10.s64 = 256;
	// li r11,64
	ctx.r11.s64 = 64;
	// lis r30,-30671
	ctx.r30.s64 = -2010054656;
	// stw r10,12368(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12368, ctx.r10.u32);
	// addi r4,r20,2
	ctx.r4.s64 = ctx.r20.s64 + 2;
	// stw r11,12384(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12384, ctx.r11.u32);
	// lis r11,16838
	ctx.r11.s64 = 1103495168;
	// lis r10,14563
	ctx.r10.s64 = 954400768;
	// stw r4,12376(r19)
	PPC_STORE_U32(ctx.r19.u32 + 12376, ctx.r4.u32);
	// li r27,5
	ctx.r27.s64 = 5;
	// lwz r26,4200(r30)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4200);
	// ori r28,r11,20077
	ctx.r28.u64 = ctx.r11.u64 | 20077;
	// ori r29,r10,36409
	ctx.r29.u64 = ctx.r10.u64 | 36409;
loc_8810E9CC:
	// mullw r11,r26,r28
	ctx.r11.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r28.s32);
	// lwz r5,12(r25)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r25.u32 + 12);
	// lwz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// li r6,64
	ctx.r6.s64 = 64;
	// mullw r10,r11,r28
	ctx.r10.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
	// stw r11,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r11.u32);
	// lhz r3,4200(r30)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4200);
	// addi r26,r10,12345
	ctx.r26.s64 = ctx.r10.s64 + 12345;
	// mulhwu r10,r3,r29
	ctx.r10.u64 = (uint64_t(ctx.r3.u32) * uint64_t(ctx.r29.u32)) >> 32;
	// stw r26,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r26.u32);
	// rlwinm r10,r10,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// lhz r15,4200(r30)
	ctx.r15.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4200);
	// mulhwu r8,r15,r29
	ctx.r8.u64 = (uint64_t(ctx.r15.u32) * uint64_t(ctx.r29.u32)) >> 32;
	// rlwinm r11,r8,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r7,r10,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r8,r11,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// subf r10,r7,r3
	ctx.r10.s64 = ctx.r3.s64 - ctx.r7.s64;
	// subf r8,r11,r15
	ctx.r8.s64 = ctx.r15.s64 - ctx.r11.s64;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// extsh r11,r8
	ctx.r11.s64 = ctx.r8.s16;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// addi r8,r11,6
	ctx.r8.s64 = ctx.r11.s64 + 6;
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r7,r8,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r22
	ctx.r11.u64 = ctx.r11.u64 + ctx.r22.u64;
	// subf r10,r5,r7
	ctx.r10.s64 = ctx.r7.s64 - ctx.r5.s64;
	// stw r11,12364(r23)
	PPC_STORE_U32(ctx.r23.u32 + 12364, ctx.r11.u32);
	// li r5,256
	ctx.r5.s64 = 256;
	// add r11,r10,r9
	ctx.r11.u64 = ctx.r10.u64 + ctx.r9.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,12372(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12372, ctx.r11.u32);
	// bl 0x880f83f8
	ctx.lr = 0x8810EA58;
	sub_880F83F8(ctx, base);
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// bne 0x8810e9cc
	if (!ctx.cr0.eq) goto loc_8810E9CC;
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8810eaf0
	if (!ctx.cr6.eq) goto loc_8810EAF0;
	// lis r5,32
	ctx.r5.s64 = 2097152;
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x88094c70
	ctx.lr = 0x8810EA7C;
	sub_88094C70(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8810eaf0
	if (ctx.cr6.eq) goto loc_8810EAF0;
	// mr r5,r21
	ctx.r5.u64 = ctx.r21.u64;
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// bl 0x88095590
	ctx.lr = 0x8810EA94;
	sub_88095590(ctx, base);
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26276(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8810eaf0
	if (!ctx.cr6.eq) goto loc_8810EAF0;
	// addi r11,r3,32
	ctx.r11.s64 = ctx.r3.s64 + 32;
	// stw r17,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r17.u32);
	// li r6,-20
	ctx.r6.s64 = -20;
	// sth r16,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r16.u16);
	// clrlwi r7,r11,16
	ctx.r7.u64 = ctx.r11.u32 & 0xFFFF;
	// mr r5,r21
	ctx.r5.u64 = ctx.r21.u64;
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// li r3,45
	ctx.r3.s64 = 45;
	// bl 0x8815c948
	ctx.lr = 0x8810EAC8;
	sub_8815C948(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810eae8
	if (ctx.cr6.eq) goto loc_8810EAE8;
	// li r11,8
	ctx.r11.s64 = 8;
	// li r10,2
	ctx.r10.s64 = 2;
	// li r9,64
	ctx.r9.s64 = 64;
	// sth r11,18(r3)
	PPC_STORE_U16(ctx.r3.u32 + 18, ctx.r11.u16);
	// stb r10,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r10.u8);
	// sth r9,20(r3)
	PPC_STORE_U16(ctx.r3.u32 + 20, ctx.r9.u16);
loc_8810EAE8:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x8810EAF0;
	sub_8815C860(ctx, base);
loc_8810EAF0:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// cmpwi cr6,r11,18
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 18, ctx.xer);
	// blt cr6,0x8810eba8
	if (ctx.cr6.lt) goto loc_8810EBA8;
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8810eb1c
	if (!ctx.cr6.eq) goto loc_8810EB1C;
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8810eb98
	if (!ctx.cr6.eq) goto loc_8810EB98;
loc_8810EB1C:
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lis r29,3
	ctx.r29.s64 = 196608;
	// addis r10,r21,35
	ctx.r10.s64 = ctx.r21.s64 + 2293760;
	// subf r11,r29,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r29.s64;
	// stw r10,12372(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12372, ctx.r10.u32);
	// addi r30,r20,-1
	ctx.r30.s64 = ctx.r20.s64 + -1;
	// stw r11,12364(r23)
	PPC_STORE_U32(ctx.r23.u32 + 12364, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x881607f8
	ctx.lr = 0x8810EB48;
	sub_881607F8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810eb58
	if (ctx.cr6.eq) goto loc_8810EB58;
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
loc_8810EB58:
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// addis r10,r21,43
	ctx.r10.s64 = ctx.r21.s64 + 2818048;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r30,12376(r19)
	PPC_STORE_U32(ctx.r19.u32 + 12376, ctx.r30.u32);
	// subf r11,r29,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r29.s64;
	// stw r10,12372(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12372, ctx.r10.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r11,12364(r23)
	PPC_STORE_U32(ctx.r23.u32 + 12364, ctx.r11.u32);
	// li r11,2
	ctx.r11.s64 = 2;
	// li r3,2
	ctx.r3.s64 = 2;
	// stw r11,12380(r18)
	PPC_STORE_U32(ctx.r18.u32 + 12380, ctx.r11.u32);
	// bl 0x881607f8
	ctx.lr = 0x8810EB88;
	sub_881607F8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8810eb98
	if (ctx.cr6.eq) goto loc_8810EB98;
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
loc_8810EB98:
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
loc_8810EB9C:
	// stw r16,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r16.u32);
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// bl 0x88094220
	ctx.lr = 0x8810EBA8;
	sub_88094220(ctx, base);
loc_8810EBA8:
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x88071174
	__restgprlr_15(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810EBB0"))) PPC_WEAK_FUNC(sub_8810EBB0);
PPC_FUNC_IMPL(__imp__sub_8810EBB0) {
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
	// lwz r11,4(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8810ec7c
	if (!ctx.cr6.gt) goto loc_8810EC7C;
	// lwz r10,48(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 48);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8810ebec
	if (!ctx.cr6.eq) goto loc_8810EBEC;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// stw r9,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r9.u32);
loc_8810EBEC:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt cr6,0x8810ec7c
	if (ctx.cr6.gt) goto loc_8810EC7C;
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8810ec08
	if (ctx.cr6.eq) goto loc_8810EC08;
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
loc_8810EC08:
	// stw r11,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8810ec28
	if (ctx.cr6.eq) goto loc_8810EC28;
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
loc_8810EC28:
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8810ec38
	if (ctx.cr6.eq) goto loc_8810EC38;
	// lwz r11,164(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_8810EC38:
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r5,680
	ctx.r5.s64 = 680;
	// stw r10,2332(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2332, ctx.r10.u32);
	// stw r11,2328(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2328, ctx.r11.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x88095178
	ctx.lr = 0x8810EC50;
	sub_88095178(ctx, base);
	// lwz r7,52(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r8,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r8.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r6,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r6.u32);
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
loc_8810EC7C:
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

__attribute__((alias("__imp__sub_8810EC94"))) PPC_WEAK_FUNC(sub_8810EC94);
PPC_FUNC_IMPL(__imp__sub_8810EC94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810EC98"))) PPC_WEAK_FUNC(sub_8810EC98);
PPC_FUNC_IMPL(__imp__sub_8810EC98) {
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
	// lis r5,-292
	ctx.r5.s64 = -19136512;
	// li r4,20
	ctx.r4.s64 = 20;
	// ori r5,r5,47768
	ctx.r5.u64 = ctx.r5.u64 | 47768;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x8810ECC0;
	sub_88094290(ctx, base);
	// li r5,20
	ctx.r5.s64 = 20;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r30,2304(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2304);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88073bd0
	ctx.lr = 0x8810ECD4;
	sub_88073BD0(ctx, base);
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,81
	ctx.r11.s64 = 81;
	// lis r10,-30703
	ctx.r10.s64 = -2012151808;
	// stw r11,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r11.u32);
	// lis r9,-30703
	ctx.r9.s64 = -2012151808;
	// addi r7,r10,-10424
	ctx.r7.s64 = ctx.r10.s64 + -10424;
	// stw r4,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r4.u32);
	// lis r8,-30703
	ctx.r8.s64 = -2012151808;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r6,r9,-9648
	ctx.r6.s64 = ctx.r9.s64 + -9648;
	// stw r3,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r3.u32);
	// addi r5,r8,-10552
	ctx.r5.s64 = ctx.r8.s64 + -10552;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r11.u32);
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// and r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 & ctx.r11.u64;
	// stw r9,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r9.u32);
	// stw r7,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r7.u32);
	// stw r6,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r6.u32);
	// stw r5,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r5.u32);
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

__attribute__((alias("__imp__sub_8810ED48"))) PPC_WEAK_FUNC(sub_8810ED48);
PPC_FUNC_IMPL(__imp__sub_8810ED48) {
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
	// lis r5,-292
	ctx.r5.s64 = -19136512;
	// li r4,16
	ctx.r4.s64 = 16;
	// ori r5,r5,47768
	ctx.r5.u64 = ctx.r5.u64 | 47768;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x8810ED70;
	sub_88094290(ctx, base);
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r30,2304(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2304);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88073bd0
	ctx.lr = 0x8810ED84;
	sub_88073BD0(ctx, base);
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,114
	ctx.r11.s64 = 114;
	// lis r10,-30703
	ctx.r10.s64 = -2012151808;
	// stw r11,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r11.u32);
	// lis r9,-30703
	ctx.r9.s64 = -2012151808;
	// addi r7,r10,-10280
	ctx.r7.s64 = ctx.r10.s64 + -10280;
	// stw r4,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r4.u32);
	// lis r8,-30703
	ctx.r8.s64 = -2012151808;
	// rotlwi r3,r4,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r4.u32, 0);
	// addi r6,r9,-9240
	ctx.r6.s64 = ctx.r9.s64 + -9240;
	// addi r5,r8,-10544
	ctx.r5.s64 = ctx.r8.s64 + -10544;
	// addis r9,r3,-82
	ctx.r9.s64 = ctx.r3.s64 + -5373952;
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// addis r8,r10,128
	ctx.r8.s64 = ctx.r10.s64 + 8388608;
	// stw r11,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// stw r9,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r9.u32);
	// stw r8,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r8.u32);
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r4,r10,-1
	ctx.r4.s64 = ctx.r10.s64 + -1;
	// and r3,r4,r11
	ctx.r3.u64 = ctx.r4.u64 & ctx.r11.u64;
	// stw r3,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r3.u32);
	// stw r7,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r7.u32);
	// stw r6,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r6.u32);
	// stw r5,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r5.u32);
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

__attribute__((alias("__imp__sub_8810EE08"))) PPC_WEAK_FUNC(sub_8810EE08);
PPC_FUNC_IMPL(__imp__sub_8810EE08) {
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
	// lis r5,-292
	ctx.r5.s64 = -19136512;
	// li r4,16
	ctx.r4.s64 = 16;
	// ori r5,r5,47768
	ctx.r5.u64 = ctx.r5.u64 | 47768;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x8810EE30;
	sub_88094290(ctx, base);
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r30,2304(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2304);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88073bd0
	ctx.lr = 0x8810EE44;
	sub_88073BD0(ctx, base);
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,124
	ctx.r11.s64 = 124;
	// lis r10,-30703
	ctx.r10.s64 = -2012151808;
	// stw r11,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r11.u32);
	// lis r9,-30703
	ctx.r9.s64 = -2012151808;
	// addi r7,r10,-10136
	ctx.r7.s64 = ctx.r10.s64 + -10136;
	// stw r4,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r4.u32);
	// lis r8,-30703
	ctx.r8.s64 = -2012151808;
	// rotlwi r3,r4,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r4.u32, 0);
	// addi r6,r9,-9056
	ctx.r6.s64 = ctx.r9.s64 + -9056;
	// addi r5,r8,-10536
	ctx.r5.s64 = ctx.r8.s64 + -10536;
	// addis r9,r3,-100
	ctx.r9.s64 = ctx.r3.s64 + -6553600;
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// addis r8,r10,-99
	ctx.r8.s64 = ctx.r10.s64 + -6488064;
	// stw r11,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// stw r9,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r9.u32);
	// stw r8,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r8.u32);
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r4,r10,-1
	ctx.r4.s64 = ctx.r10.s64 + -1;
	// and r3,r4,r11
	ctx.r3.u64 = ctx.r4.u64 & ctx.r11.u64;
	// stw r3,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r3.u32);
	// stw r7,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r7.u32);
	// stw r6,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r6.u32);
	// stw r5,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r5.u32);
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

__attribute__((alias("__imp__sub_8810EEC8"))) PPC_WEAK_FUNC(sub_8810EEC8);
PPC_FUNC_IMPL(__imp__sub_8810EEC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071138
	ctx.lr = 0x8810EED0;
	__savegprlr_20(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,40(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 40);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8810f114
	if (!ctx.cr6.gt) goto loc_8810F114;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// subf. r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r9,40(r5)
	PPC_STORE_U32(ctx.r5.u32 + 40, ctx.r9.u32);
	// bgt 0x8810f114
	if (ctx.cr0.gt) goto loc_8810F114;
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r31,0
	ctx.r31.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8810ef10
	if (!ctx.cr6.eq) goto loc_8810EF10;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// b 0x8810ef14
	goto loc_8810EF14;
loc_8810EF10:
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
loc_8810EF14:
	// stw r11,96(r29)
	PPC_STORE_U32(ctx.r29.u32 + 96, ctx.r11.u32);
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r11,100(r29)
	PPC_STORE_U32(ctx.r29.u32 + 100, ctx.r11.u32);
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8810ef34
	if (ctx.cr6.eq) goto loc_8810EF34;
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
loc_8810EF34:
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8810ef48
	if (!ctx.cr6.eq) goto loc_8810EF48;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// b 0x8810ef4c
	goto loc_8810EF4C;
loc_8810EF48:
	// lwz r11,164(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_8810EF4C:
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// li r5,1120
	ctx.r5.s64 = 1120;
	// stw r10,2332(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2332, ctx.r10.u32);
	// stw r11,2328(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2328, ctx.r11.u32);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x88095178
	ctx.lr = 0x8810EF64;
	sub_88095178(ctx, base);
	// li r6,34
	ctx.r6.s64 = 34;
	// li r5,70
	ctx.r5.s64 = 70;
	// li r4,92
	ctx.r4.s64 = 92;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x880e32d0
	ctx.lr = 0x8810EF78;
	sub_880E32D0(ctx, base);
	// lwz r9,80(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 80);
	// lis r8,-30679
	ctx.r8.s64 = -2010578944;
	// lis r7,128
	ctx.r7.s64 = 8388608;
	// addi r6,r8,-15272
	ctx.r6.s64 = ctx.r8.s64 + -15272;
	// ori r3,r7,32896
	ctx.r3.u64 = ctx.r7.u64 | 32896;
	// stw r31,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r31.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,32
	ctx.r4.s64 = 32;
	// sth r31,54(r29)
	PPC_STORE_U16(ctx.r29.u32 + 54, ctx.r31.u16);
	// lis r8,-30643
	ctx.r8.s64 = -2008219648;
	// sth r5,56(r29)
	PPC_STORE_U16(ctx.r29.u32 + 56, ctx.r5.u16);
	// sth r31,58(r29)
	PPC_STORE_U16(ctx.r29.u32 + 58, ctx.r31.u16);
	// li r10,5
	ctx.r10.s64 = 5;
	// stw r4,44(r29)
	PPC_STORE_U32(ctx.r29.u32 + 44, ctx.r4.u32);
	// addi r7,r8,32248
	ctx.r7.s64 = ctx.r8.s64 + 32248;
	// stw r3,84(r29)
	PPC_STORE_U32(ctx.r29.u32 + 84, ctx.r3.u32);
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// lwz r9,32(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 32);
	// srawi r9,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 1;
	// addze r9,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r9.s64 = temp.s64;
	// stw r9,32(r29)
	PPC_STORE_U32(ctx.r29.u32 + 32, ctx.r9.u32);
	// lwz r9,20(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	// stw r31,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r31.u32);
	// stw r10,32248(r8)
	PPC_STORE_U32(ctx.r8.u32 + 32248, ctx.r10.u32);
	// stw r9,16(r7)
	PPC_STORE_U32(ctx.r7.u32 + 16, ctx.r9.u32);
	// lwz r8,76(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 76);
	// cmpwi cr6,r8,1
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 1, ctx.xer);
	// bne cr6,0x8810f114
	if (!ctx.cr6.eq) goto loc_8810F114;
	// lis r11,16838
	ctx.r11.s64 = 1103495168;
	// lis r10,-3856
	ctx.r10.s64 = -252706816;
	// lis r9,14563
	ctx.r9.s64 = 954400768;
	// lis r8,20944
	ctx.r8.s64 = 1372585984;
	// lis r7,21399
	ctx.r7.s64 = 1402404864;
	// li r28,5
	ctx.r28.s64 = 5;
	// ori r30,r11,20077
	ctx.r30.u64 = ctx.r11.u64 | 20077;
	// ori r23,r10,61681
	ctx.r23.u64 = ctx.r10.u64 | 61681;
	// lis r31,-30671
	ctx.r31.s64 = -2010054656;
	// ori r24,r9,36409
	ctx.r24.u64 = ctx.r9.u64 | 36409;
	// ori r25,r8,32431
	ctx.r25.u64 = ctx.r8.u64 | 32431;
	// ori r26,r7,33437
	ctx.r26.u64 = ctx.r7.u64 | 33437;
	// li r22,128
	ctx.r22.s64 = 128;
loc_8810F01C:
	// lwz r11,4200(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4200);
	// li r3,51
	ctx.r3.s64 = 51;
	// stw r22,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r22.u32);
	// mullw r11,r11,r30
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// lwz r5,4(r29)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r27,8(r29)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// stw r11,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r11.u32);
	// mullw r11,r11,r30
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// lhz r4,4200(r31)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// stw r11,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r11.u32);
	// mulhwu r10,r4,r25
	ctx.r10.u64 = (uint64_t(ctx.r4.u32) * uint64_t(ctx.r25.u32)) >> 32;
	// mullw r9,r11,r30
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// addi r11,r9,12345
	ctx.r11.s64 = ctx.r9.s64 + 12345;
	// lhz r9,4200(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// stw r11,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r11.u32);
	// mulhwu r7,r9,r26
	ctx.r7.u64 = (uint64_t(ctx.r9.u32) * uint64_t(ctx.r26.u32)) >> 32;
	// mullw r8,r11,r30
	ctx.r8.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// lhz r11,4200(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// rlwinm r6,r7,28,4,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 28) & 0xFFFFFFF;
	// stw r8,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r8.u32);
	// subf r8,r10,r4
	ctx.r8.s64 = ctx.r4.s64 - ctx.r10.s64;
	// lhz r20,4200(r31)
	ctx.r20.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// rlwinm r8,r8,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mulli r8,r6,49
	ctx.r8.s64 = ctx.r6.s64 * 49;
	// rlwinm r7,r10,26,6,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 26) & 0x3FFFFFF;
	// subf r8,r8,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r8.s64;
	// mulhwu r9,r20,r23
	ctx.r9.u64 = (uint64_t(ctx.r20.u32) * uint64_t(ctx.r23.u32)) >> 32;
	// mulli r21,r7,97
	ctx.r21.s64 = ctx.r7.s64 * 97;
	// mulhwu r7,r11,r24
	ctx.r7.u64 = (uint64_t(ctx.r11.u32) * uint64_t(ctx.r24.u32)) >> 32;
	// rlwinm r9,r9,28,4,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 28) & 0xFFFFFFF;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// rlwinm r11,r7,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r6,r9,4,0,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r7,r11,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r6,r6,r9
	ctx.r6.u64 = ctx.r6.u64 + ctx.r9.u64;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// subf r9,r6,r20
	ctx.r9.s64 = ctx.r20.s64 - ctx.r6.s64;
	// subf r7,r11,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r11.s64;
	// extsh r10,r9
	ctx.r10.s64 = ctx.r9.s16;
	// extsh r11,r7
	ctx.r11.s64 = ctx.r7.s16;
	// addi r10,r10,56
	ctx.r10.s64 = ctx.r10.s64 + 56;
	// addi r9,r11,20
	ctx.r9.s64 = ctx.r11.s64 + 20;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// subf r6,r21,r4
	ctx.r6.s64 = ctx.r4.s64 - ctx.r21.s64;
	// stw r7,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// extsh r10,r8
	ctx.r10.s64 = ctx.r8.s16;
	// extsh r11,r6
	ctx.r11.s64 = ctx.r6.s16;
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// addi r9,r11,40
	ctx.r9.s64 = ctx.r11.s64 + 40;
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r9,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// add r4,r10,r5
	ctx.r4.u64 = ctx.r10.u64 + ctx.r5.u64;
	// add r5,r11,r27
	ctx.r5.u64 = ctx.r11.u64 + ctx.r27.u64;
	// bl 0x880958a0
	ctx.lr = 0x8810F10C;
	sub_880958A0(ctx, base);
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bne 0x8810f01c
	if (!ctx.cr0.eq) goto loc_8810F01C;
loc_8810F114:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x88071188
	__restgprlr_20(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810F000"))) PPC_WEAK_FUNC(sub_8810F000);
PPC_FUNC_IMPL(__imp__sub_8810F000) {
	PPC_FUNC_PROLOGUE();
	// ori r30,r11,20077
	ctx.r30.u64 = ctx.r11.u64 | 20077;
	// ori r23,r10,61681
	ctx.r23.u64 = ctx.r10.u64 | 61681;
	// lis r31,-30671
	ctx.r31.s64 = -2010054656;
	// ori r24,r9,36409
	ctx.r24.u64 = ctx.r9.u64 | 36409;
	// ori r25,r8,32431
	ctx.r25.u64 = ctx.r8.u64 | 32431;
	// ori r26,r7,33437
	ctx.r26.u64 = ctx.r7.u64 | 33437;
	// li r22,128
	ctx.r22.s64 = 128;
loc_8810F01C:
	// lwz r11,4200(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4200);
	// li r3,51
	ctx.r3.s64 = 51;
	// stw r22,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r22.u32);
	// mullw r11,r11,r30
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// lwz r5,4(r29)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r27,8(r29)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// stw r11,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r11.u32);
	// mullw r11,r11,r30
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// lhz r4,4200(r31)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// stw r11,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r11.u32);
	// mulhwu r10,r4,r25
	ctx.r10.u64 = (uint64_t(ctx.r4.u32) * uint64_t(ctx.r25.u32)) >> 32;
	// mullw r9,r11,r30
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// addi r11,r9,12345
	ctx.r11.s64 = ctx.r9.s64 + 12345;
	// lhz r9,4200(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// stw r11,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r11.u32);
	// mulhwu r7,r9,r26
	ctx.r7.u64 = (uint64_t(ctx.r9.u32) * uint64_t(ctx.r26.u32)) >> 32;
	// mullw r8,r11,r30
	ctx.r8.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// lhz r11,4200(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// rlwinm r6,r7,28,4,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 28) & 0xFFFFFFF;
	// stw r8,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r8.u32);
	// subf r8,r10,r4
	ctx.r8.s64 = ctx.r4.s64 - ctx.r10.s64;
	// lhz r20,4200(r31)
	ctx.r20.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// rlwinm r8,r8,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mulli r8,r6,49
	ctx.r8.s64 = ctx.r6.s64 * 49;
	// rlwinm r7,r10,26,6,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 26) & 0x3FFFFFF;
	// subf r8,r8,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r8.s64;
	// mulhwu r9,r20,r23
	ctx.r9.u64 = (uint64_t(ctx.r20.u32) * uint64_t(ctx.r23.u32)) >> 32;
	// mulli r21,r7,97
	ctx.r21.s64 = ctx.r7.s64 * 97;
	// mulhwu r7,r11,r24
	ctx.r7.u64 = (uint64_t(ctx.r11.u32) * uint64_t(ctx.r24.u32)) >> 32;
	// rlwinm r9,r9,28,4,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 28) & 0xFFFFFFF;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// rlwinm r11,r7,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r6,r9,4,0,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r7,r11,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r6,r6,r9
	ctx.r6.u64 = ctx.r6.u64 + ctx.r9.u64;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// subf r9,r6,r20
	ctx.r9.s64 = ctx.r20.s64 - ctx.r6.s64;
	// subf r7,r11,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r11.s64;
	// extsh r10,r9
	ctx.r10.s64 = ctx.r9.s16;
	// extsh r11,r7
	ctx.r11.s64 = ctx.r7.s16;
	// addi r10,r10,56
	ctx.r10.s64 = ctx.r10.s64 + 56;
	// addi r9,r11,20
	ctx.r9.s64 = ctx.r11.s64 + 20;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// subf r6,r21,r4
	ctx.r6.s64 = ctx.r4.s64 - ctx.r21.s64;
	// stw r7,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// extsh r10,r8
	ctx.r10.s64 = ctx.r8.s16;
	// extsh r11,r6
	ctx.r11.s64 = ctx.r6.s16;
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// addi r9,r11,40
	ctx.r9.s64 = ctx.r11.s64 + 40;
	// rlwinm r11,r10,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r9,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// add r4,r10,r5
	ctx.r4.u64 = ctx.r10.u64 + ctx.r5.u64;
	// add r5,r11,r27
	ctx.r5.u64 = ctx.r11.u64 + ctx.r27.u64;
	// bl 0x880958a0
	ctx.lr = 0x8810F10C;
	sub_880958A0(ctx, base);
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bne 0x8810f01c
	if (!ctx.cr0.eq) goto loc_8810F01C;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x88071188
	__restgprlr_20(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810F120"))) PPC_WEAK_FUNC(sub_8810F120);
PPC_FUNC_IMPL(__imp__sub_8810F120) {
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
	// lis r5,-292
	ctx.r5.s64 = -19136512;
	// li r4,24
	ctx.r4.s64 = 24;
	// ori r5,r5,47768
	ctx.r5.u64 = ctx.r5.u64 | 47768;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x8810F148;
	sub_88094290(ctx, base);
	// li r5,24
	ctx.r5.s64 = 24;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r30,2304(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2304);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88073bd0
	ctx.lr = 0x8810F15C;
	sub_88073BD0(ctx, base);
	// lwz r6,32(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,10
	ctx.r11.s64 = 10;
	// lis r10,-30703
	ctx.r10.s64 = -2012151808;
	// stw r11,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r11.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r8,r10,-10480
	ctx.r8.s64 = ctx.r10.s64 + -10480;
	// stw r6,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r6.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r5,36(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r5,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r5.u32);
	// stw r8,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r8.u32);
	// stw r9,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r9.u32);
	// stw r7,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r7.u32);
	// bl 0x88169750
	ctx.lr = 0x8810F198;
	sub_88169750(ctx, base);
	// lwz r6,132(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// lis r4,-30703
	ctx.r4.s64 = -2012151808;
	// lis r11,-30703
	ctx.r11.s64 = -2012151808;
	// addi r9,r4,-9864
	ctx.r9.s64 = ctx.r4.s64 + -9864;
	// addi r7,r11,-10432
	ctx.r7.s64 = ctx.r11.s64 + -10432;
	// sth r6,12(r30)
	PPC_STORE_U16(ctx.r30.u32 + 12, ctx.r6.u16);
	// lis r3,-30703
	ctx.r3.s64 = -2012151808;
	// addi r8,r3,-6792
	ctx.r8.s64 = ctx.r3.s64 + -6792;
	// lwz r4,136(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 136);
	// sth r4,14(r30)
	PPC_STORE_U16(ctx.r30.u32 + 14, ctx.r4.u16);
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// and r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 & ctx.r11.u64;
	// stw r6,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r6.u32);
	// stw r9,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r9.u32);
	// stw r8,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r8.u32);
	// stw r7,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r7.u32);
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

__attribute__((alias("__imp__sub_8810F1FC"))) PPC_WEAK_FUNC(sub_8810F1FC);
PPC_FUNC_IMPL(__imp__sub_8810F1FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810F200"))) PPC_WEAK_FUNC(sub_8810F200);
PPC_FUNC_IMPL(__imp__sub_8810F200) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x8810F208;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r5,-292
	ctx.r5.s64 = -19136512;
	// li r4,68
	ctx.r4.s64 = 68;
	// ori r5,r5,47768
	ctx.r5.u64 = ctx.r5.u64 | 47768;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x8810F220;
	sub_88094290(ctx, base);
	// li r5,68
	ctx.r5.s64 = 68;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,2304(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2304);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x8810F234;
	sub_88073BD0(ctx, base);
	// li r28,448
	ctx.r28.s64 = 448;
	// li r11,112
	ctx.r11.s64 = 112;
	// stw r30,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// stw r28,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r28.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,32(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,168(r30)
	PPC_STORE_U32(ctx.r30.u32 + 168, ctx.r11.u32);
	// addi r29,r31,28
	ctx.r29.s64 = ctx.r31.s64 + 28;
	// stw r10,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r10.u32);
	// lwz r9,36(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// stw r9,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r9.u32);
	// bl 0x881556a0
	ctx.lr = 0x8810F268;
	sub_881556A0(ctx, base);
	// lis r8,-30703
	ctx.r8.s64 = -2012151808;
	// stw r3,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r3.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r8,-5200
	ctx.r6.s64 = ctx.r8.s64 + -5200;
	// stw r31,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r31.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r6,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r6.u32);
	// lwz r5,52(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// stw r7,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r7.u32);
	// lwz r9,52(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r11,28(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8810f2b8
	if (ctx.cr6.eq) goto loc_8810F2B8;
loc_8810F2A0:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8810f32c
	if (ctx.cr6.eq) goto loc_8810F32C;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8810f2a0
	if (!ctx.cr6.eq) goto loc_8810F2A0;
loc_8810F2B8:
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
loc_8810F2BC:
	// li r9,56
	ctx.r9.s64 = 56;
	// stw r29,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r29.u32);
	// li r10,34
	ctx.r10.s64 = 34;
	// stw r8,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// li r6,32767
	ctx.r6.s64 = 32767;
	// stw r9,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r9.u32);
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// lis r5,-30597
	ctx.r5.s64 = -2005204992;
	// stw r9,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r9.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// stw r6,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r6.u32);
	// lwz r11,100(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 100);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// lwz r10,-11984(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + -11984);
	// addi r4,r9,-1
	ctx.r4.s64 = ctx.r9.s64 + -1;
	// and r3,r4,r11
	ctx.r3.u64 = ctx.r4.u64 & ctx.r11.u64;
	// stw r3,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r3.u32);
	// lwz r11,84(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// blt cr6,0x8810f344
	if (ctx.cr6.lt) goto loc_8810F344;
	// beq cr6,0x8810f344
	if (ctx.cr6.eq) goto loc_8810F344;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x8810f348
	if (!ctx.cr6.lt) goto loc_8810F348;
	// li r11,512
	ctx.r11.s64 = 512;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// b 0x8810f348
	goto loc_8810F348;
loc_8810F32C:
	// lwz r10,24(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8810f33c
	if (ctx.cr6.eq) goto loc_8810F33C;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_8810F33C:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x8810f2bc
	goto loc_8810F2BC;
loc_8810F344:
	// stw r28,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r28.u32);
loc_8810F348:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lis r10,-30703
	ctx.r10.s64 = -2012151808;
	// stw r8,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r8.u32);
	// lis r9,-30703
	ctx.r9.s64 = -2012151808;
	// lis r8,-30703
	ctx.r8.s64 = -2012151808;
	// stw r7,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r7.u32);
	// li r7,64
	ctx.r7.s64 = 64;
	// addi r6,r10,-6344
	ctx.r6.s64 = ctx.r10.s64 + -6344;
	// addi r5,r9,-6480
	ctx.r5.s64 = ctx.r9.s64 + -6480;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// addi r4,r8,-9928
	ctx.r4.s64 = ctx.r8.s64 + -9928;
	// stw r7,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r7.u32);
	// stw r6,64(r30)
	PPC_STORE_U32(ctx.r30.u32 + 64, ctx.r6.u32);
	// stw r5,68(r30)
	PPC_STORE_U32(ctx.r30.u32 + 68, ctx.r5.u32);
	// stw r4,84(r30)
	PPC_STORE_U32(ctx.r30.u32 + 84, ctx.r4.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810F38C"))) PPC_WEAK_FUNC(sub_8810F38C);
PPC_FUNC_IMPL(__imp__sub_8810F38C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810F390"))) PPC_WEAK_FUNC(sub_8810F390);
PPC_FUNC_IMPL(__imp__sub_8810F390) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x8810F398;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30633
	ctx.r11.s64 = -2007564288;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r11,-29780(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -29780);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8810f3bc
	if (ctx.cr6.eq) goto loc_8810F3BC;
	// bl 0x88094220
	ctx.lr = 0x8810F3B4;
	sub_88094220(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8810F3BC:
	// lis r5,-292
	ctx.r5.s64 = -19136512;
	// li r4,104
	ctx.r4.s64 = 104;
	// ori r5,r5,47768
	ctx.r5.u64 = ctx.r5.u64 | 47768;
	// bl 0x88094290
	ctx.lr = 0x8810F3CC;
	sub_88094290(ctx, base);
	// li r5,104
	ctx.r5.s64 = 104;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,2304(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2304);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x8810F3E0;
	sub_88073BD0(ctx, base);
	// stw r30,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x881556a0
	ctx.lr = 0x8810F3F0;
	sub_881556A0(ctx, base);
	// lis r11,-30703
	ctx.r11.s64 = -2012151808;
	// stw r3,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r3.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r10,r11,-4408
	ctx.r10.s64 = ctx.r11.s64 + -4408;
	// stw r31,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r31.u32);
	// li r29,0
	ctx.r29.s64 = 0;
	// stw r10,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r10.u32);
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// stw r6,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r6.u32);
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r11,28(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8810f440
	if (ctx.cr6.eq) goto loc_8810F440;
loc_8810F428:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8810f570
	if (ctx.cr6.eq) goto loc_8810F570;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8810f428
	if (!ctx.cr6.eq) goto loc_8810F428;
loc_8810F440:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_8810F444:
	// li r9,48
	ctx.r9.s64 = 48;
	// li r8,22
	ctx.r8.s64 = 22;
	// lis r7,80
	ctx.r7.s64 = 5242880;
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// li r28,10
	ctx.r28.s64 = 10;
	// stw r9,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r9.u32);
	// addi r10,r31,4
	ctx.r10.s64 = ctx.r31.s64 + 4;
	// stw r7,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r7.u32);
	// stw r8,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r8.u32);
	// mr r9,r6
	ctx.r9.u64 = ctx.r6.u64;
	// stw r10,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r10.u32);
	// stw r28,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r28.u32);
	// lwz r8,80(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r11,28(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8810f49c
	if (ctx.cr6.eq) goto loc_8810F49C;
loc_8810F484:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8810f588
	if (ctx.cr6.eq) goto loc_8810F588;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8810f484
	if (!ctx.cr6.eq) goto loc_8810F484;
loc_8810F49C:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_8810F4A0:
	// stw r7,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r7.u32);
	// li r7,64
	ctx.r7.s64 = 64;
	// li r5,80
	ctx.r5.s64 = 80;
	// stw r6,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r6.u32);
	// stw r7,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r7.u32);
	// li r9,-22
	ctx.r9.s64 = -22;
	// stw r5,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r5.u32);
	// li r8,56
	ctx.r8.s64 = 56;
	// li r4,129
	ctx.r4.s64 = 129;
	// stw r9,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r9.u32);
	// stw r8,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
	// lis r9,-30703
	ctx.r9.s64 = -2012151808;
	// stw r10,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r4,168(r30)
	PPC_STORE_U32(ctx.r30.u32 + 168, ctx.r4.u32);
	// addi r8,r9,-10528
	ctx.r8.s64 = ctx.r9.s64 + -10528;
	// lwz r7,32(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// lwz r5,36(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// stw r5,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r5.u32);
	// stw r8,76(r30)
	PPC_STORE_U32(ctx.r30.u32 + 76, ctx.r8.u32);
	// stw r6,96(r30)
	PPC_STORE_U32(ctx.r30.u32 + 96, ctx.r6.u32);
	// stw r29,80(r30)
	PPC_STORE_U32(ctx.r30.u32 + 80, ctx.r29.u32);
	// bl 0x88169750
	ctx.lr = 0x8810F500;
	sub_88169750(ctx, base);
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lwz r7,132(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 132);
	// lis r4,64
	ctx.r4.s64 = 4194304;
	// lwz r6,8(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lis r3,32
	ctx.r3.s64 = 2097152;
	// li r8,1024
	ctx.r8.s64 = 1024;
	// lwz r9,-11984(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11984);
	// addis r11,r6,-8
	ctx.r11.s64 = ctx.r6.s64 + -524288;
	// sth r7,24(r31)
	PPC_STORE_U16(ctx.r31.u32 + 24, ctx.r7.u16);
	// lwz r10,136(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 136);
	// sth r10,26(r31)
	PPC_STORE_U16(ctx.r31.u32 + 26, ctx.r10.u16);
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// stw r4,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r4.u32);
	// stw r3,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r3.u32);
	// lwz r11,100(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 100);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// stw r8,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r8.u32);
	// addi r6,r10,-1
	ctx.r6.s64 = ctx.r10.s64 + -1;
	// and r5,r6,r11
	ctx.r5.u64 = ctx.r6.u64 & ctx.r11.u64;
	// stw r5,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r5.u32);
	// lwz r11,176(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 176);
	// cmpwi cr6,r11,352
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 352, ctx.xer);
	// blt cr6,0x8810f5a0
	if (ctx.cr6.lt) goto loc_8810F5A0;
	// cmpwi cr6,r11,496
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 496, ctx.xer);
	// bgt cr6,0x8810f5a8
	if (ctx.cr6.gt) goto loc_8810F5A8;
	// li r10,2048
	ctx.r10.s64 = 2048;
	// b 0x8810f5ac
	goto loc_8810F5AC;
loc_8810F570:
	// lwz r10,24(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8810f580
	if (ctx.cr6.eq) goto loc_8810F580;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_8810F580:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x8810f444
	goto loc_8810F444;
loc_8810F588:
	// lwz r9,24(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8810f598
	if (ctx.cr6.eq) goto loc_8810F598;
	// stw r9,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r9.u32);
loc_8810F598:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x8810f4a0
	goto loc_8810F4A0;
loc_8810F5A0:
	// cmpwi cr6,r11,496
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 496, ctx.xer);
	// ble cr6,0x8810f5b0
	if (!ctx.cr6.gt) goto loc_8810F5B0;
loc_8810F5A8:
	// li r10,1792
	ctx.r10.s64 = 1792;
loc_8810F5AC:
	// stw r10,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r10.u32);
loc_8810F5B0:
	// li r10,29127
	ctx.r10.s64 = 29127;
	// cmpwi cr6,r11,352
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 352, ctx.xer);
	// sth r10,52(r31)
	PPC_STORE_U16(ctx.r31.u32 + 52, ctx.r10.u16);
	// blt cr6,0x8810f5cc
	if (ctx.cr6.lt) goto loc_8810F5CC;
	// cmpwi cr6,r11,424
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 424, ctx.xer);
	// bgt cr6,0x8810f5cc
	if (ctx.cr6.gt) goto loc_8810F5CC;
	// sth r29,52(r31)
	PPC_STORE_U16(ctx.r31.u32 + 52, ctx.r29.u16);
loc_8810F5CC:
	// li r11,128
	ctx.r11.s64 = 128;
	// sth r29,56(r31)
	PPC_STORE_U16(ctx.r31.u32 + 56, ctx.r29.u16);
	// stw r11,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// lwz r10,84(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 84);
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// stw r10,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r10.u32);
	// bne cr6,0x8810f644
	if (!ctx.cr6.eq) goto loc_8810F644;
	// lwz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// li r3,511
	ctx.r3.s64 = 511;
	// addi r11,r11,1280
	ctx.r11.s64 = ctx.r11.s64 + 1280;
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// bl 0x881534c8
	ctx.lr = 0x8810F5FC;
	sub_881534C8(ctx, base);
	// extsh r10,r3
	ctx.r10.s64 = ctx.r3.s16;
	// li r9,5
	ctx.r9.s64 = 5;
	// stw r10,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r9.u32);
	// bl 0x881534c8
	ctx.lr = 0x8810F614;
	sub_881534C8(ctx, base);
	// extsh r8,r3
	ctx.r8.s64 = ctx.r3.s16;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x8810f62c
	if (ctx.cr6.eq) goto loc_8810F62C;
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// neg r10,r11
	ctx.r10.s64 = -ctx.r11.s64;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
loc_8810F62C:
	// li r3,15
	ctx.r3.s64 = 15;
	// bl 0x881534c8
	ctx.lr = 0x8810F634;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// stw r28,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r28.u32);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// stw r11,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
loc_8810F644:
	// lis r11,-30703
	ctx.r11.s64 = -2012151808;
	// lis r10,-30703
	ctx.r10.s64 = -2012151808;
	// lis r9,-30703
	ctx.r9.s64 = -2012151808;
	// addi r8,r11,-8136
	ctx.r8.s64 = ctx.r11.s64 + -8136;
	// addi r7,r10,-8872
	ctx.r7.s64 = ctx.r10.s64 + -8872;
	// addi r6,r9,-9992
	ctx.r6.s64 = ctx.r9.s64 + -9992;
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
}

__attribute__((alias("__imp__sub_8810F670"))) PPC_WEAK_FUNC(sub_8810F670);
PPC_FUNC_IMPL(__imp__sub_8810F670) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8810F674"))) PPC_WEAK_FUNC(sub_8810F674);
PPC_FUNC_IMPL(__imp__sub_8810F674) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810F678"))) PPC_WEAK_FUNC(sub_8810F678);
PPC_FUNC_IMPL(__imp__sub_8810F678) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x8810F680;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r5,2304(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// li r26,1
	ctx.r26.s64 = 1;
	// li r28,0
	ctx.r28.s64 = 0;
	// li r29,3
	ctx.r29.s64 = 3;
	// lwz r11,68(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 68);
	// lwz r27,-11984(r10)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11984);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x8810f700
	if (ctx.cr6.gt) goto loc_8810F700;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x8810f9c0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8810F9C0;
	// bdzf 4*cr6+eq,0x8810f9f8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8810F9F8;
	// bne cr6,0x8810fa60
	if (!ctx.cr6.eq) goto loc_8810FA60;
	// lwz r11,72(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 72);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,72(r5)
	PPC_STORE_U32(ctx.r5.u32 + 72, ctx.r11.u32);
	// bgt 0x8810f700
	if (ctx.cr0.gt) goto loc_8810F700;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// stw r26,68(r5)
	PPC_STORE_U32(ctx.r5.u32 + 68, ctx.r26.u32);
	// li r10,32
	ctx.r10.s64 = 32;
	// addi r7,r11,30408
	ctx.r7.s64 = ctx.r11.s64 + 30408;
	// stw r10,72(r5)
	PPC_STORE_U32(ctx.r5.u32 + 72, ctx.r10.u32);
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// mr r8,r28
	ctx.r8.u64 = ctx.r28.u64;
	// stw r28,256(r7)
	PPC_STORE_U32(ctx.r7.u32 + 256, ctx.r28.u32);
	// stw r28,468(r7)
	PPC_STORE_U32(ctx.r7.u32 + 468, ctx.r28.u32);
	// stw r28,680(r7)
	PPC_STORE_U32(ctx.r7.u32 + 680, ctx.r28.u32);
	// stw r28,892(r7)
	PPC_STORE_U32(ctx.r7.u32 + 892, ctx.r28.u32);
loc_8810F700:
	// lwz r10,236(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 236);
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// lis r30,-256
	ctx.r30.s64 = -16777216;
	// lis r31,256
	ctx.r31.s64 = 16777216;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r4,r11,9552
	ctx.r4.s64 = ctx.r11.s64 + 9552;
	// beq cr6,0x8810f7d0
	if (ctx.cr6.eq) goto loc_8810F7D0;
	// addi r8,r5,8
	ctx.r8.s64 = ctx.r5.s64 + 8;
loc_8810F720:
	// lwz r9,-4(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4);
	// li r3,2
	ctx.r3.s64 = 2;
	// lwz r10,64(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 64);
	// rlwinm r25,r9,2,21,29
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x7FC;
	// lwz r11,-8(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -8);
	// clrlwi r9,r9,23
	ctx.r9.u64 = ctx.r9.u32 & 0x1FF;
	// lwz r6,0(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r11,r9,128
	ctx.r11.s64 = ctx.r9.s64 + 128;
	// lwzx r10,r25,r4
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r25.u32 + ctx.r4.u32);
	// rlwinm r9,r11,2,21,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x7FC;
	// mullw r11,r10,r7
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32);
	// lwzx r25,r9,r4
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r4.u32);
	// add r6,r11,r6
	ctx.r6.u64 = ctx.r11.u64 + ctx.r6.u64;
	// stw r6,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r6.u32);
	// bl 0x88094af0
	ctx.lr = 0x8810F760;
	sub_88094AF0(ctx, base);
	// mullw r9,r25,r7
	ctx.r9.s64 = int64_t(ctx.r25.s32) * int64_t(ctx.r7.s32);
	// lwz r10,4(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// add r7,r3,r6
	ctx.r7.u64 = ctx.r3.u64 + ctx.r6.u64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rotlwi r11,r7,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// stw r7,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
	// stw r10,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r10.u32);
	// cmpw cr6,r11,r30
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r30.s32, ctx.xer);
	// bgt cr6,0x8810f78c
	if (ctx.cr6.gt) goto loc_8810F78C;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
loc_8810F78C:
	// lwz r11,0(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmpw cr6,r11,r31
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r31.s32, ctx.xer);
	// blt cr6,0x8810f7a0
	if (ctx.cr6.lt) goto loc_8810F7A0;
	// subf r11,r31,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r31.s64;
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
loc_8810F7A0:
	// cmpw cr6,r10,r30
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r30.s32, ctx.xer);
	// bgt cr6,0x8810f7b0
	if (ctx.cr6.gt) goto loc_8810F7B0;
	// add r11,r10,r31
	ctx.r11.u64 = ctx.r10.u64 + ctx.r31.u64;
	// stw r11,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r11.u32);
loc_8810F7B0:
	// lwz r11,4(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cmpw cr6,r11,r31
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r31.s32, ctx.xer);
	// blt cr6,0x8810f7c4
	if (ctx.cr6.lt) goto loc_8810F7C4;
	// subf r11,r31,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r31.s64;
	// stw r11,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r11.u32);
loc_8810F7C4:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// bne 0x8810f720
	if (!ctx.cr0.eq) goto loc_8810F720;
loc_8810F7D0:
	// lwz r10,52(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 52);
	// lis r9,-30643
	ctx.r9.s64 = -2008219648;
	// lwz r7,48(r5)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r5.u32 + 48);
	// addi r11,r5,48
	ctx.r11.s64 = ctx.r5.s64 + 48;
	// clrlwi r10,r10,23
	ctx.r10.u64 = ctx.r10.u32 & 0x1FF;
	// lwz r8,56(r5)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + 56);
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r10,128
	ctx.r3.s64 = ctx.r10.s64 + 128;
	// lwz r9,26272(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 26272);
	// rlwinm r3,r3,2,21,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x7FC;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// lwzx r10,r6,r4
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r4.u32);
	// mullw r10,r10,r7
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32);
	// lwzx r9,r3,r4
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r4.u32);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// mullw r8,r9,r7
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r7.s32);
	// stw r10,56(r5)
	PPC_STORE_U32(ctx.r5.u32 + 56, ctx.r10.u32);
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// bne cr6,0x8810f820
	if (!ctx.cr6.eq) goto loc_8810F820;
	// lwz r9,212(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 212);
loc_8810F820:
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r9,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r9.u32);
	// cmpw cr6,r10,r30
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r30.s32, ctx.xer);
	// bgt cr6,0x8810f848
	if (ctx.cr6.gt) goto loc_8810F848;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + ctx.r31.u64;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
loc_8810F848:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// cmpw cr6,r10,r31
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r31.s32, ctx.xer);
	// blt cr6,0x8810f85c
	if (ctx.cr6.lt) goto loc_8810F85C;
	// subf r10,r31,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r31.s64;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
loc_8810F85C:
	// cmpw cr6,r9,r30
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r30.s32, ctx.xer);
	// bgt cr6,0x8810f86c
	if (ctx.cr6.gt) goto loc_8810F86C;
	// add r10,r9,r31
	ctx.r10.u64 = ctx.r9.u64 + ctx.r31.u64;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
loc_8810F86C:
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// cmpw cr6,r10,r31
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r31.s32, ctx.xer);
	// blt cr6,0x8810f880
	if (ctx.cr6.lt) goto loc_8810F880;
	// subf r10,r31,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r31.s64;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
loc_8810F880:
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r6,r5,84
	ctx.r6.s64 = ctx.r5.s64 + 84;
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
	// lis r3,4
	ctx.r3.s64 = 262144;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8810F898:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8810f950
	if (ctx.cr6.eq) goto loc_8810F950;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8810f950
	if (!ctx.cr6.eq) goto loc_8810F950;
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r7,32(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// clrlwi r10,r9,23
	ctx.r10.u64 = ctx.r9.u32 & 0x1FF;
	// lwz r30,12(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// rlwinm r29,r9,2,21,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x7FC;
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// addi r25,r10,128
	ctx.r25.s64 = ctx.r10.s64 + 128;
	// lwz r8,20(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// addic. r10,r7,-1
	ctx.xer.ca = ctx.r7.u32 > 0;
	ctx.r10.s64 = ctx.r7.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// rlwinm r25,r25,2,21,29
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 2) & 0x7FC;
	// lwzx r7,r29,r4
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r4.u32);
	// mullw r7,r7,r30
	ctx.r7.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r30.s32);
	// lwzx r29,r25,r4
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r25.u32 + ctx.r4.u32);
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// mullw r10,r29,r30
	ctx.r10.s64 = int64_t(ctx.r29.s32) * int64_t(ctx.r30.s32);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r9,r7,r8
	ctx.r9.u64 = ctx.r7.u64 + ctx.r8.u64;
	// stw r10,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r10.u32);
	// stw r9,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r9.u32);
	// bge 0x8810f950
	if (!ctx.cr0.lt) goto loc_8810F950;
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// lwz r8,36(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r9,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r9.u32);
	// cmpwi cr6,r9,23
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 23, ctx.xer);
	// stw r8,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r8.u32);
	// ble cr6,0x8810f928
	if (!ctx.cr6.gt) goto loc_8810F928;
	// stw r28,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r28.u32);
	// cmpwi cr6,r9,23
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 23, ctx.xer);
loc_8810F928:
	// bne cr6,0x8810f950
	if (!ctx.cr6.eq) goto loc_8810F950;
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r8,1
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 1, ctx.xer);
	// bne cr6,0x8810f944
	if (!ctx.cr6.eq) goto loc_8810F944;
	// subf r9,r3,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r3.s64;
	// subf r10,r3,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r3.s64;
loc_8810F944:
	// lwz r8,40(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// stw r9,64(r8)
	PPC_STORE_U32(ctx.r8.u32 + 64, ctx.r9.u32);
	// stw r10,68(r8)
	PPC_STORE_U32(ctx.r8.u32 + 68, ctx.r10.u32);
loc_8810F950:
	// addi r11,r11,56
	ctx.r11.s64 = ctx.r11.s64 + 56;
	// bdnz 0x8810f898
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8810F898;
	// lwz r11,196(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 196);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8810f9b8
	if (!ctx.cr6.eq) goto loc_8810F9B8;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne cr6,0x8810f9b8
	if (!ctx.cr6.eq) goto loc_8810F9B8;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// stw r26,196(r5)
	PPC_STORE_U32(ctx.r5.u32 + 196, ctx.r26.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r9,r11,26432
	ctx.r9.s64 = ctx.r11.s64 + 26432;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// addi r11,r6,40
	ctx.r11.s64 = ctx.r6.s64 + 40;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// stw r28,136(r9)
	PPC_STORE_U32(ctx.r9.u32 + 136, ctx.r28.u32);
	// stw r28,124(r27)
	PPC_STORE_U32(ctx.r27.u32 + 124, ctx.r28.u32);
	// stw r28,120(r27)
	PPC_STORE_U32(ctx.r27.u32 + 120, ctx.r28.u32);
loc_8810F994:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8810f9a8
	if (ctx.cr6.eq) goto loc_8810F9A8;
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// stw r8,112(r10)
	PPC_STORE_U32(ctx.r10.u32 + 112, ctx.r8.u32);
loc_8810F9A8:
	// addi r11,r11,56
	ctx.r11.s64 = ctx.r11.s64 + 56;
	// bdnz 0x8810f994
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8810F994;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stw r28,304(r9)
	PPC_STORE_U32(ctx.r9.u32 + 304, ctx.r28.u32);
loc_8810F9B8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_8810F9C0:
	// lwz r11,72(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 72);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8810f9d8
	if (ctx.cr6.eq) goto loc_8810F9D8;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,72(r5)
	PPC_STORE_U32(ctx.r5.u32 + 72, ctx.r11.u32);
	// b 0x8810f700
	goto loc_8810F700;
loc_8810F9D8:
	// lwz r11,236(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 236);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,236(r5)
	PPC_STORE_U32(ctx.r5.u32 + 236, ctx.r11.u32);
	// bgt 0x8810f700
	if (ctx.cr0.gt) goto loc_8810F700;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r28,236(r5)
	PPC_STORE_U32(ctx.r5.u32 + 236, ctx.r28.u32);
	// stw r11,68(r5)
	PPC_STORE_U32(ctx.r5.u32 + 68, ctx.r11.u32);
	// b 0x8810f700
	goto loc_8810F700;
loc_8810F9F8:
	// lwz r9,176(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 176);
	// cmpwi cr6,r9,64
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 64, ctx.xer);
	// blt cr6,0x8810fa50
	if (ctx.cr6.lt) goto loc_8810FA50;
	// lwz r11,244(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 244);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,244(r5)
	PPC_STORE_U32(ctx.r5.u32 + 244, ctx.r11.u32);
	// bge 0x8810fa50
	if (!ctx.cr0.lt) goto loc_8810FA50;
	// lwz r10,252(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 252);
	// lwz r11,240(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 240);
	// lwz r8,248(r5)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + 248);
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r10,252(r5)
	PPC_STORE_U32(ctx.r5.u32 + 252, ctx.r10.u32);
	// stw r8,244(r5)
	PPC_STORE_U32(ctx.r5.u32 + 244, ctx.r8.u32);
	// ble cr6,0x8810fa40
	if (!ctx.cr6.gt) goto loc_8810FA40;
	// cmpwi cr6,r10,160
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 160, ctx.xer);
	// blt cr6,0x8810fa50
	if (ctx.cr6.lt) goto loc_8810FA50;
	// b 0x8810fa48
	goto loc_8810FA48;
loc_8810FA40:
	// cmpwi cr6,r10,32
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 32, ctx.xer);
	// bgt cr6,0x8810fa50
	if (ctx.cr6.gt) goto loc_8810FA50;
loc_8810FA48:
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
	// stw r11,240(r5)
	PPC_STORE_U32(ctx.r5.u32 + 240, ctx.r11.u32);
loc_8810FA50:
	// cmpwi cr6,r9,536
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 536, ctx.xer);
	// blt cr6,0x8810f700
	if (ctx.cr6.lt) goto loc_8810F700;
	// stw r29,68(r5)
	PPC_STORE_U32(ctx.r5.u32 + 68, ctx.r29.u32);
	// b 0x8810f700
	goto loc_8810F700;
loc_8810FA60:
	// lwz r11,252(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 252);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,252(r5)
	PPC_STORE_U32(ctx.r5.u32 + 252, ctx.r11.u32);
	// bgt 0x8810f700
	if (ctx.cr0.gt) goto loc_8810F700;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,252(r5)
	PPC_STORE_U32(ctx.r5.u32 + 252, ctx.r11.u32);
	// bl 0x88094220
	ctx.lr = 0x8810FA7C;
	sub_88094220(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810FA84"))) PPC_WEAK_FUNC(sub_8810FA84);
PPC_FUNC_IMPL(__imp__sub_8810FA84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810FA88"))) PPC_WEAK_FUNC(sub_8810FA88);
PPC_FUNC_IMPL(__imp__sub_8810FA88) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071138
	ctx.lr = 0x8810FA90;
	__savegprlr_20(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r26,2304(r3)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r20,-30597
	ctx.r20.s64 = -2005204992;
	// lis r23,128
	ctx.r23.s64 = 8388608;
	// lis r22,256
	ctx.r22.s64 = 16777216;
	// lwz r11,236(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 236);
	// lwz r25,-11932(r20)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r20.u32 + -11932);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8810fb3c
	if (ctx.cr6.eq) goto loc_8810FB3C;
	// addi r24,r26,12
	ctx.r24.s64 = ctx.r26.s64 + 12;
	// li r21,3
	ctx.r21.s64 = 3;
loc_8810FABC:
	// lwz r11,-4(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + -4);
	// li r28,4
	ctx.r28.s64 = 4;
	// lwz r10,0(r24)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// subf r27,r23,r11
	ctx.r27.s64 = ctx.r11.s64 - ctx.r23.s64;
	// subf r29,r23,r10
	ctx.r29.s64 = ctx.r10.s64 - ctx.r23.s64;
loc_8810FAD0:
	// mr r31,r27
	ctx.r31.u64 = ctx.r27.u64;
	// li r30,3
	ctx.r30.s64 = 3;
loc_8810FAD8:
	// li r6,130
	ctx.r6.s64 = 130;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,1221
	ctx.r3.s64 = 1221;
	// bl 0x881538c0
	ctx.lr = 0x8810FAEC;
	sub_881538C0(ctx, base);
	// lwz r11,236(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 236);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x8810fb14
	if (ctx.cr6.eq) goto loc_8810FB14;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_8810FB14:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// add r31,r31,r22
	ctx.r31.u64 = ctx.r31.u64 + ctx.r22.u64;
	// bne 0x8810fad8
	if (!ctx.cr0.eq) goto loc_8810FAD8;
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// add r29,r29,r22
	ctx.r29.u64 = ctx.r29.u64 + ctx.r22.u64;
	// bne 0x8810fad0
	if (!ctx.cr0.eq) goto loc_8810FAD0;
	// addic. r21,r21,-1
	ctx.xer.ca = ctx.r21.u32 > 0;
	ctx.r21.s64 = ctx.r21.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// addi r24,r24,16
	ctx.r24.s64 = ctx.r24.s64 + 16;
	// bne 0x8810fabc
	if (!ctx.cr0.eq) goto loc_8810FABC;
	// stw r25,-11932(r20)
	PPC_STORE_U32(ctx.r20.u32 + -11932, ctx.r25.u32);
loc_8810FB3C:
	// lwz r11,252(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 252);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8810fbbc
	if (ctx.cr6.eq) goto loc_8810FBBC;
	// lwz r11,56(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 56);
	// li r28,4
	ctx.r28.s64 = 4;
	// lwz r10,60(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 60);
	// subf r27,r23,r11
	ctx.r27.s64 = ctx.r11.s64 - ctx.r23.s64;
	// subf r29,r23,r10
	ctx.r29.s64 = ctx.r10.s64 - ctx.r23.s64;
loc_8810FB5C:
	// mr r31,r27
	ctx.r31.u64 = ctx.r27.u64;
	// li r30,3
	ctx.r30.s64 = 3;
loc_8810FB64:
	// li r6,119
	ctx.r6.s64 = 119;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,1221
	ctx.r3.s64 = 1221;
	// bl 0x881538c0
	ctx.lr = 0x8810FB78;
	sub_881538C0(ctx, base);
	// lwz r11,252(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 252);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x8810fba0
	if (ctx.cr6.eq) goto loc_8810FBA0;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_8810FBA0:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// add r31,r31,r22
	ctx.r31.u64 = ctx.r31.u64 + ctx.r22.u64;
	// bne 0x8810fb64
	if (!ctx.cr0.eq) goto loc_8810FB64;
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// add r29,r29,r22
	ctx.r29.u64 = ctx.r29.u64 + ctx.r22.u64;
	// bne 0x8810fb5c
	if (!ctx.cr0.eq) goto loc_8810FB5C;
	// stw r25,-11932(r20)
	PPC_STORE_U32(ctx.r20.u32 + -11932, ctx.r25.u32);
loc_8810FBBC:
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r11,-30680
	ctx.r11.s64 = -2010644480;
	// addi r29,r26,84
	ctx.r29.s64 = ctx.r26.s64 + 84;
	// li r26,2
	ctx.r26.s64 = 2;
	// ori r28,r10,49565
	ctx.r28.u64 = ctx.r10.u64 | 49565;
	// ori r27,r9,49541
	ctx.r27.u64 = ctx.r9.u64 | 49541;
	// addi r30,r11,18376
	ctx.r30.s64 = ctx.r11.s64 + 18376;
loc_8810FBDC:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8810fc8c
	if (ctx.cr6.eq) goto loc_8810FC8C;
	// lwz r11,4(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// addi r31,r29,24
	ctx.r31.s64 = ctx.r29.s64 + 24;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8810fc40
	if (!ctx.cr6.eq) goto loc_8810FC40;
	// lwz r8,28(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 28);
	// addi r11,r30,-48
	ctx.r11.s64 = ctx.r30.s64 + -48;
	// addi r7,r30,-48
	ctx.r7.s64 = ctx.r30.s64 + -48;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// lwz r9,-4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + -4);
	// rlwinm r4,r8,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r8,r28
	ctx.r3.u64 = ctx.r8.u64 + ctx.r28.u64;
	// li r6,131
	ctx.r6.s64 = 131;
	// lbzx r8,r4,r5
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r5.u32);
	// lbzx r11,r4,r7
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r7.u32);
	// extsb r5,r8
	ctx.r5.s64 = ctx.r8.s8;
	// extsb r7,r11
	ctx.r7.s64 = ctx.r11.s8;
	// rlwinm r11,r5,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r8,r7,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r4,r8,r9
	ctx.r4.u64 = ctx.r8.u64 + ctx.r9.u64;
	// bl 0x881538c0
	ctx.lr = 0x8810FC40;
	sub_881538C0(ctx, base);
loc_8810FC40:
	// lwz r11,-20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -20);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8810fc8c
	if (!ctx.cr6.eq) goto loc_8810FC8C;
	// lwz r11,28(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 28);
	// addi r8,r30,1
	ctx.r8.s64 = ctx.r30.s64 + 1;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r6,131
	ctx.r6.s64 = 131;
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,-4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -4);
	// add r3,r11,r27
	ctx.r3.u64 = ctx.r11.u64 + ctx.r27.u64;
	// lbzx r5,r7,r8
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r8.u32);
	// lbzx r4,r7,r30
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r30.u32);
	// extsb r11,r5
	ctx.r11.s64 = ctx.r5.s8;
	// extsb r7,r4
	ctx.r7.s64 = ctx.r4.s8;
	// rlwinm r8,r11,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r7,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// add r5,r8,r9
	ctx.r5.u64 = ctx.r8.u64 + ctx.r9.u64;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x8810FC8C;
	sub_881538C0(ctx, base);
loc_8810FC8C:
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// addi r29,r29,56
	ctx.r29.s64 = ctx.r29.s64 + 56;
	// bne 0x8810fbdc
	if (!ctx.cr0.eq) goto loc_8810FBDC;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x88071188
	__restgprlr_20(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810FCA0"))) PPC_WEAK_FUNC(sub_8810FCA0);
PPC_FUNC_IMPL(__imp__sub_8810FCA0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071134
	ctx.lr = 0x8810FCA8;
	__savegprlr_19(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r5,-292
	ctx.r5.s64 = -19136512;
	// li r4,312
	ctx.r4.s64 = 312;
	// ori r5,r5,47768
	ctx.r5.u64 = ctx.r5.u64 | 47768;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x8810FCC0;
	sub_88094290(ctx, base);
	// li r5,312
	ctx.r5.s64 = 312;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,2304(r26)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r26.u32 + 2304);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x8810FCD4;
	sub_88073BD0(ctx, base);
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// lis r10,16838
	ctx.r10.s64 = 1103495168;
	// li r7,3
	ctx.r7.s64 = 3;
	// ori r10,r10,20077
	ctx.r10.u64 = ctx.r10.u64 | 20077;
	// li r29,4
	ctx.r29.s64 = 4;
	// lwz r9,4200(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4200);
	// li r28,2
	ctx.r28.s64 = 2;
	// li r27,1
	ctx.r27.s64 = 1;
	// mullw r9,r9,r10
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// addi r9,r9,12345
	ctx.r9.s64 = ctx.r9.s64 + 12345;
	// li r30,5
	ctx.r30.s64 = 5;
	// stw r9,4200(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4200, ctx.r9.u32);
	// mullw r9,r9,r10
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// addi r9,r9,12345
	ctx.r9.s64 = ctx.r9.s64 + 12345;
	// li r3,80
	ctx.r3.s64 = 80;
	// mullw r6,r9,r10
	ctx.r6.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// lhz r8,4200(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4200);
	// stw r9,4200(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4200, ctx.r9.u32);
	// clrlwi r9,r8,23
	ctx.r9.u64 = ctx.r8.u32 & 0x1FF;
	// lhz r8,4200(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4200);
	// clrlwi r5,r8,27
	ctx.r5.u64 = ctx.r8.u32 & 0x1F;
	// stw r9,304(r31)
	PPC_STORE_U32(ctx.r31.u32 + 304, ctx.r9.u32);
	// addi r9,r6,12345
	ctx.r9.s64 = ctx.r6.s64 + 12345;
	// li r4,64
	ctx.r4.s64 = 64;
	// mullw r6,r9,r10
	ctx.r6.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// stw r9,4200(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4200, ctx.r9.u32);
	// lhz r8,4200(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4200);
	// addi r9,r6,12345
	ctx.r9.s64 = ctx.r6.s64 + 12345;
	// lwz r6,304(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 304);
	// clrlwi r20,r8,28
	ctx.r20.u64 = ctx.r8.u32 & 0xF;
	// stw r9,4200(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4200, ctx.r9.u32);
	// li r25,160
	ctx.r25.s64 = 160;
	// lhz r8,4200(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4200);
	// clrlwi r19,r8,28
	ctx.r19.u64 = ctx.r8.u32 & 0xF;
	// add r8,r5,r6
	ctx.r8.u64 = ctx.r5.u64 + ctx.r6.u64;
	// li r24,96
	ctx.r24.s64 = 96;
	// addi r8,r8,31
	ctx.r8.s64 = ctx.r8.s64 + 31;
	// li r23,128
	ctx.r23.s64 = 128;
	// stw r8,308(r31)
	PPC_STORE_U32(ctx.r31.u32 + 308, ctx.r8.u32);
	// li r22,112
	ctx.r22.s64 = 112;
	// lwz r8,100(r26)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r26.u32 + 100);
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// rlwinm r6,r8,1,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0x1;
	// stw r29,224(r31)
	PPC_STORE_U32(ctx.r31.u32 + 224, ctx.r29.u32);
	// stw r29,220(r31)
	PPC_STORE_U32(ctx.r31.u32 + 220, ctx.r29.u32);
	// li r21,48
	ctx.r21.s64 = 48;
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// stw r28,212(r31)
	PPC_STORE_U32(ctx.r31.u32 + 212, ctx.r28.u32);
	// li r29,0
	ctx.r29.s64 = 0;
	// stw r28,208(r31)
	PPC_STORE_U32(ctx.r31.u32 + 208, ctx.r28.u32);
	// and r5,r6,r8
	ctx.r5.u64 = ctx.r6.u64 & ctx.r8.u64;
	// stw r20,216(r31)
	PPC_STORE_U32(ctx.r31.u32 + 216, ctx.r20.u32);
	// stw r19,228(r31)
	PPC_STORE_U32(ctx.r31.u32 + 228, ctx.r19.u32);
	// addi r8,r31,4
	ctx.r8.s64 = ctx.r31.s64 + 4;
	// stw r5,232(r31)
	PPC_STORE_U32(ctx.r31.u32 + 232, ctx.r5.u32);
	// stw r28,240(r31)
	PPC_STORE_U32(ctx.r31.u32 + 240, ctx.r28.u32);
	// stw r7,248(r31)
	PPC_STORE_U32(ctx.r31.u32 + 248, ctx.r7.u32);
	// stw r7,244(r31)
	PPC_STORE_U32(ctx.r31.u32 + 244, ctx.r7.u32);
	// stw r25,236(r31)
	PPC_STORE_U32(ctx.r31.u32 + 236, ctx.r25.u32);
	// stw r27,256(r31)
	PPC_STORE_U32(ctx.r31.u32 + 256, ctx.r27.u32);
	// stw r30,264(r31)
	PPC_STORE_U32(ctx.r31.u32 + 264, ctx.r30.u32);
	// stw r30,260(r31)
	PPC_STORE_U32(ctx.r31.u32 + 260, ctx.r30.u32);
	// stw r3,268(r31)
	PPC_STORE_U32(ctx.r31.u32 + 268, ctx.r3.u32);
	// stw r24,272(r31)
	PPC_STORE_U32(ctx.r31.u32 + 272, ctx.r24.u32);
	// stw r23,276(r31)
	PPC_STORE_U32(ctx.r31.u32 + 276, ctx.r23.u32);
	// stw r4,280(r31)
	PPC_STORE_U32(ctx.r31.u32 + 280, ctx.r4.u32);
	// stw r3,284(r31)
	PPC_STORE_U32(ctx.r31.u32 + 284, ctx.r3.u32);
	// stw r22,288(r31)
	PPC_STORE_U32(ctx.r31.u32 + 288, ctx.r22.u32);
	// stw r27,292(r31)
	PPC_STORE_U32(ctx.r31.u32 + 292, ctx.r27.u32);
	// stw r4,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r4.u32);
	// lis r7,20164
	ctx.r7.s64 = 1321467904;
	// stw r21,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r21.u32);
	// lis r6,15887
	ctx.r6.s64 = 1041170432;
	// ori r4,r7,60495
	ctx.r4.u64 = ctx.r7.u64 | 60495;
	// ori r6,r6,33761
	ctx.r6.u64 = ctx.r6.u64 | 33761;
loc_8810FE04:
	// mullw r9,r9,r10
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// addi r9,r9,12345
	ctx.r9.s64 = ctx.r9.s64 + 12345;
	// clrlwi r5,r29,31
	ctx.r5.u64 = ctx.r29.u32 & 0x1;
	// stw r9,4200(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4200, ctx.r9.u32);
	// mullw r9,r9,r10
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// lhz r3,4200(r11)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4200);
	// addi r9,r9,12345
	ctx.r9.s64 = ctx.r9.s64 + 12345;
	// stw r9,4200(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4200, ctx.r9.u32);
	// mulhwu r7,r3,r4
	ctx.r7.u64 = (uint64_t(ctx.r3.u32) * uint64_t(ctx.r4.u32)) >> 32;
	// rlwinm r7,r7,30,2,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 30) & 0x3FFFFFFF;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// mulli r5,r7,13
	ctx.r5.s64 = ctx.r7.s64 * 13;
	// subf r3,r5,r3
	ctx.r3.s64 = ctx.r3.s64 - ctx.r5.s64;
	// extsh r7,r3
	ctx.r7.s64 = ctx.r3.s16;
	// lhz r3,4200(r11)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4200);
	// addi r7,r7,16
	ctx.r7.s64 = ctx.r7.s64 + 16;
	// stw r7,-4(r8)
	PPC_STORE_U32(ctx.r8.u32 + -4, ctx.r7.u32);
	// mulhwu r7,r3,r6
	ctx.r7.u64 = (uint64_t(ctx.r3.u32) * uint64_t(ctx.r6.u32)) >> 32;
	// rlwinm r7,r7,29,3,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 29) & 0x1FFFFFFF;
	// rlwinm r5,r7,5,0,26
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// add r5,r5,r7
	ctx.r5.u64 = ctx.r5.u64 + ctx.r7.u64;
	// subf r3,r5,r3
	ctx.r3.s64 = ctx.r3.s64 - ctx.r5.s64;
	// beq cr6,0x8810fe74
	if (ctx.cr6.eq) goto loc_8810FE74;
	// extsh r7,r3
	ctx.r7.s64 = ctx.r3.s16;
	// addi r5,r7,112
	ctx.r5.s64 = ctx.r7.s64 + 112;
	// rlwinm r3,r5,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r3,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r3.u32);
	// b 0x8810fe84
	goto loc_8810FE84;
loc_8810FE74:
	// extsh r5,r3
	ctx.r5.s64 = ctx.r3.s16;
	// subfic r3,r5,144
	ctx.xer.ca = ctx.r5.u32 <= 144;
	ctx.r3.s64 = 144 - ctx.r5.s64;
	// rlwinm r7,r3,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r7,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
loc_8810FE84:
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// bdnz 0x8810fe04
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8810FE04;
	// mullw r10,r9,r10
	ctx.r10.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// mtctr r28
	ctx.ctr.u64 = ctx.r28.u64;
	// addi r10,r10,12345
	ctx.r10.s64 = ctx.r10.s64 + 12345;
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// stw r10,4200(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4200, ctx.r10.u32);
	// lis r8,-30643
	ctx.r8.s64 = -2008219648;
	// lhz r7,4200(r11)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4200);
	// mulhwu r6,r7,r4
	ctx.r6.u64 = (uint64_t(ctx.r7.u32) * uint64_t(ctx.r4.u32)) >> 32;
	// rlwinm r5,r6,30,2,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 30) & 0x3FFFFFFF;
	// lwz r10,-11984(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -11984);
	// li r9,192
	ctx.r9.s64 = 192;
	// mulli r3,r5,13
	ctx.r3.s64 = ctx.r5.s64 * 13;
	// stw r9,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r9.u32);
	// subf r11,r3,r7
	ctx.r11.s64 = ctx.r7.s64 - ctx.r3.s64;
	// addi r4,r8,26432
	ctx.r4.s64 = ctx.r8.s64 + 26432;
	// extsh r9,r11
	ctx.r9.s64 = ctx.r11.s16;
	// lis r7,-30680
	ctx.r7.s64 = -2010644480;
	// addi r6,r9,16
	ctx.r6.s64 = ctx.r9.s64 + 16;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r6,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r6.u32);
	// addi r9,r7,18296
	ctx.r9.s64 = ctx.r7.s64 + 18296;
	// stw r5,252(r31)
	PPC_STORE_U32(ctx.r31.u32 + 252, ctx.r5.u32);
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// stw r27,136(r4)
	PPC_STORE_U32(ctx.r4.u32 + 136, ctx.r27.u32);
	// mr r8,r28
	ctx.r8.u64 = ctx.r28.u64;
	// stw r27,124(r10)
	PPC_STORE_U32(ctx.r10.u32 + 124, ctx.r27.u32);
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// addi r11,r31,84
	ctx.r11.s64 = ctx.r31.s64 + 84;
	// stw r27,304(r4)
	PPC_STORE_U32(ctx.r4.u32 + 304, ctx.r27.u32);
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// addi r10,r10,1512
	ctx.r10.s64 = ctx.r10.s64 + 1512;
	// li r5,21
	ctx.r5.s64 = 21;
	// lis r6,-32
	ctx.r6.s64 = -2097152;
loc_8810FF14:
	// addic. r8,r10,-64
	ctx.xer.ca = ctx.r10.u32 > 63;
	ctx.r8.s64 = ctx.r10.s64 + -64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x8810ff98
	if (ctx.cr0.eq) goto loc_8810FF98;
	// lbz r7,-64(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + -64);
	// clrlwi r4,r7,31
	ctx.r4.u64 = ctx.r7.u32 & 0x1;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x8810ff98
	if (ctx.cr6.eq) goto loc_8810FF98;
	// stw r27,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r27.u32);
	// lbz r7,-56(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + -56);
	// stw r8,40(r11)
	PPC_STORE_U32(ctx.r11.u32 + 40, ctx.r8.u32);
	// stw r7,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r7.u32);
	// lwz r4,-8(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + -8);
	// stw r4,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r4.u32);
	// lwz r3,-4(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -4);
	// stw r3,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r3.u32);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r8,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r8.u32);
	// lwz r7,4(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r7,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r7.u32);
	// stw r5,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r5.u32);
	// stw r28,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r28.u32);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rotlwi r8,r4,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r4.u32, 0);
	// stw r4,44(r11)
	PPC_STORE_U32(ctx.r11.u32 + 44, ctx.r4.u32);
	// lwz r3,4(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r8,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r8.u32);
	// stw r3,48(r11)
	PPC_STORE_U32(ctx.r11.u32 + 48, ctx.r3.u32);
	// lwz r7,64(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// stw r6,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r6.u32);
	// lwz r8,48(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// lwz r7,120(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + 120);
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// stw r8,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r8.u32);
loc_8810FF98:
	// addi r11,r11,56
	ctx.r11.s64 = ctx.r11.s64 + 56;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// addi r10,r10,196
	ctx.r10.s64 = ctx.r10.s64 + 196;
	// bdnz 0x8810ff14
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8810FF14;
	// lis r11,-30703
	ctx.r11.s64 = -2012151808;
	// stw r27,240(r31)
	PPC_STORE_U32(ctx.r31.u32 + 240, ctx.r27.u32);
	// lis r10,-30703
	ctx.r10.s64 = -2012151808;
	// stw r28,248(r31)
	PPC_STORE_U32(ctx.r31.u32 + 248, ctx.r28.u32);
	// lis r9,-30703
	ctx.r9.s64 = -2012151808;
	// stw r28,244(r31)
	PPC_STORE_U32(ctx.r31.u32 + 244, ctx.r28.u32);
	// li r8,16
	ctx.r8.s64 = 16;
	// addi r7,r11,-2440
	ctx.r7.s64 = ctx.r11.s64 + -2440;
	// addi r6,r10,-1400
	ctx.r6.s64 = ctx.r10.s64 + -1400;
	// stw r8,252(r31)
	PPC_STORE_U32(ctx.r31.u32 + 252, ctx.r8.u32);
	// addi r5,r9,-2448
	ctx.r5.s64 = ctx.r9.s64 + -2448;
	// stw r7,64(r26)
	PPC_STORE_U32(ctx.r26.u32 + 64, ctx.r7.u32);
	// stw r6,68(r26)
	PPC_STORE_U32(ctx.r26.u32 + 68, ctx.r6.u32);
	// stw r5,84(r26)
	PPC_STORE_U32(ctx.r26.u32 + 84, ctx.r5.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x88071184
	__restgprlr_19(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8810FFE8"))) PPC_WEAK_FUNC(sub_8810FFE8);
PPC_FUNC_IMPL(__imp__sub_8810FFE8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8810FFEC"))) PPC_WEAK_FUNC(sub_8810FFEC);
PPC_FUNC_IMPL(__imp__sub_8810FFEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8810FFF0"))) PPC_WEAK_FUNC(sub_8810FFF0);
PPC_FUNC_IMPL(__imp__sub_8810FFF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071144
	ctx.lr = 0x8810FFF8;
	__savegprlr_23(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r29,2304(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// lwz r11,828(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 828);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x881100e8
	if (ctx.cr6.eq) goto loc_881100E8;
	// lwz r11,908(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 908);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x881100e8
	if (ctx.cr6.eq) goto loc_881100E8;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// li r3,511
	ctx.r3.s64 = 511;
	// stw r11,908(r29)
	PPC_STORE_U32(ctx.r29.u32 + 908, ctx.r11.u32);
	// bl 0x881534c8
	ctx.lr = 0x8811002C;
	sub_881534C8(ctx, base);
	// lis r9,-30643
	ctx.r9.s64 = -2008219648;
	// extsh r31,r3
	ctx.r31.s64 = ctx.r3.s16;
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// li r26,16
	ctx.r26.s64 = 16;
	// rlwinm r11,r31,2,21,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0x7FC;
	// lwz r28,26276(r9)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r9.u32 + 26276);
	// lis r27,224
	ctx.r27.s64 = 14680064;
	// li r25,0
	ctx.r25.s64 = 0;
	// li r23,1
	ctx.r23.s64 = 1;
	// addi r30,r10,9552
	ctx.r30.s64 = ctx.r10.s64 + 9552;
loc_88110054:
	// clrlwi r9,r31,23
	ctx.r9.u64 = ctx.r31.u32 & 0x1FF;
	// lwzx r11,r11,r30
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r30.u32);
	// lwz r8,4(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// addi r7,r9,128
	ctx.r7.s64 = ctx.r9.s64 + 128;
	// lwz r10,8(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r6,r7,2,21,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x7FC;
	// add r5,r11,r9
	ctx.r5.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r9,r5,7,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 7) & 0xFFFFFF80;
	// lwzx r11,r6,r30
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r30.u32);
	// add r4,r9,r8
	ctx.r4.u64 = ctx.r9.u64 + ctx.r8.u64;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r11,r9
	ctx.r3.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r3,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 8) & 0xFFFFFF00;
	// srawi r9,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 2;
	// addze r11,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r11.s64 = temp.s64;
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r5,r8,r27
	ctx.r5.u64 = ctx.r8.u64 + ctx.r27.u64;
	// bne cr6,0x881100d8
	if (!ctx.cr6.eq) goto loc_881100D8;
	// clrlwi r7,r31,16
	ctx.r7.u64 = ctx.r31.u32 & 0xFFFF;
	// stw r24,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r24.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// sth r25,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r25.u16);
	// li r3,46
	ctx.r3.s64 = 46;
	// bl 0x8815c948
	ctx.lr = 0x881100BC;
	sub_8815C948(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x881100d8
	if (ctx.cr6.eq) goto loc_881100D8;
	// stw r23,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r23.u32);
	// li r5,72
	ctx.r5.s64 = 72;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r3,36
	ctx.r3.s64 = ctx.r3.s64 + 36;
	// bl 0x88072260
	ctx.lr = 0x881100D8;
	sub_88072260(ctx, base);
loc_881100D8:
	// addi r31,r31,32
	ctx.r31.s64 = ctx.r31.s64 + 32;
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// rlwinm r11,r31,2,21,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0x7FC;
	// bne 0x88110054
	if (!ctx.cr0.eq) goto loc_88110054;
loc_881100E8:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_881100F0"))) PPC_WEAK_FUNC(sub_881100F0);
PPC_FUNC_IMPL(__imp__sub_881100F0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r9,952(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 952);
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

__attribute__((alias("__imp__sub_88110130"))) PPC_WEAK_FUNC(sub_88110130);
PPC_FUNC_IMPL(__imp__sub_88110130) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// li r10,512
	ctx.r10.s64 = 512;
	// lwz r11,2304(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2304);
	// rlwinm r9,r5,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0x1;
	// subfc r8,r10,r5
	ctx.xer.ca = ctx.r5.u32 >= ctx.r10.u32;
	ctx.r8.s64 = ctx.r5.s64 - ctx.r10.s64;
	// rlwinm r7,r10,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// cmplwi cr6,r3,4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 4, ctx.xer);
	// subfe r6,r9,r7
	temp.u8 = (~ctx.r9.u32 + ctx.r7.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r7.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ~ctx.r9.u64 + ctx.r7.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r5,844(r11)
	PPC_STORE_U32(ctx.r11.u32 + 844, ctx.r5.u32);
	// and r5,r6,r4
	ctx.r5.u64 = ctx.r6.u64 & ctx.r4.u64;
	// stw r5,840(r11)
	PPC_STORE_U32(ctx.r11.u32 + 840, ctx.r5.u32);
	// bne cr6,0x88110170
	if (!ctx.cr6.eq) goto loc_88110170;
	// lwz r11,952(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 952);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// blr 
	return;
loc_88110170:
	// cmplwi cr6,r3,5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 5, ctx.xer);
	// bne cr6,0x88110184
	if (!ctx.cr6.eq) goto loc_88110184;
	// lwz r11,952(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 952);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
loc_88110184:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8811018C"))) PPC_WEAK_FUNC(sub_8811018C);
PPC_FUNC_IMPL(__imp__sub_8811018C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88110190"))) PPC_WEAK_FUNC(sub_88110190);
PPC_FUNC_IMPL(__imp__sub_88110190) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071128
	ctx.lr = 0x88110198;
	__savegprlr_16(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// mr r17,r7
	ctx.r17.u64 = ctx.r7.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x881103e8
	if (ctx.cr6.eq) goto loc_881103E8;
	// lis r10,-30667
	ctx.r10.s64 = -2009792512;
	// lis r31,-30671
	ctx.r31.s64 = -2010054656;
	// mr r16,r11
	ctx.r16.u64 = ctx.r11.u64;
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// lis r9,-3856
	ctx.r9.s64 = -252706816;
	// stw r6,12376(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12376, ctx.r6.u32);
	// lis r10,16838
	ctx.r10.s64 = 1103495168;
	// lis r8,128
	ctx.r8.s64 = 8388608;
	// lwz r29,4200(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4200);
	// lis r7,-256
	ctx.r7.s64 = -16777216;
	// ori r28,r10,20077
	ctx.r28.u64 = ctx.r10.u64 | 20077;
	// ori r24,r9,61681
	ctx.r24.u64 = ctx.r9.u64 | 61681;
	// li r20,112
	ctx.r20.s64 = 112;
	// ori r23,r8,32912
	ctx.r23.u64 = ctx.r8.u64 | 32912;
	// ori r21,r7,65281
	ctx.r21.u64 = ctx.r7.u64 | 65281;
	// li r18,40
	ctx.r18.s64 = 40;
	// lis r26,-30667
	ctx.r26.s64 = -2009792512;
	// lis r25,-30667
	ctx.r25.s64 = -2009792512;
	// lis r19,-30667
	ctx.r19.s64 = -2009792512;
	// addi r22,r11,9552
	ctx.r22.s64 = ctx.r11.s64 + 9552;
loc_88110208:
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r8,12(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r9,4(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// add r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stw r11,12364(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12372, ctx.r10.u32);
	// bl 0x880f52c8
	ctx.lr = 0x88110230;
	sub_880F52C8(ctx, base);
	// mullw r11,r29,r28
	ctx.r11.s64 = int64_t(ctx.r29.s32) * int64_t(ctx.r28.s32);
	// lwz r10,20(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// addi r8,r11,12345
	ctx.r8.s64 = ctx.r11.s64 + 12345;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r8,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r8.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
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
	// beq cr6,0x881102bc
	if (ctx.cr6.eq) goto loc_881102BC;
	// lwz r9,16(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
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
	// beq 0x881102a4
	if (ctx.cr0.eq) goto loc_881102A4;
	// addi r6,r11,128
	ctx.r6.s64 = ctx.r11.s64 + 128;
	// rlwinm r5,r6,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// lwzx r6,r5,r22
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r22.u32);
	// mullw r5,r6,r9
	ctx.r5.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r9.s32);
	// stw r5,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r5.u32);
loc_881102A4:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x881102bc
	if (ctx.cr6.eq) goto loc_881102BC;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r22
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r22.u32);
	// mullw r9,r10,r9
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// stw r9,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r9.u32);
loc_881102BC:
	// mullw r11,r8,r28
	ctx.r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r28.s32);
	// addi r29,r11,12345
	ctx.r29.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r29,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r29.u32);
	// beq cr6,0x881102f0
	if (ctx.cr6.eq) goto loc_881102F0;
	// lhz r11,4200(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// lwz r10,24(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// rlwinm r11,r11,1,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x2;
	// stw r17,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r17.u32);
	// stw r20,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r20.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r23,160(r3)
	PPC_STORE_U32(ctx.r3.u32 + 160, ctx.r23.u32);
	// stw r11,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r11.u32);
loc_881102F0:
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// li r9,16
	ctx.r9.s64 = 16;
	// lwz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// li r3,16
	ctx.r3.s64 = 16;
	// stw r9,12380(r19)
	PPC_STORE_U32(ctx.r19.u32 + 12380, ctx.r9.u32);
	// stw r11,12364(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12372, ctx.r10.u32);
	// bl 0x880f52c8
	ctx.lr = 0x88110310;
	sub_880F52C8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8811031c
	if (ctx.cr6.eq) goto loc_8811031C;
	// stw r17,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r17.u32);
loc_8811031C:
	// mullw r11,r29,r28
	ctx.r11.s64 = int64_t(ctx.r29.s32) * int64_t(ctx.r28.s32);
	// addi r6,r11,12345
	ctx.r6.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r6,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r6.u32);
	// beq cr6,0x881103a4
	if (ctx.cr6.eq) goto loc_881103A4;
	// lhz r7,4200(r31)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// addic. r10,r3,40
	ctx.xer.ca = ctx.r3.u32 > 4294967255;
	ctx.r10.s64 = ctx.r3.s64 + 40;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r18,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, ctx.r18.u32);
	// addi r8,r3,36
	ctx.r8.s64 = ctx.r3.s64 + 36;
	// mulhwu r5,r7,r21
	ctx.r5.u64 = (uint64_t(ctx.r7.u32) * uint64_t(ctx.r21.u32)) >> 32;
	// rlwinm r11,r5,24,8,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 24) & 0xFFFFFF;
	// rlwinm r9,r11,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// subf r9,r11,r7
	ctx.r9.s64 = ctx.r7.s64 - ctx.r11.s64;
	// extsh r11,r9
	ctx.r11.s64 = ctx.r9.s16;
	// addi r11,r11,-128
	ctx.r11.s64 = ctx.r11.s64 + -128;
	// stw r11,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, ctx.r11.u32);
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// beq 0x88110384
	if (ctx.cr0.eq) goto loc_88110384;
	// addi r9,r11,128
	ctx.r9.s64 = ctx.r11.s64 + 128;
	// rlwinm r7,r9,2,21,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x7FC;
	// lwzx r9,r7,r22
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r22.u32);
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r9,r7
	ctx.r5.u64 = ctx.r9.u64 + ctx.r7.u64;
	// rlwinm r9,r5,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_88110384:
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x881103a4
	if (ctx.cr6.eq) goto loc_881103A4;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r22
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r22.u32);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r9,r10,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r9,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
loc_881103A4:
	// mullw r11,r6,r28
	ctx.r11.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r28.s32);
	// addi r29,r11,12345
	ctx.r29.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r29,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r29.u32);
	// beq cr6,0x881103dc
	if (ctx.cr6.eq) goto loc_881103DC;
	// lhz r11,4200(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// lwz r10,24(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// stw r20,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r20.u32);
	// stw r23,160(r3)
	PPC_STORE_U32(ctx.r3.u32 + 160, ctx.r23.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r10,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r10.u32);
loc_881103DC:
	// addic. r16,r16,-1
	ctx.xer.ca = ctx.r16.u32 > 0;
	ctx.r16.s64 = ctx.r16.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r16.s32, 0, ctx.xer);
	// addi r30,r30,36
	ctx.r30.s64 = ctx.r30.s64 + 36;
	// bne 0x88110208
	if (!ctx.cr0.eq) goto loc_88110208;
loc_881103E8:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071178
	__restgprlr_16(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_881103F0"))) PPC_WEAK_FUNC(sub_881103F0);
PPC_FUNC_IMPL(__imp__sub_881103F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807112c
	ctx.lr = 0x881103F8;
	__savegprlr_17(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r9,2300(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2300);
	// lis r8,547
	ctx.r8.s64 = 35848192;
	// lwz r10,184(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// lis r7,148
	ctx.r7.s64 = 9699328;
	// lwz r11,168(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// ori r18,r8,16384
	ctx.r18.u64 = ctx.r8.u64 | 16384;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// ori r19,r7,32464
	ctx.r19.u64 = ctx.r7.u64 | 32464;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r6,156(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 156);
	// lis r28,-30597
	ctx.r28.s64 = -2005204992;
	// add r26,r11,r4
	ctx.r26.u64 = ctx.r11.u64 + ctx.r4.u64;
	// lwz r5,160(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
	// srawi r4,r6,16
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xFFFF) != 0);
	ctx.r4.s64 = ctx.r6.s32 >> 16;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addze r10,r4
	temp.s64 = ctx.r4.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r10.s64 = temp.s64;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// srawi r8,r5,16
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xFFFF) != 0);
	ctx.r8.s64 = ctx.r5.s32 >> 16;
	// lwz r27,8(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r7,r10,32
	ctx.r7.s64 = ctx.r10.s64 + 32;
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addze r5,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r5.s64 = temp.s64;
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// rlwinm r8,r7,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// subfic r7,r5,128
	ctx.xer.ca = ctx.r5.u32 <= 128;
	ctx.r7.s64 = 128 - ctx.r5.s64;
	// srawi r5,r3,16
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFFFF) != 0);
	ctx.r5.s64 = ctx.r3.s32 >> 16;
	// rlwinm r10,r7,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// addze r3,r5
	temp.s64 = ctx.r5.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r3.s64 = temp.s64;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r9,r3,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 16) & 0xFFFF0000;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r11,r9,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r9.s64;
	// lis r20,16
	ctx.r20.s64 = 1048576;
	// lis r17,24
	ctx.r17.s64 = 1572864;
	// lis r21,-96
	ctx.r21.s64 = -6291456;
	// subf r25,r8,r6
	ctx.r25.s64 = ctx.r6.s64 - ctx.r8.s64;
	// add r24,r10,r27
	ctx.r24.u64 = ctx.r10.u64 + ctx.r27.u64;
	// add r22,r11,r27
	ctx.r22.u64 = ctx.r11.u64 + ctx.r27.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x881104f4
	if (ctx.cr6.eq) goto loc_881104F4;
	// add r5,r22,r17
	ctx.r5.u64 = ctx.r22.u64 + ctx.r17.u64;
	// cmpw cr6,r5,r21
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r21.s32, ctx.xer);
	// blt cr6,0x881104f4
	if (ctx.cr6.lt) goto loc_881104F4;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// subf r4,r20,r25
	ctx.r4.s64 = ctx.r25.s64 - ctx.r20.s64;
	// li r3,1002
	ctx.r3.s64 = 1002;
	// bl 0x881538c0
	ctx.lr = 0x881104BC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x881104f4
	if (ctx.cr6.eq) goto loc_881104F4;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-11932(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -11932);
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// or r8,r10,r18
	ctx.r8.u64 = ctx.r10.u64 | ctx.r18.u64;
	// lwz r7,16(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r30,r11,1
	ctx.r30.s64 = ctx.r11.s64 + 1;
	// stw r19,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r19.u32);
	// stw r30,-11932(r28)
	PPC_STORE_U32(ctx.r28.u32 + -11932, ctx.r30.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stw r7,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r7.u32);
	// b 0x881104f8
	goto loc_881104F8;
loc_881104F4:
	// lwz r30,-11932(r28)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r28.u32 + -11932);
loc_881104F8:
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bge cr6,0x881106d0
	if (!ctx.cr6.lt) goto loc_881106D0;
	// lis r23,320
	ctx.r23.s64 = 20971520;
	// lis r11,547
	ctx.r11.s64 = 35848192;
	// cmpw cr6,r24,r23
	ctx.cr6.compare<int32_t>(ctx.r24.s32, ctx.r23.s32, ctx.xer);
	// ori r29,r11,32768
	ctx.r29.u64 = ctx.r11.u64 | 32768;
	// bgt cr6,0x881105b0
	if (ctx.cr6.gt) goto loc_881105B0;
	// cmpw cr6,r24,r21
	ctx.cr6.compare<int32_t>(ctx.r24.s32, ctx.r21.s32, ctx.xer);
	// ble cr6,0x881105b0
	if (!ctx.cr6.gt) goto loc_881105B0;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// li r3,996
	ctx.r3.s64 = 996;
	// bl 0x881538c0
	ctx.lr = 0x88110534;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88110568
	if (ctx.cr6.eq) goto loc_88110568;
	// lwz r11,912(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 912);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r8,16(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// or r7,r10,r29
	ctx.r7.u64 = ctx.r10.u64 | ctx.r29.u64;
	// stw r30,-11932(r28)
	PPC_STORE_U32(ctx.r28.u32 + -11932, ctx.r30.u32);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
loc_88110568:
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// addis r5,r24,-64
	ctx.r5.s64 = ctx.r24.s64 + -4194304;
	// addis r4,r25,8
	ctx.r4.s64 = ctx.r25.s64 + 524288;
	// li r3,997
	ctx.r3.s64 = 997;
	// bl 0x881538c0
	ctx.lr = 0x8811057C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x881105b0
	if (ctx.cr6.eq) goto loc_881105B0;
	// lwz r11,912(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 912);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r8,16(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// or r7,r10,r29
	ctx.r7.u64 = ctx.r10.u64 | ctx.r29.u64;
	// stw r30,-11932(r28)
	PPC_STORE_U32(ctx.r28.u32 + -11932, ctx.r30.u32);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
loc_881105B0:
	// addis r5,r24,-96
	ctx.r5.s64 = ctx.r24.s64 + -6291456;
	// cmpw cr6,r5,r23
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r23.s32, ctx.xer);
	// bgt cr6,0x88110610
	if (ctx.cr6.gt) goto loc_88110610;
	// cmpw cr6,r5,r21
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r21.s32, ctx.xer);
	// ble cr6,0x88110610
	if (!ctx.cr6.gt) goto loc_88110610;
	// cmpw cr6,r27,r5
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r5.s32, ctx.xer);
	// bgt cr6,0x88110610
	if (ctx.cr6.gt) goto loc_88110610;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// add r4,r25,r20
	ctx.r4.u64 = ctx.r25.u64 + ctx.r20.u64;
	// li r3,998
	ctx.r3.s64 = 998;
	// bl 0x881538c0
	ctx.lr = 0x881105DC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88110610
	if (ctx.cr6.eq) goto loc_88110610;
	// lwz r11,912(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 912);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r8,16(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// or r7,r10,r29
	ctx.r7.u64 = ctx.r10.u64 | ctx.r29.u64;
	// stw r30,-11932(r28)
	PPC_STORE_U32(ctx.r28.u32 + -11932, ctx.r30.u32);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
loc_88110610:
	// addis r5,r24,-112
	ctx.r5.s64 = ctx.r24.s64 + -7340032;
	// cmpw cr6,r5,r23
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r23.s32, ctx.xer);
	// bgt cr6,0x88110670
	if (ctx.cr6.gt) goto loc_88110670;
	// cmpw cr6,r5,r21
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r21.s32, ctx.xer);
	// ble cr6,0x88110670
	if (!ctx.cr6.gt) goto loc_88110670;
	// cmpw cr6,r27,r5
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r5.s32, ctx.xer);
	// bgt cr6,0x88110670
	if (ctx.cr6.gt) goto loc_88110670;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// add r4,r25,r17
	ctx.r4.u64 = ctx.r25.u64 + ctx.r17.u64;
	// li r3,999
	ctx.r3.s64 = 999;
	// bl 0x881538c0
	ctx.lr = 0x8811063C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88110670
	if (ctx.cr6.eq) goto loc_88110670;
	// lwz r11,912(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 912);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r8,16(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// or r7,r10,r29
	ctx.r7.u64 = ctx.r10.u64 | ctx.r29.u64;
	// stw r30,-11932(r28)
	PPC_STORE_U32(ctx.r28.u32 + -11932, ctx.r30.u32);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
loc_88110670:
	// addis r5,r24,-128
	ctx.r5.s64 = ctx.r24.s64 + -8388608;
	// cmpw cr6,r5,r23
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r23.s32, ctx.xer);
	// bgt cr6,0x881106d0
	if (ctx.cr6.gt) goto loc_881106D0;
	// cmpw cr6,r5,r21
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r21.s32, ctx.xer);
	// ble cr6,0x881106d0
	if (!ctx.cr6.gt) goto loc_881106D0;
	// cmpw cr6,r27,r5
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r5.s32, ctx.xer);
	// bgt cr6,0x881106d0
	if (ctx.cr6.gt) goto loc_881106D0;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// addis r4,r25,28
	ctx.r4.s64 = ctx.r25.s64 + 1835008;
	// li r3,1000
	ctx.r3.s64 = 1000;
	// bl 0x881538c0
	ctx.lr = 0x8811069C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x881106d0
	if (ctx.cr6.eq) goto loc_881106D0;
	// lwz r11,912(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 912);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r8,16(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// or r7,r10,r29
	ctx.r7.u64 = ctx.r10.u64 | ctx.r29.u64;
	// stw r30,-11932(r28)
	PPC_STORE_U32(ctx.r28.u32 + -11932, ctx.r30.u32);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
loc_881106D0:
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88110720
	if (ctx.cr6.eq) goto loc_88110720;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// subf r5,r20,r22
	ctx.r5.s64 = ctx.r22.s64 - ctx.r20.s64;
	// subf r4,r17,r25
	ctx.r4.s64 = ctx.r25.s64 - ctx.r17.s64;
	// li r3,1001
	ctx.r3.s64 = 1001;
	// bl 0x881538c0
	ctx.lr = 0x881106F0;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88110720
	if (ctx.cr6.eq) goto loc_88110720;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r8,16(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// or r7,r10,r18
	ctx.r7.u64 = ctx.r10.u64 | ctx.r18.u64;
	// stw r19,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r19.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r11,-11932(r28)
	PPC_STORE_U32(ctx.r28.u32 + -11932, ctx.r11.u32);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
loc_88110720:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8807117c
	__restgprlr_17(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88110728"))) PPC_WEAK_FUNC(sub_88110728);
PPC_FUNC_IMPL(__imp__sub_88110728) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88110730;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r5)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r5.u32 + 2304);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,884(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 884);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x881108bc
	if (!ctx.cr6.gt) goto loc_881108BC;
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x88110760
	if (!ctx.cr6.eq) goto loc_88110760;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// stw r9,884(r31)
	PPC_STORE_U32(ctx.r31.u32 + 884, ctx.r9.u32);
loc_88110760:
	// lwz r11,884(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 884);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt cr6,0x881108bc
	if (ctx.cr6.gt) goto loc_881108BC;
	// lis r9,-30633
	ctx.r9.s64 = -2007564288;
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// stw r29,-29740(r9)
	PPC_STORE_U32(ctx.r9.u32 + -29740, ctx.r29.u32);
	// bne cr6,0x88110790
	if (!ctx.cr6.eq) goto loc_88110790;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// b 0x88110794
	goto loc_88110794;
loc_88110790:
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
loc_88110794:
	// stw r11,936(r31)
	PPC_STORE_U32(ctx.r31.u32 + 936, ctx.r11.u32);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r11,940(r31)
	PPC_STORE_U32(ctx.r31.u32 + 940, ctx.r11.u32);
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x881107b4
	if (ctx.cr6.eq) goto loc_881107B4;
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
loc_881107B4:
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x881107c8
	if (!ctx.cr6.eq) goto loc_881107C8;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// b 0x881107cc
	goto loc_881107CC;
loc_881107C8:
	// lwz r11,164(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_881107CC:
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r10,2332(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2332, ctx.r10.u32);
	// stw r11,2328(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2328, ctx.r11.u32);
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x881107ec
	if (!ctx.cr6.eq) goto loc_881107EC;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// b 0x881107f0
	goto loc_881107F0;
loc_881107EC:
	// lwz r11,164(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
loc_881107F0:
	// stw r11,944(r31)
	PPC_STORE_U32(ctx.r31.u32 + 944, ctx.r11.u32);
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88110808
	if (!ctx.cr6.eq) goto loc_88110808;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// b 0x8811080c
	goto loc_8811080C;
loc_88110808:
	// lwz r11,176(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
loc_8811080C:
	// stw r11,948(r31)
	PPC_STORE_U32(ctx.r31.u32 + 948, ctx.r11.u32);
	// li r5,6810
	ctx.r5.s64 = 6810;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x88095178
	ctx.lr = 0x8811081C;
	sub_88095178(ctx, base);
	// lwz r11,952(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 952);
	// li r30,1
	ctx.r30.s64 = 1;
	// stw r29,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r29.u32);
	// lwz r5,936(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 936);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// stw r30,956(r31)
	PPC_STORE_U32(ctx.r31.u32 + 956, ctx.r30.u32);
	// stw r29,896(r31)
	PPC_STORE_U32(ctx.r31.u32 + 896, ctx.r29.u32);
	// sth r29,900(r31)
	PPC_STORE_U16(ctx.r31.u32 + 900, ctx.r29.u16);
	// beq cr6,0x88110870
	if (ctx.cr6.eq) goto loc_88110870;
	// lwz r11,904(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 904);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x88110870
	if (!ctx.cr6.eq) goto loc_88110870;
	// li r3,32
	ctx.r3.s64 = 32;
	// lwz r6,948(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 948);
	// lwz r4,940(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 940);
	// bl 0x8815d688
	ctx.lr = 0x8811085C;
	sub_8815D688(ctx, base);
	// stw r30,928(r31)
	PPC_STORE_U32(ctx.r31.u32 + 928, ctx.r30.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r29,932(r31)
	PPC_STORE_U32(ctx.r31.u32 + 932, ctx.r29.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_88110870:
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lwz r11,-13956(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -13956);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x881108a8
	if (ctx.cr6.eq) goto loc_881108A8;
	// lis r10,4
	ctx.r10.s64 = 262144;
	// lis r9,4
	ctx.r9.s64 = 262144;
	// ori r8,r10,33876
	ctx.r8.u64 = ctx.r10.u64 | 33876;
	// ori r7,r9,33872
	ctx.r7.u64 = ctx.r9.u64 | 33872;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stwx r6,r11,r8
	PPC_STORE_U32(ctx.r11.u32 + ctx.r8.u32, ctx.r6.u32);
	// stwx r29,r11,r7
	PPC_STORE_U32(ctx.r11.u32 + ctx.r7.u32, ctx.r29.u32);
	// bl 0x8815d040
	ctx.lr = 0x881108A8;
	sub_8815D040(ctx, base);
loc_881108A8:
	// stw r30,928(r31)
	PPC_STORE_U32(ctx.r31.u32 + 928, ctx.r30.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r29,932(r31)
	PPC_STORE_U32(ctx.r31.u32 + 932, ctx.r29.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_881108BC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_881108C8"))) PPC_WEAK_FUNC(sub_881108C8);
PPC_FUNC_IMPL(__imp__sub_881108C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x881108D0;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r30,2304(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// lwz r11,168(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// lwz r10,184(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// add r28,r10,r11
	ctx.r28.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x88110974
	if (!ctx.cr6.gt) goto loc_88110974;
	// srawi r11,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 16;
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// li r31,320
	ctx.r31.s64 = 320;
	// lwz r5,8(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// addze r10,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r10.s64 = temp.s64;
	// addi r6,r28,-1
	ctx.r6.s64 = ctx.r28.s64 + -1;
	// mulli r9,r10,22
	ctx.r9.s64 = ctx.r10.s64 * 22;
	// divw r8,r9,r31
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r31.s32);
	// subfic r3,r8,419
	ctx.xer.ca = ctx.r8.u32 <= 419;
	ctx.r3.s64 = 419 - ctx.r8.s64;
	// bl 0x881538c0
	ctx.lr = 0x8811091C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88110940
	if (ctx.cr6.eq) goto loc_88110940;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// oris r8,r9,519
	ctx.r8.u64 = ctx.r9.u64 | 34013184;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// lwz r11,-11932(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11932);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-11932(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11932, ctx.r11.u32);
loc_88110940:
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// srawi r10,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 16;
	// addze r9,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r8,r9,6,0,25
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0xFFFFFFC0;
	// divw r7,r8,r31
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r31.s32);
	// subfic r11,r7,80
	ctx.xer.ca = ctx.r7.u32 <= 80;
	ctx.r11.s64 = 80 - ctx.r7.s64;
	// beq cr6,0x88110974
	if (ctx.cr6.eq) goto loc_88110974;
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
loc_88110974:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x881103f0
	ctx.lr = 0x88110980;
	sub_881103F0(ctx, base);
	// addi r31,r30,60
	ctx.r31.s64 = ctx.r30.s64 + 60;
	// li r29,16
	ctx.r29.s64 = 16;
loc_88110988:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x881109b0
	if (ctx.cr6.eq) goto loc_881109B0;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// li r3,11038
	ctx.r3.s64 = 11038;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bl 0x881538c0
	ctx.lr = 0x881109B0;
	sub_881538C0(ctx, base);
loc_881109B0:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r31,r31,48
	ctx.r31.s64 = ctx.r31.s64 + 48;
	// bne 0x88110988
	if (!ctx.cr0.eq) goto loc_88110988;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x881103f0
	ctx.lr = 0x881109C8;
	sub_881103F0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_881108E8"))) PPC_WEAK_FUNC(sub_881108E8);
PPC_FUNC_IMPL(__imp__sub_881108E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x88110974
	if (!ctx.cr6.gt) goto loc_88110974;
	// srawi r11,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 16;
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// li r31,320
	ctx.r31.s64 = 320;
	// lwz r5,8(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// addze r10,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r10.s64 = temp.s64;
	// addi r6,r28,-1
	ctx.r6.s64 = ctx.r28.s64 + -1;
	// mulli r9,r10,22
	ctx.r9.s64 = ctx.r10.s64 * 22;
	// divw r8,r9,r31
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r31.s32);
	// subfic r3,r8,419
	ctx.xer.ca = ctx.r8.u32 <= 419;
	ctx.r3.s64 = 419 - ctx.r8.s64;
	// bl 0x881538c0
	ctx.lr = 0x8811091C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88110940
	if (ctx.cr6.eq) goto loc_88110940;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// oris r8,r9,519
	ctx.r8.u64 = ctx.r9.u64 | 34013184;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// lwz r11,-11932(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11932);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-11932(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11932, ctx.r11.u32);
loc_88110940:
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// srawi r10,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 16;
	// addze r9,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r8,r9,6,0,25
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0xFFFFFFC0;
	// divw r7,r8,r31
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r31.s32);
	// subfic r11,r7,80
	ctx.xer.ca = ctx.r7.u32 <= 80;
	ctx.r11.s64 = 80 - ctx.r7.s64;
	// beq cr6,0x88110974
	if (ctx.cr6.eq) goto loc_88110974;
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
loc_88110974:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x881103f0
	ctx.lr = 0x88110980;
	sub_881103F0(ctx, base);
	// addi r31,r30,60
	ctx.r31.s64 = ctx.r30.s64 + 60;
	// li r29,16
	ctx.r29.s64 = 16;
loc_88110988:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x881109b0
	if (ctx.cr6.eq) goto loc_881109B0;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// li r3,11038
	ctx.r3.s64 = 11038;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bl 0x881538c0
	ctx.lr = 0x881109B0;
	sub_881538C0(ctx, base);
loc_881109B0:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r31,r31,48
	ctx.r31.s64 = ctx.r31.s64 + 48;
	// bne 0x88110988
	if (!ctx.cr0.eq) goto loc_88110988;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x881103f0
	ctx.lr = 0x881109C8;
	sub_881103F0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_881109D0"))) PPC_WEAK_FUNC(sub_881109D0);
PPC_FUNC_IMPL(__imp__sub_881109D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071120
	ctx.lr = 0x881109D8;
	__savegprlr_14(ctx, base);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// stw r3,324(r1)
	PPC_STORE_U32(ctx.r1.u32 + 324, ctx.r3.u32);
	// lwz r11,928(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 928);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x88110a0c
	if (!ctx.cr6.eq) goto loc_88110A0C;
	// lwz r11,932(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 932);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,932(r31)
	PPC_STORE_U32(ctx.r31.u32 + 932, ctx.r11.u32);
	// bgt 0x881113d8
	if (ctx.cr0.gt) goto loc_881113D8;
	// bl 0x88094220
	ctx.lr = 0x88110A04;
	sub_88094220(ctx, base);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
loc_88110A0C:
	// lwz r11,952(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 952);
	// li r23,0
	ctx.r23.s64 = 0;
	// mr r10,r23
	ctx.r10.u64 = ctx.r23.u64;
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88110a3c
	if (ctx.cr6.eq) goto loc_88110A3C;
loc_88110A24:
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// stw r23,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r23.u32);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88110a24
	if (!ctx.cr6.eq) goto loc_88110A24;
loc_88110A3C:
	// lis r11,148
	ctx.r11.s64 = 9699328;
	// stw r23,908(r31)
	PPC_STORE_U32(ctx.r31.u32 + 908, ctx.r23.u32);
	// clrlwi r10,r10,20
	ctx.r10.u64 = ctx.r10.u32 & 0xFFF;
	// ori r11,r11,32464
	ctx.r11.u64 = ctx.r11.u64 | 32464;
	// rlwinm r10,r10,0,26,21
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFC3F;
	// li r22,3
	ctx.r22.s64 = 3;
	// stw r11,912(r31)
	PPC_STORE_U32(ctx.r31.u32 + 912, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x88110a9c
	if (ctx.cr6.eq) goto loc_88110A9C;
	// lwz r10,916(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 916);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r8,916(r31)
	PPC_STORE_U32(ctx.r31.u32 + 916, ctx.r8.u32);
	// beq cr6,0x88110ad4
	if (ctx.cr6.eq) goto loc_88110AD4;
	// lis r10,255
	ctx.r10.s64 = 16711680;
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// ori r8,r10,12336
	ctx.r8.u64 = ctx.r10.u64 | 12336;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r8,912(r31)
	PPC_STORE_U32(ctx.r31.u32 + 912, ctx.r8.u32);
	// beq cr6,0x88110a94
	if (ctx.cr6.eq) goto loc_88110A94;
	// stw r11,912(r31)
	PPC_STORE_U32(ctx.r31.u32 + 912, ctx.r11.u32);
loc_88110A94:
	// stw r22,908(r31)
	PPC_STORE_U32(ctx.r31.u32 + 908, ctx.r22.u32);
	// b 0x88110ad4
	goto loc_88110AD4;
loc_88110A9C:
	// lwz r11,892(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 892);
	// lwz r10,884(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 884);
	// srawi r9,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 2;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// cmpw cr6,r10,r8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, ctx.xer);
	// bge cr6,0x88110ad4
	if (!ctx.cr6.lt) goto loc_88110AD4;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26428(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26428);
	// rlwinm r10,r11,0,28,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xE;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x88110ad4
	if (!ctx.cr6.eq) goto loc_88110AD4;
	// lis r11,255
	ctx.r11.s64 = 16711680;
	// ori r10,r11,4112
	ctx.r10.u64 = ctx.r11.u64 | 4112;
	// stw r10,912(r31)
	PPC_STORE_U32(ctx.r31.u32 + 912, ctx.r10.u32);
loc_88110AD4:
	// lwz r11,956(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 956);
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// lis r9,-30679
	ctx.r9.s64 = -2010578944;
	// li r20,2
	ctx.r20.s64 = 2;
	// li r15,8
	ctx.r15.s64 = 8;
	// lis r19,-30667
	ctx.r19.s64 = -2009792512;
	// lis r29,-30667
	ctx.r29.s64 = -2009792512;
	// lis r24,-30667
	ctx.r24.s64 = -2009792512;
	// lis r21,-30667
	ctx.r21.s64 = -2009792512;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// addi r14,r10,32248
	ctx.r14.s64 = ctx.r10.s64 + 32248;
	// addi r16,r9,-15272
	ctx.r16.s64 = ctx.r9.s64 + -15272;
	// beq cr6,0x88110f80
	if (ctx.cr6.eq) goto loc_88110F80;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x88110fa8
	if (ctx.cr6.eq) goto loc_88110FA8;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x88110fc0
	if (!ctx.cr6.eq) goto loc_88110FC0;
	// lwz r11,964(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 964);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,964(r31)
	PPC_STORE_U32(ctx.r31.u32 + 964, ctx.r11.u32);
	// bge 0x88110b64
	if (!ctx.cr0.lt) goto loc_88110B64;
	// lwz r11,968(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 968);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,964(r31)
	PPC_STORE_U32(ctx.r31.u32 + 964, ctx.r11.u32);
	// bl 0x881534c8
	ctx.lr = 0x88110B38;
	sub_881534C8(ctx, base);
	// extsh r10,r3
	ctx.r10.s64 = ctx.r3.s16;
	// li r6,33
	ctx.r6.s64 = 33;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// li r3,5
	ctx.r3.s64 = 5;
	// beq cr6,0x88110b58
	if (ctx.cr6.eq) goto loc_88110B58;
	// li r5,30
	ctx.r5.s64 = 30;
	// li r4,91
	ctx.r4.s64 = 91;
	// b 0x88110b60
	goto loc_88110B60;
loc_88110B58:
	// li r5,50
	ctx.r5.s64 = 50;
	// li r4,94
	ctx.r4.s64 = 94;
loc_88110B60:
	// bl 0x880e32d0
	ctx.lr = 0x88110B64;
	sub_880E32D0(ctx, base);
loc_88110B64:
	// lhz r11,900(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 900);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// sth r9,900(r31)
	PPC_STORE_U16(ctx.r31.u32 + 900, ctx.r9.u16);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge cr6,0x88110fc0
	if (!ctx.cr6.lt) goto loc_88110FC0;
	// lwz r11,896(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 896);
	// addi r9,r16,-31288
	ctx.r9.s64 = ctx.r16.s64 + -31288;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r3,8
	ctx.r3.s64 = 8;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r6,8(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r4,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// add r30,r11,r9
	ctx.r30.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r11,24(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// sth r11,900(r31)
	PPC_STORE_U16(ctx.r31.u32 + 900, ctx.r11.u16);
	// lwz r7,8(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r9,184(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 184);
	// lwz r11,168(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 168);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r27,r7,r8
	ctx.r27.u64 = ctx.r7.u64 + ctx.r8.u64;
	// add r26,r10,r6
	ctx.r26.u64 = ctx.r10.u64 + ctx.r6.u64;
	// addi r28,r11,5
	ctx.r28.s64 = ctx.r11.s64 + 5;
	// bl 0x881534c8
	ctx.lr = 0x88110BD0;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,7
	ctx.r3.s64 = 7;
	// addi r9,r11,-4
	ctx.r9.s64 = ctx.r11.s64 + -4;
	// rlwinm r11,r9,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
	// stw r11,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r11.u32);
	// bl 0x881534c8
	ctx.lr = 0x88110BEC;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r8,r11,-4
	ctx.r8.s64 = ctx.r11.s64 + -4;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// rlwinm r11,r8,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// li r3,36
	ctx.r3.s64 = 36;
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// stw r11,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r11.u32);
	// bl 0x880f34b0
	ctx.lr = 0x88110C10;
	sub_880F34B0(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// li r3,63
	ctx.r3.s64 = 63;
	// bl 0x881534c8
	ctx.lr = 0x88110C1C;
	sub_881534C8(ctx, base);
	// extsh r7,r3
	ctx.r7.s64 = ctx.r3.s16;
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// rlwinm r11,r7,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// beq cr6,0x88110c30
	if (ctx.cr6.eq) goto loc_88110C30;
	// sth r11,26(r25)
	PPC_STORE_U16(ctx.r25.u32 + 26, ctx.r11.u16);
loc_88110C30:
	// stw r27,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r27.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// stw r26,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r26.u32);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// stw r28,12376(r19)
	PPC_STORE_U32(ctx.r19.u32 + 12376, ctx.r28.u32);
	// stw r3,12380(r21)
	PPC_STORE_U32(ctx.r21.u32 + 12380, ctx.r3.u32);
	// bl 0x880f52c8
	ctx.lr = 0x88110C4C;
	sub_880F52C8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88110c60
	if (ctx.cr6.eq) goto loc_88110C60;
	// li r11,192
	ctx.r11.s64 = 192;
	// stw r11,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r11.u32);
loc_88110C60:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r5,20(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// lwz r4,16(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// bl 0x880f5570
	ctx.lr = 0x88110C70;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x88110c94
	if (ctx.cr6.eq) goto loc_88110C94;
	// lwz r11,36(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// stw r11,148(r28)
	PPC_STORE_U32(ctx.r28.u32 + 148, ctx.r11.u32);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// clrlwi r9,r10,16
	ctx.r9.u64 = ctx.r10.u32 & 0xFFFF;
	// stw r9,100(r28)
	PPC_STORE_U32(ctx.r28.u32 + 100, ctx.r9.u32);
	// lwz r8,924(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 924);
	// stw r8,144(r28)
	PPC_STORE_U32(ctx.r28.u32 + 144, ctx.r8.u32);
loc_88110C94:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r6,940(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 940);
	// lwz r5,936(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 936);
	// lwz r8,2332(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2332);
	// lwz r7,2328(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2328);
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// bl 0x880f5438
	ctx.lr = 0x88110CB4;
	sub_880F5438(ctx, base);
	// lwz r11,896(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 896);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,896(r31)
	PPC_STORE_U32(ctx.r31.u32 + 896, ctx.r11.u32);
	// cmpwi cr6,r11,24
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 24, ctx.xer);
	// bne cr6,0x88110ce0
	if (!ctx.cr6.eq) goto loc_88110CE0;
	// lwz r9,20(r16)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r16.u32 + 20);
	// li r10,5
	ctx.r10.s64 = 5;
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
	// stw r23,4(r14)
	PPC_STORE_U32(ctx.r14.u32 + 4, ctx.r23.u32);
	// stw r10,0(r14)
	PPC_STORE_U32(ctx.r14.u32 + 0, ctx.r10.u32);
	// stw r9,16(r14)
	PPC_STORE_U32(ctx.r14.u32 + 16, ctx.r9.u32);
loc_88110CE0:
	// lwz r11,896(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 896);
	// cmpwi cr6,r11,31
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 31, ctx.xer);
	// blt cr6,0x88110fc0
	if (ctx.cr6.lt) goto loc_88110FC0;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r10,12
	ctx.r10.s64 = 12;
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// stw r10,12380(r21)
	PPC_STORE_U32(ctx.r21.u32 + 12380, ctx.r10.u32);
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// stw r9,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r9.u32);
	// stw r8,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r8.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// blt cr6,0x88110d20
	if (ctx.cr6.lt) goto loc_88110D20;
	// lwz r11,192(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 192);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x88110d2c
	goto loc_88110D2C;
loc_88110D20:
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 184);
	// lwz r11,168(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 168);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_88110D2C:
	// addi r4,r11,-2
	ctx.r4.s64 = ctx.r11.s64 + -2;
	// li r3,12
	ctx.r3.s64 = 12;
	// stw r4,12376(r19)
	PPC_STORE_U32(ctx.r19.u32 + 12376, ctx.r4.u32);
	// bl 0x880f8798
	ctx.lr = 0x88110D3C;
	sub_880F8798(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88110d4c
	if (ctx.cr6.eq) goto loc_88110D4C;
	// lwz r11,924(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 924);
	// stb r11,24(r3)
	PPC_STORE_U8(ctx.r3.u32 + 24, ctx.r11.u8);
loc_88110D4C:
	// lwz r11,904(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 904);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r20,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r20.u32);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// stw r10,956(r31)
	PPC_STORE_U32(ctx.r31.u32 + 956, ctx.r10.u32);
	// bne cr6,0x88110e78
	if (!ctx.cr6.eq) goto loc_88110E78;
	// lwz r11,936(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 936);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88110fc0
	if (!ctx.cr6.eq) goto loc_88110FC0;
	// lwz r25,4(r31)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r27,8(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r3,3
	ctx.r3.s64 = 3;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r25,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r25.u32);
	// stw r27,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r27.u32);
	// lwz r11,184(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 184);
	// lwz r10,168(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 168);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r28,r11,-1
	ctx.r28.s64 = ctx.r11.s64 + -1;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x881607f8
	ctx.lr = 0x88110DA4;
	sub_881607F8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88110db4
	if (ctx.cr6.eq) goto loc_88110DB4;
	// lwz r11,924(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 924);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
loc_88110DB4:
	// lis r30,19
	ctx.r30.s64 = 1245184;
	// li r5,0
	ctx.r5.s64 = 0;
	// subf r26,r30,r25
	ctx.r26.s64 = ctx.r25.s64 - ctx.r30.s64;
	// add r23,r27,r30
	ctx.r23.u64 = ctx.r27.u64 + ctx.r30.u64;
	// stw r26,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r26.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// stw r23,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r23.u32);
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x881607f8
	ctx.lr = 0x88110DD8;
	sub_881607F8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88110de8
	if (ctx.cr6.eq) goto loc_88110DE8;
	// lwz r11,924(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 924);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
loc_88110DE8:
	// subf r27,r30,r27
	ctx.r27.s64 = ctx.r27.s64 - ctx.r30.s64;
	// stw r26,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r26.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r27,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r27.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x881607f8
	ctx.lr = 0x88110E04;
	sub_881607F8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88110e14
	if (ctx.cr6.eq) goto loc_88110E14;
	// lwz r11,924(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 924);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
loc_88110E14:
	// add r30,r25,r30
	ctx.r30.u64 = ctx.r25.u64 + ctx.r30.u64;
	// stw r23,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r23.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r30,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r30.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x881607f8
	ctx.lr = 0x88110E30;
	sub_881607F8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88110e40
	if (ctx.cr6.eq) goto loc_88110E40;
	// lwz r11,924(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 924);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
loc_88110E40:
	// stw r30,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r30.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r27,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r27.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r3,3
	ctx.r3.s64 = 3;
	// stw r22,12380(r21)
	PPC_STORE_U32(ctx.r21.u32 + 12380, ctx.r22.u32);
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// stw r28,12376(r19)
	PPC_STORE_U32(ctx.r19.u32 + 12376, ctx.r28.u32);
	// bl 0x881607f8
	ctx.lr = 0x88110E64;
	sub_881607F8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88110fc0
	if (ctx.cr6.eq) goto loc_88110FC0;
	// lwz r11,924(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 924);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// b 0x88110fc0
	goto loc_88110FC0;
loc_88110E78:
	// lwz r25,4(r31)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r27,8(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r3,3
	ctx.r3.s64 = 3;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r25,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r25.u32);
	// stw r27,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r27.u32);
	// lwz r11,184(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 184);
	// lwz r10,168(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 168);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r28,r11,-1
	ctx.r28.s64 = ctx.r11.s64 + -1;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x881607f8
	ctx.lr = 0x88110EAC;
	sub_881607F8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88110ebc
	if (ctx.cr6.eq) goto loc_88110EBC;
	// lwz r11,924(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 924);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
loc_88110EBC:
	// lis r30,19
	ctx.r30.s64 = 1245184;
	// li r5,0
	ctx.r5.s64 = 0;
	// subf r26,r30,r25
	ctx.r26.s64 = ctx.r25.s64 - ctx.r30.s64;
	// add r23,r27,r30
	ctx.r23.u64 = ctx.r27.u64 + ctx.r30.u64;
	// stw r26,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r26.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// stw r23,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r23.u32);
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x881607f8
	ctx.lr = 0x88110EE0;
	sub_881607F8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88110ef0
	if (ctx.cr6.eq) goto loc_88110EF0;
	// lwz r11,924(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 924);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
loc_88110EF0:
	// subf r27,r30,r27
	ctx.r27.s64 = ctx.r27.s64 - ctx.r30.s64;
	// stw r26,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r26.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r27,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r27.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x881607f8
	ctx.lr = 0x88110F0C;
	sub_881607F8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88110f1c
	if (ctx.cr6.eq) goto loc_88110F1C;
	// lwz r11,924(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 924);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
loc_88110F1C:
	// add r30,r25,r30
	ctx.r30.u64 = ctx.r25.u64 + ctx.r30.u64;
	// stw r23,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r23.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r30,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r30.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x881607f8
	ctx.lr = 0x88110F38;
	sub_881607F8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88110f48
	if (ctx.cr6.eq) goto loc_88110F48;
	// lwz r11,924(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 924);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
loc_88110F48:
	// stw r30,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r30.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r27,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r27.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r3,3
	ctx.r3.s64 = 3;
	// stw r22,12380(r21)
	PPC_STORE_U32(ctx.r21.u32 + 12380, ctx.r22.u32);
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// stw r28,12376(r19)
	PPC_STORE_U32(ctx.r19.u32 + 12376, ctx.r28.u32);
	// bl 0x881607f8
	ctx.lr = 0x88110F6C;
	sub_881607F8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88110fc0
	if (ctx.cr6.eq) goto loc_88110FC0;
	// lwz r11,924(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 924);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// b 0x88110fc0
	goto loc_88110FC0;
loc_88110F80:
	// li r11,32
	ctx.r11.s64 = 32;
	// stw r20,956(r31)
	PPC_STORE_U32(ctx.r31.u32 + 956, ctx.r20.u32);
	// stw r23,964(r31)
	PPC_STORE_U32(ctx.r31.u32 + 964, ctx.r23.u32);
	// li r6,34
	ctx.r6.s64 = 34;
	// stw r11,960(r31)
	PPC_STORE_U32(ctx.r31.u32 + 960, ctx.r11.u32);
	// li r5,70
	ctx.r5.s64 = 70;
	// stw r15,968(r31)
	PPC_STORE_U32(ctx.r31.u32 + 968, ctx.r15.u32);
	// li r4,92
	ctx.r4.s64 = 92;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x880e32d0
	ctx.lr = 0x88110FA8;
	sub_880E32D0(ctx, base);
loc_88110FA8:
	// lwz r11,960(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 960);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,960(r31)
	PPC_STORE_U32(ctx.r31.u32 + 960, ctx.r11.u32);
	// bge 0x88110fc0
	if (!ctx.cr0.lt) goto loc_88110FC0;
	// stw r23,960(r31)
	PPC_STORE_U32(ctx.r31.u32 + 960, ctx.r23.u32);
	// stw r22,956(r31)
	PPC_STORE_U32(ctx.r31.u32 + 956, ctx.r22.u32);
loc_88110FC0:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// li r20,1
	ctx.r20.s64 = 1;
	// li r17,16
	ctx.r17.s64 = 16;
	// lis r18,-30633
	ctx.r18.s64 = -2007564288;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x88111038
	if (ctx.cr6.lt) goto loc_88111038;
	// beq cr6,0x88110ff0
	if (ctx.cr6.eq) goto loc_88110FF0;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x88111228
	if (!ctx.cr6.lt) goto loc_88111228;
	// mr r11,r20
	ctx.r11.u64 = ctx.r20.u64;
	// stw r20,-29740(r18)
	PPC_STORE_U32(ctx.r18.u32 + -29740, ctx.r20.u32);
	// b 0x88111228
	goto loc_88111228;
loc_88110FF0:
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// mr r11,r20
	ctx.r11.u64 = ctx.r20.u64;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addis r11,r9,2
	ctx.r11.s64 = ctx.r9.s64 + 131072;
	// stw r20,-29740(r18)
	PPC_STORE_U32(ctx.r18.u32 + -29740, ctx.r20.u32);
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r8,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r8.u32);
	// blt 0x88111228
	if (ctx.cr0.lt) goto loc_88111228;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r20,828(r31)
	PPC_STORE_U32(ctx.r31.u32 + 828, ctx.r20.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r17,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r17.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stw r10,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// stw r15,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r15.u32);
	// b 0x88111228
	goto loc_88111228;
loc_88111038:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8811105c
	if (ctx.cr6.eq) goto loc_8811105C;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// bgt 0x88111228
	if (ctx.cr0.gt) goto loc_88111228;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// b 0x88111228
	goto loc_88111228;
loc_8811105C:
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r9,r11,-8192
	ctx.r9.s64 = ctx.r11.s64 + -8192;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r9,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
	// rotlwi r7,r8,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// stw r8,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r8.u32);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bgt cr6,0x88111228
	if (ctx.cr6.gt) goto loc_88111228;
	// lwz r10,952(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 952);
	// li r26,0
	ctx.r26.s64 = 0;
	// stw r20,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r20.u32);
	// lis r22,16
	ctx.r22.s64 = 1048576;
	// stw r26,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r26.u32);
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// stw r20,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r20.u32);
	// stw r20,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r20.u32);
	// stw r20,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r20.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r26,12380(r21)
	PPC_STORE_U32(ctx.r21.u32 + 12380, ctx.r26.u32);
	// li r21,255
	ctx.r21.s64 = 255;
	// lwz r25,4(r31)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// add r10,r9,r22
	ctx.r10.u64 = ctx.r9.u64 + ctx.r22.u64;
	// stw r10,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r10.u32);
	// lwz r11,184(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 184);
	// lwz r10,168(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 168);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r27,r11,4
	ctx.r27.s64 = ctx.r11.s64 + 4;
	// lis r11,64
	ctx.r11.s64 = 4194304;
	// addi r28,r27,2
	ctx.r28.s64 = ctx.r27.s64 + 2;
	// ori r23,r11,16639
	ctx.r23.u64 = ctx.r11.u64 | 16639;
	// stw r28,12376(r19)
	PPC_STORE_U32(ctx.r19.u32 + 12376, ctx.r28.u32);
	// li r19,4
	ctx.r19.s64 = 4;
loc_881110E4:
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x881534c8
	ctx.lr = 0x881110EC;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r11,r11,-8
	ctx.r11.s64 = ctx.r11.s64 + -8;
	// li r3,0
	ctx.r3.s64 = 0;
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r25
	ctx.r11.u64 = ctx.r11.u64 + ctx.r25.u64;
	// stw r11,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r11.u32);
	// bl 0x880f52c8
	ctx.lr = 0x8811110C;
	sub_880F52C8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88111120
	if (ctx.cr6.eq) goto loc_88111120;
	// lwz r11,924(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 924);
	// stw r11,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r11.u32);
loc_88111120:
	// clrlwi r11,r26,31
	ctx.r11.u64 = ctx.r26.u32 & 0x1;
	// li r3,32
	ctx.r3.s64 = 32;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88111158
	if (ctx.cr6.eq) goto loc_88111158;
	// bl 0x881534c8
	ctx.lr = 0x88111134;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,64
	ctx.r3.s64 = 64;
	// addi r29,r11,24
	ctx.r29.s64 = ctx.r11.s64 + 24;
	// bl 0x881534c8
	ctx.lr = 0x88111144;
	sub_881534C8(ctx, base);
	// clrlwi r5,r3,23
	ctx.r5.u64 = ctx.r3.u32 & 0x1FF;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880f5570
	ctx.lr = 0x88111154;
	sub_880F5570(ctx, base);
	// b 0x88111190
	goto loc_88111190;
loc_88111158:
	// bl 0x881534c8
	ctx.lr = 0x8811115C;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,64
	ctx.r3.s64 = 64;
	// addi r29,r11,24
	ctx.r29.s64 = ctx.r11.s64 + 24;
	// bl 0x881534c8
	ctx.lr = 0x8811116C;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// neg r10,r11
	ctx.r10.s64 = -ctx.r11.s64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// clrlwi r5,r10,23
	ctx.r5.u64 = ctx.r10.u32 & 0x1FF;
	// bl 0x880f5570
	ctx.lr = 0x88111184;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x881111ac
	if (ctx.cr6.eq) goto loc_881111AC;
	// stw r20,148(r30)
	PPC_STORE_U32(ctx.r30.u32 + 148, ctx.r20.u32);
loc_88111190:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x881111ac
	if (ctx.cr6.eq) goto loc_881111AC;
	// rlwinm r11,r26,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r21,140(r30)
	PPC_STORE_U32(ctx.r30.u32 + 140, ctx.r21.u32);
	// stw r19,100(r30)
	PPC_STORE_U32(ctx.r30.u32 + 100, ctx.r19.u32);
	// stw r11,112(r30)
	PPC_STORE_U32(ctx.r30.u32 + 112, ctx.r11.u32);
	// stw r23,160(r30)
	PPC_STORE_U32(ctx.r30.u32 + 160, ctx.r23.u32);
loc_881111AC:
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// cmpwi cr6,r26,4
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 4, ctx.xer);
	// blt cr6,0x881110e4
	if (ctx.cr6.lt) goto loc_881110E4;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r3,r16,-31648
	ctx.r3.s64 = ctx.r16.s64 + -31648;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r6,r27,-3
	ctx.r6.s64 = ctx.r27.s64 + -3;
	// add r9,r11,r22
	ctx.r9.u64 = ctx.r11.u64 + ctx.r22.u64;
	// lwz r7,924(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 924);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// li r4,3
	ctx.r4.s64 = 3;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x88110190
	ctx.lr = 0x881111E4;
	sub_88110190(ctx, base);
	// addi r3,r16,-31504
	ctx.r3.s64 = ctx.r16.s64 + -31504;
	// addi r6,r27,1
	ctx.r6.s64 = ctx.r27.s64 + 1;
	// lwz r7,924(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 924);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x88110190
	ctx.lr = 0x881111FC;
	sub_88110190(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,6
	ctx.r10.s64 = 6;
	// stw r11,4(r14)
	PPC_STORE_U32(ctx.r14.u32 + 4, ctx.r11.u32);
	// li r6,50
	ctx.r6.s64 = 50;
	// li r5,72
	ctx.r5.s64 = 72;
	// stw r10,0(r14)
	PPC_STORE_U32(ctx.r14.u32 + 0, ctx.r10.u32);
	// li r4,126
	ctx.r4.s64 = 126;
	// li r3,6
	ctx.r3.s64 = 6;
	// lwz r11,24(r16)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r16.u32 + 24);
	// stw r11,16(r14)
	PPC_STORE_U32(ctx.r14.u32 + 16, ctx.r11.u32);
	// bl 0x880e32d0
	ctx.lr = 0x88111228;
	sub_880E32D0(ctx, base);
loc_88111228:
	// addi r5,r31,4
	ctx.r5.s64 = ctx.r31.s64 + 4;
	// lwz r3,924(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 924);
	// addi r23,r31,8
	ctx.r23.s64 = ctx.r31.s64 + 8;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// bl 0x880940d8
	ctx.lr = 0x88111240;
	sub_880940D8(ctx, base);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8811126c
	if (ctx.cr6.eq) goto loc_8811126C;
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8811126c
	if (ctx.cr6.eq) goto loc_8811126C;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// bgt 0x8811126c
	if (ctx.cr0.gt) goto loc_8811126C;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
loc_8811126C:
	// lis r11,16838
	ctx.r11.s64 = 1103495168;
	// lwz r22,324(r1)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 324);
	// lis r10,15887
	ctx.r10.s64 = 1041170432;
	// addi r29,r31,60
	ctx.r29.s64 = ctx.r31.s64 + 60;
	// li r24,15
	ctx.r24.s64 = 15;
	// ori r27,r11,20077
	ctx.r27.u64 = ctx.r11.u64 | 20077;
	// ori r28,r10,33761
	ctx.r28.u64 = ctx.r10.u64 | 33761;
	// lis r30,-30671
	ctx.r30.s64 = -2010054656;
	// li r19,4
	ctx.r19.s64 = 4;
	// li r21,0
	ctx.r21.s64 = 0;
loc_88111294:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88111384
	if (ctx.cr6.eq) goto loc_88111384;
	// addi r26,r29,4
	ctx.r26.s64 = ctx.r29.s64 + 4;
	// lwz r3,924(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 924);
	// addi r25,r29,8
	ctx.r25.s64 = ctx.r29.s64 + 8;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x880940d8
	ctx.lr = 0x881112BC;
	sub_880940D8(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88111384
	if (ctx.cr6.eq) goto loc_88111384;
	// lwz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r11.u32);
	// bgt 0x88111384
	if (ctx.cr0.gt) goto loc_88111384;
	// lwz r11,4200(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4200);
	// lwz r10,184(r22)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r22.u32 + 184);
	// mullw r11,r11,r27
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r27.s32);
	// lwz r9,168(r22)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r22.u32 + 168);
	// lwz r8,48(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r11,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r11.u32);
	// clrlwi r6,r8,31
	ctx.r6.u64 = ctx.r8.u32 & 0x1;
	// stw r7,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r7.u32);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// lhz r5,4200(r30)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4200);
	// mulhwu r4,r5,r28
	ctx.r4.u64 = (uint64_t(ctx.r5.u32) * uint64_t(ctx.r28.u32)) >> 32;
	// rlwinm r11,r4,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 29) & 0x1FFFFFFF;
	// rlwinm r10,r11,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r11,r3,r5
	ctx.r11.s64 = ctx.r5.s64 - ctx.r3.s64;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// addi r9,r11,176
	ctx.r9.s64 = ctx.r11.s64 + 176;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r8,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// beq cr6,0x88111348
	if (ctx.cr6.eq) goto loc_88111348;
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x881534c8
	ctx.lr = 0x88111338;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// addi r11,r11,48
	ctx.r11.s64 = ctx.r11.s64 + 48;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
loc_88111348:
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stw r24,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r24.u32);
	// li r3,240
	ctx.r3.s64 = 240;
	// stw r20,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r20.u32);
	// stw r19,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r19.u32);
	// stw r22,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r22.u32);
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r11.u32);
	// lwz r5,0(r25)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r4,0(r26)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// bl 0x880958a0
	ctx.lr = 0x88111374;
	sub_880958A0(ctx, base);
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// stw r21,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r21.u32);
loc_88111384:
	// addi r24,r24,-1
	ctx.r24.s64 = ctx.r24.s64 + -1;
	// addi r29,r29,48
	ctx.r29.s64 = ctx.r29.s64 + 48;
	// cmpwi cr6,r24,-1
	ctx.cr6.compare<int32_t>(ctx.r24.s32, -1, ctx.xer);
	// bgt cr6,0x88111294
	if (ctx.cr6.gt) goto loc_88111294;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r9,-256
	ctx.r9.s64 = -16777216;
	// lwz r10,0(r23)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r23.u32 + 0);
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// bgt cr6,0x881113d8
	if (ctx.cr6.gt) goto loc_881113D8;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r17,932(r31)
	PPC_STORE_U32(ctx.r31.u32 + 932, ctx.r17.u32);
	// mr r11,r21
	ctx.r11.u64 = ctx.r21.u64;
	// stw r9,928(r31)
	PPC_STORE_U32(ctx.r31.u32 + 928, ctx.r9.u32);
	// stw r21,-29740(r18)
	PPC_STORE_U32(ctx.r18.u32 + -29740, ctx.r21.u32);
	// stw r21,68(r10)
	PPC_STORE_U32(ctx.r10.u32 + 68, ctx.r21.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r21,72(r8)
	PPC_STORE_U32(ctx.r8.u32 + 72, ctx.r21.u32);
	// lwz r7,952(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 952);
	// stw r21,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r21.u32);
loc_881113D8:
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88110BF8"))) PPC_WEAK_FUNC(sub_88110BF8);
PPC_FUNC_IMPL(__imp__sub_88110BF8) {
	PPC_FUNC_PROLOGUE();
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// rlwinm r11,r8,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// li r3,36
	ctx.r3.s64 = 36;
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// stw r11,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r11.u32);
	// bl 0x880f34b0
	ctx.lr = 0x88110C10;
	sub_880F34B0(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// li r3,63
	ctx.r3.s64 = 63;
	// bl 0x881534c8
	ctx.lr = 0x88110C1C;
	sub_881534C8(ctx, base);
	// extsh r7,r3
	ctx.r7.s64 = ctx.r3.s16;
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// rlwinm r11,r7,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// beq cr6,0x88110c30
	if (ctx.cr6.eq) goto loc_88110C30;
	// sth r11,26(r25)
	PPC_STORE_U16(ctx.r25.u32 + 26, ctx.r11.u16);
loc_88110C30:
	// stw r27,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r27.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// stw r26,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r26.u32);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// stw r28,12376(r19)
	PPC_STORE_U32(ctx.r19.u32 + 12376, ctx.r28.u32);
	// stw r3,12380(r21)
	PPC_STORE_U32(ctx.r21.u32 + 12380, ctx.r3.u32);
	// bl 0x880f52c8
	ctx.lr = 0x88110C4C;
	sub_880F52C8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88110c60
	if (ctx.cr6.eq) goto loc_88110C60;
	// li r11,192
	ctx.r11.s64 = 192;
	// stw r11,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r11.u32);
loc_88110C60:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r5,20(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// lwz r4,16(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// bl 0x880f5570
	ctx.lr = 0x88110C70;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x88110c94
	if (ctx.cr6.eq) goto loc_88110C94;
	// lwz r11,36(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// stw r11,148(r28)
	PPC_STORE_U32(ctx.r28.u32 + 148, ctx.r11.u32);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// clrlwi r9,r10,16
	ctx.r9.u64 = ctx.r10.u32 & 0xFFFF;
	// stw r9,100(r28)
	PPC_STORE_U32(ctx.r28.u32 + 100, ctx.r9.u32);
	// lwz r8,924(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 924);
	// stw r8,144(r28)
	PPC_STORE_U32(ctx.r28.u32 + 144, ctx.r8.u32);
loc_88110C94:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r6,940(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 940);
	// lwz r5,936(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 936);
	// lwz r8,2332(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2332);
	// lwz r7,2328(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2328);
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// bl 0x880f5438
	ctx.lr = 0x88110CB4;
	sub_880F5438(ctx, base);
	// lwz r11,896(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 896);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,896(r31)
	PPC_STORE_U32(ctx.r31.u32 + 896, ctx.r11.u32);
	// cmpwi cr6,r11,24
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 24, ctx.xer);
	// bne cr6,0x88110ce0
	if (!ctx.cr6.eq) goto loc_88110CE0;
	// lwz r9,20(r16)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r16.u32 + 20);
	// li r10,5
	ctx.r10.s64 = 5;
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
	// stw r23,4(r14)
	PPC_STORE_U32(ctx.r14.u32 + 4, ctx.r23.u32);
	// stw r10,0(r14)
	PPC_STORE_U32(ctx.r14.u32 + 0, ctx.r10.u32);
	// stw r9,16(r14)
	PPC_STORE_U32(ctx.r14.u32 + 16, ctx.r9.u32);
loc_88110CE0:
	// lwz r11,896(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 896);
	// cmpwi cr6,r11,31
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 31, ctx.xer);
	// blt cr6,0x88110fc0
	if (ctx.cr6.lt) goto loc_88110FC0;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r10,12
	ctx.r10.s64 = 12;
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// stw r10,12380(r21)
	PPC_STORE_U32(ctx.r21.u32 + 12380, ctx.r10.u32);
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// stw r9,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r9.u32);
	// stw r8,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r8.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// blt cr6,0x88110d20
	if (ctx.cr6.lt) goto loc_88110D20;
	// lwz r11,192(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 192);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x88110d2c
	goto loc_88110D2C;
loc_88110D20:
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 184);
	// lwz r11,168(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 168);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_88110D2C:
	// addi r4,r11,-2
	ctx.r4.s64 = ctx.r11.s64 + -2;
	// li r3,12
	ctx.r3.s64 = 12;
	// stw r4,12376(r19)
	PPC_STORE_U32(ctx.r19.u32 + 12376, ctx.r4.u32);
	// bl 0x880f8798
	ctx.lr = 0x88110D3C;
	sub_880F8798(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88110d4c
	if (ctx.cr6.eq) goto loc_88110D4C;
	// lwz r11,924(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 924);
	// stb r11,24(r3)
	PPC_STORE_U8(ctx.r3.u32 + 24, ctx.r11.u8);
loc_88110D4C:
	// lwz r11,904(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 904);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r20,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r20.u32);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// stw r10,956(r31)
	PPC_STORE_U32(ctx.r31.u32 + 956, ctx.r10.u32);
	// bne cr6,0x88110e78
	if (!ctx.cr6.eq) goto loc_88110E78;
	// lwz r11,936(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 936);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88110fc0
	if (!ctx.cr6.eq) goto loc_88110FC0;
	// lwz r25,4(r31)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r27,8(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r3,3
	ctx.r3.s64 = 3;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r25,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r25.u32);
	// stw r27,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r27.u32);
	// lwz r11,184(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 184);
	// lwz r10,168(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 168);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r28,r11,-1
	ctx.r28.s64 = ctx.r11.s64 + -1;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x881607f8
	ctx.lr = 0x88110DA4;
	sub_881607F8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88110db4
	if (ctx.cr6.eq) goto loc_88110DB4;
	// lwz r11,924(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 924);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
loc_88110DB4:
	// lis r30,19
	ctx.r30.s64 = 1245184;
	// li r5,0
	ctx.r5.s64 = 0;
	// subf r26,r30,r25
	ctx.r26.s64 = ctx.r25.s64 - ctx.r30.s64;
	// add r23,r27,r30
	ctx.r23.u64 = ctx.r27.u64 + ctx.r30.u64;
	// stw r26,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r26.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// stw r23,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r23.u32);
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x881607f8
	ctx.lr = 0x88110DD8;
	sub_881607F8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88110de8
	if (ctx.cr6.eq) goto loc_88110DE8;
	// lwz r11,924(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 924);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
loc_88110DE8:
	// subf r27,r30,r27
	ctx.r27.s64 = ctx.r27.s64 - ctx.r30.s64;
	// stw r26,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r26.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r27,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r27.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x881607f8
	ctx.lr = 0x88110E04;
	sub_881607F8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88110e14
	if (ctx.cr6.eq) goto loc_88110E14;
	// lwz r11,924(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 924);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
loc_88110E14:
	// add r30,r25,r30
	ctx.r30.u64 = ctx.r25.u64 + ctx.r30.u64;
	// stw r23,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r23.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r30,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r30.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x881607f8
	ctx.lr = 0x88110E30;
	sub_881607F8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88110e40
	if (ctx.cr6.eq) goto loc_88110E40;
	// lwz r11,924(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 924);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
loc_88110E40:
	// stw r30,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r30.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r27,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r27.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r3,3
	ctx.r3.s64 = 3;
	// stw r22,12380(r21)
	PPC_STORE_U32(ctx.r21.u32 + 12380, ctx.r22.u32);
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// stw r28,12376(r19)
	PPC_STORE_U32(ctx.r19.u32 + 12376, ctx.r28.u32);
	// bl 0x881607f8
	ctx.lr = 0x88110E64;
	sub_881607F8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88110fc0
	if (ctx.cr6.eq) goto loc_88110FC0;
	// lwz r11,924(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 924);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// b 0x88110fc0
	goto loc_88110FC0;
loc_88110E78:
	// lwz r25,4(r31)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r27,8(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r3,3
	ctx.r3.s64 = 3;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r25,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r25.u32);
	// stw r27,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r27.u32);
	// lwz r11,184(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 184);
	// lwz r10,168(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 168);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r28,r11,-1
	ctx.r28.s64 = ctx.r11.s64 + -1;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x881607f8
	ctx.lr = 0x88110EAC;
	sub_881607F8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88110ebc
	if (ctx.cr6.eq) goto loc_88110EBC;
	// lwz r11,924(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 924);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
loc_88110EBC:
	// lis r30,19
	ctx.r30.s64 = 1245184;
	// li r5,0
	ctx.r5.s64 = 0;
	// subf r26,r30,r25
	ctx.r26.s64 = ctx.r25.s64 - ctx.r30.s64;
	// add r23,r27,r30
	ctx.r23.u64 = ctx.r27.u64 + ctx.r30.u64;
	// stw r26,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r26.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// stw r23,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r23.u32);
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x881607f8
	ctx.lr = 0x88110EE0;
	sub_881607F8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88110ef0
	if (ctx.cr6.eq) goto loc_88110EF0;
	// lwz r11,924(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 924);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
loc_88110EF0:
	// subf r27,r30,r27
	ctx.r27.s64 = ctx.r27.s64 - ctx.r30.s64;
	// stw r26,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r26.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r27,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r27.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x881607f8
	ctx.lr = 0x88110F0C;
	sub_881607F8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88110f1c
	if (ctx.cr6.eq) goto loc_88110F1C;
	// lwz r11,924(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 924);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
loc_88110F1C:
	// add r30,r25,r30
	ctx.r30.u64 = ctx.r25.u64 + ctx.r30.u64;
	// stw r23,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r23.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r30,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r30.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x881607f8
	ctx.lr = 0x88110F38;
	sub_881607F8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88110f48
	if (ctx.cr6.eq) goto loc_88110F48;
	// lwz r11,924(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 924);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
loc_88110F48:
	// stw r30,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r30.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r27,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r27.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r3,3
	ctx.r3.s64 = 3;
	// stw r22,12380(r21)
	PPC_STORE_U32(ctx.r21.u32 + 12380, ctx.r22.u32);
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// stw r28,12376(r19)
	PPC_STORE_U32(ctx.r19.u32 + 12376, ctx.r28.u32);
	// bl 0x881607f8
	ctx.lr = 0x88110F6C;
	sub_881607F8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88110fc0
	if (ctx.cr6.eq) goto loc_88110FC0;
	// lwz r11,924(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 924);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// b 0x88110fc0
	goto loc_88110FC0;
	// li r11,32
	ctx.r11.s64 = 32;
	// stw r20,956(r31)
	PPC_STORE_U32(ctx.r31.u32 + 956, ctx.r20.u32);
	// stw r23,964(r31)
	PPC_STORE_U32(ctx.r31.u32 + 964, ctx.r23.u32);
	// li r6,34
	ctx.r6.s64 = 34;
	// stw r11,960(r31)
	PPC_STORE_U32(ctx.r31.u32 + 960, ctx.r11.u32);
	// li r5,70
	ctx.r5.s64 = 70;
	// stw r15,968(r31)
	PPC_STORE_U32(ctx.r31.u32 + 968, ctx.r15.u32);
	// li r4,92
	ctx.r4.s64 = 92;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x880e32d0
	ctx.lr = 0x88110FA8;
	sub_880E32D0(ctx, base);
	// lwz r11,960(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 960);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,960(r31)
	PPC_STORE_U32(ctx.r31.u32 + 960, ctx.r11.u32);
	// bge 0x88110fc0
	if (!ctx.cr0.lt) goto loc_88110FC0;
	// stw r23,960(r31)
	PPC_STORE_U32(ctx.r31.u32 + 960, ctx.r23.u32);
	// stw r22,956(r31)
	PPC_STORE_U32(ctx.r31.u32 + 956, ctx.r22.u32);
loc_88110FC0:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// li r20,1
	ctx.r20.s64 = 1;
	// li r17,16
	ctx.r17.s64 = 16;
	// lis r18,-30633
	ctx.r18.s64 = -2007564288;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x88111038
	if (ctx.cr6.lt) goto loc_88111038;
	// beq cr6,0x88110ff0
	if (ctx.cr6.eq) goto loc_88110FF0;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x88111228
	if (!ctx.cr6.lt) goto loc_88111228;
	// mr r11,r20
	ctx.r11.u64 = ctx.r20.u64;
	// stw r20,-29740(r18)
	PPC_STORE_U32(ctx.r18.u32 + -29740, ctx.r20.u32);
	// b 0x88111228
	goto loc_88111228;
loc_88110FF0:
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// mr r11,r20
	ctx.r11.u64 = ctx.r20.u64;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addis r11,r9,2
	ctx.r11.s64 = ctx.r9.s64 + 131072;
	// stw r20,-29740(r18)
	PPC_STORE_U32(ctx.r18.u32 + -29740, ctx.r20.u32);
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r8,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r8.u32);
	// blt 0x88111228
	if (ctx.cr0.lt) goto loc_88111228;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r20,828(r31)
	PPC_STORE_U32(ctx.r31.u32 + 828, ctx.r20.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r17,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r17.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stw r10,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// stw r15,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r15.u32);
	// b 0x88111228
	goto loc_88111228;
loc_88111038:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8811105c
	if (ctx.cr6.eq) goto loc_8811105C;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// bgt 0x88111228
	if (ctx.cr0.gt) goto loc_88111228;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// b 0x88111228
	goto loc_88111228;
loc_8811105C:
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r9,r11,-8192
	ctx.r9.s64 = ctx.r11.s64 + -8192;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r9,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
	// rotlwi r7,r8,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// stw r8,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r8.u32);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bgt cr6,0x88111228
	if (ctx.cr6.gt) goto loc_88111228;
	// lwz r10,952(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 952);
	// li r26,0
	ctx.r26.s64 = 0;
	// stw r20,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r20.u32);
	// lis r22,16
	ctx.r22.s64 = 1048576;
	// stw r26,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r26.u32);
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// stw r20,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r20.u32);
	// stw r20,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r20.u32);
	// stw r20,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r20.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r26,12380(r21)
	PPC_STORE_U32(ctx.r21.u32 + 12380, ctx.r26.u32);
	// li r21,255
	ctx.r21.s64 = 255;
	// lwz r25,4(r31)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// add r10,r9,r22
	ctx.r10.u64 = ctx.r9.u64 + ctx.r22.u64;
	// stw r10,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r10.u32);
	// lwz r11,184(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 184);
	// lwz r10,168(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 168);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r27,r11,4
	ctx.r27.s64 = ctx.r11.s64 + 4;
	// lis r11,64
	ctx.r11.s64 = 4194304;
	// addi r28,r27,2
	ctx.r28.s64 = ctx.r27.s64 + 2;
	// ori r23,r11,16639
	ctx.r23.u64 = ctx.r11.u64 | 16639;
	// stw r28,12376(r19)
	PPC_STORE_U32(ctx.r19.u32 + 12376, ctx.r28.u32);
	// li r19,4
	ctx.r19.s64 = 4;
loc_881110E4:
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x881534c8
	ctx.lr = 0x881110EC;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r11,r11,-8
	ctx.r11.s64 = ctx.r11.s64 + -8;
	// li r3,0
	ctx.r3.s64 = 0;
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r25
	ctx.r11.u64 = ctx.r11.u64 + ctx.r25.u64;
	// stw r11,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r11.u32);
	// bl 0x880f52c8
	ctx.lr = 0x8811110C;
	sub_880F52C8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88111120
	if (ctx.cr6.eq) goto loc_88111120;
	// lwz r11,924(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 924);
	// stw r11,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r11.u32);
loc_88111120:
	// clrlwi r11,r26,31
	ctx.r11.u64 = ctx.r26.u32 & 0x1;
	// li r3,32
	ctx.r3.s64 = 32;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88111158
	if (ctx.cr6.eq) goto loc_88111158;
	// bl 0x881534c8
	ctx.lr = 0x88111134;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,64
	ctx.r3.s64 = 64;
	// addi r29,r11,24
	ctx.r29.s64 = ctx.r11.s64 + 24;
	// bl 0x881534c8
	ctx.lr = 0x88111144;
	sub_881534C8(ctx, base);
	// clrlwi r5,r3,23
	ctx.r5.u64 = ctx.r3.u32 & 0x1FF;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880f5570
	ctx.lr = 0x88111154;
	sub_880F5570(ctx, base);
	// b 0x88111190
	goto loc_88111190;
loc_88111158:
	// bl 0x881534c8
	ctx.lr = 0x8811115C;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r3,64
	ctx.r3.s64 = 64;
	// addi r29,r11,24
	ctx.r29.s64 = ctx.r11.s64 + 24;
	// bl 0x881534c8
	ctx.lr = 0x8811116C;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// neg r10,r11
	ctx.r10.s64 = -ctx.r11.s64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// clrlwi r5,r10,23
	ctx.r5.u64 = ctx.r10.u32 & 0x1FF;
	// bl 0x880f5570
	ctx.lr = 0x88111184;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x881111ac
	if (ctx.cr6.eq) goto loc_881111AC;
	// stw r20,148(r30)
	PPC_STORE_U32(ctx.r30.u32 + 148, ctx.r20.u32);
loc_88111190:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x881111ac
	if (ctx.cr6.eq) goto loc_881111AC;
	// rlwinm r11,r26,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r21,140(r30)
	PPC_STORE_U32(ctx.r30.u32 + 140, ctx.r21.u32);
	// stw r19,100(r30)
	PPC_STORE_U32(ctx.r30.u32 + 100, ctx.r19.u32);
	// stw r11,112(r30)
	PPC_STORE_U32(ctx.r30.u32 + 112, ctx.r11.u32);
	// stw r23,160(r30)
	PPC_STORE_U32(ctx.r30.u32 + 160, ctx.r23.u32);
loc_881111AC:
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// cmpwi cr6,r26,4
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 4, ctx.xer);
	// blt cr6,0x881110e4
	if (ctx.cr6.lt) goto loc_881110E4;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r3,r16,-31648
	ctx.r3.s64 = ctx.r16.s64 + -31648;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r6,r27,-3
	ctx.r6.s64 = ctx.r27.s64 + -3;
	// add r9,r11,r22
	ctx.r9.u64 = ctx.r11.u64 + ctx.r22.u64;
	// lwz r7,924(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 924);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// li r4,3
	ctx.r4.s64 = 3;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x88110190
	ctx.lr = 0x881111E4;
	sub_88110190(ctx, base);
	// addi r3,r16,-31504
	ctx.r3.s64 = ctx.r16.s64 + -31504;
	// addi r6,r27,1
	ctx.r6.s64 = ctx.r27.s64 + 1;
	// lwz r7,924(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 924);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x88110190
	ctx.lr = 0x881111FC;
	sub_88110190(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,6
	ctx.r10.s64 = 6;
	// stw r11,4(r14)
	PPC_STORE_U32(ctx.r14.u32 + 4, ctx.r11.u32);
	// li r6,50
	ctx.r6.s64 = 50;
	// li r5,72
	ctx.r5.s64 = 72;
	// stw r10,0(r14)
	PPC_STORE_U32(ctx.r14.u32 + 0, ctx.r10.u32);
	// li r4,126
	ctx.r4.s64 = 126;
	// li r3,6
	ctx.r3.s64 = 6;
	// lwz r11,24(r16)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r16.u32 + 24);
	// stw r11,16(r14)
	PPC_STORE_U32(ctx.r14.u32 + 16, ctx.r11.u32);
	// bl 0x880e32d0
	ctx.lr = 0x88111228;
	sub_880E32D0(ctx, base);
loc_88111228:
	// addi r5,r31,4
	ctx.r5.s64 = ctx.r31.s64 + 4;
	// lwz r3,924(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 924);
	// addi r23,r31,8
	ctx.r23.s64 = ctx.r31.s64 + 8;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// bl 0x880940d8
	ctx.lr = 0x88111240;
	sub_880940D8(ctx, base);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8811126c
	if (ctx.cr6.eq) goto loc_8811126C;
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8811126c
	if (ctx.cr6.eq) goto loc_8811126C;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// bgt 0x8811126c
	if (ctx.cr0.gt) goto loc_8811126C;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
loc_8811126C:
	// lis r11,16838
	ctx.r11.s64 = 1103495168;
	// lwz r22,324(r1)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 324);
	// lis r10,15887
	ctx.r10.s64 = 1041170432;
	// addi r29,r31,60
	ctx.r29.s64 = ctx.r31.s64 + 60;
	// li r24,15
	ctx.r24.s64 = 15;
	// ori r27,r11,20077
	ctx.r27.u64 = ctx.r11.u64 | 20077;
	// ori r28,r10,33761
	ctx.r28.u64 = ctx.r10.u64 | 33761;
	// lis r30,-30671
	ctx.r30.s64 = -2010054656;
	// li r19,4
	ctx.r19.s64 = 4;
	// li r21,0
	ctx.r21.s64 = 0;
loc_88111294:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88111384
	if (ctx.cr6.eq) goto loc_88111384;
	// addi r26,r29,4
	ctx.r26.s64 = ctx.r29.s64 + 4;
	// lwz r3,924(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 924);
	// addi r25,r29,8
	ctx.r25.s64 = ctx.r29.s64 + 8;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x880940d8
	ctx.lr = 0x881112BC;
	sub_880940D8(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88111384
	if (ctx.cr6.eq) goto loc_88111384;
	// lwz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r11.u32);
	// bgt 0x88111384
	if (ctx.cr0.gt) goto loc_88111384;
	// lwz r11,4200(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4200);
	// lwz r10,184(r22)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r22.u32 + 184);
	// mullw r11,r11,r27
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r27.s32);
	// lwz r9,168(r22)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r22.u32 + 168);
	// lwz r8,48(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r11,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r11.u32);
	// clrlwi r6,r8,31
	ctx.r6.u64 = ctx.r8.u32 & 0x1;
	// stw r7,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r7.u32);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// lhz r5,4200(r30)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4200);
	// mulhwu r4,r5,r28
	ctx.r4.u64 = (uint64_t(ctx.r5.u32) * uint64_t(ctx.r28.u32)) >> 32;
	// rlwinm r11,r4,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 29) & 0x1FFFFFFF;
	// rlwinm r10,r11,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r11,r3,r5
	ctx.r11.s64 = ctx.r5.s64 - ctx.r3.s64;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// addi r9,r11,176
	ctx.r9.s64 = ctx.r11.s64 + 176;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r8,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// beq cr6,0x88111348
	if (ctx.cr6.eq) goto loc_88111348;
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x881534c8
	ctx.lr = 0x88111338;
	sub_881534C8(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// addi r11,r11,48
	ctx.r11.s64 = ctx.r11.s64 + 48;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
loc_88111348:
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stw r24,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r24.u32);
	// li r3,240
	ctx.r3.s64 = 240;
	// stw r20,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r20.u32);
	// stw r19,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r19.u32);
	// stw r22,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r22.u32);
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r11.u32);
	// lwz r5,0(r25)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r4,0(r26)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// bl 0x880958a0
	ctx.lr = 0x88111374;
	sub_880958A0(ctx, base);
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// stw r21,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r21.u32);
loc_88111384:
	// addi r24,r24,-1
	ctx.r24.s64 = ctx.r24.s64 + -1;
	// addi r29,r29,48
	ctx.r29.s64 = ctx.r29.s64 + 48;
	// cmpwi cr6,r24,-1
	ctx.cr6.compare<int32_t>(ctx.r24.s32, -1, ctx.xer);
	// bgt cr6,0x88111294
	if (ctx.cr6.gt) goto loc_88111294;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r9,-256
	ctx.r9.s64 = -16777216;
	// lwz r10,0(r23)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r23.u32 + 0);
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// bgt cr6,0x881113d8
	if (ctx.cr6.gt) goto loc_881113D8;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r17,932(r31)
	PPC_STORE_U32(ctx.r31.u32 + 932, ctx.r17.u32);
	// mr r11,r21
	ctx.r11.u64 = ctx.r21.u64;
	// stw r9,928(r31)
	PPC_STORE_U32(ctx.r31.u32 + 928, ctx.r9.u32);
	// stw r21,-29740(r18)
	PPC_STORE_U32(ctx.r18.u32 + -29740, ctx.r21.u32);
	// stw r21,68(r10)
	PPC_STORE_U32(ctx.r10.u32 + 68, ctx.r21.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r21,72(r8)
	PPC_STORE_U32(ctx.r8.u32 + 72, ctx.r21.u32);
	// lwz r7,952(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 952);
	// stw r21,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r21.u32);
loc_881113D8:
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_881113E0"))) PPC_WEAK_FUNC(sub_881113E0);
PPC_FUNC_IMPL(__imp__sub_881113E0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x881113E8;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30703
	ctx.r11.s64 = -2012151808;
	// li r4,2896
	ctx.r4.s64 = 2896;
	// addi r5,r11,5088
	ctx.r5.s64 = ctx.r11.s64 + 5088;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x88111400;
	sub_88094290(ctx, base);
	// li r5,2896
	ctx.r5.s64 = 2896;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,2304(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2304);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x88111414;
	sub_88073BD0(ctx, base);
	// stw r30,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x881556a0
	ctx.lr = 0x88111424;
	sub_881556A0(ctx, base);
	// lis r10,-30703
	ctx.r10.s64 = -2012151808;
	// stw r3,952(r31)
	PPC_STORE_U32(ctx.r31.u32 + 952, ctx.r3.u32);
	// li r27,0
	ctx.r27.s64 = 0;
	// addi r9,r10,1832
	ctx.r9.s64 = ctx.r10.s64 + 1832;
	// stw r30,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r30.u32);
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// stw r9,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r9.u32);
	// lwz r8,952(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 952);
	// stw r27,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r27.u32);
	// lwz r9,952(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 952);
	// lwz r11,28(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88111470
	if (ctx.cr6.eq) goto loc_88111470;
loc_88111458:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x881115c4
	if (ctx.cr6.eq) goto loc_881115C4;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88111458
	if (!ctx.cr6.eq) goto loc_88111458;
loc_88111470:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_88111474:
	// li r10,48
	ctx.r10.s64 = 48;
	// stw r27,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r27.u32);
	// lis r9,64
	ctx.r9.s64 = 4194304;
	// li r26,160
	ctx.r26.s64 = 160;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// addi r29,r31,4
	ctx.r29.s64 = ctx.r31.s64 + 4;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r26,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r26.u32);
	// li r8,120
	ctx.r8.s64 = 120;
	// stw r29,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r29.u32);
	// lis r7,-30703
	ctx.r7.s64 = -2012151808;
	// stw r9,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r9.u32);
	// li r28,1
	ctx.r28.s64 = 1;
	// lwz r11,100(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 100);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r6,r7,304
	ctx.r6.s64 = ctx.r7.s64 + 304;
	// addi r5,r10,-1
	ctx.r5.s64 = ctx.r10.s64 + -1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// and r4,r5,r11
	ctx.r4.u64 = ctx.r5.u64 & ctx.r11.u64;
	// stw r4,924(r31)
	PPC_STORE_U32(ctx.r31.u32 + 924, ctx.r4.u32);
	// stw r8,168(r30)
	PPC_STORE_U32(ctx.r30.u32 + 168, ctx.r8.u32);
	// lwz r11,32(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// lwz r10,36(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// stw r6,76(r30)
	PPC_STORE_U32(ctx.r30.u32 + 76, ctx.r6.u32);
	// stw r28,96(r30)
	PPC_STORE_U32(ctx.r30.u32 + 96, ctx.r28.u32);
	// stw r27,80(r30)
	PPC_STORE_U32(ctx.r30.u32 + 80, ctx.r27.u32);
	// bl 0x88169750
	ctx.lr = 0x881114EC;
	sub_88169750(ctx, base);
	// li r8,16
	ctx.r8.s64 = 16;
	// lis r7,-30671
	ctx.r7.s64 = -2010054656;
	// stw r27,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r27.u32);
	// lis r9,320
	ctx.r9.s64 = 20971520;
	// stw r9,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r9.u32);
	// stw r28,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r28.u32);
	// lis r6,16838
	ctx.r6.s64 = 1103495168;
	// lis r5,-4
	ctx.r5.s64 = -262144;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// ori r4,r6,20077
	ctx.r4.u64 = ctx.r6.u64 | 20077;
	// li r3,272
	ctx.r3.s64 = 272;
	// stw r5,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r5.u32);
	// addi r11,r31,20
	ctx.r11.s64 = ctx.r31.s64 + 20;
	// stw r3,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r3.u32);
	// lis r9,200
	ctx.r9.s64 = 13107200;
	// li r10,120
	ctx.r10.s64 = 120;
	// lwz r8,4200(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4200);
	// mullw r8,r8,r4
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r4.s32);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// stw r8,4200(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4200, ctx.r8.u32);
	// lhz r8,4200(r7)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r7.u32 + 4200);
	// clrlwi r8,r8,31
	ctx.r8.u64 = ctx.r8.u32 & 0x1;
	// stw r8,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r8.u32);
	// lis r8,8
	ctx.r8.s64 = 524288;
	// lwz r7,164(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 164);
	// stw r7,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r7.u32);
	// ori r7,r8,49152
	ctx.r7.u64 = ctx.r8.u64 | 49152;
loc_88111558:
	// stw r10,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r10.u32);
	// addi r10,r10,-8
	ctx.r10.s64 = ctx.r10.s64 + -8;
	// stw r28,40(r11)
	PPC_STORE_U32(ctx.r11.u32 + 40, ctx.r28.u32);
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// stw r8,44(r11)
	PPC_STORE_U32(ctx.r11.u32 + 44, ctx.r8.u32);
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// add r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 + ctx.r8.u64;
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stwu r8,48(r11)
	ea = 48 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x88111558
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88111558;
	// li r11,16
	ctx.r11.s64 = 16;
	// stw r27,832(r31)
	PPC_STORE_U32(ctx.r31.u32 + 832, ctx.r27.u32);
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// stw r11,836(r31)
	PPC_STORE_U32(ctx.r31.u32 + 836, ctx.r11.u32);
	// lwz r11,-11984(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11984);
	// lwz r11,84(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// stw r11,904(r31)
	PPC_STORE_U32(ctx.r31.u32 + 904, ctx.r11.u32);
	// blt cr6,0x881115dc
	if (ctx.cr6.lt) goto loc_881115DC;
	// beq cr6,0x881115dc
	if (ctx.cr6.eq) goto loc_881115DC;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x881115f0
	if (!ctx.cr6.lt) goto loc_881115F0;
	// lis r11,-30703
	ctx.r11.s64 = -2012151808;
	// stw r26,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r26.u32);
	// li r10,8064
	ctx.r10.s64 = 8064;
	// addi r9,r11,-16
	ctx.r9.s64 = ctx.r11.s64 + -16;
	// b 0x881115e8
	goto loc_881115E8;
loc_881115C4:
	// lwz r10,24(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x881115d4
	if (ctx.cr6.eq) goto loc_881115D4;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_881115D4:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x88111474
	goto loc_88111474;
loc_881115DC:
	// lis r11,-30703
	ctx.r11.s64 = -2012151808;
	// li r10,5376
	ctx.r10.s64 = 5376;
	// addi r9,r11,-24
	ctx.r9.s64 = ctx.r11.s64 + -24;
loc_881115E8:
	// stw r10,884(r31)
	PPC_STORE_U32(ctx.r31.u32 + 884, ctx.r10.u32);
	// stw r9,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r9.u32);
loc_881115F0:
	// lwz r11,884(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 884);
	// lis r10,-30703
	ctx.r10.s64 = -2012151808;
	// lis r9,-30703
	ctx.r9.s64 = -2012151808;
	// lis r8,-30703
	ctx.r8.s64 = -2012151808;
	// addi r7,r10,2512
	ctx.r7.s64 = ctx.r10.s64 + 2512;
	// addi r6,r9,2248
	ctx.r6.s64 = ctx.r9.s64 + 2248;
	// addi r5,r8,240
	ctx.r5.s64 = ctx.r8.s64 + 240;
	// stw r11,892(r31)
	PPC_STORE_U32(ctx.r31.u32 + 892, ctx.r11.u32);
	// stw r7,64(r30)
	PPC_STORE_U32(ctx.r30.u32 + 64, ctx.r7.u32);
	// stw r6,68(r30)
	PPC_STORE_U32(ctx.r30.u32 + 68, ctx.r6.u32);
	// stw r5,84(r30)
	PPC_STORE_U32(ctx.r30.u32 + 84, ctx.r5.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88111624"))) PPC_WEAK_FUNC(sub_88111624);
PPC_FUNC_IMPL(__imp__sub_88111624) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88111628"))) PPC_WEAK_FUNC(sub_88111628);
PPC_FUNC_IMPL(__imp__sub_88111628) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// li r11,512
	ctx.r11.s64 = 512;
	// lwz r10,2304(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2304);
	// rlwinm r9,r5,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0x1;
	// subfc r8,r11,r5
	ctx.xer.ca = ctx.r5.u32 >= ctx.r11.u32;
	ctx.r8.s64 = ctx.r5.s64 - ctx.r11.s64;
	// rlwinm r7,r11,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// li r3,1
	ctx.r3.s64 = 1;
	// subfe r6,r9,r7
	temp.u8 = (~ctx.r9.u32 + ctx.r7.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r7.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ~ctx.r9.u64 + ctx.r7.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r5,36(r10)
	PPC_STORE_U32(ctx.r10.u32 + 36, ctx.r5.u32);
	// and r5,r6,r4
	ctx.r5.u64 = ctx.r6.u64 & ctx.r4.u64;
	// stw r5,32(r10)
	PPC_STORE_U32(ctx.r10.u32 + 32, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88111654"))) PPC_WEAK_FUNC(sub_88111654);
PPC_FUNC_IMPL(__imp__sub_88111654) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88111658"))) PPC_WEAK_FUNC(sub_88111658);
PPC_FUNC_IMPL(__imp__sub_88111658) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8811165C"))) PPC_WEAK_FUNC(sub_8811165C);
PPC_FUNC_IMPL(__imp__sub_8811165C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88111660"))) PPC_WEAK_FUNC(sub_88111660);
PPC_FUNC_IMPL(__imp__sub_88111660) {
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
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r11,238
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 238, ctx.xer);
	// bne cr6,0x881116b8
	if (!ctx.cr6.eq) goto loc_881116B8;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x88153458
	ctx.lr = 0x88111694;
	sub_88153458(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// b 0x88111774
	goto loc_88111774;
loc_881116B8:
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r6,r31,4
	ctx.r6.s64 = ctx.r31.s64 + 4;
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addi r3,r10,9552
	ctx.r3.s64 = ctx.r10.s64 + 9552;
	// lwz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r10,r11,128
	ctx.r10.s64 = ctx.r11.s64 + 128;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// rlwinm r10,r10,2,21,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0x7FC;
	// lwzx r9,r9,r3
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r3.u32);
	// lwzx r3,r10,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// mullw r9,r9,r4
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r4.s32);
	// mullw r10,r3,r4
	ctx.r10.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r4.s32);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r4,r7,r10
	ctx.r4.u64 = ctx.r7.u64 + ctx.r10.u64;
	// stw r8,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r8.u32);
	// rlwinm r10,r11,0,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFF0000;
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// rlwinm r7,r8,0,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFF0000;
	// stw r4,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r4.u32);
	// add r3,r5,r9
	ctx.r3.u64 = ctx.r5.u64 + ctx.r9.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// stw r7,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r7.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r3,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// beq cr6,0x8811173c
	if (ctx.cr6.eq) goto loc_8811173C;
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
loc_8811173C:
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x8811174c
	if (ctx.cr6.eq) goto loc_8811174C;
	// subf r11,r7,r8
	ctx.r11.s64 = ctx.r8.s64 - ctx.r7.s64;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
loc_8811174C:
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x880940d8
	ctx.lr = 0x8811175C;
	sub_880940D8(ctx, base);
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lis r11,-200
	ctx.r11.s64 = -13107200;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bgt cr6,0x88111774
	if (ctx.cr6.gt) goto loc_88111774;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88094220
	ctx.lr = 0x88111774;
	sub_88094220(ctx, base);
loc_88111774:
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

__attribute__((alias("__imp__sub_8811178C"))) PPC_WEAK_FUNC(sub_8811178C);
PPC_FUNC_IMPL(__imp__sub_8811178C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88111790"))) PPC_WEAK_FUNC(sub_88111790);
PPC_FUNC_IMPL(__imp__sub_88111790) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x88111798;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r9,2300(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2300);
	// lwz r10,184(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// lwz r11,168(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// lwz r25,2304(r3)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// add r26,r10,r11
	ctx.r26.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r8,156(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 156);
	// lwz r7,160(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
	// srawi r6,r8,16
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFF) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 16;
	// lwz r5,0(r25)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// addze r3,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r3.s64 = temp.s64;
	// lwz r4,4(r25)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r25.u32 + 4);
	// srawi r10,r7,16
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFFFF) != 0);
	ctx.r10.s64 = ctx.r7.s32 >> 16;
	// lwz r11,28(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 28);
	// rlwinm r9,r3,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 16) & 0xFFFF0000;
	// addze r8,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r8.s64 = temp.s64;
	// subf r31,r9,r5
	ctx.r31.s64 = ctx.r5.s64 - ctx.r9.s64;
	// rlwinm r7,r8,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// cmpwi cr6,r11,233
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 233, ctx.xer);
	// subf r30,r7,r4
	ctx.r30.s64 = ctx.r4.s64 - ctx.r7.s64;
	// bne cr6,0x881118a8
	if (!ctx.cr6.eq) goto loc_881118A8;
	// lis r11,-30667
	ctx.r11.s64 = -2009792512;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r11,r11,5136
	ctx.r11.s64 = ctx.r11.s64 + 5136;
	// addi r27,r26,5
	ctx.r27.s64 = ctx.r26.s64 + 5;
	// addi r29,r11,2
	ctx.r29.s64 = ctx.r11.s64 + 2;
loc_88111800:
	// lhz r11,-2(r29)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r29.u32 + -2);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// lhz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r29.u32 + 0);
	// addi r3,r28,1039
	ctx.r3.s64 = ctx.r28.s64 + 1039;
	// rotlwi r11,r11,16
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 16);
	// rotlwi r10,r10,16
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 16);
	// add r4,r11,r31
	ctx.r4.u64 = ctx.r11.u64 + ctx.r31.u64;
	// add r5,r10,r30
	ctx.r5.u64 = ctx.r10.u64 + ctx.r30.u64;
	// bl 0x881538c0
	ctx.lr = 0x88111824;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8811183c
	if (ctx.cr6.eq) goto loc_8811183C;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
loc_8811183C:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// cmplwi cr6,r28,27
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 27, ctx.xer);
	// blt cr6,0x88111800
	if (ctx.cr6.lt) goto loc_88111800;
	// lis r11,-30667
	ctx.r11.s64 = -2009792512;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r11,r11,5076
	ctx.r11.s64 = ctx.r11.s64 + 5076;
	// addi r29,r11,2
	ctx.r29.s64 = ctx.r11.s64 + 2;
loc_8811185C:
	// lhz r11,-2(r29)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r29.u32 + -2);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// lhz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r29.u32 + 0);
	// addi r3,r28,1025
	ctx.r3.s64 = ctx.r28.s64 + 1025;
	// rotlwi r11,r11,16
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 16);
	// rotlwi r10,r10,16
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 16);
	// add r4,r11,r31
	ctx.r4.u64 = ctx.r11.u64 + ctx.r31.u64;
	// add r5,r10,r30
	ctx.r5.u64 = ctx.r10.u64 + ctx.r30.u64;
	// bl 0x881538c0
	ctx.lr = 0x88111880;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88111898
	if (ctx.cr6.eq) goto loc_88111898;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
loc_88111898:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// cmplwi cr6,r28,14
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 14, ctx.xer);
	// blt cr6,0x8811185c
	if (ctx.cr6.lt) goto loc_8811185C;
loc_881118A8:
	// lwz r11,28(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 28);
	// cmpwi cr6,r11,234
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 234, ctx.xer);
	// bne cr6,0x88111984
	if (!ctx.cr6.eq) goto loc_88111984;
	// lis r11,-30667
	ctx.r11.s64 = -2009792512;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r11,r11,5312
	ctx.r11.s64 = ctx.r11.s64 + 5312;
	// addi r27,r26,5
	ctx.r27.s64 = ctx.r26.s64 + 5;
	// addi r29,r11,2
	ctx.r29.s64 = ctx.r11.s64 + 2;
loc_881118C8:
	// lhz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r29.u32 + 0);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// lhz r10,-2(r29)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r29.u32 + -2);
	// addi r3,r28,1082
	ctx.r3.s64 = ctx.r28.s64 + 1082;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// rotlwi r10,r10,16
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 16);
	// addi r9,r11,64
	ctx.r9.s64 = ctx.r11.s64 + 64;
	// add r4,r10,r31
	ctx.r4.u64 = ctx.r10.u64 + ctx.r31.u64;
	// rlwinm r11,r9,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// add r5,r11,r30
	ctx.r5.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x881538c0
	ctx.lr = 0x881118F4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8811190c
	if (ctx.cr6.eq) goto loc_8811190C;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
loc_8811190C:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// cmplwi cr6,r28,24
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 24, ctx.xer);
	// blt cr6,0x881118c8
	if (ctx.cr6.lt) goto loc_881118C8;
	// lis r11,-30667
	ctx.r11.s64 = -2009792512;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r11,r11,5248
	ctx.r11.s64 = ctx.r11.s64 + 5248;
	// addi r27,r26,6
	ctx.r27.s64 = ctx.r26.s64 + 6;
	// addi r29,r11,2
	ctx.r29.s64 = ctx.r11.s64 + 2;
loc_88111930:
	// lhz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r29.u32 + 0);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// lhz r10,-2(r29)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r29.u32 + -2);
	// addi r3,r28,1066
	ctx.r3.s64 = ctx.r28.s64 + 1066;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// rotlwi r10,r10,16
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 16);
	// addi r9,r11,64
	ctx.r9.s64 = ctx.r11.s64 + 64;
	// add r4,r10,r31
	ctx.r4.u64 = ctx.r10.u64 + ctx.r31.u64;
	// rlwinm r11,r9,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// add r5,r11,r30
	ctx.r5.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x881538c0
	ctx.lr = 0x8811195C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88111974
	if (ctx.cr6.eq) goto loc_88111974;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
loc_88111974:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// cmplwi cr6,r28,16
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 16, ctx.xer);
	// blt cr6,0x88111930
	if (ctx.cr6.lt) goto loc_88111930;
loc_88111984:
	// lwz r11,28(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 28);
	// cmpwi cr6,r11,235
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 235, ctx.xer);
	// bne cr6,0x88111a60
	if (!ctx.cr6.eq) goto loc_88111A60;
	// lis r11,-30667
	ctx.r11.s64 = -2009792512;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r11,r11,5480
	ctx.r11.s64 = ctx.r11.s64 + 5480;
	// addi r27,r26,4
	ctx.r27.s64 = ctx.r26.s64 + 4;
	// addi r29,r11,2
	ctx.r29.s64 = ctx.r11.s64 + 2;
loc_881119A4:
	// lhz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r29.u32 + 0);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// lhz r10,-2(r29)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r29.u32 + -2);
	// addi r3,r28,1123
	ctx.r3.s64 = ctx.r28.s64 + 1123;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// rotlwi r10,r10,16
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 16);
	// addi r9,r11,64
	ctx.r9.s64 = ctx.r11.s64 + 64;
	// add r4,r10,r31
	ctx.r4.u64 = ctx.r10.u64 + ctx.r31.u64;
	// rlwinm r11,r9,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// add r5,r11,r30
	ctx.r5.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x881538c0
	ctx.lr = 0x881119D0;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x881119e8
	if (ctx.cr6.eq) goto loc_881119E8;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
loc_881119E8:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// cmplwi cr6,r28,24
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 24, ctx.xer);
	// blt cr6,0x881119a4
	if (ctx.cr6.lt) goto loc_881119A4;
	// lis r11,-30667
	ctx.r11.s64 = -2009792512;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r11,r11,5408
	ctx.r11.s64 = ctx.r11.s64 + 5408;
	// addi r27,r26,6
	ctx.r27.s64 = ctx.r26.s64 + 6;
	// addi r29,r11,2
	ctx.r29.s64 = ctx.r11.s64 + 2;
loc_88111A0C:
	// lhz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r29.u32 + 0);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// lhz r10,-2(r29)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r29.u32 + -2);
	// addi r3,r28,1106
	ctx.r3.s64 = ctx.r28.s64 + 1106;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// rotlwi r10,r10,16
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 16);
	// addi r9,r11,64
	ctx.r9.s64 = ctx.r11.s64 + 64;
	// add r4,r10,r31
	ctx.r4.u64 = ctx.r10.u64 + ctx.r31.u64;
	// rlwinm r11,r9,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// add r5,r11,r30
	ctx.r5.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x881538c0
	ctx.lr = 0x88111A38;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88111a50
	if (ctx.cr6.eq) goto loc_88111A50;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
loc_88111A50:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// cmplwi cr6,r28,17
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 17, ctx.xer);
	// blt cr6,0x88111a0c
	if (ctx.cr6.lt) goto loc_88111A0C;
loc_88111A60:
	// lwz r11,28(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 28);
	// cmpwi cr6,r11,236
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 236, ctx.xer);
	// bne cr6,0x88111b2c
	if (!ctx.cr6.eq) goto loc_88111B2C;
	// lis r11,-30667
	ctx.r11.s64 = -2009792512;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r11,r11,5624
	ctx.r11.s64 = ctx.r11.s64 + 5624;
	// addi r27,r26,4
	ctx.r27.s64 = ctx.r26.s64 + 4;
	// addi r29,r11,2
	ctx.r29.s64 = ctx.r11.s64 + 2;
loc_88111A80:
	// lhz r11,-2(r29)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r29.u32 + -2);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// lhz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r29.u32 + 0);
	// addi r3,r28,1159
	ctx.r3.s64 = ctx.r28.s64 + 1159;
	// rotlwi r11,r11,16
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 16);
	// rotlwi r10,r10,16
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 16);
	// add r4,r11,r31
	ctx.r4.u64 = ctx.r11.u64 + ctx.r31.u64;
	// add r5,r10,r30
	ctx.r5.u64 = ctx.r10.u64 + ctx.r30.u64;
	// bl 0x881538c0
	ctx.lr = 0x88111AA4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88111abc
	if (ctx.cr6.eq) goto loc_88111ABC;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
loc_88111ABC:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// cmplwi cr6,r28,16
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 16, ctx.xer);
	// blt cr6,0x88111a80
	if (ctx.cr6.lt) goto loc_88111A80;
	// lis r11,-30667
	ctx.r11.s64 = -2009792512;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r11,r11,5576
	ctx.r11.s64 = ctx.r11.s64 + 5576;
	// addi r27,r26,6
	ctx.r27.s64 = ctx.r26.s64 + 6;
	// addi r29,r11,2
	ctx.r29.s64 = ctx.r11.s64 + 2;
loc_88111AE0:
	// lhz r11,-2(r29)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r29.u32 + -2);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// lhz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r29.u32 + 0);
	// addi r3,r28,1147
	ctx.r3.s64 = ctx.r28.s64 + 1147;
	// rotlwi r11,r11,16
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 16);
	// rotlwi r10,r10,16
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 16);
	// add r4,r11,r31
	ctx.r4.u64 = ctx.r11.u64 + ctx.r31.u64;
	// add r5,r10,r30
	ctx.r5.u64 = ctx.r10.u64 + ctx.r30.u64;
	// bl 0x881538c0
	ctx.lr = 0x88111B04;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88111b1c
	if (ctx.cr6.eq) goto loc_88111B1C;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
loc_88111B1C:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// cmplwi cr6,r28,12
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 12, ctx.xer);
	// blt cr6,0x88111ae0
	if (ctx.cr6.lt) goto loc_88111AE0;
loc_88111B2C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88111B34"))) PPC_WEAK_FUNC(sub_88111B34);
PPC_FUNC_IMPL(__imp__sub_88111B34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88111B38"))) PPC_WEAK_FUNC(sub_88111B38);
PPC_FUNC_IMPL(__imp__sub_88111B38) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88111B40;
	__savegprlr_28(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r5,-292
	ctx.r5.s64 = -19136512;
	// li r4,40
	ctx.r4.s64 = 40;
	// ori r5,r5,47768
	ctx.r5.u64 = ctx.r5.u64 | 47768;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x88111B58;
	sub_88094290(ctx, base);
	// li r5,40
	ctx.r5.s64 = 40;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,2304(r28)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r28.u32 + 2304);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x88111B6C;
	sub_88073BD0(ctx, base);
	// lwz r6,32(r28)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r28.u32 + 32);
	// li r11,50
	ctx.r11.s64 = 50;
	// lis r10,-30703
	ctx.r10.s64 = -2012151808;
	// stw r11,168(r28)
	PPC_STORE_U32(ctx.r28.u32 + 168, ctx.r11.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r8,r10,5672
	ctx.r8.s64 = ctx.r10.s64 + 5672;
	// stw r6,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r6.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r5,36(r28)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r28.u32 + 36);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r5,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r5.u32);
	// stw r8,76(r28)
	PPC_STORE_U32(ctx.r28.u32 + 76, ctx.r8.u32);
	// stw r9,96(r28)
	PPC_STORE_U32(ctx.r28.u32 + 96, ctx.r9.u32);
	// stw r7,80(r28)
	PPC_STORE_U32(ctx.r28.u32 + 80, ctx.r7.u32);
	// bl 0x88169750
	ctx.lr = 0x88111BA8;
	sub_88169750(ctx, base);
	// lwz r11,100(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 100);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r4,r10,-1
	ctx.r4.s64 = ctx.r10.s64 + -1;
	// and r3,r4,r11
	ctx.r3.u64 = ctx.r4.u64 & ctx.r11.u64;
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// lwz r11,4(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// cmpwi cr6,r11,234
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 234, ctx.xer);
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// bne cr6,0x88111c24
	if (!ctx.cr6.eq) goto loc_88111C24;
	// lis r11,-30667
	ctx.r11.s64 = -2009792512;
	// addi r10,r31,8
	ctx.r10.s64 = ctx.r31.s64 + 8;
	// addi r11,r11,5688
	ctx.r11.s64 = ctx.r11.s64 + 5688;
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// li r29,6
	ctx.r29.s64 = 6;
	// addi r30,r11,-2
	ctx.r30.s64 = ctx.r11.s64 + -2;
loc_88111BE8:
	// lhz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lhz r8,6(r30)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r30.u32 + 6);
	// lhz r3,2(r30)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r30.u32 + 2);
	// lhzu r11,8(r30)
	ea = 8 + ctx.r30.u32;
	ctx.r11.u64 = PPC_LOAD_U16(ea);
	ctx.r30.u32 = ea;
	// rotlwi r8,r8,16
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 16);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// rotlwi r11,r11,16
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 16);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r4,r8,r9
	ctx.r4.u64 = ctx.r8.u64 + ctx.r9.u64;
	// bl 0x880958a0
	ctx.lr = 0x88111C1C;
	sub_880958A0(ctx, base);
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne 0x88111be8
	if (!ctx.cr0.eq) goto loc_88111BE8;
loc_88111C24:
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r11,235
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 235, ctx.xer);
	// bne cr6,0x88111c84
	if (!ctx.cr6.eq) goto loc_88111C84;
	// lis r11,-30667
	ctx.r11.s64 = -2009792512;
	// addi r10,r31,8
	ctx.r10.s64 = ctx.r31.s64 + 8;
	// addi r11,r11,5736
	ctx.r11.s64 = ctx.r11.s64 + 5736;
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// li r29,6
	ctx.r29.s64 = 6;
	// addi r30,r11,-2
	ctx.r30.s64 = ctx.r11.s64 + -2;
loc_88111C48:
	// lhz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lhz r8,6(r30)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r30.u32 + 6);
	// lhz r3,2(r30)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r30.u32 + 2);
	// lhzu r11,8(r30)
	ea = 8 + ctx.r30.u32;
	ctx.r11.u64 = PPC_LOAD_U16(ea);
	ctx.r30.u32 = ea;
	// rotlwi r8,r8,16
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 16);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// rotlwi r11,r11,16
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 16);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r4,r8,r9
	ctx.r4.u64 = ctx.r8.u64 + ctx.r9.u64;
	// bl 0x880958a0
	ctx.lr = 0x88111C7C;
	sub_880958A0(ctx, base);
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne 0x88111c48
	if (!ctx.cr0.eq) goto loc_88111C48;
loc_88111C84:
	// lis r11,-30703
	ctx.r11.s64 = -2012151808;
	// lis r10,-30703
	ctx.r10.s64 = -2012151808;
	// lis r9,-30703
	ctx.r9.s64 = -2012151808;
	// addi r8,r11,5728
	ctx.r8.s64 = ctx.r11.s64 + 5728;
	// addi r7,r10,6032
	ctx.r7.s64 = ctx.r10.s64 + 6032;
	// addi r6,r9,5720
	ctx.r6.s64 = ctx.r9.s64 + 5720;
	// stw r8,64(r28)
	PPC_STORE_U32(ctx.r28.u32 + 64, ctx.r8.u32);
	// stw r7,68(r28)
	PPC_STORE_U32(ctx.r28.u32 + 68, ctx.r7.u32);
	// stw r6,84(r28)
	PPC_STORE_U32(ctx.r28.u32 + 84, ctx.r6.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88111CB0"))) PPC_WEAK_FUNC(sub_88111CB0);
PPC_FUNC_IMPL(__imp__sub_88111CB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// li r11,512
	ctx.r11.s64 = 512;
	// lwz r10,2304(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2304);
	// rlwinm r9,r5,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0x1;
	// subfc r8,r11,r5
	ctx.xer.ca = ctx.r5.u32 >= ctx.r11.u32;
	ctx.r8.s64 = ctx.r5.s64 - ctx.r11.s64;
	// rlwinm r7,r11,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// li r3,1
	ctx.r3.s64 = 1;
	// subfe r6,r9,r7
	temp.u8 = (~ctx.r9.u32 + ctx.r7.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r7.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ~ctx.r9.u64 + ctx.r7.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r5,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r5.u32);
	// and r5,r6,r4
	ctx.r5.u64 = ctx.r6.u64 & ctx.r4.u64;
	// stw r5,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88111CDC"))) PPC_WEAK_FUNC(sub_88111CDC);
PPC_FUNC_IMPL(__imp__sub_88111CDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88111CE0"))) PPC_WEAK_FUNC(sub_88111CE0);
PPC_FUNC_IMPL(__imp__sub_88111CE0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r9,100(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 100);
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

__attribute__((alias("__imp__sub_88111D20"))) PPC_WEAK_FUNC(sub_88111D20);
PPC_FUNC_IMPL(__imp__sub_88111D20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88111D28;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r9,2300(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2300);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r3,11681
	ctx.r3.s64 = 11681;
	// lwz r8,156(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 156);
	// lwz r7,160(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
	// srawi r5,r8,16
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFF) != 0);
	ctx.r5.s64 = ctx.r8.s32 >> 16;
	// lwz r31,2304(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2304);
	// lwz r10,184(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 184);
	// addze r5,r5
	temp.s64 = ctx.r5.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r5.s64 = temp.s64;
	// lwz r11,168(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 168);
	// subfic r4,r5,12
	ctx.xer.ca = ctx.r5.u32 <= 12;
	ctx.r4.s64 = 12 - ctx.r5.s64;
	// srawi r9,r7,16
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFFFF) != 0);
	ctx.r9.s64 = ctx.r7.s32 >> 16;
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// add r28,r10,r11
	ctx.r28.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addze r9,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r9.s64 = temp.s64;
	// lwz r29,40(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// addi r7,r9,12
	ctx.r7.s64 = ctx.r9.s64 + 12;
	// addi r6,r28,-1
	ctx.r6.s64 = ctx.r28.s64 + -1;
	// rlwinm r5,r7,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r5,r5,r8
	ctx.r5.s64 = ctx.r8.s64 - ctx.r5.s64;
	// bl 0x881538c0
	ctx.lr = 0x88111D8C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88111db0
	if (ctx.cr6.eq) goto loc_88111DB0;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// oris r8,r9,518
	ctx.r8.u64 = ctx.r9.u64 | 33947648;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// lwz r11,-11932(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11932);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-11932(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11932, ctx.r11.u32);
loc_88111DB0:
	// lwz r9,2300(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2300);
	// lis r7,-30680
	ctx.r7.s64 = -2010644480;
	// rlwinm r5,r29,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r11,r7,20264
	ctx.r11.s64 = ctx.r7.s64 + 20264;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// lwz r7,156(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 156);
	// addi r3,r29,11649
	ctx.r3.s64 = ctx.r29.s64 + 11649;
	// lwz r9,160(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
	// srawi r7,r7,16
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFFFF) != 0);
	ctx.r7.s64 = ctx.r7.s32 >> 16;
	// lbzx r11,r5,r11
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r11.u32);
	// lbzx r5,r5,r4
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r4.u32);
	// addze r7,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r7.s64 = temp.s64;
	// srawi r4,r9,16
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xFFFF) != 0);
	ctx.r4.s64 = ctx.r9.s32 >> 16;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addze r9,r4
	temp.s64 = ctx.r4.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r9.s64 = temp.s64;
	// extsb r5,r5
	ctx.r5.s64 = ctx.r5.s8;
	// subf r4,r7,r11
	ctx.r4.s64 = ctx.r11.s64 - ctx.r7.s64;
	// subf r11,r9,r5
	ctx.r11.s64 = ctx.r5.s64 - ctx.r9.s64;
	// rlwinm r9,r4,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r9,r8
	ctx.r4.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x88111E18;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88111e28
	if (ctx.cr6.eq) goto loc_88111E28;
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_88111E28:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88111E30"))) PPC_WEAK_FUNC(sub_88111E30);
PPC_FUNC_IMPL(__imp__sub_88111E30) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88111E38;
	__savegprlr_29(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x88111fcc
	if (ctx.cr6.eq) goto loc_88111FCC;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x88111ea0
	if (ctx.cr6.eq) goto loc_88111EA0;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x88112008
	if (!ctx.cr6.eq) goto loc_88112008;
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// bge 0x88112008
	if (!ctx.cr0.lt) goto loc_88112008;
	// lwz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// stw r10,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r10.u32);
	// bgt 0x88112008
	if (ctx.cr0.gt) goto loc_88112008;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_88111EA0:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// bge 0x88111ed4
	if (!ctx.cr0.lt) goto loc_88111ED4;
	// lwz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// cmpwi cr6,r11,31
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 31, ctx.xer);
	// stw r10,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r10.u32);
	// blt cr6,0x88111ed4
	if (ctx.cr6.lt) goto loc_88111ED4;
	// li r11,15
	ctx.r11.s64 = 15;
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
loc_88111ED4:
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// bge 0x88112008
	if (!ctx.cr0.lt) goto loc_88112008;
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// li r10,4
	ctx.r10.s64 = 4;
	// lwz r9,52(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r10,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r10.u32);
	// stw r8,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r8.u32);
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x88111f18
	if (!ctx.cr6.eq) goto loc_88111F18;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x88095590
	ctx.lr = 0x88111F14;
	sub_88095590(ctx, base);
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
loc_88111F18:
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lis r11,144
	ctx.r11.s64 = 9437184;
	// cmpw cr6,r5,r11
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x88111f84
	if (ctx.cr6.lt) goto loc_88111F84;
	// lwz r30,4(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88094d40
	ctx.lr = 0x88111F38;
	sub_88094D40(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x88111f84
	if (ctx.cr6.eq) goto loc_88111F84;
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// addi r9,r11,8
	ctx.r9.s64 = ctx.r11.s64 + 8;
	// srawi r8,r9,4
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xF) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 4;
	// lwz r11,26276(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26276);
	// rlwinm r10,r8,4,23,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0x1F0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88111f84
	if (!ctx.cr6.eq) goto loc_88111F84;
	// clrlwi r7,r10,16
	ctx.r7.u64 = ctx.r10.u32 & 0xFFFF;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// li r6,-9
	ctx.r6.s64 = -9;
	// sth r11,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r11.u16);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,35
	ctx.r3.s64 = 35;
	// bl 0x8815c948
	ctx.lr = 0x88111F7C;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x88111F84;
	sub_8815C860(ctx, base);
loc_88111F84:
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// bgt 0x88112008
	if (ctx.cr0.gt) goto loc_88112008;
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r9,56(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// stw r8,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r8.u32);
	// lwz r11,26424(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26424);
	// stw r9,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r9.u32);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r6,r7,28,4,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 28) & 0xFFFFFFF;
	// subfic r5,r6,52
	ctx.xer.ca = ctx.r6.u32 <= 52;
	ctx.r5.s64 = 52 - ctx.r6.s64;
	// stw r5,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r5.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_88111FCC:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// bge 0x88112008
	if (!ctx.cr0.lt) goto loc_88112008;
	// lwz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// cmpwi cr6,r11,15
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 15, ctx.xer);
	// stw r10,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r10.u32);
	// blt cr6,0x88112008
	if (ctx.cr6.lt) goto loc_88112008;
	// li r11,15
	ctx.r11.s64 = 15;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
loc_88112008:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88112010"))) PPC_WEAK_FUNC(sub_88112010);
PPC_FUNC_IMPL(__imp__sub_88112010) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88112018;
	__savegprlr_29(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x88112198
	if (ctx.cr6.eq) goto loc_88112198;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x88112080
	if (ctx.cr6.eq) goto loc_88112080;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x881121d4
	if (!ctx.cr6.eq) goto loc_881121D4;
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// bge 0x881121d4
	if (!ctx.cr0.lt) goto loc_881121D4;
	// lwz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// stw r10,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r10.u32);
	// bgt 0x881121d4
	if (ctx.cr0.gt) goto loc_881121D4;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_88112080:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// bge 0x881120b4
	if (!ctx.cr0.lt) goto loc_881120B4;
	// lwz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// cmpwi cr6,r11,31
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 31, ctx.xer);
	// stw r10,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r10.u32);
	// blt cr6,0x881120b4
	if (ctx.cr6.lt) goto loc_881120B4;
	// li r11,15
	ctx.r11.s64 = 15;
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
loc_881120B4:
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// bge 0x881121d4
	if (!ctx.cr0.lt) goto loc_881121D4;
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// li r10,4
	ctx.r10.s64 = 4;
	// lwz r9,52(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r10,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r10.u32);
	// stw r8,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r8.u32);
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x881120f8
	if (!ctx.cr6.eq) goto loc_881120F8;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x88095590
	ctx.lr = 0x881120F4;
	sub_88095590(ctx, base);
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
loc_881120F8:
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lis r11,160
	ctx.r11.s64 = 10485760;
	// cmpw cr6,r5,r11
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x88112158
	if (ctx.cr6.lt) goto loc_88112158;
	// lwz r30,4(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88094d40
	ctx.lr = 0x88112118;
	sub_88094D40(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x88112158
	if (ctx.cr6.eq) goto loc_88112158;
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r10,26276(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26276);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x88112158
	if (!ctx.cr6.eq) goto loc_88112158;
	// clrlwi r7,r11,16
	ctx.r7.u64 = ctx.r11.u32 & 0xFFFF;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// li r6,-9
	ctx.r6.s64 = -9;
	// sth r10,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r10.u16);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,34
	ctx.r3.s64 = 34;
	// bl 0x8815c948
	ctx.lr = 0x88112150;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x88112158;
	sub_8815C860(ctx, base);
loc_88112158:
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// bgt 0x881121d4
	if (ctx.cr0.gt) goto loc_881121D4;
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r9,56(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// stw r8,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r8.u32);
	// lwz r11,26424(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26424);
	// stw r9,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r9.u32);
	// rlwinm r7,r11,29,4,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0xFFFFFFF;
	// subfic r6,r7,40
	ctx.xer.ca = ctx.r7.u32 <= 40;
	ctx.r6.s64 = 40 - ctx.r7.s64;
	// stw r6,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r6.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_88112198:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// bge 0x881121d4
	if (!ctx.cr0.lt) goto loc_881121D4;
	// lwz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// cmpwi cr6,r11,15
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 15, ctx.xer);
	// stw r10,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r10.u32);
	// blt cr6,0x881121d4
	if (ctx.cr6.lt) goto loc_881121D4;
	// li r11,15
	ctx.r11.s64 = 15;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
loc_881121D4:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_881121DC"))) PPC_WEAK_FUNC(sub_881121DC);
PPC_FUNC_IMPL(__imp__sub_881121DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881121E0"))) PPC_WEAK_FUNC(sub_881121E0);
PPC_FUNC_IMPL(__imp__sub_881121E0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x881121E8;
	__savegprlr_27(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x88112344
	if (ctx.cr6.eq) goto loc_88112344;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x88112250
	if (ctx.cr6.eq) goto loc_88112250;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x88112380
	if (!ctx.cr6.eq) goto loc_88112380;
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// bge 0x88112380
	if (!ctx.cr0.lt) goto loc_88112380;
	// lwz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// stw r10,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r10.u32);
	// bgt 0x88112380
	if (ctx.cr0.gt) goto loc_88112380;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_88112250:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// bge 0x88112284
	if (!ctx.cr0.lt) goto loc_88112284;
	// lwz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// cmpwi cr6,r11,31
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 31, ctx.xer);
	// stw r10,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r10.u32);
	// blt cr6,0x88112284
	if (ctx.cr6.lt) goto loc_88112284;
	// li r11,15
	ctx.r11.s64 = 15;
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
loc_88112284:
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// bge 0x88112380
	if (!ctx.cr0.lt) goto loc_88112380;
	// lwz r30,8(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r11,4
	ctx.r11.s64 = 4;
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,192
	ctx.r9.s64 = 12582912;
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// li r27,0
	ctx.r27.s64 = 0;
	// stw r10,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r10.u32);
	// cmpw cr6,r30,r9
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x88112318
	if (ctx.cr6.lt) goto loc_88112318;
	// lwz r29,4(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88094d40
	ctx.lr = 0x881122C8;
	sub_88094D40(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x88112318
	if (ctx.cr6.eq) goto loc_88112318;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x88095590
	ctx.lr = 0x881122E0;
	sub_88095590(ctx, base);
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26276(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26276);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88112318
	if (!ctx.cr6.eq) goto loc_88112318;
	// clrlwi r7,r3,16
	ctx.r7.u64 = ctx.r3.u32 & 0xFFFF;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// li r6,-7
	ctx.r6.s64 = -7;
	// sth r27,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r27.u16);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,17
	ctx.r3.s64 = 17;
	// bl 0x8815c948
	ctx.lr = 0x88112310;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x88112318;
	sub_8815C860(ctx, base);
loc_88112318:
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// bgt 0x88112380
	if (ctx.cr0.gt) goto loc_88112380;
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// li r10,64
	ctx.r10.s64 = 64;
	// stw r27,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r27.u32);
	// stw r10,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r10.u32);
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_88112344:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// bge 0x88112380
	if (!ctx.cr0.lt) goto loc_88112380;
	// lwz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// cmpwi cr6,r11,15
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 15, ctx.xer);
	// stw r10,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r10.u32);
	// blt cr6,0x88112380
	if (ctx.cr6.lt) goto loc_88112380;
	// li r11,15
	ctx.r11.s64 = 15;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
loc_88112380:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88112388"))) PPC_WEAK_FUNC(sub_88112388);
PPC_FUNC_IMPL(__imp__sub_88112388) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88112390;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// li r29,0
	ctx.r29.s64 = 0;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x881123cc
	if (ctx.cr6.eq) goto loc_881123CC;
loc_881123B4:
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
	// bne cr6,0x881123b4
	if (!ctx.cr6.eq) goto loc_881123B4;
loc_881123CC:
	// lis r11,128
	ctx.r11.s64 = 8388608;
	// clrlwi r10,r10,20
	ctx.r10.u64 = ctx.r10.u32 & 0xFFF;
	// ori r9,r11,32896
	ctx.r9.u64 = ctx.r11.u64 | 32896;
	// rlwinm r10,r10,0,26,21
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFC3F;
	// stw r9,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r9.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8811240c
	if (ctx.cr6.eq) goto loc_8811240C;
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r9,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r9.u32);
	// beq cr6,0x88112444
	if (ctx.cr6.eq) goto loc_88112444;
	// lis r11,192
	ctx.r11.s64 = 12582912;
	// ori r10,r11,49152
	ctx.r10.u64 = ctx.r11.u64 | 49152;
	// b 0x88112440
	goto loc_88112440;
loc_8811240C:
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// srawi r9,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 2;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// cmpw cr6,r10,r8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, ctx.xer);
	// bge cr6,0x88112444
	if (!ctx.cr6.lt) goto loc_88112444;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26428(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26428);
	// rlwinm r10,r11,0,28,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xE;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x88112444
	if (!ctx.cr6.eq) goto loc_88112444;
	// lis r11,255
	ctx.r11.s64 = 16711680;
	// ori r10,r11,4112
	ctx.r10.u64 = ctx.r11.u64 | 4112;
loc_88112440:
	// stw r10,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r10.u32);
loc_88112444:
	// addi r5,r31,4
	ctx.r5.s64 = ctx.r31.s64 + 4;
	// lwz r3,88(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// addi r6,r31,8
	ctx.r6.s64 = ctx.r31.s64 + 8;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// bl 0x880940d8
	ctx.lr = 0x88112458;
	sub_880940D8(ctx, base);
	// lwz r11,100(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 100);
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lis r8,16
	ctx.r8.s64 = 1048576;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// add. r10,r5,r8
	ctx.r10.u64 = ctx.r5.u64 + ctx.r8.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// and r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 & ctx.r11.u64;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// ble 0x881124cc
	if (!ctx.cr0.gt) goto loc_881124CC;
	// lis r9,32
	ctx.r9.s64 = 2097152;
	// lis r7,320
	ctx.r7.s64 = 20971520;
	// subf r6,r9,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r9.s64;
	// cmpw cr6,r6,r7
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r7.s32, ctx.xer);
	// bge cr6,0x881124cc
	if (!ctx.cr6.lt) goto loc_881124CC;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// addi r7,r11,55
	ctx.r7.s64 = ctx.r11.s64 + 55;
	// lis r6,-40
	ctx.r6.s64 = -2621440;
	// rlwinm r3,r7,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-11984(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11984);
	// lwzx r11,r3,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r11.u32);
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// cmpw cr6,r11,r6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r6.s32, ctx.xer);
	// ble cr6,0x881124cc
	if (!ctx.cr6.gt) goto loc_881124CC;
	// lis r10,280
	ctx.r10.s64 = 18350080;
	// subf r9,r9,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r9.s64;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x881124f0
	if (ctx.cr6.lt) goto loc_881124F0;
loc_881124CC:
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x881124f8
	if (ctx.cr6.eq) goto loc_881124F8;
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r29,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r29.u32);
	// bl 0x88094220
	ctx.lr = 0x881124E8;
	sub_88094220(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_881124F0:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
loc_881124F8:
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88112520
	if (!ctx.cr6.eq) goto loc_88112520;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88095590
	ctx.lr = 0x8811250C;
	sub_88095590(ctx, base);
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// bl 0x88153010
	ctx.lr = 0x88112518;
	sub_88153010(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
loc_88112520:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88112528"))) PPC_WEAK_FUNC(sub_88112528);
PPC_FUNC_IMPL(__imp__sub_88112528) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071134
	ctx.lr = 0x88112530;
	__savegprlr_19(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,68(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 68);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8811295c
	if (!ctx.cr6.gt) goto loc_8811295C;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// subf. r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r9,68(r5)
	PPC_STORE_U32(ctx.r5.u32 + 68, ctx.r9.u32);
	// bgt 0x8811295c
	if (ctx.cr0.gt) goto loc_8811295C;
	// lwz r11,0(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// lwz r10,172(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 172);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// blt cr6,0x88112570
	if (ctx.cr6.lt) goto loc_88112570;
	// lwz r9,188(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 188);
	// b 0x88112578
	goto loc_88112578;
loc_88112570:
	// lwz r9,184(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 184);
	// lwz r10,168(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 168);
loc_88112578:
	// add r29,r9,r10
	ctx.r29.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8811258c
	if (ctx.cr6.eq) goto loc_8811258C;
	// lwz r10,20(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
loc_8811258C:
	// stw r10,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r10.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// stw r10,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r10.u32);
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x881125ac
	if (ctx.cr6.eq) goto loc_881125AC;
	// lwz r9,176(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 176);
loc_881125AC:
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x881125bc
	if (ctx.cr6.eq) goto loc_881125BC;
	// lwz r10,164(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 164);
loc_881125BC:
	// stw r10,2328(r11)
	PPC_STORE_U32(ctx.r11.u32 + 2328, ctx.r10.u32);
	// li r6,32
	ctx.r6.s64 = 32;
	// stw r9,2332(r11)
	PPC_STORE_U32(ctx.r11.u32 + 2332, ctx.r9.u32);
	// li r5,40
	ctx.r5.s64 = 40;
	// li r4,93
	ctx.r4.s64 = 93;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x880e32d0
	ctx.lr = 0x881125D8;
	sub_880E32D0(ctx, base);
	// li r5,470
	ctx.r5.s64 = 470;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x88095178
	ctx.lr = 0x881125E8;
	sub_88095178(ctx, base);
	// addi r4,r29,1
	ctx.r4.s64 = ctx.r29.s64 + 1;
	// li r30,2
	ctx.r30.s64 = 2;
	// lis r25,-30667
	ctx.r25.s64 = -2009792512;
	// lis r24,-30667
	ctx.r24.s64 = -2009792512;
loc_881125F8:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// stw r11,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r10.u32);
	// bl 0x880f34b0
	ctx.lr = 0x88112610;
	sub_880F34B0(ctx, base);
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r10.u32);
	// bl 0x880f34b0
	ctx.lr = 0x88112628;
	sub_880F34B0(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x881125f8
	if (!ctx.cr0.eq) goto loc_881125F8;
	// lis r11,4
	ctx.r11.s64 = 262144;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r19,r29,2
	ctx.r19.s64 = ctx.r29.s64 + 2;
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r10,r9,r8
	ctx.r10.u64 = ctx.r9.u64 + ctx.r8.u64;
	// stw r11,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r11.u32);
	// li r3,7
	ctx.r3.s64 = 7;
	// stw r10,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r10.u32);
	// mr r4,r19
	ctx.r4.u64 = ctx.r19.u64;
	// bl 0x880f52c8
	ctx.lr = 0x88112660;
	sub_880F52C8(ctx, base);
	// li r27,8
	ctx.r27.s64 = 8;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88112678
	if (ctx.cr6.eq) goto loc_88112678;
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// stw r27,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r27.u32);
	// stw r11,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r11.u32);
loc_88112678:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// mr r4,r19
	ctx.r4.u64 = ctx.r19.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r3,9
	ctx.r3.s64 = 9;
	// stw r11,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r10.u32);
	// bl 0x880f52c8
	ctx.lr = 0x88112694;
	sub_880F52C8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x881126a4
	if (ctx.cr6.eq) goto loc_881126A4;
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// stw r11,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r11.u32);
loc_881126A4:
	// lis r30,-30671
	ctx.r30.s64 = -2010054656;
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// lis r10,16838
	ctx.r10.s64 = 1103495168;
	// addi r23,r11,9552
	ctx.r23.s64 = ctx.r11.s64 + 9552;
	// ori r29,r10,20077
	ctx.r29.u64 = ctx.r10.u64 | 20077;
	// lwz r11,4200(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4200);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// mullw r11,r11,r29
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r29.s32);
	// addi r28,r11,12345
	ctx.r28.s64 = ctx.r11.s64 + 12345;
	// stw r28,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r28.u32);
	// beq cr6,0x88112740
	if (ctx.cr6.eq) goto loc_88112740;
	// lis r9,14563
	ctx.r9.s64 = 954400768;
	// lhz r7,4200(r30)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4200);
	// addic. r10,r3,40
	ctx.xer.ca = ctx.r3.u32 > 4294967255;
	ctx.r10.s64 = ctx.r3.s64 + 40;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r27,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, ctx.r27.u32);
	// ori r6,r9,36409
	ctx.r6.u64 = ctx.r9.u64 | 36409;
	// addi r8,r3,36
	ctx.r8.s64 = ctx.r3.s64 + 36;
	// mulhwu r5,r7,r6
	ctx.r5.u64 = (uint64_t(ctx.r7.u32) * uint64_t(ctx.r6.u32)) >> 32;
	// rlwinm r11,r5,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r4,r11,r9
	ctx.r4.u64 = ctx.r11.u64 + ctx.r9.u64;
	// subf r11,r4,r7
	ctx.r11.s64 = ctx.r7.s64 - ctx.r4.s64;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// addi r7,r11,-4
	ctx.r7.s64 = ctx.r11.s64 + -4;
	// clrlwi r11,r7,23
	ctx.r11.u64 = ctx.r7.u32 & 0x1FF;
	// stw r11,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, ctx.r11.u32);
	// beq 0x88112724
	if (ctx.cr0.eq) goto loc_88112724;
	// addi r9,r11,128
	ctx.r9.s64 = ctx.r11.s64 + 128;
	// rlwinm r7,r9,2,21,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x7FC;
	// lwzx r6,r7,r23
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r23.u32);
	// rlwinm r5,r6,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r5,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r5.u32);
loc_88112724:
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8811273c
	if (ctx.cr6.eq) goto loc_8811273C;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r23
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r23.u32);
	// rlwinm r9,r10,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r9,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
loc_8811273C:
	// stw r27,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r27.u32);
loc_88112740:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r6,96(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// lwz r5,92(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// lwz r8,2332(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2332);
	// lwz r7,2328(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2328);
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// bl 0x880f5438
	ctx.lr = 0x8811275C;
	sub_880F5438(ctx, base);
	// lis r11,-13108
	ctx.r11.s64 = -859045888;
	// lis r10,-256
	ctx.r10.s64 = -16777216;
	// li r22,0
	ctx.r22.s64 = 0;
	// ori r26,r11,52429
	ctx.r26.u64 = ctx.r11.u64 | 52429;
	// ori r27,r10,65281
	ctx.r27.u64 = ctx.r10.u64 | 65281;
	// li r20,96
	ctx.r20.s64 = 96;
	// li r21,10
	ctx.r21.s64 = 10;
loc_88112778:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// mr r4,r19
	ctx.r4.u64 = ctx.r19.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r11,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r10.u32);
	// bl 0x880f52c8
	ctx.lr = 0x88112794;
	sub_880F52C8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x881127a4
	if (ctx.cr6.eq) goto loc_881127A4;
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// stw r11,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r11.u32);
loc_881127A4:
	// mullw r11,r28,r29
	ctx.r11.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r29.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r11,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r11.u32);
	// mullw r11,r11,r29
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r29.s32);
	// lhz r9,4200(r30)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4200);
	// mulhwu r8,r9,r26
	ctx.r8.u64 = (uint64_t(ctx.r9.u32) * uint64_t(ctx.r26.u32)) >> 32;
	// addi r28,r11,12345
	ctx.r28.s64 = ctx.r11.s64 + 12345;
	// rlwinm r11,r8,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0x3FFFFFFF;
	// stw r28,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r28.u32);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// subf r6,r7,r9
	ctx.r6.s64 = ctx.r9.s64 - ctx.r7.s64;
	// clrlwi r10,r6,16
	ctx.r10.u64 = ctx.r6.u32 & 0xFFFF;
	// beq cr6,0x8811285c
	if (ctx.cr6.eq) goto loc_8811285C;
	// lhz r7,4200(r30)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4200);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// mulhwu r6,r7,r27
	ctx.r6.u64 = (uint64_t(ctx.r7.u32) * uint64_t(ctx.r27.u32)) >> 32;
	// rlwinm r11,r6,24,8,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 24) & 0xFFFFFF;
	// subfic r10,r10,16
	ctx.xer.ca = ctx.r10.u32 <= 16;
	ctx.r10.s64 = 16 - ctx.r10.s64;
	// rlwinm r8,r11,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// stw r10,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, ctx.r10.u32);
	// addic. r9,r3,40
	ctx.xer.ca = ctx.r3.u32 > 4294967255;
	ctx.r9.s64 = ctx.r3.s64 + 40;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// add r5,r8,r11
	ctx.r5.u64 = ctx.r8.u64 + ctx.r11.u64;
	// addi r8,r3,36
	ctx.r8.s64 = ctx.r3.s64 + 36;
	// subf r4,r5,r7
	ctx.r4.s64 = ctx.r7.s64 - ctx.r5.s64;
	// extsh r11,r4
	ctx.r11.s64 = ctx.r4.s16;
	// addi r7,r11,-128
	ctx.r7.s64 = ctx.r11.s64 + -128;
	// clrlwi r11,r7,23
	ctx.r11.u64 = ctx.r7.u32 & 0x1FF;
	// stw r11,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, ctx.r11.u32);
	// beq 0x88112834
	if (ctx.cr0.eq) goto loc_88112834;
	// addi r7,r11,128
	ctx.r7.s64 = ctx.r11.s64 + 128;
	// rlwinm r6,r7,2,21,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x7FC;
	// lwzx r5,r6,r23
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r23.u32);
	// mullw r4,r5,r10
	ctx.r4.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r10.s32);
	// stw r4,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r4.u32);
loc_88112834:
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8811284c
	if (ctx.cr6.eq) goto loc_8811284C;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r23
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r23.u32);
	// mullw r7,r9,r10
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// stw r7,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
loc_8811284C:
	// addi r11,r22,2
	ctx.r11.s64 = ctx.r22.s64 + 2;
	// stw r20,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r20.u32);
	// stw r21,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r21.u32);
	// stw r11,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r11.u32);
loc_8811285C:
	// addi r22,r22,1
	ctx.r22.s64 = ctx.r22.s64 + 1;
	// cmpwi cr6,r22,2
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 2, ctx.xer);
	// blt cr6,0x88112778
	if (ctx.cr6.lt) goto loc_88112778;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lis r29,-30667
	ctx.r29.s64 = -2009792512;
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// mr r9,r21
	ctx.r9.u64 = ctx.r21.u64;
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// stw r8,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r8.u32);
	// stw r21,12380(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12380, ctx.r21.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r7,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r7.u32);
	// blt cr6,0x881128a0
	if (ctx.cr6.lt) goto loc_881128A0;
	// lwz r11,192(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 192);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x881128ac
	goto loc_881128AC;
loc_881128A0:
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 184);
	// lwz r11,168(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 168);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_881128AC:
	// lis r30,-30667
	ctx.r30.s64 = -2009792512;
	// addi r4,r11,-2
	ctx.r4.s64 = ctx.r11.s64 + -2;
	// li r3,10
	ctx.r3.s64 = 10;
	// stw r4,12376(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12376, ctx.r4.u32);
	// bl 0x880f8798
	ctx.lr = 0x881128C0;
	sub_880F8798(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x881128d0
	if (ctx.cr6.eq) goto loc_881128D0;
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// stb r11,24(r3)
	PPC_STORE_U8(ctx.r3.u32 + 24, ctx.r11.u8);
loc_881128D0:
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// lwz r11,-11984(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -11984);
	// lwz r8,84(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// cmpwi cr6,r8,1
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 1, ctx.xer);
	// bne cr6,0x881128fc
	if (!ctx.cr6.eq) goto loc_881128FC;
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88112948
	if (!ctx.cr6.eq) goto loc_88112948;
loc_881128FC:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r9,2
	ctx.r9.s64 = 2;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r3,2
	ctx.r3.s64 = 2;
	// stw r9,12380(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12380, ctx.r9.u32);
	// stw r10,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r10.u32);
	// stw r11,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r11.u32);
	// lwz r10,168(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 168);
	// lwz r11,184(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 184);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r4,r11,-1
	ctx.r4.s64 = ctx.r11.s64 + -1;
	// stw r4,12376(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12376, ctx.r4.u32);
	// bl 0x881607f8
	ctx.lr = 0x88112938;
	sub_881607F8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88112948
	if (ctx.cr6.eq) goto loc_88112948;
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
loc_88112948:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x88094220
	ctx.lr = 0x88112950;
	sub_88094220(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x88071184
	__restgprlr_19(ctx, base);
	return;
loc_8811295C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x88071184
	__restgprlr_19(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88112968"))) PPC_WEAK_FUNC(sub_88112968);
PPC_FUNC_IMPL(__imp__sub_88112968) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x88112970;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r5,-292
	ctx.r5.s64 = -19136512;
	// li r4,104
	ctx.r4.s64 = 104;
	// ori r5,r5,47768
	ctx.r5.u64 = ctx.r5.u64 | 47768;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x88112988;
	sub_88094290(ctx, base);
	// li r5,104
	ctx.r5.s64 = 104;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,2304(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2304);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x8811299C;
	sub_88073BD0(ctx, base);
	// li r27,0
	ctx.r27.s64 = 0;
	// stw r30,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r27,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r27.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x881556a0
	ctx.lr = 0x881129B4;
	sub_881556A0(ctx, base);
	// lis r11,-30703
	ctx.r11.s64 = -2012151808;
	// stw r3,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r3.u32);
	// li r28,1
	ctx.r28.s64 = 1;
	// addi r9,r11,9512
	ctx.r9.s64 = ctx.r11.s64 + 9512;
	// stw r31,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r31.u32);
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// stw r9,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r9.u32);
	// lwz r8,100(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// stw r28,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r28.u32);
	// lwz r9,100(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r11,28(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88112a00
	if (ctx.cr6.eq) goto loc_88112A00;
loc_881129E8:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88112abc
	if (ctx.cr6.eq) goto loc_88112ABC;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x881129e8
	if (!ctx.cr6.eq) goto loc_881129E8;
loc_88112A00:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_88112A04:
	// li r29,8
	ctx.r29.s64 = 8;
	// stw r28,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r28.u32);
	// addi r10,r31,4
	ctx.r10.s64 = ctx.r31.s64 + 4;
	// stw r29,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r29.u32);
	// li r8,120
	ctx.r8.s64 = 120;
	// stw r10,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r10.u32);
	// stw r29,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r29.u32);
	// stw r29,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r29.u32);
	// stw r29,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r29.u32);
	// lwz r11,100(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 100);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r7,r9,-1
	ctx.r7.s64 = ctx.r9.s64 + -1;
	// and r6,r7,r11
	ctx.r6.u64 = ctx.r7.u64 & ctx.r11.u64;
	// stw r6,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r6.u32);
	// stw r8,168(r30)
	PPC_STORE_U32(ctx.r30.u32 + 168, ctx.r8.u32);
	// lwz r5,88(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// cmplwi cr6,r5,1
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 1, ctx.xer);
	// bne cr6,0x88112a58
	if (!ctx.cr6.eq) goto loc_88112A58;
	// li r11,90
	ctx.r11.s64 = 90;
	// stw r11,168(r30)
	PPC_STORE_U32(ctx.r30.u32 + 168, ctx.r11.u32);
loc_88112A58:
	// lwz r11,32(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// lis r9,-30703
	ctx.r9.s64 = -2012151808;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r8,r9,7344
	ctx.r8.s64 = ctx.r9.s64 + 7344;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// lwz r7,36(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// stw r7,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r7.u32);
	// stw r8,76(r30)
	PPC_STORE_U32(ctx.r30.u32 + 76, ctx.r8.u32);
	// stw r28,96(r30)
	PPC_STORE_U32(ctx.r30.u32 + 96, ctx.r28.u32);
	// stw r27,80(r30)
	PPC_STORE_U32(ctx.r30.u32 + 80, ctx.r27.u32);
	// bl 0x88169750
	ctx.lr = 0x88112A84;
	sub_88169750(ctx, base);
	// lis r6,-30597
	ctx.r6.s64 = -2005204992;
	// li r5,2
	ctx.r5.s64 = 2;
	// stw r28,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r28.u32);
	// stw r5,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r5.u32);
	// lwz r11,-11984(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -11984);
	// lwz r11,84(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x88112ae0
	if (ctx.cr6.lt) goto loc_88112AE0;
	// beq cr6,0x88112ad4
	if (ctx.cr6.eq) goto loc_88112AD4;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x88112b00
	if (!ctx.cr6.lt) goto loc_88112B00;
	// lis r11,-30703
	ctx.r11.s64 = -2012151808;
	// addi r9,r11,7728
	ctx.r9.s64 = ctx.r11.s64 + 7728;
	// b 0x88112ae8
	goto loc_88112AE8;
loc_88112ABC:
	// lwz r10,24(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88112acc
	if (ctx.cr6.eq) goto loc_88112ACC;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_88112ACC:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x88112a04
	goto loc_88112A04;
loc_88112AD4:
	// lis r11,-30703
	ctx.r11.s64 = -2012151808;
	// addi r9,r11,8208
	ctx.r9.s64 = ctx.r11.s64 + 8208;
	// b 0x88112ae8
	goto loc_88112AE8;
loc_88112AE0:
	// lis r11,-30703
	ctx.r11.s64 = -2012151808;
	// addi r9,r11,8672
	ctx.r9.s64 = ctx.r11.s64 + 8672;
loc_88112AE8:
	// li r10,84
	ctx.r10.s64 = 84;
	// stw r29,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r29.u32);
	// stw r28,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r28.u32);
	// stw r28,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r28.u32);
	// stw r10,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r10.u32);
	// stw r9,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r9.u32);
loc_88112B00:
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// lis r10,-30703
	ctx.r10.s64 = -2012151808;
	// lis r9,-30703
	ctx.r9.s64 = -2012151808;
	// lis r8,-30703
	ctx.r8.s64 = -2012151808;
	// addi r7,r10,9096
	ctx.r7.s64 = ctx.r10.s64 + 9096;
	// addi r6,r9,7456
	ctx.r6.s64 = ctx.r9.s64 + 7456;
	// addi r5,r8,7392
	ctx.r5.s64 = ctx.r8.s64 + 7392;
	// stw r11,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// stw r7,64(r30)
	PPC_STORE_U32(ctx.r30.u32 + 64, ctx.r7.u32);
	// stw r6,68(r30)
	PPC_STORE_U32(ctx.r30.u32 + 68, ctx.r6.u32);
	// stw r5,84(r30)
	PPC_STORE_U32(ctx.r30.u32 + 84, ctx.r5.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88112B34"))) PPC_WEAK_FUNC(sub_88112B34);
PPC_FUNC_IMPL(__imp__sub_88112B34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88112B38"))) PPC_WEAK_FUNC(sub_88112B38);
PPC_FUNC_IMPL(__imp__sub_88112B38) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,172(r5)
	PPC_STORE_U32(ctx.r5.u32 + 172, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88112B48"))) PPC_WEAK_FUNC(sub_88112B48);
PPC_FUNC_IMPL(__imp__sub_88112B48) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r9,100(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 100);
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

__attribute__((alias("__imp__sub_88112B88"))) PPC_WEAK_FUNC(sub_88112B88);
PPC_FUNC_IMPL(__imp__sub_88112B88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x88112B90;
	__savegprlr_26(ctx, base);
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
	// blt cr6,0x88112bb4
	if (ctx.cr6.lt) goto loc_88112BB4;
	// lwz r11,188(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 188);
	// add r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x88112bc0
	goto loc_88112BC0;
loc_88112BB4:
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 184);
	// lwz r11,168(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 168);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_88112BC0:
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lis r28,-30667
	ctx.r28.s64 = -2009792512;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r27,-30667
	ctx.r27.s64 = -2009792512;
	// addi r29,r9,2
	ctx.r29.s64 = ctx.r9.s64 + 2;
	// li r3,5
	ctx.r3.s64 = 5;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r11,12364(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12372, ctx.r10.u32);
	// bl 0x880f52c8
	ctx.lr = 0x88112BE8;
	sub_880F52C8(ctx, base);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88112c60
	if (ctx.cr6.eq) goto loc_88112C60;
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// stw r11,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, ctx.r11.u32);
	// clrlwi r9,r11,23
	ctx.r9.u64 = ctx.r11.u32 & 0x1FF;
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r8,r10,9552
	ctx.r8.s64 = ctx.r10.s64 + 9552;
	// srawi r6,r7,2
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 2;
	// addi r7,r3,36
	ctx.r7.s64 = ctx.r3.s64 + 36;
	// addze r5,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r5.s64 = temp.s64;
	// addic. r11,r3,40
	ctx.xer.ca = ctx.r3.u32 > 4294967255;
	ctx.r11.s64 = ctx.r3.s64 + 40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r5,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, ctx.r5.u32);
	// rotlwi r10,r5,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// beq 0x88112c40
	if (ctx.cr0.eq) goto loc_88112C40;
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
loc_88112C40:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x88112c58
	if (ctx.cr6.eq) goto loc_88112C58;
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r8
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r8.u32);
	// mullw r8,r9,r10
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// stw r8,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r8.u32);
loc_88112C58:
	// li r11,128
	ctx.r11.s64 = 128;
	// stw r11,140(r30)
	PPC_STORE_U32(ctx.r30.u32 + 140, ctx.r11.u32);
loc_88112C60:
	// lwz r11,144(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// li r26,2
	ctx.r26.s64 = 2;
	// lwz r5,28(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88112c9c
	if (ctx.cr6.eq) goto loc_88112C9C;
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// srawi r9,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 2;
	// addze r4,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r4.s64 = temp.s64;
	// bl 0x880f5570
	ctx.lr = 0x88112C8C;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x88112cb4
	if (ctx.cr6.eq) goto loc_88112CB4;
	// stw r26,100(r30)
	PPC_STORE_U32(ctx.r30.u32 + 100, ctx.r26.u32);
	// b 0x88112cb4
	goto loc_88112CB4;
loc_88112C9C:
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x880f5570
	ctx.lr = 0x88112CA4;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x88112cb4
	if (ctx.cr6.eq) goto loc_88112CB4;
	// li r11,10
	ctx.r11.s64 = 10;
	// stw r11,100(r30)
	PPC_STORE_U32(ctx.r30.u32 + 100, ctx.r11.u32);
loc_88112CB4:
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lis r8,-30667
	ctx.r8.s64 = -2009792512;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r7,-30667
	ctx.r7.s64 = -2009792512;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,12364(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12372, ctx.r10.u32);
	// stw r9,12380(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12380, ctx.r9.u32);
	// stw r29,12376(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12376, ctx.r29.u32);
	// bl 0x880f52c8
	ctx.lr = 0x88112CE4;
	sub_880F52C8(ctx, base);
	// lwz r6,144(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq cr6,0x88112d5c
	if (ctx.cr6.eq) goto loc_88112D5C;
	// lis r7,-30671
	ctx.r7.s64 = -2010054656;
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lis r6,16838
	ctx.r6.s64 = 1103495168;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// ori r5,r6,20077
	ctx.r5.u64 = ctx.r6.u64 | 20077;
	// add r4,r11,r8
	ctx.r4.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lwz r10,4200(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4200);
	// lis r3,-3856
	ctx.r3.s64 = -252706816;
	// srawi r8,r4,2
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r4.s32 >> 2;
	// mullw r11,r10,r5
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r5.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// ori r6,r3,61681
	ctx.r6.u64 = ctx.r3.u64 | 61681;
	// stw r11,4200(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4200, ctx.r11.u32);
	// lhz r5,4200(r7)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r7.u32 + 4200);
	// mulhwu r4,r5,r6
	ctx.r4.u64 = (uint64_t(ctx.r5.u32) * uint64_t(ctx.r6.u32)) >> 32;
	// rlwinm r11,r4,28,4,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 28) & 0xFFFFFFF;
	// addze r4,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r4.s64 = temp.s64;
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r10,r11,r5
	ctx.r10.s64 = ctx.r5.s64 - ctx.r11.s64;
	// extsh r11,r10
	ctx.r11.s64 = ctx.r10.s16;
	// addi r7,r11,-8
	ctx.r7.s64 = ctx.r11.s64 + -8;
	// rlwinm r11,r7,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r5,r11,r9
	ctx.r5.u64 = ctx.r11.u64 + ctx.r9.u64;
	// b 0x88112db0
	goto loc_88112DB0;
loc_88112D5C:
	// lis r9,-30671
	ctx.r9.s64 = -2010054656;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lis r8,16838
	ctx.r8.s64 = 1103495168;
	// addi r4,r11,8
	ctx.r4.s64 = ctx.r11.s64 + 8;
	// ori r7,r8,20077
	ctx.r7.u64 = ctx.r8.u64 | 20077;
	// lis r6,-3856
	ctx.r6.s64 = -252706816;
	// lwz r11,4200(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4200);
	// ori r5,r6,61681
	ctx.r5.u64 = ctx.r6.u64 | 61681;
	// mullw r11,r11,r7
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r7.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// stw r11,4200(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4200, ctx.r11.u32);
	// lhz r8,4200(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4200);
	// mulhwu r7,r8,r5
	ctx.r7.u64 = (uint64_t(ctx.r8.u32) * uint64_t(ctx.r5.u32)) >> 32;
	// rlwinm r11,r7,28,4,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 28) & 0xFFFFFFF;
	// rlwinm r9,r11,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r6,r9,r11
	ctx.r6.u64 = ctx.r9.u64 + ctx.r11.u64;
	// subf r5,r6,r8
	ctx.r5.s64 = ctx.r8.s64 - ctx.r6.s64;
	// extsh r11,r5
	ctx.r11.s64 = ctx.r5.s16;
	// addi r9,r11,-8
	ctx.r9.s64 = ctx.r11.s64 + -8;
	// rlwinm r11,r9,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
loc_88112DB0:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880f5570
	ctx.lr = 0x88112DB8;
	sub_880F5570(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x88112dcc
	if (ctx.cr6.eq) goto loc_88112DCC;
	// li r11,80
	ctx.r11.s64 = 80;
	// stw r26,100(r30)
	PPC_STORE_U32(ctx.r30.u32 + 100, ctx.r26.u32);
	// stw r11,140(r30)
	PPC_STORE_U32(ctx.r30.u32 + 140, ctx.r11.u32);
loc_88112DCC:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,4360(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4360);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x88112dfc
	if (!ctx.cr6.eq) goto loc_88112DFC;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r8,4380(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4380);
	// lwz r7,4376(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4376);
	// lwz r6,4372(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4372);
	// lwz r5,4368(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4368);
	// lwz r4,12(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// bl 0x880f5438
	ctx.lr = 0x88112DFC;
	sub_880F5438(ctx, base);
loc_88112DFC:
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
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

__attribute__((alias("__imp__sub_88112E10"))) PPC_WEAK_FUNC(sub_88112E10);
PPC_FUNC_IMPL(__imp__sub_88112E10) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x88112E18;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// li r6,130
	ctx.r6.s64 = 130;
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// lwz r28,8(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r27,12(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r30,r11,13301
	ctx.r30.s64 = ctx.r11.s64 + 13301;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x881538c0
	ctx.lr = 0x88112E44;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88112e54
	if (ctx.cr6.eq) goto loc_88112E54;
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_88112E54:
	// li r6,210
	ctx.r6.s64 = 210;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x881538c0
	ctx.lr = 0x88112E68;
	sub_881538C0(ctx, base);
	// lis r30,-30597
	ctx.r30.s64 = -2005204992;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88112ea4
	if (ctx.cr6.eq) goto loc_88112EA4;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// oris r8,r9,547
	ctx.r8.u64 = ctx.r9.u64 | 35848192;
	// lwz r11,-11932(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -11932);
	// ori r8,r8,49152
	ctx.r8.u64 = ctx.r8.u64 | 49152;
	// addi r29,r11,1
	ctx.r29.s64 = ctx.r11.s64 + 1;
	// stw r10,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r10.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// lwz r7,80(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// stw r29,-11932(r30)
	PPC_STORE_U32(ctx.r30.u32 + -11932, ctx.r29.u32);
	// stw r7,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r7.u32);
	// b 0x88112ea8
	goto loc_88112EA8;
loc_88112EA4:
	// lwz r29,-11932(r30)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r30.u32 + -11932);
loc_88112EA8:
	// li r6,210
	ctx.r6.s64 = 210;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r3,13317
	ctx.r3.s64 = 13317;
	// bl 0x881538c0
	ctx.lr = 0x88112EBC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88112edc
	if (ctx.cr6.eq) goto loc_88112EDC;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r11,r29,1
	ctx.r11.s64 = ctx.r29.s64 + 1;
	// oris r9,r10,609
	ctx.r9.u64 = ctx.r10.u64 | 39911424;
	// stw r11,-11932(r30)
	PPC_STORE_U32(ctx.r30.u32 + -11932, ctx.r11.u32);
	// ori r9,r9,32768
	ctx.r9.u64 = ctx.r9.u64 | 32768;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
loc_88112EDC:
	// lis r11,128
	ctx.r11.s64 = 8388608;
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// ori r11,r11,32896
	ctx.r11.u64 = ctx.r11.u64 | 32896;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x88112f04
	if (!ctx.cr6.eq) goto loc_88112F04;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88112f10
	if (ctx.cr6.eq) goto loc_88112F10;
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_88112F04:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88112f10
	if (ctx.cr6.eq) goto loc_88112F10;
	// stw r10,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r10.u32);
loc_88112F10:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88112F18"))) PPC_WEAK_FUNC(sub_88112F18);
PPC_FUNC_IMPL(__imp__sub_88112F18) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x88112F20;
	__savegprlr_24(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// lwz r11,176(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 176);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x88112f50
	if (ctx.cr6.eq) goto loc_88112F50;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x88112f60
	if (!ctx.cr6.eq) goto loc_88112F60;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r11,-11904(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11904);
	// addi r11,r11,7000
	ctx.r11.s64 = ctx.r11.s64 + 7000;
	// b 0x88112f5c
	goto loc_88112F5C;
loc_88112F50:
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r11,-11904(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11904);
	// addi r11,r11,100
	ctx.r11.s64 = ctx.r11.s64 + 100;
loc_88112F5C:
	// stw r11,-11904(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11904, ctx.r11.u32);
loc_88112F60:
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// li r25,0
	ctx.r25.s64 = 0;
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88112f90
	if (ctx.cr6.eq) goto loc_88112F90;
loc_88112F78:
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// stw r25,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r25.u32);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88112f78
	if (!ctx.cr6.eq) goto loc_88112F78;
loc_88112F90:
	// lis r11,128
	ctx.r11.s64 = 8388608;
	// clrlwi r10,r10,20
	ctx.r10.u64 = ctx.r10.u32 & 0xFFF;
	// ori r9,r11,32896
	ctx.r9.u64 = ctx.r11.u64 | 32896;
	// rlwinm r10,r10,0,26,21
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFC3F;
	// li r26,1
	ctx.r26.s64 = 1;
	// stw r9,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r9.u32);
	// lis r30,-30667
	ctx.r30.s64 = -2009792512;
	// lis r29,-30667
	ctx.r29.s64 = -2009792512;
	// lis r28,-30667
	ctx.r28.s64 = -2009792512;
	// lis r27,-30667
	ctx.r27.s64 = -2009792512;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x88113038
	if (ctx.cr6.eq) goto loc_88113038;
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// lis r10,192
	ctx.r10.s64 = 12582912;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// ori r9,r10,49152
	ctx.r9.u64 = ctx.r10.u64 | 49152;
	// rlwinm r8,r11,0,30,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// stw r9,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r9.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x88113038
	if (ctx.cr6.eq) goto loc_88113038;
	// lwz r10,172(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 172);
	// lis r11,255
	ctx.r11.s64 = 16711680;
	// li r8,140
	ctx.r8.s64 = 140;
	// ori r9,r11,4112
	ctx.r9.u64 = ctx.r11.u64 | 4112;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// stw r9,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r9.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,140
	ctx.r4.s64 = 140;
	// stw r8,12376(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12376, ctx.r8.u32);
	// stw r11,12364(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r10.u32);
	// beq cr6,0x88113028
	if (ctx.cr6.eq) goto loc_88113028;
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x88113030
	goto loc_88113030;
loc_88113028:
	// mr r9,r25
	ctx.r9.u64 = ctx.r25.u64;
	// li r3,0
	ctx.r3.s64 = 0;
loc_88113030:
	// stw r9,12380(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12380, ctx.r9.u32);
	// bl 0x881607f8
	ctx.lr = 0x88113038;
	sub_881607F8(ctx, base);
loc_88113038:
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lwz r3,-11984(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11984);
	// lwz r10,1460(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1460);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x88113058
	if (!ctx.cr6.eq) goto loc_88113058;
	// lwz r11,1656(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1656);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88113070
	if (ctx.cr6.eq) goto loc_88113070;
loc_88113058:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88112b88
	ctx.lr = 0x88113060;
	sub_88112B88(ctx, base);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x88094220
	ctx.lr = 0x88113068;
	sub_88094220(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
loc_88113070:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,4360(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4360);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x881130e4
	if (ctx.cr6.eq) goto loc_881130E4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88112b88
	ctx.lr = 0x88113088;
	sub_88112B88(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,4360(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4360);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x881130d4
	if (!ctx.cr6.eq) goto loc_881130D4;
	// lwz r11,4368(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4368);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x881130d4
	if (!ctx.cr6.eq) goto loc_881130D4;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r8,140
	ctx.r8.s64 = 140;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,140
	ctx.r4.s64 = 140;
	// stw r25,12380(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12380, ctx.r25.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r8,12376(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12376, ctx.r8.u32);
	// mr r9,r25
	ctx.r9.u64 = ctx.r25.u64;
	// stw r11,12364(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12372, ctx.r10.u32);
	// bl 0x881607f8
	ctx.lr = 0x881130D4;
	sub_881607F8(ctx, base);
loc_881130D4:
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x88094220
	ctx.lr = 0x881130DC;
	sub_88094220(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
loc_881130E4:
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lis r8,-30643
	ctx.r8.s64 = -2008219648;
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// lwz r7,24(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// clrlwi r11,r4,23
	ctx.r11.u64 = ctx.r4.u32 & 0x1FF;
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r6,r10,9552
	ctx.r6.s64 = ctx.r10.s64 + 9552;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r5,r11,128
	ctx.r5.s64 = ctx.r11.s64 + 128;
	// rlwinm r30,r4,2,21,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x7FC;
	// lwz r11,26272(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 26272);
	// rlwinm r5,r5,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x7FC;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwzx r11,r30,r6
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r6.u32);
	// lwzx r8,r5,r6
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r6.u32);
	// mullw r11,r11,r7
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r7.s32);
	// mullw r8,r8,r7
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r7.s32);
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stw r5,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r5.u32);
	// stw r6,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r6.u32);
	// beq cr6,0x88113144
	if (ctx.cr6.eq) goto loc_88113144;
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
	// b 0x88113154
	goto loc_88113154;
loc_88113144:
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// addi r11,r11,51
	ctx.r11.s64 = ctx.r11.s64 + 51;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r3
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
loc_88113154:
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lis r8,64
	ctx.r8.s64 = 4194304;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add. r10,r6,r8
	ctx.r10.u64 = ctx.r6.u64 + ctx.r8.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r5,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r5.u32);
	// lwz r11,100(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 100);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// and r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 & ctx.r11.u64;
	// ble 0x881131c4
	if (!ctx.cr0.gt) goto loc_881131C4;
	// lis r9,128
	ctx.r9.s64 = 8388608;
	// lis r30,320
	ctx.r30.s64 = 20971520;
	// subf r10,r9,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r9.s64;
	// cmpw cr6,r10,r30
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r30.s32, ctx.xer);
	// bge cr6,0x881131c4
	if (!ctx.cr6.lt) goto loc_881131C4;
	// addi r11,r11,55
	ctx.r11.s64 = ctx.r11.s64 + 55;
	// lis r10,-40
	ctx.r10.s64 = -2621440;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r3
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r3.u32);
	// add r3,r11,r5
	ctx.r3.u64 = ctx.r11.u64 + ctx.r5.u64;
	// add r11,r3,r8
	ctx.r11.u64 = ctx.r3.u64 + ctx.r8.u64;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x881131c4
	if (!ctx.cr6.gt) goto loc_881131C4;
	// lis r10,280
	ctx.r10.s64 = 18350080;
	// subf r9,r9,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r9.s64;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x881131e8
	if (ctx.cr6.lt) goto loc_881131E8;
loc_881131C4:
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x881131ec
	if (ctx.cr6.eq) goto loc_881131EC;
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// stw r25,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r25.u32);
	// bl 0x88094220
	ctx.lr = 0x881131E0;
	sub_88094220(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
loc_881131E8:
	// stw r26,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r26.u32);
loc_881131EC:
	// lwz r11,144(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x881132a8
	if (ctx.cr6.eq) goto loc_881132A8;
	// lwz r11,132(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r11.u32);
	// bge 0x88113260
	if (!ctx.cr0.lt) goto loc_88113260;
	// lwz r9,120(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// addi r10,r7,-4
	ctx.r10.s64 = ctx.r7.s64 + -4;
	// stw r11,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r11.u32);
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r10,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// subf r11,r8,r4
	ctx.r11.s64 = ctx.r4.s64 - ctx.r8.s64;
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// ble cr6,0x8811323c
	if (!ctx.cr6.gt) goto loc_8811323C;
	// cmpwi cr6,r11,248
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 248, ctx.xer);
	// bgt cr6,0x8811324c
	if (ctx.cr6.gt) goto loc_8811324C;
	// li r11,248
	ctx.r11.s64 = 248;
	// b 0x88113248
	goto loc_88113248;
loc_8811323C:
	// cmpwi cr6,r11,264
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 264, ctx.xer);
	// blt cr6,0x8811324c
	if (ctx.cr6.lt) goto loc_8811324C;
	// li r11,264
	ctx.r11.s64 = 264;
loc_88113248:
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
loc_8811324C:
	// cmpwi cr6,r10,26
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 26, ctx.xer);
	// bgt cr6,0x88113260
	if (ctx.cr6.gt) goto loc_88113260;
	// li r11,26
	ctx.r11.s64 = 26;
	// stw r25,144(r31)
	PPC_STORE_U32(ctx.r31.u32 + 144, ctx.r25.u32);
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
loc_88113260:
	// lwz r11,176(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 176);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x881132a8
	if (!ctx.cr6.eq) goto loc_881132A8;
	// lwz r11,104(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// bge 0x881132a8
	if (!ctx.cr0.lt) goto loc_881132A8;
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// li r10,64
	ctx.r10.s64 = 64;
	// li r9,60
	ctx.r9.s64 = 60;
	// stw r25,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r25.u32);
	// neg r8,r11
	ctx.r8.s64 = -ctx.r11.s64;
	// stw r26,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r26.u32);
	// li r7,-50
	ctx.r7.s64 = -50;
	// stw r26,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r26.u32);
	// li r4,45
	ctx.r4.s64 = 45;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x88094728
	ctx.lr = 0x881132A8;
	sub_88094728(ctx, base);
loc_881132A8:
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// bge 0x88113304
	if (!ctx.cr0.lt) goto loc_88113304;
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// lwz r10,120(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// ble cr6,0x881132f0
	if (!ctx.cr6.gt) goto loc_881132F0;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// blt cr6,0x88113304
	if (ctx.cr6.lt) goto loc_88113304;
	// stw r25,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r25.u32);
	// stw r25,172(r31)
	PPC_STORE_U32(ctx.r31.u32 + 172, ctx.r25.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
loc_881132F0:
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// bge 0x88113304
	if (!ctx.cr0.lt) goto loc_88113304;
	// li r11,15
	ctx.r11.s64 = 15;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
loc_88113304:
	// stw r25,172(r31)
	PPC_STORE_U32(ctx.r31.u32 + 172, ctx.r25.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88113310"))) PPC_WEAK_FUNC(sub_88113310);
PPC_FUNC_IMPL(__imp__sub_88113310) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x88113318;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r5,-292
	ctx.r5.s64 = -19136512;
	// li r4,180
	ctx.r4.s64 = 180;
	// ori r5,r5,47768
	ctx.r5.u64 = ctx.r5.u64 | 47768;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x88113330;
	sub_88094290(ctx, base);
	// li r5,180
	ctx.r5.s64 = 180;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,2304(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2304);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x88113344;
	sub_88073BD0(ctx, base);
	// li r29,0
	ctx.r29.s64 = 0;
	// stw r30,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// li r4,21
	ctx.r4.s64 = 21;
	// stw r29,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r29.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x881556a0
	ctx.lr = 0x8811335C;
	sub_881556A0(ctx, base);
	// lis r11,-30703
	ctx.r11.s64 = -2012151808;
	// stw r3,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r3.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r9,r11,11064
	ctx.r9.s64 = ctx.r11.s64 + 11064;
	// stw r31,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r31.u32);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// stw r9,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r9.u32);
	// lwz r8,100(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// stw r6,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r6.u32);
	// lwz r9,100(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r11,28(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x881133a8
	if (ctx.cr6.eq) goto loc_881133A8;
loc_88113390:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88113528
	if (ctx.cr6.eq) goto loc_88113528;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88113390
	if (!ctx.cr6.eq) goto loc_88113390;
loc_881133A8:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_881133AC:
	// lis r5,-30671
	ctx.r5.s64 = -2010054656;
	// li r9,3
	ctx.r9.s64 = 3;
	// addi r8,r31,8
	ctx.r8.s64 = ctx.r31.s64 + 8;
	// li r4,61
	ctx.r4.s64 = 61;
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// lis r3,16838
	ctx.r3.s64 = 1103495168;
	// stw r9,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r9.u32);
	// stw r9,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r9.u32);
	// li r7,130
	ctx.r7.s64 = 130;
	// stw r9,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r9.u32);
	// ori r10,r3,20077
	ctx.r10.u64 = ctx.r3.u64 | 20077;
	// stw r4,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r4.u32);
	// lis r3,-13108
	ctx.r3.s64 = -859045888;
	// stw r8,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r8.u32);
	// lis r8,-30597
	ctx.r8.s64 = -2005204992;
	// lwz r11,4200(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4200);
	// ori r4,r3,52429
	ctx.r4.u64 = ctx.r3.u64 | 52429;
	// stw r7,168(r30)
	PPC_STORE_U32(ctx.r30.u32 + 168, ctx.r7.u32);
	// li r7,1024
	ctx.r7.s64 = 1024;
	// mullw r11,r11,r10
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// li r3,2
	ctx.r3.s64 = 2;
	// stw r11,4200(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4200, ctx.r11.u32);
	// mullw r10,r11,r10
	ctx.r10.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// lhz r27,4200(r5)
	ctx.r27.u64 = PPC_LOAD_U16(ctx.r5.u32 + 4200);
	// lwz r11,32(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// rotlwi r9,r11,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r11,36(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// rotlwi r28,r11,0
	ctx.r28.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// addi r11,r10,12345
	ctx.r11.s64 = ctx.r10.s64 + 12345;
	// stw r9,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r9.u32);
	// mulhwu r9,r27,r4
	ctx.r9.u64 = (uint64_t(ctx.r27.u32) * uint64_t(ctx.r4.u32)) >> 32;
	// stw r11,4200(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4200, ctx.r11.u32);
	// lhz r10,4200(r5)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r5.u32 + 4200);
	// stw r28,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r28.u32);
	// rlwinm r11,r9,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r11,r9
	ctx.r5.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r11,100(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 100);
	// subf r4,r5,r27
	ctx.r4.s64 = ctx.r27.s64 - ctx.r5.s64;
	// clrlwi r5,r10,29
	ctx.r5.u64 = ctx.r10.u32 & 0x7;
	// extsh r9,r4
	ctx.r9.s64 = ctx.r4.s16;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// and r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 & ctx.r11.u64;
	// lwz r11,-11984(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -11984);
	// addi r10,r9,16
	ctx.r10.s64 = ctx.r9.s64 + 16;
	// stw r4,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r4.u32);
	// stw r10,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// lwz r9,132(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 132);
	// lwz r8,2304(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2304);
	// stw r8,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// lwz r4,136(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 136);
	// stw r4,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r4.u32);
	// lwz r10,140(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 140);
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r10,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r10.u32);
	// lwz r8,144(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 144);
	// stw r8,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r8.u32);
	// stw r5,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r5.u32);
	// stw r3,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r3.u32);
	// stw r29,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r29.u32);
	// stw r29,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r29.u32);
	// stw r9,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r9.u32);
	// stw r29,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r29.u32);
	// stw r29,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r29.u32);
	// stw r29,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r29.u32);
	// stw r6,144(r31)
	PPC_STORE_U32(ctx.r31.u32 + 144, ctx.r6.u32);
	// stw r7,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r7.u32);
	// lwz r6,84(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// cmpwi cr6,r6,2
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 2, ctx.xer);
	// stw r6,176(r31)
	PPC_STORE_U32(ctx.r31.u32 + 176, ctx.r6.u32);
	// bne cr6,0x881134f4
	if (!ctx.cr6.eq) goto loc_881134F4;
	// li r11,8
	ctx.r11.s64 = 8;
	// stw r29,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r29.u32);
	// li r10,14
	ctx.r10.s64 = 14;
	// stw r11,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r11.u32);
	// stw r10,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r10.u32);
	// stw r11,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r11.u32);
loc_881134F4:
	// lis r11,-30703
	ctx.r11.s64 = -2012151808;
	// stw r7,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r7.u32);
	// lis r10,-30703
	ctx.r10.s64 = -2012151808;
	// stw r29,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r29.u32);
	// lis r9,-30703
	ctx.r9.s64 = -2012151808;
	// addi r8,r11,12056
	ctx.r8.s64 = ctx.r11.s64 + 12056;
	// addi r7,r10,11792
	ctx.r7.s64 = ctx.r10.s64 + 11792;
	// addi r6,r9,11080
	ctx.r6.s64 = ctx.r9.s64 + 11080;
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
loc_88113528:
	// lwz r10,24(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88113538
	if (ctx.cr6.eq) goto loc_88113538;
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
loc_88113538:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// b 0x881133ac
	goto loc_881133AC;
}

__attribute__((alias("__imp__sub_88113540"))) PPC_WEAK_FUNC(sub_88113540);
PPC_FUNC_IMPL(__imp__sub_88113540) {
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

__attribute__((alias("__imp__sub_88113560"))) PPC_WEAK_FUNC(sub_88113560);
PPC_FUNC_IMPL(__imp__sub_88113560) {
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
	// lwz r4,2304(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r6,r4,4
	ctx.r6.s64 = ctx.r4.s64 + 4;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// lwz r3,16(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// bl 0x880940d8
	ctx.lr = 0x88113588;
	sub_880940D8(ctx, base);
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lis r11,-160
	ctx.r11.s64 = -10485760;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bgt cr6,0x881135a0
	if (ctx.cr6.gt) goto loc_881135A0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88094220
	ctx.lr = 0x881135A0;
	sub_88094220(ctx, base);
loc_881135A0:
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

__attribute__((alias("__imp__sub_881135B4"))) PPC_WEAK_FUNC(sub_881135B4);
PPC_FUNC_IMPL(__imp__sub_881135B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881135B8"))) PPC_WEAK_FUNC(sub_881135B8);
PPC_FUNC_IMPL(__imp__sub_881135B8) {
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
	// lwz r4,2304(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r6,r4,4
	ctx.r6.s64 = ctx.r4.s64 + 4;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// lwz r3,8(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// bl 0x880940d8
	ctx.lr = 0x881135E0;
	sub_880940D8(ctx, base);
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lis r11,-128
	ctx.r11.s64 = -8388608;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bgt cr6,0x881135f8
	if (ctx.cr6.gt) goto loc_881135F8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88094220
	ctx.lr = 0x881135F8;
	sub_88094220(ctx, base);
loc_881135F8:
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

__attribute__((alias("__imp__sub_8811360C"))) PPC_WEAK_FUNC(sub_8811360C);
PPC_FUNC_IMPL(__imp__sub_8811360C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88113610"))) PPC_WEAK_FUNC(sub_88113610);
PPC_FUNC_IMPL(__imp__sub_88113610) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r10,26272(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26272);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r10,-11984(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11984);
	// lwz r10,208(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 208);
	// add r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r7,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// lwz r6,2300(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2300);
	// lwz r10,296(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 296);
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r5,r10,r9
	ctx.r5.u64 = ctx.r10.u64 + ctx.r9.u64;
	// srawi r4,r5,2
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x3) != 0);
	ctx.r4.s64 = ctx.r5.s32 >> 2;
	// addze r3,r4
	temp.s64 = ctx.r4.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r3.s64 = temp.s64;
	// subf. r10,r3,r8
	ctx.r10.s64 = ctx.r8.s64 - ctx.r3.s64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// bgt 0x8811366c
	if (ctx.cr0.gt) goto loc_8811366C;
	// addis r10,r10,320
	ctx.r10.s64 = ctx.r10.s64 + 20971520;
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
loc_8811366C:
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 96);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r10,96(r11)
	PPC_STORE_U32(ctx.r11.u32 + 96, ctx.r10.u32);
	// cmpwi cr6,r10,255
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 255, ctx.xer);
	// blelr cr6
	if (!ctx.cr6.gt) return;
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 100);
	// li r9,255
	ctx.r9.s64 = 255;
	// addi r8,r10,4
	ctx.r8.s64 = ctx.r10.s64 + 4;
	// stw r9,96(r11)
	PPC_STORE_U32(ctx.r11.u32 + 96, ctx.r9.u32);
	// stw r8,100(r11)
	PPC_STORE_U32(ctx.r11.u32 + 100, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88113698"))) PPC_WEAK_FUNC(sub_88113698);
PPC_FUNC_IMPL(__imp__sub_88113698) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071130
	ctx.lr = 0x881136A0;
	__savegprlr_18(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x881137f8
	if (!ctx.cr6.gt) goto loc_881137F8;
	// lis r10,-30667
	ctx.r10.s64 = -2009792512;
	// lis r30,-30671
	ctx.r30.s64 = -2010054656;
	// mr r18,r11
	ctx.r18.u64 = ctx.r11.u64;
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// lis r9,-3856
	ctx.r9.s64 = -252706816;
	// stw r6,12376(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12376, ctx.r6.u32);
	// lis r10,16838
	ctx.r10.s64 = 1103495168;
	// lis r8,112
	ctx.r8.s64 = 7340032;
	// lwz r28,4200(r30)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4200);
	// ori r29,r10,20077
	ctx.r29.u64 = ctx.r10.u64 | 20077;
	// ori r27,r9,61681
	ctx.r27.u64 = ctx.r9.u64 | 61681;
	// li r19,2
	ctx.r19.s64 = 2;
	// li r20,112
	ctx.r20.s64 = 112;
	// ori r22,r8,28784
	ctx.r22.u64 = ctx.r8.u64 | 28784;
	// lis r25,-30667
	ctx.r25.s64 = -2009792512;
	// lis r24,-30667
	ctx.r24.s64 = -2009792512;
	// lis r23,-30667
	ctx.r23.s64 = -2009792512;
	// addi r21,r11,9552
	ctx.r21.s64 = ctx.r11.s64 + 9552;
loc_88113704:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r9,4(r26)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// add r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stw r11,12364(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12372, ctx.r10.u32);
	// stw r3,12380(r23)
	PPC_STORE_U32(ctx.r23.u32 + 12380, ctx.r3.u32);
	// bl 0x880f52c8
	ctx.lr = 0x88113730;
	sub_880F52C8(ctx, base);
	// mullw r11,r28,r29
	ctx.r11.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r29.s32);
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addi r8,r11,12345
	ctx.r8.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r8,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r8.u32);
	// lhz r7,4200(r30)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4200);
	// mulhwu r6,r7,r27
	ctx.r6.u64 = (uint64_t(ctx.r7.u32) * uint64_t(ctx.r27.u32)) >> 32;
	// rlwinm r11,r6,28,4,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 28) & 0xFFFFFFF;
	// rlwinm r9,r11,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r5,r9,r11
	ctx.r5.u64 = ctx.r9.u64 + ctx.r11.u64;
	// subf r11,r5,r7
	ctx.r11.s64 = ctx.r7.s64 - ctx.r5.s64;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// beq cr6,0x881137b8
	if (ctx.cr6.eq) goto loc_881137B8;
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
	// beq 0x881137a0
	if (ctx.cr0.eq) goto loc_881137A0;
	// addi r6,r11,128
	ctx.r6.s64 = ctx.r11.s64 + 128;
	// rlwinm r5,r6,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// lwzx r6,r5,r21
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r21.u32);
	// mullw r5,r6,r9
	ctx.r5.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r9.s32);
	// stw r5,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r5.u32);
loc_881137A0:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x881137b8
	if (ctx.cr6.eq) goto loc_881137B8;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r21
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r21.u32);
	// mullw r9,r10,r9
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// stw r9,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r9.u32);
loc_881137B8:
	// mullw r11,r8,r29
	ctx.r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r29.s32);
	// addi r28,r11,12345
	ctx.r28.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r28,4200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4200, ctx.r28.u32);
	// beq cr6,0x881137ec
	if (ctx.cr6.eq) goto loc_881137EC;
	// lhz r11,4200(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + 4200);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// rlwinm r11,r11,1,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x2;
	// stw r19,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r19.u32);
	// stw r20,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r20.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r22,160(r3)
	PPC_STORE_U32(ctx.r3.u32 + 160, ctx.r22.u32);
	// stw r11,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r11.u32);
loc_881137EC:
	// addic. r18,r18,-1
	ctx.xer.ca = ctx.r18.u32 > 0;
	ctx.r18.s64 = ctx.r18.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r18.s32, 0, ctx.xer);
	// addi r31,r31,36
	ctx.r31.s64 = ctx.r31.s64 + 36;
	// bne 0x88113704
	if (!ctx.cr0.eq) goto loc_88113704;
loc_881137F8:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x88071180
	__restgprlr_18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88113800"))) PPC_WEAK_FUNC(sub_88113800);
PPC_FUNC_IMPL(__imp__sub_88113800) {
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
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r4,2304(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,-11900(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11900);
	// cmplwi cr6,r11,200
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 200, ctx.xer);
	// beq cr6,0x88113834
	if (ctx.cr6.eq) goto loc_88113834;
	// addi r11,r11,200
	ctx.r11.s64 = ctx.r11.s64 + 200;
	// stw r11,-11900(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11900, ctx.r11.u32);
loc_88113834:
	// lwz r11,12(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// lis r9,-30714
	ctx.r9.s64 = -2012872704;
	// lwz r7,8(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// addi r6,r4,4
	ctx.r6.s64 = ctx.r4.s64 + 4;
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// addi r9,r9,9552
	ctx.r9.s64 = ctx.r9.s64 + 9552;
	// lwz r8,4(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// addi r5,r11,128
	ctx.r5.s64 = ctx.r11.s64 + 128;
	// lwz r3,20(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r30,r5,2,21,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x7FC;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// lwzx r11,r11,r9
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r9.u32);
	// lwzx r30,r30,r9
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r9.u32);
	// mullw r9,r11,r7
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r7.s32);
	// mullw r11,r30,r7
	ctx.r11.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r7.s32);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r9,r11,r8
	ctx.r9.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stw r10,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
	// stw r9,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r9.u32);
	// bl 0x880940d8
	ctx.lr = 0x8811388C;
	sub_880940D8(ctx, base);
	// lwz r5,28(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// lis r8,-30643
	ctx.r8.s64 = -2008219648;
	// rlwinm r10,r5,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r11,r8,32424
	ctx.r11.s64 = ctx.r8.s64 + 32424;
	// lis r7,-340
	ctx.r7.s64 = -22282240;
	// addi r6,r11,4
	ctx.r6.s64 = ctx.r11.s64 + 4;
	// lwz r3,0(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stwx r3,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + ctx.r11.u32, ctx.r3.u32);
	// lwz r9,4(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r8,28(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// rlwinm r5,r8,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// stwx r9,r5,r6
	PPC_STORE_U32(ctx.r5.u32 + ctx.r6.u32, ctx.r9.u32);
	// lwz r4,4(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmpw cr6,r4,r7
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r7.s32, ctx.xer);
	// bgt cr6,0x881138d0
	if (ctx.cr6.gt) goto loc_881138D0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88094220
	ctx.lr = 0x881138D0;
	sub_88094220(ctx, base);
loc_881138D0:
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

__attribute__((alias("__imp__sub_881138E8"))) PPC_WEAK_FUNC(sub_881138E8);
PPC_FUNC_IMPL(__imp__sub_881138E8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071138
	ctx.lr = 0x881138F0;
	__savegprlr_20(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// li r10,11
	ctx.r10.s64 = 11;
	// addi r23,r11,32512
	ctx.r23.s64 = ctx.r11.s64 + 32512;
	// li r22,0
	ctx.r22.s64 = 0;
	// lwz r20,-11984(r9)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r9.u32 + -11984);
	// addi r11,r23,-4
	ctx.r11.s64 = ctx.r23.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lwz r21,176(r20)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r20.u32 + 176);
loc_88113918:
	// stw r22,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r22.u32);
	// stwu r22,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r22.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x88113918
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88113918;
	// lwz r11,1860(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 1860);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8811395c
	if (!ctx.cr6.eq) goto loc_8811395C;
	// lwz r11,1888(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 1888);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8811395c
	if (ctx.cr6.eq) goto loc_8811395C;
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// li r11,21845
	ctx.r11.s64 = 21845;
	// addi r9,r10,32688
	ctx.r9.s64 = ctx.r10.s64 + 32688;
	// lis r10,64
	ctx.r10.s64 = 4194304;
	// stw r11,64(r9)
	PPC_STORE_U32(ctx.r9.u32 + 64, ctx.r11.u32);
	// stw r10,68(r9)
	PPC_STORE_U32(ctx.r9.u32 + 68, ctx.r10.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x88071188
	__restgprlr_20(ctx, base);
	return;
loc_8811395C:
	// lis r7,-30643
	ctx.r7.s64 = -2008219648;
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// lis r9,-30679
	ctx.r9.s64 = -2010578944;
	// lis r8,-30643
	ctx.r8.s64 = -2008219648;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r24,26428(r7)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r7.u32 + 26428);
	// lis r25,64
	ctx.r25.s64 = 4194304;
	// cmpwi cr6,r21,0
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// addi r30,r10,32248
	ctx.r30.s64 = ctx.r10.s64 + 32248;
	// addi r29,r9,-15272
	ctx.r29.s64 = ctx.r9.s64 + -15272;
	// addi r27,r8,32600
	ctx.r27.s64 = ctx.r8.s64 + 32600;
	// addi r31,r11,32688
	ctx.r31.s64 = ctx.r11.s64 + 32688;
	// blt cr6,0x88113a70
	if (ctx.cr6.lt) goto loc_88113A70;
	// cmpwi cr6,r21,132
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 132, ctx.xer);
	// bgt cr6,0x88113a70
	if (ctx.cr6.gt) goto loc_88113A70;
	// cmpwi cr6,r21,84
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 84, ctx.xer);
	// blt cr6,0x88113b50
	if (ctx.cr6.lt) goto loc_88113B50;
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpw cr6,r9,r25
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r25.s32, ctx.xer);
	// bge cr6,0x881139e8
	if (!ctx.cr6.lt) goto loc_881139E8;
	// clrlwi r11,r24,30
	ctx.r11.u64 = ctx.r24.u32 & 0x3;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x881139e8
	if (!ctx.cr6.eq) goto loc_881139E8;
	// lwz r9,28(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 28);
	// li r10,7
	ctx.r10.s64 = 7;
	// li r6,50
	ctx.r6.s64 = 50;
	// stw r22,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r22.u32);
	// li r5,80
	ctx.r5.s64 = 80;
	// stw r10,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// li r4,127
	ctx.r4.s64 = 127;
	// li r3,6
	ctx.r3.s64 = 6;
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// stw r9,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r9.u32);
	// bl 0x880e3240
	ctx.lr = 0x881139E4;
	sub_880E3240(ctx, base);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
loc_881139E8:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x88113a30
	if (!ctx.cr6.eq) goto loc_88113A30;
	// lwz r11,176(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 176);
	// addi r3,r29,-23808
	ctx.r3.s64 = ctx.r29.s64 + -23808;
	// lwz r10,180(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 180);
	// li r6,79
	ctx.r6.s64 = 79;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addis r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 2097152;
	// li r4,19
	ctx.r4.s64 = 19;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x88113698
	ctx.lr = 0x88113A18;
	sub_88113698(ctx, base);
	// addi r3,r29,-23112
	ctx.r3.s64 = ctx.r29.s64 + -23112;
	// li r6,78
	ctx.r6.s64 = 78;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x88113698
	ctx.lr = 0x88113A2C;
	sub_88113698(ctx, base);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
loc_88113A30:
	// lwz r11,4(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// addi r11,r11,-16384
	ctx.r11.s64 = ctx.r11.s64 + -16384;
	// rlwinm r10,r11,0,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFF0000;
	// stw r11,4(r27)
	PPC_STORE_U32(ctx.r27.u32 + 4, ctx.r11.u32);
	// stw r10,4(r23)
	PPC_STORE_U32(ctx.r23.u32 + 4, ctx.r10.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88113a54
	if (ctx.cr6.eq) goto loc_88113A54;
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// stw r11,4(r27)
	PPC_STORE_U32(ctx.r27.u32 + 4, ctx.r11.u32);
loc_88113A54:
	// addi r11,r9,16384
	ctx.r11.s64 = ctx.r9.s64 + 16384;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// cmpw cr6,r11,r25
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r25.s32, ctx.xer);
	// blt cr6,0x88113b50
	if (ctx.cr6.lt) goto loc_88113B50;
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// stw r25,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r25.u32);
	// b 0x88113b50
	goto loc_88113B50;
loc_88113A70:
	// cmpwi cr6,r21,212
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 212, ctx.xer);
	// bgt cr6,0x88113b50
	if (ctx.cr6.gt) goto loc_88113B50;
	// cmpwi cr6,r21,160
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 160, ctx.xer);
	// blt cr6,0x88113b50
	if (ctx.cr6.lt) goto loc_88113B50;
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmpw cr6,r9,r25
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r25.s32, ctx.xer);
	// bge cr6,0x88113ac8
	if (!ctx.cr6.lt) goto loc_88113AC8;
	// clrlwi r11,r24,30
	ctx.r11.u64 = ctx.r24.u32 & 0x3;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88113ac8
	if (!ctx.cr6.eq) goto loc_88113AC8;
	// lwz r9,28(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 28);
	// li r10,7
	ctx.r10.s64 = 7;
	// li r6,50
	ctx.r6.s64 = 50;
	// stw r22,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r22.u32);
	// li r5,80
	ctx.r5.s64 = 80;
	// stw r10,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// li r4,127
	ctx.r4.s64 = 127;
	// li r3,6
	ctx.r3.s64 = 6;
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// stw r9,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r9.u32);
	// bl 0x880e3240
	ctx.lr = 0x88113AC4;
	sub_880E3240(ctx, base);
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
loc_88113AC8:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x88113b14
	if (!ctx.cr6.eq) goto loc_88113B14;
	// lwz r11,176(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 176);
	// addi r3,r29,-22920
	ctx.r3.s64 = ctx.r29.s64 + -22920;
	// lwz r10,180(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 180);
	// li r6,79
	ctx.r6.s64 = 79;
	// addis r11,r11,-12
	ctx.r11.s64 = ctx.r11.s64 + -786432;
	// addis r10,r10,-8
	ctx.r10.s64 = ctx.r10.s64 + -524288;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// li r4,19
	ctx.r4.s64 = 19;
	// bl 0x88113698
	ctx.lr = 0x88113AFC;
	sub_88113698(ctx, base);
	// addi r3,r29,-22224
	ctx.r3.s64 = ctx.r29.s64 + -22224;
	// li r6,78
	ctx.r6.s64 = 78;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x88113698
	ctx.lr = 0x88113B10;
	sub_88113698(ctx, base);
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
loc_88113B14:
	// lwz r11,12(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// addi r11,r11,-16384
	ctx.r11.s64 = ctx.r11.s64 + -16384;
	// rlwinm r10,r11,0,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFF0000;
	// stw r11,12(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12, ctx.r11.u32);
	// stw r10,12(r23)
	PPC_STORE_U32(ctx.r23.u32 + 12, ctx.r10.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88113b38
	if (ctx.cr6.eq) goto loc_88113B38;
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// stw r11,12(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12, ctx.r11.u32);
loc_88113B38:
	// addi r11,r9,16384
	ctx.r11.s64 = ctx.r9.s64 + 16384;
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// cmpw cr6,r11,r25
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r25.s32, ctx.xer);
	// blt cr6,0x88113b50
	if (ctx.cr6.lt) goto loc_88113B50;
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// stw r25,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r25.u32);
loc_88113B50:
	// lis r28,192
	ctx.r28.s64 = 12582912;
	// cmpwi cr6,r21,372
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 372, ctx.xer);
	// blt cr6,0x88113bd0
	if (ctx.cr6.lt) goto loc_88113BD0;
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmpw cr6,r9,r28
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r28.s32, ctx.xer);
	// bge cr6,0x88113bd0
	if (!ctx.cr6.lt) goto loc_88113BD0;
	// lwz r11,16(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 16);
	// addi r11,r11,-21845
	ctx.r11.s64 = ctx.r11.s64 + -21845;
	// rlwinm r10,r11,0,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFF0000;
	// stw r11,16(r27)
	PPC_STORE_U32(ctx.r27.u32 + 16, ctx.r11.u32);
	// stw r10,16(r23)
	PPC_STORE_U32(ctx.r23.u32 + 16, ctx.r10.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88113b8c
	if (ctx.cr6.eq) goto loc_88113B8C;
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// stw r11,16(r27)
	PPC_STORE_U32(ctx.r27.u32 + 16, ctx.r11.u32);
loc_88113B8C:
	// addi r11,r9,21845
	ctx.r11.s64 = ctx.r9.s64 + 21845;
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// cmpw cr6,r11,r28
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r28.s32, ctx.xer);
	// blt cr6,0x88113bd0
	if (ctx.cr6.lt) goto loc_88113BD0;
	// lwz r8,20(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// li r9,5
	ctx.r9.s64 = 5;
	// li r6,50
	ctx.r6.s64 = 50;
	// stw r28,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r28.u32);
	// li r5,80
	ctx.r5.s64 = 80;
	// stw r22,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r22.u32);
	// li r4,127
	ctx.r4.s64 = 127;
	// stw r9,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r9.u32);
	// li r3,6
	ctx.r3.s64 = 6;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stw r8,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r8.u32);
	// mr r10,r22
	ctx.r10.u64 = ctx.r22.u64;
	// bl 0x880e3240
	ctx.lr = 0x88113BD0;
	sub_880E3240(ctx, base);
loc_88113BD0:
	// cmpwi cr6,r21,420
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 420, ctx.xer);
	// blt cr6,0x88113c4c
	if (ctx.cr6.lt) goto loc_88113C4C;
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmpw cr6,r9,r28
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r28.s32, ctx.xer);
	// bge cr6,0x88113c4c
	if (!ctx.cr6.lt) goto loc_88113C4C;
	// lwz r11,24(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 24);
	// addi r11,r11,21845
	ctx.r11.s64 = ctx.r11.s64 + 21845;
	// rlwinm r10,r11,0,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFF0000;
	// stw r11,24(r27)
	PPC_STORE_U32(ctx.r27.u32 + 24, ctx.r11.u32);
	// stw r10,24(r23)
	PPC_STORE_U32(ctx.r23.u32 + 24, ctx.r10.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88113c08
	if (ctx.cr6.eq) goto loc_88113C08;
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// stw r11,24(r27)
	PPC_STORE_U32(ctx.r27.u32 + 24, ctx.r11.u32);
loc_88113C08:
	// addi r11,r9,21845
	ctx.r11.s64 = ctx.r9.s64 + 21845;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// cmpw cr6,r11,r28
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r28.s32, ctx.xer);
	// blt cr6,0x88113c4c
	if (ctx.cr6.lt) goto loc_88113C4C;
	// lwz r8,20(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// li r9,5
	ctx.r9.s64 = 5;
	// li r6,50
	ctx.r6.s64 = 50;
	// stw r28,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r28.u32);
	// li r5,80
	ctx.r5.s64 = 80;
	// stw r22,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r22.u32);
	// li r4,127
	ctx.r4.s64 = 127;
	// stw r9,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r9.u32);
	// li r3,6
	ctx.r3.s64 = 6;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stw r8,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r8.u32);
	// mr r10,r22
	ctx.r10.u64 = ctx.r22.u64;
	// bl 0x880e3240
	ctx.lr = 0x88113C4C;
	sub_880E3240(ctx, base);
loc_88113C4C:
	// lis r26,200
	ctx.r26.s64 = 13107200;
	// cmpwi cr6,r21,472
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 472, ctx.xer);
	// blt cr6,0x88113cfc
	if (ctx.cr6.lt) goto loc_88113CFC;
	// lwz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r7,80
	ctx.r7.s64 = 5242880;
	// cmpw cr6,r8,r7
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, ctx.xer);
	// bge cr6,0x88113cfc
	if (!ctx.cr6.lt) goto loc_88113CFC;
	// lwz r11,36(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 36);
	// lwz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// subf r11,r9,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r9.s64;
	// rlwinm r10,r11,0,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFF0000;
	// stw r11,36(r27)
	PPC_STORE_U32(ctx.r27.u32 + 36, ctx.r11.u32);
	// stw r10,36(r23)
	PPC_STORE_U32(ctx.r23.u32 + 36, ctx.r10.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88113c90
	if (ctx.cr6.eq) goto loc_88113C90;
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// stw r11,36(r27)
	PPC_STORE_U32(ctx.r27.u32 + 36, ctx.r11.u32);
loc_88113C90:
	// add r11,r9,r8
	ctx.r11.u64 = ctx.r9.u64 + ctx.r8.u64;
	// addi r10,r9,8192
	ctx.r10.s64 = ctx.r9.s64 + 8192;
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// cmpw cr6,r11,r7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r7.s32, ctx.xer);
	// stw r10,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r10.u32);
	// blt cr6,0x88113cfc
	if (ctx.cr6.lt) goto loc_88113CFC;
	// lis r10,120
	ctx.r10.s64 = 7864320;
	// stw r26,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r26.u32);
	// stw r7,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r7.u32);
	// addi r3,r29,-25368
	ctx.r3.s64 = ctx.r29.s64 + -25368;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// li r6,52
	ctx.r6.s64 = 52;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,18
	ctx.r4.s64 = 18;
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
	// bl 0x88113698
	ctx.lr = 0x88113CD0;
	sub_88113698(ctx, base);
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// li r10,5
	ctx.r10.s64 = 5;
	// stw r22,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r22.u32);
	// li r6,50
	ctx.r6.s64 = 50;
	// li r5,80
	ctx.r5.s64 = 80;
	// stw r10,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// li r4,127
	ctx.r4.s64 = 127;
	// li r3,6
	ctx.r3.s64 = 6;
	// lwz r11,20(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// stw r11,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r11.u32);
	// bl 0x880e3240
	ctx.lr = 0x88113CFC;
	sub_880E3240(ctx, base);
loc_88113CFC:
	// lis r28,48
	ctx.r28.s64 = 3145728;
	// cmpwi cr6,r21,492
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 492, ctx.xer);
	// blt cr6,0x88113de0
	if (ctx.cr6.lt) goto loc_88113DE0;
	// lwz r8,52(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// cmpw cr6,r8,r25
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r25.s32, ctx.xer);
	// bge cr6,0x88113de0
	if (!ctx.cr6.lt) goto loc_88113DE0;
	// clrlwi r11,r24,30
	ctx.r11.u64 = ctx.r24.u32 & 0x3;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88113d50
	if (!ctx.cr6.eq) goto loc_88113D50;
	// lwz r9,28(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 28);
	// li r10,7
	ctx.r10.s64 = 7;
	// li r6,50
	ctx.r6.s64 = 50;
	// stw r22,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r22.u32);
	// li r5,80
	ctx.r5.s64 = 80;
	// stw r10,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// li r4,127
	ctx.r4.s64 = 127;
	// li r3,6
	ctx.r3.s64 = 6;
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// stw r9,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r9.u32);
	// bl 0x880e3240
	ctx.lr = 0x88113D4C;
	sub_880E3240(ctx, base);
	// lwz r8,52(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
loc_88113D50:
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x88113d88
	if (!ctx.cr6.eq) goto loc_88113D88;
	// lwz r11,224(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 224);
	// addi r3,r29,-22032
	ctx.r3.s64 = ctx.r29.s64 + -22032;
	// lwz r10,228(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 228);
	// li r6,79
	ctx.r6.s64 = 79;
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// add r10,r10,r25
	ctx.r10.u64 = ctx.r10.u64 + ctx.r25.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// li r4,25
	ctx.r4.s64 = 25;
	// bl 0x88113698
	ctx.lr = 0x88113D84;
	sub_88113698(ctx, base);
	// lwz r8,52(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
loc_88113D88:
	// lwz r11,52(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r10,r11,0,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFF0000;
	// stw r11,52(r27)
	PPC_STORE_U32(ctx.r27.u32 + 52, ctx.r11.u32);
	// stw r10,52(r23)
	PPC_STORE_U32(ctx.r23.u32 + 52, ctx.r10.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88113db0
	if (ctx.cr6.eq) goto loc_88113DB0;
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// stw r11,52(r27)
	PPC_STORE_U32(ctx.r27.u32 + 52, ctx.r11.u32);
loc_88113DB0:
	// addi r11,r9,1024
	ctx.r11.s64 = ctx.r9.s64 + 1024;
	// add r10,r9,r8
	ctx.r10.u64 = ctx.r9.u64 + ctx.r8.u64;
	// stw r11,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// cmpwi cr6,r11,21845
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 21845, ctx.xer);
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// blt cr6,0x88113dd0
	if (ctx.cr6.lt) goto loc_88113DD0;
	// li r11,21845
	ctx.r11.s64 = 21845;
	// stw r11,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
loc_88113DD0:
	// cmpw cr6,r10,r25
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r25.s32, ctx.xer);
	// blt cr6,0x88113de0
	if (ctx.cr6.lt) goto loc_88113DE0;
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// stw r25,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r25.u32);
loc_88113DE0:
	// cmpwi cr6,r21,538
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 538, ctx.xer);
	// blt cr6,0x88113ec0
	if (ctx.cr6.lt) goto loc_88113EC0;
	// lwz r8,60(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// cmpw cr6,r8,r25
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r25.s32, ctx.xer);
	// bge cr6,0x88113ec0
	if (!ctx.cr6.lt) goto loc_88113EC0;
	// clrlwi r11,r24,30
	ctx.r11.u64 = ctx.r24.u32 & 0x3;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88113e30
	if (!ctx.cr6.eq) goto loc_88113E30;
	// lwz r9,28(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 28);
	// li r10,7
	ctx.r10.s64 = 7;
	// li r6,50
	ctx.r6.s64 = 50;
	// stw r22,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r22.u32);
	// li r5,80
	ctx.r5.s64 = 80;
	// stw r10,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// li r4,127
	ctx.r4.s64 = 127;
	// li r3,6
	ctx.r3.s64 = 6;
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// stw r9,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r9.u32);
	// bl 0x880e3240
	ctx.lr = 0x88113E2C;
	sub_880E3240(ctx, base);
	// lwz r8,60(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
loc_88113E30:
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x88113e68
	if (!ctx.cr6.eq) goto loc_88113E68;
	// lwz r11,232(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 232);
	// addi r3,r29,-22032
	ctx.r3.s64 = ctx.r29.s64 + -22032;
	// lwz r10,236(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 236);
	// li r6,79
	ctx.r6.s64 = 79;
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// add r10,r10,r25
	ctx.r10.u64 = ctx.r10.u64 + ctx.r25.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// li r4,25
	ctx.r4.s64 = 25;
	// bl 0x88113698
	ctx.lr = 0x88113E64;
	sub_88113698(ctx, base);
	// lwz r8,60(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
loc_88113E68:
	// lwz r11,60(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 60);
	// lwz r9,56(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r10,r11,0,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFF0000;
	// stw r11,60(r27)
	PPC_STORE_U32(ctx.r27.u32 + 60, ctx.r11.u32);
	// stw r10,60(r23)
	PPC_STORE_U32(ctx.r23.u32 + 60, ctx.r10.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88113e90
	if (ctx.cr6.eq) goto loc_88113E90;
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// stw r11,60(r27)
	PPC_STORE_U32(ctx.r27.u32 + 60, ctx.r11.u32);
loc_88113E90:
	// addi r11,r9,1024
	ctx.r11.s64 = ctx.r9.s64 + 1024;
	// add r10,r9,r8
	ctx.r10.u64 = ctx.r9.u64 + ctx.r8.u64;
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// cmpwi cr6,r11,21845
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 21845, ctx.xer);
	// stw r10,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r10.u32);
	// blt cr6,0x88113eb0
	if (ctx.cr6.lt) goto loc_88113EB0;
	// li r11,21845
	ctx.r11.s64 = 21845;
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
loc_88113EB0:
	// cmpw cr6,r10,r25
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r25.s32, ctx.xer);
	// blt cr6,0x88113ec0
	if (ctx.cr6.lt) goto loc_88113EC0;
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// stw r25,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r25.u32);
loc_88113EC0:
	// cmpwi cr6,r21,584
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 584, ctx.xer);
	// blt cr6,0x88113fa0
	if (ctx.cr6.lt) goto loc_88113FA0;
	// lwz r8,68(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// cmpw cr6,r8,r25
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r25.s32, ctx.xer);
	// bge cr6,0x88113fa0
	if (!ctx.cr6.lt) goto loc_88113FA0;
	// clrlwi r11,r24,30
	ctx.r11.u64 = ctx.r24.u32 & 0x3;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88113f10
	if (!ctx.cr6.eq) goto loc_88113F10;
	// lwz r9,28(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 28);
	// li r10,7
	ctx.r10.s64 = 7;
	// li r6,50
	ctx.r6.s64 = 50;
	// stw r22,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r22.u32);
	// li r5,80
	ctx.r5.s64 = 80;
	// stw r10,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// li r4,127
	ctx.r4.s64 = 127;
	// li r3,6
	ctx.r3.s64 = 6;
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// stw r9,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r9.u32);
	// bl 0x880e3240
	ctx.lr = 0x88113F0C;
	sub_880E3240(ctx, base);
	// lwz r8,68(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
loc_88113F10:
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x88113f48
	if (!ctx.cr6.eq) goto loc_88113F48;
	// lwz r11,240(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 240);
	// addi r3,r29,-21120
	ctx.r3.s64 = ctx.r29.s64 + -21120;
	// lwz r10,244(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 244);
	// li r6,79
	ctx.r6.s64 = 79;
	// addis r11,r11,-40
	ctx.r11.s64 = ctx.r11.s64 + -2621440;
	// add r10,r10,r25
	ctx.r10.u64 = ctx.r10.u64 + ctx.r25.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// li r4,20
	ctx.r4.s64 = 20;
	// bl 0x88113698
	ctx.lr = 0x88113F44;
	sub_88113698(ctx, base);
	// lwz r8,68(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
loc_88113F48:
	// lwz r11,68(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 68);
	// lwz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r10,r11,0,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFF0000;
	// stw r11,68(r27)
	PPC_STORE_U32(ctx.r27.u32 + 68, ctx.r11.u32);
	// stw r10,68(r23)
	PPC_STORE_U32(ctx.r23.u32 + 68, ctx.r10.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88113f70
	if (ctx.cr6.eq) goto loc_88113F70;
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// stw r11,68(r27)
	PPC_STORE_U32(ctx.r27.u32 + 68, ctx.r11.u32);
loc_88113F70:
	// addi r11,r9,1024
	ctx.r11.s64 = ctx.r9.s64 + 1024;
	// add r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// cmpwi cr6,r11,21845
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 21845, ctx.xer);
	// stw r10,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r10.u32);
	// blt cr6,0x88113f90
	if (ctx.cr6.lt) goto loc_88113F90;
	// li r11,21845
	ctx.r11.s64 = 21845;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
loc_88113F90:
	// cmpw cr6,r10,r25
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r25.s32, ctx.xer);
	// blt cr6,0x88113fa0
	if (ctx.cr6.lt) goto loc_88113FA0;
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// stw r25,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r25.u32);
loc_88113FA0:
	// lis r28,100
	ctx.r28.s64 = 6553600;
	// cmpwi cr6,r21,544
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 544, ctx.xer);
	// blt cr6,0x881140bc
	if (ctx.cr6.lt) goto loc_881140BC;
	// lwz r8,76(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// cmpw cr6,r8,r28
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r28.s32, ctx.xer);
	// bge cr6,0x881140bc
	if (!ctx.cr6.lt) goto loc_881140BC;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x88114018
	if (!ctx.cr6.eq) goto loc_88114018;
	// lwz r11,248(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 248);
	// addi r3,r29,-20400
	ctx.r3.s64 = ctx.r29.s64 + -20400;
	// lwz r10,252(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 252);
	// li r6,79
	ctx.r6.s64 = 79;
	// addis r11,r11,-24
	ctx.r11.s64 = ctx.r11.s64 + -1572864;
	// addis r10,r10,-112
	ctx.r10.s64 = ctx.r10.s64 + -7340032;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// li r4,13
	ctx.r4.s64 = 13;
	// bl 0x88113698
	ctx.lr = 0x88113FEC;
	sub_88113698(ctx, base);
	// addi r3,r29,-19920
	ctx.r3.s64 = ctx.r29.s64 + -19920;
	// li r6,78
	ctx.r6.s64 = 78;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x88113698
	ctx.lr = 0x88114000;
	sub_88113698(ctx, base);
	// li r6,50
	ctx.r6.s64 = 50;
	// li r5,80
	ctx.r5.s64 = 80;
	// li r4,128
	ctx.r4.s64 = 128;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x880e3240
	ctx.lr = 0x88114014;
	sub_880E3240(ctx, base);
	// lwz r8,76(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
loc_88114018:
	// lwz r11,76(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 76);
	// lwz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// subf r11,r9,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r9.s64;
	// rlwinm r10,r11,0,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFF0000;
	// stw r11,76(r27)
	PPC_STORE_U32(ctx.r27.u32 + 76, ctx.r11.u32);
	// stw r10,76(r23)
	PPC_STORE_U32(ctx.r23.u32 + 76, ctx.r10.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88114040
	if (ctx.cr6.eq) goto loc_88114040;
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// stw r11,76(r27)
	PPC_STORE_U32(ctx.r27.u32 + 76, ctx.r11.u32);
loc_88114040:
	// add r11,r9,r8
	ctx.r11.u64 = ctx.r9.u64 + ctx.r8.u64;
	// addi r10,r9,4096
	ctx.r10.s64 = ctx.r9.s64 + 4096;
	// stw r11,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// cmpw cr6,r11,r28
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r28.s32, ctx.xer);
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// blt cr6,0x881140bc
	if (ctx.cr6.lt) goto loc_881140BC;
	// lis r10,-8
	ctx.r10.s64 = -524288;
	// stw r28,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r28.u32);
	// lwz r9,224(r20)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r20.u32 + 224);
	// addi r3,r29,-24720
	ctx.r3.s64 = ctx.r29.s64 + -24720;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// stw r26,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r26.u32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// li r6,52
	ctx.r6.s64 = 52;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,15
	ctx.r4.s64 = 15;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// bl 0x88113698
	ctx.lr = 0x88114088;
	sub_88113698(ctx, base);
	// lis r7,72
	ctx.r7.s64 = 4718592;
	// addi r3,r29,-24168
	ctx.r3.s64 = ctx.r29.s64 + -24168;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// li r6,79
	ctx.r6.s64 = 79;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x88113698
	ctx.lr = 0x881140A4;
	sub_88113698(ctx, base);
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// li r10,5
	ctx.r10.s64 = 5;
	// stw r22,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r22.u32);
	// stw r10,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// lwz r11,20(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// stw r11,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r11.u32);
loc_881140BC:
	// cmpwi cr6,r21,587
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 587, ctx.xer);
	// blt cr6,0x881141d4
	if (ctx.cr6.lt) goto loc_881141D4;
	// lwz r8,84(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmpw cr6,r8,r28
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r28.s32, ctx.xer);
	// bge cr6,0x881141d4
	if (!ctx.cr6.lt) goto loc_881141D4;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x88114130
	if (!ctx.cr6.eq) goto loc_88114130;
	// lwz r11,256(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 256);
	// addi r3,r29,-19728
	ctx.r3.s64 = ctx.r29.s64 + -19728;
	// lwz r10,260(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 260);
	// li r6,79
	ctx.r6.s64 = 79;
	// addis r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 1048576;
	// subf r10,r25,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r25.s64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// li r4,14
	ctx.r4.s64 = 14;
	// bl 0x88113698
	ctx.lr = 0x88114104;
	sub_88113698(ctx, base);
	// addi r3,r29,-19224
	ctx.r3.s64 = ctx.r29.s64 + -19224;
	// li r6,78
	ctx.r6.s64 = 78;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x88113698
	ctx.lr = 0x88114118;
	sub_88113698(ctx, base);
	// li r6,50
	ctx.r6.s64 = 50;
	// li r5,80
	ctx.r5.s64 = 80;
	// li r4,128
	ctx.r4.s64 = 128;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x880e3240
	ctx.lr = 0x8811412C;
	sub_880E3240(ctx, base);
	// lwz r8,84(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
loc_88114130:
	// lwz r11,84(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 84);
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// subf r11,r9,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r9.s64;
	// rlwinm r10,r11,0,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFF0000;
	// stw r11,84(r27)
	PPC_STORE_U32(ctx.r27.u32 + 84, ctx.r11.u32);
	// stw r10,84(r23)
	PPC_STORE_U32(ctx.r23.u32 + 84, ctx.r10.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88114158
	if (ctx.cr6.eq) goto loc_88114158;
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// stw r11,84(r27)
	PPC_STORE_U32(ctx.r27.u32 + 84, ctx.r11.u32);
loc_88114158:
	// add r11,r9,r8
	ctx.r11.u64 = ctx.r9.u64 + ctx.r8.u64;
	// addi r10,r9,4096
	ctx.r10.s64 = ctx.r9.s64 + 4096;
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// cmpw cr6,r11,r28
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r28.s32, ctx.xer);
	// stw r10,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r10.u32);
	// blt cr6,0x881141d4
	if (ctx.cr6.lt) goto loc_881141D4;
	// lis r10,248
	ctx.r10.s64 = 16252928;
	// stw r28,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r28.u32);
	// lwz r9,224(r20)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r20.u32 + 224);
	// addi r3,r29,-24720
	ctx.r3.s64 = ctx.r29.s64 + -24720;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// stw r26,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r26.u32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// li r6,52
	ctx.r6.s64 = 52;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,15
	ctx.r4.s64 = 15;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// bl 0x88113698
	ctx.lr = 0x881141A0;
	sub_88113698(ctx, base);
	// lis r7,104
	ctx.r7.s64 = 6815744;
	// addi r3,r29,-24168
	ctx.r3.s64 = ctx.r29.s64 + -24168;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// li r6,79
	ctx.r6.s64 = 79;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x88113698
	ctx.lr = 0x881141BC;
	sub_88113698(ctx, base);
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// li r10,5
	ctx.r10.s64 = 5;
	// stw r22,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r22.u32);
	// stw r10,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// lwz r11,20(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// stw r11,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r11.u32);
loc_881141D4:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x88071188
	__restgprlr_20(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_881141DC"))) PPC_WEAK_FUNC(sub_881141DC);
PPC_FUNC_IMPL(__imp__sub_881141DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881141E0"))) PPC_WEAK_FUNC(sub_881141E0);
PPC_FUNC_IMPL(__imp__sub_881141E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807112c
	ctx.lr = 0x881141E8;
	__savegprlr_17(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r28,2304(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r11,-32640
	ctx.r11.s64 = -2139095040;
	// lis r20,40
	ctx.r20.s64 = 2621440;
	// ori r23,r11,32897
	ctx.r23.u64 = ctx.r11.u64 | 32897;
	// lis r21,32
	ctx.r21.s64 = 2097152;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r11,96(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 96);
	// lwz r9,4(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// subf r27,r20,r10
	ctx.r27.s64 = ctx.r10.s64 - ctx.r20.s64;
	// cmpwi cr6,r11,255
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 255, ctx.xer);
	// add r10,r9,r21
	ctx.r10.u64 = ctx.r9.u64 + ctx.r21.u64;
	// blt cr6,0x88114240
	if (ctx.cr6.lt) goto loc_88114240;
	// lwz r11,100(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 100);
	// addi r11,r11,255
	ctx.r11.s64 = ctx.r11.s64 + 255;
	// mulhwu r9,r11,r23
	ctx.r9.u64 = (uint64_t(ctx.r11.u32) * uint64_t(ctx.r23.u32)) >> 32;
	// rlwinm r8,r9,24,8,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 24) & 0xFFFFFF;
	// mulli r7,r8,510
	ctx.r7.s64 = ctx.r8.s64 * 510;
	// subf r11,r7,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r7.s64;
	// cmplwi cr6,r11,255
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 255, ctx.xer);
	// blt cr6,0x88114240
	if (ctx.cr6.lt) goto loc_88114240;
	// subfic r11,r11,510
	ctx.xer.ca = ctx.r11.u32 <= 510;
	ctx.r11.s64 = 510 - ctx.r11.s64;
loc_88114240:
	// lis r25,-30597
	ctx.r25.s64 = -2005204992;
	// lis r19,320
	ctx.r19.s64 = 20971520;
	// lis r22,256
	ctx.r22.s64 = 16777216;
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// subf r30,r19,r10
	ctx.r30.s64 = ctx.r10.s64 - ctx.r19.s64;
	// lwz r31,-11932(r25)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r25.u32 + -11932);
	// add r24,r27,r22
	ctx.r24.u64 = ctx.r27.u64 + ctx.r22.u64;
	// li r26,2
	ctx.r26.s64 = 2;
	// lis r17,120
	ctx.r17.s64 = 7864320;
	// lis r18,64
	ctx.r18.s64 = 4194304;
loc_88114268:
	// li r6,109
	ctx.r6.s64 = 109;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// li r3,1335
	ctx.r3.s64 = 1335;
	// bl 0x881538c0
	ctx.lr = 0x8811427C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x881142b4
	if (ctx.cr6.eq) goto loc_881142B4;
	// srawi r11,r29,1
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r29.s32 >> 1;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// lwz r8,12(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addze r7,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r7.s64 = temp.s64;
	// lwz r6,16(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// rlwimi r9,r7,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r7.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// or r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// stw r6,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r6.u32);
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
loc_881142B4:
	// li r6,109
	ctx.r6.s64 = 109;
	// add r5,r30,r17
	ctx.r5.u64 = ctx.r30.u64 + ctx.r17.u64;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// li r3,1336
	ctx.r3.s64 = 1336;
	// bl 0x881538c0
	ctx.lr = 0x881142C8;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88114304
	if (ctx.cr6.eq) goto loc_88114304;
	// srawi r11,r29,1
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r29.s32 >> 1;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// lwz r8,12(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addze r7,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r7.s64 = temp.s64;
	// lwz r6,16(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// rlwimi r9,r7,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r7.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r31,-11932(r25)
	PPC_STORE_U32(ctx.r25.u32 + -11932, ctx.r31.u32);
	// or r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// stw r6,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r6.u32);
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
loc_88114304:
	// li r6,109
	ctx.r6.s64 = 109;
	// subf r5,r18,r30
	ctx.r5.s64 = ctx.r30.s64 - ctx.r18.s64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// li r3,1337
	ctx.r3.s64 = 1337;
	// bl 0x881538c0
	ctx.lr = 0x88114318;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88114354
	if (ctx.cr6.eq) goto loc_88114354;
	// srawi r11,r29,1
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r29.s32 >> 1;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// lwz r8,12(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addze r7,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r7.s64 = temp.s64;
	// lwz r6,16(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// rlwimi r9,r7,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r7.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r31,-11932(r25)
	PPC_STORE_U32(ctx.r25.u32 + -11932, ctx.r31.u32);
	// or r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// stw r6,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r6.u32);
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
loc_88114354:
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// add r30,r30,r19
	ctx.r30.u64 = ctx.r30.u64 + ctx.r19.u64;
	// bne 0x88114268
	if (!ctx.cr0.eq) goto loc_88114268;
	// lwz r11,100(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 100);
	// lwz r10,4(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// srawi r9,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 1;
	// lwz r8,0(r28)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// stw r31,-11932(r25)
	PPC_STORE_U32(ctx.r25.u32 + -11932, ctx.r31.u32);
	// subf r10,r21,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r21.s64;
	// addze r11,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r11.s64 = temp.s64;
	// subf r28,r20,r8
	ctx.r28.s64 = ctx.r8.s64 - ctx.r20.s64;
	// mulhwu r7,r11,r23
	ctx.r7.u64 = (uint64_t(ctx.r11.u32) * uint64_t(ctx.r23.u32)) >> 32;
	// rlwinm r6,r7,24,8,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 24) & 0xFFFFFF;
	// mulli r5,r6,510
	ctx.r5.s64 = ctx.r6.s64 * 510;
	// subf r29,r5,r11
	ctx.r29.s64 = ctx.r11.s64 - ctx.r5.s64;
	// cmplwi cr6,r29,255
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 255, ctx.xer);
	// blt cr6,0x8811439c
	if (ctx.cr6.lt) goto loc_8811439C;
	// subfic r29,r29,510
	ctx.xer.ca = ctx.r29.u32 <= 510;
	ctx.r29.s64 = 510 - ctx.r29.s64;
loc_8811439C:
	// subf r30,r19,r10
	ctx.r30.s64 = ctx.r10.s64 - ctx.r19.s64;
	// add r26,r28,r22
	ctx.r26.u64 = ctx.r28.u64 + ctx.r22.u64;
	// li r27,3
	ctx.r27.s64 = 3;
loc_881143A8:
	// li r6,109
	ctx.r6.s64 = 109;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r3,1335
	ctx.r3.s64 = 1335;
	// bl 0x881538c0
	ctx.lr = 0x881143BC;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x881143f4
	if (ctx.cr6.eq) goto loc_881143F4;
	// srawi r11,r29,1
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r29.s32 >> 1;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// lwz r8,12(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addze r7,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r7.s64 = temp.s64;
	// lwz r6,16(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// rlwimi r9,r7,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r7.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// or r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// stw r6,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r6.u32);
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
loc_881143F4:
	// li r6,109
	ctx.r6.s64 = 109;
	// add r5,r30,r17
	ctx.r5.u64 = ctx.r30.u64 + ctx.r17.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// li r3,1336
	ctx.r3.s64 = 1336;
	// bl 0x881538c0
	ctx.lr = 0x88114408;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88114444
	if (ctx.cr6.eq) goto loc_88114444;
	// srawi r11,r29,1
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r29.s32 >> 1;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// lwz r8,12(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addze r7,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r7.s64 = temp.s64;
	// lwz r6,16(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// rlwimi r9,r7,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r7.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r31,-11932(r25)
	PPC_STORE_U32(ctx.r25.u32 + -11932, ctx.r31.u32);
	// or r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// stw r6,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r6.u32);
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
loc_88114444:
	// li r6,109
	ctx.r6.s64 = 109;
	// subf r5,r18,r30
	ctx.r5.s64 = ctx.r30.s64 - ctx.r18.s64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r3,1337
	ctx.r3.s64 = 1337;
	// bl 0x881538c0
	ctx.lr = 0x88114458;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88114494
	if (ctx.cr6.eq) goto loc_88114494;
	// srawi r11,r29,1
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r29.s32 >> 1;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,545
	ctx.r9.s64 = 35717120;
	// lwz r8,12(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addze r7,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r7.s64 = temp.s64;
	// lwz r6,16(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// rlwimi r9,r7,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r7.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r31,-11932(r25)
	PPC_STORE_U32(ctx.r25.u32 + -11932, ctx.r31.u32);
	// or r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// stw r6,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r6.u32);
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
loc_88114494:
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// add r30,r30,r19
	ctx.r30.u64 = ctx.r30.u64 + ctx.r19.u64;
	// bne 0x881143a8
	if (!ctx.cr0.eq) goto loc_881143A8;
	// stw r31,-11932(r25)
	PPC_STORE_U32(ctx.r25.u32 + -11932, ctx.r31.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8807117c
	__restgprlr_17(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_881144AC"))) PPC_WEAK_FUNC(sub_881144AC);
PPC_FUNC_IMPL(__imp__sub_881144AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881144B0"))) PPC_WEAK_FUNC(sub_881144B0);
PPC_FUNC_IMPL(__imp__sub_881144B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x881144B8;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r9,2300(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2300);
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// lwz r25,2304(r3)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r28,r10,32688
	ctx.r28.s64 = ctx.r10.s64 + 32688;
	// addi r24,r11,32424
	ctx.r24.s64 = ctx.r11.s64 + 32424;
	// lwz r8,156(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 156);
	// lwz r7,160(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
	// srawi r6,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 1;
	// lwz r11,0(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r5,4(r25)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r25.u32 + 4);
	// addze r4,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r4.s64 = temp.s64;
	// lwz r3,20(r25)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r25.u32 + 20);
	// srawi r10,r7,1
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r7.s32 >> 1;
	// subf r30,r4,r11
	ctx.r30.s64 = ctx.r11.s64 - ctx.r4.s64;
	// addze r9,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r9.s64 = temp.s64;
	// cmpwi cr6,r3,59
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 59, ctx.xer);
	// subf r29,r9,r5
	ctx.r29.s64 = ctx.r5.s64 - ctx.r9.s64;
	// bne cr6,0x88114580
	if (!ctx.cr6.eq) goto loc_88114580;
	// lis r10,-30667
	ctx.r10.s64 = -2009792512;
	// stw r11,16(r24)
	PPC_STORE_U32(ctx.r24.u32 + 16, ctx.r11.u32);
	// lwz r11,4(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 4);
	// li r27,0
	ctx.r27.s64 = 0;
	// addi r10,r10,4952
	ctx.r10.s64 = ctx.r10.s64 + 4952;
	// stw r11,20(r24)
	PPC_STORE_U32(ctx.r24.u32 + 20, ctx.r11.u32);
	// addi r31,r10,2
	ctx.r31.s64 = ctx.r10.s64 + 2;
loc_88114524:
	// lhz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 0);
	// li r6,55
	ctx.r6.s64 = 55;
	// lhz r9,-2(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + -2);
	// addi r3,r27,1338
	ctx.r3.s64 = ctx.r27.s64 + 1338;
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// lwz r11,16(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// rotlwi r8,r9,16
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 16);
	// addi r7,r10,-144
	ctx.r7.s64 = ctx.r10.s64 + -144;
	// subf r11,r11,r8
	ctx.r11.s64 = ctx.r8.s64 - ctx.r11.s64;
	// rlwinm r10,r7,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r11,r30
	ctx.r4.u64 = ctx.r11.u64 + ctx.r30.u64;
	// add r5,r10,r29
	ctx.r5.u64 = ctx.r10.u64 + ctx.r29.u64;
	// bl 0x881538c0
	ctx.lr = 0x88114558;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88114570
	if (ctx.cr6.eq) goto loc_88114570;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
loc_88114570:
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// cmplwi cr6,r27,10
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 10, ctx.xer);
	// blt cr6,0x88114524
	if (ctx.cr6.lt) goto loc_88114524;
loc_88114580:
	// lwz r11,20(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 20);
	// cmpwi cr6,r11,60
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 60, ctx.xer);
	// bne cr6,0x88114610
	if (!ctx.cr6.eq) goto loc_88114610;
	// lwz r11,0(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// lis r10,-30667
	ctx.r10.s64 = -2009792512;
	// li r27,0
	ctx.r27.s64 = 0;
	// addi r10,r10,4992
	ctx.r10.s64 = ctx.r10.s64 + 4992;
	// addi r31,r10,2
	ctx.r31.s64 = ctx.r10.s64 + 2;
	// stw r11,24(r24)
	PPC_STORE_U32(ctx.r24.u32 + 24, ctx.r11.u32);
	// lwz r11,4(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 4);
	// stw r11,28(r24)
	PPC_STORE_U32(ctx.r24.u32 + 28, ctx.r11.u32);
loc_881145AC:
	// lhz r11,-2(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + -2);
	// li r6,54
	ctx.r6.s64 = 54;
	// lhz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 0);
	// addi r3,r27,1348
	ctx.r3.s64 = ctx.r27.s64 + 1348;
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// lwz r11,24(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 24);
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// addi r8,r10,-256
	ctx.r8.s64 = ctx.r10.s64 + -256;
	// addi r7,r9,-144
	ctx.r7.s64 = ctx.r9.s64 + -144;
	// rlwinm r10,r8,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r9,r7,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r5,r9,r29
	ctx.r5.u64 = ctx.r9.u64 + ctx.r29.u64;
	// add r4,r11,r30
	ctx.r4.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x881538c0
	ctx.lr = 0x881145E8;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88114600
	if (ctx.cr6.eq) goto loc_88114600;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
loc_88114600:
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// cmplwi cr6,r27,10
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 10, ctx.xer);
	// blt cr6,0x881145ac
	if (ctx.cr6.lt) goto loc_881145AC;
loc_88114610:
	// lwz r11,20(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 20);
	// cmpwi cr6,r11,61
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 61, ctx.xer);
	// bne cr6,0x881146a0
	if (!ctx.cr6.eq) goto loc_881146A0;
	// lwz r11,0(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// lis r10,-30667
	ctx.r10.s64 = -2009792512;
	// li r27,0
	ctx.r27.s64 = 0;
	// addi r10,r10,5032
	ctx.r10.s64 = ctx.r10.s64 + 5032;
	// addi r31,r10,2
	ctx.r31.s64 = ctx.r10.s64 + 2;
	// stw r11,32(r24)
	PPC_STORE_U32(ctx.r24.u32 + 32, ctx.r11.u32);
	// lwz r11,4(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 4);
	// stw r11,36(r24)
	PPC_STORE_U32(ctx.r24.u32 + 36, ctx.r11.u32);
loc_8811463C:
	// lhz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 0);
	// li r6,50
	ctx.r6.s64 = 50;
	// lhz r9,-2(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + -2);
	// addi r3,r27,1358
	ctx.r3.s64 = ctx.r27.s64 + 1358;
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// lwz r11,36(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 36);
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// addi r8,r10,-112
	ctx.r8.s64 = ctx.r10.s64 + -112;
	// addi r7,r9,-160
	ctx.r7.s64 = ctx.r9.s64 + -160;
	// rlwinm r5,r8,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r7,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// subf r11,r11,r5
	ctx.r11.s64 = ctx.r5.s64 - ctx.r11.s64;
	// add r4,r10,r30
	ctx.r4.u64 = ctx.r10.u64 + ctx.r30.u64;
	// add r5,r11,r29
	ctx.r5.u64 = ctx.r11.u64 + ctx.r29.u64;
	// bl 0x881538c0
	ctx.lr = 0x88114678;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88114690
	if (ctx.cr6.eq) goto loc_88114690;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
loc_88114690:
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// cmplwi cr6,r27,8
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 8, ctx.xer);
	// blt cr6,0x8811463c
	if (ctx.cr6.lt) goto loc_8811463C;
loc_881146A0:
	// lwz r10,20(r25)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r25.u32 + 20);
	// lis r11,-30667
	ctx.r11.s64 = -2009792512;
	// cmpwi cr6,r10,101
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 101, ctx.xer);
	// addi r26,r11,5064
	ctx.r26.s64 = ctx.r11.s64 + 5064;
	// bne cr6,0x88114730
	if (!ctx.cr6.eq) goto loc_88114730;
	// lwz r11,0(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// li r27,0
	ctx.r27.s64 = 0;
	// addi r31,r26,2
	ctx.r31.s64 = ctx.r26.s64 + 2;
	// stw r11,72(r24)
	PPC_STORE_U32(ctx.r24.u32 + 72, ctx.r11.u32);
	// lwz r11,4(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 4);
	// stw r11,76(r24)
	PPC_STORE_U32(ctx.r24.u32 + 76, ctx.r11.u32);
loc_881146CC:
	// lhz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 0);
	// li r6,53
	ctx.r6.s64 = 53;
	// lhz r9,-2(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + -2);
	// addi r3,r27,1366
	ctx.r3.s64 = ctx.r27.s64 + 1366;
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// lwz r11,76(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 76);
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// addi r8,r10,-120
	ctx.r8.s64 = ctx.r10.s64 + -120;
	// addi r7,r9,-68
	ctx.r7.s64 = ctx.r9.s64 + -68;
	// rlwinm r5,r8,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r7,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// subf r11,r11,r5
	ctx.r11.s64 = ctx.r5.s64 - ctx.r11.s64;
	// add r4,r10,r30
	ctx.r4.u64 = ctx.r10.u64 + ctx.r30.u64;
	// add r5,r11,r29
	ctx.r5.u64 = ctx.r11.u64 + ctx.r29.u64;
	// bl 0x881538c0
	ctx.lr = 0x88114708;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88114720
	if (ctx.cr6.eq) goto loc_88114720;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
loc_88114720:
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// cmplwi cr6,r27,3
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 3, ctx.xer);
	// blt cr6,0x881146cc
	if (ctx.cr6.lt) goto loc_881146CC;
loc_88114730:
	// lwz r11,20(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 20);
	// cmpwi cr6,r11,102
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 102, ctx.xer);
	// bne cr6,0x881147cc
	if (!ctx.cr6.eq) goto loc_881147CC;
	// lwz r11,0(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// li r27,0
	ctx.r27.s64 = 0;
	// addi r31,r26,2
	ctx.r31.s64 = ctx.r26.s64 + 2;
	// stw r11,80(r24)
	PPC_STORE_U32(ctx.r24.u32 + 80, ctx.r11.u32);
	// lwz r11,4(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 4);
	// stw r11,84(r24)
	PPC_STORE_U32(ctx.r24.u32 + 84, ctx.r11.u32);
loc_88114754:
	// lhz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 0);
	// li r6,65
	ctx.r6.s64 = 65;
	// lhz r9,-2(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + -2);
	// addi r3,r27,1366
	ctx.r3.s64 = ctx.r27.s64 + 1366;
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// lwz r11,84(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 84);
	// extsh r8,r9
	ctx.r8.s64 = ctx.r9.s16;
	// addi r7,r10,-120
	ctx.r7.s64 = ctx.r10.s64 + -120;
	// subfic r5,r8,68
	ctx.xer.ca = ctx.r8.u32 <= 68;
	ctx.r5.s64 = 68 - ctx.r8.s64;
	// rlwinm r4,r7,16,0,15
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r5,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// subf r11,r11,r4
	ctx.r11.s64 = ctx.r4.s64 - ctx.r11.s64;
	// add r4,r10,r30
	ctx.r4.u64 = ctx.r10.u64 + ctx.r30.u64;
	// add r5,r11,r29
	ctx.r5.u64 = ctx.r11.u64 + ctx.r29.u64;
	// bl 0x881538c0
	ctx.lr = 0x88114790;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x881147bc
	if (ctx.cr6.eq) goto loc_881147BC;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// oris r8,r11,1024
	ctx.r8.u64 = ctx.r11.u64 | 67108864;
	// lwz r7,40(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// subf r6,r7,r9
	ctx.r6.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r6,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r6.u32);
loc_881147BC:
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// cmplwi cr6,r27,3
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 3, ctx.xer);
	// blt cr6,0x88114754
	if (ctx.cr6.lt) goto loc_88114754;
loc_881147CC:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_881147D4"))) PPC_WEAK_FUNC(sub_881147D4);
PPC_FUNC_IMPL(__imp__sub_881147D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881147D8"))) PPC_WEAK_FUNC(sub_881147D8);
PPC_FUNC_IMPL(__imp__sub_881147D8) {
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
	// lis r5,-292
	ctx.r5.s64 = -19136512;
	// li r4,24
	ctx.r4.s64 = 24;
	// ori r5,r5,47768
	ctx.r5.u64 = ctx.r5.u64 | 47768;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x881147FC;
	sub_88094290(ctx, base);
	// li r5,24
	ctx.r5.s64 = 24;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,2304(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2304);
	// bl 0x88073bd0
	ctx.lr = 0x8811480C;
	sub_88073BD0(ctx, base);
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lis r5,-30643
	ctx.r5.s64 = -2008219648;
	// addi r6,r11,32688
	ctx.r6.s64 = ctx.r11.s64 + 32688;
	// li r11,11
	ctx.r11.s64 = 11;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r7,r5,32512
	ctx.r7.s64 = ctx.r5.s64 + 32512;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// stw r10,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r10.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// stw r10,12(r6)
	PPC_STORE_U32(ctx.r6.u32 + 12, ctx.r10.u32);
	// addi r11,r7,-4
	ctx.r11.s64 = ctx.r7.s64 + -4;
	// stw r10,16(r6)
	PPC_STORE_U32(ctx.r6.u32 + 16, ctx.r10.u32);
	// stw r10,20(r6)
	PPC_STORE_U32(ctx.r6.u32 + 20, ctx.r10.u32);
	// stw r10,24(r6)
	PPC_STORE_U32(ctx.r6.u32 + 24, ctx.r10.u32);
	// stw r10,28(r6)
	PPC_STORE_U32(ctx.r6.u32 + 28, ctx.r10.u32);
	// stw r10,36(r6)
	PPC_STORE_U32(ctx.r6.u32 + 36, ctx.r10.u32);
	// stw r10,32(r6)
	PPC_STORE_U32(ctx.r6.u32 + 32, ctx.r10.u32);
	// stw r10,52(r6)
	PPC_STORE_U32(ctx.r6.u32 + 52, ctx.r10.u32);
	// stw r10,48(r6)
	PPC_STORE_U32(ctx.r6.u32 + 48, ctx.r10.u32);
	// stw r10,60(r6)
	PPC_STORE_U32(ctx.r6.u32 + 60, ctx.r10.u32);
	// stw r10,56(r6)
	PPC_STORE_U32(ctx.r6.u32 + 56, ctx.r10.u32);
	// stw r10,68(r6)
	PPC_STORE_U32(ctx.r6.u32 + 68, ctx.r10.u32);
	// stw r10,64(r6)
	PPC_STORE_U32(ctx.r6.u32 + 64, ctx.r10.u32);
	// stw r10,76(r6)
	PPC_STORE_U32(ctx.r6.u32 + 76, ctx.r10.u32);
	// stw r10,72(r6)
	PPC_STORE_U32(ctx.r6.u32 + 72, ctx.r10.u32);
	// stw r10,84(r6)
	PPC_STORE_U32(ctx.r6.u32 + 84, ctx.r10.u32);
	// stw r10,80(r6)
	PPC_STORE_U32(ctx.r6.u32 + 80, ctx.r10.u32);
loc_88114880:
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// stwu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x88114880
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88114880;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// li r9,11
	ctx.r9.s64 = 11;
	// addi r11,r11,32600
	ctx.r11.s64 = ctx.r11.s64 + 32600;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_881148A0:
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// stwu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x881148a0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_881148A0;
	// lis r11,-30703
	ctx.r11.s64 = -2012151808;
	// addi r10,r11,14568
	ctx.r10.s64 = ctx.r11.s64 + 14568;
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_881148CC"))) PPC_WEAK_FUNC(sub_881148CC);
PPC_FUNC_IMPL(__imp__sub_881148CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881148D0"))) PPC_WEAK_FUNC(sub_881148D0);
PPC_FUNC_IMPL(__imp__sub_881148D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071134
	ctx.lr = 0x881148D8;
	__savegprlr_19(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,2300(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2300);
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r21,2304(r3)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r19,-30597
	ctx.r19.s64 = -2005204992;
	// addi r20,r11,32688
	ctx.r20.s64 = ctx.r11.s64 + 32688;
	// lwz r9,156(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 156);
	// lwz r8,160(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 160);
	// srawi r7,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 1;
	// lwz r6,0(r21)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r21.u32 + 0);
	// lwz r5,4(r21)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r21.u32 + 4);
	// addze r4,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r4.s64 = temp.s64;
	// lwz r3,24(r21)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r21.u32 + 24);
	// srawi r11,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r8.s32 >> 1;
	// subf r24,r4,r6
	ctx.r24.s64 = ctx.r6.s64 - ctx.r4.s64;
	// addze r10,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r10.s64 = temp.s64;
	// cmpwi cr6,r3,74
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 74, ctx.xer);
	// subf r23,r10,r5
	ctx.r23.s64 = ctx.r5.s64 - ctx.r10.s64;
	// bne cr6,0x88114b04
	if (!ctx.cr6.eq) goto loc_88114B04;
	// lwz r11,16(r21)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r21.u32 + 16);
	// lwz r8,12(r20)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r20.u32 + 12);
	// lwz r9,4(r20)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r20.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88114944
	if (!ctx.cr6.eq) goto loc_88114944;
	// rlwinm r11,r9,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// subf r10,r9,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r9.s64;
	// b 0x8811494c
	goto loc_8811494C;
loc_88114944:
	// rlwinm r11,r8,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// subf r10,r8,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r8.s64;
loc_8811494C:
	// lis r11,-30667
	ctx.r11.s64 = -2009792512;
	// lwz r27,-11932(r19)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r19.u32 + -11932);
	// srawi r7,r10,22
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3FFFFF) != 0);
	ctx.r7.s64 = ctx.r10.s32 >> 22;
	// addi r11,r11,4900
	ctx.r11.s64 = ctx.r11.s64 + 4900;
	// addze r26,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r26.s64 = temp.s64;
	// li r28,1369
	ctx.r28.s64 = 1369;
	// li r25,5
	ctx.r25.s64 = 5;
	// addi r31,r11,2
	ctx.r31.s64 = ctx.r11.s64 + 2;
	// b 0x88114978
	goto loc_88114978;
loc_88114970:
	// lwz r8,12(r20)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r20.u32 + 12);
	// lwz r9,4(r20)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r20.u32 + 4);
loc_88114978:
	// lwz r11,16(r21)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r21.u32 + 16);
	// li r6,79
	ctx.r6.s64 = 79;
	// lhz r10,-2(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + -2);
	// addi r3,r28,-112
	ctx.r3.s64 = ctx.r28.s64 + -112;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lhz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 0);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// bne cr6,0x88114a34
	if (!ctx.cr6.eq) goto loc_88114A34;
	// addi r8,r11,-24
	ctx.r8.s64 = ctx.r11.s64 + -24;
	// addi r7,r10,-12
	ctx.r7.s64 = ctx.r10.s64 + -12;
	// rlwinm r11,r8,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r7,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r30,r10,r24
	ctx.r30.u64 = ctx.r10.u64 + ctx.r24.u64;
	// add r29,r11,r23
	ctx.r29.u64 = ctx.r11.u64 + ctx.r23.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x881538c0
	ctx.lr = 0x881149C4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x881149f8
	if (ctx.cr6.eq) goto loc_881149F8;
	// subfic r11,r26,255
	ctx.xer.ca = ctx.r26.u32 <= 255;
	ctx.r11.s64 = 255 - ctx.r26.s64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,547
	ctx.r9.s64 = 35848192;
	// lwz r8,12(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r7,16(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// rlwimi r9,r11,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// or r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// stw r7,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r7.u32);
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
loc_881149F8:
	// li r6,79
	ctx.r6.s64 = 79;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x881538c0
	ctx.lr = 0x88114A0C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88114aec
	if (ctx.cr6.eq) goto loc_88114AEC;
	// lis r11,547
	ctx.r11.s64 = 35848192;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,16(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwimi r11,r26,8,16,23
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r26.u32, 8) & 0xFF00) | (ctx.r11.u64 & 0xFFFFFFFFFFFF00FF);
	// or r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// b 0x88114adc
	goto loc_88114ADC;
loc_88114A34:
	// addi r9,r11,-64
	ctx.r9.s64 = ctx.r11.s64 + -64;
	// addi r7,r10,24
	ctx.r7.s64 = ctx.r10.s64 + 24;
	// rlwinm r11,r9,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r5,r7,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// subf r30,r5,r24
	ctx.r30.s64 = ctx.r24.s64 - ctx.r5.s64;
	// add r29,r11,r23
	ctx.r29.u64 = ctx.r11.u64 + ctx.r23.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x881538c0
	ctx.lr = 0x88114A5C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88114a9c
	if (ctx.cr6.eq) goto loc_88114A9C;
	// subfic r11,r26,255
	ctx.xer.ca = ctx.r26.u32 <= 255;
	ctx.r11.s64 = 255 - ctx.r26.s64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,1571
	ctx.r9.s64 = 102957056;
	// lwz r8,12(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r7,16(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// lwz r6,40(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// rlwimi r9,r11,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r27,-11932(r19)
	PPC_STORE_U32(ctx.r19.u32 + -11932, ctx.r27.u32);
	// or r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 | ctx.r10.u64;
	// subf r4,r6,r7
	ctx.r4.s64 = ctx.r7.s64 - ctx.r6.s64;
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// stw r4,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r4.u32);
loc_88114A9C:
	// li r6,79
	ctx.r6.s64 = 79;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x881538c0
	ctx.lr = 0x88114AB0;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88114aec
	if (ctx.cr6.eq) goto loc_88114AEC;
	// lis r11,1571
	ctx.r11.s64 = 102957056;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,16(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r7,40(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// rlwimi r11,r26,8,16,23
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r26.u32, 8) & 0xFF00) | (ctx.r11.u64 & 0xFFFFFFFFFFFF00FF);
	// or r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 | ctx.r10.u64;
	// subf r5,r7,r8
	ctx.r5.s64 = ctx.r8.s64 - ctx.r7.s64;
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// stw r5,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r5.u32);
loc_88114ADC:
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// stw r27,-11932(r19)
	PPC_STORE_U32(ctx.r19.u32 + -11932, ctx.r27.u32);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
loc_88114AEC:
	// addic. r25,r25,-1
	ctx.xer.ca = ctx.r25.u32 > 0;
	ctx.r25.s64 = ctx.r25.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// bne 0x88114970
	if (!ctx.cr0.eq) goto loc_88114970;
	// stw r27,-11932(r19)
	PPC_STORE_U32(ctx.r19.u32 + -11932, ctx.r27.u32);
	// b 0x88114b08
	goto loc_88114B08;
loc_88114B04:
	// lwz r27,-11932(r19)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r19.u32 + -11932);
loc_88114B08:
	// lwz r11,24(r21)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r21.u32 + 24);
	// cmpwi cr6,r11,75
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 75, ctx.xer);
	// bne cr6,0x88114d10
	if (!ctx.cr6.eq) goto loc_88114D10;
	// lwz r11,28(r21)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r21.u32 + 28);
	// addi r10,r20,4
	ctx.r10.s64 = ctx.r20.s64 + 4;
	// lis r9,-30667
	ctx.r9.s64 = -2009792512;
	// rlwinm r8,r11,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r11,r9,4920
	ctx.r11.s64 = ctx.r9.s64 + 4920;
	// li r31,1374
	ctx.r31.s64 = 1374;
	// addi r26,r11,2
	ctx.r26.s64 = ctx.r11.s64 + 2;
	// li r22,8
	ctx.r22.s64 = 8;
	// lwzx r7,r8,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// rlwinm r6,r7,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// subf r5,r7,r6
	ctx.r5.s64 = ctx.r6.s64 - ctx.r7.s64;
	// srawi r4,r5,22
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x3FFFFF) != 0);
	ctx.r4.s64 = ctx.r5.s32 >> 22;
	// addze r25,r4
	temp.s64 = ctx.r4.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r25.s64 = temp.s64;
loc_88114B48:
	// lwz r11,16(r21)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r21.u32 + 16);
	// li r28,85
	ctx.r28.s64 = 85;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r11,28(r21)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r21.u32 + 28);
	// beq cr6,0x88114c20
	if (ctx.cr6.eq) goto loc_88114C20;
	// lhz r9,-2(r26)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r26.u32 + -2);
	// rlwinm r7,r11,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r20,4
	ctx.r10.s64 = ctx.r20.s64 + 4;
	// lhz r6,0(r26)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r26.u32 + 0);
	// extsh r11,r9
	ctx.r11.s64 = ctx.r9.s16;
	// rotlwi r9,r6,16
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r6.u32, 16);
	// addi r5,r11,-24
	ctx.r5.s64 = ctx.r11.s64 + -24;
	// addi r8,r31,-1374
	ctx.r8.s64 = ctx.r31.s64 + -1374;
	// lwzx r11,r7,r10
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// rlwinm r10,r5,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// cmpwi cr6,r8,1
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 1, ctx.xer);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r30,r10,r24
	ctx.r30.u64 = ctx.r10.u64 + ctx.r24.u64;
	// add r29,r11,r23
	ctx.r29.u64 = ctx.r11.u64 + ctx.r23.u64;
	// bge cr6,0x88114b9c
	if (!ctx.cr6.lt) goto loc_88114B9C;
	// li r28,79
	ctx.r28.s64 = 79;
loc_88114B9C:
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r31,-112
	ctx.r3.s64 = ctx.r31.s64 + -112;
	// bl 0x881538c0
	ctx.lr = 0x88114BB0;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88114be4
	if (ctx.cr6.eq) goto loc_88114BE4;
	// subfic r11,r25,255
	ctx.xer.ca = ctx.r25.u32 <= 255;
	ctx.r11.s64 = 255 - ctx.r25.s64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,547
	ctx.r9.s64 = 35848192;
	// lwz r8,12(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r7,16(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// rlwimi r9,r11,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// or r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// stw r7,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r7.u32);
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
loc_88114BE4:
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x881538c0
	ctx.lr = 0x88114BF8;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88114cfc
	if (ctx.cr6.eq) goto loc_88114CFC;
	// lis r11,547
	ctx.r11.s64 = 35848192;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,16(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwimi r11,r25,8,16,23
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r25.u32, 8) & 0xFF00) | (ctx.r11.u64 & 0xFFFFFFFFFFFF00FF);
	// or r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// b 0x88114cec
	goto loc_88114CEC;
loc_88114C20:
	// rlwinm r6,r11,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lhz r8,0(r26)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r26.u32 + 0);
	// addi r9,r20,4
	ctx.r9.s64 = ctx.r20.s64 + 4;
	// lhz r5,-2(r26)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r26.u32 + -2);
	// rotlwi r10,r8,16
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 16);
	// addi r7,r31,-1374
	ctx.r7.s64 = ctx.r31.s64 + -1374;
	// rotlwi r4,r5,16
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 16);
	// cmpwi cr6,r7,1
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 1, ctx.xer);
	// lwzx r11,r6,r9
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// subf r30,r4,r24
	ctx.r30.s64 = ctx.r24.s64 - ctx.r4.s64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r29,r11,r23
	ctx.r29.u64 = ctx.r11.u64 + ctx.r23.u64;
	// bge cr6,0x88114c58
	if (!ctx.cr6.lt) goto loc_88114C58;
	// li r28,79
	ctx.r28.s64 = 79;
loc_88114C58:
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r31,-112
	ctx.r3.s64 = ctx.r31.s64 + -112;
	// bl 0x881538c0
	ctx.lr = 0x88114C6C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88114cac
	if (ctx.cr6.eq) goto loc_88114CAC;
	// subfic r11,r25,255
	ctx.xer.ca = ctx.r25.u32 <= 255;
	ctx.r11.s64 = 255 - ctx.r25.s64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,1571
	ctx.r9.s64 = 102957056;
	// lwz r8,12(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r7,16(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// lwz r6,40(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// rlwimi r9,r11,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r27,-11932(r19)
	PPC_STORE_U32(ctx.r19.u32 + -11932, ctx.r27.u32);
	// or r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 | ctx.r10.u64;
	// subf r4,r6,r7
	ctx.r4.s64 = ctx.r7.s64 - ctx.r6.s64;
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// stw r4,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r4.u32);
loc_88114CAC:
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x881538c0
	ctx.lr = 0x88114CC0;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88114cfc
	if (ctx.cr6.eq) goto loc_88114CFC;
	// lis r11,1571
	ctx.r11.s64 = 102957056;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,16(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r7,40(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// rlwimi r11,r25,8,16,23
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r25.u32, 8) & 0xFF00) | (ctx.r11.u64 & 0xFFFFFFFFFFFF00FF);
	// or r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 | ctx.r10.u64;
	// subf r5,r7,r8
	ctx.r5.s64 = ctx.r8.s64 - ctx.r7.s64;
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// stw r5,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r5.u32);
loc_88114CEC:
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// stw r27,-11932(r19)
	PPC_STORE_U32(ctx.r19.u32 + -11932, ctx.r27.u32);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
loc_88114CFC:
	// addic. r22,r22,-1
	ctx.xer.ca = ctx.r22.u32 > 0;
	ctx.r22.s64 = ctx.r22.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// addi r26,r26,4
	ctx.r26.s64 = ctx.r26.s64 + 4;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// bne 0x88114b48
	if (!ctx.cr0.eq) goto loc_88114B48;
	// stw r27,-11932(r19)
	PPC_STORE_U32(ctx.r19.u32 + -11932, ctx.r27.u32);
loc_88114D10:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x88071184
	__restgprlr_19(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88114D18"))) PPC_WEAK_FUNC(sub_88114D18);
PPC_FUNC_IMPL(__imp__sub_88114D18) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x88114D20;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// lwz r11,168(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// lwz r10,184(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// add r29,r10,r11
	ctx.r29.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmpwi cr6,r11,71
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 71, ctx.xer);
	// bne cr6,0x88114da8
	if (!ctx.cr6.eq) goto loc_88114DA8;
	// lis r11,-30667
	ctx.r11.s64 = -2009792512;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r11,r11,4776
	ctx.r11.s64 = ctx.r11.s64 + 4776;
	// addi r30,r11,2
	ctx.r30.s64 = ctx.r11.s64 + 2;
loc_88114D54:
	// lhz r10,-2(r30)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r30.u32 + -2);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// lhz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r30.u32 + 0);
	// addi r3,r28,1226
	ctx.r3.s64 = ctx.r28.s64 + 1226;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// rotlwi r10,r10,16
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 16);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// rotlwi r8,r8,16
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 16);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r5,r8,r9
	ctx.r5.u64 = ctx.r8.u64 + ctx.r9.u64;
	// bl 0x881538c0
	ctx.lr = 0x88114D80;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88114d98
	if (ctx.cr6.eq) goto loc_88114D98;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
loc_88114D98:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// cmplwi cr6,r28,13
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 13, ctx.xer);
	// blt cr6,0x88114d54
	if (ctx.cr6.lt) goto loc_88114D54;
loc_88114DA8:
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmpwi cr6,r11,72
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 72, ctx.xer);
	// bne cr6,0x88114e18
	if (!ctx.cr6.eq) goto loc_88114E18;
	// lis r11,-30667
	ctx.r11.s64 = -2009792512;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r11,r11,4828
	ctx.r11.s64 = ctx.r11.s64 + 4828;
	// addi r30,r11,2
	ctx.r30.s64 = ctx.r11.s64 + 2;
loc_88114DC4:
	// lhz r10,-2(r30)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r30.u32 + -2);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// lhz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r30.u32 + 0);
	// addi r3,r28,1239
	ctx.r3.s64 = ctx.r28.s64 + 1239;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// rotlwi r10,r10,16
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 16);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// rotlwi r8,r8,16
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 16);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r5,r8,r9
	ctx.r5.u64 = ctx.r8.u64 + ctx.r9.u64;
	// bl 0x881538c0
	ctx.lr = 0x88114DF0;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88114e08
	if (ctx.cr6.eq) goto loc_88114E08;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
loc_88114E08:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// cmplwi cr6,r28,9
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 9, ctx.xer);
	// blt cr6,0x88114dc4
	if (ctx.cr6.lt) goto loc_88114DC4;
loc_88114E18:
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmpwi cr6,r11,73
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 73, ctx.xer);
	// bne cr6,0x88114eac
	if (!ctx.cr6.eq) goto loc_88114EAC;
	// lis r11,-30667
	ctx.r11.s64 = -2009792512;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r11,r11,4864
	ctx.r11.s64 = ctx.r11.s64 + 4864;
	// addi r30,r11,2
	ctx.r30.s64 = ctx.r11.s64 + 2;
loc_88114E34:
	// lhz r11,-2(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + -2);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// lhz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r30.u32 + 0);
	// addi r3,r28,1248
	ctx.r3.s64 = ctx.r28.s64 + 1248;
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// lwz r7,2300(r27)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r27.u32 + 2300);
	// extsh r11,r9
	ctx.r11.s64 = ctx.r9.s16;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r5,r10,-17
	ctx.r5.s64 = ctx.r10.s64 + -17;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r4,r11,12
	ctx.r4.s64 = ctx.r11.s64 + 12;
	// rlwinm r11,r5,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// lwz r9,156(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 156);
	// rlwinm r5,r4,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// lwz r4,160(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 160);
	// subf r9,r9,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r9.s64;
	// subf r11,r4,r5
	ctx.r11.s64 = ctx.r5.s64 - ctx.r4.s64;
	// add r4,r9,r8
	ctx.r4.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x88114E84;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88114e9c
	if (ctx.cr6.eq) goto loc_88114E9C;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
loc_88114E9C:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// cmplwi cr6,r28,9
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 9, ctx.xer);
	// blt cr6,0x88114e34
	if (ctx.cr6.lt) goto loc_88114E34;
loc_88114EAC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88114EB4"))) PPC_WEAK_FUNC(sub_88114EB4);
PPC_FUNC_IMPL(__imp__sub_88114EB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88114EB8"))) PPC_WEAK_FUNC(sub_88114EB8);
PPC_FUNC_IMPL(__imp__sub_88114EB8) {
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
	// lis r5,-292
	ctx.r5.s64 = -19136512;
	// li r4,104
	ctx.r4.s64 = 104;
	// ori r5,r5,47768
	ctx.r5.u64 = ctx.r5.u64 | 47768;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x88114EE0;
	sub_88094290(ctx, base);
	// li r5,104
	ctx.r5.s64 = 104;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r30,2304(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2304);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88073bd0
	ctx.lr = 0x88114EF4;
	sub_88073BD0(ctx, base);
	// lwz r5,32(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,109
	ctx.r11.s64 = 109;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r11.u32);
	// lis r9,-30703
	ctx.r9.s64 = -2012151808;
	// lis r8,-30703
	ctx.r8.s64 = -2012151808;
	// stw r5,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r5.u32);
	// addi r7,r9,13840
	ctx.r7.s64 = ctx.r9.s64 + 13840;
	// lwz r4,36(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r6,r8,16864
	ctx.r6.s64 = ctx.r8.s64 + 16864;
	// stw r4,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r4.u32);
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r10,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// stw r10,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r10.u32);
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r3,r10,-1
	ctx.r3.s64 = ctx.r10.s64 + -1;
	// and r11,r3,r11
	ctx.r11.u64 = ctx.r3.u64 & ctx.r11.u64;
	// stw r11,40(r30)
	PPC_STORE_U32(ctx.r30.u32 + 40, ctx.r11.u32);
	// stw r7,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r7.u32);
	// stw r6,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r6.u32);
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

__attribute__((alias("__imp__sub_88114F60"))) PPC_WEAK_FUNC(sub_88114F60);
PPC_FUNC_IMPL(__imp__sub_88114F60) {
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
	// lis r5,-292
	ctx.r5.s64 = -19136512;
	// li r4,24
	ctx.r4.s64 = 24;
	// ori r5,r5,47768
	ctx.r5.u64 = ctx.r5.u64 | 47768;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x88114F88;
	sub_88094290(ctx, base);
	// li r5,24
	ctx.r5.s64 = 24;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r30,2304(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2304);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88073bd0
	ctx.lr = 0x88114F9C;
	sub_88073BD0(ctx, base);
	// lwz r6,32(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,55
	ctx.r11.s64 = 55;
	// lis r10,-30703
	ctx.r10.s64 = -2012151808;
	// stw r11,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r11.u32);
	// lis r9,-30703
	ctx.r9.s64 = -2012151808;
	// addi r8,r10,13664
	ctx.r8.s64 = ctx.r10.s64 + 13664;
	// stw r6,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r6.u32);
	// addi r7,r9,17584
	ctx.r7.s64 = ctx.r9.s64 + 17584;
	// lwz r5,36(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// stw r5,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r5.u32);
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r4,r10,-1
	ctx.r4.s64 = ctx.r10.s64 + -1;
	// and r3,r4,r11
	ctx.r3.u64 = ctx.r4.u64 & ctx.r11.u64;
	// stw r3,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r3.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r11.u32);
	// stw r8,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r8.u32);
	// stw r7,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r7.u32);
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

__attribute__((alias("__imp__sub_88115004"))) PPC_WEAK_FUNC(sub_88115004);
PPC_FUNC_IMPL(__imp__sub_88115004) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88115008"))) PPC_WEAK_FUNC(sub_88115008);
PPC_FUNC_IMPL(__imp__sub_88115008) {
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
	// lis r5,-292
	ctx.r5.s64 = -19136512;
	// li r4,32
	ctx.r4.s64 = 32;
	// ori r5,r5,47768
	ctx.r5.u64 = ctx.r5.u64 | 47768;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x88115030;
	sub_88094290(ctx, base);
	// li r5,32
	ctx.r5.s64 = 32;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,2304(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2304);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x88115044;
	sub_88073BD0(ctx, base);
	// lwz r9,32(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// li r11,79
	ctx.r11.s64 = 79;
	// lis r10,120
	ctx.r10.s64 = 7864320;
	// stw r11,168(r30)
	PPC_STORE_U32(ctx.r30.u32 + 168, ctx.r11.u32);
	// rotlwi r8,r9,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// cmpw cr6,r8,r10
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r10.s32, ctx.xer);
	// lwz r7,36(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// stw r7,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r7.u32);
	// blt cr6,0x88115074
	if (ctx.cr6.lt) goto loc_88115074;
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
loc_88115074:
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r10.u32);
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// cmpwi cr6,r9,75
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 75, ctx.xer);
	// stw r9,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r9.u32);
	// bne cr6,0x881150d0
	if (!ctx.cr6.eq) goto loc_881150D0;
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// lwz r11,116(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 116);
	// cmpwi cr6,r11,528
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 528, ctx.xer);
	// blt cr6,0x881150a0
	if (ctx.cr6.lt) goto loc_881150A0;
	// stw r10,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r10.u32);
loc_881150A0:
	// cmpwi cr6,r11,479
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 479, ctx.xer);
	// bne cr6,0x881150b0
	if (!ctx.cr6.eq) goto loc_881150B0;
	// li r11,6
	ctx.r11.s64 = 6;
	// b 0x881150cc
	goto loc_881150CC;
loc_881150B0:
	// cmpwi cr6,r11,523
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 523, ctx.xer);
	// bne cr6,0x881150c0
	if (!ctx.cr6.eq) goto loc_881150C0;
	// li r11,7
	ctx.r11.s64 = 7;
	// b 0x881150cc
	goto loc_881150CC;
loc_881150C0:
	// cmpwi cr6,r11,565
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 565, ctx.xer);
	// bne cr6,0x881150d0
	if (!ctx.cr6.eq) goto loc_881150D0;
	// li r11,8
	ctx.r11.s64 = 8;
loc_881150CC:
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
loc_881150D0:
	// lwz r11,100(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 100);
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lis r8,-30703
	ctx.r8.s64 = -2012151808;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// lis r7,-30703
	ctx.r7.s64 = -2012151808;
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// lwz r10,-11984(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11984);
	// addi r6,r8,14336
	ctx.r6.s64 = ctx.r8.s64 + 14336;
	// addi r5,r9,-1
	ctx.r5.s64 = ctx.r9.s64 + -1;
	// addi r4,r7,18640
	ctx.r4.s64 = ctx.r7.s64 + 18640;
	// and r3,r5,r11
	ctx.r3.u64 = ctx.r5.u64 & ctx.r11.u64;
	// stw r3,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r3.u32);
	// stw r6,64(r30)
	PPC_STORE_U32(ctx.r30.u32 + 64, ctx.r6.u32);
	// stw r4,68(r30)
	PPC_STORE_U32(ctx.r30.u32 + 68, ctx.r4.u32);
	// lwz r11,1860(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1860);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8811512c
	if (!ctx.cr6.eq) goto loc_8811512C;
	// lwz r11,1888(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1888);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8811512c
	if (ctx.cr6.eq) goto loc_8811512C;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addis r10,r11,-533
	ctx.r10.s64 = ctx.r11.s64 + -34930688;
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
loc_8811512C:
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

__attribute__((alias("__imp__sub_88115144"))) PPC_WEAK_FUNC(sub_88115144);
PPC_FUNC_IMPL(__imp__sub_88115144) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88115148"))) PPC_WEAK_FUNC(sub_88115148);
PPC_FUNC_IMPL(__imp__sub_88115148) {
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
	// lis r5,-292
	ctx.r5.s64 = -19136512;
	// li r4,16
	ctx.r4.s64 = 16;
	// ori r5,r5,47768
	ctx.r5.u64 = ctx.r5.u64 | 47768;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x88115170;
	sub_88094290(ctx, base);
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r30,2304(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2304);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88073bd0
	ctx.lr = 0x88115184;
	sub_88073BD0(ctx, base);
	// lwz r6,32(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,81
	ctx.r11.s64 = 81;
	// lis r10,-30703
	ctx.r10.s64 = -2012151808;
	// stw r11,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r11.u32);
	// lis r9,-30703
	ctx.r9.s64 = -2012151808;
	// addi r8,r10,13752
	ctx.r8.s64 = ctx.r10.s64 + 13752;
	// stw r6,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r6.u32);
	// addi r7,r9,19736
	ctx.r7.s64 = ctx.r9.s64 + 19736;
	// lwz r5,36(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// stw r5,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r5.u32);
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// stw r4,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r4.u32);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// stw r3,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r3.u32);
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// and r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 & ctx.r11.u64;
	// stw r9,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r9.u32);
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r6,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r6.u32);
	// stw r8,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r8.u32);
	// stw r7,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r7.u32);
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

__attribute__((alias("__imp__sub_881151FC"))) PPC_WEAK_FUNC(sub_881151FC);
PPC_FUNC_IMPL(__imp__sub_881151FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88115200"))) PPC_WEAK_FUNC(sub_88115200);
PPC_FUNC_IMPL(__imp__sub_88115200) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88115204"))) PPC_WEAK_FUNC(sub_88115204);
PPC_FUNC_IMPL(__imp__sub_88115204) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88115208"))) PPC_WEAK_FUNC(sub_88115208);
PPC_FUNC_IMPL(__imp__sub_88115208) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88115210;
	__savegprlr_29(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// lis r6,-30597
	ctx.r6.s64 = -2005204992;
	// addi r8,r11,9552
	ctx.r8.s64 = ctx.r11.s64 + 9552;
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r7,20(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r11,26272(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26272);
	// clrlwi r10,r7,23
	ctx.r10.u64 = ctx.r7.u32 & 0x1FF;
	// lwz r5,16(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// rlwinm r4,r7,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x7FC;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r29,r10,128
	ctx.r29.s64 = ctx.r10.s64 + 128;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r6,-11984(r6)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + -11984);
	// rlwinm r29,r29,2,21,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0x7FC;
	// lwzx r11,r4,r8
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r8.u32);
	// mullw r11,r11,r5
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r5.s32);
	// lwzx r8,r29,r8
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r8.u32);
	// mullw r8,r8,r5
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r5.s32);
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r5,r8,r9
	ctx.r5.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stw r4,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r4.u32);
	// stw r5,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r5.u32);
	// beq cr6,0x88115284
	if (ctx.cr6.eq) goto loc_88115284;
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// b 0x88115294
	goto loc_88115294;
loc_88115284:
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// addi r11,r11,51
	ctx.r11.s64 = ctx.r11.s64 + 51;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r6
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r6.u32);
loc_88115294:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lis r8,64
	ctx.r8.s64 = 4194304;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add. r10,r5,r8
	ctx.r10.u64 = ctx.r5.u64 + ctx.r8.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r4,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r4.u32);
	// lwz r11,100(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// and r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 & ctx.r11.u64;
	// ble 0x88115304
	if (!ctx.cr0.gt) goto loc_88115304;
	// lis r9,128
	ctx.r9.s64 = 8388608;
	// lis r29,320
	ctx.r29.s64 = 20971520;
	// subf r10,r9,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r9.s64;
	// cmpw cr6,r10,r29
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r29.s32, ctx.xer);
	// bge cr6,0x88115304
	if (!ctx.cr6.lt) goto loc_88115304;
	// addi r11,r11,55
	ctx.r11.s64 = ctx.r11.s64 + 55;
	// lis r10,-40
	ctx.r10.s64 = -2621440;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r6
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r6.u32);
	// add r6,r11,r4
	ctx.r6.u64 = ctx.r11.u64 + ctx.r4.u64;
	// add r11,r6,r8
	ctx.r11.u64 = ctx.r6.u64 + ctx.r8.u64;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x88115304
	if (!ctx.cr6.gt) goto loc_88115304;
	// lis r10,280
	ctx.r10.s64 = 18350080;
	// subf r9,r9,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r9.s64;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x8811531c
	if (ctx.cr6.lt) goto loc_8811531C;
loc_88115304:
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88115324
	if (ctx.cr6.eq) goto loc_88115324;
	// bl 0x88094220
	ctx.lr = 0x88115314;
	sub_88094220(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_8811531C:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
loc_88115324:
	// lwz r11,104(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x881153f8
	if (ctx.cr6.eq) goto loc_881153F8;
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
	// bge 0x881153f8
	if (!ctx.cr0.lt) goto loc_881153F8;
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r10,108(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
	// addi r11,r7,128
	ctx.r11.s64 = ctx.r7.s64 + 128;
	// bge cr6,0x8811535c
	if (!ctx.cr6.lt) goto loc_8811535C;
	// addi r11,r7,-128
	ctx.r11.s64 = ctx.r7.s64 + -128;
loc_8811535C:
	// lwz r10,156(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 156);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x88115394
	if (!ctx.cr6.eq) goto loc_88115394;
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// lwz r10,26276(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26276);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x881153ec
	if (!ctx.cr6.eq) goto loc_881153EC;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// clrlwi r7,r11,16
	ctx.r7.u64 = ctx.r11.u32 & 0xFFFF;
	// li r6,-12
	ctx.r6.s64 = -12;
	// sth r30,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r30.u16);
	// li r3,19
	ctx.r3.s64 = 19;
	// bl 0x8815c948
	ctx.lr = 0x88115390;
	sub_8815C948(ctx, base);
	// b 0x881153e4
	goto loc_881153E4;
loc_88115394:
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// bne cr6,0x881153ec
	if (!ctx.cr6.eq) goto loc_881153EC;
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// lwz r10,26276(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26276);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x881153ec
	if (!ctx.cr6.eq) goto loc_881153EC;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// clrlwi r7,r11,16
	ctx.r7.u64 = ctx.r11.u32 & 0xFFFF;
	// li r6,-10
	ctx.r6.s64 = -10;
	// sth r30,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r30.u16);
	// li r3,19
	ctx.r3.s64 = 19;
	// bl 0x8815c948
	ctx.lr = 0x881153C4;
	sub_8815C948(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x881153e4
	if (ctx.cr6.eq) goto loc_881153E4;
	// li r11,2
	ctx.r11.s64 = 2;
	// li r10,3
	ctx.r10.s64 = 3;
	// li r9,16
	ctx.r9.s64 = 16;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r11.u8);
	// sth r10,18(r3)
	PPC_STORE_U16(ctx.r3.u32 + 18, ctx.r10.u16);
	// sth r9,20(r3)
	PPC_STORE_U16(ctx.r3.u32 + 20, ctx.r9.u16);
loc_881153E4:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x881153EC;
	sub_8815C860(ctx, base);
loc_881153EC:
	// lwz r11,104(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
loc_881153F8:
	// lwz r11,120(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r11.u32);
	// bge 0x8811541c
	if (!ctx.cr0.lt) goto loc_8811541C;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r10,124(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stw r9,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r9.u32);
	// stw r10,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r10.u32);
loc_8811541C:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88115424"))) PPC_WEAK_FUNC(sub_88115424);
PPC_FUNC_IMPL(__imp__sub_88115424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88115428"))) PPC_WEAK_FUNC(sub_88115428);
PPC_FUNC_IMPL(__imp__sub_88115428) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r9,2304(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// li r3,402
	ctx.r3.s64 = 402;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 184);
	// lwz r11,168(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 168);
	// lwz r5,8(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + ctx.r11.u64;
	// b 0x881538c0
	sub_881538C0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8811544C"))) PPC_WEAK_FUNC(sub_8811544C);
PPC_FUNC_IMPL(__imp__sub_8811544C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88115450"))) PPC_WEAK_FUNC(sub_88115450);
PPC_FUNC_IMPL(__imp__sub_88115450) {
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
	// lis r5,-292
	ctx.r5.s64 = -19136512;
	// li r4,160
	ctx.r4.s64 = 160;
	// ori r5,r5,47768
	ctx.r5.u64 = ctx.r5.u64 | 47768;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x88094290
	ctx.lr = 0x88115478;
	sub_88094290(ctx, base);
	// li r5,160
	ctx.r5.s64 = 160;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,2304(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2304);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x8811548C;
	sub_88073BD0(ctx, base);
	// stw r30,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// lwz r8,32(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// lis r11,16838
	ctx.r11.s64 = 1103495168;
	// stw r8,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// lis r5,-30671
	ctx.r5.s64 = -2010054656;
	// ori r10,r11,20077
	ctx.r10.u64 = ctx.r11.u64 | 20077;
	// lis r4,-30597
	ctx.r4.s64 = -2005204992;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// lwz r10,4200(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4200);
	// li r11,1
	ctx.r11.s64 = 1;
	// mullw r10,r10,r9
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// lwz r7,-11984(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + -11984);
	// lwz r4,36(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// stw r4,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r4.u32);
	// addi r10,r10,12345
	ctx.r10.s64 = ctx.r10.s64 + 12345;
	// stw r10,4200(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4200, ctx.r10.u32);
	// li r6,2
	ctx.r6.s64 = 2;
	// mullw r8,r10,r9
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// lwz r9,100(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 100);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// addi r10,r9,-1
	ctx.r10.s64 = ctx.r9.s64 + -1;
	// lhz r9,4200(r5)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r5.u32 + 4200);
	// stw r8,4200(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4200, ctx.r8.u32);
	// rlwinm r8,r10,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// clrlwi r3,r9,29
	ctx.r3.u64 = ctx.r9.u32 & 0x7;
	// addi r9,r8,-1
	ctx.r9.s64 = ctx.r8.s64 + -1;
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// lhz r10,4200(r5)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r5.u32 + 4200);
	// stw r8,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r8.u32);
	// lwz r5,132(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 132);
	// stw r5,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r5.u32);
	// lwz r4,136(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 136);
	// rotlwi r5,r4,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r4.u32, 0);
	// stw r4,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r4.u32);
	// clrlwi r10,r10,29
	ctx.r10.u64 = ctx.r10.u32 & 0x7;
	// lwz r9,140(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 140);
	// stw r9,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r9.u32);
	// lwz r8,144(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 144);
	// stw r8,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r8.u32);
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r3,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r3.u32);
	// stw r6,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r6.u32);
	// stw r5,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r5.u32);
	// stw r6,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r6.u32);
	// stw r10,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r10.u32);
	// stw r11,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r11.u32);
	// stw r11,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r11.u32);
	// lwz r4,84(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 84);
	// cmpwi cr6,r4,2
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 2, ctx.xer);
	// stw r4,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r4.u32);
	// bne cr6,0x88115574
	if (!ctx.cr6.eq) goto loc_88115574;
	// li r11,6
	ctx.r11.s64 = 6;
	// li r10,5
	ctx.r10.s64 = 5;
	// stw r11,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
	// stw r11,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
	// stw r10,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r10.u32);
loc_88115574:
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// lis r10,-30703
	ctx.r10.s64 = -2012151808;
	// lis r9,-30703
	ctx.r9.s64 = -2012151808;
	// lis r8,-30703
	ctx.r8.s64 = -2012151808;
	// addi r7,r10,21000
	ctx.r7.s64 = ctx.r10.s64 + 21000;
	// addi r6,r9,21544
	ctx.r6.s64 = ctx.r9.s64 + 21544;
	// addi r5,r8,20992
	ctx.r5.s64 = ctx.r8.s64 + 20992;
	// stw r11,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// stw r7,64(r30)
	PPC_STORE_U32(ctx.r30.u32 + 64, ctx.r7.u32);
	// stw r6,68(r30)
	PPC_STORE_U32(ctx.r30.u32 + 68, ctx.r6.u32);
	// stw r5,84(r30)
	PPC_STORE_U32(ctx.r30.u32 + 84, ctx.r5.u32);
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

__attribute__((alias("__imp__sub_881155B8"))) PPC_WEAK_FUNC(sub_881155B8);
PPC_FUNC_IMPL(__imp__sub_881155B8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881155BC"))) PPC_WEAK_FUNC(sub_881155BC);
PPC_FUNC_IMPL(__imp__sub_881155BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881155C0"))) PPC_WEAK_FUNC(sub_881155C0);
PPC_FUNC_IMPL(__imp__sub_881155C0) {
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
	// lwz r4,2304(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r6,r4,4
	ctx.r6.s64 = ctx.r4.s64 + 4;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// lwz r3,20(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// bl 0x880940d8
	ctx.lr = 0x881155E8;
	sub_880940D8(ctx, base);
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lis r11,-76
	ctx.r11.s64 = -4980736;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x88115614
	if (!ctx.cr6.lt) goto loc_88115614;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88094220
	ctx.lr = 0x88115600;
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
loc_88115614:
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r11.u32);
	// bge 0x88115638
	if (!ctx.cr0.lt) goto loc_88115638;
	// lwz r11,16(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stw r9,16(r4)
	PPC_STORE_U32(ctx.r4.u32 + 16, ctx.r9.u32);
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
loc_88115638:
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

__attribute__((alias("__imp__sub_8811564C"))) PPC_WEAK_FUNC(sub_8811564C);
PPC_FUNC_IMPL(__imp__sub_8811564C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88115650"))) PPC_WEAK_FUNC(sub_88115650);
PPC_FUNC_IMPL(__imp__sub_88115650) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88115654"))) PPC_WEAK_FUNC(sub_88115654);
PPC_FUNC_IMPL(__imp__sub_88115654) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88115658"))) PPC_WEAK_FUNC(sub_88115658);
PPC_FUNC_IMPL(__imp__sub_88115658) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// li r11,512
	ctx.r11.s64 = 512;
	// lwz r10,2304(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2304);
	// rlwinm r9,r5,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0x1;
	// subfc r8,r11,r5
	ctx.xer.ca = ctx.r5.u32 >= ctx.r11.u32;
	ctx.r8.s64 = ctx.r5.s64 - ctx.r11.s64;
	// rlwinm r7,r11,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// li r3,1
	ctx.r3.s64 = 1;
	// subfe r6,r9,r7
	temp.u8 = (~ctx.r9.u32 + ctx.r7.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r7.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ~ctx.r9.u64 + ctx.r7.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r5,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r5.u32);
	// and r5,r6,r4
	ctx.r5.u64 = ctx.r6.u64 & ctx.r4.u64;
	// stw r5,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88115684"))) PPC_WEAK_FUNC(sub_88115684);
PPC_FUNC_IMPL(__imp__sub_88115684) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88115688"))) PPC_WEAK_FUNC(sub_88115688);
PPC_FUNC_IMPL(__imp__sub_88115688) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8811568C"))) PPC_WEAK_FUNC(sub_8811568C);
PPC_FUNC_IMPL(__imp__sub_8811568C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88115690"))) PPC_WEAK_FUNC(sub_88115690);
PPC_FUNC_IMPL(__imp__sub_88115690) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// lis r9,-30643
	ctx.r9.s64 = -2008219648;
	// addi r6,r10,9552
	ctx.r6.s64 = ctx.r10.s64 + 9552;
	// lwz r5,12(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r9,26272(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 26272);
	// clrlwi r10,r5,23
	ctx.r10.u64 = ctx.r5.u32 & 0x1FF;
	// lwz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r5,r10,128
	ctx.r5.s64 = ctx.r10.s64 + 128;
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r5,r5,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x7FC;
	// lwzx r10,r10,r6
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r6.u32);
	// lwzx r9,r5,r6
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r6.u32);
	// mullw r10,r10,r4
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r4.s32);
	// mullw r9,r9,r4
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r4.s32);
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r10,r9,r7
	ctx.r10.u64 = ctx.r9.u64 + ctx.r7.u64;
	// stw r8,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// beq cr6,0x881156f4
	if (ctx.cr6.eq) goto loc_881156F4;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x8811570c
	goto loc_8811570C;
loc_881156F4:
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lis r8,-30597
	ctx.r8.s64 = -2005204992;
	// addi r7,r9,51
	ctx.r7.s64 = ctx.r9.s64 + 51;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,-11984(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + -11984);
	// lwzx r9,r6,r9
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
loc_8811570C:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lis r7,-896
	ctx.r7.s64 = -58720256;
	// add r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmpw cr6,r10,r7
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, ctx.xer);
	// stw r6,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r6.u32);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// b 0x88094220
	sub_88094220(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88115728"))) PPC_WEAK_FUNC(sub_88115728);
PPC_FUNC_IMPL(__imp__sub_88115728) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8811572C"))) PPC_WEAK_FUNC(sub_8811572C);
PPC_FUNC_IMPL(__imp__sub_8811572C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88115730"))) PPC_WEAK_FUNC(sub_88115730);
PPC_FUNC_IMPL(__imp__sub_88115730) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88115738;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r4,2304(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// lwz r11,108(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 108);
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88115774
	if (ctx.cr6.eq) goto loc_88115774;
loc_8811575C:
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// stw r30,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r30.u32);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8811575c
	if (!ctx.cr6.eq) goto loc_8811575C;
loc_88115774:
	// lis r11,128
	ctx.r11.s64 = 8388608;
	// clrlwi r10,r10,20
	ctx.r10.u64 = ctx.r10.u32 & 0xFFF;
	// ori r9,r11,32896
	ctx.r9.u64 = ctx.r11.u64 | 32896;
	// rlwinm r10,r10,0,26,21
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFC3F;
	// stw r9,52(r4)
	PPC_STORE_U32(ctx.r4.u32 + 52, ctx.r9.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x881157b4
	if (ctx.cr6.eq) goto loc_881157B4;
	// lwz r11,56(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 56);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// stw r11,56(r4)
	PPC_STORE_U32(ctx.r4.u32 + 56, ctx.r11.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x881157ec
	if (ctx.cr6.eq) goto loc_881157EC;
	// lis r11,192
	ctx.r11.s64 = 12582912;
	// ori r10,r11,49152
	ctx.r10.u64 = ctx.r11.u64 | 49152;
	// b 0x881157e8
	goto loc_881157E8;
loc_881157B4:
	// lwz r11,72(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 72);
	// lwz r10,68(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 68);
	// srawi r9,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 2;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// cmpw cr6,r10,r8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, ctx.xer);
	// bge cr6,0x881157ec
	if (!ctx.cr6.lt) goto loc_881157EC;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26428(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26428);
	// rlwinm r10,r11,0,28,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xE;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x881157ec
	if (!ctx.cr6.eq) goto loc_881157EC;
	// lis r11,255
	ctx.r11.s64 = 16711680;
	// ori r10,r11,4112
	ctx.r10.u64 = ctx.r11.u64 | 4112;
loc_881157E8:
	// stw r10,52(r4)
	PPC_STORE_U32(ctx.r4.u32 + 52, ctx.r10.u32);
loc_881157EC:
	// lwz r11,24(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// lis r9,-30714
	ctx.r9.s64 = -2012872704;
	// lwz r8,20(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// addi r6,r4,4
	ctx.r6.s64 = ctx.r4.s64 + 4;
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// addi r7,r9,9552
	ctx.r7.s64 = ctx.r9.s64 + 9552;
	// lwz r9,4(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// addi r5,r11,128
	ctx.r5.s64 = ctx.r11.s64 + 128;
	// lwz r3,64(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 64);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r29,r5,2,21,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x7FC;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// lwzx r11,r11,r7
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r7.u32);
	// lwzx r7,r29,r7
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r7.u32);
	// mullw r11,r11,r8
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r8.s32);
	// mullw r8,r7,r8
	ctx.r8.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r8.s32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// stw r10,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r10.u32);
	// bl 0x880940d8
	ctx.lr = 0x88115844;
	sub_880940D8(ctx, base);
	// lwz r8,4(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lis r9,-64
	ctx.r9.s64 = -4194304;
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// bgt cr6,0x8811586c
	if (ctx.cr6.gt) goto loc_8811586C;
	// lwz r11,108(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 108);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r30.u32);
	// bl 0x88094220
	ctx.lr = 0x88115864;
	sub_88094220(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_8811586C:
	// li r10,6
	ctx.r10.s64 = 6;
	// addi r11,r4,124
	ctx.r11.s64 = ctx.r4.s64 + 124;
	// li r9,16
	ctx.r9.s64 = 16;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8811587C:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// cmpwi cr6,r10,256
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 256, ctx.xer);
	// blt cr6,0x88115898
	if (ctx.cr6.lt) goto loc_88115898;
	// addi r10,r10,-256
	ctx.r10.s64 = ctx.r10.s64 + -256;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_88115898:
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// addi r9,r9,-2
	ctx.r9.s64 = ctx.r9.s64 + -2;
	// bdnz 0x8811587c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8811587C;
	// lwz r11,148(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 148);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,148(r4)
	PPC_STORE_U32(ctx.r4.u32 + 148, ctx.r11.u32);
	// bge 0x881158b8
	if (!ctx.cr0.lt) goto loc_881158B8;
	// stw r30,148(r4)
	PPC_STORE_U32(ctx.r4.u32 + 148, ctx.r30.u32);
loc_881158B8:
	// lwz r11,112(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 112);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x881158fc
	if (ctx.cr6.eq) goto loc_881158FC;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x88115920
	if (!ctx.cr6.eq) goto loc_88115920;
	// lwz r10,120(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 120);
	// lis r11,14
	ctx.r11.s64 = 917504;
	// addis r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 65536;
	// addi r9,r9,-32768
	ctx.r9.s64 = ctx.r9.s64 + -32768;
	// stw r9,120(r4)
	PPC_STORE_U32(ctx.r4.u32 + 120, ctx.r9.u32);
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x88115920
	if (!ctx.cr6.gt) goto loc_88115920;
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r11,120(r4)
	PPC_STORE_U32(ctx.r4.u32 + 120, ctx.r11.u32);
	// stw r10,112(r4)
	PPC_STORE_U32(ctx.r4.u32 + 112, ctx.r10.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_881158FC:
	// lwz r10,116(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 116);
	// lis r11,12
	ctx.r11.s64 = 786432;
	// addis r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 65536;
	// stw r9,116(r4)
	PPC_STORE_U32(ctx.r4.u32 + 116, ctx.r9.u32);
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x88115920
	if (!ctx.cr6.gt) goto loc_88115920;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r11,116(r4)
	PPC_STORE_U32(ctx.r4.u32 + 116, ctx.r11.u32);
	// stw r10,112(r4)
	PPC_STORE_U32(ctx.r4.u32 + 112, ctx.r10.u32);
loc_88115920:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88115928"))) PPC_WEAK_FUNC(sub_88115928);
PPC_FUNC_IMPL(__imp__sub_88115928) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r9,108(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 108);
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

__attribute__((alias("__imp__sub_88115968"))) PPC_WEAK_FUNC(sub_88115968);
PPC_FUNC_IMPL(__imp__sub_88115968) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071120
	ctx.lr = 0x88115970;
	__savegprlr_14(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30679
	ctx.r11.s64 = -2010578944;
	// lis r29,-30671
	ctx.r29.s64 = -2010054656;
	// addi r11,r11,-30072
	ctx.r11.s64 = ctx.r11.s64 + -30072;
	// lis r10,16838
	ctx.r10.s64 = 1103495168;
	// addi r31,r11,16
	ctx.r31.s64 = ctx.r11.s64 + 16;
	// lis r9,-3856
	ctx.r9.s64 = -252706816;
	// lis r8,-13755
	ctx.r8.s64 = -901447680;
	// lwz r30,4200(r29)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4200);
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// mr r17,r3
	ctx.r17.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r22,r5
	ctx.r22.u64 = ctx.r5.u64;
	// mr r15,r6
	ctx.r15.u64 = ctx.r6.u64;
	// li r14,11
	ctx.r14.s64 = 11;
	// ori r28,r10,20077
	ctx.r28.u64 = ctx.r10.u64 | 20077;
	// ori r21,r9,61681
	ctx.r21.u64 = ctx.r9.u64 | 61681;
	// li r16,112
	ctx.r16.s64 = 112;
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
loc_881159D0:
	// lwz r10,-8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -8);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r9,-4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + -4);
	// lwz r8,4(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r3,-16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -16);
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
	ctx.lr = 0x88115A04;
	sub_880F52C8(ctx, base);
	// mullw r11,r30,r28
	ctx.r11.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r28.s32);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
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
	// beq cr6,0x88115a98
	if (ctx.cr6.eq) goto loc_88115A98;
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
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
	// stw r6,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, ctx.r6.u32);
	// rotlwi r11,r6,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// beq 0x88115a78
	if (ctx.cr0.eq) goto loc_88115A78;
	// addi r6,r9,128
	ctx.r6.s64 = ctx.r9.s64 + 128;
	// rlwinm r5,r6,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// lwzx r4,r5,r18
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r18.u32);
	// mullw r6,r4,r11
	ctx.r6.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r11.s32);
	// stw r6,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r6.u32);
loc_88115A78:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x88115a90
	if (ctx.cr6.eq) goto loc_88115A90;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r18
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r18.u32);
	// mullw r6,r9,r11
	ctx.r6.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// stw r6,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r6.u32);
loc_88115A90:
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// stw r11,148(r3)
	PPC_STORE_U32(ctx.r3.u32 + 148, ctx.r11.u32);
loc_88115A98:
	// mullw r11,r8,r28
	ctx.r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r28.s32);
	// addi r30,r11,12345
	ctx.r30.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r30,4200(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4200, ctx.r30.u32);
	// beq cr6,0x88115ad8
	if (ctx.cr6.eq) goto loc_88115AD8;
	// lhz r11,4200(r29)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r29.u32 + 4200);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// stw r16,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r16.u32);
	// stw r15,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r15.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r10,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r10.u32);
	// lwz r9,-12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + -12);
	// clrlwi r8,r9,16
	ctx.r8.u64 = ctx.r9.u32 & 0xFFFF;
	// stw r8,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r8.u32);
loc_88115AD8:
	// lwz r11,76(r17)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r17.u32 + 76);
	// lwz r6,240(r17)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r17.u32 + 240);
	// lwz r5,236(r17)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r17.u32 + 236);
	// lwz r8,2332(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2332);
	// lwz r7,2328(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2328);
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// bl 0x880f5438
	ctx.lr = 0x88115AF4;
	sub_880F5438(ctx, base);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// li r23,0
	ctx.r23.s64 = 0;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x88115b84
	if (!ctx.cr6.gt) goto loc_88115B84;
	// addi r4,r22,1
	ctx.r4.s64 = ctx.r22.s64 + 1;
	// stw r4,12376(r20)
	PPC_STORE_U32(ctx.r20.u32 + 12376, ctx.r4.u32);
loc_88115B10:
	// lwz r11,-8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -8);
	// lwz r8,0(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r9,-4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + -4);
	// lwz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r11,12364(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r26)
	PPC_STORE_U32(ctx.r26.u32 + 12372, ctx.r10.u32);
	// stw r3,12380(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12380, ctx.r3.u32);
	// bl 0x880f34b0
	ctx.lr = 0x88115B3C;
	sub_880F34B0(ctx, base);
	// mullw r11,r30,r28
	ctx.r11.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r28.s32);
	// addi r30,r11,12345
	ctx.r30.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r30,4200(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4200, ctx.r30.u32);
	// beq cr6,0x88115b70
	if (ctx.cr6.eq) goto loc_88115B70;
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
loc_88115B70:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r23,r23,1
	ctx.r23.s64 = ctx.r23.s64 + 1;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r23,r10
	ctx.cr6.compare<int32_t>(ctx.r23.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x88115b10
	if (ctx.cr6.lt) goto loc_88115B10;
loc_88115B84:
	// addic. r14,r14,-1
	ctx.xer.ca = ctx.r14.u32 > 0;
	ctx.r14.s64 = ctx.r14.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r14.s32, 0, ctx.xer);
	// addi r31,r31,40
	ctx.r31.s64 = ctx.r31.s64 + 40;
	// bne 0x881159d0
	if (!ctx.cr0.eq) goto loc_881159D0;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88115B98"))) PPC_WEAK_FUNC(sub_88115B98);
PPC_FUNC_IMPL(__imp__sub_88115B98) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,2304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r9,-30643
	ctx.r9.s64 = -2008219648;
	// lis r7,-30597
	ctx.r7.s64 = -2005204992;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r9,26272(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 26272);
	// lwz r7,-11984(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + -11984);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// stw r10,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// bne cr6,0x88115bcc
	if (!ctx.cr6.eq) goto loc_88115BCC;
	// lwz r9,204(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 204);
loc_88115BCC:
	// lis r5,-30633
	ctx.r5.s64 = -2007564288;
	// add r4,r10,r9
	ctx.r4.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// lis r6,2
	ctx.r6.s64 = 131072;
	// addi r9,r9,16384
	ctx.r9.s64 = ctx.r9.s64 + 16384;
	// stw r4,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r4.u32);
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r10,-29776(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + -29776);
	// stw r9,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r9.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88115c34
	if (ctx.cr6.eq) goto loc_88115C34;
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 72);
	// addis r3,r5,-3
	ctx.r3.s64 = ctx.r5.s64 + -196608;
	// addis r5,r4,-12
	ctx.r5.s64 = ctx.r4.s64 + -786432;
	// stw r3,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r3.u32);
	// cmpwi cr6,r10,160
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 160, ctx.xer);
	// stw r5,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r5.u32);
	// bge cr6,0x88115c50
	if (!ctx.cr6.lt) goto loc_88115C50;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,72(r11)
	PPC_STORE_U32(ctx.r11.u32 + 72, ctx.r10.u32);
	// cmpwi cr6,r10,160
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 160, ctx.xer);
	// ble cr6,0x88115c50
	if (!ctx.cr6.gt) goto loc_88115C50;
	// li r10,160
	ctx.r10.s64 = 160;
	// stw r10,72(r11)
	PPC_STORE_U32(ctx.r11.u32 + 72, ctx.r10.u32);
	// b 0x88115c50
	goto loc_88115C50;
loc_88115C34:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r5,128
	ctx.r5.s64 = 128;
	// subf r3,r6,r10
	ctx.r3.s64 = ctx.r10.s64 - ctx.r6.s64;
	// stw r5,72(r11)
	PPC_STORE_U32(ctx.r11.u32 + 72, ctx.r5.u32);
	// addis r10,r4,-3
	ctx.r10.s64 = ctx.r4.s64 + -196608;
	// stw r3,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r3.u32);
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
loc_88115C50:
	// lis r10,-257
	ctx.r10.s64 = -16842752;
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// ori r10,r10,32768
	ctx.r10.u64 = ctx.r10.u64 | 32768;
	// cmpw cr6,r5,r10
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r10.s32, ctx.xer);
	// bgt cr6,0x88115c68
	if (ctx.cr6.gt) goto loc_88115C68;
	// stw r8,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r8.u32);
loc_88115C68:
	// lwz r5,12(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// cmpw cr6,r5,r10
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r10.s32, ctx.xer);
	// bgt cr6,0x88115c78
	if (ctx.cr6.gt) goto loc_88115C78;
	// stw r8,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r8.u32);
loc_88115C78:
	// lwz r5,20(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// cmpw cr6,r5,r10
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r10.s32, ctx.xer);
	// bgt cr6,0x88115c88
	if (ctx.cr6.gt) goto loc_88115C88;
	// stw r8,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r8.u32);
loc_88115C88:
	// lis r10,256
	ctx.r10.s64 = 16777216;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x88115c9c
	if (!ctx.cr6.gt) goto loc_88115C9C;
	// subf r10,r10,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r10.s64;
	// stw r10,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r10.u32);
loc_88115C9C:
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r8,108(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 108);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 104);
	// subf r5,r8,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r8.s64;
	// lwz r9,176(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 176);
	// cmpwi cr6,r10,20
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 20, ctx.xer);
	// stw r5,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r5.u32);
	// bgt cr6,0x88115e08
	if (ctx.cr6.gt) goto loc_88115E08;
	// beq cr6,0x88115d9c
	if (ctx.cr6.eq) goto loc_88115D9C;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88115d30
	if (ctx.cr6.eq) goto loc_88115D30;
	// cmpwi cr6,r10,10
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 10, ctx.xer);
	// bne cr6,0x88115e34
	if (!ctx.cr6.eq) goto loc_88115E34;
	// cmpwi cr6,r9,313
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 313, ctx.xer);
	// blt cr6,0x88115e34
	if (ctx.cr6.lt) goto loc_88115E34;
	// lwz r10,88(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// cmpwi cr6,r10,64
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 64, ctx.xer);
	// ble cr6,0x88115cec
	if (!ctx.cr6.gt) goto loc_88115CEC;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,88(r11)
	PPC_STORE_U32(ctx.r11.u32 + 88, ctx.r10.u32);
loc_88115CEC:
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// lwz r10,26428(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26428);
	// clrlwi r9,r10,30
	ctx.r9.u64 = ctx.r10.u32 & 0x3;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x88115e34
	if (!ctx.cr6.eq) goto loc_88115E34;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// cmpw cr6,r8,r10
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x88115d14
	if (!ctx.cr6.gt) goto loc_88115D14;
	// addi r10,r8,-4096
	ctx.r10.s64 = ctx.r8.s64 + -4096;
	// b 0x88115e30
	goto loc_88115E30;
loc_88115D14:
	// li r10,20
	ctx.r10.s64 = 20;
	// stw r10,104(r11)
	PPC_STORE_U32(ctx.r11.u32 + 104, ctx.r10.u32);
	// lwz r10,136(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 136);
	// addi r10,r10,-2
	ctx.r10.s64 = ctx.r10.s64 + -2;
	// clrlwi r9,r10,23
	ctx.r9.u64 = ctx.r10.u32 & 0x1FF;
	// stw r9,136(r11)
	PPC_STORE_U32(ctx.r11.u32 + 136, ctx.r9.u32);
	// blr 
	return;
loc_88115D30:
	// cmpwi cr6,r9,206
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 206, ctx.xer);
	// blt cr6,0x88115e34
	if (ctx.cr6.lt) goto loc_88115E34;
	// lis r9,-30643
	ctx.r9.s64 = -2008219648;
	// lwz r10,88(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// cmpwi cr6,r10,255
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 255, ctx.xer);
	// lwz r9,26428(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 26428);
	// bge cr6,0x88115d60
	if (!ctx.cr6.lt) goto loc_88115D60;
	// clrlwi r7,r9,29
	ctx.r7.u64 = ctx.r9.u32 & 0x7;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x88115d60
	if (!ctx.cr6.eq) goto loc_88115D60;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,88(r11)
	PPC_STORE_U32(ctx.r11.u32 + 88, ctx.r10.u32);
loc_88115D60:
	// clrlwi r10,r9,27
	ctx.r10.u64 = ctx.r9.u32 & 0x1F;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x88115e34
	if (!ctx.cr6.eq) goto loc_88115E34;
	// lis r10,4
	ctx.r10.s64 = 262144;
	// cmpw cr6,r8,r10
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x88115d80
	if (!ctx.cr6.lt) goto loc_88115D80;
	// addi r10,r8,4096
	ctx.r10.s64 = ctx.r8.s64 + 4096;
	// b 0x88115e30
	goto loc_88115E30;
loc_88115D80:
	// li r10,10
	ctx.r10.s64 = 10;
	// stw r10,104(r11)
	PPC_STORE_U32(ctx.r11.u32 + 104, ctx.r10.u32);
	// lwz r10,136(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 136);
	// addi r10,r10,-2
	ctx.r10.s64 = ctx.r10.s64 + -2;
	// clrlwi r9,r10,23
	ctx.r9.u64 = ctx.r10.u32 & 0x1FF;
	// stw r9,136(r11)
	PPC_STORE_U32(ctx.r11.u32 + 136, ctx.r9.u32);
	// blr 
	return;
loc_88115D9C:
	// cmpwi cr6,r9,420
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 420, ctx.xer);
	// blt cr6,0x88115e34
	if (ctx.cr6.lt) goto loc_88115E34;
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// lwz r10,26428(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26428);
	// clrlwi r9,r10,30
	ctx.r9.u64 = ctx.r10.u32 & 0x3;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x88115dc8
	if (!ctx.cr6.eq) goto loc_88115DC8;
	// cmpw cr6,r8,r6
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r6.s32, ctx.xer);
	// bge cr6,0x88115dc8
	if (!ctx.cr6.lt) goto loc_88115DC8;
	// addi r10,r8,8192
	ctx.r10.s64 = ctx.r8.s64 + 8192;
	// stw r10,108(r11)
	PPC_STORE_U32(ctx.r11.u32 + 108, ctx.r10.u32);
loc_88115DC8:
	// lwz r10,88(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// cmpwi cr6,r10,160
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 160, ctx.xer);
	// bge cr6,0x88115e34
	if (!ctx.cr6.lt) goto loc_88115E34;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x88115e34
	if (!ctx.cr6.eq) goto loc_88115E34;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,88(r11)
	PPC_STORE_U32(ctx.r11.u32 + 88, ctx.r10.u32);
	// cmpwi cr6,r10,160
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 160, ctx.xer);
	// blt cr6,0x88115e34
	if (ctx.cr6.lt) goto loc_88115E34;
	// li r10,30
	ctx.r10.s64 = 30;
	// stw r10,104(r11)
	PPC_STORE_U32(ctx.r11.u32 + 104, ctx.r10.u32);
	// lwz r10,136(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 136);
	// addi r10,r10,-2
	ctx.r10.s64 = ctx.r10.s64 + -2;
	// clrlwi r9,r10,23
	ctx.r9.u64 = ctx.r10.u32 & 0x1FF;
	// stw r9,136(r11)
	PPC_STORE_U32(ctx.r11.u32 + 136, ctx.r9.u32);
	// blr 
	return;
loc_88115E08:
	// cmpwi cr6,r10,30
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 30, ctx.xer);
	// bne cr6,0x88115e34
	if (!ctx.cr6.eq) goto loc_88115E34;
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// lwz r10,26428(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26428);
	// clrlwi r9,r10,30
	ctx.r9.u64 = ctx.r10.u32 & 0x3;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x88115e34
	if (!ctx.cr6.eq) goto loc_88115E34;
	// cmpw cr6,r8,r6
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r6.s32, ctx.xer);
	// bge cr6,0x88115e34
	if (!ctx.cr6.lt) goto loc_88115E34;
	// addi r10,r8,8192
	ctx.r10.s64 = ctx.r8.s64 + 8192;
loc_88115E30:
	// stw r10,108(r11)
	PPC_STORE_U32(ctx.r11.u32 + 108, ctx.r10.u32);
loc_88115E34:
	// lwz r10,136(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 136);
	// addi r10,r10,-2
	ctx.r10.s64 = ctx.r10.s64 + -2;
	// clrlwi r9,r10,23
	ctx.r9.u64 = ctx.r10.u32 & 0x1FF;
	// stw r9,136(r11)
	PPC_STORE_U32(ctx.r11.u32 + 136, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88115E48"))) PPC_WEAK_FUNC(sub_88115E48);
PPC_FUNC_IMPL(__imp__sub_88115E48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88115E50;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,2300(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2300);
	// lis r9,-30667
	ctx.r9.s64 = -2009792512;
	// lwz r8,2304(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r11,r9,4736
	ctx.r11.s64 = ctx.r9.s64 + 4736;
	// addi r31,r11,2
	ctx.r31.s64 = ctx.r11.s64 + 2;
	// lwz r7,156(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 156);
	// lwz r6,160(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 160);
	// srawi r5,r7,16
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFFFF) != 0);
	ctx.r5.s64 = ctx.r7.s32 >> 16;
	// lwz r4,0(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r3,4(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// addze r11,r5
	temp.s64 = ctx.r5.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r11.s64 = temp.s64;
	// srawi r10,r6,16
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xFFFF) != 0);
	ctx.r10.s64 = ctx.r6.s32 >> 16;
	// rlwinm r9,r11,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// addze r8,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r8.s64 = temp.s64;
	// subf r29,r9,r4
	ctx.r29.s64 = ctx.r4.s64 - ctx.r9.s64;
	// rlwinm r7,r8,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// subf r28,r7,r3
	ctx.r28.s64 = ctx.r3.s64 - ctx.r7.s64;
loc_88115E9C:
	// lhz r11,-2(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + -2);
	// li r6,110
	ctx.r6.s64 = 110;
	// lhz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 0);
	// addi r3,r30,1382
	ctx.r3.s64 = ctx.r30.s64 + 1382;
	// rotlwi r11,r11,16
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 16);
	// rotlwi r10,r10,16
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 16);
	// add r4,r11,r29
	ctx.r4.u64 = ctx.r11.u64 + ctx.r29.u64;
	// add r5,r10,r28
	ctx.r5.u64 = ctx.r10.u64 + ctx.r28.u64;
	// bl 0x881538c0
	ctx.lr = 0x88115EC0;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88115ed8
	if (ctx.cr6.eq) goto loc_88115ED8;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
loc_88115ED8:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// cmplwi cr6,r30,8
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 8, ctx.xer);
	// blt cr6,0x88115e9c
	if (ctx.cr6.lt) goto loc_88115E9C;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88115EF0"))) PPC_WEAK_FUNC(sub_88115EF0);
PPC_FUNC_IMPL(__imp__sub_88115EF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,2300(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2300);
	// li r6,50
	ctx.r6.s64 = 50;
	// lwz r10,2304(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r9,160(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 160);
	// lwz r8,156(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 156);
	// srawi r7,r9,16
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xFFFF) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 16;
	// lwz r5,16(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addze r11,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r11.s64 = temp.s64;
	// srawi r10,r8,16
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFF) != 0);
	ctx.r10.s64 = ctx.r8.s32 >> 16;
	// addi r9,r11,12
	ctx.r9.s64 = ctx.r11.s64 + 12;
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r11.s64 = temp.s64;
	// rlwinm r8,r9,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// addi r7,r11,8
	ctx.r7.s64 = ctx.r11.s64 + 8;
	// clrlwi r11,r5,28
	ctx.r11.u64 = ctx.r5.u32 & 0xF;
	// rlwinm r10,r7,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// subf r5,r8,r4
	ctx.r5.s64 = ctx.r4.s64 - ctx.r8.s64;
	// subf r4,r10,r3
	ctx.r4.s64 = ctx.r3.s64 - ctx.r10.s64;
	// addi r3,r11,1390
	ctx.r3.s64 = ctx.r11.s64 + 1390;
	// b 0x881538c0
	sub_881538C0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88115F44"))) PPC_WEAK_FUNC(sub_88115F44);
PPC_FUNC_IMPL(__imp__sub_88115F44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88115F48"))) PPC_WEAK_FUNC(sub_88115F48);
PPC_FUNC_IMPL(__imp__sub_88115F48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88115F50;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lwz r10,184(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// lwz r11,168(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// add r28,r10,r11
	ctx.r28.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r9,148(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// lwz r9,2300(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2300);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r8,156(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 156);
	// lwz r7,160(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
	// beq cr6,0x88115fa0
	if (ctx.cr6.eq) goto loc_88115FA0;
	// srawi r6,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 1;
	// addze r5,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r5.s64 = temp.s64;
	// srawi r4,r7,1
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r4.s64 = ctx.r7.s32 >> 1;
	// subf r30,r5,r11
	ctx.r30.s64 = ctx.r11.s64 - ctx.r5.s64;
	// addze r3,r4
	temp.s64 = ctx.r4.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r3.s64 = temp.s64;
	// subf r29,r3,r10
	ctx.r29.s64 = ctx.r10.s64 - ctx.r3.s64;
	// b 0x88115fc0
	goto loc_88115FC0;
loc_88115FA0:
	// srawi r6,r8,16
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFF) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 16;
	// addze r5,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r5.s64 = temp.s64;
	// srawi r4,r7,16
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFFFF) != 0);
	ctx.r4.s64 = ctx.r7.s32 >> 16;
	// rlwinm r3,r5,16,0,15
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// addze r9,r4
	temp.s64 = ctx.r4.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r9.s64 = temp.s64;
	// subf r30,r3,r11
	ctx.r30.s64 = ctx.r11.s64 - ctx.r3.s64;
	// rlwinm r8,r9,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// subf r29,r8,r10
	ctx.r29.s64 = ctx.r10.s64 - ctx.r8.s64;
loc_88115FC0:
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// lwz r10,116(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// srawi r9,r11,4
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xF) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 4;
	// add r8,r10,r29
	ctx.r8.u64 = ctx.r10.u64 + ctx.r29.u64;
	// addze r11,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r11.s64 = temp.s64;
	// addis r5,r8,-3
	ctx.r5.s64 = ctx.r8.s64 + -196608;
	// addi r3,r11,1411
	ctx.r3.s64 = ctx.r11.s64 + 1411;
	// bl 0x881538c0
	ctx.lr = 0x88115FE8;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88115ff8
	if (ctx.cr6.eq) goto loc_88115FF8;
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_88115FF8:
	// lwz r10,124(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// lwz r11,116(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// srawi r9,r10,4
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 4;
	// add r8,r11,r29
	ctx.r8.u64 = ctx.r11.u64 + ctx.r29.u64;
	// addze r11,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r11.s64 = temp.s64;
	// addis r5,r8,9
	ctx.r5.s64 = ctx.r8.s64 + 589824;
	// addi r3,r11,1411
	ctx.r3.s64 = ctx.r11.s64 + 1411;
	// bl 0x881538c0
	ctx.lr = 0x88116020;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88116030
	if (ctx.cr6.eq) goto loc_88116030;
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_88116030:
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,1406
	ctx.r3.s64 = 1406;
	// bl 0x881538c0
	ctx.lr = 0x88116044;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88116054
	if (ctx.cr6.eq) goto loc_88116054;
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_88116054:
	// lwz r11,116(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// li r3,1407
	ctx.r3.s64 = 1407;
	// addis r5,r11,27
	ctx.r5.s64 = ctx.r11.s64 + 1769472;
	// bl 0x881538c0
	ctx.lr = 0x88116070;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88116080
	if (ctx.cr6.eq) goto loc_88116080;
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_88116080:
	// lwz r10,116(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// lwz r11,120(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,1409
	ctx.r3.s64 = 1409;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// addis r5,r11,46
	ctx.r5.s64 = ctx.r11.s64 + 3014656;
	// bl 0x881538c0
	ctx.lr = 0x881160A4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x881160b4
	if (ctx.cr6.eq) goto loc_881160B4;
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_881160B4:
	// lwz r11,116(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// li r3,1410
	ctx.r3.s64 = 1410;
	// addis r5,r11,52
	ctx.r5.s64 = ctx.r11.s64 + 3407872;
	// bl 0x881538c0
	ctx.lr = 0x881160D0;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x881160e0
	if (ctx.cr6.eq) goto loc_881160E0;
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_881160E0:
	// lwz r11,116(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// lwz r10,120(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,1408
	ctx.r3.s64 = 1408;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// addis r5,r11,26
	ctx.r5.s64 = ctx.r11.s64 + 1703936;
	// bl 0x881538c0
	ctx.lr = 0x88116104;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88116114
	if (ctx.cr6.eq) goto loc_88116114;
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_88116114:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8811611C"))) PPC_WEAK_FUNC(sub_8811611C);
PPC_FUNC_IMPL(__imp__sub_8811611C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88116120"))) PPC_WEAK_FUNC(sub_88116120);
PPC_FUNC_IMPL(__imp__sub_88116120) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071144
	ctx.lr = 0x88116128;
	__savegprlr_23(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2304(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2304);
	// lis r11,240
	ctx.r11.s64 = 15728640;
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// li r23,0
	ctx.r23.s64 = 0;
	// lwz r5,4(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpw cr6,r5,r11
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r11.s32, ctx.xer);
	// bgt cr6,0x8811614c
	if (ctx.cr6.gt) goto loc_8811614C;
	// stw r23,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r23.u32);
loc_8811614C:
	// lwz r11,152(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 152);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x88116328
	if (ctx.cr6.lt) goto loc_88116328;
	// beq cr6,0x881162fc
	if (ctx.cr6.eq) goto loc_881162FC;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x88116334
	if (!ctx.cr6.lt) goto loc_88116334;
	// lwz r11,204(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 204);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88116334
	if (ctx.cr6.eq) goto loc_88116334;
	// lis r11,-30714
	ctx.r11.s64 = -2012872704;
	// lwz r10,196(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 196);
	// lis r9,-30643
	ctx.r9.s64 = -2008219648;
	// addi r29,r11,9552
	ctx.r29.s64 = ctx.r11.s64 + 9552;
	// addic. r11,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r11.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,196(r31)
	PPC_STORE_U32(ctx.r31.u32 + 196, ctx.r11.u32);
	// lwz r27,26276(r9)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r9.u32 + 26276);
	// bge 0x8811623c
	if (!ctx.cr0.lt) goto loc_8811623C;
	// lwz r11,200(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 200);
	// lis r10,112
	ctx.r10.s64 = 7340032;
	// addis r9,r5,64
	ctx.r9.s64 = ctx.r5.s64 + 4194304;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// stw r11,196(r31)
	PPC_STORE_U32(ctx.r31.u32 + 196, ctx.r11.u32);
	// blt cr6,0x8811623c
	if (ctx.cr6.lt) goto loc_8811623C;
	// lwz r30,220(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 220);
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r26,16
	ctx.r26.s64 = 16;
	// rlwinm r10,r30,2,21,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0x7FC;
	// ori r28,r11,32768
	ctx.r28.u64 = ctx.r11.u64 | 32768;
loc_881161BC:
	// clrlwi r11,r30,23
	ctx.r11.u64 = ctx.r30.u32 & 0x1FF;
	// lwzx r8,r10,r29
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r29.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// addi r7,r11,128
	ctx.r7.s64 = ctx.r11.s64 + 128;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// rlwinm r11,r8,7,0,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 7) & 0xFFFFFF80;
	// rlwinm r6,r7,2,21,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x7FC;
	// add r4,r11,r9
	ctx.r4.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwzx r5,r6,r29
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r29.u32);
	// add r3,r5,r28
	ctx.r3.u64 = ctx.r5.u64 + ctx.r28.u64;
	// rlwinm r11,r3,7,0,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 7) & 0xFFFFFF80;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bne cr6,0x88116214
	if (!ctx.cr6.eq) goto loc_88116214;
	// clrlwi r7,r30,16
	ctx.r7.u64 = ctx.r30.u32 & 0xFFFF;
	// stw r24,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r24.u32);
	// li r6,-8
	ctx.r6.s64 = -8;
	// sth r23,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r23.u16);
	// li r3,59
	ctx.r3.s64 = 59;
	// bl 0x8815c948
	ctx.lr = 0x8811620C;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8815c860
	ctx.lr = 0x88116214;
	sub_8815C860(ctx, base);
loc_88116214:
	// addi r11,r30,32
	ctx.r11.s64 = ctx.r30.s64 + 32;
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// clrlwi r30,r11,23
	ctx.r30.u64 = ctx.r11.u32 & 0x1FF;
	// rlwinm r10,r30,2,21,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0x7FC;
	// bne 0x881161bc
	if (!ctx.cr0.eq) goto loc_881161BC;
	// lwz r10,220(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 220);
	// lwz r11,224(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 224);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// clrlwi r10,r11,23
	ctx.r10.u64 = ctx.r11.u32 & 0x1FF;
	// stw r10,220(r31)
	PPC_STORE_U32(ctx.r31.u32 + 220, ctx.r10.u32);
loc_8811623C:
	// lwz r11,212(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 212);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,212(r31)
	PPC_STORE_U32(ctx.r31.u32 + 212, ctx.r11.u32);
	// bge 0x88116334
	if (!ctx.cr0.lt) goto loc_88116334;
	// lwz r11,216(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 216);
	// li r26,16
	ctx.r26.s64 = 16;
	// lwz r30,228(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 228);
	// li r25,1
	ctx.r25.s64 = 1;
	// rlwinm r10,r30,2,21,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0x7FC;
	// stw r11,212(r31)
	PPC_STORE_U32(ctx.r31.u32 + 212, ctx.r11.u32);
loc_88116264:
	// clrlwi r11,r30,23
	ctx.r11.u64 = ctx.r30.u32 & 0x1FF;
	// lwzx r8,r10,r29
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r29.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// addi r7,r11,128
	ctx.r7.s64 = ctx.r11.s64 + 128;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// rlwinm r11,r8,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r6,r7,2,21,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x7FC;
	// add r4,r11,r9
	ctx.r4.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwzx r11,r6,r29
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r29.u32);
	// addi r5,r11,16384
	ctx.r5.s64 = ctx.r11.s64 + 16384;
	// rlwinm r11,r5,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bne cr6,0x881162cc
	if (!ctx.cr6.eq) goto loc_881162CC;
	// clrlwi r7,r30,16
	ctx.r7.u64 = ctx.r30.u32 & 0xFFFF;
	// stw r24,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r24.u32);
	// li r6,-16
	ctx.r6.s64 = -16;
	// sth r23,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r23.u16);
	// li r3,50
	ctx.r3.s64 = 50;
	// bl 0x8815c948
	ctx.lr = 0x881162B4;
	sub_8815C948(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x8815c860
	ctx.lr = 0x881162C0;
	sub_8815C860(ctx, base);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x881162cc
	if (ctx.cr6.eq) goto loc_881162CC;
	// sth r25,16(r28)
	PPC_STORE_U16(ctx.r28.u32 + 16, ctx.r25.u16);
loc_881162CC:
	// addi r11,r30,-32
	ctx.r11.s64 = ctx.r30.s64 + -32;
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// clrlwi r30,r11,23
	ctx.r30.u64 = ctx.r11.u32 & 0x1FF;
	// rlwinm r10,r30,2,21,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0x7FC;
	// bne 0x88116264
	if (!ctx.cr0.eq) goto loc_88116264;
	// lwz r10,228(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 228);
	// lwz r11,232(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 232);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// clrlwi r10,r11,23
	ctx.r10.u64 = ctx.r11.u32 & 0x1FF;
	// stw r10,228(r31)
	PPC_STORE_U32(ctx.r31.u32 + 228, ctx.r10.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
loc_881162FC:
	// lwz r11,112(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x88116334
	if (!ctx.cr6.eq) goto loc_88116334;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x88095590
	ctx.lr = 0x88116314;
	sub_88095590(ctx, base);
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r3,184(r31)
	PPC_STORE_U32(ctx.r31.u32 + 184, ctx.r3.u32);
	// stw r11,152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 152, ctx.r11.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
loc_88116328:
	// li r25,1
	ctx.r25.s64 = 1;
	// stw r25,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r25.u32);
	// stw r25,152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 152, ctx.r25.u32);
loc_88116334:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8811633C"))) PPC_WEAK_FUNC(sub_8811633C);
PPC_FUNC_IMPL(__imp__sub_8811633C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

