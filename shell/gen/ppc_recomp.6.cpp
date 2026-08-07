#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_8208EFAC"))) PPC_WEAK_FUNC(sub_8208EFAC);
PPC_FUNC_IMPL(__imp__sub_8208EFAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8208EFB0"))) PPC_WEAK_FUNC(sub_8208EFB0);
PPC_FUNC_IMPL(__imp__sub_8208EFB0) {
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
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// mr r5,r9
	ctx.r5.u64 = ctx.r9.u64;
	// rlwinm r9,r7,30,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 30) & 0x1;
	// cmpwi cr6,r8,-1
	ctx.cr6.compare<int32_t>(ctx.r8.s32, -1, ctx.xer);
	// beq cr6,0x8208efe0
	if (ctx.cr6.eq) goto loc_8208EFE0;
	// li r10,1
	ctx.r10.s64 = 1;
	// slw r10,r10,r8
	ctx.r10.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r8.u8 & 0x3F));
	// rlwinm r10,r10,24,0,7
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFF000000;
	// or r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 | ctx.r9.u64;
loc_8208EFE0:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
	// mr r7,r11
	ctx.r7.u64 = ctx.r11.u64;
	// addi r6,r10,-480
	ctx.r6.s64 = ctx.r10.s64 + -480;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d5774
	ctx.lr = 0x8208EFF8;
	__imp__ExCreateThread(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x8208f00c
	if (!ctx.cr0.lt) goto loc_8208F00C;
	// bl 0x8208dc98
	ctx.lr = 0x8208F004;
	sub_8208DC98(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8208f010
	goto loc_8208F010;
loc_8208F00C:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_8208F010:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8208F020"))) PPC_WEAK_FUNC(sub_8208F020);
PPC_FUNC_IMPL(__imp__sub_8208F020) {
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
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r31,1627
	ctx.r31.s64 = 1627;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8208f04c
	if (!ctx.cr6.eq) goto loc_8208F04C;
	// li r31,0
	ctx.r31.s64 = 0;
	// b 0x8208f078
	goto loc_8208F078;
loc_8208F04C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d5374
	ctx.lr = 0x8208F054;
	__imp__XamGetExecutionId(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8208f078
	if (ctx.cr0.lt) goto loc_8208F078;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r10,r30,16,16,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 16) & 0xFFFF;
	// lhz r11,12(r11)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r11.u32 + 12);
	// subf r11,r11,r10
	ctx.r11.s64 = ctx.r10.s64 - ctx.r11.s64;
	// subfic r11,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r11.s64 = 0 - ctx.r11.s64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r31,r11,r31
	ctx.r31.u64 = ctx.r11.u64 & ctx.r31.u64;
loc_8208F078:
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

__attribute__((alias("__imp__sub_8208F094"))) PPC_WEAK_FUNC(sub_8208F094);
PPC_FUNC_IMPL(__imp__sub_8208F094) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8208F098"))) PPC_WEAK_FUNC(sub_8208F098);
PPC_FUNC_IMPL(__imp__sub_8208F098) {
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
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// li r7,34
	ctx.r7.s64 = 34;
	// li r6,56
	ctx.r6.s64 = 56;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r11,5040(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 5040);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,32(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8208F0D0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x8208f0e4
	if (!ctx.cr0.lt) goto loc_8208F0E4;
	// bl 0x8208dc98
	ctx.lr = 0x8208F0DC;
	sub_8208DC98(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8208f0f0
	goto loc_8208F0F0;
loc_8208F0E4:
	// ld r11,136(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// li r3,1
	ctx.r3.s64 = 1;
	// std r11,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
loc_8208F0F0:
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

__attribute__((alias("__imp__sub_8208F104"))) PPC_WEAK_FUNC(sub_8208F104);
PPC_FUNC_IMPL(__imp__sub_8208F104) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8208F108"))) PPC_WEAK_FUNC(sub_8208F108);
PPC_FUNC_IMPL(__imp__sub_8208F108) {
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
	// lis r11,30403
	ctx.r11.s64 = 1992491008;
	// stw r4,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r4.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// ori r11,r11,62032
	ctx.r11.u64 = ctx.r11.u64 | 62032;
	// stw r10,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r10.u32);
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
	// bl 0x820901e8
	ctx.lr = 0x8208F138;
	sub_820901E8(ctx, base);
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

__attribute__((alias("__imp__sub_8208F150"))) PPC_WEAK_FUNC(sub_8208F150);
PPC_FUNC_IMPL(__imp__sub_8208F150) {
	PPC_FUNC_PROLOGUE();
	// b 0x8210e878
	sub_8210E878(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8208F154"))) PPC_WEAK_FUNC(sub_8208F154);
PPC_FUNC_IMPL(__imp__sub_8208F154) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8208F158"))) PPC_WEAK_FUNC(sub_8208F158);
PPC_FUNC_IMPL(__imp__sub_8208F158) {
	PPC_FUNC_PROLOGUE();
	// b 0x82090260
	sub_82090260(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8208F15C"))) PPC_WEAK_FUNC(sub_8208F15C);
PPC_FUNC_IMPL(__imp__sub_8208F15C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8208F160"))) PPC_WEAK_FUNC(sub_8208F160);
PPC_FUNC_IMPL(__imp__sub_8208F160) {
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
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x8208f190
	if (!ctx.cr6.eq) goto loc_8208F190;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
loc_8208F17C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8208F180:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_8208F190:
	// bl 0x820900a0
	ctx.lr = 0x8208F194;
	sub_820900A0(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// blt cr6,0x8208f17c
	if (ctx.cr6.lt) goto loc_8208F17C;
	// beq cr6,0x8208f1c8
	if (ctx.cr6.eq) goto loc_8208F1C8;
	// cmplwi cr6,r3,6
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 6, ctx.xer);
	// beq cr6,0x8208f1bc
	if (ctx.cr6.eq) goto loc_8208F1BC;
	// cmplwi cr6,r3,7
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 7, ctx.xer);
	// beq cr6,0x8208f1bc
	if (ctx.cr6.eq) goto loc_8208F1BC;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// b 0x8208f180
	goto loc_8208F180;
loc_8208F1BC:
	// lis r3,-32290
	ctx.r3.s64 = -2116157440;
	// ori r3,r3,8193
	ctx.r3.u64 = ctx.r3.u64 | 8193;
	// b 0x8208f180
	goto loc_8208F180;
loc_8208F1C8:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// b 0x8208f180
	goto loc_8208F180;
}

__attribute__((alias("__imp__sub_8208F1D4"))) PPC_WEAK_FUNC(sub_8208F1D4);
PPC_FUNC_IMPL(__imp__sub_8208F1D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8208F1D8"))) PPC_WEAK_FUNC(sub_8208F1D8);
PPC_FUNC_IMPL(__imp__sub_8208F1D8) {
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
	// lis r11,30403
	ctx.r11.s64 = 1992491008;
	// stw r4,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r4.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// ori r11,r11,62033
	ctx.r11.u64 = ctx.r11.u64 | 62033;
	// stw r10,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r10.u32);
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
	// bl 0x82090440
	ctx.lr = 0x8208F208;
	sub_82090440(ctx, base);
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

__attribute__((alias("__imp__sub_8208F220"))) PPC_WEAK_FUNC(sub_8208F220);
PPC_FUNC_IMPL(__imp__sub_8208F220) {
	PPC_FUNC_PROLOGUE();
	// b 0x820904b8
	sub_820904B8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8208F224"))) PPC_WEAK_FUNC(sub_8208F224);
PPC_FUNC_IMPL(__imp__sub_8208F224) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8208F228"))) PPC_WEAK_FUNC(sub_8208F228);
PPC_FUNC_IMPL(__imp__sub_8208F228) {
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
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x8208f258
	if (!ctx.cr6.eq) goto loc_8208F258;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
loc_8208F244:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8208F248:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_8208F258:
	// bl 0x82090348
	ctx.lr = 0x8208F25C;
	sub_82090348(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// blt cr6,0x8208f244
	if (ctx.cr6.lt) goto loc_8208F244;
	// beq cr6,0x8208f288
	if (ctx.cr6.eq) goto loc_8208F288;
	// cmplwi cr6,r3,6
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 6, ctx.xer);
	// beq cr6,0x8208f27c
	if (ctx.cr6.eq) goto loc_8208F27C;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// b 0x8208f248
	goto loc_8208F248;
loc_8208F27C:
	// lis r3,-32290
	ctx.r3.s64 = -2116157440;
	// ori r3,r3,8193
	ctx.r3.u64 = ctx.r3.u64 | 8193;
	// b 0x8208f248
	goto loc_8208F248;
loc_8208F288:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// b 0x8208f248
	goto loc_8208F248;
}

__attribute__((alias("__imp__sub_8208F294"))) PPC_WEAK_FUNC(sub_8208F294);
PPC_FUNC_IMPL(__imp__sub_8208F294) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8208F298"))) PPC_WEAK_FUNC(sub_8208F298);
PPC_FUNC_IMPL(__imp__sub_8208F298) {
	PPC_FUNC_PROLOGUE();
	// cmpwi cr6,r4,-1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1, ctx.xer);
	// bne cr6,0x8208f2a8
	if (!ctx.cr6.eq) goto loc_8208F2A8;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8208F2A8:
	// clrldi r11,r4,32
	ctx.r11.u64 = ctx.r4.u64 & 0xFFFFFFFF;
	// mulli r11,r11,-10000
	ctx.r11.s64 = ctx.r11.s64 * -10000;
	// std r11,0(r3)
	PPC_STORE_U64(ctx.r3.u32 + 0, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8208F2B8"))) PPC_WEAK_FUNC(sub_8208F2B8);
PPC_FUNC_IMPL(__imp__sub_8208F2B8) {
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
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8208f2e8
	if (ctx.cr6.eq) goto loc_8208F2E8;
	// clrldi r11,r3,32
	ctx.r11.u64 = ctx.r3.u64 & 0xFFFFFFFF;
	// mulli r11,r11,-10000
	ctx.r11.s64 = ctx.r11.s64 * -10000;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// b 0x8208f2f8
	goto loc_8208F2F8;
loc_8208F2E8:
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
loc_8208F2F8:
	// clrlwi r30,r31,24
	ctx.r30.u64 = ctx.r31.u32 & 0xFF;
loc_8208F2FC:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x821d5784
	ctx.lr = 0x8208F30C;
	__imp__KeDelayExecutionThread(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8208f31c
	if (ctx.cr6.eq) goto loc_8208F31C;
	// cmpwi cr6,r3,257
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 257, ctx.xer);
	// beq cr6,0x8208f2fc
	if (ctx.cr6.eq) goto loc_8208F2FC;
loc_8208F31C:
	// addi r11,r3,-192
	ctx.r11.s64 = ctx.r3.s64 + -192;
	// li r10,192
	ctx.r10.s64 = 192;
	// addic r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 & ctx.r10.u64;
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

__attribute__((alias("__imp__sub_8208F348"))) PPC_WEAK_FUNC(sub_8208F348);
PPC_FUNC_IMPL(__imp__sub_8208F348) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8208daf8
	ctx.lr = 0x8208F364;
	sub_8208DAF8(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// blt cr6,0x8208f398
	if (ctx.cr6.lt) goto loc_8208F398;
	// beq cr6,0x8208f388
	if (ctx.cr6.eq) goto loc_8208F388;
	// cmplwi cr6,r3,3
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 3, ctx.xer);
	// blt cr6,0x8208f380
	if (ctx.cr6.lt) goto loc_8208F380;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x8208f39c
	goto loc_8208F39C;
loc_8208F380:
	// lwz r11,248(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 248);
	// b 0x8208f38c
	goto loc_8208F38C;
loc_8208F388:
	// lwz r11,164(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
loc_8208F38C:
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x8208f39c
	goto loc_8208F39C;
loc_8208F398:
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_8208F39C:
	// mulli r11,r11,60
	ctx.r11.s64 = ctx.r11.s64 * 60;
	// lis r10,152
	ctx.r10.s64 = 9961472;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// ori r10,r10,38528
	ctx.r10.u64 = ctx.r10.u64 | 38528;
	// mulld r11,r11,r10
	ctx.r11.s64 = ctx.r11.s64 * ctx.r10.s64;
	// std r11,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8208F3C8"))) PPC_WEAK_FUNC(sub_8208F3C8);
PPC_FUNC_IMPL(__imp__sub_8208F3C8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r3,1256(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1256);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8208F3D4"))) PPC_WEAK_FUNC(sub_8208F3D4);
PPC_FUNC_IMPL(__imp__sub_8208F3D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8208F3D8"))) PPC_WEAK_FUNC(sub_8208F3D8);
PPC_FUNC_IMPL(__imp__sub_8208F3D8) {
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
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r10,4488(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4488);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8208f408
	if (ctx.cr6.eq) goto loc_8208F408;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8208F408;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8208F408:
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r10,r10,128
	ctx.r10.s64 = ctx.r10.s64 + 128;
	// addi r30,r11,140
	ctx.r30.s64 = ctx.r11.s64 + 140;
	// mr r31,r10
	ctx.r31.u64 = ctx.r10.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplw cr6,r10,r30
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r30.u32, ctx.xer);
	// bge cr6,0x8208f458
	if (!ctx.cr6.lt) goto loc_8208F458;
loc_8208F428:
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8208f4a0
	if (!ctx.cr6.eq) goto loc_8208F4A0;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8208f444
	if (ctx.cr6.eq) goto loc_8208F444;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8208F444;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8208F444:
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// blt cr6,0x8208f428
	if (ctx.cr6.lt) goto loc_8208F428;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8208f4a0
	if (!ctx.cr6.eq) goto loc_8208F4A0;
loc_8208F458:
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// addi r30,r11,124
	ctx.r30.s64 = ctx.r11.s64 + 124;
	// mr r31,r10
	ctx.r31.u64 = ctx.r10.u64;
	// cmplw cr6,r10,r30
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r30.u32, ctx.xer);
	// bge cr6,0x8208f49c
	if (!ctx.cr6.lt) goto loc_8208F49C;
loc_8208F474:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8208f490
	if (ctx.cr6.eq) goto loc_8208F490;
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8208f490
	if (ctx.cr6.eq) goto loc_8208F490;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8208F490;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8208F490:
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// blt cr6,0x8208f474
	if (ctx.cr6.lt) goto loc_8208F474;
loc_8208F49C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8208F4A0:
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

__attribute__((alias("__imp__sub_8208F4B8"))) PPC_WEAK_FUNC(sub_8208F4B8);
PPC_FUNC_IMPL(__imp__sub_8208F4B8) {
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
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r10,r10,0
	ctx.r10.s64 = ctx.r10.s64 + 0;
	// addi r30,r11,12
	ctx.r30.s64 = ctx.r11.s64 + 12;
	// mr r31,r10
	ctx.r31.u64 = ctx.r10.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplw cr6,r10,r30
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r30.u32, ctx.xer);
	// bge cr6,0x8208f514
	if (!ctx.cr6.lt) goto loc_8208F514;
loc_8208F4EC:
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8208f514
	if (!ctx.cr6.eq) goto loc_8208F514;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8208f508
	if (ctx.cr6.eq) goto loc_8208F508;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8208F508;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8208F508:
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// blt cr6,0x8208f4ec
	if (ctx.cr6.lt) goto loc_8208F4EC;
loc_8208F514:
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

__attribute__((alias("__imp__sub_8208F52C"))) PPC_WEAK_FUNC(sub_8208F52C);
PPC_FUNC_IMPL(__imp__sub_8208F52C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8208F530"))) PPC_WEAK_FUNC(sub_8208F530);
PPC_FUNC_IMPL(__imp__sub_8208F530) {
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r30,16
	ctx.r30.s64 = 1048576;
	// lwz r11,1264(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1264);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8208f588
	if (ctx.cr6.eq) goto loc_8208F588;
	// lis r4,2
	ctx.r4.s64 = 131072;
	// lwz r3,88(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// ori r4,r4,1025
	ctx.r4.u64 = ctx.r4.u64 | 1025;
	// bl 0x821d5794
	ctx.lr = 0x8208F56C;
	__imp__RtlImageXexHeaderField(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8208f588
	if (ctx.cr0.eq) goto loc_8208F588;
	// lwz r30,0(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x8208f588
	if (!ctx.cr6.eq) goto loc_8208F588;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8208f5ec
	goto loc_8208F5EC;
loc_8208F588:
	// li r10,6
	ctx.r10.s64 = 6;
	// addi r11,r1,72
	ctx.r11.s64 = ctx.r1.s64 + 72;
	// li r9,0
	ctx.r9.s64 = 0;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8208F598:
	// stdu r9,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r9.u64);
	ctx.r11.u32 = ea;
	// bdnz 0x8208f598
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8208F598;
	// lis r31,-32224
	ctx.r31.s64 = -2111832064;
	// li r11,48
	ctx.r11.s64 = 48;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lwz r11,-23076(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -23076);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8208f5d8
	if (!ctx.cr6.eq) goto loc_8208F5D8;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,4096
	ctx.r6.s64 = 4096;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x8208be88
	ctx.lr = 0x8208F5D4;
	sub_8208BE88(ctx, base);
	// stw r3,-23076(r31)
	PPC_STORE_U32(ctx.r31.u32 + -23076, ctx.r3.u32);
loc_8208F5D8:
	// bl 0x82090510
	ctx.lr = 0x8208F5DC;
	sub_82090510(ctx, base);
	// lwz r11,-23076(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -23076);
	// addi r11,r11,0
	ctx.r11.s64 = ctx.r11.s64 + 0;
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r3,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
loc_8208F5EC:
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

__attribute__((alias("__imp__sub_8208F604"))) PPC_WEAK_FUNC(sub_8208F604);
PPC_FUNC_IMPL(__imp__sub_8208F604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8208F608"))) PPC_WEAK_FUNC(sub_8208F608);
PPC_FUNC_IMPL(__imp__sub_8208F608) {
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
	// bl 0x8208f530
	ctx.lr = 0x8208F618;
	sub_8208F530(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8208f650
	if (!ctx.cr0.eq) goto loc_8208F650;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r11,1416(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1416);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8208f648
	if (ctx.cr6.eq) goto loc_8208F648;
	// lwz r11,24(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,2
	ctx.r3.s64 = 2;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8208F648;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8208F648:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x821d57a4
	ctx.lr = 0x8208F650;
	__imp__HalReturnToFirmware(ctx, base);
loc_8208F650:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8208F660"))) PPC_WEAK_FUNC(sub_8208F660);
PPC_FUNC_IMPL(__imp__sub_8208F660) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8208F668;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmpwi cr6,r4,-1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1, ctx.xer);
	// bne cr6,0x8208f68c
	if (!ctx.cr6.eq) goto loc_8208F68C;
	// bl 0x8207adf0
	ctx.lr = 0x8208F688;
	sub_8207ADF0(ctx, base);
	// addi r4,r3,1
	ctx.r4.s64 = ctx.r3.s64 + 1;
loc_8208F68C:
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// ble cr6,0x8208f764
	if (!ctx.cr6.gt) goto loc_8208F764;
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// li r9,1
	ctx.r9.s64 = 1;
loc_8208F69C:
	// lhz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r28.u32 + 0);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmplwi cr6,r10,127
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 127, ctx.xer);
	// bgt cr6,0x8208f6c8
	if (ctx.cr6.gt) goto loc_8208F6C8;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmpw cr6,r30,r29
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r29.s32, ctx.xer);
	// bgt cr6,0x8208f75c
	if (ctx.cr6.gt) goto loc_8208F75C;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8208f75c
	if (ctx.cr6.eq) goto loc_8208F75C;
	// stb r10,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r10.u8);
	// b 0x8208f758
	goto loc_8208F758;
loc_8208F6C8:
	// cmplwi cr6,r11,2047
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2047, ctx.xer);
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// bgt cr6,0x8208f6f0
	if (ctx.cr6.gt) goto loc_8208F6F0;
	// cmpw cr6,r11,r29
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r29.s32, ctx.xer);
	// bgt cr6,0x8208f738
	if (ctx.cr6.gt) goto loc_8208F738;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8208f738
	if (ctx.cr6.eq) goto loc_8208F738;
	// li r8,192
	ctx.r8.s64 = 192;
	// rlwimi r8,r10,26,27,31
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r10.u32, 26) & 0x1F) | (ctx.r8.u64 & 0xFFFFFFFFFFFFFFE0);
	// b 0x8208f730
	goto loc_8208F730;
loc_8208F6F0:
	// cmpw cr6,r11,r29
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r29.s32, ctx.xer);
	// bgt cr6,0x8208f710
	if (ctx.cr6.gt) goto loc_8208F710;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8208f710
	if (ctx.cr6.eq) goto loc_8208F710;
	// li r8,224
	ctx.r8.s64 = 224;
	// rlwimi r8,r10,20,28,31
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r10.u32, 20) & 0xF) | (ctx.r8.u64 & 0xFFFFFFFFFFFFFFF0);
	// stb r8,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r8.u8);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
loc_8208F710:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmpw cr6,r11,r29
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r29.s32, ctx.xer);
	// bgt cr6,0x8208f738
	if (ctx.cr6.gt) goto loc_8208F738;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8208f738
	if (ctx.cr6.eq) goto loc_8208F738;
	// lhz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r28.u32 + 0);
	// li r8,128
	ctx.r8.s64 = 128;
	// rlwimi r8,r10,26,26,31
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r10.u32, 26) & 0x3F) | (ctx.r8.u64 & 0xFFFFFFFFFFFFFFC0);
loc_8208F730:
	// stb r8,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r8.u8);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
loc_8208F738:
	// addi r30,r11,1
	ctx.r30.s64 = ctx.r11.s64 + 1;
	// cmpw cr6,r30,r29
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r29.s32, ctx.xer);
	// bgt cr6,0x8208f75c
	if (ctx.cr6.gt) goto loc_8208F75C;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8208f75c
	if (ctx.cr6.eq) goto loc_8208F75C;
	// lhz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r28.u32 + 0);
	// rlwimi r11,r9,7,0,25
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r9.u32, 7) & 0xFFFFFFC0) | (ctx.r11.u64 & 0xFFFFFFFF0000003F);
	// stb r11,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r11.u8);
loc_8208F758:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
loc_8208F75C:
	// addi r28,r28,2
	ctx.r28.s64 = ctx.r28.s64 + 2;
	// bdnz 0x8208f69c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8208F69C;
loc_8208F764:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x8208f784
	if (ctx.cr6.eq) goto loc_8208F784;
	// cmpw cr6,r29,r30
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r30.s32, ctx.xer);
	// bge cr6,0x8208f784
	if (!ctx.cr6.lt) goto loc_8208F784;
	// li r3,122
	ctx.r3.s64 = 122;
	// bl 0x8208da08
	ctx.lr = 0x8208F77C;
	sub_8208DA08(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8208f788
	goto loc_8208F788;
loc_8208F784:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_8208F788:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8208F790"))) PPC_WEAK_FUNC(sub_8208F790);
PPC_FUNC_IMPL(__imp__sub_8208F790) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c968
	ctx.lr = 0x8208F798;
	__savegprlr_20(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r10,r24
	ctx.r10.u64 = ctx.r24.u64;
	// cmpwi cr6,r4,-1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1, ctx.xer);
	// bne cr6,0x8208f7d4
	if (!ctx.cr6.eq) goto loc_8208F7D4;
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
loc_8208F7B4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8208f7b4
	if (!ctx.cr6.eq) goto loc_8208F7B4;
	// subf r11,r24,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r24.s64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
loc_8208F7D4:
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// ble cr6,0x8208f96c
	if (!ctx.cr6.gt) goto loc_8208F96C;
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r5,r5,-2
	ctx.r5.s64 = ctx.r5.s64 + -2;
	// lis r29,-32226
	ctx.r29.s64 = -2111963136;
	// lis r28,-32226
	ctx.r28.s64 = -2111963136;
	// lis r27,-32226
	ctx.r27.s64 = -2111963136;
	// lis r26,-32226
	ctx.r26.s64 = -2111963136;
	// lis r25,-32226
	ctx.r25.s64 = -2111963136;
	// lis r21,-32226
	ctx.r21.s64 = -2111963136;
	// lis r20,-32226
	ctx.r20.s64 = -2111963136;
	// lis r22,-32226
	ctx.r22.s64 = -2111963136;
	// addi r23,r9,5080
	ctx.r23.s64 = ctx.r9.s64 + 5080;
	// addi r30,r11,5104
	ctx.r30.s64 = ctx.r11.s64 + 5104;
loc_8208F814:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// li r11,0
	ctx.r11.s64 = 0;
	// lbzx r9,r8,r30
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r30.u32);
	// extsb r9,r9
	ctx.r9.s64 = ctx.r9.s8;
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// subf r7,r24,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r24.s64;
	// add r7,r7,r10
	ctx.r7.u64 = ctx.r7.u64 + ctx.r10.u64;
	// cmpw cr6,r7,r4
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r4.s32, ctx.xer);
	// bgt cr6,0x8208f96c
	if (ctx.cr6.gt) goto loc_8208F96C;
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// blt cr6,0x8208f8b8
	if (ctx.cr6.lt) goto loc_8208F8B8;
	// beq cr6,0x8208f8a4
	if (ctx.cr6.eq) goto loc_8208F8A4;
	// cmplwi cr6,r9,3
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 3, ctx.xer);
	// blt cr6,0x8208f890
	if (ctx.cr6.lt) goto loc_8208F890;
	// beq cr6,0x8208f87c
	if (ctx.cr6.eq) goto loc_8208F87C;
	// cmplwi cr6,r9,5
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 5, ctx.xer);
	// blt cr6,0x8208f868
	if (ctx.cr6.lt) goto loc_8208F868;
	// bne cr6,0x8208f8c8
	if (!ctx.cr6.eq) goto loc_8208F8C8;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// rlwinm r11,r8,6,0,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 6) & 0xFFFFFFC0;
loc_8208F868:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// rlwinm r11,r11,6,0,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 6) & 0xFFFFFFC0;
loc_8208F87C:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// rlwinm r11,r11,6,0,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 6) & 0xFFFFFFC0;
loc_8208F890:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// rlwinm r11,r11,6,0,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 6) & 0xFFFFFFC0;
loc_8208F8A4:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// rlwinm r11,r11,6,0,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 6) & 0xFFFFFFC0;
loc_8208F8B8:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
loc_8208F8C8:
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,5052(r22)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r22.u32 + 5052);
	// lwzx r9,r9,r23
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r23.u32);
	// subf r11,r9,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r9.s64;
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// bgt cr6,0x8208f8f0
	if (ctx.cr6.gt) goto loc_8208F8F0;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// cmpw cr6,r3,r6
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r6.s32, ctx.xer);
	// bgt cr6,0x8208f964
	if (ctx.cr6.gt) goto loc_8208F964;
	// b 0x8208f90c
	goto loc_8208F90C;
loc_8208F8F0:
	// lwz r9,5056(r20)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r20.u32 + 5056);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// ble cr6,0x8208f918
	if (!ctx.cr6.gt) goto loc_8208F918;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// cmpw cr6,r3,r6
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r6.s32, ctx.xer);
	// bgt cr6,0x8208f964
	if (ctx.cr6.gt) goto loc_8208F964;
	// lwz r11,5048(r21)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r21.u32 + 5048);
loc_8208F90C:
	// sth r11,2(r5)
	PPC_STORE_U16(ctx.r5.u32 + 2, ctx.r11.u16);
	// addi r5,r5,2
	ctx.r5.s64 = ctx.r5.s64 + 2;
	// b 0x8208f964
	goto loc_8208F964;
loc_8208F918:
	// lwz r9,5064(r25)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r25.u32 + 5064);
	// addi r7,r3,1
	ctx.r7.s64 = ctx.r3.s64 + 1;
	// subf r11,r9,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r9.s64;
	// cmpw cr6,r7,r6
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r6.s32, ctx.xer);
	// bgt cr6,0x8208f944
	if (ctx.cr6.gt) goto loc_8208F944;
	// lwz r9,5060(r26)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r26.u32 + 5060);
	// lwz r8,5072(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 5072);
	// srw r9,r11,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r11.u32 >> (ctx.r9.u8 & 0x3F));
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// sth r9,2(r5)
	PPC_STORE_U16(ctx.r5.u32 + 2, ctx.r9.u16);
	// addi r5,r5,2
	ctx.r5.s64 = ctx.r5.s64 + 2;
loc_8208F944:
	// addi r3,r7,1
	ctx.r3.s64 = ctx.r7.s64 + 1;
	// cmpw cr6,r3,r6
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r6.s32, ctx.xer);
	// bgt cr6,0x8208f964
	if (ctx.cr6.gt) goto loc_8208F964;
	// lwz r9,5068(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 5068);
	// lwz r8,5076(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 5076);
	// and r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 & ctx.r11.u64;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// sthu r11,2(r5)
	ea = 2 + ctx.r5.u32;
	PPC_STORE_U16(ea, ctx.r11.u16);
	ctx.r5.u32 = ea;
loc_8208F964:
	// cmpw cr6,r31,r4
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r4.s32, ctx.xer);
	// blt cr6,0x8208f814
	if (ctx.cr6.lt) goto loc_8208F814;
loc_8208F96C:
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq cr6,0x8208f988
	if (ctx.cr6.eq) goto loc_8208F988;
	// cmpw cr6,r6,r3
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r3.s32, ctx.xer);
	// bge cr6,0x8208f988
	if (!ctx.cr6.lt) goto loc_8208F988;
	// li r3,122
	ctx.r3.s64 = 122;
	// bl 0x8208da08
	ctx.lr = 0x8208F984;
	sub_8208DA08(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8208F988:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9b8
	__restgprlr_20(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8208F990"))) PPC_WEAK_FUNC(sub_8208F990);
PPC_FUNC_IMPL(__imp__sub_8208F990) {
	PPC_FUNC_PROLOGUE();
	// lhz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// b 0x820905b0
	sub_820905B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8208F99C"))) PPC_WEAK_FUNC(sub_8208F99C);
PPC_FUNC_IMPL(__imp__sub_8208F99C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8208F9A0"))) PPC_WEAK_FUNC(sub_8208F9A0);
PPC_FUNC_IMPL(__imp__sub_8208F9A0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c968
	ctx.lr = 0x8208F9A8;
	__savegprlr_20(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r20,r4
	ctx.r20.u64 = ctx.r4.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// mr r21,r5
	ctx.r21.u64 = ctx.r5.u64;
	// mr r31,r6
	ctx.r31.u64 = ctx.r6.u64;
	// bl 0x82090658
	ctx.lr = 0x8208F9C8;
	sub_82090658(ctx, base);
	// lhz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r29.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8208fa00
	if (ctx.cr0.eq) goto loc_8208FA00;
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820905b8
	ctx.lr = 0x8208F9E0;
	sub_820905B8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8208fbe0
	if (ctx.cr0.eq) goto loc_8208FBE0;
	// ld r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r20.u32 + 0);
	// ld r10,0(r21)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r21.u32 + 0);
	// cmpd cr6,r11,r10
	ctx.cr6.compare<int64_t>(ctx.r11.s64, ctx.r10.s64, ctx.xer);
	// blt cr6,0x8208fbe0
	if (ctx.cr6.lt) goto loc_8208FBE0;
loc_8208F9F8:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8208fbe4
	goto loc_8208FBE4;
loc_8208FA00:
	// lha r22,6(r29)
	ctx.r22.s64 = int16_t(PPC_LOAD_U16(ctx.r29.u32 + 6));
	// cmpwi cr6,r22,5
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 5, ctx.xer);
	// bgt cr6,0x8208fbe0
	if (ctx.cr6.gt) goto loc_8208FBE0;
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// beq cr6,0x8208fbe0
	if (ctx.cr6.eq) goto loc_8208FBE0;
	// li r23,0
	ctx.r23.s64 = 0;
	// lhz r25,2(r29)
	ctx.r25.u64 = PPC_LOAD_U16(ctx.r29.u32 + 2);
	// clrlwi. r11,r31,24
	ctx.r11.u64 = ctx.r31.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lhz r31,4(r29)
	ctx.r31.u64 = PPC_LOAD_U16(ctx.r29.u32 + 4);
	// li r24,1
	ctx.r24.s64 = 1;
	// mr r26,r23
	ctx.r26.u64 = ctx.r23.u64;
	// bne 0x8208fa60
	if (!ctx.cr0.eq) goto loc_8208FA60;
	// lhz r11,114(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 114);
	// extsh r10,r25
	ctx.r10.s64 = ctx.r25.s16;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x8208fa50
	if (!ctx.cr6.lt) goto loc_8208FA50;
	// lhz r11,112(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 112);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// extsh r28,r11
	ctx.r28.s64 = ctx.r11.s16;
	// b 0x8208fa64
	goto loc_8208FA64;
loc_8208FA50:
	// lhz r28,112(r1)
	ctx.r28.u64 = PPC_LOAD_U16(ctx.r1.u32 + 112);
	// bgt cr6,0x8208fa64
	if (ctx.cr6.gt) goto loc_8208FA64;
	// mr r26,r24
	ctx.r26.u64 = ctx.r24.u64;
	// b 0x8208fa64
	goto loc_8208FA64;
loc_8208FA60:
	// lhz r28,112(r1)
	ctx.r28.u64 = PPC_LOAD_U16(ctx.r1.u32 + 112);
loc_8208FA64:
	// lhz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r29.u32 + 8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lhz r10,10(r29)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r29.u32 + 10);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lhz r9,12(r29)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r29.u32 + 12);
	// lhz r8,14(r29)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r29.u32 + 14);
	// sth r28,96(r1)
	PPC_STORE_U16(ctx.r1.u32 + 96, ctx.r28.u16);
	// sth r25,98(r1)
	PPC_STORE_U16(ctx.r1.u32 + 98, ctx.r25.u16);
	// sth r24,100(r1)
	PPC_STORE_U16(ctx.r1.u32 + 100, ctx.r24.u16);
	// sth r11,102(r1)
	PPC_STORE_U16(ctx.r1.u32 + 102, ctx.r11.u16);
	// sth r10,104(r1)
	PPC_STORE_U16(ctx.r1.u32 + 104, ctx.r10.u16);
	// sth r9,106(r1)
	PPC_STORE_U16(ctx.r1.u32 + 106, ctx.r9.u16);
	// sth r23,110(r1)
	PPC_STORE_U16(ctx.r1.u32 + 110, ctx.r23.u16);
	// sth r8,108(r1)
	PPC_STORE_U16(ctx.r1.u32 + 108, ctx.r8.u16);
	// bl 0x821d57b4
	ctx.lr = 0x8208FAA0;
	__imp__RtlTimeFieldsToTime(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8208fbe0
	if (ctx.cr0.eq) goto loc_8208FBE0;
	// extsh r27,r31
	ctx.r27.s64 = ctx.r31.s16;
loc_8208FAAC:
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d55d4
	ctx.lr = 0x8208FAB8;
	__imp__RtlTimeToTimeFields(ctx, base);
	// lha r11,142(r1)
	ctx.r11.s64 = int16_t(PPC_LOAD_U16(ctx.r1.u32 + 142));
	// cmpw cr6,r11,r27
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r27.s32, ctx.xer);
	// ble cr6,0x8208fadc
	if (!ctx.cr6.gt) goto loc_8208FADC;
	// lha r10,100(r1)
	ctx.r10.s64 = int16_t(PPC_LOAD_U16(ctx.r1.u32 + 100));
	// subf r11,r11,r27
	ctx.r11.s64 = ctx.r27.s64 - ctx.r11.s64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r11,r11,7
	ctx.r11.s64 = ctx.r11.s64 + 7;
loc_8208FAD4:
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// b 0x8208faf4
	goto loc_8208FAF4;
loc_8208FADC:
	// bge cr6,0x8208faf0
	if (!ctx.cr6.lt) goto loc_8208FAF0;
	// lhz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 100);
	// subf r11,r11,r27
	ctx.r11.s64 = ctx.r27.s64 - ctx.r11.s64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x8208fad4
	goto loc_8208FAD4;
loc_8208FAF0:
	// lhz r11,100(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 100);
loc_8208FAF4:
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// mr r31,r24
	ctx.r31.u64 = ctx.r24.u64;
	// cmpwi cr6,r22,1
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 1, ctx.xer);
	// ble cr6,0x8208fb4c
	if (!ctx.cr6.gt) goto loc_8208FB4C;
	// b 0x8208fb0c
	goto loc_8208FB0C;
loc_8208FB08:
	// lhz r11,100(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 100);
loc_8208FB0C:
	// addi r11,r11,7
	ctx.r11.s64 = ctx.r11.s64 + 7;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// sth r11,100(r1)
	PPC_STORE_U16(ctx.r1.u32 + 100, ctx.r11.u16);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821d57b4
	ctx.lr = 0x8208FB20;
	__imp__RtlTimeFieldsToTime(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8208fb4c
	if (ctx.cr0.eq) goto loc_8208FB4C;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d55d4
	ctx.lr = 0x8208FB34;
	__imp__RtlTimeToTimeFields(ctx, base);
	// addi r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 1;
	// extsh r31,r11
	ctx.r31.s64 = ctx.r11.s16;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// cmpw cr6,r31,r22
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r22.s32, ctx.xer);
	// lhz r30,132(r1)
	ctx.r30.u64 = PPC_LOAD_U16(ctx.r1.u32 + 132);
	// blt cr6,0x8208fb08
	if (ctx.cr6.lt) goto loc_8208FB08;
loc_8208FB4C:
	// sth r30,100(r1)
	PPC_STORE_U16(ctx.r1.u32 + 100, ctx.r30.u16);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821d57b4
	ctx.lr = 0x8208FB5C;
	__imp__RtlTimeFieldsToTime(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8208fbe0
	if (ctx.cr0.eq) goto loc_8208FBE0;
	// ld r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// clrlwi. r11,r26,24
	ctx.r11.u64 = ctx.r26.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8208fbec
	if (ctx.cr0.eq) goto loc_8208FBEC;
	// lhz r11,118(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 118);
	// lha r10,100(r1)
	ctx.r10.s64 = int16_t(PPC_LOAD_U16(ctx.r1.u32 + 100));
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8208fb90
	if (ctx.cr6.lt) goto loc_8208FB90;
	// bne cr6,0x8208fbec
	if (!ctx.cr6.eq) goto loc_8208FBEC;
	// ld r11,0(r21)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r21.u32 + 0);
	// cmpd cr6,r9,r11
	ctx.cr6.compare<int64_t>(ctx.r9.s64, ctx.r11.s64, ctx.xer);
	// bge cr6,0x8208fbec
	if (!ctx.cr6.lt) goto loc_8208FBEC;
loc_8208FB90:
	// addi r11,r28,1
	ctx.r11.s64 = ctx.r28.s64 + 1;
	// lhz r10,10(r29)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r29.u32 + 10);
	// lhz r9,12(r29)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r29.u32 + 12);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// extsh r28,r11
	ctx.r28.s64 = ctx.r11.s16;
	// lhz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r29.u32 + 8);
	// lhz r8,14(r29)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r29.u32 + 14);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// sth r28,96(r1)
	PPC_STORE_U16(ctx.r1.u32 + 96, ctx.r28.u16);
	// mr r26,r23
	ctx.r26.u64 = ctx.r23.u64;
	// sth r10,104(r1)
	PPC_STORE_U16(ctx.r1.u32 + 104, ctx.r10.u16);
	// sth r25,98(r1)
	PPC_STORE_U16(ctx.r1.u32 + 98, ctx.r25.u16);
	// sth r11,102(r1)
	PPC_STORE_U16(ctx.r1.u32 + 102, ctx.r11.u16);
	// sth r9,106(r1)
	PPC_STORE_U16(ctx.r1.u32 + 106, ctx.r9.u16);
	// sth r24,100(r1)
	PPC_STORE_U16(ctx.r1.u32 + 100, ctx.r24.u16);
	// sth r8,108(r1)
	PPC_STORE_U16(ctx.r1.u32 + 108, ctx.r8.u16);
	// sth r23,110(r1)
	PPC_STORE_U16(ctx.r1.u32 + 110, ctx.r23.u16);
	// bl 0x821d57b4
	ctx.lr = 0x8208FBD8;
	__imp__RtlTimeFieldsToTime(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8208faac
	if (!ctx.cr0.eq) goto loc_8208FAAC;
loc_8208FBE0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8208FBE4:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x8207c9b8
	__restgprlr_20(ctx, base);
	return;
loc_8208FBEC:
	// std r9,0(r20)
	PPC_STORE_U64(ctx.r20.u32 + 0, ctx.r9.u64);
	// b 0x8208f9f8
	goto loc_8208F9F8;
}

__attribute__((alias("__imp__sub_8208FBF4"))) PPC_WEAK_FUNC(sub_8208FBF4);
PPC_FUNC_IMPL(__imp__sub_8208FBF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8208FBF8"))) PPC_WEAK_FUNC(sub_8208FBF8);
PPC_FUNC_IMPL(__imp__sub_8208FBF8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8208FC00;
	__savegprlr_29(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// sth r30,80(r1)
	PPC_STORE_U16(ctx.r1.u32 + 80, ctx.r30.u16);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r30.u32);
	// li r6,4
	ctx.r6.s64 = 4;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// stw r30,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r30.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x821d5614
	ctx.lr = 0x8208FC3C;
	__imp__ExGetXConfigSetting(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x8208fc4c
	if (!ctx.cr0.lt) goto loc_8208FC4C;
loc_8208FC44:
	// bl 0x821d5654
	ctx.lr = 0x8208FC48;
	__imp__RtlNtStatusToDosError(ctx, base);
	// b 0x8208fe10
	goto loc_8208FE10;
loc_8208FC4C:
	// lwz r11,92(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,108
	ctx.r5.s64 = ctx.r1.s64 + 108;
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,3
	ctx.r3.s64 = 3;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// bl 0x821d5614
	ctx.lr = 0x8208FC6C;
	__imp__ExGetXConfigSetting(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8208fc44
	if (ctx.cr0.lt) goto loc_8208FC44;
	// li r11,4
	ctx.r11.s64 = 4;
	// addi r10,r31,4
	ctx.r10.s64 = ctx.r31.s64 + 4;
	// addi r9,r1,107
	ctx.r9.s64 = ctx.r1.s64 + 107;
	// addi r8,r10,-2
	ctx.r8.s64 = ctx.r10.s64 + -2;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8208FC88:
	// lbzu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r11.u64 = PPC_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// sthu r11,2(r8)
	ea = 2 + ctx.r8.u32;
	PPC_STORE_U16(ea, ctx.r11.u16);
	ctx.r8.u32 = ea;
	// bdnz 0x8208fc88
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8208FC88;
	// sth r30,8(r10)
	PPC_STORE_U16(ctx.r10.u32 + 8, ctx.r30.u16);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// li r4,3
	ctx.r4.s64 = 3;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x821d5614
	ctx.lr = 0x8208FCB0;
	__imp__ExGetXConfigSetting(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8208fc44
	if (ctx.cr0.lt) goto loc_8208FC44;
	// li r11,4
	ctx.r11.s64 = 4;
	// addi r10,r31,88
	ctx.r10.s64 = ctx.r31.s64 + 88;
	// addi r9,r1,111
	ctx.r9.s64 = ctx.r1.s64 + 111;
	// addi r8,r10,-2
	ctx.r8.s64 = ctx.r10.s64 + -2;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8208FCCC:
	// lbzu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r11.u64 = PPC_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// sthu r11,2(r8)
	ea = 2 + ctx.r8.u32;
	PPC_STORE_U16(ea, ctx.r11.u16);
	ctx.r8.u32 = ea;
	// bdnz 0x8208fccc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8208FCCC;
	// sth r30,8(r10)
	PPC_STORE_U16(ctx.r10.u32 + 8, ctx.r30.u16);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x821d5614
	ctx.lr = 0x8208FCF4;
	__imp__ExGetXConfigSetting(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8208fc44
	if (ctx.cr0.lt) goto loc_8208FC44;
	// addi r3,r31,68
	ctx.r3.s64 = ctx.r31.s64 + 68;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8207da20
	ctx.lr = 0x8208FD0C;
	sub_8207DA20(ctx, base);
	// lbz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 84);
	// lbz r8,87(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lbz r10,85(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 85);
	// li r6,4
	ctx.r6.s64 = 4;
	// lbz r9,86(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 86);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// li r4,5
	ctx.r4.s64 = 5;
	// sth r11,70(r31)
	PPC_STORE_U16(ctx.r31.u32 + 70, ctx.r11.u16);
	// li r3,3
	ctx.r3.s64 = 3;
	// sth r8,76(r31)
	PPC_STORE_U16(ctx.r31.u32 + 76, ctx.r8.u16);
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// sth r10,74(r31)
	PPC_STORE_U16(ctx.r31.u32 + 74, ctx.r10.u16);
	// sth r9,72(r31)
	PPC_STORE_U16(ctx.r31.u32 + 72, ctx.r9.u16);
	// bl 0x821d5614
	ctx.lr = 0x8208FD48;
	__imp__ExGetXConfigSetting(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8208fc44
	if (ctx.cr0.lt) goto loc_8208FC44;
	// addi r3,r31,152
	ctx.r3.s64 = ctx.r31.s64 + 152;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8207da20
	ctx.lr = 0x8208FD60;
	sub_8207DA20(ctx, base);
	// lbz r11,88(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 88);
	// lbz r8,91(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 91);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lbz r10,89(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 89);
	// li r6,4
	ctx.r6.s64 = 4;
	// lbz r9,90(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 90);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,6
	ctx.r4.s64 = 6;
	// sth r11,154(r31)
	PPC_STORE_U16(ctx.r31.u32 + 154, ctx.r11.u16);
	// li r3,3
	ctx.r3.s64 = 3;
	// sth r8,160(r31)
	PPC_STORE_U16(ctx.r31.u32 + 160, ctx.r8.u16);
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// sth r10,158(r31)
	PPC_STORE_U16(ctx.r31.u32 + 158, ctx.r10.u16);
	// sth r9,156(r31)
	PPC_STORE_U16(ctx.r31.u32 + 156, ctx.r9.u16);
	// bl 0x821d5614
	ctx.lr = 0x8208FD9C;
	__imp__ExGetXConfigSetting(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8208fc44
	if (ctx.cr0.lt) goto loc_8208FC44;
	// lwz r11,96(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// li r4,7
	ctx.r4.s64 = 7;
	// li r3,3
	ctx.r3.s64 = 3;
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// bl 0x821d5614
	ctx.lr = 0x8208FDC4;
	__imp__ExGetXConfigSetting(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8208fc44
	if (ctx.cr0.lt) goto loc_8208FC44;
	// lwz r11,100(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// stw r11,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r11.u32);
	// beq cr6,0x8208fe0c
	if (ctx.cr6.eq) goto loc_8208FE0C;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// li r4,12
	ctx.r4.s64 = 12;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x821d5614
	ctx.lr = 0x8208FDF4;
	__imp__ExGetXConfigSetting(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8208fc44
	if (ctx.cr0.lt) goto loc_8208FC44;
	// lwz r11,104(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// not r11,r11
	ctx.r11.u64 = ~ctx.r11.u64;
	// rlwinm r11,r11,31,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x1;
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
loc_8208FE0C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8208FE10:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8208FE18"))) PPC_WEAK_FUNC(sub_8208FE18);
PPC_FUNC_IMPL(__imp__sub_8208FE18) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lwz r16,21428(r29)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r29.u32 + 21428);
	// lwz r16,7368(r5)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r5.u32 + 7368);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8208FE28;
	__savegprlr_29(ctx, base);
	// addi r31,r1,-128
	ctx.r31.s64 = ctx.r1.s64 + -128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8208da20
	ctx.lr = 0x8208FE50;
	sub_8208DA20(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mtctr r30
	ctx.ctr.u64 = ctx.r30.u64;
	// bctrl 
	ctx.lr = 0x8208FE5C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r3.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8208da20
	ctx.lr = 0x8208FE68;
	sub_8208DA20(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// bl 0x821d54b4
	ctx.lr = 0x8208FE7C;
	__imp__ExTerminateThread(ctx, base);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82088bb8
	ctx.lr = 0x8208FE8C;
	sub_82088BB8(ctx, base);
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

__attribute__((alias("__imp__sub_8208FE20"))) PPC_WEAK_FUNC(sub_8208FE20);
PPC_FUNC_IMPL(__imp__sub_8208FE20) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8208FE28;
	__savegprlr_29(ctx, base);
	// addi r31,r1,-128
	ctx.r31.s64 = ctx.r1.s64 + -128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8208da20
	ctx.lr = 0x8208FE50;
	sub_8208DA20(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mtctr r30
	ctx.ctr.u64 = ctx.r30.u64;
	// bctrl 
	ctx.lr = 0x8208FE5C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r3.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8208da20
	ctx.lr = 0x8208FE68;
	sub_8208DA20(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// bl 0x821d54b4
	ctx.lr = 0x8208FE7C;
	__imp__ExTerminateThread(ctx, base);
}

__attribute__((alias("__imp__sub_8208FE7C"))) PPC_WEAK_FUNC(sub_8208FE7C);
PPC_FUNC_IMPL(__imp__sub_8208FE7C) {
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
	// bl 0x82088bb8
	ctx.lr = 0x8208FE8C;
	sub_82088BB8(ctx, base);
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

__attribute__((alias("__imp__sub_8208FEA0"))) PPC_WEAK_FUNC(sub_8208FEA0);
PPC_FUNC_IMPL(__imp__sub_8208FEA0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8208FEA8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// beq cr6,0x8208ff10
	if (ctx.cr6.eq) goto loc_8208FF10;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x8208ff00
	if (ctx.cr6.gt) goto loc_8208FF00;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// srawi r10,r5,8
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xFF) != 0);
	ctx.r10.s64 = ctx.r5.s32 >> 8;
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stb r5,1(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1, ctx.r5.u8);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
loc_8208FF00:
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// b 0x8208ff68
	goto loc_8208FF68;
loc_8208FF10:
	// addi r11,r11,5
	ctx.r11.s64 = ctx.r11.s64 + 5;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x8208ff5c
	if (ctx.cr6.gt) goto loc_8208FF5C;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r9,255
	ctx.r9.s64 = 255;
	// srawi r10,r6,8
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xFF) != 0);
	ctx.r10.s64 = ctx.r6.s32 >> 8;
	// srawi r8,r29,8
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0xFF) != 0);
	ctx.r8.s64 = ctx.r29.s32 >> 8;
	// stb r9,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r9.u8);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stb r10,1(r9)
	PPC_STORE_U8(ctx.r9.u32 + 1, ctx.r10.u8);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stb r6,2(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2, ctx.r6.u8);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stb r8,3(r10)
	PPC_STORE_U8(ctx.r10.u32 + 3, ctx.r8.u8);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stb r29,4(r11)
	PPC_STORE_U8(ctx.r11.u32 + 4, ctx.r29.u8);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r11,r11,5
	ctx.r11.s64 = ctx.r11.s64 + 5;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_8208FF5C:
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r28,5
	ctx.r28.s64 = 5;
	// addi r11,r11,5
	ctx.r11.s64 = ctx.r11.s64 + 5;
loc_8208FF68:
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// subf r30,r10,r11
	ctx.r30.s64 = ctx.r11.s64 - ctx.r10.s64;
	// bge cr6,0x8208ff84
	if (!ctx.cr6.lt) goto loc_8208FF84;
	// li r30,0
	ctx.r30.s64 = 0;
loc_8208FF84:
	// cmplw cr6,r29,r30
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r30.u32, ctx.xer);
	// bge cr6,0x8208ff90
	if (!ctx.cr6.lt) goto loc_8208FF90;
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
loc_8208FF90:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207dac0
	ctx.lr = 0x8208FF9C;
	sub_8207DAC0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// add r3,r10,r30
	ctx.r3.u64 = ctx.r10.u64 + ctx.r30.u64;
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// beq cr6,0x82090000
	if (ctx.cr6.eq) goto loc_82090000;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// subf r30,r11,r10
	ctx.r30.s64 = ctx.r10.s64 - ctx.r11.s64;
	// bge cr6,0x8208ffd0
	if (!ctx.cr6.lt) goto loc_8208FFD0;
	// li r30,0
	ctx.r30.s64 = 0;
loc_8208FFD0:
	// cmplw cr6,r28,r30
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r30.u32, ctx.xer);
	// bge cr6,0x8208ffdc
	if (!ctx.cr6.lt) goto loc_8208FFDC;
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
loc_8208FFDC:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8207da20
	ctx.lr = 0x8208FFE8;
	sub_8207DA20(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + ctx.r30.u64;
	// add r11,r28,r11
	ctx.r11.u64 = ctx.r28.u64 + ctx.r11.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
loc_82090000:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8209000C"))) PPC_WEAK_FUNC(sub_8209000C);
PPC_FUNC_IMPL(__imp__sub_8209000C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82090010"))) PPC_WEAK_FUNC(sub_82090010);
PPC_FUNC_IMPL(__imp__sub_82090010) {
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
	// addi r31,r3,16
	ctx.r31.s64 = ctx.r3.s64 + 16;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820906e0
	ctx.lr = 0x82090034;
	sub_820906E0(ctx, base);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// clrlwi. r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82090050
	if (ctx.cr0.eq) goto loc_82090050;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,17232(r31)
	PPC_STORE_U32(ctx.r31.u32 + 17232, ctx.r11.u32);
	// stw r11,17248(r31)
	PPC_STORE_U32(ctx.r31.u32 + 17248, ctx.r11.u32);
	// b 0x8209007c
	goto loc_8209007C;
loc_82090050:
	// rlwinm. r11,r11,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82090080
	if (ctx.cr0.eq) goto loc_82090080;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,17224(r31)
	PPC_STORE_U32(ctx.r31.u32 + 17224, ctx.r11.u32);
	// std r11,17232(r31)
	PPC_STORE_U64(ctx.r31.u32 + 17232, ctx.r11.u64);
	// std r11,17240(r31)
	PPC_STORE_U64(ctx.r31.u32 + 17240, ctx.r11.u64);
	// stw r11,17256(r31)
	PPC_STORE_U32(ctx.r31.u32 + 17256, ctx.r11.u32);
	// stw r11,17260(r31)
	PPC_STORE_U32(ctx.r31.u32 + 17260, ctx.r11.u32);
	// stw r11,17264(r31)
	PPC_STORE_U32(ctx.r31.u32 + 17264, ctx.r11.u32);
	// stw r11,17268(r31)
	PPC_STORE_U32(ctx.r31.u32 + 17268, ctx.r11.u32);
	// stb r11,17272(r31)
	PPC_STORE_U8(ctx.r31.u32 + 17272, ctx.r11.u8);
loc_8209007C:
	// stw r11,17252(r31)
	PPC_STORE_U32(ctx.r31.u32 + 17252, ctx.r11.u32);
loc_82090080:
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

__attribute__((alias("__imp__sub_8209009C"))) PPC_WEAK_FUNC(sub_8209009C);
PPC_FUNC_IMPL(__imp__sub_8209009C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820900A0"))) PPC_WEAK_FUNC(sub_820900A0);
PPC_FUNC_IMPL(__imp__sub_820900A0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x820900A8;
	__savegprlr_25(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r31,0
	ctx.r31.s64 = 0;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// addi r29,r3,16
	ctx.r29.s64 = ctx.r3.s64 + 16;
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// mr r25,r31
	ctx.r25.u64 = ctx.r31.u64;
	// bne 0x820900d8
	if (!ctx.cr0.eq) goto loc_820900D8;
	// bl 0x82090010
	ctx.lr = 0x820900D8;
	sub_82090010(ctx, base);
loc_820900D8:
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stw r28,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r28.u32);
	// addi r10,r10,-352
	ctx.r10.s64 = ctx.r10.s64 + -352;
	// stw r31,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r31.u32);
	// stw r9,17200(r29)
	PPC_STORE_U32(ctx.r29.u32 + 17200, ctx.r9.u32);
	// mr r28,r31
	ctx.r28.u64 = ctx.r31.u64;
	// stw r10,17216(r29)
	PPC_STORE_U32(ctx.r29.u32 + 17216, ctx.r10.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r31.u32);
	// stw r31,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r31.u32);
	// beq cr6,0x8209015c
	if (ctx.cr6.eq) goto loc_8209015C;
loc_82090110:
	// cmplwi cr6,r30,32768
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 32768, ctx.xer);
	// bge cr6,0x82090120
	if (!ctx.cr6.lt) goto loc_82090120;
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
	// b 0x82090128
	goto loc_82090128;
loc_82090120:
	// lis r31,0
	ctx.r31.s64 = 0;
	// ori r31,r31,32768
	ctx.r31.u64 = ctx.r31.u64 | 32768;
loc_82090128:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// cmplwi cr6,r30,32768
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 32768, ctx.xer);
	// bgt cr6,0x82090138
	if (ctx.cr6.gt) goto loc_82090138;
	// stw r28,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r28.u32);
loc_82090138:
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820906e8
	ctx.lr = 0x82090150;
	sub_820906E8(ctx, base);
	// subf. r30,r31,r30
	ctx.r30.s64 = ctx.r30.s64 - ctx.r31.s64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// add r27,r31,r27
	ctx.r27.u64 = ctx.r31.u64 + ctx.r27.u64;
	// bne 0x82090110
	if (!ctx.cr0.eq) goto loc_82090110;
loc_8209015C:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82090758
	ctx.lr = 0x82090164;
	sub_82090758(ctx, base);
	// lwz r11,104(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// stw r11,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r11.u32);
	// ble cr6,0x8209017c
	if (!ctx.cr6.gt) goto loc_8209017C;
	// li r25,6
	ctx.r25.s64 = 6;
loc_8209017C:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82090188"))) PPC_WEAK_FUNC(sub_82090188);
PPC_FUNC_IMPL(__imp__sub_82090188) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x820901ac
	if (ctx.cr6.eq) goto loc_820901AC;
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// lwz r11,4(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// b 0x820901bc
	goto loc_820901BC;
loc_820901AC:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
loc_820901BC:
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820901d0
	if (!ctx.cr6.eq) goto loc_820901D0;
	// lis r11,2
	ctx.r11.s64 = 131072;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
loc_820901D0:
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lis r11,8
	ctx.r11.s64 = 524288;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820901E8"))) PPC_WEAK_FUNC(sub_820901E8);
PPC_FUNC_IMPL(__imp__sub_820901E8) {
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
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r6,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r6.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// bl 0x82090188
	ctx.lr = 0x82090214;
	sub_82090188(ctx, base);
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// li r7,16
	ctx.r7.s64 = 16;
	// lwz r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// addi r4,r1,172
	ctx.r4.s64 = ctx.r1.s64 + 172;
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82090938
	ctx.lr = 0x82090230;
	sub_82090938(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// clrlwi. r10,r30,31
	ctx.r10.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// beq 0x82090248
	if (ctx.cr0.eq) goto loc_82090248;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82090010
	ctx.lr = 0x82090248;
	sub_82090010(ctx, base);
loc_82090248:
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

__attribute__((alias("__imp__sub_82090260"))) PPC_WEAK_FUNC(sub_82090260);
PPC_FUNC_IMPL(__imp__sub_82090260) {
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
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82090188
	ctx.lr = 0x82090288;
	sub_82090188(ctx, base);
	// mr r8,r31
	ctx.r8.u64 = ctx.r31.u64;
	// li r7,16
	ctx.r7.s64 = 16;
	// lwz r6,96(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r5,92(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82090938
	ctx.lr = 0x820902A4;
	sub_82090938(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
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

__attribute__((alias("__imp__sub_820902BC"))) PPC_WEAK_FUNC(sub_820902BC);
PPC_FUNC_IMPL(__imp__sub_820902BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820902C0"))) PPC_WEAK_FUNC(sub_820902C0);
PPC_FUNC_IMPL(__imp__sub_820902C0) {
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
	// addi r31,r3,20
	ctx.r31.s64 = ctx.r3.s64 + 20;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82090b30
	ctx.lr = 0x820902E4;
	sub_82090B30(ctx, base);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// clrlwi. r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x820902fc
	if (ctx.cr0.eq) goto loc_820902FC;
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,12284(r31)
	PPC_STORE_U8(ctx.r31.u32 + 12284, ctx.r11.u8);
	// b 0x8209031c
	goto loc_8209031C;
loc_820902FC:
	// rlwinm. r11,r11,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82090328
	if (ctx.cr0.eq) goto loc_82090328;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,12276(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12276, ctx.r11.u32);
	// stw r11,12284(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12284, ctx.r11.u32);
	// stw r11,12288(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12288, ctx.r11.u32);
	// stw r11,12292(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12292, ctx.r11.u32);
	// stw r11,12296(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12296, ctx.r11.u32);
loc_8209031C:
	// stw r11,12280(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12280, ctx.r11.u32);
	// stw r11,12272(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12272, ctx.r11.u32);
	// stw r11,12268(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12268, ctx.r11.u32);
loc_82090328:
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

__attribute__((alias("__imp__sub_82090344"))) PPC_WEAK_FUNC(sub_82090344);
PPC_FUNC_IMPL(__imp__sub_82090344) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82090348"))) PPC_WEAK_FUNC(sub_82090348);
PPC_FUNC_IMPL(__imp__sub_82090348) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x82090350;
	__savegprlr_25(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// addi r26,r3,20
	ctx.r26.s64 = ctx.r3.s64 + 20;
	// li r27,0
	ctx.r27.s64 = 0;
	// cmplwi cr6,r7,5
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 5, ctx.xer);
	// addi r29,r7,-5
	ctx.r29.s64 = ctx.r7.s64 + -5;
	// bgt cr6,0x82090374
	if (ctx.cr6.gt) goto loc_82090374;
	// li r29,0
	ctx.r29.s64 = 0;
loc_82090374:
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r31,r6
	ctx.r31.u64 = ctx.r6.u64;
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82090388
	if (!ctx.cr0.eq) goto loc_82090388;
	// bl 0x820902c0
	ctx.lr = 0x82090388;
	sub_820902C0(ctx, base);
loc_82090388:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8209042c
	if (ctx.cr6.eq) goto loc_8209042C;
loc_82090390:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lbz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,255
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 255, ctx.xer);
	// bne cr6,0x820903dc
	if (!ctx.cr6.eq) goto loc_820903DC;
	// lbz r11,3(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 3);
	// addi r29,r29,-5
	ctx.r29.s64 = ctx.r29.s64 + -5;
	// lbz r10,1(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// lbz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 4);
	// rotlwi r11,r11,8
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// lbz r8,2(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 2);
	// rotlwi r10,r10,8
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// or r30,r11,r9
	ctx.r30.u64 = ctx.r11.u64 | ctx.r9.u64;
	// or r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 | ctx.r8.u64;
	// addi r31,r31,5
	ctx.r31.s64 = ctx.r31.s64 + 5;
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// bge cr6,0x820903f8
	if (!ctx.cr6.lt) goto loc_820903F8;
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
	// b 0x820903f8
	goto loc_820903F8;
loc_820903DC:
	// lbz r10,1(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// rlwinm r11,r11,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// lis r8,0
	ctx.r8.s64 = 0;
	// or r30,r10,r11
	ctx.r30.u64 = ctx.r10.u64 | ctx.r11.u64;
	// ori r8,r8,32768
	ctx.r8.u64 = ctx.r8.u64 | 32768;
	// addi r31,r31,2
	ctx.r31.s64 = ctx.r31.s64 + 2;
	// addi r29,r29,-2
	ctx.r29.s64 = ctx.r29.s64 + -2;
loc_820903F8:
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82090b78
	ctx.lr = 0x82090414;
	sub_82090B78(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// subf. r29,r30,r29
	ctx.r29.s64 = ctx.r29.s64 - ctx.r30.s64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// add r31,r30,r31
	ctx.r31.u64 = ctx.r30.u64 + ctx.r31.u64;
	// add r28,r11,r28
	ctx.r28.u64 = ctx.r11.u64 + ctx.r28.u64;
	// add r27,r11,r27
	ctx.r27.u64 = ctx.r11.u64 + ctx.r27.u64;
	// bne 0x82090390
	if (!ctx.cr0.eq) goto loc_82090390;
loc_8209042C:
	// stw r27,0(r25)
	PPC_STORE_U32(ctx.r25.u32 + 0, ctx.r27.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8209043C"))) PPC_WEAK_FUNC(sub_8209043C);
PPC_FUNC_IMPL(__imp__sub_8209043C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82090440"))) PPC_WEAK_FUNC(sub_82090440);
PPC_FUNC_IMPL(__imp__sub_82090440) {
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
	// stw r6,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r6.u32);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// bl 0x82090188
	ctx.lr = 0x8209046C;
	sub_82090188(ctx, base);
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// li r6,20
	ctx.r6.s64 = 20;
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r4,r1,172
	ctx.r4.s64 = ctx.r1.s64 + 172;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82090f30
	ctx.lr = 0x82090484;
	sub_82090F30(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// beq 0x8209049c
	if (ctx.cr0.eq) goto loc_8209049C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820902c0
	ctx.lr = 0x8209049C;
	sub_820902C0(ctx, base);
loc_8209049C:
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

__attribute__((alias("__imp__sub_820904B4"))) PPC_WEAK_FUNC(sub_820904B4);
PPC_FUNC_IMPL(__imp__sub_820904B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820904B8"))) PPC_WEAK_FUNC(sub_820904B8);
PPC_FUNC_IMPL(__imp__sub_820904B8) {
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
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82090188
	ctx.lr = 0x820904E0;
	sub_82090188(ctx, base);
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// li r6,20
	ctx.r6.s64 = 20;
	// lwz r5,92(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82090f30
	ctx.lr = 0x820904F8;
	sub_82090F30(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
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

__attribute__((alias("__imp__sub_82090510"))) PPC_WEAK_FUNC(sub_82090510);
PPC_FUNC_IMPL(__imp__sub_82090510) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
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
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r31,-32224
	ctx.r31.s64 = -2111832064;
	// lwz r11,1276(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1276);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm. r11,r11,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8209058c
	if (ctx.cr0.eq) goto loc_8209058C;
	// li r10,6
	ctx.r10.s64 = 6;
	// addi r11,r1,72
	ctx.r11.s64 = ctx.r1.s64 + 72;
	// li r9,0
	ctx.r9.s64 = 0;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82090548:
	// stdu r9,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r9.u64);
	ctx.r11.u32 = ea;
	// bdnz 0x82090548
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82090548;
	// lwz r3,-23080(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -23080);
	// li r11,48
	ctx.r11.s64 = 48;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82090590
	if (!ctx.cr6.eq) goto loc_82090590;
	// lis r3,12
	ctx.r3.s64 = 786432;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,4096
	ctx.r6.s64 = 4096;
	// lis r5,16
	ctx.r5.s64 = 1048576;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r3,r3,4098
	ctx.r3.u64 = ctx.r3.u64 | 4098;
	// bl 0x8208be88
	ctx.lr = 0x82090584;
	sub_8208BE88(ctx, base);
	// stw r3,-23080(r31)
	PPC_STORE_U32(ctx.r31.u32 + -23080, ctx.r3.u32);
	// b 0x82090590
	goto loc_82090590;
loc_8209058C:
	// lwz r3,-23080(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -23080);
loc_82090590:
	// addi r11,r3,0
	ctx.r11.s64 = ctx.r3.s64 + 0;
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r3,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
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

__attribute__((alias("__imp__sub_820905B0"))) PPC_WEAK_FUNC(sub_820905B0);
PPC_FUNC_IMPL(__imp__sub_820905B0) {
	PPC_FUNC_PROLOGUE();
	// twi 31,r0,20
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820905B8"))) PPC_WEAK_FUNC(sub_820905B8);
PPC_FUNC_IMPL(__imp__sub_820905B8) {
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
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lhz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// lhz r9,2(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 2);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lhz r8,6(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 6);
	// lhz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r11.u32 + 8);
	// lhz r6,10(r11)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r11.u32 + 10);
	// lhz r5,12(r11)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r11.u32 + 12);
	// lhz r11,14(r11)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r11.u32 + 14);
	// sth r10,96(r1)
	PPC_STORE_U16(ctx.r1.u32 + 96, ctx.r10.u16);
	// sth r9,98(r1)
	PPC_STORE_U16(ctx.r1.u32 + 98, ctx.r9.u16);
	// sth r8,100(r1)
	PPC_STORE_U16(ctx.r1.u32 + 100, ctx.r8.u16);
	// sth r7,102(r1)
	PPC_STORE_U16(ctx.r1.u32 + 102, ctx.r7.u16);
	// sth r6,104(r1)
	PPC_STORE_U16(ctx.r1.u32 + 104, ctx.r6.u16);
	// sth r5,106(r1)
	PPC_STORE_U16(ctx.r1.u32 + 106, ctx.r5.u16);
	// sth r11,108(r1)
	PPC_STORE_U16(ctx.r1.u32 + 108, ctx.r11.u16);
	// bl 0x821d57b4
	ctx.lr = 0x82090614;
	__imp__RtlTimeFieldsToTime(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82090630
	if (!ctx.cr0.eq) goto loc_82090630;
	// lis r3,-16384
	ctx.r3.s64 = -1073741824;
	// ori r3,r3,13
	ctx.r3.u64 = ctx.r3.u64 | 13;
	// bl 0x8208dc98
	ctx.lr = 0x82090628;
	sub_8208DC98(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82090644
	goto loc_82090644;
loc_82090630:
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
loc_82090644:
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

__attribute__((alias("__imp__sub_82090658"))) PPC_WEAK_FUNC(sub_82090658);
PPC_FUNC_IMPL(__imp__sub_82090658) {
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
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x821d55d4
	ctx.lr = 0x82090688;
	__imp__RtlTimeToTimeFields(ctx, base);
	// lhz r11,96(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 96);
	// lhz r10,98(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 98);
	// li r3,1
	ctx.r3.s64 = 1;
	// lhz r9,100(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 100);
	// lhz r8,110(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 110);
	// lhz r7,102(r1)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r1.u32 + 102);
	// lhz r6,104(r1)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r1.u32 + 104);
	// lhz r5,106(r1)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r1.u32 + 106);
	// lhz r4,108(r1)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r1.u32 + 108);
	// sth r11,0(r31)
	PPC_STORE_U16(ctx.r31.u32 + 0, ctx.r11.u16);
	// sth r10,2(r31)
	PPC_STORE_U16(ctx.r31.u32 + 2, ctx.r10.u16);
	// sth r9,6(r31)
	PPC_STORE_U16(ctx.r31.u32 + 6, ctx.r9.u16);
	// sth r8,4(r31)
	PPC_STORE_U16(ctx.r31.u32 + 4, ctx.r8.u16);
	// sth r7,8(r31)
	PPC_STORE_U16(ctx.r31.u32 + 8, ctx.r7.u16);
	// sth r6,10(r31)
	PPC_STORE_U16(ctx.r31.u32 + 10, ctx.r6.u16);
	// sth r5,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r5.u16);
	// sth r4,14(r31)
	PPC_STORE_U16(ctx.r31.u32 + 14, ctx.r4.u16);
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

__attribute__((alias("__imp__sub_820906E0"))) PPC_WEAK_FUNC(sub_820906E0);
PPC_FUNC_IMPL(__imp__sub_820906E0) {
	PPC_FUNC_PROLOGUE();
	// b 0x82090790
	sub_82090790(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820906E4"))) PPC_WEAK_FUNC(sub_820906E4);
PPC_FUNC_IMPL(__imp__sub_820906E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820906E8"))) PPC_WEAK_FUNC(sub_820906E8);
PPC_FUNC_IMPL(__imp__sub_820906E8) {
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
	// stw r4,2436(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2436, ctx.r4.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r5,2440(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2440, ctx.r5.u32);
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// stw r7,2156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2156, ctx.r7.u32);
	// bl 0x82091f00
	ctx.lr = 0x82090714;
	sub_82091F00(ctx, base);
	// lbz r11,25(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 25);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82090730
	if (ctx.cr0.eq) goto loc_82090730;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,2
	ctx.r3.s64 = 2;
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// b 0x82090740
	goto loc_82090740;
loc_82090730:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820912c8
	ctx.lr = 0x82090738;
	sub_820912C8(ctx, base);
	// stw r3,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r3.u32);
	// li r3,0
	ctx.r3.s64 = 0;
loc_82090740:
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

__attribute__((alias("__imp__sub_82090758"))) PPC_WEAK_FUNC(sub_82090758);
PPC_FUNC_IMPL(__imp__sub_82090758) {
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
	// bl 0x82091318
	ctx.lr = 0x82090770;
	sub_82091318(ctx, base);
	// lbz r11,25(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 25);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
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

__attribute__((alias("__imp__sub_82090790"))) PPC_WEAK_FUNC(sub_82090790);
PPC_FUNC_IMPL(__imp__sub_82090790) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82090798;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r5,4
	ctx.r5.s64 = 262144;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// bl 0x8207da20
	ctx.lr = 0x820907B0;
	sub_8207DA20(ctx, base);
	// lwz r11,2152(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2152);
	// li r10,32
	ctx.r10.s64 = 32;
	// lwz r9,17188(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 17188);
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// lwz r7,17192(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 17192);
	// stb r10,24(r31)
	PPC_STORE_U8(ctx.r31.u32 + 24, ctx.r10.u8);
	// li r30,1
	ctx.r30.s64 = 1;
	// rlwinm r5,r11,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// li r29,0
	ctx.r29.s64 = 0;
	// stw r30,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r30.u32);
	// addi r3,r31,14672
	ctx.r3.s64 = ctx.r31.s64 + 14672;
	// stw r30,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r30.u32);
	// stw r30,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r30.u32);
	// stw r30,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
	// stw r30,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r30.u32);
	// stb r30,2418(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2418, ctx.r30.u8);
	// stb r30,2419(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2419, ctx.r30.u8);
	// stw r29,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r29.u32);
	// stb r29,25(r31)
	PPC_STORE_U8(ctx.r31.u32 + 25, ctx.r29.u8);
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r10,17184(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 17184);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r11.s64;
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// subf r8,r8,r7
	ctx.r8.s64 = ctx.r7.s64 - ctx.r8.s64;
	// stw r11,1104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1104, ctx.r11.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r9,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r9.u32);
	// stw r8,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r8.u32);
	// stw r11,2148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2148, ctx.r11.u32);
	// bl 0x8207da20
	ctx.lr = 0x82090834;
	sub_8207DA20(ctx, base);
	// addi r3,r31,16868
	ctx.r3.s64 = ctx.r31.s64 + 16868;
	// li r5,249
	ctx.r5.s64 = 249;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8207da20
	ctx.lr = 0x82090844;
	sub_8207DA20(ctx, base);
	// addi r3,r31,9520
	ctx.r3.s64 = ctx.r31.s64 + 9520;
	// li r5,256
	ctx.r5.s64 = 256;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x8207da20
	ctx.lr = 0x82090854;
	sub_8207DA20(ctx, base);
	// lwz r11,2152(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2152);
	// addi r3,r31,9776
	ctx.r3.s64 = ctx.r31.s64 + 9776;
	// li r4,9
	ctx.r4.s64 = 9;
	// rlwinm r5,r11,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x8207da20
	ctx.lr = 0x82090868;
	sub_8207DA20(ctx, base);
	// addi r3,r31,10221
	ctx.r3.s64 = ctx.r31.s64 + 10221;
	// li r5,249
	ctx.r5.s64 = 249;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x8207da20
	ctx.lr = 0x82090878;
	sub_8207DA20(ctx, base);
	// li r11,771
	ctx.r11.s64 = 771;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// sth r11,17166(r31)
	PPC_STORE_U16(ctx.r31.u32 + 17166, ctx.r11.u16);
	// sth r11,17168(r31)
	PPC_STORE_U16(ctx.r31.u32 + 17168, ctx.r11.u16);
	// sth r11,17170(r31)
	PPC_STORE_U16(ctx.r31.u32 + 17170, ctx.r11.u16);
	// sth r11,17172(r31)
	PPC_STORE_U16(ctx.r31.u32 + 17172, ctx.r11.u16);
	// bl 0x82092b08
	ctx.lr = 0x82090894;
	sub_82092B08(ctx, base);
	// lwz r11,1104(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1104);
	// li r5,8192
	ctx.r5.s64 = 8192;
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r29,2144(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2144, ctx.r29.u32);
	// stb r30,2420(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2420, ctx.r30.u8);
	// stw r11,2432(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2432, ctx.r11.u32);
	// stw r11,2428(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2428, ctx.r11.u32);
	// bl 0x8207da20
	ctx.lr = 0x820908B8;
	sub_8207DA20(ctx, base);
	// stw r29,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r29.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r29,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r29.u32);
	// stb r29,2161(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2161, ctx.r29.u8);
	// stw r30,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r30.u32);
	// stw r30,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
	// stw r30,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r30.u32);
	// bl 0x82091ff8
	ctx.lr = 0x820908D8;
	sub_82091FF8(ctx, base);
	// li r5,2800
	ctx.r5.s64 = 2800;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r29,17196(r31)
	PPC_STORE_U32(ctx.r31.u32 + 17196, ctx.r29.u32);
	// addi r3,r31,10472
	ctx.r3.s64 = ctx.r31.s64 + 10472;
	// stw r29,17212(r31)
	PPC_STORE_U32(ctx.r31.u32 + 17212, ctx.r29.u32);
	// bl 0x8207da20
	ctx.lr = 0x820908F0;
	sub_8207DA20(ctx, base);
	// li r5,996
	ctx.r5.s64 = 996;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,15374
	ctx.r3.s64 = ctx.r31.s64 + 15374;
	// bl 0x8207da20
	ctx.lr = 0x82090900;
	sub_8207DA20(ctx, base);
	// li r5,32
	ctx.r5.s64 = 32;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,17118
	ctx.r3.s64 = ctx.r31.s64 + 17118;
	// bl 0x8207da20
	ctx.lr = 0x82090910;
	sub_8207DA20(ctx, base);
	// lwz r10,2424(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2424);
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17184(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 17184);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r5,r11,4353
	ctx.r5.s64 = ctx.r11.s64 + 4353;
	// bl 0x8207da20
	ctx.lr = 0x8209092C;
	sub_8207DA20(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82090934"))) PPC_WEAK_FUNC(sub_82090934);
PPC_FUNC_IMPL(__imp__sub_82090934) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82090938"))) PPC_WEAK_FUNC(sub_82090938);
PPC_FUNC_IMPL(__imp__sub_82090938) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c970
	ctx.lr = 0x82090940;
	__savegprlr_22(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// rlwinm r11,r8,1,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0x1;
	// add r9,r5,r6
	ctx.r9.u64 = ctx.r5.u64 + ctx.r6.u64;
	// subfic r10,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r10.s64 = 0 - ctx.r11.s64;
	// clrlwi r10,r8,31
	ctx.r10.u64 = ctx.r8.u32 & 0x1;
	// subfe r31,r31,r31
	temp.u8 = (~ctx.r31.u32 + ctx.r31.u32 < ~ctx.r31.u32) | (~ctx.r31.u32 + ctx.r31.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r31.u64 = ~ctx.r31.u64 + ctx.r31.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// subfic r8,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r8.s64 = 0 - ctx.r11.s64;
	// addi r9,r9,4353
	ctx.r9.s64 = ctx.r9.s64 + 4353;
	// subfe r30,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r30.u64 = ~ctx.r8.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// subfic r8,r10,0
	ctx.xer.ca = ctx.r10.u32 <= 0;
	ctx.r8.s64 = 0 - ctx.r10.s64;
	// addi r29,r9,3
	ctx.r29.s64 = ctx.r9.s64 + 3;
	// subfe r28,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r28.u64 = ~ctx.r8.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// subfic r8,r10,0
	ctx.xer.ca = ctx.r10.u32 <= 0;
	ctx.r8.s64 = 0 - ctx.r10.s64;
	// rlwinm r29,r29,0,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0xFFFFFFFC;
	// lis r26,2
	ctx.r26.s64 = 131072;
	// subfe r24,r27,r27
	temp.u8 = (~ctx.r27.u32 + ctx.r27.u32 < ~ctx.r27.u32) | (~ctx.r27.u32 + ctx.r27.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r24.u64 = ~ctx.r27.u64 + ctx.r27.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// add r8,r29,r9
	ctx.r8.u64 = ctx.r29.u64 + ctx.r9.u64;
	// lis r25,0
	ctx.r25.s64 = 0;
	// lis r27,9
	ctx.r27.s64 = 589824;
	// ori r26,r26,24616
	ctx.r26.u64 = ctx.r26.u64 | 24616;
	// add r23,r8,r9
	ctx.r23.u64 = ctx.r8.u64 + ctx.r9.u64;
	// ori r25,r25,32768
	ctx.r25.u64 = ctx.r25.u64 | 32768;
	// ori r22,r27,55452
	ctx.r22.u64 = ctx.r27.u64 | 55452;
	// and r27,r28,r26
	ctx.r27.u64 = ctx.r28.u64 & ctx.r26.u64;
	// and r8,r24,r25
	ctx.r8.u64 = ctx.r24.u64 & ctx.r25.u64;
	// addis r28,r23,9
	ctx.r28.s64 = ctx.r23.s64 + 589824;
	// add r8,r8,r27
	ctx.r8.u64 = ctx.r8.u64 + ctx.r27.u64;
	// addi r28,r28,32048
	ctx.r28.s64 = ctx.r28.s64 + 32048;
	// and r26,r30,r22
	ctx.r26.u64 = ctx.r30.u64 & ctx.r22.u64;
	// and r31,r31,r28
	ctx.r31.u64 = ctx.r31.u64 & ctx.r28.u64;
	// add r8,r8,r26
	ctx.r8.u64 = ctx.r8.u64 + ctx.r26.u64;
	// mr r23,r11
	ctx.r23.u64 = ctx.r11.u64;
	// add r8,r8,r31
	ctx.r8.u64 = ctx.r8.u64 + ctx.r31.u64;
	// mr r25,r10
	ctx.r25.u64 = ctx.r10.u64;
	// add r8,r8,r28
	ctx.r8.u64 = ctx.r8.u64 + ctx.r28.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// add r11,r8,r7
	ctx.r11.u64 = ctx.r8.u64 + ctx.r7.u64;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// beq cr6,0x82090b24
	if (ctx.cr6.eq) goto loc_82090B24;
	// add r31,r3,r7
	ctx.r31.u64 = ctx.r3.u64 + ctx.r7.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r11,4
	ctx.r11.s64 = 4;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stwx r30,r3,r7
	PPC_STORE_U32(ctx.r3.u32 + ctx.r7.u32, ctx.r30.u32);
	// addi r10,r31,17376
	ctx.r10.s64 = ctx.r31.s64 + 17376;
	// stw r11,2152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2152, ctx.r11.u32);
	// li r24,1
	ctx.r24.s64 = 1;
	// stw r5,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r5.u32);
	// addi r7,r8,12292
	ctx.r7.s64 = ctx.r8.s64 + 12292;
	// stw r6,2424(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2424, ctx.r6.u32);
	// stw r30,17216(r31)
	PPC_STORE_U32(ctx.r31.u32 + 17216, ctx.r30.u32);
	// stw r30,17204(r31)
	PPC_STORE_U32(ctx.r31.u32 + 17204, ctx.r30.u32);
	// stw r30,17208(r31)
	PPC_STORE_U32(ctx.r31.u32 + 17208, ctx.r30.u32);
	// stw r30,17200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 17200, ctx.r30.u32);
	// stw r30,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
	// stw r30,17188(r31)
	PPC_STORE_U32(ctx.r31.u32 + 17188, ctx.r30.u32);
	// stw r30,17192(r31)
	PPC_STORE_U32(ctx.r31.u32 + 17192, ctx.r30.u32);
	// stw r30,9516(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9516, ctx.r30.u32);
	// stw r30,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r30.u32);
	// stw r30,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r30.u32);
	// stw r30,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r30.u32);
	// stw r30,2132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2132, ctx.r30.u32);
	// stw r30,17248(r31)
	PPC_STORE_U32(ctx.r31.u32 + 17248, ctx.r30.u32);
	// stw r30,17372(r31)
	PPC_STORE_U32(ctx.r31.u32 + 17372, ctx.r30.u32);
loc_82090A44:
	// lwz r8,2152(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2152);
	// addi r6,r8,1
	ctx.r6.s64 = ctx.r8.s64 + 1;
	// lbzx r8,r8,r7
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r7.u32);
	// stw r6,2152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2152, ctx.r6.u32);
	// slw r8,r24,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r24.u32 << (ctx.r8.u8 & 0x3F));
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// cmplw cr6,r11,r5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r5.u32, ctx.xer);
	// blt cr6,0x82090a44
	if (ctx.cr6.lt) goto loc_82090A44;
	// add r11,r10,r9
	ctx.r11.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r10,17188(r31)
	PPC_STORE_U32(ctx.r31.u32 + 17188, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,17192(r31)
	PPC_STORE_U32(ctx.r31.u32 + 17192, ctx.r11.u32);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stw r11,17184(r31)
	PPC_STORE_U32(ctx.r31.u32 + 17184, ctx.r11.u32);
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// lwz r10,17184(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 17184);
	// addis r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 65536;
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// addis r11,r9,2
	ctx.r11.s64 = ctx.r9.s64 + 131072;
	// stw r9,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r9.u32);
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// addi r29,r11,8192
	ctx.r29.s64 = ctx.r11.s64 + 8192;
	// bl 0x82092cc8
	ctx.lr = 0x82090AA4;
	sub_82092CC8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82092d70
	ctx.lr = 0x82090AAC;
	sub_82092D70(ctx, base);
	// addis r11,r29,1
	ctx.r11.s64 = ctx.r29.s64 + 65536;
	// stw r29,2132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2132, ctx.r29.u32);
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// addi r11,r11,-26624
	ctx.r11.s64 = ctx.r11.s64 + -26624;
	// addis r10,r11,2
	ctx.r10.s64 = ctx.r11.s64 + 131072;
	// stw r11,9516(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9516, ctx.r11.u32);
	// addi r10,r10,-32432
	ctx.r10.s64 = ctx.r10.s64 + -32432;
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// addis r11,r10,4
	ctx.r11.s64 = ctx.r10.s64 + 262144;
	// rotlwi r10,r29,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r29.u32, 0);
	// addis r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 65536;
	// stw r10,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r10.u32);
	// addi r9,r9,-26688
	ctx.r9.s64 = ctx.r9.s64 + -26688;
	// stw r9,2140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2140, ctx.r9.u32);
	// beq cr6,0x82090b08
	if (ctx.cr6.eq) goto loc_82090B08;
	// add r10,r11,r27
	ctx.r10.u64 = ctx.r11.u64 + ctx.r27.u64;
	// stw r27,17228(r31)
	PPC_STORE_U32(ctx.r31.u32 + 17228, ctx.r27.u32);
	// stw r11,17224(r31)
	PPC_STORE_U32(ctx.r31.u32 + 17224, ctx.r11.u32);
	// stw r30,17236(r31)
	PPC_STORE_U32(ctx.r31.u32 + 17236, ctx.r30.u32);
	// stw r30,17244(r31)
	PPC_STORE_U32(ctx.r31.u32 + 17244, ctx.r30.u32);
	// stw r10,17240(r31)
	PPC_STORE_U32(ctx.r31.u32 + 17240, ctx.r10.u32);
	// stb r24,17256(r31)
	PPC_STORE_U8(ctx.r31.u32 + 17256, ctx.r24.u8);
	// b 0x82090b1c
	goto loc_82090B1C;
loc_82090B08:
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x82090b1c
	if (ctx.cr6.eq) goto loc_82090B1C;
	// add r10,r11,r26
	ctx.r10.u64 = ctx.r11.u64 + ctx.r26.u64;
	// stw r11,17248(r31)
	PPC_STORE_U32(ctx.r31.u32 + 17248, ctx.r11.u32);
	// stw r10,17372(r31)
	PPC_STORE_U32(ctx.r31.u32 + 17372, ctx.r10.u32);
loc_82090B1C:
	// stw r28,17368(r31)
	PPC_STORE_U32(ctx.r31.u32 + 17368, ctx.r28.u32);
	// stb r24,2160(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2160, ctx.r24.u8);
loc_82090B24:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9c0
	__restgprlr_22(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82090B2C"))) PPC_WEAK_FUNC(sub_82090B2C);
PPC_FUNC_IMPL(__imp__sub_82090B2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82090B30"))) PPC_WEAK_FUNC(sub_82090B30);
PPC_FUNC_IMPL(__imp__sub_82090B30) {
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
	// bl 0x82090e80
	ctx.lr = 0x82090B48;
	sub_82090E80(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82090ef8
	ctx.lr = 0x82090B50;
	sub_82090EF8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82092db8
	ctx.lr = 0x82090B58;
	sub_82092DB8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,11972(r31)
	PPC_STORE_U32(ctx.r31.u32 + 11972, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_82090B74"))) PPC_WEAK_FUNC(sub_82090B74);
PPC_FUNC_IMPL(__imp__sub_82090B74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82090B78"))) PPC_WEAK_FUNC(sub_82090B78);
PPC_FUNC_IMPL(__imp__sub_82090B78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82090B80;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r7,11020(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11020, ctx.r7.u32);
	// add r11,r5,r6
	ctx.r11.u64 = ctx.r5.u64 + ctx.r6.u64;
	// stw r5,11012(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11012, ctx.r5.u32);
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// stw r11,11016(r31)
	PPC_STORE_U32(ctx.r31.u32 + 11016, ctx.r11.u32);
	// mr r30,r9
	ctx.r30.u64 = ctx.r9.u64;
	// bl 0x821d5494
	ctx.lr = 0x82090BAC;
	__imp__MmQueryAddressProtect(ctx, base);
	// rlwinm r11,r3,0,21,22
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x600;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r11,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stb r11,12260(r31)
	PPC_STORE_U8(ctx.r31.u32 + 12260, ctx.r11.u8);
	// bl 0x82093230
	ctx.lr = 0x82090BC4;
	sub_82093230(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82092f60
	ctx.lr = 0x82090BD0;
	sub_82092F60(ctx, base);
	// lwz r10,11972(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 11972);
	// mr. r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,11972(r31)
	PPC_STORE_U32(ctx.r31.u32 + 11972, ctx.r10.u32);
	// bge 0x82090bf4
	if (!ctx.cr0.lt) goto loc_82090BF4;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// b 0x82090c08
	goto loc_82090C08;
loc_82090BF4:
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r10,11024(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 11024);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r11,11024(r31)
	PPC_STORE_U32(ctx.r31.u32 + 11024, ctx.r11.u32);
loc_82090C08:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82090C10"))) PPC_WEAK_FUNC(sub_82090C10);
PPC_FUNC_IMPL(__imp__sub_82090C10) {
	PPC_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c95c
	ctx.lr = 0x82090C18;
	__savegprlr_17(ctx, base);
	// lis r9,257
	ctx.r9.s64 = 16842752;
	// lis r8,771
	ctx.r8.s64 = 50528256;
	// ori r9,r9,514
	ctx.r9.u64 = ctx.r9.u64 | 514;
	// lis r6,1799
	ctx.r6.s64 = 117899264;
	// lis r7,1285
	ctx.r7.s64 = 84213760;
	// stw r9,12008(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12008, ctx.r9.u32);
	// ori r8,r8,1028
	ctx.r8.u64 = ctx.r8.u64 | 1028;
	// ori r7,r7,1542
	ctx.r7.u64 = ctx.r7.u64 | 1542;
	// ori r9,r6,2056
	ctx.r9.u64 = ctx.r6.u64 | 2056;
	// stw r8,12012(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12012, ctx.r8.u32);
	// lis r5,2313
	ctx.r5.s64 = 151584768;
	// stw r7,12016(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12016, ctx.r7.u32);
	// lis r4,2827
	ctx.r4.s64 = 185270272;
	// stw r9,12020(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12020, ctx.r9.u32);
	// lis r31,3341
	ctx.r31.s64 = 218955776;
	// ori r8,r5,2570
	ctx.r8.u64 = ctx.r5.u64 | 2570;
	// ori r7,r4,3084
	ctx.r7.u64 = ctx.r4.u64 | 3084;
	// ori r9,r31,3598
	ctx.r9.u64 = ctx.r31.u64 | 3598;
	// stw r8,12024(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12024, ctx.r8.u32);
	// lis r11,4369
	ctx.r11.s64 = 286326784;
	// stw r7,12028(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12028, ctx.r7.u32);
	// lis r30,3855
	ctx.r30.s64 = 252641280;
	// stw r9,12032(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12032, ctx.r9.u32);
	// ori r11,r11,4369
	ctx.r11.u64 = ctx.r11.u64 | 4369;
	// li r10,0
	ctx.r10.s64 = 0;
	// ori r8,r30,4112
	ctx.r8.u64 = ctx.r30.u64 | 4112;
	// stw r11,12040(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12040, ctx.r11.u32);
	// li r7,-2
	ctx.r7.s64 = -2;
	// stw r10,12004(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12004, ctx.r10.u32);
	// li r9,-1
	ctx.r9.s64 = -1;
	// stw r8,12036(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12036, ctx.r8.u32);
	// stw r11,12044(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12044, ctx.r11.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r11,12048(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12048, ctx.r11.u32);
	// li r6,2
	ctx.r6.s64 = 2;
	// stw r11,12052(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12052, ctx.r11.u32);
	// li r5,4
	ctx.r5.s64 = 4;
	// stw r7,12056(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12056, ctx.r7.u32);
	// li r11,6
	ctx.r11.s64 = 6;
	// stw r9,12060(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12060, ctx.r9.u32);
	// li r7,10
	ctx.r7.s64 = 10;
	// stw r10,12064(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12064, ctx.r10.u32);
	// li r9,14
	ctx.r9.s64 = 14;
	// li r10,22
	ctx.r10.s64 = 22;
	// stw r8,12068(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12068, ctx.r8.u32);
	// stw r6,12072(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12072, ctx.r6.u32);
	// li r8,30
	ctx.r8.s64 = 30;
	// li r6,46
	ctx.r6.s64 = 46;
	// stw r5,12076(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12076, ctx.r5.u32);
	// stw r11,12080(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12080, ctx.r11.u32);
	// li r5,62
	ctx.r5.s64 = 62;
	// stw r7,12084(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12084, ctx.r7.u32);
	// li r11,94
	ctx.r11.s64 = 94;
	// stw r9,12088(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12088, ctx.r9.u32);
	// li r7,126
	ctx.r7.s64 = 126;
	// stw r10,12092(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12092, ctx.r10.u32);
	// li r9,190
	ctx.r9.s64 = 190;
	// li r10,254
	ctx.r10.s64 = 254;
	// stw r8,12096(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12096, ctx.r8.u32);
	// stw r6,12100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12100, ctx.r6.u32);
	// li r8,382
	ctx.r8.s64 = 382;
	// li r6,510
	ctx.r6.s64 = 510;
	// stw r5,12104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12104, ctx.r5.u32);
	// stw r11,12108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12108, ctx.r11.u32);
	// li r5,766
	ctx.r5.s64 = 766;
	// stw r7,12112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12112, ctx.r7.u32);
	// li r11,1022
	ctx.r11.s64 = 1022;
	// stw r9,12116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12116, ctx.r9.u32);
	// li r7,1534
	ctx.r7.s64 = 1534;
	// stw r10,12120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12120, ctx.r10.u32);
	// li r9,2046
	ctx.r9.s64 = 2046;
	// li r10,3070
	ctx.r10.s64 = 3070;
	// stw r8,12124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12124, ctx.r8.u32);
	// stw r6,12128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12128, ctx.r6.u32);
	// li r8,4094
	ctx.r8.s64 = 4094;
	// stw r5,12132(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12132, ctx.r5.u32);
	// li r6,6142
	ctx.r6.s64 = 6142;
	// stw r11,12136(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12136, ctx.r11.u32);
	// stw r7,12140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12140, ctx.r7.u32);
	// stw r9,12144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12144, ctx.r9.u32);
	// stw r10,12148(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12148, ctx.r10.u32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// stw r8,12152(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12152, ctx.r8.u32);
	// lis r10,0
	ctx.r10.s64 = 0;
	// stw r6,12156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12156, ctx.r6.u32);
	// ori r11,r11,49150
	ctx.r11.u64 = ctx.r11.u64 | 49150;
	// ori r10,r10,65534
	ctx.r10.u64 = ctx.r10.u64 | 65534;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// stw r11,12180(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12180, ctx.r11.u32);
	// lis r8,1
	ctx.r8.s64 = 65536;
	// stw r10,12184(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12184, ctx.r10.u32);
	// lis r7,2
	ctx.r7.s64 = 131072;
	// ori r9,r9,32766
	ctx.r9.u64 = ctx.r9.u64 | 32766;
	// ori r11,r8,65534
	ctx.r11.u64 = ctx.r8.u64 | 65534;
	// ori r10,r7,65534
	ctx.r10.u64 = ctx.r7.u64 | 65534;
	// stw r9,12188(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12188, ctx.r9.u32);
	// lis r6,3
	ctx.r6.s64 = 196608;
	// stw r11,12192(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12192, ctx.r11.u32);
	// lis r5,5
	ctx.r5.s64 = 327680;
	// stw r10,12196(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12196, ctx.r10.u32);
	// lis r4,7
	ctx.r4.s64 = 458752;
	// ori r9,r6,65534
	ctx.r9.u64 = ctx.r6.u64 | 65534;
	// ori r11,r5,65534
	ctx.r11.u64 = ctx.r5.u64 | 65534;
	// ori r10,r4,65534
	ctx.r10.u64 = ctx.r4.u64 | 65534;
	// stw r9,12200(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12200, ctx.r9.u32);
	// lis r31,9
	ctx.r31.s64 = 589824;
	// stw r11,12204(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12204, ctx.r11.u32);
	// lis r30,11
	ctx.r30.s64 = 720896;
	// stw r10,12208(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12208, ctx.r10.u32);
	// lis r29,13
	ctx.r29.s64 = 851968;
	// ori r9,r31,65534
	ctx.r9.u64 = ctx.r31.u64 | 65534;
	// ori r11,r30,65534
	ctx.r11.u64 = ctx.r30.u64 | 65534;
	// ori r10,r29,65534
	ctx.r10.u64 = ctx.r29.u64 | 65534;
	// stw r9,12212(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12212, ctx.r9.u32);
	// lis r28,15
	ctx.r28.s64 = 983040;
	// stw r11,12216(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12216, ctx.r11.u32);
	// lis r27,17
	ctx.r27.s64 = 1114112;
	// stw r10,12220(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12220, ctx.r10.u32);
	// lis r26,19
	ctx.r26.s64 = 1245184;
	// ori r9,r28,65534
	ctx.r9.u64 = ctx.r28.u64 | 65534;
	// ori r11,r27,65534
	ctx.r11.u64 = ctx.r27.u64 | 65534;
	// ori r10,r26,65534
	ctx.r10.u64 = ctx.r26.u64 | 65534;
	// stw r9,12224(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12224, ctx.r9.u32);
	// lis r25,21
	ctx.r25.s64 = 1376256;
	// stw r11,12228(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12228, ctx.r11.u32);
	// lis r24,23
	ctx.r24.s64 = 1507328;
	// stw r10,12232(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12232, ctx.r10.u32);
	// lis r23,25
	ctx.r23.s64 = 1638400;
	// li r19,8190
	ctx.r19.s64 = 8190;
	// li r18,12286
	ctx.r18.s64 = 12286;
	// ori r9,r25,65534
	ctx.r9.u64 = ctx.r25.u64 | 65534;
	// stw r19,12160(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12160, ctx.r19.u32);
	// ori r11,r24,65534
	ctx.r11.u64 = ctx.r24.u64 | 65534;
	// stw r18,12164(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12164, ctx.r18.u32);
	// ori r10,r23,65534
	ctx.r10.u64 = ctx.r23.u64 | 65534;
	// stw r9,12236(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12236, ctx.r9.u32);
	// lis r22,27
	ctx.r22.s64 = 1769472;
	// stw r11,12240(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12240, ctx.r11.u32);
	// lis r21,29
	ctx.r21.s64 = 1900544;
	// stw r10,12244(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12244, ctx.r10.u32);
	// lis r20,31
	ctx.r20.s64 = 2031616;
	// li r17,16382
	ctx.r17.s64 = 16382;
	// li r19,24574
	ctx.r19.s64 = 24574;
	// li r18,32766
	ctx.r18.s64 = 32766;
	// stw r17,12168(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12168, ctx.r17.u32);
	// ori r9,r22,65534
	ctx.r9.u64 = ctx.r22.u64 | 65534;
	// stw r19,12172(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12172, ctx.r19.u32);
	// ori r11,r21,65534
	ctx.r11.u64 = ctx.r21.u64 | 65534;
	// stw r18,12176(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12176, ctx.r18.u32);
	// ori r10,r20,65534
	ctx.r10.u64 = ctx.r20.u64 | 65534;
	// stw r9,12248(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12248, ctx.r9.u32);
	// stw r11,12252(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12252, ctx.r11.u32);
	// stw r10,12256(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12256, ctx.r10.u32);
	// b 0x8207c9ac
	__restgprlr_17(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82090E80"))) PPC_WEAK_FUNC(sub_82090E80);
PPC_FUNC_IMPL(__imp__sub_82090E80) {
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
	// lbz r11,11957(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 11957);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// addi r3,r3,2584
	ctx.r3.s64 = ctx.r3.s64 + 2584;
	// rlwinm r5,r11,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x8207da20
	ctx.lr = 0x82090EAC;
	sub_8207DA20(ctx, base);
	// lbz r11,11957(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11957);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// addi r3,r31,11028
	ctx.r3.s64 = ctx.r31.s64 + 11028;
	// rlwinm r5,r11,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x8207da20
	ctx.lr = 0x82090EC4;
	sub_8207DA20(ctx, base);
	// li r5,249
	ctx.r5.s64 = 249;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,3256
	ctx.r3.s64 = ctx.r31.s64 + 3256;
	// bl 0x8207da20
	ctx.lr = 0x82090ED4;
	sub_8207DA20(ctx, base);
	// li r5,249
	ctx.r5.s64 = 249;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,11700
	ctx.r3.s64 = ctx.r31.s64 + 11700;
	// bl 0x8207da20
	ctx.lr = 0x82090EE4;
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

__attribute__((alias("__imp__sub_82090EF8"))) PPC_WEAK_FUNC(sub_82090EF8);
PPC_FUNC_IMPL(__imp__sub_82090EF8) {
	PPC_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,11960(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11960, ctx.r11.u32);
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// stw r10,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// stw r10,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// stw r11,11024(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11024, ctx.r11.u32);
	// stw r10,11988(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11988, ctx.r10.u32);
	// stw r11,11980(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11980, ctx.r11.u32);
	// stw r11,11984(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11984, ctx.r11.u32);
	// stb r10,11958(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11958, ctx.r10.u8);
	// stw r11,11964(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11964, ctx.r11.u32);
	// stb r11,11959(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11959, ctx.r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82090F30"))) PPC_WEAK_FUNC(sub_82090F30);
PPC_FUNC_IMPL(__imp__sub_82090F30) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x82090F38;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r27,r5,261
	ctx.r27.s64 = ctx.r5.s64 + 261;
	// lis r10,0
	ctx.r10.s64 = 0;
	// add r11,r27,r6
	ctx.r11.u64 = ctx.r27.u64 + ctx.r6.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r25,r7
	ctx.r25.u64 = ctx.r7.u64;
	// clrlwi. r26,r7,31
	ctx.r26.u64 = ctx.r7.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// ori r28,r10,32768
	ctx.r28.u64 = ctx.r10.u64 | 32768;
	// addi r11,r11,12304
	ctx.r11.s64 = ctx.r11.s64 + 12304;
	// beq 0x82090f6c
	if (ctx.cr0.eq) goto loc_82090F6C;
	// addis r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 65536;
	// addi r11,r11,-26614
	ctx.r11.s64 = ctx.r11.s64 + -26614;
	// b 0x82090f78
	goto loc_82090F78;
loc_82090F6C:
	// rlwinm. r10,r25,0,0,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82090f78
	if (ctx.cr0.eq) goto loc_82090F78;
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
loc_82090F78:
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// beq cr6,0x82091030
	if (ctx.cr6.eq) goto loc_82091030;
	// add r31,r3,r6
	ctx.r31.u64 = ctx.r3.u64 + ctx.r6.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r29,r31,12304
	ctx.r29.s64 = ctx.r31.s64 + 12304;
	// bl 0x82090c10
	ctx.lr = 0x82090F98;
	sub_82090C10(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r30,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// addi r9,r30,-1
	ctx.r9.s64 = ctx.r30.s64 + -1;
	// stw r11,11992(r31)
	PPC_STORE_U32(ctx.r31.u32 + 11992, ctx.r11.u32);
	// stw r11,11996(r31)
	PPC_STORE_U32(ctx.r31.u32 + 11996, ctx.r11.u32);
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// stw r11,12000(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12000, ctx.r11.u32);
	// stb r10,11957(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11957, ctx.r10.u8);
loc_82090FBC:
	// lbz r9,11957(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11957);
	// li r8,1
	ctx.r8.s64 = 1;
	// add r7,r9,r31
	ctx.r7.u64 = ctx.r9.u64 + ctx.r31.u64;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// lbz r7,12004(r7)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r7.u32 + 12004);
	// stb r9,11957(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11957, ctx.r9.u8);
	// slw r9,r8,r7
	ctx.r9.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r7.u8 & 0x3F));
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmplw cr6,r10,r30
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r30.u32, ctx.xer);
	// blt cr6,0x82090fbc
	if (ctx.cr6.lt) goto loc_82090FBC;
	// add r10,r29,r27
	ctx.r10.u64 = ctx.r29.u64 + ctx.r27.u64;
	// stw r29,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// stw r11,12268(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12268, ctx.r11.u32);
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// stw r10,12264(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12264, ctx.r10.u32);
	// add r10,r10,r28
	ctx.r10.u64 = ctx.r10.u64 + ctx.r28.u64;
	// stw r11,12272(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12272, ctx.r11.u32);
	// stw r11,12276(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12276, ctx.r11.u32);
	// stw r11,12280(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12280, ctx.r11.u32);
	// stw r11,12284(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12284, ctx.r11.u32);
	// stw r11,12288(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12288, ctx.r11.u32);
	// stw r11,12292(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12292, ctx.r11.u32);
	// stw r11,12296(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12296, ctx.r11.u32);
	// beq cr6,0x82091024
	if (ctx.cr6.eq) goto loc_82091024;
	// stw r10,12276(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12276, ctx.r10.u32);
	// b 0x82091030
	goto loc_82091030;
loc_82091024:
	// rlwinm. r11,r25,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82091030
	if (ctx.cr0.eq) goto loc_82091030;
	// stw r10,12300(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12300, ctx.r10.u32);
loc_82091030:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82091038"))) PPC_WEAK_FUNC(sub_82091038);
PPC_FUNC_IMPL(__imp__sub_82091038) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82091040;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82094388
	ctx.lr = 0x82091060;
	sub_82094388(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82094160
	ctx.lr = 0x82091070;
	sub_82094160(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82092a78
	ctx.lr = 0x82091080;
	sub_82092A78(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82093410
	ctx.lr = 0x82091088;
	sub_82093410(ctx, base);
	// cmplw cr6,r3,r30
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r30.u32, ctx.xer);
	// blt cr6,0x820910a4
	if (ctx.cr6.lt) goto loc_820910A4;
	// lwz r11,2432(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2432);
	// lwz r10,2428(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2428);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x820910a4
	if (ctx.cr6.lt) goto loc_820910A4;
	// li r29,3
	ctx.r29.s64 = 3;
loc_820910A4:
	// clrlwi r5,r29,24
	ctx.r5.u64 = ctx.r29.u32 & 0xFF;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82091f58
	ctx.lr = 0x820910B4;
	sub_82091F58(ctx, base);
	// rlwinm r5,r30,16,24,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 16) & 0xFF;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82091f58
	ctx.lr = 0x820910C4;
	sub_82091F58(ctx, base);
	// rlwinm r5,r30,24,24,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 24) & 0xFF;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82091f58
	ctx.lr = 0x820910D4;
	sub_82091F58(ctx, base);
	// clrlwi r5,r30,24
	ctx.r5.u64 = ctx.r30.u32 & 0xFF;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82091f58
	ctx.lr = 0x820910E4;
	sub_82091F58(ctx, base);
	// cmpwi cr6,r29,1
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 1, ctx.xer);
	// bne cr6,0x82091104
	if (!ctx.cr6.eq) goto loc_82091104;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82092b48
	ctx.lr = 0x820910F4;
	sub_82092B48(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82093638
	ctx.lr = 0x82091100;
	sub_82093638(ctx, base);
	// b 0x82091128
	goto loc_82091128;
loc_82091104:
	// cmpwi cr6,r29,2
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 2, ctx.xer);
	// bne cr6,0x82091138
	if (!ctx.cr6.eq) goto loc_82091138;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82092bb0
	ctx.lr = 0x82091114;
	sub_82092BB0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82092b48
	ctx.lr = 0x8209111C;
	sub_82092B48(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82093b00
	ctx.lr = 0x82091128;
	sub_82093B00(ctx, base);
loc_82091128:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82093340
	ctx.lr = 0x82091134;
	sub_82093340(ctx, base);
	// b 0x8209115c
	goto loc_8209115C;
loc_82091138:
	// cmpwi cr6,r29,3
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 3, ctx.xer);
	// bne cr6,0x8209115c
	if (!ctx.cr6.eq) goto loc_8209115C;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82093340
	ctx.lr = 0x8209114C;
	sub_82093340(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,2432(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2432);
	// bl 0x82093560
	ctx.lr = 0x8209115C;
	sub_82093560(ctx, base);
loc_8209115C:
	// lwz r11,2432(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2432);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// stw r11,2432(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2432, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82091170"))) PPC_WEAK_FUNC(sub_82091170);
PPC_FUNC_IMPL(__imp__sub_82091170) {
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
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r6,32(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// addi r8,r1,84
	ctx.r8.s64 = ctx.r1.s64 + 84;
	// lwz r5,28(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// stb r30,2418(r3)
	PPC_STORE_U8(ctx.r3.u32 + 2418, ctx.r30.u8);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x820946d8
	ctx.lr = 0x820911A8;
	sub_820946D8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82091038
	ctx.lr = 0x820911B8;
	sub_82091038(ctx, base);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x820911e4
	if (!ctx.cr6.eq) goto loc_820911E4;
	// li r5,8192
	ctx.r5.s64 = 8192;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8207da20
	ctx.lr = 0x820911D8;
	sub_8207DA20(ctx, base);
	// stw r30,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r30.u32);
	// stw r30,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r30.u32);
	// b 0x8209127c
	goto loc_8209127C;
loc_820911E4:
	// rlwinm r11,r11,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// rlwinm r10,r10,29,3,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFFFFFF;
	// add r4,r11,r3
	ctx.r4.u64 = ctx.r11.u64 + ctx.r3.u64;
	// subf r11,r11,r10
	ctx.r11.s64 = ctx.r10.s64 - ctx.r11.s64;
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// bl 0x8207d870
	ctx.lr = 0x820911FC;
	sub_8207D870(ctx, base);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// subf r11,r9,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r9.s64;
	// rlwinm r11,r11,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// subfic r5,r11,8191
	ctx.xer.ca = ctx.r11.u32 <= 8191;
	ctx.r5.s64 = 8191 - ctx.r11.s64;
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// bl 0x8207da20
	ctx.lr = 0x82091224;
	sub_8207DA20(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// add r4,r3,r11
	ctx.r4.u64 = ctx.r3.u64 + ctx.r11.u64;
	// subf r5,r11,r10
	ctx.r5.s64 = ctx.r10.s64 - ctx.r11.s64;
	// bl 0x8207d870
	ctx.lr = 0x8209123C;
	sub_8207D870(ctx, base);
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r10,r3
	ctx.r4.u64 = ctx.r10.u64 + ctx.r3.u64;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// subf r11,r11,r10
	ctx.r11.s64 = ctx.r10.s64 - ctx.r11.s64;
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x8207d870
	ctx.lr = 0x8209125C;
	sub_8207D870(ctx, base);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// subf r11,r9,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r9.s64;
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// stw r10,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r10.u32);
loc_8209127C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82092c08
	ctx.lr = 0x82091284;
	sub_82092C08(ctx, base);
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

__attribute__((alias("__imp__sub_8209129C"))) PPC_WEAK_FUNC(sub_8209129C);
PPC_FUNC_IMPL(__imp__sub_8209129C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820912A0"))) PPC_WEAK_FUNC(sub_820912A0);
PPC_FUNC_IMPL(__imp__sub_820912A0) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 24);
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpwi cr6,r10,32
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 32, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,240
	ctx.r11.s64 = ctx.r11.s64 + 240;
	// clrlwi r4,r11,24
	ctx.r4.u64 = ctx.r11.u32 & 0xFF;
	// b 0x82091f58
	sub_82091F58(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820912C4"))) PPC_WEAK_FUNC(sub_820912C4);
PPC_FUNC_IMPL(__imp__sub_820912C4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820912C8"))) PPC_WEAK_FUNC(sub_820912C8);
PPC_FUNC_IMPL(__imp__sub_820912C8) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82092a78
	ctx.lr = 0x820912E8;
	sub_82092A78(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82093410
	ctx.lr = 0x820912F0;
	sub_82093410(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82092c08
	ctx.lr = 0x820912FC;
	sub_82092C08(ctx, base);
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

__attribute__((alias("__imp__sub_82091318"))) PPC_WEAK_FUNC(sub_82091318);
PPC_FUNC_IMPL(__imp__sub_82091318) {
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
	// b 0x82091334
	goto loc_82091334;
loc_82091330:
	// bl 0x82091170
	ctx.lr = 0x82091334;
	sub_82091170(ctx, base);
loc_82091334:
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bgt cr6,0x82091330
	if (ctx.cr6.gt) goto loc_82091330;
	// bl 0x820934e8
	ctx.lr = 0x82091348;
	sub_820934E8(ctx, base);
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

__attribute__((alias("__imp__sub_8209135C"))) PPC_WEAK_FUNC(sub_8209135C);
PPC_FUNC_IMPL(__imp__sub_8209135C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82091360"))) PPC_WEAK_FUNC(sub_82091360);
PPC_FUNC_IMPL(__imp__sub_82091360) {
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
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r11,2418(r3)
	PPC_STORE_U8(ctx.r3.u32 + 2418, ctx.r11.u8);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stb r10,2419(r3)
	PPC_STORE_U8(ctx.r3.u32 + 2419, ctx.r10.u8);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x82091170
	ctx.lr = 0x82091390;
	sub_82091170(ctx, base);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// cmplwi cr6,r11,4096
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4096, ctx.xer);
	// bge cr6,0x820913a4
	if (!ctx.cr6.lt) goto loc_820913A4;
	// li r11,4096
	ctx.r11.s64 = 4096;
	// b 0x820913a8
	goto loc_820913A8;
loc_820913A4:
	// addi r11,r11,4096
	ctx.r11.s64 = ctx.r11.s64 + 4096;
loc_820913A8:
	// stw r11,9504(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9504, ctx.r11.u32);
	// stw r30,2148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2148, ctx.r30.u32);
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

__attribute__((alias("__imp__sub_820913C8"))) PPC_WEAK_FUNC(sub_820913C8);
PPC_FUNC_IMPL(__imp__sub_820913C8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x820913D0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r30,2148(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2148);
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stb r29,2418(r3)
	PPC_STORE_U8(ctx.r3.u32 + 2418, ctx.r29.u8);
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// subf r10,r11,r30
	ctx.r10.s64 = ctx.r30.s64 - ctx.r11.s64;
	// lwz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// subf r8,r30,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r30.s64;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x82091408
	if (!ctx.cr6.lt) goto loc_82091408;
	// add r11,r10,r8
	ctx.r11.u64 = ctx.r10.u64 + ctx.r8.u64;
	// b 0x8209140c
	goto loc_8209140C;
loc_82091408:
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
loc_8209140C:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r8,17184(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 17184);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bgt cr6,0x820914c8
	if (ctx.cr6.gt) goto loc_820914C8;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r6,32(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lwz r5,28(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820946d8
	ctx.lr = 0x82091440;
	sub_820946D8(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82094388
	ctx.lr = 0x82091454;
	sub_82094388(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82092a78
	ctx.lr = 0x82091460;
	sub_82092A78(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82092c08
	ctx.lr = 0x82091468;
	sub_82092C08(ctx, base);
	// lis r5,4
	ctx.r5.s64 = 262144;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x8207da20
	ctx.lr = 0x82091478;
	sub_8207DA20(ctx, base);
	// li r5,8192
	ctx.r5.s64 = 8192;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// bl 0x8207da20
	ctx.lr = 0x82091488;
	sub_8207DA20(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r29,2144(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2144, ctx.r29.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// stw r11,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// stw r11,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// stb r11,2419(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2419, ctx.r11.u8);
	// stw r29,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r29.u32);
	// stw r29,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r29.u32);
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,9504(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9504, ctx.r11.u32);
	// stw r30,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r30.u32);
	// b 0x820914cc
	goto loc_820914CC;
loc_820914C8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_820914CC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820914D4"))) PPC_WEAK_FUNC(sub_820914D4);
PPC_FUNC_IMPL(__imp__sub_820914D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820914D8"))) PPC_WEAK_FUNC(sub_820914D8);
PPC_FUNC_IMPL(__imp__sub_820914D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c950
	ctx.lr = 0x820914E0;
	__savegprlr_14(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r30,1104(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1104);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lbz r11,2420(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2420);
	// mr r15,r4
	ctx.r15.u64 = ctx.r4.u64;
	// li r17,0
	ctx.r17.s64 = 0;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// add r14,r30,r4
	ctx.r14.u64 = ctx.r30.u64 + ctx.r4.u64;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// beq 0x82091558
	if (ctx.cr0.eq) goto loc_82091558;
	// lwz r11,2156(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2156);
	// li r10,10000
	ctx.r10.s64 = 10000;
	// stb r17,2420(r3)
	PPC_STORE_U8(ctx.r3.u32 + 2420, ctx.r17.u8);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r10,9504(r3)
	PPC_STORE_U32(ctx.r3.u32 + 9504, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8209154c
	if (ctx.cr6.eq) goto loc_8209154C;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82091f58
	ctx.lr = 0x8209152C;
	sub_82091F58(ctx, base);
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lhz r5,2156(r31)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r31.u32 + 2156);
	// bl 0x82091f58
	ctx.lr = 0x8209153C;
	sub_82091F58(ctx, base);
	// lhz r5,2158(r31)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r31.u32 + 2158);
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x82091550
	goto loc_82091550;
loc_8209154C:
	// li r5,0
	ctx.r5.s64 = 0;
loc_82091550:
	// bl 0x82091f58
	ctx.lr = 0x82091554;
	sub_82091F58(ctx, base);
	// b 0x8209157c
	goto loc_8209157C;
loc_82091558:
	// li r29,50
	ctx.r29.s64 = 50;
loc_8209155C:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// subf r4,r29,r30
	ctx.r4.s64 = ctx.r30.s64 - ctx.r29.s64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// subf r11,r11,r30
	ctx.r11.s64 = ctx.r30.s64 - ctx.r11.s64;
	// addi r5,r11,4
	ctx.r5.s64 = ctx.r11.s64 + 4;
	// bl 0x82092560
	ctx.lr = 0x82091574;
	sub_82092560(ctx, base);
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne 0x8209155c
	if (!ctx.cr0.eq) goto loc_8209155C;
loc_8209157C:
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// ori r18,r10,32768
	ctx.r18.u64 = ctx.r10.u64 | 32768;
	// lis r16,8
	ctx.r16.s64 = 524288;
	// li r19,1
	ctx.r19.s64 = 1;
	// addi r20,r11,12292
	ctx.r20.s64 = ctx.r11.s64 + 12292;
	// b 0x8209159c
	goto loc_8209159C;
loc_82091598:
	// lwz r30,80(r1)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_8209159C:
	// add r28,r30,r18
	ctx.r28.u64 = ctx.r30.u64 + ctx.r18.u64;
loc_820915A0:
	// cmplw cr6,r30,r14
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r14.u32, ctx.xer);
	// bge cr6,0x82091dc8
	if (!ctx.cr6.lt) goto loc_82091DC8;
	// rlwinm r23,r28,0,0,16
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0xFFFF8000;
	// cmplw cr6,r23,r14
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r14.u32, ctx.xer);
	// ble cr6,0x820915b8
	if (!ctx.cr6.gt) goto loc_820915B8;
	// mr r23,r14
	ctx.r23.u64 = ctx.r14.u64;
loc_820915B8:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82092218
	ctx.lr = 0x820915C4;
	sub_82092218(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// blt cr6,0x820915e8
	if (ctx.cr6.lt) goto loc_820915E8;
	// add r11,r3,r30
	ctx.r11.u64 = ctx.r3.u64 + ctx.r30.u64;
	// cmplw cr6,r11,r23
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r23.u32, ctx.xer);
	// ble cr6,0x8209162c
	if (!ctx.cr6.gt) goto loc_8209162C;
	// subf r29,r30,r23
	ctx.r29.s64 = ctx.r23.s64 - ctx.r30.s64;
	// cmpwi cr6,r29,2
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 2, ctx.xer);
	// bge cr6,0x8209162c
	if (!ctx.cr6.lt) goto loc_8209162C;
loc_820915E8:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r9,40(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// lbzx r11,r11,r30
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r30.u32);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// stbx r11,r9,r10
	PPC_STORE_U8(ctx.r9.u32 + ctx.r10.u32, ctx.r11.u8);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// cmplwi cr6,r11,65528
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 65528, ctx.xer);
	// blt cr6,0x820915a0
	if (ctx.cr6.lt) goto loc_820915A0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82091360
	ctx.lr = 0x82091628;
	sub_82091360(ctx, base);
	// b 0x820915a0
	goto loc_820915A0;
loc_8209162C:
	// cmpwi cr6,r29,50
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 50, ctx.xer);
	// bge cr6,0x82091c90
	if (!ctx.cr6.lt) goto loc_82091C90;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// add r24,r29,r30
	ctx.r24.u64 = ctx.r29.u64 + ctx.r30.u64;
	// lwz r10,9516(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9516);
	// addi r22,r30,3837
	ctx.r22.s64 = ctx.r30.s64 + 3837;
	// mr r21,r30
	ctx.r21.u64 = ctx.r30.u64;
	// li r9,2
	ctx.r9.s64 = 2;
	// cmplwi cr6,r29,2
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 2, ctx.xer);
	// lbzx r11,r11,r30
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r30.u32);
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lbz r11,9520(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 9520);
	// stw r11,44(r10)
	PPC_STORE_U32(ctx.r10.u32 + 44, ctx.r11.u32);
	// lwz r11,9516(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9516);
	// stw r30,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r30.u32);
	// blt cr6,0x8209173c
	if (ctx.cr6.lt) goto loc_8209173C;
	// addi r11,r29,-1
	ctx.r11.s64 = ctx.r29.s64 + -1;
	// li r10,48
	ctx.r10.s64 = 48;
	// addi r6,r31,76
	ctx.r6.s64 = ctx.r31.s64 + 76;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8209167C:
	// lwz r11,4(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// cmplwi cr6,r11,1024
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1024, ctx.xer);
	// bge cr6,0x82091694
	if (!ctx.cr6.lt) goto loc_82091694;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lbz r11,1108(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1108);
	// b 0x820916b8
	goto loc_820916B8;
loc_82091694:
	// cmplw cr6,r11,r16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r16.u32, ctx.xer);
	// bge cr6,0x820916b0
	if (!ctx.cr6.lt) goto loc_820916B0;
	// rlwinm r11,r11,23,9,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 23) & 0x7FFFFF;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lbz r11,1108(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1108);
	// addi r11,r11,18
	ctx.r11.s64 = ctx.r11.s64 + 18;
	// b 0x820916b8
	goto loc_820916B8;
loc_820916B0:
	// rlwinm r11,r11,15,24,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 15) & 0xFF;
	// addi r11,r11,34
	ctx.r11.s64 = ctx.r11.s64 + 34;
loc_820916B8:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// lwz r7,9516(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9516);
	// cmplwi cr6,r9,9
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 9, ctx.xer);
	// rlwinm r8,r11,3,21,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0x7F8;
	// bge cr6,0x820916f0
	if (!ctx.cr6.lt) goto loc_820916F0;
	// clrlwi r5,r11,24
	ctx.r5.u64 = ctx.r11.u32 & 0xFF;
	// add r11,r8,r9
	ctx.r11.u64 = ctx.r8.u64 + ctx.r9.u64;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// add r8,r11,r31
	ctx.r8.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lbzx r11,r5,r20
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r20.u32);
	// lbz r8,9774(r8)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r8.u32 + 9774);
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// stw r11,20(r7)
	PPC_STORE_U32(ctx.r7.u32 + 20, ctx.r11.u32);
	// b 0x82091718
	goto loc_82091718;
loc_820916F0:
	// add r5,r9,r31
	ctx.r5.u64 = ctx.r9.u64 + ctx.r31.u64;
	// add r8,r8,r31
	ctx.r8.u64 = ctx.r8.u64 + ctx.r31.u64;
	// clrlwi r4,r11,24
	ctx.r4.u64 = ctx.r11.u32 & 0xFF;
	// add r3,r10,r7
	ctx.r3.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lbz r11,10212(r5)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + 10212);
	// lbz r8,9783(r8)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r8.u32 + 9783);
	// lbzx r7,r4,r20
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r20.u32);
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
loc_82091718:
	// lwz r11,9516(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9516);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// lwzu r11,4(r6)
	ea = 4 + ctx.r6.u32;
	ctx.r11.u64 = PPC_LOAD_U32(ea);
	ctx.r6.u32 = ea;
	// lwz r8,9516(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9516);
	// stwx r11,r10,r8
	PPC_STORE_U32(ctx.r10.u32 + ctx.r8.u32, ctx.r11.u32);
	// addi r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 + 24;
	// bdnz 0x8209167c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8209167C;
loc_8209173C:
	// lwz r10,9516(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9516);
	// mulli r11,r30,24
	ctx.r11.s64 = ctx.r30.s64 * 24;
	// stw r17,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r17.u32);
	// lwz r10,60(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// lwz r9,9516(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9516);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// addi r26,r30,-1
	ctx.r26.s64 = ctx.r30.s64 + -1;
	// lwz r10,9516(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9516);
	// subf r27,r30,r23
	ctx.r27.s64 = ctx.r23.s64 - ctx.r30.s64;
	// lwz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// stw r9,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r9.u32);
	// lwz r10,9516(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9516);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// stw r9,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r9.u32);
	// lwz r10,9516(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9516);
	// subf r25,r11,r10
	ctx.r25.s64 = ctx.r10.s64 - ctx.r11.s64;
	// add r11,r11,r25
	ctx.r11.u64 = ctx.r11.u64 + ctx.r25.u64;
	// addi r29,r11,4
	ctx.r29.s64 = ctx.r11.s64 + 4;
loc_82091784:
	// lwzu r11,24(r29)
	ea = 24 + ctx.r29.u32;
	ctx.r11.u64 = PPC_LOAD_U32(ea);
	ctx.r29.u32 = ea;
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r27,r27,-1
	ctx.r27.s64 = ctx.r27.s64 + -1;
	// cmplw cr6,r11,r26
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r26.u32, ctx.xer);
	// beq cr6,0x82091818
	if (ctx.cr6.eq) goto loc_82091818;
	// lwz r10,-4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + -4);
	// mulli r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 * 24;
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// add r11,r11,r25
	ctx.r11.u64 = ctx.r11.u64 + ctx.r25.u64;
	// blt cr6,0x820917c8
	if (ctx.cr6.lt) goto loc_820917C8;
	// addi r10,r10,-2
	ctx.r10.s64 = ctx.r10.s64 + -2;
	// stw r10,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r10.u32);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// lwz r11,12(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// b 0x82091814
	goto loc_82091814;
loc_820917C8:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820917e8
	if (!ctx.cr6.eq) goto loc_820917E8;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// stw r10,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r10.u32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
loc_820917DC:
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// b 0x82091814
	goto loc_82091814;
loc_820917E8:
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x82091800
	if (!ctx.cr6.eq) goto loc_82091800;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// stw r10,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r10.u32);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x820917dc
	goto loc_820917DC;
loc_82091800:
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// stw r10,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r10.u32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
loc_82091814:
	// stw r11,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
loc_82091818:
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// cmplw cr6,r24,r30
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r30.u32, ctx.xer);
	// stw r11,4(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4, ctx.r11.u32);
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// stw r11,8(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8, ctx.r11.u32);
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// stw r11,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r11.u32);
	// beq cr6,0x82091ab8
	if (ctx.cr6.eq) goto loc_82091AB8;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82092218
	ctx.lr = 0x82091844;
	sub_82092218(ctx, base);
	// add r11,r3,r30
	ctx.r11.u64 = ctx.r3.u64 + ctx.r30.u64;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplw cr6,r11,r23
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r23.u32, ctx.xer);
	// ble cr6,0x8209186c
	if (!ctx.cr6.gt) goto loc_8209186C;
	// li r11,2
	ctx.r11.s64 = 2;
	// xoris r10,r11,32768
	ctx.r10.u64 = ctx.r11.u64 ^ 2147483648;
	// subf r11,r11,r27
	ctx.r11.s64 = ctx.r27.s64 - ctx.r11.s64;
	// addc r11,r11,r10
	{ uint8_t _ca = ctx.r11.u32 + ctx.r10.u32 < ctx.r11.u32; // FIX 2026-07-24: insn was silently dropped by the recompiler
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	ctx.xer.ca = _ca; }
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r28,r11,r27
	ctx.r28.u64 = ctx.r11.u64 & ctx.r27.u64;
loc_8209186C:
	// cmpwi cr6,r28,50
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 50, ctx.xer);
	// bgt cr6,0x820919f0
	if (ctx.cr6.gt) goto loc_820919F0;
	// add r9,r28,r30
	ctx.r9.u64 = ctx.r28.u64 + ctx.r30.u64;
	// cmplw cr6,r9,r22
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r22.u32, ctx.xer);
	// bge cr6,0x820919f0
	if (!ctx.cr6.lt) goto loc_820919F0;
	// cmpwi cr6,r28,2
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 2, ctx.xer);
	// bgt cr6,0x82091898
	if (ctx.cr6.gt) goto loc_82091898;
	// bne cr6,0x820918f0
	if (!ctx.cr6.eq) goto loc_820918F0;
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// cmplwi cr6,r11,2048
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2048, ctx.xer);
	// bge cr6,0x820918f0
	if (!ctx.cr6.lt) goto loc_820918F0;
loc_82091898:
	// cmplw cr6,r24,r9
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x820918f0
	if (!ctx.cr6.lt) goto loc_820918F0;
	// subf r11,r21,r28
	ctx.r11.s64 = ctx.r28.s64 - ctx.r21.s64;
	// add r10,r11,r30
	ctx.r10.u64 = ctx.r11.u64 + ctx.r30.u64;
	// cmplwi cr6,r10,3836
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3836, ctx.xer);
	// blt cr6,0x820918b4
	if (ctx.cr6.lt) goto loc_820918B4;
	// li r10,3836
	ctx.r10.s64 = 3836;
loc_820918B4:
	// subf r11,r21,r24
	ctx.r11.s64 = ctx.r24.s64 - ctx.r21.s64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bgt cr6,0x820918ec
	if (ctx.cr6.gt) goto loc_820918EC;
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r11.s64;
	// mulli r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 * 24;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_820918D4:
	// lwz r10,9516(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9516);
	// li r8,-1
	ctx.r8.s64 = -1;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// stw r8,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r8.u32);
	// bdnz 0x820918d4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820918D4;
loc_820918EC:
	// mr r24,r9
	ctx.r24.u64 = ctx.r9.u64;
loc_820918F0:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r5,16(r29)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// lwz r10,40(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 40);
	// lbzx r11,r11,r30
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r30.u32);
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lbz r11,9520(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 9520);
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8209191c
	if (!ctx.cr6.lt) goto loc_8209191C;
	// stw r11,40(r29)
	PPC_STORE_U32(ctx.r29.u32 + 40, ctx.r11.u32);
	// stw r30,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r30.u32);
loc_8209191C:
	// li r8,2
	ctx.r8.s64 = 2;
	// cmplwi cr6,r28,2
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 2, ctx.xer);
	// blt cr6,0x82091784
	if (ctx.cr6.lt) goto loc_82091784;
	// addi r11,r28,-1
	ctx.r11.s64 = ctx.r28.s64 + -1;
	// addi r6,r31,80
	ctx.r6.s64 = ctx.r31.s64 + 80;
	// addi r7,r29,64
	ctx.r7.s64 = ctx.r29.s64 + 64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_82091938:
	// lwz r11,0(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,1024
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1024, ctx.xer);
	// bge cr6,0x82091950
	if (!ctx.cr6.lt) goto loc_82091950;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lbz r11,1108(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1108);
	// b 0x82091974
	goto loc_82091974;
loc_82091950:
	// cmplw cr6,r11,r16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r16.u32, ctx.xer);
	// bge cr6,0x8209196c
	if (!ctx.cr6.lt) goto loc_8209196C;
	// rlwinm r11,r11,23,9,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 23) & 0x7FFFFF;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lbz r11,1108(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1108);
	// addi r11,r11,18
	ctx.r11.s64 = ctx.r11.s64 + 18;
	// b 0x82091974
	goto loc_82091974;
loc_8209196C:
	// rlwinm r11,r11,15,24,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 15) & 0xFF;
	// addi r11,r11,34
	ctx.r11.s64 = ctx.r11.s64 + 34;
loc_82091974:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r8,9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 9, ctx.xer);
	// rlwinm r10,r11,3,21,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0x7F8;
	// bge cr6,0x8209199c
	if (!ctx.cr6.lt) goto loc_8209199C;
	// clrlwi r9,r11,24
	ctx.r9.u64 = ctx.r11.u32 & 0xFF;
	// add r11,r10,r8
	ctx.r11.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lbzx r10,r9,r20
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r20.u32);
	// lbz r11,9774(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 9774);
	// b 0x820919b8
	goto loc_820919B8;
loc_8209199C:
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + ctx.r31.u64;
	// add r9,r8,r31
	ctx.r9.u64 = ctx.r8.u64 + ctx.r31.u64;
	// clrlwi r4,r11,24
	ctx.r4.u64 = ctx.r11.u32 & 0xFF;
	// lbz r11,9783(r10)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 9783);
	// lbz r9,10212(r9)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r9.u32 + 10212);
	// lbzx r10,r4,r20
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r20.u32);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
loc_820919B8:
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x820919dc
	if (!ctx.cr6.lt) goto loc_820919DC;
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r11.u32);
	// stw r30,-16(r7)
	PPC_STORE_U32(ctx.r7.u32 + -16, ctx.r30.u32);
	// lwz r11,0(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// stw r11,-20(r7)
	PPC_STORE_U32(ctx.r7.u32 + -20, ctx.r11.u32);
loc_820919DC:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// addi r7,r7,24
	ctx.r7.s64 = ctx.r7.s64 + 24;
	// bdnz 0x82091938
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82091938;
	// b 0x82091784
	goto loc_82091784;
loc_820919F0:
	// addi r11,r28,18
	ctx.r11.s64 = ctx.r28.s64 + 18;
	// add r26,r28,r30
	ctx.r26.u64 = ctx.r28.u64 + ctx.r30.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mulli r11,r26,24
	ctx.r11.s64 = ctx.r26.s64 * 24;
	// lwzx r27,r10,r31
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// add r11,r11,r25
	ctx.r11.u64 = ctx.r11.u64 + ctx.r25.u64;
	// cmplwi cr6,r27,3
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 3, ctx.xer);
	// stw r27,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r27.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// bne cr6,0x82091a3c
	if (!ctx.cr6.eq) goto loc_82091A3C;
	// cmpwi cr6,r28,16
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 16, ctx.xer);
	// ble cr6,0x82091a3c
	if (!ctx.cr6.gt) goto loc_82091A3C;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r4,r30,1
	ctx.r4.s64 = ctx.r30.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// subf r11,r11,r30
	ctx.r11.s64 = ctx.r30.s64 - ctx.r11.s64;
	// addi r5,r11,5
	ctx.r5.s64 = ctx.r11.s64 + 5;
	// bl 0x82092560
	ctx.lr = 0x82091A38;
	sub_82092560(ctx, base);
	// b 0x82091a70
	goto loc_82091A70;
loc_82091A3C:
	// mr r29,r19
	ctx.r29.u64 = ctx.r19.u64;
	// cmplwi cr6,r28,1
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 1, ctx.xer);
	// ble cr6,0x82091a70
	if (!ctx.cr6.gt) goto loc_82091A70;
loc_82091A48:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// add r4,r29,r30
	ctx.r4.u64 = ctx.r29.u64 + ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// subf r11,r11,r29
	ctx.r11.s64 = ctx.r29.s64 - ctx.r11.s64;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r5,r11,4
	ctx.r5.s64 = ctx.r11.s64 + 4;
	// bl 0x82092560
	ctx.lr = 0x82091A64;
	sub_82092560(ctx, base);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmplw cr6,r29,r28
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r28.u32, ctx.xer);
	// blt cr6,0x82091a48
	if (ctx.cr6.lt) goto loc_82091A48;
loc_82091A70:
	// mr r30,r26
	ctx.r30.u64 = ctx.r26.u64;
	// cmplwi cr6,r27,3
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 3, ctx.xer);
	// blt cr6,0x82091a98
	if (ctx.cr6.lt) goto loc_82091A98;
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// addi r10,r27,-2
	ctx.r10.s64 = ctx.r27.s64 + -2;
	// lwz r9,60(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// stw r10,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r10.u32);
	// stw r11,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// stw r9,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r9.u32);
	// b 0x82091ab8
	goto loc_82091AB8;
loc_82091A98:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82091ab8
	if (ctx.cr6.eq) goto loc_82091AB8;
	// addi r11,r27,15
	ctx.r11.s64 = ctx.r27.s64 + 15;
	// lwz r10,60(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r31
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// stw r9,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r9.u32);
	// stwx r10,r11,r31
	PPC_STORE_U32(ctx.r11.u32 + ctx.r31.u32, ctx.r10.u32);
loc_82091AB8:
	// mulli r11,r30,24
	ctx.r11.s64 = ctx.r30.s64 * 24;
	// add r11,r11,r25
	ctx.r11.u64 = ctx.r11.u64 + ctx.r25.u64;
	// mr r28,r17
	ctx.r28.u64 = ctx.r17.u64;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
loc_82091AC8:
	// mulli r10,r11,24
	ctx.r10.s64 = ctx.r11.s64 * 24;
	// add r9,r10,r25
	ctx.r9.u64 = ctx.r10.u64 + ctx.r25.u64;
	// add r10,r10,r25
	ctx.r10.u64 = ctx.r10.u64 + ctx.r25.u64;
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// cmplw cr6,r11,r21
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r21.u32, ctx.xer);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// lwz r11,4(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r30,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r30.u32);
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// bne cr6,0x82091ac8
	if (!ctx.cr6.eq) goto loc_82091AC8;
loc_82091AF0:
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// cmplwi cr6,r11,65528
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 65528, ctx.xer);
	// bge cr6,0x82091b10
	if (!ctx.cr6.lt) goto loc_82091B10;
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// cmplwi cr6,r11,32760
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32760, ctx.xer);
	// blt cr6,0x82091b20
	if (ctx.cr6.lt) goto loc_82091B20;
loc_82091B10:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82091360
	ctx.lr = 0x82091B1C;
	sub_82091360(ctx, base);
	// b 0x82091af0
	goto loc_82091AF0;
loc_82091B20:
	// mulli r11,r30,24
	ctx.r11.s64 = ctx.r30.s64 * 24;
	// add r11,r11,r25
	ctx.r11.u64 = ctx.r11.u64 + ctx.r25.u64;
	// addi r10,r30,1
	ctx.r10.s64 = ctx.r30.s64 + 1;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x82091bac
	if (!ctx.cr6.gt) goto loc_82091BAC;
	// lwz r8,28(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r9,44(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// rlwinm r10,r8,29,3,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 29) & 0x1FFFFFFF;
	// clrlwi r8,r8,29
	ctx.r8.u64 = ctx.r8.u32 & 0x7;
	// slw r8,r19,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r19.u32 << (ctx.r8.u8 & 0x3F));
	// lbzx r7,r10,r9
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r9.u32);
	// or r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 | ctx.r7.u64;
	// stbx r8,r10,r9
	PPC_STORE_U8(ctx.r10.u32 + ctx.r9.u32, ctx.r8.u8);
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r8,40(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// subf r10,r30,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r30.s64;
	// addi r10,r10,254
	ctx.r10.s64 = ctx.r10.s64 + 254;
	// stbx r10,r9,r8
	PPC_STORE_U8(ctx.r9.u32 + ctx.r8.u32, ctx.r10.u8);
	// lwz r8,32(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r10.u32);
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mulli r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 * 24;
	// lwzx r10,r10,r25
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r25.u32);
	// stwx r10,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r10.u32);
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r10.u32);
	// lwz r30,4(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x82091bd0
	goto loc_82091BD0;
loc_82091BAC:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r8,40(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// lbzx r11,r11,r30
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r30.u32);
	// mr r30,r10
	ctx.r30.u64 = ctx.r10.u64;
	// stbx r11,r9,r8
	PPC_STORE_U8(ctx.r9.u32 + ctx.r8.u32, ctx.r11.u8);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
loc_82091BD0:
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bne 0x82091b20
	if (!ctx.cr0.eq) goto loc_82091B20;
	// lwz r6,28(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r11,9504(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9504);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// cmplw cr6,r6,r11
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82091c54
	if (ctx.cr6.lt) goto loc_82091C54;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x82091c48
	if (ctx.cr6.eq) goto loc_82091C48;
	// lbz r11,2419(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 2419);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82091c18
	if (ctx.cr0.eq) goto loc_82091C18;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82094388
	ctx.lr = 0x82091C10;
	sub_82094388(ctx, base);
	// stb r17,2419(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2419, ctx.r17.u8);
	// b 0x82091c24
	goto loc_82091C24;
loc_82091C18:
	// lwz r5,9512(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9512);
	// lwz r4,9508(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9508);
	// bl 0x820943e0
	ctx.lr = 0x82091C24;
	sub_820943E0(ctx, base);
loc_82091C24:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82092a78
	ctx.lr = 0x82091C30;
	sub_82092A78(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82092c08
	ctx.lr = 0x82091C38;
	sub_82092C08(ctx, base);
	// lwz r6,28(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// stw r6,9508(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9508, ctx.r6.u32);
	// stw r11,9512(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9512, ctx.r11.u32);
loc_82091C48:
	// lwz r11,9504(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 9504);
	// addi r11,r11,4096
	ctx.r11.s64 = ctx.r11.s64 + 4096;
	// stw r11,9504(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9504, ctx.r11.u32);
loc_82091C54:
	// lbz r11,2418(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 2418);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8209159c
	if (ctx.cr0.eq) goto loc_8209159C;
	// cmplwi cr6,r6,65024
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 65024, ctx.xer);
	// bge cr6,0x82091c74
	if (!ctx.cr6.lt) goto loc_82091C74;
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// cmplwi cr6,r11,32256
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32256, ctx.xer);
	// blt cr6,0x8209159c
	if (ctx.cr6.lt) goto loc_8209159C;
loc_82091C74:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820913c8
	ctx.lr = 0x82091C80;
	sub_820913C8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82091598
	if (!ctx.cr0.eq) goto loc_82091598;
	// lwz r30,80(r1)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// b 0x82091db8
	goto loc_82091DB8;
loc_82091C90:
	// addi r11,r29,18
	ctx.r11.s64 = ctx.r29.s64 + 18;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r27,r11,r31
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// cmplwi cr6,r27,3
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 3, ctx.xer);
	// bne cr6,0x82091cc8
	if (!ctx.cr6.eq) goto loc_82091CC8;
	// cmpwi cr6,r29,16
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 16, ctx.xer);
	// ble cr6,0x82091cc8
	if (!ctx.cr6.gt) goto loc_82091CC8;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r4,r30,1
	ctx.r4.s64 = ctx.r30.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// subf r11,r11,r30
	ctx.r11.s64 = ctx.r30.s64 - ctx.r11.s64;
	// addi r5,r11,5
	ctx.r5.s64 = ctx.r11.s64 + 5;
	// bl 0x82092560
	ctx.lr = 0x82091CC4;
	sub_82092560(ctx, base);
	// b 0x82091cfc
	goto loc_82091CFC;
loc_82091CC8:
	// mr r28,r19
	ctx.r28.u64 = ctx.r19.u64;
	// cmplwi cr6,r29,1
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 1, ctx.xer);
	// ble cr6,0x82091cfc
	if (!ctx.cr6.gt) goto loc_82091CFC;
loc_82091CD4:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// add r4,r28,r30
	ctx.r4.u64 = ctx.r28.u64 + ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// subf r11,r11,r28
	ctx.r11.s64 = ctx.r28.s64 - ctx.r11.s64;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r5,r11,4
	ctx.r5.s64 = ctx.r11.s64 + 4;
	// bl 0x82092560
	ctx.lr = 0x82091CF0;
	sub_82092560(ctx, base);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// cmplw cr6,r28,r29
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r29.u32, ctx.xer);
	// blt cr6,0x82091cd4
	if (ctx.cr6.lt) goto loc_82091CD4;
loc_82091CFC:
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// addi r8,r29,254
	ctx.r8.s64 = ctx.r29.s64 + 254;
	// lwz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// add r30,r29,r30
	ctx.r30.u64 = ctx.r29.u64 + ctx.r30.u64;
	// rlwinm r11,r9,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 29) & 0x1FFFFFFF;
	// clrlwi r9,r9,29
	ctx.r9.u64 = ctx.r9.u32 & 0x7;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// cmplwi cr6,r27,3
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 3, ctx.xer);
	// slw r9,r19,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r19.u32 << (ctx.r9.u8 & 0x3F));
	// lbzx r7,r11,r10
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r10.u32);
	// or r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 | ctx.r7.u64;
	// stbx r9,r11,r10
	PPC_STORE_U8(ctx.r11.u32 + ctx.r10.u32, ctx.r9.u8);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// stbx r8,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + ctx.r11.u32, ctx.r8.u8);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// stwx r27,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r27.u32);
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// blt cr6,0x82091d80
	if (ctx.cr6.lt) goto loc_82091D80;
	// lwz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// addi r10,r27,-2
	ctx.r10.s64 = ctx.r27.s64 + -2;
	// lwz r9,60(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// stw r10,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r10.u32);
	// stw r11,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// stw r9,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r9.u32);
	// b 0x82091da0
	goto loc_82091DA0;
loc_82091D80:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82091da0
	if (ctx.cr6.eq) goto loc_82091DA0;
	// addi r11,r27,15
	ctx.r11.s64 = ctx.r27.s64 + 15;
	// lwz r10,60(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r31
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// stw r9,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r9.u32);
	// stwx r10,r11,r31
	PPC_STORE_U32(ctx.r11.u32 + ctx.r31.u32, ctx.r10.u32);
loc_82091DA0:
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// cmplwi cr6,r11,65528
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 65528, ctx.xer);
	// bge cr6,0x82091db8
	if (!ctx.cr6.lt) goto loc_82091DB8;
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// cmplwi cr6,r11,32760
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32760, ctx.xer);
	// blt cr6,0x8209159c
	if (ctx.cr6.lt) goto loc_8209159C;
loc_82091DB8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82091360
	ctx.lr = 0x82091DC4;
	sub_82091360(ctx, base);
	// b 0x8209159c
	goto loc_8209159C;
loc_82091DC8:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpw cr6,r15,r18
	ctx.cr6.compare<int32_t>(ctx.r15.s32, ctx.r18.s32, ctx.xer);
	// subf r11,r11,r30
	ctx.r11.s64 = ctx.r30.s64 - ctx.r11.s64;
	// stw r11,2428(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2428, ctx.r11.u32);
	// bge cr6,0x82091e04
	if (!ctx.cr6.lt) goto loc_82091E04;
	// lbz r11,2418(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 2418);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82091ef4
	if (ctx.cr0.eq) goto loc_82091EF4;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820913c8
	ctx.lr = 0x82091DF4;
	sub_820913C8(ctx, base);
	// lwz r30,80(r1)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82091ef4
	if (ctx.cr0.eq) goto loc_82091EF4;
	// b 0x8209159c
	goto loc_8209159C;
loc_82091E04:
	// addi r28,r11,54
	ctx.r28.s64 = ctx.r11.s64 + 54;
	// mr r29,r19
	ctx.r29.u64 = ctx.r19.u64;
loc_82091E0C:
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// subf r4,r29,r30
	ctx.r4.s64 = ctx.r30.s64 - ctx.r29.s64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820926b8
	ctx.lr = 0x82091E1C;
	sub_820926B8(ctx, base);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmplwi cr6,r29,50
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 50, ctx.xer);
	// ble cr6,0x82091e0c
	if (!ctx.cr6.gt) goto loc_82091E0C;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r8,17184(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 17184);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r10,2424(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2424);
	// subf r11,r8,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r8.s64;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82091ef4
	if (ctx.cr6.lt) goto loc_82091EF4;
	// lbz r11,2418(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 2418);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82091e70
	if (ctx.cr0.eq) goto loc_82091E70;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820913c8
	ctx.lr = 0x82091E64;
	sub_820913C8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82091598
	if (!ctx.cr0.eq) goto loc_82091598;
	// lwz r30,80(r1)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_82091E70:
	// lwz r3,17184(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 17184);
	// lwz r11,2424(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2424);
	// lwz r5,4(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// add r4,r3,r11
	ctx.r4.u64 = ctx.r3.u64 + ctx.r11.u64;
	// bl 0x8207d870
	ctx.lr = 0x82091E84;
	sub_8207D870(ctx, base);
	// lwz r11,2424(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2424);
	// lwz r3,17188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 17188);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r5,r10,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r3
	ctx.r4.u64 = ctx.r11.u64 + ctx.r3.u64;
	// bl 0x8207d870
	ctx.lr = 0x82091EA0;
	sub_8207D870(ctx, base);
	// lwz r11,2424(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2424);
	// lwz r3,17192(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 17192);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r5,r10,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r3
	ctx.r4.u64 = ctx.r11.u64 + ctx.r3.u64;
	// bl 0x8207d870
	ctx.lr = 0x82091EBC;
	sub_8207D870(ctx, base);
	// lwz r11,2424(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2424);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// subf r11,r11,r10
	ctx.r11.s64 = ctx.r10.s64 - ctx.r11.s64;
	// lwz r7,16(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// subf r8,r8,r7
	ctx.r8.s64 = ctx.r7.s64 - ctx.r8.s64;
	// stw r9,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r9.u32);
	// stw r8,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r8.u32);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// subf r11,r10,r30
	ctx.r11.s64 = ctx.r30.s64 - ctx.r10.s64;
	// stw r11,2428(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2428, ctx.r11.u32);
loc_82091EF4:
	// stw r30,1104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1104, ctx.r30.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8207c9a0
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82091F00"))) PPC_WEAK_FUNC(sub_82091F00);
PPC_FUNC_IMPL(__imp__sub_82091F00) {
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
	// lwz r11,1104(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1104);
	// lis r5,0
	ctx.r5.s64 = 0;
	// lwz r9,17184(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 17184);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// ori r5,r5,32768
	ctx.r5.u64 = ctx.r5.u64 | 32768;
	// subf r11,r9,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r9.s64;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x82092130
	ctx.lr = 0x82091F34;
	sub_82092130(ctx, base);
	// mr. r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// ble 0x82091f44
	if (!ctx.cr0.gt) goto loc_82091F44;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820914d8
	ctx.lr = 0x82091F44;
	sub_820914D8(ctx, base);
loc_82091F44:
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

__attribute__((alias("__imp__sub_82091F58"))) PPC_WEAK_FUNC(sub_82091F58);
PPC_FUNC_IMPL(__imp__sub_82091F58) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 24);
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// subf r11,r4,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r4.s64;
	// extsb r9,r11
	ctx.r9.s64 = ctx.r11.s8;
	// slw r11,r5,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r5.u32 << (ctx.r11.u8 & 0x3F));
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stb r9,24(r3)
	PPC_STORE_U8(ctx.r3.u32 + 24, ctx.r9.u8);
	// cmpwi cr6,r9,16
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 16, ctx.xer);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// bgtlr cr6
	if (ctx.cr6.gt) return;
loc_82091F84:
	// lwz r11,2136(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2136);
	// lwz r10,2140(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2140);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82091fa4
	if (ctx.cr6.lt) goto loc_82091FA4;
	// lwz r11,2132(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2132);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,25(r3)
	PPC_STORE_U8(ctx.r3.u32 + 25, ctx.r10.u8);
	// stw r11,2136(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2136, ctx.r11.u32);
loc_82091FA4:
	// lwz r11,2136(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2136);
	// lbz r10,21(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 21);
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// lbz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 20);
	// lwz r11,2136(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2136);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,2136(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2136, ctx.r11.u32);
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// lbz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 24);
	// lwz r9,20(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r11,2136(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2136);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// stw r11,2136(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2136, ctx.r11.u32);
	// rlwinm r9,r9,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// extsb r11,r10
	ctx.r11.s64 = ctx.r10.s8;
	// stb r10,24(r3)
	PPC_STORE_U8(ctx.r3.u32 + 24, ctx.r10.u8);
	// stw r9,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r9.u32);
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// ble cr6,0x82091f84
	if (!ctx.cr6.gt) goto loc_82091F84;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82091FF8"))) PPC_WEAK_FUNC(sub_82091FF8);
PPC_FUNC_IMPL(__imp__sub_82091FF8) {
	PPC_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,2444(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2444, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82092004"))) PPC_WEAK_FUNC(sub_82092004);
PPC_FUNC_IMPL(__imp__sub_82092004) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82092008"))) PPC_WEAK_FUNC(sub_82092008);
PPC_FUNC_IMPL(__imp__sub_82092008) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82092010;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// cmpwi cr6,r5,6
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 6, ctx.xer);
	// bgt cr6,0x82092034
	if (ctx.cr6.gt) goto loc_82092034;
	// lwz r11,2444(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2444);
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// b 0x82092120
	goto loc_82092120;
loc_82092034:
	// add r27,r30,r29
	ctx.r27.u64 = ctx.r30.u64 + ctx.r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r28,r27,-6
	ctx.r28.s64 = ctx.r27.s64 + -6;
	// li r5,6
	ctx.r5.s64 = 6;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x8207dac0
	ctx.lr = 0x8209204C;
	sub_8207DAC0(ctx, base);
	// li r5,6
	ctx.r5.s64 = 6;
	// li r4,232
	ctx.r4.s64 = 232;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8207da20
	ctx.lr = 0x8209205C;
	sub_8207DA20(ctx, base);
	// lwz r11,2444(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2444);
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// addi r29,r11,-10
	ctx.r29.s64 = ctx.r11.s64 + -10;
loc_82092068:
	// lbz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + 0);
	// b 0x82092080
	goto loc_82092080;
loc_82092070:
	// lwz r11,2444(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2444);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,2444(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2444, ctx.r11.u32);
	// lbzu r11,1(r30)
	ea = 1 + ctx.r30.u32;
	ctx.r11.u64 = PPC_LOAD_U8(ea);
	ctx.r30.u32 = ea;
loc_82092080:
	// cmplwi cr6,r11,232
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 232, ctx.xer);
	// bne cr6,0x82092070
	if (!ctx.cr6.eq) goto loc_82092070;
	// lwz r9,2444(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2444);
	// addi r10,r30,1
	ctx.r10.s64 = ctx.r30.s64 + 1;
	// cmplw cr6,r9,r29
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r29.u32, ctx.xer);
	// bge cr6,0x8209210c
	if (!ctx.cr6.lt) goto loc_8209210C;
	// lbz r11,2(r10)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 2);
	// lbz r8,3(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 3);
	// lbz r6,1(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// rlwimi r11,r8,8,16,23
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r11.u64 & 0xFFFFFFFFFFFF00FF);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// rlwimi r6,r11,8,0,23
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFFFFFF00) | (ctx.r6.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r7,r6,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r6.u32, 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// add. r11,r9,r7
	ctx.r11.u64 = ctx.r9.u64 + ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt 0x820920f8
	if (ctx.cr0.lt) goto loc_820920F8;
	// lwz r8,2156(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2156);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x820920f8
	if (!ctx.cr6.lt) goto loc_820920F8;
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x820920dc
	if (ctx.cr6.lt) goto loc_820920DC;
	// subf r11,r8,r7
	ctx.r11.s64 = ctx.r7.s64 - ctx.r8.s64;
loc_820920DC:
	// rlwinm r8,r11,24,24,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 24) & 0xFF;
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r11.u8);
	// rlwinm r7,r11,16,24,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFF;
	// rlwinm r11,r11,8,24,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFF;
	// stb r8,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, ctx.r8.u8);
	// stb r7,2(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2, ctx.r7.u8);
	// stb r11,3(r10)
	PPC_STORE_U8(ctx.r10.u32 + 3, ctx.r11.u8);
loc_820920F8:
	// lwz r11,2444(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2444);
	// addi r30,r10,4
	ctx.r30.s64 = ctx.r10.s64 + 4;
	// addi r11,r11,5
	ctx.r11.s64 = ctx.r11.s64 + 5;
	// stw r11,2444(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2444, ctx.r11.u32);
	// b 0x82092068
	goto loc_82092068;
loc_8209210C:
	// addi r3,r27,-6
	ctx.r3.s64 = ctx.r27.s64 + -6;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r5,6
	ctx.r5.s64 = 6;
	// bl 0x8207dac0
	ctx.lr = 0x8209211C;
	sub_8207DAC0(ctx, base);
	// addi r11,r29,10
	ctx.r11.s64 = ctx.r29.s64 + 10;
loc_82092120:
	// stw r11,2444(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2444, ctx.r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8209212C"))) PPC_WEAK_FUNC(sub_8209212C);
PPC_FUNC_IMPL(__imp__sub_8209212C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82092130"))) PPC_WEAK_FUNC(sub_82092130);
PPC_FUNC_IMPL(__imp__sub_82092130) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82092138;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bgt cr6,0x82092158
	if (ctx.cr6.gt) goto loc_82092158;
loc_82092150:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82092210
	goto loc_82092210;
loc_82092158:
	// lwz r11,17184(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 17184);
	// lwz r29,2440(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2440);
	// add r3,r11,r28
	ctx.r3.u64 = ctx.r11.u64 + ctx.r28.u64;
	// cmpw cr6,r30,r29
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r29.s32, ctx.xer);
	// bgt cr6,0x82092198
	if (ctx.cr6.gt) goto loc_82092198;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r4,2436(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2436);
	// bl 0x8207dac0
	ctx.lr = 0x82092178;
	sub_8207DAC0(ctx, base);
	// lwz r11,2436(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2436);
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// stw r11,2436(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2436, ctx.r11.u32);
	// lwz r11,2440(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2440);
	// subf r11,r30,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r30.s64;
	// stw r11,2440(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2440, ctx.r11.u32);
	// b 0x820921cc
	goto loc_820921CC;
loc_82092198:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bgt cr6,0x820921a8
	if (ctx.cr6.gt) goto loc_820921A8;
	// li r29,0
	ctx.r29.s64 = 0;
	// b 0x820921d4
	goto loc_820921D4;
loc_820921A8:
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r4,2436(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2436);
	// bl 0x8207dac0
	ctx.lr = 0x820921B4;
	sub_8207DAC0(ctx, base);
	// lwz r11,2440(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2440);
	// lwz r10,2436(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2436);
	// li r9,0
	ctx.r9.s64 = 0;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r9,2440(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2440, ctx.r9.u32);
	// stw r11,2436(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2436, ctx.r11.u32);
loc_820921CC:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt cr6,0x82092150
	if (ctx.cr6.lt) goto loc_82092150;
loc_820921D4:
	// lwz r11,2156(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2156);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82092200
	if (ctx.cr6.eq) goto loc_82092200;
	// lwz r11,17196(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 17196);
	// cmplwi cr6,r11,32768
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32768, ctx.xer);
	// bge cr6,0x82092200
	if (!ctx.cr6.lt) goto loc_82092200;
	// lwz r11,17184(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 17184);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + ctx.r28.u64;
	// bl 0x82092008
	ctx.lr = 0x82092200;
	sub_82092008(ctx, base);
loc_82092200:
	// lwz r11,17196(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 17196);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,17196(r31)
	PPC_STORE_U32(ctx.r31.u32 + 17196, ctx.r11.u32);
loc_82092210:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82092218"))) PPC_WEAK_FUNC(sub_82092218);
PPC_FUNC_IMPL(__imp__sub_82092218) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x82092220;
	__savegprlr_25(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lhzx r10,r10,r4
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r4.u32);
	// rotlwi r8,r10,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lwzx r10,r8,r9
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// stwx r4,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r4.u32);
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// subf r9,r9,r4
	ctx.r9.s64 = ctx.r4.s64 - ctx.r9.s64;
	// addi r26,r9,4
	ctx.r26.s64 = ctx.r9.s64 + 4;
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r10,r26
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r26.u32, ctx.xer);
	// bgt cr6,0x82092270
	if (ctx.cr6.gt) goto loc_82092270;
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// li r25,0
	ctx.r25.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stwx r25,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r25.u32);
	// lwz r11,12(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// stwx r25,r11,r9
	PPC_STORE_U32(ctx.r11.u32 + ctx.r9.u32, ctx.r25.u32);
	// b 0x8209253c
	goto loc_8209253C;
loc_82092270:
	// subf r8,r10,r4
	ctx.r8.s64 = ctx.r4.s64 - ctx.r10.s64;
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r6,16(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r5,r8,2
	ctx.r5.s64 = ctx.r8.s64 + 2;
	// li r8,2
	ctx.r8.s64 = 2;
	// stw r5,80(r11)
	PPC_STORE_U32(ctx.r11.u32 + 80, ctx.r5.u32);
	// li r30,2
	ctx.r30.s64 = 2;
	// li r29,2
	ctx.r29.s64 = 2;
	// add r28,r9,r7
	ctx.r28.u64 = ctx.r9.u64 + ctx.r7.u64;
	// add r27,r6,r9
	ctx.r27.u64 = ctx.r6.u64 + ctx.r9.u64;
loc_8209229C:
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// add r7,r8,r4
	ctx.r7.u64 = ctx.r8.u64 + ctx.r4.u64;
	// add r9,r8,r10
	ctx.r9.u64 = ctx.r8.u64 + ctx.r10.u64;
	// li r25,0
	ctx.r25.s64 = 0;
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
	// lbzx r7,r5,r7
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r7.u32);
	// lbzx r5,r5,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r9.u32);
	// subf. r7,r7,r5
	ctx.r7.s64 = ctx.r5.s64 - ctx.r7.s64;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne 0x820922f4
	if (!ctx.cr0.eq) goto loc_820922F4;
	// subf r7,r10,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r10.s64;
	// subf r31,r8,r9
	ctx.r31.s64 = ctx.r9.s64 - ctx.r8.s64;
	// add r5,r7,r4
	ctx.r5.u64 = ctx.r7.u64 + ctx.r4.u64;
loc_820922CC:
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// cmpwi cr6,r6,257
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 257, ctx.xer);
	// bge cr6,0x8209230c
	if (!ctx.cr6.lt) goto loc_8209230C;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// add r7,r31,r9
	ctx.r7.u64 = ctx.r31.u64 + ctx.r9.u64;
	// lbzx r9,r5,r9
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r9.u32);
	// lbzx r7,r7,r6
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r6.u32);
	// subf. r7,r9,r7
	ctx.r7.s64 = ctx.r7.s64 - ctx.r9.s64;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq 0x820922cc
	if (ctx.cr0.eq) goto loc_820922CC;
loc_820922F4:
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bge cr6,0x82092360
	if (!ctx.cr6.lt) goto loc_82092360;
	// cmpw cr6,r6,r29
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r29.s32, ctx.xer);
	// ble cr6,0x8209234c
	if (!ctx.cr6.gt) goto loc_8209234C;
	// cmpw cr6,r6,r3
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r3.s32, ctx.xer);
	// ble cr6,0x82092338
	if (!ctx.cr6.gt) goto loc_82092338;
loc_8209230C:
	// addi r8,r3,18
	ctx.r8.s64 = ctx.r3.s64 + 18;
	// subf r9,r10,r4
	ctx.r9.s64 = ctx.r4.s64 - ctx.r10.s64;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r9,2
	ctx.r7.s64 = ctx.r9.s64 + 2;
	// add r9,r8,r11
	ctx.r9.u64 = ctx.r8.u64 + ctx.r11.u64;
loc_82092320:
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// stwu r7,4(r9)
	ea = 4 + ctx.r9.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r9.u32 = ea;
	// cmpw cr6,r3,r6
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r6.s32, ctx.xer);
	// blt cr6,0x82092320
	if (ctx.cr6.lt) goto loc_82092320;
	// cmpwi cr6,r6,50
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 50, ctx.xer);
	// bge cr6,0x82092540
	if (!ctx.cr6.lt) goto loc_82092540;
loc_82092338:
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// cmpw cr6,r30,r6
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r6.s32, ctx.xer);
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// blt cr6,0x8209234c
	if (ctx.cr6.lt) goto loc_8209234C;
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
loc_8209234C:
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r10,0(r27)
	PPC_STORE_U32(ctx.r27.u32 + 0, ctx.r10.u32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// add r27,r9,r10
	ctx.r27.u64 = ctx.r9.u64 + ctx.r10.u64;
	// b 0x820923c0
	goto loc_820923C0;
loc_82092360:
	// cmpw cr6,r6,r30
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r30.s32, ctx.xer);
	// ble cr6,0x820923b0
	if (!ctx.cr6.gt) goto loc_820923B0;
	// cmpw cr6,r6,r3
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r3.s32, ctx.xer);
	// ble cr6,0x8209239c
	if (!ctx.cr6.gt) goto loc_8209239C;
	// addi r8,r3,18
	ctx.r8.s64 = ctx.r3.s64 + 18;
	// subf r9,r10,r4
	ctx.r9.s64 = ctx.r4.s64 - ctx.r10.s64;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r9,2
	ctx.r7.s64 = ctx.r9.s64 + 2;
	// add r9,r8,r11
	ctx.r9.u64 = ctx.r8.u64 + ctx.r11.u64;
loc_82092384:
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// stwu r7,4(r9)
	ea = 4 + ctx.r9.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r9.u32 = ea;
	// cmpw cr6,r3,r6
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r6.s32, ctx.xer);
	// blt cr6,0x82092384
	if (ctx.cr6.lt) goto loc_82092384;
	// cmpwi cr6,r6,50
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 50, ctx.xer);
	// bge cr6,0x82092540
	if (!ctx.cr6.lt) goto loc_82092540;
loc_8209239C:
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// cmpw cr6,r6,r29
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r29.s32, ctx.xer);
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
	// blt cr6,0x820923b0
	if (ctx.cr6.lt) goto loc_820923B0;
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
loc_820923B0:
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r10,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r10.u32);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// add r28,r9,r10
	ctx.r28.u64 = ctx.r9.u64 + ctx.r10.u64;
loc_820923C0:
	// lwzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmplw cr6,r10,r26
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r26.u32, ctx.xer);
	// bgt cr6,0x8209229c
	if (ctx.cr6.gt) goto loc_8209229C;
	// stw r25,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r25.u32);
	// stw r25,0(r27)
	PPC_STORE_U32(ctx.r27.u32 + 0, ctx.r25.u32);
loc_820923D4:
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble cr6,0x82092414
	if (!ctx.cr6.gt) goto loc_82092414;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r7,60(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 60);
	// add r8,r9,r4
	ctx.r8.u64 = ctx.r9.u64 + ctx.r4.u64;
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// add r9,r9,r4
	ctx.r9.u64 = ctx.r9.u64 + ctx.r4.u64;
loc_820923F4:
	// lbz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// lbzx r6,r8,r10
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r10.u32);
	// cmplw cr6,r6,r7
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r7.u32, ctx.xer);
	// bne cr6,0x82092414
	if (!ctx.cr6.eq) goto loc_82092414;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpw cr6,r10,r3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r3.s32, ctx.xer);
	// blt cr6,0x820923f4
	if (ctx.cr6.lt) goto loc_820923F4;
loc_82092414:
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// blt cr6,0x82092444
	if (ctx.cr6.lt) goto loc_82092444;
	// addi r9,r10,19
	ctx.r9.s64 = ctx.r10.s64 + 19;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
loc_8209242C:
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stwu r25,-4(r9)
	ea = -4 + ctx.r9.u32;
	PPC_STORE_U32(ea, ctx.r25.u32);
	ctx.r9.u32 = ea;
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// bge cr6,0x8209242c
	if (!ctx.cr6.lt) goto loc_8209242C;
	// cmpwi cr6,r7,50
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 50, ctx.xer);
	// bgt cr6,0x82092514
	if (ctx.cr6.gt) goto loc_82092514;
loc_82092444:
	// mr r9,r25
	ctx.r9.u64 = ctx.r25.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble cr6,0x82092484
	if (!ctx.cr6.gt) goto loc_82092484;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r6,64(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// add r8,r10,r4
	ctx.r8.u64 = ctx.r10.u64 + ctx.r4.u64;
	// subf r10,r6,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r6.s64;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
loc_82092464:
	// lbz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// lbzx r5,r8,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// cmplw cr6,r5,r6
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r6.u32, ctx.xer);
	// bne cr6,0x82092484
	if (!ctx.cr6.eq) goto loc_82092484;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r9,r3
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r3.s32, ctx.xer);
	// blt cr6,0x82092464
	if (ctx.cr6.lt) goto loc_82092464;
loc_82092484:
	// cmpw cr6,r9,r7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, ctx.xer);
	// ble cr6,0x820924ac
	if (!ctx.cr6.gt) goto loc_820924AC;
	// addi r10,r7,18
	ctx.r10.s64 = ctx.r7.s64 + 18;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_82092498:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// li r8,1
	ctx.r8.s64 = 1;
	// cmpw cr6,r7,r9
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, ctx.xer);
	// stwu r8,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r10.u32 = ea;
	// blt cr6,0x82092498
	if (ctx.cr6.lt) goto loc_82092498;
loc_820924AC:
	// mr r9,r25
	ctx.r9.u64 = ctx.r25.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble cr6,0x820924ec
	if (!ctx.cr6.gt) goto loc_820924EC;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r6,68(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// add r8,r10,r4
	ctx.r8.u64 = ctx.r10.u64 + ctx.r4.u64;
	// subf r10,r6,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r6.s64;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
loc_820924CC:
	// lbz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// lbzx r5,r8,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// cmplw cr6,r5,r6
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r6.u32, ctx.xer);
	// bne cr6,0x820924ec
	if (!ctx.cr6.eq) goto loc_820924EC;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r9,r3
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r3.s32, ctx.xer);
	// blt cr6,0x820924cc
	if (ctx.cr6.lt) goto loc_820924CC;
loc_820924EC:
	// cmpw cr6,r9,r7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, ctx.xer);
	// ble cr6,0x82092514
	if (!ctx.cr6.gt) goto loc_82092514;
	// addi r10,r7,18
	ctx.r10.s64 = ctx.r7.s64 + 18;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_82092500:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// li r10,2
	ctx.r10.s64 = 2;
	// cmpw cr6,r7,r9
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, ctx.xer);
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// blt cr6,0x82092500
	if (ctx.cr6.lt) goto loc_82092500;
loc_82092514:
	// clrlwi r11,r4,17
	ctx.r11.u64 = ctx.r4.u32 & 0x7FFF;
	// subfic r11,r11,32767
	ctx.xer.ca = ctx.r11.u32 <= 32767;
	ctx.r11.s64 = 32767 - ctx.r11.s64;
	// cmpw cr6,r3,r11
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x8209253c
	if (!ctx.cr6.gt) goto loc_8209253C;
	// li r10,2
	ctx.r10.s64 = 2;
	// xoris r9,r10,32768
	ctx.r9.u64 = ctx.r10.u64 ^ 2147483648;
	// subf r10,r10,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r10.s64;
	// addc r10,r10,r9
	{ uint8_t _ca = ctx.r10.u32 + ctx.r9.u32 < ctx.r10.u32; // FIX 2026-07-24: insn was silently dropped by the recompiler
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	ctx.xer.ca = _ca; }
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 & ctx.r11.u64;
loc_8209253C:
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
loc_82092540:
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r9
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// stw r9,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r9.u32);
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// stw r10,0(r27)
	PPC_STORE_U32(ctx.r27.u32 + 0, ctx.r10.u32);
	// b 0x820923d4
	goto loc_820923D4;
}

__attribute__((alias("__imp__sub_82092560"))) PPC_WEAK_FUNC(sub_82092560);
PPC_FUNC_IMPL(__imp__sub_82092560) {
	PPC_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82092568;
	__savegprlr_27(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lhzx r10,r10,r4
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r4.u32);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lwzx r10,r9,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// stwx r4,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + ctx.r11.u32, ctx.r4.u32);
	// cmplw cr6,r10,r5
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r5.u32, ctx.xer);
	// bgt cr6,0x820925a4
	if (ctx.cr6.gt) goto loc_820925A4;
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// li r11,0
	ctx.r11.s64 = 0;
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r11.u32);
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r11.u32);
	// b 0x82092698
	goto loc_82092698;
loc_820925A4:
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// rlwinm r11,r4,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,16(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// li r7,2
	ctx.r7.s64 = 2;
	// li r29,2
	ctx.r29.s64 = 2;
	// li r28,2
	ctx.r28.s64 = 2;
	// add r31,r11,r9
	ctx.r31.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r30,r8,r11
	ctx.r30.u64 = ctx.r8.u64 + ctx.r11.u64;
loc_820925C4:
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// add r9,r7,r10
	ctx.r9.u64 = ctx.r7.u64 + ctx.r10.u64;
	// add r6,r7,r4
	ctx.r6.u64 = ctx.r7.u64 + ctx.r4.u64;
	// add r8,r11,r9
	ctx.r8.u64 = ctx.r11.u64 + ctx.r9.u64;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// lbzx r11,r11,r6
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r6.u32);
	// lbz r6,0(r8)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// subf. r11,r11,r6
	ctx.r11.s64 = ctx.r6.s64 - ctx.r11.s64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8209260c
	if (!ctx.cr0.eq) goto loc_8209260C;
	// subf r6,r10,r4
	ctx.r6.s64 = ctx.r4.s64 - ctx.r10.s64;
loc_820925EC:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmpwi cr6,r9,50
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 50, ctx.xer);
	// bge cr6,0x8209260c
	if (!ctx.cr6.lt) goto loc_8209260C;
	// lbzx r11,r6,r8
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r8.u32);
	// lbz r27,0(r8)
	ctx.r27.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// subf. r11,r11,r27
	ctx.r11.s64 = ctx.r27.s64 - ctx.r11.s64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820925ec
	if (ctx.cr0.eq) goto loc_820925EC;
loc_8209260C:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x8209264c
	if (!ctx.cr6.lt) goto loc_8209264C;
	// cmpw cr6,r9,r28
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r28.s32, ctx.xer);
	// ble cr6,0x82092638
	if (!ctx.cr6.gt) goto loc_82092638;
	// cmpwi cr6,r9,50
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 50, ctx.xer);
	// bge cr6,0x8209269c
	if (!ctx.cr6.lt) goto loc_8209269C;
	// mr r28,r9
	ctx.r28.u64 = ctx.r9.u64;
	// cmpw cr6,r29,r9
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r9.s32, ctx.xer);
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// blt cr6,0x82092638
	if (ctx.cr6.lt) goto loc_82092638;
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
loc_82092638:
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r10,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// add r30,r11,r10
	ctx.r30.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x82092680
	goto loc_82092680;
loc_8209264C:
	// cmpw cr6,r9,r29
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r29.s32, ctx.xer);
	// ble cr6,0x82092670
	if (!ctx.cr6.gt) goto loc_82092670;
	// cmpwi cr6,r9,50
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 50, ctx.xer);
	// bge cr6,0x8209269c
	if (!ctx.cr6.lt) goto loc_8209269C;
	// mr r29,r9
	ctx.r29.u64 = ctx.r9.u64;
	// cmpw cr6,r9,r28
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r28.s32, ctx.xer);
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// blt cr6,0x82092670
	if (ctx.cr6.lt) goto loc_82092670;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
loc_82092670:
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// add r31,r11,r10
	ctx.r31.u64 = ctx.r11.u64 + ctx.r10.u64;
loc_82092680:
	// lwzx r10,r11,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// cmplw cr6,r10,r5
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r5.u32, ctx.xer);
	// bgt cr6,0x820925c4
	if (ctx.cr6.gt) goto loc_820925C4;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_82092694:
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
loc_82092698:
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_8209269C:
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r10,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lwz r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwzx r11,r11,r10
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// b 0x82092694
	goto loc_82092694;
}

__attribute__((alias("__imp__sub_820926B8"))) PPC_WEAK_FUNC(sub_820926B8);
PPC_FUNC_IMPL(__imp__sub_820926B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lhzx r10,r10,r4
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r4.u32);
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mr r6,r11
	ctx.r6.u64 = ctx.r11.u64;
	// cmplw cr6,r10,r5
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r5.u32, ctx.xer);
	// rlwinm r11,r4,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// li r8,0
	ctx.r8.s64 = 0;
	// bgt cr6,0x82092708
	if (ctx.cr6.gt) goto loc_82092708;
	// stw r8,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r8.u32);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stwx r8,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + ctx.r11.u32, ctx.r8.u32);
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// stwx r8,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + ctx.r11.u32, ctx.r8.u32);
	// blr 
	return;
loc_82092708:
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// cmplw cr6,r9,r5
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r5.u32, ctx.xer);
	// bgt cr6,0x82092720
	if (ctx.cr6.gt) goto loc_82092720;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// stwx r8,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + ctx.r11.u32, ctx.r8.u32);
loc_82092720:
	// lwz r7,16(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwzx r10,r7,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r11.u32);
	// cmplw cr6,r10,r5
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r5.u32, ctx.xer);
	// bgt cr6,0x82092738
	if (ctx.cr6.gt) goto loc_82092738;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// stwx r8,r7,r11
	PPC_STORE_U32(ctx.r7.u32 + ctx.r11.u32, ctx.r8.u32);
loc_82092738:
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8209276c
	if (!ctx.cr6.gt) goto loc_8209276C;
	// subfc r11,r9,r5
	ctx.xer.ca = ctx.r5.u32 >= ctx.r9.u32;
	ctx.r11.s64 = ctx.r5.s64 - ctx.r9.s64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 & ctx.r9.u64;
	// stw r11,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r11.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r11,r9
	ctx.r6.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwzx r9,r11,r9
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r9.u32);
	// b 0x82092738
	goto loc_82092738;
loc_8209276C:
	// subfc r11,r10,r5
	ctx.xer.ca = ctx.r5.u32 >= ctx.r10.u32;
	ctx.r11.s64 = ctx.r5.s64 - ctx.r10.s64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 & ctx.r10.u64;
	// stw r11,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r11.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwzx r10,r11,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// b 0x82092738
	goto loc_82092738;
}

__attribute__((alias("__imp__sub_82092798"))) PPC_WEAK_FUNC(sub_82092798);
PPC_FUNC_IMPL(__imp__sub_82092798) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c974
	ctx.lr = 0x820927A0;
	__savegprlr_23(ctx, base);
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// li r5,96
	ctx.r5.s64 = 96;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// mr r25,r6
	ctx.r25.u64 = ctx.r6.u64;
	// bl 0x8207da20
	ctx.lr = 0x820927C4;
	sub_8207DA20(ctx, base);
	// li r9,123
	ctx.r9.s64 = 123;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lbzx r23,r29,r25
	ctx.r23.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r25.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stbx r9,r29,r25
	PPC_STORE_U8(ctx.r29.u32 + ctx.r25.u32, ctx.r9.u8);
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// addi r26,r10,12344
	ctx.r26.s64 = ctx.r10.s64 + 12344;
	// ble cr6,0x820928d4
	if (!ctx.cr6.gt) goto loc_820928D4;
loc_820927E4:
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// lbzx r9,r11,r29
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r29.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + ctx.r29.u64;
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x820928a0
	if (!ctx.cr6.eq) goto loc_820928A0;
loc_82092800:
	// lbzu r8,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82092800
	if (ctx.cr6.eq) goto loc_82092800;
	// cmpwi cr6,r7,4
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 4, ctx.xer);
	// blt cr6,0x820928a0
	if (ctx.cr6.lt) goto loc_820928A0;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82092854
	if (!ctx.cr6.eq) goto loc_82092854;
	// cmpwi cr6,r7,51
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 51, ctx.xer);
	// ble cr6,0x8209282c
	if (!ctx.cr6.gt) goto loc_8209282C;
	// li r7,51
	ctx.r7.s64 = 51;
loc_8209282C:
	// cmpwi cr6,r7,19
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 19, ctx.xer);
	// bgt cr6,0x82092844
	if (ctx.cr6.gt) goto loc_82092844;
	// lhz r10,146(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 146);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sth r10,146(r1)
	PPC_STORE_U16(ctx.r1.u32 + 146, ctx.r10.u16);
	// b 0x82092894
	goto loc_82092894;
loc_82092844:
	// lhz r10,148(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 148);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sth r10,148(r1)
	PPC_STORE_U16(ctx.r1.u32 + 148, ctx.r10.u16);
	// b 0x82092894
	goto loc_82092894;
loc_82092854:
	// cmpwi cr6,r7,5
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 5, ctx.xer);
	// ble cr6,0x82092860
	if (!ctx.cr6.gt) goto loc_82092860;
	// li r7,5
	ctx.r7.s64 = 5;
loc_82092860:
	// lbzx r10,r11,r27
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r27.u32);
	// addi r8,r26,17
	ctx.r8.s64 = ctx.r26.s64 + 17;
	// lbzx r6,r11,r29
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r29.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// subf r10,r6,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r6.s64;
	// lbzx r10,r10,r8
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// rotlwi r10,r10,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// lhzx r8,r10,r9
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r9.u32);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// sthx r8,r10,r9
	PPC_STORE_U16(ctx.r10.u32 + ctx.r9.u32, ctx.r8.u16);
	// lhz r10,150(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 150);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sth r10,150(r1)
	PPC_STORE_U16(ctx.r1.u32 + 150, ctx.r10.u16);
loc_82092894:
	// add r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 + ctx.r11.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// b 0x820928c8
	goto loc_820928C8;
loc_820928A0:
	// lbzx r10,r11,r27
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r27.u32);
	// addi r8,r26,17
	ctx.r8.s64 = ctx.r26.s64 + 17;
	// lbzx r7,r11,r29
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r29.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// subf r10,r7,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r7.s64;
	// lbzx r10,r10,r8
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// rotlwi r10,r10,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// lhzx r8,r10,r9
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r9.u32);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// sthx r8,r10,r9
	PPC_STORE_U16(ctx.r10.u32 + ctx.r9.u32, ctx.r8.u16);
loc_820928C8:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmpw cr6,r11,r25
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r25.s32, ctx.xer);
	// blt cr6,0x820927e4
	if (ctx.cr6.lt) goto loc_820927E4;
loc_820928D4:
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r7,r1,208
	ctx.r7.s64 = ctx.r1.s64 + 208;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// li r4,20
	ctx.r4.s64 = 20;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x82094cd0
	ctx.lr = 0x820928F0;
	sub_82094CD0(ctx, base);
	// li r31,0
	ctx.r31.s64 = 0;
loc_820928F4:
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// lbzx r11,r31,r11
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + ctx.r11.u32);
	// extsb r5,r11
	ctx.r5.s64 = ctx.r11.s8;
	// bl 0x82091f58
	ctx.lr = 0x8209290C;
	sub_82091F58(ctx, base);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmpwi cr6,r31,20
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 20, ctx.xer);
	// blt cr6,0x820928f4
	if (ctx.cr6.lt) goto loc_820928F4;
	// li r31,0
	ctx.r31.s64 = 0;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// ble cr6,0x82092a58
	if (!ctx.cr6.gt) goto loc_82092A58;
loc_82092924:
	// addi r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 1;
	// li r30,0
	ctx.r30.s64 = 0;
	// add r10,r11,r29
	ctx.r10.u64 = ctx.r11.u64 + ctx.r29.u64;
	// lbzx r11,r31,r29
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + ctx.r29.u32);
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82092998
	if (!ctx.cr6.eq) goto loc_82092998;
loc_82092940:
	// lbzu r9,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r9.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82092940
	if (ctx.cr6.eq) goto loc_82092940;
	// cmpwi cr6,r30,4
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 4, ctx.xer);
	// blt cr6,0x82092998
	if (ctx.cr6.lt) goto loc_82092998;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82092984
	if (!ctx.cr6.eq) goto loc_82092984;
	// cmpwi cr6,r30,51
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 51, ctx.xer);
	// ble cr6,0x8209296c
	if (!ctx.cr6.gt) goto loc_8209296C;
	// li r30,51
	ctx.r30.s64 = 51;
loc_8209296C:
	// cmpwi cr6,r30,19
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 19, ctx.xer);
	// bgt cr6,0x8209297c
	if (ctx.cr6.gt) goto loc_8209297C;
	// li r11,17
	ctx.r11.s64 = 17;
	// b 0x820929a8
	goto loc_820929A8;
loc_8209297C:
	// li r11,18
	ctx.r11.s64 = 18;
	// b 0x820929a8
	goto loc_820929A8;
loc_82092984:
	// cmpwi cr6,r30,5
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 5, ctx.xer);
	// ble cr6,0x82092990
	if (!ctx.cr6.gt) goto loc_82092990;
	// li r30,5
	ctx.r30.s64 = 5;
loc_82092990:
	// li r11,19
	ctx.r11.s64 = 19;
	// b 0x820929a8
	goto loc_820929A8;
loc_82092998:
	// lbzx r10,r31,r27
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + ctx.r27.u32);
	// addi r9,r26,17
	ctx.r9.s64 = ctx.r26.s64 + 17;
	// subf r11,r11,r10
	ctx.r11.s64 = ctx.r10.s64 - ctx.r11.s64;
	// lbzx r11,r11,r9
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r9.u32);
loc_820929A8:
	// extsb r28,r11
	ctx.r28.s64 = ctx.r11.s8;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// rlwinm r10,r28,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r9,r1,208
	ctx.r9.s64 = ctx.r1.s64 + 208;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// lbzx r11,r28,r11
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + ctx.r11.u32);
	// extsb r4,r11
	ctx.r4.s64 = ctx.r11.s8;
	// lhzx r5,r10,r9
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x82091f58
	ctx.lr = 0x820929CC;
	sub_82091F58(ctx, base);
	// cmpwi cr6,r28,17
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 17, ctx.xer);
	// bne cr6,0x820929e0
	if (!ctx.cr6.eq) goto loc_820929E0;
	// addi r5,r30,-4
	ctx.r5.s64 = ctx.r30.s64 + -4;
	// li r4,4
	ctx.r4.s64 = 4;
	// b 0x82092a3c
	goto loc_82092A3C;
loc_820929E0:
	// cmpwi cr6,r28,18
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 18, ctx.xer);
	// bne cr6,0x820929f4
	if (!ctx.cr6.eq) goto loc_820929F4;
	// addi r5,r30,-20
	ctx.r5.s64 = ctx.r30.s64 + -20;
	// li r4,5
	ctx.r4.s64 = 5;
	// b 0x82092a3c
	goto loc_82092A3C;
loc_820929F4:
	// cmpwi cr6,r28,19
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 19, ctx.xer);
	// bne cr6,0x82092a4c
	if (!ctx.cr6.eq) goto loc_82092A4C;
	// addi r5,r30,-4
	ctx.r5.s64 = ctx.r30.s64 + -4;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x82091f58
	ctx.lr = 0x82092A0C;
	sub_82091F58(ctx, base);
	// lbzx r8,r31,r27
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + ctx.r27.u32);
	// lbzx r7,r31,r29
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r31.u32 + ctx.r29.u32);
	// addi r11,r26,17
	ctx.r11.s64 = ctx.r26.s64 + 17;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// subf r8,r7,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r7.s64;
	// addi r9,r1,208
	ctx.r9.s64 = ctx.r1.s64 + 208;
	// lbzx r11,r8,r11
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r11.u32);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lbzx r11,r11,r10
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r10.u32);
	// lhzx r5,r8,r9
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r8.u32 + ctx.r9.u32);
	// extsb r4,r11
	ctx.r4.s64 = ctx.r11.s8;
loc_82092A3C:
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x82091f58
	ctx.lr = 0x82092A44;
	sub_82091F58(ctx, base);
	// add r11,r30,r31
	ctx.r11.u64 = ctx.r30.u64 + ctx.r31.u64;
	// addi r31,r11,-1
	ctx.r31.s64 = ctx.r11.s64 + -1;
loc_82092A4C:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmpw cr6,r31,r25
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r25.s32, ctx.xer);
	// blt cr6,0x82092924
	if (ctx.cr6.lt) goto loc_82092924;
loc_82092A58:
	// stbx r23,r29,r25
	PPC_STORE_U8(ctx.r29.u32 + ctx.r25.u32, ctx.r23.u8);
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8207dac0
	ctx.lr = 0x82092A6C;
	sub_8207DAC0(ctx, base);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82092A74"))) PPC_WEAK_FUNC(sub_82092A74);
PPC_FUNC_IMPL(__imp__sub_82092A74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82092A78"))) PPC_WEAK_FUNC(sub_82092A78);
PPC_FUNC_IMPL(__imp__sub_82092A78) {
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
	// lwz r11,2152(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2152);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// addi r7,r3,13272
	ctx.r7.s64 = ctx.r3.s64 + 13272;
	// addi r6,r3,9520
	ctx.r6.s64 = ctx.r3.s64 + 9520;
	// addi r5,r3,10472
	ctx.r5.s64 = ctx.r3.s64 + 10472;
	// rlwinm r4,r11,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82094cd0
	ctx.lr = 0x82092AB4;
	sub_82094CD0(ctx, base);
	// addi r7,r31,16370
	ctx.r7.s64 = ctx.r31.s64 + 16370;
	// addi r6,r31,10221
	ctx.r6.s64 = ctx.r31.s64 + 10221;
	// addi r5,r31,15374
	ctx.r5.s64 = ctx.r31.s64 + 15374;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// li r4,249
	ctx.r4.s64 = 249;
	// bl 0x82094cd0
	ctx.lr = 0x82092AD0;
	sub_82094CD0(ctx, base);
	// addi r7,r31,17150
	ctx.r7.s64 = ctx.r31.s64 + 17150;
	// addi r6,r31,17166
	ctx.r6.s64 = ctx.r31.s64 + 17166;
	// addi r5,r31,17118
	ctx.r5.s64 = ctx.r31.s64 + 17118;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82094cd0
	ctx.lr = 0x82092AEC;
	sub_82094CD0(ctx, base);
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

__attribute__((alias("__imp__sub_82092B04"))) PPC_WEAK_FUNC(sub_82092B04);
PPC_FUNC_IMPL(__imp__sub_82092B04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82092B08"))) PPC_WEAK_FUNC(sub_82092B08);
PPC_FUNC_IMPL(__imp__sub_82092B08) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lbz r11,1364(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1364);
	// lwz r10,2152(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2152);
	// addi r11,r11,18
	ctx.r11.s64 = ctx.r11.s64 + 18;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// addi r10,r11,1221
	ctx.r10.s64 = ctx.r11.s64 + 1221;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
loc_82092B28:
	// li r9,100
	ctx.r9.s64 = 100;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stbu r9,8(r10)
	ea = 8 + ctx.r10.u32;
	PPC_STORE_U8(ea, ctx.r9.u8);
	ctx.r10.u32 = ea;
	// lwz r9,2152(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2152);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x82092b28
	if (ctx.cr6.lt) goto loc_82092B28;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82092B44"))) PPC_WEAK_FUNC(sub_82092B44);
PPC_FUNC_IMPL(__imp__sub_82092B44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82092B48"))) PPC_WEAK_FUNC(sub_82092B48);
PPC_FUNC_IMPL(__imp__sub_82092B48) {
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
	// addi r5,r3,14672
	ctx.r5.s64 = ctx.r3.s64 + 14672;
	// addi r4,r3,9520
	ctx.r4.s64 = ctx.r3.s64 + 9520;
	// li r6,256
	ctx.r6.s64 = 256;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82092798
	ctx.lr = 0x82092B6C;
	sub_82092798(ctx, base);
	// lwz r11,2152(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2152);
	// addi r5,r31,14928
	ctx.r5.s64 = ctx.r31.s64 + 14928;
	// addi r4,r31,9776
	ctx.r4.s64 = ctx.r31.s64 + 9776;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rlwinm r6,r11,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x82092798
	ctx.lr = 0x82092B84;
	sub_82092798(ctx, base);
	// addi r5,r31,16868
	ctx.r5.s64 = ctx.r31.s64 + 16868;
	// addi r4,r31,10221
	ctx.r4.s64 = ctx.r31.s64 + 10221;
	// li r6,249
	ctx.r6.s64 = 249;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82092798
	ctx.lr = 0x82092B98;
	sub_82092798(ctx, base);
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

__attribute__((alias("__imp__sub_82092BAC"))) PPC_WEAK_FUNC(sub_82092BAC);
PPC_FUNC_IMPL(__imp__sub_82092BAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82092BB0"))) PPC_WEAK_FUNC(sub_82092BB0);
PPC_FUNC_IMPL(__imp__sub_82092BB0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82092BB8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r29,r3,17166
	ctx.r29.s64 = ctx.r3.s64 + 17166;
	// addi r7,r3,17150
	ctx.r7.s64 = ctx.r3.s64 + 17150;
	// addi r5,r3,17118
	ctx.r5.s64 = ctx.r3.s64 + 17118;
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82094cd0
	ctx.lr = 0x82092BDC;
	sub_82094CD0(ctx, base);
	// li r30,0
	ctx.r30.s64 = 0;
loc_82092BE0:
	// li r4,3
	ctx.r4.s64 = 3;
	// lbzx r5,r29,r30
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82091f58
	ctx.lr = 0x82092BF0;
	sub_82091F58(ctx, base);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmpwi cr6,r30,8
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 8, ctx.xer);
	// blt cr6,0x82092be0
	if (ctx.cr6.lt) goto loc_82092BE0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82092C04"))) PPC_WEAK_FUNC(sub_82092C04);
PPC_FUNC_IMPL(__imp__sub_82092C04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82092C08"))) PPC_WEAK_FUNC(sub_82092C08);
PPC_FUNC_IMPL(__imp__sub_82092C08) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r10,256
	ctx.r10.s64 = 256;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r9,r3,9520
	ctx.r9.s64 = ctx.r3.s64 + 9520;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82092C18:
	// lbzx r10,r9,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r11.u32);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x82092c2c
	if (!ctx.cr0.eq) goto loc_82092C2C;
	// li r10,11
	ctx.r10.s64 = 11;
	// stbx r10,r9,r11
	PPC_STORE_U8(ctx.r9.u32 + ctx.r11.u32, ctx.r10.u8);
loc_82092C2C:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bdnz 0x82092c18
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82092C18;
	// b 0x82092c50
	goto loc_82092C50;
loc_82092C38:
	// lbzx r10,r9,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r11.u32);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x82092c4c
	if (!ctx.cr0.eq) goto loc_82092C4C;
	// li r10,12
	ctx.r10.s64 = 12;
	// stbx r10,r9,r11
	PPC_STORE_U8(ctx.r9.u32 + ctx.r11.u32, ctx.r10.u8);
loc_82092C4C:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_82092C50:
	// lwz r10,2152(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2152);
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82092c38
	if (ctx.cr6.lt) goto loc_82092C38;
	// li r10,249
	ctx.r10.s64 = 249;
	// addi r11,r3,10221
	ctx.r11.s64 = ctx.r3.s64 + 10221;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82092C70:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x82092c84
	if (!ctx.cr0.eq) goto loc_82092C84;
	// li r10,8
	ctx.r10.s64 = 8;
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
loc_82092C84:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bdnz 0x82092c70
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82092C70;
	// lbz r11,1364(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1364);
	// lwz r10,2152(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2152);
	// addi r11,r11,18
	ctx.r11.s64 = ctx.r11.s64 + 18;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// addi r10,r11,1221
	ctx.r10.s64 = ctx.r11.s64 + 1221;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
loc_82092CAC:
	// li r9,100
	ctx.r9.s64 = 100;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stbu r9,8(r10)
	ea = 8 + ctx.r10.u32;
	PPC_STORE_U8(ea, ctx.r9.u8);
	ctx.r10.u32 = ea;
	// lwz r9,2152(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2152);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x82092cac
	if (ctx.cr6.lt) goto loc_82092CAC;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82092CC8"))) PPC_WEAK_FUNC(sub_82092CC8);
PPC_FUNC_IMPL(__imp__sub_82092CC8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r10,0
	ctx.r10.s64 = 0;
	// li r8,3
	ctx.r8.s64 = 3;
	// li r11,2
	ctx.r11.s64 = 2;
	// stb r10,1108(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1108, ctx.r10.u8);
	// li r9,1
	ctx.r9.s64 = 1;
	// stb r8,1111(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1111, ctx.r8.u8);
	// stb r11,1110(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1110, ctx.r11.u8);
	// li r8,4
	ctx.r8.s64 = 4;
	// stb r9,1109(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1109, ctx.r9.u8);
	// li r10,4
	ctx.r10.s64 = 4;
loc_82092CF0:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82092d1c
	if (!ctx.cr6.gt) goto loc_82092D1C;
	// add r9,r10,r3
	ctx.r9.u64 = ctx.r10.u64 + ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// addi r9,r9,1108
	ctx.r9.s64 = ctx.r9.s64 + 1108;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// beq 0x82092d18
	if (ctx.cr0.eq) goto loc_82092D18;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_82092D10:
	// stbu r8,1(r9)
	ea = 1 + ctx.r9.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x82092d10
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82092D10;
loc_82092D18:
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_82092D1C:
	// clrlwi r9,r8,24
	ctx.r9.u64 = ctx.r8.u32 & 0xFF;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// ble cr6,0x82092d54
	if (!ctx.cr6.gt) goto loc_82092D54;
	// add r9,r10,r3
	ctx.r9.u64 = ctx.r10.u64 + ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// addi r9,r9,1108
	ctx.r9.s64 = ctx.r9.s64 + 1108;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// beq 0x82092d50
	if (ctx.cr0.eq) goto loc_82092D50;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_82092D48:
	// stbu r8,1(r9)
	ea = 1 + ctx.r9.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x82092d48
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82092D48;
loc_82092D50:
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_82092D54:
	// clrlwi r9,r8,24
	ctx.r9.u64 = ctx.r8.u32 & 0xFF;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpwi cr6,r10,1024
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1024, ctx.xer);
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// blt cr6,0x82092cf0
	if (ctx.cr6.lt) goto loc_82092CF0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82092D70"))) PPC_WEAK_FUNC(sub_82092D70);
PPC_FUNC_IMPL(__imp__sub_82092D70) {
	PPC_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r8,r3,2162
	ctx.r8.s64 = ctx.r3.s64 + 2162;
loc_82092D78:
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82092da4
	if (ctx.cr6.eq) goto loc_82092DA4;
loc_82092D88:
	// clrlwi. r7,r9,31
	ctx.r7.u64 = ctx.r9.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq 0x82092d9c
	if (ctx.cr0.eq) goto loc_82092D9C;
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
loc_82092D9C:
	// srawi. r9,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x82092d88
	if (!ctx.cr0.eq) goto loc_82092D88;
loc_82092DA4:
	// stbx r10,r8,r11
	PPC_STORE_U8(ctx.r8.u32 + ctx.r11.u32, ctx.r10.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r11,256
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 256, ctx.xer);
	// blt cr6,0x82092d78
	if (ctx.cr6.lt) goto loc_82092D78;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82092DB8"))) PPC_WEAK_FUNC(sub_82092DB8);
PPC_FUNC_IMPL(__imp__sub_82092DB8) {
	PPC_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,11968(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11968, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82092DC4"))) PPC_WEAK_FUNC(sub_82092DC4);
PPC_FUNC_IMPL(__imp__sub_82092DC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82092DC8"))) PPC_WEAK_FUNC(sub_82092DC8);
PPC_FUNC_IMPL(__imp__sub_82092DC8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82092DD0;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// cmpwi cr6,r5,6
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 6, ctx.xer);
	// bgt cr6,0x82092df8
	if (ctx.cr6.gt) goto loc_82092DF8;
	// lwz r11,11968(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11968);
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// stw r11,11968(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11968, ctx.r11.u32);
	// b 0x82092f54
	goto loc_82092F54;
loc_82092DF8:
	// add r27,r31,r30
	ctx.r27.u64 = ctx.r31.u64 + ctx.r30.u64;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r29,r27,-6
	ctx.r29.s64 = ctx.r27.s64 + -6;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x8207dac0
	ctx.lr = 0x82092E10;
	sub_8207DAC0(ctx, base);
	// li r5,6
	ctx.r5.s64 = 6;
	// li r4,232
	ctx.r4.s64 = 232;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8207da20
	ctx.lr = 0x82092E20;
	sub_8207DA20(ctx, base);
	// lwz r11,11968(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 11968);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r7,r11,-10
	ctx.r7.s64 = ctx.r11.s64 + -10;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// addi r6,r11,12384
	ctx.r6.s64 = ctx.r11.s64 + 12384;
loc_82092E34:
	// addi r11,r31,15
	ctx.r11.s64 = ctx.r31.s64 + 15;
	// li r10,0
	ctx.r10.s64 = 0;
	// rlwinm r9,r11,0,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF0;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// cmplw cr6,r31,r9
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x82092e68
	if (!ctx.cr6.lt) goto loc_82092E68;
loc_82092E4C:
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi cr6,r8,232
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 232, ctx.xer);
	// beq cr6,0x82092e68
	if (ctx.cr6.eq) goto loc_82092E68;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x82092e4c
	if (ctx.cr6.lt) goto loc_82092E4C;
loc_82092E68:
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x82092e8c
	if (!ctx.cr6.eq) goto loc_82092E8C;
	// lvx128 v0,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82092e80
	goto loc_82092E80;
loc_82092E78:
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
loc_82092E80:
	// lvx128 v13,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpequb. v13,v13,v0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_cmpeq_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	ctx.cr6.setFromMask(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), 0xFFFF);
	// beq cr6,0x82092e78
	if (ctx.cr6.eq) goto loc_82092E78;
loc_82092E8C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// b 0x82092e9c
	goto loc_82092E9C;
loc_82092E94:
	// lbzu r9,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r9.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_82092E9C:
	// cmplwi cr6,r9,232
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 232, ctx.xer);
	// bne cr6,0x82092e94
	if (!ctx.cr6.eq) goto loc_82092E94;
	// lwz r9,11968(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 11968);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r10,11968(r28)
	PPC_STORE_U32(ctx.r28.u32 + 11968, ctx.r10.u32);
	// cmplw cr6,r10,r7
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x82092f3c
	if (!ctx.cr6.lt) goto loc_82092F3C;
	// lbz r9,3(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 3);
	// lbz r8,2(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 2);
	// rotlwi r9,r9,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// lbz r5,1(r11)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// lbz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// or r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 | ctx.r8.u64;
	// lwz r8,11964(r28)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r28.u32 + 11964);
	// rlwinm r9,r9,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// or r9,r9,r5
	ctx.r9.u64 = ctx.r9.u64 | ctx.r5.u64;
	// rlwinm r9,r9,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// or r9,r9,r4
	ctx.r9.u64 = ctx.r9.u64 | ctx.r4.u64;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x82092f00
	if (!ctx.cr6.lt) goto loc_82092F00;
	// subf r9,r10,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r10.s64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// stb r8,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r8.u8);
	// b 0x82092f14
	goto loc_82092F14;
loc_82092F00:
	// neg r5,r9
	ctx.r5.s64 = -ctx.r9.s64;
	// cmplw cr6,r5,r10
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x82092f2c
	if (ctx.cr6.gt) goto loc_82092F2C;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stb r9,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r9.u8);
loc_82092F14:
	// rlwinm r5,r9,24,24,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 24) & 0xFF;
	// rlwinm r4,r9,16,24,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFF;
	// rlwinm r9,r9,8,24,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFF;
	// stb r5,1(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1, ctx.r5.u8);
	// stb r4,2(r11)
	PPC_STORE_U8(ctx.r11.u32 + 2, ctx.r4.u8);
	// stb r9,3(r11)
	PPC_STORE_U8(ctx.r11.u32 + 3, ctx.r9.u8);
loc_82092F2C:
	// addi r10,r10,5
	ctx.r10.s64 = ctx.r10.s64 + 5;
	// addi r31,r11,4
	ctx.r31.s64 = ctx.r11.s64 + 4;
	// stw r10,11968(r28)
	PPC_STORE_U32(ctx.r28.u32 + 11968, ctx.r10.u32);
	// b 0x82092e34
	goto loc_82092E34;
loc_82092F3C:
	// addi r11,r7,10
	ctx.r11.s64 = ctx.r7.s64 + 10;
	// li r5,6
	ctx.r5.s64 = 6;
	// stw r11,11968(r28)
	PPC_STORE_U32(ctx.r28.u32 + 11968, ctx.r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r27,-6
	ctx.r3.s64 = ctx.r27.s64 + -6;
	// bl 0x8207dac0
	ctx.lr = 0x82092F54;
	sub_8207DAC0(ctx, base);
loc_82092F54:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82092F5C"))) PPC_WEAK_FUNC(sub_82092F5C);
PPC_FUNC_IMPL(__imp__sub_82092F5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82092F60"))) PPC_WEAK_FUNC(sub_82092F60);
PPC_FUNC_IMPL(__imp__sub_82092F60) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x82092F68;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r27,0
	ctx.r27.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r28,r27
	ctx.r28.u64 = ctx.r27.u64;
	// b 0x82093190
	goto loc_82093190;
loc_82092F80:
	// lwz r11,11988(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 11988);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82093160
	if (!ctx.cr6.eq) goto loc_82093160;
	// lbz r11,11958(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11958);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82092fe0
	if (ctx.cr0.eq) goto loc_82092FE0;
	// stb r27,11958(r31)
	PPC_STORE_U8(ctx.r31.u32 + 11958, ctx.r27.u8);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82093308
	ctx.lr = 0x82092FA8;
	sub_82093308(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82092fdc
	if (ctx.cr0.eq) goto loc_82092FDC;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82093308
	ctx.lr = 0x82092FBC;
	sub_82093308(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82093308
	ctx.lr = 0x82092FCC;
	sub_82093308(ctx, base);
	// rlwinm r11,r30,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 16) & 0xFFFF0000;
	// or r11,r3,r11
	ctx.r11.u64 = ctx.r3.u64 | ctx.r11.u64;
	// stw r11,11964(r31)
	PPC_STORE_U32(ctx.r31.u32 + 11964, ctx.r11.u32);
	// b 0x82092fe0
	goto loc_82092FE0;
loc_82092FDC:
	// stw r27,11964(r31)
	PPC_STORE_U32(ctx.r31.u32 + 11964, ctx.r27.u32);
loc_82092FE0:
	// lwz r11,11984(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 11984);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x82092ff8
	if (!ctx.cr6.eq) goto loc_82092FF8;
	// stw r27,11984(r31)
	PPC_STORE_U32(ctx.r31.u32 + 11984, ctx.r27.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820931d0
	ctx.lr = 0x82092FF8;
	sub_820931D0(ctx, base);
loc_82092FF8:
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82093308
	ctx.lr = 0x82093004;
	sub_82093308(ctx, base);
	// stw r3,11984(r31)
	PPC_STORE_U32(ctx.r31.u32 + 11984, ctx.r3.u32);
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82093308
	ctx.lr = 0x82093014;
	sub_82093308(ctx, base);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82093308
	ctx.lr = 0x82093024;
	sub_82093308(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82093308
	ctx.lr = 0x82093034;
	sub_82093308(ctx, base);
	// rlwinm r11,r26,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 8) & 0xFFFFFF00;
	// lwz r10,11984(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 11984);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// rlwinm r11,r11,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// add r11,r3,r11
	ctx.r11.u64 = ctx.r3.u64 + ctx.r11.u64;
	// stw r11,11976(r31)
	PPC_STORE_U32(ctx.r31.u32 + 11976, ctx.r11.u32);
	// stw r11,11980(r31)
	PPC_STORE_U32(ctx.r31.u32 + 11980, ctx.r11.u32);
	// bne cr6,0x82093060
	if (!ctx.cr6.eq) goto loc_82093060;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82096640
	ctx.lr = 0x82093060;
	sub_82096640(ctx, base);
loc_82093060:
	// lwz r11,11984(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 11984);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x82093094
	if (ctx.cr6.eq) goto loc_82093094;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x82093094
	if (ctx.cr6.eq) goto loc_82093094;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x8209308c
	if (!ctx.cr6.eq) goto loc_8209308C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82095038
	ctx.lr = 0x82093084;
	sub_82095038(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x820930c4
	if (!ctx.cr0.eq) goto loc_820930C4;
loc_8209308C:
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x820931c4
	goto loc_820931C4;
loc_82093094:
	// lbz r11,11957(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11957);
	// addi r4,r31,2584
	ctx.r4.s64 = ctx.r31.s64 + 2584;
	// addi r3,r31,11028
	ctx.r3.s64 = ctx.r31.s64 + 11028;
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// rlwinm r5,r11,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x8207dac0
	ctx.lr = 0x820930AC;
	sub_8207DAC0(ctx, base);
	// li r5,249
	ctx.r5.s64 = 249;
	// addi r4,r31,3256
	ctx.r4.s64 = ctx.r31.s64 + 3256;
	// addi r3,r31,11700
	ctx.r3.s64 = ctx.r31.s64 + 11700;
	// bl 0x8207dac0
	ctx.lr = 0x820930BC;
	sub_8207DAC0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82096550
	ctx.lr = 0x820930C4;
	sub_82096550(ctx, base);
loc_820930C4:
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,11988(r31)
	PPC_STORE_U32(ctx.r31.u32 + 11988, ctx.r11.u32);
	// b 0x82093160
	goto loc_82093160;
loc_820930D0:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// ble cr6,0x8209316c
	if (!ctx.cr6.gt) goto loc_8209316C;
	// lwz r30,11980(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 11980);
	// cmpw cr6,r30,r29
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r29.s32, ctx.xer);
	// blt cr6,0x820930e8
	if (ctx.cr6.lt) goto loc_820930E8;
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
loc_820930E8:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8209308c
	if (ctx.cr6.eq) goto loc_8209308C;
	// lwz r11,11984(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 11984);
	// lwz r4,11960(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 11960);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82093110
	if (!ctx.cr6.eq) goto loc_82093110;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82095ef8
	ctx.lr = 0x8209310C;
	sub_82095EF8(ctx, base);
	// b 0x82093144
	goto loc_82093144;
loc_82093110:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82093128
	if (!ctx.cr6.eq) goto loc_82093128;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820956e8
	ctx.lr = 0x82093124;
	sub_820956E8(ctx, base);
	// b 0x82093144
	goto loc_82093144;
loc_82093128:
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x82093140
	if (!ctx.cr6.eq) goto loc_82093140;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82094e50
	ctx.lr = 0x8209313C;
	sub_82094E50(ctx, base);
	// b 0x82093144
	goto loc_82093144;
loc_82093140:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_82093144:
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8209308c
	if (!ctx.cr6.eq) goto loc_8209308C;
	// lwz r11,11980(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 11980);
	// subf r29,r30,r29
	ctx.r29.s64 = ctx.r29.s64 - ctx.r30.s64;
	// add r28,r30,r28
	ctx.r28.u64 = ctx.r30.u64 + ctx.r28.u64;
	// subf r11,r30,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r30.s64;
	// stw r11,11980(r31)
	PPC_STORE_U32(ctx.r31.u32 + 11980, ctx.r11.u32);
loc_82093160:
	// lwz r11,11980(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 11980);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt cr6,0x820930d0
	if (ctx.cr6.gt) goto loc_820930D0;
loc_8209316C:
	// lwz r11,11980(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 11980);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82093180
	if (!ctx.cr6.eq) goto loc_82093180;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,11988(r31)
	PPC_STORE_U32(ctx.r31.u32 + 11988, ctx.r11.u32);
loc_82093180:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne cr6,0x82093194
	if (!ctx.cr6.eq) goto loc_82093194;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820931d0
	ctx.lr = 0x82093190;
	sub_820931D0(ctx, base);
loc_82093190:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
loc_82093194:
	// bgt cr6,0x82092f80
	if (ctx.cr6.gt) goto loc_82092F80;
	// lwz r11,11960(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 11960);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820931ac
	if (!ctx.cr6.eq) goto loc_820931AC;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
loc_820931AC:
	// subf r11,r28,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r28.s64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82095f68
	ctx.lr = 0x820931C0;
	sub_82095F68(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
loc_820931C4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820931CC"))) PPC_WEAK_FUNC(sub_820931CC);
PPC_FUNC_IMPL(__imp__sub_820931CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820931D0"))) PPC_WEAK_FUNC(sub_820931D0);
PPC_FUNC_IMPL(__imp__sub_820931D0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,11984(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11984);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,11012(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11012);
	// lwz r9,11016(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11016);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bgtlr cr6
	if (ctx.cr6.gt) return;
	// lbz r9,1(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// li r8,16
	ctx.r8.s64 = 16;
	// lbz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// rotlwi r9,r9,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// lbz r6,3(r11)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r11.u32 + 3);
	// lbz r11,2(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 2);
	// or r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 | ctx.r7.u64;
	// stw r10,11012(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11012, ctx.r10.u32);
	// stb r8,11956(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11956, ctx.r8.u8);
	// rlwinm r10,r9,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// or r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 | ctx.r6.u64;
	// rlwinm r10,r10,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r11,11952(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11952, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8209322C"))) PPC_WEAK_FUNC(sub_8209322C);
PPC_FUNC_IMPL(__imp__sub_8209322C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82093230"))) PPC_WEAK_FUNC(sub_82093230);
PPC_FUNC_IMPL(__imp__sub_82093230) {
	PPC_FUNC_PROLOGUE();
	// b 0x820931d0
	sub_820931D0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82093234"))) PPC_WEAK_FUNC(sub_82093234);
PPC_FUNC_IMPL(__imp__sub_82093234) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82093238"))) PPC_WEAK_FUNC(sub_82093238);
PPC_FUNC_IMPL(__imp__sub_82093238) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,11956(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 11956);
	// lwz r10,11952(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11952);
	// subf r11,r4,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r4.s64;
	// slw r9,r10,r4
	ctx.r9.u64 = ctx.r4.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r4.u8 & 0x3F));
	// extsb. r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r9,11952(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11952, ctx.r9.u32);
	// stb r11,11956(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11956, ctx.r11.u8);
	// bgtlr 
	if (ctx.cr0.gt) return;
	// lwz r8,11016(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11016);
	// lwz r10,11012(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11012);
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x820932b4
	if (!ctx.cr6.lt) goto loc_820932B4;
	// lbz r6,11956(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 11956);
	// addi r11,r10,2
	ctx.r11.s64 = ctx.r10.s64 + 2;
	// lbz r7,1(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// extsb r5,r6
	ctx.r5.s64 = ctx.r6.s8;
	// lbz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// rotlwi r7,r7,8
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 8);
	// stw r11,11012(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11012, ctx.r11.u32);
	// extsb r6,r6
	ctx.r6.s64 = ctx.r6.s8;
	// or r7,r7,r4
	ctx.r7.u64 = ctx.r7.u64 | ctx.r4.u64;
	// neg r6,r6
	ctx.r6.s64 = -ctx.r6.s64;
	// addi r10,r5,16
	ctx.r10.s64 = ctx.r5.s64 + 16;
	// slw r7,r7,r6
	ctx.r7.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r6.u8 & 0x3F));
	// extsb. r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// or r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 | ctx.r9.u64;
	// stb r10,11956(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11956, ctx.r10.u8);
	// stw r9,11952(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11952, ctx.r9.u32);
	// bgtlr 
	if (ctx.cr0.gt) return;
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x820932c0
	if (ctx.cr6.lt) goto loc_820932C0;
loc_820932B4:
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,11959(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11959, ctx.r11.u8);
	// blr 
	return;
loc_820932C0:
	// lbz r8,11956(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 11956);
	// addi r9,r11,2
	ctx.r9.s64 = ctx.r11.s64 + 2;
	// lbz r10,1(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// extsb r7,r8
	ctx.r7.s64 = ctx.r8.s8;
	// lbz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// rotlwi r10,r10,8
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// lwz r6,11952(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11952);
	// extsb r8,r8
	ctx.r8.s64 = ctx.r8.s8;
	// stw r9,11012(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11012, ctx.r9.u32);
	// or r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 | ctx.r11.u64;
	// neg r8,r8
	ctx.r8.s64 = -ctx.r8.s64;
	// addi r11,r7,16
	ctx.r11.s64 = ctx.r7.s64 + 16;
	// slw r10,r10,r8
	ctx.r10.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r8.u8 & 0x3F));
	// or r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 | ctx.r6.u64;
	// stb r11,11956(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11956, ctx.r11.u8);
	// stw r10,11952(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11952, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82093304"))) PPC_WEAK_FUNC(sub_82093304);
PPC_FUNC_IMPL(__imp__sub_82093304) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82093308"))) PPC_WEAK_FUNC(sub_82093308);
PPC_FUNC_IMPL(__imp__sub_82093308) {
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
	// lwz r11,11952(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11952);
	// subfic r10,r4,32
	ctx.xer.ca = ctx.r4.u32 <= 32;
	ctx.r10.s64 = 32 - ctx.r4.s64;
	// srw r31,r11,r10
	ctx.r31.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r11.u32 >> (ctx.r10.u8 & 0x3F));
	// bl 0x82093238
	ctx.lr = 0x82093328;
	sub_82093238(ctx, base);
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

__attribute__((alias("__imp__sub_82093340"))) PPC_WEAK_FUNC(sub_82093340);
PPC_FUNC_IMPL(__imp__sub_82093340) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// addic. r11,r4,-1
	ctx.xer.ca = ctx.r4.u32 > 0;
	ctx.r11.s64 = ctx.r4.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r9,0
	ctx.r9.s64 = 0;
	// blt 0x8209338c
	if (ctx.cr0.lt) goto loc_8209338C;
	// lwz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
loc_82093358:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r8,2
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 2, ctx.xer);
	// ble cr6,0x8209337c
	if (!ctx.cr6.gt) goto loc_8209337C;
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r9,3
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 3, ctx.xer);
	// bge cr6,0x8209338c
	if (!ctx.cr6.lt) goto loc_8209338C;
	// b 0x82093380
	goto loc_82093380;
loc_8209337C:
	// li r9,0
	ctx.r9.s64 = 0;
loc_82093380:
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// bge 0x82093358
	if (!ctx.cr0.lt) goto loc_82093358;
loc_8209338C:
	// li r10,3
	ctx.r10.s64 = 3;
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// subfc r9,r10,r9
	ctx.xer.ca = ctx.r9.u32 >= ctx.r10.u32;
	ctx.r9.s64 = ctx.r9.s64 - ctx.r10.s64;
	// addze r8,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r8.s64 = temp.s64;
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// and r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 & ctx.r11.u64;
	// cmpw cr6,r11,r4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r4.s32, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// subf r9,r11,r4
	ctx.r9.s64 = ctx.r4.s64 - ctx.r11.s64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_820933B8:
	// lwz r11,36(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// lwzx r11,r11,r10
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82093404
	if (ctx.cr6.eq) goto loc_82093404;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bgt cr6,0x820933ec
	if (ctx.cr6.gt) goto loc_820933EC;
	// addi r11,r11,12
	ctx.r11.s64 = ctx.r11.s64 + 12;
	// lwz r9,48(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r11,r3
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r3.u32);
	// stwx r9,r11,r3
	PPC_STORE_U32(ctx.r11.u32 + ctx.r3.u32, ctx.r9.u32);
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// b 0x82093404
	goto loc_82093404;
loc_820933EC:
	// lwz r9,52(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// addi r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -2;
	// lwz r8,48(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
	// stw r9,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r9.u32);
	// stw r8,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r8.u32);
loc_82093404:
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x820933b8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820933B8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82093410"))) PPC_WEAK_FUNC(sub_82093410);
PPC_FUNC_IMPL(__imp__sub_82093410) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// li r8,256
	ctx.r8.s64 = 256;
	// li r9,1200
	ctx.r9.s64 = 1200;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r3,10470
	ctx.r10.s64 = ctx.r3.s64 + 10470;
	// addi r7,r3,9520
	ctx.r7.s64 = ctx.r3.s64 + 9520;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_8209342C:
	// lbzx r6,r7,r11
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r11.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lhzu r8,2(r10)
	ea = 2 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U16(ea);
	ctx.r10.u32 = ea;
	// mullw r8,r6,r8
	ctx.r8.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r8.s32);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// bdnz 0x8209342c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8209342C;
	// lwz r31,2152(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2152);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820934ac
	if (ctx.cr6.eq) goto loc_820934AC;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r4,r11,12292
	ctx.r4.s64 = ctx.r11.s64 + 12292;
loc_8209345C:
	// addi r11,r7,32
	ctx.r11.s64 = ctx.r7.s64 + 32;
	// lbzx r6,r7,r4
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r4.u32);
	// li r10,8
	ctx.r10.s64 = 8;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r8,r11,5235
	ctx.r8.s64 = ctx.r11.s64 + 5235;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// addi r11,r11,9519
	ctx.r11.s64 = ctx.r11.s64 + 9519;
	// add r10,r8,r3
	ctx.r10.u64 = ctx.r8.u64 + ctx.r3.u64;
loc_82093484:
	// lbzu r8,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// lhzu r5,2(r10)
	ea = 2 + ctx.r10.u32;
	ctx.r5.u64 = PPC_LOAD_U16(ea);
	ctx.r10.u32 = ea;
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// mullw r8,r8,r5
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r5.s32);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// bdnz 0x82093484
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82093484;
	// addi r11,r7,1
	ctx.r11.s64 = ctx.r7.s64 + 1;
	// clrlwi r7,r11,24
	ctx.r7.u64 = ctx.r11.u32 & 0xFF;
	// cmplw cr6,r7,r31
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r31.u32, ctx.xer);
	// blt cr6,0x8209345c
	if (ctx.cr6.lt) goto loc_8209345C;
loc_820934AC:
	// li r8,249
	ctx.r8.s64 = 249;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r3,15372
	ctx.r10.s64 = ctx.r3.s64 + 15372;
	// addi r7,r3,10221
	ctx.r7.s64 = ctx.r3.s64 + 10221;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_820934C0:
	// lbzx r6,r7,r11
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r11.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lhzu r8,2(r10)
	ea = 2 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U16(ea);
	ctx.r10.u32 = ea;
	// mullw r8,r6,r8
	ctx.r8.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r8.s32);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// bdnz 0x820934c0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820934C0;
	// addi r11,r9,7
	ctx.r11.s64 = ctx.r9.s64 + 7;
	// rlwinm r3,r11,29,3,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820934E8"))) PPC_WEAK_FUNC(sub_820934E8);
PPC_FUNC_IMPL(__imp__sub_820934E8) {
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
	// lwz r11,2144(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2144);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x82093530
	if (!ctx.cr6.gt) goto loc_82093530;
	// bl 0x820912a0
	ctx.lr = 0x8209350C;
	sub_820912A0(ctx, base);
	// lwz r4,2132(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2132);
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// subf. r5,r4,r11
	ctx.r5.s64 = ctx.r11.s64 - ctx.r4.s64;
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// ble 0x82093530
	if (!ctx.cr0.gt) goto loc_82093530;
	// lwz r11,17216(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 17216);
	// lwz r6,2144(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2144);
	// lwz r3,17200(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 17200);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82093530;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82093530:
	// lwz r10,2132(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2132);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r9,32
	ctx.r9.s64 = 32;
	// stw r11,2144(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2144, ctx.r11.u32);
	// stb r9,24(r31)
	PPC_STORE_U8(ctx.r31.u32 + 24, ctx.r9.u8);
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stw r10,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_82093560"))) PPC_WEAK_FUNC(sub_82093560);
PPC_FUNC_IMPL(__imp__sub_82093560) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82093568;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 24);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82091f58
	ctx.lr = 0x8209358C;
	sub_82091F58(ctx, base);
	// addi r10,r31,48
	ctx.r10.s64 = ctx.r31.s64 + 48;
	// li r9,3
	ctx.r9.s64 = 3;
loc_82093594:
	// li r8,4
	ctx.r8.s64 = 4;
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_820935A0:
	// lwz r8,2136(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// mr r7,r11
	ctx.r7.u64 = ctx.r11.u64;
	// rlwinm r11,r11,24,8,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 24) & 0xFFFFFF;
	// stb r7,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r7.u8);
	// lwz r8,2136(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stw r8,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r8.u32);
	// bdnz 0x820935a0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820935A0;
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x82093594
	if (!ctx.cr0.eq) goto loc_82093594;
	// li r28,0
	ctx.r28.s64 = 0;
	// b 0x82093618
	goto loc_82093618;
loc_820935D4:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r30,r30,-1
	ctx.r30.s64 = ctx.r30.s64 + -1;
	// lwz r10,2136(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// lbzx r11,r11,r29
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r29.u32);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r11.u8);
	// lwz r11,2144(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2144);
	// lwz r10,2136(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r10,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r10.u32);
	// stw r11,2144(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2144, ctx.r11.u32);
	// cmplwi cr6,r11,32768
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32768, ctx.xer);
	// bne cr6,0x82093618
	if (!ctx.cr6.eq) goto loc_82093618;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820934e8
	ctx.lr = 0x82093614;
	sub_820934E8(ctx, base);
	// stb r28,2161(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2161, ctx.r28.u8);
loc_82093618:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x820935d4
	if (!ctx.cr6.eq) goto loc_820935D4;
	// li r11,32
	ctx.r11.s64 = 32;
	// stw r28,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r28.u32);
	// stb r11,24(r31)
	PPC_STORE_U8(ctx.r31.u32 + 24, ctx.r11.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82093634"))) PPC_WEAK_FUNC(sub_82093634);
PPC_FUNC_IMPL(__imp__sub_82093634) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82093638"))) PPC_WEAK_FUNC(sub_82093638);
PPC_FUNC_IMPL(__imp__sub_82093638) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x82093640;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82093af4
	if (ctx.cr6.eq) goto loc_82093AF4;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r27,0
	ctx.r27.s64 = 0;
	// li r29,1
	ctx.r29.s64 = 1;
	// addi r26,r11,12088
	ctx.r26.s64 = ctx.r11.s64 + 12088;
	// addi r28,r10,12292
	ctx.r28.s64 = ctx.r10.s64 + 12292;
loc_82093670:
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// rlwinm r10,r30,29,3,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 29) & 0x1FFFFFFF;
	// clrlwi r9,r30,29
	ctx.r9.u64 = ctx.r30.u32 & 0x7;
	// slw r9,r29,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r29.u32 << (ctx.r9.u8 & 0x3F));
	// lbzx r11,r10,r11
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r11.u32);
	// and. r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 & ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82093760
	if (!ctx.cr0.eq) goto loc_82093760;
	// lwz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// lbz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 24);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// extsb r8,r10
	ctx.r8.s64 = ctx.r10.s8;
	// extsb r7,r10
	ctx.r7.s64 = ctx.r10.s8;
	// lbzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r30.u32);
	// add r11,r10,r31
	ctx.r11.u64 = ctx.r10.u64 + ctx.r31.u64;
	// addi r6,r10,6636
	ctx.r6.s64 = ctx.r10.s64 + 6636;
	// addi r10,r11,9520
	ctx.r10.s64 = ctx.r11.s64 + 9520;
	// rlwinm r10,r6,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// lbz r6,9520(r11)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r11.u32 + 9520);
	// subf r8,r6,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r6.s64;
	// lhzx r10,r10,r31
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r31.u32);
	// slw r10,r10,r8
	ctx.r10.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r8.u8 & 0x3F));
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r10,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// lbz r11,9520(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 9520);
	// subf r11,r11,r7
	ctx.r11.s64 = ctx.r7.s64 - ctx.r11.s64;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// stb r11,24(r31)
	PPC_STORE_U8(ctx.r31.u32 + 24, ctx.r11.u8);
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// bgt cr6,0x82093750
	if (ctx.cr6.gt) goto loc_82093750;
loc_820936E4:
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// lwz r10,2140(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2140);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82093700
	if (ctx.cr6.lt) goto loc_82093700;
	// lwz r11,2132(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2132);
	// stb r29,25(r31)
	PPC_STORE_U8(ctx.r31.u32 + 25, ctx.r29.u8);
	// stw r11,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r11.u32);
loc_82093700:
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// lbz r10,21(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 21);
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// lbz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 20);
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r11.u32);
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// lbz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 24);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// stw r11,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r11.u32);
	// rlwinm r9,r9,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// extsb r11,r10
	ctx.r11.s64 = ctx.r10.s8;
	// stb r10,24(r31)
	PPC_STORE_U8(ctx.r31.u32 + 24, ctx.r10.u8);
	// stw r9,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// ble cr6,0x820936e4
	if (!ctx.cr6.gt) goto loc_820936E4;
loc_82093750:
	// lwz r11,2144(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2144);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// b 0x82093acc
	goto loc_82093ACC;
loc_82093760:
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// lwzx r7,r11,r27
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r27.u32);
	// addi r27,r27,4
	ctx.r27.s64 = ctx.r27.s64 + 4;
	// lbzx r10,r10,r30
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r30.u32);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplwi cr6,r7,1024
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 1024, ctx.xer);
	// bge cr6,0x8209378c
	if (!ctx.cr6.lt) goto loc_8209378C;
	// add r11,r7,r31
	ctx.r11.u64 = ctx.r7.u64 + ctx.r31.u64;
	// lbz r11,1108(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1108);
	// b 0x820937b4
	goto loc_820937B4;
loc_8209378C:
	// lis r11,8
	ctx.r11.s64 = 524288;
	// cmplw cr6,r7,r11
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x820937ac
	if (!ctx.cr6.lt) goto loc_820937AC;
	// rlwinm r11,r7,23,9,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 23) & 0x7FFFFF;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lbz r11,1108(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1108);
	// addi r11,r11,18
	ctx.r11.s64 = ctx.r11.s64 + 18;
	// b 0x820937b4
	goto loc_820937B4;
loc_820937AC:
	// rlwinm r11,r7,15,24,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 15) & 0xFF;
	// addi r11,r11,34
	ctx.r11.s64 = ctx.r11.s64 + 34;
loc_820937B4:
	// lbz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r31.u32 + 24);
	// clrlwi r8,r10,24
	ctx.r8.u64 = ctx.r10.u32 & 0xFF;
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// extsb r4,r6
	ctx.r4.s64 = ctx.r6.s8;
	// cmplwi cr6,r8,7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 7, ctx.xer);
	// extsb r6,r6
	ctx.r6.s64 = ctx.r6.s8;
	// bge cr6,0x82093894
	if (!ctx.cr6.lt) goto loc_82093894;
	// clrlwi r9,r11,24
	ctx.r9.u64 = ctx.r11.u32 & 0xFF;
	// rlwinm r11,r11,3,21,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0x7F8;
	// addi r10,r9,1222
	ctx.r10.s64 = ctx.r9.s64 + 1222;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r3,r11,6892
	ctx.r3.s64 = ctx.r11.s64 + 6892;
	// add r11,r10,r8
	ctx.r11.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r10,r3,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// lbzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r31.u32);
	// lhzx r10,r10,r31
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r31.u32);
	// subf r6,r3,r6
	ctx.r6.s64 = ctx.r6.s64 - ctx.r3.s64;
	// slw r10,r10,r6
	ctx.r10.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r6.u8 & 0x3F));
	// or r10,r10,r5
	ctx.r10.u64 = ctx.r10.u64 | ctx.r5.u64;
	// stw r10,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// lbzx r11,r11,r31
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r31.u32);
	// subf r11,r11,r4
	ctx.r11.s64 = ctx.r4.s64 - ctx.r11.s64;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// stb r11,24(r31)
	PPC_STORE_U8(ctx.r31.u32 + 24, ctx.r11.u8);
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// bgt cr6,0x82093a04
	if (ctx.cr6.gt) goto loc_82093A04;
loc_82093824:
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// lwz r10,2140(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2140);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82093840
	if (ctx.cr6.lt) goto loc_82093840;
	// lwz r11,2132(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2132);
	// stb r29,25(r31)
	PPC_STORE_U8(ctx.r31.u32 + 25, ctx.r29.u8);
	// stw r11,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r11.u32);
loc_82093840:
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// lbz r10,21(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 21);
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lbz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 20);
	// stw r11,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r11.u32);
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// lbz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 24);
	// lwz r6,20(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r11.u32);
	// rlwinm r11,r6,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// extsb r11,r10
	ctx.r11.s64 = ctx.r10.s8;
	// stb r10,24(r31)
	PPC_STORE_U8(ctx.r31.u32 + 24, ctx.r10.u8);
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// ble cr6,0x82093824
	if (!ctx.cr6.gt) goto loc_82093824;
	// b 0x82093a04
	goto loc_82093A04;
loc_82093894:
	// rlwinm r10,r11,3,21,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0x7F8;
	// rlwinm r9,r11,4,20,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFF0;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + ctx.r31.u64;
	// add r3,r9,r31
	ctx.r3.u64 = ctx.r9.u64 + ctx.r31.u64;
	// addi r9,r10,9783
	ctx.r9.s64 = ctx.r10.s64 + 9783;
	// clrlwi r9,r11,24
	ctx.r9.u64 = ctx.r11.u32 & 0xFF;
	// lbz r24,9783(r10)
	ctx.r24.u64 = PPC_LOAD_U8(ctx.r10.u32 + 9783);
	// lhz r11,13798(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 13798);
	// subf r6,r24,r6
	ctx.r6.s64 = ctx.r6.s64 - ctx.r24.s64;
	// slw r11,r11,r6
	ctx.r11.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r6.u8 & 0x3F));
	// or r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 | ctx.r5.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lbz r11,9783(r10)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 9783);
	// subf r11,r11,r4
	ctx.r11.s64 = ctx.r4.s64 - ctx.r11.s64;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// stb r11,24(r31)
	PPC_STORE_U8(ctx.r31.u32 + 24, ctx.r11.u8);
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// bgt cr6,0x82093948
	if (ctx.cr6.gt) goto loc_82093948;
loc_820938DC:
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// lwz r10,2140(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2140);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x820938f8
	if (ctx.cr6.lt) goto loc_820938F8;
	// lwz r11,2132(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2132);
	// stb r29,25(r31)
	PPC_STORE_U8(ctx.r31.u32 + 25, ctx.r29.u8);
	// stw r11,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r11.u32);
loc_820938F8:
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// lbz r10,21(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 21);
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lbz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 20);
	// stw r11,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r11.u32);
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// lwz r6,20(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// rlwinm r6,r6,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// lbz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 24);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r6,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r6.u32);
	// stb r10,24(r31)
	PPC_STORE_U8(ctx.r31.u32 + 24, ctx.r10.u8);
	// stw r11,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r11.u32);
	// extsb r11,r10
	ctx.r11.s64 = ctx.r10.s8;
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// ble cr6,0x820938dc
	if (!ctx.cr6.gt) goto loc_820938DC;
loc_82093948:
	// add r11,r8,r31
	ctx.r11.u64 = ctx.r8.u64 + ctx.r31.u64;
	// lbz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 24);
	// addi r6,r8,8178
	ctx.r6.s64 = ctx.r8.s64 + 8178;
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// extsb r4,r10
	ctx.r4.s64 = ctx.r10.s8;
	// rlwinm r6,r6,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// extsb r3,r10
	ctx.r3.s64 = ctx.r10.s8;
	// lbz r24,10214(r11)
	ctx.r24.u64 = PPC_LOAD_U8(ctx.r11.u32 + 10214);
	// addi r10,r11,10214
	ctx.r10.s64 = ctx.r11.s64 + 10214;
	// subf r10,r24,r4
	ctx.r10.s64 = ctx.r4.s64 - ctx.r24.s64;
	// lhzx r6,r6,r31
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r6.u32 + ctx.r31.u32);
	// slw r10,r6,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r6.u32 << (ctx.r10.u8 & 0x3F));
	// or r10,r10,r5
	ctx.r10.u64 = ctx.r10.u64 | ctx.r5.u64;
	// stw r10,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// lbz r11,10214(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 10214);
	// subf r11,r11,r3
	ctx.r11.s64 = ctx.r3.s64 - ctx.r11.s64;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// stb r11,24(r31)
	PPC_STORE_U8(ctx.r31.u32 + 24, ctx.r11.u8);
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// bgt cr6,0x82093a04
	if (ctx.cr6.gt) goto loc_82093A04;
loc_82093998:
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// lwz r10,2140(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2140);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x820939b4
	if (ctx.cr6.lt) goto loc_820939B4;
	// lwz r11,2132(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2132);
	// stb r29,25(r31)
	PPC_STORE_U8(ctx.r31.u32 + 25, ctx.r29.u8);
	// stw r11,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r11.u32);
loc_820939B4:
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// lbz r10,21(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 21);
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// lbz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 20);
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r11.u32);
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// lbz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 24);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// lwz r6,20(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r10,2136(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// stb r11,24(r31)
	PPC_STORE_U8(ctx.r31.u32 + 24, ctx.r11.u8);
	// rlwinm r6,r6,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// stw r6,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r6.u32);
	// stw r10,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r10.u32);
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// ble cr6,0x82093998
	if (!ctx.cr6.gt) goto loc_82093998;
loc_82093A04:
	// lbzx r11,r9,r28
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r28.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82093ac0
	if (ctx.cr0.eq) goto loc_82093AC0;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r31.u32 + 24);
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// extsb r6,r6
	ctx.r6.s64 = ctx.r6.s8;
	// lbz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r31.u32 + 24);
	// subf r11,r11,r6
	ctx.r11.s64 = ctx.r6.s64 - ctx.r11.s64;
	// lwzx r10,r10,r26
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r26.u32);
	// and r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 & ctx.r7.u64;
	// slw r11,r10,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r11.u8 & 0x3F));
	// or r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 | ctx.r5.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lbzx r11,r9,r28
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r28.u32);
	// subf r11,r11,r4
	ctx.r11.s64 = ctx.r4.s64 - ctx.r11.s64;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// stb r11,24(r31)
	PPC_STORE_U8(ctx.r31.u32 + 24, ctx.r11.u8);
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// bgt cr6,0x82093ac0
	if (ctx.cr6.gt) goto loc_82093AC0;
loc_82093A54:
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// lwz r10,2140(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2140);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82093a70
	if (ctx.cr6.lt) goto loc_82093A70;
	// lwz r11,2132(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2132);
	// stb r29,25(r31)
	PPC_STORE_U8(ctx.r31.u32 + 25, ctx.r29.u8);
	// stw r11,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r11.u32);
loc_82093A70:
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// lbz r10,21(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 21);
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// lbz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r11.u32);
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// lbz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 24);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r9,16
	ctx.r11.s64 = ctx.r9.s64 + 16;
	// stb r11,24(r31)
	PPC_STORE_U8(ctx.r31.u32 + 24, ctx.r11.u8);
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// stw r7,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r7.u32);
	// stw r10,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// ble cr6,0x82093a54
	if (!ctx.cr6.gt) goto loc_82093A54;
loc_82093AC0:
	// lwz r11,2144(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2144);
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
loc_82093ACC:
	// stw r11,2144(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2144, ctx.r11.u32);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// cmplwi cr6,r11,32768
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32768, ctx.xer);
	// bne cr6,0x82093aec
	if (!ctx.cr6.eq) goto loc_82093AEC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820934e8
	ctx.lr = 0x82093AE4;
	sub_820934E8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,2161(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2161, ctx.r11.u8);
loc_82093AEC:
	// cmplw cr6,r30,r25
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r25.u32, ctx.xer);
	// blt cr6,0x82093670
	if (ctx.cr6.lt) goto loc_82093670;
loc_82093AF4:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82093AFC"))) PPC_WEAK_FUNC(sub_82093AFC);
PPC_FUNC_IMPL(__imp__sub_82093AFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82093B00"))) PPC_WEAK_FUNC(sub_82093B00);
PPC_FUNC_IMPL(__imp__sub_82093B00) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x82093B08;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82094158
	if (ctx.cr6.eq) goto loc_82094158;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r27,0
	ctx.r27.s64 = 0;
	// li r30,1
	ctx.r30.s64 = 1;
	// addi r26,r11,12088
	ctx.r26.s64 = ctx.r11.s64 + 12088;
	// addi r28,r10,12292
	ctx.r28.s64 = ctx.r10.s64 + 12292;
loc_82093B38:
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// rlwinm r10,r29,29,3,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 29) & 0x1FFFFFFF;
	// clrlwi r9,r29,29
	ctx.r9.u64 = ctx.r29.u32 & 0x7;
	// slw r9,r30,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r30.u32 << (ctx.r9.u8 & 0x3F));
	// lbzx r11,r10,r11
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r11.u32);
	// and. r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 & ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82093c28
	if (!ctx.cr0.eq) goto loc_82093C28;
	// lwz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// lbz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 24);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// extsb r8,r10
	ctx.r8.s64 = ctx.r10.s8;
	// extsb r7,r10
	ctx.r7.s64 = ctx.r10.s8;
	// lbzx r10,r11,r29
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r29.u32);
	// add r11,r10,r31
	ctx.r11.u64 = ctx.r10.u64 + ctx.r31.u64;
	// addi r6,r10,6636
	ctx.r6.s64 = ctx.r10.s64 + 6636;
	// addi r10,r11,9520
	ctx.r10.s64 = ctx.r11.s64 + 9520;
	// rlwinm r10,r6,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// lbz r6,9520(r11)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r11.u32 + 9520);
	// subf r8,r6,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r6.s64;
	// lhzx r10,r10,r31
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r31.u32);
	// slw r10,r10,r8
	ctx.r10.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r8.u8 & 0x3F));
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r10,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// lbz r11,9520(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 9520);
	// subf r11,r11,r7
	ctx.r11.s64 = ctx.r7.s64 - ctx.r11.s64;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// stb r11,24(r31)
	PPC_STORE_U8(ctx.r31.u32 + 24, ctx.r11.u8);
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// bgt cr6,0x82093c18
	if (ctx.cr6.gt) goto loc_82093C18;
loc_82093BAC:
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// lwz r10,2140(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2140);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82093bc8
	if (ctx.cr6.lt) goto loc_82093BC8;
	// lwz r11,2132(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2132);
	// stb r30,25(r31)
	PPC_STORE_U8(ctx.r31.u32 + 25, ctx.r30.u8);
	// stw r11,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r11.u32);
loc_82093BC8:
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// lbz r10,21(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 21);
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// lbz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 20);
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r11.u32);
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// lbz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 24);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// stw r11,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r11.u32);
	// rlwinm r9,r9,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// extsb r11,r10
	ctx.r11.s64 = ctx.r10.s8;
	// stb r10,24(r31)
	PPC_STORE_U8(ctx.r31.u32 + 24, ctx.r10.u8);
	// stw r9,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// ble cr6,0x82093bac
	if (!ctx.cr6.gt) goto loc_82093BAC;
loc_82093C18:
	// lwz r11,2144(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2144);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// b 0x82094130
	goto loc_82094130;
loc_82093C28:
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// lwzx r8,r11,r27
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r27.u32);
	// addi r27,r27,4
	ctx.r27.s64 = ctx.r27.s64 + 4;
	// lbzx r10,r10,r29
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r29.u32);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmplwi cr6,r8,1024
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1024, ctx.xer);
	// bge cr6,0x82093c54
	if (!ctx.cr6.lt) goto loc_82093C54;
	// add r11,r8,r31
	ctx.r11.u64 = ctx.r8.u64 + ctx.r31.u64;
	// lbz r11,1108(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1108);
	// b 0x82093c7c
	goto loc_82093C7C;
loc_82093C54:
	// lis r11,8
	ctx.r11.s64 = 524288;
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x82093c74
	if (!ctx.cr6.lt) goto loc_82093C74;
	// rlwinm r11,r8,23,9,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 23) & 0x7FFFFF;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lbz r11,1108(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1108);
	// addi r11,r11,18
	ctx.r11.s64 = ctx.r11.s64 + 18;
	// b 0x82093c7c
	goto loc_82093C7C;
loc_82093C74:
	// rlwinm r11,r8,15,24,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 15) & 0xFF;
	// addi r11,r11,34
	ctx.r11.s64 = ctx.r11.s64 + 34;
loc_82093C7C:
	// lbz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r31.u32 + 24);
	// clrlwi r7,r10,24
	ctx.r7.u64 = ctx.r10.u32 & 0xFF;
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// extsb r4,r6
	ctx.r4.s64 = ctx.r6.s8;
	// cmplwi cr6,r7,7
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 7, ctx.xer);
	// extsb r6,r6
	ctx.r6.s64 = ctx.r6.s8;
	// bge cr6,0x82093d5c
	if (!ctx.cr6.lt) goto loc_82093D5C;
	// clrlwi r9,r11,24
	ctx.r9.u64 = ctx.r11.u32 & 0xFF;
	// rlwinm r11,r11,3,21,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0x7F8;
	// addi r10,r9,1222
	ctx.r10.s64 = ctx.r9.s64 + 1222;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r3,r11,6892
	ctx.r3.s64 = ctx.r11.s64 + 6892;
	// add r11,r10,r7
	ctx.r11.u64 = ctx.r10.u64 + ctx.r7.u64;
	// rlwinm r10,r3,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// lbzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r31.u32);
	// lhzx r10,r10,r31
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r31.u32);
	// subf r6,r3,r6
	ctx.r6.s64 = ctx.r6.s64 - ctx.r3.s64;
	// slw r10,r10,r6
	ctx.r10.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r6.u8 & 0x3F));
	// or r10,r10,r5
	ctx.r10.u64 = ctx.r10.u64 | ctx.r5.u64;
	// stw r10,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// lbzx r11,r11,r31
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r31.u32);
	// subf r11,r11,r4
	ctx.r11.s64 = ctx.r4.s64 - ctx.r11.s64;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// stb r11,24(r31)
	PPC_STORE_U8(ctx.r31.u32 + 24, ctx.r11.u8);
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// bgt cr6,0x82093ed0
	if (ctx.cr6.gt) goto loc_82093ED0;
loc_82093CEC:
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// lwz r10,2140(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2140);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82093d08
	if (ctx.cr6.lt) goto loc_82093D08;
	// lwz r11,2132(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2132);
	// stb r30,25(r31)
	PPC_STORE_U8(ctx.r31.u32 + 25, ctx.r30.u8);
	// stw r11,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r11.u32);
loc_82093D08:
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// lbz r10,21(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 21);
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lbz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 20);
	// stw r11,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r11.u32);
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// lwz r10,2136(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// stw r10,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r10.u32);
	// rlwinm r6,r11,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lbz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 24);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// stw r6,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r6.u32);
	// stb r11,24(r31)
	PPC_STORE_U8(ctx.r31.u32 + 24, ctx.r11.u8);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// ble cr6,0x82093cec
	if (!ctx.cr6.gt) goto loc_82093CEC;
	// b 0x82093ed0
	goto loc_82093ED0;
loc_82093D5C:
	// rlwinm r10,r11,3,21,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0x7F8;
	// rlwinm r9,r11,4,20,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFF0;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + ctx.r31.u64;
	// add r3,r9,r31
	ctx.r3.u64 = ctx.r9.u64 + ctx.r31.u64;
	// addi r9,r10,9783
	ctx.r9.s64 = ctx.r10.s64 + 9783;
	// clrlwi r9,r11,24
	ctx.r9.u64 = ctx.r11.u32 & 0xFF;
	// lbz r24,9783(r10)
	ctx.r24.u64 = PPC_LOAD_U8(ctx.r10.u32 + 9783);
	// lhz r11,13798(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 13798);
	// subf r6,r24,r6
	ctx.r6.s64 = ctx.r6.s64 - ctx.r24.s64;
	// slw r11,r11,r6
	ctx.r11.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r6.u8 & 0x3F));
	// or r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 | ctx.r5.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lbz r11,9783(r10)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 9783);
	// subf r11,r11,r4
	ctx.r11.s64 = ctx.r4.s64 - ctx.r11.s64;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// stb r11,24(r31)
	PPC_STORE_U8(ctx.r31.u32 + 24, ctx.r11.u8);
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// bgt cr6,0x82093e14
	if (ctx.cr6.gt) goto loc_82093E14;
loc_82093DA4:
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// lwz r10,2140(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2140);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82093dc0
	if (ctx.cr6.lt) goto loc_82093DC0;
	// lwz r11,2132(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2132);
	// stb r30,25(r31)
	PPC_STORE_U8(ctx.r31.u32 + 25, ctx.r30.u8);
	// stw r11,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r11.u32);
loc_82093DC0:
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// lbz r10,21(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 21);
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lbz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 20);
	// stw r11,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r11.u32);
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// lbz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r31.u32 + 24);
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r11.u32);
	// addi r11,r6,16
	ctx.r11.s64 = ctx.r6.s64 + 16;
	// rlwinm r5,r10,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// stb r11,24(r31)
	PPC_STORE_U8(ctx.r31.u32 + 24, ctx.r11.u8);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// stw r5,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r5.u32);
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// ble cr6,0x82093da4
	if (!ctx.cr6.gt) goto loc_82093DA4;
loc_82093E14:
	// add r11,r7,r31
	ctx.r11.u64 = ctx.r7.u64 + ctx.r31.u64;
	// lbz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 24);
	// addi r6,r7,8178
	ctx.r6.s64 = ctx.r7.s64 + 8178;
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// extsb r4,r10
	ctx.r4.s64 = ctx.r10.s8;
	// rlwinm r6,r6,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// extsb r3,r10
	ctx.r3.s64 = ctx.r10.s8;
	// lbz r24,10214(r11)
	ctx.r24.u64 = PPC_LOAD_U8(ctx.r11.u32 + 10214);
	// addi r10,r11,10214
	ctx.r10.s64 = ctx.r11.s64 + 10214;
	// subf r10,r24,r4
	ctx.r10.s64 = ctx.r4.s64 - ctx.r24.s64;
	// lhzx r6,r6,r31
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r6.u32 + ctx.r31.u32);
	// slw r10,r6,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r6.u32 << (ctx.r10.u8 & 0x3F));
	// or r10,r10,r5
	ctx.r10.u64 = ctx.r10.u64 | ctx.r5.u64;
	// stw r10,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// lbz r11,10214(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 10214);
	// subf r11,r11,r3
	ctx.r11.s64 = ctx.r3.s64 - ctx.r11.s64;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// stb r11,24(r31)
	PPC_STORE_U8(ctx.r31.u32 + 24, ctx.r11.u8);
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// bgt cr6,0x82093ed0
	if (ctx.cr6.gt) goto loc_82093ED0;
loc_82093E64:
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// lwz r10,2140(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2140);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82093e80
	if (ctx.cr6.lt) goto loc_82093E80;
	// lwz r11,2132(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2132);
	// stb r30,25(r31)
	PPC_STORE_U8(ctx.r31.u32 + 25, ctx.r30.u8);
	// stw r11,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r11.u32);
loc_82093E80:
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// lbz r10,21(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 21);
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// lbz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 20);
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r11.u32);
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// lbz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 24);
	// lwz r6,20(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// lwz r10,2136(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r11,24(r31)
	PPC_STORE_U8(ctx.r31.u32 + 24, ctx.r11.u8);
	// rlwinm r6,r6,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// stw r10,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r10.u32);
	// stw r6,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r6.u32);
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// ble cr6,0x82093e64
	if (!ctx.cr6.gt) goto loc_82093E64;
loc_82093ED0:
	// lbzx r11,r9,r28
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r28.u32);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x8209406c
	if (ctx.cr6.lt) goto loc_8209406C;
	// ble cr6,0x82093fa8
	if (!ctx.cr6.gt) goto loc_82093FA8;
	// lbz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 24);
	// addi r6,r11,-3
	ctx.r6.s64 = ctx.r11.s64 + -3;
	// rlwinm r5,r8,29,3,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 29) & 0x1FFFFFFF;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// extsb r3,r10
	ctx.r3.s64 = ctx.r10.s8;
	// extsb r24,r10
	ctx.r24.s64 = ctx.r10.s8;
	// slw r10,r30,r6
	ctx.r10.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r30.u32 << (ctx.r6.u8 & 0x3F));
	// subf r11,r11,r3
	ctx.r11.s64 = ctx.r3.s64 - ctx.r11.s64;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// addi r11,r11,3
	ctx.r11.s64 = ctx.r11.s64 + 3;
	// and r10,r10,r5
	ctx.r10.u64 = ctx.r10.u64 & ctx.r5.u64;
	// extsb r6,r24
	ctx.r6.s64 = ctx.r24.s8;
	// slw r11,r10,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r11.u8 & 0x3F));
	// or r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 | ctx.r4.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lbzx r11,r9,r28
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r28.u32);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// subf r11,r11,r6
	ctx.r11.s64 = ctx.r6.s64 - ctx.r11.s64;
	// addi r11,r11,3
	ctx.r11.s64 = ctx.r11.s64 + 3;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// stb r11,24(r31)
	PPC_STORE_U8(ctx.r31.u32 + 24, ctx.r11.u8);
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// bgt cr6,0x82093fa8
	if (ctx.cr6.gt) goto loc_82093FA8;
loc_82093F3C:
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// lwz r10,2140(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2140);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82093f58
	if (ctx.cr6.lt) goto loc_82093F58;
	// lwz r11,2132(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2132);
	// stb r30,25(r31)
	PPC_STORE_U8(ctx.r31.u32 + 25, ctx.r30.u8);
	// stw r11,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r11.u32);
loc_82093F58:
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// lbz r10,21(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 21);
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// lbz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 20);
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r11.u32);
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// lbz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 24);
	// lwz r10,2136(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r11,24(r31)
	PPC_STORE_U8(ctx.r31.u32 + 24, ctx.r11.u8);
	// rlwinm r9,r9,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// stw r10,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r10.u32);
	// stw r9,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// ble cr6,0x82093f3c
	if (!ctx.cr6.gt) goto loc_82093F3C;
loc_82093FA8:
	// clrlwi r10,r8,29
	ctx.r10.u64 = ctx.r8.u32 & 0x7;
	// lbz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 24);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// add r11,r10,r31
	ctx.r11.u64 = ctx.r10.u64 + ctx.r31.u64;
	// addi r10,r10,8575
	ctx.r10.s64 = ctx.r10.s64 + 8575;
	// extsb r6,r9
	ctx.r6.s64 = ctx.r9.s8;
	// rlwinm r5,r10,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// extsb r9,r9
	ctx.r9.s64 = ctx.r9.s8;
	// lbz r4,17166(r11)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r11.u32 + 17166);
	// addi r10,r11,17166
	ctx.r10.s64 = ctx.r11.s64 + 17166;
	// subf r10,r4,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r4.s64;
	// lhzx r9,r5,r31
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r5.u32 + ctx.r31.u32);
	// slw r10,r9,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r10.u8 & 0x3F));
	// or r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 | ctx.r8.u64;
	// stw r10,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// lbz r11,17166(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 17166);
	// subf r11,r11,r6
	ctx.r11.s64 = ctx.r6.s64 - ctx.r11.s64;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// stb r11,24(r31)
	PPC_STORE_U8(ctx.r31.u32 + 24, ctx.r11.u8);
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// bgt cr6,0x82094124
	if (ctx.cr6.gt) goto loc_82094124;
loc_82093FFC:
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// lwz r10,2140(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2140);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82094018
	if (ctx.cr6.lt) goto loc_82094018;
	// lwz r11,2132(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2132);
	// stb r30,25(r31)
	PPC_STORE_U8(ctx.r31.u32 + 25, ctx.r30.u8);
	// stw r11,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r11.u32);
loc_82094018:
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// lbz r10,21(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 21);
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// lbz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r11.u32);
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// lbz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 24);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r10,2136(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r11,24(r31)
	PPC_STORE_U8(ctx.r31.u32 + 24, ctx.r11.u8);
	// rlwinm r9,r9,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// stw r10,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r10.u32);
	// stw r9,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// ble cr6,0x82093ffc
	if (!ctx.cr6.gt) goto loc_82093FFC;
	// b 0x82094124
	goto loc_82094124;
loc_8209406C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82094124
	if (ctx.cr6.eq) goto loc_82094124;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r31.u32 + 24);
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// extsb r6,r6
	ctx.r6.s64 = ctx.r6.s8;
	// lbz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r31.u32 + 24);
	// subf r11,r11,r6
	ctx.r11.s64 = ctx.r6.s64 - ctx.r11.s64;
	// lwzx r10,r10,r26
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r26.u32);
	// and r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 & ctx.r8.u64;
	// slw r11,r10,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r11.u8 & 0x3F));
	// or r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 | ctx.r5.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lbzx r11,r9,r28
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r28.u32);
	// subf r11,r11,r4
	ctx.r11.s64 = ctx.r4.s64 - ctx.r11.s64;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// stb r11,24(r31)
	PPC_STORE_U8(ctx.r31.u32 + 24, ctx.r11.u8);
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// bgt cr6,0x82094124
	if (ctx.cr6.gt) goto loc_82094124;
loc_820940B8:
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// lwz r10,2140(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2140);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x820940d4
	if (ctx.cr6.lt) goto loc_820940D4;
	// lwz r11,2132(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2132);
	// stb r30,25(r31)
	PPC_STORE_U8(ctx.r31.u32 + 25, ctx.r30.u8);
	// stw r11,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r11.u32);
loc_820940D4:
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// lbz r10,21(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 21);
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// lwz r11,2136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// lbz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r11.u32);
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// lwz r10,2136(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2136);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 24);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// stw r10,2136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2136, ctx.r10.u32);
	// rlwinm r9,r9,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// stb r11,24(r31)
	PPC_STORE_U8(ctx.r31.u32 + 24, ctx.r11.u8);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// stw r9,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// ble cr6,0x820940b8
	if (!ctx.cr6.gt) goto loc_820940B8;
loc_82094124:
	// lwz r11,2144(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2144);
	// add r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 + ctx.r11.u64;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
loc_82094130:
	// stw r11,2144(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2144, ctx.r11.u32);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// cmplwi cr6,r11,32768
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32768, ctx.xer);
	// bne cr6,0x82094150
	if (!ctx.cr6.eq) goto loc_82094150;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820934e8
	ctx.lr = 0x82094148;
	sub_820934E8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,2161(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2161, ctx.r11.u8);
loc_82094150:
	// cmplw cr6,r29,r25
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r25.u32, ctx.xer);
	// blt cr6,0x82093b38
	if (ctx.cr6.lt) goto loc_82093B38;
loc_82094158:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82094160"))) PPC_WEAK_FUNC(sub_82094160);
PPC_FUNC_IMPL(__imp__sub_82094160) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82094168;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// li r5,32
	ctx.r5.s64 = 32;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r3,17118
	ctx.r3.s64 = ctx.r3.s64 + 17118;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r29,0
	ctx.r29.s64 = 0;
	// bl 0x8207da20
	ctx.lr = 0x8209418C;
	sub_8207DA20(ctx, base);
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x820941c8
	if (ctx.cr6.eq) goto loc_820941C8;
	// mtctr r28
	ctx.ctr.u64 = ctx.r28.u64;
	// addi r9,r11,-4
	ctx.r9.s64 = ctx.r11.s64 + -4;
loc_820941A0:
	// lwzu r11,4(r9)
	ea = 4 + ctx.r9.u32;
	ctx.r11.u64 = PPC_LOAD_U32(ea);
	ctx.r9.u32 = ea;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x820941c4
	if (ctx.cr6.lt) goto loc_820941C4;
	// clrlwi r11,r11,29
	ctx.r11.u64 = ctx.r11.u32 & 0x7;
	// addi r11,r11,8559
	ctx.r11.s64 = ctx.r11.s64 + 8559;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r31.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sthx r10,r11,r31
	PPC_STORE_U16(ctx.r11.u32 + ctx.r31.u32, ctx.r10.u16);
loc_820941C4:
	// bdnz 0x820941a0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820941A0;
loc_820941C8:
	// li r10,0
	ctx.r10.s64 = 0;
loc_820941CC:
	// addi r11,r10,8559
	ctx.r11.s64 = ctx.r10.s64 + 8559;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r11,r11,r31
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r31.u32);
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// ble cr6,0x820941e4
	if (!ctx.cr6.gt) goto loc_820941E4;
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
loc_820941E4:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// clrlwi r11,r10,24
	ctx.r11.u64 = ctx.r10.u32 & 0xFF;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// blt cr6,0x820941cc
	if (ctx.cr6.lt) goto loc_820941CC;
	// li r11,5
	ctx.r11.s64 = 5;
	// divwu r11,r30,r11
	ctx.r11.u32 = ppc_divwu(ctx.r30.u32, ctx.r11.u32);
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82094218
	if (!ctx.cr6.gt) goto loc_82094218;
	// cmplwi cr6,r28,100
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 100, ctx.xer);
	// li r3,2
	ctx.r3.s64 = 2;
	// bge cr6,0x8209421c
	if (!ctx.cr6.lt) goto loc_8209421C;
loc_82094218:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8209421C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82094224"))) PPC_WEAK_FUNC(sub_82094224);
PPC_FUNC_IMPL(__imp__sub_82094224) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82094228"))) PPC_WEAK_FUNC(sub_82094228);
PPC_FUNC_IMPL(__imp__sub_82094228) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// cmplw cr6,r4,r6
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r6.u32, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// subf r10,r4,r6
	ctx.r10.s64 = ctx.r6.s64 - ctx.r4.s64;
	// rlwinm r7,r5,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r6,8
	ctx.r6.s64 = 524288;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8209424C:
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// rlwinm r9,r8,29,3,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 29) & 0x1FFFFFFF;
	// clrlwi r5,r8,29
	ctx.r5.u64 = ctx.r8.u32 & 0x7;
	// li r4,1
	ctx.r4.s64 = 1;
	// slw r5,r4,r5
	ctx.r5.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r5.u8 & 0x3F));
	// lbzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// and. r10,r5,r10
	ctx.r10.u64 = ctx.r5.u64 & ctx.r10.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// bne 0x82094290
	if (!ctx.cr0.eq) goto loc_82094290;
	// lbzx r10,r10,r8
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r10,r10,5236
	ctx.r10.s64 = ctx.r10.s64 + 5236;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r11.u32);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// sthx r9,r10,r11
	PPC_STORE_U16(ctx.r10.u32 + ctx.r11.u32, ctx.r9.u16);
	// b 0x8209437c
	goto loc_8209437C;
loc_82094290:
	// lwz r9,36(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// lbzx r10,r10,r8
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// cmplwi cr6,r10,7
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 7, ctx.xer);
	// lwzx r10,r9,r7
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r7.u32);
	// bge cr6,0x820942f8
	if (!ctx.cr6.lt) goto loc_820942F8;
	// cmplwi cr6,r10,1024
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1024, ctx.xer);
	// bge cr6,0x820942bc
	if (!ctx.cr6.lt) goto loc_820942BC;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lbz r10,1108(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1108);
	// b 0x820942e0
	goto loc_820942E0;
loc_820942BC:
	// cmplw cr6,r10,r6
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r6.u32, ctx.xer);
	// bge cr6,0x820942d8
	if (!ctx.cr6.lt) goto loc_820942D8;
	// rlwinm r10,r10,23,9,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 23) & 0x7FFFFF;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lbz r10,1108(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1108);
	// addi r10,r10,18
	ctx.r10.s64 = ctx.r10.s64 + 18;
	// b 0x820942e0
	goto loc_820942E0;
loc_820942D8:
	// rlwinm r10,r10,15,24,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0xFF;
	// addi r10,r10,34
	ctx.r10.s64 = ctx.r10.s64 + 34;
loc_820942E0:
	// lwz r5,40(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// rlwinm r9,r10,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lbzx r10,r5,r8
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r8.u32);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// addi r10,r10,5492
	ctx.r10.s64 = ctx.r10.s64 + 5492;
	// b 0x82094358
	goto loc_82094358;
loc_820942F8:
	// cmplwi cr6,r10,1024
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1024, ctx.xer);
	// bge cr6,0x82094310
	if (!ctx.cr6.lt) goto loc_82094310;
	// lwzx r10,r9,r7
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r7.u32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lbz r10,1108(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1108);
	// b 0x82094334
	goto loc_82094334;
loc_82094310:
	// cmplw cr6,r10,r6
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r6.u32, ctx.xer);
	// bge cr6,0x8209432c
	if (!ctx.cr6.lt) goto loc_8209432C;
	// rlwinm r10,r10,23,9,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 23) & 0x7FFFFF;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lbz r10,1108(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1108);
	// addi r10,r10,18
	ctx.r10.s64 = ctx.r10.s64 + 18;
	// b 0x82094334
	goto loc_82094334;
loc_8209432C:
	// rlwinm r10,r10,15,24,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0xFF;
	// addi r10,r10,34
	ctx.r10.s64 = ctx.r10.s64 + 34;
loc_82094334:
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r9,r10,10998
	ctx.r9.s64 = ctx.r10.s64 + 10998;
	// lhz r9,10998(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 10998);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// sth r9,10998(r10)
	PPC_STORE_U16(ctx.r10.u32 + 10998, ctx.r9.u16);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// lbzx r10,r10,r8
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// addi r10,r10,7680
	ctx.r10.s64 = ctx.r10.s64 + 7680;
loc_82094358:
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// lhzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r11.u32);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// sthx r9,r10,r11
	PPC_STORE_U16(ctx.r10.u32 + ctx.r11.u32, ctx.r9.u16);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// lbzx r10,r10,r8
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// addi r3,r10,2
	ctx.r3.s64 = ctx.r10.s64 + 2;
loc_8209437C:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// bdnz 0x8209424c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8209424C;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82094388"))) PPC_WEAK_FUNC(sub_82094388);
PPC_FUNC_IMPL(__imp__sub_82094388) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82094390;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// addi r3,r3,10472
	ctx.r3.s64 = ctx.r3.s64 + 10472;
	// li r5,2800
	ctx.r5.s64 = 2800;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// bl 0x8207da20
	ctx.lr = 0x820943B4;
	sub_8207DA20(ctx, base);
	// addi r3,r31,15374
	ctx.r3.s64 = ctx.r31.s64 + 15374;
	// li r5,996
	ctx.r5.s64 = 996;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8207da20
	ctx.lr = 0x820943C4;
	sub_8207DA20(ctx, base);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82094228
	ctx.lr = 0x820943D8;
	sub_82094228(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820943E0"))) PPC_WEAK_FUNC(sub_820943E0);
PPC_FUNC_IMPL(__imp__sub_820943E0) {
	PPC_FUNC_PROLOGUE();
	// b 0x82094228
	sub_82094228(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820943E4"))) PPC_WEAK_FUNC(sub_820943E4);
PPC_FUNC_IMPL(__imp__sub_820943E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820943E8"))) PPC_WEAK_FUNC(sub_820943E8);
PPC_FUNC_IMPL(__imp__sub_820943E8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x820943F0;
	__savegprlr_24(ctx, base);
	// stwu r1,-3360(r1)
	ea = -3360 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,2152(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2152);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// rlwinm r25,r11,3,0,28
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// mr r30,r8
	ctx.r30.u64 = ctx.r8.u64;
	// cmplwi cr6,r25,800
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 800, ctx.xer);
	// blt cr6,0x82094428
	if (ctx.cr6.lt) goto loc_82094428;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x820946cc
	goto loc_820946CC;
loc_82094428:
	// rlwinm r24,r11,4,0,27
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8207da20
	ctx.lr = 0x8209443C;
	sub_8207DA20(ctx, base);
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1680
	ctx.r3.s64 = ctx.r1.s64 + 1680;
	// bl 0x8207da20
	ctx.lr = 0x8209444C;
	sub_8207DA20(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82094634
	if (ctx.cr6.eq) goto loc_82094634;
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// rlwinm r8,r28,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// rlwinm r7,r29,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// mtctr r30
	ctx.ctr.u64 = ctx.r30.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lis r3,8
	ctx.r3.s64 = 524288;
loc_82094470:
	// rlwinm r11,r26,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 29) & 0x1FFFFFFF;
	// clrlwi r10,r26,29
	ctx.r10.u64 = ctx.r26.u32 & 0x7;
	// slw r10,r4,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r10.u8 & 0x3F));
	// lbzx r11,r11,r5
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r5.u32);
	// and. r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 & ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82094490
	if (!ctx.cr0.eq) goto loc_82094490;
	// lbzx r11,r6,r26
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r26.u32);
	// b 0x82094538
	goto loc_82094538;
loc_82094490:
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lbzx r9,r6,r26
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r26.u32);
	// cmplwi cr6,r9,7
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 7, ctx.xer);
	// lwzx r11,r10,r7
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r7.u32);
	// bge cr6,0x820944f0
	if (!ctx.cr6.lt) goto loc_820944F0;
	// cmplwi cr6,r11,1024
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1024, ctx.xer);
	// bge cr6,0x820944bc
	if (!ctx.cr6.lt) goto loc_820944BC;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lbz r11,1108(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1108);
	// b 0x820944e0
	goto loc_820944E0;
loc_820944BC:
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// bge cr6,0x820944d8
	if (!ctx.cr6.lt) goto loc_820944D8;
	// rlwinm r11,r11,23,9,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 23) & 0x7FFFFF;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lbz r11,1108(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1108);
	// addi r11,r11,18
	ctx.r11.s64 = ctx.r11.s64 + 18;
	// b 0x820944e0
	goto loc_820944E0;
loc_820944D8:
	// rlwinm r11,r11,15,24,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 15) & 0xFF;
	// addi r11,r11,34
	ctx.r11.s64 = ctx.r11.s64 + 34;
loc_820944E0:
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// b 0x82094534
	goto loc_82094534;
loc_820944F0:
	// cmplwi cr6,r11,1024
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1024, ctx.xer);
	// bge cr6,0x82094508
	if (!ctx.cr6.lt) goto loc_82094508;
	// lwzx r11,r10,r7
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r7.u32);
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lbz r11,1108(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1108);
	// b 0x8209452c
	goto loc_8209452C;
loc_82094508:
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// bge cr6,0x82094524
	if (!ctx.cr6.lt) goto loc_82094524;
	// rlwinm r11,r11,23,9,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 23) & 0x7FFFFF;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lbz r11,1108(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1108);
	// addi r11,r11,18
	ctx.r11.s64 = ctx.r11.s64 + 18;
	// b 0x8209452c
	goto loc_8209452C;
loc_82094524:
	// rlwinm r11,r11,15,24,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 15) & 0xFF;
	// addi r11,r11,34
	ctx.r11.s64 = ctx.r11.s64 + 34;
loc_8209452C:
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r11,r11,263
	ctx.r11.s64 = ctx.r11.s64 + 263;
loc_82094534:
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
loc_82094538:
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// clrlwi r9,r27,29
	ctx.r9.u64 = ctx.r27.u32 & 0x7;
	// rlwinm r30,r27,29,3,31
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 29) & 0x1FFFFFFF;
	// slw r29,r4,r9
	ctx.r29.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r9.u8 & 0x3F));
	// lhzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r10.u32);
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// lbzx r30,r30,r5
	ctx.r30.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r5.u32);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// and. r30,r29,r30
	ctx.r30.u64 = ctx.r29.u64 & ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// sthx r9,r11,r10
	PPC_STORE_U16(ctx.r11.u32 + ctx.r10.u32, ctx.r9.u16);
	// bne 0x82094570
	if (!ctx.cr0.eq) goto loc_82094570;
	// lbzx r11,r6,r27
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r27.u32);
	// b 0x82094618
	goto loc_82094618;
loc_82094570:
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lbzx r9,r6,r27
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r27.u32);
	// cmplwi cr6,r9,7
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 7, ctx.xer);
	// lwzx r11,r10,r8
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// bge cr6,0x820945d0
	if (!ctx.cr6.lt) goto loc_820945D0;
	// cmplwi cr6,r11,1024
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1024, ctx.xer);
	// bge cr6,0x8209459c
	if (!ctx.cr6.lt) goto loc_8209459C;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lbz r11,1108(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1108);
	// b 0x820945c0
	goto loc_820945C0;
loc_8209459C:
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// bge cr6,0x820945b8
	if (!ctx.cr6.lt) goto loc_820945B8;
	// rlwinm r11,r11,23,9,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 23) & 0x7FFFFF;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lbz r11,1108(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1108);
	// addi r11,r11,18
	ctx.r11.s64 = ctx.r11.s64 + 18;
	// b 0x820945c0
	goto loc_820945C0;
loc_820945B8:
	// rlwinm r11,r11,15,24,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 15) & 0xFF;
	// addi r11,r11,34
	ctx.r11.s64 = ctx.r11.s64 + 34;
loc_820945C0:
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// b 0x82094614
	goto loc_82094614;
loc_820945D0:
	// cmplwi cr6,r11,1024
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1024, ctx.xer);
	// bge cr6,0x820945e8
	if (!ctx.cr6.lt) goto loc_820945E8;
	// lwzx r11,r10,r8
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lbz r11,1108(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1108);
	// b 0x8209460c
	goto loc_8209460C;
loc_820945E8:
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// bge cr6,0x82094604
	if (!ctx.cr6.lt) goto loc_82094604;
	// rlwinm r11,r11,23,9,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 23) & 0x7FFFFF;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lbz r11,1108(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1108);
	// addi r11,r11,18
	ctx.r11.s64 = ctx.r11.s64 + 18;
	// b 0x8209460c
	goto loc_8209460C;
loc_82094604:
	// rlwinm r11,r11,15,24,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 15) & 0xFF;
	// addi r11,r11,34
	ctx.r11.s64 = ctx.r11.s64 + 34;
loc_8209460C:
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r11,r11,263
	ctx.r11.s64 = ctx.r11.s64 + 263;
loc_82094614:
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
loc_82094618:
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r1,1680
	ctx.r10.s64 = ctx.r1.s64 + 1680;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// lhzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r10.u32);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// sthx r9,r11,r10
	PPC_STORE_U16(ctx.r11.u32 + ctx.r10.u32, ctx.r9.u16);
	// bdnz 0x82094470
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82094470;
loc_82094634:
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x820946cc
	if (ctx.cr6.eq) goto loc_820946CC;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mtctr r25
	ctx.ctr.u64 = ctx.r25.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r11,r11,12400
	ctx.r11.s64 = ctx.r11.s64 + 12400;
loc_82094650:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r11,72
	ctx.r9.s64 = ctx.r11.s64 + 72;
	// lhzx r10,r8,r10
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r8.u32 + ctx.r10.u32);
	// cmplwi cr6,r10,256
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 256, ctx.xer);
	// bge cr6,0x8209466c
	if (!ctx.cr6.lt) goto loc_8209466C;
	// lbzx r9,r10,r9
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r9.u32);
	// b 0x82094678
	goto loc_82094678;
loc_8209466C:
	// rlwinm r10,r10,24,8,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFFFFFF;
	// lbzx r10,r10,r9
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r9.u32);
	// addi r9,r10,8
	ctx.r9.s64 = ctx.r10.s64 + 8;
loc_82094678:
	// addi r10,r1,1680
	ctx.r10.s64 = ctx.r1.s64 + 1680;
	// addi r7,r11,72
	ctx.r7.s64 = ctx.r11.s64 + 72;
	// lhzx r10,r8,r10
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r8.u32 + ctx.r10.u32);
	// cmplwi cr6,r10,256
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 256, ctx.xer);
	// bge cr6,0x82094694
	if (!ctx.cr6.lt) goto loc_82094694;
	// lbzx r10,r10,r7
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r7.u32);
	// b 0x820946a0
	goto loc_820946A0;
loc_82094694:
	// rlwinm r10,r10,24,8,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFFFFFF;
	// lbzx r10,r10,r7
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r7.u32);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
loc_820946A0:
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r8,2
	ctx.r8.s64 = ctx.r8.s64 + 2;
	// lwzx r10,r10,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// lwzx r9,r9,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// subf r10,r10,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r10.s64;
	// srawi r9,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 31;
	// xor r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r9.u64;
	// subf r10,r9,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r9.s64;
	// add r3,r10,r3
	ctx.r3.u64 = ctx.r10.u64 + ctx.r3.u64;
	// bdnz 0x82094650
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82094650;
loc_820946CC:
	// addi r1,r1,3360
	ctx.r1.s64 = ctx.r1.s64 + 3360;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820946D4"))) PPC_WEAK_FUNC(sub_820946D4);
PPC_FUNC_IMPL(__imp__sub_820946D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820946D8"))) PPC_WEAK_FUNC(sub_820946D8);
PPC_FUNC_IMPL(__imp__sub_820946D8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c964
	ctx.lr = 0x820946E0;
	__savegprlr_19(ctx, base);
	// stwu r1,-2256(r1)
	ea = -2256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// stw r5,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r5.u32);
	// mr r20,r7
	ctx.r20.u64 = ctx.r7.u64;
	// mr r21,r8
	ctx.r21.u64 = ctx.r8.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82094700
	if (ctx.cr6.eq) goto loc_82094700;
	// stw r6,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r6.u32);
loc_82094700:
	// subf r11,r4,r5
	ctx.r11.s64 = ctx.r5.s64 - ctx.r4.s64;
	// cmplwi cr6,r11,6144
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6144, ctx.xer);
	// blt cr6,0x8209489c
	if (ctx.cr6.lt) goto loc_8209489C;
	// lbz r19,2161(r25)
	ctx.r19.u64 = PPC_LOAD_U8(ctx.r25.u32 + 2161);
	// cmplwi cr6,r19,4
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, 4, ctx.xer);
	// bge cr6,0x8209489c
	if (!ctx.cr6.lt) goto loc_8209489C;
	// rlwinm. r11,r5,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 29) & 0x1FFFFFFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// beq 0x82094758
	if (ctx.cr0.eq) goto loc_82094758;
	// addi r8,r1,78
	ctx.r8.s64 = ctx.r1.s64 + 78;
	// lwz r7,44(r25)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r25.u32 + 44);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_82094734:
	// clrlwi. r11,r10,29
	ctx.r11.u64 = ctx.r10.u32 & 0x7;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82094740
	if (!ctx.cr0.eq) goto loc_82094740;
	// sthu r9,2(r8)
	ea = 2 + ctx.r8.u32;
	PPC_STORE_U16(ea, ctx.r9.u16);
	ctx.r8.u32 = ea;
loc_82094740:
	// lbzx r11,r7,r10
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r10.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r11,r11,r25
	ctx.r11.u64 = ctx.r11.u64 + ctx.r25.u64;
	// lbz r11,2162(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 2162);
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// bdnz 0x82094734
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82094734;
loc_82094758:
	// addi r11,r4,63
	ctx.r11.s64 = ctx.r4.s64 + 63;
	// addi r23,r5,-4096
	ctx.r23.s64 = ctx.r5.s64 + -4096;
	// rlwinm r22,r11,0,0,25
	ctx.r22.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFC0;
	// addi r24,r22,2048
	ctx.r24.s64 = ctx.r22.s64 + 2048;
	// cmplw cr6,r24,r23
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r23.u32, ctx.xer);
	// bge cr6,0x8209489c
	if (!ctx.cr6.lt) goto loc_8209489C;
	// addi r31,r24,1024
	ctx.r31.s64 = ctx.r24.s64 + 1024;
loc_82094774:
	// rlwinm r11,r31,27,5,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 27) & 0x7FFFFFE;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// rlwinm r9,r24,27,5,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 27) & 0x7FFFFFE;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r8,1024
	ctx.r8.s64 = 1024;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// lhzx r7,r11,r10
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r10.u32);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lhzx r6,r9,r6
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r6.u32);
	// bl 0x820943e8
	ctx.lr = 0x820947A0;
	sub_820943E8(ctx, base);
	// cmplwi cr6,r3,1400
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1400, ctx.xer);
	// ble cr6,0x8209488c
	if (!ctx.cr6.gt) goto loc_8209488C;
	// addi r5,r31,1024
	ctx.r5.s64 = ctx.r31.s64 + 1024;
	// addi r4,r31,-2048
	ctx.r4.s64 = ctx.r31.s64 + -2048;
	// rlwinm r11,r5,27,5,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x7FFFFFE;
	// rlwinm r10,r4,27,5,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x7FFFFFE;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r8,1024
	ctx.r8.s64 = 1024;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lhzx r7,r11,r9
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r9.u32);
	// lhzx r6,r10,r6
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r6.u32);
	// bl 0x820943e8
	ctx.lr = 0x820947D4;
	sub_820943E8(ctx, base);
	// cmplwi cr6,r3,1400
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1400, ctx.xer);
	// ble cr6,0x8209488c
	if (!ctx.cr6.gt) goto loc_8209488C;
	// addi r5,r31,2048
	ctx.r5.s64 = ctx.r31.s64 + 2048;
	// addi r4,r31,-3072
	ctx.r4.s64 = ctx.r31.s64 + -3072;
	// rlwinm r11,r5,27,5,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x7FFFFFE;
	// rlwinm r10,r4,27,5,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x7FFFFFE;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r8,1024
	ctx.r8.s64 = 1024;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lhzx r7,r11,r9
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r9.u32);
	// lhzx r6,r10,r6
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r6.u32);
	// bl 0x820943e8
	ctx.lr = 0x82094808;
	sub_820943E8(ctx, base);
	// cmplwi cr6,r3,1400
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1400, ctx.xer);
	// ble cr6,0x8209488c
	if (!ctx.cr6.gt) goto loc_8209488C;
	// addi r30,r31,-512
	ctx.r30.s64 = ctx.r31.s64 + -512;
	// addi r26,r31,1536
	ctx.r26.s64 = ctx.r31.s64 + 1536;
	// li r28,0
	ctx.r28.s64 = 0;
	// li r27,0
	ctx.r27.s64 = 0;
	// cmplw cr6,r30,r26
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r26.u32, ctx.xer);
	// bge cr6,0x8209488c
	if (!ctx.cr6.lt) goto loc_8209488C;
	// addi r29,r31,-1536
	ctx.r29.s64 = ctx.r31.s64 + -1536;
loc_8209482C:
	// rlwinm r11,r30,27,5,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 27) & 0x7FFFFFE;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// rlwinm r9,r29,27,5,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 27) & 0x7FFFFFE;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r8,1024
	ctx.r8.s64 = 1024;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lhzx r7,r11,r10
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r10.u32);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lhzx r6,r9,r6
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r6.u32);
	// bl 0x820943e8
	ctx.lr = 0x82094858;
	sub_820943E8(ctx, base);
	// cmplw cr6,r3,r28
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r28.u32, ctx.xer);
	// ble cr6,0x82094868
	if (!ctx.cr6.gt) goto loc_82094868;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r27,r30
	ctx.r27.u64 = ctx.r30.u64;
loc_82094868:
	// addi r30,r30,64
	ctx.r30.s64 = ctx.r30.s64 + 64;
	// addi r29,r29,64
	ctx.r29.s64 = ctx.r29.s64 + 64;
	// cmplw cr6,r30,r26
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r26.u32, ctx.xer);
	// blt cr6,0x8209482c
	if (ctx.cr6.lt) goto loc_8209482C;
	// cmplwi cr6,r28,1700
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 1700, ctx.xer);
	// blt cr6,0x8209488c
	if (ctx.cr6.lt) goto loc_8209488C;
	// subf r11,r22,r27
	ctx.r11.s64 = ctx.r27.s64 - ctx.r22.s64;
	// cmplwi cr6,r11,4096
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4096, ctx.xer);
	// bge cr6,0x820948a8
	if (!ctx.cr6.lt) goto loc_820948A8;
loc_8209488C:
	// addi r24,r24,1024
	ctx.r24.s64 = ctx.r24.s64 + 1024;
	// addi r31,r31,1024
	ctx.r31.s64 = ctx.r31.s64 + 1024;
	// cmplw cr6,r24,r23
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r23.u32, ctx.xer);
	// blt cr6,0x82094774
	if (ctx.cr6.lt) goto loc_82094774;
loc_8209489C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_820948A0:
	// addi r1,r1,2256
	ctx.r1.s64 = ctx.r1.s64 + 2256;
	// b 0x8207c9b4
	__restgprlr_19(ctx, base);
	return;
loc_820948A8:
	// addi r11,r19,1
	ctx.r11.s64 = ctx.r19.s64 + 1;
	// cmplwi cr6,r21,0
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 0, ctx.xer);
	// stb r11,2161(r25)
	PPC_STORE_U8(ctx.r25.u32 + 2161, ctx.r11.u8);
	// stw r27,0(r20)
	PPC_STORE_U32(ctx.r20.u32 + 0, ctx.r27.u32);
	// beq cr6,0x820948cc
	if (ctx.cr6.eq) goto loc_820948CC;
	// rlwinm r11,r27,27,5,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 27) & 0x7FFFFFE;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lhzx r11,r11,r10
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r10.u32);
	// stw r11,0(r21)
	PPC_STORE_U32(ctx.r21.u32 + 0, ctx.r11.u32);
loc_820948CC:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x820948a0
	goto loc_820948A0;
}

__attribute__((alias("__imp__sub_820948D4"))) PPC_WEAK_FUNC(sub_820948D4);
PPC_FUNC_IMPL(__imp__sub_820948D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820948D8"))) PPC_WEAK_FUNC(sub_820948D8);
PPC_FUNC_IMPL(__imp__sub_820948D8) {
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
	// lwz r11,9496(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 9496);
	// extsh r30,r4
	ctx.r30.s64 = ctx.r4.s16;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpw cr6,r30,r11
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r11.s32, ctx.xer);
	// lbz r11,9502(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 9502);
	// bge cr6,0x8209492c
	if (!ctx.cr6.lt) goto loc_8209492C;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// blt cr6,0x82094914
	if (ctx.cr6.lt) goto loc_82094914;
	// li r11,16
	ctx.r11.s64 = 16;
loc_82094914:
	// addi r11,r11,4730
	ctx.r11.s64 = ctx.r11.s64 + 4730;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r31.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sthx r10,r11,r31
	PPC_STORE_U16(ctx.r11.u32 + ctx.r31.u32, ctx.r10.u16);
	// b 0x82094968
	goto loc_82094968;
loc_8209492C:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r30,966
	ctx.r10.s64 = ctx.r30.s64 + 966;
	// stb r11,9502(r31)
	PPC_STORE_U8(ctx.r31.u32 + 9502, ctx.r11.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lhzx r4,r10,r31
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r31.u32);
	// bl 0x820948d8
	ctx.lr = 0x82094948;
	sub_820948D8(ctx, base);
	// rlwinm r11,r30,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lhz r4,3866(r11)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r11.u32 + 3866);
	// bl 0x820948d8
	ctx.lr = 0x8209495C;
	sub_820948D8(ctx, base);
	// lbz r11,9502(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 9502);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stb r11,9502(r31)
	PPC_STORE_U8(ctx.r31.u32 + 9502, ctx.r11.u8);
loc_82094968:
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

__attribute__((alias("__imp__sub_82094980"))) PPC_WEAK_FUNC(sub_82094980);
PPC_FUNC_IMPL(__imp__sub_82094980) {
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
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82094994:
	// addi r10,r11,4730
	ctx.r10.s64 = ctx.r11.s64 + 4730;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// li r8,0
	ctx.r8.s64 = 0;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// sthx r8,r10,r9
	PPC_STORE_U16(ctx.r10.u32 + ctx.r9.u32, ctx.r8.u16);
	// ble cr6,0x82094994
	if (!ctx.cr6.gt) goto loc_82094994;
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// bl 0x820948d8
	ctx.lr = 0x820949BC;
	sub_820948D8(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,16
	ctx.r11.s64 = 16;
loc_820949C4:
	// addi r8,r11,4730
	ctx.r8.s64 = ctx.r11.s64 + 4730;
	// subfic r7,r11,16
	ctx.xer.ca = ctx.r11.u32 <= 16;
	ctx.r7.s64 = 16 - ctx.r11.s64;
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// addi r11,r11,255
	ctx.r11.s64 = ctx.r11.s64 + 255;
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lhzx r8,r8,r9
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r8.u32 + ctx.r9.u32);
	// slw r8,r8,r7
	ctx.r8.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r7.u8 & 0x3F));
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// bne 0x820949c4
	if (!ctx.cr0.eq) goto loc_820949C4;
	// clrlwi. r6,r10,16
	ctx.r6.u64 = ctx.r10.u32 & 0xFFFF;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq 0x82094a60
	if (ctx.cr0.eq) goto loc_82094A60;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r10,r11,65535
	ctx.r10.u64 = ctx.r11.u64 | 65535;
loc_82094A00:
	// lhz r8,9492(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 9492);
	// li r11,15
	ctx.r11.s64 = 15;
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// sth r8,9492(r9)
	PPC_STORE_U16(ctx.r9.u32 + 9492, ctx.r8.u16);
loc_82094A10:
	// addi r8,r11,4730
	ctx.r8.s64 = ctx.r11.s64 + 4730;
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r7,r9
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r7.u32 + ctx.r9.u32);
	// cmplwi r8,0
	ctx.cr0.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne 0x82094a34
	if (!ctx.cr0.eq) goto loc_82094A34;
	// addi r11,r11,255
	ctx.r11.s64 = ctx.r11.s64 + 255;
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82094a10
	if (!ctx.cr0.eq) goto loc_82094A10;
	// b 0x82094a50
	goto loc_82094A50;
loc_82094A34:
	// addi r11,r11,4731
	ctx.r11.s64 = ctx.r11.s64 + 4731;
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r8,r7,r9
	PPC_STORE_U16(ctx.r7.u32 + ctx.r9.u32, ctx.r8.u16);
	// lhzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r9.u32);
	// addi r8,r8,2
	ctx.r8.s64 = ctx.r8.s64 + 2;
	// sthx r8,r11,r9
	PPC_STORE_U16(ctx.r11.u32 + ctx.r9.u32, ctx.r8.u16);
loc_82094A50:
	// add r11,r6,r10
	ctx.r11.u64 = ctx.r6.u64 + ctx.r10.u64;
	// clrlwi. r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// mr r6,r11
	ctx.r6.u64 = ctx.r11.u64;
	// bne 0x82094a00
	if (!ctx.cr0.eq) goto loc_82094A00;
loc_82094A60:
	// li r10,16
	ctx.r10.s64 = 16;
	// li r7,16
	ctx.r7.s64 = 16;
loc_82094A68:
	// addi r11,r7,4730
	ctx.r11.s64 = ctx.r7.s64 + 4730;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r11,r11,r9
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r9.u32);
	// b 0x82094a94
	goto loc_82094A94;
loc_82094A78:
	// lwz r8,2452(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2452);
	// lwz r6,2456(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2456);
	// lhz r8,0(r8)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r8.u32 + 0);
	// stbx r10,r8,r6
	PPC_STORE_U8(ctx.r8.u32 + ctx.r6.u32, ctx.r10.u8);
	// lwz r8,2452(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2452);
	// addi r8,r8,2
	ctx.r8.s64 = ctx.r8.s64 + 2;
	// stw r8,2452(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2452, ctx.r8.u32);
loc_82094A94:
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// extsh. r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge 0x82094a78
	if (!ctx.cr0.lt) goto loc_82094A78;
	// addi r11,r7,255
	ctx.r11.s64 = ctx.r7.s64 + 255;
	// clrlwi. r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// bne 0x82094a68
	if (!ctx.cr0.eq) goto loc_82094A68;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82094AC0"))) PPC_WEAK_FUNC(sub_82094AC0);
PPC_FUNC_IMPL(__imp__sub_82094AC0) {
	PPC_FUNC_PROLOGUE();
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// extsh r11,r4
	ctx.r11.s64 = ctx.r4.s16;
	// lha r9,9500(r3)
	ctx.r9.s64 = int16_t(PPC_LOAD_U16(ctx.r3.u32 + 9500));
	// addi r10,r11,1230
	ctx.r10.s64 = ctx.r11.s64 + 1230;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// lhzx r7,r8,r3
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r8.u32 + ctx.r3.u32);
	// bgt cr6,0x82094b90
	if (ctx.cr6.gt) goto loc_82094B90;
	// extsh r8,r7
	ctx.r8.s64 = ctx.r7.s16;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// rlwinm r6,r8,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
loc_82094AF8:
	// bge cr6,0x82094b38
	if (!ctx.cr6.lt) goto loc_82094B38;
	// addi r9,r10,1231
	ctx.r9.s64 = ctx.r10.s64 + 1231;
	// lwz r8,2448(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2448);
	// addi r5,r10,1230
	ctx.r5.s64 = ctx.r10.s64 + 1230;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r5,r5,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// lhax r9,r9,r3
	ctx.r9.s64 = int16_t(PPC_LOAD_U16(ctx.r9.u32 + ctx.r3.u32));
	// lhax r5,r5,r3
	ctx.r5.s64 = int16_t(PPC_LOAD_U16(ctx.r5.u32 + ctx.r3.u32));
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r5,r5,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r9,r9,r8
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r8.u32);
	// lhzx r8,r5,r8
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r5.u32 + ctx.r8.u32);
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// ble cr6,0x82094b38
	if (!ctx.cr6.gt) goto loc_82094B38;
	// addi r11,r10,1
	ctx.r11.s64 = ctx.r10.s64 + 1;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
loc_82094B38:
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// lwz r8,2448(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2448);
	// addi r9,r10,1230
	ctx.r9.s64 = ctx.r10.s64 + 1230;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r5,r6,r8
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r6.u32 + ctx.r8.u32);
	// lhzx r9,r9,r3
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r3.u32);
	// extsh r31,r9
	ctx.r31.s64 = ctx.r9.s16;
	// rlwinm r31,r31,1,0,30
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r31,r8
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + ctx.r8.u32);
	// cmplw cr6,r5,r8
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r8.u32, ctx.xer);
	// ble cr6,0x82094b90
	if (!ctx.cr6.gt) goto loc_82094B90;
	// extsh r8,r4
	ctx.r8.s64 = ctx.r4.s16;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r8,r8,1230
	ctx.r8.s64 = ctx.r8.s64 + 1230;
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// extsh r11,r10
	ctx.r11.s64 = ctx.r10.s16;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// sthx r9,r8,r3
	PPC_STORE_U16(ctx.r8.u32 + ctx.r3.u32, ctx.r9.u16);
	// lha r9,9500(r3)
	ctx.r9.s64 = int16_t(PPC_LOAD_U16(ctx.r3.u32 + 9500));
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// ble cr6,0x82094af8
	if (!ctx.cr6.gt) goto loc_82094AF8;
loc_82094B90:
	// extsh r11,r4
	ctx.r11.s64 = ctx.r4.s16;
	// addi r11,r11,1230
	ctx.r11.s64 = ctx.r11.s64 + 1230;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r7,r11,r3
	PPC_STORE_U16(ctx.r11.u32 + ctx.r3.u32, ctx.r7.u16);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82094BA8"))) PPC_WEAK_FUNC(sub_82094BA8);
PPC_FUNC_IMPL(__imp__sub_82094BA8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x82094BB0;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lha r11,9500(r3)
	ctx.r11.s64 = int16_t(PPC_LOAD_U16(ctx.r3.u32 + 9500));
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// srawi r4,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r4.s64 = ctx.r11.s32 >> 1;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r25,r6
	ctx.r25.u64 = ctx.r6.u64;
	// extsh r31,r4
	ctx.r31.s64 = ctx.r4.s16;
	// b 0x82094be0
	goto loc_82094BE0;
loc_82094BD0:
	// bl 0x82094ac0
	ctx.lr = 0x82094BD4;
	sub_82094AC0(ctx, base);
	// addi r11,r31,-1
	ctx.r11.s64 = ctx.r31.s64 + -1;
	// extsh r4,r11
	ctx.r4.s64 = ctx.r11.s16;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
loc_82094BE0:
	// cmpwi cr6,r31,1
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 1, ctx.xer);
	// bge cr6,0x82094bd0
	if (!ctx.cr6.lt) goto loc_82094BD0;
	// stw r25,2452(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2452, ctx.r25.u32);
loc_82094BEC:
	// lhz r26,2462(r3)
	ctx.r26.u64 = PPC_LOAD_U16(ctx.r3.u32 + 2462);
	// lwz r11,9496(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 9496);
	// extsh r31,r26
	ctx.r31.s64 = ctx.r26.s16;
	// cmpw cr6,r31,r11
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x82094c14
	if (!ctx.cr6.lt) goto loc_82094C14;
	// lwz r11,2452(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2452);
	// sth r26,0(r11)
	PPC_STORE_U16(ctx.r11.u32 + 0, ctx.r26.u16);
	// lwz r11,2452(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2452);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// stw r11,2452(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2452, ctx.r11.u32);
loc_82094C14:
	// lha r11,9500(r3)
	ctx.r11.s64 = int16_t(PPC_LOAD_U16(ctx.r3.u32 + 9500));
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r10,r11,1230
	ctx.r10.s64 = ctx.r11.s64 + 1230;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r10,r3
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r3.u32);
	// sth r11,9500(r3)
	PPC_STORE_U16(ctx.r3.u32 + 9500, ctx.r11.u16);
	// sth r10,2462(r3)
	PPC_STORE_U16(ctx.r3.u32 + 2462, ctx.r10.u16);
	// bl 0x82094ac0
	ctx.lr = 0x82094C38;
	sub_82094AC0(ctx, base);
	// lwz r10,9496(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 9496);
	// lhz r27,2462(r3)
	ctx.r27.u64 = PPC_LOAD_U16(ctx.r3.u32 + 2462);
	// extsh r11,r27
	ctx.r11.s64 = ctx.r27.s16;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x82094c60
	if (!ctx.cr6.lt) goto loc_82094C60;
	// lwz r10,2452(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2452);
	// sth r27,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r27.u16);
	// lwz r10,2452(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2452);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// stw r10,2452(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2452, ctx.r10.u32);
loc_82094C60:
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r10,r31,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// extsh r31,r29
	ctx.r31.s64 = ctx.r29.s16;
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// rlwinm r9,r31,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r11,r11,r28
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r28.u32);
	// addi r8,r31,1
	ctx.r8.s64 = ctx.r31.s64 + 1;
	// lhzx r10,r10,r28
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r28.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// extsh r29,r8
	ctx.r29.s64 = ctx.r8.s16;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// sthx r11,r9,r28
	PPC_STORE_U16(ctx.r9.u32 + ctx.r28.u32, ctx.r11.u16);
	// sth r30,2462(r3)
	PPC_STORE_U16(ctx.r3.u32 + 2462, ctx.r30.u16);
	// bl 0x82094ac0
	ctx.lr = 0x82094C98;
	sub_82094AC0(ctx, base);
	// addi r10,r31,966
	ctx.r10.s64 = ctx.r31.s64 + 966;
	// rlwinm r11,r31,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// sthx r26,r10,r3
	PPC_STORE_U16(ctx.r10.u32 + ctx.r3.u32, ctx.r26.u16);
	// sth r27,3866(r11)
	PPC_STORE_U16(ctx.r11.u32 + 3866, ctx.r27.u16);
	// lha r11,9500(r3)
	ctx.r11.s64 = int16_t(PPC_LOAD_U16(ctx.r3.u32 + 9500));
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bgt cr6,0x82094bec
	if (ctx.cr6.gt) goto loc_82094BEC;
	// stw r25,2452(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2452, ctx.r25.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82094980
	ctx.lr = 0x82094CC8;
	sub_82094980(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82094CD0"))) PPC_WEAK_FUNC(sub_82094CD0);
PPC_FUNC_IMPL(__imp__sub_82094CD0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x82094CD8;
	__savegprlr_26(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r8
	ctx.r27.u64 = ctx.r8.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// mr r26,r7
	ctx.r26.u64 = ctx.r7.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
loc_82094CF8:
	// stw r29,9496(r31)
	PPC_STORE_U32(ctx.r31.u32 + 9496, ctx.r29.u32);
	// extsh r4,r29
	ctx.r4.s64 = ctx.r29.s16;
	// stw r5,2448(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2448, ctx.r5.u32);
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// stw r28,2456(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2456, ctx.r28.u32);
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stb r30,9502(r31)
	PPC_STORE_U8(ctx.r31.u32 + 9502, ctx.r30.u8);
	// sth r30,9500(r31)
	PPC_STORE_U16(ctx.r31.u32 + 9500, ctx.r30.u16);
	// sth r30,2462(r31)
	PPC_STORE_U16(ctx.r31.u32 + 2462, ctx.r30.u16);
	// ble cr6,0x82094d70
	if (!ctx.cr6.gt) goto loc_82094D70;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_82094D24:
	// lwz r9,2456(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2456);
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stbx r30,r11,r9
	PPC_STORE_U8(ctx.r11.u32 + ctx.r9.u32, ctx.r30.u8);
	// lhzx r9,r7,r5
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r7.u32 + ctx.r5.u32);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq 0x82094d5c
	if (ctx.cr0.eq) goto loc_82094D5C;
	// lhz r9,9500(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 9500);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// extsh r7,r9
	ctx.r7.s64 = ctx.r9.s16;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// sth r7,9500(r31)
	PPC_STORE_U16(ctx.r31.u32 + 9500, ctx.r7.u16);
	// addi r9,r9,1230
	ctx.r9.s64 = ctx.r9.s64 + 1230;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r10,r9,r31
	PPC_STORE_U16(ctx.r9.u32 + ctx.r31.u32, ctx.r10.u16);
loc_82094D5C:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmpw cr6,r10,r29
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r29.s32, ctx.xer);
	// blt cr6,0x82094d24
	if (ctx.cr6.lt) goto loc_82094D24;
loc_82094D70:
	// lha r11,9500(r31)
	ctx.r11.s64 = int16_t(PPC_LOAD_U16(ctx.r31.u32 + 9500));
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bge cr6,0x82094db4
	if (!ctx.cr6.lt) goto loc_82094DB4;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82094da4
	if (ctx.cr0.eq) goto loc_82094DA4;
	// lhz r11,2462(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 2462);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82094d9c
	if (!ctx.cr0.eq) goto loc_82094D9C;
	// sth r8,2(r5)
	PPC_STORE_U16(ctx.r5.u32 + 2, ctx.r8.u16);
	// b 0x82094cf8
	goto loc_82094CF8;
loc_82094D9C:
	// sth r8,0(r5)
	PPC_STORE_U16(ctx.r5.u32 + 0, ctx.r8.u16);
	// b 0x82094cf8
	goto loc_82094CF8;
loc_82094DA4:
	// lha r11,2462(r31)
	ctx.r11.s64 = int16_t(PPC_LOAD_U16(ctx.r31.u32 + 2462));
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r30,r11,r26
	PPC_STORE_U16(ctx.r11.u32 + ctx.r26.u32, ctx.r30.u16);
	// b 0x82094e48
	goto loc_82094E48;
loc_82094DB4:
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82094ba8
	ctx.lr = 0x82094DC0;
	sub_82094BA8(ctx, base);
	// clrlwi. r11,r27,24
	ctx.r11.u64 = ctx.r27.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82094e48
	if (ctx.cr0.eq) goto loc_82094E48;
	// li r9,16
	ctx.r9.s64 = 16;
	// sth r30,80(r1)
	PPC_STORE_U16(ctx.r1.u32 + 80, ctx.r30.u16);
	// addi r11,r1,82
	ctx.r11.s64 = ctx.r1.s64 + 82;
	// sth r30,82(r1)
	PPC_STORE_U16(ctx.r1.u32 + 82, ctx.r30.u16);
	// addi r10,r31,9460
	ctx.r10.s64 = ctx.r31.s64 + 9460;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_82094DE0:
	// lhz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 0);
	// lhzu r9,2(r10)
	ea = 2 + ctx.r10.u32;
	ctx.r9.u64 = PPC_LOAD_U16(ea);
	ctx.r10.u32 = ea;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// rlwinm r9,r9,1,16,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFE;
	// sthu r9,2(r11)
	ea = 2 + ctx.r11.u32;
	PPC_STORE_U16(ea, ctx.r9.u16);
	ctx.r11.u32 = ea;
	// bdnz 0x82094de0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82094DE0;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// ble cr6,0x82094e48
	if (!ctx.cr6.gt) goto loc_82094E48;
	// addi r8,r26,-2
	ctx.r8.s64 = ctx.r26.s64 + -2;
	// mtctr r29
	ctx.ctr.u64 = ctx.r29.u64;
loc_82094E0C:
	// lbzx r10,r11,r28
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r28.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r10,r7
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r7.u32);
	// sthu r10,2(r8)
	ea = 2 + ctx.r8.u32;
	PPC_STORE_U16(ea, ctx.r10.u16);
	ctx.r8.u32 = ea;
	// lbzx r10,r11,r28
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r28.u32);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lhzx r7,r10,r9
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r9.u32);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// sthx r7,r10,r9
	PPC_STORE_U16(ctx.r10.u32 + ctx.r9.u32, ctx.r7.u16);
	// bdnz 0x82094e0c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82094E0C;
loc_82094E48:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82094E50"))) PPC_WEAK_FUNC(sub_82094E50);
PPC_FUNC_IMPL(__imp__sub_82094E50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c968
	ctx.lr = 0x82094E58;
	__savegprlr_20(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r30,11012(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11012);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// lwz r11,11016(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11016);
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// lwz r24,0(r3)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r21,r3,11012
	ctx.r21.s64 = ctx.r3.s64 + 11012;
	// subf r11,r30,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r30.s64;
	// lwz r20,4(r3)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// add r22,r4,r5
	ctx.r22.u64 = ctx.r4.u64 + ctx.r5.u64;
	// cmpw cr6,r5,r11
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x82094e8c
	if (ctx.cr6.lt) goto loc_82094E8C;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
loc_82094E8C:
	// add r29,r24,r27
	ctx.r29.u64 = ctx.r24.u64 + ctx.r27.u64;
	// li r8,16
	ctx.r8.s64 = 16;
	// add r23,r22,r24
	ctx.r23.u64 = ctx.r22.u64 + ctx.r24.u64;
	// add r26,r29,r5
	ctx.r26.u64 = ctx.r29.u64 + ctx.r5.u64;
	// mr r31,r29
	ctx.r31.u64 = ctx.r29.u64;
	// cmplw cr6,r29,r30
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r30.u32, ctx.xer);
	// blt cr6,0x82094ecc
	if (ctx.cr6.lt) goto loc_82094ECC;
	// addi r11,r30,64
	ctx.r11.s64 = ctx.r30.s64 + 64;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x82094ecc
	if (!ctx.cr6.lt) goto loc_82094ECC;
	// addi r11,r30,16
	ctx.r11.s64 = ctx.r30.s64 + 16;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82094fa8
	if (ctx.cr6.lt) goto loc_82094FA8;
	// rlwinm r11,r5,0,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFF0;
	// add r7,r11,r29
	ctx.r7.u64 = ctx.r11.u64 + ctx.r29.u64;
	// b 0x82094f6c
	goto loc_82094F6C;
loc_82094ECC:
	// rlwinm r11,r5,0,0,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFC0;
	// rlwinm r10,r5,0,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFF0;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// add r7,r10,r29
	ctx.r7.u64 = ctx.r10.u64 + ctx.r29.u64;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x82094f6c
	if (!ctx.cr6.lt) goto loc_82094F6C;
	// subf r11,r29,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r29.s64;
	// li r10,32
	ctx.r10.s64 = 32;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// li r9,64
	ctx.r9.s64 = 64;
	// rlwinm r11,r11,26,6,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 26) & 0x3FFFFFF;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// li r11,48
	ctx.r11.s64 = 48;
loc_82094F04:
	// li r6,128
	ctx.r6.s64 = 128;
	// dcbt r6,r30
	// dcbt r6,r31
	// lvrx128 v62,r8,r30
	temp.u32 = ctx.r8.u32 + ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v63,r0,r30
	temp.u32 = ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v63,v63,v62
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// lvrx128 v61,r10,r30
	temp.u32 = ctx.r10.u32 + ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v62,r8,r30
	temp.u32 = ctx.r8.u32 + ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v62,v62,v61
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8)));
	// lvrx128 v60,r11,r30
	temp.u32 = ctx.r11.u32 + ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v61,r10,r30
	temp.u32 = ctx.r10.u32 + ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v61,v61,v60
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v60.u8)));
	// lvrx128 v59,r9,r30
	temp.u32 = ctx.r9.u32 + ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v60,r11,r30
	temp.u32 = ctx.r11.u32 + ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r30,r30,64
	ctx.r30.s64 = ctx.r30.s64 + 64;
	// stvlx128 v63,r0,r31
	ea = ctx.r31.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		PPC_STORE_U8(ea + i, ctx.v63.u8[15 - i]);
	// vor128 v60,v60,v59
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v59.u8)));
	// stvrx128 v63,r31,r8
	ea = ctx.r31.u32 + ctx.r8.u32;
	for (size_t i = 0; i < (ea & 0xF); i++)
		PPC_STORE_U8(ea - i - 1, ctx.v63.u8[i]);
	// stvlx128 v62,r31,r8
	ea = ctx.r31.u32 + ctx.r8.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		PPC_STORE_U8(ea + i, ctx.v62.u8[15 - i]);
	// stvrx128 v62,r31,r10
	ea = ctx.r31.u32 + ctx.r10.u32;
	for (size_t i = 0; i < (ea & 0xF); i++)
		PPC_STORE_U8(ea - i - 1, ctx.v62.u8[i]);
	// stvlx128 v61,r31,r10
	ea = ctx.r31.u32 + ctx.r10.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		PPC_STORE_U8(ea + i, ctx.v61.u8[15 - i]);
	// stvrx128 v61,r31,r11
	ea = ctx.r31.u32 + ctx.r11.u32;
	for (size_t i = 0; i < (ea & 0xF); i++)
		PPC_STORE_U8(ea - i - 1, ctx.v61.u8[i]);
	// stvlx128 v60,r31,r11
	ea = ctx.r31.u32 + ctx.r11.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		PPC_STORE_U8(ea + i, ctx.v60.u8[15 - i]);
	// stvrx128 v60,r31,r9
	ea = ctx.r31.u32 + ctx.r9.u32;
	for (size_t i = 0; i < (ea & 0xF); i++)
		PPC_STORE_U8(ea - i - 1, ctx.v60.u8[i]);
	// addi r31,r31,64
	ctx.r31.s64 = ctx.r31.s64 + 64;
	// bdnz 0x82094f04
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82094F04;
loc_82094F6C:
	// cmplw cr6,r31,r7
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x82094fa8
	if (!ctx.cr6.lt) goto loc_82094FA8;
	// subf r11,r31,r7
	ctx.r11.s64 = ctx.r7.s64 - ctx.r31.s64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r11,r11,28,4,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0xFFFFFFF;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_82094F88:
	// lvlx128 v63,r0,r30
	temp.u32 = ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvrx128 v62,r8,r30
	temp.u32 = ctx.r8.u32 + ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// addi r30,r30,16
	ctx.r30.s64 = ctx.r30.s64 + 16;
	// vor128 v63,v63,v62
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// stvlx128 v63,r0,r31
	ea = ctx.r31.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		PPC_STORE_U8(ea + i, ctx.v63.u8[15 - i]);
	// stvrx128 v63,r31,r8
	ea = ctx.r31.u32 + ctx.r8.u32;
	for (size_t i = 0; i < (ea & 0xF); i++)
		PPC_STORE_U8(ea - i - 1, ctx.v63.u8[i]);
	// addi r31,r31,16
	ctx.r31.s64 = ctx.r31.s64 + 16;
	// bdnz 0x82094f88
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82094F88;
loc_82094FA8:
	// cmplw cr6,r31,r26
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r26.u32, ctx.xer);
	// bge cr6,0x82094fcc
	if (!ctx.cr6.lt) goto loc_82094FCC;
	// subf r28,r31,r26
	ctx.r28.s64 = ctx.r26.s64 - ctx.r31.s64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207df48
	ctx.lr = 0x82094FC4;
	sub_8207DF48(ctx, base);
	// add r30,r28,r30
	ctx.r30.u64 = ctx.r28.u64 + ctx.r30.u64;
	// add r31,r28,r31
	ctx.r31.u64 = ctx.r28.u64 + ctx.r31.u64;
loc_82094FCC:
	// subf r11,r29,r31
	ctx.r11.s64 = ctx.r31.s64 - ctx.r29.s64;
	// cmplw cr6,r26,r23
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r23.u32, ctx.xer);
	// add r31,r11,r27
	ctx.r31.u64 = ctx.r11.u64 + ctx.r27.u64;
	// beq cr6,0x82094fe4
	if (ctx.cr6.eq) goto loc_82094FE4;
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x8209502c
	goto loc_8209502C;
loc_82094FE4:
	// stw r30,0(r21)
	PPC_STORE_U32(ctx.r21.u32 + 0, ctx.r30.u32);
	// cmpwi cr6,r22,257
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 257, ctx.xer);
	// li r11,257
	ctx.r11.s64 = 257;
	// bgt cr6,0x82094ff8
	if (ctx.cr6.gt) goto loc_82094FF8;
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
loc_82094FF8:
	// add r10,r27,r20
	ctx.r10.u64 = ctx.r27.u64 + ctx.r20.u64;
	// subf r11,r27,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r27.s64;
	// add r3,r10,r24
	ctx.r3.u64 = ctx.r10.u64 + ctx.r24.u64;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x8209501c
	if (!ctx.cr6.lt) goto loc_8209501C;
	// subf r4,r20,r3
	ctx.r4.s64 = ctx.r3.s64 - ctx.r20.s64;
	// subf r5,r3,r11
	ctx.r5.s64 = ctx.r11.s64 - ctx.r3.s64;
	// bl 0x8207df48
	ctx.lr = 0x8209501C;
	sub_8207DF48(ctx, base);
loc_8209501C:
	// lwz r11,8(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 8);
	// subf r3,r22,r31
	ctx.r3.s64 = ctx.r31.s64 - ctx.r22.s64;
	// and r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 & ctx.r31.u64;
	// stw r11,11960(r25)
	PPC_STORE_U32(ctx.r25.u32 + 11960, ctx.r11.u32);
loc_8209502C:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9b8
	__restgprlr_20(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82095034"))) PPC_WEAK_FUNC(sub_82095034);
PPC_FUNC_IMPL(__imp__sub_82095034) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82095038"))) PPC_WEAK_FUNC(sub_82095038);
PPC_FUNC_IMPL(__imp__sub_82095038) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lwz r11,11012(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11012);
	// addi r9,r3,12
	ctx.r9.s64 = ctx.r3.s64 + 12;
	// lwz r10,11016(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11016);
	// addi r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -2;
	// addi r8,r11,4
	ctx.r8.s64 = ctx.r11.s64 + 4;
	// stw r11,11012(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11012, ctx.r11.u32);
	// cmplw cr6,r8,r10
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82095060
	if (ctx.cr6.lt) goto loc_82095060;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82095060:
	// li r10,3
	ctx.r10.s64 = 3;
	// addi r9,r9,-4
	ctx.r9.s64 = ctx.r9.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8209506C:
	// lbz r10,3(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 3);
	// lbz r8,2(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 2);
	// rotlwi r10,r10,8
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// lbz r7,1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// lbz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// or r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 | ctx.r8.u64;
	// rlwinm r10,r10,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// or r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 | ctx.r7.u64;
	// rlwinm r10,r10,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// or r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 | ctx.r6.u64;
	// stwu r10,4(r9)
	ea = 4 + ctx.r9.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x8209506c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8209506C;
	// stw r11,11012(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11012, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820950AC"))) PPC_WEAK_FUNC(sub_820950AC);
PPC_FUNC_IMPL(__imp__sub_820950AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820950B0"))) PPC_WEAK_FUNC(sub_820950B0);
PPC_FUNC_IMPL(__imp__sub_820950B0) {
	PPC_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c964
	ctx.lr = 0x820950B8;
	__savegprlr_19(ctx, base);
	// add r28,r4,r5
	ctx.r28.u64 = ctx.r4.u64 + ctx.r5.u64;
	// lwz r21,11016(r3)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11016);
	// lwz r30,0(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lbz r8,11956(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 11956);
	// addi r25,r3,3644
	ctx.r25.s64 = ctx.r3.s64 + 3644;
	// lwz r10,11952(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11952);
	// addi r24,r3,9020
	ctx.r24.s64 = ctx.r3.s64 + 9020;
	// lwz r5,11012(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11012);
	// addi r23,r3,24
	ctx.r23.s64 = ctx.r3.s64 + 24;
	// addi r22,r3,2072
	ctx.r22.s64 = ctx.r3.s64 + 2072;
	// addi r27,r3,2584
	ctx.r27.s64 = ctx.r3.s64 + 2584;
	// addi r26,r3,3256
	ctx.r26.s64 = ctx.r3.s64 + 3256;
	// addi r29,r3,12
	ctx.r29.s64 = ctx.r3.s64 + 12;
	// b 0x8209534c
	goto loc_8209534C;
loc_820950F4:
	// rlwinm r9,r10,11,21,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 11) & 0x7FE;
	// lhax r7,r9,r23
	ctx.r7.s64 = int16_t(PPC_LOAD_U16(ctx.r9.u32 + ctx.r23.u32));
	// cmpwi r7,0
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bge 0x82095134
	if (!ctx.cr0.lt) goto loc_82095134;
	// lis r9,32
	ctx.r9.s64 = 2097152;
loc_82095108:
	// and r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 & ctx.r10.u64;
	// rlwinm r7,r7,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// cntlzw r6,r6
	ctx.r6.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r9,r9,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r6,r6,27,5,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x7FFFFFF;
	// xori r6,r6,1
	ctx.r6.u64 = ctx.r6.u64 ^ 1;
	// subf r7,r7,r6
	ctx.r7.s64 = ctx.r6.s64 - ctx.r7.s64;
	// rlwinm r7,r7,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// lhax r7,r7,r25
	ctx.r7.s64 = int16_t(PPC_LOAD_U16(ctx.r7.u32 + ctx.r25.u32));
	// cmpwi r7,0
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// blt 0x82095108
	if (ctx.cr0.lt) goto loc_82095108;
loc_82095134:
	// cmplw cr6,r5,r21
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r21.u32, ctx.xer);
	// bge cr6,0x82095368
	if (!ctx.cr6.lt) goto loc_82095368;
	// lbzx r9,r7,r27
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r27.u32);
	// subf r8,r9,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r9.s64;
	// slw r10,r10,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r9.u8 & 0x3F));
	// extsb r8,r8
	ctx.r8.s64 = ctx.r8.s8;
	// mr. r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bgt 0x8209517c
	if (ctx.cr0.gt) goto loc_8209517C;
	// lbz r8,1(r5)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r5.u32 + 1);
	// neg r6,r9
	ctx.r6.s64 = -ctx.r9.s64;
	// lbz r3,0(r5)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// rotlwi r8,r8,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// addi r5,r5,2
	ctx.r5.s64 = ctx.r5.s64 + 2;
	// or r3,r8,r3
	ctx.r3.u64 = ctx.r8.u64 | ctx.r3.u64;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// slw r9,r3,r6
	ctx.r9.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r3.u32 << (ctx.r6.u8 & 0x3F));
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
loc_8209517C:
	// addic. r6,r7,-256
	ctx.xer.ca = ctx.r7.u32 > 255;
	ctx.r6.s64 = ctx.r7.s64 + -256;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bge 0x820951a0
	if (!ctx.cr0.lt) goto loc_820951A0;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// clrlwi r7,r6,24
	ctx.r7.u64 = ctx.r6.u32 & 0xFF;
	// add r9,r9,r30
	ctx.r9.u64 = ctx.r9.u64 + ctx.r30.u64;
	// stbx r7,r30,r4
	PPC_STORE_U8(ctx.r30.u32 + ctx.r4.u32, ctx.r7.u8);
	// stbx r7,r9,r4
	PPC_STORE_U8(ctx.r9.u32 + ctx.r4.u32, ctx.r7.u8);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// b 0x8209534c
	goto loc_8209534C;
loc_820951A0:
	// clrlwi r3,r6,29
	ctx.r3.u64 = ctx.r6.u32 & 0x7;
	// cmpwi cr6,r3,7
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 7, ctx.xer);
	// bne cr6,0x82095230
	if (!ctx.cr6.eq) goto loc_82095230;
	// rlwinm r9,r10,9,23,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 9) & 0x1FE;
	// lhax r9,r9,r22
	ctx.r9.s64 = int16_t(PPC_LOAD_U16(ctx.r9.u32 + ctx.r22.u32));
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge 0x820951ec
	if (!ctx.cr0.lt) goto loc_820951EC;
	// lis r7,128
	ctx.r7.s64 = 8388608;
loc_820951C0:
	// and r3,r7,r10
	ctx.r3.u64 = ctx.r7.u64 & ctx.r10.u64;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// cntlzw r3,r3
	ctx.r3.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r7,r7,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r3,r3,27,5,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 27) & 0x7FFFFFF;
	// xori r3,r3,1
	ctx.r3.u64 = ctx.r3.u64 ^ 1;
	// subf r9,r9,r3
	ctx.r9.s64 = ctx.r3.s64 - ctx.r9.s64;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhax r9,r9,r24
	ctx.r9.s64 = int16_t(PPC_LOAD_U16(ctx.r9.u32 + ctx.r24.u32));
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// blt 0x820951c0
	if (ctx.cr0.lt) goto loc_820951C0;
loc_820951EC:
	// lbzx r7,r9,r26
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r26.u32);
	// subf r8,r7,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r7.s64;
	// slw r10,r10,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r7.u8 & 0x3F));
	// extsb r8,r8
	ctx.r8.s64 = ctx.r8.s8;
	// mr. r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bgt 0x8209522c
	if (ctx.cr0.gt) goto loc_8209522C;
	// lbz r8,1(r5)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r5.u32 + 1);
	// neg r3,r7
	ctx.r3.s64 = -ctx.r7.s64;
	// lbz r31,0(r5)
	ctx.r31.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// addi r7,r7,16
	ctx.r7.s64 = ctx.r7.s64 + 16;
	// rotlwi r8,r8,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// addi r5,r5,2
	ctx.r5.s64 = ctx.r5.s64 + 2;
	// or r31,r8,r31
	ctx.r31.u64 = ctx.r8.u64 | ctx.r31.u64;
	// extsb r8,r7
	ctx.r8.s64 = ctx.r7.s8;
	// slw r7,r31,r3
	ctx.r7.u64 = ctx.r3.u8 & 0x20 ? 0 : (ctx.r31.u32 << (ctx.r3.u8 & 0x3F));
	// or r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 | ctx.r10.u64;
loc_8209522C:
	// addi r3,r9,7
	ctx.r3.s64 = ctx.r9.s64 + 7;
loc_82095230:
	// srawi r9,r6,3
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7) != 0);
	ctx.r9.s64 = ctx.r6.s32 >> 3;
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// cmpwi cr6,r7,2
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 2, ctx.xer);
	// ble cr6,0x820952f4
	if (!ctx.cr6.gt) goto loc_820952F4;
	// cmpwi cr6,r7,3
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 3, ctx.xer);
	// ble cr6,0x820952dc
	if (!ctx.cr6.gt) goto loc_820952DC;
	// add r9,r7,r11
	ctx.r9.u64 = ctx.r7.u64 + ctx.r11.u64;
	// lbz r9,12004(r9)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r9.u32 + 12004);
	// mr r31,r9
	ctx.r31.u64 = ctx.r9.u64;
	// subf r9,r9,r8
	ctx.r9.s64 = ctx.r8.s64 - ctx.r9.s64;
	// subfic r6,r31,32
	ctx.xer.ca = ctx.r31.u32 <= 32;
	ctx.r6.s64 = 32 - ctx.r31.s64;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// srw r6,r10,r6
	ctx.r6.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r6.u8 & 0x3F));
	// mr. r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// slw r10,r10,r31
	ctx.r10.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r31.u8 & 0x3F));
	// bgt 0x820952c8
	if (ctx.cr0.gt) goto loc_820952C8;
	// lbz r8,1(r5)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r5.u32 + 1);
	// addi r31,r9,16
	ctx.r31.s64 = ctx.r9.s64 + 16;
	// neg r19,r9
	ctx.r19.s64 = -ctx.r9.s64;
	// lbz r20,0(r5)
	ctx.r20.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// rotlwi r9,r8,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// extsb r8,r31
	ctx.r8.s64 = ctx.r31.s8;
	// or r31,r9,r20
	ctx.r31.u64 = ctx.r9.u64 | ctx.r20.u64;
	// mr. r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// slw r31,r31,r19
	ctx.r31.u64 = ctx.r19.u8 & 0x20 ? 0 : (ctx.r31.u32 << (ctx.r19.u8 & 0x3F));
	// or r10,r31,r10
	ctx.r10.u64 = ctx.r31.u64 | ctx.r10.u64;
	// addi r5,r5,2
	ctx.r5.s64 = ctx.r5.s64 + 2;
	// bgt 0x820952c8
	if (ctx.cr0.gt) goto loc_820952C8;
	// lbz r8,1(r5)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r5.u32 + 1);
	// neg r31,r9
	ctx.r31.s64 = -ctx.r9.s64;
	// lbz r20,0(r5)
	ctx.r20.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// rotlwi r8,r8,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// addi r5,r5,2
	ctx.r5.s64 = ctx.r5.s64 + 2;
	// or r20,r8,r20
	ctx.r20.u64 = ctx.r8.u64 | ctx.r20.u64;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// slw r9,r20,r31
	ctx.r9.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r20.u32 << (ctx.r31.u8 & 0x3F));
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
loc_820952C8:
	// addi r9,r7,3014
	ctx.r9.s64 = ctx.r7.s64 + 3014;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r9,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// add r9,r9,r6
	ctx.r9.u64 = ctx.r9.u64 + ctx.r6.u64;
	// b 0x820952e0
	goto loc_820952E0;
loc_820952DC:
	// li r9,1
	ctx.r9.s64 = 1;
loc_820952E0:
	// lwz r7,4(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r6,0(r29)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// stw r7,8(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8, ctx.r7.u32);
	// stw r6,4(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4, ctx.r6.u32);
	// b 0x8209530c
	goto loc_8209530C;
loc_820952F4:
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// lwzx r9,r6,r29
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r29.u32);
	// beq cr6,0x82095310
	if (ctx.cr6.eq) goto loc_82095310;
	// lwz r7,0(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// stwx r7,r6,r29
	PPC_STORE_U32(ctx.r6.u32 + ctx.r29.u32, ctx.r7.u32);
loc_8209530C:
	// stw r9,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r9.u32);
loc_82095310:
	// lwz r31,8(r11)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// addi r3,r3,2
	ctx.r3.s64 = ctx.r3.s64 + 2;
	// subf r7,r9,r4
	ctx.r7.s64 = ctx.r4.s64 - ctx.r9.s64;
loc_8209531C:
	// and r9,r7,r31
	ctx.r9.u64 = ctx.r7.u64 & ctx.r31.u64;
	// cmpwi cr6,r4,257
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 257, ctx.xer);
	// lbzx r9,r9,r30
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r30.u32);
	// stbx r9,r30,r4
	PPC_STORE_U8(ctx.r30.u32 + ctx.r4.u32, ctx.r9.u8);
	// bge cr6,0x8209533c
	if (!ctx.cr6.lt) goto loc_8209533C;
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// add r6,r6,r30
	ctx.r6.u64 = ctx.r6.u64 + ctx.r30.u64;
	// stbx r9,r6,r4
	PPC_STORE_U8(ctx.r6.u32 + ctx.r4.u32, ctx.r9.u8);
loc_8209533C:
	// addic. r3,r3,-1
	ctx.xer.ca = ctx.r3.u32 > 0;
	ctx.r3.s64 = ctx.r3.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// bgt 0x8209531c
	if (ctx.cr0.gt) goto loc_8209531C;
loc_8209534C:
	// cmpw cr6,r4,r28
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r28.s32, ctx.xer);
	// blt cr6,0x820950f4
	if (ctx.cr6.lt) goto loc_820950F4;
	// stb r8,11956(r11)
	PPC_STORE_U8(ctx.r11.u32 + 11956, ctx.r8.u8);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// stw r10,11952(r11)
	PPC_STORE_U32(ctx.r11.u32 + 11952, ctx.r10.u32);
	// stw r5,11012(r11)
	PPC_STORE_U32(ctx.r11.u32 + 11012, ctx.r5.u32);
loc_82095364:
	// b 0x8207c9b4
	__restgprlr_19(ctx, base);
	return;
loc_82095368:
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x82095364
	goto loc_82095364;
}

__attribute__((alias("__imp__sub_82095370"))) PPC_WEAK_FUNC(sub_82095370);
PPC_FUNC_IMPL(__imp__sub_82095370) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c950
	ctx.lr = 0x82095378;
	__savegprlr_14(ctx, base);
	// add r28,r4,r5
	ctx.r28.u64 = ctx.r4.u64 + ctx.r5.u64;
	// lwz r16,11016(r3)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11016);
	// lwz r29,0(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lbz r31,11956(r3)
	ctx.r31.u64 = PPC_LOAD_U8(ctx.r3.u32 + 11956);
	// addi r26,r3,11956
	ctx.r26.s64 = ctx.r3.s64 + 11956;
	// lwz r8,11952(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11952);
	// addi r25,r3,11952
	ctx.r25.s64 = ctx.r3.s64 + 11952;
	// lwz r30,11012(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11012);
	// addi r24,r3,11012
	ctx.r24.s64 = ctx.r3.s64 + 11012;
	// addi r20,r3,3644
	ctx.r20.s64 = ctx.r3.s64 + 3644;
	// addi r19,r3,9020
	ctx.r19.s64 = ctx.r3.s64 + 9020;
	// addi r18,r3,24
	ctx.r18.s64 = ctx.r3.s64 + 24;
	// addi r17,r3,2072
	ctx.r17.s64 = ctx.r3.s64 + 2072;
	// addi r22,r3,2584
	ctx.r22.s64 = ctx.r3.s64 + 2584;
	// addi r21,r3,3256
	ctx.r21.s64 = ctx.r3.s64 + 3256;
	// addi r27,r3,12
	ctx.r27.s64 = ctx.r3.s64 + 12;
	// cmpw cr6,r4,r28
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r28.s32, ctx.xer);
	// bge cr6,0x820956c0
	if (!ctx.cr6.lt) goto loc_820956C0;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r23,16
	ctx.r23.s64 = 16;
	// addi r10,r10,12736
	ctx.r10.s64 = ctx.r10.s64 + 12736;
	// lvx128 v11,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_820953D4:
	// rlwinm r10,r8,11,21,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 11) & 0x7FE;
	// lhax r9,r10,r18
	ctx.r9.s64 = int16_t(PPC_LOAD_U16(ctx.r10.u32 + ctx.r18.u32));
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge 0x82095414
	if (!ctx.cr0.lt) goto loc_82095414;
	// lis r10,32
	ctx.r10.s64 = 2097152;
loc_820953E8:
	// and r7,r10,r8
	ctx.r7.u64 = ctx.r10.u64 & ctx.r8.u64;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// cntlzw r7,r7
	ctx.r7.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r10,r10,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r7,r7,27,5,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x7FFFFFF;
	// xori r7,r7,1
	ctx.r7.u64 = ctx.r7.u64 ^ 1;
	// subf r9,r9,r7
	ctx.r9.s64 = ctx.r7.s64 - ctx.r9.s64;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhax r9,r9,r20
	ctx.r9.s64 = int16_t(PPC_LOAD_U16(ctx.r9.u32 + ctx.r20.u32));
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// blt 0x820953e8
	if (ctx.cr0.lt) goto loc_820953E8;
loc_82095414:
	// cmplw cr6,r30,r16
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r16.u32, ctx.xer);
	// bge cr6,0x820956e0
	if (!ctx.cr6.lt) goto loc_820956E0;
	// lbzx r10,r9,r22
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r22.u32);
	// subf r7,r10,r31
	ctx.r7.s64 = ctx.r31.s64 - ctx.r10.s64;
	// slw r8,r8,r10
	ctx.r8.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r10.u8 & 0x3F));
	// extsb r31,r7
	ctx.r31.s64 = ctx.r7.s8;
	// mr. r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bgt 0x8209545c
	if (ctx.cr0.gt) goto loc_8209545C;
	// lbz r7,1(r30)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r30.u32 + 1);
	// neg r6,r10
	ctx.r6.s64 = -ctx.r10.s64;
	// lbz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r30.u32 + 0);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// rotlwi r7,r7,8
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 8);
	// extsb r31,r10
	ctx.r31.s64 = ctx.r10.s8;
	// or r7,r7,r5
	ctx.r7.u64 = ctx.r7.u64 | ctx.r5.u64;
	// addi r30,r30,2
	ctx.r30.s64 = ctx.r30.s64 + 2;
	// slw r10,r7,r6
	ctx.r10.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r6.u8 & 0x3F));
	// or r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 | ctx.r8.u64;
loc_8209545C:
	// addic. r7,r9,-256
	ctx.xer.ca = ctx.r9.u32 > 255;
	ctx.r7.s64 = ctx.r9.s64 + -256;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bge 0x82095470
	if (!ctx.cr0.lt) goto loc_82095470;
	// stbx r7,r29,r4
	PPC_STORE_U8(ctx.r29.u32 + ctx.r4.u32, ctx.r7.u8);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// b 0x820956b8
	goto loc_820956B8;
loc_82095470:
	// clrlwi r6,r7,29
	ctx.r6.u64 = ctx.r7.u32 & 0x7;
	// cmpwi cr6,r6,7
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 7, ctx.xer);
	// bne cr6,0x82095500
	if (!ctx.cr6.eq) goto loc_82095500;
	// rlwinm r10,r8,9,23,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 9) & 0x1FE;
	// lhax r10,r10,r17
	ctx.r10.s64 = int16_t(PPC_LOAD_U16(ctx.r10.u32 + ctx.r17.u32));
	// cmpwi r10,0
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bge 0x820954bc
	if (!ctx.cr0.lt) goto loc_820954BC;
	// lis r9,128
	ctx.r9.s64 = 8388608;
loc_82095490:
	// and r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 & ctx.r8.u64;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// cntlzw r6,r6
	ctx.r6.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r9,r9,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r6,r6,27,5,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x7FFFFFF;
	// xori r6,r6,1
	ctx.r6.u64 = ctx.r6.u64 ^ 1;
	// subf r10,r10,r6
	ctx.r10.s64 = ctx.r6.s64 - ctx.r10.s64;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhax r10,r10,r19
	ctx.r10.s64 = int16_t(PPC_LOAD_U16(ctx.r10.u32 + ctx.r19.u32));
	// cmpwi r10,0
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// blt 0x82095490
	if (ctx.cr0.lt) goto loc_82095490;
loc_820954BC:
	// lbzx r9,r10,r21
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r21.u32);
	// subf r6,r9,r31
	ctx.r6.s64 = ctx.r31.s64 - ctx.r9.s64;
	// slw r8,r8,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r9.u8 & 0x3F));
	// extsb r31,r6
	ctx.r31.s64 = ctx.r6.s8;
	// mr. r9,r31
	ctx.r9.u64 = ctx.r31.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bgt 0x820954fc
	if (ctx.cr0.gt) goto loc_820954FC;
	// lbz r6,1(r30)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r30.u32 + 1);
	// neg r5,r9
	ctx.r5.s64 = -ctx.r9.s64;
	// lbz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r30.u32 + 0);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// rotlwi r6,r6,8
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r6.u32, 8);
	// extsb r31,r9
	ctx.r31.s64 = ctx.r9.s8;
	// or r6,r6,r3
	ctx.r6.u64 = ctx.r6.u64 | ctx.r3.u64;
	// addi r30,r30,2
	ctx.r30.s64 = ctx.r30.s64 + 2;
	// slw r9,r6,r5
	ctx.r9.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r6.u32 << (ctx.r5.u8 & 0x3F));
	// or r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 | ctx.r8.u64;
loc_820954FC:
	// addi r6,r10,7
	ctx.r6.s64 = ctx.r10.s64 + 7;
loc_82095500:
	// srawi r10,r7,3
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7) != 0);
	ctx.r10.s64 = ctx.r7.s32 >> 3;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// cmpwi cr6,r9,2
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 2, ctx.xer);
	// ble cr6,0x820955c4
	if (!ctx.cr6.gt) goto loc_820955C4;
	// cmpwi cr6,r9,3
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 3, ctx.xer);
	// ble cr6,0x820955ac
	if (!ctx.cr6.gt) goto loc_820955AC;
	// add r10,r9,r11
	ctx.r10.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lbz r10,12004(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 12004);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// subf r10,r10,r31
	ctx.r10.s64 = ctx.r31.s64 - ctx.r10.s64;
	// subfic r7,r3,32
	ctx.xer.ca = ctx.r3.u32 <= 32;
	ctx.r7.s64 = 32 - ctx.r3.s64;
	// extsb r31,r10
	ctx.r31.s64 = ctx.r10.s8;
	// srw r7,r8,r7
	ctx.r7.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r7.u8 & 0x3F));
	// mr. r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// slw r8,r8,r3
	ctx.r8.u64 = ctx.r3.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r3.u8 & 0x3F));
	// bgt 0x82095598
	if (ctx.cr0.gt) goto loc_82095598;
	// lbz r5,1(r30)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r30.u32 + 1);
	// addi r3,r10,16
	ctx.r3.s64 = ctx.r10.s64 + 16;
	// neg r14,r10
	ctx.r14.s64 = -ctx.r10.s64;
	// lbz r15,0(r30)
	ctx.r15.u64 = PPC_LOAD_U8(ctx.r30.u32 + 0);
	// rotlwi r10,r5,8
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 8);
	// extsb r31,r3
	ctx.r31.s64 = ctx.r3.s8;
	// or r5,r10,r15
	ctx.r5.u64 = ctx.r10.u64 | ctx.r15.u64;
	// mr. r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// slw r5,r5,r14
	ctx.r5.u64 = ctx.r14.u8 & 0x20 ? 0 : (ctx.r5.u32 << (ctx.r14.u8 & 0x3F));
	// or r8,r5,r8
	ctx.r8.u64 = ctx.r5.u64 | ctx.r8.u64;
	// addi r30,r30,2
	ctx.r30.s64 = ctx.r30.s64 + 2;
	// bgt 0x82095598
	if (ctx.cr0.gt) goto loc_82095598;
	// lbz r5,1(r30)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r30.u32 + 1);
	// neg r3,r10
	ctx.r3.s64 = -ctx.r10.s64;
	// lbz r31,0(r30)
	ctx.r31.u64 = PPC_LOAD_U8(ctx.r30.u32 + 0);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// rotlwi r5,r5,8
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r5.u32, 8);
	// addi r30,r30,2
	ctx.r30.s64 = ctx.r30.s64 + 2;
	// or r5,r5,r31
	ctx.r5.u64 = ctx.r5.u64 | ctx.r31.u64;
	// extsb r31,r10
	ctx.r31.s64 = ctx.r10.s8;
	// slw r10,r5,r3
	ctx.r10.u64 = ctx.r3.u8 & 0x20 ? 0 : (ctx.r5.u32 << (ctx.r3.u8 & 0x3F));
	// or r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 | ctx.r8.u64;
loc_82095598:
	// addi r10,r9,3014
	ctx.r10.s64 = ctx.r9.s64 + 3014;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// add r9,r10,r7
	ctx.r9.u64 = ctx.r10.u64 + ctx.r7.u64;
	// b 0x820955b0
	goto loc_820955B0;
loc_820955AC:
	// lwz r9,12068(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12068);
loc_820955B0:
	// lwz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// lwz r7,0(r27)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// stw r10,8(r27)
	PPC_STORE_U32(ctx.r27.u32 + 8, ctx.r10.u32);
	// stw r7,4(r27)
	PPC_STORE_U32(ctx.r27.u32 + 4, ctx.r7.u32);
	// b 0x820955dc
	goto loc_820955DC;
loc_820955C4:
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// lwzx r9,r10,r27
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r27.u32);
	// beq cr6,0x820955e0
	if (ctx.cr6.eq) goto loc_820955E0;
	// lwz r7,0(r27)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// stwx r7,r10,r27
	PPC_STORE_U32(ctx.r10.u32 + ctx.r27.u32, ctx.r7.u32);
loc_820955DC:
	// stw r9,0(r27)
	PPC_STORE_U32(ctx.r27.u32 + 0, ctx.r9.u32);
loc_820955E0:
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r9,r9,r4
	ctx.r9.s64 = ctx.r4.s64 - ctx.r9.s64;
	// addi r10,r6,2
	ctx.r10.s64 = ctx.r6.s64 + 2;
	// and r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 & ctx.r7.u64;
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// blt cr6,0x82095600
	if (ctx.cr6.lt) goto loc_82095600;
	// mr r7,r23
	ctx.r7.u64 = ctx.r23.u64;
loc_82095600:
	// subf r6,r9,r4
	ctx.r6.s64 = ctx.r4.s64 - ctx.r9.s64;
	// cmplw cr6,r6,r7
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x8209562c
	if (!ctx.cr6.lt) goto loc_8209562C;
	// add r9,r9,r29
	ctx.r9.u64 = ctx.r9.u64 + ctx.r29.u64;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
loc_82095614:
	// lbzu r7,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r7.u64 = PPC_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stbx r7,r29,r4
	PPC_STORE_U8(ctx.r29.u32 + ctx.r4.u32, ctx.r7.u8);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// bgt 0x82095614
	if (ctx.cr0.gt) goto loc_82095614;
	// b 0x820956b8
	goto loc_820956B8;
loc_8209562C:
	// cmpwi cr6,r10,16
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 16, ctx.xer);
	// ble cr6,0x8209567c
	if (!ctx.cr6.gt) goto loc_8209567C;
	// addi r7,r10,-17
	ctx.r7.s64 = ctx.r10.s64 + -17;
	// add r3,r29,r4
	ctx.r3.u64 = ctx.r29.u64 + ctx.r4.u64;
	// rlwinm r7,r7,28,4,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 28) & 0xFFFFFFF;
	// add r5,r9,r29
	ctx.r5.u64 = ctx.r9.u64 + ctx.r29.u64;
	// addi r6,r7,1
	ctx.r6.s64 = ctx.r7.s64 + 1;
	// rlwinm r7,r6,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// add r4,r7,r4
	ctx.r4.u64 = ctx.r7.u64 + ctx.r4.u64;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// subf r10,r7,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r7.s64;
	// add r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 + ctx.r9.u64;
loc_8209565C:
	// lvlx128 v63,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvrx128 v62,r23,r5
	temp.u32 = ctx.r23.u32 + ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// addi r5,r5,16
	ctx.r5.s64 = ctx.r5.s64 + 16;
	// vor128 v63,v63,v62
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// stvlx128 v63,r0,r3
	ea = ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		PPC_STORE_U8(ea + i, ctx.v63.u8[15 - i]);
	// stvrx128 v63,r3,r23
	ea = ctx.r3.u32 + ctx.r23.u32;
	for (size_t i = 0; i < (ea & 0xF); i++)
		PPC_STORE_U8(ea - i - 1, ctx.v63.u8[i]);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bdnz 0x8209565c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8209565C;
loc_8209567C:
	// lvlx128 v63,r9,r29
	temp.u32 = ctx.r9.u32 + ctx.r29.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// add r7,r29,r4
	ctx.r7.u64 = ctx.r29.u64 + ctx.r4.u64;
	// add r9,r9,r29
	ctx.r9.u64 = ctx.r9.u64 + ctx.r29.u64;
	// lvlx128 v62,r29,r4
	temp.u32 = ctx.r29.u32 + ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r6,-1
	ctx.r6.s64 = -1;
	// lvrx128 v61,r23,r7
	temp.u32 = ctx.r23.u32 + ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvrx128 v60,r23,r9
	temp.u32 = ctx.r23.u32 + ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v0,v62,v61
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8)));
	// lvsr v12,r10,r6
	temp.u32 = ctx.r10.u32 + ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableR[(temp.u32 & 0xF) * 16]));
	// vor128 v13,v63,v60
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v60.u8)));
	// vcmpgtub v12,v11,v12
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_cmpgt_epu8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)));
	// vsel v12,v0,v13,v12
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// stvlx v12,r29,r4
	ea = ctx.r29.u32 + ctx.r4.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		PPC_STORE_U8(ea + i, ctx.v12.u8[15 - i]);
	// add r4,r10,r4
	ctx.r4.u64 = ctx.r10.u64 + ctx.r4.u64;
	// stvrx v12,r7,r23
	ea = ctx.r7.u32 + ctx.r23.u32;
	for (size_t i = 0; i < (ea & 0xF); i++)
		PPC_STORE_U8(ea - i - 1, ctx.v12.u8[i]);
loc_820956B8:
	// cmpw cr6,r4,r28
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r28.s32, ctx.xer);
	// blt cr6,0x820953d4
	if (ctx.cr6.lt) goto loc_820953D4;
loc_820956C0:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r3,r28,r4
	ctx.r3.s64 = ctx.r4.s64 - ctx.r28.s64;
	// stb r31,0(r26)
	PPC_STORE_U8(ctx.r26.u32 + 0, ctx.r31.u8);
	// and r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 & ctx.r4.u64;
	// stw r8,0(r25)
	PPC_STORE_U32(ctx.r25.u32 + 0, ctx.r8.u32);
	// stw r30,0(r24)
	PPC_STORE_U32(ctx.r24.u32 + 0, ctx.r30.u32);
	// stw r10,11960(r11)
	PPC_STORE_U32(ctx.r11.u32 + 11960, ctx.r10.u32);
loc_820956DC:
	// b 0x8207c9a0
	__restgprlr_14(ctx, base);
	return;
loc_820956E0:
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x820956dc
	goto loc_820956DC;
}

__attribute__((alias("__imp__sub_820956E8"))) PPC_WEAK_FUNC(sub_820956E8);
PPC_FUNC_IMPL(__imp__sub_820956E8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820956F0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// cmpwi cr6,r4,257
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 257, ctx.xer);
	// bge cr6,0x82095740
	if (!ctx.cr6.lt) goto loc_82095740;
	// subfic r5,r4,257
	ctx.xer.ca = ctx.r4.u32 <= 257;
	ctx.r5.s64 = 257 - ctx.r4.s64;
	// cmpw cr6,r5,r31
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r31.s32, ctx.xer);
	// blt cr6,0x82095718
	if (ctx.cr6.lt) goto loc_82095718;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
loc_82095718:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820950b0
	ctx.lr = 0x82095724;
	sub_820950B0(ctx, base);
	// subf r11,r3,r30
	ctx.r11.s64 = ctx.r30.s64 - ctx.r3.s64;
	// stw r3,11960(r29)
	PPC_STORE_U32(ctx.r29.u32 + 11960, ctx.r3.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// add. r31,r11,r31
	ctx.r31.u64 = ctx.r11.u64 + ctx.r31.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bgt 0x82095740
	if (ctx.cr0.gt) goto loc_82095740;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x82095750
	goto loc_82095750;
loc_82095740:
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82095370
	ctx.lr = 0x82095750;
	sub_82095370(ctx, base);
loc_82095750:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82095758"))) PPC_WEAK_FUNC(sub_82095758);
PPC_FUNC_IMPL(__imp__sub_82095758) {
	PPC_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c960
	ctx.lr = 0x82095760;
	__savegprlr_18(ctx, base);
	// lwz r19,11016(r3)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11016);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r30,0(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// add r26,r4,r5
	ctx.r26.u64 = ctx.r4.u64 + ctx.r5.u64;
	// lbz r9,11956(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 11956);
	// addi r23,r3,3644
	ctx.r23.s64 = ctx.r3.s64 + 3644;
	// lwz r10,11952(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11952);
	// addi r22,r3,9020
	ctx.r22.s64 = ctx.r3.s64 + 9020;
	// lwz r31,11012(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11012);
	// addi r21,r3,24
	ctx.r21.s64 = ctx.r3.s64 + 24;
	// addi r20,r3,2072
	ctx.r20.s64 = ctx.r3.s64 + 2072;
	// addi r25,r3,2584
	ctx.r25.s64 = ctx.r3.s64 + 2584;
	// addi r24,r3,3256
	ctx.r24.s64 = ctx.r3.s64 + 3256;
	// addi r28,r3,3508
	ctx.r28.s64 = ctx.r3.s64 + 3508;
	// addi r27,r3,3636
	ctx.r27.s64 = ctx.r3.s64 + 3636;
	// addi r29,r3,12
	ctx.r29.s64 = ctx.r3.s64 + 12;
	// b 0x82095aa8
	goto loc_82095AA8;
loc_820957A4:
	// rlwinm r8,r10,11,21,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 11) & 0x7FE;
	// lhax r7,r8,r21
	ctx.r7.s64 = int16_t(PPC_LOAD_U16(ctx.r8.u32 + ctx.r21.u32));
	// cmpwi r7,0
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bge 0x820957e4
	if (!ctx.cr0.lt) goto loc_820957E4;
	// lis r8,32
	ctx.r8.s64 = 2097152;
loc_820957B8:
	// and r6,r8,r10
	ctx.r6.u64 = ctx.r8.u64 & ctx.r10.u64;
	// rlwinm r7,r7,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// cntlzw r6,r6
	ctx.r6.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r8,r8,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r6,r6,27,5,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x7FFFFFF;
	// xori r6,r6,1
	ctx.r6.u64 = ctx.r6.u64 ^ 1;
	// subf r7,r7,r6
	ctx.r7.s64 = ctx.r6.s64 - ctx.r7.s64;
	// rlwinm r7,r7,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// lhax r7,r7,r23
	ctx.r7.s64 = int16_t(PPC_LOAD_U16(ctx.r7.u32 + ctx.r23.u32));
	// cmpwi r7,0
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// blt 0x820957b8
	if (ctx.cr0.lt) goto loc_820957B8;
loc_820957E4:
	// cmplw cr6,r31,r19
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r19.u32, ctx.xer);
	// bge cr6,0x82095ac4
	if (!ctx.cr6.lt) goto loc_82095AC4;
	// lbzx r8,r7,r25
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r25.u32);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// slw r10,r10,r8
	ctx.r10.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r8.u8 & 0x3F));
	// extsb r9,r9
	ctx.r9.s64 = ctx.r9.s8;
	// mr. r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bgt 0x8209582c
	if (ctx.cr0.gt) goto loc_8209582C;
	// lbz r9,1(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// neg r6,r8
	ctx.r6.s64 = -ctx.r8.s64;
	// lbz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// rotlwi r9,r9,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// addi r31,r31,2
	ctx.r31.s64 = ctx.r31.s64 + 2;
	// or r5,r9,r5
	ctx.r5.u64 = ctx.r9.u64 | ctx.r5.u64;
	// extsb r9,r8
	ctx.r9.s64 = ctx.r8.s8;
	// slw r8,r5,r6
	ctx.r8.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r5.u32 << (ctx.r6.u8 & 0x3F));
	// or r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 | ctx.r10.u64;
loc_8209582C:
	// addic. r6,r7,-256
	ctx.xer.ca = ctx.r7.u32 > 255;
	ctx.r6.s64 = ctx.r7.s64 + -256;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bge 0x82095850
	if (!ctx.cr0.lt) goto loc_82095850;
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// clrlwi r7,r6,24
	ctx.r7.u64 = ctx.r6.u32 & 0xFF;
	// add r8,r8,r30
	ctx.r8.u64 = ctx.r8.u64 + ctx.r30.u64;
	// stbx r7,r30,r4
	PPC_STORE_U8(ctx.r30.u32 + ctx.r4.u32, ctx.r7.u8);
	// stbx r7,r8,r4
	PPC_STORE_U8(ctx.r8.u32 + ctx.r4.u32, ctx.r7.u8);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// b 0x82095aa8
	goto loc_82095AA8;
loc_82095850:
	// clrlwi r5,r6,29
	ctx.r5.u64 = ctx.r6.u32 & 0x7;
	// cmpwi cr6,r5,7
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 7, ctx.xer);
	// bne cr6,0x820958e0
	if (!ctx.cr6.eq) goto loc_820958E0;
	// rlwinm r8,r10,9,23,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 9) & 0x1FE;
	// lhax r8,r8,r20
	ctx.r8.s64 = int16_t(PPC_LOAD_U16(ctx.r8.u32 + ctx.r20.u32));
	// cmpwi r8,0
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bge 0x8209589c
	if (!ctx.cr0.lt) goto loc_8209589C;
	// lis r7,128
	ctx.r7.s64 = 8388608;
loc_82095870:
	// and r5,r7,r10
	ctx.r5.u64 = ctx.r7.u64 & ctx.r10.u64;
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// cntlzw r5,r5
	ctx.r5.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r7,r7,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r5,r5,27,5,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x7FFFFFF;
	// xori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 ^ 1;
	// subf r8,r8,r5
	ctx.r8.s64 = ctx.r5.s64 - ctx.r8.s64;
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lhax r8,r8,r22
	ctx.r8.s64 = int16_t(PPC_LOAD_U16(ctx.r8.u32 + ctx.r22.u32));
	// cmpwi r8,0
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// blt 0x82095870
	if (ctx.cr0.lt) goto loc_82095870;
loc_8209589C:
	// lbzx r7,r8,r24
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r24.u32);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// slw r10,r10,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r7.u8 & 0x3F));
	// extsb r9,r9
	ctx.r9.s64 = ctx.r9.s8;
	// mr. r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bgt 0x820958dc
	if (ctx.cr0.gt) goto loc_820958DC;
	// lbz r9,1(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// neg r5,r7
	ctx.r5.s64 = -ctx.r7.s64;
	// lbz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// addi r7,r7,16
	ctx.r7.s64 = ctx.r7.s64 + 16;
	// rotlwi r9,r9,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// addi r31,r31,2
	ctx.r31.s64 = ctx.r31.s64 + 2;
	// or r3,r9,r3
	ctx.r3.u64 = ctx.r9.u64 | ctx.r3.u64;
	// extsb r9,r7
	ctx.r9.s64 = ctx.r7.s8;
	// slw r7,r3,r5
	ctx.r7.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r3.u32 << (ctx.r5.u8 & 0x3F));
	// or r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 | ctx.r10.u64;
loc_820958DC:
	// addi r5,r8,7
	ctx.r5.s64 = ctx.r8.s64 + 7;
loc_820958E0:
	// srawi r8,r6,3
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7) != 0);
	ctx.r8.s64 = ctx.r6.s32 >> 3;
	// extsb r6,r8
	ctx.r6.s64 = ctx.r8.s8;
	// cmpwi cr6,r6,2
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 2, ctx.xer);
	// ble cr6,0x82095a58
	if (!ctx.cr6.gt) goto loc_82095A58;
	// add r8,r6,r11
	ctx.r8.u64 = ctx.r6.u64 + ctx.r11.u64;
	// lbz r7,12004(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 12004);
	// cmplwi cr6,r7,3
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 3, ctx.xer);
	// blt cr6,0x820959d8
	if (ctx.cr6.lt) goto loc_820959D8;
	// addic. r7,r7,-3
	ctx.xer.ca = ctx.r7.u32 > 2;
	ctx.r7.s64 = ctx.r7.s64 + -3;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq 0x82095968
	if (ctx.cr0.eq) goto loc_82095968;
	// lbz r8,12004(r8)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r8.u32 + 12004);
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// extsb r3,r8
	ctx.r3.s64 = ctx.r8.s8;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// subf r8,r3,r7
	ctx.r8.s64 = ctx.r7.s64 - ctx.r3.s64;
	// subfic r7,r9,35
	ctx.xer.ca = ctx.r9.u32 <= 35;
	ctx.r7.s64 = 35 - ctx.r9.s64;
	// addi r8,r8,3
	ctx.r8.s64 = ctx.r8.s64 + 3;
	// addi r3,r9,-3
	ctx.r3.s64 = ctx.r9.s64 + -3;
	// extsb r9,r8
	ctx.r9.s64 = ctx.r8.s8;
	// srw r7,r10,r7
	ctx.r7.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r7.u8 & 0x3F));
	// mr. r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// slw r10,r10,r3
	ctx.r10.u64 = ctx.r3.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r3.u8 & 0x3F));
	// bgt 0x8209596c
	if (ctx.cr0.gt) goto loc_8209596C;
	// lbz r9,1(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// neg r3,r8
	ctx.r3.s64 = -ctx.r8.s64;
	// lbz r18,0(r31)
	ctx.r18.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// rotlwi r9,r9,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// addi r31,r31,2
	ctx.r31.s64 = ctx.r31.s64 + 2;
	// or r18,r9,r18
	ctx.r18.u64 = ctx.r9.u64 | ctx.r18.u64;
	// extsb r9,r8
	ctx.r9.s64 = ctx.r8.s8;
	// slw r8,r18,r3
	ctx.r8.u64 = ctx.r3.u8 & 0x20 ? 0 : (ctx.r18.u32 << (ctx.r3.u8 & 0x3F));
	// or r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 | ctx.r10.u64;
	// b 0x8209596c
	goto loc_8209596C;
loc_82095968:
	// li r7,0
	ctx.r7.s64 = 0;
loc_8209596C:
	// rlwinm r3,r10,7,25,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 7) & 0x7F;
	// rlwinm r8,r7,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r7,r6,3014
	ctx.r7.s64 = ctx.r6.s64 + 3014;
	// mr r18,r9
	ctx.r18.u64 = ctx.r9.u64;
	// rlwinm r9,r7,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lbzx r7,r3,r28
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r28.u32);
	// extsb r7,r7
	ctx.r7.s64 = ctx.r7.s8;
	// lwzx r9,r9,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// add r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lbzx r9,r7,r27
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r27.u32);
	// subf r8,r9,r18
	ctx.r8.s64 = ctx.r18.s64 - ctx.r9.s64;
	// slw r10,r10,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r9.u8 & 0x3F));
	// extsb r9,r8
	ctx.r9.s64 = ctx.r8.s8;
	// mr. r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bgt 0x820959d0
	if (ctx.cr0.gt) goto loc_820959D0;
	// lbz r9,1(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// neg r3,r8
	ctx.r3.s64 = -ctx.r8.s64;
	// lbz r18,0(r31)
	ctx.r18.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// rotlwi r9,r9,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// addi r31,r31,2
	ctx.r31.s64 = ctx.r31.s64 + 2;
	// or r18,r9,r18
	ctx.r18.u64 = ctx.r9.u64 | ctx.r18.u64;
	// extsb r9,r8
	ctx.r9.s64 = ctx.r8.s8;
	// slw r8,r18,r3
	ctx.r8.u64 = ctx.r3.u8 & 0x20 ? 0 : (ctx.r18.u32 << (ctx.r3.u8 & 0x3F));
	// or r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 | ctx.r10.u64;
loc_820959D0:
	// add r8,r6,r7
	ctx.r8.u64 = ctx.r6.u64 + ctx.r7.u64;
	// b 0x82095a44
	goto loc_82095A44;
loc_820959D8:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82095a40
	if (ctx.cr6.eq) goto loc_82095A40;
	// lbz r8,12004(r8)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r8.u32 + 12004);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// subfic r8,r8,32
	ctx.xer.ca = ctx.r8.u32 <= 32;
	ctx.r8.s64 = 32 - ctx.r8.s64;
	// extsb r9,r9
	ctx.r9.s64 = ctx.r9.s8;
	// srw r7,r10,r8
	ctx.r7.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r8.u8 & 0x3F));
	// mr. r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// slw r10,r10,r3
	ctx.r10.u64 = ctx.r3.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r3.u8 & 0x3F));
	// bgt 0x82095a2c
	if (ctx.cr0.gt) goto loc_82095A2C;
	// lbz r9,1(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// neg r3,r8
	ctx.r3.s64 = -ctx.r8.s64;
	// lbz r18,0(r31)
	ctx.r18.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// rotlwi r9,r9,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// addi r31,r31,2
	ctx.r31.s64 = ctx.r31.s64 + 2;
	// or r18,r9,r18
	ctx.r18.u64 = ctx.r9.u64 | ctx.r18.u64;
	// extsb r9,r8
	ctx.r9.s64 = ctx.r8.s8;
	// slw r8,r18,r3
	ctx.r8.u64 = ctx.r3.u8 & 0x20 ? 0 : (ctx.r18.u32 << (ctx.r3.u8 & 0x3F));
	// or r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 | ctx.r10.u64;
loc_82095A2C:
	// addi r8,r6,3014
	ctx.r8.s64 = ctx.r6.s64 + 3014;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r8,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// b 0x82095a44
	goto loc_82095A44;
loc_82095A40:
	// li r8,1
	ctx.r8.s64 = 1;
loc_82095A44:
	// lwz r7,4(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r6,0(r29)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// stw r7,8(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8, ctx.r7.u32);
	// stw r6,4(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4, ctx.r6.u32);
	// b 0x82095a68
	goto loc_82095A68;
loc_82095A58:
	// rlwinm r7,r6,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,0(r29)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lwzx r8,r7,r29
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r29.u32);
	// stwx r6,r7,r29
	PPC_STORE_U32(ctx.r7.u32 + ctx.r29.u32, ctx.r6.u32);
loc_82095A68:
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// addi r5,r5,2
	ctx.r5.s64 = ctx.r5.s64 + 2;
	// stw r8,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r8.u32);
	// subf r7,r8,r4
	ctx.r7.s64 = ctx.r4.s64 - ctx.r8.s64;
loc_82095A78:
	// and r8,r7,r3
	ctx.r8.u64 = ctx.r7.u64 & ctx.r3.u64;
	// cmpwi cr6,r4,257
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 257, ctx.xer);
	// lbzx r8,r8,r30
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r30.u32);
	// stbx r8,r30,r4
	PPC_STORE_U8(ctx.r30.u32 + ctx.r4.u32, ctx.r8.u8);
	// bge cr6,0x82095a98
	if (!ctx.cr6.lt) goto loc_82095A98;
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// add r6,r6,r30
	ctx.r6.u64 = ctx.r6.u64 + ctx.r30.u64;
	// stbx r8,r6,r4
	PPC_STORE_U8(ctx.r6.u32 + ctx.r4.u32, ctx.r8.u8);
loc_82095A98:
	// addic. r5,r5,-1
	ctx.xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// bgt 0x82095a78
	if (ctx.cr0.gt) goto loc_82095A78;
loc_82095AA8:
	// cmpw cr6,r4,r26
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r26.s32, ctx.xer);
	// blt cr6,0x820957a4
	if (ctx.cr6.lt) goto loc_820957A4;
	// stb r9,11956(r11)
	PPC_STORE_U8(ctx.r11.u32 + 11956, ctx.r9.u8);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// stw r10,11952(r11)
	PPC_STORE_U32(ctx.r11.u32 + 11952, ctx.r10.u32);
	// stw r31,11012(r11)
	PPC_STORE_U32(ctx.r11.u32 + 11012, ctx.r31.u32);
loc_82095AC0:
	// b 0x8207c9b0
	__restgprlr_18(ctx, base);
	return;
loc_82095AC4:
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x82095ac0
	goto loc_82095AC0;
}

__attribute__((alias("__imp__sub_82095ACC"))) PPC_WEAK_FUNC(sub_82095ACC);
PPC_FUNC_IMPL(__imp__sub_82095ACC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82095AD0"))) PPC_WEAK_FUNC(sub_82095AD0);
PPC_FUNC_IMPL(__imp__sub_82095AD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c950
	ctx.lr = 0x82095AD8;
	__savegprlr_14(ctx, base);
	// add r28,r4,r5
	ctx.r28.u64 = ctx.r4.u64 + ctx.r5.u64;
	// lwz r14,11016(r3)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11016);
	// lwz r29,0(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lbz r8,11956(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 11956);
	// addi r26,r3,11956
	ctx.r26.s64 = ctx.r3.s64 + 11956;
	// lwz r10,11952(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11952);
	// addi r25,r3,11952
	ctx.r25.s64 = ctx.r3.s64 + 11952;
	// lwz r30,11012(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11012);
	// addi r24,r3,11012
	ctx.r24.s64 = ctx.r3.s64 + 11012;
	// addi r18,r3,3644
	ctx.r18.s64 = ctx.r3.s64 + 3644;
	// addi r17,r3,9020
	ctx.r17.s64 = ctx.r3.s64 + 9020;
	// addi r16,r3,24
	ctx.r16.s64 = ctx.r3.s64 + 24;
	// addi r15,r3,2072
	ctx.r15.s64 = ctx.r3.s64 + 2072;
	// addi r20,r3,2584
	ctx.r20.s64 = ctx.r3.s64 + 2584;
	// addi r19,r3,3256
	ctx.r19.s64 = ctx.r3.s64 + 3256;
	// addi r23,r3,3508
	ctx.r23.s64 = ctx.r3.s64 + 3508;
	// addi r22,r3,3636
	ctx.r22.s64 = ctx.r3.s64 + 3636;
	// addi r27,r3,12
	ctx.r27.s64 = ctx.r3.s64 + 12;
	// cmpw cr6,r4,r28
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r28.s32, ctx.xer);
	// bge cr6,0x82095ed0
	if (!ctx.cr6.lt) goto loc_82095ED0;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r21,16
	ctx.r21.s64 = 16;
	// addi r9,r9,12736
	ctx.r9.s64 = ctx.r9.s64 + 12736;
	// lvx128 v11,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82095B3C:
	// rlwinm r9,r10,11,21,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 11) & 0x7FE;
	// lhax r7,r9,r16
	ctx.r7.s64 = int16_t(PPC_LOAD_U16(ctx.r9.u32 + ctx.r16.u32));
	// cmpwi r7,0
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bge 0x82095b7c
	if (!ctx.cr0.lt) goto loc_82095B7C;
	// lis r9,32
	ctx.r9.s64 = 2097152;
loc_82095B50:
	// and r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 & ctx.r10.u64;
	// rlwinm r7,r7,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// cntlzw r6,r6
	ctx.r6.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r9,r9,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r6,r6,27,5,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x7FFFFFF;
	// xori r6,r6,1
	ctx.r6.u64 = ctx.r6.u64 ^ 1;
	// subf r7,r7,r6
	ctx.r7.s64 = ctx.r6.s64 - ctx.r7.s64;
	// rlwinm r7,r7,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// lhax r7,r7,r18
	ctx.r7.s64 = int16_t(PPC_LOAD_U16(ctx.r7.u32 + ctx.r18.u32));
	// cmpwi r7,0
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// blt 0x82095b50
	if (ctx.cr0.lt) goto loc_82095B50;
loc_82095B7C:
	// cmplw cr6,r30,r14
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r14.u32, ctx.xer);
	// bge cr6,0x82095ef0
	if (!ctx.cr6.lt) goto loc_82095EF0;
	// lbzx r9,r7,r20
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r20.u32);
	// subf r8,r9,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r9.s64;
	// slw r10,r10,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r9.u8 & 0x3F));
	// extsb r8,r8
	ctx.r8.s64 = ctx.r8.s8;
	// mr. r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bgt 0x82095bc4
	if (ctx.cr0.gt) goto loc_82095BC4;
	// lbz r8,1(r30)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r30.u32 + 1);
	// neg r6,r9
	ctx.r6.s64 = -ctx.r9.s64;
	// lbz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r30.u32 + 0);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// rotlwi r8,r8,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// addi r30,r30,2
	ctx.r30.s64 = ctx.r30.s64 + 2;
	// or r5,r8,r5
	ctx.r5.u64 = ctx.r8.u64 | ctx.r5.u64;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// slw r9,r5,r6
	ctx.r9.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r5.u32 << (ctx.r6.u8 & 0x3F));
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
loc_82095BC4:
	// addic. r6,r7,-256
	ctx.xer.ca = ctx.r7.u32 > 255;
	ctx.r6.s64 = ctx.r7.s64 + -256;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bge 0x82095bd8
	if (!ctx.cr0.lt) goto loc_82095BD8;
	// stbx r6,r29,r4
	PPC_STORE_U8(ctx.r29.u32 + ctx.r4.u32, ctx.r6.u8);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// b 0x82095ec8
	goto loc_82095EC8;
loc_82095BD8:
	// clrlwi r5,r6,29
	ctx.r5.u64 = ctx.r6.u32 & 0x7;
	// cmpwi cr6,r5,7
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 7, ctx.xer);
	// bne cr6,0x82095c68
	if (!ctx.cr6.eq) goto loc_82095C68;
	// rlwinm r9,r10,9,23,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 9) & 0x1FE;
	// lhax r9,r9,r15
	ctx.r9.s64 = int16_t(PPC_LOAD_U16(ctx.r9.u32 + ctx.r15.u32));
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge 0x82095c24
	if (!ctx.cr0.lt) goto loc_82095C24;
	// lis r7,128
	ctx.r7.s64 = 8388608;
loc_82095BF8:
	// and r5,r7,r10
	ctx.r5.u64 = ctx.r7.u64 & ctx.r10.u64;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// cntlzw r5,r5
	ctx.r5.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r7,r7,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r5,r5,27,5,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x7FFFFFF;
	// xori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 ^ 1;
	// subf r9,r9,r5
	ctx.r9.s64 = ctx.r5.s64 - ctx.r9.s64;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhax r9,r9,r17
	ctx.r9.s64 = int16_t(PPC_LOAD_U16(ctx.r9.u32 + ctx.r17.u32));
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// blt 0x82095bf8
	if (ctx.cr0.lt) goto loc_82095BF8;
loc_82095C24:
	// lbzx r7,r9,r19
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r19.u32);
	// subf r8,r7,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r7.s64;
	// slw r10,r10,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r7.u8 & 0x3F));
	// extsb r8,r8
	ctx.r8.s64 = ctx.r8.s8;
	// mr. r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bgt 0x82095c64
	if (ctx.cr0.gt) goto loc_82095C64;
	// lbz r8,1(r30)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r30.u32 + 1);
	// neg r5,r7
	ctx.r5.s64 = -ctx.r7.s64;
	// lbz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r30.u32 + 0);
	// addi r7,r7,16
	ctx.r7.s64 = ctx.r7.s64 + 16;
	// rotlwi r8,r8,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// addi r30,r30,2
	ctx.r30.s64 = ctx.r30.s64 + 2;
	// or r3,r8,r3
	ctx.r3.u64 = ctx.r8.u64 | ctx.r3.u64;
	// extsb r8,r7
	ctx.r8.s64 = ctx.r7.s8;
	// slw r7,r3,r5
	ctx.r7.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r3.u32 << (ctx.r5.u8 & 0x3F));
	// or r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 | ctx.r10.u64;
loc_82095C64:
	// addi r5,r9,7
	ctx.r5.s64 = ctx.r9.s64 + 7;
loc_82095C68:
	// srawi r9,r6,3
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7) != 0);
	ctx.r9.s64 = ctx.r6.s32 >> 3;
	// extsb r6,r9
	ctx.r6.s64 = ctx.r9.s8;
	// cmpwi cr6,r6,2
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 2, ctx.xer);
	// ble cr6,0x82095de4
	if (!ctx.cr6.gt) goto loc_82095DE4;
	// add r9,r6,r11
	ctx.r9.u64 = ctx.r6.u64 + ctx.r11.u64;
	// lbz r7,12004(r9)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + 12004);
	// cmplwi cr6,r7,3
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 3, ctx.xer);
	// blt cr6,0x82095d5c
	if (ctx.cr6.lt) goto loc_82095D5C;
	// addic. r7,r7,-3
	ctx.xer.ca = ctx.r7.u32 > 2;
	ctx.r7.s64 = ctx.r7.s64 + -3;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq 0x82095cec
	if (ctx.cr0.eq) goto loc_82095CEC;
	// lbz r9,12004(r9)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r9.u32 + 12004);
	// extsb r8,r8
	ctx.r8.s64 = ctx.r8.s8;
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// addi r3,r9,-3
	ctx.r3.s64 = ctx.r9.s64 + -3;
	// subf r8,r7,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r7.s64;
	// subfic r7,r9,35
	ctx.xer.ca = ctx.r9.u32 <= 35;
	ctx.r7.s64 = 35 - ctx.r9.s64;
	// addi r8,r8,3
	ctx.r8.s64 = ctx.r8.s64 + 3;
	// srw r7,r10,r7
	ctx.r7.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r7.u8 & 0x3F));
	// extsb r8,r8
	ctx.r8.s64 = ctx.r8.s8;
	// slw r10,r10,r3
	ctx.r10.u64 = ctx.r3.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r3.u8 & 0x3F));
	// mr. r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bgt 0x82095cf0
	if (ctx.cr0.gt) goto loc_82095CF0;
	// lbz r8,1(r30)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r30.u32 + 1);
	// neg r3,r9
	ctx.r3.s64 = -ctx.r9.s64;
	// lbz r31,0(r30)
	ctx.r31.u64 = PPC_LOAD_U8(ctx.r30.u32 + 0);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// rotlwi r8,r8,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// addi r30,r30,2
	ctx.r30.s64 = ctx.r30.s64 + 2;
	// or r31,r8,r31
	ctx.r31.u64 = ctx.r8.u64 | ctx.r31.u64;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// slw r9,r31,r3
	ctx.r9.u64 = ctx.r3.u8 & 0x20 ? 0 : (ctx.r31.u32 << (ctx.r3.u8 & 0x3F));
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
	// b 0x82095cf0
	goto loc_82095CF0;
loc_82095CEC:
	// li r7,0
	ctx.r7.s64 = 0;
loc_82095CF0:
	// rlwinm r3,r10,7,25,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 7) & 0x7F;
	// rlwinm r9,r7,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r7,r6,3014
	ctx.r7.s64 = ctx.r6.s64 + 3014;
	// mr r31,r8
	ctx.r31.u64 = ctx.r8.u64;
	// rlwinm r8,r7,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lbzx r7,r3,r23
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r23.u32);
	// extsb r7,r7
	ctx.r7.s64 = ctx.r7.s8;
	// lwzx r8,r8,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
	// add r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lbzx r9,r7,r22
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r22.u32);
	// subf r8,r9,r31
	ctx.r8.s64 = ctx.r31.s64 - ctx.r9.s64;
	// slw r10,r10,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r9.u8 & 0x3F));
	// extsb r8,r8
	ctx.r8.s64 = ctx.r8.s8;
	// mr. r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bgt 0x82095d54
	if (ctx.cr0.gt) goto loc_82095D54;
	// lbz r8,1(r30)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r30.u32 + 1);
	// neg r3,r9
	ctx.r3.s64 = -ctx.r9.s64;
	// lbz r31,0(r30)
	ctx.r31.u64 = PPC_LOAD_U8(ctx.r30.u32 + 0);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// rotlwi r8,r8,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// addi r30,r30,2
	ctx.r30.s64 = ctx.r30.s64 + 2;
	// or r31,r8,r31
	ctx.r31.u64 = ctx.r8.u64 | ctx.r31.u64;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// slw r9,r31,r3
	ctx.r9.u64 = ctx.r3.u8 & 0x20 ? 0 : (ctx.r31.u32 << (ctx.r3.u8 & 0x3F));
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
loc_82095D54:
	// add r9,r6,r7
	ctx.r9.u64 = ctx.r6.u64 + ctx.r7.u64;
	// b 0x82095dd0
	goto loc_82095DD0;
loc_82095D5C:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82095dc4
	if (ctx.cr6.eq) goto loc_82095DC4;
	// lbz r9,12004(r9)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r9.u32 + 12004);
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// subf r9,r9,r8
	ctx.r9.s64 = ctx.r8.s64 - ctx.r9.s64;
	// subfic r7,r3,32
	ctx.xer.ca = ctx.r3.u32 <= 32;
	ctx.r7.s64 = 32 - ctx.r3.s64;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// srw r7,r10,r7
	ctx.r7.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r7.u8 & 0x3F));
	// mr. r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// slw r10,r10,r3
	ctx.r10.u64 = ctx.r3.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r3.u8 & 0x3F));
	// bgt 0x82095db0
	if (ctx.cr0.gt) goto loc_82095DB0;
	// lbz r8,1(r30)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r30.u32 + 1);
	// neg r3,r9
	ctx.r3.s64 = -ctx.r9.s64;
	// lbz r31,0(r30)
	ctx.r31.u64 = PPC_LOAD_U8(ctx.r30.u32 + 0);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// rotlwi r8,r8,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// addi r30,r30,2
	ctx.r30.s64 = ctx.r30.s64 + 2;
	// or r31,r8,r31
	ctx.r31.u64 = ctx.r8.u64 | ctx.r31.u64;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// slw r9,r31,r3
	ctx.r9.u64 = ctx.r3.u8 & 0x20 ? 0 : (ctx.r31.u32 << (ctx.r3.u8 & 0x3F));
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
loc_82095DB0:
	// addi r9,r6,3014
	ctx.r9.s64 = ctx.r6.s64 + 3014;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r9,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// b 0x82095dd0
	goto loc_82095DD0;
loc_82095DC4:
	// addi r9,r6,3014
	ctx.r9.s64 = ctx.r6.s64 + 3014;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r9,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
loc_82095DD0:
	// lwz r7,4(r27)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// lwz r6,0(r27)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// stw r7,8(r27)
	PPC_STORE_U32(ctx.r27.u32 + 8, ctx.r7.u32);
	// stw r6,4(r27)
	PPC_STORE_U32(ctx.r27.u32 + 4, ctx.r6.u32);
	// b 0x82095df4
	goto loc_82095DF4;
loc_82095DE4:
	// rlwinm r7,r6,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,0(r27)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lwzx r9,r7,r27
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r27.u32);
	// stwx r6,r7,r27
	PPC_STORE_U32(ctx.r7.u32 + ctx.r27.u32, ctx.r6.u32);
loc_82095DF4:
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r6,r9,r4
	ctx.r6.s64 = ctx.r4.s64 - ctx.r9.s64;
	// stw r9,0(r27)
	PPC_STORE_U32(ctx.r27.u32 + 0, ctx.r9.u32);
	// addi r9,r5,2
	ctx.r9.s64 = ctx.r5.s64 + 2;
	// and r7,r6,r7
	ctx.r7.u64 = ctx.r6.u64 & ctx.r7.u64;
	// subf r6,r7,r4
	ctx.r6.s64 = ctx.r4.s64 - ctx.r7.s64;
	// cmplw cr6,r6,r9
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x82095e3c
	if (!ctx.cr6.lt) goto loc_82095E3C;
	// cmplwi cr6,r6,16
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 16, ctx.xer);
	// bge cr6,0x82095e3c
	if (!ctx.cr6.lt) goto loc_82095E3C;
	// add r7,r7,r29
	ctx.r7.u64 = ctx.r7.u64 + ctx.r29.u64;
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
loc_82095E24:
	// lbzu r6,1(r7)
	ea = 1 + ctx.r7.u32;
	ctx.r6.u64 = PPC_LOAD_U8(ea);
	ctx.r7.u32 = ea;
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stbx r6,r29,r4
	PPC_STORE_U8(ctx.r29.u32 + ctx.r4.u32, ctx.r6.u8);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// bgt 0x82095e24
	if (ctx.cr0.gt) goto loc_82095E24;
	// b 0x82095ec8
	goto loc_82095EC8;
loc_82095E3C:
	// cmpwi cr6,r9,16
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 16, ctx.xer);
	// ble cr6,0x82095e8c
	if (!ctx.cr6.gt) goto loc_82095E8C;
	// addi r6,r9,-17
	ctx.r6.s64 = ctx.r9.s64 + -17;
	// add r31,r29,r4
	ctx.r31.u64 = ctx.r29.u64 + ctx.r4.u64;
	// rlwinm r6,r6,28,4,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 28) & 0xFFFFFFF;
	// add r3,r7,r29
	ctx.r3.u64 = ctx.r7.u64 + ctx.r29.u64;
	// addi r5,r6,1
	ctx.r5.s64 = ctx.r6.s64 + 1;
	// rlwinm r6,r5,4,0,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// add r4,r6,r4
	ctx.r4.u64 = ctx.r6.u64 + ctx.r4.u64;
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// subf r9,r6,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r6.s64;
	// add r7,r6,r7
	ctx.r7.u64 = ctx.r6.u64 + ctx.r7.u64;
loc_82095E6C:
	// lvlx128 v63,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvrx128 v62,r21,r3
	temp.u32 = ctx.r21.u32 + ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// vor128 v63,v63,v62
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// stvlx128 v63,r0,r31
	ea = ctx.r31.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		PPC_STORE_U8(ea + i, ctx.v63.u8[15 - i]);
	// stvrx128 v63,r31,r21
	ea = ctx.r31.u32 + ctx.r21.u32;
	for (size_t i = 0; i < (ea & 0xF); i++)
		PPC_STORE_U8(ea - i - 1, ctx.v63.u8[i]);
	// addi r31,r31,16
	ctx.r31.s64 = ctx.r31.s64 + 16;
	// bdnz 0x82095e6c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82095E6C;
loc_82095E8C:
	// lvlx128 v63,r7,r29
	temp.u32 = ctx.r7.u32 + ctx.r29.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// add r6,r29,r4
	ctx.r6.u64 = ctx.r29.u64 + ctx.r4.u64;
	// add r7,r7,r29
	ctx.r7.u64 = ctx.r7.u64 + ctx.r29.u64;
	// lvlx128 v62,r29,r4
	temp.u32 = ctx.r29.u32 + ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r5,-1
	ctx.r5.s64 = -1;
	// lvrx128 v61,r21,r6
	temp.u32 = ctx.r21.u32 + ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvrx128 v60,r21,r7
	temp.u32 = ctx.r21.u32 + ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v0,v62,v61
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8)));
	// lvsr v12,r9,r5
	temp.u32 = ctx.r9.u32 + ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableR[(temp.u32 & 0xF) * 16]));
	// vor128 v13,v63,v60
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v60.u8)));
	// vcmpgtub v12,v11,v12
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_cmpgt_epu8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)));
	// vsel v12,v0,v13,v12
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// stvlx v12,r29,r4
	ea = ctx.r29.u32 + ctx.r4.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		PPC_STORE_U8(ea + i, ctx.v12.u8[15 - i]);
	// add r4,r9,r4
	ctx.r4.u64 = ctx.r9.u64 + ctx.r4.u64;
	// stvrx v12,r6,r21
	ea = ctx.r6.u32 + ctx.r21.u32;
	for (size_t i = 0; i < (ea & 0xF); i++)
		PPC_STORE_U8(ea - i - 1, ctx.v12.u8[i]);
loc_82095EC8:
	// cmpw cr6,r4,r28
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r28.s32, ctx.xer);
	// blt cr6,0x82095b3c
	if (ctx.cr6.lt) goto loc_82095B3C;
loc_82095ED0:
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r3,r28,r4
	ctx.r3.s64 = ctx.r4.s64 - ctx.r28.s64;
	// stb r8,0(r26)
	PPC_STORE_U8(ctx.r26.u32 + 0, ctx.r8.u8);
	// and r9,r9,r4
	ctx.r9.u64 = ctx.r9.u64 & ctx.r4.u64;
	// stw r10,0(r25)
	PPC_STORE_U32(ctx.r25.u32 + 0, ctx.r10.u32);
	// stw r30,0(r24)
	PPC_STORE_U32(ctx.r24.u32 + 0, ctx.r30.u32);
	// stw r9,11960(r11)
	PPC_STORE_U32(ctx.r11.u32 + 11960, ctx.r9.u32);
loc_82095EEC:
	// b 0x8207c9a0
	__restgprlr_14(ctx, base);
	return;
loc_82095EF0:
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x82095eec
	goto loc_82095EEC;
}

__attribute__((alias("__imp__sub_82095EF8"))) PPC_WEAK_FUNC(sub_82095EF8);
PPC_FUNC_IMPL(__imp__sub_82095EF8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82095F00;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// cmpwi cr6,r4,257
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 257, ctx.xer);
	// bge cr6,0x82095f50
	if (!ctx.cr6.lt) goto loc_82095F50;
	// subfic r5,r4,257
	ctx.xer.ca = ctx.r4.u32 <= 257;
	ctx.r5.s64 = 257 - ctx.r4.s64;
	// cmpw cr6,r5,r31
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r31.s32, ctx.xer);
	// blt cr6,0x82095f28
	if (ctx.cr6.lt) goto loc_82095F28;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
loc_82095F28:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82095758
	ctx.lr = 0x82095F34;
	sub_82095758(ctx, base);
	// subf r11,r3,r30
	ctx.r11.s64 = ctx.r30.s64 - ctx.r3.s64;
	// stw r3,11960(r29)
	PPC_STORE_U32(ctx.r29.u32 + 11960, ctx.r3.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// add. r31,r11,r31
	ctx.r31.u64 = ctx.r11.u64 + ctx.r31.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bgt 0x82095f50
	if (ctx.cr0.gt) goto loc_82095F50;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x82095f60
	goto loc_82095F60;
loc_82095F50:
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82095ad0
	ctx.lr = 0x82095F60;
	sub_82095AD0(ctx, base);
loc_82095F60:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82095F68"))) PPC_WEAK_FUNC(sub_82095F68);
PPC_FUNC_IMPL(__imp__sub_82095F68) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82095F70;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,11020(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11020);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82096004
	if (ctx.cr6.eq) goto loc_82096004;
	// lwz r11,11964(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11964);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82095fa8
	if (ctx.cr6.eq) goto loc_82095FA8;
	// lwz r11,11972(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11972);
	// li r28,1
	ctx.r28.s64 = 1;
	// cmplwi cr6,r11,32768
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32768, ctx.xer);
	// blt cr6,0x82095fac
	if (ctx.cr6.lt) goto loc_82095FAC;
loc_82095FA8:
	// li r28,0
	ctx.r28.s64 = 0;
loc_82095FAC:
	// lbz r11,12260(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + 12260);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82095fc8
	if (ctx.cr0.eq) goto loc_82095FC8;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq cr6,0x8209600c
	if (ctx.cr6.eq) goto loc_8209600C;
	// lwz r31,12264(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12264);
loc_82095FC8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82088630
	ctx.lr = 0x82095FD0;
	sub_82088630(ctx, base);
loc_82095FD0:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq cr6,0x82096004
	if (ctx.cr6.eq) goto loc_82096004;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82092dc8
	ctx.lr = 0x82095FE8;
	sub_82092DC8(ctx, base);
	// lbz r11,12260(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + 12260);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82096004
	if (ctx.cr0.eq) goto loc_82096004;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r3,11020(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 11020);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82088580
	ctx.lr = 0x82096004;
	sub_82088580(ctx, base);
loc_82096004:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_8209600C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82088580
	ctx.lr = 0x82096014;
	sub_82088580(ctx, base);
	// b 0x82095fd0
	goto loc_82095FD0;
}

__attribute__((alias("__imp__sub_82096018"))) PPC_WEAK_FUNC(sub_82096018);
PPC_FUNC_IMPL(__imp__sub_82096018) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x82096020;
	__savegprlr_25(ctx, base);
	// stwu r1,-880(r1)
	ea = -880 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// li r31,0
	ctx.r31.s64 = 0;
loc_82096038:
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82093308
	ctx.lr = 0x82096044;
	sub_82093308(ctx, base);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stbx r3,r31,r11
	PPC_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r3.u8);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmpwi cr6,r31,20
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 20, ctx.xer);
	// blt cr6,0x82096038
	if (ctx.cr6.lt) goto loc_82096038;
	// lbz r11,11959(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + 11959);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8209606c
	if (ctx.cr0.eq) goto loc_8209606C;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82096544
	goto loc_82096544;
loc_8209606C:
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,304
	ctx.r7.s64 = ctx.r1.s64 + 304;
	// li r6,8
	ctx.r6.s64 = 8;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,20
	ctx.r4.s64 = 20;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820966b0
	ctx.lr = 0x82096088;
	sub_820966B0(ctx, base);
	// lwz r11,11012(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 11012);
	// lwz r10,11952(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 11952);
	// li r4,0
	ctx.r4.s64 = 0;
	// lbz r7,11956(r30)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r30.u32 + 11956);
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// lbz r3,11959(r30)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r30.u32 + 11959);
	// lwz r31,11016(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 11016);
	// ble cr6,0x82096528
	if (!ctx.cr6.gt) goto loc_82096528;
loc_820960A8:
	// rlwinm r9,r10,9,23,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 9) & 0x1FE;
	// addi r8,r1,304
	ctx.r8.s64 = ctx.r1.s64 + 304;
	// lhax r8,r9,r8
	ctx.r8.s64 = int16_t(PPC_LOAD_U16(ctx.r9.u32 + ctx.r8.u32));
	// cmpwi r8,0
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bge 0x820960f8
	if (!ctx.cr0.lt) goto loc_820960F8;
	// lis r9,128
	ctx.r9.s64 = 8388608;
loc_820960C0:
	// and r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 & ctx.r10.u64;
	// neg r8,r8
	ctx.r8.s64 = -ctx.r8.s64;
	// cntlzw r6,r6
	ctx.r6.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// extsh r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	// rlwinm r6,r6,27,5,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x7FFFFFF;
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// xori r6,r6,1
	ctx.r6.u64 = ctx.r6.u64 ^ 1;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// add r8,r6,r8
	ctx.r8.u64 = ctx.r6.u64 + ctx.r8.u64;
	// rlwinm r9,r9,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lhax r8,r8,r5
	ctx.r8.s64 = int16_t(PPC_LOAD_U16(ctx.r8.u32 + ctx.r5.u32));
	// cmpwi r8,0
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// blt 0x820960c0
	if (ctx.cr0.lt) goto loc_820960C0;
loc_820960F8:
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lbzx r9,r8,r9
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// subf r7,r9,r7
	ctx.r7.s64 = ctx.r7.s64 - ctx.r9.s64;
	// slw r10,r10,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r9.u8 & 0x3F));
	// extsb r7,r7
	ctx.r7.s64 = ctx.r7.s8;
	// mr. r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bgt 0x82096184
	if (ctx.cr0.gt) goto loc_82096184;
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// bge cr6,0x82096154
	if (!ctx.cr6.lt) goto loc_82096154;
	// lbz r7,1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// addi r6,r9,16
	ctx.r6.s64 = ctx.r9.s64 + 16;
	// neg r26,r9
	ctx.r26.s64 = -ctx.r9.s64;
	// lbz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// rotlwi r9,r7,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r7.u32, 8);
	// extsb r7,r6
	ctx.r7.s64 = ctx.r6.s8;
	// or r6,r9,r5
	ctx.r6.u64 = ctx.r9.u64 | ctx.r5.u64;
	// mr. r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// slw r6,r6,r26
	ctx.r6.u64 = ctx.r26.u8 & 0x20 ? 0 : (ctx.r6.u32 << (ctx.r26.u8 & 0x3F));
	// or r10,r6,r10
	ctx.r10.u64 = ctx.r6.u64 | ctx.r10.u64;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// bgt 0x82096184
	if (ctx.cr0.gt) goto loc_82096184;
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// blt cr6,0x8209615c
	if (ctx.cr6.lt) goto loc_8209615C;
loc_82096154:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82096184
	goto loc_82096184;
loc_8209615C:
	// lbz r7,1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// neg r6,r9
	ctx.r6.s64 = -ctx.r9.s64;
	// lbz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// rotlwi r7,r7,8
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 8);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// or r5,r7,r5
	ctx.r5.u64 = ctx.r7.u64 | ctx.r5.u64;
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// slw r9,r5,r6
	ctx.r9.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r5.u32 << (ctx.r6.u8 & 0x3F));
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
loc_82096184:
	// clrlwi. r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x82096528
	if (!ctx.cr0.eq) goto loc_82096528;
	// cmpwi cr6,r8,17
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 17, ctx.xer);
	// bne cr6,0x8209625c
	if (!ctx.cr6.eq) goto loc_8209625C;
	// addi r9,r7,-4
	ctx.r9.s64 = ctx.r7.s64 + -4;
	// rlwinm r8,r10,4,28,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xF;
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// mr. r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bgt 0x8209621c
	if (ctx.cr0.gt) goto loc_8209621C;
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// bge cr6,0x820961ec
	if (!ctx.cr6.lt) goto loc_820961EC;
	// lbz r7,1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// addi r6,r9,16
	ctx.r6.s64 = ctx.r9.s64 + 16;
	// neg r26,r9
	ctx.r26.s64 = -ctx.r9.s64;
	// lbz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// rotlwi r9,r7,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r7.u32, 8);
	// extsb r7,r6
	ctx.r7.s64 = ctx.r6.s8;
	// or r6,r9,r5
	ctx.r6.u64 = ctx.r9.u64 | ctx.r5.u64;
	// mr. r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// slw r6,r6,r26
	ctx.r6.u64 = ctx.r26.u8 & 0x20 ? 0 : (ctx.r6.u32 << (ctx.r26.u8 & 0x3F));
	// or r10,r6,r10
	ctx.r10.u64 = ctx.r6.u64 | ctx.r10.u64;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// bgt 0x8209621c
	if (ctx.cr0.gt) goto loc_8209621C;
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// blt cr6,0x820961f4
	if (ctx.cr6.lt) goto loc_820961F4;
loc_820961EC:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8209621c
	goto loc_8209621C;
loc_820961F4:
	// lbz r7,1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// neg r6,r9
	ctx.r6.s64 = -ctx.r9.s64;
	// lbz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// rotlwi r7,r7,8
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 8);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// or r5,r7,r5
	ctx.r5.u64 = ctx.r7.u64 | ctx.r5.u64;
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// slw r9,r5,r6
	ctx.r9.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r5.u32 << (ctx.r6.u8 & 0x3F));
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
loc_8209621C:
	// addi r9,r8,4
	ctx.r9.s64 = ctx.r8.s64 + 4;
	// add r8,r9,r4
	ctx.r8.u64 = ctx.r9.u64 + ctx.r4.u64;
	// cmpw cr6,r8,r29
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r29.s32, ctx.xer);
	// blt cr6,0x82096230
	if (ctx.cr6.lt) goto loc_82096230;
	// subf r9,r4,r29
	ctx.r9.s64 = ctx.r29.s64 - ctx.r4.s64;
loc_82096230:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x820964f8
	if (!ctx.cr6.gt) goto loc_820964F8;
	// add r8,r4,r28
	ctx.r8.u64 = ctx.r4.u64 + ctx.r28.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq 0x82096328
	if (ctx.cr0.eq) goto loc_82096328;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_82096250:
	// stbu r6,1(r8)
	ea = 1 + ctx.r8.u32;
	PPC_STORE_U8(ea, ctx.r6.u8);
	ctx.r8.u32 = ea;
	// bdnz 0x82096250
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82096250;
	// b 0x82096328
	goto loc_82096328;
loc_8209625C:
	// cmpwi cr6,r8,18
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 18, ctx.xer);
	// bne cr6,0x82096330
	if (!ctx.cr6.eq) goto loc_82096330;
	// addi r9,r7,-5
	ctx.r9.s64 = ctx.r7.s64 + -5;
	// rlwinm r8,r10,5,27,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0x1F;
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// rlwinm r10,r10,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// mr. r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bgt 0x820962ec
	if (ctx.cr0.gt) goto loc_820962EC;
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// bge cr6,0x820962bc
	if (!ctx.cr6.lt) goto loc_820962BC;
	// lbz r7,1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// addi r6,r9,16
	ctx.r6.s64 = ctx.r9.s64 + 16;
	// neg r26,r9
	ctx.r26.s64 = -ctx.r9.s64;
	// lbz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// rotlwi r9,r7,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r7.u32, 8);
	// extsb r7,r6
	ctx.r7.s64 = ctx.r6.s8;
	// or r6,r9,r5
	ctx.r6.u64 = ctx.r9.u64 | ctx.r5.u64;
	// mr. r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// slw r6,r6,r26
	ctx.r6.u64 = ctx.r26.u8 & 0x20 ? 0 : (ctx.r6.u32 << (ctx.r26.u8 & 0x3F));
	// or r10,r6,r10
	ctx.r10.u64 = ctx.r6.u64 | ctx.r10.u64;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// bgt 0x820962ec
	if (ctx.cr0.gt) goto loc_820962EC;
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// blt cr6,0x820962c4
	if (ctx.cr6.lt) goto loc_820962C4;
loc_820962BC:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x820962ec
	goto loc_820962EC;
loc_820962C4:
	// lbz r7,1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// neg r6,r9
	ctx.r6.s64 = -ctx.r9.s64;
	// lbz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// rotlwi r7,r7,8
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 8);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// or r5,r7,r5
	ctx.r5.u64 = ctx.r7.u64 | ctx.r5.u64;
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// slw r9,r5,r6
	ctx.r9.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r5.u32 << (ctx.r6.u8 & 0x3F));
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
loc_820962EC:
	// addi r9,r8,20
	ctx.r9.s64 = ctx.r8.s64 + 20;
	// add r8,r9,r4
	ctx.r8.u64 = ctx.r9.u64 + ctx.r4.u64;
	// cmpw cr6,r8,r29
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r29.s32, ctx.xer);
	// blt cr6,0x82096300
	if (ctx.cr6.lt) goto loc_82096300;
	// subf r9,r4,r29
	ctx.r9.s64 = ctx.r29.s64 - ctx.r4.s64;
loc_82096300:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x820964f8
	if (!ctx.cr6.gt) goto loc_820964F8;
	// add r8,r4,r28
	ctx.r8.u64 = ctx.r4.u64 + ctx.r28.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq 0x82096328
	if (ctx.cr0.eq) goto loc_82096328;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_82096320:
	// stbu r6,1(r8)
	ea = 1 + ctx.r8.u32;
	PPC_STORE_U8(ea, ctx.r6.u8);
	ctx.r8.u32 = ea;
	// bdnz 0x82096320
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82096320;
loc_82096328:
	// add r4,r9,r4
	ctx.r4.u64 = ctx.r9.u64 + ctx.r4.u64;
	// b 0x820964f8
	goto loc_820964F8;
loc_82096330:
	// cmpwi cr6,r8,19
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 19, ctx.xer);
	// bne cr6,0x82096500
	if (!ctx.cr6.eq) goto loc_82096500;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// rlwinm r8,r10,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// extsb r7,r7
	ctx.r7.s64 = ctx.r7.s8;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// mr. r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bgt 0x820963c4
	if (ctx.cr0.gt) goto loc_820963C4;
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// bge cr6,0x82096394
	if (!ctx.cr6.lt) goto loc_82096394;
	// lbz r7,1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// addi r6,r10,16
	ctx.r6.s64 = ctx.r10.s64 + 16;
	// neg r26,r10
	ctx.r26.s64 = -ctx.r10.s64;
	// lbz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// rotlwi r10,r7,8
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 8);
	// extsb r7,r6
	ctx.r7.s64 = ctx.r6.s8;
	// or r6,r10,r5
	ctx.r6.u64 = ctx.r10.u64 | ctx.r5.u64;
	// mr. r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// slw r6,r6,r26
	ctx.r6.u64 = ctx.r26.u8 & 0x20 ? 0 : (ctx.r6.u32 << (ctx.r26.u8 & 0x3F));
	// or r9,r6,r9
	ctx.r9.u64 = ctx.r6.u64 | ctx.r9.u64;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// bgt 0x820963c4
	if (ctx.cr0.gt) goto loc_820963C4;
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// blt cr6,0x8209639c
	if (ctx.cr6.lt) goto loc_8209639C;
loc_82096394:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x820963c4
	goto loc_820963C4;
loc_8209639C:
	// lbz r7,1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// neg r6,r10
	ctx.r6.s64 = -ctx.r10.s64;
	// lbz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// rotlwi r7,r7,8
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 8);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// or r5,r7,r5
	ctx.r5.u64 = ctx.r7.u64 | ctx.r5.u64;
	// extsb r7,r10
	ctx.r7.s64 = ctx.r10.s8;
	// slw r10,r5,r6
	ctx.r10.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r5.u32 << (ctx.r6.u8 & 0x3F));
	// or r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 | ctx.r9.u64;
loc_820963C4:
	// addi r5,r8,4
	ctx.r5.s64 = ctx.r8.s64 + 4;
	// add r10,r5,r4
	ctx.r10.u64 = ctx.r5.u64 + ctx.r4.u64;
	// cmpw cr6,r10,r29
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r29.s32, ctx.xer);
	// blt cr6,0x820963d8
	if (ctx.cr6.lt) goto loc_820963D8;
	// subf r5,r4,r29
	ctx.r5.s64 = ctx.r29.s64 - ctx.r4.s64;
loc_820963D8:
	// rlwinm r10,r9,9,23,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 9) & 0x1FE;
	// addi r8,r1,304
	ctx.r8.s64 = ctx.r1.s64 + 304;
	// lhax r8,r10,r8
	ctx.r8.s64 = int16_t(PPC_LOAD_U16(ctx.r10.u32 + ctx.r8.u32));
	// cmpwi r8,0
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bge 0x82096428
	if (!ctx.cr0.lt) goto loc_82096428;
	// lis r10,128
	ctx.r10.s64 = 8388608;
loc_820963F0:
	// and r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 & ctx.r9.u64;
	// neg r8,r8
	ctx.r8.s64 = -ctx.r8.s64;
	// cntlzw r6,r6
	ctx.r6.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// extsh r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	// rlwinm r6,r6,27,5,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x7FFFFFF;
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// xori r6,r6,1
	ctx.r6.u64 = ctx.r6.u64 ^ 1;
	// addi r26,r1,112
	ctx.r26.s64 = ctx.r1.s64 + 112;
	// add r8,r6,r8
	ctx.r8.u64 = ctx.r6.u64 + ctx.r8.u64;
	// rlwinm r10,r10,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lhax r8,r8,r26
	ctx.r8.s64 = int16_t(PPC_LOAD_U16(ctx.r8.u32 + ctx.r26.u32));
	// cmpwi r8,0
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// blt 0x820963f0
	if (ctx.cr0.lt) goto loc_820963F0;
loc_82096428:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lbzx r10,r8,r10
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r10.u32);
	// subf r7,r10,r7
	ctx.r7.s64 = ctx.r7.s64 - ctx.r10.s64;
	// slw r10,r9,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r10.u8 & 0x3F));
	// extsb r7,r7
	ctx.r7.s64 = ctx.r7.s8;
	// mr. r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bgt 0x820964b4
	if (ctx.cr0.gt) goto loc_820964B4;
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// bge cr6,0x82096484
	if (!ctx.cr6.lt) goto loc_82096484;
	// lbz r7,1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// addi r6,r9,16
	ctx.r6.s64 = ctx.r9.s64 + 16;
	// neg r25,r9
	ctx.r25.s64 = -ctx.r9.s64;
	// lbz r26,0(r11)
	ctx.r26.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// rotlwi r9,r7,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r7.u32, 8);
	// extsb r7,r6
	ctx.r7.s64 = ctx.r6.s8;
	// or r6,r9,r26
	ctx.r6.u64 = ctx.r9.u64 | ctx.r26.u64;
	// mr. r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// slw r6,r6,r25
	ctx.r6.u64 = ctx.r25.u8 & 0x20 ? 0 : (ctx.r6.u32 << (ctx.r25.u8 & 0x3F));
	// or r10,r6,r10
	ctx.r10.u64 = ctx.r6.u64 | ctx.r10.u64;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// bgt 0x820964b4
	if (ctx.cr0.gt) goto loc_820964B4;
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// blt cr6,0x8209648c
	if (ctx.cr6.lt) goto loc_8209648C;
loc_82096484:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x820964b4
	goto loc_820964B4;
loc_8209648C:
	// lbz r7,1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// neg r6,r9
	ctx.r6.s64 = -ctx.r9.s64;
	// lbz r26,0(r11)
	ctx.r26.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// rotlwi r7,r7,8
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 8);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// or r26,r7,r26
	ctx.r26.u64 = ctx.r7.u64 | ctx.r26.u64;
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// slw r9,r26,r6
	ctx.r9.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r26.u32 << (ctx.r6.u8 & 0x3F));
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
loc_820964B4:
	// lbzx r9,r4,r27
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r27.u32);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// addi r9,r9,17
	ctx.r9.s64 = ctx.r9.s64 + 17;
	// cmpwi cr6,r9,17
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 17, ctx.xer);
	// blt cr6,0x820964cc
	if (ctx.cr6.lt) goto loc_820964CC;
	// addi r9,r9,-17
	ctx.r9.s64 = ctx.r9.s64 + -17;
loc_820964CC:
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// ble cr6,0x820964f8
	if (!ctx.cr6.gt) goto loc_820964F8;
	// add r9,r4,r28
	ctx.r9.u64 = ctx.r4.u64 + ctx.r28.u64;
	// cmplwi r5,0
	ctx.cr0.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// beq 0x820964f4
	if (ctx.cr0.eq) goto loc_820964F4;
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
loc_820964EC:
	// stbu r8,1(r9)
	ea = 1 + ctx.r9.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x820964ec
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820964EC;
loc_820964F4:
	// add r4,r5,r4
	ctx.r4.u64 = ctx.r5.u64 + ctx.r4.u64;
loc_820964F8:
	// addi r4,r4,-1
	ctx.r4.s64 = ctx.r4.s64 + -1;
	// b 0x8209651c
	goto loc_8209651C;
loc_82096500:
	// lbzx r9,r4,r27
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r27.u32);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// addi r9,r9,17
	ctx.r9.s64 = ctx.r9.s64 + 17;
	// cmpwi cr6,r9,17
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 17, ctx.xer);
	// blt cr6,0x82096518
	if (ctx.cr6.lt) goto loc_82096518;
	// addi r9,r9,-17
	ctx.r9.s64 = ctx.r9.s64 + -17;
loc_82096518:
	// stbx r9,r4,r28
	PPC_STORE_U8(ctx.r4.u32 + ctx.r28.u32, ctx.r9.u8);
loc_8209651C:
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// cmpw cr6,r4,r29
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r29.s32, ctx.xer);
	// blt cr6,0x820960a8
	if (ctx.cr6.lt) goto loc_820960A8;
loc_82096528:
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// stw r11,11012(r30)
	PPC_STORE_U32(ctx.r30.u32 + 11012, ctx.r11.u32);
	// stb r3,11959(r30)
	PPC_STORE_U8(ctx.r30.u32 + 11959, ctx.r3.u8);
	// cntlzw r11,r9
	ctx.r11.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// stw r10,11952(r30)
	PPC_STORE_U32(ctx.r30.u32 + 11952, ctx.r10.u32);
	// stb r7,11956(r30)
	PPC_STORE_U8(ctx.r30.u32 + 11956, ctx.r7.u8);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
loc_82096544:
	// addi r1,r1,880
	ctx.r1.s64 = ctx.r1.s64 + 880;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8209654C"))) PPC_WEAK_FUNC(sub_8209654C);
PPC_FUNC_IMPL(__imp__sub_8209654C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82096550"))) PPC_WEAK_FUNC(sub_82096550);
PPC_FUNC_IMPL(__imp__sub_82096550) {
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
	// addi r30,r3,2584
	ctx.r30.s64 = ctx.r3.s64 + 2584;
	// addi r5,r3,11028
	ctx.r5.s64 = ctx.r3.s64 + 11028;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82096018
	ctx.lr = 0x8209657C;
	sub_82096018(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8209658c
	if (!ctx.cr0.eq) goto loc_8209658C;
loc_82096584:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82096624
	goto loc_82096624;
loc_8209658C:
	// lbz r11,11957(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11957);
	// addi r6,r31,2840
	ctx.r6.s64 = ctx.r31.s64 + 2840;
	// addi r5,r31,11284
	ctx.r5.s64 = ctx.r31.s64 + 11284;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rotlwi r4,r11,3
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r11.u32, 3);
	// bl 0x82096018
	ctx.lr = 0x820965A4;
	sub_82096018(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82096584
	if (ctx.cr0.eq) goto loc_82096584;
	// lbz r11,11957(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11957);
	// addi r8,r31,3644
	ctx.r8.s64 = ctx.r31.s64 + 3644;
	// addi r7,r31,24
	ctx.r7.s64 = ctx.r31.s64 + 24;
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// li r6,10
	ctx.r6.s64 = 10;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rlwinm r4,r11,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x820966b0
	ctx.lr = 0x820965D0;
	sub_820966B0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82096584
	if (ctx.cr0.eq) goto loc_82096584;
	// addi r30,r31,3256
	ctx.r30.s64 = ctx.r31.s64 + 3256;
	// addi r5,r31,11700
	ctx.r5.s64 = ctx.r31.s64 + 11700;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// li r4,249
	ctx.r4.s64 = 249;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82096018
	ctx.lr = 0x820965F0;
	sub_82096018(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82096584
	if (ctx.cr0.eq) goto loc_82096584;
	// addi r8,r31,9020
	ctx.r8.s64 = ctx.r31.s64 + 9020;
	// addi r7,r31,2072
	ctx.r7.s64 = ctx.r31.s64 + 2072;
	// li r6,8
	ctx.r6.s64 = 8;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r4,249
	ctx.r4.s64 = 249;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820966b0
	ctx.lr = 0x82096614;
	sub_820966B0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// addi r11,r11,0
	ctx.r11.s64 = ctx.r11.s64 + 0;
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r3,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
loc_82096624:
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

__attribute__((alias("__imp__sub_8209663C"))) PPC_WEAK_FUNC(sub_8209663C);
PPC_FUNC_IMPL(__imp__sub_8209663C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82096640"))) PPC_WEAK_FUNC(sub_82096640);
PPC_FUNC_IMPL(__imp__sub_82096640) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82096648;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r29,r3,3636
	ctx.r29.s64 = ctx.r3.s64 + 3636;
loc_82096658:
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82093308
	ctx.lr = 0x82096664;
	sub_82093308(ctx, base);
	// stbx r3,r29,r30
	PPC_STORE_U8(ctx.r29.u32 + ctx.r30.u32, ctx.r3.u8);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmpwi cr6,r30,8
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 8, ctx.xer);
	// blt cr6,0x82096658
	if (ctx.cr6.lt) goto loc_82096658;
	// lbz r11,11959(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 11959);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82096688
	if (ctx.cr0.eq) goto loc_82096688;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x820966a8
	goto loc_820966A8;
loc_82096688:
	// addi r5,r31,3508
	ctx.r5.s64 = ctx.r31.s64 + 3508;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82096978
	ctx.lr = 0x82096698;
	sub_82096978(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// addi r11,r11,0
	ctx.r11.s64 = ctx.r11.s64 + 0;
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r3,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
loc_820966A8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820966B0"))) PPC_WEAK_FUNC(sub_820966B0);
PPC_FUNC_IMPL(__imp__sub_820966B0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x820966B8;
	__savegprlr_24(ctx, base);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,16
	ctx.r11.s64 = 16;
	// li r26,0
	ctx.r26.s64 = 0;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// mr r24,r5
	ctx.r24.u64 = ctx.r5.u64;
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// mr r28,r8
	ctx.r28.u64 = ctx.r8.u64;
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
loc_820966E0:
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x820966e0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820966E0;
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x82096718
	if (ctx.cr6.eq) goto loc_82096718;
	// mtctr r25
	ctx.ctr.u64 = ctx.r25.u64;
loc_820966F8:
	// lbzx r9,r11,r24
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r24.u32);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
	// bdnz 0x820966f8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820966F8;
loc_82096718:
	// li r9,16
	ctx.r9.s64 = 16;
	// stw r26,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r26.u32);
	// li r27,1
	ctx.r27.s64 = 1;
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_82096730:
	// addi r9,r1,164
	ctx.r9.s64 = ctx.r1.s64 + 164;
	// addi r8,r1,84
	ctx.r8.s64 = ctx.r1.s64 + 84;
	// subfic r7,r10,16
	ctx.xer.ca = ctx.r10.u32 <= 16;
	ctx.r7.s64 = 16 - ctx.r10.s64;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwzx r9,r11,r9
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r9.u32);
	// lwzx r8,r11,r8
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r8.u32);
	// slw r9,r9,r7
	ctx.r9.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r7.u8 & 0x3F));
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// stwx r9,r11,r5
	PPC_STORE_U32(ctx.r11.u32 + ctx.r5.u32, ctx.r9.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x82096730
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82096730;
	// lwz r11,148(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// lis r5,1
	ctx.r5.s64 = 65536;
	// cmplw cr6,r11,r5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r5.u32, ctx.xer);
	// beq cr6,0x8209679c
	if (ctx.cr6.eq) goto loc_8209679C;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82096794
	if (!ctx.cr6.eq) goto loc_82096794;
	// clrlwi r11,r6,24
	ctx.r11.u64 = ctx.r6.u32 & 0xFF;
	// li r4,0
	ctx.r4.s64 = 0;
	// slw r11,r27,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r27.u32 << (ctx.r11.u8 & 0x3F));
	// rlwinm r5,r11,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8207da20
	ctx.lr = 0x82096790;
	sub_8207DA20(ctx, base);
	// b 0x82096968
	goto loc_82096968;
loc_82096794:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8209696c
	goto loc_8209696C;
loc_8209679C:
	// clrlwi r31,r6,24
	ctx.r31.u64 = ctx.r6.u32 & 0xFF;
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// subfic r11,r31,16
	ctx.xer.ca = ctx.r31.u32 <= 16;
	ctx.r11.s64 = 16 - ctx.r31.s64;
	// cmplwi cr6,r31,1
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 1, ctx.xer);
	// clrlwi r6,r11,24
	ctx.r6.u64 = ctx.r11.u32 & 0xFF;
	// blt cr6,0x820967fc
	if (ctx.cr6.lt) goto loc_820967FC;
	// clrlwi r7,r6,24
	ctx.r7.u64 = ctx.r6.u32 & 0xFF;
	// mtctr r31
	ctx.ctr.u64 = ctx.r31.u64;
	// addi r9,r31,-1
	ctx.r9.s64 = ctx.r31.s64 + -1;
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// addi r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 1;
loc_820967C8:
	// addi r8,r1,84
	ctx.r8.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,164
	ctx.r4.s64 = ctx.r1.s64 + 164;
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// slw r3,r27,r9
	ctx.r3.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r27.u32 << (ctx.r9.u8 & 0x3F));
	// lwz r30,0(r8)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// stwx r3,r11,r4
	PPC_STORE_U32(ctx.r11.u32 + ctx.r4.u32, ctx.r3.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// srw r4,r30,r7
	ctx.r4.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r30.u32 >> (ctx.r7.u8 & 0x3F));
	// stw r4,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r4.u32);
	// bdnz 0x820967c8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820967C8;
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// bgt cr6,0x82096828
	if (ctx.cr6.gt) goto loc_82096828;
loc_820967FC:
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// subfic r11,r10,16
	ctx.xer.ca = ctx.r10.u32 <= 16;
	ctx.r11.s64 = 16 - ctx.r10.s64;
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// subfic r10,r10,17
	ctx.xer.ca = ctx.r10.u32 <= 17;
	ctx.r10.s64 = 17 - ctx.r10.s64;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// addi r9,r9,-4
	ctx.r9.s64 = ctx.r9.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82096818:
	// slw r10,r27,r11
	ctx.r10.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r27.u32 << (ctx.r11.u8 & 0x3F));
	// stwu r10,4(r9)
	ea = 4 + ctx.r9.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r9.u32 = ea;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// bdnz 0x82096818
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82096818;
loc_82096828:
	// rlwinm r11,r31,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r1,84
	ctx.r10.s64 = ctx.r1.s64 + 84;
	// clrlwi r30,r6,24
	ctx.r30.u64 = ctx.r6.u32 & 0xFF;
	// lwzx r11,r11,r10
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// srw r11,r11,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r11.u32 >> (ctx.r30.u8 & 0x3F));
	// cmplw cr6,r11,r5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r5.u32, ctx.xer);
	// beq cr6,0x82096860
	if (ctx.cr6.eq) goto loc_82096860;
	// slw r9,r27,r31
	ctx.r9.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r27.u32 << (ctx.r31.u8 & 0x3F));
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r11,r11,r9
	ctx.r11.s64 = ctx.r9.s64 - ctx.r11.s64;
	// li r4,0
	ctx.r4.s64 = 0;
	// rlwinm r5,r11,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r10,r29
	ctx.r3.u64 = ctx.r10.u64 + ctx.r29.u64;
	// bl 0x8207da20
	ctx.lr = 0x82096860;
	sub_8207DA20(ctx, base);
loc_82096860:
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// ble cr6,0x82096968
	if (!ctx.cr6.gt) goto loc_82096968;
loc_82096870:
	// lbzx r9,r4,r24
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r24.u32);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq 0x8209695c
	if (ctx.cr0.eq) goto loc_8209695C;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// cmplw cr6,r9,r31
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r31.u32, ctx.xer);
	// lwzx r11,r8,r7
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// lwzx r10,r8,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bgt cr6,0x820968dc
	if (ctx.cr6.gt) goto loc_820968DC;
	// slw r9,r27,r31
	ctx.r9.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r27.u32 << (ctx.r31.u8 & 0x3F));
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bgt cr6,0x82096794
	if (ctx.cr6.gt) goto loc_82096794;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x820968d4
	if (!ctx.cr6.lt) goto loc_820968D4;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// subf. r11,r11,r10
	ctx.r11.s64 = ctx.r10.s64 - ctx.r11.s64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// add r9,r9,r29
	ctx.r9.u64 = ctx.r9.u64 + ctx.r29.u64;
	// extsh r6,r4
	ctx.r6.s64 = ctx.r4.s16;
	// addi r9,r9,-2
	ctx.r9.s64 = ctx.r9.s64 + -2;
	// beq 0x820968d4
	if (ctx.cr0.eq) goto loc_820968D4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_820968CC:
	// sthu r6,2(r9)
	ea = 2 + ctx.r9.u32;
	PPC_STORE_U16(ea, ctx.r6.u16);
	ctx.r9.u32 = ea;
	// bdnz 0x820968cc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820968CC;
loc_820968D4:
	// stwx r10,r8,r7
	PPC_STORE_U32(ctx.r8.u32 + ctx.r7.u32, ctx.r10.u32);
	// b 0x8209695c
	goto loc_8209695C;
loc_820968DC:
	// stwx r10,r8,r7
	PPC_STORE_U32(ctx.r8.u32 + ctx.r7.u32, ctx.r10.u32);
	// subf r6,r31,r9
	ctx.r6.s64 = ctx.r9.s64 - ctx.r31.s64;
	// srw r10,r11,r30
	ctx.r10.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r11.u32 >> (ctx.r30.u8 & 0x3F));
	// rlwinm r9,r5,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r9,r28
	ctx.r9.u64 = ctx.r9.u64 + ctx.r28.u64;
	// clrlwi r10,r6,24
	ctx.r10.u64 = ctx.r6.u32 & 0xFF;
	// slw r6,r11,r31
	ctx.r6.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r31.u8 & 0x3F));
	// add r8,r8,r29
	ctx.r8.u64 = ctx.r8.u64 + ctx.r29.u64;
	// neg r7,r5
	ctx.r7.s64 = -ctx.r5.s64;
	// addi r11,r9,-4
	ctx.r11.s64 = ctx.r9.s64 + -4;
loc_82096908:
	// lhz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r8.u32 + 0);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne 0x82096928
	if (!ctx.cr0.eq) goto loc_82096928;
	// sth r26,6(r11)
	PPC_STORE_U16(ctx.r11.u32 + 6, ctx.r26.u16);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// sthu r26,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U16(ea, ctx.r26.u16);
	ctx.r11.u32 = ea;
	// sth r7,0(r8)
	PPC_STORE_U16(ctx.r8.u32 + 0, ctx.r7.u16);
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
loc_82096928:
	// extsh. r9,r6
	ctx.r9.s64 = ctx.r6.s16;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// lha r9,0(r8)
	ctx.r9.s64 = int16_t(PPC_LOAD_U16(ctx.r8.u32 + 0));
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// bge 0x82096944
	if (!ctx.cr0.lt) goto loc_82096944;
	// subf r9,r9,r28
	ctx.r9.s64 = ctx.r28.s64 - ctx.r9.s64;
	// addi r8,r9,2
	ctx.r8.s64 = ctx.r9.s64 + 2;
	// b 0x82096948
	goto loc_82096948;
loc_82096944:
	// subf r8,r9,r28
	ctx.r8.s64 = ctx.r28.s64 - ctx.r9.s64;
loc_82096948:
	// addi r10,r10,255
	ctx.r10.s64 = ctx.r10.s64 + 255;
	// rlwinm r6,r6,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// clrlwi. r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x82096908
	if (!ctx.cr0.eq) goto loc_82096908;
	// sth r4,0(r8)
	PPC_STORE_U16(ctx.r8.u32 + 0, ctx.r4.u16);
loc_8209695C:
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// cmpw cr6,r4,r25
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r25.s32, ctx.xer);
	// blt cr6,0x82096870
	if (ctx.cr6.lt) goto loc_82096870;
loc_82096968:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8209696C:
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82096974"))) PPC_WEAK_FUNC(sub_82096974);
PPC_FUNC_IMPL(__imp__sub_82096974) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82096978"))) PPC_WEAK_FUNC(sub_82096978);
PPC_FUNC_IMPL(__imp__sub_82096978) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82096980;
	__savegprlr_29(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
	// li r31,0
	ctx.r31.s64 = 0;
loc_82096998:
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// clrlwi r11,r10,16
	ctx.r11.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// sthx r31,r9,r8
	PPC_STORE_U16(ctx.r9.u32 + ctx.r8.u32, ctx.r31.u16);
	// ble cr6,0x82096998
	if (!ctx.cr6.gt) goto loc_82096998;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
loc_820969B8:
	// lbzx r9,r11,r30
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r30.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rotlwi r9,r9,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// lhzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r10.u32);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// sthx r8,r9,r10
	PPC_STORE_U16(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u16);
	// blt cr6,0x820969b8
	if (ctx.cr6.lt) goto loc_820969B8;
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
	// sth r31,130(r1)
	PPC_STORE_U16(ctx.r1.u32 + 130, ctx.r31.u16);
loc_820969E8:
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// subfic r6,r11,16
	ctx.xer.ca = ctx.r11.u32 <= 16;
	ctx.r6.s64 = 16 - ctx.r11.s64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r5,r1,130
	ctx.r5.s64 = ctx.r1.s64 + 130;
	// lhzx r10,r8,r10
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r8.u32 + ctx.r10.u32);
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// lhzx r9,r8,r9
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r8.u32 + ctx.r9.u32);
	// slw r10,r10,r6
	ctx.r10.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r6.u8 & 0x3F));
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// sthx r10,r8,r5
	PPC_STORE_U16(ctx.r8.u32 + ctx.r5.u32, ctx.r10.u16);
	// ble cr6,0x820969e8
	if (!ctx.cr6.gt) goto loc_820969E8;
	// lhz r11,162(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 162);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82096a34
	if (ctx.cr0.eq) goto loc_82096A34;
loc_82096A2C:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82096b1c
	goto loc_82096B1C;
loc_82096A34:
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
loc_82096A38:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// subfic r8,r11,7
	ctx.xer.ca = ctx.r11.u32 <= 7;
	ctx.r8.s64 = 7 - ctx.r11.s64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// slw r8,r7,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r8.u8 & 0x3F));
	// lhzx r6,r10,r9
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r9.u32);
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// sthx r8,r10,r5
	PPC_STORE_U16(ctx.r10.u32 + ctx.r5.u32, ctx.r8.u16);
	// rlwinm r6,r6,23,9,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 23) & 0x7FFFFF;
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// sthx r6,r10,r9
	PPC_STORE_U16(ctx.r10.u32 + ctx.r9.u32, ctx.r6.u16);
	// ble cr6,0x82096a38
	if (!ctx.cr6.gt) goto loc_82096A38;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bgt cr6,0x82096a98
	if (ctx.cr6.gt) goto loc_82096A98;
loc_82096A74:
	// subfic r10,r11,16
	ctx.xer.ca = ctx.r11.u32 <= 16;
	ctx.r10.s64 = 16 - ctx.r11.s64;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// slw r10,r7,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r10.u8 & 0x3F));
	// clrlwi r11,r9,16
	ctx.r11.u64 = ctx.r9.u32 & 0xFFFF;
	// sthx r10,r8,r6
	PPC_STORE_U16(ctx.r8.u32 + ctx.r6.u32, ctx.r10.u16);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// ble cr6,0x82096a74
	if (!ctx.cr6.gt) goto loc_82096A74;
loc_82096A98:
	// li r5,128
	ctx.r5.s64 = 128;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8207da20
	ctx.lr = 0x82096AA8;
	sub_8207DA20(ctx, base);
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
loc_82096AB0:
	// lbzx r11,r5,r30
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r30.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82096b04
	if (ctx.cr0.eq) goto loc_82096B04;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lhzx r11,r9,r7
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r7.u32);
	// lhzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r10.u32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplwi cr6,r10,128
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 128, ctx.xer);
	// bgt cr6,0x82096a2c
	if (ctx.cr6.gt) goto loc_82096A2C;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x82096b00
	if (!ctx.cr6.lt) goto loc_82096B00;
loc_82096AEC:
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// stbx r6,r11,r29
	PPC_STORE_U8(ctx.r11.u32 + ctx.r29.u32, ctx.r6.u8);
	// clrlwi r11,r8,16
	ctx.r11.u64 = ctx.r8.u32 & 0xFFFF;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82096aec
	if (ctx.cr6.lt) goto loc_82096AEC;
loc_82096B00:
	// sthx r10,r9,r7
	PPC_STORE_U16(ctx.r9.u32 + ctx.r7.u32, ctx.r10.u16);
loc_82096B04:
	// addi r11,r5,1
	ctx.r11.s64 = ctx.r5.s64 + 1;
	// clrlwi r6,r11,24
	ctx.r6.u64 = ctx.r11.u32 & 0xFF;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// cmplwi cr6,r6,8
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 8, ctx.xer);
	// blt cr6,0x82096ab0
	if (ctx.cr6.lt) goto loc_82096AB0;
	// li r3,1
	ctx.r3.s64 = 1;
loc_82096B1C:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82096B24"))) PPC_WEAK_FUNC(sub_82096B24);
PPC_FUNC_IMPL(__imp__sub_82096B24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82096B28"))) PPC_WEAK_FUNC(sub_82096B28);
PPC_FUNC_IMPL(__imp__sub_82096B28) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c96c
	ctx.lr = 0x82096B30;
	__savegprlr_21(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// mr r24,r5
	ctx.r24.u64 = ctx.r5.u64;
	// mr r23,r6
	ctx.r23.u64 = ctx.r6.u64;
	// mr r22,r7
	ctx.r22.u64 = ctx.r7.u64;
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82096b60
	if (!ctx.cr6.gt) goto loc_82096B60;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820a8fc0
	ctx.lr = 0x82096B60;
	sub_820A8FC0(ctx, base);
loc_82096B60:
	// lbz r11,10940(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10940);
	// rlwinm. r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82096b74
	if (ctx.cr0.eq) goto loc_82096B74;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x82096c04
	goto loc_82096C04;
loc_82096B74:
	// rlwinm. r11,r11,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82096bfc
	if (ctx.cr0.eq) goto loc_82096BFC;
	// lwz r11,12616(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12616);
	// lwz r10,12904(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12904);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82096b94
	if (ctx.cr6.eq) goto loc_82096B94;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82096bfc
	if (!ctx.cr6.eq) goto loc_82096BFC;
loc_82096B94:
	// lwz r11,12620(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12620);
	// lwz r10,12908(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12908);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82096bac
	if (ctx.cr6.eq) goto loc_82096BAC;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82096bfc
	if (!ctx.cr6.eq) goto loc_82096BFC;
loc_82096BAC:
	// lwz r11,12624(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12624);
	// lwz r10,12912(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12912);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82096bc4
	if (ctx.cr6.eq) goto loc_82096BC4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82096bfc
	if (!ctx.cr6.eq) goto loc_82096BFC;
loc_82096BC4:
	// lwz r11,12628(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12628);
	// lwz r10,12916(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12916);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82096bdc
	if (ctx.cr6.eq) goto loc_82096BDC;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82096bfc
	if (!ctx.cr6.eq) goto loc_82096BFC;
loc_82096BDC:
	// lwz r11,12632(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12632);
	// lwz r10,12920(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12920);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82096bf4
	if (ctx.cr6.eq) goto loc_82096BF4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82096bfc
	if (!ctx.cr6.eq) goto loc_82096BFC;
loc_82096BF4:
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x82096c00
	goto loc_82096C00;
loc_82096BFC:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82096C00:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
loc_82096C04:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r10,0
	ctx.r10.s64 = 0;
	// bne 0x82096c48
	if (!ctx.cr0.eq) goto loc_82096C48;
	// lis r11,2
	ctx.r11.s64 = 131072;
	// rlwinm r9,r24,16,2,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 16) & 0x3FFF0000;
	// ori r11,r11,8320
	ctx.r11.u64 = ctx.r11.u64 | 8320;
	// rlwinm r8,r22,16,2,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 16) & 0x3FFF0000;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r11.u32);
	ctx.r3.u32 = ea;
	// clrlwi r11,r25,18
	ctx.r11.u64 = ctx.r25.u32 & 0x3FFF;
	// or r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 | ctx.r11.u64;
	// clrlwi r9,r23,18
	ctx.r9.u64 = ctx.r23.u32 & 0x3FFF;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// or r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 | ctx.r9.u64;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r11.u32);
	ctx.r3.u32 = ea;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// b 0x82096e0c
	goto loc_82096E0C;
loc_82096C48:
	// lis r11,-16384
	ctx.r11.s64 = -1073741824;
	// lis r9,-16384
	ctx.r9.s64 = -1073741824;
	// ori r11,r11,24832
	ctx.r11.u64 = ctx.r11.u64 | 24832;
	// li r27,0
	ctx.r27.s64 = 0;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r11.u32);
	ctx.r3.u32 = ea;
	// ori r26,r9,24576
	ctx.r26.u64 = ctx.r9.u64 | 24576;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// lwz r10,12924(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12924);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// ble cr6,0x82096d8c
	if (!ctx.cr6.gt) goto loc_82096D8C;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r30,r31,12932
	ctx.r30.s64 = ctx.r31.s64 + 12932;
	// addi r28,r31,13172
	ctx.r28.s64 = ctx.r31.s64 + 13172;
loc_82096C80:
	// lwz r10,-4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -4);
	// mr r7,r25
	ctx.r7.u64 = ctx.r25.u64;
	// lwz r6,-4(r28)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r28.u32 + -4);
	// lwz r5,0(r28)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// cmpw cr6,r25,r10
	ctx.cr6.compare<int32_t>(ctx.r25.s32, ctx.r10.s32, ctx.xer);
	// bgt cr6,0x82096c9c
	if (ctx.cr6.gt) goto loc_82096C9C;
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
loc_82096C9C:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r8,r24
	ctx.r8.u64 = ctx.r24.u64;
	// cmpw cr6,r24,r10
	ctx.cr6.compare<int32_t>(ctx.r24.s32, ctx.r10.s32, ctx.xer);
	// bgt cr6,0x82096cb0
	if (ctx.cr6.gt) goto loc_82096CB0;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
loc_82096CB0:
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// cmpw cr6,r23,r9
	ctx.cr6.compare<int32_t>(ctx.r23.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x82096cc0
	if (!ctx.cr6.lt) goto loc_82096CC0;
	// mr r9,r23
	ctx.r9.u64 = ctx.r23.u64;
loc_82096CC0:
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmpw cr6,r22,r10
	ctx.cr6.compare<int32_t>(ctx.r22.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x82096cd0
	if (!ctx.cr6.lt) goto loc_82096CD0;
	// mr r10,r22
	ctx.r10.u64 = ctx.r22.u64;
loc_82096CD0:
	// cmpw cr6,r7,r9
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x82096ce0
	if (!ctx.cr6.lt) goto loc_82096CE0;
	// cmpw cr6,r8,r10
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x82096cf0
	if (ctx.cr6.lt) goto loc_82096CF0;
loc_82096CE0:
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
loc_82096CF0:
	// stwu r26,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r26.u32);
	ctx.r11.u32 = ea;
	// li r3,3
	ctx.r3.s64 = 3;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// slw r3,r3,r29
	ctx.r3.u64 = ctx.r29.u8 & 0x20 ? 0 : (ctx.r3.u32 << (ctx.r29.u8 & 0x3F));
	// stwu r3,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r3.u32);
	ctx.r11.u32 = ea;
	// lis r4,-16381
	ctx.r4.s64 = -1073545216;
	// lis r21,4
	ctx.r21.s64 = 262144;
	// ori r4,r4,11521
	ctx.r4.u64 = ctx.r4.u64 | 11521;
	// neg r6,r6
	ctx.r6.s64 = -ctx.r6.s64;
	// neg r5,r5
	ctx.r5.s64 = -ctx.r5.s64;
	// stwu r4,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r11.u32 = ea;
	// ori r21,r21,128
	ctx.r21.u64 = ctx.r21.u64 | 128;
	// rlwinm r5,r5,16,1,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0x7FFF0000;
	// clrlwi r6,r6,17
	ctx.r6.u64 = ctx.r6.u32 & 0x7FFF;
	// rlwinm r8,r8,16,2,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0x3FFF0000;
	// or r6,r5,r6
	ctx.r6.u64 = ctx.r5.u64 | ctx.r6.u64;
	// stwu r21,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r21.u32);
	ctx.r11.u32 = ea;
	// clrlwi r7,r7,18
	ctx.r7.u64 = ctx.r7.u32 & 0x3FFF;
	// rlwinm r10,r10,16,2,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0x3FFF0000;
	// or r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 | ctx.r7.u64;
	// clrlwi r9,r9,18
	ctx.r9.u64 = ctx.r9.u32 & 0x3FFF;
	// stwu r6,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r11.u32 = ea;
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stwu r8,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r11.u32 = ea;
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// stw r11,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// ble cr6,0x82096d70
	if (!ctx.cr6.gt) goto loc_82096D70;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820a8fc0
	ctx.lr = 0x82096D6C;
	sub_820A8FC0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_82096D70:
	// lwz r10,12924(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12924);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// addi r28,r28,8
	ctx.r28.s64 = ctx.r28.s64 + 8;
	// addi r30,r30,16
	ctx.r30.s64 = ctx.r30.s64 + 16;
	// addi r29,r29,2
	ctx.r29.s64 = ctx.r29.s64 + 2;
	// cmplw cr6,r27,r10
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82096c80
	if (ctx.cr6.lt) goto loc_82096C80;
loc_82096D8C:
	// lbz r10,10943(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10943);
	// rlwinm. r10,r10,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82096dec
	if (ctx.cr0.eq) goto loc_82096DEC;
	// lbz r10,10940(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 10940);
	// rlwinm. r10,r10,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82096dec
	if (ctx.cr0.eq) goto loc_82096DEC;
	// stwu r26,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r26.u32);
	ctx.r11.u32 = ea;
	// li r9,1
	ctx.r9.s64 = 1;
	// lis r8,-16382
	ctx.r8.s64 = -1073610752;
	// mr r10,r26
	ctx.r10.u64 = ctx.r26.u64;
	// ori r10,r8,11521
	ctx.r10.u64 = ctx.r8.u64 | 11521;
	// lis r7,4
	ctx.r7.s64 = 262144;
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// clrlwi r6,r25,18
	ctx.r6.u64 = ctx.r25.u32 & 0x3FFF;
	// ori r8,r7,129
	ctx.r8.u64 = ctx.r7.u64 | 129;
	// rlwinm r7,r24,16,2,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 16) & 0x3FFF0000;
	// rlwinm r5,r22,16,2,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 16) & 0x3FFF0000;
	// or r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 | ctx.r6.u64;
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// clrlwi r9,r23,18
	ctx.r9.u64 = ctx.r23.u32 & 0x3FFF;
	// or r9,r5,r9
	ctx.r9.u64 = ctx.r5.u64 | ctx.r9.u64;
	// stwu r8,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r11.u32 = ea;
	// stwu r7,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r11.u32 = ea;
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
loc_82096DEC:
	// stwu r26,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r26.u32);
	ctx.r11.u32 = ea;
	// lis r10,-16384
	ctx.r10.s64 = -1073741824;
	// lwz r9,12884(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12884);
	// ori r10,r10,24832
	ctx.r10.u64 = ctx.r10.u64 | 24832;
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// lwz r10,12888(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12888);
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
loc_82096E0C:
	// stw r11,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9bc
	__restgprlr_21(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82096E18"))) PPC_WEAK_FUNC(sub_82096E18);
PPC_FUNC_IMPL(__imp__sub_82096E18) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10568(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10568);
	// rlwimi r4,r11,0,0,28
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r11.u32, 0) & 0xFFFFFFF8) | (ctx.r4.u64 & 0xFFFFFFFF00000007);
	// stw r4,10568(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10568, ctx.r4.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,64
	ctx.r11.u64 = ctx.r11.u64 | 64;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82096E34"))) PPC_WEAK_FUNC(sub_82096E34);
PPC_FUNC_IMPL(__imp__sub_82096E34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82096E38"))) PPC_WEAK_FUNC(sub_82096E38);
PPC_FUNC_IMPL(__imp__sub_82096E38) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10568(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10568);
	// clrlwi r3,r11,29
	ctx.r3.u64 = ctx.r11.u32 & 0x7;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82096E44"))) PPC_WEAK_FUNC(sub_82096E44);
PPC_FUNC_IMPL(__imp__sub_82096E44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82096E48"))) PPC_WEAK_FUNC(sub_82096E48);
PPC_FUNC_IMPL(__imp__sub_82096E48) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10568(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10568);
	// rlwimi r11,r4,3,21,28
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 3) & 0x7F8) | (ctx.r11.u64 & 0xFFFFFFFFFFFFF807);
	// stw r11,10568(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10568, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,64
	ctx.r11.u64 = ctx.r11.u64 | 64;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82096E64"))) PPC_WEAK_FUNC(sub_82096E64);
PPC_FUNC_IMPL(__imp__sub_82096E64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82096E68"))) PPC_WEAK_FUNC(sub_82096E68);
PPC_FUNC_IMPL(__imp__sub_82096E68) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10568(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10568);
	// rlwinm r3,r11,29,24,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82096E74"))) PPC_WEAK_FUNC(sub_82096E74);
PPC_FUNC_IMPL(__imp__sub_82096E74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82096E78"))) PPC_WEAK_FUNC(sub_82096E78);
PPC_FUNC_IMPL(__imp__sub_82096E78) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10556(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10556);
	// rlwimi r11,r4,3,28,28
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 3) & 0x8) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFFF7);
	// stw r11,10556(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10556, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,512
	ctx.r11.u64 = ctx.r11.u64 | 512;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// oris r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 262144;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82096E9C"))) PPC_WEAK_FUNC(sub_82096E9C);
PPC_FUNC_IMPL(__imp__sub_82096E9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82096EA0"))) PPC_WEAK_FUNC(sub_82096EA0);
PPC_FUNC_IMPL(__imp__sub_82096EA0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10556(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10556);
	// rlwinm r3,r11,29,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82096EAC"))) PPC_WEAK_FUNC(sub_82096EAC);
PPC_FUNC_IMPL(__imp__sub_82096EAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82096EB0"))) PPC_WEAK_FUNC(sub_82096EB0);
PPC_FUNC_IMPL(__imp__sub_82096EB0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,12028(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12028);
	// rlwimi r11,r4,31,0,0
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 31) & 0x80000000) | (ctx.r11.u64 & 0xFFFFFFFF7FFFFFFF);
	// stw r11,12028(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12028, ctx.r11.u32);
	// rlwinm. r10,r11,0,1,1
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r11,12024(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12024);
	// bne 0x82096ee8
	if (!ctx.cr0.eq) goto loc_82096EE8;
	// andi. r10,r11,4112
	ctx.r10.u64 = ctx.r11.u64 & 4112;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// rlwinm r9,r11,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// rlwinm r10,r10,12,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFFF0000;
	// rlwinm r10,r10,0,12,10
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFEFFFFF;
	// rlwinm r10,r10,0,4,2
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFEFFFFFFF;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
loc_82096EE8:
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne cr6,0x82096ef8
	if (!ctx.cr6.eq) goto loc_82096EF8;
	// lis r11,1
	ctx.r11.s64 = 65536;
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
loc_82096EF8:
	// stw r11,10588(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10588, ctx.r11.u32);
	// stw r11,10552(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10552, ctx.r11.u32);
	// stw r11,10584(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10584, ctx.r11.u32);
	// stw r11,10592(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10592, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,1024
	ctx.r11.u64 = ctx.r11.u64 | 1024;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// ori r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 4;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// ori r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 2;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82096F30"))) PPC_WEAK_FUNC(sub_82096F30);
PPC_FUNC_IMPL(__imp__sub_82096F30) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,12028(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12028);
	// rlwinm r3,r11,1,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82096F3C"))) PPC_WEAK_FUNC(sub_82096F3C);
PPC_FUNC_IMPL(__imp__sub_82096F3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82096F40"))) PPC_WEAK_FUNC(sub_82096F40);
PPC_FUNC_IMPL(__imp__sub_82096F40) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,12024(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12024);
	// lwz r11,12028(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12028);
	// rlwimi r10,r4,5,24,26
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r4.u32, 5) & 0xE0) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFF1F);
	// rlwinm. r9,r11,0,0,0
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r10,12024(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12024, ctx.r10.u32);
	// beqlr 
	if (ctx.cr0.eq) return;
	// rlwinm. r10,r11,0,1,1
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r11,12024(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12024);
	// bne 0x82096f84
	if (!ctx.cr0.eq) goto loc_82096F84;
	// andi. r10,r11,4112
	ctx.r10.u64 = ctx.r11.u64 & 4112;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// rlwinm r9,r11,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// rlwinm r10,r10,12,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFFF0000;
	// rlwinm r10,r10,0,12,10
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFEFFFFF;
	// rlwinm r10,r10,0,4,2
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFEFFFFFFF;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
loc_82096F84:
	// stw r11,10552(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10552, ctx.r11.u32);
	// stw r11,10584(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10584, ctx.r11.u32);
	// stw r11,10588(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10588, ctx.r11.u32);
	// stw r11,10592(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10592, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,1024
	ctx.r11.u64 = ctx.r11.u64 | 1024;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// ori r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 4;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// ori r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 2;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82096FBC"))) PPC_WEAK_FUNC(sub_82096FBC);
PPC_FUNC_IMPL(__imp__sub_82096FBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82096FC0"))) PPC_WEAK_FUNC(sub_82096FC0);
PPC_FUNC_IMPL(__imp__sub_82096FC0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,12024(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12024);
	// rlwinm r3,r11,27,29,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x7;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82096FCC"))) PPC_WEAK_FUNC(sub_82096FCC);
PPC_FUNC_IMPL(__imp__sub_82096FCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82096FD0"))) PPC_WEAK_FUNC(sub_82096FD0);
PPC_FUNC_IMPL(__imp__sub_82096FD0) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,12024(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12024);
	// lwz r11,12028(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12028);
	// rlwimi r10,r4,0,27,31
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r4.u32, 0) & 0x1F) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFE0);
	// rlwinm. r9,r11,0,0,0
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r10,12024(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12024, ctx.r10.u32);
	// beqlr 
	if (ctx.cr0.eq) return;
	// rlwinm. r10,r11,0,1,1
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r11,12024(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12024);
	// bne 0x82097014
	if (!ctx.cr0.eq) goto loc_82097014;
	// andi. r10,r11,4112
	ctx.r10.u64 = ctx.r11.u64 & 4112;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// rlwinm r9,r11,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// rlwinm r10,r10,12,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFFF0000;
	// rlwinm r10,r10,0,12,10
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFEFFFFF;
	// rlwinm r10,r10,0,4,2
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFEFFFFFFF;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
loc_82097014:
	// stw r11,10552(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10552, ctx.r11.u32);
	// stw r11,10584(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10584, ctx.r11.u32);
	// stw r11,10588(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10588, ctx.r11.u32);
	// stw r11,10592(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10592, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,1024
	ctx.r11.u64 = ctx.r11.u64 | 1024;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// ori r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 4;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// ori r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 2;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8209704C"))) PPC_WEAK_FUNC(sub_8209704C);
PPC_FUNC_IMPL(__imp__sub_8209704C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097050"))) PPC_WEAK_FUNC(sub_82097050);
PPC_FUNC_IMPL(__imp__sub_82097050) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,12024(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12024);
	// clrlwi r3,r11,27
	ctx.r3.u64 = ctx.r11.u32 & 0x1F;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8209705C"))) PPC_WEAK_FUNC(sub_8209705C);
PPC_FUNC_IMPL(__imp__sub_8209705C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097060"))) PPC_WEAK_FUNC(sub_82097060);
PPC_FUNC_IMPL(__imp__sub_82097060) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,12024(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12024);
	// lwz r11,12028(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12028);
	// rlwimi r10,r4,8,19,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r4.u32, 8) & 0x1F00) | (ctx.r10.u64 & 0xFFFFFFFFFFFFE0FF);
	// rlwinm. r9,r11,0,0,0
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r10,12024(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12024, ctx.r10.u32);
	// beqlr 
	if (ctx.cr0.eq) return;
	// rlwinm. r10,r11,0,1,1
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r11,12024(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12024);
	// bne 0x820970a4
	if (!ctx.cr0.eq) goto loc_820970A4;
	// andi. r10,r11,4112
	ctx.r10.u64 = ctx.r11.u64 & 4112;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// rlwinm r9,r11,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// rlwinm r10,r10,12,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFFF0000;
	// rlwinm r10,r10,0,12,10
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFEFFFFF;
	// rlwinm r10,r10,0,4,2
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFEFFFFFFF;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
loc_820970A4:
	// stw r11,10552(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10552, ctx.r11.u32);
	// stw r11,10584(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10584, ctx.r11.u32);
	// stw r11,10588(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10588, ctx.r11.u32);
	// stw r11,10592(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10592, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,1024
	ctx.r11.u64 = ctx.r11.u64 | 1024;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// ori r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 4;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// ori r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 2;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820970DC"))) PPC_WEAK_FUNC(sub_820970DC);
PPC_FUNC_IMPL(__imp__sub_820970DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820970E0"))) PPC_WEAK_FUNC(sub_820970E0);
PPC_FUNC_IMPL(__imp__sub_820970E0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,12024(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12024);
	// rlwinm r3,r11,24,27,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 24) & 0x1F;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820970EC"))) PPC_WEAK_FUNC(sub_820970EC);
PPC_FUNC_IMPL(__imp__sub_820970EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820970F0"))) PPC_WEAK_FUNC(sub_820970F0);
PPC_FUNC_IMPL(__imp__sub_820970F0) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,12024(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12024);
	// lwz r11,12028(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12028);
	// rlwimi r10,r4,21,8,10
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r4.u32, 21) & 0xE00000) | (ctx.r10.u64 & 0xFFFFFFFFFF1FFFFF);
	// rlwinm. r9,r11,0,0,0
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r10,12024(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12024, ctx.r10.u32);
	// beqlr 
	if (ctx.cr0.eq) return;
	// rlwinm. r11,r11,0,1,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beqlr 
	if (ctx.cr0.eq) return;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r11,10552(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10552, ctx.r11.u32);
	// stw r11,10584(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10584, ctx.r11.u32);
	// stw r11,10588(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10588, ctx.r11.u32);
	// stw r11,10592(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10592, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,1024
	ctx.r11.u64 = ctx.r11.u64 | 1024;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// ori r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 4;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// ori r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 2;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8209714C"))) PPC_WEAK_FUNC(sub_8209714C);
PPC_FUNC_IMPL(__imp__sub_8209714C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097150"))) PPC_WEAK_FUNC(sub_82097150);
PPC_FUNC_IMPL(__imp__sub_82097150) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,12024(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12024);
	// rlwinm r3,r11,11,29,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 11) & 0x7;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8209715C"))) PPC_WEAK_FUNC(sub_8209715C);
PPC_FUNC_IMPL(__imp__sub_8209715C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097160"))) PPC_WEAK_FUNC(sub_82097160);
PPC_FUNC_IMPL(__imp__sub_82097160) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,12024(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12024);
	// lwz r11,12028(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12028);
	// rlwimi r10,r4,16,11,15
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r4.u32, 16) & 0x1F0000) | (ctx.r10.u64 & 0xFFFFFFFFFFE0FFFF);
	// rlwinm. r9,r11,0,0,0
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r10,12024(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12024, ctx.r10.u32);
	// beqlr 
	if (ctx.cr0.eq) return;
	// rlwinm. r11,r11,0,1,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beqlr 
	if (ctx.cr0.eq) return;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r11,10552(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10552, ctx.r11.u32);
	// stw r11,10584(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10584, ctx.r11.u32);
	// stw r11,10588(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10588, ctx.r11.u32);
	// stw r11,10592(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10592, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,1024
	ctx.r11.u64 = ctx.r11.u64 | 1024;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// ori r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 4;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// ori r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 2;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820971BC"))) PPC_WEAK_FUNC(sub_820971BC);
PPC_FUNC_IMPL(__imp__sub_820971BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820971C0"))) PPC_WEAK_FUNC(sub_820971C0);
PPC_FUNC_IMPL(__imp__sub_820971C0) {
	PPC_FUNC_PROLOGUE();
	// lhz r11,12024(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 12024);
	// clrlwi r3,r11,27
	ctx.r3.u64 = ctx.r11.u32 & 0x1F;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820971CC"))) PPC_WEAK_FUNC(sub_820971CC);
PPC_FUNC_IMPL(__imp__sub_820971CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820971D0"))) PPC_WEAK_FUNC(sub_820971D0);
PPC_FUNC_IMPL(__imp__sub_820971D0) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,12024(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12024);
	// lwz r11,12028(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12028);
	// rlwimi r10,r4,24,3,7
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r4.u32, 24) & 0x1F000000) | (ctx.r10.u64 & 0xFFFFFFFFE0FFFFFF);
	// rlwinm. r9,r11,0,0,0
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r10,12024(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12024, ctx.r10.u32);
	// beqlr 
	if (ctx.cr0.eq) return;
	// rlwinm. r11,r11,0,1,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beqlr 
	if (ctx.cr0.eq) return;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r11,10552(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10552, ctx.r11.u32);
	// stw r11,10584(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10584, ctx.r11.u32);
	// stw r11,10588(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10588, ctx.r11.u32);
	// stw r11,10592(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10592, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,1024
	ctx.r11.u64 = ctx.r11.u64 | 1024;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// ori r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 4;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// ori r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 2;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8209722C"))) PPC_WEAK_FUNC(sub_8209722C);
PPC_FUNC_IMPL(__imp__sub_8209722C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097230"))) PPC_WEAK_FUNC(sub_82097230);
PPC_FUNC_IMPL(__imp__sub_82097230) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,12024(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 12024);
	// clrlwi r3,r11,27
	ctx.r3.u64 = ctx.r11.u32 & 0x1F;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8209723C"))) PPC_WEAK_FUNC(sub_8209723C);
PPC_FUNC_IMPL(__imp__sub_8209723C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097240"))) PPC_WEAK_FUNC(sub_82097240);
PPC_FUNC_IMPL(__imp__sub_82097240) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,12028(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12028);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// rlwimi r11,r4,30,1,1
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 30) & 0x40000000) | (ctx.r11.u64 & 0xFFFFFFFFBFFFFFFF);
	// stw r11,12028(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12028, ctx.r11.u32);
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// lwz r11,12024(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12024);
	// bne cr6,0x8209727c
	if (!ctx.cr6.eq) goto loc_8209727C;
	// andi. r9,r11,4112
	ctx.r9.u64 = ctx.r11.u64 & 4112;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// rlwinm r8,r11,4,12,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// or r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 | ctx.r8.u64;
	// rlwinm r9,r9,12,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 12) & 0xFFFF0000;
	// rlwinm r9,r9,0,12,10
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFEFFFFF;
	// rlwinm r9,r9,0,4,2
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFEFFFFFFF;
	// or r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 | ctx.r11.u64;
loc_8209727C:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8209728c
	if (!ctx.cr6.eq) goto loc_8209728C;
	// lis r11,1
	ctx.r11.s64 = 65536;
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
loc_8209728C:
	// stw r11,10552(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10552, ctx.r11.u32);
	// stw r11,10584(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10584, ctx.r11.u32);
	// stw r11,10588(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10588, ctx.r11.u32);
	// stw r11,10592(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10592, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,1024
	ctx.r11.u64 = ctx.r11.u64 | 1024;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// ori r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 4;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// ori r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 2;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820972C4"))) PPC_WEAK_FUNC(sub_820972C4);
PPC_FUNC_IMPL(__imp__sub_820972C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820972C8"))) PPC_WEAK_FUNC(sub_820972C8);
PPC_FUNC_IMPL(__imp__sub_820972C8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,12028(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12028);
	// rlwinm r3,r11,2,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820972D4"))) PPC_WEAK_FUNC(sub_820972D4);
PPC_FUNC_IMPL(__imp__sub_820972D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820972D8"))) PPC_WEAK_FUNC(sub_820972D8);
PPC_FUNC_IMPL(__imp__sub_820972D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// clrldi r11,r4,32
	ctx.r11.u64 = ctx.r4.u64 & 0xFFFFFFFF;
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r11.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// frsp f13,f0
	ctx.f13.f64 = double(float(ctx.f0.f64));
	// lfs f0,12872(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 12872);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,10500(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 10500, temp.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// oris r11,r11,2048
	ctx.r11.u64 = ctx.r11.u64 | 134217728;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8209730C"))) PPC_WEAK_FUNC(sub_8209730C);
PPC_FUNC_IMPL(__imp__sub_8209730C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097310"))) PPC_WEAK_FUNC(sub_82097310);
PPC_FUNC_IMPL(__imp__sub_82097310) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f12,10500(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 10500);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,12876(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 12876);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12868(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12868);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f12,f0,f13
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64 + ctx.f13.f64));
	// fctidz f0,f0
	ctx.f0.s64 = (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f0.u64);
	// lwz r3,-12(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097338"))) PPC_WEAK_FUNC(sub_82097338);
PPC_FUNC_IMPL(__imp__sub_82097338) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10556(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10556);
	// rlwimi r4,r11,0,0,28
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r11.u32, 0) & 0xFFFFFFF8) | (ctx.r4.u64 & 0xFFFFFFFF00000007);
	// stw r4,10556(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10556, ctx.r4.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,512
	ctx.r11.u64 = ctx.r11.u64 | 512;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097354"))) PPC_WEAK_FUNC(sub_82097354);
PPC_FUNC_IMPL(__imp__sub_82097354) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097358"))) PPC_WEAK_FUNC(sub_82097358);
PPC_FUNC_IMPL(__imp__sub_82097358) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10556(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10556);
	// clrlwi r3,r11,29
	ctx.r3.u64 = ctx.r11.u32 & 0x7;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097364"))) PPC_WEAK_FUNC(sub_82097364);
PPC_FUNC_IMPL(__imp__sub_82097364) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097368"))) PPC_WEAK_FUNC(sub_82097368);
PPC_FUNC_IMPL(__imp__sub_82097368) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// rlwinm r11,r4,8,24,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFF;
	// rlwinm r9,r4,24,24,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 24) & 0xFF;
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r11.u64);
	// lfd f13,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r9.u64);
	// lfd f0,-16(r1)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// rlwinm r10,r4,16,24,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFF;
	// clrlwi r11,r4,24
	ctx.r11.u64 = ctx.r4.u32 & 0xFF;
	// std r10,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r10.u64);
	// lfd f12,-8(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// std r11,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r11.u64);
	// lfd f11,-8(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fcfid f10,f0
	ctx.f10.f64 = double(ctx.f0.s64);
	// lfs f0,12872(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12872);
	ctx.f0.f64 = double(temp.f32);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// li r12,15
	ctx.r12.s64 = 15;
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// rldicr r12,r12,33,30
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 33) & 0xFFFFFFFE00000000;
	// frsp f10,f10
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f11,f11,f0
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// stfs f11,10472(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 10472, temp.u32);
	// fmuls f11,f10,f0
	ctx.f11.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// stfs f11,10468(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 10468, temp.u32);
	// fmuls f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfs f12,10464(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 10464, temp.u32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,10476(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 10476, temp.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// or r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 | ctx.r12.u64;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820973F8"))) PPC_WEAK_FUNC(sub_820973F8);
PPC_FUNC_IMPL(__imp__sub_820973F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f12,10468(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 10468);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f11,10472(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 10472);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,10464(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 10464);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,10476(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 10476);
	ctx.f9.f64 = double(temp.f32);
	// lfs f0,12876(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 12876);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12868(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12868);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f12,f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f0.f64 + ctx.f13.f64));
	// fmadds f11,f11,f0,f13
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f0.f64 + ctx.f13.f64));
	// fmadds f10,f10,f0,f13
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f0.f64 + ctx.f13.f64));
	// fmadds f0,f9,f0,f13
	ctx.f0.f64 = double(float(ctx.f9.f64 * ctx.f0.f64 + ctx.f13.f64));
	// fctidz f13,f12
	ctx.f13.s64 = (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f13,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f13.u64);
	// lwz r11,-12(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// fctidz f13,f11
	ctx.f13.s64 = (ctx.f11.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f13,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f13.u64);
	// lwz r3,-12(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// fctidz f13,f10
	ctx.f13.s64 = (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f13,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f13.u64);
	// fctidz f0,f0
	ctx.f0.s64 = (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.f0.u64);
	// lwz r10,-12(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// lwz r9,-4(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + -4);
	// rlwimi r10,r9,8,0,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 8) & 0xFFFFFF00) | (ctx.r10.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r11,r10,8,0,23
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 8) & 0xFFFFFF00) | (ctx.r11.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r3,r11,8,0,23
	ctx.r3.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFFFFFF00) | (ctx.r3.u64 & 0xFFFFFFFF000000FF);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097468"))) PPC_WEAK_FUNC(sub_82097468);
PPC_FUNC_IMPL(__imp__sub_82097468) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10680(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10680);
	// li r12,1
	ctx.r12.s64 = 1;
	// rlwimi r11,r4,10,21,21
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 10) & 0x400) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFBFF);
	// rldicr r12,r12,37,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 37) & 0xFFFFFFFFFFFFFFFF;
	// stw r11,10680(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10680, ctx.r11.u32);
	// ld r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 32);
	// or r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 | ctx.r12.u64;
	// std r11,32(r3)
	PPC_STORE_U64(ctx.r3.u32 + 32, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8209748C"))) PPC_WEAK_FUNC(sub_8209748C);
PPC_FUNC_IMPL(__imp__sub_8209748C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097490"))) PPC_WEAK_FUNC(sub_82097490);
PPC_FUNC_IMPL(__imp__sub_82097490) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10680(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10680);
	// rlwinm r3,r11,22,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 22) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8209749C"))) PPC_WEAK_FUNC(sub_8209749C);
PPC_FUNC_IMPL(__imp__sub_8209749C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820974A0"))) PPC_WEAK_FUNC(sub_820974A0);
PPC_FUNC_IMPL(__imp__sub_820974A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// stw r4,28(r1)
	PPC_STORE_U32(ctx.r1.u32 + 28, ctx.r4.u32);
	// lfs f13,28(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// li r12,1
	ctx.r12.s64 = 1;
	// rldicr r12,r12,52,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 52) & 0xFFFFFFFFFFFFFFFF;
	// lfs f0,12864(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 12864);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fctidz f0,f0
	ctx.f0.s64 = (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f0.u64);
	// lwz r11,-12(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// sth r11,10606(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10606, ctx.r11.u16);
	// ld r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 | ctx.r12.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820974DC"))) PPC_WEAK_FUNC(sub_820974DC);
PPC_FUNC_IMPL(__imp__sub_820974DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820974E0"))) PPC_WEAK_FUNC(sub_820974E0);
PPC_FUNC_IMPL(__imp__sub_820974E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lhz r11,10606(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 10606);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r11.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lfs f0,12880(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12880);
	ctx.f0.f64 = double(temp.f32);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,-16(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lwz r3,-16(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097510"))) PPC_WEAK_FUNC(sub_82097510);
PPC_FUNC_IMPL(__imp__sub_82097510) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,24192(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24192);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82097524
	if (ctx.cr6.eq) goto loc_82097524;
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// b 0x82097528
	goto loc_82097528;
loc_82097524:
	// rlwinm r11,r11,0,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFE;
loc_82097528:
	// stw r11,24192(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24192, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097530"))) PPC_WEAK_FUNC(sub_82097530);
PPC_FUNC_IMPL(__imp__sub_82097530) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,24192(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24192);
	// clrlwi r3,r11,31
	ctx.r3.u64 = ctx.r11.u32 & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8209753C"))) PPC_WEAK_FUNC(sub_8209753C);
PPC_FUNC_IMPL(__imp__sub_8209753C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097540"))) PPC_WEAK_FUNC(sub_82097540);
PPC_FUNC_IMPL(__imp__sub_82097540) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,12632(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12632);
	// lwz r10,10548(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// subfic r11,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r11.s64 = 0 - ctx.r11.s64;
	// stw r4,12052(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12052, ctx.r4.u32);
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 & ctx.r4.u64;
	// rlwimi r10,r11,1,30,30
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 1) & 0x2) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFFD);
	// stw r10,10548(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10548, ctx.r10.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,2048
	ctx.r11.u64 = ctx.r11.u64 | 2048;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// oris r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 131072;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097578"))) PPC_WEAK_FUNC(sub_82097578);
PPC_FUNC_IMPL(__imp__sub_82097578) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,12052(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12052);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097580"))) PPC_WEAK_FUNC(sub_82097580);
PPC_FUNC_IMPL(__imp__sub_82097580) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10548(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwimi r11,r4,2,29,29
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 2) & 0x4) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFFFB);
	// stw r11,10548(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10548, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,2048
	ctx.r11.u64 = ctx.r11.u64 | 2048;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8209759C"))) PPC_WEAK_FUNC(sub_8209759C);
PPC_FUNC_IMPL(__imp__sub_8209759C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820975A0"))) PPC_WEAK_FUNC(sub_820975A0);
PPC_FUNC_IMPL(__imp__sub_820975A0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10548(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwinm r3,r11,30,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820975AC"))) PPC_WEAK_FUNC(sub_820975AC);
PPC_FUNC_IMPL(__imp__sub_820975AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820975B0"))) PPC_WEAK_FUNC(sub_820975B0);
PPC_FUNC_IMPL(__imp__sub_820975B0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10548(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwimi r11,r4,4,25,27
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 4) & 0x70) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFF8F);
	// stw r11,10548(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10548, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,2048
	ctx.r11.u64 = ctx.r11.u64 | 2048;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// oris r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 131072;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820975D4"))) PPC_WEAK_FUNC(sub_820975D4);
PPC_FUNC_IMPL(__imp__sub_820975D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820975D8"))) PPC_WEAK_FUNC(sub_820975D8);
PPC_FUNC_IMPL(__imp__sub_820975D8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10548(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwinm r3,r11,28,29,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0x7;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820975E4"))) PPC_WEAK_FUNC(sub_820975E4);
PPC_FUNC_IMPL(__imp__sub_820975E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820975E8"))) PPC_WEAK_FUNC(sub_820975E8);
PPC_FUNC_IMPL(__imp__sub_820975E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,12632(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12632);
	// lwz r10,10548(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// subfic r11,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r11.s64 = 0 - ctx.r11.s64;
	// stw r4,12056(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12056, ctx.r4.u32);
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 & ctx.r4.u64;
	// rlwimi r10,r11,0,31,31
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 0) & 0x1) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFFE);
	// stw r10,10548(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10548, ctx.r10.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,2048
	ctx.r11.u64 = ctx.r11.u64 | 2048;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// oris r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 131072;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097620"))) PPC_WEAK_FUNC(sub_82097620);
PPC_FUNC_IMPL(__imp__sub_82097620) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,12056(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12056);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097628"))) PPC_WEAK_FUNC(sub_82097628);
PPC_FUNC_IMPL(__imp__sub_82097628) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10548(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwimi r11,r4,7,24,24
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 7) & 0x80) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFF7F);
	// stw r11,10548(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10548, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,2048
	ctx.r11.u64 = ctx.r11.u64 | 2048;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// oris r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 131072;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8209764C"))) PPC_WEAK_FUNC(sub_8209764C);
PPC_FUNC_IMPL(__imp__sub_8209764C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097650"))) PPC_WEAK_FUNC(sub_82097650);
PPC_FUNC_IMPL(__imp__sub_82097650) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10548(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwinm r3,r11,25,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8209765C"))) PPC_WEAK_FUNC(sub_8209765C);
PPC_FUNC_IMPL(__imp__sub_8209765C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097660"))) PPC_WEAK_FUNC(sub_82097660);
PPC_FUNC_IMPL(__imp__sub_82097660) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10548(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwimi r11,r4,8,21,23
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 8) & 0x700) | (ctx.r11.u64 & 0xFFFFFFFFFFFFF8FF);
	// stw r11,10548(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10548, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,2048
	ctx.r11.u64 = ctx.r11.u64 | 2048;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8209767C"))) PPC_WEAK_FUNC(sub_8209767C);
PPC_FUNC_IMPL(__imp__sub_8209767C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097680"))) PPC_WEAK_FUNC(sub_82097680);
PPC_FUNC_IMPL(__imp__sub_82097680) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10548(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwinm r3,r11,24,29,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 24) & 0x7;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8209768C"))) PPC_WEAK_FUNC(sub_8209768C);
PPC_FUNC_IMPL(__imp__sub_8209768C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097690"))) PPC_WEAK_FUNC(sub_82097690);
PPC_FUNC_IMPL(__imp__sub_82097690) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10548(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwimi r11,r4,11,18,20
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 11) & 0x3800) | (ctx.r11.u64 & 0xFFFFFFFFFFFFC7FF);
	// stw r11,10548(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10548, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,2048
	ctx.r11.u64 = ctx.r11.u64 | 2048;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// oris r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 131072;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820976B4"))) PPC_WEAK_FUNC(sub_820976B4);
PPC_FUNC_IMPL(__imp__sub_820976B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820976B8"))) PPC_WEAK_FUNC(sub_820976B8);
PPC_FUNC_IMPL(__imp__sub_820976B8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10548(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwinm r3,r11,21,29,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 21) & 0x7;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820976C4"))) PPC_WEAK_FUNC(sub_820976C4);
PPC_FUNC_IMPL(__imp__sub_820976C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820976C8"))) PPC_WEAK_FUNC(sub_820976C8);
PPC_FUNC_IMPL(__imp__sub_820976C8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10548(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwimi r11,r4,17,12,14
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 17) & 0xE0000) | (ctx.r11.u64 & 0xFFFFFFFFFFF1FFFF);
	// stw r11,10548(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10548, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,2048
	ctx.r11.u64 = ctx.r11.u64 | 2048;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// oris r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 131072;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820976EC"))) PPC_WEAK_FUNC(sub_820976EC);
PPC_FUNC_IMPL(__imp__sub_820976EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820976F0"))) PPC_WEAK_FUNC(sub_820976F0);
PPC_FUNC_IMPL(__imp__sub_820976F0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10548(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwinm r3,r11,15,29,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 15) & 0x7;
	// blr 
	return;
}

